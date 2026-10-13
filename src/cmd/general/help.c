#define _GNU_SOURCE

#include <bot/command.h>
#include <bot/cmd-category.h>

#include <lib/autofree.h>
#include <lib/string-utils.h>

static void cmd_help_handler(JustBotCommandAPI* api) {
    const char* prefix = api->bot->config.commands.prefix;
    const JustBotCommandCategory* current_cat = NULL;

    autofree char* embed_desc = NULL;
    APPEND(embed_desc, "Oto lista komend bota dla Twoje zapyziałego mózgu!\n");

    for (int cmd_index = 0; commands[cmd_index] != NULL; cmd_index++) {
        JustBotCommand* cmd = commands[cmd_index];

        if (current_cat != cmd->category) {
            current_cat = cmd->category;
            APPEND(embed_desc, "### %s %s\n\n", cmd->category->emoji, cmd->category->name);
        }
        
        APPEND(
            embed_desc, "- **%s%s** - %s\n",
            prefix, cmd->name, cmd->description.main
        );
    }

    api->reply.success(api, "Komendy bota!", embed_desc);
}

JustBotCommand cmd_help = {
    .name = "help",
    .description = {
        .main = "Wyświetla rozmaite komendy bota, by w końcu nauczyć twojego zapyziałego mózgu ich używania!",
        .shortened = "Wyświetla pomoc."
    },
    .category = &category_general,

    .flags = 0,
    .permissions.allowed_users = NULL,
    .permissions.allowed_roles = NULL,

    .execute = cmd_help_handler
};
