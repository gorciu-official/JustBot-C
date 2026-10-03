#include <concord.h>
#include <discord_codecs.h>
#include <bot/bot.h>

void bot_on_interaction(DiscordClient* client, const DiscordInteraction* event) {
    JustBot* bot = discord_get_data(client);

    if (event->type != DISCORD_INTERACTION_APPLICATION_COMMAND)
        return;

    DISCORD_IREPLY_ERROR(bot, event->id, event->token, "Hello world!", "Nie nie ma jeszcze odpalania komend, spierdalaj!");
}
