#include <stddef.h>

#include <concord.h>
#include <concord/application_command.h>
#include <bot/bot.h>
#include <bot/command.h>
#include <lib/logger.h>

DECLARE_CMD(ping);
DECLARE_CMD(lvl);

JustBotCommand* commands[] = {
    &cmd_ping,
    &cmd_lvl,
    NULL
};

void bot_init_commands(JustBot* bot, const DiscordReady* event) {
    for (size_t i = 0; commands[i] != NULL; i++) {
        JustBotCommand* cmd = commands[i];

        logger_log("Registering command: %s", cmd->name);

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
