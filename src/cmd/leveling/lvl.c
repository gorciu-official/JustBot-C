#define _GNU_SOURCE

#include <stddef.h>
#include <stdint.h>

#include <bot/command.h>
#include <bot/leveling.h>

#include <lib/logger.h>
#include <lib/string-utils.h>
#include <lib/autofree.h>
#include <lib/progressbar.h>

static void cmd_lvl_handler(JustBotCommandAPI* api) {
    uint64_t user_id = api->invocation.user->id;
    char* user_avatar = api->invocation.user->avatar;
    char* nickname = api->invocation.user->username;

    int xp = bot_db_get_xp(api->bot, user_id);
    int level = xp2lvl(api->bot, xp);

    int current_level_xp = level2xp(api->bot, level);
    int next_level_xp = level2xp(api->bot, xp2lvl(api->bot, xp) + 1);

    int progress_xp = xp - current_level_xp;
    int needed_xp = next_level_xp - current_level_xp;

    autofree char* message = NULL;
    autofree char* user_avatar_url = NULL;
    autofree char* progressbar = mk_progress_bar(progress_xp, needed_xp, 15);

    APPEND(
        message,
        "**%s** ma level **%d** (XP: %d)!\n"
        "`%s %d/%d XP`\n\n"
        "Do następnego poziomu: %d XP - ok. %d wiad.",

        nickname, level, xp,

        progressbar, progress_xp, needed_xp, 

        next_level_xp - xp, (next_level_xp - xp) / api->bot->config.features.leveling.lvl_per_message
    );

    APPEND(
        user_avatar_url, "https://cdn.discordapp.com/avatars/%lu/%s.png?size=256",
        user_id, user_avatar
    );

    DiscordEmbed embed = {
        .title = "📊 Poziom użytkownika!",
        .author = &(DiscordEmbedAuthor){ .name = "JustBOT-C" },
        .color = 0x3498DB,
        .description = message,
        .thumbnail = &(DiscordEmbedThumbnail){ 
            .url = user_avatar_url 
        }
    };

    api->reply.embed(api, &embed);
}

const JustBotCommand cmd_lvl = {
    .name = "lvl",
    .description.main = "Wyświetl jak Ty (lub ktokolwiek inny) jest daleko w rankingu poziomów! Poziom objaw!",
    .description.shortened = "Wyświetl swój level lub level wskazanego użytkownika",
    .category = &category_leveling,

    .permissions.allowed_roles = NULL,
    .permissions.allowed_users = NULL,
    .flags = 0,

    .execute = cmd_lvl_handler
};
