#include <stddef.h>

#include <bot/command.h>
#include <lib/logger.h>

#include <stdint.h>
#include <math.h>

int xp2lvl(JustBot* bot, int xp) {
    return (int)floor(
        (1.0 + sqrt(1.0 + 8.0 * xp / bot->config.features.leveling.level_divider)) / 2.0
    );
}

int level2xp(JustBot* bot, int level) {
    return (int)floor(
        (level * (level - 1) / 2.0) * bot->config.features.leveling.level_divider
    );
}

static void cmd_lvl_handler(JustBotCommandAPI* api) {
    uint64_t user_id = api->invocation.user->id;
    char* nickname = api->invocation.user->username;

    int xp = bot_db_get_xp(api->bot, user_id);
    int level = xp2lvl(api->bot, xp);
    int next_level_xp = level2xp(api->bot, xp2lvl(api->bot, xp) + 1);

    char message[2000];

    snprintf(
        message, sizeof(message),
        "**%s** ma level **%d** (XP: %d)!\n"
        "Do next lvl: %d - ok. %d wiad.",
        nickname, level, xp,
        next_level_xp - xp, (next_level_xp - xp) / api->bot->config.features.leveling.lvl_per_message
    );

    api->reply.info(api, "Poziom użytkownika!", message);
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
