#pragma once

#include <stdint.h>

typedef struct {
    struct {
        char* prefix;

        struct {
            bool slash;
            bool prefix; 

            char** commands;
        } killswitches;

        struct {
            char* command_not_found_title;
            char* command_not_found_desc;

            char* killswitch_activated_title;
            char* killswitch_activated_desc;
        } shared_runner_messages;
    } commands;

    struct {
        char* path;
    } db;

    uint64_t guild_id;
} JustBotConfig;
