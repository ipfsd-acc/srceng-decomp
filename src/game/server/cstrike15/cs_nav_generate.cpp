// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/cs_nav_generate.cpp
// Functions: 1
// ============================================================

#include "game\server\cstrike15\cs_nav_generate.h"

//------------------------------------------------------------------------------
// Address: 0x102E00A0
// Name: public: void CCSNavArea::ComputeApproachAreas(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall CCSNavArea::ComputeApproachAreas(CCSNavArea *this@<ecx>, int a2@<ebp>)
{
  float z; // eax
  float v4; // xmm0_4
  int m_Size; // ecx
  int z_low; // eax
  CNavArea *v7; // edi
  CNavArea *v8; // eax
  CNavArea *v9; // esi
  int v10; // ecx
  int v11; // esi
  CNavArea *m_parent; // eax
  float v13; // ecx
  int v14; // ecx
  __int128 v15; // xmm1
  int v16; // eax
  CNavArea *v17; // esi
  int v18; // edi
  float v19; // eax
  unsigned int id; // esi
  _DWORD *v21; // eax
  CNavArea *v22; // esi
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // eax
  bool v24; // cc
  int v25; // eax
  __int128 v26; // xmm0
  CNavArea *v27; // eax
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm3_4
  int v31; // eax
  float v32; // xmm0_4
  __int128 v33; // xmm1
  double v34; // xmm0_8
  int v35; // ecx
  int v36; // ecx
  int v37; // eax
  int *v38; // edx
  int v39; // edi
  int v40; // ecx
  int v41; // eax
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *v42; // esi
  int *v43; // edi
  CNavArea *v44; // eax
  int m_pData_low; // ecx
  int v46; // edx
  CNavArea *v47; // esi
  int v48; // edx
  int v49; // edi
  CNavArea *path[256]; // [esp+3Ch] [ebp-478h] BYREF
  _BYTE extent[28]; // [esp+43Ch] [ebp-78h] OVERLAPPED
  __int64 v52; // [esp+458h] [ebp-5Ch]
  float v53; // [esp+460h] [ebp-54h]
  CNavArea *v54; // [esp+464h] [ebp-50h]
  __int64 v55; // [esp+468h] [ebp-4Ch] BYREF
  CNavArea *farArea; // [esp+470h] [ebp-44h] BYREF
  Vector eye; // [esp+474h] [ebp-40h]
  int i; // [esp+480h] [ebp-34h]
  int v59; // [esp+484h] [ebp-30h]
  int it; // [esp+488h] [ebp-2Ch]
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *m_connect; // [esp+48Ch] [ebp-28h]
  int searchType; // [esp+490h] [ebp-24h]
  CNavArea *to; // [esp+494h] [ebp-20h]
  CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator> *m_ladder; // [esp+498h] [ebp-1Ch]
  int v65; // [esp+49Ch] [ebp-18h]
  CNavArea *v66; // [esp+4A0h] [ebp-14h]
  bool v67; // [esp+4A6h] [ebp-Eh]
  char v68; // [esp+4A7h] [ebp-Dh]
  int block; // [esp+4A8h] [ebp-Ch] BYREF
  void *v70; // [esp+4ACh] [ebp-8h]
  void *retaddr; // [esp+4B4h] [ebp+0h]

  block = a2;
  v70 = retaddr;
  this->m_approachCount = 0;
  to = this;
  if ( nav_quicksave.m_pParent == nullptr || nav_quicksave.m_pParent->m_Value.m_nValue == 0 )
  {
    z = this->m_center.z;
    v55 = *(_QWORD *)&this->m_center.x;
    *(float *)&farArea = z;
    if ( CNavMesh::GetGroundHeight(
           this: TheNavMesh,
           pos: (const Vector *)&v55,
           height: (float *)&farArea,
           normal: nullptr) )
    {
      if ( (this->m_attributeFlags & 1) != 0 )
        v4 = *(float *)&farArea + 31.94999915361404;
      else
        v4 = *(float *)&farArea + 63.899998;
      m_Size = TheNavAreas.m_Size;
      *(float *)&farArea = v4;
      v59 = 0;
      while ( 1 )
      {
        eye.z = 0.0;
        if ( m_Size > 0 )
          break;
LABEL_85:
        if ( ++v59 == 2 )
          return;
      }
      z_low = LODWORD(eye.z);
      while ( 1 )
      {
        v54 = TheNavAreas.m_Memory.m_pMemory[z_low];
        v7 = v54;
        blockedIDCount = 0;
        CNavArea::GetExtent(this: v54, extent: (Extent *)&path[253]);
        if ( (float)(*(float *)extent - *(float *)&path[253]) >= 200.0
          && (float)(*(float *)&extent[4] - *(float *)&path[254]) >= 200.0
          && CNavArea::IsVisible(this: v7, eye: (const Vector *)&v55, visSpot: nullptr) == 0 )
        {
          v8 = to;
          if ( LOBYTE(to[2].m_hidingSpots.m_pData) < 0x10u )
            break;
        }
LABEL_84:
        m_Size = TheNavAreas.m_Size;
        z_low = LODWORD(eye.z) + 1;
        LODWORD(eye.z) = z_low;
        if ( z_low >= TheNavAreas.m_Size )
          goto LABEL_85;
      }
      while ( 1 )
      {
        if ( v59 != 0 )
        {
          v9 = v7;
          v7 = v8;
          it = (int)v8;
        }
        else
        {
          v9 = v8;
          it = (int)v7;
        }
        CVProfile::EnterScope(
          this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
          a2: "NavAreaBuildPath",
          a3: 0,
          a4: "NextBotSpiky",
          a5: false,
          a6: 4);
        v10 = g_DebugPathfindCounter--;
        v67 = v10 > 0;
        if ( v9 == nullptr || v7 == nullptr || v7->IsBlocked(this: v7, a2: -1, a3: false) )
          goto LABEL_83;
        v9->m_parent = nullptr;
        v9->m_parentHow = NUM_TRAVERSE_TYPES;
        if ( v9 == v7 )
        {
          v7->m_parent = nullptr;
          v7->m_parentHow = NUM_TRAVERSE_TYPES;
          goto LABEL_22;
        }
        v13 = v7->m_center.z;
        v52 = *(_QWORD *)&v7->m_center.x;
        v53 = v13;
        CNavArea::ClearSearchLists();
        v14 = blockedIDCount;
        v15 = 0;
        *(float *)&v15 = fsqrt(
                           (float)((float)((float)(v9->m_center.x - *(float *)&v52)
                                         * (float)(v9->m_center.x - *(float *)&v52))
                                 + (float)((float)(v9->m_center.y - *((float *)&v52 + 1))
                                         * (float)(v9->m_center.y - *((float *)&v52 + 1))))
                         + (float)((float)(v9->m_center.z - v53) * (float)(v9->m_center.z - v53)));
        *(_OWORD *)&extent[12] = v15;
        v16 = 0;
        LODWORD(v9->m_totalCost) = v15;
        if ( v14 > 0 )
        {
          while ( v9->m_id != blockedID[v16] )
          {
            if ( ++v16 >= v14 )
              goto LABEL_29;
          }
LABEL_83:
          CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
          goto LABEL_84;
        }
LABEL_29:
        v9->m_costSoFar = 0.0;
        v9->m_pathLengthSoFar = 0.0;
        CNavArea::AddToOpenList(this: v9);
        v17 = CNavArea::m_openList;
        if ( CNavArea::m_openList == nullptr )
          goto LABEL_83;
        while ( 1 )
        {
          v66 = v17;
          CNavArea::RemoveFromOpenList(this: v17);
          v17->m_prevOpen = nullptr;
          v17->m_nextOpen = nullptr;
          if ( v67 )
            ((void (__thiscall *)(CNavArea *, _DWORD, int, _DWORD, int, int, int, int))v17->DrawFilled)(
              a1: v17,
              a2: 0,
              a3: 255,
              a4: 0,
              a5: 128,
              a6: 1106247680,
              a7: 1,
              a8: 1084227584);
          if ( !v17->IsBlocked(this: v17, a2: -1, a3: false) )
            break;
LABEL_82:
          v17 = CNavArea::m_openList;
          if ( CNavArea::m_openList == nullptr )
            goto LABEL_83;
        }
        if ( v17 != v7 )
          break;
LABEL_22:
        CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
        v11 = 0;
        m_parent = v7;
        do
        {
          m_parent = m_parent->m_parent;
          ++v11;
        }
        while ( m_parent != nullptr );
        if ( v11 <= 256 )
        {
          if ( v11 <= 2 )
            goto LABEL_84;
        }
        else
        {
          v11 = 256;
        }
        v36 = 0;
        v37 = (int)v7;
        if ( v59 != 0 )
        {
          do
          {
            if ( v37 == 0 )
              break;
            *(&block + v36 - 286) = v37;
            v37 = *(_DWORD *)(v37 + 120);
            ++v36;
          }
          while ( v36 < v11 );
        }
        else
        {
          v38 = &block + v11 - 287;
          do
          {
            if ( v37 == 0 )
              break;
            *v38 = v37;
            v37 = *(_DWORD *)(v37 + 120);
            ++v36;
            --v38;
          }
          while ( v36 < v11 );
        }
        v39 = 1;
        while ( 1 )
        {
          if ( CNavArea::IsVisible(this: (CNavArea *)*(&block + v39 - 286), eye: (const Vector *)&v55, visSpot: nullptr) == 0 )
          {
            v40 = blockedIDCount;
            if ( blockedIDCount == 256 )
            {
              _Msg(a1: "Overflow computing approach areas for area #%d.\n", to->m_id);
              return;
            }
            if ( (CNavArea *)*(&block + v39 - 286) == v54 )
            {
              v41 = v39 - 1;
              v65 = v39 - 1;
            }
            else
            {
              v65 = v39;
              v41 = v39;
            }
            if ( v41 != 0 )
              break;
          }
          if ( ++v39 >= v11 )
            goto LABEL_114;
        }
        v42 = (CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *)*(&block + v41 - 286);
        v43 = &block + v41 - 286;
        v44 = to;
        blockedID[blockedIDCount] = (unsigned int)v42[34].m_pData;
        blockedIDCount = v40 + 1;
        m_pData_low = LOBYTE(v44[2].m_hidingSpots.m_pData);
        v46 = 0;
        m_ladder = (CUtlVectorUltraConservative<NavLadderConnect,CUtlVectorUltraConservativeAllocator> *)v43;
        m_connect = v42;
        if ( m_pData_low != 0 )
        {
          it = *(v43 - 1);
          v47 = v44 + 1;
          do
          {
            if ( v47->__vftable == (CNavArea_vtbl *)it )
              break;
            ++v46;
            v47 = (CNavArea *)((char *)v47 + 32);
          }
          while ( v46 < LOBYTE(v44[2].m_hidingSpots.m_pData) );
          v42 = m_connect;
          v43 = (int *)m_ladder;
        }
        if ( v46 == m_pData_low )
        {
          if ( v65 < 2 )
            v48 = 0;
          else
            v48 = *(&block + v65 - 288);
          v49 = *(v43 - 1);
          *((_DWORD *)&v44[1].m_nwCorner.y + 8 * m_pData_low) = v48;
          *((_DWORD *)&v44[1].__vftable + 8 * LOBYTE(v44[2].m_hidingSpots.m_pData)) = v49;
          *((_DWORD *)&v44[1].m_seCorner.x + 8 * LOBYTE(v44[2].m_hidingSpots.m_pData)) = *(_DWORD *)(v49 + 124);
          *((_DWORD *)&v44[1].m_seCorner.y + 8 * LOBYTE(v44[2].m_hidingSpots.m_pData)) = v42;
          *((CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator> *)&v44[1].m_invDxCorners
          + 8 * (unsigned __int8)LOBYTE(v44[2].m_hidingSpots.m_pData)++) = v42[31];
        }
LABEL_114:
        v8 = to;
        if ( LOBYTE(to[2].m_hidingSpots.m_pData) >= 0x10u )
          goto LABEL_84;
        v7 = v54;
      }
      v18 = 0;
      eye.y = 0.0;
      eye.x = 0.0;
      m_connect = v17->m_connect;
      v68 = 1;
      m_ladder = nullptr;
      for ( i = 0; ; i = 0 )
      {
        while ( 1 )
        {
          while ( 1 )
          {
            while ( 1 )
            {
              while ( 1 )
              {
                v65 = 0;
                if ( LODWORD(eye.y) != 0 )
                  break;
                if ( v18 < m_connect->m_pData->m_Size )
                {
                  id = m_connect->m_pData->m_Elements[v18].id;
                  searchType = LODWORD(eye.x);
                  ++v18;
                  goto LABEL_62;
                }
                LODWORD(v19) = LODWORD(eye.x) + 1;
                eye.x = v19;
                if ( LODWORD(v19) == 4 )
                {
                  LODWORD(eye.y) = 1;
                  m_ladder = v66->m_ladder;
                  v18 = 0;
                  i = 0;
                }
                else
                {
                  m_connect = &v66->m_connect[LODWORD(v19)];
                  v18 = 0;
                }
              }
              if ( LODWORD(eye.y) == 1 )
                break;
              v22 = v66;
              if ( CNavArea::GetElevator(this: v66) == nullptr
                || (m_pData = v22->m_elevatorAreas.m_pData, v18 >= m_pData->m_Size) )
              {
                v7 = (CNavArea *)it;
                v22->m_marker = CNavArea::m_masterMarker;
                goto LABEL_82;
              }
              id = m_pData->m_Elements[v18++].id;
              v24 = *(float *)(id + 52) <= v66->m_center.z;
              searchType = 7;
              if ( v24 )
                searchType = 8;
LABEL_62:
              if ( (CNavArea *)id != v66
                && (*(unsigned __int8 (__thiscall **)(unsigned int, int, _DWORD))(*(_DWORD *)id + 68))(
                     a1: id,
                     a2: -1,
                     a3: 0) == 0 )
              {
                v25 = 0;
                if ( blockedIDCount <= 0 )
                {
LABEL_67:
                  if ( v65 != 0 )
                  {
                    LODWORD(v26) = *(_DWORD *)(v65 + 24);
                    v27 = v66;
                  }
                  else
                  {
                    v27 = v66;
                    v28 = *(float *)(id + 44) - v66->m_center.x;
                    v29 = (float)((float)((float)(*(float *)(id + 48) - v27->m_center.y)
                                        * (float)(*(float *)(id + 48) - v27->m_center.y))
                                + (float)((float)(*(float *)(id + 52) - v27->m_center.z)
                                        * (float)(*(float *)(id + 52) - v27->m_center.z)))
                        + (float)(v28 * v28);
                    v26 = 0;
                    *(float *)&v26 = fsqrt(v29);
                    *(_OWORD *)&extent[12] = v26;
                  }
                  v30 = v27->m_costSoFar + *(float *)&v26;
                  if ( v30 >= 0.0
                    && ((v31 = *(_DWORD *)(id + 80)) != CNavArea::m_masterMarker
                     && *(_DWORD *)(id + 60) != CNavArea::m_masterMarker
                     || v30 < *(float *)(id + 68)) )
                  {
                    v32 = (float)((float)((float)(*(float *)(id + 48) - *((float *)&v52 + 1))
                                        * (float)(*(float *)(id + 48) - *((float *)&v52 + 1)))
                                + (float)((float)(*(float *)(id + 44) - *(float *)&v52)
                                        * (float)(*(float *)(id + 44) - *(float *)&v52)))
                        + (float)((float)(*(float *)(id + 52) - v53) * (float)(*(float *)(id + 52) - v53));
                    if ( v32 <= 0.0 )
                    {
                      v34 = 0.0;
                    }
                    else
                    {
                      v33 = 0;
                      *(float *)&v33 = fsqrt(v32);
                      *(_OWORD *)&extent[12] = v33;
                      v34 = *(float *)&v33;
                    }
                    *(float *)(id + 68) = v30;
                    *(float *)(id + 64) = (float)v34 + v30;
                    if ( v31 == CNavArea::m_masterMarker )
                      CNavArea::UpdateOnOpenList(this: (CNavArea *)id);
                    else
                      CNavArea::AddToOpenList(this: (CNavArea *)id);
                    v35 = searchType;
                    *(_DWORD *)(id + 120) = v66;
                    *(_DWORD *)(id + 124) = v35;
                  }
                }
                else
                {
                  while ( *(_DWORD *)(id + 136) != blockedID[v25] )
                  {
                    if ( ++v25 >= blockedIDCount )
                      goto LABEL_67;
                  }
                }
              }
            }
            if ( v18 < m_ladder->m_pData->m_Size )
              break;
            if ( v68 != 0 )
            {
              v68 = 0;
              m_ladder = &v66->m_ladder[1];
            }
            else
            {
              LODWORD(eye.y) = 2;
            }
            v18 = 0;
          }
          v21 = (_DWORD *)m_ladder->m_pData->m_Elements[v18].id;
          v65 = (int)v21;
          if ( v68 == 0 )
          {
            id = v21[12];
            searchType = 5;
            ++v18;
            goto LABEL_56;
          }
          if ( i != 0 )
            break;
          id = v21[8];
          searchType = 4;
          i = 1;
LABEL_56:
          if ( id != 0 )
            goto LABEL_62;
        }
        if ( i == 1 )
        {
          id = v21[9];
          searchType = 4;
          i = 2;
          goto LABEL_56;
        }
        if ( i == 2 )
        {
          id = v21[10];
          searchType = 4;
          i = 3;
          goto LABEL_56;
        }
        ++v18;
      }
    }
  }
}
