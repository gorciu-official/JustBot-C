#include <stdlib.h>
#include <unistd.h>

#include <bot/command.h>

static void cmd_restart_handler(JustBotCommandAPI* api) {
    if (!getenv("JUSTBOT_LAUNCHED_VIA_PROD_LAUNCHER"))
        return api->reply.error(
            api, "To local instance!",
            "Bot **nie** został uruchomiony przez `sh scripts/prod-start.c`, także komenda `restart` by go po prostu wyłączyła a nie zrestartowała, pozdrawiam."
        );

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
    .permissions.allowed_roles = (uint64_t[]){ 1403684128485806182, 0 },
    .permissions.allowed_users = (uint64_t[]){ 0 },

    .execute = cmd_restart_handler
};
