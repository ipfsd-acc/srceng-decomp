// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmap/overlay.cpp
// Functions: 7
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00428C00
// Name: void Overlay_EmitOverlayFaces(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Overlay_EmitOverlayFaces()
{
  int v0; // esi
  char *v1; // esi
  doverlayfade_t *v2; // eax
  bool v3; // zf
  doverlay_t *v4; // edi
  float *v5; // ecx
  int i; // ebx
  float *v7; // eax
  int j; // edx
  int v9; // ecx
  int k; // eax
  texinfo_s searchTexInfo; // [esp+24h] [ebp-58h] BYREF
  const char *v12; // [esp+6Ch] [ebp-10h]
  int m_Size; // [esp+70h] [ebp-Ch]
  int v14; // [esp+74h] [ebp-8h]
  doverlayfade_t *v15; // [esp+78h] [ebp-4h]

  if ( g_aMapOverlays.m_Size > 0 )
  {
    v0 = 0;
    v14 = 0;
    m_Size = g_aMapOverlays.m_Size;
    do
    {
      v1 = (char *)g_aMapOverlays.m_Memory.m_pMemory + v0;
      if ( g_nOverlayCount < 512 )
      {
        v2 = &g_OverlayFades[g_nOverlayCount];
        v3 = &g_Overlays[g_nOverlayCount] == nullptr;
        v4 = &g_Overlays[g_nOverlayCount];
        v15 = v2;
        ++g_nOverlayCount;
        if ( v3 )
          goto LABEL_17;
        v4->nId = *(_DWORD *)v1;
        v4->flU[0] = *((float *)v1 + 66);
        v4->flU[1] = *((float *)v1 + 67);
        v4->flV[0] = *((float *)v1 + 68);
        v4->flV[1] = *((float *)v1 + 69);
        v4->vecUVPoints[0].x = *((float *)v1 + 72);
        v4->vecUVPoints[0].y = *((float *)v1 + 73);
        v4->vecUVPoints[0].z = *((float *)v1 + 74);
        v4->vecUVPoints[1].x = *((float *)v1 + 75);
        v4->vecUVPoints[1].y = *((float *)v1 + 76);
        v4->vecUVPoints[1].z = *((float *)v1 + 77);
        v4->vecUVPoints[2].x = *((float *)v1 + 78);
        v4->vecUVPoints[2].y = *((float *)v1 + 79);
        v4->vecUVPoints[2].z = *((float *)v1 + 80);
        v4->vecUVPoints[3].x = *((float *)v1 + 81);
        v4->vecUVPoints[3].y = *((float *)v1 + 82);
        v4->vecUVPoints[3].z = *((float *)v1 + 83);
        v4->vecOrigin.x = *((float *)v1 + 84);
        v4->vecOrigin.y = *((float *)v1 + 85);
        v4->vecOrigin.z = *((float *)v1 + 86);
        v4->vecBasisNormal.x = *((float *)v1 + 93);
        v4->vecBasisNormal.y = *((float *)v1 + 94);
        v4->vecBasisNormal.z = *((float *)v1 + 95);
        v4->m_nFaceCountAndRenderOrder = v4->m_nFaceCountAndRenderOrder & 0x3FFF | (*((_WORD *)v1 + 2) << 14);
        v4->vecUVPoints[0].z = *((float *)v1 + 87);
        v4->vecUVPoints[1].z = *((float *)v1 + 88);
        v4->vecUVPoints[2].z = *((float *)v1 + 89);
        if ( (float)((float)((float)(*((float *)v1 + 91)
                                   * (float)((float)(*((float *)v1 + 87) * *((float *)v1 + 95))
                                           - (float)(*((float *)v1 + 89) * *((float *)v1 + 93))))
                           + (float)(*((float *)v1 + 90)
                                   * (float)((float)(*((float *)v1 + 94) * *((float *)v1 + 89))
                                           - (float)(*((float *)v1 + 95) * *((float *)v1 + 88)))))
                   + (float)(*((float *)v1 + 92)
                           * (float)((float)(*((float *)v1 + 88) * *((float *)v1 + 93))
                                   - (float)(*((float *)v1 + 87) * *((float *)v1 + 94))))) < 0.0 )
          v4->vecUVPoints[3].z = 1.0;
        searchTexInfo.flags = 0;
        v12 = v1 + 6;
        searchTexInfo.texdata = FindOrCreateTexData(pName_: v1 + 6);
        v5 = &searchTexInfo.lightmapVecsLuxelsPerWorldUnits[0][3];
        for ( i = 2; i != 0; --i )
        {
          v7 = v5 - 11;
          for ( j = 3; j != 0; --j )
          {
            v7[8] = 0.0;
            *v7++ = 0.0;
          }
          *v5 = -99999.0;
          *(v5 - 8) = -99999.0;
          v5 += 4;
        }
        v4->nTexInfo = FindOrCreateTexInfo(&searchTexInfo);
        v9 = *((_DWORD *)v1 + 104);
        if ( v9 < 64 )
        {
          v4->m_nFaceCountAndRenderOrder ^= (v9 ^ v4->m_nFaceCountAndRenderOrder) & 0x3FFF;
          for ( k = 0; k < v9; ++k )
            v4->aFaces[k] = *(_DWORD *)(*((_DWORD *)v1 + 101) + 4 * k);
          v2 = v15;
LABEL_17:
          if ( v2 != nullptr )
          {
            v2->flFadeDistMinSq = *((float *)v1 + 70);
            v2->flFadeDistMaxSq = *((float *)v1 + 71);
          }
          goto LABEL_19;
        }
        _Error(
          a1: "Overlay touching too many faces (touching %d, max %d)\nOverlay %s at %.1f %.1f %.1f",
          v9,
          64,
          v12,
          *((float *)v1 + 84),
          *((float *)v1 + 85),
          *((float *)v1 + 86));
      }
      else
      {
        _Error(a1: "Too Many Overlays!\nMAX_MAP_OVERLAYS = %d", 512);
      }
LABEL_19:
      v0 = v14 + 424;
      v3 = m_Size-- == 1;
      v14 += 424;
    }
    while ( !v3 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428F90
// Name: void OverlayTransition_EmitOverlayFaces(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OverlayTransition_EmitOverlayFaces()
{
  int v0; // esi
  char *v1; // esi
  bool v2; // zf
  dwateroverlay_t *v3; // edi
  float *v4; // ecx
  int i; // ebx
  float *v6; // eax
  int j; // edx
  int v8; // ecx
  int k; // eax
  texinfo_s searchTexInfo; // [esp+24h] [ebp-54h] BYREF
  const char *v11; // [esp+6Ch] [ebp-Ch]
  int m_Size; // [esp+70h] [ebp-8h]
  int v13; // [esp+74h] [ebp-4h]

  if ( g_aMapWaterOverlays.m_Size > 0 )
  {
    v0 = 0;
    v13 = 0;
    m_Size = g_aMapWaterOverlays.m_Size;
    do
    {
      v1 = (char *)g_aMapWaterOverlays.m_Memory.m_pMemory + v0;
      if ( g_nWaterOverlayCount < 0x4000 )
      {
        v2 = &g_WaterOverlays[g_nWaterOverlayCount] == nullptr;
        v3 = &g_WaterOverlays[g_nWaterOverlayCount++];
        if ( !v2 )
        {
          v3->nId = *(_DWORD *)v1;
          v3->flU[0] = *((float *)v1 + 66);
          v3->flU[1] = *((float *)v1 + 67);
          v3->flV[0] = *((float *)v1 + 68);
          v3->flV[1] = *((float *)v1 + 69);
          v3->vecUVPoints[0].x = *((float *)v1 + 72);
          v3->vecUVPoints[0].y = *((float *)v1 + 73);
          v3->vecUVPoints[0].z = *((float *)v1 + 74);
          v3->vecUVPoints[1].x = *((float *)v1 + 75);
          v3->vecUVPoints[1].y = *((float *)v1 + 76);
          v3->vecUVPoints[1].z = *((float *)v1 + 77);
          v3->vecUVPoints[2].x = *((float *)v1 + 78);
          v3->vecUVPoints[2].y = *((float *)v1 + 79);
          v3->vecUVPoints[2].z = *((float *)v1 + 80);
          v3->vecUVPoints[3].x = *((float *)v1 + 81);
          v3->vecUVPoints[3].y = *((float *)v1 + 82);
          v3->vecUVPoints[3].z = *((float *)v1 + 83);
          v3->vecOrigin.x = *((float *)v1 + 84);
          v3->vecOrigin.y = *((float *)v1 + 85);
          v3->vecOrigin.z = *((float *)v1 + 86);
          v3->vecBasisNormal.x = *((float *)v1 + 93);
          v3->vecBasisNormal.y = *((float *)v1 + 94);
          v3->vecBasisNormal.z = *((float *)v1 + 95);
          v3->m_nFaceCountAndRenderOrder = (*((_WORD *)v1 + 2) << 14) | v3->m_nFaceCountAndRenderOrder & 0x3FFF;
          v3->vecUVPoints[0].z = *((float *)v1 + 87);
          v3->vecUVPoints[1].z = *((float *)v1 + 88);
          v3->vecUVPoints[2].z = *((float *)v1 + 89);
          if ( (float)((float)((float)(*((float *)v1 + 91)
                                     * (float)((float)(*((float *)v1 + 87) * *((float *)v1 + 95))
                                             - (float)(*((float *)v1 + 89) * *((float *)v1 + 93))))
                             + (float)(*((float *)v1 + 90)
                                     * (float)((float)(*((float *)v1 + 94) * *((float *)v1 + 89))
                                             - (float)(*((float *)v1 + 95) * *((float *)v1 + 88)))))
                     + (float)(*((float *)v1 + 92)
                             * (float)((float)(*((float *)v1 + 88) * *((float *)v1 + 93))
                                     - (float)(*((float *)v1 + 87) * *((float *)v1 + 94))))) < 0.0 )
            v3->vecUVPoints[3].z = 1.0;
          searchTexInfo.flags = 0;
          v11 = v1 + 6;
          searchTexInfo.texdata = FindOrCreateTexData(pName_: v1 + 6);
          v4 = &searchTexInfo.lightmapVecsLuxelsPerWorldUnits[0][3];
          for ( i = 2; i != 0; --i )
          {
            v6 = v4 - 11;
            for ( j = 3; j != 0; --j )
            {
              v6[8] = 0.0;
              *v6++ = 0.0;
            }
            *v4 = -99999.0;
            *(v4 - 8) = -99999.0;
            v4 += 4;
          }
          v3->nTexInfo = FindOrCreateTexInfo(&searchTexInfo);
          v8 = *((_DWORD *)v1 + 104);
          if ( v8 < 256 )
          {
            v3->m_nFaceCountAndRenderOrder ^= (v8 ^ v3->m_nFaceCountAndRenderOrder) & 0x3FFF;
            for ( k = 0; k < v8; ++k )
              v3->aFaces[k] = *(_DWORD *)(*((_DWORD *)v1 + 101) + 4 * k);
          }
          else
          {
            _Error(
              a1: "Water Overlay touching too many faces (touching %d, max %d)\nOverlay %s at %.1f %.1f %.1f",
              v8,
              64,
              v11,
              *((float *)v1 + 84),
              *((float *)v1 + 85),
              *((float *)v1 + 86));
          }
        }
      }
      else
      {
        _Error(a1: "Too many water overlays!\nMAX_MAP_WATEROVERLAYS = %d", 0x4000);
      }
      v0 = v13 + 424;
      v2 = m_Size-- == 1;
      v13 += 424;
    }
    while ( !v2 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004292F0
// Name: void Overlay_UpdateSideLists(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Overlay_UpdateSideLists()
{
  int v0; // ebx
  S3RGBA *v1; // ebx
  int v2; // ecx
  int v3; // eax
  int v4; // edx
  int *p_id; // ecx
  side_t *v6; // eax
  int v7; // edx
  CUtlMemory<S3RGBA,int> *p_aOverlayIds; // esi
  int v9; // eax
  S3RGBA *m_pMemory; // ecx
  int m_nAllocationCount; // eax
  int v12; // edi
  S3RGBA *v13; // ecx
  int v14; // eax
  S3RGBA *v15; // eax
  bool v16; // zf
  int nSideCount; // [esp+0h] [ebp-10h]
  int m_Size; // [esp+4h] [ebp-Ch]
  int v19; // [esp+8h] [ebp-8h]
  int iSide; // [esp+Ch] [ebp-4h]

  if ( g_aMapOverlays.m_Size > 0 )
  {
    v0 = 0;
    v19 = 0;
    m_Size = g_aMapOverlays.m_Size;
    do
    {
      v1 = (S3RGBA *)((char *)g_aMapOverlays.m_Memory.m_pMemory + v0);
      if ( v1 != nullptr )
      {
        v2 = 0;
        nSideCount = (int)v1[99];
        iSide = 0;
        if ( nSideCount > 0 )
        {
          do
          {
            v3 = 0;
            if ( nummapbrushsides > 0 )
            {
              v4 = *(_DWORD *)(*(_DWORD *)&v1[96] + 4 * v2);
              p_id = &brushsides[0].id;
              while ( *p_id != v4 )
              {
                ++v3;
                p_id += 25;
                if ( v3 >= nummapbrushsides )
                  goto LABEL_23;
              }
              v6 = &brushsides[v3];
              if ( v6 != nullptr )
              {
                v7 = v6->aOverlayIds.m_Size;
                p_aOverlayIds = (CUtlMemory<S3RGBA,int> *)&v6->aOverlayIds;
                v9 = 0;
                if ( v7 <= 0 )
                  goto LABEL_17;
                m_pMemory = p_aOverlayIds->m_pMemory;
                while ( *m_pMemory != *v1 )
                {
                  ++v9;
                  ++m_pMemory;
                  if ( v9 >= v7 )
                    goto LABEL_17;
                }
                if ( v9 == -1 )
                {
LABEL_17:
                  m_nAllocationCount = p_aOverlayIds->m_nAllocationCount;
                  v12 = v7;
                  if ( v7 + 1 > m_nAllocationCount )
                    CUtlMemory<HemiLightData_t *,int>::Grow(this: p_aOverlayIds, num: v7 - m_nAllocationCount + 1);
                  ++p_aOverlayIds[1].m_pMemory;
                  v13 = p_aOverlayIds->m_pMemory;
                  v14 = (int)p_aOverlayIds[1].m_pMemory - v12 - 1;
                  p_aOverlayIds[1].m_nAllocationCount = (int)p_aOverlayIds->m_pMemory;
                  if ( v14 > 0 )
                    _V_memmove(dest: &v13[v12 + 1], src: &v13[v12], count: 4 * v14);
                  v15 = &p_aOverlayIds->m_pMemory[v12];
                  if ( v15 != nullptr )
                    *v15 = *v1;
                }
              }
            }
LABEL_23:
            v2 = iSide + 1;
            iSide = v2;
          }
          while ( v2 < nSideCount );
        }
      }
      v0 = v19 + 424;
      v16 = m_Size-- == 1;
      v19 += 424;
    }
    while ( !v16 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00429410
// Name: void OverlayTransition_UpdateSideLists(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OverlayTransition_UpdateSideLists()
{
  int v0; // ebx
  S3RGBA *v1; // ebx
  int v2; // ecx
  int v3; // eax
  int v4; // edx
  int *p_id; // ecx
  side_t *v6; // eax
  int v7; // edx
  CUtlMemory<S3RGBA,int> *p_aWaterOverlayIds; // esi
  int v9; // eax
  S3RGBA *m_pMemory; // ecx
  int m_nAllocationCount; // eax
  int v12; // edi
  S3RGBA *v13; // ecx
  int v14; // eax
  S3RGBA *v15; // eax
  bool v16; // zf
  int nSideCount; // [esp+0h] [ebp-10h]
  int m_Size; // [esp+4h] [ebp-Ch]
  int v19; // [esp+8h] [ebp-8h]
  int iSide; // [esp+Ch] [ebp-4h]

  if ( g_aMapWaterOverlays.m_Size > 0 )
  {
    v0 = 0;
    v19 = 0;
    m_Size = g_aMapWaterOverlays.m_Size;
    do
    {
      v1 = (S3RGBA *)((char *)g_aMapWaterOverlays.m_Memory.m_pMemory + v0);
      if ( v1 != nullptr )
      {
        v2 = 0;
        nSideCount = (int)v1[99];
        iSide = 0;
        if ( nSideCount > 0 )
        {
          do
          {
            v3 = 0;
            if ( nummapbrushsides > 0 )
            {
              v4 = *(_DWORD *)(*(_DWORD *)&v1[96] + 4 * v2);
              p_id = &brushsides[0].id;
              while ( *p_id != v4 )
              {
                ++v3;
                p_id += 25;
                if ( v3 >= nummapbrushsides )
                  goto LABEL_23;
              }
              v6 = &brushsides[v3];
              if ( v6 != nullptr )
              {
                v7 = v6->aWaterOverlayIds.m_Size;
                p_aWaterOverlayIds = (CUtlMemory<S3RGBA,int> *)&v6->aWaterOverlayIds;
                v9 = 0;
                if ( v7 <= 0 )
                  goto LABEL_17;
                m_pMemory = p_aWaterOverlayIds->m_pMemory;
                while ( *m_pMemory != *v1 )
                {
                  ++v9;
                  ++m_pMemory;
                  if ( v9 >= v7 )
                    goto LABEL_17;
                }
                if ( v9 == -1 )
                {
LABEL_17:
                  m_nAllocationCount = p_aWaterOverlayIds->m_nAllocationCount;
                  v12 = v7;
                  if ( v7 + 1 > m_nAllocationCount )
                    CUtlMemory<HemiLightData_t *,int>::Grow(this: p_aWaterOverlayIds, num: v7 - m_nAllocationCount + 1);
                  ++p_aWaterOverlayIds[1].m_pMemory;
                  v13 = p_aWaterOverlayIds->m_pMemory;
                  v14 = (int)p_aWaterOverlayIds[1].m_pMemory - v12 - 1;
                  p_aWaterOverlayIds[1].m_nAllocationCount = (int)p_aWaterOverlayIds->m_pMemory;
                  if ( v14 > 0 )
                    _V_memmove(dest: &v13[v12 + 1], src: &v13[v12], count: 4 * v14);
                  v15 = &p_aWaterOverlayIds->m_pMemory[v12];
                  if ( v15 != nullptr )
                    *v15 = *v1;
                }
              }
            }
LABEL_23:
            v2 = iSide + 1;
            iSide = v2;
          }
          while ( v2 < nSideCount );
        }
      }
      v0 = v19 + 424;
      v16 = m_Size-- == 1;
      v19 += 424;
    }
    while ( !v16 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00429530
// Name: void Overlay_AddFaceToLists(int,struct side_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Overlay_AddFaceToLists(int iFace, side_t *pSide)
{
  int v2; // eax
  mapoverlay_t *v3; // eax
  int m_Size; // ecx
  CUtlMemory<S3RGBA,int> *p_aFaceList; // esi
  int v6; // eax
  S3RGBA *m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v9; // edi
  S3RGBA *v10; // ecx
  int v11; // eax
  S3RGBA *v12; // eax
  int nOverlayIdCount; // [esp+0h] [ebp-8h]
  int iOverlayId; // [esp+4h] [ebp-4h]

  v2 = 0;
  nOverlayIdCount = pSide->aOverlayIds.m_Size;
  iOverlayId = 0;
  if ( nOverlayIdCount > 0 )
  {
    do
    {
      v3 = &g_aMapOverlays.m_Memory.m_pMemory[pSide->aOverlayIds.m_Memory.m_pMemory[v2]];
      if ( v3 != nullptr )
      {
        m_Size = v3->aFaceList.m_Size;
        p_aFaceList = (CUtlMemory<S3RGBA,int> *)&v3->aFaceList;
        v6 = 0;
        if ( m_Size <= 0 )
          goto LABEL_9;
        m_pMemory = p_aFaceList->m_pMemory;
        while ( *m_pMemory != iFace )
        {
          ++v6;
          ++m_pMemory;
          if ( v6 >= m_Size )
            goto LABEL_9;
        }
        if ( v6 == -1 )
        {
LABEL_9:
          m_nAllocationCount = p_aFaceList->m_nAllocationCount;
          v9 = m_Size;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<HemiLightData_t *,int>::Grow(this: p_aFaceList, num: m_Size - m_nAllocationCount + 1);
          ++p_aFaceList[1].m_pMemory;
          v10 = p_aFaceList->m_pMemory;
          v11 = (int)p_aFaceList[1].m_pMemory - v9 - 1;
          p_aFaceList[1].m_nAllocationCount = (int)p_aFaceList->m_pMemory;
          if ( v11 > 0 )
            _V_memmove(dest: &v10[v9 + 1], src: &v10[v9], count: 4 * v11);
          v12 = &p_aFaceList->m_pMemory[v9];
          if ( v12 != nullptr )
            *v12 = (S3RGBA)iFace;
        }
      }
      v2 = iOverlayId + 1;
      iOverlayId = v2;
    }
    while ( v2 < nOverlayIdCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00429600
// Name: void OverlayTransition_AddFaceToLists(int,struct side_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OverlayTransition_AddFaceToLists(int iFace, side_t *pSide)
{
  int v2; // ebx
  mapoverlay_t *v3; // eax
  int m_Size; // ecx
  CUtlMemory<S3RGBA,int> *p_aFaceList; // esi
  int v6; // eax
  S3RGBA *m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v9; // edi
  S3RGBA *v10; // ecx
  int v11; // eax
  S3RGBA *v12; // eax
  int nOverlayIdCount; // [esp+4h] [ebp-4h]

  v2 = 0;
  nOverlayIdCount = pSide->aWaterOverlayIds.m_Size;
  if ( nOverlayIdCount > 0 )
  {
    do
    {
      v3 = &g_aMapWaterOverlays.m_Memory.m_pMemory[pSide->aWaterOverlayIds.m_Memory.m_pMemory[v2] - 513];
      if ( v3 != nullptr )
      {
        m_Size = v3->aFaceList.m_Size;
        p_aFaceList = (CUtlMemory<S3RGBA,int> *)&v3->aFaceList;
        v6 = 0;
        if ( m_Size <= 0 )
          goto LABEL_9;
        m_pMemory = p_aFaceList->m_pMemory;
        while ( *m_pMemory != iFace )
        {
          ++v6;
          ++m_pMemory;
          if ( v6 >= m_Size )
            goto LABEL_9;
        }
        if ( v6 == -1 )
        {
LABEL_9:
          m_nAllocationCount = p_aFaceList->m_nAllocationCount;
          v9 = m_Size;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<HemiLightData_t *,int>::Grow(this: p_aFaceList, num: m_Size - m_nAllocationCount + 1);
          ++p_aFaceList[1].m_pMemory;
          v10 = p_aFaceList->m_pMemory;
          v11 = (int)p_aFaceList[1].m_pMemory - v9 - 1;
          p_aFaceList[1].m_nAllocationCount = (int)p_aFaceList->m_pMemory;
          if ( v11 > 0 )
            _V_memmove(dest: &v10[v9 + 1], src: &v10[v9], count: 4 * v11);
          v12 = &p_aFaceList->m_pMemory[v9];
          if ( v12 != nullptr )
            *v12 = (S3RGBA)iFace;
        }
      }
      ++v2;
    }
    while ( v2 < nOverlayIdCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00429800
// Name: int Overlay_GetFromEntity(struct entity_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Overlay_GetFromEntity(entity_t *pMapEnt)
{
  mapoverlay_t *v1; // edi
  double v2; // st7
  double v3; // st7
  unsigned __int16 v4; // ax
  const char *v5; // eax
  char *v6; // eax
  int v8; // edx
  char v9; // cl
  const char *v10; // esi
  void *v11; // esp
  const char *v12; // ebx
  CUtlMemory<S3RGBA,int> *p_aSideList; // esi
  S3RGBA *m_pMemory; // edi
  int m_nAllocationCount; // eax
  S3RGBA *v16; // ecx
  int v17; // eax
  float *v18; // edi
  double v19; // [esp-Ch] [ebp-20h]
  double v20[2]; // [esp-4h] [ebp-18h] BYREF
  int nSideId; // [esp+Ch] [ebp-8h] BYREF
  int iAccessorID; // [esp+10h] [ebp-4h]

  iAccessorID = -1;
  v1 = &g_aMapOverlays.m_Memory.m_pMemory[CUtlVector<mapoverlay_t,CUtlMemory<mapoverlay_t,int>>::InsertBefore(
                                            this: &g_aMapOverlays,
                                            elem: g_aMapOverlays.m_Size)];
  v1->nId = g_aMapOverlays.m_Size - 1;
  if ( *ValueForKey(ent: pMapEnt, key: "targetname") != 0 )
    iAccessorID = v1->nId;
  v1->flU[0] = FloatForKey(ent: pMapEnt, key: "StartU");
  v1->flU[1] = FloatForKey(ent: pMapEnt, key: "EndU");
  v1->flV[0] = FloatForKey(ent: pMapEnt, key: "StartV");
  v1->flV[1] = FloatForKey(ent: pMapEnt, key: "EndV");
  v2 = FloatForKey(ent: pMapEnt, key: "fademindist");
  *(float *)&nSideId = v2;
  v1->flFadeDistMinSq = v2;
  if ( v2 > 0.0 )
    v1->flFadeDistMinSq = *(float *)&nSideId * *(float *)&nSideId;
  v3 = FloatForKey(ent: pMapEnt, key: "fademaxdist");
  *(float *)&nSideId = v3;
  v1->flFadeDistMaxSq = v3;
  if ( v3 > 0.0 )
    v1->flFadeDistMaxSq = *(float *)&nSideId * *(float *)&nSideId;
  GetVectorForKey(ent: pMapEnt, key: "BasisOrigin", angle: (QAngle *)&v1->vecOrigin);
  v4 = IntForKey(ent: pMapEnt, key: "RenderOrder");
  v1->m_nRenderOrder = v4;
  if ( v4 >= 4u )
  {
    v19 = *(double *)&v1->vecOrigin.x;
    *(float *)v20 = v1->vecOrigin.z;
    v5 = ValueForKey(ent: pMapEnt, key: "material");
    _Error(a1: "Overlay (%s) at %f %f %f has invalid render order (%d).\n", v5, v19, v20[0], v20[1], nSideId);
  }
  GetVectorForKey(ent: pMapEnt, key: "uv0", angle: (QAngle *)v1->vecUVPoints);
  GetVectorForKey(ent: pMapEnt, key: "uv1", angle: (QAngle *)&v1->vecUVPoints[1]);
  GetVectorForKey(ent: pMapEnt, key: "uv2", angle: (QAngle *)&v1->vecUVPoints[2]);
  GetVectorForKey(ent: pMapEnt, key: "uv3", angle: (QAngle *)&v1->vecUVPoints[3]);
  GetVectorForKey(ent: pMapEnt, key: "BasisU", angle: (QAngle *)v1->vecBasis);
  GetVectorForKey(ent: pMapEnt, key: "BasisV", angle: (QAngle *)&v1->vecBasis[1]);
  GetVectorForKey(ent: pMapEnt, key: "BasisNormal", angle: (QAngle *)&v1->vecBasis[2]);
  v6 = ValueForKey(ent: pMapEnt, key: "material");
  if ( strlen(v6) < 0x100 )
  {
    v8 = (char *)v1 - v6;
    do
    {
      v9 = *v6;
      v6[v8 + 6] = *v6;
      ++v6;
    }
    while ( v9 != 0 );
    v10 = ValueForKey(ent: pMapEnt, key: "sides");
    v11 = alloca(strlen(v10) + 1);
    strcpy((char *)v20 + 4, v10);
    v12 = strtok(string: (char *)v20 + 4, control: " ");
    if ( v12 != nullptr )
    {
      p_aSideList = (CUtlMemory<S3RGBA,int> *)&v1->aSideList;
      CUtlVector<int,CUtlMemory<int,int>>::Purge(this: &v1->aSideList);
      CUtlVector<int,CUtlMemory<int,int>>::Purge(this: &v1->aFaceList);
      do
      {
        if ( sscanf(string: v12, format: "%d", &nSideId) == 1 )
        {
          m_pMemory = p_aSideList[1].m_pMemory;
          m_nAllocationCount = p_aSideList->m_nAllocationCount;
          if ( (int)&m_pMemory->g > m_nAllocationCount )
            CUtlMemory<HemiLightData_t *,int>::Grow(this: p_aSideList, num: (int)(&m_pMemory->g - m_nAllocationCount));
          ++p_aSideList[1].m_pMemory;
          v16 = p_aSideList->m_pMemory;
          v17 = (char *)p_aSideList[1].m_pMemory - (char *)m_pMemory - 1;
          p_aSideList[1].m_nAllocationCount = (int)p_aSideList->m_pMemory;
          if ( v17 > 0 )
            _V_memmove(dest: &v16[(_DWORD)m_pMemory + 1], src: &v16[(_DWORD)m_pMemory], count: 4 * v17);
          v18 = (float *)&p_aSideList->m_pMemory[(_DWORD)m_pMemory];
          if ( v18 != nullptr )
            *v18 = *(float *)&nSideId;
        }
        v12 = strtok(string: nullptr, control: " ");
      }
      while ( v12 != nullptr );
    }
    return iAccessorID;
  }
  else
  {
    _Error(a1: "Overlay Material Name (%s) too long! > OVERLAY_MAP_STRLEN (%d)", v6, 256);
    return -1;
  }
}
