// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/cs_usermessages.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x101C9B90
// Name: void RegisterUserMessages(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RegisterUserMessages()
{
  CUserMessages::Register(this: usermessages, name: "Geiger", size: 1);
  CUserMessages::Register(this: usermessages, name: "Train", size: 1);
  CUserMessages::Register(this: usermessages, name: "HudText", size: -1);
  CUserMessages::Register(this: usermessages, name: "SayText", size: -1);
  CUserMessages::Register(this: usermessages, name: "SayText2", size: -1);
  CUserMessages::Register(this: usermessages, name: "TextMsg", size: -1);
  CUserMessages::Register(this: usermessages, name: "HudMsg", size: -1);
  CUserMessages::Register(this: usermessages, name: "ResetHUD", size: 1);
  CUserMessages::Register(this: usermessages, name: "GameTitle", size: 0);
  CUserMessages::Register(this: usermessages, name: "ItemPickup", size: -1);
  CUserMessages::Register(this: usermessages, name: "ShowMenu", size: -1);
  CUserMessages::Register(this: usermessages, name: "Shake", size: 13);
  CUserMessages::Register(this: usermessages, name: "Fade", size: 10);
  CUserMessages::Register(this: usermessages, name: "VGUIMenu", size: -1);
  CUserMessages::Register(this: usermessages, name: "Rumble", size: 3);
  CUserMessages::Register(this: usermessages, name: "CloseCaption", size: -1);
  CUserMessages::Register(this: usermessages, name: "CloseCaptionDirect", size: -1);
  CUserMessages::Register(this: usermessages, name: "SendAudio", size: -1);
  CUserMessages::Register(this: usermessages, name: "RawAudio", size: -1);
  CUserMessages::Register(this: usermessages, name: "VoiceMask", size: 17);
  CUserMessages::Register(this: usermessages, name: "RequestState", size: 0);
  CUserMessages::Register(this: usermessages, name: "BarTime", size: -1);
  CUserMessages::Register(this: usermessages, name: "Damage", size: -1);
  CUserMessages::Register(this: usermessages, name: "RadioText", size: -1);
  CUserMessages::Register(this: usermessages, name: "HintText", size: -1);
  CUserMessages::Register(this: usermessages, name: "KeyHintText", size: -1);
  CUserMessages::Register(this: usermessages, name: "ReloadEffect", size: 2);
  CUserMessages::Register(this: usermessages, name: "PlayerAnimEvent", size: -1);
  CUserMessages::Register(this: usermessages, name: "AmmoDenied", size: 2);
  CUserMessages::Register(this: usermessages, name: "UpdateRadar", size: -1);
  CUserMessages::Register(this: usermessages, name: "KillCam", size: -1);
  CUserMessages::Register(this: usermessages, name: "MarkAchievement", size: -1);
  CUserMessages::Register(this: usermessages, name: "DesiredTimescale", size: 16);
  CUserMessages::Register(this: usermessages, name: "CurrentTimescale", size: 4);
  CUserMessages::Register(this: usermessages, name: "PlayerStatsUpdate_DEPRECATED", size: -1);
  CUserMessages::Register(this: usermessages, name: "AchievementEvent", size: -1);
  CUserMessages::Register(this: usermessages, name: "MatchEndConditions", size: -1);
  CUserMessages::Register(this: usermessages, name: "MatchStatsUpdate", size: -1);
  CUserMessages::Register(this: usermessages, name: "PlayerStatsUpdate", size: -1);
  CUserMessages::Register(this: usermessages, name: "DisplayInventory", size: -1);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10297F20
// Name: void RegisterUserMessages(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RegisterUserMessages()
{
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"Geiger", size: 1);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"Train", size: 1);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"HudText", size: -1);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"SayText", size: -1);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"SayText2", size: -1);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"TextMsg", size: -1);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"HudMsg", size: -1);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"ResetHUD", size: 1);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"GameTitle", size: 0);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"ItemPickup", size: -1);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"ShowMenu", size: -1);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"Shake", size: 13);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"Fade", size: 10);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"VGUIMenu", size: -1);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"Rumble", size: 3);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"CloseCaption", size: -1);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"CloseCaptionDirect", size: -1);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"SendAudio", size: -1);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"RawAudio", size: -1);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"VoiceMask", size: 17);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"RequestState", size: 0);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"BarTime", size: -1);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"Damage", size: -1);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"RadioText", size: -1);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"HintText", size: -1);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"KeyHintText", size: -1);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"ReloadEffect", size: 2);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"PlayerAnimEvent", size: -1);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"AmmoDenied", size: 2);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"UpdateRadar", size: -1);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"KillCam", size: -1);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"MarkAchievement", size: -1);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"DesiredTimescale", size: 16);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"CurrentTimescale", size: 4);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"PlayerStatsUpdate_DEPRECATED", size: -1);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"AchievementEvent", size: -1);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"MatchEndConditions", size: -1);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"MatchStatsUpdate", size: -1);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"PlayerStatsUpdate", size: -1);
  CUserMessages::Register(this: usermessages, name: (CUserMessage *)"DisplayInventory", size: -1);
}

} // namespace server
