// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/rungameengine.cpp
// Functions: 9
// ============================================================

#include "game\client\cstrike15\gameui\rungameengine.h"

//------------------------------------------------------------------------------
// Address: 0x100824C0
// Name: public: virtual bool CRunGameEngine::GetGameInfo(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CRunGameEngine::GetGameInfo(vgui::Panel *this, vgui::Menu *menu, vgui::Menu *msglist)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x101E6A10
// Name: public: virtual bool CRunGameEngine::AddTextCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRunGameEngine::AddTextCommand(CRunGameEngine *this, const char *text)
{
  engine->ClientCmd_Unrestricted(this: engine, a2: text);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101E6A30
// Name: public: virtual bool CRunGameEngine::RunEngine2(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CRunGameEngine::RunEngine2(vgui::TreeView *this, int itemIndex, vgui::Menu *menu, vgui::Menu *msglist)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x101E6A40
// Name: public: virtual bool CRunGameEngine::IsInGame(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CRunGameEngine::IsInGame(CRunGameEngine *this)
{
  return ((int (__thiscall *)(IVEngineClient *, CRunGameEngine *))engine->GetLevelName)(a1: engine, a2: this) != 0
      && strlen(engine->GetLevelName(this: engine)) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E6A90
// Name: public: virtual void CRunGameEngine::SetTrackerUserID(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRunGameEngine::SetTrackerUserID(CRunGameEngine *this, unsigned int trackerID, const char *trackerName)
{
  ConVarRef name; // [esp+4h] [ebp-8h] BYREF

  gameuifuncs->SetFriendsID(this: gameuifuncs, a2: trackerID, a3: trackerName);
  ConVarRef::ConVarRef(this: &name, pName: "name");
  if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&name)
    && trackerName != nullptr
    && *trackerName != 0
    && _V_strcmp(s1: name.m_pConVarState->m_Value.m_pszString, s2: "unnamed") == 0 )
  {
    name.m_pConVar->SetValue_4(this: name.m_pConVar, a2: trackerName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E6B00
// Name: public: virtual int CRunGameEngine::GetPlayerCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRunGameEngine::GetPlayerCount(CRunGameEngine *this)
{
  return engine->GetMaxClients(this: engine);
}

//------------------------------------------------------------------------------
// Address: 0x101E6B10
// Name: public: virtual unsigned int CRunGameEngine::GetPlayerFriendsID(int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CRunGameEngine::GetPlayerFriendsID(CRunGameEngine *this, int playerIndex)
{
  bool v2; // al
  player_info_s pi; // [esp+0h] [ebp-90h] BYREF

  v2 = engine->GetPlayerInfo(this: engine, a2: playerIndex, a3: &pi);
  return v2 ? pi.friendsID : 0;
}

//------------------------------------------------------------------------------
// Address: 0x101E6B50
// Name: public: virtual unsigned int CRunGameEngine::GetEngineBuildNumber(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CRunGameEngine::GetEngineBuildNumber(CRunGameEngine *this)
{
  return engine->GetEngineBuildNumber(this: engine);
}

//------------------------------------------------------------------------------
// Address: 0x101E6B60
// Name: public: virtual char const __near * CRunGameEngine::GetProductVersionString(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CRunGameEngine::GetProductVersionString(CRunGameEngine *this)
{
  return engine->GetProductVersionString(this: engine);
}
