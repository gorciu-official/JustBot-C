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

        struct {
            bool enabled;

            struct {
                bool politics;
                bool philosophy;
            } topic_restrictions;
        } ai;
    } features;

    uint64_t guild_id;
} JustBotConfig;
