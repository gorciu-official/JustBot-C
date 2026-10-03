#pragma once

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#define LOGGER_FUNCTION_DEF(name, level, color) \
    __attribute__((used)) static void logger_##name(const char* fmt, ...) {  \
        va_list args;                           \
        va_start(args, fmt);                    \
        printf("[ " color level "\033[0m ] ");  \
        vprintf(fmt, args);                     \
        printf("\n");                           \
        va_end(args);                           \
    }

LOGGER_FUNCTION_DEF(log,   "INFO",  "\033[36m")
LOGGER_FUNCTION_DEF(warn,  "WARN",  "\033[33m")
LOGGER_FUNCTION_DEF(error, "ERROR", "\033[31m")

__attribute__((used))
static void panic(const char* reason) {
    logger_error("\033[91mFatal error\033[0m: %s", reason);
    logger_error("   If you believe this may be an error in JustBOT-C, please create an issue:");
    logger_error("      https://github.com/gorciu-official/JustBot-C/issues/new");
    abort();
}
