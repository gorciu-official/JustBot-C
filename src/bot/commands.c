#include <stddef.h>

#include <concord.h>
#include <concord/application_command.h>
#include <bot/bot.h>
#include <bot/command.h>
#include <lib/logger.h>

DECLARE_CMD(ping);
DECLARE_CMD(lvl);
DECLARE_CMD(restart);
DECLARE_CMD(help);

JustBotCommand* commands[] = {
    // general
    &cmd_ping,
    &cmd_help,

    // leveling
    &cmd_lvl,

    // dev
    &cmd_restart,
    NULL
};

void bot_init_commands(JustBot* bot, const DiscordReady* event) {
    for (size_t i = 0; commands[i] != NULL; i++) {
        JustBotCommand* cmd = commands[i];

        logger_mod_log("Commands", "Registering command: %s", cmd->name);

        if (
            !cmd->name || !cmd->description.main || !cmd->description.shortened ||
            !cmd->execute || !cmd->category
        ) {
            logger_mod_error("Commands", "Found an uninitialized, but required field in command %s", cmd->name);
            logger_mod_error("Commands", "Please ensure all fields were set. This is a code error. Panicking.");
            panic("Uninitialized value in one of the required fields in command structure.");
        }

        DiscordCreateGuildApplicationCommand params = {
            .name = cmd->name,
            .description = cmd->description.main
        };

        discord_create_guild_application_command(
            bot->clients.discord,
            event->application->id,
            bot->config.guild_id,
            &params,
            NULL
        );
    }
}
