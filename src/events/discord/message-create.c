#include <bot/bot.h>
#include <bot/leveling.h>

#include <lib/includes.h>
#include <lib/or.h>
#include <lib/string-utils.h>

#include <events/common/commands.h>
#include <events/boilerplate/prefix-command-reply.h>

static void on_prefix_command(JustBot* bot, const DiscordMessage* msg) {
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

void bot_on_message_create(DiscordClient* client, const DiscordMessage* msg) {
    JustBot* bot = discord_get_data(client);
    char* prefix = bot->config.commands.prefix;

    if (str_starts_with(msg->content, prefix)) {
        on_prefix_command(bot, msg);
    }

    char ai_prefix[32];
    snprintf(ai_prefix, sizeof(ai_prefix), "<@%" PRIu64 ">", bot->user.discord_user_id);

    if (
        str_starts_with(msg->content, ai_prefix) ||
        (msg->referenced_message && msg->referenced_message->author->id == bot->user.discord_user_id)
    ) {
        bot_on_ai_ping(bot, msg, &prefix[0]); 
    }

    bot_db_add_xp(bot, msg->author->id, compute_msg_xp(msg, bot));
}
