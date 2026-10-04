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

    struct {
        struct {
            int lvl_per_message;
            int level_divider;

            uint64_t long_msg_threshold;
            uint64_t described_attachment_msg_threshold;

            float long_msg_multiplier;
            float described_attachment_multiplier;

            uint64_t* excluded_channels;
        } leveling;
    } features;

    uint64_t guild_id;
} JustBotConfig;
