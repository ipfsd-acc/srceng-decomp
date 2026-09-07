// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/bonusmapsdatabase.cpp
// Functions: 25
// ============================================================

#include "game\client\cstrike15\gameui\bonusmapsdatabase.h"

//------------------------------------------------------------------------------
// Address: 0x10126CA0
// Name: public: void CBonusMapsDatabase::ClearBonusMapsList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBonusMapsDatabase::ClearBonusMapsList(CMoveHelperClient *this)
{
  this->m_TouchList.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101FCD70
// Name: void GetBooleanStatus(class KeyValues __near *,struct BonusMapDescription_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetBooleanStatus(KeyValues *pBonusFilesKey, BonusMapDescription_t *map)
{
  KeyValues *FirstSubKey; // esi
  const char *Name; // eax
  KeyValues *NextKey; // esi
  const char *v5; // eax

  FirstSubKey = KeyValues::GetFirstSubKey(this: pBonusFilesKey);
  if ( FirstSubKey != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstSubKey);
      if ( _V_strcmp(s1: Name, s2: map->szFileName) == 0 )
        break;
      FirstSubKey = KeyValues::GetNextTrueSubKey(this: FirstSubKey);
      if ( FirstSubKey == nullptr )
        return;
    }
    NextKey = KeyValues::GetFirstSubKey(this: FirstSubKey);
    if ( NextKey != nullptr )
    {
      while ( 1 )
      {
        v5 = KeyValues::GetName(this: NextKey);
        if ( _V_strcmp(s1: v5, s2: map->szMapName) == 0 )
          break;
        NextKey = KeyValues::GetNextKey(this: NextKey);
        if ( NextKey == nullptr )
          return;
      }
      map->bLocked = KeyValues::GetInt(this: NextKey, keyName: "lock", defaultValue: 0) != 0;
      map->bComplete = KeyValues::GetInt(this: NextKey, keyName: "complete", defaultValue: 0) != 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FCE30
// Name: bool SetBooleanStatus(class KeyValues __near *,char const __near *,char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl SetBooleanStatus(
        KeyValues *pBonusFilesKey,
        const char *pchName,
        const char *pchFileName,
        const char *pchMapName,
        bool bValue)
{
  KeyValues *i; // esi
  KeyValues *FirstSubKey; // edi
  const char *Name; // eax
  const char *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  bool bChanged; // [esp+7h] [ebp-1h]

  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pchFileName, a3: "MOD") )
  {
    bChanged = false;
    i = nullptr;
    FirstSubKey = KeyValues::GetFirstSubKey(this: pBonusFilesKey);
    if ( FirstSubKey != nullptr )
    {
      while ( 1 )
      {
        Name = KeyValues::GetName(this: FirstSubKey);
        if ( _V_strcmp(s1: Name, s2: pchFileName) == 0 )
          break;
        FirstSubKey = KeyValues::GetNextTrueSubKey(this: FirstSubKey);
        if ( FirstSubKey == nullptr )
          goto LABEL_11;
      }
      for ( i = KeyValues::GetFirstSubKey(this: FirstSubKey); i != nullptr; i = KeyValues::GetNextKey(this: i) )
      {
        v9 = KeyValues::GetName(this: i);
        if ( _V_strcmp(s1: v9, s2: pchMapName) == 0 )
          break;
      }
    }
    else
    {
LABEL_11:
      v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v10 != nullptr )
        FirstSubKey = KeyValues::KeyValues(this: v10, setName: pchFileName);
      else
        FirstSubKey = nullptr;
      KeyValues::AddSubKey(this: pBonusFilesKey, pSubkey: FirstSubKey);
    }
    if ( i == nullptr )
    {
      v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v11 != nullptr )
        i = KeyValues::KeyValues(this: v11, setName: pchMapName, firstKey: pchName, firstValue: "0");
      else
        i = nullptr;
      KeyValues::AddSubKey(this: FirstSubKey, pSubkey: i);
      bChanged = true;
    }
    if ( (KeyValues::GetInt(this: i, keyName: pchName, defaultValue: 0) != 0) != bValue )
    {
      bChanged = true;
      KeyValues::SetInt(this: i, keyName: pchName, value: bValue);
    }
    return bChanged;
  }
  else
  {
    DevMsg(a1: "Failed to set boolean status for file %s.", pchFileName);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FCF70
// Name: void GetChallengeMedals(struct ChallengeDescription_t __near *,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetChallengeMedals(
        ChallengeDescription_t *pChallengeDescription,
        int *iBest,
        int *iEarnedMedal,
        int *iNext,
        int *iNextMedal)
{
  int v5; // eax

  v5 = pChallengeDescription->iBest;
  *iBest = v5;
  if ( v5 == -1 )
  {
    *iEarnedMedal = 0;
  }
  else if ( v5 > pChallengeDescription->iGold )
  {
    if ( v5 > pChallengeDescription->iSilver )
      *iEarnedMedal = v5 <= pChallengeDescription->iBronze;
    else
      *iEarnedMedal = 2;
  }
  else
  {
    *iEarnedMedal = 3;
  }
  *iNext = -1;
  switch ( *iEarnedMedal )
  {
    case 0:
      *iNext = pChallengeDescription->iBronze;
      *iNextMedal = 1;
      break;
    case 1:
      *iNext = pChallengeDescription->iSilver;
      *iNextMedal = 2;
      break;
    case 2:
      *iNext = pChallengeDescription->iGold;
      *iNextMedal = 3;
      break;
    case 3:
      *iNext = -1;
      *iNextMedal = -1;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FD040
// Name: public: bool CBonusMapsDatabase::ReadBonusMapSaveData(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBonusMapsDatabase::ReadBonusMapSaveData(CBonusMapsDatabase *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  IBaseFileSystem *v5; // eax
  char szFilename[260]; // [esp+4h] [ebp-104h] BYREF

  if ( this->m_pBonusMapSavedData == nullptr )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "bonus_map_saved_data");
    else
      v3 = nullptr;
    this->m_pBonusMapSavedData = v3;
  }
  if ( g_bIsCreatingNewGameMenuForPreFetching )
    return 0;
  V_snprintf(pDest: szFilename, maxLen: 0x104u, pFormat: "save/bonus_maps_data.bmd");
  if ( g_pFullFileSystem != nullptr )
    v5 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v5 = nullptr;
  KeyValues::LoadFromFile(
    this: this->m_pBonusMapSavedData,
    filesystem: v5,
    resourceName: szFilename,
    pathID: nullptr,
    pfnEvaluateSymbolProc: nullptr);
  this->m_bSavedDataChanged = false;
  this->m_bHasLoadedSaveData = true;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101FD0D0
// Name: public: void CBonusMapsDatabase::RootPath(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBonusMapsDatabase::RootPath(CBonusMapsDatabase *this)
{
  this->m_iDirDepth = 0;
  _V_strcpy(dest: this->m_szCurrentPath, src: ".");
}

//------------------------------------------------------------------------------
// Address: 0x101FD0F0
// Name: public: void CBonusMapsDatabase::AppendPath(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBonusMapsDatabase::AppendPath(CBonusMapsDatabase *this, const char *pchAppend)
{
  ++this->m_iDirDepth;
  V_snprintf(pDest: this->m_szCurrentPath, maxLen: 0x104u, pFormat: "%s/%s", this->m_szCurrentPath, pchAppend);
}

//------------------------------------------------------------------------------
// Address: 0x101FD120
// Name: public: void CBonusMapsDatabase::BackPath(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBonusMapsDatabase::BackPath(CBonusMapsDatabase *this)
{
  int m_iDirDepth; // eax

  m_iDirDepth = this->m_iDirDepth;
  if ( m_iDirDepth != 0 )
  {
    if ( m_iDirDepth == 1 )
    {
      this->m_iDirDepth = 0;
      _V_strcpy(dest: this->m_szCurrentPath, src: ".");
    }
    else
    {
      this->m_iDirDepth = m_iDirDepth - 1;
      *_V_strrchr(s: this->m_szCurrentPath, c: 47) = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FD160
// Name: public: bool CBonusMapsDatabase::GetBlink(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBonusMapsDatabase::GetBlink(CBonusMapsDatabase *this)
{
  KeyValues *Key; // eax

  Key = KeyValues::FindKey(this: this->m_pBonusMapSavedData, keyName: "blink", bCreate: false);
  return Key != nullptr && KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101FD190
// Name: public: void CBonusMapsDatabase::SetBlink(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBonusMapsDatabase::SetBlink(CBonusMapsDatabase *this, bool bState)
{
  KeyValues *Key; // eax
  KeyValues *v4; // esi
  bool v5; // al

  Key = KeyValues::FindKey(this: this->m_pBonusMapSavedData, keyName: "blink", bCreate: false);
  v4 = Key;
  if ( Key != nullptr )
  {
    v5 = KeyValues::GetInt(this: Key, keyName: nullptr, defaultValue: 0) != 0;
    if ( bState )
    {
      if ( !v5 )
      {
        KeyValues::SetStringValue(this: v4, strValue: "1");
        this->m_bSavedDataChanged = true;
      }
    }
    else if ( v5 )
    {
      KeyValues::SetStringValue(this: v4, strValue: "0");
      this->m_bSavedDataChanged = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FD200
// Name: public: void CBonusMapsDatabase::SetCurrentChallengeNames(char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBonusMapsDatabase::SetCurrentChallengeNames(
        CBonusMapsDatabase *this,
        const char *pchFileName,
        const char *pchMapName,
        const char *pchChallengeName)
{
  _V_strcpy(dest: this->m_CurrentChallengeNames.szFileName, src: pchFileName);
  _V_strcpy(dest: this->m_CurrentChallengeNames.szMapName, src: pchMapName);
  _V_strcpy(dest: this->m_CurrentChallengeNames.szChallengeName, src: pchChallengeName);
}

//------------------------------------------------------------------------------
// Address: 0x101FD240
// Name: public: void CBonusMapsDatabase::SetCurrentChallengeObjectives(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBonusMapsDatabase::SetCurrentChallengeObjectives(
        CBonusMapsDatabase *this,
        int iBronze,
        int iSilver,
        int iGold)
{
  this->m_CurrentChallengeObjectives.iBronze = iBronze;
  this->m_CurrentChallengeObjectives.iSilver = iSilver;
  this->m_CurrentChallengeObjectives.iGold = iGold;
}

//------------------------------------------------------------------------------
// Address: 0x101FD270
// Name: public: float CBonusMapsDatabase::GetCompletionPercentage(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBonusMapsDatabase::GetCompletionPercentage(CBonusMapsDatabase *this)
{
  int m_iCompletableLevels; // [esp+0h] [ebp-4h]

  m_iCompletableLevels = this->m_iCompletableLevels;
  if ( m_iCompletableLevels > 0 )
    return this->m_fCurrentCompletion / (double)m_iCompletableLevels;
  else
    return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x101FD3E0
// Name: float GetChallengeBests(class KeyValues __near *,struct BonusMapDescription_t __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl GetChallengeBests(KeyValues *pBonusFilesKey, BonusMapDescription_t *challenge)
{
  CUtlVector<ChallengeDescription_t,CUtlMemory<ChallengeDescription_t,int> > *m_pChallenges; // eax
  KeyValues *i; // edi
  KeyValues *FirstSubKey; // esi
  const char *Name; // eax
  const char *v6; // eax
  CUtlVector<ChallengeDescription_t,CUtlMemory<ChallengeDescription_t,int> > *v7; // eax
  float v8; // xmm0_4
  int v9; // ebx
  ChallengeDescription_t *v10; // esi
  int Int; // eax
  int iChallenge; // [esp+4h] [ebp-8h]
  float fChallengePoints; // [esp+8h] [ebp-4h]

  m_pChallenges = challenge->m_pChallenges;
  if ( m_pChallenges == nullptr || m_pChallenges->m_Size == 0 )
    return 0.0;
  i = nullptr;
  FirstSubKey = KeyValues::GetFirstSubKey(this: pBonusFilesKey);
  if ( FirstSubKey != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstSubKey);
      if ( _V_strcmp(s1: Name, s2: challenge->szFileName) == 0 )
        break;
      FirstSubKey = KeyValues::GetNextTrueSubKey(this: FirstSubKey);
      if ( FirstSubKey == nullptr )
        goto LABEL_10;
    }
    for ( i = KeyValues::GetFirstSubKey(this: FirstSubKey); i != nullptr; i = KeyValues::GetNextKey(this: i) )
    {
      v6 = KeyValues::GetName(this: i);
      if ( _V_strcmp(s1: v6, s2: challenge->szMapName) == 0 )
        break;
    }
  }
LABEL_10:
  v7 = challenge->m_pChallenges;
  v8 = 0.0;
  v9 = 0;
  fChallengePoints = 0.0;
  iChallenge = 0;
  if ( v7->m_Size > 0 )
  {
    while ( 1 )
    {
      v10 = &v7->m_Memory.m_pMemory[v9];
      if ( i != nullptr )
      {
        Int = KeyValues::GetInt(this: i, keyName: v10->szName, defaultValue: -1);
        v8 = fChallengePoints;
      }
      else
      {
        Int = -1;
      }
      v10->iBest = Int;
      if ( Int >= 0 )
      {
        if ( Int <= v10->iGold )
          break;
        if ( Int <= v10->iSilver )
        {
          v8 = v8 + 2.0;
          goto LABEL_21;
        }
        if ( Int <= v10->iBronze )
        {
          v8 = v8 + 1.0;
          goto LABEL_21;
        }
      }
LABEL_22:
      v7 = challenge->m_pChallenges;
      ++v9;
      if ( ++iChallenge >= v7->m_Size )
        return fChallengePoints / ((double)challenge->m_pChallenges->m_Size * 3.0);
    }
    v8 = v8 + 3.0;
LABEL_21:
    fChallengePoints = v8;
    goto LABEL_22;
  }
  return fChallengePoints / ((double)challenge->m_pChallenges->m_Size * 3.0);
}

//------------------------------------------------------------------------------
// Address: 0x101FD5D0
// Name: bool WriteBonusMapSavedData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl WriteBonusMapSavedData(KeyValues *data)
{
  bool v1; // bl
  char szFilename[260]; // [esp+4h] [ebp-134h] BYREF
  CUtlBuffer buf; // [esp+108h] [ebp-30h] BYREF

  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1u);
  KeyValues::RecursiveSaveToFile(this: data, &buf, indentLevel: 0);
  V_snprintf(pDest: szFilename, maxLen: 0x104u, pFormat: "save/bonus_maps_data.bmd");
  v1 = g_pFullFileSystem->WriteFile(this: &g_pFullFileSystem->IBaseFileSystem, a2: szFilename, a3: "MOD", a4: &buf);
  xboxsystem->FinishContainerWrites(this: xboxsystem, a2: 0);
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x101FD670
// Name: public: CBonusMapsDatabase::CBonusMapsDatabase(void)
// Source: json
//------------------------------------------------------------------------------
CBonusMapsDatabase *__thiscall CBonusMapsDatabase::CBonusMapsDatabase(CBonusMapsDatabase *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  IBaseFileSystem *v4; // ecx

  this->m_BonusMaps.m_Memory.m_pMemory = nullptr;
  this->m_BonusMaps.m_Memory.m_nAllocationCount = 0;
  this->m_BonusMaps.m_Memory.m_nGrowSize = 0;
  this->m_BonusMaps.m_Size = 0;
  this->m_BonusMaps.m_pElements = nullptr;
  g_pBonusMapsDatabase = this;
  this->m_iDirDepth = 0;
  _V_strcpy(dest: this->m_szCurrentPath, src: ".");
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "bonus_maps_manifest");
  else
    v3 = nullptr;
  this->m_pBonusMapsManifest = v3;
  if ( g_pFullFileSystem != nullptr )
    v4 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v4 = nullptr;
  KeyValues::LoadFromFile(
    this: v3,
    filesystem: v4,
    resourceName: "scripts/bonus_maps_manifest.txt",
    pathID: nullptr,
    pfnEvaluateSymbolProc: nullptr);
  this->m_iX360BonusesUnlocked = -1;
  this->m_bHasLoadedSaveData = false;
  CBonusMapsDatabase::ReadBonusMapSaveData(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101FD700
// Name: public: bool CBonusMapsDatabase::WriteSaveData(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBonusMapsDatabase::WriteSaveData(CBonusMapsDatabase *this)
{
  bool result; // al

  result = false;
  if ( this->m_bSavedDataChanged )
  {
    result = WriteBonusMapSavedData(data: this->m_pBonusMapSavedData);
    if ( result )
      this->m_bSavedDataChanged = false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FD720
// Name: private: void CBonusMapsDatabase::ParseBonusMapData(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBonusMapsDatabase::ParseBonusMapData(
        CBonusMapsDatabase *this,
        char *pszFileName,
        char *pszShortName,
        bool bIsFolder)
{
  CBonusMapsDatabase *v4; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // ebx
  IBaseFileSystem *v7; // eax
  BonusMapDescription_t *v8; // esi
  const char *Name; // eax
  const char *String; // eax
  const char *v11; // eax
  const char *v12; // eax
  const char *v13; // eax
  KeyValues *Key; // eax
  KeyValues *FirstSubKey; // edi
  CUtlVector<ChallengeDescription_t,CUtlMemory<ChallengeDescription_t,int> > *v16; // eax
  float v17; // ecx
  int v18; // ebx
  int v19; // eax
  ChallengeDescription_t *v20; // edx
  int v21; // eax
  int szName; // ebx
  const char *v23; // eax
  const char *v24; // eax
  KeyValues *v25; // eax
  double ChallengeBests; // st7
  KeyValues *v27; // eax
  KeyValues *v28; // eax
  float v29; // xmm0_4
  float m_fCurrentCompletion; // xmm1_4
  char szMapInfo[260]; // [esp+4h] [ebp-110h] BYREF
  CBonusMapsDatabase *v32; // [esp+108h] [ebp-Ch]
  float fCompletion; // [esp+10Ch] [ebp-8h]
  KeyValues *kv; // [esp+110h] [ebp-4h]

  v4 = this;
  v32 = this;
  if ( pszFileName != nullptr && pszShortName != nullptr )
  {
    if ( bIsFolder )
      V_snprintf(pDest: szMapInfo, maxLen: 0x104u, pFormat: "%s/folderinfo.bns", pszFileName);
    else
      V_strncpy(pDest: szMapInfo, pSrc: pszFileName, maxLen: 260);
    v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v5 != nullptr )
    {
      v6 = KeyValues::KeyValues(this: v5, setName: pszShortName);
      kv = v6;
    }
    else
    {
      kv = nullptr;
      v6 = nullptr;
    }
    if ( g_pFullFileSystem != nullptr )
      v7 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v7 = nullptr;
    if ( !KeyValues::LoadFromFile(
            this: v6,
            filesystem: v7,
            resourceName: szMapInfo,
            pathID: nullptr,
            pfnEvaluateSymbolProc: nullptr) )
      DevMsg(a1: "Unable to load bonus map info file\n", szMapInfo);
    if ( v6 != nullptr )
    {
      while ( 1 )
      {
        v8 = &v4->m_BonusMaps.m_Memory.m_pMemory[CUtlVector<BonusMapDescription_t,CUtlMemory<BonusMapDescription_t,int>>::InsertBefore(
                                                   this: &v4->m_BonusMaps,
                                                   elem: v4->m_BonusMaps.m_Size)];
        V_strncpy(pDest: v8->szFileName, pSrc: pszFileName, maxLen: 128);
        V_strncpy(pDest: v8->szShortName, pSrc: pszShortName, maxLen: 64);
        v8->bIsFolder = bIsFolder;
        Name = KeyValues::GetName(this: v6);
        _V_strcpy(dest: v8->szMapName, src: Name);
        String = KeyValues::GetString(this: v6, keyName: "map", defaultValue: prType);
        _V_strcpy(dest: v8->szMapFileName, src: String);
        v11 = KeyValues::GetString(this: v6, keyName: "chapter", defaultValue: prType);
        _V_strcpy(dest: v8->szChapterName, src: v11);
        v12 = KeyValues::GetString(this: v6, keyName: "image", defaultValue: prType);
        _V_strcpy(dest: v8->szImageName, src: v12);
        v13 = KeyValues::GetString(this: v6, keyName: "comment", defaultValue: prType);
        _V_strcpy(dest: v8->szComment, src: v13);
        v8->bLocked = KeyValues::GetInt(this: v6, keyName: "lock", defaultValue: 0) != 0;
        v8->bComplete = KeyValues::GetInt(this: v6, keyName: "complete", defaultValue: 0) != 0;
        fCompletion = 0.0;
        Key = KeyValues::FindKey(this: v6, keyName: "challenges", bCreate: false);
        if ( Key != nullptr )
        {
          FirstSubKey = KeyValues::GetFirstSubKey(this: Key);
          if ( FirstSubKey != nullptr )
          {
            do
            {
              if ( v8->m_pChallenges == nullptr )
              {
                v16 = (CUtlVector<ChallengeDescription_t,CUtlMemory<ChallengeDescription_t,int> > *)MemAlloc_Alloc(nSize: 0x14u);
                if ( v16 != nullptr )
                {
                  v16->m_Memory.m_pMemory = nullptr;
                  v16->m_Memory.m_nAllocationCount = 0;
                  v16->m_Memory.m_nGrowSize = 0;
                  v16->m_Size = 0;
                  v16->m_pElements = nullptr;
                }
                else
                {
                  v16 = nullptr;
                }
                v8->m_pChallenges = v16;
              }
              v17 = *(float *)&v8->m_pChallenges;
              v18 = *(_DWORD *)(LODWORD(v17) + 12);
              v19 = *(_DWORD *)(LODWORD(v17) + 4);
              fCompletion = v17;
              if ( v18 + 1 > v19 )
              {
                CUtlMemory<ChallengeDescription_t,int>::Grow(
                  this: (CUtlMemory<ChallengeDescription_t,int> *)LODWORD(v17),
                  num: v18 - v19 + 1);
                v17 = fCompletion;
              }
              ++*(_DWORD *)(LODWORD(v17) + 12);
              v20 = *(ChallengeDescription_t **)LODWORD(v17);
              v21 = *(_DWORD *)(LODWORD(v17) + 12) - v18 - 1;
              *(_DWORD *)(LODWORD(v17) + 16) = *(_DWORD *)LODWORD(v17);
              if ( v21 > 0 )
                _V_memmove(dest: (unsigned __int8 *)&v20[v18 + 1], src: (unsigned __int8 *)&v20[v18], count: 308 * v21);
              szName = (int)v8->m_pChallenges->m_Memory.m_pMemory[v18].szName;
              v23 = KeyValues::GetName(this: FirstSubKey);
              _V_strcpy(dest: (char *)szName, src: v23);
              v24 = KeyValues::GetString(this: FirstSubKey, keyName: "comment", defaultValue: prType);
              _V_strcpy(dest: (char *)(szName + 32), src: v24);
              *(_DWORD *)(szName + 288) = KeyValues::GetInt(this: FirstSubKey, keyName: "type", defaultValue: -1);
              *(_DWORD *)(szName + 292) = KeyValues::GetInt(this: FirstSubKey, keyName: "bronze", defaultValue: 0);
              *(_DWORD *)(szName + 296) = KeyValues::GetInt(this: FirstSubKey, keyName: "silver", defaultValue: 0);
              *(_DWORD *)(szName + 300) = KeyValues::GetInt(this: FirstSubKey, keyName: "gold", defaultValue: 0);
              FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
            }
            while ( FirstSubKey != nullptr );
            v6 = kv;
          }
          v4 = v32;
          v25 = KeyValues::FindKey(this: v32->m_pBonusMapSavedData, keyName: "bonusfiles", bCreate: true);
          ChallengeBests = GetChallengeBests(pBonusFilesKey: v25, challenge: v8);
          fCompletion = ChallengeBests;
          if ( ChallengeBests == 1.0 )
          {
            v27 = KeyValues::FindKey(this: v4->m_pBonusMapSavedData, keyName: "bonusfiles", bCreate: true);
            if ( SetBooleanStatus(
                   pBonusFilesKey: v27,
                   pchName: "complete",
                   pchFileName: v8->szFileName,
                   pchMapName: v8->szMapName,
                   bValue: true) )
            {
              v4->m_bSavedDataChanged = true;
            }
          }
        }
        v28 = KeyValues::FindKey(this: v4->m_pBonusMapSavedData, keyName: "bonusfiles", bCreate: true);
        GetBooleanStatus(pBonusFilesKey: v28, map: v8);
        v29 = v8->bComplete ? 1.0 : fCompletion;
        if ( v8->bIsFolder )
          break;
        m_fCurrentCompletion = v4->m_fCurrentCompletion;
        ++v4->m_iCompletableLevels;
        v4->m_fCurrentCompletion = m_fCurrentCompletion + v29;
        kv = KeyValues::GetNextTrueSubKey(this: v6);
        if ( kv == nullptr )
          break;
        v6 = kv;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FDB30
// Name: private: void CBonusMapsDatabase::AddBonus(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBonusMapsDatabase::AddBonus(
        CBonusMapsDatabase *this,
        const char *pCurrentPath,
        char *pDirFileName,
        bool bIsFolder)
{
  char szFileName[260]; // [esp+8h] [ebp-104h] BYREF

  V_snprintf(pDest: szFileName, maxLen: 0x104u, pFormat: "%s%s", pCurrentPath, pDirFileName);
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: szFileName, a3: "MOD") )
    CBonusMapsDatabase::ParseBonusMapData(this, pszFileName: szFileName, pszShortName: pDirFileName, bIsFolder);
}

//------------------------------------------------------------------------------
// Address: 0x101FDBA0
// Name: private: void CBonusMapsDatabase::BuildSubdirectoryList(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBonusMapsDatabase::BuildSubdirectoryList(
        CBonusMapsDatabase *this,
        const char *pCurrentPath,
        bool bOutOfRoot)
{
  const char *v3; // ebx
  char *i; // esi
  char szFileName[260]; // [esp+Ch] [ebp-208h] BYREF
  char szDirectory[260]; // [esp+110h] [ebp-104h] BYREF

  v3 = pCurrentPath;
  V_snprintf(pDest: szDirectory, maxLen: 0x104u, pFormat: "%s*", pCurrentPath);
  for ( i = (char *)g_pFullFileSystem->FindFirst(this: g_pFullFileSystem, a2: szDirectory, a3: &pCurrentPath);
        i != nullptr;
        i = (char *)g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: pCurrentPath) )
  {
    if ( g_pFullFileSystem->FindIsDirectory(this: g_pFullFileSystem, a2: (int)pCurrentPath)
      && _V_strcmp(s1: i, s2: ".") != 0
      && _V_strcmp(s1: i, s2: "..") != 0
      && _V_stricmp(s1: i, s2: "soundcache") != 0
      && _V_stricmp(s1: i, s2: "graphs") != 0 )
    {
      if ( bOutOfRoot )
      {
        V_snprintf(pDest: szFileName, maxLen: 0x104u, pFormat: "%s%s", v3, i);
        CBonusMapsDatabase::AddBonus(this, pCurrentPath: prType, pDirFileName: szFileName, bIsFolder: true);
      }
      else
      {
        CBonusMapsDatabase::AddBonus(this, pCurrentPath: v3, pDirFileName: i, bIsFolder: true);
      }
    }
  }
  g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: (int)pCurrentPath);
}

//------------------------------------------------------------------------------
// Address: 0x101FDCE0
// Name: private: void CBonusMapsDatabase::BuildBonusMapsList(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBonusMapsDatabase::BuildBonusMapsList(
        CBonusMapsDatabase *this,
        const char *pCurrentPath,
        bool bOutOfRoot)
{
  const char *v3; // edi
  char *i; // esi
  int v6; // eax
  char szDirectory[260]; // [esp+Ch] [ebp-30Ch] BYREF
  char pDest[260]; // [esp+110h] [ebp-208h] BYREF
  char szFileName[260]; // [esp+214h] [ebp-104h] BYREF

  v3 = pCurrentPath;
  V_snprintf(pDest: szDirectory, maxLen: 0x104u, pFormat: "%s*.bns", pCurrentPath);
  for ( i = (char *)g_pFullFileSystem->FindFirst(this: g_pFullFileSystem, a2: szDirectory, a3: &pCurrentPath);
        i != nullptr;
        i = (char *)g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: pCurrentPath) )
  {
    if ( !g_pFullFileSystem->FindIsDirectory(this: g_pFullFileSystem, a2: (int)pCurrentPath) )
    {
      _V_strstr(s1: i, search: "folderinfo.bns");
      if ( v6 == 0 )
      {
        V_snprintf(pDest: szFileName, maxLen: 0x104u, pFormat: "%s%s", v3, i);
        if ( bOutOfRoot )
        {
          V_snprintf(pDest, maxLen: 0x104u, pFormat: "%s%s", prType, szFileName);
          if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pDest, a3: "MOD") )
            CBonusMapsDatabase::ParseBonusMapData(this, pszFileName: pDest, pszShortName: szFileName, bIsFolder: false);
        }
        else if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: szFileName, a3: "MOD") )
        {
          CBonusMapsDatabase::ParseBonusMapData(this, pszFileName: szFileName, pszShortName: i, bIsFolder: false);
        }
      }
    }
  }
  g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: (int)pCurrentPath);
}

//------------------------------------------------------------------------------
// Address: 0x101FDE60
// Name: class CBonusMapsDatabase __near * BonusMapsDatabase(void)
// Source: json
//------------------------------------------------------------------------------
CBonusMapsDatabase *__cdecl BonusMapsDatabase()
{
  CBonusMapsDatabase *result; // eax

  result = g_pBonusMapsDatabase;
  if ( g_pBonusMapsDatabase == nullptr && (_S1_6 & 1) == 0 )
  {
    _S1_6 |= 1u;
    CBonusMapsDatabase::CBonusMapsDatabase(this: &StaticBonusMapsDatabase);
    atexit(func: BonusMapsDatabase_::_4_::_dynamic_atexit_destructor_for__StaticBonusMapsDatabase__);
    return g_pBonusMapsDatabase;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FDEA0
// Name: public: void CBonusMapsDatabase::ScanBonusMaps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBonusMapsDatabase::ScanBonusMaps(CBonusMapsDatabase *this)
{
  KeyValues *i; // esi
  const char *Name; // ebx
  const char *v4; // eax
  char *v5; // ebx
  char *String; // eax
  char pDest[260]; // [esp+4h] [ebp-208h] BYREF
  char szDirectory[260]; // [esp+108h] [ebp-104h] BYREF

  if ( this->m_bHasLoadedSaveData || CBonusMapsDatabase::ReadBonusMapSaveData(this) != 0 )
  {
    *(_QWORD *)&this->m_fCurrentCompletion = 0;
    if ( _V_strcmp(s1: this->m_szCurrentPath, s2: ".") != 0 )
    {
      V_snprintf(pDest: szDirectory, maxLen: 0x104u, pFormat: "%s/", &this->m_szCurrentPath[2]);
      CBonusMapsDatabase::BuildSubdirectoryList(this, pCurrentPath: szDirectory, bOutOfRoot: false);
      CBonusMapsDatabase::BuildBonusMapsList(this, pCurrentPath: szDirectory, bOutOfRoot: false);
    }
    else
    {
      for ( i = KeyValues::GetFirstSubKey(this: this->m_pBonusMapsManifest);
            i != nullptr;
            i = KeyValues::GetNextKey(this: i) )
      {
        Name = KeyValues::GetName(this: i);
        if ( _V_strcmp(s1: Name, s2: "search") != 0 )
        {
          if ( _V_strcmp(s1: Name, s2: "dir") != 0 )
          {
            if ( _V_strcmp(s1: Name, s2: "map") == 0 )
            {
              String = (char *)KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
              CBonusMapsDatabase::AddBonus(this, pCurrentPath: prType, pDirFileName: String, bIsFolder: false);
            }
          }
          else
          {
            v5 = (char *)KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
            V_snprintf(pDest, maxLen: 0x104u, pFormat: "%s%s", prType, v5);
            if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: pDest, a3: "MOD") )
              CBonusMapsDatabase::ParseBonusMapData(this, pszFileName: pDest, pszShortName: v5, bIsFolder: true);
          }
        }
        else
        {
          v4 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
          V_snprintf(pDest: szDirectory, maxLen: 0x104u, pFormat: "%s/", v4);
          CBonusMapsDatabase::BuildSubdirectoryList(this, pCurrentPath: szDirectory, bOutOfRoot: true);
          CBonusMapsDatabase::BuildBonusMapsList(this, pCurrentPath: szDirectory, bOutOfRoot: true);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FE070
// Name: public: int CBonusMapsDatabase::BonusCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBonusMapsDatabase::BonusCount(CBonusMapsDatabase *this)
{
  if ( this->m_BonusMaps.m_Size == 0 )
    CBonusMapsDatabase::ScanBonusMaps(this);
  return this->m_BonusMaps.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x101FE090
// Name: public: bool CBonusMapsDatabase::BonusesUnlocked(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBonusMapsDatabase::BonusesUnlocked(CBonusMapsDatabase *this)
{
  CBonusMapsDatabase *v1; // esi
  CBonusMapsDatabase *v2; // eax
  int v3; // ebx
  int i; // edi
  CBonusMapsDatabase *v5; // ecx
  int *p_m_Size; // esi
  BonusMapDescription_t *m_pMemory; // esi

  v1 = this;
  if ( this->m_iX360BonusesUnlocked == -1 )
  {
    if ( g_pBonusMapsDatabase == nullptr && (_S1_6 & 1) == 0 )
    {
      _S1_6 |= 1u;
      CBonusMapsDatabase::CBonusMapsDatabase(this: &StaticBonusMapsDatabase);
      atexit(func: BonusMapsDatabase_::_4_::_dynamic_atexit_destructor_for__StaticBonusMapsDatabase__);
    }
    g_pBonusMapsDatabase->m_BonusMaps.m_Size = 0;
    v2 = g_pBonusMapsDatabase;
    if ( g_pBonusMapsDatabase == nullptr && (_S1_6 & 1) == 0 )
    {
      _S1_6 |= 1u;
      CBonusMapsDatabase::CBonusMapsDatabase(this: &StaticBonusMapsDatabase);
      atexit(func: BonusMapsDatabase_::_4_::_dynamic_atexit_destructor_for__StaticBonusMapsDatabase__);
      v2 = g_pBonusMapsDatabase;
    }
    v2->m_iDirDepth = 0;
    _V_strcpy(dest: v2->m_szCurrentPath, src: ".");
    if ( g_pBonusMapsDatabase == nullptr && (_S1_6 & 1) == 0 )
    {
      _S1_6 |= 1u;
      CBonusMapsDatabase::CBonusMapsDatabase(this: &StaticBonusMapsDatabase);
      atexit(func: BonusMapsDatabase_::_4_::_dynamic_atexit_destructor_for__StaticBonusMapsDatabase__);
    }
    CBonusMapsDatabase::ScanBonusMaps(this: g_pBonusMapsDatabase);
    v1->m_iX360BonusesUnlocked = 0;
  }
  if ( v1->m_iX360BonusesUnlocked == 0 )
  {
    v3 = 0;
    for ( i = 0; ; ++i )
    {
      v5 = g_pBonusMapsDatabase;
      if ( g_pBonusMapsDatabase == nullptr && (_S1_6 & 1) == 0 )
      {
        _S1_6 |= 1u;
        CBonusMapsDatabase::CBonusMapsDatabase(this: &StaticBonusMapsDatabase);
        atexit(func: BonusMapsDatabase_::_4_::_dynamic_atexit_destructor_for__StaticBonusMapsDatabase__);
        v5 = g_pBonusMapsDatabase;
      }
      p_m_Size = &v5->m_BonusMaps.m_Size;
      if ( v5->m_BonusMaps.m_Size == 0 )
      {
        CBonusMapsDatabase::ScanBonusMaps(this: v5);
        v5 = g_pBonusMapsDatabase;
      }
      if ( v3 >= *p_m_Size )
        break;
      if ( v5 == nullptr && (_S1_6 & 1) == 0 )
      {
        _S1_6 |= 1u;
        CBonusMapsDatabase::CBonusMapsDatabase(this: &StaticBonusMapsDatabase);
        atexit(func: BonusMapsDatabase_::_4_::_dynamic_atexit_destructor_for__StaticBonusMapsDatabase__);
        v5 = g_pBonusMapsDatabase;
      }
      m_pMemory = v5->m_BonusMaps.m_Memory.m_pMemory;
      if ( _V_strcmp(s1: m_pMemory[i].szMapName, s2: "#Bonus_Map_AdvancedChambers") == 0 && !m_pMemory[i].bLocked )
      {
        this->m_iX360BonusesUnlocked = 1;
        return this->m_iX360BonusesUnlocked != 0;
      }
      ++v3;
    }
    v1 = this;
  }
  return v1->m_iX360BonusesUnlocked != 0;
}
