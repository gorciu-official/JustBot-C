#include <concord.h>
#include <discord_codecs.h>

#include <bot/bot.h>
#include <bot/command.h>

#include <string.h>
#include <lib/some.h>

#include <events/interaction-reply-boilerplate.h>

void bot_on_interaction(DiscordClient* client, const DiscordInteraction* event) {
    JustBot* bot = discord_get_data(client);

    if (event->type != DISCORD_INTERACTION_APPLICATION_COMMAND)
        return;

    SOME(JustBotCommand, commands, cmd, strcmp(cmd->name, event->data->name) == 0) 

    if (!cmd) {
        DISCORD_IREPLY_ERROR(bot, event->id, event->token, "Nie znalazłem komendy!", "Albo jest jakiś internal error w bocie albo masz outdated Discord interactions albo taka komenda nie istnieje (choć nie powinna się zarejestrować w ogóle). Nie wiem, spinguj administrację!");
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
