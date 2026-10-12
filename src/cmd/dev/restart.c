#include <stdlib.h>
#include <unistd.h>

#include <bot/command.h>

static void cmd_restart_handler(JustBotCommandAPI* api) {
    api->reply.success(api, "Wysłano sygnał restartu!", "JustBOT powinien za chwilę powrócić do pracy!");

    sleep(1);
    exit(0);
}

const JustBotCommand cmd_restart = {
    .name = "restart",
    .description = {
        .main = "Restartuje bota. Co ty myślałeś, że to robi? Że szyje na drutach?",
        .shortened = "Wykonuje restart bota."
    },
    .category = &category_dev,

    .flags = 0,
    .permissions.allowed_roles = NULL,
    .permissions.allowed_users = NULL,

    .execute = cmd_restart_handler
};
