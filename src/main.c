#include <bot/bot.h>
#include <stdlib.h>

static JustBot bot;

int main() {
    bot_init(&bot, &((JustBotSecrets){
        .discord_token = getenv("JUSTBOT_TOKEN")
    }));
}
