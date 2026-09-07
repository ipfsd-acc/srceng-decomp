// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/asw_spawn_selection.cpp
// Functions: 20
// ============================================================

#include "missionchooser\asw_spawn_selection.h"

//------------------------------------------------------------------------------
// Address: 0x10008800
// Name: class CASW_Spawn_Set __near * CurrentSpawnSet(void)
// Source: json
//------------------------------------------------------------------------------
CASW_Spawn_Set *__cdecl CurrentSpawnSet()
{
  return g_SpawnSelection.m_pCurrentSpawnSet;
}

//------------------------------------------------------------------------------
// Address: 0x10008810
// Name: public: virtual void CASW_Spawn_Selection::DumpCurrentSpawnSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Spawn_Selection::DumpCurrentSpawnSet(CASW_Spawn_Selection *this)
{
  if ( this->m_pCurrentSpawnSet != nullptr )
    _Msg(
      a1: "Current spawn set: %s  Feeder chance: %f\n",
      this->m_pCurrentSpawnSet->m_pszSetName,
      this->m_pCurrentSpawnSet->m_flFeederChance);
  else
    _Msg(a1: "No current spawn set!\n");
}

//------------------------------------------------------------------------------
// Address: 0x10008860
// Name: public: virtual void CASW_Entry::GetSpawnCountRange(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Entry::GetSpawnCountRange(CASW_Entry *this, int *nMin, int *nMax)
{
  *nMin = this->m_nMinPerSpawn;
  *nMax = this->m_nMaxPerSpawn;
}

//------------------------------------------------------------------------------
// Address: 0x10008880
// Name: public: virtual float CASW_Entry::GetEliteNPCChance(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CASW_Entry::GetEliteNPCChance(CASW_Entry *this)
{
  return this->m_flEliteChance;
}

//------------------------------------------------------------------------------
// Address: 0x10008890
// Name: public: virtual bool CASW_Entry::UseSpawners(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CASW_Entry::UseSpawners(CASW_Entry *this)
{
  return this->m_bUseSpawners;
}

//------------------------------------------------------------------------------
// Address: 0x100088A0
// Name: public: class CASW_Spawn_Definition __near * CASW_Spawn_Set::GetSpawnDef(int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
CASW_Spawn_Definition *__thiscall CASW_Spawn_Set::GetSpawnDef(CASW_Spawn_Set *this, int nType)
{
  int m_Size; // esi
  CUtlVector<CASW_Spawn_Definition *,CUtlMemory<CASW_Spawn_Definition *,int> > *v3; // edi
  int v4; // eax
  CASW_Spawn_Definition **m_pMemory; // edi
  float v6; // xmm0_4
  CASW_Spawn_Definition **i; // ecx
  float flChosen; // [esp+18h] [ebp+8h]

  m_Size = this->m_SpawnDefs[nType].m_Size;
  v3 = &this->m_SpawnDefs[nType];
  flChosen = _RandomFloat((IUniformRandomStream *)this, a2: 0.0, a3: this->m_flTotalWeight[nType]);
  v4 = 0;
  if ( m_Size <= 0 )
    return nullptr;
  m_pMemory = v3->m_Memory.m_pMemory;
  v6 = flChosen;
  for ( i = m_pMemory; ; ++i )
  {
    v6 = v6 - (*i)->m_flSelectionWeight;
    if ( v6 <= 0.0 )
      break;
    if ( ++v4 >= m_Size )
      return nullptr;
  }
  return m_pMemory[v4];
}

//------------------------------------------------------------------------------
// Address: 0x10008920
// Name: public: class CASW_Spawn_Definition __near * CASW_Spawn_Selection::GetSpawnDefByID(int)
// Source: json
//------------------------------------------------------------------------------
CASW_Spawn_Definition *__thiscall CASW_Spawn_Selection::GetSpawnDefByID(CASW_Spawn_Selection *this, int nID)
{
  int v2; // eax
  int v3; // ebx
  int *p_m_Size; // edi
  int v5; // esi
  int v6; // ecx
  CASW_Spawn_Definition *result; // eax
  CASW_Spawn_Selection *v8; // [esp+Ch] [ebp-Ch]
  CASW_Spawn_Set *v9; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  v2 = 0;
  v8 = this;
  i = 0;
  if ( this->m_SpawnSets.m_Size > 0 )
  {
    while ( 2 )
    {
      v9 = this->m_SpawnSets.m_Memory.m_pMemory[v2];
      v3 = 0;
      p_m_Size = &v9->m_SpawnDefs[0].m_Size;
      while ( 1 )
      {
        v5 = 0;
        if ( *p_m_Size > 0 )
          break;
LABEL_6:
        ++v3;
        p_m_Size += 5;
        if ( v3 >= 12 )
          goto LABEL_9;
      }
      while ( 1 )
      {
        v6 = *(_DWORD *)(*(p_m_Size - 3) + 4 * v5);
        if ( (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6) == nID )
          break;
        if ( ++v5 >= *p_m_Size )
          goto LABEL_6;
      }
      result = v9->m_SpawnDefs[v3].m_Memory.m_pMemory[v5];
      if ( result != nullptr )
        return result;
LABEL_9:
      this = v8;
      v2 = i + 1;
      i = v2;
      if ( v2 < v8->m_SpawnSets.m_Size )
        continue;
      break;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100089A0
// Name: public: class CASW_Spawn_Set __near * CASW_Spawn_Selection::GetSpawnSet(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CASW_Spawn_Set *__thiscall CASW_Spawn_Selection::GetSpawnSet(CASW_Spawn_Selection *this, const char *szSetName)
{
  int v3; // esi

  v3 = 0;
  if ( this->m_SpawnSets.m_Size <= 0 )
    return nullptr;
  while ( _V_stricmp(s1: this->m_SpawnSets.m_Memory.m_pMemory[v3]->m_pszSetName, s2: szSetName) != 0 )
  {
    if ( ++v3 >= this->m_SpawnSets.m_Size )
      return nullptr;
  }
  return this->m_SpawnSets.m_Memory.m_pMemory[v3];
}

//------------------------------------------------------------------------------
// Address: 0x100089F0
// Name: public: virtual bool CASW_Spawn_Selection::SetCurrentSpawnSet(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CASW_Spawn_Selection::SetCurrentSpawnSet(CASW_Spawn_Selection *this, const char *szSetName)
{
  CASW_Spawn_Set *SpawnSet; // eax

  SpawnSet = CASW_Spawn_Selection::GetSpawnSet(this, szSetName);
  this->m_pCurrentSpawnSet = SpawnSet;
  return SpawnSet != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10008A30
// Name: public: virtual class IASWSpawnDefinitionEntry __near * CASW_Spawn_Definition::GetEntry(int)
// Source: json
//------------------------------------------------------------------------------
CASW_Entry *__thiscall CASW_Spawn_Definition::GetEntry(CASW_Spawn_Definition *this, int nEntry)
{
  return this->m_Entries.m_Memory.m_pMemory[nEntry];
}

//------------------------------------------------------------------------------
// Address: 0x10008A40
// Name: public: CASW_Spawn_Selection::CASW_Spawn_Selection(void)
// Source: json
//------------------------------------------------------------------------------
CASW_Spawn_Selection *__thiscall CASW_Spawn_Selection::CASW_Spawn_Selection(CASW_Spawn_Selection *this)
{
  this->__vftable = (CASW_Spawn_Selection_vtbl *)&CASW_Spawn_Selection::`vftable';
  this->m_SpawnSets.m_Memory.m_pMemory = nullptr;
  this->m_SpawnSets.m_Memory.m_nAllocationCount = 0;
  this->m_SpawnSets.m_Memory.m_nGrowSize = 0;
  this->m_SpawnSets.m_Size = 0;
  this->m_SpawnSets.m_pElements = nullptr;
  this->m_pSpawnSetKeys = nullptr;
  this->m_pCurrentSpawnSet = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10008A60
// Name: public: virtual class IASWSpawnDefinition __near * CASW_Spawn_Selection::GetSpawnDefinition(int)
// Source: json
//------------------------------------------------------------------------------
CASW_Spawn_Definition *__thiscall CASW_Spawn_Selection::GetSpawnDefinition(CASW_Spawn_Selection *this, int nSpawnType)
{
  return CASW_Spawn_Set::GetSpawnDef(this: this->m_pCurrentSpawnSet, nType: nSpawnType);
}

//------------------------------------------------------------------------------
// Address: 0x10008A70
// Name: public: void CASW_Spawn_Definition::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Spawn_Definition::LoadFromKeyValues(CASW_Spawn_Definition *this, KeyValues *pKeys)
{
  KeyValues *FirstSubKey; // edi
  const char *Name; // eax
  _DWORD *v4; // eax
  CASW_Entry *v5; // ebx
  const char *String; // eax
  const char *v7; // esi
  signed int v8; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CASW_Entry **m_pMemory; // ecx
  int v12; // eax
  CASW_Entry **v13; // edi
  char *v15; // [esp+10h] [ebp-8h]
  int maxLen; // [esp+14h] [ebp-4h]
  KeyValues *pKey; // [esp+20h] [ebp+8h]

  this->m_flSelectionWeight = KeyValues::GetFloat(this: pKeys, keyName: "SelectionWeight", defaultValue: 0.0);
  FirstSubKey = KeyValues::GetFirstSubKey(this: pKeys);
  pKey = FirstSubKey;
  if ( FirstSubKey != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstSubKey);
      if ( _V_stricmp(s1: Name, s2: "NPC") == 0 )
      {
        v4 = operator new(nSize: 0x18u);
        if ( v4 != nullptr )
        {
          *v4 = &CASW_Entry::`vftable';
          v4[1] = 0;
          v4[2] = 1;
          v4[3] = 1;
          v4[4] = 0;
          *((_BYTE *)v4 + 20) = 0;
          v5 = (CASW_Entry *)v4;
        }
        else
        {
          v5 = nullptr;
        }
        v5->m_nMinPerSpawn = KeyValues::GetInt(this: FirstSubKey, keyName: "MinPerSpawn", defaultValue: 1);
        v5->m_nMaxPerSpawn = KeyValues::GetInt(this: FirstSubKey, keyName: "MaxPerSpawn", defaultValue: 1);
        String = KeyValues::GetString(this: FirstSubKey, keyName: "AlienClass", defaultValue: szDescription);
        v7 = String;
        if ( String != nullptr )
        {
          v8 = _V_strlen(str: String) + 1;
          maxLen = v8;
          if ( v8 > 1 )
          {
            v15 = (char *)operator new(nSize: v8);
            V_strncpy(pDest: v15, pSrc: v7, maxLen);
            String = v15;
          }
          else
          {
            String = nullptr;
          }
        }
        v5->m_pszAlienClass = (char *)String;
        v5->m_bUseSpawners = KeyValues::GetInt(this: FirstSubKey, keyName: "UseSpawners", defaultValue: 0) != 0;
        m_Size = this->m_Entries.m_Size;
        m_nAllocationCount = this->m_Entries.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Entries,
            num: m_Size - m_nAllocationCount + 1);
        ++this->m_Entries.m_Size;
        m_pMemory = this->m_Entries.m_Memory.m_pMemory;
        v12 = this->m_Entries.m_Size - m_Size - 1;
        this->m_Entries.m_pElements = m_pMemory;
        if ( v12 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
        v13 = &this->m_Entries.m_Memory.m_pMemory[m_Size];
        if ( v13 != nullptr )
          *v13 = v5;
        FirstSubKey = pKey;
      }
      pKey = KeyValues::GetNextKey(this: FirstSubKey);
      if ( pKey == nullptr )
        break;
      FirstSubKey = pKey;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008C00
// Name: public: CASW_Spawn_Set::CASW_Spawn_Set(void)
// Source: json
//------------------------------------------------------------------------------
CASW_Spawn_Set *__thiscall CASW_Spawn_Set::CASW_Spawn_Set(CASW_Spawn_Set *this)
{
  CASW_Spawn_Set *result; // eax
  int v2; // edi
  int *p_m_nGrowSize; // edx

  result = this;
  v2 = 11;
  p_m_nGrowSize = &this->m_SpawnDefs[0].m_Memory.m_nGrowSize;
  do
  {
    *(p_m_nGrowSize - 2) = 0;
    *(p_m_nGrowSize - 1) = 0;
    *p_m_nGrowSize = 0;
    p_m_nGrowSize[1] = 0;
    p_m_nGrowSize[2] = 0;
    p_m_nGrowSize += 5;
    --v2;
  }
  while ( v2 >= 0 );
  *(_QWORD *)this->m_flTotalWeight = 0;
  *(_QWORD *)&this->m_flTotalWeight[2] = 0;
  *(_QWORD *)&this->m_flTotalWeight[4] = 0;
  *(_QWORD *)&this->m_flTotalWeight[6] = 0;
  *(_QWORD *)&this->m_flTotalWeight[8] = 0;
  *(_QWORD *)&this->m_flTotalWeight[10] = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10008C60
// Name: public: void CASW_Spawn_Set::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Spawn_Set::LoadFromKeyValues(CASW_Spawn_Set *this, KeyValues *pKeys)
{
  CASW_Spawn_Set *v3; // esi
  const char *String; // eax
  int v5; // eax
  int v6; // ebx
  KeyValues *FirstSubKey; // edi
  int v8; // ebx
  CASW_Spawn_Definition *v9; // eax
  int v10; // edx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *v13; // esi
  vgui::TreeNode **m_pMemory; // ecx
  int v15; // eax
  CASW_Spawn_Definition **v16; // edi
  int m_iMinDifficulty; // [esp-4h] [ebp-1Ch]
  int defaultValue; // [esp+0h] [ebp-18h]
  char *pKeya; // [esp+14h] [ebp-4h]
  KeyValues *pKey; // [esp+14h] [ebp-4h]
  CASW_Spawn_Definition *pSpawnDef; // [esp+20h] [ebp+8h]
  const char *pSpawnDefa; // [esp+20h] [ebp+8h]
  CASW_Spawn_Definition *pSpawnDefb; // [esp+20h] [ebp+8h]

  v3 = this;
  this->m_iMinDifficulty = KeyValues::GetInt(this: pKeys, keyName: "MinDifficulty", defaultValue: 0);
  v3->m_iMaxDifficulty = KeyValues::GetInt(this: pKeys, keyName: "MaxDifficulty", defaultValue: 0);
  v3->m_flFeederChance = KeyValues::GetFloat(this: pKeys, keyName: "FeederChance", defaultValue: 0.0);
  v3->m_iMinEncounters = KeyValues::GetInt(this: pKeys, keyName: "MinEncounters", defaultValue: 0);
  v3->m_iMaxEncounters = KeyValues::GetInt(this: pKeys, keyName: "MaxEncounters", defaultValue: 0);
  v3->m_iMinSpawnsPerEncounter = KeyValues::GetInt(this: pKeys, keyName: "MinSpawnsPerEncounter", defaultValue: 0);
  v3->m_iMaxSpawnsPerEncounter = KeyValues::GetInt(this: pKeys, keyName: "MaxSpawnsPerEncounter", defaultValue: 0);
  String = KeyValues::GetString(this: pKeys, keyName: "Name", defaultValue: "Unnamed");
  pSpawnDef = (CASW_Spawn_Definition *)String;
  if ( String != nullptr )
  {
    v5 = _V_strlen(str: String);
    v6 = v5 + 1;
    if ( v5 + 1 > 1 )
    {
      pKeya = (char *)operator new(nSize: v5 + 1);
      V_strncpy(pDest: pKeya, pSrc: (const char *)pSpawnDef, maxLen: v6);
      String = pKeya;
    }
    else
    {
      String = nullptr;
    }
  }
  defaultValue = v3->m_iMaxDifficulty;
  m_iMinDifficulty = v3->m_iMinDifficulty;
  v3->m_pszSetName = String;
  _Msg(a1: "Loaded spawn set %s mindiff=%d maxdiff=%d\n", String, m_iMinDifficulty, defaultValue);
  FirstSubKey = KeyValues::GetFirstSubKey(this: pKeys);
  pKey = FirstSubKey;
  if ( FirstSubKey != nullptr )
  {
    while ( 1 )
    {
      pSpawnDefa = KeyValues::GetName(this: FirstSubKey);
      v8 = 0;
      while ( _V_stricmp(s1: pSpawnDefa, s2: g_SpawnTypes[v8]) != 0 )
      {
        if ( ++v8 >= 8 )
          goto LABEL_23;
      }
      if ( v8 != -1 )
      {
        v9 = (CASW_Spawn_Definition *)operator new(nSize: 0x20u);
        if ( v9 != nullptr )
        {
          v10 = g_nSpawnDefIDs++;
          v9->__vftable = (CASW_Spawn_Definition_vtbl *)&CASW_Spawn_Definition::`vftable';
          v9->m_Entries.m_Memory.m_pMemory = nullptr;
          v9->m_Entries.m_Memory.m_nAllocationCount = 0;
          v9->m_Entries.m_Memory.m_nGrowSize = 0;
          v9->m_Entries.m_Size = 0;
          v9->m_Entries.m_pElements = nullptr;
          v9->m_flSelectionWeight = 1.0;
          v9->m_nID = v10;
          pSpawnDefb = v9;
        }
        else
        {
          pSpawnDefb = nullptr;
        }
        CASW_Spawn_Definition::LoadFromKeyValues(this: pSpawnDefb, pKeys: pKey);
        m_Size = v3->m_SpawnDefs[v8].m_Size;
        m_nAllocationCount = v3->m_SpawnDefs[v8].m_Memory.m_nAllocationCount;
        v13 = (CUtlMemory<vgui::TreeNode *,int> *)&v3->m_SpawnDefs[v8];
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
            this: v13,
            num: m_Size - m_nAllocationCount + 1);
        ++v13[1].m_pMemory;
        m_pMemory = v13->m_pMemory;
        v15 = (int)v13[1].m_pMemory - m_Size - 1;
        v13[1].m_nAllocationCount = (int)v13->m_pMemory;
        if ( v15 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v15);
        v16 = (CASW_Spawn_Definition **)&v13->m_pMemory[m_Size];
        if ( v16 != nullptr )
          *v16 = pSpawnDefb;
        FirstSubKey = pKey;
        this->m_flTotalWeight[v8] = pSpawnDefb->m_flSelectionWeight + this->m_flTotalWeight[v8];
        v3 = this;
      }
LABEL_23:
      pKey = KeyValues::GetNextKey(this: FirstSubKey);
      if ( pKey == nullptr )
        break;
      FirstSubKey = pKey;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008EB0
// Name: public: virtual void CASW_Spawn_Selection::SetCurrentSpawnSet(int)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall CASW_Spawn_Selection::SetCurrentSpawnSet(CASW_Spawn_Selection *this, int iMissionDifficulty)
{
  int v2; // ebx
  int v4; // eax
  CASW_Spawn_Set **m_pMemory; // ecx
  int m_Size; // esi
  int v7; // ebx
  CASW_Spawn_Set **v8; // ebx
  int j; // esi
  CASW_Spawn_Set *v10; // eax
  int v11; // eax
  CASW_Spawn_Set **v12; // edx
  bool v13; // sf
  CUtlVector<CASW_Spawn_Set *,CUtlMemory<CASW_Spawn_Set *,int> > candidates; // [esp+Ch] [ebp-1Ch] BYREF
  CASW_Spawn_Set **v15; // [esp+20h] [ebp-8h]
  int i; // [esp+24h] [ebp-4h]

  v2 = iMissionDifficulty;
  DevMsg(a1: "[AS] Setting spawn set from mission difficulty %d\n", iMissionDifficulty);
  v4 = 0;
  m_pMemory = nullptr;
  m_Size = 0;
  memset(&candidates, 0, sizeof(candidates));
  i = 0;
  if ( this->m_SpawnSets.m_Size <= 0 )
    goto LABEL_15;
  while ( 1 )
  {
    v15 = &this->m_SpawnSets.m_Memory.m_pMemory[v4];
    if ( v2 >= (*v15)->m_iMinDifficulty && v2 <= (*v15)->m_iMaxDifficulty )
    {
      v7 = m_Size;
      if ( m_Size + 1 > (int)m_pMemory )
      {
        CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&candidates,
          num: m_Size - (_DWORD)m_pMemory + 1);
        m_Size = candidates.m_Size;
      }
      m_pMemory = candidates.m_Memory.m_pMemory;
      candidates.m_Size = ++m_Size;
      candidates.m_pElements = candidates.m_Memory.m_pMemory;
      if ( m_Size - v7 - 1 > 0 )
      {
        _V_memmove(
          dest: &candidates.m_Memory.m_pMemory[v7 + 1],
          src: &candidates.m_Memory.m_pMemory[v7],
          count: 4 * (m_Size - v7 - 1));
        m_pMemory = candidates.m_Memory.m_pMemory;
      }
      v8 = &m_pMemory[v7];
      if ( v8 != nullptr )
      {
        m_pMemory = (CASW_Spawn_Set **)*v15;
        *v8 = *v15;
      }
      v2 = iMissionDifficulty;
    }
    v4 = i + 1;
    i = v4;
    if ( v4 >= this->m_SpawnSets.m_Size )
      break;
    m_pMemory = (CASW_Spawn_Set **)candidates.m_Memory.m_nAllocationCount;
  }
  if ( m_Size > 0 )
  {
    v11 = _RandomInt(this: (IUniformRandomStream *)m_pMemory, a2: 0, a3: m_Size - 1);
    v12 = candidates.m_Memory.m_pMemory;
    v13 = candidates.m_Memory.m_nGrowSize < 0;
    this->m_pCurrentSpawnSet = candidates.m_Memory.m_pMemory[v11];
    if ( !v13 && v12 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12);
  }
  else
  {
LABEL_15:
    _Warning(
      a1: "Failed to SetCurrentSpawnSet by difficulty as couldn't find a default SpawnSelection block which covers this diffi"
      "culty range.  Requested difficulty=%d.  Supported difficulties:\n",
      v2);
    for ( j = 0; j < this->m_SpawnSets.m_Size; ++j )
    {
      v10 = this->m_SpawnSets.m_Memory.m_pMemory[j];
      _Msg(a1: "%s Min=%d Max=%d\n", v10->m_pszSetName, v10->m_iMinDifficulty, v10->m_iMaxDifficulty);
    }
    if ( candidates.m_Memory.m_nGrowSize >= 0 && candidates.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: candidates.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009030
// Name: private: void CASW_Spawn_Selection::LoadSpawnSets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Spawn_Selection::LoadSpawnSets(CASW_Spawn_Selection *this)
{
  CASW_Spawn_Selection *v1; // esi
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  IBaseFileSystem *v4; // eax
  KeyValues *m_pSpawnSetKeys; // edi
  const char *Name; // eax
  CASW_Spawn_Set *v7; // eax
  CASW_Spawn_Set *v8; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CASW_Spawn_Set **m_pMemory; // ecx
  int v12; // eax
  CASW_Spawn_Set **v13; // ecx
  CASW_Spawn_Set **v14; // eax
  KeyValues *pKey; // [esp+Ch] [ebp-4h]

  v1 = this;
  g_nSpawnDefIDs = 0;
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "DefaultSpawnSets");
  else
    v3 = nullptr;
  v1->m_pSpawnSetKeys = v3;
  _Msg(a1: "LoadSpawnSets\n");
  if ( g_pFullFileSystem != nullptr )
    v4 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v4 = nullptr;
  if ( !KeyValues::LoadFromFile(
          this: v1->m_pSpawnSetKeys,
          filesystem: v4,
          resourceName: "resource/alien_selection.txt",
          pathID: "GAME",
          pfnEvaluateSymbolProc: nullptr) )
    _Warning(a1: "Error loading resource/alien_selections.txt\n");
  m_pSpawnSetKeys = v1->m_pSpawnSetKeys;
  pKey = m_pSpawnSetKeys;
  if ( m_pSpawnSetKeys != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: m_pSpawnSetKeys);
      if ( _V_stricmp(s1: Name, s2: "SpawnSet") == 0 )
      {
        v7 = (CASW_Spawn_Set *)operator new(nSize: 0x140u);
        if ( v7 != nullptr )
          v8 = CASW_Spawn_Set::CASW_Spawn_Set(this: v7);
        else
          v8 = nullptr;
        CASW_Spawn_Set::LoadFromKeyValues(this: v8, pKeys: m_pSpawnSetKeys);
        if ( v1->m_pCurrentSpawnSet == nullptr )
          v1->m_pCurrentSpawnSet = v8;
        m_Size = v1->m_SpawnSets.m_Size;
        m_nAllocationCount = v1->m_SpawnSets.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&v1->m_SpawnSets,
            num: m_Size - m_nAllocationCount + 1);
        ++v1->m_SpawnSets.m_Size;
        m_pMemory = v1->m_SpawnSets.m_Memory.m_pMemory;
        v12 = v1->m_SpawnSets.m_Size - m_Size - 1;
        v1->m_SpawnSets.m_pElements = m_pMemory;
        if ( v12 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
        v13 = v1->m_SpawnSets.m_Memory.m_pMemory;
        v1 = this;
        v14 = &v13[m_Size];
        m_pSpawnSetKeys = pKey;
        if ( v14 != nullptr )
          *v14 = v8;
      }
      pKey = KeyValues::GetNextKey(this: m_pSpawnSetKeys);
      if ( pKey == nullptr )
        break;
      m_pSpawnSetKeys = pKey;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009270
// Name: public: CASW_Spawn_Set::~CASW_Spawn_Set(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Spawn_Set::~CASW_Spawn_Set(CASW_Spawn_Set *this)
{
  CASW_Spawn_Set *v2; // esi
  int i; // edi
  float *m_flTotalWeight; // esi
  int j; // ebx
  void *v6; // eax

  v2 = this;
  for ( i = 12; i != 0; --i )
  {
    CUtlVector<CASW_Spawn_Definition *,CUtlMemory<CASW_Spawn_Definition *,int>>::PurgeAndDeleteElements(this: v2->m_SpawnDefs);
    v2 = (CASW_Spawn_Set *)((char *)v2 + 20);
  }
  m_flTotalWeight = this->m_flTotalWeight;
  for ( j = 11; j >= 0; --j )
  {
    m_flTotalWeight -= 5;
    m_flTotalWeight[3] = 0.0;
    if ( *((int *)m_flTotalWeight + 2) >= 0 )
    {
      if ( *(_DWORD *)m_flTotalWeight != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)m_flTotalWeight);
        *m_flTotalWeight = 0.0;
      }
      m_flTotalWeight[1] = 0.0;
    }
    v6 = *(void **)m_flTotalWeight;
    m_flTotalWeight[4] = *m_flTotalWeight;
    if ( *((int *)m_flTotalWeight + 2) >= 0 )
    {
      if ( v6 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
        *m_flTotalWeight = 0.0;
      }
      m_flTotalWeight[1] = 0.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009360
// Name: public: CASW_Spawn_Selection::~CASW_Spawn_Selection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Spawn_Selection::~CASW_Spawn_Selection(CASW_Spawn_Selection *this)
{
  KeyValues *m_pSpawnSetKeys; // ecx

  this->__vftable = (CASW_Spawn_Selection_vtbl *)&CASW_Spawn_Selection::`vftable';
  CUtlVector<CASW_Spawn_Set *,CUtlMemory<CASW_Spawn_Set *,int>>::PurgeAndDeleteElements(this: &this->m_SpawnSets);
  m_pSpawnSetKeys = this->m_pSpawnSetKeys;
  if ( m_pSpawnSetKeys != nullptr )
  {
    KeyValues::deleteThis(this: m_pSpawnSetKeys);
    this->m_pSpawnSetKeys = nullptr;
  }
  this->m_pCurrentSpawnSet = nullptr;
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_SpawnSets);
}

//------------------------------------------------------------------------------
// Address: 0x100093A0
// Name: public: void CASW_Spawn_Selection::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Spawn_Selection::Init(CASW_Spawn_Selection *this)
{
  KeyValues *m_pSpawnSetKeys; // ecx

  CUtlVector<CASW_Spawn_Set *,CUtlMemory<CASW_Spawn_Set *,int>>::PurgeAndDeleteElements(this: &this->m_SpawnSets);
  m_pSpawnSetKeys = this->m_pSpawnSetKeys;
  if ( m_pSpawnSetKeys != nullptr )
  {
    KeyValues::deleteThis(this: m_pSpawnSetKeys);
    this->m_pSpawnSetKeys = nullptr;
  }
  this->m_pCurrentSpawnSet = nullptr;
  CASW_Spawn_Selection::LoadSpawnSets(this);
}
