#pragma once 

#include <stdint.h>
#include <concord.h>

#include <bot/bot.h>
#include <bot/cmd-category.h>

struct JustBotCommand;

typedef struct JustBotCommandAPI {
    struct {
        char* used_alias;
        struct JustBotCommand* command;
        DiscordGuildMember* member;
        DiscordUser* user;
    } invocation;

    const void* raw;
    JustBot* bot;

    struct {
        void (*error)(struct JustBotCommandAPI* api, char* title, char* desc);
        void (*success)(struct JustBotCommandAPI* api, char* title, char* desc);
        void (*info)(struct JustBotCommandAPI* api, char* title, char* desc);
        void (*embed)(struct JustBotCommandAPI* api, DiscordEmbed* embed);
        void (*text)(struct JustBotCommandAPI* api, char* text);
    } reply;
} JustBotCommandAPI;

typedef struct JustBotCommand {
    char* name;
    struct {
        char* main;
        char* shortened;
    } description;
    JustBotCommandCategory* category;

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
