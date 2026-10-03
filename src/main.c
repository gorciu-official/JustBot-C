#define _POSIX_C_SOURCE 200809L 

#include <bot/bot.h>
#include <lib/logger.h>
#include <stdlib.h>
#include <signal.h>

static JustBot bot;

void sigsegv_handler(int) {
    panic("Internal segmentation fault");
}

void sigsegv_init() {
    struct sigaction sa = {0};

    sa.sa_handler = sigsegv_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGSEGV, &sa, NULL);
}

int main() {
    logger_log("Welcome to JustBOT-C!");
    logger_log("Licensed under: EUPL-v1.2.");
    logger_log("Source code: https://github.com/gorciu-official/JustBot-C");
    logger_log("Discord server: https://discord.gg/Q2e827Puwr");

    sigsegv_init();

    char* discord_token = getenv("JUSTBOT_TOKEN");

    if (discord_token == NULL)
        panic("Required environment variable `JUSTBOT_TOKEN` is not set"); 

    bot_init(&bot, &((JustBotSecrets){
        .discord_token = discord_token 
    }));
}
