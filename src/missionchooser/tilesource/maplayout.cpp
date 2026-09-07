// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/tilesource/maplayout.cpp
// Functions: 21
// ============================================================

#include "missionchooser\tilesource\maplayout.h"

//------------------------------------------------------------------------------
// Address: 0x10015700
// Name: public: CInstanceSpawn::CInstanceSpawn(class CInstanceSpawn const __near &)
// Source: json
//------------------------------------------------------------------------------
CInstanceSpawn *__thiscall CInstanceSpawn::CInstanceSpawn(CInstanceSpawn *this, const CInstanceSpawn *__that)
{
  CUtlVector<KeyValue_t,CUtlMemory<KeyValue_t,int> > *v2; // ebx
  int m_Size; // esi
  int v4; // eax
  int i; // edx
  KeyValue_t *v6; // esi
  KeyValue_t *v7; // edi
  KeyValue_t *m_pMemory; // [esp+10h] [ebp-4h]

  v2 = &this->m_AdditionalKeyValues.CUtlVector<KeyValue_t,CUtlMemory<KeyValue_t,int> >;
  qmemcpy(this, __that, 0x104u);
  this->m_AdditionalKeyValues.m_Memory.m_pMemory = nullptr;
  this->m_AdditionalKeyValues.m_Memory.m_nAllocationCount = 0;
  this->m_AdditionalKeyValues.m_Memory.m_nGrowSize = 0;
  this->m_AdditionalKeyValues.m_Size = 0;
  this->m_AdditionalKeyValues.m_pElements = nullptr;
  this->m_AdditionalKeyValues.__vftable = (CCopyableUtlVector<KeyValue_t>_vtbl *)&CCopyableUtlVector<KeyValue_t>::`vftable';
  m_Size = __that->m_AdditionalKeyValues.m_Size;
  m_pMemory = __that->m_AdditionalKeyValues.m_Memory.m_pMemory;
  this->m_AdditionalKeyValues.m_Size = 0;
  CUtlVector<KeyValue_t,CUtlMemory<KeyValue_t,int>>::InsertMultipleBefore(
    this: &this->m_AdditionalKeyValues.CUtlVector<KeyValue_t,CUtlMemory<KeyValue_t,int> >,
    elem: 0,
    num: m_Size);
  if ( m_Size > 0 )
  {
    v4 = 0;
    for ( i = m_Size; i != 0; --i )
    {
      v6 = &m_pMemory[v4];
      v7 = &v2->m_Memory.m_pMemory[v4++];
      qmemcpy(v7, v6, sizeof(KeyValue_t));
    }
  }
  this->m_InstanceSpawningMethod = __that->m_InstanceSpawningMethod;
  this->m_nPlacedRoomIndex = __that->m_nPlacedRoomIndex;
  this->m_nRandomSeed = __that->m_nRandomSeed;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100250A0
// Name: public: void CMapLayout::SetCurrentFilename(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLayout::SetCurrentFilename(CMapLayout *this, const char *szFilename)
{
  V_snprintf(pDest: this->m_szFilename, maxLen: 260, pFormat: "%s", szFilename);
}

//------------------------------------------------------------------------------
// Address: 0x100250D0
// Name: public: void CInstanceSpawn::FixupValues(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInstanceSpawn::FixupValues(CInstanceSpawn *this, const char *pFindValue, const char *pReplaceValue)
{
  int v3; // edi
  char outputString[64]; // [esp+8h] [ebp-44h] BYREF
  int i; // [esp+48h] [ebp-4h]

  v3 = 0;
  for ( i = 0; i < this->m_AdditionalKeyValues.m_Size; ++i )
  {
    if ( V_stristr(pStr: this->m_AdditionalKeyValues.m_Memory.m_pMemory[v3].m_Value, pSearch: pFindValue) != nullptr )
    {
      V_StrSubst(
        pIn: this->m_AdditionalKeyValues.m_Memory.m_pMemory[v3].m_Value,
        pMatch: pFindValue,
        pReplaceWith: pReplaceValue,
        pOut: outputString,
        outLen: 64,
        bCaseSensitive: false);
      V_strncpy(pDest: this->m_AdditionalKeyValues.m_Memory.m_pMemory[v3].m_Value, pSrc: outputString, maxLen: 64);
    }
    ++v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025160
// Name: public: void CInstanceSpawn::SaveToKeyValues(class KeyValues __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInstanceSpawn::SaveToKeyValues(CInstanceSpawn *this, KeyValues *pKeyValues)
{
  int v3; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  int i; // [esp+Ch] [ebp-4h]

  KeyValues::SetString(this: pKeyValues, keyName: "filename", value: this->m_InstanceFilename);
  if ( this->m_InstanceSpawningMethod == ISM_ADD_AT_RANDOM_NODE )
  {
    KeyValues::SetString(this: pKeyValues, keyName: "type", value: "add_at_random_node");
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
  {
    _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Invalid instance spawning method (%d).\n");
  }
  KeyValues::SetInt(this: pKeyValues, keyName: "room_index", value: this->m_nPlacedRoomIndex);
  KeyValues::SetInt(this: pKeyValues, keyName: "random_seed", value: this->m_nRandomSeed);
  v3 = 0;
  for ( i = 0; i < this->m_AdditionalKeyValues.m_Size; ++i )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "key_value");
    else
      v5 = nullptr;
    KeyValues::SetString(this: v5, keyName: "key", value: this->m_AdditionalKeyValues.m_Memory.m_pMemory[v3].m_Key);
    KeyValues::SetString(this: v5, keyName: "value", value: this->m_AdditionalKeyValues.m_Memory.m_pMemory[v3].m_Value);
    KeyValues::AddSubKey(this: pKeyValues, pSubkey: v5);
    ++v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025270
// Name: public: void CMapLayout::MarkEncounterRooms(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLayout::MarkEncounterRooms(CMapLayout *this)
{
  int i; // edi
  CASW_Encounter *v3; // ecx
  float *v4; // eax
  unsigned int v5; // ecx
  unsigned int v6; // eax
  CRoom *v7; // eax

  for ( i = 0; i < this->m_Encounters.m_Size; ++i )
  {
    v3 = this->m_Encounters.m_Memory.m_pMemory[i];
    v4 = (float *)v3->GetEncounterPosition(this: v3);
    v5 = (int)(float)((float)(*v4 * 0.00390625) + 60.0);
    v6 = (int)(float)((float)(v4[1] * 0.00390625) + 60.0);
    if ( v5 <= 0x77 && v6 <= 0x77 )
    {
      v7 = this->m_pRoomGrid[v5][v6];
      if ( v7 != nullptr )
        v7->m_bHasAlienEncounter = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100252F0
// Name: public: void CMapLayout::GetExtents(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLayout::GetExtents(
        CMapLayout *this,
        int *iTileX_Min,
        int *iTileX_Max,
        int *iTileY_Min,
        int *iTileY_Max)
{
  int *v5; // eax
  int *v6; // edx
  int *v7; // ebx
  int v8; // esi
  CRoom *v9; // eax
  int m_iPosX; // edx
  int m_iPosY; // edx
  int v12; // edx
  int v13; // eax

  v5 = iTileX_Max;
  v6 = iTileY_Max;
  v7 = iTileY_Min;
  *iTileX_Min = 119;
  *iTileY_Min = 119;
  *iTileX_Max = 0;
  v8 = 0;
  *iTileY_Max = 0;
  if ( this->m_PlacedRooms.m_Size > 0 )
  {
    do
    {
      v9 = this->m_PlacedRooms.m_Memory.m_pMemory[v8];
      if ( v9 != nullptr )
      {
        m_iPosX = v9->m_iPosX;
        if ( m_iPosX < *iTileX_Min )
          *iTileX_Min = m_iPosX;
        m_iPosY = v9->m_iPosY;
        if ( m_iPosY < *v7 )
          *v7 = m_iPosY;
        v12 = v9->m_iPosX + v9->m_pRoomTemplate->m_nTilesX;
        if ( v12 > *iTileX_Max )
          *iTileX_Max = v12;
        v7 = iTileY_Min;
        v13 = v9->m_pRoomTemplate->m_nTilesY + v9->m_iPosY;
        v6 = iTileY_Max;
        if ( v13 > *iTileY_Max )
          *iTileY_Max = v13;
      }
      ++v8;
    }
    while ( v8 < this->m_PlacedRooms.m_Size );
    v5 = iTileX_Max;
  }
  if ( *iTileX_Min < 0 )
    *iTileX_Min = 0;
  if ( *v7 < 0 )
    *v7 = 0;
  if ( *v5 >= 120 )
    *v5 = 119;
  if ( *v6 >= 120 )
    *v6 = 119;
}

//------------------------------------------------------------------------------
// Address: 0x100253B0
// Name: public: void CASW_Encounter::SaveToKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Encounter::SaveToKeyValues(CASW_Encounter *this, KeyValues *pKeys)
{
  int i; // ebx
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  CASW_Spawn_Definition *v6; // ecx
  int v7; // eax

  KeyValues::SetFloat(this: pKeys, keyName: "PosX", value: this->m_vecPosition.x);
  KeyValues::SetFloat(this: pKeys, keyName: "PosY", value: this->m_vecPosition.y);
  KeyValues::SetFloat(this: pKeys, keyName: "Radius", value: this->m_flEncounterRadius);
  for ( i = 0; i < this->m_SpawnDefs.m_Size; ++i )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "SpawnDef");
    else
      v5 = nullptr;
    v6 = this->m_SpawnDefs.m_Memory.m_pMemory[i];
    v7 = v6->GetID(this: v6);
    KeyValues::SetInt(this: v5, keyName: nullptr, value: v7);
    KeyValues::AddSubKey(this: pKeys, pSubkey: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025460
// Name: public: void CMapLayout::RemoveRoom(class CRoom __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLayout::RemoveRoom(CMapLayout *this, CRoom *pRoom)
{
  CRoom *v2; // esi
  const CRoomTemplate *m_pRoomTemplate; // eax
  int m_iPosX; // ebx
  int m_iPosY; // edi
  int v6; // eax
  int v7; // ecx
  CRoom *v8; // edx
  int m_nTilesX; // edx
  int x; // [esp+8h] [ebp-4h]

  CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int>>::FindAndRemove(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_PlacedRooms,
    src: (vgui::TreeNode *const *)&pRoom);
  v2 = pRoom;
  pRoom->m_pMapLayout = nullptr;
  if ( v2->m_pRoomTemplate != nullptr )
  {
    m_pRoomTemplate = v2->m_pRoomTemplate;
    m_iPosX = v2->m_iPosX;
    m_iPosY = v2->m_iPosY;
    x = m_iPosX;
    if ( m_iPosX < m_iPosX + m_pRoomTemplate->m_nTilesX )
    {
      v6 = m_iPosY + m_pRoomTemplate->m_nTilesY;
      pRoom = (CRoom *)&this->m_pRoomGrid[m_iPosX][m_iPosY];
      do
      {
        v7 = m_iPosY;
        if ( m_iPosY < v6 )
        {
          v8 = pRoom;
          do
          {
            v8->__vftable = nullptr;
            ++v7;
            v6 = m_iPosY + v2->m_pRoomTemplate->m_nTilesY;
            v8 = (CRoom *)((char *)v8 + 4);
          }
          while ( v7 < v6 );
        }
        m_nTilesX = v2->m_pRoomTemplate->m_nTilesX;
        pRoom = (CRoom *)((char *)pRoom + 480);
        ++x;
      }
      while ( x < m_iPosX + m_nTilesX );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025510
// Name: public: bool CMapLayout::SaveMapLayout(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapLayout::SaveMapLayout(CMapLayout *this, const char *filename)
{
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  KeyValues *v5; // ebx
  KeyValues *m_pGenerationOptions; // ecx
  KeyValues *Copy; // eax
  KeyValues *v8; // eax
  int m_Size; // ebx
  int i; // edi
  CRoom *v11; // ecx
  KeyValues *KeyValuesCopy; // eax
  int v13; // edi
  KeyValues *v14; // eax
  KeyValues *v15; // ebx
  CRoomTemplate *v16; // ecx
  int v17; // ebx
  KeyValues *v18; // eax
  KeyValues *v19; // edi
  int j; // ebx
  KeyValues *v21; // eax
  KeyValues *v22; // edi
  KeyValues *v23; // edi
  KeyValues *k; // esi
  CUtlBuffer buf; // [esp+Ch] [ebp-38h] BYREF
  int iRooms; // [esp+3Ch] [ebp-8h]
  KeyValues *pLayoutKeys; // [esp+40h] [ebp-4h]

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  v4 = nullptr;
  if ( v3 != nullptr )
  {
    v5 = KeyValues::KeyValues(this: v3, setName: "Layout");
    pLayoutKeys = v5;
  }
  else
  {
    pLayoutKeys = nullptr;
    v5 = nullptr;
  }
  m_pGenerationOptions = this->m_pGenerationOptions;
  if ( m_pGenerationOptions != nullptr )
  {
    Copy = KeyValues::MakeCopy(this: m_pGenerationOptions);
    KeyValues::AddSubKey(this: v5, pSubkey: Copy);
  }
  v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v8 != nullptr )
    v4 = KeyValues::KeyValues(this: v8, setName: "mapmisc");
  KeyValues::SetInt(this: v4, keyName: "PlayerStartX", value: this->m_iPlayerStartTileX);
  KeyValues::SetInt(this: v4, keyName: "PlayerStartY", value: this->m_iPlayerStartTileY);
  KeyValues::AddSubKey(this: v5, pSubkey: v4);
  m_Size = this->m_PlacedRooms.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    v11 = this->m_PlacedRooms.m_Memory.m_pMemory[i];
    if ( v11 != nullptr )
    {
      KeyValuesCopy = CRoom::GetKeyValuesCopy(this: v11);
      KeyValues::AddSubKey(this: pLayoutKeys, pSubkey: KeyValuesCopy);
    }
  }
  v13 = 0;
  iRooms = this->m_LogicalRooms.m_Size;
  if ( iRooms > 0 )
  {
    do
    {
      v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v14 != nullptr )
        v15 = KeyValues::KeyValues(this: v14, setName: "logical_room");
      else
        v15 = nullptr;
      v16 = this->m_LogicalRooms.m_Memory.m_pMemory[v13];
      if ( v16->m_pLevelTheme != nullptr )
        KeyValues::SetString(this: v15, keyName: "theme", value: v16->m_pLevelTheme->m_szName);
      KeyValues::SetString(
        this: v15,
        keyName: "template",
        value: this->m_LogicalRooms.m_Memory.m_pMemory[v13]->m_FullName);
      KeyValues::AddSubKey(this: pLayoutKeys, pSubkey: v15);
      ++v13;
    }
    while ( v13 < iRooms );
  }
  v17 = 0;
  if ( this->m_InstanceSpawns.m_Size > 0 )
  {
    iRooms = 0;
    do
    {
      v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v18 != nullptr )
        v19 = KeyValues::KeyValues(this: v18, setName: "instance_spawn");
      else
        v19 = nullptr;
      CInstanceSpawn::SaveToKeyValues(
        this: (CInstanceSpawn *)((char *)this->m_InstanceSpawns.m_Memory.m_pMemory + iRooms),
        pKeyValues: v19);
      KeyValues::AddSubKey(this: pLayoutKeys, pSubkey: v19);
      iRooms += 296;
      ++v17;
    }
    while ( v17 < this->m_InstanceSpawns.m_Size );
  }
  for ( j = 0; j < this->m_Encounters.m_Size; ++j )
  {
    v21 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v21 != nullptr )
      v22 = KeyValues::KeyValues(this: v21, setName: "npc_encounter");
    else
      v22 = nullptr;
    CASW_Encounter::SaveToKeyValues(this: this->m_Encounters.m_Memory.m_pMemory[j], pKeys: v22);
    KeyValues::AddSubKey(this: pLayoutKeys, pSubkey: v22);
  }
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  v23 = pLayoutKeys;
  for ( k = KeyValues::GetFirstSubKey(this: pLayoutKeys); k != nullptr; k = KeyValues::GetNextKey(this: k) )
    KeyValues::RecursiveSaveToFile(this: k, &buf, indentLevel: 0);
  KeyValues::deleteThis(this: v23);
  if ( g_pFullFileSystem->WriteFile(this: &g_pFullFileSystem->IBaseFileSystem, a2: filename, a3: "GAME", a4: &buf) )
  {
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return 1;
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Failed to SaveToFile %s\n");
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025820
// Name: public: CInstanceSpawn::CInstanceSpawn(void)
// Source: json
//------------------------------------------------------------------------------
CInstanceSpawn *__thiscall CInstanceSpawn::CInstanceSpawn(CInstanceSpawn *this)
{
  this->m_AdditionalKeyValues.m_Memory.m_pMemory = nullptr;
  this->m_AdditionalKeyValues.m_Memory.m_nAllocationCount = 0;
  this->m_AdditionalKeyValues.m_Memory.m_nGrowSize = 0;
  this->m_AdditionalKeyValues.m_Size = 0;
  this->m_AdditionalKeyValues.m_pElements = nullptr;
  this->m_AdditionalKeyValues.__vftable = (CCopyableUtlVector<KeyValue_t>_vtbl *)&CCopyableUtlVector<KeyValue_t>::`vftable';
  this->m_InstanceSpawningMethod = ISM_INVALID;
  this->m_nPlacedRoomIndex = -1;
  this->m_InstanceFilename[0] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10025860
// Name: public: bool CInstanceSpawn::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CInstanceSpawn::LoadFromKeyValues(CInstanceSpawn *this, KeyValues *pKeyValues)
{
  CInstanceSpawn *v2; // esi
  const char *String; // eax
  const char *v4; // eax
  KeyValues *i; // edi
  const char *Name; // eax
  int v8; // ebx
  const char *pValue; // [esp+Ch] [ebp-4h]
  const char *pKey; // [esp+18h] [ebp+8h]

  v2 = this;
  String = KeyValues::GetString(this: pKeyValues, keyName: "filename", defaultValue: nullptr);
  if ( String == nullptr )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "No 'filename' specified in CInstanceSpawn block.\n");
    return 0;
  }
  V_strncpy(pDest: v2->m_InstanceFilename, pSrc: String, maxLen: 260);
  v4 = KeyValues::GetString(this: pKeyValues, keyName: "type", defaultValue: nullptr);
  if ( v4 == nullptr )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
    {
      _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "No 'type' specified in CInstanceSpawn block.\n");
      return 0;
    }
    return 0;
  }
  if ( _V_stricmp(s1: v4, s2: "add_at_random_node") != 0 )
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_TilegenLayoutSystem, a2: 1) != 0 )
      _LoggingSystem_Log(a1: LOG_TilegenLayoutSystem, a2: 1, a3: "Invalid 'type' specified in CInstanceSpaw block.\n");
    return 0;
  }
  v2->m_InstanceSpawningMethod = ISM_ADD_AT_RANDOM_NODE;
  v2->m_nPlacedRoomIndex = KeyValues::GetInt(this: pKeyValues, keyName: "room_index", defaultValue: -1);
  v2->m_nRandomSeed = KeyValues::GetInt(this: pKeyValues, keyName: "random_seed", defaultValue: 0);
  for ( i = KeyValues::GetFirstSubKey(this: pKeyValues); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    if ( _V_stricmp(s1: Name, s2: "key_value") == 0 )
    {
      pKey = KeyValues::GetString(this: i, keyName: "key", defaultValue: szDescription);
      pValue = KeyValues::GetString(this: i, keyName: "value", defaultValue: szDescription);
      v8 = CUtlVector<KeyValue_t,CUtlMemory<KeyValue_t,int>>::AddToTail(this: &v2->m_AdditionalKeyValues.CUtlVector<KeyValue_t,CUtlMemory<KeyValue_t,int> >) << 7;
      V_strncpy(pDest: &v2->m_AdditionalKeyValues.m_Memory.m_pMemory->m_Key[v8], pSrc: pKey, maxLen: 64);
      V_strncpy(pDest: &v2->m_AdditionalKeyValues.m_Memory.m_pMemory->m_Value[v8], pSrc: pValue, maxLen: 64);
      v2 = this;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10025A40
// Name: public: bool CMapLayout::LoadLogicalRoom(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapLayout::LoadLogicalRoom(CMapLayout *this, KeyValues *pRoomKeys)
{
  const char *String; // eax
  const char *v3; // eax
  int m_Size; // ebx
  int v5; // edi
  CLevelTheme *v6; // esi
  int v8; // ebx
  int v9; // edi
  CRoomTemplate **m_pMemory; // eax
  CMapLayout *v11; // esi
  CRoomTemplate **v12; // ebx
  int v13; // edi
  int m_nAllocationCount; // eax
  CRoomTemplate **v15; // ecx
  int v16; // eax
  CRoomTemplate **v17; // edi
  char szLoadingTemplate[256]; // [esp+Ch] [ebp-204h] BYREF
  char szLoadingTheme[256]; // [esp+10Ch] [ebp-104h] BYREF
  CMapLayout *v20; // [esp+20Ch] [ebp-4h]

  v20 = this;
  szLoadingTheme[0] = 0;
  szLoadingTemplate[0] = 0;
  String = KeyValues::GetString(this: pRoomKeys, keyName: "theme", defaultValue: szDescription);
  V_snprintf(pDest: szLoadingTheme, maxLen: 256, pFormat: "%s", String);
  v3 = KeyValues::GetString(this: pRoomKeys, keyName: "template", defaultValue: szDescription);
  V_snprintf(pDest: szLoadingTemplate, maxLen: 256, pFormat: "%s", v3);
  m_Size = CLevelTheme::s_LevelThemes.m_Size;
  v5 = 0;
  if ( CLevelTheme::s_LevelThemes.m_Size <= 0 )
    return 0;
  while ( 1 )
  {
    v6 = CLevelTheme::s_LevelThemes.m_Memory.m_pMemory[v5];
    if ( v6 != nullptr && _V_stricmp(s1: v6->m_szName, s2: szLoadingTheme) == 0 )
      break;
    if ( ++v5 >= m_Size )
      return 0;
  }
  v8 = v6->m_RoomTemplates.m_Size;
  v9 = 0;
  if ( v8 <= 0 )
    return 0;
  while ( _V_stricmp(s1: v6->m_RoomTemplates.m_Memory.m_pMemory[v9]->m_FullName, s2: szLoadingTemplate) != 0 )
  {
    if ( ++v9 >= v8 )
      return 0;
  }
  m_pMemory = v6->m_RoomTemplates.m_Memory.m_pMemory;
  v11 = v20;
  v12 = &m_pMemory[v9];
  v13 = v20->m_LogicalRooms.m_Size;
  m_nAllocationCount = v20->m_LogicalRooms.m_Memory.m_nAllocationCount;
  if ( v13 + 1 > m_nAllocationCount )
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&v20->m_LogicalRooms,
      num: v13 - m_nAllocationCount + 1);
  ++v11->m_LogicalRooms.m_Size;
  v15 = v11->m_LogicalRooms.m_Memory.m_pMemory;
  v16 = v11->m_LogicalRooms.m_Size - v13 - 1;
  v11->m_LogicalRooms.m_pElements = v15;
  if ( v16 > 0 )
    _V_memmove(dest: &v15[v13 + 1], src: &v15[v13], count: 4 * v16);
  v17 = &v11->m_LogicalRooms.m_Memory.m_pMemory[v13];
  if ( v17 != nullptr )
    *v17 = *v12;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10025BA0
// Name: public: void CMapLayout::PlaceRoom(class CRoom __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLayout::PlaceRoom(CMapLayout *this, CRoom *pRoom)
{
  CMapLayout *v2; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CRoom **m_pMemory; // ecx
  int v6; // eax
  CRoom **v7; // ecx
  const CRoomTemplate *m_pRoomTemplate; // ecx
  int m_iPosX; // esi
  int v10; // edi
  int m_iPosY; // ecx
  CRoom **v12; // edx

  v2 = this;
  m_nAllocationCount = this->m_PlacedRooms.m_Memory.m_nAllocationCount;
  m_Size = this->m_PlacedRooms.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_PlacedRooms,
      num: m_Size - m_nAllocationCount + 1);
  ++v2->m_PlacedRooms.m_Size;
  m_pMemory = v2->m_PlacedRooms.m_Memory.m_pMemory;
  v6 = v2->m_PlacedRooms.m_Size - m_Size - 1;
  v2->m_PlacedRooms.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &v2->m_PlacedRooms.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = pRoom;
  m_pRoomTemplate = pRoom->m_pRoomTemplate;
  pRoom->m_nPlacementIndex = m_Size;
  pRoom->m_pMapLayout = v2;
  if ( m_pRoomTemplate != nullptr )
  {
    m_iPosX = pRoom->m_iPosX;
    if ( m_iPosX < m_iPosX + m_pRoomTemplate->m_nTilesX )
    {
      v10 = m_iPosX;
      do
      {
        m_iPosY = pRoom->m_iPosY;
        if ( m_iPosY < m_iPosY + pRoom->m_pRoomTemplate->m_nTilesY )
        {
          v12 = &v2->m_pRoomGrid[v10][m_iPosY];
          do
          {
            *v12 = pRoom;
            ++m_iPosY;
            ++v12;
          }
          while ( m_iPosY < pRoom->m_iPosY + pRoom->m_pRoomTemplate->m_nTilesY );
          v2 = this;
        }
        ++m_iPosX;
        ++v10;
      }
      while ( m_iPosX < pRoom->m_iPosX + pRoom->m_pRoomTemplate->m_nTilesX );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025C90
// Name: public: virtual void CASW_Encounter::AddSpawnDef(class CASW_Spawn_Definition __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Encounter::AddSpawnDef(CASW_Encounter *this, vgui::TreeNode *pSpawnDef)
{
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_SpawnDefs; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v6; // eax
  vgui::TreeNode **v7; // eax

  m_nAllocationCount = this->m_SpawnDefs.m_Memory.m_nAllocationCount;
  p_m_SpawnDefs = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_SpawnDefs;
  m_Size = this->m_SpawnDefs.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      this: p_m_SpawnDefs,
      num: m_Size - m_nAllocationCount + 1);
  ++p_m_SpawnDefs[1].m_pMemory;
  m_pMemory = p_m_SpawnDefs->m_pMemory;
  v6 = (int)p_m_SpawnDefs[1].m_pMemory - m_Size - 1;
  p_m_SpawnDefs[1].m_nAllocationCount = (int)p_m_SpawnDefs->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_SpawnDefs->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = pSpawnDef;
}

//------------------------------------------------------------------------------
// Address: 0x10025CF0
// Name: public: void CASW_Encounter::LoadFromKeyValues(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Encounter::LoadFromKeyValues(CASW_Encounter *this, KeyValues *pKeys)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_SpawnDefs; // esi
  KeyValues *i; // ebx
  const char *Name; // eax
  CASW_Spawn_Selection *v6; // eax
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v9; // ecx
  int v10; // eax
  CASW_Spawn_Definition **v11; // eax
  int v12; // eax
  int Int; // [esp+0h] [ebp-10h]
  CASW_Spawn_Definition *SpawnDefByID; // [esp+18h] [ebp+8h]

  p_m_SpawnDefs = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_SpawnDefs;
  this->m_SpawnDefs.m_Size = 0;
  if ( this->m_SpawnDefs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_SpawnDefs->m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_SpawnDefs->m_pMemory);
      p_m_SpawnDefs->m_pMemory = nullptr;
    }
    p_m_SpawnDefs->m_nAllocationCount = 0;
  }
  p_m_SpawnDefs[1].m_nAllocationCount = (int)p_m_SpawnDefs->m_pMemory;
  this->m_vecPosition.x = KeyValues::GetFloat(this: pKeys, keyName: "PosX", defaultValue: 0.0);
  this->m_vecPosition.y = KeyValues::GetFloat(this: pKeys, keyName: "PosY", defaultValue: 0.0);
  this->m_vecPosition.z = 0.0;
  this->m_flEncounterRadius = KeyValues::GetFloat(this: pKeys, keyName: "Radius", defaultValue: 0.0);
  for ( i = KeyValues::GetFirstSubKey(this: pKeys); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    if ( _V_stricmp(s1: Name, s2: "SpawnDef") == 0 )
    {
      Int = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0);
      v6 = SpawnSelection();
      SpawnDefByID = CASW_Spawn_Selection::GetSpawnDefByID(this: v6, nID: Int);
      if ( SpawnDefByID != nullptr )
      {
        m_pMemory = p_m_SpawnDefs[1].m_pMemory;
        m_nAllocationCount = p_m_SpawnDefs->m_nAllocationCount;
        if ( (int)m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
            this: p_m_SpawnDefs,
            num: (int)m_pMemory - m_nAllocationCount + 1);
        ++p_m_SpawnDefs[1].m_pMemory;
        v9 = p_m_SpawnDefs->m_pMemory;
        v10 = (char *)p_m_SpawnDefs[1].m_pMemory - (char *)m_pMemory - 1;
        p_m_SpawnDefs[1].m_nAllocationCount = (int)p_m_SpawnDefs->m_pMemory;
        if ( v10 > 0 )
          _V_memmove(dest: &v9[(_DWORD)m_pMemory + 1], src: &v9[(_DWORD)m_pMemory], count: 4 * v10);
        v11 = (CASW_Spawn_Definition **)&p_m_SpawnDefs->m_pMemory[(_DWORD)m_pMemory];
        if ( v11 != nullptr )
          *v11 = SpawnDefByID;
      }
      else
      {
        v12 = KeyValues::GetInt(this: i, keyName: nullptr, defaultValue: 0);
        _Msg(a1: "Failed to load spawn def %d for encounter.\n", v12);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10025E50
// Name: public: bool CMapLayout::CheckExitsOnSquares(class CRoomTemplate const __near *,int,int,enum ExitDirection_t,int,int,bool,class CUtlVector<class CRoomTemplateExit __near *,class CUtlMemory<class CRoomTemplateExit __near *,int>> __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapLayout::CheckExitsOnSquares(
        CMapLayout *this,
        const CRoomTemplate *pTemplate1,
        CRoomTemplateExit *offset_x,
        int offset_y,
        ExitDirection_t Direction,
        CRoomTemplateExit *x2,
        int y2,
        bool bRequireConnection,
        CUtlVector<CRoomTemplateExit *,CUtlMemory<CRoomTemplateExit *,int> > *pMatchingExits)
{
  CRoom *v10; // edi
  int m_Size; // ecx
  int v12; // eax
  CRoomTemplateExit **m_pMemory; // edx
  CRoomTemplateExit *v14; // edx
  CRoomTemplateExit *v15; // ebx
  ExitDirection_t v16; // eax
  char *v17; // esi
  int v18; // ecx
  int v19; // edi
  int v20; // ecx
  int v21; // edx
  CRoomTemplateExit **v22; // esi
  CRoomTemplateExit *v23; // eax
  int v24; // edi
  int m_nAllocationCount; // eax
  CRoomTemplateExit **v26; // ecx
  int v27; // eax
  CRoomTemplateExit **v28; // edi
  const CRoomTemplate *pTemplate2; // [esp+Ch] [ebp-8h]
  CRoomTemplateExit **v31; // [esp+10h] [ebp-4h]
  CRoomTemplateExit **OppositeDirection; // [esp+1Ch] [ebp+8h]
  ExitDirection_t OppositeDirectiona; // [esp+1Ch] [ebp+8h]
  int offset_x2; // [esp+28h] [ebp+14h]
  CRoomTemplateExit *pTemplate1_Exit; // [esp+2Ch] [ebp+18h]

  v10 = this->m_pRoomGrid[(_DWORD)x2][y2];
  pTemplate2 = v10->m_pRoomTemplate;
  m_Size = pTemplate1->m_Exits.m_Size;
  v12 = 0;
  pTemplate1_Exit = nullptr;
  if ( m_Size > 0 )
  {
    m_pMemory = pTemplate1->m_Exits.m_Memory.m_pMemory;
    v31 = pTemplate1->m_Exits.m_Memory.m_pMemory;
    OppositeDirection = pTemplate1->m_Exits.m_Memory.m_pMemory;
    while ( 1 )
    {
      v14 = *m_pMemory;
      if ( !v14->m_bChokepointGrowSource
        && (CRoomTemplateExit *)v14->m_iXPos == offset_x
        && v14->m_iYPos == offset_y
        && v14->m_ExitDirection == Direction )
      {
        break;
      }
      ++v12;
      m_pMemory = ++OppositeDirection;
      if ( v12 >= m_Size )
        goto LABEL_10;
    }
    pTemplate1_Exit = v31[v12];
  }
LABEL_10:
  v15 = nullptr;
  v16 = CRoomTemplateExit::GetOppositeDirection(Direction);
  v17 = (char *)x2 - v10->m_iPosX;
  OppositeDirectiona = v16;
  v18 = v10->m_iPosY + pTemplate2->m_nTilesY;
  v19 = pTemplate2->m_Exits.m_Size;
  v20 = v18 - y2 - 1;
  v21 = 0;
  offset_x2 = (int)v17;
  if ( v19 > 0 )
  {
    v22 = pTemplate2->m_Exits.m_Memory.m_pMemory;
    while ( 1 )
    {
      v23 = *v22;
      if ( (*v22)->m_iXPos == offset_x2 && v23->m_iYPos == v20 && v23->m_ExitDirection == OppositeDirectiona )
        break;
      ++v21;
      ++v22;
      if ( v21 >= v19 )
      {
        v15 = nullptr;
        goto LABEL_18;
      }
    }
    v15 = pTemplate2->m_Exits.m_Memory.m_pMemory[v21];
  }
LABEL_18:
  if ( pTemplate1_Exit != nullptr )
  {
    if ( v15 != nullptr && _V_stricmp(s1: pTemplate1_Exit->m_szExitTag, s2: v15->m_szExitTag) == 0 )
    {
      if ( pMatchingExits != nullptr )
      {
        v24 = pMatchingExits->m_Size;
        m_nAllocationCount = pMatchingExits->m_Memory.m_nAllocationCount;
        if ( v24 + 1 > m_nAllocationCount )
          CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)pMatchingExits,
            num: v24 - m_nAllocationCount + 1);
        ++pMatchingExits->m_Size;
        v26 = pMatchingExits->m_Memory.m_pMemory;
        v27 = pMatchingExits->m_Size - v24 - 1;
        pMatchingExits->m_pElements = pMatchingExits->m_Memory.m_pMemory;
        if ( v27 > 0 )
          _V_memmove(dest: &v26[v24 + 1], src: &v26[v24], count: 4 * v27);
        v28 = &pMatchingExits->m_Memory.m_pMemory[v24];
        if ( v28 != nullptr )
          *v28 = pTemplate1_Exit;
      }
      return 1;
    }
  }
  else if ( v15 == nullptr && !bRequireConnection )
  {
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10026130
// Name: public: bool CMapLayout::CheckExits(class CRoomTemplate const __near *,int,int,class CUtlVector<class CRoomTemplateExit __near *,class CUtlMemory<class CRoomTemplateExit __near *,int>> __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapLayout::CheckExits(
        CMapLayout *this,
        const CRoomTemplate *pTemplate,
        int x,
        int y,
        CUtlVector<CRoomTemplateExit *,CUtlMemory<CRoomTemplateExit *,int> > *pMatchingExits)
{
  int m_nTilesY; // ecx
  CRoomTemplateExit *v8; // edi
  int v9; // eax
  CRoom **v10; // ecx
  int v11; // edi
  CRoomTemplateExit *v12; // ecx
  int iRoomWide; // [esp+Ch] [ebp-Ch]
  CRoom **v15; // [esp+10h] [ebp-8h]
  int iRoomTall; // [esp+14h] [ebp-4h]
  CRoomTemplate ***ya; // [esp+28h] [ebp+10h]
  int yb; // [esp+28h] [ebp+10h]

  m_nTilesY = pTemplate->m_nTilesY;
  v8 = nullptr;
  iRoomWide = pTemplate->m_nTilesX;
  v9 = x;
  iRoomTall = m_nTilesY;
  if ( iRoomWide > 0 )
  {
    v10 = &this->m_pRoomGrid[x][y] + m_nTilesY;
    ya = &this->m_LogicalRooms.m_pElements + 120 * x + y;
    v15 = v10;
    while ( 1 )
    {
      if ( y > 0 && *ya != nullptr )
      {
        if ( CMapLayout::CheckExitsOnSquares(
               this,
               pTemplate1: pTemplate,
               offset_x: v8,
               offset_y: iRoomTall - 1,
               Direction: EXITDIR_SOUTH,
               x2: (CRoomTemplateExit *)((char *)v8 + v9),
               y2: y - 1,
               bRequireConnection: false,
               pMatchingExits) == 0 )
          return 0;
        v9 = x;
      }
      if ( y + iRoomTall < 120 && *v15 != nullptr )
      {
        if ( CMapLayout::CheckExitsOnSquares(
               this,
               pTemplate1: pTemplate,
               offset_x: v8,
               offset_y: 0,
               Direction: EXITDIR_BEGIN,
               x2: (CRoomTemplateExit *)((char *)v8 + v9),
               y2: y + iRoomTall,
               bRequireConnection: false,
               pMatchingExits) == 0 )
          return 0;
        v9 = x;
      }
      ya += 120;
      v15 += 120;
      v8 = (CRoomTemplateExit *)((char *)v8 + 1);
      if ( (int)v8 >= iRoomWide )
      {
        m_nTilesY = iRoomTall;
        break;
      }
    }
  }
  v11 = 0;
  if ( m_nTilesY > 0 )
  {
    yb = m_nTilesY - 1;
    do
    {
      if ( v9 > 0 && *((_DWORD *)this + 120 * v9 + y + v11 - 104) != 0 )
      {
        if ( CMapLayout::CheckExitsOnSquares(
               this,
               pTemplate1: pTemplate,
               offset_x: nullptr,
               offset_y: yb,
               Direction: EXITDIR_WEST,
               x2: (CRoomTemplateExit *)(v9 - 1),
               y2: v11 + y,
               bRequireConnection: false,
               pMatchingExits) == 0 )
          return 0;
        v9 = x;
      }
      v12 = (CRoomTemplateExit *)(v9 + iRoomWide);
      if ( v9 + iRoomWide < 120 && *((_DWORD *)&this->m_pRoomGrid[(_DWORD)v12][y] + v11) != 0 )
      {
        if ( CMapLayout::CheckExitsOnSquares(
               this,
               pTemplate1: pTemplate,
               offset_x: (CRoomTemplateExit *)(iRoomWide - 1),
               offset_y: yb,
               Direction: EXITDIR_EAST,
               x2: v12,
               y2: v11 + y,
               bRequireConnection: false,
               pMatchingExits) == 0 )
          return 0;
        v9 = x;
      }
      --yb;
      ++v11;
    }
    while ( v11 < iRoomTall );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100263A0
// Name: public: void CMapLayout::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapLayout::Clear(CMapLayout *this)
{
  int i; // edi
  CRoom *v3; // ecx

  for ( i = this->m_PlacedRooms.m_Size - 1; i >= 0; --i )
  {
    v3 = this->m_PlacedRooms.m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
      ((void (__thiscall *)(CRoom *, int))v3->dtr_CRoom)(a1: v3, a2: 1);
  }
  this->m_LogicalRooms.m_Size = 0;
  CUtlVector<CInstanceSpawn,CUtlMemory<CInstanceSpawn,int>>::RemoveAll(this: &this->m_InstanceSpawns);
  CUtlVector<CASW_Encounter *,CUtlMemory<CASW_Encounter *,int>>::PurgeAndDeleteElements(this: &this->m_Encounters);
  memset(this->m_pRoomGrid, 0, sizeof(this->m_pRoomGrid));
  this->m_iPlayerStartTileX = 60;
  this->m_iPlayerStartTileY = 60;
}

//------------------------------------------------------------------------------
// Address: 0x10026400
// Name: public: bool CMapLayout::LoadMapLayout(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapLayout::LoadMapLayout(CMapLayout *this, const char *filename)
{
  CMapLayout *v2; // esi
  KeyValues *v3; // eax
  KeyValues *NextKey; // edi
  IBaseFileSystem *v5; // eax
  const char *Name; // eax
  const char *v8; // eax
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  int v12; // eax
  const char *v13; // eax
  CASW_Encounter *v14; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CASW_Encounter **m_pMemory; // ecx
  int v18; // eax
  CASW_Encounter **v19; // ecx
  CASW_Encounter **v20; // ebx
  CASW_Encounter *pEncounter; // [esp+10h] [ebp-4h]

  v2 = this;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    NextKey = KeyValues::KeyValues(this: v3, setName: "LayoutKeys");
  else
    NextKey = nullptr;
  if ( g_pFullFileSystem != nullptr )
    v5 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v5 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: NextKey,
         filesystem: v5,
         resourceName: filename,
         pathID: "GAME",
         pfnEvaluateSymbolProc: nullptr) )
  {
    for ( ; NextKey != nullptr; NextKey = KeyValues::GetNextKey(this: NextKey) )
    {
      Name = KeyValues::GetName(this: NextKey);
      if ( _V_stricmp(s1: Name, s2: "room") != 0 )
      {
        v8 = KeyValues::GetName(this: NextKey);
        if ( _V_stricmp(s1: v8, s2: "logical_room") != 0 )
        {
          v9 = KeyValues::GetName(this: NextKey);
          if ( _V_stricmp(s1: v9, s2: "mapmisc") != 0 )
          {
            v10 = KeyValues::GetName(this: NextKey);
            if ( _V_stricmp(s1: v10, s2: "mission_settings") != 0 )
            {
              v11 = KeyValues::GetName(this: NextKey);
              if ( _V_stricmp(s1: v11, s2: "instance_spawn") != 0 )
              {
                v13 = KeyValues::GetName(this: NextKey);
                if ( _V_stricmp(s1: v13, s2: "npc_encounter") == 0 )
                {
                  v14 = (CASW_Encounter *)operator new(nSize: 0x28u);
                  if ( v14 != nullptr )
                  {
                    v14->__vftable = (CASW_Encounter_vtbl *)&CASW_Encounter::`vftable';
                    v14->m_SpawnDefs.m_Memory.m_pMemory = nullptr;
                    v14->m_SpawnDefs.m_Memory.m_nAllocationCount = 0;
                    v14->m_SpawnDefs.m_Memory.m_nGrowSize = 0;
                    v14->m_SpawnDefs.m_Size = 0;
                    v14->m_SpawnDefs.m_pElements = nullptr;
                    pEncounter = v14;
                    CASW_Encounter::LoadFromKeyValues(this: v14, pKeys: NextKey);
                  }
                  else
                  {
                    pEncounter = nullptr;
                    CASW_Encounter::LoadFromKeyValues(this: nullptr, pKeys: NextKey);
                  }
                  m_Size = v2->m_Encounters.m_Size;
                  m_nAllocationCount = v2->m_Encounters.m_Memory.m_nAllocationCount;
                  if ( m_Size + 1 > m_nAllocationCount )
                    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
                      this: (CUtlMemory<vgui::TreeNode *,int> *)&v2->m_Encounters,
                      num: m_Size - m_nAllocationCount + 1);
                  ++v2->m_Encounters.m_Size;
                  m_pMemory = v2->m_Encounters.m_Memory.m_pMemory;
                  v18 = v2->m_Encounters.m_Size - m_Size - 1;
                  v2->m_Encounters.m_pElements = m_pMemory;
                  if ( v18 > 0 )
                    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v18);
                  v19 = v2->m_Encounters.m_Memory.m_pMemory;
                  v2 = this;
                  v20 = &v19[m_Size];
                  if ( v20 != nullptr )
                    *v20 = pEncounter;
                }
              }
              else
              {
                v12 = CUtlVector<CInstanceSpawn,CUtlMemory<CInstanceSpawn,int>>::InsertBefore(
                        this: &v2->m_InstanceSpawns,
                        elem: v2->m_InstanceSpawns.m_Size);
                CInstanceSpawn::LoadFromKeyValues(
                  this: &v2->m_InstanceSpawns.m_Memory.m_pMemory[v12],
                  pKeyValues: NextKey);
              }
            }
            else
            {
              v2->m_pGenerationOptions = KeyValues::MakeCopy(this: NextKey);
            }
          }
          else
          {
            v2->m_iPlayerStartTileX = KeyValues::GetInt(this: NextKey, keyName: "PlayerStartX", defaultValue: 0);
            v2->m_iPlayerStartTileY = KeyValues::GetInt(this: NextKey, keyName: "PlayerStartY", defaultValue: 0);
          }
        }
        else
        {
          CMapLayout::LoadLogicalRoom(this: v2, pRoomKeys: NextKey);
        }
      }
      else if ( !CRoom::LoadRoomFromKeyValues(pRoomKeys: NextKey, pMapLayout: v2) )
      {
        return 0;
      }
    }
    CMapLayout::MarkEncounterRooms(this: v2);
    V_snprintf(pDest: v2->m_szFilename, maxLen: 260, pFormat: "%s", filename);
    KeyValues::deleteThis(this: NextKey);
    return 1;
  }
  else
  {
    _Msg(a1: "Failed to load map layout %s\n", filename);
    KeyValues::deleteThis(this: NextKey);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026690
// Name: public: bool CMapLayout::TemplateFits(class CRoomTemplate const __near *,int,int,bool)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMapLayout::TemplateFits(
        CMapLayout *this,
        const CRoomTemplate *pTemplate,
        int x,
        int y,
        bool bAllowNoExits)
{
  int v5; // edx
  int v6; // ebx
  const CRoomTemplate *v7; // eax
  int m_nTilesX; // ecx
  int m_nTilesY; // esi
  int v10; // edi
  CRoom **i; // ebx
  int v12; // eax
  CRoom **v13; // edx

  v5 = x;
  if ( x < 0 )
    return false;
  v6 = y;
  if ( y < 0 )
    return false;
  v7 = pTemplate;
  m_nTilesX = pTemplate->m_nTilesX;
  if ( m_nTilesX + x > 120 )
    return false;
  m_nTilesY = pTemplate->m_nTilesY;
  if ( m_nTilesY + y > 120 )
    return false;
  v10 = 0;
  if ( m_nTilesX > 0 )
  {
    for ( i = &this->m_pRoomGrid[x][y]; ; i += 120 )
    {
      v12 = 0;
      if ( m_nTilesY > 0 )
        break;
LABEL_12:
      if ( ++v10 >= m_nTilesX )
      {
        v7 = pTemplate;
        v6 = y;
        return bAllowNoExits && v7->m_Exits.m_Size == 0
            || CMapLayout::CheckExits(this, pTemplate: v7, x: v5, y: v6, pMatchingExits: nullptr) != 0;
      }
    }
    v13 = i;
    while ( *v13 == nullptr )
    {
      ++v12;
      ++v13;
      if ( v12 >= m_nTilesY )
      {
        v5 = x;
        goto LABEL_12;
      }
    }
    return false;
  }
  return bAllowNoExits && v7->m_Exits.m_Size == 0
      || CMapLayout::CheckExits(this, pTemplate: v7, x: v5, y: v6, pMatchingExits: nullptr) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100267C0
// Name: public: CMapLayout::CMapLayout(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CMapLayout *__thiscall CMapLayout::CMapLayout(CMapLayout *this, KeyValues *pGenerationOptions)
{
  CRoom **v3; // edx
  int i; // ebx
  CRoom **v5; // eax
  int j; // ecx

  this->__vftable = (CMapLayout_vtbl *)&CMapLayout::`vftable';
  this->m_InstanceSpawns.m_Memory.m_pMemory = nullptr;
  this->m_InstanceSpawns.m_Memory.m_nAllocationCount = 0;
  this->m_InstanceSpawns.m_Memory.m_nGrowSize = 0;
  this->m_InstanceSpawns.m_Size = 0;
  this->m_InstanceSpawns.m_pElements = nullptr;
  this->m_PlacedRooms.m_Memory.m_pMemory = nullptr;
  this->m_PlacedRooms.m_Memory.m_nAllocationCount = 0;
  this->m_PlacedRooms.m_Memory.m_nGrowSize = 0;
  this->m_PlacedRooms.m_Size = 0;
  this->m_PlacedRooms.m_pElements = nullptr;
  this->m_LogicalRooms.m_Memory.m_pMemory = nullptr;
  this->m_LogicalRooms.m_Memory.m_nAllocationCount = 0;
  this->m_LogicalRooms.m_Memory.m_nGrowSize = 0;
  this->m_LogicalRooms.m_Size = 0;
  this->m_LogicalRooms.m_pElements = nullptr;
  this->m_Encounters.m_Memory.m_pMemory = nullptr;
  this->m_Encounters.m_Memory.m_nAllocationCount = 0;
  this->m_Encounters.m_Memory.m_nGrowSize = 0;
  this->m_Encounters.m_Size = 0;
  this->m_Encounters.m_pElements = nullptr;
  this->m_pGenerationOptions = pGenerationOptions;
  V_snprintf(pDest: this->m_szFilename, maxLen: 260, pFormat: "%s", szDescription);
  this->m_iPlayerStartTileX = 60;
  this->m_iPlayerStartTileY = 60;
  v3 = this->m_pRoomGrid[0];
  for ( i = 120; i != 0; --i )
  {
    v5 = v3;
    for ( j = 120; j != 0; --j )
    {
      *v5 = nullptr;
      v5 += 120;
    }
    ++v3;
  }
  return this;
}
