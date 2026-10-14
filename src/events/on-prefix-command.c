#include <bot/bot.h>
#include <bot/command.h>

#include <lib/some.h>
#include <lib/or.h>
#include <lib/includes.h>
#include <lib/string-utils.h>
#include <lib/logger.h>

#include <events/common/commands.h>
#include <events/boilerplate/prefix-command-reply.h>

bool contains_alias(char** aliases, char* alias) {
    if (aliases == NULL)
        return false;

    INCLUDES(aliases, calias, contains_alias_ret, strcmp(calias, alias) == 0);
    return contains_alias_ret;
}

void bot_on_prefix_command(JustBot* bot, const DiscordMessage* msg) {
    char* command_name = str_trim_prefix(msg->content, bot->config.commands.prefix);

    while (str_starts_with(command_name, " "))
        command_name = str_trim_prefix(command_name, " ");

    bot_common_command_handler(&(JustBotCCHInput){
        .user = OR(msg->author, msg->member->user),
        .member = msg->member,
        .invoked_command_name = command_name,
        .reply = {
            .error = reply_error,
            .embed = reply_embed,
            .info = reply_info,
            .success = reply_success,
            .text = reply_text
        },
        .raw = msg,
        .bot = bot
    });
}
