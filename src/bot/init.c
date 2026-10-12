#define _GNU_SOURCE

#include <bot/bot.h>
#include <lib/autofree.h>
#include <lib/logger.h>
#include <concord.h>

#include <sys/stat.h>

#define JUSTBOT_INTENTS \
        ( DISCORD_GATEWAY_DIRECT_MESSAGES                       \
        | DISCORD_GATEWAY_GUILD_MESSAGES                        \
        | DISCORD_GATEWAY_MESSAGE_CONTENT                       \
        | DISCORD_GATEWAY_GUILDS                                \
        | DISCORD_GATEWAY_GUILD_MEMBERS                         \
        | DISCORD_GATEWAY_GUILD_MESSAGE_REACTIONS               \
        )

#define JUSTBOT_CONCORD_CFG_PATH \
    "/tmp/justbot-concord-config-sensitive.json"

#define JUSTBOT_CONCORD_CONFIG(cc, token) \
    asprintf(&cc, "{" \
        "\"log\": {" \
            "\"level\":" "\"warn\"" \
        "}," \
        "\"token\": \"%s\"" \
    "}", token)

void bot_concord_config_save(char* concord_cfg) {
    FILE* cfgf = fopen(JUSTBOT_CONCORD_CFG_PATH, "w");
    if (cfgf == NULL) 
        panic("Could not open a temporary file to store Concord's config");

    fputs(concord_cfg, cfgf);

    fclose(cfgf);
}

void bot_init(JustBot* bot, JustBotSecrets* secrets) {    
    // init bot object 
    bot->secrets = *secrets;
    bot_init_default_config(bot);

    // create concord configuration...
    autofree char* concord_cfg = NULL;
    JUSTBOT_CONCORD_CONFIG(concord_cfg, bot->secrets.discord_token);

    // ...and save it!
    bot_concord_config_save(concord_cfg);

    // change permissions for best practice
    chmod(JUSTBOT_CONCORD_CFG_PATH, 0700);

    // init discord 
    bot->clients.discord = discord_config_init(JUSTBOT_CONCORD_CFG_PATH);
    discord_add_intents(bot->clients.discord, JUSTBOT_INTENTS);
    discord_set_data(bot->clients.discord, bot);

    // set handlers
    discord_set_on_message_create(bot->clients.discord, bot_on_message_create);
    discord_set_on_ready(bot->clients.discord, bot_on_ready);
    discord_set_on_interaction_create(bot->clients.discord, bot_on_interaction);

    // prepare db 
    bot_init_db(bot);

    // start the bot
    discord_run(bot->clients.discord);
}
