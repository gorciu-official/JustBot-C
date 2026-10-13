#include <math.h>

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
