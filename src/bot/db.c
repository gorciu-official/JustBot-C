#include <lib/logger.h>
#include <bot/bot.h>

#include <sqlite3.h>

void bot_init_db(JustBot* bot) {
    int rc = sqlite3_open(bot->config.db.path, &bot->clients.sqlite);

    if (rc != SQLITE_OK) {
        logger_error("SQLite error: %s", sqlite3_errmsg(bot->clients.sqlite));
        return panic("Could not open database file");
    }

    logger_log("DB initialized");
}
