// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/cs_gameinterface.cpp
// Functions: 5
// ============================================================

#include "game\server\cstrike15\cs_gameinterface.h"

//------------------------------------------------------------------------------
// Address: 0x1026AC80
// Name: public: virtual void CServerGameClients::GetPlayerLimits(int __near &,int __near &,int __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameClients::GetPlayerLimits(
        CServerGameClients *this,
        int *minplayers,
        int *maxplayers,
        int *defaultMaxPlayers)
{
  *minplayers = 1;
  *maxplayers = 64;
  *defaultMaxPlayers = 32;
}

//------------------------------------------------------------------------------
// Address: 0x1026ACB0
// Name: private: void CServerGameDLL::LevelInit_ParseAllEntities(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerGameDLL::LevelInit_ParseAllEntities(CServerGameDLL *this, const char *pMapEntities)
{
  const char *pszValue; // eax

  pszValue = gpGlobals->mapname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  if ( _V_strcmp(s1: pszValue, s2: "cs_") != 0 )
    g_pResponseSystem->PrecacheResponses(this: g_pResponseSystem, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x1026ACF0
// Name: public: void CFmtStrN<256>::AppendFormat(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CFmtStrN<256>::AppendFormat(CFmtStrN<256> *this, const char *pchFormat, ...)
{
  CFmtStrN<256> *v2; // edi
  int m_nLength; // eax
  char *v4; // esi
  va_list params; // [esp+18h] [ebp+10h] BYREF

  va_start(params, pchFormat);
  v2 = this;
  m_nLength = this->m_nLength;
  v4 = &this->m_szBuf[m_nLength];
  HIBYTE(this) = 0;
  V_vsnprintfRet(pDest: v4, maxLen: 255 - m_nLength, pFormat: pchFormat, params, pbTruncated: (bool *)&this + 3);
  v4[-v2->m_nLength + 255] = 0;
  if ( HIBYTE(this) != 0 && !v2->m_bQuietTruncation && `CFmtStrN<256>::AppendFormat'::`4'::scAsserted < 5 )
    ++`CFmtStrN<256>::AppendFormat'::`4'::scAsserted;
  v2->m_nLength = _V_strlen(str: v2->m_szBuf);
}

//------------------------------------------------------------------------------
// Address: 0x1026AD70
// Name: public: virtual void CServerGameDLL::ApplyGameSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CServerGameDLL::ApplyGameSettings(
        CServerGameDLL *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        KeyValues *pKV)
{
  const char *String; // edi
  const char *v5; // ebx
  int v6; // eax
  ICvar_vtbl *v7; // eax
  CFmtStrN<256> command; // [esp+4h] [ebp-128h] BYREF
  ConVarRef cvFreestyleBotDiff; // [esp+110h] [ebp-1Ch] BYREF
  IKeyValuesDumpContext pDump; // [esp+118h] [ebp-14h] BYREF
  unsigned int richPresence; // [esp+11Ch] [ebp-10h]
  int freestyleBotDiff; // [esp+120h] [ebp-Ch]
  int maxPlayers; // [esp+124h] [ebp-8h] BYREF
  const char *pMapName; // [esp+128h] [ebp-4h]

  if ( pKV != nullptr && engine != nullptr )
  {
    DevMsg(a1: "CServerGameDLL::ApplyGameSettings game settings payload received:\n");
    pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
    richPresence = 1;
    KeyValues::Dump(this: pKV, &pDump, nIndentLevel: 1);
    pMapName = KeyValues::GetString(this: pKV, keyName: "game/bspname", defaultValue: locale);
    String = KeyValues::GetString(this: pKV, keyName: "game/type", defaultValue: locale);
    v5 = KeyValues::GetString(this: pKV, keyName: "game/mode", defaultValue: locale);
    if ( pMapName != nullptr && *pMapName != 0 )
    {
      v6 = 0;
      maxPlayers = 0;
      if ( String != nullptr && *String != 0 && v5 != nullptr && *v5 != 0 )
      {
        ConVarRef::ConVarRef(this: &cvFreestyleBotDiff, pName: "freestyle_bot_difficulty");
        v7 = g_pCVar->__vftable;
        freestyleBotDiff = cvFreestyleBotDiff.m_pConVarState->m_Value.m_nValue;
        ((void (__thiscall *)(ICvar *, int, int, int))v7->RevertFlaggedConVars)(a1: g_pCVar, a2: 0x2000, a3, a4: a2);
        g_pCVar->RevertFlaggedConVars(this: g_pCVar, a2: 0x4000);
        g_pGameTypes->SetGameTypeAndMode(this: g_pGameTypes, a2: String, a3: v5);
        if ( g_pGameTypes->GetCurrentGameMode(this: g_pGameTypes) == 2
          && g_pGameTypes->GetCurrentGameType(this: g_pGameTypes) == 0 )
        {
          g_pGameTypes->SetFreestyleBotDifficulty(this: g_pGameTypes, a2: freestyleBotDiff);
        }
        ((void (__thiscall *)(IGameTypes *, const char *, int *))g_pGameTypes->GetMapInfo)(
          a1: g_pGameTypes,
          a2: pMapName,
          a3: &maxPlayers);
        KeyValues::SetInt(this: pKV, keyName: "members/numExtraSpectatorSlots", value: 0);
        v6 = maxPlayers;
      }
      command.__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
      *(_WORD *)&command.m_bQuietTruncation = 1;
      command.m_nLength = 0;
      if ( v6 > 0 )
        CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(this: &command, pszFormat: "maxplayers %d\n", v6);
      CFmtStrN<256>::AppendFormat(this: &command, pchFormat: "map %s reserved\n", pMapName);
      engine->ServerCommand(this: engine, a2: command.m_szBuf);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026AF50
// Name: __CreateCGameMovementIGameMovement_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CCSGameMovement *__cdecl _CreateCGameMovementIGameMovement_interface()
{
  return &g_GameMovement;
}
