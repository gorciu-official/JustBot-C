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

// -- initialization
extern void bot_init(JustBot* bot, JustBotSecrets* secrets);
extern void bot_init_default_config(JustBot* bot);
extern void bot_init_commands(JustBot* bot, const DiscordReady* event);

// -- events
extern void bot_on_ready(DiscordClient* client, const DiscordReady* event);
extern void bot_on_interaction(DiscordClient* client, const DiscordInteraction* event);
extern void bot_on_message_create(struct discord* client, const DiscordMessage* msg);
extern void bot_on_prefix_command(JustBot* bot, const DiscordMessage* msg);

// -- database
extern void bot_init_db(JustBot* bot);
extern void bot_db_add_xp(JustBot* bot, uint64_t user_id, int xp);
extern int bot_db_get_xp(JustBot* bot, uint64_t user_id);
