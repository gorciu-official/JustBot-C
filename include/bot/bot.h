#pragma once

#include <concord.h>

typedef struct {
    char* discord_token;
} JustBotSecrets;

typedef struct {
    struct {
        struct discord* discord;
    } clients;

    JustBotSecrets secrets;
} JustBot;

extern void bot_init(JustBot* bot, JustBotSecrets* secrets);
