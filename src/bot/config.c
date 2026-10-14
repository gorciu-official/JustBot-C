#include <bot/config.h>
#include <bot/bot.h>

static char* killswitched_commands[] = {
    NULL
};

static uint64_t leveling_excluded_channels[] = {
    0
};

void bot_init_default_config(JustBot* bot) {
    bot->config = (JustBotConfig){
        .commands = {
            .prefix = "sudo ",
            .killswitches = {
                .prefix = false,
                .slash = false,
                .commands = killswitched_commands 
            }
        },
        .db = {
            .path = "bot.db"
        },
        .features = {
            .leveling = {
                .lvl_per_message = 4,
                .level_divider = 100,

                .excluded_channels = leveling_excluded_channels,

                .described_attachment_msg_threshold = 15,
                .long_msg_threshold = 100,

                .described_attachment_multiplier = 1.5,
                .long_msg_multiplier = 1.2
            }
        },
        .guild_id = 1403639417620664320
    };
}
