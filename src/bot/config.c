#include <bot/config.h>
#include <bot/bot.h>

void bot_init_default_config(JustBot* bot) {
    bot->config = (JustBotConfig){
        .commands = {
            .prefix = "sudo "
        },
        .guild_id = 1403639417620664320
    };
}
