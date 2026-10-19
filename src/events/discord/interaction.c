#include <concord.h>
#include <concord/discord_codecs.h>

#include <bot/bot.h>
#include <bot/command.h>

#include <lib/some.h>
#include <lib/includes.h>
#include <lib/or.h>

#include <events/common/commands.h>
#include <events/boilerplate/interaction-reply.h>

void bot_on_interaction(DiscordClient* client, const DiscordInteraction* event) {
    JustBot* bot = discord_get_data(client);

    if (event->type != DISCORD_INTERACTION_APPLICATION_COMMAND)
        return;

    bot_common_command_handler(&(JustBotCCHInput){
        .user = OR(event->user, event->member->user),
        .member = event->member,
        .invoked_command_name = event->data->name,
        .reply = {
            .error = ireply_error,
            .embed = ireply_embed,
            .info = ireply_info,
            .success = ireply_success,
            .text = ireply_text
        },
        .raw = event,
        .bot = bot
    });
}
