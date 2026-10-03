#include <string.h>
#include <stdbool.h>

bool str_starts_with(const char* str, const char* prefix) {
    return strncmp(str, prefix, strlen(prefix)) == 0;
}
