#pragma once

#include <bot/bot.h>
#include <bot/command.h>

__attribute__((used))
static void ireply_error(JustBotCommandAPI* api, char* title, char* desc) {
    const DiscordInteraction* event = api->raw;
    JustBot* bot = api->bot; 
    DISCORD_IREPLY_ERROR(bot, event->id, event->token, title, desc);
}

__attribute__((used))
static void ireply_success(JustBotCommandAPI* api, char* title, char* desc) {
    const DiscordInteraction* event = api->raw;
    JustBot* bot = api->bot; 
    DISCORD_IREPLY_SUCCESS(bot, event->id, event->token, title, desc);
}

__attribute__((used))
static void ireply_info(JustBotCommandAPI* api, char* title, char* desc) {
    const DiscordInteraction* event = api->raw;
    JustBot* bot = api->bot; 
    DISCORD_IREPLY_INFO(bot, event->id, event->token, title, desc);
}
