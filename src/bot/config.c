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
            },
            .shared_runner_messages = {
                .command_not_found_title = "Nie ma takiej komendy bracie!",
                .command_not_found_desc = "Nie mam zielonego pojęcia co ty ode mnie chciałeś, ale nie ma takiej komendy i weź się odwal czy coś. Nie będę przepraszał za bycie niegrzecznym, jam buntownik.",
                .killswitch_activated_title = "Włączono killswitches dla tej komendy lub tego sposobu jej wywoływania!",
                .killswitch_activated_desc = 
                    "Czyli tłumacząc na ludzki język, jest to jedna z dwóch sytuacji: \n\n"
                    "- wyłączony został sposób, w który wywołałeś tę komendę, np. jest coś zjebanego ze slash commands, więc zostały one wyłączone,\n"
                    "- wyłączona została komenda, bo jest z nią coś nie tak\n\n" 
                    "W 99\% przypadków ma to jakiś powód, więc jak nie możesz wywołać komendy inaczej to masz problem, musisz czekać"
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
