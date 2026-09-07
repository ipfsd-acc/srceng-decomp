// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/r_decal.cpp
// Functions: 57
// ============================================================

#include "engine\r_decal.h"

//------------------------------------------------------------------------------
// Address: 0x100FEAF0
// Name: bool DecalSortTreeSortLessFunc(struct DecalMaterialSortData_t const __near &,struct DecalMaterialSortData_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl DecalSortTreeSortLessFunc(const DecalMaterialSortData_t *decal1, const DecalMaterialSortData_t *decal2)
{
  int m_iLightmapPage; // edx
  int v3; // esi

  m_iLightmapPage = decal1->m_iLightmapPage;
  if ( m_iLightmapPage == -1 )
    return (int)decal1->m_pMaterial < (int)decal2->m_pMaterial;
  v3 = decal2->m_iLightmapPage;
  if ( v3 == -1 )
    return (int)decal1->m_pMaterial < (int)decal2->m_pMaterial;
  if ( decal1->m_pMaterial == decal2->m_pMaterial )
    return m_iLightmapPage < v3;
  return (int)decal1->m_pMaterial < (int)decal2->m_pMaterial;
}

//------------------------------------------------------------------------------
// Address: 0x100FEB40
// Name: private: int CDecalVertCache::AllocBlocks(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDecalVertCache::AllocBlocks(CDecalVertCache *this, int blockCount)
{
  int m_freeBlockCount; // eax
  int result; // eax
  int m_decalIndex; // edx
  int v6; // esi
  int v7; // eax
  int m_firstFree; // edx
  int v9; // edi
  int firstBlock; // [esp+Ch] [ebp+8h]

  m_freeBlockCount = this->m_freeBlockCount;
  if ( blockCount > m_freeBlockCount )
    return 0xFFFF;
  if ( m_freeBlockCount != 0 )
  {
    result = this->m_firstFree;
    m_decalIndex = this->m_cache[result].decalVert[1].m_decalIndex;
    this->m_cache[result].decalVert[2].m_decalIndex = 0;
    --this->m_freeBlockCount;
    this->m_firstFree = m_decalIndex;
  }
  else
  {
    result = 0xFFFF;
  }
  firstBlock = result;
  v6 = result;
  if ( blockCount > 1 )
  {
    v7 = blockCount - 1;
    do
    {
      if ( this->m_freeBlockCount != 0 )
      {
        m_firstFree = this->m_firstFree;
        v9 = this->m_cache[m_firstFree].decalVert[1].m_decalIndex;
        this->m_cache[m_firstFree].decalVert[2].m_decalIndex = 0;
        --this->m_freeBlockCount;
        this->m_firstFree = v9;
      }
      else
      {
        m_firstFree = 0xFFFF;
      }
      --v7;
      this->m_cache[v6].decalVert[1].m_decalIndex = m_firstFree;
      v6 = m_firstFree;
    }
    while ( v7 != 0 );
    result = firstBlock;
  }
  this->m_cache[v6].decalVert[1].m_decalIndex = 0xFFFF;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FEC00
// Name: DecalListAdd
// Source: json
//------------------------------------------------------------------------------
int __usercall DecalListAdd@<eax>(decallist_t *pList@<eax>, int a2)
{
  int v3; // eax
  decallist_t *v4; // esi
  __int16 *i; // edi
  int v7; // [esp-4h] [ebp-10h]

  v3 = a2;
  v4 = &pList[a2];
  v7 = 0;
  if ( a2 <= 0 )
    return v3 + 1;
  for ( i = &pList->entityIndex;
        _V_strcmp(s1: v4->name, s2: (const char *)i - 128) != 0
     || v4->entityIndex != *i
     || fsqrt(
          (float)((float)((float)(v4->position.y - *((float *)i - 34)) * (float)(v4->position.y - *((float *)i - 34)))
                + (float)((float)(v4->position.z - *((float *)i - 33)) * (float)(v4->position.z - *((float *)i - 33))))
        + (float)((float)(v4->position.x - *((float *)i - 35)) * (float)(v4->position.x - *((float *)i - 35)))) >= 2.0;
        i += 78 )
  {
    if ( ++v7 >= a2 )
    {
      v3 = a2;
      return v3 + 1;
    }
  }
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x100FECF0
// Name: DecalDepthCompare
// Source: json
//------------------------------------------------------------------------------
int __cdecl DecalDepthCompare(const decallist_t *elem1, const decallist_t *elem2)
{
  unsigned __int8 depth; // al
  unsigned __int8 v3; // cl

  depth = elem1->depth;
  v3 = elem2->depth;
  if ( depth <= v3 )
    return depth < v3;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100FED20
// Name: R_DecalVertsLight
// Source: json
//------------------------------------------------------------------------------
void __usercall R_DecalVertsLight(CDecalVert *v@<ecx>, const decalcontext_t *context@<eax>, int surfID)
{
  int v3; // edi
  unsigned int v4; // edx
  float y; // xmm0_4
  float z; // xmm1_4
  float x; // xmm4_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm4_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float *p_y; // ecx
  char *v19; // esi
  float v20; // xmm0_4
  float v21; // xmm1_4

  v3 = 0;
  if ( surfID >= 4 )
  {
    v4 = ((unsigned int)(surfID - 4) >> 2) + 1;
    v3 = 4 * v4;
    do
    {
      y = v->m_vPos.y;
      z = v->m_vPos.z;
      v->m_cLMCoords.x = (float)((float)((float)((float)(y * context->sAxis.y) + (float)(v->m_vPos.x * context->sAxis.x))
                                       + (float)(z * context->sAxis.z))
                               + context->sOffset)
                       * context->sScale;
      x = v[1].m_vPos.x;
      v->m_cLMCoords.y = (float)((float)((float)((float)(y * context->tAxis.y) + (float)(context->tAxis.x * v->m_vPos.x))
                                       + (float)(z * context->tAxis.z))
                               + context->tOffset)
                       * context->tScale;
      v8 = v[1].m_vPos.y;
      v9 = v[1].m_vPos.z;
      v[1].m_cLMCoords.x = (float)((float)((float)((float)(v8 * context->sAxis.y) + (float)(x * context->sAxis.x))
                                         + (float)(v9 * context->sAxis.z))
                                 + context->sOffset)
                         * context->sScale;
      v10 = v[2].m_vPos.x;
      v11 = (float)((float)((float)((float)(v8 * context->tAxis.y) + (float)(context->tAxis.x * v[1].m_vPos.x))
                          + (float)(v9 * context->tAxis.z))
                  + context->tOffset)
          * context->tScale;
      v12 = v[2].m_vPos.z;
      v[1].m_cLMCoords.y = v11;
      v13 = v[2].m_vPos.y;
      v14 = v[3].m_vPos.z;
      v[2].m_cLMCoords.x = (float)((float)((float)((float)(v13 * context->sAxis.y) + (float)(v10 * context->sAxis.x))
                                         + (float)(v12 * context->sAxis.z))
                                 + context->sOffset)
                         * context->sScale;
      v15 = (float)((float)((float)((float)(v13 * context->tAxis.y) + (float)(context->tAxis.x * v[2].m_vPos.x))
                          + (float)(v12 * context->tAxis.z))
                  + context->tOffset)
          * context->tScale;
      v16 = v[3].m_vPos.x;
      v[2].m_cLMCoords.y = v15;
      v17 = v[3].m_vPos.y;
      v[3].m_cLMCoords.x = (float)((float)((float)((float)(v17 * context->sAxis.y) + (float)(v16 * context->sAxis.x))
                                         + (float)(v14 * context->sAxis.z))
                                 + context->sOffset)
                         * context->sScale;
      v[3].m_cLMCoords.y = (float)((float)((float)((float)(v17 * context->tAxis.y) + (float)(v16 * context->tAxis.x))
                                         + (float)(v14 * context->tAxis.z))
                                 + context->tOffset)
                         * context->tScale;
      v += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
  if ( v3 < surfID )
  {
    p_y = &v->m_vPos.y;
    v19 = (char *)(surfID - v3);
    do
    {
      v20 = *p_y;
      v21 = p_y[1];
      p_y[5] = (float)((float)((float)((float)(*p_y * context->sAxis.y) + (float)(*(p_y - 1) * context->sAxis.x))
                             + (float)(v21 * context->sAxis.z))
                     + context->sOffset)
             * context->sScale;
      p_y[6] = (float)((float)((float)((float)(v20 * context->tAxis.y) + (float)(context->tAxis.x * *(p_y - 1)))
                             + (float)(v21 * context->tAxis.z))
                     + context->tOffset)
             * context->tScale;
      p_y += 8;
      --v19;
    }
    while ( v19 != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FF0A0
// Name: public: void CDecalVertCache::FreeCachedVerts(struct decal_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDecalVertCache::FreeCachedVerts(CDecalVertCache *this, decal_t *pDecal)
{
  decal_t *v2; // eax
  int cacheHandle; // edx
  int m_decalIndex; // esi
  decalcache_t *v5; // eax

  v2 = pDecal;
  cacheHandle = pDecal->cacheHandle;
  if ( cacheHandle != 0xFFFF )
  {
    do
    {
      m_decalIndex = this->m_cache[cacheHandle].decalVert[1].m_decalIndex;
      v5 = &this->m_cache[cacheHandle];
      v5->decalVert[2].m_decalIndex = 1;
      v5->decalVert[1].m_decalIndex = this->m_firstFree;
      v5->decalVert[0].m_decalIndex = -1;
      ++this->m_freeBlockCount;
      this->m_firstFree = cacheHandle;
      cacheHandle = m_decalIndex;
    }
    while ( m_decalIndex != 0xFFFF );
    v2 = pDecal;
  }
  *(_DWORD *)&v2->clippedVertCount = -65536;
}

//------------------------------------------------------------------------------
// Address: 0x100FF110
// Name: public: class CDecalVert __near * CDecalVertCache::GetCachedVerts(struct decal_t __near *)
// Source: json
//------------------------------------------------------------------------------
decalcache_t *__thiscall CDecalVertCache::GetCachedVerts(CDecalVertCache *this, decal_t *pDecal)
{
  int cacheHandle; // ecx
  decalcache_t *result; // eax
  unsigned int v5; // edx
  decal_t *v6; // edi
  int m_decalIndex; // eax
  decal_t *pDecala; // [esp+Ch] [ebp+8h]

  cacheHandle = pDecal->cacheHandle;
  if ( r_framecount != this->m_lastFrameCount )
  {
    this->m_frameBlocks = 0;
    this->m_lastFrameCount = r_framecount;
  }
  if ( cacheHandle == 0xFFFF )
    return nullptr;
  result = &this->m_cache[cacheHandle];
  do
  {
    result->decalVert[3].m_decalIndex = r_framecount;
    cacheHandle = this->m_cache[cacheHandle].decalVert[1].m_decalIndex;
  }
  while ( cacheHandle != 0xFFFF );
  v5 = (pDecal->clippedVertCount + 3) >> 2;
  this->m_frameBlocks += v5;
  if ( v5 > 1 )
  {
    pDecala = (decal_t *)g_DecalClipVerts;
    do
    {
      v6 = pDecala;
      pDecala = (decal_t *)((char *)pDecala + 128);
      qmemcpy(v6, result, 0x80u);
      m_decalIndex = result->decalVert[1].m_decalIndex;
      --v5;
      if ( m_decalIndex == 0xFFFF )
        result = nullptr;
      else
        result = &this->m_cache[m_decalIndex];
    }
    while ( v5 != 0 );
    return (decalcache_t *)g_DecalClipVerts;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FF1E0
// Name: float ComputeDecalLightmapOffset(struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl ComputeDecalLightmapOffset(int surfID)
{
  int v1; // esi
  IMaterialSystem_vtbl *v2; // edi
  int v3; // eax
  int nHeight; // [esp+4h] [ebp-4h] BYREF

  v1 = surfID;
  if ( (*(_BYTE *)surfID & 8) == 0 )
    return 0.0;
  v2 = materials->__vftable;
  v3 = SortInfoToLightmapPage(sortID: *(__int16 *)(surfID + 18));
  v2->GetLightmapPageSize(this: materials, a2: v3, a3: &surfID, a4: &nHeight);
  if ( *(float *)&surfID == 0.0 )
    return 0.0;
  *(float *)&surfID = (float)(*(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapExtents
                                         + ((v1 - (unsigned int)host_state.worldbrush->surfaces2) & 0xFFFFFFE0))
                            + 1)
                    / (float)surfID;
  return *(float *)&surfID;
}

//------------------------------------------------------------------------------
// Address: 0x100FF270
// Name: void R_DecalGetMaterialAndSize(int,class IMaterial __near * __near &,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DecalGetMaterialAndSize(int decalIndex, IMaterial **pDecalMaterial, float *w, float *h)
{
  IMaterial *v4; // eax
  int v6; // eax
  IMaterialVar *v7; // eax
  IUniformRandomStream *v8; // ecx
  double v9; // st7
  float v10; // xmm0_4
  float v11; // [esp+1Ch] [ebp-4h]
  float v12; // [esp+2Ch] [ebp+Ch]

  v4 = Draw_DecalMaterial(index: decalIndex);
  *pDecalMaterial = v4;
  if ( v4 != nullptr )
  {
    v12 = 1.0;
    v6 = (int)v4->FindVarFast(this: v4, a2: "$decalScale", a3: &s_DecalScaleVarCache);
    if ( v6 != 0 )
      v12 = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v6 + 112))(a1: v6);
    v7 = (*pDecalMaterial)->FindVarFast(
           this: *pDecalMaterial,
           a2: "$decalScaleVariation",
           a3: &s_DecalScaleVariationVarCache);
    if ( v7 != nullptr )
    {
      v9 = ((double (__thiscall *)(IMaterialVar *))v7->GetFloatValueInternal)(a1: v7);
      if ( v9 >= 0.0 )
      {
        v10 = v9;
        v11 = v9;
        if ( v11 > 0.99000001 )
          v10 = 0.99000001;
      }
      else
      {
        v10 = 0.0;
      }
      v12 = (_RandomFloat(this: v8, a2: COERCE_FLOAT(LODWORD(v10) ^ _mask__NegFloat_), a3: v10) + 1.0) * v12;
    }
    *w = (float)(*pDecalMaterial)->GetMappingWidth(this: *pDecalMaterial) * v12;
    *h = (float)(*pDecalMaterial)->GetMappingHeight(this: *pDecalMaterial) * v12;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FF380
// Name: R_DecalUnProject
// Source: json
//------------------------------------------------------------------------------
char __usercall R_DecalUnProject@<al>(decal_t *pdecal@<ecx>, decallist_t *entry@<eax>)
{
  cplane_t *plane; // ecx
  float plane_4; // [esp+4h] [ebp-10h]
  float plane_8; // [esp+8h] [ebp-Ch]

  if ( pdecal == nullptr || pdecal->surfID == nullptr )
    return 0;
  entry->position = pdecal->position;
  entry->entityIndex = pdecal->entityIndex;
  plane = pdecal->surfID->plane;
  plane_4 = plane->normal.y;
  plane_8 = plane->normal.z;
  entry->impactPlaneNormal.x = plane->normal.x;
  entry->impactPlaneNormal.y = plane_4;
  entry->impactPlaneNormal.z = plane_8;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100FF410
// Name: public: void decalcontext_t::InitSurface(struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall decalcontext_t::InitSurface(decalcontext_t *this, msurface2_t *surfID)
{
  float *v4; // esi
  int v5; // eax
  __m128i v6; // xmm1
  __int16 *v7; // ebx
  int lightmapPageHeight; // [esp+8h] [ebp-8h] BYREF
  int lightmapPageWidth; // [esp+Ch] [ebp-4h] BYREF
  msurface2_t *surfIDa; // [esp+18h] [ebp+8h]

  if ( this->pSurf != surfID )
  {
    this->pSurf = surfID;
    v4 = (float *)&host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1];
    surfIDa = (msurface2_t *)materials->__vftable;
    v5 = SortInfoToLightmapPage(sortID: surfID->materialSortID);
    ((void (__thiscall *)(IMaterialSystem *, int, int *, int *))surfIDa[13].flags)(
      a1: materials,
      a2: v5,
      a3: &lightmapPageWidth,
      a4: &lightmapPageHeight);
    v6 = _mm_cvtsi32_si128(lightmapPageHeight);
    this->sScale = 1.0 / (float)lightmapPageWidth;
    this->tScale = 1.0 / _mm_cvtepi32_ps(v6).m128_f32[0];
    v7 = (__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapMins
                   + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
    this->sOffset = (float)((float)(v4[11] - (float)*v7) + (float)v7[4]) + 0.5;
    this->tOffset = (float)((float)(v4[15] - (float)v7[1]) + (float)v7[5]) + 0.5;
    this->sAxis.x = v4[8];
    this->sAxis.y = v4[9];
    this->sAxis.z = v4[10];
    this->tAxis.x = v4[12];
    this->tAxis.y = v4[13];
    this->tAxis.z = v4[14];
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FF600
// Name: r_printdecalinfo_f
// Source: json
//------------------------------------------------------------------------------
void __cdecl r_printdecalinfo_f()
{
  int v0; // esi
  int v1; // edx
  int i; // eax
  int m_nValue; // eax

  v0 = 0;
  v1 = 0;
  for ( i = 0; i < g_nMaxDecals; ++i )
  {
    if ( s_aDecalPool.m_Memory.m_pMemory[i] != nullptr )
    {
      if ( (s_aDecalPool.m_Memory.m_pMemory[i]->flags & 1) != 0 )
        ++v0;
      else
        ++v1;
    }
  }
  if ( r_decals.m_pParent != nullptr )
    m_nValue = r_decals.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  _Msg(a1: "%d decals: %d permanent, %d dynamic\nr_decals: %d\n", v0 + v1, v0, v1, m_nValue);
}

//------------------------------------------------------------------------------
// Address: 0x100FF660
// Name: private: void CDecalVertCache::FindFreeBlocks(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDecalVertCache::FindFreeBlocks(CDecalVertCache *this, int blockCount)
{
  int m_freeTestIndex; // eax
  int v3; // esi
  int v4; // eax
  int v5; // edx

  if ( blockCount > this->m_freeBlockCount && blockCount <= 1024 - this->m_frameBlocks )
  {
    m_freeTestIndex = this->m_freeTestIndex;
    v3 = ((_WORD)m_freeTestIndex + 16) & 0x3FF;
    if ( m_freeTestIndex != v3 )
    {
      do
      {
        v4 = this->m_freeTestIndex << 7;
        if ( *(int *)((char *)&this->m_cache[0].decalVert[2].m_decalIndex + v4) == 0
          && r_framecount - *(int *)((char *)&this->m_cache[0].decalVert[3].m_decalIndex + v4) > 1 )
        {
          CDecalVertCache::FreeCachedVerts(
            this,
            pDecal: s_aDecalPool.m_Memory.m_pMemory[*(int *)((char *)&this->m_cache[0].decalVert[0].m_decalIndex + v4)]);
        }
        if ( this->m_freeBlockCount >= blockCount )
          break;
        v5 = ((unsigned __int16)this->m_freeTestIndex + 1) & 0x3FF;
        this->m_freeTestIndex = v5;
      }
      while ( v5 != v3 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FF6F0
// Name: void R_DecalUnlink(struct decal_t __near *,struct worldbrushdata_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DecalUnlink(decal_t *pdecal)
{
  msurface2_t *surfID; // edx
  int decals; // ecx
  decal_t *v3; // eax
  decal_t *v4; // esi
  decal_t *pnext; // eax
  msurface2_t *v6; // eax
  IDispInfo *pDispInfo; // ecx
  bool v8; // zf

  if ( pdecal == nullptr )
    return;
  CDecalVertCache::FreeCachedVerts(this: &g_DecalVertCache, pDecal: pdecal);
  surfID = pdecal->surfID;
  if ( surfID != nullptr )
  {
    decals = surfID->decals;
    if ( (_WORD)decals == 0xFFFF )
      v3 = nullptr;
    else
      v3 = s_aDecalPool.m_Memory.m_pMemory[decals];
    if ( v3 == pdecal )
    {
      if ( pdecal->pnext != nullptr )
        surfID->decals = pdecal->pnext->m_iDecalPool;
      else
        surfID->decals = -1;
LABEL_19:
      v6 = pdecal->surfID;
      if ( (v6->flags & 0x800) != 0 )
      {
        pDispInfo = v6->pDispInfo;
        if ( pDispInfo != nullptr )
          pDispInfo->NotifyRemoveDecal(this: pDispInfo, a2: pdecal->m_DispDecal);
      }
      goto LABEL_22;
    }
    if ( (_WORD)decals == 0xFFFF )
    {
      v4 = nullptr;
    }
    else
    {
      v4 = s_aDecalPool.m_Memory.m_pMemory[decals];
      if ( v4 != nullptr )
        goto LABEL_14;
    }
    Sys_Error(error: "Bad decal list");
LABEL_14:
    if ( v4->pnext != nullptr )
    {
      while ( 1 )
      {
        pnext = v4->pnext;
        if ( v4->pnext == pdecal )
          break;
        v4 = v4->pnext;
        if ( pnext->pnext == nullptr )
          goto LABEL_19;
      }
      v4->pnext = pdecal->pnext;
    }
    goto LABEL_19;
  }
LABEL_22:
  v8 = (pdecal->flags & 1) == 0;
  pdecal->surfID = nullptr;
  if ( v8 )
    --g_nDynamicDecals;
  else
    --g_nStaticDecals;
  s_aDecalPool.m_Memory.m_pMemory[pdecal->m_iDecalPool] = nullptr;
  CUtlMemoryPool::Free(this: &g_DecalAllocator, memBlock: pdecal);
}

//------------------------------------------------------------------------------
// Address: 0x100FF7F0
// Name: int R_FindDynamicDecalSlot(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl R_FindDynamicDecalSlot(int iStartAt)
{
  int v1; // esi
  int result; // eax

  v1 = iStartAt;
  if ( iStartAt >= g_nMaxDecals || iStartAt < 0 )
    v1 = 0;
  result = v1;
  while ( s_aDecalPool.m_Memory.m_pMemory[result] == nullptr
       || (s_aDecalPool.m_Memory.m_pMemory[result]->flags & 1) != 0
       || (s_aDecalPool.m_Memory.m_pMemory[result]->flags & 0x1000) != 0 )
  {
    if ( ++result >= g_nMaxDecals )
      result = 0;
    if ( result == v1 )
    {
      DevMsg(a1: "R_FindDynamicDecalSlot: no slot available.\n");
      return -1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FF850
// Name: int DecalListCreate(struct decallist_t __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl DecalListCreate(decallist_t *pList)
{
  unsigned int v1; // ebx
  int v2; // ecx
  decal_t **m_pMemory; // edx
  decal_t *v4; // edi
  msurface2_t *surfID; // eax
  int decals; // eax
  unsigned __int8 v7; // cl
  decal_t *j; // eax
  decallist_t *v9; // esi
  const char *v10; // eax
  int v11; // eax
  int i; // [esp+4h] [ebp-4h]

  v1 = 0;
  if ( host_state.worldmodel != nullptr )
  {
    v2 = 0;
    i = 0;
    if ( g_nMaxDecals > 0 )
    {
      m_pMemory = s_aDecalPool.m_Memory.m_pMemory;
      do
      {
        v4 = m_pMemory[v2];
        if ( v4 != nullptr )
        {
          surfID = v4->surfID;
          if ( surfID != nullptr && (v4->flags & 0x804) == 0 )
          {
            decals = surfID->decals;
            v7 = 0;
            if ( (_WORD)decals != 0xFFFF )
            {
              for ( j = m_pMemory[decals]; j != nullptr; ++v7 )
              {
                if ( j == v4 )
                  break;
                j = j->pnext;
              }
            }
            v9 = &pList[v1];
            v9->depth = v7;
            v9->flags = v4->flags;
            R_DecalUnProject(pdecal: v4, entry: v9);
            v10 = v4->material->GetName(this: v4->material);
            V_strncpy(pDest: v9->name, pSrc: v10, maxLen: 128);
            v11 = DecalListAdd(pList, a2: v1);
            m_pMemory = s_aDecalPool.m_Memory.m_pMemory;
            v2 = i;
            v1 = v11;
          }
        }
        i = ++v2;
      }
      while ( v2 < g_nMaxDecals );
    }
  }
  qsort(base: pList, num: v1, width: 0x9Cu, comp: (int (__cdecl *)(const void *, const void *))DecalDepthCompare);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x100FFB40
// Name: public: CFunctor9<void (*)(bool,int,class Vector,int,struct decal_t __near * __near *,int,int,int,float),bool,int,class Vector,int,struct decal_t __near * __near *,int,int,int,float,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::CFunctor9<void (*)(bool,int,class Vector,int,struct decal_t __near * __near *,int,int,int,float),bool,int,class Vector,int,struct decal_t __near * __near *,int,int,int,float,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>(void (*)(bool,int,class Vector,int,struct decal_t __near * __near *,int,int,int,float),bool const __near &,int const __near &,class Vector const __near &,int const __near &,struct decal_t __near * __near * const __near &,int const __near &,int const __near &,int const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor9<void (__cdecl*)(bool,int,Vector,int,decal_t * *,int,int,int,float),bool,int,Vector,int,decal_t * *,int,int,int,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *__thiscall CFunctor9<void (__cdecl *)(bool,int,Vector,int,decal_t * *,int,int,int,float),bool,int,Vector,int,decal_t * *,int,int,int,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::CFunctor9<void (__cdecl *)(bool,int,Vector,int,decal_t * *,int,int,int,float),bool,int,Vector,int,decal_t * *,int,int,int,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>(
        CFunctor9<void (__cdecl*)(bool,int,Vector,int,decal_t * *,int,int,int,float),bool,int,Vector,int,decal_t * *,int,int,int,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this,
        void (__cdecl *pfnProxied)(bool, int, Vector, int, decal_t **, int, int, int, float),
        bool *arg1,
        int *arg2,
        const Vector *arg3,
        int *arg4,
        decal_t ***arg5,
        int *arg6,
        int *arg7,
        int *arg8,
        float *arg9)
{
  this->m_iRefs = 1;
  this->m_pfnProxied = pfnProxied;
  this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CFunctor::IRefCounted::__vftable = (CFunctor9<void (__cdecl*)(bool,int,Vector,int,decal_t * *,int,int,int,float),bool,int,Vector,int,decal_t * *,int,int,int,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > >_vtbl *)&CFunctor9<void (__cdecl *)(bool,int,Vector,int,decal_t * *,int,int,int,float),bool,int,Vector,int,decal_t * *,int,int,int,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
  this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CFunctor9<void (__cdecl *)(bool,int,Vector,int,decal_t * *,int,int,int,float),bool,int,Vector,int,decal_t * *,int,int,int,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_arg1 = *arg1;
  this->m_arg2 = *arg2;
  this->m_arg3 = *arg3;
  this->m_arg4 = *arg4;
  this->m_arg5 = *arg5;
  this->m_arg6 = *arg6;
  this->m_arg7 = *arg7;
  this->m_arg8 = *arg8;
  this->m_arg9 = *arg9;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100FFBC0
// Name: public: virtual void CFunctor9<void (*)(bool,int,class Vector,int,struct decal_t __near * __near *,int,int,int,float),bool,int,class Vector,int,struct decal_t __near * __near *,int,int,int,float,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor9<void (__cdecl *)(bool,int,Vector,int,decal_t * *,int,int,int,float),bool,int,Vector,int,decal_t * *,int,int,int,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor9<void (__cdecl*)(bool,int,Vector,int,decal_t * *,int,int,int,float),bool,int,Vector,int,decal_t * *,int,int,int,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  ((void (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))this->m_pfnProxied)(
    a1: this->m_arg1,
    a2: this->m_arg2,
    a3: LODWORD(this->m_arg3.x),
    a4: LODWORD(this->m_arg3.y),
    a5: LODWORD(this->m_arg3.z),
    a6: this->m_arg4,
    a7: this->m_arg5,
    a8: this->m_arg6,
    a9: this->m_arg7,
    a10: this->m_arg8,
    a11: this->m_arg9);
}

//------------------------------------------------------------------------------
// Address: 0x10100100
// Name: public: void CDecalVertCache::StoreVertsInCache(struct decal_t __near *,class CDecalVert __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDecalVertCache::StoreVertsInCache(CDecalVertCache *this, decal_t *pDecal, CDecalVert *pList)
{
  int v3; // esi
  CDecalVertCache *v4; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  float *p_y; // edx
  double v9; // st7
  int v10; // eax

  v3 = (pDecal->clippedVertCount + 3) >> 2;
  CDecalVertCache::FindFreeBlocks(this, blockCount: v3);
  if ( v3 <= v4->m_freeBlockCount )
  {
    v5 = CDecalVertCache::AllocBlocks(this: v4, blockCount: v3);
    pDecal->cacheHandle = v5;
    v7 = v6 + (v5 << 7);
    if ( v3 != 0 )
    {
      p_y = &pList->m_cLMCoords.y;
      do
      {
        v9 = *(p_y - 7);
        p_y += 32;
        *(float *)v7 = v9;
        --v3;
        *(float *)(v7 + 4) = *(p_y - 38);
        *(float *)(v7 + 8) = *(p_y - 37);
        *(float *)(v7 + 16) = *(p_y - 35);
        *(float *)(v7 + 20) = *(p_y - 34);
        *(float *)(v7 + 24) = *(p_y - 33);
        *(float *)(v7 + 28) = *(p_y - 32);
        *(float *)(v7 + 32) = *(p_y - 31);
        *(float *)(v7 + 36) = *(p_y - 30);
        *(float *)(v7 + 40) = *(p_y - 29);
        *(float *)(v7 + 48) = *(p_y - 27);
        *(float *)(v7 + 52) = *(p_y - 26);
        *(float *)(v7 + 56) = *(p_y - 25);
        *(float *)(v7 + 60) = *(p_y - 24);
        *(float *)(v7 + 64) = *(p_y - 23);
        *(float *)(v7 + 68) = *(p_y - 22);
        *(float *)(v7 + 72) = *(p_y - 21);
        *(float *)(v7 + 80) = *(p_y - 19);
        *(float *)(v7 + 84) = *(p_y - 18);
        *(float *)(v7 + 88) = *(p_y - 17);
        *(float *)(v7 + 92) = *(p_y - 16);
        *(float *)(v7 + 96) = *(p_y - 15);
        *(float *)(v7 + 100) = *(p_y - 14);
        *(float *)(v7 + 104) = *(p_y - 13);
        *(float *)(v7 + 112) = *(p_y - 11);
        *(float *)(v7 + 116) = *(p_y - 10);
        *(float *)(v7 + 120) = *(p_y - 9);
        *(float *)(v7 + 124) = *(p_y - 8);
        *(_DWORD *)(v7 + 12) = pDecal->m_iDecalPool;
        *(_DWORD *)(v7 + 108) = r_framecount;
        v10 = *(_DWORD *)(v7 + 44);
        if ( v10 == 0xFFFF )
          v7 = 0;
        else
          v7 = v6 + (v10 << 7);
      }
      while ( v3 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10100230
// Name: void Shader_DecalDrawPoly(class CDecalVert __near *,class IMaterial __near *,struct msurface2_t __near *,int,struct decal_t __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __usercall Shader_DecalDrawPoly(
        int a1@<ebx>,
        int a2@<edi>,
        CDecalVert *v,
        IMaterial *pMaterial,
        msurface2_t *surfID,
        int vertCount,
        decal_t *pdecal,
        float flFade)
{
  IMatRenderContext *(__thiscall *GetRenderContext)(IMaterialSystem *); // edx
  IMatRenderContext *v9; // esi
  int m_nValue; // eax
  IMesh *v12; // esi
  CClientState *v14; // eax
  double v15; // st7
  CClientState *BaseLocalClient; // eax
  float v17; // xmm2_4
  char v18; // dl
  int v19; // ecx
  int v20; // edx
  int v21; // edi
  float *p_z; // esi
  float *m_pCurrPosition; // eax
  int v24; // xmm0_4
  int v25; // xmm1_4
  float *v26; // eax
  int v27; // xmm0_4
  float *v28; // eax
  int v29; // xmm0_4
  int m_nVertexCount; // eax
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+4h] [ebp-224h] BYREF
  Vector tVect; // [esp+1ECh] [ebp-3Ch] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F8h] [ebp-30h]
  IMesh *pMesh; // [esp+1FCh] [ebp-2Ch]
  Vector tangentT; // [esp+200h] [ebp-28h] BYREF
  Vector tangentS; // [esp+20Ch] [ebp-1Ch] BYREF
  Vector normal; // [esp+218h] [ebp-10h] BYREF
  int vertexFormat; // [esp+224h] [ebp-4h]
  float negate; // [esp+23Ch] [ebp+14h]
  bool negateb; // [esp+23Ch] [ebp+14h]
  int negatea; // [esp+23Ch] [ebp+14h]
  unsigned __int8 colora[4]; // [esp+240h] [ebp+18h]
  int flFadea; // [esp+244h] [ebp+1Ch]
  color32_s color; // 0:^25C.4

  GetRenderContext = materials->GetRenderContext;
  vertexFormat = 0;
  v9 = GetRenderContext(this: materials);
  pRenderContext.m_pObject = v9;
  if ( v9 != nullptr )
    v9->BeginRender(this: v9);
  if ( (sv_cheats.m_pParent != nullptr && sv_cheats.m_pParent->m_Value.m_nValue != 0 || Cmd_IsRptActive())
    && (mat_wireframe.m_pParent == nullptr ? (m_nValue = 0) : (m_nValue = mat_wireframe.m_pParent->m_Value.m_nValue),
        m_nValue != 0)
    || r_drawdecals.m_pParent != nullptr && r_drawdecals.m_pParent->m_Value.m_nValue == 2 )
  {
    ((void (__thiscall *)(IMatRenderContext *, IMaterial *, _DWORD, int, int))v9->Bind)(
      a1: v9,
      a2: g_materialDecalWireframe,
      a3: 0,
      a4: a2,
      a5: a1);
  }
  else
  {
    ((void (__thiscall *)(IMatRenderContext *, int, int, int))v9->BindLightmapPage)(
      a1: v9,
      a2: materialSortInfoArray[surfID->materialSortID].lightmapPageID,
      a3: a2,
      a4: a1);
    v9->Bind(this: v9, a2: pMaterial, a3: pdecal->userdata);
    vertexFormat = pMaterial->GetVertexFormat(this: pMaterial) & 0xFFFFFBFF;
  }
  v12 = v9->GetDynamicMesh(this: v9, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  pMesh = v12;
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v12;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_POLYGON;
  v12->SetPrimitiveType(this: v12, a2: MATERIAL_TRIANGLES);
  meshBuilder.m_pMesh->LockMesh(
    this: meshBuilder.m_pMesh,
    a2: vertCount,
    a3: 3 * vertCount - 6,
    a4: &meshBuilder,
    a5: nullptr);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v12->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 3 * vertCount - 6;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  CVertexBuilder::AttachBegin(
    this: &meshBuilder.m_VertexBuilder,
    pMesh: v12,
    nMaxVertexCount: vertCount,
    desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  color = pdecal->color;
  if ( flFade != 1.0 )
    color.a = (int)(float)((float)pdecal->color.a * flFade);
  if ( (pdecal->flags & 0x100) != 0 )
  {
    if ( pdecal->fadeDuration >= 0.0 )
    {
      BaseLocalClient = GetBaseLocalClient();
      v15 = 1.0 - (CClientState::GetTime(this: BaseLocalClient) - pdecal->fadeStartTime) / pdecal->fadeDuration;
    }
    else
    {
      v14 = GetBaseLocalClient();
      v15 = -((CClientState::GetTime(this: v14) - pdecal->fadeStartTime) / pdecal->fadeDuration);
    }
    negate = v15;
    v17 = negate;
    if ( negate >= 0.0 )
    {
      if ( negate > 1.0 )
        v17 = 1.0;
    }
    else
    {
      v17 = 0.0;
    }
    color.a = (int)(float)((float)color.a * v17);
  }
  v18 = vertexFormat;
  normal.x = 0.0;
  normal.y = 0.0;
  normal.z = 1.0;
  tangentS.x = 1.0;
  tangentS.y = 0.0;
  tangentS.z = 0.0;
  tangentT.x = 0.0;
  tangentT.y = 1.0;
  tangentT.z = 0.0;
  if ( (vertexFormat & 0x32) != 0 )
  {
    normal = surfID->plane->normal;
    if ( (vertexFormat & 0x30) != 0 )
    {
      negateb = TangentSpaceSurfaceSetup(surfID, &tVect);
      TangentSpaceComputeBasis(&tangentS, &tangentT, &normal, &tVect, negateTangent: negateb);
      v18 = vertexFormat;
    }
  }
  vertexFormat = LODWORD(pdecal->lightmapOffset);
  if ( vertCount > 0 )
  {
    v19 = v18 & 2;
    v20 = v18 & 0x30;
    v21 = color.b | ((color.g | ((color.r | (color.a << 8)) << 8)) << 8);
    flFadea = v19;
    negatea = v20;
    p_z = &v->m_vPos.z;
    *(_DWORD *)colora = vertCount;
    while ( 1 )
    {
      m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      v24 = *((_DWORD *)p_z - 1);
      v25 = *(_DWORD *)p_z;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = *(p_z - 2);
      *((_DWORD *)m_pCurrPosition + 1) = v24;
      *((_DWORD *)m_pCurrPosition + 2) = v25;
      if ( v19 != 0 )
        *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = normal;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v21;
      v26 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      v27 = *((_DWORD *)p_z + 3);
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = p_z[2];
      *((_DWORD *)v26 + 1) = v27;
      v28 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
      v29 = *((_DWORD *)p_z + 5);
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = p_z[4];
      *((_DWORD *)v28 + 1) = v29;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = vertexFormat;
      if ( v20 != 0 )
      {
        *(Vector *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                  + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS) = tangentS;
        *(Vector *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                  + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT) = tangentT;
      }
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      p_z += 8;
      if ( --*(_DWORD *)colora == 0 )
        break;
      v20 = negatea;
      v19 = flFadea;
    }
    v12 = pMesh;
  }
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
  }
  ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(
    a1: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  v12->Draw_2(this: v12, a2: -1, a3: 0);
  if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
  {
    meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
  {
    meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
  }
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x10100790
// Name: void R_DecalTerm(struct worldbrushdata_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DecalTerm(worldbrushdata_t *pBrushData, bool term_permanent_decals)
{
  bool v3; // cc
  int v4; // ebx
  int decals; // eax
  decal_t *v6; // eax
  decal_t *pnext; // esi
  float v8; // xmm0_4
  int i; // [esp+Ch] [ebp+8h]

  if ( pBrushData != nullptr )
  {
    v3 = pBrushData->numsurfaces <= 0;
    i = 0;
    if ( !v3 )
    {
      v4 = 0;
      do
      {
        decals = pBrushData->surfaces2[v4].decals;
        if ( (_WORD)decals != 0xFFFF )
        {
          v6 = s_aDecalPool.m_Memory.m_pMemory[decals];
          if ( v6 != nullptr )
          {
            do
            {
              pnext = v6->pnext;
              if ( term_permanent_decals
                || (v6->flags & 1) == 0 && (v6->flags & 0x1000) == 0
                || (v6->flags & 0x1000) != 0
                && (v8 = v6->fadeStartTime + 1.0,
                    v6->fadeStartTime = v8,
                    v8 >= r_spray_lifetime.m_pParent->m_Value.m_fValue) )
              {
                R_DecalUnlink(pdecal: v6);
              }
              v6 = pnext;
            }
            while ( pnext != nullptr );
          }
        }
        ++v4;
        ++i;
      }
      while ( i < pBrushData->numsurfaces );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10100850
// Name: void R_DecalTermAll(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DecalTermAll()
{
  int v0; // eax
  decal_t *v1; // edi
  msurface2_t *surfID; // edx
  int decals; // eax
  decal_t *v4; // eax
  int v5; // eax
  decal_t *v6; // esi
  decal_t *pnext; // eax
  msurface2_t *v8; // eax
  IDispInfo *pDispInfo; // ecx
  bool v10; // zf
  int i; // [esp+0h] [ebp-4h]

  v0 = 0;
  i = 0;
  if ( s_aDecalPool.m_Size > 0 )
  {
    while ( 1 )
    {
      v1 = s_aDecalPool.m_Memory.m_pMemory[v0];
      if ( v1 != nullptr )
        break;
LABEL_27:
      i = ++v0;
      if ( v0 >= s_aDecalPool.m_Size )
        return;
    }
    CDecalVertCache::FreeCachedVerts(this: &g_DecalVertCache, pDecal: s_aDecalPool.m_Memory.m_pMemory[v0]);
    surfID = v1->surfID;
    if ( surfID == nullptr )
    {
LABEL_23:
      v10 = (v1->flags & 1) == 0;
      v1->surfID = nullptr;
      if ( v10 )
        --g_nDynamicDecals;
      else
        --g_nStaticDecals;
      s_aDecalPool.m_Memory.m_pMemory[v1->m_iDecalPool] = nullptr;
      CUtlMemoryPool::Free(this: &g_DecalAllocator, memBlock: v1);
      v0 = i;
      goto LABEL_27;
    }
    decals = surfID->decals;
    if ( (_WORD)decals == 0xFFFF )
      v4 = nullptr;
    else
      v4 = s_aDecalPool.m_Memory.m_pMemory[decals];
    if ( v4 == v1 )
    {
      if ( v1->pnext != nullptr )
        surfID->decals = v1->pnext->m_iDecalPool;
      else
        surfID->decals = -1;
LABEL_20:
      v8 = v1->surfID;
      if ( (v8->flags & 0x800) != 0 )
      {
        pDispInfo = v8->pDispInfo;
        if ( pDispInfo != nullptr )
          pDispInfo->NotifyRemoveDecal(this: pDispInfo, a2: v1->m_DispDecal);
      }
      goto LABEL_23;
    }
    v5 = surfID->decals;
    if ( (_WORD)v5 == 0xFFFF )
    {
      v6 = nullptr;
    }
    else
    {
      v6 = s_aDecalPool.m_Memory.m_pMemory[v5];
      if ( v6 != nullptr )
        goto LABEL_15;
    }
    Sys_Error(error: "Bad decal list");
LABEL_15:
    if ( v6->pnext != nullptr )
    {
      while ( 1 )
      {
        pnext = v6->pnext;
        if ( v6->pnext == v1 )
          break;
        v6 = v6->pnext;
        if ( pnext->pnext == nullptr )
          goto LABEL_20;
      }
      v6->pnext = v1->pnext;
    }
    goto LABEL_20;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10100990
// Name: void R_DecalFlushDestroyList(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DecalFlushDestroyList()
{
  decal_t *v0; // edi
  msurface2_t *surfID; // ecx
  int decals; // edx
  decal_t *v3; // eax
  decal_t *v4; // esi
  decal_t *v5; // eax
  msurface2_t *v6; // eax
  IDispInfo *pDispInfo; // ecx
  bool v8; // zf
  decal_t *pNext; // [esp+8h] [ebp-4h]

  v0 = s_pDecalDestroyList;
  if ( s_pDecalDestroyList != nullptr )
  {
    while ( 1 )
    {
      pNext = v0->pDestroyList;
      CDecalVertCache::FreeCachedVerts(this: &g_DecalVertCache, pDecal: v0);
      surfID = v0->surfID;
      if ( surfID != nullptr )
        break;
LABEL_22:
      v8 = (v0->flags & 1) == 0;
      v0->surfID = nullptr;
      if ( v8 )
        --g_nDynamicDecals;
      else
        --g_nStaticDecals;
      s_aDecalPool.m_Memory.m_pMemory[v0->m_iDecalPool] = nullptr;
      CUtlMemoryPool::Free(this: &g_DecalAllocator, memBlock: v0);
      v0 = pNext;
      if ( pNext == nullptr )
        goto LABEL_26;
    }
    decals = surfID->decals;
    if ( (_WORD)decals == 0xFFFF )
      v3 = nullptr;
    else
      v3 = s_aDecalPool.m_Memory.m_pMemory[decals];
    if ( v3 == v0 )
    {
      if ( v0->pnext != nullptr )
        surfID->decals = v0->pnext->m_iDecalPool;
      else
        surfID->decals = -1;
LABEL_19:
      v6 = v0->surfID;
      if ( (v6->flags & 0x800) != 0 )
      {
        pDispInfo = v6->pDispInfo;
        if ( pDispInfo != nullptr )
          pDispInfo->NotifyRemoveDecal(this: pDispInfo, a2: v0->m_DispDecal);
      }
      goto LABEL_22;
    }
    if ( (_WORD)decals == 0xFFFF )
    {
      v4 = nullptr;
    }
    else
    {
      v4 = s_aDecalPool.m_Memory.m_pMemory[decals];
      if ( v4 != nullptr )
        goto LABEL_14;
    }
    Sys_Error(error: "Bad decal list");
LABEL_14:
    if ( v4->pnext != nullptr )
    {
      while ( 1 )
      {
        v5 = v4->pnext;
        if ( v4->pnext == v0 )
          break;
        v4 = v4->pnext;
        if ( v5->pnext == nullptr )
          goto LABEL_19;
      }
      v4->pnext = v0->pnext;
    }
    goto LABEL_19;
  }
LABEL_26:
  s_pDecalDestroyList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10100AA0
// Name: R_DecalAlloc
// Source: json
//------------------------------------------------------------------------------
decal_t *__cdecl R_DecalAlloc(bool flags)
{
  int m_nValue; // ecx
  int v2; // eax
  int v3; // eax
  int DynamicDecalSlot; // esi
  decal_t *result; // eax
  bool v6; // [esp+Bh] [ebp+Bh]

  v6 = flags;
  if ( r_decals.m_pParent != nullptr )
    m_nValue = r_decals.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( m_nValue >= g_nMaxDecals )
  {
    v2 = g_nMaxDecals;
  }
  else if ( r_decals.m_pParent != nullptr )
  {
    v2 = r_decals.m_pParent->m_Value.m_nValue;
  }
  else
  {
    v2 = 0;
  }
  if ( !v6 && g_nDynamicDecals >= v2 )
    goto LABEL_16;
  v3 = 0;
  if ( g_nMaxDecals <= 0 )
    goto LABEL_16;
  while ( s_aDecalPool.m_Memory.m_pMemory[v3] != nullptr )
  {
    if ( ++v3 >= g_nMaxDecals )
      goto LABEL_16;
  }
  DynamicDecalSlot = v3;
  if ( v3 == -1 )
  {
LABEL_16:
    DynamicDecalSlot = R_FindDynamicDecalSlot(iStartAt: g_iLastReplacedDynamic + 1);
    if ( DynamicDecalSlot == -1 )
    {
      if ( !bWarningOnce )
      {
        _DevWarning(a1: 1, a2: "Exceeded MAX_DECALS (%d).\n", g_nMaxDecals);
        bWarningOnce = true;
      }
      DynamicDecalSlot = 0;
    }
    R_DecalUnlink(pdecal: s_aDecalPool.m_Memory.m_pMemory[DynamicDecalSlot]);
    g_iLastReplacedDynamic = DynamicDecalSlot;
  }
  result = (decal_t *)CUtlMemoryPool::Alloc(this: &g_DecalAllocator);
  s_aDecalPool.m_Memory.m_pMemory[DynamicDecalSlot] = result;
  result->m_iDecalPool = DynamicDecalSlot;
  result->pDestroyList = nullptr;
  result->surfID = nullptr;
  *(_DWORD *)&result->clippedVertCount = -65536;
  if ( v6 )
    ++g_nStaticDecals;
  else
    ++g_nDynamicDecals;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10100BB0
// Name: class CDecalVert __near * R_DecalSetupVerts(struct decalcontext_t __near &,struct decal_t __near *,struct msurface2_t __near *,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
decalcache_t *__cdecl R_DecalSetupVerts(
        decalcontext_t *context,
        decal_t *pDecal,
        msurface2_t *surfID,
        IMaterial *pMaterial)
{
  float m_fValue; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  CDecalVert *v9; // edi
  decalcache_t *CachedVerts; // edi
  float playerOrigin_8; // [esp+8h] [ebp-24h]
  float playerOrigin_8a; // [esp+8h] [ebp-24h]
  float v14; // [esp+Ch] [ebp-20h]
  float v15; // [esp+10h] [ebp-1Ch]
  float originalScale; // [esp+14h] [ebp-18h]
  float nearDist; // [esp+18h] [ebp-14h]
  msurface2_t *nearDista; // [esp+18h] [ebp-14h]
  float fov; // [esp+1Ch] [ebp-10h]

  if ( (pDecal->flags & 0x2000) == 0 || (pDecal->flags & 0x1000) != 0 )
  {
    CachedVerts = CDecalVertCache::GetCachedVerts(this: &g_DecalVertCache, pDecal);
    if ( CachedVerts == nullptr )
    {
      decalcontext_t::InitSurface(this: context, surfID: pDecal->surfID);
      CachedVerts = (decalcache_t *)R_DecalVertsClip(pOutVerts: nullptr, pDecal, surfID, pMaterial);
      if ( pDecal->clippedVertCount != 0 )
      {
        R_DecalVertsLight(v: CachedVerts->decalVert, context, surfID: pDecal->clippedVertCount);
        CDecalVertCache::StoreVertsInCache(this: &g_DecalVertCache, pDecal, pList: CachedVerts->decalVert);
      }
    }
    return CachedVerts;
  }
  else
  {
    fov = r_dscale_farscale.m_pParent->m_Value.m_fValue;
    v15 = g_EngineRenderer->GetFov(this: g_EngineRenderer);
    m_fValue = r_dscale_basefov.m_pParent->m_Value.m_fValue;
    if ( v15 == m_fValue || v15 <= 0.0 || m_fValue <= 0.0 )
    {
      v7 = fov;
      v6 = nearDist;
    }
    else
    {
      v5 = (float)(v15 / m_fValue) * fov;
      v6 = (float)(v15 / m_fValue) * nearDist;
      v7 = v5;
      if ( v6 < 1.0 )
        v6 = 1.0;
      if ( v5 < 1.0 )
        v7 = 1.0;
    }
    if ( v14 <= originalScale )
    {
      if ( originalScale < playerOrigin_8 )
        v8 = (float)((float)((float)(originalScale - v14) / (float)(playerOrigin_8 - v14)) * (float)(v7 - v6)) + v6;
      else
        v8 = v7;
    }
    else
    {
      v8 = 1.0;
    }
    nearDista = pDecal->surfID;
    playerOrigin_8a = pDecal->scale;
    pDecal->scale = (float)(1.0 / v8) * playerOrigin_8a;
    decalcontext_t::InitSurface(this: context, surfID: nearDista);
    v9 = R_DecalVertsClip(pOutVerts: nullptr, pDecal, surfID, pMaterial);
    if ( v9 != nullptr )
      R_DecalVertsLight(v: v9, context, surfID: pDecal->clippedVertCount);
    pDecal->scale = playerOrigin_8a;
    return (decalcache_t *)v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10100EF0
// Name: void DecalUpdateAndDrawSingle(struct decalcontext_t __near &,struct msurface2_t __near *,struct decal_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall DecalUpdateAndDrawSingle(int a1@<ebx>, decalcontext_t *context, msurface2_t *surfID, decal_t *pDecal)
{
  CClientState *BaseLocalClient; // eax
  decalcache_t *v6; // eax
  char context_3; // [esp+17h] [ebp+13h]

  if ( pDecal->material != nullptr )
  {
    context_3 = 0;
    if ( (pDecal->flags & 0x100) != 0 )
    {
      if ( pDecal->fadeDuration <= 0.0
        || (BaseLocalClient = GetBaseLocalClient(),
            context_3 = 1,
            CClientState::GetTime(this: BaseLocalClient) < pDecal->fadeStartTime + pDecal->fadeDuration) )
      {
        context_3 = 0;
      }
    }
    if ( (surfID->flags & 0x800) == 0 )
    {
      v6 = R_DecalSetupVerts(context, pDecal, surfID, pMaterial: pDecal->material);
      if ( v6 != nullptr )
        Shader_DecalDrawPoly(
          a1,
          a2: (int)surfID,
          v: v6->decalVert,
          pMaterial: pDecal->material,
          surfID,
          vertCount: pDecal->clippedVertCount,
          pdecal: pDecal,
          flFade: 1.0);
    }
    if ( context_3 != 0 )
      R_DecalUnlink(pdecal: pDecal);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10100FA0
// Name: void DrawDecalsOnSingleSurface_NonQueued(class IMatRenderContext __near *,struct msurface2_t __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawDecalsOnSingleSurface_NonQueued(
        IMatRenderContext *pRenderContext,
        msurface2_t *surfID,
        const Vector *vModelOrg)
{
  decal_t *v3; // esi
  float y; // xmm0_4
  decal_t *pnext; // edi
  decalcontext_t context; // [esp+8h] [ebp-3Ch] BYREF

  if ( surfID->decals == 0xFFFF )
    v3 = nullptr;
  else
    v3 = s_aDecalPool.m_Memory.m_pMemory[surfID->decals];
  context.vModelOrg.x = vModelOrg->x;
  y = vModelOrg->y;
  context.pRenderContext = pRenderContext;
  context.vModelOrg.y = y;
  context.vModelOrg.z = vModelOrg->z;
  context.pSurf = nullptr;
  decalcontext_t::InitSurface(this: &context, surfID);
  if ( v3 != nullptr )
  {
    do
    {
      pnext = v3->pnext;
      if ( (v3->flags & 0x200) == 0 )
        DecalUpdateAndDrawSingle(&context, surfID, pDecal: v3);
      v3 = pnext;
    }
    while ( pnext != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10101030
// Name: void DrawDecalsOnSingleSurface_QueueHelper(struct msurface2_t __near *,class Vector)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawDecalsOnSingleSurface_QueueHelper(msurface2_t *surfID, Vector vModelOrg)
{
  IMatRenderContext *v2; // esi

  v2 = materials->GetRenderContext(this: materials);
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  DrawDecalsOnSingleSurface_NonQueued(pRenderContext: v2, surfID, &vModelOrg);
  if ( v2 != nullptr )
  {
    v2->EndRender(this: v2);
    v2->Release(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10101080
// Name: void R_DrawDecalsAllImmediate_Gathered(class IMatRenderContext __near *,struct decal_t __near * __near *,int,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __usercall R_DrawDecalsAllImmediate_Gathered(
        int m_nIndexCount@<ebx>,
        int a2@<edi>,
        CMeshBuilder *p_meshBuilder@<esi>,
        IMatRenderContext *pRenderContext,
        decal_t **ppDecals,
        int iDecalCount,
        const Vector *vModelOrg,
        float flFade)
{
  float z; // xmm0_4
  int m_nValue; // eax
  int v10; // eax
  decal_t *v11; // esi
  float fadeDuration; // xmm0_4
  CClientState *v13; // eax
  msurface2_t *surfID; // eax
  int clippedVertCount; // ebx
  char v16; // di
  __int64 v17; // rax
  IMesh *v18; // eax
  unsigned __int8 r; // dl
  unsigned __int8 g; // al
  unsigned __int8 a; // cl
  CClientState *v22; // eax
  double v23; // st7
  CClientState *BaseLocalClient; // eax
  float v25; // xmm2_4
  float lightmapOffset; // xmm2_4
  float *m_pCurrPosition; // edx
  int v28; // ecx
  float *p_y; // eax
  float *v30; // edx
  int v31; // xmm1_4
  float *v32; // edx
  int v33; // xmm1_4
  float *v34; // edx
  int v35; // edx
  unsigned int m_nIndexSize; // esi
  unsigned __int16 m_nIndexOffset; // di
  signed int v38; // edx
  unsigned __int16 *v39; // eax
  signed int v40; // ecx
  unsigned __int16 v41; // bx
  unsigned __int16 v42; // si
  int m_nVertexCount; // eax
  int v44; // esi
  decalcontext_t context; // [esp+0h] [ebp-280h] BYREF
  CMeshBuilder meshBuilder; // [esp+3Ch] [ebp-244h] BYREF
  Vector tVect; // [esp+224h] [ebp-5Ch] BYREF
  BOOL bNegate; // [esp+230h] [ebp-50h]
  __int64 v52; // [esp+234h] [ebp-4Ch]
  IMesh *v53; // [esp+240h] [ebp-40h]
  Vector vecTangentS; // [esp+244h] [ebp-3Ch] BYREF
  Vector vecTangentT; // [esp+250h] [ebp-30h] BYREF
  int i; // [esp+25Ch] [ebp-24h]
  msurface2_t *lastSurf; // [esp+260h] [ebp-20h]
  float flFadeValue; // [esp+264h] [ebp-1Ch]
  Vector vecNormal; // [esp+268h] [ebp-18h] BYREF
  int v60; // [esp+274h] [ebp-Ch]
  CDecalVert *pVerts; // [esp+278h] [ebp-8h]
  unsigned __int8 color[4]; // [esp+27Ch] [ebp-4h]
  bool bWireframe_3; // [esp+297h] [ebp+17h]

  context.pRenderContext = pRenderContext;
  context.vModelOrg.x = vModelOrg->x;
  context.vModelOrg.y = vModelOrg->y;
  z = vModelOrg->z;
  lastSurf = nullptr;
  context.vModelOrg.z = z;
  context.pSurf = nullptr;
  bWireframe_3 = (sv_cheats.m_pParent != nullptr && sv_cheats.m_pParent->m_Value.m_nValue != 0 || Cmd_IsRptActive())
              && (mat_wireframe.m_pParent == nullptr
                ? (m_nValue = 0)
                : (m_nValue = mat_wireframe.m_pParent->m_Value.m_nValue),
                  m_nValue != 0)
              || r_drawdecals.m_pParent != nullptr && r_drawdecals.m_pParent->m_Value.m_nValue == 2;
  v10 = 0;
  for ( i = 0; v10 != iDecalCount; i = v10 )
  {
    v11 = ppDecals[v10];
    if ( (v11->flags & 0x100) == 0
      || (v11->flags & 0x4000) != 0
      || (fadeDuration = v11->fadeDuration, v11->flags |= 0x4000u, fadeDuration <= 0.0)
      || (v13 = GetBaseLocalClient(), CClientState::GetTime(this: v13) < v11->fadeStartTime + v11->fadeDuration) )
    {
      surfID = v11->surfID;
      if ( surfID != lastSurf )
        lastSurf = v11->surfID;
      pVerts = (CDecalVert *)R_DecalSetupVerts(&context, pDecal: v11, surfID, pMaterial: v11->material);
      if ( pVerts != nullptr )
      {
        clippedVertCount = v11->clippedVertCount;
        v16 = 0;
        v53 = nullptr;
        if ( bWireframe_3 )
        {
          ((void (__thiscall *)(IMatRenderContext *, IMaterial *, _DWORD, int, int, CMeshBuilder *))pRenderContext->Bind)(
            a1: pRenderContext,
            a2: g_materialDecalWireframe,
            a3: 0,
            a4: a2,
            a5: m_nIndexCount,
            a6: p_meshBuilder);
        }
        else
        {
          ((void (__thiscall *)(IMatRenderContext *, int, int, int, CMeshBuilder *))pRenderContext->BindLightmapPage)(
            a1: pRenderContext,
            a2: materialSortInfoArray[v11->surfID->materialSortID].lightmapPageID,
            a3: a2,
            a4: m_nIndexCount,
            a5: p_meshBuilder);
          pRenderContext->Bind(this: pRenderContext, a2: v11->material, a3: v11->userdata);
          v17 = ((__int64 (__thiscall *)(IMaterial *, _DWORD, _DWORD, _DWORD))v11->material->GetVertexFormat)(
                  a1: v11->material,
                  a2: LODWORD(context.vModelOrg.x),
                  a3: LODWORD(context.vModelOrg.y),
                  a4: LODWORD(context.vModelOrg.z));
          v16 = v17;
          v53 = (IMesh *)HIDWORD(v17);
        }
        v18 = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 1, a3: 0, a4: 0, a5: 0);
        meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
        meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
        meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
        meshBuilder.m_pMesh = nullptr;
        meshBuilder.m_bGenerateIndices = false;
        memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
        meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
        meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
        meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
        meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
        memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
        meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
        v53 = v18;
        v60 = clippedVertCount - 2;
        CMeshBuilder::Begin(
          this: &meshBuilder,
          pMesh: v18,
          type: MATERIAL_TRIANGLES,
          nVertexCount: clippedVertCount,
          nIndexCount: 3 * (clippedVertCount - 2),
          pMeshSettings: nullptr);
        r = v11->color.r;
        g = v11->color.g;
        color[2] = v11->color.b;
        a = v11->color.a;
        color[0] = r;
        color[1] = g;
        color[3] = a;
        if ( flFade != 1.0 )
          color[3] = (int)(float)((float)a * flFade);
        if ( (v11->flags & 0x100) != 0 )
        {
          if ( v11->fadeDuration >= 0.0 )
          {
            BaseLocalClient = GetBaseLocalClient();
            v23 = 1.0 - (CClientState::GetTime(this: BaseLocalClient) - v11->fadeStartTime) / v11->fadeDuration;
          }
          else
          {
            v22 = GetBaseLocalClient();
            v23 = -((CClientState::GetTime(this: v22) - v11->fadeStartTime) / v11->fadeDuration);
          }
          flFadeValue = v23;
          v25 = flFadeValue;
          if ( flFadeValue >= 0.0 )
          {
            if ( flFadeValue > 1.0 )
              v25 = 1.0;
          }
          else
          {
            v25 = 0.0;
          }
          color[3] = (int)(float)((float)color[3] * v25);
        }
        vecNormal.x = 0.0;
        vecNormal.y = 0.0;
        vecNormal.z = 1.0;
        vecTangentS.x = 1.0;
        vecTangentS.y = 0.0;
        vecTangentS.z = 0.0;
        vecTangentT.x = 0.0;
        vecTangentT.y = 1.0;
        vecTangentT.z = 0.0;
        if ( (v16 & 0x32) != 0 )
        {
          vecNormal = v11->surfID->plane->normal;
          if ( (v16 & 0x30) != 0 )
          {
            LOBYTE(bNegate) = TangentSpaceSurfaceSetup(surfID: v11->surfID, &tVect);
            TangentSpaceComputeBasis(
              tangentS: &vecTangentS,
              tangentT: &vecTangentT,
              normal: &vecNormal,
              &tVect,
              negateTangent: bNegate);
          }
        }
        lightmapOffset = v11->lightmapOffset;
        if ( clippedVertCount > 0 )
        {
          m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          v28 = color[2] | ((color[1] | ((color[0] | (color[3] << 8)) << 8)) << 8);
          v52 = v16 & 0x30;
          p_y = &pVerts->m_vPos.y;
          do
          {
            *m_pCurrPosition = *(p_y - 1);
            m_pCurrPosition[1] = *p_y;
            m_pCurrPosition[2] = p_y[1];
            if ( (v16 & 2) != 0 )
              *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = vecNormal;
            *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v28;
            v30 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
            v31 = *((_DWORD *)p_y + 4);
            *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = p_y[3];
            *((_DWORD *)v30 + 1) = v31;
            v32 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
            v33 = *((_DWORD *)p_y + 6);
            *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = p_y[5];
            *((_DWORD *)v32 + 1) = v33;
            v34 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
            *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = lightmapOffset;
            v34[1] = 0.0;
            if ( v52 != 0 )
            {
              *(Vector *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                        + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                        * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS) = vecTangentS;
              *(Vector *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                        + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                        * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT) = vecTangentT;
            }
            v35 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
            meshBuilder.m_VertexBuilder.m_nCurrentVertex = v35;
            if ( v35 > meshBuilder.m_VertexBuilder.m_nVertexCount )
              meshBuilder.m_VertexBuilder.m_nVertexCount = v35;
            meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                                + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
            meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
            meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                     + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
            meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                                     + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
            m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                      + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
            meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                                     + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
            p_y += 8;
            --clippedVertCount;
            meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
          }
          while ( clippedVertCount != 0 );
        }
        m_nIndexSize = meshBuilder.m_IndexBuilder.m_nIndexSize;
        m_nIndexOffset = meshBuilder.m_IndexBuilder.m_nIndexOffset;
        v38 = v60 * meshBuilder.m_IndexBuilder.m_nIndexSize;
        v39 = &meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex];
        v40 = 0;
        if ( (signed int)(v60 * meshBuilder.m_IndexBuilder.m_nIndexSize) > 0 )
        {
          v60 = meshBuilder.m_IndexBuilder.m_nIndexOffset + 1;
          pVerts = (CDecalVert *)(meshBuilder.m_IndexBuilder.m_nIndexOffset + 2);
          do
          {
            v41 = v40 + v60;
            v42 = (_WORD)pVerts + v40;
            *v39 = m_nIndexOffset;
            v39[1] = v41;
            v39[2] = v42;
            ++v40;
            v39 += 3;
          }
          while ( v40 < v38 );
          m_nIndexSize = meshBuilder.m_IndexBuilder.m_nIndexSize;
        }
        m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
        v44 = v38 * m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex + 2 * v38 * m_nIndexSize;
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = v44;
        if ( v44 > meshBuilder.m_IndexBuilder.m_nIndexCount )
          meshBuilder.m_IndexBuilder.m_nIndexCount = v44;
        if ( meshBuilder.m_bGenerateIndices )
        {
          switch ( meshBuilder.m_Type )
          {
            case MATERIAL_LINE_STRIP:
              m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
              break;
            case MATERIAL_LINE_LOOP:
              m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
              break;
            case MATERIAL_POLYGON:
              m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
              break;
            case MATERIAL_QUADS:
              m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
              break;
            case MATERIAL_INSTANCED_QUADS:
              m_nVertexCount = 0;
              break;
            default:
              break;
          }
          CIndexBuilder::GenerateIndices(
            this: &meshBuilder.m_IndexBuilder,
            primitiveType: meshBuilder.m_Type,
            nIndexCount: m_nVertexCount);
          m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
        }
        p_meshBuilder = &meshBuilder;
        m_nIndexCount = meshBuilder.m_IndexBuilder.m_nIndexCount;
        a2 = m_nVertexCount;
        ((void (__thiscall *)(IMesh *))meshBuilder.m_pMesh->UnlockMesh)(a1: meshBuilder.m_pMesh);
        meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
        meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
        meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
        meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
        meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
        meshBuilder.m_pMesh = nullptr;
        v53->Draw_2(this: v53, a2: -1, a3: 0);
        if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
          && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
        {
          meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
        }
        if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
          && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
        {
          meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
        }
      }
    }
    else if ( v11->pDestroyList == nullptr )
    {
      v11->pDestroyList = s_pDecalDestroyList;
      s_pDecalDestroyList = v11;
    }
    v10 = i + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10101750
// Name: void R_DrawDecalsAllImmediate(class IMatRenderContext __near *,int,int,class Vector const __near &,int,float)
// Source: json
//------------------------------------------------------------------------------
void __usercall R_DrawDecalsAllImmediate(
        int a1@<ebx>,
        int m_nIndexCount@<edi>,
        CMeshBuilder *p_meshBuilder@<esi>,
        IMatRenderContext *pRenderContext,
        int iGroup,
        int iTreeType,
        const Vector *vModelOrg,
        int nCheckCount,
        float flFade)
{
  int m_Size; // esi
  float z; // xmm0_4
  int m_nValue; // eax
  DecalSortTrees_t *m_pMemory; // ecx
  int v13; // edi
  int v14; // esi
  int v15; // edx
  int v16; // eax
  bool v17; // zf
  int **v18; // eax
  int *v19; // eax
  int v20; // esi
  float v21; // xmm0_4
  CClientState *v22; // eax
  msurface2_t *v23; // eax
  int v24; // ebx
  char v25; // di
  __int64 v26; // rax
  IMesh *v27; // eax
  unsigned __int8 v28; // dl
  unsigned __int8 v29; // al
  unsigned __int8 v30; // cl
  CClientState *v31; // eax
  double v32; // st7
  CClientState *BaseLocalClient; // eax
  float v34; // xmm2_4
  int v35; // xmm1_4
  float *m_pCurrPosition; // edx
  int v37; // ecx
  float *p_y; // eax
  float *v39; // edx
  int v40; // xmm0_4
  float *v41; // edx
  int v42; // xmm0_4
  int v43; // edx
  unsigned int m_nIndexSize; // esi
  unsigned __int16 m_nIndexOffset; // di
  signed int v46; // edx
  unsigned __int16 *v47; // eax
  signed int v48; // ecx
  unsigned __int16 v49; // bx
  int m_nVertexCount; // eax
  int v51; // esi
  decalcontext_t context; // [esp+0h] [ebp-294h] BYREF
  CMeshBuilder meshBuilder; // [esp+3Ch] [ebp-258h] BYREF
  Vector tVect; // [esp+224h] [ebp-70h] BYREF
  BOOL bNegate; // [esp+230h] [ebp-64h]
  int nBucketCount; // [esp+234h] [ebp-60h]
  __int64 v60; // [esp+238h] [ebp-5Ch]
  IMesh *v61; // [esp+244h] [ebp-50h]
  Vector vecTangentS; // [esp+248h] [ebp-4Ch] BYREF
  Vector vecTangentT; // [esp+254h] [ebp-40h] BYREF
  int iBucket; // [esp+260h] [ebp-34h]
  int iElement; // [esp+264h] [ebp-30h]
  float flFadeValue; // [esp+268h] [ebp-2Ch]
  int v67; // [esp+26Ch] [ebp-28h]
  msurface2_t *lastSurf; // [esp+270h] [ebp-24h]
  int v69; // [esp+274h] [ebp-20h]
  Vector vecNormal; // [esp+278h] [ebp-1Ch] BYREF
  int v71; // [esp+284h] [ebp-10h]
  int v72; // [esp+288h] [ebp-Ch]
  CDecalVert *pVerts; // [esp+28Ch] [ebp-8h]
  unsigned __int8 color[4]; // [esp+290h] [ebp-4h]
  bool bWireframe_3; // [esp+2ABh] [ebp+17h]

  context.pRenderContext = pRenderContext;
  context.vModelOrg.x = vModelOrg->x;
  m_Size = g_aDecalSortTrees.m_Size;
  context.vModelOrg.y = vModelOrg->y;
  z = vModelOrg->z;
  lastSurf = nullptr;
  context.vModelOrg.z = z;
  context.pSurf = nullptr;
  bWireframe_3 = (sv_cheats.m_pParent != nullptr && sv_cheats.m_pParent->m_Value.m_nValue != 0 || Cmd_IsRptActive())
              && (mat_wireframe.m_pParent == nullptr
                ? (m_nValue = 0)
                : (m_nValue = mat_wireframe.m_pParent->m_Value.m_nValue),
                  m_nValue != 0)
              || r_drawdecals.m_pParent != nullptr && r_drawdecals.m_pParent->m_Value.m_nValue == 2;
  if ( m_Size > 0 )
  {
    m_pMemory = g_aDecalSortTrees.m_Memory.m_pMemory;
    v13 = 20 * (iGroup + iTreeType + 2 * iGroup);
    v67 = v13;
    v71 = v13 + 12;
    v69 = m_Size;
    do
    {
      v14 = *(int *)((char *)&m_pMemory->m_aDecalSortBuckets[0][0].m_Size + v13);
      v15 = 0;
      nBucketCount = v14;
      for ( iBucket = 0; v15 < v14; iBucket = v15 )
      {
        v16 = *(int *)((char *)m_pMemory->m_pTrees + v71);
        v17 = *(_DWORD *)(v16 + 8 * v15 + 4) == nCheckCount;
        v18 = (int **)(v16 + 8 * v15);
        if ( v17 )
        {
          v19 = *v18;
          if ( v19 != nullptr )
          {
            while ( 1 )
            {
              v20 = *v19;
              iElement = v19[2];
              if ( v20 != 0 )
              {
                if ( (*(_WORD *)(v20 + 84) & 0x100) == 0
                  || (*(_WORD *)(v20 + 84) & 0x4000) != 0
                  || (v21 = *(float *)(v20 + 60), *(_WORD *)(v20 + 84) |= 0x4000u, v21 <= 0.0)
                  || (v22 = GetBaseLocalClient(),
                      CClientState::GetTime(this: v22) < *(float *)(v20 + 64) + *(float *)(v20 + 60)) )
                {
                  v23 = *(msurface2_t **)(v20 + 8);
                  if ( v23 != lastSurf )
                    lastSurf = *(msurface2_t **)(v20 + 8);
                  pVerts = (CDecalVert *)R_DecalSetupVerts(
                                           &context,
                                           pDecal: (decal_t *)v20,
                                           surfID: v23,
                                           pMaterial: *(IMaterial **)(v20 + 12));
                  if ( pVerts != nullptr )
                  {
                    v24 = *(unsigned __int16 *)(v20 + 78);
                    v25 = 0;
                    v61 = nullptr;
                    if ( bWireframe_3 )
                    {
                      ((void (__thiscall *)(IMatRenderContext *, IMaterial *, _DWORD, int, int, CMeshBuilder *))pRenderContext->Bind)(
                        a1: pRenderContext,
                        a2: g_materialDecalWireframe,
                        a3: 0,
                        a4: a1,
                        a5: m_nIndexCount,
                        a6: p_meshBuilder);
                    }
                    else
                    {
                      ((void (__thiscall *)(IMatRenderContext *, int, int, int, CMeshBuilder *))pRenderContext->BindLightmapPage)(
                        a1: pRenderContext,
                        a2: materialSortInfoArray[*(__int16 *)(*(_DWORD *)(v20 + 8) + 18)].lightmapPageID,
                        a3: a1,
                        a4: m_nIndexCount,
                        a5: p_meshBuilder);
                      pRenderContext->Bind(
                        this: pRenderContext,
                        a2: *(IMaterial **)(v20 + 12),
                        a3: *(void **)(v20 + 72));
                      v26 = ((__int64 (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD))*(_DWORD *)(**(_DWORD **)(v20 + 12)
                                                                                               + 80))(
                              a1: *(_DWORD *)(v20 + 12),
                              a2: LODWORD(context.vModelOrg.x),
                              a3: LODWORD(context.vModelOrg.y),
                              a4: LODWORD(context.vModelOrg.z));
                      v25 = v26;
                      v61 = (IMesh *)HIDWORD(v26);
                    }
                    v27 = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 1, a3: 0, a4: 0, a5: 0);
                    meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
                    meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
                    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
                    meshBuilder.m_pMesh = nullptr;
                    meshBuilder.m_bGenerateIndices = false;
                    memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
                    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
                    meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
                    meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
                    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
                    meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
                    memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
                    meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
                    v61 = v27;
                    v72 = v24 - 2;
                    CMeshBuilder::Begin(
                      this: &meshBuilder,
                      pMesh: v27,
                      type: MATERIAL_TRIANGLES,
                      nVertexCount: v24,
                      nIndexCount: 3 * (v24 - 2),
                      pMeshSettings: nullptr);
                    v28 = *(_BYTE *)(v20 + 68);
                    v29 = *(_BYTE *)(v20 + 69);
                    color[2] = *(_BYTE *)(v20 + 70);
                    v30 = *(_BYTE *)(v20 + 71);
                    color[0] = v28;
                    color[1] = v29;
                    color[3] = v30;
                    if ( flFade != 1.0 )
                      color[3] = (int)(float)((float)v30 * flFade);
                    if ( (*(_WORD *)(v20 + 84) & 0x100) != 0 )
                    {
                      if ( *(float *)(v20 + 60) >= 0.0 )
                      {
                        BaseLocalClient = GetBaseLocalClient();
                        v32 = 1.0
                            - (CClientState::GetTime(this: BaseLocalClient) - *(float *)(v20 + 64))
                            / *(float *)(v20 + 60);
                      }
                      else
                      {
                        v31 = GetBaseLocalClient();
                        v32 = -((CClientState::GetTime(this: v31) - *(float *)(v20 + 64)) / *(float *)(v20 + 60));
                      }
                      flFadeValue = v32;
                      v34 = flFadeValue;
                      if ( flFadeValue >= 0.0 )
                      {
                        if ( flFadeValue > 1.0 )
                          v34 = 1.0;
                      }
                      else
                      {
                        v34 = 0.0;
                      }
                      color[3] = (int)(float)((float)color[3] * v34);
                    }
                    vecNormal.x = 0.0;
                    vecNormal.y = 0.0;
                    vecNormal.z = 1.0;
                    vecTangentS.x = 1.0;
                    vecTangentS.y = 0.0;
                    vecTangentS.z = 0.0;
                    vecTangentT.x = 0.0;
                    vecTangentT.y = 1.0;
                    vecTangentT.z = 0.0;
                    if ( (v25 & 0x32) != 0 )
                    {
                      vecNormal = *(Vector *)*(_DWORD *)(*(_DWORD *)(v20 + 8) + 4);
                      if ( (v25 & 0x30) != 0 )
                      {
                        LOBYTE(bNegate) = TangentSpaceSurfaceSetup(surfID: *(msurface2_t **)(v20 + 8), &tVect);
                        TangentSpaceComputeBasis(
                          tangentS: &vecTangentS,
                          tangentT: &vecTangentT,
                          normal: &vecNormal,
                          &tVect,
                          negateTangent: bNegate);
                      }
                    }
                    v35 = *(_DWORD *)(v20 + 16);
                    if ( v24 > 0 )
                    {
                      m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
                      v37 = color[2] | ((color[1] | ((color[0] | (color[3] << 8)) << 8)) << 8);
                      v60 = v25 & 0x30;
                      p_y = &pVerts->m_vPos.y;
                      do
                      {
                        *m_pCurrPosition = *(p_y - 1);
                        m_pCurrPosition[1] = *p_y;
                        m_pCurrPosition[2] = p_y[1];
                        if ( (v25 & 2) != 0 )
                          *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = vecNormal;
                        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v37;
                        v39 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
                        v40 = *((_DWORD *)p_y + 4);
                        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = p_y[3];
                        *((_DWORD *)v39 + 1) = v40;
                        v41 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
                        v42 = *((_DWORD *)p_y + 6);
                        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = p_y[5];
                        *((_DWORD *)v41 + 1) = v42;
                        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = v35;
                        if ( v60 != 0 )
                        {
                          *(Vector *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                                    + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                    * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS) = vecTangentS;
                          *(Vector *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                                    + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                    * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT) = vecTangentT;
                        }
                        v43 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
                        meshBuilder.m_VertexBuilder.m_nCurrentVertex = v43;
                        if ( v43 > meshBuilder.m_VertexBuilder.m_nVertexCount )
                          meshBuilder.m_VertexBuilder.m_nVertexCount = v43;
                        meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                                            + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
                        meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
                        meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                                 + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
                        meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                                                 + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
                        m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                        meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                                                 + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
                        p_y += 8;
                        --v24;
                        meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                                              + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                      }
                      while ( v24 != 0 );
                    }
                    m_nIndexSize = meshBuilder.m_IndexBuilder.m_nIndexSize;
                    m_nIndexOffset = meshBuilder.m_IndexBuilder.m_nIndexOffset;
                    v46 = v72 * meshBuilder.m_IndexBuilder.m_nIndexSize;
                    v47 = &meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex];
                    v48 = 0;
                    if ( (signed int)(v72 * meshBuilder.m_IndexBuilder.m_nIndexSize) > 0 )
                    {
                      v72 = meshBuilder.m_IndexBuilder.m_nIndexOffset + 1;
                      pVerts = (CDecalVert *)(meshBuilder.m_IndexBuilder.m_nIndexOffset + 2);
                      do
                      {
                        v49 = v48 + v72;
                        *v47 = m_nIndexOffset;
                        v47[1] = v49;
                        v47[2] = v48++ + (_WORD)pVerts;
                        v47 += 3;
                      }
                      while ( v48 < v46 );
                      m_nIndexSize = meshBuilder.m_IndexBuilder.m_nIndexSize;
                    }
                    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
                    v51 = v46 * m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex + 2 * v46 * m_nIndexSize;
                    meshBuilder.m_IndexBuilder.m_nCurrentIndex = v51;
                    if ( v51 > meshBuilder.m_IndexBuilder.m_nIndexCount )
                      meshBuilder.m_IndexBuilder.m_nIndexCount = v51;
                    if ( meshBuilder.m_bGenerateIndices )
                    {
                      switch ( meshBuilder.m_Type )
                      {
                        case MATERIAL_LINE_STRIP:
                          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
                          break;
                        case MATERIAL_LINE_LOOP:
                          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
                          break;
                        case MATERIAL_POLYGON:
                          m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
                          break;
                        case MATERIAL_QUADS:
                          m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
                          break;
                        case MATERIAL_INSTANCED_QUADS:
                          m_nVertexCount = 0;
                          break;
                        default:
                          break;
                      }
                      CIndexBuilder::GenerateIndices(
                        this: &meshBuilder.m_IndexBuilder,
                        primitiveType: meshBuilder.m_Type,
                        nIndexCount: m_nVertexCount);
                      m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
                    }
                    p_meshBuilder = &meshBuilder;
                    m_nIndexCount = meshBuilder.m_IndexBuilder.m_nIndexCount;
                    a1 = m_nVertexCount;
                    ((void (__thiscall *)(IMesh *))meshBuilder.m_pMesh->UnlockMesh)(a1: meshBuilder.m_pMesh);
                    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
                    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
                    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
                    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
                    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
                    meshBuilder.m_pMesh = nullptr;
                    v61->Draw_2(this: v61, a2: -1, a3: 0);
                    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
                      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
                    {
                      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
                    }
                    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
                      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
                    {
                      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
                    }
                  }
                }
                else if ( *(_DWORD *)(v20 + 4) == 0 )
                {
                  *(_DWORD *)(v20 + 4) = s_pDecalDestroyList;
                  s_pDecalDestroyList = (decal_t *)v20;
                }
              }
              if ( iElement == 0 )
                break;
              v19 = (int *)iElement;
            }
            m_pMemory = g_aDecalSortTrees.m_Memory.m_pMemory;
            v13 = v67;
            v14 = nBucketCount;
            v15 = iBucket;
          }
        }
        ++v15;
      }
      v71 += 312;
      v13 += 312;
      v17 = v69-- == 1;
      v67 = v13;
    }
    while ( !v17 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10101EB0
// Name: void R_DrawDecalMeshList(struct DecalMeshList_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall R_DrawDecalMeshList(int a1@<ebx>, int a2@<esi>, DecalMeshList_t *meshList)
{
  IMatRenderContext *v3; // edi
  DecalMeshList_t *v4; // ebx
  char *v5; // esi
  IMatRenderContext_vtbl *v6; // edx

  v3 = materials->GetRenderContext(this: materials);
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  v4 = meshList;
  if ( meshList->m_aBatches.m_Size > 0 )
  {
    v5 = &meshList->m_aBatches.m_Memory.m_Memory[4];
    meshList = (DecalMeshList_t *)meshList->m_aBatches.m_Size;
    do
    {
      v6 = v3->__vftable;
      if ( g_pMaterialSystemConfig->nFullbright == 1 )
        ((void (__thiscall *)(IMatRenderContext *, int, int, int))v6->BindLightmapPage)(a1: v3, a2: -1, a3: a2, a4: a1);
      else
        ((void (__thiscall *)(IMatRenderContext *, _DWORD, int, int))v6->BindLightmapPage)(
          a1: v3,
          a2: *((_DWORD *)v5 + 1),
          a3: a2,
          a4: a1);
      a1 = *(_DWORD *)v5;
      a2 = *((_DWORD *)v5 - 1);
      ((void (__thiscall *)(IMatRenderContext *))v3->Bind)(a1: v3);
      ((void (__stdcall *)(_DWORD, _DWORD))v4->m_pMesh->Draw_2)(
        a1: *((unsigned __int16 *)v5 + 4),
        a2: *((unsigned __int16 *)v5 + 5));
      v5 += 16;
      meshList = (DecalMeshList_t *)((char *)meshList - 1);
    }
    while ( meshList != nullptr );
  }
  if ( v3 != nullptr )
  {
    v3->EndRender(this: v3);
    ((void (__thiscall *)(IMatRenderContext *, DecalMeshList_t *))v3->Release)(a1: v3, a2: meshList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10102650
// Name: void DecalSurfacesInit(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DecalSurfacesInit(bool bBrushModel)
{
  if ( bBrushModel )
  {
    ++g_nBrushModelDecalSortCheckCount;
  }
  else
  {
    CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::RemoveAll(this: &g_aDecalSortPool);
    ++g_nDecalSortCheckCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10102680
// Name: void R_DrawDecalsAllImmediate_GatherDecals(class IMatRenderContext __near *,int,int,class CUtlVector<struct decal_t __near *,class CUtlMemory<struct decal_t __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DrawDecalsAllImmediate_GatherDecals(
        IMatRenderContext *pRenderContext,
        int iGroup,
        int iTreeType,
        CUtlVector<decal_t *,CUtlMemory<decal_t *,int> > *DrawDecals)
{
  int v4; // edi
  DecalSortTrees_t *m_pMemory; // ecx
  int v6; // edx
  int v7; // eax
  int v8; // ebx
  decal_t ***v9; // eax
  decal_t **v10; // ebx
  decal_t *v11; // eax
  int v12; // edi
  int m_nAllocationCount; // eax
  decal_t **v14; // ecx
  int v15; // eax
  decal_t **v16; // eax
  bool v17; // zf
  int nBucketCount; // [esp+0h] [ebp-18h]
  decal_t *pDecal; // [esp+4h] [ebp-14h]
  int m_Size; // [esp+8h] [ebp-10h]
  int v21; // [esp+Ch] [ebp-Ch]
  int iBucket; // [esp+10h] [ebp-8h]
  int nCheckCount; // [esp+14h] [ebp-4h]
  int iGroupa; // [esp+24h] [ebp+Ch]

  nCheckCount = g_nDecalSortCheckCount;
  if ( iGroup == 4 )
    nCheckCount = g_nBrushModelDecalSortCheckCount;
  if ( g_aDecalSortTrees.m_Size > 0 )
  {
    v4 = 20 * (iGroup + iTreeType + 2 * iGroup);
    iGroupa = v4 + 12;
    m_pMemory = g_aDecalSortTrees.m_Memory.m_pMemory;
    v21 = v4;
    m_Size = g_aDecalSortTrees.m_Size;
    do
    {
      v6 = 0;
      nBucketCount = *(int *)((char *)&m_pMemory->m_aDecalSortBuckets[0][0].m_Size + v4);
      iBucket = 0;
      if ( nBucketCount > 0 )
      {
        do
        {
          v7 = *(int *)((char *)m_pMemory->m_pTrees + iGroupa);
          v8 = *(_DWORD *)(v7 + 8 * v6 + 4);
          v9 = (decal_t ***)(v7 + 8 * v6);
          if ( v8 == nCheckCount )
          {
            v10 = *v9;
            if ( *v9 != nullptr )
            {
              do
              {
                v11 = *v10;
                v10 = (decal_t **)v10[2];
                pDecal = v11;
                if ( v11 != nullptr )
                {
                  v12 = DrawDecals->m_Size;
                  m_nAllocationCount = DrawDecals->m_Memory.m_nAllocationCount;
                  if ( v12 + 1 > m_nAllocationCount )
                    CUtlMemory<INetMessage *,int>::Grow(
                      this: (CUtlMemory<S3RGBA,int> *)DrawDecals,
                      num: v12 - m_nAllocationCount + 1);
                  ++DrawDecals->m_Size;
                  v14 = DrawDecals->m_Memory.m_pMemory;
                  v15 = DrawDecals->m_Size - v12 - 1;
                  DrawDecals->m_pElements = DrawDecals->m_Memory.m_pMemory;
                  if ( v15 > 0 )
                    _V_memmove(dest: &v14[v12 + 1], src: &v14[v12], count: 4 * v15);
                  v16 = &DrawDecals->m_Memory.m_pMemory[v12];
                  if ( v16 != nullptr )
                    *v16 = pDecal;
                }
              }
              while ( v10 != nullptr );
              m_pMemory = g_aDecalSortTrees.m_Memory.m_pMemory;
              v4 = v21;
              v6 = iBucket;
            }
          }
          iBucket = ++v6;
        }
        while ( v6 < nBucketCount );
      }
      iGroupa += 312;
      v4 += 312;
      v17 = m_Size-- == 1;
      v21 = v4;
    }
    while ( !v17 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101027A0
// Name: void R_DrawDecalsAll_GatherDecals(class IMatRenderContext __near *,int,int,class CUtlVector<struct decal_t __near *,class CUtlMemory<struct decal_t __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DrawDecalsAll_GatherDecals(
        IMatRenderContext *pRenderContext,
        int iGroup,
        int iTreeType,
        CUtlVector<decal_t *,CUtlMemory<decal_t *,int> > *DrawDecals)
{
  int v4; // ebx
  int v5; // edi
  int m_nAllocationCount; // eax
  decal_t **m_pMemory; // ecx
  int v8; // eax
  decal_t **v9; // eax
  DecalSortTrees_t *v10; // eax
  int v11; // edi
  int v12; // eax
  decal_t **v13; // ebx
  IMaterial *material; // ecx
  __int64 v15; // rax
  int v16; // edi
  int v17; // eax
  decal_t **v18; // ecx
  int v19; // eax
  decal_t **v20; // eax
  decal_t *v21; // eax
  int v22; // edi
  int v23; // eax
  decal_t **v24; // ecx
  int v25; // eax
  decal_t **v26; // eax
  int nBucketCount; // [esp+0h] [ebp-1Ch]
  decal_t *pDecal; // [esp+4h] [ebp-18h]
  DecalSortTrees_t *sortTree; // [esp+8h] [ebp-14h]
  int m_Size; // [esp+Ch] [ebp-10h]
  int v31; // [esp+10h] [ebp-Ch]
  int iBucket; // [esp+14h] [ebp-8h]
  int nCheckCount; // [esp+18h] [ebp-4h]
  int iGroupa; // [esp+28h] [ebp+Ch]

  nCheckCount = g_nDecalSortCheckCount;
  if ( iGroup == 4 )
    nCheckCount = g_nBrushModelDecalSortCheckCount;
  if ( g_aDecalSortTrees.m_Size > 0 )
  {
    v4 = 20 * (iGroup + iTreeType + 2 * iGroup);
    v31 = v4;
    iGroupa = 0;
    m_Size = g_aDecalSortTrees.m_Size;
    do
    {
      v5 = DrawDecals->m_Size;
      m_nAllocationCount = DrawDecals->m_Memory.m_nAllocationCount;
      if ( v5 + 1 > m_nAllocationCount )
        CUtlMemory<INetMessage *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)DrawDecals,
          num: v5 - m_nAllocationCount + 1);
      ++DrawDecals->m_Size;
      m_pMemory = DrawDecals->m_Memory.m_pMemory;
      v8 = DrawDecals->m_Size - v5 - 1;
      DrawDecals->m_pElements = DrawDecals->m_Memory.m_pMemory;
      if ( v8 > 0 )
        _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: 4 * v8);
      v9 = &DrawDecals->m_Memory.m_pMemory[v5];
      if ( v9 != nullptr )
        *v9 = nullptr;
      v10 = &g_aDecalSortTrees.m_Memory.m_pMemory[iGroupa];
      v11 = 0;
      sortTree = &g_aDecalSortTrees.m_Memory.m_pMemory[iGroupa];
      nBucketCount = *(int *)((char *)&g_aDecalSortTrees.m_Memory.m_pMemory[iGroupa].m_aDecalSortBuckets[0][0].m_Size
                            + v4);
      iBucket = 0;
      if ( nBucketCount > 0 )
      {
        while ( 1 )
        {
          v12 = (int)&(*(DecalMaterialBucket_t **)((char *)&v10->m_aDecalSortBuckets[0][0].m_Memory.m_pMemory + v4))[v11];
          if ( *(_DWORD *)(v12 + 4) == nCheckCount )
          {
            v13 = *(decal_t ***)v12;
            if ( *(_DWORD *)v12 != 0 && (v13[1] != (decal_t *)v13 || v13[2] == (decal_t *)v13) )
            {
              material = (*v13)->material;
              if ( material != nullptr )
              {
                v15 = material->GetVertexFormat(this: material);
                if ( (HIDWORD(v15) | v15 & 0xFFFFFBFF) != 0 )
                {
                  v16 = DrawDecals->m_Size;
                  v17 = DrawDecals->m_Memory.m_nAllocationCount;
                  if ( v16 + 1 > v17 )
                    CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)DrawDecals, num: v16 - v17 + 1);
                  ++DrawDecals->m_Size;
                  v18 = DrawDecals->m_Memory.m_pMemory;
                  v19 = DrawDecals->m_Size - v16 - 1;
                  DrawDecals->m_pElements = DrawDecals->m_Memory.m_pMemory;
                  if ( v19 > 0 )
                    _V_memmove(dest: &v18[v16 + 1], src: &v18[v16], count: 4 * v19);
                  v20 = &DrawDecals->m_Memory.m_pMemory[v16];
                  if ( v20 != nullptr )
                    *v20 = (decal_t *)-1;
                  do
                  {
                    v21 = *v13;
                    v13 = (decal_t **)v13[2];
                    pDecal = v21;
                    if ( v21 != nullptr )
                    {
                      v22 = DrawDecals->m_Size;
                      v23 = DrawDecals->m_Memory.m_nAllocationCount;
                      if ( v22 + 1 > v23 )
                        CUtlMemory<INetMessage *,int>::Grow(
                          this: (CUtlMemory<S3RGBA,int> *)DrawDecals,
                          num: v22 - v23 + 1);
                      ++DrawDecals->m_Size;
                      v24 = DrawDecals->m_Memory.m_pMemory;
                      v25 = DrawDecals->m_Size - v22 - 1;
                      DrawDecals->m_pElements = DrawDecals->m_Memory.m_pMemory;
                      if ( v25 > 0 )
                        _V_memmove(dest: &v24[v22 + 1], src: &v24[v22], count: 4 * v25);
                      v26 = &DrawDecals->m_Memory.m_pMemory[v22];
                      if ( v26 != nullptr )
                        *v26 = pDecal;
                    }
                  }
                  while ( v13 != nullptr );
                  v11 = iBucket;
                }
              }
            }
          }
          v4 = v31;
          iBucket = ++v11;
          if ( v11 >= nBucketCount )
            break;
          v10 = sortTree;
        }
      }
      ++iGroupa;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10102990
// Name: void DecalSurfaceAdd(struct msurface2_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DecalSurfaceAdd(int surfID, int iGroup)
{
  decal_t *v2; // esi
  int v3; // ebx
  decal_t **v4; // edi
  DecalMaterialBucket_t *v5; // esi
  decal_t *pNext; // [esp+0h] [ebp-4h]
  int nCheckCount; // [esp+Ch] [ebp+8h]

  if ( *(_WORD *)(surfID + 12) != 0xFFFF )
  {
    v2 = s_aDecalPool.m_Memory.m_pMemory[*(unsigned __int16 *)(surfID + 12)];
    if ( v2 != nullptr )
    {
      nCheckCount = g_nDecalSortCheckCount;
      if ( iGroup == 4 )
        nCheckCount = g_nBrushModelDecalSortCheckCount;
      do
      {
        pNext = v2->pnext;
        if ( v2->material->GetPropertyFlag(this: v2->material, a2: MATERIAL_PROPERTY_NEEDS_LIGHTMAP) )
          v3 = (v2->flags & 1) == 0;
        else
          v3 = 2;
        v2->flags &= ~0x4000u;
        v4 = (decal_t **)CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int>>>::AllocInternal(
                           this: &g_aDecalSortPool,
                           multilist: true);
        if ( v4 != nullptr )
        {
          *v4 = v2;
          v5 = &g_aDecalSortTrees.m_Memory.m_pMemory[v2->m_iSortTree].m_aDecalSortBuckets[0][2 * iGroup + iGroup + v3].m_Memory.m_pMemory[v2->m_iSortMaterial];
          if ( v5->m_nCheckCount == nCheckCount )
            CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::LinkBefore(
              this: &g_aDecalSortPool,
              before: v5->m_iHead,
              elem: (int)v4);
          v5->m_iHead = (int)v4;
          v5->m_nCheckCount = nCheckCount;
        }
        v2 = pNext;
      }
      while ( pNext != nullptr );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10102C00
// Name: public: DecalSortTrees_t::DecalSortTrees_t(void)
// Source: json
//------------------------------------------------------------------------------
DecalSortTrees_t *__thiscall DecalSortTrees_t::DecalSortTrees_t(DecalSortTrees_t *this)
{
  CUtlVector<DecalMaterialBucket_t,CUtlMemory<DecalMaterialBucket_t,int> > *v1; // eax
  int i; // ecx
  int j; // ebx
  CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl*)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int> > *v4; // eax
  CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl*)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int> > *v5; // esi

  v1 = this->m_aDecalSortBuckets[0];
  for ( i = 14; i >= 0; --i )
  {
    v1->m_Memory.m_pMemory = nullptr;
    v1->m_Memory.m_nAllocationCount = 0;
    v1->m_Memory.m_nGrowSize = 0;
    v1->m_Size = 0;
    v1->m_pElements = nullptr;
    ++v1;
  }
  for ( j = 0; j < 3; ++j )
  {
    v4 = (CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl*)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int> > *)MemAlloc_Alloc(nSize: 0x24u);
    v5 = v4;
    if ( v4 != nullptr )
    {
      v4->m_LessFunc = DecalSortTreeSortLessFunc;
      v4->m_Elements.m_nAllocationCount = 16;
      v4->m_Elements.m_nGrowSize = 16;
      v4->m_Elements.m_pMemory = nullptr;
      v4->m_Elements.m_pMemory = (UtlRBTreeNode_t<DecalMaterialSortData_t,int> *)_g_pMemAlloc->Alloc_2(
                                                                                   this: _g_pMemAlloc,
                                                                                   a2: 448);
      v5->m_Root = -1;
      v5->m_NumElements = 0;
      v5->m_FirstFree = -1;
      v5->m_LastAlloc.index = -1;
      v5->m_pElements = v5->m_Elements.m_pMemory;
    }
    else
    {
      v5 = nullptr;
    }
    this->m_pTrees[j] = v5;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10102CA0
// Name: R_AddDecalToSurface
// Source: json
//------------------------------------------------------------------------------
void __usercall R_AddDecalToSurface(decal_t *pdecal@<ecx>, decalinfo_t *decalinfo@<eax>, msurface2_t *surfID)
{
  int decals; // eax
  decal_t *v6; // eax
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_aApplySurfs; // esi
  int m_Size; // edi
  S3RGBA *m_pMemory; // ecx
  int v11; // eax
  S3RGBA *v12; // eax

  pdecal->pnext = nullptr;
  decals = surfID->decals;
  if ( (_WORD)decals == 0xFFFF || (v6 = s_aDecalPool.m_Memory.m_pMemory[decals]) == nullptr )
  {
    surfID->decals = pdecal->m_iDecalPool;
  }
  else
  {
    for ( ; v6->pnext != nullptr; v6 = v6->pnext )
      ;
    v6->pnext = pdecal;
  }
  pdecal->surfID = surfID;
  pdecal->flSize = decalinfo->m_Size;
  pdecal->lightmapOffset = ComputeDecalLightmapOffset((int)surfID);
  if ( (surfID->flags & 0x800) != 0 )
    pdecal->m_DispDecal = ((int (__stdcall *)(_DWORD, _DWORD))surfID->pDispInfo->NotifyAddDecal)(
                            a1: pdecal,
                            a2: decalinfo->m_Size);
  m_nAllocationCount = decalinfo->m_aApplySurfs.m_Memory.m_nAllocationCount;
  p_m_aApplySurfs = (CUtlMemory<S3RGBA,int> *)&decalinfo->m_aApplySurfs;
  m_Size = decalinfo->m_aApplySurfs.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow(this: p_m_aApplySurfs, num: m_Size - m_nAllocationCount + 1);
  ++p_m_aApplySurfs[1].m_pMemory;
  m_pMemory = p_m_aApplySurfs->m_pMemory;
  v11 = (int)p_m_aApplySurfs[1].m_pMemory - m_Size - 1;
  p_m_aApplySurfs[1].m_nAllocationCount = (int)p_m_aApplySurfs->m_pMemory;
  if ( v11 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v11);
  v12 = &p_m_aApplySurfs->m_pMemory[m_Size];
  if ( v12 != nullptr )
    *v12 = (S3RGBA)surfID;
}

//------------------------------------------------------------------------------
// Address: 0x10102D70
// Name: void DrawDecalsOnSingleSurface(class IMatRenderContext __near *,struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawDecalsOnSingleSurface(IMatRenderContext *pRenderContext, msurface2_t *surfID)
{
  ICallQueue *v2; // eax

  if ( r_queued_decals.m_pParent != nullptr
    && r_queued_decals.m_pParent->m_Value.m_nValue != 0
    && (v2 = pRenderContext->GetCallQueue(this: pRenderContext)) != nullptr )
  {
    ICallQueue::QueueCall<void,msurface2_t *,Vector,msurface2_t *,Vector>(
      this: v2,
      pfnProxied: DrawDecalsOnSingleSurface_QueueHelper,
      arg1: &surfID,
      arg2: &modelorg);
  }
  else
  {
    DrawDecalsOnSingleSurface_NonQueued(pRenderContext, surfID, vModelOrg: &modelorg);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10102DD0
// Name: void R_DrawDecalsAll(class IMatRenderContext __near *,int,int,class Vector const __near &,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DrawDecalsAll(
        IMatRenderContext *pRenderContext,
        int iGroup,
        int iTreeType,
        const Vector *vModelOrg,
        int nCheckCount,
        float flFade)
{
  int (__thiscall *GetMaxVerticesToRender)(IMatRenderContext *, IMaterial *); // edx
  float z; // xmm0_4
  int v8; // edi
  int v9; // ebx
  int m_nValue; // eax
  CClientState *BaseLocalClient; // eax
  int v12; // ecx
  int v13; // eax
  DecalSortTrees_t *v14; // eax
  int v15; // edx
  int v16; // ecx
  DecalMaterialBucket_t *v17; // eax
  int m_iHead; // esi
  int v19; // ecx
  __int64 v20; // rax
  char v21; // di
  int v22; // esi
  float v23; // xmm0_4
  CClientState *v24; // eax
  msurface2_t *v25; // ecx
  float v26; // xmm0_4
  int v27; // eax
  int v28; // ebx
  int v29; // eax
  IMesh *v30; // eax
  int m_Size; // edi
  int v32; // eax
  int v33; // eax
  bool v34; // zf
  DecalBatchList_t *v35; // edi
  decal_t *v36; // eax
  unsigned __int8 v37; // dl
  unsigned __int8 v38; // bl
  int v39; // ecx
  float v40; // xmm1_4
  float v41; // xmm0_4
  float v42; // xmm1_4
  CDecalVert *v43; // eax
  int v44; // ecx
  int v45; // edi
  int v46; // esi
  float *m_pCurrPosition; // edx
  float *p_y; // eax
  float *v49; // edx
  int v50; // xmm0_4
  float *v51; // edx
  int v52; // xmm0_4
  int v53; // edx
  int v54; // ebx
  int v55; // edi
  int v56; // esi
  int v57; // edi
  int m_nVertexCount; // eax
  int v59; // eax
  DecalMeshList_t meshList; // [esp+0h] [ebp-AC0h] BYREF
  decalcontext_t context; // [esp+80Ch] [ebp-2B4h] BYREF
  Vector tVect; // [esp+848h] [ebp-278h] BYREF
  CMeshBuilder meshBuilder; // [esp+854h] [ebp-26Ch] BYREF
  unsigned __int64 vertexFormat; // [esp+A3Ch] [ebp-84h]
  BOOL bNegate; // [esp+A44h] [ebp-7Ch]
  DecalSortTrees_t *sortTree; // [esp+A48h] [ebp-78h]
  int nBucketCount; // [esp+A4Ch] [ebp-74h]
  int iElement; // [esp+A50h] [ebp-70h]
  unsigned __int8 color[4]; // [esp+A54h] [ebp-6Ch]
  Vector vecTangentS; // [esp+A58h] [ebp-68h] BYREF
  Vector vecTangentT; // [esp+A64h] [ebp-5Ch] BYREF
  decal_t *pDecalHead; // [esp+A70h] [ebp-50h]
  int v73; // [esp+A74h] [ebp-4Ch]
  float localClientTime; // [esp+A78h] [ebp-48h]
  msurface2_t *lastSurf; // [esp+A7Ch] [ebp-44h]
  int nSortTreeCount; // [esp+A80h] [ebp-40h]
  float flOffset; // [esp+A84h] [ebp-3Ch]
  int v78; // [esp+A88h] [ebp-38h]
  int iSortTree; // [esp+A8Ch] [ebp-34h]
  int iBucket; // [esp+A90h] [ebp-30h]
  Vector vecNormal; // [esp+A94h] [ebp-2Ch] BYREF
  int nDecalSortMaxIndices; // [esp+AA0h] [ebp-20h]
  int nDecalSortMaxVerts; // [esp+AA4h] [ebp-1Ch]
  int nCount; // [esp+AA8h] [ebp-18h]
  CDecalVert *pVerts; // [esp+AACh] [ebp-14h]
  int nVertCount; // [esp+AB0h] [ebp-10h]
  DecalBatchList_t *pBatch; // [esp+AB4h] [ebp-Ch]
  int nIndexCount; // [esp+AB8h] [ebp-8h]
  bool bBatchInit; // [esp+ABDh] [ebp-3h]
  bool bWireframe; // [esp+ABEh] [ebp-2h]
  bool bMeshInit; // [esp+ABFh] [ebp-1h]

  nSortTreeCount = g_aDecalSortTrees.m_Size;
  if ( g_aDecalSortTrees.m_Size == 0 )
    return;
  meshList.m_aBatches.m_Size = 0;
  meshList.m_aBatches.m_pElements = (DecalBatchList_t *)&meshList.m_aBatches;
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  GetMaxVerticesToRender = pRenderContext->GetMaxVerticesToRender;
  context.vModelOrg.x = vModelOrg->x;
  context.vModelOrg.y = vModelOrg->y;
  z = vModelOrg->z;
  lastSurf = nullptr;
  context.pSurf = nullptr;
  nVertCount = 0;
  nIndexCount = 0;
  v8 = 5 * g_nMaxDecals;
  context.vModelOrg.z = z;
  v9 = 15 * g_nMaxDecals;
  context.pRenderContext = pRenderContext;
  vecNormal.x = 0.0;
  vecNormal.y = 0.0;
  vecNormal.z = 1.0;
  vecTangentS.x = 1.0;
  vecTangentS.y = 0.0;
  vecTangentS.z = 0.0;
  vecTangentT.x = 0.0;
  vecTangentT.y = 1.0;
  vecTangentT.z = 0.0;
  nDecalSortMaxVerts = 5 * g_nMaxDecals;
  nDecalSortMaxIndices = 15 * g_nMaxDecals;
  if ( v8 >= GetMaxVerticesToRender(this: pRenderContext, a2: g_materialDecalWireframe) / 4 )
    nDecalSortMaxVerts = pRenderContext->GetMaxVerticesToRender(this: pRenderContext, a2: g_materialDecalWireframe) / 4;
  if ( v9 >= pRenderContext->GetMaxIndicesToRender(this: pRenderContext) )
    nDecalSortMaxIndices = pRenderContext->GetMaxIndicesToRender(this: pRenderContext);
  bWireframe = (sv_cheats.m_pParent != nullptr && sv_cheats.m_pParent->m_Value.m_nValue != 0 || Cmd_IsRptActive())
            && (mat_wireframe.m_pParent == nullptr
              ? (m_nValue = 0)
              : (m_nValue = mat_wireframe.m_pParent->m_Value.m_nValue),
                m_nValue != 0)
            || r_drawdecals.m_pParent != nullptr && r_drawdecals.m_pParent->m_Value.m_nValue == 2;
  BaseLocalClient = GetBaseLocalClient();
  localClientTime = CClientState::GetTime(this: BaseLocalClient);
  iSortTree = 0;
  if ( nSortTreeCount <= 0 )
    goto LABEL_106;
  v12 = 20 * (iGroup + iTreeType + 2 * iGroup);
  v13 = 0;
  v73 = v12;
  v78 = 0;
LABEL_20:
  v14 = (DecalSortTrees_t *)((char *)g_aDecalSortTrees.m_Memory.m_pMemory + v13);
  bMeshInit = true;
  v15 = *(int *)((char *)&v14->m_aDecalSortBuckets[0][0].m_Size + v12);
  v16 = 0;
  sortTree = v14;
  nBucketCount = v15;
  iBucket = 0;
  if ( v15 <= 0 )
    goto LABEL_105;
  while ( 1 )
  {
    v17 = &(*(DecalMaterialBucket_t **)((char *)&v14->m_aDecalSortBuckets[0][0].m_Memory.m_pMemory + v73))[v16];
    if ( v17->m_nCheckCount == nCheckCount )
    {
      m_iHead = v17->m_iHead;
      if ( v17->m_iHead != 0 && (*(_DWORD *)(m_iHead + 4) != m_iHead || *(_DWORD *)(m_iHead + 8) == m_iHead) )
      {
        v19 = *(_DWORD *)(*(_DWORD *)m_iHead + 12);
        pDecalHead = *(decal_t **)m_iHead;
        if ( v19 != 0 )
        {
          v20 = ((__int64 (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v19 + 80))(a1: v19);
          v21 = v20;
          LODWORD(vertexFormat) = v20 & 0xFFFFFBFF;
          if ( (HIDWORD(v20) | v20 & 0xFFFFFBFF) != 0 )
            break;
        }
      }
    }
LABEL_93:
    v16 = iBucket + 1;
    iBucket = v16;
    if ( v16 >= nBucketCount )
    {
      if ( !bMeshInit )
      {
        if ( meshBuilder.m_bGenerateIndices )
        {
          switch ( meshBuilder.m_Type )
          {
            case MATERIAL_LINE_STRIP:
              m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
              break;
            case MATERIAL_LINE_LOOP:
              m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
              break;
            case MATERIAL_POLYGON:
              m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
              break;
            case MATERIAL_QUADS:
              m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
              break;
            case MATERIAL_INSTANCED_QUADS:
              m_nVertexCount = 0;
              break;
            default:
              m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
              break;
          }
          CIndexBuilder::GenerateIndices(
            this: &meshBuilder.m_IndexBuilder,
            primitiveType: meshBuilder.m_Type,
            nIndexCount: m_nVertexCount);
        }
        meshBuilder.m_pMesh->UnlockMesh(
          this: meshBuilder.m_pMesh,
          a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
          a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
          a4: &meshBuilder);
        meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
        meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
        meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
        meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
        meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
        meshBuilder.m_pMesh = nullptr;
        R_DrawDecalMeshList(a1: v9, a2: 0, &meshList);
      }
LABEL_105:
      v13 = v78 + 312;
      ++iSortTree;
      v78 += 312;
      if ( iSortTree >= nSortTreeCount )
      {
LABEL_106:
        if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
          && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
        {
          meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
        }
        if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
          && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
        {
          meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
        }
        return;
      }
      v12 = v73;
      goto LABEL_20;
    }
    v14 = sortTree;
  }
  pBatch = nullptr;
  bBatchInit = true;
  v9 = m_iHead;
  while ( 1 )
  {
    v22 = *(_DWORD *)v9;
    v9 = *(_DWORD *)(v9 + 8);
    iElement = v9;
    if ( v22 != 0 )
      break;
LABEL_90:
    if ( v9 == 0 )
    {
      if ( pBatch != nullptr )
        pBatch->m_nIndexCount = nIndexCount - pBatch->m_iStartIndex;
      goto LABEL_93;
    }
  }
  if ( (*(_WORD *)(v22 + 84) & 0x100) != 0 && (*(_WORD *)(v22 + 84) & 0x4000) == 0 )
  {
    v23 = *(float *)(v22 + 60);
    *(_WORD *)(v22 + 84) |= 0x4000u;
    if ( v23 > 0.0 )
    {
      v24 = GetBaseLocalClient();
      if ( CClientState::GetTime(this: v24) >= *(float *)(v22 + 64) + *(float *)(v22 + 60) )
      {
        if ( *(_DWORD *)(v22 + 4) == 0 )
        {
          *(_DWORD *)(v22 + 4) = s_pDecalDestroyList;
          s_pDecalDestroyList = (decal_t *)v22;
        }
        goto LABEL_90;
      }
    }
  }
  v25 = *(msurface2_t **)(v22 + 8);
  flOffset = 0.0;
  if ( v25 != lastSurf )
  {
    v26 = *(float *)(v22 + 16);
    lastSurf = v25;
    flOffset = v26;
    if ( (v21 & 0x32) != 0 )
    {
      vecNormal = v25->plane->normal;
      if ( (v21 & 0x30) != 0 )
      {
        LOBYTE(bNegate) = TangentSpaceSurfaceSetup(surfID: *(msurface2_t **)(v22 + 8), &tVect);
        TangentSpaceComputeBasis(
          tangentS: &vecTangentS,
          tangentT: &vecTangentT,
          normal: &vecNormal,
          &tVect,
          negateTangent: bNegate);
      }
    }
  }
  pVerts = (CDecalVert *)R_DecalSetupVerts(
                           &context,
                           pDecal: (decal_t *)v22,
                           surfID: *(msurface2_t **)(v22 + 8),
                           pMaterial: *(IMaterial **)(v22 + 12));
  if ( pVerts == nullptr )
    goto LABEL_90;
  v27 = *(unsigned __int16 *)(v22 + 78);
  v28 = nIndexCount;
  nCount = v27;
  if ( v27 + nVertCount <= nDecalSortMaxVerts && v27 + nIndexCount - 2 <= nDecalSortMaxIndices )
  {
    if ( bMeshInit )
      goto LABEL_57;
  }
  else
  {
    if ( pBatch != nullptr )
    {
      LOWORD(v28) = nIndexCount - pBatch->m_iStartIndex;
      pBatch->m_nIndexCount = v28;
    }
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          v29 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          v29 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          v29 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          v29 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          v29 = 0;
          break;
        default:
          v29 = meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: v29);
    }
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    R_DrawDecalMeshList(a1: v28, a2: v22, &meshList);
    pBatch = nullptr;
    bBatchInit = true;
LABEL_57:
    v28 = 0;
    meshList.m_pMesh = nullptr;
    meshList.m_aBatches.m_Size = 0;
    if ( bWireframe )
      v30 = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 0, a3: 0, a4: 0, a5: g_materialDecalWireframe);
    else
      v30 = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 0, a3: 0, a4: 0, a5: pDecalHead->material);
    meshList.m_pMesh = v30;
    CMeshBuilder::Begin(
      this: &meshBuilder,
      pMesh: v30,
      type: MATERIAL_TRIANGLES,
      nVertexCount: nDecalSortMaxVerts,
      nIndexCount: nDecalSortMaxIndices,
      pMeshSettings: nullptr);
    nVertCount = 0;
    nIndexCount = 0;
    bMeshInit = false;
  }
  if ( !bBatchInit )
  {
LABEL_69:
    v37 = *(_BYTE *)(v22 + 68);
    v38 = *(_BYTE *)(v22 + 69);
    LOBYTE(v39) = *(_BYTE *)(v22 + 71);
    color[2] = *(_BYTE *)(v22 + 70);
    if ( flFade != 1.0 )
      v39 = (int)(float)((float)(unsigned __int8)v39 * flFade);
    if ( (*(_WORD *)(v22 + 84) & 0x100) != 0 )
    {
      v40 = *(float *)(v22 + 60);
      if ( v40 >= 0.0 )
        v41 = 1.0 - (float)((float)(localClientTime - *(float *)(v22 + 64)) / v40);
      else
        LODWORD(v41) = COERCE_UNSIGNED_INT((float)(localClientTime - *(float *)(v22 + 64)) / v40) ^ _mask__NegFloat_;
      if ( v41 >= 0.0 )
      {
        if ( v41 > 1.0 )
          v41 = 1.0;
      }
      else
      {
        v41 = 0.0;
      }
      v39 = (int)(float)((float)(unsigned __int8)v39 * v41);
    }
    if ( nCount > 0 )
    {
      v42 = flOffset;
      v43 = pVerts;
      v44 = color[2] | ((v38 | ((v37 | ((unsigned __int8)v39 << 8)) << 8)) << 8);
      v45 = vertexFormat & 2;
      v46 = vertexFormat & 0x30;
      pVerts = (CDecalVert *)nCount;
      m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      p_y = &v43->m_vPos.y;
      do
      {
        *m_pCurrPosition = *(p_y - 1);
        m_pCurrPosition[1] = *p_y;
        m_pCurrPosition[2] = p_y[1];
        if ( v45 != 0 )
          *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = vecNormal;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v44;
        v49 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        v50 = *((_DWORD *)p_y + 4);
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = p_y[3];
        *((_DWORD *)v49 + 1) = v50;
        v51 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
        v52 = *((_DWORD *)p_y + 6);
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = p_y[5];
        *((_DWORD *)v51 + 1) = v52;
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = v42;
        if ( v46 != 0 )
        {
          *(Vector *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                    + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS) = vecTangentS;
          *(Vector *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                    + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT) = vecTangentT;
        }
        v53 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
        meshBuilder.m_VertexBuilder.m_nCurrentVertex = v53;
        if ( v53 > meshBuilder.m_VertexBuilder.m_nVertexCount )
          meshBuilder.m_VertexBuilder.m_nVertexCount = v53;
        meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                            + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
        meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
        meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                 + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
        meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                                 + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
        m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
        meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                                 + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
        p_y += 8;
        v34 = pVerts == (CDecalVert *)1;
        pVerts = (CDecalVert *)((char *)pVerts - 1);
        meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                              + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
      }
      while ( !v34 );
    }
    v54 = nCount;
    v55 = nVertCount;
    v56 = nCount - 2;
    CIndexBuilder::FastPolygon(this: &meshBuilder.m_IndexBuilder, startVert: nVertCount, triangleCount: nCount - 2);
    v57 = v54 + v55;
    v9 = iElement;
    nVertCount = v57;
    v21 = vertexFormat;
    nIndexCount += v56 + 2 * v56;
    goto LABEL_90;
  }
  m_Size = meshList.m_aBatches.m_Size;
  v32 = meshList.m_aBatches.m_Size + 1;
  if ( meshList.m_aBatches.m_Size + 1 <= 128 )
  {
    ++meshList.m_aBatches.m_Size;
    v33 = v32 - m_Size - 1;
    meshList.m_aBatches.m_pElements = (DecalBatchList_t *)&meshList.m_aBatches;
    if ( v33 > 0 )
      _V_memmove(
        dest: &meshList.m_aBatches.m_Memory.m_Memory[16 * m_Size + 16],
        src: (char *)&meshList.m_aBatches + 16 * m_Size,
        count: 16 * v33);
    v34 = !bWireframe;
    v35 = (DecalBatchList_t *)((char *)&meshList.m_aBatches + 16 * m_Size);
    pBatch = v35;
    v35->m_iStartIndex = v28;
    if ( v34 )
    {
      v36 = pDecalHead;
      v35->m_pMaterial = pDecalHead->material;
      v35->m_pProxy = v36->userdata;
      v35->m_iLightmapPage = materialSortInfoArray[v36->surfID->materialSortID].lightmapPageID;
    }
    else
    {
      v35->m_pMaterial = g_materialDecalWireframe;
    }
    bBatchInit = false;
    goto LABEL_69;
  }
  _Warning(a1: "R_DrawDecalsAll: overflowing m_aBatches. Reduce # of decals in the scene.\n");
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        v59 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        v59 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        v59 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        v59 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        v59 = 0;
        break;
      default:
        v59 = meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: v59);
  }
  meshBuilder.m_pMesh->UnlockMesh(
    this: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_pMesh = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  R_DrawDecalMeshList(a1: v28, a2: v22, &meshList);
  CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
}

//------------------------------------------------------------------------------
// Address: 0x10103850
// Name: void DecalSurfaceDraw_NonQueued(class IMatRenderContext __near *,int,class Vector const __near &,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DecalSurfaceDraw_NonQueued(
        IMatRenderContext *pRenderContext,
        IMatRenderContext *renderGroup,
        const Vector *vModelOrg,
        CMeshBuilder *nCheckCount,
        float flFade)
{
  if ( r_drawbatchdecals.m_pParent != nullptr && r_drawbatchdecals.m_pParent->m_Value.m_nValue != 0 )
  {
    R_DrawDecalsAll(pRenderContext, iGroup: (int)renderGroup, iTreeType: 0, vModelOrg, (int)nCheckCount, flFade);
    R_DrawDecalsAll(pRenderContext, iGroup: (int)renderGroup, iTreeType: 1, vModelOrg, (int)nCheckCount, flFade);
    R_DrawDecalsAll(pRenderContext, iGroup: (int)renderGroup, iTreeType: 2, vModelOrg, (int)nCheckCount, flFade);
  }
  else
  {
    R_DrawDecalsAllImmediate(
      a1: (int)renderGroup,
      m_nIndexCount: (int)vModelOrg,
      p_meshBuilder: nCheckCount,
      pRenderContext,
      iGroup: (int)renderGroup,
      iTreeType: 0,
      vModelOrg,
      (int)nCheckCount,
      flFade);
    R_DrawDecalsAllImmediate(
      a1: (int)renderGroup,
      m_nIndexCount: (int)vModelOrg,
      p_meshBuilder: nCheckCount,
      pRenderContext,
      iGroup: (int)renderGroup,
      iTreeType: 1,
      vModelOrg,
      (int)nCheckCount,
      flFade);
    R_DrawDecalsAllImmediate(
      a1: (int)renderGroup,
      m_nIndexCount: (int)vModelOrg,
      p_meshBuilder: nCheckCount,
      pRenderContext,
      iGroup: (int)renderGroup,
      iTreeType: 2,
      vModelOrg,
      (int)nCheckCount,
      flFade);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10103920
// Name: public: DecalSortTrees_t::~DecalSortTrees_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DecalSortTrees_t::~DecalSortTrees_t(DecalSortTrees_t *this)
{
  int i; // esi
  CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl*)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int> > *v3; // ecx
  CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl*)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int> > *v4; // edi
  CUtlVector<DecalMaterialBucket_t,CUtlMemory<DecalMaterialBucket_t,int> > *v5; // esi
  int k; // edi
  DecalSortTrees_t *v7; // esi
  int m; // edi
  CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl*)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int> > *v9; // eax
  int j; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < 3; ++i )
  {
    v3 = this->m_pTrees[i];
    if ( v3 != nullptr )
    {
      CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl *)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int>>::RemoveAll(this: v3);
      v4 = this->m_pTrees[i];
      if ( v4 != nullptr )
      {
        CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl *)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int>>::~CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl *)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int>>(this: this->m_pTrees[i]);
        free(pMem: v4);
      }
      this->m_pTrees[i] = nullptr;
    }
  }
  v5 = this->m_aDecalSortBuckets[0];
  for ( j = 5; j != 0; --j )
  {
    for ( k = 3; k != 0; --k )
    {
      v5->m_Size = 0;
      if ( v5->m_Memory.m_nGrowSize >= 0 )
      {
        if ( v5->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_Memory.m_pMemory);
          v5->m_Memory.m_pMemory = nullptr;
        }
        v5->m_Memory.m_nAllocationCount = 0;
      }
      v5->m_pElements = v5->m_Memory.m_pMemory;
      ++v5;
    }
  }
  v7 = this + 1;
  for ( m = 14; m >= 0; --m )
  {
    v7 = (DecalSortTrees_t *)((char *)v7 - 20);
    v7->m_aDecalSortBuckets[0][0].m_Memory.m_pMemory = nullptr;
    if ( (int)v7->m_pTrees[2] >= 0 )
    {
      if ( v7->m_pTrees[0] != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7->m_pTrees[0]);
        v7->m_pTrees[0] = nullptr;
      }
      v7->m_pTrees[1] = nullptr;
    }
    v9 = v7->m_pTrees[0];
    v7->m_aDecalSortBuckets[0][0].m_Memory.m_nAllocationCount = (int)v7->m_pTrees[0];
    if ( (int)v7->m_pTrees[2] >= 0 )
    {
      if ( v9 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
        v7->m_pTrees[0] = nullptr;
      }
      v7->m_pTrees[1] = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10103A20
// Name: R_DecalFindOverlappingDecals
// Source: json
//------------------------------------------------------------------------------
decal_t *__usercall R_DecalFindOverlappingDecals@<eax>(decalinfo_t *decalinfo@<eax>, msurface2_t *surfID)
{
  IMaterial *m_pMaterial; // edi
  int v4; // ebx
  int v5; // eax
  float v6; // xmm1_4
  float z; // xmm3_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  float x; // xmm1_4
  float v12; // xmm2_4
  int decals; // eax
  bool v14; // bl
  decal_t *v15; // edi
  decal_t **m_pFixedMemory; // eax
  IMaterial *material; // ecx
  float y; // xmm1_4
  float v19; // xmm3_4
  float v20; // xmm2_4
  float dy; // xmm0_4
  double v22; // st7
  double v23; // st6
  double v24; // st7
  double v25; // st6
  IMaterial *v26; // ecx
  IMaterial_vtbl *v27; // edx
  int (__thiscall *GetMappingWidth)(IMaterial *); // eax
  int v29; // eax
  float v30; // xmm2_4
  float v31; // xmm0_4
  int v32; // eax
  int m_nValue; // ecx
  int v34; // ecx
  int v35; // edi
  int i; // esi
  float testWorldScale[2]; // [esp+Ch] [ebp-144h] BYREF
  CUtlVectorFixedGrowable<decal_t *,32> coveredList; // [esp+14h] [ebp-13Ch] BYREF
  float v40; // [esp+B4h] [ebp-9Ch]
  float v41; // [esp+BCh] [ebp-94h]
  Vector testBasis[3]; // [esp+C4h] [ebp-8Ch] BYREF
  float v43; // [esp+ECh] [ebp-64h]
  float v44; // [esp+F0h] [ebp-60h]
  Vector2D vUnionMax; // [esp+F4h] [ebp-5Ch]
  Vector2D vUnionMin; // [esp+FCh] [ebp-54h]
  Vector2D vDecalMin; // [esp+104h] [ebp-4Ch]
  float sizey; // [esp+10Ch] [ebp-44h]
  float areaThreshold; // [esp+110h] [ebp-40h]
  float minProjectedWidth; // [esp+114h] [ebp-3Ch]
  Vector2D vDecalMax; // [esp+118h] [ebp-38h]
  float v52; // [esp+120h] [ebp-30h]
  float v53; // [esp+124h] [ebp-2Ch]
  float v54; // [esp+128h] [ebp-28h]
  float lastArea; // [esp+12Ch] [ebp-24h]
  float dx; // [esp+130h] [ebp-20h]
  float v57; // [esp+134h] [ebp-1Ch]
  float v58; // [esp+138h] [ebp-18h]
  float v59; // [esp+13Ch] [ebp-14h]
  decal_t *pDecal; // [esp+140h] [ebp-10h] BYREF
  float v61; // [esp+144h] [ebp-Ch]
  int count; // [esp+148h] [ebp-8h]
  decal_t *plast; // [esp+14Ch] [ebp-4h]

  m_pMaterial = decalinfo->m_pMaterial;
  plast = nullptr;
  count = 0;
  v4 = m_pMaterial->GetMappingWidth(this: m_pMaterial);
  v5 = m_pMaterial->GetMappingHeight(this: m_pMaterial);
  v6 = 1.0 / decalinfo->m_scale;
  z = decalinfo->m_Basis[1].z;
  v8 = (float)((float)v4 * v6) * 0.5;
  v57 = decalinfo->m_Basis[0].x * v8;
  v58 = decalinfo->m_Basis[0].y * v8;
  v9 = decalinfo->m_Basis[0].z * v8;
  minProjectedWidth = v8;
  v10 = (float)v5 * v6;
  x = decalinfo->m_Basis[1].x;
  v59 = v9;
  v12 = decalinfo->m_Basis[1].y * v10;
  decals = surfID->decals;
  areaThreshold = r_decal_overlap_area.m_pParent->m_Value.m_fValue;
  v14 = false;
  v52 = (float)(x * v10) * 0.5;
  v53 = v12 * 0.5;
  v54 = (float)(z * v10) * 0.5;
  lastArea = 0.0;
  if ( (_WORD)decals == 0xFFFF )
    v15 = nullptr;
  else
    v15 = s_aDecalPool.m_Memory.m_pMemory[decals];
  m_pFixedMemory = coveredList.m_Memory.m_pFixedMemory;
  pDecal = v15;
  coveredList.m_Memory.m_pMemory = coveredList.m_Memory.m_pFixedMemory;
  coveredList.m_Memory.m_nAllocationCount = 32;
  coveredList.m_Memory.m_nGrowSize = -1;
  coveredList.m_Memory.m_nMallocGrowSize = 0;
  coveredList.m_Size = 0;
  coveredList.m_pElements = coveredList.m_Memory.m_pFixedMemory;
  if ( v15 != nullptr )
  {
    do
    {
      material = v15->material;
      if ( (v15->flags & 1) == 0 && (v15->flags & 0x1000) == 0 && material != nullptr )
      {
        R_SetupDecalTextureSpaceBasis(
          pDecal: v15,
          vSurfNormal: &surfID->plane->normal,
          pMaterial: material,
          textureSpaceBasis: testBasis,
          decalWorldScale: testWorldScale);
        y = decalinfo->m_Position.y;
        v19 = decalinfo->m_Position.z;
        v20 = decalinfo->m_Position.x;
        v43 = y - v58;
        v44 = v19 - v59;
        dx = v15->dx;
        v40 = v19 - v54;
        dy = v15->dy;
        vDecalMin.x = (float)((float)((float)((float)(testBasis[0].y * (float)(y - v58))
                                            + (float)((float)(v20 - v57) * testBasis[0].x))
                                    + (float)(testBasis[0].z * (float)(v19 - v59)))
                            - dx)
                    + 0.5;
        v61 = dy;
        vDecalMin.y = (float)((float)((float)((float)(testBasis[1].x * (float)(v20 - v52))
                                            + (float)(testBasis[1].y * (float)(y - v53)))
                                    + (float)(testBasis[1].z * (float)(v19 - v54)))
                            - dy)
                    + 0.5;
        v41 = y + v53;
        vDecalMax.x = (float)((float)((float)((float)((float)(y + v58) * testBasis[0].y)
                                            + (float)((float)(v20 + v57) * testBasis[0].x))
                                    + (float)((float)(v19 + v59) * testBasis[0].z))
                            - dx)
                    + 0.5;
        v22 = 0.0;
        v23 = vDecalMin.y;
        vDecalMax.y = (float)((float)((float)((float)(testBasis[1].x * (float)(v20 + v52))
                                            + (float)(testBasis[1].y * (float)(y + v53)))
                                    + (float)(testBasis[1].z * (float)(v19 + v54)))
                            - dy)
                    + 0.5;
        if ( vDecalMin.y < 0.0 )
          v23 = 0.0;
        if ( vDecalMin.x >= 0.0 )
          v22 = vDecalMin.x;
        vUnionMin.x = v22;
        vUnionMin.y = v23;
        v24 = 1.0;
        v25 = vDecalMax.y;
        if ( vDecalMax.y > 1.0 )
          v25 = 1.0;
        if ( vDecalMax.x <= 1.0 )
          v24 = vDecalMax.x;
        v26 = v15->material;
        v27 = v26->__vftable;
        vUnionMax.x = v24;
        GetMappingWidth = v27->GetMappingWidth;
        vUnionMax.y = v25;
        v29 = GetMappingWidth(this: v26);
        sizey = vUnionMax.y - vUnionMin.y;
        v30 = (float)v29 / v15->scale;
        if ( (float)(vUnionMax.x - vUnionMin.x) >= 0.0 && sizey >= 0.0 )
        {
          v31 = sizey * (float)(vUnionMax.x - vUnionMin.x);
          if ( minProjectedWidth <= v30 )
          {
            if ( v31 > areaThreshold )
            {
              ++count;
              if ( plast == nullptr || (float)(v31 * v30) > lastArea )
              {
                plast = v15;
                lastArea = v31 * v30;
                v14 = v31 >= 0.89999998;
              }
            }
          }
          else if ( v31 > 0.99900001 )
          {
            CUtlVector<decal_t *,CUtlMemoryFixedGrowable<decal_t *,32,int>>::InsertBefore(
              this: &coveredList,
              elem: coveredList.m_Size,
              src: &pDecal);
          }
        }
      }
      v15 = v15->pnext;
      pDecal = v15;
    }
    while ( v15 != nullptr );
    if ( plast != nullptr )
    {
      v32 = r_decal_overlap_count.m_pParent != nullptr ? r_decal_overlap_count.m_pParent->m_Value.m_nValue : 0;
      if ( count < v32 && !v14 )
        plast = nullptr;
    }
    m_pFixedMemory = coveredList.m_Memory.m_pMemory;
  }
  if ( r_decal_cover_count.m_pParent != nullptr )
    m_nValue = r_decal_cover_count.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( coveredList.m_Size > m_nValue )
  {
    v34 = r_decal_cover_count.m_pParent != nullptr ? r_decal_cover_count.m_pParent->m_Value.m_nValue : 0;
    v35 = coveredList.m_Size - v34;
    for ( i = 0; i < v35; ++i )
    {
      R_DecalUnlink(pdecal: m_pFixedMemory[i]);
      m_pFixedMemory = coveredList.m_Memory.m_pMemory;
    }
  }
  coveredList.m_Size = 0;
  if ( coveredList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pFixedMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pFixedMemory);
      m_pFixedMemory = nullptr;
      coveredList.m_Memory.m_pMemory = nullptr;
    }
    coveredList.m_Memory.m_nAllocationCount = 0;
  }
  coveredList.m_pElements = m_pFixedMemory;
  if ( coveredList.m_Memory.m_nGrowSize >= 0 && m_pFixedMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pFixedMemory);
  return plast;
}

//------------------------------------------------------------------------------
// Address: 0x10103EE0
// Name: void R_DrawDecalsAll_Gathered(class IMatRenderContext __near *,struct decal_t __near * __near *,int,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DrawDecalsAll_Gathered(
        IMatRenderContext *pRenderContext,
        decal_t **ppDecals,
        int iDecalCount,
        const Vector *vModelOrg,
        float flFade)
{
  int v5; // ebx
  int (__thiscall *GetMaxVerticesToRender)(IMatRenderContext *, IMaterial *); // edx
  int v7; // edi
  decal_t *v8; // edi
  float z; // xmm0_4
  DecalBatchList_t *v10; // ebx
  int m_nValue; // eax
  decal_t *v12; // esi
  float fadeDuration; // xmm0_4
  CClientState *BaseLocalClient; // eax
  msurface2_t *surfID; // eax
  int clippedVertCount; // edi
  int v17; // eax
  IMesh *v18; // eax
  DecalBatchList_t *v19; // eax
  decal_t *v20; // ecx
  unsigned __int8 g; // cl
  unsigned __int8 b; // dl
  int v23; // ebx
  CClientState *v24; // eax
  double v25; // st7
  CClientState *v26; // eax
  float v27; // xmm2_4
  int v28; // esi
  int v29; // ebx
  float *p_y; // edi
  float *m_pCurrPosition; // eax
  int v32; // ecx
  float *v33; // eax
  int v34; // xmm0_4
  float *v35; // eax
  int v36; // xmm0_4
  int v37; // edi
  int v38; // esi
  int v39; // ebx
  int v40; // ecx
  int m_nVertexCount; // eax
  int i; // eax
  unsigned __int64 v43; // rax
  int v44; // eax
  int v45; // eax
  DecalMeshList_t meshList; // [esp+Ch] [ebp-AB0h] BYREF
  decalcontext_t context; // [esp+818h] [ebp-2A4h] BYREF
  Vector tVect; // [esp+854h] [ebp-268h] BYREF
  CMeshBuilder meshBuilder; // [esp+860h] [ebp-25Ch] BYREF
  int v50; // [esp+A48h] [ebp-74h]
  float flOffset; // [esp+A50h] [ebp-6Ch]
  CDecalVert *pVerts; // [esp+A54h] [ebp-68h]
  BOOL bNegate; // [esp+A58h] [ebp-64h]
  Vector vecTangentS; // [esp+A5Ch] [ebp-60h] BYREF
  Vector vecTangentT; // [esp+A68h] [ebp-54h] BYREF
  msurface2_t *lastSurf; // [esp+A74h] [ebp-48h]
  unsigned __int64 vertexFormat; // [esp+A78h] [ebp-44h]
  int nCount; // [esp+A80h] [ebp-3Ch]
  Vector vecNormal; // [esp+A84h] [ebp-38h] BYREF
  int nDecalSortMaxVerts; // [esp+A90h] [ebp-2Ch]
  decal_t **v61; // [esp+A94h] [ebp-28h]
  int nDecalSortMaxIndices; // [esp+A98h] [ebp-24h]
  int v63; // [esp+A9Ch] [ebp-20h]
  int nVertCount; // [esp+AA0h] [ebp-1Ch]
  decal_t *pDecalHead; // [esp+AA4h] [ebp-18h]
  DecalBatchList_t *pBatch; // [esp+AA8h] [ebp-14h]
  unsigned __int8 color[4]; // [esp+AACh] [ebp-10h]
  float flFadeValue; // [esp+AB0h] [ebp-Ch]
  int nIndexCount; // [esp+AB4h] [ebp-8h]
  bool bBatchInit; // [esp+ABAh] [ebp-2h]
  bool bMeshInit; // [esp+ABBh] [ebp-1h]
  bool bWireframe_3; // [esp+AD3h] [ebp+17h]

  meshList.m_aBatches.m_Size = 0;
  meshList.m_aBatches.m_pElements = (DecalBatchList_t *)&meshList.m_aBatches;
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  v5 = 5 * g_nMaxDecals;
  nVertCount = 0;
  nIndexCount = 0;
  GetMaxVerticesToRender = pRenderContext->GetMaxVerticesToRender;
  v7 = 15 * g_nMaxDecals;
  nDecalSortMaxVerts = 5 * g_nMaxDecals;
  nDecalSortMaxIndices = 15 * g_nMaxDecals;
  if ( v5 >= GetMaxVerticesToRender(this: pRenderContext, a2: g_materialDecalWireframe) / 4 )
    nDecalSortMaxVerts = pRenderContext->GetMaxVerticesToRender(this: pRenderContext, a2: g_materialDecalWireframe) / 4;
  if ( v7 >= pRenderContext->GetMaxIndicesToRender(this: pRenderContext) )
    nDecalSortMaxIndices = pRenderContext->GetMaxIndicesToRender(this: pRenderContext);
  v8 = nullptr;
  context.vModelOrg.x = vModelOrg->x;
  context.vModelOrg.y = vModelOrg->y;
  z = vModelOrg->z;
  v10 = nullptr;
  bMeshInit = true;
  bBatchInit = true;
  pBatch = nullptr;
  vertexFormat = 0;
  pDecalHead = nullptr;
  lastSurf = nullptr;
  context.pRenderContext = pRenderContext;
  context.vModelOrg.z = z;
  context.pSurf = nullptr;
  bWireframe_3 = (sv_cheats.m_pParent != nullptr && sv_cheats.m_pParent->m_Value.m_nValue != 0 || Cmd_IsRptActive())
              && (mat_wireframe.m_pParent == nullptr
                ? (m_nValue = 0)
                : (m_nValue = mat_wireframe.m_pParent->m_Value.m_nValue),
                  m_nValue != 0)
              || r_drawdecals.m_pParent != nullptr && r_drawdecals.m_pParent->m_Value.m_nValue == 2;
  if ( iDecalCount == 0 )
  {
LABEL_120:
    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
    {
      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
    }
    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
    }
    return;
  }
  v63 = 1;
  v61 = ppDecals;
  while ( 1 )
  {
    v12 = *v61;
    if ( *v61 == nullptr || v12 == (decal_t *)-1 )
    {
      if ( v10 != nullptr )
        v10->m_nIndexCount = nIndexCount - v10->m_iStartIndex;
      if ( v12 == nullptr && !bMeshInit )
      {
        if ( meshBuilder.m_bGenerateIndices )
        {
          switch ( meshBuilder.m_Type )
          {
            case MATERIAL_LINE_STRIP:
              m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
              break;
            case MATERIAL_LINE_LOOP:
              m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
              break;
            case MATERIAL_POLYGON:
              m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
              break;
            case MATERIAL_QUADS:
              m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
              break;
            case MATERIAL_INSTANCED_QUADS:
              m_nVertexCount = 0;
              break;
            default:
              m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
              break;
          }
          CIndexBuilder::GenerateIndices(
            this: &meshBuilder.m_IndexBuilder,
            primitiveType: meshBuilder.m_Type,
            nIndexCount: m_nVertexCount);
        }
        meshBuilder.m_pMesh->UnlockMesh(
          this: meshBuilder.m_pMesh,
          a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
          a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
          a4: &meshBuilder);
        meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
        meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
        meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
        meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
        meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
        meshBuilder.m_pMesh = nullptr;
        R_DrawDecalMeshList(a1: (int)v10, a2: 0, &meshList);
        bMeshInit = true;
      }
      v10 = nullptr;
      bBatchInit = true;
      pBatch = nullptr;
      if ( v12 == (decal_t *)-1 )
      {
        for ( i = v63; i != iDecalCount; ++i )
        {
          v8 = ppDecals[i];
          pDecalHead = v8;
          if ( v8 != nullptr && v8 != (decal_t *)-1 )
            break;
        }
        v43 = v8->material->GetVertexFormat(this: v8->material);
        LODWORD(v43) = v43 & 0xFFFFFBFF;
        vertexFormat = v43;
      }
      goto LABEL_96;
    }
    if ( (v12->flags & 0x100) == 0 )
      break;
    if ( (v12->flags & 0x4000) != 0 )
      break;
    fadeDuration = v12->fadeDuration;
    v12->flags |= 0x4000u;
    if ( fadeDuration <= 0.0 )
      break;
    BaseLocalClient = GetBaseLocalClient();
    if ( CClientState::GetTime(this: BaseLocalClient) < v12->fadeStartTime + v12->fadeDuration )
      break;
    if ( v12->pDestroyList == nullptr )
    {
      v12->pDestroyList = s_pDecalDestroyList;
      s_pDecalDestroyList = v12;
    }
LABEL_96:
    ++v61;
    if ( v63++ == iDecalCount )
    {
      if ( v10 != nullptr )
        v10->m_nIndexCount = nIndexCount - v10->m_iStartIndex;
      if ( !bMeshInit )
      {
        if ( meshBuilder.m_bGenerateIndices )
        {
          switch ( meshBuilder.m_Type )
          {
            case MATERIAL_LINE_STRIP:
              v45 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
              break;
            case MATERIAL_LINE_LOOP:
              v45 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
              break;
            case MATERIAL_POLYGON:
              v45 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
              break;
            case MATERIAL_QUADS:
              v45 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
              break;
            case MATERIAL_INSTANCED_QUADS:
              v45 = 0;
              break;
            default:
              v45 = meshBuilder.m_VertexBuilder.m_nVertexCount;
              break;
          }
          CIndexBuilder::GenerateIndices(
            this: &meshBuilder.m_IndexBuilder,
            primitiveType: meshBuilder.m_Type,
            nIndexCount: v45);
        }
        meshBuilder.m_pMesh->UnlockMesh(
          this: meshBuilder.m_pMesh,
          a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
          a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
          a4: &meshBuilder);
        meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
        meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
        meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
        meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
        meshBuilder.m_pMesh = nullptr;
        meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
        R_DrawDecalMeshList(a1: (int)v10, a2: (int)v12, &meshList);
      }
      goto LABEL_120;
    }
  }
  surfID = v12->surfID;
  if ( surfID != lastSurf )
    lastSurf = v12->surfID;
  pVerts = (CDecalVert *)R_DecalSetupVerts(&context, pDecal: v12, surfID, pMaterial: v12->material);
  if ( pVerts == nullptr )
    goto LABEL_96;
  clippedVertCount = v12->clippedVertCount;
  nCount = clippedVertCount;
  if ( clippedVertCount + nVertCount <= nDecalSortMaxVerts && clippedVertCount + nIndexCount - 2 <= nDecalSortMaxIndices )
  {
    if ( !bMeshInit )
      goto LABEL_48;
  }
  else
  {
    if ( v10 != nullptr )
      v10->m_nIndexCount = nIndexCount - v10->m_iStartIndex;
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          v17 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          v17 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          v17 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          v17 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          v17 = 0;
          break;
        default:
          v17 = meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: v17);
    }
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    R_DrawDecalMeshList(a1: 0, a2: (int)v12, &meshList);
    pBatch = nullptr;
    bBatchInit = true;
  }
  v10 = nullptr;
  meshList.m_pMesh = nullptr;
  meshList.m_aBatches.m_Size = 0;
  if ( bWireframe_3 )
    v18 = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 0, a3: 0, a4: 0, a5: g_materialDecalWireframe);
  else
    v18 = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 0, a3: 0, a4: 0, a5: pDecalHead->material);
  meshList.m_pMesh = v18;
  CMeshBuilder::Begin(
    this: &meshBuilder,
    pMesh: v18,
    type: MATERIAL_TRIANGLES,
    nVertexCount: nDecalSortMaxVerts,
    nIndexCount: nDecalSortMaxIndices,
    pMeshSettings: nullptr);
  nVertCount = 0;
  nIndexCount = 0;
  bMeshInit = false;
LABEL_48:
  if ( !bBatchInit )
  {
LABEL_54:
    g = v12->color.g;
    b = v12->color.b;
    LOBYTE(v23) = v12->color.a;
    color[0] = v12->color.r;
    color[1] = g;
    color[2] = b;
    if ( flFade != 1.0 )
      v23 = (int)(float)((float)(unsigned __int8)v23 * flFade);
    if ( (v12->flags & 0x100) != 0 )
    {
      if ( v12->fadeDuration >= 0.0 )
      {
        v26 = GetBaseLocalClient();
        v25 = 1.0 - (CClientState::GetTime(this: v26) - v12->fadeStartTime) / v12->fadeDuration;
      }
      else
      {
        v24 = GetBaseLocalClient();
        v25 = -((CClientState::GetTime(this: v24) - v12->fadeStartTime) / v12->fadeDuration);
      }
      flFadeValue = v25;
      v27 = flFadeValue;
      if ( flFadeValue >= 0.0 )
      {
        if ( flFadeValue > 1.0 )
          v27 = 1.0;
      }
      else
      {
        v27 = 0.0;
      }
      v23 = (int)(float)((float)(unsigned __int8)v23 * v27);
    }
    vecNormal.x = 0.0;
    vecNormal.y = 0.0;
    vecNormal.z = 1.0;
    vecTangentS.x = 1.0;
    vecTangentS.y = 0.0;
    vecTangentS.z = 0.0;
    vecTangentT.x = 0.0;
    vecTangentT.y = 1.0;
    vecTangentT.z = 0.0;
    if ( (vertexFormat & 0x32) != 0 )
    {
      vecNormal = v12->surfID->plane->normal;
      if ( (vertexFormat & 0x30) != 0 )
      {
        LOBYTE(bNegate) = TangentSpaceSurfaceSetup(surfID: v12->surfID, &tVect);
        TangentSpaceComputeBasis(
          tangentS: &vecTangentS,
          tangentT: &vecTangentT,
          normal: &vecNormal,
          &tVect,
          negateTangent: bNegate);
      }
    }
    flOffset = v12->lightmapOffset;
    if ( clippedVertCount > 0 )
    {
      v50 = vertexFormat & 2;
      v28 = color[2] | ((color[1] | ((color[0] | ((unsigned __int8)v23 << 8)) << 8)) << 8);
      v29 = vertexFormat & 0x30;
      p_y = &pVerts->m_vPos.y;
      flFadeValue = *(float *)&nCount;
      do
      {
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v32 = v50;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = *(p_y - 1);
        m_pCurrPosition[1] = *p_y;
        m_pCurrPosition[2] = p_y[1];
        if ( v32 != 0 )
          *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = vecNormal;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v28;
        v33 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        v34 = *((_DWORD *)p_y + 4);
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = p_y[3];
        *((_DWORD *)v33 + 1) = v34;
        v35 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
        v36 = *((_DWORD *)p_y + 6);
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = p_y[5];
        *((_DWORD *)v35 + 1) = v36;
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = flOffset;
        if ( v29 != 0 )
        {
          *(Vector *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                    + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS) = vecTangentS;
          *(Vector *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                    + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT) = vecTangentT;
        }
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        p_y += 8;
        --LODWORD(flFadeValue);
      }
      while ( flFadeValue != 0.0 );
    }
    v37 = nCount;
    v38 = nVertCount;
    v39 = nCount - 2;
    CIndexBuilder::FastPolygon(this: &meshBuilder.m_IndexBuilder, startVert: nVertCount, triangleCount: nCount - 2);
    v12 = (decal_t *)(v37 + v38);
    v8 = pDecalHead;
    v40 = v39 + nIndexCount + 2 * v39;
    v10 = pBatch;
    nVertCount = (int)v12;
    nIndexCount = v40;
    goto LABEL_96;
  }
  if ( meshList.m_aBatches.m_Size + 1 <= 128 )
  {
    v19 = (DecalBatchList_t *)((char *)&meshList.m_aBatches
                             + 16
                             * CUtlVector<DecalBatchList_t,CUtlMemoryFixed<DecalBatchList_t,128,0>>::AddToTail(this: &meshList.m_aBatches));
    pBatch = v19;
    v19->m_iStartIndex = nIndexCount;
    if ( bWireframe_3 )
    {
      v19->m_pMaterial = g_materialDecalWireframe;
    }
    else
    {
      v20 = pDecalHead;
      v19->m_pMaterial = pDecalHead->material;
      v19->m_pProxy = v20->userdata;
      v19->m_iLightmapPage = materialSortInfoArray[v20->surfID->materialSortID].lightmapPageID;
    }
    bBatchInit = false;
    goto LABEL_54;
  }
  _Warning(a1: "R_DrawDecalsAll: overflowing m_aBatches. Reduce # of decals in the scene.\n");
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        v44 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        v44 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        v44 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        v44 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        v44 = 0;
        break;
      default:
        v44 = meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: v44);
  }
  meshBuilder.m_pMesh->UnlockMesh(
    this: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_pMesh = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  R_DrawDecalMeshList(a1: (int)v10, a2: (int)v12, &meshList);
  CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
}

//------------------------------------------------------------------------------
// Address: 0x10104950
// Name: void DecalSurfaceDraw_QueueHelper(bool,int,class Vector,int,struct decal_t __near * __near *,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DecalSurfaceDraw_QueueHelper(
        bool bBatched,
        int renderGroup,
        Vector vModelOrg,
        int nCheckCount,
        decal_t **ppDecals,
        int iPermanentLightmap,
        int iLightmap,
        decal_t **iNonLightmap,
        float flFade)
{
  IMatRenderContext *v9; // esi
  int v10; // ebx
  decal_t **v11; // edi
  decal_t **v12; // edi
  int v13; // ebx
  int v14; // edi
  decal_t **v15; // ebx
  decal_t **v16; // edi
  int v17; // ebx

  v9 = materials->GetRenderContext(this: materials);
  if ( v9 != nullptr )
    v9->BeginRender(this: v9);
  if ( bBatched )
  {
    v10 = iPermanentLightmap;
    v11 = ppDecals;
    R_DrawDecalsAll_Gathered(pRenderContext: v9, ppDecals, iDecalCount: iPermanentLightmap, &vModelOrg, flFade);
    v12 = &v11[v10];
    v13 = iLightmap;
    R_DrawDecalsAll_Gathered(pRenderContext: v9, ppDecals: v12, iDecalCount: iLightmap, &vModelOrg, flFade);
    R_DrawDecalsAll_Gathered(
      pRenderContext: v9,
      ppDecals: &v12[v13],
      iDecalCount: (int)iNonLightmap,
      &vModelOrg,
      flFade);
  }
  else
  {
    v14 = iPermanentLightmap;
    v15 = ppDecals;
    R_DrawDecalsAllImmediate_Gathered(
      m_nIndexCount: (int)ppDecals,
      a2: iPermanentLightmap,
      p_meshBuilder: (CMeshBuilder *)v9,
      pRenderContext: v9,
      ppDecals,
      iDecalCount: iPermanentLightmap,
      &vModelOrg,
      flFade);
    v16 = &v15[v14];
    v17 = iLightmap;
    R_DrawDecalsAllImmediate_Gathered(
      m_nIndexCount: iLightmap,
      a2: (int)v16,
      p_meshBuilder: (CMeshBuilder *)v9,
      pRenderContext: v9,
      ppDecals: v16,
      iDecalCount: iLightmap,
      &vModelOrg,
      flFade);
    R_DrawDecalsAllImmediate_Gathered(
      m_nIndexCount: v17,
      a2: (int)v16,
      p_meshBuilder: (CMeshBuilder *)v9,
      pRenderContext: v9,
      ppDecals: &v16[v17],
      iDecalCount: (int)iNonLightmap,
      &vModelOrg,
      flFade);
  }
  if ( v9 != nullptr )
  {
    v9->EndRender(this: v9);
    v9->Release(this: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10104A40
// Name: void DecalSurfaceDraw(class IMatRenderContext __near *,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DecalSurfaceDraw(IMatRenderContext *pRenderContext, IMatRenderContext *renderGroup, float flFade)
{
  CMeshBuilder *v3; // ebx
  IMatRenderContext *v4; // edi
  int m_nValue; // eax
  bool v6; // bl
  int v7; // ebx
  IMatRenderContext_vtbl *v8; // edx
  void *(__thiscall *LockRenderData)(IMatRenderContext *, int); // eax
  CMatRenderData<matrix3x4a_t> v10; // [esp+10h] [ebp-2Ch] BYREF
  CMatRenderData<unsigned char> rd; // [esp+20h] [ebp-1Ch] BYREF
  ICallQueue *pCallQueue; // [esp+30h] [ebp-Ch] BYREF
  decal_t **arg5; // [esp+34h] [ebp-8h] BYREF
  int nCheckCount; // [esp+38h] [ebp-4h] BYREF

  if ( r_drawdecals.m_pParent != nullptr && r_drawdecals.m_pParent->m_Value.m_nValue != 0 )
  {
    v3 = (CMeshBuilder *)g_nDecalSortCheckCount;
    v4 = renderGroup;
    rd.m_nCount = g_nDecalSortCheckCount;
    if ( renderGroup == (IMatRenderContext *)4 )
    {
      v3 = (CMeshBuilder *)g_nBrushModelDecalSortCheckCount;
      rd.m_nCount = g_nBrushModelDecalSortCheckCount;
    }
    if ( r_queued_decals.m_pParent != nullptr
      && r_queued_decals.m_pParent->m_Value.m_nValue != 0
      && (rd.m_pRenderContext = (IMatRenderContext *)pRenderContext->GetCallQueue(this: pRenderContext),
          rd.m_pRenderContext != nullptr) )
    {
      if ( r_drawbatchdecals.m_pParent != nullptr )
        m_nValue = r_drawbatchdecals.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      v6 = m_nValue != 0;
      HIBYTE(nCheckCount) = m_nValue != 0;
      if ( (_S1_11 & 1) == 0 )
      {
        _S1_11 |= 1u;
        DrawDecals.m_Memory.m_pMemory = nullptr;
        DrawDecals.m_Memory.m_nAllocationCount = 0;
        DrawDecals.m_Memory.m_nGrowSize = 0;
        DrawDecals.m_Size = 0;
        DrawDecals.m_pElements = nullptr;
        atexit(func: DecalSurfaceDraw_::_11_::_dynamic_atexit_destructor_for__DrawDecals__);
      }
      if ( v6 )
      {
        R_DrawDecalsAll_GatherDecals(pRenderContext, iGroup: (int)v4, iTreeType: 0, DrawDecals: &DrawDecals);
        arg5 = (decal_t **)DrawDecals.m_Size;
        R_DrawDecalsAll_GatherDecals(pRenderContext, iGroup: (int)v4, iTreeType: 1, DrawDecals: &DrawDecals);
        v7 = DrawDecals.m_Size - (_DWORD)arg5;
        *(_DWORD *)&rd.m_bNeedsUnlock = DrawDecals.m_Size - (_DWORD)arg5;
        R_DrawDecalsAll_GatherDecals(pRenderContext, iGroup: (int)v4, iTreeType: 2, DrawDecals: &DrawDecals);
      }
      else
      {
        R_DrawDecalsAllImmediate_GatherDecals(pRenderContext, iGroup: (int)v4, iTreeType: 0, DrawDecals: &DrawDecals);
        arg5 = (decal_t **)DrawDecals.m_Size;
        R_DrawDecalsAllImmediate_GatherDecals(pRenderContext, iGroup: (int)v4, iTreeType: 1, DrawDecals: &DrawDecals);
        v7 = DrawDecals.m_Size - (_DWORD)arg5;
        *(_DWORD *)&rd.m_bNeedsUnlock = DrawDecals.m_Size - (_DWORD)arg5;
        R_DrawDecalsAllImmediate_GatherDecals(pRenderContext, iGroup: (int)v4, iTreeType: 2, DrawDecals: &DrawDecals);
      }
      pCallQueue = (ICallQueue *)(DrawDecals.m_Size - v7 - (_DWORD)arg5);
      if ( DrawDecals.m_Size != 0 )
      {
        v8 = pRenderContext->__vftable;
        v10.m_nCount = 4 * DrawDecals.m_Size;
        LockRenderData = v8->LockRenderData;
        v10.m_pRenderContext = pRenderContext;
        v10.m_pRenderData = (matrix3x4a_t *)LockRenderData(this: pRenderContext, a2: 4 * DrawDecals.m_Size);
        v10.m_bNeedsUnlock = true;
        memcpy(
          dst: (unsigned __int8 *)v10.m_pRenderData,
          src: (unsigned __int8 *)DrawDecals.m_Memory.m_pMemory,
          count: 4 * DrawDecals.m_Size);
        rd.m_pRenderData = (unsigned __int8 *)v10.m_pRenderData;
        ICallQueue::QueueCall<void,bool,int,Vector,int,decal_t * *,int,int,int,float,bool,int,Vector,int,decal_t * *,int,int,int,float>(
          this: (ICallQueue *)rd.m_pRenderContext,
          pfnProxied: (void (__cdecl *)(bool, int, Vector, int, decal_t **, int, int, int, float))DecalSurfaceDraw_QueueHelper,
          arg1: (const bool *)&nCheckCount + 3,
          arg2: (const int *)&renderGroup,
          arg3: &modelorg,
          arg4: &rd.m_nCount,
          arg5: (decal_t **const *)&rd.m_pRenderData,
          arg6: (const int *)&arg5,
          arg7: (const int *)&rd.m_bNeedsUnlock,
          arg8: (const int *)&pCallQueue,
          arg9: &flFade);
        DrawDecals.m_Size = 0;
        CMatRenderData<memhandle_t__ *>::~CMatRenderData<memhandle_t__ *>(this: &v10);
      }
    }
    else
    {
      DecalSurfaceDraw_NonQueued(pRenderContext, renderGroup: v4, vModelOrg: &modelorg, nCheckCount: v3, flFade);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10104C40
// Name: R_DecalMaterialSort
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DecalMaterialSort(decal_t *pDecal, int surfID)
{
  decal_t *v2; // esi
  IMaterial *material; // eax
  int v4; // edx
  int v5; // ebx
  __int64 v6; // rax
  unsigned int v7; // ebx
  int v8; // edi
  DecalSortVertexFormat_t *m_pMemory; // ecx
  int m_Size; // esi
  int v11; // eax
  int v12; // esi
  int v13; // eax
  int v14; // esi
  DecalSortTrees_t *v15; // edx
  int v16; // eax
  DecalSortTrees_t *v17; // ecx
  int v18; // eax
  int v19; // ebx
  DecalSortTrees_t *v20; // ecx
  int v21; // eax
  DecalSortTrees_t *v22; // ebx
  int m_iSortTree; // edi
  bool (__thiscall *GetPropertyFlag)(IMaterial *, MaterialPropertyTypes_t); // edx
  int v25; // ebx
  CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl*)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int> > *v26; // ecx
  int v27; // eax
  int v28; // esi
  int v29; // edi
  int v30; // eax
  CUtlMemory<ResourceEntryInfo,int> *v31; // esi
  ResourceEntryInfo *v32; // ecx
  int v33; // eax
  int *v34; // esi
  int v35; // ecx
  int v36; // eax
  int v37; // edx
  int v38; // eax
  int v39; // eax
  int v40; // edx
  int v41; // ebx
  int v42; // edi
  int *v43; // esi
  int v44; // eax
  int v45; // ecx
  int v46; // eax
  int v47; // edi
  int v48; // eax
  int *v49; // esi
  int v50; // ecx
  int v51; // eax
  int v52; // eax
  int v53; // edx
  bool v54; // zf
  char *v55; // esi
  CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl*)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int> > *v56; // edi
  int v57; // eax
  int v58; // edx
  int v59; // ebx
  UtlRBTreeNode_t<DecalMaterialSortData_t,int> *v60; // ecx
  int v61; // ecx
  UtlRBTreeNode_t<DecalMaterialSortData_t,int> *v62; // edx
  UtlRBTreeNode_t<DecalMaterialSortData_t,int> *v63; // eax
  DecalMaterialSortData_t *p_m_Data; // ebx
  CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl*)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int> > *v65; // esi
  int v66; // eax
  int v67; // edx
  int v68; // edi
  UtlRBTreeNode_t<DecalMaterialSortData_t,int> *v69; // ecx
  int v70; // ecx
  UtlRBTreeNode_t<DecalMaterialSortData_t,int> *v71; // edx
  UtlRBTreeNode_t<DecalMaterialSortData_t,int> *v72; // eax
  DecalMaterialSortData_t *v73; // eax
  int m_iBucket; // ecx
  DecalMaterialSortData_t sort; // [esp+Ch] [ebp-24h] BYREF
  unsigned __int64 vertexFormat; // [esp+18h] [ebp-18h]
  int v77; // [esp+20h] [ebp-10h]
  int iSortTree; // [esp+24h] [ebp-Ch]
  int parent; // [esp+28h] [ebp-8h] BYREF
  int v80; // [esp+2Ch] [ebp-4h]

  v2 = pDecal;
  if ( pDecal->material->InMaterialPage(this: pDecal->material) )
    material = pDecal->material->GetMaterialPage(this: pDecal->material);
  else
    material = pDecal->material;
  v4 = *(__int16 *)(surfID + 18);
  sort.m_pMaterial = material;
  sort.m_iLightmapPage = materialSortInfoArray[v4].lightmapPageID;
  v6 = material->GetVertexFormat(this: material);
  v5 = v6;
  LODWORD(v6) = g_aDecalFormats.m_Size;
  v7 = v5 & 0xFFFFFBFF;
  v8 = 0;
  HIDWORD(vertexFormat) = HIDWORD(v6);
  if ( g_aDecalFormats.m_Size > 0 )
  {
    m_pMemory = g_aDecalFormats.m_Memory.m_pMemory;
    do
    {
      if ( m_pMemory->m_VertexFormat == __PAIR64__(HIDWORD(v6), v7) )
        break;
      ++v8;
      ++m_pMemory;
    }
    while ( v8 < g_aDecalFormats.m_Size );
  }
  if ( v8 == g_aDecalFormats.m_Size )
  {
    m_Size = g_aDecalFormats.m_Size;
    if ( g_aDecalFormats.m_Size + 1 > g_aDecalFormats.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CPortalRect,int>::Grow(
        this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)&g_aDecalFormats,
        num: g_aDecalFormats.m_Size - g_aDecalFormats.m_Memory.m_nAllocationCount + 1);
      v6 = __PAIR64__(HIDWORD(vertexFormat), g_aDecalFormats.m_Size);
    }
    g_aDecalFormats.m_Size = v6 + 1;
    v11 = v6 - m_Size;
    g_aDecalFormats.m_pElements = g_aDecalFormats.m_Memory.m_pMemory;
    if ( v11 > 0 )
    {
      _V_memmove(
        dest: &g_aDecalFormats.m_Memory.m_pMemory[m_Size + 1],
        src: &g_aDecalFormats.m_Memory.m_pMemory[m_Size],
        count: 16 * v11);
      HIDWORD(v6) = HIDWORD(vertexFormat);
    }
    v8 = m_Size;
    v12 = m_Size;
    LODWORD(g_aDecalFormats.m_Memory.m_pMemory[v12].m_VertexFormat) = v7;
    HIDWORD(g_aDecalFormats.m_Memory.m_pMemory[v12].m_VertexFormat) = HIDWORD(v6);
    v13 = g_aDecalSortTrees.m_Size;
    surfID = v12 * 16;
    v14 = g_aDecalSortTrees.m_Size;
    if ( g_aDecalSortTrees.m_Size + 1 > g_aDecalSortTrees.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<DecalSortTrees_t,int>::Grow(
        this: &g_aDecalSortTrees.m_Memory,
        num: g_aDecalSortTrees.m_Size - g_aDecalSortTrees.m_Memory.m_nAllocationCount + 1);
      v13 = g_aDecalSortTrees.m_Size;
    }
    v15 = g_aDecalSortTrees.m_Memory.m_pMemory;
    g_aDecalSortTrees.m_Size = v13 + 1;
    v16 = v13 - v14;
    g_aDecalSortTrees.m_pElements = g_aDecalSortTrees.m_Memory.m_pMemory;
    if ( v16 > 0 )
    {
      _V_memmove(
        dest: &g_aDecalSortTrees.m_Memory.m_pMemory[v14 + 1],
        src: &g_aDecalSortTrees.m_Memory.m_pMemory[v14],
        count: 312 * v16);
      v15 = g_aDecalSortTrees.m_Memory.m_pMemory;
    }
    v17 = &v15[v14];
    if ( v17 != nullptr )
      DecalSortTrees_t::DecalSortTrees_t(this: v17);
    v18 = g_aDispDecalSortTrees.m_Size;
    v19 = g_aDispDecalSortTrees.m_Size;
    if ( g_aDispDecalSortTrees.m_Size + 1 > g_aDispDecalSortTrees.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<DecalSortTrees_t,int>::Grow(
        this: &g_aDispDecalSortTrees.m_Memory,
        num: g_aDispDecalSortTrees.m_Size - g_aDispDecalSortTrees.m_Memory.m_nAllocationCount + 1);
      v18 = g_aDispDecalSortTrees.m_Size;
    }
    v20 = g_aDispDecalSortTrees.m_Memory.m_pMemory;
    g_aDispDecalSortTrees.m_Size = v18 + 1;
    v21 = v18 - v19;
    g_aDispDecalSortTrees.m_pElements = g_aDispDecalSortTrees.m_Memory.m_pMemory;
    if ( v21 > 0 )
    {
      _V_memmove(
        dest: &g_aDispDecalSortTrees.m_Memory.m_pMemory[v19 + 1],
        src: &g_aDispDecalSortTrees.m_Memory.m_pMemory[v19],
        count: 312 * v21);
      v20 = g_aDispDecalSortTrees.m_Memory.m_pMemory;
    }
    v22 = &v20[v19];
    if ( v22 != nullptr )
      DecalSortTrees_t::DecalSortTrees_t(this: v22);
    *(int *)((char *)&g_aDecalFormats.m_Memory.m_pMemory->m_iSortTree + surfID) = v14;
    v2 = pDecal;
  }
  m_iSortTree = g_aDecalFormats.m_Memory.m_pMemory[v8].m_iSortTree;
  GetPropertyFlag = sort.m_pMaterial->GetPropertyFlag;
  iSortTree = m_iSortTree;
  if ( GetPropertyFlag(this: sort.m_pMaterial, a2: MATERIAL_PROPERTY_NEEDS_LIGHTMAP) )
  {
    v25 = (v2->flags & 1) == 0;
    surfID = v25;
  }
  else
  {
    surfID = 2;
    v25 = 2;
    sort.m_iLightmapPage = -1;
  }
  v26 = g_aDecalSortTrees.m_Memory.m_pMemory[m_iSortTree].m_pTrees[v25];
  HIDWORD(vertexFormat) = 312 * m_iSortTree;
  v27 = CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl *)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int>>::Find(
          this: v26,
          search: &sort);
  if ( v27 == -1 )
  {
    v28 = 312 * m_iSortTree + 20 * v25;
    v29 = *(int *)((char *)&g_aDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets[0][0].m_Size + v28);
    v30 = *(int *)((char *)&g_aDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets[0][0].m_Memory.m_nAllocationCount
                 + v28);
    v80 = v28;
    v31 = (CUtlMemory<ResourceEntryInfo,int> *)((char *)g_aDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets + v28);
    parent = v29;
    if ( v29 + 1 > v30 )
      CUtlMemory<CAsyncWavDataCache::DeadBufferEntry_t,int>::Grow(this: v31, num: v29 - v30 + 1);
    ++v31[1].m_pMemory;
    v32 = v31->m_pMemory;
    v33 = (int)v31[1].m_pMemory - v29 - 1;
    v31[1].m_nAllocationCount = (int)v31->m_pMemory;
    if ( v33 > 0 )
      _V_memmove(dest: &v32[v29 + 1], src: &v32[v29], count: 8 * v33);
    v34 = (int *)((char *)g_aDispDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets + v80);
    v36 = *(int *)((char *)&g_aDispDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets[0][0].m_Memory.m_nAllocationCount
                 + v80);
    v77 = *(int *)((char *)&g_aDispDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets[0][0].m_Size + v80);
    v35 = v77;
    if ( v77 + 1 > v36 )
    {
      CUtlMemory<CAsyncWavDataCache::DeadBufferEntry_t,int>::Grow(
        this: (CUtlMemory<ResourceEntryInfo,int> *)((char *)g_aDispDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets + v80),
        num: v77 - v36 + 1);
      v35 = v77;
    }
    ++v34[3];
    v37 = *v34;
    v38 = v34[3] - v35 - 1;
    v34[4] = *v34;
    if ( v38 > 0 )
      _V_memmove(dest: (void *)(v37 + 8 * v35 + 8), src: (const void *)(v37 + 8 * v35), count: 8 * v38);
    v39 = v80;
    (*(DecalMaterialBucket_t **)((char *)&g_aDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets[0][0].m_Memory.m_pMemory
                               + v80))[v29].m_nCheckCount = -1;
    v40 = HIDWORD(vertexFormat);
    (*(DecalMaterialBucket_t **)((char *)&g_aDispDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets[0][0].m_Memory.m_pMemory
                               + v39))[v29].m_nCheckCount = -1;
    v41 = v40 + 4 * (5 * v25 + 15);
    v80 = 4;
    do
    {
      v42 = *(int *)((char *)&g_aDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets[0][0].m_Size + v41);
      v43 = (int *)((char *)g_aDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets + v41);
      v44 = *(int *)((char *)&g_aDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets[0][0].m_Memory.m_nAllocationCount
                   + v41);
      if ( v42 + 1 > v44 )
        CUtlMemory<CAsyncWavDataCache::DeadBufferEntry_t,int>::Grow(
          this: (CUtlMemory<ResourceEntryInfo,int> *)((char *)g_aDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets + v41),
          num: v42 - v44 + 1);
      ++v43[3];
      v45 = *v43;
      v46 = v43[3] - v42 - 1;
      v43[4] = *v43;
      if ( v46 > 0 )
        _V_memmove(dest: (void *)(v45 + 8 * v42 + 8), src: (const void *)(v45 + 8 * v42), count: 8 * v46);
      v47 = *(int *)((char *)&g_aDispDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets[0][0].m_Size + v41);
      v48 = *(int *)((char *)&g_aDispDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets[0][0].m_Memory.m_nAllocationCount
                   + v41);
      v49 = (int *)((char *)g_aDispDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets + v41);
      if ( v47 + 1 > v48 )
        CUtlMemory<CAsyncWavDataCache::DeadBufferEntry_t,int>::Grow(
          this: (CUtlMemory<ResourceEntryInfo,int> *)((char *)g_aDispDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets
                                              + v41),
          num: v47 - v48 + 1);
      ++v49[3];
      v50 = *v49;
      v51 = v49[3] - v47 - 1;
      v49[4] = *v49;
      if ( v51 > 0 )
        _V_memmove(dest: (void *)(v50 + 8 * v47 + 8), src: (const void *)(v50 + 8 * v47), count: 8 * v51);
      v52 = parent;
      (*(DecalMaterialBucket_t **)((char *)&g_aDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets[0][0].m_Memory.m_pMemory
                                 + v41))[parent].m_nCheckCount = -1;
      v53 = *(int *)((char *)&g_aDispDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets[0][0].m_Memory.m_pMemory
                   + v41);
      v41 += 60;
      v54 = v80-- == 1;
      *(_DWORD *)(v53 + 8 * v52 + 4) = -1;
    }
    while ( !v54 );
    sort.m_iBucket = v52;
    v55 = (char *)(4 * (surfID + 78 * iSortTree));
    v56 = *(CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl*)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int> > **)&v55[(unsigned int)g_aDecalSortTrees.m_Memory.m_pMemory];
    parent = -1;
    HIBYTE(surfID) = 0;
    CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl *)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int>>::FindInsertionPosition(
      this: v56,
      insert: &sort,
      &parent,
      leftchild: (bool *)&surfID + 3);
    v57 = CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl *)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int>>::NewNode(this: v56);
    v58 = parent;
    v59 = v57;
    v60 = &v56->m_Elements.m_pMemory[v57];
    v60->m_Parent = parent;
    v60->m_Right = -1;
    v60->m_Left = -1;
    v60->m_Tag = 0;
    if ( v58 == -1 )
    {
      v56->m_Root = v57;
    }
    else
    {
      v61 = v58;
      v62 = v56->m_Elements.m_pMemory;
      if ( HIBYTE(surfID) != 0 )
        v62[v61].m_Left = v57;
      else
        v62[v61].m_Right = v57;
    }
    CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl *)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int>>::InsertRebalance(
      this: v56,
      elem: v57);
    v63 = v56->m_Elements.m_pMemory;
    ++v56->m_NumElements;
    p_m_Data = &v63[v59].m_Data;
    if ( p_m_Data != nullptr )
      *p_m_Data = sort;
    v65 = *(CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl*)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int> > **)&v55[(unsigned int)g_aDispDecalSortTrees.m_Memory.m_pMemory];
    parent = -1;
    HIBYTE(surfID) = 0;
    CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl *)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int>>::FindInsertionPosition(
      this: v65,
      insert: &sort,
      &parent,
      leftchild: (bool *)&surfID + 3);
    v66 = CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl *)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int>>::NewNode(this: v65);
    v67 = parent;
    v68 = v66;
    v69 = &v65->m_Elements.m_pMemory[v66];
    v69->m_Parent = parent;
    v69->m_Right = -1;
    v69->m_Left = -1;
    v69->m_Tag = 0;
    if ( v67 == -1 )
    {
      v65->m_Root = v66;
    }
    else
    {
      v70 = v67;
      v71 = v65->m_Elements.m_pMemory;
      if ( HIBYTE(surfID) != 0 )
        v71[v70].m_Left = v66;
      else
        v71[v70].m_Right = v66;
    }
    CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl *)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int>>::InsertRebalance(
      this: v65,
      elem: v66);
    v72 = v65->m_Elements.m_pMemory;
    ++v65->m_NumElements;
    v73 = &v72[v68].m_Data;
    if ( v73 != nullptr )
      *v73 = sort;
    m_iBucket = sort.m_iBucket;
    pDecal->m_iSortTree = iSortTree;
    pDecal->m_iSortMaterial = m_iBucket;
  }
  else
  {
    pDecal->m_iSortTree = m_iSortTree;
    pDecal->m_iSortMaterial = g_aDecalSortTrees.m_Memory.m_pMemory[m_iSortTree].m_pTrees[v25]->m_Elements.m_pMemory[v27].m_Data.m_iBucket;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101051E0
// Name: R_DecalCreate
// Source: json
//------------------------------------------------------------------------------
void __usercall R_DecalCreate(
        decalinfo_t *decalinfo@<edi>,
        msurface2_t *surfID,
        float x,
        float y,
        bool bForceForDisplacement)
{
  decal_t *OverlappingDecals; // eax
  decal_t *v6; // esi
  CClientState *BaseLocalClient; // eax

  if ( surfID != nullptr )
  {
    OverlappingDecals = R_DecalFindOverlappingDecals(decalinfo, surfID);
    if ( OverlappingDecals != nullptr )
      R_DecalUnlink(pdecal: OverlappingDecals);
    v6 = R_DecalAlloc(flags: decalinfo->m_Flags);
    v6->flags = decalinfo->m_Flags;
    v6->color = decalinfo->m_Color;
    v6->position = decalinfo->m_Position;
    if ( SLOBYTE(v6->flags) < 0 )
      v6->saxis = decalinfo->m_SAxis;
    v6->dx = x;
    v6->dy = y;
    v6->material = decalinfo->m_pMaterial;
    v6->userdata = decalinfo->m_pUserData;
    v6->scale = decalinfo->m_scale;
    v6->entityIndex = decalinfo->m_Entity;
    if ( decalinfo->m_flFadeDuration > 0.0 )
    {
      v6->flags |= 0x100u;
      v6->fadeDuration = decalinfo->m_flFadeDuration;
      v6->fadeStartTime = decalinfo->m_flFadeStartTime;
      BaseLocalClient = GetBaseLocalClient();
      v6->fadeStartTime = CClientState::GetTime(this: BaseLocalClient) + v6->fadeStartTime;
    }
    if ( (v6->flags & 0x1000) != 0 )
    {
      v6->fadeStartTime = 0.0;
      v6->scale = 1.0;
    }
    if ( bForceForDisplacement
      || (R_DecalVertsClip(pOutVerts: nullptr, pDecal: v6, surfID, pMaterial: decalinfo->m_pMaterial),
          v6->clippedVertCount != 0) )
    {
      R_AddDecalToSurface(pdecal: v6, decalinfo, surfID);
      R_DecalMaterialSort(pDecal: v6, (int)surfID);
    }
    else
    {
      R_DecalUnlink(pdecal: v6);
    }
  }
  else
  {
    ConMsg(a1: "psurface NULL in R_DecalCreate!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10105330
// Name: void R_DecalSurface(struct msurface2_t __near *,struct decalinfo_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DecalSurface(msurface2_t *surfID, decalinfo_t *decalinfo, bool bForceForDisplacement)
{
  const Vector *m_pNormal; // ecx
  float v5; // xmm0_4
  float x; // xmm2_4
  float z; // xmm1_4
  float *v8; // esi
  bool v9; // zf
  Vector *p_m_SAxis; // ecx
  double v11; // st7
  double v12; // st5
  double v13; // st4
  double v14; // st3
  double m_decalWidth; // st2
  long double v16; // rt0
  double v17; // st1
  double v18; // st7
  double v19; // st6
  long double v20; // rt1
  long double v21; // st6
  double v22; // st5
  long double v23; // st6
  msurface1_t *v24; // ecx
  float v25; // [esp+0h] [ebp-28h]
  float v26; // [esp+4h] [ebp-24h]
  float ya; // [esp+10h] [ebp-18h]
  float y; // [esp+10h] [ebp-18h]
  float m_decalHeight; // [esp+14h] [ebp-14h]
  float v30; // [esp+14h] [ebp-14h]
  float v31; // [esp+18h] [ebp-10h]
  float w; // [esp+1Ch] [ebp-Ch]
  float h; // [esp+20h] [ebp-8h]
  float v34; // [esp+24h] [ebp-4h]
  float v35; // [esp+24h] [ebp-4h]
  float v36; // [esp+34h] [ebp+Ch]
  float v37; // [esp+34h] [ebp+Ch]

  m_pNormal = decalinfo->m_pNormal;
  if ( m_pNormal == nullptr
    || (float)((float)((float)(m_pNormal->y * surfID->plane->normal.y) + (float)(m_pNormal->x * surfID->plane->normal.x))
             + (float)(m_pNormal->z * surfID->plane->normal.z)) >= 0.0 )
  {
    v5 = decalinfo->m_Position.y;
    x = decalinfo->m_Position.x;
    z = decalinfo->m_Position.z;
    v8 = (float *)&host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1];
    v9 = SLOBYTE(decalinfo->m_Flags) >= 0;
    v36 = (float)((float)((float)((float)(*v8 * decalinfo->m_Position.x) + (float)(v8[1] * v5)) + (float)(v8[2] * z))
                + v8[3])
        - (float)host_state.worldbrush->surfaces1[surfID - host_state.worldbrush->surfaces2].textureMins[0];
    v34 = (float)((float)((float)((float)(v5 * v8[5]) + (float)(v8[4] * x)) + (float)(z * v8[6])) + v8[7])
        - (float)host_state.worldbrush->surfaces1[surfID - host_state.worldbrush->surfaces2].textureMins[1];
    if ( v9 )
      p_m_SAxis = nullptr;
    else
      p_m_SAxis = &decalinfo->m_SAxis;
    R_DecalComputeBasis(surfaceNormal: &surfID->plane->normal, pSAxis: p_m_SAxis, textureSpaceBasis: decalinfo->m_Basis);
    v11 = v8[1];
    v12 = *v8;
    h = decalinfo->m_Basis[0].y;
    v13 = decalinfo->m_Basis[0].z;
    v14 = v8[2];
    m_decalWidth = (double)decalinfo->m_decalWidth;
    v31 = decalinfo->m_Basis[1].y;
    w = decalinfo->m_Basis[1].x;
    m_decalHeight = (float)decalinfo->m_decalHeight;
    v16 = fabs((decalinfo->m_Basis[0].x * v12 + h * v11 + v13 * v14) * m_decalWidth);
    v17 = v11 * v31 + v12 * w;
    v18 = decalinfo->m_Basis[1].z;
    ya = v16;
    y = fabs((v14 * v18 + v17) * m_decalHeight) + ya;
    v19 = v8[6];
    v20 = fabs(m_decalWidth * (decalinfo->m_Basis[0].x * v8[4] + h * v8[5] + v13 * v19));
    v21 = fabs((v19 * v18 + v8[5] * v31 + v8[4] * w) * m_decalHeight);
    v30 = v20 + v21;
    v22 = v36 - y * 0.5;
    v37 = v22;
    v23 = v34 - 0.5 * (v20 + v21);
    if ( bForceForDisplacement
      || (float)-y < v37
      && (v35 = v23, (float)-v30 < v35)
      && (v24 = &host_state.worldbrush->surfaces1[surfID - host_state.worldbrush->surfaces2],
          v37 <= (float)((float)v24->textureExtents[0] + y))
      && v35 <= (float)((float)v24->textureExtents[1] + v30) )
    {
      v26 = v23;
      v25 = v22;
      R_DecalCreate(decalinfo, surfID, x: v25, y: v26, bForceForDisplacement);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101055B0
// Name: R_DecalNodeSurfaces
// Source: json
//------------------------------------------------------------------------------
void __usercall R_DecalNodeSurfaces(decalinfo_t *decalinfo@<eax>, mnode_t *node)
{
  worldbrushdata_t *worldbrush; // eax
  msurface2_t *v4; // ebx
  const Vector *m_pNormal; // ecx
  float *v6; // esi
  int v7; // edx
  msurface1_t *surfaces1; // eax
  int v9; // edx
  Vector *p_m_SAxis; // ecx
  double v11; // st7
  double v12; // st5
  double z; // st4
  double v14; // st3
  double m_decalWidth; // st2
  long double v16; // rt0
  double v17; // st1
  double v18; // st7
  double v19; // st6
  long double v20; // rt1
  long double v21; // st6
  long double v22; // st7
  msurface1_t *v23; // ecx
  float v24; // [esp-Ch] [ebp-34h]
  float v25; // [esp+8h] [ebp-20h]
  float v26; // [esp+8h] [ebp-20h]
  int v27; // [esp+Ch] [ebp-1Ch]
  float m_decalHeight; // [esp+10h] [ebp-18h]
  float v29; // [esp+10h] [ebp-18h]
  float x; // [esp+14h] [ebp-14h]
  float y; // [esp+18h] [ebp-10h]
  int i; // [esp+1Ch] [ebp-Ch]
  float v33; // [esp+20h] [ebp-8h]
  float v34; // [esp+20h] [ebp-8h]
  float v35; // [esp+24h] [ebp-4h]
  float v36; // [esp+24h] [ebp-4h]

  worldbrush = host_state.worldbrush;
  v4 = &host_state.worldbrush->surfaces2[node->firstsurface];
  v27 = 0;
  if ( node->numsurfaces != 0 )
  {
    do
    {
      if ( (v4->flags & 0x4000) == 0 && (v4->flags & 0x800) == 0 )
      {
        m_pNormal = decalinfo->m_pNormal;
        if ( m_pNormal == nullptr
          || (float)((float)((float)(m_pNormal->y * v4->plane->normal.y) + (float)(v4->plane->normal.x * m_pNormal->x))
                   + (float)(m_pNormal->z * v4->plane->normal.z)) >= 0.0 )
        {
          v6 = (float *)&worldbrush->texinfo[*((unsigned __int16 *)v4 + 11) >> 1];
          v7 = (char *)v4 - (char *)worldbrush->surfaces2;
          surfaces1 = worldbrush->surfaces1;
          v9 = v7 >> 5;
          v33 = (float)((float)((float)((float)(decalinfo->m_Position.x * *v6) + (float)(decalinfo->m_Position.y * v6[1]))
                              + (float)(decalinfo->m_Position.z * v6[2]))
                      + v6[3])
              - (float)surfaces1[v9].textureMins[0];
          v35 = (float)((float)((float)((float)(decalinfo->m_Position.x * v6[4])
                                      + (float)(decalinfo->m_Position.y * v6[5]))
                              + (float)(decalinfo->m_Position.z * v6[6]))
                      + v6[7])
              - (float)surfaces1[v9].textureMins[1];
          if ( SLOBYTE(decalinfo->m_Flags) >= 0 )
            p_m_SAxis = nullptr;
          else
            p_m_SAxis = &decalinfo->m_SAxis;
          R_DecalComputeBasis(
            surfaceNormal: &v4->plane->normal,
            pSAxis: p_m_SAxis,
            textureSpaceBasis: decalinfo->m_Basis);
          v11 = v6[1];
          v12 = *v6;
          i = SLODWORD(decalinfo->m_Basis[0].y);
          z = decalinfo->m_Basis[0].z;
          v14 = v6[2];
          m_decalWidth = (double)decalinfo->m_decalWidth;
          y = decalinfo->m_Basis[1].y;
          x = decalinfo->m_Basis[1].x;
          m_decalHeight = (float)decalinfo->m_decalHeight;
          v16 = fabs((decalinfo->m_Basis[0].x * v12 + *(float *)&i * v11 + z * v14) * m_decalWidth);
          v17 = v11 * y + v12 * x;
          v18 = decalinfo->m_Basis[1].z;
          v25 = v16;
          v26 = fabs((v14 * v18 + v17) * m_decalHeight) + v25;
          v19 = v6[6];
          v20 = fabs(m_decalWidth * (decalinfo->m_Basis[0].x * v6[4] + *(float *)&i * v6[5] + z * v19));
          v21 = fabs((v19 * v18 + v6[4] * x + v6[5] * y) * m_decalHeight);
          v29 = v20 + v21;
          v22 = v35 - (v20 + v21) * 0.5;
          v34 = v33 - (float)(v26 * 0.5);
          if ( (float)-v26 >= v34 || (v36 = v22, (float)-v29 >= v36) )
          {
            worldbrush = host_state.worldbrush;
          }
          else
          {
            worldbrush = host_state.worldbrush;
            v23 = &host_state.worldbrush->surfaces1[v4 - host_state.worldbrush->surfaces2];
            if ( v34 <= (float)((float)v23->textureExtents[0] + v26)
              && v36 <= (float)((float)v23->textureExtents[1] + v29) )
            {
              v24 = v22;
              R_DecalCreate(decalinfo, surfID: v4, x: v34, y: v24, bForceForDisplacement: false);
              worldbrush = host_state.worldbrush;
            }
          }
        }
      }
      ++v4;
      ++v27;
    }
    while ( v27 < node->numsurfaces );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10105870
// Name: void R_DecalLeaf(struct mleaf_t __near *,struct decalinfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DecalLeaf(mleaf_t *pLeaf, decalinfo_t *decalinfo)
{
  mleaf_t *v2; // ecx
  worldbrushdata_t *worldbrush; // eax
  int v4; // edi
  msurface2_t *v5; // esi
  int m_Size; // edx
  int v7; // eax
  msurface2_t **m_pMemory; // ecx
  float *p_x; // eax
  int v10; // edi
  IDispInfo *v11; // esi
  float v12; // xmm0_4
  msurface2_t *v13; // eax
  Vector bbMin; // [esp+Ch] [ebp-1Ch] BYREF
  Vector bbMax; // [esp+18h] [ebp-10h] BYREF
  msurface2_t **pHandle; // [esp+24h] [ebp-4h]

  v2 = pLeaf;
  worldbrush = host_state.worldbrush;
  pHandle = &host_state.worldbrush->marksurfaces[pLeaf->firstmarksurface];
  v4 = 0;
  if ( pLeaf->nummarksurfaces != 0 )
  {
    do
    {
      v5 = pHandle[v4];
      if ( (v5->flags & 0x4002) == 0 )
      {
        m_Size = decalinfo->m_aApplySurfs.m_Size;
        v7 = 0;
        if ( m_Size <= 0 )
          goto LABEL_9;
        m_pMemory = decalinfo->m_aApplySurfs.m_Memory.m_pMemory;
        while ( *m_pMemory != v5 )
        {
          ++v7;
          ++m_pMemory;
          if ( v7 >= m_Size )
            goto LABEL_9;
        }
        if ( v7 == -1 )
        {
LABEL_9:
          p_x = &v5->plane->normal.x;
          if ( fabs(
                 p_x[1] * decalinfo->m_Position.y
               + *p_x * decalinfo->m_Position.x
               + p_x[2] * decalinfo->m_Position.z
               - p_x[3]) < 4.0 )
            R_DecalSurface(surfID: v5, decalinfo, bForceForDisplacement: false);
        }
      }
      v2 = pLeaf;
      ++v4;
    }
    while ( v4 < pLeaf->nummarksurfaces );
    worldbrush = host_state.worldbrush;
  }
  v10 = 0;
  if ( v2->dispCount != 0 )
  {
    while ( 1 )
    {
      v11 = DispInfo_IndexArray(
              hArray: (_DWORD *)worldbrush->hDispInfos,
              iElement: worldbrush->m_pDispInfoReferences[v10 + pLeaf->dispListStart]);
      if ( (v11->GetParent(this: v11)->flags & 0x4000) == 0 && !v11->GetTag(this: v11) )
      {
        v11->SetTag(this: v11);
        v11->GetBoundingBox(this: v11, a2: &bbMin, a3: &bbMax);
        v12 = decalinfo->m_Size;
        if ( bbMax.x > (float)(decalinfo->m_Position.x - v12)
          && (float)(v12 + decalinfo->m_Position.x) > bbMin.x
          && bbMax.y > (float)(decalinfo->m_Position.y - v12)
          && (float)(v12 + decalinfo->m_Position.y) > bbMin.y
          && bbMax.z > (float)(decalinfo->m_Position.z - v12)
          && (float)(v12 + decalinfo->m_Position.z) > bbMin.z )
        {
          v13 = v11->GetParent(this: v11);
          R_DecalSurface(surfID: v13, decalinfo, bForceForDisplacement: true);
        }
      }
      if ( ++v10 >= pLeaf->dispCount )
        break;
      worldbrush = host_state.worldbrush;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10105A30
// Name: R_DecalNode
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DecalNode(mnode_t *node, decalinfo_t *decalinfo)
{
  mnode_t *v2; // esi
  float v3; // xmm0_4
  float m_Size; // xmm1_4

  v2 = node;
  if ( node != nullptr )
  {
    while ( v2->contents < 0 )
    {
      v3 = (float)((float)((float)(v2->plane->normal.y * decalinfo->m_Position.y)
                         + (float)(v2->plane->normal.x * decalinfo->m_Position.x))
                 + (float)(v2->plane->normal.z * decalinfo->m_Position.z))
         - v2->plane->dist;
      m_Size = decalinfo->m_Size;
      if ( v3 <= m_Size )
      {
        if ( COERCE_FLOAT(LODWORD(m_Size) ^ _mask__NegFloat_) <= v3 )
        {
          if ( v3 < 4.0 && v3 > -4.0 )
            R_DecalNodeSurfaces(decalinfo, node: v2);
          R_DecalNode(node: v2->children[0], decalinfo);
        }
        v2 = v2->children[1];
      }
      else
      {
        v2 = v2->children[0];
      }
      if ( v2 == nullptr )
        return;
    }
    R_DecalLeaf(pLeaf: (mleaf_t *)v2, decalinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10105AE0
// Name: R_DecalShoot_
// Source: json
//------------------------------------------------------------------------------
void __usercall R_DecalShoot_(
        IMaterial *pMaterial@<esi>,
        const Vector *position@<eax>,
        const Vector *saxis@<edx>,
        int a4@<ebx>,
        int a5@<edi>,
        int entity,
        model_t *model,
        int flags,
        const color32_s *rgbaColor,
        const Vector *pNormal,
        void *userdata)
{
  int v11; // ebx
  float z; // xmm0_4
  worldbrushdata_t *pShared; // eax
  IMaterial_vtbl *v14; // eax
  int (__thiscall *GetMappingWidth)(IMaterial *); // edx
  int v16; // eax
  int (__thiscall *GetMappingHeight)(IMaterial *); // edx
  IMaterialVar *v18; // eax
  IMaterialVar *v19; // eax
  IUniformRandomStream *v20; // ecx
  double v21; // st7
  float v22; // xmm0_4
  float v23; // xmm1_4
  IMaterialVar *(__thiscall *FindVarFast)(IMaterial *, const char *, unsigned int *); // eax
  int v25; // eax
  IMaterialVar *v26; // eax
  float v27; // xmm0_4
  int (__thiscall *v28)(IMaterial *); // eax
  float v29; // xmm0_4
  color32_s v30; // eax
  decalinfo_t decalinfo; // [esp+20h] [ebp-8Ch] BYREF
  float v33; // [esp+A8h] [ebp-4h]
  float v34; // [esp+B8h] [ebp+Ch]

  v11 = flags;
  decalinfo.m_Position.x = position->x;
  decalinfo.m_Position.y = position->y;
  z = position->z;
  memset(&decalinfo.m_aApplySurfs, 0, sizeof(decalinfo.m_aApplySurfs));
  decalinfo.m_Position.z = z;
  if ( model != nullptr && model->type == mod_brush && pMaterial != nullptr )
  {
    pShared = model->brush.pShared;
    decalinfo.m_pModel = model;
    decalinfo.m_pBrush = pShared;
    if ( saxis != nullptr )
    {
      decalinfo.m_SAxis = *saxis;
      v11 = flags | 0x80;
    }
    v14 = pMaterial->__vftable;
    decalinfo.m_pUserData = userdata;
    decalinfo.m_Entity = entity;
    GetMappingWidth = v14->GetMappingWidth;
    decalinfo.m_pMaterial = pMaterial;
    decalinfo.m_Flags = v11;
    v16 = ((int (__thiscall *)(IMaterial *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))GetMappingWidth)(
            a1: pMaterial,
            a2: a5,
            a3: a4,
            a4: LODWORD(decalinfo.m_Position.x),
            a5: LODWORD(decalinfo.m_Position.y),
            a6: LODWORD(decalinfo.m_Position.z),
            a7: LODWORD(decalinfo.m_SAxis.x),
            a8: LODWORD(decalinfo.m_SAxis.y),
            a9: LODWORD(decalinfo.m_SAxis.z));
    GetMappingHeight = pMaterial->GetMappingHeight;
    decalinfo.m_Size = (float)(v16 >> 1);
    if ( (float)(GetMappingHeight(this: pMaterial) >> 1) > decalinfo.m_Size )
      decalinfo.m_Size = (float)(pMaterial->GetMappingHeight(this: pMaterial) >> 1);
    v34 = 1.0;
    v18 = decalinfo.m_pMaterial->FindVarFast(this: decalinfo.m_pMaterial, a2: "$decalScale", a3: &s_DecalScaleVarCache);
    if ( v18 != nullptr )
      v34 = v18->GetFloatValueInternal(this: v18);
    v19 = decalinfo.m_pMaterial->FindVarFast(
            this: decalinfo.m_pMaterial,
            a2: "$decalScaleVariation",
            a3: &s_DecalScaleVariationVarCache);
    if ( v19 != nullptr )
    {
      v21 = ((double (__thiscall *)(IMaterialVar *))v19->GetFloatValueInternal)(a1: v19);
      v33 = v21;
      if ( v21 >= 0.0 )
      {
        v22 = v33;
        if ( v33 > 0.99000001 )
          v22 = 0.99000001;
      }
      else
      {
        v22 = 0.0;
      }
      v33 = v22;
      v34 = (_RandomFloat(this: v20, a2: COERCE_FLOAT(LODWORD(v22) ^ _mask__NegFloat_), a3: v22) + 1.0) * v34;
    }
    v23 = 1.0;
    if ( v34 != 1.0 && v34 != 0.0 )
    {
      v23 = 1.0 / v34;
      decalinfo.m_Size = v34 * decalinfo.m_Size;
    }
    FindVarFast = pMaterial->FindVarFast;
    decalinfo.m_scale = v23;
    decalinfo.m_flFadeDuration = 0.0;
    v25 = (int)FindVarFast(this: pMaterial, a2: "$decalFadeDuration", a3: &s_DecalFadeVarCache_0);
    if ( v25 != 0 )
    {
      decalinfo.m_flFadeDuration = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v25 + 112))(a1: v25);
      v26 = pMaterial->FindVarFast(this: pMaterial, a2: "$decalFadeTime", a3: &s_DecalFadeTimeVarCache);
      if ( v26 != nullptr )
        decalinfo.m_flFadeStartTime = v26->GetFloatValueInternal(this: v26);
      else
        decalinfo.m_flFadeStartTime = 0.0;
    }
    if ( pMaterial->FindVarFast(this: pMaterial, a2: "$decalSecondPass", a3: &s_DecalSecondPassVarCache) != nullptr )
      decalinfo.m_Flags |= 0x200u;
    v27 = (float)pMaterial->GetMappingWidth(this: pMaterial) / decalinfo.m_scale;
    v28 = pMaterial->GetMappingHeight;
    decalinfo.m_decalWidth = (int)v27;
    v29 = (float)v28(this: pMaterial) / decalinfo.m_scale;
    v30 = *rgbaColor;
    decalinfo.m_decalHeight = (int)v29;
    decalinfo.m_pNormal = pNormal;
    decalinfo.m_Color = v30;
    CUtlVector<msurface2_t *,CUtlMemory<msurface2_t *,int>>::Purge(this: &decalinfo.m_aApplySurfs);
    DispInfo_ClearAllTags(hArray: (_DWORD *)decalinfo.m_pBrush->hDispInfos);
    R_DecalNode(node: &decalinfo.m_pBrush->nodes[decalinfo.m_pModel->brush.firstnode], &decalinfo);
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&decalinfo.m_aApplySurfs);
}

//------------------------------------------------------------------------------
// Address: 0x10105DC0
// Name: void R_DecalShoot(int,int,struct model_t const __near *,class Vector const __near &,class Vector const __near *,int,struct color32_s const __near &,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall R_DecalShoot(
        int a1@<ebx>,
        int a2@<edi>,
        int textureIndex,
        int entity,
        model_t *model,
        const Vector *position,
        const Vector *saxis,
        int flags,
        const color32_s *rgbaColor,
        const Vector *pNormal)
{
  IMaterial *v10; // eax

  v10 = Draw_DecalMaterial(index: textureIndex);
  R_DecalShoot_(
    pMaterial: v10,
    position,
    saxis,
    a4: a1,
    a5: a2,
    entity,
    model,
    flags,
    rgbaColor,
    pNormal,
    userdata: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10105E00
// Name: void R_PlayerDecalShoot(class IMaterial __near *,void __near *,int,struct model_t const __near *,class Vector const __near &,class Vector const __near *,int,struct color32_s const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_PlayerDecalShoot(
        IMaterial *material,
        void *userdata,
        int entity,
        model_t *model,
        const Vector *position,
        const Vector *saxis,
        int flags,
        const color32_s *rgbaColor)
{
  int v8; // eax
  decal_t **m_pMemory; // ebx
  int m_nAllocationCount; // edx
  int m_Size; // esi
  decal_t *v12; // ecx
  int v13; // edi
  decal_t **v14; // edi
  int j; // edi
  CUtlVector<decal_t *,CUtlMemory<decal_t *,int> > decalVec; // [esp+Ch] [ebp-1Ch] BYREF
  int i; // [esp+20h] [ebp-8h]
  decal_t *decal; // [esp+24h] [ebp-4h]

  v8 = 0;
  m_pMemory = nullptr;
  m_nAllocationCount = 0;
  m_Size = 0;
  memset(&decalVec, 0, sizeof(decalVec));
  i = 0;
  if ( s_aDecalPool.m_Size > 0 )
  {
    while ( 1 )
    {
      v12 = s_aDecalPool.m_Memory.m_pMemory[v8];
      decal = v12;
      if ( v12 != nullptr && (v12->flags & 0x1000) != 0 && v12->userdata == userdata )
      {
        v13 = m_Size;
        if ( m_Size + 1 > m_nAllocationCount )
        {
          CUtlMemory<INetMessage *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)&decalVec,
            num: m_Size - m_nAllocationCount + 1);
          m_Size = decalVec.m_Size;
          m_pMemory = decalVec.m_Memory.m_pMemory;
          v12 = decal;
        }
        decalVec.m_Size = ++m_Size;
        decalVec.m_pElements = m_pMemory;
        if ( m_Size - v13 - 1 > 0 )
        {
          _V_memmove(dest: &m_pMemory[v13 + 1], src: &m_pMemory[v13], count: 4 * (m_Size - v13 - 1));
          v12 = decal;
        }
        v14 = &m_pMemory[v13];
        if ( v14 != nullptr )
          *v14 = v12;
      }
      v8 = i + 1;
      i = v8;
      if ( v8 >= s_aDecalPool.m_Size )
        break;
      m_nAllocationCount = decalVec.m_Memory.m_nAllocationCount;
    }
  }
  for ( j = 0; j < m_Size; ++j )
    R_DecalUnlink(pdecal: m_pMemory[j]);
  R_DecalShoot_(
    pMaterial: material,
    position,
    saxis,
    a4: (int)m_pMemory,
    a5: j,
    entity,
    model,
    flags: flags | 0x1000,
    rgbaColor,
    pNormal: nullptr,
    userdata);
  if ( decalVec.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10105FB0
// Name: void R_DecalSortInit(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DecalSortInit()
{
  DecalSortVertexFormat_t *m_pMemory; // eax

  m_pMemory = g_aDecalFormats.m_Memory.m_pMemory;
  g_aDecalFormats.m_Size = 0;
  if ( g_aDecalFormats.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_aDecalFormats.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_aDecalFormats.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_aDecalFormats.m_Memory.m_pMemory = nullptr;
    }
    g_aDecalFormats.m_Memory.m_nAllocationCount = 0;
  }
  g_aDecalFormats.m_pElements = m_pMemory;
  CUtlVector<DecalSortTrees_t,CUtlMemory<DecalSortTrees_t,int>>::Purge(this: &g_aDecalSortTrees);
  CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::Purge(this: &g_aDecalSortPool);
  CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int>>::Grow(
    this: &g_aDecalSortPool.m_Memory,
    num: g_nMaxDecals - g_aDecalSortPool.m_Memory.m_nAllocationCount);
  g_aDecalSortPool.m_pElements = nullptr;
  CUtlLinkedList<unsigned short,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int>>>::SetGrowSize(
    this: &g_aDecalSortPool,
    growSize: 128);
  g_nDecalSortCheckCount = 0;
  g_nBrushModelDecalSortCheckCount = 0;
  CUtlVector<DecalSortTrees_t,CUtlMemory<DecalSortTrees_t,int>>::Purge(this: &g_aDispDecalSortTrees);
  CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::Purge(this: &g_aDispDecalSortPool);
  CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int>>::Grow(
    this: &g_aDispDecalSortPool.m_Memory,
    num: g_nMaxDecals - g_aDispDecalSortPool.m_Memory.m_nAllocationCount);
  g_aDispDecalSortPool.m_pElements = nullptr;
  CUtlLinkedList<unsigned short,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int>>>::SetGrowSize(
    this: &g_aDispDecalSortPool,
    growSize: 128);
  g_nDispDecalSortCheckCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10106080
// Name: void R_DecalReSortMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DecalReSortMaterials()
{
  int m_Size; // edi
  int i; // esi
  decal_t *v2; // eax

  R_DecalSortInit();
  m_Size = s_aDecalPool.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    v2 = s_aDecalPool.m_Memory.m_pMemory[i];
    if ( v2 != nullptr )
      R_DecalMaterialSort(pDecal: v2, surfID: (int)v2->surfID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101060C0
// Name: void R_DecalInit(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DecalInit()
{
  int m_nValue; // ecx
  decal_t **m_pMemory; // eax
  worldbrushdata_t *worldbrush; // eax
  int v3; // ecx
  int v4; // edx
  int i; // eax
  int v6; // ecx
  int *p_m_decalIndex; // eax

  if ( r_decals.m_pParent == nullptr
    || (m_nValue = r_decals.m_pParent->m_Value.m_nValue, g_nMaxDecals = m_nValue, m_nValue < 64) )
  {
    m_nValue = 64;
    g_nMaxDecals = 64;
  }
  m_pMemory = s_aDecalPool.m_Memory.m_pMemory;
  g_nDynamicDecals = 0;
  g_nStaticDecals = 0;
  g_iLastReplacedDynamic = -1;
  s_aDecalPool.m_Size = 0;
  if ( s_aDecalPool.m_Memory.m_nGrowSize >= 0 )
  {
    if ( s_aDecalPool.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: s_aDecalPool.m_Memory.m_pMemory);
      m_nValue = g_nMaxDecals;
      m_pMemory = nullptr;
      s_aDecalPool.m_Memory.m_pMemory = nullptr;
    }
    s_aDecalPool.m_Memory.m_nAllocationCount = 0;
  }
  s_aDecalPool.m_pElements = m_pMemory;
  s_aDecalPool.m_Size = 0;
  CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
    this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&s_aDecalPool,
    elem: 0,
    num: m_nValue);
  worldbrush = host_state.worldbrush;
  if ( host_state.worldbrush != nullptr )
  {
    v3 = 0;
    if ( host_state.worldbrush->numsurfaces > 0 )
    {
      v4 = 0;
      do
      {
        worldbrush->surfaces2[v4].decals = -1;
        worldbrush = host_state.worldbrush;
        ++v3;
        ++v4;
      }
      while ( v3 < host_state.worldbrush->numsurfaces );
    }
  }
  for ( i = 0; i < g_nMaxDecals; ++i )
    s_aDecalPool.m_Memory.m_pMemory[i] = nullptr;
  g_DecalVertCache.m_firstFree = 0;
  g_DecalVertCache.m_freeTestIndex = 0;
  v6 = 0;
  p_m_decalIndex = &g_DecalVertCache.m_cache[0].decalVert[0].m_decalIndex;
  do
  {
    p_m_decalIndex[8] = ++v6;
    *p_m_decalIndex = -1;
    p_m_decalIndex[16] = 1;
    p_m_decalIndex += 32;
  }
  while ( (int)p_m_decalIndex < (int)&g_DecalVertCache.m_lastFrameCount );
  g_DecalVertCache.m_cache[1023].decalVert[1].m_decalIndex = 0xFFFF;
  g_DecalVertCache.m_freeBlockCount = 1024;
  R_DecalSortInit();
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100FEAD0
// Name: bool DecalSortTreeSortLessFunc(struct DecalMaterialSortData_t const __near &,struct DecalMaterialSortData_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl DecalSortTreeSortLessFunc(const DecalMaterialSortData_t *decal1, const DecalMaterialSortData_t *decal2)
{
  int m_iLightmapPage; // edx
  int v3; // esi

  m_iLightmapPage = decal1->m_iLightmapPage;
  if ( m_iLightmapPage == -1 )
    return (int)decal1->m_pMaterial < (int)decal2->m_pMaterial;
  v3 = decal2->m_iLightmapPage;
  if ( v3 == -1 )
    return (int)decal1->m_pMaterial < (int)decal2->m_pMaterial;
  if ( decal1->m_pMaterial == decal2->m_pMaterial )
    return m_iLightmapPage < v3;
  return (int)decal1->m_pMaterial < (int)decal2->m_pMaterial;
}

//------------------------------------------------------------------------------
// Address: 0x100FEB20
// Name: private: int CDecalVertCache::AllocBlocks(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDecalVertCache::AllocBlocks(CDecalVertCache *this, int blockCount)
{
  int m_freeBlockCount; // eax
  int result; // eax
  int m_decalIndex; // edx
  int v6; // esi
  int v7; // eax
  int m_firstFree; // edx
  int v9; // edi
  int firstBlock; // [esp+Ch] [ebp+8h]

  m_freeBlockCount = this->m_freeBlockCount;
  if ( blockCount > m_freeBlockCount )
    return 0xFFFF;
  if ( m_freeBlockCount != 0 )
  {
    result = this->m_firstFree;
    m_decalIndex = this->m_cache[result].decalVert[1].m_decalIndex;
    this->m_cache[result].decalVert[2].m_decalIndex = 0;
    --this->m_freeBlockCount;
    this->m_firstFree = m_decalIndex;
  }
  else
  {
    result = 0xFFFF;
  }
  firstBlock = result;
  v6 = result;
  if ( blockCount > 1 )
  {
    v7 = blockCount - 1;
    do
    {
      if ( this->m_freeBlockCount != 0 )
      {
        m_firstFree = this->m_firstFree;
        v9 = this->m_cache[m_firstFree].decalVert[1].m_decalIndex;
        this->m_cache[m_firstFree].decalVert[2].m_decalIndex = 0;
        --this->m_freeBlockCount;
        this->m_firstFree = v9;
      }
      else
      {
        m_firstFree = 0xFFFF;
      }
      --v7;
      this->m_cache[v6].decalVert[1].m_decalIndex = m_firstFree;
      v6 = m_firstFree;
    }
    while ( v7 != 0 );
    result = firstBlock;
  }
  this->m_cache[v6].decalVert[1].m_decalIndex = 0xFFFF;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FEBE0
// Name: DecalListAdd
// Source: json
//------------------------------------------------------------------------------
int __usercall DecalListAdd@<eax>(decallist_t *pList@<eax>, int a2)
{
  int v3; // eax
  decallist_t *v4; // esi
  __int16 *i; // edi
  int v7; // [esp-4h] [ebp-10h]

  v3 = a2;
  v4 = &pList[a2];
  v7 = 0;
  if ( a2 <= 0 )
    return v3 + 1;
  for ( i = &pList->entityIndex;
        _V_strcmp(s1: v4->name, s2: (const char *)i - 128) != 0
     || v4->entityIndex != *i
     || fsqrt(
          (float)((float)((float)(v4->position.y - *((float *)i - 34)) * (float)(v4->position.y - *((float *)i - 34)))
                + (float)((float)(v4->position.z - *((float *)i - 33)) * (float)(v4->position.z - *((float *)i - 33))))
        + (float)((float)(v4->position.x - *((float *)i - 35)) * (float)(v4->position.x - *((float *)i - 35)))) >= 2.0;
        i += 78 )
  {
    if ( ++v7 >= a2 )
    {
      v3 = a2;
      return v3 + 1;
    }
  }
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x100FECD0
// Name: DecalDepthCompare
// Source: json
//------------------------------------------------------------------------------
int __cdecl DecalDepthCompare(const decallist_t *elem1, const decallist_t *elem2)
{
  unsigned __int8 depth; // al
  unsigned __int8 v3; // cl

  depth = elem1->depth;
  v3 = elem2->depth;
  if ( depth <= v3 )
    return depth < v3;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100FED00
// Name: R_DecalVertsLight
// Source: json
//------------------------------------------------------------------------------
void __usercall R_DecalVertsLight(CDecalVert *v@<ecx>, const decalcontext_t *context@<eax>, int surfID)
{
  int v3; // edi
  unsigned int v4; // edx
  float y; // xmm0_4
  float z; // xmm1_4
  float x; // xmm4_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm4_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  float *p_y; // ecx
  char *v19; // esi
  float v20; // xmm0_4
  float v21; // xmm1_4

  v3 = 0;
  if ( surfID >= 4 )
  {
    v4 = ((unsigned int)(surfID - 4) >> 2) + 1;
    v3 = 4 * v4;
    do
    {
      y = v->m_vPos.y;
      z = v->m_vPos.z;
      v->m_cLMCoords.x = (float)((float)((float)((float)(y * context->sAxis.y) + (float)(v->m_vPos.x * context->sAxis.x))
                                       + (float)(z * context->sAxis.z))
                               + context->sOffset)
                       * context->sScale;
      x = v[1].m_vPos.x;
      v->m_cLMCoords.y = (float)((float)((float)((float)(y * context->tAxis.y) + (float)(context->tAxis.x * v->m_vPos.x))
                                       + (float)(z * context->tAxis.z))
                               + context->tOffset)
                       * context->tScale;
      v8 = v[1].m_vPos.y;
      v9 = v[1].m_vPos.z;
      v[1].m_cLMCoords.x = (float)((float)((float)((float)(v8 * context->sAxis.y) + (float)(x * context->sAxis.x))
                                         + (float)(v9 * context->sAxis.z))
                                 + context->sOffset)
                         * context->sScale;
      v10 = v[2].m_vPos.x;
      v11 = (float)((float)((float)((float)(v8 * context->tAxis.y) + (float)(context->tAxis.x * v[1].m_vPos.x))
                          + (float)(v9 * context->tAxis.z))
                  + context->tOffset)
          * context->tScale;
      v12 = v[2].m_vPos.z;
      v[1].m_cLMCoords.y = v11;
      v13 = v[2].m_vPos.y;
      v14 = v[3].m_vPos.z;
      v[2].m_cLMCoords.x = (float)((float)((float)((float)(v13 * context->sAxis.y) + (float)(v10 * context->sAxis.x))
                                         + (float)(v12 * context->sAxis.z))
                                 + context->sOffset)
                         * context->sScale;
      v15 = (float)((float)((float)((float)(v13 * context->tAxis.y) + (float)(context->tAxis.x * v[2].m_vPos.x))
                          + (float)(v12 * context->tAxis.z))
                  + context->tOffset)
          * context->tScale;
      v16 = v[3].m_vPos.x;
      v[2].m_cLMCoords.y = v15;
      v17 = v[3].m_vPos.y;
      v[3].m_cLMCoords.x = (float)((float)((float)((float)(v17 * context->sAxis.y) + (float)(v16 * context->sAxis.x))
                                         + (float)(v14 * context->sAxis.z))
                                 + context->sOffset)
                         * context->sScale;
      v[3].m_cLMCoords.y = (float)((float)((float)((float)(v17 * context->tAxis.y) + (float)(v16 * context->tAxis.x))
                                         + (float)(v14 * context->tAxis.z))
                                 + context->tOffset)
                         * context->tScale;
      v += 4;
      --v4;
    }
    while ( v4 != 0 );
  }
  if ( v3 < surfID )
  {
    p_y = &v->m_vPos.y;
    v19 = (char *)(surfID - v3);
    do
    {
      v20 = *p_y;
      v21 = p_y[1];
      p_y[5] = (float)((float)((float)((float)(*p_y * context->sAxis.y) + (float)(*(p_y - 1) * context->sAxis.x))
                             + (float)(v21 * context->sAxis.z))
                     + context->sOffset)
             * context->sScale;
      p_y[6] = (float)((float)((float)((float)(v20 * context->tAxis.y) + (float)(context->tAxis.x * *(p_y - 1)))
                             + (float)(v21 * context->tAxis.z))
                     + context->tOffset)
             * context->tScale;
      p_y += 8;
      --v19;
    }
    while ( v19 != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FEFE0
// Name: public: void CDecalVertCache::FreeCachedVerts(struct decal_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDecalVertCache::FreeCachedVerts(CDecalVertCache *this, decal_t *pDecal)
{
  decal_t *v2; // eax
  int cacheHandle; // edx
  int m_decalIndex; // esi
  decalcache_t *v5; // eax

  v2 = pDecal;
  cacheHandle = pDecal->cacheHandle;
  if ( cacheHandle != 0xFFFF )
  {
    do
    {
      m_decalIndex = this->m_cache[cacheHandle].decalVert[1].m_decalIndex;
      v5 = &this->m_cache[cacheHandle];
      v5->decalVert[2].m_decalIndex = 1;
      v5->decalVert[1].m_decalIndex = this->m_firstFree;
      v5->decalVert[0].m_decalIndex = -1;
      ++this->m_freeBlockCount;
      this->m_firstFree = cacheHandle;
      cacheHandle = m_decalIndex;
    }
    while ( m_decalIndex != 0xFFFF );
    v2 = pDecal;
  }
  *(_DWORD *)&v2->clippedVertCount = -65536;
}

//------------------------------------------------------------------------------
// Address: 0x100FF050
// Name: public: class CDecalVert __near * CDecalVertCache::GetCachedVerts(struct decal_t __near *)
// Source: json
//------------------------------------------------------------------------------
decalcache_t *__thiscall CDecalVertCache::GetCachedVerts(CDecalVertCache *this, decal_t *pDecal)
{
  int cacheHandle; // ecx
  decalcache_t *result; // eax
  unsigned int v5; // edx
  decal_t *v6; // edi
  int m_decalIndex; // eax
  decal_t *pDecala; // [esp+Ch] [ebp+8h]

  cacheHandle = pDecal->cacheHandle;
  if ( r_framecount != this->m_lastFrameCount )
  {
    this->m_frameBlocks = 0;
    this->m_lastFrameCount = r_framecount;
  }
  if ( cacheHandle == 0xFFFF )
    return nullptr;
  result = &this->m_cache[cacheHandle];
  do
  {
    result->decalVert[3].m_decalIndex = r_framecount;
    cacheHandle = this->m_cache[cacheHandle].decalVert[1].m_decalIndex;
  }
  while ( cacheHandle != 0xFFFF );
  v5 = (pDecal->clippedVertCount + 3) >> 2;
  this->m_frameBlocks += v5;
  if ( v5 > 1 )
  {
    pDecala = (decal_t *)g_DecalClipVerts;
    do
    {
      v6 = pDecala;
      pDecala = (decal_t *)((char *)pDecala + 128);
      qmemcpy(v6, result, 0x80u);
      m_decalIndex = result->decalVert[1].m_decalIndex;
      --v5;
      if ( m_decalIndex == 0xFFFF )
        result = nullptr;
      else
        result = &this->m_cache[m_decalIndex];
    }
    while ( v5 != 0 );
    return (decalcache_t *)g_DecalClipVerts;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FF120
// Name: float ComputeDecalLightmapOffset(struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl ComputeDecalLightmapOffset(int surfID)
{
  int v1; // esi
  IMaterialSystem_vtbl *v2; // edi
  int v3; // eax
  int nHeight; // [esp+4h] [ebp-4h] BYREF

  v1 = surfID;
  if ( (*(_BYTE *)surfID & 8) == 0 )
    return 0.0;
  v2 = materials->__vftable;
  v3 = SortInfoToLightmapPage(sortID: *(__int16 *)(surfID + 18));
  v2->GetLightmapPageSize(this: materials, a2: v3, a3: &surfID, a4: &nHeight);
  if ( *(float *)&surfID == 0.0 )
    return 0.0;
  *(float *)&surfID = (float)(*(__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapExtents
                                         + ((v1 - (unsigned int)host_state.worldbrush->surfaces2) & 0xFFFFFFE0))
                            + 1)
                    / (float)surfID;
  return *(float *)&surfID;
}

//------------------------------------------------------------------------------
// Address: 0x100FF1B0
// Name: void R_DecalGetMaterialAndSize(int,class IMaterial __near * __near &,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DecalGetMaterialAndSize(int decalIndex, IMaterial **pDecalMaterial, float *w, float *h)
{
  IMaterial *v4; // eax
  int v6; // eax
  IMaterialVar *v7; // eax
  IUniformRandomStream *v8; // ecx
  double v9; // st7
  float v10; // xmm0_4
  float variation; // [esp+1Ch] [ebp-4h]
  float scale; // [esp+2Ch] [ebp+Ch]

  v4 = Draw_DecalMaterial(index: decalIndex);
  *pDecalMaterial = v4;
  if ( v4 != nullptr )
  {
    scale = 1.0;
    v6 = (int)v4->FindVarFast(this: v4, a2: "$decalScale", a3: &s_DecalScaleVarCache);
    if ( v6 != 0 )
      scale = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v6 + 112))(a1: v6);
    v7 = (*pDecalMaterial)->FindVarFast(
           this: *pDecalMaterial,
           a2: "$decalScaleVariation",
           a3: &s_DecalScaleVariationVarCache);
    if ( v7 != nullptr )
    {
      v9 = ((double (__thiscall *)(IMaterialVar *))v7->GetFloatValueInternal)(a1: v7);
      if ( v9 >= 0.0 )
      {
        v10 = v9;
        variation = v9;
        if ( variation > 0.99000001 )
          v10 = 0.99000001;
      }
      else
      {
        v10 = 0.0;
      }
      scale = (_RandomFloat(this: v8, a2: COERCE_FLOAT(LODWORD(v10) ^ _mask__NegFloat_), a3: v10) + 1.0) * scale;
    }
    *w = (float)(*pDecalMaterial)->GetMappingWidth(this: *pDecalMaterial) * scale;
    *h = (float)(*pDecalMaterial)->GetMappingHeight(this: *pDecalMaterial) * scale;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FF2C0
// Name: R_DecalUnProject
// Source: json
//------------------------------------------------------------------------------
char __usercall R_DecalUnProject@<al>(decal_t *pdecal@<ecx>, decallist_t *entry@<eax>)
{
  cplane_t *plane; // ecx
  float plane_4; // [esp+4h] [ebp-10h]
  float plane_8; // [esp+8h] [ebp-Ch]

  if ( pdecal == nullptr || pdecal->surfID == nullptr )
    return 0;
  entry->position = pdecal->position;
  entry->entityIndex = pdecal->entityIndex;
  plane = pdecal->surfID->plane;
  plane_4 = plane->normal.y;
  plane_8 = plane->normal.z;
  entry->impactPlaneNormal.x = plane->normal.x;
  entry->impactPlaneNormal.y = plane_4;
  entry->impactPlaneNormal.z = plane_8;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100FF350
// Name: public: void decalcontext_t::InitSurface(struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall decalcontext_t::InitSurface(decalcontext_t *this, msurface2_t *surfID)
{
  float *v4; // esi
  int v5; // eax
  __m128i v6; // xmm1
  __int16 *v7; // ebx
  int lightmapPageHeight; // [esp+8h] [ebp-8h] BYREF
  int lightmapPageWidth; // [esp+Ch] [ebp-4h] BYREF
  msurface2_t *surfIDa; // [esp+18h] [ebp+8h]

  if ( this->pSurf != surfID )
  {
    this->pSurf = surfID;
    v4 = (float *)&host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1];
    surfIDa = (msurface2_t *)materials->__vftable;
    v5 = SortInfoToLightmapPage(sortID: surfID->materialSortID);
    ((void (__thiscall *)(IMaterialSystem *, int, int *, int *))surfIDa[13].flags)(
      a1: materials,
      a2: v5,
      a3: &lightmapPageWidth,
      a4: &lightmapPageHeight);
    v6 = _mm_cvtsi32_si128(lightmapPageHeight);
    this->sScale = 1.0 / (float)lightmapPageWidth;
    this->tScale = 1.0 / _mm_cvtepi32_ps(v6).m128_f32[0];
    v7 = (__int16 *)((char *)host_state.worldbrush->surfacelighting->m_LightmapMins
                   + (((char *)surfID - (char *)host_state.worldbrush->surfaces2) & 0xFFFFFFE0));
    this->sOffset = (float)((float)(v4[11] - (float)*v7) + (float)v7[4]) + 0.5;
    this->tOffset = (float)((float)(v4[15] - (float)v7[1]) + (float)v7[5]) + 0.5;
    this->sAxis.x = v4[8];
    this->sAxis.y = v4[9];
    this->sAxis.z = v4[10];
    this->tAxis.x = v4[12];
    this->tAxis.y = v4[13];
    this->tAxis.z = v4[14];
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FF4E0
// Name: r_printdecalinfo_f
// Source: json
//------------------------------------------------------------------------------
void __cdecl r_printdecalinfo_f()
{
  int v0; // esi
  int v1; // edx
  int i; // eax
  int m_nValue; // eax

  v0 = 0;
  v1 = 0;
  for ( i = 0; i < g_nMaxDecals; ++i )
  {
    if ( s_aDecalPool.m_Memory.m_pMemory[i] != nullptr )
    {
      if ( (s_aDecalPool.m_Memory.m_pMemory[i]->flags & 1) != 0 )
        ++v0;
      else
        ++v1;
    }
  }
  if ( r_decals.m_pParent != nullptr )
    m_nValue = r_decals.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  _Msg(a1: "%d decals: %d permanent, %d dynamic\nr_decals: %d\n", v0 + v1, v0, v1, m_nValue);
}

//------------------------------------------------------------------------------
// Address: 0x100FF540
// Name: private: void CDecalVertCache::FindFreeBlocks(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDecalVertCache::FindFreeBlocks(CDecalVertCache *this, int blockCount)
{
  int m_freeTestIndex; // eax
  int v3; // esi
  int v4; // eax
  int v5; // edx

  if ( blockCount > this->m_freeBlockCount && blockCount <= 1024 - this->m_frameBlocks )
  {
    m_freeTestIndex = this->m_freeTestIndex;
    v3 = ((_WORD)m_freeTestIndex + 16) & 0x3FF;
    if ( m_freeTestIndex != v3 )
    {
      do
      {
        v4 = this->m_freeTestIndex << 7;
        if ( *(int *)((char *)&this->m_cache[0].decalVert[2].m_decalIndex + v4) == 0
          && r_framecount - *(int *)((char *)&this->m_cache[0].decalVert[3].m_decalIndex + v4) > 1 )
        {
          CDecalVertCache::FreeCachedVerts(
            this,
            pDecal: s_aDecalPool.m_Memory.m_pMemory[*(int *)((char *)&this->m_cache[0].decalVert[0].m_decalIndex + v4)]);
        }
        if ( this->m_freeBlockCount >= blockCount )
          break;
        v5 = ((unsigned __int16)this->m_freeTestIndex + 1) & 0x3FF;
        this->m_freeTestIndex = v5;
      }
      while ( v5 != v3 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FF5D0
// Name: void R_DecalUnlink(struct decal_t __near *,struct worldbrushdata_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DecalUnlink(decal_t *pdecal)
{
  msurface2_t *surfID; // edx
  int decals; // ecx
  decal_t *v3; // eax
  decal_t *v4; // esi
  decal_t *pnext; // eax
  msurface2_t *v6; // eax
  IDispInfo *pDispInfo; // ecx
  bool v8; // zf

  if ( pdecal == nullptr )
    return;
  CDecalVertCache::FreeCachedVerts(this: &g_DecalVertCache, pDecal: pdecal);
  surfID = pdecal->surfID;
  if ( surfID != nullptr )
  {
    decals = surfID->decals;
    if ( (_WORD)decals == 0xFFFF )
      v3 = nullptr;
    else
      v3 = s_aDecalPool.m_Memory.m_pMemory[decals];
    if ( v3 == pdecal )
    {
      if ( pdecal->pnext != nullptr )
        surfID->decals = pdecal->pnext->m_iDecalPool;
      else
        surfID->decals = -1;
LABEL_19:
      v6 = pdecal->surfID;
      if ( (v6->flags & 0x800) != 0 )
      {
        pDispInfo = v6->pDispInfo;
        if ( pDispInfo != nullptr )
          pDispInfo->NotifyRemoveDecal(this: pDispInfo, a2: pdecal->m_DispDecal);
      }
      goto LABEL_22;
    }
    if ( (_WORD)decals == 0xFFFF )
    {
      v4 = nullptr;
    }
    else
    {
      v4 = s_aDecalPool.m_Memory.m_pMemory[decals];
      if ( v4 != nullptr )
        goto LABEL_14;
    }
    Sys_Error(error: "Bad decal list");
LABEL_14:
    if ( v4->pnext != nullptr )
    {
      while ( 1 )
      {
        pnext = v4->pnext;
        if ( v4->pnext == pdecal )
          break;
        v4 = v4->pnext;
        if ( pnext->pnext == nullptr )
          goto LABEL_19;
      }
      v4->pnext = pdecal->pnext;
    }
    goto LABEL_19;
  }
LABEL_22:
  v8 = (pdecal->flags & 1) == 0;
  pdecal->surfID = nullptr;
  if ( v8 )
    --g_nDynamicDecals;
  else
    --g_nStaticDecals;
  s_aDecalPool.m_Memory.m_pMemory[pdecal->m_iDecalPool] = nullptr;
  CUtlMemoryPool::Free(this: &g_DecalAllocator, memBlock: pdecal);
}

//------------------------------------------------------------------------------
// Address: 0x100FF6D0
// Name: int R_FindDynamicDecalSlot(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl R_FindDynamicDecalSlot(int iStartAt)
{
  int v1; // esi
  int result; // eax

  v1 = iStartAt;
  if ( iStartAt >= g_nMaxDecals || iStartAt < 0 )
    v1 = 0;
  result = v1;
  while ( s_aDecalPool.m_Memory.m_pMemory[result] == nullptr
       || (s_aDecalPool.m_Memory.m_pMemory[result]->flags & 1) != 0
       || (s_aDecalPool.m_Memory.m_pMemory[result]->flags & 0x1000) != 0 )
  {
    if ( ++result >= g_nMaxDecals )
      result = 0;
    if ( result == v1 )
    {
      DevMsg(a1: "R_FindDynamicDecalSlot: no slot available.\n");
      return -1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FF730
// Name: int DecalListCreate(struct decallist_t __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl DecalListCreate(decallist_t *pList)
{
  unsigned int v1; // ebx
  int v2; // ecx
  decal_t **m_pMemory; // edx
  decal_t *v4; // edi
  msurface2_t *surfID; // eax
  int decals; // eax
  unsigned __int8 v7; // cl
  decal_t *j; // eax
  decallist_t *v9; // esi
  const char *v10; // eax
  int v11; // eax
  int i; // [esp+4h] [ebp-4h]

  v1 = 0;
  if ( host_state.worldmodel != nullptr )
  {
    v2 = 0;
    i = 0;
    if ( g_nMaxDecals > 0 )
    {
      m_pMemory = s_aDecalPool.m_Memory.m_pMemory;
      do
      {
        v4 = m_pMemory[v2];
        if ( v4 != nullptr )
        {
          surfID = v4->surfID;
          if ( surfID != nullptr && (v4->flags & 0x804) == 0 )
          {
            decals = surfID->decals;
            v7 = 0;
            if ( (_WORD)decals != 0xFFFF )
            {
              for ( j = m_pMemory[decals]; j != nullptr; ++v7 )
              {
                if ( j == v4 )
                  break;
                j = j->pnext;
              }
            }
            v9 = &pList[v1];
            v9->depth = v7;
            v9->flags = v4->flags;
            R_DecalUnProject(pdecal: v4, entry: v9);
            v10 = v4->material->GetName(this: v4->material);
            V_strncpy(pDest: v9->name, pSrc: v10, maxLen: 128);
            v11 = DecalListAdd(pList, a2: v1);
            m_pMemory = s_aDecalPool.m_Memory.m_pMemory;
            v2 = i;
            v1 = v11;
          }
        }
        i = ++v2;
      }
      while ( v2 < g_nMaxDecals );
    }
  }
  qsort(base: pList, num: v1, width: 0x9Cu, comp: (int (__cdecl *)(const void *, const void *))DecalDepthCompare);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x100FFA20
// Name: public: CFunctor9<void (*)(bool,int,class Vector,int,struct decal_t __near * __near *,int,int,int,float),bool,int,class Vector,int,struct decal_t __near * __near *,int,int,int,float,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::CFunctor9<void (*)(bool,int,class Vector,int,struct decal_t __near * __near *,int,int,int,float),bool,int,class Vector,int,struct decal_t __near * __near *,int,int,int,float,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>(void (*)(bool,int,class Vector,int,struct decal_t __near * __near *,int,int,int,float),bool const __near &,int const __near &,class Vector const __near &,int const __near &,struct decal_t __near * __near * const __near &,int const __near &,int const __near &,int const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctor9<void (__cdecl*)(bool,int,Vector,int,decal_t * *,int,int,int,float),bool,int,Vector,int,decal_t * *,int,int,int,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *__thiscall CFunctor9<void (__cdecl *)(bool,int,Vector,int,decal_t * *,int,int,int,float),bool,int,Vector,int,decal_t * *,int,int,int,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::CFunctor9<void (__cdecl *)(bool,int,Vector,int,decal_t * *,int,int,int,float),bool,int,Vector,int,decal_t * *,int,int,int,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>(
        CFunctor9<void (__cdecl*)(bool,int,Vector,int,decal_t * *,int,int,int,float),bool,int,Vector,int,decal_t * *,int,int,int,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this,
        void (__cdecl *pfnProxied)(bool, int, Vector, int, decal_t **, int, int, int, float),
        bool *arg1,
        int *arg2,
        const Vector *arg3,
        int *arg4,
        decal_t ***arg5,
        int *arg6,
        int *arg7,
        int *arg8,
        float *arg9)
{
  this->m_iRefs = 1;
  this->m_pfnProxied = pfnProxied;
  this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CFunctor::IRefCounted::__vftable = (CFunctor9<void (__cdecl*)(bool,int,Vector,int,decal_t * *,int,int,int,float),bool,int,Vector,int,decal_t * *,int,int,int,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > >_vtbl *)&CFunctor9<void (__cdecl *)(bool,int,Vector,int,decal_t * *,int,int,int,float),bool,int,Vector,int,decal_t * *,int,int,int,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CFunctor'};
  this->CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >::CRefCountServiceBase<1,CRefMT>::__vftable = (CRefCountServiceBase<1,CRefMT>_vtbl *)&CFunctor9<void (__cdecl *)(bool,int,Vector,int,decal_t * *,int,int,int,float),bool,int,Vector,int,decal_t * *,int,int,int,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  this->m_arg1 = *arg1;
  this->m_arg2 = *arg2;
  this->m_arg3 = *arg3;
  this->m_arg4 = *arg4;
  this->m_arg5 = *arg5;
  this->m_arg6 = *arg6;
  this->m_arg7 = *arg7;
  this->m_arg8 = *arg8;
  this->m_arg9 = *arg9;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100FFAA0
// Name: public: virtual void CFunctor9<void (*)(bool,int,class Vector,int,struct decal_t __near * __near *,int,int,int,float),bool,int,class Vector,int,struct decal_t __near * __near *,int,int,int,float,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor9<void (__cdecl *)(bool,int,Vector,int,decal_t * *,int,int,int,float),bool,int,Vector,int,decal_t * *,int,int,int,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor9<void (__cdecl*)(bool,int,Vector,int,decal_t * *,int,int,int,float),bool,int,Vector,int,decal_t * *,int,int,int,float,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  ((void (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))this->m_pfnProxied)(
    a1: this->m_arg1,
    a2: this->m_arg2,
    a3: LODWORD(this->m_arg3.x),
    a4: LODWORD(this->m_arg3.y),
    a5: LODWORD(this->m_arg3.z),
    a6: this->m_arg4,
    a7: this->m_arg5,
    a8: this->m_arg6,
    a9: this->m_arg7,
    a10: this->m_arg8,
    a11: this->m_arg9);
}

//------------------------------------------------------------------------------
// Address: 0x101000A0
// Name: public: void CDecalVertCache::StoreVertsInCache(struct decal_t __near *,class CDecalVert __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDecalVertCache::StoreVertsInCache(CDecalVertCache *this, decal_t *pDecal, CDecalVert *pList)
{
  int v3; // esi
  CDecalVertCache *v4; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  float *p_y; // edx
  double v9; // st7
  int v10; // eax

  v3 = (pDecal->clippedVertCount + 3) >> 2;
  CDecalVertCache::FindFreeBlocks(this, blockCount: v3);
  if ( v3 <= v4->m_freeBlockCount )
  {
    v5 = CDecalVertCache::AllocBlocks(this: v4, blockCount: v3);
    pDecal->cacheHandle = v5;
    v7 = v6 + (v5 << 7);
    if ( v3 != 0 )
    {
      p_y = &pList->m_cLMCoords.y;
      do
      {
        v9 = *(p_y - 7);
        p_y += 32;
        *(float *)v7 = v9;
        --v3;
        *(float *)(v7 + 4) = *(p_y - 38);
        *(float *)(v7 + 8) = *(p_y - 37);
        *(float *)(v7 + 16) = *(p_y - 35);
        *(float *)(v7 + 20) = *(p_y - 34);
        *(float *)(v7 + 24) = *(p_y - 33);
        *(float *)(v7 + 28) = *(p_y - 32);
        *(float *)(v7 + 32) = *(p_y - 31);
        *(float *)(v7 + 36) = *(p_y - 30);
        *(float *)(v7 + 40) = *(p_y - 29);
        *(float *)(v7 + 48) = *(p_y - 27);
        *(float *)(v7 + 52) = *(p_y - 26);
        *(float *)(v7 + 56) = *(p_y - 25);
        *(float *)(v7 + 60) = *(p_y - 24);
        *(float *)(v7 + 64) = *(p_y - 23);
        *(float *)(v7 + 68) = *(p_y - 22);
        *(float *)(v7 + 72) = *(p_y - 21);
        *(float *)(v7 + 80) = *(p_y - 19);
        *(float *)(v7 + 84) = *(p_y - 18);
        *(float *)(v7 + 88) = *(p_y - 17);
        *(float *)(v7 + 92) = *(p_y - 16);
        *(float *)(v7 + 96) = *(p_y - 15);
        *(float *)(v7 + 100) = *(p_y - 14);
        *(float *)(v7 + 104) = *(p_y - 13);
        *(float *)(v7 + 112) = *(p_y - 11);
        *(float *)(v7 + 116) = *(p_y - 10);
        *(float *)(v7 + 120) = *(p_y - 9);
        *(float *)(v7 + 124) = *(p_y - 8);
        *(_DWORD *)(v7 + 12) = pDecal->m_iDecalPool;
        *(_DWORD *)(v7 + 108) = r_framecount;
        v10 = *(_DWORD *)(v7 + 44);
        if ( v10 == 0xFFFF )
          v7 = 0;
        else
          v7 = v6 + (v10 << 7);
      }
      while ( v3 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101001D0
// Name: void Shader_DecalDrawPoly(class CDecalVert __near *,class IMaterial __near *,struct msurface2_t __near *,int,struct decal_t __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __usercall Shader_DecalDrawPoly(
        int a1@<ebx>,
        int a2@<edi>,
        CDecalVert *v,
        IMaterial *pMaterial,
        msurface2_t *surfID,
        int vertCount,
        decal_t *pdecal,
        float flFade)
{
  IMatRenderContext *(__thiscall *GetRenderContext)(IMaterialSystem *); // edx
  IMatRenderContext *v9; // esi
  int m_nValue; // eax
  IMesh *v12; // esi
  CClientState *v14; // eax
  double v15; // st7
  CClientState *BaseLocalClient; // eax
  float v17; // xmm2_4
  char v18; // dl
  int v19; // ecx
  int v20; // edx
  int v21; // edi
  float *p_z; // esi
  float *m_pCurrPosition; // eax
  int v24; // xmm0_4
  int v25; // xmm1_4
  float *v26; // eax
  int v27; // xmm0_4
  float *v28; // eax
  int v29; // xmm0_4
  int m_nVertexCount; // eax
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+4h] [ebp-224h] BYREF
  Vector tVect; // [esp+1ECh] [ebp-3Ch] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1F8h] [ebp-30h]
  IMesh *pMesh; // [esp+1FCh] [ebp-2Ch]
  Vector tangentT; // [esp+200h] [ebp-28h] BYREF
  Vector tangentS; // [esp+20Ch] [ebp-1Ch] BYREF
  Vector normal; // [esp+218h] [ebp-10h] BYREF
  int vertexFormat; // [esp+224h] [ebp-4h]
  float negate; // [esp+23Ch] [ebp+14h]
  bool negateb; // [esp+23Ch] [ebp+14h]
  int negatea; // [esp+23Ch] [ebp+14h]
  unsigned __int8 colora[4]; // [esp+240h] [ebp+18h]
  int flFadea; // [esp+244h] [ebp+1Ch]
  color32_s color; // 0:^25C.4

  GetRenderContext = materials->GetRenderContext;
  vertexFormat = 0;
  v9 = GetRenderContext(this: materials);
  pRenderContext.m_pObject = v9;
  if ( v9 != nullptr )
    v9->BeginRender(this: v9);
  if ( (sv_cheats.m_pParent != nullptr && sv_cheats.m_pParent->m_Value.m_nValue != 0 || Cmd_IsRptActive())
    && (mat_wireframe.m_pParent == nullptr ? (m_nValue = 0) : (m_nValue = mat_wireframe.m_pParent->m_Value.m_nValue),
        m_nValue != 0)
    || r_drawdecals.m_pParent != nullptr && r_drawdecals.m_pParent->m_Value.m_nValue == 2 )
  {
    ((void (__thiscall *)(IMatRenderContext *, IMaterial *, _DWORD, int, int))v9->Bind)(
      a1: v9,
      a2: g_materialDecalWireframe,
      a3: 0,
      a4: a2,
      a5: a1);
  }
  else
  {
    ((void (__thiscall *)(IMatRenderContext *, int, int, int))v9->BindLightmapPage)(
      a1: v9,
      a2: materialSortInfoArray[surfID->materialSortID].lightmapPageID,
      a3: a2,
      a4: a1);
    v9->Bind(this: v9, a2: pMaterial, a3: pdecal->userdata);
    vertexFormat = pMaterial->GetVertexFormat(this: pMaterial) & 0xFFFFFBFF;
  }
  v12 = v9->GetDynamicMesh(this: v9, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  pMesh = v12;
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v12;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_POLYGON;
  v12->SetPrimitiveType(this: v12, a2: MATERIAL_TRIANGLES);
  meshBuilder.m_pMesh->LockMesh(
    this: meshBuilder.m_pMesh,
    a2: vertCount,
    a3: 3 * vertCount - 6,
    a4: &meshBuilder,
    a5: nullptr);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v12->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 3 * vertCount - 6;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  CVertexBuilder::AttachBegin(
    this: &meshBuilder.m_VertexBuilder,
    pMesh: v12,
    nMaxVertexCount: vertCount,
    desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  color = pdecal->color;
  if ( flFade != 1.0 )
    color.a = (int)(float)((float)pdecal->color.a * flFade);
  if ( (pdecal->flags & 0x100) != 0 )
  {
    if ( pdecal->fadeDuration >= 0.0 )
    {
      BaseLocalClient = GetBaseLocalClient();
      v15 = 1.0 - (CClientState::GetTime(this: BaseLocalClient) - pdecal->fadeStartTime) / pdecal->fadeDuration;
    }
    else
    {
      v14 = GetBaseLocalClient();
      v15 = -((CClientState::GetTime(this: v14) - pdecal->fadeStartTime) / pdecal->fadeDuration);
    }
    negate = v15;
    v17 = negate;
    if ( negate >= 0.0 )
    {
      if ( negate > 1.0 )
        v17 = 1.0;
    }
    else
    {
      v17 = 0.0;
    }
    color.a = (int)(float)((float)color.a * v17);
  }
  v18 = vertexFormat;
  normal.x = 0.0;
  normal.y = 0.0;
  normal.z = 1.0;
  tangentS.x = 1.0;
  tangentS.y = 0.0;
  tangentS.z = 0.0;
  tangentT.x = 0.0;
  tangentT.y = 1.0;
  tangentT.z = 0.0;
  if ( (vertexFormat & 0x32) != 0 )
  {
    normal = surfID->plane->normal;
    if ( (vertexFormat & 0x30) != 0 )
    {
      negateb = TangentSpaceSurfaceSetup(surfID, &tVect);
      TangentSpaceComputeBasis(&tangentS, &tangentT, &normal, &tVect, negateTangent: negateb);
      v18 = vertexFormat;
    }
  }
  vertexFormat = LODWORD(pdecal->lightmapOffset);
  if ( vertCount > 0 )
  {
    v19 = v18 & 2;
    v20 = v18 & 0x30;
    v21 = color.b | ((color.g | ((color.r | (color.a << 8)) << 8)) << 8);
    flFadea = v19;
    negatea = v20;
    p_z = &v->m_vPos.z;
    *(_DWORD *)colora = vertCount;
    while ( 1 )
    {
      m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      v24 = *((_DWORD *)p_z - 1);
      v25 = *(_DWORD *)p_z;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = *(p_z - 2);
      *((_DWORD *)m_pCurrPosition + 1) = v24;
      *((_DWORD *)m_pCurrPosition + 2) = v25;
      if ( v19 != 0 )
        *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = normal;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v21;
      v26 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      v27 = *((_DWORD *)p_z + 3);
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = p_z[2];
      *((_DWORD *)v26 + 1) = v27;
      v28 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
      v29 = *((_DWORD *)p_z + 5);
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = p_z[4];
      *((_DWORD *)v28 + 1) = v29;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = vertexFormat;
      if ( v20 != 0 )
      {
        *(Vector *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                  + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS) = tangentS;
        *(Vector *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                  + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT) = tangentT;
      }
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      p_z += 8;
      if ( --*(_DWORD *)colora == 0 )
        break;
      v20 = negatea;
      v19 = flFadea;
    }
    v12 = pMesh;
  }
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        m_nVertexCount = 0;
        break;
      default:
        m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: m_nVertexCount);
  }
  ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(
    a1: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh = nullptr;
  v12->Draw_2(this: v12, a2: -1, a3: 0);
  if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
  {
    meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
  }
  if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
  {
    meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
  }
  m_pObject = pRenderContext.m_pObject;
  pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
  m_pObject->Release(this: m_pObject);
}

//------------------------------------------------------------------------------
// Address: 0x10100730
// Name: void R_DecalTerm(struct worldbrushdata_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DecalTerm(worldbrushdata_t *pBrushData, bool term_permanent_decals)
{
  bool v3; // cc
  int v4; // ebx
  int decals; // eax
  decal_t *v6; // eax
  decal_t *pnext; // esi
  float v8; // xmm0_4
  int i; // [esp+Ch] [ebp+8h]

  if ( pBrushData != nullptr )
  {
    v3 = pBrushData->numsurfaces <= 0;
    i = 0;
    if ( !v3 )
    {
      v4 = 0;
      do
      {
        decals = pBrushData->surfaces2[v4].decals;
        if ( (_WORD)decals != 0xFFFF )
        {
          v6 = s_aDecalPool.m_Memory.m_pMemory[decals];
          if ( v6 != nullptr )
          {
            do
            {
              pnext = v6->pnext;
              if ( term_permanent_decals
                || (v6->flags & 1) == 0 && (v6->flags & 0x1000) == 0
                || (v6->flags & 0x1000) != 0
                && (v8 = v6->fadeStartTime + 1.0,
                    v6->fadeStartTime = v8,
                    v8 >= r_spray_lifetime.m_pParent->m_Value.m_fValue) )
              {
                R_DecalUnlink(pdecal: v6);
              }
              v6 = pnext;
            }
            while ( pnext != nullptr );
          }
        }
        ++v4;
        ++i;
      }
      while ( i < pBrushData->numsurfaces );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101007F0
// Name: void R_DecalTermAll(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DecalTermAll()
{
  int v0; // eax
  decal_t *v1; // edi
  msurface2_t *surfID; // edx
  int decals; // eax
  decal_t *v4; // eax
  int v5; // eax
  decal_t *v6; // esi
  decal_t *pnext; // eax
  msurface2_t *v8; // eax
  IDispInfo *pDispInfo; // ecx
  bool v10; // zf
  int i; // [esp+0h] [ebp-4h]

  v0 = 0;
  i = 0;
  if ( s_aDecalPool.m_Size > 0 )
  {
    while ( 1 )
    {
      v1 = s_aDecalPool.m_Memory.m_pMemory[v0];
      if ( v1 != nullptr )
        break;
LABEL_27:
      i = ++v0;
      if ( v0 >= s_aDecalPool.m_Size )
        return;
    }
    CDecalVertCache::FreeCachedVerts(this: &g_DecalVertCache, pDecal: s_aDecalPool.m_Memory.m_pMemory[v0]);
    surfID = v1->surfID;
    if ( surfID == nullptr )
    {
LABEL_23:
      v10 = (v1->flags & 1) == 0;
      v1->surfID = nullptr;
      if ( v10 )
        --g_nDynamicDecals;
      else
        --g_nStaticDecals;
      s_aDecalPool.m_Memory.m_pMemory[v1->m_iDecalPool] = nullptr;
      CUtlMemoryPool::Free(this: &g_DecalAllocator, memBlock: v1);
      v0 = i;
      goto LABEL_27;
    }
    decals = surfID->decals;
    if ( (_WORD)decals == 0xFFFF )
      v4 = nullptr;
    else
      v4 = s_aDecalPool.m_Memory.m_pMemory[decals];
    if ( v4 == v1 )
    {
      if ( v1->pnext != nullptr )
        surfID->decals = v1->pnext->m_iDecalPool;
      else
        surfID->decals = -1;
LABEL_20:
      v8 = v1->surfID;
      if ( (v8->flags & 0x800) != 0 )
      {
        pDispInfo = v8->pDispInfo;
        if ( pDispInfo != nullptr )
          pDispInfo->NotifyRemoveDecal(this: pDispInfo, a2: v1->m_DispDecal);
      }
      goto LABEL_23;
    }
    v5 = surfID->decals;
    if ( (_WORD)v5 == 0xFFFF )
    {
      v6 = nullptr;
    }
    else
    {
      v6 = s_aDecalPool.m_Memory.m_pMemory[v5];
      if ( v6 != nullptr )
        goto LABEL_15;
    }
    Sys_Error(error: "Bad decal list");
LABEL_15:
    if ( v6->pnext != nullptr )
    {
      while ( 1 )
      {
        pnext = v6->pnext;
        if ( v6->pnext == v1 )
          break;
        v6 = v6->pnext;
        if ( pnext->pnext == nullptr )
          goto LABEL_20;
      }
      v6->pnext = v1->pnext;
    }
    goto LABEL_20;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10100930
// Name: void R_DecalFlushDestroyList(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DecalFlushDestroyList()
{
  decal_t *v0; // edi
  msurface2_t *surfID; // ecx
  int decals; // edx
  decal_t *v3; // eax
  decal_t *v4; // esi
  decal_t *v5; // eax
  msurface2_t *v6; // eax
  IDispInfo *pDispInfo; // ecx
  bool v8; // zf
  decal_t *pNext; // [esp+8h] [ebp-4h]

  v0 = s_pDecalDestroyList;
  if ( s_pDecalDestroyList != nullptr )
  {
    while ( 1 )
    {
      pNext = v0->pDestroyList;
      CDecalVertCache::FreeCachedVerts(this: &g_DecalVertCache, pDecal: v0);
      surfID = v0->surfID;
      if ( surfID != nullptr )
        break;
LABEL_22:
      v8 = (v0->flags & 1) == 0;
      v0->surfID = nullptr;
      if ( v8 )
        --g_nDynamicDecals;
      else
        --g_nStaticDecals;
      s_aDecalPool.m_Memory.m_pMemory[v0->m_iDecalPool] = nullptr;
      CUtlMemoryPool::Free(this: &g_DecalAllocator, memBlock: v0);
      v0 = pNext;
      if ( pNext == nullptr )
        goto LABEL_26;
    }
    decals = surfID->decals;
    if ( (_WORD)decals == 0xFFFF )
      v3 = nullptr;
    else
      v3 = s_aDecalPool.m_Memory.m_pMemory[decals];
    if ( v3 == v0 )
    {
      if ( v0->pnext != nullptr )
        surfID->decals = v0->pnext->m_iDecalPool;
      else
        surfID->decals = -1;
LABEL_19:
      v6 = v0->surfID;
      if ( (v6->flags & 0x800) != 0 )
      {
        pDispInfo = v6->pDispInfo;
        if ( pDispInfo != nullptr )
          pDispInfo->NotifyRemoveDecal(this: pDispInfo, a2: v0->m_DispDecal);
      }
      goto LABEL_22;
    }
    if ( (_WORD)decals == 0xFFFF )
    {
      v4 = nullptr;
    }
    else
    {
      v4 = s_aDecalPool.m_Memory.m_pMemory[decals];
      if ( v4 != nullptr )
        goto LABEL_14;
    }
    Sys_Error(error: "Bad decal list");
LABEL_14:
    if ( v4->pnext != nullptr )
    {
      while ( 1 )
      {
        v5 = v4->pnext;
        if ( v4->pnext == v0 )
          break;
        v4 = v4->pnext;
        if ( v5->pnext == nullptr )
          goto LABEL_19;
      }
      v4->pnext = v0->pnext;
    }
    goto LABEL_19;
  }
LABEL_26:
  s_pDecalDestroyList = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10100A40
// Name: R_DecalAlloc
// Source: json
//------------------------------------------------------------------------------
decal_t *__cdecl R_DecalAlloc(bool flags)
{
  int m_nValue; // ecx
  int v2; // eax
  int v3; // eax
  int DynamicDecalSlot; // esi
  decal_t *result; // eax
  bool v6; // [esp+Bh] [ebp+Bh]

  v6 = flags;
  if ( r_decals.m_pParent != nullptr )
    m_nValue = r_decals.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( m_nValue >= g_nMaxDecals )
  {
    v2 = g_nMaxDecals;
  }
  else if ( r_decals.m_pParent != nullptr )
  {
    v2 = r_decals.m_pParent->m_Value.m_nValue;
  }
  else
  {
    v2 = 0;
  }
  if ( !v6 && g_nDynamicDecals >= v2 )
    goto LABEL_16;
  v3 = 0;
  if ( g_nMaxDecals <= 0 )
    goto LABEL_16;
  while ( s_aDecalPool.m_Memory.m_pMemory[v3] != nullptr )
  {
    if ( ++v3 >= g_nMaxDecals )
      goto LABEL_16;
  }
  DynamicDecalSlot = v3;
  if ( v3 == -1 )
  {
LABEL_16:
    DynamicDecalSlot = R_FindDynamicDecalSlot(iStartAt: g_iLastReplacedDynamic + 1);
    if ( DynamicDecalSlot == -1 )
    {
      if ( !bWarningOnce )
      {
        _DevWarning(a1: 1, a2: "Exceeded MAX_DECALS (%d).\n", g_nMaxDecals);
        bWarningOnce = true;
      }
      DynamicDecalSlot = 0;
    }
    R_DecalUnlink(pdecal: s_aDecalPool.m_Memory.m_pMemory[DynamicDecalSlot]);
    g_iLastReplacedDynamic = DynamicDecalSlot;
  }
  result = (decal_t *)CUtlMemoryPool::Alloc(this: &g_DecalAllocator);
  s_aDecalPool.m_Memory.m_pMemory[DynamicDecalSlot] = result;
  result->m_iDecalPool = DynamicDecalSlot;
  result->pDestroyList = nullptr;
  result->surfID = nullptr;
  *(_DWORD *)&result->clippedVertCount = -65536;
  if ( v6 )
    ++g_nStaticDecals;
  else
    ++g_nDynamicDecals;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10100B50
// Name: class CDecalVert __near * R_DecalSetupVerts(struct decalcontext_t __near &,struct decal_t __near *,struct msurface2_t __near *,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
decalcache_t *__cdecl R_DecalSetupVerts(
        decalcontext_t *context,
        decal_t *pDecal,
        msurface2_t *surfID,
        IMaterial *pMaterial)
{
  float m_fValue; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  CDecalVert *v9; // edi
  decalcache_t *CachedVerts; // edi
  float playerOrigin_8; // [esp+8h] [ebp-24h]
  float playerOrigin_8a; // [esp+8h] [ebp-24h]
  float v14; // [esp+Ch] [ebp-20h]
  float v15; // [esp+10h] [ebp-1Ch]
  float originalScale; // [esp+14h] [ebp-18h]
  float nearDist; // [esp+18h] [ebp-14h]
  msurface2_t *nearDista; // [esp+18h] [ebp-14h]
  float fov; // [esp+1Ch] [ebp-10h]

  if ( (pDecal->flags & 0x2000) == 0 || (pDecal->flags & 0x1000) != 0 )
  {
    CachedVerts = CDecalVertCache::GetCachedVerts(this: &g_DecalVertCache, pDecal);
    if ( CachedVerts == nullptr )
    {
      decalcontext_t::InitSurface(this: context, surfID: pDecal->surfID);
      CachedVerts = (decalcache_t *)R_DecalVertsClip(pOutVerts: nullptr, pDecal, surfID, pMaterial);
      if ( pDecal->clippedVertCount != 0 )
      {
        R_DecalVertsLight(v: CachedVerts->decalVert, context, surfID: pDecal->clippedVertCount);
        CDecalVertCache::StoreVertsInCache(this: &g_DecalVertCache, pDecal, pList: CachedVerts->decalVert);
      }
    }
    return CachedVerts;
  }
  else
  {
    fov = r_dscale_farscale.m_pParent->m_Value.m_fValue;
    v15 = g_EngineRenderer->GetFov(this: g_EngineRenderer);
    m_fValue = r_dscale_basefov.m_pParent->m_Value.m_fValue;
    if ( v15 == m_fValue || v15 <= 0.0 || m_fValue <= 0.0 )
    {
      v7 = fov;
      v6 = nearDist;
    }
    else
    {
      v5 = (float)(v15 / m_fValue) * fov;
      v6 = (float)(v15 / m_fValue) * nearDist;
      v7 = v5;
      if ( v6 < 1.0 )
        v6 = 1.0;
      if ( v5 < 1.0 )
        v7 = 1.0;
    }
    if ( v14 <= originalScale )
    {
      if ( originalScale < playerOrigin_8 )
        v8 = (float)((float)((float)(originalScale - v14) / (float)(playerOrigin_8 - v14)) * (float)(v7 - v6)) + v6;
      else
        v8 = v7;
    }
    else
    {
      v8 = 1.0;
    }
    nearDista = pDecal->surfID;
    playerOrigin_8a = pDecal->scale;
    pDecal->scale = (float)(1.0 / v8) * playerOrigin_8a;
    decalcontext_t::InitSurface(this: context, surfID: nearDista);
    v9 = R_DecalVertsClip(pOutVerts: nullptr, pDecal, surfID, pMaterial);
    if ( v9 != nullptr )
      R_DecalVertsLight(v: v9, context, surfID: pDecal->clippedVertCount);
    pDecal->scale = playerOrigin_8a;
    return (decalcache_t *)v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10100E90
// Name: void DecalUpdateAndDrawSingle(struct decalcontext_t __near &,struct msurface2_t __near *,struct decal_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall DecalUpdateAndDrawSingle(int a1@<ebx>, decalcontext_t *context, msurface2_t *surfID, decal_t *pDecal)
{
  CClientState *BaseLocalClient; // eax
  decalcache_t *v6; // eax
  char retire_3; // [esp+1Fh] [ebp+13h]

  if ( pDecal->material != nullptr )
  {
    retire_3 = 0;
    if ( (pDecal->flags & 0x100) != 0 )
    {
      if ( pDecal->fadeDuration <= 0.0
        || (BaseLocalClient = GetBaseLocalClient(),
            retire_3 = 1,
            CClientState::GetTime(this: BaseLocalClient) < pDecal->fadeStartTime + pDecal->fadeDuration) )
      {
        retire_3 = 0;
      }
    }
    if ( (surfID->flags & 0x800) == 0 )
    {
      v6 = R_DecalSetupVerts(context, pDecal, surfID, pMaterial: pDecal->material);
      if ( v6 != nullptr )
        Shader_DecalDrawPoly(
          a1,
          a2: (int)surfID,
          v: v6->decalVert,
          pMaterial: pDecal->material,
          surfID,
          vertCount: pDecal->clippedVertCount,
          pdecal: pDecal,
          flFade: 1.0);
    }
    if ( retire_3 != 0 )
      R_DecalUnlink(pdecal: pDecal);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10100F40
// Name: void DrawDecalsOnSingleSurface_NonQueued(class IMatRenderContext __near *,struct msurface2_t __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawDecalsOnSingleSurface_NonQueued(
        IMatRenderContext *pRenderContext,
        msurface2_t *surfID,
        const Vector *vModelOrg)
{
  decal_t *v3; // esi
  float y; // xmm0_4
  decal_t *pnext; // edi
  decalcontext_t context; // [esp+8h] [ebp-3Ch] BYREF

  if ( surfID->decals == 0xFFFF )
    v3 = nullptr;
  else
    v3 = s_aDecalPool.m_Memory.m_pMemory[surfID->decals];
  context.vModelOrg.x = vModelOrg->x;
  y = vModelOrg->y;
  context.pRenderContext = pRenderContext;
  context.vModelOrg.y = y;
  context.vModelOrg.z = vModelOrg->z;
  context.pSurf = nullptr;
  decalcontext_t::InitSurface(this: &context, surfID);
  if ( v3 != nullptr )
  {
    do
    {
      pnext = v3->pnext;
      if ( (v3->flags & 0x200) == 0 )
        DecalUpdateAndDrawSingle(a1: (int)surfID, &context, surfID, pDecal: v3);
      v3 = pnext;
    }
    while ( pnext != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10100FD0
// Name: void DrawDecalsOnSingleSurface_QueueHelper(struct msurface2_t __near *,class Vector)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawDecalsOnSingleSurface_QueueHelper(msurface2_t *surfID, Vector vModelOrg)
{
  IMatRenderContext *v2; // esi

  v2 = materials->GetRenderContext(this: materials);
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  DrawDecalsOnSingleSurface_NonQueued(pRenderContext: v2, surfID, &vModelOrg);
  if ( v2 != nullptr )
  {
    v2->EndRender(this: v2);
    v2->Release(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10101020
// Name: void R_DrawDecalsAllImmediate_Gathered(class IMatRenderContext __near *,struct decal_t __near * __near *,int,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __usercall R_DrawDecalsAllImmediate_Gathered(
        int m_nIndexCount@<ebx>,
        int a2@<edi>,
        CMeshBuilder *p_meshBuilder@<esi>,
        IMatRenderContext *pRenderContext,
        decal_t **ppDecals,
        int iDecalCount,
        const Vector *vModelOrg,
        float flFade)
{
  float z; // xmm0_4
  int m_nValue; // eax
  int v10; // eax
  decal_t *v11; // esi
  float fadeDuration; // xmm0_4
  CClientState *v13; // eax
  msurface2_t *surfID; // eax
  int clippedVertCount; // ebx
  char v16; // di
  __int64 v17; // rax
  IMesh *v18; // eax
  unsigned __int8 r; // dl
  unsigned __int8 g; // al
  unsigned __int8 a; // cl
  CClientState *v22; // eax
  double v23; // st7
  CClientState *BaseLocalClient; // eax
  float v25; // xmm2_4
  float lightmapOffset; // xmm2_4
  float *m_pCurrPosition; // edx
  int v28; // ecx
  float *p_y; // eax
  float *v30; // edx
  int v31; // xmm1_4
  float *v32; // edx
  int v33; // xmm1_4
  float *v34; // edx
  int v35; // edx
  unsigned int m_nIndexSize; // esi
  unsigned __int16 m_nIndexOffset; // di
  signed int v38; // edx
  unsigned __int16 *v39; // eax
  signed int v40; // ecx
  unsigned __int16 v41; // bx
  unsigned __int16 v42; // si
  int m_nVertexCount; // eax
  int v44; // esi
  decalcontext_t context; // [esp+0h] [ebp-280h] BYREF
  CMeshBuilder meshBuilder; // [esp+3Ch] [ebp-244h] BYREF
  Vector tVect; // [esp+224h] [ebp-5Ch] BYREF
  BOOL bNegate; // [esp+230h] [ebp-50h]
  __int64 v52; // [esp+234h] [ebp-4Ch]
  IMesh *v53; // [esp+240h] [ebp-40h]
  Vector vecTangentS; // [esp+244h] [ebp-3Ch] BYREF
  Vector vecTangentT; // [esp+250h] [ebp-30h] BYREF
  int i; // [esp+25Ch] [ebp-24h]
  msurface2_t *lastSurf; // [esp+260h] [ebp-20h]
  float flFadeValue; // [esp+264h] [ebp-1Ch]
  Vector vecNormal; // [esp+268h] [ebp-18h] BYREF
  int v60; // [esp+274h] [ebp-Ch]
  CDecalVert *pVerts; // [esp+278h] [ebp-8h]
  unsigned __int8 color[4]; // [esp+27Ch] [ebp-4h]
  bool bWireframe_3; // [esp+297h] [ebp+17h]

  context.pRenderContext = pRenderContext;
  context.vModelOrg.x = vModelOrg->x;
  context.vModelOrg.y = vModelOrg->y;
  z = vModelOrg->z;
  lastSurf = nullptr;
  context.vModelOrg.z = z;
  context.pSurf = nullptr;
  bWireframe_3 = (sv_cheats.m_pParent != nullptr && sv_cheats.m_pParent->m_Value.m_nValue != 0 || Cmd_IsRptActive())
              && (mat_wireframe.m_pParent == nullptr
                ? (m_nValue = 0)
                : (m_nValue = mat_wireframe.m_pParent->m_Value.m_nValue),
                  m_nValue != 0)
              || r_drawdecals.m_pParent != nullptr && r_drawdecals.m_pParent->m_Value.m_nValue == 2;
  v10 = 0;
  for ( i = 0; v10 != iDecalCount; i = v10 )
  {
    v11 = ppDecals[v10];
    if ( (v11->flags & 0x100) == 0
      || (v11->flags & 0x4000) != 0
      || (fadeDuration = v11->fadeDuration, v11->flags |= 0x4000u, fadeDuration <= 0.0)
      || (v13 = GetBaseLocalClient(), CClientState::GetTime(this: v13) < v11->fadeStartTime + v11->fadeDuration) )
    {
      surfID = v11->surfID;
      if ( surfID != lastSurf )
        lastSurf = v11->surfID;
      pVerts = (CDecalVert *)R_DecalSetupVerts(&context, pDecal: v11, surfID, pMaterial: v11->material);
      if ( pVerts != nullptr )
      {
        clippedVertCount = v11->clippedVertCount;
        v16 = 0;
        v53 = nullptr;
        if ( bWireframe_3 )
        {
          ((void (__thiscall *)(IMatRenderContext *, IMaterial *, _DWORD, int, int, CMeshBuilder *))pRenderContext->Bind)(
            a1: pRenderContext,
            a2: g_materialDecalWireframe,
            a3: 0,
            a4: a2,
            a5: m_nIndexCount,
            a6: p_meshBuilder);
        }
        else
        {
          ((void (__thiscall *)(IMatRenderContext *, int, int, int, CMeshBuilder *))pRenderContext->BindLightmapPage)(
            a1: pRenderContext,
            a2: materialSortInfoArray[v11->surfID->materialSortID].lightmapPageID,
            a3: a2,
            a4: m_nIndexCount,
            a5: p_meshBuilder);
          pRenderContext->Bind(this: pRenderContext, a2: v11->material, a3: v11->userdata);
          v17 = ((__int64 (__thiscall *)(IMaterial *, _DWORD, _DWORD, _DWORD))v11->material->GetVertexFormat)(
                  a1: v11->material,
                  a2: LODWORD(context.vModelOrg.x),
                  a3: LODWORD(context.vModelOrg.y),
                  a4: LODWORD(context.vModelOrg.z));
          v16 = v17;
          v53 = (IMesh *)HIDWORD(v17);
        }
        v18 = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 1, a3: 0, a4: 0, a5: 0);
        meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
        meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
        meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
        meshBuilder.m_pMesh = nullptr;
        meshBuilder.m_bGenerateIndices = false;
        memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
        meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
        meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
        meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
        meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
        memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
        meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
        v53 = v18;
        v60 = clippedVertCount - 2;
        CMeshBuilder::Begin(
          this: &meshBuilder,
          pMesh: v18,
          type: MATERIAL_TRIANGLES,
          nVertexCount: clippedVertCount,
          nIndexCount: 3 * (clippedVertCount - 2),
          pMeshSettings: nullptr);
        r = v11->color.r;
        g = v11->color.g;
        color[2] = v11->color.b;
        a = v11->color.a;
        color[0] = r;
        color[1] = g;
        color[3] = a;
        if ( flFade != 1.0 )
          color[3] = (int)(float)((float)a * flFade);
        if ( (v11->flags & 0x100) != 0 )
        {
          if ( v11->fadeDuration >= 0.0 )
          {
            BaseLocalClient = GetBaseLocalClient();
            v23 = 1.0 - (CClientState::GetTime(this: BaseLocalClient) - v11->fadeStartTime) / v11->fadeDuration;
          }
          else
          {
            v22 = GetBaseLocalClient();
            v23 = -((CClientState::GetTime(this: v22) - v11->fadeStartTime) / v11->fadeDuration);
          }
          flFadeValue = v23;
          v25 = flFadeValue;
          if ( flFadeValue >= 0.0 )
          {
            if ( flFadeValue > 1.0 )
              v25 = 1.0;
          }
          else
          {
            v25 = 0.0;
          }
          color[3] = (int)(float)((float)color[3] * v25);
        }
        vecNormal.x = 0.0;
        vecNormal.y = 0.0;
        vecNormal.z = 1.0;
        vecTangentS.x = 1.0;
        vecTangentS.y = 0.0;
        vecTangentS.z = 0.0;
        vecTangentT.x = 0.0;
        vecTangentT.y = 1.0;
        vecTangentT.z = 0.0;
        if ( (v16 & 0x32) != 0 )
        {
          vecNormal = v11->surfID->plane->normal;
          if ( (v16 & 0x30) != 0 )
          {
            LOBYTE(bNegate) = TangentSpaceSurfaceSetup(surfID: v11->surfID, &tVect);
            TangentSpaceComputeBasis(
              tangentS: &vecTangentS,
              tangentT: &vecTangentT,
              normal: &vecNormal,
              &tVect,
              negateTangent: bNegate);
          }
        }
        lightmapOffset = v11->lightmapOffset;
        if ( clippedVertCount > 0 )
        {
          m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
          v28 = color[2] | ((color[1] | ((color[0] | (color[3] << 8)) << 8)) << 8);
          v52 = v16 & 0x30;
          p_y = &pVerts->m_vPos.y;
          do
          {
            *m_pCurrPosition = *(p_y - 1);
            m_pCurrPosition[1] = *p_y;
            m_pCurrPosition[2] = p_y[1];
            if ( (v16 & 2) != 0 )
              *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = vecNormal;
            *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v28;
            v30 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
            v31 = *((_DWORD *)p_y + 4);
            *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = p_y[3];
            *((_DWORD *)v30 + 1) = v31;
            v32 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
            v33 = *((_DWORD *)p_y + 6);
            *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = p_y[5];
            *((_DWORD *)v32 + 1) = v33;
            v34 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2];
            *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = lightmapOffset;
            v34[1] = 0.0;
            if ( v52 != 0 )
            {
              *(Vector *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                        + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                        * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS) = vecTangentS;
              *(Vector *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                        + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                        * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT) = vecTangentT;
            }
            v35 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
            meshBuilder.m_VertexBuilder.m_nCurrentVertex = v35;
            if ( v35 > meshBuilder.m_VertexBuilder.m_nVertexCount )
              meshBuilder.m_VertexBuilder.m_nVertexCount = v35;
            meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                                + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
            meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
            meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                     + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
            meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                                     + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
            m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                      + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
            meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                                     + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
            p_y += 8;
            --clippedVertCount;
            meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
          }
          while ( clippedVertCount != 0 );
        }
        m_nIndexSize = meshBuilder.m_IndexBuilder.m_nIndexSize;
        m_nIndexOffset = meshBuilder.m_IndexBuilder.m_nIndexOffset;
        v38 = v60 * meshBuilder.m_IndexBuilder.m_nIndexSize;
        v39 = &meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex];
        v40 = 0;
        if ( (signed int)(v60 * meshBuilder.m_IndexBuilder.m_nIndexSize) > 0 )
        {
          v60 = meshBuilder.m_IndexBuilder.m_nIndexOffset + 1;
          pVerts = (CDecalVert *)(meshBuilder.m_IndexBuilder.m_nIndexOffset + 2);
          do
          {
            v41 = v40 + v60;
            v42 = (_WORD)pVerts + v40;
            *v39 = m_nIndexOffset;
            v39[1] = v41;
            v39[2] = v42;
            ++v40;
            v39 += 3;
          }
          while ( v40 < v38 );
          m_nIndexSize = meshBuilder.m_IndexBuilder.m_nIndexSize;
        }
        m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
        v44 = v38 * m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex + 2 * v38 * m_nIndexSize;
        meshBuilder.m_IndexBuilder.m_nCurrentIndex = v44;
        if ( v44 > meshBuilder.m_IndexBuilder.m_nIndexCount )
          meshBuilder.m_IndexBuilder.m_nIndexCount = v44;
        if ( meshBuilder.m_bGenerateIndices )
        {
          switch ( meshBuilder.m_Type )
          {
            case MATERIAL_LINE_STRIP:
              m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
              break;
            case MATERIAL_LINE_LOOP:
              m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
              break;
            case MATERIAL_POLYGON:
              m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
              break;
            case MATERIAL_QUADS:
              m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
              break;
            case MATERIAL_INSTANCED_QUADS:
              m_nVertexCount = 0;
              break;
            default:
              break;
          }
          CIndexBuilder::GenerateIndices(
            this: &meshBuilder.m_IndexBuilder,
            primitiveType: meshBuilder.m_Type,
            nIndexCount: m_nVertexCount);
          m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
        }
        p_meshBuilder = &meshBuilder;
        m_nIndexCount = meshBuilder.m_IndexBuilder.m_nIndexCount;
        a2 = m_nVertexCount;
        ((void (__thiscall *)(IMesh *))meshBuilder.m_pMesh->UnlockMesh)(a1: meshBuilder.m_pMesh);
        meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
        meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
        meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
        meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
        meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
        meshBuilder.m_pMesh = nullptr;
        v53->Draw_2(this: v53, a2: -1, a3: 0);
        if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
          && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
        {
          meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
        }
        if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
          && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
        {
          meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
        }
      }
    }
    else if ( v11->pDestroyList == nullptr )
    {
      v11->pDestroyList = s_pDecalDestroyList;
      s_pDecalDestroyList = v11;
    }
    v10 = i + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101016F0
// Name: void R_DrawDecalsAllImmediate(class IMatRenderContext __near *,int,int,class Vector const __near &,int,float)
// Source: json
//------------------------------------------------------------------------------
void __usercall R_DrawDecalsAllImmediate(
        int a1@<ebx>,
        int m_nIndexCount@<edi>,
        CMeshBuilder *p_meshBuilder@<esi>,
        IMatRenderContext *pRenderContext,
        int iGroup,
        int iTreeType,
        const Vector *vModelOrg,
        int nCheckCount,
        float flFade)
{
  int m_Size; // esi
  float z; // xmm0_4
  int m_nValue; // eax
  DecalSortTrees_t *m_pMemory; // ecx
  int v13; // edi
  int v14; // esi
  int v15; // edx
  int v16; // eax
  bool v17; // zf
  int **v18; // eax
  int *v19; // eax
  int v20; // esi
  float v21; // xmm0_4
  CClientState *v22; // eax
  msurface2_t *v23; // eax
  int v24; // ebx
  char v25; // di
  __int64 v26; // rax
  IMesh *v27; // eax
  unsigned __int8 v28; // dl
  unsigned __int8 v29; // al
  unsigned __int8 v30; // cl
  CClientState *v31; // eax
  double v32; // st7
  CClientState *BaseLocalClient; // eax
  float v34; // xmm2_4
  int v35; // xmm1_4
  float *m_pCurrPosition; // edx
  int v37; // ecx
  float *p_y; // eax
  float *v39; // edx
  int v40; // xmm0_4
  float *v41; // edx
  int v42; // xmm0_4
  int v43; // edx
  unsigned int m_nIndexSize; // esi
  unsigned __int16 m_nIndexOffset; // di
  signed int v46; // edx
  unsigned __int16 *v47; // eax
  signed int v48; // ecx
  unsigned __int16 v49; // bx
  int m_nVertexCount; // eax
  int v51; // esi
  decalcontext_t context; // [esp+0h] [ebp-294h] BYREF
  CMeshBuilder meshBuilder; // [esp+3Ch] [ebp-258h] BYREF
  Vector tVect; // [esp+224h] [ebp-70h] BYREF
  BOOL bNegate; // [esp+230h] [ebp-64h]
  int nBucketCount; // [esp+234h] [ebp-60h]
  __int64 v60; // [esp+238h] [ebp-5Ch]
  IMesh *v61; // [esp+244h] [ebp-50h]
  Vector vecTangentS; // [esp+248h] [ebp-4Ch] BYREF
  Vector vecTangentT; // [esp+254h] [ebp-40h] BYREF
  int iBucket; // [esp+260h] [ebp-34h]
  int iElement; // [esp+264h] [ebp-30h]
  float flFadeValue; // [esp+268h] [ebp-2Ch]
  int v67; // [esp+26Ch] [ebp-28h]
  msurface2_t *lastSurf; // [esp+270h] [ebp-24h]
  int v69; // [esp+274h] [ebp-20h]
  Vector vecNormal; // [esp+278h] [ebp-1Ch] BYREF
  int v71; // [esp+284h] [ebp-10h]
  int v72; // [esp+288h] [ebp-Ch]
  CDecalVert *pVerts; // [esp+28Ch] [ebp-8h]
  unsigned __int8 color[4]; // [esp+290h] [ebp-4h]
  bool bWireframe_3; // [esp+2ABh] [ebp+17h]

  context.pRenderContext = pRenderContext;
  context.vModelOrg.x = vModelOrg->x;
  m_Size = g_aDecalSortTrees.m_Size;
  context.vModelOrg.y = vModelOrg->y;
  z = vModelOrg->z;
  lastSurf = nullptr;
  context.vModelOrg.z = z;
  context.pSurf = nullptr;
  bWireframe_3 = (sv_cheats.m_pParent != nullptr && sv_cheats.m_pParent->m_Value.m_nValue != 0 || Cmd_IsRptActive())
              && (mat_wireframe.m_pParent == nullptr
                ? (m_nValue = 0)
                : (m_nValue = mat_wireframe.m_pParent->m_Value.m_nValue),
                  m_nValue != 0)
              || r_drawdecals.m_pParent != nullptr && r_drawdecals.m_pParent->m_Value.m_nValue == 2;
  if ( m_Size > 0 )
  {
    m_pMemory = g_aDecalSortTrees.m_Memory.m_pMemory;
    v13 = 20 * (iGroup + iTreeType + 2 * iGroup);
    v67 = v13;
    v71 = v13 + 12;
    v69 = m_Size;
    do
    {
      v14 = *(int *)((char *)&m_pMemory->m_aDecalSortBuckets[0][0].m_Size + v13);
      v15 = 0;
      nBucketCount = v14;
      for ( iBucket = 0; v15 < v14; iBucket = v15 )
      {
        v16 = *(int *)((char *)m_pMemory->m_pTrees + v71);
        v17 = *(_DWORD *)(v16 + 8 * v15 + 4) == nCheckCount;
        v18 = (int **)(v16 + 8 * v15);
        if ( v17 )
        {
          v19 = *v18;
          if ( v19 != nullptr )
          {
            while ( 1 )
            {
              v20 = *v19;
              iElement = v19[2];
              if ( v20 != 0 )
              {
                if ( (*(_WORD *)(v20 + 84) & 0x100) == 0
                  || (*(_WORD *)(v20 + 84) & 0x4000) != 0
                  || (v21 = *(float *)(v20 + 60), *(_WORD *)(v20 + 84) |= 0x4000u, v21 <= 0.0)
                  || (v22 = GetBaseLocalClient(),
                      CClientState::GetTime(this: v22) < *(float *)(v20 + 64) + *(float *)(v20 + 60)) )
                {
                  v23 = *(msurface2_t **)(v20 + 8);
                  if ( v23 != lastSurf )
                    lastSurf = *(msurface2_t **)(v20 + 8);
                  pVerts = (CDecalVert *)R_DecalSetupVerts(
                                           &context,
                                           pDecal: (decal_t *)v20,
                                           surfID: v23,
                                           pMaterial: *(IMaterial **)(v20 + 12));
                  if ( pVerts != nullptr )
                  {
                    v24 = *(unsigned __int16 *)(v20 + 78);
                    v25 = 0;
                    v61 = nullptr;
                    if ( bWireframe_3 )
                    {
                      ((void (__thiscall *)(IMatRenderContext *, IMaterial *, _DWORD, int, int, CMeshBuilder *))pRenderContext->Bind)(
                        a1: pRenderContext,
                        a2: g_materialDecalWireframe,
                        a3: 0,
                        a4: a1,
                        a5: m_nIndexCount,
                        a6: p_meshBuilder);
                    }
                    else
                    {
                      ((void (__thiscall *)(IMatRenderContext *, int, int, int, CMeshBuilder *))pRenderContext->BindLightmapPage)(
                        a1: pRenderContext,
                        a2: materialSortInfoArray[*(__int16 *)(*(_DWORD *)(v20 + 8) + 18)].lightmapPageID,
                        a3: a1,
                        a4: m_nIndexCount,
                        a5: p_meshBuilder);
                      pRenderContext->Bind(
                        this: pRenderContext,
                        a2: *(IMaterial **)(v20 + 12),
                        a3: *(void **)(v20 + 72));
                      v26 = ((__int64 (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD))*(_DWORD *)(**(_DWORD **)(v20 + 12)
                                                                                               + 80))(
                              a1: *(_DWORD *)(v20 + 12),
                              a2: LODWORD(context.vModelOrg.x),
                              a3: LODWORD(context.vModelOrg.y),
                              a4: LODWORD(context.vModelOrg.z));
                      v25 = v26;
                      v61 = (IMesh *)HIDWORD(v26);
                    }
                    v27 = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 1, a3: 0, a4: 0, a5: 0);
                    meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
                    meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
                    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
                    meshBuilder.m_pMesh = nullptr;
                    meshBuilder.m_bGenerateIndices = false;
                    memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
                    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
                    meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
                    meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
                    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
                    meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
                    memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
                    meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
                    v61 = v27;
                    v72 = v24 - 2;
                    CMeshBuilder::Begin(
                      this: &meshBuilder,
                      pMesh: v27,
                      type: MATERIAL_TRIANGLES,
                      nVertexCount: v24,
                      nIndexCount: 3 * (v24 - 2),
                      pMeshSettings: nullptr);
                    v28 = *(_BYTE *)(v20 + 68);
                    v29 = *(_BYTE *)(v20 + 69);
                    color[2] = *(_BYTE *)(v20 + 70);
                    v30 = *(_BYTE *)(v20 + 71);
                    color[0] = v28;
                    color[1] = v29;
                    color[3] = v30;
                    if ( flFade != 1.0 )
                      color[3] = (int)(float)((float)v30 * flFade);
                    if ( (*(_WORD *)(v20 + 84) & 0x100) != 0 )
                    {
                      if ( *(float *)(v20 + 60) >= 0.0 )
                      {
                        BaseLocalClient = GetBaseLocalClient();
                        v32 = 1.0
                            - (CClientState::GetTime(this: BaseLocalClient) - *(float *)(v20 + 64))
                            / *(float *)(v20 + 60);
                      }
                      else
                      {
                        v31 = GetBaseLocalClient();
                        v32 = -((CClientState::GetTime(this: v31) - *(float *)(v20 + 64)) / *(float *)(v20 + 60));
                      }
                      flFadeValue = v32;
                      v34 = flFadeValue;
                      if ( flFadeValue >= 0.0 )
                      {
                        if ( flFadeValue > 1.0 )
                          v34 = 1.0;
                      }
                      else
                      {
                        v34 = 0.0;
                      }
                      color[3] = (int)(float)((float)color[3] * v34);
                    }
                    vecNormal.x = 0.0;
                    vecNormal.y = 0.0;
                    vecNormal.z = 1.0;
                    vecTangentS.x = 1.0;
                    vecTangentS.y = 0.0;
                    vecTangentS.z = 0.0;
                    vecTangentT.x = 0.0;
                    vecTangentT.y = 1.0;
                    vecTangentT.z = 0.0;
                    if ( (v25 & 0x32) != 0 )
                    {
                      vecNormal = *(Vector *)*(_DWORD *)(*(_DWORD *)(v20 + 8) + 4);
                      if ( (v25 & 0x30) != 0 )
                      {
                        LOBYTE(bNegate) = TangentSpaceSurfaceSetup(surfID: *(msurface2_t **)(v20 + 8), &tVect);
                        TangentSpaceComputeBasis(
                          tangentS: &vecTangentS,
                          tangentT: &vecTangentT,
                          normal: &vecNormal,
                          &tVect,
                          negateTangent: bNegate);
                      }
                    }
                    v35 = *(_DWORD *)(v20 + 16);
                    if ( v24 > 0 )
                    {
                      m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
                      v37 = color[2] | ((color[1] | ((color[0] | (color[3] << 8)) << 8)) << 8);
                      v60 = v25 & 0x30;
                      p_y = &pVerts->m_vPos.y;
                      do
                      {
                        *m_pCurrPosition = *(p_y - 1);
                        m_pCurrPosition[1] = *p_y;
                        m_pCurrPosition[2] = p_y[1];
                        if ( (v25 & 2) != 0 )
                          *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = vecNormal;
                        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v37;
                        v39 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
                        v40 = *((_DWORD *)p_y + 4);
                        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = p_y[3];
                        *((_DWORD *)v39 + 1) = v40;
                        v41 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
                        v42 = *((_DWORD *)p_y + 6);
                        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = p_y[5];
                        *((_DWORD *)v41 + 1) = v42;
                        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = v35;
                        if ( v60 != 0 )
                        {
                          *(Vector *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                                    + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                    * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS) = vecTangentS;
                          *(Vector *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                                    + meshBuilder.m_VertexBuilder.m_nCurrentVertex
                                    * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT) = vecTangentT;
                        }
                        v43 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
                        meshBuilder.m_VertexBuilder.m_nCurrentVertex = v43;
                        if ( v43 > meshBuilder.m_VertexBuilder.m_nVertexCount )
                          meshBuilder.m_VertexBuilder.m_nVertexCount = v43;
                        meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                                            + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
                        meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
                        meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                                 + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
                        meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                                                 + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
                        m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                        meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                                                 + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
                        p_y += 8;
                        --v24;
                        meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                                              + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
                      }
                      while ( v24 != 0 );
                    }
                    m_nIndexSize = meshBuilder.m_IndexBuilder.m_nIndexSize;
                    m_nIndexOffset = meshBuilder.m_IndexBuilder.m_nIndexOffset;
                    v46 = v72 * meshBuilder.m_IndexBuilder.m_nIndexSize;
                    v47 = &meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex];
                    v48 = 0;
                    if ( (signed int)(v72 * meshBuilder.m_IndexBuilder.m_nIndexSize) > 0 )
                    {
                      v72 = meshBuilder.m_IndexBuilder.m_nIndexOffset + 1;
                      pVerts = (CDecalVert *)(meshBuilder.m_IndexBuilder.m_nIndexOffset + 2);
                      do
                      {
                        v49 = v48 + v72;
                        *v47 = m_nIndexOffset;
                        v47[1] = v49;
                        v47[2] = v48++ + (_WORD)pVerts;
                        v47 += 3;
                      }
                      while ( v48 < v46 );
                      m_nIndexSize = meshBuilder.m_IndexBuilder.m_nIndexSize;
                    }
                    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
                    v51 = v46 * m_nIndexSize + meshBuilder.m_IndexBuilder.m_nCurrentIndex + 2 * v46 * m_nIndexSize;
                    meshBuilder.m_IndexBuilder.m_nCurrentIndex = v51;
                    if ( v51 > meshBuilder.m_IndexBuilder.m_nIndexCount )
                      meshBuilder.m_IndexBuilder.m_nIndexCount = v51;
                    if ( meshBuilder.m_bGenerateIndices )
                    {
                      switch ( meshBuilder.m_Type )
                      {
                        case MATERIAL_LINE_STRIP:
                          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
                          break;
                        case MATERIAL_LINE_LOOP:
                          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
                          break;
                        case MATERIAL_POLYGON:
                          m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
                          break;
                        case MATERIAL_QUADS:
                          m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
                          break;
                        case MATERIAL_INSTANCED_QUADS:
                          m_nVertexCount = 0;
                          break;
                        default:
                          break;
                      }
                      CIndexBuilder::GenerateIndices(
                        this: &meshBuilder.m_IndexBuilder,
                        primitiveType: meshBuilder.m_Type,
                        nIndexCount: m_nVertexCount);
                      m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
                    }
                    p_meshBuilder = &meshBuilder;
                    m_nIndexCount = meshBuilder.m_IndexBuilder.m_nIndexCount;
                    a1 = m_nVertexCount;
                    ((void (__thiscall *)(IMesh *))meshBuilder.m_pMesh->UnlockMesh)(a1: meshBuilder.m_pMesh);
                    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
                    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
                    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
                    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
                    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
                    meshBuilder.m_pMesh = nullptr;
                    v61->Draw_2(this: v61, a2: -1, a3: 0);
                    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
                      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
                    {
                      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
                    }
                    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
                      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
                    {
                      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
                    }
                  }
                }
                else if ( *(_DWORD *)(v20 + 4) == 0 )
                {
                  *(_DWORD *)(v20 + 4) = s_pDecalDestroyList;
                  s_pDecalDestroyList = (decal_t *)v20;
                }
              }
              if ( iElement == 0 )
                break;
              v19 = (int *)iElement;
            }
            m_pMemory = g_aDecalSortTrees.m_Memory.m_pMemory;
            v13 = v67;
            v14 = nBucketCount;
            v15 = iBucket;
          }
        }
        ++v15;
      }
      v71 += 312;
      v13 += 312;
      v17 = v69-- == 1;
      v67 = v13;
    }
    while ( !v17 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10101E50
// Name: void R_DrawDecalMeshList(struct DecalMeshList_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall R_DrawDecalMeshList(int a1@<ebx>, int a2@<esi>, DecalMeshList_t *meshList)
{
  IMatRenderContext *v3; // edi
  DecalMeshList_t *v4; // ebx
  char *v5; // esi
  IMatRenderContext_vtbl *v6; // edx

  v3 = materials->GetRenderContext(this: materials);
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  v4 = meshList;
  if ( meshList->m_aBatches.m_Size > 0 )
  {
    v5 = &meshList->m_aBatches.m_Memory.m_Memory[4];
    meshList = (DecalMeshList_t *)meshList->m_aBatches.m_Size;
    do
    {
      v6 = v3->__vftable;
      if ( g_pMaterialSystemConfig->nFullbright == 1 )
        ((void (__thiscall *)(IMatRenderContext *, int, int, int))v6->BindLightmapPage)(a1: v3, a2: -1, a3: a2, a4: a1);
      else
        ((void (__thiscall *)(IMatRenderContext *, _DWORD, int, int))v6->BindLightmapPage)(
          a1: v3,
          a2: *((_DWORD *)v5 + 1),
          a3: a2,
          a4: a1);
      a1 = *(_DWORD *)v5;
      a2 = *((_DWORD *)v5 - 1);
      ((void (__thiscall *)(IMatRenderContext *))v3->Bind)(a1: v3);
      ((void (__stdcall *)(_DWORD, _DWORD))v4->m_pMesh->Draw_2)(
        a1: *((unsigned __int16 *)v5 + 4),
        a2: *((unsigned __int16 *)v5 + 5));
      v5 += 16;
      meshList = (DecalMeshList_t *)((char *)meshList - 1);
    }
    while ( meshList != nullptr );
  }
  if ( v3 != nullptr )
  {
    v3->EndRender(this: v3);
    ((void (__thiscall *)(IMatRenderContext *, DecalMeshList_t *))v3->Release)(a1: v3, a2: meshList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101025F0
// Name: void DecalSurfacesInit(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DecalSurfacesInit(bool bBrushModel)
{
  if ( bBrushModel )
  {
    ++g_nBrushModelDecalSortCheckCount;
  }
  else
  {
    CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::RemoveAll(this: &g_aDecalSortPool);
    ++g_nDecalSortCheckCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10102620
// Name: void R_DrawDecalsAllImmediate_GatherDecals(class IMatRenderContext __near *,int,int,class CUtlVector<struct decal_t __near *,class CUtlMemory<struct decal_t __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DrawDecalsAllImmediate_GatherDecals(
        IMatRenderContext *pRenderContext,
        int iGroup,
        int iTreeType,
        CUtlVector<decal_t *,CUtlMemory<decal_t *,int> > *DrawDecals)
{
  int v4; // edi
  DecalSortTrees_t *m_pMemory; // ecx
  int v6; // edx
  int v7; // eax
  int v8; // ebx
  decal_t ***v9; // eax
  decal_t **v10; // ebx
  decal_t *v11; // eax
  int v12; // edi
  int m_nAllocationCount; // eax
  decal_t **v14; // ecx
  int v15; // eax
  decal_t **v16; // eax
  bool v17; // zf
  int nBucketCount; // [esp+0h] [ebp-18h]
  decal_t *pDecal; // [esp+4h] [ebp-14h]
  int m_Size; // [esp+8h] [ebp-10h]
  int v21; // [esp+Ch] [ebp-Ch]
  int iBucket; // [esp+10h] [ebp-8h]
  int nCheckCount; // [esp+14h] [ebp-4h]
  int iGroupa; // [esp+24h] [ebp+Ch]

  nCheckCount = g_nDecalSortCheckCount;
  if ( iGroup == 4 )
    nCheckCount = g_nBrushModelDecalSortCheckCount;
  if ( g_aDecalSortTrees.m_Size > 0 )
  {
    v4 = 20 * (iGroup + iTreeType + 2 * iGroup);
    iGroupa = v4 + 12;
    m_pMemory = g_aDecalSortTrees.m_Memory.m_pMemory;
    v21 = v4;
    m_Size = g_aDecalSortTrees.m_Size;
    do
    {
      v6 = 0;
      nBucketCount = *(int *)((char *)&m_pMemory->m_aDecalSortBuckets[0][0].m_Size + v4);
      iBucket = 0;
      if ( nBucketCount > 0 )
      {
        do
        {
          v7 = *(int *)((char *)m_pMemory->m_pTrees + iGroupa);
          v8 = *(_DWORD *)(v7 + 8 * v6 + 4);
          v9 = (decal_t ***)(v7 + 8 * v6);
          if ( v8 == nCheckCount )
          {
            v10 = *v9;
            if ( *v9 != nullptr )
            {
              do
              {
                v11 = *v10;
                v10 = (decal_t **)v10[2];
                pDecal = v11;
                if ( v11 != nullptr )
                {
                  v12 = DrawDecals->m_Size;
                  m_nAllocationCount = DrawDecals->m_Memory.m_nAllocationCount;
                  if ( v12 + 1 > m_nAllocationCount )
                    CUtlMemory<INetMessage *,int>::Grow(
                      this: (CUtlMemory<S3RGBA,int> *)DrawDecals,
                      num: v12 - m_nAllocationCount + 1);
                  ++DrawDecals->m_Size;
                  v14 = DrawDecals->m_Memory.m_pMemory;
                  v15 = DrawDecals->m_Size - v12 - 1;
                  DrawDecals->m_pElements = DrawDecals->m_Memory.m_pMemory;
                  if ( v15 > 0 )
                    _V_memmove(dest: &v14[v12 + 1], src: &v14[v12], count: 4 * v15);
                  v16 = &DrawDecals->m_Memory.m_pMemory[v12];
                  if ( v16 != nullptr )
                    *v16 = pDecal;
                }
              }
              while ( v10 != nullptr );
              m_pMemory = g_aDecalSortTrees.m_Memory.m_pMemory;
              v4 = v21;
              v6 = iBucket;
            }
          }
          iBucket = ++v6;
        }
        while ( v6 < nBucketCount );
      }
      iGroupa += 312;
      v4 += 312;
      v17 = m_Size-- == 1;
      v21 = v4;
    }
    while ( !v17 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10102740
// Name: void R_DrawDecalsAll_GatherDecals(class IMatRenderContext __near *,int,int,class CUtlVector<struct decal_t __near *,class CUtlMemory<struct decal_t __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DrawDecalsAll_GatherDecals(
        IMatRenderContext *pRenderContext,
        int iGroup,
        int iTreeType,
        CUtlVector<decal_t *,CUtlMemory<decal_t *,int> > *DrawDecals)
{
  int v4; // ebx
  int v5; // edi
  int m_nAllocationCount; // eax
  decal_t **m_pMemory; // ecx
  int v8; // eax
  decal_t **v9; // eax
  DecalSortTrees_t *v10; // eax
  int v11; // edi
  int v12; // eax
  decal_t **v13; // ebx
  IMaterial *material; // ecx
  __int64 v15; // rax
  int v16; // edi
  int v17; // eax
  decal_t **v18; // ecx
  int v19; // eax
  decal_t **v20; // eax
  decal_t *v21; // eax
  int v22; // edi
  int v23; // eax
  decal_t **v24; // ecx
  int v25; // eax
  decal_t **v26; // eax
  int nBucketCount; // [esp+0h] [ebp-1Ch]
  decal_t *pDecal; // [esp+4h] [ebp-18h]
  DecalSortTrees_t *sortTree; // [esp+8h] [ebp-14h]
  int m_Size; // [esp+Ch] [ebp-10h]
  int v31; // [esp+10h] [ebp-Ch]
  int iBucket; // [esp+14h] [ebp-8h]
  int nCheckCount; // [esp+18h] [ebp-4h]
  int iGroupa; // [esp+28h] [ebp+Ch]

  nCheckCount = g_nDecalSortCheckCount;
  if ( iGroup == 4 )
    nCheckCount = g_nBrushModelDecalSortCheckCount;
  if ( g_aDecalSortTrees.m_Size > 0 )
  {
    v4 = 20 * (iGroup + iTreeType + 2 * iGroup);
    v31 = v4;
    iGroupa = 0;
    m_Size = g_aDecalSortTrees.m_Size;
    do
    {
      v5 = DrawDecals->m_Size;
      m_nAllocationCount = DrawDecals->m_Memory.m_nAllocationCount;
      if ( v5 + 1 > m_nAllocationCount )
        CUtlMemory<INetMessage *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)DrawDecals,
          num: v5 - m_nAllocationCount + 1);
      ++DrawDecals->m_Size;
      m_pMemory = DrawDecals->m_Memory.m_pMemory;
      v8 = DrawDecals->m_Size - v5 - 1;
      DrawDecals->m_pElements = DrawDecals->m_Memory.m_pMemory;
      if ( v8 > 0 )
        _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: 4 * v8);
      v9 = &DrawDecals->m_Memory.m_pMemory[v5];
      if ( v9 != nullptr )
        *v9 = nullptr;
      v10 = &g_aDecalSortTrees.m_Memory.m_pMemory[iGroupa];
      v11 = 0;
      sortTree = &g_aDecalSortTrees.m_Memory.m_pMemory[iGroupa];
      nBucketCount = *(int *)((char *)&g_aDecalSortTrees.m_Memory.m_pMemory[iGroupa].m_aDecalSortBuckets[0][0].m_Size
                            + v4);
      iBucket = 0;
      if ( nBucketCount > 0 )
      {
        while ( 1 )
        {
          v12 = (int)&(*(DecalMaterialBucket_t **)((char *)&v10->m_aDecalSortBuckets[0][0].m_Memory.m_pMemory + v4))[v11];
          if ( *(_DWORD *)(v12 + 4) == nCheckCount )
          {
            v13 = *(decal_t ***)v12;
            if ( *(_DWORD *)v12 != 0 && (v13[1] != (decal_t *)v13 || v13[2] == (decal_t *)v13) )
            {
              material = (*v13)->material;
              if ( material != nullptr )
              {
                v15 = material->GetVertexFormat(this: material);
                if ( (HIDWORD(v15) | v15 & 0xFFFFFBFF) != 0 )
                {
                  v16 = DrawDecals->m_Size;
                  v17 = DrawDecals->m_Memory.m_nAllocationCount;
                  if ( v16 + 1 > v17 )
                    CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)DrawDecals, num: v16 - v17 + 1);
                  ++DrawDecals->m_Size;
                  v18 = DrawDecals->m_Memory.m_pMemory;
                  v19 = DrawDecals->m_Size - v16 - 1;
                  DrawDecals->m_pElements = DrawDecals->m_Memory.m_pMemory;
                  if ( v19 > 0 )
                    _V_memmove(dest: &v18[v16 + 1], src: &v18[v16], count: 4 * v19);
                  v20 = &DrawDecals->m_Memory.m_pMemory[v16];
                  if ( v20 != nullptr )
                    *v20 = (decal_t *)-1;
                  do
                  {
                    v21 = *v13;
                    v13 = (decal_t **)v13[2];
                    pDecal = v21;
                    if ( v21 != nullptr )
                    {
                      v22 = DrawDecals->m_Size;
                      v23 = DrawDecals->m_Memory.m_nAllocationCount;
                      if ( v22 + 1 > v23 )
                        CUtlMemory<INetMessage *,int>::Grow(
                          this: (CUtlMemory<S3RGBA,int> *)DrawDecals,
                          num: v22 - v23 + 1);
                      ++DrawDecals->m_Size;
                      v24 = DrawDecals->m_Memory.m_pMemory;
                      v25 = DrawDecals->m_Size - v22 - 1;
                      DrawDecals->m_pElements = DrawDecals->m_Memory.m_pMemory;
                      if ( v25 > 0 )
                        _V_memmove(dest: &v24[v22 + 1], src: &v24[v22], count: 4 * v25);
                      v26 = &DrawDecals->m_Memory.m_pMemory[v22];
                      if ( v26 != nullptr )
                        *v26 = pDecal;
                    }
                  }
                  while ( v13 != nullptr );
                  v11 = iBucket;
                }
              }
            }
          }
          v4 = v31;
          iBucket = ++v11;
          if ( v11 >= nBucketCount )
            break;
          v10 = sortTree;
        }
      }
      ++iGroupa;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10102930
// Name: void DecalSurfaceAdd(struct msurface2_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DecalSurfaceAdd(int surfID, int iGroup)
{
  decal_t *v2; // esi
  int v3; // ebx
  decal_t **v4; // edi
  DecalMaterialBucket_t *v5; // esi
  decal_t *pNext; // [esp+0h] [ebp-4h]
  int nCheckCount; // [esp+Ch] [ebp+8h]

  if ( *(_WORD *)(surfID + 12) != 0xFFFF )
  {
    v2 = s_aDecalPool.m_Memory.m_pMemory[*(unsigned __int16 *)(surfID + 12)];
    if ( v2 != nullptr )
    {
      nCheckCount = g_nDecalSortCheckCount;
      if ( iGroup == 4 )
        nCheckCount = g_nBrushModelDecalSortCheckCount;
      do
      {
        pNext = v2->pnext;
        if ( v2->material->GetPropertyFlag(this: v2->material, a2: MATERIAL_PROPERTY_NEEDS_LIGHTMAP) )
          v3 = (v2->flags & 1) == 0;
        else
          v3 = 2;
        v2->flags &= ~0x4000u;
        v4 = (decal_t **)CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int>>>::AllocInternal(
                           this: &g_aDecalSortPool,
                           multilist: true);
        if ( v4 != nullptr )
        {
          *v4 = v2;
          v5 = &g_aDecalSortTrees.m_Memory.m_pMemory[v2->m_iSortTree].m_aDecalSortBuckets[0][2 * iGroup + iGroup + v3].m_Memory.m_pMemory[v2->m_iSortMaterial];
          if ( v5->m_nCheckCount == nCheckCount )
            CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::LinkBefore(
              this: &g_aDecalSortPool,
              before: v5->m_iHead,
              elem: (int)v4);
          v5->m_iHead = (int)v4;
          v5->m_nCheckCount = nCheckCount;
        }
        v2 = pNext;
      }
      while ( pNext != nullptr );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10102BF0
// Name: public: DecalSortTrees_t::DecalSortTrees_t(void)
// Source: json
//------------------------------------------------------------------------------
DecalSortTrees_t *__thiscall DecalSortTrees_t::DecalSortTrees_t(DecalSortTrees_t *this)
{
  CUtlVector<DecalMaterialBucket_t,CUtlMemory<DecalMaterialBucket_t,int> > *v1; // eax
  int i; // ecx
  int j; // ebx
  CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl*)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int> > *v4; // eax
  CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl*)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int> > *v5; // esi

  v1 = this->m_aDecalSortBuckets[0];
  for ( i = 14; i >= 0; --i )
  {
    v1->m_Memory.m_pMemory = nullptr;
    v1->m_Memory.m_nAllocationCount = 0;
    v1->m_Memory.m_nGrowSize = 0;
    v1->m_Size = 0;
    v1->m_pElements = nullptr;
    ++v1;
  }
  for ( j = 0; j < 3; ++j )
  {
    v4 = (CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl*)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int> > *)MemAlloc_Alloc(nSize: 0x24u);
    v5 = v4;
    if ( v4 != nullptr )
    {
      v4->m_LessFunc = DecalSortTreeSortLessFunc;
      v4->m_Elements.m_nAllocationCount = 16;
      v4->m_Elements.m_nGrowSize = 16;
      v4->m_Elements.m_pMemory = nullptr;
      v4->m_Elements.m_pMemory = (UtlRBTreeNode_t<DecalMaterialSortData_t,int> *)_g_pMemAlloc->Alloc_2(
                                                                                   this: _g_pMemAlloc,
                                                                                   a2: 448);
      v5->m_Root = -1;
      v5->m_NumElements = 0;
      v5->m_FirstFree = -1;
      v5->m_LastAlloc.index = -1;
      v5->m_pElements = v5->m_Elements.m_pMemory;
    }
    else
    {
      v5 = nullptr;
    }
    this->m_pTrees[j] = v5;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10102C90
// Name: R_AddDecalToSurface
// Source: json
//------------------------------------------------------------------------------
void __usercall R_AddDecalToSurface(decal_t *pdecal@<ecx>, decalinfo_t *decalinfo@<eax>, msurface2_t *surfID)
{
  int decals; // eax
  decal_t *v6; // eax
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_aApplySurfs; // esi
  int m_Size; // edi
  S3RGBA *m_pMemory; // ecx
  int v11; // eax
  S3RGBA *v12; // eax

  pdecal->pnext = nullptr;
  decals = surfID->decals;
  if ( (_WORD)decals == 0xFFFF || (v6 = s_aDecalPool.m_Memory.m_pMemory[decals]) == nullptr )
  {
    surfID->decals = pdecal->m_iDecalPool;
  }
  else
  {
    for ( ; v6->pnext != nullptr; v6 = v6->pnext )
      ;
    v6->pnext = pdecal;
  }
  pdecal->surfID = surfID;
  pdecal->flSize = decalinfo->m_Size;
  pdecal->lightmapOffset = ComputeDecalLightmapOffset((int)surfID);
  if ( (surfID->flags & 0x800) != 0 )
    pdecal->m_DispDecal = ((int (__stdcall *)(_DWORD, _DWORD))surfID->pDispInfo->NotifyAddDecal)(
                            a1: pdecal,
                            a2: decalinfo->m_Size);
  m_nAllocationCount = decalinfo->m_aApplySurfs.m_Memory.m_nAllocationCount;
  p_m_aApplySurfs = (CUtlMemory<S3RGBA,int> *)&decalinfo->m_aApplySurfs;
  m_Size = decalinfo->m_aApplySurfs.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow(this: p_m_aApplySurfs, num: m_Size - m_nAllocationCount + 1);
  ++p_m_aApplySurfs[1].m_pMemory;
  m_pMemory = p_m_aApplySurfs->m_pMemory;
  v11 = (int)p_m_aApplySurfs[1].m_pMemory - m_Size - 1;
  p_m_aApplySurfs[1].m_nAllocationCount = (int)p_m_aApplySurfs->m_pMemory;
  if ( v11 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v11);
  v12 = &p_m_aApplySurfs->m_pMemory[m_Size];
  if ( v12 != nullptr )
    *v12 = (S3RGBA)surfID;
}

//------------------------------------------------------------------------------
// Address: 0x10102D60
// Name: void DrawDecalsOnSingleSurface(class IMatRenderContext __near *,struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawDecalsOnSingleSurface(IMatRenderContext *pRenderContext, msurface2_t *surfID)
{
  ICallQueue *v2; // eax

  if ( r_queued_decals.m_pParent != nullptr
    && r_queued_decals.m_pParent->m_Value.m_nValue != 0
    && (v2 = pRenderContext->GetCallQueue(this: pRenderContext)) != nullptr )
  {
    ICallQueue::QueueCall<void,msurface2_t *,Vector,msurface2_t *,Vector>(
      this: v2,
      pfnProxied: DrawDecalsOnSingleSurface_QueueHelper,
      arg1: &surfID,
      arg2: &modelorg);
  }
  else
  {
    DrawDecalsOnSingleSurface_NonQueued(pRenderContext, surfID, vModelOrg: &modelorg);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10102DC0
// Name: void R_DrawDecalsAll(class IMatRenderContext __near *,int,int,class Vector const __near &,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DrawDecalsAll(
        IMatRenderContext *pRenderContext,
        int iGroup,
        int iTreeType,
        const Vector *vModelOrg,
        int nCheckCount,
        float flFade)
{
  int (__thiscall *GetMaxVerticesToRender)(IMatRenderContext *, IMaterial *); // edx
  float z; // xmm0_4
  int v8; // edi
  int v9; // ebx
  int m_nValue; // eax
  CClientState *BaseLocalClient; // eax
  int v12; // ecx
  int v13; // eax
  DecalSortTrees_t *v14; // eax
  int v15; // edx
  int v16; // ecx
  DecalMaterialBucket_t *v17; // eax
  int m_iHead; // esi
  int v19; // ecx
  __int64 v20; // rax
  char v21; // di
  int v22; // esi
  float v23; // xmm0_4
  CClientState *v24; // eax
  msurface2_t *v25; // ecx
  float v26; // xmm0_4
  int v27; // eax
  int v28; // ebx
  int v29; // eax
  IMesh *v30; // eax
  int m_Size; // edi
  int v32; // eax
  int v33; // eax
  bool v34; // zf
  DecalBatchList_t *v35; // edi
  decal_t *v36; // eax
  unsigned __int8 v37; // dl
  unsigned __int8 v38; // bl
  int v39; // ecx
  float v40; // xmm1_4
  float v41; // xmm0_4
  float v42; // xmm1_4
  CDecalVert *v43; // eax
  int v44; // ecx
  int v45; // edi
  int v46; // esi
  float *m_pCurrPosition; // edx
  float *p_y; // eax
  float *v49; // edx
  int v50; // xmm0_4
  float *v51; // edx
  int v52; // xmm0_4
  int v53; // edx
  int v54; // ebx
  int v55; // edi
  int v56; // esi
  int v57; // edi
  int m_nVertexCount; // eax
  int v59; // eax
  DecalMeshList_t meshList; // [esp+0h] [ebp-AC0h] BYREF
  decalcontext_t context; // [esp+80Ch] [ebp-2B4h] BYREF
  Vector tVect; // [esp+848h] [ebp-278h] BYREF
  CMeshBuilder meshBuilder; // [esp+854h] [ebp-26Ch] BYREF
  unsigned __int64 vertexFormat; // [esp+A3Ch] [ebp-84h]
  BOOL bNegate; // [esp+A44h] [ebp-7Ch]
  DecalSortTrees_t *sortTree; // [esp+A48h] [ebp-78h]
  int nBucketCount; // [esp+A4Ch] [ebp-74h]
  int iElement; // [esp+A50h] [ebp-70h]
  unsigned __int8 color[4]; // [esp+A54h] [ebp-6Ch]
  Vector vecTangentS; // [esp+A58h] [ebp-68h] BYREF
  Vector vecTangentT; // [esp+A64h] [ebp-5Ch] BYREF
  decal_t *pDecalHead; // [esp+A70h] [ebp-50h]
  int v73; // [esp+A74h] [ebp-4Ch]
  float localClientTime; // [esp+A78h] [ebp-48h]
  msurface2_t *lastSurf; // [esp+A7Ch] [ebp-44h]
  int nSortTreeCount; // [esp+A80h] [ebp-40h]
  float flOffset; // [esp+A84h] [ebp-3Ch]
  int v78; // [esp+A88h] [ebp-38h]
  int iSortTree; // [esp+A8Ch] [ebp-34h]
  int iBucket; // [esp+A90h] [ebp-30h]
  Vector vecNormal; // [esp+A94h] [ebp-2Ch] BYREF
  int nDecalSortMaxIndices; // [esp+AA0h] [ebp-20h]
  int nDecalSortMaxVerts; // [esp+AA4h] [ebp-1Ch]
  int nCount; // [esp+AA8h] [ebp-18h]
  CDecalVert *pVerts; // [esp+AACh] [ebp-14h]
  int nVertCount; // [esp+AB0h] [ebp-10h]
  DecalBatchList_t *pBatch; // [esp+AB4h] [ebp-Ch]
  int nIndexCount; // [esp+AB8h] [ebp-8h]
  bool bBatchInit; // [esp+ABDh] [ebp-3h]
  bool bWireframe; // [esp+ABEh] [ebp-2h]
  bool bMeshInit; // [esp+ABFh] [ebp-1h]

  nSortTreeCount = g_aDecalSortTrees.m_Size;
  if ( g_aDecalSortTrees.m_Size == 0 )
    return;
  meshList.m_aBatches.m_Size = 0;
  meshList.m_aBatches.m_pElements = (DecalBatchList_t *)&meshList.m_aBatches;
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  GetMaxVerticesToRender = pRenderContext->GetMaxVerticesToRender;
  context.vModelOrg.x = vModelOrg->x;
  context.vModelOrg.y = vModelOrg->y;
  z = vModelOrg->z;
  lastSurf = nullptr;
  context.pSurf = nullptr;
  nVertCount = 0;
  nIndexCount = 0;
  v8 = 5 * g_nMaxDecals;
  context.vModelOrg.z = z;
  v9 = 15 * g_nMaxDecals;
  context.pRenderContext = pRenderContext;
  vecNormal.x = 0.0;
  vecNormal.y = 0.0;
  vecNormal.z = 1.0;
  vecTangentS.x = 1.0;
  vecTangentS.y = 0.0;
  vecTangentS.z = 0.0;
  vecTangentT.x = 0.0;
  vecTangentT.y = 1.0;
  vecTangentT.z = 0.0;
  nDecalSortMaxVerts = 5 * g_nMaxDecals;
  nDecalSortMaxIndices = 15 * g_nMaxDecals;
  if ( v8 >= GetMaxVerticesToRender(this: pRenderContext, a2: g_materialDecalWireframe) / 4 )
    nDecalSortMaxVerts = pRenderContext->GetMaxVerticesToRender(this: pRenderContext, a2: g_materialDecalWireframe) / 4;
  if ( v9 >= pRenderContext->GetMaxIndicesToRender(this: pRenderContext) )
    nDecalSortMaxIndices = pRenderContext->GetMaxIndicesToRender(this: pRenderContext);
  bWireframe = (sv_cheats.m_pParent != nullptr && sv_cheats.m_pParent->m_Value.m_nValue != 0 || Cmd_IsRptActive())
            && (mat_wireframe.m_pParent == nullptr
              ? (m_nValue = 0)
              : (m_nValue = mat_wireframe.m_pParent->m_Value.m_nValue),
                m_nValue != 0)
            || r_drawdecals.m_pParent != nullptr && r_drawdecals.m_pParent->m_Value.m_nValue == 2;
  BaseLocalClient = GetBaseLocalClient();
  localClientTime = CClientState::GetTime(this: BaseLocalClient);
  iSortTree = 0;
  if ( nSortTreeCount <= 0 )
    goto LABEL_106;
  v12 = 20 * (iGroup + iTreeType + 2 * iGroup);
  v13 = 0;
  v73 = v12;
  v78 = 0;
LABEL_20:
  v14 = (DecalSortTrees_t *)((char *)g_aDecalSortTrees.m_Memory.m_pMemory + v13);
  bMeshInit = true;
  v15 = *(int *)((char *)&v14->m_aDecalSortBuckets[0][0].m_Size + v12);
  v16 = 0;
  sortTree = v14;
  nBucketCount = v15;
  iBucket = 0;
  if ( v15 <= 0 )
    goto LABEL_105;
  while ( 1 )
  {
    v17 = &(*(DecalMaterialBucket_t **)((char *)&v14->m_aDecalSortBuckets[0][0].m_Memory.m_pMemory + v73))[v16];
    if ( v17->m_nCheckCount == nCheckCount )
    {
      m_iHead = v17->m_iHead;
      if ( v17->m_iHead != 0 && (*(_DWORD *)(m_iHead + 4) != m_iHead || *(_DWORD *)(m_iHead + 8) == m_iHead) )
      {
        v19 = *(_DWORD *)(*(_DWORD *)m_iHead + 12);
        pDecalHead = *(decal_t **)m_iHead;
        if ( v19 != 0 )
        {
          v20 = ((__int64 (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v19 + 80))(a1: v19);
          v21 = v20;
          LODWORD(vertexFormat) = v20 & 0xFFFFFBFF;
          if ( (HIDWORD(v20) | v20 & 0xFFFFFBFF) != 0 )
            break;
        }
      }
    }
LABEL_93:
    v16 = iBucket + 1;
    iBucket = v16;
    if ( v16 >= nBucketCount )
    {
      if ( !bMeshInit )
      {
        if ( meshBuilder.m_bGenerateIndices )
        {
          switch ( meshBuilder.m_Type )
          {
            case MATERIAL_LINE_STRIP:
              m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
              break;
            case MATERIAL_LINE_LOOP:
              m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
              break;
            case MATERIAL_POLYGON:
              m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
              break;
            case MATERIAL_QUADS:
              m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
              break;
            case MATERIAL_INSTANCED_QUADS:
              m_nVertexCount = 0;
              break;
            default:
              m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
              break;
          }
          CIndexBuilder::GenerateIndices(
            this: &meshBuilder.m_IndexBuilder,
            primitiveType: meshBuilder.m_Type,
            nIndexCount: m_nVertexCount);
        }
        meshBuilder.m_pMesh->UnlockMesh(
          this: meshBuilder.m_pMesh,
          a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
          a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
          a4: &meshBuilder);
        meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
        meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
        meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
        meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
        meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
        meshBuilder.m_pMesh = nullptr;
        R_DrawDecalMeshList(a1: v9, a2: 0, &meshList);
      }
LABEL_105:
      v13 = v78 + 312;
      ++iSortTree;
      v78 += 312;
      if ( iSortTree >= nSortTreeCount )
      {
LABEL_106:
        if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
          && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
        {
          meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
        }
        if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
          && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
        {
          meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
        }
        return;
      }
      v12 = v73;
      goto LABEL_20;
    }
    v14 = sortTree;
  }
  pBatch = nullptr;
  bBatchInit = true;
  v9 = m_iHead;
  while ( 1 )
  {
    v22 = *(_DWORD *)v9;
    v9 = *(_DWORD *)(v9 + 8);
    iElement = v9;
    if ( v22 != 0 )
      break;
LABEL_90:
    if ( v9 == 0 )
    {
      if ( pBatch != nullptr )
        pBatch->m_nIndexCount = nIndexCount - pBatch->m_iStartIndex;
      goto LABEL_93;
    }
  }
  if ( (*(_WORD *)(v22 + 84) & 0x100) != 0 && (*(_WORD *)(v22 + 84) & 0x4000) == 0 )
  {
    v23 = *(float *)(v22 + 60);
    *(_WORD *)(v22 + 84) |= 0x4000u;
    if ( v23 > 0.0 )
    {
      v24 = GetBaseLocalClient();
      if ( CClientState::GetTime(this: v24) >= *(float *)(v22 + 64) + *(float *)(v22 + 60) )
      {
        if ( *(_DWORD *)(v22 + 4) == 0 )
        {
          *(_DWORD *)(v22 + 4) = s_pDecalDestroyList;
          s_pDecalDestroyList = (decal_t *)v22;
        }
        goto LABEL_90;
      }
    }
  }
  v25 = *(msurface2_t **)(v22 + 8);
  flOffset = 0.0;
  if ( v25 != lastSurf )
  {
    v26 = *(float *)(v22 + 16);
    lastSurf = v25;
    flOffset = v26;
    if ( (v21 & 0x32) != 0 )
    {
      vecNormal = v25->plane->normal;
      if ( (v21 & 0x30) != 0 )
      {
        LOBYTE(bNegate) = TangentSpaceSurfaceSetup(surfID: *(msurface2_t **)(v22 + 8), &tVect);
        TangentSpaceComputeBasis(
          tangentS: &vecTangentS,
          tangentT: &vecTangentT,
          normal: &vecNormal,
          &tVect,
          negateTangent: bNegate);
      }
    }
  }
  pVerts = (CDecalVert *)R_DecalSetupVerts(
                           &context,
                           pDecal: (decal_t *)v22,
                           surfID: *(msurface2_t **)(v22 + 8),
                           pMaterial: *(IMaterial **)(v22 + 12));
  if ( pVerts == nullptr )
    goto LABEL_90;
  v27 = *(unsigned __int16 *)(v22 + 78);
  v28 = nIndexCount;
  nCount = v27;
  if ( v27 + nVertCount <= nDecalSortMaxVerts && v27 + nIndexCount - 2 <= nDecalSortMaxIndices )
  {
    if ( bMeshInit )
      goto LABEL_57;
  }
  else
  {
    if ( pBatch != nullptr )
    {
      LOWORD(v28) = nIndexCount - pBatch->m_iStartIndex;
      pBatch->m_nIndexCount = v28;
    }
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          v29 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          v29 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          v29 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          v29 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          v29 = 0;
          break;
        default:
          v29 = meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: v29);
    }
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    R_DrawDecalMeshList(a1: v28, a2: v22, &meshList);
    pBatch = nullptr;
    bBatchInit = true;
LABEL_57:
    v28 = 0;
    meshList.m_pMesh = nullptr;
    meshList.m_aBatches.m_Size = 0;
    if ( bWireframe )
      v30 = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 0, a3: 0, a4: 0, a5: g_materialDecalWireframe);
    else
      v30 = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 0, a3: 0, a4: 0, a5: pDecalHead->material);
    meshList.m_pMesh = v30;
    CMeshBuilder::Begin(
      this: &meshBuilder,
      pMesh: v30,
      type: MATERIAL_TRIANGLES,
      nVertexCount: nDecalSortMaxVerts,
      nIndexCount: nDecalSortMaxIndices,
      pMeshSettings: nullptr);
    nVertCount = 0;
    nIndexCount = 0;
    bMeshInit = false;
  }
  if ( !bBatchInit )
  {
LABEL_69:
    v37 = *(_BYTE *)(v22 + 68);
    v38 = *(_BYTE *)(v22 + 69);
    LOBYTE(v39) = *(_BYTE *)(v22 + 71);
    color[2] = *(_BYTE *)(v22 + 70);
    if ( flFade != 1.0 )
      v39 = (int)(float)((float)(unsigned __int8)v39 * flFade);
    if ( (*(_WORD *)(v22 + 84) & 0x100) != 0 )
    {
      v40 = *(float *)(v22 + 60);
      if ( v40 >= 0.0 )
        v41 = 1.0 - (float)((float)(localClientTime - *(float *)(v22 + 64)) / v40);
      else
        LODWORD(v41) = COERCE_UNSIGNED_INT((float)(localClientTime - *(float *)(v22 + 64)) / v40) ^ _mask__NegFloat_;
      if ( v41 >= 0.0 )
      {
        if ( v41 > 1.0 )
          v41 = 1.0;
      }
      else
      {
        v41 = 0.0;
      }
      v39 = (int)(float)((float)(unsigned __int8)v39 * v41);
    }
    if ( nCount > 0 )
    {
      v42 = flOffset;
      v43 = pVerts;
      v44 = color[2] | ((v38 | ((v37 | ((unsigned __int8)v39 << 8)) << 8)) << 8);
      v45 = vertexFormat & 2;
      v46 = vertexFormat & 0x30;
      pVerts = (CDecalVert *)nCount;
      m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      p_y = &v43->m_vPos.y;
      do
      {
        *m_pCurrPosition = *(p_y - 1);
        m_pCurrPosition[1] = *p_y;
        m_pCurrPosition[2] = p_y[1];
        if ( v45 != 0 )
          *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = vecNormal;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v44;
        v49 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        v50 = *((_DWORD *)p_y + 4);
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = p_y[3];
        *((_DWORD *)v49 + 1) = v50;
        v51 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
        v52 = *((_DWORD *)p_y + 6);
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = p_y[5];
        *((_DWORD *)v51 + 1) = v52;
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = v42;
        if ( v46 != 0 )
        {
          *(Vector *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                    + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS) = vecTangentS;
          *(Vector *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                    + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT) = vecTangentT;
        }
        v53 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
        meshBuilder.m_VertexBuilder.m_nCurrentVertex = v53;
        if ( v53 > meshBuilder.m_VertexBuilder.m_nVertexCount )
          meshBuilder.m_VertexBuilder.m_nVertexCount = v53;
        meshBuilder.m_VertexBuilder.m_pCurrNormal = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrNormal
                                                            + meshBuilder.m_VertexBuilder.m_VertexSize_Normal);
        meshBuilder.m_VertexBuilder.m_pCurrColor += meshBuilder.m_VertexBuilder.m_VertexSize_Color;
        meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                                 + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
        meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1]
                                                                 + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[1]);
        m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                  + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
        meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2]
                                                                 + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[2]);
        p_y += 8;
        v34 = pVerts == (CDecalVert *)1;
        pVerts = (CDecalVert *)((char *)pVerts - 1);
        meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                              + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
      }
      while ( !v34 );
    }
    v54 = nCount;
    v55 = nVertCount;
    v56 = nCount - 2;
    CIndexBuilder::FastPolygon(this: &meshBuilder.m_IndexBuilder, startVert: nVertCount, triangleCount: nCount - 2);
    v57 = v54 + v55;
    v9 = iElement;
    nVertCount = v57;
    v21 = vertexFormat;
    nIndexCount += v56 + 2 * v56;
    goto LABEL_90;
  }
  m_Size = meshList.m_aBatches.m_Size;
  v32 = meshList.m_aBatches.m_Size + 1;
  if ( meshList.m_aBatches.m_Size + 1 <= 128 )
  {
    ++meshList.m_aBatches.m_Size;
    v33 = v32 - m_Size - 1;
    meshList.m_aBatches.m_pElements = (DecalBatchList_t *)&meshList.m_aBatches;
    if ( v33 > 0 )
      _V_memmove(
        dest: &meshList.m_aBatches.m_Memory.m_Memory[16 * m_Size + 16],
        src: (char *)&meshList.m_aBatches + 16 * m_Size,
        count: 16 * v33);
    v34 = !bWireframe;
    v35 = (DecalBatchList_t *)((char *)&meshList.m_aBatches + 16 * m_Size);
    pBatch = v35;
    v35->m_iStartIndex = v28;
    if ( v34 )
    {
      v36 = pDecalHead;
      v35->m_pMaterial = pDecalHead->material;
      v35->m_pProxy = v36->userdata;
      v35->m_iLightmapPage = materialSortInfoArray[v36->surfID->materialSortID].lightmapPageID;
    }
    else
    {
      v35->m_pMaterial = g_materialDecalWireframe;
    }
    bBatchInit = false;
    goto LABEL_69;
  }
  _Warning(a1: "R_DrawDecalsAll: overflowing m_aBatches. Reduce # of decals in the scene.\n");
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        v59 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        v59 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        v59 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        v59 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        v59 = 0;
        break;
      default:
        v59 = meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: v59);
  }
  meshBuilder.m_pMesh->UnlockMesh(
    this: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_pMesh = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  R_DrawDecalMeshList(a1: v28, a2: v22, &meshList);
  CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
}

//------------------------------------------------------------------------------
// Address: 0x10103840
// Name: void DecalSurfaceDraw_NonQueued(class IMatRenderContext __near *,int,class Vector const __near &,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DecalSurfaceDraw_NonQueued(
        IMatRenderContext *pRenderContext,
        int renderGroup,
        const Vector *vModelOrg,
        CMeshBuilder *nCheckCount,
        float flFade)
{
  if ( r_drawbatchdecals.m_pParent != nullptr && r_drawbatchdecals.m_pParent->m_Value.m_nValue != 0 )
  {
    R_DrawDecalsAll(pRenderContext, iGroup: renderGroup, iTreeType: 0, vModelOrg, (int)nCheckCount, flFade);
    R_DrawDecalsAll(pRenderContext, iGroup: renderGroup, iTreeType: 1, vModelOrg, (int)nCheckCount, flFade);
    R_DrawDecalsAll(pRenderContext, iGroup: renderGroup, iTreeType: 2, vModelOrg, (int)nCheckCount, flFade);
  }
  else
  {
    R_DrawDecalsAllImmediate(
      a1: renderGroup,
      m_nIndexCount: (int)vModelOrg,
      p_meshBuilder: nCheckCount,
      pRenderContext,
      iGroup: renderGroup,
      iTreeType: 0,
      vModelOrg,
      (int)nCheckCount,
      flFade);
    R_DrawDecalsAllImmediate(
      a1: renderGroup,
      m_nIndexCount: (int)vModelOrg,
      p_meshBuilder: nCheckCount,
      pRenderContext,
      iGroup: renderGroup,
      iTreeType: 1,
      vModelOrg,
      (int)nCheckCount,
      flFade);
    R_DrawDecalsAllImmediate(
      a1: renderGroup,
      m_nIndexCount: (int)vModelOrg,
      p_meshBuilder: nCheckCount,
      pRenderContext,
      iGroup: renderGroup,
      iTreeType: 2,
      vModelOrg,
      (int)nCheckCount,
      flFade);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10103910
// Name: public: DecalSortTrees_t::~DecalSortTrees_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall DecalSortTrees_t::~DecalSortTrees_t(DecalSortTrees_t *this)
{
  int i; // esi
  CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl*)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int> > *v3; // ecx
  CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl*)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int> > *v4; // edi
  CUtlVector<DecalMaterialBucket_t,CUtlMemory<DecalMaterialBucket_t,int> > *v5; // esi
  int k; // edi
  DecalSortTrees_t *v7; // esi
  int m; // edi
  CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl*)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int> > *v9; // eax
  int j; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < 3; ++i )
  {
    v3 = this->m_pTrees[i];
    if ( v3 != nullptr )
    {
      CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl *)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int>>::RemoveAll(this: v3);
      v4 = this->m_pTrees[i];
      if ( v4 != nullptr )
      {
        CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl *)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int>>::~CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl *)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int>>(this: this->m_pTrees[i]);
        free(pMem: v4);
      }
      this->m_pTrees[i] = nullptr;
    }
  }
  v5 = this->m_aDecalSortBuckets[0];
  for ( j = 5; j != 0; --j )
  {
    for ( k = 3; k != 0; --k )
    {
      v5->m_Size = 0;
      if ( v5->m_Memory.m_nGrowSize >= 0 )
      {
        if ( v5->m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_Memory.m_pMemory);
          v5->m_Memory.m_pMemory = nullptr;
        }
        v5->m_Memory.m_nAllocationCount = 0;
      }
      v5->m_pElements = v5->m_Memory.m_pMemory;
      ++v5;
    }
  }
  v7 = this + 1;
  for ( m = 14; m >= 0; --m )
  {
    v7 = (DecalSortTrees_t *)((char *)v7 - 20);
    v7->m_aDecalSortBuckets[0][0].m_Memory.m_pMemory = nullptr;
    if ( (int)v7->m_pTrees[2] >= 0 )
    {
      if ( v7->m_pTrees[0] != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7->m_pTrees[0]);
        v7->m_pTrees[0] = nullptr;
      }
      v7->m_pTrees[1] = nullptr;
    }
    v9 = v7->m_pTrees[0];
    v7->m_aDecalSortBuckets[0][0].m_Memory.m_nAllocationCount = (int)v7->m_pTrees[0];
    if ( (int)v7->m_pTrees[2] >= 0 )
    {
      if ( v9 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
        v7->m_pTrees[0] = nullptr;
      }
      v7->m_pTrees[1] = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10103A10
// Name: R_DecalFindOverlappingDecals
// Source: json
//------------------------------------------------------------------------------
decal_t *__usercall R_DecalFindOverlappingDecals@<eax>(decalinfo_t *decalinfo@<eax>, msurface2_t *surfID)
{
  IMaterial *m_pMaterial; // edi
  int v4; // ebx
  int v5; // eax
  float v6; // xmm1_4
  float z; // xmm3_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  float x; // xmm1_4
  float v12; // xmm2_4
  int decals; // eax
  bool v14; // bl
  decal_t *v15; // edi
  decal_t **m_pFixedMemory; // eax
  IMaterial *material; // ecx
  float y; // xmm1_4
  float v19; // xmm3_4
  float v20; // xmm2_4
  float dy; // xmm0_4
  double v22; // st7
  double v23; // st6
  double v24; // st7
  double v25; // st6
  IMaterial *v26; // ecx
  IMaterial_vtbl *v27; // edx
  int (__thiscall *GetMappingWidth)(IMaterial *); // eax
  int v29; // eax
  float v30; // xmm2_4
  float v31; // xmm0_4
  int v32; // eax
  int m_nValue; // ecx
  int v34; // ecx
  int v35; // edi
  int i; // esi
  float testWorldScale[2]; // [esp+Ch] [ebp-144h] BYREF
  CUtlVectorFixedGrowable<decal_t *,32> coveredList; // [esp+14h] [ebp-13Ch] BYREF
  float v40; // [esp+B4h] [ebp-9Ch]
  float v41; // [esp+BCh] [ebp-94h]
  Vector testBasis[3]; // [esp+C4h] [ebp-8Ch] BYREF
  float v43; // [esp+ECh] [ebp-64h]
  float v44; // [esp+F0h] [ebp-60h]
  Vector2D vUnionMax; // [esp+F4h] [ebp-5Ch]
  Vector2D vUnionMin; // [esp+FCh] [ebp-54h]
  Vector2D vDecalMin; // [esp+104h] [ebp-4Ch]
  float sizey; // [esp+10Ch] [ebp-44h]
  float areaThreshold; // [esp+110h] [ebp-40h]
  float minProjectedWidth; // [esp+114h] [ebp-3Ch]
  Vector2D vDecalMax; // [esp+118h] [ebp-38h]
  float v52; // [esp+120h] [ebp-30h]
  float v53; // [esp+124h] [ebp-2Ch]
  float v54; // [esp+128h] [ebp-28h]
  float lastArea; // [esp+12Ch] [ebp-24h]
  float dx; // [esp+130h] [ebp-20h]
  float v57; // [esp+134h] [ebp-1Ch]
  float v58; // [esp+138h] [ebp-18h]
  float v59; // [esp+13Ch] [ebp-14h]
  decal_t *pDecal; // [esp+140h] [ebp-10h] BYREF
  float v61; // [esp+144h] [ebp-Ch]
  int count; // [esp+148h] [ebp-8h]
  decal_t *plast; // [esp+14Ch] [ebp-4h]

  m_pMaterial = decalinfo->m_pMaterial;
  plast = nullptr;
  count = 0;
  v4 = m_pMaterial->GetMappingWidth(this: m_pMaterial);
  v5 = m_pMaterial->GetMappingHeight(this: m_pMaterial);
  v6 = 1.0 / decalinfo->m_scale;
  z = decalinfo->m_Basis[1].z;
  v8 = (float)((float)v4 * v6) * 0.5;
  v57 = decalinfo->m_Basis[0].x * v8;
  v58 = decalinfo->m_Basis[0].y * v8;
  v9 = decalinfo->m_Basis[0].z * v8;
  minProjectedWidth = v8;
  v10 = (float)v5 * v6;
  x = decalinfo->m_Basis[1].x;
  v59 = v9;
  v12 = decalinfo->m_Basis[1].y * v10;
  decals = surfID->decals;
  areaThreshold = r_decal_overlap_area.m_pParent->m_Value.m_fValue;
  v14 = false;
  v52 = (float)(x * v10) * 0.5;
  v53 = v12 * 0.5;
  v54 = (float)(z * v10) * 0.5;
  lastArea = 0.0;
  if ( (_WORD)decals == 0xFFFF )
    v15 = nullptr;
  else
    v15 = s_aDecalPool.m_Memory.m_pMemory[decals];
  m_pFixedMemory = coveredList.m_Memory.m_pFixedMemory;
  pDecal = v15;
  coveredList.m_Memory.m_pMemory = coveredList.m_Memory.m_pFixedMemory;
  coveredList.m_Memory.m_nAllocationCount = 32;
  coveredList.m_Memory.m_nGrowSize = -1;
  coveredList.m_Memory.m_nMallocGrowSize = 0;
  coveredList.m_Size = 0;
  coveredList.m_pElements = coveredList.m_Memory.m_pFixedMemory;
  if ( v15 != nullptr )
  {
    do
    {
      material = v15->material;
      if ( (v15->flags & 1) == 0 && (v15->flags & 0x1000) == 0 && material != nullptr )
      {
        R_SetupDecalTextureSpaceBasis(
          pDecal: v15,
          vSurfNormal: &surfID->plane->normal,
          pMaterial: material,
          textureSpaceBasis: testBasis,
          decalWorldScale: testWorldScale);
        y = decalinfo->m_Position.y;
        v19 = decalinfo->m_Position.z;
        v20 = decalinfo->m_Position.x;
        v43 = y - v58;
        v44 = v19 - v59;
        dx = v15->dx;
        v40 = v19 - v54;
        dy = v15->dy;
        vDecalMin.x = (float)((float)((float)((float)(testBasis[0].y * (float)(y - v58))
                                            + (float)((float)(v20 - v57) * testBasis[0].x))
                                    + (float)(testBasis[0].z * (float)(v19 - v59)))
                            - dx)
                    + 0.5;
        v61 = dy;
        vDecalMin.y = (float)((float)((float)((float)(testBasis[1].x * (float)(v20 - v52))
                                            + (float)(testBasis[1].y * (float)(y - v53)))
                                    + (float)(testBasis[1].z * (float)(v19 - v54)))
                            - dy)
                    + 0.5;
        v41 = y + v53;
        vDecalMax.x = (float)((float)((float)((float)((float)(y + v58) * testBasis[0].y)
                                            + (float)((float)(v20 + v57) * testBasis[0].x))
                                    + (float)((float)(v19 + v59) * testBasis[0].z))
                            - dx)
                    + 0.5;
        v22 = 0.0;
        v23 = vDecalMin.y;
        vDecalMax.y = (float)((float)((float)((float)(testBasis[1].x * (float)(v20 + v52))
                                            + (float)(testBasis[1].y * (float)(y + v53)))
                                    + (float)(testBasis[1].z * (float)(v19 + v54)))
                            - dy)
                    + 0.5;
        if ( vDecalMin.y < 0.0 )
          v23 = 0.0;
        if ( vDecalMin.x >= 0.0 )
          v22 = vDecalMin.x;
        vUnionMin.x = v22;
        vUnionMin.y = v23;
        v24 = 1.0;
        v25 = vDecalMax.y;
        if ( vDecalMax.y > 1.0 )
          v25 = 1.0;
        if ( vDecalMax.x <= 1.0 )
          v24 = vDecalMax.x;
        v26 = v15->material;
        v27 = v26->__vftable;
        vUnionMax.x = v24;
        GetMappingWidth = v27->GetMappingWidth;
        vUnionMax.y = v25;
        v29 = GetMappingWidth(this: v26);
        sizey = vUnionMax.y - vUnionMin.y;
        v30 = (float)v29 / v15->scale;
        if ( (float)(vUnionMax.x - vUnionMin.x) >= 0.0 && sizey >= 0.0 )
        {
          v31 = sizey * (float)(vUnionMax.x - vUnionMin.x);
          if ( minProjectedWidth <= v30 )
          {
            if ( v31 > areaThreshold )
            {
              ++count;
              if ( plast == nullptr || (float)(v31 * v30) > lastArea )
              {
                plast = v15;
                lastArea = v31 * v30;
                v14 = v31 >= 0.89999998;
              }
            }
          }
          else if ( v31 > 0.99900001 )
          {
            CUtlVector<decal_t *,CUtlMemoryFixedGrowable<decal_t *,32,int>>::InsertBefore(
              this: &coveredList,
              elem: coveredList.m_Size,
              src: &pDecal);
          }
        }
      }
      v15 = v15->pnext;
      pDecal = v15;
    }
    while ( v15 != nullptr );
    if ( plast != nullptr )
    {
      v32 = r_decal_overlap_count.m_pParent != nullptr ? r_decal_overlap_count.m_pParent->m_Value.m_nValue : 0;
      if ( count < v32 && !v14 )
        plast = nullptr;
    }
    m_pFixedMemory = coveredList.m_Memory.m_pMemory;
  }
  if ( r_decal_cover_count.m_pParent != nullptr )
    m_nValue = r_decal_cover_count.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( coveredList.m_Size > m_nValue )
  {
    v34 = r_decal_cover_count.m_pParent != nullptr ? r_decal_cover_count.m_pParent->m_Value.m_nValue : 0;
    v35 = coveredList.m_Size - v34;
    for ( i = 0; i < v35; ++i )
    {
      R_DecalUnlink(pdecal: m_pFixedMemory[i]);
      m_pFixedMemory = coveredList.m_Memory.m_pMemory;
    }
  }
  coveredList.m_Size = 0;
  if ( coveredList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pFixedMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pFixedMemory);
      m_pFixedMemory = nullptr;
      coveredList.m_Memory.m_pMemory = nullptr;
    }
    coveredList.m_Memory.m_nAllocationCount = 0;
  }
  coveredList.m_pElements = m_pFixedMemory;
  if ( coveredList.m_Memory.m_nGrowSize >= 0 && m_pFixedMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pFixedMemory);
  return plast;
}

//------------------------------------------------------------------------------
// Address: 0x10103ED0
// Name: void R_DrawDecalsAll_Gathered(class IMatRenderContext __near *,struct decal_t __near * __near *,int,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DrawDecalsAll_Gathered(
        IMatRenderContext *pRenderContext,
        decal_t **ppDecals,
        int iDecalCount,
        const Vector *vModelOrg,
        float flFade)
{
  int v5; // ebx
  int (__thiscall *GetMaxVerticesToRender)(IMatRenderContext *, IMaterial *); // edx
  int v7; // edi
  decal_t *v8; // edi
  float z; // xmm0_4
  DecalBatchList_t *v10; // ebx
  int m_nValue; // eax
  decal_t *v12; // esi
  float fadeDuration; // xmm0_4
  CClientState *BaseLocalClient; // eax
  msurface2_t *surfID; // eax
  int clippedVertCount; // edi
  int v17; // eax
  IMesh *v18; // eax
  DecalBatchList_t *v19; // eax
  decal_t *v20; // ecx
  unsigned __int8 g; // cl
  unsigned __int8 b; // dl
  int v23; // ebx
  CClientState *v24; // eax
  double v25; // st7
  CClientState *v26; // eax
  float v27; // xmm2_4
  int v28; // esi
  int v29; // ebx
  float *p_y; // edi
  float *m_pCurrPosition; // eax
  int v32; // ecx
  float *v33; // eax
  int v34; // xmm0_4
  float *v35; // eax
  int v36; // xmm0_4
  int v37; // edi
  int v38; // esi
  int v39; // ebx
  int v40; // ecx
  int m_nVertexCount; // eax
  int i; // eax
  unsigned __int64 v43; // rax
  int v44; // eax
  int v45; // eax
  DecalMeshList_t meshList; // [esp+Ch] [ebp-AB0h] BYREF
  decalcontext_t context; // [esp+818h] [ebp-2A4h] BYREF
  Vector tVect; // [esp+854h] [ebp-268h] BYREF
  CMeshBuilder meshBuilder; // [esp+860h] [ebp-25Ch] BYREF
  int v50; // [esp+A48h] [ebp-74h]
  float flOffset; // [esp+A50h] [ebp-6Ch]
  CDecalVert *pVerts; // [esp+A54h] [ebp-68h]
  BOOL bNegate; // [esp+A58h] [ebp-64h]
  Vector vecTangentS; // [esp+A5Ch] [ebp-60h] BYREF
  Vector vecTangentT; // [esp+A68h] [ebp-54h] BYREF
  msurface2_t *lastSurf; // [esp+A74h] [ebp-48h]
  unsigned __int64 vertexFormat; // [esp+A78h] [ebp-44h]
  int nCount; // [esp+A80h] [ebp-3Ch]
  Vector vecNormal; // [esp+A84h] [ebp-38h] BYREF
  int nDecalSortMaxVerts; // [esp+A90h] [ebp-2Ch]
  decal_t **v61; // [esp+A94h] [ebp-28h]
  int nDecalSortMaxIndices; // [esp+A98h] [ebp-24h]
  int v63; // [esp+A9Ch] [ebp-20h]
  int nVertCount; // [esp+AA0h] [ebp-1Ch]
  decal_t *pDecalHead; // [esp+AA4h] [ebp-18h]
  DecalBatchList_t *pBatch; // [esp+AA8h] [ebp-14h]
  unsigned __int8 color[4]; // [esp+AACh] [ebp-10h]
  float flFadeValue; // [esp+AB0h] [ebp-Ch]
  int nIndexCount; // [esp+AB4h] [ebp-8h]
  bool bBatchInit; // [esp+ABAh] [ebp-2h]
  bool bMeshInit; // [esp+ABBh] [ebp-1h]
  bool bWireframe_3; // [esp+AD3h] [ebp+17h]

  meshList.m_aBatches.m_Size = 0;
  meshList.m_aBatches.m_pElements = (DecalBatchList_t *)&meshList.m_aBatches;
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  v5 = 5 * g_nMaxDecals;
  nVertCount = 0;
  nIndexCount = 0;
  GetMaxVerticesToRender = pRenderContext->GetMaxVerticesToRender;
  v7 = 15 * g_nMaxDecals;
  nDecalSortMaxVerts = 5 * g_nMaxDecals;
  nDecalSortMaxIndices = 15 * g_nMaxDecals;
  if ( v5 >= GetMaxVerticesToRender(this: pRenderContext, a2: g_materialDecalWireframe) / 4 )
    nDecalSortMaxVerts = pRenderContext->GetMaxVerticesToRender(this: pRenderContext, a2: g_materialDecalWireframe) / 4;
  if ( v7 >= pRenderContext->GetMaxIndicesToRender(this: pRenderContext) )
    nDecalSortMaxIndices = pRenderContext->GetMaxIndicesToRender(this: pRenderContext);
  v8 = nullptr;
  context.vModelOrg.x = vModelOrg->x;
  context.vModelOrg.y = vModelOrg->y;
  z = vModelOrg->z;
  v10 = nullptr;
  bMeshInit = true;
  bBatchInit = true;
  pBatch = nullptr;
  vertexFormat = 0;
  pDecalHead = nullptr;
  lastSurf = nullptr;
  context.pRenderContext = pRenderContext;
  context.vModelOrg.z = z;
  context.pSurf = nullptr;
  bWireframe_3 = (sv_cheats.m_pParent != nullptr && sv_cheats.m_pParent->m_Value.m_nValue != 0 || Cmd_IsRptActive())
              && (mat_wireframe.m_pParent == nullptr
                ? (m_nValue = 0)
                : (m_nValue = mat_wireframe.m_pParent->m_Value.m_nValue),
                  m_nValue != 0)
              || r_drawdecals.m_pParent != nullptr && r_drawdecals.m_pParent->m_Value.m_nValue == 2;
  if ( iDecalCount == 0 )
  {
LABEL_120:
    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
    {
      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
    }
    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
    }
    return;
  }
  v63 = 1;
  v61 = ppDecals;
  while ( 1 )
  {
    v12 = *v61;
    if ( *v61 == nullptr || v12 == (decal_t *)-1 )
    {
      if ( v10 != nullptr )
        v10->m_nIndexCount = nIndexCount - v10->m_iStartIndex;
      if ( v12 == nullptr && !bMeshInit )
      {
        if ( meshBuilder.m_bGenerateIndices )
        {
          switch ( meshBuilder.m_Type )
          {
            case MATERIAL_LINE_STRIP:
              m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
              break;
            case MATERIAL_LINE_LOOP:
              m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
              break;
            case MATERIAL_POLYGON:
              m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
              break;
            case MATERIAL_QUADS:
              m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
              break;
            case MATERIAL_INSTANCED_QUADS:
              m_nVertexCount = 0;
              break;
            default:
              m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
              break;
          }
          CIndexBuilder::GenerateIndices(
            this: &meshBuilder.m_IndexBuilder,
            primitiveType: meshBuilder.m_Type,
            nIndexCount: m_nVertexCount);
        }
        meshBuilder.m_pMesh->UnlockMesh(
          this: meshBuilder.m_pMesh,
          a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
          a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
          a4: &meshBuilder);
        meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
        meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
        meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
        meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
        meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
        meshBuilder.m_pMesh = nullptr;
        R_DrawDecalMeshList(a1: (int)v10, a2: 0, &meshList);
        bMeshInit = true;
      }
      v10 = nullptr;
      bBatchInit = true;
      pBatch = nullptr;
      if ( v12 == (decal_t *)-1 )
      {
        for ( i = v63; i != iDecalCount; ++i )
        {
          v8 = ppDecals[i];
          pDecalHead = v8;
          if ( v8 != nullptr && v8 != (decal_t *)-1 )
            break;
        }
        v43 = v8->material->GetVertexFormat(this: v8->material);
        LODWORD(v43) = v43 & 0xFFFFFBFF;
        vertexFormat = v43;
      }
      goto LABEL_96;
    }
    if ( (v12->flags & 0x100) == 0 )
      break;
    if ( (v12->flags & 0x4000) != 0 )
      break;
    fadeDuration = v12->fadeDuration;
    v12->flags |= 0x4000u;
    if ( fadeDuration <= 0.0 )
      break;
    BaseLocalClient = GetBaseLocalClient();
    if ( CClientState::GetTime(this: BaseLocalClient) < v12->fadeStartTime + v12->fadeDuration )
      break;
    if ( v12->pDestroyList == nullptr )
    {
      v12->pDestroyList = s_pDecalDestroyList;
      s_pDecalDestroyList = v12;
    }
LABEL_96:
    ++v61;
    if ( v63++ == iDecalCount )
    {
      if ( v10 != nullptr )
        v10->m_nIndexCount = nIndexCount - v10->m_iStartIndex;
      if ( !bMeshInit )
      {
        if ( meshBuilder.m_bGenerateIndices )
        {
          switch ( meshBuilder.m_Type )
          {
            case MATERIAL_LINE_STRIP:
              v45 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
              break;
            case MATERIAL_LINE_LOOP:
              v45 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
              break;
            case MATERIAL_POLYGON:
              v45 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
              break;
            case MATERIAL_QUADS:
              v45 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
              break;
            case MATERIAL_INSTANCED_QUADS:
              v45 = 0;
              break;
            default:
              v45 = meshBuilder.m_VertexBuilder.m_nVertexCount;
              break;
          }
          CIndexBuilder::GenerateIndices(
            this: &meshBuilder.m_IndexBuilder,
            primitiveType: meshBuilder.m_Type,
            nIndexCount: v45);
        }
        meshBuilder.m_pMesh->UnlockMesh(
          this: meshBuilder.m_pMesh,
          a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
          a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
          a4: &meshBuilder);
        meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
        meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
        meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
        meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
        meshBuilder.m_pMesh = nullptr;
        meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
        R_DrawDecalMeshList(a1: (int)v10, a2: (int)v12, &meshList);
      }
      goto LABEL_120;
    }
  }
  surfID = v12->surfID;
  if ( surfID != lastSurf )
    lastSurf = v12->surfID;
  pVerts = (CDecalVert *)R_DecalSetupVerts(&context, pDecal: v12, surfID, pMaterial: v12->material);
  if ( pVerts == nullptr )
    goto LABEL_96;
  clippedVertCount = v12->clippedVertCount;
  nCount = clippedVertCount;
  if ( clippedVertCount + nVertCount <= nDecalSortMaxVerts && clippedVertCount + nIndexCount - 2 <= nDecalSortMaxIndices )
  {
    if ( !bMeshInit )
      goto LABEL_48;
  }
  else
  {
    if ( v10 != nullptr )
      v10->m_nIndexCount = nIndexCount - v10->m_iStartIndex;
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          v17 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          v17 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          v17 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          v17 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          v17 = 0;
          break;
        default:
          v17 = meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: v17);
    }
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    R_DrawDecalMeshList(a1: 0, a2: (int)v12, &meshList);
    pBatch = nullptr;
    bBatchInit = true;
  }
  v10 = nullptr;
  meshList.m_pMesh = nullptr;
  meshList.m_aBatches.m_Size = 0;
  if ( bWireframe_3 )
    v18 = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 0, a3: 0, a4: 0, a5: g_materialDecalWireframe);
  else
    v18 = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 0, a3: 0, a4: 0, a5: pDecalHead->material);
  meshList.m_pMesh = v18;
  CMeshBuilder::Begin(
    this: &meshBuilder,
    pMesh: v18,
    type: MATERIAL_TRIANGLES,
    nVertexCount: nDecalSortMaxVerts,
    nIndexCount: nDecalSortMaxIndices,
    pMeshSettings: nullptr);
  nVertCount = 0;
  nIndexCount = 0;
  bMeshInit = false;
LABEL_48:
  if ( !bBatchInit )
  {
LABEL_54:
    g = v12->color.g;
    b = v12->color.b;
    LOBYTE(v23) = v12->color.a;
    color[0] = v12->color.r;
    color[1] = g;
    color[2] = b;
    if ( flFade != 1.0 )
      v23 = (int)(float)((float)(unsigned __int8)v23 * flFade);
    if ( (v12->flags & 0x100) != 0 )
    {
      if ( v12->fadeDuration >= 0.0 )
      {
        v26 = GetBaseLocalClient();
        v25 = 1.0 - (CClientState::GetTime(this: v26) - v12->fadeStartTime) / v12->fadeDuration;
      }
      else
      {
        v24 = GetBaseLocalClient();
        v25 = -((CClientState::GetTime(this: v24) - v12->fadeStartTime) / v12->fadeDuration);
      }
      flFadeValue = v25;
      v27 = flFadeValue;
      if ( flFadeValue >= 0.0 )
      {
        if ( flFadeValue > 1.0 )
          v27 = 1.0;
      }
      else
      {
        v27 = 0.0;
      }
      v23 = (int)(float)((float)(unsigned __int8)v23 * v27);
    }
    vecNormal.x = 0.0;
    vecNormal.y = 0.0;
    vecNormal.z = 1.0;
    vecTangentS.x = 1.0;
    vecTangentS.y = 0.0;
    vecTangentS.z = 0.0;
    vecTangentT.x = 0.0;
    vecTangentT.y = 1.0;
    vecTangentT.z = 0.0;
    if ( (vertexFormat & 0x32) != 0 )
    {
      vecNormal = v12->surfID->plane->normal;
      if ( (vertexFormat & 0x30) != 0 )
      {
        LOBYTE(bNegate) = TangentSpaceSurfaceSetup(surfID: v12->surfID, &tVect);
        TangentSpaceComputeBasis(
          tangentS: &vecTangentS,
          tangentT: &vecTangentT,
          normal: &vecNormal,
          &tVect,
          negateTangent: bNegate);
      }
    }
    flOffset = v12->lightmapOffset;
    if ( clippedVertCount > 0 )
    {
      v50 = vertexFormat & 2;
      v28 = color[2] | ((color[1] | ((color[0] | ((unsigned __int8)v23 << 8)) << 8)) << 8);
      v29 = vertexFormat & 0x30;
      p_y = &pVerts->m_vPos.y;
      flFadeValue = *(float *)&nCount;
      do
      {
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        v32 = v50;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = *(p_y - 1);
        m_pCurrPosition[1] = *p_y;
        m_pCurrPosition[2] = p_y[1];
        if ( v32 != 0 )
          *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrNormal = vecNormal;
        *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = v28;
        v33 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
        v34 = *((_DWORD *)p_y + 4);
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = p_y[3];
        *((_DWORD *)v33 + 1) = v34;
        v35 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1];
        v36 = *((_DWORD *)p_y + 6);
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[1] = p_y[5];
        *((_DWORD *)v35 + 1) = v36;
        *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[2] = flOffset;
        if ( v29 != 0 )
        {
          *(Vector *)((char *)meshBuilder.m_VertexBuilder.m_pTangentS
                    + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentS) = vecTangentS;
          *(Vector *)((char *)meshBuilder.m_VertexBuilder.m_pTangentT
                    + meshBuilder.m_VertexBuilder.m_nCurrentVertex * meshBuilder.m_VertexBuilder.m_VertexSize_TangentT) = vecTangentT;
        }
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        p_y += 8;
        --LODWORD(flFadeValue);
      }
      while ( flFadeValue != 0.0 );
    }
    v37 = nCount;
    v38 = nVertCount;
    v39 = nCount - 2;
    CIndexBuilder::FastPolygon(this: &meshBuilder.m_IndexBuilder, startVert: nVertCount, triangleCount: nCount - 2);
    v12 = (decal_t *)(v37 + v38);
    v8 = pDecalHead;
    v40 = v39 + nIndexCount + 2 * v39;
    v10 = pBatch;
    nVertCount = (int)v12;
    nIndexCount = v40;
    goto LABEL_96;
  }
  if ( meshList.m_aBatches.m_Size + 1 <= 128 )
  {
    v19 = (DecalBatchList_t *)((char *)&meshList.m_aBatches
                             + 16
                             * CUtlVector<DecalBatchList_t,CUtlMemoryFixed<DecalBatchList_t,128,0>>::AddToTail(this: &meshList.m_aBatches));
    pBatch = v19;
    v19->m_iStartIndex = nIndexCount;
    if ( bWireframe_3 )
    {
      v19->m_pMaterial = g_materialDecalWireframe;
    }
    else
    {
      v20 = pDecalHead;
      v19->m_pMaterial = pDecalHead->material;
      v19->m_pProxy = v20->userdata;
      v19->m_iLightmapPage = materialSortInfoArray[v20->surfID->materialSortID].lightmapPageID;
    }
    bBatchInit = false;
    goto LABEL_54;
  }
  _Warning(a1: "R_DrawDecalsAll: overflowing m_aBatches. Reduce # of decals in the scene.\n");
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        v44 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        v44 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
      case MATERIAL_POLYGON:
        v44 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        v44 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
        break;
      case MATERIAL_INSTANCED_QUADS:
        v44 = 0;
        break;
      default:
        v44 = meshBuilder.m_VertexBuilder.m_nVertexCount;
        break;
    }
    CIndexBuilder::GenerateIndices(
      this: &meshBuilder.m_IndexBuilder,
      primitiveType: meshBuilder.m_Type,
      nIndexCount: v44);
  }
  meshBuilder.m_pMesh->UnlockMesh(
    this: meshBuilder.m_pMesh,
    a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_pMesh = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  R_DrawDecalMeshList(a1: (int)v10, a2: (int)v12, &meshList);
  CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
}

//------------------------------------------------------------------------------
// Address: 0x10104940
// Name: void DecalSurfaceDraw_QueueHelper(bool,int,class Vector,int,struct decal_t __near * __near *,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DecalSurfaceDraw_QueueHelper(
        bool bBatched,
        int renderGroup,
        Vector vModelOrg,
        int nCheckCount,
        decal_t **ppDecals,
        int iPermanentLightmap,
        int iLightmap,
        int iNonLightmap,
        float flFade)
{
  IMatRenderContext *v9; // esi
  int v10; // ebx
  decal_t **v11; // edi
  decal_t **v12; // edi
  int v13; // ebx
  int v14; // edi
  decal_t **v15; // ebx
  decal_t **v16; // edi
  int v17; // ebx

  v9 = materials->GetRenderContext(this: materials);
  if ( v9 != nullptr )
    v9->BeginRender(this: v9);
  if ( bBatched )
  {
    v10 = iPermanentLightmap;
    v11 = ppDecals;
    R_DrawDecalsAll_Gathered(pRenderContext: v9, ppDecals, iDecalCount: iPermanentLightmap, &vModelOrg, flFade);
    v12 = &v11[v10];
    v13 = iLightmap;
    R_DrawDecalsAll_Gathered(pRenderContext: v9, ppDecals: v12, iDecalCount: iLightmap, &vModelOrg, flFade);
    R_DrawDecalsAll_Gathered(pRenderContext: v9, ppDecals: &v12[v13], iDecalCount: iNonLightmap, &vModelOrg, flFade);
  }
  else
  {
    v14 = iPermanentLightmap;
    v15 = ppDecals;
    R_DrawDecalsAllImmediate_Gathered(
      m_nIndexCount: (int)ppDecals,
      a2: iPermanentLightmap,
      p_meshBuilder: (CMeshBuilder *)v9,
      pRenderContext: v9,
      ppDecals,
      iDecalCount: iPermanentLightmap,
      &vModelOrg,
      flFade);
    v16 = &v15[v14];
    v17 = iLightmap;
    R_DrawDecalsAllImmediate_Gathered(
      m_nIndexCount: iLightmap,
      a2: (int)v16,
      p_meshBuilder: (CMeshBuilder *)v9,
      pRenderContext: v9,
      ppDecals: v16,
      iDecalCount: iLightmap,
      &vModelOrg,
      flFade);
    R_DrawDecalsAllImmediate_Gathered(
      m_nIndexCount: v17,
      a2: (int)v16,
      p_meshBuilder: (CMeshBuilder *)v9,
      pRenderContext: v9,
      ppDecals: &v16[v17],
      iDecalCount: iNonLightmap,
      &vModelOrg,
      flFade);
  }
  if ( v9 != nullptr )
  {
    v9->EndRender(this: v9);
    v9->Release(this: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10104A30
// Name: void DecalSurfaceDraw(class IMatRenderContext __near *,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DecalSurfaceDraw(IMatRenderContext *pRenderContext, int renderGroup, float flFade)
{
  CMeshBuilder *v3; // ebx
  int v4; // edi
  int m_nValue; // eax
  bool v6; // bl
  int v7; // ebx
  IMatRenderContext_vtbl *v8; // edx
  void *(__thiscall *LockRenderData)(IMatRenderContext *, int); // eax
  CMatRenderData<unsigned char> rd; // [esp+10h] [ebp-2Ch] BYREF
  ICallQueue *pCallQueue; // [esp+20h] [ebp-1Ch]
  decal_t **arg5; // [esp+24h] [ebp-18h] BYREF
  int nCheckCount; // [esp+28h] [ebp-14h] BYREF
  int iLightmap; // [esp+2Ch] [ebp-10h] BYREF
  int iNonLightmap; // [esp+30h] [ebp-Ch] BYREF
  int iPermanentLightmap; // [esp+34h] [ebp-8h] BYREF
  bool bBatched; // [esp+3Bh] [ebp-1h] BYREF

  if ( r_drawdecals.m_pParent != nullptr && r_drawdecals.m_pParent->m_Value.m_nValue != 0 )
  {
    v3 = (CMeshBuilder *)g_nDecalSortCheckCount;
    v4 = renderGroup;
    nCheckCount = g_nDecalSortCheckCount;
    if ( renderGroup == 4 )
    {
      v3 = (CMeshBuilder *)g_nBrushModelDecalSortCheckCount;
      nCheckCount = g_nBrushModelDecalSortCheckCount;
    }
    if ( r_queued_decals.m_pParent != nullptr
      && r_queued_decals.m_pParent->m_Value.m_nValue != 0
      && (pCallQueue = pRenderContext->GetCallQueue(this: pRenderContext)) != nullptr )
    {
      if ( r_drawbatchdecals.m_pParent != nullptr )
        m_nValue = r_drawbatchdecals.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      v6 = m_nValue != 0;
      bBatched = m_nValue != 0;
      if ( (_S1_11 & 1) == 0 )
      {
        _S1_11 |= 1u;
        DrawDecals.m_Memory.m_pMemory = nullptr;
        DrawDecals.m_Memory.m_nAllocationCount = 0;
        DrawDecals.m_Memory.m_nGrowSize = 0;
        DrawDecals.m_Size = 0;
        DrawDecals.m_pElements = nullptr;
        atexit(func: DecalSurfaceDraw_::_11_::_dynamic_atexit_destructor_for__DrawDecals__);
      }
      if ( v6 )
      {
        R_DrawDecalsAll_GatherDecals(pRenderContext, iGroup: v4, iTreeType: 0, DrawDecals: &DrawDecals);
        iPermanentLightmap = DrawDecals.m_Size;
        R_DrawDecalsAll_GatherDecals(pRenderContext, iGroup: v4, iTreeType: 1, DrawDecals: &DrawDecals);
        v7 = DrawDecals.m_Size - iPermanentLightmap;
        iLightmap = DrawDecals.m_Size - iPermanentLightmap;
        R_DrawDecalsAll_GatherDecals(pRenderContext, iGroup: v4, iTreeType: 2, DrawDecals: &DrawDecals);
      }
      else
      {
        R_DrawDecalsAllImmediate_GatherDecals(pRenderContext, iGroup: v4, iTreeType: 0, DrawDecals: &DrawDecals);
        iPermanentLightmap = DrawDecals.m_Size;
        R_DrawDecalsAllImmediate_GatherDecals(pRenderContext, iGroup: v4, iTreeType: 1, DrawDecals: &DrawDecals);
        v7 = DrawDecals.m_Size - iPermanentLightmap;
        iLightmap = DrawDecals.m_Size - iPermanentLightmap;
        R_DrawDecalsAllImmediate_GatherDecals(pRenderContext, iGroup: v4, iTreeType: 2, DrawDecals: &DrawDecals);
      }
      iNonLightmap = DrawDecals.m_Size - v7 - iPermanentLightmap;
      if ( DrawDecals.m_Size != 0 )
      {
        v8 = pRenderContext->__vftable;
        rd.m_nCount = 4 * DrawDecals.m_Size;
        LockRenderData = v8->LockRenderData;
        rd.m_pRenderContext = pRenderContext;
        rd.m_pRenderData = (unsigned __int8 *)LockRenderData(this: pRenderContext, a2: 4 * DrawDecals.m_Size);
        rd.m_bNeedsUnlock = true;
        memcpy(
          dst: rd.m_pRenderData,
          src: (unsigned __int8 *)DrawDecals.m_Memory.m_pMemory,
          count: 4 * DrawDecals.m_Size);
        arg5 = (decal_t **)rd.m_pRenderData;
        ICallQueue::QueueCall<void,bool,int,Vector,int,decal_t * *,int,int,int,float,bool,int,Vector,int,decal_t * *,int,int,int,float>(
          this: pCallQueue,
          pfnProxied: DecalSurfaceDraw_QueueHelper,
          arg1: &bBatched,
          arg2: &renderGroup,
          arg3: &modelorg,
          arg4: &nCheckCount,
          &arg5,
          arg6: &iPermanentLightmap,
          arg7: &iLightmap,
          arg8: &iNonLightmap,
          arg9: &flFade);
        DrawDecals.m_Size = 0;
        CMatRenderData<memhandle_t__ *>::~CMatRenderData<memhandle_t__ *>(this: (CMatRenderData<matrix3x4a_t> *)&rd);
      }
    }
    else
    {
      DecalSurfaceDraw_NonQueued(pRenderContext, renderGroup: v4, vModelOrg: &modelorg, nCheckCount: v3, flFade);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10104C30
// Name: R_DecalMaterialSort
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DecalMaterialSort(decal_t *pDecal, int surfID)
{
  decal_t *v2; // esi
  IMaterial *material; // eax
  int v4; // edx
  int v5; // ebx
  __int64 v6; // rax
  unsigned int v7; // ebx
  int v8; // edi
  DecalSortVertexFormat_t *m_pMemory; // ecx
  int m_Size; // esi
  int v11; // eax
  int v12; // esi
  int v13; // eax
  int v14; // esi
  DecalSortTrees_t *v15; // edx
  int v16; // eax
  DecalSortTrees_t *v17; // ecx
  int v18; // eax
  int v19; // ebx
  DecalSortTrees_t *v20; // ecx
  int v21; // eax
  DecalSortTrees_t *v22; // ebx
  int m_iSortTree; // edi
  bool (__thiscall *GetPropertyFlag)(IMaterial *, MaterialPropertyTypes_t); // edx
  int v25; // ebx
  CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl*)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int> > *v26; // ecx
  int v27; // eax
  int v28; // esi
  int v29; // edi
  int v30; // eax
  CUtlMemory<ResourceEntryInfo,int> *v31; // esi
  ResourceEntryInfo *v32; // ecx
  int v33; // eax
  int *v34; // esi
  int v35; // ecx
  int v36; // eax
  int v37; // edx
  int v38; // eax
  int v39; // eax
  int v40; // edx
  int v41; // ebx
  int v42; // edi
  int *v43; // esi
  int v44; // eax
  int v45; // ecx
  int v46; // eax
  int v47; // edi
  int v48; // eax
  int *v49; // esi
  int v50; // ecx
  int v51; // eax
  int v52; // eax
  int v53; // edx
  bool v54; // zf
  char *v55; // esi
  CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl*)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int> > *v56; // edi
  int v57; // eax
  int v58; // edx
  int v59; // ebx
  UtlRBTreeNode_t<DecalMaterialSortData_t,int> *v60; // ecx
  int v61; // ecx
  UtlRBTreeNode_t<DecalMaterialSortData_t,int> *v62; // edx
  UtlRBTreeNode_t<DecalMaterialSortData_t,int> *v63; // eax
  DecalMaterialSortData_t *p_m_Data; // ebx
  CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl*)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int> > *v65; // esi
  int v66; // eax
  int v67; // edx
  int v68; // edi
  UtlRBTreeNode_t<DecalMaterialSortData_t,int> *v69; // ecx
  int v70; // ecx
  UtlRBTreeNode_t<DecalMaterialSortData_t,int> *v71; // edx
  UtlRBTreeNode_t<DecalMaterialSortData_t,int> *v72; // eax
  DecalMaterialSortData_t *v73; // eax
  int m_iBucket; // ecx
  DecalMaterialSortData_t sort; // [esp+Ch] [ebp-24h] BYREF
  unsigned __int64 vertexFormat; // [esp+18h] [ebp-18h]
  int v77; // [esp+20h] [ebp-10h]
  int iSortTree; // [esp+24h] [ebp-Ch]
  int parent; // [esp+28h] [ebp-8h] BYREF
  int v80; // [esp+2Ch] [ebp-4h]

  v2 = pDecal;
  if ( pDecal->material->InMaterialPage(this: pDecal->material) )
    material = pDecal->material->GetMaterialPage(this: pDecal->material);
  else
    material = pDecal->material;
  v4 = *(__int16 *)(surfID + 18);
  sort.m_pMaterial = material;
  sort.m_iLightmapPage = materialSortInfoArray[v4].lightmapPageID;
  v6 = material->GetVertexFormat(this: material);
  v5 = v6;
  LODWORD(v6) = g_aDecalFormats.m_Size;
  v7 = v5 & 0xFFFFFBFF;
  v8 = 0;
  HIDWORD(vertexFormat) = HIDWORD(v6);
  if ( g_aDecalFormats.m_Size > 0 )
  {
    m_pMemory = g_aDecalFormats.m_Memory.m_pMemory;
    do
    {
      if ( m_pMemory->m_VertexFormat == __PAIR64__(HIDWORD(v6), v7) )
        break;
      ++v8;
      ++m_pMemory;
    }
    while ( v8 < g_aDecalFormats.m_Size );
  }
  if ( v8 == g_aDecalFormats.m_Size )
  {
    m_Size = g_aDecalFormats.m_Size;
    if ( g_aDecalFormats.m_Size + 1 > g_aDecalFormats.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CPortalRect,int>::Grow(
        this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)&g_aDecalFormats,
        num: g_aDecalFormats.m_Size - g_aDecalFormats.m_Memory.m_nAllocationCount + 1);
      v6 = __PAIR64__(HIDWORD(vertexFormat), g_aDecalFormats.m_Size);
    }
    g_aDecalFormats.m_Size = v6 + 1;
    v11 = v6 - m_Size;
    g_aDecalFormats.m_pElements = g_aDecalFormats.m_Memory.m_pMemory;
    if ( v11 > 0 )
    {
      _V_memmove(
        dest: &g_aDecalFormats.m_Memory.m_pMemory[m_Size + 1],
        src: &g_aDecalFormats.m_Memory.m_pMemory[m_Size],
        count: 16 * v11);
      HIDWORD(v6) = HIDWORD(vertexFormat);
    }
    v8 = m_Size;
    v12 = m_Size;
    LODWORD(g_aDecalFormats.m_Memory.m_pMemory[v12].m_VertexFormat) = v7;
    HIDWORD(g_aDecalFormats.m_Memory.m_pMemory[v12].m_VertexFormat) = HIDWORD(v6);
    v13 = g_aDecalSortTrees.m_Size;
    surfID = v12 * 16;
    v14 = g_aDecalSortTrees.m_Size;
    if ( g_aDecalSortTrees.m_Size + 1 > g_aDecalSortTrees.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<DecalSortTrees_t,int>::Grow(
        this: &g_aDecalSortTrees.m_Memory,
        num: g_aDecalSortTrees.m_Size - g_aDecalSortTrees.m_Memory.m_nAllocationCount + 1);
      v13 = g_aDecalSortTrees.m_Size;
    }
    v15 = g_aDecalSortTrees.m_Memory.m_pMemory;
    g_aDecalSortTrees.m_Size = v13 + 1;
    v16 = v13 - v14;
    g_aDecalSortTrees.m_pElements = g_aDecalSortTrees.m_Memory.m_pMemory;
    if ( v16 > 0 )
    {
      _V_memmove(
        dest: &g_aDecalSortTrees.m_Memory.m_pMemory[v14 + 1],
        src: &g_aDecalSortTrees.m_Memory.m_pMemory[v14],
        count: 312 * v16);
      v15 = g_aDecalSortTrees.m_Memory.m_pMemory;
    }
    v17 = &v15[v14];
    if ( v17 != nullptr )
      DecalSortTrees_t::DecalSortTrees_t(this: v17);
    v18 = g_aDispDecalSortTrees.m_Size;
    v19 = g_aDispDecalSortTrees.m_Size;
    if ( g_aDispDecalSortTrees.m_Size + 1 > g_aDispDecalSortTrees.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<DecalSortTrees_t,int>::Grow(
        this: &g_aDispDecalSortTrees.m_Memory,
        num: g_aDispDecalSortTrees.m_Size - g_aDispDecalSortTrees.m_Memory.m_nAllocationCount + 1);
      v18 = g_aDispDecalSortTrees.m_Size;
    }
    v20 = g_aDispDecalSortTrees.m_Memory.m_pMemory;
    g_aDispDecalSortTrees.m_Size = v18 + 1;
    v21 = v18 - v19;
    g_aDispDecalSortTrees.m_pElements = g_aDispDecalSortTrees.m_Memory.m_pMemory;
    if ( v21 > 0 )
    {
      _V_memmove(
        dest: &g_aDispDecalSortTrees.m_Memory.m_pMemory[v19 + 1],
        src: &g_aDispDecalSortTrees.m_Memory.m_pMemory[v19],
        count: 312 * v21);
      v20 = g_aDispDecalSortTrees.m_Memory.m_pMemory;
    }
    v22 = &v20[v19];
    if ( v22 != nullptr )
      DecalSortTrees_t::DecalSortTrees_t(this: v22);
    *(int *)((char *)&g_aDecalFormats.m_Memory.m_pMemory->m_iSortTree + surfID) = v14;
    v2 = pDecal;
  }
  m_iSortTree = g_aDecalFormats.m_Memory.m_pMemory[v8].m_iSortTree;
  GetPropertyFlag = sort.m_pMaterial->GetPropertyFlag;
  iSortTree = m_iSortTree;
  if ( GetPropertyFlag(this: sort.m_pMaterial, a2: MATERIAL_PROPERTY_NEEDS_LIGHTMAP) )
  {
    v25 = (v2->flags & 1) == 0;
    surfID = v25;
  }
  else
  {
    surfID = 2;
    v25 = 2;
    sort.m_iLightmapPage = -1;
  }
  v26 = g_aDecalSortTrees.m_Memory.m_pMemory[m_iSortTree].m_pTrees[v25];
  HIDWORD(vertexFormat) = 312 * m_iSortTree;
  v27 = CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl *)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int>>::Find(
          this: v26,
          search: &sort);
  if ( v27 == -1 )
  {
    v28 = 312 * m_iSortTree + 20 * v25;
    v29 = *(int *)((char *)&g_aDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets[0][0].m_Size + v28);
    v30 = *(int *)((char *)&g_aDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets[0][0].m_Memory.m_nAllocationCount
                 + v28);
    v80 = v28;
    v31 = (CUtlMemory<ResourceEntryInfo,int> *)((char *)g_aDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets + v28);
    parent = v29;
    if ( v29 + 1 > v30 )
      CUtlMemory<CAsyncWavDataCache::DeadBufferEntry_t,int>::Grow(this: v31, num: v29 - v30 + 1);
    ++v31[1].m_pMemory;
    v32 = v31->m_pMemory;
    v33 = (int)v31[1].m_pMemory - v29 - 1;
    v31[1].m_nAllocationCount = (int)v31->m_pMemory;
    if ( v33 > 0 )
      _V_memmove(dest: &v32[v29 + 1], src: &v32[v29], count: 8 * v33);
    v34 = (int *)((char *)g_aDispDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets + v80);
    v36 = *(int *)((char *)&g_aDispDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets[0][0].m_Memory.m_nAllocationCount
                 + v80);
    v77 = *(int *)((char *)&g_aDispDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets[0][0].m_Size + v80);
    v35 = v77;
    if ( v77 + 1 > v36 )
    {
      CUtlMemory<CAsyncWavDataCache::DeadBufferEntry_t,int>::Grow(
        this: (CUtlMemory<ResourceEntryInfo,int> *)((char *)g_aDispDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets + v80),
        num: v77 - v36 + 1);
      v35 = v77;
    }
    ++v34[3];
    v37 = *v34;
    v38 = v34[3] - v35 - 1;
    v34[4] = *v34;
    if ( v38 > 0 )
      _V_memmove(dest: (void *)(v37 + 8 * v35 + 8), src: (const void *)(v37 + 8 * v35), count: 8 * v38);
    v39 = v80;
    (*(DecalMaterialBucket_t **)((char *)&g_aDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets[0][0].m_Memory.m_pMemory
                               + v80))[v29].m_nCheckCount = -1;
    v40 = HIDWORD(vertexFormat);
    (*(DecalMaterialBucket_t **)((char *)&g_aDispDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets[0][0].m_Memory.m_pMemory
                               + v39))[v29].m_nCheckCount = -1;
    v41 = v40 + 4 * (5 * v25 + 15);
    v80 = 4;
    do
    {
      v42 = *(int *)((char *)&g_aDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets[0][0].m_Size + v41);
      v43 = (int *)((char *)g_aDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets + v41);
      v44 = *(int *)((char *)&g_aDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets[0][0].m_Memory.m_nAllocationCount
                   + v41);
      if ( v42 + 1 > v44 )
        CUtlMemory<CAsyncWavDataCache::DeadBufferEntry_t,int>::Grow(
          this: (CUtlMemory<ResourceEntryInfo,int> *)((char *)g_aDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets + v41),
          num: v42 - v44 + 1);
      ++v43[3];
      v45 = *v43;
      v46 = v43[3] - v42 - 1;
      v43[4] = *v43;
      if ( v46 > 0 )
        _V_memmove(dest: (void *)(v45 + 8 * v42 + 8), src: (const void *)(v45 + 8 * v42), count: 8 * v46);
      v47 = *(int *)((char *)&g_aDispDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets[0][0].m_Size + v41);
      v48 = *(int *)((char *)&g_aDispDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets[0][0].m_Memory.m_nAllocationCount
                   + v41);
      v49 = (int *)((char *)g_aDispDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets + v41);
      if ( v47 + 1 > v48 )
        CUtlMemory<CAsyncWavDataCache::DeadBufferEntry_t,int>::Grow(
          this: (CUtlMemory<ResourceEntryInfo,int> *)((char *)g_aDispDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets
                                              + v41),
          num: v47 - v48 + 1);
      ++v49[3];
      v50 = *v49;
      v51 = v49[3] - v47 - 1;
      v49[4] = *v49;
      if ( v51 > 0 )
        _V_memmove(dest: (void *)(v50 + 8 * v47 + 8), src: (const void *)(v50 + 8 * v47), count: 8 * v51);
      v52 = parent;
      (*(DecalMaterialBucket_t **)((char *)&g_aDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets[0][0].m_Memory.m_pMemory
                                 + v41))[parent].m_nCheckCount = -1;
      v53 = *(int *)((char *)&g_aDispDecalSortTrees.m_Memory.m_pMemory->m_aDecalSortBuckets[0][0].m_Memory.m_pMemory
                   + v41);
      v41 += 60;
      v54 = v80-- == 1;
      *(_DWORD *)(v53 + 8 * v52 + 4) = -1;
    }
    while ( !v54 );
    sort.m_iBucket = v52;
    v55 = (char *)(4 * (surfID + 78 * iSortTree));
    v56 = *(CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl*)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int> > **)&v55[(unsigned int)g_aDecalSortTrees.m_Memory.m_pMemory];
    parent = -1;
    HIBYTE(surfID) = 0;
    CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl *)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int>>::FindInsertionPosition(
      this: v56,
      insert: &sort,
      &parent,
      leftchild: (bool *)&surfID + 3);
    v57 = CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl *)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int>>::NewNode(this: v56);
    v58 = parent;
    v59 = v57;
    v60 = &v56->m_Elements.m_pMemory[v57];
    v60->m_Parent = parent;
    v60->m_Right = -1;
    v60->m_Left = -1;
    v60->m_Tag = 0;
    if ( v58 == -1 )
    {
      v56->m_Root = v57;
    }
    else
    {
      v61 = v58;
      v62 = v56->m_Elements.m_pMemory;
      if ( HIBYTE(surfID) != 0 )
        v62[v61].m_Left = v57;
      else
        v62[v61].m_Right = v57;
    }
    CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl *)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int>>::InsertRebalance(
      this: v56,
      elem: v57);
    v63 = v56->m_Elements.m_pMemory;
    ++v56->m_NumElements;
    p_m_Data = &v63[v59].m_Data;
    if ( p_m_Data != nullptr )
      *p_m_Data = sort;
    v65 = *(CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl*)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int> > **)&v55[(unsigned int)g_aDispDecalSortTrees.m_Memory.m_pMemory];
    parent = -1;
    HIBYTE(surfID) = 0;
    CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl *)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int>>::FindInsertionPosition(
      this: v65,
      insert: &sort,
      &parent,
      leftchild: (bool *)&surfID + 3);
    v66 = CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl *)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int>>::NewNode(this: v65);
    v67 = parent;
    v68 = v66;
    v69 = &v65->m_Elements.m_pMemory[v66];
    v69->m_Parent = parent;
    v69->m_Right = -1;
    v69->m_Left = -1;
    v69->m_Tag = 0;
    if ( v67 == -1 )
    {
      v65->m_Root = v66;
    }
    else
    {
      v70 = v67;
      v71 = v65->m_Elements.m_pMemory;
      if ( HIBYTE(surfID) != 0 )
        v71[v70].m_Left = v66;
      else
        v71[v70].m_Right = v66;
    }
    CUtlRBTree<DecalMaterialSortData_t,int,bool (__cdecl *)(DecalMaterialSortData_t const &,DecalMaterialSortData_t const &),CUtlMemory<UtlRBTreeNode_t<DecalMaterialSortData_t,int>,int>>::InsertRebalance(
      this: v65,
      elem: v66);
    v72 = v65->m_Elements.m_pMemory;
    ++v65->m_NumElements;
    v73 = &v72[v68].m_Data;
    if ( v73 != nullptr )
      *v73 = sort;
    m_iBucket = sort.m_iBucket;
    pDecal->m_iSortTree = iSortTree;
    pDecal->m_iSortMaterial = m_iBucket;
  }
  else
  {
    pDecal->m_iSortTree = m_iSortTree;
    pDecal->m_iSortMaterial = g_aDecalSortTrees.m_Memory.m_pMemory[m_iSortTree].m_pTrees[v25]->m_Elements.m_pMemory[v27].m_Data.m_iBucket;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101051D0
// Name: R_DecalCreate
// Source: json
//------------------------------------------------------------------------------
void __usercall R_DecalCreate(
        decalinfo_t *decalinfo@<edi>,
        msurface2_t *surfID,
        float x,
        float y,
        bool bForceForDisplacement)
{
  decal_t *OverlappingDecals; // eax
  decal_t *v6; // esi
  CClientState *BaseLocalClient; // eax

  if ( surfID != nullptr )
  {
    OverlappingDecals = R_DecalFindOverlappingDecals(decalinfo, surfID);
    if ( OverlappingDecals != nullptr )
      R_DecalUnlink(pdecal: OverlappingDecals);
    v6 = R_DecalAlloc(flags: decalinfo->m_Flags);
    v6->flags = decalinfo->m_Flags;
    v6->color = decalinfo->m_Color;
    v6->position = decalinfo->m_Position;
    if ( SLOBYTE(v6->flags) < 0 )
      v6->saxis = decalinfo->m_SAxis;
    v6->dx = x;
    v6->dy = y;
    v6->material = decalinfo->m_pMaterial;
    v6->userdata = decalinfo->m_pUserData;
    v6->scale = decalinfo->m_scale;
    v6->entityIndex = decalinfo->m_Entity;
    if ( decalinfo->m_flFadeDuration > 0.0 )
    {
      v6->flags |= 0x100u;
      v6->fadeDuration = decalinfo->m_flFadeDuration;
      v6->fadeStartTime = decalinfo->m_flFadeStartTime;
      BaseLocalClient = GetBaseLocalClient();
      v6->fadeStartTime = CClientState::GetTime(this: BaseLocalClient) + v6->fadeStartTime;
    }
    if ( (v6->flags & 0x1000) != 0 )
    {
      v6->fadeStartTime = 0.0;
      v6->scale = 1.0;
    }
    if ( bForceForDisplacement
      || (R_DecalVertsClip(pOutVerts: nullptr, pDecal: v6, surfID, pMaterial: decalinfo->m_pMaterial),
          v6->clippedVertCount != 0) )
    {
      R_AddDecalToSurface(pdecal: v6, decalinfo, surfID);
      R_DecalMaterialSort(pDecal: v6, (int)surfID);
    }
    else
    {
      R_DecalUnlink(pdecal: v6);
    }
  }
  else
  {
    ConMsg(a1: "psurface NULL in R_DecalCreate!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10105320
// Name: void R_DecalSurface(struct msurface2_t __near *,struct decalinfo_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DecalSurface(msurface2_t *surfID, decalinfo_t *decalinfo, bool bForceForDisplacement)
{
  const Vector *m_pNormal; // ecx
  float v5; // xmm0_4
  float v6; // xmm2_4
  float z; // xmm1_4
  float *v8; // esi
  bool v9; // zf
  Vector *p_m_SAxis; // ecx
  double v11; // st7
  double v12; // st5
  double v13; // st4
  double v14; // st3
  double m_decalWidth; // st2
  long double v16; // rt0
  double v17; // st1
  double v18; // st7
  double v19; // st6
  long double v20; // rt1
  long double v21; // st6
  double v22; // st5
  long double v23; // st6
  msurface1_t *v24; // ecx
  float x; // [esp+0h] [ebp-28h]
  float y; // [esp+4h] [ebp-24h]
  float wa; // [esp+10h] [ebp-18h]
  float w; // [esp+10h] [ebp-18h]
  float ha; // [esp+14h] [ebp-14h]
  float h; // [esp+14h] [ebp-14h]
  float v31; // [esp+18h] [ebp-10h]
  float v32; // [esp+1Ch] [ebp-Ch]
  float v33; // [esp+20h] [ebp-8h]
  float t; // [esp+24h] [ebp-4h]
  float ta; // [esp+24h] [ebp-4h]
  float s; // [esp+34h] [ebp+Ch]
  float sa; // [esp+34h] [ebp+Ch]

  m_pNormal = decalinfo->m_pNormal;
  if ( m_pNormal == nullptr
    || (float)((float)((float)(m_pNormal->y * surfID->plane->normal.y) + (float)(m_pNormal->x * surfID->plane->normal.x))
             + (float)(m_pNormal->z * surfID->plane->normal.z)) >= 0.0 )
  {
    v5 = decalinfo->m_Position.y;
    v6 = decalinfo->m_Position.x;
    z = decalinfo->m_Position.z;
    v8 = (float *)&host_state.worldbrush->texinfo[*((unsigned __int16 *)surfID + 11) >> 1];
    v9 = SLOBYTE(decalinfo->m_Flags) >= 0;
    s = (float)((float)((float)((float)(*v8 * decalinfo->m_Position.x) + (float)(v8[1] * v5)) + (float)(v8[2] * z))
              + v8[3])
      - (float)host_state.worldbrush->surfaces1[surfID - host_state.worldbrush->surfaces2].textureMins[0];
    t = (float)((float)((float)((float)(v5 * v8[5]) + (float)(v8[4] * v6)) + (float)(z * v8[6])) + v8[7])
      - (float)host_state.worldbrush->surfaces1[surfID - host_state.worldbrush->surfaces2].textureMins[1];
    if ( v9 )
      p_m_SAxis = nullptr;
    else
      p_m_SAxis = &decalinfo->m_SAxis;
    R_DecalComputeBasis(surfaceNormal: &surfID->plane->normal, pSAxis: p_m_SAxis, textureSpaceBasis: decalinfo->m_Basis);
    v11 = v8[1];
    v12 = *v8;
    v33 = decalinfo->m_Basis[0].y;
    v13 = decalinfo->m_Basis[0].z;
    v14 = v8[2];
    m_decalWidth = (double)decalinfo->m_decalWidth;
    v31 = decalinfo->m_Basis[1].y;
    v32 = decalinfo->m_Basis[1].x;
    ha = (float)decalinfo->m_decalHeight;
    v16 = fabs((decalinfo->m_Basis[0].x * v12 + v33 * v11 + v13 * v14) * m_decalWidth);
    v17 = v11 * v31 + v12 * v32;
    v18 = decalinfo->m_Basis[1].z;
    wa = v16;
    w = fabs((v14 * v18 + v17) * ha) + wa;
    v19 = v8[6];
    v20 = fabs(m_decalWidth * (decalinfo->m_Basis[0].x * v8[4] + v33 * v8[5] + v13 * v19));
    v21 = fabs((v19 * v18 + v8[5] * v31 + v8[4] * v32) * ha);
    h = v20 + v21;
    v22 = s - w * 0.5;
    sa = v22;
    v23 = t - 0.5 * (v20 + v21);
    if ( bForceForDisplacement
      || (float)-w < sa
      && (ta = v23, (float)-h < ta)
      && (v24 = &host_state.worldbrush->surfaces1[surfID - host_state.worldbrush->surfaces2],
          sa <= (float)((float)v24->textureExtents[0] + w))
      && ta <= (float)((float)v24->textureExtents[1] + h) )
    {
      y = v23;
      x = v22;
      R_DecalCreate(decalinfo, surfID, x, y, bForceForDisplacement);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101055A0
// Name: R_DecalNodeSurfaces
// Source: json
//------------------------------------------------------------------------------
void __usercall R_DecalNodeSurfaces(decalinfo_t *decalinfo@<eax>, mnode_t *node)
{
  worldbrushdata_t *worldbrush; // eax
  msurface2_t *v4; // ebx
  const Vector *m_pNormal; // ecx
  float *v6; // esi
  int v7; // edx
  msurface1_t *surfaces1; // eax
  int v9; // edx
  Vector *p_m_SAxis; // ecx
  double v11; // st7
  double v12; // st5
  double z; // st4
  double v14; // st3
  double m_decalWidth; // st2
  long double v16; // rt0
  double v17; // st1
  double v18; // st7
  double v19; // st6
  long double v20; // rt1
  long double v21; // st6
  long double v22; // st7
  msurface1_t *v23; // ecx
  float y; // [esp+4h] [ebp-34h]
  float v25; // [esp+18h] [ebp-20h]
  float v26; // [esp+18h] [ebp-20h]
  int i; // [esp+1Ch] [ebp-1Ch]
  float m_decalHeight; // [esp+20h] [ebp-18h]
  float v29; // [esp+20h] [ebp-18h]
  float v30; // [esp+24h] [ebp-14h]
  float v31; // [esp+28h] [ebp-10h]
  float v32; // [esp+2Ch] [ebp-Ch]
  float v33; // [esp+30h] [ebp-8h]
  float x; // [esp+30h] [ebp-8h]
  float v35; // [esp+34h] [ebp-4h]
  float v36; // [esp+34h] [ebp-4h]

  worldbrush = host_state.worldbrush;
  v4 = &host_state.worldbrush->surfaces2[node->firstsurface];
  i = 0;
  if ( node->numsurfaces != 0 )
  {
    do
    {
      if ( (v4->flags & 0x4000) == 0 && (v4->flags & 0x800) == 0 )
      {
        m_pNormal = decalinfo->m_pNormal;
        if ( m_pNormal == nullptr
          || (float)((float)((float)(m_pNormal->y * v4->plane->normal.y) + (float)(v4->plane->normal.x * m_pNormal->x))
                   + (float)(m_pNormal->z * v4->plane->normal.z)) >= 0.0 )
        {
          v6 = (float *)&worldbrush->texinfo[*((unsigned __int16 *)v4 + 11) >> 1];
          v7 = (char *)v4 - (char *)worldbrush->surfaces2;
          surfaces1 = worldbrush->surfaces1;
          v9 = v7 >> 5;
          v33 = (float)((float)((float)((float)(decalinfo->m_Position.x * *v6) + (float)(decalinfo->m_Position.y * v6[1]))
                              + (float)(decalinfo->m_Position.z * v6[2]))
                      + v6[3])
              - (float)surfaces1[v9].textureMins[0];
          v35 = (float)((float)((float)((float)(decalinfo->m_Position.x * v6[4])
                                      + (float)(decalinfo->m_Position.y * v6[5]))
                              + (float)(decalinfo->m_Position.z * v6[6]))
                      + v6[7])
              - (float)surfaces1[v9].textureMins[1];
          if ( SLOBYTE(decalinfo->m_Flags) >= 0 )
            p_m_SAxis = nullptr;
          else
            p_m_SAxis = &decalinfo->m_SAxis;
          R_DecalComputeBasis(
            surfaceNormal: &v4->plane->normal,
            pSAxis: p_m_SAxis,
            textureSpaceBasis: decalinfo->m_Basis);
          v11 = v6[1];
          v12 = *v6;
          v32 = decalinfo->m_Basis[0].y;
          z = decalinfo->m_Basis[0].z;
          v14 = v6[2];
          m_decalWidth = (double)decalinfo->m_decalWidth;
          v31 = decalinfo->m_Basis[1].y;
          v30 = decalinfo->m_Basis[1].x;
          m_decalHeight = (float)decalinfo->m_decalHeight;
          v16 = fabs((decalinfo->m_Basis[0].x * v12 + v32 * v11 + z * v14) * m_decalWidth);
          v17 = v11 * v31 + v12 * v30;
          v18 = decalinfo->m_Basis[1].z;
          v25 = v16;
          v26 = fabs((v14 * v18 + v17) * m_decalHeight) + v25;
          v19 = v6[6];
          v20 = fabs(m_decalWidth * (decalinfo->m_Basis[0].x * v6[4] + v32 * v6[5] + z * v19));
          v21 = fabs((v19 * v18 + v6[4] * v30 + v6[5] * v31) * m_decalHeight);
          v29 = v20 + v21;
          v22 = v35 - (v20 + v21) * 0.5;
          x = v33 - (float)(v26 * 0.5);
          if ( (float)-v26 >= x || (v36 = v22, (float)-v29 >= v36) )
          {
            worldbrush = host_state.worldbrush;
          }
          else
          {
            worldbrush = host_state.worldbrush;
            v23 = &host_state.worldbrush->surfaces1[v4 - host_state.worldbrush->surfaces2];
            if ( x <= (float)((float)v23->textureExtents[0] + v26)
              && v36 <= (float)((float)v23->textureExtents[1] + v29) )
            {
              y = v22;
              R_DecalCreate(decalinfo, surfID: v4, x, y, bForceForDisplacement: false);
              worldbrush = host_state.worldbrush;
            }
          }
        }
      }
      ++v4;
      ++i;
    }
    while ( i < node->numsurfaces );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10105860
// Name: void R_DecalLeaf(struct mleaf_t __near *,struct decalinfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DecalLeaf(mleaf_t *pLeaf, decalinfo_t *decalinfo)
{
  mleaf_t *v2; // ecx
  worldbrushdata_t *worldbrush; // eax
  int v4; // edi
  msurface2_t *v5; // esi
  int m_Size; // edx
  int v7; // eax
  msurface2_t **m_pMemory; // ecx
  float *p_x; // eax
  int v10; // edi
  IDispInfo *v11; // esi
  float v12; // xmm0_4
  msurface2_t *v13; // eax
  Vector bbMin; // [esp+Ch] [ebp-1Ch] BYREF
  Vector bbMax; // [esp+18h] [ebp-10h] BYREF
  msurface2_t **pHandle; // [esp+24h] [ebp-4h]

  v2 = pLeaf;
  worldbrush = host_state.worldbrush;
  pHandle = &host_state.worldbrush->marksurfaces[pLeaf->firstmarksurface];
  v4 = 0;
  if ( pLeaf->nummarksurfaces != 0 )
  {
    do
    {
      v5 = pHandle[v4];
      if ( (v5->flags & 0x4002) == 0 )
      {
        m_Size = decalinfo->m_aApplySurfs.m_Size;
        v7 = 0;
        if ( m_Size <= 0 )
          goto LABEL_9;
        m_pMemory = decalinfo->m_aApplySurfs.m_Memory.m_pMemory;
        while ( *m_pMemory != v5 )
        {
          ++v7;
          ++m_pMemory;
          if ( v7 >= m_Size )
            goto LABEL_9;
        }
        if ( v7 == -1 )
        {
LABEL_9:
          p_x = &v5->plane->normal.x;
          if ( fabs(
                 p_x[1] * decalinfo->m_Position.y
               + *p_x * decalinfo->m_Position.x
               + p_x[2] * decalinfo->m_Position.z
               - p_x[3]) < 4.0 )
            R_DecalSurface(surfID: v5, decalinfo, bForceForDisplacement: false);
        }
      }
      v2 = pLeaf;
      ++v4;
    }
    while ( v4 < pLeaf->nummarksurfaces );
    worldbrush = host_state.worldbrush;
  }
  v10 = 0;
  if ( v2->dispCount != 0 )
  {
    while ( 1 )
    {
      v11 = DispInfo_IndexArray(
              hArray: (_DWORD *)worldbrush->hDispInfos,
              iElement: worldbrush->m_pDispInfoReferences[v10 + pLeaf->dispListStart]);
      if ( (v11->GetParent(this: v11)->flags & 0x4000) == 0 && !v11->GetTag(this: v11) )
      {
        v11->SetTag(this: v11);
        v11->GetBoundingBox(this: v11, a2: &bbMin, a3: &bbMax);
        v12 = decalinfo->m_Size;
        if ( bbMax.x > (float)(decalinfo->m_Position.x - v12)
          && (float)(v12 + decalinfo->m_Position.x) > bbMin.x
          && bbMax.y > (float)(decalinfo->m_Position.y - v12)
          && (float)(v12 + decalinfo->m_Position.y) > bbMin.y
          && bbMax.z > (float)(decalinfo->m_Position.z - v12)
          && (float)(v12 + decalinfo->m_Position.z) > bbMin.z )
        {
          v13 = v11->GetParent(this: v11);
          R_DecalSurface(surfID: v13, decalinfo, bForceForDisplacement: true);
        }
      }
      if ( ++v10 >= pLeaf->dispCount )
        break;
      worldbrush = host_state.worldbrush;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10105A20
// Name: R_DecalNode
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DecalNode(mnode_t *node, decalinfo_t *decalinfo)
{
  mnode_t *v2; // esi
  float v3; // xmm0_4
  float m_Size; // xmm1_4

  v2 = node;
  if ( node != nullptr )
  {
    while ( v2->contents < 0 )
    {
      v3 = (float)((float)((float)(v2->plane->normal.y * decalinfo->m_Position.y)
                         + (float)(v2->plane->normal.x * decalinfo->m_Position.x))
                 + (float)(v2->plane->normal.z * decalinfo->m_Position.z))
         - v2->plane->dist;
      m_Size = decalinfo->m_Size;
      if ( v3 <= m_Size )
      {
        if ( COERCE_FLOAT(LODWORD(m_Size) ^ _mask__NegFloat_) <= v3 )
        {
          if ( v3 < 4.0 && v3 > -4.0 )
            R_DecalNodeSurfaces(decalinfo, node: v2);
          R_DecalNode(node: v2->children[0], decalinfo);
        }
        v2 = v2->children[1];
      }
      else
      {
        v2 = v2->children[0];
      }
      if ( v2 == nullptr )
        return;
    }
    R_DecalLeaf(pLeaf: (mleaf_t *)v2, decalinfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10105AD0
// Name: R_DecalShoot_
// Source: json
//------------------------------------------------------------------------------
void __usercall R_DecalShoot_(
        IMaterial *pMaterial@<esi>,
        const Vector *position@<eax>,
        const Vector *saxis@<edx>,
        int a4@<ebx>,
        int a5@<edi>,
        int entity,
        model_t *model,
        int flags,
        const color32_s *rgbaColor,
        const Vector *pNormal,
        void *userdata)
{
  int v11; // ebx
  float z; // xmm0_4
  worldbrushdata_t *pShared; // eax
  IMaterial_vtbl *v14; // eax
  int (__thiscall *GetMappingWidth)(IMaterial *); // edx
  int v16; // eax
  int (__thiscall *GetMappingHeight)(IMaterial *); // edx
  IMaterialVar *v18; // eax
  IMaterialVar *v19; // eax
  IUniformRandomStream *v20; // ecx
  double v21; // st7
  float v22; // xmm0_4
  float v23; // xmm1_4
  IMaterialVar *(__thiscall *FindVarFast)(IMaterial *, const char *, unsigned int *); // eax
  int v25; // eax
  IMaterialVar *v26; // eax
  float v27; // xmm0_4
  int (__thiscall *v28)(IMaterial *); // eax
  float v29; // xmm0_4
  color32_s v30; // eax
  decalinfo_t decalInfo; // [esp+20h] [ebp-8Ch] BYREF
  float variation; // [esp+A8h] [ebp-4h]
  float scale; // [esp+B8h] [ebp+Ch]

  v11 = flags;
  decalInfo.m_Position.x = position->x;
  decalInfo.m_Position.y = position->y;
  z = position->z;
  memset(&decalInfo.m_aApplySurfs, 0, sizeof(decalInfo.m_aApplySurfs));
  decalInfo.m_Position.z = z;
  if ( model != nullptr && model->type == mod_brush && pMaterial != nullptr )
  {
    pShared = model->brush.pShared;
    decalInfo.m_pModel = model;
    decalInfo.m_pBrush = pShared;
    if ( saxis != nullptr )
    {
      decalInfo.m_SAxis = *saxis;
      v11 = flags | 0x80;
    }
    v14 = pMaterial->__vftable;
    decalInfo.m_pUserData = userdata;
    decalInfo.m_Entity = entity;
    GetMappingWidth = v14->GetMappingWidth;
    decalInfo.m_pMaterial = pMaterial;
    decalInfo.m_Flags = v11;
    v16 = ((int (__thiscall *)(IMaterial *, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))GetMappingWidth)(
            a1: pMaterial,
            a2: a5,
            a3: a4,
            a4: LODWORD(decalInfo.m_Position.x),
            a5: LODWORD(decalInfo.m_Position.y),
            a6: LODWORD(decalInfo.m_Position.z),
            a7: LODWORD(decalInfo.m_SAxis.x),
            a8: LODWORD(decalInfo.m_SAxis.y),
            a9: LODWORD(decalInfo.m_SAxis.z));
    GetMappingHeight = pMaterial->GetMappingHeight;
    decalInfo.m_Size = (float)(v16 >> 1);
    if ( (float)(GetMappingHeight(this: pMaterial) >> 1) > decalInfo.m_Size )
      decalInfo.m_Size = (float)(pMaterial->GetMappingHeight(this: pMaterial) >> 1);
    scale = 1.0;
    v18 = decalInfo.m_pMaterial->FindVarFast(this: decalInfo.m_pMaterial, a2: "$decalScale", a3: &s_DecalScaleVarCache);
    if ( v18 != nullptr )
      scale = v18->GetFloatValueInternal(this: v18);
    v19 = decalInfo.m_pMaterial->FindVarFast(
            this: decalInfo.m_pMaterial,
            a2: "$decalScaleVariation",
            a3: &s_DecalScaleVariationVarCache);
    if ( v19 != nullptr )
    {
      v21 = ((double (__thiscall *)(IMaterialVar *))v19->GetFloatValueInternal)(a1: v19);
      variation = v21;
      if ( v21 >= 0.0 )
      {
        v22 = variation;
        if ( variation > 0.99000001 )
          v22 = 0.99000001;
      }
      else
      {
        v22 = 0.0;
      }
      variation = v22;
      scale = (_RandomFloat(this: v20, a2: COERCE_FLOAT(LODWORD(v22) ^ _mask__NegFloat_), a3: v22) + 1.0) * scale;
    }
    v23 = 1.0;
    if ( scale != 1.0 && scale != 0.0 )
    {
      v23 = 1.0 / scale;
      decalInfo.m_Size = scale * decalInfo.m_Size;
    }
    FindVarFast = pMaterial->FindVarFast;
    decalInfo.m_scale = v23;
    decalInfo.m_flFadeDuration = 0.0;
    v25 = (int)FindVarFast(this: pMaterial, a2: "$decalFadeDuration", a3: &s_DecalFadeVarCache_0);
    if ( v25 != 0 )
    {
      decalInfo.m_flFadeDuration = ((double (__thiscall *)(int))*(_DWORD *)(*(_DWORD *)v25 + 112))(a1: v25);
      v26 = pMaterial->FindVarFast(this: pMaterial, a2: "$decalFadeTime", a3: &s_DecalFadeTimeVarCache);
      if ( v26 != nullptr )
        decalInfo.m_flFadeStartTime = v26->GetFloatValueInternal(this: v26);
      else
        decalInfo.m_flFadeStartTime = 0.0;
    }
    if ( pMaterial->FindVarFast(this: pMaterial, a2: "$decalSecondPass", a3: &s_DecalSecondPassVarCache) != nullptr )
      decalInfo.m_Flags |= 0x200u;
    v27 = (float)pMaterial->GetMappingWidth(this: pMaterial) / decalInfo.m_scale;
    v28 = pMaterial->GetMappingHeight;
    decalInfo.m_decalWidth = (int)v27;
    v29 = (float)v28(this: pMaterial) / decalInfo.m_scale;
    v30 = *rgbaColor;
    decalInfo.m_decalHeight = (int)v29;
    decalInfo.m_pNormal = pNormal;
    decalInfo.m_Color = v30;
    CUtlVector<msurface2_t *,CUtlMemory<msurface2_t *,int>>::Purge(this: &decalInfo.m_aApplySurfs);
    DispInfo_ClearAllTags(hArray: decalInfo.m_pBrush->hDispInfos);
    R_DecalNode(node: &decalInfo.m_pBrush->nodes[decalInfo.m_pModel->brush.firstnode], decalinfo: &decalInfo);
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&decalInfo.m_aApplySurfs);
}

//------------------------------------------------------------------------------
// Address: 0x10105DB0
// Name: void R_DecalShoot(int,int,struct model_t const __near *,class Vector const __near &,class Vector const __near *,int,struct color32_s const __near &,class Vector const __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall R_DecalShoot(
        int a1@<ebx>,
        int a2@<edi>,
        int textureIndex,
        int entity,
        model_t *model,
        const Vector *position,
        const Vector *saxis,
        int flags,
        const color32_s *rgbaColor,
        const Vector *pNormal)
{
  IMaterial *v10; // eax

  v10 = Draw_DecalMaterial(index: textureIndex);
  R_DecalShoot_(
    pMaterial: v10,
    position,
    saxis,
    a4: a1,
    a5: a2,
    entity,
    model,
    flags,
    rgbaColor,
    pNormal,
    userdata: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10105DF0
// Name: void R_PlayerDecalShoot(class IMaterial __near *,void __near *,int,struct model_t const __near *,class Vector const __near &,class Vector const __near *,int,struct color32_s const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_PlayerDecalShoot(
        IMaterial *material,
        void *userdata,
        int entity,
        model_t *model,
        const Vector *position,
        const Vector *saxis,
        int flags,
        const color32_s *rgbaColor)
{
  int v8; // eax
  decal_t **m_pMemory; // ebx
  int m_nAllocationCount; // edx
  int m_Size; // esi
  decal_t *v12; // ecx
  int v13; // edi
  decal_t **v14; // edi
  int j; // edi
  CUtlVector<decal_t *,CUtlMemory<decal_t *,int> > decalVec; // [esp+Ch] [ebp-1Ch] BYREF
  int i; // [esp+20h] [ebp-8h]
  decal_t *decal; // [esp+24h] [ebp-4h]

  v8 = 0;
  m_pMemory = nullptr;
  m_nAllocationCount = 0;
  m_Size = 0;
  memset(&decalVec, 0, sizeof(decalVec));
  i = 0;
  if ( s_aDecalPool.m_Size > 0 )
  {
    while ( 1 )
    {
      v12 = s_aDecalPool.m_Memory.m_pMemory[v8];
      decal = v12;
      if ( v12 != nullptr && (v12->flags & 0x1000) != 0 && v12->userdata == userdata )
      {
        v13 = m_Size;
        if ( m_Size + 1 > m_nAllocationCount )
        {
          CUtlMemory<INetMessage *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)&decalVec,
            num: m_Size - m_nAllocationCount + 1);
          m_Size = decalVec.m_Size;
          m_pMemory = decalVec.m_Memory.m_pMemory;
          v12 = decal;
        }
        decalVec.m_Size = ++m_Size;
        decalVec.m_pElements = m_pMemory;
        if ( m_Size - v13 - 1 > 0 )
        {
          _V_memmove(dest: &m_pMemory[v13 + 1], src: &m_pMemory[v13], count: 4 * (m_Size - v13 - 1));
          v12 = decal;
        }
        v14 = &m_pMemory[v13];
        if ( v14 != nullptr )
          *v14 = v12;
      }
      v8 = i + 1;
      i = v8;
      if ( v8 >= s_aDecalPool.m_Size )
        break;
      m_nAllocationCount = decalVec.m_Memory.m_nAllocationCount;
    }
  }
  for ( j = 0; j < m_Size; ++j )
    R_DecalUnlink(pdecal: m_pMemory[j]);
  R_DecalShoot_(
    pMaterial: material,
    position,
    saxis,
    a4: (int)m_pMemory,
    a5: j,
    entity,
    model,
    flags: flags | 0x1000,
    rgbaColor,
    pNormal: nullptr,
    userdata);
  if ( decalVec.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

} // namespace engine_xlsp
