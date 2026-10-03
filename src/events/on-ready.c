#pragma once

#include <concord.h>
#include <bot/bot.h>

void bot_on_ready(DiscordClient* client, const DiscordReady* event) {
    JustBot* bot = discord_get_data(client);
    bot_init_commands(bot, event);
}
