// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/clientleafsystem.cpp
// Functions: 181
// ============================================================

#include "game\client\clientleafsystem.h"

//------------------------------------------------------------------------------
// Address: 0x100A6280
// Name: public: virtual void CClientLeafSystem::DrawStaticProps(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::DrawStaticProps(CClientLeafSystem *this, bool enable)
{
  this->m_DrawStaticProps = enable;
}

//------------------------------------------------------------------------------
// Address: 0x100A6290
// Name: public: virtual void CClientLeafSystem::DrawSmallEntities(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::DrawSmallEntities(CClientLeafSystem *this, bool enable)
{
  this->m_DrawSmallObjects = enable;
}

//------------------------------------------------------------------------------
// Address: 0x100A62A0
// Name: public: virtual void CClientLeafSystem::DisableLeafReinsertion(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::DisableLeafReinsertion(CClientLeafSystem *this, bool bDisable)
{
  this->m_bDisableLeafReinsertion = bDisable;
}

//------------------------------------------------------------------------------
// Address: 0x100A62B0
// Name: public: virtual void CClientLeafSystem::PreRender(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::PreRender(CClientLeafSystem *this)
{
  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 1) + 136))(a1: (char *)this - 4);
}

//------------------------------------------------------------------------------
// Address: 0x100A62C0
// Name: public: virtual void CClientLeafSystem::AddRenderable(class IClientRenderable __near *,bool,enum RenderableTranslucencyType_t,enum RenderableModelType_t,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::AddRenderable(
        CClientLeafSystem *this,
        IClientRenderable *pRenderable,
        BOOL bRenderWithViewModels,
        RenderableTranslucencyType_t nType,
        RenderableModelType_t nModelType,
        unsigned int nSplitscreenEnabled)
{
  unsigned __int16 *v7; // eax

  this->CreateRenderableHandle(
    this,
    a2: pRenderable,
    a3: bRenderWithViewModels,
    a4: nType,
    a5: nModelType,
    a6: nSplitscreenEnabled);
  v7 = pRenderable->RenderHandle(this: pRenderable);
  this->RenderableChanged(this, a2: *v7);
}

//------------------------------------------------------------------------------
// Address: 0x100A6300
// Name: public: virtual bool CClientLeafSystem::IsRenderableInPVS(class IClientRenderable __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClientLeafSystem::IsRenderableInPVS(CClientLeafSystem *this, IClientRenderable *pRenderable)
{
  unsigned __int16 *v3; // eax
  int v4; // eax
  int leaves[128]; // [esp+4h] [ebp-200h] BYREF

  v3 = pRenderable->RenderHandle(this: pRenderable);
  v4 = this->GetRenderableLeaves(this, a2: *v3, a3: leaves);
  return v4 != -1 && render->AreAnyLeavesVisible(this: render, a2: leaves, a3: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100A6360
// Name: void AddRenderableToRenderList(class CClientRenderablesList __near &,class IClientRenderable __near *,int,enum RenderGroup_t,int,unsigned char,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddRenderableToRenderList(
        CClientRenderablesList *renderList,
        IClientRenderable *pRenderable,
        unsigned __int16 iLeaf,
        RenderGroup_t group,
        char nModelType,
        unsigned __int8 nAlphaModulation,
        bool bShadowDepthNoCache,
        bool bTwoPass)
{
  int v8; // eax
  CClientRenderablesList::CEntry *v9; // eax

  v8 = renderList->m_RenderGroupCounts[group];
  if ( v8 >= 4096 )
  {
    engine->Con_NPrintf(this: engine, a2: 10, a3: "Warning: overflowed CClientRenderablesList group %d", group);
  }
  else
  {
    v9 = &renderList->m_RenderGroups[group][v8];
    v9->m_pRenderable = pRenderable;
    v9->m_iWorldListInfoLeaf = iLeaf;
    *((_BYTE *)v9 + 7) = nModelType & 0x3F | (((unsigned __int8)(2 * bTwoPass) | bShadowDepthNoCache) << 6);
    v9->m_InstanceData.m_nAlpha = nAlphaModulation;
    ++renderList->m_RenderGroupCounts[group];
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A63E0
// Name: private: int CClientLeafSystem::ExtractStaticProps(int,struct CClientLeafSystem::RenderableInfo_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CClientLeafSystem::ExtractStaticProps(
        CClientLeafSystem *this,
        int nCount,
        CClientLeafSystem::RenderableInfo_t **ppRenderables)
{
  int result; // eax
  int i; // edx
  CClientLeafSystem::RenderableInfo_t *v5; // ecx

  if ( this->m_DrawStaticProps )
    return nCount;
  result = 0;
  for ( i = 0; i < nCount; ++i )
  {
    v5 = ppRenderables[i];
    if ( ((unsigned __int8)v5 & 1) != 0 || (*((_WORD *)v5 + 11) & 0xC000) != 0x8000 )
      ppRenderables[result++] = v5;
    else
      --v5->m_nRenderFrame;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A6440
// Name: private: int CClientLeafSystem::ExtractDisableShadowDepthRenderables(int,struct CClientLeafSystem::RenderableInfo_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CClientLeafSystem::ExtractDisableShadowDepthRenderables(
        CClientLeafSystem *this,
        int nCount,
        CClientLeafSystem::RenderableInfo_t **ppRenderables)
{
  int result; // eax
  int i; // edx
  CClientLeafSystem::RenderableInfo_t *v5; // ecx

  if ( this->m_nDisableShadowDepthCount == 0 )
    return nCount;
  result = 0;
  for ( i = 0; i < nCount; ++i )
  {
    v5 = ppRenderables[i];
    if ( ((unsigned __int8)v5 & 1) != 0 || (*((_BYTE *)v5 + 23) & 1) == 0 )
      ppRenderables[result++] = v5;
    else
      --v5->m_nRenderFrame;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A6490
// Name: private: int CClientLeafSystem::ExtractDisableShadowDepthCacheRenderables(int,struct CClientLeafSystem::RenderableInfo_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CClientLeafSystem::ExtractDisableShadowDepthCacheRenderables(
        CClientLeafSystem *this,
        int nCount,
        CClientLeafSystem::RenderableInfo_t **ppRenderables)
{
  __int64 v3; // rax
  CClientLeafSystem::RenderableInfo_t *v4; // ecx

  v3 = 0;
  if ( nCount > 0 )
  {
    do
    {
      v4 = ppRenderables[HIDWORD(v3)];
      if ( ((unsigned __int8)v4 & 1) != 0 || (*((_WORD *)v4 + 11) & 0x200) != 0 )
      {
        ppRenderables[(_DWORD)v3] = v4;
        LODWORD(v3) = v3 + 1;
      }
      else
      {
        --v4->m_nRenderFrame;
      }
      ++HIDWORD(v3);
    }
    while ( SHIDWORD(v3) < nCount );
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100A64D0
// Name: private: int CClientLeafSystem::ExtractDuplicates(int,int,struct CClientLeafSystem::RenderableInfo_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CClientLeafSystem::ExtractDuplicates(
        CClientLeafSystem *this,
        int nFrameNumber,
        int nCount,
        CClientLeafSystem::RenderableInfo_t **ppRenderables)
{
  int v4; // esi
  int result; // eax
  int v6; // edx
  CClientLeafSystem::RenderableInfo_t *v7; // ecx
  int v8; // ebx
  CClientLeafSystem::RenderableInfo_t *v9; // ecx
  int m_nRenderFrame; // edx
  int v11; // edx
  int v12; // esi
  int i; // edx
  CClientLeafSystem::RenderableInfo_t *v14; // ecx
  int nAlternateSortCount; // [esp+Ch] [ebp-4h]

  v4 = 0;
  result = 0;
  if ( this->m_nAlternateSortCount == 0 )
  {
    v6 = 0;
    if ( nCount <= 0 )
      return result;
    while ( 1 )
    {
      v7 = ppRenderables[v6];
      if ( ((unsigned __int8)v7 & 1) == 0 )
      {
        if ( (*((_BYTE *)v7 + 22) & 9) != 0 || v7->m_nRenderFrame == nFrameNumber )
          goto LABEL_8;
        v7->m_nRenderFrame = nFrameNumber;
      }
      ppRenderables[result++] = v7;
LABEL_8:
      if ( ++v6 >= nCount )
        return result;
    }
  }
  nAlternateSortCount = 0;
  if ( nCount <= 0 )
    return result;
  v8 = nFrameNumber;
  do
  {
    v9 = ppRenderables[v4];
    if ( ((unsigned __int8)v9 & 1) == 0 )
    {
      if ( (*((_BYTE *)v9 + 22) & 4) != 0 )
      {
        m_nRenderFrame = v9->m_nRenderFrame;
        v8 = nFrameNumber;
        ++nAlternateSortCount;
        if ( m_nRenderFrame >= nFrameNumber )
          v11 = m_nRenderFrame + 1;
        else
          v11 = nFrameNumber + 1;
        v9->m_nRenderFrame = v11;
      }
      else
      {
        if ( v9->m_nRenderFrame == v8 )
          goto LABEL_21;
        v9->m_nRenderFrame = v8;
      }
    }
    ppRenderables[result++] = v9;
LABEL_21:
    ++v4;
  }
  while ( v4 < nCount );
  if ( nAlternateSortCount != 0 )
  {
    v12 = result;
    result = 0;
    for ( i = 0; i < v12; ++i )
    {
      v14 = ppRenderables[i];
      if ( ((unsigned __int8)v14 & 1) == 0 && (*((_BYTE *)v14 + 22) & 4) != 0 && --v14->m_nRenderFrame != v8 )
        continue;
      ppRenderables[result++] = v14;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A65A0
// Name: private: int CClientLeafSystem::ExtractTranslucentRenderables(int,struct CClientLeafSystem::RenderableInfo_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CClientLeafSystem::ExtractTranslucentRenderables(
        CClientLeafSystem *this,
        int nCount,
        CClientLeafSystem::RenderableInfo_t **ppRenderables)
{
  __int64 v3; // rax
  CClientLeafSystem::RenderableInfo_t *v4; // ecx

  v3 = 0;
  if ( nCount > 0 )
  {
    do
    {
      v4 = ppRenderables[HIDWORD(v3)];
      if ( ((unsigned __int8)v4 & 1) != 0 || (*((_WORD *)v4 + 11) & 0x3000) != 0x1000 )
      {
        ppRenderables[(_DWORD)v3] = v4;
        LODWORD(v3) = v3 + 1;
      }
      else
      {
        --v4->m_nRenderFrame;
      }
      ++HIDWORD(v3);
    }
    while ( SHIDWORD(v3) < nCount );
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100A65F0
// Name: public: virtual class IClientAlphaProperty __near * CClientLeafSystem::CreateClientAlphaProperty(class IClientUnknown __near *)
// Source: json
//------------------------------------------------------------------------------
CTraceFilterSimple *__thiscall CClientLeafSystem::CreateClientAlphaProperty(
        CClientLeafSystem *this,
        IClientUnknown *pUnk)
{
  CClientAlphaProperty *v2; // eax
  CTraceFilterSimple *v3; // esi

  ++this->m_nAlternateSortCount;
  v2 = (CClientAlphaProperty *)CUtlMemoryPool::Alloc(
                                 this: (CUtlMemoryPool *)&this->m_nDisableShadowDepthCount,
                                 amount: 0x20u);
  v3 = (CTraceFilterSimple *)v2;
  if ( v2 != nullptr )
    CClientAlphaProperty::CClientAlphaProperty(this: v2);
  CSceneTokenProcessor::SetBuffer(this: v3, pPassEntity: pUnk);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100A6630
// Name: public: virtual void CClientLeafSystem::DestroyClientAlphaProperty(class IClientAlphaProperty __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::DestroyClientAlphaProperty(
        CClientLeafSystem *this,
        IClientAlphaProperty *pAlphaProperty)
{
  if ( pAlphaProperty != nullptr )
  {
    CUtlMemoryPool::Free(this: (CUtlMemoryPool *)&this->m_nDisableShadowDepthCount, memBlock: pAlphaProperty);
    if ( this->m_nAlternateSortCount-- == 1 )
      CUtlMemoryPool::Clear(this: (CUtlMemoryPool *)&this->m_nDisableShadowDepthCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A6670
// Name: private: void CClientLeafSystem::SortEntities(class Vector const __near &,class Vector const __near &,struct CClientRenderablesList::CEntry __near *,struct CClientLeafSystem::BuildRenderListInfo_t __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::SortEntities(
        CClientLeafSystem *this,
        const Vector *vecRenderOrigin,
        const Vector *vecRenderForward,
        CClientRenderablesList::CEntry *pEntities,
        CClientLeafSystem::BuildRenderListInfo_t **pTranslucentRLInfo,
        int nEntities)
{
  int v6; // esi
  int v8; // edx
  float x; // xmm4_4
  float y; // xmm5_4
  float z; // xmm6_4
  float v12; // xmm7_4
  CClientLeafSystem::BuildRenderListInfo_t **v13; // eax
  float *v14; // ecx
  float v15; // xmm3_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float *v18; // ecx
  float v19; // xmm3_4
  float v20; // xmm2_4
  float v21; // xmm1_4
  float v22; // xmm3_4
  float *v23; // ecx
  float v24; // xmm3_4
  float v25; // xmm2_4
  float v26; // xmm1_4
  float v27; // xmm3_4
  float *v28; // ecx
  float v29; // xmm3_4
  float v30; // xmm2_4
  float v31; // xmm1_4
  float v32; // xmm4_4
  float v33; // xmm5_4
  float v34; // xmm6_4
  CClientLeafSystem::BuildRenderListInfo_t **v35; // ecx
  int v36; // esi
  int v37; // edi
  int v38; // eax
  float v39; // xmm0_4
  int v40; // edx
  float *v41; // esi
  float v42; // ebx
  IClientRenderable *m_pRenderable; // edi
  int v44; // [esp+4h] [ebp-4014h] BYREF
  float v45[4097]; // [esp+8h] [ebp-4010h] BYREF
  float v46; // [esp+400Ch] [ebp-Ch]
  float v47; // [esp+4014h] [ebp-4h]
  float v48; // [esp+4020h] [ebp+8h]
  int v49; // [esp+4020h] [ebp+8h]
  float v50; // [esp+4024h] [ebp+Ch]
  float v51; // [esp+4024h] [ebp+Ch]
  int i; // [esp+4024h] [ebp+Ch]
  int v53; // [esp+402Ch] [ebp+14h]

  v6 = nEntities;
  if ( nEntities > 1 )
  {
    v8 = 0;
    if ( nEntities >= 4 )
    {
      x = vecRenderOrigin->x;
      y = vecRenderOrigin->y;
      z = vecRenderOrigin->z;
      v12 = vecRenderForward->y;
      v50 = vecRenderForward->x;
      v47 = vecRenderForward->z;
      v13 = pTranslucentRLInfo + 2;
      do
      {
        v14 = (float *)*(v13 - 2);
        v15 = v14[2] + v14[5];
        v16 = v14[1] + v14[4];
        v17 = *v14 + v14[3];
        v18 = (float *)*(v13 - 1);
        v46 = (float)(v15 * 0.5) - z;
        v19 = (float)((float)(v12 * (float)((float)(v16 * 0.5) - y)) + (float)(v50 * (float)((float)(v17 * 0.5) - x)))
            + (float)(v47 * v46);
        v20 = v18[1] + v18[4];
        v21 = *v18 + v18[3];
        v45[v8 - 1] = v19;
        v22 = v18[2] + v18[5];
        v23 = (float *)*v13;
        v46 = (float)(v22 * 0.5) - z;
        v24 = (float)(v12 * (float)((float)(v20 * 0.5) - y)) + (float)(v50 * (float)((float)(v21 * 0.5) - x));
        v25 = v23[1] + v23[4];
        v26 = *v23 + v23[3];
        v45[v8] = v24 + (float)(v47 * v46);
        v27 = v23[2] + v23[5];
        v28 = (float *)v13[1];
        v46 = (float)(v27 * 0.5) - z;
        v29 = (float)(v12 * (float)((float)(v25 * 0.5) - y)) + (float)(v50 * (float)((float)(v26 * 0.5) - x));
        v30 = v28[1] + v28[4];
        v31 = *v28 + v28[3];
        *(float *)((char *)v13 + (char *)&v44 - (char *)pTranslucentRLInfo) = v29 + (float)(v47 * v46);
        v46 = (float)((float)(v28[2] + v28[5]) * 0.5) - z;
        *(float *)((char *)v13 + (char *)v45 - (char *)pTranslucentRLInfo) = (float)((float)(v12
                                                                                           * (float)((float)(v30 * 0.5) - y))
                                                                                   + (float)(v50
                                                                                           * (float)((float)(v31 * 0.5) - x)))
                                                                           + (float)(v47 * v46);
        v8 += 4;
        v13 += 4;
      }
      while ( v8 < nEntities - 3 );
      v6 = nEntities;
    }
    if ( v8 < v6 )
    {
      v32 = vecRenderOrigin->x;
      v33 = vecRenderOrigin->y;
      v34 = vecRenderOrigin->z;
      v48 = vecRenderForward->y;
      v51 = vecRenderForward->x;
      v47 = vecRenderForward->z;
      v35 = &pTranslucentRLInfo[v8];
      v36 = v6 - v8;
      do
      {
        *(float *)((char *)v35 + (char *)&v44 - (char *)pTranslucentRLInfo) = (float)((float)(v48
                                                                                            * (float)((float)((float)((*v35)->m_vecMins.y + (*v35)->m_vecMaxs.y) * 0.5) - v33))
                                                                                    + (float)(v51
                                                                                            * (float)((float)((float)((*v35)->m_vecMins.x + (*v35)->m_vecMaxs.x) * 0.5) - v32)))
                                                                            + (float)(v47
                                                                                    * (float)((float)((float)((*v35)->m_vecMins.z + (*v35)->m_vecMaxs.z) * 0.5)
                                                                                            - v34));
        ++v35;
        --v36;
      }
      while ( v36 != 0 );
    }
    v37 = 4;
    v49 = 4;
    do
    {
      v53 = -v37;
      v38 = 0;
      for ( i = nEntities - v37; v38 < i; v38 += v37 )
      {
        v39 = v45[v38 - 1];
        v40 = v37 + v38;
        v41 = &v45[v37 - 1 + v38];
        if ( v39 > *v41 )
        {
          v42 = *(float *)&pEntities[v38].m_iWorldListInfoLeaf;
          m_pRenderable = pEntities[v38].m_pRenderable;
          v45[v38 - 1] = *v41;
          v47 = v42;
          pEntities[v38] = pEntities[v40];
          pEntities[v40].m_pRenderable = m_pRenderable;
          *(float *)&pEntities[v40].m_iWorldListInfoLeaf = v47;
          v37 = v49;
          *v41 = v39;
          if ( v38 != 0 )
            v38 -= 2 * v49;
          else
            v38 = v53;
        }
      }
      v37 >>= 1;
      v49 = v37;
    }
    while ( v37 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A69F0
// Name: float ComputeScreenSize(class Vector const __near &,float,struct ScreenSizeComputeInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl ComputeScreenSize(const Vector *vecOrigin, float flRadius, const ScreenSizeComputeInfo_t *info)
{
  float v3; // xmm1_4
  float v4; // xmm3_4
  float v5; // xmm7_4
  float v6; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm6_4
  float v9; // xmm2_4
  float v10; // xmm0_4

  v5 = info->m_matViewProj.m[3][2];
  v6 = (float)((float)((float)(info->m_matViewProj.m[3][0] * info->m_vecViewUp.x)
                     + (float)(info->m_matViewProj.m[3][1] * info->m_vecViewUp.y))
             + (float)(v5 * info->m_vecViewUp.z))
     * flRadius;
  v7 = (float)((float)((float)(info->m_matViewProj.m[3][0] * vecOrigin->x)
                     + (float)(info->m_matViewProj.m[3][1] * vecOrigin->y))
             + (float)(v5 * vecOrigin->z))
     + info->m_matViewProj.m[3][3];
  if ( (float)(v6 + v7) < 0.001 )
    v8 = 1000.0;
  else
    v8 = 1.0 / (float)(v6 + v7);
  v9 = v7 - v6;
  if ( v9 < 0.001 )
    v10 = 1000.0;
  else
    v10 = 1.0 / v9;
  v3 = (float)((float)((float)(vecOrigin->x * info->m_matViewProj.m[1][0])
                     + (float)(vecOrigin->y * info->m_matViewProj.m[1][1]))
             + (float)(vecOrigin->z * info->m_matViewProj.m[1][2]))
     + info->m_matViewProj.m[1][3];
  v4 = (float)((float)((float)(info->m_vecViewUp.x * info->m_matViewProj.m[1][0])
                     + (float)(info->m_vecViewUp.y * info->m_matViewProj.m[1][1]))
             + (float)(info->m_vecViewUp.z * info->m_matViewProj.m[1][2]))
     * flRadius;
  return fabs(v10 * (float)(v3 - v4) - (float)(v8 * (float)(v4 + v3))) * (double)info->m_nViewportHeight * 0.5;
}

//------------------------------------------------------------------------------
// Address: 0x100A6B20
// Name: private: void CClientLeafSystem::ComputeScreenFade(struct ScreenSizeComputeInfo_t const __near &,float,float,int,struct CClientLeafSystem::AlphaInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::ComputeScreenFade(
        CClientLeafSystem *this,
        const ScreenSizeComputeInfo_t *info,
        float flMinScreenWidth,
        float flMaxScreenWidth,
        int nCount,
        CClientLeafSystem::AlphaInfo_t *pAlphaInfo)
{
  float v6; // xmm1_4
  float v7; // xmm0_4
  float *p_m_flFadeFactor; // edx
  int i; // esi
  int v10; // eax
  float v11; // xmm0_4
  long double v12; // st5
  float flFalloffFactor; // [esp+10h] [ebp-4h]
  int nCounta; // [esp+28h] [ebp+14h]
  float flPixelWidth; // [esp+2Ch] [ebp+18h]

  v6 = flMaxScreenWidth;
  if ( flMinScreenWidth >= flMaxScreenWidth )
  {
    v6 = flMinScreenWidth;
    flMaxScreenWidth = flMinScreenWidth;
  }
  if ( flMinScreenWidth > 0.0 )
  {
    v7 = v6 == flMinScreenWidth ? 1.0 : 1.0 / (float)(v6 - flMinScreenWidth);
    flFalloffFactor = v7;
    if ( nCount > 0 )
    {
      p_m_flFadeFactor = &pAlphaInfo->m_flFadeFactor;
      for ( i = nCount; i != 0; --i )
      {
        v10 = *((_DWORD *)p_m_flFadeFactor - 5);
        if ( v10 != 0 && *(float *)(v10 + 20) > 0.0 )
        {
          v11 = 0.0;
          nCounta = *(int *)(v10 + 20);
          v12 = ComputeScreenSize(
                  vecOrigin: (const Vector *)(p_m_flFadeFactor - 4),
                  flRadius: *(p_m_flFadeFactor - 1),
                  info)
              / *(float *)&nCounta
              * 2.0;
          if ( v12 > flMinScreenWidth )
          {
            if ( flMaxScreenWidth < 0.0 || (flPixelWidth = v12, flMaxScreenWidth <= flPixelWidth) )
              v11 = 1.0;
            else
              v11 = (float)(flPixelWidth - flMinScreenWidth) * flFalloffFactor;
          }
          if ( v11 > *p_m_flFadeFactor )
            v11 = *p_m_flFadeFactor;
          *p_m_flFadeFactor = v11;
        }
        p_m_flFadeFactor += 6;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A6C20
// Name: private: void CClientLeafSystem::ComputeBounds(int,struct CClientLeafSystem::RenderableInfo_t __near * __near *,struct CClientLeafSystem::BuildRenderListInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::ComputeBounds(
        CClientLeafSystem *this,
        int nCount,
        CClientLeafSystem::RenderableInfo_t **ppRenderables,
        CClientLeafSystem::BuildRenderListInfo_t *pRLInfo)
{
  int v4; // eax
  _BYTE *v5; // esi
  CClientLeafSystem::RenderableInfo_t *v6; // ebx
  __int16 v7; // ax
  bool v8; // al
  __int16 v9; // ax
  int i; // [esp+0h] [ebp-4h]

  v4 = 0;
  i = 0;
  if ( nCount > 0 )
  {
    v5 = (char *)pRLInfo + 27;
    do
    {
      v6 = ppRenderables[v4];
      if ( ((unsigned __int8)v6 & 1) == 0 )
      {
        v7 = *((_WORD *)v6 + 11) >> 14;
        v8 = v7 == 2 || v7 == 1;
        *v5 ^= (v8 ^ *v5) & 1;
        *(_WORD *)(v5 - 3) = v6->m_Area;
        *(v5 - 1) = -1;
        if ( (*((_BYTE *)v6 + 22) & 0x20) == 0 )
        {
          v6->m_pRenderable->GetRenderBoundsWorldspace(
            this: v6->m_pRenderable,
            a2: &v6->m_vecAbsMins,
            a3: &v6->m_vecAbsMaxs);
          v9 = *((_WORD *)v6 + 11);
          if ( (v9 & 0x40) == 0 )
            *((_WORD *)v6 + 11) = v9 | 0x20;
        }
        v4 = i;
        *(float *)(v5 - 27) = v6->m_vecAbsMins.x;
        *(float *)(v5 - 23) = v6->m_vecAbsMins.y;
        *(float *)(v5 - 19) = v6->m_vecAbsMins.z;
        *(float *)(v5 - 15) = v6->m_vecAbsMaxs.x;
        *(float *)(v5 - 11) = v6->m_vecAbsMaxs.y;
        *(float *)(v5 - 7) = v6->m_vecAbsMaxs.z;
      }
      ++v4;
      v5 += 28;
      i = v4;
    }
    while ( v4 < nCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A6CE0
// Name: public: void CUtlMemory<struct CViewModelRenderablesList::CEntry,int>::ConvertToGrowableMemory(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CViewModelRenderablesList::CEntry,int>::ConvertToGrowableMemory(
        CUtlMemory<CViewModelRenderablesList::CEntry,int> *this,
        int nGrowSize)
{
  int m_nAllocationCount; // eax
  unsigned int v4; // edi
  unsigned __int8 *v5; // ebx

  if ( this->m_nGrowSize < 0 )
  {
    this->m_nGrowSize = nGrowSize;
    m_nAllocationCount = this->m_nAllocationCount;
    if ( m_nAllocationCount != 0 )
    {
      v4 = 8 * m_nAllocationCount;
      v5 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 8 * m_nAllocationCount);
      memcpy(dst: v5, src: (unsigned __int8 *)this->m_pMemory, count: v4);
      this->m_pMemory = (CViewModelRenderablesList::CEntry *)v5;
    }
    else
    {
      this->m_pMemory = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A6DE0
// Name: private: static unsigned short __near & CClientLeafSystem::FirstRenderableInLeaf(int)
// Source: json
//------------------------------------------------------------------------------
CClientLeafSystem::ClientLeaf_t *__cdecl CClientLeafSystem::FirstRenderableInLeaf(int leaf)
{
  return &CClientLeafSystem::s_ClientLeafSystem.m_Leaf.m_Memory.m_pMemory[leaf];
}

//------------------------------------------------------------------------------
// Address: 0x100A6E00
// Name: private: static unsigned short __near & CClientLeafSystem::FirstLeafInRenderable(unsigned short)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 *__cdecl CClientLeafSystem::FirstLeafInRenderable(unsigned __int16 renderable)
{
  return &CClientLeafSystem::s_ClientLeafSystem.m_Renderables.m_Memory.m_pMemory[renderable].m_Element.m_LeafList;
}

//------------------------------------------------------------------------------
// Address: 0x100A6E20
// Name: private: static unsigned short __near & CClientLeafSystem::FirstShadowInLeaf(int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 *__cdecl CClientLeafSystem::FirstShadowInLeaf(int leaf)
{
  return &CClientLeafSystem::s_ClientLeafSystem.m_Leaf.m_Memory.m_pMemory[leaf].m_FirstShadow;
}

//------------------------------------------------------------------------------
// Address: 0x100A6E40
// Name: private: static unsigned short __near & CClientLeafSystem::FirstLeafInShadow(unsigned short)
// Source: json
//------------------------------------------------------------------------------
UtlLinkedListElem_t<CClientLeafSystem::ShadowInfo_t,unsigned short> *__cdecl CClientLeafSystem::FirstLeafInShadow(
        unsigned __int16 shadow)
{
  return &CClientLeafSystem::s_ClientLeafSystem.m_Shadows.m_Memory.m_pMemory[shadow];
}

//------------------------------------------------------------------------------
// Address: 0x100A6E60
// Name: private: static unsigned short __near & CClientLeafSystem::FirstShadowOnRenderable(unsigned short)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 *__cdecl CClientLeafSystem::FirstShadowOnRenderable(unsigned __int16 renderable)
{
  return &CClientLeafSystem::s_ClientLeafSystem.m_Renderables.m_Memory.m_pMemory[renderable].m_Element.m_FirstShadow;
}

//------------------------------------------------------------------------------
// Address: 0x100A6E80
// Name: private: static unsigned short __near & CClientLeafSystem::FirstRenderableInShadow(unsigned short)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 *__cdecl CClientLeafSystem::FirstRenderableInShadow(unsigned __int16 shadow)
{
  return &CClientLeafSystem::s_ClientLeafSystem.m_Shadows.m_Memory.m_pMemory[shadow].m_Element.m_FirstRenderable;
}

//------------------------------------------------------------------------------
// Address: 0x100A6EA0
// Name: void CalcRenderableWorldSpaceAABB_Fast(class IClientRenderable __near *,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall CalcRenderableWorldSpaceAABB_Fast(
        float a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        IClientRenderable *pRenderable,
        Vector *absMin,
        Vector *absMax)
{
  int v6; // eax
  C_BaseEntity *v7; // eax
  C_BaseEntity *v8; // esi
  unsigned int v9; // ecx
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  IClientRenderable *v12; // eax
  void (__thiscall *GetRenderBounds)(IClientRenderable *, Vector *, Vector *); // edx
  const Vector *LocalOrigin; // eax
  float v15; // xmm0_4
  __int128 v16; // xmm1
  float v17; // xmm0_4
  float v18; // [esp-30h] [ebp-4Ch]
  float v19; // [esp-20h] [ebp-3Ch]
  __int128 v20; // [esp-10h] [ebp-2Ch] BYREF
  Vector vAddMaxs; // [esp+0h] [ebp-1Ch] BYREF
  Vector vAddMins; // [esp+Ch] [ebp-10h]
  float retaddr; // [esp+1Ch] [ebp+0h]

  vAddMins.y = a1;
  vAddMins.z = retaddr;
  v6 = ((int (__thiscall *)(IClientRenderable *, int, int))pRenderable->GetIClientUnknown)(a1: pRenderable, a2, a3);
  v7 = (C_BaseEntity *)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 28))(a1: v6);
  v8 = v7;
  if ( v7 != nullptr
    && (C_BaseEntity::IsFollowingEntity(this: v7)
     || (v9 = v8->m_pMoveParent.m_Index) != -1
     && g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_SerialNumber == HIWORD(v9)
     && g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_pEntity != nullptr
     && v8->m_iParentAttachment != 0) )
  {
    m_Index = v8->m_pMoveParent.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
    {
      v12 = (IClientRenderable *)&m_pEntity[1];
    }
    else
    {
      v12 = nullptr;
    }
    CalcRenderableWorldSpaceAABB_Fast(pRenderable: v12, absMin, absMax);
    GetRenderBounds = v8->GetRenderBounds;
    LODWORD(vAddMaxs.y) = (char *)&v20 + 4;
    LODWORD(vAddMaxs.x) = &vAddMaxs;
    ((void (__thiscall *)(IClientRenderable *))GetRenderBounds)(a1: &v8->IClientRenderable);
    LocalOrigin = C_BaseEntity::GetLocalOrigin(this: v8);
    v19 = fsqrt(
            (float)((float)(LocalOrigin->x * LocalOrigin->x) + (float)(LocalOrigin->y * LocalOrigin->y))
          + (float)(LocalOrigin->z * LocalOrigin->z));
    vAddMins.x = *((float *)&v20 + 3) * *((float *)&v20 + 3);
    v16 = 0;
    v15 = fsqrt(
            (float)((float)(vAddMaxs.y * vAddMaxs.y) + (float)(vAddMaxs.x * vAddMaxs.x))
          + (float)(vAddMaxs.z * vAddMaxs.z));
    *(float *)&v16 = fsqrt(
                       (float)((float)(*((float *)&v20 + 3) * *((float *)&v20 + 3))
                             + (float)(*((float *)&v20 + 1) * *((float *)&v20 + 1)))
                     + (float)(*((float *)&v20 + 2) * *((float *)&v20 + 2)));
    v20 = v16;
    if ( v15 <= *(float *)&v16 )
      v18 = *(float *)&v16;
    else
      v18 = v15;
    v17 = v18;
    if ( v18 <= v19 )
      v17 = v19;
    absMin->x = absMin->x - v17;
    absMin->y = absMin->y - v17;
    absMin->z = absMin->z - v17;
    absMax->x = absMax->x + v17;
    absMax->y = absMax->y + v17;
    absMax->z = absMax->z + v17;
  }
  else
  {
    ((void (__thiscall *)(IClientRenderable *, Vector *))pRenderable->GetRenderBoundsWorldspace)(
      a1: pRenderable,
      a2: absMin);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A70D0
// Name: private: void CClientLeafSystem::CalcRenderableWorldSpaceAABB_Bloated(struct CClientLeafSystem::RenderableInfo_t const __near &,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::CalcRenderableWorldSpaceAABB_Bloated(
        CClientLeafSystem *this,
        const CClientLeafSystem::RenderableInfo_t *info,
        Vector *absMin,
        Vector *absMax)
{
  __m128 x_low; // xmm0
  __m128 v6; // xmm1
  __m128 v7; // xmm4
  __m128 v8; // xmm2
  __m128 v9; // xmm1
  __m128 v10; // xmm2
  __m128 y_low; // xmm0
  __m128 v12; // xmm1
  __m128 v13; // xmm1
  __m128 v14; // xmm2
  __m128 z_low; // xmm0
  __m128 v16; // xmm4
  __m128 v17; // xmm1
  __m128 v18; // xmm2
  double v19; // st7
  double v20; // st7
  double x; // xmm0_8
  float v22; // xmm0_4
  double y; // xmm0_8
  float v24; // xmm0_4
  double z; // xmm0_8
  float v26; // xmm7_4
  double v27; // xmm0_8
  double v28; // xmm1_8
  float v29; // xmm3_4
  float v30; // xmm1_4
  double v31; // xmm0_8
  double v32; // xmm2_8
  float v33; // xmm0_4
  float v34; // xmm3_4
  float v35; // xmm6_4
  float v36; // xmm0_4
  float vecTempMax_4; // [esp+18h] [ebp-14h]
  float vecTempMin; // [esp+20h] [ebp-Ch]
  float vecTempMin_4; // [esp+24h] [ebp-8h]
  int savedregs; // [esp+2Ch] [ebp+0h] BYREF
  float absMaxa; // [esp+3Ch] [ebp+10h]

  CalcRenderableWorldSpaceAABB_Fast(
    a1: COERCE_FLOAT(&savedregs),
    a2: (int)absMax,
    a3: (int)absMin,
    pRenderable: info->m_pRenderable,
    absMin,
    absMax);
  x_low = (__m128)LODWORD(absMin->x);
  x_low.m128_f32[0] = x_low.m128_f32[0] * 0.03125;
  v6 = _mm_and_ps((__m128)0x80000000, x_low);
  v7.m128_i32[0] = v6.m128_i32[0];
  v8.m128_i32[0] = 1258291200;
  v8.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(x_low, v6), v8).m128_f32[0]) & 0x4B000000
                 | v6.m128_i32[0];
  v9 = x_low;
  v9.m128_f32[0] = (float)(x_low.m128_f32[0] + v8.m128_f32[0]) - v8.m128_f32[0];
  v10 = v9;
  v10.m128_f32[0] = v9.m128_f32[0] - x_low.m128_f32[0];
  y_low = (__m128)LODWORD(absMin->y);
  absMin->x = (float)(v9.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v10, v7).m128_f32[0]) & 0x3F800000))
            * 32.0;
  y_low.m128_f32[0] = y_low.m128_f32[0] * 0.03125;
  v12 = _mm_and_ps((__m128)0x80000000, y_low);
  v7.m128_i32[0] = v12.m128_i32[0];
  v10.m128_i32[0] = 1258291200;
  v10.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(y_low, v12), v10).m128_f32[0]) & 0x4B000000
                  | v12.m128_i32[0];
  v13 = y_low;
  v13.m128_f32[0] = (float)(y_low.m128_f32[0] + v10.m128_f32[0]) - v10.m128_f32[0];
  v14 = v13;
  v14.m128_f32[0] = v13.m128_f32[0] - y_low.m128_f32[0];
  z_low = (__m128)LODWORD(absMin->z);
  absMin->y = (float)(v13.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v14, v7).m128_f32[0]) & 0x3F800000))
            * 32.0;
  z_low.m128_f32[0] = z_low.m128_f32[0] * 0.03125;
  v16 = _mm_and_ps((__m128)0x80000000, z_low);
  v14.m128_i32[0] = 1258291200;
  v14.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(z_low, v16), v14).m128_f32[0]) & 0x4B000000
                  | v16.m128_i32[0];
  v17 = z_low;
  v17.m128_f32[0] = (float)(z_low.m128_f32[0] + v14.m128_f32[0]) - v14.m128_f32[0];
  v18 = v17;
  v18.m128_f32[0] = v17.m128_f32[0] - z_low.m128_f32[0];
  absMin->z = (float)(v17.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v18, v16).m128_u32[0] & 0x3F800000)) * 32.0;
  v19 = ceil(X: (float)(absMax->x * 0.03125));
  z_low.m128_i32[0] = LODWORD(absMax->y);
  absMax->x = v19 * 32.0;
  v20 = ceil(X: (float)(z_low.m128_f32[0] * 0.03125));
  z_low.m128_i32[0] = LODWORD(absMax->z);
  absMax->y = v20 * 32.0;
  absMaxa = ceil(X: (float)(z_low.m128_f32[0] * 0.03125)) * 32.0;
  absMax->z = absMaxa;
  if ( (*((_BYTE *)info + 22) & 0x10) != 0 )
  {
    x = info->m_vecBloatedAbsMins.x;
    if ( x > absMin->x )
      x = absMin->x;
    v22 = x;
    vecTempMin = v22;
    y = info->m_vecBloatedAbsMins.y;
    if ( y > absMin->y )
      y = absMin->y;
    v24 = y;
    vecTempMin_4 = v24;
    z = info->m_vecBloatedAbsMins.z;
    if ( z > absMin->z )
      z = absMin->z;
    v26 = z;
    v27 = info->m_vecBloatedAbsMaxs.x;
    v28 = absMax->x;
    if ( v27 < v28 )
      v27 = v28;
    v29 = absMax->y;
    v30 = v27;
    v31 = info->m_vecBloatedAbsMaxs.y;
    if ( v31 < v29 )
      v31 = v29;
    v32 = info->m_vecBloatedAbsMaxs.z;
    v33 = v31;
    vecTempMax_4 = v33;
    if ( v32 < absMaxa )
      v32 = absMaxa;
    v34 = v29 - absMin->y;
    v35 = v32;
    v36 = (float)((float)((float)(v33 - vecTempMin_4) * (float)(v33 - vecTempMin_4))
                + (float)((float)(v30 - vecTempMin) * (float)(v30 - vecTempMin)))
        + (float)((float)(v35 - v26) * (float)(v35 - v26));
    if ( v36 <= 32768.0
      || (float)((float)((float)((float)(v34 * v34)
                               + (float)((float)(absMax->x - absMin->x) * (float)(absMax->x - absMin->x)))
                       + (float)((float)(absMaxa - absMin->z) * (float)(absMaxa - absMin->z)))
               * 2.0) >= v36 )
    {
      absMin->x = vecTempMin;
      absMin->y = vecTempMin_4;
      absMin->z = v26;
      absMax->x = v30;
      absMax->y = vecTempMax_4;
      absMax->z = v35;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A7400
// Name: public: virtual void CClientLeafSystem::SetTranslucencyType(unsigned short,enum RenderableTranslucencyType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::SetTranslucencyType(
        CClientLeafSystem *this,
        unsigned __int16 handle,
        RenderableTranslucencyType_t nType)
{
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *v3; // eax

  if ( handle != 0xFFFF )
  {
    v3 = &this->m_Renderables.m_Memory.m_pMemory[handle];
    *((_WORD *)&v3->m_Element + 11) ^= (*((_WORD *)&v3->m_Element + 11) ^ ((_WORD)nType << 12)) & 0x3000;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A7440
// Name: public: virtual enum RenderableTranslucencyType_t CClientLeafSystem::GetTranslucencyType(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CClientLeafSystem::GetTranslucencyType(CClientLeafSystem *this, unsigned __int16 handle)
{
  if ( handle == 0xFFFF )
    return 0;
  else
    return (*((unsigned __int16 *)&this->m_Renderables.m_Memory.m_pMemory[handle].m_Element + 11) >> 12) & 3;
}

//------------------------------------------------------------------------------
// Address: 0x100A7470
// Name: public: virtual void CClientLeafSystem::RenderInFastReflections(unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::RenderInFastReflections(
        CClientLeafSystem *this,
        unsigned __int16 handle,
        bool bRenderInFastReflections)
{
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *v3; // eax

  if ( handle != 0xFFFF )
  {
    v3 = &this->m_Renderables.m_Memory.m_pMemory[handle];
    *((_WORD *)&v3->m_Element + 11) = *((_WORD *)&v3->m_Element + 11) & 0xFF7F | (bRenderInFastReflections << 7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A74B0
// Name: public: virtual bool CClientLeafSystem::IsRenderingInFastReflections(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClientLeafSystem::IsRenderingInFastReflections(CClientLeafSystem *this, unsigned __int16 handle)
{
  if ( handle == 0xFFFF )
    return false;
  else
    return *((_BYTE *)&this->m_Renderables.m_Memory.m_pMemory[handle].m_Element + 22) >> 7;
}

//------------------------------------------------------------------------------
// Address: 0x100A74E0
// Name: public: virtual void CClientLeafSystem::DisableShadowDepthRendering(unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::DisableShadowDepthRendering(
        CClientLeafSystem *this,
        unsigned __int16 handle,
        bool bDisable)
{
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *v3; // eax

  if ( handle != 0xFFFF )
  {
    v3 = &this->m_Renderables.m_Memory.m_pMemory[handle];
    if ( bDisable != (HIBYTE(*((_WORD *)&v3->m_Element + 11)) & 1) )
    {
      *((_WORD *)&v3->m_Element + 11) = *((_WORD *)&v3->m_Element + 11) & 0xFEFF | (bDisable << 8);
      this->m_nDisableShadowDepthCount += 2 * bDisable - 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A7550
// Name: public: virtual void CClientLeafSystem::DisableShadowDepthCaching(unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::DisableShadowDepthCaching(
        CClientLeafSystem *this,
        unsigned __int16 handle,
        bool bDisable)
{
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *v3; // eax

  if ( handle != 0xFFFF )
  {
    v3 = &this->m_Renderables.m_Memory.m_pMemory[handle];
    if ( bDisable != ((*((_WORD *)&v3->m_Element + 11) & 0x200) != 0) )
    {
      *((_WORD *)&v3->m_Element + 11) = *((_WORD *)&v3->m_Element + 11) & 0xFDFF | (bDisable << 9);
      this->m_nDisableShadowDepthCacheCount += 2 * bDisable - 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A75C0
// Name: public: virtual void CClientLeafSystem::EnableSplitscreenRendering(unsigned short,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::EnableSplitscreenRendering(
        CClientLeafSystem *this,
        unsigned __int16 handle,
        __int16 nFlags)
{
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *v3; // eax

  if ( handle != 0xFFFF )
  {
    v3 = &this->m_Renderables.m_Memory.m_pMemory[handle];
    *((_WORD *)&v3->m_Element + 11) ^= (*((_WORD *)&v3->m_Element + 11) ^ (nFlags << 10)) & 0xC00;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A7600
// Name: public: virtual void CClientLeafSystem::SetModelType(unsigned short,enum RenderableModelType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::SetModelType(CClientLeafSystem *this, int handle, RenderableModelType_t nModelType)
{
  RenderableModelType_t v4; // eax
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *v5; // esi
  IVModelInfoClient_vtbl *v6; // edi
  int v7; // eax
  int v8; // eax

  if ( (_WORD)handle != 0xFFFF )
  {
    v4 = nModelType;
    v5 = &this->m_Renderables.m_Memory.m_pMemory[(unsigned __int16)handle];
    if ( nModelType == RENDERABLE_MODEL_UNKNOWN_TYPE )
    {
      v6 = modelinfo->__vftable;
      v7 = (int)v5->m_Element.m_pRenderable->GetModel(this: v5->m_Element.m_pRenderable);
      v8 = v6->GetModelType(this: modelinfo, a2: (const struct model_t *)v7) - 1;
      if ( v8 != 0 )
        v4 = v8 == 2;
      else
        v4 = RENDERABLE_MODEL_BRUSH;
    }
    if ( *((unsigned __int16 *)&v5->m_Element + 11) >> 14 != v4 )
    {
      *((_WORD *)&v5->m_Element + 11) = ((_WORD)v4 << 14) | *((_WORD *)&v5->m_Element + 11) & 0x3FFF;
      this->RenderableChanged(this, a2: handle);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A7690
// Name: public: virtual void CClientLeafSystem::EnableRendering(unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::EnableRendering(CClientLeafSystem *this, unsigned __int16 handle, bool bEnable)
{
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *v3; // eax

  if ( handle != 0xFFFF )
  {
    v3 = &this->m_Renderables.m_Memory.m_pMemory[handle];
    if ( bEnable )
      *((_WORD *)&v3->m_Element + 11) &= ~1u;
    else
      *((_WORD *)&v3->m_Element + 11) |= 1u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A76D0
// Name: public: virtual void CClientLeafSystem::EnableBloatedBounds(unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::EnableBloatedBounds(CClientLeafSystem *this, int handle, bool bEnable)
{
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *v3; // eax
  __int16 v4; // dx

  if ( (_WORD)handle != 0xFFFF )
  {
    v3 = &this->m_Renderables.m_Memory.m_pMemory[(unsigned __int16)handle];
    if ( bEnable )
    {
      *((_WORD *)&v3->m_Element + 11) |= 0x10u;
    }
    else
    {
      v4 = *((_WORD *)&v3->m_Element + 11);
      if ( (v4 & 0x10) != 0 )
      {
        *((_WORD *)&v3->m_Element + 11) = v4 & 0xFFEF;
        this->RenderableChanged(this, a2: handle);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A7720
// Name: public: virtual void CClientLeafSystem::DisableCachedRenderBounds(unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::DisableCachedRenderBounds(
        CClientLeafSystem *this,
        unsigned __int16 handle,
        bool bDisable)
{
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *v3; // eax

  if ( handle != 0xFFFF )
  {
    v3 = &this->m_Renderables.m_Memory.m_pMemory[handle];
    if ( bDisable )
      *((_WORD *)&v3->m_Element + 11) |= 0x40u;
    else
      *((_WORD *)&v3->m_Element + 11) &= ~0x40u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A7760
// Name: public: virtual void CClientLeafSystem::EnableAlternateSorting(unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::EnableAlternateSorting(
        CClientLeafSystem *this,
        unsigned __int16 handle,
        bool bEnable)
{
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *v3; // eax

  v3 = &this->m_Renderables.m_Memory.m_pMemory[handle];
  if ( bEnable )
  {
    if ( (*((_BYTE *)&v3->m_Element + 22) & 4) == 0 )
    {
      ++this->m_nAlternateSortCount;
      *((_WORD *)&v3->m_Element + 11) |= 4u;
    }
  }
  else if ( (*((_BYTE *)&v3->m_Element + 22) & 4) != 0 )
  {
    --this->m_nAlternateSortCount;
    *((_WORD *)&v3->m_Element + 11) &= ~4u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A77B0
// Name: public: virtual bool CClientLeafSystem::IsRenderingWithViewModels(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClientLeafSystem::IsRenderingWithViewModels(CClientLeafSystem *this, unsigned __int16 handle)
{
  return handle != 0xFFFF && (*((_WORD *)&this->m_Renderables.m_Memory.m_pMemory[handle].m_Element + 11) & 8) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100A77E0
// Name: public: virtual void CClientLeafSystem::SetSubSystemDataInLeaf(int,int,class CClientLeafSubSystemData __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::SetSubSystemDataInLeaf(
        CClientLeafSystem *this,
        int leaf,
        int nSubSystemIdx,
        CClientLeafSubSystemData *pData)
{
  CClientLeafSystem::ClientLeaf_t *m_pMemory; // edx
  int v6; // edi
  void (__thiscall ***v7)(_DWORD, int); // eax

  m_pMemory = this->m_Leaf.m_Memory.m_pMemory;
  v6 = 4 * (nSubSystemIdx + 4 * leaf) + 12;
  if ( *(_DWORD *)((char *)&m_pMemory->m_FirstElement + v6) != 0 )
  {
    v7 = *(void (__thiscall ****)(_DWORD, int))((char *)&m_pMemory->m_FirstElement + v6);
    if ( v7 != nullptr )
    {
      (**v7)(a1: v7, a2: 1);
      *(_DWORD *)((char *)&this->m_Leaf.m_Memory.m_pMemory->m_FirstElement + v6) = pData;
    }
    else
    {
      *(_DWORD *)((char *)&m_pMemory->m_FirstElement + v6) = pData;
    }
  }
  else
  {
    *(_DWORD *)((char *)&m_pMemory->m_FirstElement + v6) = pData;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A7840
// Name: public: virtual class CClientLeafSubSystemData __near * CClientLeafSystem::GetSubSystemDataInLeaf(int,int)
// Source: json
//------------------------------------------------------------------------------
CClientLeafSubSystemData *__thiscall CClientLeafSystem::GetSubSystemDataInLeaf(
        CClientLeafSystem *this,
        int leaf,
        int nSubSystemIdx)
{
  return this->m_Leaf.m_Memory.m_pMemory[leaf].m_pSubSystemData[nSubSystemIdx];
}

//------------------------------------------------------------------------------
// Address: 0x100A7860
// Name: public: virtual void CClientLeafSystem::SetDetailObjectsInLeaf(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::SetDetailObjectsInLeaf(
        CClientLeafSystem *this,
        int leaf,
        unsigned __int16 firstDetailObject,
        int detailObjectCount)
{
  int v4; // eax

  v4 = leaf;
  this->m_Leaf.m_Memory.m_pMemory[v4].m_FirstDetailProp = firstDetailObject;
  this->m_Leaf.m_Memory.m_pMemory[v4].m_DetailPropCount = detailObjectCount;
  if ( detailObjectCount != 0 )
    engine->SetLeafFlag(this: engine, a2: leaf, a3: 8);
}

//------------------------------------------------------------------------------
// Address: 0x100A78A0
// Name: public: virtual void CClientLeafSystem::GetDetailObjectsInLeaf(int,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::GetDetailObjectsInLeaf(
        CClientLeafSystem *this,
        int leaf,
        int *firstDetailObject,
        int *detailObjectCount)
{
  *firstDetailObject = this->m_Leaf.m_Memory.m_pMemory[leaf].m_FirstDetailProp;
  *detailObjectCount = this->m_Leaf.m_Memory.m_pMemory[leaf].m_DetailPropCount;
}

//------------------------------------------------------------------------------
// Address: 0x100A78D0
// Name: public: virtual void CClientLeafSystem::DrawDetailObjectsInLeaf(int,int,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::DrawDetailObjectsInLeaf(
        CClientLeafSystem *this,
        int leaf,
        int nFrameNumber,
        int *nFirstDetailObject,
        int *nDetailObjectCount)
{
  CClientLeafSystem::ClientLeaf_t *v5; // eax
  int m_FirstDetailProp; // edx

  v5 = &this->m_Leaf.m_Memory.m_pMemory[leaf];
  m_FirstDetailProp = v5->m_FirstDetailProp;
  v5->m_DetailPropRenderFrame = nFrameNumber;
  *nFirstDetailObject = m_FirstDetailProp;
  *nDetailObjectCount = v5->m_DetailPropCount;
}

//------------------------------------------------------------------------------
// Address: 0x100A7900
// Name: public: virtual bool CClientLeafSystem::ShouldDrawDetailObjectsInLeaf(int,int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CClientLeafSystem::ShouldDrawDetailObjectsInLeaf(CClientLeafSystem *this, int leaf, int frameNumber)
{
  CClientLeafSystem::ClientLeaf_t *v3; // eax

  v3 = &this->m_Leaf.m_Memory.m_pMemory[leaf];
  return v3->m_DetailPropRenderFrame == frameNumber
      && (v3->m_DetailPropCount != 0 || v3->m_pSubSystemData[0] != nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100A7930
// Name: private: void CClientLeafSystem::ComputeDistanceFade(int,struct CClientLeafSystem::AlphaInfo_t __near *,struct CClientLeafSystem::BuildRenderListInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::ComputeDistanceFade(
        CClientLeafSystem *this,
        int nCount,
        CClientLeafSystem::AlphaInfo_t *pAlphaInfo,
        CClientLeafSystem::BuildRenderListInfo_t *pRLInfo)
{
  C_BasePlayer *LocalPlayer; // eax
  double FOVDistanceAdjustFactor; // st7
  float *p_z; // esi
  _WORD *v8; // edi
  float v9; // xmm0_4
  double v10; // st7
  float v11; // xmm2_4
  float v12; // xmm1_4
  Vector vecViewOrigin; // [esp+0h] [ebp-10h] BYREF
  float flDistFactorSq; // [esp+Ch] [ebp-4h]
  float flCurrentDistanceSq; // [esp+20h] [ebp+10h]

  flDistFactorSq = 1.0;
  vecViewOrigin = *CurrentViewOrigin();
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
  {
    FOVDistanceAdjustFactor = C_BasePlayer::GetFOVDistanceAdjustFactor(this: LocalPlayer);
    flDistFactorSq = FOVDistanceAdjustFactor * FOVDistanceAdjustFactor;
  }
  if ( nCount > 0 )
  {
    p_z = &pAlphaInfo->m_vecCenter.z;
    do
    {
      v8 = *((_WORD **)p_z - 3);
      if ( v8 != nullptr && v8[9] != 0 )
      {
        if ( (v8[5] & 0x800) != 0 )
        {
          v10 = CalcSqrDistanceToAABB(mins: &pRLInfo->m_vecMins, maxs: &pRLInfo->m_vecMaxs, point: &vecViewOrigin);
          flCurrentDistanceSq = v10 * flDistFactorSq;
          v9 = flCurrentDistanceSq;
        }
        else
        {
          v9 = (float)((float)((float)((float)(vecViewOrigin.y - *(p_z - 1)) * (float)(vecViewOrigin.y - *(p_z - 1)))
                             + (float)((float)(vecViewOrigin.x - *(p_z - 2)) * (float)(vecViewOrigin.x - *(p_z - 2))))
                     + (float)((float)(vecViewOrigin.z - *p_z) * (float)(vecViewOrigin.z - *p_z)))
             * flDistFactorSq;
        }
        v11 = (float)(unsigned __int16)v8[8] * (float)(unsigned __int16)v8[8];
        if ( v11 < v9 )
        {
          v12 = (float)(unsigned __int16)v8[9] * (float)(unsigned __int16)v8[9];
          if ( v9 < v12 )
            p_z[2] = (float)(v12 - v9) / (float)(v12 - v11);
          else
            p_z[2] = 0.0;
        }
      }
      ++pRLInfo;
      p_z += 6;
      --nCount;
    }
    while ( nCount != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A7A70
// Name: private: int CClientLeafSystem::ExtractCulledRenderables(int,struct CClientLeafSystem::RenderableInfo_t __near * __near *,struct CClientLeafSystem::BuildRenderListInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CClientLeafSystem::ExtractCulledRenderables(
        CClientLeafSystem *this,
        int nCount,
        CClientLeafSystem::RenderableInfo_t **ppRenderables,
        CClientLeafSystem::BuildRenderListInfo_t *pRLInfo)
{
  bool v4; // al
  int v5; // eax
  float *v6; // esi
  float *v7; // edi
  CClientLeafSystem::RenderableInfo_t *v8; // ebx
  int v9; // eax
  int v11; // eax
  float *p_z; // esi
  float *v13; // edi
  CClientLeafSystem::RenderableInfo_t *v14; // ebx
  int v15; // eax
  Frustum_t *list[256]; // [esp+0h] [ebp-408h] BYREF
  int i; // [esp+400h] [ebp-8h]
  int nUniqueCount; // [esp+404h] [ebp-4h]

  v4 = r_PortalTestEnts.m_pParent != nullptr
    && r_PortalTestEnts.m_pParent->m_Value.m_nValue != 0
    && (r_portalsopenall.m_pParent == nullptr || r_portalsopenall.m_pParent->m_Value.m_nValue == 0);
  nUniqueCount = 0;
  if ( !v4 )
  {
    v11 = 0;
    i = 0;
    if ( nCount > 0 )
    {
      p_z = &pRLInfo->m_vecMaxs.z;
      v13 = &pRLInfo->m_vecMaxs.z;
      do
      {
        v14 = ppRenderables[v11];
        if ( ((unsigned __int8)v14 & 1) != 0
          || !engine->CullBox(this: engine, a2: (const Vector *)(v13 - 5), a3: (const Vector *)(v13 - 2)) )
        {
          *(p_z - 5) = *(v13 - 5);
          *(p_z - 4) = *(v13 - 4);
          *(p_z - 3) = *(v13 - 3);
          *(p_z - 2) = *(v13 - 2);
          *(p_z - 1) = *(v13 - 1);
          *p_z = *v13;
          *((_WORD *)p_z + 2) = *((_WORD *)v13 + 2);
          *((_BYTE *)p_z + 6) = *((_BYTE *)v13 + 6);
          *((_BYTE *)p_z + 7) ^= (*((_BYTE *)p_z + 7) ^ *((_BYTE *)v13 + 7)) & 1;
          v15 = nUniqueCount;
          *((_BYTE *)p_z + 7) ^= (*((_BYTE *)p_z + 7) ^ *((_BYTE *)v13 + 7)) & 2;
          ppRenderables[v15] = v14;
          nUniqueCount = v15 + 1;
          p_z += 7;
        }
        else
        {
          --v14->m_nRenderFrame;
        }
        v11 = i + 1;
        v13 += 7;
        i = v11;
      }
      while ( v11 < nCount );
    }
    return nUniqueCount;
  }
  engine->GetFrustumList(this: engine, a2: list, a3: 256);
  v5 = 0;
  i = 0;
  if ( nCount <= 0 )
    return nUniqueCount;
  v6 = &pRLInfo->m_vecMaxs.z;
  v7 = &pRLInfo->m_vecMaxs.z;
  do
  {
    v8 = ppRenderables[v5];
    if ( ((unsigned __int8)v8 & 1) != 0
      || !Frustum_t::CullBox(
            this: list[*((__int16 *)v7 + 2) + 1],
            mins: (const Vector *)(v7 - 5),
            maxs: (const Vector *)(v7 - 2)) )
    {
      *(v6 - 5) = *(v7 - 5);
      *(v6 - 4) = *(v7 - 4);
      *(v6 - 3) = *(v7 - 3);
      *(v6 - 2) = *(v7 - 2);
      *(v6 - 1) = *(v7 - 1);
      *v6 = *v7;
      *((_WORD *)v6 + 2) = *((_WORD *)v7 + 2);
      *((_BYTE *)v6 + 6) = *((_BYTE *)v7 + 6);
      *((_BYTE *)v6 + 7) ^= (*((_BYTE *)v6 + 7) ^ *((_BYTE *)v7 + 7)) & 1;
      v9 = nUniqueCount;
      *((_BYTE *)v6 + 7) ^= (*((_BYTE *)v6 + 7) ^ *((_BYTE *)v7 + 7)) & 2;
      ppRenderables[v9] = v8;
      nUniqueCount = v9 + 1;
      v6 += 7;
    }
    else
    {
      --v8->m_nRenderFrame;
    }
    v5 = i + 1;
    v7 += 7;
    i = v5;
  }
  while ( v5 < nCount );
  return nUniqueCount;
}

//------------------------------------------------------------------------------
// Address: 0x100A7C50
// Name: private: int CClientLeafSystem::ExtractOccludedRenderables(int,struct CClientLeafSystem::RenderableInfo_t __near * __near *,struct CClientLeafSystem::BuildRenderListInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CClientLeafSystem::ExtractOccludedRenderables(
        CClientLeafSystem *this,
        int nCount,
        CClientLeafSystem::RenderableInfo_t **ppRenderables,
        CClientLeafSystem::BuildRenderListInfo_t *pRLInfo)
{
  int v4; // eax
  float *p_z; // esi
  float *v7; // edi
  CClientLeafSystem::RenderableInfo_t *v8; // ebx
  int i; // [esp+0h] [ebp-8h]
  int nUniqueCount; // [esp+4h] [ebp-4h]

  if ( (_S6_26 & 1) == 0 )
  {
    _S6_26 |= 1u;
    ConVarRef::ConVarRef(this: &r_occlusion, pName: "r_occlusion");
  }
  v4 = 0;
  if ( r_occlusion.m_pConVarState->m_Value.m_nValue == 0 )
    return nCount;
  nUniqueCount = 0;
  i = 0;
  if ( nCount > 0 )
  {
    p_z = &pRLInfo->m_vecMaxs.z;
    v7 = &pRLInfo->m_vecMaxs.z;
    do
    {
      v8 = ppRenderables[v4];
      if ( ((unsigned __int8)v8 & 1) == 0
        && (*((_BYTE *)v7 + 7) & 1) != 0
        && engine->IsOccluded(this: engine, a2: (const Vector *)(v7 - 5), a3: (const Vector *)(v7 - 2)) )
      {
        --v8->m_nRenderFrame;
      }
      else
      {
        *(p_z - 5) = *(v7 - 5);
        *(p_z - 4) = *(v7 - 4);
        *(p_z - 3) = *(v7 - 3);
        *(p_z - 2) = *(v7 - 2);
        *(p_z - 1) = *(v7 - 1);
        *p_z = *v7;
        *((_WORD *)p_z + 2) = *((_WORD *)v7 + 2);
        *((_BYTE *)p_z + 6) = *((_BYTE *)v7 + 6);
        *((_BYTE *)p_z + 7) ^= (*((_BYTE *)p_z + 7) ^ *((_BYTE *)v7 + 7)) & 1;
        *((_BYTE *)p_z + 7) ^= (*((_BYTE *)p_z + 7) ^ *((_BYTE *)v7 + 7)) & 2;
        ppRenderables[nUniqueCount++] = v8;
        p_z += 7;
      }
      v4 = i + 1;
      v7 += 7;
      i = v4;
    }
    while ( v4 < nCount );
  }
  return nUniqueCount;
}

//------------------------------------------------------------------------------
// Address: 0x100A7D60
// Name: private: void CClientLeafSystem::AddRenderablesToRenderLists(struct SetupRenderInfo_t const __near &,int,struct CClientLeafSystem::RenderableInfo_t __near * __near *,struct CClientLeafSystem::BuildRenderListInfo_t __near *,int,struct DetailRenderableInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::AddRenderablesToRenderLists(
        CClientLeafSystem *this,
        const SetupRenderInfo_t *info,
        int nCount,
        CClientLeafSystem::RenderableInfo_t **ppRenderables,
        CClientLeafSystem::BuildRenderListInfo_t *pRLInfo,
        int nDetailCount,
        DetailRenderableInfo_t *pDetailInfo)
{
  const SetupRenderInfo_t *v7; // edi
  void *v8; // esp
  int v9; // eax
  int v10; // ecx
  unsigned __int8 *p_m_nAlpha; // edx
  CClientLeafSystem::RenderableInfo_t *v12; // ebx
  RenderableInstance_t *p_m_InstanceData; // edi
  int v14; // ecx
  CClientRenderablesList *v15; // esi
  int v16; // eax
  unsigned __int8 m_nAlpha; // dl
  int v18; // eax
  int v19; // edx
  int v20; // eax
  RenderGroup_t v21; // esi
  RenderableInstance_t *v22; // esi
  int v23; // ecx
  CClientRenderablesList *v24; // edi
  int v25; // eax
  unsigned __int8 v26; // dl
  int v27; // eax
  int v28; // eax
  int v29; // [esp+0h] [ebp-30h] BYREF
  CClientLeafSystem *v30; // [esp+Ch] [ebp-24h]
  CClientLeafSystem::BuildRenderListInfo_t **pTranslucentRLInfo; // [esp+10h] [ebp-20h]
  int nTranslucent; // [esp+14h] [ebp-1Ch]
  CClientRenderablesList *m_pRenderList; // [esp+18h] [ebp-18h]
  int i; // [esp+1Ch] [ebp-14h]
  int nTLucInfoCount; // [esp+20h] [ebp-10h]
  unsigned __int8 *v36; // [esp+24h] [ebp-Ch]
  int nCurDetail; // [esp+28h] [ebp-8h]
  int nWorldListLeafIndex; // [esp+2Ch] [ebp-4h]
  bool bIsTwoPass; // [esp+44h] [ebp+14h]

  v7 = info;
  m_pRenderList = info->m_pRenderList;
  v30 = this;
  v8 = alloca(4 * nCount);
  v9 = 0;
  v10 = 0;
  pTranslucentRLInfo = (CClientLeafSystem::BuildRenderListInfo_t **)&v29;
  nTranslucent = 0;
  nCurDetail = 0;
  nTLucInfoCount = 0;
  nWorldListLeafIndex = -1;
  i = 0;
  if ( nCount > 0 )
  {
    p_m_nAlpha = &pRLInfo->m_nAlpha;
    v36 = &pRLInfo->m_nAlpha;
    do
    {
      v12 = ppRenderables[v10];
      if ( ((unsigned __int8)v12 & 1) != 0 )
      {
        if ( (*((_BYTE *)v7 + 48) & 8) == 0 && v9 < nDetailCount )
        {
          p_m_InstanceData = &pDetailInfo[v9].m_InstanceData;
          do
          {
            if ( *(_DWORD *)&p_m_InstanceData[-8].m_nAlpha > nWorldListLeafIndex )
              break;
            v14 = *(_DWORD *)&p_m_InstanceData[-4].m_nAlpha;
            v15 = info->m_pRenderList;
            v16 = v15->m_RenderGroupCounts[v14];
            m_nAlpha = p_m_InstanceData->m_nAlpha;
            if ( v16 >= 4096 )
            {
              engine->Con_NPrintf(
                this: engine,
                a2: 10,
                a3: "Warning: overflowed CClientRenderablesList group %d",
                *(_DWORD *)&p_m_InstanceData[-4].m_nAlpha);
            }
            else
            {
              v18 = (int)&v15->m_RenderGroups[v14][v16];
              *(_DWORD *)v18 = *(_DWORD *)&p_m_InstanceData[-12].m_nAlpha;
              *(_WORD *)(v18 + 4) = nWorldListLeafIndex;
              *(_BYTE *)(v18 + 7) = 0;
              *(_BYTE *)(v18 + 6) = m_nAlpha;
              ++v15->m_RenderGroupCounts[v14];
            }
            p_m_InstanceData += 16;
            ++nCurDetail;
          }
          while ( nCurDetail < nDetailCount );
          v7 = info;
        }
        v19 = m_pRenderList->m_RenderGroupCounts[1];
        ++nWorldListLeafIndex;
        nTranslucent = v19;
        nTLucInfoCount = 0;
      }
      else if ( *p_m_nAlpha != 0xFF || (*((_WORD *)v12 + 11) & 0x3000) != 0 )
      {
        if ( (*((_WORD *)v12 + 11) & 0x3000) != 0x2000 || (bIsTwoPass = true, *p_m_nAlpha != 0xFF) )
          bIsTwoPass = false;
        if ( (*((_BYTE *)v7 + 48) & 2) != 0 )
        {
          if ( (p_m_nAlpha[1] & 2) != 0 )
          {
            v21 = RENDER_GROUP_TRANSLUCENT_IGNOREZ;
          }
          else
          {
            v20 = nTLucInfoCount;
            pTranslucentRLInfo[nTLucInfoCount] = (CClientLeafSystem::BuildRenderListInfo_t *)(v36 - 26);
            v21 = RENDER_GROUP_TRANSLUCENT;
            nTLucInfoCount = v20 + 1;
          }
          AddRenderableToRenderList(
            renderList: v7->m_pRenderList,
            pRenderable: v12->m_pRenderable,
            iLeaf: nWorldListLeafIndex,
            group: v21,
            nModelType: *((unsigned __int16 *)v12 + 11) >> 14,
            nAlphaModulation: *v36,
            bShadowDepthNoCache: (*((_WORD *)v12 + 11) & 0x200) != 0,
            bTwoPass: bIsTwoPass);
        }
        if ( bIsTwoPass )
          AddRenderableToRenderList(
            renderList: v7->m_pRenderList,
            pRenderable: v12->m_pRenderable,
            iLeaf: nWorldListLeafIndex,
            group: RENDER_GROUP_OPAQUE,
            nModelType: *((unsigned __int16 *)v12 + 11) >> 14,
            nAlphaModulation: 0xFFu,
            bShadowDepthNoCache: (*((_WORD *)v12 + 11) & 0x200) != 0,
            bTwoPass: bIsTwoPass);
      }
      else
      {
        AddRenderableToRenderList(
          renderList: v7->m_pRenderList,
          pRenderable: v12->m_pRenderable,
          iLeaf: nWorldListLeafIndex,
          group: RENDER_GROUP_OPAQUE,
          nModelType: *((unsigned __int16 *)v12 + 11) >> 14,
          nAlphaModulation: 0xFFu,
          bShadowDepthNoCache: (*((_WORD *)v12 + 11) & 0x200) != 0,
          bTwoPass: false);
      }
      v9 = nCurDetail;
      v10 = i + 1;
      p_m_nAlpha = v36 + 28;
      i = v10;
      v36 += 28;
    }
    while ( v10 < nCount );
  }
  if ( v9 < nDetailCount )
  {
    v22 = &pDetailInfo[v9].m_InstanceData;
    do
    {
      if ( *(_DWORD *)&v22[-8].m_nAlpha > nWorldListLeafIndex )
        break;
      v23 = *(_DWORD *)&v22[-4].m_nAlpha;
      v24 = v7->m_pRenderList;
      v25 = v24->m_RenderGroupCounts[v23];
      v26 = v22->m_nAlpha;
      if ( v25 >= 4096 )
      {
        engine->Con_NPrintf(
          this: engine,
          a2: 10,
          a3: "Warning: overflowed CClientRenderablesList group %d",
          *(_DWORD *)&v22[-4].m_nAlpha);
      }
      else
      {
        v27 = (int)&v24->m_RenderGroups[v23][v25];
        *(_DWORD *)v27 = *(_DWORD *)&v22[-12].m_nAlpha;
        *(_WORD *)(v27 + 4) = nWorldListLeafIndex;
        *(_BYTE *)(v27 + 7) = 0;
        *(_BYTE *)(v27 + 6) = v26;
        ++v24->m_RenderGroupCounts[v23];
      }
      v7 = info;
      v22 += 16;
      ++nCurDetail;
    }
    while ( nCurDetail < nDetailCount );
  }
  v28 = m_pRenderList->m_RenderGroupCounts[1] - nTranslucent;
  if ( v28 != 0 && (*((_BYTE *)v7 + 48) & 2) != 0 )
    CClientLeafSystem::SortEntities(
      this: v30,
      vecRenderOrigin: &v7->m_vecRenderOrigin,
      vecRenderForward: &v7->m_vecRenderForward,
      pEntities: &m_pRenderList->m_RenderGroups[1][nTranslucent],
      pTranslucentRLInfo,
      nEntities: v28);
}

//------------------------------------------------------------------------------
// Address: 0x100A8830
// Name: void DefaultRenderBoundsWorldspace(class IClientRenderable __near *,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall DefaultRenderBoundsWorldspace(
        float a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        IClientRenderable *pRenderable,
        Vector *absMins,
        Vector *absMaxs)
{
  int v6; // eax
  C_BaseEntity *v7; // eax
  C_BaseEntity *v8; // esi
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  void (__thiscall *GetRenderBounds)(IClientRenderable *, Vector *, Vector *); // edx
  const Vector *LocalOrigin; // eax
  float v13; // xmm0_4
  __int128 v14; // xmm1
  float v15; // xmm0_4
  void (__thiscall *v16)(IClientRenderable *, Vector *, Vector *); // eax
  const QAngle *v17; // eax
  const Vector *v18; // eax
  IClientRenderable_vtbl *v19; // edx
  const matrix3x4_t *(__thiscall *RenderableToWorldTransform)(IClientRenderable *); // eax
  const matrix3x4_t *v21; // eax
  float v22; // [esp-30h] [ebp-6Ch]
  float v23; // [esp-20h] [ebp-5Ch]
  __int128 v24; // [esp-10h] [ebp-4Ch] BYREF
  Vector vAddMaxs; // [esp+0h] [ebp-3Ch] BYREF
  float v26; // [esp+Ch] [ebp-30h]
  float v27; // [esp+10h] [ebp-2Ch]
  Vector vAddMins; // [esp+14h] [ebp-28h] BYREF
  Vector mins; // [esp+20h] [ebp-1Ch] BYREF
  Vector maxs; // [esp+2Ch] [ebp-10h] BYREF
  float retaddr; // [esp+3Ch] [ebp+0h]

  maxs.y = a1;
  maxs.z = retaddr;
  v6 = ((int (__thiscall *)(IClientRenderable *, int, int))pRenderable->GetIClientUnknown)(a1: pRenderable, a2, a3);
  v7 = (C_BaseEntity *)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 28))(a1: v6);
  v8 = v7;
  if ( v7 != nullptr
    && (C_BaseEntity::IsFollowingEntity(this: v7) || v8->m_iParentAttachment != 0)
    && (m_Index = v8->m_pMoveParent.m_Index) != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
  {
    CalcRenderableWorldSpaceAABB_Fast(
      a1: COERCE_FLOAT((Vector *)&maxs.y),
      a2: (int)absMaxs,
      a3: (int)v8,
      pRenderable: (IClientRenderable *)&m_pEntity[1],
      absMin: absMins,
      absMax: absMaxs);
    GetRenderBounds = v8->GetRenderBounds;
    LODWORD(maxs.x) = (char *)&v24 + 4;
    ((void (__thiscall *)(IClientRenderable *, float *))GetRenderBounds)(a1: &v8->IClientRenderable, a2: &vAddMaxs.z);
    LocalOrigin = C_BaseEntity::GetLocalOrigin(this: v8);
    v23 = fsqrt(
            (float)((float)(LocalOrigin->x * LocalOrigin->x) + (float)(LocalOrigin->y * LocalOrigin->y))
          + (float)(LocalOrigin->z * LocalOrigin->z));
    maxs.x = *((float *)&v24 + 2) * *((float *)&v24 + 2);
    v14 = 0;
    v13 = fsqrt((float)((float)(v27 * v27) + (float)(vAddMaxs.z * vAddMaxs.z)) + (float)(v26 * v26));
    *(float *)&v14 = fsqrt(
                       (float)((float)(*((float *)&v24 + 2) * *((float *)&v24 + 2))
                             + (float)(*((float *)&v24 + 3) * *((float *)&v24 + 3)))
                     + (float)(*((float *)&v24 + 1) * *((float *)&v24 + 1)));
    v24 = v14;
    if ( v13 <= *(float *)&v14 )
      v22 = *(float *)&v14;
    else
      v22 = v13;
    v15 = v22;
    if ( v22 <= v23 )
      v15 = v23;
    absMins->x = absMins->x - v15;
    absMins->y = absMins->y - v15;
    absMins->z = absMins->z - v15;
    absMaxs->x = absMaxs->x + v15;
    absMaxs->y = absMaxs->y + v15;
    absMaxs->z = absMaxs->z + v15;
  }
  else
  {
    v16 = pRenderable->GetRenderBounds;
    LODWORD(maxs.x) = &mins;
    ((void (__thiscall *)(IClientRenderable *, Vector *))v16)(a1: pRenderable, a2: &vAddMins);
    v17 = pRenderable->GetRenderAngles(this: pRenderable);
    if ( vec3_angle.x == v17->x && vec3_angle.y == v17->y && vec3_angle.z == v17->z )
    {
      v18 = pRenderable->GetRenderOrigin(this: pRenderable);
      absMins->x = v18->x + vAddMins.x;
      absMins->y = v18->y + vAddMins.y;
      absMins->z = v18->z + vAddMins.z;
      absMaxs->x = v18->x + mins.x;
      absMaxs->y = v18->y + mins.y;
      absMaxs->z = v18->z + mins.z;
    }
    else
    {
      LODWORD(mins.z) = absMaxs;
      LODWORD(mins.y) = absMins;
      v19 = pRenderable->__vftable;
      LODWORD(mins.x) = &mins;
      RenderableToWorldTransform = v19->RenderableToWorldTransform;
      LODWORD(vAddMins.z) = &vAddMins;
      v21 = RenderableToWorldTransform(this: pRenderable);
      TransformAABB(
        transform: v21,
        vecMinsIn: (const Vector *)LODWORD(vAddMins.z),
        vecMaxsIn: (const Vector *)LODWORD(mins.x),
        vecMinsOut: (Vector *)LODWORD(mins.y),
        vecMaxsOut: (Vector *)LODWORD(mins.z));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A8B10
// Name: private: void CClientLeafSystem::RemoveFromViewModelList(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::RemoveFromViewModelList(CClientLeafSystem *this, unsigned __int16 handle)
{
  int m_Size; // edx
  int v3; // eax
  unsigned __int16 *m_pMemory; // esi
  int v5; // esi

  m_Size = this->m_ViewModels.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    m_pMemory = this->m_ViewModels.m_Memory.m_pMemory;
    while ( *m_pMemory != handle )
    {
      ++v3;
      ++m_pMemory;
      if ( v3 >= m_Size )
        goto LABEL_5;
    }
  }
  v5 = this->m_ViewModels.m_Size;
  if ( m_Size > 0 )
  {
    if ( v3 != v5 - 1 )
      this->m_ViewModels.m_Memory.m_pMemory[v3] = this->m_ViewModels.m_Memory.m_pMemory[v5 - 1];
    --this->m_ViewModels.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A8B70
// Name: void ComputeScreenSizeInfo(struct ScreenSizeComputeInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeScreenSizeInfo(ScreenSizeComputeInfo_t *pInfo)
{
  IMatRenderContext *v1; // esi
  VMatrix projectionMatrix; // [esp+8h] [ebp-90h] BYREF
  VMatrix viewMatrix; // [esp+48h] [ebp-50h] BYREF
  int w; // [esp+88h] [ebp-10h] BYREF
  int x; // [esp+8Ch] [ebp-Ch] BYREF
  int y; // [esp+90h] [ebp-8h] BYREF
  int h; // [esp+94h] [ebp-4h] BYREF

  v1 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v1 != nullptr )
    v1->BeginRender(this: v1);
  v1->GetMatrix_2(this: v1, a2: MATERIAL_VIEW, a3: &viewMatrix);
  v1->GetMatrix_2(this: v1, a2: MATERIAL_PROJECTION, a3: &projectionMatrix);
  MatrixMultiply(src1: &projectionMatrix, src2: &viewMatrix, dst: &pInfo->m_matViewProj);
  v1->GetViewport(this: v1, a2: &x, a3: &y, a4: &w, a5: &h);
  pInfo->m_nViewportHeight = h;
  v1->GetWorldSpaceCameraVectors(this: v1, a2: nullptr, a3: nullptr, a4: &pInfo->m_vecViewUp);
  v1->EndRender(this: v1);
  v1->Release(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x100A8C20
// Name: private: int CClientLeafSystem::ComputeTranslucency(int,int,int,struct CClientLeafSystem::RenderableInfo_t __near * __near *,struct CClientLeafSystem::BuildRenderListInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
int __userpurge CClientLeafSystem::ComputeTranslucency@<eax>(
        CClientLeafSystem *this@<ecx>,
        CClientLeafSystem::AlphaInfo_t *a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        int nFrameNumber,
        int nViewID,
        float nCount,
        CClientLeafSystem::RenderableInfo_t **ppRenderables,
        CClientLeafSystem::BuildRenderListInfo_t *pRLInfo)
{
  int v9; // esi
  void *v10; // esp
  CClientLeafSystem::AlphaInfo_t *v11; // edx
  float v12; // edi
  float *p_z; // eax
  float *v14; // esi
  CClientLeafSystem::RenderableInfo_t *v15; // ecx
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm1_4
  __int128 v22; // xmm0
  char *v23; // esi
  int v24; // edi
  unsigned __int8 v25; // al
  __int16 v26; // cx
  char v27; // cl
  char v28; // cl
  int v29; // eax
  int v30; // esi
  CClientLeafSystem::AlphaInfo_t *v31; // edi
  CClientLeafSystem::AlphaInfo_t *v32; // ecx
  unsigned __int8 *p_m_nAlpha; // edi
  int i; // edx
  int v35; // eax
  CClientLeafSystem::AlphaInfo_t *v36; // esi
  CClientAlphaProperty *m_pAlphaProperty; // eax
  int v38; // eax
  float v39; // ecx
  int result; // eax
  CClientLeafSystem::BuildRenderListInfo_t *v41; // esi
  CClientLeafSystem::AlphaInfo_t *v42; // ecx
  char *v43; // edi
  bool v44; // zf
  float *v45; // esi
  float *v46; // edi
  char v47; // dl
  int v48; // [esp+4Ch] [ebp-12Ch] BYREF
  int v49; // [esp+50h] [ebp-128h]
  Vector *p_m_vecViewUp; // [esp+54h] [ebp-124h]
  int v51; // [esp+58h] [ebp-120h] BYREF
  VMatrix v52; // [esp+5Ch] [ebp-11Ch] BYREF
  VMatrix v53; // [esp+9Ch] [ebp-DCh] BYREF
  ScreenSizeComputeInfo_t v54; // [esp+DCh] [ebp-9Ch] BYREF
  __int128 v55; // [esp+12Ch] [ebp-4Ch]
  int v56; // [esp+144h] [ebp-34h] BYREF
  int v57; // [esp+148h] [ebp-30h] BYREF
  int v58; // [esp+14Ch] [ebp-2Ch] BYREF
  int v59; // [esp+150h] [ebp-28h] BYREF
  float flMaxScreenWidth; // [esp+154h] [ebp-24h] BYREF
  float v61; // [esp+158h] [ebp-20h] BYREF
  CClientLeafSystem *v62; // [esp+15Ch] [ebp-1Ch]
  CClientLeafSystem::AlphaInfo_t *v63; // [esp+160h] [ebp-18h]
  float flMinScreenWidth; // [esp+164h] [ebp-14h] BYREF
  float v65; // [esp+168h] [ebp-10h] BYREF
  CClientLeafSystem::AlphaInfo_t *pAlphaInfo; // [esp+16Ch] [ebp-Ch]
  float flMinLevelFadeArea; // [esp+170h] [ebp-8h]
  float retaddr; // [esp+178h] [ebp+0h]

  pAlphaInfo = a2;
  flMinLevelFadeArea = retaddr;
  v49 = a4;
  v9 = LODWORD(nCount);
  v48 = a3;
  v62 = this;
  v10 = alloca(24 * LODWORD(nCount));
  v11 = (CClientLeafSystem::AlphaInfo_t *)&v48;
  v12 = 0.0;
  v63 = (CClientLeafSystem::AlphaInfo_t *)&v48;
  if ( SLODWORD(nCount) > 0 )
  {
    p_z = &pRLInfo->m_vecMaxs.z;
    v14 = (float *)&v51;
    do
    {
      v15 = ppRenderables[LODWORD(v12)];
      if ( ((unsigned __int8)v15 & 1) != 0 )
      {
        *(v14 - 3) = 0.0;
      }
      else
      {
        v16 = *(p_z - 4) + *(p_z - 1);
        v17 = *(p_z - 3) + *p_z;
        v18 = (float)(*(p_z - 5) + *(p_z - 2)) * 0.5;
        *(v14 - 2) = v18;
        v19 = v16 * 0.5;
        *(v14 - 1) = v19;
        v20 = v17 * 0.5;
        *v14 = v20;
        v21 = (float)((float)((float)(v19 - *(p_z - 1)) * (float)(v19 - *(p_z - 1)))
                    + (float)((float)(v20 - *p_z) * (float)(v20 - *p_z)))
            + (float)((float)(v18 - *(p_z - 2)) * (float)(v18 - *(p_z - 2)));
        v22 = 0;
        *(float *)&v22 = fsqrt(v21);
        v55 = v22;
        *((_DWORD *)v14 + 1) = v22;
        *(v14 - 3) = *(float *)&v15->m_pAlphaProperty;
        v14[2] = 1.0;
      }
      ++LODWORD(v12);
      p_z += 7;
      v14 += 6;
    }
    while ( SLODWORD(v12) < SLODWORD(nCount) );
    v65 = COERCE_FLOAT(&v48);
    v23 = (char *)pRLInfo + 27;
    flMinScreenWidth = nCount;
    do
    {
      v24 = *(_DWORD *)LODWORD(v65);
      if ( *(_DWORD *)LODWORD(v65) != 0 )
      {
        v25 = CClientAlphaProperty::ComputeRenderAlpha(this: *(CClientAlphaProperty **)LODWORD(v65));
        v26 = (*(_WORD *)(v24 + 10) >> 5) & 0xF;
        if ( v26 == 3 || v26 == 9 )
        {
          v28 = *v23 ^ 2;
          *(v23 - 1) = v25;
          *v23 ^= v28 & 2;
        }
        else
        {
          v27 = *v23;
          *(v23 - 1) = v25;
          *v23 ^= v27 & 2;
        }
      }
      else
      {
        *v23 &= ~2u;
        *(v23 - 1) = -1;
      }
      LODWORD(v65) += 24;
      v23 += 28;
      --LODWORD(flMinScreenWidth);
    }
    while ( flMinScreenWidth != 0.0 );
    v9 = LODWORD(nCount);
    v11 = v63;
  }
  if ( g_MakingDevShots
    || cl_leveloverview.m_pParent != nullptr && cl_leveloverview.m_pParent->m_Value.m_nValue != 0
    || nViewID == 1 )
  {
    goto LABEL_35;
  }
  CClientLeafSystem::ComputeDistanceFade(this: v62, nCount: v9, pAlphaInfo: v11, pRLInfo);
  modelinfo->GetLevelScreenFadeRange(this: modelinfo, a2: &flMinScreenWidth, a3: &flMaxScreenWidth);
  view->GetScreenFadeDistances(this: view, a2: &v65, a3: &v61);
  if ( flMinScreenWidth <= 0.0 && v65 <= 0.0 )
  {
    v31 = v63;
  }
  else
  {
    v29 = ((int (__thiscall *)(IMaterialSystem *, int, int, Vector *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pMaterialSystem->GetRenderContext)(
            a1: g_pMaterialSystem,
            a2: v48,
            a3: v49,
            a4: p_m_vecViewUp,
            a5: v51,
            a6: LODWORD(v52.m[0][0]),
            a7: LODWORD(v52.m[0][1]),
            a8: LODWORD(v52.m[0][2]),
            a9: LODWORD(v52.m[0][3]),
            a10: LODWORD(v52.m[1][0]),
            a11: LODWORD(v52.m[1][1]),
            a12: LODWORD(v52.m[1][2]));
    v30 = v29;
    if ( v29 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v29 + 8))(a1: v29);
    (*(void (__thiscall **)(int, _DWORD, VMatrix *))(*(_DWORD *)v30 + 120))(a1: v30, a2: 0, a3: &v52);
    (*(void (__thiscall **)(int, int, VMatrix *))(*(_DWORD *)v30 + 120))(a1: v30, a2: 1, a3: &v53);
    MatrixMultiply(src1: &v53, src2: &v52, dst: &v54.m_matViewProj);
    (*(void (__thiscall **)(int, int *, int *, int *, int *))(*(_DWORD *)v30 + 156))(
      a1: v30,
      a2: &v58,
      a3: &v57,
      a4: &v56,
      a5: &v59);
    p_m_vecViewUp = &v54.m_vecViewUp;
    v54.m_nViewportHeight = v59;
    (*(void (__thiscall **)(int, _DWORD, _DWORD, Vector *))(*(_DWORD *)v30 + 572))(
      a1: v30,
      a2: 0,
      a3: 0,
      a4: &v54.m_vecViewUp);
    v31 = v63;
    CClientLeafSystem::ComputeScreenFade(
      this: v62,
      info: &v54,
      flMinScreenWidth,
      flMaxScreenWidth,
      nCount: SLODWORD(nCount),
      pAlphaInfo: v63);
    CClientLeafSystem::ComputeScreenFade(
      this: v62,
      info: &v54,
      flMinScreenWidth: v65,
      flMaxScreenWidth: v61,
      nCount: SLODWORD(nCount),
      pAlphaInfo: v31);
    (*(void (__thiscall **)(int))(*(_DWORD *)v30 + 12))(a1: v30);
    (*(void (__thiscall **)(int))(*(_DWORD *)v30 + 4))(a1: v30);
    v9 = LODWORD(nCount);
  }
  if ( v9 > 0 )
  {
    v32 = v31;
    p_m_nAlpha = &pRLInfo->m_nAlpha;
    for ( i = v9; i != 0; --i )
    {
      if ( v32->m_pAlphaProperty != nullptr )
      {
        v35 = (int)(float)((float)*p_m_nAlpha * v32->m_flFadeFactor);
        if ( v35 >= 0 )
        {
          if ( v35 > 255 )
            LOBYTE(v35) = -1;
        }
        else
        {
          LOBYTE(v35) = 0;
        }
        *p_m_nAlpha = v35;
      }
      ++v32;
      p_m_nAlpha += 28;
    }
LABEL_35:
    if ( v9 > 0 )
    {
      v36 = v63;
      LODWORD(v65) = &pRLInfo->m_nAlpha;
      flMinScreenWidth = nCount;
      do
      {
        m_pAlphaProperty = v36->m_pAlphaProperty;
        if ( v36->m_pAlphaProperty != nullptr && m_pAlphaProperty->m_hShadowHandle != 0xFFFF )
        {
          v62 = (CClientLeafSystem *)(unsigned __int8)*(_BYTE *)LODWORD(v65);
          if ( (*((_WORD *)m_pAlphaProperty + 5) & 0x400) != 0 )
          {
            v38 = (int)m_pAlphaProperty->m_pOuter->GetClientRenderable(this: m_pAlphaProperty->m_pOuter);
            v62 = (CClientLeafSystem *)(*(unsigned __int8 (__thiscall **)(int, CClientLeafSystem *))(*(_DWORD *)v38 + 172))(
                                         a1: v38,
                                         a2: v62);
          }
          g_pClientShadowMgr->SetFalloffBias(
            this: g_pClientShadowMgr,
            a2: v36->m_pAlphaProperty->m_hShadowHandle,
            a3: -1 - (_BYTE)v62);
        }
        LODWORD(v65) += 28;
        ++v36;
        --LODWORD(flMinScreenWidth);
      }
      while ( flMinScreenWidth != 0.0 );
      v9 = LODWORD(nCount);
    }
  }
  v39 = 0.0;
  result = 0;
  v65 = 0.0;
  if ( v9 >= 4 )
  {
    v41 = pRLInfo;
    LODWORD(flMinScreenWidth) = ((unsigned int)(LODWORD(nCount) - 4) >> 2) + 1;
    v42 = (CClientLeafSystem::AlphaInfo_t *)(ppRenderables + 2);
    v63 = (CClientLeafSystem::AlphaInfo_t *)(ppRenderables + 2);
    v43 = (char *)&pRLInfo[1].m_vecMaxs.z;
    LODWORD(v65) = 4 * LODWORD(flMinScreenWidth);
    do
    {
      if ( (LOBYTE(v42[-1].m_flRadius) & 1) != 0 || *(v43 - 22) != 0 )
      {
        ppRenderables[result] = (CClientLeafSystem::RenderableInfo_t *)LODWORD(v42[-1].m_flRadius);
        v41->m_vecMins.x = *((float *)v43 - 12);
        ++result;
        v41->m_vecMins.y = *((float *)v43 - 11);
        v41->m_vecMins.z = *((float *)v43 - 10);
        v41->m_vecMaxs.x = *((float *)v43 - 9);
        v41->m_vecMaxs.y = *((float *)v43 - 8);
        v41->m_vecMaxs.z = *((float *)v43 - 7);
        v41->m_nArea = *((_WORD *)v43 - 12);
        v41->m_nAlpha = *(v43 - 22);
        *((_BYTE *)v41 + 27) ^= (*(v43 - 21) ^ *((_BYTE *)v41 + 27)) & 1;
        v42 = v63;
        *((_BYTE *)v41 + 27) ^= (*((_BYTE *)v41 + 27) ^ *(v43 - 21)) & 2;
        ++v41;
      }
      else
      {
        --*(_DWORD *)(LODWORD(v42[-1].m_flRadius) + 12);
      }
      if ( (LOBYTE(v42[-1].m_flFadeFactor) & 1) != 0 || v43[6] != 0 )
      {
        ppRenderables[result] = (CClientLeafSystem::RenderableInfo_t *)LODWORD(v42[-1].m_flFadeFactor);
        v41->m_vecMins.x = *((float *)v43 - 5);
        ++result;
        v41->m_vecMins.y = *((float *)v43 - 4);
        v41->m_vecMins.z = *((float *)v43 - 3);
        v41->m_vecMaxs.x = *((float *)v43 - 2);
        v41->m_vecMaxs.y = *((float *)v43 - 1);
        v41->m_vecMaxs.z = *(float *)v43;
        v41->m_nArea = *((_WORD *)v43 + 2);
        v41->m_nAlpha = v43[6];
        *((_BYTE *)v41 + 27) ^= (v43[7] ^ *((_BYTE *)v41 + 27)) & 1;
        v42 = v63;
        *((_BYTE *)v41 + 27) ^= (*((_BYTE *)v41 + 27) ^ v43[7]) & 2;
        ++v41;
      }
      else
      {
        --*(_DWORD *)(LODWORD(v42[-1].m_flFadeFactor) + 12);
      }
      if ( ((int)v42->m_pAlphaProperty & 1) != 0 || v43[34] != 0 )
      {
        ppRenderables[result] = (CClientLeafSystem::RenderableInfo_t *)v42->m_pAlphaProperty;
        v41->m_vecMins.x = *((float *)v43 + 2);
        ++result;
        v41->m_vecMins.y = *((float *)v43 + 3);
        v41->m_vecMins.z = *((float *)v43 + 4);
        v41->m_vecMaxs.x = *((float *)v43 + 5);
        v41->m_vecMaxs.y = *((float *)v43 + 6);
        v41->m_vecMaxs.z = *((float *)v43 + 7);
        v41->m_nArea = *((_WORD *)v43 + 16);
        v41->m_nAlpha = v43[34];
        *((_BYTE *)v41 + 27) ^= (v43[35] ^ *((_BYTE *)v41 + 27)) & 1;
        v42 = v63;
        *((_BYTE *)v41 + 27) ^= (*((_BYTE *)v41 + 27) ^ v43[35]) & 2;
        ++v41;
      }
      else
      {
        --*(_DWORD *)&v42->m_pAlphaProperty->m_nDesyncOffset;
      }
      if ( (LOBYTE(v42->m_vecCenter.x) & 1) != 0 || v43[62] != 0 )
      {
        ppRenderables[result] = (CClientLeafSystem::RenderableInfo_t *)LODWORD(v42->m_vecCenter.x);
        v41->m_vecMins.x = *((float *)v43 + 9);
        ++result;
        v41->m_vecMins.y = *((float *)v43 + 10);
        v41->m_vecMins.z = *((float *)v43 + 11);
        v41->m_vecMaxs.x = *((float *)v43 + 12);
        v41->m_vecMaxs.y = *((float *)v43 + 13);
        v41->m_vecMaxs.z = *((float *)v43 + 14);
        v41->m_nArea = *((_WORD *)v43 + 30);
        v41->m_nAlpha = v43[62];
        *((_BYTE *)v41 + 27) ^= (v43[63] ^ *((_BYTE *)v41 + 27)) & 1;
        v42 = v63;
        *((_BYTE *)v41 + 27) ^= (*((_BYTE *)v41 + 27) ^ v43[63]) & 2;
        ++v41;
      }
      else
      {
        --*(_DWORD *)(LODWORD(v42->m_vecCenter.x) + 12);
      }
      v42 = (CClientLeafSystem::AlphaInfo_t *)((char *)v42 + 16);
      v43 += 112;
      v44 = LODWORD(flMinScreenWidth)-- == 1;
      v63 = v42;
    }
    while ( !v44 );
    v39 = v65;
    v9 = LODWORD(nCount);
  }
  if ( SLODWORD(v39) < v9 )
  {
    v45 = &pRLInfo[result].m_vecMaxs.z;
    v46 = &pRLInfo[LODWORD(v39)].m_vecMaxs.z;
    do
    {
      if ( ((int)ppRenderables[LODWORD(v39)] & 1) != 0 || *((_BYTE *)v46 + 6) != 0 )
      {
        ppRenderables[result] = ppRenderables[LODWORD(v39)];
        *(v45 - 5) = *(v46 - 5);
        ++result;
        *(v45 - 4) = *(v46 - 4);
        *(v45 - 3) = *(v46 - 3);
        *(v45 - 2) = *(v46 - 2);
        *(v45 - 1) = *(v46 - 1);
        *v45 = *v46;
        *((_WORD *)v45 + 2) = *((_WORD *)v46 + 2);
        v47 = *((_BYTE *)v45 + 7);
        *((_BYTE *)v45 + 6) = *((_BYTE *)v46 + 6);
        *((_BYTE *)v45 + 7) ^= (*((_BYTE *)v46 + 7) ^ v47) & 1;
        v39 = v65;
        *((_BYTE *)v45 + 7) ^= (*((_BYTE *)v45 + 7) ^ *((_BYTE *)v46 + 7)) & 2;
        v45 += 7;
      }
      else
      {
        --ppRenderables[LODWORD(v39)]->m_nRenderFrame;
      }
      ++LODWORD(v39);
      v46 += 7;
      v65 = v39;
    }
    while ( SLODWORD(v39) < SLODWORD(nCount) );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A92F0
// Name: private: void CClientLeafSystem::BuildRenderablesListForFastReflections(struct SetupRenderInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::BuildRenderablesListForFastReflections(
        CClientLeafSystem *this,
        const SetupRenderInfo_t *info)
{
  CClientLeafSystem *v2; // ebx
  int (__thiscall *GetFrustumList)(IVEngineClient *, Frustum_t **, int); // eax
  unsigned int i; // eax
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *m_pMemory; // esi
  int v6; // edi
  __int16 v7; // ax
  char *v8; // esi
  int m_nRenderFrame; // ecx
  __int16 v10; // ax
  int v11; // edi
  RenderGroup_t v12; // ebx
  __int16 v13; // ax
  bool v14; // al
  Frustum_t *list[256]; // [esp+4h] [ebp-40Ch] BYREF
  RenderGroup_t renderGroup; // [esp+404h] [ebp-Ch]
  int v17; // [esp+408h] [ebp-8h]
  CClientLeafSystem *v18; // [esp+40Ch] [ebp-4h]

  v2 = this;
  GetFrustumList = engine->GetFrustumList;
  v18 = this;
  GetFrustumList(this: engine, a2: list, a3: 256);
  for ( i = v2->m_Renderables.m_Head;
        i != 0xFFFF;
        i = *(unsigned __int16 *)((char *)&v2->m_Renderables.m_Memory.m_pMemory->m_Next + v6) )
  {
    m_pMemory = v2->m_Renderables.m_Memory.m_pMemory;
    v6 = 76 * i;
    v7 = *((_WORD *)&m_pMemory[i].m_Element + 11);
    v8 = (char *)m_pMemory + v6;
    v17 = v6;
    if ( (v7 & 9) == 0 )
    {
      m_nRenderFrame = info->m_nRenderFrame;
      if ( *((_DWORD *)v8 + 3) != m_nRenderFrame )
      {
        *((_DWORD *)v8 + 3) = m_nRenderFrame;
        if ( (v7 & 0x80u) != 0 )
        {
          if ( (v7 & 0x20) == 0 )
          {
            (*(void (__stdcall **)(char *, char *))(**(_DWORD **)v8 + 72))(a1: v8 + 48, a2: v8 + 60);
            v10 = *((_WORD *)v8 + 11);
            if ( (v10 & 0x40) == 0 )
              *((_WORD *)v8 + 11) = v10 | 0x20;
          }
          if ( !Frustum_t::CullBox(this: list[0], mins: (const Vector *)v8 + 4, maxs: (const Vector *)v8 + 5) )
          {
            v11 = *((_DWORD *)v8 + 1);
            v12 = RENDER_GROUP_OPAQUE;
            if ( v11 != 0
              && (CClientAlphaProperty::ComputeRenderAlpha(this: *((CClientAlphaProperty **)v8 + 1)) != 0xFF
               || (*((_WORD *)v8 + 11) & 0x3000) != 0) )
            {
              v13 = (*(_WORD *)(v11 + 10) >> 5) & 0xF;
              v14 = v13 == 3 || v13 == 9;
              renderGroup = v14 + 1;
              v12 = renderGroup;
            }
            AddRenderableToRenderList(
              renderList: info->m_pRenderList,
              pRenderable: *(IClientRenderable **)v8,
              iLeaf: 0,
              group: v12,
              nModelType: *((unsigned __int16 *)v8 + 11) >> 14,
              nAlphaModulation: 0xFFu,
              bShadowDepthNoCache: (*((_WORD *)v8 + 11) & 0x200) != 0,
              bTwoPass: false);
            v2 = v18;
            v6 = v17;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A9450
// Name: public: void CClientLeafSystem::HighlightAllTranslucentRenderables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::HighlightAllTranslucentRenderables(CClientLeafSystem *this)
{
  unsigned int i; // edi
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *m_pMemory; // esi
  unsigned int v4; // edi
  CClientAlphaProperty *m_pAlphaProperty; // ecx
  C_BaseEntity *v6; // eax
  C_BaseEntity *v7; // esi
  char *DebugName; // eax
  Vector mins; // [esp+28h] [ebp-3Ch] BYREF
  Vector extents; // [esp+34h] [ebp-30h] BYREF
  Vector vecSurroundMins; // [esp+40h] [ebp-24h] BYREF
  Vector vecSurroundMaxs; // [esp+4Ch] [ebp-18h] BYREF
  Vector center; // [esp+58h] [ebp-Ch] BYREF

  for ( i = this->m_Renderables.m_Head; i != 0xFFFF; i = this->m_Renderables.m_Memory.m_pMemory[v4].m_Next )
  {
    m_pMemory = this->m_Renderables.m_Memory.m_pMemory;
    v4 = i;
    m_pAlphaProperty = m_pMemory[v4].m_Element.m_pAlphaProperty;
    if ( m_pAlphaProperty != nullptr && CClientAlphaProperty::ComputeRenderAlpha(this: m_pAlphaProperty) != 0xFF
      || (*((_WORD *)&m_pMemory[v4].m_Element + 11) & 0x3000) != 0 )
    {
      v6 = (C_BaseEntity *)__RTDynamicCast(
                             inptr: m_pMemory[v4].m_Element.m_pRenderable,
                             VfDelta: 0,
                             SrcType: &IClientRenderable `RTTI Type Descriptor',
                             TargetType: &C_BaseEntity `RTTI Type Descriptor',
                             isReference: 0);
      v7 = v6;
      if ( v6 != nullptr )
      {
        v6->m_Collision.WorldSpaceSurroundingBounds(this: &v6->m_Collision, a2: &vecSurroundMins, a3: &vecSurroundMaxs);
        center.x = (float)(vecSurroundMaxs.x + vecSurroundMins.x) * 0.5;
        extents.x = vecSurroundMaxs.x - center.x;
        extents.y = vecSurroundMaxs.y - (float)((float)(vecSurroundMaxs.y + vecSurroundMins.y) * 0.5);
        extents.z = vecSurroundMaxs.z - (float)((float)(vecSurroundMaxs.z + vecSurroundMins.z) * 0.5);
        center.y = (float)(vecSurroundMaxs.y + vecSurroundMins.y) * 0.5;
        center.z = (float)(vecSurroundMaxs.z + vecSurroundMins.z) * 0.5;
        mins.x = -(float)(vecSurroundMaxs.x - center.x);
        mins.y = -extents.y;
        mins.z = -extents.z;
        NDebugOverlay::Box(origin: &center, &mins, maxs: &extents, r: 150, g: 150, b: 0, a: 0, flDuration: 0.0);
        DebugName = C_BaseEntity::GetDebugName(this: v7);
        NDebugOverlay::EntityTextAtPosition(
          origin: &center,
          text_offset: 0,
          text: DebugName,
          duration: 0.0,
          r: 255,
          g: 255,
          b: 255,
          a: 255);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A95E0
// Name: public: virtual enum RenderGroup_t CClientLeafSystem::GenerateRenderListEntry(class IClientRenderable __near *,struct CClientRenderablesList::CEntry __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CClientLeafSystem::GenerateRenderListEntry(
        CClientLeafSystem *this,
        IClientRenderable *pRenderable,
        CClientRenderablesList::CEntry *entryOut)
{
  unsigned __int16 i; // ax
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *v5; // esi
  CClientAlphaProperty *m_pAlphaProperty; // ecx
  char v7; // bl
  char v8; // dl
  char v9; // cl
  __int16 v11; // ax
  int nAlpha; // [esp+10h] [ebp+8h]

  for ( i = this->m_Renderables.m_Head; ; i = v5->m_Next )
  {
    if ( i >= this->m_Renderables.m_Memory.m_nAllocationCount
      || i > this->m_Renderables.m_LastAlloc.index
      || (v5 = &this->m_Renderables.m_Memory.m_pMemory[i])->m_Previous == i && v5->m_Next != i )
    {
      entryOut->m_pRenderable = nullptr;
      *(_DWORD *)&entryOut->m_iWorldListInfoLeaf = 16711680;
      return 3;
    }
    if ( v5->m_Element.m_pRenderable == pRenderable )
      break;
  }
  m_pAlphaProperty = v5->m_Element.m_pAlphaProperty;
  if ( m_pAlphaProperty != nullptr )
  {
    nAlpha = CClientAlphaProperty::ComputeRenderAlpha(this: m_pAlphaProperty);
    if ( nAlpha != 255 )
      goto LABEL_13;
  }
  else
  {
    LOBYTE(nAlpha) = -1;
  }
  if ( (*((_WORD *)&v5->m_Element + 11) & 0x3000) == 0 )
  {
    v7 = 0;
    goto LABEL_14;
  }
LABEL_13:
  v7 = 1;
LABEL_14:
  *((_BYTE *)entryOut + 7) &= ~0x40u;
  v8 = *((_BYTE *)entryOut + 7);
  entryOut->m_iWorldListInfoLeaf = 0;
  entryOut->m_pRenderable = pRenderable;
  v9 = v8 & 0x7F | (((*((_WORD *)&v5->m_Element + 11) & 0x3000) == 0x2000) << 7);
  *((_BYTE *)entryOut + 7) = v9;
  *((_BYTE *)entryOut + 7) = v9 & 0xC0 | (*((_WORD *)&v5->m_Element + 11) >> 14);
  entryOut->m_InstanceData.m_nAlpha = nAlpha;
  if ( v7 == 0 )
    return 0;
  v11 = (*((_WORD *)v5->m_Element.m_pAlphaProperty + 5) >> 5) & 0xF;
  if ( v11 == 3 || v11 == 9 )
    return 2;
  else
    return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A9720
// Name: public: void CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::EnsureCapacity(
        CBidirectionalSet<int,unsigned short,unsigned short,unsigned int> *this,
        int count)
{
  UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short> *m_pMemory; // eax
  IMemAlloc_vtbl *v4; // edx
  UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short> *v5; // eax
  UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short> *v6; // eax
  IMemAlloc_vtbl *v7; // edx
  UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short> *v8; // eax

  if ( this->m_ElementsInBucket.m_Memory.m_nAllocationCount < count
    && this->m_ElementsInBucket.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_ElementsInBucket.m_Memory.m_pMemory;
    this->m_ElementsInBucket.m_Memory.m_nAllocationCount = count;
    v4 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v5 = (UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short> *)((int (__stdcall *)(UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short> *, int))v4->Realloc_2)(a1: m_pMemory, a2: 8 * count);
    else
      v5 = (UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short> *)((int (__stdcall *)(int))v4->Alloc_2)(a1: 8 * count);
    this->m_ElementsInBucket.m_Memory.m_pMemory = v5;
  }
  this->m_ElementsInBucket.m_pElements = this->m_ElementsInBucket.m_Memory.m_pMemory;
  if ( this->m_BucketsUsedByElement.m_Memory.m_nAllocationCount >= count )
  {
    this->m_BucketsUsedByElement.m_pElements = this->m_BucketsUsedByElement.m_Memory.m_pMemory;
  }
  else
  {
    v6 = this->m_BucketsUsedByElement.m_Memory.m_pMemory;
    if ( this->m_BucketsUsedByElement.m_Memory.m_nGrowSize < 0 )
    {
      this->m_BucketsUsedByElement.m_pElements = v6;
    }
    else
    {
      this->m_BucketsUsedByElement.m_Memory.m_nAllocationCount = count;
      v7 = _g_pMemAlloc->__vftable;
      if ( v6 != nullptr )
        v8 = (UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short> *)((int (__stdcall *)(UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short> *, int))v7->Realloc_2)(a1: v6, a2: 12 * count);
      else
        v8 = (UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short> *)((int (__stdcall *)(int))v7->Alloc_2)(a1: 12 * count);
      this->m_BucketsUsedByElement.m_Memory.m_pMemory = v8;
      this->m_BucketsUsedByElement.m_pElements = v8;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A97E0
// Name: public: void CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::EnsureCapacity(
        CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int> *this,
        int count)
{
  UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short> *m_pMemory; // eax
  IMemAlloc_vtbl *v4; // edx
  UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short> *v5; // eax
  UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short> *v6; // eax
  IMemAlloc_vtbl *v7; // edx
  UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short> *v8; // eax

  if ( this->m_ElementsInBucket.m_Memory.m_nAllocationCount < count
    && this->m_ElementsInBucket.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_ElementsInBucket.m_Memory.m_pMemory;
    this->m_ElementsInBucket.m_Memory.m_nAllocationCount = count;
    v4 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v5 = (UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short> *)((int (__stdcall *)(UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short> *, int))v4->Realloc_2)(a1: m_pMemory, a2: 8 * count);
    else
      v5 = (UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short> *)((int (__stdcall *)(int))v4->Alloc_2)(a1: 8 * count);
    this->m_ElementsInBucket.m_Memory.m_pMemory = v5;
  }
  this->m_ElementsInBucket.m_pElements = this->m_ElementsInBucket.m_Memory.m_pMemory;
  if ( this->m_BucketsUsedByElement.m_Memory.m_nAllocationCount >= count )
  {
    this->m_BucketsUsedByElement.m_pElements = this->m_BucketsUsedByElement.m_Memory.m_pMemory;
  }
  else
  {
    v6 = this->m_BucketsUsedByElement.m_Memory.m_pMemory;
    if ( this->m_BucketsUsedByElement.m_Memory.m_nGrowSize < 0 )
    {
      this->m_BucketsUsedByElement.m_pElements = v6;
    }
    else
    {
      this->m_BucketsUsedByElement.m_Memory.m_nAllocationCount = count;
      v7 = _g_pMemAlloc->__vftable;
      if ( v6 != nullptr )
        v8 = (UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short> *)((int (__stdcall *)(UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short> *, int))v7->Realloc_2)(a1: v6, a2: 8 * count);
      else
        v8 = (UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short> *)((int (__stdcall *)(int))v7->Alloc_2)(a1: 8 * count);
      this->m_BucketsUsedByElement.m_Memory.m_pMemory = v8;
      this->m_BucketsUsedByElement.m_pElements = v8;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A9CA0
// Name: public: virtual int CClientLeafSystem::GetRenderableLeaves(unsigned short,int __near * const)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CClientLeafSystem::GetRenderableLeaves(CClientLeafSystem *this, int handle, int *leaves)
{
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *m_pMemory; // edx
  unsigned int v5; // ecx
  int v7; // esi
  int i; // eax
  int v9; // eax

  if ( (unsigned __int16)handle >= this->m_Renderables.m_Memory.m_nAllocationCount )
    return -1;
  if ( (unsigned __int16)handle > this->m_Renderables.m_LastAlloc.index )
    return -1;
  m_pMemory = this->m_Renderables.m_Memory.m_pMemory;
  v5 = (unsigned __int16)handle;
  if ( m_pMemory[v5].m_Previous == (unsigned __int16)handle && m_pMemory[v5].m_Next != (unsigned __int16)handle )
    return -1;
  if ( this->m_Renderables.m_Memory.m_pMemory[v5].m_Element.m_LeafList == 0xFFFF )
    return -1;
  v7 = 0;
  for ( i = *this->m_RenderablesInLeaf.m_FirstBucket(a1: handle);
        i != 0xFFFF;
        i = this->m_RenderablesInLeaf.m_BucketsUsedByElement.m_Memory.m_pMemory[v9].m_Next )
  {
    v9 = i;
    leaves[v7++] = this->m_RenderablesInLeaf.m_BucketsUsedByElement.m_Memory.m_pMemory[v9].m_Element.m_Bucket;
    if ( v7 >= 128 )
      break;
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x100A9D50
// Name: public: virtual bool CClientLeafSystem::GetRenderableLeaf(unsigned short,int __near *,int const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientLeafSystem::GetRenderableLeaf(
        CClientLeafSystem *this,
        int handle,
        int *pOutLeaf,
        const int *pInIterator,
        int *pOutIterator)
{
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *v6; // ecx
  int m_Next; // eax
  int v9; // eax

  if ( (unsigned __int16)handle >= this->m_Renderables.m_Memory.m_nAllocationCount )
    return 0;
  if ( (unsigned __int16)handle > this->m_Renderables.m_LastAlloc.index )
    return 0;
  v6 = &this->m_Renderables.m_Memory.m_pMemory[(unsigned __int16)handle];
  if ( v6->m_Previous == (unsigned __int16)handle && v6->m_Next != (unsigned __int16)handle )
    return 0;
  if ( pOutLeaf == nullptr )
    return 0;
  if ( pInIterator != nullptr )
  {
    if ( *pInIterator != 0xFFFF )
    {
      m_Next = this->m_RenderablesInLeaf.m_BucketsUsedByElement.m_Memory.m_pMemory[*pInIterator].m_Next;
      if ( m_Next != 0xFFFF )
      {
        if ( pOutIterator != nullptr )
          *pOutIterator = m_Next;
        *pOutLeaf = this->m_RenderablesInLeaf.m_BucketsUsedByElement.m_Memory.m_pMemory[m_Next].m_Element.m_Bucket;
        return 1;
      }
    }
    return 0;
  }
  v9 = *this->m_RenderablesInLeaf.m_FirstBucket(a1: handle);
  if ( v9 == 0xFFFF )
    return 0;
  *pOutLeaf = this->m_RenderablesInLeaf.m_BucketsUsedByElement.m_Memory.m_pMemory[v9].m_Element.m_Bucket;
  if ( pOutIterator != nullptr )
    *pOutIterator = v9;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A9E10
// Name: public: virtual void CClientLeafSystem::EnumerateShadowsInLeaves(int,struct WorldListLeafData_t __near *,class IClientLeafShadowEnum __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::EnumerateShadowsInLeaves(
        CClientLeafSystem *this,
        int leafCount,
        WorldListLeafData_t *pLeaves,
        IClientLeafShadowEnum *pEnum)
{
  int v4; // ebx
  int v6; // esi
  unsigned __int16 m_Next; // ax
  int v8; // ebx
  UtlLinkedListElem_t<CClientLeafSystem::ShadowInfo_t,unsigned short> *v9; // esi
  int i; // [esp+8h] [ebp-4h]

  v4 = leafCount;
  if ( leafCount != 0 )
  {
    ++this->m_ShadowEnum;
    v6 = 0;
    i = 0;
    if ( leafCount > 0 )
    {
      do
      {
        m_Next = *this->m_ShadowsInLeaf.m_FirstElement(a1: pLeaves[v6].leafIndex);
        if ( m_Next != 0xFFFF )
        {
          do
          {
            v8 = m_Next;
            v9 = &this->m_Shadows.m_Memory.m_pMemory[this->m_ShadowsInLeaf.m_ElementsInBucket.m_Memory.m_pMemory[v8].m_Element.m_Element];
            if ( v9->m_Element.m_EnumCount != this->m_ShadowEnum )
            {
              pEnum->EnumShadow(this: pEnum, a2: v9->m_Element.m_Shadow);
              v9->m_Element.m_EnumCount = this->m_ShadowEnum;
            }
            m_Next = this->m_ShadowsInLeaf.m_ElementsInBucket.m_Memory.m_pMemory[v8].m_Next;
          }
          while ( m_Next != 0xFFFF );
          v6 = i;
          v4 = leafCount;
        }
        i = ++v6;
      }
      while ( v6 < v4 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A9EC0
// Name: public: virtual int CClientLeafSystem::GetEntitiesInBox(class C_BaseEntity __near * __near *,int,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CClientLeafSystem::GetEntitiesInBox(
        CClientLeafSystem *this,
        C_BaseEntity **pEntityList,
        int listMax,
        const Vector *vWorldSpaceMins,
        const Vector *vWorldSpaceMaxs)
{
  ISpatialQuery *v6; // eax
  int v7; // ebx
  int result; // eax
  int v9; // edi
  unsigned __int16 m_Next; // ax
  int m_ShadowEnum; // ecx
  int v12; // ebx
  int m_Element; // edi
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *v14; // eax
  IClientUnknown *v15; // eax
  C_BaseEntity *v16; // eax
  int v17; // ecx
  unsigned __int16 leafList[1024]; // [esp+Ch] [ebp-80Ch] BYREF
  int leafCount; // [esp+80Ch] [ebp-Ch]
  int i; // [esp+810h] [ebp-8h]
  int totalCount; // [esp+814h] [ebp-4h]

  ++this->m_ShadowEnum;
  v6 = engine->GetBSPTreeQuery(this: engine);
  v7 = v6->ListLeavesInBox(this: v6, a2: vWorldSpaceMins, a3: vWorldSpaceMaxs, a4: leafList, a5: 1024);
  result = 0;
  v9 = 0;
  leafCount = v7;
  totalCount = 0;
  i = 0;
  if ( v7 > 0 )
  {
    do
    {
      m_Next = *this->m_RenderablesInLeaf.m_FirstElement(a1: leafList[v9]);
      if ( m_Next != 0xFFFF )
      {
        do
        {
          m_ShadowEnum = this->m_ShadowEnum;
          v12 = m_Next;
          m_Element = this->m_RenderablesInLeaf.m_ElementsInBucket.m_Memory.m_pMemory[v12].m_Element.m_Element;
          v14 = &this->m_Renderables.m_Memory.m_pMemory[m_Element];
          if ( v14->m_Element.m_EnumCount != m_ShadowEnum )
          {
            v14->m_Element.m_EnumCount = m_ShadowEnum;
            if ( IsBoxIntersectingBox(
                   boxMin1: vWorldSpaceMins,
                   boxMax1: vWorldSpaceMaxs,
                   boxMin2: &v14->m_Element.m_vecAbsMins,
                   boxMax2: &v14->m_Element.m_vecAbsMaxs) )
            {
              v15 = this->m_Renderables.m_Memory.m_pMemory[m_Element].m_Element.m_pRenderable->GetIClientUnknown(this: this->m_Renderables.m_Memory.m_pMemory[m_Element].m_Element.m_pRenderable);
              v16 = v15->GetBaseEntity(this: v15);
              if ( v16 != nullptr )
              {
                v17 = totalCount;
                pEntityList[totalCount] = v16;
                totalCount = v17 + 1;
              }
            }
          }
          m_Next = this->m_RenderablesInLeaf.m_ElementsInBucket.m_Memory.m_pMemory[v12].m_Next;
        }
        while ( m_Next != 0xFFFF );
        v9 = i;
        v7 = leafCount;
      }
      i = ++v9;
    }
    while ( v9 < v7 );
    return totalCount;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AA2F0
// Name: public: CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::~CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::~CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>(
        CBidirectionalSet<int,unsigned short,unsigned short,unsigned int> *this)
{
  CUtlLinkedList<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::RemoveAll(this: &this->m_BucketsUsedByElement);
  if ( this->m_BucketsUsedByElement.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_BucketsUsedByElement.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_BucketsUsedByElement.m_Memory.m_pMemory);
      this->m_BucketsUsedByElement.m_Memory.m_pMemory = nullptr;
    }
    this->m_BucketsUsedByElement.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::RemoveAll((CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int> > *)this);
  if ( this->m_ElementsInBucket.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ElementsInBucket.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ElementsInBucket.m_Memory.m_pMemory);
      this->m_ElementsInBucket.m_Memory.m_pMemory = nullptr;
    }
    this->m_ElementsInBucket.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AA360
// Name: public: CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::~CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::~CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>(
        CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int> *this)
{
  CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::RemoveAll(this: &this->m_BucketsUsedByElement);
  if ( this->m_BucketsUsedByElement.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_BucketsUsedByElement.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_BucketsUsedByElement.m_Memory.m_pMemory);
      this->m_BucketsUsedByElement.m_Memory.m_pMemory = nullptr;
    }
    this->m_BucketsUsedByElement.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::RemoveAll((CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int> > *)this);
  if ( this->m_ElementsInBucket.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ElementsInBucket.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ElementsInBucket.m_Memory.m_pMemory);
      this->m_ElementsInBucket.m_Memory.m_pMemory = nullptr;
    }
    this->m_ElementsInBucket.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AA3D0
// Name: public: virtual CClientLeafSystem::~CClientLeafSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::~CClientLeafSystem(CClientLeafSystem *this)
{
  IGameSystemPerFrame *v2; // [esp+8h] [ebp-4h]

  this->IClientLeafSystem::IClientLeafSystemEngine::__vftable = (CClientLeafSystem_vtbl *)&CClientLeafSystem::`vftable'{for `IClientLeafSystemEngine'};
  v2 = &this->IGameSystemPerFrame;
  this->IClientLeafSystem::IGameSystemPerFrame::IGameSystem::__vftable = (IGameSystemPerFrame_vtbl *)&CClientLeafSystem::`vftable'{for `IGameSystemPerFrame'};
  this->ISpatialLeafEnumerator::__vftable = (ISpatialLeafEnumerator_vtbl *)&CClientLeafSystem::`vftable'{for `ISpatialLeafEnumerator'};
  this->IClientAlphaPropertyMgr::__vftable = (IClientAlphaPropertyMgr_vtbl *)&CClientLeafSystem::`vftable'{for `IClientAlphaPropertyMgr'};
  CUtlMemoryPool::~CUtlMemoryPool(this: &this->m_AlphaPropertyPool);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_ViewModels);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_DirtyRenderables);
  CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::~CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>(this: &this->m_ShadowsOnRenderable);
  CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::~CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>(this: &this->m_ShadowsInLeaf);
  CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::~CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>(this: &this->m_RenderablesInLeaf);
  CUtlLinkedList<CClientLeafSystem::ShadowInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::ShadowInfo_t,unsigned short>,unsigned int>>::RemoveAll(this: &this->m_Shadows);
  if ( this->m_Shadows.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Shadows.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Shadows.m_Memory.m_pMemory);
      this->m_Shadows.m_Memory.m_pMemory = nullptr;
    }
    this->m_Shadows.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CClientLeafSystem::RenderableInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short>,unsigned int>>::RemoveAll(this: &this->m_Renderables);
  if ( this->m_Renderables.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Renderables.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Renderables.m_Memory.m_pMemory);
      this->m_Renderables.m_Memory.m_pMemory = nullptr;
    }
    this->m_Renderables.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Leaf);
  IGameSystemPerFrame::~IGameSystemPerFrame(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x100AA4C0
// Name: public: virtual char const __near * CClientLeafSystem::Name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CClientLeafSystem::Name(CClientLeafSystem *this)
{
  return "CClientLeafSystem";
}

//------------------------------------------------------------------------------
// Address: 0x100AA4D0
// Name: public: virtual void CClientLeafSystem::Update(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::Update(CClientLeafSystem *this, float frametime)
{
  *(_DWORD *)this->m_AlphaPropertyPool.m_BlobHead.m_Data = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100AA4F0
// Name: public: virtual void CClientLeafSystem::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::LevelInitPreEntity(CClientLeafSystem *this)
{
  CClientLeafSystem::ClientLeaf_t *m_pElements; // eax
  IMemAlloc_vtbl *v3; // edx
  CClientLeafSystem::ClientLeaf_t *v4; // eax
  unsigned __int16 *(__cdecl *m_FirstElement)(unsigned __int16); // eax
  unsigned __int16 *(__cdecl *v6)(unsigned __int16); // eax
  int v7; // ebx
  IClientAlphaPropertyMgr_vtbl *v8; // eax
  IMemAlloc_vtbl *v9; // edx
  IClientAlphaPropertyMgr_vtbl *v10; // eax
  int i; // ebx
  int m_nGrowSize; // edi
  CClientLeafSystem::ClientLeaf_t *m_pMemory; // eax
  IClientAlphaPropertyMgr_vtbl *v14; // ecx
  int v15; // eax
  IClientAlphaPropertyMgr_vtbl *v16; // edi

  if ( (int)this->m_Renderables.m_Memory.m_pMemory < 1024 && this->m_Renderables.m_Memory.m_nAllocationCount >= 0 )
  {
    m_pElements = this->m_Leaf.m_pElements;
    this->m_Renderables.m_Memory.m_pMemory = (UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *)1024;
    v3 = _g_pMemAlloc->__vftable;
    if ( m_pElements != nullptr )
      v4 = (CClientLeafSystem::ClientLeaf_t *)((int (__stdcall *)(CClientLeafSystem::ClientLeaf_t *, int))v3->Realloc_2)(
                                                a1: m_pElements,
                                                a2: 77824);
    else
      v4 = (CClientLeafSystem::ClientLeaf_t *)((int (__stdcall *)(int))v3->Alloc_2)(a1: 77824);
    this->m_Leaf.m_pElements = v4;
  }
  this->m_Renderables.m_LastAlloc.index = (unsigned int)this->m_Leaf.m_pElements;
  CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::EnsureCapacity(
    this: (CBidirectionalSet<int,unsigned short,unsigned short,unsigned int> *)&this->m_Shadows.m_pElements,
    count: 1024);
  CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::EnsureCapacity(
    this: (CBidirectionalSet<int,unsigned short,unsigned short,unsigned int> *)&this->m_RenderablesInLeaf.m_FirstElement,
    count: 256);
  CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::EnsureCapacity(
    this: (CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int> *)&this->m_ShadowsInLeaf.m_FirstElement,
    count: 256);
  if ( (int)this->m_DirtyRenderables.m_Memory.m_pMemory < 256
    && this->m_DirtyRenderables.m_Memory.m_nAllocationCount >= 0 )
  {
    m_FirstElement = this->m_ShadowsOnRenderable.m_FirstElement;
    this->m_DirtyRenderables.m_Memory.m_pMemory = (unsigned __int16 *)256;
    if ( m_FirstElement != nullptr )
      v6 = (unsigned __int16 *(__cdecl *)(unsigned __int16))_g_pMemAlloc->Realloc_2(
                                                              this: _g_pMemAlloc,
                                                              a2: m_FirstElement,
                                                              a3: 512);
    else
      v6 = (unsigned __int16 *(__cdecl *)(unsigned __int16))_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 512);
    this->m_ShadowsOnRenderable.m_FirstElement = v6;
  }
  this->m_DirtyRenderables.m_Size = (int)this->m_ShadowsOnRenderable.m_FirstElement;
  v7 = engine->LevelLeafCount(this: engine);
  if ( (int)this->m_Leaf.m_Memory.m_pMemory < v7 && this->m_Leaf.m_Memory.m_nAllocationCount >= 0 )
  {
    v8 = this->IClientAlphaPropertyMgr::__vftable;
    this->m_Leaf.m_Memory.m_pMemory = (CClientLeafSystem::ClientLeaf_t *)v7;
    v9 = _g_pMemAlloc->__vftable;
    if ( v8 != nullptr )
      v10 = (IClientAlphaPropertyMgr_vtbl *)((int (__stdcall *)(IClientAlphaPropertyMgr_vtbl *, int))v9->Realloc_2)(
                                              a1: v8,
                                              a2: 16 * v7);
    else
      v10 = (IClientAlphaPropertyMgr_vtbl *)((int (__stdcall *)(int))v9->Alloc_2)(a1: 16 * v7);
    this->IClientAlphaPropertyMgr::__vftable = v10;
  }
  this->m_Leaf.m_Size = (int)this->IClientAlphaPropertyMgr::__vftable;
  for ( i = v7 - 1; i >= 0; --i )
  {
    m_nGrowSize = this->m_Leaf.m_Memory.m_nGrowSize;
    m_pMemory = this->m_Leaf.m_Memory.m_pMemory;
    if ( m_nGrowSize + 1 > (int)m_pMemory )
      CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
        this: (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)&this->IClientAlphaPropertyMgr,
        num: m_nGrowSize - (_DWORD)m_pMemory + 1);
    ++this->m_Leaf.m_Memory.m_nGrowSize;
    v14 = this->IClientAlphaPropertyMgr::__vftable;
    v15 = this->m_Leaf.m_Memory.m_nGrowSize - m_nGrowSize - 1;
    this->m_Leaf.m_Size = (int)v14;
    if ( v15 > 0 )
      _V_memmove(dest: &v14[2 * m_nGrowSize + 2], src: &v14[2 * m_nGrowSize], count: 16 * v15);
    v16 = &this->IClientAlphaPropertyMgr::__vftable[2 * m_nGrowSize];
    if ( v16 != nullptr )
    {
      *v16 = (IClientAlphaPropertyMgr_vtbl)0xFFFFFFFFLL;
      v16[1] = (IClientAlphaPropertyMgr_vtbl)0xFFFFFFFFLL;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AA6A0
// Name: public: virtual void CClientLeafSystem::RenderableChanged(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::RenderableChanged(CClientLeafSystem *this, unsigned __int16 handle)
{
  CThreadFastMutex *p_m_DirtyRenderablesMutex; // ebx
  DWORD CurrentThreadId; // ecx
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *m_pMemory; // edx
  unsigned int v6; // ecx
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *v7; // eax
  __int16 v8; // cx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  unsigned __int16 *v11; // ecx
  int v12; // eax
  unsigned __int16 *v13; // eax

  p_m_DirtyRenderablesMutex = &this->m_DirtyRenderablesMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_DirtyRenderablesMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_DirtyRenderablesMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_DirtyRenderablesMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_DirtyRenderablesMutex->m_depth;
  }
  if ( handle < this->m_Renderables.m_Memory.m_nAllocationCount && handle <= this->m_Renderables.m_LastAlloc.index )
  {
    m_pMemory = this->m_Renderables.m_Memory.m_pMemory;
    v6 = handle;
    if ( m_pMemory[v6].m_Previous != handle || m_pMemory[v6].m_Next == handle )
    {
      v7 = &this->m_Renderables.m_Memory.m_pMemory[v6];
      *((_WORD *)&v7->m_Element + 11) &= ~0x20u;
      v8 = *((_WORD *)&v7->m_Element + 11);
      if ( (v8 & 2) != 0 )
      {
        if ( s_bIsInRecomputeRenderableLeaves )
        {
          _Warning(a1: "------------------------------------------------------------\n");
          _Warning(a1: "------------------------------------------------------------\n");
          _Warning(a1: "------------------------------------------------------------\n");
          _Warning(a1: "------------------------------------------------------------\n");
          _Warning(a1: "Re-entrancy found in CClientLeafSystem::RenderableChanged\n");
          _Warning(a1: "Contact Shanon or Brian\n");
          _Warning(a1: "------------------------------------------------------------\n");
          _Warning(a1: "------------------------------------------------------------\n");
          _Warning(a1: "------------------------------------------------------------\n");
          _Warning(a1: "------------------------------------------------------------\n");
        }
      }
      else
      {
        *((_WORD *)&v7->m_Element + 11) = v8 | 2;
        m_Size = this->m_DirtyRenderables.m_Size;
        m_nAllocationCount = this->m_DirtyRenderables.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<wchar_t,int>::Grow(
            this: (CUtlMemory<CUtlSymbol,int> *)&this->m_DirtyRenderables,
            num: m_Size - m_nAllocationCount + 1);
        ++this->m_DirtyRenderables.m_Size;
        v11 = this->m_DirtyRenderables.m_Memory.m_pMemory;
        v12 = this->m_DirtyRenderables.m_Size - m_Size - 1;
        this->m_DirtyRenderables.m_pElements = v11;
        if ( v12 > 0 )
          _V_memmove(dest: &v11[m_Size + 1], src: &v11[m_Size], count: 2 * v12);
        v13 = &this->m_DirtyRenderables.m_Memory.m_pMemory[m_Size];
        if ( v13 != nullptr )
          *v13 = handle;
      }
    }
  }
  if ( p_m_DirtyRenderablesMutex->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)p_m_DirtyRenderablesMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x100AA810
// Name: private: void CClientLeafSystem::AddToViewModelList(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::AddToViewModelList(CClientLeafSystem *this, unsigned __int16 handle)
{
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbol,int> *p_m_ViewModels; // esi
  int m_Size; // edi
  CUtlSymbol *m_pMemory; // ecx
  int v6; // eax
  CUtlSymbol *v7; // eax

  m_nAllocationCount = this->m_ViewModels.m_Memory.m_nAllocationCount;
  p_m_ViewModels = (CUtlMemory<CUtlSymbol,int> *)&this->m_ViewModels;
  m_Size = this->m_ViewModels.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<wchar_t,int>::Grow(this: p_m_ViewModels, num: m_Size - m_nAllocationCount + 1);
  ++p_m_ViewModels[1].m_pMemory;
  m_pMemory = p_m_ViewModels->m_pMemory;
  v6 = (int)p_m_ViewModels[1].m_pMemory - m_Size - 1;
  p_m_ViewModels[1].m_nAllocationCount = (int)p_m_ViewModels->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 2 * v6);
  v7 = &p_m_ViewModels->m_pMemory[m_Size];
  if ( v7 != nullptr )
    v7->m_Id = handle;
}

//------------------------------------------------------------------------------
// Address: 0x100AA880
// Name: public: void CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::AddElementToBucket(int,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::AddElementToBucket(
        CBidirectionalSet<int,unsigned short,unsigned short,unsigned int> *this,
        unsigned __int16 *bucket,
        int element)
{
  int v4; // eax
  unsigned int v5; // edi
  int v6; // eax
  unsigned int v7; // ebx
  int v8; // eax
  unsigned __int16 *v9; // eax
  unsigned int v10; // ecx
  unsigned __int16 *v11; // esi
  unsigned int v12; // eax
  CUtlLinkedList<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int> > *p_m_BucketsUsedByElement; // [esp+Ch] [ebp-4h]
  unsigned __int16 *firstElementInBucket; // [esp+18h] [ebp+8h]

  v4 = CUtlLinkedList<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short>,unsigned int>>::AllocInternal(
         this: &this->m_ElementsInBucket,
         multilist: true);
  v5 = 0xFFFF;
  if ( v4 != 0xFFFF )
    v5 = v4;
  p_m_BucketsUsedByElement = &this->m_BucketsUsedByElement;
  v6 = CUtlLinkedList<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::AllocInternal(
         this: &this->m_BucketsUsedByElement,
         multilist: true);
  v7 = 0xFFFF;
  if ( v6 != 0xFFFF )
    v7 = v6;
  this->m_ElementsInBucket.m_Memory.m_pMemory[v5].m_Element.m_Element = element;
  this->m_ElementsInBucket.m_Memory.m_pMemory[v5].m_Element.m_BucketListIndex = v7;
  v8 = v7;
  p_m_BucketsUsedByElement->m_Memory.m_pMemory[v8].m_Element.m_Bucket = (int)bucket;
  p_m_BucketsUsedByElement->m_Memory.m_pMemory[v8].m_Element.m_ElementListIndex = v5;
  v9 = this->m_FirstElement(a1: bucket);
  v10 = *v9;
  firstElementInBucket = v9;
  if ( (_WORD)v10 != 0xFFFF )
  {
    CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::LinkBefore(
      (CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int> > *)this,
      before: v10,
      elem: v5);
    v9 = firstElementInBucket;
  }
  *v9 = v5;
  v11 = this->m_FirstBucket(a1: element);
  v12 = *v11;
  if ( (_WORD)v12 != 0xFFFF )
    CUtlLinkedList<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::LinkBefore(
      this: p_m_BucketsUsedByElement,
      before: v12,
      elem: v7);
  *v11 = v7;
}

//------------------------------------------------------------------------------
// Address: 0x100AA940
// Name: public: void CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::RemoveElement(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::RemoveElement(
        CBidirectionalSet<int,unsigned short,unsigned short,unsigned int> *this,
        int element)
{
  unsigned int v3; // eax
  UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short> *m_pMemory; // edx
  int v5; // eax
  unsigned int m_ElementListIndex; // edi
  UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short> *v7; // ecx
  unsigned int v8; // edi
  int v9; // [esp-Ch] [ebp-20h]
  int v10; // [esp+4h] [ebp-10h]
  unsigned __int16 m_Next; // [esp+8h] [ebp-Ch]
  int bucket; // [esp+Ch] [ebp-8h]
  unsigned int i; // [esp+10h] [ebp-4h]

  v3 = *this->m_FirstBucket(a1: element);
  i = v3;
  if ( v3 != 0xFFFF )
  {
    while ( 1 )
    {
      m_pMemory = this->m_BucketsUsedByElement.m_Memory.m_pMemory;
      v5 = v3;
      m_ElementListIndex = m_pMemory[v5].m_Element.m_ElementListIndex;
      v10 = v5 * 12;
      bucket = m_pMemory[v5].m_Element.m_Bucket;
      if ( m_ElementListIndex == *this->m_FirstElement(a1: bucket) )
      {
        m_Next = this->m_ElementsInBucket.m_Memory.m_pMemory[m_ElementListIndex].m_Next;
        *this->m_FirstElement(a1: bucket) = m_Next;
      }
      CUtlLinkedList<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short>,unsigned int>>::Unlink(
        (CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int> > *)this,
        elem: m_ElementListIndex);
      this->m_ElementsInBucket.m_Memory.m_pMemory[m_ElementListIndex].m_Next = this->m_ElementsInBucket.m_FirstFree;
      v7 = this->m_BucketsUsedByElement.m_Memory.m_pMemory;
      this->m_ElementsInBucket.m_FirstFree = m_ElementListIndex;
      v8 = i;
      v9 = i;
      i = *(unsigned __int16 *)((char *)&v7->m_Next + v10);
      CUtlLinkedList<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::Unlink(
        this: &this->m_BucketsUsedByElement,
        elem: v9);
      this->m_BucketsUsedByElement.m_Memory.m_pMemory[v8].m_Next = this->m_BucketsUsedByElement.m_FirstFree;
      this->m_BucketsUsedByElement.m_FirstFree = v8;
      if ( i == 0xFFFF )
        break;
      v3 = i;
    }
  }
  *this->m_FirstBucket(a1: element) = -1;
}

//------------------------------------------------------------------------------
// Address: 0x100AAA30
// Name: public: void CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::Purge(
        CBidirectionalSet<int,unsigned short,unsigned short,unsigned int> *this)
{
  UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short> *m_pMemory; // ecx

  CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::RemoveAll((CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int> > *)this);
  if ( this->m_ElementsInBucket.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ElementsInBucket.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ElementsInBucket.m_Memory.m_pMemory);
      this->m_ElementsInBucket.m_Memory.m_pMemory = nullptr;
    }
    this->m_ElementsInBucket.m_Memory.m_nAllocationCount = 0;
  }
  this->m_ElementsInBucket.m_pElements = this->m_ElementsInBucket.m_Memory.m_pMemory;
  this->m_ElementsInBucket.m_FirstFree = 0xFFFF;
  this->m_ElementsInBucket.m_NumAlloced = 0;
  this->m_ElementsInBucket.m_LastAlloc.index = -1;
  CUtlLinkedList<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::RemoveAll(this: &this->m_BucketsUsedByElement);
  if ( this->m_BucketsUsedByElement.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_BucketsUsedByElement.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_BucketsUsedByElement.m_Memory.m_pMemory);
      this->m_BucketsUsedByElement.m_Memory.m_pMemory = nullptr;
    }
    this->m_BucketsUsedByElement.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_BucketsUsedByElement.m_Memory.m_pMemory;
  this->m_BucketsUsedByElement.m_NumAlloced = 0;
  this->m_BucketsUsedByElement.m_FirstFree = 0xFFFF;
  this->m_BucketsUsedByElement.m_LastAlloc.index = -1;
  this->m_BucketsUsedByElement.m_pElements = m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x100AAAC0
// Name: public: void CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::AddElementToBucket(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::AddElementToBucket(
        CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int> *this,
        unsigned __int16 *bucket,
        int element)
{
  int v4; // eax
  unsigned int v5; // edi
  int v6; // eax
  unsigned int v7; // ebx
  unsigned __int16 *v8; // eax
  unsigned int v9; // ecx
  unsigned __int16 *v10; // esi
  unsigned int v11; // eax
  CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int> > *p_m_BucketsUsedByElement; // [esp+Ch] [ebp-4h]
  unsigned __int16 *firstElementInBucket; // [esp+18h] [ebp+8h]

  v4 = CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short>,unsigned int>>::AllocInternal(
         this: &this->m_ElementsInBucket,
         multilist: true);
  v5 = 0xFFFF;
  if ( v4 != 0xFFFF )
    v5 = v4;
  p_m_BucketsUsedByElement = &this->m_BucketsUsedByElement;
  v6 = CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::AllocInternal(
         this: &this->m_BucketsUsedByElement,
         multilist: true);
  v7 = 0xFFFF;
  if ( v6 != 0xFFFF )
    v7 = v6;
  this->m_ElementsInBucket.m_Memory.m_pMemory[v5].m_Element.m_Element = element;
  this->m_ElementsInBucket.m_Memory.m_pMemory[v5].m_Element.m_BucketListIndex = v7;
  p_m_BucketsUsedByElement->m_Memory.m_pMemory[v7].m_Element.m_Bucket = (unsigned __int16)bucket;
  p_m_BucketsUsedByElement->m_Memory.m_pMemory[v7].m_Element.m_ElementListIndex = v5;
  v8 = this->m_FirstElement(a1: bucket);
  v9 = *v8;
  firstElementInBucket = v8;
  if ( (_WORD)v9 != 0xFFFF )
  {
    CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::LinkBefore(
      (CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int> > *)this,
      before: v9,
      elem: v5);
    v8 = firstElementInBucket;
  }
  *v8 = v5;
  v10 = this->m_FirstBucket(a1: element);
  v11 = *v10;
  if ( (_WORD)v11 != 0xFFFF )
    CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::LinkBefore(
      this: p_m_BucketsUsedByElement,
      before: v11,
      elem: v7);
  *v10 = v7;
}

//------------------------------------------------------------------------------
// Address: 0x100AAB80
// Name: public: void CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::RemoveElement(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::RemoveElement(
        CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int> *this,
        int element)
{
  unsigned int v3; // eax
  UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short> *m_pMemory; // edx
  unsigned int m_ElementListIndex; // edi
  UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short> *v6; // ecx
  unsigned int v7; // edi
  int v8; // [esp-Ch] [ebp-1Ch]
  unsigned __int16 m_Next; // [esp+4h] [ebp-Ch]
  int bucket; // [esp+8h] [ebp-8h]
  unsigned int i; // [esp+Ch] [ebp-4h]

  v3 = *this->m_FirstBucket(a1: element);
  i = v3;
  if ( v3 != 0xFFFF )
  {
    while ( 1 )
    {
      m_pMemory = this->m_BucketsUsedByElement.m_Memory.m_pMemory;
      m_ElementListIndex = m_pMemory[v3].m_Element.m_ElementListIndex;
      bucket = m_pMemory[v3].m_Element.m_Bucket;
      if ( m_ElementListIndex == *this->m_FirstElement(a1: bucket) )
      {
        m_Next = this->m_ElementsInBucket.m_Memory.m_pMemory[m_ElementListIndex].m_Next;
        *this->m_FirstElement(a1: bucket) = m_Next;
      }
      CUtlLinkedList<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short>,unsigned int>>::Unlink(
        (CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int> > *)this,
        elem: m_ElementListIndex);
      this->m_ElementsInBucket.m_Memory.m_pMemory[m_ElementListIndex].m_Next = this->m_ElementsInBucket.m_FirstFree;
      v6 = this->m_BucketsUsedByElement.m_Memory.m_pMemory;
      this->m_ElementsInBucket.m_FirstFree = m_ElementListIndex;
      v7 = i;
      v8 = i;
      i = v6[i].m_Next;
      CUtlLinkedList<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short>,unsigned int>>::Unlink(
        this: &this->m_BucketsUsedByElement,
        elem: v8);
      this->m_BucketsUsedByElement.m_Memory.m_pMemory[v7].m_Next = this->m_BucketsUsedByElement.m_FirstFree;
      this->m_BucketsUsedByElement.m_FirstFree = v7;
      if ( i == 0xFFFF )
        break;
      v3 = i;
    }
  }
  *this->m_FirstBucket(a1: element) = -1;
}

//------------------------------------------------------------------------------
// Address: 0x100AAC60
// Name: public: void CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::RemoveBucket(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::RemoveBucket(
        CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int> *this,
        int bucket)
{
  unsigned int i; // ebx
  unsigned int m_BucketListIndex; // edi
  unsigned int v5; // edi
  unsigned __int16 m_Next; // [esp+8h] [ebp-8h]
  int element; // [esp+Ch] [ebp-4h]

  for ( i = *this->m_FirstElement(a1: bucket); i != 0xFFFF; this->m_ElementsInBucket.m_FirstFree = v5 )
  {
    m_BucketListIndex = this->m_ElementsInBucket.m_Memory.m_pMemory[i].m_Element.m_BucketListIndex;
    element = this->m_ElementsInBucket.m_Memory.m_pMemory[i].m_Element.m_Element;
    if ( m_BucketListIndex == *this->m_FirstBucket(a1: element) )
    {
      m_Next = this->m_BucketsUsedByElement.m_Memory.m_pMemory[m_BucketListIndex].m_Next;
      *this->m_FirstBucket(a1: element) = m_Next;
    }
    CUtlLinkedList<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short>,unsigned int>>::Unlink(
      this: &this->m_BucketsUsedByElement,
      elem: m_BucketListIndex);
    this->m_BucketsUsedByElement.m_Memory.m_pMemory[m_BucketListIndex].m_Next = this->m_BucketsUsedByElement.m_FirstFree;
    this->m_BucketsUsedByElement.m_FirstFree = m_BucketListIndex;
    v5 = i;
    i = this->m_ElementsInBucket.m_Memory.m_pMemory[i].m_Next;
    CUtlLinkedList<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short>,unsigned int>>::Unlink(
      (CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int> > *)this,
      elem: v5);
    this->m_ElementsInBucket.m_Memory.m_pMemory[v5].m_Next = this->m_ElementsInBucket.m_FirstFree;
  }
  *this->m_FirstElement(a1: bucket) = -1;
}

//------------------------------------------------------------------------------
// Address: 0x100AAD30
// Name: public: void CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::Purge(
        CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int> *this)
{
  UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short> *m_pMemory; // ecx

  CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::RemoveAll((CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int> > *)this);
  if ( this->m_ElementsInBucket.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ElementsInBucket.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ElementsInBucket.m_Memory.m_pMemory);
      this->m_ElementsInBucket.m_Memory.m_pMemory = nullptr;
    }
    this->m_ElementsInBucket.m_Memory.m_nAllocationCount = 0;
  }
  this->m_ElementsInBucket.m_pElements = this->m_ElementsInBucket.m_Memory.m_pMemory;
  this->m_ElementsInBucket.m_FirstFree = 0xFFFF;
  this->m_ElementsInBucket.m_NumAlloced = 0;
  this->m_ElementsInBucket.m_LastAlloc.index = -1;
  CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short,1,unsigned int,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short>,unsigned int>>::RemoveAll(this: &this->m_BucketsUsedByElement);
  if ( this->m_BucketsUsedByElement.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_BucketsUsedByElement.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_BucketsUsedByElement.m_Memory.m_pMemory);
      this->m_BucketsUsedByElement.m_Memory.m_pMemory = nullptr;
    }
    this->m_BucketsUsedByElement.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_BucketsUsedByElement.m_Memory.m_pMemory;
  this->m_BucketsUsedByElement.m_NumAlloced = 0;
  this->m_BucketsUsedByElement.m_FirstFree = 0xFFFF;
  this->m_BucketsUsedByElement.m_LastAlloc.index = -1;
  this->m_BucketsUsedByElement.m_pElements = m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x100AADC0
// Name: public: CClientLeafSystem::CClientLeafSystem(void)
// Source: json
//------------------------------------------------------------------------------
CClientLeafSystem *__thiscall CClientLeafSystem::CClientLeafSystem(CClientLeafSystem *this)
{
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CClientLeafSystem::ShadowInfo_t,unsigned short> *v3; // edx
  UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short> *v4; // edx
  UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short> *v5; // edx
  UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short> *v6; // edx
  UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short> *v7; // edx
  UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short> *v8; // edx
  UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::ElementListInfo_t,unsigned short> *v9; // eax

  this->IClientLeafSystem::IGameSystemPerFrame::IGameSystem::__vftable = (IGameSystemPerFrame_vtbl *)&IGameSystemPerFrame::`vftable';
  this->ISpatialLeafEnumerator::__vftable = (ISpatialLeafEnumerator_vtbl *)&ISpatialLeafEnumerator::`vftable';
  this->IClientAlphaPropertyMgr::__vftable = (IClientAlphaPropertyMgr_vtbl *)&IClientAlphaPropertyMgr::`vftable';
  this->IClientLeafSystem::IClientLeafSystemEngine::__vftable = (CClientLeafSystem_vtbl *)&CClientLeafSystem::`vftable'{for `IClientLeafSystemEngine'};
  this->IClientLeafSystem::IGameSystemPerFrame::IGameSystem::__vftable = (IGameSystemPerFrame_vtbl *)&CClientLeafSystem::`vftable'{for `IGameSystemPerFrame'};
  this->ISpatialLeafEnumerator::__vftable = (ISpatialLeafEnumerator_vtbl *)&CClientLeafSystem::`vftable'{for `ISpatialLeafEnumerator'};
  this->IClientAlphaPropertyMgr::__vftable = (IClientAlphaPropertyMgr_vtbl *)&CClientLeafSystem::`vftable'{for `IClientAlphaPropertyMgr'};
  this->m_Leaf.m_Memory.m_pMemory = nullptr;
  this->m_Leaf.m_Memory.m_nAllocationCount = 0;
  this->m_Leaf.m_Memory.m_nGrowSize = 0;
  this->m_Leaf.m_Size = 0;
  this->m_Leaf.m_pElements = nullptr;
  this->m_Renderables.m_Memory.m_pMemory = nullptr;
  this->m_Renderables.m_Memory.m_nAllocationCount = 0;
  this->m_Renderables.m_Memory.m_nGrowSize = 0;
  this->m_Renderables.m_LastAlloc.index = -1;
  m_pMemory = this->m_Renderables.m_Memory.m_pMemory;
  this->m_Renderables.m_Head = 0xFFFF;
  this->m_Renderables.m_Tail = 0xFFFF;
  this->m_Renderables.m_FirstFree = 0xFFFF;
  this->m_Renderables.m_ElementCount = 0;
  this->m_Renderables.m_NumAlloced = 0;
  this->m_Renderables.m_pElements = m_pMemory;
  this->m_Shadows.m_Memory.m_pMemory = nullptr;
  this->m_Shadows.m_Memory.m_nAllocationCount = 0;
  this->m_Shadows.m_Memory.m_nGrowSize = 0;
  this->m_Shadows.m_LastAlloc.index = -1;
  v3 = this->m_Shadows.m_Memory.m_pMemory;
  this->m_Shadows.m_Head = 0xFFFF;
  this->m_Shadows.m_Tail = 0xFFFF;
  this->m_Shadows.m_FirstFree = 0xFFFF;
  this->m_Shadows.m_ElementCount = 0;
  this->m_Shadows.m_NumAlloced = 0;
  this->m_Shadows.m_pElements = v3;
  this->m_RenderablesInLeaf.m_ElementsInBucket.m_Memory.m_pMemory = nullptr;
  this->m_RenderablesInLeaf.m_ElementsInBucket.m_Memory.m_nAllocationCount = 0;
  this->m_RenderablesInLeaf.m_ElementsInBucket.m_Memory.m_nGrowSize = 0;
  this->m_RenderablesInLeaf.m_ElementsInBucket.m_LastAlloc.index = -1;
  v4 = this->m_RenderablesInLeaf.m_ElementsInBucket.m_Memory.m_pMemory;
  this->m_RenderablesInLeaf.m_ElementsInBucket.m_Head = 0xFFFF;
  this->m_RenderablesInLeaf.m_ElementsInBucket.m_Tail = 0xFFFF;
  this->m_RenderablesInLeaf.m_ElementsInBucket.m_FirstFree = 0xFFFF;
  this->m_RenderablesInLeaf.m_ElementsInBucket.m_ElementCount = 0;
  this->m_RenderablesInLeaf.m_ElementsInBucket.m_NumAlloced = 0;
  this->m_RenderablesInLeaf.m_ElementsInBucket.m_pElements = v4;
  this->m_RenderablesInLeaf.m_BucketsUsedByElement.m_Memory.m_pMemory = nullptr;
  this->m_RenderablesInLeaf.m_BucketsUsedByElement.m_Memory.m_nAllocationCount = 0;
  this->m_RenderablesInLeaf.m_BucketsUsedByElement.m_Memory.m_nGrowSize = 0;
  this->m_RenderablesInLeaf.m_BucketsUsedByElement.m_LastAlloc.index = -1;
  v5 = this->m_RenderablesInLeaf.m_BucketsUsedByElement.m_Memory.m_pMemory;
  this->m_RenderablesInLeaf.m_BucketsUsedByElement.m_Head = 0xFFFF;
  this->m_RenderablesInLeaf.m_BucketsUsedByElement.m_Tail = 0xFFFF;
  this->m_RenderablesInLeaf.m_BucketsUsedByElement.m_FirstFree = 0xFFFF;
  this->m_RenderablesInLeaf.m_BucketsUsedByElement.m_ElementCount = 0;
  this->m_RenderablesInLeaf.m_BucketsUsedByElement.m_NumAlloced = 0;
  this->m_RenderablesInLeaf.m_BucketsUsedByElement.m_pElements = v5;
  this->m_RenderablesInLeaf.m_FirstBucket = nullptr;
  this->m_RenderablesInLeaf.m_FirstElement = nullptr;
  this->m_ShadowsInLeaf.m_ElementsInBucket.m_Memory.m_pMemory = nullptr;
  this->m_ShadowsInLeaf.m_ElementsInBucket.m_Memory.m_nAllocationCount = 0;
  this->m_ShadowsInLeaf.m_ElementsInBucket.m_Memory.m_nGrowSize = 0;
  this->m_ShadowsInLeaf.m_ElementsInBucket.m_LastAlloc.index = -1;
  v6 = this->m_ShadowsInLeaf.m_ElementsInBucket.m_Memory.m_pMemory;
  this->m_ShadowsInLeaf.m_ElementsInBucket.m_Head = 0xFFFF;
  this->m_ShadowsInLeaf.m_ElementsInBucket.m_Tail = 0xFFFF;
  this->m_ShadowsInLeaf.m_ElementsInBucket.m_FirstFree = 0xFFFF;
  this->m_ShadowsInLeaf.m_ElementsInBucket.m_ElementCount = 0;
  this->m_ShadowsInLeaf.m_ElementsInBucket.m_NumAlloced = 0;
  this->m_ShadowsInLeaf.m_ElementsInBucket.m_pElements = v6;
  this->m_ShadowsInLeaf.m_BucketsUsedByElement.m_Memory.m_pMemory = nullptr;
  this->m_ShadowsInLeaf.m_BucketsUsedByElement.m_Memory.m_nAllocationCount = 0;
  this->m_ShadowsInLeaf.m_BucketsUsedByElement.m_Memory.m_nGrowSize = 0;
  this->m_ShadowsInLeaf.m_BucketsUsedByElement.m_LastAlloc.index = -1;
  this->m_ShadowsInLeaf.m_BucketsUsedByElement.m_Head = 0xFFFF;
  this->m_ShadowsInLeaf.m_BucketsUsedByElement.m_Tail = 0xFFFF;
  v7 = this->m_ShadowsInLeaf.m_BucketsUsedByElement.m_Memory.m_pMemory;
  this->m_ShadowsInLeaf.m_BucketsUsedByElement.m_FirstFree = 0xFFFF;
  this->m_ShadowsInLeaf.m_BucketsUsedByElement.m_ElementCount = 0;
  this->m_ShadowsInLeaf.m_BucketsUsedByElement.m_NumAlloced = 0;
  this->m_ShadowsInLeaf.m_BucketsUsedByElement.m_pElements = v7;
  this->m_ShadowsInLeaf.m_FirstBucket = nullptr;
  this->m_ShadowsInLeaf.m_FirstElement = nullptr;
  this->m_ShadowsOnRenderable.m_ElementsInBucket.m_Memory.m_pMemory = nullptr;
  this->m_ShadowsOnRenderable.m_ElementsInBucket.m_Memory.m_nAllocationCount = 0;
  this->m_ShadowsOnRenderable.m_ElementsInBucket.m_Memory.m_nGrowSize = 0;
  this->m_ShadowsOnRenderable.m_ElementsInBucket.m_LastAlloc.index = -1;
  v8 = this->m_ShadowsOnRenderable.m_ElementsInBucket.m_Memory.m_pMemory;
  this->m_ShadowsOnRenderable.m_ElementsInBucket.m_Head = 0xFFFF;
  this->m_ShadowsOnRenderable.m_ElementsInBucket.m_Tail = 0xFFFF;
  this->m_ShadowsOnRenderable.m_ElementsInBucket.m_FirstFree = 0xFFFF;
  this->m_ShadowsOnRenderable.m_ElementsInBucket.m_ElementCount = 0;
  this->m_ShadowsOnRenderable.m_ElementsInBucket.m_NumAlloced = 0;
  this->m_ShadowsOnRenderable.m_ElementsInBucket.m_pElements = v8;
  this->m_ShadowsOnRenderable.m_BucketsUsedByElement.m_Memory.m_pMemory = nullptr;
  this->m_ShadowsOnRenderable.m_BucketsUsedByElement.m_Memory.m_nAllocationCount = 0;
  this->m_ShadowsOnRenderable.m_BucketsUsedByElement.m_Memory.m_nGrowSize = 0;
  this->m_ShadowsOnRenderable.m_BucketsUsedByElement.m_LastAlloc.index = -1;
  this->m_ShadowsOnRenderable.m_BucketsUsedByElement.m_Head = 0xFFFF;
  this->m_ShadowsOnRenderable.m_BucketsUsedByElement.m_Tail = 0xFFFF;
  this->m_ShadowsOnRenderable.m_BucketsUsedByElement.m_FirstFree = 0xFFFF;
  v9 = this->m_ShadowsOnRenderable.m_BucketsUsedByElement.m_Memory.m_pMemory;
  this->m_ShadowsOnRenderable.m_BucketsUsedByElement.m_ElementCount = 0;
  this->m_ShadowsOnRenderable.m_BucketsUsedByElement.m_NumAlloced = 0;
  this->m_ShadowsOnRenderable.m_BucketsUsedByElement.m_pElements = v9;
  this->m_ShadowsOnRenderable.m_FirstBucket = nullptr;
  this->m_ShadowsOnRenderable.m_FirstElement = nullptr;
  this->m_DirtyRenderables.m_Memory.m_pMemory = nullptr;
  this->m_DirtyRenderables.m_Memory.m_nAllocationCount = 0;
  this->m_DirtyRenderables.m_Memory.m_nGrowSize = 0;
  this->m_DirtyRenderables.m_Size = 0;
  this->m_DirtyRenderables.m_pElements = nullptr;
  this->m_ViewModels.m_Memory.m_pMemory = nullptr;
  this->m_ViewModels.m_Memory.m_nAllocationCount = 0;
  this->m_ViewModels.m_Memory.m_nGrowSize = 0;
  this->m_ViewModels.m_Size = 0;
  this->m_ViewModels.m_pElements = nullptr;
  *(_WORD *)&this->m_DrawStaticProps = 257;
  CUtlMemoryPool::CUtlMemoryPool(
    this: &this->m_AlphaPropertyPool,
    blockSize: 32,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CClientAlphaProperty",
    nAlignment: 0);
  this->m_DirtyRenderablesMutex.m_ownerID = 0;
  this->m_DirtyRenderablesMutex.m_depth = 0;
  this->m_RenderablesInLeaf.m_FirstBucket = CClientLeafSystem::FirstLeafInRenderable;
  this->m_RenderablesInLeaf.m_FirstElement = (unsigned __int16 *(__cdecl *)(int))CClientLeafSystem::FirstRenderableInLeaf;
  this->m_ShadowsInLeaf.m_FirstBucket = (unsigned __int16 *(__cdecl *)(unsigned __int16))CClientLeafSystem::FirstLeafInShadow;
  this->m_ShadowsInLeaf.m_FirstElement = CClientLeafSystem::FirstShadowInLeaf;
  this->m_ShadowsOnRenderable.m_FirstBucket = CClientLeafSystem::FirstRenderableInShadow;
  this->m_ShadowsOnRenderable.m_FirstElement = CClientLeafSystem::FirstShadowOnRenderable;
  this->m_nAlternateSortCount = 0;
  this->m_nDisableShadowDepthCount = 0;
  this->m_nDisableShadowDepthCacheCount = 0;
  this->m_bDisableLeafReinsertion = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100AB0F0
// Name: public: virtual void CClientLeafSystem::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::LevelShutdownPostEntity(CClientLeafSystem *this)
{
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *m_pElements; // ecx
  int v3; // edi
  IClientAlphaPropertyMgr_vtbl *v4; // edx
  void (__thiscall ***v5)(_DWORD, int); // eax
  unsigned __int16 *(__cdecl *m_FirstElement)(unsigned __int16); // ecx
  int i; // [esp+8h] [ebp-4h]

  this->m_ShadowEnum = 0;
  this->m_nAlternateSortCount = 0;
  this->m_nDisableShadowDepthCount = 0;
  this->m_ViewModels.m_Memory.m_nGrowSize = 0;
  if ( this->m_ViewModels.m_Memory.m_nAllocationCount >= 0 )
  {
    if ( this->m_DirtyRenderables.m_pElements != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_DirtyRenderables.m_pElements);
      this->m_DirtyRenderables.m_pElements = nullptr;
    }
    this->m_ViewModels.m_Memory.m_pMemory = nullptr;
  }
  this->m_ViewModels.m_Size = (int)this->m_DirtyRenderables.m_pElements;
  CUtlLinkedList<CClientLeafSystem::RenderableInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short>,unsigned int>>::RemoveAll(this: (CUtlLinkedList<CClientLeafSystem::RenderableInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short>,unsigned int> > *)&this->m_Leaf.m_pElements);
  if ( this->m_Renderables.m_Memory.m_nAllocationCount >= 0 )
  {
    if ( this->m_Leaf.m_pElements != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Leaf.m_pElements);
      this->m_Leaf.m_pElements = nullptr;
    }
    this->m_Renderables.m_Memory.m_pMemory = nullptr;
  }
  this->m_Renderables.m_LastAlloc.index = (unsigned int)this->m_Leaf.m_pElements;
  this->m_Renderables.m_Tail = 0xFFFF;
  this->m_Renderables.m_ElementCount = 0;
  this->m_Renderables.m_NumAlloced = -1;
  CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::Purge(this: (CBidirectionalSet<int,unsigned short,unsigned short,unsigned int> *)&this->m_Shadows.m_pElements);
  CUtlLinkedList<CClientLeafSystem::ShadowInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::ShadowInfo_t,unsigned short>,unsigned int>>::RemoveAll(this: (CUtlLinkedList<CClientLeafSystem::ShadowInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::ShadowInfo_t,unsigned short>,unsigned int> > *)&this->m_Renderables.m_pElements);
  if ( this->m_Shadows.m_Memory.m_nAllocationCount >= 0 )
  {
    if ( this->m_Renderables.m_pElements != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Renderables.m_pElements);
      this->m_Renderables.m_pElements = nullptr;
    }
    this->m_Shadows.m_Memory.m_pMemory = nullptr;
  }
  m_pElements = this->m_Renderables.m_pElements;
  this->m_Shadows.m_Tail = 0xFFFF;
  this->m_Shadows.m_ElementCount = 0;
  this->m_Shadows.m_NumAlloced = -1;
  this->m_Shadows.m_LastAlloc.index = (unsigned int)m_pElements;
  i = 0;
  if ( this->m_Leaf.m_Memory.m_nGrowSize > 0 )
  {
    v3 = 12;
    do
    {
      v4 = this->IClientAlphaPropertyMgr::__vftable;
      if ( *(IClientAlphaProperty *(__thiscall **)(IClientAlphaPropertyMgr *, IClientUnknown *))((char *)&v4->CreateClientAlphaProperty
                                                                                               + v3) != nullptr )
      {
        v5 = *(void (__thiscall ****)(_DWORD, int))((char *)&v4->CreateClientAlphaProperty + v3);
        if ( v5 != nullptr )
          (**v5)(a1: v5, a2: 1);
        *(IClientAlphaProperty *(__thiscall **)(IClientAlphaPropertyMgr *, IClientUnknown *))((char *)&this->CreateClientAlphaProperty
                                                                                            + v3) = nullptr;
      }
      v3 += 16;
      ++i;
    }
    while ( i < this->m_Leaf.m_Memory.m_nGrowSize );
  }
  this->m_Leaf.m_Memory.m_nGrowSize = 0;
  if ( this->m_Leaf.m_Memory.m_nAllocationCount >= 0 )
  {
    if ( this->IClientAlphaPropertyMgr::__vftable != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->IClientAlphaPropertyMgr::__vftable);
      this->IClientAlphaPropertyMgr::__vftable = nullptr;
    }
    this->m_Leaf.m_Memory.m_pMemory = nullptr;
  }
  this->m_Leaf.m_Size = (int)this->IClientAlphaPropertyMgr::__vftable;
  CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::Purge(this: (CBidirectionalSet<int,unsigned short,unsigned short,unsigned int> *)&this->m_RenderablesInLeaf.m_FirstElement);
  CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::Purge(this: (CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int> *)&this->m_ShadowsInLeaf.m_FirstElement);
  this->m_DirtyRenderables.m_Memory.m_nGrowSize = 0;
  if ( this->m_DirtyRenderables.m_Memory.m_nAllocationCount < 0 )
  {
    this->m_DirtyRenderables.m_Size = (int)this->m_ShadowsOnRenderable.m_FirstElement;
  }
  else
  {
    if ( this->m_ShadowsOnRenderable.m_FirstElement != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ShadowsOnRenderable.m_FirstElement);
      this->m_ShadowsOnRenderable.m_FirstElement = nullptr;
    }
    m_FirstElement = this->m_ShadowsOnRenderable.m_FirstElement;
    this->m_DirtyRenderables.m_Memory.m_pMemory = nullptr;
    this->m_DirtyRenderables.m_Size = (int)m_FirstElement;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AB2B0
// Name: private: void CClientLeafSystem::AddShadowToRenderable(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::AddShadowToRenderable(
        CClientLeafSystem *this,
        unsigned __int16 renderHandle,
        unsigned __int16 shadowHandle)
{
  int v3; // edi
  int m_Flags; // ecx
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *m_pMemory; // eax

  v3 = renderHandle;
  m_Flags = this->m_Shadows.m_Memory.m_pMemory[shadowHandle].m_Element.m_Flags;
  m_pMemory = this->m_Renderables.m_Memory.m_pMemory;
  if ( (*((_WORD *)&m_pMemory[v3].m_Element + 11) & 0xC000) != 0
    && m_pMemory[renderHandle].m_Element.m_pRenderable->ShouldReceiveProjectedTextures(
         this: m_pMemory[renderHandle].m_Element.m_pRenderable,
         a2: m_Flags) )
  {
    CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::AddElementToBucket(
      this: &this->m_ShadowsOnRenderable,
      bucket: renderHandle,
      element: shadowHandle);
    ((void (__stdcall *)(_DWORD, IClientRenderable *, _DWORD))g_pClientShadowMgr->AddShadowToReceiver)(
      a1: this->m_Shadows.m_Memory.m_pMemory[shadowHandle].m_Element.m_Shadow,
      a2: this->m_Renderables.m_Memory.m_pMemory[v3].m_Element.m_pRenderable,
      a3: arrRecvType[*((unsigned __int16 *)&this->m_Renderables.m_Memory.m_pMemory[v3].m_Element + 11) >> 14]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AB340
// Name: public: void CClientLeafSystem::AddShadowToLeaf(int,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::AddShadowToLeaf(
        CClientLeafSystem *this,
        int leaf,
        unsigned __int16 shadow,
        bool bFlashlight)
{
  unsigned __int16 i; // ax
  int v6; // ebx
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *v7; // esi

  CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::AddElementToBucket(
    this: &this->m_ShadowsInLeaf,
    bucket: leaf,
    element: shadow);
  if ( bFlashlight
    || r_shadows_on_renderables_enable.m_pParent != nullptr
    && r_shadows_on_renderables_enable.m_pParent->m_Value.m_nValue != 0 )
  {
    for ( i = *this->m_RenderablesInLeaf.m_FirstElement(a1: leaf);
          i != 0xFFFF;
          i = this->m_RenderablesInLeaf.m_ElementsInBucket.m_Memory.m_pMemory[v6].m_Next )
    {
      v6 = i;
      v7 = &this->m_Renderables.m_Memory.m_pMemory[this->m_RenderablesInLeaf.m_ElementsInBucket.m_Memory.m_pMemory[v6].m_Element.m_Element];
      if ( v7->m_Element.m_EnumCount != this->m_ShadowEnum )
      {
        CClientLeafSystem::AddShadowToRenderable(
          this,
          renderHandle: this->m_RenderablesInLeaf.m_ElementsInBucket.m_Memory.m_pMemory[v6].m_Element.m_Element,
          shadowHandle: shadow);
        v7->m_Element.m_EnumCount = this->m_ShadowEnum;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AB3F0
// Name: public: virtual void CClientLeafSystem::ProjectShadow(unsigned short,int,int const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::ProjectShadow(
        CClientLeafSystem *this,
        unsigned __int16 handle,
        int nLeafCount,
        const int *pLeafList)
{
  unsigned __int16 v4; // bx
  int v6; // edi
  unsigned __int16 j; // ax
  int v8; // ecx
  int v9; // edi
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *m_pMemory; // eax
  int m_EnumCount; // edx
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *v12; // eax
  int v13; // ebx
  unsigned __int16 bucket; // [esp+8h] [ebp-14h]
  int v15; // [esp+10h] [ebp-Ch]
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *v16; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  v4 = handle;
  CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::RemoveElement(
    this: &this->m_ShadowsInLeaf,
    element: handle);
  CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::RemoveElement(
    this: &this->m_ShadowsOnRenderable,
    element: handle);
  ++this->m_ShadowEnum;
  for ( i = 0; i < nLeafCount; ++i )
  {
    v6 = pLeafList[i];
    CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::AddElementToBucket(
      this: &this->m_ShadowsInLeaf,
      bucket: v6,
      element: v4);
    if ( r_shadows_on_renderables_enable.m_pParent != nullptr
      && r_shadows_on_renderables_enable.m_pParent->m_Value.m_nValue != 0 )
    {
      for ( j = *this->m_RenderablesInLeaf.m_FirstElement(a1: v6);
            j != 0xFFFF;
            j = *(unsigned __int16 *)((char *)&this->m_RenderablesInLeaf.m_ElementsInBucket.m_Memory.m_pMemory->m_Next
                                    + v8) )
      {
        v8 = 8 * j;
        v9 = *(unsigned __int16 *)((char *)&this->m_RenderablesInLeaf.m_ElementsInBucket.m_Memory.m_pMemory->m_Element.m_Element
                                 + v8);
        bucket = *(unsigned __int16 *)((char *)&this->m_RenderablesInLeaf.m_ElementsInBucket.m_Memory.m_pMemory->m_Element.m_Element
                                     + v8);
        m_pMemory = this->m_Renderables.m_Memory.m_pMemory;
        m_EnumCount = m_pMemory[v9].m_Element.m_EnumCount;
        v12 = &m_pMemory[v9];
        v15 = v8;
        v16 = v12;
        if ( m_EnumCount != this->m_ShadowEnum )
        {
          v13 = v4;
          if ( (*((_WORD *)&v12->m_Element + 11) & 0xC000) != 0 )
          {
            if ( v12->m_Element.m_pRenderable->ShouldReceiveProjectedTextures(
                   this: v12->m_Element.m_pRenderable,
                   a2: this->m_Shadows.m_Memory.m_pMemory[v13].m_Element.m_Flags) )
            {
              CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::AddElementToBucket(
                this: &this->m_ShadowsOnRenderable,
                bucket,
                element: handle);
              ((void (__stdcall *)(_DWORD, IClientRenderable *, _DWORD))g_pClientShadowMgr->AddShadowToReceiver)(
                a1: this->m_Shadows.m_Memory.m_pMemory[v13].m_Element.m_Shadow,
                a2: this->m_Renderables.m_Memory.m_pMemory[v9].m_Element.m_pRenderable,
                a3: arrRecvType[*((unsigned __int16 *)&this->m_Renderables.m_Memory.m_pMemory[v9].m_Element + 11) >> 14]);
            }
            v8 = v15;
            v12 = v16;
          }
          v4 = handle;
          v12->m_Element.m_EnumCount = this->m_ShadowEnum;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AB570
// Name: public: virtual void CClientLeafSystem::ProjectFlashlight(unsigned short,int,int const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::ProjectFlashlight(
        CClientLeafSystem *this,
        unsigned __int16 handle,
        int nLeafCount,
        const int *pLeafList)
{
  int i; // esi

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CClientLeafSystem::ProjectFlashlight",
    a3: 0,
    a4: "Flashlight Shadows",
    a5: false,
    a6: 4);
  CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::RemoveElement(
    this: &this->m_ShadowsInLeaf,
    element: handle);
  CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::RemoveElement(
    this: &this->m_ShadowsOnRenderable,
    element: handle);
  ++this->m_ShadowEnum;
  for ( i = 0; i < nLeafCount; ++i )
    CClientLeafSystem::AddShadowToLeaf(this, leaf: pLeafList[i], shadow: handle, bFlashlight: true);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x100AB5F0
// Name: private: void CClientLeafSystem::AddRenderableToLeaf(int,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::AddRenderableToLeaf(
        CClientLeafSystem *this,
        int leaf,
        unsigned __int16 renderable,
        bool bReceiveShadows)
{
  int m_nValue; // eax
  IMatRenderContext *v7; // eax
  IMatRenderContext *m_pObject; // edi
  unsigned __int16 m_Next; // ax
  int v10; // ebx
  UtlLinkedListElem_t<CClientLeafSystem::ShadowInfo_t,unsigned short> *v11; // edi
  unsigned __int16 v12; // ax
  UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short> *m_pMemory; // edx
  unsigned int v14; // ebx
  UtlLinkedListElem_t<CClientLeafSystem::ShadowInfo_t,unsigned short> *v15; // edi
  bool bShadowsOnRenderables_3; // [esp+13h] [ebp+Bh]
  CMatRenderContextPtr pRenderContext; // [esp+18h] [ebp+10h]

  CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::AddElementToBucket(
    this: &this->m_RenderablesInLeaf,
    bucket: leaf,
    element: renderable);
  if ( r_shadows_on_renderables_enable.m_pParent != nullptr )
    m_nValue = r_shadows_on_renderables_enable.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  bShadowsOnRenderables_3 = m_nValue != 0;
  if ( bReceiveShadows )
  {
    v7 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    m_pObject = v7;
    pRenderContext.m_pObject = v7;
    if ( v7 != nullptr )
      v7->BeginRender(this: v7);
    if ( bShadowsOnRenderables_3 )
    {
      m_Next = *this->m_ShadowsInLeaf.m_FirstElement(a1: leaf);
      if ( m_Next == 0xFFFF )
        goto LABEL_19;
      do
      {
        v10 = m_Next;
        v11 = &this->m_Shadows.m_Memory.m_pMemory[this->m_ShadowsInLeaf.m_ElementsInBucket.m_Memory.m_pMemory[v10].m_Element.m_Element];
        if ( v11->m_Element.m_EnumCount != this->m_ShadowEnum )
        {
          CClientLeafSystem::AddShadowToRenderable(
            this,
            renderHandle: renderable,
            shadowHandle: this->m_ShadowsInLeaf.m_ElementsInBucket.m_Memory.m_pMemory[v10].m_Element.m_Element);
          v11->m_Element.m_EnumCount = this->m_ShadowEnum;
        }
        m_Next = this->m_ShadowsInLeaf.m_ElementsInBucket.m_Memory.m_pMemory[v10].m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    else
    {
      v12 = *this->m_ShadowsInLeaf.m_FirstElement(a1: leaf);
      if ( v12 == 0xFFFF )
        goto LABEL_19;
      do
      {
        m_pMemory = this->m_ShadowsInLeaf.m_ElementsInBucket.m_Memory.m_pMemory;
        v14 = v12;
        v15 = &this->m_Shadows.m_Memory.m_pMemory[m_pMemory[v14].m_Element.m_Element];
        if ( (v15->m_Element.m_Flags & 5) != 0 && v15->m_Element.m_EnumCount != this->m_ShadowEnum )
        {
          CClientLeafSystem::AddShadowToRenderable(
            this,
            renderHandle: renderable,
            shadowHandle: m_pMemory[v14].m_Element.m_Element);
          v15->m_Element.m_EnumCount = this->m_ShadowEnum;
        }
        v12 = this->m_ShadowsInLeaf.m_ElementsInBucket.m_Memory.m_pMemory[v14].m_Next;
      }
      while ( v12 != 0xFFFF );
    }
    m_pObject = pRenderContext.m_pObject;
LABEL_19:
    if ( m_pObject != nullptr )
    {
      m_pObject->EndRender(this: m_pObject);
      m_pObject->Release(this: m_pObject);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AB760
// Name: public: void CClientLeafSystem::AddRenderableToLeaves(unsigned short,int,unsigned short __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::AddRenderableToLeaves(
        CClientLeafSystem *this,
        unsigned __int16 handle,
        int nLeafCount,
        unsigned __int16 *pLeaves,
        bool bReceiveShadows)
{
  int v5; // edx
  int v6; // eax
  int v8; // edi
  int m_nValue; // eax
  IMatRenderContext *v10; // ebx
  unsigned __int16 m_Next; // ax
  UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short> *m_pMemory; // edx
  unsigned int v13; // ebx
  UtlLinkedListElem_t<CClientLeafSystem::ShadowInfo_t,unsigned short> *v14; // edi
  UtlLinkedListElem_t<CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::BucketListInfo_t,unsigned short> *v15; // edx
  unsigned int v16; // ebx
  UtlLinkedListElem_t<CClientLeafSystem::ShadowInfo_t,unsigned short> *v17; // edi
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *v18; // edi
  int j; // [esp+8h] [ebp-Ch]
  IMatRenderContext *v20; // [esp+Ch] [ebp-8h]
  bool v21; // [esp+13h] [ebp-1h]

  v5 = nLeafCount;
  v6 = 0;
  j = 0;
  while ( v6 < nLeafCount )
  {
    v8 = pLeaves[v6];
    CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::AddElementToBucket(
      this: &this->m_RenderablesInLeaf,
      bucket: v8,
      element: handle);
    if ( r_shadows_on_renderables_enable.m_pParent != nullptr )
      m_nValue = r_shadows_on_renderables_enable.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    v21 = m_nValue != 0;
    if ( !bReceiveShadows )
      goto LABEL_22;
    v10 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
    v20 = v10;
    if ( v10 != nullptr )
      v10->BeginRender(this: v10);
    m_Next = *this->m_ShadowsInLeaf.m_FirstElement(a1: v8);
    if ( v21 )
    {
      if ( m_Next == 0xFFFF )
        goto LABEL_20;
      do
      {
        m_pMemory = this->m_ShadowsInLeaf.m_ElementsInBucket.m_Memory.m_pMemory;
        v13 = m_Next;
        v14 = &this->m_Shadows.m_Memory.m_pMemory[m_pMemory[v13].m_Element.m_Element];
        if ( v14->m_Element.m_EnumCount != this->m_ShadowEnum )
        {
          CClientLeafSystem::AddShadowToRenderable(
            this,
            renderHandle: handle,
            shadowHandle: m_pMemory[v13].m_Element.m_Element);
          v14->m_Element.m_EnumCount = this->m_ShadowEnum;
        }
        m_Next = this->m_ShadowsInLeaf.m_ElementsInBucket.m_Memory.m_pMemory[v13].m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    else
    {
      if ( m_Next == 0xFFFF )
        goto LABEL_20;
      do
      {
        v15 = this->m_ShadowsInLeaf.m_ElementsInBucket.m_Memory.m_pMemory;
        v16 = m_Next;
        v17 = &this->m_Shadows.m_Memory.m_pMemory[v15[v16].m_Element.m_Element];
        if ( (v17->m_Element.m_Flags & 5) != 0 && v17->m_Element.m_EnumCount != this->m_ShadowEnum )
        {
          CClientLeafSystem::AddShadowToRenderable(
            this,
            renderHandle: handle,
            shadowHandle: v15[v16].m_Element.m_Element);
          v17->m_Element.m_EnumCount = this->m_ShadowEnum;
        }
        m_Next = this->m_ShadowsInLeaf.m_ElementsInBucket.m_Memory.m_pMemory[v16].m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v10 = v20;
LABEL_20:
    if ( v10 != nullptr )
    {
      v10->EndRender(this: v10);
      v10->Release(this: v10);
    }
LABEL_22:
    v5 = nLeafCount;
    v6 = j + 1;
    j = v6;
  }
  v18 = &this->m_Renderables.m_Memory.m_pMemory[handle];
  v18->m_Element.m_Area = ((int (__stdcall *)(unsigned __int16 *, int))engine->GetLeavesArea)(a1: pLeaves, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x100AB910
// Name: public: virtual void CClientLeafSystem::AddRenderableToLeaves(unsigned short,int,unsigned short __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::AddRenderableToLeaves(
        CClientLeafSystem *this,
        unsigned __int16 handle,
        int nLeafCount,
        unsigned __int16 *pLeaves)
{
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *v6; // eax
  bool bReceiveShadows; // [esp+10h] [ebp+8h]

  v6 = &this->m_Renderables.m_Memory.m_pMemory[handle];
  bReceiveShadows = (*((_WORD *)&v6->m_Element + 11) & 0xC000) != 0
                 && v6->m_Element.m_pRenderable->ShouldReceiveProjectedTextures(
                      this: v6->m_Element.m_pRenderable,
                      a2: 7);
  CClientLeafSystem::AddRenderableToLeaves(this, handle, nLeafCount, pLeaves, bReceiveShadows);
}

//------------------------------------------------------------------------------
// Address: 0x100AB960
// Name: public: virtual bool CClientLeafSystem::EnumerateLeaf(int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientLeafSystem::EnumerateLeaf(CClientLeafSystem *this, int leaf, int context)
{
  _WORD *v5; // eax
  _DWORD *v7; // eax
  char bReceiveShadows; // [esp+10h] [ebp+Ch]

  if ( (unsigned __int8)_ThreadInMainThread(a1: this) != 0 )
  {
    v5 = (_WORD *)(this->m_Leaf.m_Size + 76 * *(unsigned __int16 *)(context + 4));
    if ( (v5[11] & 0xC000) != 0 )
      bReceiveShadows = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)v5 + 80))(a1: *(_DWORD *)v5, a2: 7);
    else
      bReceiveShadows = 0;
    CClientLeafSystem::AddRenderableToLeaf(
      this: (CClientLeafSystem *)((char *)this - 8),
      leaf,
      renderable: *(_WORD *)(context + 4),
      bReceiveShadows);
    return 1;
  }
  else
  {
    v7 = MemAlloc_Alloc(nSize: 8u);
    *v7 = leaf;
    v7[1] = *(_DWORD *)context;
    *(_DWORD *)context = v7;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AB9E0
// Name: private: void CClientLeafSystem::InsertIntoTree(unsigned short __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::InsertIntoTree(
        CClientLeafSystem *this,
        unsigned __int16 *handle,
        const Vector *absMins,
        const Vector *absMaxs)
{
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *v5; // esi
  ISpatialQuery *v6; // eax
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *v7; // eax
  char *Classname; // ebx
  int v9; // eax
  C_BaseEntity *v10; // eax
  char *v11; // eax
  const char *Name; // eax
  unsigned __int16 leafList[1024]; // [esp+Ch] [ebp-918h] BYREF
  char pTemp[256]; // [esp+80Ch] [ebp-118h] BYREF
  con_nprint_s np; // [esp+90Ch] [ebp-18h] BYREF
  int leafCount; // [esp+930h] [ebp+Ch]
  bool bReceiveShadows; // [esp+934h] [ebp+10h]

  v5 = &this->m_Renderables.m_Memory.m_pMemory[*handle];
  v5->m_Element.m_vecBloatedAbsMins = *absMins;
  v5->m_Element.m_vecBloatedAbsMaxs = *absMaxs;
  ++this->m_ShadowEnum;
  v6 = engine->GetBSPTreeQuery(this: engine);
  leafCount = v6->ListLeavesInBox(this: v6, a2: absMins, a3: absMaxs, a4: leafList, a5: 1024);
  v7 = &this->m_Renderables.m_Memory.m_pMemory[*handle];
  bReceiveShadows = (*((_WORD *)&v7->m_Element + 11) & 0xC000) != 0
                 && v7->m_Element.m_pRenderable->ShouldReceiveProjectedTextures(
                      this: v7->m_Element.m_pRenderable,
                      a2: 7);
  if ( cl_leafsystemvis.m_pParent != nullptr && cl_leafsystemvis.m_pParent->m_Value.m_nValue != 0 )
  {
    Classname = "<unknown renderable>";
    v9 = (int)v5->m_Element.m_pRenderable->GetIClientUnknown(this: v5->m_Element.m_pRenderable);
    v10 = (C_BaseEntity *)(*(int (__thiscall **)(int))(*(_DWORD *)v9 + 28))(a1: v9);
    if ( v10 != nullptr )
    {
      Classname = C_BaseEntity::GetClassname(this: v10);
    }
    else
    {
      v11 = (char *)__RTDynamicCast(
                      inptr: v5->m_Element.m_pRenderable,
                      VfDelta: 0,
                      SrcType: &IClientRenderable `RTTI Type Descriptor',
                      TargetType: &CNewParticleEffect `RTTI Type Descriptor',
                      isReference: 0);
      if ( v11 != nullptr )
      {
        Name = CParticleCollection::GetName(this: (CParticleCollection *)(v11 + 16));
        V_snprintf(pDest: pTemp, maxLen: 0x100u, pFormat: "ps: %s", Name);
        Classname = pTemp;
      }
      else if ( __RTDynamicCast(
                  inptr: v5->m_Element.m_pRenderable,
                  VfDelta: 0,
                  SrcType: &IClientRenderable `RTTI Type Descriptor',
                  TargetType: &CParticleEffectBinding `RTTI Type Descriptor',
                  isReference: 0) != nullptr )
      {
        Classname = "<old particle system>";
      }
    }
    np.index = this->m_nDebugIndex;
    this->m_nDebugIndex = np.index + 1;
    np.color[0] = 1.0;
    np.time_to_live = 0.1;
    np.fixed_width_font = true;
    np.color[1] = 0.80000001;
    np.color[2] = 0.1;
    engine->Con_NXPrintf(this: engine, a2: &np, a3: "%s", Classname);
  }
  CClientLeafSystem::AddRenderableToLeaves(
    this,
    handle: *handle,
    nLeafCount: leafCount,
    pLeaves: leafList,
    bReceiveShadows);
}

//------------------------------------------------------------------------------
// Address: 0x100ABBB0
// Name: private: void CClientLeafSystem::RemoveFromTree(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::RemoveFromTree(CClientLeafSystem *this, unsigned __int16 handle)
{
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *v3; // edx

  CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::RemoveElement(
    this: &this->m_RenderablesInLeaf,
    element: handle);
  CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::RemoveBucket(
    this: &this->m_ShadowsOnRenderable,
    bucket: handle);
  v3 = &this->m_Renderables.m_Memory.m_pMemory[handle];
  switch ( *((unsigned __int16 *)&v3->m_Element + 11) >> 14 )
  {
    case 1:
      g_pClientShadowMgr->RemoveAllShadowsFromReceiver(
        this: g_pClientShadowMgr,
        a2: v3->m_Element.m_pRenderable,
        a3: SHADOW_RECEIVER_STUDIO_MODEL);
      break;
    case 2:
      g_pClientShadowMgr->RemoveAllShadowsFromReceiver(
        this: g_pClientShadowMgr,
        a2: v3->m_Element.m_pRenderable,
        a3: SHADOW_RECEIVER_STATIC_PROP);
      break;
    case 3:
      g_pClientShadowMgr->RemoveAllShadowsFromReceiver(
        this: g_pClientShadowMgr,
        a2: v3->m_Element.m_pRenderable,
        a3: SHADOW_RECEIVER_BRUSH_MODEL);
      break;
    default:
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ABC30
// Name: public: virtual void CClientLeafSystem::CollateViewModelRenderables(class CViewModelRenderablesList __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::CollateViewModelRenderables(
        CClientLeafSystem *this,
        CViewModelRenderablesList *pList)
{
  CClientLeafSystem *v2; // ebx
  bool v3; // al
  int v5; // ecx
  int v6; // esi
  CClientAlphaProperty *v7; // ecx
  unsigned __int8 v8; // bl
  CViewModelRenderablesList::CEntry *v9; // eax
  CViewModelRenderablesList::CEntry *v10; // eax
  CViewModelRenderablesList::CEntry *v11; // eax
  bool nSlotMask; // [esp+Ch] [ebp-8h]
  bool bIsSplitScreenActive; // [esp+13h] [ebp-1h]
  int i; // [esp+1Ch] [ebp+8h]

  v2 = this;
  v3 = engine->IsSplitScreenActive(this: engine);
  bIsSplitScreenActive = v3;
  nSlotMask = v3;
  v5 = v2->m_ViewModels.m_Size - 1;
  i = v5;
  if ( v5 >= 0 )
  {
    while ( 1 )
    {
      v6 = (int)&v2->m_Renderables.m_Memory.m_pMemory[v2->m_ViewModels.m_Memory.m_pMemory[v5]];
      if ( !v3 || ((*(unsigned __int16 *)(v6 + 22) >> 10) & 3 & nSlotMask) != 0 )
        break;
LABEL_14:
      v5 = --i;
      if ( i < 0 )
        return;
      v2 = this;
      v3 = bIsSplitScreenActive;
    }
    v7 = *(CClientAlphaProperty **)(v6 + 4);
    if ( v7 != nullptr )
    {
      v8 = CClientAlphaProperty::ComputeRenderAlpha(this: v7);
      if ( v8 != 255 )
      {
LABEL_11:
        v10 = &pList->m_RenderGroups[1].m_Memory.m_pMemory[CUtlVector<CViewModelRenderablesList::CEntry,CUtlMemoryFixedGrowable<CViewModelRenderablesList::CEntry,32,int>>::InsertBefore(
                                                             this: &pList->m_RenderGroups[1],
                                                             elem: pList->m_RenderGroups[1].m_Size)];
        v10->m_pRenderable = *(IClientRenderable **)v6;
        v10->m_InstanceData.m_nAlpha = v8;
        if ( (*(_WORD *)(v6 + 22) & 0x3000) == 0x2000 )
        {
          v10->m_InstanceData.m_bTwoPass = 1;
          v11 = &pList->m_RenderGroups[0].m_Memory.m_pMemory[CUtlVector<CViewModelRenderablesList::CEntry,CUtlMemoryFixedGrowable<CViewModelRenderablesList::CEntry,32,int>>::InsertBefore(
                                                               this: (CUtlVector<CViewModelRenderablesList::CEntry,CUtlMemoryFixedGrowable<CViewModelRenderablesList::CEntry,32,int> > *)pList,
                                                               elem: pList->m_RenderGroups[0].m_Size)];
          v11->m_pRenderable = *(IClientRenderable **)v6;
          v11->m_InstanceData = (ViewmodelRenderableInstance_t)511;
        }
        else
        {
          v10->m_InstanceData.m_bTwoPass = 0;
        }
        goto LABEL_14;
      }
    }
    else
    {
      v8 = -1;
    }
    if ( (*(_WORD *)(v6 + 22) & 0x3000) == 0 )
    {
      v9 = &pList->m_RenderGroups[0].m_Memory.m_pMemory[CUtlVector<CViewModelRenderablesList::CEntry,CUtlMemoryFixedGrowable<CViewModelRenderablesList::CEntry,32,int>>::InsertBefore(
                                                          this: (CUtlVector<CViewModelRenderablesList::CEntry,CUtlMemoryFixedGrowable<CViewModelRenderablesList::CEntry,32,int> > *)pList,
                                                          elem: pList->m_RenderGroups[0].m_Size)];
      v9->m_pRenderable = *(IClientRenderable **)v6;
      v9->m_InstanceData = (ViewmodelRenderableInstance_t)255;
      goto LABEL_14;
    }
    goto LABEL_11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ABD70
// Name: public: virtual void CClientLeafSystem::BuildRenderablesList(struct SetupRenderInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::BuildRenderablesList(CClientLeafSystem *this, const SetupRenderInfo_t *info)
{
  const SetupRenderInfo_t *v3; // edi
  CClientRenderablesList *m_pRenderList; // eax
  int m_Size; // eax
  bool v6; // zf
  unsigned int m_Head; // esi
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *m_pMemory; // eax
  int v9; // esi
  CClientLeafSystem::RenderableInfo_t **v10; // esi
  int Duplicates; // eax
  int StaticProps; // edi
  int v13; // edx
  int i; // ecx
  CClientLeafSystem::RenderableInfo_t *v15; // eax
  WorldListInfo_t *m_pWorldListInfo; // ecx
  int leafIndex; // esi
  unsigned __int16 v18; // cx
  int m_nAllocationCount; // edx
  int v20; // ecx
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *v21; // esi
  int v22; // edi
  CClientLeafSystem::RenderableInfo_t *v23; // eax
  IMemAlloc_vtbl *v24; // edx
  CClientLeafSystem::RenderableInfo_t **v25; // edi
  int DisableShadowDepthRenderables; // eax
  void *v27; // esp
  int CulledRenderables; // eax
  CClientLeafSystem::RenderableInfo_t *v29; // edi
  int OccludedRenderables; // eax
  CClientLeafSystem::RenderableInfo_t **v31; // eax
  float x; // eax
  CClientLeafSystem::BuildRenderListInfo_t v33; // [esp+Ch] [ebp-A050h] BYREF
  _BYTE v34[32768]; // [esp+28h] [ebp-A034h] BYREF
  int nDetailCount; // [esp+8028h] [ebp-2034h]
  float v36; // [esp+802Ch] [ebp-2030h]
  CUtlVector<CClientLeafSystem::RenderableInfo_t *,CUtlMemoryFixedGrowable<CClientLeafSystem::RenderableInfo_t *,2048,int> > v37; // [esp+8030h] [ebp-202Ch] BYREF
  unsigned __int8 *v38; // [esp+A048h] [ebp-14h]
  int v39; // [esp+A04Ch] [ebp-10h]
  int num; // [esp+A050h] [ebp-Ch]
  CClientLeafSystem::RenderableInfo_t *v41; // [esp+A054h] [ebp-8h] BYREF
  CClientLeafSystem::RenderableInfo_t *src; // [esp+A058h] [ebp-4h] BYREF
  int savedregs; // [esp+A05Ch] [ebp+0h] BYREF

  if ( r_highlight_translucent_renderables.m_pParent != nullptr
    && r_highlight_translucent_renderables.m_pParent->m_Value.m_nValue != 0 )
  {
    CClientLeafSystem::HighlightAllTranslucentRenderables(this);
  }
  v3 = info;
  if ( (*((_BYTE *)info + 48) & 4) != 0
    && r_fastreflectionfastpath.m_pParent != nullptr
    && r_fastreflectionfastpath.m_pParent->m_Value.m_nValue != 0 )
  {
    CClientLeafSystem::BuildRenderablesListForFastReflections(this, info);
  }
  else
  {
    LODWORD(v33.m_vecMaxs.x) = v34;
    m_pRenderList = info->m_pRenderList;
    v36 = COERCE_FLOAT(v34);
    LODWORD(v33.m_vecMaxs.y) = 2048;
    v33.m_vecMaxs.z = NAN;
    *(_DWORD *)&v33.m_nArea = 2048;
    nDetailCount = 0;
    *(float *)&src = g_pDetailObjectSystem->ComputeDetailFadeInfo(
                       this: g_pDetailObjectSystem,
                       a2: &m_pRenderList->m_DetailFade);
    ((void (__stdcall *)(Vector *, const SetupRenderInfo_t *, CClientLeafSystem::RenderableInfo_t *, DistanceFadeInfo_t *))g_pDetailObjectSystem->BuildRenderingData)(
      a1: &v33.m_vecMaxs,
      a2: info,
      a3: src,
      a4: &info->m_pRenderList->m_DetailFade);
    m_Size = 0;
    v6 = info->m_nViewID == 1;
    v37.m_Memory.m_pMemory = v37.m_Memory.m_pFixedMemory;
    v37.m_Memory.m_nAllocationCount = 2048;
    v37.m_Memory.m_nGrowSize = -1;
    v37.m_Memory.m_nMallocGrowSize = 2048;
    v37.m_Size = 0;
    v37.m_pElements = v37.m_Memory.m_pFixedMemory;
    if ( !v6 && r_drawallrenderables.m_pParent != nullptr && r_drawallrenderables.m_pParent->m_Value.m_nValue != 0 )
    {
      src = (CClientLeafSystem::RenderableInfo_t *)((2 * info->m_pWorldListInfo->m_pLeafDataList->leafIndex) | 1);
      CUtlVector<CClientLeafSystem::RenderableInfo_t *,CUtlMemoryFixedGrowable<CClientLeafSystem::RenderableInfo_t *,2048,int>>::InsertBefore(
        this: &v37,
        elem: 0,
        &src);
      m_Head = this->m_Renderables.m_Head;
      if ( m_Head != 0xFFFF )
      {
        m_pMemory = this->m_Renderables.m_Memory.m_pMemory;
        do
        {
          v9 = m_Head;
          src = &m_pMemory[v9].m_Element;
          CUtlVector<CClientLeafSystem::RenderableInfo_t *,CUtlMemoryFixedGrowable<CClientLeafSystem::RenderableInfo_t *,2048,int>>::InsertBefore(
            this: &v37,
            elem: v37.m_Size,
            &src);
          m_pMemory = this->m_Renderables.m_Memory.m_pMemory;
          m_Head = m_pMemory[v9].m_Next;
        }
        while ( m_Head != 0xFFFF );
      }
      m_Size = v37.m_Size;
    }
    else
    {
      m_pWorldListInfo = info->m_pWorldListInfo;
      *(float *)&src = 0.0;
      if ( m_pWorldListInfo->m_LeafCount > 0 )
      {
        do
        {
          leafIndex = m_pWorldListInfo->m_pLeafDataList[(_DWORD)src].leafIndex;
          v41 = (CClientLeafSystem::RenderableInfo_t *)((2 * leafIndex) | 1);
          CUtlVector<CClientLeafSystem::RenderableInfo_t *,CUtlMemoryFixedGrowable<CClientLeafSystem::RenderableInfo_t *,2048,int>>::InsertBefore(
            this: &v37,
            elem: m_Size,
            src: &v41);
          v18 = *this->m_RenderablesInLeaf.m_FirstElement(a1: leafIndex);
          m_Size = v37.m_Size;
          if ( v18 != 0xFFFF )
          {
            m_nAllocationCount = v37.m_Memory.m_nAllocationCount;
            do
            {
              v20 = v18;
              v21 = &this->m_Renderables.m_Memory.m_pMemory[this->m_RenderablesInLeaf.m_ElementsInBucket.m_Memory.m_pMemory[v20].m_Element.m_Element];
              v39 = v20 * 8;
              v22 = m_Size;
              if ( m_Size + 1 > m_nAllocationCount )
              {
                num = m_Size - m_nAllocationCount + 1;
                if ( v37.m_Memory.m_nGrowSize < 0 )
                {
                  v37.m_Memory.m_nGrowSize = v37.m_Memory.m_nMallocGrowSize;
                  if ( m_nAllocationCount != 0 )
                  {
                    v23 = (CClientLeafSystem::RenderableInfo_t *)(4 * m_nAllocationCount);
                    v24 = _g_pMemAlloc->__vftable;
                    v41 = v23;
                    v38 = (unsigned __int8 *)v24->Alloc_2(this: _g_pMemAlloc, a2: (unsigned int)v23);
                    memcpy(dst: v38, src: (unsigned __int8 *)v37.m_Memory.m_pMemory, count: (unsigned int)v41);
                    v37.m_Memory.m_pMemory = (CClientLeafSystem::RenderableInfo_t **)v38;
                  }
                  else
                  {
                    v37.m_Memory.m_pMemory = nullptr;
                  }
                }
                CUtlMemory<CChoreoActor *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&v37, num);
                m_Size = v37.m_Size;
                m_nAllocationCount = v37.m_Memory.m_nAllocationCount;
              }
              ++m_Size;
              v37.m_pElements = v37.m_Memory.m_pMemory;
              v37.m_Size = m_Size;
              if ( m_Size - v22 - 1 > 0 )
              {
                _V_memmove(
                  dest: &v37.m_Memory.m_pMemory[v22 + 1],
                  src: &v37.m_Memory.m_pMemory[v22],
                  count: 4 * (m_Size - v22 - 1));
                m_Size = v37.m_Size;
                m_nAllocationCount = v37.m_Memory.m_nAllocationCount;
              }
              v25 = &v37.m_Memory.m_pMemory[v22];
              if ( v25 != nullptr )
              {
                *v25 = &v21->m_Element;
                m_Size = v37.m_Size;
                m_nAllocationCount = v37.m_Memory.m_nAllocationCount;
              }
              v18 = *(unsigned __int16 *)((char *)&this->m_RenderablesInLeaf.m_ElementsInBucket.m_Memory.m_pMemory->m_Next
                                        + v39);
            }
            while ( v18 != 0xFFFF );
            v3 = info;
          }
          m_pWorldListInfo = v3->m_pWorldListInfo;
          src = (CClientLeafSystem::RenderableInfo_t *)((char *)src + 1);
        }
        while ( (int)src < m_pWorldListInfo->m_LeafCount );
      }
    }
    v10 = v37.m_Memory.m_pMemory;
    Duplicates = CClientLeafSystem::ExtractDuplicates(
                   this,
                   nFrameNumber: v3->m_nRenderFrame,
                   nCount: m_Size,
                   ppRenderables: v37.m_Memory.m_pMemory);
    StaticProps = CClientLeafSystem::ExtractStaticProps(this, nCount: Duplicates, ppRenderables: v10);
    if ( (*((_BYTE *)info + 48) & 4) != 0 )
    {
      v13 = 0;
      for ( i = 0; i < StaticProps; ++i )
      {
        v15 = v10[i];
        if ( ((unsigned __int8)v15 & 1) != 0 || *((char *)v15 + 22) < 0 )
          v10[v13++] = v15;
        else
          --v15->m_nRenderFrame;
      }
      StaticProps = v13;
    }
    if ( info->m_nViewID == 7 )
    {
      DisableShadowDepthRenderables = CClientLeafSystem::ExtractDisableShadowDepthRenderables(
                                        this,
                                        nCount: StaticProps,
                                        ppRenderables: v10);
      StaticProps = DisableShadowDepthRenderables;
      if ( (*((_BYTE *)info + 48) & 8) != 0 )
        StaticProps = CClientLeafSystem::ExtractDisableShadowDepthCacheRenderables(
                        this,
                        nCount: DisableShadowDepthRenderables,
                        ppRenderables: v10);
    }
    if ( (*((_BYTE *)info + 48) & 2) == 0 )
      StaticProps = CClientLeafSystem::ExtractTranslucentRenderables(this, nCount: StaticProps, ppRenderables: v10);
    v27 = alloca(28 * StaticProps);
    *(float *)&src = COERCE_FLOAT(&v33);
    CClientLeafSystem::ComputeBounds(this, nCount: StaticProps, ppRenderables: v10, pRLInfo: &v33);
    CulledRenderables = CClientLeafSystem::ExtractCulledRenderables(
                          this,
                          nCount: StaticProps,
                          ppRenderables: v10,
                          pRLInfo: (CClientLeafSystem::BuildRenderListInfo_t *)src);
    v29 = src;
    if ( (*((_BYTE *)info + 48) & 2) != 0 )
      CulledRenderables = CClientLeafSystem::ComputeTranslucency(
                            this,
                            a2: (CClientLeafSystem::AlphaInfo_t *)&savedregs,
                            a3: (int)src,
                            a4: (int)v10,
                            nFrameNumber: *(_DWORD *)(gpGlobals.m_Index + 4),
                            nViewID: info->m_nViewID,
                            nCount: *(float *)&CulledRenderables,
                            ppRenderables: v10,
                            pRLInfo: (CClientLeafSystem::BuildRenderListInfo_t *)src);
    OccludedRenderables = CClientLeafSystem::ExtractOccludedRenderables(
                            this,
                            nCount: CulledRenderables,
                            ppRenderables: v10,
                            pRLInfo: (CClientLeafSystem::BuildRenderListInfo_t *)v29);
    CClientLeafSystem::AddRenderablesToRenderLists(
      this,
      info,
      nCount: OccludedRenderables,
      ppRenderables: v10,
      pRLInfo: (CClientLeafSystem::BuildRenderListInfo_t *)v29,
      nDetailCount,
      pDetailInfo: (DetailRenderableInfo_t *)LODWORD(v33.m_vecMaxs.x));
    v31 = v37.m_Memory.m_pMemory;
    v37.m_Size = 0;
    if ( v37.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v37.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v37.m_Memory.m_pMemory);
        v31 = nullptr;
        v37.m_Memory.m_pMemory = nullptr;
      }
      v37.m_Memory.m_nAllocationCount = 0;
    }
    v37.m_pElements = v31;
    if ( v37.m_Memory.m_nGrowSize >= 0 )
    {
      if ( v31 != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v31);
        v37.m_Memory.m_pMemory = nullptr;
      }
      v37.m_Memory.m_nAllocationCount = 0;
    }
    x = v33.m_vecMaxs.x;
    nDetailCount = 0;
    if ( v33.m_vecMaxs.z >= 0.0 )
    {
      if ( LODWORD(v33.m_vecMaxs.x) != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)LODWORD(v33.m_vecMaxs.x));
        x = 0.0;
        v33.m_vecMaxs.x = 0.0;
      }
      v33.m_vecMaxs.y = 0.0;
    }
    v36 = x;
    if ( v33.m_vecMaxs.z >= 0.0 && x != 0.0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)LODWORD(x));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AC250
// Name: public: virtual void CClientLeafSystem::RecomputeRenderableLeaves(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::RecomputeRenderableLeaves(CClientLeafSystem *this)
{
  CThreadFastMutex *p_m_DirtyRenderablesMutex; // esi
  DWORD CurrentThreadId; // ecx
  int v4; // ecx
  int v5; // edx
  int v6; // eax
  int v7; // eax
  int v8; // ebx
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *v9; // esi
  bool v10; // zf
  unsigned __int16 v11; // si
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *v12; // ebx
  int v13; // eax
  _DWORD v14[3]; // [esp+20h] [ebp-3Ch] BYREF
  Vector absMins; // [esp+2Ch] [ebp-30h] BYREF
  Vector absMaxs; // [esp+38h] [ebp-24h] BYREF
  CAutoLockT<CThreadFastMutex> generated_id_17; // [esp+44h] [ebp-18h]
  int handle; // [esp+48h] [ebp-14h]
  int nIterations; // [esp+4Ch] [ebp-10h]
  int i; // [esp+50h] [ebp-Ch]
  int m_Size; // [esp+54h] [ebp-8h]
  bool bDebugLeafSystem; // [esp+5Bh] [ebp-1h]

  p_m_DirtyRenderablesMutex = &this->m_DirtyRenderablesMutex;
  generated_id_17.m_lock = &this->m_DirtyRenderablesMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_DirtyRenderablesMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_DirtyRenderablesMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_DirtyRenderablesMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_DirtyRenderablesMutex->m_depth;
  }
  v4 = 0;
  if ( cl_leafsystemvis.m_pParent == nullptr
    || (bDebugLeafSystem = true, cl_leafsystemvis.m_pParent->m_Value.m_nValue == 0) )
  {
    bDebugLeafSystem = false;
  }
  m_Size = this->m_DirtyRenderables.m_Size;
  if ( m_Size != 0 )
  {
    while ( 1 )
    {
      nIterations = v4 + 1;
      if ( v4 + 1 > 10 )
        break;
      v5 = m_Size;
      v6 = m_Size - 1;
      s_bIsInRecomputeRenderableLeaves = true;
      i = m_Size - 1;
      if ( m_Size - 1 >= 0 )
      {
        do
        {
          v7 = this->m_DirtyRenderables.m_Memory.m_pMemory[v6];
          v8 = (unsigned __int16)v7;
          v9 = &this->m_Renderables.m_Memory.m_pMemory[v8];
          *((_WORD *)&v9->m_Element + 11) &= ~2u;
          v10 = (*((_BYTE *)&v9->m_Element + 22) & 8) == 0;
          handle = v7;
          if ( v10 )
          {
            CClientLeafSystem::CalcRenderableWorldSpaceAABB_Bloated(
              this,
              info: &v9->m_Element,
              absMin: &absMins,
              absMax: &absMaxs);
            if ( v9->m_Element.m_vecBloatedAbsMins.x != absMins.x
              || v9->m_Element.m_vecBloatedAbsMins.y != absMins.y
              || v9->m_Element.m_vecBloatedAbsMins.z != absMins.z
              || v9->m_Element.m_vecBloatedAbsMaxs.x != absMaxs.x
              || v9->m_Element.m_vecBloatedAbsMaxs.y != absMaxs.y
              || v9->m_Element.m_vecBloatedAbsMaxs.z != absMaxs.z )
            {
              v11 = handle;
              CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::RemoveElement(
                this: &this->m_RenderablesInLeaf,
                element: handle);
              CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::RemoveBucket(
                this: &this->m_ShadowsOnRenderable,
                bucket: v11);
              v12 = &this->m_Renderables.m_Memory.m_pMemory[v8];
              switch ( *((unsigned __int16 *)&v12->m_Element + 11) >> 14 )
              {
                case 1:
                  g_pClientShadowMgr->RemoveAllShadowsFromReceiver(
                    this: g_pClientShadowMgr,
                    a2: v12->m_Element.m_pRenderable,
                    a3: SHADOW_RECEIVER_STUDIO_MODEL);
                  break;
                case 2:
                  g_pClientShadowMgr->RemoveAllShadowsFromReceiver(
                    this: g_pClientShadowMgr,
                    a2: v12->m_Element.m_pRenderable,
                    a3: SHADOW_RECEIVER_STATIC_PROP);
                  break;
                case 3:
                  g_pClientShadowMgr->RemoveAllShadowsFromReceiver(
                    this: g_pClientShadowMgr,
                    a2: v12->m_Element.m_pRenderable,
                    a3: SHADOW_RECEIVER_BRUSH_MODEL);
                  break;
                default:
                  break;
              }
              CClientLeafSystem::InsertIntoTree(
                this,
                handle: &this->m_DirtyRenderables.m_Memory.m_pMemory[i],
                &absMins,
                &absMaxs);
              if ( bDebugLeafSystem )
              {
                memset(v14, 0, sizeof(v14));
                ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, Vector *, _DWORD *, _DWORD, int, _DWORD, _DWORD, _DWORD))debugoverlay->AddBoxOverlay)(
                  a1: debugoverlay,
                  a2: &vec3_origin,
                  a3: &absMins,
                  a4: &absMaxs,
                  a5: v14,
                  a6: 0,
                  a7: 255,
                  a8: 0,
                  a9: 0,
                  a10: 0);
              }
            }
          }
          v6 = --i;
        }
        while ( i >= 0 );
        p_m_DirtyRenderablesMutex = generated_id_17.m_lock;
        v5 = m_Size;
      }
      v13 = this->m_DirtyRenderables.m_Size - v5;
      s_bIsInRecomputeRenderableLeaves = false;
      if ( v13 > 0 && v5 > 0 )
        _V_memmove(
          dest: this->m_DirtyRenderables.m_Memory.m_pMemory,
          src: &this->m_DirtyRenderables.m_Memory.m_pMemory[v5],
          count: 2 * v13);
      this->m_DirtyRenderables.m_Size -= m_Size;
      m_Size = this->m_DirtyRenderables.m_Size;
      if ( m_Size == 0 )
        goto LABEL_36;
      v4 = nIterations;
    }
    _Warning(a1: "Too many dirty renderables!\n");
  }
LABEL_36:
  v10 = p_m_DirtyRenderablesMutex->m_depth-- == 1;
  if ( v10 )
    _InterlockedExchange((volatile __int32 *)p_m_DirtyRenderablesMutex, 0);
}

//------------------------------------------------------------------------------
// Address: 0x100AC4C0
// Name: public: virtual void CClientLeafSystem::CreateRenderableHandle(class IClientRenderable __near *,bool,enum RenderableTranslucencyType_t,enum RenderableModelType_t,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::CreateRenderableHandle(
        CClientLeafSystem *this,
        IClientRenderable *pRenderable,
        BOOL bRenderWithViewModels,
        RenderableTranslucencyType_t nType,
        RenderableModelType_t nModelType,
        char nSplitscreenEnabled)
{
  CUtlLinkedList<CClientLeafSystem::RenderableInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short>,unsigned int> > *p_m_Renderables; // edi
  unsigned int v7; // eax
  unsigned int v8; // ebx
  int v9; // esi
  const struct model_t *v10; // eax
  int v11; // eax
  int v12; // eax
  unsigned __int16 *(__thiscall *RenderHandle)(IClientRenderable *); // eax
  IVModelInfoClient_vtbl *nModelTypea; // [esp+24h] [ebp+14h]

  p_m_Renderables = &this->m_Renderables;
  v7 = CUtlLinkedList<CClientLeafSystem::RenderableInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short>,unsigned int>>::AllocInternal(
         this: &this->m_Renderables,
         multilist: false);
  v8 = v7;
  if ( v7 != 0xFFFF )
    CUtlLinkedList<CClientLeafSystem::RenderableInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short>,unsigned int>>::LinkBefore(
      this: p_m_Renderables,
      before: 0xFFFFu,
      elem: v7);
  v9 = (int)&p_m_Renderables->m_Memory.m_pMemory[(unsigned __int16)v8];
  if ( nModelType == RENDERABLE_MODEL_UNKNOWN_TYPE )
  {
    nModelTypea = modelinfo->__vftable;
    v10 = pRenderable->GetModel(this: pRenderable);
    v11 = nModelTypea->GetModelType(this: modelinfo, a2: v10) - 1;
    if ( v11 != 0 )
      LOWORD(nModelType) = v11 == 2;
    else
      LOWORD(nModelType) = 3;
  }
  *(_WORD *)(v9 + 20) = -1;
  *(_DWORD *)v9 = pRenderable;
  v12 = pRenderable->GetIClientUnknown(this: pRenderable);
  *(_DWORD *)(v9 + 4) = (*(int (__thiscall **)(int))(*(_DWORD *)v12 + 36))(a1: v12);
  *(_DWORD *)(v9 + 16) = -1;
  *(_DWORD *)(v9 + 12) = -1;
  *(_DWORD *)(v9 + 8) = 0;
  *(_WORD *)(v9 + 22) = (nSplitscreenEnabled & 3 | (unsigned __int16)(4 * (nType & 3 | (4 * nModelType)))) << 10;
  RenderHandle = pRenderable->RenderHandle;
  *(_DWORD *)(v9 + 24) = 2139095039;
  *(_DWORD *)(v9 + 28) = 2139095039;
  *(_DWORD *)(v9 + 32) = 2139095039;
  *(_DWORD *)(v9 + 36) = -8388609;
  *(_DWORD *)(v9 + 40) = -8388609;
  *(_DWORD *)(v9 + 44) = -8388609;
  *(_DWORD *)(v9 + 48) = 0;
  *(_DWORD *)(v9 + 52) = 0;
  *(_DWORD *)(v9 + 56) = 0;
  *(_DWORD *)(v9 + 60) = 0;
  *(_DWORD *)(v9 + 64) = 0;
  *(_DWORD *)(v9 + 68) = 0;
  *RenderHandle(this: pRenderable) = v8;
  this->RenderWithViewModels(this, a2: v8, a3: bRenderWithViewModels);
}

//------------------------------------------------------------------------------
// Address: 0x100AC610
// Name: public: virtual void CClientLeafSystem::RenderWithViewModels(unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::RenderWithViewModels(CClientLeafSystem *this, int handle, bool bEnable)
{
  UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short> *v4; // esi
  __int16 v5; // ax
  void (__thiscall *RenderableChanged)(struct CClientLeafSystem *, unsigned __int16); // eax

  if ( (_WORD)handle != 0xFFFF )
  {
    v4 = &this->m_Renderables.m_Memory.m_pMemory[(unsigned __int16)handle];
    v5 = *((_WORD *)&v4->m_Element + 11);
    if ( bEnable )
    {
      if ( (v5 & 8) == 0 )
      {
        *((_WORD *)&v4->m_Element + 11) = v5 | 8;
        CClientLeafSystem::AddToViewModelList(this, handle);
        CClientLeafSystem::RemoveFromTree(this, handle);
      }
    }
    else if ( (v5 & 8) != 0 )
    {
      *((_WORD *)&v4->m_Element + 11) = v5 & 0xFFF7;
      CClientLeafSystem::RemoveFromViewModelList(this, handle);
      RenderableChanged = this->RenderableChanged;
      v4->m_Element.m_vecBloatedAbsMins.x = 3.4028235e38;
      v4->m_Element.m_vecBloatedAbsMins.y = 3.4028235e38;
      v4->m_Element.m_vecBloatedAbsMins.z = 3.4028235e38;
      v4->m_Element.m_vecBloatedAbsMaxs.x = -3.4028235e38;
      v4->m_Element.m_vecBloatedAbsMaxs.y = -3.4028235e38;
      v4->m_Element.m_vecBloatedAbsMaxs.z = -3.4028235e38;
      ((void (__stdcall *)(int))RenderableChanged)(a1: handle);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AC6B0
// Name: public: virtual void CClientLeafSystem::RemoveRenderable(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::RemoveRenderable(CClientLeafSystem *this, int handle)
{
  CThreadFastMutex *p_m_DirtyRenderablesMutex; // ebx
  DWORD CurrentThreadId; // ecx
  CUtlLinkedList<CClientLeafSystem::RenderableInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short>,unsigned int> > *p_m_Renderables; // edi
  unsigned int v6; // ebx
  bool v7; // zf
  int v8; // ecx
  __int16 v9; // ax
  int m_Size; // edx
  int v11; // eax
  unsigned __int16 *m_pMemory; // ecx
  CThreadFastMutex *generated_id_18; // [esp+10h] [ebp-8h]

  p_m_DirtyRenderablesMutex = &this->m_DirtyRenderablesMutex;
  generated_id_18 = &this->m_DirtyRenderablesMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != p_m_DirtyRenderablesMutex->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)p_m_DirtyRenderablesMutex, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: p_m_DirtyRenderablesMutex, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++p_m_DirtyRenderablesMutex->m_depth;
  }
  p_m_Renderables = &this->m_Renderables;
  if ( (unsigned __int16)handle >= this->m_Renderables.m_Memory.m_nAllocationCount
    || (unsigned __int16)handle > this->m_Renderables.m_LastAlloc.index )
  {
    goto LABEL_10;
  }
  v6 = (unsigned __int16)handle;
  if ( p_m_Renderables->m_Memory.m_pMemory[v6].m_Previous == (unsigned __int16)handle
    && p_m_Renderables->m_Memory.m_pMemory[v6].m_Next != (unsigned __int16)handle )
  {
    p_m_DirtyRenderablesMutex = generated_id_18;
LABEL_10:
    v7 = p_m_DirtyRenderablesMutex->m_depth-- == 1;
    if ( v7 )
      _InterlockedExchange((volatile __int32 *)p_m_DirtyRenderablesMutex, 0);
    return;
  }
  *p_m_Renderables->m_Memory.m_pMemory[v6].m_Element.m_pRenderable->RenderHandle(this: p_m_Renderables->m_Memory.m_pMemory[v6].m_Element.m_pRenderable) = -1;
  v8 = (int)&p_m_Renderables->m_Memory.m_pMemory[v6].m_Element + 22;
  v9 = *(_WORD *)v8 & 0x7F;
  if ( (*(_WORD *)v8 & 4) != 0 )
    --this->m_nAlternateSortCount;
  if ( (*(_BYTE *)(v8 + 1) & 1) != 0 )
    --this->m_nDisableShadowDepthCount;
  if ( (*(_WORD *)v8 & 0x200) != 0 )
    --this->m_nDisableShadowDepthCacheCount;
  if ( (v9 & 2) != 0 )
  {
    m_Size = this->m_DirtyRenderables.m_Size;
    v11 = 0;
    if ( m_Size > 0 )
    {
      m_pMemory = this->m_DirtyRenderables.m_Memory.m_pMemory;
      while ( *m_pMemory != (_WORD)handle )
      {
        ++v11;
        ++m_pMemory;
        if ( v11 >= m_Size )
          goto LABEL_29;
      }
      if ( v11 >= 0 && v11 < m_Size )
      {
        if ( v11 != m_Size - 1 )
          this->m_DirtyRenderables.m_Memory.m_pMemory[v11] = this->m_DirtyRenderables.m_Memory.m_pMemory[m_Size - 1];
        --this->m_DirtyRenderables.m_Size;
      }
LABEL_29:
      v6 = (unsigned __int16)handle;
    }
  }
  if ( this->IsRenderingWithViewModels(this, a2: handle) )
    CClientLeafSystem::RemoveFromViewModelList(this, handle);
  CClientLeafSystem::RemoveFromTree(this, handle);
  CUtlLinkedList<CClientLeafSystem::RenderableInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::RenderableInfo_t,unsigned short>,unsigned int>>::Unlink(
    this: p_m_Renderables,
    elem: (unsigned __int16)handle);
  this->m_Renderables.m_Memory.m_pMemory[v6].m_Next = this->m_Renderables.m_FirstFree;
  this->m_Renderables.m_FirstFree = (unsigned __int16)handle;
  v7 = generated_id_18->m_depth-- == 1;
  if ( v7 )
    _InterlockedExchange((volatile __int32 *)generated_id_18, 0);
}

//------------------------------------------------------------------------------
// Address: 0x100AC840
// Name: public: virtual unsigned short CClientLeafSystem::AddShadow(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CClientLeafSystem::AddShadow(
        CClientLeafSystem *this,
        unsigned __int16 userId,
        unsigned __int16 flags)
{
  CUtlLinkedList<CClientLeafSystem::ShadowInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::ShadowInfo_t,unsigned short>,unsigned int> > *p_m_Shadows; // esi
  unsigned int result; // eax
  unsigned int v5; // edi
  int v6; // ecx

  p_m_Shadows = &this->m_Shadows;
  result = CUtlLinkedList<CClientLeafSystem::ShadowInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::ShadowInfo_t,unsigned short>,unsigned int>>::AllocInternal(
             this: &this->m_Shadows,
             multilist: false);
  v5 = result;
  if ( result != 0xFFFF )
  {
    CUtlLinkedList<CClientLeafSystem::ShadowInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::ShadowInfo_t,unsigned short>,unsigned int>>::LinkBefore(
      this: p_m_Shadows,
      before: 0xFFFFu,
      elem: result);
    result = v5;
  }
  v6 = (unsigned __int16)result;
  p_m_Shadows->m_Memory.m_pMemory[v6].m_Element.m_Shadow = userId;
  p_m_Shadows->m_Memory.m_pMemory[v6].m_Element.m_FirstLeaf = -1;
  p_m_Shadows->m_Memory.m_pMemory[v6].m_Element.m_FirstRenderable = -1;
  p_m_Shadows->m_Memory.m_pMemory[v6].m_Element.m_EnumCount = 0;
  p_m_Shadows->m_Memory.m_pMemory[v6].m_Element.m_Flags = flags;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AC8B0
// Name: public: virtual void CClientLeafSystem::RemoveShadow(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientLeafSystem::RemoveShadow(CClientLeafSystem *this, unsigned __int16 handle)
{
  CBidirectionalSet<int,unsigned short,unsigned short,unsigned int>::RemoveElement(
    this: &this->m_ShadowsInLeaf,
    element: handle);
  CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned int>::RemoveElement(
    this: &this->m_ShadowsOnRenderable,
    element: handle);
  CUtlLinkedList<CClientLeafSystem::ShadowInfo_t,unsigned short,0,unsigned int,CUtlMemory<UtlLinkedListElem_t<CClientLeafSystem::ShadowInfo_t,unsigned short>,unsigned int>>::Unlink(
    this: &this->m_Shadows,
    elem: handle);
  this->m_Shadows.m_Memory.m_pMemory[handle].m_Next = this->m_Shadows.m_FirstFree;
  this->m_Shadows.m_FirstFree = handle;
}

//------------------------------------------------------------------------------
// Address: 0x100BB1A0
// Name: public: void CUtlMemory<struct CClientLeafSystem::RenderableInfo_t __near *,int>::ConvertToGrowableMemory(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CClientLeafSystem::RenderableInfo_t *,int>::ConvertToGrowableMemory(
        CUtlMemory<CClientLeafSystem::RenderableInfo_t *,int> *this,
        int nGrowSize)
{
  int m_nAllocationCount; // eax
  unsigned int v4; // edi
  unsigned __int8 *v5; // ebx

  if ( this->m_nGrowSize < 0 )
  {
    this->m_nGrowSize = nGrowSize;
    m_nAllocationCount = this->m_nAllocationCount;
    if ( m_nAllocationCount != 0 )
    {
      v4 = 4 * m_nAllocationCount;
      v5 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 4 * m_nAllocationCount);
      memcpy(dst: v5, src: (unsigned __int8 *)this->m_pMemory, count: v4);
      this->m_pMemory = (CClientLeafSystem::RenderableInfo_t **)v5;
    }
    else
    {
      this->m_pMemory = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10414890
// Name: _dynamic_initializer_for__CClientLeafSystem::s_ClientLeafSystem__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CClientLeafSystem::s_ClientLeafSystem__()
{
  CClientLeafSystem::CClientLeafSystem(this: &CClientLeafSystem::s_ClientLeafSystem);
  return atexit(func: dynamic_atexit_destructor_for__CClientLeafSystem::s_ClientLeafSystem__);
}

//------------------------------------------------------------------------------
// Address: 0x104310C0
// Name: _dynamic_atexit_destructor_for__CClientLeafSystem::s_ClientLeafSystem__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CClientLeafSystem::s_ClientLeafSystem__()
{
  CClientLeafSystem::~CClientLeafSystem(this: &CClientLeafSystem::s_ClientLeafSystem);
}

//------------------------------------------------------------------------------
// Address: 0x104148B0
// Name: _dynamic_initializer_for____g_CreateCClientLeafSystemIClientLeafSystem_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCClientLeafSystemIClientLeafSystem_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCClientLeafSystemIClientLeafSystem_reg,
           fn: (void *(__cdecl *)())_CreateCClientLeafSystemIClientLeafSystem_interface,
           pName: "ClientLeafSystem002");
}

//------------------------------------------------------------------------------
// Address: 0x104148D0
// Name: _dynamic_initializer_for____g_CreateCClientLeafSystemIClientAlphaPropertyMgr_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCClientLeafSystemIClientAlphaPropertyMgr_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCClientLeafSystemIClientAlphaPropertyMgr_reg,
           fn: (void *(__cdecl *)())_CreateCClientLeafSystemIClientAlphaPropertyMgr_interface,
           pName: "ClientAlphaPropertyMgrV001");
}

//------------------------------------------------------------------------------
// Address: 0x104148F0
// Name: _dynamic_initializer_for__r_drawallrenderables__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_drawallrenderables__()
{
  ConVar::ConVar(
    this: &r_drawallrenderables,
    pName: "r_drawallrenderables",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Draw all renderables, even ones inside solid leaves.");
  return atexit(func: dynamic_atexit_destructor_for__r_drawallrenderables__);
}

//------------------------------------------------------------------------------
// Address: 0x10414920
// Name: _dynamic_initializer_for__r_fastreflectionfastpath__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_fastreflectionfastpath__()
{
  ConVar::ConVar(this: &r_fastreflectionfastpath, pName: "r_fastreflectionfastpath", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_fastreflectionfastpath__);
}

//------------------------------------------------------------------------------
// Address: 0x10414950
// Name: _dynamic_initializer_for__r_highlight_translucent_renderables__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_highlight_translucent_renderables__()
{
  ConVar::ConVar(
    this: &r_highlight_translucent_renderables,
    pName: "r_highlight_translucent_renderables",
    pDefaultValue: "0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_highlight_translucent_renderables__);
}

//------------------------------------------------------------------------------
// Address: 0x10414980
// Name: _dynamic_initializer_for__cl_drawhud__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_drawhud__()
{
  ConVar::ConVar(
    this: &cl_drawhud,
    pName: "cl_drawhud",
    pDefaultValue: "1",
    flags: 0x4000,
    pHelpString: "Enable the rendering of the hud");
  return atexit(func: dynamic_atexit_destructor_for__cl_drawhud__);
}

//------------------------------------------------------------------------------
// Address: 0x104149B0
// Name: _dynamic_initializer_for__hud_takesshots__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hud_takesshots__()
{
  ConVar::ConVar(
    this: &hud_takesshots,
    pName: "hud_takesshots",
    pDefaultValue: "0",
    flags: 136,
    pHelpString: "Auto-save a scoreboard screenshot at the end of a map.");
  return atexit(func: dynamic_atexit_destructor_for__hud_takesshots__);
}

//------------------------------------------------------------------------------
// Address: 0x104149E0
// Name: _dynamic_initializer_for__hud_reloadscheme_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__hud_reloadscheme_command__()
{
  ConCommand::ConCommand(
    this: &hud_reloadscheme_command,
    pName: "hud_reloadscheme",
    callback: hud_reloadscheme,
    pHelpString: "Reloads hud layout and animation scripts.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__hud_reloadscheme_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10414A10
// Name: _dynamic_initializer_for__r_flashlightdrawfrustum__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_flashlightdrawfrustum__()
{
  ConVar::ConVar(this: &r_flashlightdrawfrustum, pName: "r_flashlightdrawfrustum", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_flashlightdrawfrustum__);
}

//------------------------------------------------------------------------------
// Address: 0x10414A40
// Name: _dynamic_initializer_for__r_flashlightdrawfrustumbbox__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_flashlightdrawfrustumbbox__()
{
  ConVar::ConVar(this: &r_flashlightdrawfrustumbbox, pName: "r_flashlightdrawfrustumbbox", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_flashlightdrawfrustumbbox__);
}

//------------------------------------------------------------------------------
// Address: 0x10414A70
// Name: _dynamic_initializer_for__r_flashlightmodels__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_flashlightmodels__()
{
  ConVar::ConVar(this: &r_flashlightmodels, pName: "r_flashlightmodels", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_flashlightmodels__);
}

//------------------------------------------------------------------------------
// Address: 0x10414AA0
// Name: _dynamic_initializer_for__r_shadowrendertotexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_shadowrendertotexture__()
{
  ConVar::ConVar(this: &r_shadowrendertotexture, pName: "r_shadowrendertotexture", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_shadowrendertotexture__);
}

//------------------------------------------------------------------------------
// Address: 0x10414AD0
// Name: _dynamic_initializer_for__r_shadow_lightpos_lerptime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_shadow_lightpos_lerptime__()
{
  ConVar::ConVar(this: &r_shadow_lightpos_lerptime, pName: "r_shadow_lightpos_lerptime", pDefaultValue: "0.5", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_shadow_lightpos_lerptime__);
}

//------------------------------------------------------------------------------
// Address: 0x10414B00
// Name: _dynamic_initializer_for__r_shadowfromworldlights_debug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_shadowfromworldlights_debug__()
{
  ConVar::ConVar(
    this: &r_shadowfromworldlights_debug,
    pName: "r_shadowfromworldlights_debug",
    pDefaultValue: "0",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_shadowfromworldlights_debug__);
}

//------------------------------------------------------------------------------
// Address: 0x10414B30
// Name: _dynamic_initializer_for__r_shadowfromanyworldlight__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_shadowfromanyworldlight__()
{
  ConVar::ConVar(
    this: &r_shadowfromanyworldlight,
    pName: "r_shadowfromanyworldlight",
    pDefaultValue: "0",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_shadowfromanyworldlight__);
}

//------------------------------------------------------------------------------
// Address: 0x10414B60
// Name: _dynamic_initializer_for__r_shadow_shortenfactor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_shadow_shortenfactor__()
{
  ConVar::ConVar(
    this: &r_shadow_shortenfactor,
    pName: "r_shadow_shortenfactor",
    pDefaultValue: "2",
    flags: 0,
    pHelpString: "Makes shadows cast from local lights shorter");
  return atexit(func: dynamic_atexit_destructor_for__r_shadow_shortenfactor__);
}

//------------------------------------------------------------------------------
// Address: 0x10414B90
// Name: _dynamic_initializer_for__r_flashlightenableculling__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_flashlightenableculling__()
{
  ConVar::ConVar(
    this: &r_flashlightenableculling,
    pName: "r_flashlightenableculling",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Enable frustum culling of flashlights");
  return atexit(func: dynamic_atexit_destructor_for__r_flashlightenableculling__);
}

//------------------------------------------------------------------------------
// Address: 0x10414BC0
// Name: _dynamic_initializer_for__r_shadow_half_update_rate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_shadow_half_update_rate__()
{
  ConVar::ConVar(
    this: &r_shadow_half_update_rate,
    pName: "r_shadow_half_update_rate",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Updates shadows at half the framerate",
    callback: (void (__cdecl *)(IConVar *, const char *, float))HalfUpdateRateCallback);
  return atexit(func: dynamic_atexit_destructor_for__r_shadow_half_update_rate__);
}

//------------------------------------------------------------------------------
// Address: 0x10414BF0
// Name: _dynamic_initializer_for__r_shadow_deferred__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_shadow_deferred__()
{
  ConVar::ConVar(
    this: &r_shadow_deferred,
    pName: "r_shadow_deferred",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Toggle deferred shadow rendering",
    callback: (void (__cdecl *)(IConVar *, const char *, float))DeferredShadowToggleCallback);
  return atexit(func: dynamic_atexit_destructor_for__r_shadow_deferred__);
}

//------------------------------------------------------------------------------
// Address: 0x10414C20
// Name: _dynamic_initializer_for__r_shadow_deferred_downsample__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_shadow_deferred_downsample__()
{
  ConVar::ConVar(
    this: &r_shadow_deferred_downsample,
    pName: "r_shadow_deferred_downsample",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Toggle low-res deferred shadow rendering",
    callback: (void (__cdecl *)(IConVar *, const char *, float))DeferredShadowDownsampleToggleCallback);
  return atexit(func: dynamic_atexit_destructor_for__r_shadow_deferred_downsample__);
}

//------------------------------------------------------------------------------
// Address: 0x10414C50
// Name: _dynamic_initializer_for__r_shadow_deferred_simd__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_shadow_deferred_simd__()
{
  ConVar::ConVar(this: &r_shadow_deferred_simd, pName: "r_shadow_deferred_simd", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_shadow_deferred_simd__);
}

//------------------------------------------------------------------------------
// Address: 0x10414C80
// Name: _dynamic_initializer_for__r_shadow_debug_spew__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_shadow_debug_spew__()
{
  ConVar::ConVar(this: &r_shadow_debug_spew, pName: "r_shadow_debug_spew", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_shadow_debug_spew__);
}

//------------------------------------------------------------------------------
// Address: 0x10414CB0
// Name: _dynamic_initializer_for__r_flashlight_info__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_flashlight_info__()
{
  ConVar::ConVar(
    this: &r_flashlight_info,
    pName: "r_flashlight_info",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Information about currently enabled flashlights");
  return atexit(func: dynamic_atexit_destructor_for__r_flashlight_info__);
}

//------------------------------------------------------------------------------
// Address: 0x10414CE0
// Name: _dynamic_initializer_for__r_flashlightdepthtexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_flashlightdepthtexture__()
{
  ConVar::ConVar(this: &r_flashlightdepthtexture, pName: "r_flashlightdepthtexture", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_flashlightdepthtexture__);
}

//------------------------------------------------------------------------------
// Address: 0x10414D10
// Name: _dynamic_initializer_for__r_flashlightdepthreshigh__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_flashlightdepthreshigh__()
{
  ConVar::ConVar(this: &r_flashlightdepthreshigh, pName: "r_flashlightdepthreshigh", pDefaultValue: "2048", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_flashlightdepthreshigh__);
}

//------------------------------------------------------------------------------
// Address: 0x10414D40
// Name: _dynamic_initializer_for__r_flashlightdepthres__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_flashlightdepthres__()
{
  ConVar::ConVar(this: &r_flashlightdepthres, pName: "r_flashlightdepthres", pDefaultValue: "1024", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_flashlightdepthres__);
}

//------------------------------------------------------------------------------
// Address: 0x10414D70
// Name: _dynamic_initializer_for__r_shadows__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_shadows__()
{
  ConVar::ConVar(this: &r_shadows, pName: "r_shadows", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_shadows__);
}

//------------------------------------------------------------------------------
// Address: 0x10414DA0
// Name: _dynamic_initializer_for__r_shadowmaxrendered__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_shadowmaxrendered__()
{
  ConVar::ConVar(this: &r_shadowmaxrendered, pName: "r_shadowmaxrendered", pDefaultValue: "32", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_shadowmaxrendered__);
}

//------------------------------------------------------------------------------
// Address: 0x10414DD0
// Name: _dynamic_initializer_for__r_shadows_gamecontrol__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_shadows_gamecontrol__()
{
  ConVar::ConVar(this: &r_shadows_gamecontrol, pName: "r_shadows_gamecontrol", pDefaultValue: "-1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_shadows_gamecontrol__);
}

//------------------------------------------------------------------------------
// Address: 0x10414E00
// Name: _dynamic_initializer_for__s_ClientShadowMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ClientShadowMgr__()
{
  CClientShadowMgr::CClientShadowMgr(this: &s_ClientShadowMgr);
  return atexit(func: dynamic_atexit_destructor_for__s_ClientShadowMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x10414E20
// Name: _dynamic_initializer_for__s_VisibleShadowList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_VisibleShadowList__()
{
  CVisibleShadowList::CVisibleShadowList(this: &s_VisibleShadowList);
  return atexit(func: dynamic_atexit_destructor_for__s_VisibleShadowList__);
}

//------------------------------------------------------------------------------
// Address: 0x10414E40
// Name: _dynamic_initializer_for__s_NPCShadowBoneSetups__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_NPCShadowBoneSetups__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_NPCShadowBoneSetups__);
}

//------------------------------------------------------------------------------
// Address: 0x10414E50
// Name: _dynamic_initializer_for__s_NonNPCShadowBoneSetups__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_NonNPCShadowBoneSetups__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_NonNPCShadowBoneSetups__);
}

//------------------------------------------------------------------------------
// Address: 0x10414E60
// Name: _dynamic_initializer_for__r_shadowdir_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_shadowdir_command__()
{
  ConCommand::ConCommand(
    this: &r_shadowdir_command,
    pName: "r_shadowdir",
    callback: (void (__cdecl *)())r_shadowdir,
    pHelpString: "Set shadow direction",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__r_shadowdir_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10414E90
// Name: _dynamic_initializer_for__r_shadowangles_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_shadowangles_command__()
{
  ConCommand::ConCommand(
    this: &r_shadowangles_command,
    pName: "r_shadowangles",
    callback: (void (__cdecl *)())r_shadowangles,
    pHelpString: "Set shadow angles",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__r_shadowangles_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10414EC0
// Name: _dynamic_initializer_for__r_shadowcolor_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_shadowcolor_command__()
{
  ConCommand::ConCommand(
    this: &r_shadowcolor_command,
    pName: "r_shadowcolor",
    callback: (void (__cdecl *)())r_shadowcolor,
    pHelpString: "Set shadow color",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__r_shadowcolor_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10414EF0
// Name: _dynamic_initializer_for__r_shadowdist_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_shadowdist_command__()
{
  ConCommand::ConCommand(
    this: &r_shadowdist_command,
    pName: "r_shadowdist",
    callback: (void (__cdecl *)())r_shadowdist,
    pHelpString: "Set shadow distance",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__r_shadowdist_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10414F20
// Name: _dynamic_initializer_for__r_shadowblobbycutoff_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_shadowblobbycutoff_command__()
{
  ConCommand::ConCommand(
    this: &r_shadowblobbycutoff_command,
    pName: "r_shadowblobbycutoff",
    callback: (void (__cdecl *)())r_shadowblobbycutoff,
    pHelpString: "some shadow stuff",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__r_shadowblobbycutoff_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10414F50
// Name: _dynamic_initializer_for__r_shadowfromworldlights__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_shadowfromworldlights__()
{
  ConVar::ConVar(
    this: &r_shadowfromworldlights,
    pName: "r_shadowfromworldlights",
    pDefaultValue: "1",
    flags: 0,
    pHelpString: "Enable shadowing from world lights",
    callback: (void (__cdecl *)(IConVar *, const char *, float))OnShadowFromWorldLights);
  return atexit(func: dynamic_atexit_destructor_for__r_shadowfromworldlights__);
}

//------------------------------------------------------------------------------
// Address: 0x10414F80
// Name: _dynamic_initializer_for__g_DirtyListAddMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DirtyListAddMutex__()
{
  g_DirtyListAddMutex.m_ownerID = 0;
  g_DirtyListAddMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10414F90
// Name: _dynamic_initializer_for__g_CShadowFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CShadowFoo__()
{
  CMaterialProxyDict *MaterialProxyDict; // eax

  MaterialProxyDict = GetMaterialProxyDict();
  return ((int (__thiscall *)(CMaterialProxyDict *, const char *, IMaterialProxy *(__cdecl *)()))MaterialProxyDict->Add)(
           a1: MaterialProxyDict,
           a2: "Shadow",
           a3: CCShadowProxyFactory);
}

//------------------------------------------------------------------------------
// Address: 0x10414FB0
// Name: _dynamic_initializer_for__g_CShadowModelFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CShadowModelFoo__()
{
  CMaterialProxyDict *MaterialProxyDict; // eax

  MaterialProxyDict = GetMaterialProxyDict();
  return ((int (__thiscall *)(CMaterialProxyDict *, const char *, IMaterialProxy *(__cdecl *)()))MaterialProxyDict->Add)(
           a1: MaterialProxyDict,
           a2: "ShadowModel",
           a3: CCShadowModelProxyFactory);
}

//------------------------------------------------------------------------------
// Address: 0x10414FD0
// Name: _dynamic_initializer_for__g_EffectsList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_EffectsList__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_EffectsList__);
}

//------------------------------------------------------------------------------
// Address: 0x104310D0
// Name: _dynamic_atexit_destructor_for__cl_drawhud__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_drawhud__()
{
  ConVar::~ConVar(this: &cl_drawhud);
}

//------------------------------------------------------------------------------
// Address: 0x104310E0
// Name: _dynamic_atexit_destructor_for__hud_takesshots__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__hud_takesshots__()
{
  ConVar::~ConVar(this: &hud_takesshots);
}

//------------------------------------------------------------------------------
// Address: 0x104310F0
// Name: _dynamic_atexit_destructor_for__hud_reloadscheme_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__hud_reloadscheme_command__()
{
  ConCommand::~ConCommand(this: &hud_reloadscheme_command);
}

//------------------------------------------------------------------------------
// Address: 0x10431100
// Name: _dynamic_atexit_destructor_for__r_flashlightdrawfrustum__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flashlightdrawfrustum__()
{
  ConVar::~ConVar(this: &r_flashlightdrawfrustum);
}

//------------------------------------------------------------------------------
// Address: 0x10431110
// Name: _dynamic_atexit_destructor_for__r_flashlightdrawfrustumbbox__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flashlightdrawfrustumbbox__()
{
  ConVar::~ConVar(this: &r_flashlightdrawfrustumbbox);
}

//------------------------------------------------------------------------------
// Address: 0x10431120
// Name: _dynamic_atexit_destructor_for__r_flashlightmodels__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flashlightmodels__()
{
  ConVar::~ConVar(this: &r_flashlightmodels);
}

//------------------------------------------------------------------------------
// Address: 0x10431130
// Name: _dynamic_atexit_destructor_for__r_shadowrendertotexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_shadowrendertotexture__()
{
  ConVar::~ConVar(this: &r_shadowrendertotexture);
}

//------------------------------------------------------------------------------
// Address: 0x10431140
// Name: _dynamic_atexit_destructor_for__r_shadow_lightpos_lerptime__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_shadow_lightpos_lerptime__()
{
  ConVar::~ConVar(this: &r_shadow_lightpos_lerptime);
}

//------------------------------------------------------------------------------
// Address: 0x10431150
// Name: _dynamic_atexit_destructor_for__r_shadowfromworldlights_debug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_shadowfromworldlights_debug__()
{
  ConVar::~ConVar(this: &r_shadowfromworldlights_debug);
}

//------------------------------------------------------------------------------
// Address: 0x10431160
// Name: _dynamic_atexit_destructor_for__r_shadowfromanyworldlight__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_shadowfromanyworldlight__()
{
  ConVar::~ConVar(this: &r_shadowfromanyworldlight);
}

//------------------------------------------------------------------------------
// Address: 0x10431170
// Name: _dynamic_atexit_destructor_for__r_shadow_shortenfactor__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_shadow_shortenfactor__()
{
  ConVar::~ConVar(this: &r_shadow_shortenfactor);
}

//------------------------------------------------------------------------------
// Address: 0x10431180
// Name: _dynamic_atexit_destructor_for__r_flashlightenableculling__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flashlightenableculling__()
{
  ConVar::~ConVar(this: &r_flashlightenableculling);
}

//------------------------------------------------------------------------------
// Address: 0x10431190
// Name: _dynamic_atexit_destructor_for__r_shadow_half_update_rate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_shadow_half_update_rate__()
{
  ConVar::~ConVar(this: &r_shadow_half_update_rate);
}

//------------------------------------------------------------------------------
// Address: 0x104311A0
// Name: _dynamic_atexit_destructor_for__r_shadow_deferred__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_shadow_deferred__()
{
  ConVar::~ConVar(this: &r_shadow_deferred);
}

//------------------------------------------------------------------------------
// Address: 0x104311B0
// Name: _dynamic_atexit_destructor_for__r_shadow_deferred_downsample__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_shadow_deferred_downsample__()
{
  ConVar::~ConVar(this: &r_shadow_deferred_downsample);
}

//------------------------------------------------------------------------------
// Address: 0x104311C0
// Name: _dynamic_atexit_destructor_for__r_shadow_deferred_simd__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_shadow_deferred_simd__()
{
  ConVar::~ConVar(this: &r_shadow_deferred_simd);
}

//------------------------------------------------------------------------------
// Address: 0x104311D0
// Name: _dynamic_atexit_destructor_for__r_shadow_debug_spew__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_shadow_debug_spew__()
{
  ConVar::~ConVar(this: &r_shadow_debug_spew);
}

//------------------------------------------------------------------------------
// Address: 0x104311E0
// Name: _dynamic_atexit_destructor_for__r_flashlight_info__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flashlight_info__()
{
  ConVar::~ConVar(this: &r_flashlight_info);
}

//------------------------------------------------------------------------------
// Address: 0x104311F0
// Name: _dynamic_atexit_destructor_for__r_flashlightdepthtexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flashlightdepthtexture__()
{
  ConVar::~ConVar(this: &r_flashlightdepthtexture);
}

//------------------------------------------------------------------------------
// Address: 0x10431200
// Name: _dynamic_atexit_destructor_for__r_flashlightdepthreshigh__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flashlightdepthreshigh__()
{
  ConVar::~ConVar(this: &r_flashlightdepthreshigh);
}

//------------------------------------------------------------------------------
// Address: 0x10431210
// Name: _dynamic_atexit_destructor_for__r_flashlightdepthres__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_flashlightdepthres__()
{
  ConVar::~ConVar(this: &r_flashlightdepthres);
}

//------------------------------------------------------------------------------
// Address: 0x10431220
// Name: _dynamic_atexit_destructor_for__r_shadows__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_shadows__()
{
  ConVar::~ConVar(this: &r_shadows);
}

//------------------------------------------------------------------------------
// Address: 0x10431230
// Name: _dynamic_atexit_destructor_for__r_shadowmaxrendered__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_shadowmaxrendered__()
{
  ConVar::~ConVar(this: &r_shadowmaxrendered);
}

//------------------------------------------------------------------------------
// Address: 0x10431240
// Name: _dynamic_atexit_destructor_for__r_shadows_gamecontrol__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_shadows_gamecontrol__()
{
  ConVar::~ConVar(this: &r_shadows_gamecontrol);
}

//------------------------------------------------------------------------------
// Address: 0x10431250
// Name: _dynamic_atexit_destructor_for__r_shadowdir_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_shadowdir_command__()
{
  ConCommand::~ConCommand(this: &r_shadowdir_command);
}

//------------------------------------------------------------------------------
// Address: 0x10431260
// Name: _dynamic_atexit_destructor_for__r_shadowangles_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_shadowangles_command__()
{
  ConCommand::~ConCommand(this: &r_shadowangles_command);
}

//------------------------------------------------------------------------------
// Address: 0x10431270
// Name: _dynamic_atexit_destructor_for__r_shadowcolor_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_shadowcolor_command__()
{
  ConCommand::~ConCommand(this: &r_shadowcolor_command);
}

//------------------------------------------------------------------------------
// Address: 0x10431280
// Name: _dynamic_atexit_destructor_for__r_shadowdist_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_shadowdist_command__()
{
  ConCommand::~ConCommand(this: &r_shadowdist_command);
}

//------------------------------------------------------------------------------
// Address: 0x10431290
// Name: _dynamic_atexit_destructor_for__r_shadowblobbycutoff_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_shadowblobbycutoff_command__()
{
  ConCommand::~ConCommand(this: &r_shadowblobbycutoff_command);
}

//------------------------------------------------------------------------------
// Address: 0x104312A0
// Name: _dynamic_atexit_destructor_for__r_shadowfromworldlights__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_shadowfromworldlights__()
{
  ConVar::~ConVar(this: &r_shadowfromworldlights);
}

//------------------------------------------------------------------------------
// Address: 0x104312B0
// Name: _dynamic_atexit_destructor_for__s_NPCShadowBoneSetups__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_NPCShadowBoneSetups__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_NPCShadowBoneSetups);
}

//------------------------------------------------------------------------------
// Address: 0x104312C0
// Name: _dynamic_atexit_destructor_for__s_NonNPCShadowBoneSetups__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_NonNPCShadowBoneSetups__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_NonNPCShadowBoneSetups);
}

//------------------------------------------------------------------------------
// Address: 0x104312D0
// Name: _dynamic_atexit_destructor_for__s_VisibleShadowList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_VisibleShadowList__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_VisibleShadowList.m_PriorityIndex);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_VisibleShadowList.m_BlobbyShadowsInView);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_VisibleShadowList.m_ShadowsInView);
}

//------------------------------------------------------------------------------
// Address: 0x104312F0
// Name: _dynamic_atexit_destructor_for__s_ClientShadowMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ClientShadowMgr__()
{
  CClientShadowMgr::~CClientShadowMgr(this: &s_ClientShadowMgr);
}

//------------------------------------------------------------------------------
// Address: 0x10431300
// Name: _dynamic_atexit_destructor_for__g_EffectsList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_EffectsList__()
{
  g_EffectsList.__vftable = (CEffectsList_vtbl *)&IEffectsList::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10431310
// Name: _dynamic_atexit_destructor_for__cl_tracer_whiz_distance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_tracer_whiz_distance__()
{
  ConVar::~ConVar(this: &cl_tracer_whiz_distance);
}

//------------------------------------------------------------------------------
// Address: 0x10431320
// Name: _dynamic_atexit_destructor_for__g_BulletWhiz__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_BulletWhiz__()
{
  IGameSystem::~IGameSystem(this: &g_BulletWhiz);
}
