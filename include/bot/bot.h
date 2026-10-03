#pragma once

#include <concord.h>
#include <bot/config.h>

typedef struct {
    char* discord_token;
} JustBotSecrets;

typedef struct {
    struct {
        struct discord* discord;
    } clients;
    JustBotSecrets secrets;
    JustBotConfig config;
} JustBot;

extern void bot_init(JustBot* bot, JustBotSecrets* secrets);
extern void bot_init_default_config(JustBot* bot);
