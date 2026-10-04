#include <stddef.h>

#include <bot/command.h>
#include <lib/logger.h>

#include <stdint.h>

static void cmd_lvl_handler(JustBotCommandAPI* api) {
    uint64_t user_id = api->invocation.user->id;
    int xp = bot_db_get_xp(api->bot, user_id);

    char message[128];

    snprintf(
        message,
        sizeof(message),
        "Masz **%d XP**.",
        xp
    );

    api->reply.info(api, "Twój poziom", message);
}

const JustBotCommand cmd_lvl = {
    .name = "lvl",
    .description.main = "Wyświetl jak Ty (lub ktokolwiek inny) jest daleko w rankingu poziomów! Poziom objaw!",
    .description.shortened = "Wyświetl swój level lub level wskazanego użytkownika",

    .permissions.allowed_roles = NULL,
    .permissions.allowed_users = NULL,
    .flags = 0,

    .execute = cmd_lvl_handler
};
