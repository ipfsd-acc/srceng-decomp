// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/nav_simplify.cpp
// Functions: 134
// ============================================================

#include "game\server\nav_simplify.h"

//------------------------------------------------------------------------------
// Address: 0x101E9730
// Name: public: bool CNavMesh::ForAllAreasOverlappingExtent<class NavAreaCollector>(class NavAreaCollector __near &,struct Extent const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNavMesh::ForAllAreasOverlappingExtent<NavAreaCollector>(
        CNavMesh *this,
        NavAreaCollector *func,
        const Extent *extent)
{
  CNavMesh *v3; // esi
  IUniformRandomStream *v4; // ecx
  int v6; // eax
  int v7; // eax
  float m_minX; // xmm1_4
  float v9; // xmm0_4
  int v10; // edx
  int m_gridSizeX; // ecx
  int v12; // ebx
  int v13; // ecx
  float m_minY; // xmm1_4
  int v15; // ebx
  int m_gridSizeY; // ecx
  int v17; // edi
  int v18; // ecx
  int v19; // edx
  int v20; // ecx
  CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > *v21; // ebx
  int v22; // edi
  CNavArea *v23; // esi
  Extent areaExtent; // [esp+4h] [ebp-30h] BYREF
  CNavMesh *v25; // [esp+1Ch] [ebp-18h]
  int y; // [esp+20h] [ebp-14h]
  int x; // [esp+24h] [ebp-10h]
  int v28; // [esp+28h] [ebp-Ch]
  int v29; // [esp+2Ch] [ebp-8h]
  int v30; // [esp+30h] [ebp-4h]

  v3 = this;
  v25 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CNavMesh::ForAllAreasOverlappingExtent",
    a3: 0,
    a4: "NextBot",
    a5: false,
    a6: 4);
  if ( v3->m_grid.m_Size == 0 )
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 1;
  }
  if ( (`CNavMesh::ForAllAreasOverlappingExtent<NavAreaCollector>'::`5'::`local static guard' & 1) != 0 )
  {
    v6 = `CNavMesh::ForAllAreasOverlappingExtent<NavAreaCollector>'::`5'::searchMarker;
  }
  else
  {
    `CNavMesh::ForAllAreasOverlappingExtent<NavAreaCollector>'::`5'::`local static guard' |= 1u;
    v6 = _RandomInt(this: v4, a2: 0, a3: 0x100000);
  }
  v7 = v6 + 1;
  `CNavMesh::ForAllAreasOverlappingExtent<NavAreaCollector>'::`5'::searchMarker = v7;
  if ( v7 == 0 )
  {
    v7 = 1;
    `CNavMesh::ForAllAreasOverlappingExtent<NavAreaCollector>'::`5'::searchMarker = 1;
  }
  m_minX = v3->m_minX;
  v9 = 1.0 / v3->m_gridCellSize;
  v10 = (int)(float)((float)(extent->lo.x - m_minX) * v9);
  if ( v10 >= 0 )
  {
    m_gridSizeX = v3->m_gridSizeX;
    if ( v10 >= m_gridSizeX )
      v10 = m_gridSizeX - 1;
  }
  else
  {
    v10 = 0;
  }
  v12 = (int)(float)((float)(extent->hi.x - m_minX) * v9);
  v28 = v12;
  if ( v12 >= 0 )
  {
    v13 = v3->m_gridSizeX;
    if ( v12 >= v13 )
      v28 = v13 - 1;
  }
  else
  {
    v28 = 0;
  }
  m_minY = v3->m_minY;
  v15 = (int)(float)((float)(extent->lo.y - m_minY) * v9);
  v30 = v15;
  if ( v15 >= 0 )
  {
    m_gridSizeY = v3->m_gridSizeY;
    if ( v15 >= m_gridSizeY )
    {
      v30 = m_gridSizeY - 1;
      v15 = m_gridSizeY - 1;
    }
  }
  else
  {
    v30 = 0;
    v15 = 0;
  }
  v17 = (int)(float)((float)(extent->hi.y - m_minY) * v9);
  v29 = v17;
  if ( v17 >= 0 )
  {
    v18 = v3->m_gridSizeY;
    if ( v17 >= v18 )
      v29 = v18 - 1;
  }
  else
  {
    v29 = 0;
  }
  x = v10;
  if ( v10 > v28 )
    goto LABEL_42;
LABEL_25:
  v19 = v15;
  y = v15;
  if ( v15 > v29 )
    goto LABEL_41;
  while ( 1 )
  {
    v20 = x + v19 * v3->m_gridSizeX;
    if ( v20 >= v3->m_grid.m_Size )
    {
      if ( `CNavMesh::ForAllAreasOverlappingExtent<NavAreaCollector>'::`16'::__executeCount < 10 )
      {
        ++`CNavMesh::ForAllAreasOverlappingExtent<NavAreaCollector>'::`16'::__executeCount;
        _Warning(a1: "** Walked off of the CNavMesh::m_grid in ForAllAreasOverlappingExtent()\n");
      }
      goto LABEL_42;
    }
    v21 = &v3->m_grid.m_Memory.m_pMemory[v20];
    v22 = 0;
    if ( v21->m_Size > 0 )
      break;
LABEL_39:
    y = ++v19;
    if ( v19 > v29 )
    {
      v15 = v30;
LABEL_41:
      if ( ++x > v28 )
      {
LABEL_42:
        CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
        return 1;
      }
      goto LABEL_25;
    }
  }
  while ( 1 )
  {
    v23 = v21->m_Memory.m_pMemory[v22];
    if ( v23->m_nearNavSearchMarker != v7 )
      break;
LABEL_37:
    if ( ++v22 >= v21->m_Size )
    {
      v3 = v25;
      v19 = y;
      goto LABEL_39;
    }
  }
  v23->m_nearNavSearchMarker = v7;
  CNavArea::GetExtent(this: v23, extent: &areaExtent);
  if ( areaExtent.hi.x < extent->lo.x
    || extent->hi.x < areaExtent.lo.x
    || areaExtent.hi.y < extent->lo.y
    || extent->hi.y < areaExtent.lo.y
    || areaExtent.hi.z < extent->lo.z
    || extent->hi.z < areaExtent.lo.z
    || NavAreaCollector::operator()(this: func, area: v23) != 0 )
  {
    v7 = `CNavMesh::ForAllAreasOverlappingExtent<NavAreaCollector>'::`5'::searchMarker;
    goto LABEL_37;
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102B4570
// Name: public: bool CNavMesh::ForAllAreas<class CollectOverlappingAreas>(class CollectOverlappingAreas __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNavMesh::ForAllAreas<CollectOverlappingAreas>(CNavMesh *this, CollectOverlappingAreas *func)
{
  int v2; // ebx
  CNavArea *v3; // edi
  CCSBotManager::Zone *m_zone; // eax
  Extent extent; // [esp+Ch] [ebp-18h] BYREF

  v2 = 0;
  if ( TheNavAreas.m_Size <= 0 )
    return 1;
  while ( 1 )
  {
    v3 = TheNavAreas.m_Memory.m_pMemory[v2];
    CNavArea::GetExtent(this: v3, &extent);
    m_zone = func->m_zone;
    if ( extent.hi.x >= func->m_zone->m_extent.lo.x
      && m_zone->m_extent.hi.x >= extent.lo.x
      && extent.hi.y >= m_zone->m_extent.lo.y
      && m_zone->m_extent.hi.y >= extent.lo.y
      && extent.hi.z >= m_zone->m_extent.lo.z
      && m_zone->m_extent.hi.z >= extent.lo.z )
    {
      m_zone->m_area[m_zone->m_areaCount] = v3;
      if ( ++func->m_zone->m_areaCount == 16 )
        break;
    }
    if ( ++v2 >= TheNavAreas.m_Size )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102B4620
// Name: public: bool CNavMesh::ForAllAreas<class CheckAreasOverlappingBreakable>(class CheckAreasOverlappingBreakable __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNavMesh::ForAllAreas<CheckAreasOverlappingBreakable>(
        CNavMesh *this,
        CheckAreasOverlappingBreakable *func)
{
  int i; // ebx
  CNavArea *v3; // edi
  Extent extent; // [esp+4h] [ebp-18h] BYREF

  for ( i = 0; i < TheNavAreas.m_Size; ++i )
  {
    v3 = TheNavAreas.m_Memory.m_pMemory[i];
    CNavArea::GetExtent(this: v3, &extent);
    if ( extent.hi.x >= func->m_breakableExtent.lo.x
      && func->m_breakableExtent.hi.x >= extent.lo.x
      && extent.hi.y >= func->m_breakableExtent.lo.y
      && func->m_breakableExtent.hi.y >= extent.lo.y
      && extent.hi.z >= func->m_breakableExtent.lo.z
      && func->m_breakableExtent.hi.z >= extent.lo.z )
    {
      CNavArea::CheckFloor(this: v3, ignore: func->m_breakable);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102CD510
// Name: public: bool CNavMesh::ForAllAreas<class CollectHidingSpotsFunctor>(class CollectHidingSpotsFunctor __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNavMesh::ForAllAreas<CollectHidingSpotsFunctor>(CNavMesh *this, CollectHidingSpotsFunctor *func)
{
  int v2; // edi
  CNavArea *v4; // edx
  unsigned int m_place; // eax
  int *p_m_Size; // eax
  int v7; // ecx
  int v8; // edi
  float m_range; // xmm3_4
  const Vector *m_origin; // eax
  CBasePlayer *ClosestPlayer; // eax
  int v12; // eax
  int v13; // edi
  CNavArea *area; // [esp+Ch] [ebp-10h]
  float distance; // [esp+10h] [ebp-Ch] BYREF
  CBaseEntity *m_me; // [esp+14h] [ebp-8h]
  int it; // [esp+18h] [ebp-4h]
  CollectHidingSpotsFunctor *funca; // [esp+24h] [ebp+8h]

  v2 = 0;
  it = 0;
  if ( TheNavAreas.m_Size <= 0 )
    return 1;
  while ( 1 )
  {
    v4 = TheNavAreas.m_Memory.m_pMemory[v2];
    m_place = func->m_place;
    area = v4;
    if ( m_place == 0 || v4->m_place == m_place )
    {
      p_m_Size = &v4->m_hidingSpots.m_pData->m_Size;
      v7 = 0;
      funca = nullptr;
      if ( *p_m_Size > 0 )
        break;
LABEL_21:
      if ( func->m_count >= 256 )
        return 0;
    }
    it = ++v2;
    if ( v2 >= TheNavAreas.m_Size )
      return 1;
  }
  while ( 1 )
  {
    v8 = p_m_Size[v7 + 1];
    if ( func->m_count == 256 )
      return 0;
    m_range = func->m_range;
    if ( m_range <= 0.0
      || (m_origin = func->m_origin,
          (float)((float)((float)((float)(*(float *)(v8 + 4) - m_origin->x) * (float)(*(float *)(v8 + 4) - m_origin->x))
                        + (float)((float)(*(float *)(v8 + 8) - m_origin->y) * (float)(*(float *)(v8 + 8) - m_origin->y)))
                + (float)((float)(*(float *)(v8 + 12) - m_origin->z) * (float)(*(float *)(v8 + 12) - m_origin->z))) <= (float)(m_range * m_range)) )
    {
      m_me = func->m_me;
      ClosestPlayer = UTIL_GetClosestPlayer(pos: (const Vector *)(v8 + 4), &distance);
      if ( ClosestPlayer == m_me || ClosestPlayer == nullptr || distance >= 75.0 )
      {
        v12 = *(_DWORD *)(v8 + 24);
        if ( (v12 == 0 || (*(_DWORD *)(v12 + 84) & 0x200) == 0) && (func->m_flags & *(_BYTE *)(v8 + 28)) != 0 )
        {
          func->m_hidingSpot[func->m_count] = (const Vector *)(v8 + 4);
          func->m_hidingSpotWeight[func->m_count] = func->m_totalWeight;
          v13 = *(_DWORD *)(v8 + 24);
          if ( v13 != 0 && *(char *)(v13 + 84) < 0 )
            ++func->m_totalWeight;
          else
            func->m_totalWeight += 2;
          ++func->m_count;
        }
      }
    }
    p_m_Size = &area->m_hidingSpots.m_pData->m_Size;
    v7 = (int)&funca->m_me + 1;
    funca = (CollectHidingSpotsFunctor *)v7;
    if ( v7 >= *p_m_Size )
    {
      v2 = it;
      goto LABEL_21;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102F6CB0
// Name: public: bool CNavMesh::ForAllAreas<class AreaDestroyNotification>(class AreaDestroyNotification __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNavMesh::ForAllAreas<AreaDestroyNotification>(CNavMesh *this, AreaDestroyNotification *func)
{
  int i; // esi
  CNavArea *v3; // ecx

  for ( i = 0; i < TheNavAreas.m_Size; ++i )
  {
    v3 = TheNavAreas.m_Memory.m_pMemory[i];
    if ( v3 != func->m_area )
      v3->OnDestroyNotify_2(this: v3, a2: func->m_area);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102F6CF0
// Name: public: bool CNavMesh::ForAllAreasOverlappingExtent<class COverlapCheck>(class COverlapCheck __near &,struct Extent const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNavMesh::ForAllAreasOverlappingExtent<COverlapCheck>(
        CNavMesh *this,
        COverlapCheck *func,
        const Extent *extent)
{
  CNavMesh *v3; // esi
  IUniformRandomStream *v4; // ecx
  int v6; // eax
  int v7; // eax
  float m_minX; // xmm1_4
  float v9; // xmm0_4
  int v11; // edx
  int m_gridSizeX; // ecx
  int v13; // edi
  int v14; // ecx
  float m_minY; // xmm1_4
  int v16; // edi
  int m_gridSizeY; // ecx
  int v18; // ecx
  int v19; // edx
  int v20; // ecx
  CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > *v21; // edi
  int v22; // esi
  const CNavArea *v23; // ecx
  float z; // xmm0_4
  float v25; // xmm2_4
  float v26; // xmm7_4
  float v27; // xmm1_4
  float m_neZ; // xmm3_4
  float m_swZ; // xmm4_4
  float v30; // xmm4_4
  const Vector *m_pos; // edx
  float v32; // xmm6_4
  float v33; // xmm0_4
  float m_invDxCorners; // xmm2_4
  float m_invDyCorners; // xmm4_4
  float v36; // xmm0_4
  float v37; // xmm2_4
  float v38; // xmm1_4
  int y; // [esp+Ch] [ebp-10h]
  int x; // [esp+10h] [ebp-Ch]
  int v42; // [esp+14h] [ebp-8h]
  int v43; // [esp+18h] [ebp-4h]
  int extenta; // [esp+28h] [ebp+Ch]

  v3 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CNavMesh::ForAllAreasOverlappingExtent",
    a3: 0,
    a4: "NextBot",
    a5: false,
    a6: 4);
  if ( v3->m_grid.m_Size == 0 )
    goto LABEL_2;
  if ( (`CNavMesh::ForAllAreasOverlappingExtent<COverlapCheck>'::`5'::`local static guard' & 1) != 0 )
  {
    v6 = `CNavMesh::ForAllAreasOverlappingExtent<COverlapCheck>'::`5'::searchMarker;
  }
  else
  {
    `CNavMesh::ForAllAreasOverlappingExtent<COverlapCheck>'::`5'::`local static guard' |= 1u;
    v6 = _RandomInt(this: v4, a2: 0, a3: 0x100000);
  }
  v7 = v6 + 1;
  `CNavMesh::ForAllAreasOverlappingExtent<COverlapCheck>'::`5'::searchMarker = v7;
  if ( v7 == 0 )
  {
    v7 = 1;
    `CNavMesh::ForAllAreasOverlappingExtent<COverlapCheck>'::`5'::searchMarker = 1;
  }
  m_minX = v3->m_minX;
  v9 = 1.0 / v3->m_gridCellSize;
  v11 = (int)(float)((float)(extent->lo.x - m_minX) * v9);
  if ( v11 >= 0 )
  {
    m_gridSizeX = v3->m_gridSizeX;
    if ( v11 >= m_gridSizeX )
      v11 = m_gridSizeX - 1;
  }
  else
  {
    v11 = 0;
  }
  v13 = (int)(float)((float)(extent->hi.x - m_minX) * v9);
  v42 = v13;
  if ( v13 >= 0 )
  {
    v14 = v3->m_gridSizeX;
    if ( v13 >= v14 )
      v42 = v14 - 1;
  }
  else
  {
    v42 = 0;
  }
  m_minY = v3->m_minY;
  v16 = (int)(float)((float)(extent->lo.y - m_minY) * v9);
  v43 = v16;
  if ( v16 >= 0 )
  {
    m_gridSizeY = v3->m_gridSizeY;
    if ( v16 >= m_gridSizeY )
    {
      v43 = m_gridSizeY - 1;
      v16 = m_gridSizeY - 1;
    }
  }
  else
  {
    v43 = 0;
    v16 = 0;
  }
  extenta = (int)(float)((float)(extent->hi.y - m_minY) * v9);
  if ( extenta >= 0 )
  {
    v18 = v3->m_gridSizeY;
    if ( extenta >= v18 )
      extenta = v18 - 1;
  }
  else
  {
    extenta = 0;
  }
  x = v11;
  if ( v11 > v42 )
    goto LABEL_2;
LABEL_25:
  v19 = v16;
  y = v16;
  if ( v16 > extenta )
    goto LABEL_73;
  while ( 1 )
  {
    v20 = x + v19 * v3->m_gridSizeX;
    if ( v20 >= v3->m_grid.m_Size )
    {
      if ( `CNavMesh::ForAllAreasOverlappingExtent<COverlapCheck>'::`16'::__executeCount < 10 )
      {
        ++`CNavMesh::ForAllAreasOverlappingExtent<COverlapCheck>'::`16'::__executeCount;
        _Warning(a1: "** Walked off of the CNavMesh::m_grid in ForAllAreasOverlappingExtent()\n");
      }
      goto LABEL_2;
    }
    v21 = &v3->m_grid.m_Memory.m_pMemory[v20];
    v22 = 0;
    if ( v21->m_Size > 0 )
      break;
LABEL_71:
    v3 = this;
    y = ++v19;
    if ( v19 > extenta )
    {
      v16 = v43;
LABEL_73:
      if ( ++x > v42 )
      {
LABEL_2:
        CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
        return 1;
      }
      goto LABEL_25;
    }
  }
  while ( 1 )
  {
    v23 = v21->m_Memory.m_pMemory[v22];
    if ( v23->m_nearNavSearchMarker != v7 )
      break;
LABEL_69:
    if ( ++v22 >= v21->m_Size )
    {
      v19 = y;
      goto LABEL_71;
    }
  }
  v23->m_nearNavSearchMarker = v7;
  z = v23->m_nwCorner.z;
  v25 = v23->m_seCorner.z;
  v26 = z;
  v27 = v25;
  if ( v25 <= z )
    z = v23->m_seCorner.z;
  m_neZ = v23->m_neZ;
  if ( m_neZ <= z )
    z = v23->m_neZ;
  m_swZ = v23->m_swZ;
  if ( m_swZ <= z )
    z = v23->m_swZ;
  if ( v25 <= v26 )
    v25 = v23->m_nwCorner.z;
  if ( v25 <= v27 )
    v25 = v23->m_seCorner.z;
  if ( v25 <= m_neZ )
    v25 = v23->m_neZ;
  if ( v25 <= m_swZ )
    v25 = v23->m_swZ;
  if ( v23->m_seCorner.x >= extent->lo.x && extent->hi.x >= v23->m_nwCorner.x && v23->m_seCorner.y >= extent->lo.y )
  {
    v30 = v23->m_nwCorner.y;
    if ( extent->hi.y >= v30 && v25 >= extent->lo.z && extent->hi.z >= z && v23 != func->m_me )
    {
      m_pos = func->m_pos;
      v32 = v23->m_nwCorner.x;
      if ( m_pos->x >= v32 && v23->m_seCorner.x >= m_pos->x )
      {
        v33 = m_pos->y;
        if ( v33 >= v30 && v23->m_seCorner.y >= v33 )
        {
          m_invDxCorners = v23->m_invDxCorners;
          if ( m_invDxCorners == 0.0 || (m_invDyCorners = v23->m_invDyCorners) == 0.0 )
          {
            v38 = v23->m_neZ;
          }
          else
          {
            v36 = (float)(m_pos->x - v32) * m_invDxCorners;
            v37 = (float)(m_pos->y - v23->m_nwCorner.y) * m_invDyCorners;
            if ( v36 < 0.0 )
              v36 = 0.0;
            if ( (float)(v36 - 1.0) >= 0.0 )
              v36 = 1.0;
            if ( v37 < 0.0 )
              v37 = 0.0;
            if ( (float)(v37 - 1.0) >= 0.0 )
              v37 = 1.0;
            v38 = (float)((float)((float)((float)((float)(v27 - v23->m_swZ) * v36) + v23->m_swZ)
                                - (float)((float)((float)(m_neZ - v26) * v36) + v26))
                        * v37)
                + (float)((float)((float)(m_neZ - v26) * v36) + v26);
          }
          if ( v38 <= m_pos->z && v38 > func->m_myZ )
          {
            CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
            return 0;
          }
        }
      }
    }
  }
  v7 = `CNavMesh::ForAllAreasOverlappingExtent<COverlapCheck>'::`5'::searchMarker;
  goto LABEL_69;
}

//------------------------------------------------------------------------------
// Address: 0x102F70D0
// Name: public: bool CNavMesh::ForAllAreas<class SelectOverlappingAreas>(class SelectOverlappingAreas __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNavMesh::ForAllAreas<SelectOverlappingAreas>(CNavMesh *this, SelectOverlappingAreas *func)
{
  int i; // edi
  CNavArea *v3; // esi
  float z; // ecx
  float v5; // edx
  float x; // xmm1_4
  bool v7; // cc
  float v8; // xmm4_4
  float v9; // xmm0_4
  float m_invDxCorners; // xmm2_4
  float m_invDyCorners; // xmm4_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm4_4
  float v15; // xmm1_4
  float m_neZ; // xmm0_4
  __int64 v18; // [esp+8h] [ebp-3Ch]
  Vector end; // [esp+14h] [ebp-30h] BYREF
  __int64 v20; // [esp+20h] [ebp-24h]
  float v21; // [esp+28h] [ebp-1Ch]
  Vector start; // [esp+2Ch] [ebp-18h] BYREF
  float v23; // [esp+38h] [ebp-Ch]
  CNavLadder *bestLadder; // [esp+3Ch] [ebp-8h] BYREF
  CNavArea *bestArea; // [esp+40h] [ebp-4h] BYREF

  for ( i = 0; i < TheNavAreas.m_Size; ++i )
  {
    v3 = TheNavAreas.m_Memory.m_pMemory[i];
    z = v3->m_nwCorner.z;
    v5 = v3->m_seCorner.z;
    v18 = *(_QWORD *)&v3->m_nwCorner.x;
    v20 = *(_QWORD *)&v3->m_seCorner.x;
    *(_QWORD *)&start.x = *(_QWORD *)&v3->m_nwCorner.x;
    x = start.x + 12.5;
    start.y = start.y + 12.5;
    v7 = *(float *)&v20 <= (float)(start.x + 12.5);
    bestArea = nullptr;
    bestLadder = nullptr;
    v21 = v5;
    start.z = z;
    start.x = start.x + 12.5;
    if ( !v7 )
    {
      v8 = *((float *)&v20 + 1);
      v9 = *((float *)&v18 + 1) + 12.5;
      v23 = *((float *)&v18 + 1) + 12.5;
      do
      {
        start.y = v9;
        if ( v8 > v9 )
        {
          do
          {
            m_invDxCorners = v3->m_invDxCorners;
            if ( m_invDxCorners == 0.0 || (m_invDyCorners = v3->m_invDyCorners) == 0.0 )
            {
              m_neZ = v3->m_neZ;
            }
            else
            {
              v12 = (float)(x - v3->m_nwCorner.x) * m_invDxCorners;
              v13 = (float)(v9 - v3->m_nwCorner.y) * m_invDyCorners;
              v14 = v13;
              if ( v12 < 0.0 )
                v12 = 0.0;
              if ( (float)(v12 - 1.0) >= 0.0 )
                v12 = 1.0;
              if ( v13 < 0.0 )
                v14 = 0.0;
              if ( (float)(v14 - 1.0) >= 0.0 )
                v14 = 1.0;
              v15 = (float)((float)(v3->m_neZ - v3->m_nwCorner.z) * v12) + v3->m_nwCorner.z;
              m_neZ = (float)((float)((float)((float)((float)(v3->m_seCorner.z - v3->m_swZ) * v12) + v3->m_swZ) - v15)
                            * v14)
                    + v15;
            }
            start.z = m_neZ - 18.0;
            *(_QWORD *)&end.x = *(_QWORD *)&start.x;
            end.z = m_neZ + 35.5;
            if ( CNavMesh::FindNavAreaOrLadderAlongRay(
                   this: TheNavMesh,
                   &start,
                   &end,
                   &bestArea,
                   &bestLadder,
                   ignore: v3)
              && bestArea != nullptr )
            {
              CNavMesh::AddToSelectedSet(this: TheNavMesh, area: bestArea);
              CNavMesh::AddToSelectedSet(this: TheNavMesh, area: v3);
            }
            v8 = *((float *)&v20 + 1);
            x = start.x;
            v9 = start.y + 25.0;
            v7 = *((float *)&v20 + 1) <= (float)(start.y + 25.0);
            start.y = start.y + 25.0;
          }
          while ( !v7 );
          v9 = v23;
        }
        x = x + 25.0;
        start.x = x;
      }
      while ( *(float *)&v20 > x );
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102FAB40
// Name: public: bool CNavMesh::ForAllLadders<class LadderConnectionReplacement>(class LadderConnectionReplacement __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNavMesh::ForAllLadders<LadderConnectionReplacement>(CNavMesh *this, LadderConnectionReplacement *func)
{
  int i; // esi
  CNavLadder *v3; // eax

  for ( i = 0; i < this->m_ladders.m_Size; ++i )
  {
    v3 = this->m_ladders.m_Memory.m_pMemory[i];
    if ( v3->m_topForwardArea == func->m_originalArea )
      v3->m_topForwardArea = func->m_replacementArea;
    if ( v3->m_topRightArea == func->m_originalArea )
      v3->m_topRightArea = func->m_replacementArea;
    if ( v3->m_topLeftArea == func->m_originalArea )
      v3->m_topLeftArea = func->m_replacementArea;
    if ( v3->m_topBehindArea == func->m_originalArea )
      v3->m_topBehindArea = func->m_replacementArea;
    if ( v3->m_bottomArea == func->m_originalArea )
      v3->m_bottomArea = func->m_replacementArea;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102FD0C0
// Name: public: bool CNavMesh::ForAllAreasInRadius<class NavAreaCollector>(class NavAreaCollector __near &,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNavMesh::ForAllAreasInRadius<NavAreaCollector>(
        CNavMesh *this,
        NavAreaCollector *func,
        const Vector *pos,
        float radius)
{
  CNavMesh *v4; // esi
  float v5; // xmm0_4
  int v6; // edi
  int m_gridSizeX; // eax
  int v8; // ecx
  int m_gridSizeY; // eax
  float v10; // xmm3_4
  int v11; // ecx
  int v12; // edi
  unsigned int v13; // edx
  int v14; // ebx
  CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > *v15; // esi
  int v16; // edi
  CNavArea *v17; // ecx
  int v19; // [esp+Ch] [ebp-18h]
  float radiusSq; // [esp+14h] [ebp-10h]
  int v22; // [esp+1Ch] [ebp-8h]
  int shiftLimit; // [esp+20h] [ebp-4h]
  int x; // [esp+34h] [ebp+10h]

  v4 = this;
  if ( (`CNavMesh::ForAllAreasInRadius<NavAreaCollector>'::`2'::`local static guard' & 1) == 0 )
  {
    `CNavMesh::ForAllAreasInRadius<NavAreaCollector>'::`2'::`local static guard' |= 1u;
    `CNavMesh::ForAllAreasInRadius<NavAreaCollector>'::`2'::searchMarker = _RandomInt(
                                                                             (IUniformRandomStream *)this,
                                                                             a2: 0,
                                                                             a3: 0x100000);
  }
  if ( ++`CNavMesh::ForAllAreasInRadius<NavAreaCollector>'::`2'::searchMarker == 0 )
    `CNavMesh::ForAllAreasInRadius<NavAreaCollector>'::`2'::searchMarker = 1;
  v5 = 1.0 / v4->m_gridCellSize;
  v6 = (int)(float)((float)(pos->x - v4->m_minX) * v5);
  if ( v6 >= 0 )
  {
    m_gridSizeX = v4->m_gridSizeX;
    if ( v6 >= m_gridSizeX )
      v6 = m_gridSizeX - 1;
  }
  else
  {
    v6 = 0;
  }
  v8 = (int)(float)((float)(pos->y - v4->m_minY) * v5);
  v22 = v8;
  if ( v8 >= 0 )
  {
    m_gridSizeY = v4->m_gridSizeY;
    if ( v8 >= m_gridSizeY )
      v22 = m_gridSizeY - 1;
  }
  else
  {
    v22 = 0;
  }
  shiftLimit = (int)ceil(X: (float)(v5 * radius));
  v10 = radius * radius;
  radiusSq = radius * radius;
  if ( radius == 0.0 )
  {
    shiftLimit = v4->m_gridSizeX;
    if ( shiftLimit <= v4->m_gridSizeY )
      shiftLimit = v4->m_gridSizeY;
  }
  v11 = v6 - shiftLimit;
  v12 = shiftLimit + v6;
  x = v11;
  v19 = v12;
  if ( v11 > v12 )
    return 1;
  v13 = `CNavMesh::ForAllAreasInRadius<NavAreaCollector>'::`2'::searchMarker;
  while ( 1 )
  {
    if ( v11 >= 0 && v11 < v4->m_gridSizeX )
    {
      v14 = v22 - shiftLimit;
      if ( v22 - shiftLimit <= v22 + shiftLimit )
        break;
LABEL_34:
      v12 = v19;
    }
    x = ++v11;
    if ( v11 > v12 )
      return 1;
  }
  while ( 1 )
  {
    if ( v14 >= 0 && v14 < v4->m_gridSizeY )
    {
      v15 = &v4->m_grid.m_Memory.m_pMemory[v11 + v14 * v4->m_gridSizeX];
      v16 = 0;
      if ( v15->m_Size > 0 )
        break;
LABEL_32:
      v4 = this;
    }
    if ( ++v14 > v22 + shiftLimit )
      goto LABEL_34;
  }
  while ( 1 )
  {
    v17 = v15->m_Memory.m_pMemory[v16];
    if ( v17->m_nearNavSearchMarker != v13 )
      break;
LABEL_30:
    if ( ++v16 >= v15->m_Size )
    {
      v11 = x;
      goto LABEL_32;
    }
  }
  v17->m_nearNavSearchMarker = v13;
  if ( v10 < (float)((float)((float)((float)(v17->m_center.x - pos->x) * (float)(v17->m_center.x - pos->x))
                           + (float)((float)(v17->m_center.y - pos->y) * (float)(v17->m_center.y - pos->y)))
                   + (float)((float)(v17->m_center.z - pos->z) * (float)(v17->m_center.z - pos->z)))
    && v10 != 0.0 )
  {
LABEL_29:
    v13 = `CNavMesh::ForAllAreasInRadius<NavAreaCollector>'::`2'::searchMarker;
    goto LABEL_30;
  }
  if ( NavAreaCollector::operator()(this: func, area: v17) != 0 )
  {
    v10 = radiusSq;
    goto LABEL_29;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103064A0
// Name: public: bool CNavMesh::ForAllSelectedAreas<class ShiftSet>(class ShiftSet __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNavMesh::ForAllSelectedAreas<ShiftSet>(CNavMesh *this, ShiftSet *func)
{
  CNavMesh *v2; // ebx
  int m_Size; // eax
  bool result; // al
  CNavArea *v6; // edi
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // eax
  ShiftSet *v8; // ecx
  CNavLadder *ladder; // ebx
  int v10; // eax
  CNavLadder **m_pMemory; // ecx
  int v12; // edi
  int m_nAllocationCount; // eax
  CNavLadder **v14; // ecx
  int v15; // eax
  CNavLadder **v16; // eax
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v17; // eax
  ShiftSet *v18; // ecx
  CNavLadder *v19; // ebx
  int v20; // eax
  CNavLadder **v21; // ecx
  int v22; // edi
  int v23; // eax
  CNavLadder **v24; // ecx
  int v25; // eax
  CNavLadder **v26; // eax
  CNavArea *area; // [esp+8h] [ebp-8h]
  int it; // [esp+Ch] [ebp-4h]
  ShiftSet *funca; // [esp+18h] [ebp+8h]
  ShiftSet *funcb; // [esp+18h] [ebp+8h]

  v2 = this;
  m_Size = this->m_selectedSet.m_Size;
  if ( m_Size != 0 )
  {
    it = 0;
    if ( m_Size > 0 )
    {
      do
      {
        area = v2->m_selectedSet.m_Memory.m_pMemory[it];
        v6 = area;
        CNavArea::Shift(this: area, shift: &func->m_shift);
        m_pData = area->m_ladder[0].m_pData;
        v8 = nullptr;
        funca = nullptr;
        if ( m_pData->m_Size > 0 )
        {
          do
          {
            ladder = m_pData->m_Elements[(_DWORD)v8].ladder;
            v10 = 0;
            if ( func->m_ladders.m_Size <= 0 )
              goto LABEL_13;
            m_pMemory = func->m_ladders.m_Memory.m_pMemory;
            while ( *m_pMemory != ladder )
            {
              ++v10;
              ++m_pMemory;
              if ( v10 >= func->m_ladders.m_Size )
                goto LABEL_13;
            }
            if ( v10 < 0 )
            {
LABEL_13:
              CNavLadder::Shift(this: ladder, shift: &func->m_shift);
              v12 = func->m_ladders.m_Size;
              m_nAllocationCount = func->m_ladders.m_Memory.m_nAllocationCount;
              if ( v12 + 1 > m_nAllocationCount )
                CUtlMemory<CNavLadder *,int>::Grow(
                  this: (CUtlMemory<vgui::TreeNode *,int> *)func,
                  num: v12 - m_nAllocationCount + 1);
              ++func->m_ladders.m_Size;
              v14 = func->m_ladders.m_Memory.m_pMemory;
              v15 = func->m_ladders.m_Size - v12 - 1;
              func->m_ladders.m_pElements = func->m_ladders.m_Memory.m_pMemory;
              if ( v15 > 0 )
                _V_memmove(dest: &v14[v12 + 1], src: &v14[v12], count: 4 * v15);
              v16 = &func->m_ladders.m_Memory.m_pMemory[v12];
              if ( v16 != nullptr )
                *v16 = ladder;
            }
            v6 = area;
            m_pData = area->m_ladder[0].m_pData;
            v8 = (ShiftSet *)((char *)&funca->m_ladders.m_Memory.m_pMemory + 1);
            funca = v8;
          }
          while ( (int)v8 < m_pData->m_Size );
          v2 = this;
        }
        v17 = v6->m_ladder[1].m_pData;
        v18 = nullptr;
        funcb = nullptr;
        if ( v17->m_Size > 0 )
        {
          do
          {
            v19 = v17->m_Elements[(_DWORD)v18].ladder;
            v20 = 0;
            if ( func->m_ladders.m_Size <= 0 )
              goto LABEL_28;
            v21 = func->m_ladders.m_Memory.m_pMemory;
            while ( *v21 != v19 )
            {
              ++v20;
              ++v21;
              if ( v20 >= func->m_ladders.m_Size )
                goto LABEL_28;
            }
            if ( v20 < 0 )
            {
LABEL_28:
              CNavLadder::Shift(this: v19, shift: &func->m_shift);
              v22 = func->m_ladders.m_Size;
              v23 = func->m_ladders.m_Memory.m_nAllocationCount;
              if ( v22 + 1 > v23 )
                CUtlMemory<CNavLadder *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)func, num: v22 - v23 + 1);
              ++func->m_ladders.m_Size;
              v24 = func->m_ladders.m_Memory.m_pMemory;
              v25 = func->m_ladders.m_Size - v22 - 1;
              func->m_ladders.m_pElements = func->m_ladders.m_Memory.m_pMemory;
              if ( v25 > 0 )
                _V_memmove(dest: &v24[v22 + 1], src: &v24[v22], count: 4 * v25);
              v26 = &func->m_ladders.m_Memory.m_pMemory[v22];
              if ( v26 != nullptr )
                *v26 = v19;
            }
            v17 = area->m_ladder[1].m_pData;
            v18 = (ShiftSet *)((char *)&funcb->m_ladders.m_Memory.m_pMemory + 1);
            funcb = v18;
          }
          while ( (int)v18 < v17->m_Size );
          v2 = this;
        }
        ++it;
      }
      while ( it < v2->m_selectedSet.m_Size );
    }
  }
  else if ( this->m_selectedArea != nullptr )
  {
    result = ShiftSet::operator()(this: func, area: this->m_selectedArea);
    if ( !result )
      return result;
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10307A40
// Name: public: bool CNavMesh::ForAllAreas<class AddToDragSet>(class AddToDragSet __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNavMesh::ForAllAreas<AddToDragSet>(CNavMesh *this, AddToDragSet *func)
{
  int i; // edi
  CNavArea *v3; // esi
  int m_Size; // ecx
  int v5; // eax
  CNavArea **m_pMemory; // edx
  char v7; // al
  float z; // xmm0_4

  for ( i = 0; i < TheNavAreas.m_Size; ++i )
  {
    v3 = TheNavAreas.m_Memory.m_pMemory[i];
    m_Size = TheNavMesh->m_selectedSet.m_Size;
    v5 = 0;
    if ( m_Size <= 0 )
    {
LABEL_6:
      v7 = 0;
    }
    else
    {
      m_pMemory = TheNavMesh->m_selectedSet.m_Memory.m_pMemory;
      while ( *m_pMemory != v3 )
      {
        ++v5;
        ++m_pMemory;
        if ( v5 >= m_Size )
          goto LABEL_6;
      }
      v7 = 1;
    }
    if ( v7 == func->m_bDragDeselecting && CNavArea::IsOverlapping(this: v3, extent: &func->m_dragArea) )
    {
      z = v3->m_center.z;
      if ( z >= (float)func->m_zMin && (float)func->m_zMax >= z )
        CNavMesh::AddToDragSelectionSet(this: TheNavMesh, area: v3);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103083F0
// Name: public: bool CNavMesh::ForAllAreas<class RadiusSelect>(class RadiusSelect __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNavMesh::ForAllAreas<RadiusSelect>(CNavMesh *this, RadiusSelect *func)
{
  int i; // ebx
  CNavArea *v3; // esi
  int m_Size; // ecx
  int v5; // eax
  CNavArea **m_pMemory; // edx
  Vector close; // [esp+4h] [ebp-Ch] BYREF

  for ( i = 0; i < TheNavAreas.m_Size; ++i )
  {
    v3 = TheNavAreas.m_Memory.m_pMemory[i];
    m_Size = TheNavMesh->m_selectedSet.m_Size;
    v5 = 0;
    if ( m_Size <= 0 )
    {
LABEL_6:
      CNavArea::GetClosestPointOnArea(this: v3, pPos: &func->m_origin, &close);
      if ( func->m_radiusSquared > (float)((float)((float)((float)(close.y - func->m_origin.y)
                                                         * (float)(close.y - func->m_origin.y))
                                                 + (float)((float)(close.x - func->m_origin.x)
                                                         * (float)(close.x - func->m_origin.x)))
                                         + (float)((float)(close.z - func->m_origin.z)
                                                 * (float)(close.z - func->m_origin.z))) )
      {
        CNavMesh::AddToSelectedSet(this: TheNavMesh, area: v3);
        ++func->m_selected;
      }
    }
    else
    {
      m_pMemory = TheNavMesh->m_selectedSet.m_Memory.m_pMemory;
      while ( *m_pMemory != v3 )
      {
        ++v5;
        ++m_pMemory;
        if ( v5 >= m_Size )
          goto LABEL_6;
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10309840
// Name: public: bool CNavMesh::ForAllAreasOverlappingExtent<class CFuncNavBlocker>(class CFuncNavBlocker __near &,struct Extent const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNavMesh::ForAllAreasOverlappingExtent<CFuncNavBlocker>(
        CNavMesh *this,
        CFuncNavBlocker *func,
        const Extent *extent)
{
  CNavMesh *v3; // esi
  IUniformRandomStream *v4; // ecx
  float m_minX; // xmm1_4
  float v7; // xmm0_4
  int v8; // ecx
  int m_gridSizeX; // eax
  int v10; // ebx
  int v11; // eax
  float m_minY; // xmm1_4
  int v13; // edi
  int m_gridSizeY; // eax
  int v15; // edx
  int v16; // eax
  int v17; // edx
  int v18; // ecx
  int v19; // eax
  CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > *v20; // ebx
  int v21; // edi
  CNavArea *v22; // esi
  Extent areaExtent; // [esp+4h] [ebp-30h] BYREF
  CNavMesh *v24; // [esp+1Ch] [ebp-18h]
  int x; // [esp+20h] [ebp-14h]
  int y; // [esp+24h] [ebp-10h]
  int v27; // [esp+28h] [ebp-Ch]
  int v28; // [esp+2Ch] [ebp-8h]
  int v29; // [esp+30h] [ebp-4h]

  v3 = this;
  v24 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CNavMesh::ForAllAreasOverlappingExtent",
    a3: 0,
    a4: "NextBot",
    a5: false,
    a6: 4);
  if ( v3->m_grid.m_Size != 0 )
  {
    if ( (`CNavMesh::ForAllAreasOverlappingExtent<CFuncNavBlocker>'::`5'::`local static guard' & 1) == 0 )
    {
      `CNavMesh::ForAllAreasOverlappingExtent<CFuncNavBlocker>'::`5'::`local static guard' |= 1u;
      `CNavMesh::ForAllAreasOverlappingExtent<CFuncNavBlocker>'::`5'::searchMarker = _RandomInt(
                                                                                       this: v4,
                                                                                       a2: 0,
                                                                                       a3: 0x100000);
    }
    if ( ++`CNavMesh::ForAllAreasOverlappingExtent<CFuncNavBlocker>'::`5'::searchMarker == 0 )
      `CNavMesh::ForAllAreasOverlappingExtent<CFuncNavBlocker>'::`5'::searchMarker = 1;
    m_minX = v3->m_minX;
    v7 = 1.0 / v3->m_gridCellSize;
    v8 = (int)(float)((float)(extent->lo.x - m_minX) * v7);
    if ( v8 >= 0 )
    {
      m_gridSizeX = v3->m_gridSizeX;
      if ( v8 >= m_gridSizeX )
        v8 = m_gridSizeX - 1;
    }
    else
    {
      v8 = 0;
    }
    v10 = (int)(float)((float)(extent->hi.x - m_minX) * v7);
    v29 = v10;
    if ( v10 >= 0 )
    {
      v11 = v3->m_gridSizeX;
      if ( v10 >= v11 )
      {
        v29 = v11 - 1;
        v10 = v11 - 1;
      }
    }
    else
    {
      v29 = 0;
      v10 = 0;
    }
    m_minY = v3->m_minY;
    v13 = (int)(float)((float)(extent->lo.y - m_minY) * v7);
    v28 = v13;
    if ( v13 >= 0 )
    {
      m_gridSizeY = v3->m_gridSizeY;
      if ( v13 >= m_gridSizeY )
      {
        v28 = m_gridSizeY - 1;
        v13 = m_gridSizeY - 1;
      }
    }
    else
    {
      v28 = 0;
      v13 = 0;
    }
    v15 = (int)(float)((float)(extent->hi.y - m_minY) * v7);
    v27 = v15;
    if ( v15 >= 0 )
    {
      v16 = v3->m_gridSizeY;
      if ( v15 >= v16 )
        v27 = v16 - 1;
    }
    else
    {
      v27 = 0;
    }
    v17 = v8;
    x = v8;
    if ( v8 <= v10 )
    {
      while ( 1 )
      {
        v18 = v13;
        y = v13;
        if ( v13 <= v27 )
          break;
LABEL_39:
        x = ++v17;
        if ( v17 > v10 )
          goto LABEL_43;
      }
      while ( 1 )
      {
        v19 = v17 + v18 * v3->m_gridSizeX;
        if ( v19 >= v3->m_grid.m_Size )
          break;
        v20 = &v3->m_grid.m_Memory.m_pMemory[v19];
        v21 = 0;
        if ( v20->m_Size > 0 )
        {
          do
          {
            v22 = v20->m_Memory.m_pMemory[v21];
            if ( v22->m_nearNavSearchMarker != `CNavMesh::ForAllAreasOverlappingExtent<CFuncNavBlocker>'::`5'::searchMarker )
            {
              v22->m_nearNavSearchMarker = `CNavMesh::ForAllAreasOverlappingExtent<CFuncNavBlocker>'::`5'::searchMarker;
              CNavArea::GetExtent(this: v22, extent: &areaExtent);
              if ( areaExtent.hi.x >= extent->lo.x
                && extent->hi.x >= areaExtent.lo.x
                && areaExtent.hi.y >= extent->lo.y
                && extent->hi.y >= areaExtent.lo.y
                && areaExtent.hi.z >= extent->lo.z
                && extent->hi.z >= areaExtent.lo.z )
              {
                CNavArea::MarkAsBlocked(this: v22, teamID: func->m_blockedTeamNumber, blocker: func, bGenerateEvent: 1);
              }
            }
            ++v21;
          }
          while ( v21 < v20->m_Size );
          v3 = v24;
          v18 = y;
          v17 = x;
        }
        y = ++v18;
        if ( v18 > v27 )
        {
          v10 = v29;
          v13 = v28;
          goto LABEL_39;
        }
      }
      if ( `CNavMesh::ForAllAreasOverlappingExtent<CFuncNavBlocker>'::`16'::__executeCount < 10 )
      {
        ++`CNavMesh::ForAllAreasOverlappingExtent<CFuncNavBlocker>'::`16'::__executeCount;
        _Warning(a1: "** Walked off of the CNavMesh::m_grid in ForAllAreasOverlappingExtent()\n");
      }
    }
LABEL_43:
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 1;
  }
  else
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10309AA0
// Name: public: bool CNavMesh::ForAllAreasOverlappingExtent<class CFuncNavObstruction>(class CFuncNavObstruction __near &,struct Extent const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNavMesh::ForAllAreasOverlappingExtent<CFuncNavObstruction>(
        CNavMesh *this,
        CFuncNavObstruction *func,
        const Extent *extent)
{
  CNavMesh *v3; // esi
  IUniformRandomStream *v4; // ecx
  float m_minX; // xmm1_4
  float v7; // xmm0_4
  int v8; // ecx
  int m_gridSizeX; // eax
  int v10; // ebx
  int v11; // eax
  float m_minY; // xmm1_4
  int v13; // edi
  int m_gridSizeY; // eax
  int v15; // edx
  int v16; // eax
  int v17; // edx
  int v18; // ecx
  int v19; // eax
  CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > *v20; // ebx
  int v21; // edi
  CNavArea *v22; // esi
  float obstructionHeight; // [esp+0h] [ebp-4Ch]
  Extent areaExtent; // [esp+1Ch] [ebp-30h] BYREF
  CNavMesh *v25; // [esp+34h] [ebp-18h]
  int x; // [esp+38h] [ebp-14h]
  int y; // [esp+3Ch] [ebp-10h]
  int v28; // [esp+40h] [ebp-Ch]
  int v29; // [esp+44h] [ebp-8h]
  int v30; // [esp+48h] [ebp-4h]

  v3 = this;
  v25 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CNavMesh::ForAllAreasOverlappingExtent",
    a3: 0,
    a4: "NextBot",
    a5: false,
    a6: 4);
  if ( v3->m_grid.m_Size != 0 )
  {
    if ( (`CNavMesh::ForAllAreasOverlappingExtent<CFuncNavObstruction>'::`5'::`local static guard' & 1) == 0 )
    {
      `CNavMesh::ForAllAreasOverlappingExtent<CFuncNavObstruction>'::`5'::`local static guard' |= 1u;
      `CNavMesh::ForAllAreasOverlappingExtent<CFuncNavObstruction>'::`5'::searchMarker = _RandomInt(
                                                                                           this: v4,
                                                                                           a2: 0,
                                                                                           a3: 0x100000);
    }
    if ( ++`CNavMesh::ForAllAreasOverlappingExtent<CFuncNavObstruction>'::`5'::searchMarker == 0 )
      `CNavMesh::ForAllAreasOverlappingExtent<CFuncNavObstruction>'::`5'::searchMarker = 1;
    m_minX = v3->m_minX;
    v7 = 1.0 / v3->m_gridCellSize;
    v8 = (int)(float)((float)(extent->lo.x - m_minX) * v7);
    if ( v8 >= 0 )
    {
      m_gridSizeX = v3->m_gridSizeX;
      if ( v8 >= m_gridSizeX )
        v8 = m_gridSizeX - 1;
    }
    else
    {
      v8 = 0;
    }
    v10 = (int)(float)((float)(extent->hi.x - m_minX) * v7);
    v30 = v10;
    if ( v10 >= 0 )
    {
      v11 = v3->m_gridSizeX;
      if ( v10 >= v11 )
      {
        v30 = v11 - 1;
        v10 = v11 - 1;
      }
    }
    else
    {
      v30 = 0;
      v10 = 0;
    }
    m_minY = v3->m_minY;
    v13 = (int)(float)((float)(extent->lo.y - m_minY) * v7);
    v29 = v13;
    if ( v13 >= 0 )
    {
      m_gridSizeY = v3->m_gridSizeY;
      if ( v13 >= m_gridSizeY )
      {
        v29 = m_gridSizeY - 1;
        v13 = m_gridSizeY - 1;
      }
    }
    else
    {
      v29 = 0;
      v13 = 0;
    }
    v15 = (int)(float)((float)(extent->hi.y - m_minY) * v7);
    v28 = v15;
    if ( v15 >= 0 )
    {
      v16 = v3->m_gridSizeY;
      if ( v15 >= v16 )
        v28 = v16 - 1;
    }
    else
    {
      v28 = 0;
    }
    v17 = v8;
    x = v8;
    if ( v8 <= v10 )
    {
      while ( 1 )
      {
        v18 = v13;
        y = v13;
        if ( v13 <= v28 )
          break;
LABEL_39:
        x = ++v17;
        if ( v17 > v10 )
          goto LABEL_43;
      }
      while ( 1 )
      {
        v19 = v17 + v18 * v3->m_gridSizeX;
        if ( v19 >= v3->m_grid.m_Size )
          break;
        v20 = &v3->m_grid.m_Memory.m_pMemory[v19];
        v21 = 0;
        if ( v20->m_Size > 0 )
        {
          do
          {
            v22 = v20->m_Memory.m_pMemory[v21];
            if ( v22->m_nearNavSearchMarker != `CNavMesh::ForAllAreasOverlappingExtent<CFuncNavObstruction>'::`5'::searchMarker )
            {
              v22->m_nearNavSearchMarker = `CNavMesh::ForAllAreasOverlappingExtent<CFuncNavObstruction>'::`5'::searchMarker;
              CNavArea::GetExtent(this: v22, extent: &areaExtent);
              if ( areaExtent.hi.x >= extent->lo.x
                && extent->hi.x >= areaExtent.lo.x
                && areaExtent.hi.y >= extent->lo.y
                && extent->hi.y >= areaExtent.lo.y
                && areaExtent.hi.z >= extent->lo.z
                && extent->hi.z >= areaExtent.lo.z )
              {
                obstructionHeight = func->GetNavObstructionHeight(this: &func->INavAvoidanceObstacle);
                CNavArea::MarkObstacleToAvoid(this: v22, obstructionHeight);
              }
            }
            ++v21;
          }
          while ( v21 < v20->m_Size );
          v3 = v25;
          v18 = y;
          v17 = x;
        }
        y = ++v18;
        if ( v18 > v28 )
        {
          v10 = v30;
          v13 = v29;
          goto LABEL_39;
        }
      }
      if ( `CNavMesh::ForAllAreasOverlappingExtent<CFuncNavObstruction>'::`16'::__executeCount < 10 )
      {
        ++`CNavMesh::ForAllAreasOverlappingExtent<CFuncNavObstruction>'::`16'::__executeCount;
        _Warning(a1: "** Walked off of the CNavMesh::m_grid in ForAllAreasOverlappingExtent()\n");
      }
    }
LABEL_43:
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 1;
  }
  else
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10313C50
// Name: public: bool CNavMesh::ForAllAreas<class JumpConnector>(class JumpConnector __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNavMesh::ForAllAreas<JumpConnector>(CNavMesh *this, JumpConnector *func)
{
  int v2; // eax
  CNavArea *v3; // esi
  int i; // ebx
  NavDirType v5; // edi
  int it; // [esp+4h] [ebp-4h]

  v2 = 0;
  for ( it = 0; v2 < TheNavAreas.m_Size; it = v2 )
  {
    v3 = TheNavAreas.m_Memory.m_pMemory[v2];
    if ( (v3->m_attributeFlags & 2) != 0 )
    {
      for ( i = 0; i < 4; ++i )
      {
        switch ( i )
        {
          case 0:
            v5 = SOUTH;
            break;
          case 1:
            v5 = WEST;
            break;
          case 3:
            v5 = EAST;
            break;
          default:
            v5 = NORTH;
            break;
        }
        JumpConnector::TryToConnect(
          this: func,
          jumpArea: v3,
          source: &v3->m_incomingConnect[i],
          dest: &v3->m_connect[v5],
          outgoingDir: v5);
        JumpConnector::TryToConnect(
          this: func,
          jumpArea: v3,
          source: &v3->m_connect[i],
          dest: &v3->m_connect[v5],
          outgoingDir: v5);
      }
      v2 = it;
    }
    ++v2;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10313D10
// Name: public: bool CNavMesh::ForAllSelectedAreas<class Subdivider>(class Subdivider __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNavMesh::ForAllSelectedAreas<Subdivider>(CNavMesh *this, Subdivider *func)
{
  CNavMesh *v2; // esi
  CNavArea *m_selectedArea; // esi
  bool result; // al
  int v5; // eax
  int m_depth; // edi
  CNavArea *v8; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // edi
  CNavArea *v12; // [esp+30h] [ebp-18h] BYREF
  CNavArea *area; // [esp+34h] [ebp-14h] BYREF
  CNavArea *outBeta; // [esp+38h] [ebp-10h] BYREF
  CNavArea *outAlpha; // [esp+3Ch] [ebp-Ch] BYREF
  CNavMesh *v16; // [esp+40h] [ebp-8h]
  int it; // [esp+44h] [ebp-4h]
  float funca; // [esp+50h] [ebp+8h]
  float funcb; // [esp+50h] [ebp+8h]

  v2 = this;
  v16 = this;
  if ( !CNavMesh::IsSelectedSetEmpty(this) )
  {
    v5 = 0;
    it = 0;
    if ( v2->m_selectedSet.m_Size > 0 )
    {
      while ( 1 )
      {
        m_depth = func->m_depth;
        v8 = v2->m_selectedSet.m_Memory.m_pMemory[v5];
        if ( func->m_depth > 0 )
        {
          v9 = (float)(v8->m_seCorner.x - v8->m_nwCorner.x) * 0.5;
          if ( v9 >= 25.0 )
          {
            funcb = CNavMesh::SnapToGrid(this: TheNavMesh, x: v9 + v8->m_nwCorner.x, forceGrid: false);
            if ( CNavArea::SplitEdit(this: v8, splitAlongX: 0, splitEdge: funcb, outAlpha: &area, outBeta: &v12) != 0 )
            {
              Subdivider::SubdivideY(this: func, area, canDivideX: true, canDivideY: true, depth: m_depth);
              Subdivider::SubdivideY(this: func, area: v12, canDivideX: true, canDivideY: true, depth: m_depth);
            }
          }
          else
          {
            v10 = (float)(v8->m_seCorner.y - v8->m_nwCorner.y) * 0.5;
            if ( v10 >= 25.0 )
            {
              funca = CNavMesh::SnapToGrid(this: TheNavMesh, x: v10 + v8->m_nwCorner.y, forceGrid: false);
              if ( CNavArea::SplitEdit(this: v8, splitAlongX: 1, splitEdge: funca, &outAlpha, &outBeta) != 0 )
              {
                v11 = m_depth - 1;
                Subdivider::SubdivideX(this: func, area: outAlpha, canDivideX: false, canDivideY: true, depth: v11);
                Subdivider::SubdivideX(this: func, area: outBeta, canDivideX: false, canDivideY: true, depth: v11);
              }
            }
          }
        }
        v5 = it + 1;
        it = v5;
        if ( v5 >= v16->m_selectedSet.m_Size )
          break;
        v2 = v16;
      }
    }
    return true;
  }
  m_selectedArea = v2->m_selectedArea;
  if ( m_selectedArea == nullptr )
    return true;
  result = Subdivider::operator()(this: func, area: m_selectedArea);
  if ( result )
    return true;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10313EC0
// Name: public: void CNavMesh::StitchAreaIntoMesh<class IncrementallyGeneratedAreas>(class CNavArea __near *,enum NavDirType,class IncrementallyGeneratedAreas __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::StitchAreaIntoMesh<IncrementallyGeneratedAreas>(
        CNavMesh *this,
        CNavArea *area,
        NavDirType dir,
        IncrementallyGeneratedAreas *func)
{
  float z; // eax
  float x; // xmm1_4
  float y; // xmm0_4
  float v9; // ecx
  float v10; // xmm1_4
  float m_swZ; // xmm2_4
  float v12; // xmm0_4
  bool v13; // cc
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // edx
  float v18; // xmm1_4
  float m_neZ; // xmm2_4
  float v20; // eax
  float v21; // xmm1_4
  CNavArea *NavArea; // eax
  CNavArea *v23; // ebx
  CNavArea *JumpDownArea; // eax
  CNavArea *v25; // ebx
  NavDirType x_4; // [esp+4h] [ebp-40h]
  Vector corner2; // [esp+14h] [ebp-30h] BYREF
  Vector sourcePos; // [esp+20h] [ebp-24h] BYREF
  Vector targetPos; // [esp+2Ch] [ebp-18h] BYREF
  Vector corner1; // [esp+38h] [ebp-Ch]
  float edgeLengtha; // [esp+4Ch] [ebp+8h]
  float edgeLength; // [esp+4Ch] [ebp+8h]
  float n; // [esp+50h] [ebp+Ch]

  switch ( dir )
  {
    case NORTH:
      z = area->m_nwCorner.z;
      x = area->m_seCorner.x;
      *(_QWORD *)&corner2.x = *(_QWORD *)&area->m_nwCorner.x;
      *(_QWORD *)&corner1.x = *(_QWORD *)&corner2.x;
      corner2.z = z;
      corner1.z = z;
      y = area->m_nwCorner.y;
      goto LABEL_5;
    case EAST:
      v17 = area->m_seCorner.z;
      v18 = area->m_nwCorner.y;
      m_neZ = area->m_neZ;
      corner1.x = area->m_seCorner.x;
      corner1.y = v18;
      corner1.z = m_neZ;
      *(_QWORD *)&corner2.x = *(_QWORD *)&area->m_seCorner.x;
      corner2.z = v17;
      goto LABEL_4;
    case SOUTH:
      v9 = area->m_seCorner.z;
      v10 = area->m_seCorner.y;
      m_swZ = area->m_swZ;
      corner1.x = area->m_nwCorner.x;
      corner1.y = v10;
      corner1.z = m_swZ;
      *(_QWORD *)&corner2.x = *(_QWORD *)&area->m_seCorner.x;
      corner2.z = v9;
      goto LABEL_4;
    case WEST:
      v20 = area->m_nwCorner.z;
      x = area->m_nwCorner.x;
      *(_QWORD *)&corner2.x = *(_QWORD *)&area->m_nwCorner.x;
      *(_QWORD *)&corner1.x = *(_QWORD *)&corner2.x;
      corner2.z = v20;
      corner1.z = v20;
      y = area->m_seCorner.y;
      goto LABEL_5;
    default:
LABEL_4:
      y = corner2.y;
      x = corner2.x;
LABEL_5:
      corner2.y = y - corner1.y;
      corner2.x = x - corner1.x;
      corner2.z = 0.0;
      edgeLengtha = VectorNormalize(vec: &corner2);
      v12 = 0.0;
      v13 = (float)(edgeLengtha - 1.0) <= 0.0;
      n = 0.0;
      for ( edgeLength = edgeLengtha - 1.0; !v13; n = n + 25.0 )
      {
        v14 = v12 + 0.5;
        v15 = (float)(corner2.x * v14) + corner1.x;
        v16 = (float)(corner2.y * v14) + corner1.y;
        sourcePos.z = (float)((float)(v14 * corner2.z) + corner1.z) + 35.5;
        sourcePos.x = v15;
        sourcePos.y = v16;
        targetPos = sourcePos;
        switch ( dir )
        {
          case NORTH:
            targetPos.y = v16 - 12.5;
            break;
          case EAST:
            v21 = v15 + 12.5;
            goto LABEL_13;
          case SOUTH:
            targetPos.y = v16 + 12.5;
            break;
          case WEST:
            v21 = v15 - 12.5;
LABEL_13:
            targetPos.x = v21;
            break;
          default:
            break;
        }
        NavArea = CNavMesh::GetNavArea(this: TheNavMesh, pos: &targetPos, beneathLimit: 120.0);
        v23 = NavArea;
        if ( NavArea == nullptr || CNavArea::HasNodes(this: NavArea) != 0 )
        {
          sourcePos.z = (float)(sourcePos.z - 35.5) + 1.0;
          JumpDownArea = findJumpDownArea(fromPos: &sourcePos, dir);
          v25 = JumpDownArea;
          if ( JumpDownArea != nullptr && JumpDownArea != area && CNavArea::HasNodes(this: JumpDownArea) == 0 )
            CNavArea::ConnectTo(this: area, area: v25, dir);
        }
        else
        {
          targetPos.z = CNavArea::GetZ(this: v23, x: targetPos.x, y: targetPos.y) + 35.5;
          if ( testStitchConnection(&sourcePos, &targetPos) )
            CNavArea::ConnectTo(this: area, area: v23, dir);
          if ( testStitchConnection(sourcePos: &targetPos, targetPos: &sourcePos) )
          {
            x_4 = OppositeDirection(dir);
            CNavArea::ConnectTo(this: v23, area, dir: x_4);
          }
        }
        v12 = n + 25.0;
        v13 = edgeLength <= (float)(n + 25.0);
      }
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103141C0
// Name: public: void CNavMesh::StitchAreaIntoMesh<class AreaSet>(class CNavArea __near *,enum NavDirType,class AreaSet __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::StitchAreaIntoMesh<AreaSet>(CNavMesh *this, CNavArea *area, NavDirType dir, AreaSet *func)
{
  float z; // eax
  float x; // xmm1_4
  float y; // xmm0_4
  float v9; // ecx
  float v10; // xmm1_4
  float m_swZ; // xmm2_4
  float v12; // xmm0_4
  bool v13; // cc
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // edx
  float v18; // xmm1_4
  float m_neZ; // xmm2_4
  float v20; // eax
  float v21; // xmm1_4
  CNavArea *NavArea; // esi
  int m_Size; // ecx
  int v24; // eax
  CNavArea **m_pMemory; // edx
  CNavArea *JumpDownArea; // eax
  int v27; // edx
  int v28; // ecx
  CNavArea **v29; // esi
  NavDirType x_4; // [esp+4h] [ebp-40h]
  Vector corner2; // [esp+14h] [ebp-30h] BYREF
  Vector sourcePos; // [esp+20h] [ebp-24h] BYREF
  Vector targetPos; // [esp+2Ch] [ebp-18h] BYREF
  Vector corner1; // [esp+38h] [ebp-Ch]
  float edgeLengtha; // [esp+4Ch] [ebp+8h]
  float edgeLength; // [esp+4Ch] [ebp+8h]
  float n; // [esp+50h] [ebp+Ch]

  switch ( dir )
  {
    case NORTH:
      z = area->m_nwCorner.z;
      x = area->m_seCorner.x;
      *(_QWORD *)&corner2.x = *(_QWORD *)&area->m_nwCorner.x;
      *(_QWORD *)&corner1.x = *(_QWORD *)&corner2.x;
      corner2.z = z;
      corner1.z = z;
      y = area->m_nwCorner.y;
      goto LABEL_5;
    case EAST:
      v17 = area->m_seCorner.z;
      v18 = area->m_nwCorner.y;
      m_neZ = area->m_neZ;
      corner1.x = area->m_seCorner.x;
      corner1.y = v18;
      corner1.z = m_neZ;
      *(_QWORD *)&corner2.x = *(_QWORD *)&area->m_seCorner.x;
      corner2.z = v17;
      goto LABEL_4;
    case SOUTH:
      v9 = area->m_seCorner.z;
      v10 = area->m_seCorner.y;
      m_swZ = area->m_swZ;
      corner1.x = area->m_nwCorner.x;
      corner1.y = v10;
      corner1.z = m_swZ;
      *(_QWORD *)&corner2.x = *(_QWORD *)&area->m_seCorner.x;
      corner2.z = v9;
      goto LABEL_4;
    case WEST:
      v20 = area->m_nwCorner.z;
      x = area->m_nwCorner.x;
      *(_QWORD *)&corner2.x = *(_QWORD *)&area->m_nwCorner.x;
      *(_QWORD *)&corner1.x = *(_QWORD *)&corner2.x;
      corner2.z = v20;
      corner1.z = v20;
      y = area->m_seCorner.y;
      goto LABEL_5;
    default:
LABEL_4:
      y = corner2.y;
      x = corner2.x;
LABEL_5:
      corner2.y = y - corner1.y;
      corner2.x = x - corner1.x;
      corner2.z = 0.0;
      edgeLengtha = VectorNormalize(vec: &corner2);
      v12 = 0.0;
      v13 = (float)(edgeLengtha - 1.0) <= 0.0;
      n = 0.0;
      edgeLength = edgeLengtha - 1.0;
      if ( v13 )
        return;
      break;
  }
  do
  {
    v14 = v12 + 0.5;
    v15 = (float)(corner2.x * v14) + corner1.x;
    v16 = (float)(corner2.y * v14) + corner1.y;
    sourcePos.z = (float)((float)(v14 * corner2.z) + corner1.z) + 35.5;
    sourcePos.x = v15;
    sourcePos.y = v16;
    targetPos = sourcePos;
    switch ( dir )
    {
      case NORTH:
        targetPos.y = v16 - 12.5;
        break;
      case EAST:
        v21 = v15 + 12.5;
        goto LABEL_13;
      case SOUTH:
        targetPos.y = v16 + 12.5;
        break;
      case WEST:
        v21 = v15 - 12.5;
LABEL_13:
        targetPos.x = v21;
        break;
      default:
        break;
    }
    NavArea = CNavMesh::GetNavArea(this: TheNavMesh, pos: &targetPos, beneathLimit: 120.0);
    if ( NavArea == nullptr )
      goto LABEL_25;
    m_Size = func->m_areas->m_Size;
    v24 = 0;
    if ( m_Size <= 0 )
      goto LABEL_21;
    m_pMemory = func->m_areas->m_Memory.m_pMemory;
    while ( *m_pMemory != NavArea )
    {
      ++v24;
      ++m_pMemory;
      if ( v24 >= m_Size )
        goto LABEL_21;
    }
    if ( v24 < 0 )
    {
LABEL_21:
      targetPos.z = CNavArea::GetZ(this: NavArea, x: targetPos.x, y: targetPos.y) + 35.5;
      if ( testStitchConnection(&sourcePos, &targetPos) )
        CNavArea::ConnectTo(this: area, area: NavArea, dir);
      if ( testStitchConnection(sourcePos: &targetPos, targetPos: &sourcePos) )
      {
        x_4 = OppositeDirection(dir);
        CNavArea::ConnectTo(this: NavArea, area, dir: x_4);
      }
    }
    else
    {
LABEL_25:
      sourcePos.z = (float)(sourcePos.z - 35.5) + 1.0;
      JumpDownArea = findJumpDownArea(fromPos: &sourcePos, dir);
      if ( JumpDownArea != nullptr && JumpDownArea != area )
      {
        v27 = func->m_areas->m_Size;
        v28 = 0;
        if ( v27 <= 0 )
          goto LABEL_33;
        v29 = func->m_areas->m_Memory.m_pMemory;
        while ( *v29 != JumpDownArea )
        {
          ++v28;
          ++v29;
          if ( v28 >= v27 )
            goto LABEL_33;
        }
        if ( v28 < 0 )
LABEL_33:
          CNavArea::ConnectTo(this: area, area: JumpDownArea, dir);
      }
    }
    v12 = n + 25.0;
    v13 = edgeLength <= (float)(n + 25.0);
    n = n + 25.0;
  }
  while ( !v13 );
}

//------------------------------------------------------------------------------
// Address: 0x10314550
// Name: public: bool CNavMesh::StitchMesh<class IncrementallyGeneratedAreas>(class IncrementallyGeneratedAreas __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CNavMesh::StitchMesh<IncrementallyGeneratedAreas>@<al>(
        CNavMesh *this@<ecx>,
        int a2@<ebp>,
        float *a3@<edi>,
        int a4@<esi>,
        IncrementallyGeneratedAreas *func)
{
  int v5; // esi
  CNavArea *v6; // edi
  float z; // ecx
  float y; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  CNavArea *NavArea; // eax
  CNavArea *v12; // esi
  int v13; // eax
  int v14; // esi
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  void (__thiscall *TraceRay)(IEngineTrace *, const Ray_t *, unsigned int, ITraceFilter *, CGameTrace *); // eax
  CNavArea *v19; // eax
  CNavArea *v20; // esi
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // eax
  float v24; // xmm0_4
  float v25; // xmm0_4
  CNavArea *v26; // eax
  CNavArea *v27; // esi
  NavDirType v28; // eax
  int n; // edi
  int v30; // eax
  int v31; // esi
  float v32; // xmm1_4
  float v33; // xmm2_4
  float v34; // xmm0_4
  void (__thiscall *v35)(IEngineTrace *, const Ray_t *, unsigned int, ITraceFilter *, CGameTrace *); // edx
  CNavArea *v36; // eax
  CNavArea *v37; // esi
  float v38; // xmm1_4
  float v39; // xmm2_4
  float v40; // edx
  float v41; // xmm1_4
  float v42; // xmm1_4
  CNavArea *v43; // eax
  CNavArea *v44; // esi
  NavDirType v45; // eax
  int jj; // edi
  int v47; // eax
  int v48; // esi
  float v49; // xmm1_4
  float v50; // xmm2_4
  float v51; // xmm0_4
  void (__thiscall *v52)(IEngineTrace *, const Ray_t *, unsigned int, ITraceFilter *, CGameTrace *); // edx
  CNavArea *v53; // eax
  CNavArea *v54; // esi
  NavDirType beneathLimit; // [esp+34h] [ebp-240h]
  CTraceFilterSimple v59; // [esp+40h] [ebp-234h] BYREF
  CTraceFilterSimple v60; // [esp+50h] [ebp-224h] BYREF
  CTraceFilterSimple v61; // [esp+60h] [ebp-214h] BYREF
  Vector v62; // [esp+70h] [ebp-204h] BYREF
  Vector v63[2]; // [esp+7Ch] [ebp-1F8h] BYREF
  float v64; // [esp+9Ch] [ebp-1D8h]
  Vector v65; // [esp+C8h] [ebp-1ACh] BYREF
  Vector v66; // [esp+D4h] [ebp-1A0h] BYREF
  __int64 v67; // [esp+E0h] [ebp-194h]
  float v68; // [esp+E8h] [ebp-18Ch]
  Vector v69; // [esp+ECh] [ebp-188h] BYREF
  __int64 v70; // [esp+F8h] [ebp-17Ch]
  float v71; // [esp+100h] [ebp-174h]
  float m; // [esp+104h] [ebp-170h]
  CNavMesh *v73; // [esp+108h] [ebp-16Ch]
  unsigned int v74; // [esp+10Ch] [ebp-168h]
  float ii; // [esp+110h] [ebp-164h]
  float v76; // [esp+114h] [ebp-160h]
  float v77; // [esp+118h] [ebp-15Ch]
  float m_swZ; // [esp+11Ch] [ebp-158h]
  unsigned int v79; // [esp+120h] [ebp-154h]
  float j; // [esp+124h] [ebp-150h]
  unsigned int v81; // [esp+128h] [ebp-14Ch]
  float v82; // [esp+12Ch] [ebp-148h]
  float v83; // [esp+130h] [ebp-144h]
  float m_neZ; // [esp+134h] [ebp-140h]
  Vector v85; // [esp+138h] [ebp-13Ch] BYREF
  Vector v86; // [esp+144h] [ebp-130h] BYREF
  __int64 v87; // [esp+150h] [ebp-124h]
  float v88; // [esp+158h] [ebp-11Ch]
  Vector v89; // [esp+15Ch] [ebp-118h] BYREF
  float v90[4]; // [esp+168h] [ebp-10Ch] BYREF
  float v91; // [esp+178h] [ebp-FCh]
  float v92; // [esp+17Ch] [ebp-F8h]
  float v93; // [esp+180h] [ebp-F4h]
  float v94; // [esp+188h] [ebp-ECh]
  float v95; // [esp+18Ch] [ebp-E8h]
  float v96; // [esp+190h] [ebp-E4h]
  float v97; // [esp+198h] [ebp-DCh]
  float v98; // [esp+19Ch] [ebp-D8h]
  float v99; // [esp+1A0h] [ebp-D4h]
  int v100; // [esp+1A8h] [ebp-CCh]
  bool v101; // [esp+1ACh] [ebp-C8h]
  bool v102; // [esp+1ADh] [ebp-C7h]
  unsigned __int64 v103; // [esp+1C0h] [ebp-B4h]
  float v104; // [esp+1C8h] [ebp-ACh]
  float v105; // [esp+1CCh] [ebp-A8h]
  Vector v106; // [esp+1D0h] [ebp-A4h] BYREF
  float v107; // [esp+1DCh] [ebp-98h]
  Vector x; // [esp+1E0h] [ebp-94h] BYREF
  Vector v109; // [esp+1ECh] [ebp-88h] BYREF
  float v110; // [esp+1F8h] [ebp-7Ch]
  int i; // [esp+1FCh] [ebp-78h]
  unsigned __int64 v112; // [esp+200h] [ebp-74h]
  int it; // [esp+208h] [ebp-6Ch]
  unsigned __int64 v114; // [esp+20Ch] [ebp-68h]
  float v115; // [esp+214h] [ebp-60h]
  Vector v116; // [esp+218h] [ebp-5Ch] BYREF
  Vector v117; // [esp+224h] [ebp-50h] BYREF
  Vector v118; // [esp+230h] [ebp-44h] BYREF
  Vector v119; // [esp+23Ch] [ebp-38h] BYREF
  Vector v120; // [esp+248h] [ebp-2Ch] BYREF
  Vector v121; // [esp+254h] [ebp-20h] BYREF
  int k; // [esp+260h] [ebp-14h]
  CNavArea *v123; // [esp+264h] [ebp-10h]
  int v124; // [esp+268h] [ebp-Ch]
  void *v125; // [esp+26Ch] [ebp-8h]
  void *retaddr; // [esp+274h] [ebp+0h]

  v124 = a2;
  v125 = retaddr;
  v5 = 0;
  v73 = this;
  for ( i = 0; v5 < TheNavAreas.m_Size; i = v5 )
  {
    v123 = TheNavAreas.m_Memory.m_pMemory[v5];
    v6 = v123;
    if ( CNavArea::HasNodes(this: v123) != 0 )
    {
      z = v6->m_nwCorner.z;
      y = v6->m_nwCorner.y;
      v87 = *(_QWORD *)&v6->m_nwCorner.x;
      v89.x = v6->m_seCorner.x - *(float *)&v87;
      v88 = z;
      v89.y = y - *((float *)&v87 + 1);
      v89.z = 0.0;
      *(float *)&k = VectorNormalize(vec: &v89);
      v9 = 0.0;
      v110 = 0.0;
      for ( j = *(float *)&k - 1.0; j > v9; v110 = v9 )
      {
        v10 = v9 + 0.5;
        v120.y = *((float *)&v87 + 1) + (float)(v89.y * v10);
        v120.x = *(float *)&v87 + (float)(v89.x * v10);
        x.x = v120.x;
        v120.z = (float)(v88 + (float)(v10 * v89.z)) + 35.5;
        x.z = v120.z;
        *(float *)&v81 = v120.y - 12.5;
        x.y = v120.y - 12.5;
        NavArea = CNavMesh::GetNavArea(this: TheNavMesh, pos: &x, beneathLimit: 120.0);
        v12 = NavArea;
        if ( NavArea == nullptr || CNavArea::HasNodes(this: NavArea) != 0 )
        {
          v120.z = (float)(v120.z - 35.5) + 1.0;
          v115 = v120.z + 35.5;
          v114 = __PAIR64__(v81, LODWORD(v120.x));
          *(_QWORD *)&v118.x = __PAIR64__(v81, LODWORD(v120.x));
          v118.z = v120.z + 35.5;
          for ( k = 1; k <= 4; ++k )
          {
            v118.y = v118.y - 25.0;
            v13 = ((int (__thiscall *)(CNavMesh *, float *, int, CTraceFilterSimple_vtbl *, const IHandleEntity *))TheNavMesh->GetGenerationTraceMask)(
                    a1: TheNavMesh,
                    a2: a3,
                    a3: a4,
                    a4: v59.__vftable,
                    a5: v59.m_pPassEnt);
            v92 = v118.y - *((float *)&v114 + 1);
            v91 = v118.x - v120.x;
            v93 = v118.z - v115;
            v14 = v13;
            v100 = 0;
            v102 = (float)((float)((float)(v92 * v92) + (float)(v91 * v91)) + (float)(v93 * v93)) != 0.0;
            v98 = (float)(NavTraceMaxs.y - NavTraceMins.y) * 0.5;
            v97 = (float)(NavTraceMaxs.x - NavTraceMins.x) * 0.5;
            v99 = (float)(NavTraceMaxs.z - NavTraceMins.z) * 0.5;
            v101 = (float)((float)((float)(v98 * v98) + (float)(v97 * v97)) + (float)(v99 * v99)) < 0.000001;
            v15 = (float)(NavTraceMins.x + NavTraceMaxs.x) * 0.5;
            v16 = (float)(NavTraceMins.y + NavTraceMaxs.y) * 0.5;
            v17 = 0.5 * (float)(NavTraceMins.z + NavTraceMaxs.z);
            v90[0] = v15 + v120.x;
            v90[1] = v16 + *((float *)&v114 + 1);
            v90[2] = v17 + v115;
            v94 = v15 * -1.0;
            v95 = v16 * -1.0;
            v96 = v17 * -1.0;
            CTraceFilterSimple::CTraceFilterSimple(
              this: &v61,
              passedict: nullptr,
              collisionGroup: 0,
              pExtraShouldHitFunc: nullptr);
            TraceRay = enginetrace->TraceRay;
            v59.m_pPassEnt = (const IHandleEntity *)&v62;
            v59.__vftable = (CTraceFilterSimple_vtbl *)&v61;
            a4 = v14;
            a3 = v90;
            ((void (__thiscall *)(IEngineTrace *))TraceRay)(a1: enginetrace);
            if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
              DebugDrawLine(vecAbsStart: &v62, vecAbsEnd: v63, r: 255, g: 255, b: 0, test: 1, duration: -1.0);
            if ( v64 < 1.0 )
              break;
            v19 = CNavMesh::GetNavArea(this: TheNavMesh, pos: &v118, beneathLimit: 200.0);
            v20 = v19;
            if ( v19 != nullptr )
            {
              v66.x = v118.x;
              v66.y = v118.y;
              v66.z = CNavArea::GetZ(this: v19, x: v118.x, y: v118.y);
              if ( testJumpDown(fromPos: &v120, toPos: &v66) && v20 != v6 && CNavArea::HasNodes(this: v20) == 0 )
                CNavArea::ConnectTo(this: v6, area: v20, dir: NORTH);
              break;
            }
          }
        }
        else
        {
          x.z = CNavArea::GetZ(this: v12, x: x.x, y: x.y) + 35.5;
          if ( testStitchConnection(sourcePos: &v120, targetPos: &x) )
            CNavArea::ConnectTo(this: v6, area: v12, dir: NORTH);
          if ( testStitchConnection(sourcePos: &x, targetPos: &v120) )
          {
            beneathLimit = OppositeDirection(dir: NORTH);
            CNavArea::ConnectTo(this: v12, area: v6, dir: beneathLimit);
          }
        }
        v9 = v110 + 25.0;
      }
      v21 = v6->m_nwCorner.x;
      v22 = v6->m_seCorner.y;
      v23 = v6->m_seCorner.z;
      m_swZ = v6->m_swZ;
      v70 = *(_QWORD *)&v6->m_seCorner.x;
      v76 = v21;
      v77 = v22;
      v71 = v23;
      v85.x = *(float *)&v70 - v21;
      v85.y = *((float *)&v70 + 1) - v22;
      v85.z = 0.0;
      *(float *)&k = VectorNormalize(vec: &v85);
      v24 = 0.0;
      v105 = 0.0;
      for ( m = *(float *)&k - 1.0; m > v24; v105 = v24 )
      {
        v25 = v24 + 0.5;
        v121.x = (float)(v85.x * v25) + v76;
        v121.y = v77 + (float)(v25 * v85.y);
        v106.x = v121.x;
        v121.z = (float)(m_swZ + (float)(v25 * v85.z)) + 35.5;
        v106.z = v121.z;
        *(float *)&v74 = v121.y + 12.5;
        v106.y = v121.y + 12.5;
        v26 = CNavMesh::GetNavArea(this: TheNavMesh, pos: &v106, beneathLimit: 120.0);
        v27 = v26;
        if ( v26 == nullptr || CNavArea::HasNodes(this: v26) != 0 )
        {
          v121.z = (float)(v121.z - 35.5) + 1.0;
          v104 = v121.z + 35.5;
          v103 = __PAIR64__(v74, LODWORD(v121.x));
          *(_QWORD *)&v117.x = __PAIR64__(v74, LODWORD(v121.x));
          v117.z = v121.z + 35.5;
          for ( n = 1; n <= 4; ++n )
          {
            v117.y = v117.y + 25.0;
            v30 = ((int (__thiscall *)(CNavMesh *, float *, int, CTraceFilterSimple_vtbl *, const IHandleEntity *))TheNavMesh->GetGenerationTraceMask)(
                    a1: TheNavMesh,
                    a2: a3,
                    a3: a4,
                    a4: v59.__vftable,
                    a5: v59.m_pPassEnt);
            v92 = v117.y - *((float *)&v103 + 1);
            v91 = v117.x - v121.x;
            v93 = v117.z - v104;
            v31 = v30;
            v100 = 0;
            v102 = (float)((float)((float)(v92 * v92) + (float)(v91 * v91)) + (float)(v93 * v93)) != 0.0;
            v98 = (float)(NavTraceMaxs.y - NavTraceMins.y) * 0.5;
            v97 = (float)(NavTraceMaxs.x - NavTraceMins.x) * 0.5;
            v99 = (float)(NavTraceMaxs.z - NavTraceMins.z) * 0.5;
            v101 = (float)((float)((float)(v98 * v98) + (float)(v97 * v97)) + (float)(v99 * v99)) < 0.000001;
            v32 = (float)(NavTraceMins.x + NavTraceMaxs.x) * 0.5;
            v33 = (float)(NavTraceMins.y + NavTraceMaxs.y) * 0.5;
            v34 = 0.5 * (float)(NavTraceMins.z + NavTraceMaxs.z);
            v90[0] = v121.x + v32;
            v90[1] = *((float *)&v103 + 1) + v33;
            v90[2] = v104 + v34;
            v94 = v32 * -1.0;
            v95 = v33 * -1.0;
            v96 = v34 * -1.0;
            CTraceFilterSimple::CTraceFilterSimple(
              this: &v60,
              passedict: nullptr,
              collisionGroup: 0,
              pExtraShouldHitFunc: nullptr);
            v35 = enginetrace->TraceRay;
            v59.m_pPassEnt = (const IHandleEntity *)&v62;
            v59.__vftable = (CTraceFilterSimple_vtbl *)&v60;
            a4 = v31;
            a3 = v90;
            ((void (__thiscall *)(IEngineTrace *))v35)(a1: enginetrace);
            if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
              DebugDrawLine(vecAbsStart: &v62, vecAbsEnd: v63, r: 255, g: 255, b: 0, test: 1, duration: -1.0);
            if ( v64 < 1.0 )
              break;
            v36 = CNavMesh::GetNavArea(this: TheNavMesh, pos: &v117, beneathLimit: 200.0);
            v37 = v36;
            if ( v36 != nullptr )
            {
              v65.x = v117.x;
              v65.y = v117.y;
              v65.z = CNavArea::GetZ(this: v36, x: v117.x, y: v117.y);
              if ( testJumpDown(fromPos: &v121, toPos: &v65) && v37 != v123 && CNavArea::HasNodes(this: v37) == 0 )
                CNavArea::ConnectTo(this: v123, area: v37, dir: SOUTH);
              break;
            }
          }
          v6 = v123;
        }
        else
        {
          v106.z = CNavArea::GetZ(this: v27, x: v106.x, y: v106.y) + 35.5;
          if ( testStitchConnection(sourcePos: &v121, targetPos: &v106) )
            CNavArea::ConnectTo(this: v6, area: v27, dir: SOUTH);
          if ( testStitchConnection(sourcePos: &v106, targetPos: &v121) )
          {
            v28 = OppositeDirection(dir: SOUTH);
            CNavArea::ConnectTo(this: v27, area: v6, dir: v28);
          }
        }
        v24 = v105 + 25.0;
      }
      v38 = v6->m_seCorner.x;
      v39 = v6->m_nwCorner.y;
      v40 = v6->m_seCorner.z;
      m_neZ = v6->m_neZ;
      v67 = *(_QWORD *)&v6->m_seCorner.x;
      v82 = v38;
      v83 = v39;
      v68 = v40;
      v86.x = *(float *)&v67 - v38;
      v86.y = *((float *)&v67 + 1) - v39;
      v86.z = 0.0;
      *(float *)&k = VectorNormalize(vec: &v86);
      v41 = 0.0;
      v107 = 0.0;
      for ( ii = *(float *)&k - 1.0; ii > v41; v107 = v41 )
      {
        v42 = v41 + 0.5;
        v119.z = (float)((float)(v86.z * v42) + m_neZ) + 35.5;
        v119.x = (float)(v86.x * v42) + v82;
        v119.y = (float)(v86.y * v42) + v83;
        v109.y = v119.y;
        v109.z = v119.z;
        *(float *)&v79 = v119.x + 12.5;
        v109.x = v119.x + 12.5;
        v43 = CNavMesh::GetNavArea(this: TheNavMesh, pos: &v109, beneathLimit: 120.0);
        v44 = v43;
        if ( v43 == nullptr || CNavArea::HasNodes(this: v43) != 0 )
        {
          v119.z = (float)(v119.z - 35.5) + 1.0;
          *(float *)&it = v119.z + 35.5;
          v112 = __PAIR64__(LODWORD(v119.y), v79);
          *(_QWORD *)&v116.x = __PAIR64__(LODWORD(v119.y), v79);
          v116.z = v119.z + 35.5;
          for ( jj = 1; jj <= 4; ++jj )
          {
            v116.x = v116.x + 25.0;
            v47 = ((int (__thiscall *)(CNavMesh *, float *, int, CTraceFilterSimple_vtbl *, const IHandleEntity *))TheNavMesh->GetGenerationTraceMask)(
                    a1: TheNavMesh,
                    a2: a3,
                    a3: a4,
                    a4: v59.__vftable,
                    a5: v59.m_pPassEnt);
            v92 = v116.y - v119.y;
            v91 = v116.x - *(float *)&v112;
            v93 = v116.z - *(float *)&it;
            v48 = v47;
            v100 = 0;
            v102 = (float)((float)((float)(v92 * v92) + (float)(v91 * v91)) + (float)(v93 * v93)) != 0.0;
            v98 = (float)(NavTraceMaxs.y - NavTraceMins.y) * 0.5;
            v97 = (float)(NavTraceMaxs.x - NavTraceMins.x) * 0.5;
            v99 = (float)(NavTraceMaxs.z - NavTraceMins.z) * 0.5;
            v101 = (float)((float)((float)(v98 * v98) + (float)(v97 * v97)) + (float)(v99 * v99)) < 0.000001;
            v49 = (float)(NavTraceMins.x + NavTraceMaxs.x) * 0.5;
            v50 = (float)(NavTraceMins.y + NavTraceMaxs.y) * 0.5;
            v51 = 0.5 * (float)(NavTraceMins.z + NavTraceMaxs.z);
            v90[0] = v49 + *(float *)&v112;
            v90[1] = v119.y + v50;
            v90[2] = *(float *)&it + v51;
            v94 = v49 * -1.0;
            v95 = v50 * -1.0;
            v96 = v51 * -1.0;
            CTraceFilterSimple::CTraceFilterSimple(
              this: &v59,
              passedict: nullptr,
              collisionGroup: 0,
              pExtraShouldHitFunc: nullptr);
            v52 = enginetrace->TraceRay;
            v59.m_pPassEnt = (const IHandleEntity *)&v62;
            v59.__vftable = (CTraceFilterSimple_vtbl *)&v59;
            a4 = v48;
            a3 = v90;
            ((void (__thiscall *)(IEngineTrace *))v52)(a1: enginetrace);
            if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
              DebugDrawLine(vecAbsStart: &v62, vecAbsEnd: v63, r: 255, g: 255, b: 0, test: 1, duration: -1.0);
            if ( v64 < 1.0 )
              break;
            v53 = CNavMesh::GetNavArea(this: TheNavMesh, pos: &v116, beneathLimit: 200.0);
            v54 = v53;
            if ( v53 != nullptr )
            {
              v69.x = v116.x;
              v69.y = v116.y;
              v69.z = CNavArea::GetZ(this: v53, x: v116.x, y: v116.y);
              if ( testJumpDown(fromPos: &v119, toPos: &v69) && v54 != v123 && CNavArea::HasNodes(this: v54) == 0 )
                CNavArea::ConnectTo(this: v123, area: v54, dir: EAST);
              break;
            }
          }
          v6 = v123;
        }
        else
        {
          v109.z = CNavArea::GetZ(this: v44, x: v109.x, y: v109.y) + 35.5;
          if ( testStitchConnection(sourcePos: &v119, targetPos: &v109) )
            CNavArea::ConnectTo(this: v6, area: v44, dir: EAST);
          if ( testStitchConnection(sourcePos: &v109, targetPos: &v119) )
          {
            v45 = OppositeDirection(dir: EAST);
            CNavArea::ConnectTo(this: v44, area: v6, dir: v45);
          }
        }
        v41 = v107 + 25.0;
      }
      CNavMesh::StitchAreaIntoMesh<IncrementallyGeneratedAreas>(this: v73, area: v6, dir: WEST, func);
      v5 = i;
    }
    ++v5;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10315570
// Name: public: bool CNavMesh::StitchMesh<class AreaSet>(class AreaSet __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CNavMesh::StitchMesh<AreaSet>@<al>(
        CNavMesh *this@<ecx>,
        int a2@<ebp>,
        float *a3@<edi>,
        int a4@<esi>,
        AreaSet *func)
{
  int v5; // edi
  CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > *m_areas; // edx
  CNavArea *v7; // esi
  int m_Size; // ecx
  int v9; // eax
  CNavArea **m_pMemory; // edx
  float z; // edx
  float y; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  CNavArea *NavArea; // esi
  int v16; // ecx
  int v17; // eax
  CNavArea **v18; // edx
  int k; // edi
  int v20; // eax
  int v21; // esi
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm0_4
  void (__thiscall *TraceRay)(IEngineTrace *, const Ray_t *, unsigned int, ITraceFilter *, CGameTrace *); // eax
  CNavArea *v26; // eax
  CNavArea *v27; // esi
  int v28; // ecx
  int v29; // eax
  CNavArea **v30; // edx
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // ecx
  float v34; // xmm0_4
  float v35; // xmm0_4
  CNavArea *v36; // esi
  int v37; // ecx
  int v38; // eax
  CNavArea **v39; // edx
  int n; // edi
  int v41; // eax
  int v42; // esi
  float v43; // xmm1_4
  float v44; // xmm2_4
  float v45; // xmm0_4
  void (__thiscall *v46)(IEngineTrace *, const Ray_t *, unsigned int, ITraceFilter *, CGameTrace *); // edx
  CNavArea *v47; // eax
  CNavArea *v48; // esi
  int v49; // ecx
  int v50; // eax
  CNavArea **v51; // edx
  float v52; // xmm1_4
  float v53; // xmm2_4
  float v54; // eax
  float v55; // xmm1_4
  float v56; // xmm1_4
  CNavArea *v57; // esi
  int v58; // ecx
  int v59; // eax
  CNavArea **v60; // edx
  int jj; // edi
  int v62; // eax
  int v63; // esi
  float v64; // xmm1_4
  float v65; // xmm2_4
  float v66; // xmm0_4
  void (__thiscall *v67)(IEngineTrace *, const Ray_t *, unsigned int, ITraceFilter *, CGameTrace *); // edx
  CNavArea *v68; // eax
  CNavArea *v69; // esi
  int v70; // ecx
  int v71; // eax
  CNavArea **v72; // edx
  NavDirType beneathLimit; // [esp+34h] [ebp-240h]
  NavDirType beneathLimita; // [esp+34h] [ebp-240h]
  NavDirType beneathLimitb; // [esp+34h] [ebp-240h]
  CTraceFilterSimple v79; // [esp+40h] [ebp-234h] BYREF
  CTraceFilterSimple v80; // [esp+50h] [ebp-224h] BYREF
  CTraceFilterSimple v81; // [esp+60h] [ebp-214h] BYREF
  Vector v82; // [esp+70h] [ebp-204h] BYREF
  Vector v83[2]; // [esp+7Ch] [ebp-1F8h] BYREF
  float v84; // [esp+9Ch] [ebp-1D8h]
  Vector v85; // [esp+C8h] [ebp-1ACh] BYREF
  Vector v86; // [esp+D4h] [ebp-1A0h] BYREF
  __int64 v87; // [esp+E0h] [ebp-194h]
  float v88; // [esp+E8h] [ebp-18Ch]
  Vector v89; // [esp+ECh] [ebp-188h] BYREF
  __int64 v90; // [esp+F8h] [ebp-17Ch]
  float v91; // [esp+100h] [ebp-174h]
  float m; // [esp+104h] [ebp-170h]
  CNavMesh *v93; // [esp+108h] [ebp-16Ch]
  unsigned int v94; // [esp+10Ch] [ebp-168h]
  float ii; // [esp+110h] [ebp-164h]
  float v96; // [esp+114h] [ebp-160h]
  float v97; // [esp+118h] [ebp-15Ch]
  float m_swZ; // [esp+11Ch] [ebp-158h]
  unsigned int v99; // [esp+120h] [ebp-154h]
  float j; // [esp+124h] [ebp-150h]
  unsigned int v101; // [esp+128h] [ebp-14Ch]
  float v102; // [esp+12Ch] [ebp-148h]
  float v103; // [esp+130h] [ebp-144h]
  float m_neZ; // [esp+134h] [ebp-140h]
  Vector v105; // [esp+138h] [ebp-13Ch] BYREF
  Vector v106; // [esp+144h] [ebp-130h] BYREF
  __int64 v107; // [esp+150h] [ebp-124h]
  float v108; // [esp+158h] [ebp-11Ch]
  Vector v109; // [esp+15Ch] [ebp-118h] BYREF
  float v110[4]; // [esp+168h] [ebp-10Ch] BYREF
  float v111; // [esp+178h] [ebp-FCh]
  float v112; // [esp+17Ch] [ebp-F8h]
  float v113; // [esp+180h] [ebp-F4h]
  float v114; // [esp+188h] [ebp-ECh]
  float v115; // [esp+18Ch] [ebp-E8h]
  float v116; // [esp+190h] [ebp-E4h]
  float v117; // [esp+198h] [ebp-DCh]
  float v118; // [esp+19Ch] [ebp-D8h]
  float v119; // [esp+1A0h] [ebp-D4h]
  int v120; // [esp+1A8h] [ebp-CCh]
  bool v121; // [esp+1ACh] [ebp-C8h]
  bool v122; // [esp+1ADh] [ebp-C7h]
  unsigned __int64 v123; // [esp+1C0h] [ebp-B4h]
  float v124; // [esp+1C8h] [ebp-ACh]
  float v125; // [esp+1CCh] [ebp-A8h]
  Vector v126; // [esp+1D0h] [ebp-A4h] BYREF
  int i; // [esp+1DCh] [ebp-98h]
  float x; // [esp+1E0h] [ebp-94h] BYREF
  float v129; // [esp+1E4h] [ebp-90h]
  int it; // [esp+1E8h] [ebp-8Ch]
  Vector v131; // [esp+1ECh] [ebp-88h] BYREF
  float v132; // [esp+1F8h] [ebp-7Ch]
  float v133; // [esp+1FCh] [ebp-78h]
  unsigned __int64 v134; // [esp+200h] [ebp-74h]
  float v135; // [esp+208h] [ebp-6Ch]
  unsigned __int64 v136; // [esp+20Ch] [ebp-68h]
  float v137; // [esp+214h] [ebp-60h]
  Vector v138; // [esp+218h] [ebp-5Ch] BYREF
  Vector v139; // [esp+224h] [ebp-50h] BYREF
  Vector v140; // [esp+230h] [ebp-44h] BYREF
  Vector v141; // [esp+23Ch] [ebp-38h] BYREF
  Vector v142; // [esp+248h] [ebp-2Ch] BYREF
  Vector v143; // [esp+254h] [ebp-20h] BYREF
  float v144; // [esp+260h] [ebp-14h]
  CNavArea *v145; // [esp+264h] [ebp-10h]
  int v146; // [esp+268h] [ebp-Ch]
  void *v147; // [esp+26Ch] [ebp-8h]
  void *retaddr; // [esp+274h] [ebp+0h]

  v146 = a2;
  v147 = retaddr;
  v5 = 0;
  v93 = this;
  for ( i = 0; v5 < TheNavAreas.m_Size; i = v5 )
  {
    m_areas = func->m_areas;
    v7 = TheNavAreas.m_Memory.m_pMemory[v5];
    m_Size = func->m_areas->m_Size;
    v9 = 0;
    v145 = v7;
    if ( m_Size > 0 )
    {
      m_pMemory = m_areas->m_Memory.m_pMemory;
      while ( *m_pMemory != v7 )
      {
        ++v9;
        ++m_pMemory;
        if ( v9 >= m_Size )
          goto LABEL_99;
      }
      if ( v9 >= 0 )
      {
        z = v7->m_nwCorner.z;
        y = v7->m_nwCorner.y;
        v107 = *(_QWORD *)&v7->m_nwCorner.x;
        v109.x = v7->m_seCorner.x - *(float *)&v107;
        v108 = z;
        v109.y = y - *((float *)&v107 + 1);
        v109.z = 0.0;
        v144 = VectorNormalize(vec: &v109);
        v13 = 0.0;
        v133 = 0.0;
        for ( j = v144 - 1.0; j > v13; v133 = v13 )
        {
          v14 = v13 + 0.5;
          v142.y = *((float *)&v107 + 1) + (float)(v109.y * v14);
          v142.z = (float)(v108 + (float)(v14 * v109.z)) + 35.5;
          v142.x = *(float *)&v107 + (float)(v109.x * v14);
          x = v142.x;
          it = SLODWORD(v142.z);
          *(float *)&v101 = v142.y - 12.5;
          v129 = v142.y - 12.5;
          NavArea = CNavMesh::GetNavArea(this: TheNavMesh, pos: (const Vector *)&x, beneathLimit: 120.0);
          if ( NavArea == nullptr )
            goto LABEL_20;
          v16 = func->m_areas->m_Size;
          v17 = 0;
          if ( v16 <= 0 )
            goto LABEL_16;
          v18 = func->m_areas->m_Memory.m_pMemory;
          while ( *v18 != NavArea )
          {
            ++v17;
            ++v18;
            if ( v17 >= v16 )
              goto LABEL_16;
          }
          if ( v17 < 0 )
          {
LABEL_16:
            *(float *)&it = CNavArea::GetZ(this: NavArea, x, y: v129) + 35.5;
            if ( testStitchConnection(sourcePos: &v142, targetPos: (const Vector *)&x) )
              CNavArea::ConnectTo(this: v145, area: NavArea, dir: NORTH);
            if ( testStitchConnection(sourcePos: (const Vector *)&x, targetPos: &v142) )
            {
              beneathLimit = OppositeDirection(dir: NORTH);
              CNavArea::ConnectTo(this: NavArea, area: v145, dir: beneathLimit);
            }
          }
          else
          {
LABEL_20:
            v142.z = (float)(v142.z - 35.5) + 1.0;
            v137 = v142.z + 35.5;
            v136 = __PAIR64__(v101, LODWORD(v142.x));
            *(_QWORD *)&v140.x = __PAIR64__(v101, LODWORD(v142.x));
            v140.z = v142.z + 35.5;
            for ( k = 1; k <= 4; ++k )
            {
              v140.y = v140.y - 25.0;
              v20 = ((int (__thiscall *)(CNavMesh *, float *, int, CTraceFilterSimple_vtbl *, const IHandleEntity *))TheNavMesh->GetGenerationTraceMask)(
                      a1: TheNavMesh,
                      a2: a3,
                      a3: a4,
                      a4: v79.__vftable,
                      a5: v79.m_pPassEnt);
              v112 = v140.y - *((float *)&v136 + 1);
              v111 = v140.x - v142.x;
              v113 = v140.z - v137;
              v21 = v20;
              v120 = 0;
              v122 = (float)((float)((float)(v112 * v112) + (float)(v111 * v111)) + (float)(v113 * v113)) != 0.0;
              v118 = (float)(NavTraceMaxs.y - NavTraceMins.y) * 0.5;
              v117 = (float)(NavTraceMaxs.x - NavTraceMins.x) * 0.5;
              v119 = (float)(NavTraceMaxs.z - NavTraceMins.z) * 0.5;
              v121 = (float)((float)((float)(v118 * v118) + (float)(v117 * v117)) + (float)(v119 * v119)) < 0.000001;
              v22 = (float)(NavTraceMins.x + NavTraceMaxs.x) * 0.5;
              v23 = (float)(NavTraceMins.y + NavTraceMaxs.y) * 0.5;
              v24 = 0.5 * (float)(NavTraceMins.z + NavTraceMaxs.z);
              v110[0] = v22 + v142.x;
              v110[1] = v23 + *((float *)&v136 + 1);
              v110[2] = v24 + v137;
              v114 = v22 * -1.0;
              v115 = v23 * -1.0;
              v116 = v24 * -1.0;
              CTraceFilterSimple::CTraceFilterSimple(
                this: &v81,
                passedict: nullptr,
                collisionGroup: 0,
                pExtraShouldHitFunc: nullptr);
              TraceRay = enginetrace->TraceRay;
              v79.m_pPassEnt = (const IHandleEntity *)&v82;
              v79.__vftable = (CTraceFilterSimple_vtbl *)&v81;
              a4 = v21;
              a3 = v110;
              ((void (__thiscall *)(IEngineTrace *))TraceRay)(a1: enginetrace);
              if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
                DebugDrawLine(vecAbsStart: &v82, vecAbsEnd: v83, r: 255, g: 255, b: 0, test: 1, duration: -1.0);
              if ( v84 < 1.0 )
                break;
              v26 = CNavMesh::GetNavArea(this: TheNavMesh, pos: &v140, beneathLimit: 200.0);
              v27 = v26;
              if ( v26 != nullptr )
              {
                v86.x = v140.x;
                v86.y = v140.y;
                v86.z = CNavArea::GetZ(this: v26, x: v140.x, y: v140.y);
                if ( testJumpDown(fromPos: &v142, toPos: &v86) && v27 != v145 )
                {
                  v28 = func->m_areas->m_Size;
                  v29 = 0;
                  if ( v28 <= 0 )
                    goto LABEL_36;
                  v30 = func->m_areas->m_Memory.m_pMemory;
                  while ( *v30 != v27 )
                  {
                    ++v29;
                    ++v30;
                    if ( v29 >= v28 )
                      goto LABEL_36;
                  }
                  if ( v29 < 0 )
LABEL_36:
                    CNavArea::ConnectTo(this: v145, area: v27, dir: NORTH);
                }
                break;
              }
            }
          }
          v13 = v133 + 25.0;
        }
        v31 = v145->m_nwCorner.x;
        v32 = v145->m_seCorner.y;
        v33 = v145->m_seCorner.z;
        m_swZ = v145->m_swZ;
        v90 = *(_QWORD *)&v145->m_seCorner.x;
        v96 = v31;
        v97 = v32;
        v91 = v33;
        v105.x = *(float *)&v90 - v31;
        v105.y = *((float *)&v90 + 1) - v32;
        v105.z = 0.0;
        v144 = VectorNormalize(vec: &v105);
        v34 = 0.0;
        v132 = 0.0;
        for ( m = v144 - 1.0; m > v34; v132 = v34 )
        {
          v35 = v34 + 0.5;
          v143.x = (float)(v105.x * v35) + v96;
          v143.y = v97 + (float)(v35 * v105.y);
          v126.x = v143.x;
          v143.z = (float)(m_swZ + (float)(v35 * v105.z)) + 35.5;
          v126.z = v143.z;
          *(float *)&v94 = v143.y + 12.5;
          v126.y = v143.y + 12.5;
          v36 = CNavMesh::GetNavArea(this: TheNavMesh, pos: &v126, beneathLimit: 120.0);
          if ( v36 == nullptr )
            goto LABEL_50;
          v37 = func->m_areas->m_Size;
          v38 = 0;
          if ( v37 <= 0 )
            goto LABEL_46;
          v39 = func->m_areas->m_Memory.m_pMemory;
          while ( *v39 != v36 )
          {
            ++v38;
            ++v39;
            if ( v38 >= v37 )
              goto LABEL_46;
          }
          if ( v38 < 0 )
          {
LABEL_46:
            v126.z = CNavArea::GetZ(this: v36, x: v126.x, y: v126.y) + 35.5;
            if ( testStitchConnection(sourcePos: &v143, targetPos: &v126) )
              CNavArea::ConnectTo(this: v145, area: v36, dir: SOUTH);
            if ( testStitchConnection(sourcePos: &v126, targetPos: &v143) )
            {
              beneathLimita = OppositeDirection(dir: SOUTH);
              CNavArea::ConnectTo(this: v36, area: v145, dir: beneathLimita);
            }
          }
          else
          {
LABEL_50:
            v143.z = (float)(v143.z - 35.5) + 1.0;
            v124 = v143.z + 35.5;
            v123 = __PAIR64__(v94, LODWORD(v143.x));
            *(_QWORD *)&v139.x = __PAIR64__(v94, LODWORD(v143.x));
            v139.z = v143.z + 35.5;
            for ( n = 1; n <= 4; ++n )
            {
              v139.y = v139.y + 25.0;
              v41 = ((int (__thiscall *)(CNavMesh *, float *, int, CTraceFilterSimple_vtbl *, const IHandleEntity *))TheNavMesh->GetGenerationTraceMask)(
                      a1: TheNavMesh,
                      a2: a3,
                      a3: a4,
                      a4: v79.__vftable,
                      a5: v79.m_pPassEnt);
              v112 = v139.y - *((float *)&v123 + 1);
              v111 = v139.x - v143.x;
              v113 = v139.z - v124;
              v42 = v41;
              v120 = 0;
              v122 = (float)((float)((float)(v112 * v112) + (float)(v111 * v111)) + (float)(v113 * v113)) != 0.0;
              v117 = (float)(NavTraceMaxs.x - NavTraceMins.x) * 0.5;
              v118 = (float)(NavTraceMaxs.y - NavTraceMins.y) * 0.5;
              v119 = (float)(NavTraceMaxs.z - NavTraceMins.z) * 0.5;
              v121 = (float)((float)((float)(v117 * v117) + (float)(v118 * v118)) + (float)(v119 * v119)) < 0.000001;
              v43 = (float)(NavTraceMins.x + NavTraceMaxs.x) * 0.5;
              v44 = (float)(NavTraceMins.y + NavTraceMaxs.y) * 0.5;
              v45 = 0.5 * (float)(NavTraceMins.z + NavTraceMaxs.z);
              v110[0] = v143.x + v43;
              v110[1] = v44 + *((float *)&v123 + 1);
              v110[2] = v45 + v124;
              v114 = v43 * -1.0;
              v115 = v44 * -1.0;
              v116 = v45 * -1.0;
              CTraceFilterSimple::CTraceFilterSimple(
                this: &v80,
                passedict: nullptr,
                collisionGroup: 0,
                pExtraShouldHitFunc: nullptr);
              v46 = enginetrace->TraceRay;
              v79.m_pPassEnt = (const IHandleEntity *)&v82;
              v79.__vftable = (CTraceFilterSimple_vtbl *)&v80;
              a4 = v42;
              a3 = v110;
              ((void (__thiscall *)(IEngineTrace *))v46)(a1: enginetrace);
              if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
                DebugDrawLine(vecAbsStart: &v82, vecAbsEnd: v83, r: 255, g: 255, b: 0, test: 1, duration: -1.0);
              if ( v84 < 1.0 )
                break;
              v47 = CNavMesh::GetNavArea(this: TheNavMesh, pos: &v139, beneathLimit: 200.0);
              v48 = v47;
              if ( v47 != nullptr )
              {
                v85.x = v139.x;
                v85.y = v139.y;
                v85.z = CNavArea::GetZ(this: v47, x: v139.x, y: v139.y);
                if ( testJumpDown(fromPos: &v143, toPos: &v85) && v48 != v145 )
                {
                  v49 = func->m_areas->m_Size;
                  v50 = 0;
                  if ( v49 <= 0 )
                    goto LABEL_66;
                  v51 = func->m_areas->m_Memory.m_pMemory;
                  while ( *v51 != v48 )
                  {
                    ++v50;
                    ++v51;
                    if ( v50 >= v49 )
                      goto LABEL_66;
                  }
                  if ( v50 < 0 )
LABEL_66:
                    CNavArea::ConnectTo(this: v145, area: v48, dir: SOUTH);
                }
                break;
              }
            }
          }
          v34 = v132 + 25.0;
        }
        v52 = v145->m_seCorner.x;
        v53 = v145->m_nwCorner.y;
        m_neZ = v145->m_neZ;
        v54 = v145->m_seCorner.z;
        v87 = *(_QWORD *)&v145->m_seCorner.x;
        v102 = v52;
        v103 = v53;
        v88 = v54;
        v106.x = *(float *)&v87 - v52;
        v106.y = *((float *)&v87 + 1) - v53;
        v106.z = 0.0;
        v144 = VectorNormalize(vec: &v106);
        v55 = 0.0;
        v125 = 0.0;
        for ( ii = v144 - 1.0; ii > v55; v125 = v55 )
        {
          v56 = v55 + 0.5;
          v141.z = (float)((float)(v106.z * v56) + m_neZ) + 35.5;
          v141.x = (float)(v106.x * v56) + v102;
          v141.y = (float)(v106.y * v56) + v103;
          v131.y = v141.y;
          v131.z = v141.z;
          *(float *)&v99 = v141.x + 12.5;
          v131.x = v141.x + 12.5;
          v57 = CNavMesh::GetNavArea(this: TheNavMesh, pos: &v131, beneathLimit: 120.0);
          if ( v57 == nullptr )
            goto LABEL_80;
          v58 = func->m_areas->m_Size;
          v59 = 0;
          if ( v58 <= 0 )
            goto LABEL_76;
          v60 = func->m_areas->m_Memory.m_pMemory;
          while ( *v60 != v57 )
          {
            ++v59;
            ++v60;
            if ( v59 >= v58 )
              goto LABEL_76;
          }
          if ( v59 < 0 )
          {
LABEL_76:
            v131.z = CNavArea::GetZ(this: v57, x: v131.x, y: v131.y) + 35.5;
            if ( testStitchConnection(sourcePos: &v141, targetPos: &v131) )
              CNavArea::ConnectTo(this: v145, area: v57, dir: EAST);
            if ( testStitchConnection(sourcePos: &v131, targetPos: &v141) )
            {
              beneathLimitb = OppositeDirection(dir: EAST);
              CNavArea::ConnectTo(this: v57, area: v145, dir: beneathLimitb);
            }
          }
          else
          {
LABEL_80:
            v141.z = (float)(v141.z - 35.5) + 1.0;
            v135 = v141.z + 35.5;
            v134 = __PAIR64__(LODWORD(v141.y), v99);
            *(_QWORD *)&v138.x = __PAIR64__(LODWORD(v141.y), v99);
            v138.z = v141.z + 35.5;
            for ( jj = 1; jj <= 4; ++jj )
            {
              v138.x = v138.x + 25.0;
              v62 = ((int (__thiscall *)(CNavMesh *, float *, int, CTraceFilterSimple_vtbl *, const IHandleEntity *))TheNavMesh->GetGenerationTraceMask)(
                      a1: TheNavMesh,
                      a2: a3,
                      a3: a4,
                      a4: v79.__vftable,
                      a5: v79.m_pPassEnt);
              v112 = v138.y - v141.y;
              v111 = v138.x - *(float *)&v134;
              v113 = v138.z - v135;
              v63 = v62;
              v120 = 0;
              v122 = (float)((float)((float)(v112 * v112) + (float)(v111 * v111)) + (float)(v113 * v113)) != 0.0;
              v118 = (float)(NavTraceMaxs.y - NavTraceMins.y) * 0.5;
              v117 = (float)(NavTraceMaxs.x - NavTraceMins.x) * 0.5;
              v119 = (float)(NavTraceMaxs.z - NavTraceMins.z) * 0.5;
              v121 = (float)((float)((float)(v118 * v118) + (float)(v117 * v117)) + (float)(v119 * v119)) < 0.000001;
              v64 = (float)(NavTraceMins.x + NavTraceMaxs.x) * 0.5;
              v65 = (float)(NavTraceMins.y + NavTraceMaxs.y) * 0.5;
              v66 = 0.5 * (float)(NavTraceMins.z + NavTraceMaxs.z);
              v110[0] = v64 + *(float *)&v134;
              v110[1] = v65 + v141.y;
              v110[2] = v66 + v135;
              v114 = v64 * -1.0;
              v115 = v65 * -1.0;
              v116 = v66 * -1.0;
              CTraceFilterSimple::CTraceFilterSimple(
                this: &v79,
                passedict: nullptr,
                collisionGroup: 0,
                pExtraShouldHitFunc: nullptr);
              v67 = enginetrace->TraceRay;
              v79.m_pPassEnt = (const IHandleEntity *)&v82;
              v79.__vftable = (CTraceFilterSimple_vtbl *)&v79;
              a4 = v63;
              a3 = v110;
              ((void (__thiscall *)(IEngineTrace *))v67)(a1: enginetrace);
              if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
                DebugDrawLine(vecAbsStart: &v82, vecAbsEnd: v83, r: 255, g: 255, b: 0, test: 1, duration: -1.0);
              if ( v84 < 1.0 )
                break;
              v68 = CNavMesh::GetNavArea(this: TheNavMesh, pos: &v138, beneathLimit: 200.0);
              v69 = v68;
              if ( v68 != nullptr )
              {
                v89.x = v138.x;
                v89.y = v138.y;
                v89.z = CNavArea::GetZ(this: v68, x: v138.x, y: v138.y);
                if ( testJumpDown(fromPos: &v141, toPos: &v89) && v69 != v145 )
                {
                  v70 = func->m_areas->m_Size;
                  v71 = 0;
                  if ( v70 <= 0 )
                    goto LABEL_96;
                  v72 = func->m_areas->m_Memory.m_pMemory;
                  while ( *v72 != v69 )
                  {
                    ++v71;
                    ++v72;
                    if ( v71 >= v70 )
                      goto LABEL_96;
                  }
                  if ( v71 < 0 )
LABEL_96:
                    CNavArea::ConnectTo(this: v145, area: v69, dir: EAST);
                }
                break;
              }
            }
          }
          v55 = v125 + 25.0;
        }
        CNavMesh::StitchAreaIntoMesh<AreaSet>(this: v93, area: v145, dir: WEST, func);
        v5 = i;
      }
    }
LABEL_99:
    ++v5;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1031D490
// Name: public: bool CNavMesh::ForAllSelectedAreas<class BuildSelectedSet>(class BuildSelectedSet __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNavMesh::ForAllSelectedAreas<BuildSelectedSet>(CNavMesh *this, BuildSelectedSet *func)
{
  CNavMesh *v2; // esi
  CNavArea *m_selectedArea; // esi
  bool result; // al
  bool v5; // cc
  CNavArea *v7; // esi
  KeyValues *Key; // eax
  KeyValues *v9; // edi
  KeyValues *v10; // eax
  float z; // edx
  KeyValues *v12; // eax
  float x; // xmm0_4
  KeyValues *v14; // eax
  float v15; // xmm0_4
  KeyValues *v16; // eax
  float v17; // ecx
  CFmtStrN<32> v18; // [esp+10h] [ebp-64h] BYREF
  float v19; // [esp+40h] [ebp-34h]
  float m_swZ; // [esp+44h] [ebp-30h]
  float y; // [esp+4Ch] [ebp-28h]
  float m_neZ; // [esp+50h] [ebp-24h]
  __int64 v23; // [esp+54h] [ebp-20h]
  float v24; // [esp+5Ch] [ebp-18h]
  __int64 value; // [esp+60h] [ebp-14h]
  float v26; // [esp+68h] [ebp-Ch]
  CNavMesh *v27; // [esp+6Ch] [ebp-8h]
  int it; // [esp+70h] [ebp-4h]
  KeyValues *funca; // [esp+7Ch] [ebp+8h]
  KeyValues *funcb; // [esp+7Ch] [ebp+8h]
  KeyValues *funcc; // [esp+7Ch] [ebp+8h]
  KeyValues *funcd; // [esp+7Ch] [ebp+8h]

  v2 = this;
  v27 = this;
  if ( !CNavMesh::IsSelectedSetEmpty(this) )
  {
    v5 = v2->m_selectedSet.m_Size <= 0;
    it = 0;
    if ( !v5 )
    {
      while ( 1 )
      {
        v7 = v2->m_selectedSet.m_Memory.m_pMemory[it];
        CFmtStrN<32>::CFmtStrN<32>(this: &v18, pszFormat: "%d", v7->m_id);
        Key = KeyValues::FindKey(this: func->m_kv, keyName: v18.m_szBuf, bCreate: true);
        v9 = Key;
        if ( Key != nullptr )
        {
          ++func->m_areaCount;
          v10 = KeyValues::FindKey(this: Key, keyName: "NorthWest", bCreate: true);
          funca = v10;
          if ( v10 != nullptr )
          {
            z = v7->m_nwCorner.z;
            value = *(_QWORD *)&v7->m_nwCorner.x;
            v26 = z;
            KeyValues::SetFloat(this: v10, keyName: "x", value: *(float *)&value);
            KeyValues::SetFloat(this: funca, keyName: "y", value: *((float *)&value + 1));
            KeyValues::SetFloat(this: funca, keyName: "z", value: v26);
          }
          v12 = KeyValues::FindKey(this: v9, keyName: "NorthEast", bCreate: true);
          funcb = v12;
          if ( v12 != nullptr )
          {
            x = v7->m_seCorner.x;
            y = v7->m_nwCorner.y;
            m_neZ = v7->m_neZ;
            KeyValues::SetFloat(this: v12, keyName: "x", value: x);
            KeyValues::SetFloat(this: funcb, keyName: "y", value: y);
            KeyValues::SetFloat(this: funcb, keyName: "z", value: m_neZ);
          }
          v14 = KeyValues::FindKey(this: v9, keyName: "SouthWest", bCreate: true);
          funcc = v14;
          if ( v14 != nullptr )
          {
            v15 = v7->m_nwCorner.x;
            v19 = v7->m_seCorner.y;
            m_swZ = v7->m_swZ;
            KeyValues::SetFloat(this: v14, keyName: "x", value: v15);
            KeyValues::SetFloat(this: funcc, keyName: "y", value: v19);
            KeyValues::SetFloat(this: funcc, keyName: "z", value: m_swZ);
          }
          v16 = KeyValues::FindKey(this: v9, keyName: "SouthEast", bCreate: true);
          funcd = v16;
          if ( v16 != nullptr )
          {
            v17 = v7->m_seCorner.z;
            v23 = *(_QWORD *)&v7->m_seCorner.x;
            v24 = v17;
            KeyValues::SetFloat(this: v16, keyName: "x", value: *(float *)&v23);
            KeyValues::SetFloat(this: funcd, keyName: "y", value: *((float *)&v23 + 1));
            KeyValues::SetFloat(this: funcd, keyName: "z", value: v24);
          }
          BuildSelectedSet::WriteConnections(this: func, area: v7, areaKey: v9, dir: NORTH, dirName: "North");
          BuildSelectedSet::WriteConnections(this: func, area: v7, areaKey: v9, dir: SOUTH, dirName: "South");
          BuildSelectedSet::WriteConnections(this: func, area: v7, areaKey: v9, dir: EAST, dirName: "East");
          BuildSelectedSet::WriteConnections(this: func, area: v7, areaKey: v9, dir: WEST, dirName: "West");
          v7->SaveToSelectedSet(this: v7, a2: v9);
        }
        if ( ++it >= v27->m_selectedSet.m_Size )
          break;
        v2 = v27;
      }
    }
    return true;
  }
  m_selectedArea = v2->m_selectedArea;
  if ( m_selectedArea == nullptr )
    return true;
  result = BuildSelectedSet::operator()(this: func, area: m_selectedArea);
  if ( result )
    return true;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1031F780
// Name: public: bool CNavMesh::ForAllSelectedAreas<class NavAttributeClearer>(class NavAttributeClearer __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNavMesh::ForAllSelectedAreas<NavAttributeClearer>(CNavMesh *this, NavAttributeClearer *func)
{
  CNavArea *m_selectedArea; // esi
  int i; // eax
  CNavArea *v6; // ecx

  if ( CNavMesh::IsSelectedSetEmpty(this) )
  {
    m_selectedArea = this->m_selectedArea;
    if ( m_selectedArea != nullptr )
    {
      m_selectedArea->m_attributeFlags &= ~func->m_attribute;
      return 1;
    }
  }
  else
  {
    for ( i = 0; i < this->m_selectedSet.m_Size; ++i )
    {
      v6 = this->m_selectedSet.m_Memory.m_pMemory[i];
      v6->m_attributeFlags &= ~func->m_attribute;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1031F7F0
// Name: public: bool CNavMesh::ForAllSelectedAreas<class NavAttributeSetter>(class NavAttributeSetter __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNavMesh::ForAllSelectedAreas<NavAttributeSetter>(CNavMesh *this, NavAttributeSetter *func)
{
  CNavArea *m_selectedArea; // esi
  int i; // eax
  CNavArea *v6; // ecx

  if ( CNavMesh::IsSelectedSetEmpty(this) )
  {
    m_selectedArea = this->m_selectedArea;
    if ( m_selectedArea != nullptr )
    {
      m_selectedArea->m_attributeFlags |= func->m_attribute;
      return 1;
    }
  }
  else
  {
    for ( i = 0; i < this->m_selectedSet.m_Size; ++i )
    {
      v6 = this->m_selectedSet.m_Memory.m_pMemory[i];
      v6->m_attributeFlags |= func->m_attribute;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10324790
// Name: ReduceToComponentAreas
// Source: json
//------------------------------------------------------------------------------
char __cdecl ReduceToComponentAreas(CNavArea *area, bool addToSelectedSet)
{
  CNavArea *v2; // esi
  float v4; // xmm2_4
  float v5; // xmm0_4
  char v6; // cl
  float x; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  char v10; // al
  float y; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  char v14; // al
  bool v15; // bl
  float splitEdge; // [esp+20h] [ebp-10h]
  float splitEdgea; // [esp+20h] [ebp-10h]
  CNavArea *fourth; // [esp+24h] [ebp-Ch] BYREF
  CNavArea *third; // [esp+28h] [ebp-8h] BYREF
  CNavArea *second; // [esp+2Ch] [ebp-4h] BYREF

  v2 = area;
  if ( area == nullptr )
    return 0;
  v4 = area->m_seCorner.x - area->m_nwCorner.x;
  v5 = area->m_seCorner.y - area->m_nwCorner.y;
  v6 = 0;
  splitEdge = v5;
  area = nullptr;
  second = nullptr;
  third = nullptr;
  fourth = nullptr;
  if ( v4 > 25.0 )
  {
    x = v2->m_nwCorner.x;
    if ( x >= 0.0 )
      v8 = 12.5;
    else
      v8 = -12.5;
    v9 = (float)((int)(float)(v8 + x) / 25) * 25.0;
    if ( (float)(v2->m_nwCorner.x + 2.0) > v9 )
      v9 = v9 + 25.0;
    v10 = CNavArea::SplitEdit(this: v2, splitAlongX: 0, splitEdge: v9, outAlpha: &area, outBeta: &second);
    v5 = splitEdge;
    v6 = v10;
  }
  if ( v5 > 25.0 )
  {
    y = v2->m_nwCorner.y;
    if ( y >= 0.0 )
      v12 = 12.5;
    else
      v12 = -12.5;
    v13 = (float)((int)(float)(v12 + y) / 25) * 25.0;
    splitEdgea = v13;
    if ( (float)(v2->m_nwCorner.y + 2.0) > v13 )
    {
      v13 = v13 + 25.0;
      splitEdgea = v13;
    }
    if ( v6 != 0 )
    {
      CNavArea::SplitEdit(this: area, splitAlongX: 1, splitEdge: v13, outAlpha: &third, outBeta: &fourth);
      v14 = CNavArea::SplitEdit(this: second, splitAlongX: 1, splitEdge: splitEdgea, outAlpha: &area, outBeta: &second);
    }
    else
    {
      v14 = CNavArea::SplitEdit(this: v2, splitAlongX: 1, splitEdge: v13, outAlpha: &area, outBeta: &second);
    }
    v6 = v14;
  }
  if ( v6 == 0 )
    return 0;
  v15 = addToSelectedSet;
  if ( addToSelectedSet )
  {
    CNavMesh::AddToSelectedSet(this: TheNavMesh, area);
    CNavMesh::AddToSelectedSet(this: TheNavMesh, area: second);
    CNavMesh::AddToSelectedSet(this: TheNavMesh, area: third);
    CNavMesh::AddToSelectedSet(this: TheNavMesh, area: fourth);
  }
  ReduceToComponentAreas(area, addToSelectedSet: v15);
  ReduceToComponentAreas(area: second, addToSelectedSet: v15);
  ReduceToComponentAreas(area: third, addToSelectedSet: v15);
  ReduceToComponentAreas(area: fourth, addToSelectedSet: v15);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103249E0
// Name: public: bool CNavMesh::ForAllSelectedAreas<class NavAreaCollector>(class NavAreaCollector __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNavMesh::ForAllSelectedAreas<NavAreaCollector>(CNavMesh *this, NavAreaCollector *func)
{
  CNavMesh *v2; // edi
  char result; // al
  CNavArea *v4; // ebx
  int m_Size; // edx
  int v6; // eax
  CNavArea **m_pMemory; // ecx
  int v8; // edi
  int m_nAllocationCount; // eax
  CNavArea **v10; // ecx
  int v11; // eax
  CNavArea **v12; // eax
  int it; // [esp+8h] [ebp-4h]

  v2 = this;
  if ( !CNavMesh::IsSelectedSetEmpty(this) )
  {
    for ( it = 0; it < v2->m_selectedSet.m_Size; ++it )
    {
      v4 = v2->m_selectedSet.m_Memory.m_pMemory[it];
      if ( func->m_checkForDuplicates )
      {
        m_Size = func->m_area.m_Size;
        v6 = 0;
        if ( m_Size > 0 )
        {
          m_pMemory = func->m_area.m_Memory.m_pMemory;
          while ( *m_pMemory != v4 )
          {
            ++v6;
            ++m_pMemory;
            if ( v6 >= m_Size )
              goto LABEL_13;
          }
          if ( v6 >= 0 )
            continue;
        }
      }
LABEL_13:
      v8 = func->m_area.m_Size;
      m_nAllocationCount = func->m_area.m_Memory.m_nAllocationCount;
      if ( v8 + 1 > m_nAllocationCount )
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&func->m_area,
          num: v8 - m_nAllocationCount + 1);
      ++func->m_area.m_Size;
      v10 = func->m_area.m_Memory.m_pMemory;
      v11 = func->m_area.m_Size - v8 - 1;
      func->m_area.m_pElements = v10;
      if ( v11 > 0 )
        _V_memmove(dest: &v10[v8 + 1], src: &v10[v8], count: 4 * v11);
      v12 = &func->m_area.m_Memory.m_pMemory[v8];
      v2 = this;
      if ( v12 != nullptr )
        *v12 = v4;
    }
  }
  else if ( v2->m_selectedArea != nullptr )
  {
    result = NavAreaCollector::operator()(this: func, area: v2->m_selectedArea);
    if ( result == 0 )
      return result;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10324AE0
// Name: nav_chop_selected
// Source: json
//------------------------------------------------------------------------------
void __cdecl nav_chop_selected()
{
  int m_Size; // edi
  int v1; // esi
  CNavArea **m_pMemory; // ebx
  int SelecteSetSize; // eax
  NavAreaCollector collector; // [esp+0h] [ebp-18h] BYREF

  if ( UTIL_IsCommandIssuedByServerAdmin() && !engine->IsDedicatedServer(this: engine) )
  {
    CNavMesh::StripNavigationAreas(this: TheNavMesh);
    CNavMesh::SetMarkedArea(this: TheNavMesh, area: nullptr);
    memset(&collector.m_area, 0, sizeof(collector.m_area));
    collector.m_checkForDuplicates = false;
    CNavMesh::ForAllSelectedAreas<NavAreaCollector>(this: TheNavMesh, func: &collector);
    m_Size = collector.m_area.m_Size;
    v1 = 0;
    if ( collector.m_area.m_Size > 0 )
    {
      m_pMemory = collector.m_area.m_Memory.m_pMemory;
      do
        ReduceToComponentAreas(area: m_pMemory[v1++], addToSelectedSet: true);
      while ( v1 < m_Size );
    }
    SelecteSetSize = CNavMesh::GetSelecteSetSize(this: TheNavMesh);
    _Msg(a1: "%d areas chopped into %d\n", m_Size, SelecteSetSize);
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&collector.m_area);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10324B90
// Name: public: void CNavMesh::SimplifySelectedAreas(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNavMesh::SimplifySelectedAreas(CNavMesh *this)
{
  int v2; // esi
  int m_nValue; // eax
  float v4; // xmm0_4
  float v5; // xmm0_4
  int v6; // ebx
  CNavArea *v7; // esi
  int i; // eax
  float v9; // xmm0_4
  int j; // eax
  float v11; // xmm0_4
  int k; // eax
  float v13; // xmm0_4
  int m_Size; // ebx
  int m; // esi
  int n; // ebx
  CNavArea *v17; // esi
  CNavNode *Node; // eax
  CNavNode *v19; // ecx
  CNavNode *v20; // eax
  CNavNode *v21; // eax
  int v22; // eax
  int ii; // esi
  CNavArea *v24; // ebx
  int v25; // esi
  unsigned int v26; // [esp+0h] [ebp-7Ch]
  CGameTrace *value; // [esp+4h] [ebp-78h]
  unsigned int x; // [esp+8h] [ebp-74h]
  Extent areaExtent; // [esp+Ch] [ebp-70h] BYREF
  NavAreaCollector collector; // [esp+24h] [ebp-58h] BYREF
  Extent bounds; // [esp+3Ch] [ebp-40h] BYREF
  Vector corner; // [esp+54h] [ebp-28h] BYREF
  Vector center; // [esp+60h] [ebp-1Ch] BYREF
  float savedCoplanarSlopeLimit; // [esp+6Ch] [ebp-10h]
  float savedCoplanarSlopeDisplacementLimit; // [esp+70h] [ebp-Ch]
  int savedGrid; // [esp+74h] [ebp-8h]
  bool savedSplitPlaceOnGround; // [esp+7Bh] [ebp-1h]

  this->m_generationMode = GENERATE_SIMPLIFY;
  v2 = 0;
  if ( nav_split_place_on_ground.m_pParent != nullptr )
    m_nValue = nav_split_place_on_ground.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  savedSplitPlaceOnGround = m_nValue != 0;
  CCollisionProperty::TestCollision(
    this: (ConVar *)&nav_split_place_on_ground.IConVar,
    value: 1,
    fContentsMask: v26,
    tr: value);
  savedCoplanarSlopeDisplacementLimit = nav_coplanar_slope_limit_displacement.m_pParent->m_Value.m_fValue;
  v4 = savedCoplanarSlopeDisplacementLimit;
  if ( savedCoplanarSlopeDisplacementLimit > 0.5 )
    v4 = 0.5;
  ConVar::SetValue(this: (ConVar *)&nav_coplanar_slope_limit_displacement.IConVar, value: v4);
  savedCoplanarSlopeLimit = nav_coplanar_slope_limit.m_pParent->m_Value.m_fValue;
  v5 = savedCoplanarSlopeLimit;
  if ( savedCoplanarSlopeLimit > 0.5 )
    v5 = 0.5;
  ConVar::SetValue(this: (ConVar *)&nav_coplanar_slope_limit.IConVar, value: v5);
  if ( nav_snap_to_grid.m_pParent != nullptr )
    savedGrid = nav_snap_to_grid.m_pParent->m_Value.m_nValue;
  else
    savedGrid = 0;
  CCollisionProperty::TestCollision(
    this: (ConVar *)&nav_snap_to_grid.IConVar,
    value: 1,
    fContentsMask: x,
    tr: (CGameTrace *)LODWORD(areaExtent.lo.x));
  CNavMesh::StripNavigationAreas(this);
  CNavMesh::SetMarkedArea(this, area: nullptr);
  memset(&collector.m_area, 0, sizeof(collector.m_area));
  collector.m_checkForDuplicates = false;
  CNavMesh::ForAllSelectedAreas<NavAreaCollector>(this, func: &collector);
  bounds.lo.x = 3.4028235e38;
  bounds.lo.y = 3.4028235e38;
  bounds.lo.z = 3.4028235e38;
  v6 = 0;
  this->m_walkableSeeds.m_Size = 0;
  bounds.hi.x = -3.4028235e38;
  bounds.hi.y = -3.4028235e38;
  bounds.hi.z = -3.4028235e38;
  if ( collector.m_area.m_Size > 0 )
  {
    do
    {
      v7 = collector.m_area.m_Memory.m_pMemory[v6];
      CNavArea::GetExtent(this: v7, extent: &areaExtent);
      areaExtent.lo.z = areaExtent.lo.z - 35.5;
      areaExtent.hi.z = areaExtent.hi.z + 142.0;
      for ( i = 0; i < 12; i += 4 )
      {
        v9 = *(float *)((char *)&areaExtent.lo.x + i);
        if ( *(float *)((char *)&bounds.lo.x + i) <= v9 )
        {
          if ( v9 > *(float *)((char *)&bounds.hi.x + i) )
            *(float *)((char *)&bounds.hi.x + i) = v9;
        }
        else
        {
          *(float *)((char *)&bounds.lo.x + i) = v9;
        }
      }
      for ( j = 0; j < 12; j += 4 )
      {
        v11 = *(float *)((char *)&areaExtent.hi.x + j);
        if ( *(float *)((char *)&bounds.lo.x + j) <= v11 )
        {
          if ( v11 > *(float *)((char *)&bounds.hi.x + j) )
            *(float *)((char *)&bounds.hi.x + j) = v11;
        }
        else
        {
          *(float *)((char *)&bounds.lo.x + j) = v11;
        }
      }
      center = v7->m_center;
      center.x = CNavMesh::SnapToGrid(this, x: center.x, forceGrid: false);
      center.y = CNavMesh::SnapToGrid(this, x: center.y, forceGrid: false);
      if ( CNavMesh::FindGroundForNode(this, pos: &center, normal: &corner) )
      {
        CNavMesh::AddWalkableSeed(this, pos: &center, normal: &corner);
        center.z = center.z + 71.0;
        for ( k = 0; k < 12; k += 4 )
        {
          v13 = *(float *)((char *)&center.x + k);
          if ( *(float *)((char *)&bounds.lo.x + k) <= v13 )
          {
            if ( v13 > *(float *)((char *)&bounds.hi.x + k) )
              *(float *)((char *)&bounds.hi.x + k) = v13;
          }
          else
          {
            *(float *)((char *)&bounds.lo.x + k) = v13;
          }
        }
      }
      ++v6;
    }
    while ( v6 < collector.m_area.m_Size );
    v2 = 0;
  }
  if ( TheNavAreas.m_Size > 0 )
  {
    do
      CNavArea::ResetNodes(this: TheNavAreas.m_Memory.m_pMemory[v2++]);
    while ( v2 < TheNavAreas.m_Size );
  }
  CNavNode::CleanupGeneration();
  this->m_simplifyGenerationExtent = bounds;
  this->m_seedIdx = 0;
  while ( CNavMesh::SampleStep(this) )
    ;
  this->m_walkableSeeds.m_Size = 0;
  m_Size = collector.m_area.m_Size;
  for ( m = 0; m < m_Size; ++m )
    ReduceToComponentAreas(area: collector.m_area.m_Memory.m_pMemory[m], addToSelectedSet: true);
  for ( n = 0; n < this->m_selectedSet.m_Size; ++n )
  {
    v17 = this->m_selectedSet.m_Memory.m_pMemory[n];
    center.x = v17->m_seCorner.x;
    center.y = v17->m_nwCorner.y;
    center.z = v17->m_neZ;
    corner = center;
    if ( CNavMesh::FindGroundForNode(this, pos: &corner, normal: &bounds.hi) )
    {
      Node = CNavNode::GetNode(pos: &corner);
      v17->m_node[1] = Node;
      if ( Node != nullptr )
      {
        v19 = Node->m_to[3];
        v17->m_node[0] = v19;
        v20 = Node->m_to[2];
        v17->m_node[2] = v20;
        if ( v20 != nullptr )
        {
          v21 = v20->m_to[3];
          v17->m_node[3] = v21;
          if ( v19 != nullptr && v21 != nullptr )
            CNavArea::AssignNodes(this: v17, area: v17);
        }
      }
    }
    if ( v17->m_node[1] == nullptr
      || v17->m_node[0] == nullptr
      || v17->m_node[2] == nullptr
      || v17->m_node[3] == nullptr )
    {
      _Warning(a1: "Area %d didn't get any nodes!\n", v17->m_id);
    }
  }
  CNavMesh::MergeGeneratedAreas(this);
  CNavMesh::SquareUpAreas(this);
  CNavMesh::MarkJumpAreas(this);
  CNavMesh::SplitAreasUnderOverhangs(this);
  CNavMesh::MarkStairAreas(this);
  CNavMesh::StichAndRemoveJumpAreas(this);
  CNavMesh::HandleObstacleTopAreas(this);
  CNavMesh::FixUpGeneratedAreas(this);
  CNavMesh::ClearSelectedSet(this);
  v22 = TheNavAreas.m_Size;
  for ( ii = 0; ii < TheNavAreas.m_Size; ++ii )
  {
    v24 = TheNavAreas.m_Memory.m_pMemory[ii];
    if ( CNavArea::HasNodes(this: v24) != 0 )
      CNavMesh::AddToSelectedSet(this, area: v24);
    v22 = TheNavAreas.m_Size;
  }
  v25 = 0;
  if ( v22 > 0 )
  {
    do
      CNavArea::ResetNodes(this: TheNavAreas.m_Memory.m_pMemory[v25++]);
    while ( v25 < TheNavAreas.m_Size );
  }
  CNavNode::CleanupGeneration();
  LODWORD(areaExtent.lo.x) = savedSplitPlaceOnGround;
  this->m_generationMode = GENERATE_NONE;
  CCollisionProperty::TestCollision(
    this: (ConVar *)&nav_split_place_on_ground.IConVar,
    value: SLODWORD(areaExtent.lo.x),
    fContentsMask: LODWORD(areaExtent.lo.y),
    tr: (CGameTrace *)LODWORD(areaExtent.lo.z));
  ConVar::SetValue(
    this: (ConVar *)&nav_coplanar_slope_limit_displacement.IConVar,
    value: savedCoplanarSlopeDisplacementLimit);
  ConVar::SetValue(this: (ConVar *)&nav_coplanar_slope_limit.IConVar, value: savedCoplanarSlopeLimit);
  CCollisionProperty::TestCollision(
    this: (ConVar *)&nav_snap_to_grid.IConVar,
    value: savedGrid,
    fContentsMask: LODWORD(areaExtent.hi.x),
    tr: (CGameTrace *)LODWORD(areaExtent.hi.y));
  if ( collector.m_area.m_Memory.m_nGrowSize >= 0 && collector.m_area.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: collector.m_area.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x103250E0
// Name: nav_simplify_selected
// Source: json
//------------------------------------------------------------------------------
void __cdecl nav_simplify_selected()
{
  int SelecteSetSize; // esi
  int v1; // eax

  if ( UTIL_IsCommandIssuedByServerAdmin() && !engine->IsDedicatedServer(this: engine) )
  {
    SelecteSetSize = CNavMesh::GetSelecteSetSize(this: TheNavMesh);
    if ( SelecteSetSize != 0 )
    {
      CNavMesh::SimplifySelectedAreas(this: TheNavMesh);
      v1 = CNavMesh::GetSelecteSetSize(this: TheNavMesh);
      _Msg(a1: "%d areas simplified - %d remain\n", SelecteSetSize, v1);
    }
    else
    {
      _Msg(a1: "nav_simplify_selected only works on the selected set\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10421380
// Name: _CNavMesh::UpdateGeneration_::_2_::_dynamic_atexit_destructor_for__s_unlitSeedAreas__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CNavMesh::UpdateGeneration_::_2_::_dynamic_atexit_destructor_for__s_unlitSeedAreas__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_unlitSeedAreas);
}

//------------------------------------------------------------------------------
// Address: 0x10421390
// Name: _CNavMesh::UpdateGeneration_::_2_::_dynamic_atexit_destructor_for__s_unlitAreas__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CNavMesh::UpdateGeneration_::_2_::_dynamic_atexit_destructor_for__s_unlitAreas__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_unlitAreas);
}

//------------------------------------------------------------------------------
// Address: 0x101E99A0
// Name: class CPhysBoxMultiplayer __near * _CreateEntityTemplate<class CPhysBoxMultiplayer>(class CPhysBoxMultiplayer __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPhysBoxMultiplayer *__cdecl _CreateEntityTemplate<CPhysBoxMultiplayer>(
        CPhysBoxMultiplayer *newEnt,
        const char *className)
{
  CPhysBox *v2; // eax
  _DWORD *v3; // esi

  v2 = (CPhysBox *)CBaseEntity::operator new(stAllocateBlock: 0x4FCu);
  v3 = &v2->CBreakable::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( v2 != nullptr )
  {
    CPhysBox::CPhysBox(this: v2);
    v3[316] = &IMultiplayerPhysics::`vftable';
    *v3 = &CPhysBoxMultiplayer::`vftable'{for `CBaseEntity'};
    v3[213] = &CPhysBoxMultiplayer::`vftable'{for `IBreakableWithPropData'};
    v3[214] = &CPhysBoxMultiplayer::`vftable'{for `CDefaultPlayerPickupVPhysics'};
    v3[316] = &CPhysBoxMultiplayer::`vftable';
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CPhysBoxMultiplayer *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B46C0
// Name: bool NavAreaBuildPath<class ShortestPathCost>(class CNavArea __near *,class CNavArea __near *,class Vector const __near *,class ShortestPathCost __near &,class CNavArea __near * __near *,float,int,bool)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl NavAreaBuildPath<ShortestPathCost>(
        CNavArea *startArea,
        CNavArea *goalArea,
        const Vector *goalPos,
        ShortestPathCost *costFunc,
        CNavArea **closestArea,
        float maxPathLength,
        int teamID,
        BOOL ignoreNavBlockers)
{
  int v8; // ecx
  CNavArea *v9; // edi
  const Vector *v10; // ecx
  const Vector *p_m_center; // eax
  CNavArea *v13; // esi
  int v14; // edi
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // eax
  int v16; // eax
  CNavArea *area; // esi
  float v18; // xmm0_4
  const CNavLadder *v19; // eax
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v20; // eax
  double v21; // st7
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  float v25; // xmm0_4
  double v26; // xmm0_8
  float v27; // xmm0_4
  unsigned int m_openMarker; // eax
  __int64 v29; // [esp+70h] [ebp-48h]
  float z; // [esp+78h] [ebp-40h]
  float actualGoalPos; // [esp+7Ch] [ebp-3Ch]
  const CFuncElevator *actualGoalPos_4; // [esp+80h] [ebp-38h]
  float actualGoalPos_4a; // [esp+80h] [ebp-38h]
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *actualGoalPos_8; // [esp+84h] [ebp-34h]
  const CNavLadder *closestAreaDist; // [esp+88h] [ebp-30h]
  const CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *floorList; // [esp+90h] [ebp-28h]
  int ladder; // [esp+94h] [ebp-24h]
  int length; // [esp+98h] [ebp-20h]
  const CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator> *ladderList; // [esp+9Ch] [ebp-1Ch]
  NavAreaBuildPath::__l31::SearchType searchWhere; // [esp+A0h] [ebp-18h]
  CNavArea *dir; // [esp+A4h] [ebp-14h]
  bool how_2; // [esp+AAh] [ebp-Eh]
  char how_3; // [esp+ABh] [ebp-Dh]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "NavAreaBuildPath",
    a3: 0,
    a4: "NextBotSpiky",
    a5: false,
    a6: 4);
  if ( closestArea != nullptr )
    *closestArea = startArea;
  v8 = g_DebugPathfindCounter--;
  how_2 = v8 > 0;
  if ( startArea == nullptr )
    goto LABEL_8;
  v9 = goalArea;
  if ( goalArea != nullptr )
  {
    if ( !goalArea->IsBlocked(this: goalArea, a2: teamID, a3: ignoreNavBlockers) )
    {
      v10 = goalPos;
      goto LABEL_10;
    }
    goalArea = nullptr;
    v9 = nullptr;
  }
  v10 = goalPos;
  if ( goalPos == nullptr )
  {
LABEL_8:
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 0;
  }
LABEL_10:
  startArea->m_parent = nullptr;
  startArea->m_parentHow = NUM_TRAVERSE_TYPES;
  if ( startArea == v9 )
  {
    v9->m_parent = nullptr;
    v9->m_parentHow = NUM_TRAVERSE_TYPES;
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return 1;
  }
  p_m_center = v10;
  if ( v10 == nullptr )
    p_m_center = &v9->m_center;
  v29 = *(_QWORD *)&p_m_center->x;
  z = p_m_center->z;
  CNavArea::ClearSearchLists();
  startArea->m_totalCost = fsqrt(
                             (float)((float)((float)(startArea->m_center.x - *(float *)&v29)
                                           * (float)(startArea->m_center.x - *(float *)&v29))
                                   + (float)((float)(startArea->m_center.y - *((float *)&v29 + 1))
                                           * (float)(startArea->m_center.y - *((float *)&v29 + 1))))
                           + (float)((float)(startArea->m_center.z - z) * (float)(startArea->m_center.z - z)));
  startArea->m_costSoFar = 0.0;
  startArea->m_pathLengthSoFar = 0.0;
  CNavArea::AddToOpenList(this: startArea);
  if ( closestArea != nullptr )
    *closestArea = startArea;
  v13 = CNavArea::m_openList;
  actualGoalPos = startArea->m_totalCost;
  if ( CNavArea::m_openList == nullptr )
    goto LABEL_8;
  while ( 1 )
  {
    CNavArea::RemoveFromOpenList(this: v13);
    v13->m_prevOpen = nullptr;
    v13->m_nextOpen = nullptr;
    if ( how_2 )
      ((void (__thiscall *)(CNavArea *, _DWORD, int, _DWORD, int, int, int, int))v13->DrawFilled)(
        a1: v13,
        a2: 0,
        a3: 255,
        a4: 0,
        a5: 128,
        a6: 1106247680,
        a7: 1,
        a8: 1084227584);
    if ( !v13->IsBlocked(this: v13, a2: teamID, a3: ignoreNavBlockers) )
      break;
LABEL_72:
    v13 = CNavArea::m_openList;
    if ( CNavArea::m_openList == nullptr )
      goto LABEL_8;
  }
  if ( v13 != v9 && (v9 != nullptr || goalPos == nullptr || !CNavArea::Contains(this: v13, pos: goalPos)) )
  {
    actualGoalPos_8 = v13->m_connect;
    v14 = 0;
    ladder = 0;
    length = 0;
    how_3 = 1;
    floorList = nullptr;
    searchWhere = SEARCH_FLOOR;
    while ( 1 )
    {
      while ( 1 )
      {
        closestAreaDist = nullptr;
        actualGoalPos_4 = nullptr;
        if ( ladder != 0 )
          break;
        m_pData = actualGoalPos_8->m_pData;
        if ( v14 < actualGoalPos_8->m_pData->m_Size )
        {
          area = m_pData->m_Elements[v14].area;
          v18 = m_pData->m_Elements[v14++].length;
LABEL_52:
          if ( area != dir && !area->IsBlocked(this: area, a2: teamID, a3: ignoreNavBlockers) )
          {
            v21 = ShortestPathCost::operator()(
                    this: costFunc,
                    area,
                    fromArea: dir,
                    ladder: closestAreaDist,
                    elevator: actualGoalPos_4,
                    length: v18);
            if ( v21 >= 0.0 )
            {
              if ( maxPathLength > 0.0 )
              {
                v22 = area->m_center.y - dir->m_center.y;
                v23 = area->m_center.x - dir->m_center.x;
                v24 = dir->m_pathLengthSoFar
                    + fsqrt(
                        (float)((float)(v23 * v23) + (float)(v22 * v22))
                      + (float)((float)(area->m_center.z - dir->m_center.z) * (float)(area->m_center.z - dir->m_center.z)));
                if ( v24 > maxPathLength )
                  goto LABEL_25;
                area->m_pathLengthSoFar = v24;
              }
              actualGoalPos_4a = v21;
              if ( area->m_openMarker != CNavArea::m_masterMarker && area->m_marker != CNavArea::m_masterMarker
                || actualGoalPos_4a < area->m_costSoFar )
              {
                v25 = (float)((float)((float)(area->m_center.y - *((float *)&v29 + 1))
                                    * (float)(area->m_center.y - *((float *)&v29 + 1)))
                            + (float)((float)(area->m_center.x - *(float *)&v29)
                                    * (float)(area->m_center.x - *(float *)&v29)))
                    + (float)((float)(area->m_center.z - z) * (float)(area->m_center.z - z));
                if ( v25 <= 0.0 )
                  v26 = 0.0;
                else
                  v26 = fsqrt(v25);
                v27 = v26;
                if ( closestArea != nullptr && actualGoalPos > v27 )
                {
                  *closestArea = area;
                  actualGoalPos = v27;
                }
                m_openMarker = area->m_openMarker;
                area->m_costSoFar = actualGoalPos_4a;
                area->m_totalCost = v27 + actualGoalPos_4a;
                if ( m_openMarker == CNavArea::m_masterMarker )
                  CNavArea::UpdateOnOpenList(this: area);
                else
                  CNavArea::AddToOpenList(this: area);
                area->m_parent = dir;
                area->m_parentHow = (NavTraverseType)ladderList;
              }
            }
          }
LABEL_25:
          v13 = dir;
        }
        else
        {
          v16 = length + 1;
          v14 = 0;
          length = v16;
          if ( v16 == 4 )
          {
            ladder = 1;
            floorList = (const CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *)v13->m_ladder;
            searchWhere = SEARCH_FLOOR;
          }
          else
          {
            actualGoalPos_8 = &v13->m_connect[v16];
          }
        }
      }
      if ( ladder != 1 )
        break;
      if ( v14 < floorList->m_pData->m_Size )
      {
        v19 = (const CNavLadder *)*(&floorList->m_pData->m_Elements[0].id + v14);
        closestAreaDist = v19;
        if ( how_3 == 0 )
        {
          area = v19->m_bottomArea;
          ++v14;
          goto LABEL_46;
        }
        switch ( searchWhere )
        {
          case SEARCH_FLOOR:
            area = v19->m_topForwardArea;
            searchWhere = SEARCH_LADDERS;
LABEL_46:
            if ( area == nullptr )
              goto LABEL_25;
LABEL_51:
            v18 = -1.0;
            goto LABEL_52;
          case SEARCH_LADDERS:
            area = v19->m_topLeftArea;
            searchWhere = SEARCH_ELEVATORS;
            goto LABEL_46;
          case SEARCH_ELEVATORS:
            area = v19->m_topRightArea;
            searchWhere = SEARCH_ELEVATORS|SEARCH_LADDERS;
            goto LABEL_46;
          default:
            break;
        }
        ++v14;
        searchWhere = SEARCH_FLOOR;
      }
      else
      {
        v14 = 0;
        if ( how_3 != 0 )
        {
          how_3 = 0;
          floorList = (const CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *)&v13->m_ladder[1];
        }
        else
        {
          ladder = 2;
        }
      }
    }
    actualGoalPos_4 = CNavArea::GetElevator(this: v13);
    if ( actualGoalPos_4 == nullptr || (v20 = v13->m_elevatorAreas.m_pData, v14 >= v20->m_Size) )
    {
      v9 = goalArea;
      v13->m_marker = CNavArea::m_masterMarker;
      goto LABEL_72;
    }
    area = v20->m_Elements[v14++].area;
    goto LABEL_51;
  }
  if ( closestArea != nullptr )
    *closestArea = v13;
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10309D10
// Name: class CFuncNavObstruction __near * _CreateEntityTemplate<class CFuncNavObstruction>(class CFuncNavObstruction __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFuncNavObstruction *__cdecl _CreateEntityTemplate<CFuncNavObstruction>(
        CFuncNavObstruction *newEnt,
        const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x35Cu);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    v3[213] = &INavAvoidanceObstacle::`vftable';
    *v3 = &CFuncNavObstruction::`vftable'{for `CBaseEntity'};
    v3[213] = &CFuncNavObstruction::`vftable'{for `INavAvoidanceObstacle'};
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CFuncNavObstruction *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104213A0
// Name: _dynamic_atexit_destructor_for__nav_save_selected_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_save_selected_command__()
{
  ConCommand::~ConCommand(this: &nav_save_selected_command);
}

//------------------------------------------------------------------------------
// Address: 0x104213B0
// Name: _dynamic_atexit_destructor_for__nav_merge_mesh_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_merge_mesh_command__()
{
  ConCommand::~ConCommand(this: &nav_merge_mesh_command);
}

//------------------------------------------------------------------------------
// Address: 0x104213C0
// Name: _dynamic_atexit_destructor_for__nav_edit__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_edit__()
{
  ConVar::~ConVar(this: &nav_edit);
}

//------------------------------------------------------------------------------
// Address: 0x104213D0
// Name: _dynamic_atexit_destructor_for__nav_quicksave__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_quicksave__()
{
  ConVar::~ConVar(this: &nav_quicksave);
}

//------------------------------------------------------------------------------
// Address: 0x104213E0
// Name: _dynamic_atexit_destructor_for__nav_show_approach_points__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_show_approach_points__()
{
  ConVar::~ConVar(this: &nav_show_approach_points);
}

//------------------------------------------------------------------------------
// Address: 0x104213F0
// Name: _dynamic_atexit_destructor_for__nav_show_danger__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_show_danger__()
{
  ConVar::~ConVar(this: &nav_show_danger);
}

//------------------------------------------------------------------------------
// Address: 0x10421400
// Name: _dynamic_atexit_destructor_for__nav_show_player_counts__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_show_player_counts__()
{
  ConVar::~ConVar(this: &nav_show_player_counts);
}

//------------------------------------------------------------------------------
// Address: 0x10421410
// Name: _dynamic_atexit_destructor_for__nav_max_vis_delta_list_length__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_max_vis_delta_list_length__()
{
  ConVar::~ConVar(this: &nav_max_vis_delta_list_length);
}

//------------------------------------------------------------------------------
// Address: 0x10421420
// Name: _dynamic_atexit_destructor_for__nav_remove_jump_areas__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_remove_jump_areas__()
{
  ConCommand::~ConCommand(this: &nav_remove_jump_areas);
}

//------------------------------------------------------------------------------
// Address: 0x10421430
// Name: _dynamic_atexit_destructor_for__nav_delete__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_delete__()
{
  ConCommand::~ConCommand(this: &nav_delete);
}

//------------------------------------------------------------------------------
// Address: 0x10421440
// Name: _dynamic_atexit_destructor_for__nav_delete_marked__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_delete_marked__()
{
  ConCommand::~ConCommand(this: &nav_delete_marked);
}

//------------------------------------------------------------------------------
// Address: 0x10421450
// Name: _dynamic_atexit_destructor_for__nav_flood_select_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_flood_select_command__()
{
  ConCommand::~ConCommand(this: &nav_flood_select_command);
}

//------------------------------------------------------------------------------
// Address: 0x10421460
// Name: _dynamic_atexit_destructor_for__nav_toggle_selected_set__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_toggle_selected_set__()
{
  ConCommand::~ConCommand(this: &nav_toggle_selected_set);
}

//------------------------------------------------------------------------------
// Address: 0x10421470
// Name: _dynamic_atexit_destructor_for__nav_store_selected_set__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_store_selected_set__()
{
  ConCommand::~ConCommand(this: &nav_store_selected_set);
}

//------------------------------------------------------------------------------
// Address: 0x10421480
// Name: _dynamic_atexit_destructor_for__nav_recall_selected_set__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_recall_selected_set__()
{
  ConCommand::~ConCommand(this: &nav_recall_selected_set);
}

//------------------------------------------------------------------------------
// Address: 0x10421490
// Name: _dynamic_atexit_destructor_for__nav_add_to_selected_set__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_add_to_selected_set__()
{
  ConCommand::~ConCommand(this: &nav_add_to_selected_set);
}

//------------------------------------------------------------------------------
// Address: 0x104214A0
// Name: _dynamic_atexit_destructor_for__nav_add_to_selected_set_by_id_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_add_to_selected_set_by_id_command__()
{
  ConCommand::~ConCommand(this: &nav_add_to_selected_set_by_id_command);
}

//------------------------------------------------------------------------------
// Address: 0x104214B0
// Name: _dynamic_atexit_destructor_for__nav_remove_from_selected_set__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_remove_from_selected_set__()
{
  ConCommand::~ConCommand(this: &nav_remove_from_selected_set);
}

//------------------------------------------------------------------------------
// Address: 0x104214C0
// Name: _dynamic_atexit_destructor_for__nav_toggle_in_selected_set__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_toggle_in_selected_set__()
{
  ConCommand::~ConCommand(this: &nav_toggle_in_selected_set);
}

//------------------------------------------------------------------------------
// Address: 0x104214D0
// Name: _dynamic_atexit_destructor_for__nav_clear_selected_set__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_clear_selected_set__()
{
  ConCommand::~ConCommand(this: &nav_clear_selected_set);
}

//------------------------------------------------------------------------------
// Address: 0x104214E0
// Name: _dynamic_atexit_destructor_for__nav_begin_selecting__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_begin_selecting__()
{
  ConCommand::~ConCommand(this: &nav_begin_selecting);
}

//------------------------------------------------------------------------------
// Address: 0x104214F0
// Name: _dynamic_atexit_destructor_for__nav_end_selecting__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_end_selecting__()
{
  ConCommand::~ConCommand(this: &nav_end_selecting);
}

//------------------------------------------------------------------------------
// Address: 0x10421500
// Name: _dynamic_atexit_destructor_for__nav_begin_drag_selecting__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_begin_drag_selecting__()
{
  ConCommand::~ConCommand(this: &nav_begin_drag_selecting);
}

//------------------------------------------------------------------------------
// Address: 0x10421510
// Name: _dynamic_atexit_destructor_for__nav_end_drag_selecting__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_end_drag_selecting__()
{
  ConCommand::~ConCommand(this: &nav_end_drag_selecting);
}

//------------------------------------------------------------------------------
// Address: 0x10421520
// Name: _dynamic_atexit_destructor_for__nav_begin_drag_deselecting__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_begin_drag_deselecting__()
{
  ConCommand::~ConCommand(this: &nav_begin_drag_deselecting);
}

//------------------------------------------------------------------------------
// Address: 0x10421530
// Name: _dynamic_atexit_destructor_for__nav_end_drag_deselecting__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_end_drag_deselecting__()
{
  ConCommand::~ConCommand(this: &nav_end_drag_deselecting);
}

//------------------------------------------------------------------------------
// Address: 0x10421540
// Name: _dynamic_atexit_destructor_for__nav_raise_drag_volume_max__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_raise_drag_volume_max__()
{
  ConCommand::~ConCommand(this: &nav_raise_drag_volume_max);
}

//------------------------------------------------------------------------------
// Address: 0x10421550
// Name: _dynamic_atexit_destructor_for__nav_lower_drag_volume_max__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_lower_drag_volume_max__()
{
  ConCommand::~ConCommand(this: &nav_lower_drag_volume_max);
}

//------------------------------------------------------------------------------
// Address: 0x10421560
// Name: _dynamic_atexit_destructor_for__nav_raise_drag_volume_min__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_raise_drag_volume_min__()
{
  ConCommand::~ConCommand(this: &nav_raise_drag_volume_min);
}

//------------------------------------------------------------------------------
// Address: 0x10421570
// Name: _dynamic_atexit_destructor_for__nav_lower_drag_volume_min__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_lower_drag_volume_min__()
{
  ConCommand::~ConCommand(this: &nav_lower_drag_volume_min);
}

//------------------------------------------------------------------------------
// Address: 0x10421580
// Name: _dynamic_atexit_destructor_for__nav_toggle_selecting__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_toggle_selecting__()
{
  ConCommand::~ConCommand(this: &nav_toggle_selecting);
}

//------------------------------------------------------------------------------
// Address: 0x10421590
// Name: _dynamic_atexit_destructor_for__nav_begin_deselecting__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_begin_deselecting__()
{
  ConCommand::~ConCommand(this: &nav_begin_deselecting);
}

//------------------------------------------------------------------------------
// Address: 0x104215A0
// Name: _dynamic_atexit_destructor_for__nav_end_deselecting__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_end_deselecting__()
{
  ConCommand::~ConCommand(this: &nav_end_deselecting);
}

//------------------------------------------------------------------------------
// Address: 0x104215B0
// Name: _dynamic_atexit_destructor_for__nav_toggle_deselecting__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_toggle_deselecting__()
{
  ConCommand::~ConCommand(this: &nav_toggle_deselecting);
}

//------------------------------------------------------------------------------
// Address: 0x104215C0
// Name: _dynamic_atexit_destructor_for__nav_select_half_space_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_select_half_space_command__()
{
  ConCommand::~ConCommand(this: &nav_select_half_space_command);
}

//------------------------------------------------------------------------------
// Address: 0x104215D0
// Name: _dynamic_atexit_destructor_for__nav_begin_shift_xy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_begin_shift_xy__()
{
  ConCommand::~ConCommand(this: &nav_begin_shift_xy);
}

//------------------------------------------------------------------------------
// Address: 0x104215E0
// Name: _dynamic_atexit_destructor_for__nav_end_shift_xy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_end_shift_xy__()
{
  ConCommand::~ConCommand(this: &nav_end_shift_xy);
}

//------------------------------------------------------------------------------
// Address: 0x104215F0
// Name: _dynamic_atexit_destructor_for__nav_select_invalid_areas__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_select_invalid_areas__()
{
  ConCommand::~ConCommand(this: &nav_select_invalid_areas);
}

//------------------------------------------------------------------------------
// Address: 0x10421600
// Name: _dynamic_atexit_destructor_for__nav_select_blocked_areas_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_select_blocked_areas_command__()
{
  ConCommand::~ConCommand(this: &nav_select_blocked_areas_command);
}

//------------------------------------------------------------------------------
// Address: 0x10421610
// Name: _dynamic_atexit_destructor_for__nav_select_obstructed_areas_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_select_obstructed_areas_command__()
{
  ConCommand::~ConCommand(this: &nav_select_obstructed_areas_command);
}

//------------------------------------------------------------------------------
// Address: 0x10421620
// Name: _dynamic_atexit_destructor_for__nav_select_damaging_areas_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_select_damaging_areas_command__()
{
  ConCommand::~ConCommand(this: &nav_select_damaging_areas_command);
}

//------------------------------------------------------------------------------
// Address: 0x10421630
// Name: _dynamic_atexit_destructor_for__nav_select_stairs_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_select_stairs_command__()
{
  ConCommand::~ConCommand(this: &nav_select_stairs_command);
}

//------------------------------------------------------------------------------
// Address: 0x10421640
// Name: _dynamic_atexit_destructor_for__nav_split__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_split__()
{
  ConCommand::~ConCommand(this: &nav_split);
}

//------------------------------------------------------------------------------
// Address: 0x10421650
// Name: _dynamic_atexit_destructor_for__nav_make_sniper_spots__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_make_sniper_spots__()
{
  ConCommand::~ConCommand(this: &nav_make_sniper_spots);
}

//------------------------------------------------------------------------------
// Address: 0x10421660
// Name: _dynamic_atexit_destructor_for__nav_merge__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_merge__()
{
  ConCommand::~ConCommand(this: &nav_merge);
}

//------------------------------------------------------------------------------
// Address: 0x10421670
// Name: _dynamic_atexit_destructor_for__nav_mark__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_mark__()
{
  ConCommand::~ConCommand(this: &nav_mark);
}

//------------------------------------------------------------------------------
// Address: 0x10421680
// Name: _dynamic_atexit_destructor_for__nav_unmark__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_unmark__()
{
  ConCommand::~ConCommand(this: &nav_unmark);
}

//------------------------------------------------------------------------------
// Address: 0x10421690
// Name: _dynamic_atexit_destructor_for__nav_begin_area__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_begin_area__()
{
  ConCommand::~ConCommand(this: &nav_begin_area);
}

//------------------------------------------------------------------------------
// Address: 0x104216A0
// Name: _dynamic_atexit_destructor_for__nav_end_area__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_end_area__()
{
  ConCommand::~ConCommand(this: &nav_end_area);
}

//------------------------------------------------------------------------------
// Address: 0x104216B0
// Name: _dynamic_atexit_destructor_for__nav_connect__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_connect__()
{
  ConCommand::~ConCommand(this: &nav_connect);
}

//------------------------------------------------------------------------------
// Address: 0x104216C0
// Name: _dynamic_atexit_destructor_for__nav_disconnect__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_disconnect__()
{
  ConCommand::~ConCommand(this: &nav_disconnect);
}

//------------------------------------------------------------------------------
// Address: 0x104216D0
// Name: _dynamic_atexit_destructor_for__nav_splice__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_splice__()
{
  ConCommand::~ConCommand(this: &nav_splice);
}

//------------------------------------------------------------------------------
// Address: 0x104216E0
// Name: _dynamic_atexit_destructor_for__nav_crouch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_crouch__()
{
  ConCommand::~ConCommand(this: &nav_crouch);
}

//------------------------------------------------------------------------------
// Address: 0x104216F0
// Name: _dynamic_atexit_destructor_for__nav_precise__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_precise__()
{
  ConCommand::~ConCommand(this: &nav_precise);
}

//------------------------------------------------------------------------------
// Address: 0x10421700
// Name: _dynamic_atexit_destructor_for__nav_jump__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_jump__()
{
  ConCommand::~ConCommand(this: &nav_jump);
}

//------------------------------------------------------------------------------
// Address: 0x10421710
// Name: _dynamic_atexit_destructor_for__nav_no_jump__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_no_jump__()
{
  ConCommand::~ConCommand(this: &nav_no_jump);
}

//------------------------------------------------------------------------------
// Address: 0x10421720
// Name: _dynamic_atexit_destructor_for__nav_stop__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_stop__()
{
  ConCommand::~ConCommand(this: &nav_stop);
}

//------------------------------------------------------------------------------
// Address: 0x10421730
// Name: _dynamic_atexit_destructor_for__nav_walk__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_walk__()
{
  ConCommand::~ConCommand(this: &nav_walk);
}

//------------------------------------------------------------------------------
// Address: 0x10421740
// Name: _dynamic_atexit_destructor_for__nav_run__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_run__()
{
  ConCommand::~ConCommand(this: &nav_run);
}

//------------------------------------------------------------------------------
// Address: 0x10421750
// Name: _dynamic_atexit_destructor_for__nav_avoid__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_avoid__()
{
  ConCommand::~ConCommand(this: &nav_avoid);
}

//------------------------------------------------------------------------------
// Address: 0x10421760
// Name: _dynamic_atexit_destructor_for__nav_transient__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_transient__()
{
  ConCommand::~ConCommand(this: &nav_transient);
}

//------------------------------------------------------------------------------
// Address: 0x10421770
// Name: _dynamic_atexit_destructor_for__nav_dont_hide__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_dont_hide__()
{
  ConCommand::~ConCommand(this: &nav_dont_hide);
}

//------------------------------------------------------------------------------
// Address: 0x10421780
// Name: _dynamic_atexit_destructor_for__nav_stand__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_stand__()
{
  ConCommand::~ConCommand(this: &nav_stand);
}

//------------------------------------------------------------------------------
// Address: 0x10421790
// Name: _dynamic_atexit_destructor_for__nav_no_hostages__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_no_hostages__()
{
  ConCommand::~ConCommand(this: &nav_no_hostages);
}

//------------------------------------------------------------------------------
// Address: 0x104217A0
// Name: _dynamic_atexit_destructor_for__nav_strip__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_strip__()
{
  ConCommand::~ConCommand(this: &nav_strip);
}

//------------------------------------------------------------------------------
// Address: 0x104217B0
// Name: _dynamic_atexit_destructor_for__nav_save__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_save__()
{
  ConCommand::~ConCommand(this: &nav_save);
}

//------------------------------------------------------------------------------
// Address: 0x104217C0
// Name: _dynamic_atexit_destructor_for__nav_load__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_load__()
{
  ConCommand::~ConCommand(this: &nav_load);
}

//------------------------------------------------------------------------------
// Address: 0x104217D0
// Name: _dynamic_atexit_destructor_for__nav_use_place__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_use_place__()
{
  ConCommand::~ConCommand(this: &nav_use_place);
}

//------------------------------------------------------------------------------
// Address: 0x104217E0
// Name: _dynamic_atexit_destructor_for__nav_place_replace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_place_replace__()
{
  ConCommand::~ConCommand(this: &nav_place_replace);
}

//------------------------------------------------------------------------------
// Address: 0x104217F0
// Name: _dynamic_atexit_destructor_for__nav_place_list__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_place_list__()
{
  ConCommand::~ConCommand(this: &nav_place_list);
}

//------------------------------------------------------------------------------
// Address: 0x10421800
// Name: _dynamic_atexit_destructor_for__nav_toggle_place_mode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_toggle_place_mode__()
{
  ConCommand::~ConCommand(this: &nav_toggle_place_mode);
}

//------------------------------------------------------------------------------
// Address: 0x10421810
// Name: _dynamic_atexit_destructor_for__nav_set_place_mode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_set_place_mode__()
{
  ConCommand::~ConCommand(this: &nav_set_place_mode);
}

//------------------------------------------------------------------------------
// Address: 0x10421820
// Name: _dynamic_atexit_destructor_for__nav_place_floodfill__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_place_floodfill__()
{
  ConCommand::~ConCommand(this: &nav_place_floodfill);
}

//------------------------------------------------------------------------------
// Address: 0x10421830
// Name: _dynamic_atexit_destructor_for__nav_place_set__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_place_set__()
{
  ConCommand::~ConCommand(this: &nav_place_set);
}

//------------------------------------------------------------------------------
// Address: 0x10421840
// Name: _dynamic_atexit_destructor_for__nav_place_pick__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_place_pick__()
{
  ConCommand::~ConCommand(this: &nav_place_pick);
}

//------------------------------------------------------------------------------
// Address: 0x10421850
// Name: _dynamic_atexit_destructor_for__nav_toggle_place_painting__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_toggle_place_painting__()
{
  ConCommand::~ConCommand(this: &nav_toggle_place_painting);
}

//------------------------------------------------------------------------------
// Address: 0x10421860
// Name: _dynamic_atexit_destructor_for__nav_mark_unnamed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_mark_unnamed__()
{
  ConCommand::~ConCommand(this: &nav_mark_unnamed);
}

//------------------------------------------------------------------------------
// Address: 0x10421870
// Name: _dynamic_atexit_destructor_for__nav_corner_select__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_corner_select__()
{
  ConCommand::~ConCommand(this: &nav_corner_select);
}

//------------------------------------------------------------------------------
// Address: 0x10421880
// Name: _dynamic_atexit_destructor_for__nav_corner_raise_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_corner_raise_command__()
{
  ConCommand::~ConCommand(this: &nav_corner_raise_command);
}

//------------------------------------------------------------------------------
// Address: 0x10421890
// Name: _dynamic_atexit_destructor_for__nav_corner_lower_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_corner_lower_command__()
{
  ConCommand::~ConCommand(this: &nav_corner_lower_command);
}

//------------------------------------------------------------------------------
// Address: 0x104218A0
// Name: _dynamic_atexit_destructor_for__nav_corner_place_on_ground_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_corner_place_on_ground_command__()
{
  ConCommand::~ConCommand(this: &nav_corner_place_on_ground_command);
}

//------------------------------------------------------------------------------
// Address: 0x104218B0
// Name: _dynamic_atexit_destructor_for__nav_warp_to_mark__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_warp_to_mark__()
{
  ConCommand::~ConCommand(this: &nav_warp_to_mark);
}

//------------------------------------------------------------------------------
// Address: 0x104218C0
// Name: _dynamic_atexit_destructor_for__nav_ladder_flip__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_ladder_flip__()
{
  ConCommand::~ConCommand(this: &nav_ladder_flip);
}

//------------------------------------------------------------------------------
// Address: 0x104218D0
// Name: _dynamic_atexit_destructor_for__nav_generate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_generate__()
{
  ConCommand::~ConCommand(this: &nav_generate);
}

//------------------------------------------------------------------------------
// Address: 0x104218E0
// Name: _dynamic_atexit_destructor_for__nav_generate_incremental__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_generate_incremental__()
{
  ConCommand::~ConCommand(this: &nav_generate_incremental);
}

//------------------------------------------------------------------------------
// Address: 0x104218F0
// Name: _dynamic_atexit_destructor_for__nav_analyze__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_analyze__()
{
  ConCommand::~ConCommand(this: &nav_analyze);
}

//------------------------------------------------------------------------------
// Address: 0x10421900
// Name: _dynamic_atexit_destructor_for__nav_analyze_scripted__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_analyze_scripted__()
{
  ConCommand::~ConCommand(this: &nav_analyze_scripted);
}

//------------------------------------------------------------------------------
// Address: 0x10421910
// Name: _dynamic_atexit_destructor_for__nav_mark_walkable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_mark_walkable__()
{
  ConCommand::~ConCommand(this: &nav_mark_walkable);
}

//------------------------------------------------------------------------------
// Address: 0x10421920
// Name: _dynamic_atexit_destructor_for__nav_clear_walkable_marks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_clear_walkable_marks__()
{
  ConCommand::~ConCommand(this: &nav_clear_walkable_marks);
}

//------------------------------------------------------------------------------
// Address: 0x10421930
// Name: _dynamic_atexit_destructor_for__nav_compress_id__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_compress_id__()
{
  ConCommand::~ConCommand(this: &nav_compress_id);
}

//------------------------------------------------------------------------------
// Address: 0x10421940
// Name: _dynamic_atexit_destructor_for__nav_build_ladder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_build_ladder__()
{
  ConCommand::~ConCommand(this: &nav_build_ladder);
}

//------------------------------------------------------------------------------
// Address: 0x10421950
// Name: _dynamic_atexit_destructor_for__ClearAllNavAttributes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ClearAllNavAttributes__()
{
  ConCommand::~ConCommand(this: &ClearAllNavAttributes);
}

//------------------------------------------------------------------------------
// Address: 0x10421960
// Name: _dynamic_atexit_destructor_for__NavClearAttribute__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__NavClearAttribute__()
{
  ConCommand::~ConCommand(this: &NavClearAttribute);
}

//------------------------------------------------------------------------------
// Address: 0x10421970
// Name: _dynamic_atexit_destructor_for__NavMarkAttribute__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__NavMarkAttribute__()
{
  ConCommand::~ConCommand(this: &NavMarkAttribute);
}

//------------------------------------------------------------------------------
// Address: 0x10421980
// Name: _dynamic_atexit_destructor_for__TheHidingSpots__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__TheHidingSpots__()
{
  if ( TheHidingSpots.m_pData != (CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData )
  {
    free(pMem: TheHidingSpots.m_pData);
    TheHidingSpots.m_pData = (CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *)&`CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::StaticData'::`2'::staticData;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104219A0
// Name: _dynamic_atexit_destructor_for__nav_show_nodes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_show_nodes__()
{
  ConVar::~ConVar(this: &nav_show_nodes);
}

//------------------------------------------------------------------------------
// Address: 0x104219B0
// Name: _dynamic_atexit_destructor_for__nav_show_node_id__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_show_node_id__()
{
  ConVar::~ConVar(this: &nav_show_node_id);
}

//------------------------------------------------------------------------------
// Address: 0x104219C0
// Name: _dynamic_atexit_destructor_for__nav_test_node__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_test_node__()
{
  ConVar::~ConVar(this: &nav_test_node);
}

//------------------------------------------------------------------------------
// Address: 0x104219D0
// Name: _dynamic_atexit_destructor_for__nav_test_node_crouch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_test_node_crouch__()
{
  ConVar::~ConVar(this: &nav_test_node_crouch);
}

//------------------------------------------------------------------------------
// Address: 0x104219E0
// Name: _dynamic_atexit_destructor_for__nav_test_node_crouch_dir__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_test_node_crouch_dir__()
{
  ConVar::~ConVar(this: &nav_test_node_crouch_dir);
}

//------------------------------------------------------------------------------
// Address: 0x104219F0
// Name: _dynamic_atexit_destructor_for__nav_show_node_grid__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__nav_show_node_grid__()
{
  ConVar::~ConVar(this: &nav_show_node_grid);
}
