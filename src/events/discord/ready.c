#include <concord.h>
#include <bot/bot.h>
#include <lib/logger.h>

void bot_on_ready(DiscordClient* client, const DiscordReady* event) {
    logger_mod_trace("Concord", "Received bot `ready` event");

    JustBot* bot = discord_get_data(client);
    bot->user.discord_user_id = event->user->id;

    bot_init_commands(bot, event);

    logger_success("\033[92;1mBot is ready!\033[0m");
}
