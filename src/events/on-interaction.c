#include <concord.h>
#include <discord_codecs.h>

#include <bot/bot.h>
#include <bot/command.h>

#include <string.h>
#include <lib/some.h>
#include <lib/includes.h>

#include <events/interaction-reply-boilerplate.h>

void bot_on_interaction(DiscordClient* client, const DiscordInteraction* event) {
    JustBot* bot = discord_get_data(client);

    if (event->type != DISCORD_INTERACTION_APPLICATION_COMMAND)
        return;

    SOME(JustBotCommand, commands, cmd, strcmp(cmd->name, event->data->name) == 0) 

    if (!cmd) {
        // display command not found message
        DISCORD_IREPLY_ERROR(
            bot, event->id, event->token, 
            bot->config.commands.shared_runner_messages.command_not_found_title,
            bot->config.commands.shared_runner_messages.command_not_found_desc
        );
        return;
    }

    INCLUDES(bot->config.commands.killswitches.commands, a, command_killswitched, strcmp(a, cmd->name) == 0)

    if (bot->config.commands.killswitches.slash || command_killswitched) {
        // display killswitch message
        DISCORD_IREPLY_ERROR(
            bot, event->id, event->token, 
            bot->config.commands.shared_runner_messages.killswitch_activated_title,
            bot->config.commands.shared_runner_messages.killswitch_activated_desc
        );
        return;
    }

    cmd->execute(&(JustBotCommandAPI){
        .bot = bot,
        .raw = event,
        .invocation = {
            .command = cmd,
            .member = event->member,
            .used_alias = cmd->name
        },
        .reply = {
            .error = ireply_error,
            .success = ireply_success,
            .info = ireply_info
        }
    });
}
