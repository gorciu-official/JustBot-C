#include <bot/bot.h>
#include <bot/command.h>

#include <lib/some.h>
#include <lib/or.h>
#include <lib/includes.h>
#include <lib/string-utils.h>
#include <lib/logger.h>

#include <events/prefix-command-reply-boilerplate.h>

void bot_on_prefix_command(JustBot* bot, const DiscordMessage* msg) {
    char* command_name = str_trim_prefix(msg->content, bot->config.commands.prefix);

    while (str_starts_with(command_name, " "))
        command_name = str_trim_prefix(command_name, " ");

    logger_log("cmd name:%s--end", command_name);

    SOME(JustBotCommand, commands, cmd, strcmp(cmd->name, command_name) == 0) 

    if (!cmd) {
        // display command not found message
        DISCORD_REPLY_ERROR(
            bot, msg, 
            bot->config.commands.shared_runner_messages.command_not_found_title,
            bot->config.commands.shared_runner_messages.command_not_found_desc
        );
        return;
    }

    INCLUDES(bot->config.commands.killswitches.commands, a, command_killswitched, strcmp(a, cmd->name) == 0)

    if (bot->config.commands.killswitches.prefix || command_killswitched) {
        // display killswitch message
        DISCORD_REPLY_ERROR(
            bot, msg, 
            bot->config.commands.shared_runner_messages.killswitch_activated_title,
            bot->config.commands.shared_runner_messages.killswitch_activated_desc
        );
        return;
    }

    cmd->execute(&(JustBotCommandAPI){
        .bot = bot,
        .raw = msg,
        .invocation = {
            .command = cmd,
            .member = msg->member,
            .user = OR(msg->member->user, msg->author),
            .used_alias = cmd->name
        },
        .reply = {
            .error = reply_error,
            .success = reply_success,
            .info = reply_info
        }
    });
}
