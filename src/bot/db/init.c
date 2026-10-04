#include <lib/logger.h>
#include <bot/bot.h>

#include <sqlite3.h>

#include <stddef.h>

#include "boilerplate.h"

void bot_init_db(JustBot* bot) {
    int rc;

    rc = sqlite3_open(bot->config.db.path, &bot->clients.sqlite);

    HANDLE_ERROR_PANIC(rc, "Could not open database file")

    rc = sqlite3_exec(
        bot->clients.sqlite, 
        "CREATE TABLE IF NOT EXISTS users ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT,"
            "user_id INTEGER NOT NULL,"
            "xp INTEGER DEFAULT 0," 

            "money_wallet INTEGER DEFAULT 0,"
            "money_bank INTEGER DEFAULT 0"
        ")",
        NULL, NULL, NULL
    );

    HANDLE_ERROR_PANIC(rc, "Could not create base database structure")

    logger_log("DB initialized");
}
