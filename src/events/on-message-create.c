#include <bot/bot.h>

#include <lib/includes.h>
#include <lib/string-utils.h>
#include <string.h>

int compute_msg_xp(const DiscordMessage* msg, JustBot* bot) {
    float xp = bot->config.features.leveling.lvl_per_message;

    // excluded channels
    INCLUDES_I(bot->config.features.leveling.excluded_channels, a, in_excluded_channels, a == msg->channel_id)
    if (__builtin_expect(in_excluded_channels, 0)) {
        return 0;
    }

    // described attachment
    if (msg->attachments->size > 0 && strlen(msg->content) > bot->config.features.leveling.described_attachment_msg_threshold) {
        xp = xp * bot->config.features.leveling.described_attachment_multiplier;
    }
    
    // long messages
    if (strlen(msg->content) > bot->config.features.leveling.long_msg_threshold) {
        xp = xp * bot->config.features.leveling.long_msg_multiplier;
    }

    return (int)xp;
}

void bot_on_message_create(DiscordClient* client, const DiscordMessage* msg) {
    JustBot* bot = discord_get_data(client);
    char* prefix = bot->config.commands.prefix;

    if (str_starts_with(msg->content, prefix)) {
        bot_on_prefix_command(bot, msg);
    }

    char ai_prefix[32];
    snprintf(ai_prefix, sizeof(ai_prefix), "<@%" PRIu64 ">", bot->user.discord_user_id);

    if (str_starts_with(msg->content, ai_prefix)) {
        bot_on_ai_ping(bot, msg, &prefix[0]); 
    }

    bot_db_add_xp(bot, msg->author->id, compute_msg_xp(msg, bot));
}
