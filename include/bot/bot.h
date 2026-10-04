#pragma once

#include <concord.h>
#include <sqlite3.h>

#include <bot/config.h>

typedef struct {
    char* discord_token;
} JustBotSecrets;

typedef struct {
    struct {
        struct discord* discord;
        sqlite3* sqlite;
    } clients;
    JustBotSecrets secrets;
    JustBotConfig config;
} JustBot;

extern void bot_init(JustBot* bot, JustBotSecrets* secrets);
extern void bot_init_default_config(JustBot* bot);
extern void bot_init_commands(JustBot* bot, const DiscordReady* event);

extern void bot_on_ready(DiscordClient* client, const DiscordReady* event);
extern void bot_on_interaction(DiscordClient* client, const DiscordInteraction* event);
extern void bot_init_db(JustBot* bot);
