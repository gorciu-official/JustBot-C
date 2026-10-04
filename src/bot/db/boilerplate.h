#pragma once

#include <bot/bot.h>

#include <sqlite3.h>
#include <stdint.h>
#include <stddef.h>

#define HANDLE_ERROR_PANIC(rc, reason) \
    if (rc != SQLITE_OK && rc != SQLITE_DONE) { \
        logger_error("SQLite error: %s", sqlite3_errmsg(bot->clients.sqlite)); \
        return panic(reason); \
    } 

#define HANDLE_ERROR(rc) \
    if (rc != SQLITE_OK && rc != SQLITE_DONE) { \
        logger_error("SQLite error: %s", sqlite3_errmsg(bot->clients.sqlite)); \
        return; \
    }

#define HANDLE_ERROR_VAL(rc, val) \
    if (rc != SQLITE_OK && rc != SQLITE_DONE) { \
        logger_error("SQLite error: %s", sqlite3_errmsg(bot->clients.sqlite)); \
        return val; \
    }

__attribute__((used))
static inline void create_user_if_doesnt_exist(JustBot* bot, int* rc, sqlite3_stmt** stmt, uint64_t user_id) {
    *rc = sqlite3_prepare_v2(bot->clients.sqlite, "INSERT INTO USERS(user_id) VALUES(?)", -1, stmt, NULL);
    if (*rc != SQLITE_OK) return;
    sqlite3_bind_int64(*stmt, 1, user_id);
    *rc = sqlite3_step(*stmt);
    sqlite3_finalize(*stmt);
}
