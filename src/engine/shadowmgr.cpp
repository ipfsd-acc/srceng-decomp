// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/shadowmgr.cpp
// Functions: 128
// ============================================================

#include "engine\shadowmgr.h"

//------------------------------------------------------------------------------
// Address: 0x1000DFC0
// Name: public: void Ray_t::Init(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Ray_t::Init(Ray_t *this, const Vector *start, const Vector *end)
{
  this->m_Delta.x = end->x - start->x;
  this->m_Delta.y = end->y - start->y;
  this->m_Delta.z = end->z - start->z;
  this->m_IsSwept = (float)((float)((float)(this->m_Delta.x * this->m_Delta.x)
                                  + (float)(this->m_Delta.y * this->m_Delta.y))
                          + (float)(this->m_Delta.z * this->m_Delta.z)) != 0.0;
  this->m_Extents.z = 0.0;
  this->m_Extents.y = 0.0;
  this->m_Extents.x = 0.0;
  this->m_pWorldAxisTransform = nullptr;
  this->m_IsRay = true;
  this->m_StartOffset.z = 0.0;
  this->m_StartOffset.y = 0.0;
  this->m_StartOffset.x = 0.0;
  this->m_Start.Vector = *start;
}

//------------------------------------------------------------------------------
// Address: 0x10063E20
// Name: public: void CUtlMemory<struct CShadowMgr::FlashlightInfo_t __near *,int>::ConvertToGrowableMemory(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CShadowMgr::FlashlightInfo_t *,int>::ConvertToGrowableMemory(
        CUtlMemory<int,int> *this,
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
      this->m_pMemory = (int *)v5;
    }
    else
    {
      this->m_pMemory = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FD890
// Name: public: void CUtlMemoryAligned<class Frustum_t,16>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryAligned<Frustum_t,16>::Grow(CUtlMemoryAligned<Frustum_t,16> *this, int num)
{
  int m_nGrowSize; // ecx
  int m_nAllocationCount; // eax
  int v5; // edx
  Frustum_t *m_pMemory; // ecx
  unsigned int v7; // eax
  void *v8; // eax
  Frustum_t *v9; // ecx

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
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 320 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
    {
      this->m_pMemory = (Frustum_t *)MemAlloc_ReallocAligned(ptr: (unsigned __int8 *)m_pMemory, size: v7, align: 0x10u);
    }
    else
    {
      v8 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7 + 19);
      if ( v8 != nullptr )
      {
        v9 = (Frustum_t *)(((unsigned int)v8 + 19) & 0xFFFFFFF0);
        v9[-1].planes[1].nZAbs.m128_i32[3] = (int)v8;
        this->m_pMemory = v9;
      }
      else
      {
        this->m_pMemory = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10106F50
// Name: public: ShaderStencilState_t::ShaderStencilState_t(void)
// Source: json
//------------------------------------------------------------------------------
ShaderStencilState_t *__thiscall ShaderStencilState_t::ShaderStencilState_t(ShaderStencilState_t *this)
{
  this->m_ZFailOp = SHADER_STENCILOP_KEEP;
  this->m_FailOp = SHADER_STENCILOP_KEEP;
  this->m_PassOp = SHADER_STENCILOP_KEEP;
  this->m_bEnable = false;
  this->m_CompareFunc = SHADER_STENCILFUNC_ALWAYS;
  this->m_nReferenceValue = 0;
  this->m_nWriteMask = -1;
  this->m_nTestMask = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10106F90
// Name: unsigned short __near & FirstShadowOnModel(unsigned short)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 *__cdecl FirstShadowOnModel(unsigned __int16 h)
{
  return FirstShadowOnModelInstance(handle: h);
}

//------------------------------------------------------------------------------
// Address: 0x10106FA0
// Name: public: virtual void CShadowMgr::LevelInit(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CShadowMgr::LevelInit(CShadowMgr *this@<ecx>, int a2@<edi>, int nSurfCount)
{
  int v4; // eax
  unsigned __int16 *v5; // eax

  if ( !this->m_bInitialized )
  {
    this->m_bInitialized = true;
    v4 = ((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(a1: materials, a2);
    (*(void (__thiscall **)(int, bool))(*(_DWORD *)v4 + 724))(a1: v4, a2: this->m_bSinglePassFlashlightStateEnabled);
    v5 = (unsigned __int16 *)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)nSurfCount >> 31 != 0 ? -1 : 2 * nSurfCount);
    this->m_pSurfaceBounds = v5;
    memset(dst: (unsigned __int8 *)v5, value: 0xFFu, count: 2 * nSurfCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10107020
// Name: public: virtual void CShadowMgr::DisableDropShadows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::DisableDropShadows(CShadowMgr *this)
{
  this->m_bShadowsDisabled = true;
}

//------------------------------------------------------------------------------
// Address: 0x10107030
// Name: public: virtual unsigned short CShadowMgr::CreateShadow(class IMaterial __near *,class IMaterial __near *,void __near *,int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CShadowMgr::CreateShadow(
        CShadowMgr *this,
        IMaterial *pMaterial,
        IMaterial *pModelMaterial,
        void *pBindProxy,
        int creationFlags)
{
  return this->CreateShadowEx(this, a2: pMaterial, a3: pModelMaterial, a4: pBindProxy, a5: creationFlags, a6: -1);
}

//------------------------------------------------------------------------------
// Address: 0x10107050
// Name: private: virtual void CShadowMgr::RenderProjectedTextures(class IMatRenderContext __near *,class VMatrix const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::RenderProjectedTextures(
        CShadowMgr *this,
        IMatRenderContext *pRenderContext,
        const VMatrix *pModelToWorld)
{
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CShadowMgr::RenderProjectedTextures",
    a3: 0,
    a4: "Shadow_Rendering",
    a5: false,
    a6: 4);
  this->RenderFlashlights(this, a2: true, a3: false, a4: pModelToWorld);
  this->RenderShadows(this, a2: pRenderContext, a3: pModelToWorld);
  this->ClearShadowRenderList(this);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x101070C0
// Name: ClampTexCoord
// Source: json
//------------------------------------------------------------------------------
void __fastcall ClampTexCoord(ShadowVertex_t *pOutVertex, ShadowVertex_t *pInVertex)
{
  double v2; // st7

  if ( fabs(pInVertex->m_ShadowSpaceTexCoord.x) >= 0.001 )
  {
    v2 = 1.0;
    if ( fabs(pInVertex->m_ShadowSpaceTexCoord.x - 1.0) < 0.001 )
      pOutVertex->m_ShadowSpaceTexCoord.x = 1.0;
  }
  else
  {
    v2 = 1.0;
    pOutVertex->m_ShadowSpaceTexCoord.x = 0.0;
  }
  if ( fabs(pInVertex->m_ShadowSpaceTexCoord.y) >= 0.001 )
  {
    if ( fabs(pInVertex->m_ShadowSpaceTexCoord.y - v2) < 0.001 )
      pOutVertex->m_ShadowSpaceTexCoord.y = 1.0;
  }
  else
  {
    pOutVertex->m_ShadowSpaceTexCoord.y = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10107130
// Name: private: void CShadowMgr::CopyClippedVertices(int,struct ShadowVertex_t __near * __near *,struct ShadowVertex_t __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::CopyClippedVertices(
        CShadowMgr *this,
        int count,
        ShadowVertex_t **ppSrcVert,
        ShadowVertex_t *pDstVert,
        const Vector *vToAdd)
{
  int v5; // edi
  int v6; // ebx
  ShadowVertex_t **v7; // esi
  float *p_z; // eax
  unsigned int v9; // edi
  float *v10; // edx
  float v11; // xmm1_4
  float v12; // xmm2_4
  double v13; // st7
  float *v14; // edx
  float v15; // xmm1_4
  float v16; // xmm2_4
  double v17; // st7
  float *v18; // edx
  float v19; // xmm1_4
  float v20; // xmm2_4
  double v21; // st7
  float *v22; // edx
  float v23; // xmm1_4
  float v24; // xmm2_4
  float *v25; // eax
  ShadowVertex_t *v26; // edx
  float v27; // xmm1_4
  float v28; // xmm2_4

  v5 = count;
  v6 = 0;
  if ( count >= 4 )
  {
    v7 = ppSrcVert + 2;
    p_z = &pDstVert->m_ShadowSpaceTexCoord.z;
    v9 = ((unsigned int)(count - 4) >> 2) + 1;
    v6 = 4 * v9;
    do
    {
      v10 = (float *)*(v7 - 2);
      v11 = v10[1] + vToAdd->y;
      v12 = v10[2] + vToAdd->z;
      *(p_z - 5) = vToAdd->x + *v10;
      *(p_z - 4) = v11;
      *(p_z - 3) = v12;
      *(p_z - 2) = v10[3];
      v7 += 4;
      p_z += 24;
      --v9;
      *(p_z - 25) = v10[4];
      v13 = v10[5];
      v14 = (float *)*(v7 - 5);
      *(p_z - 24) = v13;
      v15 = v14[1] + vToAdd->y;
      v16 = v14[2] + vToAdd->z;
      *(p_z - 23) = vToAdd->x + *v14;
      *(p_z - 22) = v15;
      *(p_z - 21) = v16;
      *(p_z - 20) = v14[3];
      *(p_z - 19) = v14[4];
      v17 = v14[5];
      v18 = (float *)*(v7 - 4);
      *(p_z - 18) = v17;
      v19 = v18[1] + vToAdd->y;
      v20 = v18[2] + vToAdd->z;
      *(p_z - 17) = vToAdd->x + *v18;
      *(p_z - 16) = v19;
      *(p_z - 15) = v20;
      *(p_z - 14) = v18[3];
      *(p_z - 13) = v18[4];
      v21 = v18[5];
      v22 = (float *)*(v7 - 3);
      *(p_z - 12) = v21;
      v23 = v22[1] + vToAdd->y;
      v24 = v22[2] + vToAdd->z;
      *(p_z - 11) = vToAdd->x + *v22;
      *(p_z - 10) = v23;
      *(p_z - 9) = v24;
      *(p_z - 8) = v22[3];
      *(p_z - 7) = v22[4];
      *(p_z - 6) = v22[5];
    }
    while ( v9 != 0 );
    v5 = count;
  }
  if ( v6 < v5 )
  {
    v25 = &pDstVert[v6].m_ShadowSpaceTexCoord.z;
    do
    {
      v26 = ppSrcVert[v6];
      v27 = v26->m_Position.y + vToAdd->y;
      v28 = v26->m_Position.z + vToAdd->z;
      *(v25 - 5) = vToAdd->x + v26->m_Position.x;
      *(v25 - 4) = v27;
      *(v25 - 3) = v28;
      *(v25 - 2) = v26->m_ShadowSpaceTexCoord.x;
      ++v6;
      v25 += 6;
      *(v25 - 7) = v26->m_ShadowSpaceTexCoord.y;
      *(v25 - 6) = v26->m_ShadowSpaceTexCoord.z;
    }
    while ( v6 < count );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101072E0
// Name: DrawShadowID
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawShadowID(unsigned __int16 shadowHandle, const Vector *vecCentroid)
{
  char duration[8]; // [esp+0h] [ebp-20h] BYREF

  V_snprintf(pDest: duration, maxLen: 32, pFormat: "%d", shadowHandle);
  CDebugOverlay::AddTextOverlay(textPos: vecCentroid, duration: 0.0, text: duration);
}

//------------------------------------------------------------------------------
// Address: 0x10107320
// Name: void ConstructNearAndFarPolygons(class Vector __near *,class Vector __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConstructNearAndFarPolygons(Vector *pVecNearPlane, Vector *pVecFarPlane, float flPlaneEpsilon)
{
  const CViewSetup *v3; // esi
  double v4; // st7
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm5_4
  float v17; // xmm7_4
  float v18; // xmm6_4
  float v19; // xmm6_4
  float v20; // xmm7_4
  float v21; // xmm6_4
  float v22; // xmm4_4
  float v23; // xmm6_4
  float v24; // xmm7_4
  float v25; // xmm7_4
  float v26; // xmm6_4
  float v27; // xmm3_4
  float x; // xmm4_4
  float v29; // xmm6_4
  float v30; // xmm3_4
  float v31; // xmm5_4
  float v32; // xmm4_4
  float v33; // xmm3_4
  float v34; // xmm4_4
  float v35; // xmm5_4
  float v36; // xmm3_4
  float v37; // xmm4_4
  float v38; // xmm3_4
  float v39; // xmm4_4
  float v40; // xmm5_4
  float v41; // xmm0_4
  float v42; // xmm1_4
  float v43; // xmm2_4
  float flAspect; // [esp+4h] [ebp-50h] BYREF
  float v45; // [esp+8h] [ebp-4Ch]
  Vector vForward; // [esp+Ch] [ebp-48h]
  float v47; // [esp+1Ch] [ebp-38h]
  float v48; // [esp+20h] [ebp-34h]
  float v49; // [esp+24h] [ebp-30h]
  Vector right; // [esp+28h] [ebp-2Ch] BYREF
  Vector up; // [esp+34h] [ebp-20h] BYREF
  float v52; // [esp+40h] [ebp-14h]
  float v53; // [esp+44h] [ebp-10h]
  float flHalfFarWidth; // [esp+48h] [ebp-Ch]
  float flHalfFarHeight; // [esp+4Ch] [ebp-8h]
  float flHalfNearHeight; // [esp+50h] [ebp-4h]
  float v57; // [esp+5Ch] [ebp+8h]
  float pVecNearPlanea; // [esp+64h] [ebp+10h]
  float pVecNearPlaneb; // [esp+64h] [ebp+10h]

  v3 = g_EngineRenderer->ViewGetCurrent(this: g_EngineRenderer);
  v4 = CalcFovY(flFovX: v3->fov, flAspect: v3->m_flAspectRatio);
  v5 = v3->zNear + flPlaneEpsilon;
  flHalfNearHeight = tan(v3->fov * 0.008726646259971648);
  flHalfFarHeight = v5 * flHalfNearHeight;
  v6 = v3->zFar - flPlaneEpsilon;
  v52 = v6 * flHalfNearHeight;
  flHalfNearHeight = tan(v4 * 0.008726646259971648);
  flHalfFarWidth = v5 * flHalfNearHeight;
  v53 = v6 * flHalfNearHeight;
  AngleVectors(angles: &v3->angles, forward: (Vector *)&flAspect, &right, &up);
  VectorNormalize(vec: (Vector *)&flAspect);
  VectorNormalize(vec: &right);
  VectorNormalize(vec: &up);
  v7 = v3->zNear + flPlaneEpsilon;
  v8 = v45 * v7;
  v9 = vForward.x * v7;
  v10 = v3->origin.x + (float)(flAspect * v7);
  v11 = v3->origin.y + v8;
  v12 = v3->origin.z + v9;
  v13 = up.x * flHalfFarWidth;
  v14 = up.y * flHalfFarWidth;
  v15 = up.z * flHalfFarWidth;
  v47 = right.x * flHalfFarHeight;
  pVecNearPlanea = right.x * flHalfFarHeight;
  flHalfNearHeight = right.y * flHalfFarHeight;
  v48 = right.y * flHalfFarHeight;
  flHalfFarHeight = right.z * flHalfFarHeight;
  v47 = (float)(v10 - v47) - (float)(up.x * flHalfFarWidth);
  v17 = v47;
  v48 = (float)(v11 - v48) - (float)(up.y * flHalfFarWidth);
  pVecNearPlane->z = (float)(v12 - flHalfFarHeight) - (float)(up.z * flHalfFarWidth);
  v18 = flHalfNearHeight;
  pVecNearPlane->x = v17;
  v49 = flHalfFarHeight;
  flAspect = v10 - pVecNearPlanea;
  v45 = v11 - v18;
  pVecNearPlane->y = v48;
  v48 = v45 + v14;
  v19 = (float)(v12 - v49) + v15;
  pVecNearPlane[1].x = flAspect + v13;
  v20 = v48;
  pVecNearPlane[1].z = v19;
  pVecNearPlane[1].y = v20;
  v47 = (float)(pVecNearPlanea + v10) + v13;
  v21 = (float)(flHalfNearHeight + v11) + v14;
  v45 = v14;
  v22 = (float)(flHalfFarHeight + v12) - v15;
  v48 = v21;
  v23 = (float)(flHalfFarHeight + v12) + v15;
  pVecNearPlane[2].x = v47;
  v24 = v48;
  pVecNearPlane[2].z = v23;
  pVecNearPlane[2].y = v24;
  v25 = flHalfNearHeight;
  pVecNearPlane[3].z = v22;
  v26 = (float)(pVecNearPlanea + v10) - v13;
  v27 = v53;
  pVecNearPlaneb = up.y * v53;
  v57 = up.z * v53;
  x = right.x;
  pVecNearPlane[3].x = v26;
  v29 = up.x * v27;
  v30 = v52;
  flHalfFarHeight = x * v52;
  v31 = x * v52;
  v32 = right.y * v52;
  flHalfFarWidth = right.y * v52;
  pVecNearPlane[3].y = (float)(v25 + v11) - v45;
  flHalfNearHeight = right.z * v30;
  vForward.x = right.z * v30;
  v33 = v10 - v31;
  pVecFarPlane->y = (float)(v11 - v32) - pVecNearPlaneb;
  v34 = flHalfFarWidth;
  pVecFarPlane->z = (float)(v12 - vForward.x) - v57;
  v35 = flHalfNearHeight;
  pVecFarPlane->x = v33 - v29;
  pVecFarPlane[1].x = (float)(flHalfFarHeight + v10) - v29;
  v36 = flHalfFarHeight;
  pVecFarPlane[1].y = (float)(v34 + v11) - pVecNearPlaneb;
  v37 = flHalfFarWidth;
  pVecFarPlane[1].z = (float)(v35 + v12) - v57;
  v38 = (float)(v36 + v10) + v29;
  v39 = (float)(v37 + v11) + pVecNearPlaneb;
  v40 = (float)(flHalfNearHeight + v12) + v57;
  v41 = v10 - flHalfFarHeight;
  v42 = (float)(v11 - flHalfFarWidth) + pVecNearPlaneb;
  v43 = (float)(v12 - flHalfNearHeight) + v57;
  pVecFarPlane[2].x = v38;
  pVecFarPlane[2].y = v39;
  pVecFarPlane[2].z = v40;
  pVecFarPlane[3].x = v41 + v29;
  pVecFarPlane[3].y = v42;
  pVecFarPlane[3].z = v43;
}

//------------------------------------------------------------------------------
// Address: 0x10107780
// Name: void DrawDebugPolygon(int,class Vector __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawDebugPolygon(int nNumVerts, Vector *pVecPoints, bool bFrontFacing, bool bNearPlane)
{
  bool v4; // cl
  int v5; // eax
  int v6; // esi
  float y; // edx
  int v8; // eax
  Vector *v9; // eax
  float v10; // edx
  int v11; // eax
  float x; // edx
  Vector *v13; // eax
  float v14; // ecx
  float z; // edx
  Vector *v16; // esi
  int v17; // edi
  float v18; // ecx
  Vector *v19; // eax
  float v20; // edx
  float v21; // eax
  Vector flDuration; // [esp+0h] [ebp-30h] BYREF
  Vector p2; // [esp+Ch] [ebp-24h] BYREF
  Vector p3; // [esp+18h] [ebp-18h] BYREF
  int v25; // [esp+24h] [ebp-Ch]
  Vector v2; // [esp+28h] [ebp-8h]

  v4 = bFrontFacing;
  v5 = 0;
  v2.x = 0.0;
  v25 = 0;
  v2.y = 0.0;
  if ( bFrontFacing )
    LODWORD(v2.y) = 255;
  else
    LODWORD(v2.x) = 255;
  if ( bNearPlane )
  {
    v2.y = 0.0;
    v2.x = 0.0;
    v25 = 255;
  }
  v6 = 1;
  if ( nNumVerts - 1 > 1 )
  {
    while ( 1 )
    {
      y = pVecPoints->y;
      flDuration.x = pVecPoints->x;
      flDuration.z = pVecPoints->z;
      flDuration.y = y;
      v8 = v6;
      if ( !v4 )
        v8 = v6 + 1;
      v9 = &pVecPoints[v8];
      p2.x = v9->x;
      v10 = v9->y;
      p2.z = v9->z;
      p2.y = v10;
      v11 = v6 + 1;
      if ( !v4 )
        v11 = v6;
      x = pVecPoints[v11].x;
      v13 = &pVecPoints[v11];
      v14 = v13->y;
      p3.x = x;
      z = v13->z;
      p3.y = v14;
      p3.z = z;
      CDebugOverlay::AddTriangleOverlay(
        p1: &flDuration,
        &p2,
        &p3,
        r: SLODWORD(v2.x),
        g: v25,
        b: SLODWORD(v2.y),
        a: (const Vector *)0x14,
        noDepthTest: true,
        flDuration: 0.0);
      if ( ++v6 >= nNumVerts - 1 )
        break;
      v4 = bFrontFacing;
    }
    v5 = 0;
  }
  if ( nNumVerts > 0 )
  {
    v16 = pVecPoints;
    do
    {
      v17 = v5 + 1;
      p2 = *v16;
      v18 = pVecPoints[(v5 + 1) % nNumVerts].x;
      v19 = &pVecPoints[(v5 + 1) % nNumVerts];
      v20 = v19->y;
      v21 = v19->z;
      flDuration.x = v18;
      flDuration.y = v20;
      flDuration.z = v21;
      CDebugOverlay::AddLineOverlay(
        origin: &p2,
        dest: &flDuration,
        r: 255,
        g: 255,
        b: 255,
        a: 255,
        noDepthTest: false,
        flDuration: 0.0);
      v5 = v17;
      ++v16;
    }
    while ( v17 < nNumVerts );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101078E0
// Name: int ClipPlaneToFrustum(class Vector __near *,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClipPlaneToFrustum(Vector *pInPoints, Vector *pOutPoints, Vector *pVecWorldFrustumPoints)
{
  int v3; // edi
  bool v4; // bl
  Vector *v5; // esi
  int v6; // eax
  int v7; // esi
  unsigned __int8 *p_outVerts; // ecx
  float v10; // [esp+4h] [ebp-110h]
  Vector inVerts; // [esp+14h] [ebp-100h] BYREF
  Vector outVerts; // [esp+8Ch] [ebp-88h] BYREF
  Vector v13; // [esp+98h] [ebp-7Ch]
  Vector v14; // [esp+A4h] [ebp-70h]
  Vector v15; // [esp+B0h] [ebp-64h]
  Vector normal; // [esp+104h] [ebp-10h] BYREF
  float v17; // [esp+110h] [ebp-4h] BYREF
  int v18; // [esp+11Ch] [ebp+8h]

  outVerts = *pInPoints;
  v13 = pInPoints[1];
  v14 = pInPoints[2];
  v15 = pInPoints[3];
  v3 = 0;
  v4 = true;
  v18 = 4;
  v5 = pVecWorldFrustumPoints + 1;
  do
  {
    if ( v18 < 3 )
      return 0;
    ComputeTrianglePlane(v1: v5 - 1, v2: v5, v3: v5 + 1, &normal, intercept: &v17);
    v10 = 0.1;
    if ( v4 )
      v6 = ClipPolyToPlane(
             inVerts: &outVerts,
             vertCount: v18,
             outVerts: &inVerts,
             &normal,
             dist: v17,
             fOnPlaneEpsilon: v10);
    else
      v6 = ClipPolyToPlane(&inVerts, vertCount: v18, &outVerts, &normal, dist: v17, fOnPlaneEpsilon: v10);
    v4 = !v4;
    ++v3;
    v5 += 4;
    v18 = v6;
  }
  while ( v3 < 6 );
  v7 = v6;
  if ( v6 < 3 )
    return 0;
  p_outVerts = (unsigned __int8 *)&outVerts;
  if ( !v4 )
    p_outVerts = (unsigned __int8 *)&inVerts;
  memcpy(dst: (unsigned __int8 *)pOutPoints, src: p_outVerts, count: 12 * v6);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10107A40
// Name: public: virtual void CShadowMgr::SetSinglePassFlashlightRenderState(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::SetSinglePassFlashlightRenderState(CShadowMgr *this, int handle)
{
  bool v2; // zf
  CShadowMgr_vtbl *v3; // edx

  v2 = !this->m_bSinglePassFlashlightStateEnabled;
  v3 = this->IShadowMgrInternal::IShadowMgr::__vftable;
  this->m_hSinglePassFlashlightState = handle;
  if ( v2 )
    ((void (__stdcall *)(int))v3->SetFlashlightRenderState)(a1: 0xFFFF);
  else
    ((void (__stdcall *)(int))v3->SetFlashlightRenderState)(a1: handle);
}

//------------------------------------------------------------------------------
// Address: 0x10107A70
// Name: public: virtual bool CShadowMgr::SinglePassFlashlightModeEnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShadowMgr::SinglePassFlashlightModeEnabled(CShadowMgr *this)
{
  return this->m_bSinglePassFlashlightStateEnabled;
}

//------------------------------------------------------------------------------
// Address: 0x10107A80
// Name: public: virtual void CShadowMgr::SkipShadowForEntity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::SkipShadowForEntity(CShadowMgr *this, int nEntIndex)
{
  this->m_nSkipShadowForEntIndex = nEntIndex;
}

//------------------------------------------------------------------------------
// Address: 0x10107A90
// Name: public: FlashlightState_t::FlashlightState_t(void)
// Source: json
//------------------------------------------------------------------------------
FlashlightState_t *__thiscall FlashlightState_t::FlashlightState_t(FlashlightState_t *this)
{
  this->m_uberlightState.m_fNearEdge = 2.0;
  this->m_uberlightState.m_fFarEdge = 100.0;
  this->m_uberlightState.m_fCutOn = 10.0;
  this->m_uberlightState.m_fWedge = 0.050000001;
  this->m_uberlightState.m_fHedge = 0.050000001;
  this->m_uberlightState.m_fCutOff = 650.0;
  this->m_uberlightState.m_fWidth = 0.30000001;
  this->m_uberlightState.m_fHeight = 0.30000001;
  this->m_uberlightState.m_fShearx = 0.0;
  this->m_uberlightState.m_fSheary = 0.0;
  this->m_uberlightState.m_fRoundness = 0.80000001;
  this->m_flShadowMapResolution = 1024.0;
  this->m_flShadowFilterSize = 3.0;
  this->m_flShadowSlopeScaleDepthBias = 16.0;
  this->m_flShadowJitterSeed = 0.0;
  this->m_flShadowAtten = 0.0;
  this->m_flAmbientOcclusion = 0.0;
  this->m_flNoiseStrength = 0.80000001;
  this->m_flFlashlightTime = 0.0;
  this->m_flPlaneOffset = 0.0;
  *(_WORD *)&this->m_bEnableShadows = 0;
  this->m_flShadowDepthBias = 0.00050000002;
  this->m_nShadowQuality = 0;
  this->m_bShadowHighRes = false;
  this->m_nLeft = -1;
  this->m_nTop = -1;
  this->m_nRight = -1;
  this->m_nBottom = -1;
  this->m_bUberlight = false;
  this->m_bVolumetric = false;
  this->m_nNumPlanes = 64;
  this->m_flVolumetricIntensity = 1.0;
  this->m_bOrtho = false;
  this->m_fOrthoLeft = -1.0;
  this->m_fOrthoRight = 1.0;
  this->m_fOrthoTop = -1.0;
  this->m_fOrthoBottom = 1.0;
  this->m_fBrightnessScale = 1.0;
  this->m_pSpotlightTexture = nullptr;
  this->m_pProjectedMaterial = nullptr;
  *(_WORD *)&this->m_bShareBetweenSplitscreenPlayers = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10107C20
// Name: public: void Ray_t::Init(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Ray_t::Init(
        Ray_t *this,
        const Vector *start,
        const Vector *end,
        const Vector *mins,
        const Vector *maxs)
{
  this->m_Delta.x = end->x - start->x;
  this->m_Delta.y = end->y - start->y;
  this->m_Delta.z = end->z - start->z;
  this->m_pWorldAxisTransform = nullptr;
  this->m_IsSwept = (float)((float)((float)(this->m_Delta.x * this->m_Delta.x)
                                  + (float)(this->m_Delta.y * this->m_Delta.y))
                          + (float)(this->m_Delta.z * this->m_Delta.z)) != 0.0;
  this->m_Extents.x = maxs->x - mins->x;
  this->m_Extents.y = maxs->y - mins->y;
  this->m_Extents.z = maxs->z - mins->z;
  this->m_Extents.x = this->m_Extents.x * 0.5;
  this->m_Extents.y = this->m_Extents.y * 0.5;
  this->m_Extents.z = this->m_Extents.z * 0.5;
  this->m_IsRay = this->m_Extents.y * this->m_Extents.y
                + this->m_Extents.x * this->m_Extents.x
                + this->m_Extents.z * this->m_Extents.z < 0.000001;
  this->m_StartOffset.x = mins->x + maxs->x;
  this->m_StartOffset.y = maxs->y + mins->y;
  this->m_StartOffset.z = mins->z + maxs->z;
  this->m_StartOffset.x = this->m_StartOffset.x * 0.5;
  this->m_StartOffset.y = this->m_StartOffset.y * 0.5;
  this->m_StartOffset.z = this->m_StartOffset.z * 0.5;
  this->m_Start.x = start->x + this->m_StartOffset.x;
  this->m_Start.y = this->m_StartOffset.y + start->y;
  this->m_Start.z = this->m_StartOffset.z + start->z;
  this->m_StartOffset.x = this->m_StartOffset.x * -1.0;
  this->m_StartOffset.y = this->m_StartOffset.y * -1.0;
  this->m_StartOffset.z = this->m_StartOffset.z * -1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10107DF0
// Name: public: void CUtlMemoryAligned<struct UtlLinkedListElem_t<struct CShadowMgr::Shadow_t,unsigned short>,16>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>::Grow(
        CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16> *this,
        int num)
{
  int m_nGrowSize; // ecx
  int m_nAllocationCount; // eax
  int v5; // edx
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *m_pMemory; // ecx
  unsigned int v7; // eax
  void *v8; // eax
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v9; // ecx

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
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 336 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
    {
      this->m_pMemory = (UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *)MemAlloc_ReallocAligned(
                                                                                      ptr: m_pMemory,
                                                                                      size: v7,
                                                                                      align: 0x10u);
    }
    else
    {
      v8 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7 + 19);
      if ( v8 != nullptr )
      {
        v9 = (UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *)(((unsigned int)v8 + 19) & 0xFFFFFFF0);
        *(_DWORD *)(&v9[-1].m_Next + 5) = v8;
        this->m_pMemory = v9;
      }
      else
      {
        this->m_pMemory = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10107E80
// Name: public: void CUtlMemoryAligned<struct UtlLinkedListElem_t<struct CShadowMgr::FlashlightInfo_t,unsigned short>,16>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16>::Grow(
        CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16> *this,
        int num)
{
  int m_nGrowSize; // ecx
  int m_nAllocationCount; // eax
  int v5; // edx
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *m_pMemory; // ecx
  unsigned int v7; // eax
  void *v8; // eax
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *v9; // ecx

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
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 768 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
    {
      this->m_pMemory = (UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *)MemAlloc_ReallocAligned(
                                                                                              ptr: m_pMemory,
                                                                                              size: v7,
                                                                                              align: 0x10u);
    }
    else
    {
      v8 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7 + 19);
      if ( v8 != nullptr )
      {
        v9 = (UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *)(((unsigned int)v8 + 19) & 0xFFFFFFF0);
        *(_DWORD *)(&v9[-1].m_Next + 5) = v8;
        this->m_pMemory = v9;
      }
      else
      {
        this->m_pMemory = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10107F10
// Name: public: int CJob::Abort(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJob::Abort(CJob *this, BOOL bDiscard)
{
  int result; // eax
  CThreadFastMutex *p_m_mutex; // edi
  DWORD CurrentThreadId; // ecx
  bool v6; // bl
  int v7; // eax
  int m_status; // [esp+10h] [ebp+8h]

  result = this->m_status;
  if ( result == 1 || result == 2 || result == 4 )
  {
    p_m_mutex = &this->m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != p_m_mutex->m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_mutex.m_depth;
    }
    this->AddRef(this);
    switch ( this->m_status )
    {
      case 1:
      case 4:
        v6 = bDiscard;
        v7 = this->DoAbort(this, a2: bDiscard);
        this->m_status = v7;
        m_status = v7;
        if ( v6 )
          this->DoCleanup(this);
        CThreadEvent::Set(this: &this->m_CompleteEvent);
        break;
      default:
        m_status = this->m_status;
        break;
    }
    this->Release(this);
    if ( this->m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return m_status;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10107FE0
// Name: private: void CShadowMgr::ComputeSurfaceBounds(struct CShadowMgr::SurfaceBounds_t __near *,struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::ComputeSurfaceBounds(
        CShadowMgr *this,
        CShadowMgr::SurfaceBounds_t *pBounds,
        msurface2_t *nSurfID)
{
  float v4; // xmm1_4
  msurface2_t *v5; // esi
  int flags_high; // edi
  int v7; // edx
  mvertex_t *vertexes; // edi
  float v9; // xmm0_4
  __m128 *v10; // ecx
  __m128 v11; // xmm0
  __m128 v12; // xmm0
  int v13; // edx
  worldbrushdata_t *worldbrush; // ecx
  mvertex_t *v15; // edi
  int v16; // esi
  float v17; // xmm0_4
  mvertex_t *v18; // edi
  float x; // xmm2_4
  float y; // xmm0_4
  float z; // xmm3_4
  float v22; // xmm0_4
  mvertex_t *v23; // edi
  float v24; // xmm2_4
  float v25; // xmm0_4
  float v26; // xmm3_4
  float v27; // xmm0_4
  mvertex_t *v28; // edi
  float v29; // xmm2_4
  float v30; // xmm0_4
  float v31; // xmm3_4
  float v32; // xmm0_4
  float m_flRadius; // xmm3_4
  mvertex_t *v34; // edi
  int v35; // esi
  float v36; // xmm0_4
  int nCount; // [esp+8h] [ebp+8h]

  v4 = 0.0;
  pBounds->m_vecCenter.x = 0.0;
  pBounds->m_vecCenter.y = 0.0;
  pBounds->m_vecCenter.z = 0.0;
  pBounds->m_vecMins = _mm_shuffle_ps((__m128)0x7F7FFFFFu, (__m128)0x7F7FFFFFu, 0);
  v5 = nSurfID;
  pBounds->m_vecMaxs = _mm_shuffle_ps((__m128)0xFF7FFFFF, (__m128)0xFF7FFFFF, 0);
  flags_high = HIBYTE(nSurfID->flags);
  v7 = 0;
  nCount = flags_high;
  if ( HIBYTE(nSurfID->flags) != 0 )
  {
    do
    {
      vertexes = host_state.worldbrush->vertexes;
      v9 = vertexes[host_state.worldbrush->vertindices[v7 + nSurfID->firstvertindex]].position.x
         + pBounds->m_vecCenter.x;
      v10 = (__m128 *)&vertexes[host_state.worldbrush->vertindices[v7 + nSurfID->firstvertindex]];
      flags_high = nCount;
      pBounds->m_vecCenter.x = v9;
      pBounds->m_vecCenter.y = v10->m128_f32[1] + pBounds->m_vecCenter.y;
      pBounds->m_vecCenter.z = v10->m128_f32[2] + pBounds->m_vecCenter.z;
      v11 = _mm_max_ps(*v10, pBounds->m_vecMaxs);
      ++v7;
      pBounds->m_vecMins = _mm_min_ps(*v10, pBounds->m_vecMins);
      pBounds->m_vecMaxs = v11;
    }
    while ( v7 < nCount );
  }
  v12 = _mm_shuffle_ps((__m128)0x3A83126Fu, (__m128)0x3A83126Fu, 0);
  pBounds->m_vecMins = _mm_and_ps(_mm_sub_ps(pBounds->m_vecMins, v12), *(__m128 *)g_SIMD_clear_wmask);
  pBounds->m_vecMaxs = _mm_and_ps(_mm_add_ps(pBounds->m_vecMaxs, v12), *(__m128 *)g_SIMD_clear_wmask);
  v12.m128_f32[0] = 1.0 / (float)flags_high;
  pBounds->m_vecCenter.x = v12.m128_f32[0] * pBounds->m_vecCenter.x;
  pBounds->m_vecCenter.y = pBounds->m_vecCenter.y * v12.m128_f32[0];
  pBounds->m_vecCenter.z = pBounds->m_vecCenter.z * v12.m128_f32[0];
  v13 = 0;
  pBounds->m_flRadius = 0.0;
  worldbrush = host_state.worldbrush;
  if ( flags_high >= 4 )
  {
    do
    {
      v15 = worldbrush->vertexes;
      v16 = worldbrush->vertindices[v13 + v5->firstvertindex];
      v17 = (float)((float)((float)(v15[v16].position.y - pBounds->m_vecCenter.y)
                          * (float)(v15[v16].position.y - pBounds->m_vecCenter.y))
                  + (float)((float)(v15[v16].position.x - pBounds->m_vecCenter.x)
                          * (float)(v15[v16].position.x - pBounds->m_vecCenter.x)))
          + (float)((float)(v15[v16].position.z - pBounds->m_vecCenter.z)
                  * (float)(v15[v16].position.z - pBounds->m_vecCenter.z));
      if ( v17 > v4 )
      {
        pBounds->m_flRadius = v17;
        worldbrush = host_state.worldbrush;
        v4 = v17;
      }
      v18 = worldbrush->vertexes;
      x = v18[worldbrush->vertindices[v13 + 1 + nSurfID->firstvertindex]].position.x;
      y = v18[worldbrush->vertindices[v13 + 1 + nSurfID->firstvertindex]].position.y;
      z = v18[worldbrush->vertindices[v13 + 1 + nSurfID->firstvertindex]].position.z;
      v22 = (float)((float)((float)(y - pBounds->m_vecCenter.y) * (float)(y - pBounds->m_vecCenter.y))
                  + (float)((float)(x - pBounds->m_vecCenter.x) * (float)(x - pBounds->m_vecCenter.x)))
          + (float)((float)(z - pBounds->m_vecCenter.z) * (float)(z - pBounds->m_vecCenter.z));
      if ( v22 > v4 )
      {
        pBounds->m_flRadius = v22;
        worldbrush = host_state.worldbrush;
        v4 = v22;
      }
      v23 = worldbrush->vertexes;
      v24 = v23[worldbrush->vertindices[v13 + 2 + nSurfID->firstvertindex]].position.x;
      v25 = v23[worldbrush->vertindices[v13 + 2 + nSurfID->firstvertindex]].position.y;
      v26 = v23[worldbrush->vertindices[v13 + 2 + nSurfID->firstvertindex]].position.z;
      v27 = (float)((float)((float)(v25 - pBounds->m_vecCenter.y) * (float)(v25 - pBounds->m_vecCenter.y))
                  + (float)((float)(v24 - pBounds->m_vecCenter.x) * (float)(v24 - pBounds->m_vecCenter.x)))
          + (float)((float)(v26 - pBounds->m_vecCenter.z) * (float)(v26 - pBounds->m_vecCenter.z));
      if ( v27 > v4 )
      {
        pBounds->m_flRadius = v27;
        worldbrush = host_state.worldbrush;
        v4 = v27;
      }
      v28 = worldbrush->vertexes;
      v29 = v28[worldbrush->vertindices[v13 + 3 + nSurfID->firstvertindex]].position.x;
      v30 = v28[worldbrush->vertindices[v13 + 3 + nSurfID->firstvertindex]].position.y;
      v31 = v28[worldbrush->vertindices[v13 + 3 + nSurfID->firstvertindex]].position.z;
      v32 = (float)((float)((float)(v30 - pBounds->m_vecCenter.y) * (float)(v30 - pBounds->m_vecCenter.y))
                  + (float)((float)(v29 - pBounds->m_vecCenter.x) * (float)(v29 - pBounds->m_vecCenter.x)))
          + (float)((float)(v31 - pBounds->m_vecCenter.z) * (float)(v31 - pBounds->m_vecCenter.z));
      if ( v32 > v4 )
      {
        pBounds->m_flRadius = v32;
        worldbrush = host_state.worldbrush;
        v4 = v32;
      }
      flags_high = nCount;
      v13 += 4;
      v5 = nSurfID;
    }
    while ( v13 < nCount - 3 );
  }
  if ( v13 < flags_high )
  {
    m_flRadius = pBounds->m_flRadius;
    while ( 1 )
    {
      v34 = worldbrush->vertexes;
      v35 = worldbrush->vertindices[v13 + v5->firstvertindex];
      v36 = (float)((float)((float)(v34[v35].position.y - pBounds->m_vecCenter.y)
                          * (float)(v34[v35].position.y - pBounds->m_vecCenter.y))
                  + (float)((float)(v34[v35].position.x - pBounds->m_vecCenter.x)
                          * (float)(v34[v35].position.x - pBounds->m_vecCenter.x)))
          + (float)((float)(v34[v35].position.z - pBounds->m_vecCenter.z)
                  * (float)(v34[v35].position.z - pBounds->m_vecCenter.z));
      if ( v36 > m_flRadius )
      {
        pBounds->m_flRadius = v36;
        worldbrush = host_state.worldbrush;
        m_flRadius = v36;
      }
      if ( ++v13 >= nCount )
        break;
      v5 = nSurfID;
    }
  }
  pBounds->m_flRadius = sqrt(pBounds->m_flRadius);
}

//------------------------------------------------------------------------------
// Address: 0x10108350
// Name: private: bool CShadowMgr::ProjectVerticesIntoShadowSpace(class VMatrix const restrict __near *,float,int,class Vector __near * restrict __near *,struct ShadowClipState_t __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShadowMgr::ProjectVerticesIntoShadowSpace(
        CShadowMgr *this,
        const VMatrix *modelToShadow,
        float maxDist,
        int count,
        Vector **ppPosition,
        ShadowClipState_t *clip)
{
  int v7; // edx
  double v9; // st7
  double v10; // st6
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm5_4
  ShadowVertex_t **v14; // edi
  float *p_y; // ecx
  Vector *v16; // eax
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  double v20; // st4
  double v21; // st5
  double v22; // rt1
  double v23; // st4
  double v24; // st5
  double v25; // st4
  double v26; // st2
  double v27; // st3
  double v28; // st5
  double v29; // st4
  bool result; // al
  float maxs; // [esp+0h] [ebp-34h]
  float maxs_4; // [esp+4h] [ebp-30h]
  float maxs_8; // [esp+8h] [ebp-2Ch]
  float mins; // [esp+Ch] [ebp-28h]
  float mins_4; // [esp+10h] [ebp-24h]
  float mins_8; // [esp+14h] [ebp-20h]
  float v37; // [esp+18h] [ebp-1Ch]
  float v38; // [esp+1Ch] [ebp-18h]
  float v39; // [esp+20h] [ebp-14h]
  float v40; // [esp+24h] [ebp-10h]
  float v41; // [esp+28h] [ebp-Ch]
  float v42; // [esp+2Ch] [ebp-8h]
  float v43; // [esp+30h] [ebp-4h]
  float modelToShadowa; // [esp+3Ch] [ebp+8h]
  float counta; // [esp+44h] [ebp+10h]

  mins = 1.0;
  mins_4 = 1.0;
  v7 = 0;
  maxs = 0.0;
  maxs_8 = 0.0;
  if ( count <= 0 )
    goto LABEL_23;
  v9 = maxDist;
  v10 = 0.0;
  v11 = modelToShadow->m[0][1];
  v12 = modelToShadow->m[0][0];
  v13 = modelToShadow->m[0][2];
  counta = modelToShadow->m[0][3];
  modelToShadowa = modelToShadow->m[1][1];
  v43 = modelToShadow->m[1][0];
  v42 = modelToShadow->m[1][2];
  v41 = modelToShadow->m[1][3];
  v40 = modelToShadow->m[2][1];
  v39 = modelToShadow->m[2][0];
  v38 = modelToShadow->m[2][2];
  v14 = clip->m_ppClipVertices[0];
  v37 = modelToShadow->m[2][3];
  p_y = &clip->m_pTempVertices[0].m_ShadowSpaceTexCoord.y;
  do
  {
    v16 = ppPosition[v7];
    x = v16->x;
    y = v16->y;
    z = v16->z;
    *(p_y - 1) = (float)((float)((float)(v11 * y) + (float)(v12 * v16->x)) + (float)(v13 * z)) + counta;
    v20 = *(p_y - 1);
    v21 = v20;
    *p_y = (float)((float)((float)(modelToShadowa * y) + (float)(v43 * x)) + (float)(v42 * z)) + v41;
    *(p_y - 3) = y;
    *(p_y - 4) = x;
    *(p_y - 2) = z;
    p_y[1] = (float)((float)((float)(v40 * y) + (float)(v39 * x)) + (float)(v38 * z)) + v37;
    if ( mins <= v20 )
      v21 = mins;
    v22 = v20;
    v23 = v21;
    v24 = v22;
    mins = v23;
    v25 = *p_y;
    if ( mins_4 <= v25 )
      v25 = mins_4;
    mins_4 = v25;
    v26 = v9;
    v9 = p_y[1];
    if ( v26 <= v9 )
      v9 = v26;
    if ( maxs >= v24 )
      v24 = maxs;
    v27 = v24;
    v28 = p_y[1];
    maxs = v27;
    v29 = v10;
    v10 = *p_y;
    if ( v29 >= v10 )
      v10 = v29;
    if ( maxs_8 >= v28 )
      v28 = maxs_8;
    *v14 = (ShadowVertex_t *)(p_y - 4);
    maxs_8 = v28;
    ++v7;
    ++v14;
    p_y += 6;
  }
  while ( v7 < count );
  if ( mins >= 1.0 || maxs <= 0.0 || mins_4 >= 1.0 || (maxs_4 = v10) <= 0.0 || (mins_8 = v9) >= maxDist || maxs_8 <= 0.0 )
LABEL_23:
    result = false;
  else
    result = true;
  clip->m_ClipCount = count;
  clip->m_TempCount = count;
  clip->m_CurrVert = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101085A0
// Name: private: bool CShadowMgr::GenerateDispShadowRenderInfo(struct CShadowMgr::ShadowDecal_t __near &,struct CShadowMgr::ShadowRenderInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShadowMgr::GenerateDispShadowRenderInfo(
        CShadowMgr *this,
        CShadowMgr::ShadowDecal_t *decal,
        CShadowMgr::ShadowRenderInfo_t *info)
{
  CShadowMgr::ShadowRenderInfo_t *v3; // esi
  bool result; // al
  CShadowMgr::ShadowDecal_t *v5; // edi
  char *v6; // ecx
  char *v7; // eax
  unsigned __int16 *m_pDispCache; // edx
  int m_DispCount; // ecx

  v3 = info;
  if ( info->m_DispCount < 0x10000 )
  {
    v5 = decal;
    result = decal->m_SurfID->pDispInfo->ComputeShadowFragments(
               this: decal->m_SurfID->pDispInfo,
               a2: decal->m_DispShadow,
               a3: (int *)&info,
               a4: (int *)&decal);
    if ( result )
    {
      v6 = (char *)info + v3->m_VertexCount;
      if ( (int)v6 >= v3->m_nMaxVertices )
        return true;
      v7 = (char *)decal + v3->m_IndexCount;
      if ( (int)v7 >= v3->m_nMaxIndices )
      {
        return true;
      }
      else
      {
        m_pDispCache = v3->m_pDispCache;
        v3->m_VertexCount = (int)v6;
        m_DispCount = v3->m_DispCount;
        v3->m_IndexCount = (int)v7;
        m_pDispCache[m_DispCount] = v5->m_DispShadow;
        ++v3->m_DispCount;
        return true;
      }
    }
  }
  else
  {
    info->m_DispCount = 0x10000;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10108620
// Name: bool ScreenSpaceRectFromPoints(class IMatRenderContext __near *,class Vector (__near * const)[10],int __near *,int,int __near *,int __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __usercall ScreenSpaceRectFromPoints@<al>(
        int a1@<esi>,
        IMatRenderContext *pRenderContext,
        Vector (*vClippedPolygons)[10],
        int *pNumPoints,
        int nNumPolygons,
        int *nLeft,
        int *nTop,
        int *nRight,
        int *nBottom)
{
  int v9; // ebx
  double v11; // st7
  double v12; // st6
  double v13; // st5
  double v14; // st4
  int v15; // edx
  int v16; // edi
  float *v17; // ecx
  unsigned int v18; // esi
  float v19; // xmm0_4
  float v20; // xmm3_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  double v23; // st2
  double x; // st7
  double v25; // st3
  double v26; // st5
  double v27; // st3
  double v28; // st2
  double v29; // st6
  double v30; // rtt
  double v31; // st3
  double v32; // st4
  float v33; // xmm0_4
  float v34; // xmm3_4
  float v35; // xmm1_4
  float v36; // xmm2_4
  double v37; // st2
  double v38; // st7
  double v39; // st3
  double v40; // st5
  double v41; // st3
  double v42; // st2
  double v43; // st6
  double v44; // rtt
  double v45; // st3
  double v46; // st4
  float v47; // xmm0_4
  float v48; // xmm3_4
  float v49; // xmm1_4
  float v50; // xmm2_4
  double v51; // st2
  double v52; // st7
  double v53; // st3
  double v54; // st5
  double v55; // st3
  double v56; // st2
  double v57; // st6
  double v58; // rtt
  double v59; // st3
  double v60; // st4
  float v61; // xmm0_4
  float v62; // xmm3_4
  float v63; // xmm1_4
  float v64; // xmm2_4
  float v65; // xmm5_4
  double v66; // st2
  double v67; // st3
  double v68; // st3
  double v69; // st2
  double v70; // rtt
  double v71; // st3
  float *v72; // ecx
  int v73; // edx
  float v74; // xmm0_4
  float v75; // xmm3_4
  float v76; // xmm1_4
  float v77; // xmm2_4
  float v78; // xmm5_4
  double v79; // st2
  double v80; // st3
  double v81; // st3
  double v82; // st2
  double v83; // rt1
  double v84; // st3
  int v85; // ecx
  int v86; // edx
  float v87; // xmm3_4
  float v88; // xmm1_4
  int v89; // eax
  float v90; // xmm1_4
  int v91; // eax
  float v92; // xmm1_4
  int v93; // eax
  int v94; // eax
  int v95; // eax
  int v96; // eax
  int v97; // eax
  float v98; // xmm0_4
  float v99; // xmm1_4
  int v100; // edx
  int v101; // eax
  int v102; // eax
  bool v103; // dl
  int v104; // eax
  int v105; // ecx
  int v106; // ecx
  VMatrix matProj; // [esp+8h] [ebp-FCh] BYREF
  VMatrix matView; // [esp+48h] [ebp-BCh] BYREF
  int nViewportHeight; // [esp+88h] [ebp-7Ch]
  int nViewportWidth; // [esp+8Ch] [ebp-78h] BYREF
  int nViewportX; // [esp+90h] [ebp-74h] BYREF
  int nViewportY; // [esp+94h] [ebp-70h] BYREF
  VMatrix matViewProj; // [esp+98h] [ebp-6Ch] BYREF
  int v114; // [esp+D8h] [ebp-2Ch]
  float *p_z; // [esp+DCh] [ebp-28h]
  int nWidth; // [esp+E0h] [ebp-24h] BYREF
  float fMinX; // [esp+E4h] [ebp-20h]
  float fMinY; // [esp+E8h] [ebp-1Ch]
  int nHeight; // [esp+ECh] [ebp-18h] BYREF
  float fMaxY; // [esp+F0h] [ebp-14h]
  float fMaxX; // [esp+F4h] [ebp-10h]
  Vector vScreenSpacePoint; // [esp+F8h] [ebp-Ch]

  v9 = 0;
  if ( nNumPolygons == 0 )
    return false;
  ((void (__thiscall *)(IMatRenderContext *, _DWORD, VMatrix *, int))pRenderContext->GetMatrix_2)(
    a1: pRenderContext,
    a2: 0,
    a3: &matView,
    a4: a1);
  pRenderContext->GetMatrix_2(this: pRenderContext, a2: MATERIAL_PROJECTION, a3: &matProj);
  MatrixMultiply(src1: &matProj, src2: &matView, dst: &matViewProj);
  fMinY = 3.4028235e38;
  fMinX = 3.4028235e38;
  fMaxY = -3.4028235e38;
  fMaxX = -3.4028235e38;
  if ( nNumPolygons > 0 )
  {
    v11 = fMinX;
    v12 = fMinY;
    v13 = fMaxX;
    v114 = 0;
    v14 = fMaxY;
    p_z = &(*vClippedPolygons)[1].z;
    do
    {
      v15 = pNumPoints[v9];
      v16 = 0;
      if ( v15 >= 4 )
      {
        v17 = p_z;
        v18 = ((unsigned int)(v15 - 4) >> 2) + 1;
        v16 = 4 * v18;
        do
        {
          v19 = *(v17 - 5);
          v20 = 1.0
              / (float)((float)((float)((float)(v19 * matViewProj.m[3][0]) + (float)(*(v17 - 4) * matViewProj.m[3][1]))
                              + (float)(*(v17 - 3) * matViewProj.m[3][2]))
                      + matViewProj.m[3][3]);
          v21 = *(v17 - 4) * matViewProj.m[1][1];
          v22 = *(v17 - 3) * matViewProj.m[1][2];
          vScreenSpacePoint.x = (float)((float)((float)((float)(v19 * matViewProj.m[0][0])
                                                      + (float)(*(v17 - 4) * matViewProj.m[0][1]))
                                              + (float)(*(v17 - 3) * matViewProj.m[0][2]))
                                      + matViewProj.m[0][3])
                              * v20;
          v23 = v11;
          x = vScreenSpacePoint.x;
          vScreenSpacePoint.y = (float)((float)((float)((float)(v19 * matViewProj.m[1][0]) + v21) + v22)
                                      + matViewProj.m[1][3])
                              * v20;
          if ( v23 <= vScreenSpacePoint.x )
            x = v23;
          v25 = v13;
          v26 = vScreenSpacePoint.x;
          if ( v25 >= vScreenSpacePoint.x )
            v26 = v25;
          v27 = -vScreenSpacePoint.y;
          v28 = v12;
          v29 = v27;
          if ( v28 <= v27 )
            v29 = v28;
          v30 = v27;
          v31 = v14;
          v32 = v30;
          if ( v31 >= v30 )
            v32 = v31;
          v33 = *(v17 - 2);
          v34 = 1.0
              / (float)((float)((float)((float)(v33 * matViewProj.m[3][0]) + (float)(*(v17 - 1) * matViewProj.m[3][1]))
                              + (float)(*v17 * matViewProj.m[3][2]))
                      + matViewProj.m[3][3]);
          v35 = *(v17 - 1) * matViewProj.m[1][1];
          v36 = *v17 * matViewProj.m[1][2];
          vScreenSpacePoint.x = (float)((float)((float)((float)(*(v17 - 1) * matViewProj.m[0][1])
                                                      + (float)(v33 * matViewProj.m[0][0]))
                                              + (float)(*v17 * matViewProj.m[0][2]))
                                      + matViewProj.m[0][3])
                              * v34;
          v37 = x;
          v38 = vScreenSpacePoint.x;
          vScreenSpacePoint.y = (float)((float)((float)((float)(v33 * matViewProj.m[1][0]) + v35) + v36)
                                      + matViewProj.m[1][3])
                              * v34;
          if ( v37 <= vScreenSpacePoint.x )
            v38 = v37;
          v39 = v26;
          v40 = vScreenSpacePoint.x;
          if ( v39 >= vScreenSpacePoint.x )
            v40 = v39;
          v41 = -vScreenSpacePoint.y;
          v42 = v29;
          v43 = v41;
          if ( v42 <= v41 )
            v43 = v42;
          v44 = v41;
          v45 = v32;
          v46 = v44;
          if ( v45 >= v44 )
            v46 = v45;
          v47 = v17[1];
          v48 = 1.0
              / (float)((float)((float)((float)(v47 * matViewProj.m[3][0]) + (float)(v17[2] * matViewProj.m[3][1]))
                              + (float)(v17[3] * matViewProj.m[3][2]))
                      + matViewProj.m[3][3]);
          v49 = v17[2] * matViewProj.m[1][1];
          v50 = v17[3] * matViewProj.m[1][2];
          vScreenSpacePoint.x = (float)((float)((float)((float)(v47 * matViewProj.m[0][0])
                                                      + (float)(v17[2] * matViewProj.m[0][1]))
                                              + (float)(v17[3] * matViewProj.m[0][2]))
                                      + matViewProj.m[0][3])
                              * v48;
          v51 = v38;
          v52 = vScreenSpacePoint.x;
          vScreenSpacePoint.y = (float)((float)((float)((float)(v47 * matViewProj.m[1][0]) + v49) + v50)
                                      + matViewProj.m[1][3])
                              * v48;
          if ( v51 <= vScreenSpacePoint.x )
            v52 = v51;
          v53 = v40;
          v54 = vScreenSpacePoint.x;
          if ( v53 >= vScreenSpacePoint.x )
            v54 = v53;
          v55 = -vScreenSpacePoint.y;
          v56 = v43;
          v57 = v55;
          if ( v56 <= v55 )
            v57 = v56;
          v58 = v55;
          v59 = v46;
          v60 = v58;
          if ( v59 >= v58 )
            v60 = v59;
          v61 = v17[4];
          v62 = 1.0
              / (float)((float)((float)((float)(v61 * matViewProj.m[3][0]) + (float)(v17[5] * matViewProj.m[3][1]))
                              + (float)(v17[6] * matViewProj.m[3][2]))
                      + matViewProj.m[3][3]);
          v63 = v17[5] * matViewProj.m[1][1];
          v64 = v17[6] * matViewProj.m[1][2];
          v65 = (float)((float)((float)((float)(v61 * matViewProj.m[0][0]) + (float)(v17[5] * matViewProj.m[0][1]))
                              + (float)(v17[6] * matViewProj.m[0][2]))
                      + matViewProj.m[0][3])
              * v62;
          vScreenSpacePoint.x = v65;
          v66 = v52;
          v11 = v65;
          vScreenSpacePoint.y = (float)((float)((float)((float)(v61 * matViewProj.m[1][0]) + v63) + v64)
                                      + matViewProj.m[1][3])
                              * v62;
          if ( v66 <= v65 )
            v11 = v66;
          v67 = v54;
          v13 = v65;
          if ( v67 >= v65 )
            v13 = v67;
          v68 = -vScreenSpacePoint.y;
          v69 = v57;
          v12 = v68;
          if ( v69 <= v68 )
            v12 = v69;
          v70 = v68;
          v71 = v60;
          v14 = v70;
          if ( v71 >= v70 )
            v14 = v71;
          v17 += 12;
          --v18;
        }
        while ( v18 != 0 );
        fMaxY = v14;
        fMinY = v12;
        fMaxX = v13;
        fMinX = v11;
      }
      if ( v16 < v15 )
      {
        v72 = &(*vClippedPolygons)[v16 + v114].z;
        v73 = v15 - v16;
        do
        {
          v74 = *(v72 - 2);
          v75 = 1.0
              / (float)((float)((float)((float)(v74 * matViewProj.m[3][0]) + (float)(*(v72 - 1) * matViewProj.m[3][1]))
                              + (float)(*v72 * matViewProj.m[3][2]))
                      + matViewProj.m[3][3]);
          v76 = *(v72 - 1) * matViewProj.m[1][1];
          v77 = *v72 * matViewProj.m[1][2];
          v78 = (float)((float)((float)((float)(*(v72 - 1) * matViewProj.m[0][1]) + (float)(v74 * matViewProj.m[0][0]))
                              + (float)(*v72 * matViewProj.m[0][2]))
                      + matViewProj.m[0][3])
              * v75;
          vScreenSpacePoint.x = v78;
          v79 = v11;
          v11 = v78;
          vScreenSpacePoint.y = (float)((float)((float)((float)(v74 * matViewProj.m[1][0]) + v76) + v77)
                                      + matViewProj.m[1][3])
                              * v75;
          if ( v79 <= v78 )
            v11 = v79;
          v80 = v13;
          v13 = v78;
          if ( v80 >= v78 )
            v13 = v80;
          v81 = -vScreenSpacePoint.y;
          v82 = v12;
          v12 = v81;
          if ( v82 <= v81 )
            v12 = v82;
          v83 = v81;
          v84 = v14;
          v14 = v83;
          if ( v84 >= v83 )
            v14 = v84;
          v72 += 3;
          --v73;
        }
        while ( v73 != 0 );
        fMaxY = v14;
        fMinY = v12;
        fMaxX = v13;
        fMinX = v11;
      }
      p_z += 30;
      v114 += 10;
      ++v9;
    }
    while ( v9 < nNumPolygons );
  }
  g_pMaterialSystem->GetBackBufferDimensions(this: g_pMaterialSystem, a2: &nWidth, a3: &nHeight);
  v85 = nWidth;
  v86 = nHeight;
  v87 = (float)nWidth;
  v88 = (float)(fMinY + 1.0) * 0.5;
  *nLeft = (int)(float)((float)((float)((float)(fMinX + 1.0) * 0.5) * (float)nWidth) - 1.0);
  v89 = (int)(float)((float)(v88 * (float)v86) - 1.0);
  v90 = (float)((float)((float)(fMaxX + 1.0) * 0.5) * v87) + 1.0;
  *nTop = v89;
  v91 = (int)v90;
  v92 = fMaxY + 1.0;
  *nRight = v91;
  *nBottom = (int)(float)((float)((float)(v92 * 0.5) * (float)v86) + 1.0);
  v93 = *nLeft;
  if ( *nLeft >= 0 )
  {
    if ( v93 > v85 )
      v93 = v85;
  }
  else
  {
    v93 = 0;
  }
  *nLeft = v93;
  v94 = *nTop;
  if ( *nTop >= 0 )
  {
    if ( v94 > v86 )
      v94 = v86;
  }
  else
  {
    v94 = 0;
  }
  *nTop = v94;
  v95 = *nRight;
  if ( *nRight >= 0 )
  {
    if ( v95 > v85 )
      v95 = v85;
  }
  else
  {
    v95 = 0;
  }
  *nRight = v95;
  v96 = *nBottom;
  if ( *nBottom >= 0 )
  {
    if ( v96 > nHeight )
      v96 = nHeight;
  }
  else
  {
    v96 = 0;
  }
  *nBottom = v96;
  ((void (__thiscall *)(IMatRenderContext *, int *, int *, int *))pRenderContext->GetViewport)(
    a1: pRenderContext,
    a2: &nViewportX,
    a3: &nViewportY,
    a4: &nViewportWidth);
  v97 = nViewportX;
  v98 = (float)nViewportWidth / (float)nWidth;
  v99 = (float)nViewportHeight / (float)nHeight;
  *nLeft = nViewportX + (int)(float)((float)*nLeft * v98);
  v100 = v97 + (int)(float)((float)*nRight * v98);
  v101 = nViewportY;
  *nRight = v100;
  *nTop = v101 + (int)(float)((float)*nTop * v99);
  v102 = (int)(float)((float)*nBottom * v99) + v101;
  *nBottom = v102;
  v103 = *nLeft > 0 || *nTop > 0 || *nRight < nWidth || v102 < nHeight;
  v104 = v102 - *nTop;
  v105 = *nRight - *nLeft;
  if ( v105 <= 0 || v104 <= 0 )
    v106 = 0;
  else
    v106 = v104 * v105;
  return v103 && v106 > 0;
}

//------------------------------------------------------------------------------
// Address: 0x10108D50
// Name: ShadowClip_CClipTop_
// Source: json
//------------------------------------------------------------------------------
void __usercall ShadowClip_CClipTop_(ShadowClipState_t *clip@<esi>)
{
  int m_ClipCount; // ecx
  int v2; // edi
  ShadowVertex_t **v3; // edx
  float *p_x; // ecx
  ShadowVertex_t **v5; // ebx
  float *v6; // eax
  int v7; // edx
  float *v8; // edx
  float v9; // xmm0_4
  int m_TempCount; // edx
  float *v11; // edx
  float v12; // xmm0_4
  int v13; // eax
  ShadowVertex_t **pSrcVert; // [esp+0h] [ebp-10h]
  int v15; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  bool endInside; // [esp+Eh] [ebp-2h]
  bool startInside; // [esp+Fh] [ebp-1h]

  m_ClipCount = clip->m_ClipCount;
  v15 = m_ClipCount;
  if ( m_ClipCount != 0 )
  {
    v2 = 0;
    v3 = clip->m_ppClipVertices[clip->m_CurrVert];
    p_x = &v3[m_ClipCount - 1]->m_Position.x;
    pSrcVert = v3;
    v5 = clip->m_ppClipVertices[clip->m_CurrVert == 0];
    startInside = p_x[4] < 1.0;
    i = 0;
    if ( v15 > 0 )
    {
      while ( 1 )
      {
        v6 = &v3[i]->m_Position.x;
        if ( v6[4] >= 1.0 )
        {
          endInside = false;
          if ( !startInside )
            goto LABEL_14;
          m_TempCount = clip->m_TempCount;
          if ( m_TempCount >= 48 )
            return;
          v5[v2] = &clip->m_pTempVertices[m_TempCount];
          ++clip->m_TempCount;
          v11 = &v5[v2]->m_Position.x;
          v12 = (float)(1.0 - p_x[4]) / (float)(v6[4] - p_x[4]);
          v11[3] = (float)((float)(v6[3] - p_x[3]) * v12) + p_x[3];
          v11[4] = (float)((float)(v6[4] - p_x[4]) * v12) + p_x[4];
          v11[5] = (float)((float)(v6[5] - p_x[5]) * v12) + p_x[5];
          *v11 = (float)((float)(*v6 - *p_x) * v12) + *p_x;
          v11[1] = (float)((float)(v6[1] - p_x[1]) * v12) + p_x[1];
          v11[2] = (float)((float)(v6[2] - p_x[2]) * v12) + p_x[2];
        }
        else
        {
          endInside = true;
          if ( !startInside )
          {
            v7 = clip->m_TempCount;
            if ( v7 >= 48 )
              return;
            v5[v2] = &clip->m_pTempVertices[v7];
            ++clip->m_TempCount;
            v8 = &v5[v2]->m_Position.x;
            v9 = (float)(1.0 - p_x[4]) / (float)(v6[4] - p_x[4]);
            v8[3] = (float)((float)(v6[3] - p_x[3]) * v9) + p_x[3];
            v8[4] = (float)((float)(v6[4] - p_x[4]) * v9) + p_x[4];
            v8[5] = (float)((float)(v6[5] - p_x[5]) * v9) + p_x[5];
            *v8 = (float)((float)(*v6 - *p_x) * v9) + *p_x;
            v8[1] = (float)((float)(v6[1] - p_x[1]) * v9) + p_x[1];
            v8[2] = (float)((float)(v6[2] - p_x[2]) * v9) + p_x[2];
            ++v2;
          }
          v5[v2] = (ShadowVertex_t *)v6;
        }
        ++v2;
LABEL_14:
        ++i;
        p_x = v6;
        startInside = endInside;
        if ( i >= v15 )
          break;
        v3 = pSrcVert;
      }
    }
    v13 = 1 - clip->m_CurrVert;
    clip->m_ClipCount = v2;
    clip->m_CurrVert = v13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10108FA0
// Name: ShadowClip_CClipBottom_
// Source: json
//------------------------------------------------------------------------------
void __usercall ShadowClip_CClipBottom_(ShadowClipState_t *clip@<esi>)
{
  int m_ClipCount; // ecx
  int v2; // edi
  ShadowVertex_t **v3; // edx
  float *p_x; // ecx
  ShadowVertex_t **v5; // ebx
  float *v6; // eax
  int v7; // edx
  float *v8; // edx
  float v9; // xmm0_4
  int m_TempCount; // edx
  float *v11; // edx
  float v12; // xmm0_4
  int v13; // eax
  ShadowVertex_t **pSrcVert; // [esp+0h] [ebp-10h]
  int v15; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  bool endInside; // [esp+Eh] [ebp-2h]
  bool startInside; // [esp+Fh] [ebp-1h]

  m_ClipCount = clip->m_ClipCount;
  v15 = m_ClipCount;
  if ( m_ClipCount != 0 )
  {
    v2 = 0;
    v3 = clip->m_ppClipVertices[clip->m_CurrVert];
    p_x = &v3[m_ClipCount - 1]->m_Position.x;
    pSrcVert = v3;
    v5 = clip->m_ppClipVertices[clip->m_CurrVert == 0];
    startInside = p_x[4] > 0.0;
    i = 0;
    if ( v15 > 0 )
    {
      while ( 1 )
      {
        v6 = &v3[i]->m_Position.x;
        if ( v6[4] <= 0.0 )
        {
          endInside = false;
          if ( !startInside )
            goto LABEL_14;
          m_TempCount = clip->m_TempCount;
          if ( m_TempCount >= 48 )
            return;
          v5[v2] = &clip->m_pTempVertices[m_TempCount];
          ++clip->m_TempCount;
          v11 = &v5[v2]->m_Position.x;
          v12 = p_x[4] / (float)(p_x[4] - v6[4]);
          v11[3] = (float)((float)(v6[3] - p_x[3]) * v12) + p_x[3];
          v11[4] = (float)((float)(v6[4] - p_x[4]) * v12) + p_x[4];
          v11[5] = (float)((float)(v6[5] - p_x[5]) * v12) + p_x[5];
          *v11 = (float)((float)(*v6 - *p_x) * v12) + *p_x;
          v11[1] = (float)((float)(v6[1] - p_x[1]) * v12) + p_x[1];
          v11[2] = (float)((float)(v6[2] - p_x[2]) * v12) + p_x[2];
        }
        else
        {
          endInside = true;
          if ( !startInside )
          {
            v7 = clip->m_TempCount;
            if ( v7 >= 48 )
              return;
            v5[v2] = &clip->m_pTempVertices[v7];
            ++clip->m_TempCount;
            v8 = &v5[v2]->m_Position.x;
            v9 = p_x[4] / (float)(p_x[4] - v6[4]);
            v8[3] = (float)((float)(v6[3] - p_x[3]) * v9) + p_x[3];
            v8[4] = (float)((float)(v6[4] - p_x[4]) * v9) + p_x[4];
            v8[5] = (float)((float)(v6[5] - p_x[5]) * v9) + p_x[5];
            *v8 = (float)((float)(*v6 - *p_x) * v9) + *p_x;
            v8[1] = (float)((float)(v6[1] - p_x[1]) * v9) + p_x[1];
            v8[2] = (float)((float)(v6[2] - p_x[2]) * v9) + p_x[2];
            ++v2;
          }
          v5[v2] = (ShadowVertex_t *)v6;
        }
        ++v2;
LABEL_14:
        ++i;
        p_x = v6;
        startInside = endInside;
        if ( i >= v15 )
          break;
        v3 = pSrcVert;
      }
    }
    v13 = 1 - clip->m_CurrVert;
    clip->m_ClipCount = v2;
    clip->m_CurrVert = v13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101091E0
// Name: ShadowClip_CClipLeft_
// Source: json
//------------------------------------------------------------------------------
void __usercall ShadowClip_CClipLeft_(ShadowClipState_t *clip@<esi>)
{
  int m_ClipCount; // ecx
  int v2; // edi
  ShadowVertex_t **v3; // edx
  float *p_x; // ecx
  ShadowVertex_t **v5; // ebx
  float *v6; // eax
  int v7; // edx
  float v8; // xmm2_4
  float v9; // xmm1_4
  float *v10; // edx
  float v11; // xmm0_4
  int m_TempCount; // edx
  float v13; // xmm2_4
  float v14; // xmm1_4
  float *v15; // edx
  float v16; // xmm0_4
  int v17; // eax
  ShadowVertex_t **pSrcVert; // [esp+0h] [ebp-10h]
  int v19; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  bool endInside; // [esp+Eh] [ebp-2h]
  bool startInside; // [esp+Fh] [ebp-1h]

  m_ClipCount = clip->m_ClipCount;
  v19 = m_ClipCount;
  if ( m_ClipCount != 0 )
  {
    v2 = 0;
    v3 = clip->m_ppClipVertices[clip->m_CurrVert];
    p_x = &v3[m_ClipCount - 1]->m_Position.x;
    pSrcVert = v3;
    v5 = clip->m_ppClipVertices[clip->m_CurrVert == 0];
    startInside = p_x[3] > 0.0;
    i = 0;
    if ( v19 > 0 )
    {
      while ( 1 )
      {
        v6 = &v3[i]->m_Position.x;
        if ( v6[3] <= 0.0 )
        {
          endInside = false;
          if ( !startInside )
            goto LABEL_14;
          m_TempCount = clip->m_TempCount;
          if ( m_TempCount >= 48 )
            return;
          v5[v2] = &clip->m_pTempVertices[m_TempCount];
          ++clip->m_TempCount;
          v13 = p_x[3];
          v14 = v6[3];
          v15 = &v5[v2]->m_Position.x;
          v16 = v13 / (float)(v13 - v14);
          v15[3] = (float)((float)(v14 - v13) * v16) + v13;
          v15[4] = (float)((float)(v6[4] - p_x[4]) * v16) + p_x[4];
          v15[5] = (float)((float)(v6[5] - p_x[5]) * v16) + p_x[5];
          *v15 = (float)((float)(*v6 - *p_x) * v16) + *p_x;
          v15[1] = (float)((float)(v6[1] - p_x[1]) * v16) + p_x[1];
          v15[2] = (float)((float)(v6[2] - p_x[2]) * v16) + p_x[2];
        }
        else
        {
          endInside = true;
          if ( !startInside )
          {
            v7 = clip->m_TempCount;
            if ( v7 >= 48 )
              return;
            v5[v2] = &clip->m_pTempVertices[v7];
            ++clip->m_TempCount;
            v8 = p_x[3];
            v9 = v6[3];
            v10 = &v5[v2]->m_Position.x;
            v11 = v8 / (float)(v8 - v9);
            v10[3] = (float)((float)(v9 - v8) * v11) + v8;
            v10[4] = (float)((float)(v6[4] - p_x[4]) * v11) + p_x[4];
            v10[5] = (float)((float)(v6[5] - p_x[5]) * v11) + p_x[5];
            *v10 = (float)((float)(*v6 - *p_x) * v11) + *p_x;
            v10[1] = (float)((float)(v6[1] - p_x[1]) * v11) + p_x[1];
            v10[2] = (float)((float)(v6[2] - p_x[2]) * v11) + p_x[2];
            ++v2;
          }
          v5[v2] = (ShadowVertex_t *)v6;
        }
        ++v2;
LABEL_14:
        ++i;
        p_x = v6;
        startInside = endInside;
        if ( i >= v19 )
          break;
        v3 = pSrcVert;
      }
    }
    v17 = 1 - clip->m_CurrVert;
    clip->m_ClipCount = v2;
    clip->m_CurrVert = v17;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109420
// Name: ShadowClip_CClipRight_
// Source: json
//------------------------------------------------------------------------------
void __usercall ShadowClip_CClipRight_(ShadowClipState_t *clip@<esi>)
{
  int m_ClipCount; // ecx
  int v2; // edi
  ShadowVertex_t **v3; // edx
  float *p_x; // ecx
  ShadowVertex_t **v5; // ebx
  float *v6; // eax
  int v7; // edx
  float v8; // xmm2_4
  float *v9; // edx
  float v10; // xmm1_4
  float v11; // xmm0_4
  int m_TempCount; // edx
  float v13; // xmm2_4
  float *v14; // edx
  float v15; // xmm1_4
  float v16; // xmm0_4
  int v17; // eax
  ShadowVertex_t **pSrcVert; // [esp+0h] [ebp-10h]
  int v19; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  bool endInside; // [esp+Eh] [ebp-2h]
  bool startInside; // [esp+Fh] [ebp-1h]

  m_ClipCount = clip->m_ClipCount;
  v19 = m_ClipCount;
  if ( m_ClipCount != 0 )
  {
    v2 = 0;
    v3 = clip->m_ppClipVertices[clip->m_CurrVert];
    p_x = &v3[m_ClipCount - 1]->m_Position.x;
    pSrcVert = v3;
    v5 = clip->m_ppClipVertices[clip->m_CurrVert == 0];
    startInside = p_x[3] < 1.0;
    i = 0;
    if ( v19 > 0 )
    {
      while ( 1 )
      {
        v6 = &v3[i]->m_Position.x;
        if ( v6[3] >= 1.0 )
        {
          endInside = false;
          if ( !startInside )
            goto LABEL_14;
          m_TempCount = clip->m_TempCount;
          if ( m_TempCount >= 48 )
            return;
          v5[v2] = &clip->m_pTempVertices[m_TempCount];
          ++clip->m_TempCount;
          v13 = p_x[3];
          v14 = &v5[v2]->m_Position.x;
          v15 = v6[3] - v13;
          v16 = (float)(1.0 - v13) / v15;
          v14[3] = (float)(v15 * v16) + v13;
          v14[4] = (float)((float)(v6[4] - p_x[4]) * v16) + p_x[4];
          v14[5] = (float)((float)(v6[5] - p_x[5]) * v16) + p_x[5];
          *v14 = (float)((float)(*v6 - *p_x) * v16) + *p_x;
          v14[1] = (float)((float)(v6[1] - p_x[1]) * v16) + p_x[1];
          v14[2] = (float)((float)(v6[2] - p_x[2]) * v16) + p_x[2];
        }
        else
        {
          endInside = true;
          if ( !startInside )
          {
            v7 = clip->m_TempCount;
            if ( v7 >= 48 )
              return;
            v5[v2] = &clip->m_pTempVertices[v7];
            ++clip->m_TempCount;
            v8 = p_x[3];
            v9 = &v5[v2]->m_Position.x;
            v10 = v6[3] - v8;
            v11 = (float)(1.0 - v8) / v10;
            v9[3] = (float)(v10 * v11) + v8;
            v9[4] = (float)((float)(v6[4] - p_x[4]) * v11) + p_x[4];
            v9[5] = (float)((float)(v6[5] - p_x[5]) * v11) + p_x[5];
            *v9 = (float)((float)(*v6 - *p_x) * v11) + *p_x;
            v9[1] = (float)((float)(v6[1] - p_x[1]) * v11) + p_x[1];
            v9[2] = (float)((float)(v6[2] - p_x[2]) * v11) + p_x[2];
            ++v2;
          }
          v5[v2] = (ShadowVertex_t *)v6;
        }
        ++v2;
LABEL_14:
        ++i;
        p_x = v6;
        startInside = endInside;
        if ( i >= v19 )
          break;
        v3 = pSrcVert;
      }
    }
    v17 = 1 - clip->m_CurrVert;
    clip->m_ClipCount = v2;
    clip->m_CurrVert = v17;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109660
// Name: ShadowClip_CClipAbove_
// Source: json
//------------------------------------------------------------------------------
void __usercall ShadowClip_CClipAbove_(ShadowClipState_t *clip@<edi>)
{
  ShadowVertex_t **v1; // edx
  int v2; // ebx
  ShadowVertex_t **v3; // ecx
  ShadowVertex_t *v4; // esi
  ShadowVertex_t *v5; // eax
  int v6; // edx
  ShadowVertex_t *v7; // ecx
  float v8; // xmm2_4
  float *v9; // ecx
  int m_TempCount; // edx
  ShadowVertex_t *v11; // ecx
  float v12; // xmm2_4
  float *v13; // ecx
  int v14; // eax
  ShadowVertex_t **pSrcVert; // [esp+0h] [ebp-14h]
  ShadowVertex_t **pDestVert; // [esp+4h] [ebp-10h]
  int m_ClipCount; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]
  bool endInside; // [esp+12h] [ebp-2h]
  bool startInside; // [esp+13h] [ebp-1h]

  m_ClipCount = clip->m_ClipCount;
  if ( m_ClipCount != 0 )
  {
    v1 = clip->m_ppClipVertices[clip->m_CurrVert];
    v2 = 0;
    pSrcVert = v1;
    v3 = clip->m_ppClipVertices[clip->m_CurrVert == 0];
    v4 = v1[m_ClipCount - 1];
    pDestVert = v3;
    startInside = v4->m_ShadowSpaceTexCoord.z > 0.0;
    i = 0;
    if ( m_ClipCount > 0 )
    {
      while ( 1 )
      {
        v5 = v1[i];
        if ( v5->m_ShadowSpaceTexCoord.z <= 0.0 )
        {
          endInside = false;
          if ( !startInside )
            goto LABEL_14;
          m_TempCount = clip->m_TempCount;
          if ( m_TempCount >= 48 )
            return;
          v3[v2] = &clip->m_pTempVertices[m_TempCount];
          ++clip->m_TempCount;
          v11 = v3[v2];
          v12 = v4->m_ShadowSpaceTexCoord.z / (float)(v4->m_ShadowSpaceTexCoord.z - v5->m_ShadowSpaceTexCoord.z);
          v11->m_ShadowSpaceTexCoord.x = (float)((float)(v5->m_ShadowSpaceTexCoord.x - v4->m_ShadowSpaceTexCoord.x) * v12)
                                       + v4->m_ShadowSpaceTexCoord.x;
          v11->m_ShadowSpaceTexCoord.y = (float)((float)(v5->m_ShadowSpaceTexCoord.y - v4->m_ShadowSpaceTexCoord.y) * v12)
                                       + v4->m_ShadowSpaceTexCoord.y;
          v11->m_ShadowSpaceTexCoord.z = (float)((float)(v5->m_ShadowSpaceTexCoord.z - v4->m_ShadowSpaceTexCoord.z) * v12)
                                       + v4->m_ShadowSpaceTexCoord.z;
          ClampTexCoord(pOutVertex: v11, pInVertex: v5);
          *v13 = (float)((float)(v5->m_Position.x - v4->m_Position.x) * v12) + v4->m_Position.x;
          v13[1] = (float)((float)(v5->m_Position.y - v4->m_Position.y) * v12) + v4->m_Position.y;
          v13[2] = (float)((float)(v5->m_Position.z - v4->m_Position.z) * v12) + v4->m_Position.z;
          v3 = pDestVert;
        }
        else
        {
          endInside = true;
          if ( !startInside )
          {
            v6 = clip->m_TempCount;
            if ( v6 >= 48 )
              return;
            v3[v2] = &clip->m_pTempVertices[v6];
            ++clip->m_TempCount;
            v7 = v3[v2];
            v8 = v4->m_ShadowSpaceTexCoord.z / (float)(v4->m_ShadowSpaceTexCoord.z - v5->m_ShadowSpaceTexCoord.z);
            v7->m_ShadowSpaceTexCoord.x = (float)((float)(v5->m_ShadowSpaceTexCoord.x - v4->m_ShadowSpaceTexCoord.x) * v8)
                                        + v4->m_ShadowSpaceTexCoord.x;
            v7->m_ShadowSpaceTexCoord.y = (float)((float)(v5->m_ShadowSpaceTexCoord.y - v4->m_ShadowSpaceTexCoord.y) * v8)
                                        + v4->m_ShadowSpaceTexCoord.y;
            v7->m_ShadowSpaceTexCoord.z = (float)((float)(v5->m_ShadowSpaceTexCoord.z - v4->m_ShadowSpaceTexCoord.z) * v8)
                                        + v4->m_ShadowSpaceTexCoord.z;
            ClampTexCoord(pOutVertex: v7, pInVertex: v4);
            *v9 = (float)((float)(v5->m_Position.x - v4->m_Position.x) * v8) + v4->m_Position.x;
            v9[1] = (float)((float)(v5->m_Position.y - v4->m_Position.y) * v8) + v4->m_Position.y;
            v9[2] = (float)((float)(v5->m_Position.z - v4->m_Position.z) * v8) + v4->m_Position.z;
            v3 = pDestVert;
            ++v2;
          }
          v3[v2] = v5;
        }
        ++v2;
LABEL_14:
        ++i;
        v4 = v5;
        startInside = endInside;
        if ( i >= m_ClipCount )
          break;
        v1 = pSrcVert;
      }
    }
    v14 = 1 - clip->m_CurrVert;
    clip->m_ClipCount = v2;
    clip->m_CurrVert = v14;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101098C0
// Name: ShadowClip_CClipPlane_
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShadowClip_CClipPlane_(ShadowClipState_t *clip, CClipPlane *clipper)
{
  int m_ClipCount; // edx
  int m_CurrVert; // ecx
  int v5; // eax
  bool v6; // zf
  const Vector *v7; // esi
  float x; // xmm1_4
  float v9; // xmm0_4
  float m_Dist; // xmm1_4
  ShadowVertex_t **v11; // ecx
  float *v12; // edi
  int v13; // edx
  float v14; // xmm0_4
  double v15; // st7
  const Vector *v16; // ecx
  float v17; // eax
  float v18; // xmm2_4
  int m_TempCount; // edx
  float v20; // xmm0_4
  double v21; // st7
  const Vector *m_pNormal; // ecx
  float v23; // eax
  float v24; // xmm2_4
  int v25; // ecx
  float v26; // [esp-Ch] [ebp-44h]
  float v27; // [esp-Ch] [ebp-44h]
  Vector v28; // [esp+4h] [ebp-34h] BYREF
  Vector v29; // [esp+10h] [ebp-28h] BYREF
  Vector dir; // [esp+1Ch] [ebp-1Ch]
  ShadowVertex_t **v31; // [esp+28h] [ebp-10h]
  ShadowVertex_t **pSrcVert; // [esp+2Ch] [ebp-Ch]
  int v33; // [esp+30h] [ebp-8h]
  ShadowVertex_t **pDestVert; // [esp+34h] [ebp-4h]
  float v35; // [esp+40h] [ebp+8h]
  float v36; // [esp+40h] [ebp+8h]
  char endInside; // [esp+43h] [ebp+Bh]

  m_ClipCount = clip->m_ClipCount;
  LODWORD(dir.z) = m_ClipCount;
  if ( m_ClipCount != 0 )
  {
    m_CurrVert = clip->m_CurrVert;
    v5 = 0;
    v6 = clip->m_CurrVert == 0;
    v7 = *((const Vector **)&clip->m_pTempVertices[8 * m_CurrVert + 47].m_ShadowSpaceTexCoord.z + m_ClipCount);
    x = v7->x;
    LODWORD(dir.y) = clip->m_ppClipVertices[m_CurrVert];
    v9 = (float)((float)(clipper->m_pNormal->y * v7->y) + (float)(x * clipper->m_pNormal->x))
       + (float)(clipper->m_pNormal->z * v7->z);
    m_Dist = clipper->m_Dist;
    v11 = clip->m_ppClipVertices[v6];
    v33 = 0;
    v31 = v11;
    endInside = m_Dist > v9;
    for ( pSrcVert = nullptr; (int)pSrcVert < SLODWORD(dir.z); v7 = (const Vector *)v12 )
    {
      v12 = *(float **)(LODWORD(dir.y) + 4 * (_DWORD)pSrcVert);
      if ( clipper->m_Dist <= (float)((float)((float)(clipper->m_pNormal->y * v12[1])
                                            + (float)(clipper->m_pNormal->x * *v12))
                                    + (float)(clipper->m_pNormal->z * v12[2])) )
      {
        HIBYTE(pDestVert) = 0;
        if ( endInside != 0 )
        {
          m_TempCount = clip->m_TempCount;
          if ( m_TempCount >= 48 )
            return;
          v11[v5] = &clip->m_pTempVertices[m_TempCount];
          ++clip->m_TempCount;
          v20 = *v12 - v7->x;
          LODWORD(dir.x) = v11[v5];
          v21 = clipper->m_Dist;
          m_pNormal = clipper->m_pNormal;
          v28.x = v20;
          v27 = v21;
          v28.y = v12[1] - v7->y;
          v28.z = v12[2] - v7->z;
          v36 = IntersectRayWithPlane(org: v7, dir: &v28, normal: m_pNormal, dist: v27);
          v23 = dir.x;
          *(float *)(LODWORD(dir.x) + 12) = (float)((float)(v12[3] - v7[1].x) * v36) + v7[1].x;
          *(float *)(LODWORD(v23) + 16) = (float)((float)(v12[4] - v7[1].y) * v36) + v7[1].y;
          v11 = v31;
          *(float *)(LODWORD(v23) + 20) = (float)((float)(v12[5] - v7[1].z) * v36) + v7[1].z;
          *(float *)LODWORD(v23) = (float)((float)(*v12 - v7->x) * v36) + v7->x;
          *(float *)(LODWORD(v23) + 4) = (float)((float)(v12[1] - v7->y) * v36) + v7->y;
          v24 = v12[2] - v7->z;
          ++v33;
          *(float *)(LODWORD(v23) + 8) = (float)(v24 * v36) + v7->z;
          v5 = v33;
        }
      }
      else
      {
        HIBYTE(pDestVert) = 1;
        if ( endInside == 0 )
        {
          v13 = clip->m_TempCount;
          if ( v13 >= 48 )
            return;
          v11[v5] = &clip->m_pTempVertices[v13];
          ++clip->m_TempCount;
          v14 = *v12 - v7->x;
          LODWORD(dir.x) = v11[v5];
          v15 = clipper->m_Dist;
          v16 = clipper->m_pNormal;
          v29.x = v14;
          v26 = v15;
          v29.y = v12[1] - v7->y;
          v29.z = v12[2] - v7->z;
          v35 = IntersectRayWithPlane(org: v7, dir: &v29, normal: v16, dist: v26);
          v17 = dir.x;
          *(float *)(LODWORD(dir.x) + 12) = (float)((float)(v12[3] - v7[1].x) * v35) + v7[1].x;
          *(float *)(LODWORD(v17) + 16) = (float)((float)(v12[4] - v7[1].y) * v35) + v7[1].y;
          v11 = v31;
          *(float *)(LODWORD(v17) + 20) = (float)((float)(v12[5] - v7[1].z) * v35) + v7[1].z;
          *(float *)LODWORD(v17) = (float)((float)(*v12 - v7->x) * v35) + v7->x;
          *(float *)(LODWORD(v17) + 4) = (float)((float)(v12[1] - v7->y) * v35) + v7->y;
          v18 = v12[2] - v7->z;
          ++v33;
          *(float *)(LODWORD(v17) + 8) = (float)(v18 * v35) + v7->z;
          v5 = v33;
        }
        v11[v5++] = (ShadowVertex_t *)v12;
        v33 = v5;
      }
      pSrcVert = (ShadowVertex_t **)((char *)pSrcVert + 1);
      endInside = HIBYTE(pDestVert);
    }
    v25 = 1 - clip->m_CurrVert;
    clip->m_ClipCount = v5;
    clip->m_CurrVert = v25;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109D30
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short> *m_pMemory; // edx
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
    v7 = 196 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                                     this: _g_pMemAlloc,
                                                                                                     a2: m_pMemory,
                                                                                                     a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                                     this: _g_pMemAlloc,
                                                                                                     a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109DE0
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short> *m_pMemory; // edx
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
    v7 = 772 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                                     this: _g_pMemAlloc,
                                                                                                     a2: m_pMemory,
                                                                                                     a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                                     this: _g_pMemAlloc,
                                                                                                     a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109E90
// Name: unsigned short __near & FirstModelInShadow(unsigned short)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 *__cdecl FirstModelInShadow(unsigned __int16 h)
{
  return &s_ShadowMgr.m_Shadows.m_Memory.m_pMemory[h].m_Element.m_FirstModel;
}

//------------------------------------------------------------------------------
// Address: 0x10109EB0
// Name: public: virtual void CShadowMgr::SetShadowTexCoord(unsigned short,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::SetShadowTexCoord(
        CShadowMgr *this,
        unsigned __int16 handle,
        float x,
        float y,
        float w,
        float h)
{
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v6; // eax

  v6 = &this->m_Shadows.m_Memory.m_pMemory[handle];
  v6->m_Element.m_TexOrigin.x = x;
  v6->m_Element.m_TexOrigin.y = y;
  v6->m_Element.m_TexSize.x = w;
  v6->m_Element.m_TexSize.y = h;
}

//------------------------------------------------------------------------------
// Address: 0x10109EF0
// Name: public: virtual void CShadowMgr::ClearExtraClipPlanes(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::ClearExtraClipPlanes(CShadowMgr *this, unsigned __int16 h)
{
  this->m_Shadows.m_Memory.m_pMemory[h].m_Element.m_ClipPlaneCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10109F10
// Name: public: virtual void CShadowMgr::AddExtraClipPlane(unsigned short,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::AddExtraClipPlane(CShadowMgr *this, unsigned __int16 h, const Vector *normal, float dist)
{
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v4; // eax

  v4 = &this->m_Shadows.m_Memory.m_pMemory[h];
  v4->m_Element.m_ClipPlane[v4->m_Element.m_ClipPlaneCount] = *normal;
  v4->m_Element.m_ClipDist[v4->m_Element.m_ClipPlaneCount++] = dist;
}

//------------------------------------------------------------------------------
// Address: 0x10109F70
// Name: public: virtual struct ShadowInfo_t const __near & CShadowMgr::GetInfo(unsigned short)
// Source: json
//------------------------------------------------------------------------------
UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *__thiscall CShadowMgr::GetInfo(
        CShadowMgr *this,
        unsigned __int16 handle)
{
  return &this->m_Shadows.m_Memory.m_pMemory[handle];
}

//------------------------------------------------------------------------------
// Address: 0x10109F90
// Name: public: virtual bool CShadowMgr::ModelHasShadows(unsigned short)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShadowMgr::ModelHasShadows(CShadowMgr *this, int instance)
{
  return (_WORD)instance != 0xFFFF && *this->m_ShadowsOnModels.m_FirstElement(a1: instance) != 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10109FD0
// Name: public: virtual void CShadowMgr::GetFlashlightRenderInfo(struct FlashlightInstance_t __near *,int,unsigned short const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::GetFlashlightRenderInfo(
        CShadowMgr *this,
        FlashlightInstance_t *pFlashlightState,
        int nCount,
        const unsigned __int16 *pHandles)
{
  int m_nValue; // eax
  VMatrix *p_m_WorldToTexture; // edx
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v6; // ebx
  CShadowMgr *v7; // [esp+0h] [ebp-Ch]
  int i; // [esp+4h] [ebp-8h]
  bool bWireframe; // [esp+Bh] [ebp-1h]
  VMatrix *pFlashlightStatea; // [esp+14h] [ebp+8h]

  v7 = this;
  if ( r_shadowwireframe.m_pParent != nullptr )
    m_nValue = r_shadowwireframe.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  bWireframe = m_nValue != 0;
  i = 0;
  if ( nCount > 0 )
  {
    p_m_WorldToTexture = &pFlashlightState->m_WorldToTexture;
    pFlashlightStatea = &pFlashlightState->m_WorldToTexture;
    while ( 1 )
    {
      v6 = &this->m_Shadows.m_Memory.m_pMemory[pHandles[i]];
      qmemcpy(
        &p_m_WorldToTexture[-4].m[0][1],
        &this->m_FlashlightStates.m_Memory.m_pMemory[v6->m_Element.m_FlashlightHandle].m_Element.m_FlashlightState,
        0xFCu);
      VMatrix::operator=(this: p_m_WorldToTexture, mOther: &v6->m_Element.m_WorldToShadow);
      LODWORD(pFlashlightStatea[-4].m[0][0]) = bWireframe ? g_pMaterialMRMWireframe : nullptr;
      LODWORD(pFlashlightStatea[1].m[0][0]) = v6->m_Element.m_pFlashlightDepthTexture;
      ++i;
      pFlashlightStatea = (VMatrix *)((char *)pFlashlightStatea + 324);
      if ( i >= nCount )
        break;
      p_m_WorldToTexture = pFlashlightStatea;
      this = v7;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010A0A0
// Name: public: virtual void CShadowMgr::SetFalloffBias(unsigned short,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::SetFalloffBias(CShadowMgr *this, unsigned __int16 shadow, unsigned __int8 ucBias)
{
  this->m_Shadows.m_Memory.m_pMemory[shadow].m_Element.m_FalloffBias = ucBias;
}

//------------------------------------------------------------------------------
// Address: 0x1010A0C0
// Name: private: int CShadowMgr::ProjectAndClipVertices(struct CShadowMgr::Shadow_t const __near &,class VMatrix const __near &,class VMatrix const __near *,int,class Vector __near * __near *,struct ShadowVertex_t __near * __near * __near *,struct ShadowClipState_t __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __userpurge CShadowMgr::ProjectAndClipVertices@<eax>(
        CShadowMgr *this@<ecx>,
        CClipTop *a2@<edi>,
        const CShadowMgr::Shadow_t *shadow,
        const VMatrix *worldToShadow,
        const VMatrix *pWorldToModel,
        int count,
        Vector **ppPosition,
        ShadowVertex_t ***ppOutVertex,
        ShadowClipState_t *clip)
{
  float *m_ClipDist; // ebx
  Vector *m_ClipPlane; // edi
  float dist; // xmm0_4
  CClipBottom *v14; // [esp+Ch] [ebp-3Ch]
  CClipLeft *v15; // [esp+Ch] [ebp-3Ch]
  CClipRight *v16; // [esp+Ch] [ebp-3Ch]
  CClipAbove *v17; // [esp+Ch] [ebp-3Ch]
  cplane_t outPlane; // [esp+18h] [ebp-30h] BYREF
  _DWORD v19[4]; // [esp+2Ch] [ebp-1Ch] BYREF
  __int64 worldPlane_4; // [esp+40h] [ebp-8h] OVERLAPPED BYREF
  const VMatrix *pWorldToModela; // [esp+68h] [ebp+20h]

  if ( !CShadowMgr::ProjectVerticesIntoShadowSpace(
          this,
          modelToShadow: worldToShadow,
          maxDist: shadow->m_MaxDist,
          count,
          ppPosition,
          clip) )
    return 0;
  ShadowClip_CClipTop_(clip, clipper: a2);
  ShadowClip_CClipBottom_(clip, clipper: v14);
  ShadowClip_CClipLeft_(clip, clipper: v15);
  ShadowClip_CClipRight_(clip, clipper: v16);
  if ( shadow->m_ClipPlaneCount == 0 )
    ShadowClip_CClipAbove_(clip, clipper: v17);
  pWorldToModela = nullptr;
  if ( shadow->m_ClipPlaneCount != 0 )
  {
    m_ClipDist = shadow->m_ClipDist;
    m_ClipPlane = shadow->m_ClipPlane;
    do
    {
      if ( pWorldToModel != nullptr )
      {
        v19[0] = LODWORD(m_ClipPlane->x);
        v19[1] = LODWORD(m_ClipPlane->y);
        v19[2] = LODWORD(m_ClipPlane->z);
        *(float *)&v19[3] = *m_ClipDist;
        MatrixTransformPlane(src: pWorldToModel, inPlane: (const cplane_t *)v19, &outPlane);
        dist = outPlane.dist;
        LODWORD(worldPlane_4) = &outPlane;
      }
      else
      {
        dist = *m_ClipDist;
        LODWORD(worldPlane_4) = m_ClipPlane;
      }
      *((float *)&worldPlane_4 + 1) = dist;
      ShadowClip_CClipPlane_(clip, clipper: (CClipPlane *)&worldPlane_4);
      ++m_ClipDist;
      ++m_ClipPlane;
      pWorldToModela = (const VMatrix *)((char *)pWorldToModela + 1);
    }
    while ( (int)pWorldToModela < shadow->m_ClipPlaneCount );
  }
  if ( clip->m_ClipCount < 3 )
    return 0;
  *ppOutVertex = clip->m_ppClipVertices[clip->m_CurrVert];
  return clip->m_ClipCount;
}

//------------------------------------------------------------------------------
// Address: 0x1010A1F0
// Name: public: virtual int CShadowMgr::ProjectAndClipVertices(unsigned short,int,class Vector __near * __near *,struct ShadowVertex_t __near * __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShadowMgr::ProjectAndClipVertices(
        CShadowMgr *this,
        unsigned __int16 handle,
        int count,
        Vector **ppPosition,
        ShadowVertex_t ***ppOutVertex)
{
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v6; // [esp-1Ch] [ebp-1Ch]

  if ( (_S1_12 & 1) == 0 )
    _S1_12 |= 1u;
  v6 = &this->m_Shadows.m_Memory.m_pMemory[handle];
  return CShadowMgr::ProjectAndClipVertices(
           this,
           shadow: &v6->m_Element,
           worldToShadow: &v6->m_Element.m_WorldToShadow,
           pWorldToModel: nullptr,
           count,
           ppPosition,
           ppOutVertex,
           clip: &clip);
}

//------------------------------------------------------------------------------
// Address: 0x1010A240
// Name: public: virtual int CShadowMgr::ProjectAndClipVerticesEx(unsigned short,int,class Vector __near * __near *,struct ShadowVertex_t __near * __near * __near *,struct ShadowClipState_t __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShadowMgr::ProjectAndClipVerticesEx(
        CShadowMgr *this,
        unsigned __int16 handle,
        int count,
        Vector **ppPosition,
        ShadowVertex_t ***ppOutVertex,
        ShadowClipState_t *clip)
{
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v7; // [esp-1Ch] [ebp-1Ch]

  v7 = &this->m_Shadows.m_Memory.m_pMemory[handle];
  return CShadowMgr::ProjectAndClipVertices(
           this,
           shadow: &v7->m_Element,
           worldToShadow: &v7->m_Element.m_WorldToShadow,
           pWorldToModel: nullptr,
           count,
           ppPosition,
           ppOutVertex,
           clip);
}

//------------------------------------------------------------------------------
// Address: 0x1010A270
// Name: private: void CShadowMgr::ProcessDispDecalWorkItem(struct CShadowMgr::DispDecalWorkItem_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::ProcessDispDecalWorkItem(CShadowMgr *this, CShadowMgr::DispDecalWorkItem_t *wi)
{
  UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short> *v2; // eax

  v2 = &this->m_ShadowDecals.m_Memory.m_pMemory[wi->h];
  wi->bKeepShadow = v2->m_Element.m_SurfID->pDispInfo->ComputeShadowFragments(
                      this: v2->m_Element.m_SurfID->pDispInfo,
                      a2: v2->m_Element.m_DispShadow,
                      a3: &wi->vertCount,
                      a4: &wi->indexCount);
}

//------------------------------------------------------------------------------
// Address: 0x1010A2B0
// Name: public: virtual void CShadowMgr::ComputeRenderInfo(struct ShadowDecalRenderInfo_t __near *,unsigned short)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::ComputeRenderInfo(
        CShadowMgr *this,
        ShadowDecalRenderInfo_t *pInfo,
        unsigned __int16 handle)
{
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v3; // eax
  float m_flFalloffOffset; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm2_4

  v3 = &this->m_Shadows.m_Memory.m_pMemory[handle];
  pInfo->m_vTexOrigin = v3->m_Element.m_TexOrigin;
  pInfo->m_vTexSize = v3->m_Element.m_TexSize;
  pInfo->m_flFalloffOffset = v3->m_Element.m_FalloffOffset * 0.69999999;
  m_flFalloffOffset = pInfo->m_flFalloffOffset;
  pInfo->m_flFalloffAmount = v3->m_Element.m_FalloffAmount;
  pInfo->m_flFalloffBias = (float)v3->m_Element.m_FalloffBias;
  v5 = 1.0;
  v6 = v3->m_Element.m_MaxDist - m_flFalloffOffset;
  if ( v6 > 0.0 )
    v5 = 1.0 / v6;
  pInfo->m_flOOZFalloffDist = v5;
  pInfo->m_vShadowFalloffParams.y = v5;
  LODWORD(pInfo->m_vShadowFalloffParams.x) = COERCE_UNSIGNED_INT(m_flFalloffOffset * v5) ^ _mask__NegFloat_;
  pInfo->m_vShadowFalloffParams.z = (float)v3->m_Element.m_FalloffBias * 0.0039215689;
}

//------------------------------------------------------------------------------
// Address: 0x1010A360
// Name: private: int CShadowMgr::AddNormalShadowsToMeshBuilder(class CMeshBuilder __near &,struct CShadowMgr::ShadowRenderInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShadowMgr::AddNormalShadowsToMeshBuilder(
        CShadowMgr *this,
        CMeshBuilder *meshBuilder,
        CShadowMgr::ShadowRenderInfo_t *info)
{
  int result; // eax
  int v5; // eax
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short> *v6; // ebx
  unsigned int m_Count; // eax
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short> *m_pVerts; // edi
  int m_CachedVerts; // edi
  float *p_z; // eax
  float v11; // xmm1_4
  float *m_pCurrPosition; // ecx
  float v13; // xmm2_4
  float y; // xmm0_4
  float v15; // xmm0_4
  int v16; // xmm1_4
  float *v17; // ecx
  int v18; // ecx
  int v19; // edx
  float v20; // xmm1_4
  float *v21; // eax
  float v22; // xmm2_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  float z; // xmm1_4
  float *v26; // eax
  int v27; // eax
  double x; // st7
  float v29; // xmm0_4
  float v30; // xmm2_4
  float v31; // xmm1_4
  float *v32; // eax
  float v33; // xmm2_4
  float v34; // xmm0_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  float *v37; // eax
  int v38; // eax
  int v39; // eax
  ShadowDecalRenderInfo_t shadow; // [esp+0h] [ebp-3Ch] BYREF
  int vCount; // [esp+2Ch] [ebp-10h]
  CShadowMgr *v42; // [esp+30h] [ebp-Ch]
  int i; // [esp+34h] [ebp-8h]
  int baseIndex; // [esp+38h] [ebp-4h]
  int j; // [esp+44h] [ebp+8h]

  result = 0;
  v42 = this;
  baseIndex = 0;
  i = 0;
  if ( info->m_Count > 0 )
  {
    while ( 1 )
    {
      v5 = info->m_pCache[i];
      v6 = v5 >= 0
         ? &this->m_VertexCache.m_Memory.m_pMemory[(unsigned __int16)v5]
         : (UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short> *)&this->m_TempVertexCache.m_Memory.m_pMemory[-v5 - 1];
      m_Count = v6->m_Element.m_Count;
      if ( (_WORD)m_Count != 0 )
      {
        m_pVerts = (UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short> *)v6->m_Element.m_pVerts;
        if ( m_pVerts == nullptr )
        {
          m_CachedVerts = v6->m_Element.m_CachedVerts;
          if ( m_Count > 8 )
            m_pVerts = (UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short> *)&this->m_LargeVertexList.m_Memory.m_pMemory[m_CachedVerts];
          else
            m_pVerts = &this->m_SmallVertexList.m_Memory.m_pMemory[m_CachedVerts];
        }
      }
      else
      {
        m_pVerts = nullptr;
      }
      ((void (__stdcall *)(ShadowDecalRenderInfo_t *, _DWORD))g_pShadowMgr->ComputeRenderInfo)(
        a1: &shadow,
        a2: v6->m_Element.m_Shadow);
      vCount = v6->m_Element.m_Count - 2;
      if ( vCount > 0 )
      {
        j = 0;
        p_z = &m_pVerts->m_Element.m_Verts[0].m_Position.z;
        do
        {
          v11 = p_z[2] * shadow.m_vTexSize.y;
          m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
          v13 = shadow.m_vTexOrigin.x + (float)(p_z[1] * shadow.m_vTexSize.x);
          y = shadow.m_vTexOrigin.y;
          *m_pCurrPosition = m_pVerts->m_Element.m_Verts[0].m_Position.x;
          v15 = y + v11;
          m_pCurrPosition[1] = *(p_z - 1);
          m_pCurrPosition[2] = *p_z;
          v16 = *((_DWORD *)p_z + 3);
          v17 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
          *v17 = v13;
          v17[1] = v15;
          *((_DWORD *)v17 + 2) = v16;
          *(Vector *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1] = shadow.m_vShadowFalloffParams;
          v18 = ++meshBuilder->m_VertexBuilder.m_nCurrentVertex;
          if ( v18 > meshBuilder->m_VertexBuilder.m_nVertexCount )
            meshBuilder->m_VertexBuilder.m_nVertexCount = v18;
          meshBuilder->m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                                                                 + meshBuilder->m_VertexBuilder.m_VertexSize_Position);
          meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0]
                                                                    + meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[0]);
          meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1]
                                                                    + meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[1]);
          meshBuilder->m_IndexBuilder.m_pIndices[meshBuilder->m_IndexBuilder.m_nCurrentIndex] = baseIndex
                                                                                              + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset);
          meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
          meshBuilder->m_IndexBuilder.m_nIndexCount = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
          meshBuilder->m_IndexBuilder.m_pIndices[meshBuilder->m_IndexBuilder.m_nCurrentIndex] = baseIndex
                                                                                              + j
                                                                                              + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset)
                                                                                              + 1;
          meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
          meshBuilder->m_IndexBuilder.m_nIndexCount = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
          meshBuilder->m_IndexBuilder.m_pIndices[meshBuilder->m_IndexBuilder.m_nCurrentIndex] = baseIndex
                                                                                              + j
                                                                                              + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset)
                                                                                              + 2;
          meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
          v19 = vCount;
          meshBuilder->m_IndexBuilder.m_nIndexCount = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
          m_pVerts = (UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short> *)((char *)m_pVerts + 24);
          p_z += 6;
          ++j;
        }
        while ( j < v19 );
        v20 = m_pVerts->m_Element.m_Verts[0].m_ShadowSpaceTexCoord.y * shadow.m_vTexSize.y;
        v21 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
        v22 = shadow.m_vTexOrigin.x
            + (float)(shadow.m_vTexSize.x * m_pVerts->m_Element.m_Verts[0].m_ShadowSpaceTexCoord.x);
        v23 = shadow.m_vTexOrigin.y;
        *v21 = m_pVerts->m_Element.m_Verts[0].m_Position.x;
        v24 = v23 + v20;
        v21[1] = m_pVerts->m_Element.m_Verts[0].m_Position.y;
        v21[2] = m_pVerts->m_Element.m_Verts[0].m_Position.z;
        z = m_pVerts->m_Element.m_Verts[0].m_ShadowSpaceTexCoord.z;
        v26 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
        *v26 = v22;
        v26[1] = v24;
        v26[2] = z;
        *(Vector *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1] = shadow.m_vShadowFalloffParams;
        v27 = ++meshBuilder->m_VertexBuilder.m_nCurrentVertex;
        if ( v27 > meshBuilder->m_VertexBuilder.m_nVertexCount )
          meshBuilder->m_VertexBuilder.m_nVertexCount = v27;
        x = m_pVerts->m_Element.m_Verts[1].m_Position.x;
        meshBuilder->m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                                                               + meshBuilder->m_VertexBuilder.m_VertexSize_Position);
        meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0]
                                                                  + meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[0]);
        v29 = shadow.m_vTexSize.x * m_pVerts->m_Element.m_Verts[1].m_ShadowSpaceTexCoord.x;
        v30 = shadow.m_vTexOrigin.x;
        v31 = m_pVerts->m_Element.m_Verts[1].m_ShadowSpaceTexCoord.y * shadow.m_vTexSize.y;
        meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1]
                                                                  + meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[1]);
        v32 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
        v33 = v30 + v29;
        v34 = shadow.m_vTexOrigin.y;
        *v32 = x;
        v35 = v34 + v31;
        v32[1] = m_pVerts->m_Element.m_Verts[1].m_Position.y;
        v32[2] = m_pVerts->m_Element.m_Verts[1].m_Position.z;
        v36 = m_pVerts->m_Element.m_Verts[1].m_ShadowSpaceTexCoord.z;
        v37 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
        *v37 = v33;
        v37[1] = v35;
        v37[2] = v36;
        *(Vector *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1] = shadow.m_vShadowFalloffParams;
        v38 = ++meshBuilder->m_VertexBuilder.m_nCurrentVertex;
        if ( v38 > meshBuilder->m_VertexBuilder.m_nVertexCount )
          meshBuilder->m_VertexBuilder.m_nVertexCount = v38;
        meshBuilder->m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                                                               + meshBuilder->m_VertexBuilder.m_VertexSize_Position);
        meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0]
                                                                  + meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[0]);
        v39 = baseIndex;
        meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1]
                                                                  + meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[1]);
        baseIndex = v39 + v19 + 2;
      }
      if ( ++i >= info->m_Count )
        break;
      this = v42;
    }
    return baseIndex;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010A740
// Name: private: int CShadowMgr::AddDisplacementShadowsToMeshBuilder(class CMeshBuilder __near &,struct CShadowMgr::ShadowRenderInfo_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShadowMgr::AddDisplacementShadowsToMeshBuilder(
        CShadowMgr *this,
        CMeshBuilder *meshBuilder,
        CShadowMgr::ShadowRenderInfo_t *info,
        int baseIndex)
{
  int result; // eax
  int i; // esi

  if ( r_DrawDisp.m_pParent == nullptr || r_DrawDisp.m_pParent->m_Value.m_nValue == 0 )
    return baseIndex;
  result = baseIndex;
  for ( i = 0; i < info->m_DispCount; ++i )
    result = DispInfo_AddShadowsToMeshBuilder(meshBuilder, h: info->m_pDispCache[i], baseIndex: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010A790
// Name: private: void CShadowMgr::RenderDebuggingInfo(struct CShadowMgr::ShadowRenderInfo_t const __near &,void (*)(unsigned short,class Vector const __near &))
// Source: json
//------------------------------------------------------------------------------
void __userpurge CShadowMgr::RenderDebuggingInfo(
        CShadowMgr *this@<ecx>,
        float a2@<ebp>,
        const CShadowMgr::ShadowRenderInfo_t *info,
        void (__cdecl *func)(unsigned __int16, const Vector *))
{
  int v4; // esi
  float x; // edi
  int v6; // eax
  unsigned __int16 *v7; // ecx
  unsigned int v8; // edx
  float *v9; // eax
  int v10; // eax
  int v11; // edx
  float v12; // xmm6_4
  float v13; // xmm7_4
  float v14; // xmm4_4
  float *v15; // eax
  float v16; // xmm2_4
  float v17; // xmm6_4
  float v18; // xmm5_4
  float v19; // xmm0_4
  float v20; // xmm4_4
  float v21; // xmm2_4
  float v22; // xmm4_4
  float v23; // xmm1_4
  float v24; // xmm5_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // [esp-24h] [ebp-5Ch]
  float v29; // [esp-8h] [ebp-40h]
  float v30; // [esp-4h] [ebp-3Ch]
  float v2; // [esp+0h] [ebp-38h]
  float v2_4; // [esp+4h] [ebp-34h]
  float v2_8; // [esp+8h] [ebp-30h]
  float v1; // [esp+Ch] [ebp-2Ch]
  float v1_4; // [esp+10h] [ebp-28h]
  float v1_8; // [esp+14h] [ebp-24h]
  Vector vecApex; // [esp+18h] [ebp-20h] BYREF
  Vector vecCentroid; // [esp+24h] [ebp-14h]
  void *v39; // [esp+30h] [ebp-8h]
  void *retaddr; // [esp+38h] [ebp+0h]

  vecCentroid.z = a2;
  v39 = retaddr;
  v4 = 0;
  x = *(float *)&this;
  for ( LODWORD(vecCentroid.x) = this; v4 < info->m_Count; ++v4 )
  {
    v6 = info->m_pCache[v4];
    if ( v6 >= 0 )
      v7 = (unsigned __int16 *)(*(_DWORD *)(LODWORD(x) + 180) + 16 * (unsigned __int16)v6);
    else
      v7 = (unsigned __int16 *)(*(_DWORD *)(LODWORD(x) + 208) - 4 * (3 * v6 + 3));
    v8 = *v7;
    if ( (_WORD)v8 != 0 )
    {
      v9 = *((float **)v7 + 2);
      if ( v9 == nullptr )
      {
        v10 = v7[2];
        if ( v8 > 8 )
          v9 = (float *)(*(_DWORD *)(LODWORD(x) + 256) + 772 * v10);
        else
          v9 = (float *)(*(_DWORD *)(LODWORD(x) + 228) + 196 * v10);
      }
    }
    else
    {
      v9 = nullptr;
    }
    memset(&vecApex, 0, sizeof(vecApex));
    v1 = *v9;
    v1_4 = v9[1];
    v1_8 = v9[2];
    v11 = *v7 - 2;
    vecCentroid.y = 0.0;
    if ( v11 > 0 )
    {
      v12 = v1_8;
      v13 = v1_4;
      v14 = v1;
      v15 = v9 + 12;
      do
      {
        v2 = *(v15 - 6);
        v2_4 = *(v15 - 5);
        v2_8 = *(v15 - 4);
        v16 = v2_8 - v12;
        v17 = *v15 - v2;
        v18 = v2 - v14;
        v29 = v15[1];
        v30 = v15[2];
        v19 = (float)(v2_4 - v13) * v17;
        v20 = (float)(v29 - v2_4) * v16;
        v21 = v16 * v17;
        v12 = v1_8;
        v22 = v20 - (float)((float)(v30 - v2_8) * (float)(v2_4 - v13));
        v13 = v1_4;
        v23 = (float)((float)((float)((float)((float)(v30 - v2_8) * v18) - v21)
                            * (float)((float)((float)(v30 - v2_8) * v18) - v21))
                    + (float)((float)(v19 - (float)((float)(v29 - v2_4) * v18))
                            * (float)(v19 - (float)((float)(v29 - v2_4) * v18))))
            + (float)(v22 * v22);
        v14 = v1;
        v28 = fsqrt(v23);
        v24 = v28 + vecCentroid.y;
        v25 = (float)((float)((float)((float)(v1 + v2) + *v15) * v28) * 0.33333334) + vecApex.x;
        v26 = (float)((float)((float)((float)(v1_4 + v2_4) + v29) * v28) * 0.33333334) + vecApex.y;
        v27 = (float)((float)((float)((float)(v1_8 + v2_8) + v30) * v28) * 0.33333334) + vecApex.z;
        v15 += 6;
        --v11;
        vecCentroid.y = v28 + vecCentroid.y;
        vecApex.x = v25;
        vecApex.y = v26;
        vecApex.z = v27;
      }
      while ( v11 != 0 );
      x = vecCentroid.x;
      if ( v24 != 0.0 )
      {
        vecApex.x = v25 * (float)(1.0 / v24);
        vecApex.y = (float)(1.0 / v24) * v26;
        vecApex.z = v27 * (float)(1.0 / v24);
      }
    }
    func(a1: v7[1], a2: &vecApex);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010AA10
// Name: public: virtual void CShadowMgr::UpdateFlashlightState(unsigned short,struct FlashlightState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::UpdateFlashlightState(
        CShadowMgr *this,
        unsigned __int16 shadowHandle,
        const FlashlightState_t *lightState)
{
  qmemcpy(
    (void *)&this->m_FlashlightStates.m_Memory.m_pMemory[this->m_Shadows.m_Memory.m_pMemory[shadowHandle].m_Element.m_FlashlightHandle].m_Element.m_FlashlightState,
    lightState,
    sizeof(this->m_FlashlightStates.m_Memory.m_pMemory[this->m_Shadows.m_Memory.m_pMemory[shadowHandle].m_Element.m_FlashlightHandle].m_Element.m_FlashlightState));
}

//------------------------------------------------------------------------------
// Address: 0x1010AA50
// Name: public: virtual void CShadowMgr::SetFlashlightDepthTexture(unsigned short,class ITexture __near *,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::SetFlashlightDepthTexture(
        CShadowMgr *this,
        unsigned __int16 shadowHandle,
        ITexture *pFlashlightDepthTexture,
        unsigned __int8 ucShadowStencilBit)
{
  int v4; // eax

  v4 = shadowHandle;
  this->m_Shadows.m_Memory.m_pMemory[v4].m_Element.m_pFlashlightDepthTexture = pFlashlightDepthTexture;
  this->m_Shadows.m_Memory.m_pMemory[v4].m_Element.m_ucShadowStencilBit = ucShadowStencilBit;
}

//------------------------------------------------------------------------------
// Address: 0x1010AA80
// Name: void DrawPolygonToStencil(class IMatRenderContext __near *,int,class Vector __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawPolygonToStencil(
        IMatRenderContext *pRenderContext,
        int nNumVerts,
        Vector *pVecPoints,
        bool bFrontFacing)
{
  IMaterial *v4; // eax
  IMesh *v6; // edi
  int v7; // ebx
  int v8; // edi
  float *m_pCurrPosition; // eax
  float y; // xmm0_4
  float z; // xmm1_4
  int v12; // eax
  float *v13; // ecx
  int v14; // eax
  int v15; // eax
  float v16; // xmm0_4
  float v17; // xmm1_4
  int v18; // eax
  float *v19; // ecx
  int v20; // eax
  int v21; // eax
  float v22; // xmm0_4
  float v23; // xmm1_4
  int m_nVertexCount; // edi
  int v25; // eax
  void (__thiscall *MatrixMode)(IMatRenderContext *, MaterialMatrixMode_t); // edx
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-1E8h] BYREF
  int i; // [esp+1FCh] [ebp+8h]
  int nNumVertsa; // [esp+200h] [ebp+Ch]

  v4 = materials->FindMaterial(this: materials, a2: "engine/writestencil", a3: "Other textures", a4: 1, a5: 0);
  pRenderContext->Bind(this: pRenderContext, a2: v4, a3: nullptr);
  v6 = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 1, a3: 0, a4: 0, a5: 0);
  pRenderContext->MatrixMode(this: pRenderContext, a2: MATERIAL_MODEL);
  pRenderContext->PushMatrix(this: pRenderContext);
  pRenderContext->LoadIdentity(this: pRenderContext);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v6;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_TRIANGLES;
  v7 = 3 * nNumVerts - 6;
  v6->SetPrimitiveType(this: v6, a2: MATERIAL_TRIANGLES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v7, a3: v7, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v6->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v7;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v6, nMaxVertexCount: v7, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  v8 = 1;
  i = 1;
  nNumVertsa = nNumVerts - 1;
  if ( nNumVertsa <= 1 )
  {
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  }
  else
  {
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    while ( 1 )
    {
      y = pVecPoints->y;
      z = pVecPoints->z;
      *m_pCurrPosition = pVecPoints->x;
      m_pCurrPosition[1] = y;
      m_pCurrPosition[2] = z;
      v12 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
      meshBuilder.m_VertexBuilder.m_nCurrentVertex = v12;
      if ( v12 > meshBuilder.m_VertexBuilder.m_nVertexCount )
        meshBuilder.m_VertexBuilder.m_nVertexCount = v12;
      v13 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                    + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
      v14 = v8;
      meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                            + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
      if ( !bFrontFacing )
        v14 = v8 + 1;
      v15 = v14;
      v16 = pVecPoints[v15].y;
      v17 = pVecPoints[v15].z;
      *v13 = pVecPoints[v15].x;
      v13[1] = v16;
      v13[2] = v17;
      v18 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
      meshBuilder.m_VertexBuilder.m_nCurrentVertex = v18;
      if ( v18 > meshBuilder.m_VertexBuilder.m_nVertexCount )
        meshBuilder.m_VertexBuilder.m_nVertexCount = v18;
      v19 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                    + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
      v20 = v8 + 1;
      meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                            + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
      if ( !bFrontFacing )
        v20 = v8;
      v21 = v20;
      v22 = pVecPoints[v21].y;
      v23 = pVecPoints[v21].z;
      *v19 = pVecPoints[v21].x;
      v19[1] = v22;
      v19[2] = v23;
      m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
      v25 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
      meshBuilder.m_VertexBuilder.m_nCurrentVertex = v25;
      if ( v25 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      {
        m_nVertexCount = v25;
        meshBuilder.m_VertexBuilder.m_nVertexCount = v25;
      }
      m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
      ++i;
      meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                            + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
      if ( i >= nNumVertsa )
        break;
      v8 = i;
    }
  }
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount *= 2;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * m_nVertexCount / 4;
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
  meshBuilder.m_pMesh->UnlockMesh(
    this: meshBuilder.m_pMesh,
    a2: m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh->Draw_2(this: meshBuilder.m_pMesh, a2: -1, a3: 0);
  MatrixMode = pRenderContext->MatrixMode;
  meshBuilder.m_pMesh = nullptr;
  MatrixMode(this: pRenderContext, a2: MATERIAL_MODEL);
  pRenderContext->PopMatrix(this: pRenderContext);
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

//------------------------------------------------------------------------------
// Address: 0x1010ADC0
// Name: private: void CShadowMgr::SetStencilAndScissor(class IMatRenderContext __near *,struct CShadowMgr::FlashlightInfo_t __near &,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CShadowMgr::SetStencilAndScissor(
        CShadowMgr *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        IMatRenderContext *pRenderContext,
        int flashlightInfo,
        bool bUseStencil)
{
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v7; // eax
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm1_4
  int i; // eax
  float v13; // xmm5_4
  float v14; // xmm7_4
  float v15; // xmm7_4
  float v16; // xmm5_4
  float v17; // xmm7_4
  float v18; // xmm6_4
  float v19; // xmm5_4
  float v20; // xmm7_4
  float v21; // xmm6_4
  float v22; // xmm7_4
  float v23; // xmm7_4
  float v24; // xmm5_4
  float v25; // xmm7_4
  float v26; // xmm6_4
  float v27; // xmm5_4
  float v28; // xmm7_4
  float v29; // xmm6_4
  float v30; // xmm7_4
  float v31; // xmm7_4
  float v32; // xmm5_4
  float v33; // xmm6_4
  float v34; // xmm5_4
  float v35; // xmm7_4
  float v36; // xmm6_4
  float v37; // xmm7_4
  float v38; // xmm7_4
  float v39; // xmm5_4
  float v40; // xmm7_4
  float v41; // xmm6_4
  float v42; // xmm7_4
  const QAngle *v43; // esi
  float v44; // xmm0_4
  int v45; // ebx
  unsigned __int8 *v46; // edi
  int v47; // eax
  int v48; // eax
  unsigned int v49; // esi
  int v50; // eax
  float v51; // ecx
  int v52; // eax
  int v53; // edi
  float *v54; // ebx
  int v55; // esi
  float *v56; // edx
  float *v57; // ecx
  CShadowMgr::FlashlightInfo_t *v58; // ecx
  IMatRenderContext *v59; // edi
  bool v60; // al
  int v61; // eax
  int v62; // edx
  int v63; // eax
  ConVar *m_pParent; // eax
  int v65; // esi
  Vector *v66; // edi
  int v67; // edx
  unsigned __int8 *v68; // eax
  unsigned int v69; // edx
  IMatRenderContext_vtbl *v70; // eax
  int v71; // esi
  Vector *v72; // edi
  void (__thiscall *SetStencilState)(IMatRenderContext *, const ShaderStencilState_t *); // edx
  _BYTE dst[961]; // [esp+8h] [ebp-798h] OVERLAPPED BYREF
  Vector vClippedFace[6]; // [esp+3DCh] [ebp-3C4h] BYREF
  Vector vTempFace[5]; // [esp+424h] [ebp-37Ch] BYREF
  Vector vWorldFrustumPoints[24]; // [esp+460h] [ebp-340h] BYREF
  ShaderStencilState_t stateDisable; // [esp+580h] [ebp-220h] BYREF
  int v79; // [esp+5ACh] [ebp-1F4h] BYREF
  ShaderStencilState_t state; // [esp+5B0h] [ebp-1F0h] BYREF
  int nNumVertices[8]; // [esp+5E0h] [ebp-1C0h] BYREF
  Vector vFarNormal; // [esp+600h] [ebp-1A0h] BYREF
  Vector vForward; // [esp+60Ch] [ebp-194h]
  Vector vNearNormal; // [esp+618h] [ebp-188h]
  float v85; // [esp+624h] [ebp-17Ch]
  float v86; // [esp+628h] [ebp-178h]
  int v87; // [esp+62Ch] [ebp-174h]
  int v88; // [esp+630h] [ebp-170h]
  int v89; // [esp+634h] [ebp-16Ch]
  int v90; // [esp+638h] [ebp-168h]
  int v91; // [esp+63Ch] [ebp-164h]
  Vector vFrustumPoints[24]; // [esp+640h] [ebp-160h] BYREF
  int nLeft; // [esp+760h] [ebp-40h]
  VMatrix matFlashlightToWorld; // [esp+764h] [ebp-3Ch] BYREF

  v7 = &this->m_Shadows.m_Memory.m_pMemory[*(unsigned __int16 *)(flashlightInfo + 572)];
  LODWORD(vForward.y) = this;
  MatrixInverseGeneral(src: &v7->m_Element.m_WorldToShadow, dst: (VMatrix *)&vFrustumPoints[22].z);
  v87 = 0;
  v88 = 0;
  v89 = 0;
  v90 = 1065353216;
  v91 = 0;
  vFrustumPoints[0].x = 0.0;
  vFrustumPoints[0].y = 1.0;
  vFrustumPoints[0].z = 1.0;
  vFrustumPoints[1].x = 0.0;
  vFrustumPoints[1].y = 0.0;
  vFrustumPoints[1].z = 1.0;
  memset(&vFrustumPoints[2], 0, sizeof(Vector));
  vFrustumPoints[3].x = 1.0;
  vFrustumPoints[3].y = 0.0;
  vFrustumPoints[3].z = 1.0;
  vFrustumPoints[4].x = 1.0;
  vFrustumPoints[4].y = 1.0;
  vFrustumPoints[4].z = 1.0;
  vFrustumPoints[5].x = 1.0;
  vFrustumPoints[5].y = 1.0;
  vFrustumPoints[5].z = 0.0;
  vFrustumPoints[6].x = 1.0;
  vFrustumPoints[6].y = 1.0;
  vFrustumPoints[6].z = 0.0;
  vFrustumPoints[7].x = 0.0;
  vFrustumPoints[7].y = 1.0;
  vFrustumPoints[7].z = 0.0;
  vFrustumPoints[8].x = 1.0;
  vFrustumPoints[8].y = 1.0;
  vFrustumPoints[8].z = 1.0;
  vFrustumPoints[9].x = 1.0;
  vFrustumPoints[9].y = 1.0;
  vFrustumPoints[9].z = 1.0;
  memset(&vFrustumPoints[10], 0, 20);
  vFrustumPoints[11].z = 1.0;
  vFrustumPoints[12].x = 0.0;
  vFrustumPoints[12].y = 0.0;
  vFrustumPoints[12].z = 1.0;
  vFrustumPoints[13].x = 1.0;
  vFrustumPoints[13].y = 0.0;
  vFrustumPoints[13].z = 0.0;
  vFrustumPoints[14].x = 1.0;
  vFrustumPoints[14].y = 0.0;
  vFrustumPoints[14].z = 1.0;
  vFrustumPoints[15].x = 0.0;
  vFrustumPoints[15].y = 1.0;
  vFrustumPoints[15].z = 1.0;
  vFrustumPoints[16].x = 0.0;
  vFrustumPoints[16].y = 1.0;
  vFrustumPoints[16].z = 1.0;
  vFrustumPoints[17].x = 1.0;
  vFrustumPoints[17].y = 0.0;
  vFrustumPoints[17].z = 1.0;
  vFrustumPoints[18].x = 1.0;
  vFrustumPoints[18].y = 0.0;
  vFrustumPoints[18].z = 0.0;
  memset(&vFrustumPoints[19], 0, sizeof(Vector));
  vFrustumPoints[20].x = 1.0;
  vFrustumPoints[20].y = 1.0;
  vFrustumPoints[20].z = 0.0;
  vFrustumPoints[21].x = 1.0;
  v8 = matFlashlightToWorld.m[2][1];
  v9 = matFlashlightToWorld.m[2][0];
  v10 = matFlashlightToWorld.m[1][3];
  vFrustumPoints[21].z = 0.0;
  vFrustumPoints[22].x = 0.0;
  v11 = matFlashlightToWorld.m[2][2];
  vFrustumPoints[21].y = 1.0;
  for ( i = 0; i < 24; i += 8 )
  {
    v13 = 1.0
        / (float)((float)((float)((float)(v10 * *(float *)((char *)&v87 + i * 12))
                                + (float)(v9 * *(float *)((char *)&v88 + i * 12)))
                        + (float)(v8 * *(float *)((char *)&v89 + i * 12)))
                + v11);
    vTempFace[i + 3].y = (float)((float)((float)((float)(vFrustumPoints[22].z * *(float *)((char *)&v87 + i * 12))
                                               + (float)(vFrustumPoints[23].x * *(float *)((char *)&v88 + i * 12)))
                                       + (float)(vFrustumPoints[23].y * *(float *)((char *)&v89 + i * 12)))
                               + vFrustumPoints[23].z)
                       * v13;
    v14 = matFlashlightToWorld.m[1][0] * *(float *)((char *)&v88 + i * 12);
    vTempFace[i + 3].z = (float)((float)((float)((float)(*(float *)&nLeft * *(float *)((char *)&v87 + i * 12))
                                               + (float)(matFlashlightToWorld.m[0][0] * *(float *)((char *)&v88 + i * 12)))
                                       + (float)(matFlashlightToWorld.m[0][1] * *(float *)((char *)&v89 + i * 12)))
                               + matFlashlightToWorld.m[0][2])
                       * v13;
    vTempFace[i + 4].x = (float)((float)((float)((float)(matFlashlightToWorld.m[0][3] * *(float *)((char *)&v87 + i * 12))
                                               + v14)
                                       + (float)(matFlashlightToWorld.m[1][1] * *(float *)((char *)&v89 + i * 12)))
                               + matFlashlightToWorld.m[1][2])
                       * v13;
    v15 = (float)(v10 * *(float *)((char *)&v90 + i * 12)) + (float)(v9 * *(float *)((char *)&v91 + i * 12));
    matFlashlightToWorld.m[3][2] = v13;
    v16 = 1.0 / (float)((float)(v15 + (float)(v8 * vFrustumPoints[i].x)) + v11);
    v17 = matFlashlightToWorld.m[0][0] * *(float *)((char *)&v91 + i * 12);
    vTempFace[i + 4].y = (float)((float)((float)((float)(vFrustumPoints[22].z * *(float *)((char *)&v90 + i * 12))
                                               + (float)(vFrustumPoints[23].x * *(float *)((char *)&v91 + i * 12)))
                                       + (float)(vFrustumPoints[23].y * vFrustumPoints[i].x))
                               + vFrustumPoints[23].z)
                       * v16;
    vTempFace[i + 4].z = (float)((float)((float)((float)(*(float *)&nLeft * *(float *)((char *)&v90 + i * 12)) + v17)
                                       + (float)(matFlashlightToWorld.m[0][1] * vFrustumPoints[i].x))
                               + matFlashlightToWorld.m[0][2])
                       * v16;
    v18 = matFlashlightToWorld.m[0][3] * *(float *)((char *)&v90 + i * 12);
    matFlashlightToWorld.m[3][2] = v16;
    vWorldFrustumPoints[i].x = (float)((float)((float)(v18
                                                     + (float)(matFlashlightToWorld.m[1][0]
                                                             * *(float *)((char *)&v91 + i * 12)))
                                             + (float)(matFlashlightToWorld.m[1][1] * vFrustumPoints[i].x))
                                     + matFlashlightToWorld.m[1][2])
                             * v16;
    v19 = 1.0
        / (float)((float)((float)((float)(v10 * vFrustumPoints[i].y) + (float)(v9 * vFrustumPoints[i].z))
                        + (float)(v8 * vFrustumPoints[i + 1].x))
                + v11);
    v20 = matFlashlightToWorld.m[0][0] * vFrustumPoints[i].z;
    vWorldFrustumPoints[i].y = (float)((float)((float)((float)(vFrustumPoints[22].z * vFrustumPoints[i].y)
                                                     + (float)(vFrustumPoints[23].x * vFrustumPoints[i].z))
                                             + (float)(vFrustumPoints[23].y * vFrustumPoints[i + 1].x))
                                     + vFrustumPoints[23].z)
                             * v19;
    v21 = (float)((float)((float)(*(float *)&nLeft * vFrustumPoints[i].y) + v20)
                + (float)(matFlashlightToWorld.m[0][1] * vFrustumPoints[i + 1].x))
        + matFlashlightToWorld.m[0][2];
    v22 = matFlashlightToWorld.m[1][0] * vFrustumPoints[i].z;
    vWorldFrustumPoints[i].z = v21 * v19;
    vWorldFrustumPoints[i + 1].x = (float)((float)((float)((float)(matFlashlightToWorld.m[0][3] * vFrustumPoints[i].y)
                                                         + v22)
                                                 + (float)(matFlashlightToWorld.m[1][1] * vFrustumPoints[i + 1].x))
                                         + matFlashlightToWorld.m[1][2])
                                 * v19;
    v23 = (float)(v10 * vFrustumPoints[i + 1].y) + (float)(v9 * vFrustumPoints[i + 1].z);
    matFlashlightToWorld.m[3][2] = v19;
    v24 = 1.0 / (float)((float)(v23 + (float)(v8 * vFrustumPoints[i + 2].x)) + v11);
    v25 = matFlashlightToWorld.m[0][0] * vFrustumPoints[i + 1].z;
    vWorldFrustumPoints[i + 1].y = (float)((float)((float)((float)(vFrustumPoints[22].z * vFrustumPoints[i + 1].y)
                                                         + (float)(vFrustumPoints[23].x * vFrustumPoints[i + 1].z))
                                                 + (float)(vFrustumPoints[23].y * vFrustumPoints[i + 2].x))
                                         + vFrustumPoints[23].z)
                                 * v24;
    v26 = *(float *)&nLeft * vFrustumPoints[i + 1].y;
    matFlashlightToWorld.m[3][2] = v24;
    vWorldFrustumPoints[i + 1].z = (float)((float)((float)(v26 + v25)
                                                 + (float)(matFlashlightToWorld.m[0][1] * vFrustumPoints[i + 2].x))
                                         + matFlashlightToWorld.m[0][2])
                                 * v24;
    vWorldFrustumPoints[i + 2].x = (float)((float)((float)((float)(matFlashlightToWorld.m[0][3] * vFrustumPoints[i + 1].y)
                                                         + (float)(matFlashlightToWorld.m[1][0] * vFrustumPoints[i + 1].z))
                                                 + (float)(matFlashlightToWorld.m[1][1] * vFrustumPoints[i + 2].x))
                                         + matFlashlightToWorld.m[1][2])
                                 * v24;
    v27 = 1.0
        / (float)((float)((float)((float)(v10 * vFrustumPoints[i + 2].y) + (float)(v9 * vFrustumPoints[i + 2].z))
                        + (float)(v8 * vFrustumPoints[i + 3].x))
                + v11);
    v28 = matFlashlightToWorld.m[0][0] * vFrustumPoints[i + 2].z;
    vWorldFrustumPoints[i + 2].y = (float)((float)((float)((float)(vFrustumPoints[22].z * vFrustumPoints[i + 2].y)
                                                         + (float)(vFrustumPoints[23].x * vFrustumPoints[i + 2].z))
                                                 + (float)(vFrustumPoints[23].y * vFrustumPoints[i + 3].x))
                                         + vFrustumPoints[23].z)
                                 * v27;
    v29 = (float)((float)((float)(*(float *)&nLeft * vFrustumPoints[i + 2].y) + v28)
                + (float)(matFlashlightToWorld.m[0][1] * vFrustumPoints[i + 3].x))
        + matFlashlightToWorld.m[0][2];
    v30 = matFlashlightToWorld.m[1][0] * vFrustumPoints[i + 2].z;
    vWorldFrustumPoints[i + 2].z = v29 * v27;
    vWorldFrustumPoints[i + 3].x = (float)((float)((float)((float)(matFlashlightToWorld.m[0][3] * vFrustumPoints[i + 2].y)
                                                         + v30)
                                                 + (float)(matFlashlightToWorld.m[1][1] * vFrustumPoints[i + 3].x))
                                         + matFlashlightToWorld.m[1][2])
                                 * v27;
    v31 = (float)(v10 * vFrustumPoints[i + 3].y) + (float)(v9 * vFrustumPoints[i + 3].z);
    matFlashlightToWorld.m[3][2] = v27;
    v32 = 1.0 / (float)((float)(v31 + (float)(v8 * vFrustumPoints[i + 4].x)) + v11);
    v33 = (float)(vFrustumPoints[22].z * vFrustumPoints[i + 3].y)
        + (float)(vFrustumPoints[23].x * vFrustumPoints[i + 3].z);
    matFlashlightToWorld.m[3][2] = v32;
    vWorldFrustumPoints[i + 3].y = (float)((float)(v33 + (float)(vFrustumPoints[23].y * vFrustumPoints[i + 4].x))
                                         + vFrustumPoints[23].z)
                                 * v32;
    vWorldFrustumPoints[i + 3].z = (float)((float)((float)((float)(*(float *)&nLeft * vFrustumPoints[i + 3].y)
                                                         + (float)(matFlashlightToWorld.m[0][0] * vFrustumPoints[i + 3].z))
                                                 + (float)(matFlashlightToWorld.m[0][1] * vFrustumPoints[i + 4].x))
                                         + matFlashlightToWorld.m[0][2])
                                 * v32;
    vWorldFrustumPoints[i + 4].x = (float)((float)((float)((float)(matFlashlightToWorld.m[0][3] * vFrustumPoints[i + 3].y)
                                                         + (float)(matFlashlightToWorld.m[1][0] * vFrustumPoints[i + 3].z))
                                                 + (float)(matFlashlightToWorld.m[1][1] * vFrustumPoints[i + 4].x))
                                         + matFlashlightToWorld.m[1][2])
                                 * v32;
    v34 = 1.0
        / (float)((float)((float)((float)(v10 * vFrustumPoints[i + 4].y) + (float)(v9 * vFrustumPoints[i + 4].z))
                        + (float)(v8 * vFrustumPoints[i + 5].x))
                + v11);
    v35 = matFlashlightToWorld.m[0][0] * vFrustumPoints[i + 4].z;
    vWorldFrustumPoints[i + 4].y = (float)((float)((float)((float)(vFrustumPoints[22].z * vFrustumPoints[i + 4].y)
                                                         + (float)(vFrustumPoints[23].x * vFrustumPoints[i + 4].z))
                                                 + (float)(vFrustumPoints[23].y * vFrustumPoints[i + 5].x))
                                         + vFrustumPoints[23].z)
                                 * v34;
    v36 = (float)((float)((float)(*(float *)&nLeft * vFrustumPoints[i + 4].y) + v35)
                + (float)(matFlashlightToWorld.m[0][1] * vFrustumPoints[i + 5].x))
        + matFlashlightToWorld.m[0][2];
    v37 = matFlashlightToWorld.m[1][0] * vFrustumPoints[i + 4].z;
    vWorldFrustumPoints[i + 4].z = v36 * v34;
    vWorldFrustumPoints[i + 5].x = (float)((float)((float)((float)(matFlashlightToWorld.m[0][3] * vFrustumPoints[i + 4].y)
                                                         + v37)
                                                 + (float)(matFlashlightToWorld.m[1][1] * vFrustumPoints[i + 5].x))
                                         + matFlashlightToWorld.m[1][2])
                                 * v34;
    v38 = (float)((float)(v10 * vFrustumPoints[i + 5].y) + (float)(v9 * vFrustumPoints[i + 5].z))
        + (float)(v8 * vFrustumPoints[i + 6].x);
    matFlashlightToWorld.m[3][2] = v34;
    v39 = 1.0 / (float)(v38 + v11);
    v40 = matFlashlightToWorld.m[0][0] * vFrustumPoints[i + 5].z;
    vWorldFrustumPoints[i + 5].y = (float)((float)((float)((float)(vFrustumPoints[i + 5].y * vFrustumPoints[22].z)
                                                         + (float)(vFrustumPoints[23].x * vFrustumPoints[i + 5].z))
                                                 + (float)(vFrustumPoints[23].y * vFrustumPoints[i + 6].x))
                                         + vFrustumPoints[23].z)
                                 * v39;
    v41 = (float)((float)((float)(*(float *)&nLeft * vFrustumPoints[i + 5].y) + v40)
                + (float)(matFlashlightToWorld.m[0][1] * vFrustumPoints[i + 6].x))
        + matFlashlightToWorld.m[0][2];
    v42 = matFlashlightToWorld.m[1][0] * vFrustumPoints[i + 5].z;
    vWorldFrustumPoints[i + 5].z = v41 * v39;
    vWorldFrustumPoints[i + 6].x = (float)((float)((float)((float)(matFlashlightToWorld.m[0][3] * vFrustumPoints[i + 5].y)
                                                         + v42)
                                                 + (float)(matFlashlightToWorld.m[1][1] * vFrustumPoints[i + 6].x))
                                         + matFlashlightToWorld.m[1][2])
                                 * v39;
    matFlashlightToWorld.m[3][2] = v39;
  }
  v43 = (const QAngle *)((int (__thiscall *)(IRender *, int, int, int))g_EngineRenderer->ViewGetCurrent)(
                          a1: g_EngineRenderer,
                          a2: a3,
                          a3: a4,
                          a4: a2);
  AngleVectors(angles: v43 + 9, forward: (Vector *)&nNumVertices[6], right: nullptr, up: nullptr);
  v44 = (float)((float)(v43[8].y * *(float *)&nNumVertices[7]) + (float)(*(float *)&nNumVertices[6] * v43[8].x))
      + (float)(v43[8].z * vFarNormal.x);
  nNumVertices[4] = nNumVertices[7] ^ 0x80000000;
  *(float *)&nNumVertices[3] = -*(float *)&nNumVertices[6];
  *(float *)&nNumVertices[5] = -vFarNormal.x;
  LODWORD(vFarNormal.y) = nNumVertices[6];
  LODWORD(vFarNormal.z) = nNumVertices[7];
  vForward.x = vFarNormal.x;
  matFlashlightToWorld.m[2][3] = (float)(v43[10].x + 0.40000001) + v44;
  matFlashlightToWorld.m[3][0] = -(float)((float)(v43[10].y - 0.40000001) + v44);
  v45 = 0;
  v46 = dst;
  LODWORD(matFlashlightToWorld.m[3][2]) = &vTempFace[3].y;
  LODWORD(matFlashlightToWorld.m[3][1]) = 6;
  do
  {
    v47 = ClipPolyToPlane(
            inVerts: (Vector *)LODWORD(matFlashlightToWorld.m[3][2]),
            vertCount: 4,
            outVerts: (Vector *)&vClippedFace[4].y,
            normal: (Vector *)&vFarNormal.y,
            dist: matFlashlightToWorld.m[2][3],
            fOnPlaneEpsilon: 0.1);
    if ( v47 > 2 )
    {
      v48 = ClipPolyToPlane(
              inVerts: (Vector *)&vClippedFace[4].y,
              vertCount: v47,
              outVerts: (Vector *)&dst[960],
              normal: (const Vector *)&nNumVertices[3],
              dist: matFlashlightToWorld.m[3][0],
              fOnPlaneEpsilon: 0.1);
      v49 = v48;
      if ( v48 > 2 )
      {
        memcpy(dst: v46, src: &dst[960], count: 12 * v48);
        *(&state.m_nWriteMask + v45++) = v49;
        v46 += 120;
      }
    }
    LODWORD(matFlashlightToWorld.m[3][2]) += 48;
    --LODWORD(matFlashlightToWorld.m[3][1]);
  }
  while ( LODWORD(matFlashlightToWorld.m[3][1]) != 0 );
  LODWORD(matFlashlightToWorld.m[3][2]) = v45;
  ConstructNearAndFarPolygons(
    pVecNearPlane: (Vector *)&vWorldFrustumPoints[22].y,
    pVecFarPlane: (Vector *)&stateDisable.m_nWriteMask,
    flPlaneEpsilon: 0.40000001);
  v50 = ClipPlaneToFrustum(
          pInPoints: (Vector *)&vWorldFrustumPoints[22].y,
          pOutPoints: (Vector *)&dst[120 * v45],
          pVecWorldFrustumPoints: (Vector *)&vTempFace[3].y);
  if ( v50 > 2 )
  {
    *(&state.m_nWriteMask + v45++) = v50;
    LODWORD(matFlashlightToWorld.m[3][2]) = v45;
  }
  v51 = 0.0;
  matFlashlightToWorld.m[2][3] = 0.0;
  if ( v45 > 0 )
  {
    matFlashlightToWorld.m[3][1] = 0.0;
    do
    {
      v52 = 0;
      matFlashlightToWorld.m[3][0] = 0.0;
      if ( *((int *)&state.m_nWriteMask + LODWORD(v51)) > 0 )
      {
        vFrustumPoints[22].y = *((float *)&state.m_nWriteMask + LODWORD(v51));
        do
        {
          v53 = LODWORD(v51) + 1;
          if ( LODWORD(v51) + 1 < v45 )
          {
            v54 = (float *)&dst[120 * v53];
            do
            {
              if ( *((int *)&state.m_nWriteMask + v53) > 0 )
              {
                v55 = *(&state.m_nWriteMask + v53);
                v56 = (float *)&dst[12 * LODWORD(matFlashlightToWorld.m[3][1]) + 12 * v52];
                v57 = v54;
                do
                {
                  vNearNormal.z = *v57;
                  v85 = v57[1];
                  v86 = v57[2];
                  vForward.z = *v56;
                  vNearNormal.x = v56[1];
                  vNearNormal.y = v56[2];
                  if ( fabs(vForward.z - vNearNormal.z) <= 0.1
                    && fabs(vNearNormal.x - v85) <= 0.1
                    && fabs(vNearNormal.y - v86) <= 0.1 )
                  {
                    *v57 = *v56;
                    v57[1] = v56[1];
                    v57[2] = v56[2];
                  }
                  v57 += 3;
                  --v55;
                }
                while ( v55 != 0 );
                v52 = LODWORD(matFlashlightToWorld.m[3][0]);
              }
              ++v53;
              v54 += 30;
            }
            while ( v53 < SLODWORD(matFlashlightToWorld.m[3][2]) );
            v45 = LODWORD(matFlashlightToWorld.m[3][2]);
            v51 = matFlashlightToWorld.m[2][3];
          }
          LODWORD(matFlashlightToWorld.m[3][0]) = ++v52;
        }
        while ( v52 < SLODWORD(vFrustumPoints[22].y) );
      }
      LODWORD(matFlashlightToWorld.m[3][1]) += 10;
      ++LODWORD(v51);
      matFlashlightToWorld.m[2][3] = v51;
    }
    while ( SLODWORD(v51) < v45 );
  }
  v58 = (CShadowMgr::FlashlightInfo_t *)flashlightInfo;
  *(_BYTE *)(flashlightInfo + 553) = 0;
  if ( r_flashlightscissor.m_pParent != nullptr && r_flashlightscissor.m_pParent->m_Value.m_nValue != 0 && v45 > 0 )
  {
    v59 = pRenderContext;
    v60 = ScreenSpaceRectFromPoints(
            pRenderContext,
            vClippedPolygons: (Vector (*)[10])dst,
            pNumPoints: (int *)&state.m_nWriteMask,
            nNumPolygons: v45,
            nLeft: (int *)&vFrustumPoints[22].y,
            nTop: (int *)&matFlashlightToWorld.m[2][3],
            nRight: (int *)matFlashlightToWorld.m[3],
            nBottom: (int *)&matFlashlightToWorld.m[3][1]);
    v58 = (CShadowMgr::FlashlightInfo_t *)flashlightInfo;
    *(_BYTE *)(flashlightInfo + 553) = v60;
    if ( v60 )
    {
      v61 = LODWORD(matFlashlightToWorld.m[2][3]);
      *(float *)(flashlightInfo + 556) = vFrustumPoints[22].y;
      v62 = LODWORD(matFlashlightToWorld.m[3][0]);
      *(_DWORD *)(flashlightInfo + 560) = v61;
      v63 = LODWORD(matFlashlightToWorld.m[3][1]);
      *(_DWORD *)(flashlightInfo + 564) = v62;
      *(_DWORD *)(flashlightInfo + 568) = v63;
    }
  }
  else
  {
    v59 = pRenderContext;
  }
  if ( r_flashlightdrawclip.m_pParent == nullptr || r_flashlightdrawclip.m_pParent->m_Value.m_nValue == 0 )
    goto LABEL_43;
  m_pParent = r_flashlightclip.m_pParent;
  if ( r_flashlightclip.m_pParent == nullptr )
    return;
  if ( r_flashlightclip.m_pParent->m_Value.m_nValue != 0 && bUseStencil )
  {
    v65 = 0;
    if ( v45 > 0 )
    {
      v66 = (Vector *)dst;
      do
      {
        DrawDebugPolygon(
          nNumVerts: *(&state.m_nWriteMask + v65++),
          pVecPoints: v66,
          bFrontFacing: false,
          bNearPlane: false);
        v66 += 10;
      }
      while ( v65 < v45 );
      v59 = pRenderContext;
      v58 = (CShadowMgr::FlashlightInfo_t *)flashlightInfo;
LABEL_43:
      m_pParent = r_flashlightclip.m_pParent;
    }
  }
  if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 && bUseStencil )
  {
    v67 = 336 * v58->m_Shadow;
    state.m_nTestMask = -1;
    state.m_nReferenceValue = -1;
    state.m_FailOp = SHADER_STENCILOP_SET_TO_REFERENCE;
    state.m_ZFailOp = SHADER_STENCILOP_SET_TO_REFERENCE;
    v68 = (unsigned __int8 *)(v67 + *(_DWORD *)(LODWORD(vForward.y) + 8) + 302);
    state.m_CompareFunc = 0;
    LOBYTE(v79) = 1;
    *(_DWORD *)&state.m_bEnable = 1;
    state.m_PassOp = SHADER_STENCILOP_DECREMENT_WRAP;
    state.m_CompareFunc = *v68;
    state.m_nReferenceValue = *v68;
    v69 = *v68;
    v70 = v59->__vftable;
    state.m_nTestMask = v69;
    v70->SetStencilState(this: v59, a2: (const ShaderStencilState_t *)&v79);
    v71 = 0;
    if ( v45 > 0 )
    {
      v72 = (Vector *)dst;
      do
      {
        DrawPolygonToStencil(
          pRenderContext,
          nNumVerts: *(&state.m_nWriteMask + v71++),
          pVecPoints: v72,
          bFrontFacing: true,
          bNearPlane: false);
        v72 += 10;
      }
      while ( v71 < v45 );
      v59 = pRenderContext;
    }
    SetStencilState = v59->SetStencilState;
    stateDisable.m_FailOp = SHADER_STENCILOP_KEEP;
    *(_DWORD *)&stateDisable.m_bEnable = 1;
    stateDisable.m_ZFailOp = SHADER_STENCILOP_KEEP;
    stateDisable.m_nTestMask = -1;
    stateDisable.m_nReferenceValue = -1;
    stateDisable.m_PassOp = SHADER_STENCILOP_DECREMENT_WRAP;
    stateDisable.m_CompareFunc = 0;
    LOBYTE(vWorldFrustumPoints[23].z) = 0;
    SetStencilState(this: v59, a2: (const ShaderStencilState_t *)&vWorldFrustumPoints[23].z);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010BDB0
// Name: private: void CShadowMgr::DisableStencilAndScissorMasking(class IMatRenderContext __near *,struct CShadowMgr::FlashlightInfo_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::DisableStencilAndScissorMasking(
        CShadowMgr *this,
        IMatRenderContext *pRenderContext,
        const CShadowMgr::FlashlightInfo_t *flashlightInfo,
        bool bDoMasking)
{
  ConVar *m_pParent; // eax
  void (__thiscall *SetStencilState)(IMatRenderContext *, const ShaderStencilState_t *); // edx
  ShaderStencilState_t state; // [esp+4h] [ebp-20h] BYREF

  m_pParent = r_flashlightclip.m_pParent;
  if ( r_flashlightclip.m_pParent != nullptr )
  {
    if ( r_flashlightclip.m_pParent->m_Value.m_nValue != 0 )
    {
      state.m_ZFailOp = SHADER_STENCILOP_KEEP;
      state.m_FailOp = SHADER_STENCILOP_KEEP;
      state.m_PassOp = SHADER_STENCILOP_KEEP;
      state.m_nWriteMask = -1;
      state.m_nTestMask = -1;
      SetStencilState = pRenderContext->SetStencilState;
      state.m_CompareFunc = SHADER_STENCILFUNC_ALWAYS;
      state.m_nReferenceValue = 0;
      state.m_bEnable = false;
      SetStencilState(this: pRenderContext, a2: &state);
      m_pParent = r_flashlightclip.m_pParent;
    }
    if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
      goto LABEL_11;
  }
  if ( r_flashlightscissor.m_pParent != nullptr && r_flashlightscissor.m_pParent->m_Value.m_nValue != 0 )
  {
LABEL_11:
    if ( bDoMasking
      && pRenderContext->GetRenderTarget(this: pRenderContext) == nullptr
      && r_flashlightscissor.m_pParent != nullptr
      && r_flashlightscissor.m_pParent->m_Value.m_nValue != 0
      && flashlightInfo->m_FlashlightState.m_bScissor )
    {
      pRenderContext->PopScissorRect(this: pRenderContext);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010BE70
// Name: private: void CShadowMgr::EnableStencilAndScissorMasking(class IMatRenderContext __near *,struct CShadowMgr::FlashlightInfo_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::EnableStencilAndScissorMasking(
        CShadowMgr *this,
        IMatRenderContext *pRenderContext,
        const CShadowMgr::FlashlightInfo_t *flashlightInfo,
        bool bDoMasking)
{
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *m_pMemory; // ecx
  int m_Shadow; // eax
  unsigned __int8 m_ucShadowStencilBit; // bl
  void (__thiscall *SetStencilState)(IMatRenderContext *, const ShaderStencilState_t *); // edx
  ShaderStencilState_t state; // [esp+4h] [ebp-20h] BYREF

  if ( (r_flashlightclip.m_pParent != nullptr && r_flashlightclip.m_pParent->m_Value.m_nValue != 0
     || r_flashlightscissor.m_pParent != nullptr && r_flashlightscissor.m_pParent->m_Value.m_nValue != 0)
    && bDoMasking
    && pRenderContext->GetRenderTarget(this: pRenderContext) == nullptr )
  {
    if ( r_flashlightclip.m_pParent != nullptr && r_flashlightclip.m_pParent->m_Value.m_nValue != 0 )
    {
      m_pMemory = this->m_Shadows.m_Memory.m_pMemory;
      m_Shadow = flashlightInfo->m_Shadow;
      if ( m_pMemory[m_Shadow].m_Element.m_pFlashlightDepthTexture != nullptr )
      {
        m_ucShadowStencilBit = m_pMemory[m_Shadow].m_Element.m_ucShadowStencilBit;
        ShaderStencilState_t::ShaderStencilState_t(this: &state);
        SetStencilState = pRenderContext->SetStencilState;
        state.m_bEnable = true;
        state.m_FailOp = SHADER_STENCILOP_KEEP;
        state.m_ZFailOp = SHADER_STENCILOP_KEEP;
        state.m_PassOp = SHADER_STENCILOP_KEEP;
        state.m_nReferenceValue = m_ucShadowStencilBit;
        state.m_nTestMask = m_ucShadowStencilBit;
        state.m_CompareFunc = SHADER_STENCILFUNC_EQUAL;
        state.m_nWriteMask = 0;
        SetStencilState(this: pRenderContext, a2: &state);
      }
    }
    if ( r_flashlightscissor.m_pParent != nullptr
      && r_flashlightscissor.m_pParent->m_Value.m_nValue != 0
      && flashlightInfo->m_FlashlightState.m_bScissor )
    {
      pRenderContext->PushScissorRect(
        this: pRenderContext,
        a2: flashlightInfo->m_FlashlightState.m_nLeft,
        a3: flashlightInfo->m_FlashlightState.m_nTop,
        a4: flashlightInfo->m_FlashlightState.m_nRight,
        a5: flashlightInfo->m_FlashlightState.m_nBottom);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010BF80
// Name: public: virtual class Frustum_t const __near & CShadowMgr::GetFlashlightFrustum(unsigned short)
// Source: json
//------------------------------------------------------------------------------
UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *__thiscall CShadowMgr::GetFlashlightFrustum(
        CShadowMgr *this,
        unsigned __int16 handle)
{
  return &this->m_FlashlightStates.m_Memory.m_pMemory[this->m_Shadows.m_Memory.m_pMemory[handle].m_Element.m_FlashlightHandle];
}

//------------------------------------------------------------------------------
// Address: 0x1010BFB0
// Name: public: virtual struct FlashlightState_t const __near & CShadowMgr::GetFlashlightState(unsigned short)
// Source: json
//------------------------------------------------------------------------------
const FlashlightState_t *__thiscall CShadowMgr::GetFlashlightState(CShadowMgr *this, unsigned __int16 handle)
{
  return &this->m_FlashlightStates.m_Memory.m_pMemory[this->m_Shadows.m_Memory.m_pMemory[handle].m_Element.m_FlashlightHandle].m_Element.m_FlashlightState;
}

//------------------------------------------------------------------------------
// Address: 0x1010D510
// Name: private: virtual void CShadowMgr::SetFlashlightStencilMasks(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::SetFlashlightStencilMasks(CShadowMgr *this, bool bDoMasking)
{
  unsigned __int16 m_Head; // si
  IMatRenderContext *v4; // eax
  IMatRenderContext *v5; // ebx
  int v6; // esi
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *v7; // eax

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CShadowMgr::SetFlashlightStencilMasks",
    a3: 0,
    a4: "Shadow_Rendering",
    a5: false,
    a6: 4);
  if ( !this->m_bSinglePassFlashlightStateEnabled
    && (r_flashlightclip.m_pParent != nullptr && r_flashlightclip.m_pParent->m_Value.m_nValue != 0
     || r_flashlightscissor.m_pParent != nullptr && r_flashlightscissor.m_pParent->m_Value.m_nValue != 0) )
  {
    m_Head = this->m_FlashlightStates.m_Head;
    if ( m_Head != 0xFFFF )
    {
      v4 = materials->GetRenderContext(this: materials);
      v5 = v4;
      if ( v4 != nullptr )
        v4->BeginRender(this: v4);
      do
      {
        v6 = m_Head;
        v7 = &this->m_FlashlightStates.m_Memory.m_pMemory[v6];
        if ( v7->m_Element.m_nSplitscreenOwner == 0 )
          CShadowMgr::SetStencilAndScissor(
            this,
            pRenderContext: v5,
            flashlightInfo: &v7->m_Element,
            bUseStencil: this->m_Shadows.m_Memory.m_pMemory[v7->m_Element.m_Shadow].m_Element.m_pFlashlightDepthTexture != nullptr);
        m_Head = this->m_FlashlightStates.m_Memory.m_pMemory[v6].m_Next;
      }
      while ( m_Head != 0xFFFF );
      if ( v5 != nullptr )
      {
        v5->EndRender(this: v5);
        v5->Release(this: v5);
      }
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x1010D640
// Name: public: virtual void CShadowMgr::PopFlashlightScissorBounds(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::PopFlashlightScissorBounds(CShadowMgr *this)
{
  int v2; // ebx
  unsigned __int16 m_Head; // ax
  CShadowMgr::FlashLightScissorStateBackup_t *m_pMemory; // ecx
  int p_m_nTop; // edi
  int v6; // edx
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *v7; // eax

  v2 = this->m_ScissorStateEntryStart.m_Memory.m_pMemory[--this->m_ScissorStateEntryStart.m_Size];
  if ( v2 != this->m_ScissorStateBackups.m_Size )
  {
    m_Head = this->m_FlashlightStates.m_Head;
    m_pMemory = this->m_ScissorStateBackups.m_Memory.m_pMemory;
    if ( m_Head != 0xFFFF )
    {
      p_m_nTop = (int)&m_pMemory[v2].m_nTop;
      do
      {
        v6 = m_Head;
        v7 = &this->m_FlashlightStates.m_Memory.m_pMemory[v6];
        if ( v7->m_Element.m_nSplitscreenOwner == 0 )
        {
          v7->m_Element.m_FlashlightState.m_bScissor = *(_BYTE *)(p_m_nTop + 12);
          v7->m_Element.m_FlashlightState.m_nLeft = *(_DWORD *)(p_m_nTop - 4);
          v7->m_Element.m_FlashlightState.m_nTop = *(_DWORD *)p_m_nTop;
          v7->m_Element.m_FlashlightState.m_nRight = *(_DWORD *)(p_m_nTop + 4);
          v7->m_Element.m_FlashlightState.m_nBottom = *(_DWORD *)(p_m_nTop + 8);
          p_m_nTop += 20;
        }
        m_Head = this->m_FlashlightStates.m_Memory.m_pMemory[v6].m_Next;
      }
      while ( m_Head != 0xFFFF );
    }
    this->m_ScissorStateBackups.m_Size -= this->m_ScissorStateBackups.m_Size - v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010D710
// Name: public: virtual void CShadowMgr::SetFlashlightRenderState(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::SetFlashlightRenderState(CShadowMgr *this, unsigned __int16 handle)
{
  IMatRenderContext *v3; // esi
  IMatRenderContext_vtbl *v4; // edx
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v5; // edi

  v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  v4 = v3->__vftable;
  if ( handle == 0xFFFF )
  {
    v4->SetFlashlightMode(this: v3, a2: false);
  }
  else
  {
    v5 = &this->m_Shadows.m_Memory.m_pMemory[handle];
    v4->SetFlashlightMode(this: v3, a2: true);
    v3->SetFlashlightStateEx(
      this: v3,
      a2: &this->m_FlashlightStates.m_Memory.m_pMemory[v5->m_Element.m_FlashlightHandle].m_Element.m_FlashlightState,
      a3: &v5->m_Element.m_WorldToShadow,
      a4: v5->m_Element.m_pFlashlightDepthTexture);
  }
  v3->EndRender(this: v3);
  v3->Release(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1010D7D0
// Name: public: virtual void CShadowMgr::DrawVolumetrics(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::DrawVolumetrics(CShadowMgr *this)
{
  unsigned __int16 m_Head; // si
  IMatRenderContext *v3; // eax
  IMatRenderContext *v4; // ebx
  int v5; // edi
  bool v6; // zf
  IMaterial *v7; // esi
  int v8; // eax
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *m_pMemory; // edx
  ITexture *m_pFlashlightDepthTexture; // eax
  IMaterialVar_vtbl *v11; // ebx
  ITexture *v12; // eax
  VPlane *p_pPlanesOut; // esi
  IMatRenderContext_vtbl *v14; // edx
  float v15; // xmm0_4
  float v16; // xmm2_4
  IMesh *(__thiscall *GetDynamicMesh)(IMatRenderContext *, bool, IMesh *, IMesh *, IMaterial *); // eax
  IMesh *v18; // esi
  int v19; // edx
  int v20; // edi
  IMesh_vtbl *v21; // eax
  int *v22; // esi
  int v23; // ecx
  float *m_pCurrPosition; // eax
  float v25; // xmm6_4
  float v26; // xmm1_4
  float v27; // xmm3_4
  float v28; // xmm0_4
  int v29; // eax
  float *v30; // eax
  float v31; // xmm3_4
  float v32; // xmm0_4
  int v33; // eax
  float *v34; // eax
  float v35; // xmm3_4
  float v36; // xmm0_4
  int v37; // eax
  float v38; // xmm1_4
  float *v39; // eax
  float v40; // xmm3_4
  float v41; // xmm0_4
  int m_nVertexCount; // edx
  int v43; // eax
  int v44; // eax
  void (__thiscall *PopMatrix)(IMatRenderContext *); // edx
  int j; // esi
  VPlane pPlanesOut; // [esp+1Ch] [ebp-3C8h] BYREF
  VMatrix volumeToWorld; // [esp+7Ch] [ebp-368h] BYREF
  VMatrix dst; // [esp+BCh] [ebp-328h] BYREF
  VMatrix src; // [esp+FCh] [ebp-2E8h] BYREF
  CMeshBuilder v51; // [esp+13Ch] [ebp-2A8h] BYREF
  float v52; // [esp+324h] [ebp-C0h]
  int v53; // [esp+328h] [ebp-BCh]
  Vector v54; // [esp+32Ch] [ebp-B8h] BYREF
  IMatRenderContext *v55; // [esp+338h] [ebp-ACh]
  int v56; // [esp+33Ch] [ebp-A8h]
  int v57; // [esp+340h] [ebp-A4h]
  int v58; // [esp+344h] [ebp-A0h]
  int v59; // [esp+348h] [ebp-9Ch]
  int v60; // [esp+34Ch] [ebp-98h]
  int v61; // [esp+350h] [ebp-94h]
  int v62; // [esp+354h] [ebp-90h]
  int v63; // [esp+358h] [ebp-8Ch]
  int v64; // [esp+35Ch] [ebp-88h]
  int v65; // [esp+360h] [ebp-84h]
  int v66; // [esp+364h] [ebp-80h]
  int v67; // [esp+368h] [ebp-7Ch]
  int v68; // [esp+36Ch] [ebp-78h]
  int v69; // [esp+370h] [ebp-74h]
  int v70; // [esp+374h] [ebp-70h]
  int v71; // [esp+378h] [ebp-6Ch]
  int v72; // [esp+37Ch] [ebp-68h]
  VMatrix v73; // [esp+380h] [ebp-64h] BYREF
  Vector v74; // [esp+3C0h] [ebp-24h] BYREF
  IMaterialVar *v75; // [esp+3CCh] [ebp-18h]
  int v76; // [esp+3D0h] [ebp-14h]
  int v77; // [esp+3D4h] [ebp-10h]
  CShadowMgr *v78; // [esp+3D8h] [ebp-Ch]
  int i; // [esp+3DCh] [ebp-8h]
  _BYTE _3E3[5]; // [esp+3E3h] [ebp-1h] BYREF

  v78 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CShadowMgr::DrawVolumetrics",
    a3: 0,
    a4: "Shadow_Rendering",
    a5: false,
    a6: 4);
  m_Head = this->m_FlashlightStates.m_Head;
  if ( m_Head != 0xFFFF )
  {
    v3 = materials->GetRenderContext(this: materials);
    v4 = v3;
    v55 = v3;
    if ( v3 != nullptr )
      v3->BeginRender(this: v3);
    do
    {
      v5 = (int)&v78->m_FlashlightStates.m_Memory.m_pMemory[m_Head];
      v6 = *(_DWORD *)(v5 + 736) == 0;
      v53 = 768 * m_Head;
      if ( v6 && *(_BYTE *)(v5 + 528) != 0 && *(float *)(v5 + 548) > 0.0 )
      {
        v7 = materials->FindMaterial(this: materials, a2: "engine/lightshaft", a3: "Other textures", a4: 1, a5: 0);
        v71 = (int)v7->FindVar(this: v7, a2: "$COOKIETEXTURE", a3: _3E3, a4: false);
        v75 = v7->FindVar(this: v7, a2: "$NOISETEXTURE", a3: _3E3, a4: false);
        v69 = (int)v7->FindVar(this: v7, a2: "$COOKIEFRAMENUM", a3: _3E3, a4: false);
        v63 = (int)v7->FindVar(this: v7, a2: "$SHADOWDEPTHTEXTURE", a3: _3E3, a4: false);
        v76 = (int)v7->FindVar(this: v7, a2: "$WORLDTOTEXTURE", a3: _3E3, a4: false);
        v56 = (int)v7->FindVar(this: v7, a2: "$FLASHLIGHTCOLOR", a3: _3E3, a4: false);
        v61 = (int)v7->FindVar(this: v7, a2: "$ATTENFACTORS", a3: _3E3, a4: false);
        v70 = (int)v7->FindVar(this: v7, a2: "$ORIGINFARZ", a3: _3E3, a4: false);
        v62 = (int)v7->FindVar(this: v7, a2: "$QUATORIENTATION", a3: _3E3, a4: false);
        v68 = (int)v7->FindVar(this: v7, a2: "$SHADOWFILTERSIZE", a3: _3E3, a4: false);
        v60 = (int)v7->FindVar(this: v7, a2: "$SHADOWATTEN", a3: _3E3, a4: false);
        v58 = (int)v7->FindVar(this: v7, a2: "$SHADOWJITTERSEED", a3: _3E3, a4: false);
        v65 = (int)v7->FindVar(this: v7, a2: "$UBERLIGHT", a3: _3E3, a4: false);
        v57 = (int)v7->FindVar(this: v7, a2: "$ENABLESHADOWS", a3: _3E3, a4: false);
        v72 = (int)v7->FindVar(this: v7, a2: "$UBERNEARFAR", a3: _3E3, a4: false);
        v59 = (int)v7->FindVar(this: v7, a2: "$UBERHEIGHTWIDTH", a3: _3E3, a4: false);
        v67 = (int)v7->FindVar(this: v7, a2: "$UBERROUNDNESS", a3: _3E3, a4: false);
        v66 = (int)v7->FindVar(this: v7, a2: "$NOISESTRENGTH", a3: _3E3, a4: false);
        v64 = (int)v7->FindVar(this: v7, a2: "$FLASHLIGHTTIME", a3: _3E3, a4: false);
        v77 = (int)v7->FindVar(this: v7, a2: "$NUMPLANES", a3: _3E3, a4: false);
        v8 = (int)v7->FindVar(this: v7, a2: "$VOLUMETRICINTENSITY", a3: _3E3, a4: false);
        m_pMemory = v78->m_Shadows.m_Memory.m_pMemory;
        i = v8;
        m_pFlashlightDepthTexture = m_pMemory[*(unsigned __int16 *)(v5 + 572)].m_Element.m_pFlashlightDepthTexture;
        if ( m_pFlashlightDepthTexture != nullptr && v63 != 0 )
          (*(void (__thiscall **)(int, ITexture *))(*(_DWORD *)v63 + 60))(a1: v63, a2: m_pFlashlightDepthTexture);
        if ( *(_DWORD *)(v5 + 420) != 0 && v71 != 0 )
          (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v71 + 60))(a1: v71, a2: *(_DWORD *)(v5 + 420));
        if ( v75 != nullptr )
        {
          v11 = v75->__vftable;
          v12 = materials->FindTexture(this: materials, a2: "effects/noise_rg", a3: "Other textures", a4: 1, a5: 0);
          v11->SetTextureValue(this: v75, a2: v12);
          v4 = v55;
        }
        if ( v69 != 0 )
          (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v69 + 20))(a1: v69, a2: *(_DWORD *)(v5 + 428));
        if ( v76 != 0 )
          (*(void (__thiscall **)(int, UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *))(*(_DWORD *)v76 + 80))(
            a1: v76,
            a2: &v78->m_Shadows.m_Memory.m_pMemory[*(unsigned __int16 *)(v5 + 572)]);
        if ( v56 != 0 )
          (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v56 + 52))(a1: v56, a2: v5 + 400, a3: 4);
        if ( v61 != 0 )
          (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v61 + 40))(
            a1: *(float *)(v5 + 392),
            a2: *(float *)(v5 + 388),
            a3: *(float *)(v5 + 384),
            a4: *(float *)(v5 + 396));
        if ( v70 != 0 )
          (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v70 + 40))(
            a1: *(float *)(v5 + 320),
            a2: *(float *)(v5 + 324),
            a3: *(float *)(v5 + 328),
            a4: *(float *)(v5 + 352));
        if ( v62 != 0 )
          (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v62 + 52))(a1: v62, a2: v5 + 332, a3: 4);
        if ( v68 != 0 )
          (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v68 + 16))(a1: *(float *)(v5 + 440));
        if ( v60 != 0 )
          (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v60 + 16))(a1: *(float *)(v5 + 456));
        if ( v58 != 0 )
          (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v58 + 16))(a1: *(float *)(v5 + 452));
        if ( v65 != 0 )
          (*(void (__stdcall **)(bool))(*(_DWORD *)v65 + 20))(a1: *(_BYTE *)(v5 + 480) != 0);
        if ( v57 != 0 )
          (*(void (__stdcall **)(bool))(*(_DWORD *)v57 + 20))(a1: *(_BYTE *)(v5 + 432) != 0);
        if ( v72 != 0 )
          (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v72 + 40))(
            a1: *(float *)(v5 + 484),
            a2: *(float *)(v5 + 488),
            a3: *(float *)(v5 + 492),
            a4: *(float *)(v5 + 496));
        if ( v59 != 0 )
          (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v59 + 40))(
            a1: *(float *)(v5 + 508),
            a2: *(float *)(v5 + 512),
            a3: *(float *)(v5 + 516),
            a4: *(float *)(v5 + 520));
        if ( v67 != 0 )
          (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v67 + 16))(a1: *(float *)(v5 + 524));
        if ( v66 != 0 )
          (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v66 + 16))(a1: *(float *)(v5 + 532));
        if ( v64 != 0 )
          (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v64 + 16))(a1: *(float *)(v5 + 536));
        if ( v77 != 0 )
          (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v77 + 20))(a1: v77, a2: *(_DWORD *)(v5 + 540));
        if ( i != 0 )
          (*(void (__stdcall **)(_DWORD))(*(_DWORD *)i + 16))(a1: *(float *)(v5 + 548));
        v4->Bind(this: v4, a2: v7, a3: nullptr);
        Frustum_t::GetPlanes(this: (Frustum_t *)v5, &pPlanesOut);
        p_pPlanesOut = &pPlanesOut;
        for ( i = 6; i != 0; --i )
        {
          v4->PushCustomClipPlane(this: v4, a2: &p_pPlanesOut->m_Normal.x);
          ++p_pPlanesOut;
        }
        v4->GetMatrix_2(this: v4, a2: MATERIAL_VIEW, a3: &src);
        MatrixInverseGeneral(&src, dst: &v73);
        MatrixMultiply(
          src1: &v78->m_Shadows.m_Memory.m_pMemory[*(unsigned __int16 *)(v5 + 572)].m_Element.m_WorldToShadow,
          src2: &v73,
          &dst);
        MatrixInverseGeneral(src: &dst, dst: &volumeToWorld);
        CalculateAABBFromProjectionMatrixInverse(&volumeToWorld, pMins: &v74, pMaxs: &v54);
        v14 = v4->__vftable;
        v15 = (float)(v54.z - v74.z) / (float)*(int *)(v5 + 540);
        v16 = *(float *)(v5 + 544);
        v77 = v5 + 540;
        GetDynamicMesh = v14->GetDynamicMesh;
        v52 = v15;
        v74.z = (float)(v16 * v15) + v74.z;
        v18 = GetDynamicMesh(this: v4, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
        v4->MatrixMode(this: v4, a2: MATERIAL_MODEL);
        v4->PushMatrix(this: v4);
        v4->LoadIdentity(this: v4);
        CMeshBuilder::CMeshBuilder(this: &v51);
        v19 = 4 * *(_DWORD *)v77;
        v20 = 3 * *(_DWORD *)v77;
        v51.m_pMesh = v18;
        v51.m_bGenerateIndices = true;
        v51.m_Type = MATERIAL_QUADS;
        v21 = v18->IVertexBuffer::__vftable;
        i = v19;
        v20 *= 2;
        v21->SetPrimitiveType(this: v18, a2: MATERIAL_TRIANGLES);
        v51.m_pMesh->LockMesh(this: v51.m_pMesh, a2: i, a3: v20, a4: &v51, a5: nullptr);
        v51.m_IndexBuilder.m_pIndexBuffer = &v18->IIndexBuffer;
        v51.m_IndexBuilder.m_nMaxIndexCount = v20;
        v51.m_IndexBuilder.m_pIndices = v51.m_pIndices;
        v51.m_IndexBuilder.m_nIndexSize = v51.m_nIndexSize;
        v51.m_VertexBuilder.m_pVertexBuffer = v18;
        v51.m_IndexBuilder.m_nIndexOffset = v51.m_nFirstVertex;
        v51.m_IndexBuilder.m_nIndexCount = 0;
        v51.m_IndexBuilder.m_bModify = false;
        v51.m_VertexBuilder.VertexDesc_t = v51.VertexDesc_t;
        v51.m_VertexBuilder.m_nMaxVertexCount = i;
        v51.m_VertexBuilder.m_NumBoneWeights = v51.m_NumBoneWeights != 0 ? 2 : 0;
        v51.m_VertexBuilder.m_nVertexCount = 0;
        v51.m_VertexBuilder.m_bModify = false;
        if ( v51.m_VertexBuilder.m_nBufferOffset == -1 )
        {
          v51.m_VertexBuilder.m_nTotalVertexCount = 0;
          v51.m_VertexBuilder.m_nBufferOffset = v51.MeshDesc_t::VertexDesc_t::m_nOffset;
          v51.m_VertexBuilder.m_nBufferFirstVertex = v51.m_nFirstVertex;
        }
        v51.m_IndexBuilder.m_nCurrentIndex = 0;
        CVertexBuilder::Reset(this: &v51.m_VertexBuilder);
        v22 = (int *)v77;
        v23 = 0;
        if ( *(int *)v77 <= 0 )
        {
          m_nVertexCount = v51.m_VertexBuilder.m_nVertexCount;
        }
        else
        {
          m_pCurrPosition = v51.m_VertexBuilder.m_pCurrPosition;
          v25 = v52;
          do
          {
            v26 = (float)v23 * v25;
            v27 = (float)((float)((float)(v74.x * v73.m[1][0]) + (float)(v74.y * v73.m[1][1]))
                        + (float)(v73.m[1][2] * (float)(v26 + v74.z)))
                + v73.m[1][3];
            v28 = (float)((float)((float)(v74.x * v73.m[2][0]) + (float)(v74.y * v73.m[2][1]))
                        + (float)(v73.m[2][2] * (float)(v26 + v74.z)))
                + v73.m[2][3];
            *m_pCurrPosition = (float)((float)((float)(v74.x * v73.m[0][0]) + (float)(v74.y * v73.m[0][1]))
                                     + (float)(v73.m[0][2] * (float)(v26 + v74.z)))
                             + v73.m[0][3];
            m_pCurrPosition[1] = v27;
            m_pCurrPosition[2] = v28;
            v29 = v51.m_VertexBuilder.m_nCurrentVertex + 1;
            v51.m_VertexBuilder.m_nCurrentVertex = v29;
            if ( v29 > v51.m_VertexBuilder.m_nVertexCount )
              v51.m_VertexBuilder.m_nVertexCount = v29;
            v30 = (float *)((char *)v51.m_VertexBuilder.m_pCurrPosition + v51.m_VertexBuilder.m_VertexSize_Position);
            v51.m_VertexBuilder.m_pCurrPosition = v30;
            v31 = (float)((float)((float)(v54.y * v73.m[1][1]) + (float)(v74.x * v73.m[1][0]))
                        + (float)(v73.m[1][2] * (float)(v26 + v74.z)))
                + v73.m[1][3];
            v32 = (float)((float)((float)(v54.y * v73.m[2][1]) + (float)(v74.x * v73.m[2][0]))
                        + (float)(v73.m[2][2] * (float)(v26 + v74.z)))
                + v73.m[2][3];
            *v30 = (float)((float)((float)(v54.y * v73.m[0][1]) + (float)(v74.x * v73.m[0][0]))
                         + (float)(v73.m[0][2] * (float)(v26 + v74.z)))
                 + v73.m[0][3];
            v30[1] = v31;
            v30[2] = v32;
            v33 = v51.m_VertexBuilder.m_nCurrentVertex + 1;
            v51.m_VertexBuilder.m_nCurrentVertex = v33;
            if ( v33 > v51.m_VertexBuilder.m_nVertexCount )
              v51.m_VertexBuilder.m_nVertexCount = v33;
            v34 = (float *)((char *)v51.m_VertexBuilder.m_pCurrPosition + v51.m_VertexBuilder.m_VertexSize_Position);
            v51.m_VertexBuilder.m_pCurrPosition = v34;
            v35 = (float)((float)((float)(v54.x * v73.m[1][0]) + (float)(v54.y * v73.m[1][1]))
                        + (float)(v73.m[1][2] * (float)(v26 + v74.z)))
                + v73.m[1][3];
            v36 = (float)((float)((float)(v54.x * v73.m[2][0]) + (float)(v54.y * v73.m[2][1]))
                        + (float)(v73.m[2][2] * (float)(v26 + v74.z)))
                + v73.m[2][3];
            *v34 = (float)((float)((float)(v54.x * v73.m[0][0]) + (float)(v54.y * v73.m[0][1]))
                         + (float)(v73.m[0][2] * (float)(v26 + v74.z)))
                 + v73.m[0][3];
            v34[1] = v35;
            v34[2] = v36;
            v37 = v51.m_VertexBuilder.m_nCurrentVertex + 1;
            v51.m_VertexBuilder.m_nCurrentVertex = v37;
            if ( v37 > v51.m_VertexBuilder.m_nVertexCount )
              v51.m_VertexBuilder.m_nVertexCount = v37;
            v38 = v26 + v74.z;
            v39 = (float *)((char *)v51.m_VertexBuilder.m_pCurrPosition + v51.m_VertexBuilder.m_VertexSize_Position);
            v51.m_VertexBuilder.m_pCurrPosition = v39;
            v40 = (float)((float)((float)(v54.x * v73.m[1][0]) + (float)(v74.y * v73.m[1][1]))
                        + (float)(v73.m[1][2] * v38))
                + v73.m[1][3];
            v41 = (float)((float)((float)(v54.x * v73.m[2][0]) + (float)(v74.y * v73.m[2][1]))
                        + (float)(v73.m[2][2] * v38))
                + v73.m[2][3];
            *v39 = (float)((float)((float)(v54.x * v73.m[0][0]) + (float)(v74.y * v73.m[0][1]))
                         + (float)(v73.m[0][2] * v38))
                 + v73.m[0][3];
            v39[1] = v40;
            v39[2] = v41;
            m_nVertexCount = v51.m_VertexBuilder.m_nVertexCount;
            v43 = v51.m_VertexBuilder.m_nCurrentVertex + 1;
            v51.m_VertexBuilder.m_nCurrentVertex = v43;
            if ( v43 > v51.m_VertexBuilder.m_nVertexCount )
            {
              m_nVertexCount = v43;
              v51.m_VertexBuilder.m_nVertexCount = v43;
            }
            m_pCurrPosition = (float *)((char *)v51.m_VertexBuilder.m_pCurrPosition
                                      + v51.m_VertexBuilder.m_VertexSize_Position);
            ++v23;
            v51.m_VertexBuilder.m_pCurrPosition = (float *)((char *)v51.m_VertexBuilder.m_pCurrPosition
                                                          + v51.m_VertexBuilder.m_VertexSize_Position);
          }
          while ( v23 < *v22 );
        }
        if ( v51.m_bGenerateIndices )
        {
          switch ( v51.m_Type )
          {
            case MATERIAL_LINE_STRIP:
              v44 = 2 * m_nVertexCount - 2;
              break;
            case MATERIAL_LINE_LOOP:
              v44 = 2 * m_nVertexCount;
              break;
            case MATERIAL_POLYGON:
              v44 = 3 * m_nVertexCount - 6;
              break;
            case MATERIAL_QUADS:
              v44 = 6 * m_nVertexCount / 4;
              break;
            case MATERIAL_INSTANCED_QUADS:
              v44 = 0;
              break;
            default:
              v44 = m_nVertexCount;
              break;
          }
          CIndexBuilder::GenerateIndices(this: &v51.m_IndexBuilder, primitiveType: v51.m_Type, nIndexCount: v44);
          m_nVertexCount = v51.m_VertexBuilder.m_nVertexCount;
        }
        v51.m_pMesh->UnlockMesh(this: v51.m_pMesh, a2: m_nVertexCount, a3: v51.m_IndexBuilder.m_nIndexCount, a4: &v51);
        v51.m_IndexBuilder.m_pIndexBuffer = nullptr;
        v51.m_IndexBuilder.m_nMaxIndexCount = 0;
        v51.m_VertexBuilder.m_nMaxVertexCount = 0;
        v51.m_VertexBuilder.m_pVertexBuffer = nullptr;
        v51.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
        v51.m_pMesh->Draw_2(this: v51.m_pMesh, a2: -1, a3: 0);
        PopMatrix = v4->PopMatrix;
        v51.m_pMesh = nullptr;
        PopMatrix(this: v4);
        for ( j = 6; j != 0; --j )
          v4->PopCustomClipPlane(this: v4);
        if ( v51.m_VertexBuilder.m_pVertexBuffer != nullptr
          && v51.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: v51.m_VertexBuilder.m_pVertexBuffer) )
        {
          v51.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: v51.m_VertexBuilder.m_pVertexBuffer);
        }
        if ( v51.m_IndexBuilder.m_pIndexBuffer != nullptr
          && v51.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: v51.m_IndexBuilder.m_pIndexBuffer) )
        {
          v51.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: v51.m_IndexBuilder.m_pIndexBuffer);
        }
      }
      m_Head = v78->m_FlashlightStates.m_Memory.m_pMemory[v53 / 0x300u].m_Next;
    }
    while ( m_Head != 0xFFFF );
    if ( v4 != nullptr )
    {
      v4->EndRender(this: v4);
      v4->Release(this: v4);
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x1010E4B0
// Name: public: virtual void CShadowMgr::DrawFlashlightDecals(class IMatRenderContext __near *,int,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CShadowMgr::DrawFlashlightDecals(
        CShadowMgr *this@<ecx>,
        int a2@<ebx>,
        IMatRenderContext *pRenderContext,
        int sortGroup,
        bool bDoMasking,
        float flFade)
{
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *m_pMemory; // edx
  int v10; // eax
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *v11; // esi
  int v12; // eax
  int v13; // ecx
  const CShadowMgr::FlashlightInfo_t *v14; // esi
  IMatRenderContext *v16; // [esp+14h] [ebp+8h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CShadowMgr::DrawFlashlightDecals",
    a3: 0,
    a4: "Shadow_Rendering",
    a5: false,
    a6: 4);
  if ( this->m_bSinglePassFlashlightStateEnabled || (m_Head = this->m_FlashlightStates.m_Head) == 0xFFFF )
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    ((void (__thiscall *)(IMatRenderContext *, int, int))pRenderContext->SetFlashlightMode)(
      a1: pRenderContext,
      a2: 1,
      a3: a2);
    do
    {
      m_pMemory = this->m_Shadows.m_Memory.m_pMemory;
      v10 = m_Head;
      v11 = this->m_FlashlightStates.m_Memory.m_pMemory;
      v12 = 768 * v10;
      v13 = *(unsigned __int16 *)((char *)&v11->m_Element.m_Shadow + v12);
      v14 = (CShadowMgr::FlashlightInfo_t *)((char *)&v11->m_Element + v12);
      v16 = (IMatRenderContext *)v12;
      if ( (m_pMemory[v13].m_Element.m_Flags & 4) == 0 && v14->m_nSplitscreenOwner == 0 )
      {
        pRenderContext->SetFlashlightStateEx(
          this: pRenderContext,
          a2: &v14->m_FlashlightState,
          a3: (const VMatrix *)&m_pMemory[v14->m_Shadow],
          a4: m_pMemory[v14->m_Shadow].m_Element.m_pFlashlightDepthTexture);
        CShadowMgr::EnableStencilAndScissorMasking(this, pRenderContext, flashlightInfo: v14, bDoMasking);
        DecalSurfaceDraw(pRenderContext, renderGroup: sortGroup, flFade);
        CShadowMgr::DisableStencilAndScissorMasking(this, pRenderContext, flashlightInfo: v14, bDoMasking);
        v12 = (int)v16;
      }
      m_Head = *(unsigned __int16 *)((char *)&this->m_FlashlightStates.m_Memory.m_pMemory->m_Next + v12);
    }
    while ( m_Head != 0xFFFF );
    pRenderContext->SetFlashlightMode(this: pRenderContext, a2: false);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010E5F0
// Name: public: virtual void CShadowMgr::FlashlightDrawCallback(void (*)(void __near *),void __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CShadowMgr::FlashlightDrawCallback(
        CShadowMgr *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        void (__cdecl *pCallback)(void *),
        void *pData)
{
  unsigned __int16 m_Head; // si
  int v7; // eax
  IMatRenderContext *v8; // edi
  int v9; // eax
  const CShadowMgr::FlashlightInfo_t *v10; // esi
  int v12; // [esp+4h] [ebp-4h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CShadowMgr::FlashlightDrawCallback",
    a3: 0,
    a4: "Shadow_Rendering",
    a5: false,
    a6: 4);
  if ( this->m_bSinglePassFlashlightStateEnabled || (m_Head = this->m_FlashlightStates.m_Head) == 0xFFFF )
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    v7 = ((int (__thiscall *)(IMaterialSystem *, int, int))materials->GetRenderContext)(a1: materials, a2, a3);
    v8 = (IMatRenderContext *)v7;
    if ( v7 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 8))(a1: v7);
    v8->SetFlashlightMode(this: v8, a2: true);
    do
    {
      v9 = 768 * m_Head;
      v10 = (CShadowMgr::FlashlightInfo_t *)((char *)&this->m_FlashlightStates.m_Memory.m_pMemory->m_Element + v9);
      v12 = v9;
      if ( v10->m_nSplitscreenOwner == 0 )
      {
        v8->SetFlashlightStateEx(
          this: v8,
          a2: &v10->m_FlashlightState,
          a3: &this->m_Shadows.m_Memory.m_pMemory[v10->m_Shadow].m_Element.m_WorldToShadow,
          a4: this->m_Shadows.m_Memory.m_pMemory[v10->m_Shadow].m_Element.m_pFlashlightDepthTexture);
        CShadowMgr::EnableStencilAndScissorMasking(this, pRenderContext: v8, flashlightInfo: v10, bDoMasking: false);
        pCallback(a1: pData);
        CShadowMgr::DisableStencilAndScissorMasking(this, pRenderContext: v8, flashlightInfo: v10, bDoMasking: false);
        v9 = v12;
      }
      m_Head = *(unsigned __int16 *)((char *)&this->m_FlashlightStates.m_Memory.m_pMemory->m_Next + v9);
    }
    while ( m_Head != 0xFFFF );
    v8->SetFlashlightMode(this: v8, a2: false);
    v8->EndRender(this: v8);
    v8->Release(this: v8);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010E740
// Name: public: virtual void CShadowMgr::PopSinglePassFlashlightStateEnabled(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::PopSinglePassFlashlightStateEnabled(CShadowMgr *this)
{
  bool v2; // bl
  IMatRenderContext *v3; // eax
  void (__thiscall *SetFlashlightRenderState)(struct CShadowMgr *, unsigned __int16); // edx
  IMatRenderContext *v5; // eax
  bool bEnable; // [esp+8h] [ebp-4h]

  --this->m_bStack_SinglePassFlashlightStateEnabled.m_Size;
  v2 = false;
  bEnable = false;
  if ( this->m_bStack_SinglePassFlashlightStateEnabled.m_Size != 0 )
  {
    v2 = this->m_bStack_SinglePassFlashlightStateEnabled.m_Memory.m_pMemory[this->m_bStack_SinglePassFlashlightStateEnabled.m_Size
                                                                          - 1];
    bEnable = v2;
  }
  if ( this->m_bSinglePassFlashlightStateEnabled != v2 )
  {
    v3 = materials->GetRenderContext(this: materials);
    v3->EnableSinglePassFlashlightMode(this: v3, a2: bEnable);
    SetFlashlightRenderState = this->SetFlashlightRenderState;
    if ( v2 )
      SetFlashlightRenderState(this, a2: this->m_hSinglePassFlashlightState);
    else
      SetFlashlightRenderState(this, a2: 0xFFFFu);
    this->m_bSinglePassFlashlightStateEnabled = v2;
  }
  if ( this->m_bSinglePassFlashlightStateEnabled )
  {
    v5 = materials->GetRenderContext(this: materials);
    v5->EnableCullingForSinglePassFlashlight(this: v5, a2: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010E7F0
// Name: public: virtual void CShadowMgr::DrawFlashlightDecalsOnDisplacements(class IMatRenderContext __near *,int,class CDispInfo __near * __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CShadowMgr::DrawFlashlightDecalsOnDisplacements(
        CShadowMgr *this@<ecx>,
        int a2@<edi>,
        IMatRenderContext *pRenderContext,
        int sortGroup,
        CDispInfo **visibleDisps,
        int nVisibleDisps,
        bool bDoMasking)
{
  unsigned __int16 m_Head; // si
  int v10; // eax
  const CShadowMgr::FlashlightInfo_t *v11; // esi
  IMatRenderContext *pRenderContexta; // [esp+Ch] [ebp+8h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CShadowMgr::DrawFlashlightDecalsOnDisplacements",
    a3: 0,
    a4: "Shadow_Rendering",
    a5: false,
    a6: 4);
  if ( this->m_bSinglePassFlashlightStateEnabled || (m_Head = this->m_FlashlightStates.m_Head) == 0xFFFF )
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    ((void (__thiscall *)(IMatRenderContext *, int, int))pRenderContext->SetFlashlightMode)(
      a1: pRenderContext,
      a2: 1,
      a3: a2);
    DispInfo_BatchDecals(pVisibleDisps: visibleDisps, nVisibleDisps);
    do
    {
      v10 = 768 * m_Head;
      v11 = (CShadowMgr::FlashlightInfo_t *)((char *)&this->m_FlashlightStates.m_Memory.m_pMemory->m_Element + v10);
      pRenderContexta = (IMatRenderContext *)v10;
      if ( v11->m_nSplitscreenOwner == 0 )
      {
        pRenderContext->SetFlashlightStateEx(
          this: pRenderContext,
          a2: &v11->m_FlashlightState,
          a3: (const VMatrix *)&this->m_Shadows.m_Memory.m_pMemory[v11->m_Shadow],
          a4: this->m_Shadows.m_Memory.m_pMemory[v11->m_Shadow].m_Element.m_pFlashlightDepthTexture);
        CShadowMgr::EnableStencilAndScissorMasking(this, pRenderContext, flashlightInfo: v11, bDoMasking);
        DispInfo_DrawDecals(pRenderContext, visibleDisps, nVisibleDisps);
        CShadowMgr::DisableStencilAndScissorMasking(this, pRenderContext, flashlightInfo: v11, bDoMasking);
        v10 = (int)pRenderContexta;
      }
      m_Head = *(unsigned __int16 *)((char *)&this->m_FlashlightStates.m_Memory.m_pMemory->m_Next + v10);
    }
    while ( m_Head != 0xFFFF );
    pRenderContext->SetFlashlightMode(this: pRenderContext, a2: false);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010E930
// Name: public: virtual void CShadowMgr::DrawFlashlightDecalsOnSurfaceList(class IMatRenderContext __near *,struct msurface2_t __near * __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CShadowMgr::DrawFlashlightDecalsOnSurfaceList(
        CShadowMgr *this@<ecx>,
        int a2@<ebx>,
        IMatRenderContext *pRenderContext,
        msurface2_t **pList,
        int listCount,
        bool bDoMasking)
{
  CShadowMgr *v6; // edi
  unsigned __int16 m_Head; // si
  int v9; // eax
  const CShadowMgr::FlashlightInfo_t *v10; // esi
  int i; // edi
  msurface2_t *v12; // eax
  IMatRenderContext *pRenderContexta; // [esp+10h] [ebp+8h]

  v6 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CShadowMgr::DrawFlashlightDecalsOnSurfaceList",
    a3: 0,
    a4: "Shadow_Rendering",
    a5: false,
    a6: 4);
  if ( v6->m_bSinglePassFlashlightStateEnabled || (m_Head = v6->m_FlashlightStates.m_Head) == 0xFFFF )
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    ((void (__thiscall *)(IMatRenderContext *, int, int))pRenderContext->SetFlashlightMode)(
      a1: pRenderContext,
      a2: 1,
      a3: a2);
    do
    {
      v9 = 768 * m_Head;
      v10 = (CShadowMgr::FlashlightInfo_t *)((char *)&v6->m_FlashlightStates.m_Memory.m_pMemory->m_Element + v9);
      pRenderContexta = (IMatRenderContext *)v9;
      if ( v10->m_nSplitscreenOwner == 0 )
      {
        pRenderContext->SetFlashlightStateEx(
          this: pRenderContext,
          a2: &v10->m_FlashlightState,
          a3: (const VMatrix *)&v6->m_Shadows.m_Memory.m_pMemory[v10->m_Shadow],
          a4: v6->m_Shadows.m_Memory.m_pMemory[v10->m_Shadow].m_Element.m_pFlashlightDepthTexture);
        CShadowMgr::EnableStencilAndScissorMasking(this: v6, pRenderContext, flashlightInfo: v10, bDoMasking);
        for ( i = 0; i < listCount; ++i )
        {
          v12 = pList[i];
          if ( v12->decals != 0xFFFF )
            DrawDecalsOnSingleSurface(pRenderContext, surfID: v12);
        }
        CShadowMgr::DisableStencilAndScissorMasking(this, pRenderContext, flashlightInfo: v10, bDoMasking);
        v6 = this;
        v9 = (int)pRenderContexta;
      }
      m_Head = *(unsigned __int16 *)((char *)&v6->m_FlashlightStates.m_Memory.m_pMemory->m_Next + v9);
    }
    while ( m_Head != 0xFFFF );
    pRenderContext->SetFlashlightMode(this: pRenderContext, a2: false);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010EA90
// Name: public: virtual void CShadowMgr::DrawFlashlightOverlays(class IMatRenderContext __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CShadowMgr::DrawFlashlightOverlays(
        CShadowMgr *this@<ecx>,
        int a2@<edi>,
        IMatRenderContext *pRenderContext,
        int nSortGroup,
        bool bDoMasking)
{
  unsigned __int16 m_Head; // si
  int v8; // eax
  const CShadowMgr::FlashlightInfo_t *v9; // esi
  IOverlayMgr *v10; // eax
  IMatRenderContext *pRenderContexta; // [esp+Ch] [ebp+8h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CShadowMgr::DrawFlashlightOverlays",
    a3: 0,
    a4: "Shadow_Rendering",
    a5: false,
    a6: 4);
  if ( !this->m_bSinglePassFlashlightStateEnabled
    && (m_Head = this->m_FlashlightStates.m_Head) != 0xFFFF
    && r_flashlightrender.m_pParent != nullptr
    && r_flashlightrender.m_pParent->m_Value.m_nValue != 0 )
  {
    ((void (__thiscall *)(IMatRenderContext *, int, int))pRenderContext->SetFlashlightMode)(
      a1: pRenderContext,
      a2: 1,
      a3: a2);
    do
    {
      v8 = 768 * m_Head;
      v9 = (CShadowMgr::FlashlightInfo_t *)((char *)&this->m_FlashlightStates.m_Memory.m_pMemory->m_Element + v8);
      pRenderContexta = (IMatRenderContext *)v8;
      if ( v9->m_nSplitscreenOwner == 0 )
      {
        pRenderContext->SetFlashlightStateEx(
          this: pRenderContext,
          a2: &v9->m_FlashlightState,
          a3: (const VMatrix *)&this->m_Shadows.m_Memory.m_pMemory[v9->m_Shadow],
          a4: this->m_Shadows.m_Memory.m_pMemory[v9->m_Shadow].m_Element.m_pFlashlightDepthTexture);
        CShadowMgr::EnableStencilAndScissorMasking(this, pRenderContext, flashlightInfo: v9, bDoMasking);
        v10 = OverlayMgr();
        v10->RenderOverlays(this: v10, a2: pRenderContext, a3: nSortGroup);
        CShadowMgr::DisableStencilAndScissorMasking(this, pRenderContext, flashlightInfo: v9, bDoMasking);
        v8 = (int)pRenderContexta;
      }
      m_Head = *(unsigned __int16 *)((char *)&this->m_FlashlightStates.m_Memory.m_pMemory->m_Next + v8);
    }
    while ( m_Head != 0xFFFF );
    pRenderContext->SetFlashlightMode(this: pRenderContext, a2: false);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010EBD0
// Name: public: virtual void CShadowMgr::DrawFlashlightDepthTexture(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CShadowMgr::DrawFlashlightDepthTexture(
        CShadowMgr *this@<ecx>,
        CMeshBuilder *p_meshBuilder@<ebx>,
        int a3@<edi>,
        int m_nIndexCount@<esi>)
{
  unsigned __int16 m_Head; // ax
  int v5; // eax
  char *v6; // esi
  bool v7; // zf
  IMaterial *v8; // edi
  int v9; // ebx
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *m_pMemory; // ecx
  void (__thiscall *v11)(int, ITexture *, int, int, CMeshBuilder *); // edx
  IMatRenderContext *v12; // esi
  IMesh *v13; // edi
  float *m_pCurrPosition; // eax
  float v15; // xmm5_4
  float v16; // xmm2_4
  float *v17; // eax
  int v18; // eax
  float *v19; // eax
  float v20; // xmm4_4
  float v21; // xmm1_4
  float *v22; // eax
  int v23; // eax
  float *v24; // eax
  float v25; // xmm2_4
  float *v26; // eax
  int v27; // eax
  float *v28; // eax
  float *v29; // eax
  int m_nVertexCount; // eax
  int v31; // ecx
  ITexture *m_pFlashlightDepthTexture; // [esp-10h] [ebp-218h]
  CMeshBuilder meshBuilder; // [esp+0h] [ebp-208h] BYREF
  float hOffset; // [esp+1E8h] [ebp-20h]
  int v38; // [esp+1ECh] [ebp-1Ch]
  IMaterialVar *FrameVar; // [esp+1F0h] [ebp-18h]
  float h; // [esp+1F4h] [ebp-14h]
  float wOffset; // [esp+1F8h] [ebp-10h]
  CShadowMgr *v42; // [esp+1FCh] [ebp-Ch]
  int i; // [esp+200h] [ebp-8h]
  bool foundVar; // [esp+207h] [ebp-1h] BYREF

  m_Head = this->m_FlashlightStates.m_Head;
  v42 = this;
  for ( i = 0;
        m_Head != 0xFFFF;
        m_Head = *(unsigned __int16 *)((char *)&this->m_FlashlightStates.m_Memory.m_pMemory->m_Next + v5) )
  {
    v5 = 768 * m_Head;
    v6 = (char *)this->m_FlashlightStates.m_Memory.m_pMemory + v5;
    v7 = *((_DWORD *)v6 + 184) == 0;
    v38 = v5;
    if ( v7
      && this->m_Shadows.m_Memory.m_pMemory[*((unsigned __int16 *)v6 + 286)].m_Element.m_pFlashlightDepthTexture != nullptr )
    {
      v8 = materials->FindMaterial(this: materials, a2: "debug/showz", a3: "Other textures", a4: 1, a5: 0);
      v9 = (int)v8->FindVar(this: v8, a2: "$basetexture", a3: &foundVar, a4: false);
      if ( !foundVar )
        return;
      FrameVar = v8->FindVar(this: v8, a2: "$frame", a3: &foundVar, a4: false);
      if ( !foundVar )
        return;
      h = r_flashlightdrawdepthres.m_pParent->m_Value.m_fValue;
      m_pMemory = v42->m_Shadows.m_Memory.m_pMemory;
      v11 = *(void (__thiscall **)(int, ITexture *, int, int, CMeshBuilder *))(*(_DWORD *)v9 + 60);
      wOffset = (float)(i % 2) * 256.0;
      m_pFlashlightDepthTexture = m_pMemory[*((unsigned __int16 *)v6 + 286)].m_Element.m_pFlashlightDepthTexture;
      hOffset = (float)(i / 2) * 256.0;
      v11(a1: v9, a2: m_pFlashlightDepthTexture, a3, a4: m_nIndexCount, a5: p_meshBuilder);
      FrameVar->SetIntValue(this: FrameVar, a2: 0);
      v12 = materials->GetRenderContext(this: materials);
      if ( v12 != nullptr )
        v12->BeginRender(this: v12);
      v12->Bind(this: v12, a2: v8, a3: nullptr);
      v13 = v12->GetDynamicMesh(this: v12, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
      CMeshBuilder::CMeshBuilder(this: &meshBuilder);
      meshBuilder.m_pMesh = v13;
      meshBuilder.m_bGenerateIndices = true;
      meshBuilder.m_Type = MATERIAL_QUADS;
      v13->SetPrimitiveType(this: v13, a2: MATERIAL_TRIANGLES);
      meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
      meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v13->IIndexBuffer;
      meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
      meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
      meshBuilder.m_IndexBuilder.m_bModify = false;
      meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      CVertexBuilder::AttachBegin(
        this: &meshBuilder.m_VertexBuilder,
        pMesh: v13,
        nMaxVertexCount: 4,
        desc: &meshBuilder);
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
      m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      v15 = wOffset;
      v16 = hOffset;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = wOffset;
      m_pCurrPosition[1] = v16;
      m_pCurrPosition[2] = 0.0;
      v17 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
      v17[1] = 0.0;
      v18 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
      meshBuilder.m_VertexBuilder.m_nCurrentVertex = v18;
      if ( v18 > meshBuilder.m_VertexBuilder.m_nVertexCount )
        meshBuilder.m_VertexBuilder.m_nVertexCount = v18;
      v19 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                    + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
      meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                               + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
      v20 = h;
      meshBuilder.m_VertexBuilder.m_pCurrPosition = v19;
      v21 = v15 + h;
      *v19 = v15 + h;
      v19[1] = v16;
      v19[2] = 0.0;
      v22 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
      v22[1] = 0.0;
      v23 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
      meshBuilder.m_VertexBuilder.m_nCurrentVertex = v23;
      if ( v23 > meshBuilder.m_VertexBuilder.m_nVertexCount )
        meshBuilder.m_VertexBuilder.m_nVertexCount = v23;
      v24 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                    + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
      meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                               + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
      meshBuilder.m_VertexBuilder.m_pCurrPosition = v24;
      *v24 = v21;
      v25 = v16 + v20;
      v24[1] = v25;
      v24[2] = 0.0;
      v26 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
      v26[1] = 1.0;
      v27 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
      meshBuilder.m_VertexBuilder.m_nCurrentVertex = v27;
      if ( v27 > meshBuilder.m_VertexBuilder.m_nVertexCount )
        meshBuilder.m_VertexBuilder.m_nVertexCount = v27;
      v28 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                    + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
      meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                               + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
      meshBuilder.m_VertexBuilder.m_pCurrPosition = v28;
      *v28 = v15;
      v28[1] = v25;
      v28[2] = 0.0;
      v29 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
      v29[1] = 1.0;
      m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
      v31 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
      meshBuilder.m_VertexBuilder.m_nCurrentVertex = v31;
      if ( v31 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      {
        m_nVertexCount = v31;
        meshBuilder.m_VertexBuilder.m_nVertexCount = v31;
      }
      meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                            + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
      meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                               + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
      if ( meshBuilder.m_bGenerateIndices )
      {
        switch ( meshBuilder.m_Type )
        {
          case MATERIAL_LINE_STRIP:
            m_nVertexCount = 2 * m_nVertexCount - 2;
            break;
          case MATERIAL_LINE_LOOP:
            m_nVertexCount *= 2;
            break;
          case MATERIAL_POLYGON:
            m_nVertexCount = 3 * m_nVertexCount - 6;
            break;
          case MATERIAL_QUADS:
            m_nVertexCount = 6 * m_nVertexCount / 4;
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
      a3 = m_nVertexCount;
      ((void (__thiscall *)(IMesh *))meshBuilder.m_pMesh->UnlockMesh)(a1: meshBuilder.m_pMesh);
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
      meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
      meshBuilder.m_pMesh = nullptr;
      v13->Draw_2(this: v13, a2: -1, a3: 0);
      ++i;
      CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
      v12->EndRender(this: v12);
      v12->Release(this: v12);
      v5 = v38;
      this = v42;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F0F0
// Name: public: CUtlMemoryAligned<struct UtlLinkedListElem_t<struct CShadowMgr::Shadow_t,unsigned short>,16>::~CUtlMemoryAligned<struct UtlLinkedListElem_t<struct CShadowMgr::Shadow_t,unsigned short>,16>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>::~CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>(
        CUtlMemoryAligned<Frustum_t,16> *this)
{
  bool v2; // sf

  if ( this->m_nGrowSize >= 0 )
  {
    if ( this->m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((int)this->m_pMemory & 0xFFFFFFFC) - 4));
      this->m_pMemory = nullptr;
    }
    v2 = this->m_nGrowSize < 0;
    this->m_nAllocationCount = 0;
    if ( !v2 )
    {
      if ( this->m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pMemory);
        this->m_pMemory = nullptr;
      }
      this->m_nAllocationCount = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F770
// Name: public: virtual int CShadowMgr::GetNumShadowsOnModel(unsigned short)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShadowMgr::GetNumShadowsOnModel(CShadowMgr *this, int instance)
{
  int m_Next; // ecx
  int result; // eax

  if ( (_WORD)instance == 0xFFFF
    || r_shadows.m_pParent == nullptr
    || r_shadows.m_pParent->m_Value.m_nValue == 0
    || this->m_bShadowsDisabled )
  {
    return 0;
  }
  m_Next = *this->m_ShadowsOnModels.m_FirstElement(a1: instance);
  for ( result = 0; m_Next != 0xFFFF; ++result )
    m_Next = this->m_ShadowsOnModels.m_ElementsInBucket.m_Memory.m_pMemory[(unsigned __int16)m_Next].m_Next;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010F7E0
// Name: public: virtual int CShadowMgr::GetShadowsOnModel(unsigned short,unsigned short __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShadowMgr::GetShadowsOnModel(
        CShadowMgr *this,
        int instance,
        unsigned __int16 *pShadowArray,
        bool bNormalShadows,
        bool bFlashlightShadows)
{
  int m_Next; // ecx
  int v8; // ecx
  int nCount; // [esp+Ch] [ebp+8h]

  if ( (_WORD)instance == 0xFFFF
    || r_shadows.m_pParent == nullptr
    || r_shadows.m_pParent->m_Value.m_nValue == 0
    || this->m_bShadowsDisabled )
  {
    return 0;
  }
  m_Next = *this->m_ShadowsOnModels.m_FirstElement(a1: instance);
  nCount = 0;
  if ( m_Next != 0xFFFF )
  {
    while ( 1 )
    {
      v8 = (unsigned __int16)m_Next;
      if ( (this->m_Shadows.m_Memory.m_pMemory[this->m_ShadowsOnModels.m_ElementsInBucket.m_Memory.m_pMemory[v8].m_Element.m_Element].m_Element.m_Flags
          & 6) != 0 )
        break;
      if ( bNormalShadows )
        goto LABEL_10;
LABEL_11:
      m_Next = this->m_ShadowsOnModels.m_ElementsInBucket.m_Memory.m_pMemory[v8].m_Next;
      if ( m_Next == 0xFFFF )
        return nCount;
    }
    if ( !bFlashlightShadows )
      goto LABEL_11;
LABEL_10:
    *pShadowArray++ = this->m_ShadowsOnModels.m_ElementsInBucket.m_Memory.m_pMemory[v8].m_Element.m_Element;
    ++nCount;
    goto LABEL_11;
  }
  return nCount;
}

//------------------------------------------------------------------------------
// Address: 0x1010F8B0
// Name: public: virtual void CShadowMgr::SetModelShadowState(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::SetModelShadowState(CShadowMgr *this, int instance)
{
  int v3; // eax
  int i; // eax
  int v5; // edi
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v6; // eax
  __int16 v7; // cx
  bool instance_3; // [esp+Fh] [ebp+Bh]

  g_pStudioRender->ClearAllShadows(this: g_pStudioRender);
  if ( (_WORD)instance != 0xFFFF
    && r_shadows.m_pParent != nullptr
    && r_shadows.m_pParent->m_Value.m_nValue != 0
    && !this->m_bShadowsDisabled )
  {
    v3 = r_shadowwireframe.m_pParent != nullptr ? r_shadowwireframe.m_pParent->m_Value.m_nValue : 0;
    instance_3 = v3 != 0;
    for ( i = *this->m_ShadowsOnModels.m_FirstElement(a1: instance);
          i != 0xFFFF;
          i = this->m_ShadowsOnModels.m_ElementsInBucket.m_Memory.m_pMemory[v5].m_Next )
    {
      v5 = (unsigned __int16)i;
      v6 = &this->m_Shadows.m_Memory.m_pMemory[this->m_ShadowsOnModels.m_ElementsInBucket.m_Memory.m_pMemory[v5].m_Element.m_Element];
      v7 = v6->m_Element.m_Flags & 6;
      if ( v7 == 0
        || this->m_FlashlightStates.m_Memory.m_pMemory[v6->m_Element.m_FlashlightHandle].m_Element.m_nSplitscreenOwner == 0 )
      {
        if ( instance_3 )
        {
          if ( v7 != 0
            || r_shadows_gamecontrol.m_pParent != nullptr && r_shadows_gamecontrol.m_pParent->m_Value.m_nValue != 0 )
          {
            g_pStudioRender->AddShadow(
              this: g_pStudioRender,
              a2: g_pMaterialMRMWireframe,
              a3: nullptr,
              a4: nullptr,
              a5: nullptr,
              a6: nullptr);
          }
        }
        else if ( v7 != 0 )
        {
          ((void (__stdcall *)(_DWORD, _DWORD, FlashlightState_t *, UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *, ITexture *))g_pStudioRender->AddShadow)(
            a1: 0,
            a2: 0,
            a3: &this->m_FlashlightStates.m_Memory.m_pMemory[v6->m_Element.m_FlashlightHandle].m_Element.m_FlashlightState,
            a4: v6,
            a5: v6->m_Element.m_pFlashlightDepthTexture);
        }
        else if ( r_shadows_gamecontrol.m_pParent != nullptr && r_shadows_gamecontrol.m_pParent->m_Value.m_nValue != 0 )
        {
          g_pStudioRender->AddShadow(
            this: g_pStudioRender,
            a2: v6->m_Element.m_pModelMaterial,
            a3: v6->m_Element.m_pBindProxy,
            a4: nullptr,
            a5: nullptr,
            a6: nullptr);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010FA40
// Name: public: virtual int CShadowMgr::SetupFlashlightRenderInstanceInfo(unsigned short __near *,unsigned int __near *,int,int,unsigned short const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShadowMgr::SetupFlashlightRenderInstanceInfo(
        CShadowMgr *this,
        unsigned __int16 *pShadowHandle,
        unsigned int *pModelUsageMask,
        int nUsageStride,
        int nInstanceCount,
        const unsigned __int16 *pInstance)
{
  IMatRenderContext *v7; // esi
  int v8; // ebx
  int v10; // esi
  int v11; // eax
  int m_Next; // eax
  int v13; // esi
  unsigned __int16 m_Element; // dx
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v15; // eax
  int j; // ecx
  CMatRenderContextPtr pRenderContext; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  int nFlashlightCount; // [esp+14h] [ebp-4h]

  v7 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v7;
  if ( v7 != nullptr )
    v7->BeginRender(this: v7);
  v8 = 0;
  nFlashlightCount = 0;
  if ( (!this->SinglePassFlashlightModeEnabled(this) || v7->IsCullingEnabledForSinglePassFlashlight(this: v7))
    && r_shadows.m_pParent != nullptr
    && r_shadows.m_pParent->m_Value.m_nValue != 0 )
  {
    v10 = 0;
    for ( i = 0; v10 < nInstanceCount; i = v10 )
    {
      v11 = pInstance[v10];
      *pModelUsageMask = 0;
      if ( (_WORD)v11 != 0xFFFF )
      {
        m_Next = *this->m_ShadowsOnModels.m_FirstElement(a1: v11);
        if ( m_Next != 0xFFFF )
        {
          do
          {
            v13 = (unsigned __int16)m_Next;
            m_Element = this->m_ShadowsOnModels.m_ElementsInBucket.m_Memory.m_pMemory[v13].m_Element.m_Element;
            v15 = &this->m_Shadows.m_Memory.m_pMemory[m_Element];
            if ( (v15->m_Element.m_Flags & 6) != 0
              && this->m_FlashlightStates.m_Memory.m_pMemory[v15->m_Element.m_FlashlightHandle].m_Element.m_nSplitscreenOwner == 0 )
            {
              for ( j = 0; j < v8; ++j )
              {
                if ( pShadowHandle[j] == m_Element )
                  break;
              }
              *pModelUsageMask |= 1 << j;
              v8 = nFlashlightCount;
              if ( j == nFlashlightCount )
              {
                v8 = nFlashlightCount + 1;
                pShadowHandle[j] = m_Element;
                ++nFlashlightCount;
              }
            }
            m_Next = this->m_ShadowsOnModels.m_ElementsInBucket.m_Memory.m_pMemory[v13].m_Next;
          }
          while ( m_Next != 0xFFFF );
          v10 = i;
        }
      }
      pModelUsageMask = (unsigned int *)((char *)pModelUsageMask + nUsageStride);
      ++v10;
    }
    if ( pRenderContext.m_pObject != nullptr )
    {
      ((void (__thiscall *)(CMatRenderContextPtr))pRenderContext.m_pObject->EndRender)(a1: pRenderContext);
      ((void (__thiscall *)(CMatRenderContextPtr))pRenderContext.m_pObject->Release)(a1: pRenderContext);
    }
    return v8;
  }
  else
  {
    if ( v7 != nullptr )
    {
      v7->EndRender(this: v7);
      v7->Release(this: v7);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010FBE0
// Name: public: virtual void CShadowMgr::PushSinglePassFlashlightStateEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::PushSinglePassFlashlightStateEnabled(CShadowMgr *this, BOOL bEnable)
{
  bool *m_pMemory; // eax
  int m_Size; // ecx
  bool *v5; // eax
  IMatRenderContext *v6; // eax
  IMatRenderContext *v7; // eax

  if ( this->m_bStack_SinglePassFlashlightStateEnabled.m_Size >= this->m_bStack_SinglePassFlashlightStateEnabled.m_Memory.m_nAllocationCount )
    CUtlMemory<bool,int>::Grow(this: (CUtlMemory<char,int> *)&this->m_bStack_SinglePassFlashlightStateEnabled, num: 1);
  ++this->m_bStack_SinglePassFlashlightStateEnabled.m_Size;
  m_pMemory = this->m_bStack_SinglePassFlashlightStateEnabled.m_Memory.m_pMemory;
  m_Size = this->m_bStack_SinglePassFlashlightStateEnabled.m_Size;
  this->m_bStack_SinglePassFlashlightStateEnabled.m_pElements = m_pMemory;
  v5 = &m_pMemory[m_Size - 1];
  if ( v5 != nullptr )
    *v5 = bEnable;
  if ( this->m_bSinglePassFlashlightStateEnabled != bEnable )
  {
    v6 = materials->GetRenderContext(this: materials);
    v6->EnableSinglePassFlashlightMode(this: v6, a2: bEnable);
    if ( bEnable )
      ((void (__stdcall *)(_DWORD))this->SetFlashlightRenderState)(a1: this->m_hSinglePassFlashlightState);
    else
      ((void (__stdcall *)(int))this->SetFlashlightRenderState)(a1: 0xFFFF);
    this->m_bSinglePassFlashlightStateEnabled = bEnable;
  }
  if ( this->m_bSinglePassFlashlightStateEnabled )
  {
    v7 = materials->GetRenderContext(this: materials);
    v7->EnableCullingForSinglePassFlashlight(this: v7, a2: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010FDA0
// Name: public: CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short> *__thiscall CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>(
        CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short> *this)
{
  this->m_ElementsInBucket.m_Memory.m_pMemory = nullptr;
  this->m_ElementsInBucket.m_Memory.m_nAllocationCount = 0;
  this->m_ElementsInBucket.m_Memory.m_nGrowSize = 0;
  this->m_ElementsInBucket.m_LastAlloc.index = -1;
  this->m_ElementsInBucket.m_Head = -1;
  this->m_ElementsInBucket.m_Tail = -1;
  this->m_ElementsInBucket.m_FirstFree = -1;
  this->m_ElementsInBucket.m_ElementCount = 0;
  this->m_ElementsInBucket.m_NumAlloced = 0;
  this->m_ElementsInBucket.m_pElements = this->m_ElementsInBucket.m_Memory.m_pMemory;
  this->m_BucketsUsedByElement.m_Memory.m_pMemory = nullptr;
  this->m_BucketsUsedByElement.m_Memory.m_nAllocationCount = 0;
  this->m_BucketsUsedByElement.m_Memory.m_nGrowSize = 0;
  this->m_BucketsUsedByElement.m_LastAlloc.index = -1;
  this->m_BucketsUsedByElement.m_Head = -1;
  this->m_BucketsUsedByElement.m_Tail = -1;
  this->m_BucketsUsedByElement.m_FirstFree = -1;
  this->m_BucketsUsedByElement.m_ElementCount = 0;
  this->m_BucketsUsedByElement.m_NumAlloced = 0;
  this->m_BucketsUsedByElement.m_pElements = this->m_BucketsUsedByElement.m_Memory.m_pMemory;
  this->m_FirstBucket = nullptr;
  this->m_FirstElement = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10110080
// Name: public: CMaterialsBuckets<struct msurface2_t __near *>::~CMaterialsBuckets<struct msurface2_t __near *>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialsBuckets<msurface2_t *>::~CMaterialsBuckets<msurface2_t *>(
        CMaterialsBuckets<msurface2_t *> *this)
{
  CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short>,unsigned short> > *)&this->m_Elements);
  if ( this->m_Elements.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_Memory.m_pMemory);
      this->m_Elements.m_Memory.m_pMemory = nullptr;
    }
    this->m_Elements.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_MaterialSortInfoArray);
  CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_UsedSortIDs);
  if ( this->m_UsedSortIDs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_UsedSortIDs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_UsedSortIDs.m_Memory.m_pMemory);
      this->m_UsedSortIDs.m_Memory.m_pMemory = nullptr;
    }
    this->m_UsedSortIDs.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110100
// Name: public: CMaterialsBuckets<struct msurface2_t __near *>::CMaterialsBuckets<struct msurface2_t __near *>(void)
// Source: json
//------------------------------------------------------------------------------
CMaterialsBuckets<msurface2_t *> *__thiscall CMaterialsBuckets<msurface2_t *>::CMaterialsBuckets<msurface2_t *>(
        CMaterialsBuckets<msurface2_t *> *this)
{
  CMaterialsBuckets<msurface2_t *> *result; // eax
  UtlLinkedListElem_t<msurface2_t *,unsigned short> *m_pMemory; // ecx

  result = this;
  this->m_UsedSortIDs.m_Memory.m_pMemory = nullptr;
  this->m_UsedSortIDs.m_Memory.m_nAllocationCount = 0;
  this->m_UsedSortIDs.m_Memory.m_nGrowSize = 0;
  this->m_UsedSortIDs.m_LastAlloc.index = -1;
  this->m_UsedSortIDs.m_Head = -1;
  this->m_UsedSortIDs.m_Tail = -1;
  this->m_UsedSortIDs.m_FirstFree = -1;
  this->m_UsedSortIDs.m_ElementCount = 0;
  this->m_UsedSortIDs.m_NumAlloced = 0;
  this->m_UsedSortIDs.m_pElements = this->m_UsedSortIDs.m_Memory.m_pMemory;
  this->m_MaterialSortInfoArray.m_Memory.m_pMemory = nullptr;
  this->m_MaterialSortInfoArray.m_Memory.m_nAllocationCount = 0;
  this->m_MaterialSortInfoArray.m_Memory.m_nGrowSize = 0;
  this->m_MaterialSortInfoArray.m_Size = 0;
  this->m_MaterialSortInfoArray.m_pElements = nullptr;
  this->m_Elements.m_Memory.m_pMemory = nullptr;
  this->m_Elements.m_Memory.m_nAllocationCount = 0;
  this->m_Elements.m_Memory.m_nGrowSize = 0;
  this->m_Elements.m_LastAlloc.index = -1;
  *(_DWORD *)&this->m_Elements.m_FirstFree = 0xFFFF;
  m_pMemory = this->m_Elements.m_Memory.m_pMemory;
  *(_DWORD *)&result->m_Elements.m_Head = -1;
  result->m_Elements.m_NumAlloced = 0;
  result->m_Elements.m_pElements = m_pMemory;
  result->m_FlushCount = -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10110170
// Name: public: CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::~CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::~CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>(
        CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short> *this)
{
  CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_BucketsUsedByElement);
  if ( this->m_BucketsUsedByElement.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_BucketsUsedByElement.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_BucketsUsedByElement.m_Memory.m_pMemory);
      this->m_BucketsUsedByElement.m_Memory.m_pMemory = nullptr;
    }
    this->m_BucketsUsedByElement.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short>,unsigned short>>::RemoveAll((CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short>,unsigned short> > *)this);
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
// Address: 0x101101E0
// Name: private: bool CShadowMgr::AddDecalToShadowList(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShadowMgr::AddDecalToShadowList(
        CShadowMgr *this,
        unsigned __int16 handle,
        unsigned __int16 decalHandle)
{
  int m_NumAlloced; // esi
  _WORD *v5; // eax
  int v6; // esi
  int v8; // edi
  int m_FirstDecal; // eax

  m_NumAlloced = this->m_ShadowSurfaces.m_NumAlloced;
  if ( m_NumAlloced > m_ShadowSurfacesMax )
  {
    if ( m_ShadowSurfacesMax / 0x2000 != m_NumAlloced / 0x2000 )
      _Warning(a1: "Shadow memory (%s) growing [%d]\n", "m_ShadowSurfaces", m_NumAlloced);
    m_ShadowSurfacesMax = m_NumAlloced;
  }
  v5 = (_WORD *)CUtlLinkedList<unsigned short,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int>>>::AllocInternal(
                  this: &this->m_ShadowSurfaces,
                  multilist: true);
  v6 = (int)v5;
  if ( v5 != nullptr )
  {
    v8 = handle;
    *v5 = decalHandle;
    m_FirstDecal = this->m_Shadows.m_Memory.m_pMemory[v8].m_Element.m_FirstDecal;
    if ( m_FirstDecal != 0 )
      CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::LinkBefore(
        this: (CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > > *)&this->m_ShadowSurfaces,
        before: m_FirstDecal,
        elem: v6);
    this->m_Shadows.m_Memory.m_pMemory[v8].m_Element.m_FirstDecal = v6;
    this->m_ShadowDecals.m_Memory.m_pMemory[decalHandle].m_Element.m_ShadowListIndex = v6;
    return 1;
  }
  else
  {
    if ( _executeCount_0 < 10 )
    {
      ++_executeCount_0;
      _Warning(a1: "CShadowMgr::AddDecalToShadowList - overflowed m_ShadowSurfaces linked list!\n");
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101102B0
// Name: private: unsigned short CShadowMgr::AddShadowDecalToSurface(struct msurface2_t __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShadowMgr::AddShadowDecalToSurface(CShadowMgr *this, msurface2_t *surfID, int handle)
{
  int m_NumAlloced; // esi
  CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int> > *p_m_ShadowDecals; // esi
  int v6; // eax
  int v8; // edi
  int v9; // esi
  unsigned int v10; // eax
  int decalHandle; // [esp+Ch] [ebp-10h]
  CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int> > *v13; // [esp+14h] [ebp-8h]
  unsigned __int16 v14; // [esp+18h] [ebp-4h]

  m_NumAlloced = this->m_ShadowDecals.m_NumAlloced;
  if ( m_NumAlloced > m_ShadowDecalsMax )
  {
    if ( m_ShadowDecalsMax / 0x2000 != m_NumAlloced / 0x2000 )
      _Warning(a1: "Shadow memory (%s) growing [%d]\n", "m_ShadowDecals", m_NumAlloced);
    m_ShadowDecalsMax = m_NumAlloced;
  }
  p_m_ShadowDecals = &this->m_ShadowDecals;
  v13 = &this->m_ShadowDecals;
  v6 = CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int>>::AllocInternal(
         this: &this->m_ShadowDecals,
         multilist: true);
  if ( v6 == 0xFFFF )
    v14 = -1;
  else
    v14 = v6;
  decalHandle = (unsigned __int16)v6;
  if ( (_WORD)v6 == 0xFFFF )
  {
    if ( `CShadowMgr::AddShadowDecalToSurface'::`6'::__executeCount < 10 )
    {
      ++`CShadowMgr::AddShadowDecalToSurface'::`6'::__executeCount;
      _Warning(a1: "CShadowMgr::AddShadowDecalToSurface - overflowed m_ShadowDecals linked list!\n");
    }
    return 0xFFFF;
  }
  else
  {
    v8 = (unsigned __int16)v6;
    v9 = (int)&p_m_ShadowDecals->m_Memory.m_pMemory[(unsigned __int16)v6];
    *(_DWORD *)v9 = surfID;
    CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int>>::LinkBefore(
      this: v13,
      before: surfID->m_ShadowDecals,
      elem: (unsigned __int16)v6);
    v10 = surfID->flags >> 11;
    surfID->m_ShadowDecals = v14;
    if ( (v10 & 1) != 0 )
      *(_WORD *)(v9 + 10) = surfID->pDispInfo->AddShadowDecal(this: surfID->pDispInfo, a2: handle);
    else
      *(_WORD *)(v9 + 10) = -1;
    *(_WORD *)(v9 + 8) = handle;
    *(_DWORD *)(v9 + 12) = -1;
    *(_DWORD *)(v9 + 4) = 0;
    if ( CShadowMgr::AddDecalToShadowList(this, handle, decalHandle: v14) != 0 )
    {
      return decalHandle;
    }
    else
    {
      CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int>>::Unlink(
        this: v13,
        elem: v8);
      v13->m_Memory.m_pMemory[v8].m_Next = v13->m_FirstFree;
      v13->m_FirstFree = v8;
      return 0xFFFF;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110410
// Name: private: void CShadowMgr::ApplyShadowToDisplacement(struct CShadowMgr::ShadowBuildInfo_t __near &,class IDispInfo __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::ApplyShadowToDisplacement(
        CShadowMgr *this,
        CShadowMgr::ShadowBuildInfo_t *build,
        IDispInfo *pDispInfo,
        bool bIsFlashlight)
{
  Frustum_t *v5; // eax
  msurface2_t *v6; // eax
  Vector boxMin; // [esp+10h] [ebp-18h] BYREF
  Vector bbMin; // [esp+1Ch] [ebp-Ch] BYREF

  if ( bIsFlashlight || (pDispInfo->GetParent(this: pDispInfo)->flags & 0x2000) == 0 )
  {
    pDispInfo->GetBoundingBox(this: pDispInfo, a2: &boxMin, a3: &bbMin);
    if ( bIsFlashlight )
    {
      v5 = (Frustum_t *)this->GetFlashlightFrustum(this, a2: build->m_Shadow);
      if ( Frustum_t::CullBox(this: v5, mins: &boxMin, maxs: &bbMin) )
        return;
    }
    else if ( !IsBoxIntersectingSphere(
                 &boxMin,
                 boxMax: &bbMin,
                 center: &build->m_vecSphereCenter,
                 radius: build->m_flSphereRadius) )
    {
      return;
    }
    v6 = pDispInfo->GetParent(this: pDispInfo);
    if ( ((*((_BYTE *)v6 + 22) & 1) != 0 || bIsFlashlight)
      && ((this->m_Shadows.m_Memory.m_pMemory[build->m_Shadow].m_Element.m_Flags & 6) != 0 || (v6->flags & 0x3020) == 0) )
    {
      CShadowMgr::AddShadowDecalToSurface(this, surfID: v6, handle: build->m_Shadow);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101104E0
// Name: private: void CShadowMgr::ApplyShadowToLeaf(struct CShadowMgr::Shadow_t const __near &,struct mleaf_t restrict __near *,struct CShadowMgr::ShadowBuildInfo_t restrict __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::ApplyShadowToLeaf(
        CShadowMgr *this,
        const CShadowMgr::Shadow_t *shadow,
        mleaf_t *pLeaf,
        CShadowMgr::ShadowBuildInfo_t *pBuild)
{
  int v4; // eax
  msurface2_t *v5; // edx
  bool v6; // zf
  float *p_x; // ecx
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float v12; // xmm3_4
  bool v13; // cc
  msurface2_t **pHandle; // [esp+4h] [ebp-18h]
  int i; // [esp+8h] [ebp-14h]

  pHandle = &host_state.worldbrush->marksurfaces[pLeaf->firstmarksurface];
  v4 = 0;
  i = 0;
  if ( pLeaf->nummarksurfaces != 0 )
  {
    do
    {
      v5 = pHandle[v4];
      if ( v5->visframe != r_surfacevisframe )
      {
        v6 = (*((_BYTE *)v5 + 22) & 1) == 0;
        v5->visframe = r_surfacevisframe;
        if ( !v6 )
        {
          p_x = &v5->plane->normal.x;
          v8 = p_x[1];
          v9 = *p_x;
          v10 = p_x[2];
          v11 = (float)((float)(pBuild->m_ProjectionDirection.y * v8) + (float)(pBuild->m_ProjectionDirection.x * *p_x))
              + (float)(pBuild->m_ProjectionDirection.z * v10);
          if ( (v5->flags & 0x200) != 0 )
          {
            if ( fabs(v11) >= 0.0099999998 )
            {
              if ( v11 >= 0.0 )
              {
                v12 = p_x[3];
                v13 = (float)((float)((float)(pBuild->m_RayStart.y * v8) + (float)(v9 * pBuild->m_RayStart.x))
                            + (float)(pBuild->m_RayStart.z * v10)) <= v12;
              }
              else
              {
LABEL_9:
                v12 = p_x[3];
                v13 = v12 <= (float)((float)((float)(pBuild->m_RayStart.y * v8) + (float)(v9 * pBuild->m_RayStart.x))
                                   + (float)(pBuild->m_RayStart.z * v10));
              }
              if ( v13
                && fabs(
                     pBuild->m_vecSphereCenter.y * p_x[1]
                   + *p_x * pBuild->m_vecSphereCenter.x
                   + pBuild->m_vecSphereCenter.z * p_x[2]
                   - v12) < pBuild->m_flSphereRadius
                && ((this->m_Shadows.m_Memory.m_pMemory[pBuild->m_Shadow].m_Element.m_Flags & 6) != 0
                 || (v5->flags & 0x3020) == 0) )
              {
                CShadowMgr::AddShadowDecalToSurface(this, surfID: v5, handle: pBuild->m_Shadow);
              }
            }
          }
          else if ( v11 <= -0.0099999998 )
          {
            goto LABEL_9;
          }
        }
      }
      v4 = i + 1;
      i = v4;
    }
    while ( v4 < pLeaf->nummarksurfaces );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110690
// Name: public: virtual void CShadowMgr::AddShadowToBrushModel(unsigned short,struct model_t __near *,class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::AddShadowToBrushModel(
        CShadowMgr *this,
        unsigned __int16 handle,
        model_t *pModel,
        const Vector *origin,
        const QAngle *angles)
{
  int v5; // edi
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v6; // esi
  model_t *v7; // edx
  msurface2_t *v8; // esi
  int i; // ebx
  unsigned int flags; // ecx
  matrix3x4_t worldToModel; // [esp+0h] [ebp-44h] BYREF
  Vector shadowDirInModelSpace; // [esp+30h] [ebp-14h] BYREF
  CShadowMgr *v13; // [esp+3Ch] [ebp-8h]
  bool bIsFlashlight; // [esp+43h] [ebp-1h]

  v13 = this;
  if ( r_shadows.m_pParent != nullptr && r_shadows.m_pParent->m_Value.m_nValue != 0 )
  {
    v5 = handle;
    v6 = &this->m_Shadows.m_Memory.m_pMemory[v5];
    bIsFlashlight = (v6->m_Element.m_Flags & 6) != 0;
    if ( !bIsFlashlight )
    {
      AngleIMatrix(angles, matrix: &worldToModel);
      VectorRotate(in1: &v6->m_Element.m_ProjectionDir.x, in2: &worldToModel, out: &shadowDirInModelSpace.x);
    }
    v7 = pModel;
    v8 = (msurface2_t *)(*(_DWORD *)(pModel->sprite.numframes + 124) + 32 * pModel->brush.firstmodelsurface);
    for ( i = 0; i < v7->brush.nummodelsurfaces; ++v8 )
    {
      flags = v8->flags;
      if ( (v8->flags & 0x10) == 0
        && (bIsFlashlight
         || (flags & 0x200) != 0
         || (float)((float)((float)(v8->plane->normal.y * shadowDirInModelSpace.y)
                          + (float)(v8->plane->normal.x * shadowDirInModelSpace.x))
                  + (float)(v8->plane->normal.z * shadowDirInModelSpace.z)) <= 0.0)
        && ((v13->m_Shadows.m_Memory.m_pMemory[v5].m_Element.m_Flags & 6) != 0 || (flags & 0x3020) == 0) )
      {
        CShadowMgr::AddShadowDecalToSurface(this: v13, surfID: v8, handle);
        v7 = pModel;
      }
      ++i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110790
// Name: private: void CShadowMgr::ClearAllFlashlightMaterialBuckets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::ClearAllFlashlightMaterialBuckets(CShadowMgr *this)
{
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *m_pMemory; // ecx
  int v4; // esi
  CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short> > *p_m_UsedSortIDs; // edi

  if ( !this->m_bSinglePassFlashlightStateEnabled )
  {
    m_Head = this->m_FlashlightStates.m_Head;
    if ( m_Head != 0xFFFF )
    {
      m_pMemory = this->m_FlashlightStates.m_Memory.m_pMemory;
      do
      {
        v4 = m_Head;
        ++m_pMemory[v4].m_Element.m_MaterialBuckets.m_FlushCount;
        p_m_UsedSortIDs = &m_pMemory[v4].m_Element.m_MaterialBuckets.m_UsedSortIDs;
        CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short>,unsigned short> > *)&m_pMemory[v4].m_Element.m_MaterialBuckets.m_Elements);
        CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::RemoveAll(this: p_m_UsedSortIDs);
        m_pMemory = this->m_FlashlightStates.m_Memory.m_pMemory;
        m_Head = m_pMemory[v4].m_Next;
      }
      while ( m_Head != 0xFFFF );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110800
// Name: public: void CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::AddElementToBucket(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::AddElementToBucket(
        CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short> *this,
        unsigned __int16 *bucket,
        int element)
{
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // di
  unsigned __int16 v6; // ax
  unsigned __int16 v7; // bx
  int v8; // eax
  int v9; // eax
  unsigned __int16 *v10; // eax
  unsigned __int16 *v11; // esi
  CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *p_m_BucketsUsedByElement; // [esp+Ch] [ebp-4h]
  unsigned __int16 *firstElementInBucket; // [esp+18h] [ebp+8h]

  v4 = CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_ElementsInBucket,
         multilist: true);
  v5 = -1;
  if ( v4 != 0xFFFF )
    v5 = v4;
  p_m_BucketsUsedByElement = (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&this->m_BucketsUsedByElement;
  v6 = CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_BucketsUsedByElement,
         multilist: true);
  v7 = -1;
  if ( v6 != 0xFFFF )
    v7 = v6;
  v8 = v5;
  this->m_ElementsInBucket.m_Memory.m_pMemory[v8].m_Element.m_Element = element;
  this->m_ElementsInBucket.m_Memory.m_pMemory[v8].m_Element.m_BucketListIndex = v7;
  v9 = v7;
  LOWORD(p_m_BucketsUsedByElement->m_Memory.m_pMemory[v9].m_Element) = (_WORD)bucket;
  HIWORD(p_m_BucketsUsedByElement->m_Memory.m_pMemory[v9].m_Element) = v5;
  v10 = this->m_FirstElement(a1: bucket);
  firstElementInBucket = v10;
  if ( *v10 != 0xFFFF )
  {
    CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short>>::LinkBefore(
      (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)this,
      before: *v10,
      elem: v5);
    v10 = firstElementInBucket;
  }
  *v10 = v5;
  v11 = this->m_FirstBucket(a1: element);
  if ( *v11 != 0xFFFF )
    CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short>>::LinkBefore(
      this: p_m_BucketsUsedByElement,
      before: *v11,
      elem: v7);
  *v11 = v7;
}

//------------------------------------------------------------------------------
// Address: 0x101108E0
// Name: public: void CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::RemoveElement(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::RemoveElement(
        CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short> *this,
        int element)
{
  unsigned __int16 v3; // ax
  UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short> *v4; // eax
  int m_ElementListIndex; // edi
  UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short> *m_pMemory; // eax
  int v7; // edi
  unsigned __int16 v8; // [esp-Ch] [ebp-20h]
  int v9; // [esp+4h] [ebp-10h]
  unsigned __int16 m_Next; // [esp+8h] [ebp-Ch]
  int bucket; // [esp+Ch] [ebp-8h]
  unsigned __int16 i; // [esp+10h] [ebp-4h]

  v3 = *this->m_FirstBucket(a1: element);
  i = v3;
  if ( v3 != 0xFFFF )
  {
    while ( 1 )
    {
      v9 = v3;
      v4 = &this->m_BucketsUsedByElement.m_Memory.m_pMemory[v9];
      m_ElementListIndex = v4->m_Element.m_ElementListIndex;
      bucket = v4->m_Element.m_Bucket;
      if ( (_WORD)m_ElementListIndex == *this->m_FirstElement(a1: bucket) )
      {
        m_Next = this->m_ElementsInBucket.m_Memory.m_pMemory[m_ElementListIndex].m_Next;
        *this->m_FirstElement(a1: bucket) = m_Next;
      }
      CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::Unlink(
        (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)this,
        elem: m_ElementListIndex);
      this->m_ElementsInBucket.m_Memory.m_pMemory[m_ElementListIndex].m_Next = this->m_ElementsInBucket.m_FirstFree;
      m_pMemory = this->m_BucketsUsedByElement.m_Memory.m_pMemory;
      this->m_ElementsInBucket.m_FirstFree = m_ElementListIndex;
      v7 = i;
      v8 = i;
      i = m_pMemory[v9].m_Next;
      CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::Unlink(
        this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&this->m_BucketsUsedByElement,
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
// Address: 0x101109D0
// Name: public: void CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::RemoveBucket(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::RemoveBucket(
        CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short> *this,
        int bucket)
{
  unsigned __int16 v3; // ax
  int v4; // ebx
  int m_BucketListIndex; // edi
  int v6; // edi
  unsigned __int16 v7; // [esp-Ch] [ebp-1Ch]
  unsigned __int16 m_Next; // [esp+4h] [ebp-Ch]
  int element; // [esp+8h] [ebp-8h]
  unsigned __int16 i; // [esp+Ch] [ebp-4h]

  v3 = *this->m_FirstElement(a1: bucket);
  i = v3;
  if ( v3 != 0xFFFF )
  {
    while ( 1 )
    {
      v4 = v3;
      m_BucketListIndex = this->m_ElementsInBucket.m_Memory.m_pMemory[v4].m_Element.m_BucketListIndex;
      element = this->m_ElementsInBucket.m_Memory.m_pMemory[v4].m_Element.m_Element;
      if ( (_WORD)m_BucketListIndex == *this->m_FirstBucket(a1: element) )
      {
        m_Next = this->m_BucketsUsedByElement.m_Memory.m_pMemory[m_BucketListIndex].m_Next;
        *this->m_FirstBucket(a1: element) = m_Next;
      }
      CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::Unlink(
        this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&this->m_BucketsUsedByElement,
        elem: m_BucketListIndex);
      this->m_BucketsUsedByElement.m_Memory.m_pMemory[m_BucketListIndex].m_Next = this->m_BucketsUsedByElement.m_FirstFree;
      this->m_BucketsUsedByElement.m_FirstFree = m_BucketListIndex;
      v6 = i;
      v7 = i;
      i = this->m_ElementsInBucket.m_Memory.m_pMemory[v4].m_Next;
      CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::Unlink(
        (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)this,
        elem: v7);
      this->m_ElementsInBucket.m_Memory.m_pMemory[v6].m_Next = this->m_ElementsInBucket.m_FirstFree;
      this->m_ElementsInBucket.m_FirstFree = v6;
      if ( i == 0xFFFF )
        break;
      v3 = i;
    }
  }
  *this->m_FirstElement(a1: bucket) = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10110DE0
// Name: public: virtual void CShadowMgr::LevelShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::LevelShutdown(CShadowMgr *this)
{
  if ( this->m_bInitialized )
  {
    if ( this->m_pSurfaceBounds != nullptr )
    {
      free(pMem: this->m_pSurfaceBounds);
      this->m_pSurfaceBounds = nullptr;
    }
    CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::RemoveAll(this: &this->m_SurfaceBoundsCache);
    this->m_bInitialized = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110E20
// Name: private: void CShadowMgr::CleanupMaterial(struct CShadowMgr::Shadow_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::CleanupMaterial(CShadowMgr *this, CShadowMgr::Shadow_t *shadow)
{
  CUtlLinkedList<CDispShadowFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowFragment,unsigned short>,unsigned short> > *p_m_SortOrderIds; // esi
  UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short> *m_pMemory; // ecx
  int m_SortOrder; // eax
  int v5; // ebx

  p_m_SortOrderIds = (CUtlLinkedList<CDispShadowFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowFragment,unsigned short>,unsigned short> > *)&this->m_SortOrderIds;
  m_pMemory = this->m_SortOrderIds.m_Memory.m_pMemory;
  m_SortOrder = shadow->m_SortOrder;
  if ( --m_pMemory[m_SortOrder].m_Element.m_RefCount <= 0 )
  {
    v5 = shadow->m_SortOrder;
    CUtlLinkedList<CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::Unlink(
      this: p_m_SortOrderIds,
      elem: shadow->m_SortOrder);
    p_m_SortOrderIds->m_Memory.m_pMemory[v5].m_Next = p_m_SortOrderIds->m_FirstFree;
    p_m_SortOrderIds->m_FirstFree = v5;
  }
  if ( shadow->m_pMaterial != nullptr )
    shadow->m_pMaterial->DecrementReferenceCount(this: shadow->m_pMaterial);
  if ( shadow->m_pModelMaterial != nullptr )
    shadow->m_pModelMaterial->DecrementReferenceCount(this: shadow->m_pModelMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x10110E90
// Name: private: void CShadowMgr::FreeVertices(struct CShadowMgr::ShadowVertexCache_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::FreeVertices(CShadowMgr *this, CShadowMgr::ShadowVertexCache_t *cache)
{
  unsigned int m_Count; // edx
  int m_CachedVerts; // edi
  _WORD *p_m_LargeVertexList; // esi
  unsigned __int16 v5; // [esp-Ch] [ebp-Ch]

  m_Count = cache->m_Count;
  if ( (_WORD)m_Count != 0 )
  {
    if ( cache->m_pVerts != nullptr )
    {
      free(pMem: cache->m_pVerts);
    }
    else
    {
      m_CachedVerts = cache->m_CachedVerts;
      v5 = cache->m_CachedVerts;
      if ( m_Count > 8 )
      {
        p_m_LargeVertexList = &this->m_LargeVertexList;
        CUtlLinkedList<CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>>::Unlink(
          this: &this->m_LargeVertexList,
          elem: v5);
        *(_WORD *)(772 * m_CachedVerts + *(_DWORD *)p_m_LargeVertexList + 770) = p_m_LargeVertexList[8];
      }
      else
      {
        p_m_LargeVertexList = &this->m_SmallVertexList;
        CUtlLinkedList<CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>>::Unlink(
          this: &this->m_SmallVertexList,
          elem: v5);
        *(_WORD *)(196 * m_CachedVerts + *(_DWORD *)p_m_LargeVertexList + 194) = p_m_LargeVertexList[8];
      }
      p_m_LargeVertexList[8] = m_CachedVerts;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110F20
// Name: private: void CShadowMgr::RemoveShadowDecalFromSurface(struct msurface2_t __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::RemoveShadowDecalFromSurface(
        CShadowMgr *this,
        msurface2_t *surfID,
        unsigned __int16 decalHandle)
{
  UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short> *m_pMemory; // esi
  CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int> > *p_m_ShadowDecals; // ebx
  int v5; // edi
  int m_ShadowVerts; // eax
  unsigned __int16 *v7; // esi
  int v8; // edx
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v9; // esi
  int m_ShadowListIndex; // eax
  bool v11; // zf
  int *p_m_FirstDecal; // edx
  unsigned __int16 v13; // [esp+10h] [ebp-8h]
  CShadowMgr *v14; // [esp+14h] [ebp-4h]

  m_pMemory = this->m_ShadowDecals.m_Memory.m_pMemory;
  p_m_ShadowDecals = &this->m_ShadowDecals;
  v5 = decalHandle;
  m_ShadowVerts = m_pMemory[v5].m_Element.m_ShadowVerts;
  v7 = (unsigned __int16 *)&m_pMemory[v5];
  v14 = this;
  if ( (_WORD)m_ShadowVerts != 0xFFFF )
  {
    CShadowMgr::FreeVertices(this, cache: &this->m_VertexCache.m_Memory.m_pMemory[m_ShadowVerts].m_Element);
    v13 = v7[6];
    CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::Unlink(
      this: (CUtlLinkedList<CDispDecalFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecalFragment,unsigned short>,unsigned short> > *)&v14->m_VertexCache,
      elem: v13);
    v14->m_VertexCache.m_Memory.m_pMemory[v13].m_Next = v14->m_VertexCache.m_FirstFree;
    v14->m_VertexCache.m_FirstFree = v13;
    v7[6] = -1;
    this = v14;
  }
  if ( v7[5] != 0xFFFF )
  {
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(*(_DWORD *)v7 + 24) + 44))(
      a1: *(_DWORD *)(*(_DWORD *)v7 + 24),
      a2: v7[5]);
    this = v14;
  }
  if ( surfID->m_ShadowDecals == decalHandle )
    surfID->m_ShadowDecals = p_m_ShadowDecals->m_Memory.m_pMemory[v5].m_Next;
  v8 = v7[4];
  v9 = this->m_Shadows.m_Memory.m_pMemory;
  m_ShadowListIndex = p_m_ShadowDecals->m_Memory.m_pMemory[v5].m_Element.m_ShadowListIndex;
  v11 = v9[v8].m_Element.m_FirstDecal == m_ShadowListIndex;
  p_m_FirstDecal = &v9[v8].m_Element.m_FirstDecal;
  if ( v11 )
    *p_m_FirstDecal = *(_DWORD *)(m_ShadowListIndex + 8);
  CUtlLinkedList<PackedEntity *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int>>>::Free(
    this: &this->m_ShadowSurfaces,
    elem: m_ShadowListIndex);
  p_m_ShadowDecals->m_Memory.m_pMemory[v5].m_Element.m_ShadowListIndex = 0;
  CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int>>::Unlink(
    this: p_m_ShadowDecals,
    elem: decalHandle);
  p_m_ShadowDecals->m_Memory.m_pMemory[v5].m_Next = p_m_ShadowDecals->m_FirstFree;
  p_m_ShadowDecals->m_FirstFree = decalHandle;
}

//------------------------------------------------------------------------------
// Address: 0x10111040
// Name: private: void CShadowMgr::RemoveAllSurfacesFromShadow(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::RemoveAllSurfacesFromShadow(CShadowMgr *this, unsigned __int16 handle)
{
  int v2; // ebx
  unsigned __int16 *m_FirstDecal; // eax
  unsigned __int16 *v5; // edi

  v2 = handle;
  m_FirstDecal = (unsigned __int16 *)this->m_Shadows.m_Memory.m_pMemory[v2].m_Element.m_FirstDecal;
  if ( m_FirstDecal != nullptr )
  {
    do
    {
      v5 = *((unsigned __int16 **)m_FirstDecal + 2);
      CShadowMgr::RemoveShadowDecalFromSurface(
        this,
        surfID: this->m_ShadowDecals.m_Memory.m_pMemory[*m_FirstDecal].m_Element.m_SurfID,
        decalHandle: *m_FirstDecal);
      m_FirstDecal = v5;
    }
    while ( v5 != nullptr );
    this->m_Shadows.m_Memory.m_pMemory[v2].m_Element.m_FirstDecal = 0;
  }
  else
  {
    this->m_Shadows.m_Memory.m_pMemory[v2].m_Element.m_FirstDecal = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101110B0
// Name: public: virtual void CShadowMgr::AddShadowToModel(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::AddShadowToModel(CShadowMgr *this, unsigned __int16 handle, unsigned __int16 model)
{
  int m_NumAlloced; // esi

  if ( model != 0xFFFF && r_flashlightrender.m_pParent != nullptr && r_flashlightrender.m_pParent->m_Value.m_nValue != 0 )
  {
    m_NumAlloced = this->m_ShadowsOnModels.m_ElementsInBucket.m_NumAlloced;
    if ( m_NumAlloced > m_ShadowsOnModelsMax )
    {
      if ( m_ShadowsOnModelsMax / 1000 != m_NumAlloced / 1000 )
        _Warning(
          a1: "Shadow memory (%s) growing [%d]\n",
          "m_ShadowsOnModels",
          this->m_ShadowsOnModels.m_ElementsInBucket.m_NumAlloced);
      m_ShadowsOnModelsMax = m_NumAlloced;
    }
    CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::AddElementToBucket(
      this: &this->m_ShadowsOnModels,
      bucket: model,
      element: handle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10111140
// Name: public: virtual void CShadowMgr::RemoveAllShadowsFromModel(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::RemoveAllShadowsFromModel(CShadowMgr *this, unsigned __int16 model)
{
  if ( model != 0xFFFF )
    CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::RemoveBucket(
      this: &this->m_ShadowsOnModels,
      bucket: model);
}

//------------------------------------------------------------------------------
// Address: 0x10111160
// Name: public: virtual void CShadowMgr::EnableShadow(unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::EnableShadow(CShadowMgr *this, unsigned __int16 handle, bool bEnable)
{
  unsigned __int16 *p_m_Flags; // eax

  if ( bEnable )
  {
    p_m_Flags = &this->m_Shadows.m_Memory.m_pMemory[handle].m_Element.m_Flags;
    *p_m_Flags &= ~8u;
  }
  else
  {
    CShadowMgr::RemoveAllSurfacesFromShadow(this, handle);
    CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::RemoveElement(
      this: &this->m_ShadowsOnModels,
      element: handle);
    this->m_Shadows.m_Memory.m_pMemory[handle].m_Element.m_Flags |= 8u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101111C0
// Name: public: virtual void CShadowMgr::RemoveAllShadowsFromBrushModel(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::RemoveAllShadowsFromBrushModel(CShadowMgr *this, model_t *pModel)
{
  model_t *v3; // ecx
  unsigned __int16 *v4; // ebx
  unsigned __int16 v5; // ax
  UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short> *m_pMemory; // edx
  unsigned __int16 m_Next; // si
  int i; // [esp+4h] [ebp-4h]

  v3 = pModel;
  i = 0;
  if ( pModel->brush.nummodelsurfaces > 0 )
  {
    v4 = (unsigned __int16 *)(*(_DWORD *)(pModel->sprite.numframes + 124) + 32 * pModel->brush.firstmodelsurface + 14);
    do
    {
      v5 = *v4;
      if ( *v4 != 0xFFFF )
      {
        do
        {
          m_pMemory = this->m_ShadowDecals.m_Memory.m_pMemory;
          m_Next = m_pMemory[v5].m_Next;
          CShadowMgr::RemoveShadowDecalFromSurface(this, surfID: m_pMemory[v5].m_Element.m_SurfID, decalHandle: v5);
          v5 = m_Next;
        }
        while ( m_Next != 0xFFFF );
        v3 = pModel;
      }
      *v4 = -1;
      v4 += 16;
      ++i;
    }
    while ( i < v3->brush.nummodelsurfaces );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10111250
// Name: public: virtual void CShadowMgr::ClearShadowRenderList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::ClearShadowRenderList(CShadowMgr *this)
{
  int m_Size; // eax

  m_Size = this->m_RenderQueue.m_Size;
  if ( m_Size > 0 )
    memset(dst: (unsigned __int8 *)this->m_RenderQueue.m_Memory.m_pMemory, value: 0xFFu, count: 2 * m_Size);
  this->m_DecalsToRender = 0;
  CShadowMgr::ClearAllFlashlightMaterialBuckets(this);
}

//------------------------------------------------------------------------------
// Address: 0x10111290
// Name: public: virtual void CShadowMgr::PushFlashlightScissorBounds(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::PushFlashlightScissorBounds(CShadowMgr *this)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v5; // eax
  int *v6; // edi
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *v8; // ecx
  int v9; // edi
  int v10; // eax
  CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *p_m_ScissorStateBackups; // esi
  int v12; // ebx
  int v13; // ecx
  int v14; // edx
  vgui::CTreeViewListControl::CColumnInfo *v15; // ecx
  int v16; // eax
  unsigned __int16 m_Next; // ax
  vgui::CTreeViewListControl::CColumnInfo *v18; // esi
  int p_m_Width; // esi
  int v20; // ecx
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *v21; // eax
  int v23; // [esp+14h] [ebp-4h]

  m_Size = this->m_ScissorStateEntryStart.m_Size;
  v23 = this->m_ScissorStateBackups.m_Size;
  m_nAllocationCount = this->m_ScissorStateEntryStart.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&this->m_ScissorStateEntryStart,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_ScissorStateEntryStart.m_Size;
  m_pMemory = this->m_ScissorStateEntryStart.m_Memory.m_pMemory;
  v5 = this->m_ScissorStateEntryStart.m_Size - m_Size - 1;
  this->m_ScissorStateEntryStart.m_pElements = m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v5);
  v6 = &this->m_ScissorStateEntryStart.m_Memory.m_pMemory[m_Size];
  if ( v6 != nullptr )
    *v6 = v23;
  m_Head = this->m_FlashlightStates.m_Head;
  if ( m_Head != 0xFFFF )
  {
    v8 = this->m_FlashlightStates.m_Memory.m_pMemory;
    v9 = 0;
    do
    {
      v10 = m_Head;
      if ( v8[v10].m_Element.m_nSplitscreenOwner == 0 )
        ++v9;
      m_Head = v8[v10].m_Next;
    }
    while ( m_Head != 0xFFFF );
    p_m_ScissorStateBackups = (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&this->m_ScissorStateBackups;
    v12 = this->m_ScissorStateBackups.m_Size;
    if ( v9 != 0 )
    {
      v13 = p_m_ScissorStateBackups->m_nAllocationCount;
      v14 = v12 + v9;
      if ( v12 + v9 > v13 )
      {
        CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(this: p_m_ScissorStateBackups, num: v9 + v12 - v13);
        v14 = v12 + v9;
      }
      p_m_ScissorStateBackups[1].m_pMemory = (vgui::CTreeViewListControl::CColumnInfo *)((char *)p_m_ScissorStateBackups[1].m_pMemory
                                                                                       + v9);
      v15 = p_m_ScissorStateBackups->m_pMemory;
      v16 = (int)p_m_ScissorStateBackups[1].m_pMemory - v12 - v9;
      p_m_ScissorStateBackups[1].m_nAllocationCount = (int)p_m_ScissorStateBackups->m_pMemory;
      if ( v16 > 0 && v9 > 0 )
        _V_memmove(dest: &v15[v14], src: &v15[v12], count: 20 * v16);
    }
    m_Next = this->m_FlashlightStates.m_Head;
    v18 = p_m_ScissorStateBackups->m_pMemory;
    if ( m_Next != 0xFFFF )
    {
      p_m_Width = (int)&v18[v12].m_Width;
      do
      {
        v20 = m_Next;
        v21 = &this->m_FlashlightStates.m_Memory.m_pMemory[v20];
        if ( v21->m_Element.m_nSplitscreenOwner == 0 )
        {
          *(_BYTE *)(p_m_Width + 12) = v21->m_Element.m_FlashlightState.m_bScissor;
          *(_DWORD *)(p_m_Width - 4) = v21->m_Element.m_FlashlightState.m_nLeft;
          *(_DWORD *)p_m_Width = v21->m_Element.m_FlashlightState.m_nTop;
          *(_DWORD *)(p_m_Width + 4) = v21->m_Element.m_FlashlightState.m_nRight;
          *(_DWORD *)(p_m_Width + 8) = v21->m_Element.m_FlashlightState.m_nBottom;
          p_m_Width += 20;
        }
        m_Next = this->m_FlashlightStates.m_Memory.m_pMemory[v20].m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10111460
// Name: private: virtual void CShadowMgr::RenderFlashlights(bool,bool,class VMatrix const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CShadowMgr::RenderFlashlights(
        CShadowMgr *this@<ecx>,
        int a2@<ebx>,
        bool bDoMasking,
        bool bDoSimpleProjections,
        const VMatrix *pModelToWorld)
{
  unsigned __int16 m_Head; // bx
  int m_nValue; // eax
  bool v8; // zf
  IMatRenderContext *(__thiscall *GetRenderContext)(IMaterialSystem *); // eax
  IMatRenderContext *v10; // eax
  IMatRenderContext *v11; // edi
  void (__thiscall *SetFlashlightMode)(IMatRenderContext *, bool); // eax
  CShadowMgr *v13; // ecx
  int v14; // eax
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *m_pMemory; // ebx
  int v16; // eax
  int v17; // edx
  CShadowMgr::FlashlightInfo_t *v18; // ebx
  int v19; // edx
  unsigned __int16 v20; // si
  int v21; // eax
  int m_Element; // esi
  IMatRenderContext *m_pObject; // edi
  unsigned __int16 m_Next; // ax
  int v25; // edi
  msurface2_t *v26; // esi
  unsigned int flags; // eax
  unsigned int v28; // ecx
  int v29; // edi
  IMesh *v30; // esi
  unsigned __int16 v31; // ax
  worldbrushdata_t *worldbrush; // edx
  UtlLinkedListElem_t<msurface2_t *,unsigned short> *v33; // ecx
  msurface2_t *v34; // eax
  int v35; // esi
  int v36; // ebx
  unsigned __int16 vertBufferIndex; // cx
  signed int v38; // eax
  __int16 v39; // cx
  unsigned __int16 *v40; // edx
  int v41; // esi
  signed int j; // edi
  signed int v43; // ecx
  int m_nVertexCount; // eax
  unsigned __int16 k; // ax
  int v46; // esi
  msurface2_t *v47; // eax
  CDispInfo *pDispInfo; // eax
  CShadowMgr::FlashlightInfo_t *v49; // eax
  unsigned __int16 v50; // bx
  IMatRenderContext v51; // edx
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v52; // eax
  int v53; // eax
  int v54; // ebx
  IMesh *v55; // eax
  worldbrushdata_t *v56; // esi
  int m_nCurrentIndex; // ebx
  msurface2_t *v58; // ecx
  unsigned __int16 firstPrimID; // ax
  __int16 v60; // cx
  int v61; // eax
  int v62; // edx
  signed int v63; // eax
  int v64; // edi
  unsigned __int16 *v65; // edx
  int v66; // esi
  signed int m; // edi
  int v68; // eax
  CShadowMgr::FlashlightInfo_t **v69; // eax
  int *v70; // eax
  int *v71; // eax
  msurface2_t **v72; // eax
  CUtlVectorFixedGrowable<msurface2_t *,64> paintableSurfaces; // [esp+8h] [ebp-444h] BYREF
  CMeshBuilder meshBuilder; // [esp+120h] [ebp-32Ch] BYREF
  CUtlVectorFixedGrowable<int,16> batchPaintableSurfaceIndexCount; // [esp+308h] [ebp-144h] BYREF
  int nVertCount; // [esp+360h] [ebp-ECh] BYREF
  CUtlVectorFixedGrowable<int,16> batchPaintableSurfaceCount; // [esp+364h] [ebp-E8h] BYREF
  CUtlVectorFixedGrowable<CShadowMgr::FlashlightInfo_t *,16> flashlightInfos; // [esp+3BCh] [ebp-90h] BYREF
  int v80; // [esp+414h] [ebp-38h]
  int nIndexCount; // [esp+418h] [ebp-34h] BYREF
  int v82; // [esp+41Ch] [ebp-30h]
  int v83; // [esp+420h] [ebp-2Ch] BYREF
  msurface2_t *surfID; // [esp+424h] [ebp-28h] BYREF
  int src; // [esp+428h] [ebp-24h] BYREF
  int i; // [esp+42Ch] [ebp-20h]
  CMatRenderContextPtr pRenderContext; // [esp+430h] [ebp-1Ch]
  int nSurfaceIndex; // [esp+434h] [ebp-18h]
  CShadowMgr::FlashlightInfo_t *flashlightInfo; // [esp+438h] [ebp-14h]
  int sortID; // [esp+43Ch] [ebp-10h]
  CShadowMgr *v91; // [esp+440h] [ebp-Ch]
  int numIndices; // [esp+444h] [ebp-8h]
  bool bWireframe; // [esp+44Bh] [ebp-1h]

  v91 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CShadowMgr::RenderFlashlights",
    a3: 0,
    a4: "Shadow_Rendering",
    a5: false,
    a6: 4);
  if ( !this->m_bSinglePassFlashlightStateEnabled
    && (r_flashlightrender.m_pParent != nullptr && r_flashlightrender.m_pParent->m_Value.m_nValue != 0
     || bDoSimpleProjections) )
  {
    m_Head = this->m_FlashlightStates.m_Head;
    if ( m_Head != 0xFFFF )
    {
      if ( r_shadowwireframe.m_pParent != nullptr )
        m_nValue = r_shadowwireframe.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      v8 = m_nValue == 0;
      GetRenderContext = materials->GetRenderContext;
      bWireframe = !v8;
      v10 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int))GetRenderContext)(a1: materials, a2);
      v11 = v10;
      pRenderContext.m_pObject = v10;
      if ( v10 != nullptr )
        v10->BeginRender(this: v10);
      SetFlashlightMode = v11->SetFlashlightMode;
      i = 4;
      if ( bDoSimpleProjections )
      {
        SetFlashlightMode(this: v11, a2: false);
        bDoMasking = false;
      }
      else
      {
        SetFlashlightMode(this: v11, a2: true);
        i = 2;
      }
      paintableSurfaces.m_pElements = paintableSurfaces.m_Memory.m_pFixedMemory;
      paintableSurfaces.m_Memory.m_pMemory = paintableSurfaces.m_Memory.m_pFixedMemory;
      batchPaintableSurfaceCount.m_pElements = batchPaintableSurfaceCount.m_Memory.m_pFixedMemory;
      batchPaintableSurfaceCount.m_Memory.m_pMemory = batchPaintableSurfaceCount.m_Memory.m_pFixedMemory;
      batchPaintableSurfaceIndexCount.m_Memory.m_pMemory = batchPaintableSurfaceIndexCount.m_Memory.m_pFixedMemory;
      batchPaintableSurfaceIndexCount.m_pElements = batchPaintableSurfaceIndexCount.m_Memory.m_pFixedMemory;
      paintableSurfaces.m_Memory.m_nGrowSize = -1;
      batchPaintableSurfaceCount.m_Memory.m_nGrowSize = -1;
      batchPaintableSurfaceIndexCount.m_Memory.m_nGrowSize = -1;
      flashlightInfos.m_Memory.m_nGrowSize = -1;
      batchPaintableSurfaceCount.m_Memory.m_nAllocationCount = 16;
      batchPaintableSurfaceIndexCount.m_Memory.m_nAllocationCount = 16;
      flashlightInfos.m_Memory.m_nAllocationCount = 16;
      v13 = v91;
      paintableSurfaces.m_Memory.m_nAllocationCount = 64;
      paintableSurfaces.m_Memory.m_nMallocGrowSize = 0;
      paintableSurfaces.m_Size = 0;
      batchPaintableSurfaceCount.m_Memory.m_nMallocGrowSize = 0;
      batchPaintableSurfaceCount.m_Size = 0;
      batchPaintableSurfaceIndexCount.m_Memory.m_nMallocGrowSize = 0;
      batchPaintableSurfaceIndexCount.m_Size = 0;
      flashlightInfos.m_Memory.m_pMemory = flashlightInfos.m_Memory.m_pFixedMemory;
      flashlightInfos.m_Memory.m_nMallocGrowSize = 0;
      flashlightInfos.m_Size = 0;
      flashlightInfos.m_pElements = flashlightInfos.m_Memory.m_pFixedMemory;
      do
      {
        v14 = m_Head;
        m_pMemory = v13->m_FlashlightStates.m_Memory.m_pMemory;
        v16 = 768 * v14;
        v17 = *(unsigned __int16 *)((char *)&m_pMemory->m_Element.m_Shadow + v16);
        v18 = (CShadowMgr::FlashlightInfo_t *)((char *)&m_pMemory->m_Element + v16);
        v19 = v13->m_Shadows.m_Memory.m_pMemory[v17].m_Element.m_Flags & 6;
        v80 = v16;
        flashlightInfo = v18;
        if ( v19 == i && v18->m_nSplitscreenOwner == 0 )
        {
          nSurfaceIndex = v18->m_MaterialBuckets.m_UsedSortIDs.m_Head;
          if ( (_WORD)nSurfaceIndex != 0xFFFF )
          {
            src = (int)v18;
            CUtlVector<int,CUtlMemoryFixedGrowable<int,16,int>>::InsertBefore(
              this: (CUtlVector<int,CUtlMemoryFixedGrowable<int,16,int> > *)&flashlightInfos,
              elem: flashlightInfos.m_Size,
              &src);
            v11->SetFlashlightStateEx(
              this: v11,
              a2: &v18->m_FlashlightState,
              a3: &v91->m_Shadows.m_Memory.m_pMemory[v18->m_Shadow].m_Element.m_WorldToShadow,
              a4: v91->m_Shadows.m_Memory.m_pMemory[v18->m_Shadow].m_Element.m_pFlashlightDepthTexture);
            CShadowMgr::EnableStencilAndScissorMasking(this: v91, pRenderContext: v11, flashlightInfo: v18, bDoMasking);
            src = 0;
            v83 = 0;
            v20 = nSurfaceIndex;
            do
            {
              nSurfaceIndex = batchPaintableSurfaceCount.m_Size;
              CUtlVector<int,CUtlMemoryFixedGrowable<int,16,int>>::InsertBefore(
                this: &batchPaintableSurfaceCount,
                elem: batchPaintableSurfaceCount.m_Size,
                &src);
              CUtlVector<int,CUtlMemoryFixedGrowable<int,16,int>>::InsertBefore(
                this: &batchPaintableSurfaceIndexCount,
                elem: batchPaintableSurfaceIndexCount.m_Size,
                src: &v83);
              v21 = v20;
              m_Element = v18->m_MaterialBuckets.m_UsedSortIDs.m_Memory.m_pMemory[v21].m_Element;
              v82 = v21 * 6;
              sortID = m_Element;
              if ( bWireframe )
              {
                pRenderContext.m_pObject->Bind(
                  this: pRenderContext.m_pObject,
                  a2: g_materialWorldWireframe,
                  a3: nullptr);
              }
              else if ( bDoSimpleProjections )
              {
                pRenderContext.m_pObject->Bind(
                  this: pRenderContext.m_pObject,
                  a2: v18->m_FlashlightState.m_pProjectedMaterial,
                  a3: nullptr);
              }
              else
              {
                m_pObject = pRenderContext.m_pObject;
                pRenderContext.m_pObject->Bind(
                  this: pRenderContext.m_pObject,
                  a2: materialSortInfoArray[m_Element].material,
                  a3: nullptr);
                m_pObject->BindLightmapPage(this: m_pObject, a2: materialSortInfoArray[m_Element].lightmapPageID);
              }
              m_Next = v18->m_MaterialBuckets.m_MaterialSortInfoArray.m_Memory.m_pMemory[m_Element].m_Head;
              numIndices = 0;
              if ( m_Next != 0xFFFF )
              {
                do
                {
                  v25 = m_Next;
                  v26 = v18->m_MaterialBuckets.m_Elements.m_Memory.m_pMemory[v25].m_Element;
                  flags = v26->flags;
                  v28 = v26->flags >> 11;
                  surfID = v26;
                  if ( (v28 & 1) == 0 && !bWireframe && (flags & 0x200000) != 0 )
                  {
                    CUtlVector<msurface2_t *,CUtlMemoryFixedGrowable<msurface2_t *,64,int>>::InsertBefore(
                      this: &paintableSurfaces,
                      elem: paintableSurfaces.m_Size,
                      src: &surfID);
                    ++batchPaintableSurfaceCount.m_Memory.m_pMemory[nSurfaceIndex];
                    Shader_GetSurfVertexAndIndexCount(
                      surfaceHandle: v26,
                      pVertexCount: &nVertCount,
                      pIndexCount: &nIndexCount);
                    batchPaintableSurfaceIndexCount.m_Memory.m_pMemory[nSurfaceIndex] += nIndexCount;
                  }
                  if ( (v26->flags & 0x800) == 0 )
                    numIndices = HIBYTE(v26->flags) + numIndices - 2 + 2 * HIBYTE(v26->flags) - 4;
                  m_Next = v18->m_MaterialBuckets.m_Elements.m_Memory.m_pMemory[v25].m_Next;
                }
                while ( m_Next != 0xFFFF );
                if ( numIndices > 0 )
                {
                  v29 = sortID;
                  v30 = pRenderContext.m_pObject->GetDynamicMesh(
                          this: pRenderContext.m_pObject,
                          a2: 0,
                          a3: g_WorldStaticMeshes.m_Memory.m_pMemory[sortID],
                          a4: 0,
                          a5: 0);
                  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
                  CMeshBuilder::Begin(
                    this: &meshBuilder,
                    pMesh: v30,
                    type: MATERIAL_TRIANGLES,
                    nVertexCount: 0,
                    nIndexCount: numIndices,
                    pMeshSettings: nullptr);
                  v31 = v18->m_MaterialBuckets.m_MaterialSortInfoArray.m_Memory.m_pMemory[v29].m_Head;
                  if ( v31 != 0xFFFF )
                  {
                    worldbrush = host_state.worldbrush;
                    do
                    {
                      v33 = flashlightInfo->m_MaterialBuckets.m_Elements.m_Memory.m_pMemory;
                      surfID = (msurface2_t *)(8 * v31);
                      v34 = *(msurface2_t **)((char *)&v33->m_Element + (_DWORD)surfID);
                      if ( (v34->flags & 0x800) == 0 )
                      {
                        if ( (v34->flags & 0x8000) != 0 )
                        {
                          v35 = (int)&worldbrush->primitives[worldbrush->surfaces1[v34 - worldbrush->surfaces2].prims.firstPrimID];
                          v36 = (int)&worldbrush->primindices[*(unsigned __int16 *)(v35 + 4)];
                          vertBufferIndex = v34->vertBufferIndex;
                          v38 = meshBuilder.m_IndexBuilder.m_nIndexSize * *(unsigned __int16 *)(v35 + 6);
                          v39 = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset) + vertBufferIndex;
                          if ( v38 > 0 )
                          {
                            v40 = &meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex];
                            v41 = v36 - (_DWORD)v40;
                            for ( j = v38; j != 0; --j )
                            {
                              *v40 = v39 + *(unsigned __int16 *)((char *)v40 + v41);
                              ++v40;
                            }
                            worldbrush = host_state.worldbrush;
                          }
                          v43 = meshBuilder.m_IndexBuilder.m_nIndexSize * v38
                              + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
                          meshBuilder.m_IndexBuilder.m_nCurrentIndex = v43;
                          if ( v43 > meshBuilder.m_IndexBuilder.m_nIndexCount )
                            meshBuilder.m_IndexBuilder.m_nIndexCount = v43;
                        }
                        else
                        {
                          BuildIndicesForSurface(meshBuilder: &meshBuilder.m_IndexBuilder, surfID: v34);
                          worldbrush = host_state.worldbrush;
                        }
                      }
                      v31 = *(_WORD *)((char *)&surfID->plane
                                     + (unsigned int)flashlightInfo->m_MaterialBuckets.m_Elements.m_Memory.m_pMemory
                                     + 2);
                    }
                    while ( v31 != 0xFFFF );
                    v18 = flashlightInfo;
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
                  meshBuilder.m_pMesh->Draw_2(this: meshBuilder.m_pMesh, a2: -1, a3: 0);
                  meshBuilder.m_pMesh = nullptr;
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
              for ( k = v18->m_MaterialBuckets.m_MaterialSortInfoArray.m_Memory.m_pMemory[sortID].m_Head;
                    k != 0xFFFF;
                    k = v18->m_MaterialBuckets.m_Elements.m_Memory.m_pMemory[v46].m_Next )
              {
                v46 = k;
                v47 = v18->m_MaterialBuckets.m_Elements.m_Memory.m_pMemory[v46].m_Element;
                if ( (v47->flags & 0x800) != 0 )
                {
                  pDispInfo = (CDispInfo *)v47->pDispInfo;
                  if ( bWireframe )
                    CDispInfo::SpecifyDynamicMesh(this: pDispInfo);
                  else
                    pDispInfo->m_pMesh->m_pMesh->Draw_2(
                      this: pDispInfo->m_pMesh->m_pMesh,
                      a2: pDispInfo->m_iIndexOffset,
                      a3: pDispInfo->m_nIndices);
                }
              }
              v20 = *(unsigned __int16 *)((char *)&v18->m_MaterialBuckets.m_UsedSortIDs.m_Memory.m_pMemory->m_Next + v82);
            }
            while ( v20 != 0xFFFF );
            CShadowMgr::DisableStencilAndScissorMasking(
              this: v91,
              pRenderContext: pRenderContext.m_pObject,
              flashlightInfo: v18,
              bDoMasking);
            v16 = v80;
            v11 = pRenderContext.m_pObject;
          }
        }
        v13 = v91;
        m_Head = *(unsigned __int16 *)((char *)&v91->m_FlashlightStates.m_Memory.m_pMemory->m_Next + v16);
      }
      while ( m_Head != 0xFFFF );
      if ( paintableSurfaces.m_Size != 0 )
      {
        ((void (__thiscall *)(IMatRenderContext *, int))v11->__vftable[1].EndRender)(a1: v11, a2: 1);
        flashlightInfo = nullptr;
        nSurfaceIndex = 0;
        for ( i = 0; i < flashlightInfos.m_Size; ++i )
        {
          v49 = flashlightInfos.m_Memory.m_pMemory[i];
          v50 = v49->m_MaterialBuckets.m_UsedSortIDs.m_Head;
          v51.__vftable = v11->__vftable;
          numIndices = (int)v49;
          v52 = &v91->m_Shadows.m_Memory.m_pMemory[v49->m_Shadow];
          v51.SetFlashlightStateEx(
            this: v11,
            a2: (const FlashlightState_t *)(numIndices + 320),
            a3: &v52->m_Element.m_WorldToShadow,
            a4: v52->m_Element.m_pFlashlightDepthTexture);
          CShadowMgr::EnableStencilAndScissorMasking(
            this: v91,
            pRenderContext: v11,
            flashlightInfo: (const CShadowMgr::FlashlightInfo_t *)numIndices,
            bDoMasking);
          for ( ; v50 != 0xFFFF; flashlightInfo = (CShadowMgr::FlashlightInfo_t *)((char *)flashlightInfo + 1) )
          {
            v53 = 6 * v50;
            sortID = *(unsigned __int16 *)(*(_DWORD *)(numIndices + 576) + v53);
            v54 = batchPaintableSurfaceCount.m_Memory.m_pMemory[(_DWORD)flashlightInfo];
            src = v53;
            if ( v54 > 0 )
            {
              if ( bDoSimpleProjections )
              {
                v11->Bind(this: v11, a2: *(IMaterial **)(numIndices + 424), a3: nullptr);
              }
              else
              {
                v11->Bind(this: v11, a2: materialSortInfoArray[sortID].material, a3: nullptr);
                v11->BindLightmapPage(this: v11, a2: materialSortInfoArray[sortID].lightmapPageID);
              }
              v55 = v11->GetDynamicMesh(
                      this: v11,
                      a2: false,
                      a3: g_WorldStaticMeshes.m_Memory.m_pMemory[sortID],
                      a4: nullptr,
                      a5: nullptr);
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
              CMeshBuilder::Begin(
                this: &meshBuilder,
                pMesh: v55,
                type: MATERIAL_TRIANGLES,
                nVertexCount: 0,
                nIndexCount: batchPaintableSurfaceIndexCount.m_Memory.m_pMemory[(_DWORD)flashlightInfo],
                pMeshSettings: nullptr);
              v56 = host_state.worldbrush;
              sortID = v54;
              m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
              do
              {
                v58 = paintableSurfaces.m_Memory.m_pMemory[nSurfaceIndex];
                if ( (v58->flags & 0x8000) != 0 )
                {
                  if ( (v58->flags & 0x800) != 0 )
                    firstPrimID = 0;
                  else
                    firstPrimID = v56->surfaces1[v58 - v56->surfaces2].prims.firstPrimID;
                  v60 = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset) + v58->vertBufferIndex;
                  v61 = (int)&v56->primitives[firstPrimID];
                  v62 = *(unsigned __int16 *)(v61 + 4);
                  v63 = meshBuilder.m_IndexBuilder.m_nIndexSize * *(unsigned __int16 *)(v61 + 6);
                  v64 = (int)&v56->primindices[v62];
                  v65 = &meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex];
                  if ( v63 > 0 )
                  {
                    v66 = v64 - (_DWORD)v65;
                    for ( m = v63; m != 0; --m )
                    {
                      *v65 = v60 + *(unsigned __int16 *)((char *)v65 + v66);
                      ++v65;
                    }
                    v56 = host_state.worldbrush;
                    m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
                  }
                  m_nCurrentIndex += v63 * meshBuilder.m_IndexBuilder.m_nIndexSize;
                  meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
                  if ( m_nCurrentIndex > meshBuilder.m_IndexBuilder.m_nIndexCount )
                    meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
                }
                else
                {
                  BuildIndicesForSurface(
                    meshBuilder: &meshBuilder.m_IndexBuilder,
                    surfID: paintableSurfaces.m_Memory.m_pMemory[nSurfaceIndex]);
                  v56 = host_state.worldbrush;
                  m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
                }
                ++nSurfaceIndex;
                --sortID;
              }
              while ( sortID != 0 );
              v11 = pRenderContext.m_pObject;
              if ( meshBuilder.m_bGenerateIndices )
              {
                switch ( meshBuilder.m_Type )
                {
                  case MATERIAL_LINE_STRIP:
                    v68 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
                    break;
                  case MATERIAL_LINE_LOOP:
                    v68 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
                    break;
                  case MATERIAL_POLYGON:
                    v68 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
                    break;
                  case MATERIAL_QUADS:
                    v68 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
                    break;
                  case MATERIAL_INSTANCED_QUADS:
                    v68 = 0;
                    break;
                  default:
                    v68 = meshBuilder.m_VertexBuilder.m_nVertexCount;
                    break;
                }
                CIndexBuilder::GenerateIndices(
                  this: &meshBuilder.m_IndexBuilder,
                  primitiveType: meshBuilder.m_Type,
                  nIndexCount: v68);
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
              meshBuilder.m_pMesh->Draw_2(this: meshBuilder.m_pMesh, a2: -1, a3: 0);
              meshBuilder.m_pMesh = nullptr;
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
              v53 = src;
            }
            v50 = *(_WORD *)(*(_DWORD *)(numIndices + 576) + v53 + 4);
          }
          CShadowMgr::DisableStencilAndScissorMasking(
            this: v91,
            pRenderContext: v11,
            flashlightInfo: (const CShadowMgr::FlashlightInfo_t *)numIndices,
            bDoMasking);
        }
        ((void (__thiscall *)(IMatRenderContext *, _DWORD))v11->__vftable[1].EndRender)(a1: v11, a2: 0);
      }
      v11->SetFlashlightMode(this: v11, a2: false);
      v69 = flashlightInfos.m_Memory.m_pMemory;
      flashlightInfos.m_Size = 0;
      if ( flashlightInfos.m_Memory.m_nGrowSize >= 0 )
      {
        if ( flashlightInfos.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: flashlightInfos.m_Memory.m_pMemory);
          v69 = nullptr;
          flashlightInfos.m_Memory.m_pMemory = nullptr;
        }
        flashlightInfos.m_Memory.m_nAllocationCount = 0;
      }
      flashlightInfos.m_pElements = v69;
      if ( flashlightInfos.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v69 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v69);
          flashlightInfos.m_Memory.m_pMemory = nullptr;
        }
        flashlightInfos.m_Memory.m_nAllocationCount = 0;
      }
      v70 = batchPaintableSurfaceIndexCount.m_Memory.m_pMemory;
      batchPaintableSurfaceIndexCount.m_Size = 0;
      if ( batchPaintableSurfaceIndexCount.m_Memory.m_nGrowSize >= 0 )
      {
        if ( batchPaintableSurfaceIndexCount.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: batchPaintableSurfaceIndexCount.m_Memory.m_pMemory);
          v70 = nullptr;
          batchPaintableSurfaceIndexCount.m_Memory.m_pMemory = nullptr;
        }
        batchPaintableSurfaceIndexCount.m_Memory.m_nAllocationCount = 0;
      }
      batchPaintableSurfaceIndexCount.m_pElements = v70;
      if ( batchPaintableSurfaceIndexCount.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v70 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v70);
          batchPaintableSurfaceIndexCount.m_Memory.m_pMemory = nullptr;
        }
        batchPaintableSurfaceIndexCount.m_Memory.m_nAllocationCount = 0;
      }
      v71 = batchPaintableSurfaceCount.m_Memory.m_pMemory;
      batchPaintableSurfaceCount.m_Size = 0;
      if ( batchPaintableSurfaceCount.m_Memory.m_nGrowSize >= 0 )
      {
        if ( batchPaintableSurfaceCount.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: batchPaintableSurfaceCount.m_Memory.m_pMemory);
          v71 = nullptr;
          batchPaintableSurfaceCount.m_Memory.m_pMemory = nullptr;
        }
        batchPaintableSurfaceCount.m_Memory.m_nAllocationCount = 0;
      }
      batchPaintableSurfaceCount.m_pElements = v71;
      if ( batchPaintableSurfaceCount.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v71 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v71);
          batchPaintableSurfaceCount.m_Memory.m_pMemory = nullptr;
        }
        batchPaintableSurfaceCount.m_Memory.m_nAllocationCount = 0;
      }
      v72 = paintableSurfaces.m_Memory.m_pMemory;
      paintableSurfaces.m_Size = 0;
      if ( paintableSurfaces.m_Memory.m_nGrowSize >= 0 )
      {
        if ( paintableSurfaces.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: paintableSurfaces.m_Memory.m_pMemory);
          v72 = nullptr;
          paintableSurfaces.m_Memory.m_pMemory = nullptr;
        }
        paintableSurfaces.m_Memory.m_nAllocationCount = 0;
      }
      paintableSurfaces.m_pElements = v72;
      if ( paintableSurfaces.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v72 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v72);
          paintableSurfaces.m_Memory.m_pMemory = nullptr;
        }
        paintableSurfaces.m_Memory.m_nAllocationCount = 0;
      }
      v11->EndRender(this: v11);
      v11->Release(this: v11);
    }
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10112180
// Name: public: void CMaterialsBuckets<struct msurface2_t __near *>::SetNumMaterialSortIDs(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialsBuckets<msurface2_t *>::SetNumMaterialSortIDs(CMaterialsBuckets<msurface2_t *> *this, int n)
{
  UtlLinkedListElem_t<unsigned short,unsigned short> *m_pMemory; // ecx

  this->m_MaterialSortInfoArray.m_Size = 0;
  if ( this->m_MaterialSortInfoArray.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_MaterialSortInfoArray.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_MaterialSortInfoArray.m_Memory.m_pMemory);
      this->m_MaterialSortInfoArray.m_Memory.m_pMemory = nullptr;
    }
    this->m_MaterialSortInfoArray.m_Memory.m_nAllocationCount = 0;
  }
  this->m_MaterialSortInfoArray.m_pElements = this->m_MaterialSortInfoArray.m_Memory.m_pMemory;
  this->m_MaterialSortInfoArray.m_Size = 0;
  CUtlVector<CMaterialsBuckets<msurface2_t *>::MaterialSortInfo_t,CUtlMemory<CMaterialsBuckets<msurface2_t *>::MaterialSortInfo_t,int>>::InsertMultipleBefore(
    this: &this->m_MaterialSortInfoArray,
    elem: 0,
    num: n);
  CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short>,unsigned short> > *)&this->m_Elements);
  if ( this->m_Elements.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_Memory.m_pMemory);
      this->m_Elements.m_Memory.m_pMemory = nullptr;
    }
    this->m_Elements.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Elements.m_FirstFree = -1;
  this->m_Elements.m_pElements = this->m_Elements.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_Elements.m_NumAlloced = -65536;
  CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_UsedSortIDs);
  if ( this->m_UsedSortIDs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_UsedSortIDs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_UsedSortIDs.m_Memory.m_pMemory);
      this->m_UsedSortIDs.m_Memory.m_pMemory = nullptr;
    }
    this->m_UsedSortIDs.m_Memory.m_nAllocationCount = 0;
  }
  this->m_UsedSortIDs.m_FirstFree = -1;
  m_pMemory = this->m_UsedSortIDs.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_UsedSortIDs.m_NumAlloced = -65536;
  this->m_UsedSortIDs.m_pElements = m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x10112280
// Name: private: void CShadowMgr::SetMaterial(struct CShadowMgr::Shadow_t __near &,class IMaterial __near *,class IMaterial __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::SetMaterial(
        CShadowMgr *this,
        CShadowMgr::Shadow_t *shadow,
        IMaterial *pMaterial,
        IMaterial *pModelMaterial,
        void *pBindProxy)
{
  int m_Head; // eax
  UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short> *v6; // edx
  int m_ElementCount; // esi
  unsigned __int16 v8; // ax
  unsigned __int16 v9; // bx
  unsigned __int16 v10; // ax
  int m_Size; // ebx
  int v12; // edi
  int m_nAllocationCount; // eax
  unsigned __int16 *m_pMemory; // ecx
  int v15; // eax
  unsigned __int16 *v16; // eax

  shadow->m_pMaterial = pMaterial;
  shadow->m_pModelMaterial = pModelMaterial;
  shadow->m_pBindProxy = pBindProxy;
  if ( pMaterial != nullptr )
    pMaterial->IncrementReferenceCount(this: pMaterial);
  if ( pModelMaterial != nullptr )
    pModelMaterial->IncrementReferenceCount(this: pModelMaterial);
  m_Head = this->m_SortOrderIds.m_Head;
  if ( m_Head == 0xFFFF )
  {
LABEL_9:
    m_ElementCount = this->m_SortOrderIds.m_ElementCount;
    if ( m_ElementCount > m_SortOrderIdsMax )
    {
      if ( m_SortOrderIdsMax / 1000 != m_ElementCount / 1000 )
        _Warning(a1: "Shadow memory (%s) growing [%d]\n", "m_SortOrderIds", this->m_SortOrderIds.m_ElementCount);
      m_SortOrderIdsMax = m_ElementCount;
    }
    v8 = CUtlLinkedList<CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::AllocInternal(
           this: &this->m_SortOrderIds,
           multilist: false);
    v9 = v8;
    if ( v8 == 0xFFFF )
    {
      v10 = -1;
    }
    else
    {
      CUtlLinkedList<CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::LinkBefore(
        this: (CUtlLinkedList<CDispShadowFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowFragment,unsigned short>,unsigned short> > *)&this->m_SortOrderIds,
        before: 0xFFFFu,
        elem: v8);
      v10 = v9;
    }
    shadow->m_SortOrder = v10;
    this->m_SortOrderIds.m_Memory.m_pMemory[v10].m_Element.m_MaterialEnum = (int)pMaterial;
    this->m_SortOrderIds.m_Memory.m_pMemory[shadow->m_SortOrder].m_Element.m_RefCount = 1;
    m_Size = this->m_RenderQueue.m_Size;
    if ( m_Size > m_RenderQueueMax )
    {
      if ( m_RenderQueueMax / 1000 != m_Size / 1000 )
        _Warning(a1: "Shadow memory (%s) growing [%d]\n", "m_RenderQueue", this->m_RenderQueue.m_Size);
      m_RenderQueueMax = m_Size;
    }
    for ( ; m_Size < LOWORD(this->m_SortOrderIds.m_Memory.m_nAllocationCount); ++m_Size )
    {
      v12 = this->m_RenderQueue.m_Size;
      m_nAllocationCount = this->m_RenderQueue.m_Memory.m_nAllocationCount;
      if ( v12 + 1 > m_nAllocationCount )
        CUtlMemory<wchar_t,int>::Grow(
          this: (CUtlMemory<wchar_t,int> *)&this->m_RenderQueue,
          num: v12 - m_nAllocationCount + 1);
      ++this->m_RenderQueue.m_Size;
      m_pMemory = this->m_RenderQueue.m_Memory.m_pMemory;
      v15 = this->m_RenderQueue.m_Size - v12 - 1;
      this->m_RenderQueue.m_pElements = m_pMemory;
      if ( v15 > 0 )
        _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 2 * v15);
      v16 = &this->m_RenderQueue.m_Memory.m_pMemory[v12];
      if ( v16 != nullptr )
        *v16 = -1;
    }
  }
  else
  {
    v6 = this->m_SortOrderIds.m_Memory.m_pMemory;
    while ( (IMaterial *)v6[(unsigned __int16)m_Head].m_Element.m_MaterialEnum != pMaterial )
    {
      m_Head = v6[(unsigned __int16)m_Head].m_Next;
      if ( m_Head == 0xFFFF )
        goto LABEL_9;
    }
    ++v6[(unsigned __int16)m_Head].m_Element.m_RefCount;
    shadow->m_SortOrder = m_Head;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101124B0
// Name: public: virtual void CShadowMgr::RemoveAllDecalsFromShadow(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::RemoveAllDecalsFromShadow(CShadowMgr *this, unsigned __int16 handle)
{
  CShadowMgr::RemoveAllSurfacesFromShadow(this, handle);
  CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::RemoveElement(
    this: &this->m_ShadowsOnModels,
    element: handle);
}

//------------------------------------------------------------------------------
// Address: 0x101124E0
// Name: public: virtual void CShadowMgr::SetShadowMaterial(unsigned short,class IMaterial __near *,class IMaterial __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::SetShadowMaterial(
        CShadowMgr *this,
        unsigned __int16 handle,
        IMaterial *pMaterial,
        IMaterial *pModelMaterial,
        void *pBindProxy)
{
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v6; // esi

  v6 = &this->m_Shadows.m_Memory.m_pMemory[handle];
  if ( v6->m_Element.m_pMaterial != pMaterial
    || v6->m_Element.m_pModelMaterial != pModelMaterial
    || v6->m_Element.m_pBindProxy != pBindProxy )
  {
    CShadowMgr::CleanupMaterial(this, shadow: &v6->m_Element);
    CShadowMgr::SetMaterial(this, shadow: &v6->m_Element, pMaterial, pModelMaterial, pBindProxy);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10112530
// Name: private: struct ShadowVertex_t __near * CShadowMgr::AllocateVertices(struct CShadowMgr::ShadowVertexCache_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short> *__thiscall CShadowMgr::AllocateVertices(
        CShadowMgr *this,
        CShadowMgr::ShadowVertexCache_t *cache,
        int count)
{
  int v4; // esi
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // si
  unsigned __int16 v7; // ax
  int m_NumAlloced; // esi
  unsigned __int16 v10; // ax
  unsigned __int16 v11; // si
  unsigned __int16 v12; // ax

  cache->m_pVerts = nullptr;
  cache->m_Count = count;
  if ( count > 8 )
  {
    if ( count > 32 )
    {
      cache->m_pVerts = (ShadowVertex_t *)MemAlloc_Alloc(nSize: (24 * (unsigned __int64)(unsigned int)count) >> 32 != 0 ? -1 : 24 * count);
      cache->m_CachedVerts = -1;
      return (UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short> *)cache->m_pVerts;
    }
    else
    {
      m_NumAlloced = this->m_LargeVertexList.m_NumAlloced;
      if ( m_NumAlloced > m_LargeVertexListMax )
      {
        if ( m_LargeVertexListMax / 1000 != m_NumAlloced / 1000 )
          _Warning(a1: "Shadow memory (%s) growing [%d]\n", "m_LargeVertexList", this->m_LargeVertexList.m_NumAlloced);
        m_LargeVertexListMax = m_NumAlloced;
      }
      v10 = CUtlLinkedList<CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>>::AllocInternal(
              this: &this->m_LargeVertexList,
              multilist: false);
      v11 = v10;
      if ( v10 == 0xFFFF )
      {
        v12 = -1;
      }
      else
      {
        CUtlLinkedList<CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>>::LinkBefore(
          this: &this->m_LargeVertexList,
          before: 0xFFFFu,
          elem: v10);
        v12 = v11;
      }
      cache->m_CachedVerts = v12;
      return (UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short> *)&this->m_LargeVertexList.m_Memory.m_pMemory[v12];
    }
  }
  else
  {
    v4 = this->m_SmallVertexList.m_NumAlloced;
    if ( v4 > m_SmallVertexListMax )
    {
      if ( m_SmallVertexListMax / 1000 != v4 / 1000 )
        _Warning(a1: "Shadow memory (%s) growing [%d]\n", "m_SmallVertexList", this->m_SmallVertexList.m_NumAlloced);
      m_SmallVertexListMax = v4;
    }
    v5 = CUtlLinkedList<CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>>::AllocInternal(
           this: &this->m_SmallVertexList,
           multilist: false);
    v6 = v5;
    if ( v5 == 0xFFFF )
    {
      v7 = -1;
    }
    else
    {
      CUtlLinkedList<CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>>::LinkBefore(
        this: &this->m_SmallVertexList,
        before: 0xFFFFu,
        elem: v5);
      v7 = v6;
    }
    cache->m_CachedVerts = v7;
    return &this->m_SmallVertexList.m_Memory.m_pMemory[v7];
  }
}

//------------------------------------------------------------------------------
// Address: 0x101126D0
// Name: private: bool CShadowMgr::ComputeShadowVertices(struct CShadowMgr::ShadowDecal_t __near &,class VMatrix const __near *,class VMatrix const __near *,struct CShadowMgr::ShadowVertexCache_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShadowMgr::ComputeShadowVertices(
        CShadowMgr *this,
        Vector **decal,
        const VMatrix *pModelToWorld,
        ShadowVertex_t **pWorldToModel,
        CShadowMgr::ShadowVertexCache_t *pVertexCache)
{
  msurface2_t *v5; // esi
  void *v7; // esp
  int v8; // eax
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *p_temp; // ecx
  int v10; // eax
  int v11; // esi
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short> *Vertices; // eax
  cplane_t *y_low; // ecx
  Vector *v15[3]; // [esp+0h] [ebp-664h] BYREF
  ShadowClipState_t clip; // [esp+Ch] [ebp-658h] BYREF
  VMatrix temp; // [esp+618h] [ebp-4Ch] BYREF
  Vector vToAdd; // [esp+658h] [ebp-Ch] BYREF

  v5 = (msurface2_t *)*decal;
  v7 = alloca((4 * HIBYTE((*decal)->x) + 15) & 0xFF0);
  v8 = 0;
  if ( HIBYTE((*decal)->x) != 0 )
  {
    do
    {
      v15[v8] = &host_state.worldbrush->vertexes[host_state.worldbrush->vertindices[v8 + v5->firstvertindex]].position;
      v5 = (msurface2_t *)*decal;
      ++v8;
    }
    while ( v8 < HIBYTE((*decal)->x) );
  }
  p_temp = &this->m_Shadows.m_Memory.m_pMemory[*((unsigned __int16 *)decal + 4)];
  if ( pModelToWorld != nullptr )
  {
    MatrixMultiply(src1: &p_temp->m_Element.m_WorldToShadow, src2: pModelToWorld, dst: &temp);
    p_temp = (UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *)&temp;
  }
  else
  {
    pWorldToModel = nullptr;
  }
  v10 = CShadowMgr::ProjectAndClipVertices(
          this,
          a2: (CClipTop *)decal,
          shadow: &this->m_Shadows.m_Memory.m_pMemory[*((unsigned __int16 *)decal + 4)].m_Element,
          worldToShadow: &p_temp->m_Element.m_WorldToShadow,
          (const VMatrix *)pWorldToModel,
          count: HIBYTE((*decal)->x),
          ppPosition: v15,
          ppOutVertex: &pWorldToModel,
          &clip);
  v11 = v10;
  if ( v10 != 0 )
  {
    Vertices = CShadowMgr::AllocateVertices(this, cache: pVertexCache, count: v10);
    y_low = (cplane_t *)LODWORD((*decal)->y);
    vToAdd.x = y_low->normal.x * 0.1;
    vToAdd.y = y_low->normal.y * 0.1;
    vToAdd.z = y_low->normal.z * 0.1;
    CShadowMgr::CopyClippedVertices(
      this,
      count: v11,
      ppSrcVert: pWorldToModel,
      pDstVert: Vertices->m_Element.m_Verts,
      &vToAdd);
    pVertexCache->m_Shadow = *((_WORD *)decal + 4);
    return 1;
  }
  else
  {
    pVertexCache->m_Count = 0;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10112830
// Name: public: virtual void CShadowMgr::SetNumWorldMaterialBuckets(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::SetNumWorldMaterialBuckets(CShadowMgr *this, int numMaterialSortBins)
{
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *m_pMemory; // ecx
  unsigned int v5; // esi

  m_Head = this->m_FlashlightStates.m_Head;
  this->m_NumWorldMaterialBuckets = numMaterialSortBins;
  if ( m_Head != 0xFFFF )
  {
    m_pMemory = this->m_FlashlightStates.m_Memory.m_pMemory;
    do
    {
      v5 = m_Head;
      CMaterialsBuckets<msurface2_t *>::SetNumMaterialSortIDs(
        this: &m_pMemory[v5].m_Element.m_MaterialBuckets,
        n: numMaterialSortBins);
      CMaterialsBuckets<msurface2_t *>::SetNumMaterialSortIDs(
        this: &this->m_FlashlightStates.m_Memory.m_pMemory[v5].m_Element.m_OccluderBuckets,
        n: numMaterialSortBins);
      m_pMemory = this->m_FlashlightStates.m_Memory.m_pMemory;
      m_Head = m_pMemory[v5].m_Next;
    }
    while ( m_Head != 0xFFFF );
  }
  CShadowMgr::ClearAllFlashlightMaterialBuckets(this);
}

//------------------------------------------------------------------------------
// Address: 0x101128B0
// Name: private: void CShadowMgr::AllocFlashlightMaterialBuckets(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::AllocFlashlightMaterialBuckets(CShadowMgr *this, unsigned __int16 flashlightID)
{
  int v3; // edi

  v3 = flashlightID;
  CMaterialsBuckets<msurface2_t *>::SetNumMaterialSortIDs(
    this: &this->m_FlashlightStates.m_Memory.m_pMemory[v3].m_Element.m_MaterialBuckets,
    n: this->m_NumWorldMaterialBuckets);
  CMaterialsBuckets<msurface2_t *>::SetNumMaterialSortIDs(
    this: &this->m_FlashlightStates.m_Memory.m_pMemory[v3].m_Element.m_OccluderBuckets,
    n: this->m_NumWorldMaterialBuckets);
}

//------------------------------------------------------------------------------
// Address: 0x10112900
// Name: public: void CMaterialsBuckets<struct msurface2_t __near *>::AddElement(int,struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialsBuckets<msurface2_t *>::AddElement(
        CMaterialsBuckets<msurface2_t *> *this,
        int sortID,
        msurface2_t *elem)
{
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // bx
  int m_FlushCount; // ecx
  CMaterialsBuckets<msurface2_t *>::MaterialSortInfo_t *v7; // eax
  unsigned __int16 v8; // ax
  int v9; // edi
  UtlLinkedListElem_t<unsigned short,unsigned short> *v10; // eax

  v4 = CUtlLinkedList<msurface2_t *,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<msurface2_t *,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_Elements,
         multilist: true);
  v5 = -1;
  if ( v4 != 0xFFFF )
    v5 = v4;
  this->m_Elements.m_Memory.m_pMemory[v5].m_Element = elem;
  m_FlushCount = this->m_FlushCount;
  v7 = &this->m_MaterialSortInfoArray.m_Memory.m_pMemory[sortID];
  if ( v7->m_FlushCount == m_FlushCount )
  {
    CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short>>::LinkBefore(
      this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&this->m_Elements,
      before: v7->m_Head,
      elem: v5);
  }
  else
  {
    v7->m_FlushCount = m_FlushCount;
    v8 = CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::AllocInternal(
           this: &this->m_UsedSortIDs,
           multilist: false);
    v9 = v8;
    if ( v8 != 0xFFFF )
    {
      CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::LinkBefore(
        this: &this->m_UsedSortIDs,
        before: 0xFFFFu,
        elem: v8);
      v10 = &this->m_UsedSortIDs.m_Memory.m_pMemory[v9];
      if ( v10 != nullptr )
      {
        v10->m_Element = sortID;
        this->m_MaterialSortInfoArray.m_Memory.m_pMemory[sortID].m_Head = v5;
        return;
      }
    }
  }
  this->m_MaterialSortInfoArray.m_Memory.m_pMemory[sortID].m_Head = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10112AC0
// Name: private: struct CShadowMgr::SurfaceBounds_t const __near * CShadowMgr::GetSurfaceBounds(struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
const CShadowMgr::SurfaceBounds_t *__thiscall CShadowMgr::GetSurfaceBounds(CShadowMgr *this, msurface2_t *surfID)
{
  int v3; // ebx
  int v4; // eax
  bool v6; // cc
  CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16> > *p_m_SurfaceBoundsCache; // ecx
  unsigned int m_Tail_low; // edi
  unsigned int v9; // eax
  unsigned __int16 v10; // di
  CShadowMgr::SurfaceBounds_t *v11; // edi
  unsigned __int16 nIndex; // [esp+8h] [ebp-4h]

  v3 = surfID - host_state.worldbrush->surfaces2;
  v4 = this->m_pSurfaceBounds[v3];
  if ( (_WORD)v4 != 0xFFFF )
    return (const CShadowMgr::SurfaceBounds_t *)(((unsigned int)&this->m_SurfaceBoundsCache.m_Memory.m_Memory[15]
                                                & 0xFFFFFFF0)
                                               + 80 * v4);
  v6 = this->m_SurfaceBoundsCache.m_ElementCount < 1024;
  p_m_SurfaceBoundsCache = &this->m_SurfaceBoundsCache;
  if ( v6 )
  {
    v9 = CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::AllocInternal(
           this: p_m_SurfaceBoundsCache,
           multilist: false);
    v10 = v9;
    if ( v9 != 0xFFFF )
      CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::LinkAfter(
        this: &this->m_SurfaceBoundsCache,
        after: 0xFFFF,
        elem: v9);
    nIndex = v10;
  }
  else
  {
    m_Tail_low = LOWORD(this->m_SurfaceBoundsCache.m_Tail);
    nIndex = this->m_SurfaceBoundsCache.m_Tail;
    CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::Unlink(
      this: p_m_SurfaceBoundsCache,
      elem: m_Tail_low);
    CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::LinkAfter(
      this: &this->m_SurfaceBoundsCache,
      after: 0xFFFF,
      elem: m_Tail_low);
    this->m_pSurfaceBounds[*(_DWORD *)(((unsigned int)&this->m_SurfaceBoundsCache.m_Memory.m_Memory[15] & 0xFFFFFFF0)
                                     + 80 * m_Tail_low
                                     + 0x30)] = -1;
  }
  this->m_pSurfaceBounds[v3] = nIndex;
  v11 = (CShadowMgr::SurfaceBounds_t *)(80 * nIndex
                                      + ((unsigned int)&this->m_SurfaceBoundsCache.m_Memory.m_Memory[15] & 0xFFFFFFF0));
  v11->m_nSurfaceIndex = v3;
  CShadowMgr::ComputeSurfaceBounds(this, pBounds: v11, nSurfID: surfID);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x10112BD0
// Name: private: bool CShadowMgr::IsShadowNearSurface(unsigned short,struct msurface2_t __near *,class VMatrix const __near *,class VMatrix const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
bool __userpurge CShadowMgr::IsShadowNearSurface@<al>(
        CShadowMgr *this@<ecx>,
        int a2@<ebp>,
        unsigned __int16 h,
        msurface2_t *nSurfID,
        const VMatrix *pModelToWorld,
        const VMatrix *pWorldToModel)
{
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v6; // esi
  const CShadowMgr::SurfaceBounds_t *SurfaceBounds; // edi
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  float v15; // xmm3_4
  float v16; // xmm4_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm4_4
  const Ray_t *p_m_Ray; // [esp-24h] [ebp-84h]
  float v23[3]; // [esp-Ch] [ebp-6Ch] BYREF
  Ray_t transformedRay_4; // [esp+4h] [ebp-5Ch] OVERLAPPED BYREF
  int v25; // [esp+54h] [ebp-Ch]
  void *v26; // [esp+58h] [ebp-8h]
  void *retaddr; // [esp+60h] [ebp+0h]

  v25 = a2;
  v26 = retaddr;
  v6 = &this->m_Shadows.m_Memory.m_pMemory[h];
  SurfaceBounds = CShadowMgr::GetSurfaceBounds(this, surfID: nSurfID);
  if ( pModelToWorld != nullptr )
  {
    x = SurfaceBounds->m_vecCenter.x;
    y = SurfaceBounds->m_vecCenter.y;
    z = SurfaceBounds->m_vecCenter.z;
    v8 = (float)((float)((float)(pModelToWorld->m[0][1] * y) + (float)(pModelToWorld->m[0][0] * x))
               + (float)(pModelToWorld->m[0][2] * z))
       + pModelToWorld->m[0][3];
    v9 = (float)((float)((float)(pModelToWorld->m[1][1] * y) + (float)(pModelToWorld->m[1][0] * x))
               + (float)(pModelToWorld->m[1][2] * z))
       + pModelToWorld->m[1][3];
    v10 = (float)((float)((float)(pModelToWorld->m[2][1] * y) + (float)(pModelToWorld->m[2][0] * x))
                + (float)(pModelToWorld->m[2][2] * z))
        + pModelToWorld->m[2][3];
  }
  else
  {
    v8 = SurfaceBounds->m_vecCenter.x;
    v9 = SurfaceBounds->m_vecCenter.y;
    v10 = SurfaceBounds->m_vecCenter.z;
  }
  if ( (float)((float)((float)((float)(v6->m_Element.m_vecSphereCenter.x - v8)
                             * (float)(v6->m_Element.m_vecSphereCenter.x - v8))
                     + (float)((float)(v6->m_Element.m_vecSphereCenter.y - v9)
                             * (float)(v6->m_Element.m_vecSphereCenter.y - v9)))
             + (float)((float)(v6->m_Element.m_vecSphereCenter.z - v10)
                     * (float)(v6->m_Element.m_vecSphereCenter.z - v10))) >= (float)((float)(v6->m_Element.m_flSphereRadius
                                                                                           + SurfaceBounds->m_flRadius)
                                                                                   * (float)(v6->m_Element.m_flSphereRadius
                                                                                           + SurfaceBounds->m_flRadius)) )
    return false;
  if ( pModelToWorld != nullptr )
  {
    v15 = pWorldToModel->m[0][1];
    v16 = pWorldToModel->m[0][0];
    transformedRay_4.m_Extents.x = 0.0;
    v17 = v6->m_Element.m_Ray.m_Start.x;
    v18 = v6->m_Element.m_Ray.m_Start.y;
    v19 = v6->m_Element.m_Ray.m_Start.z;
    v20 = (float)((float)((float)(v15 * v18) + (float)(v16 * v17)) + (float)(pWorldToModel->m[0][2] * v19))
        + pWorldToModel->m[0][3];
    v21 = pWorldToModel->m[1][0];
    v23[0] = v20;
    v23[1] = (float)((float)((float)(pWorldToModel->m[1][1] * v18) + (float)(v21 * v17))
                   + (float)(pWorldToModel->m[1][2] * v19))
           + pWorldToModel->m[1][3];
    v23[2] = (float)((float)((float)(pWorldToModel->m[2][1] * v18) + (float)(pWorldToModel->m[2][0] * v17))
                   + (float)(pWorldToModel->m[2][2] * v19))
           + pWorldToModel->m[2][3];
    Vector3DMultiply(src1: pWorldToModel, src2: &v6->m_Element.m_Ray.m_Delta, dst: &transformedRay_4.m_Start);
    transformedRay_4.m_Delta = v6->m_Element.m_Ray.m_StartOffset;
    transformedRay_4.m_StartOffset = v6->m_Element.m_Ray.m_Extents;
    LOWORD(transformedRay_4.m_Extents.y) = *(_WORD *)&v6->m_Element.m_Ray.m_IsRay;
    p_m_Ray = (const Ray_t *)v23;
  }
  else
  {
    p_m_Ray = &v6->m_Element.m_Ray;
  }
  *(__m128 *)&transformedRay_4.m_pWorldAxisTransform = Four_Zeros;
  return IsBoxIntersectingRay(
           boxMin: &SurfaceBounds->m_vecMins,
           boxMax: &SurfaceBounds->m_vecMaxs,
           ray: p_m_Ray,
           fl4Tolerance: (const __m128 *)&transformedRay_4.m_pWorldAxisTransform);
}

//------------------------------------------------------------------------------
// Address: 0x10112E20
// Name: private: void CShadowMgr::ApplyFlashlightToLeaf(struct CShadowMgr::Shadow_t const __near &,struct mleaf_t __near *,struct CShadowMgr::ShadowBuildInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::ApplyFlashlightToLeaf(
        CShadowMgr *this,
        const CShadowMgr::Shadow_t *shadow,
        mleaf_t *pLeaf,
        CShadowMgr::ShadowBuildInfo_t *pBuild)
{
  mleaf_t *v4; // ebx
  float x; // xmm0_4
  float y; // xmm2_4
  float z; // xmm6_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  const Frustum_t *(__thiscall *GetFlashlightFrustum)(struct CShadowMgr *, unsigned __int16); // eax
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  int m_Shadow; // edx
  float v16; // xmm2_4
  float v17; // xmm6_4
  float v18; // xmm2_4
  Frustum_t *v19; // eax
  int v20; // eax
  int v21; // eax
  msurface2_t *v22; // esi
  int firstvertindex; // edx
  int v24; // edx
  mvertex_t *vertexes; // eax
  float v26; // xmm0_4
  mvertex_t *v27; // eax
  float *p_x; // ebx
  CShadowMgr *v29; // ecx
  bool v30; // cc
  int nummarksurfaces; // ecx
  Vector leafMins; // [esp+8h] [ebp-30h] BYREF
  Vector leafMaxs; // [esp+14h] [ebp-24h] BYREF
  Vector lookdir; // [esp+20h] [ebp-18h] BYREF
  msurface2_t **pHandle; // [esp+2Ch] [ebp-Ch]
  int i; // [esp+30h] [ebp-8h]
  CShadowMgr *v37; // [esp+34h] [ebp-4h]
  bool bCullDepth_3; // [esp+4Bh] [ebp+13h]

  v37 = this;
  v4 = pLeaf;
  x = pLeaf->m_vecCenter.x;
  y = pLeaf->m_vecHalfDiagonal.y;
  z = pLeaf->m_vecHalfDiagonal.z;
  v9 = pLeaf->m_vecHalfDiagonal.x + x;
  v10 = x - pLeaf->m_vecHalfDiagonal.x;
  GetFlashlightFrustum = this->GetFlashlightFrustum;
  leafMaxs.x = v9;
  v12 = pLeaf->m_vecCenter.y;
  v13 = y + v12;
  v14 = v12 - pLeaf->m_vecHalfDiagonal.y;
  m_Shadow = pBuild->m_Shadow;
  leafMaxs.y = v13;
  v16 = pLeaf->m_vecCenter.z;
  v17 = z + v16;
  v18 = v16 - pLeaf->m_vecHalfDiagonal.z;
  leafMaxs.z = v17;
  leafMins.x = v10;
  leafMins.y = v14;
  leafMins.z = v18;
  v19 = (Frustum_t *)GetFlashlightFrustum(this, a2: m_Shadow);
  if ( !Frustum_t::CullBox(this: v19, mins: &leafMins, maxs: &leafMaxs) )
  {
    v20 = r_flashlightculldepth.m_pParent != nullptr ? r_flashlightculldepth.m_pParent->m_Value.m_nValue : 0;
    bCullDepth_3 = v20 != 0;
    v21 = 0;
    pHandle = &host_state.worldbrush->marksurfaces[pLeaf->firstmarksurface];
    i = 0;
    if ( pLeaf->nummarksurfaces != 0 )
    {
      do
      {
        v22 = pHandle[v21];
        if ( v22->visframe != r_surfacevisframe )
        {
          firstvertindex = v22->firstvertindex;
          v22->visframe = r_surfacevisframe;
          v24 = host_state.worldbrush->vertindices[firstvertindex];
          vertexes = host_state.worldbrush->vertexes;
          v26 = vertexes[v24].position.x - pBuild->m_RayStart.x;
          v27 = &vertexes[v24];
          lookdir.x = v26;
          lookdir.y = v27->position.y - pBuild->m_RayStart.y;
          lookdir.z = v27->position.z - pBuild->m_RayStart.z;
          VectorNormalize(vec: &lookdir);
          p_x = &v22->plane->normal.x;
          if ( fabs(
                 pBuild->m_vecSphereCenter.y * p_x[1]
               + *p_x * pBuild->m_vecSphereCenter.x
               + pBuild->m_vecSphereCenter.z * p_x[2]
               - p_x[3]) < pBuild->m_flSphereRadius )
          {
            v29 = v37;
            if ( (v37->m_Shadows.m_Memory.m_pMemory[pBuild->m_Shadow].m_Element.m_Flags & 6) != 0
              || (v22->flags & 0x3020) == 0 )
            {
              CShadowMgr::AddShadowDecalToSurface(this: v37, surfID: v22, handle: pBuild->m_Shadow);
              v29 = v37;
            }
            if ( !bCullDepth_3
              || ((v22->flags & 0x200) != 0
                ? (v30 = fabs(*p_x * lookdir.x + p_x[1] * lookdir.y + p_x[2] * lookdir.z) >= 0.0099999998)
                : (v30 = (float)((float)((float)(*p_x * lookdir.x) + (float)(p_x[1] * lookdir.y))
                               + (float)(p_x[2] * lookdir.z)) >= 0.0099999998),
                  v30) )
            {
              CMaterialsBuckets<msurface2_t *>::AddElement(
                this: &v29->m_FlashlightStates.m_Memory.m_pMemory[shadow->m_FlashlightHandle].m_Element.m_OccluderBuckets,
                sortID: v22->materialSortID,
                elem: v22);
            }
          }
          v4 = pLeaf;
        }
        nummarksurfaces = v4->nummarksurfaces;
        v21 = i + 1;
        i = v21;
      }
      while ( v21 < nummarksurfaces );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10113060
// Name: public: virtual bool CShadowMgr::EnumerateLeaf(int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShadowMgr::EnumerateLeaf(CShadowMgr *this, int leaf, CShadowMgr::ShadowBuildInfo_t *context)
{
  int v4; // eax
  ISpatialLeafEnumerator_vtbl *v5; // eax
  mleaf_t *v6; // edi
  CShadowMgr *v7; // ecx
  IDispInfo *v8; // esi
  CShadowMgr *v10; // [esp+Ch] [ebp-4h]
  CShadowMgr *v11; // [esp+Ch] [ebp-4h]
  bool bIsFlashlight; // [esp+18h] [ebp+8h]
  int i; // [esp+1Ch] [ebp+Ch]

  v10 = this;
  if ( context->m_pVis != nullptr )
  {
    v4 = CM_LeafCluster(leafnum: leaf);
    if ( ((unsigned __int8)(1 << (v4 & 7)) & context->m_pVis[v4 >> 3]) == 0 )
      return 1;
    this = v10;
  }
  v5 = &this->ISpatialLeafEnumerator::__vftable[84 * context->m_Shadow];
  v6 = &host_state.worldbrush->leafs[leaf];
  v7 = (CShadowMgr *)((char *)this - 4);
  v11 = v7;
  if ( ((int)v5[30].EnumerateLeaf & 6) != 0 )
  {
    bIsFlashlight = true;
    CShadowMgr::ApplyFlashlightToLeaf(this: v7, shadow: (const CShadowMgr::Shadow_t *)v5, pLeaf: v6, pBuild: context);
  }
  else
  {
    bIsFlashlight = false;
    CShadowMgr::ApplyShadowToLeaf(this: v7, shadow: (const CShadowMgr::Shadow_t *)v5, pLeaf: v6, pBuild: context);
  }
  i = 0;
  if ( v6->dispCount != 0 )
  {
    do
    {
      v8 = DispInfo_IndexArray(
             hArray: host_state.worldbrush->hDispInfos,
             iElement: host_state.worldbrush->m_pDispInfoReferences[i + v6->dispListStart]);
      if ( !v8->GetTag(this: v8) )
      {
        v8->SetTag(this: v8);
        CShadowMgr::ApplyShadowToDisplacement(this: v11, build: context, pDispInfo: v8, bIsFlashlight);
      }
      ++i;
    }
    while ( i < v6->dispCount );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10113160
// Name: public: virtual void CShadowMgr::AddShadowsOnSurfaceToRenderList(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::AddShadowsOnSurfaceToRenderList(CShadowMgr *this, unsigned __int16 decalHandle)
{
  unsigned __int16 i; // dx
  UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short> *m_pMemory; // ecx
  unsigned int v5; // edi
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v6; // eax
  msurface2_t *m_SurfID; // ecx
  int v8; // edx
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *v9; // eax
  int v10; // edx
  int m_SortOrder; // eax

  if ( r_shadows.m_pParent != nullptr && r_shadows.m_pParent->m_Value.m_nValue != 0 )
  {
    for ( i = decalHandle; i != 0xFFFF; i = this->m_ShadowDecals.m_Memory.m_pMemory[v5].m_Next )
    {
      m_pMemory = this->m_ShadowDecals.m_Memory.m_pMemory;
      v5 = i;
      v6 = &this->m_Shadows.m_Memory.m_pMemory[m_pMemory[v5].m_Element.m_Shadow];
      if ( (v6->m_Element.m_Flags & 6) != 0 )
      {
        m_SurfID = m_pMemory[i].m_Element.m_SurfID;
        if ( !this->m_bSinglePassFlashlightStateEnabled )
        {
          v8 = 3 * v6->m_Element.m_FlashlightHandle;
          v9 = this->m_FlashlightStates.m_Memory.m_pMemory;
          v10 = v8 << 8;
          if ( *(int *)((char *)&v9->m_Element.m_nSplitscreenOwner + v10) == 0 )
            CMaterialsBuckets<msurface2_t *>::AddElement(
              this: (CMaterialsBuckets<msurface2_t *> *)((char *)&v9->m_Element.m_MaterialBuckets + v10),
              sortID: m_SurfID->materialSortID,
              elem: m_SurfID);
        }
      }
      else
      {
        if ( r_shadows_gamecontrol.m_pParent == nullptr
          || r_shadows_gamecontrol.m_pParent->m_Value.m_nValue == 0
          || this->m_nSkipShadowForEntIndex == v6->m_Element.m_nEntIndex )
        {
          continue;
        }
        m_SortOrder = v6->m_Element.m_SortOrder;
        m_pMemory[v5].m_Element.m_NextRender = this->m_RenderQueue.m_Memory.m_pMemory[m_SortOrder];
        this->m_RenderQueue.m_Memory.m_pMemory[m_SortOrder] = i;
      }
      ++this->m_DecalsToRender;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10113250
// Name: private: bool CShadowMgr::GenerateNormalShadowRenderInfo(class IMatRenderContext __near *,struct CShadowMgr::ShadowDecal_t __near &,struct CShadowMgr::ShadowRenderInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShadowMgr::GenerateNormalShadowRenderInfo(
        CShadowMgr *this,
        IMatRenderContext *pRenderContext,
        Vector **decal,
        CShadowMgr::ShadowRenderInfo_t *info)
{
  int m_Count; // ecx
  int v7; // edx
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short> *v8; // edi
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // ecx
  int m_NumAlloced; // edi
  unsigned __int16 v14; // ax
  int m_nAllocationCount; // edi
  int v16; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  m_Count = info->m_Count;
  if ( m_Count >= 0x10000 )
  {
    info->m_Count = 0x10000;
    return 1;
  }
  v7 = *((unsigned __int16 *)decal + 6);
  if ( (_WORD)v7 == 0xFFFF )
  {
    if ( !CShadowMgr::IsShadowNearSurface(
            this,
            a2: (int)&savedregs,
            h: *((_WORD *)decal + 4),
            nSurfID: (msurface2_t *)*decal,
            pModelToWorld: info->m_pModelToWorld,
            pWorldToModel: &info->m_WorldToModel) )
      return 0;
    if ( (this->m_Shadows.m_Memory.m_pMemory[*((unsigned __int16 *)decal + 4)].m_Element.m_Flags & 1) != 0 )
    {
      m_NumAlloced = this->m_VertexCache.m_NumAlloced;
      if ( m_NumAlloced > m_VertexCacheMax )
      {
        if ( m_VertexCacheMax / 1000 != m_NumAlloced / 1000 )
          _Warning(a1: "Shadow memory (%s) growing [%d]\n", "m_VertexCache", this->m_VertexCache.m_NumAlloced);
        m_VertexCacheMax = m_NumAlloced;
      }
      v14 = CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::AddToTail(this: &this->m_VertexCache);
      *((_WORD *)decal + 6) = v14;
      info->m_pCache[info->m_Count] = v14;
      v8 = &this->m_VertexCache.m_Memory.m_pMemory[*((unsigned __int16 *)decal + 6)];
    }
    else
    {
      m_nAllocationCount = this->m_TempVertexCache.m_Memory.m_nAllocationCount;
      if ( m_nAllocationCount > m_TempVertexCacheMax )
      {
        if ( m_TempVertexCacheMax / 1000 != m_nAllocationCount / 1000 )
          _Warning(
            a1: "Shadow memory (%s) growing [%d]\n",
            "m_TempVertexCache",
            this->m_TempVertexCache.m_Memory.m_nAllocationCount);
        m_TempVertexCacheMax = m_nAllocationCount;
      }
      v16 = CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::AddToTail(this: (CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int> > *)&this->m_TempVertexCache);
      info->m_pCache[info->m_Count] = -1 - v16;
      v8 = (UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short> *)&this->m_TempVertexCache.m_Memory.m_pMemory[v16];
    }
    if ( CShadowMgr::ComputeShadowVertices(
           this,
           decal,
           pModelToWorld: info->m_pModelToWorld,
           pWorldToModel: (ShadowVertex_t **)&info->m_WorldToModel,
           pVertexCache: &v8->m_Element) == 0 )
      return 0;
  }
  else
  {
    info->m_pCache[m_Count] = v7;
    v8 = &this->m_VertexCache.m_Memory.m_pMemory[*((unsigned __int16 *)decal + 6)];
  }
  v9 = v8->m_Element.m_Count;
  v10 = 3 * v9 - 6;
  v11 = info->m_VertexCount + v9;
  if ( v11 < info->m_nMaxVertices )
  {
    v12 = info->m_IndexCount + v10;
    if ( v12 < info->m_nMaxIndices )
    {
      ++info->m_Count;
      info->m_VertexCount = v11;
      info->m_IndexCount = v12;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10113410
// Name: private: void CShadowMgr::GenerateShadowRenderInfo(class IMatRenderContext __near *,unsigned short,struct CShadowMgr::ShadowRenderInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::GenerateShadowRenderInfo(
        CShadowMgr *this,
        IMatRenderContext *pRenderContext,
        unsigned __int16 decalHandle,
        CShadowMgr::ShadowRenderInfo_t *info)
{
  UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short> *v6; // esi
  char NormalShadowRenderInfo; // al
  unsigned __int16 next; // [esp+1Ch] [ebp+10h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CShadowMgr::GenerateShadowRenderInfo",
    a3: 0,
    a4: "Shadow_Rendering",
    a5: false,
    a6: 4);
  info->m_VertexCount = 0;
  info->m_IndexCount = 0;
  info->m_Count = 0;
  info->m_DispCount = 0;
  if ( decalHandle != 0xFFFF )
  {
    do
    {
      v6 = &this->m_ShadowDecals.m_Memory.m_pMemory[decalHandle];
      next = v6->m_Element.m_NextRender;
      if ( this->m_Shadows.m_Memory.m_pMemory[v6->m_Element.m_Shadow].m_Element.m_FalloffBias != 0xFF )
      {
        if ( v6->m_Element.m_DispShadow == 0xFFFF )
          NormalShadowRenderInfo = CShadowMgr::GenerateNormalShadowRenderInfo(
                                     this,
                                     pRenderContext,
                                     decal: (Vector **)v6,
                                     info);
        else
          NormalShadowRenderInfo = CShadowMgr::GenerateDispShadowRenderInfo(this, decal: &v6->m_Element, info);
        if ( NormalShadowRenderInfo == 0
          && (this->m_Shadows.m_Memory.m_pMemory[v6->m_Element.m_Shadow].m_Element.m_Flags & 1) != 0 )
        {
          CShadowMgr::RemoveShadowDecalFromSurface(this, surfID: v6->m_Element.m_SurfID, decalHandle);
        }
      }
      decalHandle = next;
    }
    while ( next != 0xFFFF );
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x101134F0
// Name: private: void CShadowMgr::GenerateShadowRenderInfoThreaded(class IMatRenderContext __near *,unsigned short,struct CShadowMgr::ShadowRenderInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::GenerateShadowRenderInfoThreaded(
        CShadowMgr *this,
        IMatRenderContext *pRenderContext,
        unsigned __int16 decalHandle,
        CShadowMgr::ShadowRenderInfo_t *info)
{
  signed int v5; // ebx
  void *v7; // esp
  unsigned __int16 v8; // cx
  UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short> *v9; // ebx
  int m_Shadow; // edx
  unsigned __int16 *v11; // eax
  int *p_vertCount; // ebx
  UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short> *v13; // eax
  int m_IndexCount; // ecx
  int v15; // edx
  int m_DispCount; // ecx
  _BYTE v17[12]; // [esp+0h] [ebp-48h] BYREF
  CParallelProcessor<CShadowMgr::DispDecalWorkItem_t,CMemberFuncJobItemProcessor<CShadowMgr::DispDecalWorkItem_t,CShadowMgr,CShadowMgr>,1> v18; // [esp+Ch] [ebp-3Ch] BYREF
  int next; // [esp+3Ch] [ebp-Ch]
  CShadowMgr::DispDecalWorkItem_t *pDispDecalWorkItems; // [esp+40h] [ebp-8h]
  unsigned __int16 *v21; // [esp+44h] [ebp-4h]
  int decalHandlea; // [esp+54h] [ebp+Ch]
  int nNumDispDecals; // [esp+58h] [ebp+10h]
  int nNumDispDecalsa; // [esp+58h] [ebp+10h]

  v5 = 0;
  info->m_VertexCount = 0;
  info->m_IndexCount = 0;
  info->m_Count = 0;
  info->m_DispCount = 0;
  v7 = alloca(12 * this->m_DecalsToRender);
  v8 = decalHandle;
  pDispDecalWorkItems = (CShadowMgr::DispDecalWorkItem_t *)v17;
  nNumDispDecals = 0;
  if ( decalHandle != 0xFFFF )
  {
    v21 = (unsigned __int16 *)v17;
    while ( 1 )
    {
      v9 = &this->m_ShadowDecals.m_Memory.m_pMemory[v8];
      m_Shadow = v9->m_Element.m_Shadow;
      next = v9->m_Element.m_NextRender;
      if ( this->m_Shadows.m_Memory.m_pMemory[m_Shadow].m_Element.m_FalloffBias != 0xFF )
      {
        if ( v9->m_Element.m_DispShadow == 0xFFFF )
        {
          if ( CShadowMgr::GenerateNormalShadowRenderInfo(this, pRenderContext, decal: (Vector **)v9, info) == 0
            && (this->m_Shadows.m_Memory.m_pMemory[v9->m_Element.m_Shadow].m_Element.m_Flags & 1) != 0 )
          {
            CShadowMgr::RemoveShadowDecalFromSurface(this, surfID: v9->m_Element.m_SurfID, decalHandle);
          }
        }
        else
        {
          v11 = v21;
          ++nNumDispDecals;
          *v21 = v8;
          v21 = v11 + 6;
        }
      }
      decalHandle = next;
      if ( (_WORD)next == 0xFFFF )
        break;
      v8 = next;
    }
    v5 = nNumDispDecals;
  }
  v18.m_pItems.m_value = nullptr;
  v18.m_pLimit = nullptr;
  _InterlockedExchange((volatile __int32 *)&v18.m_pItems, 0);
  LODWORD(v18.m_ItemProcessor.m_pfnProcess) = CShadowMgr::ProcessDispDecalWorkItem;
  memset((char *)&v18.m_ItemProcessor.m_pfnProcess + 4, 0, 20);
  v18.m_ItemProcessor.m_pObject = this;
  CParallelProcessor<CShadowMgr::DispDecalWorkItem_t,CMemberFuncJobItemProcessor<CShadowMgr::DispDecalWorkItem_t,CShadowMgr,CShadowMgr>,1>::Run(
    this: &v18,
    pItems: pDispDecalWorkItems,
    nItems: v5,
    nChunkSize: 1,
    nMaxParallel: 0x7FFFFFFF,
    pThreadPool: nullptr);
  if ( v5 > 0 )
  {
    p_vertCount = &pDispDecalWorkItems->vertCount;
    decalHandlea = nNumDispDecals;
    do
    {
      v13 = &this->m_ShadowDecals.m_Memory.m_pMemory[*((unsigned __int16 *)p_vertCount - 2)];
      if ( *((_BYTE *)p_vertCount - 2) != 0 )
      {
        nNumDispDecalsa = *p_vertCount + info->m_VertexCount;
        if ( nNumDispDecalsa < info->m_nMaxVertices )
        {
          m_IndexCount = info->m_IndexCount;
          if ( m_IndexCount + p_vertCount[1] < info->m_nMaxIndices )
          {
            info->m_VertexCount = nNumDispDecalsa;
            v15 = m_IndexCount + p_vertCount[1];
            m_DispCount = info->m_DispCount;
            info->m_IndexCount = v15;
            info->m_pDispCache[m_DispCount] = v13->m_Element.m_DispShadow;
            ++info->m_DispCount;
          }
        }
      }
      else if ( (this->m_Shadows.m_Memory.m_pMemory[v13->m_Element.m_Shadow].m_Element.m_Flags & 1) != 0 )
      {
        CShadowMgr::RemoveShadowDecalFromSurface(
          this,
          surfID: v13->m_Element.m_SurfID,
          decalHandle: *((_WORD *)p_vertCount - 2));
      }
      p_vertCount += 3;
      --decalHandlea;
    }
    while ( decalHandlea != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101136C0
// Name: private: void CShadowMgr::RenderShadowList(class IMatRenderContext __near *,unsigned short,class VMatrix const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::RenderShadowList(
        CShadowMgr *this,
        IMatRenderContext *pRenderContext,
        unsigned __int16 decalHandle,
        const VMatrix *pModelToWorld)
{
  int m_nAllocationCount; // ecx
  int m_DecalsToRender; // eax
  int v7; // eax
  int v8; // edi
  int v9; // ecx
  int v10; // eax
  int v11; // eax
  int v12; // edi
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v13; // ebx
  int v14; // edi
  int v15; // ebx
  unsigned __int16 *m_pMemory; // edx
  int v17; // eax
  int (__thiscall *GetMaxVerticesToRender)(IMatRenderContext *, IMaterial *); // edx
  IMesh *v19; // edi
  int v20; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-250h] BYREF
  CShadowMgr::ShadowRenderInfo_t info; // [esp+1F4h] [ebp-68h] BYREF
  CShadowMgr::Shadow_t *shadow; // [esp+258h] [ebp-4h]
  int savedregs; // [esp+25Ch] [ebp+0h] BYREF

  m_nAllocationCount = this->m_ShadowDecalCache.m_nAllocationCount;
  m_DecalsToRender = this->m_DecalsToRender;
  if ( m_DecalsToRender > m_nAllocationCount )
  {
    if ( m_DecalsToRender >= 0x10000 )
      m_DecalsToRender = 0x10000;
    v7 = m_DecalsToRender - m_nAllocationCount;
    v8 = v7;
    if ( v7 > 0 )
    {
      CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&this->m_ShadowDecalCache, num: v7);
      DevMsg(
        a1: "[CShadowMgr::RenderShadowList] growing shadow decal cache (decals: %d, cache: %d, diff: %d).\n",
        this->m_DecalsToRender,
        this->m_ShadowDecalCache.m_nAllocationCount,
        v8);
    }
  }
  v9 = this->m_DispShadowDecalCache.m_nAllocationCount;
  v10 = this->m_DecalsToRender;
  if ( v10 > v9 )
  {
    if ( v10 >= 0x10000 )
      v10 = 0x10000;
    v11 = v10 - v9;
    v12 = v11;
    if ( v11 > 0 )
    {
      CUtlMemory<wchar_t,int>::Grow(this: (CUtlMemory<wchar_t,int> *)&this->m_DispShadowDecalCache, num: v11);
      DevMsg(
        a1: "[CShadowMgr::RenderShadowList] growing disp shadow decal cache (decals: %d, cache: %d, diff: %d).\n",
        this->m_DecalsToRender,
        this->m_DispShadowDecalCache.m_nAllocationCount,
        v12);
    }
  }
  v13 = &this->m_Shadows.m_Memory.m_pMemory[this->m_ShadowDecals.m_Memory.m_pMemory[decalHandle].m_Element.m_Shadow];
  shadow = &v13->m_Element;
  if ( r_shadowwireframe.m_pParent != nullptr && r_shadowwireframe.m_pParent->m_Value.m_nValue != 0 )
    pRenderContext->Bind(this: pRenderContext, a2: g_materialWorldWireframe, a3: nullptr);
  else
    pRenderContext->Bind(this: pRenderContext, a2: v13->m_Element.m_pMaterial, a3: v13->m_Element.m_pBindProxy);
  v14 = this->m_TempVertexCache.m_Size - 1;
  if ( v14 >= 0 )
  {
    v15 = v14;
    do
    {
      CShadowMgr::FreeVertices(this, cache: &this->m_TempVertexCache.m_Memory.m_pMemory[v15--]);
      --v14;
    }
    while ( v14 >= 0 );
    v13 = (UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *)shadow;
  }
  this->m_TempVertexCache.m_Size = 0;
  m_pMemory = this->m_DispShadowDecalCache.m_pMemory;
  info.m_pCache = this->m_ShadowDecalCache.m_pMemory;
  info.m_pDispCache = m_pMemory;
  info.m_pModelToWorld = pModelToWorld;
  if ( pModelToWorld != nullptr )
    MatrixInverseTR(src: pModelToWorld, dst: &info.m_WorldToModel);
  v17 = pRenderContext->GetMaxIndicesToRender(this: pRenderContext);
  GetMaxVerticesToRender = pRenderContext->GetMaxVerticesToRender;
  info.m_nMaxIndices = v17;
  info.m_nMaxVertices = GetMaxVerticesToRender(this: pRenderContext, a2: v13->m_Element.m_pMaterial);
  if ( r_threaded_shadow_clip.m_pParent != nullptr && r_threaded_shadow_clip.m_pParent->m_Value.m_nValue != 0 )
    CShadowMgr::GenerateShadowRenderInfoThreaded(this, pRenderContext, decalHandle, &info);
  else
    CShadowMgr::GenerateShadowRenderInfo(this, pRenderContext, decalHandle, &info);
  v19 = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 1, a3: 0, a4: 0, a5: 0);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  CMeshBuilder::Begin(
    this: &meshBuilder,
    pMesh: v19,
    type: MATERIAL_TRIANGLES,
    nVertexCount: info.m_VertexCount,
    nIndexCount: info.m_IndexCount,
    pMeshSettings: nullptr);
  v20 = CShadowMgr::AddNormalShadowsToMeshBuilder(this, &meshBuilder, &info);
  CShadowMgr::AddDisplacementShadowsToMeshBuilder(this, &meshBuilder, &info, baseIndex: v20);
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
  v19->Draw_2(this: v19, a2: -1, a3: 0);
  if ( r_shadowids.m_pParent != nullptr && r_shadowids.m_pParent->m_Value.m_nValue != 0 )
    CShadowMgr::RenderDebuggingInfo(this, a2: COERCE_FLOAT(&savedregs), &info, func: DrawShadowID);
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

//------------------------------------------------------------------------------
// Address: 0x10113A10
// Name: public: CShadowMgr::~CShadowMgr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::~CShadowMgr(CShadowMgr *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int> >::BlockHeader_t *m_pBlocks; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int> >::BlockHeader_t *v3; // [esp-4h] [ebp-10h]

  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_ScissorStateEntryStart);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_ScissorStateBackups);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_bStack_SinglePassFlashlightStateEnabled);
  if ( this->m_DispShadowDecalCache.m_nGrowSize >= 0 )
  {
    if ( this->m_DispShadowDecalCache.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_DispShadowDecalCache.m_pMemory);
      this->m_DispShadowDecalCache.m_pMemory = nullptr;
    }
    this->m_DispShadowDecalCache.m_nAllocationCount = 0;
  }
  if ( this->m_ShadowDecalCache.m_nGrowSize >= 0 )
  {
    if ( this->m_ShadowDecalCache.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ShadowDecalCache.m_pMemory);
      this->m_ShadowDecalCache.m_pMemory = nullptr;
    }
    this->m_ShadowDecalCache.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::RemoveAll(this: &this->m_FlashlightStates);
  CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>::~CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>(this: (CUtlMemoryAligned<Frustum_t,16> *)&this->m_FlashlightStates);
  CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::RemoveAll(this: &this->m_SurfaceBoundsCache);
  CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::~CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>(this: &this->m_ShadowsOnModels);
  CUtlLinkedList<CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_LargeVertexList);
  if ( this->m_LargeVertexList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_LargeVertexList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_LargeVertexList.m_Memory.m_pMemory);
      this->m_LargeVertexList.m_Memory.m_pMemory = nullptr;
    }
    this->m_LargeVertexList.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_SmallVertexList);
  if ( this->m_SmallVertexList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SmallVertexList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SmallVertexList.m_Memory.m_pMemory);
      this->m_SmallVertexList.m_Memory.m_pMemory = nullptr;
    }
    this->m_SmallVertexList.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_TempVertexCache);
  CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_VertexCache);
  if ( this->m_VertexCache.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_VertexCache.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_VertexCache.m_Memory.m_pMemory);
      this->m_VertexCache.m_Memory.m_pMemory = nullptr;
    }
    this->m_VertexCache.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_SortOrderIds);
  if ( this->m_SortOrderIds.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SortOrderIds.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SortOrderIds.m_Memory.m_pMemory);
      this->m_SortOrderIds.m_Memory.m_pMemory = nullptr;
    }
    this->m_SortOrderIds.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_RenderQueue);
  CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::RemoveAll(this: (CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > > *)&this->m_ShadowSurfaces);
  m_pBlocks = this->m_ShadowSurfaces.m_Memory.m_pBlocks;
  if ( m_pBlocks != nullptr )
  {
    do
    {
      v3 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
    }
    while ( m_pBlocks != nullptr );
    this->m_ShadowSurfaces.m_Memory.m_pBlocks = nullptr;
    this->m_ShadowSurfaces.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int>>::RemoveAll(this: &this->m_ShadowDecals);
  if ( this->m_ShadowDecals.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ShadowDecals.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ShadowDecals.m_Memory.m_pMemory);
      this->m_ShadowDecals.m_Memory.m_pMemory = nullptr;
    }
    this->m_ShadowDecals.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CShadowMgr::Shadow_t,unsigned short,0,int,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>>::RemoveAll(this: &this->m_Shadows);
  CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>::~CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>(this: (CUtlMemoryAligned<Frustum_t,16> *)&this->m_Shadows);
}

//------------------------------------------------------------------------------
// Address: 0x10113C30
// Name: public: CShadowMgr::CShadowMgr(void)
// Source: json
//------------------------------------------------------------------------------
CShadowMgr *__thiscall CShadowMgr::CShadowMgr(CShadowMgr *this)
{
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short> *v3; // ecx
  int m_Size; // eax

  this->ISpatialLeafEnumerator::__vftable = (ISpatialLeafEnumerator_vtbl *)&ISpatialLeafEnumerator::`vftable';
  this->IShadowMgrInternal::IShadowMgr::__vftable = (CShadowMgr_vtbl *)&CShadowMgr::`vftable'{for `IShadowMgrInternal'};
  this->ISpatialLeafEnumerator::__vftable = (ISpatialLeafEnumerator_vtbl *)&CShadowMgr::`vftable'{for `ISpatialLeafEnumerator'};
  this->m_Shadows.m_Memory.m_pMemory = nullptr;
  this->m_Shadows.m_Memory.m_nAllocationCount = 0;
  this->m_Shadows.m_Memory.m_nGrowSize = 0;
  this->m_Shadows.m_LastAlloc.index = -1;
  this->m_Shadows.m_pElements = this->m_Shadows.m_Memory.m_pMemory;
  this->m_Shadows.m_ElementCount = 0;
  this->m_Shadows.m_NumAlloced = 0;
  this->m_Shadows.m_Head = 0xFFFF;
  this->m_Shadows.m_Tail = 0xFFFF;
  this->m_Shadows.m_FirstFree = 0xFFFF;
  this->m_ShadowDecals.m_Memory.m_pMemory = nullptr;
  this->m_ShadowDecals.m_Memory.m_nAllocationCount = 0;
  this->m_ShadowDecals.m_Memory.m_nGrowSize = 0;
  this->m_ShadowDecals.m_LastAlloc.index = -1;
  this->m_ShadowDecals.m_pElements = this->m_ShadowDecals.m_Memory.m_pMemory;
  this->m_ShadowDecals.m_Head = 0xFFFF;
  this->m_ShadowDecals.m_Tail = 0xFFFF;
  this->m_ShadowDecals.m_FirstFree = 0xFFFF;
  this->m_ShadowDecals.m_ElementCount = 0;
  this->m_ShadowDecals.m_NumAlloced = 0;
  this->m_ShadowSurfaces.m_Memory.m_pBlocks = nullptr;
  this->m_ShadowSurfaces.m_Memory.m_nAllocationCount = 0;
  this->m_ShadowSurfaces.m_Memory.m_nGrowSize = 0;
  this->m_ShadowSurfaces.m_LastAlloc.m_nIndex = -1;
  this->m_ShadowSurfaces.m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_ShadowSurfaces.m_Head = 0;
  this->m_ShadowSurfaces.m_Tail = 0;
  this->m_ShadowSurfaces.m_FirstFree = 0;
  this->m_ShadowSurfaces.m_ElementCount = 0;
  this->m_ShadowSurfaces.m_NumAlloced = 0;
  this->m_ShadowSurfaces.m_pElements = nullptr;
  this->m_RenderQueue.m_Memory.m_pMemory = nullptr;
  this->m_RenderQueue.m_Memory.m_nAllocationCount = 0;
  this->m_RenderQueue.m_Memory.m_nGrowSize = 0;
  this->m_RenderQueue.m_Size = 0;
  this->m_RenderQueue.m_pElements = nullptr;
  this->m_SortOrderIds.m_Memory.m_pMemory = nullptr;
  this->m_SortOrderIds.m_Memory.m_nAllocationCount = 0;
  this->m_SortOrderIds.m_Memory.m_nGrowSize = 0;
  this->m_SortOrderIds.m_LastAlloc.index = -1;
  this->m_SortOrderIds.m_Tail = -1;
  *(_DWORD *)&this->m_SortOrderIds.m_ElementCount = 0;
  this->m_SortOrderIds.m_pElements = this->m_SortOrderIds.m_Memory.m_pMemory;
  this->m_SortOrderIds.m_Head = -1;
  this->m_SortOrderIds.m_FirstFree = -1;
  this->m_VertexCache.m_Memory.m_pMemory = nullptr;
  this->m_VertexCache.m_Memory.m_nAllocationCount = 0;
  this->m_VertexCache.m_Memory.m_nGrowSize = 0;
  this->m_VertexCache.m_LastAlloc.index = -1;
  this->m_VertexCache.m_Tail = -1;
  *(_DWORD *)&this->m_VertexCache.m_ElementCount = 0;
  this->m_VertexCache.m_pElements = this->m_VertexCache.m_Memory.m_pMemory;
  this->m_VertexCache.m_Head = -1;
  this->m_VertexCache.m_FirstFree = -1;
  this->m_TempVertexCache.m_Memory.m_pMemory = nullptr;
  this->m_TempVertexCache.m_Memory.m_nAllocationCount = 0;
  this->m_TempVertexCache.m_Memory.m_nGrowSize = 0;
  this->m_TempVertexCache.m_Size = 0;
  this->m_TempVertexCache.m_pElements = nullptr;
  this->m_SmallVertexList.m_Memory.m_pMemory = nullptr;
  this->m_SmallVertexList.m_Memory.m_nAllocationCount = 0;
  this->m_SmallVertexList.m_Memory.m_nGrowSize = 0;
  this->m_SmallVertexList.m_LastAlloc.index = -1;
  this->m_SmallVertexList.m_Tail = -1;
  *(_DWORD *)&this->m_SmallVertexList.m_ElementCount = 0;
  this->m_SmallVertexList.m_pElements = this->m_SmallVertexList.m_Memory.m_pMemory;
  this->m_SmallVertexList.m_Head = -1;
  this->m_SmallVertexList.m_FirstFree = -1;
  this->m_LargeVertexList.m_Memory.m_pMemory = nullptr;
  this->m_LargeVertexList.m_Memory.m_nAllocationCount = 0;
  this->m_LargeVertexList.m_Memory.m_nGrowSize = 0;
  this->m_LargeVertexList.m_LastAlloc.index = -1;
  this->m_LargeVertexList.m_Tail = -1;
  m_pMemory = this->m_LargeVertexList.m_Memory.m_pMemory;
  this->m_LargeVertexList.m_FirstFree = -1;
  this->m_LargeVertexList.m_Head = -1;
  *(_DWORD *)&this->m_LargeVertexList.m_ElementCount = 0;
  this->m_LargeVertexList.m_pElements = m_pMemory;
  CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>(this: &this->m_ShadowsOnModels);
  this->m_SurfaceBoundsCache.m_LastAlloc.index = -1;
  this->m_SurfaceBoundsCache.m_Head = 0xFFFF;
  this->m_SurfaceBoundsCache.m_Tail = 0xFFFF;
  this->m_SurfaceBoundsCache.m_FirstFree = 0xFFFF;
  this->m_SurfaceBoundsCache.m_ElementCount = 0;
  this->m_SurfaceBoundsCache.m_NumAlloced = 0;
  this->m_SurfaceBoundsCache.m_pElements = (UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short> *)((unsigned int)&this->m_SurfaceBoundsCache.m_Memory.m_Memory[15] & 0xFFFFFFF0);
  this->m_FlashlightStates.m_Memory.m_pMemory = nullptr;
  this->m_FlashlightStates.m_Memory.m_nAllocationCount = 0;
  this->m_FlashlightStates.m_Memory.m_nGrowSize = 0;
  this->m_FlashlightStates.m_LastAlloc.index = -1;
  this->m_FlashlightStates.m_FirstFree = -1;
  this->m_FlashlightStates.m_Tail = -1;
  this->m_FlashlightStates.m_pElements = this->m_FlashlightStates.m_Memory.m_pMemory;
  this->m_FlashlightStates.m_Head = -1;
  *(_DWORD *)&this->m_FlashlightStates.m_ElementCount = 0;
  this->m_ShadowDecalCache.m_pMemory = nullptr;
  this->m_ShadowDecalCache.m_nAllocationCount = 0;
  this->m_ShadowDecalCache.m_nGrowSize = 0;
  this->m_DispShadowDecalCache.m_pMemory = nullptr;
  this->m_DispShadowDecalCache.m_nAllocationCount = 0;
  this->m_DispShadowDecalCache.m_nGrowSize = 0;
  this->m_bStack_SinglePassFlashlightStateEnabled.m_Memory.m_pMemory = nullptr;
  this->m_bStack_SinglePassFlashlightStateEnabled.m_Memory.m_nAllocationCount = 0;
  this->m_bStack_SinglePassFlashlightStateEnabled.m_Memory.m_nGrowSize = 0;
  this->m_bStack_SinglePassFlashlightStateEnabled.m_Size = 0;
  this->m_bStack_SinglePassFlashlightStateEnabled.m_pElements = nullptr;
  this->m_ScissorStateBackups.m_Memory.m_pMemory = nullptr;
  this->m_ScissorStateBackups.m_Memory.m_nAllocationCount = 0;
  this->m_ScissorStateBackups.m_Memory.m_nGrowSize = 0;
  this->m_ScissorStateBackups.m_Size = 0;
  this->m_ScissorStateBackups.m_pElements = nullptr;
  this->m_ScissorStateEntryStart.m_Memory.m_pMemory = nullptr;
  this->m_ScissorStateEntryStart.m_Memory.m_nAllocationCount = 0;
  this->m_ScissorStateEntryStart.m_Memory.m_nGrowSize = 0;
  this->m_ScissorStateEntryStart.m_Size = 0;
  this->m_ScissorStateEntryStart.m_pElements = nullptr;
  this->m_bShadowsDisabled = false;
  CUtlLinkedList<unsigned short,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int>>>::SetGrowSize(
    this: (CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > > *)&this->m_ShadowSurfaces,
    growSize: 4096);
  CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int>>::RemoveAll(this: &this->m_ShadowDecals);
  if ( this->m_ShadowDecals.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ShadowDecals.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ShadowDecals.m_Memory.m_pMemory);
      this->m_ShadowDecals.m_Memory.m_pMemory = nullptr;
    }
    this->m_ShadowDecals.m_Memory.m_nAllocationCount = 0;
  }
  v3 = this->m_ShadowDecals.m_Memory.m_pMemory;
  this->m_ShadowDecals.m_Memory.m_nGrowSize = 4096;
  this->m_ShadowDecals.m_Memory.m_nAllocationCount = 0;
  this->m_ShadowDecals.m_pElements = v3;
  this->m_ShadowsOnModels.m_FirstBucket = FirstModelInShadow;
  this->m_ShadowsOnModels.m_FirstElement = FirstShadowOnModel;
  m_Size = this->m_RenderQueue.m_Size;
  this->m_NumWorldMaterialBuckets = 0;
  this->m_pSurfaceBounds = nullptr;
  this->m_bInitialized = false;
  this->m_hSinglePassFlashlightState = -1;
  this->m_bSinglePassFlashlightStateEnabled = false;
  this->m_nSkipShadowForEntIndex = 0x80000000;
  if ( m_Size > 0 )
    memset(dst: (unsigned __int8 *)this->m_RenderQueue.m_Memory.m_pMemory, value: 0xFFu, count: 2 * m_Size);
  this->m_DecalsToRender = 0;
  CShadowMgr::ClearAllFlashlightMaterialBuckets(this);
  this->m_ShadowDecalCache.m_nGrowSize = 4096;
  this->m_DispShadowDecalCache.m_nGrowSize = 4096;
  CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&this->m_ShadowDecalCache, num: 0x4000);
  CUtlMemory<wchar_t,int>::Grow(this: (CUtlMemory<wchar_t,int> *)&this->m_DispShadowDecalCache, num: 0x4000);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10114010
// Name: public: virtual unsigned short CShadowMgr::CreateShadowEx(class IMaterial __near *,class IMaterial __near *,void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CShadowMgr::CreateShadowEx(
        CShadowMgr *this,
        IMaterial *pMaterial,
        IMaterial *pModelMaterial,
        void *pBindProxy,
        __int16 creationFlags,
        int nEntIndex)
{
  CUtlLinkedList<CShadowMgr::Shadow_t,unsigned short,0,int,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16> > *p_m_Shadows; // edi
  int v7; // eax
  int v8; // ebx
  int v9; // eax
  int v11; // esi
  unsigned __int16 v12; // ax

  p_m_Shadows = &this->m_Shadows;
  v7 = CUtlLinkedList<CShadowMgr::Shadow_t,unsigned short,0,int,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>>::AllocInternal(
         this: &this->m_Shadows,
         multilist: false);
  v8 = v7;
  if ( v7 == 0xFFFF )
    goto LABEL_5;
  CUtlLinkedList<CShadowMgr::Shadow_t,unsigned short,0,int,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>>::LinkBefore(
    this: p_m_Shadows,
    before: 0xFFFF,
    elem: v7);
  v9 = (int)&p_m_Shadows->m_Memory.m_pMemory[v8];
  if ( v9 != 0 )
    *(_DWORD *)(v9 + 192) = 0;
  if ( (_WORD)v8 == 0xFFFF )
  {
LABEL_5:
    if ( _executeCount_1 < 10 )
    {
      ++_executeCount_1;
      _Warning(a1: "CShadowMgr::CreateShadowEx - overflowed m_Shadows linked list!\n");
    }
    return -1;
  }
  else
  {
    v11 = (int)&p_m_Shadows->m_Memory.m_pMemory[(unsigned __int16)v8];
    CShadowMgr::SetMaterial(this, shadow: (CShadowMgr::Shadow_t *)v11, pMaterial, pModelMaterial, pBindProxy);
    *(_WORD *)(v11 + 120) = creationFlags;
    *(_DWORD *)(v11 + 296) = 0;
    *(_WORD *)(v11 + 300) = -1;
    *(_DWORD *)(v11 + 96) = 0;
    *(_DWORD *)(v11 + 100) = 0;
    *(_DWORD *)(v11 + 104) = 1065353216;
    *(_DWORD *)(v11 + 76) = 0;
    *(_DWORD *)(v11 + 80) = 0;
    *(_DWORD *)(v11 + 84) = 1065353216;
    *(_DWORD *)(v11 + 88) = 1065353216;
    *(_WORD *)(v11 + 228) = 0;
    *(_BYTE *)(v11 + 92) = 0;
    *(_DWORD *)(v11 + 224) = 0;
    *(_WORD *)(v11 + 220) = -1;
    *(_DWORD *)(v11 + 304) = nEntIndex;
    if ( (creationFlags & 6) != 0 )
    {
      v12 = CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::InsertBefore(
              this: &this->m_FlashlightStates,
              before: 0xFFFFu);
      *(_WORD *)(v11 + 220) = v12;
      this->m_FlashlightStates.m_Memory.m_pMemory[v12].m_Element.m_Shadow = v8;
      this->m_FlashlightStates.m_Memory.m_pMemory[*(unsigned __int16 *)(v11 + 220)].m_Element.m_nSplitscreenOwner = 0;
      if ( !this->m_bSinglePassFlashlightStateEnabled )
        CShadowMgr::AllocFlashlightMaterialBuckets(this, flashlightID: *(_WORD *)(v11 + 220));
    }
    MatrixSetIdentity(dst: (VMatrix *)v11);
    return v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101141A0
// Name: public: virtual void CShadowMgr::DestroyShadow(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::DestroyShadow(CShadowMgr *this, unsigned __int16 handle)
{
  unsigned int v2; // ebx
  CUtlLinkedList<CShadowMgr::Shadow_t,unsigned short,0,int,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16> > *p_m_Shadows; // edi
  unsigned __int16 m_FlashlightHandle; // ax
  CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16> > *p_m_FlashlightStates; // edi
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *v7; // esi
  int elem; // [esp+Ch] [ebp-8h]
  CUtlLinkedList<CShadowMgr::Shadow_t,unsigned short,0,int,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16> > *v9; // [esp+10h] [ebp-4h]
  unsigned __int16 handlea; // [esp+1Ch] [ebp+8h]

  elem = handle;
  v2 = handle;
  p_m_Shadows = &this->m_Shadows;
  v9 = &this->m_Shadows;
  CShadowMgr::CleanupMaterial(this, shadow: &this->m_Shadows.m_Memory.m_pMemory[v2].m_Element);
  CShadowMgr::RemoveAllSurfacesFromShadow(this, handle);
  CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::RemoveElement(
    this: &this->m_ShadowsOnModels,
    element: handle);
  m_FlashlightHandle = p_m_Shadows->m_Memory.m_pMemory[v2].m_Element.m_FlashlightHandle;
  if ( m_FlashlightHandle != 0xFFFF )
  {
    p_m_FlashlightStates = &this->m_FlashlightStates;
    handlea = m_FlashlightHandle;
    CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::Unlink(
      this: &this->m_FlashlightStates,
      elem: m_FlashlightHandle);
    v7 = &this->m_FlashlightStates.m_Memory.m_pMemory[handlea];
    CMaterialsBuckets<msurface2_t *>::~CMaterialsBuckets<msurface2_t *>(this: &v7->m_Element.m_OccluderBuckets);
    CMaterialsBuckets<msurface2_t *>::~CMaterialsBuckets<msurface2_t *>(this: &v7->m_Element.m_MaterialBuckets);
    v7->m_Next = p_m_FlashlightStates->m_FirstFree;
    p_m_FlashlightStates->m_FirstFree = handlea;
    p_m_Shadows = v9;
  }
  CUtlLinkedList<CShadowMgr::Shadow_t,unsigned short,0,int,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>>::Unlink(
    this: p_m_Shadows,
    elem);
  p_m_Shadows->m_Memory.m_pMemory[v2].m_Next = p_m_Shadows->m_FirstFree;
  p_m_Shadows->m_FirstFree = elem;
}

//------------------------------------------------------------------------------
// Address: 0x10114270
// Name: public: virtual void CShadowMgr::ProjectShadow(unsigned short,class Vector const __near &,class Vector const __near &,class VMatrix const __near &,class Vector2D const __near &,int,int const __near *,float,float,float,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::ProjectShadow(
        CShadowMgr *this,
        unsigned __int16 handle,
        const Vector *origin,
        const Vector *projectionDir,
        const VMatrix *worldToShadow,
        const Vector2D *size,
        int nLeafCount,
        const int *pLeafList,
        float maxHeight,
        float falloffOffset,
        float falloffAmount,
        const Vector *vecCasterOrigin)
{
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v13; // esi
  double v14; // st6
  double y; // st5
  float v16; // xmm1_4
  float v17; // xmm0_4
  int v18; // esi
  CShadowMgr *v19; // ebx
  CShadowMgr::ShadowBuildInfo_t build; // [esp+8h] [ebp-58h] BYREF
  Vector vecEndPoint; // [esp+38h] [ebp-28h] BYREF
  Vector vecMins; // [esp+44h] [ebp-1Ch] BYREF
  Vector vecMaxs; // [esp+50h] [ebp-10h] BYREF
  CShadowMgr *v24; // [esp+5Ch] [ebp-4h]
  float flRadius; // [esp+88h] [ebp+28h]

  v24 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CShadowMgr::ProjectShadow",
    a3: 0,
    a4: "Shadow_Rendering",
    a5: false,
    a6: 4);
  CShadowMgr::RemoveAllSurfacesFromShadow(this, handle);
  CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::RemoveElement(
    this: &this->m_ShadowsOnModels,
    element: handle);
  v13 = &this->m_Shadows.m_Memory.m_pMemory[handle];
  if ( (v13->m_Element.m_Flags & 8) != 0
    || r_shadows.m_pParent == nullptr
    || r_shadows.m_pParent->m_Value.m_nValue == 0
    || this->m_bShadowsDisabled )
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    v13->m_Element.m_FalloffOffset = falloffOffset;
    v13->m_Element.m_ProjectionDir = *projectionDir;
    v13->m_Element.m_MaxDist = maxHeight;
    v13->m_Element.m_FalloffAmount = falloffAmount;
    MatrixCopy(src: worldToShadow, dst: &v13->m_Element.m_WorldToShadow);
    v14 = size->x * size->x;
    y = size->y;
    v13->m_Element.m_vecSphereCenter.x = (float)((float)(maxHeight * 0.5) * projectionDir->x) + origin->x;
    v13->m_Element.m_vecSphereCenter.y = (float)(projectionDir->y * (float)(maxHeight * 0.5)) + origin->y;
    v13->m_Element.m_vecSphereCenter.z = (float)((float)(maxHeight * 0.5) * projectionDir->z) + origin->z;
    flRadius = sqrt(y * y + v14) * 0.5;
    vecMaxs.x = flRadius;
    v13->m_Element.m_flSphereRadius = (float)(maxHeight * 0.5) + flRadius;
    LODWORD(vecMins.x) = LODWORD(flRadius) ^ _mask__NegFloat_;
    LODWORD(vecMins.y) = LODWORD(flRadius) ^ _mask__NegFloat_;
    LODWORD(vecMins.z) = LODWORD(flRadius) ^ _mask__NegFloat_;
    vecEndPoint.x = (float)(projectionDir->x * maxHeight) + origin->x;
    v16 = (float)(projectionDir->y * maxHeight) + origin->y;
    v17 = (float)(maxHeight * projectionDir->z) + origin->z;
    vecMaxs.y = flRadius;
    vecMaxs.z = flRadius;
    vecEndPoint.y = v16;
    vecEndPoint.z = v17;
    Ray_t::Init(this: &v13->m_Element.m_Ray, start: origin, end: &vecEndPoint, mins: &vecMins, maxs: &vecMaxs);
    if ( nLeafCount != 0 )
    {
      ++r_surfacevisframe;
      DispInfo_ClearAllTags(hArray: host_state.worldbrush->hDispInfos);
      build.m_RayStart = *origin;
      build.m_Shadow = handle;
      build.m_pVis = nullptr;
      build.m_vecSphereCenter = v13->m_Element.m_vecSphereCenter;
      build.m_flSphereRadius = v13->m_Element.m_flSphereRadius;
      build.m_ProjectionDirection = *projectionDir;
      v18 = 0;
      if ( nLeafCount > 0 )
      {
        v19 = v24;
        do
          CShadowMgr::EnumerateLeaf(
            this: (CShadowMgr *)&v19->ISpatialLeafEnumerator,
            leaf: pLeafList[v18++],
            context: &build);
        while ( v18 < nLeafCount );
      }
    }
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101144F0
// Name: public: virtual void CShadowMgr::ProjectFlashlight(unsigned short,class VMatrix const __near &,int,int const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::ProjectFlashlight(
        CShadowMgr *this,
        unsigned __int16 handle,
        const VMatrix *worldToShadow,
        int nLeafCount,
        const int *pLeafList)
{
  IMatRenderContext *m_pObject; // ebx
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v7; // esi
  bool v8; // zf
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *m_pMemory; // eax
  int m_FlashlightHandle; // edx
  CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short> > *p_m_UsedSortIDs; // ebx
  Vector *p_m_vecSphereCenter; // ebx
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *v13; // edx
  int v14; // esi
  IMatRenderContext *v15; // esi
  VMatrix shadowToWorld; // [esp+Ch] [ebp-78h] BYREF
  CShadowMgr::ShadowBuildInfo_t build; // [esp+4Ch] [ebp-38h] BYREF
  unsigned int v18; // [esp+7Ch] [ebp-8h]
  CMatRenderContextPtr pRenderContext; // [esp+80h] [ebp-4h]
  const VMatrix *worldToShadowa; // [esp+90h] [ebp+Ch]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CShadowMgr::ProjectFlashlight",
    a3: 0,
    a4: "Flashlight Shadows",
    a5: false,
    a6: 4);
  m_pObject = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  v7 = &this->m_Shadows.m_Memory.m_pMemory[handle];
  v8 = !this->m_bSinglePassFlashlightStateEnabled;
  v18 = 336 * handle;
  if ( v8 || m_pObject->IsCullingEnabledForSinglePassFlashlight(this: m_pObject) )
  {
    CShadowMgr::RemoveAllSurfacesFromShadow(this, handle);
    CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::RemoveElement(
      this: &this->m_ShadowsOnModels,
      element: handle);
    m_pMemory = this->m_FlashlightStates.m_Memory.m_pMemory;
    m_FlashlightHandle = v7->m_Element.m_FlashlightHandle;
    ++m_pMemory[m_FlashlightHandle].m_Element.m_OccluderBuckets.m_FlushCount;
    p_m_UsedSortIDs = &m_pMemory[m_FlashlightHandle].m_Element.m_OccluderBuckets.m_UsedSortIDs;
    CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short>,unsigned short> > *)&m_pMemory[m_FlashlightHandle].m_Element.m_OccluderBuckets.m_Elements);
    CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::RemoveAll(this: p_m_UsedSortIDs);
    m_pObject = pRenderContext.m_pObject;
  }
  if ( (this->m_Shadows.m_Memory.m_pMemory[v18 / 0x150].m_Element.m_Flags & 8) == 0
    && r_shadows.m_pParent != nullptr
    && r_shadows.m_pParent->m_Value.m_nValue != 0 )
  {
    MatrixCopy(src: worldToShadow, dst: &v7->m_Element.m_WorldToShadow);
    MatrixInverseGeneral(src: &v7->m_Element.m_WorldToShadow, dst: &shadowToWorld);
    FrustumPlanesFromMatrix(
      clipToWorld: &shadowToWorld,
      frustum: &this->m_FlashlightStates.m_Memory.m_pMemory[v7->m_Element.m_FlashlightHandle].m_Element.m_Frustum);
    p_m_vecSphereCenter = &v7->m_Element.m_vecSphereCenter;
    worldToShadowa = (const VMatrix *)&v7->m_Element.m_flSphereRadius;
    CalculateSphereFromProjectionMatrixInverse(
      volumeToWorld: &shadowToWorld,
      pCenter: &v7->m_Element.m_vecSphereCenter,
      pflRadius: &v7->m_Element.m_flSphereRadius);
    if ( nLeafCount != 0 && !this->m_bSinglePassFlashlightStateEnabled )
    {
      ++r_surfacevisframe;
      DispInfo_ClearAllTags(hArray: host_state.worldbrush->hDispInfos);
      v13 = this->m_FlashlightStates.m_Memory.m_pMemory;
      build.m_Shadow = handle;
      build.m_RayStart = v13[v7->m_Element.m_FlashlightHandle].m_Element.m_FlashlightState.m_vecLightOrigin;
      v14 = 0;
      build.m_pVis = nullptr;
      build.m_vecSphereCenter = *p_m_vecSphereCenter;
      for ( build.m_flSphereRadius = worldToShadowa->m[0][0]; v14 < nLeafCount; ++v14 )
        CShadowMgr::EnumerateLeaf(
          this: (CShadowMgr *)&this->ISpatialLeafEnumerator,
          leaf: pLeafList[v14],
          context: &build);
    }
    v15 = pRenderContext.m_pObject;
    if ( pRenderContext.m_pObject != nullptr )
    {
      pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
      v15->Release(this: v15);
    }
  }
  else if ( m_pObject != nullptr )
  {
    m_pObject->EndRender(this: m_pObject);
    m_pObject->Release(this: m_pObject);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10114730
// Name: private: virtual void CShadowMgr::RenderShadows(class IMatRenderContext __near *,class VMatrix const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::RenderShadows(
        CShadowMgr *this,
        IMatRenderContext *pRenderContext,
        const VMatrix *pModelToWorld)
{
  int i; // edi
  unsigned __int16 v5; // ax

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CShadowMgr::RenderShadows",
    a3: 0,
    a4: "Shadow_Rendering",
    a5: false,
    a6: 4);
  for ( i = 0; i < this->m_RenderQueue.m_Size; ++i )
  {
    v5 = this->m_RenderQueue.m_Memory.m_pMemory[i];
    if ( v5 != 0xFFFF )
      CShadowMgr::RenderShadowList(this, pRenderContext, decalHandle: v5, pModelToWorld);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10261A10
// Name: public: int CUtlStack<float,class CUtlMemory<float,int>>::Push(float const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlStack<float,CUtlMemory<float,int>>::Push(CUtlStack<float,CUtlMemory<float,int> > *this, float *src)
{
  float *m_pMemory; // eax
  int m_Size; // ecx
  float *v5; // eax

  if ( this->m_Size >= this->m_Memory.m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  m_Size = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v5 = &m_pMemory[m_Size - 1];
  if ( v5 != nullptr )
    *v5 = *src;
  return this->m_Size - 1;
}

//------------------------------------------------------------------------------
// Address: 0x10106F80
// Name: __CreateCShadowMgrIShadowMgr_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CShadowMgr *__cdecl _CreateCShadowMgrIShadowMgr_interface()
{
  return &s_ShadowMgr;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1000DF50
// Name: public: void Ray_t::Init(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Ray_t::Init(Ray_t *this, const Vector *start, const Vector *end)
{
  this->m_Delta.x = end->x - start->x;
  this->m_Delta.y = end->y - start->y;
  this->m_Delta.z = end->z - start->z;
  this->m_IsSwept = (float)((float)((float)(this->m_Delta.x * this->m_Delta.x)
                                  + (float)(this->m_Delta.y * this->m_Delta.y))
                          + (float)(this->m_Delta.z * this->m_Delta.z)) != 0.0;
  this->m_Extents.z = 0.0;
  this->m_Extents.y = 0.0;
  this->m_Extents.x = 0.0;
  this->m_pWorldAxisTransform = nullptr;
  this->m_IsRay = true;
  this->m_StartOffset.z = 0.0;
  this->m_StartOffset.y = 0.0;
  this->m_StartOffset.x = 0.0;
  this->m_Start.Vector = *start;
}

//------------------------------------------------------------------------------
// Address: 0x10063BD0
// Name: public: void CUtlMemory<struct CShadowMgr::FlashlightInfo_t __near *,int>::ConvertToGrowableMemory(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CShadowMgr::FlashlightInfo_t *,int>::ConvertToGrowableMemory(
        CUtlMemory<int,int> *this,
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
      this->m_pMemory = (int *)v5;
    }
    else
    {
      this->m_pMemory = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FD8F0
// Name: public: void CUtlMemoryAligned<class Frustum_t,16>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryAligned<Frustum_t,16>::Grow(CUtlMemoryAligned<Frustum_t,16> *this, int num)
{
  int m_nGrowSize; // ecx
  int m_nAllocationCount; // eax
  int v5; // edx
  Frustum_t *m_pMemory; // ecx
  unsigned int v7; // eax
  void *v8; // eax
  Frustum_t *v9; // ecx

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
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 320 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
    {
      this->m_pMemory = (Frustum_t *)MemAlloc_ReallocAligned(ptr: m_pMemory, size: v7, align: 0x10u);
    }
    else
    {
      v8 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7 + 19);
      if ( v8 != nullptr )
      {
        v9 = (Frustum_t *)(((unsigned int)v8 + 19) & 0xFFFFFFF0);
        v9[-1].planes[1].nZAbs.m128_i32[3] = (int)v8;
        this->m_pMemory = v9;
      }
      else
      {
        this->m_pMemory = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10106F40
// Name: public: ShaderStencilState_t::ShaderStencilState_t(void)
// Source: json
//------------------------------------------------------------------------------
ShaderStencilState_t *__thiscall ShaderStencilState_t::ShaderStencilState_t(ShaderStencilState_t *this)
{
  this->m_ZFailOp = SHADER_STENCILOP_KEEP;
  this->m_FailOp = SHADER_STENCILOP_KEEP;
  this->m_PassOp = SHADER_STENCILOP_KEEP;
  this->m_bEnable = false;
  this->m_CompareFunc = SHADER_STENCILFUNC_ALWAYS;
  this->m_nReferenceValue = 0;
  this->m_nWriteMask = -1;
  this->m_nTestMask = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10107010
// Name: public: virtual void CShadowMgr::DisableDropShadows(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::DisableDropShadows(CShadowMgr *this)
{
  this->m_bShadowsDisabled = true;
}

//------------------------------------------------------------------------------
// Address: 0x10107040
// Name: private: virtual void CShadowMgr::RenderProjectedTextures(class IMatRenderContext __near *,class VMatrix const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::RenderProjectedTextures(
        CShadowMgr *this,
        IMatRenderContext *pRenderContext,
        const VMatrix *pModelToWorld)
{
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CShadowMgr::RenderProjectedTextures",
    a3: 0,
    a4: "Shadow_Rendering",
    a5: false,
    a6: 4);
  this->RenderFlashlights(this, a2: true, a3: false, a4: pModelToWorld);
  this->RenderShadows(this, a2: pRenderContext, a3: pModelToWorld);
  this->ClearShadowRenderList(this);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x101070B0
// Name: ClampTexCoord
// Source: json
//------------------------------------------------------------------------------
void __fastcall ClampTexCoord(ShadowVertex_t *pOutVertex, ShadowVertex_t *pInVertex)
{
  double v2; // st7

  if ( fabs(pInVertex->m_ShadowSpaceTexCoord.x) >= 0.001 )
  {
    v2 = 1.0;
    if ( fabs(pInVertex->m_ShadowSpaceTexCoord.x - 1.0) < 0.001 )
      pOutVertex->m_ShadowSpaceTexCoord.x = 1.0;
  }
  else
  {
    v2 = 1.0;
    pOutVertex->m_ShadowSpaceTexCoord.x = 0.0;
  }
  if ( fabs(pInVertex->m_ShadowSpaceTexCoord.y) >= 0.001 )
  {
    if ( fabs(pInVertex->m_ShadowSpaceTexCoord.y - v2) < 0.001 )
      pOutVertex->m_ShadowSpaceTexCoord.y = 1.0;
  }
  else
  {
    pOutVertex->m_ShadowSpaceTexCoord.y = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10107120
// Name: private: void CShadowMgr::CopyClippedVertices(int,struct ShadowVertex_t __near * __near *,struct ShadowVertex_t __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::CopyClippedVertices(
        CShadowMgr *this,
        int count,
        ShadowVertex_t **ppSrcVert,
        ShadowVertex_t *pDstVert,
        const Vector *vToAdd)
{
  int v5; // edi
  int v6; // ebx
  ShadowVertex_t **v7; // esi
  float *p_z; // eax
  unsigned int v9; // edi
  float *v10; // edx
  float v11; // xmm1_4
  float v12; // xmm2_4
  double v13; // st7
  float *v14; // edx
  float v15; // xmm1_4
  float v16; // xmm2_4
  double v17; // st7
  float *v18; // edx
  float v19; // xmm1_4
  float v20; // xmm2_4
  double v21; // st7
  float *v22; // edx
  float v23; // xmm1_4
  float v24; // xmm2_4
  float *v25; // eax
  ShadowVertex_t *v26; // edx
  float v27; // xmm1_4
  float v28; // xmm2_4

  v5 = count;
  v6 = 0;
  if ( count >= 4 )
  {
    v7 = ppSrcVert + 2;
    p_z = &pDstVert->m_ShadowSpaceTexCoord.z;
    v9 = ((unsigned int)(count - 4) >> 2) + 1;
    v6 = 4 * v9;
    do
    {
      v10 = (float *)*(v7 - 2);
      v11 = v10[1] + vToAdd->y;
      v12 = v10[2] + vToAdd->z;
      *(p_z - 5) = vToAdd->x + *v10;
      *(p_z - 4) = v11;
      *(p_z - 3) = v12;
      *(p_z - 2) = v10[3];
      v7 += 4;
      p_z += 24;
      --v9;
      *(p_z - 25) = v10[4];
      v13 = v10[5];
      v14 = (float *)*(v7 - 5);
      *(p_z - 24) = v13;
      v15 = v14[1] + vToAdd->y;
      v16 = v14[2] + vToAdd->z;
      *(p_z - 23) = vToAdd->x + *v14;
      *(p_z - 22) = v15;
      *(p_z - 21) = v16;
      *(p_z - 20) = v14[3];
      *(p_z - 19) = v14[4];
      v17 = v14[5];
      v18 = (float *)*(v7 - 4);
      *(p_z - 18) = v17;
      v19 = v18[1] + vToAdd->y;
      v20 = v18[2] + vToAdd->z;
      *(p_z - 17) = vToAdd->x + *v18;
      *(p_z - 16) = v19;
      *(p_z - 15) = v20;
      *(p_z - 14) = v18[3];
      *(p_z - 13) = v18[4];
      v21 = v18[5];
      v22 = (float *)*(v7 - 3);
      *(p_z - 12) = v21;
      v23 = v22[1] + vToAdd->y;
      v24 = v22[2] + vToAdd->z;
      *(p_z - 11) = vToAdd->x + *v22;
      *(p_z - 10) = v23;
      *(p_z - 9) = v24;
      *(p_z - 8) = v22[3];
      *(p_z - 7) = v22[4];
      *(p_z - 6) = v22[5];
    }
    while ( v9 != 0 );
    v5 = count;
  }
  if ( v6 < v5 )
  {
    v25 = &pDstVert[v6].m_ShadowSpaceTexCoord.z;
    do
    {
      v26 = ppSrcVert[v6];
      v27 = v26->m_Position.y + vToAdd->y;
      v28 = v26->m_Position.z + vToAdd->z;
      *(v25 - 5) = vToAdd->x + v26->m_Position.x;
      *(v25 - 4) = v27;
      *(v25 - 3) = v28;
      *(v25 - 2) = v26->m_ShadowSpaceTexCoord.x;
      ++v6;
      v25 += 6;
      *(v25 - 7) = v26->m_ShadowSpaceTexCoord.y;
      *(v25 - 6) = v26->m_ShadowSpaceTexCoord.z;
    }
    while ( v6 < count );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101072D0
// Name: DrawShadowID
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawShadowID(unsigned __int16 shadowHandle, const Vector *vecCentroid)
{
  char buf[32]; // [esp+8h] [ebp-20h] BYREF

  V_snprintf(pDest: buf, maxLen: 32, pFormat: "%d", shadowHandle);
  CDebugOverlay::AddTextOverlay(textPos: vecCentroid, duration: 0.0, text: buf);
}

//------------------------------------------------------------------------------
// Address: 0x10107310
// Name: void ConstructNearAndFarPolygons(class Vector __near *,class Vector __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConstructNearAndFarPolygons(Vector *pVecNearPlane, Vector *pVecFarPlane, float flPlaneEpsilon)
{
  const CViewSetup *v3; // esi
  double v4; // st7
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm4_4
  float v15; // xmm5_4
  float v17; // xmm7_4
  float v18; // xmm6_4
  float v19; // xmm6_4
  float v20; // xmm7_4
  float v21; // xmm6_4
  float v22; // xmm4_4
  float v23; // xmm6_4
  float v24; // xmm7_4
  float v25; // xmm7_4
  float v26; // xmm6_4
  float v27; // xmm3_4
  float x; // xmm4_4
  float v29; // xmm6_4
  float v30; // xmm3_4
  float v31; // xmm5_4
  float v32; // xmm4_4
  float v33; // xmm3_4
  float v34; // xmm4_4
  float v35; // xmm5_4
  float v36; // xmm3_4
  float v37; // xmm4_4
  float v38; // xmm3_4
  float v39; // xmm4_4
  float v40; // xmm5_4
  float v41; // xmm0_4
  float v42; // xmm1_4
  float v43; // xmm2_4
  Vector vForward; // [esp+Ch] [ebp-50h] BYREF
  float v45; // [esp+24h] [ebp-38h]
  float v46; // [esp+28h] [ebp-34h]
  float v47; // [esp+2Ch] [ebp-30h]
  Vector vRight; // [esp+30h] [ebp-2Ch] BYREF
  Vector vUp; // [esp+3Ch] [ebp-20h] BYREF
  float flHalfFarWidth; // [esp+48h] [ebp-14h]
  float flHalfFarHeight; // [esp+4Ch] [ebp-10h]
  float flHalfNearHeight; // [esp+50h] [ebp-Ch]
  float flHalfNearWidth; // [esp+54h] [ebp-8h]
  float flTanHalfAngleRadians; // [esp+58h] [ebp-4h]
  float pVecNearPlanea; // [esp+64h] [ebp+8h]
  float flPlaneEpsilona; // [esp+6Ch] [ebp+10h]
  float flPlaneEpsilonb; // [esp+6Ch] [ebp+10h]

  v3 = g_EngineRenderer->ViewGetCurrent(this: g_EngineRenderer);
  v4 = CalcFovY(flFovX: v3->fov, flAspect: v3->m_flAspectRatio);
  v5 = v3->zNear + flPlaneEpsilon;
  flTanHalfAngleRadians = tan(v3->fov * 0.008726646259971648);
  flHalfNearWidth = v5 * flTanHalfAngleRadians;
  v6 = v3->zFar - flPlaneEpsilon;
  flHalfFarWidth = v6 * flTanHalfAngleRadians;
  flTanHalfAngleRadians = tan(v4 * 0.008726646259971648);
  flHalfNearHeight = v5 * flTanHalfAngleRadians;
  flHalfFarHeight = v6 * flTanHalfAngleRadians;
  AngleVectors(angles: &v3->angles, forward: &vForward, right: &vRight, up: &vUp);
  VectorNormalize(vec: &vForward);
  VectorNormalize(vec: &vRight);
  VectorNormalize(vec: &vUp);
  v7 = v3->zNear + flPlaneEpsilon;
  v8 = vForward.y * v7;
  v9 = vForward.z * v7;
  v10 = v3->origin.x + (float)(vForward.x * v7);
  v11 = v3->origin.y + v8;
  v12 = v3->origin.z + v9;
  v13 = vUp.x * flHalfNearHeight;
  v14 = vUp.y * flHalfNearHeight;
  v15 = vUp.z * flHalfNearHeight;
  v45 = vRight.x * flHalfNearWidth;
  flPlaneEpsilona = vRight.x * flHalfNearWidth;
  flTanHalfAngleRadians = vRight.y * flHalfNearWidth;
  v46 = vRight.y * flHalfNearWidth;
  flHalfNearWidth = vRight.z * flHalfNearWidth;
  v45 = (float)(v10 - v45) - (float)(vUp.x * flHalfNearHeight);
  v17 = v45;
  v46 = (float)(v11 - v46) - (float)(vUp.y * flHalfNearHeight);
  pVecNearPlane->z = (float)(v12 - flHalfNearWidth) - (float)(vUp.z * flHalfNearHeight);
  v18 = flTanHalfAngleRadians;
  pVecNearPlane->x = v17;
  v47 = flHalfNearWidth;
  vForward.x = v10 - flPlaneEpsilona;
  vForward.y = v11 - v18;
  pVecNearPlane->y = v46;
  v46 = vForward.y + v14;
  v19 = (float)(v12 - v47) + v15;
  pVecNearPlane[1].x = vForward.x + v13;
  v20 = v46;
  pVecNearPlane[1].z = v19;
  pVecNearPlane[1].y = v20;
  v45 = (float)(flPlaneEpsilona + v10) + v13;
  v21 = (float)(flTanHalfAngleRadians + v11) + v14;
  vForward.y = v14;
  v22 = (float)(flHalfNearWidth + v12) - v15;
  v46 = v21;
  v23 = (float)(flHalfNearWidth + v12) + v15;
  pVecNearPlane[2].x = v45;
  v24 = v46;
  pVecNearPlane[2].z = v23;
  pVecNearPlane[2].y = v24;
  v25 = flTanHalfAngleRadians;
  pVecNearPlane[3].z = v22;
  v26 = (float)(flPlaneEpsilona + v10) - v13;
  v27 = flHalfFarHeight;
  flPlaneEpsilonb = vUp.y * flHalfFarHeight;
  pVecNearPlanea = vUp.z * flHalfFarHeight;
  x = vRight.x;
  pVecNearPlane[3].x = v26;
  v29 = vUp.x * v27;
  v30 = flHalfFarWidth;
  flHalfNearWidth = x * flHalfFarWidth;
  v31 = x * flHalfFarWidth;
  v32 = vRight.y * flHalfFarWidth;
  flHalfNearHeight = vRight.y * flHalfFarWidth;
  pVecNearPlane[3].y = (float)(v25 + v11) - vForward.y;
  flTanHalfAngleRadians = vRight.z * v30;
  vForward.z = vRight.z * v30;
  v33 = v10 - v31;
  pVecFarPlane->y = (float)(v11 - v32) - flPlaneEpsilonb;
  v34 = flHalfNearHeight;
  pVecFarPlane->z = (float)(v12 - vForward.z) - pVecNearPlanea;
  v35 = flTanHalfAngleRadians;
  pVecFarPlane->x = v33 - v29;
  pVecFarPlane[1].x = (float)(flHalfNearWidth + v10) - v29;
  v36 = flHalfNearWidth;
  pVecFarPlane[1].y = (float)(v34 + v11) - flPlaneEpsilonb;
  v37 = flHalfNearHeight;
  pVecFarPlane[1].z = (float)(v35 + v12) - pVecNearPlanea;
  v38 = (float)(v36 + v10) + v29;
  v39 = (float)(v37 + v11) + flPlaneEpsilonb;
  v40 = (float)(flTanHalfAngleRadians + v12) + pVecNearPlanea;
  v41 = v10 - flHalfNearWidth;
  v42 = (float)(v11 - flHalfNearHeight) + flPlaneEpsilonb;
  v43 = (float)(v12 - flTanHalfAngleRadians) + pVecNearPlanea;
  pVecFarPlane[2].x = v38;
  pVecFarPlane[2].y = v39;
  pVecFarPlane[2].z = v40;
  pVecFarPlane[3].x = v41 + v29;
  pVecFarPlane[3].y = v42;
  pVecFarPlane[3].z = v43;
}

//------------------------------------------------------------------------------
// Address: 0x10107770
// Name: void DrawDebugPolygon(int,class Vector __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawDebugPolygon(int nNumVerts, Vector *pVecPoints, bool bFrontFacing, bool bNearPlane)
{
  bool v4; // cl
  int v5; // eax
  int v6; // esi
  float y; // edx
  int v8; // eax
  Vector *v9; // eax
  float v10; // edx
  int v11; // eax
  float x; // edx
  Vector *v13; // eax
  float v14; // ecx
  float z; // edx
  Vector *v16; // esi
  int v17; // edi
  float v18; // ecx
  Vector *v19; // eax
  float v20; // edx
  float v21; // eax
  Vector v0; // [esp+10h] [ebp-30h] BYREF
  Vector v1; // [esp+1Ch] [ebp-24h] BYREF
  Vector v2; // [esp+28h] [ebp-18h] BYREF
  int g; // [esp+34h] [ebp-Ch]
  int r; // [esp+38h] [ebp-8h]
  int b; // [esp+3Ch] [ebp-4h]

  v4 = bFrontFacing;
  v5 = 0;
  r = 0;
  g = 0;
  b = 0;
  if ( bFrontFacing )
    b = 255;
  else
    r = 255;
  if ( bNearPlane )
  {
    b = 0;
    r = 0;
    g = 255;
  }
  v6 = 1;
  if ( nNumVerts - 1 > 1 )
  {
    while ( 1 )
    {
      y = pVecPoints->y;
      v0.x = pVecPoints->x;
      v0.z = pVecPoints->z;
      v0.y = y;
      v8 = v6;
      if ( !v4 )
        v8 = v6 + 1;
      v9 = &pVecPoints[v8];
      v1.x = v9->x;
      v10 = v9->y;
      v1.z = v9->z;
      v1.y = v10;
      v11 = v6 + 1;
      if ( !v4 )
        v11 = v6;
      x = pVecPoints[v11].x;
      v13 = &pVecPoints[v11];
      v14 = v13->y;
      v2.x = x;
      z = v13->z;
      v2.y = v14;
      v2.z = z;
      CDebugOverlay::AddTriangleOverlay(p1: &v0, p2: &v1, p3: &v2, r, g, b, a: 20, noDepthTest: true, flDuration: 0.0);
      if ( ++v6 >= nNumVerts - 1 )
        break;
      v4 = bFrontFacing;
    }
    v5 = 0;
  }
  if ( nNumVerts > 0 )
  {
    v16 = pVecPoints;
    do
    {
      v17 = v5 + 1;
      v1 = *v16;
      v18 = pVecPoints[(v5 + 1) % nNumVerts].x;
      v19 = &pVecPoints[(v5 + 1) % nNumVerts];
      v20 = v19->y;
      v21 = v19->z;
      v0.x = v18;
      v0.y = v20;
      v0.z = v21;
      CDebugOverlay::AddLineOverlay(
        origin: &v1,
        dest: &v0,
        r: 255,
        g: 255,
        b: 255,
        a: 255,
        noDepthTest: false,
        flDuration: 0.0);
      v5 = v17;
      ++v16;
    }
    while ( v17 < nNumVerts );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101078D0
// Name: int ClipPlaneToFrustum(class Vector __near *,class Vector __near *,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ClipPlaneToFrustum(Vector *pInPoints, Vector *pOutPoints, Vector *pVecWorldFrustumPoints)
{
  int v3; // edi
  bool v4; // bl
  Vector *v5; // esi
  int v6; // eax
  int v7; // esi
  unsigned __int8 *v9; // ecx
  float fOnPlaneEpsilon; // [esp+4h] [ebp-110h]
  Vector vClipPong[10]; // [esp+14h] [ebp-100h] BYREF
  Vector vClipPing[10]; // [esp+8Ch] [ebp-88h] BYREF
  Vector vNormal; // [esp+104h] [ebp-10h] BYREF
  float flDist; // [esp+110h] [ebp-4h] BYREF
  int nNumPoints; // [esp+11Ch] [ebp+8h]

  vClipPing[0] = *pInPoints;
  vClipPing[1] = pInPoints[1];
  vClipPing[2] = pInPoints[2];
  vClipPing[3] = pInPoints[3];
  v3 = 0;
  v4 = true;
  nNumPoints = 4;
  v5 = pVecWorldFrustumPoints + 1;
  do
  {
    if ( nNumPoints < 3 )
      return 0;
    ComputeTrianglePlane(v1: v5 - 1, v2: v5, v3: v5 + 1, normal: &vNormal, intercept: &flDist);
    fOnPlaneEpsilon = 0.1;
    if ( v4 )
      v6 = ClipPolyToPlane(
             inVerts: vClipPing,
             vertCount: nNumPoints,
             outVerts: vClipPong,
             normal: &vNormal,
             dist: flDist,
             fOnPlaneEpsilon);
    else
      v6 = ClipPolyToPlane(
             inVerts: vClipPong,
             vertCount: nNumPoints,
             outVerts: vClipPing,
             normal: &vNormal,
             dist: flDist,
             fOnPlaneEpsilon);
    v4 = !v4;
    ++v3;
    v5 += 4;
    nNumPoints = v6;
  }
  while ( v3 < 6 );
  v7 = v6;
  if ( v6 < 3 )
    return 0;
  v9 = (unsigned __int8 *)vClipPing;
  if ( !v4 )
    v9 = (unsigned __int8 *)vClipPong;
  memcpy(dst: (unsigned __int8 *)pOutPoints, src: v9, count: 12 * v6);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10107A30
// Name: public: virtual void CShadowMgr::SetSinglePassFlashlightRenderState(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::SetSinglePassFlashlightRenderState(CShadowMgr *this, int handle)
{
  bool v2; // zf
  CShadowMgr_vtbl *v3; // edx

  v2 = !this->m_bSinglePassFlashlightStateEnabled;
  v3 = this->IShadowMgrInternal::IShadowMgr::__vftable;
  this->m_hSinglePassFlashlightState = handle;
  if ( v2 )
    ((void (__stdcall *)(int))v3->SetFlashlightRenderState)(a1: 0xFFFF);
  else
    ((void (__stdcall *)(int))v3->SetFlashlightRenderState)(a1: handle);
}

//------------------------------------------------------------------------------
// Address: 0x10107A60
// Name: public: virtual bool CShadowMgr::SinglePassFlashlightModeEnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShadowMgr::SinglePassFlashlightModeEnabled(CShadowMgr *this)
{
  return this->m_bSinglePassFlashlightStateEnabled;
}

//------------------------------------------------------------------------------
// Address: 0x10107C10
// Name: public: void Ray_t::Init(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Ray_t::Init(
        Ray_t *this,
        const Vector *start,
        const Vector *end,
        const Vector *mins,
        const Vector *maxs)
{
  this->m_Delta.x = end->x - start->x;
  this->m_Delta.y = end->y - start->y;
  this->m_Delta.z = end->z - start->z;
  this->m_pWorldAxisTransform = nullptr;
  this->m_IsSwept = (float)((float)((float)(this->m_Delta.x * this->m_Delta.x)
                                  + (float)(this->m_Delta.y * this->m_Delta.y))
                          + (float)(this->m_Delta.z * this->m_Delta.z)) != 0.0;
  this->m_Extents.x = maxs->x - mins->x;
  this->m_Extents.y = maxs->y - mins->y;
  this->m_Extents.z = maxs->z - mins->z;
  this->m_Extents.x = this->m_Extents.x * 0.5;
  this->m_Extents.y = this->m_Extents.y * 0.5;
  this->m_Extents.z = this->m_Extents.z * 0.5;
  this->m_IsRay = this->m_Extents.y * this->m_Extents.y
                + this->m_Extents.x * this->m_Extents.x
                + this->m_Extents.z * this->m_Extents.z < 0.000001;
  this->m_StartOffset.x = mins->x + maxs->x;
  this->m_StartOffset.y = maxs->y + mins->y;
  this->m_StartOffset.z = mins->z + maxs->z;
  this->m_StartOffset.x = this->m_StartOffset.x * 0.5;
  this->m_StartOffset.y = this->m_StartOffset.y * 0.5;
  this->m_StartOffset.z = this->m_StartOffset.z * 0.5;
  this->m_Start.x = start->x + this->m_StartOffset.x;
  this->m_Start.y = this->m_StartOffset.y + start->y;
  this->m_Start.z = this->m_StartOffset.z + start->z;
  this->m_StartOffset.x = this->m_StartOffset.x * -1.0;
  this->m_StartOffset.y = this->m_StartOffset.y * -1.0;
  this->m_StartOffset.z = this->m_StartOffset.z * -1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10107DE0
// Name: public: void CUtlMemoryAligned<struct UtlLinkedListElem_t<struct CShadowMgr::Shadow_t,unsigned short>,16>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>::Grow(
        CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16> *this,
        int num)
{
  int m_nGrowSize; // ecx
  int m_nAllocationCount; // eax
  int v5; // edx
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *m_pMemory; // ecx
  unsigned int v7; // eax
  void *v8; // eax
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v9; // ecx

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
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 336 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
    {
      this->m_pMemory = (UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *)MemAlloc_ReallocAligned(
                                                                                      ptr: m_pMemory,
                                                                                      size: v7,
                                                                                      align: 0x10u);
    }
    else
    {
      v8 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7 + 19);
      if ( v8 != nullptr )
      {
        v9 = (UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *)(((unsigned int)v8 + 19) & 0xFFFFFFF0);
        *(_DWORD *)(&v9[-1].m_Next + 5) = v8;
        this->m_pMemory = v9;
      }
      else
      {
        this->m_pMemory = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10107E70
// Name: public: void CUtlMemoryAligned<struct UtlLinkedListElem_t<struct CShadowMgr::FlashlightInfo_t,unsigned short>,16>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16>::Grow(
        CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16> *this,
        int num)
{
  int m_nGrowSize; // ecx
  int m_nAllocationCount; // eax
  int v5; // edx
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *m_pMemory; // ecx
  unsigned int v7; // eax
  void *v8; // eax
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *v9; // ecx

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
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 768 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
    {
      this->m_pMemory = (UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *)MemAlloc_ReallocAligned(
                                                                                              ptr: m_pMemory,
                                                                                              size: v7,
                                                                                              align: 0x10u);
    }
    else
    {
      v8 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7 + 19);
      if ( v8 != nullptr )
      {
        v9 = (UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *)(((unsigned int)v8 + 19) & 0xFFFFFFF0);
        *(_DWORD *)(&v9[-1].m_Next + 5) = v8;
        this->m_pMemory = v9;
      }
      else
      {
        this->m_pMemory = nullptr;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10107F00
// Name: public: int CJob::Abort(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CJob::Abort(CJob *this, BOOL bDiscard)
{
  int result; // eax
  CThreadFastMutex *p_m_mutex; // edi
  DWORD CurrentThreadId; // ecx
  bool v6; // bl
  int v7; // eax
  int m_status; // [esp+10h] [ebp+8h]

  result = this->m_status;
  if ( result == 1 || result == 2 || result == 4 )
  {
    p_m_mutex = &this->m_mutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != p_m_mutex->m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)p_m_mutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &this->m_mutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++this->m_mutex.m_depth;
    }
    this->AddRef(this);
    switch ( this->m_status )
    {
      case 1:
      case 4:
        v6 = bDiscard;
        v7 = this->DoAbort(this, a2: bDiscard);
        this->m_status = v7;
        m_status = v7;
        if ( v6 )
          this->DoCleanup(this);
        CThreadEvent::Set(this: &this->m_CompleteEvent);
        break;
      default:
        m_status = this->m_status;
        break;
    }
    this->Release(this);
    if ( this->m_mutex.m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)p_m_mutex, 0);
    return m_status;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10107FD0
// Name: private: void CShadowMgr::ComputeSurfaceBounds(struct CShadowMgr::SurfaceBounds_t __near *,struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::ComputeSurfaceBounds(
        CShadowMgr *this,
        CShadowMgr::SurfaceBounds_t *pBounds,
        msurface2_t *nSurfID)
{
  float v4; // xmm1_4
  msurface2_t *v5; // esi
  int flags_high; // edi
  int v7; // edx
  mvertex_t *vertexes; // edi
  float v9; // xmm0_4
  __m128 *v10; // ecx
  __m128 v11; // xmm0
  __m128 v12; // xmm0
  int v13; // edx
  worldbrushdata_t *worldbrush; // ecx
  mvertex_t *v15; // edi
  int v16; // esi
  float v17; // xmm0_4
  mvertex_t *v18; // edi
  float x; // xmm2_4
  float y; // xmm0_4
  float z; // xmm3_4
  float v22; // xmm0_4
  mvertex_t *v23; // edi
  float v24; // xmm2_4
  float v25; // xmm0_4
  float v26; // xmm3_4
  float v27; // xmm0_4
  mvertex_t *v28; // edi
  float v29; // xmm2_4
  float v30; // xmm0_4
  float v31; // xmm3_4
  float v32; // xmm0_4
  float m_flRadius; // xmm3_4
  mvertex_t *v34; // edi
  int v35; // esi
  float v36; // xmm0_4
  int nCount; // [esp+8h] [ebp+8h]

  v4 = 0.0;
  pBounds->m_vecCenter.x = 0.0;
  pBounds->m_vecCenter.y = 0.0;
  pBounds->m_vecCenter.z = 0.0;
  pBounds->m_vecMins = _mm_shuffle_ps((__m128)0x7F7FFFFFu, (__m128)0x7F7FFFFFu, 0);
  v5 = nSurfID;
  pBounds->m_vecMaxs = _mm_shuffle_ps((__m128)0xFF7FFFFF, (__m128)0xFF7FFFFF, 0);
  flags_high = HIBYTE(nSurfID->flags);
  v7 = 0;
  nCount = flags_high;
  if ( HIBYTE(nSurfID->flags) != 0 )
  {
    do
    {
      vertexes = host_state.worldbrush->vertexes;
      v9 = vertexes[host_state.worldbrush->vertindices[v7 + nSurfID->firstvertindex]].position.x
         + pBounds->m_vecCenter.x;
      v10 = (__m128 *)&vertexes[host_state.worldbrush->vertindices[v7 + nSurfID->firstvertindex]];
      flags_high = nCount;
      pBounds->m_vecCenter.x = v9;
      pBounds->m_vecCenter.y = v10->m128_f32[1] + pBounds->m_vecCenter.y;
      pBounds->m_vecCenter.z = v10->m128_f32[2] + pBounds->m_vecCenter.z;
      v11 = _mm_max_ps(*v10, pBounds->m_vecMaxs);
      ++v7;
      pBounds->m_vecMins = _mm_min_ps(*v10, pBounds->m_vecMins);
      pBounds->m_vecMaxs = v11;
    }
    while ( v7 < nCount );
  }
  v12 = _mm_shuffle_ps((__m128)0x3A83126Fu, (__m128)0x3A83126Fu, 0);
  pBounds->m_vecMins = _mm_and_ps(_mm_sub_ps(pBounds->m_vecMins, v12), *(__m128 *)g_SIMD_clear_wmask);
  pBounds->m_vecMaxs = _mm_and_ps(_mm_add_ps(pBounds->m_vecMaxs, v12), *(__m128 *)g_SIMD_clear_wmask);
  v12.m128_f32[0] = 1.0 / (float)flags_high;
  pBounds->m_vecCenter.x = v12.m128_f32[0] * pBounds->m_vecCenter.x;
  pBounds->m_vecCenter.y = pBounds->m_vecCenter.y * v12.m128_f32[0];
  pBounds->m_vecCenter.z = pBounds->m_vecCenter.z * v12.m128_f32[0];
  v13 = 0;
  pBounds->m_flRadius = 0.0;
  worldbrush = host_state.worldbrush;
  if ( flags_high >= 4 )
  {
    do
    {
      v15 = worldbrush->vertexes;
      v16 = worldbrush->vertindices[v13 + v5->firstvertindex];
      v17 = (float)((float)((float)(v15[v16].position.y - pBounds->m_vecCenter.y)
                          * (float)(v15[v16].position.y - pBounds->m_vecCenter.y))
                  + (float)((float)(v15[v16].position.x - pBounds->m_vecCenter.x)
                          * (float)(v15[v16].position.x - pBounds->m_vecCenter.x)))
          + (float)((float)(v15[v16].position.z - pBounds->m_vecCenter.z)
                  * (float)(v15[v16].position.z - pBounds->m_vecCenter.z));
      if ( v17 > v4 )
      {
        pBounds->m_flRadius = v17;
        worldbrush = host_state.worldbrush;
        v4 = v17;
      }
      v18 = worldbrush->vertexes;
      x = v18[worldbrush->vertindices[v13 + 1 + nSurfID->firstvertindex]].position.x;
      y = v18[worldbrush->vertindices[v13 + 1 + nSurfID->firstvertindex]].position.y;
      z = v18[worldbrush->vertindices[v13 + 1 + nSurfID->firstvertindex]].position.z;
      v22 = (float)((float)((float)(y - pBounds->m_vecCenter.y) * (float)(y - pBounds->m_vecCenter.y))
                  + (float)((float)(x - pBounds->m_vecCenter.x) * (float)(x - pBounds->m_vecCenter.x)))
          + (float)((float)(z - pBounds->m_vecCenter.z) * (float)(z - pBounds->m_vecCenter.z));
      if ( v22 > v4 )
      {
        pBounds->m_flRadius = v22;
        worldbrush = host_state.worldbrush;
        v4 = v22;
      }
      v23 = worldbrush->vertexes;
      v24 = v23[worldbrush->vertindices[v13 + 2 + nSurfID->firstvertindex]].position.x;
      v25 = v23[worldbrush->vertindices[v13 + 2 + nSurfID->firstvertindex]].position.y;
      v26 = v23[worldbrush->vertindices[v13 + 2 + nSurfID->firstvertindex]].position.z;
      v27 = (float)((float)((float)(v25 - pBounds->m_vecCenter.y) * (float)(v25 - pBounds->m_vecCenter.y))
                  + (float)((float)(v24 - pBounds->m_vecCenter.x) * (float)(v24 - pBounds->m_vecCenter.x)))
          + (float)((float)(v26 - pBounds->m_vecCenter.z) * (float)(v26 - pBounds->m_vecCenter.z));
      if ( v27 > v4 )
      {
        pBounds->m_flRadius = v27;
        worldbrush = host_state.worldbrush;
        v4 = v27;
      }
      v28 = worldbrush->vertexes;
      v29 = v28[worldbrush->vertindices[v13 + 3 + nSurfID->firstvertindex]].position.x;
      v30 = v28[worldbrush->vertindices[v13 + 3 + nSurfID->firstvertindex]].position.y;
      v31 = v28[worldbrush->vertindices[v13 + 3 + nSurfID->firstvertindex]].position.z;
      v32 = (float)((float)((float)(v30 - pBounds->m_vecCenter.y) * (float)(v30 - pBounds->m_vecCenter.y))
                  + (float)((float)(v29 - pBounds->m_vecCenter.x) * (float)(v29 - pBounds->m_vecCenter.x)))
          + (float)((float)(v31 - pBounds->m_vecCenter.z) * (float)(v31 - pBounds->m_vecCenter.z));
      if ( v32 > v4 )
      {
        pBounds->m_flRadius = v32;
        worldbrush = host_state.worldbrush;
        v4 = v32;
      }
      flags_high = nCount;
      v13 += 4;
      v5 = nSurfID;
    }
    while ( v13 < nCount - 3 );
  }
  if ( v13 < flags_high )
  {
    m_flRadius = pBounds->m_flRadius;
    while ( 1 )
    {
      v34 = worldbrush->vertexes;
      v35 = worldbrush->vertindices[v13 + v5->firstvertindex];
      v36 = (float)((float)((float)(v34[v35].position.y - pBounds->m_vecCenter.y)
                          * (float)(v34[v35].position.y - pBounds->m_vecCenter.y))
                  + (float)((float)(v34[v35].position.x - pBounds->m_vecCenter.x)
                          * (float)(v34[v35].position.x - pBounds->m_vecCenter.x)))
          + (float)((float)(v34[v35].position.z - pBounds->m_vecCenter.z)
                  * (float)(v34[v35].position.z - pBounds->m_vecCenter.z));
      if ( v36 > m_flRadius )
      {
        pBounds->m_flRadius = v36;
        worldbrush = host_state.worldbrush;
        m_flRadius = v36;
      }
      if ( ++v13 >= nCount )
        break;
      v5 = nSurfID;
    }
  }
  pBounds->m_flRadius = sqrt(pBounds->m_flRadius);
}

//------------------------------------------------------------------------------
// Address: 0x10108340
// Name: private: bool CShadowMgr::ProjectVerticesIntoShadowSpace(class VMatrix const restrict __near *,float,int,class Vector __near * restrict __near *,struct ShadowClipState_t __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShadowMgr::ProjectVerticesIntoShadowSpace(
        CShadowMgr *this,
        const VMatrix *modelToShadow,
        float maxDist,
        int count,
        Vector **ppPosition,
        ShadowClipState_t *clip)
{
  int v7; // edx
  double v9; // st7
  double v10; // st6
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm5_4
  ShadowVertex_t **v14; // edi
  float *p_y; // ecx
  Vector *v16; // eax
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  double v20; // st4
  double v21; // st5
  double v22; // rt1
  double v23; // st4
  double v24; // st5
  double v25; // st4
  double v26; // st2
  double v27; // st3
  double v28; // st5
  double v29; // st4
  bool result; // al
  float maxs; // [esp+0h] [ebp-34h]
  float maxs_4; // [esp+4h] [ebp-30h]
  float maxs_8; // [esp+8h] [ebp-2Ch]
  float mins; // [esp+Ch] [ebp-28h]
  float mins_4; // [esp+10h] [ebp-24h]
  float mins_8; // [esp+14h] [ebp-20h]
  float v37; // [esp+18h] [ebp-1Ch]
  float v38; // [esp+1Ch] [ebp-18h]
  float v39; // [esp+20h] [ebp-14h]
  float v40; // [esp+24h] [ebp-10h]
  float v41; // [esp+28h] [ebp-Ch]
  float v42; // [esp+2Ch] [ebp-8h]
  float v43; // [esp+30h] [ebp-4h]
  float modelToShadowa; // [esp+3Ch] [ebp+8h]
  float counta; // [esp+44h] [ebp+10h]

  mins = 1.0;
  mins_4 = 1.0;
  v7 = 0;
  maxs = 0.0;
  maxs_8 = 0.0;
  if ( count <= 0 )
    goto LABEL_23;
  v9 = maxDist;
  v10 = 0.0;
  v11 = modelToShadow->m[0][1];
  v12 = modelToShadow->m[0][0];
  v13 = modelToShadow->m[0][2];
  counta = modelToShadow->m[0][3];
  modelToShadowa = modelToShadow->m[1][1];
  v43 = modelToShadow->m[1][0];
  v42 = modelToShadow->m[1][2];
  v41 = modelToShadow->m[1][3];
  v40 = modelToShadow->m[2][1];
  v39 = modelToShadow->m[2][0];
  v38 = modelToShadow->m[2][2];
  v14 = clip->m_ppClipVertices[0];
  v37 = modelToShadow->m[2][3];
  p_y = &clip->m_pTempVertices[0].m_ShadowSpaceTexCoord.y;
  do
  {
    v16 = ppPosition[v7];
    x = v16->x;
    y = v16->y;
    z = v16->z;
    *(p_y - 1) = (float)((float)((float)(v11 * y) + (float)(v12 * v16->x)) + (float)(v13 * z)) + counta;
    v20 = *(p_y - 1);
    v21 = v20;
    *p_y = (float)((float)((float)(modelToShadowa * y) + (float)(v43 * x)) + (float)(v42 * z)) + v41;
    *(p_y - 3) = y;
    *(p_y - 4) = x;
    *(p_y - 2) = z;
    p_y[1] = (float)((float)((float)(v40 * y) + (float)(v39 * x)) + (float)(v38 * z)) + v37;
    if ( mins <= v20 )
      v21 = mins;
    v22 = v20;
    v23 = v21;
    v24 = v22;
    mins = v23;
    v25 = *p_y;
    if ( mins_4 <= v25 )
      v25 = mins_4;
    mins_4 = v25;
    v26 = v9;
    v9 = p_y[1];
    if ( v26 <= v9 )
      v9 = v26;
    if ( maxs >= v24 )
      v24 = maxs;
    v27 = v24;
    v28 = p_y[1];
    maxs = v27;
    v29 = v10;
    v10 = *p_y;
    if ( v29 >= v10 )
      v10 = v29;
    if ( maxs_8 >= v28 )
      v28 = maxs_8;
    *v14 = (ShadowVertex_t *)(p_y - 4);
    maxs_8 = v28;
    ++v7;
    ++v14;
    p_y += 6;
  }
  while ( v7 < count );
  if ( mins >= 1.0 || maxs <= 0.0 || mins_4 >= 1.0 || (maxs_4 = v10) <= 0.0 || (mins_8 = v9) >= maxDist || maxs_8 <= 0.0 )
LABEL_23:
    result = false;
  else
    result = true;
  clip->m_ClipCount = count;
  clip->m_TempCount = count;
  clip->m_CurrVert = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10108590
// Name: private: bool CShadowMgr::GenerateDispShadowRenderInfo(struct CShadowMgr::ShadowDecal_t __near &,struct CShadowMgr::ShadowRenderInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShadowMgr::GenerateDispShadowRenderInfo(
        CShadowMgr *this,
        CShadowMgr::ShadowDecal_t *decal,
        CShadowMgr::ShadowRenderInfo_t *info)
{
  CShadowMgr::ShadowRenderInfo_t *v3; // esi
  bool result; // al
  CShadowMgr::ShadowDecal_t *v5; // edi
  char *v6; // ecx
  char *v7; // eax
  unsigned __int16 *m_pDispCache; // edx
  int m_DispCount; // ecx

  v3 = info;
  if ( info->m_DispCount < 0x10000 )
  {
    v5 = decal;
    result = decal->m_SurfID->pDispInfo->ComputeShadowFragments(
               this: decal->m_SurfID->pDispInfo,
               a2: decal->m_DispShadow,
               a3: (int *)&info,
               a4: (int *)&decal);
    if ( result )
    {
      v6 = (char *)info + v3->m_VertexCount;
      if ( (int)v6 >= v3->m_nMaxVertices )
        return true;
      v7 = (char *)decal + v3->m_IndexCount;
      if ( (int)v7 >= v3->m_nMaxIndices )
      {
        return true;
      }
      else
      {
        m_pDispCache = v3->m_pDispCache;
        v3->m_VertexCount = (int)v6;
        m_DispCount = v3->m_DispCount;
        v3->m_IndexCount = (int)v7;
        m_pDispCache[m_DispCount] = v5->m_DispShadow;
        ++v3->m_DispCount;
        return true;
      }
    }
  }
  else
  {
    info->m_DispCount = 0x10000;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10108610
// Name: bool ScreenSpaceRectFromPoints(class IMatRenderContext __near *,class Vector (__near * const)[10],int __near *,int,int __near *,int __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __usercall ScreenSpaceRectFromPoints@<al>(
        int a1@<esi>,
        IMatRenderContext *pRenderContext,
        Vector (*vClippedPolygons)[10],
        int *pNumPoints,
        int nNumPolygons,
        int *nLeft,
        int *nTop,
        int *nRight,
        int *nBottom)
{
  int v9; // ebx
  double v11; // st7
  double v12; // st6
  double v13; // st5
  double v14; // st4
  int v15; // edx
  int v16; // edi
  float *v17; // ecx
  unsigned int v18; // esi
  float v19; // xmm0_4
  float v20; // xmm3_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  double v23; // st2
  double x; // st7
  double v25; // st3
  double v26; // st5
  double v27; // st3
  double v28; // st2
  double v29; // st6
  double v30; // rtt
  double v31; // st3
  double v32; // st4
  float v33; // xmm0_4
  float v34; // xmm3_4
  float v35; // xmm1_4
  float v36; // xmm2_4
  double v37; // st2
  double v38; // st7
  double v39; // st3
  double v40; // st5
  double v41; // st3
  double v42; // st2
  double v43; // st6
  double v44; // rtt
  double v45; // st3
  double v46; // st4
  float v47; // xmm0_4
  float v48; // xmm3_4
  float v49; // xmm1_4
  float v50; // xmm2_4
  double v51; // st2
  double v52; // st7
  double v53; // st3
  double v54; // st5
  double v55; // st3
  double v56; // st2
  double v57; // st6
  double v58; // rtt
  double v59; // st3
  double v60; // st4
  float v61; // xmm0_4
  float v62; // xmm3_4
  float v63; // xmm1_4
  float v64; // xmm2_4
  float v65; // xmm5_4
  double v66; // st2
  double v67; // st3
  double v68; // st3
  double v69; // st2
  double v70; // rtt
  double v71; // st3
  float *v72; // ecx
  int v73; // edx
  float v74; // xmm0_4
  float v75; // xmm3_4
  float v76; // xmm1_4
  float v77; // xmm2_4
  float v78; // xmm5_4
  double v79; // st2
  double v80; // st3
  double v81; // st3
  double v82; // st2
  double v83; // rt1
  double v84; // st3
  int v85; // ecx
  int v86; // edx
  float v87; // xmm3_4
  float v88; // xmm1_4
  int v89; // eax
  float v90; // xmm1_4
  int v91; // eax
  float v92; // xmm1_4
  int v93; // eax
  int v94; // eax
  int v95; // eax
  int v96; // eax
  int v97; // eax
  float v98; // xmm0_4
  float v99; // xmm1_4
  int v100; // edx
  int v101; // eax
  int v102; // eax
  bool v103; // dl
  int v104; // eax
  int v105; // ecx
  int v106; // ecx
  VMatrix matProj; // [esp+8h] [ebp-FCh] BYREF
  VMatrix matView; // [esp+48h] [ebp-BCh] BYREF
  int nViewportHeight; // [esp+88h] [ebp-7Ch]
  int nViewportWidth; // [esp+8Ch] [ebp-78h] BYREF
  int nViewportX; // [esp+90h] [ebp-74h] BYREF
  int nViewportY; // [esp+94h] [ebp-70h] BYREF
  VMatrix matViewProj; // [esp+98h] [ebp-6Ch] BYREF
  int v114; // [esp+D8h] [ebp-2Ch]
  float *p_z; // [esp+DCh] [ebp-28h]
  int nWidth; // [esp+E0h] [ebp-24h] BYREF
  float fMinX; // [esp+E4h] [ebp-20h]
  float fMinY; // [esp+E8h] [ebp-1Ch]
  int nHeight; // [esp+ECh] [ebp-18h] BYREF
  float fMaxY; // [esp+F0h] [ebp-14h]
  float fMaxX; // [esp+F4h] [ebp-10h]
  Vector vScreenSpacePoint; // [esp+F8h] [ebp-Ch]

  v9 = 0;
  if ( nNumPolygons == 0 )
    return false;
  ((void (__thiscall *)(IMatRenderContext *, _DWORD, VMatrix *, int))pRenderContext->GetMatrix_2)(
    a1: pRenderContext,
    a2: 0,
    a3: &matView,
    a4: a1);
  pRenderContext->GetMatrix_2(this: pRenderContext, a2: MATERIAL_PROJECTION, a3: &matProj);
  MatrixMultiply(src1: &matProj, src2: &matView, dst: &matViewProj);
  fMinY = 3.4028235e38;
  fMinX = 3.4028235e38;
  fMaxY = -3.4028235e38;
  fMaxX = -3.4028235e38;
  if ( nNumPolygons > 0 )
  {
    v11 = fMinX;
    v12 = fMinY;
    v13 = fMaxX;
    v114 = 0;
    v14 = fMaxY;
    p_z = &(*vClippedPolygons)[1].z;
    do
    {
      v15 = pNumPoints[v9];
      v16 = 0;
      if ( v15 >= 4 )
      {
        v17 = p_z;
        v18 = ((unsigned int)(v15 - 4) >> 2) + 1;
        v16 = 4 * v18;
        do
        {
          v19 = *(v17 - 5);
          v20 = 1.0
              / (float)((float)((float)((float)(v19 * matViewProj.m[3][0]) + (float)(*(v17 - 4) * matViewProj.m[3][1]))
                              + (float)(*(v17 - 3) * matViewProj.m[3][2]))
                      + matViewProj.m[3][3]);
          v21 = *(v17 - 4) * matViewProj.m[1][1];
          v22 = *(v17 - 3) * matViewProj.m[1][2];
          vScreenSpacePoint.x = (float)((float)((float)((float)(v19 * matViewProj.m[0][0])
                                                      + (float)(*(v17 - 4) * matViewProj.m[0][1]))
                                              + (float)(*(v17 - 3) * matViewProj.m[0][2]))
                                      + matViewProj.m[0][3])
                              * v20;
          v23 = v11;
          x = vScreenSpacePoint.x;
          vScreenSpacePoint.y = (float)((float)((float)((float)(v19 * matViewProj.m[1][0]) + v21) + v22)
                                      + matViewProj.m[1][3])
                              * v20;
          if ( v23 <= vScreenSpacePoint.x )
            x = v23;
          v25 = v13;
          v26 = vScreenSpacePoint.x;
          if ( v25 >= vScreenSpacePoint.x )
            v26 = v25;
          v27 = -vScreenSpacePoint.y;
          v28 = v12;
          v29 = v27;
          if ( v28 <= v27 )
            v29 = v28;
          v30 = v27;
          v31 = v14;
          v32 = v30;
          if ( v31 >= v30 )
            v32 = v31;
          v33 = *(v17 - 2);
          v34 = 1.0
              / (float)((float)((float)((float)(v33 * matViewProj.m[3][0]) + (float)(*(v17 - 1) * matViewProj.m[3][1]))
                              + (float)(*v17 * matViewProj.m[3][2]))
                      + matViewProj.m[3][3]);
          v35 = *(v17 - 1) * matViewProj.m[1][1];
          v36 = *v17 * matViewProj.m[1][2];
          vScreenSpacePoint.x = (float)((float)((float)((float)(*(v17 - 1) * matViewProj.m[0][1])
                                                      + (float)(v33 * matViewProj.m[0][0]))
                                              + (float)(*v17 * matViewProj.m[0][2]))
                                      + matViewProj.m[0][3])
                              * v34;
          v37 = x;
          v38 = vScreenSpacePoint.x;
          vScreenSpacePoint.y = (float)((float)((float)((float)(v33 * matViewProj.m[1][0]) + v35) + v36)
                                      + matViewProj.m[1][3])
                              * v34;
          if ( v37 <= vScreenSpacePoint.x )
            v38 = v37;
          v39 = v26;
          v40 = vScreenSpacePoint.x;
          if ( v39 >= vScreenSpacePoint.x )
            v40 = v39;
          v41 = -vScreenSpacePoint.y;
          v42 = v29;
          v43 = v41;
          if ( v42 <= v41 )
            v43 = v42;
          v44 = v41;
          v45 = v32;
          v46 = v44;
          if ( v45 >= v44 )
            v46 = v45;
          v47 = v17[1];
          v48 = 1.0
              / (float)((float)((float)((float)(v47 * matViewProj.m[3][0]) + (float)(v17[2] * matViewProj.m[3][1]))
                              + (float)(v17[3] * matViewProj.m[3][2]))
                      + matViewProj.m[3][3]);
          v49 = v17[2] * matViewProj.m[1][1];
          v50 = v17[3] * matViewProj.m[1][2];
          vScreenSpacePoint.x = (float)((float)((float)((float)(v47 * matViewProj.m[0][0])
                                                      + (float)(v17[2] * matViewProj.m[0][1]))
                                              + (float)(v17[3] * matViewProj.m[0][2]))
                                      + matViewProj.m[0][3])
                              * v48;
          v51 = v38;
          v52 = vScreenSpacePoint.x;
          vScreenSpacePoint.y = (float)((float)((float)((float)(v47 * matViewProj.m[1][0]) + v49) + v50)
                                      + matViewProj.m[1][3])
                              * v48;
          if ( v51 <= vScreenSpacePoint.x )
            v52 = v51;
          v53 = v40;
          v54 = vScreenSpacePoint.x;
          if ( v53 >= vScreenSpacePoint.x )
            v54 = v53;
          v55 = -vScreenSpacePoint.y;
          v56 = v43;
          v57 = v55;
          if ( v56 <= v55 )
            v57 = v56;
          v58 = v55;
          v59 = v46;
          v60 = v58;
          if ( v59 >= v58 )
            v60 = v59;
          v61 = v17[4];
          v62 = 1.0
              / (float)((float)((float)((float)(v61 * matViewProj.m[3][0]) + (float)(v17[5] * matViewProj.m[3][1]))
                              + (float)(v17[6] * matViewProj.m[3][2]))
                      + matViewProj.m[3][3]);
          v63 = v17[5] * matViewProj.m[1][1];
          v64 = v17[6] * matViewProj.m[1][2];
          v65 = (float)((float)((float)((float)(v61 * matViewProj.m[0][0]) + (float)(v17[5] * matViewProj.m[0][1]))
                              + (float)(v17[6] * matViewProj.m[0][2]))
                      + matViewProj.m[0][3])
              * v62;
          vScreenSpacePoint.x = v65;
          v66 = v52;
          v11 = v65;
          vScreenSpacePoint.y = (float)((float)((float)((float)(v61 * matViewProj.m[1][0]) + v63) + v64)
                                      + matViewProj.m[1][3])
                              * v62;
          if ( v66 <= v65 )
            v11 = v66;
          v67 = v54;
          v13 = v65;
          if ( v67 >= v65 )
            v13 = v67;
          v68 = -vScreenSpacePoint.y;
          v69 = v57;
          v12 = v68;
          if ( v69 <= v68 )
            v12 = v69;
          v70 = v68;
          v71 = v60;
          v14 = v70;
          if ( v71 >= v70 )
            v14 = v71;
          v17 += 12;
          --v18;
        }
        while ( v18 != 0 );
        fMaxY = v14;
        fMinY = v12;
        fMaxX = v13;
        fMinX = v11;
      }
      if ( v16 < v15 )
      {
        v72 = &(*vClippedPolygons)[v16 + v114].z;
        v73 = v15 - v16;
        do
        {
          v74 = *(v72 - 2);
          v75 = 1.0
              / (float)((float)((float)((float)(v74 * matViewProj.m[3][0]) + (float)(*(v72 - 1) * matViewProj.m[3][1]))
                              + (float)(*v72 * matViewProj.m[3][2]))
                      + matViewProj.m[3][3]);
          v76 = *(v72 - 1) * matViewProj.m[1][1];
          v77 = *v72 * matViewProj.m[1][2];
          v78 = (float)((float)((float)((float)(*(v72 - 1) * matViewProj.m[0][1]) + (float)(v74 * matViewProj.m[0][0]))
                              + (float)(*v72 * matViewProj.m[0][2]))
                      + matViewProj.m[0][3])
              * v75;
          vScreenSpacePoint.x = v78;
          v79 = v11;
          v11 = v78;
          vScreenSpacePoint.y = (float)((float)((float)((float)(v74 * matViewProj.m[1][0]) + v76) + v77)
                                      + matViewProj.m[1][3])
                              * v75;
          if ( v79 <= v78 )
            v11 = v79;
          v80 = v13;
          v13 = v78;
          if ( v80 >= v78 )
            v13 = v80;
          v81 = -vScreenSpacePoint.y;
          v82 = v12;
          v12 = v81;
          if ( v82 <= v81 )
            v12 = v82;
          v83 = v81;
          v84 = v14;
          v14 = v83;
          if ( v84 >= v83 )
            v14 = v84;
          v72 += 3;
          --v73;
        }
        while ( v73 != 0 );
        fMaxY = v14;
        fMinY = v12;
        fMaxX = v13;
        fMinX = v11;
      }
      p_z += 30;
      v114 += 10;
      ++v9;
    }
    while ( v9 < nNumPolygons );
  }
  g_pMaterialSystem->GetBackBufferDimensions(this: g_pMaterialSystem, a2: &nWidth, a3: &nHeight);
  v85 = nWidth;
  v86 = nHeight;
  v87 = (float)nWidth;
  v88 = (float)(fMinY + 1.0) * 0.5;
  *nLeft = (int)(float)((float)((float)((float)(fMinX + 1.0) * 0.5) * (float)nWidth) - 1.0);
  v89 = (int)(float)((float)(v88 * (float)v86) - 1.0);
  v90 = (float)((float)((float)(fMaxX + 1.0) * 0.5) * v87) + 1.0;
  *nTop = v89;
  v91 = (int)v90;
  v92 = fMaxY + 1.0;
  *nRight = v91;
  *nBottom = (int)(float)((float)((float)(v92 * 0.5) * (float)v86) + 1.0);
  v93 = *nLeft;
  if ( *nLeft >= 0 )
  {
    if ( v93 > v85 )
      v93 = v85;
  }
  else
  {
    v93 = 0;
  }
  *nLeft = v93;
  v94 = *nTop;
  if ( *nTop >= 0 )
  {
    if ( v94 > v86 )
      v94 = v86;
  }
  else
  {
    v94 = 0;
  }
  *nTop = v94;
  v95 = *nRight;
  if ( *nRight >= 0 )
  {
    if ( v95 > v85 )
      v95 = v85;
  }
  else
  {
    v95 = 0;
  }
  *nRight = v95;
  v96 = *nBottom;
  if ( *nBottom >= 0 )
  {
    if ( v96 > nHeight )
      v96 = nHeight;
  }
  else
  {
    v96 = 0;
  }
  *nBottom = v96;
  ((void (__thiscall *)(IMatRenderContext *, int *, int *, int *))pRenderContext->GetViewport)(
    a1: pRenderContext,
    a2: &nViewportX,
    a3: &nViewportY,
    a4: &nViewportWidth);
  v97 = nViewportX;
  v98 = (float)nViewportWidth / (float)nWidth;
  v99 = (float)nViewportHeight / (float)nHeight;
  *nLeft = nViewportX + (int)(float)((float)*nLeft * v98);
  v100 = v97 + (int)(float)((float)*nRight * v98);
  v101 = nViewportY;
  *nRight = v100;
  *nTop = v101 + (int)(float)((float)*nTop * v99);
  v102 = (int)(float)((float)*nBottom * v99) + v101;
  *nBottom = v102;
  v103 = *nLeft > 0 || *nTop > 0 || *nRight < nWidth || v102 < nHeight;
  v104 = v102 - *nTop;
  v105 = *nRight - *nLeft;
  if ( v105 <= 0 || v104 <= 0 )
    v106 = 0;
  else
    v106 = v104 * v105;
  return v103 && v106 > 0;
}

//------------------------------------------------------------------------------
// Address: 0x10108D40
// Name: ShadowClip_CClipTop_
// Source: json
//------------------------------------------------------------------------------
void __usercall ShadowClip_CClipTop_(ShadowClipState_t *clip@<esi>)
{
  int m_ClipCount; // ecx
  int v2; // edi
  ShadowVertex_t **v3; // edx
  float *p_x; // ecx
  ShadowVertex_t **v5; // ebx
  float *v6; // eax
  int v7; // edx
  float *v8; // edx
  float v9; // xmm0_4
  int m_TempCount; // edx
  float *v11; // edx
  float v12; // xmm0_4
  int v13; // eax
  ShadowVertex_t **pSrcVert; // [esp+0h] [ebp-10h]
  int v15; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  bool endInside; // [esp+Eh] [ebp-2h]
  bool startInside; // [esp+Fh] [ebp-1h]

  m_ClipCount = clip->m_ClipCount;
  v15 = m_ClipCount;
  if ( m_ClipCount != 0 )
  {
    v2 = 0;
    v3 = clip->m_ppClipVertices[clip->m_CurrVert];
    p_x = &v3[m_ClipCount - 1]->m_Position.x;
    pSrcVert = v3;
    v5 = clip->m_ppClipVertices[clip->m_CurrVert == 0];
    startInside = p_x[4] < 1.0;
    i = 0;
    if ( v15 > 0 )
    {
      while ( 1 )
      {
        v6 = &v3[i]->m_Position.x;
        if ( v6[4] >= 1.0 )
        {
          endInside = false;
          if ( !startInside )
            goto LABEL_14;
          m_TempCount = clip->m_TempCount;
          if ( m_TempCount >= 48 )
            return;
          v5[v2] = &clip->m_pTempVertices[m_TempCount];
          ++clip->m_TempCount;
          v11 = &v5[v2]->m_Position.x;
          v12 = (float)(1.0 - p_x[4]) / (float)(v6[4] - p_x[4]);
          v11[3] = (float)((float)(v6[3] - p_x[3]) * v12) + p_x[3];
          v11[4] = (float)((float)(v6[4] - p_x[4]) * v12) + p_x[4];
          v11[5] = (float)((float)(v6[5] - p_x[5]) * v12) + p_x[5];
          *v11 = (float)((float)(*v6 - *p_x) * v12) + *p_x;
          v11[1] = (float)((float)(v6[1] - p_x[1]) * v12) + p_x[1];
          v11[2] = (float)((float)(v6[2] - p_x[2]) * v12) + p_x[2];
        }
        else
        {
          endInside = true;
          if ( !startInside )
          {
            v7 = clip->m_TempCount;
            if ( v7 >= 48 )
              return;
            v5[v2] = &clip->m_pTempVertices[v7];
            ++clip->m_TempCount;
            v8 = &v5[v2]->m_Position.x;
            v9 = (float)(1.0 - p_x[4]) / (float)(v6[4] - p_x[4]);
            v8[3] = (float)((float)(v6[3] - p_x[3]) * v9) + p_x[3];
            v8[4] = (float)((float)(v6[4] - p_x[4]) * v9) + p_x[4];
            v8[5] = (float)((float)(v6[5] - p_x[5]) * v9) + p_x[5];
            *v8 = (float)((float)(*v6 - *p_x) * v9) + *p_x;
            v8[1] = (float)((float)(v6[1] - p_x[1]) * v9) + p_x[1];
            v8[2] = (float)((float)(v6[2] - p_x[2]) * v9) + p_x[2];
            ++v2;
          }
          v5[v2] = (ShadowVertex_t *)v6;
        }
        ++v2;
LABEL_14:
        ++i;
        p_x = v6;
        startInside = endInside;
        if ( i >= v15 )
          break;
        v3 = pSrcVert;
      }
    }
    v13 = 1 - clip->m_CurrVert;
    clip->m_ClipCount = v2;
    clip->m_CurrVert = v13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10108F90
// Name: ShadowClip_CClipBottom_
// Source: json
//------------------------------------------------------------------------------
void __usercall ShadowClip_CClipBottom_(ShadowClipState_t *clip@<esi>)
{
  int m_ClipCount; // ecx
  int v2; // edi
  ShadowVertex_t **v3; // edx
  float *p_x; // ecx
  ShadowVertex_t **v5; // ebx
  float *v6; // eax
  int v7; // edx
  float *v8; // edx
  float v9; // xmm0_4
  int m_TempCount; // edx
  float *v11; // edx
  float v12; // xmm0_4
  int v13; // eax
  ShadowVertex_t **pSrcVert; // [esp+0h] [ebp-10h]
  int v15; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  bool endInside; // [esp+Eh] [ebp-2h]
  bool startInside; // [esp+Fh] [ebp-1h]

  m_ClipCount = clip->m_ClipCount;
  v15 = m_ClipCount;
  if ( m_ClipCount != 0 )
  {
    v2 = 0;
    v3 = clip->m_ppClipVertices[clip->m_CurrVert];
    p_x = &v3[m_ClipCount - 1]->m_Position.x;
    pSrcVert = v3;
    v5 = clip->m_ppClipVertices[clip->m_CurrVert == 0];
    startInside = p_x[4] > 0.0;
    i = 0;
    if ( v15 > 0 )
    {
      while ( 1 )
      {
        v6 = &v3[i]->m_Position.x;
        if ( v6[4] <= 0.0 )
        {
          endInside = false;
          if ( !startInside )
            goto LABEL_14;
          m_TempCount = clip->m_TempCount;
          if ( m_TempCount >= 48 )
            return;
          v5[v2] = &clip->m_pTempVertices[m_TempCount];
          ++clip->m_TempCount;
          v11 = &v5[v2]->m_Position.x;
          v12 = p_x[4] / (float)(p_x[4] - v6[4]);
          v11[3] = (float)((float)(v6[3] - p_x[3]) * v12) + p_x[3];
          v11[4] = (float)((float)(v6[4] - p_x[4]) * v12) + p_x[4];
          v11[5] = (float)((float)(v6[5] - p_x[5]) * v12) + p_x[5];
          *v11 = (float)((float)(*v6 - *p_x) * v12) + *p_x;
          v11[1] = (float)((float)(v6[1] - p_x[1]) * v12) + p_x[1];
          v11[2] = (float)((float)(v6[2] - p_x[2]) * v12) + p_x[2];
        }
        else
        {
          endInside = true;
          if ( !startInside )
          {
            v7 = clip->m_TempCount;
            if ( v7 >= 48 )
              return;
            v5[v2] = &clip->m_pTempVertices[v7];
            ++clip->m_TempCount;
            v8 = &v5[v2]->m_Position.x;
            v9 = p_x[4] / (float)(p_x[4] - v6[4]);
            v8[3] = (float)((float)(v6[3] - p_x[3]) * v9) + p_x[3];
            v8[4] = (float)((float)(v6[4] - p_x[4]) * v9) + p_x[4];
            v8[5] = (float)((float)(v6[5] - p_x[5]) * v9) + p_x[5];
            *v8 = (float)((float)(*v6 - *p_x) * v9) + *p_x;
            v8[1] = (float)((float)(v6[1] - p_x[1]) * v9) + p_x[1];
            v8[2] = (float)((float)(v6[2] - p_x[2]) * v9) + p_x[2];
            ++v2;
          }
          v5[v2] = (ShadowVertex_t *)v6;
        }
        ++v2;
LABEL_14:
        ++i;
        p_x = v6;
        startInside = endInside;
        if ( i >= v15 )
          break;
        v3 = pSrcVert;
      }
    }
    v13 = 1 - clip->m_CurrVert;
    clip->m_ClipCount = v2;
    clip->m_CurrVert = v13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101091D0
// Name: ShadowClip_CClipLeft_
// Source: json
//------------------------------------------------------------------------------
void __usercall ShadowClip_CClipLeft_(ShadowClipState_t *clip@<esi>)
{
  int m_ClipCount; // ecx
  int v2; // edi
  ShadowVertex_t **v3; // edx
  float *p_x; // ecx
  ShadowVertex_t **v5; // ebx
  float *v6; // eax
  int v7; // edx
  float v8; // xmm2_4
  float v9; // xmm1_4
  float *v10; // edx
  float v11; // xmm0_4
  int m_TempCount; // edx
  float v13; // xmm2_4
  float v14; // xmm1_4
  float *v15; // edx
  float v16; // xmm0_4
  int v17; // eax
  ShadowVertex_t **pSrcVert; // [esp+0h] [ebp-10h]
  int v19; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  bool endInside; // [esp+Eh] [ebp-2h]
  bool startInside; // [esp+Fh] [ebp-1h]

  m_ClipCount = clip->m_ClipCount;
  v19 = m_ClipCount;
  if ( m_ClipCount != 0 )
  {
    v2 = 0;
    v3 = clip->m_ppClipVertices[clip->m_CurrVert];
    p_x = &v3[m_ClipCount - 1]->m_Position.x;
    pSrcVert = v3;
    v5 = clip->m_ppClipVertices[clip->m_CurrVert == 0];
    startInside = p_x[3] > 0.0;
    i = 0;
    if ( v19 > 0 )
    {
      while ( 1 )
      {
        v6 = &v3[i]->m_Position.x;
        if ( v6[3] <= 0.0 )
        {
          endInside = false;
          if ( !startInside )
            goto LABEL_14;
          m_TempCount = clip->m_TempCount;
          if ( m_TempCount >= 48 )
            return;
          v5[v2] = &clip->m_pTempVertices[m_TempCount];
          ++clip->m_TempCount;
          v13 = p_x[3];
          v14 = v6[3];
          v15 = &v5[v2]->m_Position.x;
          v16 = v13 / (float)(v13 - v14);
          v15[3] = (float)((float)(v14 - v13) * v16) + v13;
          v15[4] = (float)((float)(v6[4] - p_x[4]) * v16) + p_x[4];
          v15[5] = (float)((float)(v6[5] - p_x[5]) * v16) + p_x[5];
          *v15 = (float)((float)(*v6 - *p_x) * v16) + *p_x;
          v15[1] = (float)((float)(v6[1] - p_x[1]) * v16) + p_x[1];
          v15[2] = (float)((float)(v6[2] - p_x[2]) * v16) + p_x[2];
        }
        else
        {
          endInside = true;
          if ( !startInside )
          {
            v7 = clip->m_TempCount;
            if ( v7 >= 48 )
              return;
            v5[v2] = &clip->m_pTempVertices[v7];
            ++clip->m_TempCount;
            v8 = p_x[3];
            v9 = v6[3];
            v10 = &v5[v2]->m_Position.x;
            v11 = v8 / (float)(v8 - v9);
            v10[3] = (float)((float)(v9 - v8) * v11) + v8;
            v10[4] = (float)((float)(v6[4] - p_x[4]) * v11) + p_x[4];
            v10[5] = (float)((float)(v6[5] - p_x[5]) * v11) + p_x[5];
            *v10 = (float)((float)(*v6 - *p_x) * v11) + *p_x;
            v10[1] = (float)((float)(v6[1] - p_x[1]) * v11) + p_x[1];
            v10[2] = (float)((float)(v6[2] - p_x[2]) * v11) + p_x[2];
            ++v2;
          }
          v5[v2] = (ShadowVertex_t *)v6;
        }
        ++v2;
LABEL_14:
        ++i;
        p_x = v6;
        startInside = endInside;
        if ( i >= v19 )
          break;
        v3 = pSrcVert;
      }
    }
    v17 = 1 - clip->m_CurrVert;
    clip->m_ClipCount = v2;
    clip->m_CurrVert = v17;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109410
// Name: ShadowClip_CClipRight_
// Source: json
//------------------------------------------------------------------------------
void __usercall ShadowClip_CClipRight_(ShadowClipState_t *clip@<esi>)
{
  int m_ClipCount; // ecx
  int v2; // edi
  ShadowVertex_t **v3; // edx
  float *p_x; // ecx
  ShadowVertex_t **v5; // ebx
  float *v6; // eax
  int v7; // edx
  float v8; // xmm2_4
  float *v9; // edx
  float v10; // xmm1_4
  float v11; // xmm0_4
  int m_TempCount; // edx
  float v13; // xmm2_4
  float *v14; // edx
  float v15; // xmm1_4
  float v16; // xmm0_4
  int v17; // eax
  ShadowVertex_t **pSrcVert; // [esp+0h] [ebp-10h]
  int v19; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  bool endInside; // [esp+Eh] [ebp-2h]
  bool startInside; // [esp+Fh] [ebp-1h]

  m_ClipCount = clip->m_ClipCount;
  v19 = m_ClipCount;
  if ( m_ClipCount != 0 )
  {
    v2 = 0;
    v3 = clip->m_ppClipVertices[clip->m_CurrVert];
    p_x = &v3[m_ClipCount - 1]->m_Position.x;
    pSrcVert = v3;
    v5 = clip->m_ppClipVertices[clip->m_CurrVert == 0];
    startInside = p_x[3] < 1.0;
    i = 0;
    if ( v19 > 0 )
    {
      while ( 1 )
      {
        v6 = &v3[i]->m_Position.x;
        if ( v6[3] >= 1.0 )
        {
          endInside = false;
          if ( !startInside )
            goto LABEL_14;
          m_TempCount = clip->m_TempCount;
          if ( m_TempCount >= 48 )
            return;
          v5[v2] = &clip->m_pTempVertices[m_TempCount];
          ++clip->m_TempCount;
          v13 = p_x[3];
          v14 = &v5[v2]->m_Position.x;
          v15 = v6[3] - v13;
          v16 = (float)(1.0 - v13) / v15;
          v14[3] = (float)(v15 * v16) + v13;
          v14[4] = (float)((float)(v6[4] - p_x[4]) * v16) + p_x[4];
          v14[5] = (float)((float)(v6[5] - p_x[5]) * v16) + p_x[5];
          *v14 = (float)((float)(*v6 - *p_x) * v16) + *p_x;
          v14[1] = (float)((float)(v6[1] - p_x[1]) * v16) + p_x[1];
          v14[2] = (float)((float)(v6[2] - p_x[2]) * v16) + p_x[2];
        }
        else
        {
          endInside = true;
          if ( !startInside )
          {
            v7 = clip->m_TempCount;
            if ( v7 >= 48 )
              return;
            v5[v2] = &clip->m_pTempVertices[v7];
            ++clip->m_TempCount;
            v8 = p_x[3];
            v9 = &v5[v2]->m_Position.x;
            v10 = v6[3] - v8;
            v11 = (float)(1.0 - v8) / v10;
            v9[3] = (float)(v10 * v11) + v8;
            v9[4] = (float)((float)(v6[4] - p_x[4]) * v11) + p_x[4];
            v9[5] = (float)((float)(v6[5] - p_x[5]) * v11) + p_x[5];
            *v9 = (float)((float)(*v6 - *p_x) * v11) + *p_x;
            v9[1] = (float)((float)(v6[1] - p_x[1]) * v11) + p_x[1];
            v9[2] = (float)((float)(v6[2] - p_x[2]) * v11) + p_x[2];
            ++v2;
          }
          v5[v2] = (ShadowVertex_t *)v6;
        }
        ++v2;
LABEL_14:
        ++i;
        p_x = v6;
        startInside = endInside;
        if ( i >= v19 )
          break;
        v3 = pSrcVert;
      }
    }
    v17 = 1 - clip->m_CurrVert;
    clip->m_ClipCount = v2;
    clip->m_CurrVert = v17;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109650
// Name: ShadowClip_CClipAbove_
// Source: json
//------------------------------------------------------------------------------
void __usercall ShadowClip_CClipAbove_(ShadowClipState_t *clip@<edi>)
{
  ShadowVertex_t **v1; // edx
  int v2; // ebx
  ShadowVertex_t **v3; // ecx
  ShadowVertex_t *v4; // esi
  ShadowVertex_t *v5; // eax
  int v6; // edx
  ShadowVertex_t *v7; // ecx
  float v8; // xmm2_4
  float *v9; // ecx
  int m_TempCount; // edx
  ShadowVertex_t *v11; // ecx
  float v12; // xmm2_4
  float *v13; // ecx
  int v14; // eax
  ShadowVertex_t **pSrcVert; // [esp+0h] [ebp-14h]
  ShadowVertex_t **pDestVert; // [esp+4h] [ebp-10h]
  int m_ClipCount; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]
  bool endInside; // [esp+12h] [ebp-2h]
  bool startInside; // [esp+13h] [ebp-1h]

  m_ClipCount = clip->m_ClipCount;
  if ( m_ClipCount != 0 )
  {
    v1 = clip->m_ppClipVertices[clip->m_CurrVert];
    v2 = 0;
    pSrcVert = v1;
    v3 = clip->m_ppClipVertices[clip->m_CurrVert == 0];
    v4 = v1[m_ClipCount - 1];
    pDestVert = v3;
    startInside = v4->m_ShadowSpaceTexCoord.z > 0.0;
    i = 0;
    if ( m_ClipCount > 0 )
    {
      while ( 1 )
      {
        v5 = v1[i];
        if ( v5->m_ShadowSpaceTexCoord.z <= 0.0 )
        {
          endInside = false;
          if ( !startInside )
            goto LABEL_14;
          m_TempCount = clip->m_TempCount;
          if ( m_TempCount >= 48 )
            return;
          v3[v2] = &clip->m_pTempVertices[m_TempCount];
          ++clip->m_TempCount;
          v11 = v3[v2];
          v12 = v4->m_ShadowSpaceTexCoord.z / (float)(v4->m_ShadowSpaceTexCoord.z - v5->m_ShadowSpaceTexCoord.z);
          v11->m_ShadowSpaceTexCoord.x = (float)((float)(v5->m_ShadowSpaceTexCoord.x - v4->m_ShadowSpaceTexCoord.x) * v12)
                                       + v4->m_ShadowSpaceTexCoord.x;
          v11->m_ShadowSpaceTexCoord.y = (float)((float)(v5->m_ShadowSpaceTexCoord.y - v4->m_ShadowSpaceTexCoord.y) * v12)
                                       + v4->m_ShadowSpaceTexCoord.y;
          v11->m_ShadowSpaceTexCoord.z = (float)((float)(v5->m_ShadowSpaceTexCoord.z - v4->m_ShadowSpaceTexCoord.z) * v12)
                                       + v4->m_ShadowSpaceTexCoord.z;
          ClampTexCoord(pOutVertex: v11, pInVertex: v5);
          *v13 = (float)((float)(v5->m_Position.x - v4->m_Position.x) * v12) + v4->m_Position.x;
          v13[1] = (float)((float)(v5->m_Position.y - v4->m_Position.y) * v12) + v4->m_Position.y;
          v13[2] = (float)((float)(v5->m_Position.z - v4->m_Position.z) * v12) + v4->m_Position.z;
          v3 = pDestVert;
        }
        else
        {
          endInside = true;
          if ( !startInside )
          {
            v6 = clip->m_TempCount;
            if ( v6 >= 48 )
              return;
            v3[v2] = &clip->m_pTempVertices[v6];
            ++clip->m_TempCount;
            v7 = v3[v2];
            v8 = v4->m_ShadowSpaceTexCoord.z / (float)(v4->m_ShadowSpaceTexCoord.z - v5->m_ShadowSpaceTexCoord.z);
            v7->m_ShadowSpaceTexCoord.x = (float)((float)(v5->m_ShadowSpaceTexCoord.x - v4->m_ShadowSpaceTexCoord.x) * v8)
                                        + v4->m_ShadowSpaceTexCoord.x;
            v7->m_ShadowSpaceTexCoord.y = (float)((float)(v5->m_ShadowSpaceTexCoord.y - v4->m_ShadowSpaceTexCoord.y) * v8)
                                        + v4->m_ShadowSpaceTexCoord.y;
            v7->m_ShadowSpaceTexCoord.z = (float)((float)(v5->m_ShadowSpaceTexCoord.z - v4->m_ShadowSpaceTexCoord.z) * v8)
                                        + v4->m_ShadowSpaceTexCoord.z;
            ClampTexCoord(pOutVertex: v7, pInVertex: v4);
            *v9 = (float)((float)(v5->m_Position.x - v4->m_Position.x) * v8) + v4->m_Position.x;
            v9[1] = (float)((float)(v5->m_Position.y - v4->m_Position.y) * v8) + v4->m_Position.y;
            v9[2] = (float)((float)(v5->m_Position.z - v4->m_Position.z) * v8) + v4->m_Position.z;
            v3 = pDestVert;
            ++v2;
          }
          v3[v2] = v5;
        }
        ++v2;
LABEL_14:
        ++i;
        v4 = v5;
        startInside = endInside;
        if ( i >= m_ClipCount )
          break;
        v1 = pSrcVert;
      }
    }
    v14 = 1 - clip->m_CurrVert;
    clip->m_ClipCount = v2;
    clip->m_CurrVert = v14;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101098B0
// Name: ShadowClip_CClipPlane_
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShadowClip_CClipPlane_(ShadowClipState_t *clip, CClipPlane *clipper)
{
  int m_ClipCount; // edx
  int m_CurrVert; // ecx
  int v5; // eax
  bool v6; // zf
  const Vector *p_m_Position; // esi
  float x; // xmm1_4
  float v9; // xmm0_4
  float m_Dist; // xmm1_4
  ShadowVertex_t **v11; // ecx
  ShadowVertex_t *v12; // edi
  int v13; // edx
  float v14; // xmm0_4
  double v15; // st7
  const Vector *v16; // ecx
  float *v17; // eax
  float v18; // xmm2_4
  int m_TempCount; // edx
  float v20; // xmm0_4
  double v21; // st7
  const Vector *m_pNormal; // ecx
  float *p_x; // eax
  float v24; // xmm2_4
  int v25; // ecx
  float dist; // [esp+0h] [ebp-44h]
  float dista; // [esp+0h] [ebp-44h]
  Vector v28; // [esp+10h] [ebp-34h] BYREF
  Vector dir; // [esp+1Ch] [ebp-28h] BYREF
  ShadowVertex_t *v30; // [esp+28h] [ebp-1Ch]
  ShadowVertex_t **pSrcVert; // [esp+2Ch] [ebp-18h]
  int v32; // [esp+30h] [ebp-14h]
  ShadowVertex_t **pDestVert; // [esp+34h] [ebp-10h]
  int i; // [esp+38h] [ebp-Ch]
  int numOutVerts; // [esp+3Ch] [ebp-8h]
  bool endInside; // [esp+43h] [ebp-1h]
  float startInside; // [esp+4Ch] [ebp+8h]
  float startInsidea; // [esp+4Ch] [ebp+8h]
  bool startInside_3; // [esp+4Fh] [ebp+Bh]

  m_ClipCount = clip->m_ClipCount;
  v32 = m_ClipCount;
  if ( m_ClipCount != 0 )
  {
    m_CurrVert = clip->m_CurrVert;
    v5 = 0;
    v6 = clip->m_CurrVert == 0;
    p_m_Position = *((const Vector **)&clip->m_pTempVertices[8 * m_CurrVert + 47].m_ShadowSpaceTexCoord.z + m_ClipCount);
    x = p_m_Position->x;
    pSrcVert = clip->m_ppClipVertices[m_CurrVert];
    v9 = (float)((float)(clipper->m_pNormal->y * p_m_Position->y) + (float)(x * clipper->m_pNormal->x))
       + (float)(clipper->m_pNormal->z * p_m_Position->z);
    m_Dist = clipper->m_Dist;
    v11 = clip->m_ppClipVertices[v6];
    numOutVerts = 0;
    pDestVert = v11;
    startInside_3 = m_Dist > v9;
    for ( i = 0; i < v32; p_m_Position = &v12->m_Position )
    {
      v12 = pSrcVert[i];
      if ( clipper->m_Dist <= (float)((float)((float)(clipper->m_pNormal->y * v12->m_Position.y)
                                            + (float)(clipper->m_pNormal->x * v12->m_Position.x))
                                    + (float)(clipper->m_pNormal->z * v12->m_Position.z)) )
      {
        endInside = false;
        if ( startInside_3 )
        {
          m_TempCount = clip->m_TempCount;
          if ( m_TempCount >= 48 )
            return;
          v11[v5] = &clip->m_pTempVertices[m_TempCount];
          ++clip->m_TempCount;
          v20 = v12->m_Position.x - p_m_Position->x;
          v30 = v11[v5];
          v21 = clipper->m_Dist;
          m_pNormal = clipper->m_pNormal;
          v28.x = v20;
          dista = v21;
          v28.y = v12->m_Position.y - p_m_Position->y;
          v28.z = v12->m_Position.z - p_m_Position->z;
          startInsidea = IntersectRayWithPlane(org: p_m_Position, dir: &v28, normal: m_pNormal, dist: dista);
          p_x = &v30->m_Position.x;
          v30->m_ShadowSpaceTexCoord.x = (float)((float)(v12->m_ShadowSpaceTexCoord.x - p_m_Position[1].x) * startInsidea)
                                       + p_m_Position[1].x;
          p_x[4] = (float)((float)(v12->m_ShadowSpaceTexCoord.y - p_m_Position[1].y) * startInsidea) + p_m_Position[1].y;
          v11 = pDestVert;
          p_x[5] = (float)((float)(v12->m_ShadowSpaceTexCoord.z - p_m_Position[1].z) * startInsidea) + p_m_Position[1].z;
          *p_x = (float)((float)(v12->m_Position.x - p_m_Position->x) * startInsidea) + p_m_Position->x;
          p_x[1] = (float)((float)(v12->m_Position.y - p_m_Position->y) * startInsidea) + p_m_Position->y;
          v24 = v12->m_Position.z - p_m_Position->z;
          ++numOutVerts;
          p_x[2] = (float)(v24 * startInsidea) + p_m_Position->z;
          v5 = numOutVerts;
        }
      }
      else
      {
        endInside = true;
        if ( !startInside_3 )
        {
          v13 = clip->m_TempCount;
          if ( v13 >= 48 )
            return;
          v11[v5] = &clip->m_pTempVertices[v13];
          ++clip->m_TempCount;
          v14 = v12->m_Position.x - p_m_Position->x;
          v30 = v11[v5];
          v15 = clipper->m_Dist;
          v16 = clipper->m_pNormal;
          dir.x = v14;
          dist = v15;
          dir.y = v12->m_Position.y - p_m_Position->y;
          dir.z = v12->m_Position.z - p_m_Position->z;
          startInside = IntersectRayWithPlane(org: p_m_Position, &dir, normal: v16, dist);
          v17 = &v30->m_Position.x;
          v30->m_ShadowSpaceTexCoord.x = (float)((float)(v12->m_ShadowSpaceTexCoord.x - p_m_Position[1].x) * startInside)
                                       + p_m_Position[1].x;
          v17[4] = (float)((float)(v12->m_ShadowSpaceTexCoord.y - p_m_Position[1].y) * startInside) + p_m_Position[1].y;
          v11 = pDestVert;
          v17[5] = (float)((float)(v12->m_ShadowSpaceTexCoord.z - p_m_Position[1].z) * startInside) + p_m_Position[1].z;
          *v17 = (float)((float)(v12->m_Position.x - p_m_Position->x) * startInside) + p_m_Position->x;
          v17[1] = (float)((float)(v12->m_Position.y - p_m_Position->y) * startInside) + p_m_Position->y;
          v18 = v12->m_Position.z - p_m_Position->z;
          ++numOutVerts;
          v17[2] = (float)(v18 * startInside) + p_m_Position->z;
          v5 = numOutVerts;
        }
        v11[v5++] = v12;
        numOutVerts = v5;
      }
      ++i;
      startInside_3 = endInside;
    }
    v25 = 1 - clip->m_CurrVert;
    clip->m_ClipCount = v5;
    clip->m_CurrVert = v25;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109C70
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short> *m_pMemory; // edx
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
    v7 = 196 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                                     this: _g_pMemAlloc,
                                                                                                     a2: m_pMemory,
                                                                                                     a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                                     this: _g_pMemAlloc,
                                                                                                     a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109D20
// Name: public: void CUtlMemory<struct UtlLinkedListElem_t<struct CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>::Grow(
        CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short> *m_pMemory; // edx
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
    v7 = 772 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short> *)_g_pMemAlloc->Realloc_2(
                                                                                                     this: _g_pMemAlloc,
                                                                                                     a2: m_pMemory,
                                                                                                     a3: v7);
    else
      this->m_pMemory = (UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                                     this: _g_pMemAlloc,
                                                                                                     a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10109DD0
// Name: unsigned short __near & FirstModelInShadow(unsigned short)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 *__cdecl FirstModelInShadow(unsigned __int16 h)
{
  return &s_ShadowMgr.m_Shadows.m_Memory.m_pMemory[h].m_Element.m_FirstModel;
}

//------------------------------------------------------------------------------
// Address: 0x10109DF0
// Name: public: virtual void CShadowMgr::SetShadowTexCoord(unsigned short,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::SetShadowTexCoord(
        CShadowMgr *this,
        unsigned __int16 handle,
        float x,
        float y,
        float w,
        float h)
{
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v6; // eax

  v6 = &this->m_Shadows.m_Memory.m_pMemory[handle];
  v6->m_Element.m_TexOrigin.x = x;
  v6->m_Element.m_TexOrigin.y = y;
  v6->m_Element.m_TexSize.x = w;
  v6->m_Element.m_TexSize.y = h;
}

//------------------------------------------------------------------------------
// Address: 0x10109E30
// Name: public: virtual void CShadowMgr::ClearExtraClipPlanes(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::ClearExtraClipPlanes(CShadowMgr *this, unsigned __int16 h)
{
  this->m_Shadows.m_Memory.m_pMemory[h].m_Element.m_ClipPlaneCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10109E50
// Name: public: virtual void CShadowMgr::AddExtraClipPlane(unsigned short,class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::AddExtraClipPlane(CShadowMgr *this, unsigned __int16 h, const Vector *normal, float dist)
{
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v4; // eax

  v4 = &this->m_Shadows.m_Memory.m_pMemory[h];
  v4->m_Element.m_ClipPlane[v4->m_Element.m_ClipPlaneCount] = *normal;
  v4->m_Element.m_ClipDist[v4->m_Element.m_ClipPlaneCount++] = dist;
}

//------------------------------------------------------------------------------
// Address: 0x10109ED0
// Name: public: virtual bool CShadowMgr::ModelHasShadows(unsigned short)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShadowMgr::ModelHasShadows(CShadowMgr *this, int instance)
{
  return (_WORD)instance != 0xFFFF && *this->m_ShadowsOnModels.m_FirstElement(a1: instance) != 0xFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x10109FE0
// Name: public: virtual void CShadowMgr::SetFalloffBias(unsigned short,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::SetFalloffBias(CShadowMgr *this, unsigned __int16 shadow, unsigned __int8 ucBias)
{
  this->m_Shadows.m_Memory.m_pMemory[shadow].m_Element.m_FalloffBias = ucBias;
}

//------------------------------------------------------------------------------
// Address: 0x1010A000
// Name: private: int CShadowMgr::ProjectAndClipVertices(struct CShadowMgr::Shadow_t const __near &,class VMatrix const __near &,class VMatrix const __near *,int,class Vector __near * __near *,struct ShadowVertex_t __near * __near * __near *,struct ShadowClipState_t __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShadowMgr::ProjectAndClipVertices(
        CShadowMgr *this,
        const CShadowMgr::Shadow_t *shadow,
        const VMatrix *worldToShadow,
        const VMatrix *pWorldToModel,
        int count,
        Vector **ppPosition,
        ShadowVertex_t ***ppOutVertex,
        int clip)
{
  float *m_ClipDist; // ebx
  Vector *m_ClipPlane; // edi
  float dist; // xmm0_4
  cplane_t modelPlane; // [esp+18h] [ebp-30h] BYREF
  cplane_t worldPlane; // [esp+2Ch] [ebp-1Ch] BYREF
  CClipPlane plane; // [esp+40h] [ebp-8h] BYREF
  int i; // [esp+68h] [ebp+20h]

  if ( !CShadowMgr::ProjectVerticesIntoShadowSpace(
          this,
          modelToShadow: worldToShadow,
          maxDist: shadow->m_MaxDist,
          count,
          ppPosition,
          (ShadowClipState_t *)clip) )
    return 0;
  ShadowClip_CClipTop_((ShadowClipState_t *)clip);
  ShadowClip_CClipBottom_((ShadowClipState_t *)clip);
  ShadowClip_CClipLeft_((ShadowClipState_t *)clip);
  ShadowClip_CClipRight_((ShadowClipState_t *)clip);
  if ( shadow->m_ClipPlaneCount == 0 )
    ShadowClip_CClipAbove_((ShadowClipState_t *)clip);
  i = 0;
  if ( shadow->m_ClipPlaneCount != 0 )
  {
    m_ClipDist = shadow->m_ClipDist;
    m_ClipPlane = shadow->m_ClipPlane;
    do
    {
      if ( pWorldToModel != nullptr )
      {
        worldPlane.normal = *m_ClipPlane;
        worldPlane.dist = *m_ClipDist;
        MatrixTransformPlane(src: pWorldToModel, inPlane: &worldPlane, outPlane: &modelPlane);
        dist = modelPlane.dist;
        plane.m_pNormal = (const Vector *)&modelPlane;
      }
      else
      {
        dist = *m_ClipDist;
        plane.m_pNormal = m_ClipPlane;
      }
      plane.m_Dist = dist;
      ShadowClip_CClipPlane_((ShadowClipState_t *)clip, clipper: &plane);
      ++m_ClipDist;
      ++m_ClipPlane;
      ++i;
    }
    while ( i < shadow->m_ClipPlaneCount );
  }
  if ( *(int *)(clip + 8) < 3 )
    return 0;
  *ppOutVertex = (ShadowVertex_t **)(192 * *(_DWORD *)clip + clip + 1164);
  return *(_DWORD *)(clip + 8);
}

//------------------------------------------------------------------------------
// Address: 0x1010A130
// Name: public: virtual int CShadowMgr::ProjectAndClipVertices(unsigned short,int,class Vector __near * __near *,struct ShadowVertex_t __near * __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShadowMgr::ProjectAndClipVertices(
        CShadowMgr *this,
        unsigned __int16 handle,
        int count,
        Vector **ppPosition,
        ShadowVertex_t ***ppOutVertex)
{
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v6; // [esp-1Ch] [ebp-1Ch]

  if ( (_S1_12 & 1) == 0 )
    _S1_12 |= 1u;
  v6 = &this->m_Shadows.m_Memory.m_pMemory[handle];
  return CShadowMgr::ProjectAndClipVertices(
           this,
           shadow: &v6->m_Element,
           worldToShadow: &v6->m_Element.m_WorldToShadow,
           pWorldToModel: nullptr,
           count,
           ppPosition,
           ppOutVertex,
           clip: (int)&clip);
}

//------------------------------------------------------------------------------
// Address: 0x1010A180
// Name: public: virtual int CShadowMgr::ProjectAndClipVerticesEx(unsigned short,int,class Vector __near * __near *,struct ShadowVertex_t __near * __near * __near *,struct ShadowClipState_t __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShadowMgr::ProjectAndClipVerticesEx(
        CShadowMgr *this,
        unsigned __int16 handle,
        int count,
        Vector **ppPosition,
        ShadowVertex_t ***ppOutVertex,
        ShadowClipState_t *clip)
{
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v7; // [esp-1Ch] [ebp-1Ch]

  v7 = &this->m_Shadows.m_Memory.m_pMemory[handle];
  return CShadowMgr::ProjectAndClipVertices(
           this,
           shadow: &v7->m_Element,
           worldToShadow: &v7->m_Element.m_WorldToShadow,
           pWorldToModel: nullptr,
           count,
           ppPosition,
           ppOutVertex,
           (int)clip);
}

//------------------------------------------------------------------------------
// Address: 0x1010A1B0
// Name: private: void CShadowMgr::ProcessDispDecalWorkItem(struct CShadowMgr::DispDecalWorkItem_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::ProcessDispDecalWorkItem(CShadowMgr *this, CShadowMgr::DispDecalWorkItem_t *wi)
{
  UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short> *v2; // eax

  v2 = &this->m_ShadowDecals.m_Memory.m_pMemory[wi->h];
  wi->bKeepShadow = v2->m_Element.m_SurfID->pDispInfo->ComputeShadowFragments(
                      this: v2->m_Element.m_SurfID->pDispInfo,
                      a2: v2->m_Element.m_DispShadow,
                      a3: &wi->vertCount,
                      a4: &wi->indexCount);
}

//------------------------------------------------------------------------------
// Address: 0x1010A2A0
// Name: private: int CShadowMgr::AddNormalShadowsToMeshBuilder(class CMeshBuilder __near &,struct CShadowMgr::ShadowRenderInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShadowMgr::AddNormalShadowsToMeshBuilder(
        CShadowMgr *this,
        CMeshBuilder *meshBuilder,
        CShadowMgr::ShadowRenderInfo_t *info)
{
  int result; // eax
  int v5; // eax
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short> *v6; // ebx
  unsigned int m_Count; // eax
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short> *m_pVerts; // edi
  int m_CachedVerts; // edi
  float *p_z; // eax
  float v11; // xmm1_4
  float *m_pCurrPosition; // ecx
  float v13; // xmm2_4
  float y; // xmm0_4
  float v15; // xmm0_4
  int v16; // xmm1_4
  float *v17; // ecx
  int v18; // ecx
  int v19; // edx
  float v20; // xmm1_4
  float *v21; // eax
  float v22; // xmm2_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  float z; // xmm1_4
  float *v26; // eax
  int v27; // eax
  double x; // st7
  float v29; // xmm0_4
  float v30; // xmm2_4
  float v31; // xmm1_4
  float *v32; // eax
  float v33; // xmm2_4
  float v34; // xmm0_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  float *v37; // eax
  int v38; // eax
  int v39; // eax
  ShadowDecalRenderInfo_t shadow; // [esp+0h] [ebp-3Ch] BYREF
  int vCount; // [esp+2Ch] [ebp-10h]
  CShadowMgr *v42; // [esp+30h] [ebp-Ch]
  int i; // [esp+34h] [ebp-8h]
  int baseIndex; // [esp+38h] [ebp-4h]
  int j; // [esp+44h] [ebp+8h]

  result = 0;
  v42 = this;
  baseIndex = 0;
  i = 0;
  if ( info->m_Count > 0 )
  {
    while ( 1 )
    {
      v5 = info->m_pCache[i];
      v6 = v5 >= 0
         ? &this->m_VertexCache.m_Memory.m_pMemory[(unsigned __int16)v5]
         : (UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short> *)&this->m_TempVertexCache.m_Memory.m_pMemory[-v5 - 1];
      m_Count = v6->m_Element.m_Count;
      if ( (_WORD)m_Count != 0 )
      {
        m_pVerts = (UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short> *)v6->m_Element.m_pVerts;
        if ( m_pVerts == nullptr )
        {
          m_CachedVerts = v6->m_Element.m_CachedVerts;
          if ( m_Count > 8 )
            m_pVerts = (UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short> *)&this->m_LargeVertexList.m_Memory.m_pMemory[m_CachedVerts];
          else
            m_pVerts = &this->m_SmallVertexList.m_Memory.m_pMemory[m_CachedVerts];
        }
      }
      else
      {
        m_pVerts = nullptr;
      }
      ((void (__stdcall *)(ShadowDecalRenderInfo_t *, _DWORD))g_pShadowMgr->ComputeRenderInfo)(
        a1: &shadow,
        a2: v6->m_Element.m_Shadow);
      vCount = v6->m_Element.m_Count - 2;
      if ( vCount > 0 )
      {
        j = 0;
        p_z = &m_pVerts->m_Element.m_Verts[0].m_Position.z;
        do
        {
          v11 = p_z[2] * shadow.m_vTexSize.y;
          m_pCurrPosition = meshBuilder->m_VertexBuilder.m_pCurrPosition;
          v13 = shadow.m_vTexOrigin.x + (float)(p_z[1] * shadow.m_vTexSize.x);
          y = shadow.m_vTexOrigin.y;
          *m_pCurrPosition = m_pVerts->m_Element.m_Verts[0].m_Position.x;
          v15 = y + v11;
          m_pCurrPosition[1] = *(p_z - 1);
          m_pCurrPosition[2] = *p_z;
          v16 = *((_DWORD *)p_z + 3);
          v17 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
          *v17 = v13;
          v17[1] = v15;
          *((_DWORD *)v17 + 2) = v16;
          *(Vector *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1] = shadow.m_vShadowFalloffParams;
          v18 = ++meshBuilder->m_VertexBuilder.m_nCurrentVertex;
          if ( v18 > meshBuilder->m_VertexBuilder.m_nVertexCount )
            meshBuilder->m_VertexBuilder.m_nVertexCount = v18;
          meshBuilder->m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                                                                 + meshBuilder->m_VertexBuilder.m_VertexSize_Position);
          meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0]
                                                                    + meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[0]);
          meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1]
                                                                    + meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[1]);
          meshBuilder->m_IndexBuilder.m_pIndices[meshBuilder->m_IndexBuilder.m_nCurrentIndex] = baseIndex
                                                                                              + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset);
          meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
          meshBuilder->m_IndexBuilder.m_nIndexCount = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
          meshBuilder->m_IndexBuilder.m_pIndices[meshBuilder->m_IndexBuilder.m_nCurrentIndex] = baseIndex
                                                                                              + j
                                                                                              + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset)
                                                                                              + 1;
          meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
          meshBuilder->m_IndexBuilder.m_nIndexCount = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
          meshBuilder->m_IndexBuilder.m_pIndices[meshBuilder->m_IndexBuilder.m_nCurrentIndex] = baseIndex
                                                                                              + j
                                                                                              + LOWORD(meshBuilder->m_IndexBuilder.m_nIndexOffset)
                                                                                              + 2;
          meshBuilder->m_IndexBuilder.m_nCurrentIndex += meshBuilder->m_IndexBuilder.m_nIndexSize;
          v19 = vCount;
          meshBuilder->m_IndexBuilder.m_nIndexCount = meshBuilder->m_IndexBuilder.m_nCurrentIndex;
          m_pVerts = (UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short> *)((char *)m_pVerts + 24);
          p_z += 6;
          ++j;
        }
        while ( j < v19 );
        v20 = m_pVerts->m_Element.m_Verts[0].m_ShadowSpaceTexCoord.y * shadow.m_vTexSize.y;
        v21 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
        v22 = shadow.m_vTexOrigin.x
            + (float)(shadow.m_vTexSize.x * m_pVerts->m_Element.m_Verts[0].m_ShadowSpaceTexCoord.x);
        v23 = shadow.m_vTexOrigin.y;
        *v21 = m_pVerts->m_Element.m_Verts[0].m_Position.x;
        v24 = v23 + v20;
        v21[1] = m_pVerts->m_Element.m_Verts[0].m_Position.y;
        v21[2] = m_pVerts->m_Element.m_Verts[0].m_Position.z;
        z = m_pVerts->m_Element.m_Verts[0].m_ShadowSpaceTexCoord.z;
        v26 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
        *v26 = v22;
        v26[1] = v24;
        v26[2] = z;
        *(Vector *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1] = shadow.m_vShadowFalloffParams;
        v27 = ++meshBuilder->m_VertexBuilder.m_nCurrentVertex;
        if ( v27 > meshBuilder->m_VertexBuilder.m_nVertexCount )
          meshBuilder->m_VertexBuilder.m_nVertexCount = v27;
        x = m_pVerts->m_Element.m_Verts[1].m_Position.x;
        meshBuilder->m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                                                               + meshBuilder->m_VertexBuilder.m_VertexSize_Position);
        meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0]
                                                                  + meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[0]);
        v29 = shadow.m_vTexSize.x * m_pVerts->m_Element.m_Verts[1].m_ShadowSpaceTexCoord.x;
        v30 = shadow.m_vTexOrigin.x;
        v31 = m_pVerts->m_Element.m_Verts[1].m_ShadowSpaceTexCoord.y * shadow.m_vTexSize.y;
        meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1]
                                                                  + meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[1]);
        v32 = meshBuilder->m_VertexBuilder.m_pCurrPosition;
        v33 = v30 + v29;
        v34 = shadow.m_vTexOrigin.y;
        *v32 = x;
        v35 = v34 + v31;
        v32[1] = m_pVerts->m_Element.m_Verts[1].m_Position.y;
        v32[2] = m_pVerts->m_Element.m_Verts[1].m_Position.z;
        v36 = m_pVerts->m_Element.m_Verts[1].m_ShadowSpaceTexCoord.z;
        v37 = meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0];
        *v37 = v33;
        v37[1] = v35;
        v37[2] = v36;
        *(Vector *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1] = shadow.m_vShadowFalloffParams;
        v38 = ++meshBuilder->m_VertexBuilder.m_nCurrentVertex;
        if ( v38 > meshBuilder->m_VertexBuilder.m_nVertexCount )
          meshBuilder->m_VertexBuilder.m_nVertexCount = v38;
        meshBuilder->m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrPosition
                                                               + meshBuilder->m_VertexBuilder.m_VertexSize_Position);
        meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[0]
                                                                  + meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[0]);
        v39 = baseIndex;
        meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1] = (float *)((char *)meshBuilder->m_VertexBuilder.m_pCurrTexCoord[1]
                                                                  + meshBuilder->m_VertexBuilder.m_VertexSize_TexCoord[1]);
        baseIndex = v39 + v19 + 2;
      }
      if ( ++i >= info->m_Count )
        break;
      this = v42;
    }
    return baseIndex;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010A680
// Name: private: int CShadowMgr::AddDisplacementShadowsToMeshBuilder(class CMeshBuilder __near &,struct CShadowMgr::ShadowRenderInfo_t __near &,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShadowMgr::AddDisplacementShadowsToMeshBuilder(
        CShadowMgr *this,
        CMeshBuilder *meshBuilder,
        CShadowMgr::ShadowRenderInfo_t *info,
        int baseIndex)
{
  int result; // eax
  int i; // esi

  if ( r_DrawDisp.m_pParent == nullptr || r_DrawDisp.m_pParent->m_Value.m_nValue == 0 )
    return baseIndex;
  result = baseIndex;
  for ( i = 0; i < info->m_DispCount; ++i )
    result = DispInfo_AddShadowsToMeshBuilder(meshBuilder, h: info->m_pDispCache[i], baseIndex: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010A6D0
// Name: private: void CShadowMgr::RenderDebuggingInfo(struct CShadowMgr::ShadowRenderInfo_t const __near &,void (*)(unsigned short,class Vector const __near &))
// Source: json
//------------------------------------------------------------------------------
void __userpurge CShadowMgr::RenderDebuggingInfo(
        CShadowMgr *this@<ecx>,
        float a2@<ebp>,
        const CShadowMgr::ShadowRenderInfo_t *info,
        void (__cdecl *func)(unsigned __int16, const Vector *))
{
  int v4; // esi
  float x; // edi
  int v6; // eax
  unsigned __int16 *v7; // ecx
  unsigned int v8; // edx
  float *v9; // eax
  int v10; // eax
  int v11; // edx
  float v12; // xmm6_4
  float v13; // xmm7_4
  float v14; // xmm4_4
  float *v15; // eax
  float v16; // xmm2_4
  float v17; // xmm6_4
  float v18; // xmm5_4
  float v19; // xmm0_4
  float v20; // xmm4_4
  float v21; // xmm2_4
  float v22; // xmm4_4
  float v23; // xmm1_4
  float v24; // xmm5_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // [esp-24h] [ebp-5Ch]
  float v29; // [esp-8h] [ebp-40h]
  float v30; // [esp-4h] [ebp-3Ch]
  float v2; // [esp+0h] [ebp-38h]
  float v2_4; // [esp+4h] [ebp-34h]
  float v2_8; // [esp+8h] [ebp-30h]
  float v1; // [esp+Ch] [ebp-2Ch]
  float v1_4; // [esp+10h] [ebp-28h]
  float v1_8; // [esp+14h] [ebp-24h]
  Vector vecApex; // [esp+18h] [ebp-20h] BYREF
  Vector vecCentroid; // [esp+24h] [ebp-14h]
  void *v39; // [esp+30h] [ebp-8h]
  void *retaddr; // [esp+38h] [ebp+0h]

  vecCentroid.z = a2;
  v39 = retaddr;
  v4 = 0;
  x = *(float *)&this;
  for ( LODWORD(vecCentroid.x) = this; v4 < info->m_Count; ++v4 )
  {
    v6 = info->m_pCache[v4];
    if ( v6 >= 0 )
      v7 = (unsigned __int16 *)(*(_DWORD *)(LODWORD(x) + 180) + 16 * (unsigned __int16)v6);
    else
      v7 = (unsigned __int16 *)(*(_DWORD *)(LODWORD(x) + 208) - 4 * (3 * v6 + 3));
    v8 = *v7;
    if ( (_WORD)v8 != 0 )
    {
      v9 = *((float **)v7 + 2);
      if ( v9 == nullptr )
      {
        v10 = v7[2];
        if ( v8 > 8 )
          v9 = (float *)(*(_DWORD *)(LODWORD(x) + 256) + 772 * v10);
        else
          v9 = (float *)(*(_DWORD *)(LODWORD(x) + 228) + 196 * v10);
      }
    }
    else
    {
      v9 = nullptr;
    }
    memset(&vecApex, 0, sizeof(vecApex));
    v1 = *v9;
    v1_4 = v9[1];
    v1_8 = v9[2];
    v11 = *v7 - 2;
    vecCentroid.y = 0.0;
    if ( v11 > 0 )
    {
      v12 = v1_8;
      v13 = v1_4;
      v14 = v1;
      v15 = v9 + 12;
      do
      {
        v2 = *(v15 - 6);
        v2_4 = *(v15 - 5);
        v2_8 = *(v15 - 4);
        v16 = v2_8 - v12;
        v17 = *v15 - v2;
        v18 = v2 - v14;
        v29 = v15[1];
        v30 = v15[2];
        v19 = (float)(v2_4 - v13) * v17;
        v20 = (float)(v29 - v2_4) * v16;
        v21 = v16 * v17;
        v12 = v1_8;
        v22 = v20 - (float)((float)(v30 - v2_8) * (float)(v2_4 - v13));
        v13 = v1_4;
        v23 = (float)((float)((float)((float)((float)(v30 - v2_8) * v18) - v21)
                            * (float)((float)((float)(v30 - v2_8) * v18) - v21))
                    + (float)((float)(v19 - (float)((float)(v29 - v2_4) * v18))
                            * (float)(v19 - (float)((float)(v29 - v2_4) * v18))))
            + (float)(v22 * v22);
        v14 = v1;
        v28 = fsqrt(v23);
        v24 = v28 + vecCentroid.y;
        v25 = (float)((float)((float)((float)(v1 + v2) + *v15) * v28) * 0.33333334) + vecApex.x;
        v26 = (float)((float)((float)((float)(v1_4 + v2_4) + v29) * v28) * 0.33333334) + vecApex.y;
        v27 = (float)((float)((float)((float)(v1_8 + v2_8) + v30) * v28) * 0.33333334) + vecApex.z;
        v15 += 6;
        --v11;
        vecCentroid.y = v28 + vecCentroid.y;
        vecApex.x = v25;
        vecApex.y = v26;
        vecApex.z = v27;
      }
      while ( v11 != 0 );
      x = vecCentroid.x;
      if ( v24 != 0.0 )
      {
        vecApex.x = v25 * (float)(1.0 / v24);
        vecApex.y = (float)(1.0 / v24) * v26;
        vecApex.z = v27 * (float)(1.0 / v24);
      }
    }
    func(a1: v7[1], a2: &vecApex);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010A950
// Name: public: virtual void CShadowMgr::UpdateFlashlightState(unsigned short,struct FlashlightState_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::UpdateFlashlightState(
        CShadowMgr *this,
        unsigned __int16 shadowHandle,
        const FlashlightState_t *lightState)
{
  qmemcpy(
    (void *)&this->m_FlashlightStates.m_Memory.m_pMemory[this->m_Shadows.m_Memory.m_pMemory[shadowHandle].m_Element.m_FlashlightHandle].m_Element.m_FlashlightState,
    lightState,
    sizeof(this->m_FlashlightStates.m_Memory.m_pMemory[this->m_Shadows.m_Memory.m_pMemory[shadowHandle].m_Element.m_FlashlightHandle].m_Element.m_FlashlightState));
}

//------------------------------------------------------------------------------
// Address: 0x1010A990
// Name: public: virtual void CShadowMgr::SetFlashlightDepthTexture(unsigned short,class ITexture __near *,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::SetFlashlightDepthTexture(
        CShadowMgr *this,
        unsigned __int16 shadowHandle,
        ITexture *pFlashlightDepthTexture,
        unsigned __int8 ucShadowStencilBit)
{
  int v4; // eax

  v4 = shadowHandle;
  this->m_Shadows.m_Memory.m_pMemory[v4].m_Element.m_pFlashlightDepthTexture = pFlashlightDepthTexture;
  this->m_Shadows.m_Memory.m_pMemory[v4].m_Element.m_ucShadowStencilBit = ucShadowStencilBit;
}

//------------------------------------------------------------------------------
// Address: 0x1010A9C0
// Name: void DrawPolygonToStencil(class IMatRenderContext __near *,int,class Vector __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawPolygonToStencil(
        IMatRenderContext *pRenderContext,
        int nNumVerts,
        Vector *pVecPoints,
        bool bFrontFacing)
{
  IMaterial *v4; // eax
  IMesh *v6; // edi
  int v7; // ebx
  int v8; // edi
  float *m_pCurrPosition; // eax
  float y; // xmm0_4
  float z; // xmm1_4
  int v12; // eax
  float *v13; // ecx
  int v14; // eax
  int v15; // eax
  float v16; // xmm0_4
  float v17; // xmm1_4
  int v18; // eax
  float *v19; // ecx
  int v20; // eax
  int v21; // eax
  float v22; // xmm0_4
  float v23; // xmm1_4
  int m_nVertexCount; // edi
  int v25; // eax
  void (__thiscall *MatrixMode)(IMatRenderContext *, MaterialMatrixMode_t); // edx
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-1E8h] BYREF
  int i; // [esp+1FCh] [ebp+8h]
  int nNumVertsa; // [esp+200h] [ebp+Ch]

  v4 = materials->FindMaterial(this: materials, a2: "engine/writestencil", a3: "Other textures", a4: 1, a5: 0);
  pRenderContext->Bind(this: pRenderContext, a2: v4, a3: nullptr);
  v6 = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 1, a3: 0, a4: 0, a5: 0);
  pRenderContext->MatrixMode(this: pRenderContext, a2: MATERIAL_MODEL);
  pRenderContext->PushMatrix(this: pRenderContext);
  pRenderContext->LoadIdentity(this: pRenderContext);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  meshBuilder.m_pMesh = v6;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_TRIANGLES;
  v7 = 3 * nNumVerts - 6;
  v6->SetPrimitiveType(this: v6, a2: MATERIAL_TRIANGLES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v7, a3: v7, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v6->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v7;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v6, nMaxVertexCount: v7, desc: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  v8 = 1;
  i = 1;
  nNumVertsa = nNumVerts - 1;
  if ( nNumVertsa <= 1 )
  {
    m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  }
  else
  {
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    while ( 1 )
    {
      y = pVecPoints->y;
      z = pVecPoints->z;
      *m_pCurrPosition = pVecPoints->x;
      m_pCurrPosition[1] = y;
      m_pCurrPosition[2] = z;
      v12 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
      meshBuilder.m_VertexBuilder.m_nCurrentVertex = v12;
      if ( v12 > meshBuilder.m_VertexBuilder.m_nVertexCount )
        meshBuilder.m_VertexBuilder.m_nVertexCount = v12;
      v13 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                    + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
      v14 = v8;
      meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                            + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
      if ( !bFrontFacing )
        v14 = v8 + 1;
      v15 = v14;
      v16 = pVecPoints[v15].y;
      v17 = pVecPoints[v15].z;
      *v13 = pVecPoints[v15].x;
      v13[1] = v16;
      v13[2] = v17;
      v18 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
      meshBuilder.m_VertexBuilder.m_nCurrentVertex = v18;
      if ( v18 > meshBuilder.m_VertexBuilder.m_nVertexCount )
        meshBuilder.m_VertexBuilder.m_nVertexCount = v18;
      v19 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                    + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
      v20 = v8 + 1;
      meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                            + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
      if ( !bFrontFacing )
        v20 = v8;
      v21 = v20;
      v22 = pVecPoints[v21].y;
      v23 = pVecPoints[v21].z;
      *v19 = pVecPoints[v21].x;
      v19[1] = v22;
      v19[2] = v23;
      m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
      v25 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
      meshBuilder.m_VertexBuilder.m_nCurrentVertex = v25;
      if ( v25 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      {
        m_nVertexCount = v25;
        meshBuilder.m_VertexBuilder.m_nVertexCount = v25;
      }
      m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
      ++i;
      meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                            + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
      if ( i >= nNumVertsa )
        break;
      v8 = i;
    }
  }
  if ( meshBuilder.m_bGenerateIndices )
  {
    switch ( meshBuilder.m_Type )
    {
      case MATERIAL_LINE_STRIP:
        m_nVertexCount = 2 * m_nVertexCount - 2;
        break;
      case MATERIAL_LINE_LOOP:
        m_nVertexCount *= 2;
        break;
      case MATERIAL_POLYGON:
        m_nVertexCount = 3 * m_nVertexCount - 6;
        break;
      case MATERIAL_QUADS:
        m_nVertexCount = 6 * m_nVertexCount / 4;
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
  meshBuilder.m_pMesh->UnlockMesh(
    this: meshBuilder.m_pMesh,
    a2: m_nVertexCount,
    a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
    a4: &meshBuilder);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  meshBuilder.m_pMesh->Draw_2(this: meshBuilder.m_pMesh, a2: -1, a3: 0);
  MatrixMode = pRenderContext->MatrixMode;
  meshBuilder.m_pMesh = nullptr;
  MatrixMode(this: pRenderContext, a2: MATERIAL_MODEL);
  pRenderContext->PopMatrix(this: pRenderContext);
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

//------------------------------------------------------------------------------
// Address: 0x1010AD00
// Name: private: void CShadowMgr::SetStencilAndScissor(class IMatRenderContext __near *,struct CShadowMgr::FlashlightInfo_t __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CShadowMgr::SetStencilAndScissor(
        CShadowMgr *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        IMatRenderContext *pRenderContext,
        CShadowMgr::FlashlightInfo_t *flashlightInfo,
        bool bUseStencil)
{
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v7; // eax
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm1_4
  int i; // eax
  int v13; // xmm5_4
  float v14; // xmm7_4
  float v15; // xmm7_4
  int v16; // xmm5_4
  float v17; // xmm7_4
  float v18; // xmm6_4
  int v19; // xmm5_4
  float v20; // xmm7_4
  float v21; // xmm6_4
  float v22; // xmm7_4
  float v23; // xmm7_4
  int v24; // xmm5_4
  float v25; // xmm7_4
  float v26; // xmm6_4
  int v27; // xmm5_4
  float v28; // xmm7_4
  float v29; // xmm6_4
  float v30; // xmm7_4
  float v31; // xmm7_4
  int v32; // xmm5_4
  float v33; // xmm6_4
  int v34; // xmm5_4
  float v35; // xmm7_4
  float v36; // xmm6_4
  float v37; // xmm7_4
  float v38; // xmm7_4
  int v39; // xmm5_4
  float v40; // xmm7_4
  float v41; // xmm6_4
  float v42; // xmm7_4
  const QAngle *v43; // esi
  float v44; // xmm0_4
  int v45; // ebx
  unsigned __int8 *v46; // edi
  int v47; // eax
  int v48; // eax
  int v49; // eax
  int v50; // ecx
  int v51; // eax
  int v52; // edi
  Vector *v53; // ebx
  float *p_x; // edx
  float *v55; // ecx
  CShadowMgr::FlashlightInfo_t *v56; // ecx
  IMatRenderContext *v57; // edi
  bool v58; // al
  int v59; // eax
  int v60; // edx
  int v61; // eax
  ConVar *m_pParent; // eax
  int v63; // esi
  Vector *v64; // edi
  int m_Shadow; // edx
  unsigned __int8 *p_m_ucShadowStencilBit; // eax
  int v67; // edx
  IMatRenderContext_vtbl *v68; // eax
  int v69; // esi
  Vector *v70; // edi
  void (__thiscall *SetStencilState)(IMatRenderContext *, const ShaderStencilState_t *); // edx
  Vector vClippedPolygons[8][10]; // [esp+14h] [ebp-798h] BYREF
  Vector vClippedFace[6]; // [esp+3D4h] [ebp-3D8h] BYREF
  Vector vTempFace[5]; // [esp+41Ch] [ebp-390h] BYREF
  Vector vWorldFrustumPoints[24]; // [esp+458h] [ebp-354h] BYREF
  ShaderStencilState_t stateDisable; // [esp+578h] [ebp-234h] BYREF
  int v77; // [esp+598h] [ebp-214h]
  int v78; // [esp+59Ch] [ebp-210h]
  int v79; // [esp+5A0h] [ebp-20Ch]
  int v80; // [esp+5A4h] [ebp-208h]
  ShaderStencilState_t state; // [esp+5A8h] [ebp-204h] BYREF
  int v82; // [esp+5C8h] [ebp-1E4h]
  int v83; // [esp+5CCh] [ebp-1E0h]
  int v84; // [esp+5D0h] [ebp-1DCh]
  int v85; // [esp+5D4h] [ebp-1D8h]
  int nNumVertices[8]; // [esp+5D8h] [ebp-1D4h] BYREF
  Vector vFarNormal; // [esp+5F8h] [ebp-1B4h] BYREF
  Vector vForward; // [esp+604h] [ebp-1A8h] BYREF
  Vector vNearNormal; // [esp+610h] [ebp-19Ch] BYREF
  CShadowMgr *v90; // [esp+61Ch] [ebp-190h]
  float v91; // [esp+620h] [ebp-18Ch]
  float v92; // [esp+624h] [ebp-188h]
  float v93; // [esp+628h] [ebp-184h]
  float v94; // [esp+62Ch] [ebp-180h]
  float v95; // [esp+630h] [ebp-17Ch]
  float v96; // [esp+634h] [ebp-178h]
  Vector vFrustumPoints[24]; // [esp+638h] [ebp-174h] BYREF
  int nLeft; // [esp+758h] [ebp-54h] BYREF
  VMatrix matFlashlightToWorld; // [esp+75Ch] [ebp-50h] BYREF
  int nTop; // [esp+79Ch] [ebp-10h] BYREF
  int nRight; // [esp+7A0h] [ebp-Ch] BYREF
  int nBottom; // [esp+7A4h] [ebp-8h] BYREF
  int nNumPolygons; // [esp+7A8h] [ebp-4h]

  v7 = &this->m_Shadows.m_Memory.m_pMemory[flashlightInfo->m_Shadow];
  v90 = this;
  MatrixInverseGeneral(src: &v7->m_Element.m_WorldToShadow, dst: &matFlashlightToWorld);
  memset(vFrustumPoints, 0, 12);
  vFrustumPoints[1].x = 1.0;
  vFrustumPoints[1].y = 0.0;
  vFrustumPoints[1].z = 0.0;
  vFrustumPoints[2].x = 1.0;
  vFrustumPoints[2].y = 1.0;
  vFrustumPoints[2].z = 0.0;
  vFrustumPoints[3].x = 0.0;
  vFrustumPoints[3].y = 1.0;
  vFrustumPoints[3].z = 0.0;
  vFrustumPoints[4].x = 0.0;
  vFrustumPoints[4].y = 0.0;
  vFrustumPoints[4].z = 1.0;
  vFrustumPoints[5].x = 0.0;
  vFrustumPoints[5].y = 1.0;
  vFrustumPoints[5].z = 1.0;
  vFrustumPoints[6].x = 1.0;
  vFrustumPoints[6].y = 1.0;
  vFrustumPoints[6].z = 1.0;
  vFrustumPoints[7].x = 1.0;
  vFrustumPoints[7].y = 0.0;
  vFrustumPoints[7].z = 1.0;
  vFrustumPoints[8].x = 1.0;
  vFrustumPoints[8].y = 0.0;
  vFrustumPoints[8].z = 0.0;
  vFrustumPoints[9].x = 1.0;
  vFrustumPoints[9].y = 0.0;
  vFrustumPoints[9].z = 1.0;
  vFrustumPoints[10].x = 1.0;
  vFrustumPoints[10].y = 1.0;
  vFrustumPoints[10].z = 1.0;
  vFrustumPoints[11].x = 1.0;
  vFrustumPoints[11].y = 1.0;
  vFrustumPoints[11].z = 0.0;
  memset(&vFrustumPoints[12], 0, 16);
  vFrustumPoints[13].y = 1.0;
  vFrustumPoints[13].z = 0.0;
  vFrustumPoints[14].x = 0.0;
  vFrustumPoints[14].y = 1.0;
  vFrustumPoints[14].z = 1.0;
  vFrustumPoints[15].x = 0.0;
  vFrustumPoints[15].y = 0.0;
  vFrustumPoints[15].z = 1.0;
  vFrustumPoints[16].x = 0.0;
  vFrustumPoints[16].y = 1.0;
  vFrustumPoints[16].z = 0.0;
  vFrustumPoints[17].x = 1.0;
  vFrustumPoints[17].y = 1.0;
  vFrustumPoints[17].z = 0.0;
  vFrustumPoints[18].x = 1.0;
  vFrustumPoints[18].y = 1.0;
  vFrustumPoints[18].z = 1.0;
  vFrustumPoints[19].x = 0.0;
  vFrustumPoints[19].y = 1.0;
  vFrustumPoints[19].z = 1.0;
  memset(&vFrustumPoints[20], 0, 20);
  vFrustumPoints[21].z = 1.0;
  vFrustumPoints[22].x = 1.0;
  vFrustumPoints[22].y = 0.0;
  vFrustumPoints[22].z = 1.0;
  v8 = matFlashlightToWorld.m[3][2];
  v9 = matFlashlightToWorld.m[3][1];
  v10 = matFlashlightToWorld.m[3][0];
  vFrustumPoints[23].y = 0.0;
  vFrustumPoints[23].z = 0.0;
  v11 = matFlashlightToWorld.m[3][3];
  vFrustumPoints[23].x = 1.0;
  for ( i = 0; i < 24; i += 8 )
  {
    *(float *)&v13 = 1.0
                   / (float)((float)((float)((float)(v10 * vFrustumPoints[i].x) + (float)(v9 * vFrustumPoints[i].y))
                                   + (float)(v8 * vFrustumPoints[i].z))
                           + v11);
    vWorldFrustumPoints[i].x = (float)((float)((float)((float)(matFlashlightToWorld.m[0][0] * vFrustumPoints[i].x)
                                                     + (float)(matFlashlightToWorld.m[0][1] * vFrustumPoints[i].y))
                                             + (float)(matFlashlightToWorld.m[0][2] * vFrustumPoints[i].z))
                                     + matFlashlightToWorld.m[0][3])
                             * *(float *)&v13;
    v14 = matFlashlightToWorld.m[2][1] * vFrustumPoints[i].y;
    vWorldFrustumPoints[i].y = (float)((float)((float)((float)(matFlashlightToWorld.m[1][0] * vFrustumPoints[i].x)
                                                     + (float)(matFlashlightToWorld.m[1][1] * vFrustumPoints[i].y))
                                             + (float)(matFlashlightToWorld.m[1][2] * vFrustumPoints[i].z))
                                     + matFlashlightToWorld.m[1][3])
                             * *(float *)&v13;
    vWorldFrustumPoints[i].z = (float)((float)((float)((float)(matFlashlightToWorld.m[2][0] * vFrustumPoints[i].x) + v14)
                                             + (float)(matFlashlightToWorld.m[2][2] * vFrustumPoints[i].z))
                                     + matFlashlightToWorld.m[2][3])
                             * *(float *)&v13;
    v15 = (float)(v10 * vFrustumPoints[i + 1].x) + (float)(v9 * vFrustumPoints[i + 1].y);
    nNumPolygons = v13;
    *(float *)&v16 = 1.0 / (float)((float)(v15 + (float)(v8 * vFrustumPoints[i + 1].z)) + v11);
    v17 = matFlashlightToWorld.m[1][1] * vFrustumPoints[i + 1].y;
    vWorldFrustumPoints[i + 1].x = (float)((float)((float)((float)(matFlashlightToWorld.m[0][0] * vFrustumPoints[i + 1].x)
                                                         + (float)(matFlashlightToWorld.m[0][1] * vFrustumPoints[i + 1].y))
                                                 + (float)(matFlashlightToWorld.m[0][2] * vFrustumPoints[i + 1].z))
                                         + matFlashlightToWorld.m[0][3])
                                 * *(float *)&v16;
    vWorldFrustumPoints[i + 1].y = (float)((float)((float)((float)(matFlashlightToWorld.m[1][0] * vFrustumPoints[i + 1].x)
                                                         + v17)
                                                 + (float)(matFlashlightToWorld.m[1][2] * vFrustumPoints[i + 1].z))
                                         + matFlashlightToWorld.m[1][3])
                                 * *(float *)&v16;
    v18 = matFlashlightToWorld.m[2][0] * vFrustumPoints[i + 1].x;
    nNumPolygons = v16;
    vWorldFrustumPoints[i + 1].z = (float)((float)((float)(v18
                                                         + (float)(matFlashlightToWorld.m[2][1] * vFrustumPoints[i + 1].y))
                                                 + (float)(matFlashlightToWorld.m[2][2] * vFrustumPoints[i + 1].z))
                                         + matFlashlightToWorld.m[2][3])
                                 * *(float *)&v16;
    *(float *)&v19 = 1.0
                   / (float)((float)((float)((float)(v10 * vFrustumPoints[i + 2].x)
                                           + (float)(v9 * vFrustumPoints[i + 2].y))
                                   + (float)(v8 * vFrustumPoints[i + 2].z))
                           + v11);
    v20 = matFlashlightToWorld.m[1][1] * vFrustumPoints[i + 2].y;
    vWorldFrustumPoints[i + 2].x = (float)((float)((float)((float)(matFlashlightToWorld.m[0][0] * vFrustumPoints[i + 2].x)
                                                         + (float)(matFlashlightToWorld.m[0][1] * vFrustumPoints[i + 2].y))
                                                 + (float)(matFlashlightToWorld.m[0][2] * vFrustumPoints[i + 2].z))
                                         + matFlashlightToWorld.m[0][3])
                                 * *(float *)&v19;
    v21 = (float)((float)((float)(matFlashlightToWorld.m[1][0] * vFrustumPoints[i + 2].x) + v20)
                + (float)(matFlashlightToWorld.m[1][2] * vFrustumPoints[i + 2].z))
        + matFlashlightToWorld.m[1][3];
    v22 = matFlashlightToWorld.m[2][1] * vFrustumPoints[i + 2].y;
    vWorldFrustumPoints[i + 2].y = v21 * *(float *)&v19;
    vWorldFrustumPoints[i + 2].z = (float)((float)((float)((float)(matFlashlightToWorld.m[2][0] * vFrustumPoints[i + 2].x)
                                                         + v22)
                                                 + (float)(matFlashlightToWorld.m[2][2] * vFrustumPoints[i + 2].z))
                                         + matFlashlightToWorld.m[2][3])
                                 * *(float *)&v19;
    v23 = (float)(v10 * vFrustumPoints[i + 3].x) + (float)(v9 * vFrustumPoints[i + 3].y);
    nNumPolygons = v19;
    *(float *)&v24 = 1.0 / (float)((float)(v23 + (float)(v8 * vFrustumPoints[i + 3].z)) + v11);
    v25 = matFlashlightToWorld.m[1][1] * vFrustumPoints[i + 3].y;
    vWorldFrustumPoints[i + 3].x = (float)((float)((float)((float)(matFlashlightToWorld.m[0][0] * vFrustumPoints[i + 3].x)
                                                         + (float)(matFlashlightToWorld.m[0][1] * vFrustumPoints[i + 3].y))
                                                 + (float)(matFlashlightToWorld.m[0][2] * vFrustumPoints[i + 3].z))
                                         + matFlashlightToWorld.m[0][3])
                                 * *(float *)&v24;
    v26 = matFlashlightToWorld.m[1][0] * vFrustumPoints[i + 3].x;
    nNumPolygons = v24;
    vWorldFrustumPoints[i + 3].y = (float)((float)((float)(v26 + v25)
                                                 + (float)(matFlashlightToWorld.m[1][2] * vFrustumPoints[i + 3].z))
                                         + matFlashlightToWorld.m[1][3])
                                 * *(float *)&v24;
    vWorldFrustumPoints[i + 3].z = (float)((float)((float)((float)(matFlashlightToWorld.m[2][0] * vFrustumPoints[i + 3].x)
                                                         + (float)(matFlashlightToWorld.m[2][1] * vFrustumPoints[i + 3].y))
                                                 + (float)(matFlashlightToWorld.m[2][2] * vFrustumPoints[i + 3].z))
                                         + matFlashlightToWorld.m[2][3])
                                 * *(float *)&v24;
    *(float *)&v27 = 1.0
                   / (float)((float)((float)((float)(v10 * vFrustumPoints[i + 4].x)
                                           + (float)(v9 * vFrustumPoints[i + 4].y))
                                   + (float)(v8 * vFrustumPoints[i + 4].z))
                           + v11);
    v28 = matFlashlightToWorld.m[1][1] * vFrustumPoints[i + 4].y;
    vWorldFrustumPoints[i + 4].x = (float)((float)((float)((float)(matFlashlightToWorld.m[0][0] * vFrustumPoints[i + 4].x)
                                                         + (float)(matFlashlightToWorld.m[0][1] * vFrustumPoints[i + 4].y))
                                                 + (float)(matFlashlightToWorld.m[0][2] * vFrustumPoints[i + 4].z))
                                         + matFlashlightToWorld.m[0][3])
                                 * *(float *)&v27;
    v29 = (float)((float)((float)(matFlashlightToWorld.m[1][0] * vFrustumPoints[i + 4].x) + v28)
                + (float)(matFlashlightToWorld.m[1][2] * vFrustumPoints[i + 4].z))
        + matFlashlightToWorld.m[1][3];
    v30 = matFlashlightToWorld.m[2][1] * vFrustumPoints[i + 4].y;
    vWorldFrustumPoints[i + 4].y = v29 * *(float *)&v27;
    vWorldFrustumPoints[i + 4].z = (float)((float)((float)((float)(matFlashlightToWorld.m[2][0] * vFrustumPoints[i + 4].x)
                                                         + v30)
                                                 + (float)(matFlashlightToWorld.m[2][2] * vFrustumPoints[i + 4].z))
                                         + matFlashlightToWorld.m[2][3])
                                 * *(float *)&v27;
    v31 = (float)(v10 * vFrustumPoints[i + 5].x) + (float)(v9 * vFrustumPoints[i + 5].y);
    nNumPolygons = v27;
    *(float *)&v32 = 1.0 / (float)((float)(v31 + (float)(v8 * vFrustumPoints[i + 5].z)) + v11);
    v33 = (float)(matFlashlightToWorld.m[0][0] * vFrustumPoints[i + 5].x)
        + (float)(matFlashlightToWorld.m[0][1] * vFrustumPoints[i + 5].y);
    nNumPolygons = v32;
    vWorldFrustumPoints[i + 5].x = (float)((float)(v33 + (float)(matFlashlightToWorld.m[0][2] * vFrustumPoints[i + 5].z))
                                         + matFlashlightToWorld.m[0][3])
                                 * *(float *)&v32;
    vWorldFrustumPoints[i + 5].y = (float)((float)((float)((float)(matFlashlightToWorld.m[1][0] * vFrustumPoints[i + 5].x)
                                                         + (float)(matFlashlightToWorld.m[1][1] * vFrustumPoints[i + 5].y))
                                                 + (float)(matFlashlightToWorld.m[1][2] * vFrustumPoints[i + 5].z))
                                         + matFlashlightToWorld.m[1][3])
                                 * *(float *)&v32;
    vWorldFrustumPoints[i + 5].z = (float)((float)((float)((float)(matFlashlightToWorld.m[2][0] * vFrustumPoints[i + 5].x)
                                                         + (float)(matFlashlightToWorld.m[2][1] * vFrustumPoints[i + 5].y))
                                                 + (float)(matFlashlightToWorld.m[2][2] * vFrustumPoints[i + 5].z))
                                         + matFlashlightToWorld.m[2][3])
                                 * *(float *)&v32;
    *(float *)&v34 = 1.0
                   / (float)((float)((float)((float)(v10 * vFrustumPoints[i + 6].x)
                                           + (float)(v9 * vFrustumPoints[i + 6].y))
                                   + (float)(v8 * vFrustumPoints[i + 6].z))
                           + v11);
    v35 = matFlashlightToWorld.m[1][1] * vFrustumPoints[i + 6].y;
    vWorldFrustumPoints[i + 6].x = (float)((float)((float)((float)(matFlashlightToWorld.m[0][0] * vFrustumPoints[i + 6].x)
                                                         + (float)(matFlashlightToWorld.m[0][1] * vFrustumPoints[i + 6].y))
                                                 + (float)(matFlashlightToWorld.m[0][2] * vFrustumPoints[i + 6].z))
                                         + matFlashlightToWorld.m[0][3])
                                 * *(float *)&v34;
    v36 = (float)((float)((float)(matFlashlightToWorld.m[1][0] * vFrustumPoints[i + 6].x) + v35)
                + (float)(matFlashlightToWorld.m[1][2] * vFrustumPoints[i + 6].z))
        + matFlashlightToWorld.m[1][3];
    v37 = matFlashlightToWorld.m[2][1] * vFrustumPoints[i + 6].y;
    vWorldFrustumPoints[i + 6].y = v36 * *(float *)&v34;
    vWorldFrustumPoints[i + 6].z = (float)((float)((float)((float)(matFlashlightToWorld.m[2][0] * vFrustumPoints[i + 6].x)
                                                         + v37)
                                                 + (float)(matFlashlightToWorld.m[2][2] * vFrustumPoints[i + 6].z))
                                         + matFlashlightToWorld.m[2][3])
                                 * *(float *)&v34;
    v38 = (float)((float)(v10 * vFrustumPoints[i + 7].x) + (float)(v9 * vFrustumPoints[i + 7].y))
        + (float)(v8 * vFrustumPoints[i + 7].z);
    nNumPolygons = v34;
    *(float *)&v39 = 1.0 / (float)(v38 + v11);
    v40 = matFlashlightToWorld.m[1][1] * vFrustumPoints[i + 7].y;
    vWorldFrustumPoints[i + 7].x = (float)((float)((float)((float)(vFrustumPoints[i + 7].x * matFlashlightToWorld.m[0][0])
                                                         + (float)(matFlashlightToWorld.m[0][1] * vFrustumPoints[i + 7].y))
                                                 + (float)(matFlashlightToWorld.m[0][2] * vFrustumPoints[i + 7].z))
                                         + matFlashlightToWorld.m[0][3])
                                 * *(float *)&v39;
    v41 = (float)((float)((float)(matFlashlightToWorld.m[1][0] * vFrustumPoints[i + 7].x) + v40)
                + (float)(matFlashlightToWorld.m[1][2] * vFrustumPoints[i + 7].z))
        + matFlashlightToWorld.m[1][3];
    v42 = matFlashlightToWorld.m[2][1] * vFrustumPoints[i + 7].y;
    vWorldFrustumPoints[i + 7].y = v41 * *(float *)&v39;
    vWorldFrustumPoints[i + 7].z = (float)((float)((float)((float)(matFlashlightToWorld.m[2][0] * vFrustumPoints[i + 7].x)
                                                         + v42)
                                                 + (float)(matFlashlightToWorld.m[2][2] * vFrustumPoints[i + 7].z))
                                         + matFlashlightToWorld.m[2][3])
                                 * *(float *)&v39;
    nNumPolygons = v39;
  }
  v43 = (const QAngle *)((int (__thiscall *)(IRender *, int, int, int))g_EngineRenderer->ViewGetCurrent)(
                          a1: g_EngineRenderer,
                          a2: a3,
                          a3: a4,
                          a4: a2);
  AngleVectors(angles: v43 + 9, forward: &vForward, right: nullptr, up: nullptr);
  v44 = (float)((float)(v43[8].y * vForward.y) + (float)(vForward.x * v43[8].x)) + (float)(v43[8].z * vForward.z);
  vFarNormal.y = -vForward.y;
  vFarNormal.x = -vForward.x;
  vFarNormal.z = -vForward.z;
  vNearNormal = vForward;
  *(float *)&nTop = (float)(v43[10].x + 0.40000001) + v44;
  *(float *)&nRight = -(float)((float)(v43[10].y - 0.40000001) + v44);
  v45 = 0;
  v46 = (unsigned __int8 *)vClippedPolygons;
  nNumPolygons = (int)vWorldFrustumPoints;
  for ( nBottom = 6; nBottom != 0; --nBottom )
  {
    v47 = ClipPolyToPlane(
            inVerts: (Vector *)nNumPolygons,
            vertCount: 4,
            outVerts: vTempFace,
            normal: &vNearNormal,
            dist: *(float *)&nTop,
            fOnPlaneEpsilon: 0.1);
    if ( v47 > 2 )
    {
      v48 = ClipPolyToPlane(
              inVerts: vTempFace,
              vertCount: v47,
              outVerts: vClippedFace,
              normal: &vFarNormal,
              dist: *(float *)&nRight,
              fOnPlaneEpsilon: 0.1);
      v43 = (const QAngle *)v48;
      if ( v48 > 2 )
      {
        memcpy(dst: v46, src: (unsigned __int8 *)vClippedFace, count: 12 * v48);
        nNumVertices[v45++] = (int)v43;
        v46 += 120;
      }
    }
    nNumPolygons += 48;
  }
  nNumPolygons = v45;
  ConstructNearAndFarPolygons(
    pVecNearPlane: (Vector *)&stateDisable,
    pVecFarPlane: (Vector *)&state,
    flPlaneEpsilon: 0.40000001);
  v49 = ClipPlaneToFrustum(
          pInPoints: (Vector *)&stateDisable,
          pOutPoints: vClippedPolygons[v45],
          pVecWorldFrustumPoints: vWorldFrustumPoints);
  if ( v49 > 2 )
  {
    nNumVertices[v45++] = v49;
    nNumPolygons = v45;
  }
  v50 = 0;
  *(float *)&nTop = 0.0;
  if ( v45 > 0 )
  {
    nBottom = 0;
    do
    {
      v51 = 0;
      *(float *)&nRight = 0.0;
      if ( nNumVertices[v50] > 0 )
      {
        nLeft = nNumVertices[v50];
        do
        {
          v52 = v50 + 1;
          if ( v50 + 1 < v45 )
          {
            v53 = vClippedPolygons[v52];
            do
            {
              if ( nNumVertices[v52] > 0 )
              {
                v43 = (const QAngle *)nNumVertices[v52];
                p_x = &vClippedPolygons[0][nBottom + v51].x;
                v55 = &v53->x;
                do
                {
                  v94 = *v55;
                  v95 = v55[1];
                  v96 = v55[2];
                  v91 = *p_x;
                  v92 = p_x[1];
                  v93 = p_x[2];
                  if ( fabs(v91 - v94) <= 0.1 && fabs(v92 - v95) <= 0.1 && fabs(v93 - v96) <= 0.1 )
                  {
                    *v55 = *p_x;
                    v55[1] = p_x[1];
                    v55[2] = p_x[2];
                  }
                  v55 += 3;
                  v43 = (const QAngle *)((char *)v43 - 1);
                }
                while ( v43 != nullptr );
                v51 = nRight;
              }
              ++v52;
              v53 += 10;
            }
            while ( v52 < nNumPolygons );
            v45 = nNumPolygons;
            v50 = nTop;
          }
          nRight = ++v51;
        }
        while ( v51 < nLeft );
      }
      nBottom += 10;
      nTop = ++v50;
    }
    while ( v50 < v45 );
  }
  v56 = flashlightInfo;
  flashlightInfo->m_FlashlightState.m_bScissor = false;
  if ( r_flashlightscissor.m_pParent != nullptr && r_flashlightscissor.m_pParent->m_Value.m_nValue != 0 && v45 > 0 )
  {
    v57 = pRenderContext;
    v58 = ScreenSpaceRectFromPoints(
            a1: (int)v43,
            pRenderContext,
            vClippedPolygons,
            pNumPoints: nNumVertices,
            nNumPolygons: v45,
            &nLeft,
            &nTop,
            &nRight,
            &nBottom);
    v56 = flashlightInfo;
    flashlightInfo->m_FlashlightState.m_bScissor = v58;
    if ( v58 )
    {
      v59 = nTop;
      flashlightInfo->m_FlashlightState.m_nLeft = nLeft;
      v60 = nRight;
      flashlightInfo->m_FlashlightState.m_nTop = v59;
      v61 = nBottom;
      flashlightInfo->m_FlashlightState.m_nRight = v60;
      flashlightInfo->m_FlashlightState.m_nBottom = v61;
    }
  }
  else
  {
    v57 = pRenderContext;
  }
  if ( r_flashlightdrawclip.m_pParent == nullptr || r_flashlightdrawclip.m_pParent->m_Value.m_nValue == 0 )
    goto LABEL_43;
  m_pParent = r_flashlightclip.m_pParent;
  if ( r_flashlightclip.m_pParent == nullptr )
    return;
  if ( r_flashlightclip.m_pParent->m_Value.m_nValue != 0 && bUseStencil )
  {
    v63 = 0;
    if ( v45 > 0 )
    {
      v64 = vClippedPolygons[0];
      do
      {
        DrawDebugPolygon(nNumVerts: nNumVertices[v63++], pVecPoints: v64, bFrontFacing: false, bNearPlane: false);
        v64 += 10;
      }
      while ( v63 < v45 );
      v57 = pRenderContext;
      v56 = flashlightInfo;
LABEL_43:
      m_pParent = r_flashlightclip.m_pParent;
    }
  }
  if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 && bUseStencil )
  {
    m_Shadow = v56->m_Shadow;
    v85 = -1;
    v84 = -1;
    state.m_nTestMask = 3;
    state.m_nWriteMask = 3;
    p_m_ucShadowStencilBit = &v90->m_Shadows.m_Memory.m_pMemory[m_Shadow].m_Element.m_ucShadowStencilBit;
    v83 = 0;
    LOBYTE(state.m_CompareFunc) = 1;
    state.m_nReferenceValue = 1;
    v82 = 8;
    v83 = *p_m_ucShadowStencilBit;
    v84 = *p_m_ucShadowStencilBit;
    v67 = *p_m_ucShadowStencilBit;
    v68 = v57->__vftable;
    v85 = v67;
    v68->SetStencilState(this: v57, a2: (const ShaderStencilState_t *)&state.m_CompareFunc);
    v69 = 0;
    if ( v45 > 0 )
    {
      v70 = vClippedPolygons[0];
      do
      {
        DrawPolygonToStencil(pRenderContext, nNumVerts: nNumVertices[v69++], pVecPoints: v70, bFrontFacing: true);
        v70 += 10;
      }
      while ( v69 < v45 );
      v57 = pRenderContext;
    }
    SetStencilState = v57->SetStencilState;
    stateDisable.m_nTestMask = 1;
    stateDisable.m_nReferenceValue = 1;
    stateDisable.m_nWriteMask = 1;
    v80 = -1;
    v79 = -1;
    v77 = 8;
    v78 = 0;
    LOBYTE(stateDisable.m_CompareFunc) = 0;
    SetStencilState(this: v57, a2: (const ShaderStencilState_t *)&stateDisable.m_CompareFunc);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010BCF0
// Name: private: void CShadowMgr::DisableStencilAndScissorMasking(class IMatRenderContext __near *,struct CShadowMgr::FlashlightInfo_t const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::DisableStencilAndScissorMasking(
        CShadowMgr *this,
        IMatRenderContext *pRenderContext,
        const CShadowMgr::FlashlightInfo_t *flashlightInfo,
        bool bDoMasking)
{
  ConVar *m_pParent; // eax
  void (__thiscall *SetStencilState)(IMatRenderContext *, const ShaderStencilState_t *); // edx
  ShaderStencilState_t state; // [esp+4h] [ebp-20h] BYREF

  m_pParent = r_flashlightclip.m_pParent;
  if ( r_flashlightclip.m_pParent != nullptr )
  {
    if ( r_flashlightclip.m_pParent->m_Value.m_nValue != 0 )
    {
      state.m_ZFailOp = SHADER_STENCILOP_KEEP;
      state.m_FailOp = SHADER_STENCILOP_KEEP;
      state.m_PassOp = SHADER_STENCILOP_KEEP;
      state.m_nWriteMask = -1;
      state.m_nTestMask = -1;
      SetStencilState = pRenderContext->SetStencilState;
      state.m_CompareFunc = SHADER_STENCILFUNC_ALWAYS;
      state.m_nReferenceValue = 0;
      state.m_bEnable = false;
      SetStencilState(this: pRenderContext, a2: &state);
      m_pParent = r_flashlightclip.m_pParent;
    }
    if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
      goto LABEL_11;
  }
  if ( r_flashlightscissor.m_pParent != nullptr && r_flashlightscissor.m_pParent->m_Value.m_nValue != 0 )
  {
LABEL_11:
    if ( bDoMasking
      && pRenderContext->GetRenderTarget(this: pRenderContext) == nullptr
      && r_flashlightscissor.m_pParent != nullptr
      && r_flashlightscissor.m_pParent->m_Value.m_nValue != 0
      && flashlightInfo->m_FlashlightState.m_bScissor )
    {
      pRenderContext->PopScissorRect(this: pRenderContext);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010BEC0
// Name: public: virtual class Frustum_t const __near & CShadowMgr::GetFlashlightFrustum(unsigned short)
// Source: json
//------------------------------------------------------------------------------
UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *__thiscall CShadowMgr::GetFlashlightFrustum(
        CShadowMgr *this,
        unsigned __int16 handle)
{
  return &this->m_FlashlightStates.m_Memory.m_pMemory[this->m_Shadows.m_Memory.m_pMemory[handle].m_Element.m_FlashlightHandle];
}

//------------------------------------------------------------------------------
// Address: 0x1010BEF0
// Name: public: virtual struct FlashlightState_t const __near & CShadowMgr::GetFlashlightState(unsigned short)
// Source: json
//------------------------------------------------------------------------------
const FlashlightState_t *__thiscall CShadowMgr::GetFlashlightState(CShadowMgr *this, unsigned __int16 handle)
{
  return &this->m_FlashlightStates.m_Memory.m_pMemory[this->m_Shadows.m_Memory.m_pMemory[handle].m_Element.m_FlashlightHandle].m_Element.m_FlashlightState;
}

//------------------------------------------------------------------------------
// Address: 0x1010D450
// Name: private: virtual void CShadowMgr::SetFlashlightStencilMasks(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::SetFlashlightStencilMasks(CShadowMgr *this, bool bDoMasking)
{
  unsigned __int16 m_Head; // si
  IMatRenderContext *v4; // eax
  IMatRenderContext *v5; // ebx
  int v6; // esi
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *v7; // eax

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CShadowMgr::SetFlashlightStencilMasks",
    a3: 0,
    a4: "Shadow_Rendering",
    a5: false,
    a6: 4);
  if ( !this->m_bSinglePassFlashlightStateEnabled
    && (r_flashlightclip.m_pParent != nullptr && r_flashlightclip.m_pParent->m_Value.m_nValue != 0
     || r_flashlightscissor.m_pParent != nullptr && r_flashlightscissor.m_pParent->m_Value.m_nValue != 0) )
  {
    m_Head = this->m_FlashlightStates.m_Head;
    if ( m_Head != 0xFFFF )
    {
      v4 = materials->GetRenderContext(this: materials);
      v5 = v4;
      if ( v4 != nullptr )
        v4->BeginRender(this: v4);
      do
      {
        v6 = m_Head;
        v7 = &this->m_FlashlightStates.m_Memory.m_pMemory[v6];
        if ( v7->m_Element.m_nSplitscreenOwner == 0 )
          CShadowMgr::SetStencilAndScissor(
            this,
            a2: (int)v5,
            a3: (int)this,
            a4: v6 * 768,
            pRenderContext: v5,
            flashlightInfo: &v7->m_Element,
            bUseStencil: this->m_Shadows.m_Memory.m_pMemory[v7->m_Element.m_Shadow].m_Element.m_pFlashlightDepthTexture != nullptr);
        m_Head = this->m_FlashlightStates.m_Memory.m_pMemory[v6].m_Next;
      }
      while ( m_Head != 0xFFFF );
      if ( v5 != nullptr )
      {
        v5->EndRender(this: v5);
        v5->Release(this: v5);
      }
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x1010D580
// Name: public: virtual void CShadowMgr::PopFlashlightScissorBounds(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::PopFlashlightScissorBounds(CShadowMgr *this)
{
  int v2; // ebx
  unsigned __int16 m_Head; // ax
  CShadowMgr::FlashLightScissorStateBackup_t *m_pMemory; // ecx
  int p_m_nTop; // edi
  int v6; // edx
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *v7; // eax

  v2 = this->m_ScissorStateEntryStart.m_Memory.m_pMemory[--this->m_ScissorStateEntryStart.m_Size];
  if ( v2 != this->m_ScissorStateBackups.m_Size )
  {
    m_Head = this->m_FlashlightStates.m_Head;
    m_pMemory = this->m_ScissorStateBackups.m_Memory.m_pMemory;
    if ( m_Head != 0xFFFF )
    {
      p_m_nTop = (int)&m_pMemory[v2].m_nTop;
      do
      {
        v6 = m_Head;
        v7 = &this->m_FlashlightStates.m_Memory.m_pMemory[v6];
        if ( v7->m_Element.m_nSplitscreenOwner == 0 )
        {
          v7->m_Element.m_FlashlightState.m_bScissor = *(_BYTE *)(p_m_nTop + 12);
          v7->m_Element.m_FlashlightState.m_nLeft = *(_DWORD *)(p_m_nTop - 4);
          v7->m_Element.m_FlashlightState.m_nTop = *(_DWORD *)p_m_nTop;
          v7->m_Element.m_FlashlightState.m_nRight = *(_DWORD *)(p_m_nTop + 4);
          v7->m_Element.m_FlashlightState.m_nBottom = *(_DWORD *)(p_m_nTop + 8);
          p_m_nTop += 20;
        }
        m_Head = this->m_FlashlightStates.m_Memory.m_pMemory[v6].m_Next;
      }
      while ( m_Head != 0xFFFF );
    }
    this->m_ScissorStateBackups.m_Size -= this->m_ScissorStateBackups.m_Size - v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010D650
// Name: public: virtual void CShadowMgr::SetFlashlightRenderState(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::SetFlashlightRenderState(CShadowMgr *this, unsigned __int16 handle)
{
  IMatRenderContext *v3; // esi
  IMatRenderContext_vtbl *v4; // edx
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v5; // edi

  v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  v4 = v3->__vftable;
  if ( handle == 0xFFFF )
  {
    v4->SetFlashlightMode(this: v3, a2: false);
  }
  else
  {
    v5 = &this->m_Shadows.m_Memory.m_pMemory[handle];
    v4->SetFlashlightMode(this: v3, a2: true);
    v3->SetFlashlightStateEx(
      this: v3,
      a2: &this->m_FlashlightStates.m_Memory.m_pMemory[v5->m_Element.m_FlashlightHandle].m_Element.m_FlashlightState,
      a3: &v5->m_Element.m_WorldToShadow,
      a4: v5->m_Element.m_pFlashlightDepthTexture);
  }
  v3->EndRender(this: v3);
  v3->Release(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1010E3F0
// Name: public: virtual void CShadowMgr::DrawFlashlightDecals(class IMatRenderContext __near *,int,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CShadowMgr::DrawFlashlightDecals(
        CShadowMgr *this@<ecx>,
        int a2@<ebx>,
        IMatRenderContext *pRenderContext,
        int sortGroup,
        bool bDoMasking,
        float flFade)
{
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *m_pMemory; // edx
  int v10; // eax
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *v11; // esi
  int v12; // eax
  int v13; // ecx
  const CShadowMgr::FlashlightInfo_t *v14; // esi
  IMatRenderContext *pRenderContexta; // [esp+3Ch] [ebp+8h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CShadowMgr::DrawFlashlightDecals",
    a3: 0,
    a4: "Shadow_Rendering",
    a5: false,
    a6: 4);
  if ( this->m_bSinglePassFlashlightStateEnabled || (m_Head = this->m_FlashlightStates.m_Head) == 0xFFFF )
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    ((void (__thiscall *)(IMatRenderContext *, int, int))pRenderContext->SetFlashlightMode)(
      a1: pRenderContext,
      a2: 1,
      a3: a2);
    do
    {
      m_pMemory = this->m_Shadows.m_Memory.m_pMemory;
      v10 = m_Head;
      v11 = this->m_FlashlightStates.m_Memory.m_pMemory;
      v12 = 768 * v10;
      v13 = *(unsigned __int16 *)((char *)&v11->m_Element.m_Shadow + v12);
      v14 = (CShadowMgr::FlashlightInfo_t *)((char *)&v11->m_Element + v12);
      pRenderContexta = (IMatRenderContext *)v12;
      if ( (m_pMemory[v13].m_Element.m_Flags & 4) == 0 && v14->m_nSplitscreenOwner == 0 )
      {
        pRenderContext->SetFlashlightStateEx(
          this: pRenderContext,
          a2: &v14->m_FlashlightState,
          a3: (const VMatrix *)&m_pMemory[v14->m_Shadow],
          a4: m_pMemory[v14->m_Shadow].m_Element.m_pFlashlightDepthTexture);
        CShadowMgr::EnableStencilAndScissorMasking(this, pRenderContext, flashlightInfo: v14, bDoMasking);
        DecalSurfaceDraw(pRenderContext, renderGroup: sortGroup, flFade);
        CShadowMgr::DisableStencilAndScissorMasking(this, pRenderContext, flashlightInfo: v14, bDoMasking);
        v12 = (int)pRenderContexta;
      }
      m_Head = *(unsigned __int16 *)((char *)&this->m_FlashlightStates.m_Memory.m_pMemory->m_Next + v12);
    }
    while ( m_Head != 0xFFFF );
    pRenderContext->SetFlashlightMode(this: pRenderContext, a2: false);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010E530
// Name: public: virtual void CShadowMgr::FlashlightDrawCallback(void (*)(void __near *),void __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CShadowMgr::FlashlightDrawCallback(
        CShadowMgr *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        void (__cdecl *pCallback)(void *),
        void *pData)
{
  unsigned __int16 m_Head; // si
  int v7; // eax
  IMatRenderContext *v8; // edi
  int v9; // eax
  const CShadowMgr::FlashlightInfo_t *v10; // esi
  int v12; // [esp+4h] [ebp-4h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CShadowMgr::FlashlightDrawCallback",
    a3: 0,
    a4: "Shadow_Rendering",
    a5: false,
    a6: 4);
  if ( this->m_bSinglePassFlashlightStateEnabled || (m_Head = this->m_FlashlightStates.m_Head) == 0xFFFF )
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    v7 = ((int (__thiscall *)(IMaterialSystem *, int, int))materials->GetRenderContext)(a1: materials, a2, a3);
    v8 = (IMatRenderContext *)v7;
    if ( v7 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 8))(a1: v7);
    v8->SetFlashlightMode(this: v8, a2: true);
    do
    {
      v9 = 768 * m_Head;
      v10 = (CShadowMgr::FlashlightInfo_t *)((char *)&this->m_FlashlightStates.m_Memory.m_pMemory->m_Element + v9);
      v12 = v9;
      if ( v10->m_nSplitscreenOwner == 0 )
      {
        v8->SetFlashlightStateEx(
          this: v8,
          a2: &v10->m_FlashlightState,
          a3: &this->m_Shadows.m_Memory.m_pMemory[v10->m_Shadow].m_Element.m_WorldToShadow,
          a4: this->m_Shadows.m_Memory.m_pMemory[v10->m_Shadow].m_Element.m_pFlashlightDepthTexture);
        CShadowMgr::EnableStencilAndScissorMasking(this, pRenderContext: v8, flashlightInfo: v10, bDoMasking: false);
        pCallback(a1: pData);
        CShadowMgr::DisableStencilAndScissorMasking(this, pRenderContext: v8, flashlightInfo: v10, bDoMasking: false);
        v9 = v12;
      }
      m_Head = *(unsigned __int16 *)((char *)&this->m_FlashlightStates.m_Memory.m_pMemory->m_Next + v9);
    }
    while ( m_Head != 0xFFFF );
    v8->SetFlashlightMode(this: v8, a2: false);
    v8->EndRender(this: v8);
    v8->Release(this: v8);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010E680
// Name: public: virtual void CShadowMgr::PopSinglePassFlashlightStateEnabled(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::PopSinglePassFlashlightStateEnabled(CShadowMgr *this)
{
  bool v2; // bl
  IMatRenderContext *v3; // eax
  void (__thiscall *SetFlashlightRenderState)(struct CShadowMgr *, unsigned __int16); // edx
  IMatRenderContext *v5; // eax
  bool bEnable; // [esp+8h] [ebp-4h]

  --this->m_bStack_SinglePassFlashlightStateEnabled.m_Size;
  v2 = false;
  bEnable = false;
  if ( this->m_bStack_SinglePassFlashlightStateEnabled.m_Size != 0 )
  {
    v2 = this->m_bStack_SinglePassFlashlightStateEnabled.m_Memory.m_pMemory[this->m_bStack_SinglePassFlashlightStateEnabled.m_Size
                                                                          - 1];
    bEnable = v2;
  }
  if ( this->m_bSinglePassFlashlightStateEnabled != v2 )
  {
    v3 = materials->GetRenderContext(this: materials);
    v3->EnableSinglePassFlashlightMode(this: v3, a2: bEnable);
    SetFlashlightRenderState = this->SetFlashlightRenderState;
    if ( v2 )
      SetFlashlightRenderState(this, a2: this->m_hSinglePassFlashlightState);
    else
      SetFlashlightRenderState(this, a2: 0xFFFFu);
    this->m_bSinglePassFlashlightStateEnabled = v2;
  }
  if ( this->m_bSinglePassFlashlightStateEnabled )
  {
    v5 = materials->GetRenderContext(this: materials);
    v5->EnableCullingForSinglePassFlashlight(this: v5, a2: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010E730
// Name: public: virtual void CShadowMgr::DrawFlashlightDecalsOnDisplacements(class IMatRenderContext __near *,int,class CDispInfo __near * __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CShadowMgr::DrawFlashlightDecalsOnDisplacements(
        CShadowMgr *this@<ecx>,
        int a2@<edi>,
        IMatRenderContext *pRenderContext,
        int sortGroup,
        CDispInfo **visibleDisps,
        int nVisibleDisps,
        bool bDoMasking)
{
  unsigned __int16 m_Head; // si
  int v10; // eax
  const CShadowMgr::FlashlightInfo_t *v11; // esi
  IMatRenderContext *pRenderContexta; // [esp+Ch] [ebp+8h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CShadowMgr::DrawFlashlightDecalsOnDisplacements",
    a3: 0,
    a4: "Shadow_Rendering",
    a5: false,
    a6: 4);
  if ( this->m_bSinglePassFlashlightStateEnabled || (m_Head = this->m_FlashlightStates.m_Head) == 0xFFFF )
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    ((void (__thiscall *)(IMatRenderContext *, int, int))pRenderContext->SetFlashlightMode)(
      a1: pRenderContext,
      a2: 1,
      a3: a2);
    DispInfo_BatchDecals(pVisibleDisps: visibleDisps, nVisibleDisps);
    do
    {
      v10 = 768 * m_Head;
      v11 = (CShadowMgr::FlashlightInfo_t *)((char *)&this->m_FlashlightStates.m_Memory.m_pMemory->m_Element + v10);
      pRenderContexta = (IMatRenderContext *)v10;
      if ( v11->m_nSplitscreenOwner == 0 )
      {
        pRenderContext->SetFlashlightStateEx(
          this: pRenderContext,
          a2: &v11->m_FlashlightState,
          a3: (const VMatrix *)&this->m_Shadows.m_Memory.m_pMemory[v11->m_Shadow],
          a4: this->m_Shadows.m_Memory.m_pMemory[v11->m_Shadow].m_Element.m_pFlashlightDepthTexture);
        CShadowMgr::EnableStencilAndScissorMasking(this, pRenderContext, flashlightInfo: v11, bDoMasking);
        DispInfo_DrawDecals(pRenderContext, visibleDisps, nVisibleDisps);
        CShadowMgr::DisableStencilAndScissorMasking(this, pRenderContext, flashlightInfo: v11, bDoMasking);
        v10 = (int)pRenderContexta;
      }
      m_Head = *(unsigned __int16 *)((char *)&this->m_FlashlightStates.m_Memory.m_pMemory->m_Next + v10);
    }
    while ( m_Head != 0xFFFF );
    pRenderContext->SetFlashlightMode(this: pRenderContext, a2: false);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010E870
// Name: public: virtual void CShadowMgr::DrawFlashlightDecalsOnSurfaceList(class IMatRenderContext __near *,struct msurface2_t __near * __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CShadowMgr::DrawFlashlightDecalsOnSurfaceList(
        CShadowMgr *this@<ecx>,
        int a2@<ebx>,
        IMatRenderContext *pRenderContext,
        msurface2_t **pList,
        int listCount,
        bool bDoMasking)
{
  CShadowMgr *v6; // edi
  unsigned __int16 m_Head; // si
  int v9; // eax
  const CShadowMgr::FlashlightInfo_t *v10; // esi
  int i; // edi
  msurface2_t *v12; // eax
  IMatRenderContext *pRenderContexta; // [esp+10h] [ebp+8h]

  v6 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CShadowMgr::DrawFlashlightDecalsOnSurfaceList",
    a3: 0,
    a4: "Shadow_Rendering",
    a5: false,
    a6: 4);
  if ( v6->m_bSinglePassFlashlightStateEnabled || (m_Head = v6->m_FlashlightStates.m_Head) == 0xFFFF )
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    ((void (__thiscall *)(IMatRenderContext *, int, int))pRenderContext->SetFlashlightMode)(
      a1: pRenderContext,
      a2: 1,
      a3: a2);
    do
    {
      v9 = 768 * m_Head;
      v10 = (CShadowMgr::FlashlightInfo_t *)((char *)&v6->m_FlashlightStates.m_Memory.m_pMemory->m_Element + v9);
      pRenderContexta = (IMatRenderContext *)v9;
      if ( v10->m_nSplitscreenOwner == 0 )
      {
        pRenderContext->SetFlashlightStateEx(
          this: pRenderContext,
          a2: &v10->m_FlashlightState,
          a3: (const VMatrix *)&v6->m_Shadows.m_Memory.m_pMemory[v10->m_Shadow],
          a4: v6->m_Shadows.m_Memory.m_pMemory[v10->m_Shadow].m_Element.m_pFlashlightDepthTexture);
        CShadowMgr::EnableStencilAndScissorMasking(this: v6, pRenderContext, flashlightInfo: v10, bDoMasking);
        for ( i = 0; i < listCount; ++i )
        {
          v12 = pList[i];
          if ( v12->decals != 0xFFFF )
            DrawDecalsOnSingleSurface(pRenderContext, surfID: v12);
        }
        CShadowMgr::DisableStencilAndScissorMasking(this, pRenderContext, flashlightInfo: v10, bDoMasking);
        v6 = this;
        v9 = (int)pRenderContexta;
      }
      m_Head = *(unsigned __int16 *)((char *)&v6->m_FlashlightStates.m_Memory.m_pMemory->m_Next + v9);
    }
    while ( m_Head != 0xFFFF );
    pRenderContext->SetFlashlightMode(this: pRenderContext, a2: false);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010E9D0
// Name: public: virtual void CShadowMgr::DrawFlashlightOverlays(class IMatRenderContext __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CShadowMgr::DrawFlashlightOverlays(
        CShadowMgr *this@<ecx>,
        int a2@<edi>,
        IMatRenderContext *pRenderContext,
        int nSortGroup,
        bool bDoMasking)
{
  unsigned __int16 m_Head; // si
  int v8; // eax
  const CShadowMgr::FlashlightInfo_t *v9; // esi
  IOverlayMgr *v10; // eax
  IMatRenderContext *pRenderContexta; // [esp+Ch] [ebp+8h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CShadowMgr::DrawFlashlightOverlays",
    a3: 0,
    a4: "Shadow_Rendering",
    a5: false,
    a6: 4);
  if ( !this->m_bSinglePassFlashlightStateEnabled
    && (m_Head = this->m_FlashlightStates.m_Head) != 0xFFFF
    && r_flashlightrender.m_pParent != nullptr
    && r_flashlightrender.m_pParent->m_Value.m_nValue != 0 )
  {
    ((void (__thiscall *)(IMatRenderContext *, int, int))pRenderContext->SetFlashlightMode)(
      a1: pRenderContext,
      a2: 1,
      a3: a2);
    do
    {
      v8 = 768 * m_Head;
      v9 = (CShadowMgr::FlashlightInfo_t *)((char *)&this->m_FlashlightStates.m_Memory.m_pMemory->m_Element + v8);
      pRenderContexta = (IMatRenderContext *)v8;
      if ( v9->m_nSplitscreenOwner == 0 )
      {
        pRenderContext->SetFlashlightStateEx(
          this: pRenderContext,
          a2: &v9->m_FlashlightState,
          a3: (const VMatrix *)&this->m_Shadows.m_Memory.m_pMemory[v9->m_Shadow],
          a4: this->m_Shadows.m_Memory.m_pMemory[v9->m_Shadow].m_Element.m_pFlashlightDepthTexture);
        CShadowMgr::EnableStencilAndScissorMasking(this, pRenderContext, flashlightInfo: v9, bDoMasking);
        v10 = OverlayMgr();
        v10->RenderOverlays(this: v10, a2: pRenderContext, a3: nSortGroup);
        CShadowMgr::DisableStencilAndScissorMasking(this, pRenderContext, flashlightInfo: v9, bDoMasking);
        v8 = (int)pRenderContexta;
      }
      m_Head = *(unsigned __int16 *)((char *)&this->m_FlashlightStates.m_Memory.m_pMemory->m_Next + v8);
    }
    while ( m_Head != 0xFFFF );
    pRenderContext->SetFlashlightMode(this: pRenderContext, a2: false);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010EB10
// Name: public: virtual void CShadowMgr::DrawFlashlightDepthTexture(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CShadowMgr::DrawFlashlightDepthTexture(
        CShadowMgr *this@<ecx>,
        CMeshBuilder *p_meshBuilder@<ebx>,
        int a3@<edi>,
        int m_nIndexCount@<esi>)
{
  unsigned __int16 m_Head; // ax
  int v5; // eax
  char *v6; // esi
  bool v7; // zf
  IMaterial *v8; // edi
  int v9; // ebx
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *m_pMemory; // ecx
  void (__thiscall *v11)(int, ITexture *, int, int, CMeshBuilder *); // edx
  IMatRenderContext *v12; // esi
  IMesh *v13; // edi
  float *m_pCurrPosition; // eax
  float v15; // xmm5_4
  float v16; // xmm2_4
  float *v17; // eax
  int v18; // eax
  float *v19; // eax
  float v20; // xmm4_4
  float v21; // xmm1_4
  float *v22; // eax
  int v23; // eax
  float *v24; // eax
  float v25; // xmm2_4
  float *v26; // eax
  int v27; // eax
  float *v28; // eax
  float *v29; // eax
  int m_nVertexCount; // eax
  int v31; // ecx
  ITexture *m_pFlashlightDepthTexture; // [esp-10h] [ebp-218h]
  CMeshBuilder meshBuilder; // [esp+0h] [ebp-208h] BYREF
  float hOffset; // [esp+1E8h] [ebp-20h]
  int v38; // [esp+1ECh] [ebp-1Ch]
  IMaterialVar *FrameVar; // [esp+1F0h] [ebp-18h]
  float h; // [esp+1F4h] [ebp-14h]
  float wOffset; // [esp+1F8h] [ebp-10h]
  CShadowMgr *v42; // [esp+1FCh] [ebp-Ch]
  int i; // [esp+200h] [ebp-8h]
  bool foundVar; // [esp+207h] [ebp-1h] BYREF

  m_Head = this->m_FlashlightStates.m_Head;
  v42 = this;
  for ( i = 0;
        m_Head != 0xFFFF;
        m_Head = *(unsigned __int16 *)((char *)&this->m_FlashlightStates.m_Memory.m_pMemory->m_Next + v5) )
  {
    v5 = 768 * m_Head;
    v6 = (char *)this->m_FlashlightStates.m_Memory.m_pMemory + v5;
    v7 = *((_DWORD *)v6 + 184) == 0;
    v38 = v5;
    if ( v7
      && this->m_Shadows.m_Memory.m_pMemory[*((unsigned __int16 *)v6 + 286)].m_Element.m_pFlashlightDepthTexture != nullptr )
    {
      v8 = materials->FindMaterial(this: materials, a2: "debug/showz", a3: "Other textures", a4: 1, a5: 0);
      v9 = (int)v8->FindVar(this: v8, a2: "$basetexture", a3: &foundVar, a4: false);
      if ( !foundVar )
        return;
      FrameVar = v8->FindVar(this: v8, a2: "$frame", a3: &foundVar, a4: false);
      if ( !foundVar )
        return;
      h = r_flashlightdrawdepthres.m_pParent->m_Value.m_fValue;
      m_pMemory = v42->m_Shadows.m_Memory.m_pMemory;
      v11 = *(void (__thiscall **)(int, ITexture *, int, int, CMeshBuilder *))(*(_DWORD *)v9 + 60);
      wOffset = (float)(i % 2) * 256.0;
      m_pFlashlightDepthTexture = m_pMemory[*((unsigned __int16 *)v6 + 286)].m_Element.m_pFlashlightDepthTexture;
      hOffset = (float)(i / 2) * 256.0;
      v11(a1: v9, a2: m_pFlashlightDepthTexture, a3, a4: m_nIndexCount, a5: p_meshBuilder);
      FrameVar->SetIntValue(this: FrameVar, a2: 0);
      v12 = materials->GetRenderContext(this: materials);
      if ( v12 != nullptr )
        v12->BeginRender(this: v12);
      v12->Bind(this: v12, a2: v8, a3: nullptr);
      v13 = v12->GetDynamicMesh(this: v12, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
      CMeshBuilder::CMeshBuilder(this: &meshBuilder);
      meshBuilder.m_pMesh = v13;
      meshBuilder.m_bGenerateIndices = true;
      meshBuilder.m_Type = MATERIAL_QUADS;
      v13->SetPrimitiveType(this: v13, a2: MATERIAL_TRIANGLES);
      meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
      meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v13->IIndexBuffer;
      meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
      meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
      meshBuilder.m_IndexBuilder.m_bModify = false;
      meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      CVertexBuilder::AttachBegin(
        this: &meshBuilder.m_VertexBuilder,
        pMesh: v13,
        nMaxVertexCount: 4,
        desc: &meshBuilder);
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
      m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      v15 = wOffset;
      v16 = hOffset;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = wOffset;
      m_pCurrPosition[1] = v16;
      m_pCurrPosition[2] = 0.0;
      v17 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
      v17[1] = 0.0;
      v18 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
      meshBuilder.m_VertexBuilder.m_nCurrentVertex = v18;
      if ( v18 > meshBuilder.m_VertexBuilder.m_nVertexCount )
        meshBuilder.m_VertexBuilder.m_nVertexCount = v18;
      v19 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                    + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
      meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                               + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
      v20 = h;
      meshBuilder.m_VertexBuilder.m_pCurrPosition = v19;
      v21 = v15 + h;
      *v19 = v15 + h;
      v19[1] = v16;
      v19[2] = 0.0;
      v22 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
      v22[1] = 0.0;
      v23 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
      meshBuilder.m_VertexBuilder.m_nCurrentVertex = v23;
      if ( v23 > meshBuilder.m_VertexBuilder.m_nVertexCount )
        meshBuilder.m_VertexBuilder.m_nVertexCount = v23;
      v24 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                    + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
      meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                               + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
      meshBuilder.m_VertexBuilder.m_pCurrPosition = v24;
      *v24 = v21;
      v25 = v16 + v20;
      v24[1] = v25;
      v24[2] = 0.0;
      v26 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
      v26[1] = 1.0;
      v27 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
      meshBuilder.m_VertexBuilder.m_nCurrentVertex = v27;
      if ( v27 > meshBuilder.m_VertexBuilder.m_nVertexCount )
        meshBuilder.m_VertexBuilder.m_nVertexCount = v27;
      v28 = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                    + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
      meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                               + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
      meshBuilder.m_VertexBuilder.m_pCurrPosition = v28;
      *v28 = v15;
      v28[1] = v25;
      v28[2] = 0.0;
      v29 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
      v29[1] = 1.0;
      m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
      v31 = meshBuilder.m_VertexBuilder.m_nCurrentVertex + 1;
      meshBuilder.m_VertexBuilder.m_nCurrentVertex = v31;
      if ( v31 > meshBuilder.m_VertexBuilder.m_nVertexCount )
      {
        m_nVertexCount = v31;
        meshBuilder.m_VertexBuilder.m_nVertexCount = v31;
      }
      meshBuilder.m_VertexBuilder.m_pCurrPosition = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrPosition
                                                            + meshBuilder.m_VertexBuilder.m_VertexSize_Position);
      meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = (float *)((char *)meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0]
                                                               + meshBuilder.m_VertexBuilder.m_VertexSize_TexCoord[0]);
      if ( meshBuilder.m_bGenerateIndices )
      {
        switch ( meshBuilder.m_Type )
        {
          case MATERIAL_LINE_STRIP:
            m_nVertexCount = 2 * m_nVertexCount - 2;
            break;
          case MATERIAL_LINE_LOOP:
            m_nVertexCount *= 2;
            break;
          case MATERIAL_POLYGON:
            m_nVertexCount = 3 * m_nVertexCount - 6;
            break;
          case MATERIAL_QUADS:
            m_nVertexCount = 6 * m_nVertexCount / 4;
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
      a3 = m_nVertexCount;
      ((void (__thiscall *)(IMesh *))meshBuilder.m_pMesh->UnlockMesh)(a1: meshBuilder.m_pMesh);
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
      meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
      meshBuilder.m_pMesh = nullptr;
      v13->Draw_2(this: v13, a2: -1, a3: 0);
      ++i;
      CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
      v12->EndRender(this: v12);
      v12->Release(this: v12);
      v5 = v38;
      this = v42;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010EF80
// Name: public: CUtlMemoryAligned<struct UtlLinkedListElem_t<struct CShadowMgr::Shadow_t,unsigned short>,16>::~CUtlMemoryAligned<struct UtlLinkedListElem_t<struct CShadowMgr::Shadow_t,unsigned short>,16>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>::~CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>(
        CUtlMemoryAligned<Frustum_t,16> *this)
{
  bool v2; // sf

  if ( this->m_nGrowSize >= 0 )
  {
    if ( this->m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(((int)this->m_pMemory & 0xFFFFFFFC) - 4));
      this->m_pMemory = nullptr;
    }
    v2 = this->m_nGrowSize < 0;
    this->m_nAllocationCount = 0;
    if ( !v2 )
    {
      if ( this->m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pMemory);
        this->m_pMemory = nullptr;
      }
      this->m_nAllocationCount = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010F7D0
// Name: public: virtual int CShadowMgr::GetNumShadowsOnModel(unsigned short)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShadowMgr::GetNumShadowsOnModel(CShadowMgr *this, int instance)
{
  int m_Next; // ecx
  int result; // eax

  if ( (_WORD)instance == 0xFFFF
    || r_shadows.m_pParent == nullptr
    || r_shadows.m_pParent->m_Value.m_nValue == 0
    || this->m_bShadowsDisabled )
  {
    return 0;
  }
  m_Next = *this->m_ShadowsOnModels.m_FirstElement(a1: instance);
  for ( result = 0; m_Next != 0xFFFF; ++result )
    m_Next = this->m_ShadowsOnModels.m_ElementsInBucket.m_Memory.m_pMemory[(unsigned __int16)m_Next].m_Next;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1010F840
// Name: public: virtual int CShadowMgr::GetShadowsOnModel(unsigned short,unsigned short __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShadowMgr::GetShadowsOnModel(
        CShadowMgr *this,
        int instance,
        unsigned __int16 *pShadowArray,
        bool bNormalShadows,
        bool bFlashlightShadows)
{
  int m_Next; // ecx
  int v8; // ecx
  int nCount; // [esp+Ch] [ebp+8h]

  if ( (_WORD)instance == 0xFFFF
    || r_shadows.m_pParent == nullptr
    || r_shadows.m_pParent->m_Value.m_nValue == 0
    || this->m_bShadowsDisabled )
  {
    return 0;
  }
  m_Next = *this->m_ShadowsOnModels.m_FirstElement(a1: instance);
  nCount = 0;
  if ( m_Next != 0xFFFF )
  {
    while ( 1 )
    {
      v8 = (unsigned __int16)m_Next;
      if ( (this->m_Shadows.m_Memory.m_pMemory[this->m_ShadowsOnModels.m_ElementsInBucket.m_Memory.m_pMemory[v8].m_Element.m_Element].m_Element.m_Flags
          & 6) != 0 )
        break;
      if ( bNormalShadows )
        goto LABEL_10;
LABEL_11:
      m_Next = this->m_ShadowsOnModels.m_ElementsInBucket.m_Memory.m_pMemory[v8].m_Next;
      if ( m_Next == 0xFFFF )
        return nCount;
    }
    if ( !bFlashlightShadows )
      goto LABEL_11;
LABEL_10:
    *pShadowArray++ = this->m_ShadowsOnModels.m_ElementsInBucket.m_Memory.m_pMemory[v8].m_Element.m_Element;
    ++nCount;
    goto LABEL_11;
  }
  return nCount;
}

//------------------------------------------------------------------------------
// Address: 0x1010F910
// Name: public: virtual void CShadowMgr::SetModelShadowState(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::SetModelShadowState(CShadowMgr *this, int instance)
{
  int v3; // eax
  int i; // eax
  int v5; // edi
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v6; // eax
  __int16 v7; // cx
  bool instance_3; // [esp+Fh] [ebp+Bh]

  g_pStudioRender->ClearAllShadows(this: g_pStudioRender);
  if ( (_WORD)instance != 0xFFFF
    && r_shadows.m_pParent != nullptr
    && r_shadows.m_pParent->m_Value.m_nValue != 0
    && !this->m_bShadowsDisabled )
  {
    v3 = r_shadowwireframe.m_pParent != nullptr ? r_shadowwireframe.m_pParent->m_Value.m_nValue : 0;
    instance_3 = v3 != 0;
    for ( i = *this->m_ShadowsOnModels.m_FirstElement(a1: instance);
          i != 0xFFFF;
          i = this->m_ShadowsOnModels.m_ElementsInBucket.m_Memory.m_pMemory[v5].m_Next )
    {
      v5 = (unsigned __int16)i;
      v6 = &this->m_Shadows.m_Memory.m_pMemory[this->m_ShadowsOnModels.m_ElementsInBucket.m_Memory.m_pMemory[v5].m_Element.m_Element];
      v7 = v6->m_Element.m_Flags & 6;
      if ( v7 == 0
        || this->m_FlashlightStates.m_Memory.m_pMemory[v6->m_Element.m_FlashlightHandle].m_Element.m_nSplitscreenOwner == 0 )
      {
        if ( instance_3 )
        {
          if ( v7 != 0
            || r_shadows_gamecontrol.m_pParent != nullptr && r_shadows_gamecontrol.m_pParent->m_Value.m_nValue != 0 )
          {
            g_pStudioRender->AddShadow(
              this: g_pStudioRender,
              a2: g_pMaterialMRMWireframe,
              a3: nullptr,
              a4: nullptr,
              a5: nullptr,
              a6: nullptr);
          }
        }
        else if ( v7 != 0 )
        {
          ((void (__stdcall *)(_DWORD, _DWORD, FlashlightState_t *, UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *, ITexture *))g_pStudioRender->AddShadow)(
            a1: 0,
            a2: 0,
            a3: &this->m_FlashlightStates.m_Memory.m_pMemory[v6->m_Element.m_FlashlightHandle].m_Element.m_FlashlightState,
            a4: v6,
            a5: v6->m_Element.m_pFlashlightDepthTexture);
        }
        else if ( r_shadows_gamecontrol.m_pParent != nullptr && r_shadows_gamecontrol.m_pParent->m_Value.m_nValue != 0 )
        {
          g_pStudioRender->AddShadow(
            this: g_pStudioRender,
            a2: v6->m_Element.m_pModelMaterial,
            a3: v6->m_Element.m_pBindProxy,
            a4: nullptr,
            a5: nullptr,
            a6: nullptr);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010FAA0
// Name: public: virtual int CShadowMgr::SetupFlashlightRenderInstanceInfo(unsigned short __near *,unsigned int __near *,int,int,unsigned short const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShadowMgr::SetupFlashlightRenderInstanceInfo(
        CShadowMgr *this,
        unsigned __int16 *pShadowHandle,
        unsigned int *pModelUsageMask,
        int nUsageStride,
        int nInstanceCount,
        const unsigned __int16 *pInstance)
{
  IMatRenderContext *v7; // esi
  int v8; // ebx
  int v10; // esi
  int v11; // eax
  int m_Next; // eax
  int v13; // esi
  unsigned __int16 m_Element; // dx
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v15; // eax
  int j; // ecx
  CMatRenderContextPtr pRenderContext; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  int nFlashlightCount; // [esp+14h] [ebp-4h]

  v7 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v7;
  if ( v7 != nullptr )
    v7->BeginRender(this: v7);
  v8 = 0;
  nFlashlightCount = 0;
  if ( (!this->SinglePassFlashlightModeEnabled(this) || v7->IsCullingEnabledForSinglePassFlashlight(this: v7))
    && r_shadows.m_pParent != nullptr
    && r_shadows.m_pParent->m_Value.m_nValue != 0 )
  {
    v10 = 0;
    for ( i = 0; v10 < nInstanceCount; i = v10 )
    {
      v11 = pInstance[v10];
      *pModelUsageMask = 0;
      if ( (_WORD)v11 != 0xFFFF )
      {
        m_Next = *this->m_ShadowsOnModels.m_FirstElement(a1: v11);
        if ( m_Next != 0xFFFF )
        {
          do
          {
            v13 = (unsigned __int16)m_Next;
            m_Element = this->m_ShadowsOnModels.m_ElementsInBucket.m_Memory.m_pMemory[v13].m_Element.m_Element;
            v15 = &this->m_Shadows.m_Memory.m_pMemory[m_Element];
            if ( (v15->m_Element.m_Flags & 6) != 0
              && this->m_FlashlightStates.m_Memory.m_pMemory[v15->m_Element.m_FlashlightHandle].m_Element.m_nSplitscreenOwner == 0 )
            {
              for ( j = 0; j < v8; ++j )
              {
                if ( pShadowHandle[j] == m_Element )
                  break;
              }
              *pModelUsageMask |= 1 << j;
              v8 = nFlashlightCount;
              if ( j == nFlashlightCount )
              {
                v8 = nFlashlightCount + 1;
                pShadowHandle[j] = m_Element;
                ++nFlashlightCount;
              }
            }
            m_Next = this->m_ShadowsOnModels.m_ElementsInBucket.m_Memory.m_pMemory[v13].m_Next;
          }
          while ( m_Next != 0xFFFF );
          v10 = i;
        }
      }
      pModelUsageMask = (unsigned int *)((char *)pModelUsageMask + nUsageStride);
      ++v10;
    }
    if ( pRenderContext.m_pObject != nullptr )
    {
      ((void (__thiscall *)(CMatRenderContextPtr))pRenderContext.m_pObject->EndRender)(a1: pRenderContext);
      ((void (__thiscall *)(CMatRenderContextPtr))pRenderContext.m_pObject->Release)(a1: pRenderContext);
    }
    return v8;
  }
  else
  {
    if ( v7 != nullptr )
    {
      v7->EndRender(this: v7);
      v7->Release(this: v7);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010FC40
// Name: public: virtual void CShadowMgr::PushSinglePassFlashlightStateEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::PushSinglePassFlashlightStateEnabled(CShadowMgr *this, BOOL bEnable)
{
  bool *m_pMemory; // eax
  int m_Size; // ecx
  bool *v5; // eax
  IMatRenderContext *v6; // eax
  IMatRenderContext *v7; // eax

  if ( this->m_bStack_SinglePassFlashlightStateEnabled.m_Size >= this->m_bStack_SinglePassFlashlightStateEnabled.m_Memory.m_nAllocationCount )
    CUtlMemory<bool,int>::Grow(this: (CUtlMemory<char,int> *)&this->m_bStack_SinglePassFlashlightStateEnabled, num: 1);
  ++this->m_bStack_SinglePassFlashlightStateEnabled.m_Size;
  m_pMemory = this->m_bStack_SinglePassFlashlightStateEnabled.m_Memory.m_pMemory;
  m_Size = this->m_bStack_SinglePassFlashlightStateEnabled.m_Size;
  this->m_bStack_SinglePassFlashlightStateEnabled.m_pElements = m_pMemory;
  v5 = &m_pMemory[m_Size - 1];
  if ( v5 != nullptr )
    *v5 = bEnable;
  if ( this->m_bSinglePassFlashlightStateEnabled != bEnable )
  {
    v6 = materials->GetRenderContext(this: materials);
    v6->EnableSinglePassFlashlightMode(this: v6, a2: bEnable);
    if ( bEnable )
      ((void (__stdcall *)(_DWORD))this->SetFlashlightRenderState)(a1: this->m_hSinglePassFlashlightState);
    else
      ((void (__stdcall *)(int))this->SetFlashlightRenderState)(a1: 0xFFFF);
    this->m_bSinglePassFlashlightStateEnabled = bEnable;
  }
  if ( this->m_bSinglePassFlashlightStateEnabled )
  {
    v7 = materials->GetRenderContext(this: materials);
    v7->EnableCullingForSinglePassFlashlight(this: v7, a2: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1010FE50
// Name: public: CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short> *__thiscall CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>(
        CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short> *this)
{
  this->m_ElementsInBucket.m_Memory.m_pMemory = nullptr;
  this->m_ElementsInBucket.m_Memory.m_nAllocationCount = 0;
  this->m_ElementsInBucket.m_Memory.m_nGrowSize = 0;
  this->m_ElementsInBucket.m_LastAlloc.index = -1;
  this->m_ElementsInBucket.m_Head = -1;
  this->m_ElementsInBucket.m_Tail = -1;
  this->m_ElementsInBucket.m_FirstFree = -1;
  this->m_ElementsInBucket.m_ElementCount = 0;
  this->m_ElementsInBucket.m_NumAlloced = 0;
  this->m_ElementsInBucket.m_pElements = this->m_ElementsInBucket.m_Memory.m_pMemory;
  this->m_BucketsUsedByElement.m_Memory.m_pMemory = nullptr;
  this->m_BucketsUsedByElement.m_Memory.m_nAllocationCount = 0;
  this->m_BucketsUsedByElement.m_Memory.m_nGrowSize = 0;
  this->m_BucketsUsedByElement.m_LastAlloc.index = -1;
  this->m_BucketsUsedByElement.m_Head = -1;
  this->m_BucketsUsedByElement.m_Tail = -1;
  this->m_BucketsUsedByElement.m_FirstFree = -1;
  this->m_BucketsUsedByElement.m_ElementCount = 0;
  this->m_BucketsUsedByElement.m_NumAlloced = 0;
  this->m_BucketsUsedByElement.m_pElements = this->m_BucketsUsedByElement.m_Memory.m_pMemory;
  this->m_FirstBucket = nullptr;
  this->m_FirstElement = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10110230
// Name: public: CMaterialsBuckets<struct msurface2_t __near *>::~CMaterialsBuckets<struct msurface2_t __near *>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialsBuckets<msurface2_t *>::~CMaterialsBuckets<msurface2_t *>(
        CMaterialsBuckets<msurface2_t *> *this)
{
  CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short>,unsigned short> > *)&this->m_Elements);
  if ( this->m_Elements.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_Memory.m_pMemory);
      this->m_Elements.m_Memory.m_pMemory = nullptr;
    }
    this->m_Elements.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_MaterialSortInfoArray);
  CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_UsedSortIDs);
  if ( this->m_UsedSortIDs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_UsedSortIDs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_UsedSortIDs.m_Memory.m_pMemory);
      this->m_UsedSortIDs.m_Memory.m_pMemory = nullptr;
    }
    this->m_UsedSortIDs.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110320
// Name: public: CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::~CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::~CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>(
        CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short> *this)
{
  CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_BucketsUsedByElement);
  if ( this->m_BucketsUsedByElement.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_BucketsUsedByElement.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_BucketsUsedByElement.m_Memory.m_pMemory);
      this->m_BucketsUsedByElement.m_Memory.m_pMemory = nullptr;
    }
    this->m_BucketsUsedByElement.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short>,unsigned short>>::RemoveAll((CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short>,unsigned short> > *)this);
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
// Address: 0x10110390
// Name: private: bool CShadowMgr::AddDecalToShadowList(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShadowMgr::AddDecalToShadowList(
        CShadowMgr *this,
        unsigned __int16 handle,
        unsigned __int16 decalHandle)
{
  int m_NumAlloced; // esi
  _WORD *v5; // eax
  int v6; // esi
  int v8; // edi
  int m_FirstDecal; // eax

  m_NumAlloced = this->m_ShadowSurfaces.m_NumAlloced;
  if ( m_NumAlloced > m_ShadowSurfacesMax )
  {
    if ( m_ShadowSurfacesMax / 0x2000 != m_NumAlloced / 0x2000 )
      _Warning(a1: "Shadow memory (%s) growing [%d]\n", "m_ShadowSurfaces", m_NumAlloced);
    m_ShadowSurfacesMax = m_NumAlloced;
  }
  v5 = (_WORD *)CUtlLinkedList<unsigned short,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int>>>::AllocInternal(
                  this: &this->m_ShadowSurfaces,
                  multilist: true);
  v6 = (int)v5;
  if ( v5 != nullptr )
  {
    v8 = handle;
    *v5 = decalHandle;
    m_FirstDecal = this->m_Shadows.m_Memory.m_pMemory[v8].m_Element.m_FirstDecal;
    if ( m_FirstDecal != 0 )
      CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::LinkBefore(
        this: (CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > > *)&this->m_ShadowSurfaces,
        before: m_FirstDecal,
        elem: v6);
    this->m_Shadows.m_Memory.m_pMemory[v8].m_Element.m_FirstDecal = v6;
    this->m_ShadowDecals.m_Memory.m_pMemory[decalHandle].m_Element.m_ShadowListIndex = v6;
    return 1;
  }
  else
  {
    if ( _executeCount_0 < 10 )
    {
      ++_executeCount_0;
      _Warning(a1: "CShadowMgr::AddDecalToShadowList - overflowed m_ShadowSurfaces linked list!\n");
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110460
// Name: private: unsigned short CShadowMgr::AddShadowDecalToSurface(struct msurface2_t __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShadowMgr::AddShadowDecalToSurface(CShadowMgr *this, msurface2_t *surfID, int handle)
{
  int m_NumAlloced; // esi
  CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int> > *p_m_ShadowDecals; // esi
  int v6; // eax
  int v8; // edi
  int v9; // esi
  unsigned int v10; // eax
  int decalHandle; // [esp+Ch] [ebp-10h]
  CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int> > *v13; // [esp+14h] [ebp-8h]
  unsigned __int16 v14; // [esp+18h] [ebp-4h]

  m_NumAlloced = this->m_ShadowDecals.m_NumAlloced;
  if ( m_NumAlloced > m_ShadowDecalsMax )
  {
    if ( m_ShadowDecalsMax / 0x2000 != m_NumAlloced / 0x2000 )
      _Warning(a1: "Shadow memory (%s) growing [%d]\n", "m_ShadowDecals", m_NumAlloced);
    m_ShadowDecalsMax = m_NumAlloced;
  }
  p_m_ShadowDecals = &this->m_ShadowDecals;
  v13 = &this->m_ShadowDecals;
  v6 = CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int>>::AllocInternal(
         this: &this->m_ShadowDecals,
         multilist: true);
  if ( v6 == 0xFFFF )
    v14 = -1;
  else
    v14 = v6;
  decalHandle = (unsigned __int16)v6;
  if ( (_WORD)v6 == 0xFFFF )
  {
    if ( `CShadowMgr::AddShadowDecalToSurface'::`6'::__executeCount < 10 )
    {
      ++`CShadowMgr::AddShadowDecalToSurface'::`6'::__executeCount;
      _Warning(a1: "CShadowMgr::AddShadowDecalToSurface - overflowed m_ShadowDecals linked list!\n");
    }
    return 0xFFFF;
  }
  else
  {
    v8 = (unsigned __int16)v6;
    v9 = (int)&p_m_ShadowDecals->m_Memory.m_pMemory[(unsigned __int16)v6];
    *(_DWORD *)v9 = surfID;
    CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int>>::LinkBefore(
      this: v13,
      before: surfID->m_ShadowDecals,
      elem: (unsigned __int16)v6);
    v10 = surfID->flags >> 11;
    surfID->m_ShadowDecals = v14;
    if ( (v10 & 1) != 0 )
      *(_WORD *)(v9 + 10) = surfID->pDispInfo->AddShadowDecal(this: surfID->pDispInfo, a2: handle);
    else
      *(_WORD *)(v9 + 10) = -1;
    *(_WORD *)(v9 + 8) = handle;
    *(_DWORD *)(v9 + 12) = -1;
    *(_DWORD *)(v9 + 4) = 0;
    if ( CShadowMgr::AddDecalToShadowList(this, handle, decalHandle: v14) != 0 )
    {
      return decalHandle;
    }
    else
    {
      CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int>>::Unlink(
        this: v13,
        elem: v8);
      v13->m_Memory.m_pMemory[v8].m_Next = v13->m_FirstFree;
      v13->m_FirstFree = v8;
      return 0xFFFF;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101105C0
// Name: private: void CShadowMgr::ApplyShadowToDisplacement(struct CShadowMgr::ShadowBuildInfo_t __near &,class IDispInfo __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::ApplyShadowToDisplacement(
        CShadowMgr *this,
        CShadowMgr::ShadowBuildInfo_t *build,
        IDispInfo *pDispInfo,
        bool bIsFlashlight)
{
  Frustum_t *v5; // eax
  msurface2_t *v6; // eax
  Vector bbMin; // [esp+18h] [ebp-18h] BYREF
  Vector bbMax; // [esp+24h] [ebp-Ch] BYREF

  if ( bIsFlashlight || (pDispInfo->GetParent(this: pDispInfo)->flags & 0x2000) == 0 )
  {
    pDispInfo->GetBoundingBox(this: pDispInfo, a2: &bbMin, a3: &bbMax);
    if ( bIsFlashlight )
    {
      v5 = (Frustum_t *)this->GetFlashlightFrustum(this, a2: build->m_Shadow);
      if ( Frustum_t::CullBox(this: v5, mins: &bbMin, maxs: &bbMax) )
        return;
    }
    else if ( !IsBoxIntersectingSphere(
                 boxMin: &bbMin,
                 boxMax: &bbMax,
                 center: &build->m_vecSphereCenter,
                 radius: build->m_flSphereRadius) )
    {
      return;
    }
    v6 = pDispInfo->GetParent(this: pDispInfo);
    if ( ((*((_BYTE *)v6 + 22) & 1) != 0 || bIsFlashlight)
      && ((this->m_Shadows.m_Memory.m_pMemory[build->m_Shadow].m_Element.m_Flags & 6) != 0 || (v6->flags & 0x3020) == 0) )
    {
      CShadowMgr::AddShadowDecalToSurface(this, surfID: v6, handle: build->m_Shadow);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110840
// Name: public: virtual void CShadowMgr::AddShadowToBrushModel(unsigned short,struct model_t __near *,class Vector const __near &,class QAngle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::AddShadowToBrushModel(
        CShadowMgr *this,
        int handle,
        model_t *pModel,
        const Vector *origin,
        const QAngle *angles)
{
  int v5; // edi
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v6; // esi
  model_t *v7; // edx
  msurface2_t *v8; // esi
  int i; // ebx
  unsigned int flags; // ecx
  matrix3x4_t worldToModel; // [esp+0h] [ebp-44h] BYREF
  Vector shadowDirInModelSpace; // [esp+30h] [ebp-14h] BYREF
  CShadowMgr *v13; // [esp+3Ch] [ebp-8h]
  bool bIsFlashlight; // [esp+43h] [ebp-1h]

  v13 = this;
  if ( r_shadows.m_pParent != nullptr && r_shadows.m_pParent->m_Value.m_nValue != 0 )
  {
    v5 = (unsigned __int16)handle;
    v6 = &this->m_Shadows.m_Memory.m_pMemory[v5];
    bIsFlashlight = (v6->m_Element.m_Flags & 6) != 0;
    if ( !bIsFlashlight )
    {
      AngleIMatrix(angles, matrix: &worldToModel);
      VectorRotate(in1: &v6->m_Element.m_ProjectionDir.x, in2: &worldToModel, out: &shadowDirInModelSpace.x);
    }
    v7 = pModel;
    v8 = (msurface2_t *)(*(_DWORD *)(pModel->sprite.numframes + 124) + 32 * pModel->brush.firstmodelsurface);
    for ( i = 0; i < v7->brush.nummodelsurfaces; ++v8 )
    {
      flags = v8->flags;
      if ( (v8->flags & 0x10) == 0
        && (bIsFlashlight
         || (flags & 0x200) != 0
         || (float)((float)((float)(v8->plane->normal.y * shadowDirInModelSpace.y)
                          + (float)(v8->plane->normal.x * shadowDirInModelSpace.x))
                  + (float)(v8->plane->normal.z * shadowDirInModelSpace.z)) <= 0.0)
        && ((v13->m_Shadows.m_Memory.m_pMemory[v5].m_Element.m_Flags & 6) != 0 || (flags & 0x3020) == 0) )
      {
        CShadowMgr::AddShadowDecalToSurface(this: v13, surfID: v8, handle);
        v7 = pModel;
      }
      ++i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110940
// Name: private: void CShadowMgr::ClearAllFlashlightMaterialBuckets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::ClearAllFlashlightMaterialBuckets(CShadowMgr *this)
{
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *m_pMemory; // ecx
  int v4; // esi
  CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short> > *p_m_UsedSortIDs; // edi

  if ( !this->m_bSinglePassFlashlightStateEnabled )
  {
    m_Head = this->m_FlashlightStates.m_Head;
    if ( m_Head != 0xFFFF )
    {
      m_pMemory = this->m_FlashlightStates.m_Memory.m_pMemory;
      do
      {
        v4 = m_Head;
        ++m_pMemory[v4].m_Element.m_MaterialBuckets.m_FlushCount;
        p_m_UsedSortIDs = &m_pMemory[v4].m_Element.m_MaterialBuckets.m_UsedSortIDs;
        CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short>,unsigned short> > *)&m_pMemory[v4].m_Element.m_MaterialBuckets.m_Elements);
        CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::RemoveAll(this: p_m_UsedSortIDs);
        m_pMemory = this->m_FlashlightStates.m_Memory.m_pMemory;
        m_Head = m_pMemory[v4].m_Next;
      }
      while ( m_Head != 0xFFFF );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101109B0
// Name: public: void CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::AddElementToBucket(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::AddElementToBucket(
        CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short> *this,
        unsigned __int16 *bucket,
        int element)
{
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // di
  unsigned __int16 v6; // ax
  unsigned __int16 v7; // bx
  int v8; // eax
  int v9; // eax
  unsigned __int16 *v10; // eax
  unsigned __int16 *v11; // esi
  CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *p_m_BucketsUsedByElement; // [esp+Ch] [ebp-4h]
  unsigned __int16 *firstElementInBucket; // [esp+18h] [ebp+8h]

  v4 = CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_ElementsInBucket,
         multilist: true);
  v5 = -1;
  if ( v4 != 0xFFFF )
    v5 = v4;
  p_m_BucketsUsedByElement = (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&this->m_BucketsUsedByElement;
  v6 = CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_BucketsUsedByElement,
         multilist: true);
  v7 = -1;
  if ( v6 != 0xFFFF )
    v7 = v6;
  v8 = v5;
  this->m_ElementsInBucket.m_Memory.m_pMemory[v8].m_Element.m_Element = element;
  this->m_ElementsInBucket.m_Memory.m_pMemory[v8].m_Element.m_BucketListIndex = v7;
  v9 = v7;
  LOWORD(p_m_BucketsUsedByElement->m_Memory.m_pMemory[v9].m_Element) = (_WORD)bucket;
  HIWORD(p_m_BucketsUsedByElement->m_Memory.m_pMemory[v9].m_Element) = v5;
  v10 = this->m_FirstElement(a1: bucket);
  firstElementInBucket = v10;
  if ( *v10 != 0xFFFF )
  {
    CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short>>::LinkBefore(
      (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)this,
      before: *v10,
      elem: v5);
    v10 = firstElementInBucket;
  }
  *v10 = v5;
  v11 = this->m_FirstBucket(a1: element);
  if ( *v11 != 0xFFFF )
    CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short>>::LinkBefore(
      this: p_m_BucketsUsedByElement,
      before: *v11,
      elem: v7);
  *v11 = v7;
}

//------------------------------------------------------------------------------
// Address: 0x10110A90
// Name: public: void CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::RemoveElement(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::RemoveElement(
        CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short> *this,
        int element)
{
  unsigned __int16 v3; // ax
  UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short> *v4; // eax
  int m_ElementListIndex; // edi
  UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short> *m_pMemory; // eax
  int v7; // edi
  unsigned __int16 v8; // [esp-Ch] [ebp-20h]
  int v9; // [esp+4h] [ebp-10h]
  unsigned __int16 m_Next; // [esp+8h] [ebp-Ch]
  int bucket; // [esp+Ch] [ebp-8h]
  unsigned __int16 i; // [esp+10h] [ebp-4h]

  v3 = *this->m_FirstBucket(a1: element);
  i = v3;
  if ( v3 != 0xFFFF )
  {
    while ( 1 )
    {
      v9 = v3;
      v4 = &this->m_BucketsUsedByElement.m_Memory.m_pMemory[v9];
      m_ElementListIndex = v4->m_Element.m_ElementListIndex;
      bucket = v4->m_Element.m_Bucket;
      if ( (_WORD)m_ElementListIndex == *this->m_FirstElement(a1: bucket) )
      {
        m_Next = this->m_ElementsInBucket.m_Memory.m_pMemory[m_ElementListIndex].m_Next;
        *this->m_FirstElement(a1: bucket) = m_Next;
      }
      CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::Unlink(
        (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)this,
        elem: m_ElementListIndex);
      this->m_ElementsInBucket.m_Memory.m_pMemory[m_ElementListIndex].m_Next = this->m_ElementsInBucket.m_FirstFree;
      m_pMemory = this->m_BucketsUsedByElement.m_Memory.m_pMemory;
      this->m_ElementsInBucket.m_FirstFree = m_ElementListIndex;
      v7 = i;
      v8 = i;
      i = m_pMemory[v9].m_Next;
      CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::Unlink(
        this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&this->m_BucketsUsedByElement,
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
// Address: 0x10110B80
// Name: public: void CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::RemoveBucket(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::RemoveBucket(
        CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short> *this,
        int bucket)
{
  unsigned __int16 v3; // ax
  int v4; // ebx
  int m_BucketListIndex; // edi
  int v6; // edi
  unsigned __int16 v7; // [esp-Ch] [ebp-1Ch]
  unsigned __int16 m_Next; // [esp+4h] [ebp-Ch]
  int element; // [esp+8h] [ebp-8h]
  unsigned __int16 i; // [esp+Ch] [ebp-4h]

  v3 = *this->m_FirstElement(a1: bucket);
  i = v3;
  if ( v3 != 0xFFFF )
  {
    while ( 1 )
    {
      v4 = v3;
      m_BucketListIndex = this->m_ElementsInBucket.m_Memory.m_pMemory[v4].m_Element.m_BucketListIndex;
      element = this->m_ElementsInBucket.m_Memory.m_pMemory[v4].m_Element.m_Element;
      if ( (_WORD)m_BucketListIndex == *this->m_FirstBucket(a1: element) )
      {
        m_Next = this->m_BucketsUsedByElement.m_Memory.m_pMemory[m_BucketListIndex].m_Next;
        *this->m_FirstBucket(a1: element) = m_Next;
      }
      CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::Unlink(
        this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&this->m_BucketsUsedByElement,
        elem: m_BucketListIndex);
      this->m_BucketsUsedByElement.m_Memory.m_pMemory[m_BucketListIndex].m_Next = this->m_BucketsUsedByElement.m_FirstFree;
      this->m_BucketsUsedByElement.m_FirstFree = m_BucketListIndex;
      v6 = i;
      v7 = i;
      i = this->m_ElementsInBucket.m_Memory.m_pMemory[v4].m_Next;
      CUtlLinkedList<RecvTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<RecvTable *,unsigned short>,unsigned short>>::Unlink(
        (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)this,
        elem: v7);
      this->m_ElementsInBucket.m_Memory.m_pMemory[v6].m_Next = this->m_ElementsInBucket.m_FirstFree;
      this->m_ElementsInBucket.m_FirstFree = v6;
      if ( i == 0xFFFF )
        break;
      v3 = i;
    }
  }
  *this->m_FirstElement(a1: bucket) = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10110F90
// Name: public: virtual void CShadowMgr::LevelShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::LevelShutdown(CShadowMgr *this)
{
  if ( this->m_bInitialized )
  {
    if ( this->m_pSurfaceBounds != nullptr )
    {
      free(pMem: this->m_pSurfaceBounds);
      this->m_pSurfaceBounds = nullptr;
    }
    CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::RemoveAll(this: &this->m_SurfaceBoundsCache);
    this->m_bInitialized = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110FD0
// Name: private: void CShadowMgr::CleanupMaterial(struct CShadowMgr::Shadow_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::CleanupMaterial(CShadowMgr *this, CShadowMgr::Shadow_t *shadow)
{
  CUtlLinkedList<CDispShadowFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowFragment,unsigned short>,unsigned short> > *p_m_SortOrderIds; // esi
  UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short> *m_pMemory; // ecx
  int m_SortOrder; // eax
  int v5; // ebx

  p_m_SortOrderIds = (CUtlLinkedList<CDispShadowFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowFragment,unsigned short>,unsigned short> > *)&this->m_SortOrderIds;
  m_pMemory = this->m_SortOrderIds.m_Memory.m_pMemory;
  m_SortOrder = shadow->m_SortOrder;
  if ( --m_pMemory[m_SortOrder].m_Element.m_RefCount <= 0 )
  {
    v5 = shadow->m_SortOrder;
    CUtlLinkedList<CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::Unlink(
      this: p_m_SortOrderIds,
      elem: shadow->m_SortOrder);
    p_m_SortOrderIds->m_Memory.m_pMemory[v5].m_Next = p_m_SortOrderIds->m_FirstFree;
    p_m_SortOrderIds->m_FirstFree = v5;
  }
  if ( shadow->m_pMaterial != nullptr )
    shadow->m_pMaterial->DecrementReferenceCount(this: shadow->m_pMaterial);
  if ( shadow->m_pModelMaterial != nullptr )
    shadow->m_pModelMaterial->DecrementReferenceCount(this: shadow->m_pModelMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x101110D0
// Name: private: void CShadowMgr::RemoveShadowDecalFromSurface(struct msurface2_t __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::RemoveShadowDecalFromSurface(
        CShadowMgr *this,
        msurface2_t *surfID,
        unsigned __int16 decalHandle)
{
  UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short> *m_pMemory; // esi
  CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int> > *p_m_ShadowDecals; // ebx
  int v5; // edi
  int m_ShadowVerts; // eax
  unsigned __int16 *v7; // esi
  int v8; // edx
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v9; // esi
  int m_ShadowListIndex; // eax
  bool v11; // zf
  int *p_m_FirstDecal; // edx
  unsigned __int16 v13; // [esp+10h] [ebp-8h]
  CShadowMgr *v14; // [esp+14h] [ebp-4h]

  m_pMemory = this->m_ShadowDecals.m_Memory.m_pMemory;
  p_m_ShadowDecals = &this->m_ShadowDecals;
  v5 = decalHandle;
  m_ShadowVerts = m_pMemory[v5].m_Element.m_ShadowVerts;
  v7 = (unsigned __int16 *)&m_pMemory[v5];
  v14 = this;
  if ( (_WORD)m_ShadowVerts != 0xFFFF )
  {
    CShadowMgr::FreeVertices(this, cache: &this->m_VertexCache.m_Memory.m_pMemory[m_ShadowVerts].m_Element);
    v13 = v7[6];
    CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::Unlink(
      this: (CUtlLinkedList<CDispDecalFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispDecalFragment,unsigned short>,unsigned short> > *)&v14->m_VertexCache,
      elem: v13);
    v14->m_VertexCache.m_Memory.m_pMemory[v13].m_Next = v14->m_VertexCache.m_FirstFree;
    v14->m_VertexCache.m_FirstFree = v13;
    v7[6] = -1;
    this = v14;
  }
  if ( v7[5] != 0xFFFF )
  {
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(*(_DWORD *)v7 + 24) + 44))(
      a1: *(_DWORD *)(*(_DWORD *)v7 + 24),
      a2: v7[5]);
    this = v14;
  }
  if ( surfID->m_ShadowDecals == decalHandle )
    surfID->m_ShadowDecals = p_m_ShadowDecals->m_Memory.m_pMemory[v5].m_Next;
  v8 = v7[4];
  v9 = this->m_Shadows.m_Memory.m_pMemory;
  m_ShadowListIndex = p_m_ShadowDecals->m_Memory.m_pMemory[v5].m_Element.m_ShadowListIndex;
  v11 = v9[v8].m_Element.m_FirstDecal == m_ShadowListIndex;
  p_m_FirstDecal = &v9[v8].m_Element.m_FirstDecal;
  if ( v11 )
    *p_m_FirstDecal = *(_DWORD *)(m_ShadowListIndex + 8);
  CUtlLinkedList<PackedEntity *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<PackedEntity *,int>>>::Free(
    this: &this->m_ShadowSurfaces,
    elem: m_ShadowListIndex);
  p_m_ShadowDecals->m_Memory.m_pMemory[v5].m_Element.m_ShadowListIndex = 0;
  CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int>>::Unlink(
    this: p_m_ShadowDecals,
    elem: decalHandle);
  p_m_ShadowDecals->m_Memory.m_pMemory[v5].m_Next = p_m_ShadowDecals->m_FirstFree;
  p_m_ShadowDecals->m_FirstFree = decalHandle;
}

//------------------------------------------------------------------------------
// Address: 0x101111F0
// Name: private: void CShadowMgr::RemoveAllSurfacesFromShadow(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::RemoveAllSurfacesFromShadow(CShadowMgr *this, unsigned __int16 handle)
{
  int v2; // ebx
  unsigned __int16 *m_FirstDecal; // eax
  unsigned __int16 *v5; // edi

  v2 = handle;
  m_FirstDecal = (unsigned __int16 *)this->m_Shadows.m_Memory.m_pMemory[v2].m_Element.m_FirstDecal;
  if ( m_FirstDecal != nullptr )
  {
    do
    {
      v5 = *((unsigned __int16 **)m_FirstDecal + 2);
      CShadowMgr::RemoveShadowDecalFromSurface(
        this,
        surfID: this->m_ShadowDecals.m_Memory.m_pMemory[*m_FirstDecal].m_Element.m_SurfID,
        decalHandle: *m_FirstDecal);
      m_FirstDecal = v5;
    }
    while ( v5 != nullptr );
    this->m_Shadows.m_Memory.m_pMemory[v2].m_Element.m_FirstDecal = 0;
  }
  else
  {
    this->m_Shadows.m_Memory.m_pMemory[v2].m_Element.m_FirstDecal = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10111260
// Name: public: virtual void CShadowMgr::AddShadowToModel(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::AddShadowToModel(CShadowMgr *this, int handle, unsigned __int16 *model)
{
  int m_NumAlloced; // esi

  if ( (_WORD)model != 0xFFFF
    && r_flashlightrender.m_pParent != nullptr
    && r_flashlightrender.m_pParent->m_Value.m_nValue != 0 )
  {
    m_NumAlloced = this->m_ShadowsOnModels.m_ElementsInBucket.m_NumAlloced;
    if ( m_NumAlloced > m_ShadowsOnModelsMax )
    {
      if ( m_ShadowsOnModelsMax / 1000 != m_NumAlloced / 1000 )
        _Warning(
          a1: "Shadow memory (%s) growing [%d]\n",
          "m_ShadowsOnModels",
          this->m_ShadowsOnModels.m_ElementsInBucket.m_NumAlloced);
      m_ShadowsOnModelsMax = m_NumAlloced;
    }
    CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::AddElementToBucket(
      this: &this->m_ShadowsOnModels,
      bucket: model,
      element: handle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101112F0
// Name: public: virtual void CShadowMgr::RemoveAllShadowsFromModel(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::RemoveAllShadowsFromModel(CShadowMgr *this, int model)
{
  if ( (_WORD)model != 0xFFFF )
    CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::RemoveBucket(
      this: &this->m_ShadowsOnModels,
      bucket: model);
}

//------------------------------------------------------------------------------
// Address: 0x10111310
// Name: public: virtual void CShadowMgr::EnableShadow(unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::EnableShadow(CShadowMgr *this, int handle, bool bEnable)
{
  unsigned __int16 *p_m_Flags; // eax

  if ( bEnable )
  {
    p_m_Flags = &this->m_Shadows.m_Memory.m_pMemory[(unsigned __int16)handle].m_Element.m_Flags;
    *p_m_Flags &= ~8u;
  }
  else
  {
    CShadowMgr::RemoveAllSurfacesFromShadow(this, handle);
    CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::RemoveElement(
      this: &this->m_ShadowsOnModels,
      element: handle);
    this->m_Shadows.m_Memory.m_pMemory[(unsigned __int16)handle].m_Element.m_Flags |= 8u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10111370
// Name: public: virtual void CShadowMgr::RemoveAllShadowsFromBrushModel(struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::RemoveAllShadowsFromBrushModel(CShadowMgr *this, model_t *pModel)
{
  model_t *v3; // ecx
  unsigned __int16 *v4; // ebx
  unsigned __int16 v5; // ax
  UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short> *m_pMemory; // edx
  unsigned __int16 m_Next; // si
  int i; // [esp+4h] [ebp-4h]

  v3 = pModel;
  i = 0;
  if ( pModel->brush.nummodelsurfaces > 0 )
  {
    v4 = (unsigned __int16 *)(*(_DWORD *)(pModel->sprite.numframes + 124) + 32 * pModel->brush.firstmodelsurface + 14);
    do
    {
      v5 = *v4;
      if ( *v4 != 0xFFFF )
      {
        do
        {
          m_pMemory = this->m_ShadowDecals.m_Memory.m_pMemory;
          m_Next = m_pMemory[v5].m_Next;
          CShadowMgr::RemoveShadowDecalFromSurface(this, surfID: m_pMemory[v5].m_Element.m_SurfID, decalHandle: v5);
          v5 = m_Next;
        }
        while ( m_Next != 0xFFFF );
        v3 = pModel;
      }
      *v4 = -1;
      v4 += 16;
      ++i;
    }
    while ( i < v3->brush.nummodelsurfaces );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10111400
// Name: public: virtual void CShadowMgr::ClearShadowRenderList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::ClearShadowRenderList(CShadowMgr *this)
{
  int m_Size; // eax

  m_Size = this->m_RenderQueue.m_Size;
  if ( m_Size > 0 )
    memset(dst: (unsigned __int8 *)this->m_RenderQueue.m_Memory.m_pMemory, value: 0xFFu, count: 2 * m_Size);
  this->m_DecalsToRender = 0;
  CShadowMgr::ClearAllFlashlightMaterialBuckets(this);
}

//------------------------------------------------------------------------------
// Address: 0x10111440
// Name: public: virtual void CShadowMgr::PushFlashlightScissorBounds(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::PushFlashlightScissorBounds(CShadowMgr *this)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v5; // eax
  int *v6; // edi
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *v8; // ecx
  int v9; // edi
  int v10; // eax
  CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *p_m_ScissorStateBackups; // esi
  int v12; // ebx
  int v13; // ecx
  int v14; // edx
  vgui::CTreeViewListControl::CColumnInfo *v15; // ecx
  int v16; // eax
  unsigned __int16 m_Next; // ax
  vgui::CTreeViewListControl::CColumnInfo *v18; // esi
  int p_m_Width; // esi
  int v20; // ecx
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *v21; // eax
  int v23; // [esp+14h] [ebp-4h]

  m_Size = this->m_ScissorStateEntryStart.m_Size;
  v23 = this->m_ScissorStateBackups.m_Size;
  m_nAllocationCount = this->m_ScissorStateEntryStart.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&this->m_ScissorStateEntryStart,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_ScissorStateEntryStart.m_Size;
  m_pMemory = this->m_ScissorStateEntryStart.m_Memory.m_pMemory;
  v5 = this->m_ScissorStateEntryStart.m_Size - m_Size - 1;
  this->m_ScissorStateEntryStart.m_pElements = m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v5);
  v6 = &this->m_ScissorStateEntryStart.m_Memory.m_pMemory[m_Size];
  if ( v6 != nullptr )
    *v6 = v23;
  m_Head = this->m_FlashlightStates.m_Head;
  if ( m_Head != 0xFFFF )
  {
    v8 = this->m_FlashlightStates.m_Memory.m_pMemory;
    v9 = 0;
    do
    {
      v10 = m_Head;
      if ( v8[v10].m_Element.m_nSplitscreenOwner == 0 )
        ++v9;
      m_Head = v8[v10].m_Next;
    }
    while ( m_Head != 0xFFFF );
    p_m_ScissorStateBackups = (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&this->m_ScissorStateBackups;
    v12 = this->m_ScissorStateBackups.m_Size;
    if ( v9 != 0 )
    {
      v13 = p_m_ScissorStateBackups->m_nAllocationCount;
      v14 = v12 + v9;
      if ( v12 + v9 > v13 )
      {
        CUtlMemory<UtlRBTreeNode_t<void *,int>,int>::Grow(this: p_m_ScissorStateBackups, num: v9 + v12 - v13);
        v14 = v12 + v9;
      }
      p_m_ScissorStateBackups[1].m_pMemory = (vgui::CTreeViewListControl::CColumnInfo *)((char *)p_m_ScissorStateBackups[1].m_pMemory
                                                                                       + v9);
      v15 = p_m_ScissorStateBackups->m_pMemory;
      v16 = (int)p_m_ScissorStateBackups[1].m_pMemory - v12 - v9;
      p_m_ScissorStateBackups[1].m_nAllocationCount = (int)p_m_ScissorStateBackups->m_pMemory;
      if ( v16 > 0 && v9 > 0 )
        _V_memmove(dest: &v15[v14], src: &v15[v12], count: 20 * v16);
    }
    m_Next = this->m_FlashlightStates.m_Head;
    v18 = p_m_ScissorStateBackups->m_pMemory;
    if ( m_Next != 0xFFFF )
    {
      p_m_Width = (int)&v18[v12].m_Width;
      do
      {
        v20 = m_Next;
        v21 = &this->m_FlashlightStates.m_Memory.m_pMemory[v20];
        if ( v21->m_Element.m_nSplitscreenOwner == 0 )
        {
          *(_BYTE *)(p_m_Width + 12) = v21->m_Element.m_FlashlightState.m_bScissor;
          *(_DWORD *)(p_m_Width - 4) = v21->m_Element.m_FlashlightState.m_nLeft;
          *(_DWORD *)p_m_Width = v21->m_Element.m_FlashlightState.m_nTop;
          *(_DWORD *)(p_m_Width + 4) = v21->m_Element.m_FlashlightState.m_nRight;
          *(_DWORD *)(p_m_Width + 8) = v21->m_Element.m_FlashlightState.m_nBottom;
          p_m_Width += 20;
        }
        m_Next = this->m_FlashlightStates.m_Memory.m_pMemory[v20].m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10111600
// Name: private: virtual void CShadowMgr::RenderFlashlights(bool,bool,class VMatrix const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CShadowMgr::RenderFlashlights(
        CShadowMgr *this@<ecx>,
        int a2@<ebx>,
        bool bDoMasking,
        bool bDoSimpleProjections,
        const VMatrix *pModelToWorld)
{
  unsigned __int16 m_Head; // bx
  int m_nValue; // eax
  bool v8; // zf
  IMatRenderContext *(__thiscall *GetRenderContext)(IMaterialSystem *); // eax
  IMatRenderContext *v10; // eax
  IMatRenderContext *v11; // edi
  void (__thiscall *SetFlashlightMode)(IMatRenderContext *, bool); // eax
  CShadowMgr *v13; // ecx
  int v14; // eax
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *m_pMemory; // ebx
  int v16; // eax
  int v17; // edx
  CShadowMgr::FlashlightInfo_t *v18; // ebx
  int v19; // edx
  unsigned __int16 v20; // si
  int v21; // eax
  int m_Element; // esi
  IMatRenderContext *m_pObject; // edi
  unsigned __int16 m_Next; // ax
  int v25; // edi
  msurface2_t *v26; // esi
  unsigned int flags; // eax
  unsigned int v28; // ecx
  int v29; // edi
  IMesh *v30; // esi
  unsigned __int16 v31; // ax
  worldbrushdata_t *worldbrush; // edx
  UtlLinkedListElem_t<msurface2_t *,unsigned short> *v33; // ecx
  msurface2_t *v34; // eax
  int v35; // esi
  int v36; // ebx
  unsigned __int16 vertBufferIndex; // cx
  signed int v38; // eax
  __int16 v39; // cx
  unsigned __int16 *v40; // edx
  int v41; // esi
  signed int j; // edi
  signed int v43; // ecx
  int m_nVertexCount; // eax
  unsigned __int16 k; // ax
  int v46; // esi
  msurface2_t *v47; // eax
  CDispInfo *pDispInfo; // eax
  CShadowMgr::FlashlightInfo_t *v49; // eax
  unsigned __int16 v50; // bx
  IMatRenderContext v51; // edx
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v52; // eax
  int v53; // eax
  int v54; // ebx
  IMesh *v55; // eax
  worldbrushdata_t *v56; // esi
  int m_nCurrentIndex; // ebx
  msurface2_t *v58; // ecx
  unsigned __int16 firstPrimID; // ax
  __int16 v60; // cx
  int v61; // eax
  int v62; // edx
  signed int v63; // eax
  int v64; // edi
  unsigned __int16 *v65; // edx
  int v66; // esi
  signed int m; // edi
  int v68; // eax
  CShadowMgr::FlashlightInfo_t **v69; // eax
  int *v70; // eax
  int *v71; // eax
  msurface2_t **v72; // eax
  CUtlVectorFixedGrowable<msurface2_t *,64> paintableSurfaces; // [esp+8h] [ebp-444h] BYREF
  CMeshBuilder meshBuilder; // [esp+120h] [ebp-32Ch] BYREF
  CUtlVectorFixedGrowable<int,16> batchPaintableSurfaceIndexCount; // [esp+308h] [ebp-144h] BYREF
  int nVertCount; // [esp+360h] [ebp-ECh] BYREF
  CUtlVectorFixedGrowable<int,16> batchPaintableSurfaceCount; // [esp+364h] [ebp-E8h] BYREF
  CUtlVectorFixedGrowable<CShadowMgr::FlashlightInfo_t *,16> flashlightInfos; // [esp+3BCh] [ebp-90h] BYREF
  int v80; // [esp+414h] [ebp-38h]
  int nIndexCount; // [esp+418h] [ebp-34h] BYREF
  int v82; // [esp+41Ch] [ebp-30h]
  int v83; // [esp+420h] [ebp-2Ch] BYREF
  msurface2_t *surfID; // [esp+424h] [ebp-28h] BYREF
  int src; // [esp+428h] [ebp-24h] BYREF
  int i; // [esp+42Ch] [ebp-20h]
  CMatRenderContextPtr pRenderContext; // [esp+430h] [ebp-1Ch]
  int nSurfaceIndex; // [esp+434h] [ebp-18h]
  CShadowMgr::FlashlightInfo_t *flashlightInfo; // [esp+438h] [ebp-14h]
  int sortID; // [esp+43Ch] [ebp-10h]
  CShadowMgr *v91; // [esp+440h] [ebp-Ch]
  int numIndices; // [esp+444h] [ebp-8h]
  bool bWireframe; // [esp+44Bh] [ebp-1h]

  v91 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CShadowMgr::RenderFlashlights",
    a3: 0,
    a4: "Shadow_Rendering",
    a5: false,
    a6: 4);
  if ( !this->m_bSinglePassFlashlightStateEnabled
    && (r_flashlightrender.m_pParent != nullptr && r_flashlightrender.m_pParent->m_Value.m_nValue != 0
     || bDoSimpleProjections) )
  {
    m_Head = this->m_FlashlightStates.m_Head;
    if ( m_Head != 0xFFFF )
    {
      if ( r_shadowwireframe.m_pParent != nullptr )
        m_nValue = r_shadowwireframe.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      v8 = m_nValue == 0;
      GetRenderContext = materials->GetRenderContext;
      bWireframe = !v8;
      v10 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int))GetRenderContext)(a1: materials, a2);
      v11 = v10;
      pRenderContext.m_pObject = v10;
      if ( v10 != nullptr )
        v10->BeginRender(this: v10);
      SetFlashlightMode = v11->SetFlashlightMode;
      i = 4;
      if ( bDoSimpleProjections )
      {
        SetFlashlightMode(this: v11, a2: false);
        bDoMasking = false;
      }
      else
      {
        SetFlashlightMode(this: v11, a2: true);
        i = 2;
      }
      paintableSurfaces.m_pElements = paintableSurfaces.m_Memory.m_pFixedMemory;
      paintableSurfaces.m_Memory.m_pMemory = paintableSurfaces.m_Memory.m_pFixedMemory;
      batchPaintableSurfaceCount.m_pElements = batchPaintableSurfaceCount.m_Memory.m_pFixedMemory;
      batchPaintableSurfaceCount.m_Memory.m_pMemory = batchPaintableSurfaceCount.m_Memory.m_pFixedMemory;
      batchPaintableSurfaceIndexCount.m_Memory.m_pMemory = batchPaintableSurfaceIndexCount.m_Memory.m_pFixedMemory;
      batchPaintableSurfaceIndexCount.m_pElements = batchPaintableSurfaceIndexCount.m_Memory.m_pFixedMemory;
      paintableSurfaces.m_Memory.m_nGrowSize = -1;
      batchPaintableSurfaceCount.m_Memory.m_nGrowSize = -1;
      batchPaintableSurfaceIndexCount.m_Memory.m_nGrowSize = -1;
      flashlightInfos.m_Memory.m_nGrowSize = -1;
      batchPaintableSurfaceCount.m_Memory.m_nAllocationCount = 16;
      batchPaintableSurfaceIndexCount.m_Memory.m_nAllocationCount = 16;
      flashlightInfos.m_Memory.m_nAllocationCount = 16;
      v13 = v91;
      paintableSurfaces.m_Memory.m_nAllocationCount = 64;
      paintableSurfaces.m_Memory.m_nMallocGrowSize = 0;
      paintableSurfaces.m_Size = 0;
      batchPaintableSurfaceCount.m_Memory.m_nMallocGrowSize = 0;
      batchPaintableSurfaceCount.m_Size = 0;
      batchPaintableSurfaceIndexCount.m_Memory.m_nMallocGrowSize = 0;
      batchPaintableSurfaceIndexCount.m_Size = 0;
      flashlightInfos.m_Memory.m_pMemory = flashlightInfos.m_Memory.m_pFixedMemory;
      flashlightInfos.m_Memory.m_nMallocGrowSize = 0;
      flashlightInfos.m_Size = 0;
      flashlightInfos.m_pElements = flashlightInfos.m_Memory.m_pFixedMemory;
      do
      {
        v14 = m_Head;
        m_pMemory = v13->m_FlashlightStates.m_Memory.m_pMemory;
        v16 = 768 * v14;
        v17 = *(unsigned __int16 *)((char *)&m_pMemory->m_Element.m_Shadow + v16);
        v18 = (CShadowMgr::FlashlightInfo_t *)((char *)&m_pMemory->m_Element + v16);
        v19 = v13->m_Shadows.m_Memory.m_pMemory[v17].m_Element.m_Flags & 6;
        v80 = v16;
        flashlightInfo = v18;
        if ( v19 == i && v18->m_nSplitscreenOwner == 0 )
        {
          nSurfaceIndex = v18->m_MaterialBuckets.m_UsedSortIDs.m_Head;
          if ( (_WORD)nSurfaceIndex != 0xFFFF )
          {
            src = (int)v18;
            CUtlVector<int,CUtlMemoryFixedGrowable<int,16,int>>::InsertBefore(
              this: (CUtlVector<int,CUtlMemoryFixedGrowable<int,16,int> > *)&flashlightInfos,
              elem: flashlightInfos.m_Size,
              &src);
            v11->SetFlashlightStateEx(
              this: v11,
              a2: &v18->m_FlashlightState,
              a3: &v91->m_Shadows.m_Memory.m_pMemory[v18->m_Shadow].m_Element.m_WorldToShadow,
              a4: v91->m_Shadows.m_Memory.m_pMemory[v18->m_Shadow].m_Element.m_pFlashlightDepthTexture);
            CShadowMgr::EnableStencilAndScissorMasking(this: v91, pRenderContext: v11, flashlightInfo: v18, bDoMasking);
            src = 0;
            v83 = 0;
            v20 = nSurfaceIndex;
            do
            {
              nSurfaceIndex = batchPaintableSurfaceCount.m_Size;
              CUtlVector<int,CUtlMemoryFixedGrowable<int,16,int>>::InsertBefore(
                this: &batchPaintableSurfaceCount,
                elem: batchPaintableSurfaceCount.m_Size,
                &src);
              CUtlVector<int,CUtlMemoryFixedGrowable<int,16,int>>::InsertBefore(
                this: &batchPaintableSurfaceIndexCount,
                elem: batchPaintableSurfaceIndexCount.m_Size,
                src: &v83);
              v21 = v20;
              m_Element = v18->m_MaterialBuckets.m_UsedSortIDs.m_Memory.m_pMemory[v21].m_Element;
              v82 = v21 * 6;
              sortID = m_Element;
              if ( bWireframe )
              {
                pRenderContext.m_pObject->Bind(
                  this: pRenderContext.m_pObject,
                  a2: g_materialWorldWireframe,
                  a3: nullptr);
              }
              else if ( bDoSimpleProjections )
              {
                pRenderContext.m_pObject->Bind(
                  this: pRenderContext.m_pObject,
                  a2: v18->m_FlashlightState.m_pProjectedMaterial,
                  a3: nullptr);
              }
              else
              {
                m_pObject = pRenderContext.m_pObject;
                pRenderContext.m_pObject->Bind(
                  this: pRenderContext.m_pObject,
                  a2: materialSortInfoArray[m_Element].material,
                  a3: nullptr);
                m_pObject->BindLightmapPage(this: m_pObject, a2: materialSortInfoArray[m_Element].lightmapPageID);
              }
              m_Next = v18->m_MaterialBuckets.m_MaterialSortInfoArray.m_Memory.m_pMemory[m_Element].m_Head;
              numIndices = 0;
              if ( m_Next != 0xFFFF )
              {
                do
                {
                  v25 = m_Next;
                  v26 = v18->m_MaterialBuckets.m_Elements.m_Memory.m_pMemory[v25].m_Element;
                  flags = v26->flags;
                  v28 = v26->flags >> 11;
                  surfID = v26;
                  if ( (v28 & 1) == 0 && !bWireframe && (flags & 0x200000) != 0 )
                  {
                    CUtlVector<msurface2_t *,CUtlMemoryFixedGrowable<msurface2_t *,64,int>>::InsertBefore(
                      this: &paintableSurfaces,
                      elem: paintableSurfaces.m_Size,
                      src: &surfID);
                    ++batchPaintableSurfaceCount.m_Memory.m_pMemory[nSurfaceIndex];
                    Shader_GetSurfVertexAndIndexCount(
                      surfaceHandle: v26,
                      pVertexCount: &nVertCount,
                      pIndexCount: &nIndexCount);
                    batchPaintableSurfaceIndexCount.m_Memory.m_pMemory[nSurfaceIndex] += nIndexCount;
                  }
                  if ( (v26->flags & 0x800) == 0 )
                    numIndices = HIBYTE(v26->flags) + numIndices - 2 + 2 * HIBYTE(v26->flags) - 4;
                  m_Next = v18->m_MaterialBuckets.m_Elements.m_Memory.m_pMemory[v25].m_Next;
                }
                while ( m_Next != 0xFFFF );
                if ( numIndices > 0 )
                {
                  v29 = sortID;
                  v30 = pRenderContext.m_pObject->GetDynamicMesh(
                          this: pRenderContext.m_pObject,
                          a2: 0,
                          a3: g_WorldStaticMeshes.m_Memory.m_pMemory[sortID],
                          a4: 0,
                          a5: 0);
                  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
                  CMeshBuilder::Begin(
                    this: &meshBuilder,
                    pMesh: v30,
                    type: MATERIAL_TRIANGLES,
                    nVertexCount: 0,
                    nIndexCount: numIndices,
                    pMeshSettings: nullptr);
                  v31 = v18->m_MaterialBuckets.m_MaterialSortInfoArray.m_Memory.m_pMemory[v29].m_Head;
                  if ( v31 != 0xFFFF )
                  {
                    worldbrush = host_state.worldbrush;
                    do
                    {
                      v33 = flashlightInfo->m_MaterialBuckets.m_Elements.m_Memory.m_pMemory;
                      surfID = (msurface2_t *)(8 * v31);
                      v34 = *(msurface2_t **)((char *)&v33->m_Element + (_DWORD)surfID);
                      if ( (v34->flags & 0x800) == 0 )
                      {
                        if ( (v34->flags & 0x8000) != 0 )
                        {
                          v35 = (int)&worldbrush->primitives[worldbrush->surfaces1[v34 - worldbrush->surfaces2].prims.firstPrimID];
                          v36 = (int)&worldbrush->primindices[*(unsigned __int16 *)(v35 + 4)];
                          vertBufferIndex = v34->vertBufferIndex;
                          v38 = meshBuilder.m_IndexBuilder.m_nIndexSize * *(unsigned __int16 *)(v35 + 6);
                          v39 = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset) + vertBufferIndex;
                          if ( v38 > 0 )
                          {
                            v40 = &meshBuilder.m_IndexBuilder.m_pIndices[meshBuilder.m_IndexBuilder.m_nCurrentIndex];
                            v41 = v36 - (_DWORD)v40;
                            for ( j = v38; j != 0; --j )
                            {
                              *v40 = v39 + *(unsigned __int16 *)((char *)v40 + v41);
                              ++v40;
                            }
                            worldbrush = host_state.worldbrush;
                          }
                          v43 = meshBuilder.m_IndexBuilder.m_nIndexSize * v38
                              + meshBuilder.m_IndexBuilder.m_nCurrentIndex;
                          meshBuilder.m_IndexBuilder.m_nCurrentIndex = v43;
                          if ( v43 > meshBuilder.m_IndexBuilder.m_nIndexCount )
                            meshBuilder.m_IndexBuilder.m_nIndexCount = v43;
                        }
                        else
                        {
                          BuildIndicesForSurface(meshBuilder: &meshBuilder.m_IndexBuilder, surfID: v34);
                          worldbrush = host_state.worldbrush;
                        }
                      }
                      v31 = *(_WORD *)((char *)&surfID->plane
                                     + (unsigned int)flashlightInfo->m_MaterialBuckets.m_Elements.m_Memory.m_pMemory
                                     + 2);
                    }
                    while ( v31 != 0xFFFF );
                    v18 = flashlightInfo;
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
                  meshBuilder.m_pMesh->Draw_2(this: meshBuilder.m_pMesh, a2: -1, a3: 0);
                  meshBuilder.m_pMesh = nullptr;
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
              for ( k = v18->m_MaterialBuckets.m_MaterialSortInfoArray.m_Memory.m_pMemory[sortID].m_Head;
                    k != 0xFFFF;
                    k = v18->m_MaterialBuckets.m_Elements.m_Memory.m_pMemory[v46].m_Next )
              {
                v46 = k;
                v47 = v18->m_MaterialBuckets.m_Elements.m_Memory.m_pMemory[v46].m_Element;
                if ( (v47->flags & 0x800) != 0 )
                {
                  pDispInfo = (CDispInfo *)v47->pDispInfo;
                  if ( bWireframe )
                    CDispInfo::SpecifyDynamicMesh(this: pDispInfo);
                  else
                    pDispInfo->m_pMesh->m_pMesh->Draw_2(
                      this: pDispInfo->m_pMesh->m_pMesh,
                      a2: pDispInfo->m_iIndexOffset,
                      a3: pDispInfo->m_nIndices);
                }
              }
              v20 = *(unsigned __int16 *)((char *)&v18->m_MaterialBuckets.m_UsedSortIDs.m_Memory.m_pMemory->m_Next + v82);
            }
            while ( v20 != 0xFFFF );
            CShadowMgr::DisableStencilAndScissorMasking(
              this: v91,
              pRenderContext: pRenderContext.m_pObject,
              flashlightInfo: v18,
              bDoMasking);
            v16 = v80;
            v11 = pRenderContext.m_pObject;
          }
        }
        v13 = v91;
        m_Head = *(unsigned __int16 *)((char *)&v91->m_FlashlightStates.m_Memory.m_pMemory->m_Next + v16);
      }
      while ( m_Head != 0xFFFF );
      if ( paintableSurfaces.m_Size != 0 )
      {
        ((void (__thiscall *)(IMatRenderContext *, int))v11->__vftable[1].EndRender)(a1: v11, a2: 1);
        flashlightInfo = nullptr;
        nSurfaceIndex = 0;
        for ( i = 0; i < flashlightInfos.m_Size; ++i )
        {
          v49 = flashlightInfos.m_Memory.m_pMemory[i];
          v50 = v49->m_MaterialBuckets.m_UsedSortIDs.m_Head;
          v51.__vftable = v11->__vftable;
          numIndices = (int)v49;
          v52 = &v91->m_Shadows.m_Memory.m_pMemory[v49->m_Shadow];
          v51.SetFlashlightStateEx(
            this: v11,
            a2: (const FlashlightState_t *)(numIndices + 320),
            a3: &v52->m_Element.m_WorldToShadow,
            a4: v52->m_Element.m_pFlashlightDepthTexture);
          CShadowMgr::EnableStencilAndScissorMasking(
            this: v91,
            pRenderContext: v11,
            flashlightInfo: (const CShadowMgr::FlashlightInfo_t *)numIndices,
            bDoMasking);
          for ( ; v50 != 0xFFFF; flashlightInfo = (CShadowMgr::FlashlightInfo_t *)((char *)flashlightInfo + 1) )
          {
            v53 = 6 * v50;
            sortID = *(unsigned __int16 *)(*(_DWORD *)(numIndices + 576) + v53);
            v54 = batchPaintableSurfaceCount.m_Memory.m_pMemory[(_DWORD)flashlightInfo];
            src = v53;
            if ( v54 > 0 )
            {
              if ( bDoSimpleProjections )
              {
                v11->Bind(this: v11, a2: *(IMaterial **)(numIndices + 424), a3: nullptr);
              }
              else
              {
                v11->Bind(this: v11, a2: materialSortInfoArray[sortID].material, a3: nullptr);
                v11->BindLightmapPage(this: v11, a2: materialSortInfoArray[sortID].lightmapPageID);
              }
              v55 = v11->GetDynamicMesh(
                      this: v11,
                      a2: false,
                      a3: g_WorldStaticMeshes.m_Memory.m_pMemory[sortID],
                      a4: nullptr,
                      a5: nullptr);
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
              CMeshBuilder::Begin(
                this: &meshBuilder,
                pMesh: v55,
                type: MATERIAL_TRIANGLES,
                nVertexCount: 0,
                nIndexCount: batchPaintableSurfaceIndexCount.m_Memory.m_pMemory[(_DWORD)flashlightInfo],
                pMeshSettings: nullptr);
              v56 = host_state.worldbrush;
              sortID = v54;
              m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
              do
              {
                v58 = paintableSurfaces.m_Memory.m_pMemory[nSurfaceIndex];
                if ( (v58->flags & 0x8000) != 0 )
                {
                  if ( (v58->flags & 0x800) != 0 )
                    firstPrimID = 0;
                  else
                    firstPrimID = v56->surfaces1[v58 - v56->surfaces2].prims.firstPrimID;
                  v60 = LOWORD(meshBuilder.m_IndexBuilder.m_nIndexOffset) + v58->vertBufferIndex;
                  v61 = (int)&v56->primitives[firstPrimID];
                  v62 = *(unsigned __int16 *)(v61 + 4);
                  v63 = meshBuilder.m_IndexBuilder.m_nIndexSize * *(unsigned __int16 *)(v61 + 6);
                  v64 = (int)&v56->primindices[v62];
                  v65 = &meshBuilder.m_IndexBuilder.m_pIndices[m_nCurrentIndex];
                  if ( v63 > 0 )
                  {
                    v66 = v64 - (_DWORD)v65;
                    for ( m = v63; m != 0; --m )
                    {
                      *v65 = v60 + *(unsigned __int16 *)((char *)v65 + v66);
                      ++v65;
                    }
                    v56 = host_state.worldbrush;
                    m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
                  }
                  m_nCurrentIndex += v63 * meshBuilder.m_IndexBuilder.m_nIndexSize;
                  meshBuilder.m_IndexBuilder.m_nCurrentIndex = m_nCurrentIndex;
                  if ( m_nCurrentIndex > meshBuilder.m_IndexBuilder.m_nIndexCount )
                    meshBuilder.m_IndexBuilder.m_nIndexCount = m_nCurrentIndex;
                }
                else
                {
                  BuildIndicesForSurface(
                    meshBuilder: &meshBuilder.m_IndexBuilder,
                    surfID: paintableSurfaces.m_Memory.m_pMemory[nSurfaceIndex]);
                  v56 = host_state.worldbrush;
                  m_nCurrentIndex = meshBuilder.m_IndexBuilder.m_nCurrentIndex;
                }
                ++nSurfaceIndex;
                --sortID;
              }
              while ( sortID != 0 );
              v11 = pRenderContext.m_pObject;
              if ( meshBuilder.m_bGenerateIndices )
              {
                switch ( meshBuilder.m_Type )
                {
                  case MATERIAL_LINE_STRIP:
                    v68 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
                    break;
                  case MATERIAL_LINE_LOOP:
                    v68 = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
                    break;
                  case MATERIAL_POLYGON:
                    v68 = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
                    break;
                  case MATERIAL_QUADS:
                    v68 = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
                    break;
                  case MATERIAL_INSTANCED_QUADS:
                    v68 = 0;
                    break;
                  default:
                    v68 = meshBuilder.m_VertexBuilder.m_nVertexCount;
                    break;
                }
                CIndexBuilder::GenerateIndices(
                  this: &meshBuilder.m_IndexBuilder,
                  primitiveType: meshBuilder.m_Type,
                  nIndexCount: v68);
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
              meshBuilder.m_pMesh->Draw_2(this: meshBuilder.m_pMesh, a2: -1, a3: 0);
              meshBuilder.m_pMesh = nullptr;
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
              v53 = src;
            }
            v50 = *(_WORD *)(*(_DWORD *)(numIndices + 576) + v53 + 4);
          }
          CShadowMgr::DisableStencilAndScissorMasking(
            this: v91,
            pRenderContext: v11,
            flashlightInfo: (const CShadowMgr::FlashlightInfo_t *)numIndices,
            bDoMasking);
        }
        ((void (__thiscall *)(IMatRenderContext *, _DWORD))v11->__vftable[1].EndRender)(a1: v11, a2: 0);
      }
      v11->SetFlashlightMode(this: v11, a2: false);
      v69 = flashlightInfos.m_Memory.m_pMemory;
      flashlightInfos.m_Size = 0;
      if ( flashlightInfos.m_Memory.m_nGrowSize >= 0 )
      {
        if ( flashlightInfos.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: flashlightInfos.m_Memory.m_pMemory);
          v69 = nullptr;
          flashlightInfos.m_Memory.m_pMemory = nullptr;
        }
        flashlightInfos.m_Memory.m_nAllocationCount = 0;
      }
      flashlightInfos.m_pElements = v69;
      if ( flashlightInfos.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v69 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v69);
          flashlightInfos.m_Memory.m_pMemory = nullptr;
        }
        flashlightInfos.m_Memory.m_nAllocationCount = 0;
      }
      v70 = batchPaintableSurfaceIndexCount.m_Memory.m_pMemory;
      batchPaintableSurfaceIndexCount.m_Size = 0;
      if ( batchPaintableSurfaceIndexCount.m_Memory.m_nGrowSize >= 0 )
      {
        if ( batchPaintableSurfaceIndexCount.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: batchPaintableSurfaceIndexCount.m_Memory.m_pMemory);
          v70 = nullptr;
          batchPaintableSurfaceIndexCount.m_Memory.m_pMemory = nullptr;
        }
        batchPaintableSurfaceIndexCount.m_Memory.m_nAllocationCount = 0;
      }
      batchPaintableSurfaceIndexCount.m_pElements = v70;
      if ( batchPaintableSurfaceIndexCount.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v70 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v70);
          batchPaintableSurfaceIndexCount.m_Memory.m_pMemory = nullptr;
        }
        batchPaintableSurfaceIndexCount.m_Memory.m_nAllocationCount = 0;
      }
      v71 = batchPaintableSurfaceCount.m_Memory.m_pMemory;
      batchPaintableSurfaceCount.m_Size = 0;
      if ( batchPaintableSurfaceCount.m_Memory.m_nGrowSize >= 0 )
      {
        if ( batchPaintableSurfaceCount.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: batchPaintableSurfaceCount.m_Memory.m_pMemory);
          v71 = nullptr;
          batchPaintableSurfaceCount.m_Memory.m_pMemory = nullptr;
        }
        batchPaintableSurfaceCount.m_Memory.m_nAllocationCount = 0;
      }
      batchPaintableSurfaceCount.m_pElements = v71;
      if ( batchPaintableSurfaceCount.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v71 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v71);
          batchPaintableSurfaceCount.m_Memory.m_pMemory = nullptr;
        }
        batchPaintableSurfaceCount.m_Memory.m_nAllocationCount = 0;
      }
      v72 = paintableSurfaces.m_Memory.m_pMemory;
      paintableSurfaces.m_Size = 0;
      if ( paintableSurfaces.m_Memory.m_nGrowSize >= 0 )
      {
        if ( paintableSurfaces.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: paintableSurfaces.m_Memory.m_pMemory);
          v72 = nullptr;
          paintableSurfaces.m_Memory.m_pMemory = nullptr;
        }
        paintableSurfaces.m_Memory.m_nAllocationCount = 0;
      }
      paintableSurfaces.m_pElements = v72;
      if ( paintableSurfaces.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v72 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v72);
          paintableSurfaces.m_Memory.m_pMemory = nullptr;
        }
        paintableSurfaces.m_Memory.m_nAllocationCount = 0;
      }
      v11->EndRender(this: v11);
      v11->Release(this: v11);
    }
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10112320
// Name: public: void CMaterialsBuckets<struct msurface2_t __near *>::SetNumMaterialSortIDs(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialsBuckets<msurface2_t *>::SetNumMaterialSortIDs(CMaterialsBuckets<msurface2_t *> *this, int n)
{
  UtlLinkedListElem_t<unsigned short,unsigned short> *m_pMemory; // ecx

  this->m_MaterialSortInfoArray.m_Size = 0;
  if ( this->m_MaterialSortInfoArray.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_MaterialSortInfoArray.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_MaterialSortInfoArray.m_Memory.m_pMemory);
      this->m_MaterialSortInfoArray.m_Memory.m_pMemory = nullptr;
    }
    this->m_MaterialSortInfoArray.m_Memory.m_nAllocationCount = 0;
  }
  this->m_MaterialSortInfoArray.m_pElements = this->m_MaterialSortInfoArray.m_Memory.m_pMemory;
  this->m_MaterialSortInfoArray.m_Size = 0;
  CUtlVector<CMaterialsBuckets<msurface2_t *>::MaterialSortInfo_t,CUtlMemory<CMaterialsBuckets<msurface2_t *>::MaterialSortInfo_t,int>>::InsertMultipleBefore(
    this: &this->m_MaterialSortInfoArray,
    elem: 0,
    num: n);
  CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short>,unsigned short> > *)&this->m_Elements);
  if ( this->m_Elements.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Elements.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Elements.m_Memory.m_pMemory);
      this->m_Elements.m_Memory.m_pMemory = nullptr;
    }
    this->m_Elements.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Elements.m_FirstFree = -1;
  this->m_Elements.m_pElements = this->m_Elements.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_Elements.m_NumAlloced = -65536;
  CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_UsedSortIDs);
  if ( this->m_UsedSortIDs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_UsedSortIDs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_UsedSortIDs.m_Memory.m_pMemory);
      this->m_UsedSortIDs.m_Memory.m_pMemory = nullptr;
    }
    this->m_UsedSortIDs.m_Memory.m_nAllocationCount = 0;
  }
  this->m_UsedSortIDs.m_FirstFree = -1;
  m_pMemory = this->m_UsedSortIDs.m_Memory.m_pMemory;
  *(_DWORD *)&this->m_UsedSortIDs.m_NumAlloced = -65536;
  this->m_UsedSortIDs.m_pElements = m_pMemory;
}

//------------------------------------------------------------------------------
// Address: 0x10112420
// Name: private: void CShadowMgr::SetMaterial(struct CShadowMgr::Shadow_t __near &,class IMaterial __near *,class IMaterial __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::SetMaterial(
        CShadowMgr *this,
        CShadowMgr::Shadow_t *shadow,
        IMaterial *pMaterial,
        IMaterial *pModelMaterial,
        void *pBindProxy)
{
  int m_Head; // eax
  UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short> *v6; // edx
  int m_ElementCount; // esi
  unsigned __int16 v8; // ax
  unsigned __int16 v9; // bx
  unsigned __int16 v10; // ax
  int m_Size; // ebx
  int v12; // edi
  int m_nAllocationCount; // eax
  unsigned __int16 *m_pMemory; // ecx
  int v15; // eax
  unsigned __int16 *v16; // eax

  shadow->m_pMaterial = pMaterial;
  shadow->m_pModelMaterial = pModelMaterial;
  shadow->m_pBindProxy = pBindProxy;
  if ( pMaterial != nullptr )
    pMaterial->IncrementReferenceCount(this: pMaterial);
  if ( pModelMaterial != nullptr )
    pModelMaterial->IncrementReferenceCount(this: pModelMaterial);
  m_Head = this->m_SortOrderIds.m_Head;
  if ( m_Head == 0xFFFF )
  {
LABEL_9:
    m_ElementCount = this->m_SortOrderIds.m_ElementCount;
    if ( m_ElementCount > m_SortOrderIdsMax )
    {
      if ( m_SortOrderIdsMax / 1000 != m_ElementCount / 1000 )
        _Warning(a1: "Shadow memory (%s) growing [%d]\n", "m_SortOrderIds", this->m_SortOrderIds.m_ElementCount);
      m_SortOrderIdsMax = m_ElementCount;
    }
    v8 = CUtlLinkedList<CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::AllocInternal(
           this: &this->m_SortOrderIds,
           multilist: false);
    v9 = v8;
    if ( v8 == 0xFFFF )
    {
      v10 = -1;
    }
    else
    {
      CUtlLinkedList<CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::LinkBefore(
        this: (CUtlLinkedList<CDispShadowFragment,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CDispShadowFragment,unsigned short>,unsigned short> > *)&this->m_SortOrderIds,
        before: 0xFFFFu,
        elem: v8);
      v10 = v9;
    }
    shadow->m_SortOrder = v10;
    this->m_SortOrderIds.m_Memory.m_pMemory[v10].m_Element.m_MaterialEnum = (int)pMaterial;
    this->m_SortOrderIds.m_Memory.m_pMemory[shadow->m_SortOrder].m_Element.m_RefCount = 1;
    m_Size = this->m_RenderQueue.m_Size;
    if ( m_Size > m_RenderQueueMax )
    {
      if ( m_RenderQueueMax / 1000 != m_Size / 1000 )
        _Warning(a1: "Shadow memory (%s) growing [%d]\n", "m_RenderQueue", this->m_RenderQueue.m_Size);
      m_RenderQueueMax = m_Size;
    }
    for ( ; m_Size < LOWORD(this->m_SortOrderIds.m_Memory.m_nAllocationCount); ++m_Size )
    {
      v12 = this->m_RenderQueue.m_Size;
      m_nAllocationCount = this->m_RenderQueue.m_Memory.m_nAllocationCount;
      if ( v12 + 1 > m_nAllocationCount )
        CUtlMemory<wchar_t,int>::Grow(
          this: (CUtlMemory<wchar_t,int> *)&this->m_RenderQueue,
          num: v12 - m_nAllocationCount + 1);
      ++this->m_RenderQueue.m_Size;
      m_pMemory = this->m_RenderQueue.m_Memory.m_pMemory;
      v15 = this->m_RenderQueue.m_Size - v12 - 1;
      this->m_RenderQueue.m_pElements = m_pMemory;
      if ( v15 > 0 )
        _V_memmove(dest: &m_pMemory[v12 + 1], src: &m_pMemory[v12], count: 2 * v15);
      v16 = &this->m_RenderQueue.m_Memory.m_pMemory[v12];
      if ( v16 != nullptr )
        *v16 = -1;
    }
  }
  else
  {
    v6 = this->m_SortOrderIds.m_Memory.m_pMemory;
    while ( (IMaterial *)v6[(unsigned __int16)m_Head].m_Element.m_MaterialEnum != pMaterial )
    {
      m_Head = v6[(unsigned __int16)m_Head].m_Next;
      if ( m_Head == 0xFFFF )
        goto LABEL_9;
    }
    ++v6[(unsigned __int16)m_Head].m_Element.m_RefCount;
    shadow->m_SortOrder = m_Head;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10112650
// Name: public: virtual void CShadowMgr::RemoveAllDecalsFromShadow(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::RemoveAllDecalsFromShadow(CShadowMgr *this, int handle)
{
  CShadowMgr::RemoveAllSurfacesFromShadow(this, handle);
  CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::RemoveElement(
    this: &this->m_ShadowsOnModels,
    element: handle);
}

//------------------------------------------------------------------------------
// Address: 0x10112680
// Name: public: virtual void CShadowMgr::SetShadowMaterial(unsigned short,class IMaterial __near *,class IMaterial __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::SetShadowMaterial(
        CShadowMgr *this,
        unsigned __int16 handle,
        IMaterial *pMaterial,
        IMaterial *pModelMaterial,
        void *pBindProxy)
{
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v6; // esi

  v6 = &this->m_Shadows.m_Memory.m_pMemory[handle];
  if ( v6->m_Element.m_pMaterial != pMaterial
    || v6->m_Element.m_pModelMaterial != pModelMaterial
    || v6->m_Element.m_pBindProxy != pBindProxy )
  {
    CShadowMgr::CleanupMaterial(this, shadow: &v6->m_Element);
    CShadowMgr::SetMaterial(this, shadow: &v6->m_Element, pMaterial, pModelMaterial, pBindProxy);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10112870
// Name: private: bool CShadowMgr::ComputeShadowVertices(struct CShadowMgr::ShadowDecal_t __near &,class VMatrix const __near *,class VMatrix const __near *,struct CShadowMgr::ShadowVertexCache_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShadowMgr::ComputeShadowVertices(
        CShadowMgr *this,
        Vector **decal,
        const VMatrix *pModelToWorld,
        ShadowVertex_t **pWorldToModel,
        CShadowMgr::ShadowVertexCache_t *pVertexCache)
{
  msurface2_t *v5; // esi
  void *v7; // esp
  int v8; // eax
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *p_temp; // ecx
  int v10; // eax
  int v11; // esi
  ShadowVertex_t *Vertices; // eax
  cplane_t *y_low; // ecx
  Vector *v15[3]; // [esp+0h] [ebp-664h] BYREF
  ShadowClipState_t clip; // [esp+Ch] [ebp-658h] BYREF
  VMatrix temp; // [esp+618h] [ebp-4Ch] BYREF
  Vector vToAdd; // [esp+658h] [ebp-Ch] BYREF

  v5 = (msurface2_t *)*decal;
  v7 = alloca((4 * HIBYTE((*decal)->x) + 15) & 0xFF0);
  v8 = 0;
  if ( HIBYTE((*decal)->x) != 0 )
  {
    do
    {
      v15[v8] = &host_state.worldbrush->vertexes[host_state.worldbrush->vertindices[v8 + v5->firstvertindex]].position;
      v5 = (msurface2_t *)*decal;
      ++v8;
    }
    while ( v8 < HIBYTE((*decal)->x) );
  }
  p_temp = &this->m_Shadows.m_Memory.m_pMemory[*((unsigned __int16 *)decal + 4)];
  if ( pModelToWorld != nullptr )
  {
    MatrixMultiply(src1: &p_temp->m_Element.m_WorldToShadow, src2: pModelToWorld, dst: &temp);
    p_temp = (UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *)&temp;
  }
  else
  {
    pWorldToModel = nullptr;
  }
  v10 = CShadowMgr::ProjectAndClipVertices(
          this,
          shadow: &this->m_Shadows.m_Memory.m_pMemory[*((unsigned __int16 *)decal + 4)].m_Element,
          worldToShadow: &p_temp->m_Element.m_WorldToShadow,
          (const VMatrix *)pWorldToModel,
          count: HIBYTE((*decal)->x),
          ppPosition: v15,
          ppOutVertex: &pWorldToModel,
          (int)&clip);
  v11 = v10;
  if ( v10 != 0 )
  {
    Vertices = CShadowMgr::AllocateVertices(this, cache: pVertexCache, count: v10);
    y_low = (cplane_t *)LODWORD((*decal)->y);
    vToAdd.x = y_low->normal.x * 0.1;
    vToAdd.y = y_low->normal.y * 0.1;
    vToAdd.z = y_low->normal.z * 0.1;
    CShadowMgr::CopyClippedVertices(this, count: v11, ppSrcVert: pWorldToModel, pDstVert: Vertices, &vToAdd);
    pVertexCache->m_Shadow = *((_WORD *)decal + 4);
    return 1;
  }
  else
  {
    pVertexCache->m_Count = 0;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101129D0
// Name: public: virtual void CShadowMgr::SetNumWorldMaterialBuckets(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::SetNumWorldMaterialBuckets(CShadowMgr *this, int numMaterialSortBins)
{
  unsigned __int16 m_Head; // ax
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *m_pMemory; // ecx
  unsigned int v5; // esi

  m_Head = this->m_FlashlightStates.m_Head;
  this->m_NumWorldMaterialBuckets = numMaterialSortBins;
  if ( m_Head != 0xFFFF )
  {
    m_pMemory = this->m_FlashlightStates.m_Memory.m_pMemory;
    do
    {
      v5 = m_Head;
      CMaterialsBuckets<msurface2_t *>::SetNumMaterialSortIDs(
        this: &m_pMemory[v5].m_Element.m_MaterialBuckets,
        n: numMaterialSortBins);
      CMaterialsBuckets<msurface2_t *>::SetNumMaterialSortIDs(
        this: &this->m_FlashlightStates.m_Memory.m_pMemory[v5].m_Element.m_OccluderBuckets,
        n: numMaterialSortBins);
      m_pMemory = this->m_FlashlightStates.m_Memory.m_pMemory;
      m_Head = m_pMemory[v5].m_Next;
    }
    while ( m_Head != 0xFFFF );
  }
  CShadowMgr::ClearAllFlashlightMaterialBuckets(this);
}

//------------------------------------------------------------------------------
// Address: 0x10112A50
// Name: private: void CShadowMgr::AllocFlashlightMaterialBuckets(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::AllocFlashlightMaterialBuckets(CShadowMgr *this, unsigned __int16 flashlightID)
{
  int v3; // edi

  v3 = flashlightID;
  CMaterialsBuckets<msurface2_t *>::SetNumMaterialSortIDs(
    this: &this->m_FlashlightStates.m_Memory.m_pMemory[v3].m_Element.m_MaterialBuckets,
    n: this->m_NumWorldMaterialBuckets);
  CMaterialsBuckets<msurface2_t *>::SetNumMaterialSortIDs(
    this: &this->m_FlashlightStates.m_Memory.m_pMemory[v3].m_Element.m_OccluderBuckets,
    n: this->m_NumWorldMaterialBuckets);
}

//------------------------------------------------------------------------------
// Address: 0x10112AA0
// Name: public: void CMaterialsBuckets<struct msurface2_t __near *>::AddElement(int,struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMaterialsBuckets<msurface2_t *>::AddElement(
        CMaterialsBuckets<msurface2_t *> *this,
        int sortID,
        msurface2_t *elem)
{
  unsigned __int16 v4; // ax
  unsigned __int16 v5; // bx
  int m_FlushCount; // ecx
  CMaterialsBuckets<msurface2_t *>::MaterialSortInfo_t *v7; // eax
  unsigned __int16 v8; // ax
  int v9; // edi
  UtlLinkedListElem_t<unsigned short,unsigned short> *v10; // eax

  v4 = CUtlLinkedList<msurface2_t *,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<msurface2_t *,unsigned short>,unsigned short>>::AllocInternal(
         this: &this->m_Elements,
         multilist: true);
  v5 = -1;
  if ( v4 != 0xFFFF )
    v5 = v4;
  this->m_Elements.m_Memory.m_pMemory[v5].m_Element = elem;
  m_FlushCount = this->m_FlushCount;
  v7 = &this->m_MaterialSortInfoArray.m_Memory.m_pMemory[sortID];
  if ( v7->m_FlushCount == m_FlushCount )
  {
    CUtlLinkedList<CClientSendTable *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CClientSendTable *,unsigned short>,unsigned short>>::LinkBefore(
      this: (CUtlLinkedList<unsigned int,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned int,unsigned short>,unsigned short> > *)&this->m_Elements,
      before: v7->m_Head,
      elem: v5);
  }
  else
  {
    v7->m_FlushCount = m_FlushCount;
    v8 = CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::AllocInternal(
           this: &this->m_UsedSortIDs,
           multilist: false);
    v9 = v8;
    if ( v8 != 0xFFFF )
    {
      CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::LinkBefore(
        this: &this->m_UsedSortIDs,
        before: 0xFFFFu,
        elem: v8);
      v10 = &this->m_UsedSortIDs.m_Memory.m_pMemory[v9];
      if ( v10 != nullptr )
      {
        v10->m_Element = sortID;
        this->m_MaterialSortInfoArray.m_Memory.m_pMemory[sortID].m_Head = v5;
        return;
      }
    }
  }
  this->m_MaterialSortInfoArray.m_Memory.m_pMemory[sortID].m_Head = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10112C60
// Name: private: struct CShadowMgr::SurfaceBounds_t const __near * CShadowMgr::GetSurfaceBounds(struct msurface2_t __near *)
// Source: json
//------------------------------------------------------------------------------
const CShadowMgr::SurfaceBounds_t *__thiscall CShadowMgr::GetSurfaceBounds(CShadowMgr *this, msurface2_t *surfID)
{
  int v3; // ebx
  int v4; // eax
  bool v6; // cc
  CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16> > *p_m_SurfaceBoundsCache; // ecx
  int m_Tail_low; // edi
  int v9; // eax
  unsigned __int16 v10; // di
  CShadowMgr::SurfaceBounds_t *v11; // edi
  unsigned __int16 nIndex; // [esp+8h] [ebp-4h]

  v3 = surfID - host_state.worldbrush->surfaces2;
  v4 = this->m_pSurfaceBounds[v3];
  if ( (_WORD)v4 != 0xFFFF )
    return (const CShadowMgr::SurfaceBounds_t *)(((unsigned int)&this->m_SurfaceBoundsCache.m_Memory.m_Memory[15]
                                                & 0xFFFFFFF0)
                                               + 80 * v4);
  v6 = this->m_SurfaceBoundsCache.m_ElementCount < 1024;
  p_m_SurfaceBoundsCache = &this->m_SurfaceBoundsCache;
  if ( v6 )
  {
    v9 = CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::AllocInternal(
           this: p_m_SurfaceBoundsCache,
           multilist: false);
    v10 = v9;
    if ( v9 != 0xFFFF )
      CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::LinkAfter(
        this: &this->m_SurfaceBoundsCache,
        after: 0xFFFF,
        elem: v9);
    nIndex = v10;
  }
  else
  {
    m_Tail_low = LOWORD(this->m_SurfaceBoundsCache.m_Tail);
    nIndex = this->m_SurfaceBoundsCache.m_Tail;
    CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::Unlink(
      this: p_m_SurfaceBoundsCache,
      elem: m_Tail_low);
    CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::LinkAfter(
      this: &this->m_SurfaceBoundsCache,
      after: 0xFFFF,
      elem: m_Tail_low);
    this->m_pSurfaceBounds[*(_DWORD *)(((unsigned int)&this->m_SurfaceBoundsCache.m_Memory.m_Memory[15] & 0xFFFFFFF0)
                                     + 80 * m_Tail_low
                                     + 0x30)] = -1;
  }
  this->m_pSurfaceBounds[v3] = nIndex;
  v11 = (CShadowMgr::SurfaceBounds_t *)(80 * nIndex
                                      + ((unsigned int)&this->m_SurfaceBoundsCache.m_Memory.m_Memory[15] & 0xFFFFFFF0));
  v11->m_nSurfaceIndex = v3;
  CShadowMgr::ComputeSurfaceBounds(this, pBounds: v11, nSurfID: surfID);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x10112D70
// Name: private: bool CShadowMgr::IsShadowNearSurface(unsigned short,struct msurface2_t __near *,class VMatrix const __near *,class VMatrix const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
bool __userpurge CShadowMgr::IsShadowNearSurface@<al>(
        CShadowMgr *this@<ecx>,
        int a2@<ebp>,
        unsigned __int16 h,
        msurface2_t *nSurfID,
        const VMatrix *pModelToWorld,
        const VMatrix *pWorldToModel)
{
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v6; // esi
  const CShadowMgr::SurfaceBounds_t *SurfaceBounds; // edi
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float x; // xmm3_4
  float y; // xmm4_4
  float z; // xmm5_4
  float v15; // xmm3_4
  float v16; // xmm4_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm4_4
  const Ray_t *p_m_Ray; // [esp-24h] [ebp-84h]
  float v23[3]; // [esp-Ch] [ebp-6Ch] BYREF
  Ray_t transformedRay_4; // [esp+4h] [ebp-5Ch] OVERLAPPED BYREF
  int v25; // [esp+54h] [ebp-Ch]
  void *v26; // [esp+58h] [ebp-8h]
  void *retaddr; // [esp+60h] [ebp+0h]

  v25 = a2;
  v26 = retaddr;
  v6 = &this->m_Shadows.m_Memory.m_pMemory[h];
  SurfaceBounds = CShadowMgr::GetSurfaceBounds(this, surfID: nSurfID);
  if ( pModelToWorld != nullptr )
  {
    x = SurfaceBounds->m_vecCenter.x;
    y = SurfaceBounds->m_vecCenter.y;
    z = SurfaceBounds->m_vecCenter.z;
    v8 = (float)((float)((float)(pModelToWorld->m[0][1] * y) + (float)(pModelToWorld->m[0][0] * x))
               + (float)(pModelToWorld->m[0][2] * z))
       + pModelToWorld->m[0][3];
    v9 = (float)((float)((float)(pModelToWorld->m[1][1] * y) + (float)(pModelToWorld->m[1][0] * x))
               + (float)(pModelToWorld->m[1][2] * z))
       + pModelToWorld->m[1][3];
    v10 = (float)((float)((float)(pModelToWorld->m[2][1] * y) + (float)(pModelToWorld->m[2][0] * x))
                + (float)(pModelToWorld->m[2][2] * z))
        + pModelToWorld->m[2][3];
  }
  else
  {
    v8 = SurfaceBounds->m_vecCenter.x;
    v9 = SurfaceBounds->m_vecCenter.y;
    v10 = SurfaceBounds->m_vecCenter.z;
  }
  if ( (float)((float)((float)((float)(v6->m_Element.m_vecSphereCenter.x - v8)
                             * (float)(v6->m_Element.m_vecSphereCenter.x - v8))
                     + (float)((float)(v6->m_Element.m_vecSphereCenter.y - v9)
                             * (float)(v6->m_Element.m_vecSphereCenter.y - v9)))
             + (float)((float)(v6->m_Element.m_vecSphereCenter.z - v10)
                     * (float)(v6->m_Element.m_vecSphereCenter.z - v10))) >= (float)((float)(v6->m_Element.m_flSphereRadius
                                                                                           + SurfaceBounds->m_flRadius)
                                                                                   * (float)(v6->m_Element.m_flSphereRadius
                                                                                           + SurfaceBounds->m_flRadius)) )
    return false;
  if ( pModelToWorld != nullptr )
  {
    v15 = pWorldToModel->m[0][1];
    v16 = pWorldToModel->m[0][0];
    transformedRay_4.m_Extents.x = 0.0;
    v17 = v6->m_Element.m_Ray.m_Start.x;
    v18 = v6->m_Element.m_Ray.m_Start.y;
    v19 = v6->m_Element.m_Ray.m_Start.z;
    v20 = (float)((float)((float)(v15 * v18) + (float)(v16 * v17)) + (float)(pWorldToModel->m[0][2] * v19))
        + pWorldToModel->m[0][3];
    v21 = pWorldToModel->m[1][0];
    v23[0] = v20;
    v23[1] = (float)((float)((float)(pWorldToModel->m[1][1] * v18) + (float)(v21 * v17))
                   + (float)(pWorldToModel->m[1][2] * v19))
           + pWorldToModel->m[1][3];
    v23[2] = (float)((float)((float)(pWorldToModel->m[2][1] * v18) + (float)(pWorldToModel->m[2][0] * v17))
                   + (float)(pWorldToModel->m[2][2] * v19))
           + pWorldToModel->m[2][3];
    Vector3DMultiply(src1: pWorldToModel, src2: &v6->m_Element.m_Ray.m_Delta, dst: &transformedRay_4.m_Start);
    transformedRay_4.m_Delta = v6->m_Element.m_Ray.m_StartOffset;
    transformedRay_4.m_StartOffset = v6->m_Element.m_Ray.m_Extents;
    LOWORD(transformedRay_4.m_Extents.y) = *(_WORD *)&v6->m_Element.m_Ray.m_IsRay;
    p_m_Ray = (const Ray_t *)v23;
  }
  else
  {
    p_m_Ray = &v6->m_Element.m_Ray;
  }
  *(__m128 *)&transformedRay_4.m_pWorldAxisTransform = Four_Zeros;
  return IsBoxIntersectingRay(
           boxMin: &SurfaceBounds->m_vecMins,
           boxMax: &SurfaceBounds->m_vecMaxs,
           ray: p_m_Ray,
           fl4Tolerance: (const __m128 *)&transformedRay_4.m_pWorldAxisTransform);
}

//------------------------------------------------------------------------------
// Address: 0x10112FC0
// Name: private: void CShadowMgr::ApplyFlashlightToLeaf(struct CShadowMgr::Shadow_t const __near &,struct mleaf_t __near *,struct CShadowMgr::ShadowBuildInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::ApplyFlashlightToLeaf(
        CShadowMgr *this,
        const CShadowMgr::Shadow_t *shadow,
        mleaf_t *pLeaf,
        CShadowMgr::ShadowBuildInfo_t *pBuild)
{
  mleaf_t *v4; // ebx
  float x; // xmm0_4
  float y; // xmm2_4
  float z; // xmm6_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  const Frustum_t *(__thiscall *GetFlashlightFrustum)(struct CShadowMgr *, unsigned __int16); // eax
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  int m_Shadow; // edx
  float v16; // xmm2_4
  float v17; // xmm6_4
  float v18; // xmm2_4
  Frustum_t *v19; // eax
  int v20; // eax
  int v21; // eax
  msurface2_t *v22; // esi
  int firstvertindex; // edx
  int v24; // edx
  mvertex_t *vertexes; // eax
  float v26; // xmm0_4
  mvertex_t *v27; // eax
  float *p_x; // ebx
  CShadowMgr *v29; // ecx
  bool v30; // cc
  int nummarksurfaces; // ecx
  Vector leafMins; // [esp+8h] [ebp-30h] BYREF
  Vector leafMaxs; // [esp+14h] [ebp-24h] BYREF
  Vector lookdir; // [esp+20h] [ebp-18h] BYREF
  msurface2_t **pHandle; // [esp+2Ch] [ebp-Ch]
  int i; // [esp+30h] [ebp-8h]
  CShadowMgr *v37; // [esp+34h] [ebp-4h]
  bool bCullDepth_3; // [esp+4Bh] [ebp+13h]

  v37 = this;
  v4 = pLeaf;
  x = pLeaf->m_vecCenter.x;
  y = pLeaf->m_vecHalfDiagonal.y;
  z = pLeaf->m_vecHalfDiagonal.z;
  v9 = pLeaf->m_vecHalfDiagonal.x + x;
  v10 = x - pLeaf->m_vecHalfDiagonal.x;
  GetFlashlightFrustum = this->GetFlashlightFrustum;
  leafMaxs.x = v9;
  v12 = pLeaf->m_vecCenter.y;
  v13 = y + v12;
  v14 = v12 - pLeaf->m_vecHalfDiagonal.y;
  m_Shadow = pBuild->m_Shadow;
  leafMaxs.y = v13;
  v16 = pLeaf->m_vecCenter.z;
  v17 = z + v16;
  v18 = v16 - pLeaf->m_vecHalfDiagonal.z;
  leafMaxs.z = v17;
  leafMins.x = v10;
  leafMins.y = v14;
  leafMins.z = v18;
  v19 = (Frustum_t *)GetFlashlightFrustum(this, a2: m_Shadow);
  if ( !Frustum_t::CullBox(this: v19, mins: &leafMins, maxs: &leafMaxs) )
  {
    v20 = r_flashlightculldepth.m_pParent != nullptr ? r_flashlightculldepth.m_pParent->m_Value.m_nValue : 0;
    bCullDepth_3 = v20 != 0;
    v21 = 0;
    pHandle = &host_state.worldbrush->marksurfaces[pLeaf->firstmarksurface];
    i = 0;
    if ( pLeaf->nummarksurfaces != 0 )
    {
      do
      {
        v22 = pHandle[v21];
        if ( v22->visframe != r_surfacevisframe )
        {
          firstvertindex = v22->firstvertindex;
          v22->visframe = r_surfacevisframe;
          v24 = host_state.worldbrush->vertindices[firstvertindex];
          vertexes = host_state.worldbrush->vertexes;
          v26 = vertexes[v24].position.x - pBuild->m_RayStart.x;
          v27 = &vertexes[v24];
          lookdir.x = v26;
          lookdir.y = v27->position.y - pBuild->m_RayStart.y;
          lookdir.z = v27->position.z - pBuild->m_RayStart.z;
          VectorNormalize(vec: &lookdir);
          p_x = &v22->plane->normal.x;
          if ( fabs(
                 pBuild->m_vecSphereCenter.y * p_x[1]
               + *p_x * pBuild->m_vecSphereCenter.x
               + pBuild->m_vecSphereCenter.z * p_x[2]
               - p_x[3]) < pBuild->m_flSphereRadius )
          {
            v29 = v37;
            if ( (v37->m_Shadows.m_Memory.m_pMemory[pBuild->m_Shadow].m_Element.m_Flags & 6) != 0
              || (v22->flags & 0x3020) == 0 )
            {
              CShadowMgr::AddShadowDecalToSurface(this: v37, surfID: v22, handle: pBuild->m_Shadow);
              v29 = v37;
            }
            if ( !bCullDepth_3
              || ((v22->flags & 0x200) != 0
                ? (v30 = fabs(*p_x * lookdir.x + p_x[1] * lookdir.y + p_x[2] * lookdir.z) >= 0.0099999998)
                : (v30 = (float)((float)((float)(*p_x * lookdir.x) + (float)(p_x[1] * lookdir.y))
                               + (float)(p_x[2] * lookdir.z)) >= 0.0099999998),
                  v30) )
            {
              CMaterialsBuckets<msurface2_t *>::AddElement(
                this: &v29->m_FlashlightStates.m_Memory.m_pMemory[shadow->m_FlashlightHandle].m_Element.m_OccluderBuckets,
                sortID: v22->materialSortID,
                elem: v22);
            }
          }
          v4 = pLeaf;
        }
        nummarksurfaces = v4->nummarksurfaces;
        v21 = i + 1;
        i = v21;
      }
      while ( v21 < nummarksurfaces );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10113200
// Name: public: virtual bool CShadowMgr::EnumerateLeaf(int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShadowMgr::EnumerateLeaf(CShadowMgr *this, int leaf, CShadowMgr::ShadowBuildInfo_t *context)
{
  int v4; // eax
  ISpatialLeafEnumerator_vtbl *v5; // eax
  mleaf_t *v6; // edi
  CShadowMgr *v7; // ecx
  IDispInfo *v8; // esi
  CShadowMgr *v10; // [esp+Ch] [ebp-4h]
  CShadowMgr *v11; // [esp+Ch] [ebp-4h]
  bool bIsFlashlight; // [esp+18h] [ebp+8h]
  int i; // [esp+1Ch] [ebp+Ch]

  v10 = this;
  if ( context->m_pVis != nullptr )
  {
    v4 = CM_LeafCluster(leafnum: leaf);
    if ( ((unsigned __int8)(1 << (v4 & 7)) & context->m_pVis[v4 >> 3]) == 0 )
      return 1;
    this = v10;
  }
  v5 = &this->ISpatialLeafEnumerator::__vftable[84 * context->m_Shadow];
  v6 = &host_state.worldbrush->leafs[leaf];
  v7 = (CShadowMgr *)((char *)this - 4);
  v11 = v7;
  if ( ((int)v5[30].EnumerateLeaf & 6) != 0 )
  {
    bIsFlashlight = true;
    CShadowMgr::ApplyFlashlightToLeaf(this: v7, shadow: (const CShadowMgr::Shadow_t *)v5, pLeaf: v6, pBuild: context);
  }
  else
  {
    bIsFlashlight = false;
    CShadowMgr::ApplyShadowToLeaf(this: v7, shadow: (const CShadowMgr::Shadow_t *)v5, pLeaf: v6, pBuild: context);
  }
  i = 0;
  if ( v6->dispCount != 0 )
  {
    do
    {
      v8 = DispInfo_IndexArray(
             hArray: host_state.worldbrush->hDispInfos,
             iElement: host_state.worldbrush->m_pDispInfoReferences[i + v6->dispListStart]);
      if ( !v8->GetTag(this: v8) )
      {
        v8->SetTag(this: v8);
        CShadowMgr::ApplyShadowToDisplacement(this: v11, build: context, pDispInfo: v8, bIsFlashlight);
      }
      ++i;
    }
    while ( i < v6->dispCount );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10113300
// Name: public: virtual void CShadowMgr::AddShadowsOnSurfaceToRenderList(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::AddShadowsOnSurfaceToRenderList(CShadowMgr *this, unsigned __int16 decalHandle)
{
  unsigned __int16 i; // dx
  UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short> *m_pMemory; // ecx
  unsigned int v5; // edi
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v6; // eax
  msurface2_t *m_SurfID; // ecx
  int v8; // edx
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *v9; // eax
  int v10; // edx
  int m_SortOrder; // eax

  if ( r_shadows.m_pParent != nullptr && r_shadows.m_pParent->m_Value.m_nValue != 0 )
  {
    for ( i = decalHandle; i != 0xFFFF; i = this->m_ShadowDecals.m_Memory.m_pMemory[v5].m_Next )
    {
      m_pMemory = this->m_ShadowDecals.m_Memory.m_pMemory;
      v5 = i;
      v6 = &this->m_Shadows.m_Memory.m_pMemory[m_pMemory[v5].m_Element.m_Shadow];
      if ( (v6->m_Element.m_Flags & 6) != 0 )
      {
        m_SurfID = m_pMemory[i].m_Element.m_SurfID;
        if ( !this->m_bSinglePassFlashlightStateEnabled )
        {
          v8 = 3 * v6->m_Element.m_FlashlightHandle;
          v9 = this->m_FlashlightStates.m_Memory.m_pMemory;
          v10 = v8 << 8;
          if ( *(int *)((char *)&v9->m_Element.m_nSplitscreenOwner + v10) == 0 )
            CMaterialsBuckets<msurface2_t *>::AddElement(
              this: (CMaterialsBuckets<msurface2_t *> *)((char *)&v9->m_Element.m_MaterialBuckets + v10),
              sortID: m_SurfID->materialSortID,
              elem: m_SurfID);
        }
      }
      else
      {
        if ( r_shadows_gamecontrol.m_pParent == nullptr
          || r_shadows_gamecontrol.m_pParent->m_Value.m_nValue == 0
          || this->m_nSkipShadowForEntIndex == v6->m_Element.m_nEntIndex )
        {
          continue;
        }
        m_SortOrder = v6->m_Element.m_SortOrder;
        m_pMemory[v5].m_Element.m_NextRender = this->m_RenderQueue.m_Memory.m_pMemory[m_SortOrder];
        this->m_RenderQueue.m_Memory.m_pMemory[m_SortOrder] = i;
      }
      ++this->m_DecalsToRender;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101133F0
// Name: private: bool CShadowMgr::GenerateNormalShadowRenderInfo(class IMatRenderContext __near *,struct CShadowMgr::ShadowDecal_t __near &,struct CShadowMgr::ShadowRenderInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShadowMgr::GenerateNormalShadowRenderInfo(
        CShadowMgr *this,
        IMatRenderContext *pRenderContext,
        Vector **decal,
        CShadowMgr::ShadowRenderInfo_t *info)
{
  int m_Count; // ecx
  int v7; // edx
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short> *v8; // edi
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // ecx
  int m_NumAlloced; // edi
  unsigned __int16 v14; // ax
  int m_nAllocationCount; // edi
  int v16; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  m_Count = info->m_Count;
  if ( m_Count >= 0x10000 )
  {
    info->m_Count = 0x10000;
    return 1;
  }
  v7 = *((unsigned __int16 *)decal + 6);
  if ( (_WORD)v7 == 0xFFFF )
  {
    if ( !CShadowMgr::IsShadowNearSurface(
            this,
            a2: (int)&savedregs,
            h: *((_WORD *)decal + 4),
            nSurfID: (msurface2_t *)*decal,
            pModelToWorld: info->m_pModelToWorld,
            pWorldToModel: &info->m_WorldToModel) )
      return 0;
    if ( (this->m_Shadows.m_Memory.m_pMemory[*((unsigned __int16 *)decal + 4)].m_Element.m_Flags & 1) != 0 )
    {
      m_NumAlloced = this->m_VertexCache.m_NumAlloced;
      if ( m_NumAlloced > m_VertexCacheMax )
      {
        if ( m_VertexCacheMax / 1000 != m_NumAlloced / 1000 )
          _Warning(a1: "Shadow memory (%s) growing [%d]\n", "m_VertexCache", this->m_VertexCache.m_NumAlloced);
        m_VertexCacheMax = m_NumAlloced;
      }
      v14 = CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::AddToTail(this: &this->m_VertexCache);
      *((_WORD *)decal + 6) = v14;
      info->m_pCache[info->m_Count] = v14;
      v8 = &this->m_VertexCache.m_Memory.m_pMemory[*((unsigned __int16 *)decal + 6)];
    }
    else
    {
      m_nAllocationCount = this->m_TempVertexCache.m_Memory.m_nAllocationCount;
      if ( m_nAllocationCount > m_TempVertexCacheMax )
      {
        if ( m_TempVertexCacheMax / 1000 != m_nAllocationCount / 1000 )
          _Warning(
            a1: "Shadow memory (%s) growing [%d]\n",
            "m_TempVertexCache",
            this->m_TempVertexCache.m_Memory.m_nAllocationCount);
        m_TempVertexCacheMax = m_nAllocationCount;
      }
      v16 = CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::AddToTail(this: (CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int> > *)&this->m_TempVertexCache);
      info->m_pCache[info->m_Count] = -1 - v16;
      v8 = (UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short> *)&this->m_TempVertexCache.m_Memory.m_pMemory[v16];
    }
    if ( CShadowMgr::ComputeShadowVertices(
           this,
           decal,
           pModelToWorld: info->m_pModelToWorld,
           pWorldToModel: (ShadowVertex_t **)&info->m_WorldToModel,
           pVertexCache: &v8->m_Element) == 0 )
      return 0;
  }
  else
  {
    info->m_pCache[m_Count] = v7;
    v8 = &this->m_VertexCache.m_Memory.m_pMemory[*((unsigned __int16 *)decal + 6)];
  }
  v9 = v8->m_Element.m_Count;
  v10 = 3 * v9 - 6;
  v11 = info->m_VertexCount + v9;
  if ( v11 < info->m_nMaxVertices )
  {
    v12 = info->m_IndexCount + v10;
    if ( v12 < info->m_nMaxIndices )
    {
      ++info->m_Count;
      info->m_VertexCount = v11;
      info->m_IndexCount = v12;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101135B0
// Name: private: void CShadowMgr::GenerateShadowRenderInfo(class IMatRenderContext __near *,unsigned short,struct CShadowMgr::ShadowRenderInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::GenerateShadowRenderInfo(
        CShadowMgr *this,
        IMatRenderContext *pRenderContext,
        unsigned __int16 decalHandle,
        CShadowMgr::ShadowRenderInfo_t *info)
{
  UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short> *v6; // esi
  char NormalShadowRenderInfo; // al
  unsigned __int16 next; // [esp+1Ch] [ebp+10h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CShadowMgr::GenerateShadowRenderInfo",
    a3: 0,
    a4: "Shadow_Rendering",
    a5: false,
    a6: 4);
  info->m_VertexCount = 0;
  info->m_IndexCount = 0;
  info->m_Count = 0;
  info->m_DispCount = 0;
  if ( decalHandle != 0xFFFF )
  {
    do
    {
      v6 = &this->m_ShadowDecals.m_Memory.m_pMemory[decalHandle];
      next = v6->m_Element.m_NextRender;
      if ( this->m_Shadows.m_Memory.m_pMemory[v6->m_Element.m_Shadow].m_Element.m_FalloffBias != 0xFF )
      {
        if ( v6->m_Element.m_DispShadow == 0xFFFF )
          NormalShadowRenderInfo = CShadowMgr::GenerateNormalShadowRenderInfo(
                                     this,
                                     pRenderContext,
                                     decal: (Vector **)v6,
                                     info);
        else
          NormalShadowRenderInfo = CShadowMgr::GenerateDispShadowRenderInfo(this, decal: &v6->m_Element, info);
        if ( NormalShadowRenderInfo == 0
          && (this->m_Shadows.m_Memory.m_pMemory[v6->m_Element.m_Shadow].m_Element.m_Flags & 1) != 0 )
        {
          CShadowMgr::RemoveShadowDecalFromSurface(this, surfID: v6->m_Element.m_SurfID, decalHandle);
        }
      }
      decalHandle = next;
    }
    while ( next != 0xFFFF );
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10113690
// Name: private: void CShadowMgr::GenerateShadowRenderInfoThreaded(class IMatRenderContext __near *,unsigned short,struct CShadowMgr::ShadowRenderInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::GenerateShadowRenderInfoThreaded(
        CShadowMgr *this,
        IMatRenderContext *pRenderContext,
        unsigned __int16 decalHandle,
        CShadowMgr::ShadowRenderInfo_t *info)
{
  signed int v5; // ebx
  void *v7; // esp
  unsigned __int16 v8; // cx
  UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short> *v9; // ebx
  int m_Shadow; // edx
  unsigned __int16 *v11; // eax
  int *p_vertCount; // ebx
  UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short> *v13; // eax
  int m_IndexCount; // ecx
  int v15; // edx
  int m_DispCount; // ecx
  _BYTE v17[12]; // [esp+0h] [ebp-48h] BYREF
  CParallelProcessor<CShadowMgr::DispDecalWorkItem_t,CMemberFuncJobItemProcessor<CShadowMgr::DispDecalWorkItem_t,CShadowMgr,CShadowMgr>,1> v18; // [esp+Ch] [ebp-3Ch] BYREF
  int next; // [esp+3Ch] [ebp-Ch]
  CShadowMgr::DispDecalWorkItem_t *pDispDecalWorkItems; // [esp+40h] [ebp-8h]
  unsigned __int16 *v21; // [esp+44h] [ebp-4h]
  int decalHandlea; // [esp+54h] [ebp+Ch]
  int nNumDispDecals; // [esp+58h] [ebp+10h]
  int nNumDispDecalsa; // [esp+58h] [ebp+10h]

  v5 = 0;
  info->m_VertexCount = 0;
  info->m_IndexCount = 0;
  info->m_Count = 0;
  info->m_DispCount = 0;
  v7 = alloca(12 * this->m_DecalsToRender);
  v8 = decalHandle;
  pDispDecalWorkItems = (CShadowMgr::DispDecalWorkItem_t *)v17;
  nNumDispDecals = 0;
  if ( decalHandle != 0xFFFF )
  {
    v21 = (unsigned __int16 *)v17;
    while ( 1 )
    {
      v9 = &this->m_ShadowDecals.m_Memory.m_pMemory[v8];
      m_Shadow = v9->m_Element.m_Shadow;
      next = v9->m_Element.m_NextRender;
      if ( this->m_Shadows.m_Memory.m_pMemory[m_Shadow].m_Element.m_FalloffBias != 0xFF )
      {
        if ( v9->m_Element.m_DispShadow == 0xFFFF )
        {
          if ( CShadowMgr::GenerateNormalShadowRenderInfo(this, pRenderContext, decal: (Vector **)v9, info) == 0
            && (this->m_Shadows.m_Memory.m_pMemory[v9->m_Element.m_Shadow].m_Element.m_Flags & 1) != 0 )
          {
            CShadowMgr::RemoveShadowDecalFromSurface(this, surfID: v9->m_Element.m_SurfID, decalHandle);
          }
        }
        else
        {
          v11 = v21;
          ++nNumDispDecals;
          *v21 = v8;
          v21 = v11 + 6;
        }
      }
      decalHandle = next;
      if ( (_WORD)next == 0xFFFF )
        break;
      v8 = next;
    }
    v5 = nNumDispDecals;
  }
  v18.m_pItems.m_value = nullptr;
  v18.m_pLimit = nullptr;
  _InterlockedExchange((volatile __int32 *)&v18.m_pItems, 0);
  LODWORD(v18.m_ItemProcessor.m_pfnProcess) = CShadowMgr::ProcessDispDecalWorkItem;
  memset((char *)&v18.m_ItemProcessor.m_pfnProcess + 4, 0, 20);
  v18.m_ItemProcessor.m_pObject = this;
  CParallelProcessor<CShadowMgr::DispDecalWorkItem_t,CMemberFuncJobItemProcessor<CShadowMgr::DispDecalWorkItem_t,CShadowMgr,CShadowMgr>,1>::Run(
    this: &v18,
    pItems: pDispDecalWorkItems,
    nItems: v5,
    nChunkSize: 1,
    nMaxParallel: 0x7FFFFFFF,
    pThreadPool: nullptr);
  if ( v5 > 0 )
  {
    p_vertCount = &pDispDecalWorkItems->vertCount;
    decalHandlea = nNumDispDecals;
    do
    {
      v13 = &this->m_ShadowDecals.m_Memory.m_pMemory[*((unsigned __int16 *)p_vertCount - 2)];
      if ( *((_BYTE *)p_vertCount - 2) != 0 )
      {
        nNumDispDecalsa = *p_vertCount + info->m_VertexCount;
        if ( nNumDispDecalsa < info->m_nMaxVertices )
        {
          m_IndexCount = info->m_IndexCount;
          if ( m_IndexCount + p_vertCount[1] < info->m_nMaxIndices )
          {
            info->m_VertexCount = nNumDispDecalsa;
            v15 = m_IndexCount + p_vertCount[1];
            m_DispCount = info->m_DispCount;
            info->m_IndexCount = v15;
            info->m_pDispCache[m_DispCount] = v13->m_Element.m_DispShadow;
            ++info->m_DispCount;
          }
        }
      }
      else if ( (this->m_Shadows.m_Memory.m_pMemory[v13->m_Element.m_Shadow].m_Element.m_Flags & 1) != 0 )
      {
        CShadowMgr::RemoveShadowDecalFromSurface(
          this,
          surfID: v13->m_Element.m_SurfID,
          decalHandle: *((_WORD *)p_vertCount - 2));
      }
      p_vertCount += 3;
      --decalHandlea;
    }
    while ( decalHandlea != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10113860
// Name: private: void CShadowMgr::RenderShadowList(class IMatRenderContext __near *,unsigned short,class VMatrix const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::RenderShadowList(
        CShadowMgr *this,
        IMatRenderContext *pRenderContext,
        unsigned __int16 decalHandle,
        const VMatrix *pModelToWorld)
{
  int m_nAllocationCount; // ecx
  int m_DecalsToRender; // eax
  int v7; // eax
  int v8; // edi
  int v9; // ecx
  int v10; // eax
  int v11; // eax
  int v12; // edi
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v13; // ebx
  int v14; // edi
  int v15; // ebx
  unsigned __int16 *m_pMemory; // edx
  int v17; // eax
  int (__thiscall *GetMaxVerticesToRender)(IMatRenderContext *, IMaterial *); // edx
  IMesh *v19; // edi
  int v20; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-250h] BYREF
  CShadowMgr::ShadowRenderInfo_t info; // [esp+1F4h] [ebp-68h] BYREF
  CShadowMgr::Shadow_t *shadow; // [esp+258h] [ebp-4h]
  int savedregs; // [esp+25Ch] [ebp+0h] BYREF

  m_nAllocationCount = this->m_ShadowDecalCache.m_nAllocationCount;
  m_DecalsToRender = this->m_DecalsToRender;
  if ( m_DecalsToRender > m_nAllocationCount )
  {
    if ( m_DecalsToRender >= 0x10000 )
      m_DecalsToRender = 0x10000;
    v7 = m_DecalsToRender - m_nAllocationCount;
    v8 = v7;
    if ( v7 > 0 )
    {
      CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&this->m_ShadowDecalCache, num: v7);
      DevMsg(
        a1: "[CShadowMgr::RenderShadowList] growing shadow decal cache (decals: %d, cache: %d, diff: %d).\n",
        this->m_DecalsToRender,
        this->m_ShadowDecalCache.m_nAllocationCount,
        v8);
    }
  }
  v9 = this->m_DispShadowDecalCache.m_nAllocationCount;
  v10 = this->m_DecalsToRender;
  if ( v10 > v9 )
  {
    if ( v10 >= 0x10000 )
      v10 = 0x10000;
    v11 = v10 - v9;
    v12 = v11;
    if ( v11 > 0 )
    {
      CUtlMemory<wchar_t,int>::Grow(this: (CUtlMemory<wchar_t,int> *)&this->m_DispShadowDecalCache, num: v11);
      DevMsg(
        a1: "[CShadowMgr::RenderShadowList] growing disp shadow decal cache (decals: %d, cache: %d, diff: %d).\n",
        this->m_DecalsToRender,
        this->m_DispShadowDecalCache.m_nAllocationCount,
        v12);
    }
  }
  v13 = &this->m_Shadows.m_Memory.m_pMemory[this->m_ShadowDecals.m_Memory.m_pMemory[decalHandle].m_Element.m_Shadow];
  shadow = &v13->m_Element;
  if ( r_shadowwireframe.m_pParent != nullptr && r_shadowwireframe.m_pParent->m_Value.m_nValue != 0 )
    pRenderContext->Bind(this: pRenderContext, a2: g_materialWorldWireframe, a3: nullptr);
  else
    pRenderContext->Bind(this: pRenderContext, a2: v13->m_Element.m_pMaterial, a3: v13->m_Element.m_pBindProxy);
  v14 = this->m_TempVertexCache.m_Size - 1;
  if ( v14 >= 0 )
  {
    v15 = v14;
    do
    {
      CShadowMgr::FreeVertices(this, cache: &this->m_TempVertexCache.m_Memory.m_pMemory[v15--]);
      --v14;
    }
    while ( v14 >= 0 );
    v13 = (UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *)shadow;
  }
  this->m_TempVertexCache.m_Size = 0;
  m_pMemory = this->m_DispShadowDecalCache.m_pMemory;
  info.m_pCache = this->m_ShadowDecalCache.m_pMemory;
  info.m_pDispCache = m_pMemory;
  info.m_pModelToWorld = pModelToWorld;
  if ( pModelToWorld != nullptr )
    MatrixInverseTR(src: pModelToWorld, dst: &info.m_WorldToModel);
  v17 = pRenderContext->GetMaxIndicesToRender(this: pRenderContext);
  GetMaxVerticesToRender = pRenderContext->GetMaxVerticesToRender;
  info.m_nMaxIndices = v17;
  info.m_nMaxVertices = GetMaxVerticesToRender(this: pRenderContext, a2: v13->m_Element.m_pMaterial);
  if ( r_threaded_shadow_clip.m_pParent != nullptr && r_threaded_shadow_clip.m_pParent->m_Value.m_nValue != 0 )
    CShadowMgr::GenerateShadowRenderInfoThreaded(this, pRenderContext, decalHandle, &info);
  else
    CShadowMgr::GenerateShadowRenderInfo(this, pRenderContext, decalHandle, &info);
  v19 = pRenderContext->GetDynamicMesh(this: pRenderContext, a2: 1, a3: 0, a4: 0, a5: 0);
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  CMeshBuilder::Begin(
    this: &meshBuilder,
    pMesh: v19,
    type: MATERIAL_TRIANGLES,
    nVertexCount: info.m_VertexCount,
    nIndexCount: info.m_IndexCount,
    pMeshSettings: nullptr);
  v20 = CShadowMgr::AddNormalShadowsToMeshBuilder(this, &meshBuilder, &info);
  CShadowMgr::AddDisplacementShadowsToMeshBuilder(this, &meshBuilder, &info, baseIndex: v20);
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
  v19->Draw_2(this: v19, a2: -1, a3: 0);
  if ( r_shadowids.m_pParent != nullptr && r_shadowids.m_pParent->m_Value.m_nValue != 0 )
    CShadowMgr::RenderDebuggingInfo(this, a2: COERCE_FLOAT(&savedregs), &info, func: DrawShadowID);
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

//------------------------------------------------------------------------------
// Address: 0x10113BB0
// Name: public: CShadowMgr::~CShadowMgr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::~CShadowMgr(CShadowMgr *this)
{
  CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int> >::BlockHeader_t *m_pBlocks; // edi
  CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int> >::BlockHeader_t *v3; // [esp-4h] [ebp-10h]

  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_ScissorStateEntryStart);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_ScissorStateBackups);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_bStack_SinglePassFlashlightStateEnabled);
  if ( this->m_DispShadowDecalCache.m_nGrowSize >= 0 )
  {
    if ( this->m_DispShadowDecalCache.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_DispShadowDecalCache.m_pMemory);
      this->m_DispShadowDecalCache.m_pMemory = nullptr;
    }
    this->m_DispShadowDecalCache.m_nAllocationCount = 0;
  }
  if ( this->m_ShadowDecalCache.m_nGrowSize >= 0 )
  {
    if ( this->m_ShadowDecalCache.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ShadowDecalCache.m_pMemory);
      this->m_ShadowDecalCache.m_pMemory = nullptr;
    }
    this->m_ShadowDecalCache.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::RemoveAll(this: &this->m_FlashlightStates);
  CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>::~CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>(this: (CUtlMemoryAligned<Frustum_t,16> *)&this->m_FlashlightStates);
  CUtlLinkedList<CShadowMgr::SurfaceBounds_t,unsigned short,0,int,CUtlMemoryFixed<UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short>,1024,16>>::RemoveAll(this: &this->m_SurfaceBoundsCache);
  CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::~CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>(this: &this->m_ShadowsOnModels);
  CUtlLinkedList<CShadowMgr::ShadowVertexLargeList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_LargeVertexList);
  if ( this->m_LargeVertexList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_LargeVertexList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_LargeVertexList.m_Memory.m_pMemory);
      this->m_LargeVertexList.m_Memory.m_pMemory = nullptr;
    }
    this->m_LargeVertexList.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CShadowMgr::ShadowVertexSmallList_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexSmallList_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_SmallVertexList);
  if ( this->m_SmallVertexList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SmallVertexList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SmallVertexList.m_Memory.m_pMemory);
      this->m_SmallVertexList.m_Memory.m_pMemory = nullptr;
    }
    this->m_SmallVertexList.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_TempVertexCache);
  CUtlLinkedList<CShadowMgr::ShadowVertexCache_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowVertexCache_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_VertexCache);
  if ( this->m_VertexCache.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_VertexCache.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_VertexCache.m_Memory.m_pMemory);
      this->m_VertexCache.m_Memory.m_pMemory = nullptr;
    }
    this->m_VertexCache.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CShadowMgr::SortOrderInfo_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::SortOrderInfo_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_SortOrderIds);
  if ( this->m_SortOrderIds.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_SortOrderIds.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SortOrderIds.m_Memory.m_pMemory);
      this->m_SortOrderIds.m_Memory.m_pMemory = nullptr;
    }
    this->m_SortOrderIds.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_RenderQueue);
  CUtlLinkedList<CSpatialEntry,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<CSpatialEntry,int>>>::RemoveAll(this: (CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > > *)&this->m_ShadowSurfaces);
  m_pBlocks = this->m_ShadowSurfaces.m_Memory.m_pBlocks;
  if ( m_pBlocks != nullptr )
  {
    do
    {
      v3 = m_pBlocks;
      m_pBlocks = m_pBlocks->m_pNext;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
    }
    while ( m_pBlocks != nullptr );
    this->m_ShadowSurfaces.m_Memory.m_pBlocks = nullptr;
    this->m_ShadowSurfaces.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int>>::RemoveAll(this: &this->m_ShadowDecals);
  if ( this->m_ShadowDecals.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ShadowDecals.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ShadowDecals.m_Memory.m_pMemory);
      this->m_ShadowDecals.m_Memory.m_pMemory = nullptr;
    }
    this->m_ShadowDecals.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<CShadowMgr::Shadow_t,unsigned short,0,int,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>>::RemoveAll(this: &this->m_Shadows);
  CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>::~CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>(this: (CUtlMemoryAligned<Frustum_t,16> *)&this->m_Shadows);
}

//------------------------------------------------------------------------------
// Address: 0x10113DD0
// Name: public: CShadowMgr::CShadowMgr(void)
// Source: json
//------------------------------------------------------------------------------
CShadowMgr *__thiscall CShadowMgr::CShadowMgr(CShadowMgr *this)
{
  UtlLinkedListElem_t<CShadowMgr::ShadowVertexLargeList_t,unsigned short> *m_pMemory; // edx
  UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short> *v3; // ecx
  int m_Size; // eax

  this->ISpatialLeafEnumerator::__vftable = (ISpatialLeafEnumerator_vtbl *)&ISpatialLeafEnumerator::`vftable';
  this->IShadowMgrInternal::IShadowMgr::__vftable = (CShadowMgr_vtbl *)&CShadowMgr::`vftable'{for `IShadowMgrInternal'};
  this->ISpatialLeafEnumerator::__vftable = (ISpatialLeafEnumerator_vtbl *)&CShadowMgr::`vftable'{for `ISpatialLeafEnumerator'};
  this->m_Shadows.m_Memory.m_pMemory = nullptr;
  this->m_Shadows.m_Memory.m_nAllocationCount = 0;
  this->m_Shadows.m_Memory.m_nGrowSize = 0;
  this->m_Shadows.m_LastAlloc.index = -1;
  this->m_Shadows.m_pElements = this->m_Shadows.m_Memory.m_pMemory;
  this->m_Shadows.m_ElementCount = 0;
  this->m_Shadows.m_NumAlloced = 0;
  this->m_Shadows.m_Head = 0xFFFF;
  this->m_Shadows.m_Tail = 0xFFFF;
  this->m_Shadows.m_FirstFree = 0xFFFF;
  this->m_ShadowDecals.m_Memory.m_pMemory = nullptr;
  this->m_ShadowDecals.m_Memory.m_nAllocationCount = 0;
  this->m_ShadowDecals.m_Memory.m_nGrowSize = 0;
  this->m_ShadowDecals.m_LastAlloc.index = -1;
  this->m_ShadowDecals.m_pElements = this->m_ShadowDecals.m_Memory.m_pMemory;
  this->m_ShadowDecals.m_Head = 0xFFFF;
  this->m_ShadowDecals.m_Tail = 0xFFFF;
  this->m_ShadowDecals.m_FirstFree = 0xFFFF;
  this->m_ShadowDecals.m_ElementCount = 0;
  this->m_ShadowDecals.m_NumAlloced = 0;
  this->m_ShadowSurfaces.m_Memory.m_pBlocks = nullptr;
  this->m_ShadowSurfaces.m_Memory.m_nAllocationCount = 0;
  this->m_ShadowSurfaces.m_Memory.m_nGrowSize = 0;
  this->m_ShadowSurfaces.m_LastAlloc.m_nIndex = -1;
  this->m_ShadowSurfaces.m_LastAlloc.m_pBlockHeader = nullptr;
  this->m_ShadowSurfaces.m_Head = 0;
  this->m_ShadowSurfaces.m_Tail = 0;
  this->m_ShadowSurfaces.m_FirstFree = 0;
  this->m_ShadowSurfaces.m_ElementCount = 0;
  this->m_ShadowSurfaces.m_NumAlloced = 0;
  this->m_ShadowSurfaces.m_pElements = nullptr;
  this->m_RenderQueue.m_Memory.m_pMemory = nullptr;
  this->m_RenderQueue.m_Memory.m_nAllocationCount = 0;
  this->m_RenderQueue.m_Memory.m_nGrowSize = 0;
  this->m_RenderQueue.m_Size = 0;
  this->m_RenderQueue.m_pElements = nullptr;
  this->m_SortOrderIds.m_Memory.m_pMemory = nullptr;
  this->m_SortOrderIds.m_Memory.m_nAllocationCount = 0;
  this->m_SortOrderIds.m_Memory.m_nGrowSize = 0;
  this->m_SortOrderIds.m_LastAlloc.index = -1;
  this->m_SortOrderIds.m_Tail = -1;
  *(_DWORD *)&this->m_SortOrderIds.m_ElementCount = 0;
  this->m_SortOrderIds.m_pElements = this->m_SortOrderIds.m_Memory.m_pMemory;
  this->m_SortOrderIds.m_Head = -1;
  this->m_SortOrderIds.m_FirstFree = -1;
  this->m_VertexCache.m_Memory.m_pMemory = nullptr;
  this->m_VertexCache.m_Memory.m_nAllocationCount = 0;
  this->m_VertexCache.m_Memory.m_nGrowSize = 0;
  this->m_VertexCache.m_LastAlloc.index = -1;
  this->m_VertexCache.m_Tail = -1;
  *(_DWORD *)&this->m_VertexCache.m_ElementCount = 0;
  this->m_VertexCache.m_pElements = this->m_VertexCache.m_Memory.m_pMemory;
  this->m_VertexCache.m_Head = -1;
  this->m_VertexCache.m_FirstFree = -1;
  this->m_TempVertexCache.m_Memory.m_pMemory = nullptr;
  this->m_TempVertexCache.m_Memory.m_nAllocationCount = 0;
  this->m_TempVertexCache.m_Memory.m_nGrowSize = 0;
  this->m_TempVertexCache.m_Size = 0;
  this->m_TempVertexCache.m_pElements = nullptr;
  this->m_SmallVertexList.m_Memory.m_pMemory = nullptr;
  this->m_SmallVertexList.m_Memory.m_nAllocationCount = 0;
  this->m_SmallVertexList.m_Memory.m_nGrowSize = 0;
  this->m_SmallVertexList.m_LastAlloc.index = -1;
  this->m_SmallVertexList.m_Tail = -1;
  *(_DWORD *)&this->m_SmallVertexList.m_ElementCount = 0;
  this->m_SmallVertexList.m_pElements = this->m_SmallVertexList.m_Memory.m_pMemory;
  this->m_SmallVertexList.m_Head = -1;
  this->m_SmallVertexList.m_FirstFree = -1;
  this->m_LargeVertexList.m_Memory.m_pMemory = nullptr;
  this->m_LargeVertexList.m_Memory.m_nAllocationCount = 0;
  this->m_LargeVertexList.m_Memory.m_nGrowSize = 0;
  this->m_LargeVertexList.m_LastAlloc.index = -1;
  this->m_LargeVertexList.m_Tail = -1;
  m_pMemory = this->m_LargeVertexList.m_Memory.m_pMemory;
  this->m_LargeVertexList.m_FirstFree = -1;
  this->m_LargeVertexList.m_Head = -1;
  *(_DWORD *)&this->m_LargeVertexList.m_ElementCount = 0;
  this->m_LargeVertexList.m_pElements = m_pMemory;
  CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>(this: &this->m_ShadowsOnModels);
  this->m_SurfaceBoundsCache.m_LastAlloc.index = -1;
  this->m_SurfaceBoundsCache.m_Head = 0xFFFF;
  this->m_SurfaceBoundsCache.m_Tail = 0xFFFF;
  this->m_SurfaceBoundsCache.m_FirstFree = 0xFFFF;
  this->m_SurfaceBoundsCache.m_ElementCount = 0;
  this->m_SurfaceBoundsCache.m_NumAlloced = 0;
  this->m_SurfaceBoundsCache.m_pElements = (UtlLinkedListElem_t<CShadowMgr::SurfaceBounds_t,unsigned short> *)((unsigned int)&this->m_SurfaceBoundsCache.m_Memory.m_Memory[15] & 0xFFFFFFF0);
  this->m_FlashlightStates.m_Memory.m_pMemory = nullptr;
  this->m_FlashlightStates.m_Memory.m_nAllocationCount = 0;
  this->m_FlashlightStates.m_Memory.m_nGrowSize = 0;
  this->m_FlashlightStates.m_LastAlloc.index = -1;
  this->m_FlashlightStates.m_FirstFree = -1;
  this->m_FlashlightStates.m_Tail = -1;
  this->m_FlashlightStates.m_pElements = this->m_FlashlightStates.m_Memory.m_pMemory;
  this->m_FlashlightStates.m_Head = -1;
  *(_DWORD *)&this->m_FlashlightStates.m_ElementCount = 0;
  this->m_ShadowDecalCache.m_pMemory = nullptr;
  this->m_ShadowDecalCache.m_nAllocationCount = 0;
  this->m_ShadowDecalCache.m_nGrowSize = 0;
  this->m_DispShadowDecalCache.m_pMemory = nullptr;
  this->m_DispShadowDecalCache.m_nAllocationCount = 0;
  this->m_DispShadowDecalCache.m_nGrowSize = 0;
  this->m_bStack_SinglePassFlashlightStateEnabled.m_Memory.m_pMemory = nullptr;
  this->m_bStack_SinglePassFlashlightStateEnabled.m_Memory.m_nAllocationCount = 0;
  this->m_bStack_SinglePassFlashlightStateEnabled.m_Memory.m_nGrowSize = 0;
  this->m_bStack_SinglePassFlashlightStateEnabled.m_Size = 0;
  this->m_bStack_SinglePassFlashlightStateEnabled.m_pElements = nullptr;
  this->m_ScissorStateBackups.m_Memory.m_pMemory = nullptr;
  this->m_ScissorStateBackups.m_Memory.m_nAllocationCount = 0;
  this->m_ScissorStateBackups.m_Memory.m_nGrowSize = 0;
  this->m_ScissorStateBackups.m_Size = 0;
  this->m_ScissorStateBackups.m_pElements = nullptr;
  this->m_ScissorStateEntryStart.m_Memory.m_pMemory = nullptr;
  this->m_ScissorStateEntryStart.m_Memory.m_nAllocationCount = 0;
  this->m_ScissorStateEntryStart.m_Memory.m_nGrowSize = 0;
  this->m_ScissorStateEntryStart.m_Size = 0;
  this->m_ScissorStateEntryStart.m_pElements = nullptr;
  this->m_bShadowsDisabled = false;
  CUtlLinkedList<unsigned short,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<unsigned short,int>>>::SetGrowSize(
    this: (CUtlLinkedList<decal_t *,int,1,int,CUtlFixedMemory<UtlLinkedListElem_t<decal_t *,int> > > *)&this->m_ShadowSurfaces,
    growSize: 4096);
  CUtlLinkedList<CShadowMgr::ShadowDecal_t,unsigned short,1,int,CUtlMemory<UtlLinkedListElem_t<CShadowMgr::ShadowDecal_t,unsigned short>,int>>::RemoveAll(this: &this->m_ShadowDecals);
  if ( this->m_ShadowDecals.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ShadowDecals.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ShadowDecals.m_Memory.m_pMemory);
      this->m_ShadowDecals.m_Memory.m_pMemory = nullptr;
    }
    this->m_ShadowDecals.m_Memory.m_nAllocationCount = 0;
  }
  v3 = this->m_ShadowDecals.m_Memory.m_pMemory;
  this->m_ShadowDecals.m_Memory.m_nGrowSize = 4096;
  this->m_ShadowDecals.m_Memory.m_nAllocationCount = 0;
  this->m_ShadowDecals.m_pElements = v3;
  this->m_ShadowsOnModels.m_FirstBucket = FirstModelInShadow;
  this->m_ShadowsOnModels.m_FirstElement = FirstShadowOnModel;
  m_Size = this->m_RenderQueue.m_Size;
  this->m_NumWorldMaterialBuckets = 0;
  this->m_pSurfaceBounds = nullptr;
  this->m_bInitialized = false;
  this->m_hSinglePassFlashlightState = -1;
  this->m_bSinglePassFlashlightStateEnabled = false;
  this->m_nSkipShadowForEntIndex = 0x80000000;
  if ( m_Size > 0 )
    memset(dst: (unsigned __int8 *)this->m_RenderQueue.m_Memory.m_pMemory, value: 0xFFu, count: 2 * m_Size);
  this->m_DecalsToRender = 0;
  CShadowMgr::ClearAllFlashlightMaterialBuckets(this);
  this->m_ShadowDecalCache.m_nGrowSize = 4096;
  this->m_DispShadowDecalCache.m_nGrowSize = 4096;
  CUtlMemory<INetMessage *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&this->m_ShadowDecalCache, num: 0x4000);
  CUtlMemory<wchar_t,int>::Grow(this: (CUtlMemory<wchar_t,int> *)&this->m_DispShadowDecalCache, num: 0x4000);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101141B0
// Name: public: virtual unsigned short CShadowMgr::CreateShadowEx(class IMaterial __near *,class IMaterial __near *,void __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CShadowMgr::CreateShadowEx(
        CShadowMgr *this,
        IMaterial *pMaterial,
        IMaterial *pModelMaterial,
        void *pBindProxy,
        __int16 creationFlags,
        int nEntIndex)
{
  CUtlLinkedList<CShadowMgr::Shadow_t,unsigned short,0,int,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16> > *p_m_Shadows; // edi
  int v7; // eax
  int v8; // ebx
  int v9; // eax
  int v11; // esi
  unsigned __int16 v12; // ax

  p_m_Shadows = &this->m_Shadows;
  v7 = CUtlLinkedList<CShadowMgr::Shadow_t,unsigned short,0,int,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>>::AllocInternal(
         this: &this->m_Shadows,
         multilist: false);
  v8 = v7;
  if ( v7 == 0xFFFF )
    goto LABEL_5;
  CUtlLinkedList<CShadowMgr::Shadow_t,unsigned short,0,int,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>>::LinkBefore(
    this: p_m_Shadows,
    before: 0xFFFF,
    elem: v7);
  v9 = (int)&p_m_Shadows->m_Memory.m_pMemory[v8];
  if ( v9 != 0 )
    *(_DWORD *)(v9 + 192) = 0;
  if ( (_WORD)v8 == 0xFFFF )
  {
LABEL_5:
    if ( _executeCount_1 < 10 )
    {
      ++_executeCount_1;
      _Warning(a1: "CShadowMgr::CreateShadowEx - overflowed m_Shadows linked list!\n");
    }
    return -1;
  }
  else
  {
    v11 = (int)&p_m_Shadows->m_Memory.m_pMemory[(unsigned __int16)v8];
    CShadowMgr::SetMaterial(this, shadow: (CShadowMgr::Shadow_t *)v11, pMaterial, pModelMaterial, pBindProxy);
    *(_WORD *)(v11 + 120) = creationFlags;
    *(_DWORD *)(v11 + 296) = 0;
    *(_WORD *)(v11 + 300) = -1;
    *(_DWORD *)(v11 + 96) = 0;
    *(_DWORD *)(v11 + 100) = 0;
    *(_DWORD *)(v11 + 104) = 1065353216;
    *(_DWORD *)(v11 + 76) = 0;
    *(_DWORD *)(v11 + 80) = 0;
    *(_DWORD *)(v11 + 84) = 1065353216;
    *(_DWORD *)(v11 + 88) = 1065353216;
    *(_WORD *)(v11 + 228) = 0;
    *(_BYTE *)(v11 + 92) = 0;
    *(_DWORD *)(v11 + 224) = 0;
    *(_WORD *)(v11 + 220) = -1;
    *(_DWORD *)(v11 + 304) = nEntIndex;
    if ( (creationFlags & 6) != 0 )
    {
      v12 = CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::InsertBefore(
              this: &this->m_FlashlightStates,
              before: 0xFFFFu);
      *(_WORD *)(v11 + 220) = v12;
      this->m_FlashlightStates.m_Memory.m_pMemory[v12].m_Element.m_Shadow = v8;
      this->m_FlashlightStates.m_Memory.m_pMemory[*(unsigned __int16 *)(v11 + 220)].m_Element.m_nSplitscreenOwner = 0;
      if ( !this->m_bSinglePassFlashlightStateEnabled )
        CShadowMgr::AllocFlashlightMaterialBuckets(this, flashlightID: *(_WORD *)(v11 + 220));
    }
    MatrixSetIdentity(dst: (VMatrix *)v11);
    return v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10114340
// Name: public: virtual void CShadowMgr::DestroyShadow(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::DestroyShadow(CShadowMgr *this, int handle)
{
  unsigned int v2; // ebx
  CUtlLinkedList<CShadowMgr::Shadow_t,unsigned short,0,int,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16> > *p_m_Shadows; // edi
  unsigned __int16 m_FlashlightHandle; // ax
  CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16> > *p_m_FlashlightStates; // edi
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *v7; // esi
  int elem; // [esp+Ch] [ebp-8h]
  CUtlLinkedList<CShadowMgr::Shadow_t,unsigned short,0,int,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16> > *v9; // [esp+10h] [ebp-4h]
  unsigned __int16 handlea; // [esp+1Ch] [ebp+8h]

  elem = (unsigned __int16)handle;
  v2 = (unsigned __int16)handle;
  p_m_Shadows = &this->m_Shadows;
  v9 = &this->m_Shadows;
  CShadowMgr::CleanupMaterial(this, shadow: &this->m_Shadows.m_Memory.m_pMemory[v2].m_Element);
  CShadowMgr::RemoveAllSurfacesFromShadow(this, handle);
  CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::RemoveElement(
    this: &this->m_ShadowsOnModels,
    element: handle);
  m_FlashlightHandle = p_m_Shadows->m_Memory.m_pMemory[v2].m_Element.m_FlashlightHandle;
  if ( m_FlashlightHandle != 0xFFFF )
  {
    p_m_FlashlightStates = &this->m_FlashlightStates;
    handlea = m_FlashlightHandle;
    CUtlLinkedList<CShadowMgr::FlashlightInfo_t,unsigned short,0,unsigned short,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short>,16>>::Unlink(
      this: &this->m_FlashlightStates,
      elem: m_FlashlightHandle);
    v7 = &this->m_FlashlightStates.m_Memory.m_pMemory[handlea];
    CMaterialsBuckets<msurface2_t *>::~CMaterialsBuckets<msurface2_t *>(this: &v7->m_Element.m_OccluderBuckets);
    CMaterialsBuckets<msurface2_t *>::~CMaterialsBuckets<msurface2_t *>(this: &v7->m_Element.m_MaterialBuckets);
    v7->m_Next = p_m_FlashlightStates->m_FirstFree;
    p_m_FlashlightStates->m_FirstFree = handlea;
    p_m_Shadows = v9;
  }
  CUtlLinkedList<CShadowMgr::Shadow_t,unsigned short,0,int,CUtlMemoryAligned<UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short>,16>>::Unlink(
    this: p_m_Shadows,
    elem);
  p_m_Shadows->m_Memory.m_pMemory[v2].m_Next = p_m_Shadows->m_FirstFree;
  p_m_Shadows->m_FirstFree = elem;
}

//------------------------------------------------------------------------------
// Address: 0x10114410
// Name: public: virtual void CShadowMgr::ProjectShadow(unsigned short,class Vector const __near &,class Vector const __near &,class VMatrix const __near &,class Vector2D const __near &,int,int const __near *,float,float,float,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::ProjectShadow(
        CShadowMgr *this,
        int handle,
        const Vector *origin,
        const Vector *projectionDir,
        const VMatrix *worldToShadow,
        const Vector2D *size,
        int nLeafCount,
        const int *pLeafList,
        float maxHeight,
        float falloffOffset,
        float falloffAmount,
        const Vector *vecCasterOrigin)
{
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v13; // esi
  double v14; // st6
  double y; // st5
  float v16; // xmm1_4
  float v17; // xmm0_4
  int v18; // esi
  CShadowMgr *v19; // ebx
  CShadowMgr::ShadowBuildInfo_t build; // [esp+8h] [ebp-58h] BYREF
  Vector vecEndPoint; // [esp+38h] [ebp-28h] BYREF
  Vector vecMins; // [esp+44h] [ebp-1Ch] BYREF
  Vector vecMaxs; // [esp+50h] [ebp-10h] BYREF
  CShadowMgr *v24; // [esp+5Ch] [ebp-4h]
  float flRadius; // [esp+88h] [ebp+28h]

  v24 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CShadowMgr::ProjectShadow",
    a3: 0,
    a4: "Shadow_Rendering",
    a5: false,
    a6: 4);
  CShadowMgr::RemoveAllSurfacesFromShadow(this, handle);
  CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::RemoveElement(
    this: &this->m_ShadowsOnModels,
    element: handle);
  v13 = &this->m_Shadows.m_Memory.m_pMemory[(unsigned __int16)handle];
  if ( (v13->m_Element.m_Flags & 8) != 0
    || r_shadows.m_pParent == nullptr
    || r_shadows.m_pParent->m_Value.m_nValue == 0
    || this->m_bShadowsDisabled )
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    v13->m_Element.m_FalloffOffset = falloffOffset;
    v13->m_Element.m_ProjectionDir = *projectionDir;
    v13->m_Element.m_MaxDist = maxHeight;
    v13->m_Element.m_FalloffAmount = falloffAmount;
    MatrixCopy(src: worldToShadow, dst: &v13->m_Element.m_WorldToShadow);
    v14 = size->x * size->x;
    y = size->y;
    v13->m_Element.m_vecSphereCenter.x = (float)((float)(maxHeight * 0.5) * projectionDir->x) + origin->x;
    v13->m_Element.m_vecSphereCenter.y = (float)(projectionDir->y * (float)(maxHeight * 0.5)) + origin->y;
    v13->m_Element.m_vecSphereCenter.z = (float)((float)(maxHeight * 0.5) * projectionDir->z) + origin->z;
    flRadius = sqrt(y * y + v14) * 0.5;
    vecMaxs.x = flRadius;
    v13->m_Element.m_flSphereRadius = (float)(maxHeight * 0.5) + flRadius;
    LODWORD(vecMins.x) = LODWORD(flRadius) ^ _mask__NegFloat_;
    LODWORD(vecMins.y) = LODWORD(flRadius) ^ _mask__NegFloat_;
    LODWORD(vecMins.z) = LODWORD(flRadius) ^ _mask__NegFloat_;
    vecEndPoint.x = (float)(projectionDir->x * maxHeight) + origin->x;
    v16 = (float)(projectionDir->y * maxHeight) + origin->y;
    v17 = (float)(maxHeight * projectionDir->z) + origin->z;
    vecMaxs.y = flRadius;
    vecMaxs.z = flRadius;
    vecEndPoint.y = v16;
    vecEndPoint.z = v17;
    Ray_t::Init(this: &v13->m_Element.m_Ray, start: origin, end: &vecEndPoint, mins: &vecMins, maxs: &vecMaxs);
    if ( nLeafCount != 0 )
    {
      ++r_surfacevisframe;
      DispInfo_ClearAllTags(hArray: host_state.worldbrush->hDispInfos);
      build.m_RayStart = *origin;
      build.m_Shadow = handle;
      build.m_pVis = nullptr;
      build.m_vecSphereCenter = v13->m_Element.m_vecSphereCenter;
      build.m_flSphereRadius = v13->m_Element.m_flSphereRadius;
      build.m_ProjectionDirection = *projectionDir;
      v18 = 0;
      if ( nLeafCount > 0 )
      {
        v19 = v24;
        do
          CShadowMgr::EnumerateLeaf(
            this: (CShadowMgr *)&v19->ISpatialLeafEnumerator,
            leaf: pLeafList[v18++],
            context: &build);
        while ( v18 < nLeafCount );
      }
    }
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10114690
// Name: public: virtual void CShadowMgr::ProjectFlashlight(unsigned short,class VMatrix const __near &,int,int const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::ProjectFlashlight(
        CShadowMgr *this,
        int handle,
        const VMatrix *worldToShadow,
        int nLeafCount,
        const int *pLeafList)
{
  IMatRenderContext *m_pObject; // ebx
  UtlLinkedListElem_t<CShadowMgr::Shadow_t,unsigned short> *v7; // esi
  bool v8; // zf
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *m_pMemory; // eax
  int m_FlashlightHandle; // edx
  CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short> > *p_m_UsedSortIDs; // ebx
  Vector *p_m_vecSphereCenter; // ebx
  UtlLinkedListElem_t<CShadowMgr::FlashlightInfo_t,unsigned short> *v13; // edx
  int v14; // esi
  IMatRenderContext *v15; // esi
  VMatrix shadowToWorld; // [esp+Ch] [ebp-78h] BYREF
  CShadowMgr::ShadowBuildInfo_t build; // [esp+4Ch] [ebp-38h] BYREF
  unsigned int v18; // [esp+7Ch] [ebp-8h]
  CMatRenderContextPtr pRenderContext; // [esp+80h] [ebp-4h]
  const VMatrix *worldToShadowa; // [esp+90h] [ebp+Ch]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CShadowMgr::ProjectFlashlight",
    a3: 0,
    a4: "Flashlight Shadows",
    a5: false,
    a6: 4);
  m_pObject = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = m_pObject;
  if ( m_pObject != nullptr )
    m_pObject->BeginRender(this: m_pObject);
  v7 = &this->m_Shadows.m_Memory.m_pMemory[(unsigned __int16)handle];
  v8 = !this->m_bSinglePassFlashlightStateEnabled;
  v18 = 336 * (unsigned __int16)handle;
  if ( v8 || m_pObject->IsCullingEnabledForSinglePassFlashlight(this: m_pObject) )
  {
    CShadowMgr::RemoveAllSurfacesFromShadow(this, handle);
    CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::RemoveElement(
      this: &this->m_ShadowsOnModels,
      element: handle);
    m_pMemory = this->m_FlashlightStates.m_Memory.m_pMemory;
    m_FlashlightHandle = v7->m_Element.m_FlashlightHandle;
    ++m_pMemory[m_FlashlightHandle].m_Element.m_OccluderBuckets.m_FlushCount;
    p_m_UsedSortIDs = &m_pMemory[m_FlashlightHandle].m_Element.m_OccluderBuckets.m_UsedSortIDs;
    CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::BucketListInfo_t,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short,1,unsigned short,CUtlMemory<UtlLinkedListElem_t<CBidirectionalSet<unsigned short,unsigned short,unsigned short,unsigned short>::ElementListInfo_t,unsigned short>,unsigned short> > *)&m_pMemory[m_FlashlightHandle].m_Element.m_OccluderBuckets.m_Elements);
    CUtlLinkedList<unsigned short,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<unsigned short,unsigned short>,unsigned short>>::RemoveAll(this: p_m_UsedSortIDs);
    m_pObject = pRenderContext.m_pObject;
  }
  if ( (this->m_Shadows.m_Memory.m_pMemory[v18 / 0x150].m_Element.m_Flags & 8) == 0
    && r_shadows.m_pParent != nullptr
    && r_shadows.m_pParent->m_Value.m_nValue != 0 )
  {
    MatrixCopy(src: worldToShadow, dst: &v7->m_Element.m_WorldToShadow);
    MatrixInverseGeneral(src: &v7->m_Element.m_WorldToShadow, dst: &shadowToWorld);
    FrustumPlanesFromMatrix(
      clipToWorld: &shadowToWorld,
      frustum: &this->m_FlashlightStates.m_Memory.m_pMemory[v7->m_Element.m_FlashlightHandle].m_Element.m_Frustum);
    p_m_vecSphereCenter = &v7->m_Element.m_vecSphereCenter;
    worldToShadowa = (const VMatrix *)&v7->m_Element.m_flSphereRadius;
    CalculateSphereFromProjectionMatrixInverse(
      volumeToWorld: &shadowToWorld,
      pCenter: &v7->m_Element.m_vecSphereCenter,
      pflRadius: &v7->m_Element.m_flSphereRadius);
    if ( nLeafCount != 0 && !this->m_bSinglePassFlashlightStateEnabled )
    {
      ++r_surfacevisframe;
      DispInfo_ClearAllTags(hArray: host_state.worldbrush->hDispInfos);
      v13 = this->m_FlashlightStates.m_Memory.m_pMemory;
      build.m_Shadow = handle;
      build.m_RayStart = v13[v7->m_Element.m_FlashlightHandle].m_Element.m_FlashlightState.m_vecLightOrigin;
      v14 = 0;
      build.m_pVis = nullptr;
      build.m_vecSphereCenter = *p_m_vecSphereCenter;
      for ( build.m_flSphereRadius = worldToShadowa->m[0][0]; v14 < nLeafCount; ++v14 )
        CShadowMgr::EnumerateLeaf(
          this: (CShadowMgr *)&this->ISpatialLeafEnumerator,
          leaf: pLeafList[v14],
          context: &build);
    }
    v15 = pRenderContext.m_pObject;
    if ( pRenderContext.m_pObject != nullptr )
    {
      pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
      v15->Release(this: v15);
    }
  }
  else if ( m_pObject != nullptr )
  {
    m_pObject->EndRender(this: m_pObject);
    m_pObject->Release(this: m_pObject);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x101148D0
// Name: private: virtual void CShadowMgr::RenderShadows(class IMatRenderContext __near *,class VMatrix const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowMgr::RenderShadows(
        CShadowMgr *this,
        IMatRenderContext *pRenderContext,
        const VMatrix *pModelToWorld)
{
  int i; // edi
  unsigned __int16 v5; // ax

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CShadowMgr::RenderShadows",
    a3: 0,
    a4: "Shadow_Rendering",
    a5: false,
    a6: 4);
  for ( i = 0; i < this->m_RenderQueue.m_Size; ++i )
  {
    v5 = this->m_RenderQueue.m_Memory.m_pMemory[i];
    if ( v5 != 0xFFFF )
      CShadowMgr::RenderShadowList(this, pRenderContext, decalHandle: v5, pModelToWorld);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10261A40
// Name: public: int CUtlStack<float,class CUtlMemory<float,int>>::Push(float const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlStack<float,CUtlMemory<float,int>>::Push(CUtlStack<float,CUtlMemory<float,int> > *this, float *src)
{
  float *m_pMemory; // eax
  int m_Size; // ecx
  float *v5; // eax

  if ( this->m_Size >= this->m_Memory.m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  m_Size = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v5 = &m_pMemory[m_Size - 1];
  if ( v5 != nullptr )
    *v5 = *src;
  return this->m_Size - 1;
}

//------------------------------------------------------------------------------
// Address: 0x10106F70
// Name: __CreateCShadowMgrIShadowMgr_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CShadowMgr *__cdecl _CreateCShadowMgrIShadowMgr_interface()
{
  return &s_ShadowMgr;
}

} // namespace engine_xlsp
