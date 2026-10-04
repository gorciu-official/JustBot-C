#include "lib/logger.h"
#include <bot/bot.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <lib/string-utils.h>

#include <cjson.h>
#include <curl/curl.h>

typedef struct {
    char* data;
    size_t size;
} HttpResponse;

static size_t write_callback(void* contents, size_t size, size_t nmemb, void* userp)  {
    HttpResponse* response = userp;
    size_t bytes = size * nmemb;

    char* tmp = realloc(response->data, response->size + bytes + 1);
    if (!tmp)
        return 0;

    response->data = tmp;
    memcpy(response->data + response->size, contents, bytes);

    response->size += bytes;
    response->data[response->size] = '\0';

    return bytes;
}

char* ask_gemini(const char* prompt, const char* api_key)  {
    CURL* curl = NULL;
    struct curl_slist* headers = NULL;
    cJSON* root = NULL;
    cJSON* parsed = NULL;
    char* json = NULL;
    char* answer = NULL;

    HttpResponse response = {
        .data = malloc(1),
        .size = 0
    };

    if (!response.data)
        return NULL;

    curl = curl_easy_init();
    if (!curl)
        goto cleanup;

    char url[512];
    snprintf(
        url,
        sizeof(url),
        "https://generativelanguage.googleapis.com/v1beta/"
        "models/gemini-3.5-flash-lite:generateContent?key=%s",
        api_key
    );

    root = cJSON_CreateObject();
    if (!root)
        goto cleanup;

    cJSON* contents = cJSON_AddArrayToObject(root, "contents");
    cJSON* content = cJSON_CreateObject();
    cJSON* parts = cJSON_AddArrayToObject(content, "parts");
    cJSON* part = cJSON_CreateObject();

    if (!contents || !content || !parts || !part)
        goto cleanup;

    cJSON_AddStringToObject(part, "text", prompt);
    cJSON_AddItemToArray(parts, part);
    cJSON_AddItemToArray(contents, content);

    json = cJSON_PrintUnformatted(root);
    if (!json)
        goto cleanup;

    headers = curl_slist_append(headers, "Content-Type: application/json");
    if (!headers)
        goto cleanup;

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    CURLcode result = curl_easy_perform(curl);
    if (result != CURLE_OK) {
        logger_error("Error using cURL to query Gemini API: %s", curl_easy_strerror(result));
        goto cleanup;
    }

    long status_code = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &status_code);

    if (status_code < 200 || status_code >= 300) {
        logger_error("Gemini API gave non-200 HTTP status code %d: %s", status_code, response.data);
        goto cleanup;
    }

    parsed = cJSON_Parse(response.data);
    if (!parsed) {
        logger_error("Gemini API gave invalid JSON");
        goto cleanup;
    }

    cJSON* candidates = cJSON_GetObjectItem(parsed, "candidates");
    cJSON* candidate = cJSON_GetArrayItem(candidates, 0);
    cJSON* content_json = cJSON_GetObjectItem(candidate, "content");
    cJSON* parts_json = cJSON_GetObjectItem(content_json, "parts");
    cJSON* response_part = cJSON_GetArrayItem(parts_json, 0);
    cJSON* text = cJSON_GetObjectItem(response_part, "text");

    if (!cJSON_IsString(text) || !text->valuestring) {
        logger_error("Gemini's response is... idk what is this, but not a string");
        goto cleanup;
    }

    answer = strdup(text->valuestring);

cleanup:
    cJSON_Delete(parsed);
    cJSON_Delete(root);

    free(json);
    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
    free(response.data);

    return answer;
}

void bot_on_ai_ping(JustBot* bot, const DiscordMessage* msg, char* prefix)  {
    char* prompt = str_trim_prefix(msg->content, prefix);
    const char* api_key = getenv("JUSTBOT_GEMINI_API_KEY");

    if (!api_key) {
        DISCORD_REPLY_ERROR(
            bot,
            msg,
            "Masz problem",
            "Niestety niemądrzy administratorzy JustCorda zapomnieli włożyć Gemini API key do `.env`. No i co ja mam z tobą zrobić teraz???"
        );
        return;
    }

    char* answer = ask_gemini(prompt, api_key);

    if (!answer) {
        DISCORD_REPLY_ERROR(
            bot,
            msg,
            "Masz problem",
            "API się zjebało i niestety nasze peak AI nie może Ci teraz odpowiedzieć. "
            "Jak jesteś adminem, no to logi sprawdź czy coś."
        );
        return;
    }

    DISCORD_REPLY_SUCCESS(bot, msg, "Odpowiedź od twojego AI!!!", answer);

    free(answer);
}
