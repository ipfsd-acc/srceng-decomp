// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/bot/states/cs_bot_escape_from_flames.cpp
// Functions: 15
// ============================================================

#include "game\server\cstrike15\bot\states\cs_bot_escape_from_flames.h"

//------------------------------------------------------------------------------
// Address: 0x102A76A0
// Name: void SearchSurroundingAreas<class CollectRetreatSpotsFunctor>(class CNavArea __near *,class Vector const __near &,class CollectRetreatSpotsFunctor __near &,float,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall SearchSurroundingAreas<CollectRetreatSpotsFunctor>(
        const CNavLadder *a1@<ebp>,
        CNavArea *startArea,
        const Vector *startPos,
        CollectRetreatSpotsFunctor *func,
        float maxRange,
        char options,
        int teamID)
{
  CNavArea *v7; // edi
  float v8; // xmm0_4
  int v9; // edx
  int v10; // eax
  float v11; // esi
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  bool v15; // cc
  float v16; // esi
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float *v20; // edx
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // eax
  int id; // eax
  int v23; // esi
  float v24; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm1_4
  int v27; // esi
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  int v31; // esi
  CNavArea *v32; // ecx
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm1_4
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v36; // eax
  int v37; // esi
  CNavArea *v38; // ecx
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm1_4
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v42; // eax
  unsigned int v43; // esi
  float v44; // xmm1_4
  float v45; // xmm2_4
  float v46; // xmm1_4
  Vector v47; // [esp-60h] [ebp-7Ch] BYREF
  Vector v48; // [esp-54h] [ebp-70h] BYREF
  Vector v49; // [esp-48h] [ebp-64h] BYREF
  Vector v50; // [esp-3Ch] [ebp-58h] BYREF
  Vector v51; // [esp-30h] [ebp-4Ch] BYREF
  Vector v52; // [esp-24h] [ebp-40h] BYREF
  Vector v53; // [esp-18h] [ebp-34h] BYREF
  int v54; // [esp-8h] [ebp-24h]
  float v55; // [esp-4h] [ebp-20h]
  int v56; // [esp+0h] [ebp-1Ch]
  int count; // [esp+4h] [ebp-18h]
  int v58; // [esp+8h] [ebp-14h]
  float **m_connect; // [esp+Ch] [ebp-10h]
  const CNavLadder *ladder; // [esp+10h] [ebp-Ch]
  int it; // [esp+14h] [ebp-8h]
  int retaddr; // [esp+1Ch] [ebp+0h]

  ladder = a1;
  it = retaddr;
  if ( startArea != nullptr )
  {
    if ( ++CNavArea::m_masterMarker == 0 )
      CNavArea::m_masterMarker = 1;
    CNavArea::ClearSearchLists();
    CNavArea::AddToOpenList(this: startArea);
    startArea->m_totalCost = 0.0;
    startArea->m_costSoFar = 0.0;
    startArea->m_parent = nullptr;
    startArea->m_parentHow = NUM_TRAVERSE_TYPES;
    startArea->m_marker = CNavArea::m_masterMarker;
    v7 = CNavArea::m_openList;
    while ( CNavArea::m_openList != nullptr )
    {
      if ( v7 != nullptr )
      {
        CNavArea::RemoveFromOpenList(this: v7);
        v7->m_prevOpen = nullptr;
        v7->m_nextOpen = nullptr;
      }
      else
      {
        v7 = nullptr;
      }
      if ( (!v7->IsBlocked(this: v7, a2: teamID, a3: false) || (options & 2) != 0)
        && CollectRetreatSpotsFunctor::operator()(this: func, area: v7) )
      {
        v8 = maxRange;
        m_connect = (float **)v7->m_connect;
        for ( count = 4; count != 0; --count )
        {
          v54 = *(int *)*m_connect;
          v58 = 0;
          if ( v54 > 0 )
          {
            v56 = options & 4;
            do
            {
              v9 = v58;
              v10 = 0;
              if ( *(int *)*m_connect <= 0 )
              {
LABEL_17:
                v11 = 0.0;
              }
              else
              {
                while ( v9 != 0 )
                {
                  ++v10;
                  --v9;
                  if ( v10 >= *(_DWORD *)*m_connect )
                    goto LABEL_17;
                }
                v11 = (*m_connect)[2 * v10 + 1];
              }
              if ( v56 == 0
                || (v8 = maxRange,
                    CNavArea::IsConnected(this: (CNavArea *)LODWORD(v11), area: v7, dir: NUM_DIRECTIONS) != 0) )
              {
                if ( v11 != 0.0 && *(_DWORD *)(LODWORD(v11) + 60) != CNavArea::m_masterMarker )
                {
                  *(_DWORD *)(LODWORD(v11) + 60) = CNavArea::m_masterMarker;
                  *(_DWORD *)(LODWORD(v11) + 64) = 0;
                  *(_DWORD *)(LODWORD(v11) + 120) = v7;
                  *(_DWORD *)(LODWORD(v11) + 124) = 9;
                  if ( v8 <= 0.0
                    || (CNavArea::GetClosestPointOnArea(this: (CNavArea *)LODWORD(v11), pPos: startPos, close: &v53),
                        v55 = (float)((float)(v53.x - startPos->x) * (float)(v53.x - startPos->x))
                            + (float)((float)(v53.y - startPos->y) * (float)(v53.y - startPos->y)),
                        (float)((v8 = maxRange) * v8) > v55)
                    && (v12 = *(float *)(LODWORD(v11) + 44) - v7->m_center.x,
                        v13 = *(float *)(LODWORD(v11) + 48) - v7->m_center.y,
                        v14 = v7->m_costSoFar
                            + fsqrt(
                                (float)((float)(v13 * v13)
                                      + (float)((float)(*(float *)(LODWORD(v11) + 52) - v7->m_center.z)
                                              * (float)(*(float *)(LODWORD(v11) + 52) - v7->m_center.z)))
                              + (float)(v12 * v12)),
                        *(float *)(LODWORD(v11) + 68) = v14,
                        (float)(maxRange * 1.5) >= v14) )
                  {
                    CNavArea::AddToOpenList(this: (CNavArea *)LODWORD(v11));
                    v8 = maxRange;
                  }
                }
              }
              ++v58;
            }
            while ( v58 < v54 );
          }
          ++m_connect;
        }
        if ( (options & 1) != 0 )
        {
          m_connect = (float **)v7->m_incomingConnect;
          for ( count = 4; count != 0; --count )
          {
            v15 = *(_DWORD *)*m_connect <= 0;
            v58 = 0;
            if ( !v15 )
            {
              do
              {
                v16 = (*m_connect)[2 * v58 + 1];
                v54 = SLODWORD((*m_connect)[2 * v58 + 2]);
                if ( v16 != 0.0 && *(_DWORD *)(LODWORD(v16) + 60) != CNavArea::m_masterMarker )
                {
                  *(_DWORD *)(LODWORD(v16) + 60) = CNavArea::m_masterMarker;
                  *(_DWORD *)(LODWORD(v16) + 64) = 0;
                  *(_DWORD *)(LODWORD(v16) + 120) = v7;
                  *(_DWORD *)(LODWORD(v16) + 124) = 9;
                  if ( v8 <= 0.0
                    || (CNavArea::GetClosestPointOnArea(this: (CNavArea *)LODWORD(v16), pPos: startPos, close: &v52),
                        (float)((v8 = maxRange) * v8) > (float)((float)((float)(v52.y - startPos->y)
                                                                      * (float)(v52.y - startPos->y))
                                                              + (float)((float)(v52.x - startPos->x)
                                                                      * (float)(v52.x - startPos->x))))
                    && (v17 = *(float *)(LODWORD(v16) + 44) - v7->m_center.x,
                        v18 = *(float *)(LODWORD(v16) + 48) - v7->m_center.y,
                        v19 = v7->m_costSoFar
                            + fsqrt(
                                (float)((float)(v18 * v18) + (float)(v17 * v17))
                              + (float)((float)(*(float *)(LODWORD(v16) + 52) - v7->m_center.z)
                                      * (float)(*(float *)(LODWORD(v16) + 52) - v7->m_center.z))),
                        *(float *)(LODWORD(v16) + 68) = v19,
                        (float)(maxRange * 1.5) >= v19) )
                  {
                    CNavArea::AddToOpenList(this: (CNavArea *)LODWORD(v16));
                    v8 = maxRange;
                  }
                }
                v20 = *m_connect;
                ++v58;
              }
              while ( v58 < *(_DWORD *)v20 );
            }
            ++m_connect;
          }
        }
        if ( v7 != (CNavArea *)-104 )
        {
          m_pData = v7->m_ladder[0].m_pData;
          v15 = m_pData->m_Size <= 0;
          v58 = 0;
          if ( !v15 )
          {
            do
            {
              id = m_pData->m_Elements[v58].id;
              v23 = *(_DWORD *)(id + 32);
              count = id;
              if ( v23 != 0 && *(_DWORD *)(v23 + 60) != CNavArea::m_masterMarker )
              {
                *(_DWORD *)(v23 + 60) = CNavArea::m_masterMarker;
                *(_DWORD *)(v23 + 64) = 0;
                *(_DWORD *)(v23 + 120) = v7;
                *(_DWORD *)(v23 + 124) = 9;
                if ( v8 <= 0.0
                  || (CNavArea::GetClosestPointOnArea(this: (CNavArea *)v23, pPos: startPos, close: &v51),
                      *(float *)&v54 = (float)((float)(v51.x - startPos->x) * (float)(v51.x - startPos->x))
                                     + (float)((float)(v51.y - startPos->y) * (float)(v51.y - startPos->y)),
                      (float)((v8 = maxRange) * v8) > *(float *)&v54)
                  && (v24 = *(float *)(v23 + 48) - v7->m_center.y,
                      v25 = *(float *)(v23 + 44) - v7->m_center.x,
                      v26 = v7->m_costSoFar
                          + fsqrt(
                              (float)((float)(v25 * v25) + (float)(v24 * v24))
                            + (float)((float)(*(float *)(v23 + 52) - v7->m_center.z)
                                    * (float)(*(float *)(v23 + 52) - v7->m_center.z))),
                      *(float *)(v23 + 68) = v26,
                      (float)(maxRange * 1.5) >= v26) )
                {
                  CNavArea::AddToOpenList(this: (CNavArea *)v23);
                  v8 = maxRange;
                }
              }
              v27 = *(_DWORD *)(count + 36);
              if ( v27 != 0 && *(_DWORD *)(v27 + 60) != CNavArea::m_masterMarker )
              {
                *(_DWORD *)(v27 + 60) = CNavArea::m_masterMarker;
                *(_DWORD *)(v27 + 64) = 0;
                *(_DWORD *)(v27 + 120) = v7;
                *(_DWORD *)(v27 + 124) = 9;
                if ( v8 <= 0.0
                  || (CNavArea::GetClosestPointOnArea(this: (CNavArea *)v27, pPos: startPos, close: &v50),
                      (float)((v8 = maxRange) * v8) > (float)((float)((float)(v50.y - startPos->y)
                                                                    * (float)(v50.y - startPos->y))
                                                            + (float)((float)(v50.x - startPos->x)
                                                                    * (float)(v50.x - startPos->x))))
                  && (v28 = *(float *)(v27 + 44) - v7->m_center.x,
                      v29 = *(float *)(v27 + 48) - v7->m_center.y,
                      v30 = v7->m_costSoFar
                          + fsqrt(
                              (float)((float)(v29 * v29)
                                    + (float)((float)(*(float *)(v27 + 52) - v7->m_center.z)
                                            * (float)(*(float *)(v27 + 52) - v7->m_center.z)))
                            + (float)(v28 * v28)),
                      *(float *)(v27 + 68) = v30,
                      (float)(maxRange * 1.5) >= v30) )
                {
                  CNavArea::AddToOpenList(this: (CNavArea *)v27);
                  v8 = maxRange;
                }
              }
              v31 = *(_DWORD *)(count + 40);
              if ( v31 != 0 && *(_DWORD *)(v31 + 60) != CNavArea::m_masterMarker )
              {
                *(_DWORD *)(v31 + 60) = CNavArea::m_masterMarker;
                *(_DWORD *)(v31 + 64) = 0;
                *(_DWORD *)(v31 + 120) = v7;
                *(_DWORD *)(v31 + 124) = 9;
                v32 = (CNavArea *)v31;
                if ( v8 > 0.0 )
                {
                  CNavArea::GetClosestPointOnArea(this: (CNavArea *)v31, pPos: startPos, close: &v49);
                  v8 = maxRange;
                  if ( (float)(v8 * v8) <= (float)((float)((float)(v49.y - startPos->y) * (float)(v49.y - startPos->y))
                                                 + (float)((float)(v49.x - startPos->x) * (float)(v49.x - startPos->x))) )
                    goto LABEL_60;
                  v33 = *(float *)(v31 + 44) - v7->m_center.x;
                  v34 = *(float *)(v31 + 48) - v7->m_center.y;
                  v35 = v7->m_costSoFar
                      + fsqrt(
                          (float)((float)(v34 * v34)
                                + (float)((float)(*(float *)(v31 + 52) - v7->m_center.z)
                                        * (float)(*(float *)(v31 + 52) - v7->m_center.z)))
                        + (float)(v33 * v33));
                  *(float *)(v31 + 68) = v35;
                  if ( (float)(maxRange * 1.5) < v35 )
                    goto LABEL_60;
                  v32 = (CNavArea *)v31;
                }
                CNavArea::AddToOpenList(this: v32);
                v8 = maxRange;
              }
LABEL_60:
              m_pData = v7->m_ladder[0].m_pData;
              ++v58;
            }
            while ( v58 < m_pData->m_Size );
          }
        }
        if ( v7 != (CNavArea *)-108 )
        {
          v36 = v7->m_ladder[1].m_pData;
          v15 = v36->m_Size <= 0;
          v58 = 0;
          if ( !v15 )
          {
            do
            {
              v37 = *(_DWORD *)(v36->m_Elements[v58].id + 48);
              if ( v37 != 0 && *(_DWORD *)(v37 + 60) != CNavArea::m_masterMarker )
              {
                *(_DWORD *)(v37 + 60) = CNavArea::m_masterMarker;
                *(_DWORD *)(v37 + 64) = 0;
                *(_DWORD *)(v37 + 120) = v7;
                *(_DWORD *)(v37 + 124) = 9;
                v38 = (CNavArea *)v37;
                if ( v8 > 0.0 )
                {
                  CNavArea::GetClosestPointOnArea(this: (CNavArea *)v37, pPos: startPos, close: &v48);
                  v8 = maxRange;
                  if ( (float)(v8 * v8) <= (float)((float)((float)(v48.y - startPos->y) * (float)(v48.y - startPos->y))
                                                 + (float)((float)(v48.x - startPos->x) * (float)(v48.x - startPos->x))) )
                    goto LABEL_70;
                  v39 = *(float *)(v37 + 44) - v7->m_center.x;
                  v40 = *(float *)(v37 + 48) - v7->m_center.y;
                  v41 = v7->m_costSoFar
                      + fsqrt(
                          (float)((float)(v40 * v40)
                                + (float)((float)(*(float *)(v37 + 52) - v7->m_center.z)
                                        * (float)(*(float *)(v37 + 52) - v7->m_center.z)))
                        + (float)(v39 * v39));
                  *(float *)(v37 + 68) = v41;
                  if ( (float)(maxRange * 1.5) < v41 )
                    goto LABEL_70;
                  v38 = (CNavArea *)v37;
                }
                CNavArea::AddToOpenList(this: v38);
                v8 = maxRange;
              }
LABEL_70:
              v36 = v7->m_ladder[1].m_pData;
              ++v58;
            }
            while ( v58 < v36->m_Size );
          }
        }
        if ( (options & 8) == 0 )
        {
          v42 = v7->m_elevatorAreas.m_pData;
          v15 = v42->m_Size <= 0;
          v58 = 0;
          if ( !v15 )
          {
            do
            {
              v43 = v42->m_Elements[v58].id;
              if ( v43 != 0 && *(_DWORD *)(v43 + 60) != CNavArea::m_masterMarker )
              {
                *(_DWORD *)(v43 + 60) = CNavArea::m_masterMarker;
                *(_DWORD *)(v43 + 64) = 0;
                *(_DWORD *)(v43 + 120) = v7;
                *(_DWORD *)(v43 + 124) = 9;
                if ( v8 <= 0.0
                  || (CNavArea::GetClosestPointOnArea(this: (CNavArea *)v43, pPos: startPos, close: &v47),
                      (float)((v8 = maxRange) * v8) > (float)((float)((float)(v47.y - startPos->y)
                                                                    * (float)(v47.y - startPos->y))
                                                            + (float)((float)(v47.x - startPos->x)
                                                                    * (float)(v47.x - startPos->x))))
                  && (v44 = *(float *)(v43 + 44) - v7->m_center.x,
                      v45 = *(float *)(v43 + 48) - v7->m_center.y,
                      v46 = v7->m_costSoFar
                          + fsqrt(
                              (float)((float)(v45 * v45)
                                    + (float)((float)(*(float *)(v43 + 52) - v7->m_center.z)
                                            * (float)(*(float *)(v43 + 52) - v7->m_center.z)))
                            + (float)(v44 * v44)),
                      *(float *)(v43 + 68) = v46,
                      (float)(maxRange * 1.5) >= v46) )
                {
                  CNavArea::AddToOpenList(this: (CNavArea *)v43);
                  v8 = maxRange;
                }
              }
              v42 = v7->m_elevatorAreas.m_pData;
              ++v58;
            }
            while ( v58 < v42->m_Size );
          }
        }
      }
      v7 = CNavArea::m_openList;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CBF60
// Name: void SearchSurroundingAreas<class CollectHidingSpotsFunctor>(class CNavArea __near *,class Vector const __near &,class CollectHidingSpotsFunctor __near &,float,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall SearchSurroundingAreas<CollectHidingSpotsFunctor>(
        const CNavLadder *a1@<ebp>,
        CNavArea *startArea,
        const Vector *startPos,
        CollectHidingSpotsFunctor *func,
        float maxRange,
        char options,
        int teamID)
{
  CNavArea *v7; // edi
  float v8; // xmm0_4
  int v9; // edx
  int v10; // eax
  float v11; // esi
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  bool v15; // cc
  float v16; // esi
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float *v20; // edx
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // eax
  int id; // eax
  int v23; // esi
  float v24; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm1_4
  int v27; // esi
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  int v31; // esi
  CNavArea *v32; // ecx
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm1_4
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v36; // eax
  int v37; // esi
  CNavArea *v38; // ecx
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm1_4
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v42; // eax
  unsigned int v43; // esi
  float v44; // xmm1_4
  float v45; // xmm2_4
  float v46; // xmm1_4
  Vector v47; // [esp-60h] [ebp-7Ch] BYREF
  Vector v48; // [esp-54h] [ebp-70h] BYREF
  Vector v49; // [esp-48h] [ebp-64h] BYREF
  Vector v50; // [esp-3Ch] [ebp-58h] BYREF
  Vector v51; // [esp-30h] [ebp-4Ch] BYREF
  Vector v52; // [esp-24h] [ebp-40h] BYREF
  Vector v53; // [esp-18h] [ebp-34h] BYREF
  int v54; // [esp-8h] [ebp-24h]
  float v55; // [esp-4h] [ebp-20h]
  int v56; // [esp+0h] [ebp-1Ch]
  int count; // [esp+4h] [ebp-18h]
  int v58; // [esp+8h] [ebp-14h]
  float **m_connect; // [esp+Ch] [ebp-10h]
  const CNavLadder *ladder; // [esp+10h] [ebp-Ch]
  int it; // [esp+14h] [ebp-8h]
  int retaddr; // [esp+1Ch] [ebp+0h]

  ladder = a1;
  it = retaddr;
  if ( startArea != nullptr )
  {
    if ( ++CNavArea::m_masterMarker == 0 )
      CNavArea::m_masterMarker = 1;
    CNavArea::ClearSearchLists();
    CNavArea::AddToOpenList(this: startArea);
    startArea->m_totalCost = 0.0;
    startArea->m_costSoFar = 0.0;
    startArea->m_parent = nullptr;
    startArea->m_parentHow = NUM_TRAVERSE_TYPES;
    startArea->m_marker = CNavArea::m_masterMarker;
    v7 = CNavArea::m_openList;
    while ( CNavArea::m_openList != nullptr )
    {
      if ( v7 != nullptr )
      {
        CNavArea::RemoveFromOpenList(this: v7);
        v7->m_prevOpen = nullptr;
        v7->m_nextOpen = nullptr;
      }
      else
      {
        v7 = nullptr;
      }
      if ( (!v7->IsBlocked(this: v7, a2: teamID, a3: false) || (options & 2) != 0)
        && CollectHidingSpotsFunctor::operator()(this: func, area: v7) )
      {
        v8 = maxRange;
        m_connect = (float **)v7->m_connect;
        for ( count = 4; count != 0; --count )
        {
          v54 = *(int *)*m_connect;
          v58 = 0;
          if ( v54 > 0 )
          {
            v56 = options & 4;
            do
            {
              v9 = v58;
              v10 = 0;
              if ( *(int *)*m_connect <= 0 )
              {
LABEL_17:
                v11 = 0.0;
              }
              else
              {
                while ( v9 != 0 )
                {
                  ++v10;
                  --v9;
                  if ( v10 >= *(_DWORD *)*m_connect )
                    goto LABEL_17;
                }
                v11 = (*m_connect)[2 * v10 + 1];
              }
              if ( v56 == 0
                || (v8 = maxRange,
                    CNavArea::IsConnected(this: (CNavArea *)LODWORD(v11), area: v7, dir: NUM_DIRECTIONS) != 0) )
              {
                if ( v11 != 0.0 && *(_DWORD *)(LODWORD(v11) + 60) != CNavArea::m_masterMarker )
                {
                  *(_DWORD *)(LODWORD(v11) + 60) = CNavArea::m_masterMarker;
                  *(_DWORD *)(LODWORD(v11) + 64) = 0;
                  *(_DWORD *)(LODWORD(v11) + 120) = v7;
                  *(_DWORD *)(LODWORD(v11) + 124) = 9;
                  if ( v8 <= 0.0
                    || (CNavArea::GetClosestPointOnArea(this: (CNavArea *)LODWORD(v11), pPos: startPos, close: &v53),
                        v55 = (float)((float)(v53.x - startPos->x) * (float)(v53.x - startPos->x))
                            + (float)((float)(v53.y - startPos->y) * (float)(v53.y - startPos->y)),
                        (float)((v8 = maxRange) * v8) > v55)
                    && (v12 = *(float *)(LODWORD(v11) + 44) - v7->m_center.x,
                        v13 = *(float *)(LODWORD(v11) + 48) - v7->m_center.y,
                        v14 = v7->m_costSoFar
                            + fsqrt(
                                (float)((float)(v13 * v13)
                                      + (float)((float)(*(float *)(LODWORD(v11) + 52) - v7->m_center.z)
                                              * (float)(*(float *)(LODWORD(v11) + 52) - v7->m_center.z)))
                              + (float)(v12 * v12)),
                        *(float *)(LODWORD(v11) + 68) = v14,
                        (float)(maxRange * 1.5) >= v14) )
                  {
                    CNavArea::AddToOpenList(this: (CNavArea *)LODWORD(v11));
                    v8 = maxRange;
                  }
                }
              }
              ++v58;
            }
            while ( v58 < v54 );
          }
          ++m_connect;
        }
        if ( (options & 1) != 0 )
        {
          m_connect = (float **)v7->m_incomingConnect;
          for ( count = 4; count != 0; --count )
          {
            v15 = *(_DWORD *)*m_connect <= 0;
            v58 = 0;
            if ( !v15 )
            {
              do
              {
                v16 = (*m_connect)[2 * v58 + 1];
                v54 = SLODWORD((*m_connect)[2 * v58 + 2]);
                if ( v16 != 0.0 && *(_DWORD *)(LODWORD(v16) + 60) != CNavArea::m_masterMarker )
                {
                  *(_DWORD *)(LODWORD(v16) + 60) = CNavArea::m_masterMarker;
                  *(_DWORD *)(LODWORD(v16) + 64) = 0;
                  *(_DWORD *)(LODWORD(v16) + 120) = v7;
                  *(_DWORD *)(LODWORD(v16) + 124) = 9;
                  if ( v8 <= 0.0
                    || (CNavArea::GetClosestPointOnArea(this: (CNavArea *)LODWORD(v16), pPos: startPos, close: &v52),
                        (float)((v8 = maxRange) * v8) > (float)((float)((float)(v52.y - startPos->y)
                                                                      * (float)(v52.y - startPos->y))
                                                              + (float)((float)(v52.x - startPos->x)
                                                                      * (float)(v52.x - startPos->x))))
                    && (v17 = *(float *)(LODWORD(v16) + 44) - v7->m_center.x,
                        v18 = *(float *)(LODWORD(v16) + 48) - v7->m_center.y,
                        v19 = v7->m_costSoFar
                            + fsqrt(
                                (float)((float)(v18 * v18) + (float)(v17 * v17))
                              + (float)((float)(*(float *)(LODWORD(v16) + 52) - v7->m_center.z)
                                      * (float)(*(float *)(LODWORD(v16) + 52) - v7->m_center.z))),
                        *(float *)(LODWORD(v16) + 68) = v19,
                        (float)(maxRange * 1.5) >= v19) )
                  {
                    CNavArea::AddToOpenList(this: (CNavArea *)LODWORD(v16));
                    v8 = maxRange;
                  }
                }
                v20 = *m_connect;
                ++v58;
              }
              while ( v58 < *(_DWORD *)v20 );
            }
            ++m_connect;
          }
        }
        if ( v7 != (CNavArea *)-104 )
        {
          m_pData = v7->m_ladder[0].m_pData;
          v15 = m_pData->m_Size <= 0;
          v58 = 0;
          if ( !v15 )
          {
            do
            {
              id = m_pData->m_Elements[v58].id;
              v23 = *(_DWORD *)(id + 32);
              count = id;
              if ( v23 != 0 && *(_DWORD *)(v23 + 60) != CNavArea::m_masterMarker )
              {
                *(_DWORD *)(v23 + 60) = CNavArea::m_masterMarker;
                *(_DWORD *)(v23 + 64) = 0;
                *(_DWORD *)(v23 + 120) = v7;
                *(_DWORD *)(v23 + 124) = 9;
                if ( v8 <= 0.0
                  || (CNavArea::GetClosestPointOnArea(this: (CNavArea *)v23, pPos: startPos, close: &v51),
                      *(float *)&v54 = (float)((float)(v51.x - startPos->x) * (float)(v51.x - startPos->x))
                                     + (float)((float)(v51.y - startPos->y) * (float)(v51.y - startPos->y)),
                      (float)((v8 = maxRange) * v8) > *(float *)&v54)
                  && (v24 = *(float *)(v23 + 48) - v7->m_center.y,
                      v25 = *(float *)(v23 + 44) - v7->m_center.x,
                      v26 = v7->m_costSoFar
                          + fsqrt(
                              (float)((float)(v25 * v25) + (float)(v24 * v24))
                            + (float)((float)(*(float *)(v23 + 52) - v7->m_center.z)
                                    * (float)(*(float *)(v23 + 52) - v7->m_center.z))),
                      *(float *)(v23 + 68) = v26,
                      (float)(maxRange * 1.5) >= v26) )
                {
                  CNavArea::AddToOpenList(this: (CNavArea *)v23);
                  v8 = maxRange;
                }
              }
              v27 = *(_DWORD *)(count + 36);
              if ( v27 != 0 && *(_DWORD *)(v27 + 60) != CNavArea::m_masterMarker )
              {
                *(_DWORD *)(v27 + 60) = CNavArea::m_masterMarker;
                *(_DWORD *)(v27 + 64) = 0;
                *(_DWORD *)(v27 + 120) = v7;
                *(_DWORD *)(v27 + 124) = 9;
                if ( v8 <= 0.0
                  || (CNavArea::GetClosestPointOnArea(this: (CNavArea *)v27, pPos: startPos, close: &v50),
                      (float)((v8 = maxRange) * v8) > (float)((float)((float)(v50.y - startPos->y)
                                                                    * (float)(v50.y - startPos->y))
                                                            + (float)((float)(v50.x - startPos->x)
                                                                    * (float)(v50.x - startPos->x))))
                  && (v28 = *(float *)(v27 + 44) - v7->m_center.x,
                      v29 = *(float *)(v27 + 48) - v7->m_center.y,
                      v30 = v7->m_costSoFar
                          + fsqrt(
                              (float)((float)(v29 * v29)
                                    + (float)((float)(*(float *)(v27 + 52) - v7->m_center.z)
                                            * (float)(*(float *)(v27 + 52) - v7->m_center.z)))
                            + (float)(v28 * v28)),
                      *(float *)(v27 + 68) = v30,
                      (float)(maxRange * 1.5) >= v30) )
                {
                  CNavArea::AddToOpenList(this: (CNavArea *)v27);
                  v8 = maxRange;
                }
              }
              v31 = *(_DWORD *)(count + 40);
              if ( v31 != 0 && *(_DWORD *)(v31 + 60) != CNavArea::m_masterMarker )
              {
                *(_DWORD *)(v31 + 60) = CNavArea::m_masterMarker;
                *(_DWORD *)(v31 + 64) = 0;
                *(_DWORD *)(v31 + 120) = v7;
                *(_DWORD *)(v31 + 124) = 9;
                v32 = (CNavArea *)v31;
                if ( v8 > 0.0 )
                {
                  CNavArea::GetClosestPointOnArea(this: (CNavArea *)v31, pPos: startPos, close: &v49);
                  v8 = maxRange;
                  if ( (float)(v8 * v8) <= (float)((float)((float)(v49.y - startPos->y) * (float)(v49.y - startPos->y))
                                                 + (float)((float)(v49.x - startPos->x) * (float)(v49.x - startPos->x))) )
                    goto LABEL_60;
                  v33 = *(float *)(v31 + 44) - v7->m_center.x;
                  v34 = *(float *)(v31 + 48) - v7->m_center.y;
                  v35 = v7->m_costSoFar
                      + fsqrt(
                          (float)((float)(v34 * v34)
                                + (float)((float)(*(float *)(v31 + 52) - v7->m_center.z)
                                        * (float)(*(float *)(v31 + 52) - v7->m_center.z)))
                        + (float)(v33 * v33));
                  *(float *)(v31 + 68) = v35;
                  if ( (float)(maxRange * 1.5) < v35 )
                    goto LABEL_60;
                  v32 = (CNavArea *)v31;
                }
                CNavArea::AddToOpenList(this: v32);
                v8 = maxRange;
              }
LABEL_60:
              m_pData = v7->m_ladder[0].m_pData;
              ++v58;
            }
            while ( v58 < m_pData->m_Size );
          }
        }
        if ( v7 != (CNavArea *)-108 )
        {
          v36 = v7->m_ladder[1].m_pData;
          v15 = v36->m_Size <= 0;
          v58 = 0;
          if ( !v15 )
          {
            do
            {
              v37 = *(_DWORD *)(v36->m_Elements[v58].id + 48);
              if ( v37 != 0 && *(_DWORD *)(v37 + 60) != CNavArea::m_masterMarker )
              {
                *(_DWORD *)(v37 + 60) = CNavArea::m_masterMarker;
                *(_DWORD *)(v37 + 64) = 0;
                *(_DWORD *)(v37 + 120) = v7;
                *(_DWORD *)(v37 + 124) = 9;
                v38 = (CNavArea *)v37;
                if ( v8 > 0.0 )
                {
                  CNavArea::GetClosestPointOnArea(this: (CNavArea *)v37, pPos: startPos, close: &v48);
                  v8 = maxRange;
                  if ( (float)(v8 * v8) <= (float)((float)((float)(v48.y - startPos->y) * (float)(v48.y - startPos->y))
                                                 + (float)((float)(v48.x - startPos->x) * (float)(v48.x - startPos->x))) )
                    goto LABEL_70;
                  v39 = *(float *)(v37 + 44) - v7->m_center.x;
                  v40 = *(float *)(v37 + 48) - v7->m_center.y;
                  v41 = v7->m_costSoFar
                      + fsqrt(
                          (float)((float)(v40 * v40)
                                + (float)((float)(*(float *)(v37 + 52) - v7->m_center.z)
                                        * (float)(*(float *)(v37 + 52) - v7->m_center.z)))
                        + (float)(v39 * v39));
                  *(float *)(v37 + 68) = v41;
                  if ( (float)(maxRange * 1.5) < v41 )
                    goto LABEL_70;
                  v38 = (CNavArea *)v37;
                }
                CNavArea::AddToOpenList(this: v38);
                v8 = maxRange;
              }
LABEL_70:
              v36 = v7->m_ladder[1].m_pData;
              ++v58;
            }
            while ( v58 < v36->m_Size );
          }
        }
        if ( (options & 8) == 0 )
        {
          v42 = v7->m_elevatorAreas.m_pData;
          v15 = v42->m_Size <= 0;
          v58 = 0;
          if ( !v15 )
          {
            do
            {
              v43 = v42->m_Elements[v58].id;
              if ( v43 != 0 && *(_DWORD *)(v43 + 60) != CNavArea::m_masterMarker )
              {
                *(_DWORD *)(v43 + 60) = CNavArea::m_masterMarker;
                *(_DWORD *)(v43 + 64) = 0;
                *(_DWORD *)(v43 + 120) = v7;
                *(_DWORD *)(v43 + 124) = 9;
                if ( v8 <= 0.0
                  || (CNavArea::GetClosestPointOnArea(this: (CNavArea *)v43, pPos: startPos, close: &v47),
                      (float)((v8 = maxRange) * v8) > (float)((float)((float)(v47.y - startPos->y)
                                                                    * (float)(v47.y - startPos->y))
                                                            + (float)((float)(v47.x - startPos->x)
                                                                    * (float)(v47.x - startPos->x))))
                  && (v44 = *(float *)(v43 + 44) - v7->m_center.x,
                      v45 = *(float *)(v43 + 48) - v7->m_center.y,
                      v46 = v7->m_costSoFar
                          + fsqrt(
                              (float)((float)(v45 * v45)
                                    + (float)((float)(*(float *)(v43 + 52) - v7->m_center.z)
                                            * (float)(*(float *)(v43 + 52) - v7->m_center.z)))
                            + (float)(v44 * v44)),
                      *(float *)(v43 + 68) = v46,
                      (float)(maxRange * 1.5) >= v46) )
                {
                  CNavArea::AddToOpenList(this: (CNavArea *)v43);
                  v8 = maxRange;
                }
              }
              v42 = v7->m_elevatorAreas.m_pData;
              ++v58;
            }
            while ( v58 < v42->m_Size );
          }
        }
      }
      v7 = CNavArea::m_openList;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CC840
// Name: void SearchSurroundingAreas<class CollectArriveFirstSpotsFunctor>(class CNavArea __near *,class Vector const __near &,class CollectArriveFirstSpotsFunctor __near &,float,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall SearchSurroundingAreas<CollectArriveFirstSpotsFunctor>(
        const CNavLadder *a1@<ebp>,
        CNavArea *startArea,
        const Vector *startPos,
        CollectArriveFirstSpotsFunctor *func,
        float maxRange,
        char options,
        int teamID)
{
  CNavArea *v7; // edi
  float v8; // xmm0_4
  int v9; // edx
  int v10; // eax
  float v11; // esi
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  bool v15; // cc
  float v16; // esi
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float *v20; // edx
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // eax
  int id; // eax
  int v23; // esi
  float v24; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm1_4
  int v27; // esi
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  int v31; // esi
  CNavArea *v32; // ecx
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm1_4
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v36; // eax
  int v37; // esi
  CNavArea *v38; // ecx
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm1_4
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v42; // eax
  unsigned int v43; // esi
  float v44; // xmm1_4
  float v45; // xmm2_4
  float v46; // xmm1_4
  Vector v47; // [esp-60h] [ebp-7Ch] BYREF
  Vector v48; // [esp-54h] [ebp-70h] BYREF
  Vector v49; // [esp-48h] [ebp-64h] BYREF
  Vector v50; // [esp-3Ch] [ebp-58h] BYREF
  Vector v51; // [esp-30h] [ebp-4Ch] BYREF
  Vector v52; // [esp-24h] [ebp-40h] BYREF
  Vector v53; // [esp-18h] [ebp-34h] BYREF
  int v54; // [esp-8h] [ebp-24h]
  float v55; // [esp-4h] [ebp-20h]
  int v56; // [esp+0h] [ebp-1Ch]
  int count; // [esp+4h] [ebp-18h]
  int v58; // [esp+8h] [ebp-14h]
  float **m_connect; // [esp+Ch] [ebp-10h]
  const CNavLadder *ladder; // [esp+10h] [ebp-Ch]
  int it; // [esp+14h] [ebp-8h]
  int retaddr; // [esp+1Ch] [ebp+0h]

  ladder = a1;
  it = retaddr;
  if ( startArea != nullptr )
  {
    if ( ++CNavArea::m_masterMarker == 0 )
      CNavArea::m_masterMarker = 1;
    CNavArea::ClearSearchLists();
    CNavArea::AddToOpenList(this: startArea);
    startArea->m_totalCost = 0.0;
    startArea->m_costSoFar = 0.0;
    startArea->m_parent = nullptr;
    startArea->m_parentHow = NUM_TRAVERSE_TYPES;
    startArea->m_marker = CNavArea::m_masterMarker;
    v7 = CNavArea::m_openList;
    while ( CNavArea::m_openList != nullptr )
    {
      if ( v7 != nullptr )
      {
        CNavArea::RemoveFromOpenList(this: v7);
        v7->m_prevOpen = nullptr;
        v7->m_nextOpen = nullptr;
      }
      else
      {
        v7 = nullptr;
      }
      if ( (!v7->IsBlocked(this: v7, a2: teamID, a3: false) || (options & 2) != 0)
        && CollectArriveFirstSpotsFunctor::operator()(this: func, area: v7) )
      {
        v8 = maxRange;
        m_connect = (float **)v7->m_connect;
        for ( count = 4; count != 0; --count )
        {
          v54 = *(int *)*m_connect;
          v58 = 0;
          if ( v54 > 0 )
          {
            v56 = options & 4;
            do
            {
              v9 = v58;
              v10 = 0;
              if ( *(int *)*m_connect <= 0 )
              {
LABEL_17:
                v11 = 0.0;
              }
              else
              {
                while ( v9 != 0 )
                {
                  ++v10;
                  --v9;
                  if ( v10 >= *(_DWORD *)*m_connect )
                    goto LABEL_17;
                }
                v11 = (*m_connect)[2 * v10 + 1];
              }
              if ( v56 == 0
                || (v8 = maxRange,
                    CNavArea::IsConnected(this: (CNavArea *)LODWORD(v11), area: v7, dir: NUM_DIRECTIONS) != 0) )
              {
                if ( v11 != 0.0 && *(_DWORD *)(LODWORD(v11) + 60) != CNavArea::m_masterMarker )
                {
                  *(_DWORD *)(LODWORD(v11) + 60) = CNavArea::m_masterMarker;
                  *(_DWORD *)(LODWORD(v11) + 64) = 0;
                  *(_DWORD *)(LODWORD(v11) + 120) = v7;
                  *(_DWORD *)(LODWORD(v11) + 124) = 9;
                  if ( v8 <= 0.0
                    || (CNavArea::GetClosestPointOnArea(this: (CNavArea *)LODWORD(v11), pPos: startPos, close: &v53),
                        v55 = (float)((float)(v53.x - startPos->x) * (float)(v53.x - startPos->x))
                            + (float)((float)(v53.y - startPos->y) * (float)(v53.y - startPos->y)),
                        (float)((v8 = maxRange) * v8) > v55)
                    && (v12 = *(float *)(LODWORD(v11) + 44) - v7->m_center.x,
                        v13 = *(float *)(LODWORD(v11) + 48) - v7->m_center.y,
                        v14 = v7->m_costSoFar
                            + fsqrt(
                                (float)((float)(v13 * v13)
                                      + (float)((float)(*(float *)(LODWORD(v11) + 52) - v7->m_center.z)
                                              * (float)(*(float *)(LODWORD(v11) + 52) - v7->m_center.z)))
                              + (float)(v12 * v12)),
                        *(float *)(LODWORD(v11) + 68) = v14,
                        (float)(maxRange * 1.5) >= v14) )
                  {
                    CNavArea::AddToOpenList(this: (CNavArea *)LODWORD(v11));
                    v8 = maxRange;
                  }
                }
              }
              ++v58;
            }
            while ( v58 < v54 );
          }
          ++m_connect;
        }
        if ( (options & 1) != 0 )
        {
          m_connect = (float **)v7->m_incomingConnect;
          for ( count = 4; count != 0; --count )
          {
            v15 = *(_DWORD *)*m_connect <= 0;
            v58 = 0;
            if ( !v15 )
            {
              do
              {
                v16 = (*m_connect)[2 * v58 + 1];
                v54 = SLODWORD((*m_connect)[2 * v58 + 2]);
                if ( v16 != 0.0 && *(_DWORD *)(LODWORD(v16) + 60) != CNavArea::m_masterMarker )
                {
                  *(_DWORD *)(LODWORD(v16) + 60) = CNavArea::m_masterMarker;
                  *(_DWORD *)(LODWORD(v16) + 64) = 0;
                  *(_DWORD *)(LODWORD(v16) + 120) = v7;
                  *(_DWORD *)(LODWORD(v16) + 124) = 9;
                  if ( v8 <= 0.0
                    || (CNavArea::GetClosestPointOnArea(this: (CNavArea *)LODWORD(v16), pPos: startPos, close: &v52),
                        (float)((v8 = maxRange) * v8) > (float)((float)((float)(v52.y - startPos->y)
                                                                      * (float)(v52.y - startPos->y))
                                                              + (float)((float)(v52.x - startPos->x)
                                                                      * (float)(v52.x - startPos->x))))
                    && (v17 = *(float *)(LODWORD(v16) + 44) - v7->m_center.x,
                        v18 = *(float *)(LODWORD(v16) + 48) - v7->m_center.y,
                        v19 = v7->m_costSoFar
                            + fsqrt(
                                (float)((float)(v18 * v18) + (float)(v17 * v17))
                              + (float)((float)(*(float *)(LODWORD(v16) + 52) - v7->m_center.z)
                                      * (float)(*(float *)(LODWORD(v16) + 52) - v7->m_center.z))),
                        *(float *)(LODWORD(v16) + 68) = v19,
                        (float)(maxRange * 1.5) >= v19) )
                  {
                    CNavArea::AddToOpenList(this: (CNavArea *)LODWORD(v16));
                    v8 = maxRange;
                  }
                }
                v20 = *m_connect;
                ++v58;
              }
              while ( v58 < *(_DWORD *)v20 );
            }
            ++m_connect;
          }
        }
        if ( v7 != (CNavArea *)-104 )
        {
          m_pData = v7->m_ladder[0].m_pData;
          v15 = m_pData->m_Size <= 0;
          v58 = 0;
          if ( !v15 )
          {
            do
            {
              id = m_pData->m_Elements[v58].id;
              v23 = *(_DWORD *)(id + 32);
              count = id;
              if ( v23 != 0 && *(_DWORD *)(v23 + 60) != CNavArea::m_masterMarker )
              {
                *(_DWORD *)(v23 + 60) = CNavArea::m_masterMarker;
                *(_DWORD *)(v23 + 64) = 0;
                *(_DWORD *)(v23 + 120) = v7;
                *(_DWORD *)(v23 + 124) = 9;
                if ( v8 <= 0.0
                  || (CNavArea::GetClosestPointOnArea(this: (CNavArea *)v23, pPos: startPos, close: &v51),
                      *(float *)&v54 = (float)((float)(v51.x - startPos->x) * (float)(v51.x - startPos->x))
                                     + (float)((float)(v51.y - startPos->y) * (float)(v51.y - startPos->y)),
                      (float)((v8 = maxRange) * v8) > *(float *)&v54)
                  && (v24 = *(float *)(v23 + 48) - v7->m_center.y,
                      v25 = *(float *)(v23 + 44) - v7->m_center.x,
                      v26 = v7->m_costSoFar
                          + fsqrt(
                              (float)((float)(v25 * v25) + (float)(v24 * v24))
                            + (float)((float)(*(float *)(v23 + 52) - v7->m_center.z)
                                    * (float)(*(float *)(v23 + 52) - v7->m_center.z))),
                      *(float *)(v23 + 68) = v26,
                      (float)(maxRange * 1.5) >= v26) )
                {
                  CNavArea::AddToOpenList(this: (CNavArea *)v23);
                  v8 = maxRange;
                }
              }
              v27 = *(_DWORD *)(count + 36);
              if ( v27 != 0 && *(_DWORD *)(v27 + 60) != CNavArea::m_masterMarker )
              {
                *(_DWORD *)(v27 + 60) = CNavArea::m_masterMarker;
                *(_DWORD *)(v27 + 64) = 0;
                *(_DWORD *)(v27 + 120) = v7;
                *(_DWORD *)(v27 + 124) = 9;
                if ( v8 <= 0.0
                  || (CNavArea::GetClosestPointOnArea(this: (CNavArea *)v27, pPos: startPos, close: &v50),
                      (float)((v8 = maxRange) * v8) > (float)((float)((float)(v50.y - startPos->y)
                                                                    * (float)(v50.y - startPos->y))
                                                            + (float)((float)(v50.x - startPos->x)
                                                                    * (float)(v50.x - startPos->x))))
                  && (v28 = *(float *)(v27 + 44) - v7->m_center.x,
                      v29 = *(float *)(v27 + 48) - v7->m_center.y,
                      v30 = v7->m_costSoFar
                          + fsqrt(
                              (float)((float)(v29 * v29)
                                    + (float)((float)(*(float *)(v27 + 52) - v7->m_center.z)
                                            * (float)(*(float *)(v27 + 52) - v7->m_center.z)))
                            + (float)(v28 * v28)),
                      *(float *)(v27 + 68) = v30,
                      (float)(maxRange * 1.5) >= v30) )
                {
                  CNavArea::AddToOpenList(this: (CNavArea *)v27);
                  v8 = maxRange;
                }
              }
              v31 = *(_DWORD *)(count + 40);
              if ( v31 != 0 && *(_DWORD *)(v31 + 60) != CNavArea::m_masterMarker )
              {
                *(_DWORD *)(v31 + 60) = CNavArea::m_masterMarker;
                *(_DWORD *)(v31 + 64) = 0;
                *(_DWORD *)(v31 + 120) = v7;
                *(_DWORD *)(v31 + 124) = 9;
                v32 = (CNavArea *)v31;
                if ( v8 > 0.0 )
                {
                  CNavArea::GetClosestPointOnArea(this: (CNavArea *)v31, pPos: startPos, close: &v49);
                  v8 = maxRange;
                  if ( (float)(v8 * v8) <= (float)((float)((float)(v49.y - startPos->y) * (float)(v49.y - startPos->y))
                                                 + (float)((float)(v49.x - startPos->x) * (float)(v49.x - startPos->x))) )
                    goto LABEL_60;
                  v33 = *(float *)(v31 + 44) - v7->m_center.x;
                  v34 = *(float *)(v31 + 48) - v7->m_center.y;
                  v35 = v7->m_costSoFar
                      + fsqrt(
                          (float)((float)(v34 * v34)
                                + (float)((float)(*(float *)(v31 + 52) - v7->m_center.z)
                                        * (float)(*(float *)(v31 + 52) - v7->m_center.z)))
                        + (float)(v33 * v33));
                  *(float *)(v31 + 68) = v35;
                  if ( (float)(maxRange * 1.5) < v35 )
                    goto LABEL_60;
                  v32 = (CNavArea *)v31;
                }
                CNavArea::AddToOpenList(this: v32);
                v8 = maxRange;
              }
LABEL_60:
              m_pData = v7->m_ladder[0].m_pData;
              ++v58;
            }
            while ( v58 < m_pData->m_Size );
          }
        }
        if ( v7 != (CNavArea *)-108 )
        {
          v36 = v7->m_ladder[1].m_pData;
          v15 = v36->m_Size <= 0;
          v58 = 0;
          if ( !v15 )
          {
            do
            {
              v37 = *(_DWORD *)(v36->m_Elements[v58].id + 48);
              if ( v37 != 0 && *(_DWORD *)(v37 + 60) != CNavArea::m_masterMarker )
              {
                *(_DWORD *)(v37 + 60) = CNavArea::m_masterMarker;
                *(_DWORD *)(v37 + 64) = 0;
                *(_DWORD *)(v37 + 120) = v7;
                *(_DWORD *)(v37 + 124) = 9;
                v38 = (CNavArea *)v37;
                if ( v8 > 0.0 )
                {
                  CNavArea::GetClosestPointOnArea(this: (CNavArea *)v37, pPos: startPos, close: &v48);
                  v8 = maxRange;
                  if ( (float)(v8 * v8) <= (float)((float)((float)(v48.y - startPos->y) * (float)(v48.y - startPos->y))
                                                 + (float)((float)(v48.x - startPos->x) * (float)(v48.x - startPos->x))) )
                    goto LABEL_70;
                  v39 = *(float *)(v37 + 44) - v7->m_center.x;
                  v40 = *(float *)(v37 + 48) - v7->m_center.y;
                  v41 = v7->m_costSoFar
                      + fsqrt(
                          (float)((float)(v40 * v40)
                                + (float)((float)(*(float *)(v37 + 52) - v7->m_center.z)
                                        * (float)(*(float *)(v37 + 52) - v7->m_center.z)))
                        + (float)(v39 * v39));
                  *(float *)(v37 + 68) = v41;
                  if ( (float)(maxRange * 1.5) < v41 )
                    goto LABEL_70;
                  v38 = (CNavArea *)v37;
                }
                CNavArea::AddToOpenList(this: v38);
                v8 = maxRange;
              }
LABEL_70:
              v36 = v7->m_ladder[1].m_pData;
              ++v58;
            }
            while ( v58 < v36->m_Size );
          }
        }
        if ( (options & 8) == 0 )
        {
          v42 = v7->m_elevatorAreas.m_pData;
          v15 = v42->m_Size <= 0;
          v58 = 0;
          if ( !v15 )
          {
            do
            {
              v43 = v42->m_Elements[v58].id;
              if ( v43 != 0 && *(_DWORD *)(v43 + 60) != CNavArea::m_masterMarker )
              {
                *(_DWORD *)(v43 + 60) = CNavArea::m_masterMarker;
                *(_DWORD *)(v43 + 64) = 0;
                *(_DWORD *)(v43 + 120) = v7;
                *(_DWORD *)(v43 + 124) = 9;
                if ( v8 <= 0.0
                  || (CNavArea::GetClosestPointOnArea(this: (CNavArea *)v43, pPos: startPos, close: &v47),
                      (float)((v8 = maxRange) * v8) > (float)((float)((float)(v47.y - startPos->y)
                                                                    * (float)(v47.y - startPos->y))
                                                            + (float)((float)(v47.x - startPos->x)
                                                                    * (float)(v47.x - startPos->x))))
                  && (v44 = *(float *)(v43 + 44) - v7->m_center.x,
                      v45 = *(float *)(v43 + 48) - v7->m_center.y,
                      v46 = v7->m_costSoFar
                          + fsqrt(
                              (float)((float)(v45 * v45)
                                    + (float)((float)(*(float *)(v43 + 52) - v7->m_center.z)
                                            * (float)(*(float *)(v43 + 52) - v7->m_center.z)))
                            + (float)(v44 * v44)),
                      *(float *)(v43 + 68) = v46,
                      (float)(maxRange * 1.5) >= v46) )
                {
                  CNavArea::AddToOpenList(this: (CNavArea *)v43);
                  v8 = maxRange;
                }
              }
              v42 = v7->m_elevatorAreas.m_pData;
              ++v58;
            }
            while ( v58 < v42->m_Size );
          }
        }
      }
      v7 = CNavArea::m_openList;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D2C20
// Name: public: virtual void EscapeFromFlamesState::OnExit(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall EscapeFromFlamesState::OnExit(EscapeFromBombState *this, CCSBot *me)
{
  CCSBot::EquipBestWeapon(this: me, mustEquip: false);
}

//------------------------------------------------------------------------------
// Address: 0x102D2FD0
// Name: public: virtual bool ISearchSurroundingAreasFunctor::ShouldSearch(class CNavArea __near *,class CNavArea __near *,float)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall ISearchSurroundingAreasFunctor::ShouldSearch(
        ISearchSurroundingAreasFunctor *this,
        CNavArea *adjArea,
        CNavArea *currentArea,
        float travelDistanceSoFar)
{
  return !adjArea->IsBlocked(this: adjArea, a2: -1, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102D3020
// Name: public: virtual void ISearchSurroundingAreasFunctor::IterateAdjacentAreas(class CNavArea __near *,class CNavArea __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ISearchSurroundingAreasFunctor::IterateAdjacentAreas(
        ISearchSurroundingAreasFunctor *this,
        CNavArea *area,
        CNavArea *priorArea,
        float travelDistanceSoFar)
{
  int v4; // edx
  int v5; // eax
  unsigned int id; // esi
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  int m_Size; // [esp+30h] [ebp-20h]
  int i; // [esp+38h] [ebp-18h]
  int count; // [esp+3Ch] [ebp-14h]
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *m_connect; // [esp+40h] [ebp-10h]

  m_connect = area->m_connect;
  for ( i = 4; i != 0; --i )
  {
    m_Size = m_connect->m_pData->m_Size;
    for ( count = 0; count < m_Size; ++count )
    {
      v4 = count;
      v5 = 0;
      if ( m_connect->m_pData->m_Size <= 0 )
      {
LABEL_6:
        id = 0;
      }
      else
      {
        while ( v4 != 0 )
        {
          ++v5;
          --v4;
          if ( v5 >= m_connect->m_pData->m_Size )
            goto LABEL_6;
        }
        id = m_connect->m_pData->m_Elements[v5].id;
      }
      if ( ((unsigned __int8 (__stdcall *)(unsigned int, CNavArea *, _DWORD))this->ShouldSearch)(
             a1: id,
             a2: area,
             a3: LODWORD(travelDistanceSoFar)) != 0
        && id != 0
        && *(_DWORD *)(id + 60) != CNavArea::m_masterMarker )
      {
        v7 = 0.0;
        *(_DWORD *)(id + 60) = CNavArea::m_masterMarker;
        *(_DWORD *)(id + 64) = 0;
        *(_DWORD *)(id + 120) = area;
        *(_DWORD *)(id + 124) = 9;
        if ( area != nullptr )
        {
          v8 = *(float *)(id + 48) - area->m_center.y;
          v9 = *(float *)(id + 44) - area->m_center.x;
          v7 = area->m_costSoFar
             + fsqrt(
                 (float)((float)(v9 * v9) + (float)(v8 * v8))
               + (float)((float)(*(float *)(id + 52) - area->m_center.z)
                       * (float)(*(float *)(id + 52) - area->m_center.z)));
        }
        *(float *)(id + 68) = v7;
        CNavArea::AddToOpenList(this: (CNavArea *)id);
      }
    }
    ++m_connect;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D3160
// Name: public: virtual bool CNonDamagingScan::operator()(class CNavArea __near *,class CNavArea __near *,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNonDamagingScan::operator()(
        CNonDamagingScan *this,
        CNavArea *area,
        CNavArea *priorArea,
        float travelDistanceSoFar)
{
  if ( travelDistanceSoFar < 2000.0
    && gpGlobals->tickcount > area->m_damagingTickCount
    && this->m_safeAreaTravelRange > travelDistanceSoFar )
  {
    this->m_safeArea = area;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102D31A0
// Name: public: virtual void EscapeFromFlamesState::OnEnter(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall EscapeFromFlamesState::OnEnter(EscapeFromFlamesState *this, CCSBot *me)
{
  float m_Value; // xmm0_4

  me->StandUp(this: me);
  me->Run(this: me);
  if ( me->m_waitTimer.m_timestamp.m_Value != -1.0 )
  {
    me->m_waitTimer.NetworkStateChanged(this: &me->m_waitTimer, a2: &me->m_waitTimer.m_timestamp);
    me->m_waitTimer.m_timestamp.m_Value = -1.0;
  }
  me->m_isStopping = false;
  me->m_pathLength = 0;
  me->m_pathLadder = nullptr;
  CCSBot::EquipKnife(this: me);
  m_Value = this->m_searchTimer.m_timestamp.m_Value;
  this->m_safeArea = nullptr;
  if ( m_Value != -1.0 )
  {
    this->m_searchTimer.NetworkStateChanged(this: &this->m_searchTimer, a2: &this->m_searchTimer.m_timestamp);
    this->m_searchTimer.m_timestamp.m_Value = -1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D3250
// Name: void SearchSurroundingAreas(class CNavArea __near *,class ISearchSurroundingAreasFunctor __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SearchSurroundingAreas(CNavArea *startArea, ISearchSurroundingAreasFunctor *func)
{
  CNavArea *v2; // esi
  CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int> > adjVector; // [esp+1Ch] [ebp-14h] BYREF

  if ( startArea != nullptr )
  {
    if ( ++CNavArea::m_masterMarker == 0 )
      CNavArea::m_masterMarker = 1;
    CNavArea::ClearSearchLists();
    CNavArea::AddToOpenList(this: startArea);
    startArea->m_totalCost = 0.0;
    startArea->m_costSoFar = 0.0;
    startArea->m_parent = nullptr;
    startArea->m_parentHow = NUM_TRAVERSE_TYPES;
    startArea->m_marker = CNavArea::m_masterMarker;
    v2 = CNavArea::m_openList;
    memset(&adjVector, 0, sizeof(adjVector));
    for ( ; CNavArea::m_openList != nullptr; v2 = CNavArea::m_openList )
    {
      CNavArea::RemoveFromOpenList(this: v2);
      v2->m_prevOpen = nullptr;
      v2->m_nextOpen = nullptr;
      if ( ((unsigned __int8 (__thiscall *)(ISearchSurroundingAreasFunctor *, CNavArea *, CNavArea *, _DWORD))func->operator())(
             a1: func,
             a2: v2,
             a3: v2->m_parent,
             a4: LODWORD(v2->m_costSoFar)) == 0 )
        break;
      ((void (__thiscall *)(ISearchSurroundingAreasFunctor *, CNavArea *, CNavArea *, _DWORD))func->IterateAdjacentAreas)(
        a1: func,
        a2: v2,
        a3: v2->m_parent,
        a4: LODWORD(v2->m_costSoFar));
    }
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&adjVector);
  }
  func->PostSearch(this: func);
}

//------------------------------------------------------------------------------
// Address: 0x102D3330
// Name: public: virtual void EscapeFromFlamesState::OnUpdate(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge EscapeFromFlamesState::OnUpdate(EscapeFromFlamesState *this@<ecx>, int a2@<edi>, CCSBot *me)
{
  IUniformRandomStream *v5; // ecx
  CNavArea *v6; // eax
  CNavArea *m_safeArea; // eax
  float duration; // [esp+Ch] [ebp-14h]
  ISearchSurroundingAreasFunctor func; // [esp+14h] [ebp-Ch] BYREF
  CNavArea *v10; // [esp+18h] [ebp-8h]
  int v11; // [esp+1Ch] [ebp-4h]
  float mea; // [esp+28h] [ebp+8h]

  if ( me->m_burnedByFlamesTimer.m_timestamp.m_Value > 0.0
    && (mea = IntervalTimer::Now(this: (CEffectsServer *)&me->m_burnedByFlamesTimer)
            - me->m_burnedByFlamesTimer.m_timestamp.m_Value) <= 1.5 )
  {
    if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_searchTimer) > this->m_searchTimer.m_timestamp.m_Value )
    {
      duration = _RandomFloat(this: v5, a2: 0.5, a3: 1.0);
      CountdownTimer::Start(this: &this->m_searchTimer, duration);
      v6 = me->GetLastKnownArea(this: me);
      if ( v6 != nullptr )
      {
        func.__vftable = (ISearchSurroundingAreasFunctor_vtbl *)&CNonDamagingScan::`vftable';
        v10 = nullptr;
        v11 = 2139095039;
        SearchSurroundingAreas(startArea: v6, &func);
        v6 = v10;
      }
      this->m_safeArea = v6;
    }
    CCSBot::UpdateLookAround(this: me, updateNow: false);
    CCSBot::EquipBestWeapon(this: me, mustEquip: false);
    CCSBot::FireWeaponAtEnemy(this: me, a2);
    if ( CCSBot::UpdatePathMovement(this: me, allowSpeedChange: true) != PROGRESSING )
    {
      m_safeArea = this->m_safeArea;
      if ( m_safeArea != nullptr )
        CCSBot::ComputePath(this: me, goal: &m_safeArea->m_center, route: FASTEST_ROUTE);
    }
  }
  else
  {
    CCSBot::Idle(this: me);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D3820
// Name: void SearchSurroundingAreas<class FollowTargetCollector>(class CNavArea __near *,class Vector const __near &,class FollowTargetCollector __near &,float,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall SearchSurroundingAreas<FollowTargetCollector>(
        const CNavLadder *a1@<ebp>,
        CNavArea *startArea,
        const Vector *startPos,
        FollowTargetCollector *func,
        float maxRange,
        char options,
        int teamID)
{
  CNavArea *v7; // edi
  float v8; // xmm0_4
  int v9; // edx
  int v10; // eax
  float v11; // esi
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  bool v15; // cc
  float v16; // esi
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float *v20; // edx
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // eax
  int id; // eax
  int v23; // esi
  float v24; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm1_4
  int v27; // esi
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  int v31; // esi
  CNavArea *v32; // ecx
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm1_4
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v36; // eax
  int v37; // esi
  CNavArea *v38; // ecx
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm1_4
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v42; // eax
  unsigned int v43; // esi
  float v44; // xmm1_4
  float v45; // xmm2_4
  float v46; // xmm1_4
  Vector v47; // [esp-60h] [ebp-7Ch] BYREF
  Vector v48; // [esp-54h] [ebp-70h] BYREF
  Vector v49; // [esp-48h] [ebp-64h] BYREF
  Vector v50; // [esp-3Ch] [ebp-58h] BYREF
  Vector v51; // [esp-30h] [ebp-4Ch] BYREF
  Vector v52; // [esp-24h] [ebp-40h] BYREF
  Vector v53; // [esp-18h] [ebp-34h] BYREF
  int v54; // [esp-8h] [ebp-24h]
  float v55; // [esp-4h] [ebp-20h]
  int v56; // [esp+0h] [ebp-1Ch]
  int count; // [esp+4h] [ebp-18h]
  int v58; // [esp+8h] [ebp-14h]
  float **m_connect; // [esp+Ch] [ebp-10h]
  const CNavLadder *ladder; // [esp+10h] [ebp-Ch]
  int it; // [esp+14h] [ebp-8h]
  int retaddr; // [esp+1Ch] [ebp+0h]

  ladder = a1;
  it = retaddr;
  if ( startArea != nullptr )
  {
    if ( ++CNavArea::m_masterMarker == 0 )
      CNavArea::m_masterMarker = 1;
    CNavArea::ClearSearchLists();
    CNavArea::AddToOpenList(this: startArea);
    startArea->m_totalCost = 0.0;
    startArea->m_costSoFar = 0.0;
    startArea->m_parent = nullptr;
    startArea->m_parentHow = NUM_TRAVERSE_TYPES;
    startArea->m_marker = CNavArea::m_masterMarker;
    v7 = CNavArea::m_openList;
    while ( CNavArea::m_openList != nullptr )
    {
      if ( v7 != nullptr )
      {
        CNavArea::RemoveFromOpenList(this: v7);
        v7->m_prevOpen = nullptr;
        v7->m_nextOpen = nullptr;
      }
      else
      {
        v7 = nullptr;
      }
      if ( (!v7->IsBlocked(this: v7, a2: teamID, a3: false) || (options & 2) != 0)
        && FollowTargetCollector::operator()(this: func, area: v7) )
      {
        v8 = maxRange;
        m_connect = (float **)v7->m_connect;
        for ( count = 4; count != 0; --count )
        {
          v54 = *(int *)*m_connect;
          v58 = 0;
          if ( v54 > 0 )
          {
            v56 = options & 4;
            do
            {
              v9 = v58;
              v10 = 0;
              if ( *(int *)*m_connect <= 0 )
              {
LABEL_17:
                v11 = 0.0;
              }
              else
              {
                while ( v9 != 0 )
                {
                  ++v10;
                  --v9;
                  if ( v10 >= *(_DWORD *)*m_connect )
                    goto LABEL_17;
                }
                v11 = (*m_connect)[2 * v10 + 1];
              }
              if ( v56 == 0
                || (v8 = maxRange,
                    CNavArea::IsConnected(this: (CNavArea *)LODWORD(v11), area: v7, dir: NUM_DIRECTIONS) != 0) )
              {
                if ( v11 != 0.0 && *(_DWORD *)(LODWORD(v11) + 60) != CNavArea::m_masterMarker )
                {
                  *(_DWORD *)(LODWORD(v11) + 60) = CNavArea::m_masterMarker;
                  *(_DWORD *)(LODWORD(v11) + 64) = 0;
                  *(_DWORD *)(LODWORD(v11) + 120) = v7;
                  *(_DWORD *)(LODWORD(v11) + 124) = 9;
                  if ( v8 <= 0.0
                    || (CNavArea::GetClosestPointOnArea(this: (CNavArea *)LODWORD(v11), pPos: startPos, close: &v53),
                        v55 = (float)((float)(v53.x - startPos->x) * (float)(v53.x - startPos->x))
                            + (float)((float)(v53.y - startPos->y) * (float)(v53.y - startPos->y)),
                        (float)((v8 = maxRange) * v8) > v55)
                    && (v12 = *(float *)(LODWORD(v11) + 44) - v7->m_center.x,
                        v13 = *(float *)(LODWORD(v11) + 48) - v7->m_center.y,
                        v14 = v7->m_costSoFar
                            + fsqrt(
                                (float)((float)(v13 * v13)
                                      + (float)((float)(*(float *)(LODWORD(v11) + 52) - v7->m_center.z)
                                              * (float)(*(float *)(LODWORD(v11) + 52) - v7->m_center.z)))
                              + (float)(v12 * v12)),
                        *(float *)(LODWORD(v11) + 68) = v14,
                        (float)(maxRange * 1.5) >= v14) )
                  {
                    CNavArea::AddToOpenList(this: (CNavArea *)LODWORD(v11));
                    v8 = maxRange;
                  }
                }
              }
              ++v58;
            }
            while ( v58 < v54 );
          }
          ++m_connect;
        }
        if ( (options & 1) != 0 )
        {
          m_connect = (float **)v7->m_incomingConnect;
          for ( count = 4; count != 0; --count )
          {
            v15 = *(_DWORD *)*m_connect <= 0;
            v58 = 0;
            if ( !v15 )
            {
              do
              {
                v16 = (*m_connect)[2 * v58 + 1];
                v54 = SLODWORD((*m_connect)[2 * v58 + 2]);
                if ( v16 != 0.0 && *(_DWORD *)(LODWORD(v16) + 60) != CNavArea::m_masterMarker )
                {
                  *(_DWORD *)(LODWORD(v16) + 60) = CNavArea::m_masterMarker;
                  *(_DWORD *)(LODWORD(v16) + 64) = 0;
                  *(_DWORD *)(LODWORD(v16) + 120) = v7;
                  *(_DWORD *)(LODWORD(v16) + 124) = 9;
                  if ( v8 <= 0.0
                    || (CNavArea::GetClosestPointOnArea(this: (CNavArea *)LODWORD(v16), pPos: startPos, close: &v52),
                        (float)((v8 = maxRange) * v8) > (float)((float)((float)(v52.y - startPos->y)
                                                                      * (float)(v52.y - startPos->y))
                                                              + (float)((float)(v52.x - startPos->x)
                                                                      * (float)(v52.x - startPos->x))))
                    && (v17 = *(float *)(LODWORD(v16) + 44) - v7->m_center.x,
                        v18 = *(float *)(LODWORD(v16) + 48) - v7->m_center.y,
                        v19 = v7->m_costSoFar
                            + fsqrt(
                                (float)((float)(v18 * v18) + (float)(v17 * v17))
                              + (float)((float)(*(float *)(LODWORD(v16) + 52) - v7->m_center.z)
                                      * (float)(*(float *)(LODWORD(v16) + 52) - v7->m_center.z))),
                        *(float *)(LODWORD(v16) + 68) = v19,
                        (float)(maxRange * 1.5) >= v19) )
                  {
                    CNavArea::AddToOpenList(this: (CNavArea *)LODWORD(v16));
                    v8 = maxRange;
                  }
                }
                v20 = *m_connect;
                ++v58;
              }
              while ( v58 < *(_DWORD *)v20 );
            }
            ++m_connect;
          }
        }
        if ( v7 != (CNavArea *)-104 )
        {
          m_pData = v7->m_ladder[0].m_pData;
          v15 = m_pData->m_Size <= 0;
          v58 = 0;
          if ( !v15 )
          {
            do
            {
              id = m_pData->m_Elements[v58].id;
              v23 = *(_DWORD *)(id + 32);
              count = id;
              if ( v23 != 0 && *(_DWORD *)(v23 + 60) != CNavArea::m_masterMarker )
              {
                *(_DWORD *)(v23 + 60) = CNavArea::m_masterMarker;
                *(_DWORD *)(v23 + 64) = 0;
                *(_DWORD *)(v23 + 120) = v7;
                *(_DWORD *)(v23 + 124) = 9;
                if ( v8 <= 0.0
                  || (CNavArea::GetClosestPointOnArea(this: (CNavArea *)v23, pPos: startPos, close: &v51),
                      *(float *)&v54 = (float)((float)(v51.x - startPos->x) * (float)(v51.x - startPos->x))
                                     + (float)((float)(v51.y - startPos->y) * (float)(v51.y - startPos->y)),
                      (float)((v8 = maxRange) * v8) > *(float *)&v54)
                  && (v24 = *(float *)(v23 + 48) - v7->m_center.y,
                      v25 = *(float *)(v23 + 44) - v7->m_center.x,
                      v26 = v7->m_costSoFar
                          + fsqrt(
                              (float)((float)(v25 * v25) + (float)(v24 * v24))
                            + (float)((float)(*(float *)(v23 + 52) - v7->m_center.z)
                                    * (float)(*(float *)(v23 + 52) - v7->m_center.z))),
                      *(float *)(v23 + 68) = v26,
                      (float)(maxRange * 1.5) >= v26) )
                {
                  CNavArea::AddToOpenList(this: (CNavArea *)v23);
                  v8 = maxRange;
                }
              }
              v27 = *(_DWORD *)(count + 36);
              if ( v27 != 0 && *(_DWORD *)(v27 + 60) != CNavArea::m_masterMarker )
              {
                *(_DWORD *)(v27 + 60) = CNavArea::m_masterMarker;
                *(_DWORD *)(v27 + 64) = 0;
                *(_DWORD *)(v27 + 120) = v7;
                *(_DWORD *)(v27 + 124) = 9;
                if ( v8 <= 0.0
                  || (CNavArea::GetClosestPointOnArea(this: (CNavArea *)v27, pPos: startPos, close: &v50),
                      (float)((v8 = maxRange) * v8) > (float)((float)((float)(v50.y - startPos->y)
                                                                    * (float)(v50.y - startPos->y))
                                                            + (float)((float)(v50.x - startPos->x)
                                                                    * (float)(v50.x - startPos->x))))
                  && (v28 = *(float *)(v27 + 44) - v7->m_center.x,
                      v29 = *(float *)(v27 + 48) - v7->m_center.y,
                      v30 = v7->m_costSoFar
                          + fsqrt(
                              (float)((float)(v29 * v29)
                                    + (float)((float)(*(float *)(v27 + 52) - v7->m_center.z)
                                            * (float)(*(float *)(v27 + 52) - v7->m_center.z)))
                            + (float)(v28 * v28)),
                      *(float *)(v27 + 68) = v30,
                      (float)(maxRange * 1.5) >= v30) )
                {
                  CNavArea::AddToOpenList(this: (CNavArea *)v27);
                  v8 = maxRange;
                }
              }
              v31 = *(_DWORD *)(count + 40);
              if ( v31 != 0 && *(_DWORD *)(v31 + 60) != CNavArea::m_masterMarker )
              {
                *(_DWORD *)(v31 + 60) = CNavArea::m_masterMarker;
                *(_DWORD *)(v31 + 64) = 0;
                *(_DWORD *)(v31 + 120) = v7;
                *(_DWORD *)(v31 + 124) = 9;
                v32 = (CNavArea *)v31;
                if ( v8 > 0.0 )
                {
                  CNavArea::GetClosestPointOnArea(this: (CNavArea *)v31, pPos: startPos, close: &v49);
                  v8 = maxRange;
                  if ( (float)(v8 * v8) <= (float)((float)((float)(v49.y - startPos->y) * (float)(v49.y - startPos->y))
                                                 + (float)((float)(v49.x - startPos->x) * (float)(v49.x - startPos->x))) )
                    goto LABEL_60;
                  v33 = *(float *)(v31 + 44) - v7->m_center.x;
                  v34 = *(float *)(v31 + 48) - v7->m_center.y;
                  v35 = v7->m_costSoFar
                      + fsqrt(
                          (float)((float)(v34 * v34)
                                + (float)((float)(*(float *)(v31 + 52) - v7->m_center.z)
                                        * (float)(*(float *)(v31 + 52) - v7->m_center.z)))
                        + (float)(v33 * v33));
                  *(float *)(v31 + 68) = v35;
                  if ( (float)(maxRange * 1.5) < v35 )
                    goto LABEL_60;
                  v32 = (CNavArea *)v31;
                }
                CNavArea::AddToOpenList(this: v32);
                v8 = maxRange;
              }
LABEL_60:
              m_pData = v7->m_ladder[0].m_pData;
              ++v58;
            }
            while ( v58 < m_pData->m_Size );
          }
        }
        if ( v7 != (CNavArea *)-108 )
        {
          v36 = v7->m_ladder[1].m_pData;
          v15 = v36->m_Size <= 0;
          v58 = 0;
          if ( !v15 )
          {
            do
            {
              v37 = *(_DWORD *)(v36->m_Elements[v58].id + 48);
              if ( v37 != 0 && *(_DWORD *)(v37 + 60) != CNavArea::m_masterMarker )
              {
                *(_DWORD *)(v37 + 60) = CNavArea::m_masterMarker;
                *(_DWORD *)(v37 + 64) = 0;
                *(_DWORD *)(v37 + 120) = v7;
                *(_DWORD *)(v37 + 124) = 9;
                v38 = (CNavArea *)v37;
                if ( v8 > 0.0 )
                {
                  CNavArea::GetClosestPointOnArea(this: (CNavArea *)v37, pPos: startPos, close: &v48);
                  v8 = maxRange;
                  if ( (float)(v8 * v8) <= (float)((float)((float)(v48.y - startPos->y) * (float)(v48.y - startPos->y))
                                                 + (float)((float)(v48.x - startPos->x) * (float)(v48.x - startPos->x))) )
                    goto LABEL_70;
                  v39 = *(float *)(v37 + 44) - v7->m_center.x;
                  v40 = *(float *)(v37 + 48) - v7->m_center.y;
                  v41 = v7->m_costSoFar
                      + fsqrt(
                          (float)((float)(v40 * v40)
                                + (float)((float)(*(float *)(v37 + 52) - v7->m_center.z)
                                        * (float)(*(float *)(v37 + 52) - v7->m_center.z)))
                        + (float)(v39 * v39));
                  *(float *)(v37 + 68) = v41;
                  if ( (float)(maxRange * 1.5) < v41 )
                    goto LABEL_70;
                  v38 = (CNavArea *)v37;
                }
                CNavArea::AddToOpenList(this: v38);
                v8 = maxRange;
              }
LABEL_70:
              v36 = v7->m_ladder[1].m_pData;
              ++v58;
            }
            while ( v58 < v36->m_Size );
          }
        }
        if ( (options & 8) == 0 )
        {
          v42 = v7->m_elevatorAreas.m_pData;
          v15 = v42->m_Size <= 0;
          v58 = 0;
          if ( !v15 )
          {
            do
            {
              v43 = v42->m_Elements[v58].id;
              if ( v43 != 0 && *(_DWORD *)(v43 + 60) != CNavArea::m_masterMarker )
              {
                *(_DWORD *)(v43 + 60) = CNavArea::m_masterMarker;
                *(_DWORD *)(v43 + 64) = 0;
                *(_DWORD *)(v43 + 120) = v7;
                *(_DWORD *)(v43 + 124) = 9;
                if ( v8 <= 0.0
                  || (CNavArea::GetClosestPointOnArea(this: (CNavArea *)v43, pPos: startPos, close: &v47),
                      (float)((v8 = maxRange) * v8) > (float)((float)((float)(v47.y - startPos->y)
                                                                    * (float)(v47.y - startPos->y))
                                                            + (float)((float)(v47.x - startPos->x)
                                                                    * (float)(v47.x - startPos->x))))
                  && (v44 = *(float *)(v43 + 44) - v7->m_center.x,
                      v45 = *(float *)(v43 + 48) - v7->m_center.y,
                      v46 = v7->m_costSoFar
                          + fsqrt(
                              (float)((float)(v45 * v45)
                                    + (float)((float)(*(float *)(v43 + 52) - v7->m_center.z)
                                            * (float)(*(float *)(v43 + 52) - v7->m_center.z)))
                            + (float)(v44 * v44)),
                      *(float *)(v43 + 68) = v46,
                      (float)(maxRange * 1.5) >= v46) )
                {
                  CNavArea::AddToOpenList(this: (CNavArea *)v43);
                  v8 = maxRange;
                }
              }
              v42 = v7->m_elevatorAreas.m_pData;
              ++v58;
            }
            while ( v58 < v42->m_Size );
          }
        }
      }
      v7 = CNavArea::m_openList;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10301320
// Name: void SearchSurroundingAreas<class PlaceFloodFillFunctor>(class CNavArea __near *,class Vector const __near &,class PlaceFloodFillFunctor __near &,float,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall SearchSurroundingAreas<PlaceFloodFillFunctor>(
        const CNavLadder *a1@<ebp>,
        CNavArea *startArea,
        const Vector *startPos,
        PlaceFloodFillFunctor *func,
        float maxRange,
        char options,
        int teamID)
{
  CNavArea *v7; // edi
  float v8; // xmm0_4
  int v9; // edx
  int v10; // eax
  float v11; // esi
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  bool v15; // cc
  float v16; // esi
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float *v20; // edx
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // eax
  int id; // eax
  int v23; // esi
  float v24; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm1_4
  int v27; // esi
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  int v31; // esi
  CNavArea *v32; // ecx
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm1_4
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v36; // eax
  int v37; // esi
  CNavArea *v38; // ecx
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm1_4
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v42; // eax
  unsigned int v43; // esi
  float v44; // xmm1_4
  float v45; // xmm2_4
  float v46; // xmm1_4
  Vector v47; // [esp-60h] [ebp-7Ch] BYREF
  Vector v48; // [esp-54h] [ebp-70h] BYREF
  Vector v49; // [esp-48h] [ebp-64h] BYREF
  Vector v50; // [esp-3Ch] [ebp-58h] BYREF
  Vector v51; // [esp-30h] [ebp-4Ch] BYREF
  Vector v52; // [esp-24h] [ebp-40h] BYREF
  Vector v53; // [esp-18h] [ebp-34h] BYREF
  int v54; // [esp-8h] [ebp-24h]
  float v55; // [esp-4h] [ebp-20h]
  int v56; // [esp+0h] [ebp-1Ch]
  int count; // [esp+4h] [ebp-18h]
  int v58; // [esp+8h] [ebp-14h]
  float **m_connect; // [esp+Ch] [ebp-10h]
  const CNavLadder *ladder; // [esp+10h] [ebp-Ch]
  int it; // [esp+14h] [ebp-8h]
  int retaddr; // [esp+1Ch] [ebp+0h]

  ladder = a1;
  it = retaddr;
  if ( startArea != nullptr )
  {
    if ( ++CNavArea::m_masterMarker == 0 )
      CNavArea::m_masterMarker = 1;
    CNavArea::ClearSearchLists();
    CNavArea::AddToOpenList(this: startArea);
    startArea->m_totalCost = 0.0;
    startArea->m_costSoFar = 0.0;
    startArea->m_parent = nullptr;
    startArea->m_parentHow = NUM_TRAVERSE_TYPES;
    startArea->m_marker = CNavArea::m_masterMarker;
    v7 = CNavArea::m_openList;
    while ( CNavArea::m_openList != nullptr )
    {
      if ( v7 != nullptr )
      {
        CNavArea::RemoveFromOpenList(this: v7);
        v7->m_prevOpen = nullptr;
        v7->m_nextOpen = nullptr;
      }
      else
      {
        v7 = nullptr;
      }
      if ( (!v7->IsBlocked(this: v7, a2: teamID, a3: false) || (options & 2) != 0)
        && v7->m_place == func->m_initialPlace )
      {
        v8 = maxRange;
        v7->m_place = TheNavMesh->m_navPlace;
        m_connect = (float **)v7->m_connect;
        for ( count = 4; count != 0; --count )
        {
          v54 = *(int *)*m_connect;
          v58 = 0;
          if ( v54 > 0 )
          {
            v56 = options & 4;
            do
            {
              v9 = v58;
              v10 = 0;
              if ( *(int *)*m_connect <= 0 )
              {
LABEL_17:
                v11 = 0.0;
              }
              else
              {
                while ( v9 != 0 )
                {
                  ++v10;
                  --v9;
                  if ( v10 >= *(_DWORD *)*m_connect )
                    goto LABEL_17;
                }
                v11 = (*m_connect)[2 * v10 + 1];
              }
              if ( v56 == 0
                || (v8 = maxRange,
                    CNavArea::IsConnected(this: (CNavArea *)LODWORD(v11), area: v7, dir: NUM_DIRECTIONS) != 0) )
              {
                if ( v11 != 0.0 && *(_DWORD *)(LODWORD(v11) + 60) != CNavArea::m_masterMarker )
                {
                  *(_DWORD *)(LODWORD(v11) + 60) = CNavArea::m_masterMarker;
                  *(_DWORD *)(LODWORD(v11) + 64) = 0;
                  *(_DWORD *)(LODWORD(v11) + 120) = v7;
                  *(_DWORD *)(LODWORD(v11) + 124) = 9;
                  if ( v8 <= 0.0
                    || (CNavArea::GetClosestPointOnArea(this: (CNavArea *)LODWORD(v11), pPos: startPos, close: &v53),
                        v55 = (float)((float)(v53.x - startPos->x) * (float)(v53.x - startPos->x))
                            + (float)((float)(v53.y - startPos->y) * (float)(v53.y - startPos->y)),
                        (float)((v8 = maxRange) * v8) > v55)
                    && (v12 = *(float *)(LODWORD(v11) + 44) - v7->m_center.x,
                        v13 = *(float *)(LODWORD(v11) + 48) - v7->m_center.y,
                        v14 = v7->m_costSoFar
                            + fsqrt(
                                (float)((float)(v13 * v13)
                                      + (float)((float)(*(float *)(LODWORD(v11) + 52) - v7->m_center.z)
                                              * (float)(*(float *)(LODWORD(v11) + 52) - v7->m_center.z)))
                              + (float)(v12 * v12)),
                        *(float *)(LODWORD(v11) + 68) = v14,
                        (float)(maxRange * 1.5) >= v14) )
                  {
                    CNavArea::AddToOpenList(this: (CNavArea *)LODWORD(v11));
                    v8 = maxRange;
                  }
                }
              }
              ++v58;
            }
            while ( v58 < v54 );
          }
          ++m_connect;
        }
        if ( (options & 1) != 0 )
        {
          m_connect = (float **)v7->m_incomingConnect;
          for ( count = 4; count != 0; --count )
          {
            v15 = *(_DWORD *)*m_connect <= 0;
            v58 = 0;
            if ( !v15 )
            {
              do
              {
                v16 = (*m_connect)[2 * v58 + 1];
                v54 = SLODWORD((*m_connect)[2 * v58 + 2]);
                if ( v16 != 0.0 && *(_DWORD *)(LODWORD(v16) + 60) != CNavArea::m_masterMarker )
                {
                  *(_DWORD *)(LODWORD(v16) + 60) = CNavArea::m_masterMarker;
                  *(_DWORD *)(LODWORD(v16) + 64) = 0;
                  *(_DWORD *)(LODWORD(v16) + 120) = v7;
                  *(_DWORD *)(LODWORD(v16) + 124) = 9;
                  if ( v8 <= 0.0
                    || (CNavArea::GetClosestPointOnArea(this: (CNavArea *)LODWORD(v16), pPos: startPos, close: &v52),
                        (float)((v8 = maxRange) * v8) > (float)((float)((float)(v52.y - startPos->y)
                                                                      * (float)(v52.y - startPos->y))
                                                              + (float)((float)(v52.x - startPos->x)
                                                                      * (float)(v52.x - startPos->x))))
                    && (v17 = *(float *)(LODWORD(v16) + 44) - v7->m_center.x,
                        v18 = *(float *)(LODWORD(v16) + 48) - v7->m_center.y,
                        v19 = v7->m_costSoFar
                            + fsqrt(
                                (float)((float)(v18 * v18) + (float)(v17 * v17))
                              + (float)((float)(*(float *)(LODWORD(v16) + 52) - v7->m_center.z)
                                      * (float)(*(float *)(LODWORD(v16) + 52) - v7->m_center.z))),
                        *(float *)(LODWORD(v16) + 68) = v19,
                        (float)(maxRange * 1.5) >= v19) )
                  {
                    CNavArea::AddToOpenList(this: (CNavArea *)LODWORD(v16));
                    v8 = maxRange;
                  }
                }
                v20 = *m_connect;
                ++v58;
              }
              while ( v58 < *(_DWORD *)v20 );
            }
            ++m_connect;
          }
        }
        if ( v7 != (CNavArea *)-104 )
        {
          m_pData = v7->m_ladder[0].m_pData;
          v15 = m_pData->m_Size <= 0;
          v58 = 0;
          if ( !v15 )
          {
            do
            {
              id = m_pData->m_Elements[v58].id;
              v23 = *(_DWORD *)(id + 32);
              count = id;
              if ( v23 != 0 && *(_DWORD *)(v23 + 60) != CNavArea::m_masterMarker )
              {
                *(_DWORD *)(v23 + 60) = CNavArea::m_masterMarker;
                *(_DWORD *)(v23 + 64) = 0;
                *(_DWORD *)(v23 + 120) = v7;
                *(_DWORD *)(v23 + 124) = 9;
                if ( v8 <= 0.0
                  || (CNavArea::GetClosestPointOnArea(this: (CNavArea *)v23, pPos: startPos, close: &v51),
                      *(float *)&v54 = (float)((float)(v51.x - startPos->x) * (float)(v51.x - startPos->x))
                                     + (float)((float)(v51.y - startPos->y) * (float)(v51.y - startPos->y)),
                      (float)((v8 = maxRange) * v8) > *(float *)&v54)
                  && (v24 = *(float *)(v23 + 48) - v7->m_center.y,
                      v25 = *(float *)(v23 + 44) - v7->m_center.x,
                      v26 = v7->m_costSoFar
                          + fsqrt(
                              (float)((float)(v25 * v25) + (float)(v24 * v24))
                            + (float)((float)(*(float *)(v23 + 52) - v7->m_center.z)
                                    * (float)(*(float *)(v23 + 52) - v7->m_center.z))),
                      *(float *)(v23 + 68) = v26,
                      (float)(maxRange * 1.5) >= v26) )
                {
                  CNavArea::AddToOpenList(this: (CNavArea *)v23);
                  v8 = maxRange;
                }
              }
              v27 = *(_DWORD *)(count + 36);
              if ( v27 != 0 && *(_DWORD *)(v27 + 60) != CNavArea::m_masterMarker )
              {
                *(_DWORD *)(v27 + 60) = CNavArea::m_masterMarker;
                *(_DWORD *)(v27 + 64) = 0;
                *(_DWORD *)(v27 + 120) = v7;
                *(_DWORD *)(v27 + 124) = 9;
                if ( v8 <= 0.0
                  || (CNavArea::GetClosestPointOnArea(this: (CNavArea *)v27, pPos: startPos, close: &v50),
                      (float)((v8 = maxRange) * v8) > (float)((float)((float)(v50.y - startPos->y)
                                                                    * (float)(v50.y - startPos->y))
                                                            + (float)((float)(v50.x - startPos->x)
                                                                    * (float)(v50.x - startPos->x))))
                  && (v28 = *(float *)(v27 + 44) - v7->m_center.x,
                      v29 = *(float *)(v27 + 48) - v7->m_center.y,
                      v30 = v7->m_costSoFar
                          + fsqrt(
                              (float)((float)(v29 * v29)
                                    + (float)((float)(*(float *)(v27 + 52) - v7->m_center.z)
                                            * (float)(*(float *)(v27 + 52) - v7->m_center.z)))
                            + (float)(v28 * v28)),
                      *(float *)(v27 + 68) = v30,
                      (float)(maxRange * 1.5) >= v30) )
                {
                  CNavArea::AddToOpenList(this: (CNavArea *)v27);
                  v8 = maxRange;
                }
              }
              v31 = *(_DWORD *)(count + 40);
              if ( v31 != 0 && *(_DWORD *)(v31 + 60) != CNavArea::m_masterMarker )
              {
                *(_DWORD *)(v31 + 60) = CNavArea::m_masterMarker;
                *(_DWORD *)(v31 + 64) = 0;
                *(_DWORD *)(v31 + 120) = v7;
                *(_DWORD *)(v31 + 124) = 9;
                v32 = (CNavArea *)v31;
                if ( v8 > 0.0 )
                {
                  CNavArea::GetClosestPointOnArea(this: (CNavArea *)v31, pPos: startPos, close: &v49);
                  v8 = maxRange;
                  if ( (float)(v8 * v8) <= (float)((float)((float)(v49.y - startPos->y) * (float)(v49.y - startPos->y))
                                                 + (float)((float)(v49.x - startPos->x) * (float)(v49.x - startPos->x))) )
                    goto LABEL_60;
                  v33 = *(float *)(v31 + 44) - v7->m_center.x;
                  v34 = *(float *)(v31 + 48) - v7->m_center.y;
                  v35 = v7->m_costSoFar
                      + fsqrt(
                          (float)((float)(v34 * v34)
                                + (float)((float)(*(float *)(v31 + 52) - v7->m_center.z)
                                        * (float)(*(float *)(v31 + 52) - v7->m_center.z)))
                        + (float)(v33 * v33));
                  *(float *)(v31 + 68) = v35;
                  if ( (float)(maxRange * 1.5) < v35 )
                    goto LABEL_60;
                  v32 = (CNavArea *)v31;
                }
                CNavArea::AddToOpenList(this: v32);
                v8 = maxRange;
              }
LABEL_60:
              m_pData = v7->m_ladder[0].m_pData;
              ++v58;
            }
            while ( v58 < m_pData->m_Size );
          }
        }
        if ( v7 != (CNavArea *)-108 )
        {
          v36 = v7->m_ladder[1].m_pData;
          v15 = v36->m_Size <= 0;
          v58 = 0;
          if ( !v15 )
          {
            do
            {
              v37 = *(_DWORD *)(v36->m_Elements[v58].id + 48);
              if ( v37 != 0 && *(_DWORD *)(v37 + 60) != CNavArea::m_masterMarker )
              {
                *(_DWORD *)(v37 + 60) = CNavArea::m_masterMarker;
                *(_DWORD *)(v37 + 64) = 0;
                *(_DWORD *)(v37 + 120) = v7;
                *(_DWORD *)(v37 + 124) = 9;
                v38 = (CNavArea *)v37;
                if ( v8 > 0.0 )
                {
                  CNavArea::GetClosestPointOnArea(this: (CNavArea *)v37, pPos: startPos, close: &v48);
                  v8 = maxRange;
                  if ( (float)(v8 * v8) <= (float)((float)((float)(v48.y - startPos->y) * (float)(v48.y - startPos->y))
                                                 + (float)((float)(v48.x - startPos->x) * (float)(v48.x - startPos->x))) )
                    goto LABEL_70;
                  v39 = *(float *)(v37 + 44) - v7->m_center.x;
                  v40 = *(float *)(v37 + 48) - v7->m_center.y;
                  v41 = v7->m_costSoFar
                      + fsqrt(
                          (float)((float)(v40 * v40)
                                + (float)((float)(*(float *)(v37 + 52) - v7->m_center.z)
                                        * (float)(*(float *)(v37 + 52) - v7->m_center.z)))
                        + (float)(v39 * v39));
                  *(float *)(v37 + 68) = v41;
                  if ( (float)(maxRange * 1.5) < v41 )
                    goto LABEL_70;
                  v38 = (CNavArea *)v37;
                }
                CNavArea::AddToOpenList(this: v38);
                v8 = maxRange;
              }
LABEL_70:
              v36 = v7->m_ladder[1].m_pData;
              ++v58;
            }
            while ( v58 < v36->m_Size );
          }
        }
        if ( (options & 8) == 0 )
        {
          v42 = v7->m_elevatorAreas.m_pData;
          v15 = v42->m_Size <= 0;
          v58 = 0;
          if ( !v15 )
          {
            do
            {
              v43 = v42->m_Elements[v58].id;
              if ( v43 != 0 && *(_DWORD *)(v43 + 60) != CNavArea::m_masterMarker )
              {
                *(_DWORD *)(v43 + 60) = CNavArea::m_masterMarker;
                *(_DWORD *)(v43 + 64) = 0;
                *(_DWORD *)(v43 + 120) = v7;
                *(_DWORD *)(v43 + 124) = 9;
                if ( v8 <= 0.0
                  || (CNavArea::GetClosestPointOnArea(this: (CNavArea *)v43, pPos: startPos, close: &v47),
                      (float)((v8 = maxRange) * v8) > (float)((float)((float)(v47.y - startPos->y)
                                                                    * (float)(v47.y - startPos->y))
                                                            + (float)((float)(v47.x - startPos->x)
                                                                    * (float)(v47.x - startPos->x))))
                  && (v44 = *(float *)(v43 + 44) - v7->m_center.x,
                      v45 = *(float *)(v43 + 48) - v7->m_center.y,
                      v46 = v7->m_costSoFar
                          + fsqrt(
                              (float)((float)(v45 * v45)
                                    + (float)((float)(*(float *)(v43 + 52) - v7->m_center.z)
                                            * (float)(*(float *)(v43 + 52) - v7->m_center.z)))
                            + (float)(v44 * v44)),
                      *(float *)(v43 + 68) = v46,
                      (float)(maxRange * 1.5) >= v46) )
                {
                  CNavArea::AddToOpenList(this: (CNavArea *)v43);
                  v8 = maxRange;
                }
              }
              v42 = v7->m_elevatorAreas.m_pData;
              ++v58;
            }
            while ( v58 < v42->m_Size );
          }
        }
      }
      v7 = CNavArea::m_openList;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10304420
// Name: void SearchSurroundingAreas<class DrawSelectedSet>(class CNavArea __near *,class Vector const __near &,class DrawSelectedSet __near &,float,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall SearchSurroundingAreas<DrawSelectedSet>(
        const CNavLadder *a1@<ebp>,
        CNavArea *startArea,
        const Vector *startPos,
        DrawSelectedSet *func,
        float maxRange,
        char options,
        int teamID)
{
  CNavArea *v7; // edi
  float v8; // xmm0_4
  int v9; // edx
  int v10; // eax
  float v11; // esi
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  bool v15; // cc
  float v16; // esi
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float *v20; // edx
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // eax
  int id; // eax
  int v23; // esi
  float v24; // xmm2_4
  float v25; // xmm1_4
  float v26; // xmm1_4
  int v27; // esi
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm1_4
  int v31; // esi
  CNavArea *v32; // ecx
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm1_4
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v36; // eax
  int v37; // esi
  CNavArea *v38; // ecx
  float v39; // xmm1_4
  float v40; // xmm2_4
  float v41; // xmm1_4
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v42; // eax
  unsigned int v43; // esi
  float v44; // xmm1_4
  float v45; // xmm2_4
  float v46; // xmm1_4
  Vector v47; // [esp-60h] [ebp-7Ch] BYREF
  Vector v48; // [esp-54h] [ebp-70h] BYREF
  Vector v49; // [esp-48h] [ebp-64h] BYREF
  Vector v50; // [esp-3Ch] [ebp-58h] BYREF
  Vector v51; // [esp-30h] [ebp-4Ch] BYREF
  Vector v52; // [esp-24h] [ebp-40h] BYREF
  Vector v53; // [esp-18h] [ebp-34h] BYREF
  int v54; // [esp-8h] [ebp-24h]
  float v55; // [esp-4h] [ebp-20h]
  int v56; // [esp+0h] [ebp-1Ch]
  int count; // [esp+4h] [ebp-18h]
  int v58; // [esp+8h] [ebp-14h]
  float **m_connect; // [esp+Ch] [ebp-10h]
  const CNavLadder *ladder; // [esp+10h] [ebp-Ch]
  int it; // [esp+14h] [ebp-8h]
  int retaddr; // [esp+1Ch] [ebp+0h]

  ladder = a1;
  it = retaddr;
  if ( startArea != nullptr )
  {
    if ( ++CNavArea::m_masterMarker == 0 )
      CNavArea::m_masterMarker = 1;
    CNavArea::ClearSearchLists();
    CNavArea::AddToOpenList(this: startArea);
    startArea->m_totalCost = 0.0;
    startArea->m_costSoFar = 0.0;
    startArea->m_parent = nullptr;
    startArea->m_parentHow = NUM_TRAVERSE_TYPES;
    startArea->m_marker = CNavArea::m_masterMarker;
    v7 = CNavArea::m_openList;
    while ( CNavArea::m_openList != nullptr )
    {
      if ( v7 != nullptr )
      {
        CNavArea::RemoveFromOpenList(this: v7);
        v7->m_prevOpen = nullptr;
        v7->m_nextOpen = nullptr;
      }
      else
      {
        v7 = nullptr;
      }
      if ( (!v7->IsBlocked(this: v7, a2: teamID, a3: false) || (options & 2) != 0)
        && DrawSelectedSet::operator()(this: func, area: v7) )
      {
        v8 = maxRange;
        m_connect = (float **)v7->m_connect;
        for ( count = 4; count != 0; --count )
        {
          v54 = *(int *)*m_connect;
          v58 = 0;
          if ( v54 > 0 )
          {
            v56 = options & 4;
            do
            {
              v9 = v58;
              v10 = 0;
              if ( *(int *)*m_connect <= 0 )
              {
LABEL_17:
                v11 = 0.0;
              }
              else
              {
                while ( v9 != 0 )
                {
                  ++v10;
                  --v9;
                  if ( v10 >= *(_DWORD *)*m_connect )
                    goto LABEL_17;
                }
                v11 = (*m_connect)[2 * v10 + 1];
              }
              if ( v56 == 0
                || (v8 = maxRange,
                    CNavArea::IsConnected(this: (CNavArea *)LODWORD(v11), area: v7, dir: NUM_DIRECTIONS) != 0) )
              {
                if ( v11 != 0.0 && *(_DWORD *)(LODWORD(v11) + 60) != CNavArea::m_masterMarker )
                {
                  *(_DWORD *)(LODWORD(v11) + 60) = CNavArea::m_masterMarker;
                  *(_DWORD *)(LODWORD(v11) + 64) = 0;
                  *(_DWORD *)(LODWORD(v11) + 120) = v7;
                  *(_DWORD *)(LODWORD(v11) + 124) = 9;
                  if ( v8 <= 0.0
                    || (CNavArea::GetClosestPointOnArea(this: (CNavArea *)LODWORD(v11), pPos: startPos, close: &v53),
                        v55 = (float)((float)(v53.x - startPos->x) * (float)(v53.x - startPos->x))
                            + (float)((float)(v53.y - startPos->y) * (float)(v53.y - startPos->y)),
                        (float)((v8 = maxRange) * v8) > v55)
                    && (v12 = *(float *)(LODWORD(v11) + 44) - v7->m_center.x,
                        v13 = *(float *)(LODWORD(v11) + 48) - v7->m_center.y,
                        v14 = v7->m_costSoFar
                            + fsqrt(
                                (float)((float)(v13 * v13)
                                      + (float)((float)(*(float *)(LODWORD(v11) + 52) - v7->m_center.z)
                                              * (float)(*(float *)(LODWORD(v11) + 52) - v7->m_center.z)))
                              + (float)(v12 * v12)),
                        *(float *)(LODWORD(v11) + 68) = v14,
                        (float)(maxRange * 1.5) >= v14) )
                  {
                    CNavArea::AddToOpenList(this: (CNavArea *)LODWORD(v11));
                    v8 = maxRange;
                  }
                }
              }
              ++v58;
            }
            while ( v58 < v54 );
          }
          ++m_connect;
        }
        if ( (options & 1) != 0 )
        {
          m_connect = (float **)v7->m_incomingConnect;
          for ( count = 4; count != 0; --count )
          {
            v15 = *(_DWORD *)*m_connect <= 0;
            v58 = 0;
            if ( !v15 )
            {
              do
              {
                v16 = (*m_connect)[2 * v58 + 1];
                v54 = SLODWORD((*m_connect)[2 * v58 + 2]);
                if ( v16 != 0.0 && *(_DWORD *)(LODWORD(v16) + 60) != CNavArea::m_masterMarker )
                {
                  *(_DWORD *)(LODWORD(v16) + 60) = CNavArea::m_masterMarker;
                  *(_DWORD *)(LODWORD(v16) + 64) = 0;
                  *(_DWORD *)(LODWORD(v16) + 120) = v7;
                  *(_DWORD *)(LODWORD(v16) + 124) = 9;
                  if ( v8 <= 0.0
                    || (CNavArea::GetClosestPointOnArea(this: (CNavArea *)LODWORD(v16), pPos: startPos, close: &v52),
                        (float)((v8 = maxRange) * v8) > (float)((float)((float)(v52.y - startPos->y)
                                                                      * (float)(v52.y - startPos->y))
                                                              + (float)((float)(v52.x - startPos->x)
                                                                      * (float)(v52.x - startPos->x))))
                    && (v17 = *(float *)(LODWORD(v16) + 44) - v7->m_center.x,
                        v18 = *(float *)(LODWORD(v16) + 48) - v7->m_center.y,
                        v19 = v7->m_costSoFar
                            + fsqrt(
                                (float)((float)(v18 * v18) + (float)(v17 * v17))
                              + (float)((float)(*(float *)(LODWORD(v16) + 52) - v7->m_center.z)
                                      * (float)(*(float *)(LODWORD(v16) + 52) - v7->m_center.z))),
                        *(float *)(LODWORD(v16) + 68) = v19,
                        (float)(maxRange * 1.5) >= v19) )
                  {
                    CNavArea::AddToOpenList(this: (CNavArea *)LODWORD(v16));
                    v8 = maxRange;
                  }
                }
                v20 = *m_connect;
                ++v58;
              }
              while ( v58 < *(_DWORD *)v20 );
            }
            ++m_connect;
          }
        }
        if ( v7 != (CNavArea *)-104 )
        {
          m_pData = v7->m_ladder[0].m_pData;
          v15 = m_pData->m_Size <= 0;
          v58 = 0;
          if ( !v15 )
          {
            do
            {
              id = m_pData->m_Elements[v58].id;
              v23 = *(_DWORD *)(id + 32);
              count = id;
              if ( v23 != 0 && *(_DWORD *)(v23 + 60) != CNavArea::m_masterMarker )
              {
                *(_DWORD *)(v23 + 60) = CNavArea::m_masterMarker;
                *(_DWORD *)(v23 + 64) = 0;
                *(_DWORD *)(v23 + 120) = v7;
                *(_DWORD *)(v23 + 124) = 9;
                if ( v8 <= 0.0
                  || (CNavArea::GetClosestPointOnArea(this: (CNavArea *)v23, pPos: startPos, close: &v51),
                      *(float *)&v54 = (float)((float)(v51.x - startPos->x) * (float)(v51.x - startPos->x))
                                     + (float)((float)(v51.y - startPos->y) * (float)(v51.y - startPos->y)),
                      (float)((v8 = maxRange) * v8) > *(float *)&v54)
                  && (v24 = *(float *)(v23 + 48) - v7->m_center.y,
                      v25 = *(float *)(v23 + 44) - v7->m_center.x,
                      v26 = v7->m_costSoFar
                          + fsqrt(
                              (float)((float)(v25 * v25) + (float)(v24 * v24))
                            + (float)((float)(*(float *)(v23 + 52) - v7->m_center.z)
                                    * (float)(*(float *)(v23 + 52) - v7->m_center.z))),
                      *(float *)(v23 + 68) = v26,
                      (float)(maxRange * 1.5) >= v26) )
                {
                  CNavArea::AddToOpenList(this: (CNavArea *)v23);
                  v8 = maxRange;
                }
              }
              v27 = *(_DWORD *)(count + 36);
              if ( v27 != 0 && *(_DWORD *)(v27 + 60) != CNavArea::m_masterMarker )
              {
                *(_DWORD *)(v27 + 60) = CNavArea::m_masterMarker;
                *(_DWORD *)(v27 + 64) = 0;
                *(_DWORD *)(v27 + 120) = v7;
                *(_DWORD *)(v27 + 124) = 9;
                if ( v8 <= 0.0
                  || (CNavArea::GetClosestPointOnArea(this: (CNavArea *)v27, pPos: startPos, close: &v50),
                      (float)((v8 = maxRange) * v8) > (float)((float)((float)(v50.y - startPos->y)
                                                                    * (float)(v50.y - startPos->y))
                                                            + (float)((float)(v50.x - startPos->x)
                                                                    * (float)(v50.x - startPos->x))))
                  && (v28 = *(float *)(v27 + 44) - v7->m_center.x,
                      v29 = *(float *)(v27 + 48) - v7->m_center.y,
                      v30 = v7->m_costSoFar
                          + fsqrt(
                              (float)((float)(v29 * v29)
                                    + (float)((float)(*(float *)(v27 + 52) - v7->m_center.z)
                                            * (float)(*(float *)(v27 + 52) - v7->m_center.z)))
                            + (float)(v28 * v28)),
                      *(float *)(v27 + 68) = v30,
                      (float)(maxRange * 1.5) >= v30) )
                {
                  CNavArea::AddToOpenList(this: (CNavArea *)v27);
                  v8 = maxRange;
                }
              }
              v31 = *(_DWORD *)(count + 40);
              if ( v31 != 0 && *(_DWORD *)(v31 + 60) != CNavArea::m_masterMarker )
              {
                *(_DWORD *)(v31 + 60) = CNavArea::m_masterMarker;
                *(_DWORD *)(v31 + 64) = 0;
                *(_DWORD *)(v31 + 120) = v7;
                *(_DWORD *)(v31 + 124) = 9;
                v32 = (CNavArea *)v31;
                if ( v8 > 0.0 )
                {
                  CNavArea::GetClosestPointOnArea(this: (CNavArea *)v31, pPos: startPos, close: &v49);
                  v8 = maxRange;
                  if ( (float)(v8 * v8) <= (float)((float)((float)(v49.y - startPos->y) * (float)(v49.y - startPos->y))
                                                 + (float)((float)(v49.x - startPos->x) * (float)(v49.x - startPos->x))) )
                    goto LABEL_60;
                  v33 = *(float *)(v31 + 44) - v7->m_center.x;
                  v34 = *(float *)(v31 + 48) - v7->m_center.y;
                  v35 = v7->m_costSoFar
                      + fsqrt(
                          (float)((float)(v34 * v34)
                                + (float)((float)(*(float *)(v31 + 52) - v7->m_center.z)
                                        * (float)(*(float *)(v31 + 52) - v7->m_center.z)))
                        + (float)(v33 * v33));
                  *(float *)(v31 + 68) = v35;
                  if ( (float)(maxRange * 1.5) < v35 )
                    goto LABEL_60;
                  v32 = (CNavArea *)v31;
                }
                CNavArea::AddToOpenList(this: v32);
                v8 = maxRange;
              }
LABEL_60:
              m_pData = v7->m_ladder[0].m_pData;
              ++v58;
            }
            while ( v58 < m_pData->m_Size );
          }
        }
        if ( v7 != (CNavArea *)-108 )
        {
          v36 = v7->m_ladder[1].m_pData;
          v15 = v36->m_Size <= 0;
          v58 = 0;
          if ( !v15 )
          {
            do
            {
              v37 = *(_DWORD *)(v36->m_Elements[v58].id + 48);
              if ( v37 != 0 && *(_DWORD *)(v37 + 60) != CNavArea::m_masterMarker )
              {
                *(_DWORD *)(v37 + 60) = CNavArea::m_masterMarker;
                *(_DWORD *)(v37 + 64) = 0;
                *(_DWORD *)(v37 + 120) = v7;
                *(_DWORD *)(v37 + 124) = 9;
                v38 = (CNavArea *)v37;
                if ( v8 > 0.0 )
                {
                  CNavArea::GetClosestPointOnArea(this: (CNavArea *)v37, pPos: startPos, close: &v48);
                  v8 = maxRange;
                  if ( (float)(v8 * v8) <= (float)((float)((float)(v48.y - startPos->y) * (float)(v48.y - startPos->y))
                                                 + (float)((float)(v48.x - startPos->x) * (float)(v48.x - startPos->x))) )
                    goto LABEL_70;
                  v39 = *(float *)(v37 + 44) - v7->m_center.x;
                  v40 = *(float *)(v37 + 48) - v7->m_center.y;
                  v41 = v7->m_costSoFar
                      + fsqrt(
                          (float)((float)(v40 * v40)
                                + (float)((float)(*(float *)(v37 + 52) - v7->m_center.z)
                                        * (float)(*(float *)(v37 + 52) - v7->m_center.z)))
                        + (float)(v39 * v39));
                  *(float *)(v37 + 68) = v41;
                  if ( (float)(maxRange * 1.5) < v41 )
                    goto LABEL_70;
                  v38 = (CNavArea *)v37;
                }
                CNavArea::AddToOpenList(this: v38);
                v8 = maxRange;
              }
LABEL_70:
              v36 = v7->m_ladder[1].m_pData;
              ++v58;
            }
            while ( v58 < v36->m_Size );
          }
        }
        if ( (options & 8) == 0 )
        {
          v42 = v7->m_elevatorAreas.m_pData;
          v15 = v42->m_Size <= 0;
          v58 = 0;
          if ( !v15 )
          {
            do
            {
              v43 = v42->m_Elements[v58].id;
              if ( v43 != 0 && *(_DWORD *)(v43 + 60) != CNavArea::m_masterMarker )
              {
                *(_DWORD *)(v43 + 60) = CNavArea::m_masterMarker;
                *(_DWORD *)(v43 + 64) = 0;
                *(_DWORD *)(v43 + 120) = v7;
                *(_DWORD *)(v43 + 124) = 9;
                if ( v8 <= 0.0
                  || (CNavArea::GetClosestPointOnArea(this: (CNavArea *)v43, pPos: startPos, close: &v47),
                      (float)((v8 = maxRange) * v8) > (float)((float)((float)(v47.y - startPos->y)
                                                                    * (float)(v47.y - startPos->y))
                                                            + (float)((float)(v47.x - startPos->x)
                                                                    * (float)(v47.x - startPos->x))))
                  && (v44 = *(float *)(v43 + 44) - v7->m_center.x,
                      v45 = *(float *)(v43 + 48) - v7->m_center.y,
                      v46 = v7->m_costSoFar
                          + fsqrt(
                              (float)((float)(v45 * v45)
                                    + (float)((float)(*(float *)(v43 + 52) - v7->m_center.z)
                                            * (float)(*(float *)(v43 + 52) - v7->m_center.z)))
                            + (float)(v44 * v44)),
                      *(float *)(v43 + 68) = v46,
                      (float)(maxRange * 1.5) >= v46) )
                {
                  CNavArea::AddToOpenList(this: (CNavArea *)v43);
                  v8 = maxRange;
                }
              }
              v42 = v7->m_elevatorAreas.m_pData;
              ++v58;
            }
            while ( v58 < v42->m_Size );
          }
        }
      }
      v7 = CNavArea::m_openList;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10307AF0
// Name: void SearchSurroundingAreas<class SelectCollector>(class CNavArea __near *,class Vector const __near &,class SelectCollector __near &,float,unsigned int,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall SearchSurroundingAreas<SelectCollector>(
        const CNavLadder *a1@<ebp>,
        CNavArea *startArea,
        const Vector *startPos,
        SelectCollector *func,
        float maxRange,
        char options,
        int teamID)
{
  CNavArea *v7; // edi
  int m_Size; // esi
  int v9; // eax
  CNavArea **m_pMemory; // edx
  float v11; // xmm0_4
  int v12; // edx
  int v13; // eax
  float v14; // esi
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  bool v18; // cc
  float v19; // esi
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  float *v23; // edx
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // eax
  int id; // eax
  int v26; // esi
  float v27; // xmm1_4
  float v28; // xmm2_4
  float v29; // xmm1_4
  int v30; // esi
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm1_4
  int v34; // esi
  CNavArea *v35; // ecx
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm1_4
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v39; // eax
  int v40; // esi
  CNavArea *v41; // ecx
  float v42; // xmm1_4
  float v43; // xmm2_4
  float v44; // xmm1_4
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *v45; // eax
  unsigned int v46; // esi
  float v47; // xmm1_4
  float v48; // xmm2_4
  float v49; // xmm1_4
  Vector v50; // [esp-60h] [ebp-7Ch] BYREF
  Vector v51; // [esp-54h] [ebp-70h] BYREF
  Vector v52; // [esp-48h] [ebp-64h] BYREF
  Vector v53; // [esp-3Ch] [ebp-58h] BYREF
  Vector v54; // [esp-30h] [ebp-4Ch] BYREF
  Vector v55; // [esp-24h] [ebp-40h] BYREF
  Vector v56; // [esp-18h] [ebp-34h] BYREF
  int v57; // [esp-8h] [ebp-24h]
  float v58; // [esp-4h] [ebp-20h]
  int v59; // [esp+0h] [ebp-1Ch]
  int count; // [esp+4h] [ebp-18h]
  int v61; // [esp+8h] [ebp-14h]
  float **m_connect; // [esp+Ch] [ebp-10h]
  const CNavLadder *ladder; // [esp+10h] [ebp-Ch]
  int it; // [esp+14h] [ebp-8h]
  int retaddr; // [esp+1Ch] [ebp+0h]

  ladder = a1;
  it = retaddr;
  if ( startArea != nullptr )
  {
    if ( ++CNavArea::m_masterMarker == 0 )
      CNavArea::m_masterMarker = 1;
    CNavArea::ClearSearchLists();
    CNavArea::AddToOpenList(this: startArea);
    startArea->m_totalCost = 0.0;
    startArea->m_costSoFar = 0.0;
    startArea->m_parent = nullptr;
    startArea->m_parentHow = NUM_TRAVERSE_TYPES;
    startArea->m_marker = CNavArea::m_masterMarker;
    v7 = CNavArea::m_openList;
    while ( CNavArea::m_openList != nullptr )
    {
      if ( v7 != nullptr )
      {
        CNavArea::RemoveFromOpenList(this: v7);
        v7->m_prevOpen = nullptr;
        v7->m_nextOpen = nullptr;
      }
      else
      {
        v7 = nullptr;
      }
      if ( !v7->IsBlocked(this: v7, a2: teamID, a3: false) || (options & 2) != 0 )
      {
        m_Size = TheNavMesh->m_selectedSet.m_Size;
        v9 = 0;
        if ( m_Size > 0 )
        {
          m_pMemory = TheNavMesh->m_selectedSet.m_Memory.m_pMemory;
          while ( *m_pMemory != v7 )
          {
            ++v9;
            ++m_pMemory;
            if ( v9 >= m_Size )
              goto LABEL_14;
          }
          goto LABEL_83;
        }
LABEL_14:
        CNavMesh::AddToSelectedSet(this: TheNavMesh, area: v7);
        ++func->m_count;
        v11 = maxRange;
        m_connect = (float **)v7->m_connect;
        for ( count = 4; count != 0; --count )
        {
          v57 = *(int *)*m_connect;
          v61 = 0;
          if ( v57 > 0 )
          {
            v59 = options & 4;
            do
            {
              v12 = v61;
              v13 = 0;
              if ( *(int *)*m_connect <= 0 )
              {
LABEL_20:
                v14 = 0.0;
              }
              else
              {
                while ( v12 != 0 )
                {
                  ++v13;
                  --v12;
                  if ( v13 >= *(_DWORD *)*m_connect )
                    goto LABEL_20;
                }
                v14 = (*m_connect)[2 * v13 + 1];
              }
              if ( v59 == 0
                || (v11 = maxRange,
                    CNavArea::IsConnected(this: (CNavArea *)LODWORD(v14), area: v7, dir: NUM_DIRECTIONS) != 0) )
              {
                if ( v14 != 0.0 && *(_DWORD *)(LODWORD(v14) + 60) != CNavArea::m_masterMarker )
                {
                  *(_DWORD *)(LODWORD(v14) + 60) = CNavArea::m_masterMarker;
                  *(_DWORD *)(LODWORD(v14) + 64) = 0;
                  *(_DWORD *)(LODWORD(v14) + 120) = v7;
                  *(_DWORD *)(LODWORD(v14) + 124) = 9;
                  if ( v11 <= 0.0
                    || (CNavArea::GetClosestPointOnArea(this: (CNavArea *)LODWORD(v14), pPos: startPos, close: &v56),
                        v58 = (float)((float)(v56.x - startPos->x) * (float)(v56.x - startPos->x))
                            + (float)((float)(v56.y - startPos->y) * (float)(v56.y - startPos->y)),
                        (float)((v11 = maxRange) * v11) > v58)
                    && (v15 = *(float *)(LODWORD(v14) + 44) - v7->m_center.x,
                        v16 = *(float *)(LODWORD(v14) + 48) - v7->m_center.y,
                        v17 = v7->m_costSoFar
                            + fsqrt(
                                (float)((float)(v16 * v16)
                                      + (float)((float)(*(float *)(LODWORD(v14) + 52) - v7->m_center.z)
                                              * (float)(*(float *)(LODWORD(v14) + 52) - v7->m_center.z)))
                              + (float)(v15 * v15)),
                        *(float *)(LODWORD(v14) + 68) = v17,
                        (float)(maxRange * 1.5) >= v17) )
                  {
                    CNavArea::AddToOpenList(this: (CNavArea *)LODWORD(v14));
                    v11 = maxRange;
                  }
                }
              }
              ++v61;
            }
            while ( v61 < v57 );
          }
          ++m_connect;
        }
        if ( (options & 1) != 0 )
        {
          m_connect = (float **)v7->m_incomingConnect;
          for ( count = 4; count != 0; --count )
          {
            v18 = *(_DWORD *)*m_connect <= 0;
            v61 = 0;
            if ( !v18 )
            {
              do
              {
                v19 = (*m_connect)[2 * v61 + 1];
                v57 = SLODWORD((*m_connect)[2 * v61 + 2]);
                if ( v19 != 0.0 && *(_DWORD *)(LODWORD(v19) + 60) != CNavArea::m_masterMarker )
                {
                  *(_DWORD *)(LODWORD(v19) + 60) = CNavArea::m_masterMarker;
                  *(_DWORD *)(LODWORD(v19) + 64) = 0;
                  *(_DWORD *)(LODWORD(v19) + 120) = v7;
                  *(_DWORD *)(LODWORD(v19) + 124) = 9;
                  if ( v11 <= 0.0
                    || (CNavArea::GetClosestPointOnArea(this: (CNavArea *)LODWORD(v19), pPos: startPos, close: &v55),
                        (float)((v11 = maxRange) * v11) > (float)((float)((float)(v55.y - startPos->y)
                                                                        * (float)(v55.y - startPos->y))
                                                                + (float)((float)(v55.x - startPos->x)
                                                                        * (float)(v55.x - startPos->x))))
                    && (v20 = *(float *)(LODWORD(v19) + 44) - v7->m_center.x,
                        v21 = *(float *)(LODWORD(v19) + 48) - v7->m_center.y,
                        v22 = v7->m_costSoFar
                            + fsqrt(
                                (float)((float)(v21 * v21) + (float)(v20 * v20))
                              + (float)((float)(*(float *)(LODWORD(v19) + 52) - v7->m_center.z)
                                      * (float)(*(float *)(LODWORD(v19) + 52) - v7->m_center.z))),
                        *(float *)(LODWORD(v19) + 68) = v22,
                        (float)(maxRange * 1.5) >= v22) )
                  {
                    CNavArea::AddToOpenList(this: (CNavArea *)LODWORD(v19));
                    v11 = maxRange;
                  }
                }
                v23 = *m_connect;
                ++v61;
              }
              while ( v61 < *(_DWORD *)v23 );
            }
            ++m_connect;
          }
        }
        if ( v7 != (CNavArea *)-104 )
        {
          m_pData = v7->m_ladder[0].m_pData;
          v18 = m_pData->m_Size <= 0;
          v61 = 0;
          if ( !v18 )
          {
            do
            {
              id = m_pData->m_Elements[v61].id;
              v26 = *(_DWORD *)(id + 32);
              count = id;
              if ( v26 != 0 && *(_DWORD *)(v26 + 60) != CNavArea::m_masterMarker )
              {
                *(_DWORD *)(v26 + 60) = CNavArea::m_masterMarker;
                *(_DWORD *)(v26 + 64) = 0;
                *(_DWORD *)(v26 + 120) = v7;
                *(_DWORD *)(v26 + 124) = 9;
                if ( v11 <= 0.0
                  || (CNavArea::GetClosestPointOnArea(this: (CNavArea *)v26, pPos: startPos, close: &v54),
                      *(float *)&v57 = (float)((float)(v54.x - startPos->x) * (float)(v54.x - startPos->x))
                                     + (float)((float)(v54.y - startPos->y) * (float)(v54.y - startPos->y)),
                      (float)((v11 = maxRange) * v11) > *(float *)&v57)
                  && (v27 = *(float *)(v26 + 44) - v7->m_center.x,
                      v28 = *(float *)(v26 + 48) - v7->m_center.y,
                      v29 = v7->m_costSoFar
                          + fsqrt(
                              (float)((float)(v28 * v28)
                                    + (float)((float)(*(float *)(v26 + 52) - v7->m_center.z)
                                            * (float)(*(float *)(v26 + 52) - v7->m_center.z)))
                            + (float)(v27 * v27)),
                      *(float *)(v26 + 68) = v29,
                      (float)(maxRange * 1.5) >= v29) )
                {
                  CNavArea::AddToOpenList(this: (CNavArea *)v26);
                  v11 = maxRange;
                }
              }
              v30 = *(_DWORD *)(count + 36);
              if ( v30 != 0 && *(_DWORD *)(v30 + 60) != CNavArea::m_masterMarker )
              {
                *(_DWORD *)(v30 + 60) = CNavArea::m_masterMarker;
                *(_DWORD *)(v30 + 64) = 0;
                *(_DWORD *)(v30 + 120) = v7;
                *(_DWORD *)(v30 + 124) = 9;
                if ( v11 <= 0.0
                  || (CNavArea::GetClosestPointOnArea(this: (CNavArea *)v30, pPos: startPos, close: &v53),
                      (float)((v11 = maxRange) * v11) > (float)((float)((float)(v53.y - startPos->y)
                                                                      * (float)(v53.y - startPos->y))
                                                              + (float)((float)(v53.x - startPos->x)
                                                                      * (float)(v53.x - startPos->x))))
                  && (v31 = *(float *)(v30 + 44) - v7->m_center.x,
                      v32 = *(float *)(v30 + 48) - v7->m_center.y,
                      v33 = v7->m_costSoFar
                          + fsqrt(
                              (float)((float)(v32 * v32)
                                    + (float)((float)(*(float *)(v30 + 52) - v7->m_center.z)
                                            * (float)(*(float *)(v30 + 52) - v7->m_center.z)))
                            + (float)(v31 * v31)),
                      *(float *)(v30 + 68) = v33,
                      (float)(maxRange * 1.5) >= v33) )
                {
                  CNavArea::AddToOpenList(this: (CNavArea *)v30);
                  v11 = maxRange;
                }
              }
              v34 = *(_DWORD *)(count + 40);
              if ( v34 != 0 && *(_DWORD *)(v34 + 60) != CNavArea::m_masterMarker )
              {
                *(_DWORD *)(v34 + 60) = CNavArea::m_masterMarker;
                *(_DWORD *)(v34 + 64) = 0;
                *(_DWORD *)(v34 + 120) = v7;
                *(_DWORD *)(v34 + 124) = 9;
                v35 = (CNavArea *)v34;
                if ( v11 > 0.0 )
                {
                  CNavArea::GetClosestPointOnArea(this: (CNavArea *)v34, pPos: startPos, close: &v52);
                  v11 = maxRange;
                  if ( (float)(v11 * v11) <= (float)((float)((float)(v52.y - startPos->y) * (float)(v52.y - startPos->y))
                                                   + (float)((float)(v52.x - startPos->x) * (float)(v52.x - startPos->x))) )
                    goto LABEL_63;
                  v36 = *(float *)(v34 + 44) - v7->m_center.x;
                  v37 = *(float *)(v34 + 48) - v7->m_center.y;
                  v38 = v7->m_costSoFar
                      + fsqrt(
                          (float)((float)(v37 * v37)
                                + (float)((float)(*(float *)(v34 + 52) - v7->m_center.z)
                                        * (float)(*(float *)(v34 + 52) - v7->m_center.z)))
                        + (float)(v36 * v36));
                  *(float *)(v34 + 68) = v38;
                  if ( (float)(maxRange * 1.5) < v38 )
                    goto LABEL_63;
                  v35 = (CNavArea *)v34;
                }
                CNavArea::AddToOpenList(this: v35);
                v11 = maxRange;
              }
LABEL_63:
              m_pData = v7->m_ladder[0].m_pData;
              ++v61;
            }
            while ( v61 < m_pData->m_Size );
          }
        }
        if ( v7 != (CNavArea *)-108 )
        {
          v39 = v7->m_ladder[1].m_pData;
          v18 = v39->m_Size <= 0;
          v61 = 0;
          if ( !v18 )
          {
            do
            {
              v40 = *(_DWORD *)(v39->m_Elements[v61].id + 48);
              if ( v40 != 0 && *(_DWORD *)(v40 + 60) != CNavArea::m_masterMarker )
              {
                *(_DWORD *)(v40 + 60) = CNavArea::m_masterMarker;
                *(_DWORD *)(v40 + 64) = 0;
                *(_DWORD *)(v40 + 120) = v7;
                *(_DWORD *)(v40 + 124) = 9;
                v41 = (CNavArea *)v40;
                if ( v11 > 0.0 )
                {
                  CNavArea::GetClosestPointOnArea(this: (CNavArea *)v40, pPos: startPos, close: &v51);
                  v11 = maxRange;
                  if ( (float)(v11 * v11) <= (float)((float)((float)(v51.y - startPos->y) * (float)(v51.y - startPos->y))
                                                   + (float)((float)(v51.x - startPos->x) * (float)(v51.x - startPos->x))) )
                    goto LABEL_73;
                  v42 = *(float *)(v40 + 44) - v7->m_center.x;
                  v43 = *(float *)(v40 + 48) - v7->m_center.y;
                  v44 = v7->m_costSoFar
                      + fsqrt(
                          (float)((float)(v43 * v43)
                                + (float)((float)(*(float *)(v40 + 52) - v7->m_center.z)
                                        * (float)(*(float *)(v40 + 52) - v7->m_center.z)))
                        + (float)(v42 * v42));
                  *(float *)(v40 + 68) = v44;
                  if ( (float)(maxRange * 1.5) < v44 )
                    goto LABEL_73;
                  v41 = (CNavArea *)v40;
                }
                CNavArea::AddToOpenList(this: v41);
                v11 = maxRange;
              }
LABEL_73:
              v39 = v7->m_ladder[1].m_pData;
              ++v61;
            }
            while ( v61 < v39->m_Size );
          }
        }
        if ( (options & 8) == 0 )
        {
          v45 = v7->m_elevatorAreas.m_pData;
          v18 = v45->m_Size <= 0;
          v61 = 0;
          if ( !v18 )
          {
            do
            {
              v46 = v45->m_Elements[v61].id;
              if ( v46 != 0 && *(_DWORD *)(v46 + 60) != CNavArea::m_masterMarker )
              {
                *(_DWORD *)(v46 + 60) = CNavArea::m_masterMarker;
                *(_DWORD *)(v46 + 64) = 0;
                *(_DWORD *)(v46 + 120) = v7;
                *(_DWORD *)(v46 + 124) = 9;
                if ( v11 <= 0.0
                  || (CNavArea::GetClosestPointOnArea(this: (CNavArea *)v46, pPos: startPos, close: &v50),
                      (float)((v11 = maxRange) * v11) > (float)((float)((float)(v50.y - startPos->y)
                                                                      * (float)(v50.y - startPos->y))
                                                              + (float)((float)(v50.x - startPos->x)
                                                                      * (float)(v50.x - startPos->x))))
                  && (v47 = *(float *)(v46 + 44) - v7->m_center.x,
                      v48 = *(float *)(v46 + 48) - v7->m_center.y,
                      v49 = v7->m_costSoFar
                          + fsqrt(
                              (float)((float)(v48 * v48)
                                    + (float)((float)(*(float *)(v46 + 52) - v7->m_center.z)
                                            * (float)(*(float *)(v46 + 52) - v7->m_center.z)))
                            + (float)(v47 * v47)),
                      *(float *)(v46 + 68) = v49,
                      (float)(maxRange * 1.5) >= v49) )
                {
                  CNavArea::AddToOpenList(this: (CNavArea *)v46);
                  v11 = maxRange;
                }
              }
              v45 = v7->m_elevatorAreas.m_pData;
              ++v61;
            }
            while ( v61 < v45->m_Size );
          }
        }
      }
LABEL_83:
      v7 = CNavArea::m_openList;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D3450
// Name: __CreateCServerGameTagsIServerGameTags_interface_41
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_41()
{
  return &_g_CServerGameTags_singleton_41;
}
