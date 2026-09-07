// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: matchmaking/stub/mm_title_titledata.cpp
// Functions: 3
// ============================================================

#include "matchmaking\stub\mm_title_titledata.h"

//------------------------------------------------------------------------------
// Address: 0x10001B90
// Name: public: virtual struct TitleDataFieldsDescription_t const __near * CMatchTitle::DescribeTitleDataStorage(void)
// Source: json
//------------------------------------------------------------------------------
const TitleDataFieldsDescription_t *__thiscall CMatchTitle::DescribeTitleDataStorage(CMatchTitle *this)
{
  return tdfd;
}

//------------------------------------------------------------------------------
// Address: 0x10001BA0
// Name: public: virtual struct TitleAchievementsDescription_t const __near * CMatchTitle::DescribeTitleAchievements(void)
// Source: json
//------------------------------------------------------------------------------
const TitleAchievementsDescription_t *__thiscall CMatchTitle::DescribeTitleAchievements(CMatchTitle *this)
{
  return tad;
}

//------------------------------------------------------------------------------
// Address: 0x10001BB0
// Name: public: virtual struct TitleAvatarAwardsDescription_t const __near * CMatchTitle::DescribeTitleAvatarAwards(void)
// Source: json
//------------------------------------------------------------------------------
const TitleAvatarAwardsDescription_t *__thiscall CMatchTitle::DescribeTitleAvatarAwards(CMatchTitle *this)
{
  return taad;
}

// ============================================================
// Overlay from matchmaking_ds (Missing functions)
// ============================================================
namespace matchmaking_ds {

//------------------------------------------------------------------------------
// Address: 0x100011B0
// Name: public: virtual unsigned __int64 CMatchTitle::GetTitleSettingsFlags(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CMatchTitle::GetTitleSettingsFlags(CMatchTitle *this)
{
  return 33;
}

//------------------------------------------------------------------------------
// Address: 0x10002880
// Name: public: virtual struct TitleAchievementsDescription_t const __near * CMatchTitle::DescribeTitleAchievements(void)
// Source: json
//------------------------------------------------------------------------------
const TitleAchievementsDescription_t *__thiscall CMatchTitle::DescribeTitleAchievements(CMatchTitle *this)
{
  return tad;
}

//------------------------------------------------------------------------------
// Address: 0x10002890
// Name: public: virtual struct TitleAvatarAwardsDescription_t const __near * CMatchTitle::DescribeTitleAvatarAwards(void)
// Source: json
//------------------------------------------------------------------------------
const TitleAvatarAwardsDescription_t *__thiscall CMatchTitle::DescribeTitleAvatarAwards(CMatchTitle *this)
{
  return taad;
}

//------------------------------------------------------------------------------
// Address: 0x100028A0
// Name: public: virtual struct TitleDlcDescription_t const __near * CMatchTitle::DescribeTitleDlcs(void)
// Source: json
//------------------------------------------------------------------------------
const TitleDlcDescription_t *__thiscall CMatchTitle::DescribeTitleDlcs(CMatchTitle *this)
{
  return tdlcs;
}

//------------------------------------------------------------------------------
// Address: 0x100028B0
// Name: public: virtual struct TitleDataFieldsDescription_t const __near * CMatchTitle::DescribeTitleDataStorage(void)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolTable::StringPool_t **__thiscall CMatchTitle::DescribeTitleDataStorage(CMatchTitle *this)
{
  if ( (_S2_0 & 1) != 0 )
    return (CUtlSymbolTable::StringPool_t **)s_pTDFD;
  _S2_0 |= 1u;
  if ( (_S1_0 & 1) == 0 )
  {
    _S1_0 |= 1u;
    stru_10046E50.m_Memory.m_pMemory = nullptr;
    stru_10046E50.m_Memory.m_nAllocationCount = 0;
    stru_10046E50.m_Memory.m_nGrowSize = 0;
    stru_10046E50.m_Size = 0;
    stru_10046E50.m_pElements = nullptr;
    atexit(func: PrepareTitleDataStorageDescription_::_2_::_dynamic_atexit_destructor_for__s_tdfd__);
  }
  s_pTDFD = (const TitleDataFieldsDescription_t *)stru_10046E50.m_Memory.m_pMemory;
  return stru_10046E50.m_Memory.m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x10002940
// Name: public: static unsigned __int64 DLCHelper::GetInstalledDLCMask(void)
// Source: linker_block_proximity
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
// Address: 0x100029F0
// Name: public: static void DLCHelper::AppendDLCKeyValues(class KeyValues __near *,char const __near *,char const __near *)
// Source: linker_block_proximity
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
      v5 = KeyValues::KeyValues(this: v4, setName: str);
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
// Address: 0x10002B60
// Name: __CreateGameTypesIGameTypes_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
GameTypes *__cdecl _CreateGameTypesIGameTypes_interface()
{
  return &s_GameTypes;
}

//------------------------------------------------------------------------------
// Address: 0x10002B70
// Name: public: virtual bool GameTypes::SetGameTypeAndMode(char const __near *,char const __near *)
// Source: linker_block_proximity
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
// Address: 0x10002C00
// Name: public: virtual int GameTypes::GetCurrentGameType(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall GameTypes::GetCurrentGameType(GameTypes *this)
{
  if ( game_type.m_pParent != nullptr )
    return game_type.m_pParent->m_Value.m_nValue;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10002C10
// Name: public: virtual int GameTypes::GetCurrentGameMode(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall GameTypes::GetCurrentGameMode(GameTypes *this)
{
  if ( game_mode.m_pParent != nullptr )
    return game_mode.m_pParent->m_Value.m_nValue;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10002C20
// Name: private: void GameTypes::DisplayConvars(class KeyValues __near *,char const __near *)
// Source: linker_block_proximity
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
      String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: str);
      v6 = KeyValues::GetName(this: i);
      ConMsg(a1: "\t\"%s\": current value (\"%s\"), expected value (\"%s\")\n", v6, m_pszString, String);
    }
    ConMsg(a1: "}\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002CB0
// Name: public: virtual int GameTypes::GetFreestyleBotDifficulty(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall GameTypes::GetFreestyleBotDifficulty(GameTypes *this)
{
  if ( freestyle_bot_difficulty.m_pParent != nullptr )
    return freestyle_bot_difficulty.m_pParent->m_Value.m_nValue;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10002CC0
// Name: void DisplayGameModeConvars(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DisplayGameModeConvars()
{
  if ( g_pGameTypes != nullptr )
    g_pGameTypes->DisplayConvarsForCurrentMode(this: g_pGameTypes);
}

//------------------------------------------------------------------------------
// Address: 0x10002CE0
// Name: public: virtual bool GameTypes::SetFreestyleBotDifficulty(int)
// Source: linker_block_proximity
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

} // namespace matchmaking_ds
