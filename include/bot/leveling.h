#pragma once 

#include <bot/bot.h>

extern int level2xp(JustBot* bot, int level);
extern int xp2lvl(JustBot* bot, int xp);
extern int compute_msg_xp(const DiscordMessage* msg, JustBot* bot);
