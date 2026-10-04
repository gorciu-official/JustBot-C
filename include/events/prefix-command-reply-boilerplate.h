#pragma once

#include <bot/bot.h>
#include <bot/command.h>

__attribute__((used))
static void reply_error(JustBotCommandAPI* api, char* title, char* desc) {
    const DiscordMessage* event = api->raw;
    JustBot* bot = api->bot; 
    DISCORD_REPLY_ERROR(bot, event, title, desc);
}

__attribute__((used))
static void reply_success(JustBotCommandAPI* api, char* title, char* desc) {
    const DiscordMessage* event = api->raw;
    JustBot* bot = api->bot; 
    DISCORD_REPLY_SUCCESS(bot, event, title, desc);
}

__attribute__((used))
static void reply_info(JustBotCommandAPI* api, char* title, char* desc) {
    const DiscordMessage* event = api->raw;
    JustBot* bot = api->bot; 
    DISCORD_REPLY_INFO(bot, event, title, desc);
}
