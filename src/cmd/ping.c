#include <stddef.h>

#include <bot/command.h>
#include <lib/logger.h>

static void cmd_ping_handler(JustBotCommandAPI* api) {
    api->reply.error(api, "Ping!", "Nie ma na razie non-error type shit 🥀");
}

const JustBotCommand cmd_ping = {
    .name = "ping",
    .description.main = "Taka komenda do sprawdzania czy bot działa. Useless 99\% of the time.",
    .description.shortened = "Pinguje bota!",

    .permissions.allowed_roles = NULL,
    .permissions.allowed_users = NULL,
    .flags = 0,

    .execute = cmd_ping_handler
};
