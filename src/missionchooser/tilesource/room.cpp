// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/tilesource/room.cpp
// Functions: 20
// ============================================================

#include "missionchooser\tilesource\room.h"

//------------------------------------------------------------------------------
// Address: 0x100268E0
// Name: public: CRoom::CRoom(class CMapLayout __near *,class CRoomTemplate const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
CRoom *__thiscall CRoom::CRoom(
        CRoom *this,
        CMapLayout *pMapLayout,
        const CRoomTemplate *pRoomTemplate,
        int TileX,
        int TileY)
{
  this->m_iPosX = TileX;
  this->__vftable = (CRoom_vtbl *)&CRoom::`vftable';
  this->m_pRoomTemplate = pRoomTemplate;
  this->m_iPosY = TileY;
  this->m_iNumChildren = 0;
  this->m_bHasAlienEncounter = false;
  CMapLayout::PlaceRoom(this: pMapLayout, pRoom: this);
  this->m_pPlacedRoomPanel = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10026920
// Name: public: virtual bool CRoom::HasAlienEncounter(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CRoom::HasAlienEncounter(CRoom *this)
{
  return this->m_bHasAlienEncounter;
}

//------------------------------------------------------------------------------
// Address: 0x10026930
// Name: public: class KeyValues __near * CRoom::GetKeyValuesCopy(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CRoom::GetKeyValuesCopy(CRoom *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "room");
  else
    v3 = nullptr;
  KeyValues::SetInt(this: v3, keyName: "posx", value: this->m_iPosX);
  KeyValues::SetInt(this: v3, keyName: "posy", value: this->m_iPosY);
  KeyValues::SetString(this: v3, keyName: "theme", value: this->m_pRoomTemplate->m_pLevelTheme->m_szName);
  KeyValues::SetString(this: v3, keyName: "template", value: this->m_pRoomTemplate->m_FullName);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100269B0
// Name: public: virtual bool CRoom::HasTag(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CRoom::HasTag(CRoom *this, const char *szTag)
{
  CRoomTemplate *m_pRoomTemplate; // ecx

  m_pRoomTemplate = (CRoomTemplate *)this->m_pRoomTemplate;
  return m_pRoomTemplate != nullptr && CRoomTemplate::HasTag(this: m_pRoomTemplate, szTag);
}

//------------------------------------------------------------------------------
// Address: 0x100269D0
// Name: public: virtual int CRoom::GetSpawnWeight(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRoom::GetSpawnWeight(CRoom *this)
{
  const CRoomTemplate *m_pRoomTemplate; // eax

  m_pRoomTemplate = this->m_pRoomTemplate;
  if ( m_pRoomTemplate != nullptr )
    return m_pRoomTemplate->m_nSpawnWeight;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100269E0
// Name: public: virtual bool CRoom::GetThumbnailName(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRoom::GetThumbnailName(CRoom *this, char *szOut, int iBufferSize)
{
  const CRoomTemplate *m_pRoomTemplate; // eax

  m_pRoomTemplate = this->m_pRoomTemplate;
  if ( m_pRoomTemplate == nullptr || m_pRoomTemplate->m_pLevelTheme == nullptr )
    return 0;
  V_snprintf(
    pDest: szOut,
    maxLen: iBufferSize,
    pFormat: "tilegen/roomtemplates/%s/%s.tga",
    m_pRoomTemplate->m_pLevelTheme->m_szName,
    m_pRoomTemplate->m_FullName);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10026A20
// Name: public: virtual bool CRoom::GetFullRoomName(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRoom::GetFullRoomName(CRoom *this, char *szOut, int iBufferSize)
{
  const CRoomTemplate *m_pRoomTemplate; // eax

  m_pRoomTemplate = this->m_pRoomTemplate;
  if ( m_pRoomTemplate == nullptr || m_pRoomTemplate->m_pLevelTheme == nullptr )
    return 0;
  V_snprintf(
    pDest: szOut,
    maxLen: iBufferSize,
    pFormat: "%s\\%s",
    m_pRoomTemplate->m_pLevelTheme->m_szName,
    m_pRoomTemplate->m_FullName);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10026A60
// Name: public: virtual void CRoom::GetSoundscape(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRoom::GetSoundscape(CRoom *this, char *szOut, int iBufferSize)
{
  const CRoomTemplate *m_pRoomTemplate; // eax
  const char *m_Soundscape; // eax

  m_pRoomTemplate = this->m_pRoomTemplate;
  if ( m_pRoomTemplate != nullptr )
    m_Soundscape = m_pRoomTemplate->m_Soundscape;
  else
    m_Soundscape = szDescription;
  V_snprintf(pDest: szOut, maxLen: iBufferSize, pFormat: "%s", m_Soundscape);
}

//------------------------------------------------------------------------------
// Address: 0x10026A90
// Name: public: virtual void CRoom::GetTheme(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRoom::GetTheme(CRoom *this, char *szOut, int iBufferSize)
{
  const CRoomTemplate *m_pRoomTemplate; // eax
  const char *m_szName; // eax

  m_pRoomTemplate = this->m_pRoomTemplate;
  if ( m_pRoomTemplate == nullptr || (m_szName = m_pRoomTemplate->m_pLevelTheme->m_szName) == nullptr )
    m_szName = szDescription;
  V_snprintf(pDest: szOut, maxLen: iBufferSize, pFormat: "%s", m_szName);
}

//------------------------------------------------------------------------------
// Address: 0x10026AC0
// Name: public: virtual class Vector const __near & CRoom::GetAmbientLight(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CRoom::GetAmbientLight(CRoom *this)
{
  const CRoomTemplate *m_pRoomTemplate; // eax
  CLevelTheme *m_pLevelTheme; // eax

  m_pRoomTemplate = this->m_pRoomTemplate;
  if ( m_pRoomTemplate != nullptr && (m_pLevelTheme = m_pRoomTemplate->m_pLevelTheme) != nullptr )
    return &m_pLevelTheme->m_vecAmbientLight;
  else
    return &vec3_origin;
}

//------------------------------------------------------------------------------
// Address: 0x10026AE0
// Name: public: virtual int CRoom::GetTileType(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRoom::GetTileType(CRoom *this)
{
  const CRoomTemplate *m_pRoomTemplate; // eax

  m_pRoomTemplate = this->m_pRoomTemplate;
  if ( m_pRoomTemplate != nullptr )
    return m_pRoomTemplate->m_nTileType;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10026B00
// Name: public: virtual char const __near * CRoom::GetTileTypeName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CRoom::GetTileTypeName(CRoom *this, int nType)
{
  if ( nType == -1 )
    return nullptr;
  else
    return g_szASWTileTypeStrings_13[nType];
}

//------------------------------------------------------------------------------
// Address: 0x10026B20
// Name: public: virtual void CRoom::GetWorldBounds(class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRoom::GetWorldBounds(CRoom *this, Vector *vecWorldMins, Vector *vecWorldMaxs)
{
  int v3; // edx
  float v4; // xmm1_4

  if ( this->m_pRoomTemplate != nullptr )
  {
    v3 = (int)(float)((float)(this->m_iPosY - 60) * 256.0);
    v4 = (float)(int)(float)((float)(this->m_iPosX - 60) * 256.0);
    vecWorldMins->x = v4;
    vecWorldMins->z = 0.0;
    vecWorldMins->y = (float)v3;
    vecWorldMaxs->x = (float)((float)this->m_pRoomTemplate->m_nTilesX * 256.0) + v4;
    vecWorldMaxs->y = (float)((float)this->m_pRoomTemplate->m_nTilesY * 256.0) + (float)v3;
    vecWorldMaxs->z = 0.0;
  }
  else
  {
    *vecWorldMins = vec3_origin;
    *vecWorldMaxs = vec3_origin;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026C20
// Name: public: virtual class IASW_Room_Details __near * CRoom::GetAdjacentRoom(int)
// Source: json
//------------------------------------------------------------------------------
CRoom *__thiscall CRoom::GetAdjacentRoom(CRoom *this, int nExit)
{
  int nExitY; // [esp+4h] [ebp-4h] BYREF

  if ( GetExitPosition(
         pTemplate: this->m_pRoomTemplate,
         nX: this->m_iPosX,
         nY: this->m_iPosY,
         nExitIndex: nExit,
         pExitX: &nExit,
         pExitY: &nExitY) )
  {
    return this->m_pMapLayout->m_pRoomGrid[nExit][nExitY];
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026C80
// Name: class Vector __near & AllocTempVector(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__cdecl AllocTempVector()
{
  int v0; // eax
  volatile int m_value; // edx
  unsigned __int16 v2; // cx
  volatile int v3; // edx

  v0 = `AllocTempVector'::`2'::`local static guard';
  if ( (`AllocTempVector'::`2'::`local static guard' & 1) == 0 )
  {
    v0 = `AllocTempVector'::`2'::`local static guard' | 1;
    `AllocTempVector'::`2'::`local static guard' |= 1u;
  }
  if ( (v0 & 2) == 0 )
  {
    `AllocTempVector'::`2'::`local static guard' = v0 | 2;
    `AllocTempVector'::`2'::s_nIndex.m_value = 0;
  }
  m_value = `AllocTempVector'::`2'::s_nIndex.m_value;
  v2 = (LOBYTE(`AllocTempVector'::`2'::s_nIndex.m_value) + 1) & 0x7F;
  if ( _InterlockedCompareExchange(
         &`AllocTempVector'::`2'::s_nIndex.m_value,
         (LOBYTE(`AllocTempVector'::`2'::s_nIndex.m_value) + 1) & 0x7F,
         `AllocTempVector'::`2'::s_nIndex.m_value) != m_value )
  {
    do
    {
      _mm_pause();
      v3 = `AllocTempVector'::`2'::s_nIndex.m_value;
      v2 = (LOBYTE(`AllocTempVector'::`2'::s_nIndex.m_value) + 1) & 0x7F;
    }
    while ( _InterlockedCompareExchange(
              &`AllocTempVector'::`2'::s_nIndex.m_value,
              (LOBYTE(`AllocTempVector'::`2'::s_nIndex.m_value) + 1) & 0x7F,
              `AllocTempVector'::`2'::s_nIndex.m_value) != v3 );
  }
  return &`AllocTempVector'::`2'::s_vecTemp[v2];
}

//------------------------------------------------------------------------------
// Address: 0x10026D10
// Name: public: virtual int CRoom::GetNumTags(void)
// Source: json
//------------------------------------------------------------------------------
const CRoomTemplate *__thiscall CRoom::GetNumTags(CRoom *this)
{
  const CRoomTemplate *result; // eax

  result = this->m_pRoomTemplate;
  if ( result != nullptr )
    return (const CRoomTemplate *)result->m_Tags.m_Size;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10026D20
// Name: public: virtual class Vector const __near & CRoom::WorldSpaceCenter(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CRoom::WorldSpaceCenter(CRoom *this)
{
  void (__thiscall *GetWorldBounds)(struct CRoom *, Vector *, Vector *); // eax
  const Vector *result; // eax
  float v3; // xmm1_4
  float v4; // xmm2_4
  Vector mins; // [esp+0h] [ebp-18h] BYREF
  Vector maxs; // [esp+Ch] [ebp-Ch] BYREF

  mins.z = vec3_origin.z;
  maxs.z = vec3_origin.z;
  GetWorldBounds = this->GetWorldBounds;
  *(_QWORD *)&mins.x = *(_QWORD *)&vec3_origin.x;
  *(_QWORD *)&maxs.x = *(_QWORD *)&vec3_origin.x;
  GetWorldBounds(this, a2: &mins, a3: &maxs);
  result = AllocTempVector();
  v3 = (float)(maxs.y + mins.y) * 0.5;
  v4 = (float)(maxs.z + mins.z) * 0.5;
  result->x = (float)(maxs.x + mins.x) * 0.5;
  result->y = v3;
  result->z = v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10026DA0
// Name: public: virtual int CRoom::GetNumExits(void)
// Source: json
//------------------------------------------------------------------------------
const CRoomTemplate *__thiscall CRoom::GetNumExits(CRoom *this)
{
  const CRoomTemplate *result; // eax

  result = this->m_pRoomTemplate;
  if ( result != nullptr )
    return (const CRoomTemplate *)result->m_Exits.m_Size;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10026DB0
// Name: public: static bool CRoom::LoadRoomFromKeyValues(class KeyValues __near *,class CMapLayout __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CRoom::LoadRoomFromKeyValues(KeyValues *pRoomKeys, CMapLayout *pMapLayout)
{
  CRoom *v2; // eax
  int v3; // edi
  CRoom *v4; // ebx
  const char *String; // eax
  const char *v6; // eax
  int m_Size; // ebx
  CLevelTheme *v8; // esi
  int v9; // ebx
  int v10; // edi
  CRoom *v11; // esi
  char szLoadingTemplate[256]; // [esp+Ch] [ebp-204h] BYREF
  char szLoadingTheme[256]; // [esp+10Ch] [ebp-104h] BYREF
  CRoom *pNewRoom; // [esp+20Ch] [ebp-4h]

  v2 = (CRoom *)operator new(nSize: 0x24u);
  v3 = 0;
  if ( v2 != nullptr )
  {
    v4 = v2;
    v2->__vftable = (CRoom_vtbl *)&CRoom::`vftable';
    v2->m_pRoomTemplate = nullptr;
    v2->m_iPosX = 0;
    v2->m_iPosY = 0;
    v2->m_iNumChildren = 0;
    v2->m_nPlacementIndex = -1;
    v2->m_bHasAlienEncounter = false;
    v2->m_pPlacedRoomPanel = nullptr;
    v2->m_pMapLayout = nullptr;
    pNewRoom = v2;
  }
  else
  {
    pNewRoom = nullptr;
    v4 = nullptr;
  }
  szLoadingTheme[0] = 0;
  szLoadingTemplate[0] = 0;
  String = KeyValues::GetString(this: pRoomKeys, keyName: "theme", defaultValue: szDescription);
  V_snprintf(pDest: szLoadingTheme, maxLen: 256, pFormat: "%s", String);
  v6 = KeyValues::GetString(this: pRoomKeys, keyName: "template", defaultValue: szDescription);
  V_snprintf(pDest: szLoadingTemplate, maxLen: 256, pFormat: "%s", v6);
  v4->m_iPosX = KeyValues::GetInt(this: pRoomKeys, keyName: "posx", defaultValue: 0);
  v4->m_iPosY = KeyValues::GetInt(this: pRoomKeys, keyName: "posy", defaultValue: 0);
  m_Size = CLevelTheme::s_LevelThemes.m_Size;
  if ( CLevelTheme::s_LevelThemes.m_Size > 0 )
  {
    while ( 1 )
    {
      v8 = CLevelTheme::s_LevelThemes.m_Memory.m_pMemory[v3];
      if ( v8 != nullptr && _V_stricmp(s1: v8->m_szName, s2: szLoadingTheme) == 0 )
        break;
      if ( ++v3 >= m_Size )
        goto LABEL_14;
    }
    v9 = v8->m_RoomTemplates.m_Size;
    v10 = 0;
    if ( v9 > 0 )
    {
      while ( _V_stricmp(s1: v8->m_RoomTemplates.m_Memory.m_pMemory[v10]->m_FullName, s2: szLoadingTemplate) != 0 )
      {
        if ( ++v10 >= v9 )
          goto LABEL_14;
      }
      pNewRoom->m_pRoomTemplate = v8->m_RoomTemplates.m_Memory.m_pMemory[v10];
    }
  }
LABEL_14:
  v11 = pNewRoom;
  if ( pNewRoom->m_pRoomTemplate != nullptr )
  {
    CMapLayout::PlaceRoom(this: pMapLayout, pRoom: pNewRoom);
    return 1;
  }
  else
  {
    _Msg(a1: "Failed to load room template %s in theme %s\n", szLoadingTemplate, szLoadingTheme);
    ((void (__thiscall *)(CRoom *, int))v11->dtr_CRoom)(a1: v11, a2: 1);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10026F60
// Name: public: virtual char const __near * CRoom::GetTag(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CRoom::GetTag(CRoom *this, int i)
{
  const CRoomTemplate *m_pRoomTemplate; // eax

  m_pRoomTemplate = this->m_pRoomTemplate;
  if ( m_pRoomTemplate != nullptr )
    return m_pRoomTemplate->m_Tags.m_Memory.m_pMemory[i];
  else
    return szDescription;
}
