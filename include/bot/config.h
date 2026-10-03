#pragma once

#include <stdint.h>

typedef struct {
    struct {
        char* prefix;
    } commands;

    uint64_t guild_id;
} JustBotConfig;
