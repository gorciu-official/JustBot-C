#pragma once

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#define LOGGER_FUNCTION_DEF(name, level, color)                              \
    static void logger_impl_##name(const char* module,                       \
                                   const char* fmt, va_list args) {           \
        printf("[ " color level "\033[0m ] ");                               \
        if (module != NULL)                                                  \
            printf("\033[35m%s\033[0m: ", module);                           \
        vprintf(fmt, args);                                                  \
        printf("\n");                                                        \
    }                                                                        \
    __attribute__((used)) static void logger_##name(                         \
        const char* fmt, ...) {                                              \
        va_list args;                                                        \
        va_start(args, fmt);                                                 \
        logger_impl_##name(NULL, fmt, args);                                 \
        va_end(args);                                                        \
    }                                                                        \
    __attribute__((used)) static void logger_mod_##name(                     \
        const char* module, const char* fmt, ...) {                          \
        va_list args;                                                        \
        va_start(args, fmt);                                                 \
        logger_impl_##name(module, fmt, args);                               \
        va_end(args);                                                        \
    }

LOGGER_FUNCTION_DEF(log,   "INFO",  "\033[36m")
LOGGER_FUNCTION_DEF(warn,  "WARN",  "\033[33m")
LOGGER_FUNCTION_DEF(error, "ERROR", "\033[31m")

__attribute__((used))
static void panic(const char* reason) {
    logger_error("");
    logger_error("\033[91;1mFatal error\033[0m: %s", reason);
    logger_error("   If you believe this may be an error in JustBOT-C, please create an issue:");
    logger_error("      https://github.com/gorciu-official/JustBot-C/issues/new");
    abort();
}
