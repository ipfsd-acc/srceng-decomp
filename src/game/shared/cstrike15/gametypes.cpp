// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/gametypes.cpp
// Functions: 36
// ============================================================

#include "game\shared\cstrike15\gametypes.h"

//------------------------------------------------------------------------------
// Address: 0x101CC180
// Name: public: static unsigned __int64 DLCHelper::GetInstalledDLCMask(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DLCHelper::GetInstalledDLCMask()
{
  int (__thiscall *IsAnyDLCPresent)(IFileSystem *, bool *); // eax
  int v1; // edi
  int v2; // esi
  __int64 v3; // kr00_8
  __int64 uiDlcHeader; // [esp+Ch] [ebp-Ch] BYREF
  bool bSearchPath; // [esp+17h] [ebp-1h] BYREF

  bSearchPath = false;
  IsAnyDLCPresent = g_pFullFileSystem->IsAnyDLCPresent;
  uiDlcHeader = 0;
  v1 = IsAnyDLCPresent(this: g_pFullFileSystem, a2: &bSearchPath);
  if ( !bSearchPath )
    g_pFullFileSystem->AddDLCSearchPaths(this: g_pFullFileSystem);
  v2 = 0;
  if ( v1 <= 0 )
    return uiDlcHeader;
  v3 = uiDlcHeader;
  do
  {
    HIDWORD(uiDlcHeader) = 0;
    if ( g_pFullFileSystem->GetAnyDLCInfo(
           this: g_pFullFileSystem,
           a2: v2,
           a3: (unsigned int *)((char *)&uiDlcHeader + 4),
           a4: nullptr,
           a5: 0)
      && (unsigned int)(HIBYTE(HIDWORD(uiDlcHeader)) - 1) <= 0x1D )
    {
      v3 |= 1LL << SHIBYTE(uiDlcHeader);
    }
    ++v2;
  }
  while ( v2 < v1 );
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101CC230
// Name: public: static void DLCHelper::AppendDLCKeyValues(class KeyValues __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DLCHelper::AppendDLCKeyValues(KeyValues *pKeyValues, char *fileName, const char *startDir)
{
  unsigned __int64 v3; // rax
  KeyValues *v4; // eax
  KeyValues *v5; // ebx
  unsigned int v6; // eax
  int v7; // esi
  bool v8; // zf
  int v9; // edi
  IBaseFileSystem *v10; // eax
  unsigned int v11; // et0
  char dlcFileName[128]; // [esp+0h] [ebp-94h] BYREF
  unsigned __int64 i; // [esp+80h] [ebp-14h]
  const char *extension; // [esp+88h] [ebp-Ch]
  unsigned __int64 installedDlc; // [esp+8Ch] [ebp-8h]

  LODWORD(v3) = DLCHelper::GetInstalledDLCMask();
  installedDlc = v3;
  if ( v3 != 0 )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: prType);
    else
      v5 = nullptr;
    memset(dlcFileName, 0, sizeof(dlcFileName));
    v6 = _V_strlen(str: fileName);
    v7 = v6 - 1;
    v8 = v6 == 1;
    if ( (int)(v6 - 1) > 0 )
    {
      do
      {
        if ( fileName[v7] == 46 )
          break;
        --v7;
      }
      while ( v7 > 0 );
      v8 = v7 == 0;
    }
    if ( v8 )
    {
      _Warning(a1: "Invalid file name passed to DLCHelper::AppendDLCKeyValues (%s)\n", fileName);
    }
    else
    {
      extension = &fileName[v7 + 1];
      V_strncpy(pDest: dlcFileName, pSrc: fileName, maxLen: 128);
      v9 = 1;
      HIDWORD(i) = 0;
      do
      {
        if ( (installedDlc & (1LL << v9)) != 0 )
        {
          V_snprintf(pDest: &dlcFileName[v7], maxLen: 128 - v7, pFormat: "_dlc%d.%s", v9, extension);
          KeyValues::Clear(this: v5);
          if ( g_pFullFileSystem != nullptr )
            v10 = &g_pFullFileSystem->IBaseFileSystem;
          else
            v10 = nullptr;
          if ( KeyValues::LoadFromFile(
                 this: v5,
                 filesystem: v10,
                 resourceName: dlcFileName,
                 pathID: startDir,
                 pfnEvaluateSymbolProc: nullptr) )
          {
            KeyValues::MergeFrom(this: pKeyValues, kvMerge: v5, eOp: MERGE_KV_UPDATE);
          }
          else
          {
            _Warning(a1: "Failed to load %s\n", dlcFileName);
          }
        }
        v11 = (__PAIR64__(HIDWORD(i), v9++) + 1) >> 32;
        HIDWORD(i) = v11;
      }
      while ( __PAIR64__(v11, v9) < 0x40 );
      if ( v5 != nullptr )
        KeyValues::deleteThis(this: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CC3B0
// Name: public: virtual bool GameTypes::SetGameTypeAndMode(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameTypes::SetGameTypeAndMode(GameTypes *this, const char *gameType, const char *gameMode)
{
  int iMode; // [esp+8h] [ebp-8h] BYREF
  int iType; // [esp+Ch] [ebp-4h] BYREF

  iType = -1;
  iMode = -1;
  if ( this->GetGameModeAndTypeIntsFromStrings(this, a2: gameType, a3: gameMode, a4: &iType, a5: &iMode) )
  {
    DevMsg(a1: "GameTypes: setting game type to %s:%d.\n", gameType, iType);
    ConVar::SetValue(this: (ConVar *)&game_type.IConVar, value: iType);
    DevMsg(a1: "GameTypes: setting game mode to %s:%d.\n", gameMode, iMode);
    ConVar::SetValue(this: (ConVar *)&game_mode.IConVar, value: iMode);
    return 1;
  }
  else
  {
    _Warning(
      a1: "GamesTypes: unable to set game type and mode. Could not find type/mode matching type:%s/mode:%s.\n",
      gameType,
      gameMode);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CC440
// Name: public: virtual int GameTypes::GetCurrentGameType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GameTypes::GetCurrentGameType(GameTypes *this)
{
  if ( game_type.m_pParent != nullptr )
    return game_type.m_pParent->m_Value.m_nValue;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101CC450
// Name: public: virtual int GameTypes::GetCurrentGameMode(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GameTypes::GetCurrentGameMode(GameTypes *this)
{
  if ( game_mode.m_pParent != nullptr )
    return game_mode.m_pParent->m_Value.m_nValue;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101CC460
// Name: private: void GameTypes::DisplayConvars(class KeyValues __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GameTypes::DisplayConvars(GameTypes *this, KeyValues *pKV_Convars, const char *title)
{
  KeyValues *i; // esi
  const char *Name; // eax
  char *m_pszString; // edi
  const char *v6; // eax
  char *String; // [esp-Ch] [ebp-18h]
  ConVarRef conVarRef; // [esp+4h] [ebp-8h] BYREF

  if ( pKV_Convars != nullptr && title != nullptr )
  {
    ConMsg(a1: "%s\n{\n", title);
    for ( i = KeyValues::GetFirstValue(this: pKV_Convars); i != nullptr; i = KeyValues::GetNextValue(this: i) )
    {
      Name = KeyValues::GetName(this: i);
      ConVarRef::ConVarRef(this: &conVarRef, pName: Name);
      m_pszString = conVarRef.m_pConVarState->m_Value.m_pszString;
      String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
      v6 = KeyValues::GetName(this: i);
      ConMsg(a1: "\t\"%s\": current value (\"%s\"), expected value (\"%s\")\n", v6, m_pszString, String);
    }
    ConMsg(a1: "}\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CC4F0
// Name: public: virtual int GameTypes::GetFreestyleBotDifficulty(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GameTypes::GetFreestyleBotDifficulty(GameTypes *this)
{
  if ( freestyle_bot_difficulty.m_pParent != nullptr )
    return freestyle_bot_difficulty.m_pParent->m_Value.m_nValue;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101CC500
// Name: void DisplayGameModeConvars(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisplayGameModeConvars()
{
  if ( g_pGameTypes != nullptr )
    g_pGameTypes->DisplayConvarsForCurrentMode(this: g_pGameTypes);
}

//------------------------------------------------------------------------------
// Address: 0x101CC520
// Name: public: virtual bool GameTypes::SetFreestyleBotDifficulty(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameTypes::SetFreestyleBotDifficulty(GameTypes *this, int botDiff)
{
  if ( botDiff < 0 || botDiff >= this->m_FreestyleBotDifficulties.m_Size )
  {
    _Warning(
      a1: "GameTypes: invalid freestyle bot difficulty (%d). Range [%d,%d].\n",
      botDiff,
      0,
      this->m_FreestyleBotDifficulties.m_Size - 1);
    return 0;
  }
  else
  {
    DevMsg(a1: "GameTypes: setting freestyle_bot_difficulty to %d.\n", botDiff);
    ConVar::SetValue(this: (ConVar *)&freestyle_bot_difficulty.IConVar, value: botDiff);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CC570
// Name: private: struct GameTypes::GameType __near * GameTypes::GetGameType_Internal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
GameTypes::GameType *__thiscall GameTypes::GetGameType_Internal(GameTypes *this, const char *gameType)
{
  const char *v2; // eax
  int v4; // edi
  GameTypes::GameType *v5; // esi

  v2 = gameType;
  if ( gameType != nullptr && *gameType != 0 && (v4 = 0, this->m_GameTypes.m_Size > 0) )
  {
    while ( 1 )
    {
      v5 = this->m_GameTypes.m_Memory.m_pMemory[v4];
      if ( v5 != nullptr && _V_stricmp(s1: v5->m_Name, s2: gameType) == 0 )
        return v5;
      if ( ++v4 >= this->m_GameTypes.m_Size )
      {
        v2 = gameType;
        goto LABEL_8;
      }
    }
  }
  else
  {
LABEL_8:
    _Warning(a1: "GameTypes: could not find matching game type \"%s\".\n", v2);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CC5E0
// Name: private: struct GameTypes::GameMode __near * GameTypes::GetGameMode_Internal(struct GameTypes::GameType __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
GameTypes::GameMode *__thiscall GameTypes::GetGameMode_Internal(
        GameTypes *this,
        GameTypes::GameType *pGameType,
        const char *gameMode)
{
  int v3; // edi
  GameTypes::GameMode *v4; // esi
  char *m_Name; // ebx

  if ( pGameType == nullptr )
  {
    m_Name = "null";
    goto LABEL_11;
  }
  if ( gameMode == nullptr || *gameMode == 0 || (v3 = 0, pGameType->m_GameModes.m_Size <= 0) )
  {
LABEL_8:
    m_Name = pGameType->m_Name;
LABEL_11:
    _Warning(a1: "GameTypes: could not find matching game mode \"%s\" for type \"%s\".\n", gameMode, m_Name);
    return nullptr;
  }
  while ( 1 )
  {
    v4 = pGameType->m_GameModes.m_Memory.m_pMemory[v3];
    if ( v4 != nullptr && _V_stricmp(s1: v4->m_Name, s2: gameMode) == 0 )
      return v4;
    if ( ++v3 >= pGameType->m_GameModes.m_Size )
      goto LABEL_8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CC660
// Name: private: struct GameTypes::Map __near * GameTypes::GetMap_Internal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
GameTypes::Map *__thiscall GameTypes::GetMap_Internal(GameTypes *this, char *mapName)
{
  unsigned int v4; // eax
  char *v5; // esi
  unsigned int v6; // eax
  char *v7; // esi
  int v8; // esi
  GameTypes::Map *v9; // edi
  char mapNameNoExt[36]; // [esp+4h] [ebp-24h] BYREF

  if ( this->m_Maps.m_Size != 0 )
  {
    if ( mapName != nullptr && *mapName != 0 )
    {
      V_strncpy(pDest: mapNameNoExt, pSrc: mapName, maxLen: 33);
      v4 = _V_strlen(str: mapNameNoExt);
      v5 = &mapNameNoExt[v4 - 4];
      if ( v5 >= mapNameNoExt && V_strnicmp(s1: &mapNameNoExt[v4 - 4], s2: ".360", n: 4) == 0 )
        *v5 = 0;
      v6 = _V_strlen(str: mapNameNoExt);
      v7 = &mapNameNoExt[v6 - 4];
      if ( v7 >= mapNameNoExt && V_strnicmp(s1: &mapNameNoExt[v6 - 4], s2: ".bsp", n: 4) == 0 )
        *v7 = 0;
      v8 = 0;
      if ( this->m_Maps.m_Size <= 0 )
      {
LABEL_15:
        _Warning(a1: "GameTypes: could not find matching map \"%s\".\n", mapNameNoExt);
        return nullptr;
      }
      else
      {
        while ( 1 )
        {
          v9 = this->m_Maps.m_Memory.m_pMemory[v8];
          if ( v9 != nullptr && _V_stricmp(s1: v9->m_Name, s2: mapNameNoExt) == 0 )
            return v9;
          if ( ++v8 >= this->m_Maps.m_Size )
            goto LABEL_15;
        }
      }
    }
    else
    {
      _Warning(a1: "GamesTypes: invalid map name.\n");
      return nullptr;
    }
  }
  else
  {
    _Warning(a1: "GamesTypes: no maps have been loaded.\n");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CC780
// Name: private: struct GameTypes::FreestyleBotDifficulty __near * GameTypes::GetCurrentFreestyleBotDifficulty_Internal(void)
// Source: json
//------------------------------------------------------------------------------
GameTypes::FreestyleBotDifficulty *__thiscall GameTypes::GetCurrentFreestyleBotDifficulty_Internal(GameTypes *this)
{
  int m_Size; // edx
  int m_nValue; // eax

  m_Size = this->m_FreestyleBotDifficulties.m_Size;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no freestyle bot difficulties have been loaded.\n");
    return nullptr;
  }
  if ( freestyle_bot_difficulty.m_pParent != nullptr )
  {
    m_nValue = freestyle_bot_difficulty.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
      goto LABEL_8;
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue < m_Size )
    return this->m_FreestyleBotDifficulties.m_Memory.m_pMemory[m_nValue];
LABEL_8:
  _Warning(
    a1: "GamesTypes: freestyle_bot_difficulty is set to an invalid value (%d). Range [%d,%d].\n",
    m_nValue,
    0,
    m_Size - 1);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101CC7D0
// Name: public: virtual char const __near * GameTypes::GetCurrentGameTypeNameID(void)
// Source: json
//------------------------------------------------------------------------------
GameTypes::GameType *__thiscall GameTypes::GetCurrentGameTypeNameID(GameTypes *this)
{
  int m_Size; // edx
  GameTypes::GameType *result; // eax
  int m_nValue; // eax

  m_Size = this->m_GameTypes.m_Size;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no game types have been loaded.\n");
    return nullptr;
  }
  if ( game_type.m_pParent != nullptr )
  {
    m_nValue = game_type.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
    {
LABEL_9:
      _Warning(a1: "GamesTypes: game_type is set to an invalid value (%d). Range [%d,%d].\n", m_nValue, 0, m_Size - 1);
      return nullptr;
    }
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue >= m_Size )
    goto LABEL_9;
  result = this->m_GameTypes.m_Memory.m_pMemory[m_nValue];
  if ( result != nullptr )
    return (GameTypes::GameType *)((char *)result + 36);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101CC830
// Name: public: virtual char const __near * GameTypes::GetCurrentGameModeNameID(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall GameTypes::GetCurrentGameModeNameID(GameTypes *this)
{
  int m_Size; // edx
  int m_nValue; // eax
  GameTypes::GameType *v4; // ecx
  int v5; // eax
  GameTypes::GameMode *v6; // eax

  m_Size = this->m_GameTypes.m_Size;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no game types have been loaded.\n");
    return nullptr;
  }
  if ( game_type.m_pParent != nullptr )
  {
    m_nValue = game_type.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
    {
LABEL_9:
      _Warning(a1: "GamesTypes: game_type is set to an invalid value (%d). Range [%d,%d].\n", m_nValue, 0, m_Size - 1);
      return nullptr;
    }
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue >= m_Size )
    goto LABEL_9;
  v4 = this->m_GameTypes.m_Memory.m_pMemory[m_nValue];
  if ( v4 == nullptr )
    return nullptr;
  if ( game_mode.m_pParent != nullptr )
  {
    v5 = game_mode.m_pParent->m_Value.m_nValue;
    if ( v5 < 0 )
    {
LABEL_16:
      _Warning(
        a1: "GamesTypes: game_mode is set to an invalid value (%d). Range [%d,%d].\n",
        v5,
        0,
        v4->m_GameModes.m_Size - 1);
      return nullptr;
    }
  }
  else
  {
    v5 = 0;
  }
  if ( v5 >= v4->m_GameModes.m_Size )
    goto LABEL_16;
  v6 = v4->m_GameModes.m_Memory.m_pMemory[v5];
  if ( v6 == nullptr )
    return nullptr;
  return v6->m_NameID;
}

//------------------------------------------------------------------------------
// Address: 0x101CC8D0
// Name: public: virtual bool GameTypes::ApplyConvarsForCurrentMode(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameTypes::ApplyConvarsForCurrentMode(GameTypes *this, bool isMultiplayer)
{
  int m_Size; // ecx
  int m_nValue; // eax
  GameTypes::GameType *v6; // edx
  int v7; // eax
  GameTypes::GameMode *v8; // ebx
  KeyValues *m_pConvarsSP; // edi
  int v10; // ecx
  int v11; // eax
  KeyValues *i; // esi
  const char *Name; // eax
  char *String; // eax
  int v15; // ecx
  int v16; // eax
  GameTypes *v17; // esi
  GameTypes::FreestyleBotDifficulty *CurrentFreestyleBotDifficulty_Internal; // eax
  GameTypes::FreestyleBotDifficulty *v19; // ebx
  KeyValues *m_pConvars; // edi
  KeyValues *j; // esi
  const char *v22; // eax
  char *v23; // eax
  int v24; // eax
  int v25; // eax
  ConVarRef conVarRef; // [esp+4h] [ebp-18h] BYREF
  IKeyValuesDumpContext v27; // [esp+Ch] [ebp-10h] BYREF
  GameTypes *v28; // [esp+10h] [ebp-Ch]
  IKeyValuesDumpContext pDump; // [esp+14h] [ebp-8h] BYREF
  GameTypes::GameType *pGameType; // [esp+18h] [ebp-4h]

  m_Size = this->m_GameTypes.m_Size;
  v28 = this;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no game types have been loaded.\n");
    return 0;
  }
  if ( game_type.m_pParent != nullptr )
  {
    m_nValue = game_type.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
    {
LABEL_9:
      _Warning(a1: "GamesTypes: game_type is set to an invalid value (%d). Range [%d,%d].\n", m_nValue, 0, m_Size - 1);
      return 0;
    }
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue >= m_Size )
    goto LABEL_9;
  v6 = this->m_GameTypes.m_Memory.m_pMemory[m_nValue];
  pGameType = v6;
  if ( v6 == nullptr )
    return 0;
  if ( game_mode.m_pParent != nullptr )
  {
    v7 = game_mode.m_pParent->m_Value.m_nValue;
    if ( v7 < 0 )
    {
LABEL_20:
      _Warning(
        a1: "GamesTypes: game_mode is set to an invalid value (%d). Range [%d,%d].\n",
        v7,
        0,
        v6->m_GameModes.m_Size - 1);
      return 0;
    }
  }
  else
  {
    v7 = 0;
  }
  if ( v7 >= v6->m_GameModes.m_Size )
    goto LABEL_20;
  v8 = v6->m_GameModes.m_Memory.m_pMemory[v7];
  if ( v8 == nullptr )
    return 0;
  if ( !isMultiplayer || (m_pConvarsSP = v8->m_pConvarsMP) == nullptr )
  {
    m_pConvarsSP = v8->m_pConvarsSP;
    if ( m_pConvarsSP == nullptr )
    {
      if ( game_mode.m_pParent != nullptr )
        v10 = game_mode.m_pParent->m_Value.m_nValue;
      else
        v10 = 0;
      if ( game_type.m_pParent != nullptr )
        v11 = game_type.m_pParent->m_Value.m_nValue;
      else
        v11 = 0;
      _Warning(
        a1: "GamesTypes: unable to set convars. There are no convars for game type/mode (%s:%d/%s:%d).\n",
        v6->m_Name,
        v11,
        v8->m_Name,
        v10);
      return 0;
    }
  }
  for ( i = KeyValues::GetFirstValue(this: m_pConvarsSP); i != nullptr; i = KeyValues::GetNextValue(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    ConVarRef::ConVarRef(this: &conVarRef, pName: Name);
    String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
    conVarRef.m_pConVar->SetValue_4(this: conVarRef.m_pConVar, a2: String);
  }
  if ( game_mode.m_pParent != nullptr )
    v15 = game_mode.m_pParent->m_Value.m_nValue;
  else
    v15 = 0;
  if ( game_type.m_pParent != nullptr )
    v16 = game_type.m_pParent->m_Value.m_nValue;
  else
    v16 = 0;
  DevMsg(a1: "GameTypes: set convars for game type/mode (%s:%d/%s:%d):\n", pGameType->m_Name, v16, v8->m_Name, v15);
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  pGameType = (GameTypes::GameType *)1;
  KeyValues::Dump(this: m_pConvarsSP, &pDump, nIndentLevel: 1);
  v17 = v28;
  if ( v28->GetCurrentGameMode(this: v28) != 2 )
    return 1;
  if ( v17->GetCurrentGameType(this: v17) != 0 )
    return 1;
  CurrentFreestyleBotDifficulty_Internal = GameTypes::GetCurrentFreestyleBotDifficulty_Internal(this: v17);
  v19 = CurrentFreestyleBotDifficulty_Internal;
  if ( CurrentFreestyleBotDifficulty_Internal == nullptr )
    return 1;
  m_pConvars = CurrentFreestyleBotDifficulty_Internal->m_pConvars;
  if ( m_pConvars == nullptr )
  {
    if ( freestyle_bot_difficulty.m_pParent != nullptr )
      v25 = freestyle_bot_difficulty.m_pParent->m_Value.m_nValue;
    else
      v25 = 0;
    _Warning(
      a1: "GamesTypes: unable to set freestyle bot difficulty convars. There are no convars for bot difficulty (%s:%d).\n",
      v19->m_Name,
      v25);
    return 1;
  }
  for ( j = KeyValues::GetFirstValue(this: CurrentFreestyleBotDifficulty_Internal->m_pConvars);
        j != nullptr;
        j = KeyValues::GetNextValue(this: j) )
  {
    v22 = KeyValues::GetName(this: j);
    ConVarRef::ConVarRef(this: &conVarRef, pName: v22);
    v23 = KeyValues::GetString(this: j, keyName: nullptr, defaultValue: prType);
    conVarRef.m_pConVar->SetValue_4(this: conVarRef.m_pConVar, a2: v23);
  }
  if ( freestyle_bot_difficulty.m_pParent != nullptr )
    v24 = freestyle_bot_difficulty.m_pParent->m_Value.m_nValue;
  else
    v24 = 0;
  DevMsg(a1: "GameTypes: set convars for freestyle bot difficulty (%s:%d):\n", v19->m_Name, v24);
  v27.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  v28 = (GameTypes *)1;
  KeyValues::Dump(this: m_pConvars, pDump: &v27, nIndentLevel: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101CCB70
// Name: public: virtual void GameTypes::DisplayConvarsForCurrentMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GameTypes::DisplayConvarsForCurrentMode(GameTypes *this)
{
  GameTypes *v1; // edx
  int m_Size; // esi
  int m_nValue; // eax
  GameTypes::GameType *v4; // ebx
  ConVar *m_pParent; // ecx
  int v6; // eax
  GameTypes::GameMode *v7; // esi
  KeyValues *m_pConvarsSP; // edi
  int v9; // ecx
  int v10; // eax
  KeyValues *m_pConvarsMP; // edi
  int v12; // ecx
  int v13; // eax
  GameTypes *v14; // edi
  GameTypes::FreestyleBotDifficulty *CurrentFreestyleBotDifficulty_Internal; // eax
  KeyValues *m_pConvars; // esi
  int v17; // ecx
  char title[256]; // [esp+4h] [ebp-104h] BYREF
  GameTypes *v19; // [esp+104h] [ebp-4h]

  v1 = this;
  m_Size = this->m_GameTypes.m_Size;
  v19 = this;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no game types have been loaded.\n");
    return;
  }
  if ( game_type.m_pParent != nullptr )
  {
    m_nValue = game_type.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
    {
LABEL_15:
      _Warning(a1: "GamesTypes: game_type is set to an invalid value (%d). Range [%d,%d].\n", m_nValue, 0, m_Size - 1);
      return;
    }
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue >= m_Size )
    goto LABEL_15;
  v4 = this->m_GameTypes.m_Memory.m_pMemory[m_nValue];
  if ( v4 == nullptr )
    return;
  m_pParent = game_mode.m_pParent;
  if ( game_mode.m_pParent != nullptr )
  {
    v6 = game_mode.m_pParent->m_Value.m_nValue;
    if ( v6 < 0 )
    {
LABEL_17:
      _Warning(
        a1: "GamesTypes: game_mode is set to an invalid value (%d). Range [%d,%d].\n",
        v6,
        0,
        v4->m_GameModes.m_Size - 1);
      return;
    }
  }
  else
  {
    v6 = 0;
  }
  if ( v6 >= v4->m_GameModes.m_Size )
    goto LABEL_17;
  v7 = v4->m_GameModes.m_Memory.m_pMemory[v6];
  if ( v7 != nullptr )
  {
    m_pConvarsSP = v7->m_pConvarsSP;
    if ( m_pConvarsSP != nullptr )
    {
      if ( game_mode.m_pParent != nullptr )
        v9 = game_mode.m_pParent->m_Value.m_nValue;
      else
        v9 = 0;
      if ( game_type.m_pParent != nullptr )
        v10 = game_type.m_pParent->m_Value.m_nValue;
      else
        v10 = 0;
      V_snprintf(
        pDest: title,
        maxLen: 0x100u,
        pFormat: "GameTypes: dumping convars for game type/mode (%s:%d/%s:%d):",
        v4->m_Name,
        v10,
        v7->m_Name,
        v9);
      GameTypes::DisplayConvars(this: v19, pKV_Convars: m_pConvarsSP, title);
      m_pParent = game_mode.m_pParent;
      v1 = v19;
    }
    m_pConvarsMP = v7->m_pConvarsMP;
    if ( m_pConvarsMP != nullptr )
    {
      if ( m_pParent != nullptr )
        v12 = m_pParent->m_Value.m_nValue;
      else
        v12 = 0;
      if ( game_type.m_pParent != nullptr )
        v13 = game_type.m_pParent->m_Value.m_nValue;
      else
        v13 = 0;
      V_snprintf(
        pDest: title,
        maxLen: 0x100u,
        pFormat: "GameTypes: dumping multiplayer convars for game type/mode (%s:%d/%s:%d):",
        v4->m_Name,
        v13,
        v7->m_Name,
        v12);
      GameTypes::DisplayConvars(this: v19, pKV_Convars: m_pConvarsMP, title);
      v1 = v19;
    }
    if ( v1->GetCurrentGameMode(this: v1) == 2 )
    {
      v14 = v19;
      if ( v19->GetCurrentGameType(this: v19) == 0 )
      {
        CurrentFreestyleBotDifficulty_Internal = GameTypes::GetCurrentFreestyleBotDifficulty_Internal(this: v14);
        if ( CurrentFreestyleBotDifficulty_Internal != nullptr )
        {
          m_pConvars = CurrentFreestyleBotDifficulty_Internal->m_pConvars;
          if ( m_pConvars != nullptr )
          {
            if ( freestyle_bot_difficulty.m_pParent != nullptr )
              v17 = freestyle_bot_difficulty.m_pParent->m_Value.m_nValue;
            else
              v17 = 0;
            V_snprintf(
              pDest: title,
              maxLen: 0x100u,
              pFormat: "GameTypes: dumping convars for freestyle bot difficulty (%s:%d):",
              CurrentFreestyleBotDifficulty_Internal->m_Name,
              v17);
            GameTypes::DisplayConvars(this: v14, pKV_Convars: m_pConvars, title);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CCE90
// Name: public: virtual char const __near * GameTypes::GetRandomMap(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char *__thiscall GameTypes::GetRandomMap(GameTypes *this, const char *gameType, const char *gameMode)
{
  GameTypes::GameType *GameType_Internal; // eax
  GameTypes::GameMode *GameMode_Internal; // eax
  IUniformRandomStream *v6; // ecx
  GameTypes::GameMode *v7; // esi
  int m_Size; // eax

  if ( gameType != nullptr
    && gameMode != nullptr
    && (GameType_Internal = GameTypes::GetGameType_Internal(this, gameType)) != nullptr
    && (GameMode_Internal = GameTypes::GetGameMode_Internal(this, pGameType: GameType_Internal, gameMode),
        v7 = GameMode_Internal,
        GameMode_Internal != nullptr)
    && (m_Size = GameMode_Internal->m_Maps.m_Size) != 0 )
  {
    return v7->m_Maps.m_Memory.m_pMemory[_RandomInt(this: v6, a2: 0, a3: m_Size - 1)];
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CCEF0
// Name: public: virtual bool GameTypes::ApplyConvarsForMap(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameTypes::ApplyConvarsForMap(GameTypes *this, char *mapName)
{
  GameTypes::Map *Map_Internal; // edi
  GameTypes::FreestyleBotDifficulty *CurrentFreestyleBotDifficulty_Internal; // eax
  ConVarRef bot_quota; // [esp+Ch] [ebp-8h] BYREF

  Map_Internal = GameTypes::GetMap_Internal(this, mapName);
  if ( Map_Internal != nullptr )
  {
    if ( this->GetCurrentGameMode(this) != 2
      || this->GetCurrentGameType(this) != 0
      || (CurrentFreestyleBotDifficulty_Internal = GameTypes::GetCurrentFreestyleBotDifficulty_Internal(this)) == nullptr
      || !CurrentFreestyleBotDifficulty_Internal->m_HasBotQuota )
    {
      DevMsg(a1: "GameTypes: setting bot_quota to %d for map %s.\n", Map_Internal->m_MinPlayers, Map_Internal->m_Name);
      ConVarRef::ConVarRef(this: &bot_quota, pName: "bot_quota");
      bot_quota.m_pConVar->SetValue_2(this: bot_quota.m_pConVar, a2: Map_Internal->m_MinPlayers);
    }
    return 1;
  }
  else
  {
    _Warning(a1: "GamesTypes: unable to set convars for map %s. Could not find matching map name.\n", mapName);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CCFA0
// Name: public: virtual bool GameTypes::GetMapInfo(char const __near *,int __near &,int __near &,unsigned int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameTypes::GetMapInfo(
        GameTypes *this,
        char *mapName,
        int *maxPlayers,
        int *extraSpectators,
        unsigned int *richPresence)
{
  GameTypes::Map *Map_Internal; // eax

  Map_Internal = GameTypes::GetMap_Internal(this, mapName);
  if ( Map_Internal == nullptr )
    return 0;
  *maxPlayers = Map_Internal->m_MaxPlayers;
  *richPresence = Map_Internal->m_RichPresence;
  *extraSpectators = Map_Internal->m_ExtraSpectators;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101CCFE0
// Name: public: virtual class CUtlStringList const __near * GameTypes::GetTModelsForMap(char const __near *)
// Source: json
//------------------------------------------------------------------------------
GameTypes::Map *__thiscall GameTypes::GetTModelsForMap(GameTypes *this, char *mapName)
{
  GameTypes::Map *result; // eax

  result = GameTypes::GetMap_Internal(this, mapName);
  if ( result != nullptr )
    return (GameTypes::Map *)((char *)result + 84);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101CD000
// Name: public: virtual class CUtlStringList const __near * GameTypes::GetCTModelsForMap(char const __near *)
// Source: json
//------------------------------------------------------------------------------
GameTypes::Map *__thiscall GameTypes::GetCTModelsForMap(GameTypes *this, char *mapName)
{
  GameTypes::Map *result; // eax

  result = GameTypes::GetMap_Internal(this, mapName);
  if ( result != nullptr )
    return (GameTypes::Map *)((char *)result + 104);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101CD020
// Name: public: virtual char const __near * GameTypes::GetGameTypeFromInt(int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall GameTypes::GetGameTypeFromInt(GameTypes *this, int gameType)
{
  int m_Size; // esi
  int v3; // eax
  GameTypes::GameType **m_pMemory; // edx
  GameTypes::GameType *v5; // ecx

  m_Size = this->m_GameTypes.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
  {
LABEL_6:
    _Warning(a1: "GameTypes: could not find matching game type for value \"%d\".\n", gameType);
    return nullptr;
  }
  else
  {
    m_pMemory = this->m_GameTypes.m_Memory.m_pMemory;
    while ( 1 )
    {
      v5 = *m_pMemory;
      if ( *m_pMemory != nullptr && v5->m_Index == gameType )
        return v5->m_Name;
      ++v3;
      ++m_pMemory;
      if ( v3 >= m_Size )
        goto LABEL_6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CD070
// Name: public: virtual char const __near * GameTypes::GetGameModeFromInt(int,int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall GameTypes::GetGameModeFromInt(GameTypes *this, int gameType, int gameMode)
{
  int m_Size; // edx
  int v5; // edi
  GameTypes::GameType **m_pMemory; // ecx
  GameTypes::GameType *v7; // ecx
  int v8; // esi
  int v9; // eax
  GameTypes::GameMode **v10; // edx
  GameTypes::GameMode *v11; // ecx
  int v13; // [esp+Ch] [ebp-4h]
  int gameModea; // [esp+1Ch] [ebp+Ch]

  m_Size = this->m_GameTypes.m_Size;
  v5 = 0;
  v13 = m_Size;
  if ( m_Size <= 0 )
  {
LABEL_12:
    _Warning(
      a1: "GameTypes: could not find matching game mode value of \"%d\" and type value of \"%d\".\n",
      gameType,
      gameMode);
    return nullptr;
  }
  else
  {
    m_pMemory = this->m_GameTypes.m_Memory.m_pMemory;
    gameModea = (int)m_pMemory;
    while ( 1 )
    {
      v7 = *m_pMemory;
      if ( v7 != nullptr && v7->m_Index == gameType )
      {
        v8 = v7->m_GameModes.m_Size;
        v9 = 0;
        if ( v8 > 0 )
          break;
      }
LABEL_11:
      ++v5;
      m_pMemory = (GameTypes::GameType **)(gameModea + 4);
      gameModea += 4;
      if ( v5 >= m_Size )
        goto LABEL_12;
    }
    v10 = v7->m_GameModes.m_Memory.m_pMemory;
    while ( 1 )
    {
      v11 = *v10;
      if ( *v10 != nullptr && v11->m_Index == gameMode )
        return v11->m_Name;
      ++v9;
      ++v10;
      if ( v9 >= v8 )
      {
        m_Size = v13;
        goto LABEL_11;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CD100
// Name: public: virtual int GameTypes::GetNoResetVoteThresholdForCurrentModeCT(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GameTypes::GetNoResetVoteThresholdForCurrentModeCT(GameTypes *this)
{
  int m_Size; // edx
  int m_nValue; // eax
  GameTypes::GameType *v4; // ecx
  int v5; // eax
  GameTypes::GameMode *v6; // eax

  m_Size = this->m_GameTypes.m_Size;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no game types have been loaded.\n");
    return -1;
  }
  if ( game_type.m_pParent != nullptr )
  {
    m_nValue = game_type.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
    {
LABEL_9:
      _Warning(a1: "GamesTypes: game_type is set to an invalid value (%d). Range [%d,%d].\n", m_nValue, 0, m_Size - 1);
      return -1;
    }
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue >= m_Size )
    goto LABEL_9;
  v4 = this->m_GameTypes.m_Memory.m_pMemory[m_nValue];
  if ( v4 == nullptr )
    return -1;
  if ( game_mode.m_pParent != nullptr )
  {
    v5 = game_mode.m_pParent->m_Value.m_nValue;
    if ( v5 < 0 )
    {
LABEL_16:
      _Warning(
        a1: "GamesTypes: game_mode is set to an invalid value (%d). Range [%d,%d].\n",
        v5,
        0,
        v4->m_GameModes.m_Size - 1);
      return -1;
    }
  }
  else
  {
    v5 = 0;
  }
  if ( v5 >= v4->m_GameModes.m_Size )
    goto LABEL_16;
  v6 = v4->m_GameModes.m_Memory.m_pMemory[v5];
  if ( v6 == nullptr )
    return -1;
  return v6->m_NoResetVoteThresholdCT;
}

//------------------------------------------------------------------------------
// Address: 0x101CD1A0
// Name: public: virtual int GameTypes::GetNoResetVoteThresholdForCurrentModeT(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GameTypes::GetNoResetVoteThresholdForCurrentModeT(GameTypes *this)
{
  int m_Size; // edx
  int m_nValue; // eax
  GameTypes::GameType *v4; // ecx
  int v5; // eax
  GameTypes::GameMode *v6; // eax

  m_Size = this->m_GameTypes.m_Size;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no game types have been loaded.\n");
    return -1;
  }
  if ( game_type.m_pParent != nullptr )
  {
    m_nValue = game_type.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
    {
LABEL_9:
      _Warning(a1: "GamesTypes: game_type is set to an invalid value (%d). Range [%d,%d].\n", m_nValue, 0, m_Size - 1);
      return -1;
    }
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue >= m_Size )
    goto LABEL_9;
  v4 = this->m_GameTypes.m_Memory.m_pMemory[m_nValue];
  if ( v4 == nullptr )
    return -1;
  if ( game_mode.m_pParent != nullptr )
  {
    v5 = game_mode.m_pParent->m_Value.m_nValue;
    if ( v5 < 0 )
    {
LABEL_16:
      _Warning(
        a1: "GamesTypes: game_mode is set to an invalid value (%d). Range [%d,%d].\n",
        v5,
        0,
        v4->m_GameModes.m_Size - 1);
      return -1;
    }
  }
  else
  {
    v5 = 0;
  }
  if ( v5 >= v4->m_GameModes.m_Size )
    goto LABEL_16;
  v6 = v4->m_GameModes.m_Memory.m_pMemory[v5];
  if ( v6 == nullptr )
    return -1;
  return v6->m_NoResetVoteThresholdT;
}

//------------------------------------------------------------------------------
// Address: 0x101CD240
// Name: public: virtual bool GameTypes::GetGameModeAndTypeIntsFromStrings(char const __near *,char const __near *,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameTypes::GetGameModeAndTypeIntsFromStrings(
        GameTypes *this,
        const char *szGameType,
        const char *szGameMode,
        int *iOutGameType,
        int *iOutGameMode)
{
  GameTypes::GameType *GameType_Internal; // eax
  GameTypes::GameType *v7; // esi
  GameTypes::GameMode *GameMode_Internal; // eax
  int m_Index; // ecx

  *iOutGameType = -1;
  *iOutGameMode = -1;
  if ( szGameType == nullptr || szGameMode == nullptr )
    return 0;
  GameType_Internal = GameTypes::GetGameType_Internal(this, gameType: szGameType);
  v7 = GameType_Internal;
  if ( GameType_Internal == nullptr
    || (GameMode_Internal = GameTypes::GetGameMode_Internal(this, pGameType: GameType_Internal, gameMode: szGameMode)) == nullptr )
  {
    _Warning(
      a1: "GamesTypes: unable to get game type and mode. Could not find type/mode matching type:%s/mode:%s.\n",
      szGameType,
      szGameMode);
    return 0;
  }
  m_Index = v7->m_Index;
  if ( v7->m_Index < 0
    || m_Index >= this->m_GameTypes.m_Size
    || GameMode_Internal->m_Index < 0
    || GameMode_Internal->m_Index >= v7->m_GameModes.m_Size )
  {
    return 0;
  }
  *iOutGameType = m_Index;
  *iOutGameMode = GameMode_Internal->m_Index;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101CD2D0
// Name: public: virtual bool GameTypes::GetGameModeAndTypeNameIdsFromStrings(char const __near *,char const __near *,char const __near * __near &,char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameTypes::GetGameModeAndTypeNameIdsFromStrings(
        GameTypes *this,
        const char *szGameType,
        const char *szGameMode,
        char **szOutGameTypeNameId,
        char **szOutGameModeNameId)
{
  GameTypes::GameType *GameType_Internal; // eax
  GameTypes::GameType *v7; // esi
  GameTypes::GameMode *GameMode_Internal; // eax

  *szOutGameTypeNameId = nullptr;
  *szOutGameModeNameId = nullptr;
  if ( szGameType == nullptr || szGameMode == nullptr )
    return 0;
  GameType_Internal = GameTypes::GetGameType_Internal(this, gameType: szGameType);
  v7 = GameType_Internal;
  if ( GameType_Internal == nullptr
    || (GameMode_Internal = GameTypes::GetGameMode_Internal(this, pGameType: GameType_Internal, gameMode: szGameMode)) == nullptr )
  {
    _Warning(
      a1: "GamesTypes: unable to get game type and mode. Could not find type/mode matching type:%s/mode:%s.\n",
      szGameType,
      szGameMode);
    return 0;
  }
  if ( GameMode_Internal == (GameTypes::GameMode *)-36 || v7 == (GameTypes::GameType *)-36 )
    return 0;
  *szOutGameTypeNameId = v7->m_NameID;
  *szOutGameModeNameId = GameMode_Internal->m_NameID;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101CD450
// Name: public: void CUtlStringList::CopyAndAddToTail(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlStringList::CopyAndAddToTail(CUtlStringList *this, const char *pString)
{
  char *v3; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v7; // eax
  char **v8; // edi

  v3 = (char *)MemAlloc_Alloc(nSize: strlen(pString) + 1);
  _V_strcpy(dest: v3, src: pString);
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v7);
  v8 = &this->m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = v3;
}

//------------------------------------------------------------------------------
// Address: 0x101CD4D0
// Name: private: bool GameTypes::LoadFreestyleBotDifficulties(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameTypes::LoadFreestyleBotDifficulties(GameTypes *this, KeyValues *pKV)
{
  KeyValues *Key; // eax
  KeyValues *FirstTrueSubKey; // edi
  _DWORD *v6; // eax
  GameTypes::FreestyleBotDifficulty *v7; // ebx
  char *Name; // eax
  char *String; // eax
  const char *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  GameTypes::FreestyleBotDifficulty **m_pMemory; // ecx
  int v16; // eax
  GameTypes::FreestyleBotDifficulty **v17; // edi
  const char *v18; // eax
  KeyValues *pKV_BotDiff; // [esp+14h] [ebp+8h]

  if ( pKV == nullptr )
    return 0;
  if ( this->m_FreestyleBotDifficulties.m_Size > 0 )
    CUtlVector<GameTypes::FreestyleBotDifficulty *,CUtlMemory<GameTypes::FreestyleBotDifficulty *,int>>::PurgeAndDeleteElements(this: &this->m_FreestyleBotDifficulties);
  Key = KeyValues::FindKey(this: pKV, keyName: "botDifficulty", bCreate: false);
  if ( Key == nullptr )
  {
    _Warning(a1: "GameTypes: could not find entry %s.\n", "botDifficulty");
    return 0;
  }
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: Key);
  pKV_BotDiff = FirstTrueSubKey;
  if ( FirstTrueSubKey != nullptr )
  {
    while ( 1 )
    {
      v6 = MemAlloc_Alloc(nSize: 0x4Cu);
      v7 = nullptr;
      if ( v6 != nullptr )
      {
        v6[17] = 0;
        *((_BYTE *)v6 + 72) = 0;
        *((_BYTE *)v6 + 4) = 0;
        *((_BYTE *)v6 + 36) = 0;
        *v6 = -1;
        v7 = (GameTypes::FreestyleBotDifficulty *)v6;
      }
      Name = (char *)KeyValues::GetName(this: FirstTrueSubKey);
      V_strncpy(pDest: v7->m_Name, pSrc: Name, maxLen: 32);
      String = KeyValues::GetString(this: FirstTrueSubKey, keyName: "nameID", defaultValue: prType);
      if ( String != nullptr )
      {
        V_strncpy(pDest: v7->m_NameID, pSrc: String, maxLen: 32);
      }
      else
      {
        v10 = KeyValues::GetName(this: FirstTrueSubKey);
        _Warning(a1: "GameTypes: missing %s entry for bot difficulty %s.\n", "nameID", v10);
      }
      v11 = KeyValues::FindKey(this: FirstTrueSubKey, keyName: "convars", bCreate: false);
      v12 = v11;
      if ( v11 != nullptr )
      {
        v7->m_pConvars = KeyValues::MakeCopy(this: v11);
        v7->m_HasBotQuota = KeyValues::GetInt(this: v12, keyName: "bot_quota", defaultValue: -1) != -1;
      }
      else
      {
        v18 = KeyValues::GetName(this: pKV_BotDiff);
        _Warning(a1: "GameTypes: missing entry %s for bot difficulty %s.\n", "convars", v18);
      }
      v7->m_Index = this->m_FreestyleBotDifficulties.m_Size;
      m_Size = this->m_FreestyleBotDifficulties.m_Size;
      m_nAllocationCount = this->m_FreestyleBotDifficulties.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_FreestyleBotDifficulties,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_FreestyleBotDifficulties.m_Size;
      m_pMemory = this->m_FreestyleBotDifficulties.m_Memory.m_pMemory;
      v16 = this->m_FreestyleBotDifficulties.m_Size - m_Size - 1;
      this->m_FreestyleBotDifficulties.m_pElements = m_pMemory;
      if ( v16 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: 4 * v16);
      v17 = &this->m_FreestyleBotDifficulties.m_Memory.m_pMemory[m_Size];
      if ( v17 != nullptr )
        *v17 = v7;
      pKV_BotDiff = KeyValues::GetNextTrueSubKey(this: pKV_BotDiff);
      if ( pKV_BotDiff == nullptr )
        break;
      FirstTrueSubKey = pKV_BotDiff;
    }
  }
  if ( this->m_FreestyleBotDifficulties.m_Size == 0 )
    _Warning(a1: "GamesTypes: empty %s entry.\n", "botDifficulty");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101CD710
// Name: private: void GameTypes::LoadWeaponProgression(class KeyValues __near *,class CUtlVector<struct IGameTypes::WeaponProgression,class CUtlMemory<struct IGameTypes::WeaponProgression,int>> __near &,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GameTypes::LoadWeaponProgression(
        GameTypes *this,
        KeyValues *pKV_WeaponProgression,
        CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int> > *vecWeaponProgression,
        const char *szGameType,
        const char *szGameMode)
{
  KeyValues *v5; // edi
  KeyValues *FirstTrueSubKey; // ebx
  const char *Name; // eax
  const char *v8; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  IGameTypes::WeaponProgression *m_pMemory; // ecx
  int v12; // eax
  IGameTypes::WeaponProgression *v13; // edi
  const char *v14; // eax
  IGameTypes::WeaponProgression wp; // [esp+4h] [ebp-14h] BYREF

  v5 = pKV_WeaponProgression;
  if ( pKV_WeaponProgression != nullptr )
  {
    FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pKV_WeaponProgression);
    if ( FirstTrueSubKey != nullptr )
    {
      do
      {
        CUtlString::CUtlString(this: &wp.m_Name);
        wp.m_Kills = 0;
        Name = KeyValues::GetName(this: FirstTrueSubKey);
        CUtlString::Set(this: &wp.m_Name, pValue: Name);
        wp.m_Kills = KeyValues::GetInt(this: FirstTrueSubKey, keyName: "kills", defaultValue: -1);
        if ( wp.m_Kills == -1 )
        {
          wp.m_Kills = 0;
          v8 = KeyValues::GetName(this: FirstTrueSubKey);
          _Warning(
            a1: "GameTypes: missing %s entry for weapon \"%s\" for game type/mode (%s/%s).\n",
            "kills",
            v8,
            szGameType,
            szGameMode);
        }
        m_Size = vecWeaponProgression->m_Size;
        m_nAllocationCount = vecWeaponProgression->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CUtlVector<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,CUtlMemory<CEntityDataInstantiator<vphysicsupdateai_t>::HashEntry,int>>,int>::Grow(
            this: (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)vecWeaponProgression,
            num: m_Size - m_nAllocationCount + 1);
        ++vecWeaponProgression->m_Size;
        m_pMemory = vecWeaponProgression->m_Memory.m_pMemory;
        v12 = vecWeaponProgression->m_Size - m_Size - 1;
        vecWeaponProgression->m_pElements = vecWeaponProgression->m_Memory.m_pMemory;
        if ( v12 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
            src: (unsigned __int8 *)&m_pMemory[m_Size],
            count: 20 * v12);
        v13 = &vecWeaponProgression->m_Memory.m_pMemory[m_Size];
        if ( v13 != nullptr )
        {
          CUtlString::CUtlString(this: &v13->m_Name, string: &wp.m_Name);
          v13->m_Kills = wp.m_Kills;
        }
        wp.m_Name.m_Storage.m_nActualLength = 0;
        if ( wp.m_Name.m_Storage.m_Memory.m_nGrowSize >= 0 && wp.m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: wp.m_Name.m_Storage.m_Memory.m_pMemory);
        FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
      }
      while ( FirstTrueSubKey != nullptr );
      v5 = pKV_WeaponProgression;
    }
    if ( vecWeaponProgression->m_Size == 0 )
    {
      v14 = KeyValues::GetName(this: v5);
      _Warning(a1: "GameTypes: empty %s entry for game type/mode (%s/%s).\n", v14, szGameType, szGameMode);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101CD990
// Name: public: GameTypes::GameMode::GameMode(void)
// Source: json
//------------------------------------------------------------------------------
GameTypes::GameMode *__thiscall GameTypes::GameMode::GameMode(GameTypes::GameMode *this)
{
  this->m_pConvarsSP = nullptr;
  this->m_pConvarsMP = nullptr;
  this->m_Index = -1;
  this->m_Maps.m_Memory.m_pMemory = nullptr;
  this->m_Maps.m_Memory.m_nAllocationCount = 0;
  this->m_Maps.m_Memory.m_nGrowSize = 0;
  this->m_Maps.m_Size = 0;
  this->m_Maps.m_pElements = nullptr;
  this->m_WeaponProgressionCT.m_Memory.m_pMemory = nullptr;
  this->m_WeaponProgressionCT.m_Memory.m_nAllocationCount = 0;
  this->m_WeaponProgressionCT.m_Memory.m_nGrowSize = 0;
  this->m_WeaponProgressionCT.m_Size = 0;
  this->m_WeaponProgressionCT.m_pElements = nullptr;
  this->m_WeaponProgressionT.m_Memory.m_pMemory = nullptr;
  this->m_WeaponProgressionT.m_Memory.m_nAllocationCount = 0;
  this->m_WeaponProgressionT.m_Memory.m_nGrowSize = 0;
  this->m_WeaponProgressionT.m_Size = 0;
  this->m_WeaponProgressionT.m_pElements = nullptr;
  this->m_Name[0] = 0;
  this->m_NameID[0] = 0;
  this->m_DescID[0] = 0;
  this->m_NoResetVoteThresholdCT = -1;
  this->m_NoResetVoteThresholdT = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101CDA00
// Name: private: bool GameTypes::LoadMaps(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameTypes::LoadMaps(GameTypes *this, KeyValues *pKV)
{
  GameTypes *v2; // edi
  KeyValues *Key; // eax
  KeyValues *FirstTrueSubKey; // ebx
  GameTypes::Map *v6; // eax
  unsigned int v7; // ecx
  GameTypes::Map *v8; // edi
  char *Name; // eax
  char *String; // eax
  const char *v11; // eax
  int Int; // eax
  int v13; // eax
  int v14; // eax
  KeyValues *v15; // eax
  KeyValues *i; // esi
  const char *v17; // eax
  KeyValues *v18; // eax
  KeyValues *FirstValue; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_CTModels; // esi
  const char *v21; // eax
  const char *v22; // edi
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v25; // ecx
  int v26; // eax
  char **v27; // edi
  const char *v28; // eax
  int m_Size; // esi
  CUtlVector<GameTypes::Map *,CUtlMemory<GameTypes::Map *,int> > *p_m_Maps; // edi
  int v31; // eax
  GameTypes::Map **v32; // ecx
  int v33; // eax
  GameTypes::Map **v34; // esi
  const char *v35; // [esp-4h] [ebp-1Ch]
  const char *v36; // [esp-4h] [ebp-1Ch]
  const char *v37; // [esp-4h] [ebp-1Ch]
  const char *v38; // [esp-4h] [ebp-1Ch]
  int v39; // [esp-4h] [ebp-1Ch]
  char *v40; // [esp+Ch] [ebp-Ch]
  KeyValues *pKV_Model; // [esp+14h] [ebp-4h]
  GameTypes::Map *pMap; // [esp+20h] [ebp+8h]

  v2 = this;
  if ( pKV == nullptr )
    return 0;
  if ( this->m_Maps.m_Size > 0 )
    CUtlVector<GameTypes::Map *,CUtlMemory<GameTypes::Map *,int>>::PurgeAndDeleteElements(this: &this->m_Maps);
  Key = KeyValues::FindKey(this: pKV, keyName: "maps", bCreate: false);
  if ( Key == nullptr )
  {
    _Warning(a1: "GameTypes: could not find entry %s.\n", "maps");
    return 0;
  }
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: Key);
  if ( FirstTrueSubKey == nullptr )
    goto LABEL_49;
  do
  {
    v6 = (GameTypes::Map *)MemAlloc_Alloc(nSize: 0x7Cu);
    if ( v6 != nullptr )
    {
      v7 = g_richPresenceDefault;
      v6->m_Index = -1;
      v6->m_MinPlayers = 0;
      v6->m_MaxPlayers = 0;
      v6->m_ExtraSpectators = 0;
      v6->m_RichPresence = v7;
      v6->m_TModels.m_Memory.m_pMemory = nullptr;
      v6->m_TModels.m_Memory.m_nAllocationCount = 0;
      v6->m_TModels.m_Memory.m_nGrowSize = 0;
      v6->m_TModels.m_Size = 0;
      v6->m_TModels.m_pElements = nullptr;
      v6->m_CTModels.m_Memory.m_pMemory = nullptr;
      v6->m_CTModels.m_Memory.m_nAllocationCount = 0;
      v6->m_CTModels.m_Memory.m_nGrowSize = 0;
      v6->m_CTModels.m_Size = 0;
      v6->m_CTModels.m_pElements = nullptr;
      v8 = v6;
      v6->m_Name[0] = 0;
      v6->m_NameID[0] = 0;
      pMap = v6;
    }
    else
    {
      pMap = nullptr;
      v8 = nullptr;
    }
    Name = (char *)KeyValues::GetName(this: FirstTrueSubKey);
    V_strncpy(pDest: v8->m_Name, pSrc: Name, maxLen: 32);
    String = KeyValues::GetString(this: FirstTrueSubKey, keyName: "nameID", defaultValue: prType);
    if ( String != nullptr )
    {
      V_strncpy(pDest: v8->m_NameID, pSrc: String, maxLen: 32);
    }
    else
    {
      v11 = KeyValues::GetName(this: FirstTrueSubKey);
      _Warning(a1: "GameTypes: missing %s entry for map %s.\n", "nameID", v11);
    }
    Int = KeyValues::GetInt(this: FirstTrueSubKey, keyName: "minplayers", defaultValue: -1);
    v8->m_MinPlayers = Int;
    if ( Int == -1 )
    {
      v35 = KeyValues::GetName(this: FirstTrueSubKey);
      _Warning(a1: "GameTypes: missing %s entry for map %s.\n", "minplayers", v35);
    }
    else
    {
      if ( Int >= 0 )
        goto LABEL_19;
      v36 = KeyValues::GetName(this: FirstTrueSubKey);
      _Warning(a1: "GameTypes: invalid %s entry for map %s.\n", "minplayers", v36);
    }
    v8->m_MinPlayers = 0;
LABEL_19:
    v13 = KeyValues::GetInt(this: FirstTrueSubKey, keyName: "maxplayers", defaultValue: -1);
    v8->m_MaxPlayers = v13;
    if ( v13 == -1 )
    {
      v37 = KeyValues::GetName(this: FirstTrueSubKey);
      _Warning(a1: "GameTypes: missing %s entry for map %s.\n", "maxplayers", v37);
    }
    else
    {
      if ( v13 >= 0 )
        goto LABEL_24;
      v38 = KeyValues::GetName(this: FirstTrueSubKey);
      _Warning(a1: "GameTypes: invalid %s entry for map %s.\n", "maxplayers", v38);
    }
    v8->m_MaxPlayers = 0;
LABEL_24:
    v14 = KeyValues::GetInt(this: FirstTrueSubKey, keyName: "extraspectators", defaultValue: 0);
    v39 = g_richPresenceDefault;
    v8->m_ExtraSpectators = v14;
    v8->m_RichPresence = KeyValues::GetInt(this: FirstTrueSubKey, keyName: "richpresencecontext", defaultValue: v39);
    v15 = KeyValues::FindKey(this: FirstTrueSubKey, keyName: "t_models", bCreate: false);
    if ( v15 != nullptr )
    {
      for ( i = KeyValues::GetFirstValue(this: v15); i != nullptr; i = KeyValues::GetNextValue(this: i) )
      {
        v17 = KeyValues::GetName(this: i);
        CUtlStringList::CopyAndAddToTail(this: &v8->m_TModels, pString: v17);
      }
    }
    else
    {
      v21 = KeyValues::GetName(this: FirstTrueSubKey);
      _Warning(a1: "GameTypes: missing %s entry for map %s.\n", "t_models", v21);
    }
    v18 = KeyValues::FindKey(this: FirstTrueSubKey, keyName: "ct_models", bCreate: false);
    if ( v18 != nullptr )
    {
      FirstValue = KeyValues::GetFirstValue(this: v18);
      pKV_Model = FirstValue;
      if ( FirstValue != nullptr )
      {
        p_m_CTModels = (CUtlMemory<vgui::TreeNode *,int> *)&v8->m_CTModels;
        while ( 1 )
        {
          v22 = KeyValues::GetName(this: FirstValue);
          v40 = (char *)MemAlloc_Alloc(nSize: strlen(v22) + 1);
          _V_strcpy(dest: v40, src: v22);
          m_pMemory = p_m_CTModels[1].m_pMemory;
          m_nAllocationCount = p_m_CTModels->m_nAllocationCount;
          if ( (int)m_pMemory + 1 > m_nAllocationCount )
            CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_CTModels, num: (int)m_pMemory - m_nAllocationCount + 1);
          ++p_m_CTModels[1].m_pMemory;
          v25 = p_m_CTModels->m_pMemory;
          v26 = (char *)p_m_CTModels[1].m_pMemory - (char *)m_pMemory - 1;
          p_m_CTModels[1].m_nAllocationCount = (int)p_m_CTModels->m_pMemory;
          if ( v26 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&v25[(_DWORD)m_pMemory + 1],
              src: (unsigned __int8 *)&v25[(_DWORD)m_pMemory],
              count: 4 * v26);
          v27 = (char **)&p_m_CTModels->m_pMemory[(_DWORD)m_pMemory];
          if ( v27 != nullptr )
            *v27 = v40;
          pKV_Model = KeyValues::GetNextValue(this: pKV_Model);
          if ( pKV_Model == nullptr )
            break;
          FirstValue = pKV_Model;
        }
        v8 = pMap;
      }
    }
    else
    {
      v28 = KeyValues::GetName(this: FirstTrueSubKey);
      _Warning(a1: "GameTypes: missing %s entry for map %s.\n", "ct_models", v28);
    }
    v8->m_Index = this->m_Maps.m_Size;
    m_Size = this->m_Maps.m_Size;
    p_m_Maps = &this->m_Maps;
    v31 = this->m_Maps.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > v31 )
      CUtlMemory<CChoreoActor *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Maps, num: m_Size - v31 + 1);
    ++this->m_Maps.m_Size;
    v32 = p_m_Maps->m_Memory.m_pMemory;
    v33 = this->m_Maps.m_Size - m_Size - 1;
    this->m_Maps.m_pElements = this->m_Maps.m_Memory.m_pMemory;
    if ( v33 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v32[m_Size + 1], src: (unsigned __int8 *)&v32[m_Size], count: 4 * v33);
    v34 = &p_m_Maps->m_Memory.m_pMemory[m_Size];
    if ( v34 != nullptr )
      *v34 = pMap;
    FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
  }
  while ( FirstTrueSubKey != nullptr );
  v2 = this;
LABEL_49:
  if ( v2->m_Maps.m_Size == 0 )
    _Warning(a1: "GamesTypes: empty %s entry.\n", "maps");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101CE050
// Name: private: bool GameTypes::LoadGameTypes(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameTypes::LoadGameTypes(GameTypes *this, KeyValues *pKV)
{
  KeyValues *Key; // eax
  KeyValues *FirstTrueSubKey; // edi
  GameTypes::GameType *v5; // eax
  GameTypes::GameType *v6; // esi
  char *Name; // eax
  char *String; // eax
  const char *v9; // eax
  KeyValues *v10; // eax
  KeyValues *NextTrueSubKey; // ebx
  GameTypes::GameMode *v12; // eax
  GameTypes::GameMode *v13; // esi
  char *v14; // eax
  char *v15; // eax
  void (*v16)(const char *, ...); // esi
  const char *v17; // eax
  char *v18; // eax
  const char *v19; // eax
  KeyValues *v20; // eax
  const char *v21; // eax
  KeyValues *v22; // eax
  KeyValues *v23; // eax
  KeyValues *FirstValue; // edi
  const char *v25; // eax
  const char *v26; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v30; // eax
  char **v31; // edi
  const char *v32; // eax
  const char *v33; // eax
  KeyValues *v34; // esi
  const char *v35; // eax
  const char *v36; // eax
  KeyValues *v37; // eax
  const char *v38; // eax
  bool v39; // zf
  int v40; // eax
  KeyValues *v41; // eax
  int v42; // esi
  const char *v43; // eax
  int v44; // edi
  int v45; // eax
  GameTypes::GameMode **v46; // ecx
  int v47; // eax
  GameTypes::GameMode **v48; // edi
  const char *v49; // eax
  int v50; // ebx
  int v51; // eax
  GameTypes::GameType **v52; // ecx
  int v53; // eax
  GameTypes::GameType **v54; // eax
  const char *v55; // eax
  const char *v56; // [esp-8h] [ebp-28h]
  const char *v57; // [esp-8h] [ebp-28h]
  const char *v58; // [esp-8h] [ebp-28h]
  const char *v59; // [esp-8h] [ebp-28h]
  const char *v60; // [esp-8h] [ebp-28h]
  const char *v61; // [esp-8h] [ebp-28h]
  const char *v62; // [esp-8h] [ebp-28h]
  const char *s2; // [esp+8h] [ebp-18h]
  const char *s2a; // [esp+8h] [ebp-18h]
  char *pKV_WeaponProgressionT; // [esp+Ch] [ebp-14h]
  KeyValues *pKV_WeaponProgressionTc; // [esp+Ch] [ebp-14h]
  KeyValues *pKV_WeaponProgressionTa; // [esp+Ch] [ebp-14h]
  KeyValues *pKV_WeaponProgressionTb; // [esp+Ch] [ebp-14h]
  GameTypes::GameType *pGameType; // [esp+14h] [ebp-Ch]
  KeyValues *pKV_Map; // [esp+18h] [ebp-8h]
  KeyValues *pKV_Mapa; // [esp+18h] [ebp-8h]
  KeyValues *pKV_GameType; // [esp+1Ch] [ebp-4h]
  GameTypes::GameMode *pGameMode; // [esp+28h] [ebp+8h]

  if ( pKV == nullptr )
    return 0;
  if ( this->m_GameTypes.m_Size > 0 )
    CUtlVector<GameTypes::GameType *,CUtlMemory<GameTypes::GameType *,int>>::PurgeAndDeleteElements(this: &this->m_GameTypes);
  Key = KeyValues::FindKey(this: pKV, keyName: "gameTypes", bCreate: false);
  if ( Key == nullptr )
  {
    _Warning(a1: "GameTypes: could not find entry %s.\n", "gameTypes");
    return 0;
  }
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: Key);
  pKV_GameType = FirstTrueSubKey;
  if ( FirstTrueSubKey != nullptr )
  {
    while ( 1 )
    {
      v5 = (GameTypes::GameType *)MemAlloc_Alloc(nSize: 0x58u);
      if ( v5 != nullptr )
      {
        v5->m_Index = -1;
        v5->m_GameModes.m_Memory.m_pMemory = nullptr;
        v5->m_GameModes.m_Memory.m_nAllocationCount = 0;
        v5->m_GameModes.m_Memory.m_nGrowSize = 0;
        v5->m_GameModes.m_Size = 0;
        v5->m_GameModes.m_pElements = nullptr;
        v6 = v5;
        v5->m_Name[0] = 0;
        v5->m_NameID[0] = 0;
        pGameType = v5;
      }
      else
      {
        pGameType = nullptr;
        v6 = nullptr;
      }
      Name = (char *)KeyValues::GetName(this: FirstTrueSubKey);
      V_strncpy(pDest: v6->m_Name, pSrc: Name, maxLen: 32);
      String = KeyValues::GetString(this: FirstTrueSubKey, keyName: "nameID", defaultValue: prType);
      if ( String != nullptr )
      {
        V_strncpy(pDest: v6->m_NameID, pSrc: String, maxLen: 32);
      }
      else
      {
        v9 = KeyValues::GetName(this: FirstTrueSubKey);
        _Warning(a1: "GameTypes: missing %s entry for game type %s.\n", "nameID", v9);
      }
      v10 = KeyValues::FindKey(this: FirstTrueSubKey, keyName: "gameModes", bCreate: false);
      if ( v10 != nullptr )
      {
        NextTrueSubKey = KeyValues::GetFirstTrueSubKey(this: v10);
        if ( NextTrueSubKey != nullptr )
        {
          do
          {
            v12 = (GameTypes::GameMode *)MemAlloc_Alloc(nSize: 0xB0u);
            if ( v12 != nullptr )
            {
              v13 = GameTypes::GameMode::GameMode(this: v12);
              pGameMode = v13;
            }
            else
            {
              pGameMode = nullptr;
              v13 = nullptr;
            }
            v14 = (char *)KeyValues::GetName(this: NextTrueSubKey);
            V_strncpy(pDest: v13->m_Name, pSrc: v14, maxLen: 32);
            v15 = KeyValues::GetString(this: NextTrueSubKey, keyName: "nameID", defaultValue: prType);
            if ( v15 != nullptr )
            {
              V_strncpy(pDest: v13->m_NameID, pSrc: v15, maxLen: 32);
              v16 = (void (*)(const char *, ...))_Warning;
            }
            else
            {
              v56 = KeyValues::GetName(this: NextTrueSubKey);
              v17 = KeyValues::GetName(this: FirstTrueSubKey);
              v16 = (void (*)(const char *, ...))_Warning;
              _Warning(a1: "GameTypes: missing %s entry for game type/mode (%s/%s).\n", "nameID", v17, v56);
            }
            v18 = KeyValues::GetString(this: NextTrueSubKey, keyName: "descID", defaultValue: prType);
            if ( v18 != nullptr )
            {
              V_strncpy(pDest: pGameMode->m_DescID, pSrc: v18, maxLen: 32);
            }
            else
            {
              v57 = KeyValues::GetName(this: NextTrueSubKey);
              v19 = KeyValues::GetName(this: FirstTrueSubKey);
              v16(a1: "GameTypes: missing %s entry for game type/mode (%s/%s).\n", "descID", v19, v57);
            }
            v20 = KeyValues::FindKey(this: NextTrueSubKey, keyName: "convars", bCreate: false);
            if ( v20 != nullptr )
            {
              pGameMode->m_pConvarsSP = KeyValues::MakeCopy(this: v20);
            }
            else
            {
              v58 = KeyValues::GetName(this: NextTrueSubKey);
              v21 = KeyValues::GetName(this: FirstTrueSubKey);
              v16(a1: "GameTypes: missing entry %s for game type/mode (%s/%s).\n", "convars", v21, v58);
            }
            v22 = KeyValues::FindKey(this: NextTrueSubKey, keyName: "convars_mp", bCreate: false);
            if ( v22 != nullptr )
              pGameMode->m_pConvarsMP = KeyValues::MakeCopy(this: v22);
            v23 = KeyValues::FindKey(this: NextTrueSubKey, keyName: "maps", bCreate: false);
            if ( v23 != nullptr )
            {
              FirstValue = KeyValues::GetFirstValue(this: v23);
              pKV_Map = FirstValue;
              if ( FirstValue != nullptr )
              {
                while ( 1 )
                {
                  v25 = KeyValues::GetName(this: FirstValue);
                  if ( _V_stricmp(s1: v25, s2: "random") != 0 )
                  {
                    v26 = KeyValues::GetName(this: FirstValue);
                    pKV_WeaponProgressionT = (char *)MemAlloc_Alloc(nSize: strlen(v26) + 1);
                    _V_strcpy(dest: pKV_WeaponProgressionT, src: v26);
                    m_Size = pGameMode->m_Maps.m_Size;
                    m_nAllocationCount = pGameMode->m_Maps.m_Memory.m_nAllocationCount;
                    if ( m_Size + 1 > m_nAllocationCount )
                      CUtlMemory<CChoreoActor *,int>::Grow(
                        this: (CUtlMemory<vgui::TreeNode *,int> *)&pGameMode->m_Maps,
                        num: m_Size - m_nAllocationCount + 1);
                    ++pGameMode->m_Maps.m_Size;
                    m_pMemory = pGameMode->m_Maps.m_Memory.m_pMemory;
                    v30 = pGameMode->m_Maps.m_Size - m_Size - 1;
                    pGameMode->m_Maps.m_pElements = m_pMemory;
                    if ( v30 > 0 )
                      _V_memmove(
                        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
                        src: (unsigned __int8 *)&m_pMemory[m_Size],
                        count: 4 * v30);
                    v31 = &pGameMode->m_Maps.m_Memory.m_pMemory[m_Size];
                    if ( v31 != nullptr )
                      *v31 = pKV_WeaponProgressionT;
                    FirstValue = pKV_Map;
                  }
                  pKV_Map = KeyValues::GetNextValue(this: FirstValue);
                  if ( pKV_Map == nullptr )
                    break;
                  FirstValue = pKV_Map;
                }
              }
              if ( pGameMode->m_Maps.m_Size == 0 )
              {
                v59 = KeyValues::GetName(this: NextTrueSubKey);
                v32 = KeyValues::GetName(this: pKV_GameType);
                _Warning(a1: "GameTypes: empty %s entry for game type/mode (%s/%s).\n", "maps", v32, v59);
              }
            }
            else
            {
              v60 = KeyValues::GetName(this: NextTrueSubKey);
              v33 = KeyValues::GetName(this: FirstTrueSubKey);
              v16(a1: "GameTypes: missing %s entry for game type/mode (%s/%s).\n", "maps", v33, v60);
            }
            v34 = KeyValues::FindKey(this: NextTrueSubKey, keyName: "weaponprogression_ct", bCreate: false);
            v61 = KeyValues::GetName(this: NextTrueSubKey);
            v35 = KeyValues::GetName(this: pKV_GameType);
            GameTypes::LoadWeaponProgression(
              this,
              pKV_WeaponProgression: v34,
              vecWeaponProgression: &pGameMode->m_WeaponProgressionCT,
              szGameType: v35,
              szGameMode: v61);
            pKV_WeaponProgressionTc = KeyValues::FindKey(
                                        this: NextTrueSubKey,
                                        keyName: "weaponprogression_t",
                                        bCreate: false);
            v62 = KeyValues::GetName(this: NextTrueSubKey);
            v36 = KeyValues::GetName(this: pKV_GameType);
            GameTypes::LoadWeaponProgression(
              this,
              pKV_WeaponProgression: pKV_WeaponProgressionTc,
              vecWeaponProgression: &pGameMode->m_WeaponProgressionT,
              szGameType: v36,
              szGameMode: v62);
            v37 = KeyValues::FindKey(this: NextTrueSubKey, keyName: "no_reset_vote_threshold_t", bCreate: false);
            if ( v37 != nullptr )
            {
              s2 = KeyValues::GetString(this: v37, keyName: nullptr, defaultValue: prType);
              pKV_WeaponProgressionTa = nullptr;
              if ( pGameMode->m_WeaponProgressionT.m_Size <= 0 )
              {
LABEL_53:
                v40 = -1;
              }
              else
              {
                pKV_Mapa = nullptr;
                while ( 1 )
                {
                  v38 = CUtlString::operator char const *(this: (CUtlString *)((char *)pKV_Mapa
                                                                             + (unsigned int)pGameMode->m_WeaponProgressionT.m_Memory.m_pMemory));
                  v39 = _V_strcmp(s1: v38, s2) == 0;
                  v40 = (int)pKV_WeaponProgressionTa;
                  if ( v39 )
                    break;
                  pKV_Mapa = (KeyValues *)((char *)pKV_Mapa + 20);
                  pKV_WeaponProgressionTa = (KeyValues *)((char *)pKV_WeaponProgressionTa + 1);
                  if ( (int)pKV_WeaponProgressionTa >= pGameMode->m_WeaponProgressionT.m_Size )
                    goto LABEL_53;
                }
              }
              pGameMode->m_NoResetVoteThresholdT = v40;
            }
            v41 = KeyValues::FindKey(this: NextTrueSubKey, keyName: "no_reset_vote_threshold_ct", bCreate: false);
            v42 = 0;
            if ( v41 != nullptr )
            {
              s2a = KeyValues::GetString(this: v41, keyName: nullptr, defaultValue: prType);
              if ( pGameMode->m_WeaponProgressionCT.m_Size <= 0 )
              {
LABEL_60:
                v42 = -1;
              }
              else
              {
                pKV_WeaponProgressionTb = nullptr;
                while ( 1 )
                {
                  v43 = CUtlString::operator char const *(this: (CUtlString *)((char *)pKV_WeaponProgressionTb
                                                                             + (unsigned int)pGameMode->m_WeaponProgressionCT.m_Memory.m_pMemory));
                  if ( _V_strcmp(s1: v43, s2: s2a) == 0 )
                    break;
                  pKV_WeaponProgressionTb = (KeyValues *)((char *)pKV_WeaponProgressionTb + 20);
                  if ( ++v42 >= pGameMode->m_WeaponProgressionCT.m_Size )
                    goto LABEL_60;
                }
              }
              pGameMode->m_NoResetVoteThresholdCT = v42;
            }
            pGameMode->m_Index = pGameType->m_GameModes.m_Size;
            v44 = pGameType->m_GameModes.m_Size;
            v45 = pGameType->m_GameModes.m_Memory.m_nAllocationCount;
            if ( v44 + 1 > v45 )
              CUtlMemory<CChoreoActor *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)&pGameType->m_GameModes,
                num: v44 - v45 + 1);
            ++pGameType->m_GameModes.m_Size;
            v46 = pGameType->m_GameModes.m_Memory.m_pMemory;
            v47 = pGameType->m_GameModes.m_Size - v44 - 1;
            pGameType->m_GameModes.m_pElements = v46;
            if ( v47 > 0 )
              _V_memmove(dest: (unsigned __int8 *)&v46[v44 + 1], src: (unsigned __int8 *)&v46[v44], count: 4 * v47);
            v48 = &pGameType->m_GameModes.m_Memory.m_pMemory[v44];
            if ( v48 != nullptr )
              *v48 = pGameMode;
            FirstTrueSubKey = pKV_GameType;
            NextTrueSubKey = KeyValues::GetNextTrueSubKey(this: NextTrueSubKey);
          }
          while ( NextTrueSubKey != nullptr );
          v6 = pGameType;
        }
      }
      else
      {
        v55 = KeyValues::GetName(this: FirstTrueSubKey);
        _Warning(a1: "GameTypes: missing %s entry for game type %s.\n", "gameModes", v55);
      }
      if ( v6->m_GameModes.m_Size == 0 )
      {
        v49 = KeyValues::GetName(this: FirstTrueSubKey);
        _Warning(a1: "GameTypes: empty %s entry for game type %s.\n", "gameModes", v49);
      }
      v6->m_Index = this->m_GameTypes.m_Size;
      v50 = this->m_GameTypes.m_Size;
      v51 = this->m_GameTypes.m_Memory.m_nAllocationCount;
      if ( v50 + 1 > v51 )
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_GameTypes,
          num: v50 - v51 + 1);
      ++this->m_GameTypes.m_Size;
      v52 = this->m_GameTypes.m_Memory.m_pMemory;
      v53 = this->m_GameTypes.m_Size - v50 - 1;
      this->m_GameTypes.m_pElements = v52;
      if ( v53 > 0 )
        _V_memmove(dest: (unsigned __int8 *)&v52[v50 + 1], src: (unsigned __int8 *)&v52[v50], count: 4 * v53);
      v54 = &this->m_GameTypes.m_Memory.m_pMemory[v50];
      if ( v54 != nullptr )
        *v54 = v6;
      pKV_GameType = KeyValues::GetNextTrueSubKey(this: pKV_GameType);
      if ( pKV_GameType == nullptr )
        break;
      FirstTrueSubKey = pKV_GameType;
    }
  }
  if ( this->m_GameTypes.m_Size == 0 )
    _Warning(a1: "GameTypes: empty %s entry.\n", "gameTypes");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101CE6B0
// Name: public: virtual bool GameTypes::Initialize(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameTypes::Initialize(GameTypes *this, bool force)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IBaseFileSystem *v6; // eax

  if ( this->m_Initialized && !force )
    return 1;
  DevMsg(a1: "GameTypes: initializing game types interface from %s.\n", "GameModes.txt");
  CUtlVector<GameTypes::GameType *,CUtlMemory<GameTypes::GameType *,int>>::PurgeAndDeleteElements(this: &this->m_GameTypes);
  CUtlVector<GameTypes::Map *,CUtlMemory<GameTypes::Map *,int>>::PurgeAndDeleteElements(this: &this->m_Maps);
  CUtlVector<GameTypes::FreestyleBotDifficulty *,CUtlMemory<GameTypes::FreestyleBotDifficulty *,int>>::PurgeAndDeleteElements(this: &this->m_FreestyleBotDifficulties);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: prType);
  else
    v5 = nullptr;
  if ( g_pFullFileSystem != nullptr )
    v6 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v6 = nullptr;
  if ( !KeyValues::LoadFromFile(
          this: v5,
          filesystem: v6,
          resourceName: "GameModes.txt",
          pathID: nullptr,
          pfnEvaluateSymbolProc: nullptr) )
  {
    _Warning(a1: "GameTypes: error loading %s.", "GameModes.txt");
    goto LABEL_12;
  }
  DLCHelper::AppendDLCKeyValues(pKeyValues: v5, fileName: "GameModes.txt", startDir: nullptr);
  if ( GameTypes::LoadGameTypes(this, pKV: v5) == 0
    || GameTypes::LoadMaps(this, pKV: v5) == 0
    || GameTypes::LoadFreestyleBotDifficulties(this, pKV: v5) == 0 )
  {
LABEL_12:
    if ( v5 != nullptr )
      KeyValues::deleteThis(this: v5);
    return 0;
  }
  this->m_Initialized = true;
  if ( v5 != nullptr )
    KeyValues::deleteThis(this: v5);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101CC3A0
// Name: __CreateGameTypesIGameTypes_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
GameTypes *__cdecl _CreateGameTypesIGameTypes_interface()
{
  return &s_GameTypes;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x102A1010
// Name: public: static unsigned __int64 DLCHelper::GetInstalledDLCMask(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DLCHelper::GetInstalledDLCMask()
{
  int (__thiscall *IsAnyDLCPresent)(IFileSystem *, bool *); // eax
  int v1; // edi
  int v2; // esi
  __int64 v3; // kr00_8
  __int64 uiDlcHeader; // [esp+Ch] [ebp-Ch] BYREF
  bool bSearchPath; // [esp+17h] [ebp-1h] BYREF

  bSearchPath = false;
  IsAnyDLCPresent = g_pFullFileSystem->IsAnyDLCPresent;
  uiDlcHeader = 0;
  v1 = IsAnyDLCPresent(this: g_pFullFileSystem, a2: &bSearchPath);
  if ( !bSearchPath )
    g_pFullFileSystem->AddDLCSearchPaths(this: g_pFullFileSystem);
  v2 = 0;
  if ( v1 <= 0 )
    return uiDlcHeader;
  v3 = uiDlcHeader;
  do
  {
    HIDWORD(uiDlcHeader) = 0;
    if ( g_pFullFileSystem->GetAnyDLCInfo(
           this: g_pFullFileSystem,
           a2: v2,
           a3: (unsigned int *)((char *)&uiDlcHeader + 4),
           a4: nullptr,
           a5: 0)
      && (unsigned int)(HIBYTE(HIDWORD(uiDlcHeader)) - 1) <= 0x1D )
    {
      v3 |= 1LL << SHIBYTE(uiDlcHeader);
    }
    ++v2;
  }
  while ( v2 < v1 );
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x102A10C0
// Name: public: static void DLCHelper::AppendDLCKeyValues(class KeyValues __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DLCHelper::AppendDLCKeyValues(KeyValues *pKeyValues, const char *fileName, const char *startDir)
{
  unsigned __int64 v3; // rax
  KeyValues *v4; // eax
  KeyValues *v5; // ebx
  int v6; // eax
  int v7; // esi
  bool v8; // zf
  int v9; // edi
  IBaseFileSystem *v10; // eax
  unsigned int v11; // et0
  char dlcFileName[128]; // [esp+0h] [ebp-94h] BYREF
  unsigned __int64 i; // [esp+80h] [ebp-14h]
  const char *extension; // [esp+88h] [ebp-Ch]
  unsigned __int64 installedDlc; // [esp+8Ch] [ebp-8h]

  LODWORD(v3) = DLCHelper::GetInstalledDLCMask();
  installedDlc = v3;
  if ( v3 != 0 )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: locale);
    else
      v5 = nullptr;
    memset(dlcFileName, 0, sizeof(dlcFileName));
    v6 = _V_strlen(str: fileName);
    v7 = v6 - 1;
    v8 = v6 == 1;
    if ( v6 - 1 > 0 )
    {
      do
      {
        if ( fileName[v7] == 46 )
          break;
        --v7;
      }
      while ( v7 > 0 );
      v8 = v7 == 0;
    }
    if ( v8 )
    {
      _Warning(a1: "Invalid file name passed to DLCHelper::AppendDLCKeyValues (%s)\n", fileName);
    }
    else
    {
      extension = &fileName[v7 + 1];
      V_strncpy(pDest: dlcFileName, pSrc: fileName, maxLen: 128);
      v9 = 1;
      HIDWORD(i) = 0;
      do
      {
        if ( (installedDlc & (1LL << v9)) != 0 )
        {
          V_snprintf(pDest: &dlcFileName[v7], maxLen: 128 - v7, pFormat: "_dlc%d.%s", v9, extension);
          KeyValues::Clear(this: v5);
          if ( g_pFullFileSystem != nullptr )
            v10 = &g_pFullFileSystem->IBaseFileSystem;
          else
            v10 = nullptr;
          if ( KeyValues::LoadFromFile(
                 this: v5,
                 filesystem: v10,
                 resourceName: dlcFileName,
                 pathID: startDir,
                 pfnEvaluateSymbolProc: nullptr) )
          {
            KeyValues::MergeFrom(this: pKeyValues, kvMerge: v5, eOp: MERGE_KV_UPDATE);
          }
          else
          {
            _Warning(a1: "Failed to load %s\n", dlcFileName);
          }
        }
        v11 = (__PAIR64__(HIDWORD(i), v9++) + 1) >> 32;
        HIDWORD(i) = v11;
      }
      while ( __PAIR64__(v11, v9) < 0x40 );
      if ( v5 != nullptr )
        KeyValues::deleteThis(this: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A1240
// Name: public: virtual bool GameTypes::SetGameTypeAndMode(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameTypes::SetGameTypeAndMode(GameTypes *this, const char *gameType, char *gameMode)
{
  int iMode; // [esp+8h] [ebp-8h] BYREF
  int iType; // [esp+Ch] [ebp-4h] BYREF

  iType = -1;
  iMode = -1;
  if ( ((unsigned __int8 (__thiscall *)(GameTypes *))this->GetGameModeAndTypeIntsFromStrings)(a1: this) != 0 )
  {
    DevMsg(a1: "GameTypes: setting game type to %s:%d.\n", gameType, iType);
    CCollisionProperty::TestCollision(
      this: (ConVar *)&game_type.IConVar,
      value: iType,
      fContentsMask: (unsigned int)gameType,
      tr: (CGameTrace *)gameMode);
    DevMsg(a1: "GameTypes: setting game mode to %s:%d.\n", gameMode, iMode);
    CCollisionProperty::TestCollision(
      this: (ConVar *)&game_mode.IConVar,
      value: iMode,
      fContentsMask: (unsigned int)&iType,
      tr: (CGameTrace *)&iMode);
    return 1;
  }
  else
  {
    _Warning(
      a1: "GamesTypes: unable to set game type and mode. Could not find type/mode matching type:%s/mode:%s.\n",
      gameType,
      gameMode);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A12D0
// Name: public: virtual int GameTypes::GetCurrentGameType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GameTypes::GetCurrentGameType(GameTypes *this)
{
  if ( game_type.m_pParent != nullptr )
    return game_type.m_pParent->m_Value.m_nValue;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102A12E0
// Name: public: virtual int GameTypes::GetCurrentGameMode(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GameTypes::GetCurrentGameMode(GameTypes *this)
{
  if ( game_mode.m_pParent != nullptr )
    return game_mode.m_pParent->m_Value.m_nValue;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102A12F0
// Name: private: void GameTypes::DisplayConvars(class KeyValues __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GameTypes::DisplayConvars(GameTypes *this, KeyValues *pKV_Convars, const char *title)
{
  KeyValues *i; // esi
  const char *Name; // eax
  char *m_pszString; // edi
  const char *v6; // eax
  const char *String; // [esp-Ch] [ebp-18h]
  ConVarRef conVarRef; // [esp+4h] [ebp-8h] BYREF

  if ( pKV_Convars != nullptr && title != nullptr )
  {
    ConMsg(a1: "%s\n{\n", title);
    for ( i = KeyValues::GetFirstValue(this: pKV_Convars); i != nullptr; i = KeyValues::GetNextValue(this: i) )
    {
      Name = KeyValues::GetName(this: i);
      ConVarRef::ConVarRef(this: &conVarRef, pName: Name);
      m_pszString = conVarRef.m_pConVarState->m_Value.m_pszString;
      String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: locale);
      v6 = KeyValues::GetName(this: i);
      ConMsg(a1: "\t\"%s\": current value (\"%s\"), expected value (\"%s\")\n", v6, m_pszString, String);
    }
    ConMsg(a1: "}\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A1380
// Name: public: virtual int GameTypes::GetFreestyleBotDifficulty(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GameTypes::GetFreestyleBotDifficulty(GameTypes *this)
{
  if ( freestyle_bot_difficulty.m_pParent != nullptr )
    return freestyle_bot_difficulty.m_pParent->m_Value.m_nValue;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102A1390
// Name: void DisplayGameModeConvars(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisplayGameModeConvars()
{
  if ( g_pGameTypes != nullptr )
    g_pGameTypes->DisplayConvarsForCurrentMode(this: g_pGameTypes);
}

//------------------------------------------------------------------------------
// Address: 0x102A13B0
// Name: public: virtual bool GameTypes::SetFreestyleBotDifficulty(int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __thiscall GameTypes::SetFreestyleBotDifficulty(GameTypes *this, int botDiff)
{
  unsigned int v3; // [esp-8h] [ebp-Ch]
  CGameTrace *v4; // [esp-4h] [ebp-8h]

  if ( botDiff < 0 || botDiff >= this->m_FreestyleBotDifficulties.m_Size )
  {
    _Warning(
      a1: "GameTypes: invalid freestyle bot difficulty (%d). Range [%d,%d].\n",
      botDiff,
      0,
      this->m_FreestyleBotDifficulties.m_Size - 1);
    return 0;
  }
  else
  {
    DevMsg(a1: "GameTypes: setting freestyle_bot_difficulty to %d.\n", botDiff);
    CCollisionProperty::TestCollision(
      this: (ConVar *)&freestyle_bot_difficulty.IConVar,
      value: botDiff,
      fContentsMask: v3,
      tr: v4);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A1400
// Name: private: struct GameTypes::GameType __near * GameTypes::GetGameType_Internal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
GameTypes::GameType *__thiscall GameTypes::GetGameType_Internal(GameTypes *this, const char *gameType)
{
  const char *v2; // eax
  int v4; // edi
  GameTypes::GameType *v5; // esi

  v2 = gameType;
  if ( gameType != nullptr && *gameType != 0 && (v4 = 0, this->m_GameTypes.m_Size > 0) )
  {
    while ( 1 )
    {
      v5 = this->m_GameTypes.m_Memory.m_pMemory[v4];
      if ( v5 != nullptr && _V_stricmp(s1: v5->m_Name, s2: gameType) == 0 )
        return v5;
      if ( ++v4 >= this->m_GameTypes.m_Size )
      {
        v2 = gameType;
        goto LABEL_8;
      }
    }
  }
  else
  {
LABEL_8:
    _Warning(a1: "GameTypes: could not find matching game type \"%s\".\n", v2);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A1470
// Name: private: struct GameTypes::GameMode __near * GameTypes::GetGameMode_Internal(struct GameTypes::GameType __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
GameTypes::GameMode *__thiscall GameTypes::GetGameMode_Internal(
        GameTypes *this,
        GameTypes::GameType *pGameType,
        const char *gameMode)
{
  int v3; // edi
  GameTypes::GameMode *v4; // esi
  char *m_Name; // ebx

  if ( pGameType == nullptr )
  {
    m_Name = "null";
    goto LABEL_11;
  }
  if ( gameMode == nullptr || *gameMode == 0 || (v3 = 0, pGameType->m_GameModes.m_Size <= 0) )
  {
LABEL_8:
    m_Name = pGameType->m_Name;
LABEL_11:
    _Warning(a1: "GameTypes: could not find matching game mode \"%s\" for type \"%s\".\n", gameMode, m_Name);
    return nullptr;
  }
  while ( 1 )
  {
    v4 = pGameType->m_GameModes.m_Memory.m_pMemory[v3];
    if ( v4 != nullptr && _V_stricmp(s1: v4->m_Name, s2: gameMode) == 0 )
      return v4;
    if ( ++v3 >= pGameType->m_GameModes.m_Size )
      goto LABEL_8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A14F0
// Name: private: struct GameTypes::Map __near * GameTypes::GetMap_Internal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
GameTypes::Map *__thiscall GameTypes::GetMap_Internal(GameTypes *this, const char *mapName)
{
  int v4; // eax
  char *v5; // esi
  int v6; // eax
  char *v7; // esi
  int v8; // esi
  GameTypes::Map *v9; // edi
  char mapNameNoExt[36]; // [esp+4h] [ebp-24h] BYREF

  if ( this->m_Maps.m_Size != 0 )
  {
    if ( mapName != nullptr && *mapName != 0 )
    {
      V_strncpy(pDest: mapNameNoExt, pSrc: mapName, maxLen: 33);
      v4 = _V_strlen(str: mapNameNoExt);
      v5 = &mapNameNoExt[v4 - 4];
      if ( v5 >= mapNameNoExt && V_strnicmp(s1: &mapNameNoExt[v4 - 4], s2: ".360", n: 4) == 0 )
        *v5 = 0;
      v6 = _V_strlen(str: mapNameNoExt);
      v7 = &mapNameNoExt[v6 - 4];
      if ( v7 >= mapNameNoExt && V_strnicmp(s1: &mapNameNoExt[v6 - 4], s2: ".bsp", n: 4) == 0 )
        *v7 = 0;
      v8 = 0;
      if ( this->m_Maps.m_Size <= 0 )
      {
LABEL_15:
        _Warning(a1: "GameTypes: could not find matching map \"%s\".\n", mapNameNoExt);
        return nullptr;
      }
      else
      {
        while ( 1 )
        {
          v9 = this->m_Maps.m_Memory.m_pMemory[v8];
          if ( v9 != nullptr && _V_stricmp(s1: v9->m_Name, s2: mapNameNoExt) == 0 )
            return v9;
          if ( ++v8 >= this->m_Maps.m_Size )
            goto LABEL_15;
        }
      }
    }
    else
    {
      _Warning(a1: "GamesTypes: invalid map name.\n");
      return nullptr;
    }
  }
  else
  {
    _Warning(a1: "GamesTypes: no maps have been loaded.\n");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A1610
// Name: private: struct GameTypes::FreestyleBotDifficulty __near * GameTypes::GetCurrentFreestyleBotDifficulty_Internal(void)
// Source: json
//------------------------------------------------------------------------------
GameTypes::FreestyleBotDifficulty *__thiscall GameTypes::GetCurrentFreestyleBotDifficulty_Internal(GameTypes *this)
{
  int m_Size; // edx
  int m_nValue; // eax

  m_Size = this->m_FreestyleBotDifficulties.m_Size;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no freestyle bot difficulties have been loaded.\n");
    return nullptr;
  }
  if ( freestyle_bot_difficulty.m_pParent != nullptr )
  {
    m_nValue = freestyle_bot_difficulty.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
      goto LABEL_8;
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue < m_Size )
    return this->m_FreestyleBotDifficulties.m_Memory.m_pMemory[m_nValue];
LABEL_8:
  _Warning(
    a1: "GamesTypes: freestyle_bot_difficulty is set to an invalid value (%d). Range [%d,%d].\n",
    m_nValue,
    0,
    m_Size - 1);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102A1660
// Name: public: virtual char const __near * GameTypes::GetCurrentGameTypeNameID(void)
// Source: json
//------------------------------------------------------------------------------
GameTypes::GameType *__thiscall GameTypes::GetCurrentGameTypeNameID(GameTypes *this)
{
  int m_Size; // edx
  GameTypes::GameType *result; // eax
  int m_nValue; // eax

  m_Size = this->m_GameTypes.m_Size;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no game types have been loaded.\n");
    return nullptr;
  }
  if ( game_type.m_pParent != nullptr )
  {
    m_nValue = game_type.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
    {
LABEL_9:
      _Warning(a1: "GamesTypes: game_type is set to an invalid value (%d). Range [%d,%d].\n", m_nValue, 0, m_Size - 1);
      return nullptr;
    }
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue >= m_Size )
    goto LABEL_9;
  result = this->m_GameTypes.m_Memory.m_pMemory[m_nValue];
  if ( result != nullptr )
    return (GameTypes::GameType *)((char *)result + 36);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102A16C0
// Name: public: virtual char const __near * GameTypes::GetCurrentGameModeNameID(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall GameTypes::GetCurrentGameModeNameID(GameTypes *this)
{
  int m_Size; // edx
  int m_nValue; // eax
  GameTypes::GameType *v4; // ecx
  int v5; // eax
  GameTypes::GameMode *v6; // eax

  m_Size = this->m_GameTypes.m_Size;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no game types have been loaded.\n");
    return nullptr;
  }
  if ( game_type.m_pParent != nullptr )
  {
    m_nValue = game_type.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
    {
LABEL_9:
      _Warning(a1: "GamesTypes: game_type is set to an invalid value (%d). Range [%d,%d].\n", m_nValue, 0, m_Size - 1);
      return nullptr;
    }
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue >= m_Size )
    goto LABEL_9;
  v4 = this->m_GameTypes.m_Memory.m_pMemory[m_nValue];
  if ( v4 == nullptr )
    return nullptr;
  if ( game_mode.m_pParent != nullptr )
  {
    v5 = game_mode.m_pParent->m_Value.m_nValue;
    if ( v5 < 0 )
    {
LABEL_16:
      _Warning(
        a1: "GamesTypes: game_mode is set to an invalid value (%d). Range [%d,%d].\n",
        v5,
        0,
        v4->m_GameModes.m_Size - 1);
      return nullptr;
    }
  }
  else
  {
    v5 = 0;
  }
  if ( v5 >= v4->m_GameModes.m_Size )
    goto LABEL_16;
  v6 = v4->m_GameModes.m_Memory.m_pMemory[v5];
  if ( v6 == nullptr )
    return nullptr;
  return v6->m_NameID;
}

//------------------------------------------------------------------------------
// Address: 0x102A1760
// Name: public: virtual bool GameTypes::ApplyConvarsForCurrentMode(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameTypes::ApplyConvarsForCurrentMode(GameTypes *this, bool isMultiplayer)
{
  int m_Size; // ecx
  int m_nValue; // eax
  GameTypes::GameType *v6; // edx
  int v7; // eax
  GameTypes::GameMode *v8; // ebx
  KeyValues *m_pConvarsSP; // edi
  int v10; // ecx
  int v11; // eax
  KeyValues *i; // esi
  const char *Name; // eax
  const char *String; // eax
  int v15; // ecx
  int v16; // eax
  GameTypes *v17; // esi
  GameTypes::FreestyleBotDifficulty *CurrentFreestyleBotDifficulty_Internal; // eax
  GameTypes::FreestyleBotDifficulty *v19; // ebx
  KeyValues *m_pConvars; // edi
  KeyValues *j; // esi
  const char *v22; // eax
  const char *v23; // eax
  int v24; // eax
  int v25; // eax
  ConVarRef conVarRef; // [esp+4h] [ebp-18h] BYREF
  IKeyValuesDumpContext v27; // [esp+Ch] [ebp-10h] BYREF
  GameTypes *v28; // [esp+10h] [ebp-Ch]
  IKeyValuesDumpContext pDump; // [esp+14h] [ebp-8h] BYREF
  GameTypes::GameType *pGameType; // [esp+18h] [ebp-4h]

  m_Size = this->m_GameTypes.m_Size;
  v28 = this;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no game types have been loaded.\n");
    return 0;
  }
  if ( game_type.m_pParent != nullptr )
  {
    m_nValue = game_type.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
    {
LABEL_9:
      _Warning(a1: "GamesTypes: game_type is set to an invalid value (%d). Range [%d,%d].\n", m_nValue, 0, m_Size - 1);
      return 0;
    }
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue >= m_Size )
    goto LABEL_9;
  v6 = this->m_GameTypes.m_Memory.m_pMemory[m_nValue];
  pGameType = v6;
  if ( v6 == nullptr )
    return 0;
  if ( game_mode.m_pParent != nullptr )
  {
    v7 = game_mode.m_pParent->m_Value.m_nValue;
    if ( v7 < 0 )
    {
LABEL_20:
      _Warning(
        a1: "GamesTypes: game_mode is set to an invalid value (%d). Range [%d,%d].\n",
        v7,
        0,
        v6->m_GameModes.m_Size - 1);
      return 0;
    }
  }
  else
  {
    v7 = 0;
  }
  if ( v7 >= v6->m_GameModes.m_Size )
    goto LABEL_20;
  v8 = v6->m_GameModes.m_Memory.m_pMemory[v7];
  if ( v8 == nullptr )
    return 0;
  if ( !isMultiplayer || (m_pConvarsSP = v8->m_pConvarsMP) == nullptr )
  {
    m_pConvarsSP = v8->m_pConvarsSP;
    if ( m_pConvarsSP == nullptr )
    {
      if ( game_mode.m_pParent != nullptr )
        v10 = game_mode.m_pParent->m_Value.m_nValue;
      else
        v10 = 0;
      if ( game_type.m_pParent != nullptr )
        v11 = game_type.m_pParent->m_Value.m_nValue;
      else
        v11 = 0;
      _Warning(
        a1: "GamesTypes: unable to set convars. There are no convars for game type/mode (%s:%d/%s:%d).\n",
        v6->m_Name,
        v11,
        v8->m_Name,
        v10);
      return 0;
    }
  }
  for ( i = KeyValues::GetFirstValue(this: m_pConvarsSP); i != nullptr; i = KeyValues::GetNextValue(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    ConVarRef::ConVarRef(this: &conVarRef, pName: Name);
    String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: locale);
    conVarRef.m_pConVar->SetValue_4(this: conVarRef.m_pConVar, a2: String);
  }
  if ( game_mode.m_pParent != nullptr )
    v15 = game_mode.m_pParent->m_Value.m_nValue;
  else
    v15 = 0;
  if ( game_type.m_pParent != nullptr )
    v16 = game_type.m_pParent->m_Value.m_nValue;
  else
    v16 = 0;
  DevMsg(a1: "GameTypes: set convars for game type/mode (%s:%d/%s:%d):\n", pGameType->m_Name, v16, v8->m_Name, v15);
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  pGameType = (GameTypes::GameType *)1;
  KeyValues::Dump(this: m_pConvarsSP, &pDump, nIndentLevel: 1);
  v17 = v28;
  if ( v28->GetCurrentGameMode(this: v28) != 2 )
    return 1;
  if ( v17->GetCurrentGameType(this: v17) != 0 )
    return 1;
  CurrentFreestyleBotDifficulty_Internal = GameTypes::GetCurrentFreestyleBotDifficulty_Internal(this: v17);
  v19 = CurrentFreestyleBotDifficulty_Internal;
  if ( CurrentFreestyleBotDifficulty_Internal == nullptr )
    return 1;
  m_pConvars = CurrentFreestyleBotDifficulty_Internal->m_pConvars;
  if ( m_pConvars == nullptr )
  {
    if ( freestyle_bot_difficulty.m_pParent != nullptr )
      v25 = freestyle_bot_difficulty.m_pParent->m_Value.m_nValue;
    else
      v25 = 0;
    _Warning(
      a1: "GamesTypes: unable to set freestyle bot difficulty convars. There are no convars for bot difficulty (%s:%d).\n",
      v19->m_Name,
      v25);
    return 1;
  }
  for ( j = KeyValues::GetFirstValue(this: CurrentFreestyleBotDifficulty_Internal->m_pConvars);
        j != nullptr;
        j = KeyValues::GetNextValue(this: j) )
  {
    v22 = KeyValues::GetName(this: j);
    ConVarRef::ConVarRef(this: &conVarRef, pName: v22);
    v23 = KeyValues::GetString(this: j, keyName: nullptr, defaultValue: locale);
    conVarRef.m_pConVar->SetValue_4(this: conVarRef.m_pConVar, a2: v23);
  }
  if ( freestyle_bot_difficulty.m_pParent != nullptr )
    v24 = freestyle_bot_difficulty.m_pParent->m_Value.m_nValue;
  else
    v24 = 0;
  DevMsg(a1: "GameTypes: set convars for freestyle bot difficulty (%s:%d):\n", v19->m_Name, v24);
  v27.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  v28 = (GameTypes *)1;
  KeyValues::Dump(this: m_pConvars, pDump: &v27, nIndentLevel: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102A1A00
// Name: public: virtual void GameTypes::DisplayConvarsForCurrentMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GameTypes::DisplayConvarsForCurrentMode(GameTypes *this)
{
  GameTypes *v1; // edx
  int m_Size; // esi
  int m_nValue; // eax
  GameTypes::GameType *v4; // ebx
  ConVar *m_pParent; // ecx
  int v6; // eax
  GameTypes::GameMode *v7; // esi
  KeyValues *m_pConvarsSP; // edi
  int v9; // ecx
  int v10; // eax
  KeyValues *m_pConvarsMP; // edi
  int v12; // ecx
  int v13; // eax
  GameTypes *v14; // edi
  GameTypes::FreestyleBotDifficulty *CurrentFreestyleBotDifficulty_Internal; // eax
  KeyValues *m_pConvars; // esi
  int v17; // ecx
  char title[256]; // [esp+4h] [ebp-104h] BYREF
  GameTypes *v19; // [esp+104h] [ebp-4h]

  v1 = this;
  m_Size = this->m_GameTypes.m_Size;
  v19 = this;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no game types have been loaded.\n");
    return;
  }
  if ( game_type.m_pParent != nullptr )
  {
    m_nValue = game_type.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
    {
LABEL_15:
      _Warning(a1: "GamesTypes: game_type is set to an invalid value (%d). Range [%d,%d].\n", m_nValue, 0, m_Size - 1);
      return;
    }
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue >= m_Size )
    goto LABEL_15;
  v4 = this->m_GameTypes.m_Memory.m_pMemory[m_nValue];
  if ( v4 == nullptr )
    return;
  m_pParent = game_mode.m_pParent;
  if ( game_mode.m_pParent != nullptr )
  {
    v6 = game_mode.m_pParent->m_Value.m_nValue;
    if ( v6 < 0 )
    {
LABEL_17:
      _Warning(
        a1: "GamesTypes: game_mode is set to an invalid value (%d). Range [%d,%d].\n",
        v6,
        0,
        v4->m_GameModes.m_Size - 1);
      return;
    }
  }
  else
  {
    v6 = 0;
  }
  if ( v6 >= v4->m_GameModes.m_Size )
    goto LABEL_17;
  v7 = v4->m_GameModes.m_Memory.m_pMemory[v6];
  if ( v7 != nullptr )
  {
    m_pConvarsSP = v7->m_pConvarsSP;
    if ( m_pConvarsSP != nullptr )
    {
      if ( game_mode.m_pParent != nullptr )
        v9 = game_mode.m_pParent->m_Value.m_nValue;
      else
        v9 = 0;
      if ( game_type.m_pParent != nullptr )
        v10 = game_type.m_pParent->m_Value.m_nValue;
      else
        v10 = 0;
      V_snprintf(
        pDest: title,
        maxLen: 256,
        pFormat: "GameTypes: dumping convars for game type/mode (%s:%d/%s:%d):",
        v4->m_Name,
        v10,
        v7->m_Name,
        v9);
      GameTypes::DisplayConvars(this: v19, pKV_Convars: m_pConvarsSP, title);
      m_pParent = game_mode.m_pParent;
      v1 = v19;
    }
    m_pConvarsMP = v7->m_pConvarsMP;
    if ( m_pConvarsMP != nullptr )
    {
      if ( m_pParent != nullptr )
        v12 = m_pParent->m_Value.m_nValue;
      else
        v12 = 0;
      if ( game_type.m_pParent != nullptr )
        v13 = game_type.m_pParent->m_Value.m_nValue;
      else
        v13 = 0;
      V_snprintf(
        pDest: title,
        maxLen: 256,
        pFormat: "GameTypes: dumping multiplayer convars for game type/mode (%s:%d/%s:%d):",
        v4->m_Name,
        v13,
        v7->m_Name,
        v12);
      GameTypes::DisplayConvars(this: v19, pKV_Convars: m_pConvarsMP, title);
      v1 = v19;
    }
    if ( v1->GetCurrentGameMode(this: v1) == 2 )
    {
      v14 = v19;
      if ( v19->GetCurrentGameType(this: v19) == 0 )
      {
        CurrentFreestyleBotDifficulty_Internal = GameTypes::GetCurrentFreestyleBotDifficulty_Internal(this: v14);
        if ( CurrentFreestyleBotDifficulty_Internal != nullptr )
        {
          m_pConvars = CurrentFreestyleBotDifficulty_Internal->m_pConvars;
          if ( m_pConvars != nullptr )
          {
            if ( freestyle_bot_difficulty.m_pParent != nullptr )
              v17 = freestyle_bot_difficulty.m_pParent->m_Value.m_nValue;
            else
              v17 = 0;
            V_snprintf(
              pDest: title,
              maxLen: 256,
              pFormat: "GameTypes: dumping convars for freestyle bot difficulty (%s:%d):",
              CurrentFreestyleBotDifficulty_Internal->m_Name,
              v17);
            GameTypes::DisplayConvars(this: v14, pKV_Convars: m_pConvars, title);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A1D20
// Name: public: virtual char const __near * GameTypes::GetRandomMap(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char *__thiscall GameTypes::GetRandomMap(GameTypes *this, const char *gameType, const char *gameMode)
{
  GameTypes::GameType *GameType_Internal; // eax
  GameTypes::GameMode *GameMode_Internal; // eax
  IUniformRandomStream *v6; // ecx
  GameTypes::GameMode *v7; // esi
  int m_Size; // eax

  if ( gameType != nullptr
    && gameMode != nullptr
    && (GameType_Internal = GameTypes::GetGameType_Internal(this, gameType)) != nullptr
    && (GameMode_Internal = GameTypes::GetGameMode_Internal(this, pGameType: GameType_Internal, gameMode),
        v7 = GameMode_Internal,
        GameMode_Internal != nullptr)
    && (m_Size = GameMode_Internal->m_Maps.m_Size) != 0 )
  {
    return v7->m_Maps.m_Memory.m_pMemory[_RandomInt(this: v6, a2: 0, a3: m_Size - 1)];
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A1D80
// Name: public: virtual bool GameTypes::ApplyConvarsForMap(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameTypes::ApplyConvarsForMap(GameTypes *this, const char *mapName)
{
  GameTypes::Map *Map_Internal; // edi
  GameTypes::FreestyleBotDifficulty *CurrentFreestyleBotDifficulty_Internal; // eax
  ConVarRef bot_quota; // [esp+Ch] [ebp-8h] BYREF

  Map_Internal = GameTypes::GetMap_Internal(this, mapName);
  if ( Map_Internal != nullptr )
  {
    if ( this->GetCurrentGameMode(this) != 2
      || this->GetCurrentGameType(this) != 0
      || (CurrentFreestyleBotDifficulty_Internal = GameTypes::GetCurrentFreestyleBotDifficulty_Internal(this)) == nullptr
      || !CurrentFreestyleBotDifficulty_Internal->m_HasBotQuota )
    {
      DevMsg(a1: "GameTypes: setting bot_quota to %d for map %s.\n", Map_Internal->m_MinPlayers, Map_Internal->m_Name);
      ConVarRef::ConVarRef(this: &bot_quota, pName: "bot_quota");
      bot_quota.m_pConVar->SetValue_2(this: bot_quota.m_pConVar, a2: Map_Internal->m_MinPlayers);
    }
    return 1;
  }
  else
  {
    _Warning(a1: "GamesTypes: unable to set convars for map %s. Could not find matching map name.\n", mapName);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A1E30
// Name: public: virtual bool GameTypes::GetMapInfo(char const __near *,int __near &,int __near &,unsigned int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameTypes::GetMapInfo(
        GameTypes *this,
        const char *mapName,
        int *maxPlayers,
        int *extraSpectators,
        unsigned int *richPresence)
{
  GameTypes::Map *Map_Internal; // eax

  Map_Internal = GameTypes::GetMap_Internal(this, mapName);
  if ( Map_Internal == nullptr )
    return 0;
  *maxPlayers = Map_Internal->m_MaxPlayers;
  *richPresence = Map_Internal->m_RichPresence;
  *extraSpectators = Map_Internal->m_ExtraSpectators;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102A1E70
// Name: public: virtual class CUtlStringList const __near * GameTypes::GetTModelsForMap(char const __near *)
// Source: json
//------------------------------------------------------------------------------
GameTypes::Map *__thiscall GameTypes::GetTModelsForMap(GameTypes *this, const char *mapName)
{
  GameTypes::Map *result; // eax

  result = GameTypes::GetMap_Internal(this, mapName);
  if ( result != nullptr )
    return (GameTypes::Map *)((char *)result + 84);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102A1E90
// Name: public: virtual class CUtlStringList const __near * GameTypes::GetCTModelsForMap(char const __near *)
// Source: json
//------------------------------------------------------------------------------
GameTypes::Map *__thiscall GameTypes::GetCTModelsForMap(GameTypes *this, const char *mapName)
{
  GameTypes::Map *result; // eax

  result = GameTypes::GetMap_Internal(this, mapName);
  if ( result != nullptr )
    return (GameTypes::Map *)((char *)result + 104);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102A1EB0
// Name: public: virtual char const __near * GameTypes::GetGameTypeFromInt(int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall GameTypes::GetGameTypeFromInt(GameTypes *this, int gameType)
{
  int m_Size; // esi
  int v3; // eax
  GameTypes::GameType **m_pMemory; // edx
  GameTypes::GameType *v5; // ecx

  m_Size = this->m_GameTypes.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
  {
LABEL_6:
    _Warning(a1: "GameTypes: could not find matching game type for value \"%d\".\n", gameType);
    return nullptr;
  }
  else
  {
    m_pMemory = this->m_GameTypes.m_Memory.m_pMemory;
    while ( 1 )
    {
      v5 = *m_pMemory;
      if ( *m_pMemory != nullptr && v5->m_Index == gameType )
        return v5->m_Name;
      ++v3;
      ++m_pMemory;
      if ( v3 >= m_Size )
        goto LABEL_6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A1F00
// Name: public: virtual char const __near * GameTypes::GetGameModeFromInt(int,int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall GameTypes::GetGameModeFromInt(GameTypes *this, int gameType, int gameMode)
{
  int m_Size; // edx
  int v5; // edi
  GameTypes::GameType **m_pMemory; // ecx
  GameTypes::GameType *v7; // ecx
  int v8; // esi
  int v9; // eax
  GameTypes::GameMode **v10; // edx
  GameTypes::GameMode *v11; // ecx
  int v13; // [esp+Ch] [ebp-4h]
  int gameModea; // [esp+1Ch] [ebp+Ch]

  m_Size = this->m_GameTypes.m_Size;
  v5 = 0;
  v13 = m_Size;
  if ( m_Size <= 0 )
  {
LABEL_12:
    _Warning(
      a1: "GameTypes: could not find matching game mode value of \"%d\" and type value of \"%d\".\n",
      gameType,
      gameMode);
    return nullptr;
  }
  else
  {
    m_pMemory = this->m_GameTypes.m_Memory.m_pMemory;
    gameModea = (int)m_pMemory;
    while ( 1 )
    {
      v7 = *m_pMemory;
      if ( v7 != nullptr && v7->m_Index == gameType )
      {
        v8 = v7->m_GameModes.m_Size;
        v9 = 0;
        if ( v8 > 0 )
          break;
      }
LABEL_11:
      ++v5;
      m_pMemory = (GameTypes::GameType **)(gameModea + 4);
      gameModea += 4;
      if ( v5 >= m_Size )
        goto LABEL_12;
    }
    v10 = v7->m_GameModes.m_Memory.m_pMemory;
    while ( 1 )
    {
      v11 = *v10;
      if ( *v10 != nullptr && v11->m_Index == gameMode )
        return v11->m_Name;
      ++v9;
      ++v10;
      if ( v9 >= v8 )
      {
        m_Size = v13;
        goto LABEL_11;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A1F90
// Name: public: virtual int GameTypes::GetNoResetVoteThresholdForCurrentModeCT(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GameTypes::GetNoResetVoteThresholdForCurrentModeCT(GameTypes *this)
{
  int m_Size; // edx
  int m_nValue; // eax
  GameTypes::GameType *v4; // ecx
  int v5; // eax
  GameTypes::GameMode *v6; // eax

  m_Size = this->m_GameTypes.m_Size;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no game types have been loaded.\n");
    return -1;
  }
  if ( game_type.m_pParent != nullptr )
  {
    m_nValue = game_type.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
    {
LABEL_9:
      _Warning(a1: "GamesTypes: game_type is set to an invalid value (%d). Range [%d,%d].\n", m_nValue, 0, m_Size - 1);
      return -1;
    }
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue >= m_Size )
    goto LABEL_9;
  v4 = this->m_GameTypes.m_Memory.m_pMemory[m_nValue];
  if ( v4 == nullptr )
    return -1;
  if ( game_mode.m_pParent != nullptr )
  {
    v5 = game_mode.m_pParent->m_Value.m_nValue;
    if ( v5 < 0 )
    {
LABEL_16:
      _Warning(
        a1: "GamesTypes: game_mode is set to an invalid value (%d). Range [%d,%d].\n",
        v5,
        0,
        v4->m_GameModes.m_Size - 1);
      return -1;
    }
  }
  else
  {
    v5 = 0;
  }
  if ( v5 >= v4->m_GameModes.m_Size )
    goto LABEL_16;
  v6 = v4->m_GameModes.m_Memory.m_pMemory[v5];
  if ( v6 == nullptr )
    return -1;
  return v6->m_NoResetVoteThresholdCT;
}

//------------------------------------------------------------------------------
// Address: 0x102A2030
// Name: public: virtual int GameTypes::GetNoResetVoteThresholdForCurrentModeT(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GameTypes::GetNoResetVoteThresholdForCurrentModeT(GameTypes *this)
{
  int m_Size; // edx
  int m_nValue; // eax
  GameTypes::GameType *v4; // ecx
  int v5; // eax
  GameTypes::GameMode *v6; // eax

  m_Size = this->m_GameTypes.m_Size;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no game types have been loaded.\n");
    return -1;
  }
  if ( game_type.m_pParent != nullptr )
  {
    m_nValue = game_type.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
    {
LABEL_9:
      _Warning(a1: "GamesTypes: game_type is set to an invalid value (%d). Range [%d,%d].\n", m_nValue, 0, m_Size - 1);
      return -1;
    }
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue >= m_Size )
    goto LABEL_9;
  v4 = this->m_GameTypes.m_Memory.m_pMemory[m_nValue];
  if ( v4 == nullptr )
    return -1;
  if ( game_mode.m_pParent != nullptr )
  {
    v5 = game_mode.m_pParent->m_Value.m_nValue;
    if ( v5 < 0 )
    {
LABEL_16:
      _Warning(
        a1: "GamesTypes: game_mode is set to an invalid value (%d). Range [%d,%d].\n",
        v5,
        0,
        v4->m_GameModes.m_Size - 1);
      return -1;
    }
  }
  else
  {
    v5 = 0;
  }
  if ( v5 >= v4->m_GameModes.m_Size )
    goto LABEL_16;
  v6 = v4->m_GameModes.m_Memory.m_pMemory[v5];
  if ( v6 == nullptr )
    return -1;
  return v6->m_NoResetVoteThresholdT;
}

//------------------------------------------------------------------------------
// Address: 0x102A20D0
// Name: public: virtual bool GameTypes::GetGameModeAndTypeIntsFromStrings(char const __near *,char const __near *,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameTypes::GetGameModeAndTypeIntsFromStrings(
        GameTypes *this,
        const char *szGameType,
        const char *szGameMode,
        int *iOutGameType,
        int *iOutGameMode)
{
  GameTypes::GameType *GameType_Internal; // eax
  GameTypes::GameType *v7; // esi
  GameTypes::GameMode *GameMode_Internal; // eax
  int m_Index; // ecx

  *iOutGameType = -1;
  *iOutGameMode = -1;
  if ( szGameType == nullptr || szGameMode == nullptr )
    return 0;
  GameType_Internal = GameTypes::GetGameType_Internal(this, gameType: szGameType);
  v7 = GameType_Internal;
  if ( GameType_Internal == nullptr
    || (GameMode_Internal = GameTypes::GetGameMode_Internal(this, pGameType: GameType_Internal, gameMode: szGameMode)) == nullptr )
  {
    _Warning(
      a1: "GamesTypes: unable to get game type and mode. Could not find type/mode matching type:%s/mode:%s.\n",
      szGameType,
      szGameMode);
    return 0;
  }
  m_Index = v7->m_Index;
  if ( v7->m_Index < 0
    || m_Index >= this->m_GameTypes.m_Size
    || GameMode_Internal->m_Index < 0
    || GameMode_Internal->m_Index >= v7->m_GameModes.m_Size )
  {
    return 0;
  }
  *iOutGameType = m_Index;
  *iOutGameMode = GameMode_Internal->m_Index;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102A2160
// Name: public: virtual bool GameTypes::GetGameModeAndTypeNameIdsFromStrings(char const __near *,char const __near *,char const __near * __near &,char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameTypes::GetGameModeAndTypeNameIdsFromStrings(
        GameTypes *this,
        const char *szGameType,
        const char *szGameMode,
        char **szOutGameTypeNameId,
        char **szOutGameModeNameId)
{
  GameTypes::GameType *GameType_Internal; // eax
  GameTypes::GameType *v7; // esi
  GameTypes::GameMode *GameMode_Internal; // eax

  *szOutGameTypeNameId = nullptr;
  *szOutGameModeNameId = nullptr;
  if ( szGameType == nullptr || szGameMode == nullptr )
    return 0;
  GameType_Internal = GameTypes::GetGameType_Internal(this, gameType: szGameType);
  v7 = GameType_Internal;
  if ( GameType_Internal == nullptr
    || (GameMode_Internal = GameTypes::GetGameMode_Internal(this, pGameType: GameType_Internal, gameMode: szGameMode)) == nullptr )
  {
    _Warning(
      a1: "GamesTypes: unable to get game type and mode. Could not find type/mode matching type:%s/mode:%s.\n",
      szGameType,
      szGameMode);
    return 0;
  }
  if ( GameMode_Internal == (GameTypes::GameMode *)-36 || v7 == (GameTypes::GameType *)-36 )
    return 0;
  *szOutGameTypeNameId = v7->m_NameID;
  *szOutGameModeNameId = GameMode_Internal->m_NameID;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102A2270
// Name: public: void CUtlStringList::CopyAndAddToTail(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlStringList::CopyAndAddToTail(CUtlStringList *this, const char *pString)
{
  char *v3; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v7; // eax
  char **v8; // edi

  v3 = (char *)operator new(nSize: strlen(pString) + 1);
  _V_strcpy(dest: v3, src: pString);
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CNavLadder *,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &this->m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = v3;
}

//------------------------------------------------------------------------------
// Address: 0x102A22F0
// Name: private: bool GameTypes::LoadFreestyleBotDifficulties(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameTypes::LoadFreestyleBotDifficulties(GameTypes *this, KeyValues *pKV)
{
  KeyValues *Key; // eax
  KeyValues *FirstTrueSubKey; // edi
  _DWORD *v6; // eax
  GameTypes::FreestyleBotDifficulty *v7; // ebx
  const char *Name; // eax
  const char *String; // eax
  const char *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  GameTypes::FreestyleBotDifficulty **m_pMemory; // ecx
  int v16; // eax
  GameTypes::FreestyleBotDifficulty **v17; // edi
  const char *v18; // eax
  KeyValues *pKV_BotDiff; // [esp+14h] [ebp+8h]

  if ( pKV == nullptr )
    return 0;
  if ( this->m_FreestyleBotDifficulties.m_Size > 0 )
    CUtlVector<GameTypes::FreestyleBotDifficulty *,CUtlMemory<GameTypes::FreestyleBotDifficulty *,int>>::PurgeAndDeleteElements(this: &this->m_FreestyleBotDifficulties);
  Key = KeyValues::FindKey(this: pKV, keyName: "botDifficulty", bCreate: false);
  if ( Key == nullptr )
  {
    _Warning(a1: "GameTypes: could not find entry %s.\n", "botDifficulty");
    return 0;
  }
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: Key);
  pKV_BotDiff = FirstTrueSubKey;
  if ( FirstTrueSubKey != nullptr )
  {
    while ( 1 )
    {
      v6 = operator new(nSize: 0x4Cu);
      v7 = nullptr;
      if ( v6 != nullptr )
      {
        v6[17] = 0;
        *((_BYTE *)v6 + 72) = 0;
        *((_BYTE *)v6 + 4) = 0;
        *((_BYTE *)v6 + 36) = 0;
        *v6 = -1;
        v7 = (GameTypes::FreestyleBotDifficulty *)v6;
      }
      Name = KeyValues::GetName(this: FirstTrueSubKey);
      V_strncpy(pDest: v7->m_Name, pSrc: Name, maxLen: 32);
      String = KeyValues::GetString(this: FirstTrueSubKey, keyName: "nameID", defaultValue: locale);
      if ( String != nullptr )
      {
        V_strncpy(pDest: v7->m_NameID, pSrc: String, maxLen: 32);
      }
      else
      {
        v10 = KeyValues::GetName(this: FirstTrueSubKey);
        _Warning(a1: "GameTypes: missing %s entry for bot difficulty %s.\n", "nameID", v10);
      }
      v11 = KeyValues::FindKey(this: FirstTrueSubKey, keyName: "convars", bCreate: false);
      v12 = v11;
      if ( v11 != nullptr )
      {
        v7->m_pConvars = KeyValues::MakeCopy(this: v11);
        v7->m_HasBotQuota = KeyValues::GetInt(this: v12, keyName: "bot_quota", defaultValue: -1) != -1;
      }
      else
      {
        v18 = KeyValues::GetName(this: pKV_BotDiff);
        _Warning(a1: "GameTypes: missing entry %s for bot difficulty %s.\n", "convars", v18);
      }
      v7->m_Index = this->m_FreestyleBotDifficulties.m_Size;
      m_Size = this->m_FreestyleBotDifficulties.m_Size;
      m_nAllocationCount = this->m_FreestyleBotDifficulties.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_FreestyleBotDifficulties,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_FreestyleBotDifficulties.m_Size;
      m_pMemory = this->m_FreestyleBotDifficulties.m_Memory.m_pMemory;
      v16 = this->m_FreestyleBotDifficulties.m_Size - m_Size - 1;
      this->m_FreestyleBotDifficulties.m_pElements = m_pMemory;
      if ( v16 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v16);
      v17 = &this->m_FreestyleBotDifficulties.m_Memory.m_pMemory[m_Size];
      if ( v17 != nullptr )
        *v17 = v7;
      pKV_BotDiff = KeyValues::GetNextTrueSubKey(this: pKV_BotDiff);
      if ( pKV_BotDiff == nullptr )
        break;
      FirstTrueSubKey = pKV_BotDiff;
    }
  }
  if ( this->m_FreestyleBotDifficulties.m_Size == 0 )
    _Warning(a1: "GamesTypes: empty %s entry.\n", "botDifficulty");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102A2530
// Name: private: void GameTypes::LoadWeaponProgression(class KeyValues __near *,class CUtlVector<struct IGameTypes::WeaponProgression,class CUtlMemory<struct IGameTypes::WeaponProgression,int>> __near &,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GameTypes::LoadWeaponProgression(
        GameTypes *this,
        KeyValues *pKV_WeaponProgression,
        CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int> > *vecWeaponProgression,
        const char *szGameType,
        const char *szGameMode)
{
  KeyValues *v5; // edi
  KeyValues *FirstTrueSubKey; // ebx
  const char *Name; // eax
  const char *v8; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  IGameTypes::WeaponProgression *m_pMemory; // ecx
  int v12; // eax
  IGameTypes::WeaponProgression *v13; // edi
  const char *v14; // eax
  IGameTypes::WeaponProgression wp; // [esp+4h] [ebp-14h] BYREF

  v5 = pKV_WeaponProgression;
  if ( pKV_WeaponProgression != nullptr )
  {
    FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pKV_WeaponProgression);
    if ( FirstTrueSubKey != nullptr )
    {
      do
      {
        CUtlString::CUtlString(this: &wp.m_Name);
        wp.m_Kills = 0;
        Name = KeyValues::GetName(this: FirstTrueSubKey);
        CUtlString::Set(this: &wp.m_Name, pValue: Name);
        wp.m_Kills = KeyValues::GetInt(this: FirstTrueSubKey, keyName: "kills", defaultValue: -1);
        if ( wp.m_Kills == -1 )
        {
          wp.m_Kills = 0;
          v8 = KeyValues::GetName(this: FirstTrueSubKey);
          _Warning(
            a1: "GameTypes: missing %s entry for weapon \"%s\" for game type/mode (%s/%s).\n",
            "kills",
            v8,
            szGameType,
            szGameMode);
        }
        m_Size = vecWeaponProgression->m_Size;
        m_nAllocationCount = vecWeaponProgression->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int>>,int>::Grow(
            this: (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)vecWeaponProgression,
            num: m_Size - m_nAllocationCount + 1);
        ++vecWeaponProgression->m_Size;
        m_pMemory = vecWeaponProgression->m_Memory.m_pMemory;
        v12 = vecWeaponProgression->m_Size - m_Size - 1;
        vecWeaponProgression->m_pElements = vecWeaponProgression->m_Memory.m_pMemory;
        if ( v12 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 20 * v12);
        v13 = &vecWeaponProgression->m_Memory.m_pMemory[m_Size];
        if ( v13 != nullptr )
        {
          CUtlString::CUtlString(this: &v13->m_Name, string: &wp.m_Name);
          v13->m_Kills = wp.m_Kills;
        }
        wp.m_Name.m_Storage.m_nActualLength = 0;
        if ( wp.m_Name.m_Storage.m_Memory.m_nGrowSize >= 0 && wp.m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: wp.m_Name.m_Storage.m_Memory.m_pMemory);
        FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
      }
      while ( FirstTrueSubKey != nullptr );
      v5 = pKV_WeaponProgression;
    }
    if ( vecWeaponProgression->m_Size == 0 )
    {
      v14 = KeyValues::GetName(this: v5);
      _Warning(a1: "GameTypes: empty %s entry for game type/mode (%s/%s).\n", v14, szGameType, szGameMode);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A27B0
// Name: public: GameTypes::GameMode::GameMode(void)
// Source: json
//------------------------------------------------------------------------------
GameTypes::GameMode *__thiscall GameTypes::GameMode::GameMode(GameTypes::GameMode *this)
{
  this->m_pConvarsSP = nullptr;
  this->m_pConvarsMP = nullptr;
  this->m_Index = -1;
  this->m_Maps.m_Memory.m_pMemory = nullptr;
  this->m_Maps.m_Memory.m_nAllocationCount = 0;
  this->m_Maps.m_Memory.m_nGrowSize = 0;
  this->m_Maps.m_Size = 0;
  this->m_Maps.m_pElements = nullptr;
  this->m_WeaponProgressionCT.m_Memory.m_pMemory = nullptr;
  this->m_WeaponProgressionCT.m_Memory.m_nAllocationCount = 0;
  this->m_WeaponProgressionCT.m_Memory.m_nGrowSize = 0;
  this->m_WeaponProgressionCT.m_Size = 0;
  this->m_WeaponProgressionCT.m_pElements = nullptr;
  this->m_WeaponProgressionT.m_Memory.m_pMemory = nullptr;
  this->m_WeaponProgressionT.m_Memory.m_nAllocationCount = 0;
  this->m_WeaponProgressionT.m_Memory.m_nGrowSize = 0;
  this->m_WeaponProgressionT.m_Size = 0;
  this->m_WeaponProgressionT.m_pElements = nullptr;
  this->m_Name[0] = 0;
  this->m_NameID[0] = 0;
  this->m_DescID[0] = 0;
  this->m_NoResetVoteThresholdCT = -1;
  this->m_NoResetVoteThresholdT = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102A2820
// Name: private: bool GameTypes::LoadMaps(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameTypes::LoadMaps(GameTypes *this, KeyValues *pKV)
{
  GameTypes *v2; // edi
  KeyValues *Key; // eax
  KeyValues *FirstTrueSubKey; // ebx
  GameTypes::Map *v6; // eax
  unsigned int v7; // ecx
  GameTypes::Map *v8; // edi
  const char *Name; // eax
  const char *String; // eax
  const char *v11; // eax
  int Int; // eax
  int v13; // eax
  int v14; // eax
  KeyValues *v15; // eax
  KeyValues *i; // esi
  const char *v17; // eax
  KeyValues *v18; // eax
  KeyValues *FirstValue; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_CTModels; // esi
  const char *v21; // eax
  const char *v22; // edi
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v25; // ecx
  int v26; // eax
  char **v27; // edi
  const char *v28; // eax
  int m_Size; // esi
  CUtlVector<GameTypes::Map *,CUtlMemory<GameTypes::Map *,int> > *p_m_Maps; // edi
  int v31; // eax
  GameTypes::Map **v32; // ecx
  int v33; // eax
  GameTypes::Map **v34; // esi
  const char *v35; // [esp-4h] [ebp-1Ch]
  const char *v36; // [esp-4h] [ebp-1Ch]
  const char *v37; // [esp-4h] [ebp-1Ch]
  const char *v38; // [esp-4h] [ebp-1Ch]
  int v39; // [esp-4h] [ebp-1Ch]
  char *v40; // [esp+Ch] [ebp-Ch]
  KeyValues *pKV_Model; // [esp+14h] [ebp-4h]
  GameTypes::Map *pMap; // [esp+20h] [ebp+8h]

  v2 = this;
  if ( pKV == nullptr )
    return 0;
  if ( this->m_Maps.m_Size > 0 )
    CUtlVector<GameTypes::Map *,CUtlMemory<GameTypes::Map *,int>>::PurgeAndDeleteElements(this: &this->m_Maps);
  Key = KeyValues::FindKey(this: pKV, keyName: "maps", bCreate: false);
  if ( Key == nullptr )
  {
    _Warning(a1: "GameTypes: could not find entry %s.\n", "maps");
    return 0;
  }
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: Key);
  if ( FirstTrueSubKey == nullptr )
    goto LABEL_49;
  do
  {
    v6 = (GameTypes::Map *)operator new(nSize: 0x7Cu);
    if ( v6 != nullptr )
    {
      v7 = g_richPresenceDefault;
      v6->m_Index = -1;
      v6->m_MinPlayers = 0;
      v6->m_MaxPlayers = 0;
      v6->m_ExtraSpectators = 0;
      v6->m_RichPresence = v7;
      v6->m_TModels.m_Memory.m_pMemory = nullptr;
      v6->m_TModels.m_Memory.m_nAllocationCount = 0;
      v6->m_TModels.m_Memory.m_nGrowSize = 0;
      v6->m_TModels.m_Size = 0;
      v6->m_TModels.m_pElements = nullptr;
      v6->m_CTModels.m_Memory.m_pMemory = nullptr;
      v6->m_CTModels.m_Memory.m_nAllocationCount = 0;
      v6->m_CTModels.m_Memory.m_nGrowSize = 0;
      v6->m_CTModels.m_Size = 0;
      v6->m_CTModels.m_pElements = nullptr;
      v8 = v6;
      v6->m_Name[0] = 0;
      v6->m_NameID[0] = 0;
      pMap = v6;
    }
    else
    {
      pMap = nullptr;
      v8 = nullptr;
    }
    Name = KeyValues::GetName(this: FirstTrueSubKey);
    V_strncpy(pDest: v8->m_Name, pSrc: Name, maxLen: 32);
    String = KeyValues::GetString(this: FirstTrueSubKey, keyName: "nameID", defaultValue: locale);
    if ( String != nullptr )
    {
      V_strncpy(pDest: v8->m_NameID, pSrc: String, maxLen: 32);
    }
    else
    {
      v11 = KeyValues::GetName(this: FirstTrueSubKey);
      _Warning(a1: "GameTypes: missing %s entry for map %s.\n", "nameID", v11);
    }
    Int = KeyValues::GetInt(this: FirstTrueSubKey, keyName: "minplayers", defaultValue: -1);
    v8->m_MinPlayers = Int;
    if ( Int == -1 )
    {
      v35 = KeyValues::GetName(this: FirstTrueSubKey);
      _Warning(a1: "GameTypes: missing %s entry for map %s.\n", "minplayers", v35);
    }
    else
    {
      if ( Int >= 0 )
        goto LABEL_19;
      v36 = KeyValues::GetName(this: FirstTrueSubKey);
      _Warning(a1: "GameTypes: invalid %s entry for map %s.\n", "minplayers", v36);
    }
    v8->m_MinPlayers = 0;
LABEL_19:
    v13 = KeyValues::GetInt(this: FirstTrueSubKey, keyName: "maxplayers", defaultValue: -1);
    v8->m_MaxPlayers = v13;
    if ( v13 == -1 )
    {
      v37 = KeyValues::GetName(this: FirstTrueSubKey);
      _Warning(a1: "GameTypes: missing %s entry for map %s.\n", "maxplayers", v37);
    }
    else
    {
      if ( v13 >= 0 )
        goto LABEL_24;
      v38 = KeyValues::GetName(this: FirstTrueSubKey);
      _Warning(a1: "GameTypes: invalid %s entry for map %s.\n", "maxplayers", v38);
    }
    v8->m_MaxPlayers = 0;
LABEL_24:
    v14 = KeyValues::GetInt(this: FirstTrueSubKey, keyName: "extraspectators", defaultValue: 0);
    v39 = g_richPresenceDefault;
    v8->m_ExtraSpectators = v14;
    v8->m_RichPresence = KeyValues::GetInt(this: FirstTrueSubKey, keyName: "richpresencecontext", defaultValue: v39);
    v15 = KeyValues::FindKey(this: FirstTrueSubKey, keyName: "t_models", bCreate: false);
    if ( v15 != nullptr )
    {
      for ( i = KeyValues::GetFirstValue(this: v15); i != nullptr; i = KeyValues::GetNextValue(this: i) )
      {
        v17 = KeyValues::GetName(this: i);
        CUtlStringList::CopyAndAddToTail(this: &v8->m_TModels, pString: v17);
      }
    }
    else
    {
      v21 = KeyValues::GetName(this: FirstTrueSubKey);
      _Warning(a1: "GameTypes: missing %s entry for map %s.\n", "t_models", v21);
    }
    v18 = KeyValues::FindKey(this: FirstTrueSubKey, keyName: "ct_models", bCreate: false);
    if ( v18 != nullptr )
    {
      FirstValue = KeyValues::GetFirstValue(this: v18);
      pKV_Model = FirstValue;
      if ( FirstValue != nullptr )
      {
        p_m_CTModels = (CUtlMemory<vgui::TreeNode *,int> *)&v8->m_CTModels;
        while ( 1 )
        {
          v22 = KeyValues::GetName(this: FirstValue);
          v40 = (char *)operator new(nSize: strlen(v22) + 1);
          _V_strcpy(dest: v40, src: v22);
          m_pMemory = p_m_CTModels[1].m_pMemory;
          m_nAllocationCount = p_m_CTModels->m_nAllocationCount;
          if ( (int)m_pMemory + 1 > m_nAllocationCount )
            CUtlMemory<CNavLadder *,int>::Grow(this: p_m_CTModels, num: (int)m_pMemory - m_nAllocationCount + 1);
          ++p_m_CTModels[1].m_pMemory;
          v25 = p_m_CTModels->m_pMemory;
          v26 = (char *)p_m_CTModels[1].m_pMemory - (char *)m_pMemory - 1;
          p_m_CTModels[1].m_nAllocationCount = (int)p_m_CTModels->m_pMemory;
          if ( v26 > 0 )
            _V_memmove(dest: &v25[(_DWORD)m_pMemory + 1], src: &v25[(_DWORD)m_pMemory], count: 4 * v26);
          v27 = (char **)&p_m_CTModels->m_pMemory[(_DWORD)m_pMemory];
          if ( v27 != nullptr )
            *v27 = v40;
          pKV_Model = KeyValues::GetNextValue(this: pKV_Model);
          if ( pKV_Model == nullptr )
            break;
          FirstValue = pKV_Model;
        }
        v8 = pMap;
      }
    }
    else
    {
      v28 = KeyValues::GetName(this: FirstTrueSubKey);
      _Warning(a1: "GameTypes: missing %s entry for map %s.\n", "ct_models", v28);
    }
    v8->m_Index = this->m_Maps.m_Size;
    m_Size = this->m_Maps.m_Size;
    p_m_Maps = &this->m_Maps;
    v31 = this->m_Maps.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > v31 )
      CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)p_m_Maps, num: m_Size - v31 + 1);
    ++this->m_Maps.m_Size;
    v32 = p_m_Maps->m_Memory.m_pMemory;
    v33 = this->m_Maps.m_Size - m_Size - 1;
    this->m_Maps.m_pElements = this->m_Maps.m_Memory.m_pMemory;
    if ( v33 > 0 )
      _V_memmove(dest: &v32[m_Size + 1], src: &v32[m_Size], count: 4 * v33);
    v34 = &p_m_Maps->m_Memory.m_pMemory[m_Size];
    if ( v34 != nullptr )
      *v34 = pMap;
    FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
  }
  while ( FirstTrueSubKey != nullptr );
  v2 = this;
LABEL_49:
  if ( v2->m_Maps.m_Size == 0 )
    _Warning(a1: "GamesTypes: empty %s entry.\n", "maps");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102A2E70
// Name: private: bool GameTypes::LoadGameTypes(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameTypes::LoadGameTypes(GameTypes *this, KeyValues *pKV)
{
  KeyValues *Key; // eax
  KeyValues *FirstTrueSubKey; // edi
  GameTypes::GameType *v5; // eax
  GameTypes::GameType *v6; // esi
  const char *Name; // eax
  const char *String; // eax
  const char *v9; // eax
  KeyValues *v10; // eax
  KeyValues *NextTrueSubKey; // ebx
  GameTypes::GameMode *v12; // eax
  GameTypes::GameMode *v13; // esi
  const char *v14; // eax
  const char *v15; // eax
  void (*v16)(const char *, ...); // esi
  const char *v17; // eax
  const char *v18; // eax
  const char *v19; // eax
  KeyValues *v20; // eax
  const char *v21; // eax
  KeyValues *v22; // eax
  KeyValues *v23; // eax
  KeyValues *FirstValue; // edi
  const char *v25; // eax
  const char *v26; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v30; // eax
  char **v31; // edi
  const char *v32; // eax
  const char *v33; // eax
  KeyValues *v34; // esi
  const char *v35; // eax
  const char *v36; // eax
  KeyValues *v37; // eax
  const char *v38; // eax
  bool v39; // zf
  int v40; // eax
  KeyValues *v41; // eax
  int v42; // esi
  const char *v43; // eax
  int v44; // edi
  int v45; // eax
  GameTypes::GameMode **v46; // ecx
  int v47; // eax
  GameTypes::GameMode **v48; // edi
  const char *v49; // eax
  int v50; // ebx
  int v51; // eax
  GameTypes::GameType **v52; // ecx
  int v53; // eax
  GameTypes::GameType **v54; // eax
  const char *v55; // eax
  const char *v56; // [esp-8h] [ebp-28h]
  const char *v57; // [esp-8h] [ebp-28h]
  const char *v58; // [esp-8h] [ebp-28h]
  const char *v59; // [esp-8h] [ebp-28h]
  const char *v60; // [esp-8h] [ebp-28h]
  const char *v61; // [esp-8h] [ebp-28h]
  const char *v62; // [esp-8h] [ebp-28h]
  char *s2; // [esp+8h] [ebp-18h]
  char *s2a; // [esp+8h] [ebp-18h]
  char *pKV_WeaponProgressionT; // [esp+Ch] [ebp-14h]
  KeyValues *pKV_WeaponProgressionTc; // [esp+Ch] [ebp-14h]
  KeyValues *pKV_WeaponProgressionTa; // [esp+Ch] [ebp-14h]
  KeyValues *pKV_WeaponProgressionTb; // [esp+Ch] [ebp-14h]
  GameTypes::GameType *pGameType; // [esp+14h] [ebp-Ch]
  KeyValues *pKV_Map; // [esp+18h] [ebp-8h]
  KeyValues *pKV_Mapa; // [esp+18h] [ebp-8h]
  KeyValues *pKV_GameType; // [esp+1Ch] [ebp-4h]
  GameTypes::GameMode *pGameMode; // [esp+28h] [ebp+8h]

  if ( pKV == nullptr )
    return 0;
  if ( this->m_GameTypes.m_Size > 0 )
    CUtlVector<GameTypes::GameType *,CUtlMemory<GameTypes::GameType *,int>>::PurgeAndDeleteElements(this: &this->m_GameTypes);
  Key = KeyValues::FindKey(this: pKV, keyName: "gameTypes", bCreate: false);
  if ( Key == nullptr )
  {
    _Warning(a1: "GameTypes: could not find entry %s.\n", "gameTypes");
    return 0;
  }
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: Key);
  pKV_GameType = FirstTrueSubKey;
  if ( FirstTrueSubKey != nullptr )
  {
    while ( 1 )
    {
      v5 = (GameTypes::GameType *)operator new(nSize: 0x58u);
      if ( v5 != nullptr )
      {
        v5->m_Index = -1;
        v5->m_GameModes.m_Memory.m_pMemory = nullptr;
        v5->m_GameModes.m_Memory.m_nAllocationCount = 0;
        v5->m_GameModes.m_Memory.m_nGrowSize = 0;
        v5->m_GameModes.m_Size = 0;
        v5->m_GameModes.m_pElements = nullptr;
        v6 = v5;
        v5->m_Name[0] = 0;
        v5->m_NameID[0] = 0;
        pGameType = v5;
      }
      else
      {
        pGameType = nullptr;
        v6 = nullptr;
      }
      Name = KeyValues::GetName(this: FirstTrueSubKey);
      V_strncpy(pDest: v6->m_Name, pSrc: Name, maxLen: 32);
      String = KeyValues::GetString(this: FirstTrueSubKey, keyName: "nameID", defaultValue: locale);
      if ( String != nullptr )
      {
        V_strncpy(pDest: v6->m_NameID, pSrc: String, maxLen: 32);
      }
      else
      {
        v9 = KeyValues::GetName(this: FirstTrueSubKey);
        _Warning(a1: "GameTypes: missing %s entry for game type %s.\n", "nameID", v9);
      }
      v10 = KeyValues::FindKey(this: FirstTrueSubKey, keyName: "gameModes", bCreate: false);
      if ( v10 != nullptr )
      {
        NextTrueSubKey = KeyValues::GetFirstTrueSubKey(this: v10);
        if ( NextTrueSubKey != nullptr )
        {
          do
          {
            v12 = (GameTypes::GameMode *)operator new(nSize: 0xB0u);
            if ( v12 != nullptr )
            {
              v13 = GameTypes::GameMode::GameMode(this: v12);
              pGameMode = v13;
            }
            else
            {
              pGameMode = nullptr;
              v13 = nullptr;
            }
            v14 = KeyValues::GetName(this: NextTrueSubKey);
            V_strncpy(pDest: v13->m_Name, pSrc: v14, maxLen: 32);
            v15 = KeyValues::GetString(this: NextTrueSubKey, keyName: "nameID", defaultValue: locale);
            if ( v15 != nullptr )
            {
              V_strncpy(pDest: v13->m_NameID, pSrc: v15, maxLen: 32);
              v16 = (void (*)(const char *, ...))_Warning;
            }
            else
            {
              v56 = KeyValues::GetName(this: NextTrueSubKey);
              v17 = KeyValues::GetName(this: FirstTrueSubKey);
              v16 = (void (*)(const char *, ...))_Warning;
              _Warning(a1: "GameTypes: missing %s entry for game type/mode (%s/%s).\n", "nameID", v17, v56);
            }
            v18 = KeyValues::GetString(this: NextTrueSubKey, keyName: "descID", defaultValue: locale);
            if ( v18 != nullptr )
            {
              V_strncpy(pDest: pGameMode->m_DescID, pSrc: v18, maxLen: 32);
            }
            else
            {
              v57 = KeyValues::GetName(this: NextTrueSubKey);
              v19 = KeyValues::GetName(this: FirstTrueSubKey);
              v16(a1: "GameTypes: missing %s entry for game type/mode (%s/%s).\n", "descID", v19, v57);
            }
            v20 = KeyValues::FindKey(this: NextTrueSubKey, keyName: "convars", bCreate: false);
            if ( v20 != nullptr )
            {
              pGameMode->m_pConvarsSP = KeyValues::MakeCopy(this: v20);
            }
            else
            {
              v58 = KeyValues::GetName(this: NextTrueSubKey);
              v21 = KeyValues::GetName(this: FirstTrueSubKey);
              v16(a1: "GameTypes: missing entry %s for game type/mode (%s/%s).\n", "convars", v21, v58);
            }
            v22 = KeyValues::FindKey(this: NextTrueSubKey, keyName: "convars_mp", bCreate: false);
            if ( v22 != nullptr )
              pGameMode->m_pConvarsMP = KeyValues::MakeCopy(this: v22);
            v23 = KeyValues::FindKey(this: NextTrueSubKey, keyName: "maps", bCreate: false);
            if ( v23 != nullptr )
            {
              FirstValue = KeyValues::GetFirstValue(this: v23);
              pKV_Map = FirstValue;
              if ( FirstValue != nullptr )
              {
                while ( 1 )
                {
                  v25 = KeyValues::GetName(this: FirstValue);
                  if ( _V_stricmp(s1: v25, s2: "random") != 0 )
                  {
                    v26 = KeyValues::GetName(this: FirstValue);
                    pKV_WeaponProgressionT = (char *)operator new(nSize: strlen(v26) + 1);
                    _V_strcpy(dest: pKV_WeaponProgressionT, src: v26);
                    m_Size = pGameMode->m_Maps.m_Size;
                    m_nAllocationCount = pGameMode->m_Maps.m_Memory.m_nAllocationCount;
                    if ( m_Size + 1 > m_nAllocationCount )
                      CUtlMemory<CNavLadder *,int>::Grow(
                        this: (CUtlMemory<vgui::TreeNode *,int> *)&pGameMode->m_Maps,
                        num: m_Size - m_nAllocationCount + 1);
                    ++pGameMode->m_Maps.m_Size;
                    m_pMemory = pGameMode->m_Maps.m_Memory.m_pMemory;
                    v30 = pGameMode->m_Maps.m_Size - m_Size - 1;
                    pGameMode->m_Maps.m_pElements = m_pMemory;
                    if ( v30 > 0 )
                      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v30);
                    v31 = &pGameMode->m_Maps.m_Memory.m_pMemory[m_Size];
                    if ( v31 != nullptr )
                      *v31 = pKV_WeaponProgressionT;
                    FirstValue = pKV_Map;
                  }
                  pKV_Map = KeyValues::GetNextValue(this: FirstValue);
                  if ( pKV_Map == nullptr )
                    break;
                  FirstValue = pKV_Map;
                }
              }
              if ( pGameMode->m_Maps.m_Size == 0 )
              {
                v59 = KeyValues::GetName(this: NextTrueSubKey);
                v32 = KeyValues::GetName(this: pKV_GameType);
                _Warning(a1: "GameTypes: empty %s entry for game type/mode (%s/%s).\n", "maps", v32, v59);
              }
            }
            else
            {
              v60 = KeyValues::GetName(this: NextTrueSubKey);
              v33 = KeyValues::GetName(this: FirstTrueSubKey);
              v16(a1: "GameTypes: missing %s entry for game type/mode (%s/%s).\n", "maps", v33, v60);
            }
            v34 = KeyValues::FindKey(this: NextTrueSubKey, keyName: "weaponprogression_ct", bCreate: false);
            v61 = KeyValues::GetName(this: NextTrueSubKey);
            v35 = KeyValues::GetName(this: pKV_GameType);
            GameTypes::LoadWeaponProgression(
              this,
              pKV_WeaponProgression: v34,
              vecWeaponProgression: &pGameMode->m_WeaponProgressionCT,
              szGameType: v35,
              szGameMode: v61);
            pKV_WeaponProgressionTc = KeyValues::FindKey(
                                        this: NextTrueSubKey,
                                        keyName: "weaponprogression_t",
                                        bCreate: false);
            v62 = KeyValues::GetName(this: NextTrueSubKey);
            v36 = KeyValues::GetName(this: pKV_GameType);
            GameTypes::LoadWeaponProgression(
              this,
              pKV_WeaponProgression: pKV_WeaponProgressionTc,
              vecWeaponProgression: &pGameMode->m_WeaponProgressionT,
              szGameType: v36,
              szGameMode: v62);
            v37 = KeyValues::FindKey(this: NextTrueSubKey, keyName: "no_reset_vote_threshold_t", bCreate: false);
            if ( v37 != nullptr )
            {
              s2 = (char *)KeyValues::GetString(this: v37, keyName: nullptr, defaultValue: locale);
              pKV_WeaponProgressionTa = nullptr;
              if ( pGameMode->m_WeaponProgressionT.m_Size <= 0 )
              {
LABEL_53:
                v40 = -1;
              }
              else
              {
                pKV_Mapa = nullptr;
                while ( 1 )
                {
                  v38 = CUtlString::operator char const *(this: (CUtlString *)((char *)pKV_Mapa
                                                                             + (unsigned int)pGameMode->m_WeaponProgressionT.m_Memory.m_pMemory));
                  v39 = _V_strcmp(s1: v38, s2) == 0;
                  v40 = (int)pKV_WeaponProgressionTa;
                  if ( v39 )
                    break;
                  pKV_Mapa = (KeyValues *)((char *)pKV_Mapa + 20);
                  pKV_WeaponProgressionTa = (KeyValues *)((char *)pKV_WeaponProgressionTa + 1);
                  if ( (int)pKV_WeaponProgressionTa >= pGameMode->m_WeaponProgressionT.m_Size )
                    goto LABEL_53;
                }
              }
              pGameMode->m_NoResetVoteThresholdT = v40;
            }
            v41 = KeyValues::FindKey(this: NextTrueSubKey, keyName: "no_reset_vote_threshold_ct", bCreate: false);
            v42 = 0;
            if ( v41 != nullptr )
            {
              s2a = (char *)KeyValues::GetString(this: v41, keyName: nullptr, defaultValue: locale);
              if ( pGameMode->m_WeaponProgressionCT.m_Size <= 0 )
              {
LABEL_60:
                v42 = -1;
              }
              else
              {
                pKV_WeaponProgressionTb = nullptr;
                while ( 1 )
                {
                  v43 = CUtlString::operator char const *(this: (CUtlString *)((char *)pKV_WeaponProgressionTb
                                                                             + (unsigned int)pGameMode->m_WeaponProgressionCT.m_Memory.m_pMemory));
                  if ( _V_strcmp(s1: v43, s2: s2a) == 0 )
                    break;
                  pKV_WeaponProgressionTb = (KeyValues *)((char *)pKV_WeaponProgressionTb + 20);
                  if ( ++v42 >= pGameMode->m_WeaponProgressionCT.m_Size )
                    goto LABEL_60;
                }
              }
              pGameMode->m_NoResetVoteThresholdCT = v42;
            }
            pGameMode->m_Index = pGameType->m_GameModes.m_Size;
            v44 = pGameType->m_GameModes.m_Size;
            v45 = pGameType->m_GameModes.m_Memory.m_nAllocationCount;
            if ( v44 + 1 > v45 )
              CUtlMemory<CNavLadder *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)&pGameType->m_GameModes,
                num: v44 - v45 + 1);
            ++pGameType->m_GameModes.m_Size;
            v46 = pGameType->m_GameModes.m_Memory.m_pMemory;
            v47 = pGameType->m_GameModes.m_Size - v44 - 1;
            pGameType->m_GameModes.m_pElements = v46;
            if ( v47 > 0 )
              _V_memmove(dest: &v46[v44 + 1], src: &v46[v44], count: 4 * v47);
            v48 = &pGameType->m_GameModes.m_Memory.m_pMemory[v44];
            if ( v48 != nullptr )
              *v48 = pGameMode;
            FirstTrueSubKey = pKV_GameType;
            NextTrueSubKey = KeyValues::GetNextTrueSubKey(this: NextTrueSubKey);
          }
          while ( NextTrueSubKey != nullptr );
          v6 = pGameType;
        }
      }
      else
      {
        v55 = KeyValues::GetName(this: FirstTrueSubKey);
        _Warning(a1: "GameTypes: missing %s entry for game type %s.\n", "gameModes", v55);
      }
      if ( v6->m_GameModes.m_Size == 0 )
      {
        v49 = KeyValues::GetName(this: FirstTrueSubKey);
        _Warning(a1: "GameTypes: empty %s entry for game type %s.\n", "gameModes", v49);
      }
      v6->m_Index = this->m_GameTypes.m_Size;
      v50 = this->m_GameTypes.m_Size;
      v51 = this->m_GameTypes.m_Memory.m_nAllocationCount;
      if ( v50 + 1 > v51 )
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_GameTypes,
          num: v50 - v51 + 1);
      ++this->m_GameTypes.m_Size;
      v52 = this->m_GameTypes.m_Memory.m_pMemory;
      v53 = this->m_GameTypes.m_Size - v50 - 1;
      this->m_GameTypes.m_pElements = v52;
      if ( v53 > 0 )
        _V_memmove(dest: &v52[v50 + 1], src: &v52[v50], count: 4 * v53);
      v54 = &this->m_GameTypes.m_Memory.m_pMemory[v50];
      if ( v54 != nullptr )
        *v54 = v6;
      pKV_GameType = KeyValues::GetNextTrueSubKey(this: pKV_GameType);
      if ( pKV_GameType == nullptr )
        break;
      FirstTrueSubKey = pKV_GameType;
    }
  }
  if ( this->m_GameTypes.m_Size == 0 )
    _Warning(a1: "GameTypes: empty %s entry.\n", "gameTypes");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102A34D0
// Name: public: virtual bool GameTypes::Initialize(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameTypes::Initialize(GameTypes *this, bool force)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IBaseFileSystem *v6; // eax

  if ( this->m_Initialized && !force )
    return 1;
  DevMsg(a1: "GameTypes: initializing game types interface from %s.\n", "GameModes.txt");
  CUtlVector<GameTypes::GameType *,CUtlMemory<GameTypes::GameType *,int>>::PurgeAndDeleteElements(this: &this->m_GameTypes);
  CUtlVector<GameTypes::Map *,CUtlMemory<GameTypes::Map *,int>>::PurgeAndDeleteElements(this: &this->m_Maps);
  CUtlVector<GameTypes::FreestyleBotDifficulty *,CUtlMemory<GameTypes::FreestyleBotDifficulty *,int>>::PurgeAndDeleteElements(this: &this->m_FreestyleBotDifficulties);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: locale);
  else
    v5 = nullptr;
  if ( g_pFullFileSystem != nullptr )
    v6 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v6 = nullptr;
  if ( !KeyValues::LoadFromFile(
          this: v5,
          filesystem: v6,
          resourceName: "GameModes.txt",
          pathID: nullptr,
          pfnEvaluateSymbolProc: nullptr) )
  {
    _Warning(a1: "GameTypes: error loading %s.", "GameModes.txt");
    goto LABEL_12;
  }
  DLCHelper::AppendDLCKeyValues(pKeyValues: v5, fileName: "GameModes.txt", startDir: nullptr);
  if ( GameTypes::LoadGameTypes(this, pKV: v5) == 0
    || GameTypes::LoadMaps(this, pKV: v5) == 0
    || GameTypes::LoadFreestyleBotDifficulties(this, pKV: v5) == 0 )
  {
LABEL_12:
    if ( v5 != nullptr )
      KeyValues::deleteThis(this: v5);
    return 0;
  }
  this->m_Initialized = true;
  if ( v5 != nullptr )
    KeyValues::deleteThis(this: v5);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102A1230
// Name: __CreateGameTypesIGameTypes_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
GameTypes *__cdecl _CreateGameTypesIGameTypes_interface()
{
  return &s_GameTypes;
}

} // namespace server

// ============================================================
// Overlay from matchmaking (Missing functions)
// ============================================================
namespace matchmaking {

//------------------------------------------------------------------------------
// Address: 0x10001D30
// Name: public: int CUtlVector<int,class CUtlMemory<int,int>>::InsertBefore(int,int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<int,CUtlMemory<int,int>>::InsertBefore(
        CUtlVector<int,CUtlMemory<int,int> > *this,
        int elem,
        int *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int *m_pMemory; // ecx
  int v7; // eax
  int *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<GCSDK::CLock *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 4 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10001DA0
// Name: public: int CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::InsertBefore(int,class CUtlString const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this,
        int elem,
        const CUtlString *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlString *m_pMemory; // ecx
  int v7; // eax
  CUtlString *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CMatchSearcher::SearchResult_t,int>::Grow(
      (CUtlMemory<CMatchSearcher::SearchResult_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    CUtlString::CUtlString(this: v8, string: src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10001E10
// Name: public: void CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CUtlString *v3; // esi
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v3->m_Storage.m_nActualLength = 0;
      if ( v3->m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001E80
// Name: public: void CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::Purge(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  CUtlString *m_pMemory; // ecx

  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001EC0
// Name: public: CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::~CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  bool v2; // sf
  CUtlString *m_pMemory; // eax

  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002980
// Name: public: static unsigned __int64 DLCHelper::GetInstalledDLCMask(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl DLCHelper::GetInstalledDLCMask()
{
  int (__thiscall *IsAnyDLCPresent)(IFileSystem *, bool *); // eax
  int v1; // edi
  int v2; // esi
  __int64 v3; // kr00_8
  __int64 uiDlcHeader; // [esp+Ch] [ebp-Ch] BYREF
  bool bSearchPath; // [esp+17h] [ebp-1h] BYREF

  bSearchPath = false;
  IsAnyDLCPresent = g_pFullFileSystem->IsAnyDLCPresent;
  uiDlcHeader = 0;
  v1 = IsAnyDLCPresent(this: g_pFullFileSystem, a2: &bSearchPath);
  if ( !bSearchPath )
    g_pFullFileSystem->AddDLCSearchPaths(this: g_pFullFileSystem);
  v2 = 0;
  if ( v1 <= 0 )
    return uiDlcHeader;
  v3 = uiDlcHeader;
  do
  {
    HIDWORD(uiDlcHeader) = 0;
    if ( g_pFullFileSystem->GetAnyDLCInfo(
           this: g_pFullFileSystem,
           a2: v2,
           a3: (unsigned int *)((char *)&uiDlcHeader + 4),
           a4: nullptr,
           a5: 0)
      && (unsigned int)(HIBYTE(HIDWORD(uiDlcHeader)) - 1) <= 0x1D )
    {
      v3 |= 1LL << SHIBYTE(uiDlcHeader);
    }
    ++v2;
  }
  while ( v2 < v1 );
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10002A30
// Name: public: static void DLCHelper::AppendDLCKeyValues(class KeyValues __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DLCHelper::AppendDLCKeyValues(KeyValues *pKeyValues, const char *fileName, const char *startDir)
{
  unsigned __int64 v3; // rax
  KeyValues *v4; // eax
  KeyValues *v5; // ebx
  int v6; // eax
  int v7; // esi
  bool v8; // zf
  int v9; // edi
  IBaseFileSystem *v10; // eax
  unsigned int v11; // et0
  char dlcFileName[128]; // [esp+0h] [ebp-94h] BYREF
  unsigned __int64 i; // [esp+80h] [ebp-14h]
  const char *extension; // [esp+88h] [ebp-Ch]
  unsigned __int64 installedDlc; // [esp+8Ch] [ebp-8h]

  LODWORD(v3) = DLCHelper::GetInstalledDLCMask();
  installedDlc = v3;
  if ( v3 != 0 )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: defaultValue);
    else
      v5 = nullptr;
    memset(dlcFileName, 0, sizeof(dlcFileName));
    v6 = _V_strlen(str: fileName);
    v7 = v6 - 1;
    v8 = v6 == 1;
    if ( v6 - 1 > 0 )
    {
      do
      {
        if ( fileName[v7] == 46 )
          break;
        --v7;
      }
      while ( v7 > 0 );
      v8 = v7 == 0;
    }
    if ( v8 )
    {
      _Warning(a1: "Invalid file name passed to DLCHelper::AppendDLCKeyValues (%s)\n", fileName);
    }
    else
    {
      extension = &fileName[v7 + 1];
      V_strncpy(pDest: dlcFileName, pSrc: fileName, maxLen: 128);
      v9 = 1;
      HIDWORD(i) = 0;
      do
      {
        if ( (installedDlc & (1LL << v9)) != 0 )
        {
          V_snprintf(pDest: &dlcFileName[v7], maxLen: 128 - v7, pFormat: "_dlc%d.%s", v9, extension);
          KeyValues::Clear(this: v5);
          if ( g_pFullFileSystem != nullptr )
            v10 = &g_pFullFileSystem->IBaseFileSystem;
          else
            v10 = nullptr;
          if ( KeyValues::LoadFromFile(
                 this: v5,
                 filesystem: v10,
                 resourceName: dlcFileName,
                 pathID: startDir,
                 pfnEvaluateSymbolProc: nullptr) )
          {
            KeyValues::MergeFrom(this: pKeyValues, kvMerge: v5, eOp: MERGE_KV_UPDATE);
          }
          else
          {
            _Warning(a1: "Failed to load %s\n", dlcFileName);
          }
        }
        v11 = (__PAIR64__(HIDWORD(i), v9++) + 1) >> 32;
        HIDWORD(i) = v11;
      }
      while ( __PAIR64__(v11, v9) < 0x40 );
      if ( v5 != nullptr )
        KeyValues::deleteThis(this: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002BB0
// Name: public: virtual bool GameTypes::SetGameTypeAndMode(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameTypes::SetGameTypeAndMode(GameTypes *this, const char *gameType, const char *gameMode)
{
  int iMode; // [esp+8h] [ebp-8h] BYREF
  int iType; // [esp+Ch] [ebp-4h] BYREF

  iType = -1;
  iMode = -1;
  if ( this->GetGameModeAndTypeIntsFromStrings(this, a2: gameType, a3: gameMode, a4: &iType, a5: &iMode) )
  {
    DevMsg(a1: "GameTypes: setting game type to %s:%d.\n", gameType, iType);
    ConVar::SetValue(this: (ConVar *)&game_type.IConVar, value: iType);
    DevMsg(a1: "GameTypes: setting game mode to %s:%d.\n", gameMode, iMode);
    ConVar::SetValue(this: (ConVar *)&game_mode.IConVar, value: iMode);
    return 1;
  }
  else
  {
    _Warning(
      a1: "GamesTypes: unable to set game type and mode. Could not find type/mode matching type:%s/mode:%s.\n",
      gameType,
      gameMode);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002C40
// Name: public: virtual int GameTypes::GetCurrentGameType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GameTypes::GetCurrentGameType(GameTypes *this)
{
  if ( game_type.m_pParent != nullptr )
    return game_type.m_pParent->m_Value.m_nValue;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10002C50
// Name: public: virtual int GameTypes::GetCurrentGameMode(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GameTypes::GetCurrentGameMode(GameTypes *this)
{
  if ( game_mode.m_pParent != nullptr )
    return game_mode.m_pParent->m_Value.m_nValue;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10002C60
// Name: private: void GameTypes::DisplayConvars(class KeyValues __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GameTypes::DisplayConvars(GameTypes *this, KeyValues *pKV_Convars, const char *title)
{
  KeyValues *i; // esi
  const char *Name; // eax
  char *m_pszString; // edi
  const char *v6; // eax
  const char *String; // [esp-Ch] [ebp-18h]
  ConVarRef conVarRef; // [esp+4h] [ebp-8h] BYREF

  if ( pKV_Convars != nullptr && title != nullptr )
  {
    ConMsg(a1: "%s\n{\n", title);
    for ( i = KeyValues::GetFirstValue(this: pKV_Convars); i != nullptr; i = KeyValues::GetNextValue(this: i) )
    {
      Name = KeyValues::GetName(this: i);
      ConVarRef::ConVarRef(this: &conVarRef, pName: Name);
      m_pszString = conVarRef.m_pConVarState->m_Value.m_pszString;
      String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
      v6 = KeyValues::GetName(this: i);
      ConMsg(a1: "\t\"%s\": current value (\"%s\"), expected value (\"%s\")\n", v6, m_pszString, String);
    }
    ConMsg(a1: "}\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002CF0
// Name: public: virtual int GameTypes::GetFreestyleBotDifficulty(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GameTypes::GetFreestyleBotDifficulty(GameTypes *this)
{
  if ( freestyle_bot_difficulty.m_pParent != nullptr )
    return freestyle_bot_difficulty.m_pParent->m_Value.m_nValue;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10002D00
// Name: void DisplayGameModeConvars(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DisplayGameModeConvars()
{
  if ( g_pGameTypes != nullptr )
    g_pGameTypes->DisplayConvarsForCurrentMode(this: g_pGameTypes);
}

//------------------------------------------------------------------------------
// Address: 0x10002D20
// Name: public: virtual bool GameTypes::SetFreestyleBotDifficulty(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameTypes::SetFreestyleBotDifficulty(GameTypes *this, int botDiff)
{
  if ( botDiff < 0 || botDiff >= this->m_FreestyleBotDifficulties.m_Size )
  {
    _Warning(
      a1: "GameTypes: invalid freestyle bot difficulty (%d). Range [%d,%d].\n",
      botDiff,
      0,
      this->m_FreestyleBotDifficulties.m_Size - 1);
    return 0;
  }
  else
  {
    DevMsg(a1: "GameTypes: setting freestyle_bot_difficulty to %d.\n", botDiff);
    ConVar::SetValue(this: (ConVar *)&freestyle_bot_difficulty.IConVar, value: botDiff);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002D70
// Name: public: void CUtlMemory<struct IGameTypes::WeaponProgression,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<IGameTypes::WeaponProgression,int>::Grow(
        CUtlMemory<IGameTypes::WeaponProgression,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  IGameTypes::WeaponProgression *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 2;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 20 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (IGameTypes::WeaponProgression *)_g_pMemAlloc->Realloc_2(
                                                           this: _g_pMemAlloc,
                                                           a2: m_pMemory,
                                                           a3: v7);
    else
      this->m_pMemory = (IGameTypes::WeaponProgression *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002E10
// Name: private: struct GameTypes::GameType __near * GameTypes::GetGameType_Internal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
GameTypes::GameType *__thiscall GameTypes::GetGameType_Internal(GameTypes *this, const char *gameType)
{
  const char *v2; // eax
  int v4; // edi
  GameTypes::GameType *v5; // esi

  v2 = gameType;
  if ( gameType != nullptr && *gameType != 0 && (v4 = 0, this->m_GameTypes.m_Size > 0) )
  {
    while ( 1 )
    {
      v5 = this->m_GameTypes.m_Memory.m_pMemory[v4];
      if ( v5 != nullptr && _V_stricmp(s1: v5->m_Name, s2: gameType) == 0 )
        return v5;
      if ( ++v4 >= this->m_GameTypes.m_Size )
      {
        v2 = gameType;
        goto LABEL_8;
      }
    }
  }
  else
  {
LABEL_8:
    _Warning(a1: "GameTypes: could not find matching game type \"%s\".\n", v2);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002E80
// Name: private: struct GameTypes::GameMode __near * GameTypes::GetGameMode_Internal(struct GameTypes::GameType __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
GameTypes::GameMode *__thiscall GameTypes::GetGameMode_Internal(
        GameTypes *this,
        GameTypes::GameType *pGameType,
        const char *gameMode)
{
  int v3; // edi
  GameTypes::GameMode *v4; // esi
  char *m_Name; // ebx

  if ( pGameType == nullptr )
  {
    m_Name = "null";
    goto LABEL_11;
  }
  if ( gameMode == nullptr || *gameMode == 0 || (v3 = 0, pGameType->m_GameModes.m_Size <= 0) )
  {
LABEL_8:
    m_Name = pGameType->m_Name;
LABEL_11:
    _Warning(a1: "GameTypes: could not find matching game mode \"%s\" for type \"%s\".\n", gameMode, m_Name);
    return nullptr;
  }
  while ( 1 )
  {
    v4 = pGameType->m_GameModes.m_Memory.m_pMemory[v3];
    if ( v4 != nullptr && _V_stricmp(s1: v4->m_Name, s2: gameMode) == 0 )
      return v4;
    if ( ++v3 >= pGameType->m_GameModes.m_Size )
      goto LABEL_8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002F10
// Name: private: struct GameTypes::Map __near * GameTypes::GetMap_Internal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
GameTypes::Map *__thiscall GameTypes::GetMap_Internal(GameTypes *this, const char *mapName)
{
  int v4; // eax
  char *v5; // esi
  int v6; // eax
  char *v7; // esi
  int v8; // esi
  GameTypes::Map *v9; // edi
  char mapNameNoExt[36]; // [esp+4h] [ebp-24h] BYREF

  if ( this->m_Maps.m_Size != 0 )
  {
    if ( mapName != nullptr && *mapName != 0 )
    {
      V_strncpy(pDest: mapNameNoExt, pSrc: mapName, maxLen: 33);
      v4 = _V_strlen(str: mapNameNoExt);
      v5 = &mapNameNoExt[v4 - 4];
      if ( v5 >= mapNameNoExt && V_strnicmp(s1: &mapNameNoExt[v4 - 4], s2: ".360", n: 4) == 0 )
        *v5 = 0;
      v6 = _V_strlen(str: mapNameNoExt);
      v7 = &mapNameNoExt[v6 - 4];
      if ( v7 >= mapNameNoExt && V_strnicmp(s1: &mapNameNoExt[v6 - 4], s2: ".bsp", n: 4) == 0 )
        *v7 = 0;
      v8 = 0;
      if ( this->m_Maps.m_Size <= 0 )
      {
LABEL_15:
        _Warning(a1: "GameTypes: could not find matching map \"%s\".\n", mapNameNoExt);
        return nullptr;
      }
      else
      {
        while ( 1 )
        {
          v9 = this->m_Maps.m_Memory.m_pMemory[v8];
          if ( v9 != nullptr && _V_stricmp(s1: v9->m_Name, s2: mapNameNoExt) == 0 )
            return v9;
          if ( ++v8 >= this->m_Maps.m_Size )
            goto LABEL_15;
        }
      }
    }
    else
    {
      _Warning(a1: "GamesTypes: invalid map name.\n");
      return nullptr;
    }
  }
  else
  {
    _Warning(a1: "GamesTypes: no maps have been loaded.\n");
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003030
// Name: private: struct GameTypes::FreestyleBotDifficulty __near * GameTypes::GetCurrentFreestyleBotDifficulty_Internal(void)
// Source: json
//------------------------------------------------------------------------------
GameTypes::FreestyleBotDifficulty *__thiscall GameTypes::GetCurrentFreestyleBotDifficulty_Internal(GameTypes *this)
{
  int m_Size; // edx
  int m_nValue; // eax

  m_Size = this->m_FreestyleBotDifficulties.m_Size;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no freestyle bot difficulties have been loaded.\n");
    return nullptr;
  }
  if ( freestyle_bot_difficulty.m_pParent != nullptr )
  {
    m_nValue = freestyle_bot_difficulty.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
      goto LABEL_8;
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue < m_Size )
    return this->m_FreestyleBotDifficulties.m_Memory.m_pMemory[m_nValue];
LABEL_8:
  _Warning(
    a1: "GamesTypes: freestyle_bot_difficulty is set to an invalid value (%d). Range [%d,%d].\n",
    m_nValue,
    0,
    m_Size - 1);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10003080
// Name: public: virtual char const __near * GameTypes::GetCurrentGameTypeNameID(void)
// Source: json
//------------------------------------------------------------------------------
GameTypes::GameType *__thiscall GameTypes::GetCurrentGameTypeNameID(GameTypes *this)
{
  int m_Size; // edx
  GameTypes::GameType *result; // eax
  int m_nValue; // eax

  m_Size = this->m_GameTypes.m_Size;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no game types have been loaded.\n");
    return nullptr;
  }
  if ( game_type.m_pParent != nullptr )
  {
    m_nValue = game_type.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
    {
LABEL_9:
      _Warning(a1: "GamesTypes: game_type is set to an invalid value (%d). Range [%d,%d].\n", m_nValue, 0, m_Size - 1);
      return nullptr;
    }
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue >= m_Size )
    goto LABEL_9;
  result = this->m_GameTypes.m_Memory.m_pMemory[m_nValue];
  if ( result != nullptr )
    return (GameTypes::GameType *)((char *)result + 36);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100030E0
// Name: public: virtual char const __near * GameTypes::GetCurrentGameModeNameID(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall GameTypes::GetCurrentGameModeNameID(GameTypes *this)
{
  int m_Size; // edx
  int m_nValue; // eax
  GameTypes::GameType *v4; // ecx
  int v5; // eax
  GameTypes::GameMode *v6; // eax

  m_Size = this->m_GameTypes.m_Size;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no game types have been loaded.\n");
    return nullptr;
  }
  if ( game_type.m_pParent != nullptr )
  {
    m_nValue = game_type.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
    {
LABEL_9:
      _Warning(a1: "GamesTypes: game_type is set to an invalid value (%d). Range [%d,%d].\n", m_nValue, 0, m_Size - 1);
      return nullptr;
    }
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue >= m_Size )
    goto LABEL_9;
  v4 = this->m_GameTypes.m_Memory.m_pMemory[m_nValue];
  if ( v4 == nullptr )
    return nullptr;
  if ( game_mode.m_pParent != nullptr )
  {
    v5 = game_mode.m_pParent->m_Value.m_nValue;
    if ( v5 < 0 )
    {
LABEL_16:
      _Warning(
        a1: "GamesTypes: game_mode is set to an invalid value (%d). Range [%d,%d].\n",
        v5,
        0,
        v4->m_GameModes.m_Size - 1);
      return nullptr;
    }
  }
  else
  {
    v5 = 0;
  }
  if ( v5 >= v4->m_GameModes.m_Size )
    goto LABEL_16;
  v6 = v4->m_GameModes.m_Memory.m_pMemory[v5];
  if ( v6 == nullptr )
    return nullptr;
  return v6->m_NameID;
}

//------------------------------------------------------------------------------
// Address: 0x10003180
// Name: public: virtual bool GameTypes::ApplyConvarsForCurrentMode(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameTypes::ApplyConvarsForCurrentMode(GameTypes *this, bool isMultiplayer)
{
  int m_Size; // ecx
  int m_nValue; // eax
  GameTypes::GameType *v6; // edx
  int v7; // eax
  GameTypes::GameMode *v8; // ebx
  KeyValues *m_pConvarsSP; // edi
  int v10; // ecx
  int v11; // eax
  KeyValues *i; // esi
  const char *Name; // eax
  const char *String; // eax
  int v15; // ecx
  int v16; // eax
  GameTypes *v17; // esi
  GameTypes::FreestyleBotDifficulty *CurrentFreestyleBotDifficulty_Internal; // eax
  GameTypes::FreestyleBotDifficulty *v19; // ebx
  KeyValues *m_pConvars; // edi
  KeyValues *j; // esi
  const char *v22; // eax
  const char *v23; // eax
  int v24; // eax
  int v25; // eax
  ConVarRef conVarRef; // [esp+4h] [ebp-18h] BYREF
  IKeyValuesDumpContext v27; // [esp+Ch] [ebp-10h] BYREF
  GameTypes *v28; // [esp+10h] [ebp-Ch]
  IKeyValuesDumpContext pDump; // [esp+14h] [ebp-8h] BYREF
  GameTypes::GameType *pGameType; // [esp+18h] [ebp-4h]

  m_Size = this->m_GameTypes.m_Size;
  v28 = this;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no game types have been loaded.\n");
    return 0;
  }
  if ( game_type.m_pParent != nullptr )
  {
    m_nValue = game_type.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
    {
LABEL_9:
      _Warning(a1: "GamesTypes: game_type is set to an invalid value (%d). Range [%d,%d].\n", m_nValue, 0, m_Size - 1);
      return 0;
    }
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue >= m_Size )
    goto LABEL_9;
  v6 = this->m_GameTypes.m_Memory.m_pMemory[m_nValue];
  pGameType = v6;
  if ( v6 == nullptr )
    return 0;
  if ( game_mode.m_pParent != nullptr )
  {
    v7 = game_mode.m_pParent->m_Value.m_nValue;
    if ( v7 < 0 )
    {
LABEL_20:
      _Warning(
        a1: "GamesTypes: game_mode is set to an invalid value (%d). Range [%d,%d].\n",
        v7,
        0,
        v6->m_GameModes.m_Size - 1);
      return 0;
    }
  }
  else
  {
    v7 = 0;
  }
  if ( v7 >= v6->m_GameModes.m_Size )
    goto LABEL_20;
  v8 = v6->m_GameModes.m_Memory.m_pMemory[v7];
  if ( v8 == nullptr )
    return 0;
  if ( !isMultiplayer || (m_pConvarsSP = v8->m_pConvarsMP) == nullptr )
  {
    m_pConvarsSP = v8->m_pConvarsSP;
    if ( m_pConvarsSP == nullptr )
    {
      if ( game_mode.m_pParent != nullptr )
        v10 = game_mode.m_pParent->m_Value.m_nValue;
      else
        v10 = 0;
      if ( game_type.m_pParent != nullptr )
        v11 = game_type.m_pParent->m_Value.m_nValue;
      else
        v11 = 0;
      _Warning(
        a1: "GamesTypes: unable to set convars. There are no convars for game type/mode (%s:%d/%s:%d).\n",
        v6->m_Name,
        v11,
        v8->m_Name,
        v10);
      return 0;
    }
  }
  for ( i = KeyValues::GetFirstValue(this: m_pConvarsSP); i != nullptr; i = KeyValues::GetNextValue(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    ConVarRef::ConVarRef(this: &conVarRef, pName: Name);
    String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: defaultValue);
    conVarRef.m_pConVar->SetValue_4(this: conVarRef.m_pConVar, a2: String);
  }
  if ( game_mode.m_pParent != nullptr )
    v15 = game_mode.m_pParent->m_Value.m_nValue;
  else
    v15 = 0;
  if ( game_type.m_pParent != nullptr )
    v16 = game_type.m_pParent->m_Value.m_nValue;
  else
    v16 = 0;
  DevMsg(a1: "GameTypes: set convars for game type/mode (%s:%d/%s:%d):\n", pGameType->m_Name, v16, v8->m_Name, v15);
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  pGameType = (GameTypes::GameType *)1;
  KeyValues::Dump(this: m_pConvarsSP, &pDump, nIndentLevel: 1);
  v17 = v28;
  if ( v28->GetCurrentGameMode(this: v28) != 2 )
    return 1;
  if ( v17->GetCurrentGameType(this: v17) != 0 )
    return 1;
  CurrentFreestyleBotDifficulty_Internal = GameTypes::GetCurrentFreestyleBotDifficulty_Internal(this: v17);
  v19 = CurrentFreestyleBotDifficulty_Internal;
  if ( CurrentFreestyleBotDifficulty_Internal == nullptr )
    return 1;
  m_pConvars = CurrentFreestyleBotDifficulty_Internal->m_pConvars;
  if ( m_pConvars == nullptr )
  {
    if ( freestyle_bot_difficulty.m_pParent != nullptr )
      v25 = freestyle_bot_difficulty.m_pParent->m_Value.m_nValue;
    else
      v25 = 0;
    _Warning(
      a1: "GamesTypes: unable to set freestyle bot difficulty convars. There are no convars for bot difficulty (%s:%d).\n",
      v19->m_Name,
      v25);
    return 1;
  }
  for ( j = KeyValues::GetFirstValue(this: CurrentFreestyleBotDifficulty_Internal->m_pConvars);
        j != nullptr;
        j = KeyValues::GetNextValue(this: j) )
  {
    v22 = KeyValues::GetName(this: j);
    ConVarRef::ConVarRef(this: &conVarRef, pName: v22);
    v23 = KeyValues::GetString(this: j, keyName: nullptr, defaultValue: defaultValue);
    conVarRef.m_pConVar->SetValue_4(this: conVarRef.m_pConVar, a2: v23);
  }
  if ( freestyle_bot_difficulty.m_pParent != nullptr )
    v24 = freestyle_bot_difficulty.m_pParent->m_Value.m_nValue;
  else
    v24 = 0;
  DevMsg(a1: "GameTypes: set convars for freestyle bot difficulty (%s:%d):\n", v19->m_Name, v24);
  v27.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  v28 = (GameTypes *)1;
  KeyValues::Dump(this: m_pConvars, pDump: &v27, nIndentLevel: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10003420
// Name: public: virtual void GameTypes::DisplayConvarsForCurrentMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GameTypes::DisplayConvarsForCurrentMode(GameTypes *this)
{
  GameTypes *v1; // edx
  int m_Size; // esi
  int m_nValue; // eax
  GameTypes::GameType *v4; // ebx
  ConVar *m_pParent; // ecx
  int v6; // eax
  GameTypes::GameMode *v7; // esi
  KeyValues *m_pConvarsSP; // edi
  int v9; // ecx
  int v10; // eax
  KeyValues *m_pConvarsMP; // edi
  int v12; // ecx
  int v13; // eax
  GameTypes *v14; // edi
  GameTypes::FreestyleBotDifficulty *CurrentFreestyleBotDifficulty_Internal; // eax
  KeyValues *m_pConvars; // esi
  int v17; // ecx
  char title[256]; // [esp+4h] [ebp-104h] BYREF
  GameTypes *v19; // [esp+104h] [ebp-4h]

  v1 = this;
  m_Size = this->m_GameTypes.m_Size;
  v19 = this;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no game types have been loaded.\n");
    return;
  }
  if ( game_type.m_pParent != nullptr )
  {
    m_nValue = game_type.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
    {
LABEL_15:
      _Warning(a1: "GamesTypes: game_type is set to an invalid value (%d). Range [%d,%d].\n", m_nValue, 0, m_Size - 1);
      return;
    }
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue >= m_Size )
    goto LABEL_15;
  v4 = this->m_GameTypes.m_Memory.m_pMemory[m_nValue];
  if ( v4 == nullptr )
    return;
  m_pParent = game_mode.m_pParent;
  if ( game_mode.m_pParent != nullptr )
  {
    v6 = game_mode.m_pParent->m_Value.m_nValue;
    if ( v6 < 0 )
    {
LABEL_17:
      _Warning(
        a1: "GamesTypes: game_mode is set to an invalid value (%d). Range [%d,%d].\n",
        v6,
        0,
        v4->m_GameModes.m_Size - 1);
      return;
    }
  }
  else
  {
    v6 = 0;
  }
  if ( v6 >= v4->m_GameModes.m_Size )
    goto LABEL_17;
  v7 = v4->m_GameModes.m_Memory.m_pMemory[v6];
  if ( v7 != nullptr )
  {
    m_pConvarsSP = v7->m_pConvarsSP;
    if ( m_pConvarsSP != nullptr )
    {
      if ( game_mode.m_pParent != nullptr )
        v9 = game_mode.m_pParent->m_Value.m_nValue;
      else
        v9 = 0;
      if ( game_type.m_pParent != nullptr )
        v10 = game_type.m_pParent->m_Value.m_nValue;
      else
        v10 = 0;
      V_snprintf(
        pDest: title,
        maxLen: 256,
        pFormat: "GameTypes: dumping convars for game type/mode (%s:%d/%s:%d):",
        v4->m_Name,
        v10,
        v7->m_Name,
        v9);
      GameTypes::DisplayConvars(this: v19, pKV_Convars: m_pConvarsSP, title);
      m_pParent = game_mode.m_pParent;
      v1 = v19;
    }
    m_pConvarsMP = v7->m_pConvarsMP;
    if ( m_pConvarsMP != nullptr )
    {
      if ( m_pParent != nullptr )
        v12 = m_pParent->m_Value.m_nValue;
      else
        v12 = 0;
      if ( game_type.m_pParent != nullptr )
        v13 = game_type.m_pParent->m_Value.m_nValue;
      else
        v13 = 0;
      V_snprintf(
        pDest: title,
        maxLen: 256,
        pFormat: "GameTypes: dumping multiplayer convars for game type/mode (%s:%d/%s:%d):",
        v4->m_Name,
        v13,
        v7->m_Name,
        v12);
      GameTypes::DisplayConvars(this: v19, pKV_Convars: m_pConvarsMP, title);
      v1 = v19;
    }
    if ( v1->GetCurrentGameMode(this: v1) == 2 )
    {
      v14 = v19;
      if ( v19->GetCurrentGameType(this: v19) == 0 )
      {
        CurrentFreestyleBotDifficulty_Internal = GameTypes::GetCurrentFreestyleBotDifficulty_Internal(this: v14);
        if ( CurrentFreestyleBotDifficulty_Internal != nullptr )
        {
          m_pConvars = CurrentFreestyleBotDifficulty_Internal->m_pConvars;
          if ( m_pConvars != nullptr )
          {
            if ( freestyle_bot_difficulty.m_pParent != nullptr )
              v17 = freestyle_bot_difficulty.m_pParent->m_Value.m_nValue;
            else
              v17 = 0;
            V_snprintf(
              pDest: title,
              maxLen: 256,
              pFormat: "GameTypes: dumping convars for freestyle bot difficulty (%s:%d):",
              CurrentFreestyleBotDifficulty_Internal->m_Name,
              v17);
            GameTypes::DisplayConvars(this: v14, pKV_Convars: m_pConvars, title);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003600
// Name: public: virtual class CUtlVector<struct IGameTypes::WeaponProgression,class CUtlMemory<struct IGameTypes::WeaponProgression,int>> const __near * GameTypes::GetWeaponProgressionForCurrentModeCT(void)
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int> > *__thiscall GameTypes::GetWeaponProgressionForCurrentModeCT(
        GameTypes *this)
{
  int m_Size; // edx
  int m_nValue; // eax
  GameTypes::GameType *v4; // ecx
  int v5; // eax
  GameTypes::GameMode *v6; // eax

  m_Size = this->m_GameTypes.m_Size;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no game types have been loaded.\n");
    return nullptr;
  }
  if ( game_type.m_pParent != nullptr )
  {
    m_nValue = game_type.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
    {
LABEL_9:
      _Warning(a1: "GamesTypes: game_type is set to an invalid value (%d). Range [%d,%d].\n", m_nValue, 0, m_Size - 1);
      return nullptr;
    }
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue >= m_Size )
    goto LABEL_9;
  v4 = this->m_GameTypes.m_Memory.m_pMemory[m_nValue];
  if ( v4 == nullptr )
    return nullptr;
  if ( game_mode.m_pParent != nullptr )
  {
    v5 = game_mode.m_pParent->m_Value.m_nValue;
    if ( v5 < 0 )
    {
LABEL_16:
      _Warning(
        a1: "GamesTypes: game_mode is set to an invalid value (%d). Range [%d,%d].\n",
        v5,
        0,
        v4->m_GameModes.m_Size - 1);
      return nullptr;
    }
  }
  else
  {
    v5 = 0;
  }
  if ( v5 >= v4->m_GameModes.m_Size )
    goto LABEL_16;
  v6 = v4->m_GameModes.m_Memory.m_pMemory[v5];
  if ( v6 == nullptr )
    return nullptr;
  return &v6->m_WeaponProgressionCT;
}

//------------------------------------------------------------------------------
// Address: 0x100036A0
// Name: public: virtual class CUtlVector<struct IGameTypes::WeaponProgression,class CUtlMemory<struct IGameTypes::WeaponProgression,int>> const __near * GameTypes::GetWeaponProgressionForCurrentModeT(void)
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int> > *__thiscall GameTypes::GetWeaponProgressionForCurrentModeT(
        GameTypes *this)
{
  int m_Size; // edx
  int m_nValue; // eax
  GameTypes::GameType *v4; // ecx
  int v5; // eax
  GameTypes::GameMode *v6; // eax

  m_Size = this->m_GameTypes.m_Size;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no game types have been loaded.\n");
    return nullptr;
  }
  if ( game_type.m_pParent != nullptr )
  {
    m_nValue = game_type.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
    {
LABEL_9:
      _Warning(a1: "GamesTypes: game_type is set to an invalid value (%d). Range [%d,%d].\n", m_nValue, 0, m_Size - 1);
      return nullptr;
    }
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue >= m_Size )
    goto LABEL_9;
  v4 = this->m_GameTypes.m_Memory.m_pMemory[m_nValue];
  if ( v4 == nullptr )
    return nullptr;
  if ( game_mode.m_pParent != nullptr )
  {
    v5 = game_mode.m_pParent->m_Value.m_nValue;
    if ( v5 < 0 )
    {
LABEL_16:
      _Warning(
        a1: "GamesTypes: game_mode is set to an invalid value (%d). Range [%d,%d].\n",
        v5,
        0,
        v4->m_GameModes.m_Size - 1);
      return nullptr;
    }
  }
  else
  {
    v5 = 0;
  }
  if ( v5 >= v4->m_GameModes.m_Size )
    goto LABEL_16;
  v6 = v4->m_GameModes.m_Memory.m_pMemory[v5];
  if ( v6 == nullptr )
    return nullptr;
  return &v6->m_WeaponProgressionT;
}

//------------------------------------------------------------------------------
// Address: 0x10003740
// Name: public: virtual char const __near * GameTypes::GetRandomMap(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char *__thiscall GameTypes::GetRandomMap(GameTypes *this, const char *gameType, const char *gameMode)
{
  GameTypes::GameType *GameType_Internal; // eax
  GameTypes::GameMode *GameMode_Internal; // eax
  IUniformRandomStream *v6; // ecx
  GameTypes::GameMode *v7; // esi
  int m_Size; // eax

  if ( gameType != nullptr
    && gameMode != nullptr
    && (GameType_Internal = GameTypes::GetGameType_Internal(this, gameType)) != nullptr
    && (GameMode_Internal = GameTypes::GetGameMode_Internal(this, pGameType: GameType_Internal, gameMode),
        v7 = GameMode_Internal,
        GameMode_Internal != nullptr)
    && (m_Size = GameMode_Internal->m_Maps.m_Size) != 0 )
  {
    return v7->m_Maps.m_Memory.m_pMemory[_RandomInt(this: v6, a2: 0, a3: m_Size - 1)];
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100037A0
// Name: public: virtual bool GameTypes::ApplyConvarsForMap(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameTypes::ApplyConvarsForMap(GameTypes *this, const char *mapName)
{
  GameTypes::Map *Map_Internal; // edi
  GameTypes::FreestyleBotDifficulty *CurrentFreestyleBotDifficulty_Internal; // eax
  ConVarRef bot_quota; // [esp+Ch] [ebp-8h] BYREF

  Map_Internal = GameTypes::GetMap_Internal(this, mapName);
  if ( Map_Internal != nullptr )
  {
    if ( this->GetCurrentGameMode(this) != 2
      || this->GetCurrentGameType(this) != 0
      || (CurrentFreestyleBotDifficulty_Internal = GameTypes::GetCurrentFreestyleBotDifficulty_Internal(this)) == nullptr
      || !CurrentFreestyleBotDifficulty_Internal->m_HasBotQuota )
    {
      DevMsg(a1: "GameTypes: setting bot_quota to %d for map %s.\n", Map_Internal->m_MinPlayers, Map_Internal->m_Name);
      ConVarRef::ConVarRef(this: &bot_quota, pName: "bot_quota");
      bot_quota.m_pConVar->SetValue_2(this: bot_quota.m_pConVar, a2: Map_Internal->m_MinPlayers);
    }
    return 1;
  }
  else
  {
    _Warning(a1: "GamesTypes: unable to set convars for map %s. Could not find matching map name.\n", mapName);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003850
// Name: public: virtual bool GameTypes::GetMapInfo(char const __near *,int __near &,int __near &,unsigned int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameTypes::GetMapInfo(
        GameTypes *this,
        const char *mapName,
        int *maxPlayers,
        int *extraSpectators,
        unsigned int *richPresence)
{
  GameTypes::Map *Map_Internal; // eax

  Map_Internal = GameTypes::GetMap_Internal(this, mapName);
  if ( Map_Internal == nullptr )
    return 0;
  *maxPlayers = Map_Internal->m_MaxPlayers;
  *richPresence = Map_Internal->m_RichPresence;
  *extraSpectators = Map_Internal->m_ExtraSpectators;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10003890
// Name: public: virtual class CUtlStringList const __near * GameTypes::GetTModelsForMap(char const __near *)
// Source: json
//------------------------------------------------------------------------------
GameTypes::Map *__thiscall GameTypes::GetTModelsForMap(GameTypes *this, const char *mapName)
{
  GameTypes::Map *result; // eax

  result = GameTypes::GetMap_Internal(this, mapName);
  if ( result != nullptr )
    return (GameTypes::Map *)((char *)result + 84);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100038B0
// Name: public: virtual class CUtlStringList const __near * GameTypes::GetCTModelsForMap(char const __near *)
// Source: json
//------------------------------------------------------------------------------
GameTypes::Map *__thiscall GameTypes::GetCTModelsForMap(GameTypes *this, const char *mapName)
{
  GameTypes::Map *result; // eax

  result = GameTypes::GetMap_Internal(this, mapName);
  if ( result != nullptr )
    return (GameTypes::Map *)((char *)result + 104);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100038D0
// Name: public: virtual char const __near * GameTypes::GetGameTypeFromInt(int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall GameTypes::GetGameTypeFromInt(GameTypes *this, int gameType)
{
  int m_Size; // esi
  int v3; // eax
  GameTypes::GameType **m_pMemory; // edx
  GameTypes::GameType *v5; // ecx

  m_Size = this->m_GameTypes.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
  {
LABEL_6:
    _Warning(a1: "GameTypes: could not find matching game type for value \"%d\".\n", gameType);
    return nullptr;
  }
  else
  {
    m_pMemory = this->m_GameTypes.m_Memory.m_pMemory;
    while ( 1 )
    {
      v5 = *m_pMemory;
      if ( *m_pMemory != nullptr && v5->m_Index == gameType )
        return v5->m_Name;
      ++v3;
      ++m_pMemory;
      if ( v3 >= m_Size )
        goto LABEL_6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003920
// Name: public: virtual char const __near * GameTypes::GetGameModeFromInt(int,int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall GameTypes::GetGameModeFromInt(GameTypes *this, int gameType, int gameMode)
{
  int m_Size; // edx
  int v5; // edi
  GameTypes::GameType **m_pMemory; // ecx
  GameTypes::GameType *v7; // ecx
  int v8; // esi
  int v9; // eax
  GameTypes::GameMode **v10; // edx
  GameTypes::GameMode *v11; // ecx
  int v13; // [esp+Ch] [ebp-4h]
  int gameModea; // [esp+1Ch] [ebp+Ch]

  m_Size = this->m_GameTypes.m_Size;
  v5 = 0;
  v13 = m_Size;
  if ( m_Size <= 0 )
  {
LABEL_12:
    _Warning(
      a1: "GameTypes: could not find matching game mode value of \"%d\" and type value of \"%d\".\n",
      gameType,
      gameMode);
    return nullptr;
  }
  else
  {
    m_pMemory = this->m_GameTypes.m_Memory.m_pMemory;
    gameModea = (int)m_pMemory;
    while ( 1 )
    {
      v7 = *m_pMemory;
      if ( v7 != nullptr && v7->m_Index == gameType )
      {
        v8 = v7->m_GameModes.m_Size;
        v9 = 0;
        if ( v8 > 0 )
          break;
      }
LABEL_11:
      ++v5;
      m_pMemory = (GameTypes::GameType **)(gameModea + 4);
      gameModea += 4;
      if ( v5 >= m_Size )
        goto LABEL_12;
    }
    v10 = v7->m_GameModes.m_Memory.m_pMemory;
    while ( 1 )
    {
      v11 = *v10;
      if ( *v10 != nullptr && v11->m_Index == gameMode )
        return v11->m_Name;
      ++v9;
      ++v10;
      if ( v9 >= v8 )
      {
        m_Size = v13;
        goto LABEL_11;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100039B0
// Name: public: virtual int GameTypes::GetNoResetVoteThresholdForCurrentModeCT(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GameTypes::GetNoResetVoteThresholdForCurrentModeCT(GameTypes *this)
{
  int m_Size; // edx
  int m_nValue; // eax
  GameTypes::GameType *v4; // ecx
  int v5; // eax
  GameTypes::GameMode *v6; // eax

  m_Size = this->m_GameTypes.m_Size;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no game types have been loaded.\n");
    return -1;
  }
  if ( game_type.m_pParent != nullptr )
  {
    m_nValue = game_type.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
    {
LABEL_9:
      _Warning(a1: "GamesTypes: game_type is set to an invalid value (%d). Range [%d,%d].\n", m_nValue, 0, m_Size - 1);
      return -1;
    }
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue >= m_Size )
    goto LABEL_9;
  v4 = this->m_GameTypes.m_Memory.m_pMemory[m_nValue];
  if ( v4 == nullptr )
    return -1;
  if ( game_mode.m_pParent != nullptr )
  {
    v5 = game_mode.m_pParent->m_Value.m_nValue;
    if ( v5 < 0 )
    {
LABEL_16:
      _Warning(
        a1: "GamesTypes: game_mode is set to an invalid value (%d). Range [%d,%d].\n",
        v5,
        0,
        v4->m_GameModes.m_Size - 1);
      return -1;
    }
  }
  else
  {
    v5 = 0;
  }
  if ( v5 >= v4->m_GameModes.m_Size )
    goto LABEL_16;
  v6 = v4->m_GameModes.m_Memory.m_pMemory[v5];
  if ( v6 == nullptr )
    return -1;
  return v6->m_NoResetVoteThresholdCT;
}

//------------------------------------------------------------------------------
// Address: 0x10003A50
// Name: public: virtual int GameTypes::GetNoResetVoteThresholdForCurrentModeT(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GameTypes::GetNoResetVoteThresholdForCurrentModeT(GameTypes *this)
{
  int m_Size; // edx
  int m_nValue; // eax
  GameTypes::GameType *v4; // ecx
  int v5; // eax
  GameTypes::GameMode *v6; // eax

  m_Size = this->m_GameTypes.m_Size;
  if ( m_Size == 0 )
  {
    _Warning(a1: "GamesTypes: no game types have been loaded.\n");
    return -1;
  }
  if ( game_type.m_pParent != nullptr )
  {
    m_nValue = game_type.m_pParent->m_Value.m_nValue;
    if ( m_nValue < 0 )
    {
LABEL_9:
      _Warning(a1: "GamesTypes: game_type is set to an invalid value (%d). Range [%d,%d].\n", m_nValue, 0, m_Size - 1);
      return -1;
    }
  }
  else
  {
    m_nValue = 0;
  }
  if ( m_nValue >= m_Size )
    goto LABEL_9;
  v4 = this->m_GameTypes.m_Memory.m_pMemory[m_nValue];
  if ( v4 == nullptr )
    return -1;
  if ( game_mode.m_pParent != nullptr )
  {
    v5 = game_mode.m_pParent->m_Value.m_nValue;
    if ( v5 < 0 )
    {
LABEL_16:
      _Warning(
        a1: "GamesTypes: game_mode is set to an invalid value (%d). Range [%d,%d].\n",
        v5,
        0,
        v4->m_GameModes.m_Size - 1);
      return -1;
    }
  }
  else
  {
    v5 = 0;
  }
  if ( v5 >= v4->m_GameModes.m_Size )
    goto LABEL_16;
  v6 = v4->m_GameModes.m_Memory.m_pMemory[v5];
  if ( v6 == nullptr )
    return -1;
  return v6->m_NoResetVoteThresholdT;
}

//------------------------------------------------------------------------------
// Address: 0x10003AF0
// Name: public: virtual bool GameTypes::GetGameModeAndTypeIntsFromStrings(char const __near *,char const __near *,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameTypes::GetGameModeAndTypeIntsFromStrings(
        GameTypes *this,
        const char *szGameType,
        const char *szGameMode,
        int *iOutGameType,
        int *iOutGameMode)
{
  GameTypes::GameType *GameType_Internal; // eax
  GameTypes::GameType *v7; // esi
  GameTypes::GameMode *GameMode_Internal; // eax
  int m_Index; // ecx

  *iOutGameType = -1;
  *iOutGameMode = -1;
  if ( szGameType == nullptr || szGameMode == nullptr )
    return 0;
  GameType_Internal = GameTypes::GetGameType_Internal(this, gameType: szGameType);
  v7 = GameType_Internal;
  if ( GameType_Internal == nullptr
    || (GameMode_Internal = GameTypes::GetGameMode_Internal(this, pGameType: GameType_Internal, gameMode: szGameMode)) == nullptr )
  {
    _Warning(
      a1: "GamesTypes: unable to get game type and mode. Could not find type/mode matching type:%s/mode:%s.\n",
      szGameType,
      szGameMode);
    return 0;
  }
  m_Index = v7->m_Index;
  if ( v7->m_Index < 0
    || m_Index >= this->m_GameTypes.m_Size
    || GameMode_Internal->m_Index < 0
    || GameMode_Internal->m_Index >= v7->m_GameModes.m_Size )
  {
    return 0;
  }
  *iOutGameType = m_Index;
  *iOutGameMode = GameMode_Internal->m_Index;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10003B80
// Name: public: virtual bool GameTypes::GetGameModeAndTypeNameIdsFromStrings(char const __near *,char const __near *,char const __near * __near &,char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameTypes::GetGameModeAndTypeNameIdsFromStrings(
        GameTypes *this,
        const char *szGameType,
        const char *szGameMode,
        char **szOutGameTypeNameId,
        char **szOutGameModeNameId)
{
  GameTypes::GameType *GameType_Internal; // eax
  GameTypes::GameType *v7; // esi
  GameTypes::GameMode *GameMode_Internal; // eax

  *szOutGameTypeNameId = nullptr;
  *szOutGameModeNameId = nullptr;
  if ( szGameType == nullptr || szGameMode == nullptr )
    return 0;
  GameType_Internal = GameTypes::GetGameType_Internal(this, gameType: szGameType);
  v7 = GameType_Internal;
  if ( GameType_Internal == nullptr
    || (GameMode_Internal = GameTypes::GetGameMode_Internal(this, pGameType: GameType_Internal, gameMode: szGameMode)) == nullptr )
  {
    _Warning(
      a1: "GamesTypes: unable to get game type and mode. Could not find type/mode matching type:%s/mode:%s.\n",
      szGameType,
      szGameMode);
    return 0;
  }
  if ( GameMode_Internal == (GameTypes::GameMode *)-36 || v7 == (GameTypes::GameType *)-36 )
    return 0;
  *szOutGameTypeNameId = v7->m_NameID;
  *szOutGameModeNameId = GameMode_Internal->m_NameID;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10003C10
// Name: public: void CUtlVector<char __near *,class CUtlMemory<char __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(
        CUtlVector<char *,CUtlMemory<char *,int> > *this)
{
  int i; // edi
  bool v3; // sf
  char **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
    free(pMem: this->m_Memory.m_pMemory[i]);
  v3 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v3 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003C80
// Name: public: void CUtlVector<struct GameTypes::FreestyleBotDifficulty __near *,class CUtlMemory<struct GameTypes::FreestyleBotDifficulty __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<GameTypes::FreestyleBotDifficulty *,CUtlMemory<GameTypes::FreestyleBotDifficulty *,int>>::PurgeAndDeleteElements(
        CUtlVector<GameTypes::FreestyleBotDifficulty *,CUtlMemory<GameTypes::FreestyleBotDifficulty *,int> > *this)
{
  int i; // ebx
  GameTypes::FreestyleBotDifficulty *v3; // edi
  KeyValues *m_pConvars; // ecx
  bool v5; // sf
  GameTypes::FreestyleBotDifficulty **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
    {
      m_pConvars = v3->m_pConvars;
      if ( m_pConvars != nullptr )
        KeyValues::deleteThis(this: m_pConvars);
      free(pMem: v3);
    }
  }
  v5 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v5 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003D00
// Name: public: virtual bool GameTypes::IsInitialized(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GameTypes::IsInitialized(GameTypes *this)
{
  return this->m_Initialized;
}

//------------------------------------------------------------------------------
// Address: 0x10003D10
// Name: public: void CUtlStringList::CopyAndAddToTail(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlStringList::CopyAndAddToTail(CUtlStringList *this, const char *pString)
{
  char *v3; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v7; // eax
  char **v8; // edi

  v3 = (char *)operator new(nSize: strlen(pString) + 1);
  _V_strcpy(dest: v3, src: pString);
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<GCSDK::CLock *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &this->m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = v3;
}

//------------------------------------------------------------------------------
// Address: 0x10003D90
// Name: private: bool GameTypes::LoadFreestyleBotDifficulties(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameTypes::LoadFreestyleBotDifficulties(GameTypes *this, KeyValues *pKV)
{
  KeyValues *Key; // eax
  KeyValues *FirstTrueSubKey; // edi
  _DWORD *v6; // eax
  GameTypes::FreestyleBotDifficulty *v7; // ebx
  const char *Name; // eax
  const char *String; // eax
  const char *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  GameTypes::FreestyleBotDifficulty **m_pMemory; // ecx
  int v16; // eax
  GameTypes::FreestyleBotDifficulty **v17; // edi
  const char *v18; // eax
  KeyValues *pKV_BotDiff; // [esp+14h] [ebp+8h]

  if ( pKV == nullptr )
    return 0;
  if ( this->m_FreestyleBotDifficulties.m_Size > 0 )
    CUtlVector<GameTypes::FreestyleBotDifficulty *,CUtlMemory<GameTypes::FreestyleBotDifficulty *,int>>::PurgeAndDeleteElements(this: &this->m_FreestyleBotDifficulties);
  Key = KeyValues::FindKey(this: pKV, keyName: "botDifficulty", bCreate: false);
  if ( Key == nullptr )
  {
    _Warning(a1: "GameTypes: could not find entry %s.\n", "botDifficulty");
    return 0;
  }
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: Key);
  pKV_BotDiff = FirstTrueSubKey;
  if ( FirstTrueSubKey != nullptr )
  {
    while ( 1 )
    {
      v6 = operator new(nSize: 0x4Cu);
      v7 = nullptr;
      if ( v6 != nullptr )
      {
        v6[17] = 0;
        *((_BYTE *)v6 + 72) = 0;
        *((_BYTE *)v6 + 4) = 0;
        *((_BYTE *)v6 + 36) = 0;
        *v6 = -1;
        v7 = (GameTypes::FreestyleBotDifficulty *)v6;
      }
      Name = KeyValues::GetName(this: FirstTrueSubKey);
      V_strncpy(pDest: v7->m_Name, pSrc: Name, maxLen: 32);
      String = KeyValues::GetString(this: FirstTrueSubKey, keyName: "nameID", defaultValue: defaultValue);
      if ( String != nullptr )
      {
        V_strncpy(pDest: v7->m_NameID, pSrc: String, maxLen: 32);
      }
      else
      {
        v10 = KeyValues::GetName(this: FirstTrueSubKey);
        _Warning(a1: "GameTypes: missing %s entry for bot difficulty %s.\n", "nameID", v10);
      }
      v11 = KeyValues::FindKey(this: FirstTrueSubKey, keyName: "convars", bCreate: false);
      v12 = v11;
      if ( v11 != nullptr )
      {
        v7->m_pConvars = KeyValues::MakeCopy(this: v11);
        v7->m_HasBotQuota = KeyValues::GetInt(this: v12, keyName: "bot_quota", defaultValue: -1) != -1;
      }
      else
      {
        v18 = KeyValues::GetName(this: pKV_BotDiff);
        _Warning(a1: "GameTypes: missing entry %s for bot difficulty %s.\n", "convars", v18);
      }
      v7->m_Index = this->m_FreestyleBotDifficulties.m_Size;
      m_Size = this->m_FreestyleBotDifficulties.m_Size;
      m_nAllocationCount = this->m_FreestyleBotDifficulties.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<GCSDK::CLock *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_FreestyleBotDifficulties,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_FreestyleBotDifficulties.m_Size;
      m_pMemory = this->m_FreestyleBotDifficulties.m_Memory.m_pMemory;
      v16 = this->m_FreestyleBotDifficulties.m_Size - m_Size - 1;
      this->m_FreestyleBotDifficulties.m_pElements = m_pMemory;
      if ( v16 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v16);
      v17 = &this->m_FreestyleBotDifficulties.m_Memory.m_pMemory[m_Size];
      if ( v17 != nullptr )
        *v17 = v7;
      pKV_BotDiff = KeyValues::GetNextTrueSubKey(this: pKV_BotDiff);
      if ( pKV_BotDiff == nullptr )
        break;
      FirstTrueSubKey = pKV_BotDiff;
    }
  }
  if ( this->m_FreestyleBotDifficulties.m_Size == 0 )
    _Warning(a1: "GamesTypes: empty %s entry.\n", "botDifficulty");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10003F60
// Name: public: void CUtlVector<struct IGameTypes::WeaponProgression,class CUtlMemory<struct IGameTypes::WeaponProgression,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int>>::RemoveAll(
        CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  IGameTypes::WeaponProgression *v3; // esi
  CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v3->m_Name.m_Storage.m_nActualLength = 0;
      if ( v3->m_Name.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Name.m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->m_Name.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Name.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003FD0
// Name: private: void GameTypes::LoadWeaponProgression(class KeyValues __near *,class CUtlVector<struct IGameTypes::WeaponProgression,class CUtlMemory<struct IGameTypes::WeaponProgression,int>> __near &,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GameTypes::LoadWeaponProgression(
        GameTypes *this,
        KeyValues *pKV_WeaponProgression,
        CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int> > *vecWeaponProgression,
        const char *szGameType,
        const char *szGameMode)
{
  KeyValues *v5; // edi
  KeyValues *FirstTrueSubKey; // ebx
  const char *Name; // eax
  const char *v8; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  IGameTypes::WeaponProgression *m_pMemory; // ecx
  int v12; // eax
  IGameTypes::WeaponProgression *v13; // edi
  const char *v14; // eax
  IGameTypes::WeaponProgression wp; // [esp+4h] [ebp-14h] BYREF

  v5 = pKV_WeaponProgression;
  if ( pKV_WeaponProgression != nullptr )
  {
    FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pKV_WeaponProgression);
    if ( FirstTrueSubKey != nullptr )
    {
      do
      {
        CUtlString::CUtlString(this: &wp.m_Name);
        wp.m_Kills = 0;
        Name = KeyValues::GetName(this: FirstTrueSubKey);
        CUtlString::Set(this: &wp.m_Name, pValue: Name);
        wp.m_Kills = KeyValues::GetInt(this: FirstTrueSubKey, keyName: "kills", defaultValue: -1);
        if ( wp.m_Kills == -1 )
        {
          wp.m_Kills = 0;
          v8 = KeyValues::GetName(this: FirstTrueSubKey);
          _Warning(
            a1: "GameTypes: missing %s entry for weapon \"%s\" for game type/mode (%s/%s).\n",
            "kills",
            v8,
            szGameType,
            szGameMode);
        }
        m_Size = vecWeaponProgression->m_Size;
        m_nAllocationCount = vecWeaponProgression->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<IGameTypes::WeaponProgression,int>::Grow(
            this: &vecWeaponProgression->m_Memory,
            num: m_Size - m_nAllocationCount + 1);
        ++vecWeaponProgression->m_Size;
        m_pMemory = vecWeaponProgression->m_Memory.m_pMemory;
        v12 = vecWeaponProgression->m_Size - m_Size - 1;
        vecWeaponProgression->m_pElements = vecWeaponProgression->m_Memory.m_pMemory;
        if ( v12 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 20 * v12);
        v13 = &vecWeaponProgression->m_Memory.m_pMemory[m_Size];
        if ( v13 != nullptr )
        {
          CUtlString::CUtlString(this: &v13->m_Name, string: &wp.m_Name);
          v13->m_Kills = wp.m_Kills;
        }
        wp.m_Name.m_Storage.m_nActualLength = 0;
        if ( wp.m_Name.m_Storage.m_Memory.m_nGrowSize >= 0 && wp.m_Name.m_Storage.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: wp.m_Name.m_Storage.m_Memory.m_pMemory);
        FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
      }
      while ( FirstTrueSubKey != nullptr );
      v5 = pKV_WeaponProgression;
    }
    if ( vecWeaponProgression->m_Size == 0 )
    {
      v14 = KeyValues::GetName(this: v5);
      _Warning(a1: "GameTypes: empty %s entry for game type/mode (%s/%s).\n", v14, szGameType, szGameMode);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004120
// Name: public: void CUtlVector<struct GameTypes::Map __near *,class CUtlMemory<struct GameTypes::Map __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<GameTypes::Map *,CUtlMemory<GameTypes::Map *,int>>::PurgeAndDeleteElements(
        CUtlVector<GameTypes::Map *,CUtlMemory<GameTypes::Map *,int> > *this)
{
  int v2; // eax
  GameTypes::Map *v3; // esi
  char **m_pMemory; // eax
  char **v5; // eax
  GameTypes::Map **v6; // ecx
  int i; // [esp+8h] [ebp-8h]

  v2 = 0;
  for ( i = 0; v2 < this->m_Size; i = v2 )
  {
    v3 = this->m_Memory.m_pMemory[v2];
    if ( v3 != nullptr )
    {
      CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &v3->m_CTModels);
      v3->m_CTModels.m_Size = 0;
      if ( v3->m_CTModels.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_CTModels.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_CTModels.m_Memory.m_pMemory);
          v3->m_CTModels.m_Memory.m_pMemory = nullptr;
        }
        v3->m_CTModels.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v3->m_CTModels.m_Memory.m_pMemory;
      v3->m_CTModels.m_pElements = m_pMemory;
      if ( v3->m_CTModels.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_CTModels.m_Memory.m_pMemory = nullptr;
        }
        v3->m_CTModels.m_Memory.m_nAllocationCount = 0;
      }
      CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &v3->m_TModels);
      v3->m_TModels.m_Size = 0;
      if ( v3->m_TModels.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_TModels.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_TModels.m_Memory.m_pMemory);
          v3->m_TModels.m_Memory.m_pMemory = nullptr;
        }
        v3->m_TModels.m_Memory.m_nAllocationCount = 0;
      }
      v5 = v3->m_TModels.m_Memory.m_pMemory;
      v3->m_TModels.m_pElements = v5;
      if ( v3->m_TModels.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v5 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
          v3->m_TModels.m_Memory.m_pMemory = nullptr;
        }
        v3->m_TModels.m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: v3);
      v2 = i;
    }
    ++v2;
  }
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    v6 = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004250
// Name: public: GameTypes::GameMode::GameMode(void)
// Source: json
//------------------------------------------------------------------------------
GameTypes::GameMode *__thiscall GameTypes::GameMode::GameMode(GameTypes::GameMode *this)
{
  this->m_pConvarsSP = nullptr;
  this->m_pConvarsMP = nullptr;
  this->m_Index = -1;
  this->m_Maps.m_Memory.m_pMemory = nullptr;
  this->m_Maps.m_Memory.m_nAllocationCount = 0;
  this->m_Maps.m_Memory.m_nGrowSize = 0;
  this->m_Maps.m_Size = 0;
  this->m_Maps.m_pElements = nullptr;
  this->m_WeaponProgressionCT.m_Memory.m_pMemory = nullptr;
  this->m_WeaponProgressionCT.m_Memory.m_nAllocationCount = 0;
  this->m_WeaponProgressionCT.m_Memory.m_nGrowSize = 0;
  this->m_WeaponProgressionCT.m_Size = 0;
  this->m_WeaponProgressionCT.m_pElements = nullptr;
  this->m_WeaponProgressionT.m_Memory.m_pMemory = nullptr;
  this->m_WeaponProgressionT.m_Memory.m_nAllocationCount = 0;
  this->m_WeaponProgressionT.m_Memory.m_nGrowSize = 0;
  this->m_WeaponProgressionT.m_Size = 0;
  this->m_WeaponProgressionT.m_pElements = nullptr;
  this->m_Name[0] = 0;
  this->m_NameID[0] = 0;
  this->m_DescID[0] = 0;
  this->m_NoResetVoteThresholdCT = -1;
  this->m_NoResetVoteThresholdT = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100042C0
// Name: private: bool GameTypes::LoadMaps(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameTypes::LoadMaps(GameTypes *this, KeyValues *pKV)
{
  GameTypes *v2; // edi
  KeyValues *Key; // eax
  KeyValues *FirstTrueSubKey; // ebx
  GameTypes::Map *v6; // eax
  unsigned int v7; // ecx
  GameTypes::Map *v8; // edi
  const char *Name; // eax
  const char *String; // eax
  const char *v11; // eax
  int Int; // eax
  int v13; // eax
  int v14; // eax
  KeyValues *v15; // eax
  KeyValues *i; // esi
  const char *v17; // eax
  KeyValues *v18; // eax
  KeyValues *FirstValue; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_CTModels; // esi
  const char *v21; // eax
  const char *v22; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **v25; // ecx
  int v26; // eax
  char **v27; // edi
  const char *v28; // eax
  int m_Size; // esi
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_Maps; // edi
  int v31; // eax
  CUtlSymbolTable::StringPool_t **v32; // ecx
  int v33; // eax
  GameTypes::Map **v34; // esi
  const char *v35; // [esp-4h] [ebp-1Ch]
  const char *v36; // [esp-4h] [ebp-1Ch]
  const char *v37; // [esp-4h] [ebp-1Ch]
  const char *v38; // [esp-4h] [ebp-1Ch]
  int v39; // [esp-4h] [ebp-1Ch]
  char *v40; // [esp+Ch] [ebp-Ch]
  KeyValues *pKV_Model; // [esp+14h] [ebp-4h]
  GameTypes::Map *pMap; // [esp+20h] [ebp+8h]

  v2 = this;
  if ( pKV == nullptr )
    return 0;
  if ( this->m_Maps.m_Size > 0 )
    CUtlVector<GameTypes::Map *,CUtlMemory<GameTypes::Map *,int>>::PurgeAndDeleteElements(this: &this->m_Maps);
  Key = KeyValues::FindKey(this: pKV, keyName: "maps", bCreate: false);
  if ( Key == nullptr )
  {
    _Warning(a1: "GameTypes: could not find entry %s.\n", "maps");
    return 0;
  }
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: Key);
  if ( FirstTrueSubKey == nullptr )
    goto LABEL_49;
  do
  {
    v6 = (GameTypes::Map *)operator new(nSize: 0x7Cu);
    if ( v6 != nullptr )
    {
      v7 = g_richPresenceDefault;
      v6->m_Index = -1;
      v6->m_MinPlayers = 0;
      v6->m_MaxPlayers = 0;
      v6->m_ExtraSpectators = 0;
      v6->m_RichPresence = v7;
      v6->m_TModels.m_Memory.m_pMemory = nullptr;
      v6->m_TModels.m_Memory.m_nAllocationCount = 0;
      v6->m_TModels.m_Memory.m_nGrowSize = 0;
      v6->m_TModels.m_Size = 0;
      v6->m_TModels.m_pElements = nullptr;
      v6->m_CTModels.m_Memory.m_pMemory = nullptr;
      v6->m_CTModels.m_Memory.m_nAllocationCount = 0;
      v6->m_CTModels.m_Memory.m_nGrowSize = 0;
      v6->m_CTModels.m_Size = 0;
      v6->m_CTModels.m_pElements = nullptr;
      v8 = v6;
      v6->m_Name[0] = 0;
      v6->m_NameID[0] = 0;
      pMap = v6;
    }
    else
    {
      pMap = nullptr;
      v8 = nullptr;
    }
    Name = KeyValues::GetName(this: FirstTrueSubKey);
    V_strncpy(pDest: v8->m_Name, pSrc: Name, maxLen: 32);
    String = KeyValues::GetString(this: FirstTrueSubKey, keyName: "nameID", defaultValue: defaultValue);
    if ( String != nullptr )
    {
      V_strncpy(pDest: v8->m_NameID, pSrc: String, maxLen: 32);
    }
    else
    {
      v11 = KeyValues::GetName(this: FirstTrueSubKey);
      _Warning(a1: "GameTypes: missing %s entry for map %s.\n", "nameID", v11);
    }
    Int = KeyValues::GetInt(this: FirstTrueSubKey, keyName: "minplayers", defaultValue: -1);
    v8->m_MinPlayers = Int;
    if ( Int == -1 )
    {
      v35 = KeyValues::GetName(this: FirstTrueSubKey);
      _Warning(a1: "GameTypes: missing %s entry for map %s.\n", "minplayers", v35);
    }
    else
    {
      if ( Int >= 0 )
        goto LABEL_19;
      v36 = KeyValues::GetName(this: FirstTrueSubKey);
      _Warning(a1: "GameTypes: invalid %s entry for map %s.\n", "minplayers", v36);
    }
    v8->m_MinPlayers = 0;
LABEL_19:
    v13 = KeyValues::GetInt(this: FirstTrueSubKey, keyName: "maxplayers", defaultValue: -1);
    v8->m_MaxPlayers = v13;
    if ( v13 == -1 )
    {
      v37 = KeyValues::GetName(this: FirstTrueSubKey);
      _Warning(a1: "GameTypes: missing %s entry for map %s.\n", "maxplayers", v37);
    }
    else
    {
      if ( v13 >= 0 )
        goto LABEL_24;
      v38 = KeyValues::GetName(this: FirstTrueSubKey);
      _Warning(a1: "GameTypes: invalid %s entry for map %s.\n", "maxplayers", v38);
    }
    v8->m_MaxPlayers = 0;
LABEL_24:
    v14 = KeyValues::GetInt(this: FirstTrueSubKey, keyName: "extraspectators", defaultValue: 0);
    v39 = g_richPresenceDefault;
    v8->m_ExtraSpectators = v14;
    v8->m_RichPresence = KeyValues::GetInt(this: FirstTrueSubKey, keyName: "richpresencecontext", defaultValue: v39);
    v15 = KeyValues::FindKey(this: FirstTrueSubKey, keyName: "t_models", bCreate: false);
    if ( v15 != nullptr )
    {
      for ( i = KeyValues::GetFirstValue(this: v15); i != nullptr; i = KeyValues::GetNextValue(this: i) )
      {
        v17 = KeyValues::GetName(this: i);
        CUtlStringList::CopyAndAddToTail(this: &v8->m_TModels, pString: v17);
      }
    }
    else
    {
      v21 = KeyValues::GetName(this: FirstTrueSubKey);
      _Warning(a1: "GameTypes: missing %s entry for map %s.\n", "t_models", v21);
    }
    v18 = KeyValues::FindKey(this: FirstTrueSubKey, keyName: "ct_models", bCreate: false);
    if ( v18 != nullptr )
    {
      FirstValue = KeyValues::GetFirstValue(this: v18);
      pKV_Model = FirstValue;
      if ( FirstValue != nullptr )
      {
        p_m_CTModels = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v8->m_CTModels;
        while ( 1 )
        {
          v22 = KeyValues::GetName(this: FirstValue);
          v40 = (char *)operator new(nSize: strlen(v22) + 1);
          _V_strcpy(dest: v40, src: v22);
          m_pMemory = p_m_CTModels[1].m_pMemory;
          m_nAllocationCount = p_m_CTModels->m_nAllocationCount;
          if ( (int)m_pMemory + 1 > m_nAllocationCount )
            CUtlMemory<GCSDK::CLock *,int>::Grow(this: p_m_CTModels, num: (int)m_pMemory - m_nAllocationCount + 1);
          ++p_m_CTModels[1].m_pMemory;
          v25 = p_m_CTModels->m_pMemory;
          v26 = (char *)p_m_CTModels[1].m_pMemory - (char *)m_pMemory - 1;
          p_m_CTModels[1].m_nAllocationCount = (int)p_m_CTModels->m_pMemory;
          if ( v26 > 0 )
            _V_memmove(dest: &v25[(_DWORD)m_pMemory + 1], src: &v25[(_DWORD)m_pMemory], count: 4 * v26);
          v27 = (char **)&p_m_CTModels->m_pMemory[(_DWORD)m_pMemory];
          if ( v27 != nullptr )
            *v27 = v40;
          pKV_Model = KeyValues::GetNextValue(this: pKV_Model);
          if ( pKV_Model == nullptr )
            break;
          FirstValue = pKV_Model;
        }
        v8 = pMap;
      }
    }
    else
    {
      v28 = KeyValues::GetName(this: FirstTrueSubKey);
      _Warning(a1: "GameTypes: missing %s entry for map %s.\n", "ct_models", v28);
    }
    v8->m_Index = this->m_Maps.m_Size;
    m_Size = this->m_Maps.m_Size;
    p_m_Maps = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Maps;
    v31 = this->m_Maps.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > v31 )
      CUtlMemory<GCSDK::CLock *,int>::Grow(this: p_m_Maps, num: m_Size - v31 + 1);
    ++this->m_Maps.m_Size;
    v32 = p_m_Maps->m_pMemory;
    v33 = this->m_Maps.m_Size - m_Size - 1;
    this->m_Maps.m_pElements = this->m_Maps.m_Memory.m_pMemory;
    if ( v33 > 0 )
      _V_memmove(dest: &v32[m_Size + 1], src: &v32[m_Size], count: 4 * v33);
    v34 = (GameTypes::Map **)&p_m_Maps->m_pMemory[m_Size];
    if ( v34 != nullptr )
      *v34 = pMap;
    FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
  }
  while ( FirstTrueSubKey != nullptr );
  v2 = this;
LABEL_49:
  if ( v2->m_Maps.m_Size == 0 )
    _Warning(a1: "GamesTypes: empty %s entry.\n", "maps");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10004670
// Name: public: void CUtlVector<struct GameTypes::GameMode __near *,class CUtlMemory<struct GameTypes::GameMode __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<GameTypes::GameMode *,CUtlMemory<GameTypes::GameMode *,int>>::PurgeAndDeleteElements(
        CUtlVector<GameTypes::GameMode *,CUtlMemory<GameTypes::GameMode *,int> > *this)
{
  CUtlVector<GameTypes::GameMode *,CUtlMemory<GameTypes::GameMode *,int> > *v1; // esi
  int v2; // eax
  GameTypes::GameMode *v3; // ebx
  KeyValues *m_pConvarsSP; // ecx
  KeyValues *m_pConvarsMP; // ecx
  IGameTypes::WeaponProgression *m_pMemory; // eax
  IGameTypes::WeaponProgression *v7; // eax
  char **v8; // eax
  GameTypes::GameMode **v9; // ecx
  int i; // [esp+Ch] [ebp-4h]

  v1 = this;
  v2 = 0;
  for ( i = 0; v2 < v1->m_Size; i = v2 )
  {
    v3 = v1->m_Memory.m_pMemory[v2];
    if ( v3 != nullptr )
    {
      m_pConvarsSP = v3->m_pConvarsSP;
      if ( m_pConvarsSP != nullptr )
        KeyValues::deleteThis(this: m_pConvarsSP);
      m_pConvarsMP = v3->m_pConvarsMP;
      if ( m_pConvarsMP != nullptr )
        KeyValues::deleteThis(this: m_pConvarsMP);
      CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int>>::RemoveAll(this: &v3->m_WeaponProgressionT);
      if ( v3->m_WeaponProgressionT.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_WeaponProgressionT.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_WeaponProgressionT.m_Memory.m_pMemory);
          v3->m_WeaponProgressionT.m_Memory.m_pMemory = nullptr;
        }
        v3->m_WeaponProgressionT.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v3->m_WeaponProgressionT.m_Memory.m_pMemory;
      v3->m_WeaponProgressionT.m_pElements = m_pMemory;
      if ( v3->m_WeaponProgressionT.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_WeaponProgressionT.m_Memory.m_pMemory = nullptr;
        }
        v3->m_WeaponProgressionT.m_Memory.m_nAllocationCount = 0;
      }
      CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int>>::RemoveAll(this: &v3->m_WeaponProgressionCT);
      if ( v3->m_WeaponProgressionCT.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_WeaponProgressionCT.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_WeaponProgressionCT.m_Memory.m_pMemory);
          v3->m_WeaponProgressionCT.m_Memory.m_pMemory = nullptr;
        }
        v3->m_WeaponProgressionCT.m_Memory.m_nAllocationCount = 0;
      }
      v7 = v3->m_WeaponProgressionCT.m_Memory.m_pMemory;
      v3->m_WeaponProgressionCT.m_pElements = v7;
      if ( v3->m_WeaponProgressionCT.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v7 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
          v3->m_WeaponProgressionCT.m_Memory.m_pMemory = nullptr;
        }
        v3->m_WeaponProgressionCT.m_Memory.m_nAllocationCount = 0;
      }
      CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &v3->m_Maps);
      v3->m_Maps.m_Size = 0;
      if ( v3->m_Maps.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Maps.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Maps.m_Memory.m_pMemory);
          v3->m_Maps.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Maps.m_Memory.m_nAllocationCount = 0;
      }
      v8 = v3->m_Maps.m_Memory.m_pMemory;
      v3->m_Maps.m_pElements = v8;
      if ( v3->m_Maps.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v8 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
          v3->m_Maps.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Maps.m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: v3);
      v1 = this;
      v2 = i;
    }
    ++v2;
  }
  v1->m_Size = 0;
  if ( v1->m_Memory.m_nGrowSize < 0 )
  {
    v1->m_pElements = v1->m_Memory.m_pMemory;
  }
  else
  {
    if ( v1->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1->m_Memory.m_pMemory);
      v1->m_Memory.m_pMemory = nullptr;
    }
    v9 = v1->m_Memory.m_pMemory;
    v1->m_Memory.m_nAllocationCount = 0;
    v1->m_pElements = v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004840
// Name: public: void CUtlVector<struct GameTypes::GameType __near *,class CUtlMemory<struct GameTypes::GameType __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<GameTypes::GameType *,CUtlMemory<GameTypes::GameType *,int>>::PurgeAndDeleteElements(
        CUtlVector<GameTypes::GameType *,CUtlMemory<GameTypes::GameType *,int> > *this)
{
  int v2; // eax
  GameTypes::GameType *v3; // esi
  GameTypes::GameMode **m_pMemory; // eax
  GameTypes::GameType **v5; // ecx
  int i; // [esp+Ch] [ebp-4h]

  v2 = 0;
  for ( i = 0; v2 < this->m_Size; i = v2 )
  {
    v3 = this->m_Memory.m_pMemory[v2];
    if ( v3 != nullptr )
    {
      CUtlVector<GameTypes::GameMode *,CUtlMemory<GameTypes::GameMode *,int>>::PurgeAndDeleteElements(this: &v3->m_GameModes);
      v3->m_GameModes.m_Size = 0;
      if ( v3->m_GameModes.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_GameModes.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_GameModes.m_Memory.m_pMemory);
          v3->m_GameModes.m_Memory.m_pMemory = nullptr;
        }
        v3->m_GameModes.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v3->m_GameModes.m_Memory.m_pMemory;
      v3->m_GameModes.m_pElements = m_pMemory;
      if ( v3->m_GameModes.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_GameModes.m_Memory.m_pMemory = nullptr;
        }
        v3->m_GameModes.m_Memory.m_nAllocationCount = 0;
      }
      free(pMem: v3);
      v2 = i;
    }
    ++v2;
  }
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    v5 = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004910
// Name: private: bool GameTypes::LoadGameTypes(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameTypes::LoadGameTypes(GameTypes *this, KeyValues *pKV)
{
  KeyValues *Key; // eax
  KeyValues *FirstTrueSubKey; // edi
  GameTypes::GameType *v5; // eax
  GameTypes::GameType *v6; // esi
  const char *Name; // eax
  const char *String; // eax
  const char *v9; // eax
  KeyValues *v10; // eax
  KeyValues *NextTrueSubKey; // ebx
  GameTypes::GameMode *v12; // eax
  GameTypes::GameMode *v13; // esi
  const char *v14; // eax
  const char *v15; // eax
  void (*v16)(const char *, ...); // esi
  const char *v17; // eax
  const char *v18; // eax
  const char *v19; // eax
  KeyValues *v20; // eax
  const char *v21; // eax
  KeyValues *v22; // eax
  KeyValues *v23; // eax
  KeyValues *FirstValue; // edi
  const char *v25; // eax
  const char *v26; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  char **m_pMemory; // ecx
  int v30; // eax
  char **v31; // edi
  const char *v32; // eax
  const char *v33; // eax
  KeyValues *v34; // esi
  const char *v35; // eax
  const char *v36; // eax
  KeyValues *v37; // eax
  const char *v38; // eax
  bool v39; // zf
  int v40; // eax
  KeyValues *v41; // eax
  int v42; // esi
  const char *v43; // eax
  int v44; // edi
  int v45; // eax
  GameTypes::GameMode **v46; // ecx
  int v47; // eax
  GameTypes::GameMode **v48; // edi
  const char *v49; // eax
  int v50; // ebx
  int v51; // eax
  GameTypes::GameType **v52; // ecx
  int v53; // eax
  GameTypes::GameType **v54; // eax
  const char *v55; // eax
  const char *v56; // [esp-8h] [ebp-28h]
  const char *v57; // [esp-8h] [ebp-28h]
  const char *v58; // [esp-8h] [ebp-28h]
  const char *v59; // [esp-8h] [ebp-28h]
  const char *v60; // [esp-8h] [ebp-28h]
  const char *v61; // [esp-8h] [ebp-28h]
  const char *v62; // [esp-8h] [ebp-28h]
  char *s2; // [esp+8h] [ebp-18h]
  char *s2a; // [esp+8h] [ebp-18h]
  char *pKV_WeaponProgressionT; // [esp+Ch] [ebp-14h]
  KeyValues *pKV_WeaponProgressionTc; // [esp+Ch] [ebp-14h]
  KeyValues *pKV_WeaponProgressionTa; // [esp+Ch] [ebp-14h]
  KeyValues *pKV_WeaponProgressionTb; // [esp+Ch] [ebp-14h]
  GameTypes::GameType *pGameType; // [esp+14h] [ebp-Ch]
  KeyValues *pKV_Map; // [esp+18h] [ebp-8h]
  KeyValues *pKV_Mapa; // [esp+18h] [ebp-8h]
  KeyValues *pKV_GameType; // [esp+1Ch] [ebp-4h]
  GameTypes::GameMode *pGameMode; // [esp+28h] [ebp+8h]

  if ( pKV == nullptr )
    return 0;
  if ( this->m_GameTypes.m_Size > 0 )
    CUtlVector<GameTypes::GameType *,CUtlMemory<GameTypes::GameType *,int>>::PurgeAndDeleteElements(this: &this->m_GameTypes);
  Key = KeyValues::FindKey(this: pKV, keyName: "gameTypes", bCreate: false);
  if ( Key == nullptr )
  {
    _Warning(a1: "GameTypes: could not find entry %s.\n", "gameTypes");
    return 0;
  }
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: Key);
  pKV_GameType = FirstTrueSubKey;
  if ( FirstTrueSubKey != nullptr )
  {
    while ( 1 )
    {
      v5 = (GameTypes::GameType *)operator new(nSize: 0x58u);
      if ( v5 != nullptr )
      {
        v5->m_Index = -1;
        v5->m_GameModes.m_Memory.m_pMemory = nullptr;
        v5->m_GameModes.m_Memory.m_nAllocationCount = 0;
        v5->m_GameModes.m_Memory.m_nGrowSize = 0;
        v5->m_GameModes.m_Size = 0;
        v5->m_GameModes.m_pElements = nullptr;
        v6 = v5;
        v5->m_Name[0] = 0;
        v5->m_NameID[0] = 0;
        pGameType = v5;
      }
      else
      {
        pGameType = nullptr;
        v6 = nullptr;
      }
      Name = KeyValues::GetName(this: FirstTrueSubKey);
      V_strncpy(pDest: v6->m_Name, pSrc: Name, maxLen: 32);
      String = KeyValues::GetString(this: FirstTrueSubKey, keyName: "nameID", defaultValue: defaultValue);
      if ( String != nullptr )
      {
        V_strncpy(pDest: v6->m_NameID, pSrc: String, maxLen: 32);
      }
      else
      {
        v9 = KeyValues::GetName(this: FirstTrueSubKey);
        _Warning(a1: "GameTypes: missing %s entry for game type %s.\n", "nameID", v9);
      }
      v10 = KeyValues::FindKey(this: FirstTrueSubKey, keyName: "gameModes", bCreate: false);
      if ( v10 != nullptr )
      {
        NextTrueSubKey = KeyValues::GetFirstTrueSubKey(this: v10);
        if ( NextTrueSubKey != nullptr )
        {
          do
          {
            v12 = (GameTypes::GameMode *)operator new(nSize: 0xB0u);
            if ( v12 != nullptr )
            {
              v13 = GameTypes::GameMode::GameMode(this: v12);
              pGameMode = v13;
            }
            else
            {
              pGameMode = nullptr;
              v13 = nullptr;
            }
            v14 = KeyValues::GetName(this: NextTrueSubKey);
            V_strncpy(pDest: v13->m_Name, pSrc: v14, maxLen: 32);
            v15 = KeyValues::GetString(this: NextTrueSubKey, keyName: "nameID", defaultValue: defaultValue);
            if ( v15 != nullptr )
            {
              V_strncpy(pDest: v13->m_NameID, pSrc: v15, maxLen: 32);
              v16 = (void (*)(const char *, ...))_Warning;
            }
            else
            {
              v56 = KeyValues::GetName(this: NextTrueSubKey);
              v17 = KeyValues::GetName(this: FirstTrueSubKey);
              v16 = (void (*)(const char *, ...))_Warning;
              _Warning(a1: "GameTypes: missing %s entry for game type/mode (%s/%s).\n", "nameID", v17, v56);
            }
            v18 = KeyValues::GetString(this: NextTrueSubKey, keyName: "descID", defaultValue: defaultValue);
            if ( v18 != nullptr )
            {
              V_strncpy(pDest: pGameMode->m_DescID, pSrc: v18, maxLen: 32);
            }
            else
            {
              v57 = KeyValues::GetName(this: NextTrueSubKey);
              v19 = KeyValues::GetName(this: FirstTrueSubKey);
              v16(a1: "GameTypes: missing %s entry for game type/mode (%s/%s).\n", "descID", v19, v57);
            }
            v20 = KeyValues::FindKey(this: NextTrueSubKey, keyName: "convars", bCreate: false);
            if ( v20 != nullptr )
            {
              pGameMode->m_pConvarsSP = KeyValues::MakeCopy(this: v20);
            }
            else
            {
              v58 = KeyValues::GetName(this: NextTrueSubKey);
              v21 = KeyValues::GetName(this: FirstTrueSubKey);
              v16(a1: "GameTypes: missing entry %s for game type/mode (%s/%s).\n", "convars", v21, v58);
            }
            v22 = KeyValues::FindKey(this: NextTrueSubKey, keyName: "convars_mp", bCreate: false);
            if ( v22 != nullptr )
              pGameMode->m_pConvarsMP = KeyValues::MakeCopy(this: v22);
            v23 = KeyValues::FindKey(this: NextTrueSubKey, keyName: "maps", bCreate: false);
            if ( v23 != nullptr )
            {
              FirstValue = KeyValues::GetFirstValue(this: v23);
              pKV_Map = FirstValue;
              if ( FirstValue != nullptr )
              {
                while ( 1 )
                {
                  v25 = KeyValues::GetName(this: FirstValue);
                  if ( _V_stricmp(s1: v25, s2: "random") != 0 )
                  {
                    v26 = KeyValues::GetName(this: FirstValue);
                    pKV_WeaponProgressionT = (char *)operator new(nSize: strlen(v26) + 1);
                    _V_strcpy(dest: pKV_WeaponProgressionT, src: v26);
                    m_Size = pGameMode->m_Maps.m_Size;
                    m_nAllocationCount = pGameMode->m_Maps.m_Memory.m_nAllocationCount;
                    if ( m_Size + 1 > m_nAllocationCount )
                      CUtlMemory<GCSDK::CLock *,int>::Grow(
                        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&pGameMode->m_Maps,
                        num: m_Size - m_nAllocationCount + 1);
                    ++pGameMode->m_Maps.m_Size;
                    m_pMemory = pGameMode->m_Maps.m_Memory.m_pMemory;
                    v30 = pGameMode->m_Maps.m_Size - m_Size - 1;
                    pGameMode->m_Maps.m_pElements = m_pMemory;
                    if ( v30 > 0 )
                      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v30);
                    v31 = &pGameMode->m_Maps.m_Memory.m_pMemory[m_Size];
                    if ( v31 != nullptr )
                      *v31 = pKV_WeaponProgressionT;
                    FirstValue = pKV_Map;
                  }
                  pKV_Map = KeyValues::GetNextValue(this: FirstValue);
                  if ( pKV_Map == nullptr )
                    break;
                  FirstValue = pKV_Map;
                }
              }
              if ( pGameMode->m_Maps.m_Size == 0 )
              {
                v59 = KeyValues::GetName(this: NextTrueSubKey);
                v32 = KeyValues::GetName(this: pKV_GameType);
                _Warning(a1: "GameTypes: empty %s entry for game type/mode (%s/%s).\n", "maps", v32, v59);
              }
            }
            else
            {
              v60 = KeyValues::GetName(this: NextTrueSubKey);
              v33 = KeyValues::GetName(this: FirstTrueSubKey);
              v16(a1: "GameTypes: missing %s entry for game type/mode (%s/%s).\n", "maps", v33, v60);
            }
            v34 = KeyValues::FindKey(this: NextTrueSubKey, keyName: "weaponprogression_ct", bCreate: false);
            v61 = KeyValues::GetName(this: NextTrueSubKey);
            v35 = KeyValues::GetName(this: pKV_GameType);
            GameTypes::LoadWeaponProgression(
              this,
              pKV_WeaponProgression: v34,
              vecWeaponProgression: &pGameMode->m_WeaponProgressionCT,
              szGameType: v35,
              szGameMode: v61);
            pKV_WeaponProgressionTc = KeyValues::FindKey(
                                        this: NextTrueSubKey,
                                        keyName: "weaponprogression_t",
                                        bCreate: false);
            v62 = KeyValues::GetName(this: NextTrueSubKey);
            v36 = KeyValues::GetName(this: pKV_GameType);
            GameTypes::LoadWeaponProgression(
              this,
              pKV_WeaponProgression: pKV_WeaponProgressionTc,
              vecWeaponProgression: &pGameMode->m_WeaponProgressionT,
              szGameType: v36,
              szGameMode: v62);
            v37 = KeyValues::FindKey(this: NextTrueSubKey, keyName: "no_reset_vote_threshold_t", bCreate: false);
            if ( v37 != nullptr )
            {
              s2 = (char *)KeyValues::GetString(this: v37, keyName: nullptr, defaultValue: defaultValue);
              pKV_WeaponProgressionTa = nullptr;
              if ( pGameMode->m_WeaponProgressionT.m_Size <= 0 )
              {
LABEL_53:
                v40 = -1;
              }
              else
              {
                pKV_Mapa = nullptr;
                while ( 1 )
                {
                  v38 = CUtlString::operator char const *(this: (CUtlString *)((char *)pKV_Mapa
                                                                             + (unsigned int)pGameMode->m_WeaponProgressionT.m_Memory.m_pMemory));
                  v39 = _V_strcmp(s1: v38, s2) == 0;
                  v40 = (int)pKV_WeaponProgressionTa;
                  if ( v39 )
                    break;
                  pKV_Mapa = (KeyValues *)((char *)pKV_Mapa + 20);
                  pKV_WeaponProgressionTa = (KeyValues *)((char *)pKV_WeaponProgressionTa + 1);
                  if ( (int)pKV_WeaponProgressionTa >= pGameMode->m_WeaponProgressionT.m_Size )
                    goto LABEL_53;
                }
              }
              pGameMode->m_NoResetVoteThresholdT = v40;
            }
            v41 = KeyValues::FindKey(this: NextTrueSubKey, keyName: "no_reset_vote_threshold_ct", bCreate: false);
            v42 = 0;
            if ( v41 != nullptr )
            {
              s2a = (char *)KeyValues::GetString(this: v41, keyName: nullptr, defaultValue: defaultValue);
              if ( pGameMode->m_WeaponProgressionCT.m_Size <= 0 )
              {
LABEL_60:
                v42 = -1;
              }
              else
              {
                pKV_WeaponProgressionTb = nullptr;
                while ( 1 )
                {
                  v43 = CUtlString::operator char const *(this: (CUtlString *)((char *)pKV_WeaponProgressionTb
                                                                             + (unsigned int)pGameMode->m_WeaponProgressionCT.m_Memory.m_pMemory));
                  if ( _V_strcmp(s1: v43, s2: s2a) == 0 )
                    break;
                  pKV_WeaponProgressionTb = (KeyValues *)((char *)pKV_WeaponProgressionTb + 20);
                  if ( ++v42 >= pGameMode->m_WeaponProgressionCT.m_Size )
                    goto LABEL_60;
                }
              }
              pGameMode->m_NoResetVoteThresholdCT = v42;
            }
            pGameMode->m_Index = pGameType->m_GameModes.m_Size;
            v44 = pGameType->m_GameModes.m_Size;
            v45 = pGameType->m_GameModes.m_Memory.m_nAllocationCount;
            if ( v44 + 1 > v45 )
              CUtlMemory<GCSDK::CLock *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&pGameType->m_GameModes,
                num: v44 - v45 + 1);
            ++pGameType->m_GameModes.m_Size;
            v46 = pGameType->m_GameModes.m_Memory.m_pMemory;
            v47 = pGameType->m_GameModes.m_Size - v44 - 1;
            pGameType->m_GameModes.m_pElements = v46;
            if ( v47 > 0 )
              _V_memmove(dest: &v46[v44 + 1], src: &v46[v44], count: 4 * v47);
            v48 = &pGameType->m_GameModes.m_Memory.m_pMemory[v44];
            if ( v48 != nullptr )
              *v48 = pGameMode;
            FirstTrueSubKey = pKV_GameType;
            NextTrueSubKey = KeyValues::GetNextTrueSubKey(this: NextTrueSubKey);
          }
          while ( NextTrueSubKey != nullptr );
          v6 = pGameType;
        }
      }
      else
      {
        v55 = KeyValues::GetName(this: FirstTrueSubKey);
        _Warning(a1: "GameTypes: missing %s entry for game type %s.\n", "gameModes", v55);
      }
      if ( v6->m_GameModes.m_Size == 0 )
      {
        v49 = KeyValues::GetName(this: FirstTrueSubKey);
        _Warning(a1: "GameTypes: empty %s entry for game type %s.\n", "gameModes", v49);
      }
      v6->m_Index = this->m_GameTypes.m_Size;
      v50 = this->m_GameTypes.m_Size;
      v51 = this->m_GameTypes.m_Memory.m_nAllocationCount;
      if ( v50 + 1 > v51 )
        CUtlMemory<GCSDK::CLock *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_GameTypes,
          num: v50 - v51 + 1);
      ++this->m_GameTypes.m_Size;
      v52 = this->m_GameTypes.m_Memory.m_pMemory;
      v53 = this->m_GameTypes.m_Size - v50 - 1;
      this->m_GameTypes.m_pElements = v52;
      if ( v53 > 0 )
        _V_memmove(dest: &v52[v50 + 1], src: &v52[v50], count: 4 * v53);
      v54 = &this->m_GameTypes.m_Memory.m_pMemory[v50];
      if ( v54 != nullptr )
        *v54 = v6;
      pKV_GameType = KeyValues::GetNextTrueSubKey(this: pKV_GameType);
      if ( pKV_GameType == nullptr )
        break;
      FirstTrueSubKey = pKV_GameType;
    }
  }
  if ( this->m_GameTypes.m_Size == 0 )
    _Warning(a1: "GameTypes: empty %s entry.\n", "gameTypes");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10004F70
// Name: public: virtual bool GameTypes::Initialize(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GameTypes::Initialize(GameTypes *this, bool force)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IBaseFileSystem *v6; // eax

  if ( this->m_Initialized && !force )
    return 1;
  DevMsg(a1: "GameTypes: initializing game types interface from %s.\n", "GameModes.txt");
  CUtlVector<GameTypes::GameType *,CUtlMemory<GameTypes::GameType *,int>>::PurgeAndDeleteElements(this: &this->m_GameTypes);
  CUtlVector<GameTypes::Map *,CUtlMemory<GameTypes::Map *,int>>::PurgeAndDeleteElements(this: &this->m_Maps);
  CUtlVector<GameTypes::FreestyleBotDifficulty *,CUtlMemory<GameTypes::FreestyleBotDifficulty *,int>>::PurgeAndDeleteElements(this: &this->m_FreestyleBotDifficulties);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: defaultValue);
  else
    v5 = nullptr;
  if ( g_pFullFileSystem != nullptr )
    v6 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v6 = nullptr;
  if ( !KeyValues::LoadFromFile(
          this: v5,
          filesystem: v6,
          resourceName: "GameModes.txt",
          pathID: nullptr,
          pfnEvaluateSymbolProc: nullptr) )
  {
    _Warning(a1: "GameTypes: error loading %s.", "GameModes.txt");
    goto LABEL_12;
  }
  DLCHelper::AppendDLCKeyValues(pKeyValues: v5, fileName: "GameModes.txt", startDir: nullptr);
  if ( GameTypes::LoadGameTypes(this, pKV: v5) == 0
    || GameTypes::LoadMaps(this, pKV: v5) == 0
    || GameTypes::LoadFreestyleBotDifficulties(this, pKV: v5) == 0 )
  {
LABEL_12:
    if ( v5 != nullptr )
      KeyValues::deleteThis(this: v5);
    return 0;
  }
  this->m_Initialized = true;
  if ( v5 != nullptr )
    KeyValues::deleteThis(this: v5);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100054B0
// Name: public: int CUtlVector<struct CMatchExtensions::RegisteredInterface_t,class CUtlMemory<struct CMatchExtensions::RegisteredInterface_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CMatchExtensions::RegisteredInterface_t,CUtlMemory<CMatchExtensions::RegisteredInterface_t,int>>::InsertMultipleBefore(
        CUtlVector<CMatchExtensions::RegisteredInterface_t,CUtlMemory<CMatchExtensions::RegisteredInterface_t,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CMatchExtensions::RegisteredInterface_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CMatchExtensions::RegisteredInterface_t *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<unsigned __int64,int>::Grow(
      (CUtlMemory<CThreadSafeMemoryPool::BlockSet_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 8 * v9);
  if ( num > 0 )
  {
    v10 = elem;
    do
    {
      v11 = &this->m_Memory.m_pMemory[v10];
      if ( v11 != nullptr )
      {
        v11->m_pvInterface = nullptr;
        v11->m_nRefCount = 0;
      }
      ++v10;
      --v3;
    }
    while ( v3 != 0 );
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10009AC0
// Name: public: CUtlVector<struct CMatchTitleGameSettingsMgr::SearchPass __near *,class CUtlMemory<struct CMatchTitleGameSettingsMgr::SearchPass __near *,int>>::~CUtlVector<struct CMatchTitleGameSettingsMgr::SearchPass __near *,class CUtlMemory<struct CMatchTitleGameSettingsMgr::SearchPass __near *,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(
        CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *this)
{
  bool v2; // sf
  CUtlSymbolTable::StringPool_t **m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B2F0
// Name: public: int CUtlVector<unsigned __int64,class CUtlMemory<unsigned __int64,int>>::Find(unsigned __int64 const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int>>::Find(
        CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *this,
        const unsigned __int64 *src)
{
  int m_Size; // edx
  int result; // eax
  unsigned __int64 *i; // ecx

  m_Size = this->m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_Memory.m_pMemory; *(_DWORD *)i != *(_DWORD *)src || *((_DWORD *)i + 1) != *((_DWORD *)src + 1); ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000B330
// Name: public: bool CUtlVector<unsigned __int64,class CUtlMemory<unsigned __int64,int>>::FindAndRemove(unsigned __int64 const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int>>::FindAndRemove(
        CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *this,
        const unsigned __int64 *src)
{
  int m_Size; // edx
  int v4; // eax
  unsigned __int64 *i; // ecx
  int v7; // edx

  m_Size = this->m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  for ( i = this->m_Memory.m_pMemory; *(_DWORD *)i != *(_DWORD *)src || *((_DWORD *)i + 1) != *((_DWORD *)src + 1); ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  if ( v4 == -1 )
    return 0;
  v7 = m_Size - v4;
  if ( v7 - 1 > 0 )
    _V_memmove(dest: &this->m_Memory.m_pMemory[v4], src: &this->m_Memory.m_pMemory[v4 + 1], count: 8 * (v7 - 1));
  --this->m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000B3B0
// Name: public: void CUtlVector<unsigned __int64,class CUtlMemory<unsigned __int64,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int>>::Purge(
        CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *this)
{
  bool v2; // sf
  unsigned __int64 *m_pMemory; // ecx

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v2 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B720
// Name: public: int CUtlVector<unsigned __int64,class CUtlMemory<unsigned __int64,int>>::InsertBefore(int,unsigned __int64 const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int>>::InsertBefore(
        CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *this,
        int elem,
        unsigned __int64 *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  unsigned __int64 *m_pMemory; // ecx
  int v7; // eax
  unsigned __int64 *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned __int64,int>::Grow(
      (CUtlMemory<CThreadSafeMemoryPool::BlockSet_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100118A0
// Name: public: int CUtlVector<struct GCSDK::CJobMgr::JobSleeping_t,class CUtlMemory<struct GCSDK::CJobMgr::JobSleeping_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<GCSDK::CJobMgr::JobSleeping_t,CUtlMemory<GCSDK::CJobMgr::JobSleeping_t,int>>::InsertBefore(
        CUtlVector<GCSDK::CJobMgr::JobSleeping_t,CUtlMemory<GCSDK::CJobMgr::JobSleeping_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  GCSDK::CJobMgr::JobSleeping_t *m_pMemory; // ecx
  int v6; // eax
  GCSDK::CJobMgr::JobSleeping_t *v7; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,int,int>::Node_t,int>,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    GCSDK::CJobTime::CJobTime(this: &v7->m_SWakeupTime);
    GCSDK::CJobTime::CJobTime(this: &v7->m_STimeTouched);
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1001A6E0
// Name: public: void CUtlVector<class GCSDK::CSharedObject __near *,class CUtlMemory<class GCSDK::CSharedObject __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<GCSDK::CSharedObject *,CUtlMemory<GCSDK::CSharedObject *,int>>::PurgeAndDeleteElements(
        CUtlVector<GCSDK::CSharedObject *,CUtlMemory<GCSDK::CSharedObject *,int> > *this)
{
  int i; // edi
  GCSDK::CSharedObject *v3; // ecx
  bool v4; // sf
  GCSDK::CSharedObject **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
      ((void (__thiscall *)(GCSDK::CSharedObject *, int))v3->dtr_CSharedObject)(a1: v3, a2: 1);
  }
  v4 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v4 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D420
// Name: public: bool CUtlVector<int,class CUtlMemory<int,int>>::FindAndFastRemove(int const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<int,CUtlMemory<int,int>>::FindAndFastRemove(
        CUtlVector<CServer *,CUtlMemory<CServer *,int> > *this,
        CServer **src)
{
  int m_Size; // esi
  int v3; // eax
  CServer **i; // edx

  m_Size = this->m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return 0;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++v3 >= m_Size )
      return 0;
  }
  if ( v3 == -1 )
    return 0;
  if ( v3 != m_Size - 1 )
    this->m_Memory.m_pMemory[v3] = this->m_Memory.m_pMemory[m_Size - 1];
  --this->m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001D470
// Name: public: void CUtlVector<class CServer __near *,class CUtlMemory<class CServer __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CServer *,CUtlMemory<CServer *,int>>::PurgeAndDeleteElements(
        CUtlVector<CServer *,CUtlMemory<CServer *,int> > *this)
{
  int i; // edi
  CServer *v3; // ecx
  bool v4; // sf
  CServer **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
      ((void (__thiscall *)(CServer *, int))v3->dtr_CServer)(a1: v3, a2: 1);
  }
  v4 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v4 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D4E0
// Name: public: int CUtlVector<class KeyValues __near *,class CUtlMemory<class KeyValues __near *,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int>>::InsertMultipleBefore(
        CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  unsigned int *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<GCSDK::CLock *,int>::Grow(
      (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10029130
// Name: public: bool CUtlVector<unsigned __int64,class CUtlMemory<unsigned __int64,int>>::FindAndFastRemove(unsigned __int64 const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int>>::FindAndFastRemove(
        CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int> > *this,
        const unsigned __int64 *src)
{
  int v2; // eax
  unsigned __int64 *m_pMemory; // esi
  unsigned __int64 *i; // edx
  int m_Size; // edx

  v2 = 0;
  if ( this->m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Memory.m_pMemory;
  for ( i = this->m_Memory.m_pMemory; *(_DWORD *)i != *(_DWORD *)src || *((_DWORD *)i + 1) != *((_DWORD *)src + 1); ++i )
  {
    if ( ++v2 >= this->m_Size )
      return 0;
  }
  if ( v2 == -1 )
    return 0;
  m_Size = this->m_Size;
  if ( m_Size > 0 )
  {
    if ( v2 != m_Size - 1 )
    {
      LODWORD(m_pMemory[v2]) = m_pMemory[m_Size - 1];
      HIDWORD(m_pMemory[v2]) = HIDWORD(m_pMemory[m_Size - 1]);
    }
    --this->m_Size;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10029650
// Name: public: bool CUtlVector<class GCSDK::CLock __near *,class CUtlMemory<class GCSDK::CLock __near *,int>>::FindAndRemove(class GCSDK::CLock __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<GCSDK::CLock *,CUtlMemory<GCSDK::CLock *,int>>::FindAndRemove(
        CUtlVector<GCSDK::CLock *,CUtlMemory<GCSDK::CLock *,int> > *this,
        GCSDK::CLock **src)
{
  int m_Size; // edx
  int v4; // eax
  GCSDK::CLock **m_pMemory; // ebx
  GCSDK::CLock **i; // ecx
  int v8; // edx

  m_Size = this->m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Memory.m_pMemory;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  if ( v4 == -1 )
    return 0;
  v8 = m_Size - v4 - 1;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v4], src: &m_pMemory[v4 + 1], count: 4 * v8);
  --this->m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1002F5F0
// Name: public: void CUtlMemory<struct MatchMakingKeyValuePair_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<MatchMakingKeyValuePair_t,int>::Grow(
        CUtlMemory<MatchMakingKeyValuePair_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  MatchMakingKeyValuePair_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = m_nAllocationCount << 9;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (MatchMakingKeyValuePair_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (MatchMakingKeyValuePair_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002F7F0
// Name: public: int CUtlVector<struct MatchMakingKeyValuePair_t,class CUtlMemory<struct MatchMakingKeyValuePair_t,int>>::InsertBefore(int,struct MatchMakingKeyValuePair_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<MatchMakingKeyValuePair_t,CUtlMemory<MatchMakingKeyValuePair_t,int>>::InsertBefore(
        CUtlVector<MatchMakingKeyValuePair_t,CUtlMemory<MatchMakingKeyValuePair_t,int> > *this,
        int elem,
        const MatchMakingKeyValuePair_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  MatchMakingKeyValuePair_t *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<MatchMakingKeyValuePair_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: v7 << 9);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002FA10
// Name: public: int CUtlVector<struct CDsSearcher::DsServer_t,class CUtlMemory<struct CDsSearcher::DsServer_t,int>>::InsertBefore(int,struct CDsSearcher::DsServer_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDsSearcher::DsServer_t,CUtlMemory<CDsSearcher::DsServer_t,int>>::InsertBefore(
        CUtlVector<CDsSearcher::DsServer_t,CUtlMemory<CDsSearcher::DsServer_t,int> > *this,
        int elem,
        const CDsSearcher::DsServer_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDsSearcher::DsServer_t *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CDsSearcher::DsServer_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 516 * v7);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100309C0
// Name: public: int CUtlVector<struct CMatchSearcher::SearchResult_t,class CUtlMemory<struct CMatchSearcher::SearchResult_t,int>>::InsertMultipleBefore(int,int,struct CMatchSearcher::SearchResult_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CMatchSearcher::SearchResult_t,CUtlMemory<CMatchSearcher::SearchResult_t,int>>::InsertMultipleBefore(
        CUtlVector<CMatchSearcher::SearchResult_t,CUtlMemory<CMatchSearcher::SearchResult_t,int> > *this,
        int elem,
        int num,
        const CMatchSearcher::SearchResult_t *pToInsert)
{
  int v4; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CMatchSearcher::SearchResult_t *m_pMemory; // ecx
  int v10; // eax
  const CMatchSearcher::SearchResult_t *v11; // edx
  int v12; // eax
  CMatchSearcher::SearchResult_t *v13; // ecx

  v4 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CMatchSearcher::SearchResult_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 > 0 && num > 0 )
    _V_memmove(dest: (void *)&m_pMemory[elem + num], src: &m_pMemory[elem], count: 16 * v10);
  v11 = pToInsert;
  if ( pToInsert != nullptr && num > 0 )
  {
    v12 = elem;
    do
    {
      v13 = &this->m_Memory.m_pMemory[v12];
      if ( v13 != nullptr )
      {
        v13->m_uiLobbyId = v11->m_uiLobbyId;
        *(_QWORD *)&v13->m_pGameDetails = *(_QWORD *)&v11->m_pGameDetails;
      }
      ++v12;
      ++v11;
      --v4;
    }
    while ( v4 != 0 );
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100310F0
// Name: public: void CUtlVector<class GCSDK::CSchema,class CUtlMemory<class GCSDK::CSchema,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<GCSDK::CSchema,CUtlMemory<GCSDK::CSchema,int>>::Purge(
        CUtlVector<GCSDK::CSchema,CUtlMemory<GCSDK::CSchema,int> > *this)
{
  int v2; // esi
  int v3; // ebx
  GCSDK::CSchema *m_pMemory; // ecx

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      GCSDK::CSchema::~CSchema(this: &this->m_Memory.m_pMemory[v3--]);
      --v2;
    }
    while ( v2 >= 0 );
  }
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031200
// Name: public: void CUtlVector<class GCSDK::CFTSCatalogInfo,class CUtlMemory<class GCSDK::CFTSCatalogInfo,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<GCSDK::CFTSCatalogInfo,CUtlMemory<GCSDK::CFTSCatalogInfo,int>>::Purge(
        CUtlVector<GCSDK::CFTSCatalogInfo,CUtlMemory<GCSDK::CFTSCatalogInfo,int> > *this)
{
  int v2; // esi
  int v3; // ebx
  GCSDK::CFTSCatalogInfo *m_pMemory; // ecx

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      free(pMem: (void *)this->m_Memory.m_pMemory[v3--].m_pstrName);
      --v2;
    }
    while ( v2 >= 0 );
  }
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100312D0
// Name: public: void CUtlVector<class GCSDK::CTriggerInfo,class CUtlMemory<class GCSDK::CTriggerInfo,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<GCSDK::CTriggerInfo,CUtlMemory<GCSDK::CTriggerInfo,int>>::RemoveAll(
        CUtlVector<GCSDK::CTriggerInfo,CUtlMemory<GCSDK::CTriggerInfo,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  GCSDK::CTriggerInfo *v3; // esi
  CUtlVector<GCSDK::CTriggerInfo,CUtlMemory<GCSDK::CTriggerInfo,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v3->m_strText.m_Storage.m_nActualLength = 0;
      if ( v3->m_strText.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_strText.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_strText.m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->m_strText.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_strText.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031350
// Name: public: CUtlVector<class GCSDK::CTriggerInfo,class CUtlMemory<class GCSDK::CTriggerInfo,int>>::~CUtlVector<class GCSDK::CTriggerInfo,class CUtlMemory<class GCSDK::CTriggerInfo,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<GCSDK::CTriggerInfo,CUtlMemory<GCSDK::CTriggerInfo,int>>::~CUtlVector<GCSDK::CTriggerInfo,CUtlMemory<GCSDK::CTriggerInfo,int>>(
        CUtlVector<GCSDK::CTriggerInfo,CUtlMemory<GCSDK::CTriggerInfo,int> > *this)
{
  bool v2; // sf
  GCSDK::CTriggerInfo *m_pMemory; // eax

  CUtlVector<GCSDK::CTriggerInfo,CUtlMemory<GCSDK::CTriggerInfo,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031560
// Name: public: void CUtlVector<class GCSDK::FieldSet_t,class CUtlMemory<class GCSDK::FieldSet_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<GCSDK::FieldSet_t,CUtlMemory<GCSDK::FieldSet_t,int>>::RemoveAll(
        CUtlVector<GCSDK::FieldSet_t,CUtlMemory<GCSDK::FieldSet_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  void *v5; // eax
  CUtlVector<GCSDK::FieldSet_t,CUtlMemory<GCSDK::FieldSet_t,int> > *v6; // [esp+4h] [ebp-8h]
  int v7; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 176 * v1;
    v7 = 176 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 8) = 0;
      if ( *((int *)v3 + 7) >= 0 )
      {
        if ( *((_DWORD *)v3 + 5) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 5));
          *((_DWORD *)v3 + 5) = 0;
        }
        *((_DWORD *)v3 + 6) = 0;
      }
      v4 = *((void **)v3 + 5);
      *((_DWORD *)v3 + 9) = v4;
      if ( *((int *)v3 + 7) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          *((_DWORD *)v3 + 5) = 0;
        }
        *((_DWORD *)v3 + 6) = 0;
      }
      *((_DWORD *)v3 + 3) = 0;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( *(_DWORD *)v3 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v3);
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      v5 = *(void **)v3;
      *((_DWORD *)v3 + 4) = *(_DWORD *)v3;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( v5 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      this = v6;
      --v1;
      v2 = v7 - 176;
      v7 -= 176;
    }
    while ( v1 >= 0 );
    v6->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031650
// Name: public: CUtlVector<class GCSDK::FieldSet_t,class CUtlMemory<class GCSDK::FieldSet_t,int>>::~CUtlVector<class GCSDK::FieldSet_t,class CUtlMemory<class GCSDK::FieldSet_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<GCSDK::FieldSet_t,CUtlMemory<GCSDK::FieldSet_t,int>>::~CUtlVector<GCSDK::FieldSet_t,CUtlMemory<GCSDK::FieldSet_t,int>>(
        CUtlVector<GCSDK::FieldSet_t,CUtlMemory<GCSDK::FieldSet_t,int> > *this)
{
  bool v2; // sf
  GCSDK::FieldSet_t *m_pMemory; // eax

  CUtlVector<GCSDK::FieldSet_t,CUtlMemory<GCSDK::FieldSet_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100316B0
// Name: public: void CUtlVector<struct GCSDK::FKData_t,class CUtlMemory<struct GCSDK::FKData_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<GCSDK::FKData_t,CUtlMemory<GCSDK::FKData_t,int>>::RemoveAll(
        CUtlVector<GCSDK::FKData_t,CUtlMemory<GCSDK::FKData_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<GCSDK::FKData_t,CUtlMemory<GCSDK::FKData_t,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 292 * v1;
    v5 = 292 * v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory->m_rgchName[v2];
      *((_DWORD *)v3 + 65) = &CCopyableUtlVector<GCSDK::FKColumnRelation_t>::`vftable';
      *((_DWORD *)v3 + 69) = 0;
      if ( *((int *)v3 + 68) >= 0 )
      {
        if ( *((_DWORD *)v3 + 66) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 66));
          this = v6;
          *((_DWORD *)v3 + 66) = 0;
        }
        *((_DWORD *)v3 + 67) = 0;
      }
      v4 = *((void **)v3 + 66);
      *((_DWORD *)v3 + 70) = v4;
      if ( *((int *)v3 + 68) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          this = v6;
          *((_DWORD *)v3 + 66) = 0;
        }
        *((_DWORD *)v3 + 67) = 0;
      }
      --v1;
      v2 = v5 - 292;
      v5 -= 292;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031790
// Name: public: CUtlVector<struct GCSDK::FKData_t,class CUtlMemory<struct GCSDK::FKData_t,int>>::~CUtlVector<struct GCSDK::FKData_t,class CUtlMemory<struct GCSDK::FKData_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<GCSDK::FKData_t,CUtlMemory<GCSDK::FKData_t,int>>::~CUtlVector<GCSDK::FKData_t,CUtlMemory<GCSDK::FKData_t,int>>(
        CUtlVector<GCSDK::FKData_t,CUtlMemory<GCSDK::FKData_t,int> > *this)
{
  bool v2; // sf
  GCSDK::FKData_t *m_pMemory; // eax

  CUtlVector<GCSDK::FKData_t,CUtlMemory<GCSDK::FKData_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002BA0
// Name: __CreateGameTypesIGameTypes_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
GameTypes *__cdecl _CreateGameTypesIGameTypes_interface()
{
  return &s_GameTypes;
}

//------------------------------------------------------------------------------
// Address: 0x10005070
// Name: void __near * operator new(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x10005090
// Name: __calloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl _calloc_crt(unsigned int count, unsigned int size)
{
  unsigned __int8 *v2; // edi

  v2 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: size * count);
  memset(dst: v2, value: 0, count: size * count);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100050C0
// Name: __realloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl _realloc_crt(void *ptr, unsigned int size)
{
  return _g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: ptr, a3: size);
}

//------------------------------------------------------------------------------
// Address: 0x100050E0
// Name: __recalloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl _recalloc_crt(void *ptr, unsigned int count, unsigned int size)
{
  unsigned __int8 *v3; // edi

  v3 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: ptr, a3: size * count);
  memset(dst: v3, value: 0, count: size * count);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10005120
// Name: __msize
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _msize(void *pMem)
{
  return _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: pMem);
}

//------------------------------------------------------------------------------
// Address: 0x10005140
// Name: __heap_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _heap_init()
{
  return _g_pMemAlloc != nullptr;
}

} // namespace matchmaking
