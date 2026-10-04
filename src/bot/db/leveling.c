#include <lib/logger.h>
#include <bot/bot.h>

#include <sqlite3.h>

#include <stddef.h>
#include <stdint.h>

#include "boilerplate.h"

void bot_db_add_xp(JustBot* bot, uint64_t user_id, int xp) {
    int rc;
    sqlite3* db = bot->clients.sqlite;
    sqlite3_stmt* stmt = NULL;

    create_user_if_doesnt_exist(bot, &rc, &stmt, user_id);

    rc = sqlite3_prepare_v2(
        db,
        "UPDATE users SET xp = xp + ? WHERE user_id = ?",
        -1, &stmt, NULL
    );

    HANDLE_ERROR(rc)

    sqlite3_bind_int(stmt, 1, xp);
    sqlite3_bind_int64(stmt, 2, user_id);

    rc = sqlite3_step(stmt);

    HANDLE_ERROR(rc)

    sqlite3_finalize(stmt);
}

int bot_db_get_xp(JustBot* bot, uint64_t user_id) {
    int rc;
    sqlite3* db = bot->clients.sqlite;
    sqlite3_stmt* stmt = NULL;
    int xp = 0;

    create_user_if_doesnt_exist(bot, &rc, &stmt, user_id);

    rc = sqlite3_prepare_v2(
        db,
        "SELECT xp FROM users WHERE user_id = ?",
        -1, &stmt, NULL
    );

    HANDLE_ERROR_VAL(rc, 0)

    sqlite3_bind_int64(stmt, 1, user_id);

    rc = sqlite3_step(stmt);

    if (rc == SQLITE_ROW) {
        xp = sqlite3_column_int(stmt, 0);
    } else {
        HANDLE_ERROR_VAL(rc, 0)
    }

    sqlite3_finalize(stmt);

    return xp;
}
