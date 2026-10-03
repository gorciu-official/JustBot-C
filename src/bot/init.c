#include <bot/bot.h>
#include <concord.h>
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
        DISCORD_REPLY_ERROR(bot, msg, "Nie działa jeszcze!", "Nie ma komend prefixowych! Co ty myślisz, że wszystko będzie implementowane w 5 nanosekund? Pisałeś kiedyś w języku Bogów, że się odzywasz (chociażby Zap, Elash, Wavler, HolyC czy zwykłe C)?");
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
    discord_set_on_ready(bot->clients.discord, bot_on_ready);
    discord_set_on_interaction_create(bot->clients.discord, bot_on_interaction);

    // start the bot
    discord_run(bot->clients.discord);
}
