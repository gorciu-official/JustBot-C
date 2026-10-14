#include <string.h>

#include <lib/includes.h>
#include <lib/some.h>

#include <events/common/commands.h>

static bool user_has_permissions(JustBotCCHInput* data, JustBotCommand* cmd) {
    if (cmd->permissions.allowed_users == NULL || cmd->permissions.allowed_roles == NULL)
        return true;

    INCLUDES_I(
        cmd->permissions.allowed_users, user, 
        in_allowed_users, __builtin_expect(data->user->id == user, 0)
    )

    if (in_allowed_users) return true;

    for (size_t n = 0; cmd->permissions.allowed_roles[n] != 0; n++) {
        INCLUDES_S(
            data->member->roles->array, data->member->roles->size, role, 
            contains_allowed_role, cmd->permissions.allowed_roles[n] == role  
        )
        
        if (contains_allowed_role)
            return true;
    }

    return false;
}

void bot_common_command_handler(JustBotCCHInput* data) {
    JustBot* bot = data->bot;

    SOME(JustBotCommand, commands, cmd, strcmp(cmd->name, data->invoked_command_name) == 0) 

    if (!cmd) {
        data->reply.error(
            JUSTBOT_CCHPD_MK_CMD_API_STUB(data->bot, data->raw), 
            "Nie ma takiej komendy bracie!",
            "Nie mam zielonego pojęcia co ty ode mnie chciałeś, ale nie ma takiej komendy i weź się odwal czy coś."
            "Nie będę przepraszał za bycie niegrzecznym, jam buntownik."
        );
        return;
    }

    INCLUDES(bot->config.commands.killswitches.commands, a, command_killswitched, strcmp(a, cmd->name) == 0)

    if (bot->config.commands.killswitches.slash || command_killswitched) {
        data->reply.error(
            JUSTBOT_CCHPD_MK_CMD_API_STUB(data->bot, data->raw), 
            "Killswitch włączono panie!",
            "W skrócie to sprawdź czy możesz wywołać komendę inaczej a jak nie to masz problem."
            "Byłem zbyt leniwy by zrobić dokładnego ifa i powiedzieć o co chodzi. Administracji się spytaj."
        );
        return;
    }

    if (!user_has_permissions(data, cmd)) {
        data->reply.error(
            JUSTBOT_CCHPD_MK_CMD_API_STUB(data->bot, data->raw), 
            "Co ty odpierdalasz?",
            "Czy ja mam wysłać po Ciebie policję? Po chuj próbujesz wykonywać komendy nie dla Ciebie?"
            "Myślałeś, że bot w C jest dziurawy i Ci pozwoli? Tak? To się naucz, że Ci nie pozwolę."
        );
        
        return;
    }

    cmd->execute(&(JustBotCommandAPI){
        .bot = bot,
        .raw = data->raw,
        .invocation = {
            .command = cmd,
            .member = data->member,
            .user = data->user,
            .used_alias = data->invoked_command_name 
        },
        .reply = {
            .error = data->reply.error,
            .success = data->reply.success,
            .info = data->reply.info,
            .text = data->reply.text,
            .embed = data->reply.embed
        }
    });
}
