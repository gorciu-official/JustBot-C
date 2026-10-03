#pragma once 

#include <stdint.h>
#include <concord.h>

#include <bot/bot.h>

struct JustBotCommand;

typedef struct JustBotCommandAPI {
    struct {
        char* used_alias;
        struct JustBotCommand* command;
        DiscordGuildMember* member;
    } invocation;

    const void* raw;
    JustBot* bot;

    struct {
        void (*error)(struct JustBotCommandAPI* api, char* title, char* desc);
        void (*success)(struct JustBotCommandAPI* api, char* title, char* desc);
        void (*info)(struct JustBotCommandAPI* api, char* title, char* desc);
    } reply;
} JustBotCommandAPI;

typedef struct JustBotCommand {
    char* name;
    struct {
        char* main;
        char* shortened;
    } description;

    struct {
        char** allowed_roles;
        char** allowed_users;
    } permissions;
    uint64_t flags;

    void (*execute)(JustBotCommandAPI* api);
} JustBotCommand;

extern JustBotCommand* commands[];

#define DECLARE_CMD(name) \
    extern JustBotCommand cmd_##name;
