#include <bot/bot.h>
#include <discord-events.h>
#include <lib/string-utils.h>

#define JUSTBOT_INTENTS \
        ( DISCORD_GATEWAY_DIRECT_MESSAGES                       \
        | DISCORD_GATEWAY_GUILD_MESSAGES                        \
        | DISCORD_GATEWAY_MESSAGE_CONTENT                       \
        | DISCORD_GATEWAY_GUILDS                                \
        | DISCORD_GATEWAY_GUILD_MEMBERS                         \
        | DISCORD_GATEWAY_GUILD_MESSAGE_REACTIONS               \
        )
 
void bot_on_message_create(struct discord* client, const DiscordMessage* msg) {
    JustBot* bot = discord_get_data(client);
    char* prefix = bot->config.commands.prefix;

    if (str_starts_with(msg->content, prefix)) {
        discord_reply_embed(client, msg, &(DiscordEmbed){
            .color = 0xff0000,
            .title = "Nie ma jeszcze komend bracie!",
            .description = "Wiem, że czekacie!\n\nAle się zrymowało frfr. A tak na serio to na razie będą slash tylko, pozdrawiam."
        });     
    }
}

void bot_init(JustBot* bot, JustBotSecrets* secrets) {
    // init bot object 
    bot->secrets = *secrets;
    bot_init_default_config(bot);

    // init discord 
    bot->clients.discord = discord_init(bot->secrets.discord_token);
    discord_add_intents(bot->clients.discord, JUSTBOT_INTENTS);
    discord_set_data(bot->clients.discord, bot);

    // set handlers
    discord_set_on_message_create(bot->clients.discord, bot_on_message_create);

    // start the bot
    discord_run(bot->clients.discord);
}
