// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/vmfexporter.cpp
// Functions: 27
// ============================================================

#include "missionchooser\vmfexporter.h"

//------------------------------------------------------------------------------
// Address: 0x1000A450
// Name: public: float __near & Vector::operator[](int)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall Vector::operator[](Vector *this, int i)
{
  return (Vector *)((char *)this + 4 * i);
}

//------------------------------------------------------------------------------
// Address: 0x1000A460
// Name: public: bool VMFExporter::IsDisplacementBrush(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall VMFExporter::IsDisplacementBrush(VMFExporter *this, KeyValues *pSolidKeys)
{
  KeyValues *FirstSubKey; // esi
  const char *Name; // eax

  FirstSubKey = KeyValues::GetFirstSubKey(this: pSolidKeys);
  if ( FirstSubKey == nullptr )
    return 0;
  while ( 1 )
  {
    Name = KeyValues::GetName(this: FirstSubKey);
    if ( _V_stricmp(s1: Name, s2: "side") == 0
      && KeyValues::FindKey(this: FirstSubKey, keyName: "dispinfo", bCreate: false) != nullptr )
    {
      break;
    }
    FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
    if ( FirstSubKey == nullptr )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000A4C0
// Name: public: void VMFExporter::ReorderObjectives(class CRoomTemplate const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VMFExporter::ReorderObjectives(
        VMFExporter *this,
        const CRoomTemplate *pTemplate,
        KeyValues *pTemplateKeys)
{
  KeyValues *i; // esi
  const char *Name; // eax
  const char *String; // eax

  for ( i = this->m_pTemplateKeys; i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    if ( _V_stricmp(s1: Name, s2: "entity") == 0 )
    {
      String = KeyValues::GetString(this: i, keyName: "classname", defaultValue: szDescription);
      if ( V_strnicmp(s1: String, s2: "asw_objective", n: 13) == 0
        && KeyValues::GetFloat(this: i, keyName: "Priority", defaultValue: 0.0) == 0.0 )
      {
        KeyValues::SetFloat(this: i, keyName: "Priority", value: 100.0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A560
// Name: public: class Vector const __near & VMFExporter::GetCurrentRoomOffset(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall VMFExporter::GetCurrentRoomOffset(VMFExporter *this)
{
  if ( (_S1 & 1) == 0 )
  {
    _S1 |= 1u;
    s_vecCurrentRoomOffset = vec3_origin;
  }
  if ( this->m_pRoom != nullptr )
  {
    s_vecCurrentRoomOffset.x = (float)(this->m_pRoom->m_iPosX - 60) * 256.0;
    s_vecCurrentRoomOffset.y = (float)(this->m_pRoom->m_iPosY - 60) * 256.0;
    s_vecCurrentRoomOffset.z = 0.0;
  }
  else
  {
    s_vecCurrentRoomOffset.x = 0.0;
    s_vecCurrentRoomOffset.y = 0.0;
    s_vecCurrentRoomOffset.z = 1024.0;
  }
  return &s_vecCurrentRoomOffset;
}

//------------------------------------------------------------------------------
// Address: 0x1000A610
// Name: public: void VMFExporter::AddRoomInstance(class CRoomTemplate const __near *,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall VMFExporter::AddRoomInstance(
        VMFExporter *this,
        const CRoomTemplate *pRoomTemplate,
        int nPlacedRoomIndex)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  int v6; // eax
  int i; // ecx
  const Vector *CurrentRoomOffset; // eax
  __int64 v9; // xmm0_8
  float z; // eax
  char pDest[8]; // [esp+8h] [ebp-190h] BYREF
  char buf[128]; // [esp+20h] [ebp-178h] BYREF
  _BYTE vmfName_236[12]; // [esp+18Ch] [ebp-Ch] OVERLAPPED

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "entity");
  else
    v5 = nullptr;
  KeyValues::SetInt(this: v5, keyName: "id", value: ++this->m_iEntityCount);
  KeyValues::SetString(this: v5, keyName: "classname", value: "func_instance");
  KeyValues::SetString(this: v5, keyName: "angles", value: "0 0 0");
  if ( nPlacedRoomIndex != -1 )
    KeyValues::SetInt(this: v5, keyName: "PlacedRoomIndex", value: nPlacedRoomIndex);
  V_snprintf(
    pDest: &buf[104],
    maxLen: 260,
    pFormat: "tilegen/roomtemplates/%s/%s.vmf",
    pRoomTemplate->m_pLevelTheme->m_szName,
    pRoomTemplate->m_FullName);
  v6 = _V_strlen(str: &buf[104]);
  for ( i = 0; i < v6; ++i )
  {
    if ( buf[i + 104] == 92 )
      buf[i + 104] = 47;
  }
  KeyValues::SetString(this: v5, keyName: "file", value: &buf[104]);
  CurrentRoomOffset = VMFExporter::GetCurrentRoomOffset(this);
  v9 = *(_QWORD *)&CurrentRoomOffset->x;
  z = CurrentRoomOffset->z;
  *(_QWORD *)vmfName_236 = v9;
  *(float *)&vmfName_236[8] = z;
  V_snprintf(pDest, maxLen: 128, pFormat: "%f %f %f", *(float *)&v9, *((float *)&v9 + 1), z);
  KeyValues::SetString(this: v5, keyName: "origin", value: pDest);
  KeyValues::AddSubKey(this: this->m_pExportKeys, pSubkey: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1000A770
// Name: public: class KeyValues __near * VMFExporter::GetVersionInfo(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall VMFExporter::GetVersionInfo(VMFExporter *this)
{
  KeyValues *v1; // eax
  KeyValues *v2; // esi

  v1 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v1 != nullptr )
    v2 = KeyValues::KeyValues(this: v1, setName: "versioninfo");
  else
    v2 = nullptr;
  KeyValues::SetInt(this: v2, keyName: "editorversion", value: 400);
  KeyValues::SetInt(this: v2, keyName: "editorbuild", value: 3900);
  KeyValues::SetInt(this: v2, keyName: "mapversion", value: 1);
  KeyValues::SetInt(this: v2, keyName: "formatversion", value: 100);
  KeyValues::SetInt(this: v2, keyName: "prefab", value: 0);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1000A7F0
// Name: public: class KeyValues __near * VMFExporter::GetDefaultCamera(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall VMFExporter::GetDefaultCamera(VMFExporter *this)
{
  KeyValues *v1; // eax
  KeyValues *v2; // edi
  KeyValues *v3; // eax
  KeyValues *v4; // esi

  v1 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v1 != nullptr )
    v2 = KeyValues::KeyValues(this: v1, setName: "cameras");
  else
    v2 = nullptr;
  KeyValues::SetInt(this: v2, keyName: "activecamera", value: 0);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "camera");
  else
    v4 = nullptr;
  KeyValues::SetString(this: v4, keyName: "position", value: "[135.491 -60.314 364.02]");
  KeyValues::SetString(this: v4, keyName: "look", value: "[141.195 98.7571 151.25]");
  KeyValues::AddSubKey(this: v2, pSubkey: v4);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1000A870
// Name: public: class KeyValues __near * VMFExporter::GetPlayerStarts(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall VMFExporter::GetPlayerStarts(VMFExporter *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  int m_iEntityCount; // eax
  char pDest[16]; // [esp+8h] [ebp-80h] BYREF

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "entity");
  else
    v3 = nullptr;
  m_iEntityCount = this->m_iEntityCount;
  this->m_iEntityCount = m_iEntityCount + 1;
  KeyValues::SetInt(this: v3, keyName: "id", value: m_iEntityCount);
  KeyValues::SetString(this: v3, keyName: "classname", value: "info_player_start");
  KeyValues::SetString(this: v3, keyName: "angles", value: "0 0 0");
  V_snprintf(
    pDest,
    maxLen: 128,
    pFormat: "%f %f 1.0",
    (float)((float)((float)(this->m_pMapLayout->m_iPlayerStartTileX - 60) * 256.0) + 128.0),
    (float)((float)((float)(this->m_pMapLayout->m_iPlayerStartTileY - 60) * 256.0) + 128.0));
  KeyValues::SetString(this: v3, keyName: "origin", value: pDest);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1000A960
// Name: public: class KeyValues __near * VMFExporter::GetGameRulesProxy(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall VMFExporter::GetGameRulesProxy(VMFExporter *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  int m_iEntityCount; // eax
  KeyValues *m_pGenerationOptions; // ecx
  int v6; // eax
  char pDest[8]; // [esp+8h] [ebp-80h] BYREF

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "entity");
  else
    v3 = nullptr;
  m_iEntityCount = this->m_iEntityCount;
  this->m_iEntityCount = m_iEntityCount + 1;
  KeyValues::SetInt(this: v3, keyName: "id", value: m_iEntityCount);
  KeyValues::SetString(this: v3, keyName: "classname", value: "asw_gamerules");
  KeyValues::SetString(this: v3, keyName: "targetname", value: "@asw_gamerules");
  V_snprintf(
    pDest,
    maxLen: 128,
    pFormat: "%f %f %f",
    this->m_vecStartRoomOrigin.x,
    this->m_vecStartRoomOrigin.y,
    this->m_vecStartRoomOrigin.z);
  KeyValues::SetString(this: v3, keyName: "origin", value: pDest);
  m_pGenerationOptions = this->m_pMapLayout->m_pGenerationOptions;
  v6 = 0;
  if ( m_pGenerationOptions != nullptr )
    v6 = KeyValues::GetInt(this: m_pGenerationOptions, keyName: "Difficulty", defaultValue: 5) - 5;
  KeyValues::SetInt(this: v3, keyName: "difficultymodifier", value: v6);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1000AA60
// Name: public: class KeyValues __near * VMFExporter::GetDefaultWorldChunk(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall VMFExporter::GetDefaultWorldChunk(VMFExporter *this)
{
  KeyValues *v1; // eax
  KeyValues *v2; // esi

  v1 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v1 != nullptr )
    v2 = KeyValues::KeyValues(this: v1, setName: "world");
  else
    v2 = nullptr;
  KeyValues::SetInt(this: v2, keyName: "id", value: 1);
  KeyValues::SetInt(this: v2, keyName: "mapversion", value: 1);
  KeyValues::SetString(this: v2, keyName: "classname", value: "worldspawn");
  KeyValues::SetString(this: v2, keyName: "skyname", value: "blacksky");
  KeyValues::SetInt(this: v2, keyName: "maxpropscreenwidth", value: -1);
  KeyValues::SetString(this: v2, keyName: "detailvbsp", value: "detail.vbsp");
  KeyValues::SetString(this: v2, keyName: "detailmaterial", value: "detail/detailsprites");
  KeyValues::SetInt(this: v2, keyName: "speedruntime", value: 180);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1000AB10
// Name: public: bool VMFExporter::ProcessGenericRecursive(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __thiscall VMFExporter::ProcessGenericRecursive(VMFExporter *this, KeyValues *pKey)
{
  const char *Name; // edi
  const Vector *CurrentRoomOffset; // eax
  KeyValues *FirstSubKey; // esi
  char pDest[28]; // [esp+20h] [ebp-110h] BYREF
  _BYTE buffer_232[12]; // [esp+124h] [ebp-Ch] OVERLAPPED BYREF
  const char *buffer_252; // [esp+138h] [ebp+8h]

  Name = KeyValues::GetName(this: pKey);
  buffer_252 = KeyValues::GetString(this: pKey, keyName: nullptr, defaultValue: szDescription);
  if ( _V_stricmp(s1: Name, s2: "startposition") == 0 )
  {
    if ( sscanf(string: buffer_252, format: "[%f %f %f]", buffer_232, &buffer_232[4], &buffer_232[8]) != 3 )
      return 0;
    CurrentRoomOffset = VMFExporter::GetCurrentRoomOffset(this);
    *(float *)buffer_232 = CurrentRoomOffset->x + *(float *)buffer_232;
    *(float *)&buffer_232[4] = CurrentRoomOffset->y + *(float *)&buffer_232[4];
    *(float *)&buffer_232[8] = CurrentRoomOffset->z + *(float *)&buffer_232[8];
    V_snprintf(
      pDest: &pDest[4],
      maxLen: 256,
      pFormat: "[%f %f %f]",
      *(float *)buffer_232,
      *(float *)&buffer_232[4],
      *(float *)&buffer_232[8]);
    KeyValues::SetStringValue(this: pKey, strValue: &pDest[4]);
  }
  if ( KeyValues::GetFirstSubKey(this: pKey) != nullptr )
  {
    FirstSubKey = KeyValues::GetFirstSubKey(this: pKey);
    if ( FirstSubKey != nullptr )
    {
      while ( VMFExporter::ProcessGenericRecursive(this, pKey: FirstSubKey) )
      {
        FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
        if ( FirstSubKey == nullptr )
          return 1;
      }
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000AC40
// Name: public: bool VMFExporter::ProcessConnections(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall VMFExporter::ProcessConnections(VMFExporter *this, KeyValues *pConnections)
{
  KeyValues *i; // esi
  const char *String; // eax
  char pDest[256]; // [esp+8h] [ebp-100h] BYREF

  for ( i = KeyValues::GetFirstSubKey(this: pConnections); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    String = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: szDescription);
    if ( String == nullptr || *String == 64 )
      V_snprintf(pDest, maxLen: 256, pFormat: "%s", String);
    else
      V_snprintf(pDest, maxLen: 256, pFormat: "Room%d_%s", this->m_iCurrentRoom, String);
    KeyValues::SetStringValue(this: i, strValue: pDest);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000ACE0
// Name: public: bool VMFExporter::ShowExportErrors(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall VMFExporter::ShowExportErrors(VMFExporter *this)
{
  int v3; // esi
  char pDest[4096]; // [esp+4h] [ebp-1000h] BYREF

  if ( this->m_ExportErrors.m_Size <= 0 )
    return 0;
  v3 = 0;
  pDest[0] = 0;
  do
    V_snprintf(pDest, maxLen: 4096, pFormat: "%s\n%s", pDest, this->m_ExportErrors.m_Memory.m_pMemory[v3++]);
  while ( v3 < this->m_ExportErrors.m_Size );
  VGUIMessageBox(pParent: g_pTileGenDialog, pTitle: "Export problems:", pMsg: pDest);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000AD70
// Name: public: bool VMFExporter::ProcessEntityKey(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall VMFExporter::ProcessEntityKey(VMFExporter *this, KeyValues *pKey)
{
  const char *String; // edi
  KeyValues *v4; // ecx
  int v6; // eax
  int v7; // ecx
  VMFExporter::SideTranslation_t **m_pMemory; // edx
  int v9; // ebx
  int v10; // edi
  const char *v11; // eax
  int v12; // ebx
  const char *v13; // eax
  int v14; // eax
  int v15; // ecx
  VMFExporter::NodeTranslation_t **v16; // edx
  const Vector *CurrentRoomOffset; // eax
  char strValue[28]; // [esp+20h] [ebp-140h] BYREF
  char v19[24]; // [esp+124h] [ebp-3Ch] BYREF
  char buffer[32]; // [esp+13Ch] [ebp-24h] BYREF
  int i; // [esp+15Ch] [ebp-4h]

  i = (int)KeyValues::GetName(this: pKey);
  String = KeyValues::GetString(this: pKey, keyName: nullptr, defaultValue: szDescription);
  *(_DWORD *)&buffer[16] = String;
  if ( _V_stricmp(s1: (const char *)i, s2: "id") == 0 )
  {
    V_snprintf(pDest: v19, maxLen: 32, pFormat: "%d", ++this->m_iEntityCount);
    v4 = pKey;
    goto LABEL_35;
  }
  if ( _V_stricmp(s1: (const char *)i, s2: "origin") == 0 )
  {
    if ( sscanf(string: String, format: "%f %f %f", &buffer[20], &buffer[24], &buffer[28]) != 3 )
      return 0;
LABEL_32:
    CurrentRoomOffset = VMFExporter::GetCurrentRoomOffset(this);
    *(float *)&buffer[20] = CurrentRoomOffset->x + *(float *)&buffer[20];
    *(float *)&buffer[24] = CurrentRoomOffset->y + *(float *)&buffer[24];
    *(float *)&buffer[28] = CurrentRoomOffset->z + *(float *)&buffer[28];
    V_snprintf(
      pDest: &strValue[4],
      maxLen: 256,
      pFormat: "%f %f %f",
      *(float *)&buffer[20],
      *(float *)&buffer[24],
      *(float *)&buffer[28]);
    KeyValues::SetStringValue(this: pKey, strValue: &strValue[4]);
    return 1;
  }
  if ( _V_stricmp(s1: (const char *)i, s2: "sides") != 0 )
  {
    if ( _V_stricmp(s1: (const char *)i, s2: "BasisOrigin") == 0 )
    {
      if ( sscanf(string: String, format: "%f %f %f", &buffer[20], &buffer[24], &buffer[28]) != 3 )
        return 0;
      goto LABEL_32;
    }
  }
  else
  {
    v6 = atoi(nptr: String);
    v7 = 0;
    if ( this->m_SideTranslations.m_Size > 0 )
    {
      m_pMemory = this->m_SideTranslations.m_Memory.m_pMemory;
      while ( (*m_pMemory)->m_iOriginalSide != v6 )
      {
        ++v7;
        ++m_pMemory;
        if ( v7 >= this->m_SideTranslations.m_Size )
        {
          String = *(const char **)&buffer[16];
          goto LABEL_13;
        }
      }
      V_snprintf(pDest: v19, maxLen: 32, pFormat: "%d", (*m_pMemory)->m_iNewSide);
      KeyValues::SetStringValue(this: pKey, strValue: v19);
      return 1;
    }
  }
LABEL_13:
  v9 = 0;
  *(_DWORD *)&buffer[12] = this->m_UniqueKeys.m_Size;
  if ( *(int *)&buffer[12] <= 0 )
  {
LABEL_20:
    v12 = 0;
    *(_DWORD *)&buffer[12] = this->m_NodeIDKeys.m_Size;
    *(_DWORD *)&buffer[8] = 0;
    if ( *(int *)&buffer[12] <= 0 )
      return 1;
    while ( 1 )
    {
      v13 = CUtlString::operator char const *(this: &this->m_NodeIDKeys.m_Memory.m_pMemory[v12]);
      if ( _V_stricmp(s1: (const char *)i, s2: v13) == 0 )
      {
        v14 = atoi(nptr: String);
        v15 = 0;
        if ( this->m_NodeTranslations.m_Size > 0 )
          break;
      }
LABEL_27:
      ++v12;
      ++*(_DWORD *)&buffer[8];
      if ( *(int *)&buffer[8] >= *(int *)&buffer[12] )
        return 1;
    }
    v16 = this->m_NodeTranslations.m_Memory.m_pMemory;
    while ( (*v16)->m_iOriginalNodeID != v14 )
    {
      ++v15;
      ++v16;
      if ( v15 >= this->m_NodeTranslations.m_Size )
      {
        String = *(const char **)&buffer[16];
        goto LABEL_27;
      }
    }
    V_snprintf(pDest: v19, maxLen: 32, pFormat: "%d", (*v16)->m_iNewNodeID);
    v4 = pKey;
LABEL_35:
    KeyValues::SetStringValue(this: v4, strValue: v19);
    return 1;
  }
  v10 = 0;
  while ( 1 )
  {
    v11 = CUtlString::operator char const *(this: &this->m_UniqueKeys.m_Memory.m_pMemory[v10]);
    if ( _V_stricmp(s1: (const char *)i, s2: v11) == 0 && *(_DWORD *)&buffer[16] != 0 && **(_BYTE **)&buffer[16] != 64 )
      break;
    ++v9;
    ++v10;
    if ( v9 >= *(int *)&buffer[12] )
    {
      String = *(const char **)&buffer[16];
      goto LABEL_20;
    }
  }
  V_snprintf(pDest: &strValue[4], maxLen: 256, pFormat: "Room%d_%s", this->m_iCurrentRoom, *(const char **)&buffer[16]);
  KeyValues::SetStringValue(this: pKey, strValue: &strValue[4]);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000B180
// Name: public: void VMFExporter::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VMFExporter::Init(VMFExporter *this)
{
  this->m_szLastExporterError[0] = 0;
  this->m_SideTranslations.m_Size = 0;
  if ( this->m_SideTranslations.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SideTranslations.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SideTranslations.m_Memory.m_pMemory);
      this->m_SideTranslations.m_Memory.m_pMemory = nullptr;
    }
    this->m_SideTranslations.m_Memory.m_nAllocationCount = 0;
  }
  this->m_SideTranslations.m_pElements = this->m_SideTranslations.m_Memory.m_pMemory;
  this->m_NodeTranslations.m_Size = 0;
  if ( this->m_NodeTranslations.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_NodeTranslations.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_NodeTranslations.m_Memory.m_pMemory);
      this->m_NodeTranslations.m_Memory.m_pMemory = nullptr;
    }
    this->m_NodeTranslations.m_Memory.m_nAllocationCount = 0;
  }
  this->m_NodeTranslations.m_pElements = this->m_NodeTranslations.m_Memory.m_pMemory;
  this->m_vecLastPlaneOffset = vec3_origin;
  this->m_bWritingLevelContainer = false;
  this->m_iSideCount = 0;
  this->m_pTemplateKeys = nullptr;
  this->m_iNextNodeID = 0;
  this->m_pRoom = nullptr;
  this->m_iCurrentRoom = 0;
  this->m_iMapExtents_XMin = 0;
  this->m_iMapExtents_YMin = 0;
  this->m_iMapExtents_XMax = 0;
  this->m_iMapExtents_YMax = 0;
  this->m_pExportKeys = nullptr;
  this->m_iEntityCount = 1;
  this->m_vecStartRoomOrigin = vec3_origin;
  CUtlVector<VMFExporter::SideTranslation_t *,CUtlMemory<VMFExporter::SideTranslation_t *,int>>::PurgeAndDeleteElements(this: (CUtlVector<char *,CUtlMemory<char *,int> > *)&this->m_ExportErrors);
}

//------------------------------------------------------------------------------
// Address: 0x1000B2A0
// Name: public: bool VMFExporter::ProcessSideKey(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall VMFExporter::ProcessSideKey(VMFExporter *this, KeyValues *pKey)
{
  const char *Name; // ebx
  const char *String; // edi
  VMFExporter::SideTranslation_t *v5; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  VMFExporter::SideTranslation_t **m_pMemory; // ecx
  int v9; // eax
  VMFExporter::SideTranslation_t **v10; // edi
  __m128i v12; // xmm6
  float v13; // xmm6_4
  __m128i v14; // xmm5
  float v15; // xmm5_4
  __m128i v16; // xmm4
  float v17; // xmm4_4
  __m128i v18; // xmm3
  float v19; // xmm3_4
  __m128i v20; // xmm2
  float v21; // xmm2_4
  __m128i v22; // xmm1
  float v23; // xmm1_4
  float *v24; // edi
  int i; // ebx
  const Vector *CurrentRoomOffset; // eax
  const Vector *v27; // eax
  char v28[76]; // [esp+50h] [ebp-13Ch] BYREF
  float v29; // [esp+154h] [ebp-38h] BYREF
  float v30; // [esp+158h] [ebp-34h] BYREF
  float v31; // [esp+15Ch] [ebp-30h] BYREF
  float v32; // [esp+160h] [ebp-2Ch] BYREF
  float v33; // [esp+164h] [ebp-28h] BYREF
  float v34; // [esp+168h] [ebp-24h] BYREF
  char strValue[4]; // [esp+16Ch] [ebp-20h] BYREF
  float v36; // [esp+170h] [ebp-1Ch] BYREF
  float v37; // [esp+174h] [ebp-18h] BYREF
  float v38; // [esp+178h] [ebp-14h] BYREF
  float v39; // [esp+17Ch] [ebp-10h] BYREF
  float v40; // [esp+180h] [ebp-Ch] BYREF
  float v41; // [esp+184h] [ebp-8h] BYREF
  float v42; // [esp+188h] [ebp-4h] BYREF

  Name = KeyValues::GetName(this: pKey);
  String = KeyValues::GetString(this: pKey, keyName: nullptr, defaultValue: szDescription);
  if ( _V_stricmp(s1: Name, s2: "id") == 0 )
  {
    v5 = (VMFExporter::SideTranslation_t *)operator new(nSize: 8u);
    v5->m_iOriginalSide = atoi(nptr: String);
    V_snprintf(pDest: strValue, maxLen: 32, pFormat: "%d", ++this->m_iSideCount);
    KeyValues::SetStringValue(this: pKey, strValue);
    v5->m_iNewSide = this->m_iSideCount;
    m_Size = this->m_SideTranslations.m_Size;
    m_nAllocationCount = this->m_SideTranslations.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_SideTranslations,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_SideTranslations.m_Size;
    m_pMemory = this->m_SideTranslations.m_Memory.m_pMemory;
    v9 = this->m_SideTranslations.m_Size - m_Size - 1;
    this->m_SideTranslations.m_pElements = m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
    v10 = &this->m_SideTranslations.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
    {
      *v10 = v5;
      return 1;
    }
    return 1;
  }
  if ( _V_stricmp(s1: Name, s2: "plane") != 0 )
  {
    if ( _V_stricmp(s1: Name, s2: "uaxis") == 0 || _V_stricmp(s1: Name, s2: "vaxis") == 0 )
    {
      v33 = 0.0;
      v32 = 1.0;
      if ( sscanf(string: String, format: "[%f %f %f %f] %f", &v29, &v30, &v31, &v33, &v32) == 5 )
      {
        v33 = v33
            - (float)((float)((float)((float)(this->m_vecLastPlaneOffset.y * v30)
                                    + (float)(this->m_vecLastPlaneOffset.x * v29))
                            + (float)(this->m_vecLastPlaneOffset.z * v31))
                    / v32);
        V_snprintf(pDest: &v28[4], maxLen: 256, pFormat: "[%f %f %f %f] %f", v29, v30, v31, v33, v32);
        KeyValues::SetStringValue(this: pKey, strValue: &v28[4]);
        return 1;
      }
      _Msg(a1: "Error loading in uvaxis\n");
    }
    return 1;
  }
  if ( sscanf(
         string: String,
         format: "(%f %f %f) (%f %f %f) (%f %f %f)",
         &v34,
         strValue,
         &v36,
         &v37,
         &v38,
         &v39,
         &v40,
         &v41,
         &v42) != 9 )
    return 0;
  if ( this->m_bWritingLevelContainer )
  {
    if ( v34 >= 0.0 )
      v12 = _mm_cvtsi32_si128(this->m_iMapExtents_XMax);
    else
      v12 = _mm_cvtsi32_si128(this->m_iMapExtents_XMin);
    v13 = (float)(_mm_cvtepi32_ps(v12).m128_f32[0] * 256.0) + v34;
    v34 = v13;
    if ( *(float *)strValue >= 0.0 )
      v14 = _mm_cvtsi32_si128(this->m_iMapExtents_YMax);
    else
      v14 = _mm_cvtsi32_si128(this->m_iMapExtents_YMin);
    v15 = (float)(_mm_cvtepi32_ps(v14).m128_f32[0] * 256.0) + *(float *)strValue;
    *(float *)strValue = v15;
    if ( v37 >= 0.0 )
      v16 = _mm_cvtsi32_si128(this->m_iMapExtents_XMax);
    else
      v16 = _mm_cvtsi32_si128(this->m_iMapExtents_XMin);
    v17 = (float)(_mm_cvtepi32_ps(v16).m128_f32[0] * 256.0) + v37;
    v37 = v17;
    if ( v38 >= 0.0 )
      v18 = _mm_cvtsi32_si128(this->m_iMapExtents_YMax);
    else
      v18 = _mm_cvtsi32_si128(this->m_iMapExtents_YMin);
    v19 = (float)(_mm_cvtepi32_ps(v18).m128_f32[0] * 256.0) + v38;
    v38 = v19;
    if ( v40 >= 0.0 )
      v20 = _mm_cvtsi32_si128(this->m_iMapExtents_XMax);
    else
      v20 = _mm_cvtsi32_si128(this->m_iMapExtents_XMin);
    v21 = (float)(_mm_cvtepi32_ps(v20).m128_f32[0] * 256.0) + v40;
    v40 = v21;
    if ( v41 >= 0.0 )
      v22 = _mm_cvtsi32_si128(this->m_iMapExtents_YMax);
    else
      v22 = _mm_cvtsi32_si128(this->m_iMapExtents_YMin);
    v23 = (float)(_mm_cvtepi32_ps(v22).m128_f32[0] * 256.0) + v41;
    v41 = v23;
  }
  else
  {
    v24 = &v36;
    for ( i = 3; i != 0; --i )
    {
      CurrentRoomOffset = VMFExporter::GetCurrentRoomOffset(this);
      *(v24 - 2) = CurrentRoomOffset->x + *(v24 - 2);
      *(v24 - 1) = CurrentRoomOffset->y + *(v24 - 1);
      *v24 = CurrentRoomOffset->z + *v24;
      v24 += 3;
    }
    v27 = VMFExporter::GetCurrentRoomOffset(this);
    v23 = v41;
    this->m_vecLastPlaneOffset.x = v27->x;
    v21 = v40;
    v19 = v38;
    this->m_vecLastPlaneOffset.y = v27->y;
    v17 = v37;
    v15 = *(float *)strValue;
    this->m_vecLastPlaneOffset.z = v27->z;
    v13 = v34;
  }
  V_snprintf(
    pDest: &v28[4],
    maxLen: 256,
    pFormat: "(%f %f %f) (%f %f %f) (%f %f %f)",
    v13,
    v15,
    v36,
    v17,
    v19,
    v39,
    v21,
    v23,
    v42);
  KeyValues::SetStringValue(this: pKey, strValue: &v28[4]);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000B750
// Name: public: int VMFExporter::MakeNodeIDsUnique(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall VMFExporter::MakeNodeIDsUnique(VMFExporter *this)
{
  KeyValues *m_pTemplateKeys; // esi
  int result; // eax
  const char *Name; // eax
  KeyValues *FirstSubKey; // edi
  const char *v6; // eax
  VMFExporter::NodeTranslation_t *v7; // esi
  const char *String; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  VMFExporter::NodeTranslation_t **m_pMemory; // ecx
  int v12; // eax
  VMFExporter::NodeTranslation_t **v13; // edi
  char buffer[16]; // [esp+8h] [ebp-20h] BYREF
  VMFExporter::NodeTranslation_t *pNodeTranslation; // [esp+18h] [ebp-10h]
  int iNodes; // [esp+1Ch] [ebp-Ch]
  KeyValues *pKeys; // [esp+20h] [ebp-8h]
  KeyValues *pFieldKey; // [esp+24h] [ebp-4h]

  m_pTemplateKeys = this->m_pTemplateKeys;
  result = 0;
  iNodes = 0;
  pKeys = m_pTemplateKeys;
  if ( m_pTemplateKeys != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: m_pTemplateKeys);
      if ( _V_stricmp(s1: Name, s2: "entity") == 0 )
      {
        FirstSubKey = KeyValues::GetFirstSubKey(this: m_pTemplateKeys);
        pFieldKey = FirstSubKey;
        if ( FirstSubKey != nullptr )
        {
          while ( 1 )
          {
            if ( KeyValues::GetFirstSubKey(this: FirstSubKey) == nullptr )
            {
              v6 = KeyValues::GetName(this: FirstSubKey);
              if ( _V_stricmp(s1: v6, s2: "nodeid") == 0 )
              {
                v7 = (VMFExporter::NodeTranslation_t *)operator new(nSize: 8u);
                pNodeTranslation = v7;
                String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: szDescription);
                v7->m_iOriginalNodeID = atoi(nptr: String);
                v7->m_iNewNodeID = this->m_iNextNodeID;
                m_Size = this->m_NodeTranslations.m_Size;
                m_nAllocationCount = this->m_NodeTranslations.m_Memory.m_nAllocationCount;
                if ( m_Size + 1 > m_nAllocationCount )
                  CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
                    this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_NodeTranslations,
                    num: m_Size - m_nAllocationCount + 1);
                ++this->m_NodeTranslations.m_Size;
                m_pMemory = this->m_NodeTranslations.m_Memory.m_pMemory;
                v12 = this->m_NodeTranslations.m_Size - m_Size - 1;
                this->m_NodeTranslations.m_pElements = m_pMemory;
                if ( v12 > 0 )
                  _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
                v13 = &this->m_NodeTranslations.m_Memory.m_pMemory[m_Size];
                if ( v13 != nullptr )
                  *v13 = pNodeTranslation;
                V_snprintf(pDest: buffer, maxLen: 16, pFormat: "%d", this->m_iNextNodeID);
                KeyValues::SetStringValue(this: pFieldKey, strValue: buffer);
                FirstSubKey = pFieldKey;
                m_pTemplateKeys = pKeys;
                ++this->m_iNextNodeID;
                ++iNodes;
              }
            }
            pFieldKey = KeyValues::GetNextKey(this: FirstSubKey);
            if ( pFieldKey == nullptr )
              break;
            FirstSubKey = pFieldKey;
          }
        }
      }
      pKeys = KeyValues::GetNextKey(this: m_pTemplateKeys);
      if ( pKeys == nullptr )
        break;
      m_pTemplateKeys = pKeys;
    }
    return iNodes;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000B940
// Name: public: bool VMFExporter::ProcessSide(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall VMFExporter::ProcessSide(VMFExporter *this, KeyValues *pSideKey)
{
  KeyValues *FirstSubKey; // esi
  const char *Name; // eax
  char v5; // al

  FirstSubKey = KeyValues::GetFirstSubKey(this: pSideKey);
  if ( FirstSubKey == nullptr )
    return 1;
  while ( 1 )
  {
    Name = KeyValues::GetName(this: FirstSubKey);
    v5 = _V_stricmp(s1: Name, s2: "dispinfo") != 0
       ? VMFExporter::ProcessSideKey(this, pKey: FirstSubKey)
       : VMFExporter::ProcessGenericRecursive(this, pKey: FirstSubKey);
    if ( v5 == 0 )
      break;
    FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
    if ( FirstSubKey == nullptr )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000B9B0
// Name: public: void VMFExporter::LoadUniqueKeyList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VMFExporter::LoadUniqueKeyList(VMFExporter *this)
{
  CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *p_m_UniqueKeys; // edi
  KeyValues *v3; // eax
  IBaseFileSystem *v4; // eax
  KeyValues *FirstSubKey; // ebx
  const char *Name; // eax
  const char *v7; // eax
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *m_pMemory; // esi
  int m_nAllocationCount; // eax
  UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int> *v10; // ecx
  int v11; // eax
  CUtlString *v12; // esi
  const char *v13; // eax
  const char *v14; // eax
  const char *v15; // eax
  CUtlString src; // [esp+Ch] [ebp-28h] BYREF
  CUtlString string; // [esp+1Ch] [ebp-18h] BYREF
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *p_m_NodeIDKeys; // [esp+2Ch] [ebp-8h]
  KeyValues *manifest; // [esp+30h] [ebp-4h]

  p_m_UniqueKeys = (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)&this->m_UniqueKeys;
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: &this->m_UniqueKeys);
  p_m_NodeIDKeys = &this->m_NodeIDKeys;
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: &this->m_NodeIDKeys);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    manifest = KeyValues::KeyValues(this: v3, setName: "unique_keys.txt");
  else
    manifest = nullptr;
  if ( g_pFullFileSystem != nullptr )
    v4 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v4 = nullptr;
  if ( !KeyValues::LoadFromFile(
          this: manifest,
          filesystem: v4,
          resourceName: "unique_keys.txt",
          pathID: "TILEGEN",
          pfnEvaluateSymbolProc: nullptr) )
  {
    _Warning(a1: "VMFExporter: Unable to load manifest file '%s'\n", "unique_keys.txt");
    goto LABEL_29;
  }
  FirstSubKey = KeyValues::GetFirstSubKey(this: manifest);
  if ( FirstSubKey == nullptr )
  {
LABEL_29:
    KeyValues::deleteThis(this: manifest);
    return;
  }
  do
  {
    Name = KeyValues::GetName(this: FirstSubKey);
    if ( _V_stricmp(s1: Name, s2: "key") != 0 )
    {
      v13 = KeyValues::GetName(this: FirstSubKey);
      if ( _V_stricmp(s1: v13, s2: "NodeID") != 0 )
      {
        v15 = KeyValues::GetName(this: FirstSubKey);
        _Warning(
          a1: "VMFExporter::LoadUniqueKeyList:  Manifest '%s' with bogus file type '%s', expecting 'key' or 'NodeID'\n",
          "unique_keys.txt",
          v15);
      }
      else
      {
        v14 = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: szDescription);
        CUtlString::CUtlString(this: &src, pString: v14);
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
          this: p_m_NodeIDKeys,
          elem: p_m_NodeIDKeys->m_Size,
          &src);
        src.m_Storage.m_nActualLength = 0;
        if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 )
        {
          if ( src.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
            src.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          src.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
      }
    }
    else
    {
      v7 = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: szDescription);
      CUtlString::CUtlString(this: &string, pString: v7);
      m_pMemory = p_m_UniqueKeys[1].m_pMemory;
      m_nAllocationCount = p_m_UniqueKeys->m_nAllocationCount;
      if ( (int)&m_pMemory->m_Element.panel + 1 > m_nAllocationCount )
        CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
          this: p_m_UniqueKeys,
          num: (int)&m_pMemory->m_Element.panel - m_nAllocationCount + 1);
      ++p_m_UniqueKeys[1].m_pMemory;
      v10 = p_m_UniqueKeys->m_pMemory;
      v11 = (char *)p_m_UniqueKeys[1].m_pMemory - (char *)m_pMemory - 1;
      p_m_UniqueKeys[1].m_nAllocationCount = (int)p_m_UniqueKeys->m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: &v10[(int)m_pMemory + 1], src: &v10[(_DWORD)m_pMemory], count: 16 * v11);
      v12 = (CUtlString *)&p_m_UniqueKeys->m_pMemory[(_DWORD)m_pMemory];
      if ( v12 != nullptr )
        CUtlString::CUtlString(this: v12, &string);
      string.m_Storage.m_nActualLength = 0;
      if ( string.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( string.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: string.m_Storage.m_Memory.m_pMemory);
          string.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        string.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
    }
    FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
  }
  while ( FirstSubKey != nullptr );
  KeyValues::deleteThis(this: manifest);
}

//------------------------------------------------------------------------------
// Address: 0x1000BC20
// Name: public: VMFExporter::VMFExporter(void)
// Source: json
//------------------------------------------------------------------------------
VMFExporter *__thiscall VMFExporter::VMFExporter(VMFExporter *this)
{
  this->__vftable = (VMFExporter_vtbl *)&VMFExporter::`vftable';
  this->m_UniqueKeys.m_Memory.m_pMemory = nullptr;
  this->m_UniqueKeys.m_Memory.m_nAllocationCount = 0;
  this->m_UniqueKeys.m_Memory.m_nGrowSize = 0;
  this->m_UniqueKeys.m_Size = 0;
  this->m_UniqueKeys.m_pElements = nullptr;
  this->m_NodeIDKeys.m_Memory.m_pMemory = nullptr;
  this->m_NodeIDKeys.m_Memory.m_nAllocationCount = 0;
  this->m_NodeIDKeys.m_Memory.m_nGrowSize = 0;
  this->m_NodeIDKeys.m_Size = 0;
  this->m_NodeIDKeys.m_pElements = nullptr;
  this->m_SideTranslations.m_Memory.m_pMemory = nullptr;
  this->m_SideTranslations.m_Memory.m_nAllocationCount = 0;
  this->m_SideTranslations.m_Memory.m_nGrowSize = 0;
  this->m_SideTranslations.m_Size = 0;
  this->m_SideTranslations.m_pElements = nullptr;
  this->m_NodeTranslations.m_Memory.m_pMemory = nullptr;
  this->m_NodeTranslations.m_Memory.m_nAllocationCount = 0;
  this->m_NodeTranslations.m_Memory.m_nGrowSize = 0;
  this->m_NodeTranslations.m_Size = 0;
  this->m_NodeTranslations.m_pElements = nullptr;
  this->m_ExportErrors.m_Memory.m_pMemory = nullptr;
  this->m_ExportErrors.m_Memory.m_nAllocationCount = 0;
  this->m_ExportErrors.m_Memory.m_nGrowSize = 0;
  this->m_ExportErrors.m_Size = 0;
  this->m_ExportErrors.m_pElements = nullptr;
  this->m_pMapLayout = nullptr;
  VMFExporter::Init(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000BCC0
// Name: public: bool VMFExporter::ProcessSolid(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall VMFExporter::ProcessSolid(VMFExporter *this, KeyValues *pSolidKey)
{
  KeyValues *FirstSubKey; // esi
  const char *Name; // eax
  char v5; // al

  KeyValues::SetInt(this: pSolidKey, keyName: "id", value: ++this->m_iEntityCount);
  FirstSubKey = KeyValues::GetFirstSubKey(this: pSolidKey);
  if ( FirstSubKey == nullptr )
    return 1;
  while ( 1 )
  {
    Name = KeyValues::GetName(this: FirstSubKey);
    v5 = _V_stricmp(s1: Name, s2: "side") != 0
       ? VMFExporter::ProcessGenericRecursive(this, pKey: FirstSubKey)
       : VMFExporter::ProcessSide(this, pSideKey: FirstSubKey);
    if ( v5 == 0 )
      break;
    FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
    if ( FirstSubKey == nullptr )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000BD40
// Name: public: bool VMFExporter::ProcessEntity(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall VMFExporter::ProcessEntity(VMFExporter *this, KeyValues *pEntityKeys)
{
  KeyValues *FirstSubKey; // esi
  const char *Name; // eax
  char v5; // al
  const char *v6; // eax
  const char *v7; // eax
  KeyValues *v8; // edi
  KeyValues *v10; // [esp-4h] [ebp-10h]

  FirstSubKey = KeyValues::GetFirstSubKey(this: pEntityKeys);
  if ( FirstSubKey == nullptr )
    return 1;
  while ( KeyValues::GetFirstSubKey(this: FirstSubKey) != nullptr )
  {
    Name = KeyValues::GetName(this: FirstSubKey);
    if ( _V_stricmp(s1: Name, s2: "solid") == 0 )
    {
      v5 = VMFExporter::ProcessSolid(this, pSolidKey: FirstSubKey);
      goto LABEL_10;
    }
    v6 = KeyValues::GetName(this: FirstSubKey);
    if ( _V_stricmp(s1: v6, s2: "connections") == 0 )
    {
      v5 = VMFExporter::ProcessConnections(this, pConnections: FirstSubKey);
      goto LABEL_10;
    }
    v7 = KeyValues::GetName(this: FirstSubKey);
    if ( _V_stricmp(s1: v7, s2: "editor") != 0 )
      goto LABEL_11;
    v8 = FirstSubKey;
    v10 = FirstSubKey;
    FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
    KeyValues::RemoveSubKey(this: pEntityKeys, subKey: v10);
    KeyValues::deleteThis(this: v8);
LABEL_12:
    if ( FirstSubKey == nullptr )
      return 1;
  }
  v5 = VMFExporter::ProcessEntityKey(this, pKey: FirstSubKey);
LABEL_10:
  if ( v5 != 0 )
  {
LABEL_11:
    FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
    goto LABEL_12;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000BE80
// Name: public: bool VMFExporter::AddRoomTemplateEntities(class CRoomTemplate const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall VMFExporter::AddRoomTemplateEntities(VMFExporter *this, const CRoomTemplate *pRoomTemplate)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  IBaseFileSystem *v5; // ecx
  KeyValues *m_pTemplateKeys; // edi
  const char *Name; // eax
  KeyValues *Copy; // eax
  char roomvmfname[260]; // [esp+Ch] [ebp-104h] BYREF

  CUtlVector<VMFExporter::SideTranslation_t *,CUtlMemory<VMFExporter::SideTranslation_t *,int>>::PurgeAndDeleteElements(this: (CUtlVector<char *,CUtlMemory<char *,int> > *)&this->m_SideTranslations);
  CUtlVector<VMFExporter::SideTranslation_t *,CUtlMemory<VMFExporter::SideTranslation_t *,int>>::PurgeAndDeleteElements(this: (CUtlVector<char *,CUtlMemory<char *,int> > *)&this->m_NodeTranslations);
  V_snprintf(
    pDest: roomvmfname,
    maxLen: 260,
    pFormat: "tilegen/roomtemplates/%s/%s.vmf",
    pRoomTemplate->m_pLevelTheme->m_szName,
    pRoomTemplate->m_FullName);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "RoomTemplateVMF");
  else
    v4 = nullptr;
  this->m_pTemplateKeys = v4;
  if ( g_pFullFileSystem != nullptr )
    v5 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v5 = nullptr;
  KeyValues::LoadFromFile(
    this: v4,
    filesystem: v5,
    resourceName: roomvmfname,
    pathID: "GAME",
    pfnEvaluateSymbolProc: nullptr);
  VMFExporter::MakeNodeIDsUnique(this);
  VMFExporter::ReorderObjectives(this, pTemplate: pRoomTemplate, pTemplateKeys: this->m_pTemplateKeys);
  m_pTemplateKeys = this->m_pTemplateKeys;
  if ( m_pTemplateKeys == nullptr )
  {
LABEL_12:
    KeyValues::deleteThis(this: this->m_pTemplateKeys);
    this->m_pTemplateKeys = nullptr;
    return 1;
  }
  while ( 1 )
  {
    Name = KeyValues::GetName(this: m_pTemplateKeys);
    if ( _V_stricmp(s1: Name, s2: "entity") == 0 )
      break;
LABEL_11:
    m_pTemplateKeys = KeyValues::GetNextKey(this: m_pTemplateKeys);
    if ( m_pTemplateKeys == nullptr )
      goto LABEL_12;
  }
  if ( VMFExporter::ProcessEntity(this, pEntityKeys: m_pTemplateKeys) != 0 )
  {
    Copy = KeyValues::MakeCopy(this: m_pTemplateKeys);
    KeyValues::AddSubKey(this: this->m_pExportKeys, pSubkey: Copy);
    goto LABEL_11;
  }
  V_snprintf(
    pDest: this->m_szLastExporterError,
    maxLen: 256,
    pFormat: "Failed to copy entity from room %s\n",
    pRoomTemplate->m_FullName);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000BFB0
// Name: public: bool VMFExporter::ProcessWorld(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall VMFExporter::ProcessWorld(VMFExporter *this, KeyValues *pWorldKeys)
{
  KeyValues *FirstSubKey; // ebx
  const char *Name; // eax
  KeyValues *NextKey; // esi
  const char *v6; // eax
  char v7; // al

  FirstSubKey = KeyValues::GetFirstSubKey(this: pWorldKeys);
  if ( FirstSubKey == nullptr )
    return 1;
  while ( 1 )
  {
    Name = KeyValues::GetName(this: FirstSubKey);
    if ( _V_stricmp(s1: Name, s2: "solid") == 0 )
    {
      KeyValues::SetInt(this: FirstSubKey, keyName: "id", value: ++this->m_iEntityCount);
      NextKey = KeyValues::GetFirstSubKey(this: FirstSubKey);
      if ( NextKey != nullptr )
        break;
    }
LABEL_9:
    FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
    if ( FirstSubKey == nullptr )
      return 1;
  }
  while ( 1 )
  {
    v6 = KeyValues::GetName(this: NextKey);
    v7 = _V_stricmp(s1: v6, s2: "side") != 0
       ? VMFExporter::ProcessGenericRecursive(this, pKey: NextKey)
       : VMFExporter::ProcessSide(this, pSideKey: NextKey);
    if ( v7 == 0 )
      return 0;
    NextKey = KeyValues::GetNextKey(this: NextKey);
    if ( NextKey == nullptr )
      goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C070
// Name: public: bool VMFExporter::AddLevelContainer(void)
// Source: json
//------------------------------------------------------------------------------
bool __usercall VMFExporter::AddLevelContainer@<al>(
        VMFExporter *this@<ecx>,
        unsigned int a2@<ebx>,
        unsigned int a3@<edi>)
{
  KeyValues *v4; // eax
  IBaseFileSystem *v5; // eax
  bool result; // al
  CMapLayout *m_pMapLayout; // ecx
  int m_iMapExtents_YMax; // edi
  int m_iMapExtents_XMax; // ecx
  int m_iMapExtents_YMin; // ebx
  KeyValues *NextKey; // edi
  const char *Name; // eax
  KeyValues *i; // edi
  const char *v14; // eax
  KeyValues *Copy; // eax
  double v16; // [esp+0h] [ebp-8h]
  KeyValues *pLevelContainerKeys; // [esp+4h] [ebp-4h]

  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    HIDWORD(v16) = KeyValues::KeyValues(this: v4, setName: "LevelContainer");
  else
    HIDWORD(v16) = 0;
  if ( g_pFullFileSystem != nullptr )
    v5 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v5 = nullptr;
  result = KeyValues::LoadFromFile(
             this: (KeyValues *)HIDWORD(v16),
             filesystem: v5,
             resourceName: "tilegen/roomtemplates/levelcontainer.vmf.no_func_detail",
             pathID: "GAME",
             pfnEvaluateSymbolProc: nullptr);
  if ( result )
  {
    m_pMapLayout = this->m_pMapLayout;
    this->m_bWritingLevelContainer = true;
    CMapLayout::GetExtents(
      this: m_pMapLayout,
      iTileX_Min: &this->m_iMapExtents_XMin,
      iTileX_Max: &this->m_iMapExtents_XMax,
      iTileY_Min: &this->m_iMapExtents_YMin,
      iTileY_Max: &this->m_iMapExtents_YMax);
    _Msg(
      a1: "Layout extents: Topleft: %f %f - Lower right: %f %f\n",
      *(double *)&this->m_iMapExtents_XMin,
      *(double *)&this->m_iMapExtents_XMax,
      COERCE_DOUBLE(__PAIR64__(a2, a3)),
      v16);
    this->m_iMapExtents_YMax -= 58;
    m_iMapExtents_YMax = this->m_iMapExtents_YMax;
    this->m_iMapExtents_XMax -= 58;
    m_iMapExtents_XMax = this->m_iMapExtents_XMax;
    this->m_iMapExtents_YMin -= 62;
    m_iMapExtents_YMin = this->m_iMapExtents_YMin;
    this->m_iMapExtents_XMin -= 62;
    _Msg(
      a1: "   Adjusted to: Topleft: %d %d - Lower right: %d %d\n",
      this->m_iMapExtents_XMin,
      m_iMapExtents_YMin,
      m_iMapExtents_XMax,
      m_iMapExtents_YMax);
    NextKey = pLevelContainerKeys;
    if ( pLevelContainerKeys == nullptr )
      goto LABEL_11;
    while ( 1 )
    {
      Name = KeyValues::GetName(this: NextKey);
      if ( _V_stricmp(s1: Name, s2: "world") == 0 )
        break;
      NextKey = KeyValues::GetNextKey(this: NextKey);
      if ( NextKey == nullptr )
        goto LABEL_11;
    }
    if ( NextKey != nullptr && VMFExporter::ProcessWorld(this, pWorldKeys: NextKey) != 0 )
    {
      this->m_bWritingLevelContainer = false;
      for ( i = KeyValues::GetFirstSubKey(this: NextKey); i != nullptr; i = KeyValues::GetNextKey(this: i) )
      {
        v14 = KeyValues::GetName(this: i);
        if ( _V_stricmp(s1: v14, s2: "solid") == 0 )
        {
          Copy = KeyValues::MakeCopy(this: i);
          KeyValues::AddSubKey(this: this->m_pExportWorldKeys, pSubkey: Copy);
        }
      }
      KeyValues::deleteThis(this: pLevelContainerKeys);
      KeyValues::deleteThis(this: this->m_pTemplateKeys);
      this->m_pTemplateKeys = nullptr;
      return true;
    }
    else
    {
LABEL_11:
      V_snprintf(pDest: this->m_szLastExporterError, maxLen: 256, pFormat: "Failed to copy level container\n");
      return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000C200
// Name: public: bool VMFExporter::AddRoomTemplateSolids(class CRoomTemplate const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall VMFExporter::AddRoomTemplateSolids(VMFExporter *this, KeyValues *pRoomTemplate)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  IBaseFileSystem *v5; // ecx
  KeyValues *m_pTemplateKeys; // esi
  const char *Name; // eax
  KeyValues *i; // ebx
  const char *v10; // eax
  KeyValues *Copy; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // esi
  KeyValues *v14; // eax
  CLevelTheme *m_pPeer; // [esp-8h] [ebp-11Ch]
  char roomvmfname[260]; // [esp+Ch] [ebp-108h] BYREF
  char *p_m_pChain; // [esp+110h] [ebp-4h]
  KeyValues *pKeys; // [esp+11Ch] [ebp+8h]

  m_pPeer = (CLevelTheme *)pRoomTemplate->m_pPeer;
  p_m_pChain = (char *)&pRoomTemplate[15].m_pChain;
  V_snprintf(
    pDest: roomvmfname,
    maxLen: 260,
    pFormat: "tilegen/roomtemplates/%s/%s.vmf",
    m_pPeer->m_szName,
    (const char *)&pRoomTemplate[15].m_pChain);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "RoomTemplateVMF");
  else
    v4 = nullptr;
  this->m_pTemplateKeys = v4;
  if ( g_pFullFileSystem != nullptr )
    v5 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v5 = nullptr;
  KeyValues::LoadFromFile(
    this: v4,
    filesystem: v5,
    resourceName: roomvmfname,
    pathID: "GAME",
    pfnEvaluateSymbolProc: nullptr);
  m_pTemplateKeys = this->m_pTemplateKeys;
  pKeys = m_pTemplateKeys;
  if ( m_pTemplateKeys == nullptr )
  {
LABEL_8:
    KeyValues::deleteThis(this: this->m_pTemplateKeys);
    this->m_pTemplateKeys = nullptr;
    return 1;
  }
  while ( 1 )
  {
    Name = KeyValues::GetName(this: m_pTemplateKeys);
    if ( _V_stricmp(s1: Name, s2: "world") != 0 )
      goto LABEL_21;
    if ( VMFExporter::ProcessWorld(this, pWorldKeys: m_pTemplateKeys) == 0 )
      break;
    for ( i = KeyValues::GetFirstSubKey(this: m_pTemplateKeys); i != nullptr; i = KeyValues::GetNextKey(this: i) )
    {
      v10 = KeyValues::GetName(this: i);
      if ( _V_stricmp(s1: v10, s2: "solid") == 0 )
      {
        if ( VMFExporter::IsDisplacementBrush(this, pSolidKeys: i) != 0 )
        {
          Copy = KeyValues::MakeCopy(this: i);
          KeyValues::AddSubKey(this: this->m_pExportWorldKeys, pSubkey: Copy);
        }
        else
        {
          v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v12 != nullptr )
            v13 = KeyValues::KeyValues(this: v12, setName: "entity");
          else
            v13 = nullptr;
          KeyValues::SetInt(this: v13, keyName: "id", value: ++this->m_iEntityCount);
          KeyValues::SetString(this: v13, keyName: "classname", value: "func_detail");
          v14 = KeyValues::MakeCopy(this: i);
          KeyValues::AddSubKey(this: v13, pSubkey: v14);
          KeyValues::AddSubKey(this: this->m_pExportKeys, pSubkey: v13);
          m_pTemplateKeys = pKeys;
        }
      }
    }
LABEL_21:
    pKeys = KeyValues::GetNextKey(this: m_pTemplateKeys);
    if ( pKeys == nullptr )
      goto LABEL_8;
    m_pTemplateKeys = pKeys;
  }
  V_snprintf(
    pDest: this->m_szLastExporterError,
    maxLen: 256,
    pFormat: "Failed to copy world from room %s\n",
    p_m_pChain);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000C3D0
// Name: public: bool VMFExporter::ExportVMF(class CMapLayout __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall VMFExporter::ExportVMF(
        VMFExporter *this,
        CMapLayout *pLayout,
        const char *mapname,
        bool bPopupWarnings)
{
  int v6; // edi
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  KeyValues *VersionInfo; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // edi
  KeyValues *DefaultWorldChunk; // eax
  CMapLayout *m_pMapLayout; // eax
  int m_Size; // ebx
  int v17; // edi
  int i; // edi
  CRoom *v19; // eax
  int v20; // ebx
  int v21; // edi
  CMapLayout *v22; // eax
  CRoomTemplate **m_pMemory; // ecx
  int v24; // eax
  CRoom *v25; // eax
  KeyValues *m_pRoomTemplate; // eax
  int v27; // edi
  CMapLayout *v28; // ecx
  CRoomTemplate **v29; // edx
  CRoom *v30; // eax
  const CRoomTemplate *v31; // eax
  KeyValues *PlayerStarts; // eax
  KeyValues *GameRulesProxy; // eax
  KeyValues *DefaultCamera; // eax
  KeyValues *j; // edi
  char filename[512]; // [esp+8h] [ebp-230h] BYREF
  CUtlBuffer buf; // [esp+208h] [ebp-30h] BYREF
  int iRooms; // [esp+240h] [ebp+8h]
  int iRoomsa; // [esp+240h] [ebp+8h]
  bool bHasStartRoom; // [esp+24Bh] [ebp+13h]

  this->m_bPopupWarnings = bPopupWarnings;
  VMFExporter::Init(this);
  this->m_pMapLayout = pLayout;
  if ( pLayout->m_PlacedRooms.m_Size <= 0 )
  {
    V_snprintf(
      pDest: this->m_szLastExporterError,
      maxLen: 256,
      pFormat: "Failed to export: No rooms placed in the map layout!\n");
    return 0;
  }
  v6 = 0;
  bHasStartRoom = false;
  while ( !CRoomTemplate::IsStartRoom(this: (CRoomTemplate *)pLayout->m_PlacedRooms.m_Memory.m_pMemory[v6]->m_pRoomTemplate) )
  {
    if ( ++v6 >= pLayout->m_PlacedRooms.m_Size )
      goto LABEL_8;
  }
  this->m_vecStartRoomOrigin.x = (float)(pLayout->m_PlacedRooms.m_Memory.m_pMemory[v6]->m_iPosX - 60) * 256.0;
  this->m_vecStartRoomOrigin.y = (float)(pLayout->m_PlacedRooms.m_Memory.m_pMemory[v6]->m_iPosY - 60) * 256.0;
  bHasStartRoom = true;
LABEL_8:
  VMFExporter::LoadUniqueKeyList(this);
  this->m_iNextNodeID = 0;
  v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v7 != nullptr )
    v8 = KeyValues::KeyValues(this: v7, setName: "ExportKeys");
  else
    v8 = nullptr;
  this->m_pExportKeys = v8;
  VersionInfo = VMFExporter::GetVersionInfo(this);
  KeyValues::AddSubKey(this: this->m_pExportKeys, pSubkey: VersionInfo);
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 != nullptr )
    v11 = KeyValues::KeyValues(this: v10, setName: "visgroups");
  else
    v11 = nullptr;
  KeyValues::AddSubKey(this: this->m_pExportKeys, pSubkey: v11);
  v12 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v12 != nullptr )
    v13 = KeyValues::KeyValues(this: v12, setName: "viewsettings");
  else
    v13 = nullptr;
  KeyValues::SetInt(this: v13, keyName: "bSnapToGrid", value: 1);
  KeyValues::SetInt(this: v13, keyName: "bShowGrid", value: 1);
  KeyValues::SetInt(this: v13, keyName: "bShowLogicalGrid", value: 0);
  KeyValues::SetInt(this: v13, keyName: "nGridSpacing", value: 256);
  KeyValues::SetInt(this: v13, keyName: "bShow3DGrid", value: 0);
  KeyValues::AddSubKey(this: this->m_pExportKeys, pSubkey: v13);
  DefaultWorldChunk = VMFExporter::GetDefaultWorldChunk(this);
  this->m_pExportWorldKeys = DefaultWorldChunk;
  if ( DefaultWorldChunk == nullptr )
  {
    V_snprintf(pDest: this->m_szLastExporterError, maxLen: 256, pFormat: "Failed to save world chunk start\n");
    return 0;
  }
  KeyValues::AddSubKey(this: this->m_pExportKeys, pSubkey: DefaultWorldChunk);
  if ( !VMFExporter::AddLevelContainer(this, a2: (unsigned int)pLayout, a3: (unsigned int)v13) )
  {
    V_snprintf(pDest: this->m_szLastExporterError, maxLen: 256, pFormat: "Failed to save level container\n");
    return 0;
  }
  if ( tilegen_use_instancing.m_pParent != nullptr && tilegen_use_instancing.m_pParent->m_Value.m_nValue != 0 )
  {
    m_pMapLayout = this->m_pMapLayout;
    m_Size = m_pMapLayout->m_LogicalRooms.m_Size;
    v17 = 0;
    iRooms = m_pMapLayout->m_PlacedRooms.m_Size;
    for ( this->m_pRoom = nullptr; v17 < m_Size; ++v17 )
      VMFExporter::AddRoomInstance(
        this,
        pRoomTemplate: this->m_pMapLayout->m_LogicalRooms.m_Memory.m_pMemory[v17],
        nPlacedRoomIndex: -1);
    for ( i = 0; i < iRooms; ++i )
    {
      v19 = this->m_pMapLayout->m_PlacedRooms.m_Memory.m_pMemory[i];
      this->m_pRoom = v19;
      VMFExporter::AddRoomInstance(this, pRoomTemplate: v19->m_pRoomTemplate, nPlacedRoomIndex: i);
    }
  }
  else
  {
    v20 = this->m_pMapLayout->m_LogicalRooms.m_Size;
    v21 = 0;
    this->m_pRoom = nullptr;
    if ( v20 > 0 )
    {
      do
      {
        v22 = this->m_pMapLayout;
        this->m_iCurrentRoom = v21 + 5000;
        m_pMemory = v22->m_LogicalRooms.m_Memory.m_pMemory;
        if ( m_pMemory[v21] != nullptr
          && VMFExporter::AddRoomTemplateSolids(this, pRoomTemplate: (KeyValues *)m_pMemory[v21]) == 0 )
        {
          return 0;
        }
      }
      while ( ++v21 < v20 );
    }
    iRoomsa = this->m_pMapLayout->m_PlacedRooms.m_Size;
    v24 = iRoomsa;
    this->m_iCurrentRoom = 0;
    if ( iRoomsa > 0 )
    {
      do
      {
        v25 = this->m_pMapLayout->m_PlacedRooms.m_Memory.m_pMemory[this->m_iCurrentRoom];
        this->m_pRoom = v25;
        if ( v25 != nullptr )
        {
          m_pRoomTemplate = (KeyValues *)v25->m_pRoomTemplate;
          if ( m_pRoomTemplate != nullptr
            && VMFExporter::AddRoomTemplateSolids(this, pRoomTemplate: m_pRoomTemplate) == 0 )
          {
            return 0;
          }
        }
        v24 = iRoomsa;
      }
      while ( ++this->m_iCurrentRoom < iRoomsa );
    }
    v27 = 0;
    this->m_pRoom = nullptr;
    if ( v20 > 0 )
    {
      while ( 1 )
      {
        v28 = this->m_pMapLayout;
        this->m_iCurrentRoom = v27 + 5000;
        v29 = v28->m_LogicalRooms.m_Memory.m_pMemory;
        if ( v29[v27] != nullptr && VMFExporter::AddRoomTemplateEntities(this, pRoomTemplate: v29[v27]) == 0 )
          return 0;
        if ( ++v27 >= v20 )
        {
          v24 = iRoomsa;
          break;
        }
      }
    }
    this->m_iCurrentRoom = 0;
    if ( v24 > 0 )
    {
      do
      {
        v30 = this->m_pMapLayout->m_PlacedRooms.m_Memory.m_pMemory[this->m_iCurrentRoom];
        this->m_pRoom = v30;
        if ( v30 != nullptr )
        {
          v31 = v30->m_pRoomTemplate;
          if ( v31 != nullptr && VMFExporter::AddRoomTemplateEntities(this, pRoomTemplate: v31) == 0 )
            return 0;
        }
      }
      while ( ++this->m_iCurrentRoom < iRoomsa );
    }
  }
  if ( !bHasStartRoom )
  {
    PlayerStarts = VMFExporter::GetPlayerStarts(this);
    KeyValues::AddSubKey(this: this->m_pExportKeys, pSubkey: PlayerStarts);
  }
  GameRulesProxy = VMFExporter::GetGameRulesProxy(this);
  KeyValues::AddSubKey(this: this->m_pExportKeys, pSubkey: GameRulesProxy);
  DefaultCamera = VMFExporter::GetDefaultCamera(this);
  KeyValues::AddSubKey(this: this->m_pExportKeys, pSubkey: DefaultCamera);
  V_snprintf(pDest: filename, maxLen: 512, pFormat: "maps\\%s", mapname);
  V_SetExtension(path: filename, extension: "vmf", pathStringLength: 512);
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  for ( j = KeyValues::GetFirstSubKey(this: this->m_pExportKeys); j != nullptr; j = KeyValues::GetNextKey(this: j) )
    KeyValues::RecursiveSaveToFile(this: j, &buf, indentLevel: 0);
  if ( !g_pFullFileSystem->WriteFile(this: &g_pFullFileSystem->IBaseFileSystem, a2: filename, a3: "GAME", a4: &buf) )
  {
    _Msg(a1: "Failed to SaveToFile %s\n", filename);
    goto LABEL_56;
  }
  V_snprintf(pDest: filename, maxLen: 512, pFormat: "maps\\%s", mapname);
  V_SetExtension(path: filename, extension: "layout", pathStringLength: 512);
  if ( !CMapLayout::SaveMapLayout(this: this->m_pMapLayout, filename) )
  {
    V_snprintf(pDest: this->m_szLastExporterError, maxLen: 256, pFormat: "Failed to save .layout file\n");
LABEL_56:
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    return 0;
  }
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  return 1;
}
