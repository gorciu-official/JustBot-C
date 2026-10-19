#include <math.h>

#include <lib/includes.h>
#include <lib/string-utils.h>

#include <bot/bot.h>

int xp2lvl(JustBot* bot, int xp) {
    return (int)floor(
        (1.0 + sqrt(1.0 + 8.0 * xp / bot->config.features.leveling.level_divider)) / 2.0
    );
}

int level2xp(JustBot* bot, int level) {
    return (int)floor(
        (level * (level - 1) / 2.0) * bot->config.features.leveling.level_divider
    );
}

int compute_msg_xp(const DiscordMessage* msg, JustBot* bot) {
    // if you are retarted, then u don't get xp 
    if (msg->author->bot || str_starts_with(msg->content, bot->config.commands.prefix))
        return 0;

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
