#include <concord.h>
#include <discord_codecs.h>

#include <string.h>

#include <bot/bot.h>
#include <bot/command.h>

static void ireply_error(JustBotCommandAPI* api, char* title, char* desc) {
    const DiscordInteraction* event = api->raw;
    JustBot* bot = api->bot; 
    DISCORD_IREPLY_ERROR(bot, event->id, event->token, title, desc);
}

static void ireply_success(JustBotCommandAPI* api, char* title, char* desc) {
    const DiscordInteraction* event = api->raw;
    JustBot* bot = api->bot; 
    DISCORD_IREPLY_SUCCESS(bot, event->id, event->token, title, desc);
}

static void ireply_info(JustBotCommandAPI* api, char* title, char* desc) {
    const DiscordInteraction* event = api->raw;
    JustBot* bot = api->bot; 
    DISCORD_IREPLY_INFO(bot, event->id, event->token, title, desc);
}

void bot_on_interaction(DiscordClient* client, const DiscordInteraction* event) {
    JustBot* bot = discord_get_data(client);

    if (event->type != DISCORD_INTERACTION_APPLICATION_COMMAND)
        return;

    JustBotCommand* cmd = commands[0];

    for (int i = 0; commands[i] != NULL; i++) {
        if (strcmp(cmd->name, event->data->name) == 0)
            break;
        cmd = commands[i + 1]; 
    }

    if (!cmd) {
        DISCORD_IREPLY_ERROR(bot, event->id, event->token, "Nie znalazłem komendy!", "Albo jest jakiś internal error w bocie albo masz outdated Discord interactions albo taka komenda nie istnieje (choć nie powinna się zarejestrować w ogóle). Nie wiem, spinguj administrację!");
        return;
    }

    cmd->execute(&(JustBotCommandAPI){
        .bot = bot,
        .raw = event,
        .invocation = {
            .command = cmd,
            .member = event->member,
            .used_alias = cmd->name
        },
        .reply = {
            .error = ireply_error,
            .success = ireply_success,
            .info = ireply_info
        }
    });
}
