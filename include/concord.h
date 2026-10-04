#pragma once

#include "discord_codecs.h"
#include <stdint.h>

#include <discord.h>
#include <interaction.h>

typedef struct discord_activities DiscordActivities;
typedef struct discord_activity DiscordActivity;
typedef struct discord_activity_assets DiscordActivityAssets;
typedef struct discord_activity_button DiscordActivityButton;
typedef struct discord_activity_buttons DiscordActivityButtons;
typedef struct discord_activity_emoji DiscordActivityEmoji;
typedef struct discord_activity_party DiscordActivityParty;
typedef struct discord_activity_secrets DiscordActivitySecrets;
typedef struct discord_activity_timestamps DiscordActivityTimestamps;
typedef struct discord_add_guild_member DiscordAddGuildMember;
typedef struct discord_add_guild_member_role DiscordAddGuildMemberRole;
typedef struct discord_allowed_mention DiscordAllowedMention;
typedef struct discord_application DiscordApplication;
typedef struct discord_application_command DiscordApplicationCommand;
typedef struct discord_application_command_interaction_data_option DiscordApplicationCommandInteractionDataOption;
typedef struct discord_application_command_interaction_data_options DiscordApplicationCommandInteractionDataOptions;
typedef struct discord_application_command_option DiscordApplicationCommandOption;
typedef struct discord_application_command_option_choice DiscordApplicationCommandOptionChoice;
typedef struct discord_application_command_option_choices DiscordApplicationCommandOptionChoices;
typedef struct discord_application_command_options DiscordApplicationCommandOptions;
typedef struct discord_application_command_permission DiscordApplicationCommandPermission;
typedef struct discord_application_command_permissions DiscordApplicationCommandPermissions;
typedef struct discord_application_commands DiscordApplicationCommands;
typedef struct discord_attachment DiscordAttachment;
typedef struct discord_attachments DiscordAttachments;
typedef struct discord_attributes DiscordAttributes;
typedef struct discord_audit_log DiscordAuditLog;
typedef struct discord_audit_log_change DiscordAuditLogChange;
typedef struct discord_audit_log_changes DiscordAuditLogChanges;
typedef struct discord_audit_log_entries DiscordAuditLogEntries;
typedef struct discord_audit_log_entry DiscordAuditLogEntry;
typedef struct discord_auth_response DiscordAuthResponse;
typedef struct discord_auto_moderation_action DiscordAutoModerationAction;
typedef struct discord_auto_moderation_action_execution DiscordAutoModerationActionExecution;
typedef struct discord_auto_moderation_action_metadata DiscordAutoModerationActionMetadata;
typedef struct discord_auto_moderation_actions DiscordAutoModerationActions;
typedef struct discord_auto_moderation_rule DiscordAutoModerationRule;
typedef struct discord_auto_moderation_rules DiscordAutoModerationRules;
typedef struct discord_auto_moderation_trigger_metadata DiscordAutoModerationTriggerMetadata;
typedef struct discord_ban DiscordBan;
typedef struct discord_bans DiscordBans;
typedef struct discord_begin_guild_prune DiscordBeginGuildPrune;
typedef struct discord_bucket DiscordBucket;
typedef struct discord_bulk_delete_messages DiscordBulkDeleteMessages;
typedef struct discord_bulk_overwrite_guild_application_commands DiscordBulkOverwriteGuildApplicationCommands;
typedef struct discord_cache DiscordCache;
typedef struct discord_channel DiscordChannel;
typedef struct discord_channel_mention DiscordChannelMention;
typedef struct discord_channel_pins_update DiscordChannelPinsUpdate;
typedef struct discord_channels DiscordChannels;
typedef struct discord_client_status DiscordClientStatus;
typedef struct discord_component DiscordComponent;
typedef struct discord_component_item DiscordComponentItem;
typedef struct discord_component_items DiscordComponentItems;
typedef struct discord_component_media DiscordComponentMedia;
typedef struct discord_components DiscordComponents;
typedef struct discord_connection DiscordConnection;
typedef struct discord_connections DiscordConnections;
typedef struct discord_create_auto_moderation_rule DiscordCreateAutoModerationRule;
typedef struct discord_create_channel_invite DiscordCreateChannelInvite;
typedef struct discord_create_dm DiscordCreateDm;
typedef struct discord_create_followup_message DiscordCreateFollowupMessage;
typedef struct discord_create_global_application_command DiscordCreateGlobalApplicationCommand;
typedef struct discord_create_group_dm DiscordCreateGroupDm;
typedef struct discord_create_guild DiscordCreateGuild;
typedef struct discord_create_guild_application_command DiscordCreateGuildApplicationCommand;
typedef struct discord_create_guild_ban DiscordCreateGuildBan;
typedef struct discord_create_guild_channel DiscordCreateGuildChannel;
typedef struct discord_create_guild_emoji DiscordCreateGuildEmoji;
typedef struct discord_create_guild_from_guild_template DiscordCreateGuildFromGuildTemplate;
typedef struct discord_create_guild_role DiscordCreateGuildRole;
typedef struct discord_create_guild_scheduled_event DiscordCreateGuildScheduledEvent;
typedef struct discord_create_guild_sticker DiscordCreateGuildSticker;
typedef struct discord_create_guild_template DiscordCreateGuildTemplate;
typedef struct discord_create_message DiscordCreateMessage;
typedef struct discord_create_stage_instance DiscordCreateStageInstance;
typedef struct discord_create_webhook DiscordCreateWebhook;
typedef struct discord_delete_auto_moderation_rule DiscordDeleteAutoModerationRule;
typedef struct discord_delete_channel DiscordDeleteChannel;
typedef struct discord_delete_channel_permission DiscordDeleteChannelPermission;
typedef struct discord_delete_guild_emoji DiscordDeleteGuildEmoji;
typedef struct discord_delete_guild_integrations DiscordDeleteGuildIntegrations;
typedef struct discord_delete_guild_role DiscordDeleteGuildRole;
typedef struct discord_delete_guild_sticker DiscordDeleteGuildSticker;
typedef struct discord_delete_invite DiscordDeleteInvite;
typedef struct discord_delete_message DiscordDeleteMessage;
typedef struct discord_delete_stage_instance DiscordDeleteStageInstance;
typedef struct discord_delete_webhook DiscordDeleteWebhook;
typedef struct discord_delete_webhook_message DiscordDeleteWebhookMessage;
typedef struct discord_edit_channel_permissions DiscordEditChannelPermissions;
typedef struct discord_edit_followup_message DiscordEditFollowupMessage;
typedef struct discord_edit_global_application_command DiscordEditGlobalApplicationCommand;
typedef struct discord_edit_guild_application_command DiscordEditGuildApplicationCommand;
typedef struct discord_edit_message DiscordEditMessage;
typedef struct discord_edit_original_interaction_response DiscordEditOriginalInteractionResponse;
typedef struct discord_edit_webhook_message DiscordEditWebhookMessage;
typedef struct discord_embed DiscordEmbed;
typedef struct discord_embed_author DiscordEmbedAuthor;
typedef struct discord_embed_field DiscordEmbedField;
typedef struct discord_embed_fields DiscordEmbedFields;
typedef struct discord_embed_footer DiscordEmbedFooter;
typedef struct discord_embed_image DiscordEmbedImage;
typedef struct discord_embed_provider DiscordEmbedProvider;
typedef struct discord_embed_thumbnail DiscordEmbedThumbnail;
typedef struct discord_embed_video DiscordEmbedVideo;
typedef struct discord_embeds DiscordEmbeds;
typedef struct discord_emoji DiscordEmoji;
typedef struct discord_emojis DiscordEmojis;
typedef struct discord_execute_webhook DiscordExecuteWebhook;
typedef struct discord_follow_news_channel DiscordFollowNewsChannel;
typedef struct discord_followed_channel DiscordFollowedChannel;
typedef struct discord_gateway DiscordGateway;
typedef struct discord_gateway_payload DiscordGatewayPayload;
typedef struct discord_gateway_session DiscordGatewaySession;
typedef struct discord_get_channel_messages DiscordGetChannelMessages;
typedef struct discord_get_current_user_guilds DiscordGetCurrentUserGuilds;
typedef struct discord_get_guild_audit_log DiscordGetGuildAuditLog;
typedef struct discord_get_guild_prune_count DiscordGetGuildPruneCount;
typedef struct discord_get_guild_scheduled_event DiscordGetGuildScheduledEvent;
typedef struct discord_get_guild_scheduled_event_users DiscordGetGuildScheduledEventUsers;
typedef struct discord_get_guild_widget_image DiscordGetGuildWidgetImage;
typedef struct discord_get_invite DiscordGetInvite;
typedef struct discord_get_reactions DiscordGetReactions;
typedef struct discord_get_webhook_message DiscordGetWebhookMessage;
typedef struct discord_group_dm_add_recipient DiscordGroupDmAddRecipient;
typedef struct discord_guild DiscordGuild;
typedef struct discord_guild_application_command_permission DiscordGuildApplicationCommandPermission;
typedef struct discord_guild_application_command_permissions DiscordGuildApplicationCommandPermissions;
typedef struct discord_guild_ban_add DiscordGuildBanAdd;
typedef struct discord_guild_ban_remove DiscordGuildBanRemove;
typedef struct discord_guild_emojis_update DiscordGuildEmojisUpdate;
typedef struct discord_guild_integrations_update DiscordGuildIntegrationsUpdate;
typedef struct discord_guild_member DiscordGuildMember;
typedef struct discord_guild_member_remove DiscordGuildMemberRemove;
typedef struct discord_guild_member_update DiscordGuildMemberUpdate;
typedef struct discord_guild_members DiscordGuildMembers;
typedef struct discord_guild_members_chunk DiscordGuildMembersChunk;
typedef struct discord_guild_preview DiscordGuildPreview;
typedef struct discord_guild_role_create DiscordGuildRoleCreate;
typedef struct discord_guild_role_delete DiscordGuildRoleDelete;
typedef struct discord_guild_role_update DiscordGuildRoleUpdate;
typedef struct discord_guild_scheduled_event DiscordGuildScheduledEvent;
typedef struct discord_guild_scheduled_event_entity_metadata DiscordGuildScheduledEventEntityMetadata;
typedef struct discord_guild_scheduled_event_user DiscordGuildScheduledEventUser;
typedef struct discord_guild_scheduled_event_user_add DiscordGuildScheduledEventUserAdd;
typedef struct discord_guild_scheduled_event_user_remove DiscordGuildScheduledEventUserRemove;
typedef struct discord_guild_scheduled_event_users DiscordGuildScheduledEventUsers;
typedef struct discord_guild_scheduled_events DiscordGuildScheduledEvents;
typedef struct discord_guild_stickers_update DiscordGuildStickersUpdate;
typedef struct discord_guild_template DiscordGuildTemplate;
typedef struct discord_guild_templates DiscordGuildTemplates;
typedef struct discord_guild_widget DiscordGuildWidget;
typedef struct discord_guild_widget_settings DiscordGuildWidgetSettings;
typedef struct discord_guilds DiscordGuilds;
typedef struct discord_identify DiscordIdentify;
typedef struct discord_identify_connection DiscordIdentifyConnection;
typedef struct discord_install_params DiscordInstallParams;
typedef struct discord_integration DiscordIntegration;
typedef struct discord_integration_account DiscordIntegrationAccount;
typedef struct discord_integration_application DiscordIntegrationApplication;
typedef struct discord_integration_delete DiscordIntegrationDelete;
typedef struct discord_integrations DiscordIntegrations;
typedef struct discord_interaction DiscordInteraction;
typedef struct discord_interaction_callback_data DiscordInteractionCallbackData;
typedef struct discord_interaction_data DiscordInteractionData;
typedef struct discord_interaction_response DiscordInteractionResponse;
typedef struct discord_invite DiscordInvite;
typedef struct discord_invite_create DiscordInviteCreate;
typedef struct discord_invite_delete DiscordInviteDelete;
typedef struct discord_invite_metadata DiscordInviteMetadata;
typedef struct discord_invite_stage_instance DiscordInviteStageInstance;
typedef struct discord_invites DiscordInvites;
typedef struct discord_list_active_guild_threads DiscordListActiveGuildThreads;
typedef struct discord_list_active_threads DiscordListActiveThreads;
typedef struct discord_list_guild_members DiscordListGuildMembers;
typedef struct discord_list_guild_scheduled_events DiscordListGuildScheduledEvents;
typedef struct discord_list_nitro_sticker_packs DiscordListNitroStickerPacks;
typedef struct discord_message DiscordMessage;
typedef struct discord_message_activity DiscordMessageActivity;
typedef struct discord_message_commands DiscordMessageCommands;
typedef struct discord_message_delete DiscordMessageDelete;
typedef struct discord_message_delete_bulk DiscordMessageDeleteBulk;
typedef struct discord_message_interaction DiscordMessageInteraction;
typedef struct discord_message_reaction_add DiscordMessageReactionAdd;
typedef struct discord_message_reaction_remove DiscordMessageReactionRemove;
typedef struct discord_message_reaction_remove_all DiscordMessageReactionRemoveAll;
typedef struct discord_message_reaction_remove_emoji DiscordMessageReactionRemoveEmoji;
typedef struct discord_message_reference DiscordMessageReference;
typedef struct discord_messages DiscordMessages;
typedef struct discord_modify_auto_moderation_rule DiscordModifyAutoModerationRule;
typedef struct discord_modify_channel DiscordModifyChannel;
typedef struct discord_modify_current_member DiscordModifyCurrentMember;
typedef struct discord_modify_current_user DiscordModifyCurrentUser;
typedef struct discord_modify_current_user_nick DiscordModifyCurrentUserNick;
typedef struct discord_modify_current_user_voice_state DiscordModifyCurrentUserVoiceState;
typedef struct discord_modify_guild DiscordModifyGuild;
typedef struct discord_modify_guild_channel_position DiscordModifyGuildChannelPosition;
typedef struct discord_modify_guild_channel_positions DiscordModifyGuildChannelPositions;
typedef struct discord_modify_guild_emoji DiscordModifyGuildEmoji;
typedef struct discord_modify_guild_member DiscordModifyGuildMember;
typedef struct discord_modify_guild_role DiscordModifyGuildRole;
typedef struct discord_modify_guild_role_position DiscordModifyGuildRolePosition;
typedef struct discord_modify_guild_role_positions DiscordModifyGuildRolePositions;
typedef struct discord_modify_guild_scheduled_event DiscordModifyGuildScheduledEvent;
typedef struct discord_modify_guild_sticker DiscordModifyGuildSticker;
typedef struct discord_modify_guild_template DiscordModifyGuildTemplate;
typedef struct discord_modify_guild_welcome_screen DiscordModifyGuildWelcomeScreen;
typedef struct discord_modify_stage_instance DiscordModifyStageInstance;
typedef struct discord_modify_user_voice_state DiscordModifyUserVoiceState;
typedef struct discord_modify_webhook DiscordModifyWebhook;
typedef struct discord_modify_webhook_with_token DiscordModifyWebhookWithToken;
typedef struct discord_optional_audit_entry_info DiscordOptionalAuditEntryInfo;
typedef struct discord_optional_audit_entry_infos DiscordOptionalAuditEntryInfos;
typedef struct discord_overwrite DiscordOverwrite;
typedef struct discord_overwrites DiscordOverwrites;
typedef struct discord_pin_message DiscordPinMessage;
typedef struct discord_presence_update DiscordPresenceUpdate;
typedef struct discord_presence_updates DiscordPresenceUpdates;
typedef struct discord_prune_count DiscordPruneCount;
typedef struct discord_ratelimiter DiscordRatelimiter;
typedef struct discord_reaction DiscordReaction;
typedef struct discord_reaction_count_details DiscordReactionCountDetails;
typedef struct discord_reactions DiscordReactions;
typedef struct discord_ready DiscordReady;
typedef struct discord_refcounter DiscordRefcounter;
typedef struct discord_remove_guild_ban DiscordRemoveGuildBan;
typedef struct discord_remove_guild_member DiscordRemoveGuildMember;
typedef struct discord_remove_guild_member_role DiscordRemoveGuildMemberRole;
typedef struct discord_request DiscordRequest;
typedef struct discord_request_guild_members DiscordRequestGuildMembers;
typedef struct discord_requestor DiscordRequestor;
typedef struct discord_resolved_data DiscordResolvedData;
typedef struct discord_response DiscordResponse;
typedef struct discord_rest DiscordRest;
typedef struct discord_resume DiscordResume;
typedef struct discord_ret DiscordRet;
typedef struct discord_ret_application DiscordRetApplication;
typedef struct discord_ret_application_command DiscordRetApplicationCommand;
typedef struct discord_ret_application_command_permission DiscordRetApplicationCommandPermission;
typedef struct discord_ret_application_command_permissions DiscordRetApplicationCommandPermissions;
typedef struct discord_ret_application_commands DiscordRetApplicationCommands;
typedef struct discord_ret_audit_log DiscordRetAuditLog;
typedef struct discord_ret_auth_response DiscordRetAuthResponse;
typedef struct discord_ret_auto_moderation_rule DiscordRetAutoModerationRule;
typedef struct discord_ret_auto_moderation_rules DiscordRetAutoModerationRules;
typedef struct discord_ret_ban DiscordRetBan;
typedef struct discord_ret_bans DiscordRetBans;
typedef struct discord_ret_channel DiscordRetChannel;
typedef struct discord_ret_channels DiscordRetChannels;
typedef struct discord_ret_connections DiscordRetConnections;
typedef struct discord_ret_default_fields DiscordRetDefaultFields;
typedef struct discord_ret_dispatch DiscordRetDispatch;
typedef struct discord_ret_emoji DiscordRetEmoji;
typedef struct discord_ret_emojis DiscordRetEmojis;
typedef struct discord_ret_followed_channel DiscordRetFollowedChannel;
typedef struct discord_ret_guild DiscordRetGuild;
typedef struct discord_ret_guild_application_command_permissions DiscordRetGuildApplicationCommandPermissions;
typedef struct discord_ret_guild_member DiscordRetGuildMember;
typedef struct discord_ret_guild_members DiscordRetGuildMembers;
typedef struct discord_ret_guild_preview DiscordRetGuildPreview;
typedef struct discord_ret_guild_scheduled_event DiscordRetGuildScheduledEvent;
typedef struct discord_ret_guild_scheduled_event_users DiscordRetGuildScheduledEventUsers;
typedef struct discord_ret_guild_scheduled_events DiscordRetGuildScheduledEvents;
typedef struct discord_ret_guild_template DiscordRetGuildTemplate;
typedef struct discord_ret_guild_templates DiscordRetGuildTemplates;
typedef struct discord_ret_guild_widget DiscordRetGuildWidget;
typedef struct discord_ret_guild_widget_settings DiscordRetGuildWidgetSettings;
typedef struct discord_ret_guilds DiscordRetGuilds;
typedef struct discord_ret_integrations DiscordRetIntegrations;
typedef struct discord_ret_interaction_response DiscordRetInteractionResponse;
typedef struct discord_ret_invite DiscordRetInvite;
typedef struct discord_ret_invites DiscordRetInvites;
typedef struct discord_ret_list_nitro_sticker_packs DiscordRetListNitroStickerPacks;
typedef struct discord_ret_message DiscordRetMessage;
typedef struct discord_ret_messages DiscordRetMessages;
typedef struct discord_ret_prune_count DiscordRetPruneCount;
typedef struct discord_ret_response DiscordRetResponse;
typedef struct discord_ret_role DiscordRetRole;
typedef struct discord_ret_roles DiscordRetRoles;
typedef struct discord_ret_stage_instance DiscordRetStageInstance;
typedef struct discord_ret_sticker DiscordRetSticker;
typedef struct discord_ret_stickers DiscordRetStickers;
typedef struct discord_ret_thread_members DiscordRetThreadMembers;
typedef struct discord_ret_thread_response_body DiscordRetThreadResponseBody;
typedef struct discord_ret_user DiscordRetUser;
typedef struct discord_ret_users DiscordRetUsers;
typedef struct discord_ret_voice_regions DiscordRetVoiceRegions;
typedef struct discord_ret_webhook DiscordRetWebhook;
typedef struct discord_ret_webhooks DiscordRetWebhooks;
typedef struct discord_ret_welcome_screen DiscordRetWelcomeScreen;
typedef struct discord_role DiscordRole;
typedef struct discord_role_subscription_data DiscordRoleSubscriptionData;
typedef struct discord_role_tag DiscordRoleTag;
typedef struct discord_roles DiscordRoles;
typedef struct discord_search_guild_members DiscordSearchGuildMembers;
typedef struct discord_select_option DiscordSelectOption;
typedef struct discord_select_options DiscordSelectOptions;
typedef struct discord_session_start_limit DiscordSessionStartLimit;
typedef struct discord_stage_instance DiscordStageInstance;
typedef struct discord_stage_instances DiscordStageInstances;
typedef struct discord_start_thread_with_message DiscordStartThreadWithMessage;
typedef struct discord_start_thread_without_message DiscordStartThreadWithoutMessage;
typedef struct discord_sticker DiscordSticker;
typedef struct discord_sticker_item DiscordStickerItem;
typedef struct discord_sticker_items DiscordStickerItems;
typedef struct discord_sticker_pack DiscordStickerPack;
typedef struct discord_sticker_packs DiscordStickerPacks;
typedef struct discord_stickers DiscordStickers;
typedef struct discord_team DiscordTeam;
typedef struct discord_team_member DiscordTeamMember;
typedef struct discord_team_members DiscordTeamMembers;
typedef struct discord_thread_default_reaction DiscordThreadDefaultReaction;
typedef struct discord_thread_list_sync DiscordThreadListSync;
typedef struct discord_thread_member DiscordThreadMember;
typedef struct discord_thread_members DiscordThreadMembers;
typedef struct discord_thread_members_update DiscordThreadMembersUpdate;
typedef struct discord_thread_metadata DiscordThreadMetadata;
typedef struct discord_thread_response_body DiscordThreadResponseBody;
typedef struct discord_thread_tag DiscordThreadTag;
typedef struct discord_thread_tags DiscordThreadTags;
typedef struct discord_timer DiscordTimer;
typedef struct discord_timers DiscordTimers;
typedef struct discord_typing_start DiscordTypingStart;
typedef struct discord_unpin_message DiscordUnpinMessage;
typedef struct discord_update_voice_state DiscordUpdateVoiceState;
typedef struct discord_user DiscordUser;
typedef struct discord_users DiscordUsers;
typedef struct discord_voice_region DiscordVoiceRegion;
typedef struct discord_voice_regions DiscordVoiceRegions;
typedef struct discord_voice_server_update DiscordVoiceServerUpdate;
typedef struct discord_voice_state DiscordVoiceState;
typedef struct discord_voice_states DiscordVoiceStates;
typedef struct discord_webhook DiscordWebhook;
typedef struct discord_webhooks DiscordWebhooks;
typedef struct discord_webhooks_update DiscordWebhooksUpdate;
typedef struct discord_welcome_screen DiscordWelcomeScreen;
typedef struct discord_welcome_screen_channel DiscordWelcomeScreenChannel;
typedef struct discord_welcome_screen_channels DiscordWelcomeScreenChannels;

typedef CCORDcode DiscordErrorCode;

typedef u64snowflake DiscordSnowflake;

typedef DiscordSnowflake DiscordGuildID;
typedef DiscordSnowflake DiscordChannelID;
typedef DiscordSnowflake DiscordUserID;
typedef DiscordSnowflake DiscordRoleID;

typedef struct discord DiscordClient;

typedef struct discord_embed DiscordEmbed;
typedef struct discord_embeds DiscordEmbeds;

static inline DiscordErrorCode discord_reply_ret(DiscordClient* client, const DiscordMessage* reference, DiscordCreateMessage* params, DiscordRetMessage* ret) {
    DiscordCreateMessage new_params = {0};
    if (params == NULL)
        params = &new_params;

    DiscordMessageReference ref = {
        .message_id = reference->id,
        .channel_id = reference->channel_id,
        .guild_id = reference->guild_id
    };
    params->message_reference = &ref;
    return discord_create_message(client, reference->channel_id, params, ret);
}

static inline DiscordErrorCode discord_reply_embed_ret(DiscordClient* client, const DiscordMessage* reference, DiscordEmbed* embed, DiscordRetMessage* ret) {
    static DiscordEmbeds embeds = {
        .size = 1,
    };
    embeds.array = embed;
    
    DiscordCreateMessage params = (DiscordCreateMessage) {
        .embeds = &embeds,
    };
    return discord_reply_ret(client, reference, &params, ret);
}

static inline DiscordErrorCode discord_reply_embed(DiscordClient* client, const DiscordMessage* reference, DiscordEmbed* embed) {
    return discord_reply_embed_ret(client, reference, embed, NULL);
}

static inline DiscordErrorCode discord_interaction_reply_embed(DiscordClient* client, uint64_t event_id, char* event_token, DiscordEmbed* embed) {
    static DiscordEmbeds embeds = {
        .size = 1
    };
    embeds.array = embed;
    DiscordInteractionResponse params = {
        .type = DISCORD_INTERACTION_CHANNEL_MESSAGE_WITH_SOURCE,
        .data = &(DiscordInteractionCallbackData){
            .embeds = &embeds
        }
    };
    return discord_create_interaction_response(client, event_id, event_token, &params, NULL);
}

#define DISCORD_CUSTOMIZATION_ERROR_COLOR 0xff0000
#define DISCORD_CUSTOMIZATION_ERROR_EMOJI "🛑"
#define DISCORD_CUSTOMIZATION_SUCCESS_COLOR 0x00ff00
#define DISCORD_CUSTOMIZATION_SUCCESS_EMOJI "✅"
#define DISCORD_CUSTOMIZATION_INFO_COLOR 0x0000ff
#define DISCORD_CUSTOMIZATION_INFO_EMOJI "ℹ️"

#define DISCORD_REPLY_PREDEFINED_EMBED_STYLE(ecolor, eemoji, bot, msg, etitle, edesc) \
    do { \
        char _embed_title[256]; \
        snprintf(_embed_title, sizeof(_embed_title), "%s %s", eemoji, etitle); \
        discord_reply_embed(bot->clients.discord, msg, &(DiscordEmbed){ \
            .title = _embed_title, \
            .description = edesc, \
            .color = ecolor, \
            .author = &(DiscordEmbedAuthor){ .name = "JustBOT-C" } \
        }); \
    } while (0);

#define DISCORD_REPLY_ERROR(bot, msg, etitle, edesc) \
    DISCORD_REPLY_PREDEFINED_EMBED_STYLE(DISCORD_CUSTOMIZATION_ERROR_COLOR, DISCORD_CUSTOMIZATION_ERROR_EMOJI, bot, msg, etitle, edesc)

#define DISCORD_REPLY_SUCCESS(bot, msg, etitle, edesc) \
    DISCORD_REPLY_PREDEFINED_EMBED_STYLE(DISCORD_CUSTOMIZATION_SUCCESS_COLOR, DISCORD_CUSTOMIZATION_SUCCESS_EMOJI, bot, msg, etitle, edesc)

#define DISCORD_REPLY_INFO(bot, msg, etitle, edesc) \
    DISCORD_REPLY_PREDEFINED_EMBED_STYLE(DISCORD_CUSTOMIZATION_INFO_COLOR, DISCORD_CUSTOMIZATION_INFO_EMOJI, bot, msg, etitle, edesc)

#define DISCORD_IREPLY_PREDEFINED_EMBED_STYLE(ecolor, eemoji, bot, event_id, event_token, etitle, edesc) \
    do { \
        char _embed_title[256]; \
        snprintf(_embed_title, sizeof(_embed_title), "%s %s", eemoji, etitle); \
        discord_interaction_reply_embed(bot->clients.discord, event_id, event_token, &(DiscordEmbed){ \
            .title = _embed_title, \
            .description = edesc, \
            .color = ecolor, \
            .author = &(DiscordEmbedAuthor){ .name = "JustBOT-C" } \
        }); \
    } while (0)

#define DISCORD_IREPLY_ERROR(bot, event_id, event_token, etitle, edesc) \
    DISCORD_IREPLY_PREDEFINED_EMBED_STYLE(DISCORD_CUSTOMIZATION_ERROR_COLOR, DISCORD_CUSTOMIZATION_ERROR_EMOJI, bot, event_id, event_token, etitle, edesc)

#define DISCORD_IREPLY_SUCCESS(bot, event_id, event_token, etitle, edesc) \
    DISCORD_IREPLY_PREDEFINED_EMBED_STYLE(DISCORD_CUSTOMIZATION_SUCCESS_COLOR, DISCORD_CUSTOMIZATION_SUCCESS_EMOJI, bot, event_id, event_token, etitle, edesc)

#define DISCORD_IREPLY_INFO(bot, event_id, event_token, etitle, edesc) \
    DISCORD_IREPLY_PREDEFINED_EMBED_STYLE(DISCORD_CUSTOMIZATION_INFO_COLOR, DISCORD_CUSTOMIZATION_INFO_EMOJI, bot, event_id, event_token, etitle, edesc)
