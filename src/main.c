#include <concord.h>
#include <discord-events.h>

#include <stdlib.h>
#include <string.h>
 
#define JUSTBOT_INTENTS \
        ( DISCORD_GATEWAY_DIRECT_MESSAGES                       \
        | DISCORD_GATEWAY_GUILD_MESSAGES                        \
        | DISCORD_GATEWAY_MESSAGE_CONTENT                       \
        | DISCORD_GATEWAY_GUILDS                                \
        | DISCORD_GATEWAY_GUILD_MEMBERS                         \
        | DISCORD_GATEWAY_GUILD_MESSAGE_REACTIONS               \
        )
 
void bot_on_message_create(struct discord*, const DiscordMessage* msg) {
    if (strcmp(msg->content, "sudo ping") == 0) {
        puts("YAY!!!!!!!!!!!!! I GOT PINGED! \n\n\n\n");
    }
}

int main() {
    printf("begin token:%s--end\n", getenv("JUSTBOT_TOKEN"));
    struct discord* client = discord_init(getenv("JUSTBOT_TOKEN"));
    discord_add_intents(client, JUSTBOT_INTENTS);
    discord_set_on_message_create(client, bot_on_message_create);
    discord_run(client);
}
