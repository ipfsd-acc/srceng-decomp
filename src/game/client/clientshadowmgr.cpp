// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/clientshadowmgr.cpp
// Functions: 137
// ============================================================

#include "game\client\clientshadowmgr.h"

//------------------------------------------------------------------------------
// Address: 0x100AE980
// Name: private: static bool CClientShadowMgr::ShadowHandleCompareFunc(unsigned short const __near &,unsigned short const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CClientShadowMgr::ShadowHandleCompareFunc(const unsigned __int16 *lhs, const unsigned __int16 *rhs)
{
  return *lhs < *rhs;
}

//------------------------------------------------------------------------------
// Address: 0x100AE9A0
// Name: public: virtual void CClientShadowMgr::SetShadowBlobbyCutoffArea(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::SetShadowBlobbyCutoffArea(CClientShadowMgr *this, float flMinArea)
{
  this->m_flMinShadowArea = flMinArea;
}

//------------------------------------------------------------------------------
// Address: 0x100AE9C0
// Name: public: virtual void CClientShadowMgr::DestroyFlashlight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::DestroyFlashlight(CClientShadowMgr *this, int shadowHandle)
{
  this->DestroyShadow(this, a2: shadowHandle);
}

//------------------------------------------------------------------------------
// Address: 0x100AE9D0
// Name: public: virtual void CClientShadowMgr::RemoveAllShadowsFromReceiver(class IClientRenderable __near *,enum ShadowReceiver_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::RemoveAllShadowsFromReceiver(
        CClientShadowMgr *this,
        IClientRenderable *pRenderable,
        ShadowReceiver_t type)
{
  IShadowMgr_vtbl *v3; // edi
  unsigned __int16 v4; // ax
  struct model_t *v5; // eax

  if ( pRenderable->ShouldReceiveProjectedTextures(this: pRenderable, a2: 7) )
  {
    if ( type != SHADOW_RECEIVER_BRUSH_MODEL )
    {
      if ( type == SHADOW_RECEIVER_STATIC_PROP )
      {
        staticpropmgr->RemoveAllShadowsFromStaticProp(this: staticpropmgr, a2: pRenderable);
      }
      else if ( type == SHADOW_RECEIVER_STUDIO_MODEL && pRenderable->GetModelInstance(this: pRenderable) != 0xFFFF )
      {
        v3 = shadowmgr->__vftable;
        v4 = pRenderable->GetModelInstance(this: pRenderable);
        v3->RemoveAllShadowsFromModel(this: shadowmgr, a2: v4);
      }
    }
    else
    {
      v5 = pRenderable->GetModel(this: pRenderable);
      shadowmgr->RemoveAllShadowsFromBrushModel(this: shadowmgr, a2: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AEA60
// Name: private: void CClientShadowMgr::SetRenderToTextureShadowTexCoords(unsigned short,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::SetRenderToTextureShadowTexCoords(
        CClientShadowMgr *this,
        int handle,
        int x,
        int y,
        int w,
        int h)
{
  ((void (__thiscall *)(IShadowMgr *, int, _DWORD, _DWORD, _DWORD, _DWORD))shadowmgr->SetShadowTexCoord)(
    a1: shadowmgr,
    a2: handle,
    a3: (float)((float)x + 0.5) * 0.0009765625,
    a4: (float)((float)y + 0.5) * 0.0009765625,
    a5: (float)((float)w - 1.0) * 0.0009765625,
    a6: (float)((float)h - 1.0) * 0.0009765625);
}

//------------------------------------------------------------------------------
// Address: 0x100AEAF0
// Name: private: void CClientShadowMgr::SetRenderToTextureShadowTexCoords(struct CClientShadowMgr::ClientShadow_t __near &,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::SetRenderToTextureShadowTexCoords(
        CClientShadowMgr *this,
        CClientShadowMgr::ClientShadow_t *shadow,
        int x,
        int y,
        int w,
        int h)
{
  shadow->m_TexCoordOffset.x = (float)((float)x + 0.5) * 0.0009765625;
  shadow->m_TexCoordOffset.y = (float)((float)y + 0.5) * 0.0009765625;
  shadow->m_TexCoordScale.x = (float)((float)w - 1.0) * 0.0009765625;
  shadow->m_TexCoordScale.y = (float)((float)h - 1.0) * 0.0009765625;
}

//------------------------------------------------------------------------------
// Address: 0x100AEB80
// Name: private: virtual void CClientShadowMgr::AdvanceFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::AdvanceFrame(CClientShadowMgr *this)
{
  ++this->m_ShadowAllocator.m_CurrentFrame;
}

//------------------------------------------------------------------------------
// Address: 0x100AEB90
// Name: public: virtual bool CShadowProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShadowProxy::Init(CShadowProxy *this, IMaterial *pMaterial, KeyValues *pKeyValues)
{
  IMaterial *v3; // esi
  IMaterialVar *v5; // eax
  bool v6; // zf

  v3 = pMaterial;
  v5 = pMaterial->FindVar(this: pMaterial, a2: "$basetexture", a3: (char *)&pMaterial + 3, a4: 0);
  v6 = HIBYTE(pMaterial) == 0;
  this->m_BaseTextureVar = v5;
  if ( v6 )
    return false;
  this->m_MaxFalloffAmountVar = v3->FindVar(this: v3, a2: "$maxfalloffamount", a3: (bool *)&pMaterial + 3, a4: false);
  return HIBYTE(pMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x100AEBE0
// Name: public: virtual bool CShadowModelProxy::Init(class IMaterial __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShadowModelProxy::Init(CShadowModelProxy *this, IMaterial *pMaterial, KeyValues *pKeyValues)
{
  IMaterial *v3; // esi
  IMaterialVar *v5; // eax
  bool v6; // zf
  IMaterialVar *v8; // eax
  IMaterialVar *v9; // eax
  IMaterialVar *v10; // eax
  IMaterialVar *v11; // eax
  IMaterialVar *v12; // eax

  v3 = pMaterial;
  v5 = pMaterial->FindVar(this: pMaterial, a2: "$basetexture", a3: (char *)&pMaterial + 3, a4: 0);
  v6 = HIBYTE(pMaterial) == 0;
  this->m_BaseTextureVar = v5;
  if ( v6 )
    return false;
  v8 = v3->FindVar(this: v3, a2: "$basetextureoffset", a3: (bool *)&pMaterial + 3, a4: false);
  v6 = HIBYTE(pMaterial) == 0;
  this->m_BaseTextureOffsetVar = v8;
  if ( v6 )
    return false;
  v9 = v3->FindVar(this: v3, a2: "$basetexturescale", a3: (bool *)&pMaterial + 3, a4: false);
  v6 = HIBYTE(pMaterial) == 0;
  this->m_BaseTextureScaleVar = v9;
  if ( v6 )
    return false;
  v10 = v3->FindVar(this: v3, a2: "$basetexturetransform", a3: (bool *)&pMaterial + 3, a4: false);
  v6 = HIBYTE(pMaterial) == 0;
  this->m_BaseTextureMatrixVar = v10;
  if ( v6 )
    return false;
  v11 = v3->FindVar(this: v3, a2: "$falloffoffset", a3: (bool *)&pMaterial + 3, a4: false);
  v6 = HIBYTE(pMaterial) == 0;
  this->m_FalloffOffsetVar = v11;
  if ( v6 )
    return false;
  v12 = v3->FindVar(this: v3, a2: "$falloffdistance", a3: (bool *)&pMaterial + 3, a4: false);
  v6 = HIBYTE(pMaterial) == 0;
  this->m_FalloffDistanceVar = v12;
  if ( v6 )
    return false;
  this->m_FalloffAmountVar = v3->FindVar(this: v3, a2: "$falloffamount", a3: (bool *)&pMaterial + 3, a4: false);
  return HIBYTE(pMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x100AECD0
// Name: public: void FourVectors::TransformBy(struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FourVectors::TransformBy(FourVectors *this, const matrix3x4_t *matrix)
{
  __m128 v2; // xmm2
  __m128 v3; // xmm1
  __m128 v4; // xmm4
  __m128 v5; // xmm3
  __m128 z; // xmm5

  v2 = *(__m128 *)&matrix->m_flMatVal[2][0];
  v3 = *(__m128 *)&matrix->m_flMatVal[1][0];
  v4 = _mm_mul_ps(_mm_shuffle_ps(v3, v3, 0), this->x);
  v5 = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v2, v2, 0), this->x), _mm_mul_ps(_mm_shuffle_ps(v2, v2, 85), this->y));
  z = this->z;
  this->x = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_shuffle_ps(*(__m128 *)&matrix->m_flMatVal[0][0], *(__m128 *)&matrix->m_flMatVal[0][0], 85),
                    this->y),
                  _mm_mul_ps(
                    _mm_shuffle_ps(*(__m128 *)&matrix->m_flMatVal[0][0], *(__m128 *)&matrix->m_flMatVal[0][0], 0),
                    this->x)),
                _mm_mul_ps(
                  _mm_shuffle_ps(*(__m128 *)&matrix->m_flMatVal[0][0], *(__m128 *)&matrix->m_flMatVal[0][0], 170),
                  z)),
              _mm_shuffle_ps((__m128)LODWORD(matrix->m_flMatVal[0][3]), (__m128)LODWORD(matrix->m_flMatVal[0][3]), 0));
  this->y = _mm_add_ps(
              _mm_add_ps(
                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v3, v3, 85), this->y), v4),
                _mm_mul_ps(_mm_shuffle_ps(v3, v3, 170), z)),
              _mm_shuffle_ps((__m128)LODWORD(matrix->m_flMatVal[1][3]), (__m128)LODWORD(matrix->m_flMatVal[1][3]), 0));
  this->z = _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v2, v2, 170), z), v5),
              _mm_shuffle_ps((__m128)LODWORD(matrix->m_flMatVal[2][3]), (__m128)LODWORD(matrix->m_flMatVal[2][3]), 0));
}

//------------------------------------------------------------------------------
// Address: 0x100AEDB0
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CUtlMultiList<class CPixelVisibilityQuery,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisibilityQuery,unsigned short>::List_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 4;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 10 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AEE60
// Name: private: void CClientShadowMgr::CalculateRenderTargetsAndSizes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::CalculateRenderTargetsAndSizes(CClientShadowMgr *this)
{
  int v2; // eax
  bool v3; // bl
  int m_nValue; // eax
  int v5; // eax
  int v6; // eax
  const char *v7; // eax
  char defaultRes[8]; // [esp+Ch] [ebp-8h] BYREF

  v2 = _CommandLine(a1: this);
  v3 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 12))(a1: v2, a2: "-tools", a3: 0) != 0;
  if ( r_flashlightdepthres.m_pParent != nullptr )
    m_nValue = r_flashlightdepthres.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  this->m_nDepthTextureResolution = m_nValue;
  if ( r_flashlightdepthreshigh.m_pParent != nullptr )
    v5 = r_flashlightdepthreshigh.m_pParent->m_Value.m_nValue;
  else
    v5 = 0;
  this->m_nDepthTextureResolutionHigh = v5;
  if ( v3 )
  {
    strcpy(defaultRes, "2048");
    v6 = _CommandLine(a1: *(_DWORD *)"2048");
    v7 = (const char *)(*(int (__thiscall **)(int, const char *, char *))(*(_DWORD *)v6 + 32))(
                         a1: v6,
                         a2: "-sfm_shadowmapres",
                         a3: defaultRes);
    this->m_nDepthTextureResolution = atoi(nptr: v7);
  }
  this->m_nMaxDepthTextureShadows = v3 ? 8 : 1;
}

//------------------------------------------------------------------------------
// Address: 0x100AEF10
// Name: r_shadowblobbycutoff
// Source: json
//------------------------------------------------------------------------------
void __cdecl r_shadowblobbycutoff(const CCommand *args)
{
  if ( args->m_nArgc == 1 )
  {
    _Msg(a1: "Cutoff area %.2f\n", s_ClientShadowMgr.m_flMinShadowArea);
  }
  else if ( args->m_nArgc == 2 )
  {
    s_ClientShadowMgr.m_flMinShadowArea = atof(nptr: args->m_ppArgv[1]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AEF60
// Name: public: virtual void CClientShadowMgr::SetShadowColor(unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CClientShadowMgr::SetShadowColor(
        CClientShadowMgr *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        unsigned __int8 r,
        unsigned __int8 g,
        unsigned __int8 b)
{
  IMaterial *m_pMaterial; // ecx
  IMaterial *v9; // ecx
  float fr; // [esp+2Ch] [ebp-8h]
  float fg; // [esp+30h] [ebp-4h]
  float fb; // [esp+3Ch] [ebp+8h]

  fr = (float)r * 0.0039215689;
  fg = (float)g * 0.0039215689;
  fb = (float)b * 0.0039215689;
  ((void (__thiscall *)(IMaterial *, _DWORD, _DWORD, _DWORD, int, int))this->m_SimpleShadow.m_pMaterial->ColorModulate)(
    a1: this->m_SimpleShadow.m_pMaterial,
    a2: LODWORD(fr),
    a3: LODWORD(fg),
    a4: LODWORD(fb),
    a5: a3,
    a6: a2);
  if ( this->m_RenderToTextureActive )
  {
    m_pMaterial = this->m_RenderShadow.m_pMaterial;
    if ( m_pMaterial != nullptr )
      m_pMaterial->ColorModulate(
        this: m_pMaterial,
        a2: COERCE_FLOAT(LODWORD(fr)),
        a3: COERCE_FLOAT(LODWORD(fg)),
        a4: COERCE_FLOAT(LODWORD(fb)));
    v9 = this->m_RenderModelShadow.m_pMaterial;
    if ( v9 != nullptr )
      v9->ColorModulate(
        this: v9,
        a2: COERCE_FLOAT(LODWORD(fr)),
        a3: COERCE_FLOAT(LODWORD(fg)),
        a4: COERCE_FLOAT(LODWORD(fb)));
  }
  this->m_AmbientLightColor.r = r;
  this->m_AmbientLightColor.g = g;
  this->m_AmbientLightColor.b = b;
}

//------------------------------------------------------------------------------
// Address: 0x100AF050
// Name: public: virtual class Vector const __near & CClientShadowMgr::GetShadowDirection(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CClientShadowMgr::GetShadowDirection(CClientShadowMgr *this)
{
  const Vector *result; // eax

  if ( (_S6_27 & 1) == 0 )
  {
    _S6_27 |= 1u;
    s_vecDown.x = 0.0;
    s_vecDown.y = 0.0;
    s_vecDown.z = -1.0;
  }
  result = &s_vecDown;
  if ( this->m_RenderToTextureActive )
    return &this->m_SimpleShadowDir;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AF0A0
// Name: private: void CClientShadowMgr::DrawRenderToTextureDebugInfo(class IClientRenderable __near *,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::DrawRenderToTextureDebugInfo(
        CClientShadowMgr *this,
        IClientRenderable *pRenderable,
        const Vector *mins,
        const Vector *maxs)
{
  const QAngle *v4; // eax
  float v5; // xmm0_4
  const Vector *(__thiscall *GetRenderOrigin)(IClientRenderable *); // edx
  Vector *v7; // eax
  float x; // xmm6_4
  float y; // xmm7_4
  float v10; // xmm3_4
  float v11; // xmm5_4
  float v12; // xmm6_4
  float v13; // xmm1_4
  float v14; // xmm3_4
  float z; // xmm7_4
  float v16; // xmm3_4
  float v17; // xmm7_4
  int v18; // eax
  int v19; // eax
  IVDebugOverlay_vtbl *v20; // esi
  int v21; // eax
  Vector vec[3]; // [esp+164h] [ebp-60h] BYREF
  Vector vecOrigin; // [esp+188h] [ebp-3Ch] BYREF
  Vector end2; // [esp+194h] [ebp-30h] BYREF
  Vector vecSize; // [esp+1A0h] [ebp-24h]
  Vector start; // [esp+1ACh] [ebp-18h] BYREF
  Vector end; // [esp+1B8h] [ebp-Ch] BYREF
  const Vector *maxsa; // [esp+1D4h] [ebp+10h]

  v4 = pRenderable->GetRenderAngles(this: pRenderable);
  AngleVectors(angles: v4, forward: vec, right: &vec[1], up: &vec[2]);
  vec[1].x = vec[1].x * -1.0;
  vec[1].y = vec[1].y * -1.0;
  vecSize.x = maxs->x - mins->x;
  vecSize.y = maxs->y - mins->y;
  v5 = maxs->z - mins->z;
  GetRenderOrigin = pRenderable->GetRenderOrigin;
  vec[1].z = vec[1].z * -1.0;
  vecSize.z = v5;
  v7 = GetRenderOrigin(this: pRenderable);
  x = mins->x;
  y = mins->y;
  vecOrigin = *v7;
  v10 = (float)(vec[0].y * x) + vecOrigin.y;
  v11 = vec[0].z * x;
  v12 = (float)(vec[1].x * y) + (float)((float)(vec[0].x * x) + vecOrigin.x);
  v13 = (float)(vec[1].y * y) + v10;
  v14 = vec[1].z * y;
  z = mins->z;
  start.x = (float)(vec[2].x * z) + v12;
  start.y = (float)(vec[2].y * z) + v13;
  start.z = (float)(vec[2].z * z) + (float)(v14 + (float)(v11 + vecOrigin.z));
  end.x = (float)(vec[0].x * vecSize.x) + start.x;
  end2.y = (float)(vec[2].y * vecSize.z) + (float)((float)(vec[0].y * vecSize.x) + start.y);
  end2.z = (float)(vec[2].z * vecSize.z) + (float)((float)(vec[0].z * vecSize.x) + start.z);
  end.y = (float)(vec[0].y * vecSize.x) + start.y;
  end.z = (float)(vec[0].z * vecSize.x) + start.z;
  end2.x = (float)(vec[2].x * vecSize.z) + end.x;
  ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
    a1: debugoverlay,
    a2: &start,
    a3: &end,
    a4: 255,
    a5: 0,
    a6: 0,
    a7: 1,
    a8: 1008981770);
  ((void (__stdcall *)(Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
    a1: &end2,
    a2: &end,
    a3: 255,
    a4: 0,
    a5: 0,
    a6: 1,
    a7: 1008981770);
  end.x = (float)(vec[1].x * vecSize.y) + start.x;
  end2.y = (float)(vec[2].y * vecSize.z) + (float)((float)(vec[1].y * vecSize.y) + start.y);
  end.y = (float)(vec[1].y * vecSize.y) + start.y;
  end.z = (float)(vec[1].z * vecSize.y) + start.z;
  end2.x = (float)(vec[2].x * vecSize.z) + end.x;
  end2.z = (float)(vec[2].z * vecSize.z) + end.z;
  ((void (__stdcall *)(Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
    a1: &start,
    a2: &end,
    a3: 255,
    a4: 0,
    a5: 0,
    a6: 1,
    a7: 1008981770);
  ((void (__stdcall *)(Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
    a1: &end2,
    a2: &end,
    a3: 255,
    a4: 0,
    a5: 0,
    a6: 1,
    a7: 1008981770);
  end.x = (float)(vec[2].x * vecSize.z) + start.x;
  end.y = (float)(vec[2].y * vecSize.z) + start.y;
  end.z = (float)(vec[2].z * vecSize.z) + start.z;
  ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
    a1: debugoverlay,
    a2: &start,
    a3: &end,
    a4: 255,
    a5: 0,
    a6: 0,
    a7: 1,
    a8: 1008981770);
  start = end;
  end.y = (float)(vec[0].y * vecSize.x) + end.y;
  end.x = (float)(vec[0].x * vecSize.x) + end.x;
  end.z = (float)(vec[0].z * vecSize.x) + end.z;
  ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
    a1: debugoverlay,
    a2: &start,
    a3: &end,
    a4: 255,
    a5: 0,
    a6: 0,
    a7: 1,
    a8: 1008981770);
  end.x = (float)(vec[1].x * vecSize.y) + start.x;
  end.y = (float)(vec[1].y * vecSize.y) + start.y;
  end.z = (float)(vec[1].z * vecSize.y) + start.z;
  ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
    a1: debugoverlay,
    a2: &start,
    a3: &end,
    a4: 255,
    a5: 0,
    a6: 0,
    a7: 1,
    a8: 1008981770);
  v16 = (float)(vec[0].z * vecSize.x) + end.z;
  LODWORD(v17) = LODWORD(vecSize.x) ^ _mask__NegFloat_;
  start.x = (float)(vec[0].x * vecSize.x) + end.x;
  end.z = (float)(COERCE_FLOAT(LODWORD(vecSize.x) ^ _mask__NegFloat_) * vec[0].z) + v16;
  start.y = (float)(vec[0].y * vecSize.x) + end.y;
  start.z = v16;
  end.x = (float)(COERCE_FLOAT(LODWORD(vecSize.x) ^ _mask__NegFloat_) * vec[0].x) + start.x;
  end.y = (float)(COERCE_FLOAT(LODWORD(vecSize.x) ^ _mask__NegFloat_) * vec[0].y) + start.y;
  ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
    a1: debugoverlay,
    a2: &start,
    a3: &end,
    a4: 255,
    a5: 0,
    a6: 0,
    a7: 1,
    a8: 1008981770);
  maxsa = (const Vector *)(LODWORD(vecSize.y) ^ _mask__NegFloat_);
  end.x = (float)(COERCE_FLOAT(LODWORD(vecSize.y) ^ _mask__NegFloat_) * vec[1].x) + start.x;
  end.z = (float)(COERCE_FLOAT(LODWORD(vecSize.y) ^ _mask__NegFloat_) * vec[1].z) + start.z;
  end.y = (float)(COERCE_FLOAT(LODWORD(vecSize.y) ^ _mask__NegFloat_) * vec[1].y) + start.y;
  ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
    a1: debugoverlay,
    a2: &start,
    a3: &end,
    a4: 255,
    a5: 0,
    a6: 0,
    a7: 1,
    a8: 1008981770);
  end.x = (float)(vec[2].x * COERCE_FLOAT(LODWORD(vecSize.z) ^ _mask__NegFloat_)) + start.x;
  end.y = (float)(vec[2].y * COERCE_FLOAT(LODWORD(vecSize.z) ^ _mask__NegFloat_)) + start.y;
  end.z = (float)(vec[2].z * COERCE_FLOAT(LODWORD(vecSize.z) ^ _mask__NegFloat_)) + start.z;
  ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
    a1: debugoverlay,
    a2: &start,
    a3: &end,
    a4: 255,
    a5: 0,
    a6: 0,
    a7: 1,
    a8: 1008981770);
  start = end;
  end.z = (float)(v17 * vec[0].z) + end.z;
  end.x = (float)(v17 * vec[0].x) + end.x;
  end.y = (float)(v17 * vec[0].y) + end.y;
  ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
    a1: debugoverlay,
    a2: &start,
    a3: &end,
    a4: 255,
    a5: 0,
    a6: 0,
    a7: 1,
    a8: 1008981770);
  end.x = (float)(*(float *)&maxsa * vec[1].x) + start.x;
  end.z = (float)(*(float *)&maxsa * vec[1].z) + start.z;
  end.y = (float)(*(float *)&maxsa * vec[1].y) + start.y;
  ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, _DWORD, _DWORD, int, int))debugoverlay->AddLineOverlay)(
    a1: debugoverlay,
    a2: &start,
    a3: &end,
    a4: 255,
    a5: 0,
    a6: 0,
    a7: 1,
    a8: 1008981770);
  v18 = pRenderable->GetIClientUnknown(this: pRenderable);
  v19 = (*(int (__thiscall **)(int))(*(_DWORD *)v18 + 28))(a1: v18);
  if ( v19 != 0 )
  {
    v20 = debugoverlay->__vftable;
    v21 = (*(int (__thiscall **)(int))(*(_DWORD *)(v19 + 8) + 40))(a1: v19 + 8);
    ((void (*)(IVDebugOverlay *, Vector *, _DWORD, const char *, ...))v20->AddTextOverlay_2)(
      a1: debugoverlay,
      a2: &vecOrigin,
      a3: 0,
      a4: "%d",
      v21);
  }
  else
  {
    ((void (*)(IVDebugOverlay *, Vector *, _DWORD, const char *, ...))debugoverlay->AddTextOverlay_2)(
      a1: debugoverlay,
      a2: &vecOrigin,
      a3: 0,
      a4: "%X",
      pRenderable);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AF7D0
// Name: private: void CClientShadowMgr::DrawFrustum(class Vector const __near &,class VMatrix const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::DrawFrustum(
        CClientShadowMgr *this,
        const Vector *vOrigin,
        const VMatrix *matWorldToFlashlight)
{
  VMatrix flashlightToWorld; // [esp+18Ch] [ebp-70h] BYREF
  Vector dst; // [esp+1CCh] [ebp-30h] BYREF
  Vector v5; // [esp+1D8h] [ebp-24h] BYREF
  Vector v6; // [esp+1E4h] [ebp-18h] BYREF
  Vector src2; // [esp+1F0h] [ebp-Ch] BYREF

  MatrixInverseGeneral(src: matWorldToFlashlight, dst: &flashlightToWorld);
  v6.x = 0.0;
  v6.y = 0.0;
  v6.z = 1.0;
  memset((void *)&src2, 0, sizeof(src2));
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, &src2, &dst);
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, src2: &v6, dst: &v5);
  ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int, int, _DWORD, int))debugoverlay->AddLineOverlay)(
    a1: debugoverlay,
    a2: &dst,
    a3: &v5,
    a4: 255,
    a5: 255,
    a6: 255,
    a7: 0,
    a8: -1082130432);
  src2.x = 0.0;
  src2.y = 1.0;
  src2.z = 1.0;
  v6.x = 0.0;
  v6.y = 0.0;
  v6.z = 1.0;
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, src2: &v6, dst: &v5);
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, &src2, &dst);
  ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int, int, _DWORD, int))debugoverlay->AddLineOverlay)(
    a1: debugoverlay,
    a2: &v5,
    a3: &dst,
    a4: 255,
    a5: 255,
    a6: 255,
    a7: 0,
    a8: -1082130432);
  src2.x = 0.0;
  src2.y = 1.0;
  src2.z = 0.0;
  v6.x = 0.0;
  v6.y = 1.0;
  v6.z = 1.0;
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, src2: &v6, dst: &v5);
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, &src2, &dst);
  ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int, int, _DWORD, int))debugoverlay->AddLineOverlay)(
    a1: debugoverlay,
    a2: &v5,
    a3: &dst,
    a4: 255,
    a5: 255,
    a6: 255,
    a7: 0,
    a8: -1082130432);
  memset((void *)&src2, 0, sizeof(src2));
  v6.x = 0.0;
  v6.y = 1.0;
  v6.z = 0.0;
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, src2: &v6, dst: &v5);
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, &src2, &dst);
  ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int, int, _DWORD, int))debugoverlay->AddLineOverlay)(
    a1: debugoverlay,
    a2: &v5,
    a3: &dst,
    a4: 255,
    a5: 255,
    a6: 255,
    a7: 0,
    a8: -1082130432);
  src2.x = 1.0;
  src2.y = 0.0;
  src2.z = 1.0;
  v6.x = 1.0;
  v6.y = 0.0;
  v6.z = 0.0;
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, src2: &v6, dst: &v5);
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, &src2, &dst);
  ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int, int, _DWORD, int))debugoverlay->AddLineOverlay)(
    a1: debugoverlay,
    a2: &v5,
    a3: &dst,
    a4: 255,
    a5: 255,
    a6: 255,
    a7: 0,
    a8: -1082130432);
  src2.x = 1.0;
  src2.y = 1.0;
  src2.z = 1.0;
  v6.x = 1.0;
  v6.y = 0.0;
  v6.z = 1.0;
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, src2: &v6, dst: &v5);
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, &src2, &dst);
  ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int, int, _DWORD, int))debugoverlay->AddLineOverlay)(
    a1: debugoverlay,
    a2: &v5,
    a3: &dst,
    a4: 255,
    a5: 255,
    a6: 255,
    a7: 0,
    a8: -1082130432);
  src2.x = 1.0;
  src2.y = 1.0;
  src2.z = 0.0;
  v6.x = 1.0;
  v6.y = 1.0;
  v6.z = 1.0;
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, src2: &v6, dst: &v5);
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, &src2, &dst);
  ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int, int, _DWORD, int))debugoverlay->AddLineOverlay)(
    a1: debugoverlay,
    a2: &v5,
    a3: &dst,
    a4: 255,
    a5: 255,
    a6: 255,
    a7: 0,
    a8: -1082130432);
  src2.x = 1.0;
  src2.y = 0.0;
  src2.z = 0.0;
  v6.x = 1.0;
  v6.y = 1.0;
  v6.z = 0.0;
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, src2: &v6, dst: &v5);
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, &src2, &dst);
  ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int, int, _DWORD, int))debugoverlay->AddLineOverlay)(
    a1: debugoverlay,
    a2: &v5,
    a3: &dst,
    a4: 255,
    a5: 255,
    a6: 255,
    a7: 0,
    a8: -1082130432);
  src2.x = 1.0;
  src2.y = 0.0;
  src2.z = 0.0;
  memset((void *)&v6, 0, sizeof(v6));
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, src2: &v6, dst: &v5);
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, &src2, &dst);
  ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int, int, _DWORD, int))debugoverlay->AddLineOverlay)(
    a1: debugoverlay,
    a2: &v5,
    a3: &dst,
    a4: 255,
    a5: 255,
    a6: 255,
    a7: 0,
    a8: -1082130432);
  src2.x = 1.0;
  src2.y = 0.0;
  src2.z = 1.0;
  v6.x = 0.0;
  v6.y = 0.0;
  v6.z = 1.0;
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, src2: &v6, dst: &v5);
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, &src2, &dst);
  ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int, int, _DWORD, int))debugoverlay->AddLineOverlay)(
    a1: debugoverlay,
    a2: &v5,
    a3: &dst,
    a4: 255,
    a5: 255,
    a6: 255,
    a7: 0,
    a8: -1082130432);
  src2.x = 1.0;
  src2.y = 1.0;
  src2.z = 1.0;
  v6.x = 0.0;
  v6.y = 1.0;
  v6.z = 1.0;
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, src2: &v6, dst: &v5);
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, &src2, &dst);
  ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int, int, _DWORD, int))debugoverlay->AddLineOverlay)(
    a1: debugoverlay,
    a2: &v5,
    a3: &dst,
    a4: 255,
    a5: 255,
    a6: 255,
    a7: 0,
    a8: -1082130432);
  src2.x = 1.0;
  src2.y = 1.0;
  src2.z = 0.0;
  v6.x = 0.0;
  v6.y = 1.0;
  v6.z = 0.0;
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, src2: &v6, dst: &v5);
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, &src2, &dst);
  ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int, int, _DWORD, int))debugoverlay->AddLineOverlay)(
    a1: debugoverlay,
    a2: &v5,
    a3: &dst,
    a4: 255,
    a5: 255,
    a6: 255,
    a7: 0,
    a8: -1082130432);
  src2.x = 1.0;
  src2.y = 0.5;
  src2.z = 0.0;
  v6.x = 0.5;
  v6.y = 0.5;
  v6.z = 0.0;
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, src2: &v6, dst: &v5);
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, &src2, &dst);
  ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, _DWORD, _DWORD, _DWORD, int))debugoverlay->AddLineOverlay)(
    a1: debugoverlay,
    a2: &v5,
    a3: &dst,
    a4: 255,
    a5: 0,
    a6: 0,
    a7: 0,
    a8: -1082130432);
  src2.y = 1.0;
  src2.x = 0.5;
  src2.z = 0.0;
  v6.x = 0.5;
  v6.y = 0.5;
  v6.z = 0.0;
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, src2: &v6, dst: &v5);
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, &src2, &dst);
  ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, _DWORD, int, _DWORD, _DWORD, int))debugoverlay->AddLineOverlay)(
    a1: debugoverlay,
    a2: &v5,
    a3: &dst,
    a4: 0,
    a5: 255,
    a6: 0,
    a7: 0,
    a8: -1082130432);
  src2.x = 0.5;
  src2.y = 0.5;
  v6.x = 0.5;
  v6.y = 0.5;
  src2.z = 0.34999999;
  v6.z = 0.0;
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, src2: &v6, dst: &v5);
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, &src2, &dst);
  ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, _DWORD, _DWORD, int, _DWORD, int))debugoverlay->AddLineOverlay)(
    a1: debugoverlay,
    a2: &v5,
    a3: &dst,
    a4: 0,
    a5: 0,
    a6: 255,
    a7: 0,
    a8: -1082130432);
}

//------------------------------------------------------------------------------
// Address: 0x100AFF80
// Name: public: virtual void CClientShadowMgr::AddToDirtyShadowList(class IClientRenderable __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::AddToDirtyShadowList(
        CClientShadowMgr *this,
        IClientRenderable *pRenderable,
        BOOL bForce)
{
  DWORD CurrentThreadId; // ecx
  int v5; // edi

  if ( !this->m_bUpdatingDirtyShadows )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != g_DirtyListAddMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&g_DirtyListAddMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &g_DirtyListAddMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++g_DirtyListAddMutex.m_depth;
    }
    if ( pRenderable->IsShadowDirty(this: pRenderable) )
    {
      if ( --g_DirtyListAddMutex.m_depth != 0 )
        return;
    }
    else
    {
      v5 = pRenderable->GetShadowHandle(this: pRenderable);
      if ( (_WORD)v5 == 0xFFFF )
      {
        if ( --g_DirtyListAddMutex.m_depth != 0 )
          return;
      }
      else
      {
        pRenderable->MarkShadowDirty(this: pRenderable, a2: true);
        this->AddToDirtyShadowList_2(this, a2: v5, a3: bForce);
        if ( --g_DirtyListAddMutex.m_depth != 0 )
          return;
      }
    }
    _InterlockedExchange((volatile __int32 *)&g_DirtyListAddMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B0070
// Name: public: virtual void CClientShadowMgr::UpdateSplitscreenLocalPlayerShadowSkip(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::UpdateSplitscreenLocalPlayerShadowSkip(CClientShadowMgr *this)
{
  C_BasePlayer *LocalPlayer; // esi
  bool v2; // zf
  C_BasePlayer_vtbl *v3; // eax
  IShadowMgr_vtbl *v4; // edi
  int v5; // eax

  if ( engine->IsSplitScreenActive(this: engine) )
  {
    LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    if ( LocalPlayer != nullptr )
    {
      v2 = LocalPlayer->GetObserverMode(this: LocalPlayer) == 4;
      v3 = LocalPlayer->C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
      if ( v2 )
      {
        LocalPlayer = (C_BasePlayer *)v3->GetObserverTarget(this: LocalPlayer);
        if ( LocalPlayer == nullptr || !LocalPlayer->IsPlayer(this: LocalPlayer) )
          goto LABEL_6;
        goto LABEL_8;
      }
      if ( v3->GetObserverMode(this: LocalPlayer) == 0 )
      {
LABEL_8:
        v4 = shadowmgr->__vftable;
        v5 = LocalPlayer->entindex(this: &LocalPlayer->IClientNetworkable);
        v4->SkipShadowForEntity(this: shadowmgr, a2: v5);
        return;
      }
    }
LABEL_6:
    shadowmgr->SkipShadowForEntity(this: shadowmgr, a2: 0x80000000);
    return;
  }
  shadowmgr->SkipShadowForEntity(this: shadowmgr, a2: 0x80000000);
}

//------------------------------------------------------------------------------
// Address: 0x100B0130
// Name: public: virtual void CShadowProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowProxy::OnBind(CShadowProxy *this, void *pProxyData)
{
  this->m_BaseTextureVar->SetTextureValue(
    this: this->m_BaseTextureVar,
    a2: s_ClientShadowMgr.m_ShadowAllocator.m_TexturePage.m_pTexture);
  ((void (__stdcall *)(int))this->m_MaxFalloffAmountVar->SetFloatValue)(a1: 1131413504);
}

//------------------------------------------------------------------------------
// Address: 0x100B0160
// Name: CCShadowProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCShadowProxyFactory()
{
  IMaterialProxy *result; // eax

  result = (IMaterialProxy *)MemAlloc_Alloc(nSize: 0xCu);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (IMaterialProxy_vtbl *)&CShadowProxy::`vftable';
  result[1].__vftable = nullptr;
  result[2].__vftable = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B0180
// Name: CCShadowModelProxyFactory
// Source: json
//------------------------------------------------------------------------------
IMaterialProxy *__cdecl CCShadowModelProxyFactory()
{
  IMaterialProxy *result; // eax

  result = (IMaterialProxy *)MemAlloc_Alloc(nSize: 0x20u);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (IMaterialProxy_vtbl *)&CShadowModelProxy::`vftable';
  result[1].__vftable = nullptr;
  result[2].__vftable = nullptr;
  result[3].__vftable = nullptr;
  result[4].__vftable = nullptr;
  result[5].__vftable = nullptr;
  result[6].__vftable = nullptr;
  result[7].__vftable = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B0220
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CClientShadowMgr::ClientShadow_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      for ( ; m_nAllocationCount < v5; m_nAllocationCount *= 2 )
        ;
    }
    if ( (unsigned __int16)m_nAllocationCount < v5 )
    {
      if ( (_WORD)m_nAllocationCount != 0 || v5 > 0xFFFF )
      {
        if ( (unsigned __int16)v5 != v5 )
          return;
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( (unsigned __int16)m_nAllocationCount < v5 );
      }
      else
      {
        --m_nAllocationCount;
      }
    }
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 276 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                                  this: _g_pMemAlloc,
                                                                                                  a2: m_pMemory,
                                                                                                  a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                                  this: _g_pMemAlloc,
                                                                                                  a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B0340
// Name: public: void CTextureAllocator::GetTextureRect(unsigned short,int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureAllocator::GetTextureRect(
        CTextureAllocator *this,
        unsigned __int16 handle,
        int *x,
        int *y,
        int *w,
        int *h)
{
  CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::ListElem_t *v6; // eax
  unsigned int m_Block; // edi
  int v8; // esi
  int v9; // edx

  v6 = &this->m_Fragments.m_Memory.m_pMemory[this->m_Textures.m_Memory.m_pMemory[handle].m_Element.m_Fragment];
  m_Block = v6->m_Element.m_Block;
  v8 = 1 << LOBYTE(this->m_Blocks[m_Block].m_FragmentPower);
  v9 = v6->m_Element.m_Index / (256 / v8);
  *x = ((m_Block - 4 * (m_Block >> 2)) << 8) + v8 * (v6->m_Element.m_Index - 256 / v8 * v9);
  *y = (m_Block >> 2 << 8) + v8 * v9;
  *w = v8;
  *h = v8;
}

//------------------------------------------------------------------------------
// Address: 0x100B03D0
// Name: r_shadowcolor
// Source: json
//------------------------------------------------------------------------------
void __cdecl r_shadowcolor(const CCommand *args)
{
  unsigned __int8 v1; // bl
  const char *v2; // eax
  unsigned __int8 v3; // di
  const char *v4; // esi
  unsigned __int8 v5; // al

  if ( args->m_nArgc == 1 )
  {
    _Msg(
      a1: "Shadow color %d %d %d\n",
      s_ClientShadowMgr.m_AmbientLightColor.r,
      s_ClientShadowMgr.m_AmbientLightColor.g,
      s_ClientShadowMgr.m_AmbientLightColor.b);
  }
  else if ( args->m_nArgc == 4 )
  {
    v1 = atoi(nptr: args->m_ppArgv[1]);
    v2 = prType;
    if ( args->m_nArgc > 2 )
      v2 = args->m_ppArgv[2];
    v3 = atoi(nptr: v2);
    if ( args->m_nArgc > 3 )
      v4 = args->m_ppArgv[3];
    else
      v4 = prType;
    v5 = atoi(nptr: v4);
    CClientShadowMgr::SetShadowColor(this: &s_ClientShadowMgr, r: v1, g: v3, b: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B0470
// Name: private: void CClientShadowMgr::UpdateShadowDirectionFromLocalLightSource(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::UpdateShadowDirectionFromLocalLightSource(
        CClientShadowMgr *this,
        unsigned __int16 shadowHandle)
{
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *esi1; // esi
  IClientRenderable *ClientRenderableFromHandle; // eax
  IClientRenderable *v4; // edi
  int m_nValue; // eax
  IVModelRender_vtbl *v6; // ebx
  int v7; // eax
  float x; // xmm0_4
  float m_LightPosLerp; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  float z; // eax
  float v13; // ecx
  CClientShadowMgr *v14; // edi
  float *v15; // eax
  float v16; // xmm4_4
  float y; // xmm5_4
  float v18; // xmm6_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float *v21; // eax
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm5_4
  float v25; // xmm6_4
  float v26; // xmm0_4
  float v27; // xmm3_4
  bool v28; // cc
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm2_4
  float *v34; // eax
  float v35; // xmm1_4
  float v36; // xmm2_4
  Vector lightBrightness; // [esp+18h] [ebp-7Ch] BYREF
  Vector bbMax; // [esp+24h] [ebp-70h] BYREF
  Vector bbMin; // [esp+30h] [ebp-64h] BYREF
  Vector v1; // [esp+3Ch] [ebp-58h] BYREF
  Vector v2; // [esp+48h] [ebp-4Ch] BYREF
  Vector vecResult; // [esp+54h] [ebp-40h] BYREF
  Vector currLightPos; // [esp+60h] [ebp-34h]
  Vector targetLightPos; // [esp+6Ch] [ebp-28h]
  Vector origin; // [esp+78h] [ebp-1Ch] BYREF
  Vector lightPos; // [esp+84h] [ebp-10h] BYREF
  CClientShadowMgr *v47; // [esp+90h] [ebp-4h]

  esi1 = &this->m_Shadows.m_Memory.m_pMemory[shadowHandle];
  v47 = this;
  ClientRenderableFromHandle = CClientEntityList::GetClientRenderableFromHandle(
                                 this: (CClientEntityList *)cl_entitylist.m_Index,
                                 hEnt: esi1->m_Element.m_Entity);
  v4 = ClientRenderableFromHandle;
  if ( ClientRenderableFromHandle == nullptr )
  {
    DevWarning(
      a1: "%s(): Skipping shadow with invalid client renderable (shadow handle %d)\n",
      "CClientShadowMgr::UpdateShadowDirectionFromLocalLightSource",
      shadowHandle);
    return;
  }
  ClientRenderableFromHandle->GetRenderBoundsWorldspace(this: ClientRenderableFromHandle, a2: &bbMin, a3: &bbMax);
  origin.x = (float)(bbMax.x + bbMin.x) * 0.5;
  origin.y = (float)(bbMax.y + bbMin.y) * 0.5;
  origin.z = bbMin.z;
  if ( esi1->m_Element.m_LightPosLerp < 1.0
    || (r_shadowfromanyworldlight.m_pParent == nullptr
      ? (m_nValue = 0)
      : (m_nValue = r_shadowfromanyworldlight.m_pParent->m_Value.m_nValue),
        v6 = modelrender->__vftable,
        v7 = ((int (__thiscall *)(IClientRenderable *, Vector *, Vector *, bool))v4->GetRenderOrigin)(
               a1: v4,
               a2: &lightPos,
               a3: &lightBrightness,
               a4: m_nValue != 0),
        ((unsigned __int8 (__thiscall *)(IVModelRender *, int))v6->GetBrightestShadowingLightSource)(
          a1: modelrender,
          a2: v7) != 0) )
  {
    x = lightPos.x;
  }
  else
  {
    x = 3.4028235e38;
    lightPos.x = 3.4028235e38;
    lightPos.y = 3.4028235e38;
    lightPos.z = 3.4028235e38;
  }
  m_LightPosLerp = esi1->m_Element.m_LightPosLerp;
  if ( m_LightPosLerp != 3.4028235e38 )
  {
    if ( m_LightPosLerp >= 1.0 )
    {
      if ( (float)((float)((float)((float)(lightPos.y - esi1->m_Element.m_CurrentLightPos.y)
                                 * (float)(lightPos.y - esi1->m_Element.m_CurrentLightPos.y))
                         + (float)((float)(x - esi1->m_Element.m_CurrentLightPos.x)
                                 * (float)(x - esi1->m_Element.m_CurrentLightPos.x)))
                 + (float)((float)(lightPos.z - esi1->m_Element.m_CurrentLightPos.z)
                         * (float)(lightPos.z - esi1->m_Element.m_CurrentLightPos.z))) > 1.0 )
      {
        esi1->m_Element.m_TargetLightPos.x = x;
        esi1->m_Element.m_TargetLightPos.y = lightPos.y;
        esi1->m_Element.m_TargetLightPos.z = lightPos.z;
        esi1->m_Element.m_LightPosLerp = 0.0;
      }
      v10 = esi1->m_Element.m_CurrentLightPos.x;
      lightPos.x = v10;
      lightPos.y = esi1->m_Element.m_CurrentLightPos.y;
      lightPos.z = esi1->m_Element.m_CurrentLightPos.z;
      goto LABEL_33;
    }
    v11 = (float)(*(float *)(gpGlobals.m_Index + 16) / r_shadow_lightpos_lerptime.m_pParent->m_Value.m_fValue)
        + m_LightPosLerp;
    esi1->m_Element.m_LightPosLerp = v11;
    if ( v11 >= 0.0 )
    {
      if ( v11 > 1.0 )
        v11 = 1.0;
    }
    else
    {
      v11 = 0.0;
    }
    z = esi1->m_Element.m_CurrentLightPos.z;
    v13 = esi1->m_Element.m_TargetLightPos.z;
    v14 = v47;
    esi1->m_Element.m_LightPosLerp = v11;
    *(_QWORD *)&currLightPos.x = *(_QWORD *)&esi1->m_Element.m_CurrentLightPos.x;
    *(_QWORD *)&targetLightPos.x = *(_QWORD *)&esi1->m_Element.m_TargetLightPos.x;
    currLightPos.z = z;
    targetLightPos.z = v13;
    if ( currLightPos.x == 3.4028235e38 )
    {
      v15 = (float *)v14->GetShadowDirection(this: v14);
      v16 = origin.x;
      y = origin.y;
      v18 = origin.z;
      v19 = origin.y - (float)(v15[1] * 200.0);
      v20 = origin.z - (float)(v15[2] * 200.0);
      currLightPos.x = origin.x - (float)(*v15 * 200.0);
      currLightPos.y = v19;
      currLightPos.z = v20;
    }
    else
    {
      v18 = origin.z;
      y = origin.y;
      v16 = origin.x;
    }
    if ( targetLightPos.x == 3.4028235e38 )
    {
      v21 = (float *)v14->GetShadowDirection(this: v14);
      v16 = origin.x;
      y = origin.y;
      v18 = origin.z;
      v22 = origin.y - (float)(v21[1] * 200.0);
      v23 = origin.z - (float)(v21[2] * 200.0);
      targetLightPos.x = origin.x - (float)(*v21 * 200.0);
      targetLightPos.y = v22;
      targetLightPos.z = v23;
    }
    v24 = y - esi1->m_Element.m_CurrentLightPos.y;
    v25 = v18 - esi1->m_Element.m_CurrentLightPos.z;
    v1.x = v16 - esi1->m_Element.m_CurrentLightPos.x;
    v1.y = v24;
    v1.z = v25;
    VectorNormalize(vec: &v1);
    v2.x = origin.x - esi1->m_Element.m_TargetLightPos.x;
    v2.y = origin.y - esi1->m_Element.m_TargetLightPos.y;
    v2.z = origin.z - esi1->m_Element.m_TargetLightPos.z;
    VectorNormalize(vec: &v2);
    v26 = esi1->m_Element.m_LightPosLerp;
    if ( (float)((float)((float)(v2.y * v1.y) + (float)(v2.x * v1.x)) + (float)(v2.z * v1.z)) >= 0.0 )
    {
      v29 = targetLightPos.x;
      v30 = targetLightPos.y;
      v27 = targetLightPos.z;
    }
    else
    {
      v27 = origin.z + 200.0;
      v28 = v26 >= 0.5;
      v26 = v26 * 2.0;
      if ( v28 )
      {
        v31 = v26 - 1.0;
        v32 = (float)((float)(targetLightPos.x - origin.x) * v31) + origin.x;
        v33 = (float)((float)(targetLightPos.y - origin.y) * v31) + origin.y;
        lightPos.z = (float)((float)(targetLightPos.z - v27) * v31) + v27;
        goto LABEL_28;
      }
      v29 = origin.x;
      v30 = origin.y;
    }
    v32 = (float)((float)(v29 - currLightPos.x) * v26) + currLightPos.x;
    v33 = (float)((float)(v30 - currLightPos.y) * v26) + currLightPos.y;
    lightPos.z = (float)((float)(v27 - currLightPos.z) * v26) + currLightPos.z;
LABEL_28:
    v10 = v32;
    lightPos.x = v32;
    lightPos.y = v33;
    if ( esi1->m_Element.m_LightPosLerp >= 1.0 )
    {
      esi1->m_Element.m_CurrentLightPos.x = esi1->m_Element.m_TargetLightPos.x;
      esi1->m_Element.m_CurrentLightPos.y = esi1->m_Element.m_TargetLightPos.y;
      esi1->m_Element.m_CurrentLightPos.z = esi1->m_Element.m_TargetLightPos.z;
      v10 = lightPos.x;
    }
    goto LABEL_34;
  }
  esi1->m_Element.m_CurrentLightPos.x = x;
  esi1->m_Element.m_CurrentLightPos.y = lightPos.y;
  esi1->m_Element.m_CurrentLightPos.z = lightPos.z;
  esi1->m_Element.m_TargetLightPos = lightPos;
  esi1->m_Element.m_LightPosLerp = 1.0;
  v10 = lightPos.x;
LABEL_33:
  v14 = v47;
LABEL_34:
  if ( v10 == 3.4028235e38 )
  {
    v34 = (float *)v14->GetShadowDirection(this: v14);
    v10 = origin.x - (float)(*v34 * 200.0);
    v35 = origin.y - (float)(v34[1] * 200.0);
    v36 = origin.z - (float)(v34[2] * 200.0);
    lightPos.x = v10;
    lightPos.y = v35;
    lightPos.z = v36;
  }
  vecResult.y = origin.y - lightPos.y;
  vecResult.x = origin.x - v10;
  vecResult.z = origin.z - lightPos.z;
  VectorNormalize(vec: &vecResult);
  vecResult.z = r_shadow_shortenfactor.m_pParent->m_Value.m_fValue * vecResult.z;
  VectorNormalize(vec: &vecResult);
  esi1->m_Element.m_ShadowDir = vecResult;
  if ( r_shadowfromworldlights_debug.m_pParent != nullptr
    && r_shadowfromworldlights_debug.m_pParent->m_Value.m_nValue != 0 )
  {
    NDebugOverlay::Line(origin: &lightPos, target: &origin, r: 255, g: 255, b: 0, noDepthTest: false, duration: 0.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B0AC0
// Name: public: virtual void CClientShadowMgr::SetFalloffBias(unsigned short,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::SetFalloffBias(CClientShadowMgr *this, unsigned __int16 handle, int ucBias)
{
  int v3; // esi

  v3 = handle;
  shadowmgr->SetFalloffBias(
    this: shadowmgr,
    a2: this->m_Shadows.m_Memory.m_pMemory[v3].m_Element.m_ShadowHandle,
    a3: ucBias);
  this->m_Shadows.m_Memory.m_pMemory[v3].m_Element.m_FalloffBias = (unsigned __int8)ucBias;
}

//------------------------------------------------------------------------------
// Address: 0x100B0B00
// Name: private: void CClientShadowMgr::DestroyQueuedShadows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::DestroyQueuedShadows(CClientShadowMgr *this)
{
  int v2; // edi

  v2 = 0;
  if ( this->m_shadowsToDestroy.m_Size <= 0 )
  {
    this->m_shadowsToDestroy.m_Size = 0;
  }
  else
  {
    do
      this->DestroyShadow(this, a2: this->m_shadowsToDestroy.m_Memory.m_pMemory[v2++]);
    while ( v2 < this->m_shadowsToDestroy.m_Size );
    this->m_shadowsToDestroy.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B0B50
// Name: private: void CClientShadowMgr::BuildWorldToShadowMatrix(class VMatrix __near &,class Vector const __near &,class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::BuildWorldToShadowMatrix(
        CClientShadowMgr *this,
        VMatrix *matWorldToShadow,
        const Vector *origin,
        const Quaternion *quatOrientation)
{
  const VMatrix *v4; // eax
  float y; // xmm1_4
  float z; // xmm2_4
  VMatrix result; // [esp+4h] [ebp-BCh] BYREF
  VMatrix matBasis; // [esp+44h] [ebp-7Ch] BYREF
  Vector translation; // [esp+84h] [ebp-3Ch] BYREF
  matrix3x4_t matOrientation; // [esp+90h] [ebp-30h] BYREF

  QuaternionMatrix(q: quatOrientation, matrix: &matOrientation);
  MatrixSetColumn(in: &vec3_origin, column: 3, out: &matOrientation);
  *(_QWORD *)&matBasis.m[3][0] = 0;
  *(_QWORD *)&matBasis.m[3][2] = 0x3F80000000000000LL;
  *(_QWORD *)&matBasis.m[0][0] = *(_QWORD *)&matOrientation.m_flMatVal[0][1];
  *(_QWORD *)&matBasis.m[1][0] = *(_QWORD *)&matOrientation.m_flMatVal[1][1];
  *(_QWORD *)&matBasis.m[2][0] = *(_QWORD *)&matOrientation.m_flMatVal[2][1];
  *(_QWORD *)&matBasis.m[0][2] = __PAIR64__(
                                   LODWORD(matOrientation.m_flMatVal[0][3]),
                                   LODWORD(matOrientation.m_flMatVal[0][0]));
  *(_QWORD *)&matBasis.m[1][2] = __PAIR64__(
                                   LODWORD(matOrientation.m_flMatVal[1][3]),
                                   LODWORD(matOrientation.m_flMatVal[1][0]));
  *(_QWORD *)&matBasis.m[2][2] = __PAIR64__(
                                   LODWORD(matOrientation.m_flMatVal[2][3]),
                                   LODWORD(matOrientation.m_flMatVal[2][0]));
  v4 = VMatrix::Transpose(this: &matBasis, &result);
  VMatrix::operator=(this: matWorldToShadow, mOther: v4);
  Vector3DMultiply(src1: matWorldToShadow, src2: origin, dst: &translation);
  y = translation.y;
  z = translation.z;
  matWorldToShadow->m[0][3] = translation.x * -1.0;
  matWorldToShadow->m[1][3] = y * -1.0;
  matWorldToShadow->m[2][3] = z * -1.0;
  *(_QWORD *)&matWorldToShadow->m[3][1] = 0;
  matWorldToShadow->m[3][0] = 0.0;
  matWorldToShadow->m[3][3] = 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x100B0CC0
// Name: private: void CClientShadowMgr::BuildPerspectiveWorldToFlashlightMatrix(class VMatrix __near &,struct FlashlightState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::BuildPerspectiveWorldToFlashlightMatrix(
        CClientShadowMgr *this,
        VMatrix *matWorldToShadow,
        const FlashlightState_t *flashlightState)
{
  VMatrix matPerspective; // [esp+2Ch] [ebp-80h] BYREF
  VMatrix matWorldToShadowView; // [esp+6Ch] [ebp-40h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CClientShadowMgr::BuildPerspectiveWorldToFlashlightMatrix",
    a3: 0,
    a4: "Flashlight Shadows",
    a5: false,
    a6: 4);
  CClientShadowMgr::BuildWorldToShadowMatrix(
    this,
    matWorldToShadow: &matWorldToShadowView,
    origin: &flashlightState->m_vecLightOrigin,
    quatOrientation: &flashlightState->m_quatOrientation);
  MatrixBuildPerspective(
    dst: &matPerspective,
    fovX: flashlightState->m_fHorizontalFOVDegrees,
    fovY: flashlightState->m_fVerticalFOVDegrees,
    zNear: flashlightState->m_NearZ,
    zFar: flashlightState->m_FarZ);
  MatrixMultiply(src1: &matPerspective, src2: &matWorldToShadowView, dst: matWorldToShadow);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x100B0D60
// Name: private: void CClientShadowMgr::BuildOrthoWorldToFlashlightMatrix(class VMatrix __near &,struct FlashlightState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::BuildOrthoWorldToFlashlightMatrix(
        CClientShadowMgr *this,
        VMatrix *matWorldToShadow,
        const FlashlightState_t *flashlightState)
{
  VMatrix matWorldToShadowView; // [esp+4Ch] [ebp-100h] BYREF
  VMatrix scaleHalf; // [esp+8Ch] [ebp-C0h] BYREF
  VMatrix addW; // [esp+CCh] [ebp-80h] BYREF
  VMatrix matPerspective; // [esp+10Ch] [ebp-40h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CClientShadowMgr::BuildPerspectiveWorldToFlashlightMatrix",
    a3: 0,
    a4: "Flashlight Shadows",
    a5: false,
    a6: 4);
  CClientShadowMgr::BuildWorldToShadowMatrix(
    this,
    matWorldToShadow: &matWorldToShadowView,
    origin: &flashlightState->m_vecLightOrigin,
    quatOrientation: &flashlightState->m_quatOrientation);
  MatrixBuildOrtho(
    dst: &matPerspective,
    left: flashlightState->m_fOrthoLeft,
    top: flashlightState->m_fOrthoTop,
    right: flashlightState->m_fOrthoRight,
    bottom: flashlightState->m_fOrthoBottom,
    zNear: flashlightState->m_NearZ,
    zFar: flashlightState->m_FarZ);
  MatrixSetIdentity(dst: &addW);
  addW.m[0][3] = -1.0;
  addW.m[1][3] = -1.0;
  addW.m[2][3] = 0.0;
  MatrixMultiply(src1: &addW, src2: &matPerspective, dst: &matPerspective);
  MatrixSetIdentity(dst: &scaleHalf);
  scaleHalf.m[0][0] = -0.5;
  scaleHalf.m[1][1] = -0.5;
  scaleHalf.m[2][2] = -1.0;
  MatrixMultiply(src1: &scaleHalf, src2: &matPerspective, dst: &matPerspective);
  MatrixMultiply(src1: &matPerspective, src2: &matWorldToShadowView, dst: matWorldToShadow);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x100B0EB0
// Name: private: void CClientShadowMgr::ComputeExtraClipPlanes(class IClientRenderable __near *,unsigned short,class Vector const __near *,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::ComputeExtraClipPlanes(
        CClientShadowMgr *this,
        IClientRenderable *pRenderable,
        unsigned __int16 handle,
        const Vector *vec,
        const Vector *mins,
        const Vector *maxs,
        const Vector *localShadowDir)
{
  const Vector *(__thiscall *GetRenderOrigin)(IClientRenderable *); // edx
  int v9; // eax
  __int64 v10; // xmm0_8
  bool v11; // cc
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  float *p_z; // esi
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm3_4
  float v20; // xmm2_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm5_4
  float v24; // xmm4_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm5_4
  float v29; // xmm4_4
  float v30; // xmm5_4
  float v31; // xmm3_4
  float v32; // xmm6_4
  float v33; // xmm2_4
  ConVar *m_pParent; // eax
  unsigned __int16 v35; // bx
  float v36; // xmm4_4
  float v37; // xmm3_4
  int i; // edi
  float v39; // xmm0_4
  float v40; // xmm6_4
  float v41; // xmm5_4
  float v42; // xmm0_4
  CClientShadowMgr *v43; // edi
  int v44; // esi
  C_BaseEntity *BaseEntityFromHandle; // eax
  float dir[3]; // [esp+20h] [ebp-28h]
  Vector normal; // [esp+2Ch] [ebp-1Ch] BYREF
  Vector origin; // [esp+38h] [ebp-10h]
  CClientShadowMgr *v49; // [esp+44h] [ebp-4h]

  GetRenderOrigin = pRenderable->GetRenderOrigin;
  v49 = this;
  v9 = (int)GetRenderOrigin(this: pRenderable);
  v10 = *(_QWORD *)v9;
  v11 = localShadowDir->x >= 0.0;
  origin.z = *(float *)(v9 + 8);
  x = vec->x;
  y = vec->y;
  z = vec->z;
  p_z = &vec->z;
  *(_QWORD *)&origin.x = v10;
  if ( v11 )
  {
    v16 = x * mins->x;
    v17 = y * mins->x;
    v18 = z * mins->x;
    dir[0] = -1.0;
  }
  else
  {
    v16 = x * maxs->x;
    v17 = y * maxs->x;
    v18 = z * maxs->x;
    dir[0] = 1.0;
  }
  v19 = v18 + origin.z;
  v20 = v17 + origin.y;
  v21 = v16 + origin.x;
  v22 = vec[1].x;
  v23 = vec[1].z;
  if ( localShadowDir->y >= 0.0 )
  {
    v24 = mins->y;
    v25 = (float)(v22 * v24) + v21;
    v26 = (float)(vec[1].y * v24) + v20;
    dir[1] = -1.0;
  }
  else
  {
    v24 = maxs->y;
    v25 = (float)(v22 * v24) + v21;
    v26 = (float)(vec[1].y * v24) + v20;
    dir[1] = 1.0;
  }
  v27 = vec[2].x;
  v28 = v23 * v24;
  v29 = vec[2].z;
  v30 = v28 + v19;
  v31 = vec[2].y;
  if ( localShadowDir->z >= 0.0 )
  {
    v32 = mins->z;
    v33 = (float)(v27 * v32) + v25;
    dir[2] = -1.0;
  }
  else
  {
    v32 = maxs->z;
    v33 = (float)(v27 * v32) + v25;
    dir[2] = 1.0;
  }
  m_pParent = r_shadow_deferred.m_pParent;
  v35 = handle;
  v36 = (float)(v29 * v32) + v30;
  v37 = (float)(v31 * v32) + v26;
  origin.z = v36;
  origin.y = v37;
  origin.x = v33;
  if ( r_shadow_deferred.m_pParent == nullptr || r_shadow_deferred.m_pParent->m_Value.m_nValue == 0 )
  {
    ((void (__stdcall *)(_DWORD))shadowmgr->ClearExtraClipPlanes)(a1: this->m_Shadows.m_Memory.m_pMemory[handle].m_Element.m_ShadowHandle);
    m_pParent = r_shadow_deferred.m_pParent;
    v36 = origin.z;
    v37 = origin.y;
    v33 = origin.x;
  }
  for ( i = 0; i < 3; ++i )
  {
    v39 = dir[i];
    v40 = *(p_z - 1) * v39;
    v41 = *(p_z - 2) * v39;
    v42 = v39 * *p_z;
    normal.y = v40;
    normal.z = v42;
    normal.x = v41;
    if ( m_pParent == nullptr || m_pParent->m_Value.m_nValue == 0 )
    {
      ((void (__stdcall *)(_DWORD, Vector *, _DWORD))shadowmgr->AddExtraClipPlane)(
        a1: v49->m_Shadows.m_Memory.m_pMemory[v35].m_Element.m_ShadowHandle,
        a2: &normal,
        a3: (float)((float)(v37 * v40) + (float)(v33 * v41)) + (float)(v42 * v36));
      m_pParent = r_shadow_deferred.m_pParent;
      v36 = origin.z;
      v37 = origin.y;
      v33 = origin.x;
      v35 = handle;
    }
    p_z += 3;
  }
  v43 = v49;
  v44 = v35;
  BaseEntityFromHandle = CClientEntityList::GetBaseEntityFromHandle(
                           this: (CClientEntityList *)cl_entitylist.m_Index,
                           hEnt: v49->m_Shadows.m_Memory.m_pMemory[v44].m_Element.m_Entity);
  if ( BaseEntityFromHandle != nullptr && BaseEntityFromHandle->m_bEnableRenderingClipPlane )
  {
    normal.x = -BaseEntityFromHandle->m_fRenderingClipPlane[0];
    normal.y = -BaseEntityFromHandle->m_fRenderingClipPlane[1];
    normal.z = -BaseEntityFromHandle->m_fRenderingClipPlane[2];
    if ( r_shadow_deferred.m_pParent == nullptr || r_shadow_deferred.m_pParent->m_Value.m_nValue == 0 )
      ((void (__stdcall *)(_DWORD, Vector *, _DWORD))shadowmgr->AddExtraClipPlane)(
        a1: v43->m_Shadows.m_Memory.m_pMemory[v44].m_Element.m_ShadowHandle,
        a2: &normal,
        a3: (float)-BaseEntityFromHandle->m_fRenderingClipPlane[3] - 0.5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B11C0
// Name: private: enum ShadowType_t CClientShadowMgr::GetActualShadowCastType(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CClientShadowMgr::GetActualShadowCastType(CClientShadowMgr *this, unsigned __int16 handle)
{
  unsigned __int16 m_Flags; // ax
  int m_RenderToTextureActive; // eax

  if ( handle == 0xFFFF )
    return 0;
  m_Flags = this->m_Shadows.m_Memory.m_pMemory[handle].m_Element.m_Flags;
  if ( (m_Flags & 8) != 0 )
    m_RenderToTextureActive = this->m_RenderToTextureActive;
  else
    m_RenderToTextureActive = (m_Flags & 0x20) != 0 ? 3 : 0;
  return m_RenderToTextureActive + 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B1210
// Name: private: enum ShadowType_t CClientShadowMgr::GetActualShadowCastType(class IClientRenderable __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CClientShadowMgr::GetActualShadowCastType(CClientShadowMgr *this, IClientRenderable *pEnt)
{
  unsigned __int16 v3; // ax
  unsigned __int16 m_Flags; // ax
  int m_RenderToTextureActive; // eax

  v3 = pEnt->GetShadowHandle(this: pEnt);
  if ( v3 == 0xFFFF )
    return 0;
  m_Flags = this->m_Shadows.m_Memory.m_pMemory[v3].m_Element.m_Flags;
  if ( (m_Flags & 8) != 0 )
    m_RenderToTextureActive = this->m_RenderToTextureActive;
  else
    m_RenderToTextureActive = (m_Flags & 0x20) != 0 ? 3 : 0;
  return m_RenderToTextureActive + 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B1270
// Name: LineDrawHelper
// Source: json
//------------------------------------------------------------------------------
void __usercall LineDrawHelper(
        const Vector *end@<edx>,
        const VMatrix *viewMatrixInverse@<eax>,
        const Vector *start,
        unsigned __int8 r,
        unsigned __int8 g,
        unsigned __int8 b)
{
  float y; // xmm6_4
  float v8; // xmm3_4
  float v9; // xmm0_4
  float v10; // xmm4_4
  float v11; // xmm2_4
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm5_4
  float v15; // xmm2_4
  float v16; // xmm7_4
  float x; // xmm6_4
  float v18; // xmm2_4
  Vector startWorldSpace; // [esp+4h] [ebp-24h] BYREF
  Vector endWorldSpace; // [esp+10h] [ebp-18h] BYREF
  float v21; // [esp+1Ch] [ebp-Ch]
  float v22; // [esp+20h] [ebp-8h]
  float v23; // [esp+24h] [ebp-4h]
  const Vector *starta; // [esp+30h] [ebp+8h]

  y = start->y;
  v8 = viewMatrixInverse->m[0][1];
  v9 = viewMatrixInverse->m[0][0];
  v10 = viewMatrixInverse->m[0][2];
  v11 = viewMatrixInverse->m[2][1];
  v12 = viewMatrixInverse->m[1][1];
  startWorldSpace.x = (float)((float)((float)(viewMatrixInverse->m[0][0] * start->x) + (float)(v8 * y))
                            + (float)(v10 * start->z))
                    + viewMatrixInverse->m[0][3];
  v23 = viewMatrixInverse->m[1][2];
  *(float *)&starta = v12;
  v13 = viewMatrixInverse->m[1][0];
  v14 = viewMatrixInverse->m[2][2];
  startWorldSpace.y = (float)((float)((float)(v13 * start->x) + (float)(*(float *)&starta * y)) + (float)(v23 * start->z))
                    + viewMatrixInverse->m[1][3];
  v22 = v11;
  v15 = viewMatrixInverse->m[2][0];
  v21 = v14;
  v16 = (float)((float)((float)(v15 * start->x) + (float)(v22 * y)) + (float)(v14 * start->z))
      + viewMatrixInverse->m[2][3];
  x = end->x;
  startWorldSpace.z = v16;
  endWorldSpace.y = end->y;
  endWorldSpace.z = end->z;
  endWorldSpace.x = (float)((float)((float)(v9 * x) + (float)(v8 * endWorldSpace.y)) + (float)(v10 * endWorldSpace.z))
                  + viewMatrixInverse->m[0][3];
  v18 = (float)((float)((float)(v15 * x) + (float)(v22 * endWorldSpace.y)) + (float)(v14 * endWorldSpace.z))
      + viewMatrixInverse->m[2][3];
  endWorldSpace.y = (float)((float)((float)(v13 * x) + (float)(*(float *)&starta * endWorldSpace.y))
                          + (float)(v23 * endWorldSpace.z))
                  + viewMatrixInverse->m[1][3];
  endWorldSpace.z = v18;
  ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, _DWORD, _DWORD, _DWORD, _DWORD, int))debugoverlay->AddLineOverlay)(
    a1: debugoverlay,
    a2: &startWorldSpace,
    a3: &endWorldSpace,
    a4: r,
    a5: g,
    a6: b,
    a7: 0,
    a8: -1082130432);
}

//------------------------------------------------------------------------------
// Address: 0x100B1410
// Name: private: void CClientShadowMgr::DrawUberlightRig(class Vector const __near &,class VMatrix const __near &,struct FlashlightState_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CClientShadowMgr::DrawUberlightRig(
        CClientShadowMgr *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const Vector *vOrigin,
        const VMatrix *matWorldToFlashlight,
        FlashlightState_t state)
{
  float v7; // xmm4_4
  float v8; // xmm6_4
  float m_fCutOff; // xmm7_4
  float v10; // xmm3_4
  int v12; // edi
  __m128i v13; // xmm0
  double v14; // xmm0_8
  double v15; // xmm0_8
  float v16; // xmm1_4
  double v17; // xmm0_8
  double v18; // xmm0_8
  float v19; // xmm1_4
  const VMatrix *v20; // eax
  float v21; // xmm1_4
  unsigned int v22; // esi
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm2_4
  float v27; // xmm3_4
  float v28; // xmm1_4
  float v29; // xmm5_4
  float v30; // xmm4_4
  double v31; // xmm0_8
  double v32; // xmm0_8
  float v33; // xmm1_4
  double v34; // xmm0_8
  double v35; // xmm0_8
  float v36; // xmm1_4
  Vector *v37; // eax
  float v38; // xmm1_4
  float v39; // xmm2_4
  float v40; // xmm1_4
  float m_fSheary; // xmm5_4
  float m_fShearx; // xmm6_4
  float x; // xmm3_4
  int v44; // esi
  float *v45; // edi
  float *v46; // ebx
  float z; // xmm2_4
  float v48; // xmm0_4
  float y; // xmm1_4
  float v50; // xmm7_4
  int v51; // esi
  float *v52; // edi
  float *v53; // ebx
  float v54; // xmm5_4
  float v55; // xmm4_4
  float v56; // xmm3_4
  float v57; // xmm2_4
  float v58; // xmm0_4
  float v59; // xmm1_4
  float v60; // xmm7_4
  int v61; // esi
  float *v62; // edi
  float *v63; // ebx
  float v64; // xmm5_4
  float v65; // xmm4_4
  float v66; // xmm3_4
  float v67; // xmm2_4
  float v68; // xmm0_4
  float v69; // xmm1_4
  float v70; // xmm7_4
  int v71; // esi
  float *v72; // edi
  float *v73; // ebx
  float v74; // xmm6_4
  float v75; // xmm5_4
  float v76; // xmm3_4
  float v77; // xmm2_4
  float v78; // xmm0_4
  float v79; // xmm1_4
  float v80; // xmm7_4
  int v81; // esi
  float *v82; // edi
  float v83; // xmm6_4
  float v84; // xmm5_4
  float v85; // xmm3_4
  float *v86; // ebx
  float v87; // xmm2_4
  float v88; // xmm0_4
  float v89; // xmm1_4
  float v90; // xmm7_4
  int v91; // esi
  float *v92; // edi
  float *v93; // ebx
  float v94; // xmm5_4
  float v95; // xmm4_4
  float v96; // xmm3_4
  float v97; // xmm2_4
  float v98; // xmm0_4
  float v99; // xmm1_4
  float v100; // xmm7_4
  int v101; // esi
  float *v102; // edi
  float *v103; // ebx
  float v104; // xmm4_4
  float v105; // xmm3_4
  float v106; // xmm2_4
  float v107; // xmm0_4
  float v108; // xmm1_4
  float v109; // xmm4_4
  float v110; // xmm3_4
  int v111; // esi
  float *v112; // edi
  float *v113; // ebx
  float v114; // xmm2_4
  float v115; // xmm0_4
  float v116; // xmm1_4
  int v117; // ebx
  unsigned int v118; // edi
  unsigned int v119; // esi
  float v120; // xmm5_4
  float v121; // xmm0_4
  float v122; // xmm5_4
  float v123; // xmm0_4
  float v124; // xmm5_4
  float v125; // xmm0_4
  float v126; // xmm1_4
  float v127; // xmm2_4
  float v128; // xmm1_4
  float v129; // xmm6_4
  float v130; // xmm1_4
  float v131; // xmm6_4
  float v132; // xmm1_4
  float v133; // xmm4_4
  float v134; // xmm3_4
  float v135; // xmm2_4
  float v136; // xmm4_4
  float v137; // xmm2_4
  float v138; // xmm1_4
  float v139; // xmm3_4
  float v140; // xmm1_4
  float v141; // xmm3_4
  float v142; // xmm6_4
  float v143; // xmm2_4
  float v144; // xmm1_4
  float v145; // xmm3_4
  float v146; // xmm6_4
  float v147; // xmm2_4
  float v148; // xmm1_4
  float v149; // xmm0_4
  float v150; // xmm1_4
  float v151; // xmm0_4
  float v152; // xmm1_4
  float v153; // xmm6_4
  float v154; // xmm0_4
  float v155; // xmm1_4
  Vector *v156; // [esp+120h] [ebp-13DCh]
  int v157; // [esp+124h] [ebp-13D8h]
  int v158; // [esp+128h] [ebp-13D4h]
  int v159; // [esp+12Ch] [ebp-13D0h]
  int v160; // [esp+130h] [ebp-13CCh]
  int v161; // [esp+134h] [ebp-13C8h]
  int v162; // [esp+138h] [ebp-13C4h]
  int v163; // [esp+13Ch] [ebp-13C0h]
  int v164; // [esp+140h] [ebp-13BCh]
  float v165; // [esp+144h] [ebp-13B8h]
  float v166; // [esp+148h] [ebp-13B4h]
  float v167[22]; // [esp+14Ch] [ebp-13B0h]
  int v168; // [esp+1A4h] [ebp-1358h] BYREF
  float v169; // [esp+390h] [ebp-116Ch]
  float v170; // [esp+394h] [ebp-1168h]
  float v171[22]; // [esp+398h] [ebp-1164h]
  int v172; // [esp+3F0h] [ebp-110Ch] BYREF
  char v173; // [esp+5CCh] [ebp-F30h] BYREF
  VMatrix result; // [esp+5DCh] [ebp-F20h] BYREF
  float v175; // [esp+61Ch] [ebp-EE0h]
  float v176; // [esp+620h] [ebp-EDCh]
  float v177[6]; // [esp+624h] [ebp-ED8h]
  int v178; // [esp+63Ch] [ebp-EC0h] BYREF
  char v179; // [esp+818h] [ebp-CE4h] BYREF
  float v180; // [esp+868h] [ebp-C94h]
  float v181; // [esp+86Ch] [ebp-C90h]
  float v182[6]; // [esp+870h] [ebp-C8Ch]
  int v183; // [esp+888h] [ebp-C74h] BYREF
  char v184; // [esp+AA4h] [ebp-A58h] BYREF
  _BYTE v185[8]; // [esp+AACh] [ebp-A50h] BYREF
  Vector v186[47]; // [esp+AB4h] [ebp-A48h] BYREF
  Vector v187[47]; // [esp+B14h] [ebp-9E8h] BYREF
  char v188; // [esp+CF0h] [ebp-80Ch] BYREF
  int v189; // [esp+CF8h] [ebp-804h] BYREF
  int v190; // [esp+CFCh] [ebp-800h] BYREF
  Vector v191[46]; // [esp+D00h] [ebp-7FCh] BYREF
  _BYTE v192[476]; // [esp+D60h] [ebp-79Ch] BYREF
  _DWORD v193[4]; // [esp+F3Ch] [ebp-5C0h] BYREF
  VMatrix matWorldToShadow; // [esp+F4Ch] [ebp-5B0h] BYREF
  float v195; // [esp+F8Ch] [ebp-570h]
  float v196; // [esp+F90h] [ebp-56Ch]
  float v197[125]; // [esp+F94h] [ebp-568h]
  _DWORD v198[18]; // [esp+1188h] [ebp-374h] BYREF
  int v199; // [esp+11D0h] [ebp-32Ch] BYREF
  int v200; // [esp+11D4h] [ebp-328h] BYREF
  float v201; // [esp+11D8h] [ebp-324h]
  float v202; // [esp+11DCh] [ebp-320h]
  float v203[141]; // [esp+11E0h] [ebp-31Ch]
  _DWORD v204[4]; // [esp+1414h] [ebp-E8h] BYREF
  float v205; // [esp+1424h] [ebp-D8h]
  float v206; // [esp+1428h] [ebp-D4h]
  float v207; // [esp+142Ch] [ebp-D0h]
  float v208; // [esp+1430h] [ebp-CCh]
  float v209; // [esp+1434h] [ebp-C8h]
  float v210; // [esp+1438h] [ebp-C4h]
  float v211; // [esp+143Ch] [ebp-C0h]
  float v212; // [esp+1440h] [ebp-BCh]
  float v213; // [esp+1444h] [ebp-B8h]
  UberlightState_t m_uberlightState; // [esp+1448h] [ebp-B4h]
  float v215; // [esp+1474h] [ebp-88h]
  float v216; // [esp+1478h] [ebp-84h]
  float v217; // [esp+147Ch] [ebp-80h]
  float v218; // [esp+1480h] [ebp-7Ch]
  float v219; // [esp+1484h] [ebp-78h]
  float v220; // [esp+1488h] [ebp-74h]
  VMatrix viewMatrixInverse; // [esp+148Ch] [ebp-70h] BYREF
  Vector v222; // [esp+14CCh] [ebp-30h] BYREF
  Vector v223; // [esp+14D8h] [ebp-24h] BYREF
  Vector start; // [esp+14E4h] [ebp-18h] BYREF
  Vector end; // [esp+14F0h] [ebp-Ch] BYREF
  int savedregs; // [esp+14FCh] [ebp+0h] BYREF

  v7 = state.m_uberlightState.m_fCutOff + state.m_uberlightState.m_fFarEdge;
  v8 = state.m_uberlightState.m_fCutOn - state.m_uberlightState.m_fNearEdge;
  m_uberlightState = state.m_uberlightState;
  m_fCutOff = state.m_uberlightState.m_fCutOff;
  v164 = a2;
  v163 = a4;
  v162 = a3;
  v10 = 0.0;
  v213 = 0.0;
  v215 = 2.0 / state.m_uberlightState.m_fRoundness;
  v12 = 0;
  v218 = state.m_uberlightState.m_fCutOff + state.m_uberlightState.m_fFarEdge;
  v207 = state.m_uberlightState.m_fCutOn - state.m_uberlightState.m_fNearEdge;
  while ( 1 )
  {
    if ( v12 != 0 )
    {
      if ( v12 == 48 )
      {
        v219 = 0.0;
        v212 = 0.0;
        v208 = 0.0;
        v206 = 0.0;
        v210 = m_uberlightState.m_fHeight * m_fCutOff;
        v211 = m_uberlightState.m_fHeight * m_uberlightState.m_fCutOn;
        v217 = v7 * m_uberlightState.m_fHeight;
        v216 = v8 * m_uberlightState.m_fHeight;
      }
      else
      {
        v13 = 0;
        *(double *)v13.m128i_i64 = v10;
        __libm_sse2_sin(X: v13);
        *(float *)&v14 = v14;
        v220 = *(float *)&v14;
        __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(v213)));
        v16 = v15;
        v209 = v220 / v16;
        v17 = (float)((float)(v220 / v16) / m_uberlightState.m_fHeight);
        __libm_sse2_pow();
        *(float *)&v17 = v17;
        v220 = *(float *)&v17;
        v18 = (float)(1.0 / m_uberlightState.m_fWidth);
        __libm_sse2_pow();
        *(float *)&v18 = v18;
        v19 = v220 + *(float *)&v18;
        __libm_sse2_pow();
        v206 = v19 * m_uberlightState.m_fCutOff;
        v211 = v209 * (float)(v19 * m_uberlightState.m_fCutOn);
        v208 = v19 * m_uberlightState.m_fCutOn;
        v212 = v19 * v218;
        v219 = v19 * v207;
        v210 = v209 * (float)(v19 * m_uberlightState.m_fCutOff);
        v217 = v209 * (float)(v19 * v218);
        v216 = v209 * (float)(v19 * v207);
      }
    }
    else
    {
      v208 = m_uberlightState.m_fCutOn * m_uberlightState.m_fWidth;
      v206 = m_fCutOff * m_uberlightState.m_fWidth;
      v212 = v7 * m_uberlightState.m_fWidth;
      v219 = v8 * m_uberlightState.m_fWidth;
      v216 = 0.0;
      v217 = 0.0;
      v211 = 0.0;
      v210 = 0.0;
    }
    CClientShadowMgr::BuildWorldToShadowMatrix(
      this,
      &matWorldToShadow,
      origin: &state.m_vecLightOrigin,
      quatOrientation: &state.m_quatOrientation);
    v20 = VMatrix::InverseTR(this: &matWorldToShadow, &result);
    VMatrix::operator=(this: &viewMatrixInverse, mOther: v20);
    v21 = v212;
    m_fCutOff = m_uberlightState.m_fCutOff;
    v8 = v207;
    v22 = 12 * v12;
    *(float *)((char *)&v180 + v22) = v206;
    v182[v22 / 4 - 1] = v210;
    *(float *)((char *)&v169 + v22) = v208;
    v171[v22 / 4 - 1] = v211;
    v171[v22 / 4] = m_uberlightState.m_fCutOn;
    v177[v22 / 4] = v218;
    v23 = v219;
    *(float *)((char *)&v175 + v22) = v21;
    v24 = v217;
    *(float *)((char *)&v165 + v22) = v23;
    v25 = v216;
    v182[v22 / 4] = m_fCutOff;
    v177[v22 / 4 - 1] = v24;
    v167[v22 / 4 - 1] = v25;
    v167[v22 / 4] = v8;
    if ( v12 != 0 )
    {
      if ( v12 == 48 )
      {
        v205 = m_uberlightState.m_fHedge + m_uberlightState.m_fHeight;
        v29 = (float)(m_uberlightState.m_fHedge + m_uberlightState.m_fHeight) * m_uberlightState.m_fCutOn;
        v30 = (float)(m_uberlightState.m_fHedge + m_uberlightState.m_fHeight) * m_fCutOff;
        v217 = (float)(m_uberlightState.m_fHedge + m_uberlightState.m_fHeight) * v218;
        v8 = v207;
        v219 = 0.0;
        v27 = 0.0;
        v26 = 0.0;
        v28 = 0.0;
        v216 = (float)(m_uberlightState.m_fHedge + m_uberlightState.m_fHeight) * v207;
      }
      else
      {
        __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(v213)));
        *(float *)&v31 = v31;
        v220 = *(float *)&v31;
        __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd((__m128)LODWORD(v213)));
        v33 = v32;
        v209 = v220 / v33;
        v34 = (float)((float)(v220 / v33) / (float)(m_uberlightState.m_fHedge + m_uberlightState.m_fHeight));
        __libm_sse2_pow();
        *(float *)&v34 = v34;
        v220 = *(float *)&v34;
        v35 = (float)(1.0 / (float)(m_uberlightState.m_fWedge + m_uberlightState.m_fWidth));
        __libm_sse2_pow();
        *(float *)&v35 = v35;
        v36 = v220 + *(float *)&v35;
        __libm_sse2_pow();
        v8 = v207;
        *(float *)&v35 = v36;
        v28 = v36 * m_uberlightState.m_fCutOff;
        v26 = *(float *)&v35 * m_uberlightState.m_fCutOn;
        v27 = *(float *)&v35 * v218;
        v219 = *(float *)&v35 * v207;
        v216 = v209 * (float)(*(float *)&v35 * v207);
        v30 = v209 * v28;
        v29 = v209 * (float)(*(float *)&v35 * m_uberlightState.m_fCutOn);
        v217 = v209 * (float)(*(float *)&v35 * v218);
      }
      m_fCutOff = m_uberlightState.m_fCutOff;
    }
    else
    {
      v26 = (float)(m_uberlightState.m_fWedge + m_uberlightState.m_fWidth) * m_uberlightState.m_fCutOn;
      v27 = (float)(m_uberlightState.m_fWedge + m_uberlightState.m_fWidth) * v218;
      v219 = (float)(m_uberlightState.m_fWedge + m_uberlightState.m_fWidth) * v8;
      v28 = (float)(m_uberlightState.m_fWedge + m_uberlightState.m_fWidth) * m_fCutOff;
      v216 = 0.0;
      v217 = 0.0;
      v29 = 0.0;
      v30 = 0.0;
    }
    *(&v195 + 3 * v12) = v28;
    v203[3 * v12] = m_uberlightState.m_fCutOn;
    v37 = &v186[v22 / 0xC];
    v191[v12].z = v218;
    v38 = v219;
    v191[v12].x = v27;
    v10 = v213 + 0.032724895;
    ++v12;
    *(float *)((char *)&v201 + v22) = v26;
    v39 = v217;
    v37->x = v38;
    v40 = v216;
    v197[v22 / 4 - 1] = v30;
    v197[v22 / 4] = m_fCutOff;
    v203[v22 / 4 - 1] = v29;
    v191[v22 / 0xC].y = v39;
    v37->y = v40;
    v37->z = v8;
    v213 = v10;
    if ( v12 >= 49 )
      break;
    v7 = v218;
  }
  m_fSheary = m_uberlightState.m_fSheary;
  m_fShearx = m_uberlightState.m_fShearx;
  x = start.x;
  v44 = 0;
  v45 = (float *)(&savedregs - 1401);
  v46 = (float *)&v179;
  do
  {
    if ( v44 > 48 )
    {
      if ( v44 > 96 )
      {
        if ( v44 > 144 )
        {
          z = v46[288];
          v48 = (float)(z * m_fShearx) + v46[286];
          y = (float)(m_fSheary * z) + (float)(v46[287] * -1.0);
        }
        else
        {
          z = *v45;
          v50 = *(v45 - 2) * -1.0;
          end.y = *(v45 - 1) * -1.0;
          y = (float)(m_fSheary * z) + end.y;
          v48 = (float)(z * m_fShearx) + v50;
        }
      }
      else
      {
        z = *v46;
        v48 = (float)(*v46 * m_fShearx) + (float)(*(v46 - 2) * -1.0);
        y = (float)(m_fSheary * *v46) + *(v46 - 1);
      }
    }
    else
    {
      z = v45[288];
      v48 = (float)(z * m_fShearx) + v45[286];
      y = (float)(m_fSheary * z) + v45[287];
    }
    end.y = y;
    end.x = v48;
    end.z = z;
    if ( v44 != 0 )
    {
      v222.x = (float)((float)((float)(x * viewMatrixInverse.m[0][0]) + (float)(viewMatrixInverse.m[0][1] * start.y))
                     + (float)(viewMatrixInverse.m[0][2] * start.z))
             + viewMatrixInverse.m[0][3];
      v222.y = (float)((float)((float)(x * viewMatrixInverse.m[1][0]) + (float)(viewMatrixInverse.m[1][1] * start.y))
                     + (float)(viewMatrixInverse.m[1][2] * start.z))
             + viewMatrixInverse.m[1][3];
      v222.z = (float)((float)((float)(x * viewMatrixInverse.m[2][0]) + (float)(viewMatrixInverse.m[2][1] * start.y))
                     + (float)(viewMatrixInverse.m[2][2] * start.z))
             + viewMatrixInverse.m[2][3];
      v223.x = (float)((float)((float)(viewMatrixInverse.m[0][1] * y) + (float)(viewMatrixInverse.m[0][0] * v48))
                     + (float)(viewMatrixInverse.m[0][2] * z))
             + viewMatrixInverse.m[0][3];
      v161 = -1082130432;
      v160 = 0;
      v159 = 10;
      v158 = 10;
      v157 = 255;
      v156 = &v223;
      v223.y = (float)((float)((float)(viewMatrixInverse.m[1][1] * y) + (float)(viewMatrixInverse.m[1][0] * v48))
                     + (float)(viewMatrixInverse.m[1][2] * z))
             + viewMatrixInverse.m[1][3];
      v223.z = (float)((float)((float)(viewMatrixInverse.m[2][1] * y) + (float)(viewMatrixInverse.m[2][0] * v48))
                     + (float)(viewMatrixInverse.m[2][2] * z))
             + viewMatrixInverse.m[2][3];
      ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int, int, _DWORD, int))debugoverlay->AddLineOverlay)(
        a1: debugoverlay,
        a2: &v222,
        a3: &v223,
        a4: 255,
        a5: 10,
        a6: 10,
        a7: 0,
        a8: -1082130432);
      v48 = end.x;
      y = end.y;
      z = end.z;
      m_fShearx = m_uberlightState.m_fShearx;
      m_fSheary = m_uberlightState.m_fSheary;
    }
    ++v44;
    v45 += 3;
    v46 -= 3;
    x = v48;
    start.y = y;
    start.z = z;
  }
  while ( v44 < 192 );
  start.x = v48;
  v222.x = (float)((float)((float)(viewMatrixInverse.m[0][1] * y) + (float)(viewMatrixInverse.m[0][0] * v48))
                 + (float)(viewMatrixInverse.m[0][2] * z))
         + viewMatrixInverse.m[0][3];
  v222.y = (float)((float)((float)(viewMatrixInverse.m[1][1] * y) + (float)(viewMatrixInverse.m[1][0] * v48))
                 + (float)(viewMatrixInverse.m[1][2] * z))
         + viewMatrixInverse.m[1][3];
  v222.z = (float)((float)((float)(viewMatrixInverse.m[2][1] * y) + (float)(viewMatrixInverse.m[2][0] * v48))
                 + (float)(viewMatrixInverse.m[2][2] * z))
         + viewMatrixInverse.m[2][3];
  v161 = -1082130432;
  v223.x = (float)((float)((float)(v169 * viewMatrixInverse.m[0][0]) + (float)(viewMatrixInverse.m[0][1] * v170))
                 + (float)(viewMatrixInverse.m[0][2] * v171[0]))
         + viewMatrixInverse.m[0][3];
  v160 = 0;
  v159 = 10;
  v158 = 10;
  v157 = 255;
  v156 = &v223;
  v223.y = (float)((float)((float)(v169 * viewMatrixInverse.m[1][0]) + (float)(viewMatrixInverse.m[1][1] * v170))
                 + (float)(viewMatrixInverse.m[1][2] * v171[0]))
         + viewMatrixInverse.m[1][3];
  v223.z = (float)((float)((float)(v169 * viewMatrixInverse.m[2][0]) + (float)(viewMatrixInverse.m[2][1] * v170))
                 + (float)(viewMatrixInverse.m[2][2] * v171[0]))
         + viewMatrixInverse.m[2][3];
  ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int, int, _DWORD, int, int, int, int))debugoverlay->AddLineOverlay)(
    a1: debugoverlay,
    a2: &v222,
    a3: &v223,
    a4: 255,
    a5: 10,
    a6: 10,
    a7: 0,
    a8: -1082130432,
    a9: v162,
    a10: v163,
    a11: v164);
  v51 = 0;
  v52 = (float *)&v172;
  v53 = (float *)&v188;
  v54 = m_uberlightState.m_fShearx;
  v55 = m_uberlightState.m_fSheary;
  v56 = start.x;
  do
  {
    if ( v51 > 48 )
    {
      if ( v51 > 96 )
      {
        if ( v51 > 144 )
        {
          v57 = v53[288];
          v58 = (float)(v57 * v54) + v53[286];
          v59 = (float)(v55 * v57) + (float)(v53[287] * -1.0);
        }
        else
        {
          v57 = *v52;
          v60 = *(v52 - 2) * -1.0;
          end.y = *(v52 - 1) * -1.0;
          v59 = (float)(v55 * v57) + end.y;
          v58 = (float)(v57 * v54) + v60;
        }
      }
      else
      {
        v57 = *v53;
        v58 = (float)(*v53 * v54) + (float)(*(v53 - 2) * -1.0);
        v59 = (float)(v55 * *v53) + *(v53 - 1);
      }
    }
    else
    {
      v57 = v52[288];
      v58 = (float)(v57 * v54) + v52[286];
      v59 = (float)(v55 * v57) + v52[287];
    }
    end.y = v59;
    end.x = v58;
    end.z = v57;
    if ( v51 != 0 )
    {
      v222.x = (float)((float)((float)(v56 * viewMatrixInverse.m[0][0]) + (float)(viewMatrixInverse.m[0][1] * start.y))
                     + (float)(viewMatrixInverse.m[0][2] * start.z))
             + viewMatrixInverse.m[0][3];
      v222.y = (float)((float)((float)(v56 * viewMatrixInverse.m[1][0]) + (float)(viewMatrixInverse.m[1][1] * start.y))
                     + (float)(viewMatrixInverse.m[1][2] * start.z))
             + viewMatrixInverse.m[1][3];
      v222.z = (float)((float)((float)(v56 * viewMatrixInverse.m[2][0]) + (float)(viewMatrixInverse.m[2][1] * start.y))
                     + (float)(viewMatrixInverse.m[2][2] * start.z))
             + viewMatrixInverse.m[2][3];
      v223.x = (float)((float)((float)(viewMatrixInverse.m[0][1] * v59) + (float)(viewMatrixInverse.m[0][0] * v58))
                     + (float)(viewMatrixInverse.m[0][2] * v57))
             + viewMatrixInverse.m[0][3];
      v164 = -1082130432;
      v163 = 0;
      v162 = 255;
      v161 = 10;
      v160 = 10;
      v159 = (int)&v223;
      v223.y = (float)((float)((float)(viewMatrixInverse.m[1][1] * v59) + (float)(viewMatrixInverse.m[1][0] * v58))
                     + (float)(viewMatrixInverse.m[1][2] * v57))
             + viewMatrixInverse.m[1][3];
      v223.z = (float)((float)((float)(viewMatrixInverse.m[2][1] * v59) + (float)(viewMatrixInverse.m[2][0] * v58))
                     + (float)(viewMatrixInverse.m[2][2] * v57))
             + viewMatrixInverse.m[2][3];
      ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int, int, _DWORD, int))debugoverlay->AddLineOverlay)(
        a1: debugoverlay,
        a2: &v222,
        a3: &v223,
        a4: 10,
        a5: 10,
        a6: 255,
        a7: 0,
        a8: -1082130432);
      v58 = end.x;
      v59 = end.y;
      v57 = end.z;
      v54 = m_uberlightState.m_fShearx;
      v55 = m_uberlightState.m_fSheary;
    }
    ++v51;
    v52 += 3;
    v53 -= 3;
    v56 = v58;
    start.y = v59;
    start.z = v57;
  }
  while ( v51 < 192 );
  start.x = v58;
  v222.x = (float)((float)((float)(viewMatrixInverse.m[0][1] * v59) + (float)(viewMatrixInverse.m[0][0] * v58))
                 + (float)(viewMatrixInverse.m[0][2] * v57))
         + viewMatrixInverse.m[0][3];
  v222.y = (float)((float)((float)(viewMatrixInverse.m[1][1] * v59) + (float)(viewMatrixInverse.m[1][0] * v58))
                 + (float)(viewMatrixInverse.m[1][2] * v57))
         + viewMatrixInverse.m[1][3];
  v222.z = (float)((float)((float)(viewMatrixInverse.m[2][1] * v59) + (float)(viewMatrixInverse.m[2][0] * v58))
                 + (float)(viewMatrixInverse.m[2][2] * v57))
         + viewMatrixInverse.m[2][3];
  v164 = -1082130432;
  v163 = 0;
  v162 = 255;
  v161 = 10;
  v160 = 10;
  v159 = (int)&v223;
  v223.x = (float)((float)((float)(viewMatrixInverse.m[0][1] * v181) + (float)(viewMatrixInverse.m[0][0] * v180))
                 + (float)(viewMatrixInverse.m[0][2] * v182[0]))
         + viewMatrixInverse.m[0][3];
  v223.y = (float)((float)((float)(viewMatrixInverse.m[1][1] * v181) + (float)(viewMatrixInverse.m[1][0] * v180))
                 + (float)(viewMatrixInverse.m[1][2] * v182[0]))
         + viewMatrixInverse.m[1][3];
  v223.z = (float)((float)((float)(viewMatrixInverse.m[2][1] * v181) + (float)(viewMatrixInverse.m[2][0] * v180))
                 + (float)(viewMatrixInverse.m[2][2] * v182[0]))
         + viewMatrixInverse.m[2][3];
  ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int, int, _DWORD, int))debugoverlay->AddLineOverlay)(
    a1: debugoverlay,
    a2: &v222,
    a3: &v223,
    a4: 10,
    a5: 10,
    a6: 255,
    a7: 0,
    a8: -1082130432);
  v61 = 0;
  v62 = (float *)v192;
  v63 = (float *)&STACK[0x1660];
  v64 = m_uberlightState.m_fShearx;
  v65 = m_uberlightState.m_fSheary;
  v66 = start.x;
  do
  {
    if ( v61 > 48 )
    {
      if ( v61 > 96 )
      {
        if ( v61 > 144 )
        {
          v67 = v63[288];
          v68 = (float)(v67 * v64) + v63[286];
          v69 = (float)(v65 * v67) + (float)(v63[287] * -1.0);
        }
        else
        {
          v67 = *v62;
          v70 = *(v62 - 2) * -1.0;
          end.y = *(v62 - 1) * -1.0;
          v69 = (float)(v65 * v67) + end.y;
          v68 = (float)(v67 * v64) + v70;
        }
      }
      else
      {
        v67 = *v63;
        v68 = (float)(*v63 * v64) + (float)(*(v63 - 2) * -1.0);
        v69 = (float)(v65 * *v63) + *(v63 - 1);
      }
    }
    else
    {
      v67 = v62[288];
      v68 = (float)(v67 * v64) + v62[286];
      v69 = (float)(v65 * v67) + v62[287];
    }
    end.y = v69;
    end.x = v68;
    end.z = v67;
    if ( v61 != 0 )
    {
      v222.x = (float)((float)((float)(v66 * viewMatrixInverse.m[0][0]) + (float)(viewMatrixInverse.m[0][1] * start.y))
                     + (float)(viewMatrixInverse.m[0][2] * start.z))
             + viewMatrixInverse.m[0][3];
      v222.y = (float)((float)((float)(v66 * viewMatrixInverse.m[1][0]) + (float)(viewMatrixInverse.m[1][1] * start.y))
                     + (float)(viewMatrixInverse.m[1][2] * start.z))
             + viewMatrixInverse.m[1][3];
      v222.z = (float)((float)((float)(v66 * viewMatrixInverse.m[2][0]) + (float)(viewMatrixInverse.m[2][1] * start.y))
                     + (float)(viewMatrixInverse.m[2][2] * start.z))
             + viewMatrixInverse.m[2][3];
      v223.x = (float)((float)((float)(viewMatrixInverse.m[0][1] * v69) + (float)(viewMatrixInverse.m[0][0] * v68))
                     + (float)(viewMatrixInverse.m[0][2] * v67))
             + viewMatrixInverse.m[0][3];
      v164 = -1082130432;
      v163 = 0;
      v162 = 10;
      v161 = 10;
      v160 = 255;
      v159 = (int)&v223;
      v223.y = (float)((float)((float)(viewMatrixInverse.m[1][1] * v69) + (float)(viewMatrixInverse.m[1][0] * v68))
                     + (float)(viewMatrixInverse.m[1][2] * v67))
             + viewMatrixInverse.m[1][3];
      v223.z = (float)((float)((float)(viewMatrixInverse.m[2][1] * v69) + (float)(viewMatrixInverse.m[2][0] * v68))
                     + (float)(viewMatrixInverse.m[2][2] * v67))
             + viewMatrixInverse.m[2][3];
      ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int, int, _DWORD, int))debugoverlay->AddLineOverlay)(
        a1: debugoverlay,
        a2: &v222,
        a3: &v223,
        a4: 255,
        a5: 10,
        a6: 10,
        a7: 0,
        a8: -1082130432);
      v68 = end.x;
      v69 = end.y;
      v67 = end.z;
      v64 = m_uberlightState.m_fShearx;
      v65 = m_uberlightState.m_fSheary;
    }
    ++v61;
    v62 += 3;
    v63 -= 3;
    v66 = v68;
    start.y = v69;
    start.z = v67;
  }
  while ( v61 < 192 );
  start.x = v68;
  v222.x = (float)((float)((float)(viewMatrixInverse.m[0][1] * v69) + (float)(viewMatrixInverse.m[0][0] * v68))
                 + (float)(viewMatrixInverse.m[0][2] * v67))
         + viewMatrixInverse.m[0][3];
  v222.y = (float)((float)((float)(viewMatrixInverse.m[1][1] * v69) + (float)(viewMatrixInverse.m[1][0] * v68))
                 + (float)(viewMatrixInverse.m[1][2] * v67))
         + viewMatrixInverse.m[1][3];
  v222.z = (float)((float)((float)(viewMatrixInverse.m[2][1] * v69) + (float)(viewMatrixInverse.m[2][0] * v68))
                 + (float)(viewMatrixInverse.m[2][2] * v67))
         + viewMatrixInverse.m[2][3];
  v164 = -1082130432;
  v163 = 0;
  v162 = 10;
  v161 = 10;
  v160 = 255;
  v159 = (int)&v223;
  v223.x = (float)((float)((float)(viewMatrixInverse.m[0][1] * v202) + (float)(viewMatrixInverse.m[0][0] * v201))
                 + (float)(viewMatrixInverse.m[0][2] * v203[0]))
         + viewMatrixInverse.m[0][3];
  v223.y = (float)((float)((float)(viewMatrixInverse.m[1][1] * v202) + (float)(viewMatrixInverse.m[1][0] * v201))
                 + (float)(viewMatrixInverse.m[1][2] * v203[0]))
         + viewMatrixInverse.m[1][3];
  v223.z = (float)((float)((float)(viewMatrixInverse.m[2][1] * v202) + (float)(viewMatrixInverse.m[2][0] * v201))
                 + (float)(viewMatrixInverse.m[2][2] * v203[0]))
         + viewMatrixInverse.m[2][3];
  ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int, int, _DWORD, int))debugoverlay->AddLineOverlay)(
    a1: debugoverlay,
    a2: &v222,
    a3: &v223,
    a4: 255,
    a5: 10,
    a6: 10,
    a7: 0,
    a8: -1082130432);
  v71 = 0;
  v72 = (float *)v187;
  v73 = (float *)v204;
  v74 = m_uberlightState.m_fShearx;
  v75 = m_uberlightState.m_fSheary;
  v76 = start.x;
  do
  {
    if ( v71 > 48 )
    {
      if ( v71 > 96 )
      {
        if ( v71 > 144 )
        {
          v77 = v73[288];
          v78 = (float)(v77 * v74) + v73[286];
          v79 = (float)(v75 * v77) + (float)(v73[287] * -1.0);
        }
        else
        {
          v77 = *v72;
          v80 = *(v72 - 2) * -1.0;
          end.y = *(v72 - 1) * -1.0;
          v79 = (float)(v75 * v77) + end.y;
          v78 = (float)(v77 * v74) + v80;
        }
      }
      else
      {
        v77 = *v73;
        v78 = (float)(*v73 * v74) + (float)(*(v73 - 2) * -1.0);
        v79 = (float)(v75 * *v73) + *(v73 - 1);
      }
    }
    else
    {
      v77 = v72[288];
      v78 = (float)(v77 * v74) + v72[286];
      v79 = (float)(v75 * v77) + v72[287];
    }
    end.y = v79;
    end.x = v78;
    end.z = v77;
    if ( v71 != 0 )
    {
      v222.x = (float)((float)((float)(v76 * viewMatrixInverse.m[0][0]) + (float)(viewMatrixInverse.m[0][1] * start.y))
                     + (float)(viewMatrixInverse.m[0][2] * start.z))
             + viewMatrixInverse.m[0][3];
      v222.y = (float)((float)((float)(v76 * viewMatrixInverse.m[1][0]) + (float)(viewMatrixInverse.m[1][1] * start.y))
                     + (float)(viewMatrixInverse.m[1][2] * start.z))
             + viewMatrixInverse.m[1][3];
      v222.z = (float)((float)((float)(v76 * viewMatrixInverse.m[2][0]) + (float)(viewMatrixInverse.m[2][1] * start.y))
                     + (float)(viewMatrixInverse.m[2][2] * start.z))
             + viewMatrixInverse.m[2][3];
      v223.x = (float)((float)((float)(viewMatrixInverse.m[0][1] * v79) + (float)(viewMatrixInverse.m[0][0] * v78))
                     + (float)(viewMatrixInverse.m[0][2] * v77))
             + viewMatrixInverse.m[0][3];
      v164 = -1082130432;
      v163 = 0;
      v162 = 255;
      v161 = 10;
      v160 = 10;
      v159 = (int)&v223;
      v223.y = (float)((float)((float)(viewMatrixInverse.m[1][1] * v79) + (float)(viewMatrixInverse.m[1][0] * v78))
                     + (float)(viewMatrixInverse.m[1][2] * v77))
             + viewMatrixInverse.m[1][3];
      v223.z = (float)((float)((float)(viewMatrixInverse.m[2][1] * v79) + (float)(viewMatrixInverse.m[2][0] * v78))
                     + (float)(viewMatrixInverse.m[2][2] * v77))
             + viewMatrixInverse.m[2][3];
      ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int, int, _DWORD, int))debugoverlay->AddLineOverlay)(
        a1: debugoverlay,
        a2: &v222,
        a3: &v223,
        a4: 10,
        a5: 10,
        a6: 255,
        a7: 0,
        a8: -1082130432);
      v78 = end.x;
      v79 = end.y;
      v77 = end.z;
      v74 = m_uberlightState.m_fShearx;
      v75 = m_uberlightState.m_fSheary;
    }
    ++v71;
    v72 += 3;
    v73 -= 3;
    v76 = v78;
    start.y = v79;
    start.z = v77;
  }
  while ( v71 < 192 );
  start.x = v78;
  v222.x = (float)((float)((float)(viewMatrixInverse.m[0][1] * v79) + (float)(viewMatrixInverse.m[0][0] * v78))
                 + (float)(viewMatrixInverse.m[0][2] * v77))
         + viewMatrixInverse.m[0][3];
  v222.y = (float)((float)((float)(viewMatrixInverse.m[1][1] * v79) + (float)(viewMatrixInverse.m[1][0] * v78))
                 + (float)(viewMatrixInverse.m[1][2] * v77))
         + viewMatrixInverse.m[1][3];
  v222.z = (float)((float)((float)(viewMatrixInverse.m[2][1] * v79) + (float)(viewMatrixInverse.m[2][0] * v78))
                 + (float)(viewMatrixInverse.m[2][2] * v77))
         + viewMatrixInverse.m[2][3];
  v223.x = (float)((float)((float)(v195 * viewMatrixInverse.m[0][0]) + (float)(viewMatrixInverse.m[0][1] * v196))
                 + (float)(viewMatrixInverse.m[0][2] * v197[0]))
         + viewMatrixInverse.m[0][3];
  v164 = -1082130432;
  v163 = 0;
  v162 = 255;
  v161 = 10;
  v160 = 10;
  v159 = (int)&v223;
  v223.y = (float)((float)((float)(v195 * viewMatrixInverse.m[1][0]) + (float)(viewMatrixInverse.m[1][1] * v196))
                 + (float)(viewMatrixInverse.m[1][2] * v197[0]))
         + viewMatrixInverse.m[1][3];
  v223.z = (float)((float)((float)(viewMatrixInverse.m[2][0] * v195) + (float)(viewMatrixInverse.m[2][1] * v196))
                 + (float)(viewMatrixInverse.m[2][2] * v197[0]))
         + viewMatrixInverse.m[2][3];
  ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int, int, _DWORD, int))debugoverlay->AddLineOverlay)(
    a1: debugoverlay,
    a2: &v222,
    a3: &v223,
    a4: 10,
    a5: 10,
    a6: 255,
    a7: 0,
    a8: -1082130432);
  v81 = 0;
  v82 = (float *)(&savedregs - 1548);
  v83 = m_uberlightState.m_fShearx;
  v84 = m_uberlightState.m_fSheary;
  v85 = start.x;
  v86 = (float *)&v173;
  do
  {
    if ( v81 > 48 )
    {
      if ( v81 > 96 )
      {
        if ( v81 > 144 )
        {
          v87 = v86[288];
          v88 = (float)(v87 * v83) + v86[286];
          v89 = (float)(v84 * v87) + (float)(v86[287] * -1.0);
        }
        else
        {
          v87 = *v82;
          v90 = *(v82 - 2) * -1.0;
          end.y = *(v82 - 1) * -1.0;
          v89 = (float)(v84 * v87) + end.y;
          v88 = (float)(v87 * v83) + v90;
        }
      }
      else
      {
        v87 = *v86;
        v88 = (float)(*v86 * v83) + (float)(*(v86 - 2) * -1.0);
        v89 = (float)(v84 * *v86) + *(v86 - 1);
      }
    }
    else
    {
      v87 = v82[288];
      v88 = (float)(v87 * v83) + v82[286];
      v89 = (float)(v84 * v87) + v82[287];
    }
    end.y = v89;
    end.x = v88;
    end.z = v87;
    if ( v81 != 0 )
    {
      v222.x = (float)((float)((float)(v85 * viewMatrixInverse.m[0][0]) + (float)(viewMatrixInverse.m[0][1] * start.y))
                     + (float)(viewMatrixInverse.m[0][2] * start.z))
             + viewMatrixInverse.m[0][3];
      v222.y = (float)((float)((float)(v85 * viewMatrixInverse.m[1][0]) + (float)(viewMatrixInverse.m[1][1] * start.y))
                     + (float)(viewMatrixInverse.m[1][2] * start.z))
             + viewMatrixInverse.m[1][3];
      v222.z = (float)((float)((float)(v85 * viewMatrixInverse.m[2][0]) + (float)(viewMatrixInverse.m[2][1] * start.y))
                     + (float)(viewMatrixInverse.m[2][2] * start.z))
             + viewMatrixInverse.m[2][3];
      v223.x = (float)((float)((float)(viewMatrixInverse.m[0][1] * v89) + (float)(viewMatrixInverse.m[0][0] * v88))
                     + (float)(viewMatrixInverse.m[0][2] * v87))
             + viewMatrixInverse.m[0][3];
      v164 = -1082130432;
      v163 = 0;
      v162 = 10;
      v161 = 10;
      v160 = 255;
      v159 = (int)&v223;
      v223.y = (float)((float)((float)(viewMatrixInverse.m[1][1] * v89) + (float)(viewMatrixInverse.m[1][0] * v88))
                     + (float)(viewMatrixInverse.m[1][2] * v87))
             + viewMatrixInverse.m[1][3];
      v223.z = (float)((float)((float)(viewMatrixInverse.m[2][1] * v89) + (float)(viewMatrixInverse.m[2][0] * v88))
                     + (float)(viewMatrixInverse.m[2][2] * v87))
             + viewMatrixInverse.m[2][3];
      ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int, int, _DWORD, int))debugoverlay->AddLineOverlay)(
        a1: debugoverlay,
        a2: &v222,
        a3: &v223,
        a4: 255,
        a5: 10,
        a6: 10,
        a7: 0,
        a8: -1082130432);
      v88 = end.x;
      v89 = end.y;
      v87 = end.z;
      v83 = m_uberlightState.m_fShearx;
      v84 = m_uberlightState.m_fSheary;
    }
    ++v81;
    v82 += 3;
    v86 -= 3;
    v85 = v88;
    start.y = v89;
    start.z = v87;
  }
  while ( v81 < 192 );
  start.x = v88;
  v222.x = (float)((float)((float)(viewMatrixInverse.m[0][1] * v89) + (float)(viewMatrixInverse.m[0][0] * v88))
                 + (float)(viewMatrixInverse.m[0][2] * v87))
         + viewMatrixInverse.m[0][3];
  v222.y = (float)((float)((float)(viewMatrixInverse.m[1][1] * v89) + (float)(viewMatrixInverse.m[1][0] * v88))
                 + (float)(viewMatrixInverse.m[1][2] * v87))
         + viewMatrixInverse.m[1][3];
  v222.z = (float)((float)((float)(viewMatrixInverse.m[2][1] * v89) + (float)(viewMatrixInverse.m[2][0] * v88))
                 + (float)(viewMatrixInverse.m[2][2] * v87))
         + viewMatrixInverse.m[2][3];
  v164 = -1082130432;
  v223.x = (float)((float)((float)(v165 * viewMatrixInverse.m[0][0]) + (float)(viewMatrixInverse.m[0][1] * v166))
                 + (float)(viewMatrixInverse.m[0][2] * v167[0]))
         + viewMatrixInverse.m[0][3];
  v163 = 0;
  v162 = 10;
  v161 = 10;
  v160 = 255;
  v159 = (int)&v223;
  v223.y = (float)((float)((float)(v165 * viewMatrixInverse.m[1][0]) + (float)(viewMatrixInverse.m[1][1] * v166))
                 + (float)(viewMatrixInverse.m[1][2] * v167[0]))
         + viewMatrixInverse.m[1][3];
  v223.z = (float)((float)((float)(viewMatrixInverse.m[2][1] * v166) + (float)(v165 * viewMatrixInverse.m[2][0]))
                 + (float)(viewMatrixInverse.m[2][2] * v167[0]))
         + viewMatrixInverse.m[2][3];
  ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int, int, _DWORD, int))debugoverlay->AddLineOverlay)(
    a1: debugoverlay,
    a2: &v222,
    a3: &v223,
    a4: 255,
    a5: 10,
    a6: 10,
    a7: 0,
    a8: -1082130432);
  v91 = 0;
  v92 = (float *)&v168;
  v93 = (float *)&v184;
  v94 = m_uberlightState.m_fShearx;
  v95 = m_uberlightState.m_fSheary;
  v96 = start.x;
  do
  {
    if ( v91 > 48 )
    {
      if ( v91 > 96 )
      {
        if ( v91 > 144 )
        {
          v97 = v93[288];
          v98 = (float)(v97 * v94) + v93[286];
          v99 = (float)(v95 * v97) + (float)(v93[287] * -1.0);
        }
        else
        {
          v97 = *v92;
          v100 = *(v92 - 2) * -1.0;
          end.y = *(v92 - 1) * -1.0;
          v99 = (float)(v95 * v97) + end.y;
          v98 = (float)(v97 * v94) + v100;
        }
      }
      else
      {
        v97 = *v93;
        v98 = (float)(*v93 * v94) + (float)(*(v93 - 2) * -1.0);
        v99 = (float)(v95 * *v93) + *(v93 - 1);
      }
    }
    else
    {
      v97 = v92[288];
      v98 = (float)(v97 * v94) + v92[286];
      v99 = (float)(v95 * v97) + v92[287];
    }
    end.y = v99;
    end.x = v98;
    end.z = v97;
    if ( v91 != 0 )
    {
      v222.x = (float)((float)((float)(v96 * viewMatrixInverse.m[0][0]) + (float)(viewMatrixInverse.m[0][1] * start.y))
                     + (float)(viewMatrixInverse.m[0][2] * start.z))
             + viewMatrixInverse.m[0][3];
      v222.y = (float)((float)((float)(v96 * viewMatrixInverse.m[1][0]) + (float)(viewMatrixInverse.m[1][1] * start.y))
                     + (float)(viewMatrixInverse.m[1][2] * start.z))
             + viewMatrixInverse.m[1][3];
      v222.z = (float)((float)((float)(v96 * viewMatrixInverse.m[2][0]) + (float)(viewMatrixInverse.m[2][1] * start.y))
                     + (float)(viewMatrixInverse.m[2][2] * start.z))
             + viewMatrixInverse.m[2][3];
      v223.x = (float)((float)((float)(viewMatrixInverse.m[0][1] * v99) + (float)(viewMatrixInverse.m[0][0] * v98))
                     + (float)(viewMatrixInverse.m[0][2] * v97))
             + viewMatrixInverse.m[0][3];
      v164 = -1082130432;
      v163 = 0;
      v162 = 255;
      v161 = 10;
      v160 = 10;
      v159 = (int)&v223;
      v223.y = (float)((float)((float)(viewMatrixInverse.m[1][1] * v99) + (float)(viewMatrixInverse.m[1][0] * v98))
                     + (float)(viewMatrixInverse.m[1][2] * v97))
             + viewMatrixInverse.m[1][3];
      v223.z = (float)((float)((float)(viewMatrixInverse.m[2][1] * v99) + (float)(viewMatrixInverse.m[2][0] * v98))
                     + (float)(viewMatrixInverse.m[2][2] * v97))
             + viewMatrixInverse.m[2][3];
      ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int, int, _DWORD, int))debugoverlay->AddLineOverlay)(
        a1: debugoverlay,
        a2: &v222,
        a3: &v223,
        a4: 10,
        a5: 10,
        a6: 255,
        a7: 0,
        a8: -1082130432);
      v98 = end.x;
      v99 = end.y;
      v97 = end.z;
      v94 = m_uberlightState.m_fShearx;
      v95 = m_uberlightState.m_fSheary;
    }
    ++v91;
    v92 += 3;
    v93 -= 3;
    v96 = v98;
    start.y = v99;
    start.z = v97;
  }
  while ( v91 < 192 );
  start.x = v98;
  v222.x = (float)((float)((float)(viewMatrixInverse.m[0][1] * v99) + (float)(viewMatrixInverse.m[0][0] * v98))
                 + (float)(viewMatrixInverse.m[0][2] * v97))
         + viewMatrixInverse.m[0][3];
  v222.y = (float)((float)((float)(viewMatrixInverse.m[1][1] * v99) + (float)(viewMatrixInverse.m[1][0] * v98))
                 + (float)(viewMatrixInverse.m[1][2] * v97))
         + viewMatrixInverse.m[1][3];
  v222.z = (float)((float)((float)(viewMatrixInverse.m[2][1] * v99) + (float)(viewMatrixInverse.m[2][0] * v98))
                 + (float)(viewMatrixInverse.m[2][2] * v97))
         + viewMatrixInverse.m[2][3];
  v164 = -1082130432;
  v163 = 0;
  v162 = 255;
  v161 = 10;
  v160 = 10;
  v159 = (int)&v223;
  v223.x = (float)((float)((float)(viewMatrixInverse.m[0][0] * v175) + (float)(viewMatrixInverse.m[0][1] * v176))
                 + (float)(viewMatrixInverse.m[0][2] * v177[0]))
         + viewMatrixInverse.m[0][3];
  v223.y = (float)((float)((float)(viewMatrixInverse.m[1][0] * v175) + (float)(viewMatrixInverse.m[1][1] * v176))
                 + (float)(viewMatrixInverse.m[1][2] * v177[0]))
         + viewMatrixInverse.m[1][3];
  v223.z = (float)((float)((float)(viewMatrixInverse.m[2][1] * v176) + (float)(viewMatrixInverse.m[2][0] * v175))
                 + (float)(viewMatrixInverse.m[2][2] * v177[0]))
         + viewMatrixInverse.m[2][3];
  ((void (__thiscall *)(IVDebugOverlay *, Vector *, Vector *, int, int, int, _DWORD, int))debugoverlay->AddLineOverlay)(
    a1: debugoverlay,
    a2: &v222,
    a3: &v223,
    a4: 10,
    a5: 10,
    a6: 255,
    a7: 0,
    a8: -1082130432);
  v101 = 0;
  v102 = (float *)&v178;
  v103 = (float *)v193;
  v104 = m_uberlightState.m_fShearx;
  v105 = m_uberlightState.m_fSheary;
  do
  {
    if ( v101 > 48 )
    {
      if ( v101 > 96 )
      {
        if ( v101 > 144 )
        {
          v106 = v103[288];
          v107 = (float)(v106 * v104) + v103[286];
          v108 = (float)(v105 * v106) + (float)(v103[287] * -1.0);
        }
        else
        {
          v106 = *v102;
          v107 = (float)(*v102 * v104) + (float)(*(v102 - 2) * -1.0);
          v108 = (float)(v105 * *v102) + (float)(*(v102 - 1) * -1.0);
        }
      }
      else
      {
        v106 = *v103;
        v107 = (float)(*v103 * v104) + (float)(*(v103 - 2) * -1.0);
        v108 = (float)(v105 * *v103) + *(v103 - 1);
      }
    }
    else
    {
      v106 = v102[288];
      v107 = (float)(v106 * v104) + v102[286];
      v108 = (float)(v105 * v106) + v102[287];
    }
    end.y = v108;
    end.x = v107;
    end.z = v106;
    if ( v101 != 0 )
    {
      LineDrawHelper(&end, &viewMatrixInverse, &start, r: 0xFFu, g: 0xAu, b: 0xAu);
      v107 = end.x;
      v108 = end.y;
      v106 = end.z;
      v104 = m_uberlightState.m_fShearx;
      v105 = m_uberlightState.m_fSheary;
    }
    ++v101;
    v102 += 3;
    v103 -= 3;
    start.x = v107;
    start.y = v108;
    start.z = v106;
  }
  while ( v101 < 192 );
  LineDrawHelper(end: v186, &viewMatrixInverse, &start, r: 0xFFu, g: 0xAu, b: 0xAu);
  v109 = m_uberlightState.m_fShearx;
  v110 = m_uberlightState.m_fSheary;
  v111 = 0;
  v112 = (float *)&v183;
  v113 = (float *)v198;
  do
  {
    if ( v111 > 48 )
    {
      if ( v111 > 96 )
      {
        if ( v111 > 144 )
        {
          v114 = v113[288];
          v115 = (float)(v114 * v109) + v113[286];
          v116 = (float)(v110 * v114) + (float)(v113[287] * -1.0);
        }
        else
        {
          v114 = *v112;
          v115 = (float)(*v112 * v109) + (float)(*(v112 - 2) * -1.0);
          v116 = (float)(v110 * *v112) + (float)(*(v112 - 1) * -1.0);
        }
      }
      else
      {
        v114 = *v113;
        v115 = (float)(*v113 * v109) + (float)(*(v113 - 2) * -1.0);
        v116 = (float)(v110 * *v113) + *(v113 - 1);
      }
    }
    else
    {
      v114 = v112[288];
      v115 = (float)(v114 * v109) + v112[286];
      v116 = (float)(v110 * v114) + v112[287];
    }
    end.y = v116;
    end.x = v115;
    end.z = v114;
    if ( v111 != 0 )
    {
      LineDrawHelper(&end, &viewMatrixInverse, &start, r: 0xAu, g: 0xAu, b: 0xFFu);
      v115 = end.x;
      v116 = end.y;
      v114 = end.z;
      v109 = m_uberlightState.m_fShearx;
      v110 = m_uberlightState.m_fSheary;
    }
    ++v111;
    v112 += 3;
    v113 -= 3;
    start.x = v115;
    start.y = v116;
    start.z = v114;
  }
  while ( v111 < 192 );
  LineDrawHelper(end: v191, &viewMatrixInverse, &start, r: 0xAu, g: 0xAu, b: 0xFFu);
  v209 = COERCE_FLOAT(&v200);
  v211 = COERCE_FLOAT(&v190);
  v210 = COERCE_FLOAT((VMatrix *)&matWorldToShadow.m[3][3]);
  v205 = COERCE_FLOAT(v185);
  v220 = COERCE_FLOAT(&v199);
  v212 = COERCE_FLOAT(&v189);
  v117 = 0;
  v118 = 0;
  v119 = -1144;
  v208 = COERCE_FLOAT((VMatrix *)&matWorldToShadow.m[3][2]);
  do
  {
    if ( v117 % 0x18u != 0 )
      goto LABEL_115;
    if ( v117 <= 48 )
    {
      v222.z = *(float *)&v192[v119 + 468];
      v222.y = (float)(v222.z * m_uberlightState.m_fSheary) + *(float *)&v192[v119 + 464];
      LODWORD(start.z) = *(unsigned int *)((char *)&STACK[0x1658] + v119);
      v120 = (float)(start.z * m_uberlightState.m_fShearx) + *(float *)((char *)&STACK[0x1650] + v119);
      start.y = (float)(start.z * m_uberlightState.m_fSheary) + *(float *)((char *)&STACK[0x1654] + v119);
      v121 = v197[v119 / 4 + 123];
      start.x = v120;
      v223.z = v121;
      v122 = (float)(v121 * m_uberlightState.m_fShearx) + v197[v119 / 4 + 121];
      v223.y = (float)(v121 * m_uberlightState.m_fSheary) + v197[v119 / 4 + 122];
      v123 = v203[v119 / 4 + 139];
      v223.x = v122;
      end.z = v123;
      v124 = (float)(v123 * m_uberlightState.m_fShearx) + v203[v119 / 4 + 137];
      v125 = (float)(v123 * m_uberlightState.m_fSheary) + v203[v119 / 4 + 138];
      v222.x = (float)(v222.z * m_uberlightState.m_fShearx) + *(float *)&v192[v119 + 460];
      end.x = v124;
LABEL_113:
      end.y = v125;
      goto LABEL_114;
    }
    if ( v117 <= 96 )
    {
      v126 = *(float *)&v192[v118 + 468] * -1.0;
      LODWORD(v222.z) = v193[v118 / 4];
      v127 = (float)(v222.z * m_uberlightState.m_fShearx) + v126;
      v128 = *(float *)((char *)&STACK[0x1658] + v118);
      v222.x = v127;
      v222.y = (float)(v222.z * m_uberlightState.m_fSheary) + *(float *)&v192[v118 + 472];
      LODWORD(start.z) = *(unsigned int *)((char *)&STACK[0x1660] + v118);
      start.y = (float)(start.z * m_uberlightState.m_fSheary) + *(float *)((char *)&STACK[0x165C] + v118);
      v129 = (float)(start.z * m_uberlightState.m_fShearx) + (float)(v128 * -1.0);
      v130 = v197[v118 / 4 + 123];
      LODWORD(v223.z) = v198[v118 / 4];
      start.x = v129;
      v131 = (float)(v223.z * m_uberlightState.m_fShearx) + (float)(v130 * -1.0);
      v132 = v203[v118 / 4 + 139];
      v223.y = (float)(v223.z * m_uberlightState.m_fSheary) + v197[v118 / 4 + 124];
      LODWORD(end.z) = v204[v118 / 4];
      v125 = (float)(end.z * m_uberlightState.m_fSheary) + v203[v118 / 4 + 140];
      v133 = (float)(end.z * m_uberlightState.m_fShearx) + (float)(v132 * -1.0);
LABEL_112:
      end.x = v133;
      v223.x = v131;
      goto LABEL_113;
    }
    if ( v117 > 144 )
    {
      v148 = v203[v118 / 4 + 118];
      v222.z = v203[v118 / 4 + 119];
      v149 = (float)(v222.z * m_uberlightState.m_fSheary) + (float)(v148 * -1.0);
      v150 = *(float *)((char *)&STACK[0x1ADC] + v118);
      v222.y = v149;
      LODWORD(start.z) = *(unsigned int *)((char *)&STACK[0x1AE0] + v118);
      v151 = (float)(start.z * m_uberlightState.m_fSheary) + (float)(v150 * -1.0);
      v152 = *(float *)((char *)&state.m_nBottom + v118);
      start.y = v151;
      v153 = (float)(start.z * m_uberlightState.m_fShearx) + *(float *)((char *)&STACK[0x1AD8] + v118);
      LODWORD(v223.z) = *(unsigned int *)((char *)&STACK[0x1608] + v118);
      start.x = v153;
      v154 = (float)(v223.z * m_uberlightState.m_fSheary) + (float)(v152 * -1.0);
      v155 = *(float *)((char *)&STACK[0x1890] + v118);
      v223.y = v154;
      LODWORD(end.z) = *(unsigned int *)((char *)&STACK[0x1894] + v118);
      v131 = (float)(v223.z * m_uberlightState.m_fShearx) + *(float *)((char *)&state.m_nRight + v118);
      v133 = (float)(end.z * m_uberlightState.m_fShearx) + *(float *)((char *)&STACK[0x188C] + v118);
      v222.x = (float)(v222.z * m_uberlightState.m_fShearx) + v203[v118 / 4 + 117];
      v125 = (float)(end.z * m_uberlightState.m_fSheary) + (float)(v155 * -1.0);
      goto LABEL_112;
    }
    v134 = *(float *)&v185[v119 + 4];
    v135 = *(float *)(LODWORD(v205) + v119) * -1.0;
    v222.z = v186[v119 / 0xC].x;
    v136 = (float)(v222.z * m_uberlightState.m_fShearx) + v135;
    v137 = *(float *)(LODWORD(v220) + v119);
    v222.x = v136;
    v138 = (float)(v222.z * m_uberlightState.m_fSheary) + (float)(v134 * -1.0);
    v139 = *(float *)(LODWORD(v209) + v119);
    v222.y = v138;
    start.z = *(float *)((char *)&v201 + v119);
    v140 = (float)(start.z * m_uberlightState.m_fSheary) + (float)(v139 * -1.0);
    v141 = *(float *)(LODWORD(v211) + v119);
    start.y = v140;
    v142 = (float)(start.z * m_uberlightState.m_fShearx) + (float)(v137 * -1.0);
    v143 = *(float *)(LODWORD(v212) + v119);
    v223.z = v191[v119 / 0xC].x;
    start.x = v142;
    v144 = (float)(v223.z * m_uberlightState.m_fSheary) + (float)(v141 * -1.0);
    v145 = *(float *)(LODWORD(v210) + v119);
    v146 = (float)(v223.z * m_uberlightState.m_fShearx) + (float)(v143 * -1.0);
    v147 = *(float *)(LODWORD(v208) + v119);
    v223.y = v144;
    end.z = *(float *)((char *)&v195 + v119);
    v223.x = v146;
    end.x = (float)(end.z * m_uberlightState.m_fShearx) + (float)(v147 * -1.0);
    end.y = (float)(end.z * m_uberlightState.m_fSheary) + (float)(v145 * -1.0);
LABEL_114:
    LineDrawHelper(end: &v222, &viewMatrixInverse, &start, r: 0xFFu, g: 0xAu, b: 0xAu);
    LineDrawHelper(&end, &viewMatrixInverse, &start, r: 0xDCu, g: 0xAu, b: 0xDCu);
    LineDrawHelper(&end, &viewMatrixInverse, start: &v223, r: 0xAu, g: 0xAu, b: 0xFFu);
LABEL_115:
    v118 -= 12;
    ++v117;
    v119 += 12;
  }
  while ( (int)v118 > -2304 );
}

//------------------------------------------------------------------------------
// Address: 0x100B3A20
// Name: private: void CClientShadowMgr::AddChildBounds(struct matrix3x4_t __near &,class IClientRenderable __near *,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::AddChildBounds(
        CClientShadowMgr *this,
        matrix3x4_t *matWorldToBBox,
        IClientRenderable *pParent,
        Vector *vecMins,
        Vector *vecMaxs)
{
  IClientRenderable *i; // esi
  unsigned __int16 v7; // ax
  const matrix3x4_t *v8; // eax
  double x; // xmm0_8
  float y; // xmm1_4
  float v11; // xmm0_4
  double v12; // xmm0_8
  double v13; // xmm1_8
  float z; // xmm1_4
  float v15; // xmm0_4
  double v16; // xmm0_8
  double v17; // xmm1_8
  Vector *v18; // eax
  float v19; // xmm1_4
  float v20; // xmm0_4
  double v21; // xmm0_8
  double v22; // xmm1_8
  float v23; // xmm1_4
  float v24; // xmm0_4
  double v25; // xmm0_8
  double v26; // xmm1_8
  float v27; // xmm1_4
  float v28; // xmm0_4
  double v29; // xmm0_8
  double v30; // xmm1_8
  matrix3x4_t childToBBox; // [esp+8h] [ebp-60h] BYREF
  Vector vecChildMins; // [esp+38h] [ebp-30h] BYREF
  Vector vecChildMaxs; // [esp+44h] [ebp-24h] BYREF
  Vector vecNewChildMaxs; // [esp+50h] [ebp-18h] BYREF
  Vector vecNewChildMins; // [esp+5Ch] [ebp-Ch] BYREF

  for ( i = pParent->FirstShadowChild(this: pParent); i != nullptr; i = i->NextShadowPeer(this: i) )
  {
    v7 = i->GetShadowHandle(this: i);
    if ( v7 == 0xFFFF
      || (this->m_Shadows.m_Memory.m_pMemory[v7].m_Element.m_Flags & 8) != 0 && this->m_RenderToTextureActive == -1 )
    {
      v18 = vecMaxs;
    }
    else
    {
      i->GetShadowRenderBounds(this: i, a2: &vecChildMins, a3: &vecChildMaxs, a4: SHADOWS_RENDER_TO_TEXTURE);
      v8 = i->RenderableToWorldTransform(this: i);
      ConcatTransforms(in1: matWorldToBBox, in2: v8, out: &childToBBox);
      TransformAABB(
        transform: &childToBBox,
        vecMinsIn: &vecChildMins,
        vecMaxsIn: &vecChildMaxs,
        vecMinsOut: &vecNewChildMins,
        vecMaxsOut: &vecNewChildMaxs);
      x = vecMins->x;
      if ( x > vecNewChildMins.x )
        x = vecNewChildMins.x;
      y = vecNewChildMins.y;
      v11 = x;
      vecMins->x = v11;
      v12 = vecMins->y;
      v13 = y;
      if ( v12 > v13 )
        v12 = v13;
      z = vecNewChildMins.z;
      v15 = v12;
      vecMins->y = v15;
      v16 = vecMins->z;
      v17 = z;
      if ( v16 > v17 )
        v16 = v17;
      v18 = vecMaxs;
      v19 = vecNewChildMaxs.x;
      v20 = v16;
      vecMins->z = v20;
      v21 = vecMaxs->x;
      v22 = v19;
      if ( v21 < v22 )
        v21 = v22;
      v23 = vecNewChildMaxs.y;
      v24 = v21;
      vecMaxs->x = v24;
      v25 = vecMaxs->y;
      v26 = v23;
      if ( v25 < v26 )
        v25 = v26;
      v27 = vecNewChildMaxs.z;
      v28 = v25;
      vecMaxs->y = v28;
      v29 = vecMaxs->z;
      v30 = v27;
      if ( v29 < v30 )
        v29 = v30;
      vecMaxs->z = v29;
    }
    CClientShadowMgr::AddChildBounds(this, matWorldToBBox, pParent: i, vecMins, vecMaxs: v18);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3BD0
// Name: private: void CClientShadowMgr::ComputeHierarchicalBounds(class IClientRenderable __near *,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::ComputeHierarchicalBounds(
        CClientShadowMgr *this,
        IClientRenderable *pRenderable,
        Vector *vecMins,
        Vector *vecMaxs)
{
  unsigned __int16 v5; // ax
  ShadowType_t v6; // edi
  unsigned __int16 m_Flags; // ax
  const matrix3x4_t *v8; // eax
  matrix3x4_t matWorldToBBox; // [esp+Ch] [ebp-30h] BYREF

  v5 = pRenderable->GetShadowHandle(this: pRenderable);
  if ( v5 == 0xFFFF )
  {
    v6 = SHADOWS_NONE;
  }
  else
  {
    m_Flags = this->m_Shadows.m_Memory.m_pMemory[v5].m_Element.m_Flags;
    if ( (m_Flags & 8) != 0 )
      v6 = this->m_RenderToTextureActive + 1;
    else
      v6 = (m_Flags & 0x20) != 0 ? SHADOWS_RENDER_TO_DEPTH_TEXTURE : SHADOWS_SIMPLE;
  }
  pRenderable->GetShadowRenderBounds(this: pRenderable, a2: vecMins, a3: vecMaxs, a4: v6);
  if ( pRenderable->FirstShadowChild(this: pRenderable) != nullptr && v6 != SHADOWS_SIMPLE )
  {
    v8 = pRenderable->RenderableToWorldTransform(this: pRenderable);
    MatrixInvert(in: v8, out: &matWorldToBBox);
    CClientShadowMgr::AddChildBounds(this, &matWorldToBBox, pParent: pRenderable, vecMins, vecMaxs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3C90
// Name: public: bool CClientShadowMgr::WillParentRenderBlobbyShadow(class IClientRenderable __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClientShadowMgr::WillParentRenderBlobbyShadow(CClientShadowMgr *this, IClientRenderable *pRenderable)
{
  IClientRenderable *v3; // ecx
  IClientRenderable *v4; // eax
  IClientRenderable *v5; // esi
  int ActualShadowCastType; // eax

  v3 = pRenderable;
  if ( pRenderable == nullptr )
    return false;
  while ( 1 )
  {
    v4 = v3->GetShadowParent(this: v3);
    v5 = v4;
    if ( v4 == nullptr )
      return false;
    ActualShadowCastType = CClientShadowMgr::GetActualShadowCastType(this, pEnt: v4);
    if ( ActualShadowCastType != 0 )
      break;
    v3 = v5;
  }
  return ActualShadowCastType == 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B3CE0
// Name: public: bool CClientShadowMgr::ShouldUseParentShadow(class IClientRenderable __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientShadowMgr::ShouldUseParentShadow(CClientShadowMgr *this, IClientRenderable *pRenderable)
{
  IClientRenderable *v3; // ecx
  IClientRenderable *v4; // eax
  IClientRenderable *v5; // esi
  int ActualShadowCastType; // eax

  v3 = pRenderable;
  if ( pRenderable == nullptr )
    return 0;
  while ( 1 )
  {
    v4 = v3->GetShadowParent(this: v3);
    v5 = v4;
    if ( v4 == nullptr )
      return 0;
    ActualShadowCastType = CClientShadowMgr::GetActualShadowCastType(this, pEnt: v4);
    if ( ActualShadowCastType == 1 )
      return 0;
    if ( ActualShadowCastType != 0 )
      break;
    v3 = v5;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B3D30
// Name: private: class IClientRenderable __near * CClientShadowMgr::GetParentShadowEntity(unsigned short)
// Source: json
//------------------------------------------------------------------------------
IClientRenderable *__thiscall CClientShadowMgr::GetParentShadowEntity(CClientShadowMgr *this, unsigned __int16 handle)
{
  IClientRenderable *ClientRenderableFromHandle; // eax
  int v4; // edi
  unsigned __int16 v5; // ax

  ClientRenderableFromHandle = CClientEntityList::GetClientRenderableFromHandle(
                                 this: (CClientEntityList *)cl_entitylist.m_Index,
                                 hEnt: this->m_Shadows.m_Memory.m_pMemory[handle].m_Element.m_Entity);
  v4 = (int)ClientRenderableFromHandle;
  if ( ClientRenderableFromHandle == nullptr
    || CClientShadowMgr::ShouldUseParentShadow(this, pRenderable: ClientRenderableFromHandle) == 0 )
  {
    return nullptr;
  }
  do
  {
    do
    {
      v4 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 100))(a1: v4);
      v5 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 24))(a1: v4);
    }
    while ( v5 == 0xFFFF );
  }
  while ( (this->m_Shadows.m_Memory.m_pMemory[v5].m_Element.m_Flags & 8) != 0 && this->m_RenderToTextureActive == -1 );
  return (IClientRenderable *)v4;
}

//------------------------------------------------------------------------------
// Address: 0x100B3DC0
// Name: public: virtual void CClientShadowMgr::MarkRenderToTextureShadowDirty(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::MarkRenderToTextureShadowDirty(CClientShadowMgr *this, unsigned __int16 handle)
{
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *v3; // eax
  IClientRenderable *ParentShadowEntity; // eax
  unsigned __int16 v5; // ax
  unsigned __int16 *p_m_Flags; // eax

  if ( handle != 0xFFFF )
  {
    v3 = &this->m_Shadows.m_Memory.m_pMemory[handle];
    v3->m_Element.m_Flags |= 0x80u;
    ParentShadowEntity = CClientShadowMgr::GetParentShadowEntity(this, handle);
    if ( ParentShadowEntity != nullptr )
    {
      v5 = ParentShadowEntity->GetShadowHandle(this: ParentShadowEntity);
      if ( v5 != 0xFFFF )
      {
        p_m_Flags = &this->m_Shadows.m_Memory.m_pMemory[v5].m_Element.m_Flags;
        *p_m_Flags |= 0x80u;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B3E30
// Name: public: void CClientShadowMgr::ComputeBoundingSphere(class IClientRenderable __near *,class Vector __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CClientShadowMgr::ComputeBoundingSphere(
        CClientShadowMgr *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        IClientRenderable *pRenderable,
        Vector *origin,
        float *radius)
{
  unsigned __int16 v8; // ax
  float v9; // eax
  unsigned __int16 m_Flags; // ax
  int m_RenderToTextureActive; // eax
  void (__thiscall *GetShadowRenderBounds)(IClientRenderable *, Vector *, Vector *, ShadowType_t); // edx
  float v13; // xmm4_4
  float v14; // xmm5_4
  __int128 v15; // xmm0
  IClientRenderable_vtbl *v16; // edx
  const QAngle *(__thiscall *GetRenderAngles)(IClientRenderable *); // eax
  const QAngle *v18; // eax
  const Vector *(__thiscall *GetRenderOrigin)(IClientRenderable *); // eax
  float *v20; // eax
  float v21; // xmm4_4
  float x; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm3_4
  float v25; // xmm4_4
  float v26; // xmm2_4
  float y; // xmm5_4
  float v29[3]; // [esp-Ch] [ebp-5Ch] BYREF
  Vector vec[3]; // [esp+0h] [ebp-50h] BYREF
  __int128 mins; // [esp+24h] [ebp-2Ch] OVERLAPPED
  Vector centroid; // [esp+34h] [ebp-1Ch] BYREF
  float v33; // [esp+40h] [ebp-10h]
  Vector maxs; // [esp+44h] [ebp-Ch]
  float retaddr; // [esp+50h] [ebp+0h]

  maxs.x = a2;
  maxs.y = retaddr;
  v8 = ((int (__thiscall *)(IClientRenderable *, int, int))pRenderable->GetShadowHandle)(
         a1: pRenderable,
         a2: a3,
         a3: a4);
  if ( v8 == 0xFFFF )
  {
    v9 = 0.0;
  }
  else
  {
    m_Flags = this->m_Shadows.m_Memory.m_pMemory[v8].m_Element.m_Flags;
    if ( (m_Flags & 8) != 0 )
      m_RenderToTextureActive = this->m_RenderToTextureActive;
    else
      m_RenderToTextureActive = (m_Flags & 0x20) != 0 ? 3 : 0;
    LODWORD(v9) = m_RenderToTextureActive + 1;
  }
  GetShadowRenderBounds = pRenderable->GetShadowRenderBounds;
  v33 = v9;
  LODWORD(centroid.z) = &centroid.y;
  LODWORD(centroid.y) = &vec[2];
  ((void (__thiscall *)(IClientRenderable *))GetShadowRenderBounds)(a1: pRenderable);
  v13 = vec[2].y + centroid.z;
  v14 = vec[2].z + v33;
  v15 = 0;
  *(float *)&v15 = fsqrt(
                     (float)((float)((float)(centroid.z - vec[2].y) * (float)(centroid.z - vec[2].y))
                           + (float)((float)(v33 - vec[2].z) * (float)(v33 - vec[2].z)))
                   + (float)((float)(centroid.y - vec[2].x) * (float)(centroid.y - vec[2].x)));
  mins = v15;
  LODWORD(centroid.x) = &vec[1];
  *radius = *(float *)&v15 * 0.5;
  HIDWORD(mins) = vec;
  v16 = pRenderable->__vftable;
  DWORD2(mins) = v29;
  GetRenderAngles = v16->GetRenderAngles;
  *((float *)&mins + 2) = v13 * 0.5;
  *((float *)&mins + 3) = v14 * 0.5;
  v18 = GetRenderAngles(this: pRenderable);
  AngleVectors(
    angles: v18,
    forward: (Vector *)DWORD2(mins),
    right: (Vector *)HIDWORD(mins),
    up: (Vector *)LODWORD(centroid.x));
  GetRenderOrigin = pRenderable->GetRenderOrigin;
  vec[0].x = vec[0].x * -1.0;
  vec[0].y = vec[0].y * -1.0;
  vec[0].z = vec[0].z * -1.0;
  v20 = (float *)GetRenderOrigin(this: pRenderable);
  v21 = v29[0];
  origin->x = *v20;
  LODWORD(v15) = DWORD1(mins);
  x = vec[0].x;
  origin->y = v20[1];
  v23 = *((float *)&mins + 2);
  v24 = v20[2];
  v25 = (float)((float)(v21 * *(float *)&v15) + origin->x) + (float)(x * *((float *)&mins + 2));
  v26 = *((float *)&mins + 3);
  y = vec[0].y;
  origin->x = v25 + (float)(vec[1].x * *((float *)&mins + 3));
  origin->y = (float)((float)((float)(v29[1] * *(float *)&v15) + origin->y) + (float)(y * v23))
            + (float)(vec[1].y * v26);
  origin->z = (float)((float)((float)(v29[2] * *(float *)&v15) + v24) + (float)(vec[0].z * v23))
            + (float)(vec[1].z * v26);
}

//------------------------------------------------------------------------------
// Address: 0x100B4050
// Name: private: bool CClientShadowMgr::ComputeSeparatingPlane(class IClientRenderable __near *,class IClientRenderable __near *,struct cplane_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientShadowMgr::ComputeSeparatingPlane(
        CClientShadowMgr *this,
        IClientRenderable *pRend1,
        IClientRenderable *pRend2,
        cplane_t *pPlane)
{
  unsigned __int16 v5; // ax
  ShadowType_t v6; // eax
  unsigned __int16 m_Flags; // ax
  int m_RenderToTextureActive; // eax
  unsigned __int16 v9; // ax
  ShadowType_t v10; // eax
  unsigned __int16 v11; // ax
  int v12; // eax
  const Vector *v13; // eax
  const QAngle *v15; // [esp-4h] [ebp-60h]
  const Vector *v16; // [esp+8h] [ebp-54h]
  const QAngle *v17; // [esp+Ch] [ebp-50h]
  Vector min1; // [esp+2Ch] [ebp-30h] BYREF
  Vector max1; // [esp+38h] [ebp-24h] BYREF
  Vector min2; // [esp+44h] [ebp-18h] BYREF
  Vector max2; // [esp+50h] [ebp-Ch] BYREF

  v5 = pRend1->GetShadowHandle(this: pRend1);
  if ( v5 == 0xFFFF )
  {
    v6 = SHADOWS_NONE;
  }
  else
  {
    m_Flags = this->m_Shadows.m_Memory.m_pMemory[v5].m_Element.m_Flags;
    if ( (m_Flags & 8) != 0 )
      m_RenderToTextureActive = this->m_RenderToTextureActive;
    else
      m_RenderToTextureActive = (m_Flags & 0x20) != 0 ? 3 : 0;
    v6 = m_RenderToTextureActive + 1;
  }
  pRend1->GetShadowRenderBounds(this: pRend1, a2: &min1, a3: &max1, a4: v6);
  v9 = pRend2->GetShadowHandle(this: pRend2);
  if ( v9 == 0xFFFF )
  {
    v10 = SHADOWS_NONE;
  }
  else
  {
    v11 = this->m_Shadows.m_Memory.m_pMemory[v9].m_Element.m_Flags;
    if ( (v11 & 8) != 0 )
      v12 = this->m_RenderToTextureActive;
    else
      v12 = (v11 & 0x20) != 0 ? 3 : 0;
    v10 = v12 + 1;
  }
  pRend2->GetShadowRenderBounds(this: pRend2, a2: &min2, a3: &max2, a4: v10);
  v17 = pRend2->GetRenderAngles(this: pRend2);
  v16 = pRend2->GetRenderOrigin(this: pRend2);
  v15 = pRend1->GetRenderAngles(this: pRend1);
  v13 = pRend1->GetRenderOrigin(this: pRend1);
  return ComputeSeparatingPlane(
           org1: v13,
           angles1: v15,
           &min1,
           &max1,
           org2: v16,
           angles2: v17,
           &min2,
           &max2,
           tolerance: 3.0,
           pPlane);
}

//------------------------------------------------------------------------------
// Address: 0x100B4180
// Name: private: void CClientShadowMgr::DrawRenderToTextureShadowLOD(int,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::DrawRenderToTextureShadowLOD(
        CClientShadowMgr *this,
        int nSlot,
        unsigned __int16 clientShadowHandle)
{
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *v4; // esi

  if ( r_shadow_deferred.m_pParent == nullptr || r_shadow_deferred.m_pParent->m_Value.m_nValue == 0 )
  {
    v4 = &this->m_Shadows.m_Memory.m_pMemory[clientShadowHandle];
    if ( (!v4->m_Element.m_bUseSplitScreenBits
       || ((1 << (nSlot & 0x1F)) & v4->m_Element.m_SplitScreenBits.m_Ints[nSlot >> 5]) != 0)
      && (v4->m_Element.m_Flags & 0x200) == 0 )
    {
      ((void (__stdcall *)(_DWORD, IMaterial *, IMaterial *, int))shadowmgr->SetShadowMaterial)(
        a1: v4->m_Element.m_ShadowHandle,
        a2: this->m_SimpleShadow.m_pMaterial,
        a3: this->m_SimpleShadow.m_pMaterial,
        a4: 0xFFFF);
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, int, int))shadowmgr->SetShadowTexCoord)(
        a1: v4->m_Element.m_ShadowHandle,
        a2: 0,
        a3: 0,
        a4: 1065353216,
        a5: 1065353216);
      if ( r_shadow_deferred.m_pParent == nullptr || r_shadow_deferred.m_pParent->m_Value.m_nValue == 0 )
        shadowmgr->ClearExtraClipPlanes(
          this: shadowmgr,
          a2: this->m_Shadows.m_Memory.m_pMemory[v4->m_Element.m_ShadowHandle].m_Element.m_ShadowHandle);
      v4->m_Element.m_Flags |= 0x200u;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B4270
// Name: public: virtual void CClientShadowMgr::GetFrustumExtents(unsigned short,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::GetFrustumExtents(
        CClientShadowMgr *this,
        unsigned __int16 handle,
        Vector *vecMin,
        Vector *vecMax)
{
  float x; // xmm2_4
  double v5; // xmm0_8
  float y; // xmm4_4
  float v7; // xmm0_4
  double v8; // xmm0_8
  float z; // xmm3_4
  float v10; // xmm0_4
  double v11; // xmm0_8
  float v12; // xmm0_4
  double v13; // xmm0_8
  float v14; // xmm0_4
  double v15; // xmm0_8
  float v16; // xmm0_4
  double v17; // xmm0_8
  float v18; // xmm0_4
  float v19; // xmm2_4
  double v20; // xmm0_8
  float v21; // xmm4_4
  float v22; // xmm0_4
  double v23; // xmm0_8
  float v24; // xmm3_4
  float v25; // xmm0_4
  double v26; // xmm0_8
  float v27; // xmm0_4
  double v28; // xmm0_8
  float v29; // xmm0_4
  double v30; // xmm0_8
  float v31; // xmm0_4
  double v32; // xmm0_8
  float v33; // xmm0_4
  float v34; // xmm2_4
  double v35; // xmm0_8
  float v36; // xmm4_4
  float v37; // xmm0_4
  double v38; // xmm0_8
  float v39; // xmm3_4
  float v40; // xmm0_4
  double v41; // xmm0_8
  float v42; // xmm0_4
  double v43; // xmm0_8
  float v44; // xmm0_4
  double v45; // xmm0_8
  float v46; // xmm0_4
  double v47; // xmm0_8
  float v48; // xmm0_4
  float v49; // xmm2_4
  double v50; // xmm0_8
  float v51; // xmm4_4
  float v52; // xmm0_4
  double v53; // xmm0_8
  float v54; // xmm3_4
  float v55; // xmm0_4
  double v56; // xmm0_8
  float v57; // xmm0_4
  double v58; // xmm0_8
  float v59; // xmm0_4
  double v60; // xmm0_8
  float v61; // xmm0_4
  double v62; // xmm0_8
  float v63; // xmm0_4
  float v64; // xmm2_4
  double v65; // xmm0_8
  float v66; // xmm4_4
  float v67; // xmm0_4
  double v68; // xmm0_8
  float v69; // xmm3_4
  float v70; // xmm0_4
  double v71; // xmm0_8
  float v72; // xmm0_4
  double v73; // xmm0_8
  float v74; // xmm0_4
  double v75; // xmm0_8
  float v76; // xmm0_4
  double v77; // xmm0_8
  float v78; // xmm0_4
  float v79; // xmm2_4
  double v80; // xmm0_8
  float v81; // xmm4_4
  float v82; // xmm0_4
  double v83; // xmm0_8
  float v84; // xmm3_4
  float v85; // xmm0_4
  double v86; // xmm0_8
  float v87; // xmm0_4
  double v88; // xmm0_8
  float v89; // xmm0_4
  double v90; // xmm0_8
  float v91; // xmm0_4
  double v92; // xmm0_8
  float v93; // xmm0_4
  float v94; // xmm2_4
  double v95; // xmm0_8
  float v96; // xmm4_4
  float v97; // xmm0_4
  double v98; // xmm0_8
  float v99; // xmm3_4
  float v100; // xmm0_4
  double v101; // xmm0_8
  float v102; // xmm0_4
  double v103; // xmm0_8
  float v104; // xmm0_4
  double v105; // xmm0_8
  float v106; // xmm0_4
  double v107; // xmm0_8
  float v108; // xmm0_4
  float v109; // xmm2_4
  double v110; // xmm0_8
  float v111; // xmm4_4
  float v112; // xmm0_4
  double v113; // xmm0_8
  float v114; // xmm3_4
  float v115; // xmm0_4
  double v116; // xmm0_8
  float v117; // xmm0_4
  double v118; // xmm0_8
  float v119; // xmm0_4
  double v120; // xmm0_8
  float v121; // xmm0_4
  double v122; // xmm0_8
  VMatrix flashlightToWorld; // [esp+8h] [ebp-58h] BYREF
  Vector dst; // [esp+48h] [ebp-18h] BYREF
  Vector src2; // [esp+54h] [ebp-Ch] BYREF

  MatrixInverseGeneral(
    src: &this->m_Shadows.m_Memory.m_pMemory[handle].m_Element.m_WorldToShadow,
    dst: &flashlightToWorld);
  vecMin->x = 3.4028235e38;
  vecMin->y = 3.4028235e38;
  vecMin->z = 3.4028235e38;
  vecMax->x = -3.4028235e38;
  vecMax->y = -3.4028235e38;
  vecMax->z = -3.4028235e38;
  memset((void *)&src2, 0, sizeof(src2));
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, &src2, &dst);
  x = dst.x;
  v5 = vecMin->x;
  if ( v5 > dst.x )
    v5 = dst.x;
  y = dst.y;
  v7 = v5;
  vecMin->x = v7;
  v8 = vecMin->y;
  if ( v8 > y )
    v8 = y;
  z = dst.z;
  v10 = v8;
  vecMin->y = v10;
  v11 = vecMin->z;
  if ( v11 > z )
    v11 = z;
  v12 = v11;
  vecMin->z = v12;
  v13 = vecMax->x;
  if ( v13 < x )
    v13 = x;
  v14 = v13;
  vecMax->x = v14;
  v15 = vecMax->y;
  if ( v15 < y )
    v15 = y;
  v16 = v15;
  vecMax->y = v16;
  v17 = vecMax->z;
  if ( v17 < z )
    v17 = z;
  v18 = v17;
  vecMax->z = v18;
  dst.x = 0.0;
  dst.y = 0.0;
  dst.z = 1.0;
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, src2: &dst, dst: &src2);
  v19 = src2.x;
  v20 = vecMin->x;
  if ( v20 > src2.x )
    v20 = src2.x;
  v21 = src2.y;
  v22 = v20;
  vecMin->x = v22;
  v23 = vecMin->y;
  if ( v23 > v21 )
    v23 = v21;
  v24 = src2.z;
  v25 = v23;
  vecMin->y = v25;
  v26 = vecMin->z;
  if ( v26 > v24 )
    v26 = v24;
  v27 = v26;
  vecMin->z = v27;
  v28 = vecMax->x;
  if ( v28 < v19 )
    v28 = v19;
  v29 = v28;
  vecMax->x = v29;
  v30 = vecMax->y;
  if ( v30 < v21 )
    v30 = v21;
  v31 = v30;
  vecMax->y = v31;
  v32 = vecMax->z;
  if ( v32 < v24 )
    v32 = v24;
  v33 = v32;
  vecMax->z = v33;
  dst.x = 0.0;
  dst.y = 1.0;
  dst.z = 0.0;
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, src2: &dst, dst: &src2);
  v34 = src2.x;
  v35 = vecMin->x;
  if ( v35 > src2.x )
    v35 = src2.x;
  v36 = src2.y;
  v37 = v35;
  vecMin->x = v37;
  v38 = vecMin->y;
  if ( v38 > v36 )
    v38 = v36;
  v39 = src2.z;
  v40 = v38;
  vecMin->y = v40;
  v41 = vecMin->z;
  if ( v41 > v39 )
    v41 = v39;
  v42 = v41;
  vecMin->z = v42;
  v43 = vecMax->x;
  if ( v43 < v34 )
    v43 = v34;
  v44 = v43;
  vecMax->x = v44;
  v45 = vecMax->y;
  if ( v45 < v36 )
    v45 = v36;
  v46 = v45;
  vecMax->y = v46;
  v47 = vecMax->z;
  if ( v47 < v39 )
    v47 = v39;
  v48 = v47;
  vecMax->z = v48;
  dst.x = 1.0;
  dst.y = 0.0;
  dst.z = 0.0;
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, src2: &dst, dst: &src2);
  v49 = src2.x;
  v50 = vecMin->x;
  if ( v50 > src2.x )
    v50 = src2.x;
  v51 = src2.y;
  v52 = v50;
  vecMin->x = v52;
  v53 = vecMin->y;
  if ( v53 > v51 )
    v53 = v51;
  v54 = src2.z;
  v55 = v53;
  vecMin->y = v55;
  v56 = vecMin->z;
  if ( v56 > v54 )
    v56 = v54;
  v57 = v56;
  vecMin->z = v57;
  v58 = vecMax->x;
  if ( v58 < v49 )
    v58 = v49;
  v59 = v58;
  vecMax->x = v59;
  v60 = vecMax->y;
  if ( v60 < v51 )
    v60 = v51;
  v61 = v60;
  vecMax->y = v61;
  v62 = vecMax->z;
  if ( v62 < v54 )
    v62 = v54;
  v63 = v62;
  vecMax->z = v63;
  dst.x = 0.0;
  dst.y = 1.0;
  dst.z = 1.0;
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, src2: &dst, dst: &src2);
  v64 = src2.x;
  v65 = vecMin->x;
  if ( v65 > src2.x )
    v65 = src2.x;
  v66 = src2.y;
  v67 = v65;
  vecMin->x = v67;
  v68 = vecMin->y;
  if ( v68 > v66 )
    v68 = v66;
  v69 = src2.z;
  v70 = v68;
  vecMin->y = v70;
  v71 = vecMin->z;
  if ( v71 > v69 )
    v71 = v69;
  v72 = v71;
  vecMin->z = v72;
  v73 = vecMax->x;
  if ( v73 < v64 )
    v73 = v64;
  v74 = v73;
  vecMax->x = v74;
  v75 = vecMax->y;
  if ( v75 < v66 )
    v75 = v66;
  v76 = v75;
  vecMax->y = v76;
  v77 = vecMax->z;
  if ( v77 < v69 )
    v77 = v69;
  v78 = v77;
  vecMax->z = v78;
  dst.x = 1.0;
  dst.y = 0.0;
  dst.z = 1.0;
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, src2: &dst, dst: &src2);
  v79 = src2.x;
  v80 = vecMin->x;
  if ( v80 > src2.x )
    v80 = src2.x;
  v81 = src2.y;
  v82 = v80;
  vecMin->x = v82;
  v83 = vecMin->y;
  if ( v83 > v81 )
    v83 = v81;
  v84 = src2.z;
  v85 = v83;
  vecMin->y = v85;
  v86 = vecMin->z;
  if ( v86 > v84 )
    v86 = v84;
  v87 = v86;
  vecMin->z = v87;
  v88 = vecMax->x;
  if ( v88 < v79 )
    v88 = v79;
  v89 = v88;
  vecMax->x = v89;
  v90 = vecMax->y;
  if ( v90 < v81 )
    v90 = v81;
  v91 = v90;
  vecMax->y = v91;
  v92 = vecMax->z;
  if ( v92 < v84 )
    v92 = v84;
  v93 = v92;
  vecMax->z = v93;
  dst.x = 1.0;
  dst.y = 1.0;
  dst.z = 0.0;
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, src2: &dst, dst: &src2);
  v94 = src2.x;
  v95 = vecMin->x;
  if ( v95 > src2.x )
    v95 = src2.x;
  v96 = src2.y;
  v97 = v95;
  vecMin->x = v97;
  v98 = vecMin->y;
  if ( v98 > v96 )
    v98 = v96;
  v99 = src2.z;
  v100 = v98;
  vecMin->y = v100;
  v101 = vecMin->z;
  if ( v101 > v99 )
    v101 = v99;
  v102 = v101;
  vecMin->z = v102;
  v103 = vecMax->x;
  if ( v103 < v94 )
    v103 = v94;
  v104 = v103;
  vecMax->x = v104;
  v105 = vecMax->y;
  if ( v105 < v96 )
    v105 = v96;
  v106 = v105;
  vecMax->y = v106;
  v107 = vecMax->z;
  if ( v107 < v99 )
    v107 = v99;
  v108 = v107;
  vecMax->z = v108;
  dst.x = 1.0;
  dst.y = 1.0;
  dst.z = 1.0;
  Vector3DMultiplyPositionProjective(src1: &flashlightToWorld, src2: &dst, dst: &src2);
  v109 = src2.x;
  v110 = vecMin->x;
  if ( v110 > src2.x )
    v110 = src2.x;
  v111 = src2.y;
  v112 = v110;
  vecMin->x = v112;
  v113 = vecMin->y;
  if ( v113 > v111 )
    v113 = v111;
  v114 = src2.z;
  v115 = v113;
  vecMin->y = v115;
  v116 = vecMin->z;
  if ( v116 > v114 )
    v116 = v114;
  v117 = v116;
  vecMin->z = v117;
  v118 = vecMax->x;
  if ( v118 < v109 )
    v118 = v109;
  v119 = v118;
  vecMax->x = v119;
  v120 = vecMax->y;
  if ( v120 < v111 )
    v120 = v111;
  v121 = v120;
  vecMax->y = v121;
  v122 = vecMax->z;
  if ( v122 < v114 )
    v122 = v114;
  vecMax->z = v122;
}

//------------------------------------------------------------------------------
// Address: 0x100B4AC0
// Name: private: virtual void CClientShadowMgr::UnlockAllShadowDepthTextures(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::UnlockAllShadowDepthTextures(CClientShadowMgr *this)
{
  int i; // eax

  for ( i = 0; i < this->m_DepthTextureCache.m_Size; ++i )
    this->m_DepthTextureCacheLocks.m_Memory.m_pMemory[i] = false;
  shadowmgr->SetSinglePassFlashlightRenderState(this: shadowmgr, a2: 0xFFFFu);
  shadowmgr->PopSinglePassFlashlightStateEnabled(this: shadowmgr);
}

//------------------------------------------------------------------------------
// Address: 0x100B4B10
// Name: private: virtual void CClientShadowMgr::SetFlashlightTarget(unsigned short,class CHandle<class C_BaseEntity>)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::SetFlashlightTarget(
        CClientShadowMgr *this,
        unsigned __int16 shadowHandle,
        CHandle<C_BaseEntity> targetEntity)
{
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *v3; // eax

  v3 = &this->m_Shadows.m_Memory.m_pMemory[shadowHandle];
  if ( (v3->m_Element.m_Flags & 5) != 0 )
    v3->m_Element.m_hTargetEntity = targetEntity;
}

//------------------------------------------------------------------------------
// Address: 0x100B4B40
// Name: private: virtual void CClientShadowMgr::SetFlashlightLightWorld(unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::SetFlashlightLightWorld(
        CClientShadowMgr *this,
        unsigned __int16 shadowHandle,
        bool bLightWorld)
{
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *v3; // eax
  unsigned __int16 m_Flags; // cx

  v3 = &this->m_Shadows.m_Memory.m_pMemory[shadowHandle];
  m_Flags = v3->m_Element.m_Flags;
  if ( (m_Flags & 5) != 0 )
  {
    if ( bLightWorld )
      v3->m_Element.m_Flags = m_Flags | 0x400;
    else
      v3->m_Element.m_Flags = m_Flags & 0xFBFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B4B80
// Name: private: bool CClientShadowMgr::IsFlashlightTarget(unsigned short,class IClientRenderable __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientShadowMgr::IsFlashlightTarget(
        CClientShadowMgr *this,
        unsigned __int16 shadowHandle,
        IClientRenderable *pRenderable)
{
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *v3; // esi
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  unsigned int v7; // esi
  IHandleEntity *v8; // eax
  IHandleEntity_vtbl *v9; // ecx
  IHandleEntity *v10; // esi
  IHandleEntity_vtbl *v11; // ecx
  IHandleEntity *v12; // eax

  v3 = &this->m_Shadows.m_Memory.m_pMemory[shadowHandle];
  m_Index = v3->m_Element.m_hTargetEntity.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( (IClientRenderable *)m_pEntity->__vftable[1].GetRefEHandle(this: m_pEntity) == pRenderable )
    return 1;
  v7 = v3->m_Element.m_hTargetEntity.m_Index;
  if ( v7 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
    v8 = nullptr;
  else
    v8 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
  v9 = v8[190].__vftable;
  if ( v9 == (IHandleEntity_vtbl *)-1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_SerialNumber != (unsigned int)v9 >> 16 )
  {
    v10 = nullptr;
  }
  else
  {
    v10 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_pEntity;
  }
  if ( v10 != nullptr )
  {
    while ( (IClientRenderable *)v10->__vftable[1].GetRefEHandle(this: v10) != pRenderable )
    {
      v11 = v10[191].__vftable;
      if ( v11 == (IHandleEntity_vtbl *)-1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != (unsigned int)v11 >> 16 )
      {
        v12 = nullptr;
      }
      else
      {
        v12 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
      }
      v10 = v12;
      if ( v12 == nullptr )
        return 0;
    }
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100B4C80
// Name: DeferredShadowDownsampleToggleCallback
// Source: json
//------------------------------------------------------------------------------
void __cdecl DeferredShadowDownsampleToggleCallback()
{
  CMaterialReference::Shutdown(this: &s_ClientShadowMgr.m_RenderDeferredShadowMat, bDeleteIfUnreferenced: false);
  CMaterialReference::Shutdown(this: &s_ClientShadowMgr.m_RenderDeferredSimpleShadowMat, bDeleteIfUnreferenced: false);
  CTextureReference::Shutdown(this: &s_ClientShadowMgr.m_downSampledNormals, bDeleteIfUnReferenced: false);
  CTextureReference::Shutdown(this: &s_ClientShadowMgr.m_downSampledDepth, bDeleteIfUnReferenced: false);
}

//------------------------------------------------------------------------------
// Address: 0x100B4CC0
// Name: public: virtual void CShadowModelProxy::OnBind(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowModelProxy::OnBind(CShadowModelProxy *this, void *pProxyData)
{
  const ShadowInfo_t *v3; // edi

  this->m_BaseTextureVar->SetTextureValue(
    this: this->m_BaseTextureVar,
    a2: s_ClientShadowMgr.m_ShadowAllocator.m_TexturePage.m_pTexture);
  v3 = shadowmgr->GetInfo(
         this: shadowmgr,
         a2: s_ClientShadowMgr.m_Shadows.m_Memory.m_pMemory[(unsigned __int16)pProxyData].m_Element.m_ShadowHandle);
  this->m_BaseTextureMatrixVar->SetMatrixValue(this: this->m_BaseTextureMatrixVar, a2: (const VMatrix *)v3);
  this->m_BaseTextureOffsetVar->SetVecValue_4(
    this: this->m_BaseTextureOffsetVar,
    a2: (const float *)&v3->m_TexOrigin,
    a3: 2);
  this->m_BaseTextureScaleVar->SetVecValue_4(
    this: this->m_BaseTextureScaleVar,
    a2: (const float *)&v3->m_TexSize,
    a3: 2);
  ((void (__stdcall *)(_DWORD))this->m_FalloffOffsetVar->SetFloatValue)(a1: LODWORD(v3->m_FalloffOffset));
  ((void (__stdcall *)(_DWORD))this->m_FalloffDistanceVar->SetFloatValue)(a1: LODWORD(v3->m_MaxDist));
  ((void (__stdcall *)(_DWORD))this->m_FalloffAmountVar->SetFloatValue)(a1: LODWORD(v3->m_FalloffAmount));
}

//------------------------------------------------------------------------------
// Address: 0x100B4D70
// Name: public: unsigned short CUtlMultiList<struct CTextureAllocator::FragmentInfo_t,unsigned short>::Alloc(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::Alloc(
        CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short> *this)
{
  int m_FirstFree; // ecx
  int m_MaxElementIndex; // ecx
  int result; // eax
  int v5; // ecx

  m_FirstFree = this->m_FirstFree;
  if ( (_WORD)m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
    goto LABEL_13;
  }
  m_MaxElementIndex = this->m_MaxElementIndex;
  if ( (unsigned __int16)m_MaxElementIndex != m_MaxElementIndex || (_WORD)m_MaxElementIndex == 0xFFFF )
  {
    if ( `CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::Alloc'::`9'::__executeCount < 10 )
    {
      ++`CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::Alloc'::`9'::__executeCount;
      _Warning(a1: "CUtlMultiList overflow! (exhausted index range)\n");
    }
    return 0xFFFF;
  }
  if ( m_MaxElementIndex != this->m_Memory.m_nAllocationCount
    || (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
          (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
          num: 1),
        this->m_pElements = this->m_Memory.m_pMemory,
        (m_MaxElementIndex = this->m_MaxElementIndex) < this->m_Memory.m_nAllocationCount) )
  {
    result = LOWORD(this->m_MaxElementIndex);
    this->m_MaxElementIndex = m_MaxElementIndex + 1;
LABEL_13:
    v5 = (unsigned __int16)result;
    this->m_Memory.m_pMemory[v5].m_Previous = result;
    this->m_Memory.m_pMemory[v5].m_Next = result;
    ++this->m_TotalElements;
    return result;
  }
  if ( `CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::Alloc'::`19'::__executeCount >= 10 )
    return 0xFFFF;
  ++`CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::Alloc'::`19'::__executeCount;
  _Warning(a1: "CUtlMultiList overflow! (exhausted memory allocator)\n");
  return 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x100B4E30
// Name: public: void CUtlMultiList<struct CTextureAllocator::FragmentInfo_t,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::RemoveAll(
        CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short> *this)
{
  int m_MaxElementIndex; // esi
  int v2; // esi
  unsigned __int16 i; // di
  unsigned __int16 v4; // dx
  int v5; // eax
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx
  int v8; // eax

  m_MaxElementIndex = this->m_MaxElementIndex;
  if ( m_MaxElementIndex != 0 )
  {
    v2 = m_MaxElementIndex - 1;
    for ( i = -1; v2 >= 0; i = v4 )
    {
      v4 = v2;
      v5 = (unsigned __int16)v2--;
      this->m_Memory.m_pMemory[v5].m_Next = i;
      this->m_Memory.m_pMemory[v5].m_Previous = v4;
    }
    this->m_FirstFree = 0;
    m_Head = this->m_List.m_Head;
    if ( m_Head != 0xFFFF )
    {
      m_pMemory = this->m_List.m_Memory.m_pMemory;
      do
      {
        v8 = m_Head;
        m_pMemory[v8].m_Element.m_Head = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Tail = -1;
        this->m_List.m_Memory.m_pMemory[v8].m_Element.m_Count = 0;
        m_pMemory = this->m_List.m_Memory.m_pMemory;
        m_Head = m_pMemory[v8].m_Next;
      }
      while ( m_Head != 0xFFFF );
    }
    this->m_TotalElements = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B5EA0
// Name: private: float CVisibleShadowList::ComputeScreenArea(class Vector const __near &,float)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CVisibleShadowList::ComputeScreenArea(CVisibleShadowList *this, const Vector *vecCenter, float r)
{
  IMatRenderContext *v3; // esi
  double v4; // st7
  float ra; // [esp+14h] [ebp+Ch]

  v3 = materials->GetRenderContext(this: materials);
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  v4 = ((double (__thiscall *)(IMatRenderContext *, const Vector *, _DWORD))v3->ComputePixelDiameterOfSphere)(
         a1: v3,
         a2: vecCenter,
         a3: LODWORD(r));
  ra = v4 * v4;
  v3->EndRender(this: v3);
  v3->Release(this: v3);
  return ra;
}

//------------------------------------------------------------------------------
// Address: 0x100B5F00
// Name: public: void CClientShadowMgr::RestoreRenderState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::RestoreRenderState(CClientShadowMgr *this)
{
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *m_pMemory; // ecx
  int v4; // eax

  m_Head = this->m_Shadows.m_Head;
  if ( m_Head != 0xFFFF )
  {
    m_pMemory = this->m_Shadows.m_Memory.m_pMemory;
    do
    {
      v4 = m_Head;
      m_pMemory[v4].m_Element.m_Flags |= 0x80u;
      m_pMemory = this->m_Shadows.m_Memory.m_pMemory;
      m_Head = m_pMemory[v4].m_Next;
    }
    while ( m_Head != 0xFFFF );
  }
  this->SetShadowColor(
    this,
    a2: this->m_AmbientLightColor.r,
    a3: this->m_AmbientLightColor.g,
    a4: this->m_AmbientLightColor.b);
  this->m_bRenderTargetNeedsClear = true;
}

//------------------------------------------------------------------------------
// Address: 0x100B5F70
// Name: private: void CClientShadowMgr::UpdateAllShadows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::UpdateAllShadows(CClientShadowMgr *this)
{
  unsigned __int16 i; // ax
  unsigned int v3; // esi
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *m_pMemory; // eax
  unsigned int v5; // esi
  IClientRenderable *ClientRenderableFromHandle; // eax

  for ( i = this->m_Shadows.m_Head; i != 0xFFFF; i = this->m_Shadows.m_Memory.m_pMemory[v5].m_Next )
  {
    v3 = i;
    m_pMemory = this->m_Shadows.m_Memory.m_pMemory;
    v5 = v3;
    if ( (m_pMemory[v5].m_Element.m_Flags & 5) == 0 )
    {
      ClientRenderableFromHandle = CClientEntityList::GetClientRenderableFromHandle(
                                     this: (CClientEntityList *)cl_entitylist.m_Index,
                                     hEnt: m_pMemory[v5].m_Element.m_Entity);
      if ( ClientRenderableFromHandle != nullptr )
        this->AddToDirtyShadowList(this, a2: ClientRenderableFromHandle, a3: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B5FD0
// Name: public: virtual void CClientShadowMgr::SetShadowDirection(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::SetShadowDirection(CClientShadowMgr *this, const Vector *dir)
{
  this->m_SimpleShadowDir = *dir;
  VectorNormalize(vec: &this->m_SimpleShadowDir);
  if ( this->m_RenderToTextureActive )
    CClientShadowMgr::UpdateAllShadows(this);
}

//------------------------------------------------------------------------------
// Address: 0x100B6010
// Name: private: float CClientShadowMgr::GetShadowDistance(class IClientRenderable __near *)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CClientShadowMgr::GetShadowDistance(CClientShadowMgr *this, IClientRenderable *pRenderable)
{
  unsigned __int16 (__thiscall *GetShadowHandle)(IClientRenderable *); // edx
  unsigned __int16 v4; // ax
  ShadowType_t v5; // eax
  unsigned __int16 m_Flags; // ax
  int m_RenderToTextureActive; // eax
  float flDist; // [esp+8h] [ebp-4h] BYREF

  GetShadowHandle = pRenderable->GetShadowHandle;
  flDist = this->m_flShadowCastDist;
  v4 = GetShadowHandle(this: pRenderable);
  if ( v4 == 0xFFFF )
  {
    v5 = SHADOWS_NONE;
  }
  else
  {
    m_Flags = this->m_Shadows.m_Memory.m_pMemory[v4].m_Element.m_Flags;
    if ( (m_Flags & 8) != 0 )
      m_RenderToTextureActive = this->m_RenderToTextureActive;
    else
      m_RenderToTextureActive = (m_Flags & 0x20) != 0 ? 3 : 0;
    v5 = m_RenderToTextureActive + 1;
  }
  pRenderable->GetShadowCastDistance(this: pRenderable, a2: &flDist, a3: v5);
  return flDist;
}

//------------------------------------------------------------------------------
// Address: 0x100B6090
// Name: private: class Vector const __near & CClientShadowMgr::GetShadowDirection(class IClientRenderable __near *)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CClientShadowMgr::GetShadowDirection(CClientShadowMgr *this, IClientRenderable *pRenderable)
{
  Vector *v3; // esi
  const Vector *v4; // eax
  unsigned __int16 (__thiscall *GetShadowHandle)(IClientRenderable *); // edx
  unsigned __int16 v6; // ax
  unsigned __int16 m_Flags; // ax

  v3 = AllocTempVector();
  v4 = this->GetShadowDirection(this);
  v3->x = v4->x;
  v3->y = v4->y;
  GetShadowHandle = pRenderable->GetShadowHandle;
  v3->z = v4->z;
  v6 = GetShadowHandle(this: pRenderable);
  if ( v6 == 0xFFFF )
  {
    pRenderable->GetShadowCastDirection(this: pRenderable, a2: v3, a3: SHADOWS_NONE);
    return v3;
  }
  else
  {
    m_Flags = this->m_Shadows.m_Memory.m_pMemory[v6].m_Element.m_Flags;
    if ( (m_Flags & 8) != 0 )
      pRenderable->GetShadowCastDirection(
        this: pRenderable,
        a2: v3,
        a3: (ShadowType_t)(this->m_RenderToTextureActive + 1));
    else
      pRenderable->GetShadowCastDirection(
        this: pRenderable,
        a2: v3,
        a3: (ShadowType_t)((m_Flags & 0x20) != 0 ? SHADOWS_RENDER_TO_DEPTH_TEXTURE : SHADOWS_SIMPLE));
    return v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B6140
// Name: private: class Vector const __near & CClientShadowMgr::GetShadowDirection(unsigned short)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CClientShadowMgr::GetShadowDirection(CClientShadowMgr *this, unsigned __int16 shadowHandle)
{
  unsigned int v2; // ebx
  IClientRenderable *ClientRenderableFromHandle; // eax
  Vector *v6; // esi
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *m_pMemory; // eax
  double x; // st7
  int p_m_ShadowDir; // ebx
  double v10; // st7
  IClientRenderable *v11; // ebx
  int ActualShadowCastType; // eax
  IClientRenderable *shadowHandlea; // [esp+14h] [ebp+8h]
  IClientRenderable shadowHandleb; // [esp+14h] [ebp+8h]

  v2 = shadowHandle;
  ClientRenderableFromHandle = CClientEntityList::GetClientRenderableFromHandle(
                                 this: (CClientEntityList *)cl_entitylist.m_Index,
                                 hEnt: this->m_Shadows.m_Memory.m_pMemory[v2].m_Element.m_Entity);
  shadowHandlea = ClientRenderableFromHandle;
  if ( !this->m_bShadowFromWorldLights || this->m_bSuppressShadowFromWorldLights )
    return CClientShadowMgr::GetShadowDirection(this, pRenderable: ClientRenderableFromHandle);
  v6 = AllocTempVector();
  m_pMemory = this->m_Shadows.m_Memory.m_pMemory;
  x = m_pMemory[v2].m_Element.m_ShadowDir.x;
  p_m_ShadowDir = (int)&m_pMemory[v2].m_Element.m_ShadowDir;
  v6->x = x;
  v6->y = *(float *)(p_m_ShadowDir + 4);
  v10 = *(float *)(p_m_ShadowDir + 8);
  v11 = shadowHandlea;
  v6->z = v10;
  shadowHandleb.__vftable = shadowHandlea->__vftable;
  ActualShadowCastType = CClientShadowMgr::GetActualShadowCastType(this, pEnt: v11);
  shadowHandleb.GetShadowCastDirection(this: v11, a2: v6, a3: (ShadowType_t)ActualShadowCastType);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x100B61E0
// Name: public: virtual void CClientShadowMgr::SetShadowDistance(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::SetShadowDistance(CClientShadowMgr *this, float flMaxDistance)
{
  this->m_flShadowCastDist = flMaxDistance;
  CClientShadowMgr::UpdateAllShadows(this);
}

//------------------------------------------------------------------------------
// Address: 0x100B6200
// Name: public: virtual void CClientShadowMgr::RenderShadowTexture(int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CClientShadowMgr::RenderShadowTexture(CClientShadowMgr *this@<ecx>, int a2@<edi>, int w, int h)
{
  int v5; // edi
  IMesh *v6; // esi
  float *m_pCurrPosition; // eax
  float *v8; // eax
  float *v9; // eax
  float *v10; // eax
  float *v11; // eax
  float *v12; // eax
  float *v13; // eax
  float *v14; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1E8h] BYREF

  if ( this->m_RenderToTextureActive )
  {
    v5 = ((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(a1: materials, a2);
    if ( v5 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 8))(a1: v5);
    (*(void (__thiscall **)(int, IMaterial *, _DWORD))(*(_DWORD *)v5 + 36))(
      a1: v5,
      a2: this->m_RenderShadow.m_pMaterial,
      a3: 0);
    v6 = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v5 + 228))(
                    a1: v5,
                    a2: 1,
                    a3: 0,
                    a4: 0,
                    a5: 0);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v6;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_QUADS;
    v6->SetPrimitiveType(this: v6, a2: MATERIAL_TRIANGLES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v6->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v6, nMaxVertexCount: 4, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
    m_pCurrPosition[1] = 0.0;
    m_pCurrPosition[2] = 0.0;
    v8 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v8[1] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = 0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v9 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)w;
    v9[1] = 0.0;
    v9[2] = 0.0;
    v10 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
    v10[1] = 0.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = 0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v11 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)w;
    v11[1] = (float)h;
    v11[2] = 0.0;
    v12 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
    v12[1] = 1.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = 0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v13 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = 0.0;
    *(_QWORD *)(v13 + 1) = COERCE_UNSIGNED_INT((float)h);
    v14 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v14[1] = 1.0;
    *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = 0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
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
    ((void (__thiscall *)(IMesh *, int, int))meshBuilder.m_pMesh->UnlockMesh)(
      a1: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v6->Draw_2(this: v6, a2: -1, a3: 0);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 12))(a1: v5);
    (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 4))(a1: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B6500
// Name: public: virtual void CClientShadowMgr::UpdateFlashlightState(unsigned short,struct FlashlightState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::UpdateFlashlightState(
        CClientShadowMgr *this,
        unsigned __int16 shadowHandle,
        const FlashlightState_t *flashlightState)
{
  int v4; // esi

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CClientShadowMgr::UpdateFlashlightState",
    a3: 0,
    a4: "Flashlight Shadows",
    a5: false,
    a6: 4);
  if ( flashlightState->m_bEnableShadows
    && r_flashlightdepthtexture.m_pParent != nullptr
    && r_flashlightdepthtexture.m_pParent->m_Value.m_nValue != 0 )
  {
    v4 = shadowHandle;
    this->m_Shadows.m_Memory.m_pMemory[v4].m_Element.m_Flags |= 0x20u;
  }
  else
  {
    v4 = shadowHandle;
    this->m_Shadows.m_Memory.m_pMemory[v4].m_Element.m_Flags &= ~0x20u;
  }
  if ( flashlightState->m_bOrtho )
    CClientShadowMgr::BuildOrthoWorldToFlashlightMatrix(
      this,
      matWorldToShadow: &this->m_Shadows.m_Memory.m_pMemory[v4].m_Element.m_WorldToShadow,
      flashlightState);
  else
    CClientShadowMgr::BuildPerspectiveWorldToFlashlightMatrix(
      this,
      matWorldToShadow: &this->m_Shadows.m_Memory.m_pMemory[v4].m_Element.m_WorldToShadow,
      flashlightState);
  ((void (__stdcall *)(_DWORD, const FlashlightState_t *))shadowmgr->UpdateFlashlightState)(
    a1: this->m_Shadows.m_Memory.m_pMemory[v4].m_Element.m_ShadowHandle,
    a2: flashlightState);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x100B65C0
// Name: public: virtual void CClientShadowMgr::UpdateProjectionState(unsigned short,struct FlashlightState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::UpdateProjectionState(
        CClientShadowMgr *this,
        unsigned __int16 shadowHandle,
        const FlashlightState_t *flashlightState)
{
  int v4; // esi

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CClientShadowMgr::UpdateProjectionState",
    a3: 0,
    a4: "Flashlight Shadows",
    a5: false,
    a6: 4);
  v4 = shadowHandle;
  if ( flashlightState->m_bOrtho )
    CClientShadowMgr::BuildOrthoWorldToFlashlightMatrix(
      this,
      matWorldToShadow: &this->m_Shadows.m_Memory.m_pMemory[v4].m_Element.m_WorldToShadow,
      flashlightState);
  else
    CClientShadowMgr::BuildPerspectiveWorldToFlashlightMatrix(
      this,
      matWorldToShadow: &this->m_Shadows.m_Memory.m_pMemory[v4].m_Element.m_WorldToShadow,
      flashlightState);
  ((void (__stdcall *)(_DWORD, const FlashlightState_t *))shadowmgr->UpdateFlashlightState)(
    a1: this->m_Shadows.m_Memory.m_pMemory[v4].m_Element.m_ShadowHandle,
    a2: flashlightState);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x100B6650
// Name: public: void CClientShadowMgr::ComputeShadowBBox(class IClientRenderable __near *,unsigned short,class Vector const __near &,float,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::ComputeShadowBBox(
        CClientShadowMgr *this,
        IClientRenderable *pRenderable,
        float shadowHandle,
        const Vector *vecAbsCenter,
        float flRadius,
        Vector *pAbsMins,
        Vector *pAbsMaxs)
{
  const Vector *ShadowDirection; // eax
  __int64 v9; // xmm0_8
  const Vector *v10; // esi
  unsigned __int16 (__thiscall *GetShadowHandle)(IClientRenderable *); // eax
  unsigned __int16 v12; // ax
  ShadowType_t v13; // eax
  unsigned __int16 m_Flags; // ax
  int m_RenderToTextureActive; // eax
  float *v16; // eax
  float v17; // xmm0_4
  float v18; // xmm2_4
  const Vector *v19; // edx
  Vector vecShadowDir; // [esp+Ch] [ebp-14h] BYREF
  int v21; // [esp+18h] [ebp-8h]
  int v22; // [esp+1Ch] [ebp-4h]

  ShadowDirection = CClientShadowMgr::GetShadowDirection(this, shadowHandle: LOWORD(shadowHandle));
  v9 = *(_QWORD *)&ShadowDirection->x;
  v10 = vecAbsCenter;
  vecShadowDir.z = ShadowDirection->z;
  v22 = (char *)pAbsMins - (char *)vecAbsCenter;
  *(_QWORD *)&vecShadowDir.x = v9;
  v21 = (char *)&vecShadowDir - (char *)pAbsMins;
  vecAbsCenter = (const Vector *)((char *)pAbsMaxs - (char *)vecAbsCenter);
  for ( pAbsMins = (Vector *)3; pAbsMins != nullptr; pAbsMins = (Vector *)((char *)pAbsMins - 1) )
  {
    GetShadowHandle = pRenderable->GetShadowHandle;
    shadowHandle = this->m_flShadowCastDist;
    v12 = GetShadowHandle(this: pRenderable);
    if ( v12 == 0xFFFF )
    {
      v13 = SHADOWS_NONE;
    }
    else
    {
      m_Flags = this->m_Shadows.m_Memory.m_pMemory[v12].m_Element.m_Flags;
      if ( (m_Flags & 8) != 0 )
        m_RenderToTextureActive = this->m_RenderToTextureActive;
      else
        m_RenderToTextureActive = (m_Flags & 0x20) != 0 ? 3 : 0;
      v13 = m_RenderToTextureActive + 1;
    }
    pRenderable->GetShadowCastDistance(this: pRenderable, a2: &shadowHandle, a3: v13);
    v16 = (float *)((char *)&v10->x + v22);
    v17 = *(float *)((char *)&v10->x + v22 + v21) * shadowHandle;
    v18 = v10->x - flRadius;
    if ( *(float *)((char *)&v10->x + v22 + v21) >= 0.0 )
    {
      *v16 = v18;
      *(float *)((char *)&v10->x + (_DWORD)vecAbsCenter) = (float)(v10->x + flRadius) + v17;
    }
    else
    {
      v19 = vecAbsCenter;
      *v16 = v18 + v17;
      *(float *)((char *)&v10->x + (_DWORD)v19) = v10->x + flRadius;
    }
    v10 = (const Vector *)((char *)v10 + 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B6780
// Name: private: bool CClientShadowMgr::CullReceiver(unsigned short,class IClientRenderable __near *,class IClientRenderable __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientShadowMgr::CullReceiver(
        CClientShadowMgr *this,
        unsigned __int16 handle,
        IClientRenderable *pRenderable,
        IClientRenderable *pSourceRenderable)
{
  unsigned int v4; // edi
  Frustum_t *v6; // esi
  bool v7; // bl
  IClientRenderable *v9; // ebx
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *m_pMemory; // eax
  float v11; // xmm2_4
  float v12; // xmm4_4
  float v13; // xmm3_4
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *v14; // eax
  float v15; // xmm2_4
  float m_MaxDist; // xmm1_4
  float v17; // xmm3_4
  IClientRenderable *v18; // edi
  const Vector *ShadowDirection; // eax
  float z; // edx
  float v21; // xmm0_4
  float v22; // xmm1_4
  cplane_t plane; // [esp+18h] [ebp-68h] BYREF
  Vector mins; // [esp+2Ch] [ebp-54h] BYREF
  Vector shadowMin; // [esp+38h] [ebp-48h] BYREF
  Vector shadowMax; // [esp+44h] [ebp-3Ch] BYREF
  Vector localOrigin; // [esp+50h] [ebp-30h] BYREF
  Vector vecShadowDir; // [esp+5Ch] [ebp-24h] BYREF
  Vector originSource; // [esp+68h] [ebp-18h] BYREF
  Vector origin; // [esp+74h] [ebp-Ch] BYREF
  int savedregs; // [esp+80h] [ebp+0h] BYREF

  v4 = handle;
  if ( (this->m_Shadows.m_Memory.m_pMemory[v4].m_Element.m_Flags & 5) != 0 )
  {
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "CClientShadowMgr::CullReceiver",
      a3: 0,
      a4: "Flashlight Shadows",
      a5: false,
      a6: 4);
    v6 = (Frustum_t *)((int (__stdcall *)(_DWORD))shadowmgr->GetFlashlightFrustum)(a1: this->m_Shadows.m_Memory.m_pMemory[v4].m_Element.m_ShadowHandle);
    pRenderable->GetRenderBoundsWorldspace(this: pRenderable, a2: &mins, a3: &vecShadowDir);
    v7 = Frustum_t::CullBox(this: v6, &mins, maxs: &vecShadowDir);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return v7;
  }
  v9 = pRenderable;
  CClientShadowMgr::ComputeBoundingSphere(
    this,
    a2: COERCE_FLOAT(&savedregs),
    a3: v4 * 276,
    a4: (int)this,
    pRenderable,
    &origin,
    radius: (float *)&pRenderable);
  m_pMemory = this->m_Shadows.m_Memory.m_pMemory;
  v11 = m_pMemory[v4].m_Element.m_WorldToShadow.m[0][0];
  v12 = m_pMemory[v4].m_Element.m_WorldToShadow.m[0][2];
  v13 = m_pMemory[v4].m_Element.m_WorldToShadow.m[0][1] * origin.y;
  v14 = &m_pMemory[v4];
  localOrigin.x = (float)((float)(v13 + (float)(v11 * origin.x)) + (float)(v12 * origin.z))
                + v14->m_Element.m_WorldToShadow.m[0][3];
  localOrigin.y = (float)((float)((float)(v14->m_Element.m_WorldToShadow.m[1][1] * origin.y)
                                + (float)(v14->m_Element.m_WorldToShadow.m[1][0] * origin.x))
                        + (float)(v14->m_Element.m_WorldToShadow.m[1][2] * origin.z))
                + v14->m_Element.m_WorldToShadow.m[1][3];
  localOrigin.z = (float)((float)((float)(v14->m_Element.m_WorldToShadow.m[2][1] * origin.y)
                                + (float)(v14->m_Element.m_WorldToShadow.m[2][0] * origin.x))
                        + (float)(v14->m_Element.m_WorldToShadow.m[2][2] * origin.z))
                + v14->m_Element.m_WorldToShadow.m[2][3];
  v15 = v14->m_Element.m_WorldSize.x * -0.5;
  shadowMin.y = v14->m_Element.m_WorldSize.y * -0.5;
  shadowMin.z = 0.0;
  shadowMin.x = v15;
  m_MaxDist = v14->m_Element.m_MaxDist;
  v17 = v14->m_Element.m_WorldSize.x * 0.5;
  shadowMax.y = v14->m_Element.m_WorldSize.y * 0.5;
  shadowMax.x = v17;
  shadowMax.z = m_MaxDist;
  if ( !IsBoxIntersectingSphere(
          boxMin: &shadowMin,
          boxMax: &shadowMax,
          center: &localOrigin,
          radius: *(float *)&pRenderable) )
    return 1;
  v18 = pSourceRenderable;
  CClientShadowMgr::ComputeBoundingSphere(
    this,
    a2: COERCE_FLOAT(&savedregs),
    a3: (int)pSourceRenderable,
    a4: (int)this,
    pRenderable: pSourceRenderable,
    origin: &originSource,
    radius: (float *)&pSourceRenderable);
  if ( IsSphereIntersectingSphere(
         center1: &originSource,
         radius1: *(float *)&pSourceRenderable,
         center2: &origin,
         radius2: *(float *)&pRenderable) )
  {
    if ( CClientShadowMgr::ComputeSeparatingPlane(this, pRend1: v9, pRend2: v18, pPlane: &plane) == 0 )
      return 0;
  }
  else
  {
    plane.normal.x = origin.x - originSource.x;
    plane.normal.y = origin.y - originSource.y;
    plane.normal.z = origin.z - originSource.z;
  }
  ShadowDirection = CClientShadowMgr::GetShadowDirection(this, shadowHandle: handle);
  z = ShadowDirection->z;
  *(_QWORD *)&vecShadowDir.x = *(_QWORD *)&ShadowDirection->x;
  v21 = (float)((float)(plane.normal.y * origin.y) + (float)(plane.normal.x * origin.x))
      + (float)(plane.normal.z * origin.z);
  v22 = (float)((float)(plane.normal.y * originSource.y) + (float)(plane.normal.x * originSource.x))
      + (float)(plane.normal.z * originSource.z);
  vecShadowDir.z = z;
  if ( (float)((float)((float)(vecShadowDir.y * plane.normal.y) + (float)(plane.normal.x * vecShadowDir.x))
             + (float)(z * plane.normal.z)) <= 0.0 )
  {
    if ( v21 >= v22 )
      return 1;
  }
  else if ( v22 >= v21 )
  {
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100B6A80
// Name: public: virtual void CClientShadowMgr::AddShadowToReceiver(unsigned short,class IClientRenderable __near *,enum ShadowReceiver_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::AddShadowToReceiver(
        CClientShadowMgr *this,
        unsigned __int16 handle,
        IClientRenderable *pRenderable,
        ShadowReceiver_t type)
{
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *v5; // edi
  IShadowMgr_vtbl *v6; // ebx
  unsigned __int16 v7; // ax
  int v8; // eax
  int v9; // eax
  IShadowMgr_vtbl *v10; // ebx
  const QAngle *v11; // eax
  int v12; // eax
  int v13; // eax
  IShadowMgr_vtbl *v14; // ebx
  const QAngle *v15; // eax
  int v16; // eax
  int v17; // eax
  IClientRenderable *pSourceRenderable; // [esp+Ch] [ebp-4h]

  v5 = &this->m_Shadows.m_Memory.m_pMemory[handle];
  pSourceRenderable = CClientEntityList::GetClientRenderableFromHandle(
                        this: (CClientEntityList *)cl_entitylist.m_Index,
                        hEnt: v5->m_Element.m_Entity);
  if ( pSourceRenderable != pRenderable
    && pRenderable->ShouldReceiveProjectedTextures(this: pRenderable, a2: 7)
    && CClientShadowMgr::CullReceiver(this, handle, pRenderable, pSourceRenderable) == 0 )
  {
    if ( type != SHADOW_RECEIVER_BRUSH_MODEL )
    {
      if ( type == SHADOW_RECEIVER_STATIC_PROP )
      {
        if ( CClientShadowMgr::GetActualShadowCastType(this, handle) != 2 )
        {
          if ( (v5->m_Element.m_Flags & 5) == 0 )
            return;
          CVProfile::EnterScope(
            this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
            a2: "CClientShadowMgr::AddShadowToReceiver",
            a3: 0,
            a4: "Flashlight Shadows",
            a5: false,
            a6: 4);
          if ( CHandle<C_BaseEntity>::operator!(this: &v5->m_Element.m_hTargetEntity)
            || CClientShadowMgr::IsFlashlightTarget(this, shadowHandle: handle, pRenderable) != 0 )
          {
            staticpropmgr->AddShadowToStaticProp(this: staticpropmgr, a2: v5->m_Element.m_ShadowHandle, a3: pRenderable);
          }
          goto LABEL_27;
        }
        if ( r_shadow_deferred.m_pParent == nullptr || r_shadow_deferred.m_pParent->m_Value.m_nValue == 0 )
        {
          v8 = pSourceRenderable->GetIClientUnknown(this: pSourceRenderable);
          v9 = (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 28))(a1: v8);
          if ( v9 != 0 && (*(_DWORD *)(v9 + 248) & 0x4100) != 0 )
            staticpropmgr->AddShadowToStaticProp(this: staticpropmgr, a2: v5->m_Element.m_ShadowHandle, a3: pRenderable);
        }
      }
      else if ( type == SHADOW_RECEIVER_STUDIO_MODEL && (v5->m_Element.m_Flags & 5) != 0 )
      {
        CVProfile::EnterScope(
          this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
          a2: "CClientShadowMgr::AddShadowToReceiver",
          a3: 0,
          a4: "Flashlight Shadows",
          a5: false,
          a6: 4);
        if ( CHandle<C_BaseEntity>::operator!(this: &v5->m_Element.m_hTargetEntity)
          || CClientShadowMgr::IsFlashlightTarget(this, shadowHandle: handle, pRenderable) != 0 )
        {
          pRenderable->CreateModelInstance(this: pRenderable);
          v6 = shadowmgr->__vftable;
          v7 = pRenderable->GetModelInstance(this: pRenderable);
          v6->AddShadowToModel(this: shadowmgr, a2: v5->m_Element.m_ShadowHandle, a3: v7);
        }
LABEL_27:
        CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      }
    }
    else
    {
      if ( (v5->m_Element.m_Flags & 5) != 0 )
      {
        CVProfile::EnterScope(
          this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
          a2: "CClientShadowMgr::AddShadowToReceiver",
          a3: 0,
          a4: "Flashlight Shadows",
          a5: false,
          a6: 4);
        if ( CHandle<C_BaseEntity>::operator!(this: &v5->m_Element.m_hTargetEntity)
          || CClientShadowMgr::IsFlashlightTarget(this, shadowHandle: handle, pRenderable) != 0 )
        {
          v10 = shadowmgr->__vftable;
          v11 = pRenderable->GetRenderAngles(this: pRenderable);
          v12 = ((int (__thiscall *)(IClientRenderable *, const QAngle *))pRenderable->GetRenderOrigin)(
                  a1: pRenderable,
                  a2: v11);
          v13 = ((int (__thiscall *)(IClientRenderable *, int))pRenderable->GetModel)(a1: pRenderable, a2: v12);
          ((void (__thiscall *)(IShadowMgr *, _DWORD, int))v10->AddShadowToBrushModel)(
            a1: shadowmgr,
            a2: v5->m_Element.m_ShadowHandle,
            a3: v13);
        }
        goto LABEL_27;
      }
      if ( r_shadow_deferred.m_pParent == nullptr || r_shadow_deferred.m_pParent->m_Value.m_nValue == 0 )
      {
        v14 = shadowmgr->__vftable;
        v15 = pRenderable->GetRenderAngles(this: pRenderable);
        v16 = ((int (__thiscall *)(IClientRenderable *, const QAngle *))pRenderable->GetRenderOrigin)(
                a1: pRenderable,
                a2: v15);
        v17 = ((int (__thiscall *)(IClientRenderable *, int))pRenderable->GetModel)(a1: pRenderable, a2: v16);
        ((void (__thiscall *)(IShadowMgr *, _DWORD, int))v14->AddShadowToBrushModel)(
          a1: shadowmgr,
          a2: v5->m_Element.m_ShadowHandle,
          a3: v17);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B6D40
// Name: private: bool CClientShadowMgr::DrawShadowHierarchy(class IClientRenderable __near *,struct CClientShadowMgr::ClientShadow_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CClientShadowMgr::DrawShadowHierarchy(
        CClientShadowMgr *this,
        IClientRenderable *pRenderable,
        const CClientShadowMgr::ClientShadow_t *shadow,
        int bChild)
{
  unsigned __int16 (__thiscall *GetShadowHandle)(IClientRenderable *); // edx
  CClientShadowMgr *v5; // edi
  char v6; // bl
  unsigned __int16 v7; // ax
  unsigned __int16 m_Flags; // ax
  bool v10; // zf
  bool v11; // cl
  IVModelInfoClient_vtbl *v12; // edi
  const struct model_t *v13; // eax
  int v14; // eax
  int (__thiscall *DrawModel)(IClientRenderable *, int, const RenderableInstance_t *); // edx
  IMatRenderContext *v16; // edi
  matrix3x4a_t *(__thiscall **p_DrawModelShadowSetup)(IVModelRender *, IClientRenderable *, int, int, DrawModelInfo_t *, matrix3x4a_t *); // ebx
  int v18; // eax
  int v19; // eax
  matrix3x4a_t *v20; // eax
  IClientRenderable *i; // esi
  DrawModelInfo_t info; // [esp+Ch] [ebp-1E4h] BYREF
  CClientShadowMgr *v23; // [esp+1ECh] [ebp-4h]

  GetShadowHandle = pRenderable->GetShadowHandle;
  v5 = this;
  v23 = this;
  v6 = 0;
  v7 = GetShadowHandle(this: pRenderable);
  if ( v7 == 0xFFFF )
    goto LABEL_22;
  m_Flags = v5->m_Shadows.m_Memory.m_pMemory[v7].m_Element.m_Flags;
  if ( (m_Flags & 8) != 0 )
  {
    if ( !v5->m_RenderToTextureActive )
      return 0;
    if ( v5->m_RenderToTextureActive == -1 )
      goto LABEL_22;
  }
  else if ( (m_Flags & 0x20) == 0 )
  {
    return 0;
  }
  if ( (_BYTE)bChild != 0 )
  {
    v12 = modelinfo->__vftable;
    v13 = pRenderable->GetModel(this: pRenderable);
    v14 = v12->GetModelType(this: modelinfo, a2: v13);
    v5 = v23;
    v11 = v14 == 3;
    v10 = v14 == 1;
  }
  else
  {
    v11 = (shadow->m_Flags & 0x100) == 0;
    v10 = (shadow->m_Flags & 0x100) != 0;
  }
  if ( (shadow->m_Flags & 0x40) != 0 )
  {
    DrawModel = pRenderable->DrawModel;
    HIBYTE(bChild) = -1;
    DrawModel(this: pRenderable, a2: 0x20000000, a3: (const RenderableInstance_t *)&bChild + 3);
LABEL_21:
    v6 = 1;
    goto LABEL_22;
  }
  if ( v11 )
  {
    v16 = materials->GetRenderContext(this: materials);
    if ( v16 != nullptr )
      v16->BeginRender(this: v16);
    v16->AddRefRenderData(this: v16);
    p_DrawModelShadowSetup = &modelrender->DrawModelShadowSetup;
    v18 = ((int (__thiscall *)(IClientRenderable *, DrawModelInfo_t *, _DWORD))pRenderable->GetSkin)(
            a1: pRenderable,
            a2: &info,
            a3: 0);
    v19 = ((int (__thiscall *)(IClientRenderable *, int))pRenderable->GetBody)(a1: pRenderable, a2: v18);
    v20 = (matrix3x4a_t *)((int (__thiscall *)(IVModelRender *, IClientRenderable *, int))*p_DrawModelShadowSetup)(
                            a1: modelrender,
                            a2: pRenderable,
                            a3: v19);
    if ( v20 != nullptr )
      modelrender->DrawModelShadow(this: modelrender, a2: pRenderable, a3: &info, a4: v20);
    v6 = 1;
    v16->ReleaseRenderData(this: v16);
    v16->EndRender(this: v16);
    v16->Release(this: v16);
    v5 = v23;
    goto LABEL_22;
  }
  if ( v10 )
  {
    render->DrawBrushModelShadow(this: render, a2: pRenderable);
    goto LABEL_21;
  }
LABEL_22:
  for ( i = pRenderable->FirstShadowChild(this: pRenderable); i != nullptr; i = i->NextShadowPeer(this: i) )
  {
    if ( CClientShadowMgr::DrawShadowHierarchy(this: v5, pRenderable: i, shadow, bChild: true) )
      v6 = 1;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x100B6F20
// Name: private: int CClientShadowMgr::BuildActiveShadowDepthList(class CViewSetup const __near &,int,unsigned short __near *,int __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CClientShadowMgr::BuildActiveShadowDepthList@<eax>(
        CClientShadowMgr *this@<ecx>,
        int a2@<ebp>,
        const CViewSetup *viewSetup,
        int nMaxDepthShadows,
        unsigned __int16 *pActiveDepthShadows,
        int *nNumHighRes)
{
  void *v6; // esp
  CClientShadowMgr *v7; // edi
  int m_Head; // eax
  int v9; // ecx
  int v10; // eax
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *v11; // edi
  bool v12; // zf
  int v13; // esi
  int v14; // esi
  int v15; // eax
  unsigned __int16 v16; // dx
  int v17; // edi
  int v18; // ecx
  unsigned __int16 *v19; // eax
  float v20; // xmm1_4
  unsigned __int16 v21; // dx
  float v22; // xmm0_4
  unsigned __int16 v23; // dx
  float v24; // xmm1_4
  unsigned __int16 v25; // dx
  unsigned __int16 v26; // dx
  unsigned __int16 v27; // ax
  float flZNear; // [esp+0h] [ebp-11C0h]
  float flZFar; // [esp+4h] [ebp-11BCh]
  float flFovX; // [esp+8h] [ebp-11B8h]
  float flAspectRatio; // [esp+Ch] [ebp-11B4h]
  _BYTE v33[4096]; // [esp+24h] [ebp-119Ch]
  Frustum_t v34; // [esp+1024h] [ebp-19Ch] BYREF
  Vector v35; // [esp+1170h] [ebp-50h] BYREF
  Vector v36; // [esp+117Ch] [ebp-44h] BYREF
  Vector v37; // [esp+1188h] [ebp-38h] BYREF
  int v38; // [esp+1194h] [ebp-2Ch]
  Vector *p_origin; // [esp+1198h] [ebp-28h]
  Vector v40; // [esp+119Ch] [ebp-24h] BYREF
  CClientShadowMgr *v41; // [esp+11A8h] [ebp-18h]
  int v42; // [esp+11ACh] [ebp-14h]
  int v43; // [esp+11B0h] [ebp-10h]
  int v44; // [esp+11B4h] [ebp-Ch]
  void *v45; // [esp+11B8h] [ebp-8h]
  void *retaddr; // [esp+11C0h] [ebp+0h]

  v44 = a2;
  v45 = retaddr;
  v6 = alloca(4504);
  v7 = this;
  v41 = this;
  *nNumHighRes = 0;
  Frustum_t::Frustum_t(this: &v34);
  flAspectRatio = viewSetup->m_flAspectRatio;
  flFovX = viewSetup->fov;
  flZFar = viewSetup->zFar;
  flZNear = viewSetup->zNear;
  p_origin = &viewSetup->origin;
  GeneratePerspectiveFrustum(
    a1: (int)v7,
    a2: (int)&viewSetup->angles,
    origin: &viewSetup->origin,
    angles: &viewSetup->angles,
    flZNear,
    flZFar,
    flFovX,
    flAspectRatio,
    frustum: &v34);
  AngleVectors(angles: &viewSetup->angles, forward: &v37);
  m_Head = v7->m_Shadows.m_Head;
  v9 = 0;
  v42 = 0;
  v43 = m_Head;
  if ( (_WORD)m_Head != 0xFFFF )
  {
    while ( v9 < nMaxDepthShadows || *nNumHighRes != v9 )
    {
      v10 = (unsigned __int16)m_Head;
      v11 = &v7->m_Shadows.m_Memory.m_pMemory[v10];
      v12 = (v11->m_Element.m_Flags & 0x20) == 0;
      v38 = v10 * 276;
      if ( !v12 && v11->m_Element.m_nSplitscreenOwner <= 0 )
      {
        v13 = ((int (__stdcall *)(_DWORD))shadowmgr->GetFlashlightState)(a1: v11->m_Element.m_ShadowHandle);
        if ( *(_BYTE *)(v13 + 112) != 0 )
        {
          if ( r_flashlightenableculling.m_pParent != nullptr
            && r_flashlightenableculling.m_pParent->m_Value.m_nValue != 0 )
          {
            CalculateAABBFromProjectionMatrix(worldToVolume: &v11->m_Element.m_WorldToShadow, pMins: &v35, pMaxs: &v36);
            if ( *(_BYTE *)(v13 + 44) == 0 && Frustum_t::CullBox(this: &v34, mins: &v35, maxs: &v36) )
              goto LABEL_13;
          }
          if ( v42 < nMaxDepthShadows )
          {
            if ( *(_BYTE *)(v13 + 148) != 0 )
              ++*nNumHighRes;
            v40.x = *(float *)v13 - p_origin->x;
            v40.y = *(float *)(v13 + 4) - p_origin->y;
            v40.z = *(float *)(v13 + 8) - p_origin->z;
            VectorNormalize(vec: &v40);
            v15 = v42;
            v16 = v43;
            *(float *)&v33[4 * v42] = (float)((float)(v40.x * v37.x) + (float)(v37.y * v40.y)) + (float)(v37.z * v40.z);
            pActiveDepthShadows[v15] = v16;
            v42 = v15 + 1;
          }
          else
          {
            if ( *(_BYTE *)(v13 + 148) == 0 )
            {
              if ( !s_bOverflowWarning )
              {
                _Warning(a1: "Too many depth textures rendered in a single view!\n");
                s_bOverflowWarning = true;
              }
LABEL_13:
              shadowmgr->SetFlashlightDepthTexture(
                this: shadowmgr,
                a2: v11->m_Element.m_ShadowHandle,
                a3: nullptr,
                a4: 0);
              goto LABEL_27;
            }
            v14 = v42 - 1;
            if ( v42 - 1 >= 0 )
            {
              while ( shadowmgr->GetFlashlightState(
                        this: shadowmgr,
                        a2: v41->m_Shadows.m_Memory.m_pMemory[pActiveDepthShadows[v14]].m_Element.m_ShadowHandle)->m_bShadowHighRes )
              {
                if ( --v14 < 0 )
                  goto LABEL_27;
              }
              pActiveDepthShadows[v14] = v43;
              ++*nNumHighRes;
            }
          }
        }
      }
LABEL_27:
      v9 = v42;
      v43 = *(unsigned __int16 *)((char *)&v41->m_Shadows.m_Memory.m_pMemory->m_Next + v38);
      if ( (_WORD)v43 == 0xFFFF )
        break;
      LOWORD(m_Head) = v43;
      v7 = v41;
    }
  }
  if ( v9 - 1 <= 0 )
    return v9;
  v17 = v9 - 1;
  v41 = (CClientShadowMgr *)(v9 - 1);
  v43 = v9 - 1;
  do
  {
    v18 = 0;
    if ( v17 >= 4 )
    {
      v19 = pActiveDepthShadows + 2;
      do
      {
        v20 = *(float *)&v33[4 * v18 + 4];
        if ( v20 > *(float *)&v33[4 * v18] )
        {
          v21 = *(v19 - 2);
          *(v19 - 2) = *(v19 - 1);
          *(v19 - 1) = v21;
        }
        v22 = *(float *)&v33[4 * v18 + 8];
        if ( v22 > v20 )
        {
          v23 = *(v19 - 1);
          *(v19 - 1) = *v19;
          *v19 = v23;
        }
        v24 = *(float *)&v33[4 * v18 + 12];
        if ( v24 > v22 )
        {
          v25 = *v19;
          *v19 = v19[1];
          v19[1] = v25;
        }
        if ( *(float *)&v33[4 * v18 + 16] > v24 )
        {
          v26 = v19[1];
          v19[1] = v19[2];
          v19[2] = v26;
        }
        v17 = (int)v41;
        v18 += 4;
        v19 += 4;
      }
      while ( v18 < (int)&v41[-1].m_downSampledDepth.m_pTexture + 1 );
    }
    for ( ; v18 < v17; ++v18 )
    {
      if ( *(float *)&v33[4 * v18 + 4] > *(float *)&v33[4 * v18] )
      {
        v27 = pActiveDepthShadows[v18];
        pActiveDepthShadows[v18] = pActiveDepthShadows[v18 + 1];
        pActiveDepthShadows[v18 + 1] = v27;
      }
    }
    --v17;
    v12 = v43-- == 1;
    v41 = (CClientShadowMgr *)v17;
  }
  while ( !v12 );
  return v42;
}

//------------------------------------------------------------------------------
// Address: 0x100B72F0
// Name: private: int CClientShadowMgr::BuildActiveFlashlightList(class CViewSetup const __near &,int,unsigned short __near *)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CClientShadowMgr::BuildActiveFlashlightList@<eax>(
        CClientShadowMgr *this@<ecx>,
        float a2@<ebp>,
        const CViewSetup *viewSetup,
        int nMaxFlashlights,
        unsigned __int16 *pActiveFlashlights)
{
  int m_Head; // esi
  int result; // eax
  unsigned int v7; // edi
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *v8; // eax
  float y; // eax
  _BYTE v10[12]; // [esp+24h] [ebp-16Ch] BYREF
  Frustum_t viewFrustum; // [esp+30h] [ebp-160h] BYREF
  Vector vecAbsMins; // [esp+170h] [ebp-20h] BYREF
  Vector vecAbsMaxs; // [esp+17Ch] [ebp-14h]
  void *v14; // [esp+188h] [ebp-8h]
  void *retaddr; // [esp+190h] [ebp+0h]

  vecAbsMaxs.z = a2;
  v14 = retaddr;
  m_Head = this->m_Shadows.m_Head;
  result = 0;
  LODWORD(vecAbsMaxs.x) = this;
  vecAbsMaxs.y = 0.0;
  if ( (_WORD)m_Head != 0xFFFF )
  {
    do
    {
      v7 = 276 * (unsigned __int16)m_Head;
      v8 = &this->m_Shadows.m_Memory.m_pMemory[v7 / 0x114];
      if ( (v8->m_Element.m_Flags & 5) != 0 && v8->m_Element.m_nSplitscreenOwner <= 0 )
      {
        CalculateAABBFromProjectionMatrix(
          worldToVolume: &v8->m_Element.m_WorldToShadow,
          pMins: (Vector *)&viewFrustum.planes[1].nZAbs.m128_i16[2],
          pMaxs: &vecAbsMins);
        Frustum_t::Frustum_t(this: (Frustum_t *)v10);
        GeneratePerspectiveFrustum(
          a1: v7,
          a2: m_Head,
          origin: &viewSetup->origin,
          angles: &viewSetup->angles,
          flZNear: viewSetup->zNear,
          flZFar: viewSetup->zFar,
          flFovX: viewSetup->fov,
          flAspectRatio: viewSetup->m_flAspectRatio,
          frustum: (Frustum_t *)v10);
        if ( !Frustum_t::CullBox(
                this: (Frustum_t *)v10,
                mins: (const Vector *)&viewFrustum.planes[1].nZAbs.m128_i16[2],
                maxs: &vecAbsMins) )
        {
          y = vecAbsMaxs.y;
          if ( SLODWORD(vecAbsMaxs.y) < nMaxFlashlights )
          {
            pActiveFlashlights[LODWORD(vecAbsMaxs.y)] = m_Head;
            LODWORD(vecAbsMaxs.y) = LODWORD(y) + 1;
          }
          else if ( !s_bOverflowWarning_0 )
          {
            _Warning(a1: "Too many flashlights rendered in a single view!\n");
            s_bOverflowWarning_0 = true;
          }
        }
      }
      this = (CClientShadowMgr *)LODWORD(vecAbsMaxs.x);
      m_Head = *(unsigned __int16 *)(*(_DWORD *)(LODWORD(vecAbsMaxs.x) + 44) + v7 + 274);
    }
    while ( (_WORD)m_Head != 0xFFFF );
    return LODWORD(vecAbsMaxs.y);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100B7430
// Name: public: virtual void CClientShadowMgr::DrawVolumetrics(class CViewSetup const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::DrawVolumetrics(CClientShadowMgr *this, const CViewSetup *viewSetup)
{
  IMatRenderContext *v2; // esi

  v2 = materials->GetRenderContext(this: materials);
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  shadowmgr->DrawVolumetrics(this: shadowmgr);
  if ( v2 != nullptr )
  {
    v2->EndRender(this: v2);
    v2->Release(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B7480
// Name: public: virtual void CClientShadowMgr::ComputeShadowDepthTextures(class CViewSetup const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::ComputeShadowDepthTextures(CClientShadowMgr *this, const CViewSetup *viewSetup)
{
  CClientShadowMgr *v2; // esi
  int v3; // edi
  IMatRenderContext *m_pObject; // ebx
  int active; // edi
  bool v6; // sf
  bool v7; // of
  int m_nValue; // eax
  int v9; // eax
  int v10; // eax
  CClientShadowMgr::ClientShadow_t *p_m_Element; // edi
  const FlashlightState_t *(__thiscall *GetFlashlightState)(IShadowMgr *, unsigned __int16); // eax
  float *v13; // ebx
  int v14; // esi
  int m_Size; // eax
  CTextureReference *m_pMemory; // edx
  CClientShadowMgr *v17; // esi
  float v18; // xmm0_4
  IMatRenderContext *v19; // esi
  int flDuration_4; // [esp+38h] [ebp-974h]
  int v21; // [esp+3Ch] [ebp-970h] BYREF
  unsigned __int16 pActiveDepthShadows[1024]; // [esp+48h] [ebp-964h] BYREF
  unsigned __int16 pActiveFlashlights[16]; // [esp+848h] [ebp-164h] BYREF
  CViewSetup shadowView; // [esp+868h] [ebp-144h] BYREF
  Vector vecExtentsMax; // [esp+95Ch] [ebp-50h] BYREF
  Vector vecExtentsMin; // [esp+968h] [ebp-44h] BYREF
  Vector origin; // [esp+974h] [ebp-38h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+980h] [ebp-2Ch]
  int nActiveDepthShadowCount; // [esp+984h] [ebp-28h]
  int iLowResStart; // [esp+988h] [ebp-24h]
  int i; // [esp+98Ch] [ebp-20h]
  CClientShadowMgr::ClientShadow_t *shadow; // [esp+990h] [ebp-1Ch]
  int v33; // [esp+994h] [ebp-18h]
  bool bDebugFrustumBBox; // [esp+99Bh] [ebp-11h]
  int iNumHighRes; // [esp+99Ch] [ebp-10h] BYREF
  bool bDebugFrustum; // [esp+9A3h] [ebp-9h]
  CTextureReference shadowDepthTexture; // [esp+9A4h] [ebp-8h] BYREF
  CClientShadowMgr *v38; // [esp+9A8h] [ebp-4h]
  int savedregs; // [esp+9ACh] [ebp+0h] BYREF
  bool bPrintFlashlightInfo_3; // [esp+9B7h] [ebp+Bh]

  v2 = this;
  v38 = this;
  if ( r_flashlightdepthtexture.m_pParent != nullptr && r_flashlightdepthtexture.m_pParent->m_Value.m_nValue != 0 )
  {
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "CClientShadowMgr::ComputeShadowDepthTextures",
      a3: 0,
      a4: "Flashlight Shadows",
      a5: false,
      a6: 4);
    m_pObject = materials->GetRenderContext(this: materials);
    pRenderContext.m_pObject = m_pObject;
    if ( m_pObject != nullptr )
      m_pObject->BeginRender(this: m_pObject);
    iNumHighRes = 0;
    active = CClientShadowMgr::BuildActiveShadowDepthList(
               this: v2,
               a2: (int)&savedregs,
               viewSetup,
               nMaxDepthShadows: 1024,
               pActiveDepthShadows,
               nNumHighRes: &iNumHighRes);
    v7 = __OFSUB__(iNumHighRes, v2->m_nMaxDepthTextureShadows);
    v6 = iNumHighRes - v2->m_nMaxDepthTextureShadows < 0;
    nActiveDepthShadowCount = active;
    iLowResStart = v6 == v7 ? 0 : iNumHighRes;
    if ( r_flashlightdrawfrustum.m_pParent != nullptr )
      m_nValue = r_flashlightdrawfrustum.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    bDebugFrustum = m_nValue != 0;
    if ( r_flashlightdrawfrustumbbox.m_pParent != nullptr )
      v9 = r_flashlightdrawfrustumbbox.m_pParent->m_Value.m_nValue;
    else
      v9 = 0;
    bDebugFrustumBBox = v9 != 0;
    if ( r_flashlight_info.m_pParent != nullptr )
      v10 = r_flashlight_info.m_pParent->m_Value.m_nValue;
    else
      v10 = 0;
    bPrintFlashlightInfo_3 = v10 != 0;
    if ( v10 != 0 )
      engine->Con_NPrintf(this: engine, a2: 0, a3: "%d active flashlights", active);
    if ( active > 0 )
    {
      v33 = 1;
      iNumHighRes = (int)pActiveDepthShadows;
      for ( i = active; i != 0; --i )
      {
        p_m_Element = &v2->m_Shadows.m_Memory.m_pMemory[*(unsigned __int16 *)iNumHighRes].m_Element;
        GetFlashlightState = shadowmgr->GetFlashlightState;
        flDuration_4 = p_m_Element->m_ShadowHandle;
        shadow = p_m_Element;
        v13 = (float *)((int (__stdcall *)(int))GetFlashlightState)(a1: flDuration_4);
        CTextureReference::CTextureReference(this: &shadowDepthTexture);
        v14 = *((_BYTE *)v13 + 148) != 0 ? 0 : iLowResStart;
        m_Size = v38->m_DepthTextureCache.m_Size;
        if ( v14 >= m_Size )
        {
LABEL_25:
          if ( bitchCount < 10 )
          {
            _Warning(a1: "Too many shadow maps this frame!\n");
            ++bitchCount;
          }
          shadowmgr->SetFlashlightDepthTexture(this: shadowmgr, a2: p_m_Element->m_ShadowHandle, a3: nullptr, a4: 0);
          if ( bPrintFlashlightInfo_3 )
            engine->Con_NPrintf(this: engine, a2: v33, a3: "[ERROR - no shadow] %f %f %f ", *v13, v13[1], v13[2]);
        }
        else
        {
          while ( 1 )
          {
            if ( !v38->m_DepthTextureCacheLocks.m_Memory.m_pMemory[v14] )
            {
              m_pMemory = v38->m_DepthTextureCache.m_Memory.m_pMemory;
              if ( m_pMemory[v14].m_pTexture != nullptr )
                break;
            }
            if ( ++v14 >= m_Size )
              goto LABEL_25;
          }
          CTextureReference::operator=(this: &shadowDepthTexture, ref: &m_pMemory[v14]);
          v38->m_DepthTextureCacheLocks.m_Memory.m_pMemory[v14] = true;
          if ( bPrintFlashlightInfo_3 )
            engine->Con_NPrintf(this: engine, a2: v33, a3: "[shadow] %f %f %f ", *v13, v13[1], v13[2]);
          shadowView.m_flNearBlurDepth = 20.0;
          shadowView.m_flNearFocusDepth = 100.0;
          shadowView.m_flFarFocusDepth = 250.0;
          shadowView.m_flFarBlurDepth = 1000.0;
          shadowView.m_flNearBlurRadius = 10.0;
          shadowView.m_flFarBlurRadius = 5.0;
          shadowView.m_nDoFQuality = 0;
          shadowView.m_bCustomViewMatrix = false;
          shadowView.y = 0;
          shadowView.x = 0;
          *((_BYTE *)&shadowView + 240) = 4;
          shadowView.m_nMotionBlurMode = MOTION_BLUR_GAME;
          shadowView.m_flAspectRatio = 1.0;
          shadowView.width = shadowDepthTexture.m_pTexture->GetActualWidth(this: shadowDepthTexture.m_pTexture);
          shadowView.height = shadowDepthTexture.m_pTexture->GetActualHeight(this: shadowDepthTexture.m_pTexture);
          if ( *((_BYTE *)v13 + 44) != 0 )
          {
            shadowView.m_bOrtho = true;
            shadowView.m_OrthoLeft = v13[12];
            shadowView.m_OrthoTop = v13[14];
            shadowView.m_OrthoRight = v13[13];
            shadowView.m_OrthoBottom = v13[15];
          }
          else
          {
            shadowView.m_bOrtho = false;
          }
          *((_BYTE *)&shadowView + 240) &= ~4u;
          shadowView.m_nMotionBlurMode = MOTION_BLUR_DISABLE;
          shadowView.fovViewmodel = v13[9];
          shadowView.fov = shadowView.fovViewmodel;
          shadowView.origin = *(Vector *)v13;
          QuaternionAngles(q: (const Quaternion *)(v13 + 3), angles: &shadowView.angles);
          shadowView.zNearViewmodel = v13[7];
          shadowView.zNear = shadowView.zNearViewmodel;
          shadowView.zFarViewmodel = v13[8];
          shadowView.zFar = shadowView.zFarViewmodel;
          if ( bDebugFrustum || *((_BYTE *)v13 + 113) != 0 )
          {
            if ( *((_BYTE *)v13 + 160) != 0 )
            {
              CClientShadowMgr::DrawUberlightRig(
                this: v38,
                a2: (int)v13,
                a3: (int)&v21,
                a4: (int)(v13 + 63),
                vOrigin: &shadowView.origin,
                matWorldToFlashlight: &shadow->m_WorldToShadow,
                state: *(FlashlightState_t *)v13);
              p_m_Element = shadow;
            }
            v17 = v38;
            CClientShadowMgr::DrawFrustum(
              this: v38,
              vOrigin: &shadowView.origin,
              matWorldToFlashlight: &p_m_Element->m_WorldToShadow);
          }
          else
          {
            v17 = v38;
          }
          if ( bDebugFrustumBBox )
          {
            v17->GetFrustumExtents(this: v17, a2: *(_WORD *)iNumHighRes, a3: &vecExtentsMin, a4: &vecExtentsMax);
            v18 = vecExtentsMax.z - 1.0;
            if ( C_EnvProjectedTexture::m_flVisibleBBoxMinHeight <= (float)(vecExtentsMax.z - 1.0) )
              v18 = C_EnvProjectedTexture::m_flVisibleBBoxMinHeight;
            if ( vecExtentsMin.z <= v18 )
              vecExtentsMin.z = v18;
            memset((void *)&origin, 0, sizeof(origin));
            NDebugOverlay::Box(
              &origin,
              mins: &vecExtentsMin,
              maxs: &vecExtentsMax,
              r: 0,
              g: 0,
              b: 255,
              a: 100,
              flDuration: 0.0);
          }
          v19 = materials->GetRenderContext(this: materials);
          if ( v19 != nullptr )
            v19->BeginRender(this: v19);
          ((void (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD))v19->SetShadowDepthBiasFactors)(
            a1: v19,
            a2: *((_DWORD *)v13 + 31),
            a3: *((_DWORD *)v13 + 32));
          view->UpdateShadowDepthTexture(
            this: view,
            a2: v38->m_DummyColorTexture.m_pTexture,
            a3: shadowDepthTexture.m_pTexture,
            a4: &shadowView);
          ((void (__stdcall *)(_DWORD, ITexture *, _DWORD))shadowmgr->SetFlashlightDepthTexture)(
            a1: p_m_Element->m_ShadowHandle,
            a2: shadowDepthTexture.m_pTexture,
            a3: 0);
          v19->EndRender(this: v19);
          v19->Release(this: v19);
        }
        CTextureReference::~CTextureReference(this: &shadowDepthTexture);
        iNumHighRes += 2;
        v2 = v38;
        ++v33;
      }
      active = nActiveDepthShadowCount;
      m_pObject = pRenderContext.m_pObject;
    }
    shadowmgr->PushSinglePassFlashlightStateEnabled(this: shadowmgr, a2: false);
    if ( active <= 0 )
      ((void (__stdcall *)(int))shadowmgr->SetSinglePassFlashlightRenderState)(a1: 0xFFFF);
    else
      ((void (__stdcall *)(_DWORD))shadowmgr->SetSinglePassFlashlightRenderState)(a1: v2->m_Shadows.m_Memory.m_pMemory[pActiveDepthShadows[0]].m_Element.m_ShadowHandle);
    if ( m_pObject != nullptr )
    {
      m_pObject->EndRender(this: m_pObject);
      m_pObject->Release(this: m_pObject);
    }
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    v3 = CClientShadowMgr::BuildActiveFlashlightList(
           this,
           a2: COERCE_FLOAT(&savedregs),
           viewSetup,
           nMaxFlashlights: 16,
           pActiveFlashlights);
    shadowmgr->PushSinglePassFlashlightStateEnabled(this: shadowmgr, a2: false);
    if ( v3 <= 0 )
      shadowmgr->SetSinglePassFlashlightRenderState(this: shadowmgr, a2: 0xFFFFu);
    else
      ((void (__stdcall *)(_DWORD))shadowmgr->SetSinglePassFlashlightRenderState)(a1: v2->m_Shadows.m_Memory.m_pMemory[pActiveFlashlights[0]].m_Element.m_ShadowHandle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B7AF0
// Name: public: virtual void CClientShadowMgr::SetShadowFromWorldLightsEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::SetShadowFromWorldLightsEnabled(CClientShadowMgr *this, bool bEnable)
{
  char v2; // dl
  char v3; // al

  v2 = this->m_bShadowFromWorldLights && !this->m_bSuppressShadowFromWorldLights;
  this->m_bShadowFromWorldLights = bEnable;
  v3 = bEnable && !this->m_bSuppressShadowFromWorldLights;
  if ( v2 != v3 )
    CClientShadowMgr::UpdateAllShadows(this);
}

//------------------------------------------------------------------------------
// Address: 0x100B7B40
// Name: public: virtual void CClientShadowMgr::DrawDeferredShadows(class CViewSetup const __near &,int,struct WorldListLeafData_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::DrawDeferredShadows(
        CClientShadowMgr *this,
        const CViewSetup *view,
        const CViewSetup *leafCount,
        WorldListLeafData_t *pLeafList)
{
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CClientShadowMgr::DrawDeferredShadows",
    a3: 0,
    a4: "Shadow_Rendering",
    a5: false,
    a6: 4);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x100B7B70
// Name: DeferredShadowToggleCallback
// Source: json
//------------------------------------------------------------------------------
void __cdecl DeferredShadowToggleCallback()
{
  DevMsg(a1: "Deferred shadow rendering only supported on the 360.\n");
}

//------------------------------------------------------------------------------
// Address: 0x100B7B80
// Name: public: void CUtlMultiList<struct CTextureAllocator::FragmentInfo_t,unsigned short>::Unlink(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::Unlink(
        CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 elem)
{
  int v4; // eax
  CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::ListElem_t *v5; // eax
  int m_Previous; // esi
  unsigned __int16 m_Next; // bx
  int v8; // esi
  unsigned __int16 v9; // bx
  unsigned __int16 *p_m_Count; // eax
  unsigned __int16 *m_pElementList; // ecx
  int elema; // [esp+Ch] [ebp+Ch]

  v4 = elem;
  elema = v4;
  if ( v4 < this->m_MaxElementIndex )
  {
    v5 = &this->m_Memory.m_pMemory[v4];
    if ( v5->m_Previous != elem )
    {
      m_Previous = v5->m_Previous;
      m_Next = v5->m_Next;
      if ( (_WORD)m_Previous == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      v8 = v5->m_Next;
      v9 = v5->m_Previous;
      if ( (_WORD)v8 == 0xFFFF )
        this->m_List.m_Memory.m_pMemory[list].m_Element.m_Tail = v9;
      else
        this->m_Memory.m_pMemory[v8].m_Previous = v9;
      v5->m_Next = elem;
      v5->m_Previous = elem;
      p_m_Count = &this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
      --*p_m_Count;
      m_pElementList = this->m_pElementList;
      if ( m_pElementList != nullptr )
        m_pElementList[elema] = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B8210
// Name: public: void CUtlMultiList<struct CTextureAllocator::FragmentInfo_t,unsigned short>::LinkBefore(unsigned short,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::LinkBefore(
        CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::ListElem_t *v5; // eax
  int v6; // ecx
  CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::ListElem_t *v7; // ecx
  int m_Previous; // eax
  unsigned __int16 *m_pElementList; // esi

  CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::Unlink(this, list, elem);
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    v6 = list;
    v5->m_Previous = this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail;
    this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Tail = elem;
  }
  else
  {
    v7 = &this->m_Memory.m_pMemory[before];
    v5->m_Previous = v7->m_Previous;
    v7->m_Previous = elem;
  }
  m_Previous = v5->m_Previous;
  if ( (_WORD)m_Previous == 0xFFFF )
    this->m_List.m_Memory.m_pMemory[list].m_Element.m_Head = elem;
  else
    this->m_Memory.m_pMemory[m_Previous].m_Next = elem;
  ++this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
  m_pElementList = this->m_pElementList;
  if ( m_pElementList != nullptr )
    m_pElementList[elem] = list;
}

//------------------------------------------------------------------------------
// Address: 0x100B82D0
// Name: public: void CUtlMultiList<struct CTextureAllocator::FragmentInfo_t,unsigned short>::LinkAfter(unsigned short,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::LinkAfter(
        CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short> *this,
        unsigned __int16 list,
        unsigned __int16 after,
        unsigned __int16 elem)
{
  CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::ListElem_t *v5; // eax
  int v6; // ecx
  CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::ListElem_t *v7; // ecx
  int m_Next; // eax
  unsigned __int16 *m_pElementList; // esi

  CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::Unlink(this, list, elem);
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Previous = after;
  if ( after == 0xFFFF )
  {
    v6 = list;
    v5->m_Next = this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Head;
    this->m_List.m_Memory.m_pMemory[v6].m_Element.m_Head = elem;
  }
  else
  {
    v7 = &this->m_Memory.m_pMemory[after];
    v5->m_Next = v7->m_Next;
    v7->m_Next = elem;
  }
  m_Next = v5->m_Next;
  if ( (_WORD)m_Next == 0xFFFF )
    this->m_List.m_Memory.m_pMemory[list].m_Element.m_Tail = elem;
  else
    this->m_Memory.m_pMemory[m_Next].m_Previous = elem;
  ++this->m_List.m_Memory.m_pMemory[list].m_Element.m_Count;
  m_pElementList = this->m_pElementList;
  if ( m_pElementList != nullptr )
    m_pElementList[elem] = list;
}

//------------------------------------------------------------------------------
// Address: 0x100B8FE0
// Name: public: CVisibleShadowList::CVisibleShadowList(void)
// Source: json
//------------------------------------------------------------------------------
CVisibleShadowList *__thiscall CVisibleShadowList::CVisibleShadowList(CVisibleShadowList *this)
{
  VisibleShadowInfo_t *v2; // eax
  int *v3; // eax

  this->__vftable = (CVisibleShadowList_vtbl *)&CVisibleShadowList::`vftable';
  this->m_ShadowsInView.m_Memory.m_pMemory = nullptr;
  this->m_ShadowsInView.m_Memory.m_nAllocationCount = 64;
  this->m_ShadowsInView.m_Memory.m_nGrowSize = 0;
  v2 = (VisibleShadowInfo_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 1280);
  this->m_ShadowsInView.m_Memory.m_pMemory = v2;
  this->m_ShadowsInView.m_pElements = v2;
  this->m_ShadowsInView.m_Size = 0;
  this->m_BlobbyShadowsInView.m_Memory.m_pMemory = nullptr;
  this->m_BlobbyShadowsInView.m_Memory.m_nAllocationCount = 0;
  this->m_BlobbyShadowsInView.m_Memory.m_nGrowSize = 0;
  this->m_BlobbyShadowsInView.m_Size = 0;
  this->m_BlobbyShadowsInView.m_pElements = nullptr;
  this->m_PriorityIndex.m_Memory.m_pMemory = nullptr;
  this->m_PriorityIndex.m_Memory.m_nAllocationCount = 64;
  this->m_PriorityIndex.m_Memory.m_nGrowSize = 0;
  v3 = (int *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 256);
  this->m_PriorityIndex.m_Size = 0;
  this->m_PriorityIndex.m_Memory.m_pMemory = v3;
  this->m_PriorityIndex.m_pElements = v3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100B9060
// Name: r_shadowdir
// Source: json
//------------------------------------------------------------------------------
void __cdecl r_shadowdir(const CCommand *args)
{
  Vector *p_m_SimpleShadowDir; // eax
  const char *v2; // eax
  const char *v3; // esi
  float dir; // [esp+1Ch] [ebp-Ch]
  float dir_4; // [esp+20h] [ebp-8h]

  if ( args->m_nArgc == 1 )
  {
    if ( (_S6_27 & 1) == 0 )
    {
      _S6_27 |= 1u;
      s_vecDown.x = 0.0;
      s_vecDown.y = 0.0;
      s_vecDown.z = -1.0;
    }
    p_m_SimpleShadowDir = &s_vecDown;
    if ( s_ClientShadowMgr.m_RenderToTextureActive )
      p_m_SimpleShadowDir = &s_ClientShadowMgr.m_SimpleShadowDir;
    _Msg(a1: "%.2f %.2f %.2f\n", p_m_SimpleShadowDir->x, p_m_SimpleShadowDir->y, p_m_SimpleShadowDir->z);
  }
  else if ( args->m_nArgc == 4 )
  {
    dir = atof(nptr: args->m_ppArgv[1]);
    v2 = prType;
    if ( args->m_nArgc > 2 )
      v2 = args->m_ppArgv[2];
    dir_4 = atof(nptr: v2);
    if ( args->m_nArgc > 3 )
      v3 = args->m_ppArgv[3];
    else
      v3 = prType;
    s_ClientShadowMgr.m_SimpleShadowDir.z = atof(nptr: v3);
    s_ClientShadowMgr.m_SimpleShadowDir.x = dir;
    s_ClientShadowMgr.m_SimpleShadowDir.y = dir_4;
    VectorNormalize(vec: &s_ClientShadowMgr.m_SimpleShadowDir);
    if ( s_ClientShadowMgr.m_RenderToTextureActive )
      CClientShadowMgr::UpdateAllShadows(this: &s_ClientShadowMgr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B91B0
// Name: r_shadowangles
// Source: json
//------------------------------------------------------------------------------
void __cdecl r_shadowangles(const CCommand *args)
{
  Vector *p_m_SimpleShadowDir; // eax
  __int64 v2; // xmm0_8
  float z; // eax
  const char *v4; // eax
  const char *v5; // esi
  Vector forward; // [esp+1Ch] [ebp-30h] BYREF
  Vector dir; // [esp+28h] [ebp-24h] BYREF
  QAngle angles; // [esp+34h] [ebp-18h] BYREF
  QAngle v9; // [esp+40h] [ebp-Ch] BYREF

  if ( args->m_nArgc == 1 )
  {
    if ( (_S6_27 & 1) == 0 )
    {
      _S6_27 |= 1u;
      s_vecDown.x = 0.0;
      s_vecDown.y = 0.0;
      s_vecDown.z = -1.0;
    }
    p_m_SimpleShadowDir = &s_vecDown;
    if ( s_ClientShadowMgr.m_RenderToTextureActive )
      p_m_SimpleShadowDir = &s_ClientShadowMgr.m_SimpleShadowDir;
    v2 = *(_QWORD *)&p_m_SimpleShadowDir->x;
    z = p_m_SimpleShadowDir->z;
    *(_QWORD *)&forward.x = v2;
    forward.z = z;
    VectorAngles(&forward, angles: &v9);
    _Msg(a1: "%.2f %.2f %.2f\n", v9.x, v9.y, v9.z);
  }
  else if ( args->m_nArgc == 4 )
  {
    angles.x = atof(nptr: args->m_ppArgv[1]);
    v4 = prType;
    if ( args->m_nArgc > 2 )
      v4 = args->m_ppArgv[2];
    angles.y = atof(nptr: v4);
    if ( args->m_nArgc > 3 )
      v5 = args->m_ppArgv[3];
    else
      v5 = prType;
    angles.z = atof(nptr: v5);
    AngleVectors(&angles, forward: &dir);
    s_ClientShadowMgr.m_SimpleShadowDir = dir;
    VectorNormalize(vec: &s_ClientShadowMgr.m_SimpleShadowDir);
    if ( s_ClientShadowMgr.m_RenderToTextureActive )
      CClientShadowMgr::UpdateAllShadows(this: &s_ClientShadowMgr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9320
// Name: r_shadowdist
// Source: json
//------------------------------------------------------------------------------
void __cdecl r_shadowdist(const CCommand *args)
{
  if ( args->m_nArgc == 1 )
  {
    _Msg(a1: "Shadow distance %.2f\n", s_ClientShadowMgr.m_flShadowCastDist);
  }
  else if ( args->m_nArgc == 2 )
  {
    s_ClientShadowMgr.m_flShadowCastDist = atof(nptr: args->m_ppArgv[1]);
    CClientShadowMgr::UpdateAllShadows(this: &s_ClientShadowMgr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9380
// Name: void OnShadowFromWorldLights(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OnShadowFromWorldLights()
{
  int m_nValue; // eax
  char v1; // dl
  bool v2; // al
  char v3; // al

  if ( r_shadowfromworldlights.m_pParent != nullptr )
    m_nValue = r_shadowfromworldlights.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v1 = s_ClientShadowMgr.m_bShadowFromWorldLights && !s_ClientShadowMgr.m_bSuppressShadowFromWorldLights;
  v2 = m_nValue == 0;
  s_ClientShadowMgr.m_bSuppressShadowFromWorldLights = v2;
  v3 = s_ClientShadowMgr.m_bShadowFromWorldLights && !v2;
  if ( v1 != v3 )
    CClientShadowMgr::UpdateAllShadows(this: &s_ClientShadowMgr);
}

//------------------------------------------------------------------------------
// Address: 0x100B93E0
// Name: ShadowRestoreFunc
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShadowRestoreFunc()
{
  CClientShadowMgr::RestoreRenderState(this: &s_ClientShadowMgr);
}

//------------------------------------------------------------------------------
// Address: 0x100B93F0
// Name: private: virtual void CClientShadowMgr::ShutdownRenderTargets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::ShutdownRenderTargets(CClientShadowMgr *this)
{
  if ( materials != nullptr )
    materials->RemoveRestoreFunc(this: materials, a2: (void (__cdecl *)(int))ShadowRestoreFunc);
}

//------------------------------------------------------------------------------
// Address: 0x100B9410
// Name: private: void CClientShadowMgr::ShutdownDepthTextureShadows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::ShutdownDepthTextureShadows(CClientShadowMgr *this)
{
  int v2; // edi

  if ( this->m_bDepthTexturesAllocated )
  {
    CTextureReference::Shutdown(this: &this->m_DummyColorTexture, bDeleteIfUnReferenced: false);
    for ( ; this->m_DepthTextureCache.m_Size != 0; --this->m_DepthTextureCache.m_Size )
    {
      CTextureReference::Shutdown(
        this: &this->m_DepthTextureCache.m_Memory.m_pMemory[this->m_DepthTextureCache.m_Size - 1],
        bDeleteIfUnReferenced: false);
      if ( this->m_DepthTextureCacheLocks.m_Size - this->m_DepthTextureCache.m_Size > 0 )
        _V_memmove(
          dest: &this->m_DepthTextureCacheLocks.m_Memory.m_pMemory[this->m_DepthTextureCache.m_Size - 1],
          src: &this->m_DepthTextureCacheLocks.m_Memory.m_pMemory[this->m_DepthTextureCache.m_Size],
          count: this->m_DepthTextureCacheLocks.m_Size - this->m_DepthTextureCache.m_Size);
      --this->m_DepthTextureCacheLocks.m_Size;
      v2 = this->m_DepthTextureCache.m_Size - 1;
      CTextureReference::~CTextureReference(this: &this->m_DepthTextureCache.m_Memory.m_pMemory[v2]);
      if ( this->m_DepthTextureCache.m_Size - v2 - 1 > 0 )
        _V_memmove(
          dest: &this->m_DepthTextureCache.m_Memory.m_pMemory[v2],
          src: &this->m_DepthTextureCache.m_Memory.m_pMemory[v2 + 1],
          count: 4 * (this->m_DepthTextureCache.m_Size - v2 - 1));
    }
    this->m_bDepthTexturesAllocated = false;
  }
  this->m_bDepthTextureActive = false;
}

//------------------------------------------------------------------------------
// Address: 0x100B94F0
// Name: public: CUtlMultiList<struct CTextureAllocator::FragmentInfo_t,unsigned short>::~CUtlMultiList<struct CTextureAllocator::FragmentInfo_t,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::~CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>(
        CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short> *this)
{
  CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::RemoveAll(this);
  if ( this->m_pElementList != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pElementList);
  CUtlLinkedList<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *)&this->m_List);
  if ( this->m_List.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_List.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_List.m_Memory.m_pMemory);
      this->m_List.m_Memory.m_pMemory = nullptr;
    }
    this->m_List.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9570
// Name: public: void CUtlMultiList<struct CTextureAllocator::FragmentInfo_t,unsigned short>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::Purge(
        CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short> *this)
{
  UtlLinkedListElem_t<CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::List_t,unsigned short> *m_pMemory; // ecx
  UtlLinkedListElem_t<CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::List_t,unsigned short> *v3; // ecx
  CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::ListElem_t *v4; // ecx

  CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::RemoveAll(this);
  CUtlLinkedList<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *)&this->m_List);
  if ( this->m_List.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_List.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_List.m_Memory.m_pMemory);
      this->m_List.m_Memory.m_pMemory = nullptr;
    }
    this->m_List.m_Memory.m_nAllocationCount = 0;
  }
  this->m_List.m_FirstFree = -1;
  m_pMemory = this->m_List.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_List.m_NumAlloced = -65536;
  this->m_List.m_pElements = m_pMemory;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *)&this->m_List);
  if ( this->m_List.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_List.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_List.m_Memory.m_pMemory);
      this->m_List.m_Memory.m_pMemory = nullptr;
    }
    this->m_List.m_Memory.m_nAllocationCount = 0;
  }
  this->m_List.m_FirstFree = -1;
  v3 = this->m_List.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_List.m_NumAlloced = -65536;
  this->m_List.m_pElements = v3;
  v4 = this->m_Memory.m_pMemory;
  this->m_MaxElementIndex = 0;
  *(_DWORD *)&this->m_FirstFree = 0xFFFF;
  this->m_pElements = v4;
}

//------------------------------------------------------------------------------
// Address: 0x100B9B10
// Name: public: void CTextureAllocator::DeallocateAllTextures(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureAllocator::DeallocateAllTextures(CTextureAllocator *this)
{
  CUtlLinkedList<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *)&this->m_Textures);
  if ( this->m_Textures.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Textures.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Textures.m_Memory.m_pMemory);
      this->m_Textures.m_Memory.m_pMemory = nullptr;
    }
    this->m_Textures.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Textures.m_FirstFree = -1;
  this->m_Textures.m_pElements = this->m_Textures.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_Textures.m_NumAlloced = -65536;
  CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::Purge(this: &this->m_Fragments);
  *(_DWORD *)&this->m_Cache[0].m_List = -1;
  *(_DWORD *)&this->m_Cache[2].m_List = -1;
  *(_DWORD *)&this->m_Cache[4].m_List = -1;
  *(_DWORD *)&this->m_Cache[6].m_List = -1;
  this->m_Cache[8].m_List = -1;
}

//------------------------------------------------------------------------------
// Address: 0x100B9B90
// Name: private: void CTextureAllocator::AddBlockToLRU(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureAllocator::AddBlockToLRU(CTextureAllocator *this, int block)
{
  int i; // edi
  unsigned __int16 v4; // cx
  int v5; // eax
  int power; // [esp+8h] [ebp-8h]

  power = this->m_Blocks[block].m_FragmentPower;
  for ( i = 256 / (1 << power) * (256 / (1 << power)) - 1; i >= 0; --i )
  {
    v4 = CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::Alloc(this: &this->m_Fragments);
    v5 = v4;
    this->m_Fragments.m_Memory.m_pMemory[v5].m_Element.m_Block = block;
    this->m_Fragments.m_Memory.m_pMemory[v5].m_Element.m_Index = i;
    this->m_Fragments.m_Memory.m_pMemory[v5].m_Element.m_Texture = -1;
    this->m_Fragments.m_Memory.m_pMemory[v5].m_Element.m_FrameUsed = -1;
    CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::LinkAfter(
      this: &this->m_Fragments,
      list: this->m_Cache[power].m_List,
      after: 0xFFFFu,
      elem: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9C20
// Name: private: void CTextureAllocator::MarkUsed(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureAllocator::MarkUsed(CTextureAllocator *this, unsigned __int16 fragment)
{
  CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::LinkBefore(
    this: &this->m_Fragments,
    list: this->m_Cache[this->m_Blocks[this->m_Fragments.m_Memory.m_pMemory[fragment].m_Element.m_Block].m_FragmentPower].m_List,
    before: 0xFFFFu,
    elem: fragment);
  this->m_Fragments.m_Memory.m_pMemory[fragment].m_Element.m_FrameUsed = this->m_CurrentFrame;
}

//------------------------------------------------------------------------------
// Address: 0x100B9C70
// Name: public: bool CTextureAllocator::UseTexture(unsigned short,bool,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTextureAllocator::UseTexture(
        CTextureAllocator *this,
        unsigned __int16 h,
        bool bWillRedraw,
        float flArea)
{
  UtlLinkedListElem_t<CTextureAllocator::TextureInfo_t,unsigned short> *v5; // edx
  int m_Power; // ecx
  int v7; // eax
  int m_Fragment; // eax
  int m_FragmentPower; // ebx
  bool v10; // dl
  int v11; // ebx
  unsigned __int16 m_Head; // ax
  int v14; // edx
  CTextureAllocator::Cache_t *i; // ecx
  CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::ListElem_t *v16; // ecx
  int m_Texture; // edx
  int v18; // edi
  int v19; // ecx
  CTextureAllocator::TextureInfo_t *info; // [esp+0h] [ebp-8h]
  int nCurrentPower; // [esp+4h] [ebp-4h]
  unsigned __int16 currentFragment; // [esp+18h] [ebp+10h]
  CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::ListElem_t *currentFragmenta; // [esp+18h] [ebp+10h]

  v5 = &this->m_Textures.m_Memory.m_pMemory[h];
  m_Power = 4;
  info = &v5->m_Element;
  v7 = 16;
  if ( flArea > 256.0 )
  {
    while ( m_Power < v5->m_Element.m_Power )
    {
      v7 *= 2;
      ++m_Power;
      if ( flArea <= (float)(v7 * v7) )
        goto LABEL_6;
    }
    m_Power = v5->m_Element.m_Power;
  }
LABEL_6:
  m_Fragment = v5->m_Element.m_Fragment;
  nCurrentPower = -1;
  currentFragment = v5->m_Element.m_Fragment;
  if ( v5->m_Element.m_Fragment != 0xFFFF )
  {
    m_FragmentPower = this->m_Blocks[this->m_Fragments.m_Memory.m_pMemory[m_Fragment].m_Element.m_Block].m_FragmentPower;
    nCurrentPower = m_FragmentPower;
    v10 = !bWillRedraw && m_Power < 8 && m_Power - m_FragmentPower <= 1;
    if ( m_FragmentPower == m_Power || v10 )
    {
      v11 = m_Fragment;
      CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::LinkBefore(
        this: &this->m_Fragments,
        list: this->m_Cache[this->m_Blocks[this->m_Fragments.m_Memory.m_pMemory[m_Fragment].m_Element.m_Block].m_FragmentPower].m_List,
        before: 0xFFFFu,
        elem: currentFragment);
      this->m_Fragments.m_Memory.m_pMemory[v11].m_Element.m_FrameUsed = this->m_CurrentFrame;
      return 0;
    }
  }
  m_Head = -1;
  v14 = m_Power;
  for ( i = &this->m_Cache[m_Power]; v14 >= 0; --i )
  {
    m_Head = this->m_Fragments.m_List.m_Memory.m_pMemory[i->m_List].m_Element.m_Head;
    if ( m_Head != 0xFFFF && this->m_Fragments.m_Memory.m_pMemory[m_Head].m_Element.m_FrameUsed != this->m_CurrentFrame )
      break;
    --v14;
  }
  if ( currentFragment != 0xFFFF )
  {
    if ( v14 <= nCurrentPower )
    {
      CTextureAllocator::MarkUsed(this, fragment: currentFragment);
      return 0;
    }
    v16 = &this->m_Fragments.m_Memory.m_pMemory[currentFragment];
    m_Texture = v16->m_Element.m_Texture;
    if ( (_WORD)m_Texture != 0xFFFF )
    {
      this->m_Textures.m_Memory.m_pMemory[m_Texture].m_Element.m_Fragment = -1;
      v16->m_Element.m_Texture = -1;
    }
  }
  if ( m_Head == 0xFFFF )
    return 0;
  v18 = m_Head;
  currentFragmenta = &this->m_Fragments.m_Memory.m_pMemory[v18];
  v19 = currentFragmenta->m_Element.m_Texture;
  if ( (_WORD)v19 != 0xFFFF )
  {
    this->m_Textures.m_Memory.m_pMemory[v19].m_Element.m_Fragment = -1;
    currentFragmenta->m_Element.m_Texture = -1;
  }
  info->m_Fragment = m_Head;
  this->m_Fragments.m_Memory.m_pMemory[v18].m_Element.m_Texture = h;
  CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::LinkBefore(
    this: &this->m_Fragments,
    list: this->m_Cache[this->m_Blocks[this->m_Fragments.m_Memory.m_pMemory[m_Head].m_Element.m_Block].m_FragmentPower].m_List,
    before: 0xFFFFu,
    elem: m_Head);
  this->m_Fragments.m_Memory.m_pMemory[v18].m_Element.m_FrameUsed = this->m_CurrentFrame;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B9E70
// Name: private: virtual void CVisibleShadowList::EnumShadow(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisibleShadowList::EnumShadow(CVisibleShadowList *this, float clientShadowHandle)
{
  float v2; // ebx
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *v3; // esi
  ShadowType_t ActualShadowCastType; // eax
  IClientRenderable *ClientRenderableFromHandle; // edi
  CVisibleShadowList *v6; // edi
  int v7; // edi
  CVisibleShadowList *v8; // ecx
  CVisibleShadowList *v9; // esi
  int v10; // eax
  float r; // [esp+8h] [ebp-3Ch]
  Vector vecAbsMins; // [esp+18h] [ebp-2Ch] BYREF
  Vector vecAbsMaxs; // [esp+24h] [ebp-20h] BYREF
  Vector vecAbsCenter; // [esp+30h] [ebp-14h] BYREF
  ShadowType_t shadowType; // [esp+3Ch] [ebp-8h]
  CVisibleShadowList *v16; // [esp+40h] [ebp-4h]
  int savedregs; // [esp+44h] [ebp+0h] BYREF

  v2 = clientShadowHandle;
  v3 = &s_ClientShadowMgr.m_Shadows.m_Memory.m_pMemory[LOWORD(clientShadowHandle)];
  v16 = this;
  if ( v3->m_Element.m_nRenderFrame != *(_DWORD *)(gpGlobals.m_Index + 4) && (v3->m_Element.m_Flags & 5) == 0 )
  {
    ActualShadowCastType = CClientShadowMgr::GetActualShadowCastType(
                             this: &s_ClientShadowMgr,
                             handle: LOWORD(clientShadowHandle));
    shadowType = ActualShadowCastType;
    if ( (ActualShadowCastType == SHADOWS_RENDER_TO_TEXTURE || ActualShadowCastType == SHADOWS_SIMPLE)
      && v3->m_Element.m_FalloffBias != 255 )
    {
      ClientRenderableFromHandle = CClientEntityList::GetClientRenderableFromHandle(
                                     this: (CClientEntityList *)cl_entitylist.m_Index,
                                     hEnt: v3->m_Element.m_Entity);
      if ( CClientShadowMgr::ShouldUseParentShadow(this: &s_ClientShadowMgr, pRenderable: ClientRenderableFromHandle) == 0
        && !CClientShadowMgr::WillParentRenderBlobbyShadow(
              this: &s_ClientShadowMgr,
              pRenderable: ClientRenderableFromHandle) )
      {
        CClientShadowMgr::ComputeBoundingSphere(
          this: &s_ClientShadowMgr,
          a2: COERCE_FLOAT(&savedregs),
          a3: (int)ClientRenderableFromHandle,
          a4: (int)v3,
          pRenderable: ClientRenderableFromHandle,
          origin: &vecAbsCenter,
          radius: &clientShadowHandle);
        CClientShadowMgr::ComputeShadowBBox(
          this: &s_ClientShadowMgr,
          pRenderable: ClientRenderableFromHandle,
          shadowHandle: v2,
          &vecAbsCenter,
          flRadius: clientShadowHandle,
          pAbsMins: &vecAbsMins,
          pAbsMaxs: &vecAbsMaxs);
        if ( !engine->CullBox(this: engine, a2: &vecAbsMins, a3: &vecAbsMaxs) )
        {
          if ( shadowType == SHADOWS_RENDER_TO_TEXTURE )
          {
            v6 = v16;
            v7 = (int)&v6->m_ShadowsInView.m_Memory.m_pMemory[CUtlVector<VisibleShadowInfo_t,CUtlMemory<VisibleShadowInfo_t,int>>::AddToTail(this: &v16->m_ShadowsInView)];
            v8 = v16;
            r = clientShadowHandle;
            *(_WORD *)v7 = LOWORD(v2);
            *(float *)(v7 + 4) = CVisibleShadowList::ComputeScreenArea(this: v8, vecCenter: &vecAbsCenter, r);
            v3->m_Element.m_nRenderFrame = *(_DWORD *)(gpGlobals.m_Index + 4);
          }
          else
          {
            v9 = v16;
            v10 = (int)&v9->m_BlobbyShadowsInView.m_Memory.m_pMemory[CUtlVector<VisibleShadowInfo_t,CUtlMemory<VisibleShadowInfo_t,int>>::AddToTail(this: &v16->m_BlobbyShadowsInView)];
            *(_WORD *)v10 = LOWORD(v2);
            *(_DWORD *)(v10 + 4) = 0;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B9FE0
// Name: public: CTextureAllocator::CTextureAllocator(void)
// Source: json
//------------------------------------------------------------------------------
CTextureAllocator *__thiscall CTextureAllocator::CTextureAllocator(CTextureAllocator *this)
{
  UtlLinkedListElem_t<CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::List_t,unsigned short> *m_pMemory; // edx

  CTextureReference::CTextureReference(this: &this->m_TexturePage);
  this->m_Textures.m_Memory.m_pMemory = nullptr;
  this->m_Textures.m_Memory.m_nAllocationCount = 0;
  this->m_Textures.m_Memory.m_nGrowSize = 0;
  this->m_Textures.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_Textures.m_FirstFree = 0xFFFF;
  this->m_Textures.m_pElements = this->m_Textures.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_Textures.m_Head = -1;
  this->m_Textures.m_NumAlloced = 0;
  this->m_Fragments.m_Memory.m_pMemory = nullptr;
  this->m_Fragments.m_Memory.m_nAllocationCount = 0;
  this->m_Fragments.m_Memory.m_nGrowSize = 0;
  this->m_Fragments.m_List.m_Memory.m_pMemory = nullptr;
  this->m_Fragments.m_List.m_Memory.m_nAllocationCount = 0;
  this->m_Fragments.m_List.m_Memory.m_nGrowSize = 0;
  this->m_Fragments.m_List.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_Fragments.m_List.m_FirstFree = 0xFFFF;
  m_pMemory = this->m_Fragments.m_List.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_Fragments.m_List.m_Head = -1;
  this->m_Fragments.m_List.m_pElements = m_pMemory;
  this->m_Fragments.m_List.m_NumAlloced = 0;
  this->m_Fragments.m_pElementList = nullptr;
  this->m_Fragments.m_MaxElementIndex = 0;
  this->m_Fragments.m_pElements = this->m_Fragments.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_Fragments.m_FirstFree = 0xFFFF;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100BA060
// Name: private: void CClientShadowMgr::InitDepthTextureShadows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::InitDepthTextureShadows(CClientShadowMgr *this)
{
  CClientShadowMgr *v1; // ebx
  int m_nValue; // eax
  int v3; // eax
  ImageFormat v4; // esi
  CUtlMemory<vgui::TreeNode *,int> *p_m_DepthTextureCache; // esi
  CUtlMemory<unsigned char,int> *p_m_DepthTextureCacheLocks; // edi
  bool v7; // cc
  int m_nDepthTextureResolution; // ebx
  vgui::TreeNode **m_pMemory; // ebx
  int m_nAllocationCount; // eax
  vgui::TreeNode **v11; // ecx
  int v12; // eax
  CTextureReference *v13; // ecx
  unsigned __int8 *v14; // ebx
  int v15; // eax
  unsigned __int8 *v16; // ecx
  int v17; // eax
  unsigned __int8 *v18; // eax
  char strRTName[64]; // [esp+4h] [ebp-50h] BYREF
  ImageFormat dstFormat; // [esp+44h] [ebp-10h]
  CClientShadowMgr *v21; // [esp+48h] [ebp-Ch]
  CTextureReference depthTex; // [esp+4Ch] [ebp-8h] BYREF
  int i; // [esp+50h] [ebp-4h]

  v1 = this;
  v21 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CClientShadowMgr::InitDepthTextureShadows",
    a3: 0,
    a4: "Flashlight Shadows",
    a5: false,
    a6: 4);
  if ( !v1->m_bDepthTextureActive )
  {
    v1->m_bDepthTextureActive = true;
    if ( r_flashlightdepthtexture.m_pParent != nullptr && r_flashlightdepthtexture.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( !v1->m_bDepthTexturesAllocated
        || (r_flashlightdepthres.m_pParent == nullptr
          ? (m_nValue = 0)
          : (m_nValue = r_flashlightdepthres.m_pParent->m_Value.m_nValue),
            v1->m_nDepthTextureResolution != m_nValue
         || (r_flashlightdepthreshigh.m_pParent == nullptr
           ? (v3 = 0)
           : (v3 = r_flashlightdepthreshigh.m_pParent->m_Value.m_nValue),
             v1->m_nDepthTextureResolutionHigh != v3)) )
      {
        CClientShadowMgr::CalculateRenderTargetsAndSizes(this: v1);
        v1->m_bDepthTexturesAllocated = true;
        dstFormat = g_pMaterialSystemHardwareConfig->GetShadowDepthTextureFormat(this: g_pMaterialSystemHardwareConfig);
        v4 = g_pMaterialSystemHardwareConfig->GetNullTextureFormat(this: g_pMaterialSystemHardwareConfig);
        materials->BeginRenderTargetAllocation(this: materials);
        CTextureReference::InitRenderTarget(
          this: &v1->m_DummyColorTexture,
          w: v1->m_nDepthTextureResolution,
          h: v1->m_nDepthTextureResolution,
          sizeMode: RT_SIZE_NO_CHANGE,
          fmt: v4,
          depth: MATERIAL_RT_DEPTH_NONE,
          bHDR: false,
          pStrOptionalName: "_rt_ShadowDummy");
        p_m_DepthTextureCache = (CUtlMemory<vgui::TreeNode *,int> *)&v1->m_DepthTextureCache;
        CUtlVector<CTextureReference,CUtlMemory<CTextureReference,int>>::Purge(this: &v1->m_DepthTextureCache);
        p_m_DepthTextureCacheLocks = (CUtlMemory<unsigned char,int> *)&v1->m_DepthTextureCacheLocks;
        CUtlVector<CBoneMergeCache::CMergedBone,CUtlMemory<CBoneMergeCache::CMergedBone,int>>::Purge(this: (CUtlVector<CBoneMergeCache::CMergedBone,CUtlMemory<CBoneMergeCache::CMergedBone,int> > *)&v1->m_DepthTextureCacheLocks);
        v7 = v1->m_nMaxDepthTextureShadows <= 0;
        i = 0;
        if ( !v7 )
        {
          while ( 1 )
          {
            CTextureReference::CTextureReference(this: &depthTex);
            V_snprintf(pDest: strRTName, maxLen: 0x40u, pFormat: "_rt_ShadowDepthTexture_%d", i);
            if ( i >= 0 )
              m_nDepthTextureResolution = v1->m_nDepthTextureResolution;
            else
              m_nDepthTextureResolution = v1->m_nDepthTextureResolutionHigh;
            CTextureReference::InitRenderTarget(
              this: &depthTex,
              w: m_nDepthTextureResolution,
              h: m_nDepthTextureResolution,
              sizeMode: RT_SIZE_NO_CHANGE,
              fmt: dstFormat,
              depth: MATERIAL_RT_DEPTH_NONE,
              bHDR: false,
              pStrOptionalName: strRTName);
            m_pMemory = p_m_DepthTextureCache[1].m_pMemory;
            m_nAllocationCount = p_m_DepthTextureCache->m_nAllocationCount;
            if ( (int)m_pMemory + 1 > m_nAllocationCount )
              CUtlMemory<CChoreoActor *,int>::Grow(
                this: p_m_DepthTextureCache,
                num: (int)m_pMemory - m_nAllocationCount + 1);
            ++p_m_DepthTextureCache[1].m_pMemory;
            v11 = p_m_DepthTextureCache->m_pMemory;
            v12 = (char *)p_m_DepthTextureCache[1].m_pMemory - (char *)m_pMemory - 1;
            p_m_DepthTextureCache[1].m_nAllocationCount = (int)p_m_DepthTextureCache->m_pMemory;
            if ( v12 > 0 )
              _V_memmove(dest: &v11[(_DWORD)m_pMemory + 1], src: &v11[(_DWORD)m_pMemory], count: 4 * v12);
            v13 = (CTextureReference *)&p_m_DepthTextureCache->m_pMemory[(_DWORD)m_pMemory];
            if ( v13 != nullptr )
              CTextureReference::CTextureReference(this: v13, ref: &depthTex);
            v14 = p_m_DepthTextureCacheLocks[1].m_pMemory;
            v15 = p_m_DepthTextureCacheLocks->m_nAllocationCount;
            if ( (int)(v14 + 1) > v15 )
              CUtlMemory<bool,int>::Grow(this: p_m_DepthTextureCacheLocks, num: (int)&v14[-v15 + 1]);
            ++p_m_DepthTextureCacheLocks[1].m_pMemory;
            v16 = p_m_DepthTextureCacheLocks->m_pMemory;
            v17 = p_m_DepthTextureCacheLocks[1].m_pMemory - v14 - 1;
            p_m_DepthTextureCacheLocks[1].m_nAllocationCount = (int)p_m_DepthTextureCacheLocks->m_pMemory;
            if ( v17 > 0 )
              _V_memmove(dest: &v16[(_DWORD)v14 + 1], src: &v16[(_DWORD)v14], count: v17);
            v18 = &v14[(unsigned int)p_m_DepthTextureCacheLocks->m_pMemory];
            if ( v18 != nullptr )
              *v18 = 0;
            CTextureReference::~CTextureReference(this: &depthTex);
            if ( ++i >= v21->m_nMaxDepthTextureShadows )
              break;
            v1 = v21;
          }
        }
        materials->EndRenderTargetAllocation(this: materials);
      }
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x100BA2B0
// Name: public: virtual void CClientShadowMgr::LevelShutdownPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::LevelShutdownPostEntity(CClientShadowMgr *this)
{
  CFlashlightEffectManager *v2; // edi
  CFlashlightEffect *m_pFlashlightEffect; // ebx
  int m_Head; // eax
  int m_Next; // edi

  v2 = FlashlightEffectManager(nSplitscreenPlayerOverride: 0);
  v2->m_pFlashlightTextureName = nullptr;
  v2->m_bFlashlightOn = false;
  v2->m_bFlashlightOverride = false;
  v2->m_nMuzzleFlashFrameCountdown = 0;
  if ( v2->m_muzzleFlashTimer.m_timestamp.m_Value != -1.0 )
  {
    v2->m_muzzleFlashTimer.NetworkStateChanged(this: &v2->m_muzzleFlashTimer, a2: &v2->m_muzzleFlashTimer.m_timestamp);
    v2->m_muzzleFlashTimer.m_timestamp.m_Value = -1.0;
  }
  m_pFlashlightEffect = v2->m_pFlashlightEffect;
  if ( v2->m_pFlashlightEffect != nullptr )
  {
    CFlashlightEffect::~CFlashlightEffect(this: v2->m_pFlashlightEffect);
    C_BaseEntity::operator delete(pMem: m_pFlashlightEffect);
  }
  v2->m_pFlashlightEffect = nullptr;
  m_Head = this->m_Shadows.m_Head;
  if ( (_WORD)m_Head != 0xFFFF )
  {
    do
    {
      m_Next = this->m_Shadows.m_Memory.m_pMemory[(unsigned __int16)m_Head].m_Next;
      this->DestroyShadow(this, a2: m_Head);
      m_Head = m_Next;
    }
    while ( (_WORD)m_Next != 0xFFFF );
  }
  if ( this->m_RenderToTextureActive )
    CTextureAllocator::DeallocateAllTextures(this: &this->m_ShadowAllocator);
  ConVar::SetValue(this: (ConVar *)&r_shadows_gamecontrol.IConVar, value: -1);
}

//------------------------------------------------------------------------------
// Address: 0x100BA380
// Name: private: void CClientShadowMgr::QueueShadowForDestruction(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::QueueShadowForDestruction(CClientShadowMgr *this, unsigned __int16 handle)
{
  int m_Size; // edx
  CUtlMemory<CUtlSymbol,int> *p_m_shadowsToDestroy; // esi
  int v4; // eax
  CUtlSymbol *m_pMemory; // edi
  int m_nAllocationCount; // eax
  int v7; // edi
  CUtlSymbol *v8; // ecx
  int v9; // eax
  CUtlSymbol *v10; // eax

  m_Size = this->m_shadowsToDestroy.m_Size;
  p_m_shadowsToDestroy = (CUtlMemory<CUtlSymbol,int> *)&this->m_shadowsToDestroy;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_8;
  m_pMemory = p_m_shadowsToDestroy->m_pMemory;
  while ( m_pMemory->m_Id != handle )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_8;
  }
  if ( v4 < 0 || v4 >= this->m_shadowsToDestroy.m_Size )
  {
LABEL_8:
    m_nAllocationCount = this->m_shadowsToDestroy.m_Memory.m_nAllocationCount;
    v7 = this->m_shadowsToDestroy.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<wchar_t,int>::Grow(this: p_m_shadowsToDestroy, num: m_Size - m_nAllocationCount + 1);
    ++p_m_shadowsToDestroy[1].m_pMemory;
    v8 = p_m_shadowsToDestroy->m_pMemory;
    v9 = (int)p_m_shadowsToDestroy[1].m_pMemory - v7 - 1;
    p_m_shadowsToDestroy[1].m_nAllocationCount = (int)p_m_shadowsToDestroy->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 2 * v9);
    v10 = &p_m_shadowsToDestroy->m_pMemory[v7];
    if ( v10 != nullptr )
      v10->m_Id = handle;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BA410
// Name: private: bool CClientShadowMgr::DrawRenderToTextureShadow(int,unsigned short,float)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CClientShadowMgr::DrawRenderToTextureShadow(
        CClientShadowMgr *this,
        float nSlot,
        int clientShadowHandle,
        int flArea)
{
  int v4; // edi
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *v6; // esi
  bool v7; // cl
  unsigned __int16 v8; // ax
  unsigned __int16 m_ShadowTexture; // ax
  bool v10; // al
  unsigned __int16 v11; // dx
  int v13; // edi
  IMatRenderContext *v14; // eax
  IMatRenderContext *v15; // edi
  unsigned __int16 m_Flags; // ax
  void (__thiscall *SetShadowTexCoord)(IShadowMgr *, unsigned __int16, float, float, float, float); // edx
  void (__thiscall *EndRender)(IMatRenderContext *); // edx
  int m_ShadowHandle; // [esp+30h] [ebp-30h]
  float v20; // [esp+50h] [ebp-10h]
  IClientRenderable *pRenderable; // [esp+54h] [ebp-Ch]
  float pRenderablea; // [esp+54h] [ebp-Ch]
  int x; // [esp+58h] [ebp-8h] BYREF
  bool bPreviouslyUsingLODShadow; // [esp+5Eh] [ebp-2h]
  bool bDrewTexture; // [esp+5Fh] [ebp-1h]

  v4 = (unsigned __int16)clientShadowHandle;
  v6 = &this->m_Shadows.m_Memory.m_pMemory[(unsigned __int16)clientShadowHandle];
  if ( v6->m_Element.m_bUseSplitScreenBits
    && ((1 << (LOBYTE(nSlot) & 0x1F)) & v6->m_Element.m_SplitScreenBits.m_Ints[SLODWORD(nSlot) >> 5]) == 0 )
  {
    return false;
  }
  v8 = v6->m_Element.m_Flags & 0xFDFF;
  bPreviouslyUsingLODShadow = (v6->m_Element.m_Flags & 0x200) != 0;
  v7 = bPreviouslyUsingLODShadow;
  v6->m_Element.m_Flags = v8;
  if ( v7 )
    ((void (__stdcall *)(_DWORD, IMaterial *, IMaterial *, int))shadowmgr->SetShadowMaterial)(
      a1: v6->m_Element.m_ShadowHandle,
      a2: this->m_RenderShadow.m_pMaterial,
      a3: this->m_RenderModelShadow.m_pMaterial,
      a4: v4);
  LOBYTE(x) = LOBYTE(v6->m_Element.m_Flags) >> 7;
  m_ShadowTexture = v6->m_Element.m_ShadowTexture;
  bDrewTexture = false;
  v10 = CTextureAllocator::UseTexture(
          this: &this->m_ShadowAllocator,
          h: m_ShadowTexture,
          bWillRedraw: x,
          flArea: *(float *)&flArea);
  v11 = v6->m_Element.m_ShadowTexture;
  HIBYTE(flArea) = v10;
  if ( this->m_ShadowAllocator.m_Textures.m_Memory.m_pMemory[v11].m_Element.m_Fragment == 0xFFFF )
  {
    CClientShadowMgr::DrawRenderToTextureShadowLOD(this, nSlot: SLODWORD(nSlot), clientShadowHandle);
    return false;
  }
  if ( HIBYTE(flArea) != 0 || (_BYTE)x != 0 )
  {
    pRenderable = CClientEntityList::GetClientRenderableFromHandle(
                    this: (CClientEntityList *)cl_entitylist.m_Index,
                    hEnt: v6->m_Element.m_Entity);
    v14 = materials->GetRenderContext(this: materials);
    v15 = v14;
    if ( v14 != nullptr )
      v14->BeginRender(this: v14);
    CTextureAllocator::GetTextureRect(
      this: &this->m_ShadowAllocator,
      handle: v6->m_Element.m_ShadowTexture,
      &x,
      y: &flArea,
      w: (int *)&nSlot,
      h: &clientShadowHandle);
    ((void (__thiscall *)(IMatRenderContext *, int, int, float, int))v15->Viewport)(
      a1: v15,
      a2: x,
      a3: flArea,
      a4: COERCE_FLOAT(LODWORD(nSlot)),
      a5: clientShadowHandle);
    v15->ClearBuffers(this: v15, a2: true, a3: false, a4: false);
    v15->MatrixMode(this: v15, a2: MATERIAL_VIEW);
    v15->LoadMatrix_2(this: v15, a2: &v6->m_Element.m_WorldToTexture);
    if ( CClientShadowMgr::DrawShadowHierarchy(this, pRenderable, shadow: &v6->m_Element, bChild: 0) != 0 )
      bDrewTexture = true;
    else
      DevMsg(a1: "Didn't draw shadow hierarchy.. bad shadow texcoords probably going to happen..grab Brian!\n");
    m_Flags = v6->m_Element.m_Flags;
    if ( (m_Flags & 0x10) == 0 )
      v6->m_Element.m_Flags = m_Flags & 0xFF7F;
    SetShadowTexCoord = shadowmgr->SetShadowTexCoord;
    m_ShadowHandle = v6->m_Element.m_ShadowHandle;
    v20 = (float)((float)clientShadowHandle - 1.0) * 0.0009765625;
    pRenderablea = (float)((float)SLODWORD(nSlot) - 1.0) * 0.0009765625;
    nSlot = (float)((float)flArea + 0.5) * 0.0009765625;
    *(float *)&clientShadowHandle = (float)((float)x + 0.5) * 0.0009765625;
    ((void (__thiscall *)(IShadowMgr *, int, int, _DWORD, _DWORD, _DWORD))SetShadowTexCoord)(
      a1: shadowmgr,
      a2: m_ShadowHandle,
      a3: clientShadowHandle,
      a4: LODWORD(nSlot),
      a5: LODWORD(pRenderablea),
      a6: LODWORD(v20));
    EndRender = v15->EndRender;
    v6->m_Element.m_TexCoordOffset.x = *(float *)&clientShadowHandle;
    v6->m_Element.m_TexCoordOffset.y = nSlot;
    v6->m_Element.m_TexCoordScale.x = pRenderablea;
    v6->m_Element.m_TexCoordScale.y = v20;
    EndRender(this: v15);
    v15->Release(this: v15);
  }
  else if ( bPreviouslyUsingLODShadow )
  {
    CTextureAllocator::GetTextureRect(
      this: &this->m_ShadowAllocator,
      handle: v11,
      x: &flArea,
      y: (int *)&nSlot,
      w: &clientShadowHandle,
      h: &x);
    v13 = x;
    CClientShadowMgr::SetRenderToTextureShadowTexCoords(
      this,
      handle: v6->m_Element.m_ShadowHandle,
      x: flArea,
      y: SLODWORD(nSlot),
      w: clientShadowHandle,
      h: x);
    CClientShadowMgr::SetRenderToTextureShadowTexCoords(
      this,
      shadow: &v6->m_Element,
      x: flArea,
      y: SLODWORD(nSlot),
      w: clientShadowHandle,
      h: v13);
    return bDrewTexture;
  }
  return bDrewTexture;
}

//------------------------------------------------------------------------------
// Address: 0x100BA8E0
// Name: public: void CTextureAllocator::DeallocateTexture(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureAllocator::DeallocateTexture(CTextureAllocator *this, unsigned __int16 h)
{
  CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *p_m_Textures; // esi
  int v3; // edi
  int m_Fragment; // eax
  CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short> *p_m_Fragments; // ebx
  int v6; // eax
  int v7; // ecx

  p_m_Textures = (CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *)&this->m_Textures;
  v3 = h;
  m_Fragment = this->m_Textures.m_Memory.m_pMemory[v3].m_Element.m_Fragment;
  if ( (_WORD)m_Fragment != 0xFFFF )
  {
    p_m_Fragments = &this->m_Fragments;
    CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::LinkAfter(
      this: &this->m_Fragments,
      list: this->m_Cache[this->m_Blocks[this->m_Fragments.m_Memory.m_pMemory[m_Fragment].m_Element.m_Block].m_FragmentPower].m_List,
      after: 0xFFFFu,
      elem: this->m_Textures.m_Memory.m_pMemory[v3].m_Element.m_Fragment);
    p_m_Fragments->m_Memory.m_pMemory[p_m_Textures->m_Memory.m_pMemory[h].m_Element.m_Head].m_Element.m_FrameUsed = -1;
    v6 = (int)&p_m_Fragments->m_Memory.m_pMemory[p_m_Textures->m_Memory.m_pMemory[h].m_Element.m_Head];
    v7 = *(unsigned __int16 *)(v6 + 4);
    if ( (_WORD)v7 != 0xFFFF )
    {
      p_m_Textures->m_Memory.m_pMemory[v7].m_Element.m_Head = -1;
      *(_WORD *)(v6 + 4) = -1;
    }
  }
  CUtlLinkedList<Panel_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<Panel_t,unsigned short>,unsigned short>>::Unlink(
    this: p_m_Textures,
    elem: h);
  p_m_Textures->m_Memory.m_pMemory[v3].m_Next = p_m_Textures->m_FirstFree;
  p_m_Textures->m_FirstFree = h;
}

//------------------------------------------------------------------------------
// Address: 0x100BA990
// Name: public: virtual CClientShadowMgr::~CClientShadowMgr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::~CClientShadowMgr(CClientShadowMgr *this)
{
  CTextureReference::~CTextureReference(this: &this->m_downSampledDepth);
  CTextureReference::~CTextureReference(this: &this->m_downSampledNormals);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_DepthTextureCacheLocks);
  CUtlVector<CTextureReference,CUtlMemory<CTextureReference,int>>::Purge(this: &this->m_DepthTextureCache);
  if ( this->m_DepthTextureCache.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_DepthTextureCache.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_DepthTextureCache.m_Memory.m_pMemory);
      this->m_DepthTextureCache.m_Memory.m_pMemory = nullptr;
    }
    this->m_DepthTextureCache.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_shadowsToDestroy);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_TransparentShadows);
  CUtlRBTree<unsigned short,unsigned short,bool (__cdecl *)(unsigned short const &,unsigned short const &),CUtlMemory<UtlRBTreeNode_t<unsigned short,unsigned short>,unsigned short>>::~CUtlRBTree<unsigned short,unsigned short,bool (__cdecl *)(unsigned short const &,unsigned short const &),CUtlMemory<UtlRBTreeNode_t<unsigned short,unsigned short>,unsigned short>>(this: &this->m_DirtyShadowsLeftOver);
  CUtlRBTree<unsigned short,unsigned short,bool (__cdecl *)(unsigned short const &,unsigned short const &),CUtlMemory<UtlRBTreeNode_t<unsigned short,unsigned short>,unsigned short>>::~CUtlRBTree<unsigned short,unsigned short,bool (__cdecl *)(unsigned short const &,unsigned short const &),CUtlMemory<UtlRBTreeNode_t<unsigned short,unsigned short>,unsigned short>>(this: &this->m_DirtyShadows);
  CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::~CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>(this: &this->m_ShadowAllocator.m_Fragments);
  CUtlLinkedList<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *)&this->m_ShadowAllocator.m_Textures);
  if ( this->m_ShadowAllocator.m_Textures.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ShadowAllocator.m_Textures.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ShadowAllocator.m_Textures.m_Memory.m_pMemory);
      this->m_ShadowAllocator.m_Textures.m_Memory.m_pMemory = nullptr;
    }
    this->m_ShadowAllocator.m_Textures.m_Memory.m_nAllocationCount = 0;
  }
  CTextureReference::~CTextureReference(this: &this->m_ShadowAllocator.m_TexturePage);
  CUtlLinkedList<CClientShadowMgr::ClientShadow_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Shadows);
  if ( this->m_Shadows.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Shadows.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Shadows.m_Memory.m_pMemory);
      this->m_Shadows.m_Memory.m_pMemory = nullptr;
    }
    this->m_Shadows.m_Memory.m_nAllocationCount = 0;
  }
  CTextureReference::~CTextureReference(this: &this->m_DummyColorTexture);
  CMaterialReference::~CMaterialReference(this: &this->m_RenderDeferredSimpleShadowMat);
  CMaterialReference::~CMaterialReference(this: &this->m_RenderDeferredShadowMat);
  CMaterialReference::~CMaterialReference(this: &this->m_RenderModelShadow);
  CMaterialReference::~CMaterialReference(this: &this->m_RenderShadow);
  CMaterialReference::~CMaterialReference(this: &this->m_SimpleShadow);
  IGameSystemPerFrame::~IGameSystemPerFrame(this);
}

//------------------------------------------------------------------------------
// Address: 0x100BAAE0
// Name: private: void CVisibleShadowList::PrioritySort(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVisibleShadowList::PrioritySort(CVisibleShadowList *this)
{
  int m_Size; // ebx
  CUtlMemory<vgui::TreeNode *,int> *p_m_PriorityIndex; // esi
  vgui::TreeNode **m_pMemory; // eax
  IMemAlloc_vtbl *v4; // edx
  int v5; // eax
  vgui::TreeNode **v6; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  int *v10; // edi
  int v11; // ebx
  int v12; // eax
  VisibleShadowInfo_t *v13; // edx
  int v14; // ebx
  vgui::TreeNode *v15; // ecx
  int v16; // edi
  int v17; // eax
  float m_flArea; // xmm0_4
  _DWORD *v19; // ecx
  _DWORD *v20; // ebx
  vgui::TreeNode **v21; // eax
  vgui::TreeNode *v22; // ecx
  int v23; // [esp+Ch] [ebp-14h]
  int v25; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  int ia; // [esp+18h] [ebp-8h]
  int nCount; // [esp+1Ch] [ebp-4h]

  m_Size = this->m_ShadowsInView.m_Size;
  p_m_PriorityIndex = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_PriorityIndex;
  nCount = m_Size;
  if ( this->m_PriorityIndex.m_Memory.m_nAllocationCount < m_Size && this->m_PriorityIndex.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = p_m_PriorityIndex->m_pMemory;
    this->m_PriorityIndex.m_Memory.m_nAllocationCount = m_Size;
    v4 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v5 = ((int (__stdcall *)(vgui::TreeNode **, int))v4->Realloc_2)(a1: m_pMemory, a2: 4 * m_Size);
    else
      v5 = ((int (__stdcall *)(int))v4->Alloc_2)(a1: 4 * m_Size);
    p_m_PriorityIndex->m_pMemory = (vgui::TreeNode **)v5;
  }
  p_m_PriorityIndex[1].m_nAllocationCount = (int)p_m_PriorityIndex->m_pMemory;
  p_m_PriorityIndex[1].m_pMemory = nullptr;
  for ( i = 0; i < m_Size; ++i )
  {
    v6 = p_m_PriorityIndex[1].m_pMemory;
    m_nAllocationCount = p_m_PriorityIndex->m_nAllocationCount;
    if ( (int)v6 + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_PriorityIndex, num: (int)v6 - m_nAllocationCount + 1);
    ++p_m_PriorityIndex[1].m_pMemory;
    v8 = p_m_PriorityIndex->m_pMemory;
    v9 = (char *)p_m_PriorityIndex[1].m_pMemory - (char *)v6 - 1;
    p_m_PriorityIndex[1].m_nAllocationCount = (int)p_m_PriorityIndex->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[(_DWORD)v6 + 1], src: &v8[(_DWORD)v6], count: 4 * v9);
    v10 = (int *)&p_m_PriorityIndex->m_pMemory[(_DWORD)v6];
    if ( v10 != nullptr )
      *v10 = i;
  }
  v11 = m_Size - 1;
  v12 = 0;
  if ( v11 > 0 )
  {
    ia = v11;
    do
    {
      v13 = this->m_ShadowsInView.m_Memory.m_pMemory;
      v14 = v12;
      v15 = p_m_PriorityIndex->m_pMemory[v12];
      v16 = v12;
      v17 = v12 + 1;
      m_flArea = v13[(_DWORD)v15].m_flArea;
      v25 = v14 * 4;
      v23 = v17;
      if ( v17 < nCount )
      {
        if ( ia >= 4 )
        {
          v19 = &p_m_PriorityIndex->m_pMemory[v14 + 3];
          do
          {
            if ( v13[*(v19 - 2)].m_flArea > m_flArea )
            {
              v16 = v17;
              m_flArea = v13[*(v19 - 2)].m_flArea;
            }
            if ( v13[*(v19 - 1)].m_flArea > m_flArea )
            {
              v16 = v17 + 1;
              m_flArea = v13[*(v19 - 1)].m_flArea;
            }
            if ( v13[*v19].m_flArea > m_flArea )
            {
              v16 = v17 + 2;
              m_flArea = v13[*v19].m_flArea;
            }
            if ( v13[v19[1]].m_flArea > m_flArea )
            {
              v16 = v17 + 3;
              m_flArea = v13[v19[1]].m_flArea;
            }
            v17 += 4;
            v19 += 4;
          }
          while ( v17 < nCount - 3 );
        }
        if ( v17 < nCount )
        {
          v20 = &p_m_PriorityIndex->m_pMemory[v17];
          do
          {
            if ( v13[*v20].m_flArea > m_flArea )
            {
              v16 = v17;
              m_flArea = v13[*v20].m_flArea;
            }
            ++v17;
            ++v20;
          }
          while ( v17 < nCount );
        }
      }
      v21 = p_m_PriorityIndex->m_pMemory;
      v22 = *(vgui::TreeNode **)((char *)p_m_PriorityIndex->m_pMemory + v25);
      --ia;
      *(vgui::TreeNode **)((char *)v21 + v25) = p_m_PriorityIndex->m_pMemory[v16];
      v21[v16] = v22;
      v12 = v23;
    }
    while ( v23 < nCount - 1 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BACB0
// Name: public: int CVisibleShadowList::FindShadows(class CViewSetup const __near *,int,struct WorldListLeafData_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVisibleShadowList::FindShadows(
        CVisibleShadowList *this,
        const CViewSetup *pView,
        int nLeafCount,
        WorldListLeafData_t *pLeafList)
{
  int m_Size; // edi

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CVisibleShadowList::FindShadows",
    a3: 0,
    a4: "Shadow_Rendering",
    a5: false,
    a6: 4);
  this->m_ShadowsInView.m_Size = 0;
  this->m_BlobbyShadowsInView.m_Size = 0;
  g_pClientLeafSystem->EnumerateShadowsInLeaves(this: g_pClientLeafSystem, a2: nLeafCount, a3: pLeafList, a4: this);
  m_Size = this->m_ShadowsInView.m_Size;
  if ( m_Size != 0 )
    CVisibleShadowList::PrioritySort(this);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100BAD20
// Name: public: CClientShadowMgr::CClientShadowMgr(void)
// Source: json
//------------------------------------------------------------------------------
CClientShadowMgr *__thiscall CClientShadowMgr::CClientShadowMgr(CClientShadowMgr *this)
{
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *m_pMemory; // eax
  UtlRBTreeNode_t<unsigned short,unsigned short> *v3; // ecx
  UtlRBTreeNode_t<unsigned short,unsigned short> *v4; // eax

  this->__vftable = (CClientShadowMgr_vtbl *)&CClientShadowMgr::`vftable';
  CMaterialReference::CMaterialReference(
    this: &this->m_SimpleShadow,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_RenderShadow,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_RenderModelShadow,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_RenderDeferredShadowMat,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_RenderDeferredSimpleShadowMat,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CTextureReference::CTextureReference(this: &this->m_DummyColorTexture);
  this->m_Shadows.m_Memory.m_pMemory = nullptr;
  this->m_Shadows.m_Memory.m_nAllocationCount = 0;
  this->m_Shadows.m_Memory.m_nGrowSize = 0;
  this->m_Shadows.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_Shadows.m_FirstFree = 0xFFFF;
  m_pMemory = this->m_Shadows.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_Shadows.m_Head = -1;
  this->m_Shadows.m_NumAlloced = 0;
  this->m_Shadows.m_pElements = m_pMemory;
  CTextureAllocator::CTextureAllocator(this: &this->m_ShadowAllocator);
  this->m_RenderToTextureActive = false;
  this->m_DirtyShadows.m_LessFunc = (bool (__cdecl *)(const unsigned __int16 *, const unsigned __int16 *))CClientShadowMgr::ShadowHandleCompareFunc;
  this->m_DirtyShadows.m_Elements.m_pMemory = nullptr;
  this->m_DirtyShadows.m_Elements.m_nAllocationCount = 0;
  this->m_DirtyShadows.m_Elements.m_nGrowSize = 0;
  v3 = this->m_DirtyShadows.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_DirtyShadows.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_DirtyShadows.m_FirstFree = -1;
  this->m_DirtyShadows.m_pElements = v3;
  this->m_DirtyShadowsLeftOver.m_LessFunc = (bool (__cdecl *)(const unsigned __int16 *, const unsigned __int16 *))CClientShadowMgr::ShadowHandleCompareFunc;
  this->m_DirtyShadowsLeftOver.m_Elements.m_pMemory = nullptr;
  this->m_DirtyShadowsLeftOver.m_Elements.m_nAllocationCount = 0;
  this->m_DirtyShadowsLeftOver.m_Elements.m_nGrowSize = 0;
  v4 = this->m_DirtyShadowsLeftOver.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_DirtyShadowsLeftOver.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_DirtyShadowsLeftOver.m_FirstFree = -1;
  this->m_DirtyShadowsLeftOver.m_pElements = v4;
  this->m_TransparentShadows.m_Memory.m_pMemory = nullptr;
  this->m_TransparentShadows.m_Memory.m_nAllocationCount = 0;
  this->m_TransparentShadows.m_Memory.m_nGrowSize = 0;
  this->m_TransparentShadows.m_Size = 0;
  this->m_TransparentShadows.m_pElements = nullptr;
  this->m_shadowsToDestroy.m_Memory.m_pMemory = nullptr;
  this->m_shadowsToDestroy.m_Memory.m_nAllocationCount = 0;
  this->m_shadowsToDestroy.m_Memory.m_nGrowSize = 0;
  this->m_shadowsToDestroy.m_Size = 0;
  this->m_shadowsToDestroy.m_pElements = nullptr;
  this->m_nPrevFrameCount = -1;
  this->m_bDepthTextureActive = false;
  this->m_bDepthTexturesAllocated = false;
  this->m_uiDepthTextureCache = 0;
  this->m_DepthTextureCache.m_Memory.m_pMemory = nullptr;
  this->m_DepthTextureCache.m_Memory.m_nAllocationCount = 0;
  this->m_DepthTextureCache.m_Memory.m_nGrowSize = 0;
  this->m_DepthTextureCache.m_Size = 0;
  this->m_DepthTextureCache.m_pElements = nullptr;
  this->m_DepthTextureCacheLocks.m_Memory.m_pMemory = nullptr;
  this->m_DepthTextureCacheLocks.m_Memory.m_nAllocationCount = 0;
  this->m_DepthTextureCacheLocks.m_Memory.m_nGrowSize = 0;
  this->m_DepthTextureCacheLocks.m_Size = 0;
  this->m_DepthTextureCacheLocks.m_pElements = nullptr;
  *(_WORD *)&this->m_bShadowFromWorldLights = 0;
  CTextureReference::CTextureReference(this: &this->m_downSampledNormals);
  CTextureReference::CTextureReference(this: &this->m_downSampledDepth);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100BAEE0
// Name: public: virtual char const __near * CClientShadowMgr::Name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CClientShadowMgr::Name(CClientShadowMgr *this)
{
  return "CCLientShadowMgr";
}

//------------------------------------------------------------------------------
// Address: 0x100BAEF0
// Name: public: virtual void CClientShadowMgr::SetShadowsDisabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::SetShadowsDisabled(CClientShadowMgr *this, bool bDisabled)
{
  ConVar::SetValue(this: (ConVar *)&r_shadows_gamecontrol.IConVar, value: !bDisabled);
}

//------------------------------------------------------------------------------
// Address: 0x100BAF40
// Name: private: void CClientShadowMgr::RemoveShadowFromDirtyList(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::RemoveShadowFromDirtyList(CClientShadowMgr *this, unsigned __int16 handle)
{
  int v3; // edi
  IClientRenderable *ClientRenderableFromHandle; // eax
  int v5; // eax
  int v6; // edi
  IClientRenderable *v7; // eax
  int v8; // eax

  v3 = CUtlRBTree<unsigned short,unsigned short,bool (__cdecl *)(unsigned short const &,unsigned short const &),CUtlMemory<UtlRBTreeNode_t<unsigned short,unsigned short>,unsigned short>>::Find(
         this: &this->m_DirtyShadows,
         search: &handle);
  if ( v3 != 0xFFFF )
  {
    ClientRenderableFromHandle = CClientEntityList::GetClientRenderableFromHandle(
                                   this: (CClientEntityList *)cl_entitylist.m_Index,
                                   hEnt: this->m_Shadows.m_Memory.m_pMemory[handle].m_Element.m_Entity);
    if ( ClientRenderableFromHandle != nullptr )
      ClientRenderableFromHandle->MarkShadowDirty(this: ClientRenderableFromHandle, a2: false);
    CUtlRBTree<unsigned short,unsigned short,bool (__cdecl *)(unsigned short const &,unsigned short const &),CUtlMemory<UtlRBTreeNode_t<unsigned short,unsigned short>,unsigned short>>::Unlink(
      this: &this->m_DirtyShadows,
      elem: v3);
    v5 = v3;
    this->m_DirtyShadows.m_Elements.m_pMemory[v5].m_Left = v3;
    this->m_DirtyShadows.m_Elements.m_pMemory[v5].m_Right = this->m_DirtyShadows.m_FirstFree;
    --this->m_DirtyShadows.m_NumElements;
    this->m_DirtyShadows.m_FirstFree = v3;
  }
  v6 = CUtlRBTree<unsigned short,unsigned short,bool (__cdecl *)(unsigned short const &,unsigned short const &),CUtlMemory<UtlRBTreeNode_t<unsigned short,unsigned short>,unsigned short>>::Find(
         this: &this->m_DirtyShadowsLeftOver,
         search: &handle);
  if ( v6 != 0xFFFF )
  {
    v7 = CClientEntityList::GetClientRenderableFromHandle(
           this: (CClientEntityList *)cl_entitylist.m_Index,
           hEnt: this->m_Shadows.m_Memory.m_pMemory[handle].m_Element.m_Entity);
    if ( v7 != nullptr )
      v7->MarkShadowDirty(this: v7, a2: false);
    CUtlRBTree<unsigned short,unsigned short,bool (__cdecl *)(unsigned short const &,unsigned short const &),CUtlMemory<UtlRBTreeNode_t<unsigned short,unsigned short>,unsigned short>>::Unlink(
      this: &this->m_DirtyShadowsLeftOver,
      elem: v6);
    v8 = v6;
    this->m_DirtyShadowsLeftOver.m_Elements.m_pMemory[v8].m_Left = v6;
    this->m_DirtyShadowsLeftOver.m_Elements.m_pMemory[v8].m_Right = this->m_DirtyShadowsLeftOver.m_FirstFree;
    --this->m_DirtyShadowsLeftOver.m_NumElements;
    this->m_DirtyShadowsLeftOver.m_FirstFree = v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BB080
// Name: public: virtual void CClientShadowMgr::DestroyShadow(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::DestroyShadow(CClientShadowMgr *this, unsigned __int16 handle)
{
  unsigned int v3; // esi
  IClientRenderable *ClientRenderableFromHandle; // eax
  int v5; // eax
  CClientAlphaProperty *v6; // eax
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *m_pMemory; // ebx
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *v8; // ebx

  if ( this->m_bUpdatingDirtyShadows )
  {
    CClientShadowMgr::QueueShadowForDestruction(this, handle);
  }
  else
  {
    CClientShadowMgr::RemoveShadowFromDirtyList(this, handle);
    v3 = handle;
    ClientRenderableFromHandle = CClientEntityList::GetClientRenderableFromHandle(
                                   this: (CClientEntityList *)cl_entitylist.m_Index,
                                   hEnt: this->m_Shadows.m_Memory.m_pMemory[v3].m_Element.m_Entity);
    if ( ClientRenderableFromHandle != nullptr )
    {
      v5 = ClientRenderableFromHandle->GetIClientUnknown(this: ClientRenderableFromHandle);
      v6 = (CClientAlphaProperty *)(*(int (__thiscall **)(int))(*(_DWORD *)v5 + 36))(a1: v5);
      if ( v6 != nullptr )
        CClientAlphaProperty::SetShadowHandle(this: v6, hShadowHandle: 0xFFFFu);
    }
    ((void (__stdcall *)(_DWORD))shadowmgr->DestroyShadow)(a1: this->m_Shadows.m_Memory.m_pMemory[v3].m_Element.m_ShadowHandle);
    if ( this->m_Shadows.m_Memory.m_pMemory[v3].m_Element.m_ClientLeafShadowHandle != 0xFFFF )
      g_pClientLeafSystem->RemoveShadow(
        this: g_pClientLeafSystem,
        a2: this->m_Shadows.m_Memory.m_pMemory[v3].m_Element.m_ClientLeafShadowHandle);
    m_pMemory = this->m_Shadows.m_Memory.m_pMemory;
    if ( this->m_RenderToTextureActive && (m_pMemory[v3].m_Element.m_Flags & 8) != 0 )
    {
      CTextureAllocator::DeallocateTexture(this: &this->m_ShadowAllocator, h: m_pMemory[v3].m_Element.m_ShadowTexture);
      m_pMemory[v3].m_Element.m_ShadowTexture = -1;
    }
    CUtlLinkedList<CClientShadowMgr::ClientShadow_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short>,unsigned short>>::Unlink(
      this: &this->m_Shadows,
      elem: handle);
    v8 = this->m_Shadows.m_Memory.m_pMemory;
    CTextureReference::~CTextureReference(this: &v8[v3].m_Element.m_ShadowDepthTexture);
    v8[v3].m_Next = this->m_Shadows.m_FirstFree;
    this->m_Shadows.m_FirstFree = handle;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BB290
// Name: public: virtual bool CShadowLeafEnum::EnumerateLeaf(int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShadowLeafEnum::EnumerateLeaf(CShadowLeafEnum *this, int leaf, int context)
{
  CUtlVector<int,CUtlMemoryFixedGrowable<int,512,int>>::InsertBefore(
    this: &this->m_LeafList,
    elem: this->m_LeafList.m_Size,
    src: &leaf);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100BB2B0
// Name: private: void CClientShadowMgr::BuildRenderToTextureShadow(class IClientRenderable __near *,unsigned short,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CClientShadowMgr::BuildRenderToTextureShadow(
        CClientShadowMgr *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        IClientRenderable *pRenderable,
        unsigned __int16 handle,
        const Vector *mins,
        const Vector *maxs)
{
  const Vector *v9; // esi
  const QAngle *v10; // eax
  float y; // xmm5_4
  float z; // xmm6_4
  int v13; // eax
  float *p_y; // ecx
  float v15; // xmm4_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm3_4
  float v20; // xmm4_4
  float x; // xmm3_4
  float v22; // xmm5_4
  float v23; // xmm0_4
  float v24; // xmm3_4
  float v25; // xmm1_4
  float v26; // xmm4_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  __int128 v29; // xmm0
  float v30; // xmm2_4
  float v31; // xmm1_4
  float v32; // xmm3_4
  float v33; // xmm7_4
  float v34; // xmm7_4
  float v35; // xmm7_4
  float v36; // xmm0_4
  const Vector *(__thiscall *GetRenderOrigin)(IClientRenderable *); // eax
  float v38; // xmm0_4
  int v39; // eax
  float v40; // ecx
  VMatrix *p_m_WorldToShadow; // esi
  float v42; // xmm1_4
  const int *v43; // xmm2_4
  float v44; // esi
  float *v45; // eax
  unsigned __int16 (__thiscall *GetShadowHandle)(IClientRenderable *); // edx
  unsigned __int16 v47; // ax
  ShadowType_t v48; // eax
  unsigned __int16 m_Flags; // ax
  int m_RenderToTextureActive; // eax
  float v51; // xmm1_4
  ISpatialQuery *v52; // eax
  char *v53; // eax
  IShadowMgr_vtbl *v54; // esi
  Vector *v55; // eax
  float v56; // ecx
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *m_pMemory; // ecx
  float v58; // xmm0_4
  float v59; // eax
  int *v60; // eax
  void **v63; // [esp+34h] [ebp-95Ch] BYREF
  int *p_m_nAllocationCount; // [esp+38h] [ebp-958h]
  int v65; // [esp+3Ch] [ebp-954h]
  CShadowLeafEnum leafList; // [esp+40h] [ebp-950h] BYREF
  __int128 matWorldToTexture_52; // [esp+894h] [ebp-FCh] OVERLAPPED
  Vector v68; // [esp+8A4h] [ebp-ECh] BYREF
  VMatrix v69; // [esp+8B4h] [ebp-DCh] BYREF
  char *v70; // [esp+8F8h] [ebp-98h]
  Vector v71; // [esp+8FCh] [ebp-94h] BYREF
  Vector localShadowDir; // [esp+908h] [ebp-88h] BYREF
  float v73; // [esp+914h] [ebp-7Ch]
  const int *pLeafList; // [esp+918h] [ebp-78h]
  Vector xvec; // [esp+91Ch] [ebp-74h] BYREF
  Vector worldOrigin; // [esp+928h] [ebp-68h] BYREF
  Vector2D size; // [esp+934h] [ebp-5Ch] BYREF
  Vector vec[3]; // [esp+93Ch] [ebp-54h] BYREF
  Vector yvec; // [esp+960h] [ebp-30h] BYREF
  Vector vecShadowDir; // [esp+96Ch] [ebp-24h] BYREF
  float maxHeight; // [esp+978h] [ebp-18h]
  Vector org; // [esp+97Ch] [ebp-14h]
  int nCount; // [esp+988h] [ebp-8h]
  int retaddr; // [esp+990h] [ebp+0h]

  org.z = a2;
  nCount = retaddr;
  if ( cl_drawshadowtexture.m_pParent != nullptr && cl_drawshadowtexture.m_pParent->m_Value.m_nValue != 0 )
  {
    v9 = mins;
    CClientShadowMgr::DrawRenderToTextureDebugInfo(this, pRenderable, mins, maxs);
  }
  else
  {
    v9 = mins;
  }
  v10 = (const QAngle *)((int (__thiscall *)(IClientRenderable *, float *, Vector *, Vector *, int, int))pRenderable->GetRenderAngles)(
                          a1: pRenderable,
                          a2: &worldOrigin.z,
                          a3: vec,
                          a4: &vec[1],
                          a5: a3,
                          a6: a4);
  AngleVectors(
    angles: v10,
    forward: (Vector *)LODWORD(maxHeight),
    right: (Vector *)LODWORD(org.x),
    up: (Vector *)LODWORD(org.y));
  vec[0].x = vec[0].x * -1.0;
  vec[0].y = vec[0].y * -1.0;
  vec[0].z = vec[0].z * -1.0;
  yvec = *CClientShadowMgr::GetShadowDirection(this, shadowHandle: handle);
  y = yvec.y;
  z = yvec.z;
  v71.x = (float)((float)(yvec.x * worldOrigin.z) + (float)(size.x * yvec.y)) + (float)(size.y * yvec.z);
  v71.y = (float)((float)(vec[0].x * yvec.x) + (float)(vec[0].y * yvec.y)) + (float)(vec[0].z * yvec.z);
  v71.z = (float)((float)(vec[1].x * yvec.x) + (float)(vec[1].y * yvec.y)) + (float)(vec[1].z * yvec.z);
  vecShadowDir.y = maxs->x - v9->x;
  vecShadowDir.z = maxs->y - v9->y;
  maxHeight = maxs->z - v9->z;
  org.y = 0.0;
  v13 = 0;
  p_y = &size.y;
  while ( 1 )
  {
    v15 = (float)((float)(*(p_y - 2) * yvec.x) + (float)(*(p_y - 1) * y)) + (float)(*p_y * z);
    v16 = *(&vecShadowDir.y + v13);
    v17 = (float)(*(p_y - 2) - (float)(v15 * yvec.x)) * v16;
    v18 = (float)(*(p_y - 1) - (float)(y * v15)) * v16;
    v19 = (float)(*p_y - (float)(z * v15)) * v16;
    if ( (float)((float)((float)(v18 * v18) + (float)(v17 * v17)) + (float)(v19 * v19)) > org.y )
    {
      org.y = (float)((float)(v18 * v18) + (float)(v17 * v17)) + (float)(v19 * v19);
      vec[2].x = v17;
      vec[2].y = v18;
      vec[2].z = v19;
    }
    ++v13;
    p_y += 3;
    if ( v13 == 3 )
      break;
    z = yvec.z;
    y = yvec.y;
  }
  VectorNormalize(vec: &vec[2]);
  *(float *)&pLeafList = (float)(yvec.y * vec[2].x) - (float)(vec[2].y * yvec.x);
  v73 = (float)(vec[2].z * yvec.x) - (float)(yvec.z * vec[2].x);
  localShadowDir.z = (float)(vec[2].y * yvec.z) - (float)(vec[2].z * yvec.y);
  v20 = maxs->y;
  x = maxs->x;
  v22 = maxs->z;
  worldOrigin.x = (float)((float)((float)(fabs(
                                            (float)((float)(vec[0].x * localShadowDir.z) + (float)(vec[0].y * v73))
                                          + (float)(vec[0].z * *(float *)&pLeafList))
                                        * vecShadowDir.z)
                                + (float)(fabs(
                                            (float)((float)(v73 * size.x) + (float)(localShadowDir.z * worldOrigin.z))
                                          + (float)(*(float *)&pLeafList * size.y))
                                        * vecShadowDir.y))
                        + (float)(fabs(
                                    (float)((float)(vec[1].x * localShadowDir.z) + (float)(vec[1].y * v73))
                                  + (float)(vec[1].z * *(float *)&pLeafList))
                                * maxHeight))
                + 4.0;
  v23 = v9->x + x;
  v24 = x - v9->x;
  worldOrigin.y = (float)((float)((float)(fabs(
                                            (float)((float)(vec[0].x * vec[2].x) + (float)(vec[0].y * vec[2].y))
                                          + (float)(vec[0].z * vec[2].z))
                                        * vecShadowDir.z)
                                + (float)(fabs(
                                            (float)((float)(vec[2].y * size.x) + (float)(vec[2].x * worldOrigin.z))
                                          + (float)(vec[2].z * size.y))
                                        * vecShadowDir.y))
                        + (float)(fabs(
                                    (float)((float)(vec[1].x * vec[2].x) + (float)(vec[1].y * vec[2].y))
                                  + (float)(vec[1].z * vec[2].z))
                                * maxHeight))
                + 4.0;
  v25 = v20;
  v26 = v20 - v9->y;
  v27 = v25 + v9->y;
  vecShadowDir.y = v23 * 0.5;
  v28 = v22 + v9->z;
  v29 = 0;
  *(float *)&v29 = fsqrt(
                     (float)((float)(v26 * v26) + (float)((float)(v22 - v9->z) * (float)(v22 - v9->z)))
                   + (float)(v24 * v24));
  matWorldToTexture_52 = v29;
  v30 = v28 * 0.5;
  v31 = v27 * 0.5;
  v32 = *(float *)&v29 * 0.5;
  if ( v71.x <= 0.0 )
    v33 = v71.x * maxs->x;
  else
    v33 = v9->x * v71.x;
  org.y = v33
        + COERCE_FLOAT(
            COERCE_UNSIGNED_INT((float)((float)(v71.x * vecShadowDir.y) + (float)(v71.y * v31)) + (float)(v71.z * v30))
          ^ _mask__NegFloat_);
  if ( v71.y <= 0.0 )
    v34 = v71.y * maxs->y;
  else
    v34 = v9->y * v71.y;
  v35 = v34 + org.y;
  if ( v71.z <= 0.0 )
    v36 = maxs->z;
  else
    v36 = v9->z;
  GetRenderOrigin = pRenderable->GetRenderOrigin;
  v38 = (float)(v36 * v71.z) + v35;
  vecShadowDir.y = (float)(v71.x * v38) + vecShadowDir.y;
  vecShadowDir.z = (float)(v71.y * v38) + v31;
  maxHeight = (float)(v71.z * v38) + v30;
  org.y = v32 - v38;
  v39 = (int)GetRenderOrigin(this: pRenderable);
  *(_QWORD *)&xvec.x = *(_QWORD *)v39;
  v40 = *(float *)(v39 + 8);
  p_m_WorldToShadow = &this->m_Shadows.m_Memory.m_pMemory[handle].m_Element.m_WorldToShadow;
  xvec.x = (float)(vec[1].x * maxHeight)
         + (float)((float)(vec[0].x * vecShadowDir.z) + (float)((float)(worldOrigin.z * vecShadowDir.y) + xvec.x));
  xvec.z = (float)(vec[1].z * maxHeight)
         + (float)((float)(vec[0].z * vecShadowDir.z) + (float)((float)(size.y * vecShadowDir.y) + v40));
  xvec.y = (float)(vec[1].y * maxHeight)
         + (float)((float)(vec[0].y * vecShadowDir.z) + (float)((float)(size.x * vecShadowDir.y) + xvec.y));
  p_m_WorldToShadow->m[0][0] = localShadowDir.z;
  p_m_WorldToShadow->m[1][0] = v73;
  p_m_WorldToShadow->m[2][0] = *(float *)&pLeafList;
  p_m_WorldToShadow->m[0][1] = vec[2].x;
  p_m_WorldToShadow->m[1][1] = vec[2].y;
  p_m_WorldToShadow->m[2][1] = vec[2].z;
  p_m_WorldToShadow->m[0][2] = yvec.x;
  p_m_WorldToShadow->m[1][2] = yvec.y;
  LODWORD(org.y) = p_m_WorldToShadow;
  LODWORD(org.x) = p_m_WorldToShadow;
  LODWORD(localShadowDir.x) = 276 * handle;
  p_m_WorldToShadow->m[2][2] = yvec.z;
  MatrixTranspose(src: (const VMatrix *)LODWORD(org.x), dst: (VMatrix *)LODWORD(org.y));
  Vector3DMultiply(src1: p_m_WorldToShadow, src2: &xvec, dst: (Vector *)&localShadowDir.z);
  v42 = v73;
  v43 = pLeafList;
  p_m_WorldToShadow->m[0][3] = localShadowDir.z * -1.0;
  p_m_WorldToShadow->m[1][3] = v42 * -1.0;
  p_m_WorldToShadow->m[2][3] = *(float *)&v43 * -1.0;
  p_m_WorldToShadow->m[3][2] = 0.0;
  p_m_WorldToShadow->m[3][1] = 0.0;
  p_m_WorldToShadow->m[3][0] = 0.0;
  p_m_WorldToShadow->m[3][3] = 1.0;
  v44 = localShadowDir.x;
  MatrixBuildScale(
    dst: &v69,
    x: COERCE_UNSIGNED_INT(1.0 / worldOrigin.x),
    y: (unsigned int)&this->m_Shadows.m_Memory.m_pMemory->m_Element.m_WorldToShadow + LODWORD(localShadowDir.x),
    z: 1.0);
  v69.m[1][3] = 0.5;
  v69.m[0][3] = 0.5;
  MatrixMultiply(src1: &v69, src2: (VMatrix *)LODWORD(org.x), dst: (VMatrix *)&leafList.m_LeafList.m_Size);
  v45 = (float *)((char *)&this->m_Shadows.m_Memory.m_pMemory->m_Element.m_WorldSize.x + LODWORD(v44));
  *v45 = worldOrigin.x;
  v45[1] = worldOrigin.y;
  MatrixCopy(
    src: (const VMatrix *)&leafList.m_LeafList.m_Size,
    dst: (VMatrix *)((char *)&this->m_Shadows.m_Memory.m_pMemory->m_Element.m_WorldToTexture + LODWORD(v44)));
  GetShadowHandle = pRenderable->GetShadowHandle;
  vecShadowDir.x = this->m_flShadowCastDist;
  v47 = GetShadowHandle(this: pRenderable);
  if ( v47 == 0xFFFF )
  {
    v48 = SHADOWS_NONE;
  }
  else
  {
    m_Flags = this->m_Shadows.m_Memory.m_pMemory[v47].m_Element.m_Flags;
    if ( (m_Flags & 8) != 0 )
      m_RenderToTextureActive = this->m_RenderToTextureActive;
    else
      m_RenderToTextureActive = (m_Flags & 0x20) != 0 ? 3 : 0;
    v48 = m_RenderToTextureActive + 1;
  }
  pRenderable->GetShadowCastDistance(this: pRenderable, a2: (float *)&vecShadowDir, a3: v48);
  v68 = xvec;
  v69.m[0][0] = yvec.x * (float)(vecShadowDir.x + org.y);
  v51 = yvec.y * (float)(vecShadowDir.x + org.y);
  vecShadowDir.x = vecShadowDir.x + org.y;
  v69.m[0][1] = v51;
  memset(v69.m[1], 0, 12);
  org.x = worldOrigin.y * worldOrigin.y;
  v69.m[0][2] = yvec.z * vecShadowDir.x;
  p_m_nAllocationCount = &leafList.m_LeafList.m_Memory.m_nAllocationCount;
  leafList.m_LeafList.m_Memory.m_pFixedMemory[510] = (int)&leafList.m_LeafList.m_Memory.m_nAllocationCount;
  leafList.m_LeafList.m_Memory.m_pMemory = nullptr;
  leafList.m_LeafList.m_Memory.m_pFixedMemory[509] = 0;
  v69.m[3][0] = 0.0;
  v63 = &CShadowLeafEnum::`vftable';
  v65 = 512;
  leafList.__vftable = (CShadowLeafEnum_vtbl *)-1;
  v69.m[2][0] = fsqrt((float)(worldOrigin.y * worldOrigin.y) + (float)(worldOrigin.x * worldOrigin.x)) * 0.5;
  v69.m[2][1] = v69.m[2][0];
  v69.m[2][2] = v69.m[2][0];
  LOWORD(v69.m[3][1]) = 256;
  v52 = engine->GetBSPTreeQuery(this: engine);
  v52->EnumerateLeavesAlongRay(this: v52, a2: (const Ray_t *)&v68, a3: (ISpatialLeafEnumerator *)&v63, a4: 0);
  LODWORD(org.x) = leafList.m_LeafList.m_Memory.m_pFixedMemory[509];
  LODWORD(localShadowDir.y) = p_m_nAllocationCount;
  if ( r_shadow_deferred.m_pParent == nullptr || r_shadow_deferred.m_pParent->m_Value.m_nValue == 0 )
  {
    v53 = (char *)this->m_Shadows.m_Memory.m_pMemory + LODWORD(v44);
    v54 = shadowmgr->__vftable;
    v70 = v53;
    *(float *)&v55 = COERCE_FLOAT((int)pRenderable->GetRenderOrigin(this: pRenderable));
    v56 = org.x;
    LODWORD(org.y) = v55;
    org.x = 240.0;
    maxHeight = *(float *)&v55;
    vecShadowDir.z = vecShadowDir.x;
    vecShadowDir.y = localShadowDir.y;
    vecShadowDir.x = v56;
    LODWORD(yvec.z) = &worldOrigin;
    LODWORD(yvec.y) = &leafList.m_LeafList.m_Size;
    LODWORD(yvec.x) = &yvec;
    ((void (__thiscall *)(IShadowMgr *, _DWORD, Vector *))v54->ProjectShadow)(
      a1: shadowmgr,
      a2: *((unsigned __int16 *)v70 + 2),
      a3: &xvec);
    CClientShadowMgr::ComputeExtraClipPlanes(
      this,
      pRenderable,
      handle,
      vec: (Vector *)&worldOrigin.z,
      mins,
      maxs,
      localShadowDir: &v71);
    v44 = localShadowDir.x;
  }
  *(float *)((char *)&this->m_Shadows.m_Memory.m_pMemory->m_Element.m_MaxDist + LODWORD(v44)) = vecShadowDir.x;
  m_pMemory = this->m_Shadows.m_Memory.m_pMemory;
  v58 = org.y;
  org.y = localShadowDir.y;
  v59 = org.x;
  *(float *)((char *)&m_pMemory->m_Element.m_FalloffStart + LODWORD(v44)) = v58;
  ((void (__stdcall *)(_DWORD, _DWORD))g_pClientLeafSystem->ProjectShadow)(
    a1: *(unsigned __int16 *)((char *)&this->m_Shadows.m_Memory.m_pMemory->m_Element.m_ClientLeafShadowHandle + LODWORD(v44)),
    a2: LODWORD(v59));
  v60 = p_m_nAllocationCount;
  leafList.m_LeafList.m_Memory.m_pFixedMemory[509] = 0;
  if ( (int)leafList.__vftable >= 0 )
  {
    if ( p_m_nAllocationCount != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_nAllocationCount);
      v60 = nullptr;
      p_m_nAllocationCount = nullptr;
    }
    v65 = 0;
  }
  leafList.m_LeafList.m_Memory.m_pFixedMemory[510] = (int)v60;
  if ( (int)leafList.__vftable >= 0 && v60 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v60);
}

//------------------------------------------------------------------------------
// Address: 0x100BBCF0
// Name: private: void CClientShadowMgr::BuildFlashlight(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::BuildFlashlight(CClientShadowMgr *this, int handle)
{
  IMatRenderContext *(__thiscall *GetRenderContext)(IMaterialSystem *); // edx
  IMatRenderContext *m_pObject; // edi
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *v5; // esi
  int m_nValue; // eax
  bool v7; // zf
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // eax
  bool v10; // bl
  ISpatialQuery *v11; // eax
  C_BaseCombatWeapon *v12; // eax
  C_BaseEntity *MoveChild; // ebx
  IVModelInfoClient_vtbl *v14; // edi
  int v15; // eax
  int v16; // eax
  unsigned int v17; // ecx
  IHandleEntity *v18; // eax
  C_BaseCombatWeapon *v19; // eax
  IVModelInfoClient_vtbl *v20; // esi
  int v21; // eax
  int v22; // eax
  C_BaseCombatWeapon *v23; // eax
  IClientRenderable *v24; // eax
  C_BaseCombatWeapon *v25; // eax
  IClientRenderable *v26; // eax
  CShadowLeafEnum leafList; // [esp+Ch] [ebp-84Ch] BYREF
  Vector pMins; // [esp+828h] [ebp-30h] BYREF
  Vector pMaxs; // [esp+834h] [ebp-24h] BYREF
  const int *pLeafList; // [esp+840h] [ebp-18h]
  CMatRenderContextPtr pRenderContext; // [esp+844h] [ebp-14h]
  int nCount; // [esp+848h] [ebp-10h]
  CClientShadowMgr *v33; // [esp+84Ch] [ebp-Ch]
  CHandle<C_BaseCombatWeapon> *p_m_hTargetEntity; // [esp+850h] [ebp-8h]
  bool bLightSpecificEntity; // [esp+856h] [ebp-2h]
  bool bLightModels; // [esp+857h] [ebp-1h]

  GetRenderContext = g_pMaterialSystem->GetRenderContext;
  v33 = this;
  m_pObject = GetRenderContext(this: g_pMaterialSystem);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  v5 = &this->m_Shadows.m_Memory.m_pMemory[(unsigned __int16)handle];
  if ( ((unsigned __int8 (*)(void))shadowmgr->SinglePassFlashlightModeEnabled)() != 0
    && !m_pObject->IsCullingEnabledForSinglePassFlashlight(this: m_pObject) )
  {
    ((void (__stdcall *)(_DWORD, VMatrix *, _DWORD, _DWORD))shadowmgr->ProjectFlashlight)(
      a1: v5->m_Element.m_ShadowHandle,
      a2: &v5->m_Element.m_WorldToShadow,
      a3: 0,
      a4: 0);
    goto LABEL_50;
  }
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CClientShadowMgr::BuildFlashlight",
    a3: 0,
    a4: "Flashlight Shadows",
    a5: false,
    a6: 4);
  if ( r_flashlightmodels.m_pParent != nullptr )
    m_nValue = r_flashlightmodels.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v7 = m_nValue == 0;
  p_m_hTargetEntity = (CHandle<C_BaseCombatWeapon> *)&v5->m_Element.m_hTargetEntity;
  m_Index = v5->m_Element.m_hTargetEntity.m_Index;
  bLightModels = !v7;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v10 = (v5->m_Element.m_Flags & 0x400) != 0;
  v7 = (v5->m_Element.m_Flags & 0x400) == 0;
  bLightSpecificEntity = m_pEntity != nullptr;
  nCount = 0;
  pLeafList = nullptr;
  leafList.__vftable = (CShadowLeafEnum_vtbl *)&CShadowLeafEnum::`vftable';
  leafList.m_LeafList.m_Memory.m_pMemory = leafList.m_LeafList.m_Memory.m_pFixedMemory;
  leafList.m_LeafList.m_Memory.m_nAllocationCount = 512;
  leafList.m_LeafList.m_Memory.m_nGrowSize = -1;
  leafList.m_LeafList.m_Memory.m_nMallocGrowSize = 0;
  leafList.m_LeafList.m_Size = 0;
  leafList.m_LeafList.m_pElements = leafList.m_LeafList.m_Memory.m_pFixedMemory;
  if ( v7 && (!bLightModels || m_pEntity != nullptr) )
    goto LABEL_19;
  ((void (__stdcall *)(_DWORD))shadowmgr->GetFlashlightState)(a1: v5->m_Element.m_ShadowHandle);
  CalculateAABBFromProjectionMatrix(worldToVolume: &v5->m_Element.m_WorldToShadow, &pMins, &pMaxs);
  v11 = engine->GetBSPTreeQuery(this: engine);
  v11->EnumerateLeavesInBox(this: v11, a2: &pMins, a3: &pMaxs, a4: &leafList, a5: 0);
  nCount = leafList.m_LeafList.m_Size;
  pLeafList = leafList.m_LeafList.m_Memory.m_pMemory;
  if ( !v10 )
  {
    m_pObject = pRenderContext.m_pObject;
LABEL_19:
    ((void (__stdcall *)(_DWORD, _DWORD))shadowmgr->EnableShadow)(a1: v5->m_Element.m_ShadowHandle, a2: 0);
    ((void (__stdcall *)(_DWORD, int))shadowmgr->EnableShadow)(a1: v5->m_Element.m_ShadowHandle, a2: 1);
    goto LABEL_20;
  }
  ((void (__stdcall *)(_DWORD, VMatrix *, int, int *))shadowmgr->ProjectFlashlight)(
    a1: v5->m_Element.m_ShadowHandle,
    a2: &v5->m_Element.m_WorldToShadow,
    a3: leafList.m_LeafList.m_Size,
    a4: leafList.m_LeafList.m_Memory.m_pMemory);
  m_pObject = pRenderContext.m_pObject;
LABEL_20:
  if ( (v5->m_Element.m_Flags & 4) != 0 || !bLightModels )
  {
    CUtlVector<int,CUtlMemoryFixedGrowable<int,512,int>>::~CUtlVector<int,CUtlMemoryFixedGrowable<int,512,int>>(this: &leafList.m_LeafList);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    if ( m_pObject == nullptr )
      return;
    goto LABEL_50;
  }
  if ( bLightSpecificEntity )
  {
    v12 = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: p_m_hTargetEntity);
    MoveChild = C_BaseEntity::FirstMoveChild(this: v12);
    if ( MoveChild != nullptr )
    {
      while ( 1 )
      {
        v14 = modelinfo->__vftable;
        v15 = (int)MoveChild->GetModel(this: &MoveChild->IClientRenderable);
        v16 = v14->GetModelType(this: modelinfo, a2: (const struct model_t *)v15);
        if ( v16 == 1 )
        {
          v33->AddShadowToReceiver(
            this: v33,
            a2: handle,
            a3: &MoveChild->IClientRenderable,
            a4: SHADOW_RECEIVER_BRUSH_MODEL);
        }
        else if ( v16 == 3 )
        {
          v33->AddShadowToReceiver(
            this: v33,
            a2: handle,
            a3: &MoveChild->IClientRenderable,
            a4: SHADOW_RECEIVER_STUDIO_MODEL);
        }
        v17 = MoveChild->m_pMovePeer.m_Index;
        if ( v17 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v17].m_SerialNumber != HIWORD(v17) )
          v18 = nullptr;
        else
          v18 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v17].m_pEntity;
        nCount = (int)v18;
        if ( v18 == nullptr )
          break;
        MoveChild = (C_BaseEntity *)nCount;
      }
      m_pObject = pRenderContext.m_pObject;
    }
    v19 = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: p_m_hTargetEntity);
    v20 = modelinfo->__vftable;
    v21 = (int)v19->GetModel(this: &v19->IClientRenderable);
    v22 = v20->GetModelType(this: modelinfo, a2: (const struct model_t *)v21);
    if ( v22 == 1 )
    {
      v23 = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: p_m_hTargetEntity);
      if ( v23 != nullptr )
        v24 = &v23->IClientRenderable;
      else
        v24 = nullptr;
      ((void (__stdcall *)(int, IClientRenderable *, _DWORD))v33->AddShadowToReceiver)(a1: handle, a2: v24, a3: 0);
    }
    else if ( v22 == 3 )
    {
      v25 = CHandle<C_PointCommentaryNode>::operator C_PointCommentaryNode *(this: p_m_hTargetEntity);
      if ( v25 != nullptr )
        v26 = &v25->IClientRenderable;
      else
        v26 = nullptr;
      ((void (__stdcall *)(int, IClientRenderable *, int))v33->AddShadowToReceiver)(a1: handle, a2: v26, a3: 2);
    }
  }
  else
  {
    ((void (__stdcall *)(_DWORD, int, const int *))g_pClientLeafSystem->ProjectFlashlight)(
      a1: v5->m_Element.m_ClientLeafShadowHandle,
      a2: nCount,
      a3: pLeafList);
  }
  CUtlVector<int,CUtlMemoryFixedGrowable<int,512,int>>::~CUtlVector<int,CUtlMemoryFixedGrowable<int,512,int>>(this: &leafList.m_LeafList);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  if ( m_pObject != nullptr )
  {
LABEL_50:
    m_pObject->EndRender(this: m_pObject);
    m_pObject->Release(this: m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BC0A0
// Name: private: void CClientShadowMgr::FlushLeftOverDirtyShadows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::FlushLeftOverDirtyShadows(CClientShadowMgr *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<unsigned short,unsigned short,bool (__cdecl *)(unsigned short const &,unsigned short const &),CUtlMemory<UtlRBTreeNode_t<unsigned short,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_DirtyShadowsLeftOver);
        i != 0xFFFF;
        i = CUtlRBTree<unsigned short,unsigned short,bool (__cdecl *)(unsigned short const &,unsigned short const &),CUtlMemory<UtlRBTreeNode_t<unsigned short,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_DirtyShadowsLeftOver,
              i) )
  {
    CUtlRBTree<unsigned short,unsigned short,bool (__cdecl *)(unsigned short const &,unsigned short const &),CUtlMemory<UtlRBTreeNode_t<unsigned short,unsigned short>,unsigned short>>::InsertIfNotFound(
      this: &this->m_DirtyShadows,
      insert: &this->m_DirtyShadowsLeftOver.m_Elements.m_pMemory[i].m_Data);
  }
  CUtlRBTree<unsigned short,unsigned short,bool (__cdecl *)(unsigned short const &,unsigned short const &),CUtlMemory<UtlRBTreeNode_t<unsigned short,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_DirtyShadowsLeftOver);
}

//------------------------------------------------------------------------------
// Address: 0x100BC110
// Name: public: virtual void CClientShadowMgr::AddToDirtyShadowList(unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CClientShadowMgr::AddToDirtyShadowList(
        CClientShadowMgr *this@<ecx>,
        const char *a2@<edi>,
        unsigned __int16 handle,
        BOOL bForce)
{
  DWORD CurrentThreadId; // eax
  BOOL v6; // ebx
  QAngle *p_m_LastAngles; // eax
  IClientRenderable *ParentShadowEntity; // eax

  if ( !this->m_bUpdatingDirtyShadows && handle != 0xFFFF )
  {
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != g_DirtyListAddMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&g_DirtyListAddMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &g_DirtyListAddMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++g_DirtyListAddMutex.m_depth;
    }
    CUtlRBTree<unsigned short,unsigned short,bool (__cdecl *)(unsigned short const &,unsigned short const &),CUtlMemory<UtlRBTreeNode_t<unsigned short,unsigned short>,unsigned short>>::Insert(
      this: &this->m_DirtyShadows,
      a2,
      insert: &handle);
    v6 = bForce;
    if ( bForce )
    {
      p_m_LastAngles = &this->m_Shadows.m_Memory.m_pMemory[handle].m_Element.m_LastAngles;
      p_m_LastAngles->x = 3.4028235e38;
      p_m_LastAngles->y = 3.4028235e38;
      p_m_LastAngles->z = 3.4028235e38;
    }
    ParentShadowEntity = CClientShadowMgr::GetParentShadowEntity(this, handle);
    if ( ParentShadowEntity != nullptr )
      this->AddToDirtyShadowList(this, a2: ParentShadowEntity, a3: v6);
    if ( --g_DirtyListAddMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&g_DirtyListAddMutex, 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BC1F0
// Name: public: virtual void CClientShadowMgr::ComputeShadowTextures(class CViewSetup const __near &,int,struct WorldListLeafData_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CClientShadowMgr::ComputeShadowTextures(
        CClientShadowMgr *this@<ecx>,
        int a2@<esi>,
        const CViewSetup *view,
        int leafCount,
        WorldListLeafData_t *pLeafList)
{
  int v5; // ebx
  IMDLCache *v7; // esi
  IMDLCache_vtbl *v8; // eax
  IMDLCache *v9; // ecx
  int v10; // esi
  int i; // edi
  VisibleShadowInfo_t *v12; // eax
  IMDLCache *cacheCriticalSection; // [esp+8Ch] [ebp-8h]
  MaterialHeightClipMode_t oldHeightClipMode; // [esp+9Ch] [ebp+8h]
  int nCount; // [esp+A0h] [ebp+Ch]
  int nMaxShadows; // [esp+A4h] [ebp+10h]

  v5 = 0;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CClientShadowMgr::ComputeShadowTextures",
    a3: 0,
    a4: "Shadow_Rendering",
    a5: false,
    a6: 4);
  if ( this->m_RenderToTextureActive
    && r_shadows.m_pParent != nullptr
    && r_shadows.m_pParent->m_Value.m_nValue != 0
    && r_shadows_gamecontrol.m_pParent != nullptr
    && r_shadows_gamecontrol.m_pParent->m_Value.m_nValue != 0 )
  {
    v7 = mdlcache;
    cacheCriticalSection = mdlcache;
    mdlcache->BeginLock(this: mdlcache);
    nCount = CVisibleShadowList::FindShadows(this: &s_VisibleShadowList, pView: view, nLeafCount: leafCount, pLeafList);
    if ( nCount != 0 )
    {
      v10 = ((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(a1: materials, a2);
      if ( v10 != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 8))(a1: v10);
      (*(void (__thiscall **)(int, int, int, int, _DWORD))(*(_DWORD *)v10 + 296))(
        a1: v10,
        a2: 255,
        a3: 255,
        a4: 255,
        a5: 0);
      oldHeightClipMode = (*(int (__thiscall **)(int))(*(_DWORD *)v10 + 344))(a1: v10);
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v10 + 168))(a1: v10, a2: 0);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v10 + 80))(a1: v10, a2: 1);
      (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 84))(a1: v10);
      (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 124))(a1: v10);
      (*(void (__thiscall **)(int, int, int, int))(*(_DWORD *)v10 + 148))(
        a1: v10,
        a2: 1065353216,
        a3: -1082130432,
        a4: 1065353216);
      (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, int, _DWORD, int, _DWORD, _DWORD))(*(_DWORD *)v10 + 128))(
        a1: v10,
        a2: 0,
        a3: 0,
        a4: 0,
        a5: 0,
        a6: 0,
        a7: 1072693248,
        a8: 0,
        a9: 1072693248,
        a10: 0,
        a11: -1060927616,
        a12: 0,
        a13: 0);
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v10 + 80))(a1: v10, a2: 0);
      (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 84))(a1: v10);
      (*(void (__thiscall **)(int, ITexture *))(*(_DWORD *)v10 + 436))(
        a1: v10,
        a2: this->m_ShadowAllocator.m_TexturePage.m_pTexture);
      if ( this->m_bRenderTargetNeedsClear )
      {
        (*(void (__thiscall **)(int, int, _DWORD, _DWORD))(*(_DWORD *)v10 + 48))(a1: v10, a2: 1, a3: 0, a4: 0);
        this->m_bRenderTargetNeedsClear = false;
      }
      if ( r_shadowmaxrendered.m_pParent != nullptr )
        nMaxShadows = r_shadowmaxrendered.m_pParent->m_Value.m_nValue;
      else
        nMaxShadows = 0;
      for ( i = 0; i < nCount; ++i )
      {
        v12 = &s_VisibleShadowList.m_ShadowsInView.m_Memory.m_pMemory[s_VisibleShadowList.m_PriorityIndex.m_Memory.m_pMemory[i]];
        if ( v5 >= nMaxShadows )
        {
          CClientShadowMgr::DrawRenderToTextureShadowLOD(this, nSlot: 0, clientShadowHandle: v12->m_hShadow);
        }
        else if ( CClientShadowMgr::DrawRenderToTextureShadow(
                    this,
                    nSlot: 0.0,
                    clientShadowHandle: v12->m_hShadow,
                    flArea: LODWORD(v12->m_flArea)) )
        {
          ++v5;
        }
      }
      (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 444))(a1: v10);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v10 + 80))(a1: v10, a2: 1);
      (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 88))(a1: v10);
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v10 + 80))(a1: v10, a2: 0);
      (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 88))(a1: v10);
      (*(void (__thiscall **)(int, MaterialHeightClipMode_t))(*(_DWORD *)v10 + 168))(a1: v10, a2: oldHeightClipMode);
      (*(void (__thiscall **)(int, MaterialHeightClipMode_t))(*(_DWORD *)v10 + 168))(a1: v10, a2: oldHeightClipMode);
      (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v10 + 292))(a1: v10, a2: 0, a3: 0, a4: 0);
      (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 12))(a1: v10);
      (*(void (__thiscall **)(int))(*(_DWORD *)v10 + 4))(a1: v10);
      v9 = cacheCriticalSection;
      v8 = cacheCriticalSection->__vftable;
    }
    else
    {
      v8 = v7->__vftable;
      v9 = v7;
    }
    ((void (__fastcall *)(IMDLCache *))v8->EndLock)(a1: v9);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BC4D0
// Name: public: void CTextureAllocator::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureAllocator::Reset(CTextureAllocator *this)
{
  UtlLinkedListElem_t<CTextureAllocator::TextureInfo_t,unsigned short> *m_pMemory; // eax
  IMemAlloc_vtbl *v3; // edx
  UtlLinkedListElem_t<CTextureAllocator::TextureInfo_t,unsigned short> *v4; // eax
  CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::ListElem_t *v5; // eax
  CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::ListElem_t *v6; // eax
  unsigned __int16 v7; // ax
  unsigned __int16 v8; // bx
  unsigned __int16 v9; // cx
  int v10; // eax
  bool v11; // zf
  int i; // edi
  int v13; // [esp+8h] [ebp-8h]
  CTextureAllocator::Cache_t *m_Cache; // [esp+Ch] [ebp-4h]

  CTextureAllocator::DeallocateAllTextures(this);
  if ( this->m_Textures.m_Memory.m_nAllocationCount < 256 && this->m_Textures.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_Textures.m_Memory.m_pMemory;
    this->m_Textures.m_Memory.m_nAllocationCount = 256;
    v3 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v4 = (UtlLinkedListElem_t<CTextureAllocator::TextureInfo_t,unsigned short> *)((int (__stdcall *)(UtlLinkedListElem_t<CTextureAllocator::TextureInfo_t,unsigned short> *, int))v3->Realloc_2)(
                                                                                     a1: m_pMemory,
                                                                                     a2: 2560);
    else
      v4 = (UtlLinkedListElem_t<CTextureAllocator::TextureInfo_t,unsigned short> *)((int (__stdcall *)(int))v3->Alloc_2)(a1: 2560);
    this->m_Textures.m_Memory.m_pMemory = v4;
  }
  this->m_Textures.m_pElements = this->m_Textures.m_Memory.m_pMemory;
  if ( this->m_Fragments.m_Memory.m_nAllocationCount < 256 && this->m_Fragments.m_Memory.m_nGrowSize >= 0 )
  {
    v5 = this->m_Fragments.m_Memory.m_pMemory;
    this->m_Fragments.m_Memory.m_nAllocationCount = 256;
    if ( v5 != nullptr )
      v6 = (CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::ListElem_t *)_g_pMemAlloc->Realloc_2(
                                                                                            this: _g_pMemAlloc,
                                                                                            a2: v5,
                                                                                            a3: 4096);
    else
      v6 = (CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::ListElem_t *)_g_pMemAlloc->Alloc_2(
                                                                                            this: _g_pMemAlloc,
                                                                                            a2: 4096);
    this->m_Fragments.m_Memory.m_pMemory = v6;
  }
  this->m_Fragments.m_pElements = this->m_Fragments.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_Blocks[0].m_FragmentPower = 327684;
  *(_DWORD *)&this->m_Blocks[2].m_FragmentPower = 393222;
  *(_DWORD *)&this->m_Blocks[4].m_FragmentPower = 458759;
  *(_DWORD *)&this->m_Blocks[6].m_FragmentPower = 458759;
  *(_DWORD *)&this->m_Blocks[8].m_FragmentPower = 458759;
  *(_DWORD *)&this->m_Blocks[10].m_FragmentPower = 524296;
  *(_DWORD *)&this->m_Blocks[12].m_FragmentPower = 524296;
  *(_DWORD *)&this->m_Blocks[14].m_FragmentPower = 524296;
  m_Cache = this->m_Cache;
  v13 = 9;
  do
  {
    v7 = CUtlLinkedList<CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CTextureAllocator::FragmentInfo_t,unsigned short>::List_t,unsigned short>,unsigned short>>::AllocInternal(
           this: &this->m_Fragments.m_List,
           multilist: false);
    v8 = v7;
    v9 = -1;
    if ( v7 != 0xFFFF )
    {
      CUtlLinkedList<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
        this: (CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *)&this->m_Fragments.m_List,
        before: 0xFFFFu,
        elem: v7);
      v9 = v8;
    }
    v10 = v9;
    this->m_Fragments.m_List.m_Memory.m_pMemory[v10].m_Element.m_Tail = -1;
    this->m_Fragments.m_List.m_Memory.m_pMemory[v10].m_Element.m_Head = -1;
    this->m_Fragments.m_List.m_Memory.m_pMemory[v10].m_Element.m_Count = 0;
    m_Cache->m_List = v9;
    v11 = v13-- == 1;
    ++m_Cache;
  }
  while ( !v11 );
  for ( i = 0; i < 16; ++i )
    CTextureAllocator::AddBlockToLRU(this, block: i);
  this->m_CurrentFrame = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100BC630
// Name: public: unsigned short CTextureAllocator::AllocateTexture(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTextureAllocator::AllocateTexture(CTextureAllocator *this, int w, int h)
{
  int v3; // edi
  int v5; // ebx
  int result; // eax
  int v7; // ecx
  unsigned __int16 v8; // bx
  int i; // edx

  v3 = w;
  if ( w >= 16 )
  {
    if ( w > 256 )
      v3 = 256;
  }
  else
  {
    v3 = 16;
  }
  v5 = (unsigned __int16)CUtlLinkedList<CTextureAllocator::TextureInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CTextureAllocator::TextureInfo_t,unsigned short>,unsigned short>>::AllocInternal(
                           this: &this->m_Textures,
                           multilist: false);
  result = 0xFFFF;
  if ( (_WORD)v5 != 0xFFFF )
  {
    CUtlLinkedList<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CPixelVisSet,unsigned short>::List_t,unsigned short>,unsigned short>>::LinkBefore(
      this: (CUtlLinkedList<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlMultiList<CDataManagerBase::resource_lru_element_t,unsigned short>::List_t,unsigned short>,unsigned short> > *)&this->m_Textures,
      before: 0xFFFFu,
      elem: v5);
    result = v5;
  }
  v7 = (unsigned __int16)result;
  this->m_Textures.m_Memory.m_pMemory[v7].m_Element.m_Fragment = -1;
  v8 = 0;
  this->m_Textures.m_Memory.m_pMemory[v7].m_Element.m_Size = v3;
  for ( i = 1; i < v3; ++v8 )
    i *= 2;
  this->m_Textures.m_Memory.m_pMemory[v7].m_Element.m_Power = v8;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BC6C0
// Name: private: void CClientShadowMgr::ShutdownRenderToTextureShadows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::ShutdownRenderToTextureShadows(CClientShadowMgr *this)
{
  unsigned __int16 i; // ax
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *m_pMemory; // edi
  unsigned int v4; // ebx
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *v5; // edi

  if ( this->m_RenderToTextureActive )
  {
    for ( i = this->m_Shadows.m_Head; i != 0xFFFF; i = this->m_Shadows.m_Memory.m_pMemory[v4].m_Next )
    {
      m_pMemory = this->m_Shadows.m_Memory.m_pMemory;
      v4 = i;
      if ( this->m_RenderToTextureActive && (m_pMemory[v4].m_Element.m_Flags & 8) != 0 )
      {
        CTextureAllocator::DeallocateTexture(this: &this->m_ShadowAllocator, h: m_pMemory[v4].m_Element.m_ShadowTexture);
        m_pMemory[v4].m_Element.m_ShadowTexture = -1;
      }
      v5 = this->m_Shadows.m_Memory.m_pMemory;
      ((void (__stdcall *)(_DWORD, IMaterial *, IMaterial *, int))shadowmgr->SetShadowMaterial)(
        a1: v5[v4].m_Element.m_ShadowHandle,
        a2: this->m_SimpleShadow.m_pMaterial,
        a3: this->m_SimpleShadow.m_pMaterial,
        a4: 0xFFFF);
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, int, int))shadowmgr->SetShadowTexCoord)(
        a1: v5[v4].m_Element.m_ShadowHandle,
        a2: 0,
        a3: 0,
        a4: 1065353216,
        a5: 1065353216);
      if ( r_shadow_deferred.m_pParent == nullptr || r_shadow_deferred.m_pParent->m_Value.m_nValue == 0 )
        ((void (__stdcall *)(_DWORD))shadowmgr->ClearExtraClipPlanes)(a1: this->m_Shadows.m_Memory.m_pMemory[v4].m_Element.m_ShadowHandle);
    }
    CMaterialReference::Shutdown(this: &this->m_RenderShadow, bDeleteIfUnreferenced: false);
    CMaterialReference::Shutdown(this: &this->m_RenderModelShadow, bDeleteIfUnreferenced: false);
    CTextureAllocator::DeallocateAllTextures(this: &this->m_ShadowAllocator);
    CTextureReference::Shutdown(this: &this->m_ShadowAllocator.m_TexturePage, bDeleteIfUnReferenced: false);
    materials->UncacheUnusedMaterials(this: materials, a2: false);
    this->m_RenderToTextureActive = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BC800
// Name: public: virtual void CClientShadowMgr::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::LevelInitPreEntity(CClientShadowMgr *this)
{
  void (__thiscall *SetShadowFromWorldLightsEnabled)(struct CClientShadowMgr *, bool); // edx
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  Vector ambientColor; // [esp+4h] [ebp-14h] BYREF
  int r; // [esp+10h] [ebp-8h]
  int g; // [esp+14h] [ebp-4h]

  SetShadowFromWorldLightsEnabled = this->SetShadowFromWorldLightsEnabled;
  this->m_bUpdatingDirtyShadows = false;
  ((void (__stdcall *)(int))SetShadowFromWorldLightsEnabled)(a1: 1);
  engine->GetAmbientLightColor(this: engine, a2: &ambientColor);
  v3 = (float)(ambientColor.y * 3.0) + 0.30000001;
  v4 = (float)(ambientColor.z * 3.0) + 0.30000001;
  ambientColor.x = (float)(ambientColor.x * 3.0) + 0.30000001;
  ambientColor.y = v3;
  ambientColor.z = v4;
  if ( ambientColor.x <= 1.0 )
    v5 = ambientColor.x * 255.0;
  else
    v5 = 255.0;
  LOBYTE(r) = (int)v5;
  if ( v3 <= 1.0 )
    v6 = v3 * 255.0;
  else
    v6 = 255.0;
  LOBYTE(g) = (int)v6;
  if ( v4 <= 1.0 )
    v7 = v4 * 255.0;
  else
    v7 = 255.0;
  this->SetShadowColor(this, a2: r, a3: g, a4: (int)v7);
  if ( this->m_RenderToTextureActive )
  {
    CTextureAllocator::Reset(this: &this->m_ShadowAllocator);
    this->m_bRenderTargetNeedsClear = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BC900
// Name: private: void CClientShadowMgr::SetupRenderToTextureShadow(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::SetupRenderToTextureShadow(CClientShadowMgr *this, unsigned __int16 h)
{
  unsigned int v2; // esi
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *m_pMemory; // edi
  CBaseHandle v5; // ecx
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *v6; // edi
  IClientRenderable *ClientRenderableFromHandle; // eax
  ShadowType_t v8; // edx
  unsigned __int16 m_Flags; // cx
  int m_RenderToTextureActive; // edx
  float v11; // xmm0_4
  int v12; // eax
  int v13; // ecx
  Vector mins; // [esp+Ch] [ebp-18h] BYREF
  Vector maxs; // [esp+18h] [ebp-Ch] BYREF

  v2 = h;
  m_pMemory = this->m_Shadows.m_Memory.m_pMemory;
  v5.m_Index = m_pMemory[v2].m_Element.m_Entity.m_Index;
  v6 = &m_pMemory[v2];
  ClientRenderableFromHandle = CClientEntityList::GetClientRenderableFromHandle(
                                 this: (CClientEntityList *)cl_entitylist.m_Index,
                                 hEnt: v5);
  if ( ClientRenderableFromHandle != nullptr )
  {
    if ( h == 0xFFFF )
    {
      v8 = SHADOWS_NONE;
    }
    else
    {
      m_Flags = this->m_Shadows.m_Memory.m_pMemory[v2].m_Element.m_Flags;
      if ( (m_Flags & 8) != 0 )
        m_RenderToTextureActive = this->m_RenderToTextureActive;
      else
        m_RenderToTextureActive = (m_Flags & 0x20) != 0 ? 3 : 0;
      v8 = m_RenderToTextureActive + 1;
    }
    ClientRenderableFromHandle->GetShadowRenderBounds(this: ClientRenderableFromHandle, a2: &mins, a3: &maxs, a4: v8);
    v11 = maxs.x - mins.x;
    if ( (float)(maxs.x - mins.x) <= (float)(maxs.y - mins.y) )
      v11 = maxs.y - mins.y;
    if ( v11 <= (float)(maxs.z - mins.z) )
      v11 = maxs.z - mins.z;
    v12 = 1;
    v13 = (int)(float)(v11 * 2.0);
    if ( v13 > 1 )
    {
      do
        v12 *= 2;
      while ( v12 < v13 );
    }
    v6->m_Element.m_ShadowTexture = CTextureAllocator::AllocateTexture(this: &this->m_ShadowAllocator, w: v12, h: v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BC9F0
// Name: private: void CClientShadowMgr::BuildOrthoShadow(class IClientRenderable __near *,unsigned short,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CClientShadowMgr::BuildOrthoShadow(
        CClientShadowMgr *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        IClientRenderable *pRenderable,
        unsigned __int16 handle,
        const Vector *mins,
        const Vector *maxs)
{
  CClientShadowMgr *v8; // edi
  const QAngle *(__thiscall *GetRenderAngles)(IClientRenderable *); // edx
  const QAngle *v10; // eax
  int v11; // eax
  int v12; // eax
  float v13; // edx
  float *v14; // esi
  float v15; // xmm0_4
  float v16; // xmm0_4
  float x; // xmm1_4
  float y; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float z; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float *v24; // eax
  float v25; // xmm1_4
  float v26; // xmm4_4
  float v27; // xmm1_4
  float v28; // xmm3_4
  float v29; // xmm1_4
  __int128 v30; // xmm0
  float v31; // xmm7_4
  float v32; // xmm7_4
  float v33; // xmm7_4
  float v34; // xmm3_4
  const Vector *(__thiscall *GetRenderOrigin)(IClientRenderable *); // eax
  float v36; // xmm3_4
  int v37; // eax
  int v38; // esi
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *m_pMemory; // edx
  float v40; // xmm1_4
  float v41; // xmm2_4
  int p_m_WorldToShadow; // eax
  float *p_x; // eax
  double ShadowDistance; // st7
  double v45; // st7
  ISpatialQuery *v46; // eax
  IClientRenderable_vtbl *v47; // eax
  IShadowMgr_vtbl *v48; // edi
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *v49; // ecx
  int v50; // xmm0_4
  int v51; // eax
  void **v53; // [esp+2Ch] [ebp-96Ch] BYREF
  _DWORD v54[2]; // [esp+30h] [ebp-968h] BYREF
  CShadowLeafEnum leafList; // [esp+38h] [ebp-960h] BYREF
  VMatrix matWorldToTexture; // [esp+858h] [ebp-140h] BYREF
  VMatrix v57; // [esp+89Ch] [ebp-FCh] BYREF
  float v58; // [esp+8DCh] [ebp-BCh]
  float v59; // [esp+8E0h] [ebp-B8h]
  CClientShadowMgr *v60; // [esp+8E4h] [ebp-B4h]
  float v61; // [esp+8E8h] [ebp-B0h]
  float v62[3]; // [esp+8ECh] [ebp-ACh] BYREF
  Vector vec[3]; // [esp+8F8h] [ebp-A0h] BYREF
  __int128 org; // [esp+91Ch] [ebp-7Ch] OVERLAPPED
  Vector boxSize_8; // [esp+934h] [ebp-64h] OVERLAPPED BYREF
  __int128 vecShadowDir; // [esp+940h] [ebp-58h] OVERLAPPED BYREF
  int nCount; // [esp+950h] [ebp-48h]
  Vector worldOrigin; // [esp+954h] [ebp-44h] BYREF
  Vector xvec; // [esp+960h] [ebp-38h] BYREF
  Vector2D size; // [esp+96Ch] [ebp-2Ch] BYREF
  float maxHeight; // [esp+974h] [ebp-24h]
  Vector yvec; // [esp+978h] [ebp-20h]
  int vecIdx[3]; // [esp+984h] [ebp-14h]
  void *v74; // [esp+990h] [ebp-8h]
  void *retaddr; // [esp+998h] [ebp+0h]

  vecIdx[2] = a2;
  v74 = retaddr;
  v8 = this;
  GetRenderAngles = pRenderable->GetRenderAngles;
  v60 = this;
  v10 = (const QAngle *)((int (__thiscall *)(IClientRenderable *, float *, Vector *, Vector *, int, int))GetRenderAngles)(
                          a1: pRenderable,
                          a2: v62,
                          a3: vec,
                          a4: &vec[1],
                          a5: a3,
                          a6: a4);
  AngleVectors(angles: v10, forward: (Vector *)LODWORD(yvec.z), right: (Vector *)vecIdx[0], up: (Vector *)vecIdx[1]);
  vec[0].x = vec[0].x * -1.0;
  vec[0].y = vec[0].y * -1.0;
  vec[0].z = vec[0].z * -1.0;
  boxSize_8 = *CClientShadowMgr::GetShadowDirection(this: v8, shadowHandle: handle);
  vec[2].x = (float)((float)(boxSize_8.x * v62[0]) + (float)(boxSize_8.y * v62[1])) + (float)(boxSize_8.z * v62[2]);
  vec[2].y = (float)((float)(vec[0].x * boxSize_8.x) + (float)(vec[0].y * boxSize_8.y))
           + (float)(vec[0].z * boxSize_8.z);
  vec[2].z = (float)((float)(vec[1].y * boxSize_8.y) + (float)(vec[1].x * boxSize_8.x))
           + (float)(vec[1].z * boxSize_8.z);
  *(_QWORD *)((char *)&org + 4) = __PAIR64__(COERCE_UNSIGNED_INT(fabs(vec[2].y)), COERCE_UNSIGNED_INT(fabs(vec[2].x)));
  HIDWORD(org) = fabs(vec[2].z);
  v11 = *((float *)&org + 1) <= *((float *)&org + 2);
  if ( *((float *)&org + 3) > *((float *)&org + v11 + 1) )
    v11 = 2;
  if ( v11 != 0 )
  {
    v12 = v11 - 1;
    if ( v12 != 0 )
    {
      if ( v12 == 1 )
      {
        yvec.x = 0.0;
        LODWORD(yvec.y) = 1;
        LODWORD(yvec.z) = 2;
      }
    }
    else
    {
      LODWORD(yvec.x) = 2;
      yvec.y = 0.0;
      LODWORD(yvec.z) = 1;
    }
  }
  else
  {
    LODWORD(yvec.x) = 1;
    LODWORD(yvec.y) = 2;
    yvec.z = 0.0;
  }
  v13 = v62[3 * LODWORD(yvec.x) + 2];
  *(_QWORD *)&worldOrigin.x = *(_QWORD *)&v62[3 * LODWORD(yvec.x)];
  size = *(Vector2D *)&v62[3 * LODWORD(yvec.y)];
  v14 = &v62[3 * LODWORD(yvec.x)];
  v15 = (float)((float)(worldOrigin.x * boxSize_8.x) + (float)(boxSize_8.y * worldOrigin.y))
      + (float)(v13 * boxSize_8.z);
  *((float *)&org + 1) = v15 * boxSize_8.x;
  *((float *)&org + 2) = boxSize_8.y * v15;
  worldOrigin.z = v13 - (float)(boxSize_8.z * v15);
  worldOrigin.x = worldOrigin.x - (float)(v15 * boxSize_8.x);
  worldOrigin.y = worldOrigin.y - (float)(boxSize_8.y * v15);
  DWORD1(vecShadowDir) = &v62[3 * LODWORD(yvec.y)];
  maxHeight = *(float *)(DWORD1(vecShadowDir) + 8);
  v16 = (float)((float)(size.x * boxSize_8.x) + (float)(size.y * boxSize_8.y)) + (float)(maxHeight * boxSize_8.z);
  size.x = size.x - (float)(v16 * boxSize_8.x);
  size.y = size.y - (float)(boxSize_8.y * v16);
  maxHeight = maxHeight - (float)(boxSize_8.z * v16);
  VectorNormalize(vec: &worldOrigin);
  VectorNormalize(vec: (Vector *)&size);
  x = mins->x;
  xvec.z = maxs->x;
  *(float *)&vecShadowDir = xvec.z - x;
  *((float *)&org + 1) = xvec.z - x;
  y = maxs->y;
  *(float *)&vecIdx[1] = x;
  v58 = y;
  v19 = mins->y;
  v20 = v14[1] * worldOrigin.y;
  *((float *)&org + 2) = y - v19;
  z = maxs->z;
  v61 = v19;
  v22 = mins->z;
  *(float *)vecIdx = z;
  *((float *)&org + 3) = z - v22;
  v23 = *v14 * worldOrigin.x;
  v59 = v22;
  v24 = &v62[3 * LODWORD(yvec.z)];
  v25 = (float)((float)(fabs(
                          (float)((float)(v62[3 * LODWORD(yvec.z) + 1] * size.y) + (float)(*v24 * size.x))
                        + (float)(v62[3 * LODWORD(yvec.z) + 2] * maxHeight))
                      * *((float *)&org + LODWORD(yvec.z) + 1))
              + (float)(COERCE_FLOAT(
                          COERCE_UNSIGNED_INT(
                            (float)((float)(*(float *)(DWORD1(vecShadowDir) + 4) * size.y)
                                  + (float)(*(float *)DWORD1(vecShadowDir) * size.x))
                          + (float)(*(float *)(DWORD1(vecShadowDir) + 8) * maxHeight))
                        & _mask__AbsFloat_)
                      * *((float *)&org + LODWORD(yvec.y) + 1)))
      + 10.0;
  xvec.x = (float)((float)(fabs(
                             (float)((float)(v62[3 * LODWORD(yvec.z) + 1] * worldOrigin.y)
                                   + (float)(*v24 * worldOrigin.x))
                           + (float)(v62[3 * LODWORD(yvec.z) + 2] * worldOrigin.z))
                         * *((float *)&org + LODWORD(yvec.z) + 1))
                 + (float)(COERCE_FLOAT(
                             COERCE_UNSIGNED_INT((float)(v20 + v23) + (float)(v14[2] * worldOrigin.z))
                           & _mask__AbsFloat_)
                         * *((float *)&org + LODWORD(yvec.x) + 1)))
         + 10.0;
  xvec.y = v25;
  if ( xvec.x <= 10.0 )
    xvec.x = 10.0;
  if ( v25 <= 10.0 )
    xvec.y = 10.0;
  v26 = maxs->z;
  v27 = maxs->y;
  v28 = v27 - mins->y;
  v29 = v27 + mins->y;
  yvec.x = (float)(*(float *)&vecIdx[1] + xvec.z) * 0.5;
  v30 = 0;
  *(float *)&v30 = fsqrt(
                     (float)((float)(v28 * v28) + (float)((float)(v26 - mins->z) * (float)(v26 - mins->z)))
                   + (float)(*(float *)&vecShadowDir * *(float *)&vecShadowDir));
  yvec.z = (float)(v26 + mins->z) * 0.5;
  org = v30;
  yvec.y = v29 * 0.5;
  if ( vec[2].x <= 0.0 )
    v31 = vec[2].x * xvec.z;
  else
    v31 = vec[2].x * *(float *)&vecIdx[1];
  *(float *)&vecIdx[1] = v31
                       + COERCE_FLOAT(
                           COERCE_UNSIGNED_INT(
                             (float)((float)(vec[2].x * yvec.x) + (float)(vec[2].y * yvec.y))
                           + (float)(vec[2].z * yvec.z))
                         ^ _mask__NegFloat_);
  if ( vec[2].y <= 0.0 )
    v32 = vec[2].y * v58;
  else
    v32 = vec[2].y * v61;
  v33 = v32 + *(float *)&vecIdx[1];
  if ( vec[2].z <= 0.0 )
    v34 = vec[2].z * *(float *)vecIdx;
  else
    v34 = vec[2].z * v59;
  GetRenderOrigin = pRenderable->GetRenderOrigin;
  v36 = (float)(v34 + v33) * 2.0;
  vec[2].x = (float)(vec[2].x * v36) + yvec.x;
  vec[2].y = (float)(vec[2].y * v36) + yvec.y;
  vec[2].z = (float)(vec[2].z * v36) + yvec.z;
  *(float *)&vecIdx[1] = (float)(*(float *)&org * 0.5) - v36;
  v37 = (int)GetRenderOrigin(this: pRenderable);
  *((_QWORD *)&vecShadowDir + 1) = *(_QWORD *)v37;
  v38 = handle;
  nCount = *(int *)(v37 + 8);
  *((float *)&vecShadowDir + 3) = (float)(int)(float)((float)((float)(vec[1].y * vec[2].z)
                                                            + (float)((float)(vec[0].y * vec[2].y)
                                                                    + (float)((float)(v62[1] * vec[2].x)
                                                                            + *((float *)&vecShadowDir + 3))))
                                                    * 2.0)
                                * 0.5;
  m_pMemory = v8->m_Shadows.m_Memory.m_pMemory;
  *(float *)&nCount = (float)(int)(float)((float)((float)(vec[1].z * vec[2].z)
                                                + (float)((float)(vec[0].z * vec[2].y)
                                                        + (float)((float)(v62[2] * vec[2].x) + *(float *)&nCount)))
                                        * 2.0)
                    * 0.5;
  *((float *)&vecShadowDir + 2) = (float)(int)(float)((float)((float)(vec[1].x * vec[2].z)
                                                            + (float)((float)(vec[0].x * vec[2].y)
                                                                    + (float)((float)(v62[0] * vec[2].x)
                                                                            + *((float *)&vecShadowDir + 2))))
                                                    * 2.0)
                                * 0.5;
  v40 = -worldOrigin.y;
  v41 = -worldOrigin.z;
  p_m_WorldToShadow = (int)&m_pMemory[v38].m_Element.m_WorldToShadow;
  *(float *)p_m_WorldToShadow = -worldOrigin.x;
  *(float *)(p_m_WorldToShadow + 16) = v40;
  *(float *)(p_m_WorldToShadow + 32) = v41;
  *(float *)(p_m_WorldToShadow + 4) = size.x;
  *(float *)(p_m_WorldToShadow + 20) = size.y;
  *(float *)(p_m_WorldToShadow + 36) = maxHeight;
  *(float *)(p_m_WorldToShadow + 8) = boxSize_8.x;
  *(float *)(p_m_WorldToShadow + 24) = boxSize_8.y;
  *(float *)(p_m_WorldToShadow + 40) = boxSize_8.z;
  *(_DWORD *)(p_m_WorldToShadow + 12) = DWORD2(vecShadowDir);
  *(_DWORD *)(p_m_WorldToShadow + 28) = HIDWORD(vecShadowDir);
  *(float *)(p_m_WorldToShadow + 44) = *(float *)&nCount;
  vecIdx[1] = p_m_WorldToShadow;
  *(_DWORD *)(p_m_WorldToShadow + 56) = 0;
  *(_DWORD *)(p_m_WorldToShadow + 52) = 0;
  *(_DWORD *)(p_m_WorldToShadow + 48) = 0;
  vecIdx[0] = p_m_WorldToShadow;
  *(_DWORD *)(p_m_WorldToShadow + 60) = 1065353216;
  MatrixInverseGeneral(src: (const VMatrix *)vecIdx[0], dst: (VMatrix *)vecIdx[1]);
  MatrixBuildScale(
    dst: &v57,
    x: COERCE_UNSIGNED_INT(1.0 / xvec.x),
    y: (unsigned int)&v8->m_Shadows.m_Memory.m_pMemory[v38].m_Element.m_WorldToShadow,
    z: 1.0);
  v57.m[1][3] = 0.5;
  v57.m[0][3] = 0.5;
  MatrixMultiply(src1: &v57, src2: (VMatrix *)vecIdx[0], dst: (VMatrix *)&leafList.m_LeafList.m_Size);
  p_x = &v8->m_Shadows.m_Memory.m_pMemory[v38].m_Element.m_WorldSize.x;
  *p_x = xvec.x;
  p_x[1] = xvec.y;
  MatrixCopy(
    src: (const VMatrix *)&leafList.m_LeafList.m_Size,
    dst: &v8->m_Shadows.m_Memory.m_pMemory[v38].m_Element.m_WorldToTexture);
  ShadowDistance = CClientShadowMgr::GetShadowDistance(this: v8, pRenderable);
  v45 = ShadowDistance + *(float *)&vecIdx[1];
  xvec.z = v45;
  v53 = &CShadowLeafEnum::`vftable';
  v54[0] = &leafList.m_LeafList.m_Memory.m_nAllocationCount;
  v54[1] = 512;
  leafList.__vftable = (CShadowLeafEnum_vtbl *)-1;
  leafList.m_LeafList.m_Memory.m_pMemory = nullptr;
  *(_QWORD *)&matWorldToTexture.m[3][1] = *((_QWORD *)&vecShadowDir + 1);
  v57.m[0][0] = boxSize_8.x * v45;
  LODWORD(matWorldToTexture.m[3][3]) = nCount;
  memset(v57.m[1], 0, 12);
  v57.m[0][1] = boxSize_8.y * v45;
  *(float *)vecIdx = xvec.y * xvec.y;
  v57.m[0][2] = v45 * boxSize_8.z;
  leafList.m_LeafList.m_Memory.m_pFixedMemory[510] = (int)&leafList.m_LeafList.m_Memory.m_nAllocationCount;
  leafList.m_LeafList.m_Memory.m_pFixedMemory[509] = 0;
  v57.m[3][0] = 0.0;
  v57.m[2][0] = fsqrt((float)(xvec.y * xvec.y) + (float)(xvec.x * xvec.x)) * 0.5;
  v57.m[2][1] = v57.m[2][0];
  v57.m[2][2] = v57.m[2][0];
  LOWORD(v57.m[3][1]) = 256;
  v46 = engine->GetBSPTreeQuery(this: engine);
  v46->EnumerateLeavesAlongRay(
    this: v46,
    a2: (const Ray_t *)&matWorldToTexture.m[3][1],
    a3: (ISpatialLeafEnumerator *)&v53,
    a4: 0);
  *(_QWORD *)&vecShadowDir = __PAIR64__(leafList.m_LeafList.m_Memory.m_pFixedMemory[509], v54[0]);
  if ( r_shadow_deferred.m_pParent == nullptr || r_shadow_deferred.m_pParent->m_Value.m_nValue == 0 )
  {
    v47 = pRenderable->__vftable;
    vecIdx[0] = (int)&v8->m_Shadows.m_Memory.m_pMemory[v38];
    v48 = shadowmgr->__vftable;
    vecIdx[1] = (int)v47->GetRenderOrigin(this: pRenderable);
    vecIdx[0] = 1131413504;
    LODWORD(yvec.z) = vecIdx[1];
    yvec.y = xvec.z;
    maxHeight = *((float *)&vecShadowDir + 1);
    LODWORD(yvec.x) = vecShadowDir;
    LODWORD(size.y) = &xvec;
    ((void (__thiscall *)(IShadowMgr *, _DWORD, char *, Vector *, int *))v48->ProjectShadow)(
      a1: shadowmgr,
      a2: MEMORY[0x43700004],
      a3: (char *)&vecShadowDir + 8,
      a4: &boxSize_8,
      a5: &leafList.m_LeafList.m_Size);
    v8 = v60;
  }
  v8->m_Shadows.m_Memory.m_pMemory[v38].m_Element.m_MaxDist = xvec.z;
  v49 = v8->m_Shadows.m_Memory.m_pMemory;
  v50 = vecIdx[1];
  v51 = DWORD1(vecShadowDir);
  vecIdx[1] = vecShadowDir;
  LODWORD(v49[v38].m_Element.m_FalloffStart) = v50;
  ((void (__cdecl *)(_DWORD, int, int))g_pClientLeafSystem->ProjectShadow)(
    a1: v8->m_Shadows.m_Memory.m_pMemory[v38].m_Element.m_ClientLeafShadowHandle,
    a2: v51,
    a3: vecIdx[1]);
  CUtlVector<int,CUtlMemoryFixedGrowable<int,512,int>>::~CUtlVector<int,CUtlMemoryFixedGrowable<int,512,int>>(this: (CUtlVector<int,CUtlMemoryFixedGrowable<int,512,int> > *)v54);
}

//------------------------------------------------------------------------------
// Address: 0x100BD430
// Name: private: void CClientShadowMgr::UpdateStudioShadow(class IClientRenderable __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::UpdateStudioShadow(
        CClientShadowMgr *this,
        IClientRenderable *pRenderable,
        int handle)
{
  int v3; // edi
  Vector mins; // [esp+Ch] [ebp-18h] BYREF
  Vector maxs; // [esp+18h] [ebp-Ch] BYREF
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  v3 = (unsigned __int16)handle;
  if ( (this->m_Shadows.m_Memory.m_pMemory[v3].m_Element.m_Flags & 5) != 0 )
  {
    CClientShadowMgr::BuildFlashlight(this, handle);
  }
  else
  {
    CClientShadowMgr::ComputeHierarchicalBounds(this, pRenderable, vecMins: &mins, vecMaxs: &maxs);
    if ( (_WORD)handle != 0xFFFF
      && (this->m_Shadows.m_Memory.m_pMemory[v3].m_Element.m_Flags & 8) != 0
      && this->m_RenderToTextureActive )
    {
      CClientShadowMgr::BuildRenderToTextureShadow(
        this,
        a2: COERCE_FLOAT(&savedregs),
        a3: v3 * 276,
        a4: (int)this,
        pRenderable,
        handle,
        &mins,
        &maxs);
    }
    else
    {
      CClientShadowMgr::BuildOrthoShadow(
        this,
        a2: (int)&savedregs,
        a3: v3 * 276,
        a4: (int)this,
        pRenderable,
        handle,
        &mins,
        &maxs);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BD4E0
// Name: private: void CClientShadowMgr::UpdateBrushShadow(class IClientRenderable __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::UpdateBrushShadow(CClientShadowMgr *this, IClientRenderable *pRenderable, int handle)
{
  int v3; // edi
  Vector mins; // [esp+Ch] [ebp-18h] BYREF
  Vector maxs; // [esp+18h] [ebp-Ch] BYREF
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  v3 = (unsigned __int16)handle;
  if ( (this->m_Shadows.m_Memory.m_pMemory[v3].m_Element.m_Flags & 5) != 0 )
  {
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "CClientShadowMgr::UpdateBrushShadow",
      a3: 0,
      a4: "Flashlight Shadows",
      a5: false,
      a6: 4);
    CClientShadowMgr::BuildFlashlight(this, handle);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    CClientShadowMgr::ComputeHierarchicalBounds(this, pRenderable, vecMins: &mins, vecMaxs: &maxs);
    if ( (_WORD)handle != 0xFFFF
      && (this->m_Shadows.m_Memory.m_pMemory[v3].m_Element.m_Flags & 8) != 0
      && this->m_RenderToTextureActive )
    {
      CClientShadowMgr::BuildRenderToTextureShadow(
        this,
        a2: COERCE_FLOAT(&savedregs),
        a3: v3 * 276,
        a4: (int)this,
        pRenderable,
        handle,
        &mins,
        &maxs);
    }
    else
    {
      CClientShadowMgr::BuildOrthoShadow(
        this,
        a2: (int)&savedregs,
        a3: v3 * 276,
        a4: (int)this,
        pRenderable,
        handle,
        &mins,
        &maxs);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BD5B0
// Name: HalfUpdateRateCallback
// Source: json
//------------------------------------------------------------------------------
void __cdecl HalfUpdateRateCallback()
{
  CClientShadowMgr::FlushLeftOverDirtyShadows(this: &s_ClientShadowMgr);
}

//------------------------------------------------------------------------------
// Address: 0x100BD5C0
// Name: private: void CClientShadowMgr::UpdateShadow(unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::UpdateShadow(CClientShadowMgr *this, int handle, bool force)
{
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *v4; // esi
  IClientRenderable *ClientRenderableFromHandle; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  unsigned __int16 *m_pMemory; // ecx
  int v9; // eax
  unsigned __int16 *v10; // edi
  Vector *v11; // ebx
  float *p_x; // eax
  IMatRenderContext *v13; // eax
  IMatRenderContext *v14; // esi
  const struct model_t *v15; // ebx
  int v16; // eax
  int i; // [esp+10h] [ebp-4h]
  Vector *ia; // [esp+10h] [ebp-4h]
  MaterialFogMode_t fogMode; // [esp+20h] [ebp+Ch]

  v4 = &this->m_Shadows.m_Memory.m_pMemory[(unsigned __int16)handle];
  ClientRenderableFromHandle = CClientEntityList::GetClientRenderableFromHandle(
                                 this: (CClientEntityList *)cl_entitylist.m_Index,
                                 hEnt: v4->m_Element.m_Entity);
  if ( ClientRenderableFromHandle == nullptr )
  {
    this->DestroyShadow(this, a2: handle);
    return;
  }
  if ( ClientRenderableFromHandle->GetModel(this: ClientRenderableFromHandle) == nullptr )
    goto LABEL_38;
  i = 0;
  while ( !ClientRenderableFromHandle->ShouldDrawForSplitScreenUser(this: ClientRenderableFromHandle, a2: i) )
  {
    if ( ++i != 0 )
      goto LABEL_38;
  }
  if ( v4->m_Element.m_FalloffBias != 255 )
  {
    if ( CClientShadowMgr::ShouldUseParentShadow(this, pRenderable: ClientRenderableFromHandle) != 0
      || CClientShadowMgr::WillParentRenderBlobbyShadow(this, pRenderable: ClientRenderableFromHandle) )
    {
      if ( r_shadow_deferred.m_pParent == nullptr || r_shadow_deferred.m_pParent->m_Value.m_nValue == 0 )
        shadowmgr->EnableShadow(this: shadowmgr, a2: v4->m_Element.m_ShadowHandle, a3: false);
      goto LABEL_38;
    }
    if ( r_shadow_deferred.m_pParent == nullptr || r_shadow_deferred.m_pParent->m_Value.m_nValue == 0 )
      shadowmgr->EnableShadow(this: shadowmgr, a2: v4->m_Element.m_ShadowHandle, a3: true);
    v11 = ClientRenderableFromHandle->GetRenderOrigin(this: ClientRenderableFromHandle);
    p_x = (float *)ClientRenderableFromHandle->GetRenderAngles(this: ClientRenderableFromHandle);
    ia = (Vector *)p_x;
    if ( !force )
    {
      if ( !Vector::operator!=(this: v11, src: &v4->m_Element.m_LastOrigin)
        && !Vector::operator!=(this: ia, src: (const Vector *)&v4->m_Element.m_LastAngles) )
      {
LABEL_38:
        ClientRenderableFromHandle->MarkShadowDirty(this: ClientRenderableFromHandle, a2: false);
        return;
      }
      p_x = &ia->x;
    }
    v4->m_Element.m_LastOrigin.x = v11->x;
    v4->m_Element.m_LastOrigin.y = v11->y;
    v4->m_Element.m_LastOrigin.z = v11->z;
    v4->m_Element.m_LastAngles.x = *p_x;
    v4->m_Element.m_LastAngles.y = p_x[1];
    v4->m_Element.m_LastAngles.z = p_x[2];
    v13 = materials->GetRenderContext(this: materials);
    v14 = v13;
    if ( v13 != nullptr )
      v13->BeginRender(this: v13);
    v15 = ClientRenderableFromHandle->GetModel(this: ClientRenderableFromHandle);
    fogMode = v14->GetFogMode(this: v14);
    v14->FogMode(this: v14, a2: MATERIAL_FOG_NONE);
    v16 = modelinfo->GetModelType(this: modelinfo, a2: v15) - 1;
    if ( v16 != 0 )
    {
      if ( v16 == 2 )
        CClientShadowMgr::UpdateStudioShadow(this, pRenderable: ClientRenderableFromHandle, handle);
    }
    else
    {
      CClientShadowMgr::UpdateBrushShadow(this, pRenderable: ClientRenderableFromHandle, handle);
    }
    v14->FogMode(this: v14, a2: fogMode);
    v14->EndRender(this: v14);
    v14->Release(this: v14);
    goto LABEL_38;
  }
  if ( r_shadow_deferred.m_pParent == nullptr || r_shadow_deferred.m_pParent->m_Value.m_nValue == 0 )
    shadowmgr->EnableShadow(this: shadowmgr, a2: v4->m_Element.m_ShadowHandle, a3: false);
  m_Size = this->m_TransparentShadows.m_Size;
  m_nAllocationCount = this->m_TransparentShadows.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<wchar_t,int>::Grow(
      this: (CUtlMemory<CUtlSymbol,int> *)&this->m_TransparentShadows,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_TransparentShadows.m_Size;
  m_pMemory = this->m_TransparentShadows.m_Memory.m_pMemory;
  v9 = this->m_TransparentShadows.m_Size - m_Size - 1;
  this->m_TransparentShadows.m_pElements = m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 2 * v9);
  v10 = &this->m_TransparentShadows.m_Memory.m_pMemory[m_Size];
  if ( v10 != nullptr )
    *v10 = handle;
}

//------------------------------------------------------------------------------
// Address: 0x100BD890
// Name: private: void CClientShadowMgr::UpdateProjectedTextureInternal(unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::UpdateProjectedTextureInternal(CClientShadowMgr *this, int handle, bool force)
{
  int v3; // edi

  v3 = (unsigned __int16)handle;
  if ( (this->m_Shadows.m_Memory.m_pMemory[v3].m_Element.m_Flags & 5) != 0 )
  {
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "CClientShadowMgr::UpdateProjectedTextureInternal",
      a3: 0,
      a4: "Flashlight Shadows",
      a5: false,
      a6: 4);
    ((void (__stdcall *)(_DWORD, int))shadowmgr->EnableShadow)(
      a1: this->m_Shadows.m_Memory.m_pMemory[v3].m_Element.m_ShadowHandle,
      a2: 1);
    CClientShadowMgr::UpdateBrushShadow(this, pRenderable: nullptr, handle);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    CClientShadowMgr::UpdateShadow(this, handle, force);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BD910
// Name: public: virtual void CClientShadowMgr::UpdateProjectedTexture(unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::UpdateProjectedTexture(CClientShadowMgr *this, int handle, bool force)
{
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CClientShadowMgr::UpdateProjectedTexture",
    a3: 0,
    a4: "Flashlight Shadows",
    a5: false,
    a6: 4);
  if ( (_WORD)handle != 0xFFFF )
  {
    if ( (this->m_Shadows.m_Memory.m_pMemory[(unsigned __int16)handle].m_Element.m_Flags & 5) == 0 )
    {
      _Warning(a1: "CClientShadowMgr::UpdateProjectedTexture can only be used with flashlights!\n");
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      return;
    }
    CClientShadowMgr::UpdateProjectedTextureInternal(this, handle, force);
    CClientShadowMgr::RemoveShadowFromDirtyList(this, handle);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x100BDA00
// Name: public: virtual void CClientShadowMgr::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::Shutdown(CClientShadowMgr *this)
{
  this->ShutdownRenderTargets(this);
  CMaterialReference::Shutdown(this: &this->m_SimpleShadow, bDeleteIfUnreferenced: false);
  CUtlLinkedList<CClientShadowMgr::ClientShadow_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Shadows);
  CClientShadowMgr::ShutdownRenderToTextureShadows(this);
  CClientShadowMgr::ShutdownDepthTextureShadows(this);
  CMaterialReference::Shutdown(this: &this->m_RenderDeferredShadowMat, bDeleteIfUnreferenced: false);
  CMaterialReference::Shutdown(this: &this->m_RenderDeferredSimpleShadowMat, bDeleteIfUnreferenced: false);
  CTextureReference::Shutdown(this: &this->m_downSampledNormals, bDeleteIfUnReferenced: false);
  CTextureReference::Shutdown(this: &this->m_downSampledDepth, bDeleteIfUnReferenced: false);
}

//------------------------------------------------------------------------------
// Address: 0x100BDA60
// Name: private: void CClientShadowMgr::InitRenderToTextureShadows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::InitRenderToTextureShadows(CClientShadowMgr *this)
{
  int r; // ecx
  IMaterial *m_pMaterial; // ebx
  float g; // xmm1_4
  float b; // xmm2_4
  int i; // edi
  int v7; // eax
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *v8; // ebx
  float fr; // [esp+24h] [ebp-Ch]

  if ( !this->m_RenderToTextureActive )
  {
    this->m_RenderToTextureActive = true;
    g_pMaterialSystem->BeginRenderTargetAllocation(this: g_pMaterialSystem);
    *(_DWORD *)&this->m_ShadowAllocator.m_Cache[0].m_List = -1;
    *(_DWORD *)&this->m_ShadowAllocator.m_Cache[2].m_List = -1;
    *(_DWORD *)&this->m_ShadowAllocator.m_Cache[4].m_List = -1;
    *(_DWORD *)&this->m_ShadowAllocator.m_Cache[6].m_List = -1;
    this->m_ShadowAllocator.m_Cache[8].m_List = -1;
    CTextureReference::InitRenderTarget(
      this: &this->m_ShadowAllocator.m_TexturePage,
      w: 1024,
      h: 1024,
      sizeMode: RT_SIZE_NO_CHANGE,
      fmt: IMAGE_FORMAT_ARGB8888,
      depth: MATERIAL_RT_DEPTH_NONE,
      bHDR: false,
      pStrOptionalName: "_rt_Shadows");
    g_pMaterialSystem->EndRenderTargetAllocation(this: g_pMaterialSystem);
    CMaterialReference::Init(
      this: &this->m_RenderShadow,
      pMaterialName: "decals/rendershadow",
      pTextureGroupName: "Decal textures",
      bComplain: true);
    CMaterialReference::Init(
      this: &this->m_RenderModelShadow,
      pMaterialName: "decals/rendermodelshadow",
      pTextureGroupName: "Decal textures",
      bComplain: true);
    CTextureAllocator::Reset(this: &this->m_ShadowAllocator);
    r = this->m_AmbientLightColor.r;
    m_pMaterial = this->m_RenderShadow.m_pMaterial;
    g = (float)this->m_AmbientLightColor.g;
    b = (float)this->m_AmbientLightColor.b;
    this->m_bRenderTargetNeedsClear = true;
    fr = (float)r * 0.0039215689;
    ((void (__thiscall *)(IMaterial *, _DWORD, _DWORD, _DWORD))m_pMaterial->ColorModulate)(
      a1: m_pMaterial,
      a2: LODWORD(fr),
      a3: g * 0.0039215689,
      a4: b * 0.0039215689);
    ((void (__thiscall *)(IMaterial *, _DWORD, _DWORD, _DWORD))this->m_RenderModelShadow.m_pMaterial->ColorModulate)(
      a1: this->m_RenderModelShadow.m_pMaterial,
      a2: LODWORD(fr),
      a3: g * 0.0039215689,
      a4: b * 0.0039215689);
    for ( i = this->m_Shadows.m_Head; (_WORD)i != 0xFFFF; i = this->m_Shadows.m_Memory.m_pMemory[v7].m_Next )
    {
      v7 = (unsigned __int16)i;
      v8 = &this->m_Shadows.m_Memory.m_pMemory[v7];
      if ( (v8->m_Element.m_Flags & 8) != 0 )
      {
        CClientShadowMgr::SetupRenderToTextureShadow(this, h: i);
        this->MarkRenderToTextureShadowDirty(this, a2: i);
        ((void (__stdcall *)(_DWORD, IMaterial *, IMaterial *, _DWORD))shadowmgr->SetShadowMaterial)(
          a1: v8->m_Element.m_ShadowHandle,
          a2: this->m_RenderShadow.m_pMaterial,
          a3: this->m_RenderModelShadow.m_pMaterial,
          a4: (unsigned __int16)i);
        v7 = (unsigned __int16)i;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BDC30
// Name: private: unsigned short CClientShadowMgr::CreateProjectedTexture(class CBaseHandle,int,int,class CBitVec<1> __near *,bool)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CClientShadowMgr::CreateProjectedTexture(
        CClientShadowMgr *this,
        CBaseHandle entity,
        int nEntIndex,
        int flags,
        CBitVec<1> *pSplitScreenBits,
        bool bShareProjectedTextureBetweenSplitscreenPlayers)
{
  IClientRenderable *ClientRenderableFromHandle; // eax
  IVModelInfoClient_vtbl *v9; // esi
  int v10; // eax
  unsigned __int16 v11; // ax
  int v12; // ebx
  UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short> *v13; // esi
  const Vector *v14; // eax
  IMaterial *m_pMaterial; // eax
  IMaterial *v16; // edx
  int v17; // ecx
  unsigned __int16 h; // [esp+Ch] [ebp-4h]
  int flagsa; // [esp+20h] [ebp+10h]
  int createShadowFlags; // [esp+28h] [ebp+18h]

  if ( (flags & 5) == 0 )
  {
    ClientRenderableFromHandle = CClientEntityList::GetClientRenderableFromHandle(
                                   this: (CClientEntityList *)cl_entitylist.m_Index,
                                   hEnt: entity);
    if ( ClientRenderableFromHandle == nullptr )
      return -1;
    v9 = modelinfo->__vftable;
    v10 = (int)ClientRenderableFromHandle->GetModel(this: ClientRenderableFromHandle);
    if ( v9->GetModelType(this: modelinfo, a2: (const struct model_t *)v10) == 1 )
      flags |= 0x100u;
  }
  v11 = CUtlLinkedList<CClientShadowMgr::ClientShadow_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientShadowMgr::ClientShadow_t,unsigned short>,unsigned short>>::AddToTail(this: &this->m_Shadows);
  v12 = flags;
  v13 = &this->m_Shadows.m_Memory.m_pMemory[v11];
  h = v11;
  v13->m_Element.m_Entity = entity;
  flagsa = flags & 4;
  if ( (v12 & 4) != 0 )
    v13->m_Element.m_ClientLeafShadowHandle = -1;
  else
    v13->m_Element.m_ClientLeafShadowHandle = g_pClientLeafSystem->AddShadow(
                                                this: g_pClientLeafSystem,
                                                a2: v11,
                                                a3: v12);
  v13->m_Element.m_Flags = v12;
  v13->m_Element.m_nRenderFrame = -1;
  v14 = this->GetShadowDirection(this);
  v13->m_Element.m_ShadowDir.x = v14->x;
  v13->m_Element.m_ShadowDir.y = v14->y;
  v13->m_Element.m_ShadowDir.z = v14->z;
  v13->m_Element.m_LastOrigin.x = 3.4028235e38;
  v13->m_Element.m_LastOrigin.y = 3.4028235e38;
  v13->m_Element.m_LastOrigin.z = 3.4028235e38;
  v13->m_Element.m_LastAngles.x = 3.4028235e38;
  v13->m_Element.m_LastAngles.y = 3.4028235e38;
  v13->m_Element.m_LastAngles.z = 3.4028235e38;
  v13->m_Element.m_CurrentLightPos.x = 3.4028235e38;
  v13->m_Element.m_CurrentLightPos.y = 3.4028235e38;
  v13->m_Element.m_CurrentLightPos.z = 3.4028235e38;
  v13->m_Element.m_TargetLightPos.x = 3.4028235e38;
  v13->m_Element.m_TargetLightPos.y = 3.4028235e38;
  v13->m_Element.m_TargetLightPos.z = 3.4028235e38;
  v13->m_Element.m_LightPosLerp = 3.4028235e38;
  v13->m_Element.m_nLastUpdateFrame = 0;
  v13->m_Element.m_nSplitscreenOwner = -1;
  if ( !bShareProjectedTextureBetweenSplitscreenPlayers
    && (v12 & 0x25) != 0
    && engine->IsLocalPlayerResolvable(this: engine) )
  {
    v13->m_Element.m_nSplitscreenOwner = 0;
  }
  m_pMaterial = this->m_SimpleShadow.m_pMaterial;
  v16 = m_pMaterial;
  v17 = 0xFFFF;
  if ( this->m_RenderToTextureActive && (v12 & 8) != 0 )
  {
    CClientShadowMgr::SetupRenderToTextureShadow(this, h);
    m_pMaterial = this->m_RenderShadow.m_pMaterial;
    v16 = this->m_RenderModelShadow.m_pMaterial;
    v17 = h;
  }
  if ( (v12 & 0x25) != 0 )
  {
    v17 = h;
    m_pMaterial = nullptr;
    v16 = nullptr;
  }
  if ( flagsa != 0 )
    createShadowFlags = 4;
  else
    createShadowFlags = ((v12 & 1) != 0) + 1;
  v13->m_Element.m_ShadowHandle = shadowmgr->CreateShadowEx(
                                    this: shadowmgr,
                                    a2: m_pMaterial,
                                    a3: v16,
                                    a4: (void *)v17,
                                    a5: createShadowFlags,
                                    a6: nEntIndex);
  v13->m_Element.m_bUseSplitScreenBits = pSplitScreenBits != nullptr;
  if ( pSplitScreenBits != nullptr )
    v13->m_Element.m_SplitScreenBits = (CBitVec<1>)pSplitScreenBits->m_Ints[0];
  return h;
}

//------------------------------------------------------------------------------
// Address: 0x100BDE40
// Name: public: virtual unsigned short CClientShadowMgr::CreateFlashlight(struct FlashlightState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CClientShadowMgr::CreateFlashlight(
        CClientShadowMgr *this,
        const FlashlightState_t *lightState)
{
  int v3; // eax
  int ProjectedTexture; // edi

  if ( (_S7_8 & 1) == 0 )
  {
    _S7_8 |= 1u;
    invalidHandle.m_Index = -1;
  }
  v3 = 1025;
  if ( lightState->m_bEnableShadows
    && r_flashlightdepthtexture.m_pParent != nullptr
    && r_flashlightdepthtexture.m_pParent->m_Value.m_nValue != 0 )
  {
    v3 = 1057;
  }
  ProjectedTexture = CClientShadowMgr::CreateProjectedTexture(
                       this,
                       entity: invalidHandle,
                       nEntIndex: -1,
                       flags: v3,
                       pSplitScreenBits: nullptr,
                       bShareProjectedTextureBetweenSplitscreenPlayers: lightState->m_bShareBetweenSplitscreenPlayers);
  this->UpdateFlashlightState(this, a2: ProjectedTexture, a3: lightState);
  this->UpdateProjectedTexture(this, a2: ProjectedTexture, a3: true);
  return ProjectedTexture;
}

//------------------------------------------------------------------------------
// Address: 0x100BDED0
// Name: public: virtual unsigned short CClientShadowMgr::CreateShadow(class CBaseHandle,int,int,class CBitVec<1> __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CClientShadowMgr::CreateShadow(
        CClientShadowMgr *this,
        CBaseHandle entity,
        int nEntIndex,
        int flags,
        CBitVec<1> *pSplitScreenBits)
{
  int ProjectedTexture; // ebx
  IClientRenderable *ClientRenderableFromHandle; // esi
  int v8; // eax
  CClientAlphaProperty *v9; // eax

  ProjectedTexture = CClientShadowMgr::CreateProjectedTexture(
                       this,
                       entity,
                       nEntIndex,
                       flags: flags & 0xFFFFFF78 | 0x82,
                       pSplitScreenBits,
                       bShareProjectedTextureBetweenSplitscreenPlayers: false);
  ClientRenderableFromHandle = CClientEntityList::GetClientRenderableFromHandle(
                                 this: (CClientEntityList *)cl_entitylist.m_Index,
                                 hEnt: entity);
  if ( ClientRenderableFromHandle != nullptr )
  {
    ClientRenderableFromHandle->MarkShadowDirty(this: ClientRenderableFromHandle, a2: true);
    v8 = ClientRenderableFromHandle->GetIClientUnknown(this: ClientRenderableFromHandle);
    v9 = (CClientAlphaProperty *)(*(int (__thiscall **)(int))(*(_DWORD *)v8 + 36))(a1: v8);
    if ( v9 != nullptr )
      CClientAlphaProperty::SetShadowHandle(this: v9, hShadowHandle: ProjectedTexture);
  }
  this->AddToDirtyShadowList_2(this, a2: ProjectedTexture, a3: true);
  return ProjectedTexture;
}

//------------------------------------------------------------------------------
// Address: 0x100BDF60
// Name: public: virtual unsigned short CClientShadowMgr::CreateProjection(struct FlashlightState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CClientShadowMgr::CreateProjection(
        CClientShadowMgr *this,
        const FlashlightState_t *lightState)
{
  int ProjectedTexture; // edi

  if ( (_S8_6 & 1) == 0 )
  {
    _S8_6 |= 1u;
    invalidHandle_0.m_Index = -1;
  }
  ProjectedTexture = CClientShadowMgr::CreateProjectedTexture(
                       this,
                       entity: invalidHandle_0,
                       nEntIndex: -1,
                       flags: 4,
                       pSplitScreenBits: nullptr,
                       bShareProjectedTextureBetweenSplitscreenPlayers: lightState->m_bShareBetweenSplitscreenPlayers);
  this->UpdateFlashlightState(this, a2: ProjectedTexture, a3: lightState);
  this->UpdateProjectedTexture(this, a2: ProjectedTexture, a3: true);
  return ProjectedTexture;
}

//------------------------------------------------------------------------------
// Address: 0x100BDFD0
// Name: public: virtual void CClientShadowMgr::InitRenderTargets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::InitRenderTargets(CClientShadowMgr *this)
{
  void (__thiscall *SetShadowDirection)(struct CClientShadowMgr *, const Vector *); // edx
  int v3; // ecx
  int v4; // eax
  int v5; // eax
  int v6; // eax
  Vector dir; // [esp+10h] [ebp-10h] BYREF

  this->m_bRenderTargetNeedsClear = false;
  CMaterialReference::Init(
    this: &this->m_SimpleShadow,
    pMaterialName: "decals/simpleshadow",
    pTextureGroupName: "Decal textures",
    bComplain: true);
  SetShadowDirection = this->SetShadowDirection;
  dir.x = 0.1;
  dir.y = 0.1;
  dir.z = -1.0;
  SetShadowDirection(this, a2: &dir);
  ((void (__thiscall *)(CClientShadowMgr *, int))this->SetShadowDistance)(a1: this, a2: 1112014848);
  ((void (__thiscall *)(CClientShadowMgr *, int))this->SetShadowBlobbyCutoffArea)(a1: this, a2: 1000593162);
  if ( r_shadowrendertotexture.m_pParent != nullptr && r_shadowrendertotexture.m_pParent->m_Value.m_nValue != 0 )
    CClientShadowMgr::InitRenderToTextureShadows(this);
  if ( r_flashlightdepthtexture.m_pParent != nullptr
    && r_flashlightdepthtexture.m_pParent->m_Value.m_nValue != 0
    && !g_pMaterialSystemHardwareConfig->SupportsShadowDepthTextures(this: g_pMaterialSystemHardwareConfig) )
  {
    ConVar::SetValue(this: (ConVar *)&r_flashlightdepthtexture.IConVar, value: 0);
    CClientShadowMgr::ShutdownDepthTextureShadows(this);
  }
  CClientShadowMgr::InitDepthTextureShadows(this);
  ConVar::SetValue(this: (ConVar *)&r_flashlightdepthres.IConVar, value: this->m_nDepthTextureResolution);
  ConVar::SetValue(this: (ConVar *)&r_flashlightdepthreshigh.IConVar, value: this->m_nDepthTextureResolutionHigh);
  if ( this->m_DepthTextureCache.m_Size != 0 )
  {
    v4 = _CommandLine(a1: v3);
    (*(void (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v4 + 12))(a1: v4, a2: "-tools", a3: 0);
    this->m_nLowResStart = 0;
    v5 = this->m_DepthTextureCache.m_Memory.m_pMemory->m_pTexture->GetActualWidth(this: this->m_DepthTextureCache.m_Memory.m_pMemory->m_pTexture);
    this->m_nDepthTextureResolution = v5;
    ConVar::SetValue(this: (ConVar *)&r_flashlightdepthres.IConVar, value: v5);
    v6 = this->m_DepthTextureCache.m_Memory.m_pMemory->m_pTexture->GetActualWidth(this: this->m_DepthTextureCache.m_Memory.m_pMemory->m_pTexture);
    this->m_nDepthTextureResolutionHigh = v6;
    ConVar::SetValue(this: (ConVar *)&r_flashlightdepthreshigh.IConVar, value: v6);
  }
  materials->AddRestoreFunc(this: materials, a2: (void (__cdecl *)(int))ShadowRestoreFunc);
}

//------------------------------------------------------------------------------
// Address: 0x100BE170
// Name: private: void CClientShadowMgr::UpdateDirtyShadows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::UpdateDirtyShadows(CClientShadowMgr *this)
{
  unsigned __int16 Inorder; // bx
  int m_Data; // eax
  int v4; // ebx
  int v5; // ebx
  void (__thiscall *EndLock)(IMDLCache *); // eax
  unsigned __int16 v7; // cx
  int v8; // ebx
  UtlRBTreeNode_t<unsigned short,unsigned short> *v9; // eax
  UtlRBTreeNode_t<unsigned short,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<unsigned short,unsigned short> *v11; // eax
  _WORD *p_m_Data; // ebx
  int nCount; // [esp+Ch] [ebp-14h]
  IMDLCache *cacheCriticalSection; // [esp+10h] [ebp-10h]
  const unsigned __int16 *cacheCriticalSectiona; // [esp+10h] [ebp-10h]
  int handle; // [esp+14h] [ebp-Ch]
  unsigned __int16 handlea[2]; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h] BYREF
  bool leftchild; // [esp+1Fh] [ebp-1h] BYREF

  if ( r_shadow_debug_spew.m_pParent != nullptr && r_shadow_debug_spew.m_pParent->m_Value.m_nValue != 0 )
    DevMsg(a1: "dirty shadows: %3d\n", this->m_DirtyShadows.m_NumElements);
  Inorder = CUtlRBTree<unsigned short,unsigned short,bool (__cdecl *)(unsigned short const &,unsigned short const &),CUtlMemory<UtlRBTreeNode_t<unsigned short,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_DirtyShadows);
  i = Inorder;
  if ( Inorder != 0xFFFF )
  {
    while ( 1 )
    {
      cacheCriticalSection = mdlcache;
      ((void (*)(void))mdlcache->BeginLock)();
      m_Data = this->m_DirtyShadows.m_Elements.m_pMemory[Inorder].m_Data;
      handle = m_Data;
      if ( this->m_bShadowFromWorldLights && !this->m_bSuppressShadowFromWorldLights )
      {
        CClientShadowMgr::UpdateShadowDirectionFromLocalLightSource(this, shadowHandle: m_Data);
        m_Data = handle;
      }
      v4 = (unsigned __int16)m_Data;
      if ( (this->m_Shadows.m_Memory.m_pMemory[v4].m_Element.m_Flags & 5) != 0 )
      {
        CVProfile::EnterScope(
          this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
          a2: "CClientShadowMgr::UpdateProjectedTextureInternal",
          a3: 0,
          a4: "Flashlight Shadows",
          a5: false,
          a6: 4);
        ((void (__stdcall *)(_DWORD, int))shadowmgr->EnableShadow)(
          a1: this->m_Shadows.m_Memory.m_pMemory[v4].m_Element.m_ShadowHandle,
          a2: 1);
        CClientShadowMgr::UpdateBrushShadow(this, pRenderable: nullptr, handle);
        CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      }
      else
      {
        CClientShadowMgr::UpdateShadow(this, handle: m_Data, force: false);
      }
      v5 = (unsigned __int16)CUtlRBTree<unsigned short,unsigned short,bool (__cdecl *)(unsigned short const &,unsigned short const &),CUtlMemory<UtlRBTreeNode_t<unsigned short,unsigned short>,unsigned short>>::NextInorder(
                               this: &this->m_DirtyShadows,
                               i);
      EndLock = cacheCriticalSection->EndLock;
      i = v5;
      EndLock(this: cacheCriticalSection);
      if ( (_WORD)v5 == 0xFFFF )
        break;
      Inorder = i;
    }
  }
  CUtlRBTree<unsigned short,unsigned short,bool (__cdecl *)(unsigned short const &,unsigned short const &),CUtlMemory<UtlRBTreeNode_t<unsigned short,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_DirtyShadows);
  nCount = this->m_TransparentShadows.m_Size;
  *(_DWORD *)handlea = 0;
  if ( nCount <= 0 )
  {
    this->m_TransparentShadows.m_Size = 0;
  }
  else
  {
    do
    {
      cacheCriticalSectiona = &this->m_TransparentShadows.m_Memory.m_pMemory[*(_DWORD *)handlea];
      i = 0xFFFF;
      leftchild = false;
      CUtlRBTree<unsigned short,unsigned short,bool (__cdecl *)(unsigned short const &,unsigned short const &),CUtlMemory<UtlRBTreeNode_t<unsigned short,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &this->m_DirtyShadows,
        insert: cacheCriticalSectiona,
        parent: (unsigned __int16 *)&i,
        &leftchild);
      v7 = CUtlRBTree<unsigned short,unsigned short,bool (__cdecl *)(unsigned short const &,unsigned short const &),CUtlMemory<UtlRBTreeNode_t<unsigned short,unsigned short>,unsigned short>>::NewNode(
             this: &this->m_DirtyShadows,
             a2: (const char *)this);
      v8 = v7;
      v9 = &this->m_DirtyShadows.m_Elements.m_pMemory[v8];
      v9->m_Parent = i;
      v9->m_Right = -1;
      v9->m_Left = -1;
      v9->m_Tag = 0;
      if ( (_WORD)i == 0xFFFF )
      {
        this->m_DirtyShadows.m_Root = v7;
      }
      else
      {
        m_pMemory = this->m_DirtyShadows.m_Elements.m_pMemory;
        if ( leftchild )
          m_pMemory[(unsigned __int16)i].m_Left = v7;
        else
          m_pMemory[(unsigned __int16)i].m_Right = v7;
      }
      CUtlRBTree<unsigned short,unsigned short,bool (__cdecl *)(unsigned short const &,unsigned short const &),CUtlMemory<UtlRBTreeNode_t<unsigned short,unsigned short>,unsigned short>>::InsertRebalance(
        this: &this->m_DirtyShadows,
        elem: v7);
      v11 = this->m_DirtyShadows.m_Elements.m_pMemory;
      ++this->m_DirtyShadows.m_NumElements;
      p_m_Data = &v11[v8].m_Data;
      if ( p_m_Data != nullptr )
        *p_m_Data = *cacheCriticalSectiona;
      ++*(_DWORD *)handlea;
    }
    while ( *(int *)handlea < nCount );
    this->m_TransparentShadows.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BE3B0
// Name: private: void CClientShadowMgr::UpdateDirtyShadowsHalfRate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::UpdateDirtyShadowsHalfRate(CClientShadowMgr *this)
{
  unsigned __int16 Inorder; // di
  bool v3; // zf
  int v4; // eax
  int v5; // edi
  unsigned __int16 v6; // ax
  int v7; // edi
  int v8; // eax
  int v9; // edi
  void (__thiscall *EndLock)(IMDLCache *); // eax
  int m_NumElements; // ebx
  __int64 v12; // rax
  int v13; // edi
  unsigned int v14; // eax
  const char *v15; // edi
  unsigned __int16 v16; // bx
  int m_Data; // ecx
  unsigned __int16 v18; // cx
  int v19; // ebx
  UtlRBTreeNode_t<unsigned short,unsigned short> *v20; // eax
  UtlRBTreeNode_t<unsigned short,unsigned short> *m_pMemory; // edx
  UtlRBTreeNode_t<unsigned short,unsigned short> *v22; // eax
  _WORD *p_m_Data; // ebx
  unsigned __int16 v24; // cx
  int v25; // ebx
  UtlRBTreeNode_t<unsigned short,unsigned short> *v26; // eax
  UtlRBTreeNode_t<unsigned short,unsigned short> *v27; // edx
  UtlRBTreeNode_t<unsigned short,unsigned short> *v28; // eax
  _WORD *v29; // ebx
  IMDLCache *v30; // [esp+Ch] [ebp-18h]
  const unsigned __int16 *v31; // [esp+Ch] [ebp-18h]
  IMDLCache *cacheCriticalSection; // [esp+10h] [ebp-14h]
  CMDLCacheCriticalSection cacheCriticalSectiona; // [esp+10h] [ebp-14h]
  CMDLCacheCriticalSection cacheCriticalSectionb; // [esp+10h] [ebp-14h]
  const unsigned __int16 *handle; // [esp+14h] [ebp-10h]
  unsigned __int16 *handlea; // [esp+14h] [ebp-10h]
  const unsigned __int16 *handleb; // [esp+14h] [ebp-10h]
  int nNumShadowsToProcess; // [esp+18h] [ebp-Ch] BYREF
  int i; // [esp+1Ch] [ebp-8h]
  bool leftchild; // [esp+23h] [ebp-1h] BYREF

  Inorder = CUtlRBTree<unsigned short,unsigned short,bool (__cdecl *)(unsigned short const &,unsigned short const &),CUtlMemory<UtlRBTreeNode_t<unsigned short,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_DirtyShadowsLeftOver);
  i = Inorder;
  if ( Inorder != 0xFFFF )
  {
    while ( 1 )
    {
      cacheCriticalSection = mdlcache;
      ((void (*)(void))mdlcache->BeginLock)();
      v3 = !this->m_bShadowFromWorldLights;
      handle = &this->m_DirtyShadowsLeftOver.m_Elements.m_pMemory[Inorder].m_Data;
      v4 = *handle;
      nNumShadowsToProcess = v4;
      if ( !v3 && !this->m_bSuppressShadowFromWorldLights )
      {
        CClientShadowMgr::UpdateShadowDirectionFromLocalLightSource(this, shadowHandle: v4);
        v4 = nNumShadowsToProcess;
      }
      v5 = (unsigned __int16)v4;
      if ( (this->m_Shadows.m_Memory.m_pMemory[v5].m_Element.m_Flags & 5) != 0 )
      {
        CVProfile::EnterScope(
          this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
          a2: "CClientShadowMgr::UpdateProjectedTextureInternal",
          a3: 0,
          a4: "Flashlight Shadows",
          a5: false,
          a6: 4);
        ((void (__stdcall *)(_DWORD, int))shadowmgr->EnableShadow)(
          a1: this->m_Shadows.m_Memory.m_pMemory[v5].m_Element.m_ShadowHandle,
          a2: 1);
        CClientShadowMgr::UpdateBrushShadow(this, pRenderable: nullptr, handle: nNumShadowsToProcess);
        CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      }
      else
      {
        CClientShadowMgr::UpdateShadow(this, handle: v4, force: false);
      }
      v6 = CUtlRBTree<unsigned short,unsigned short,bool (__cdecl *)(unsigned short const &,unsigned short const &),CUtlMemory<UtlRBTreeNode_t<unsigned short,unsigned short>,unsigned short>>::Find(
             this: &this->m_DirtyShadows,
             search: handle);
      v7 = v6;
      if ( v6 != 0xFFFF )
      {
        CUtlRBTree<unsigned short,unsigned short,bool (__cdecl *)(unsigned short const &,unsigned short const &),CUtlMemory<UtlRBTreeNode_t<unsigned short,unsigned short>,unsigned short>>::Unlink(
          this: &this->m_DirtyShadows,
          elem: v6);
        v8 = v7;
        this->m_DirtyShadows.m_Elements.m_pMemory[v8].m_Left = v7;
        this->m_DirtyShadows.m_Elements.m_pMemory[v8].m_Right = this->m_DirtyShadows.m_FirstFree;
        --this->m_DirtyShadows.m_NumElements;
        this->m_DirtyShadows.m_FirstFree = v7;
      }
      v9 = (unsigned __int16)CUtlRBTree<unsigned short,unsigned short,bool (__cdecl *)(unsigned short const &,unsigned short const &),CUtlMemory<UtlRBTreeNode_t<unsigned short,unsigned short>,unsigned short>>::NextInorder(
                               this: &this->m_DirtyShadowsLeftOver,
                               i);
      EndLock = cacheCriticalSection->EndLock;
      i = v9;
      EndLock(this: cacheCriticalSection);
      if ( (_WORD)v9 == 0xFFFF )
        break;
      Inorder = i;
    }
  }
  m_NumElements = this->m_DirtyShadowsLeftOver.m_NumElements;
  v12 = m_NumElements + this->m_DirtyShadows.m_NumElements;
  v13 = (((int)v12 - HIDWORD(v12)) >> 1) + 1;
  if ( r_shadow_debug_spew.m_pParent != nullptr && r_shadow_debug_spew.m_pParent->m_Value.m_nValue != 0 )
    DevMsg(a1: "dirty shadows: %3d\n", v13);
  v14 = this->m_DirtyShadows.m_NumElements;
  v15 = (const char *)(v13 - m_NumElements);
  nNumShadowsToProcess = (int)v15 < 0 ? 0 : (unsigned int)v15;
  if ( v14 < nNumShadowsToProcess )
    nNumShadowsToProcess = v14;
  CUtlRBTree<unsigned short,unsigned short,bool (__cdecl *)(unsigned short const &,unsigned short const &),CUtlMemory<UtlRBTreeNode_t<unsigned short,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_DirtyShadowsLeftOver);
  v16 = CUtlRBTree<unsigned short,unsigned short,bool (__cdecl *)(unsigned short const &,unsigned short const &),CUtlMemory<UtlRBTreeNode_t<unsigned short,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_DirtyShadows);
  if ( nNumShadowsToProcess > 0 )
  {
    handlea = (unsigned __int16 *)nNumShadowsToProcess;
    do
    {
      v30 = mdlcache;
      ((void (*)(void))mdlcache->BeginLock)();
      v3 = !this->m_bShadowFromWorldLights;
      m_Data = this->m_DirtyShadows.m_Elements.m_pMemory[v16].m_Data;
      nNumShadowsToProcess = m_Data;
      if ( !v3 && !this->m_bSuppressShadowFromWorldLights )
      {
        CClientShadowMgr::UpdateShadowDirectionFromLocalLightSource(this, shadowHandle: m_Data);
        m_Data = nNumShadowsToProcess;
      }
      cacheCriticalSectiona.m_pCache = (IMDLCache *)(276 * (unsigned __int16)m_Data);
      if ( (*((_BYTE *)&this->m_Shadows.m_Memory.m_pMemory->m_Element.m_Flags
            + (unsigned int)cacheCriticalSectiona.m_pCache)
          & 5) != 0 )
      {
        CVProfile::EnterScope(
          this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
          a2: "CClientShadowMgr::UpdateProjectedTextureInternal",
          a3: 0,
          a4: "Flashlight Shadows",
          a5: false,
          a6: 4);
        shadowmgr->EnableShadow(
          this: shadowmgr,
          a2: *(unsigned __int16 *)((char *)&this->m_Shadows.m_Memory.m_pMemory->m_Element.m_ShadowHandle
                              + (unsigned int)cacheCriticalSectiona.m_pCache),
          a3: true);
        CClientShadowMgr::UpdateBrushShadow(this, pRenderable: nullptr, handle: nNumShadowsToProcess);
        CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      }
      else
      {
        CClientShadowMgr::UpdateShadow(this, handle: m_Data, force: false);
      }
      i = (unsigned __int16)CUtlRBTree<unsigned short,unsigned short,bool (__cdecl *)(unsigned short const &,unsigned short const &),CUtlMemory<UtlRBTreeNode_t<unsigned short,unsigned short>,unsigned short>>::NextInorder(
                              this: &this->m_DirtyShadows,
                              i: v16);
      v30->EndLock(this: v30);
      v3 = handlea == (unsigned __int16 *)1;
      handlea = (unsigned __int16 *)((char *)handlea - 1);
      v16 = i;
    }
    while ( !v3 );
  }
  if ( v16 != 0xFFFF )
  {
    while ( 1 )
    {
      handleb = &this->m_DirtyShadows.m_Elements.m_pMemory[v16].m_Data;
      i = (unsigned __int16)CUtlRBTree<unsigned short,unsigned short,bool (__cdecl *)(unsigned short const &,unsigned short const &),CUtlMemory<UtlRBTreeNode_t<unsigned short,unsigned short>,unsigned short>>::NextInorder(
                              this: &this->m_DirtyShadows,
                              i: v16);
      nNumShadowsToProcess = 0xFFFF;
      leftchild = false;
      CUtlRBTree<unsigned short,unsigned short,bool (__cdecl *)(unsigned short const &,unsigned short const &),CUtlMemory<UtlRBTreeNode_t<unsigned short,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &this->m_DirtyShadowsLeftOver,
        insert: handleb,
        parent: (unsigned __int16 *)&nNumShadowsToProcess,
        &leftchild);
      v18 = CUtlRBTree<unsigned short,unsigned short,bool (__cdecl *)(unsigned short const &,unsigned short const &),CUtlMemory<UtlRBTreeNode_t<unsigned short,unsigned short>,unsigned short>>::NewNode(
              this: &this->m_DirtyShadowsLeftOver,
              a2: v15);
      v19 = v18;
      v20 = &this->m_DirtyShadowsLeftOver.m_Elements.m_pMemory[v19];
      v20->m_Parent = nNumShadowsToProcess;
      v20->m_Right = -1;
      v20->m_Left = -1;
      v20->m_Tag = 0;
      if ( (_WORD)nNumShadowsToProcess == 0xFFFF )
      {
        this->m_DirtyShadowsLeftOver.m_Root = v18;
      }
      else
      {
        m_pMemory = this->m_DirtyShadowsLeftOver.m_Elements.m_pMemory;
        if ( leftchild )
          m_pMemory[(unsigned __int16)nNumShadowsToProcess].m_Left = v18;
        else
          m_pMemory[(unsigned __int16)nNumShadowsToProcess].m_Right = v18;
      }
      CUtlRBTree<unsigned short,unsigned short,bool (__cdecl *)(unsigned short const &,unsigned short const &),CUtlMemory<UtlRBTreeNode_t<unsigned short,unsigned short>,unsigned short>>::InsertRebalance(
        this: &this->m_DirtyShadowsLeftOver,
        elem: v18);
      v22 = this->m_DirtyShadowsLeftOver.m_Elements.m_pMemory;
      ++this->m_DirtyShadowsLeftOver.m_NumElements;
      p_m_Data = &v22[v19].m_Data;
      if ( p_m_Data != nullptr )
        *p_m_Data = *handleb;
      if ( (_WORD)i == 0xFFFF )
        break;
      v16 = i;
    }
  }
  CUtlRBTree<unsigned short,unsigned short,bool (__cdecl *)(unsigned short const &,unsigned short const &),CUtlMemory<UtlRBTreeNode_t<unsigned short,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_DirtyShadows);
  cacheCriticalSectionb.m_pCache = (IMDLCache *)this->m_TransparentShadows.m_Size;
  i = 0;
  if ( (int)cacheCriticalSectionb.m_pCache <= 0 )
  {
    this->m_TransparentShadows.m_Size = 0;
  }
  else
  {
    do
    {
      v31 = &this->m_TransparentShadows.m_Memory.m_pMemory[i];
      nNumShadowsToProcess = 0xFFFF;
      leftchild = false;
      CUtlRBTree<unsigned short,unsigned short,bool (__cdecl *)(unsigned short const &,unsigned short const &),CUtlMemory<UtlRBTreeNode_t<unsigned short,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &this->m_DirtyShadows,
        insert: v31,
        parent: (unsigned __int16 *)&nNumShadowsToProcess,
        &leftchild);
      v24 = CUtlRBTree<unsigned short,unsigned short,bool (__cdecl *)(unsigned short const &,unsigned short const &),CUtlMemory<UtlRBTreeNode_t<unsigned short,unsigned short>,unsigned short>>::NewNode(
              this: &this->m_DirtyShadows,
              a2: v15);
      v25 = v24;
      v26 = &this->m_DirtyShadows.m_Elements.m_pMemory[v25];
      v26->m_Parent = nNumShadowsToProcess;
      v26->m_Right = -1;
      v26->m_Left = -1;
      v26->m_Tag = 0;
      if ( (_WORD)nNumShadowsToProcess == 0xFFFF )
      {
        this->m_DirtyShadows.m_Root = v24;
      }
      else
      {
        v27 = this->m_DirtyShadows.m_Elements.m_pMemory;
        if ( leftchild )
          v27[(unsigned __int16)nNumShadowsToProcess].m_Left = v24;
        else
          v27[(unsigned __int16)nNumShadowsToProcess].m_Right = v24;
      }
      CUtlRBTree<unsigned short,unsigned short,bool (__cdecl *)(unsigned short const &,unsigned short const &),CUtlMemory<UtlRBTreeNode_t<unsigned short,unsigned short>,unsigned short>>::InsertRebalance(
        this: &this->m_DirtyShadows,
        elem: v24);
      v28 = this->m_DirtyShadows.m_Elements.m_pMemory;
      ++this->m_DirtyShadows.m_NumElements;
      v29 = &v28[v25].m_Data;
      if ( v29 != nullptr )
        *v29 = *v31;
      ++i;
    }
    while ( i < (int)cacheCriticalSectionb.m_pCache );
    this->m_TransparentShadows.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BE890
// Name: public: virtual void CClientShadowMgr::ReprojectShadows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CClientShadowMgr::ReprojectShadows(CClientShadowMgr *this)
{
  IMDLCache *v2; // edi
  ConVar *m_pParent; // eax
  int m_nValue; // eax
  bool v5; // dl
  int v6; // eax
  int v7; // ecx
  int v8; // eax

  this->m_nPrevFrameCount = *(_DWORD *)(gpGlobals.m_Index + 4);
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CClientShadowMgr::ReprojectShadows",
    a3: 0,
    a4: "Shadow_Rendering",
    a5: false,
    a6: 4);
  v2 = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  m_pParent = r_flashlightdepthtexture.m_pParent;
  if ( r_flashlightdepthtexture.m_pParent == nullptr )
    goto LABEL_8;
  if ( r_flashlightdepthtexture.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( !g_pMaterialSystemHardwareConfig->SupportsShadowDepthTextures(this: g_pMaterialSystemHardwareConfig) )
    {
      ConVar::SetValue(this: (ConVar *)&r_flashlightdepthtexture.IConVar, value: 0);
      CClientShadowMgr::ShutdownDepthTextureShadows(this);
    }
    m_pParent = r_flashlightdepthtexture.m_pParent;
  }
  if ( m_pParent != nullptr )
    m_nValue = m_pParent->m_Value.m_nValue;
  else
LABEL_8:
    m_nValue = 0;
  v5 = m_nValue != 0;
  if ( r_flashlightdepthres.m_pParent != nullptr )
    v6 = r_flashlightdepthres.m_pParent->m_Value.m_nValue;
  else
    v6 = 0;
  if ( r_flashlightdepthreshigh.m_pParent != nullptr )
    v7 = r_flashlightdepthreshigh.m_pParent->m_Value.m_nValue;
  else
    v7 = 0;
  if ( v5 )
  {
    if ( this->m_bDepthTextureActive
      && (v6 != this->m_nDepthTextureResolution || v7 != this->m_nDepthTextureResolutionHigh) )
    {
      CClientShadowMgr::ShutdownDepthTextureShadows(this);
      CClientShadowMgr::InitDepthTextureShadows(this);
      goto LABEL_23;
    }
  }
  else if ( !v5 )
  {
    goto LABEL_23;
  }
  if ( !this->m_bDepthTextureActive )
  {
    materials->ReEnableRenderTargetAllocation_IRealizeIfICallThisAllTexturesWillBeUnloadedAndLoadTimeWillSufferHorribly(this: materials);
    CClientShadowMgr::InitDepthTextureShadows(this);
    materials->FinishRenderTargetAllocation(this: materials);
  }
LABEL_23:
  if ( r_shadows.m_pParent == nullptr || r_shadows.m_pParent->m_Value.m_nValue == 0 )
  {
    v2->EndLock(this: v2);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return;
  }
  if ( r_shadowrendertotexture.m_pParent != nullptr )
    v8 = r_shadowrendertotexture.m_pParent->m_Value.m_nValue;
  else
    v8 = 0;
  if ( this->m_RenderToTextureActive )
  {
    if ( v8 == 0 )
    {
      materials->ReEnableRenderTargetAllocation_IRealizeIfICallThisAllTexturesWillBeUnloadedAndLoadTimeWillSufferHorribly(this: materials);
      CClientShadowMgr::ShutdownRenderToTextureShadows(this);
      materials->FinishRenderTargetAllocation(this: materials);
      CClientShadowMgr::UpdateAllShadows(this);
      v2->EndLock(this: v2);
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
      return;
    }
  }
  else if ( v8 != 0 )
  {
    materials->ReEnableRenderTargetAllocation_IRealizeIfICallThisAllTexturesWillBeUnloadedAndLoadTimeWillSufferHorribly(this: materials);
    CClientShadowMgr::InitRenderToTextureShadows(this);
    materials->FinishRenderTargetAllocation(this: materials);
    CClientShadowMgr::UpdateAllShadows(this);
    v2->EndLock(this: v2);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    return;
  }
  this->m_bUpdatingDirtyShadows = true;
  if ( r_shadow_half_update_rate.m_pParent != nullptr && r_shadow_half_update_rate.m_pParent->m_Value.m_nValue != 0 )
    CClientShadowMgr::UpdateDirtyShadowsHalfRate(this);
  else
    CClientShadowMgr::UpdateDirtyShadows(this);
  this->m_bUpdatingDirtyShadows = false;
  CClientShadowMgr::DestroyQueuedShadows(this);
  v2->EndLock(this: v2);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10169850
// Name: public: void CUtlMemory<bool,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<bool,int>::Grow(CUtlMemory<unsigned char,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  unsigned __int8 *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 32;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(
                                             this: _g_pMemAlloc,
                                             a2: m_pMemory,
                                             a3: m_nAllocationCount);
    else
      this->m_pMemory = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
  }
}
