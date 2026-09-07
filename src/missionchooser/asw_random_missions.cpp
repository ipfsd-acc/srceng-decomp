// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/asw_random_missions.cpp
// Functions: 14
// ============================================================

#include "missionchooser\asw_random_missions.h"

//------------------------------------------------------------------------------
// Address: 0x100083D0
// Name: public: CASW_Random_Missions::~CASW_Random_Missions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Random_Missions::~CASW_Random_Missions(CASW_Random_Missions *this)
{
  CMapLayout *m_pCurrentMapLayout; // ecx

  this->__vftable = (CASW_Random_Missions_vtbl *)&CASW_Random_Missions::`vftable';
  m_pCurrentMapLayout = this->m_pCurrentMapLayout;
  if ( m_pCurrentMapLayout != nullptr )
    ((void (__thiscall *)(CMapLayout *, int))m_pCurrentMapLayout->dtr_CMapLayout)(a1: m_pCurrentMapLayout, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100083F0
// Name: public: virtual class vgui::Panel __near * CASW_Random_Missions::CreateTileGenFrame(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CTileGenDialog *__thiscall CASW_Random_Missions::CreateTileGenFrame(CASW_Random_Missions *this, vgui::Panel *parent)
{
  CTileGenDialog *result; // eax
  CTileGenDialog *v3; // eax

  result = g_pTileGenDialog;
  if ( g_pTileGenDialog == nullptr )
  {
    v3 = (CTileGenDialog *)operator new(nSize: 0x3A8u);
    if ( v3 != nullptr )
      CTileGenDialog::CTileGenDialog(this: v3, parent, name: (vgui::MenuButton *)"TileGenDialog");
    return g_pTileGenDialog;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10008430
// Name: public: virtual void CASW_Random_Missions::LevelInitPostEntity(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Random_Missions::LevelInitPostEntity(CASW_Random_Missions *this, const char *pszMapName)
{
  CMapLayout *m_pCurrentMapLayout; // ecx
  CMapLayout *v4; // eax
  CMapLayout *v5; // eax
  CMapLayout *v6; // ecx
  char fullpath[260]; // [esp+4h] [ebp-184h] BYREF
  char filename[128]; // [esp+108h] [ebp-80h] BYREF

  m_pCurrentMapLayout = this->m_pCurrentMapLayout;
  if ( m_pCurrentMapLayout != nullptr )
    ((void (__thiscall *)(CMapLayout *, int))m_pCurrentMapLayout->dtr_CMapLayout)(a1: m_pCurrentMapLayout, a2: 1);
  CLevelTheme::LoadLevelThemes();
  V_snprintf(pDest: filename, maxLen: 128, pFormat: "maps/%s", pszMapName);
  V_SetExtension(path: filename, extension: "layout", pathStringLength: 128);
  g_pFullFileSystem->RelativePathToFullPath(
    this: g_pFullFileSystem,
    a2: filename,
    a3: "MOD",
    a4: fullpath,
    a5: 260,
    a6: FILTER_NONE,
    a7: nullptr);
  v4 = (CMapLayout *)operator new(nSize: 0xE264u);
  if ( v4 != nullptr )
    v5 = CMapLayout::CMapLayout(this: v4, pGenerationOptions: nullptr);
  else
    v5 = nullptr;
  this->m_pCurrentMapLayout = v5;
  if ( !CMapLayout::LoadMapLayout(this: v5, filename) )
  {
    v6 = this->m_pCurrentMapLayout;
    if ( v6 != nullptr )
      ((void (__thiscall *)(CMapLayout *, int))v6->dtr_CMapLayout)(a1: v6, a2: 1);
    this->m_pCurrentMapLayout = nullptr;
  }
  this->m_bDirtyLayoutForMinimap = true;
}

//------------------------------------------------------------------------------
// Address: 0x10008500
// Name: public: virtual bool CASW_Random_Missions::ValidMapLayout(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CASW_Random_Missions::ValidMapLayout(CASW_Random_Missions *this)
{
  return this->m_pCurrentMapLayout != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10008510
// Name: public: virtual class KeyValues __near * CASW_Random_Missions::GetGenerationOptions(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CASW_Random_Missions::GetGenerationOptions(CASW_Random_Missions *this)
{
  CMapLayout *m_pCurrentMapLayout; // eax
  KeyValues *result; // eax

  m_pCurrentMapLayout = this->m_pCurrentMapLayout;
  if ( m_pCurrentMapLayout == nullptr )
    return nullptr;
  result = m_pCurrentMapLayout->m_pGenerationOptions;
  if ( result == nullptr )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10008530
// Name: public: virtual class IASW_Room_Details __near * CASW_Random_Missions::GetRoomDetails(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
CRoom *__thiscall CASW_Random_Missions::GetRoomDetails(CASW_Random_Missions *this, const Vector *vecPos)
{
  CMapLayout *m_pCurrentMapLayout; // edx
  int v3; // eax
  int v4; // ecx

  m_pCurrentMapLayout = this->m_pCurrentMapLayout;
  if ( m_pCurrentMapLayout != nullptr
    && (v3 = (int)(float)((float)(vecPos->x * 0.00390625) + 60.0),
        v4 = (int)(float)((float)(vecPos->y * 0.00390625) + 60.0),
        v3 >= 0)
    && v4 >= 0
    && v3 < 120
    && v4 < 120 )
  {
    return m_pCurrentMapLayout->m_pRoomGrid[v3][v4];
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100085A0
// Name: public: virtual void CASW_Random_Missions::GetMapBounds(class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CASW_Random_Missions::GetMapBounds(
        CASW_Random_Missions *this,
        Vector *vecWorldMins,
        Vector *vecWorldMaxs)
{
  int (__thiscall *GetNumRooms)(struct CASW_Random_Missions *); // edx
  IASW_Room_Details *v7; // eax
  float x; // xmm0_4
  float y; // xmm1_4
  float v10; // xmm0_4
  float z; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  Vector vecRoomMaxs; // [esp+4h] [ebp-18h] BYREF
  Vector vecRoomMins; // [esp+10h] [ebp-Ch] BYREF
  int i; // [esp+24h] [ebp+8h]
  int iNumRooms; // [esp+28h] [ebp+Ch]

  if ( this->m_pCurrentMapLayout != nullptr )
  {
    vecWorldMins->x = 65535.0;
    vecWorldMins->y = 65535.0;
    vecWorldMins->z = 65535.0;
    vecWorldMaxs->x = -65535.0;
    vecWorldMaxs->y = -65535.0;
    vecWorldMaxs->z = -65535.0;
    vecRoomMins.z = vec3_origin.z;
    vecRoomMaxs.z = vec3_origin.z;
    GetNumRooms = this->GetNumRooms;
    *(_QWORD *)&vecRoomMins.x = *(_QWORD *)&vec3_origin.x;
    *(_QWORD *)&vecRoomMaxs.x = *(_QWORD *)&vec3_origin.x;
    iNumRooms = GetNumRooms(this);
    for ( i = 0; i < iNumRooms; ++i )
    {
      v7 = this->GetRoomDetails(this, a2: i);
      if ( v7 != nullptr )
      {
        v7->GetWorldBounds(this: v7, a2: &vecRoomMins, a3: &vecRoomMaxs);
        x = vecWorldMins->x;
        if ( vecRoomMins.x <= vecWorldMins->x )
          x = vecRoomMins.x;
        y = vecRoomMins.y;
        vecWorldMins->x = x;
        v10 = vecWorldMins->y;
        if ( y <= v10 )
          v10 = y;
        z = vecRoomMins.z;
        vecWorldMins->y = v10;
        v12 = vecWorldMins->z;
        if ( z <= v12 )
          v12 = z;
        v13 = vecRoomMaxs.x;
        vecWorldMins->z = v12;
        v14 = vecWorldMaxs->x;
        if ( vecWorldMaxs->x <= v13 )
          v14 = v13;
        v15 = vecRoomMaxs.y;
        vecWorldMaxs->x = v14;
        v16 = vecWorldMaxs->y;
        if ( v16 <= v15 )
          v16 = v15;
        v17 = vecRoomMaxs.z;
        vecWorldMaxs->y = v16;
        v18 = vecWorldMaxs->z;
        if ( v18 <= v17 )
          v18 = v17;
        vecWorldMaxs->z = v18;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100086F0
// Name: public: virtual bool CASW_Random_Missions::CheckAndCleanDirtyLayout(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CASW_Random_Missions::CheckAndCleanDirtyLayout(CASW_Random_Missions *this)
{
  bool result; // al

  result = this->m_bDirtyLayoutForMinimap;
  this->m_bDirtyLayoutForMinimap = false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10008700
// Name: public: CASW_Random_Missions::CASW_Random_Missions(void)
// Source: json
//------------------------------------------------------------------------------
CASW_Random_Missions *__thiscall CASW_Random_Missions::CASW_Random_Missions(CASW_Random_Missions *this)
{
  this->__vftable = (CASW_Random_Missions_vtbl *)&CASW_Random_Missions::`vftable';
  this->m_pCurrentMapLayout = nullptr;
  this->m_bDirtyLayoutForMinimap = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10008720
// Name: public: virtual int CASW_Random_Missions::GetNumRooms(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CASW_Random_Missions::GetNumRooms(CASW_Random_Missions *this)
{
  return this->m_pCurrentMapLayout->m_PlacedRooms.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10008730
// Name: public: virtual int CASW_Random_Missions::GetNumEncounters(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CASW_Random_Missions::GetNumEncounters(CASW_Random_Missions *this)
{
  return this->m_pCurrentMapLayout->m_Encounters.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10008740
// Name: public: virtual class IASW_Room_Details __near * CASW_Random_Missions::GetStartRoomDetails(void)
// Source: json
//------------------------------------------------------------------------------
CMapLayout *__thiscall CASW_Random_Missions::GetStartRoomDetails(CASW_Random_Missions *this)
{
  CMapLayout *result; // eax
  IASW_Room_Details_vtbl *m_Size; // ebx
  int v3; // esi
  CRoom *v4; // edi
  CASW_Random_Missions *v5; // [esp+0h] [ebp-4h]

  result = this->m_pCurrentMapLayout;
  v5 = this;
  if ( result != nullptr )
  {
    m_Size = (IASW_Room_Details_vtbl *)result->m_PlacedRooms.m_Size;
    v3 = 0;
    if ( (int)m_Size <= 0 )
      return nullptr;
    while ( 1 )
    {
      v4 = this->m_pCurrentMapLayout->m_PlacedRooms.m_Memory.m_pMemory[v3];
      if ( v4 != nullptr )
      {
        if ( CRoomTemplate::IsStartRoom(this: (CRoomTemplate *)v4->m_pRoomTemplate) )
          return (CMapLayout *)v4;
        this = v5;
      }
      if ( ++v3 >= (int)m_Size )
        return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100087A0
// Name: public: virtual class IASW_Room_Details __near * CASW_Random_Missions::GetRoomDetails(int)
// Source: json
//------------------------------------------------------------------------------
CRoom *__thiscall CASW_Random_Missions::GetRoomDetails(CASW_Random_Missions *this, int iRoomIndex)
{
  CMapLayout *m_pCurrentMapLayout; // eax

  if ( iRoomIndex < 0 )
    return nullptr;
  m_pCurrentMapLayout = this->m_pCurrentMapLayout;
  if ( iRoomIndex >= m_pCurrentMapLayout->m_PlacedRooms.m_Size )
    return nullptr;
  else
    return m_pCurrentMapLayout->m_PlacedRooms.m_Memory.m_pMemory[iRoomIndex];
}

//------------------------------------------------------------------------------
// Address: 0x100087D0
// Name: public: virtual class IASW_Encounter __near * CASW_Random_Missions::GetEncounter(int)
// Source: json
//------------------------------------------------------------------------------
CASW_Encounter *__thiscall CASW_Random_Missions::GetEncounter(CASW_Random_Missions *this, int i)
{
  CMapLayout *m_pCurrentMapLayout; // eax

  if ( i < 0 )
    return nullptr;
  m_pCurrentMapLayout = this->m_pCurrentMapLayout;
  if ( i >= m_pCurrentMapLayout->m_Encounters.m_Size )
    return nullptr;
  else
    return m_pCurrentMapLayout->m_Encounters.m_Memory.m_pMemory[i];
}
