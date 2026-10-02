#include <lib/logger.h>
#include <bot/bot.h>
#include <discord-events.h>

#include <string.h>

#define JUSTBOT_INTENTS \
        ( DISCORD_GATEWAY_DIRECT_MESSAGES                       \
        | DISCORD_GATEWAY_GUILD_MESSAGES                        \
        | DISCORD_GATEWAY_MESSAGE_CONTENT                       \
        | DISCORD_GATEWAY_GUILDS                                \
        | DISCORD_GATEWAY_GUILD_MEMBERS                         \
        | DISCORD_GATEWAY_GUILD_MESSAGE_REACTIONS               \
        )
 
void bot_on_message_create(struct discord*, const DiscordMessage* msg) {
    if (strcmp(msg->content, "sudo ping") == 0) {
        puts("YAY!!!!!!!!!!!!! I GOT PINGED! \n\n\n\n");
    }
}

void bot_init(JustBot* bot, JustBotSecrets* secrets) {
    logger_log("Hi! The answer to everything in life is %d!", 42); 
    bot->clients.discord = discord_init(secrets->discord_token);
    discord_add_intents(bot->clients.discord, JUSTBOT_INTENTS);
    discord_set_on_message_create(bot->clients.discord, bot_on_message_create);
    discord_run(bot->clients.discord);
}
