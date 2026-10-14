#include <bot/bot.h>
#include <bot/leveling.h>
#include <bot/command.h>

#include <lib/autofree.h>

#include <stdio.h>

#define TOPLVL_COUNT 12
#define TOPLVL_TEXT_SIZE 128

static void cmd_toplvl_handler(JustBotCommandAPI* api) {
    int user_count = 0;

    autofree JustBotUser* users =
        bot_db_get_users_by_xp(api->bot, TOPLVL_COUNT, &user_count);

    if (!users || user_count <= 0) {
        return;
    }

    if (user_count > TOPLVL_COUNT) {
        user_count = TOPLVL_COUNT;
    }

    DiscordEmbedField fields[TOPLVL_COUNT] = {0};
    char field_names[TOPLVL_COUNT][TOPLVL_TEXT_SIZE] = {0};
    char field_values[TOPLVL_COUNT][TOPLVL_TEXT_SIZE] = {0};

    for (int i = 0; i < user_count; i++) {
        JustBotUser* user = &users[i];

        DiscordUser discord_user_data = {0};

        struct discord_ret_user retuser = {
            .sync = &discord_user_data
        };

        discord_get_user(
            api->bot->clients.discord,
            user->user_id,
            &retuser
        );

        DiscordUser* discord_user = &discord_user_data;

        if (discord_user && discord_user->username) {
            snprintf(
                field_names[i],
                sizeof(field_names[i]),
                "#%d - %s",
                i + 1,
                discord_user->username
            );
        } else {
            snprintf(
                field_names[i],
                sizeof(field_names[i]),
                "#%d - undefined",
                i + 1
            );
        }

        snprintf(
            field_values[i],
            sizeof(field_values[i]),
            "Level: %d\nXP: %d",
            xp2lvl(api->bot, user->xp),
            user->xp
        );

        fields[i].name = field_names[i];
        fields[i].value = field_values[i];
        fields[i].Inline = true;

        // TODO: memory leak ig!!! we probably gotta do .cleanup on retuser but it fucks up every time idk
    }

    DiscordEmbed embed = {
        .fields = &(struct discord_embed_fields){
            .array = fields,
            .size = user_count
        }
    }; 

    api->reply.embed(api, &embed);
}

const JustBotCommand cmd_toplvl = {
    .name = "toplvl",
    .aliases = (char*[]){ "topka", NULL },
    .description = {
        .main = "Czy chcesz zobaczyć januszów ~~biznesu~~ **pisania na serwerze**? To świetne miejsce dla Ciebie!",
        .shortened = "Wyświetla ludzi z największą ilością XP!"
    },
    .category = &category_leveling,

    .flags = 0,
    .permissions.allowed_roles = NULL,
    .permissions.allowed_users = NULL,

    .execute = cmd_toplvl_handler
};
