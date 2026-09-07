// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: matchmaking/mm_voice.cpp
// Functions: 53
// ============================================================

#include "matchmaking\mm_voice.h"

//------------------------------------------------------------------------------
// Address: 0x100045E0
// Name: public: virtual bool CMatchVoice::IsMachineMuted(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatchVoice::IsMachineMuted(CMatchVoice *this, unsigned __int64 xuidPlayer)
{
  return ((bool (__thiscall *)(CMatchVoice *, _DWORD, _DWORD))this->IsTalkerMuted)(
           a1: this,
           a2: xuidPlayer,
           a3: HIDWORD(xuidPlayer));
}

//------------------------------------------------------------------------------
// Address: 0x10004600
// Name: public: virtual void CMatchVoice::MuteTalker(unsigned __int64,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchVoice::MuteTalker(CMatchVoice *this, unsigned __int64 xuidTalker, bool bMute)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10004610
// Name: voice_reset_mutelist
// Source: json
//------------------------------------------------------------------------------
void __cdecl voice_reset_mutelist()
{
  ((void (__thiscall *)(CMatchVoice *, _DWORD, _DWORD, _DWORD))g_pMatchVoice->MuteTalker)(
    a1: g_pMatchVoice,
    a2: 0,
    a3: 0,
    a4: 0);
  _Msg(a1: "Mute list cleared.\n");
}

//------------------------------------------------------------------------------
// Address: 0x10004640
// Name: voice_mute
// Source: json
//------------------------------------------------------------------------------
void __cdecl voice_mute(const CCommand *args)
{
  int v1; // eax
  player_info_s pi; // [esp+10h] [ebp-94h] BYREF

  if ( args->m_nArgc == 2 )
  {
    v1 = V_atoi(str: args->m_ppArgv[1]);
    if ( g_pMatchExtensions->m_exts.m_pIVEngineClient->GetPlayerInfo(
           this: g_pMatchExtensions->m_exts.m_pIVEngineClient,
           a2: v1,
           a3: (player_info_s *)&pi.name[4])
      && *(unsigned __int64 *)((char *)&pi.xuid + 4) != 0 )
    {
      ((void (__thiscall *)(CMatchVoice *, _DWORD, _DWORD, int))g_pMatchVoice->MuteTalker)(
        a1: g_pMatchVoice,
        a2: HIDWORD(pi.xuid),
        a3: *(_DWORD *)pi.friendsName,
        a4: 1);
      _Msg(a1: "%s is now muted.\n", &pi.name[4]);
      return;
    }
    _Msg(a1: "Player# is invalid or refers to a bot, please use \"voice_show_mute\" command.\n");
  }
  _Msg(
    a1: "Example usage: voice_mute player#   -   where player# is a number that you can find with \"voice_show_mute\" command.\n");
}

//------------------------------------------------------------------------------
// Address: 0x100046E0
// Name: voice_unmute
// Source: json
//------------------------------------------------------------------------------
void __cdecl voice_unmute(const CCommand *args)
{
  IPlayerLocal *v1; // eax
  __int64 v2; // rax
  unsigned int v3; // ebx
  int v4; // edi
  int i; // esi
  const char *v6; // esi
  int v7; // eax
  player_info_s pi; // [esp+10h] [ebp-124h] BYREF
  _BYTE v9[80]; // [esp+A4h] [ebp-90h] BYREF
  __int64 v10; // [esp+F4h] [ebp-40h]

  if ( args->m_nArgc != 2 )
  {
usage_0:
    _Msg(
      a1: "Example usage: voice_unmute {player#|all}   -   where player# is a number that you can find with \"voice_show_mute"
      "\" command, or all to unmute all connected players.\n");
    return;
  }
  if ( _V_stricmp(s1: "all", s2: args->m_ppArgv[1]) != 0 )
  {
    if ( args->m_nArgc > 1 )
      v6 = args->m_ppArgv[1];
    else
      v6 = str;
    v7 = V_atoi(str: v6);
    if ( g_pMatchExtensions->m_exts.m_pIVEngineClient->GetPlayerInfo(
           this: g_pMatchExtensions->m_exts.m_pIVEngineClient,
           a2: v7,
           a3: (player_info_s *)&pi.name[4])
      && *(unsigned __int64 *)((char *)&pi.xuid + 4) != 0 )
    {
      ((void (__thiscall *)(CMatchVoice *, _DWORD, _DWORD, _DWORD))g_pMatchVoice->MuteTalker)(
        a1: g_pMatchVoice,
        a2: HIDWORD(pi.xuid),
        a3: *(_DWORD *)pi.friendsName,
        a4: 0);
      _Msg(a1: "%s is now unmuted.\n", &pi.name[4]);
      return;
    }
    _Msg(a1: "Player# is invalid or refers to a bot, please use \"voice_show_mute\" command.\n");
    goto usage_0;
  }
  v1 = g_pPlayerManager->GetLocalPlayer(this: g_pPlayerManager, a2: 0);
  v2 = v1->GetXUID(this: v1);
  *(_DWORD *)pi.name = HIDWORD(v2);
  v3 = v2;
  v4 = g_pMatchExtensions->m_exts.m_pIVEngineClient->GetMaxClients(this: g_pMatchExtensions->m_exts.m_pIVEngineClient);
  for ( i = 1; i <= v4; ++i )
  {
    if ( g_pMatchExtensions->m_exts.m_pIVEngineClient->GetPlayerInfo(
           this: g_pMatchExtensions->m_exts.m_pIVEngineClient,
           a2: i,
           a3: (player_info_s *)v9)
      && v10 != 0
      && v10 != __PAIR64__(*(unsigned int *)pi.name, v3) )
    {
      ((void (__thiscall *)(CMatchVoice *, _DWORD, _DWORD, _DWORD))g_pMatchVoice->MuteTalker)(
        a1: g_pMatchVoice,
        a2: v10,
        a3: HIDWORD(v10),
        a4: 0);
    }
  }
  _Msg(a1: "All connected players have been unmuted.\n");
}

//------------------------------------------------------------------------------
// Address: 0x10004850
// Name: voice_show_mute
// Source: json
//------------------------------------------------------------------------------
void __cdecl voice_show_mute()
{
  char v0; // bl
  IPlayerLocal *v1; // eax
  int v2; // ebp
  int v3; // edi
  int xuid_high; // edx
  int v5; // eax
  bool v6; // zf
  const char *v7; // eax
  unsigned __int64 xuidLocal_4; // [esp+10h] [ebp-9Ch]
  player_info_s pi; // [esp+18h] [ebp-94h] BYREF

  v0 = 0;
  v1 = g_pPlayerManager->GetLocalPlayer(this: g_pPlayerManager, a2: 0);
  xuidLocal_4 = v1->GetXUID(this: v1);
  v2 = g_pMatchExtensions->m_exts.m_pIVEngineClient->GetMaxClients(this: g_pMatchExtensions->m_exts.m_pIVEngineClient);
  v3 = 1;
  *(_DWORD *)pi.name = v2;
  if ( v2 < 1 )
    goto LABEL_13;
  do
  {
    if ( g_pMatchExtensions->m_exts.m_pIVEngineClient->GetPlayerInfo(
           this: g_pMatchExtensions->m_exts.m_pIVEngineClient,
           a2: v3,
           a3: (player_info_s *)&pi.name[4]) )
    {
      xuid_high = HIDWORD(pi.xuid);
      v5 = *(_DWORD *)pi.friendsName;
      if ( *(unsigned __int64 *)((char *)&pi.xuid + 4) != 0
        && *(unsigned __int64 *)((char *)&pi.xuid + 4) != xuidLocal_4 )
      {
        if ( v0 == 0 )
        {
          v0 = 1;
          _Msg(a1: "Player#     Player Name\n");
          _Msg(a1: "-------     ----------------\n");
          v5 = *(_DWORD *)pi.friendsName;
          xuid_high = HIDWORD(pi.xuid);
        }
        v6 = ((unsigned __int8 (__thiscall *)(CMatchVoice *, int, int))g_pMatchVoice->IsTalkerMuted)(
               a1: g_pMatchVoice,
               a2: xuid_high,
               a3: v5) == 0;
        v7 = "(muted)";
        if ( v6 )
          v7 = "       ";
        _Msg(a1: " % 2d %s %s\n", v3, v7, &pi.name[4]);
        v2 = *(_DWORD *)pi.name;
      }
    }
    ++v3;
  }
  while ( v3 <= v2 );
  if ( v0 != 0 )
    _Msg(a1: "-------     ----------------\n");
  else
LABEL_13:
    _Msg(a1: "No players currently connected who can be muted.\n");
}

//------------------------------------------------------------------------------
// Address: 0x10004970
// Name: class KeyValues __near * SessionMembersFindPlayer(class KeyValues __near *,unsigned __int64,class KeyValues __near * __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__cdecl SessionMembersFindPlayer(
        KeyValues *pSessionSettings,
        unsigned __int64 xuidPlayer,
        KeyValues **ppMachine)
{
  KeyValues *result; // eax
  KeyValues *v4; // edi
  int v5; // esi
  CFmtStrN<256> *v6; // eax
  KeyValues *Key; // eax
  KeyValues *v8; // ebx
  int Int; // ebp
  int v10; // edi
  CFmtStrN<256> *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // esi
  int numMachines; // [esp+4h] [ebp-20Ch]
  KeyValues *pMembers; // [esp+8h] [ebp-208h]
  KeyValues *v16; // [esp+Ch] [ebp-204h]
  CFmtStrN<256> v17; // [esp+10h] [ebp-200h] BYREF
  CFmtStrN<256> v18; // [esp+110h] [ebp-100h] BYREF

  if ( ppMachine != nullptr )
    *ppMachine = nullptr;
  if ( pSessionSettings == nullptr )
    return nullptr;
  result = KeyValues::FindKey(this: pSessionSettings, keyName: "Members", bCreate: false);
  v4 = result;
  v16 = result;
  if ( result != nullptr )
  {
    v5 = 0;
    pMembers = (KeyValues *)KeyValues::GetInt(this: result, keyName: "numMachines", defaultValue: 0);
    numMachines = 0;
    if ( (int)pMembers > 0 )
    {
      while ( 1 )
      {
        v6 = CFmtStrN<256>::CFmtStrN<256>(this: &v17, pszFormat: "machine%d", v5);
        Key = KeyValues::FindKey(this: v4, keyName: v6->m_szBuf, bCreate: false);
        v8 = Key;
        if ( Key != nullptr )
        {
          Int = KeyValues::GetInt(this: Key, keyName: "numPlayers", defaultValue: 0);
          v10 = 0;
          if ( Int > 0 )
            break;
        }
LABEL_15:
        numMachines = ++v5;
        if ( v5 >= (int)pMembers )
          return nullptr;
        v4 = v16;
      }
      while ( 1 )
      {
        v11 = CFmtStrN<256>::CFmtStrN<256>(this: &v18, pszFormat: "player%d", v10);
        v12 = KeyValues::FindKey(this: v8, keyName: v11->m_szBuf, bCreate: false);
        v13 = v12;
        if ( v12 != nullptr && KeyValues::GetUint64(this: v12, keyName: "xuid", defaultValue: 0) == xuidPlayer )
          break;
        if ( ++v10 >= Int )
        {
          v5 = numMachines;
          goto LABEL_15;
        }
      }
      if ( ppMachine != nullptr )
        *ppMachine = v8;
      return v13;
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10004AB0
// Name: protected: bool CMatchVoice::IsMachineMutingLocalTalkers(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMatchVoice::IsMachineMutingLocalTalkers(CMatchVoice *this, unsigned __int64 xuidPlayer)
{
  IMatchSession *v2; // eax
  KeyValues *v4; // esi
  KeyValues *v5; // edi
  IPlayerLocal *v6; // eax
  unsigned __int64 v7; // rax
  KeyValues *v8; // ebx
  KeyValues *Key; // eax
  KeyValues *FirstValue; // esi
  unsigned __int64 Uint64; // kr00_8
  int v12; // esi
  CFmtStrN<256> *v13; // eax
  int numLocalPlayers; // [esp+4h] [ebp-108h] BYREF
  int Int; // [esp+8h] [ebp-104h]
  CFmtStrN<256> v16; // [esp+Ch] [ebp-100h] BYREF

  v2 = g_pMatchFramework->GetMatchSession(this: g_pMatchFramework);
  if ( v2 == nullptr )
    return 0;
  v4 = v2->GetSessionSettings(this: v2);
  numLocalPlayers = 0;
  SessionMembersFindPlayer(pSessionSettings: v4, xuidPlayer, ppMachine: (KeyValues **)&numLocalPlayers);
  v5 = (KeyValues *)numLocalPlayers;
  if ( numLocalPlayers == 0 )
    return 0;
  v6 = g_pPlayerManager->GetLocalPlayer(this: g_pPlayerManager, a2: 0);
  v7 = v6->GetXUID(this: v6);
  numLocalPlayers = 0;
  SessionMembersFindPlayer(pSessionSettings: v4, xuidPlayer: v7, ppMachine: (KeyValues **)&numLocalPlayers);
  v8 = (KeyValues *)numLocalPlayers;
  if ( numLocalPlayers == 0 )
    return 0;
  if ( (KeyValues *)numLocalPlayers == v5 )
    return 0;
  Int = KeyValues::GetInt(this: (KeyValues *)numLocalPlayers, keyName: "numPlayers", defaultValue: 0);
  Key = KeyValues::FindKey(this: v5, keyName: "Mutelist", bCreate: false);
  if ( Key == nullptr )
    return 0;
  FirstValue = KeyValues::GetFirstValue(this: Key);
  numLocalPlayers = (int)FirstValue;
  if ( FirstValue == nullptr )
    return 0;
  while ( 1 )
  {
    Uint64 = KeyValues::GetUint64(this: FirstValue, keyName: nullptr, defaultValue: 0);
    if ( Uint64 != 0 )
    {
      v12 = 0;
      if ( Int > 0 )
        break;
LABEL_15:
      FirstValue = (KeyValues *)numLocalPlayers;
    }
    numLocalPlayers = (int)KeyValues::GetNextValue(this: FirstValue);
    if ( numLocalPlayers == 0 )
      return 0;
    FirstValue = (KeyValues *)numLocalPlayers;
  }
  while ( 1 )
  {
    v13 = CFmtStrN<256>::CFmtStrN<256>(this: &v16, pszFormat: "player%d/xuid", v12);
    if ( Uint64 == KeyValues::GetUint64(this: v8, keyName: v13->m_szBuf, defaultValue: 0) )
      return 1;
    if ( ++v12 >= Int )
      goto LABEL_15;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004C30
// Name: public: virtual bool CMatchVoice::CanPlaybackTalker(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatchVoice::CanPlaybackTalker(CMatchVoice *this, unsigned __int64 xuidTalker)
{
  return CMatchVoice::IsMachineMutingLocalTalkers(this, xuidPlayer: xuidTalker) == 0
      && ((unsigned __int8 (__thiscall *)(CMatchVoice *, _DWORD, _DWORD))this->IsMachineMuted)(
           a1: this,
           a2: xuidTalker,
           a3: HIDWORD(xuidTalker)) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10004C70
// Name: public: virtual bool CMatchVoice::IsTalkerMuted(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatchVoice::IsTalkerMuted(CMatchVoice *this, unsigned __int64 xuidTalker)
{
  int m_Size; // edx
  int v3; // eax
  unsigned __int64 *i; // ecx

  m_Size = this->m_arrMutedTalkers.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return false;
  for ( i = this->m_arrMutedTalkers.m_Memory.m_pMemory; *i != xuidTalker; ++i )
  {
    if ( ++v3 >= m_Size )
      return false;
  }
  return v3 != -1;
}

//------------------------------------------------------------------------------
// Address: 0x10021980
// Name: _dynamic_initializer_for__voice_reset_mutelist_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_reset_mutelist_command__()
{
  ConCommand::ConCommand(
    this: &voice_reset_mutelist_command,
    pName: "voice_reset_mutelist",
    callback: (void (__cdecl *)(const CCommand *))voice_reset_mutelist,
    pHelpString: "Reset all mute information for all players who were ever muted.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__voice_reset_mutelist_command__);
}

//------------------------------------------------------------------------------
// Address: 0x100219B0
// Name: _dynamic_initializer_for__voice_mute_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_mute_command__()
{
  ConCommand::ConCommand(
    this: &voice_mute_command,
    pName: "voice_mute",
    callback: voice_mute,
    pHelpString: "Mute a specific Steam user",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__voice_mute_command__);
}

//------------------------------------------------------------------------------
// Address: 0x100219E0
// Name: _dynamic_initializer_for__voice_unmute_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_unmute_command__()
{
  ConCommand::ConCommand(
    this: &voice_unmute_command,
    pName: "voice_unmute",
    callback: voice_unmute,
    pHelpString: "Unmute a specific Steam user, or `all` to unmute all connected players.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__voice_unmute_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10021A10
// Name: _dynamic_initializer_for__voice_show_mute_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_show_mute_command__()
{
  ConCommand::ConCommand(
    this: &voice_show_mute_command,
    pName: "voice_show_mute",
    callback: (void (__cdecl *)(const CCommand *))voice_show_mute,
    pHelpString: "Show whether current players are muted.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__voice_show_mute_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10021ED0
// Name: _dynamic_atexit_destructor_for__voice_reset_mutelist_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_reset_mutelist_command__()
{
  ConCommand::~ConCommand(this: &voice_reset_mutelist_command);
}

//------------------------------------------------------------------------------
// Address: 0x10021EE0
// Name: _dynamic_atexit_destructor_for__voice_mute_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_mute_command__()
{
  ConCommand::~ConCommand(this: &voice_mute_command);
}

//------------------------------------------------------------------------------
// Address: 0x10021EF0
// Name: _dynamic_atexit_destructor_for__voice_unmute_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_unmute_command__()
{
  ConCommand::~ConCommand(this: &voice_unmute_command);
}

//------------------------------------------------------------------------------
// Address: 0x10021F00
// Name: _dynamic_atexit_destructor_for__voice_show_mute_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_show_mute_command__()
{
  ConCommand::~ConCommand(this: &voice_show_mute_command);
}

//------------------------------------------------------------------------------
// Address: 0x10021A40
// Name: _dynamic_initializer_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::CExpressionEvaluator(this: &g_ExpressionEvaluator);
  return atexit(func: dynamic_atexit_destructor_for__g_ExpressionEvaluator__);
}

//------------------------------------------------------------------------------
// Address: 0x10021A60
// Name: _dynamic_initializer_for__g_KVMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KVMutex__()
{
  g_KVMutex.m_ownerID = 0;
  g_KVMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10021A70
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  s_EmptyConVar.m_Value.m_StringLength = strlen("0") + 1;
  s_EmptyConVar.m_Value.m_pszString = (char *)operator new(nSize: s_EmptyConVar.m_Value.m_StringLength);
  memcpy(
    dst: (unsigned __int8 *)s_EmptyConVar.m_Value.m_pszString,
    src: (unsigned __int8 *)s_EmptyConVar.m_pszDefaultValue,
    count: s_EmptyConVar.m_Value.m_StringLength);
  if ( !ConVar::InternalSetColorFromString(this: &s_EmptyConVar, value: s_EmptyConVar.m_Value.m_pszString) )
  {
    s_EmptyConVar.m_Value.m_fValue = atof(nptr: s_EmptyConVar.m_Value.m_pszString);
    if ( (LODWORD(s_EmptyConVar.m_Value.m_fValue) & 0x7F800000) == 0x7F800000 )
    {
      _Warning(a1: "ConVar(%s) defined with infinite float value (%s)\n", str, s_EmptyConVar.m_Value.m_pszString);
      s_EmptyConVar.m_Value.m_fValue = 3.4028235e38;
    }
    s_EmptyConVar.m_Value.m_nValue = (int)s_EmptyConVar.m_Value.m_fValue;
  }
  s_EmptyConVar.m_bRegistered = false;
  s_EmptyConVar.m_pszName = str;
  s_EmptyConVar.m_pszHelpString = empty_string;
  s_EmptyConVar.m_nFlags = 0;
  s_EmptyConVar.m_pNext = ConCommandBase::s_pConCommandBases;
  ConCommandBase::s_pConCommandBases = &s_EmptyConVar;
  if ( ConCommandBase::s_pAccessor != nullptr )
    s_EmptyConVar.Init(this: &s_EmptyConVar);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&CEmptyConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&CEmptyConVar::`vftable'{for `IConVar'};
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x10021BA0
// Name: _dynamic_initializer_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupSymbolTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10021BB0
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **dynamic_initializer_for__s_StringCharConversion__()
{
  char **result; // eax
  int v1; // edx
  char v2; // cl

  CUtlCharConversion::CUtlCharConversion(
    this: &s_StringCharConversion,
    nEscapeChar: 92,
    pDelimiter: "\"",
    nCount: 11,
    pArray: s_pConversionArrays_StringCharConversion);
  s_StringCharConversion.__vftable = (CUtlCStringConversion_vtbl *)&CUtlCStringConversion::`vftable';
  memset(
    dst: (unsigned __int8 *)s_StringCharConversion.m_pConversion,
    value: 0,
    count: sizeof(s_StringCharConversion.m_pConversion));
  result = &s_pConversionArrays_StringCharConversion[0].m_pReplacementString;
  do
  {
    v1 = **result;
    v2 = *((_BYTE *)result - 4);
    result += 2;
    s_StringCharConversion.m_pConversion[v1] = v2;
  }
  while ( (int)result < (int)&s_pConversionArrays_NoEscConversion[0].m_pReplacementString );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10021C10
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_NoEscConversion__()
{
  CUtlCharConversion *result; // eax

  result = CUtlCharConversion::CUtlCharConversion(
             this: &s_NoEscConversion,
             nEscapeChar: 127,
             pDelimiter: "\"",
             nCount: 1,
             pArray: s_pConversionArrays_NoEscConversion);
  s_NoEscConversion.__vftable = (CUtlNoEscConversion_vtbl *)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10021C40
// Name: _dynamic_initializer_for__g_BitWriteMasksInit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBitWriteMasksInit *dynamic_initializer_for__g_BitWriteMasksInit__()
{
  return CBitWriteMasksInit::CBitWriteMasksInit(this: &g_BitWriteMasksInit);
}

//------------------------------------------------------------------------------
// Address: 0x10021C50
// Name: _dynamic_atexit_destructor_for__g_MatchTitle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MatchTitle__()
{
  CMatchTitle::~CMatchTitle(this: &g_MatchTitle);
}

//------------------------------------------------------------------------------
// Address: 0x10021C60
// Name: _dynamic_atexit_destructor_for__g_MatchExtensions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MatchExtensions__()
{
  g_MatchExtensions.__vftable = (CMatchExtensions_vtbl *)&CMatchExtensions::`vftable';
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_MatchExtensions.m_mapRegisteredInterfaces.m_SymbolTable);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_MatchExtensions.m_mapRegisteredInterfaces);
}

//------------------------------------------------------------------------------
// Address: 0x10021C80
// Name: _dynamic_atexit_destructor_for__g_MatchFramework__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MatchFramework__()
{
  CMatchFramework::~CMatchFramework(this: &g_MatchFramework);
}

//------------------------------------------------------------------------------
// Address: 0x10021C90
// Name: _dynamic_atexit_destructor_for__mm_events_listeners_validation__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_events_listeners_validation__()
{
  ConVar::~ConVar(this: &mm_events_listeners_validation);
}

//------------------------------------------------------------------------------
// Address: 0x10021CA0
// Name: _dynamic_atexit_destructor_for__mm_datacenter_update_interval__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_datacenter_update_interval__()
{
  ConVar::~ConVar(this: &mm_datacenter_update_interval);
}

//------------------------------------------------------------------------------
// Address: 0x10021CB0
// Name: _dynamic_atexit_destructor_for__mm_datacenter_retry_interval__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_datacenter_retry_interval__()
{
  ConVar::~ConVar(this: &mm_datacenter_retry_interval);
}

//------------------------------------------------------------------------------
// Address: 0x10021CC0
// Name: _dynamic_atexit_destructor_for__mm_datacenter_query_delay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_datacenter_query_delay__()
{
  ConVar::~ConVar(this: &mm_datacenter_query_delay);
}

//------------------------------------------------------------------------------
// Address: 0x10021CD0
// Name: _dynamic_atexit_destructor_for__mm_datacenter_report_version__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_datacenter_report_version__()
{
  ConVar::~ConVar(this: &mm_datacenter_report_version);
}

//------------------------------------------------------------------------------
// Address: 0x10021CE0
// Name: _dynamic_atexit_destructor_for__mm_datacenter_debugprint_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_datacenter_debugprint_command__()
{
  ConCommand::~ConCommand(this: &mm_datacenter_debugprint_command);
}

//------------------------------------------------------------------------------
// Address: 0x10021CF0
// Name: _dynamic_atexit_destructor_for__g_Datacenter__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Datacenter__()
{
  g_Datacenter.IDatacenter::__vftable = (CDatacenter_vtbl *)&CDatacenter::`vftable'{for `IDatacenter'};
  g_Datacenter.IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&CDatacenter::`vftable'{for `IMatchEventsSink'};
  if ( g_Datacenter.m_pInfoChunks != nullptr )
    KeyValues::deleteThis(this: g_Datacenter.m_pInfoChunks);
  g_Datacenter.m_pInfoChunks = nullptr;
  if ( g_Datacenter.m_pDataInfo != nullptr )
    KeyValues::deleteThis(this: g_Datacenter.m_pDataInfo);
  g_Datacenter.m_pDataInfo = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10021D40
// Name: _dynamic_atexit_destructor_for__mm_server_search_update_interval__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_server_search_update_interval__()
{
  ConVar::~ConVar(this: &mm_server_search_update_interval);
}

//------------------------------------------------------------------------------
// Address: 0x10021D50
// Name: _dynamic_atexit_destructor_for__mm_server_search_inet_ping_interval__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_server_search_inet_ping_interval__()
{
  ConVar::~ConVar(this: &mm_server_search_inet_ping_interval);
}

//------------------------------------------------------------------------------
// Address: 0x10021D60
// Name: _dynamic_atexit_destructor_for__mm_server_search_inet_ping_timeout__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_server_search_inet_ping_timeout__()
{
  ConVar::~ConVar(this: &mm_server_search_inet_ping_timeout);
}

//------------------------------------------------------------------------------
// Address: 0x10021D70
// Name: _dynamic_atexit_destructor_for__mm_server_search_inet_ping_window__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_server_search_inet_ping_window__()
{
  ConVar::~ConVar(this: &mm_server_search_inet_ping_window);
}

//------------------------------------------------------------------------------
// Address: 0x10021D80
// Name: _dynamic_atexit_destructor_for__mm_server_search_lan_ping_interval__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_server_search_lan_ping_interval__()
{
  ConVar::~ConVar(this: &mm_server_search_lan_ping_interval);
}

//------------------------------------------------------------------------------
// Address: 0x10021D90
// Name: _dynamic_atexit_destructor_for__mm_server_search_lan_ping_duration__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_server_search_lan_ping_duration__()
{
  ConVar::~ConVar(this: &mm_server_search_lan_ping_duration);
}

//------------------------------------------------------------------------------
// Address: 0x10021DA0
// Name: _dynamic_atexit_destructor_for__mm_server_search_lan_ports__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_server_search_lan_ports__()
{
  ConVar::~ConVar(this: &mm_server_search_lan_ports);
}

//------------------------------------------------------------------------------
// Address: 0x10021DB0
// Name: _dynamic_atexit_destructor_for__g_ServerManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ServerManager__()
{
  g_ServerManager.IServerManager::__vftable = (CServerManager_vtbl *)&CServerManager::`vftable'{for `IServerManager'};
  g_ServerManager.IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&CServerManager::`vftable'{for `IMatchEventsSink'};
  CUtlVector<CServer *,CUtlMemory<CServer *,int>>::PurgeAndDeleteElements(this: &g_ServerManager.m_Servers);
  CUtlVector<CServer *,CUtlMemory<CServer *,int>>::PurgeAndDeleteElements(this: &g_ServerManager.m_ServersPinging);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_ServerManager.m_ServersPinging);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_ServerManager.m_Servers);
}

//------------------------------------------------------------------------------
// Address: 0x10021DF0
// Name: _dynamic_atexit_destructor_for__g_MatchEventsSubscription__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MatchEventsSubscription__()
{
  g_MatchEventsSubscription.__vftable = (CMatchEventsSubscription_vtbl *)&CMatchEventsSubscription::`vftable';
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_MatchEventsSubscription.m_arrSentEvents);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_MatchEventsSubscription.m_arrEventData);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_MatchEventsSubscription.m_arrQueuedEvents);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_MatchEventsSubscription.m_arrIteratorsOutstanding);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_MatchEventsSubscription.m_arrRefCount);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_MatchEventsSubscription.m_arrSinks);
}

//------------------------------------------------------------------------------
// Address: 0x10021E40
// Name: _dynamic_atexit_destructor_for__g_MatchNetMsgControllerBase__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MatchNetMsgControllerBase__()
{
  g_MatchNetMsgControllerBase.__vftable = (CMatchNetworkMsgControllerBase_vtbl *)&CMatchNetworkMsgControllerBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10021E50
// Name: _dynamic_atexit_destructor_for__s_MatchSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_MatchSystem__()
{
  s_MatchSystem.__vftable = (CMatchSystem_vtbl *)&CMatchSystem::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10021E60
// Name: _dynamic_atexit_destructor_for__net_allow_multicast__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_allow_multicast__()
{
  ConVar::~ConVar(this: &net_allow_multicast);
}

//------------------------------------------------------------------------------
// Address: 0x10021E70
// Name: _dynamic_atexit_destructor_for__net_allow_syslink__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__net_allow_syslink__()
{
  ConVar::~ConVar(this: &net_allow_syslink);
}

//------------------------------------------------------------------------------
// Address: 0x10021E80
// Name: _dynamic_atexit_destructor_for__g_ConnectionlessLanMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ConnectionlessLanMgr__()
{
  g_ConnectionlessLanMgr.__vftable = (CConnectionlessLanMgr_vtbl *)&CConnectionlessLanMgr::`vftable';
  if ( g_ConnectionlessLanMgr.m_buffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_ConnectionlessLanMgr.m_buffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_ConnectionlessLanMgr.m_buffer.m_Memory.m_pMemory);
      g_ConnectionlessLanMgr.m_buffer.m_Memory.m_pMemory = nullptr;
    }
    g_ConnectionlessLanMgr.m_buffer.m_Memory.m_nAllocationCount = 0;
  }
  g_ConnectionlessLanMgr.__vftable = (CConnectionlessLanMgr_vtbl *)&IConnectionlessPacketHandler::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10021F10
// Name: _dynamic_atexit_destructor_for__g_MatchVoice__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MatchVoice__()
{
  g_MatchVoice.__vftable = (CMatchVoice_vtbl *)&CMatchVoice::`vftable';
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_MatchVoice.m_arrMutedTalkers);
}

//------------------------------------------------------------------------------
// Address: 0x10021F30
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x10021F40
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10021F90
// Name: _dynamic_atexit_destructor_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupSymbolTable__()
{
  CUtlSymbolTableMT *v0; // esi

  v0 = CUtlSymbol::s_pSymbolTable;
  if ( CUtlSymbol::s_pSymbolTable != nullptr )
  {
    CUtlSymbolTable::RemoveAll(this: CUtlSymbol::s_pSymbolTable);
    CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: &v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}

// ============================================================
// Overlay from matchmaking (Missing functions)
// ============================================================
namespace matchmaking {

//------------------------------------------------------------------------------
// Address: 0x100289F0
// Name: public: virtual bool CMatchVoice::IsMachineMuted(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatchVoice::IsMachineMuted(CMatchVoice *this, unsigned __int64 xuidPlayer)
{
  return ((bool (__thiscall *)(CMatchVoice *, _DWORD, _DWORD))this->IsTalkerMuted)(
           a1: this,
           a2: xuidPlayer,
           a3: HIDWORD(xuidPlayer));
}

//------------------------------------------------------------------------------
// Address: 0x10028A10
// Name: public: virtual bool CMatchVoice::IsVoiceRecording(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatchVoice::IsVoiceRecording(CMatchVoice *this)
{
  EVoiceResult v1; // eax

  v1 = steamapicontext->m_pSteamUser->GetAvailableVoice(this: steamapicontext->m_pSteamUser, a2: nullptr, a3: nullptr);
  return v1 == k_EVoiceResultOK || v1 == k_EVoiceResultNoData;
}

//------------------------------------------------------------------------------
// Address: 0x10028A40
// Name: public: virtual void CMatchVoice::SetVoiceRecording(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchVoice::SetVoiceRecording(CMatchVoice *this, bool bRecordingEnabled)
{
  if ( bRecordingEnabled )
    steamapicontext->m_pSteamUser->StartVoiceRecording(this: steamapicontext->m_pSteamUser);
  else
    steamapicontext->m_pSteamUser->StopVoiceRecording(this: steamapicontext->m_pSteamUser);
}

//------------------------------------------------------------------------------
// Address: 0x10028A70
// Name: voice_reset_mutelist
// Source: json
//------------------------------------------------------------------------------
void __cdecl voice_reset_mutelist()
{
  ((void (__thiscall *)(CMatchVoice *, _DWORD, _DWORD, _DWORD))g_pMatchVoice->MuteTalker)(
    a1: g_pMatchVoice,
    a2: 0,
    a3: 0,
    a4: 0);
  _Msg(a1: "Mute list cleared.\n");
}

//------------------------------------------------------------------------------
// Address: 0x10028A90
// Name: voice_mute
// Source: json
//------------------------------------------------------------------------------
void __cdecl voice_mute(const CCommand *args)
{
  int v1; // eax
  player_info_s pi; // [esp+4h] [ebp-90h] BYREF

  if ( args->m_nArgc == 2 )
  {
    v1 = V_atoi(str: args->m_ppArgv[1]);
    if ( g_pMatchExtensions->m_exts.m_pIVEngineClient->GetPlayerInfo(
           this: g_pMatchExtensions->m_exts.m_pIVEngineClient,
           a2: v1,
           a3: &pi)
      && pi.xuid != 0 )
    {
      ((void (__thiscall *)(CMatchVoice *, _DWORD, _DWORD, int))g_pMatchVoice->MuteTalker)(
        a1: g_pMatchVoice,
        a2: pi.xuid,
        a3: HIDWORD(pi.xuid),
        a4: 1);
      _Msg(a1: "%s is now muted.\n", pi.name);
      return;
    }
    _Msg(a1: "Player# is invalid or refers to a bot, please use \"voice_show_mute\" command.\n");
  }
  _Msg(
    a1: "Example usage: voice_mute player#   -   where player# is a number that you can find with \"voice_show_mute\" command.\n");
}

//------------------------------------------------------------------------------
// Address: 0x10028B30
// Name: voice_unmute
// Source: json
//------------------------------------------------------------------------------
void __cdecl voice_unmute(const CCommand *args)
{
  IPlayerLocal *v1; // eax
  __int64 v2; // rax
  IVEngineClient *m_pIVEngineClient; // ecx
  int v4; // edi
  int i; // esi
  const char *v6; // esi
  int v7; // eax
  __int64 v8; // [esp+8h] [ebp-128h] BYREF
  player_info_s pi; // [esp+98h] [ebp-98h] BYREF
  unsigned __int64 xuidLocal; // [esp+128h] [ebp-8h]

  if ( args->m_nArgc != 2 )
  {
usage_0:
    _Msg(
      a1: "Example usage: voice_unmute {player#|all}   -   where player# is a number that you can find with \"voice_show_mute"
      "\" command, or all to unmute all connected players.\n");
    return;
  }
  if ( _V_stricmp(s1: "all", s2: args->m_ppArgv[1]) != 0 )
  {
    if ( args->m_nArgc > 1 )
      v6 = args->m_ppArgv[1];
    else
      v6 = defaultValue;
    v7 = V_atoi(str: v6);
    if ( g_pMatchExtensions->m_exts.m_pIVEngineClient->GetPlayerInfo(
           this: g_pMatchExtensions->m_exts.m_pIVEngineClient,
           a2: v7,
           a3: &pi)
      && pi.xuid != 0 )
    {
      ((void (__thiscall *)(CMatchVoice *, _DWORD, _DWORD, _DWORD))g_pMatchVoice->MuteTalker)(
        a1: g_pMatchVoice,
        a2: pi.xuid,
        a3: HIDWORD(pi.xuid),
        a4: 0);
      _Msg(a1: "%s is now unmuted.\n", pi.name);
      return;
    }
    _Msg(a1: "Player# is invalid or refers to a bot, please use \"voice_show_mute\" command.\n");
    goto usage_0;
  }
  v1 = g_pPlayerManager->GetLocalPlayer(this: g_pPlayerManager, a2: 0);
  v2 = v1->GetXUID(this: v1);
  m_pIVEngineClient = g_pMatchExtensions->m_exts.m_pIVEngineClient;
  HIDWORD(xuidLocal) = HIDWORD(v2);
  HIDWORD(v2) = (IVEngineClient)m_pIVEngineClient->__vftable;
  LODWORD(xuidLocal) = v2;
  v4 = (*(int (__thiscall **)(IVEngineClient *))(HIDWORD(v2) + 80))(a1: m_pIVEngineClient);
  for ( i = 1; i <= v4; ++i )
  {
    if ( g_pMatchExtensions->m_exts.m_pIVEngineClient->GetPlayerInfo(
           this: g_pMatchExtensions->m_exts.m_pIVEngineClient,
           a2: i,
           a3: (player_info_s *)&v8)
      && v8 != 0
      && v8 != xuidLocal )
    {
      ((void (__thiscall *)(CMatchVoice *, _DWORD, _DWORD, _DWORD))g_pMatchVoice->MuteTalker)(
        a1: g_pMatchVoice,
        a2: v8,
        a3: HIDWORD(v8),
        a4: 0);
    }
  }
  _Msg(a1: "All connected players have been unmuted.\n");
}

//------------------------------------------------------------------------------
// Address: 0x10028CA0
// Name: voice_show_mute
// Source: json
//------------------------------------------------------------------------------
void __cdecl voice_show_mute()
{
  IPlayerLocal *(__thiscall *GetLocalPlayer)(struct PlayerManager *, int); // edx
  __int64 (__thiscall ***v1)(_DWORD); // eax
  __int64 v2; // rax
  IVEngineClient *m_pIVEngineClient; // ecx
  int v4; // ebx
  int v5; // edi
  unsigned __int64 xuid; // kr00_8
  bool v7; // zf
  const char *v8; // eax
  player_info_s pi; // [esp+Ch] [ebp-A0h] BYREF
  unsigned __int64 xuidLocal; // [esp+9Ch] [ebp-10h]
  int maxClients; // [esp+A4h] [ebp-8h]
  bool bPrinted; // [esp+ABh] [ebp-1h]

  GetLocalPlayer = g_pPlayerManager->GetLocalPlayer;
  bPrinted = false;
  v1 = (__int64 (__thiscall ***)(_DWORD))GetLocalPlayer(this: g_pPlayerManager, a2: 0);
  v2 = (**v1)(a1: v1);
  m_pIVEngineClient = g_pMatchExtensions->m_exts.m_pIVEngineClient;
  HIDWORD(xuidLocal) = HIDWORD(v2);
  HIDWORD(v2) = (IVEngineClient)m_pIVEngineClient->__vftable;
  LODWORD(xuidLocal) = v2;
  v4 = (*(int (__thiscall **)(IVEngineClient *))(HIDWORD(v2) + 80))(a1: m_pIVEngineClient);
  v5 = 1;
  maxClients = v4;
  if ( v4 < 1 )
    goto LABEL_13;
  do
  {
    if ( g_pMatchExtensions->m_exts.m_pIVEngineClient->GetPlayerInfo(
           this: g_pMatchExtensions->m_exts.m_pIVEngineClient,
           a2: v5,
           a3: &pi) )
    {
      xuid = pi.xuid;
      if ( pi.xuid != 0 && pi.xuid != xuidLocal )
      {
        if ( !bPrinted )
        {
          bPrinted = true;
          _Msg(a1: "Player#     Player Name\n");
          _Msg(a1: "-------     ----------------\n");
          xuid = pi.xuid;
        }
        v7 = ((unsigned __int8 (__thiscall *)(CMatchVoice *, _DWORD, _DWORD))g_pMatchVoice->IsTalkerMuted)(
               a1: g_pMatchVoice,
               a2: xuid,
               a3: HIDWORD(xuid)) == 0;
        v8 = "(muted)";
        if ( v7 )
          v8 = "       ";
        _Msg(a1: " % 2d %s %s\n", v5, v8, pi.name);
        v4 = maxClients;
      }
    }
    ++v5;
  }
  while ( v5 <= v4 );
  if ( bPrinted )
    _Msg(a1: "-------     ----------------\n");
  else
LABEL_13:
    _Msg(a1: "No players currently connected who can be muted.\n");
}

//------------------------------------------------------------------------------
// Address: 0x10028DC0
// Name: class KeyValues __near * SessionMembersFindPlayer(class KeyValues __near *,unsigned __int64,class KeyValues __near * __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__cdecl SessionMembersFindPlayer(
        KeyValues *pSessionSettings,
        unsigned __int64 xuidPlayer,
        KeyValues **ppMachine)
{
  KeyValues *result; // eax
  KeyValues *v4; // edi
  int v5; // esi
  CFmtStrN<256> *v6; // eax
  KeyValues *Key; // eax
  KeyValues *v8; // ebx
  int v9; // edi
  CFmtStrN<256> *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  CFmtStrN<256> v13; // [esp+0h] [ebp-224h] BYREF
  CFmtStrN<256> v14; // [esp+10Ch] [ebp-118h] BYREF
  int numPlayers; // [esp+218h] [ebp-Ch]
  KeyValues *pMembers; // [esp+21Ch] [ebp-8h]
  int numMachines; // [esp+220h] [ebp-4h]
  int k; // [esp+22Ch] [ebp+8h]

  if ( ppMachine != nullptr )
    *ppMachine = nullptr;
  if ( pSessionSettings == nullptr )
    return nullptr;
  result = KeyValues::FindKey(this: pSessionSettings, keyName: "Members", bCreate: false);
  v4 = result;
  pMembers = result;
  if ( result != nullptr )
  {
    v5 = 0;
    numMachines = KeyValues::GetInt(this: result, keyName: "numMachines", defaultValue: 0);
    k = 0;
    if ( numMachines > 0 )
    {
      while ( 1 )
      {
        v6 = CFmtStrN<256>::CFmtStrN<256>(this: &v14, pszFormat: "machine%d", v5);
        Key = KeyValues::FindKey(this: v4, keyName: v6->m_szBuf, bCreate: false);
        v8 = Key;
        if ( Key != nullptr )
        {
          v9 = 0;
          numPlayers = KeyValues::GetInt(this: Key, keyName: "numPlayers", defaultValue: 0);
          if ( numPlayers > 0 )
            break;
        }
LABEL_15:
        k = ++v5;
        if ( v5 >= numMachines )
          return nullptr;
        v4 = pMembers;
      }
      while ( 1 )
      {
        v10 = CFmtStrN<256>::CFmtStrN<256>(this: &v13, pszFormat: "player%d", v9);
        v11 = KeyValues::FindKey(this: v8, keyName: v10->m_szBuf, bCreate: false);
        v12 = v11;
        if ( v11 != nullptr && KeyValues::GetUint64(this: v11, keyName: "xuid", defaultValue: 0) == xuidPlayer )
          break;
        if ( ++v9 >= numPlayers )
        {
          v5 = k;
          goto LABEL_15;
        }
      }
      if ( ppMachine != nullptr )
        *ppMachine = v8;
      return v12;
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10028EF0
// Name: protected: bool CMatchVoice::IsMachineMutingLocalTalkers(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMatchVoice::IsMachineMutingLocalTalkers(CMatchVoice *this, unsigned __int64 xuidPlayer)
{
  IMatchSession *v2; // eax
  KeyValues *v4; // esi
  KeyValues *v5; // edi
  IPlayerLocal *v6; // eax
  unsigned __int64 v7; // rax
  KeyValues *v8; // ebx
  KeyValues *Key; // eax
  KeyValues *FirstValue; // esi
  unsigned __int64 Uint64; // kr00_8
  int v12; // esi
  CFmtStrN<256> *v13; // eax
  unsigned __int64 v14; // rax
  CFmtStrN<256> v15; // [esp+4h] [ebp-118h] BYREF
  unsigned __int64 xuidMuted; // [esp+110h] [ebp-Ch]
  KeyValues *pMachine; // [esp+118h] [ebp-4h] BYREF

  v2 = g_pMatchFramework->GetMatchSession(this: g_pMatchFramework);
  if ( v2 == nullptr )
    return 0;
  v4 = v2->GetSessionSettings(this: v2);
  pMachine = nullptr;
  SessionMembersFindPlayer(pSessionSettings: v4, xuidPlayer, ppMachine: &pMachine);
  v5 = pMachine;
  if ( pMachine != nullptr )
  {
    v6 = g_pPlayerManager->GetLocalPlayer(this: g_pPlayerManager, a2: 0);
    v7 = v6->GetXUID(this: v6);
    HIDWORD(xuidPlayer) = 0;
    SessionMembersFindPlayer(pSessionSettings: v4, xuidPlayer: v7, ppMachine: (KeyValues **)&xuidPlayer + 1);
    v8 = (KeyValues *)HIDWORD(xuidPlayer);
    if ( HIDWORD(xuidPlayer) != 0 && (KeyValues *)HIDWORD(xuidPlayer) != v5 )
    {
      pMachine = (KeyValues *)KeyValues::GetInt(
                                this: (KeyValues *)HIDWORD(xuidPlayer),
                                keyName: "numPlayers",
                                defaultValue: 0);
      Key = KeyValues::FindKey(this: v5, keyName: "Mutelist", bCreate: false);
      if ( Key != nullptr )
      {
        FirstValue = KeyValues::GetFirstValue(this: Key);
        HIDWORD(xuidPlayer) = FirstValue;
        if ( FirstValue != nullptr )
        {
          while ( 1 )
          {
            Uint64 = KeyValues::GetUint64(this: FirstValue, keyName: nullptr, defaultValue: 0);
            HIDWORD(xuidMuted) = HIDWORD(Uint64);
            if ( Uint64 != 0 )
            {
              v12 = 0;
              if ( (int)pMachine > 0 )
                break;
LABEL_15:
              FirstValue = (KeyValues *)HIDWORD(xuidPlayer);
            }
            HIDWORD(xuidPlayer) = KeyValues::GetNextValue(this: FirstValue);
            if ( HIDWORD(xuidPlayer) == 0 )
              return 0;
            FirstValue = (KeyValues *)HIDWORD(xuidPlayer);
          }
          while ( 1 )
          {
            v13 = CFmtStrN<256>::CFmtStrN<256>(this: &v15, pszFormat: "player%d/xuid", v12);
            v14 = KeyValues::GetUint64(this: v8, keyName: v13->m_szBuf, defaultValue: 0);
            if ( __PAIR64__(HIDWORD(xuidMuted), Uint64) == v14 )
              return 1;
            if ( ++v12 >= (int)pMachine )
              goto LABEL_15;
          }
        }
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10029030
// Name: public: virtual bool CMatchVoice::CanPlaybackTalker(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatchVoice::CanPlaybackTalker(CMatchVoice *this, unsigned __int64 xuidTalker)
{
  return CMatchVoice::IsMachineMutingLocalTalkers(this, xuidPlayer: xuidTalker) == 0
      && ((unsigned __int8 (__thiscall *)(CMatchVoice *, _DWORD, _DWORD))this->IsMachineMuted)(
           a1: this,
           a2: xuidTalker,
           a3: HIDWORD(xuidTalker)) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10029070
// Name: public: virtual bool CMatchVoice::IsTalkerMuted(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatchVoice::IsTalkerMuted(CMatchVoice *this, unsigned __int64 xuidTalker)
{
  unsigned int v2; // edi
  int v4; // eax
  int v5; // eax
  int m_Size; // edx
  int v8; // eax
  unsigned __int64 *m_pMemory; // ecx
  int v10; // eax
  int v11; // eax

  v2 = xuidTalker;
  v4 = ((int (__thiscall *)(ISteamFriends *, _DWORD, _DWORD))steamapicontext->m_pSteamFriends->GetFriendRelationship)(
         a1: steamapicontext->m_pSteamFriends,
         a2: xuidTalker,
         a3: HIDWORD(xuidTalker))
     - 1;
  if ( v4 == 0 )
    return true;
  v5 = v4 - 511;
  if ( v5 == 0 || v5 == 512 )
    return true;
  m_Size = this->m_arrMutedTalkers.m_Size;
  v8 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_arrMutedTalkers.m_Memory.m_pMemory;
    while ( *m_pMemory != __PAIR64__(HIDWORD(xuidTalker), v2) )
    {
      ++v8;
      ++m_pMemory;
      if ( v8 >= m_Size )
        goto LABEL_11;
    }
    if ( v8 != -1 )
      return true;
  }
LABEL_11:
  v10 = ((int (__thiscall *)(ISteamFriends *, unsigned int, _DWORD))steamapicontext->m_pSteamFriends->GetFriendRelationship)(
          a1: steamapicontext->m_pSteamFriends,
          a2: v2,
          a3: HIDWORD(xuidTalker))
      - 1;
  if ( v10 == 0 )
    return true;
  v11 = v10 - 511;
  if ( v11 == 0 || v11 == 512 )
    return true;
  return CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int>>::Find(
           this: &this->m_arrMutedTalkers,
           src: &xuidTalker) != -1;
}

//------------------------------------------------------------------------------
// Address: 0x100291B0
// Name: public: virtual void CMatchVoice::MuteTalker(unsigned __int64,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchVoice::MuteTalker(CMatchVoice *this, unsigned __int64 xuidTalker, bool bMute)
{
  CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *p_m_arrMutedTalkers; // esi
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IMatchEventsSubscription *v6; // eax

  if ( xuidTalker != 0 )
  {
    p_m_arrMutedTalkers = &this->m_arrMutedTalkers;
    CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int>>::FindAndFastRemove(
      this: &this->m_arrMutedTalkers,
      src: &xuidTalker);
    if ( bMute )
      CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int>>::InsertBefore(
        this: p_m_arrMutedTalkers,
        elem: p_m_arrMutedTalkers->m_Size,
        src: &xuidTalker);
  }
  else if ( !bMute )
  {
    CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int>>::Purge(this: &this->m_arrMutedTalkers);
  }
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "OnSysMuteListChanged");
  else
    v5 = nullptr;
  v6 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
  v6->BroadcastEvent(this: v6, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10054700
// Name: _dynamic_initializer_for__voice_reset_mutelist_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_reset_mutelist_command__()
{
  ConCommand::ConCommand(
    this: &voice_reset_mutelist_command,
    pName: "voice_reset_mutelist",
    callback: voice_reset_mutelist,
    pHelpString: "Reset all mute information for all players who were ever muted.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__voice_reset_mutelist_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10054730
// Name: _dynamic_initializer_for__voice_mute_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_mute_command__()
{
  ConCommand::ConCommand(
    this: &voice_mute_command,
    pName: "voice_mute",
    callback: (void (__cdecl *)())voice_mute,
    pHelpString: "Mute a specific Steam user",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__voice_mute_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10054760
// Name: _dynamic_initializer_for__voice_unmute_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_unmute_command__()
{
  ConCommand::ConCommand(
    this: &voice_unmute_command,
    pName: "voice_unmute",
    callback: (void (__cdecl *)())voice_unmute,
    pHelpString: "Unmute a specific Steam user, or `all` to unmute all connected players.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__voice_unmute_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10054790
// Name: _dynamic_initializer_for__voice_show_mute_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_show_mute_command__()
{
  ConCommand::ConCommand(
    this: &voice_show_mute_command,
    pName: "voice_show_mute",
    callback: voice_show_mute,
    pHelpString: "Show whether current players are muted.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__voice_show_mute_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10055310
// Name: _dynamic_atexit_destructor_for__voice_reset_mutelist_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_reset_mutelist_command__()
{
  ConCommand::~ConCommand(this: &voice_reset_mutelist_command);
}

//------------------------------------------------------------------------------
// Address: 0x10055320
// Name: _dynamic_atexit_destructor_for__voice_mute_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_mute_command__()
{
  ConCommand::~ConCommand(this: &voice_mute_command);
}

//------------------------------------------------------------------------------
// Address: 0x10055330
// Name: _dynamic_atexit_destructor_for__voice_unmute_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_unmute_command__()
{
  ConCommand::~ConCommand(this: &voice_unmute_command);
}

//------------------------------------------------------------------------------
// Address: 0x10055340
// Name: _dynamic_atexit_destructor_for__voice_show_mute_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_show_mute_command__()
{
  ConCommand::~ConCommand(this: &voice_show_mute_command);
}

//------------------------------------------------------------------------------
// Address: 0x100547C0
// Name: _dynamic_initializer_for__mm_match_search_update_interval__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_match_search_update_interval__()
{
  ConVar::ConVar(
    this: &mm_match_search_update_interval,
    pName: "mm_match_search_update_interval",
    pDefaultValue: "10",
    flags: 2,
    pHelpString: "Interval between matchsearcher updates.");
  return atexit(func: dynamic_atexit_destructor_for__mm_match_search_update_interval__);
}

//------------------------------------------------------------------------------
// Address: 0x100547F0
// Name: _dynamic_initializer_for__mm_session_sys_delay_create__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_session_sys_delay_create__()
{
  ConVar::ConVar(this: &mm_session_sys_delay_create, pName: "mm_session_sys_delay_create", pDefaultValue: "0", flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__mm_session_sys_delay_create__);
}

//------------------------------------------------------------------------------
// Address: 0x10054820
// Name: _dynamic_initializer_for__mm_session_sys_delay_create_host__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_session_sys_delay_create_host__()
{
  ConVar::ConVar(
    this: &mm_session_sys_delay_create_host,
    pName: "mm_session_sys_delay_create_host",
    pDefaultValue: "1.2",
    flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__mm_session_sys_delay_create_host__);
}

//------------------------------------------------------------------------------
// Address: 0x10054850
// Name: _dynamic_initializer_for__mm_session_sys_timeout__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_session_sys_timeout__()
{
  ConVar::ConVar(this: &mm_session_sys_timeout, pName: "mm_session_sys_timeout", pDefaultValue: "3", flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__mm_session_sys_timeout__);
}

//------------------------------------------------------------------------------
// Address: 0x10054880
// Name: _dynamic_initializer_for__mm_session_sys_connect_timeout__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_session_sys_connect_timeout__()
{
  ConVar::ConVar(
    this: &mm_session_sys_connect_timeout,
    pName: "mm_session_sys_connect_timeout",
    pDefaultValue: "8",
    flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__mm_session_sys_connect_timeout__);
}

//------------------------------------------------------------------------------
// Address: 0x100548B0
// Name: _dynamic_initializer_for__mm_session_voice_loading__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_session_voice_loading__()
{
  ConVar::ConVar(this: &mm_session_voice_loading, pName: "mm_session_voice_loading", pDefaultValue: "0", flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__mm_session_voice_loading__);
}

//------------------------------------------------------------------------------
// Address: 0x100548E0
// Name: _dynamic_initializer_for__cl_session__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_session__()
{
  ConVar::ConVar(this: &cl_session, pName: "cl_session", pDefaultValue: defaultValue, flags: 268435986);
  return atexit(func: dynamic_atexit_destructor_for__cl_session__);
}

//------------------------------------------------------------------------------
// Address: 0x10054910
// Name: _dynamic_initializer_for__mm_tu_string__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_tu_string__()
{
  ConVar::ConVar(this: &mm_tu_string, pName: "mm_tu_string", pDefaultValue: "00000000", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mm_tu_string__);
}

//------------------------------------------------------------------------------
// Address: 0x10054940
// Name: _dynamic_initializer_for__mm_debugprint_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_debugprint_command__()
{
  ConCommand::ConCommand(
    this: &mm_debugprint_command,
    pName: "mm_debugprint",
    callback: (void (__cdecl *)())mm_debugprint,
    pHelpString: "Show debug information about current matchmaking session",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__mm_debugprint_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10054970
// Name: _dynamic_initializer_for__mm_teamsearch_errortime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_teamsearch_errortime__()
{
  ConVar::ConVar(
    this: &mm_teamsearch_errortime,
    pName: "mm_teamsearch_errortime",
    pDefaultValue: "3.0",
    flags: 2,
    pHelpString: "Time team search is in error state until it self-cancels");
  return atexit(func: dynamic_atexit_destructor_for__mm_teamsearch_errortime__);
}

//------------------------------------------------------------------------------
// Address: 0x100549A0
// Name: _dynamic_initializer_for__mm_teamsearch_nostart__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_teamsearch_nostart__()
{
  ConVar::ConVar(
    this: &mm_teamsearch_nostart,
    pName: "mm_teamsearch_nostart",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "Team search will fake cancel before searching for server");
  return atexit(func: dynamic_atexit_destructor_for__mm_teamsearch_nostart__);
}

//------------------------------------------------------------------------------
// Address: 0x100549D0
// Name: _dynamic_initializer_for__sv_search_team_key__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_search_team_key__()
{
  ConVar::ConVar(
    this: &sv_search_team_key,
    pName: "sv_search_team_key",
    pDefaultValue: "public",
    flags: 0x80000,
    pHelpString: "When initiating team search, set this key to match with known opponents team");
  return atexit(func: dynamic_atexit_destructor_for__sv_search_team_key__);
}

//------------------------------------------------------------------------------
// Address: 0x10054A00
// Name: _dynamic_initializer_for__mm_dedicated_allow__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_dedicated_allow__()
{
  ConVar::ConVar(
    this: &mm_dedicated_allow,
    pName: "mm_dedicated_allow",
    pDefaultValue: "1",
    flags: 2,
    pHelpString: "1 = allow searches for dedicated servers");
  return atexit(func: dynamic_atexit_destructor_for__mm_dedicated_allow__);
}

//------------------------------------------------------------------------------
// Address: 0x10054A30
// Name: _dynamic_initializer_for__mm_dedicated_fake__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_dedicated_fake__()
{
  ConVar::ConVar(
    this: &mm_dedicated_fake,
    pName: "mm_dedicated_fake",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "1 = pretend like search is going, but abort after some time");
  return atexit(func: dynamic_atexit_destructor_for__mm_dedicated_fake__);
}

//------------------------------------------------------------------------------
// Address: 0x10054A60
// Name: _dynamic_initializer_for__mm_dedicated_force_servers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_dedicated_force_servers__()
{
  ConVar::ConVar(
    this: &mm_dedicated_force_servers,
    pName: "mm_dedicated_force_servers",
    pDefaultValue: defaultValue,
    flags: 0x80000,
    pHelpString: "Comma delimited list of ip:port of servers used to search for dedicated servers instead of searching for public serv"
    "ers.\n"
    "Use syntax `publicip1:port|privateip1:port,publicip2:port|privateip2:port` if your server is behind NAT.\n"
    "If the server is behind NAT, you can specify `0.0.0.0|privateip:port` and if server port is in the list of `mm_serve"
    "r_search_lan_ports` its public address should be automatically detected.");
  return atexit(func: dynamic_atexit_destructor_for__mm_dedicated_force_servers__);
}

//------------------------------------------------------------------------------
// Address: 0x10054A90
// Name: _dynamic_initializer_for__mm_dedicated_ip__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_dedicated_ip__()
{
  ConVar::ConVar(
    this: &mm_dedicated_ip,
    pName: "mm_dedicated_ip",
    pDefaultValue: defaultValue,
    flags: 2,
    pHelpString: "IP address of dedicated servers to consider available");
  return atexit(func: dynamic_atexit_destructor_for__mm_dedicated_ip__);
}

//------------------------------------------------------------------------------
// Address: 0x10054AC0
// Name: _dynamic_initializer_for__mm_dedicated_timeout_request__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_dedicated_timeout_request__()
{
  ConVar::ConVar(
    this: &mm_dedicated_timeout_request,
    pName: "mm_dedicated_timeout_request",
    pDefaultValue: "20",
    flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__mm_dedicated_timeout_request__);
}

//------------------------------------------------------------------------------
// Address: 0x10054AF0
// Name: _dynamic_initializer_for__mm_dedicated_search_maxping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_dedicated_search_maxping__()
{
  ConVar::ConVar(
    this: &mm_dedicated_search_maxping,
    pName: "mm_dedicated_search_maxping",
    pDefaultValue: "150",
    flags: 0x80000,
    pHelpString: "Longest preferred ping to dedicated servers for games",
    bMin: true,
    fMin: 50.0,
    bMax: true,
    fMax: 350.0);
  return atexit(func: dynamic_atexit_destructor_for__mm_dedicated_search_maxping__);
}

//------------------------------------------------------------------------------
// Address: 0x10054B40
// Name: _dynamic_initializer_for__mm_dedicated_search_maxresults__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_dedicated_search_maxresults__()
{
  ConVar::ConVar(
    this: &mm_dedicated_search_maxresults,
    pName: "mm_dedicated_search_maxresults",
    pDefaultValue: "75",
    flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__mm_dedicated_search_maxresults__);
}

//------------------------------------------------------------------------------
// Address: 0x10054B70
// Name: _dynamic_initializer_for__mm_session_search_num_results__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_session_search_num_results__()
{
  ConVar::ConVar(
    this: &mm_session_search_num_results,
    pName: "mm_session_search_num_results",
    pDefaultValue: "50",
    flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__mm_session_search_num_results__);
}

//------------------------------------------------------------------------------
// Address: 0x10054BA0
// Name: _dynamic_initializer_for__mm_session_search_qos_timeout__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_session_search_qos_timeout__()
{
  ConVar::ConVar(
    this: &mm_session_search_qos_timeout,
    pName: "mm_session_search_qos_timeout",
    pDefaultValue: "8.0",
    flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__mm_session_search_qos_timeout__);
}

//------------------------------------------------------------------------------
// Address: 0x10054BD0
// Name: _dynamic_initializer_for__mm_session_search_ping_limit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mm_session_search_ping_limit__()
{
  ConVar::ConVar(
    this: &mm_session_search_ping_limit,
    pName: "mm_session_search_ping_limit",
    pDefaultValue: "200",
    flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__mm_session_search_ping_limit__);
}

//------------------------------------------------------------------------------
// Address: 0x10055350
// Name: _dynamic_atexit_destructor_for__g_MatchVoice__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MatchVoice__()
{
  g_MatchVoice.__vftable = (CMatchVoice_vtbl *)&CMatchVoice::`vftable';
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_MatchVoice.m_arrMutedTalkers);
}

//------------------------------------------------------------------------------
// Address: 0x10055370
// Name: _dynamic_atexit_destructor_for__mm_match_search_update_interval__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_match_search_update_interval__()
{
  ConVar::~ConVar(this: &mm_match_search_update_interval);
}

//------------------------------------------------------------------------------
// Address: 0x10055380
// Name: _GetSearchManagerPool_::_2_::_dynamic_atexit_destructor_for__s_smp__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl GetSearchManagerPool_::_2_::_dynamic_atexit_destructor_for__s_smp__()
{
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&stru_10083464);
}

//------------------------------------------------------------------------------
// Address: 0x10055390
// Name: _dynamic_atexit_destructor_for__mm_session_sys_delay_create__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_session_sys_delay_create__()
{
  ConVar::~ConVar(this: &mm_session_sys_delay_create);
}

//------------------------------------------------------------------------------
// Address: 0x100553A0
// Name: _dynamic_atexit_destructor_for__mm_session_sys_delay_create_host__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_session_sys_delay_create_host__()
{
  ConVar::~ConVar(this: &mm_session_sys_delay_create_host);
}

//------------------------------------------------------------------------------
// Address: 0x100553B0
// Name: _dynamic_atexit_destructor_for__mm_session_sys_timeout__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_session_sys_timeout__()
{
  ConVar::~ConVar(this: &mm_session_sys_timeout);
}

//------------------------------------------------------------------------------
// Address: 0x100553C0
// Name: _dynamic_atexit_destructor_for__mm_session_sys_connect_timeout__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_session_sys_connect_timeout__()
{
  ConVar::~ConVar(this: &mm_session_sys_connect_timeout);
}

//------------------------------------------------------------------------------
// Address: 0x100553D0
// Name: _dynamic_atexit_destructor_for__mm_session_voice_loading__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_session_voice_loading__()
{
  ConVar::~ConVar(this: &mm_session_voice_loading);
}

//------------------------------------------------------------------------------
// Address: 0x100553E0
// Name: _dynamic_atexit_destructor_for__cl_session__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_session__()
{
  ConVar::~ConVar(this: &cl_session);
}

//------------------------------------------------------------------------------
// Address: 0x100553F0
// Name: _dynamic_atexit_destructor_for__mm_tu_string__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_tu_string__()
{
  ConVar::~ConVar(this: &mm_tu_string);
}

//------------------------------------------------------------------------------
// Address: 0x10055400
// Name: _dynamic_atexit_destructor_for__mm_debugprint_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_debugprint_command__()
{
  ConCommand::~ConCommand(this: &mm_debugprint_command);
}

//------------------------------------------------------------------------------
// Address: 0x10055410
// Name: _dynamic_atexit_destructor_for__mm_teamsearch_errortime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_teamsearch_errortime__()
{
  ConVar::~ConVar(this: &mm_teamsearch_errortime);
}

//------------------------------------------------------------------------------
// Address: 0x10055420
// Name: _dynamic_atexit_destructor_for__mm_teamsearch_nostart__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_teamsearch_nostart__()
{
  ConVar::~ConVar(this: &mm_teamsearch_nostart);
}

//------------------------------------------------------------------------------
// Address: 0x10055430
// Name: _dynamic_atexit_destructor_for__sv_search_team_key__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_search_team_key__()
{
  ConVar::~ConVar(this: &sv_search_team_key);
}

//------------------------------------------------------------------------------
// Address: 0x10055440
// Name: _dynamic_atexit_destructor_for__mm_dedicated_allow__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_dedicated_allow__()
{
  ConVar::~ConVar(this: &mm_dedicated_allow);
}

//------------------------------------------------------------------------------
// Address: 0x10055450
// Name: _dynamic_atexit_destructor_for__mm_dedicated_fake__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_dedicated_fake__()
{
  ConVar::~ConVar(this: &mm_dedicated_fake);
}

//------------------------------------------------------------------------------
// Address: 0x10055460
// Name: _dynamic_atexit_destructor_for__mm_dedicated_force_servers__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_dedicated_force_servers__()
{
  ConVar::~ConVar(this: &mm_dedicated_force_servers);
}

//------------------------------------------------------------------------------
// Address: 0x10055470
// Name: _dynamic_atexit_destructor_for__mm_dedicated_ip__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_dedicated_ip__()
{
  ConVar::~ConVar(this: &mm_dedicated_ip);
}

//------------------------------------------------------------------------------
// Address: 0x10055480
// Name: _dynamic_atexit_destructor_for__mm_dedicated_timeout_request__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_dedicated_timeout_request__()
{
  ConVar::~ConVar(this: &mm_dedicated_timeout_request);
}

//------------------------------------------------------------------------------
// Address: 0x10055490
// Name: _dynamic_atexit_destructor_for__mm_dedicated_search_maxping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_dedicated_search_maxping__()
{
  ConVar::~ConVar(this: &mm_dedicated_search_maxping);
}

//------------------------------------------------------------------------------
// Address: 0x100554A0
// Name: _dynamic_atexit_destructor_for__mm_dedicated_search_maxresults__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_dedicated_search_maxresults__()
{
  ConVar::~ConVar(this: &mm_dedicated_search_maxresults);
}

//------------------------------------------------------------------------------
// Address: 0x100554B0
// Name: _dynamic_atexit_destructor_for__mm_session_search_num_results__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_session_search_num_results__()
{
  ConVar::~ConVar(this: &mm_session_search_num_results);
}

//------------------------------------------------------------------------------
// Address: 0x100554C0
// Name: _dynamic_atexit_destructor_for__mm_session_search_qos_timeout__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_session_search_qos_timeout__()
{
  ConVar::~ConVar(this: &mm_session_search_qos_timeout);
}

//------------------------------------------------------------------------------
// Address: 0x100554D0
// Name: _dynamic_atexit_destructor_for__mm_session_search_ping_limit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mm_session_search_ping_limit__()
{
  ConVar::~ConVar(this: &mm_session_search_ping_limit);
}

} // namespace matchmaking

// ============================================================
// Overlay from matchmaking_ds (Missing functions)
// ============================================================
namespace matchmaking_ds {

//------------------------------------------------------------------------------
// Address: 0x100084C0
// Name: public: virtual bool CMatchVoice::IsMachineMuted(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatchVoice::IsMachineMuted(CMatchVoice *this, unsigned __int64 xuidPlayer)
{
  return ((bool (__thiscall *)(CMatchVoice *, _DWORD, _DWORD))this->IsTalkerMuted)(
           a1: this,
           a2: xuidPlayer,
           a3: HIDWORD(xuidPlayer));
}

//------------------------------------------------------------------------------
// Address: 0x100084F0
// Name: public: virtual void CMatchVoice::MuteTalker(unsigned __int64,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchVoice::MuteTalker(CMatchVoice *this, unsigned __int64 xuidTalker, bool bMute)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10008500
// Name: voice_reset_mutelist
// Source: json
//------------------------------------------------------------------------------
void __cdecl voice_reset_mutelist()
{
  ((void (__thiscall *)(CMatchVoice *, _DWORD, _DWORD, _DWORD))g_pMatchVoice->MuteTalker)(
    a1: g_pMatchVoice,
    a2: 0,
    a3: 0,
    a4: 0);
  _Msg(a1: "Mute list cleared.\n");
}

//------------------------------------------------------------------------------
// Address: 0x10008520
// Name: voice_mute
// Source: json
//------------------------------------------------------------------------------
void __cdecl voice_mute(const CCommand *args)
{
  int v1; // eax
  player_info_s pi; // [esp+4h] [ebp-90h] BYREF

  if ( args->m_nArgc == 2 )
  {
    v1 = V_atoi(str: args->m_ppArgv[1]);
    if ( g_pMatchExtensions->m_exts.m_pIVEngineClient->GetPlayerInfo(
           this: g_pMatchExtensions->m_exts.m_pIVEngineClient,
           a2: v1,
           a3: &pi)
      && pi.xuid != 0 )
    {
      ((void (__thiscall *)(CMatchVoice *, _DWORD, _DWORD, int))g_pMatchVoice->MuteTalker)(
        a1: g_pMatchVoice,
        a2: pi.xuid,
        a3: HIDWORD(pi.xuid),
        a4: 1);
      _Msg(a1: "%s is now muted.\n", pi.name);
      return;
    }
    _Msg(a1: "Player# is invalid or refers to a bot, please use \"voice_show_mute\" command.\n");
  }
  _Msg(
    a1: "Example usage: voice_mute player#   -   where player# is a number that you can find with \"voice_show_mute\" command.\n");
}

//------------------------------------------------------------------------------
// Address: 0x100085C0
// Name: voice_unmute
// Source: json
//------------------------------------------------------------------------------
void __cdecl voice_unmute(const CCommand *args)
{
  IPlayerLocal *v1; // eax
  __int64 v2; // rax
  IVEngineClient *m_pIVEngineClient; // ecx
  int v4; // edi
  int i; // esi
  const char *v6; // esi
  int v7; // eax
  __int64 v8; // [esp+8h] [ebp-128h] BYREF
  player_info_s pi; // [esp+98h] [ebp-98h] BYREF
  unsigned __int64 xuidLocal; // [esp+128h] [ebp-8h]

  if ( args->m_nArgc != 2 )
  {
usage_0:
    _Msg(
      a1: "Example usage: voice_unmute {player#|all}   -   where player# is a number that you can find with \"voice_show_mute"
      "\" command, or all to unmute all connected players.\n");
    return;
  }
  if ( _V_stricmp(s1: "all", s2: args->m_ppArgv[1]) != 0 )
  {
    if ( args->m_nArgc > 1 )
      v6 = args->m_ppArgv[1];
    else
      v6 = str;
    v7 = V_atoi(str: v6);
    if ( g_pMatchExtensions->m_exts.m_pIVEngineClient->GetPlayerInfo(
           this: g_pMatchExtensions->m_exts.m_pIVEngineClient,
           a2: v7,
           a3: &pi)
      && pi.xuid != 0 )
    {
      ((void (__thiscall *)(CMatchVoice *, _DWORD, _DWORD, _DWORD))g_pMatchVoice->MuteTalker)(
        a1: g_pMatchVoice,
        a2: pi.xuid,
        a3: HIDWORD(pi.xuid),
        a4: 0);
      _Msg(a1: "%s is now unmuted.\n", pi.name);
      return;
    }
    _Msg(a1: "Player# is invalid or refers to a bot, please use \"voice_show_mute\" command.\n");
    goto usage_0;
  }
  v1 = g_pPlayerManager->GetLocalPlayer(this: g_pPlayerManager, a2: 0);
  v2 = v1->GetXUID(this: v1);
  m_pIVEngineClient = g_pMatchExtensions->m_exts.m_pIVEngineClient;
  HIDWORD(xuidLocal) = HIDWORD(v2);
  HIDWORD(v2) = (IVEngineClient)m_pIVEngineClient->__vftable;
  LODWORD(xuidLocal) = v2;
  v4 = (*(int (__thiscall **)(IVEngineClient *))(HIDWORD(v2) + 80))(a1: m_pIVEngineClient);
  for ( i = 1; i <= v4; ++i )
  {
    if ( g_pMatchExtensions->m_exts.m_pIVEngineClient->GetPlayerInfo(
           this: g_pMatchExtensions->m_exts.m_pIVEngineClient,
           a2: i,
           a3: (player_info_s *)&v8)
      && v8 != 0
      && v8 != xuidLocal )
    {
      ((void (__thiscall *)(CMatchVoice *, _DWORD, _DWORD, _DWORD))g_pMatchVoice->MuteTalker)(
        a1: g_pMatchVoice,
        a2: v8,
        a3: HIDWORD(v8),
        a4: 0);
    }
  }
  _Msg(a1: "All connected players have been unmuted.\n");
}

//------------------------------------------------------------------------------
// Address: 0x10008730
// Name: voice_show_mute
// Source: json
//------------------------------------------------------------------------------
void __cdecl voice_show_mute()
{
  IPlayerLocal *(__thiscall *GetLocalPlayer)(struct PlayerManager *, int); // edx
  __int64 (__thiscall ***v1)(_DWORD); // eax
  __int64 v2; // rax
  IVEngineClient *m_pIVEngineClient; // ecx
  int v4; // ebx
  int v5; // edi
  unsigned __int64 xuid; // kr00_8
  bool v7; // zf
  const char *v8; // eax
  player_info_s pi; // [esp+Ch] [ebp-A0h] BYREF
  unsigned __int64 xuidLocal; // [esp+9Ch] [ebp-10h]
  int maxClients; // [esp+A4h] [ebp-8h]
  bool bPrinted; // [esp+ABh] [ebp-1h]

  GetLocalPlayer = g_pPlayerManager->GetLocalPlayer;
  bPrinted = false;
  v1 = (__int64 (__thiscall ***)(_DWORD))GetLocalPlayer(this: g_pPlayerManager, a2: 0);
  v2 = (**v1)(a1: v1);
  m_pIVEngineClient = g_pMatchExtensions->m_exts.m_pIVEngineClient;
  HIDWORD(xuidLocal) = HIDWORD(v2);
  HIDWORD(v2) = (IVEngineClient)m_pIVEngineClient->__vftable;
  LODWORD(xuidLocal) = v2;
  v4 = (*(int (__thiscall **)(IVEngineClient *))(HIDWORD(v2) + 80))(a1: m_pIVEngineClient);
  v5 = 1;
  maxClients = v4;
  if ( v4 < 1 )
    goto LABEL_13;
  do
  {
    if ( g_pMatchExtensions->m_exts.m_pIVEngineClient->GetPlayerInfo(
           this: g_pMatchExtensions->m_exts.m_pIVEngineClient,
           a2: v5,
           a3: &pi) )
    {
      xuid = pi.xuid;
      if ( pi.xuid != 0 && pi.xuid != xuidLocal )
      {
        if ( !bPrinted )
        {
          bPrinted = true;
          _Msg(a1: "Player#     Player Name\n");
          _Msg(a1: "-------     ----------------\n");
          xuid = pi.xuid;
        }
        v7 = ((unsigned __int8 (__thiscall *)(CMatchVoice *, _DWORD, _DWORD))g_pMatchVoice->IsTalkerMuted)(
               a1: g_pMatchVoice,
               a2: xuid,
               a3: HIDWORD(xuid)) == 0;
        v8 = "(muted)";
        if ( v7 )
          v8 = "       ";
        _Msg(a1: " % 2d %s %s\n", v5, v8, pi.name);
        v4 = maxClients;
      }
    }
    ++v5;
  }
  while ( v5 <= v4 );
  if ( bPrinted )
    _Msg(a1: "-------     ----------------\n");
  else
LABEL_13:
    _Msg(a1: "No players currently connected who can be muted.\n");
}

//------------------------------------------------------------------------------
// Address: 0x10008850
// Name: class KeyValues __near * SessionMembersFindPlayer(class KeyValues __near *,unsigned __int64,class KeyValues __near * __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__cdecl SessionMembersFindPlayer(
        KeyValues *pSessionSettings,
        unsigned __int64 xuidPlayer,
        KeyValues **ppMachine)
{
  KeyValues *result; // eax
  KeyValues *v4; // edi
  int v5; // esi
  CFmtStrN<256> *v6; // eax
  KeyValues *Key; // eax
  KeyValues *v8; // ebx
  int v9; // edi
  CFmtStrN<256> *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  CFmtStrN<256> v13; // [esp+0h] [ebp-224h] BYREF
  CFmtStrN<256> v14; // [esp+10Ch] [ebp-118h] BYREF
  int numPlayers; // [esp+218h] [ebp-Ch]
  KeyValues *pMembers; // [esp+21Ch] [ebp-8h]
  int numMachines; // [esp+220h] [ebp-4h]
  int k; // [esp+22Ch] [ebp+8h]

  if ( ppMachine != nullptr )
    *ppMachine = nullptr;
  if ( pSessionSettings == nullptr )
    return nullptr;
  result = KeyValues::FindKey(this: pSessionSettings, keyName: "Members", bCreate: false);
  v4 = result;
  pMembers = result;
  if ( result != nullptr )
  {
    v5 = 0;
    numMachines = KeyValues::GetInt(this: result, keyName: "numMachines", defaultValue: 0);
    k = 0;
    if ( numMachines > 0 )
    {
      while ( 1 )
      {
        v6 = CFmtStrN<256>::CFmtStrN<256>(this: &v14, pszFormat: "machine%d", v5);
        Key = KeyValues::FindKey(this: v4, keyName: v6->m_szBuf, bCreate: false);
        v8 = Key;
        if ( Key != nullptr )
        {
          v9 = 0;
          numPlayers = KeyValues::GetInt(this: Key, keyName: "numPlayers", defaultValue: 0);
          if ( numPlayers > 0 )
            break;
        }
LABEL_15:
        k = ++v5;
        if ( v5 >= numMachines )
          return nullptr;
        v4 = pMembers;
      }
      while ( 1 )
      {
        v10 = CFmtStrN<256>::CFmtStrN<256>(this: &v13, pszFormat: "player%d", v9);
        v11 = KeyValues::FindKey(this: v8, keyName: v10->m_szBuf, bCreate: false);
        v12 = v11;
        if ( v11 != nullptr && KeyValues::GetUint64(this: v11, keyName: "xuid", defaultValue: 0) == xuidPlayer )
          break;
        if ( ++v9 >= numPlayers )
        {
          v5 = k;
          goto LABEL_15;
        }
      }
      if ( ppMachine != nullptr )
        *ppMachine = v8;
      return v12;
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10008980
// Name: protected: bool CMatchVoice::IsMachineMutingLocalTalkers(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMatchVoice::IsMachineMutingLocalTalkers(CMatchVoice *this, unsigned __int64 xuidPlayer)
{
  IMatchSession *v2; // eax
  KeyValues *v4; // esi
  KeyValues *v5; // edi
  IPlayerLocal *v6; // eax
  unsigned __int64 v7; // rax
  KeyValues *v8; // ebx
  KeyValues *Key; // eax
  KeyValues *FirstValue; // esi
  unsigned __int64 Uint64; // kr00_8
  int v12; // esi
  CFmtStrN<256> *v13; // eax
  unsigned __int64 v14; // rax
  CFmtStrN<256> v15; // [esp+4h] [ebp-118h] BYREF
  unsigned __int64 xuidMuted; // [esp+110h] [ebp-Ch]
  KeyValues *pMachine; // [esp+118h] [ebp-4h] BYREF

  v2 = g_pMatchFramework->GetMatchSession(this: g_pMatchFramework);
  if ( v2 == nullptr )
    return 0;
  v4 = v2->GetSessionSettings(this: v2);
  pMachine = nullptr;
  SessionMembersFindPlayer(pSessionSettings: v4, xuidPlayer, ppMachine: &pMachine);
  v5 = pMachine;
  if ( pMachine != nullptr )
  {
    v6 = g_pPlayerManager->GetLocalPlayer(this: g_pPlayerManager, a2: 0);
    v7 = v6->GetXUID(this: v6);
    HIDWORD(xuidPlayer) = 0;
    SessionMembersFindPlayer(pSessionSettings: v4, xuidPlayer: v7, ppMachine: (KeyValues **)&xuidPlayer + 1);
    v8 = (KeyValues *)HIDWORD(xuidPlayer);
    if ( HIDWORD(xuidPlayer) != 0 && (KeyValues *)HIDWORD(xuidPlayer) != v5 )
    {
      pMachine = (KeyValues *)KeyValues::GetInt(
                                this: (KeyValues *)HIDWORD(xuidPlayer),
                                keyName: "numPlayers",
                                defaultValue: 0);
      Key = KeyValues::FindKey(this: v5, keyName: "Mutelist", bCreate: false);
      if ( Key != nullptr )
      {
        FirstValue = KeyValues::GetFirstValue(this: Key);
        HIDWORD(xuidPlayer) = FirstValue;
        if ( FirstValue != nullptr )
        {
          while ( 1 )
          {
            Uint64 = KeyValues::GetUint64(this: FirstValue, keyName: nullptr, defaultValue: 0);
            HIDWORD(xuidMuted) = HIDWORD(Uint64);
            if ( Uint64 != 0 )
            {
              v12 = 0;
              if ( (int)pMachine > 0 )
                break;
LABEL_15:
              FirstValue = (KeyValues *)HIDWORD(xuidPlayer);
            }
            HIDWORD(xuidPlayer) = KeyValues::GetNextValue(this: FirstValue);
            if ( HIDWORD(xuidPlayer) == 0 )
              return 0;
            FirstValue = (KeyValues *)HIDWORD(xuidPlayer);
          }
          while ( 1 )
          {
            v13 = CFmtStrN<256>::CFmtStrN<256>(this: &v15, pszFormat: "player%d/xuid", v12);
            v14 = KeyValues::GetUint64(this: v8, keyName: v13->m_szBuf, defaultValue: 0);
            if ( __PAIR64__(HIDWORD(xuidMuted), Uint64) == v14 )
              return 1;
            if ( ++v12 >= (int)pMachine )
              goto LABEL_15;
          }
        }
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10008AC0
// Name: public: virtual bool CMatchVoice::CanPlaybackTalker(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatchVoice::CanPlaybackTalker(CMatchVoice *this, unsigned __int64 xuidTalker)
{
  return CMatchVoice::IsMachineMutingLocalTalkers(this, xuidPlayer: xuidTalker) == 0
      && ((unsigned __int8 (__thiscall *)(CMatchVoice *, _DWORD, _DWORD))this->IsMachineMuted)(
           a1: this,
           a2: xuidTalker,
           a3: HIDWORD(xuidTalker)) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10008B00
// Name: public: virtual bool CMatchVoice::IsTalkerMuted(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatchVoice::IsTalkerMuted(CMatchVoice *this, unsigned __int64 xuidTalker)
{
  int m_Size; // edx
  int v3; // eax
  unsigned __int64 *i; // ecx

  m_Size = this->m_arrMutedTalkers.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return false;
  for ( i = this->m_arrMutedTalkers.m_Memory.m_pMemory; *i != xuidTalker; ++i )
  {
    if ( ++v3 >= m_Size )
      return false;
  }
  return v3 != -1;
}

//------------------------------------------------------------------------------
// Address: 0x10026D60
// Name: _dynamic_initializer_for__voice_reset_mutelist_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_reset_mutelist_command__()
{
  ConCommand::ConCommand(
    this: &voice_reset_mutelist_command,
    pName: "voice_reset_mutelist",
    callback: (void (__cdecl *)(const CCommand *))voice_reset_mutelist,
    pHelpString: "Reset all mute information for all players who were ever muted.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__voice_reset_mutelist_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10026D90
// Name: _dynamic_initializer_for__voice_mute_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_mute_command__()
{
  ConCommand::ConCommand(
    this: &voice_mute_command,
    pName: "voice_mute",
    callback: voice_mute,
    pHelpString: "Mute a specific Steam user",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__voice_mute_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10026DC0
// Name: _dynamic_initializer_for__voice_unmute_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_unmute_command__()
{
  ConCommand::ConCommand(
    this: &voice_unmute_command,
    pName: "voice_unmute",
    callback: voice_unmute,
    pHelpString: "Unmute a specific Steam user, or `all` to unmute all connected players.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__voice_unmute_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10026DF0
// Name: _dynamic_initializer_for__voice_show_mute_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__voice_show_mute_command__()
{
  ConCommand::ConCommand(
    this: &voice_show_mute_command,
    pName: "voice_show_mute",
    callback: (void (__cdecl *)(const CCommand *))voice_show_mute,
    pHelpString: "Show whether current players are muted.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__voice_show_mute_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10027360
// Name: _dynamic_atexit_destructor_for__voice_reset_mutelist_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_reset_mutelist_command__()
{
  ConCommand::~ConCommand(this: &voice_reset_mutelist_command);
}

//------------------------------------------------------------------------------
// Address: 0x10027370
// Name: _dynamic_atexit_destructor_for__voice_mute_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_mute_command__()
{
  ConCommand::~ConCommand(this: &voice_mute_command);
}

//------------------------------------------------------------------------------
// Address: 0x10027380
// Name: _dynamic_atexit_destructor_for__voice_unmute_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_unmute_command__()
{
  ConCommand::~ConCommand(this: &voice_unmute_command);
}

//------------------------------------------------------------------------------
// Address: 0x10027390
// Name: _dynamic_atexit_destructor_for__voice_show_mute_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__voice_show_mute_command__()
{
  ConCommand::~ConCommand(this: &voice_show_mute_command);
}

//------------------------------------------------------------------------------
// Address: 0x10026E20
// Name: _dynamic_initializer_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::CExpressionEvaluator(this: &g_ExpressionEvaluator);
  return atexit(func: dynamic_atexit_destructor_for__g_ExpressionEvaluator__);
}

//------------------------------------------------------------------------------
// Address: 0x10026E40
// Name: _dynamic_initializer_for__g_KVMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KVMutex__()
{
  g_KVMutex.m_ownerID = 0;
  g_KVMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10026E50
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  CEmptyConVar::CEmptyConVar(this: &s_EmptyConVar);
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x10026E70
// Name: _dynamic_initializer_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupSymbolTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10026E80
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **dynamic_initializer_for__s_StringCharConversion__()
{
  char **result; // eax
  int v1; // edx
  char v2; // cl

  CUtlCharConversion::CUtlCharConversion(
    this: &s_StringCharConversion,
    nEscapeChar: 92,
    pDelimiter: "\"",
    nCount: 11,
    pArray: s_pConversionArrays_StringCharConversion);
  s_StringCharConversion.__vftable = (CUtlCStringConversion_vtbl *)&CUtlCStringConversion::`vftable';
  memset(
    dst: (unsigned __int8 *)s_StringCharConversion.m_pConversion,
    value: 0,
    count: sizeof(s_StringCharConversion.m_pConversion));
  result = &s_pConversionArrays_StringCharConversion[0].m_pReplacementString;
  do
  {
    v1 = **result;
    v2 = *((_BYTE *)result - 4);
    result += 2;
    s_StringCharConversion.m_pConversion[v1] = v2;
  }
  while ( (int)result < (int)&s_pConversionArrays_NoEscConversion[0].m_pReplacementString );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10026EE0
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_NoEscConversion__()
{
  CUtlCharConversion *result; // eax

  result = CUtlCharConversion::CUtlCharConversion(
             this: &s_NoEscConversion,
             nEscapeChar: 127,
             pDelimiter: "\"",
             nCount: 1,
             pArray: s_pConversionArrays_NoEscConversion);
  s_NoEscConversion.__vftable = (CUtlNoEscConversion_vtbl *)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10026F10
// Name: _dynamic_initializer_for__g_BitWriteMasksInit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBitWriteMasksInit *dynamic_initializer_for__g_BitWriteMasksInit__()
{
  return CBitWriteMasksInit::CBitWriteMasksInit(this: &g_BitWriteMasksInit);
}

//------------------------------------------------------------------------------
// Address: 0x10026F20
// Name: _dynamic_atexit_destructor_for__g_MatchTitleGameSettingsMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MatchTitleGameSettingsMgr__()
{
  g_MatchTitleGameSettingsMgr.__vftable = (CMatchTitleGameSettingsMgr_vtbl *)&CMatchTitleGameSettingsMgr::`vftable';
  if ( g_MatchTitleGameSettingsMgr.m_pMatchSystemData != nullptr )
    KeyValues::deleteThis(this: g_MatchTitleGameSettingsMgr.m_pMatchSystemData);
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_MatchTitleGameSettingsMgr.m_SearchPass);
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_MatchTitleGameSettingsMgr.m_FormulaSkill);
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(this: &g_MatchTitleGameSettingsMgr.m_FormulaExperience);
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(this: &g_MatchTitleGameSettingsMgr.m_FormulaAverage);
}

//------------------------------------------------------------------------------
// Address: 0x10026F70
// Name: _dynamic_atexit_destructor_for__g_MatchTitle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MatchTitle__()
{
  CMatchTitle::~CMatchTitle(this: &g_MatchTitle);
}

//------------------------------------------------------------------------------
// Address: 0x10026F80
// Name: _dynamic_atexit_destructor_for__cl_titledataversionblock1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_titledataversionblock1__()
{
  ConVar::~ConVar(this: &cl_titledataversionblock1);
}

//------------------------------------------------------------------------------
// Address: 0x10026F90
// Name: _dynamic_atexit_destructor_for__cl_titledataversionblock2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_titledataversionblock2__()
{
  ConVar::~ConVar(this: &cl_titledataversionblock2);
}

//------------------------------------------------------------------------------
// Address: 0x10026FA0
// Name: _dynamic_atexit_destructor_for__cl_titledataversionblock3__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_titledataversionblock3__()
{
  ConVar::~ConVar(this: &cl_titledataversionblock3);
}

//------------------------------------------------------------------------------
// Address: 0x10026FB0
// Name: _PrepareTitleDataStorageDescription_::_2_::_dynamic_atexit_destructor_for__s_tdfd__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl PrepareTitleDataStorageDescription_::_2_::_dynamic_atexit_destructor_for__s_tdfd__()
{
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: &stru_10046E50);
}

//------------------------------------------------------------------------------
// Address: 0x100273A0
// Name: _dynamic_atexit_destructor_for__g_MatchVoice__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MatchVoice__()
{
  g_MatchVoice.__vftable = (CMatchVoice_vtbl *)&CMatchVoice::`vftable';
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_MatchVoice.m_arrMutedTalkers);
}

//------------------------------------------------------------------------------
// Address: 0x100273C0
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x100273D0
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10027420
// Name: _dynamic_atexit_destructor_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupSymbolTable__()
{
  CUtlSymbolTableMT *v0; // esi

  v0 = CUtlSymbol::s_pSymbolTable;
  if ( CUtlSymbol::s_pSymbolTable != nullptr )
  {
    CUtlSymbolTable::RemoveAll(this: CUtlSymbol::s_pSymbolTable);
    CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: &v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}

} // namespace matchmaking_ds
