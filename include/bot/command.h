#pragma once 

#include <stdint.h>

typedef struct {
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

    void (*execute)();
} JustBotCommand;

extern JustBotCommand* commands[];

#define DECLARE_CMD(name) \
    extern JustBotCommand cmd_##name;
