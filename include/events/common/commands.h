#pragma once

#include <bot/command.h>

typedef struct {
    const void* raw;
    JustBot* bot;

    char* invoked_command_name;

    DiscordGuildMember* member;
    DiscordUser* user;

    struct {
        void (*error)(struct JustBotCommandAPI* api, char* title, char* desc);
        void (*success)(struct JustBotCommandAPI* api, char* title, char* desc);
        void (*info)(struct JustBotCommandAPI* api, char* title, char* desc);
        void (*embed)(struct JustBotCommandAPI* api, DiscordEmbed* embed);
        void (*text)(struct JustBotCommandAPI* api, char* text);
    } reply;
} JustBotCCHInput;

#define JUSTBOT_CCHPD_MK_CMD_API_STUB(botd, rawd) \
    &(JustBotCommandAPI){ .bot = botd, .raw = rawd }

extern void bot_common_command_handler(JustBotCCHInput* data);
