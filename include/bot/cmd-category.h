#pragma once

typedef struct {
    char* name;
    char* emoji;
} JustBotCommandCategory;

#define DECLARE_CATEGORY(catname) \
    extern JustBotCommandCategory category_##catname;

DECLARE_CATEGORY(general);
DECLARE_CATEGORY(dev);
DECLARE_CATEGORY(leveling);
