#pragma once

#include <string.h>
#include <stdbool.h>

__attribute__((used))
static bool str_starts_with(const char* str, const char* prefix) {
    return strncmp(str, prefix, strlen(prefix)) == 0;
}

__attribute__((used))
static char* str_trim_prefix(char* source, char* prefix) {
    size_t len = strlen(prefix);

    if (strncmp(source, prefix, len) == 0)
        return source + len;

    return source;
}
