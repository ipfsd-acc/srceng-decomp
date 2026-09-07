// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/viewrender.cpp
// Functions: 176
// ============================================================

#include "game\client\viewrender.h"

//------------------------------------------------------------------------------
// Address: 0x1019A930
// Name: testfreezeframe_f
// Source: json
//------------------------------------------------------------------------------
void __cdecl testfreezeframe_f()
{
  ((void (__stdcall *)(int))view->FreezeFrame)(a1: 1077936128);
}

//------------------------------------------------------------------------------
// Address: 0x1019A950
// Name: struct FrustumCache_t __near * FrustumCache(void)
// Source: json
//------------------------------------------------------------------------------
FrustumCache_t *__cdecl FrustumCache()
{
  return &s_FrustumCache;
}

//------------------------------------------------------------------------------
// Address: 0x1019A960
// Name: public: bool CWorldListCache::CEntryComparator::operator()(struct CWorldListCache::Entry_t const __near *,struct CWorldListCache::Entry_t const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWorldListCache::CEntryComparator::operator()(
        CWorldListCache::CEntryComparator *this,
        const CWorldListCache::Entry_t *lhs,
        const CWorldListCache::Entry_t *rhs)
{
  unsigned int v5; // eax
  int v7; // eax

  v5 = 176;
  while ( lhs->m_iForceViewLeaf == rhs->m_iForceViewLeaf )
  {
    v5 -= 4;
    rhs = (const CWorldListCache::Entry_t *)((char *)rhs + 4);
    lhs = (const CWorldListCache::Entry_t *)((char *)lhs + 4);
    if ( v5 < 4 )
      return false;
  }
  v7 = LOBYTE(lhs->m_iForceViewLeaf) - LOBYTE(rhs->m_iForceViewLeaf);
  if ( v7 == 0 )
  {
    v7 = BYTE1(lhs->m_iForceViewLeaf) - BYTE1(rhs->m_iForceViewLeaf);
    if ( v7 == 0 )
    {
      v7 = BYTE2(lhs->m_iForceViewLeaf) - BYTE2(rhs->m_iForceViewLeaf);
      if ( v7 == 0 )
        v7 = HIBYTE(lhs->m_iForceViewLeaf) - HIBYTE(rhs->m_iForceViewLeaf);
    }
  }
  return v7 >> 31 < 0;
}

//------------------------------------------------------------------------------
// Address: 0x1019A9D0
// Name: BuildEngineDrawWorldListFlags
// Source: json
//------------------------------------------------------------------------------
unsigned int __fastcall BuildEngineDrawWorldListFlags(unsigned int nDrawFlags)
{
  unsigned int result; // eax

  result = 0;
  if ( (nDrawFlags & 0x4000) == 0 )
    result = 512;
  if ( (nDrawFlags & 0x8000) == 0 )
    result |= 0x400u;
  if ( (nDrawFlags & 0x800) != 0 )
    result |= 0x10u;
  if ( (nDrawFlags & 0x20) != 0 )
    result |= 5u;
  if ( (nDrawFlags & 0x10) != 0 )
    result |= 6u;
  if ( (nDrawFlags & 0x40) != 0 )
    result |= 8u;
  if ( (nDrawFlags & 0x40000) != 0 )
    result |= 0x20u;
  if ( (nDrawFlags & 0x100000) != 0 )
    result = result & 0xFFFFFBBF | 0x40;
  if ( (nDrawFlags & 1) != 0 )
    result |= 0x80u;
  if ( (nDrawFlags & 2) != 0 )
    result |= 0x100u;
  if ( (nDrawFlags & 0x480000) != 0 )
  {
    result &= 0xFFFFF9FF;
    if ( (nDrawFlags & 0x80000) != 0 )
      result |= 0x800u;
    if ( (nDrawFlags & 0x400000) != 0 )
      result |= 0x1000u;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019AA70
// Name: public: virtual void PrecachePostProcessingEffectsPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PrecachePostProcessingEffectsPrecache::CResourcePrecacher::Cache(
        PrecachePostProcessingEffectsPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "dev/blurfiltery_and_add_nohdr",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "dev/blurfilterx",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "dev/blurfilterx_nohdr",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "dev/blurfiltery",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "dev/blurfiltery_nohdr",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "dev/blurfiltery_nohdr_clear",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "dev/bloomadd",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "dev/downsample",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "dev/downsample_non_hdr",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "dev/no_pixel_write",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "dev/lumcompare",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "dev/floattoscreen_combine",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "dev/copyfullframefb_vanilla",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "dev/copyfullframefb",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "dev/engine_post",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "dev/engine_post_splitscreen",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "dev/motion_blur",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "dev/depth_of_field",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "dev/blurgaussian_3x3",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: MATERIAL,
    a3: "dev/fade_blur",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1019AC10
// Name: class Vector const __near & CurrentViewOrigin(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__cdecl CurrentViewOrigin()
{
  return &g_vecCurrentRenderOrigin;
}

//------------------------------------------------------------------------------
// Address: 0x1019AC20
// Name: class QAngle const __near & CurrentViewAngles(void)
// Source: json
//------------------------------------------------------------------------------
const QAngle *__cdecl CurrentViewAngles()
{
  return &g_vecCurrentRenderAngles;
}

//------------------------------------------------------------------------------
// Address: 0x1019AC30
// Name: class Vector const __near & CurrentViewForward(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__cdecl CurrentViewForward()
{
  return &g_vecCurrentVForward;
}

//------------------------------------------------------------------------------
// Address: 0x1019AC40
// Name: class Vector const __near & CurrentViewRight(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__cdecl CurrentViewRight()
{
  return &g_vecCurrentVRight;
}

//------------------------------------------------------------------------------
// Address: 0x1019AC50
// Name: class Vector const __near & CurrentViewUp(void)
// Source: json
//------------------------------------------------------------------------------
const Vector *__cdecl CurrentViewUp()
{
  return &g_vecCurrentVUp;
}

//------------------------------------------------------------------------------
// Address: 0x1019AC60
// Name: void AllowCurrentViewAccess(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AllowCurrentViewAccess(bool allow)
{
  s_bCanAccessCurrentView = allow;
}

//------------------------------------------------------------------------------
// Address: 0x1019AC70
// Name: bool IsCurrentViewAccessAllowed(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsCurrentViewAccessAllowed()
{
  return s_bCanAccessCurrentView;
}

//------------------------------------------------------------------------------
// Address: 0x1019AC80
// Name: enum view_id_t CurrentViewID(void)
// Source: json
//------------------------------------------------------------------------------
view_id_t __cdecl CurrentViewID()
{
  return g_CurrentViewID;
}

//------------------------------------------------------------------------------
// Address: 0x1019AC90
// Name: bool IsMainView(enum view_id_t)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsMainView(view_id_t id)
{
  return id == VIEW_MAIN;
}

//------------------------------------------------------------------------------
// Address: 0x1019ACA0
// Name: public: virtual void CSimpleRenderExecutor::AddView(class CRendering3dView __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleRenderExecutor::AddView(CSimpleRenderExecutor *this, CRendering3dView *pView)
{
  CViewRender *m_pMainView; // eax
  CBase3dView *m_pActiveRenderer; // edi

  m_pMainView = this->m_pMainView;
  m_pActiveRenderer = m_pMainView->m_pActiveRenderer;
  m_pMainView->m_pActiveRenderer = pView;
  pView->Draw(this: pView);
  this->m_pMainView->m_pActiveRenderer = m_pActiveRenderer;
}

//------------------------------------------------------------------------------
// Address: 0x1019ACD0
// Name: protected: virtual void CViewRender::SetScreenOverlayMaterial(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRender::SetScreenOverlayMaterial(CViewRender *this, IMaterial *pMaterial)
{
  CMaterialReference::Init(this: &this->m_ScreenOverlayMaterial, pMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x1019ACE0
// Name: public: virtual void CViewRender::InitFadeData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRender::InitFadeData(CViewRender *this)
{
  CPULevel_t ActualCPULevel; // eax
  __int64 v3; // xmm0_8
  FadeData_t *v4; // eax

  ActualCPULevel = GetActualCPULevel();
  v3 = *(_QWORD *)&g_aFadeData[ActualCPULevel + 1].m_flPercentMin;
  v4 = &g_aFadeData[ActualCPULevel + 1];
  *(_QWORD *)&this->m_FadeData.m_flPercentMin = v3;
  *(_QWORD *)&this->m_FadeData.m_flPixelMin = *(_QWORD *)&v4->m_flPixelMin;
  this->m_FadeData.m_flWidth = v4->m_flWidth;
}

//------------------------------------------------------------------------------
// Address: 0x1019AD20
// Name: public: virtual class C_BaseEntity __near * CViewRender::GetCurrentlyDrawingEntity(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__thiscall CViewRender::GetCurrentlyDrawingEntity(CViewRender *this)
{
  return this->m_pCurrentlyDrawingEntity;
}

//------------------------------------------------------------------------------
// Address: 0x1019AD30
// Name: public: virtual void CViewRender::SetCurrentlyDrawingEntity(class C_BaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRender::SetCurrentlyDrawingEntity(CViewRender *this, C_BaseEntity *pEnt)
{
  this->m_pCurrentlyDrawingEntity = pEnt;
}

//------------------------------------------------------------------------------
// Address: 0x1019AD40
// Name: public: void CViewRender::SetupVis(class CViewSetup const __near &,unsigned int __near &,struct ViewCustomVisibility_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRender::SetupVis(
        CViewRender *this,
        const CViewSetup *view,
        unsigned int *visFlags,
        ViewCustomVisibility_t *pCustomVisibility)
{
  IVRenderView_vtbl *v4; // esi
  unsigned __int8 v5; // al
  IVRenderView_vtbl *v6; // esi
  unsigned __int8 v7; // al

  if ( pCustomVisibility != nullptr && pCustomVisibility->m_nNumVisOrigins != 0 )
  {
    v4 = render->__vftable;
    v5 = ((int (__thiscall *)(CViewRender *, int, Vector *, unsigned int *))this->ShouldForceNoVis)(
           a1: this,
           a2: pCustomVisibility->m_nNumVisOrigins,
           a3: pCustomVisibility->m_rgVisOrigins,
           a4: visFlags);
    ((void (__thiscall *)(IVRenderView *, _DWORD))v4->ViewSetupVisEx)(a1: render, a2: v5);
  }
  else
  {
    v6 = render->__vftable;
    v7 = ((int (__thiscall *)(CViewRender *, int, Vector *, unsigned int *))this->ShouldForceNoVis)(
           a1: this,
           a2: 1,
           a3: &view->origin,
           a4: visFlags);
    ((void (__thiscall *)(IVRenderView *, _DWORD))v6->ViewSetupVisEx)(a1: render, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019ADC0
// Name: public: virtual void CViewRender::RenderPlayerSprites(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRender::RenderPlayerSprites(CViewRender *this)
{
  CVoiceStatus *ClientVoiceMgr; // eax

  ClientVoiceMgr = GetClientVoiceMgr();
  CVoiceStatus::DrawHeadLabels(this: ClientVoiceMgr);
}

//------------------------------------------------------------------------------
// Address: 0x1019ADD0
// Name: public: virtual void CViewRender::FreezeFrame(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRender::FreezeFrame(CViewRender *this, float flFreezeTime)
{
  float m_flFreezeFrameUntil; // xmm0_4
  float v3; // xmm1_4

  if ( flFreezeTime == 0.0 )
  {
    this->m_FreezeParams[0].m_flFreezeFrameUntil = 0.0;
    this->m_FreezeParams[0].m_bTakeFreezeFrame = false;
  }
  else
  {
    m_flFreezeFrameUntil = this->m_FreezeParams[0].m_flFreezeFrameUntil;
    v3 = *(float *)(gpGlobals.m_Index + 12);
    if ( m_flFreezeFrameUntil <= v3 )
    {
      this->m_FreezeParams[0].m_flFreezeFrameUntil = v3 + flFreezeTime;
      this->m_FreezeParams[0].m_bTakeFreezeFrame = true;
    }
    else
    {
      this->m_FreezeParams[0].m_flFreezeFrameUntil = m_flFreezeFrameUntil + flFreezeTime;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019AE40
// Name: public: virtual void CViewRender::SetCheapWaterStartDistance(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRender::SetCheapWaterStartDistance(CViewRender *this, float flCheapWaterStartDistance)
{
  this->m_flCheapWaterStartDistance = flCheapWaterStartDistance;
}

//------------------------------------------------------------------------------
// Address: 0x1019AE60
// Name: public: virtual void CViewRender::SetCheapWaterEndDistance(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRender::SetCheapWaterEndDistance(CViewRender *this, float flCheapWaterEndDistance)
{
  this->m_flCheapWaterEndDistance = flCheapWaterEndDistance;
}

//------------------------------------------------------------------------------
// Address: 0x1019AE80
// Name: public: virtual void CViewRender::GetWaterLODParams(float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRender::GetWaterLODParams(
        CViewRender *this,
        float *flCheapWaterStartDistance,
        float *flCheapWaterEndDistance)
{
  *flCheapWaterStartDistance = this->m_flCheapWaterStartDistance;
  *flCheapWaterEndDistance = this->m_flCheapWaterEndDistance;
}

//------------------------------------------------------------------------------
// Address: 0x1019AEA0
// Name: public: virtual int CRendering3dView::GetDrawFlags(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRendering3dView::GetDrawFlags(CRendering3dView *this)
{
  return this->m_DrawFlags;
}

//------------------------------------------------------------------------------
// Address: 0x1019AEB0
// Name: protected: virtual enum SkyboxVisibility_t CSkyboxView::ComputeSkyboxVisibility(void)
// Source: json
//------------------------------------------------------------------------------
SkyboxVisibility_t __thiscall CSkyboxView::ComputeSkyboxVisibility(CSkyboxView *this)
{
  return engine->IsSkyboxVisibleFromPoint(this: engine, a2: &this->origin);
}

//------------------------------------------------------------------------------
// Address: 0x1019AED0
// Name: public: virtual bool CReflectiveGlassView::AdjustView(float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CReflectiveGlassView::AdjustView(CReflectiveGlassView *this, float flWaterHeight)
{
  ITexture *WaterReflectionTexture; // edi
  float x; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  Vector vecForward; // [esp+8h] [ebp-18h] BYREF
  Vector vecUp; // [esp+14h] [ebp-Ch] BYREF

  WaterReflectionTexture = GetWaterReflectionTexture();
  this->y = 0;
  this->x = 0;
  this->width = WaterReflectionTexture->GetActualWidth(this: WaterReflectionTexture);
  this->height = WaterReflectionTexture->GetActualHeight(this: WaterReflectionTexture);
  x = this->m_ReflectionPlane.normal.x;
  v5 = (float)((float)((float)((float)(this->origin.CSimpleWorldView::CBaseWorldView::CRendering3dView::CBase3dView::CViewSetup::x
                                     * x)
                             + (float)(this->m_ReflectionPlane.normal.y * this->origin.y))
                     + (float)(this->m_ReflectionPlane.normal.z * this->origin.z))
             - this->m_ReflectionPlane.dist)
     * -2.0;
  this->origin.CSimpleWorldView::CBaseWorldView::CRendering3dView::CBase3dView::CViewSetup::x = (float)(x * v5)
                                                                                              + this->origin.CSimpleWorldView::CBaseWorldView::CRendering3dView::CBase3dView::CViewSetup::x;
  this->origin.y = (float)(this->m_ReflectionPlane.normal.y * v5) + this->origin.y;
  this->origin.z = (float)(this->m_ReflectionPlane.normal.z * v5) + this->origin.z;
  AngleVectors(angles: &this->angles, forward: &vecForward, right: nullptr, up: &vecUp);
  v6 = this->m_ReflectionPlane.normal.x;
  y = this->m_ReflectionPlane.normal.y;
  z = this->m_ReflectionPlane.normal.z;
  v9 = (float)((float)((float)(y * vecForward.y) + (float)(v6 * vecForward.x)) + (float)(z * vecForward.z)) * -2.0;
  vecForward.x = (float)(v6 * v9) + vecForward.x;
  vecForward.y = (float)(y * v9) + vecForward.y;
  vecForward.z = (float)(z * v9) + vecForward.z;
  v10 = (float)((float)((float)(y * vecUp.y) + (float)(v6 * vecUp.x)) + (float)(z * vecUp.z)) * -2.0;
  vecUp.x = (float)(v6 * v10) + vecUp.x;
  vecUp.y = (float)(y * v10) + vecUp.y;
  vecUp.z = (float)(z * v10) + vecUp.z;
  VectorAngles(forward: &vecForward, pseudoup: &vecUp, angles: &this->angles);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1019B090
// Name: public: virtual bool CRefractiveGlassView::AdjustView(float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRefractiveGlassView::AdjustView(CRefractiveGlassView *this, float flWaterHeight)
{
  ITexture *WaterRefractionTexture; // edi

  WaterRefractionTexture = GetWaterRefractionTexture();
  this->y = 0;
  this->x = 0;
  this->width = WaterRefractionTexture->GetActualWidth(this: WaterRefractionTexture);
  this->height = WaterRefractionTexture->GetActualHeight(this: WaterRefractionTexture);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1019B0D0
// Name: public: void FrustumCache_t::Add(class CViewSetup const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge FrustumCache_t::Add(
        FrustumCache_t *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        const CViewSetup *pView,
        int iSlot)
{
  if ( pView != nullptr )
    GeneratePerspectiveFrustum(
      a1: a2,
      a2: a3,
      origin: &pView->origin,
      angles: &pView->angles,
      flZNear: pView->zNear,
      flZFar: pView->zFar,
      flFovX: pView->fov,
      flAspectRatio: pView->m_flAspectRatio,
      frustum: &this->m_Frustums[iSlot]);
}

//------------------------------------------------------------------------------
// Address: 0x1019B130
// Name: public: virtual void CConCommandMemberAccessor<class CViewRender>::CommandCallback(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConCommandMemberAccessor<CViewRender>::CommandCallback(
        CConCommandMemberAccessor<CViewRender> *this,
        const CCommand *command)
{
  ((void (__thiscall *)(const char *, const CCommand *))this->m_pszName)(
    a1: &this->m_pszHelpString[*(_DWORD *)&this->m_bRegistered],
    a2: command);
}

//------------------------------------------------------------------------------
// Address: 0x1019B150
// Name: public: virtual int CConCommandMemberAccessor<class CViewRender>::CommandCompletionCallback(char const __near *,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CConCommandMemberAccessor<CViewRender>::CommandCompletionCallback(
        CConCommandMemberAccessor<CViewRender> *this,
        const char *pPartial,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *commands)
{
  return ((int (__thiscall *)(char *, const char *, CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *))this->m_fnCommandCallbackV1)(
           a1: (char *)this->m_pNext + (unsigned int)this->m_fnCompletionCallback,
           a2: pPartial,
           a3: commands);
}

//------------------------------------------------------------------------------
// Address: 0x1019B1B0
// Name: r_cheapwaterstart
// Source: json
//------------------------------------------------------------------------------
void __cdecl r_cheapwaterstart(float args)
{
  float end; // [esp+10h] [ebp-4h] BYREF

  if ( *(_DWORD *)LODWORD(args) == 2 )
  {
    args = atof(nptr: (const char *)*(_DWORD *)(LODWORD(args) + 1036));
    ((void (__thiscall *)(IViewRender *, _DWORD))view->SetCheapWaterStartDistance)(a1: view, a2: LODWORD(args));
  }
  else
  {
    view->GetWaterLODParams(this: view, a2: &args, a3: &end);
    _Warning(a1: "r_cheapwaterstart: %f\n", args);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019B220
// Name: r_cheapwaterend
// Source: json
//------------------------------------------------------------------------------
void __cdecl r_cheapwaterend(float args)
{
  float start; // [esp+10h] [ebp-4h] BYREF

  if ( *(_DWORD *)LODWORD(args) == 2 )
  {
    args = atof(nptr: (const char *)*(_DWORD *)(LODWORD(args) + 1036));
    ((void (__thiscall *)(IViewRender *, _DWORD))view->SetCheapWaterEndDistance)(a1: view, a2: LODWORD(args));
  }
  else
  {
    view->GetWaterLODParams(this: view, a2: &start, a3: &args);
    _Warning(a1: "r_cheapwaterend: %f\n", args);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019B290
// Name: public: bool CViewRender::ShouldDrawEntities(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CViewRender::ShouldDrawEntities(CViewRender *this)
{
  const ConVar *m_pDrawEntities; // eax
  ConVar *m_pParent; // eax
  BOOL result; // eax

  m_pDrawEntities = this->m_pDrawEntities;
  result = true;
  if ( m_pDrawEntities != nullptr )
  {
    m_pParent = m_pDrawEntities->m_pParent;
    if ( m_pParent == nullptr || m_pParent->m_Value.m_nValue == 0 )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019B2B0
// Name: public: virtual bool CViewRender::ShouldDrawBrushModels(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CViewRender::ShouldDrawBrushModels(CViewRender *this)
{
  const ConVar *m_pDrawBrushModels; // eax
  ConVar *m_pParent; // eax
  bool result; // al

  m_pDrawBrushModels = this->m_pDrawBrushModels;
  result = true;
  if ( m_pDrawBrushModels != nullptr )
  {
    m_pParent = m_pDrawBrushModels->m_pParent;
    if ( m_pParent == nullptr || m_pParent->m_Value.m_nValue == 0 )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019B2D0
// Name: protected: virtual class IMaterial __near * CViewRender::GetScreenOverlayMaterial(void)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CViewRender::GetScreenOverlayMaterial(CViewRender *this)
{
  return this->m_ScreenOverlayMaterial.m_pMaterial;
}

//------------------------------------------------------------------------------
// Address: 0x1019B2E0
// Name: public: virtual void CViewRender::GetScreenFadeDistances(float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRender::GetScreenFadeDistances(CViewRender *this, float *pMin, float *pMax)
{
  float *v3; // esi
  float *v4; // edi
  float v5; // xmm0_4

  v3 = pMin;
  if ( pMin != nullptr )
    *pMin = this->m_FadeData.m_flPixelMin;
  v4 = pMax;
  if ( pMax != nullptr )
    *pMax = this->m_FadeData.m_flPixelMax;
  if ( r_fade360style.m_pParent != nullptr && r_fade360style.m_pParent->m_Value.m_nValue != 0 )
  {
    g_pMaterialSystem->GetBackBufferDimensions(this: g_pMaterialSystem, a2: (int *)&pMax, a3: (int *)&pMin);
    if ( pMin != (float *)720 )
    {
      v5 = (float)(int)pMin * 0.0013888889;
      if ( v3 != nullptr )
        *v3 = *v3 * v5;
      if ( v4 != nullptr )
        *v4 = *v4 * v5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019B370
// Name: protected: void CViewRender::OnScreenFadeMinSize(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRender::OnScreenFadeMinSize(CViewRender *this, const CCommand *args)
{
  const char *v2; // eax

  if ( args->m_nArgc >= 2 )
  {
    v2 = prType;
    if ( args->m_nArgc > 1 )
      v2 = args->m_ppArgv[1];
    this->m_FadeData.m_flPixelMin = atof(nptr: v2) * 1000.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019B3B0
// Name: protected: void CViewRender::OnScreenFadeMaxSize(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRender::OnScreenFadeMaxSize(CViewRender *this, const CCommand *args)
{
  const char *v2; // eax

  if ( args->m_nArgc >= 2 )
  {
    v2 = prType;
    if ( args->m_nArgc > 1 )
      v2 = args->m_ppArgv[1];
    this->m_FadeData.m_flPixelMax = atof(nptr: v2) * 1000.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019B3F0
// Name: GetFogColorTransition
// Source: json
//------------------------------------------------------------------------------
void __fastcall GetFogColorTransition(float *pColorPrimary, float *pColorSecondary, fogparams_t *pFogParams)
{
  float m_Value; // xmm1_4
  float v4; // xmm0_4
  float v5; // xmm0_4
  float r; // xmm1_4
  float g; // xmm2_4
  float b; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm6_4
  float v11; // xmm5_4
  float v12; // xmm2_4

  if ( pFogParams != nullptr )
  {
    m_Value = pFogParams->lerptime.m_Value;
    v4 = *(float *)(gpGlobals.m_Index + 12);
    if ( m_Value >= v4 )
    {
      v5 = 1.0 - (float)((float)(m_Value - v4) / pFogParams->duration.m_Value);
      r = (float)pFogParams->colorPrimaryLerpTo.m_Value.r;
      g = (float)pFogParams->colorPrimaryLerpTo.m_Value.g;
      b = (float)pFogParams->colorPrimaryLerpTo.m_Value.b;
      v9 = (float)pFogParams->colorSecondaryLerpTo.m_Value.r;
      v10 = (float)pFogParams->colorSecondaryLerpTo.m_Value.b;
      v11 = (float)pFogParams->colorSecondaryLerpTo.m_Value.g;
      if ( r == *pColorPrimary && g == pColorPrimary[1] && b == pColorPrimary[2] )
      {
        *pColorPrimary = r;
      }
      else
      {
        v12 = g - pColorPrimary[1];
        *pColorPrimary = (float)((float)(r - *pColorPrimary) * v5) + *pColorPrimary;
        g = (float)(v12 * v5) + pColorPrimary[1];
        b = (float)((float)(b - pColorPrimary[2]) * v5) + pColorPrimary[2];
      }
      pColorPrimary[2] = b;
      pColorPrimary[1] = g;
      if ( v9 != *pColorSecondary || v11 != pColorSecondary[1] || v10 != pColorSecondary[2] )
      {
        v11 = (float)((float)(v11 - pColorSecondary[1]) * v5) + pColorSecondary[1];
        v10 = (float)((float)(v10 - pColorSecondary[2]) * v5) + pColorSecondary[2];
        v9 = (float)((float)(v9 - *pColorSecondary) * v5) + *pColorSecondary;
      }
      pColorSecondary[2] = v10;
      pColorSecondary[1] = v11;
      *pColorSecondary = v9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019B530
// Name: public: virtual void CViewRender::QueueOverlayRenderView(class CViewSetup const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRender::QueueOverlayRenderView(
        CViewRender *this,
        const CViewSetup *view,
        int nClearFlags,
        int whatToDraw)
{
  this->m_bDrawOverlay = true;
  CViewSetup::operator=(this: &this->m_OverlayViewSetup, __that: view);
  this->m_OverlayClearFlags = nClearFlags;
  this->m_OverlayDrawFlags = whatToDraw;
}

//------------------------------------------------------------------------------
// Address: 0x1019B570
// Name: protected: virtual bool CBaseWorldView::AdjustView(float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseWorldView::AdjustView(CBaseWorldView *this, float waterHeight)
{
  int m_DrawFlags; // eax
  ITexture *WaterRefractionTexture; // edi
  ITexture *WaterReflectionTexture; // edi
  float v7; // xmm0_4
  const VMatrix *v8; // eax
  float v9; // eax
  float v10; // ecx
  float v11; // edx
  float v12; // xmm7_4
  float v13; // xmm0_4
  float v14; // xmm5_4
  float v15; // xmm4_4
  float v16; // xmm6_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  VMatrix customMatrix; // [esp+Ch] [ebp-130h] BYREF
  VMatrix dst; // [esp+4Ch] [ebp-F0h] BYREF
  VMatrix v21; // [esp+8Ch] [ebp-B0h] BYREF
  VMatrix newCustomMatrix; // [esp+CCh] [ebp-70h] BYREF
  QAngle newAngles; // [esp+10Ch] [ebp-30h] BYREF
  __int64 v24; // [esp+118h] [ebp-24h]
  float v25; // [esp+120h] [ebp-1Ch]
  Vector vNewOrigin; // [esp+124h] [ebp-18h]
  Vector vAxisOfRot; // [esp+130h] [ebp-Ch] BYREF

  m_DrawFlags = this->m_DrawFlags;
  if ( (m_DrawFlags & 1) != 0 )
  {
    WaterRefractionTexture = GetWaterRefractionTexture();
    this->y = 0;
    this->x = 0;
    this->width = WaterRefractionTexture->GetActualWidth(this: WaterRefractionTexture);
    this->height = WaterRefractionTexture->GetActualHeight(this: WaterRefractionTexture);
    return 1;
  }
  else if ( (m_DrawFlags & 2) != 0 )
  {
    WaterReflectionTexture = GetWaterReflectionTexture();
    this->y = 0;
    this->x = 0;
    this->width = WaterReflectionTexture->GetActualWidth(this: WaterReflectionTexture);
    this->height = WaterReflectionTexture->GetActualHeight(this: WaterReflectionTexture);
    this->angles.CRendering3dView::CBase3dView::CViewSetup::x = -this->angles.CRendering3dView::CBase3dView::CViewSetup::x;
    v7 = (float)(this->origin.z - waterHeight) * 2.0;
    this->angles.z = -this->angles.z;
    this->origin.z = this->origin.z - v7;
    if ( this->m_bCustomViewMatrix )
    {
      VMatrix::CopyFrom3x4(this: &customMatrix, m3x4: &this->m_matCustomViewMatrix);
      v8 = VMatrix::Transpose(this: &customMatrix, result: &v21);
      VMatrix::operator=(this: &customMatrix, mOther: v8);
      MatrixAngles(a1: (int)this, src: &customMatrix, vAngles: &newAngles);
      v9 = this->m_matCustomViewMatrix.m_flMatVal[2][2];
      v10 = this->m_matCustomViewMatrix.m_flMatVal[1][2];
      v11 = this->m_matCustomViewMatrix.m_flMatVal[0][2];
      v12 = this->m_matCustomViewMatrix.m_flMatVal[0][3];
      newAngles.x = -newAngles.x;
      newAngles.z = -newAngles.z;
      *(_QWORD *)&vNewOrigin.x = *(_QWORD *)&this->m_matCustomViewMatrix.m_flMatVal[2][0];
      v24 = *(_QWORD *)&this->m_matCustomViewMatrix.m_flMatVal[1][0];
      *(_QWORD *)&vAxisOfRot.x = *(_QWORD *)&this->m_matCustomViewMatrix.m_flMatVal[0][0];
      v13 = this->m_matCustomViewMatrix.m_flMatVal[2][3];
      v14 = vNewOrigin.y * v13;
      v15 = vNewOrigin.x * v13;
      vNewOrigin.z = v9;
      v16 = v9 * v13;
      v17 = this->m_matCustomViewMatrix.m_flMatVal[1][3];
      vNewOrigin.x = *(float *)&v24 * v17;
      vNewOrigin.y = *((float *)&v24 + 1) * v17;
      v25 = v10;
      vAxisOfRot.z = v11;
      *(float *)&v24 = -(float)((float)((float)(vAxisOfRot.x * v12) + (float)(*(float *)&v24 * v17)) + v15);
      *((float *)&v24 + 1) = -(float)((float)((float)(vAxisOfRot.y * v12) + (float)(*((float *)&v24 + 1) * v17)) + v14);
      v18 = -(float)((float)((float)(v11 * v12) + (float)(v10 * v17)) + v16);
      vNewOrigin.z = v18 - (float)((float)(v18 - waterHeight) * 2.0);
      MatrixSetIdentity(dst: &newCustomMatrix);
      vAxisOfRot.x = 1.0;
      vAxisOfRot.y = 0.0;
      vAxisOfRot.z = 0.0;
      MatrixBuildRotationAboutAxis(
        (matrix3x4_t *)&dst,
        &vAxisOfRot,
        angleDegrees: COERCE_FLOAT(LODWORD(newAngles.z) ^ _mask__NegFloat_));
      MatrixMultiply(src1: &newCustomMatrix, src2: &dst, dst: &v21);
      VMatrix::operator=(this: &newCustomMatrix, mOther: &v21);
      vAxisOfRot.x = 0.0;
      vAxisOfRot.z = 0.0;
      vAxisOfRot.y = 1.0;
      MatrixBuildRotationAboutAxis(
        dst: (matrix3x4_t *)&v21,
        &vAxisOfRot,
        angleDegrees: COERCE_FLOAT(LODWORD(newAngles.x) ^ _mask__NegFloat_));
      MatrixMultiply(src1: &newCustomMatrix, src2: &v21, &dst);
      VMatrix::operator=(this: &newCustomMatrix, mOther: &dst);
      vAxisOfRot.x = 0.0;
      vAxisOfRot.y = 0.0;
      vAxisOfRot.z = 1.0;
      MatrixBuildRotationAboutAxis(
        dst: (matrix3x4_t *)&v21,
        &vAxisOfRot,
        angleDegrees: COERCE_FLOAT(LODWORD(newAngles.y) ^ _mask__NegFloat_));
      MatrixMultiply(src1: &newCustomMatrix, src2: &v21, &dst);
      VMatrix::operator=(this: &newCustomMatrix, mOther: &dst);
      vAxisOfRot.x = -*(float *)&v24;
      LODWORD(vAxisOfRot.y) = HIDWORD(v24) ^ 0x80000000;
      vAxisOfRot.z = -vNewOrigin.z;
      MatrixBuildTranslation(dst: &v21, translation: &vAxisOfRot);
      MatrixMultiply(src1: &newCustomMatrix, src2: &v21, &dst);
      VMatrix::operator=(this: &newCustomMatrix, mOther: &dst);
      *(_QWORD *)&this->m_matCustomViewMatrix.m_flMatVal[0][0] = *(_QWORD *)&newCustomMatrix.m[0][0];
      *(_QWORD *)&this->m_matCustomViewMatrix.m_flMatVal[0][2] = *(_QWORD *)&newCustomMatrix.m[0][2];
      *(_OWORD *)&this->m_matCustomViewMatrix.m_flMatVal[1][0] = *(_OWORD *)&newCustomMatrix.m[1][0];
      *(_OWORD *)&this->m_matCustomViewMatrix.m_flMatVal[2][0] = *(_OWORD *)&newCustomMatrix.m[2][0];
    }
    return 1;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019B980
// Name: public: CConCommandMemberAccessor<class CViewRender>::CConCommandMemberAccessor<class CViewRender>(class CViewRender __near *,char const __near *,void (CViewRender::*)(class CCommand const __near &),char const __near *,int,int (CViewRender::*)(char const __near *,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &))
// Source: json
//------------------------------------------------------------------------------
CConCommandMemberAccessor<CViewRender> *__thiscall CConCommandMemberAccessor<CViewRender>::CConCommandMemberAccessor<CViewRender>(
        CConCommandMemberAccessor<CViewRender> *this,
        CViewRender *pOwner,
        const char *pName,
        __int128 callback,
        const char *pHelpString,
        int flags,
        __int128 completionFunc)
{
  ICommandCompletionCallback *v8; // ecx
  ICommandCallback *v9; // eax
  __int64 v10; // xmm0_8

  if ( (_DWORD)completionFunc != 0 && this != nullptr )
    v8 = &this->ICommandCompletionCallback;
  else
    v8 = nullptr;
  if ( this != nullptr )
    v9 = &this->ICommandCallback;
  else
    v9 = nullptr;
  ConCommand::ConCommand(this, pName, pCallback: v9, pHelpString, flags, pCompletionCallback: v8);
  this->ICommandCallback::__vftable = (ICommandCallback_vtbl *)&ICommandCallback::`vftable';
  this->ICommandCompletionCallback::__vftable = (ICommandCompletionCallback_vtbl *)&ICommandCompletionCallback::`vftable';
  this->m_Func = callback;
  *(_QWORD *)&this->m_CompletionFunc = completionFunc;
  v10 = *((_QWORD *)&completionFunc + 1);
  this->ConCommand::ConCommandBase::__vftable = (CConCommandMemberAccessor<CViewRender>_vtbl *)&CConCommandMemberAccessor<CViewRender>::`vftable'{for `ConCommand'};
  this->ICommandCallback::__vftable = (ICommandCallback_vtbl *)&CConCommandMemberAccessor<CViewRender>::`vftable'{for `ICommandCallback'};
  this->ICommandCompletionCallback::__vftable = (ICommandCompletionCallback_vtbl *)&CConCommandMemberAccessor<CViewRender>::`vftable'{for `ICommandCompletionCallback'};
  this->m_pOwner = pOwner;
  *((_QWORD *)&this->m_CompletionFunc + 1) = v10;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1019BA10
// Name: public: void CMatRenderContextPtr::GetFrom(class IMaterialSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderContextPtr::GetFrom(CMatRenderContextPtr *this, IMaterialSystem *pFrom)
{
  IMatRenderContext *v3; // edi

  v3 = pFrom->GetRenderContext(this: pFrom);
  if ( this->m_pObject != nullptr )
  {
    this->m_pObject->EndRender(this: this->m_pObject);
    if ( this->m_pObject != nullptr )
      this->m_pObject->Release(this: this->m_pObject);
  }
  this->m_pObject = nullptr;
  if ( v3 != nullptr )
    v3->AddRef(this: v3);
  this->m_pObject = v3;
  v3->BeginRender(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1019BB10
// Name: public: CViewRender::CCommandMemberInitializer_OnScreenFadeMinSize::CCommandMemberInitializer_OnScreenFadeMinSize(void)
// Source: json
//------------------------------------------------------------------------------
CViewRender::CCommandMemberInitializer_OnScreenFadeMinSize *__thiscall CViewRender::CCommandMemberInitializer_OnScreenFadeMinSize::CCommandMemberInitializer_OnScreenFadeMinSize(
        CViewRender::CCommandMemberInitializer_OnScreenFadeMinSize *this)
{
  __int128 v3; // [esp-10h] [ebp-34h]

  *(_QWORD *)&v3 = 0;
  *((_QWORD *)&v3 + 1) = 0xFFFFFFFF00000000uLL;
  CConCommandMemberAccessor<CViewRender>::CConCommandMemberAccessor<CViewRender>(
    this: &this->m_ConCommandAccessor,
    pOwner: nullptr,
    pName: "screenfademinsize",
    callback: (unsigned int)CViewRender::OnScreenFadeMinSize,
    pHelpString: "Modify global screen fade min size in pixels",
    flags: 16386,
    completionFunc: v3);
  this->m_ConCommandAccessor.m_pOwner = (CViewRender *)((char *)this - 984);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1019BBA0
// Name: public: CViewRender::CCommandMemberInitializer_OnScreenFadeMaxSize::CCommandMemberInitializer_OnScreenFadeMaxSize(void)
// Source: json
//------------------------------------------------------------------------------
CViewRender::CCommandMemberInitializer_OnScreenFadeMaxSize *__thiscall CViewRender::CCommandMemberInitializer_OnScreenFadeMaxSize::CCommandMemberInitializer_OnScreenFadeMaxSize(
        CViewRender::CCommandMemberInitializer_OnScreenFadeMaxSize *this)
{
  __int128 v3; // [esp-10h] [ebp-34h]

  *(_QWORD *)&v3 = 0;
  *((_QWORD *)&v3 + 1) = 0xFFFFFFFF00000000uLL;
  CConCommandMemberAccessor<CViewRender>::CConCommandMemberAccessor<CViewRender>(
    this: &this->m_ConCommandAccessor,
    pOwner: nullptr,
    pName: "screenfademaxsize",
    callback: (unsigned int)CViewRender::OnScreenFadeMaxSize,
    pHelpString: "Modify global screen fade max size in pixels",
    flags: 16386,
    completionFunc: v3);
  this->m_ConCommandAccessor.m_pOwner = (CViewRender *)((char *)this - 1064);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1019BC30
// Name: void GetSimpleWorldModelConfiguration(bool __near &,int __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetSimpleWorldModelConfiguration(
        bool *bSimpleWorldModeWaterReflectionOut,
        int *nSimpleWorldModelRecursionLevelOut,
        float *flSimpleWorldModelDrawBeyondDistanceOut)
{
  int m_nValue; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax

  g_pGameRules->IsMultiplayer(this: g_pGameRules);
  if ( VGui_IsSplitScreen() )
  {
    if ( VGui_IsSplitScreenPIP() )
    {
      if ( r_simpleworldmodel_waterreflections_fullscreen.m_pParent != nullptr )
        m_nValue = r_simpleworldmodel_waterreflections_fullscreen.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      *bSimpleWorldModeWaterReflectionOut = m_nValue != 0;
      if ( r_simpleworldmodel_drawforrecursionlevel_fullscreen.m_pParent != nullptr )
        v4 = r_simpleworldmodel_drawforrecursionlevel_fullscreen.m_pParent->m_Value.m_nValue;
      else
        v4 = 0;
      *nSimpleWorldModelRecursionLevelOut = v4;
      *flSimpleWorldModelDrawBeyondDistanceOut = r_simpleworldmodel_drawbeyonddistance_fullscreen.m_pParent->m_Value.m_fValue;
    }
    else
    {
      if ( r_simpleworldmodel_waterreflections_splitscreen.m_pParent != nullptr )
        v5 = r_simpleworldmodel_waterreflections_splitscreen.m_pParent->m_Value.m_nValue;
      else
        v5 = 0;
      *bSimpleWorldModeWaterReflectionOut = v5 != 0;
      if ( r_simpleworldmodel_drawforrecursionlevel_splitscreen.m_pParent != nullptr )
        *nSimpleWorldModelRecursionLevelOut = r_simpleworldmodel_drawforrecursionlevel_splitscreen.m_pParent->m_Value.m_nValue;
      else
        *nSimpleWorldModelRecursionLevelOut = 0;
      *flSimpleWorldModelDrawBeyondDistanceOut = r_simpleworldmodel_drawbeyonddistance_splitscreen.m_pParent->m_Value.m_fValue;
    }
  }
  else
  {
    if ( r_simpleworldmodel_waterreflections_fullscreen.m_pParent != nullptr )
      v6 = r_simpleworldmodel_waterreflections_fullscreen.m_pParent->m_Value.m_nValue;
    else
      v6 = 0;
    *bSimpleWorldModeWaterReflectionOut = v6 != 0;
    if ( r_simpleworldmodel_drawforrecursionlevel_fullscreen.m_pParent != nullptr )
      v7 = r_simpleworldmodel_drawforrecursionlevel_fullscreen.m_pParent->m_Value.m_nValue;
    else
      v7 = 0;
    *nSimpleWorldModelRecursionLevelOut = v7;
    *flSimpleWorldModelDrawBeyondDistanceOut = r_simpleworldmodel_drawbeyonddistance_fullscreen.m_pParent->m_Value.m_fValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019BD30
// Name: public: CWorldListCache::Entry_t::Entry_t(class CViewSetup const __near &,struct VisOverrideData_t __near *,int,class IWorldRenderList __near *,struct ClientWorldListInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
CWorldListCache::Entry_t *__thiscall CWorldListCache::Entry_t::Entry_t(
        CWorldListCache::Entry_t *this,
        const CViewSetup *viewSetup,
        VisOverrideData_t *pVisOverrideData,
        int iForceViewLeaf,
        IWorldRenderList *pList,
        ClientWorldListInfo_t *pListInfo)
{
  IWorldRenderList *v7; // eax
  ClientWorldListInfo_t *v8; // eax

  if ( pList != nullptr )
  {
    pList->AddRef(this: pList);
    v7 = pList;
  }
  else
  {
    v7 = nullptr;
  }
  this->pList = v7;
  v8 = pListInfo;
  if ( pListInfo != nullptr )
    _InterlockedExchangeAdd(&pListInfo->m_iRefs, 1u);
  else
    v8 = nullptr;
  this->pListInfo = v8;
  *(_DWORD *)&this->m_bOrtho = 0;
  this->m_bOrtho = viewSetup->m_bOrtho;
  this->m_OrthoLeft = viewSetup->m_OrthoLeft;
  this->m_OrthoTop = viewSetup->m_OrthoTop;
  this->m_OrthoRight = viewSetup->m_OrthoRight;
  this->m_OrthoBottom = viewSetup->m_OrthoBottom;
  this->fov = viewSetup->fov;
  this->origin = viewSetup->origin;
  this->angles = viewSetup->angles;
  this->zNear = viewSetup->zNear;
  this->zFar = viewSetup->zFar;
  this->m_flAspectRatio = viewSetup->m_flAspectRatio;
  this->m_bOffCenter = *((_BYTE *)viewSetup + 240) & 1;
  this->m_flOffCenterTop = viewSetup->m_flOffCenterTop;
  this->m_flOffCenterBottom = viewSetup->m_flOffCenterBottom;
  this->m_flOffCenterLeft = viewSetup->m_flOffCenterLeft;
  this->m_flOffCenterRight = viewSetup->m_flOffCenterRight;
  if ( pVisOverrideData != nullptr )
    qmemcpy((void *)&this->m_VisOverride, pVisOverrideData, sizeof(this->m_VisOverride));
  else
    memset(dst: (int)&this->m_VisOverride, value: nullptr, count: sizeof(this->m_VisOverride));
  this->m_iForceViewLeaf = iForceViewLeaf;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1019BE70
// Name: public: CViewRender::CViewRender(void)
// Source: json
//------------------------------------------------------------------------------
CViewRender *__thiscall CViewRender::CViewRender(CViewRender *this)
{
  this->__vftable = (CViewRender_vtbl *)&CViewRender::`vftable';
  this->m_UserView[0].m_flAspectRatio = 0.0;
  this->m_UserView[0].m_flNearBlurDepth = 20.0;
  this->m_UserView[0].m_flNearFocusDepth = 100.0;
  this->m_UserView[0].m_flFarFocusDepth = 250.0;
  this->m_UserView[0].m_flFarBlurDepth = 1000.0;
  this->m_UserView[0].m_flNearBlurRadius = 10.0;
  this->m_UserView[0].m_flFarBlurRadius = 5.0;
  this->m_UserView[0].m_nMotionBlurMode = MOTION_BLUR_GAME;
  *((_BYTE *)this->m_UserView + 240) = 4;
  this->m_UserView[0].m_nDoFQuality = 0;
  this->m_UserView[0].m_bCustomViewMatrix = false;
  this->m_CurrentView.m_flAspectRatio = 0.0;
  this->m_CurrentView.m_flNearBlurDepth = 20.0;
  this->m_CurrentView.m_flNearFocusDepth = 100.0;
  this->m_CurrentView.m_flFarFocusDepth = 250.0;
  this->m_CurrentView.m_flFarBlurDepth = 1000.0;
  this->m_CurrentView.m_flNearBlurRadius = 10.0;
  this->m_CurrentView.m_flFarBlurRadius = 5.0;
  this->m_CurrentView.m_nDoFQuality = 0;
  this->m_CurrentView.m_nMotionBlurMode = MOTION_BLUR_GAME;
  *((_BYTE *)&this->m_CurrentView + 240) = 4;
  this->m_CurrentView.m_bCustomViewMatrix = false;
  CMaterialReference::CMaterialReference(
    this: &this->m_TranslucentSingleColor,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_ModulateSingleColor,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_ScreenOverlayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_UnderWaterOverlayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  this->m_OverlayViewSetup.m_flNearBlurDepth = 20.0;
  this->m_OverlayViewSetup.m_flNearFocusDepth = 100.0;
  this->m_OverlayViewSetup.m_flFarFocusDepth = 250.0;
  this->m_OverlayViewSetup.m_flFarBlurDepth = 1000.0;
  this->m_OverlayViewSetup.m_flNearBlurRadius = 10.0;
  this->m_OverlayViewSetup.m_flAspectRatio = 0.0;
  this->m_OverlayViewSetup.m_flFarBlurRadius = 5.0;
  this->m_OverlayViewSetup.m_nDoFQuality = 0;
  this->m_OverlayViewSetup.m_nMotionBlurMode = MOTION_BLUR_GAME;
  *((_BYTE *)&this->m_OverlayViewSetup + 240) = 4;
  this->m_OverlayViewSetup.m_bCustomViewMatrix = false;
  this->m_SimpleExecutor.m_pMainView = this;
  this->m_SimpleExecutor.__vftable = (CSimpleRenderExecutor_vtbl *)&CSimpleRenderExecutor::`vftable';
  this->m_FreezeParams[0].m_bTakeFreezeFrame = false;
  this->m_FreezeParams[0].m_flFreezeFrameUntil = 0.0;
  CMaterialReference::CMaterialReference(
    this: &this->m_WhiteMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CViewRender::CCommandMemberInitializer_OnScreenFadeMinSize::CCommandMemberInitializer_OnScreenFadeMinSize(this: &this->m_OnScreenFadeMinSize_register);
  CViewRender::CCommandMemberInitializer_OnScreenFadeMaxSize::CCommandMemberInitializer_OnScreenFadeMaxSize(this: &this->m_OnScreenFadeMaxSize_register);
  this->m_flCheapWaterStartDistance = 0.0;
  this->m_BaseDrawFlags = 0;
  this->m_pActiveRenderer = nullptr;
  this->m_pCurrentlyDrawingEntity = nullptr;
  this->m_bAllowViewAccess = false;
  this->m_flCheapWaterEndDistance = 0.1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1019C0A0
// Name: public: virtual bool CViewRender::ShouldForceNoVis(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CViewRender::ShouldForceNoVis(CViewRender *this)
{
  return this->m_bForceNoVis;
}

//------------------------------------------------------------------------------
// Address: 0x1019C0B0
// Name: public: virtual int CViewRender::GetDrawFlags(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CViewRender::GetDrawFlags(CViewRender *this)
{
  if ( this->m_pActiveRenderer != nullptr )
    return this->m_pActiveRenderer->GetDrawFlags(this: this->m_pActiveRenderer);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1019C0D0
// Name: public: virtual class VPlane __near * CViewRender::GetFrustum(void)
// Source: json
//------------------------------------------------------------------------------
VPlane *__thiscall CViewRender::GetFrustum(CViewRender *this)
{
  CBase3dView *m_pActiveRenderer; // eax

  m_pActiveRenderer = this->m_pActiveRenderer;
  if ( m_pActiveRenderer != nullptr )
    return m_pActiveRenderer->m_Frustum;
  else
    return this->m_Frustum;
}

//------------------------------------------------------------------------------
// Address: 0x1019C0F0
// Name: public: virtual CViewRender::~CViewRender(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRender::~CViewRender(CViewRender *this)
{
  CViewRender::CCommandMemberInitializer_OnScreenFadeMaxSize *p_m_OnScreenFadeMaxSize_register; // ecx

  this->__vftable = (CViewRender_vtbl *)&CViewRender::`vftable';
  p_m_OnScreenFadeMaxSize_register = &this->m_OnScreenFadeMaxSize_register;
  p_m_OnScreenFadeMaxSize_register->m_ConCommandAccessor.__vftable = (CConCommandMemberAccessor<CViewRender>_vtbl *)&CConCommandMemberAccessor<CViewRender>::`vftable'{for `ConCommand'};
  this->m_OnScreenFadeMaxSize_register.m_ConCommandAccessor.__vftable = (ICommandCallback_vtbl *)&CConCommandMemberAccessor<CViewRender>::`vftable'{for `ICommandCallback'};
  this->m_OnScreenFadeMaxSize_register.m_ConCommandAccessor.__vftable = (ICommandCompletionCallback_vtbl *)&CConCommandMemberAccessor<CViewRender>::`vftable'{for `ICommandCompletionCallback'};
  ConCommandBase::Shutdown(this: &p_m_OnScreenFadeMaxSize_register->m_ConCommandAccessor);
  ConCommand::~ConCommand(this: &this->m_OnScreenFadeMaxSize_register.m_ConCommandAccessor);
  this->m_OnScreenFadeMinSize_register.m_ConCommandAccessor.__vftable = (CConCommandMemberAccessor<CViewRender>_vtbl *)&CConCommandMemberAccessor<CViewRender>::`vftable'{for `ConCommand'};
  this->m_OnScreenFadeMinSize_register.m_ConCommandAccessor.__vftable = (ICommandCallback_vtbl *)&CConCommandMemberAccessor<CViewRender>::`vftable'{for `ICommandCallback'};
  this->m_OnScreenFadeMinSize_register.m_ConCommandAccessor.__vftable = (ICommandCompletionCallback_vtbl *)&CConCommandMemberAccessor<CViewRender>::`vftable'{for `ICommandCompletionCallback'};
  ConCommandBase::Shutdown(this: &this->m_OnScreenFadeMinSize_register.m_ConCommandAccessor);
  ConCommand::~ConCommand(this: &this->m_OnScreenFadeMinSize_register.m_ConCommandAccessor);
  CMaterialReference::~CMaterialReference(this: &this->m_WhiteMaterial);
  CMaterialReference::~CMaterialReference(this: &this->m_UnderWaterOverlayMaterial);
  CMaterialReference::~CMaterialReference(this: &this->m_ScreenOverlayMaterial);
  CMaterialReference::~CMaterialReference(this: &this->m_ModulateSingleColor);
  CMaterialReference::~CMaterialReference(this: &this->m_TranslucentSingleColor);
}

//------------------------------------------------------------------------------
// Address: 0x1019C1D0
// Name: protected: bool CViewRender::ShouldDrawViewModel(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CViewRender::ShouldDrawViewModel(CViewRender *this, bool bDrawViewmodel)
{
  bool result; // al
  C_BasePlayer *LocalPlayer; // eax

  result = bDrawViewmodel
        && r_drawviewmodel.m_pParent != nullptr
        && r_drawviewmodel.m_pParent->m_Value.m_nValue != 0
        && C_BasePlayer::GetLocalPlayer(nSlot: -1) != nullptr
        && (LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1),
            !C_BasePlayer::ShouldDrawLocalPlayer(this: LocalPlayer))
        && CViewRender::ShouldDrawEntities(this)
        && render->GetViewEntity(this: render) <= *(_DWORD *)(gpGlobals.m_Index + 20);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019C240
// Name: protected: void CViewRender::DrawRenderablesInList(class CUtlVectorFixedGrowable<struct CViewModelRenderablesList::CEntry,32> __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRender::DrawRenderablesInList(
        CViewRender *this,
        CUtlVectorFixedGrowable<CViewModelRenderablesList::CEntry,32> *renderGroups,
        int flags)
{
  int v4; // edi
  IClientRenderable *m_pRenderable; // esi
  int v6; // eax
  int nCount; // [esp+14h] [ebp+8h]

  v4 = 0;
  nCount = renderGroups->m_Size;
  if ( nCount <= 0 )
  {
    this->m_pCurrentlyDrawingEntity = nullptr;
  }
  else
  {
    do
    {
      m_pRenderable = renderGroups->m_Memory.m_pMemory[v4].m_pRenderable;
      v6 = m_pRenderable->GetIClientUnknown(this: m_pRenderable);
      this->m_pCurrentlyDrawingEntity = (C_BaseEntity *)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 28))(a1: v6);
      m_pRenderable->DrawModel(
        this: m_pRenderable,
        a2: flags | (renderGroups->m_Memory.m_pMemory[v4].m_InstanceData.m_bTwoPass != 0 ? 8 : 0) | 1,
        a3: &renderGroups->m_Memory.m_pMemory[v4].m_InstanceData);
      ++v4;
    }
    while ( v4 < nCount );
    this->m_pCurrentlyDrawingEntity = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019C2D0
// Name: void PositionHudPanels(class CUtlVector<unsigned int,class CUtlMemory<unsigned int,int>> __near &,class CViewSetup const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PositionHudPanels(CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *list, const CViewSetup *view)
{
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *v2; // eax
  int i; // ebx
  unsigned int v4; // esi

  v2 = list;
  for ( i = 0; i < v2->m_Size; ++i )
  {
    v4 = v2->m_Memory.m_pMemory[i];
    if ( v4 != 0 )
    {
      g_pVGuiPanel->SetPos(this: g_pVGuiPanel, a2: v4, a3: view->x, a4: view->y);
      g_pVGuiPanel->SetSize(this: g_pVGuiPanel, a2: v4, a3: view->width, a4: view->height);
      v2 = list;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019C330
// Name: protected: void CViewRender::DetermineWaterRenderInfo(struct VisibleFogVolumeInfo_t const __near &,struct WaterRenderInfo_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRender::DetermineWaterRenderInfo(
        CViewRender *this,
        const VisibleFogVolumeInfo_t *fogVolumeInfo,
        WaterRenderInfo_t *info)
{
  const VisibleFogVolumeInfo_t *v3; // eax
  WaterRenderInfo_t *v4; // esi
  IMaterial *m_pFogVolumeMaterial; // edi
  int m_nValue; // eax
  char v7; // al
  int v8; // eax
  int v9; // eax
  IMaterialVar *v10; // ebx
  int v11; // eax
  bool v12; // zf
  int v13; // eax
  const char *v14; // ecx
  const char *v15; // eax
  const char *v16; // eax
  int v17; // eax
  bool v18; // bl
  int v19; // eax
  bool v20; // al
  char v21; // al
  char v22; // al
  int v23; // eax
  bool v24; // al
  IMaterialVar *(__thiscall *FindVar)(IMaterial *, const char *, bool *, bool); // edx
  int v26; // eax
  int v27; // eax
  bool v28; // al
  char v29; // al
  const char *v30; // ecx
  const char *v31; // eax
  double v32; // [esp+18h] [ebp-28h]
  const char *v33; // [esp+20h] [ebp-20h]
  const char *v34; // [esp+24h] [ebp-1Ch]
  IMaterialVar *pForceExpensiveVar; // [esp+38h] [ebp-8h]
  bool bDebugCheapWater; // [esp+3Dh] [ebp-3h]
  bool bForceReflectEntities; // [esp+3Eh] [ebp-2h]
  bool bForceCheap; // [esp+3Fh] [ebp-1h]

  v3 = fogVolumeInfo;
  v4 = info;
  *((_BYTE *)info + 1) &= ~1u;
  *(_BYTE *)v4 = 65;
  m_pFogVolumeMaterial = v3->m_pFogVolumeMaterial;
  if ( v3->m_nVisibleFogVolume == -1 || m_pFogVolumeMaterial == nullptr )
    return;
  if ( mat_drawwater.m_pParent != nullptr )
    m_nValue = mat_drawwater.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v7 = ((32 * (m_nValue != 0)) ^ 0x41) & 0x20 ^ 0x41;
  *(_BYTE *)v4 = v7;
  if ( (v7 & 0x20) == 0 )
  {
    *(_BYTE *)v4 = v7 & 0xBF;
    return;
  }
  if ( r_waterforceexpensive.m_pParent != nullptr )
    v8 = r_waterforceexpensive.m_pParent->m_Value.m_nValue;
  else
    v8 = 0;
  HIBYTE(info) = v8 != 0;
  if ( r_waterforcereflectentities.m_pParent != nullptr )
    v9 = r_waterforcereflectentities.m_pParent->m_Value.m_nValue;
  else
    v9 = 0;
  bForceReflectEntities = v9 != 0;
  bForceCheap = false;
  *(_BYTE *)v4 ^= (*(_BYTE *)v4 ^ (!m_pFogVolumeMaterial->IsTranslucent(this: m_pFogVolumeMaterial) << 6)) & 0x40;
  v10 = m_pFogVolumeMaterial->FindVar(this: m_pFogVolumeMaterial, a2: "$forcecheap", a3: nullptr, a4: false);
  v11 = (int)m_pFogVolumeMaterial->FindVar(this: m_pFogVolumeMaterial, a2: "$forceexpensive", a3: nullptr, a4: false);
  pForceExpensiveVar = (IMaterialVar *)v11;
  if ( v10 != nullptr )
  {
    if ( v10->IsDefined(this: v10) )
    {
      bForceCheap = v10->m_intVal != 0;
      if ( v10->m_intVal != 0 )
      {
        HIBYTE(info) = 0;
        goto LABEL_24;
      }
    }
    v11 = (int)pForceExpensiveVar;
  }
  if ( v11 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v11 + 72))(a1: v11) != 0 )
  {
    if ( HIBYTE(info) != 0 || (v12 = pForceExpensiveVar->m_intVal == 0, HIBYTE(info) = 0, !v12) )
      HIBYTE(info) = 1;
  }
LABEL_24:
  if ( r_debugcheapwater.m_pParent != nullptr )
    v13 = r_debugcheapwater.m_pParent->m_Value.m_nValue;
  else
    v13 = 0;
  bDebugCheapWater = v13 != 0;
  if ( v13 != 0 )
  {
    v14 = "true";
    if ( HIBYTE(info) == 0 )
      v14 = "false";
    v15 = "true";
    if ( !bForceCheap )
      v15 = "false";
    v16 = (const char *)((int (__thiscall *)(IMaterial *, _DWORD, _DWORD, const char *, const char *))m_pFogVolumeMaterial->GetName)(
                          a1: m_pFogVolumeMaterial,
                          a2: COERCE_UNSIGNED_INT64(fogVolumeInfo->m_flDistanceToWater),
                          a3: HIDWORD(COERCE_UNSIGNED_INT64(fogVolumeInfo->m_flDistanceToWater)),
                          a4: v15,
                          a5: v14);
    _Msg(a1: "Water material: %s dist to water: %f\nforcecheap: %s forceexpensive: %s\n", v16, v32, v33, v34);
  }
  v18 = false;
  if ( HIBYTE(info) != 0
    && r_WaterDrawReflection.m_pParent != nullptr
    && r_WaterDrawReflection.m_pParent->m_Value.m_nValue != 0 )
  {
    v17 = (int)m_pFogVolumeMaterial->FindVar(this: m_pFogVolumeMaterial, a2: "$reflecttexture", a3: nullptr, a4: false);
    if ( v17 != 0 && (*(_BYTE *)(v17 + 28) & 0xF) == 3 )
      v18 = true;
  }
  if ( (fogVolumeInfo->m_flDistanceToWater < this->m_flCheapWaterEndDistance || v18) && !bForceCheap )
  {
    if ( r_WaterDrawRefraction.m_pParent != nullptr && r_WaterDrawRefraction.m_pParent->m_Value.m_nValue != 0 )
    {
      v19 = (int)m_pFogVolumeMaterial->FindVar(
                   this: m_pFogVolumeMaterial,
                   a2: "$refracttexture",
                   a3: nullptr,
                   a4: false);
      v20 = v19 != 0 && (*(_BYTE *)(v19 + 28) & 0xF) == 3;
      *(_BYTE *)v4 ^= (*(_BYTE *)v4 ^ (4 * v20)) & 4;
      if ( (*(_BYTE *)v4 & 4) != 0 )
        *(_BYTE *)v4 &= ~0x40u;
    }
    else
    {
      *(_BYTE *)v4 &= ~4u;
    }
    if ( (*(_BYTE *)v4 & 4) == 0 )
    {
      v21 = *(_BYTE *)v4 & 0x7F
          | (m_pFogVolumeMaterial->GetMaterialVarFlag(this: m_pFogVolumeMaterial, a2: MATERIAL_VAR_PSEUDO_TRANSLUCENT) << 7);
      *(_BYTE *)v4 = v21;
      if ( v21 < 0 )
        *(_BYTE *)v4 = v21 & 0xBF;
    }
    *(_BYTE *)v4 ^= (*(_BYTE *)v4 ^ (2 * v18)) & 2;
    if ( (*(_BYTE *)v4 & 2) == 0 )
      goto LABEL_72;
    if ( bForceReflectEntities )
    {
      v22 = *(_BYTE *)v4 | 8;
    }
    else
    {
      v23 = (int)m_pFogVolumeMaterial->FindVar(
                   this: m_pFogVolumeMaterial,
                   a2: "$reflectentities",
                   a3: nullptr,
                   a4: false);
      v24 = v23 != 0 && *(_DWORD *)(v23 + 8) != 0;
      *(_BYTE *)v4 ^= (*(_BYTE *)v4 ^ (8 * v24)) & 8;
      if ( (*(_BYTE *)v4 & 8) != 0 )
        goto LABEL_67;
      FindVar = m_pFogVolumeMaterial->FindVar;
      HIBYTE(fogVolumeInfo) = 0;
      v26 = (int)FindVar(
                   this: m_pFogVolumeMaterial,
                   a2: "$reflectonlymarkedentities",
                   a3: (bool *)&fogVolumeInfo + 3,
                   a4: false);
      *(_BYTE *)v4 &= ~0x10u;
      if ( v26 == 0 || HIBYTE(fogVolumeInfo) == 0 )
        goto LABEL_67;
      v22 = *(_BYTE *)v4 ^ (*(_BYTE *)v4 ^ (16 * (*(_DWORD *)(v26 + 8) != 0))) & 0x10;
    }
    *(_BYTE *)v4 = v22;
LABEL_67:
    v27 = (int)m_pFogVolumeMaterial->FindVar(this: m_pFogVolumeMaterial, a2: "$reflect2dskybox", a3: nullptr, a4: false);
    v28 = v27 != 0 && *(_DWORD *)(v27 + 8) != 0;
    *((_BYTE *)v4 + 1) ^= (v28 ^ *((_BYTE *)v4 + 1)) & 1;
LABEL_72:
    *(_BYTE *)v4 ^= (((*(_BYTE *)v4 & 6) == 0) ^ *(_BYTE *)v4) & 1;
    v29 = *(_BYTE *)v4;
    if ( bDebugCheapWater )
    {
      v30 = "true";
      if ( (v29 & 2) == 0 )
        v30 = "false";
      v12 = (v29 & 4) == 0;
      v31 = "true";
      if ( v12 )
        v31 = "false";
      _Warning(a1: "refract: %s reflect: %s\n", v31, v30);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019C690
// Name: public: CBase3dView::CBase3dView(class CViewRender __near *)
// Source: json
//------------------------------------------------------------------------------
CBase3dView *__thiscall CBase3dView::CBase3dView(CBase3dView *this, CViewRender *pMainView)
{
  this->m_iRefs = 1;
  this->m_flAspectRatio = 0.0;
  this->m_flNearBlurDepth = 20.0;
  this->m_flNearFocusDepth = 100.0;
  this->m_flFarFocusDepth = 250.0;
  this->m_flFarBlurDepth = 1000.0;
  this->m_flNearBlurRadius = 10.0;
  this->m_flFarBlurRadius = 5.0;
  this->m_nDoFQuality = 0;
  this->m_nMotionBlurMode = MOTION_BLUR_GAME;
  *((_BYTE *)&this->CViewSetup + 240) = 4;
  this->m_bCustomViewMatrix = false;
  this->m_Frustum = pMainView->m_Frustum;
  this->__vftable = (CBase3dView_vtbl *)&CBase3dView::`vftable';
  this->m_pMainView = pMainView;
  this->m_nSlot = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1019C770
// Name: public: CRendering3dView::CRendering3dView(class CViewRender __near *)
// Source: json
//------------------------------------------------------------------------------
CRendering3dView *__thiscall CRendering3dView::CRendering3dView(CRendering3dView *this, CViewRender *pMainView)
{
  CBase3dView::CBase3dView(this, pMainView);
  this->m_DrawFlags = 0;
  this->m_ClearFlags = 0;
  this->m_pWorldRenderList = nullptr;
  this->m_pRenderablesList = nullptr;
  this->m_pWorldListInfo = nullptr;
  this->m_pCustomVisibility = nullptr;
  this->__vftable = (CRendering3dView_vtbl *)&CRendering3dView::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1019C7C0
// Name: protected: void CRendering3dView::ReleaseLists(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRendering3dView::ReleaseLists(CRendering3dView *this)
{
  IWorldRenderList *m_pWorldRenderList; // ecx
  CClientRenderablesList *m_pRenderablesList; // edi
  ClientWorldListInfo_t *m_pWorldListInfo; // edi

  m_pWorldRenderList = this->m_pWorldRenderList;
  if ( m_pWorldRenderList != nullptr )
  {
    m_pWorldRenderList->Release(this: m_pWorldRenderList);
    this->m_pWorldRenderList = nullptr;
  }
  m_pRenderablesList = this->m_pRenderablesList;
  if ( m_pRenderablesList != nullptr )
  {
    if ( _InterlockedDecrement(&m_pRenderablesList->m_iRefs) == 0
      && m_pRenderablesList->OnFinalRelease(this: m_pRenderablesList) )
    {
      ((void (__thiscall *)(CClientRenderablesList *, int))m_pRenderablesList->dtr_CRefCountServiceBase<1,CRefMT>)(
        a1: m_pRenderablesList,
        a2: 1);
    }
    this->m_pRenderablesList = nullptr;
  }
  m_pWorldListInfo = this->m_pWorldListInfo;
  if ( m_pWorldListInfo != nullptr )
  {
    if ( _InterlockedDecrement(&m_pWorldListInfo->m_iRefs) == 0
      && m_pWorldListInfo->OnFinalRelease(this: m_pWorldListInfo) )
    {
      ((void (__thiscall *)(ClientWorldListInfo_t *, int))m_pWorldListInfo->dtr_CRefCountServiceBase<1,CRefMT>)(
        a1: m_pWorldListInfo,
        a2: 1);
    }
    this->m_pWorldListInfo = nullptr;
  }
  this->m_pCustomVisibility = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1019C860
// Name: protected: void CRendering3dView::SetupRenderablesList(int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRendering3dView::SetupRenderablesList(
        CRendering3dView *this,
        int viewID,
        bool bFastEntityRendering,
        bool bDrawDepthViewNonCachedObjectsOnly)
{
  CViewRender *m_pMainView; // eax
  const ConVar *m_pDrawEntities; // ecx
  ConVar *m_pParent; // ecx
  ClientWorldListInfo_t *m_pWorldListInfo; // eax
  CViewRender *v9; // ecx
  IClientMode *ClientMode; // eax
  bool v11; // cl
  char v12; // al
  bool v13; // cl
  float m_fValue; // xmm0_4
  SetupRenderInfo_t setupInfo; // [esp+8h] [ebp-34h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "SetupRenderablesList",
    a3: 0,
    a4: "SetupRenderablesList",
    a5: false,
    a6: 4);
  this->m_pRenderablesList->m_RenderGroupCounts[0] = 0;
  this->m_pRenderablesList->m_RenderGroupCounts[1] = 0;
  this->m_pRenderablesList->m_RenderGroupCounts[2] = 0;
  m_pMainView = this->m_pMainView;
  m_pDrawEntities = m_pMainView->m_pDrawEntities;
  if ( m_pDrawEntities == nullptr
    || (m_pParent = m_pDrawEntities->m_pParent) != nullptr && m_pParent->m_Value.m_nValue != 0 )
  {
    ++m_pMainView->m_BuildRenderableListsNumber;
    *((_BYTE *)&setupInfo + 48) = *((_BYTE *)&setupInfo + 48) & 0xF0 | 3;
    m_pWorldListInfo = this->m_pWorldListInfo;
    if ( m_pWorldListInfo != nullptr )
      setupInfo.m_pWorldListInfo = &m_pWorldListInfo->WorldListInfo_t;
    else
      setupInfo.m_pWorldListInfo = nullptr;
    v9 = this->m_pMainView;
    setupInfo.m_nRenderFrame = v9->m_BuildRenderableListsNumber;
    setupInfo.m_nDetailBuildFrame = v9->BuildWorldListsNumber(this: v9);
    setupInfo.m_pRenderList = this->m_pRenderablesList;
    ClientMode = GetClientMode();
    v11 = ClientMode->ShouldDrawDetailObjects(this: ClientMode)
       && r_DrawDetailProps.m_pParent != nullptr
       && r_DrawDetailProps.m_pParent->m_Value.m_nValue != 0;
    v12 = (*((_BYTE *)&setupInfo + 48) ^ v11) & 1 ^ *((_BYTE *)&setupInfo + 48);
    *((_BYTE *)&setupInfo + 48) = v12;
    v13 = r_flashlightdepth_drawtranslucents.m_pParent != nullptr
       && r_flashlightdepth_drawtranslucents.m_pParent->m_Value.m_nValue != 0
       || viewID != 7;
    setupInfo.m_vecRenderOrigin = this->origin;
    setupInfo.m_vecRenderForward = g_vecCurrentVForward;
    setupInfo.m_nViewID = viewID;
    *((_BYTE *)&setupInfo + 48) = ((v12 ^ (2 * v13)) & 2 ^ v12) & 0xF3
                                | (4 * (bFastEntityRendering | (2 * bDrawDepthViewNonCachedObjectsOnly)));
    m_fValue = cl_maxrenderable_dist.m_pParent->m_Value.m_fValue;
    if ( viewID == 7 && m_fValue > this->zFar )
      m_fValue = this->zFar;
    setupInfo.m_flRenderDistSq = m_fValue * m_fValue;
    g_pClientLeafSystem->BuildRenderablesList(this: g_pClientLeafSystem, a2: &setupInfo);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x1019CA20
// Name: protected: void CRendering3dView::BuildRenderableRenderLists(int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRendering3dView::BuildRenderableRenderLists(
        CRendering3dView *this,
        int viewID,
        bool bFastEntityRendering,
        bool bDrawDepthViewNonCachedObjectsOnly)
{
  IMDLCache *v4; // ebx
  CRendering3dView *v5; // edi
  int v6; // edx
  CClientRenderablesList *m_pRenderablesList; // eax
  char *v8; // edi
  int v9; // ebx
  IClientRenderable *v10; // esi
  struct model_t *v11; // eax
  IMDLCache *cacheCriticalSection; // [esp+10h] [ebp-4h]
  int i; // [esp+1Ch] [ebp+8h]
  int bFastEntityRenderinga; // [esp+20h] [ebp+Ch]
  int bDrawDepthViewNonCachedObjectsOnlya; // [esp+24h] [ebp+10h]

  v4 = mdlcache;
  v5 = this;
  cacheCriticalSection = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  if ( viewID != 7 )
    render->BeginUpdateLightmaps(this: render);
  CRendering3dView::SetupRenderablesList(this: v5, viewID, bFastEntityRendering, bDrawDepthViewNonCachedObjectsOnly);
  if ( viewID != 7 )
  {
    v6 = 98324;
    i = 0;
    bDrawDepthViewNonCachedObjectsOnlya = 0;
    bFastEntityRenderinga = 98324;
    do
    {
      m_pRenderablesList = v5->m_pRenderablesList;
      if ( *(int *)((char *)&m_pRenderablesList->__vftable + v6) > 0 )
      {
        v8 = (char *)&m_pRenderablesList->m_RenderGroups[bDrawDepthViewNonCachedObjectsOnlya][0] + 7;
        v9 = *(int *)((char *)&m_pRenderablesList->__vftable + v6);
        do
        {
          if ( (*v8 & 0x3F) == 3 && (*v8 >= 0 || i == 0) )
          {
            v10 = *(IClientRenderable **)(v8 - 7);
            v11 = v10->GetModel(this: v10);
            render->UpdateBrushModelLightmap(this: render, a2: v11, a3: v10);
          }
          v8 += 8;
          --v9;
        }
        while ( v9 != 0 );
        v4 = cacheCriticalSection;
        v5 = this;
        v6 = bFastEntityRenderinga;
      }
      ++i;
      ++bDrawDepthViewNonCachedObjectsOnlya;
      v6 += 4;
      bFastEntityRenderinga = v6;
    }
    while ( v6 < 98336 );
    render->EndUpdateLightmaps(this: render);
  }
  v4->EndLock(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1019CB20
// Name: protected: void CRendering3dView::DrawWorld(class IMatRenderContext __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRendering3dView::DrawWorld(
        CRendering3dView *this,
        IMatRenderContext *pRenderContext,
        float waterZAdjust)
{
  IVRenderView_vtbl *v4; // edi
  unsigned int v5; // eax
  int v6; // edx

  if ( (_S8_13 & 1) == 0 )
  {
    _S8_13 |= 1u;
    counter_1.m_pCounter = CVProfile::FindOrCreateCounter(
                             this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                             a2: "RenderWorld",
                             a3: COUNTER_GROUP_DEFAULT);
    atexit(func: CRendering3dView::DrawWorld_::_4_::_dynamic_atexit_destructor_for___counter__);
  }
  ++*counter_1.m_pCounter;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "DrawWorld",
    a3: 0,
    a4: "World Rendering",
    a5: false,
    a6: 4);
  if ( r_drawopaqueworld.m_pParent != nullptr && r_drawopaqueworld.m_pParent->m_Value.m_nValue != 0 )
  {
    v4 = render->__vftable;
    v5 = BuildEngineDrawWorldListFlags(nDrawFlags: this->m_DrawFlags);
    ((void (__thiscall *)(int, IMatRenderContext *, IWorldRenderList *, unsigned int, _DWORD))v4->DrawWorldLists)(
      a1: v6,
      a2: pRenderContext,
      a3: this->m_pWorldRenderList,
      a4: v5,
      a5: LODWORD(waterZAdjust));
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019CBF0
// Name: DrawOpaqueRenderables_DrawStaticProps
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawOpaqueRenderables_DrawStaticProps(
        int nCount,
        CClientRenderablesList::CEntry **ppEntities,
        BOOL bShadowDepth)
{
  int v3; // eax
  int v4; // edi
  int v5; // esi
  CClientRenderablesList::CEntry *v6; // ecx
  int m_nValue; // edx
  int v8; // edx
  IClientRenderable *pStatics[512]; // [esp+14h] [ebp-A10h] BYREF
  RenderableInstance_t pInstances[512]; // [esp+814h] [ebp-210h] BYREF
  float one[4]; // [esp+A14h] [ebp-10h] BYREF

  if ( nCount != 0 )
  {
    one[0] = 1.0;
    one[1] = 1.0;
    one[2] = 1.0;
    one[3] = 1.0;
    render->SetColorModulation(this: render, a2: one);
    ((void (__stdcall *)(int))render->SetBlend)(a1: 1065353216);
    v3 = 0;
    v4 = 0;
    v5 = 512;
    if ( nCount > 0 )
    {
      do
      {
        v6 = ppEntities[v4];
        if ( v6->m_pRenderable != nullptr )
        {
          pInstances[v3] = v6->m_InstanceData;
          pStatics[v3] = v6->m_pRenderable;
          --v5;
          ++v3;
          if ( v5 <= 0 )
          {
            if ( vcollide_wireframe.m_pParent != nullptr )
              m_nValue = vcollide_wireframe.m_pParent->m_Value.m_nValue;
            else
              m_nValue = 0;
            staticpropmgr->DrawStaticProps(
              this: staticpropmgr,
              a2: pStatics,
              a3: pInstances,
              a4: v3,
              a5: bShadowDepth,
              a6: m_nValue != 0);
            v3 = 0;
            v5 = 512;
          }
        }
        ++v4;
      }
      while ( v4 < nCount );
      if ( v3 != 0 )
      {
        if ( vcollide_wireframe.m_pParent != nullptr )
          v8 = vcollide_wireframe.m_pParent->m_Value.m_nValue;
        else
          v8 = 0;
        staticpropmgr->DrawStaticProps(
          this: staticpropmgr,
          a2: pStatics,
          a3: pInstances,
          a4: v3,
          a5: bShadowDepth,
          a6: v8 != 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019D140
// Name: public: CFreezeFrameView::CFreezeFrameView(class CViewRender __near *)
// Source: json
//------------------------------------------------------------------------------
CFreezeFrameView *__thiscall CFreezeFrameView::CFreezeFrameView(CFreezeFrameView *this, CViewRender *pMainView)
{
  CBase3dView::CBase3dView(this, pMainView);
  this->m_DrawFlags = 0;
  this->m_ClearFlags = 0;
  this->m_pWorldRenderList = nullptr;
  this->m_pRenderablesList = nullptr;
  this->m_pWorldListInfo = nullptr;
  this->m_pCustomVisibility = nullptr;
  this->__vftable = (CFreezeFrameView_vtbl *)&CFreezeFrameView::`vftable';
  CMaterialReference::CMaterialReference(
    this: &this->m_pFreezeFrame,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_TranslucentSingleColor,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1019D1E0
// Name: public: CReflectiveGlassView::CReflectiveGlassView(class CViewRender __near *)
// Source: json
//------------------------------------------------------------------------------
CReflectiveGlassView *__thiscall CReflectiveGlassView::CReflectiveGlassView(
        CReflectiveGlassView *this,
        CViewRender *pMainView)
{
  CBase3dView::CBase3dView(this, pMainView);
  this->m_DrawFlags = 0;
  this->m_ClearFlags = 0;
  this->m_pWorldRenderList = nullptr;
  this->m_pRenderablesList = nullptr;
  this->m_pWorldListInfo = nullptr;
  this->m_pCustomVisibility = nullptr;
  this->__vftable = (CReflectiveGlassView_vtbl *)&CReflectiveGlassView::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1019D230
// Name: public: CRefractiveGlassView::CRefractiveGlassView(class CViewRender __near *)
// Source: json
//------------------------------------------------------------------------------
CRefractiveGlassView *__thiscall CRefractiveGlassView::CRefractiveGlassView(
        CRefractiveGlassView *this,
        CViewRender *pMainView)
{
  CBase3dView::CBase3dView(this, pMainView);
  this->m_DrawFlags = 0;
  this->m_ClearFlags = 0;
  this->m_pWorldRenderList = nullptr;
  this->m_pRenderablesList = nullptr;
  this->m_pWorldListInfo = nullptr;
  this->m_pCustomVisibility = nullptr;
  this->__vftable = (CRefractiveGlassView_vtbl *)&CRefractiveGlassView::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1019D280
// Name: SetClearColorToFogColor
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int SetClearColorToFogColor()
{
  IMatRenderContext *v0; // esi
  float *v1; // eax
  Vector v3; // [esp+10h] [ebp-18h] BYREF
  unsigned __int8 ucFogColor[8]; // [esp+1Ch] [ebp-Ch] OVERLAPPED BYREF
  float scale; // [esp+24h] [ebp-4h]

  v0 = materials->GetRenderContext(this: materials);
  if ( v0 != nullptr )
    v0->BeginRender(this: v0);
  v0->GetFogColor(this: v0, a2: ucFogColor);
  if ( g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) == HDR_TYPE_INTEGER )
  {
    v1 = (float *)v0->GetToneMappingScaleLinear(this: v0, result: &v3);
    scale = LinearToGammaFullRange(linear: *v1);
    ucFogColor[0] = (int)(float)((float)ucFogColor[0] * scale);
    ucFogColor[1] = (int)(float)((float)ucFogColor[1] * scale);
    ucFogColor[2] = (int)(float)((float)ucFogColor[2] * scale);
  }
  v0->ClearColor4ub(
    this: v0,
    a2: *(_DWORD *)ucFogColor,
    a3: *(_DWORD *)&ucFogColor[1],
    a4: *(_DWORD *)&ucFogColor[2],
    a5: 255u);
  v0->EndRender(this: v0);
  return v0->Release(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x1019D370
// Name: void SetupCurrentView(class Vector const __near &,class QAngle const __near &,enum view_id_t,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall SetupCurrentView(
        int a1@<edi>,
        int a2@<esi>,
        const Vector *vecOrigin,
        const QAngle *angles,
        view_id_t viewID,
        bool bDrawWorldNormal,
        bool bCullFrontFaces)
{
  view_id_t v7; // edi
  void (__thiscall *GetScreenFadeDistances)(IViewRender *, float *, float *); // eax
  IMatRenderContext *v9; // eax
  IMatRenderContext *v10; // esi
  int m_nValue; // eax

  g_vecCurrentRenderOrigin = *vecOrigin;
  g_vecCurrentRenderAngles = *angles;
  ComputeCameraVariables(
    vecOrigin,
    vecAngles: angles,
    pVecForward: &g_vecCurrentVForward,
    pVecRight: &g_vecCurrentVRight,
    pVecUp: &g_vecCurrentVUp,
    pMatCamInverse: &g_matCurrentCamInverse);
  v7 = viewID;
  s_bCanAccessCurrentView = true;
  GetScreenFadeDistances = view->GetScreenFadeDistances;
  g_CurrentViewID = viewID;
  ((void (__thiscall *)(IViewRender *, const QAngle **, const Vector **, int, int))GetScreenFadeDistances)(
    a1: view,
    a2: &angles,
    a3: &vecOrigin,
    a4: a1,
    a5: a2);
  ((void (__thiscall *)(IVModelInfoClient *, const QAngle *, const Vector *))modelinfo->SetViewScreenFadeRange)(
    a1: modelinfo,
    a2: angles,
    a3: vecOrigin);
  v9 = materials->GetRenderContext(this: materials);
  v10 = v9;
  if ( v9 != nullptr )
    v9->BeginRender(this: v9);
  v10->SetIntRenderingParameter(this: v10, a2: 10, a3: (unsigned int)v7 < VIEW_MONITOR);
  if ( bDrawWorldNormal )
    v10->SetIntRenderingParameter(this: v10, a2: 0, a3: 3);
  if ( mat_lpreview_mode.m_pParent != nullptr )
  {
    m_nValue = mat_lpreview_mode.m_pParent->m_Value.m_nValue;
    if ( m_nValue == -1 )
      goto LABEL_10;
  }
  else
  {
    m_nValue = 0;
  }
  v10->SetIntRenderingParameter(this: v10, a2: 0, a3: m_nValue);
LABEL_10:
  if ( bCullFrontFaces )
    v10->FlipCulling(this: v10, a2: true);
  v10->EndRender(this: v10);
  v10->Release(this: v10);
}

//------------------------------------------------------------------------------
// Address: 0x1019D4E0
// Name: protected: bool CViewRender::UpdateRefractIfNeededByList(class CUtlVectorFixedGrowable<struct CViewModelRenderablesList::CEntry,32> __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CViewRender::UpdateRefractIfNeededByList(
        CViewRender *this,
        CUtlVectorFixedGrowable<CViewModelRenderablesList::CEntry,32> *list)
{
  CUtlVectorFixedGrowable<CViewModelRenderablesList::CEntry,32> *v2; // ebx
  int m_Size; // edi
  int v4; // esi
  IMatRenderContext *v6; // eax
  int v7; // esi
  int x; // [esp+Ch] [ebp-Ch] BYREF
  int y; // [esp+10h] [ebp-8h] BYREF
  int w; // [esp+14h] [ebp-4h] BYREF

  v2 = list;
  m_Size = list->m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  while ( (v2->m_Memory.m_pMemory[v4].m_pRenderable->GetRenderFlags(this: v2->m_Memory.m_pMemory[v4].m_pRenderable) & 1) == 0 )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  v6 = materials->GetRenderContext(this: materials);
  v7 = (int)v6;
  if ( v6 != nullptr )
    v6->BeginRender(this: v6);
  (*(void (__thiscall **)(int, int *, int *, int *, CUtlVectorFixedGrowable<CViewModelRenderablesList::CEntry,32> **))(*(_DWORD *)v7 + 156))(
    a1: v7,
    a2: &x,
    a3: &y,
    a4: &w,
    a5: &list);
  UpdateRefractTexture(a1: m_Size, a2: v7);
  (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 12))(a1: v7);
  (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 4))(a1: v7);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1019D590
// Name: protected: void CViewRender::PerformScreenOverlay(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CViewRender::PerformScreenOverlay(CViewRender *this@<ecx>, int a2@<edi>, int x, int y, int w, int h)
{
  IMaterial *m_pMaterial; // ecx
  IMatRenderContext *v8; // eax
  IMatRenderContext *v9; // esi
  ITexture *PowerOfTwoFrameBufferTexture; // edi
  int v11; // ebx
  int v12; // eax
  IMaterial *v13; // [esp+30h] [ebp-Ch]

  if ( r_drawscreenoverlay.m_pParent != nullptr && r_drawscreenoverlay.m_pParent->m_Value.m_nValue != 0 )
  {
    m_pMaterial = this->m_ScreenOverlayMaterial.m_pMaterial;
    if ( m_pMaterial != nullptr )
    {
      if ( m_pMaterial->NeedsFullFrameBufferTexture(this: m_pMaterial, a2: true) )
      {
        DrawScreenEffectMaterial(pMaterial: this->m_ScreenOverlayMaterial.m_pMaterial, x, y, w, h);
      }
      else if ( this->m_ScreenOverlayMaterial.m_pMaterial->NeedsPowerOfTwoFrameBufferTexture(
                  this: this->m_ScreenOverlayMaterial.m_pMaterial,
                  a2: true) )
      {
        UpdateRefractTexture(a1: a2, a2: (int)this);
        v8 = materials->GetRenderContext(this: materials);
        v9 = v8;
        if ( v8 != nullptr )
          v8->BeginRender(this: v8);
        PowerOfTwoFrameBufferTexture = GetPowerOfTwoFrameBufferTexture();
        v11 = PowerOfTwoFrameBufferTexture->GetActualWidth(this: PowerOfTwoFrameBufferTexture);
        v12 = PowerOfTwoFrameBufferTexture->GetActualHeight(this: PowerOfTwoFrameBufferTexture);
        ((void (__thiscall *)(IMatRenderContext *, IMaterial *, int, int, int, int, _DWORD, _DWORD, float, float, int, int, _DWORD, int, int))v9->DrawScreenSpaceRectangle)(
          a1: v9,
          a2: this->m_ScreenOverlayMaterial.m_pMaterial,
          a3: x,
          a4: y,
          a5: w,
          a6: h,
          a7: 0,
          a8: 0,
          a9: (float)(v11 - 1),
          a10: (float)(v12 - 1),
          a11: v11,
          a12: v12,
          a13: 0,
          a14: 1,
          a15: 1);
        v9->EndRender(this: v9);
        v9->Release(this: v9);
      }
      else
      {
        v13 = this->m_ScreenOverlayMaterial.m_pMaterial;
        h = -1;
        render->ViewDrawFade(this: render, a2: (unsigned __int8 *)&h, a3: v13);
      }
    }
  }
  else if ( this->m_ScreenOverlayMaterial.m_pMaterial != nullptr && !s_bPrintedWarning )
  {
    s_bPrintedWarning = true;
    _Warning(a1: "****** CViewRender::PerformScreenOverlay: Screen overlay wants to render, but it's been disabled!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019D730
// Name: protected: void CViewRender::DrawUnderwaterOverlay(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CViewRender::DrawUnderwaterOverlay(CViewRender *this@<ecx>, int a2@<ebx>, int a3@<edi>, int a4@<esi>)
{
  IMaterial *m_pMaterial; // ebx
  float v5; // esi
  IMatRenderContext *v6; // eax
  IMatRenderContext *v7; // esi
  ITexture *PowerOfTwoFrameBufferTexture; // edi
  int v9; // eax
  IMatRenderContext_vtbl *v10; // edx
  void (__thiscall *DrawScreenSpaceRectangle)(IMatRenderContext *, IMaterial *, int, int, int, int, float, float, float, float, int, int, void *, int, int); // edx
  CMatRenderContextPtr pRenderContext; // [esp+48h] [ebp-18h]
  int sw; // [esp+4Ch] [ebp-14h]
  int x; // [esp+50h] [ebp-10h] BYREF
  int y; // [esp+54h] [ebp-Ch] BYREF
  int w; // [esp+58h] [ebp-8h] BYREF
  int h; // [esp+5Ch] [ebp-4h] BYREF
  int savedregs; // [esp+60h] [ebp+0h]

  if ( r_drawunderwateroverlay.m_pParent != nullptr && r_drawunderwateroverlay.m_pParent->m_Value.m_nValue != 0 )
  {
    m_pMaterial = this->m_UnderWaterOverlayMaterial.m_pMaterial;
    if ( m_pMaterial != nullptr )
    {
      v5 = COERCE_FLOAT(
             ((int (__thiscall *)(IMaterialSystem *, int, int))materials->GetRenderContext)(
               a1: materials,
               a2: a4,
               a3: a2));
      pRenderContext.m_pObject = (IMatRenderContext *)LODWORD(v5);
      if ( v5 != 0.0 )
        (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(v5) + 8))(a1: COERCE_FLOAT(LODWORD(v5)));
      (*(void (__thiscall **)(float, int *, int *))(*(_DWORD *)LODWORD(v5) + 156))(
        a1: COERCE_FLOAT(LODWORD(v5)),
        a2: &x,
        a3: &y);
      if ( m_pMaterial->NeedsFullFrameBufferTexture(this: m_pMaterial, a2: true) )
      {
        DrawScreenEffectMaterial(pMaterial: m_pMaterial, x, y, w, h);
      }
      else if ( ((unsigned __int8 (__thiscall *)(IMaterial *, int, int *, int *))m_pMaterial->NeedsPowerOfTwoFrameBufferTexture)(
                  a1: m_pMaterial,
                  a2: 1,
                  a3: &w,
                  a4: &h) != 0 )
      {
        UpdateRefractTexture(a1: a3, a2: SLODWORD(v5));
        v6 = materials->GetRenderContext(this: materials);
        v7 = v6;
        if ( v6 != nullptr )
          v6->BeginRender(this: v6);
        PowerOfTwoFrameBufferTexture = GetPowerOfTwoFrameBufferTexture();
        sw = ((int (__thiscall *)(ITexture *, int))PowerOfTwoFrameBufferTexture->GetActualWidth)(
               a1: PowerOfTwoFrameBufferTexture,
               a2: a3);
        v9 = PowerOfTwoFrameBufferTexture->GetActualHeight(this: PowerOfTwoFrameBufferTexture);
        savedregs = 1;
        v10 = v7->__vftable;
        h = 1;
        DrawScreenSpaceRectangle = v10->DrawScreenSpaceRectangle;
        w = 0;
        y = v9;
        x = sw;
        ((void (__thiscall *)(IMatRenderContext *, IMaterial *, int, int, _DWORD, int, _DWORD, _DWORD))DrawScreenSpaceRectangle)(
          a1: v7,
          a2: m_pMaterial,
          a3: sw,
          a4: v9,
          a5: 0,
          a6: 1,
          a7: 0,
          a8: 0);
        v7->EndRender(this: v7);
        v7->Release(this: v7);
        v5 = (float)(sw - 1);
      }
      else
      {
        (*(void (__thiscall **)(float, IMaterial *, int, int, int, int, _DWORD, _DWORD, int, int, int, int, _DWORD))(*(_DWORD *)LODWORD(v5) + 420))(
          a1: COERCE_FLOAT(LODWORD(v5)),
          a2: m_pMaterial,
          a3: x,
          a4: y,
          a5: w,
          a6: h,
          a7: 0,
          a8: 0,
          a9: 1065353216,
          a10: 1065353216,
          a11: 1,
          a12: 1,
          a13: 0);
      }
      (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(v5) + 12))(a1: COERCE_FLOAT(LODWORD(v5)));
      (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(v5) + 4))(a1: COERCE_FLOAT(LODWORD(v5)));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019D900
// Name: GetFogColor
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetFogColor(fogparams_t *pFogParams, float *pColor, bool ignoreOverride, bool ignoreHDRColorScale)
{
  fogparams_t *v4; // ecx
  float m_fValue; // xmm1_4
  char v6; // dl
  float *v7; // esi
  float *v8; // edi
  float *v9; // ebx
  char *m_pszString; // eax
  int g; // eax
  int b; // edx
  float v13; // xmm0_4
  int r; // eax
  float v15; // xmm0_4
  int v16; // edx
  float v17; // xmm0_4
  int v18; // eax
  float z; // eax
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  Vector forward; // [esp+0h] [ebp-38h] BYREF
  float flSecondaryColor[3]; // [esp+Ch] [ebp-2Ch] BYREF
  Vector vNormalized; // [esp+18h] [ebp-20h] BYREF
  float flPrimaryColor[3]; // [esp+24h] [ebp-14h] BYREF
  C_BasePlayer *pbp; // [esp+30h] [ebp-8h]
  float HDRColorScale; // [esp+34h] [ebp-4h]

  pbp = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( pbp == nullptr )
    return;
  v4 = pFogParams;
  if ( pFogParams == nullptr )
    return;
  if ( fog_override.m_pParent != nullptr && fog_override.m_pParent->m_Value.m_nValue != 0 && !ignoreOverride )
  {
    m_fValue = fog_hdrcolorscale.m_pParent->m_Value.m_fValue;
    v6 = 1;
    if ( m_fValue != -1.0 )
      goto LABEL_8;
  }
  else
  {
    v6 = 0;
  }
  m_fValue = pFogParams->HDRColorScale.m_Value;
LABEL_8:
  v7 = pColor;
  v8 = pColor + 2;
  v9 = pColor + 1;
  pColor[2] = -1.0;
  pColor[1] = -1.0;
  *pColor = -1.0;
  HDRColorScale = m_fValue;
  if ( (fog_color.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = fog_color.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)prType;
  }
  if ( v6 == 0 || m_pszString == nullptr )
    goto LABEL_17;
  sscanf(string: m_pszString, format: "%f %f %f", pColor, v9, v8);
  if ( *pColor == -1.0 )
  {
    v4 = pFogParams;
LABEL_17:
    if ( *v9 == -1.0 && *v8 == -1.0 )
    {
      g = v4->colorPrimary.m_Value.g;
      b = v4->colorPrimary.m_Value.b;
      flPrimaryColor[0] = (float)v4->colorPrimary.m_Value.r;
      v13 = (float)g;
      r = v4->colorSecondary.m_Value.r;
      flPrimaryColor[1] = v13;
      v15 = (float)b;
      v16 = v4->colorSecondary.m_Value.g;
      flPrimaryColor[2] = v15;
      v17 = (float)r;
      v18 = v4->colorSecondary.m_Value.b;
      flSecondaryColor[0] = v17;
      flSecondaryColor[1] = (float)v16;
      flSecondaryColor[2] = (float)v18;
      GetFogColorTransition(pColorPrimary: flPrimaryColor, pColorSecondary: flSecondaryColor, pFogParams: v4);
      if ( pFogParams->blend.m_Value )
      {
        C_BasePlayer::EyeVectors(this: pbp, pForward: &forward, pRight: nullptr, pUp: nullptr);
        z = pFogParams->dirPrimary.m_Value.z;
        *(_QWORD *)&vNormalized.x = *(_QWORD *)&pFogParams->dirPrimary.m_Value.x;
        vNormalized.z = z;
        VectorNormalize(vec: &vNormalized);
        if ( vNormalized.x != pFogParams->dirPrimary.m_Value.x
          || vNormalized.y != pFogParams->dirPrimary.m_Value.y
          || vNormalized.z != pFogParams->dirPrimary.m_Value.z )
        {
          pFogParams->NetworkStateChanged(this: pFogParams, a2: &pFogParams->dirPrimary);
          pFogParams->dirPrimary.m_Value = vNormalized;
        }
        v20 = (float)((float)((float)((float)(pFogParams->dirPrimary.m_Value.x * forward.x)
                                    + (float)(forward.y * pFogParams->dirPrimary.m_Value.y))
                            + (float)(pFogParams->dirPrimary.m_Value.z * forward.z))
                    + 1.0)
            * 0.5;
        *pColor = (float)((float)(1.0 - v20) * flSecondaryColor[0]) + (float)(v20 * flPrimaryColor[0]);
        v21 = (float)((float)(1.0 - v20) * flSecondaryColor[2]) + (float)(v20 * flPrimaryColor[2]);
        *v9 = (float)((float)(1.0 - v20) * flSecondaryColor[1]) + (float)(v20 * flPrimaryColor[1]);
        *v8 = v21;
        v7 = pColor;
      }
      else
      {
        *pColor = flPrimaryColor[0];
        *v9 = flPrimaryColor[1];
        *v8 = flPrimaryColor[2];
      }
    }
  }
  if ( !ignoreHDRColorScale
    && g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) != HDR_TYPE_NONE )
  {
    v22 = HDRColorScale;
    *v7 = *v7 * HDRColorScale;
    *v9 = *v9 * v22;
    *v8 = *v8 * v22;
  }
  *v7 = *v7 * 0.0039215689;
  *v9 = *v9 * 0.0039215689;
  *v8 = *v8 * 0.0039215689;
}

//------------------------------------------------------------------------------
// Address: 0x1019DC20
// Name: GetSkyboxFogColor
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetSkyboxFogColor(float *pColor, bool ignoreOverride, bool ignoreHDRColorScale)
{
  C_BasePlayer *LocalPlayer; // edi
  float m_fValue; // xmm1_4
  char v5; // dl
  float *v6; // esi
  float *v7; // ecx
  float *v8; // ebx
  char *m_pszString; // eax
  float z; // edx
  float v11; // xmm0_4
  float *v12; // eax
  float v13; // xmm0_4
  float *v14; // eax
  Vector forward; // [esp+4h] [ebp-20h] BYREF
  Vector vNormalized; // [esp+10h] [ebp-14h] BYREF
  float HDRColorScale; // [esp+1Ch] [ebp-8h]
  float *v18; // [esp+20h] [ebp-4h]

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer == nullptr )
    return;
  if ( fog_override.m_pParent == nullptr || fog_override.m_pParent->m_Value.m_nValue == 0 || ignoreOverride )
  {
    v5 = 0;
    goto LABEL_6;
  }
  m_fValue = fog_hdrcolorscaleskybox.m_pParent->m_Value.m_fValue;
  v5 = 1;
  if ( m_fValue == -1.0 )
LABEL_6:
    m_fValue = LocalPlayer->m_Local.m_skybox3d.fog.HDRColorScale.m_Value;
  v6 = pColor;
  v7 = pColor + 1;
  v8 = pColor + 2;
  pColor[2] = -1.0;
  pColor[1] = -1.0;
  *pColor = -1.0;
  HDRColorScale = m_fValue;
  v18 = pColor + 1;
  if ( (fog_colorskybox.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = fog_colorskybox.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)prType;
  }
  if ( v5 == 0
    || m_pszString == nullptr
    || (sscanf(string: m_pszString, format: "%f %f %f", pColor, v7, v8), v7 = v18, *pColor == -1.0) )
  {
    if ( *v7 == -1.0 && *v8 == -1.0 )
    {
      if ( LocalPlayer->m_Local.m_skybox3d.fog.blend.m_Value )
      {
        C_BasePlayer::EyeVectors(this: LocalPlayer, pForward: &forward, pRight: nullptr, pUp: nullptr);
        z = LocalPlayer->m_Local.m_skybox3d.fog.dirPrimary.m_Value.z;
        *(_QWORD *)&vNormalized.x = *(_QWORD *)&LocalPlayer->m_Local.m_skybox3d.fog.dirPrimary.m_Value.x;
        vNormalized.z = z;
        VectorNormalize(vec: &vNormalized);
        if ( vNormalized.x != LocalPlayer->m_Local.m_skybox3d.fog.dirPrimary.m_Value.x
          || vNormalized.y != LocalPlayer->m_Local.m_skybox3d.fog.dirPrimary.m_Value.y
          || vNormalized.z != LocalPlayer->m_Local.m_skybox3d.fog.dirPrimary.m_Value.z )
        {
          LocalPlayer->m_Local.m_skybox3d.fog.NetworkStateChanged(
            this: &LocalPlayer->m_Local.m_skybox3d.fog,
            a2: &LocalPlayer->m_Local.m_skybox3d.fog.dirPrimary);
          LocalPlayer->m_Local.m_skybox3d.fog.dirPrimary.m_Value = vNormalized;
        }
        v6 = pColor;
        v11 = (float)((float)((float)((float)(LocalPlayer->m_Local.m_skybox3d.fog.dirPrimary.m_Value.y * forward.y)
                                    + (float)(LocalPlayer->m_Local.m_skybox3d.fog.dirPrimary.m_Value.x * forward.x))
                            + (float)(LocalPlayer->m_Local.m_skybox3d.fog.dirPrimary.m_Value.z * forward.z))
                    + 1.0)
            * 0.5;
        *pColor = (float)((float)LocalPlayer->m_Local.m_skybox3d.fog.colorSecondary.m_Value.r * (float)(1.0 - v11))
                + (float)((float)LocalPlayer->m_Local.m_skybox3d.fog.colorPrimary.m_Value.r * v11);
        v12 = v18;
        *v18 = (float)((float)LocalPlayer->m_Local.m_skybox3d.fog.colorSecondary.m_Value.g * (float)(1.0 - v11))
             + (float)((float)LocalPlayer->m_Local.m_skybox3d.fog.colorPrimary.m_Value.g * v11);
        *v8 = (float)((float)LocalPlayer->m_Local.m_skybox3d.fog.colorSecondary.m_Value.b * (float)(1.0 - v11))
            + (float)((float)LocalPlayer->m_Local.m_skybox3d.fog.colorPrimary.m_Value.b * v11);
        v7 = v12;
      }
      else
      {
        *pColor = (float)LocalPlayer->m_Local.m_skybox3d.fog.colorPrimary.m_Value.r;
        *v7 = (float)LocalPlayer->m_Local.m_skybox3d.fog.colorPrimary.m_Value.g;
        *v8 = (float)LocalPlayer->m_Local.m_skybox3d.fog.colorPrimary.m_Value.b;
      }
    }
  }
  if ( !ignoreHDRColorScale )
  {
    if ( g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) != HDR_TYPE_NONE )
    {
      v13 = HDRColorScale;
      v14 = v18;
      *v6 = *v6 * HDRColorScale;
      *v14 = *v14 * v13;
      *v8 = *v8 * v13;
      v7 = v14;
    }
    else
    {
      v7 = v18;
    }
  }
  *v6 = *v6 * 0.0039215689;
  *v7 = *v7 * 0.0039215689;
  *v8 = *v8 * 0.0039215689;
}

//------------------------------------------------------------------------------
// Address: 0x1019DF40
// Name: protected: void CViewRender::DrawLetterBoxRectangles(int,class CUtlVector<struct vrect_t,class CUtlMemory<struct vrect_t,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRender::DrawLetterBoxRectangles(
        CViewRender *this,
        int nSlot,
        const CUtlVector<vrect_t,CUtlMemory<vrect_t,int> > *vecLetterBoxRectangles)
{
  IMatRenderContext *v4; // esi
  IMesh *v5; // esi
  int m_Size; // ebx
  int v8; // ebx
  float *m_pCurrPosition; // eax
  vrect_t *v10; // esi
  float y; // xmm1_4
  float *v12; // eax
  float *v13; // eax
  float v14; // xmm0_4
  float *v15; // eax
  float *v16; // eax
  float v17; // xmm0_4
  float *v18; // eax
  float *v19; // eax
  float v20; // xmm0_4
  float *v21; // eax
  int m_nVertexCount; // eax
  IMatRenderContext *m_pObject; // esi
  CMeshBuilder meshBuilder; // [esp+8h] [ebp-1F0h] BYREF
  IMesh *pMesh; // [esp+1F0h] [ebp-8h]
  CMatRenderContextPtr pRenderContext; // [esp+1F4h] [ebp-4h]
  const CUtlVector<vrect_t,CUtlMemory<vrect_t,int> > *vecLetterBoxRectanglesb; // [esp+204h] [ebp+Ch]
  const CUtlVector<vrect_t,CUtlMemory<vrect_t,int> > *vecLetterBoxRectanglesa; // [esp+204h] [ebp+Ch]

  v4 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v4;
  if ( v4 != nullptr )
    v4->BeginRender(this: v4);
  v4->Bind(this: v4, a2: this->m_WhiteMaterial.m_pMaterial, a3: nullptr);
  v5 = v4->GetDynamicMesh(this: v4, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
  pMesh = v5;
  CMeshBuilder::CMeshBuilder(this: &meshBuilder);
  m_Size = vecLetterBoxRectangles->m_Size;
  meshBuilder.m_pMesh = v5;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_QUADS;
  vecLetterBoxRectanglesb = (const CUtlVector<vrect_t,CUtlMemory<vrect_t,int> > *)(4 * m_Size);
  m_Size *= 6;
  v5->SetPrimitiveType(this: v5, a2: MATERIAL_TRIANGLES);
  meshBuilder.m_pMesh->LockMesh(
    this: meshBuilder.m_pMesh,
    a2: (int)vecLetterBoxRectanglesb,
    a3: m_Size,
    a4: &meshBuilder,
    a5: nullptr);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v5->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = m_Size;
  CVertexBuilder::AttachBegin(
    this: &meshBuilder.m_VertexBuilder,
    pMesh: v5,
    nMaxVertexCount: (int)vecLetterBoxRectanglesb,
    desc: &meshBuilder);
  v8 = 0;
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
  if ( vecLetterBoxRectangles->m_Size > 0 )
  {
    vecLetterBoxRectanglesa = nullptr;
    do
    {
      m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      v10 = (vrect_t *)((char *)vecLetterBoxRectanglesa + (unsigned int)vecLetterBoxRectangles->m_Memory.m_pMemory);
      y = (float)v10->y;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)v10->x;
      m_pCurrPosition[1] = y;
      m_pCurrPosition[2] = -99999.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16777216;
      v12 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
      v12[1] = 0.0;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v13 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      v14 = (float)v10->y;
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(v10->x + v10->width);
      v13[1] = v14;
      v13[2] = -99999.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16777216;
      v15 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
      v15[1] = 0.0;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v16 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      v17 = (float)(v10->y + v10->height);
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)(v10->x + v10->width);
      v16[1] = v17;
      v16[2] = -99999.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16777216;
      v18 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
      v18[1] = 0.0;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      v19 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
      v20 = (float)(v10->y + v10->height);
      *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)v10->x;
      v19[1] = v20;
      v19[2] = -99999.0;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = -16777216;
      v21 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
      *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
      v21[1] = 0.0;
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
      ++vecLetterBoxRectanglesa;
      ++v8;
    }
    while ( v8 < vecLetterBoxRectangles->m_Size );
    v5 = pMesh;
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
  meshBuilder.m_pMesh = nullptr;
  v5->Draw_2(this: v5, a2: -1, a3: 0);
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
// Address: 0x1019E2F0
// Name: protected: void CViewRender::CleanupMain3DView(class CViewSetup const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRender::CleanupMain3DView(CViewRender *this, const CViewSetup *view)
{
  IMatRenderContext *v3; // esi
  IVRenderView_vtbl *v4; // ebx
  VPlane *v5; // eax

  v3 = materials->GetRenderContext(this: materials);
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  if ( g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) == HDR_TYPE_FLOAT )
    v3->SetIntRenderingParameter(this: v3, a2: 11, a3: 0);
  v4 = render->__vftable;
  v5 = this->GetFrustum(this);
  v4->PopView(this: render, a2: v3, a3: v5);
  if ( v3 != nullptr )
  {
    v3->EndRender(this: v3);
    v3->Release(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019E380
// Name: void ParticleUsageDemo(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall ParticleUsageDemo(int a1@<edi>)
{
  int v1; // ebx
  CNonDrawingParticleSystem *NonDrawingEffect; // eax
  CParticleMgr *v3; // eax
  CParticleCollection *m_pSystem; // edi
  float *v5; // esi
  int v6; // ecx
  int v7; // edx
  int v8; // eax
  int v9; // esi
  CNonDrawingParticleSystem *v10; // esi
  float vecColor; // [esp+8h] [ebp-14h]
  float vecColor_4; // [esp+Ch] [ebp-10h]
  float vecColor_8; // [esp+10h] [ebp-Ch]
  float flRadius; // [esp+14h] [ebp-8h]
  int v16; // [esp+18h] [ebp-4h]

  v1 = 0;
  if ( r_particle_demo.m_pParent != nullptr && r_particle_demo.m_pParent->m_Value.m_nValue != 0 )
  {
    NonDrawingEffect = s_pDemoSystem;
    if ( s_pDemoSystem == nullptr )
    {
      v3 = ParticleMgr();
      NonDrawingEffect = CParticleMgr::CreateNonDrawingEffect(this: v3, pEffectName: "christest");
      s_pDemoSystem = NonDrawingEffect;
    }
    m_pSystem = NonDrawingEffect->m_pSystem;
    if ( m_pSystem->m_nActiveParticles > 0 )
    {
      v16 = 0;
      do
      {
        v5 = m_pSystem->m_ParticleAttributes.m_pAttributes[6];
        v6 = v1 & 3;
        v7 = v6 + 12 * (v1 / 4);
        vecColor = v5[v7] * 255.0;
        vecColor_4 = v5[v7 + 4] * 255.0;
        vecColor_8 = v5[v7 + 8] * 255.0;
        flRadius = m_pSystem->m_ParticleAttributes.m_pAttributes[3][v6
                                                                  + v1
                                                                  / 4
                                                                  * m_pSystem->m_ParticleAttributes.m_nFloatStrides[3]];
        v8 = ((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(a1: materials, a2: a1);
        v9 = v8;
        if ( v8 != 0 )
          (*(void (__thiscall **)(int))(*(_DWORD *)v8 + 8))(a1: v8);
        a1 = 255;
        (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v9 + 296))(
          a1: v9,
          a2: (unsigned __int8)(int)vecColor,
          a3: (unsigned __int8)(int)vecColor_4,
          a4: (unsigned __int8)(int)vecColor_8);
        (*(void (__thiscall **)(int, _DWORD, int, int, int))(*(_DWORD *)v9 + 152))(
          a1: v9,
          a2: 0,
          a3: v16,
          a4: (int)flRadius,
          a5: 17);
        (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v9 + 48))(a1: v9, a2: 1, a3: 1, a4: 0);
        (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 12))(a1: v9);
        (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 4))(a1: v9);
        v16 += 20;
        ++v1;
      }
      while ( v1 < m_pSystem->m_nActiveParticles );
    }
  }
  else if ( s_pDemoSystem != nullptr )
  {
    v10 = s_pDemoSystem;
    CNonDrawingParticleSystem::~CNonDrawingParticleSystem(this: s_pDemoSystem);
    C_BaseEntity::operator delete(pMem: v10);
    s_pDemoSystem = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019E500
// Name: SetLightmapScaleForWater
// Source: json
//------------------------------------------------------------------------------
HDRType_t __usercall SetLightmapScaleForWater@<eax>(int a1@<esi>)
{
  HDRType_t result; // eax
  int v2; // esi
  _BYTE v3[12]; // [esp+0h] [ebp-18h] BYREF
  Vector t25; // [esp+Ch] [ebp-Ch] BYREF

  result = g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig);
  if ( result == HDR_TYPE_INTEGER )
  {
    v2 = ((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(a1: materials, a2: a1);
    if ( v2 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 8))(a1: v2);
    s_vSavedLinearLightMapScale = *(Vector *)(*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v2 + 580))(a1: v2, a2: v3);
    t25.x = s_vSavedLinearLightMapScale.x * 0.25;
    t25.y = s_vSavedLinearLightMapScale.y * 0.25;
    t25.z = s_vSavedLinearLightMapScale.z * 0.25;
    (*(void (__thiscall **)(int, Vector *))(*(_DWORD *)v2 + 576))(a1: v2, a2: &t25);
    (*(void (__thiscall **)(int))(*(_DWORD *)v2 + 12))(a1: v2);
    return (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 4))(a1: v2);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019E5E0
// Name: bool DoesViewPlaneIntersectWater(float,int)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
bool __usercall DoesViewPlaneIntersectWater@<al>(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        float waterZ,
        int leafWaterDataID)
{
  int v6; // esi
  Vector *v7; // edi
  int i; // ebx
  bool v9; // bl
  VMatrix inverseViewProjectionMatrix; // [esp+0h] [ebp-158h] BYREF
  VMatrix viewMatrix; // [esp+40h] [ebp-118h] BYREF
  VMatrix viewProjectionMatrix; // [esp+80h] [ebp-D8h] BYREF
  VMatrix projectionMatrix; // [esp+C0h] [ebp-98h] BYREF
  Vector worldPos; // [esp+100h] [ebp-58h] BYREF
  Vector testPoint[4]; // [esp+10Ch] [ebp-4Ch] BYREF
  Vector mins; // [esp+13Ch] [ebp-1Ch] BYREF
  Vector maxs; // [esp+148h] [ebp-10h] BYREF
  bool bBelow; // [esp+156h] [ebp-2h]
  bool bAbove; // [esp+157h] [ebp-1h]

  if ( leafWaterDataID == -1 )
    return false;
  v6 = ((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(a1: materials, a2: a3);
  if ( v6 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
  (*(void (__thiscall **)(int, _DWORD, VMatrix *, int, int))(*(_DWORD *)v6 + 120))(
    a1: v6,
    a2: 0,
    a3: &viewMatrix,
    a4: a2,
    a5: a1);
  (*(void (__thiscall **)(int, int, VMatrix *))(*(_DWORD *)v6 + 120))(a1: v6, a2: 1, a3: &projectionMatrix);
  MatrixMultiply(src1: &projectionMatrix, src2: &viewMatrix, dst: &viewProjectionMatrix);
  MatrixInverseGeneral(src: &viewProjectionMatrix, dst: &inverseViewProjectionMatrix);
  ClearBounds(&mins, &maxs);
  testPoint[0].x = -1.0;
  testPoint[0].y = -1.0;
  testPoint[0].z = 0.0;
  testPoint[1].x = -1.0;
  testPoint[1].y = 1.0;
  testPoint[1].z = 0.0;
  testPoint[2].x = 1.0;
  testPoint[2].y = -1.0;
  testPoint[2].z = 0.0;
  testPoint[3].x = 1.0;
  testPoint[3].y = 1.0;
  testPoint[3].z = 0.0;
  bAbove = false;
  bBelow = false;
  v7 = testPoint;
  for ( i = 4; i != 0; --i )
  {
    Vector3DMultiplyPositionProjective(src1: &inverseViewProjectionMatrix, src2: v7, dst: &worldPos);
    AddPointToBounds(v: &worldPos, &mins, &maxs);
    if ( (float)(worldPos.z + 7.0) > waterZ )
      bAbove = true;
    if ( waterZ > (float)(worldPos.z - 7.0) )
      bBelow = true;
    ++v7;
  }
  if ( bAbove && bBelow )
  {
    mins.x = mins.x - 7.0;
    mins.y = mins.y - 7.0;
    mins.z = mins.z - 7.0;
    maxs.x = maxs.x + 7.0;
    maxs.y = maxs.y + 7.0;
    maxs.z = maxs.z + 7.0;
    v9 = render->DoesBoxIntersectWaterVolume(this: render, a2: &mins, a3: &maxs, a4: leafWaterDataID);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
    return v9;
  }
  else
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019E800
// Name: public: void CRendering3dView::Setup(class CViewSetup const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRendering3dView::Setup(CRendering3dView *this, const CViewSetup *setup)
{
  CViewSetup *v3; // edi
  CClientRenderablesList *v4; // eax

  if ( this != nullptr )
    v3 = &this->CViewSetup;
  else
    v3 = nullptr;
  qmemcpy(v3, setup, sizeof(CViewSetup));
  CRendering3dView::ReleaseLists(this);
  v4 = (CClientRenderablesList *)CUtlMemoryPool::Alloc(this: &CClientRenderablesList::s_Allocator, amount: 0x18124u);
  if ( v4 != nullptr )
  {
    v4->m_iRefs = 1;
    v4->__vftable = (CClientRenderablesList_vtbl *)&CClientRenderablesList::`vftable';
    v4->m_RenderGroupCounts[0] = 0;
    v4->m_RenderGroupCounts[1] = 0;
    v4->m_RenderGroupCounts[2] = 0;
    v4->m_nBoneSetupDependencyCount = 0;
    this->m_pCustomVisibility = nullptr;
    this->m_pRenderablesList = v4;
  }
  else
  {
    this->m_pCustomVisibility = nullptr;
    this->m_pRenderablesList = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019E890
// Name: DrawClippedDepthBox
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall DrawClippedDepthBox(
        IClientRenderable *pEnt@<ecx>,
        float *pClipPlane@<eax>,
        int a3@<ebx>,
        int a4@<edi>,
        int a5@<esi>)
{
  float *v6; // ecx
  void (__thiscall *GetRenderBounds)(IClientRenderable *, Vector *, Vector *); // edx
  IMatRenderContext *v8; // xmm0_4
  const Vector *v9; // eax
  __int64 v10; // xmm0_8
  IClientRenderable_vtbl *v11; // edx
  const QAngle *(__thiscall *GetRenderAngles)(IClientRenderable *); // eax
  float y; // xmm1_4
  float z; // xmm2_4
  float v15; // xmm4_4
  float *v16; // xmm2_4
  float v17; // xmm7_4
  float *v18; // xmm1_4
  IMatRenderContext *m_pObject; // xmm5_4
  float *v20; // xmm3_4
  float *p_z; // ecx
  int i; // eax
  float v23; // xmm0_4
  const int *v24; // ebx
  int v25; // eax
  int v26; // ecx
  int v27; // esi
  int v28; // edx
  bool v29; // zf
  int v30; // esi
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm4_4
  float v34; // xmm5_4
  float v35; // xmm1_4
  float v36; // xmm3_4
  float v37; // xmm6_4
  float x; // xmm0_4
  Vector *v39; // edx
  int v40; // eax
  float v41; // xmm0_4
  float v42; // xmm1_4
  float v43; // xmm2_4
  float v44; // xmm0_4
  float v45; // xmm2_4
  float v46; // xmm5_4
  float v47; // xmm4_4
  float v48; // xmm1_4
  float *p_x; // edx
  float v50; // xmm0_4
  float *v51; // ecx
  IMatRenderContext *v52; // eax
  IMatRenderContext *v53; // esi
  IMesh *v54; // ebx
  void (__thiscall *SetPrimitiveType)(IMesh *, MaterialPrimitiveType_t); // edx
  Vector *v56; // edi
  const int *v57; // eax
  int v58; // edx
  int v59; // esi
  int v60; // ebx
  int v61; // ecx
  int v62; // ebx
  int v63; // edi
  Vector *v64; // esi
  int v65; // edx
  const int *v66; // eax
  int v67; // esi
  int v68; // eax
  int v69; // ebx
  int v70; // ebx
  Vector *v71; // eax
  int v72; // edx
  int v73; // ebx
  int v74; // esi
  float *m_pCurrPosition; // eax
  float *v76; // eax
  float *v77; // ecx
  float *v78; // eax
  float *v79; // ecx
  int m_nVertexCount; // eax
  IMatRenderContext *v81; // esi
  Vector vSplitPoints[8][8]; // [esp+0h] [ebp-734h] BYREF
  int iLineStates[8][8]; // [esp+300h] [ebp-434h]
  int iClipped[8]; // [esp+400h] [ebp-334h]
  CMeshBuilder meshBuilder; // [esp+420h] [ebp-314h] BYREF
  QAngle qAngles; // [esp+608h] [ebp-12Ch] BYREF
  Vector vMaxs; // [esp+614h] [ebp-120h] BYREF
  Vector vMins; // [esp+620h] [ebp-114h] BYREF
  Vector vPoints[8]; // [esp+62Ch] [ebp-108h] BYREF
  Vector vUp; // [esp+68Ch] [ebp-A8h] BYREF
  Vector vForward; // [esp+698h] [ebp-9Ch] BYREF
  Vector vRight; // [esp+6A4h] [ebp-90h] BYREF
  Vector vNormal; // [esp+6B0h] [ebp-84h]
  float *pTriangleFanPoints[4]; // [esp+6C0h] [ebp-74h]
  float v97; // [esp+6D0h] [ebp-64h]
  float v98; // [esp+6D4h] [ebp-60h]
  float v99; // [esp+6D8h] [ebp-5Ch]
  float v100; // [esp+6DCh] [ebp-58h]
  float v101; // [esp+6E0h] [ebp-54h]
  float v102; // [esp+6E4h] [ebp-50h]
  float v103; // [esp+6E8h] [ebp-4Ch]
  float v104; // [esp+6ECh] [ebp-48h]
  CMatRenderContextPtr pRenderContext; // [esp+6F0h] [ebp-44h]
  float v106; // [esp+6F4h] [ebp-40h]
  float v107; // [esp+6F8h] [ebp-3Ch]
  float v108; // [esp+6FCh] [ebp-38h]
  float v109; // [esp+700h] [ebp-34h]
  IMesh *pMesh; // [esp+704h] [ebp-30h]
  float v111; // [esp+708h] [ebp-2Ch]
  float v112; // [esp+70Ch] [ebp-28h]
  float v113; // [esp+710h] [ebp-24h]
  float v114; // [esp+714h] [ebp-20h]
  float v115; // [esp+718h] [ebp-1Ch]
  Vector vOrigin; // [esp+71Ch] [ebp-18h]
  float v117; // [esp+728h] [ebp-Ch]
  float v118; // [esp+72Ch] [ebp-8h]
  float v119; // [esp+730h] [ebp-4h]

  v6 = *((float **)pClipPlane + 2);
  GetRenderBounds = pEnt->GetRenderBounds;
  *(_QWORD *)&pTriangleFanPoints[1] = *(_QWORD *)pClipPlane;
  v8 = *((IMatRenderContext **)pClipPlane + 3);
  pTriangleFanPoints[3] = v6;
  pRenderContext.m_pObject = v8;
  ((void (__thiscall *)(IClientRenderable *, Vector *, Vector *, int, int))GetRenderBounds)(
    a1: pEnt,
    a2: &vMins,
    a3: &vMaxs,
    a4,
    a5);
  v9 = pEnt->GetRenderOrigin(this: pEnt);
  v10 = *(_QWORD *)&v9->x;
  v11 = pEnt->__vftable;
  vOrigin.z = v9->z;
  GetRenderAngles = v11->GetRenderAngles;
  *(_QWORD *)&vOrigin.x = v10;
  qAngles = *GetRenderAngles(this: pEnt);
  AngleVectors(angles: &qAngles, forward: &vForward, right: &vRight, up: &vUp);
  v97 = vRight.x * vMins.y;
  v100 = vRight.y * vMins.y;
  v98 = vRight.z * vMins.y;
  v101 = vForward.x * vMins.x;
  v99 = vForward.y * vMins.x;
  *(float *)&pMesh = vForward.z * vMins.x;
  *(float *)&v10 = vOrigin.x;
  y = vOrigin.y;
  z = vOrigin.z;
  vOrigin.x = (float)(vOrigin.x + (float)(vForward.x * vMins.x)) + (float)(vRight.x * vMins.y);
  vOrigin.y = (float)(vOrigin.y + (float)(vForward.y * vMins.x)) + (float)(vRight.y * vMins.y);
  vOrigin.z = (float)(vOrigin.z + (float)(vForward.z * vMins.x)) + (float)(vRight.z * vMins.y);
  vPoints[0].z = vOrigin.z + (float)(vUp.z * vMins.z);
  vPoints[0].x = vOrigin.x + (float)(vUp.x * vMins.z);
  vPoints[0].y = vOrigin.y + (float)(vUp.y * vMins.z);
  v109 = vForward.x * vMaxs.x;
  v115 = vForward.y * vMaxs.x;
  v111 = vForward.z * vMaxs.x;
  vPoints[1].x = (float)((float)((float)(vForward.x * vMaxs.x) + *(float *)&v10) + (float)(vRight.x * vMins.y))
               + (float)(vUp.x * vMins.z);
  v102 = vUp.x * vMins.z;
  v103 = vUp.y * vMins.z;
  v104 = vUp.z * vMins.z;
  vPoints[1].z = (float)((float)((float)(vForward.z * vMaxs.x) + z) + (float)(vRight.z * vMins.y))
               + (float)(vUp.z * vMins.z);
  vPoints[1].y = (float)((float)((float)(vForward.y * vMaxs.x) + y) + (float)(vRight.y * vMins.y))
               + (float)(vUp.y * vMins.z);
  v107 = vRight.x * vMaxs.y;
  v106 = vRight.y * vMaxs.y;
  v108 = vRight.z * vMaxs.y;
  vPoints[2].x = (float)((float)((float)(vForward.x * vMins.x) + *(float *)&v10) + (float)(vRight.x * vMaxs.y))
               + (float)(vUp.x * vMins.z);
  vPoints[2].z = (float)((float)((float)(vForward.z * vMins.x) + z) + (float)(vRight.z * vMaxs.y))
               + (float)(vUp.z * vMins.z);
  vPoints[2].y = (float)((float)((float)(vForward.y * vMins.x) + y) + (float)(vRight.y * vMaxs.y))
               + (float)(vUp.y * vMins.z);
  vPoints[3].x = (float)((float)((float)(vForward.x * vMaxs.x) + *(float *)&v10) + (float)(vRight.x * vMaxs.y))
               + (float)(vUp.x * vMins.z);
  v112 = vUp.x * vMins.z;
  vPoints[3].z = (float)((float)((float)(vForward.z * vMaxs.x) + z) + (float)(vRight.z * vMaxs.y))
               + (float)(vUp.z * vMins.z);
  vPoints[3].y = (float)((float)((float)(vForward.y * vMaxs.x) + y) + (float)(vRight.y * vMaxs.y))
               + (float)(vUp.y * vMins.z);
  vPoints[4].z = (float)((float)((float)(vForward.z * vMins.x) + z) + (float)(vRight.z * vMins.y))
               + (float)(vUp.z * vMaxs.z);
  v113 = vRight.y * vMins.y;
  v114 = vRight.z * vMins.y;
  vPoints[4].x = (float)((float)((float)(vForward.x * vMins.x) + *(float *)&v10) + (float)(vRight.x * vMins.y))
               + (float)(vUp.x * vMaxs.z);
  vPoints[4].y = (float)((float)((float)(vForward.y * vMins.x) + y) + (float)(vRight.y * vMins.y))
               + (float)(vUp.y * vMaxs.z);
  vPoints[5].z = (float)((float)((float)(vForward.z * vMaxs.x) + z) + (float)(vRight.z * vMins.y))
               + (float)(vUp.z * vMaxs.z);
  vPoints[5].x = (float)((float)((float)(vForward.x * vMaxs.x) + *(float *)&v10) + (float)(vRight.x * vMins.y))
               + (float)(vUp.x * vMaxs.z);
  vPoints[5].y = (float)((float)((float)(vForward.y * vMaxs.x) + y) + (float)(vRight.y * vMins.y))
               + (float)(vUp.y * vMaxs.z);
  v119 = (float)(vForward.z * vMins.x) + z;
  vOrigin.x = (float)((float)(vForward.x * vMins.x) + *(float *)&v10) + (float)(vRight.x * vMaxs.y);
  vOrigin.y = (float)((float)(vForward.y * vMins.x) + y) + (float)(vRight.y * vMaxs.y);
  vOrigin.z = v119 + (float)(vRight.z * vMaxs.y);
  v117 = vOrigin.x + (float)(vUp.x * vMaxs.z);
  vPoints[6].x = v117;
  v118 = vUp.y * vMaxs.z;
  vPoints[6].y = vOrigin.y + (float)(vUp.y * vMaxs.z);
  vPoints[6].z = vOrigin.z + (float)(vUp.z * vMaxs.z);
  v15 = (float)((float)(vForward.z * vMaxs.x) + z) + (float)(vRight.z * vMaxs.y);
  v16 = pTriangleFanPoints[2];
  v17 = (float)((float)((float)(vForward.y * vMaxs.x) + y) + (float)(vRight.y * vMaxs.y)) + (float)(vUp.y * vMaxs.z);
  v18 = pTriangleFanPoints[3];
  m_pObject = pRenderContext.m_pObject;
  v20 = pTriangleFanPoints[1];
  vPoints[7].z = v15 + (float)(vUp.z * vMaxs.z);
  vPoints[7].x = (float)((float)((float)(vForward.x * vMaxs.x) + *(float *)&v10) + (float)(vRight.x * vMaxs.y))
               + (float)(vUp.x * vMaxs.z);
  vPoints[7].y = v17;
  p_z = &vPoints[0].z;
  for ( i = 0; i != 8; ++i )
  {
    v23 = (float)((float)((float)(*(p_z - 2) * *(float *)&v20) + (float)(*(p_z - 1) * *(float *)&v16))
                + (float)(*(float *)&v18 * *p_z))
        - *(float *)&m_pObject;
    *(float *)((char *)&vNormal.x + i * 4) = v23;
    iClipped[i] = v23 > 0.0;
    p_z += 3;
  }
  v24 = iLines[0];
  do
  {
    v25 = v24[1];
    v26 = *v24;
    v27 = iClipped[*v24];
    v28 = v27 + iClipped[v25];
    if ( v28 == 1 )
    {
      v29 = v27 == 1;
      v30 = v26 + 8 * v25;
      if ( v29 )
      {
        v31 = *(&vNormal.x + v25);
        v32 = 1.0 / (float)(*(&vNormal.x + v26) - v31);
        v33 = vPoints[v26].y;
        v34 = vPoints[v26].z;
        v35 = v31 * v32;
        v36 = v35 * vPoints[v26].x;
        v37 = *(&vNormal.x + v26) * v32;
        x = vPoints[v25].x;
        v39 = &vPoints[v25];
        v40 = v25 + 8 * v26;
        iLineStates[0][v40] = 3;
        v41 = x * v37;
        iLineStates[0][v30] = 4;
      }
      else
      {
        v42 = *(&vNormal.x + v26);
        v43 = 1.0 / (float)(*(&vNormal.x + v25) - v42);
        v33 = vPoints[v25].y;
        v34 = vPoints[v25].z;
        v35 = v42 * v43;
        v36 = v35 * vPoints[v25].x;
        v44 = *(&vNormal.x + v25) * v43;
        v40 = v25 + 8 * v26;
        v39 = &vPoints[v26];
        v37 = v44;
        v41 = v44 * v39->x;
        iLineStates[0][v40] = 4;
        iLineStates[0][v30] = 3;
      }
      v45 = v39->z;
      v46 = v34 * v35;
      v47 = v33 * v35;
      v48 = v39->y;
      p_x = &vSplitPoints[0][v30].x;
      v50 = v41 - v36;
      *p_x = v50;
      v51 = &vSplitPoints[0][v40].x;
      p_x[1] = (float)(v48 * v37) - v47;
      p_x[2] = (float)(v45 * v37) - v46;
      *v51 = v50;
      v51[1] = p_x[1];
      v51[2] = p_x[2];
    }
    else
    {
      iLineStates[v25][v26] = v28;
      iLineStates[v26][v25] = v28;
    }
    v24 += 2;
  }
  while ( v24 != (const int *)"FreezeFrame_FullScreen" );
  v52 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(
                               a1: materials,
                               a2: a3);
  v53 = v52;
  pRenderContext.m_pObject = v52;
  if ( v52 != nullptr )
    v52->BeginRender(this: v52);
  v53->Bind(this: v53, a2: g_material_WriteZ.m_pMaterial, a3: nullptr);
  meshBuilder.m_pMesh = nullptr;
  meshBuilder.m_bGenerateIndices = false;
  memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
  meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
  meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
  meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
  memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
  meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
  v54 = v53->GetDynamicMesh(this: v53, a2: false, a3: nullptr, a4: nullptr, a5: nullptr);
  meshBuilder.m_pMesh = v54;
  meshBuilder.m_bGenerateIndices = true;
  meshBuilder.m_Type = MATERIAL_TRIANGLES;
  SetPrimitiveType = v54->SetPrimitiveType;
  pMesh = v54;
  SetPrimitiveType(this: v54, a2: MATERIAL_TRIANGLES);
  meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 54, a3: 54, a4: &meshBuilder, a5: nullptr);
  meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v54->IIndexBuffer;
  meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
  meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
  meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
  meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 54;
  meshBuilder.m_IndexBuilder.m_bModify = false;
  meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
  meshBuilder.m_VertexBuilder.m_pVertexBuffer = v54;
  meshBuilder.m_VertexBuilder.VertexDesc_t = meshBuilder.VertexDesc_t;
  v56 = nullptr;
  meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 54;
  meshBuilder.m_VertexBuilder.m_NumBoneWeights = meshBuilder.m_NumBoneWeights != 0 ? 2 : 0;
  meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
  meshBuilder.m_VertexBuilder.m_bModify = false;
  if ( meshBuilder.m_VertexBuilder.m_nBufferOffset == -1 )
  {
    meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_nBufferOffset = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
    meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = meshBuilder.m_nFirstVertex;
  }
  meshBuilder.m_VertexBuilder.m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pNormal;
  meshBuilder.m_VertexBuilder.m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pPosition;
  qmemcpy(
    meshBuilder.m_VertexBuilder.m_pCurrTexCoord,
    meshBuilder.m_VertexBuilder.m_pTexCoord,
    sizeof(meshBuilder.m_VertexBuilder.m_pCurrTexCoord));
  meshBuilder.m_VertexBuilder.m_pCurrColor = meshBuilder.m_VertexBuilder.m_pColor;
  v57 = iQuads[0];
  meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
  meshBuilder.m_VertexBuilder.m_nCurrentVertex = 0;
  v111 = COERCE_FLOAT(iQuads);
  do
  {
    v58 = 0;
    while ( 1 )
    {
      v59 = v57[v58 + 1];
      if ( iLineStates[v57[v58]][v59] != 2 )
        break;
      if ( ++v58 == 3 )
        goto LABEL_45;
    }
    LODWORD(v115) = v59 + 8 * v57[v58];
    v60 = iLineStates[0][LODWORD(v115)];
    v61 = 1;
    if ( v60 == 0 )
    {
      v63 = v57[v58];
      v64 = &vPoints[v59];
      goto LABEL_26;
    }
    v62 = v60 - 3;
    if ( v62 == 0 )
    {
      v56 = &vSplitPoints[0][LODWORD(v115)];
      v64 = &vPoints[v59];
LABEL_27:
      pTriangleFanPoints[0] = &v64->x;
      goto LABEL_28;
    }
    if ( v62 == 1 )
    {
      v63 = v57[v58];
      v64 = &vSplitPoints[0][LODWORD(v115)];
LABEL_26:
      v56 = &vPoints[v63];
      goto LABEL_27;
    }
LABEL_28:
    v65 = v58 + 1;
    if ( v65 == 3 )
      goto LABEL_39;
    v66 = &v57[v65 + 1];
    v115 = *(float *)&v66;
    LODWORD(v109) = 3 - v65;
    v65 = 3;
    do
    {
      v67 = *v66;
      v68 = *v66 + 8 * *(v66 - 1);
      v69 = iLineStates[0][v68];
      if ( v69 != 0 )
      {
        v70 = v69 - 3;
        if ( v70 == 0 )
        {
          pTriangleFanPoints[v61] = &vSplitPoints[0][v68].x;
          pTriangleFanPoints[v61 + 1] = &vPoints[v67].x;
          v61 += 2;
          goto LABEL_37;
        }
        if ( v70 != 1 )
          goto LABEL_37;
        v71 = &vSplitPoints[0][v68];
      }
      else
      {
        v71 = &vPoints[v67];
      }
      pTriangleFanPoints[v61++] = &v71->x;
LABEL_37:
      v66 = (const int *)(LODWORD(v115) + 4);
      v29 = LODWORD(v109)-- == 1;
      LODWORD(v115) += 4;
    }
    while ( !v29 );
    v57 = (const int *)LODWORD(v111);
LABEL_39:
    v72 = v57[v65 + 1] + 8 * v57[v65];
    if ( (unsigned int)(iLineStates[0][v72] - 3) <= 1 )
      pTriangleFanPoints[v61++] = &vSplitPoints[0][v72].x;
    v73 = v61 - 1;
    v74 = 0;
    if ( v61 != 1 )
    {
      do
      {
        m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = v56->x;
        m_pCurrPosition[1] = v56->y;
        m_pCurrPosition[2] = v56->z;
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v76 = pTriangleFanPoints[v74];
        v77 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = *v76;
        v77[1] = v76[1];
        v77[2] = v76[2];
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        v78 = pTriangleFanPoints[v74 + 1];
        v79 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
        *meshBuilder.m_VertexBuilder.m_pCurrPosition = *v78;
        v79[1] = v78[1];
        v79[2] = v78[2];
        CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
        ++v74;
      }
      while ( v74 != v73 );
      v57 = (const int *)LODWORD(v111);
    }
    v54 = pMesh;
    v56 = nullptr;
LABEL_45:
    v57 += 5;
    v111 = *(float *)&v57;
  }
  while ( v57 != (const int *)iLines );
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
  v54->Draw_2(this: v54, a2: -1, a3: 0);
  v81 = pRenderContext.m_pObject;
  pRenderContext.m_pObject->Flush(this: pRenderContext.m_pObject, a2: false);
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
  v81->EndRender(this: v81);
  v81->Release(this: v81);
}

//------------------------------------------------------------------------------
// Address: 0x1019F710
// Name: DrawRenderable
// Source: json
//------------------------------------------------------------------------------
void __usercall DrawRenderable(
        IClientRenderable *pEnt@<esi>,
        int a2@<ebx>,
        int flags,
        const RenderableInstance_t *instance,
        bool bShadowDepth)
{
  float *v5; // edi
  int v6; // ebx
  int v7; // eax
  IViewRender_vtbl *v8; // edi
  int v9; // eax
  int v10; // eax
  IViewRender_vtbl *v11; // edi
  int v12; // eax

  if ( r_entityclips.m_pParent != nullptr
    && r_entityclips.m_pParent->m_Value.m_nValue != 0
    && (v5 = pEnt->GetRenderClipPlane(this: pEnt)) != nullptr )
  {
    v6 = ((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(a1: materials, a2);
    if ( v6 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
    if ( materials->UsingFastClipping(this: materials) )
    {
      if ( !bShadowDepth )
        DrawClippedDepthBox(pEnt, pClipPlane: v5, a3: v6, a4: (int)v5, a5: (int)pEnt);
    }
    else
    {
      (*(void (__thiscall **)(int, float *))(*(_DWORD *)v6 + 484))(a1: v6, a2: v5);
    }
    v7 = pEnt->GetIClientUnknown(this: pEnt);
    v8 = view->__vftable;
    v9 = (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 28))(a1: v7);
    v8->SetCurrentlyDrawingEntity(this: view, a2: (C_BaseEntity *)v9);
    pEnt->DrawModel(this: pEnt, a2: flags, a3: instance);
    view->SetCurrentlyDrawingEntity(this: view, a2: nullptr);
    if ( !materials->UsingFastClipping(this: materials) )
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 488))(a1: v6);
    if ( v6 != 0 )
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6);
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
    }
  }
  else
  {
    v10 = pEnt->GetIClientUnknown(this: pEnt);
    v11 = view->__vftable;
    v12 = (*(int (__thiscall **)(int))(*(_DWORD *)v10 + 28))(a1: v10);
    v11->SetCurrentlyDrawingEntity(this: view, a2: (C_BaseEntity *)v12);
    pEnt->DrawModel(this: pEnt, a2: flags, a3: instance);
    view->SetCurrentlyDrawingEntity(this: view, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019F860
// Name: protected: void CRendering3dView::DrawDeferredClippedOpaqueRenderables(class IMatRenderContext __near *,enum CRendering3dView::RenderablesRenderPath_t,class CUtlVector<struct CClientRenderablesList::CEntry __near *,class CUtlMemory<struct CClientRenderablesList::CEntry __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRendering3dView::DrawDeferredClippedOpaqueRenderables(
        CRendering3dView *this,
        IMatRenderContext *pRenderContext,
        CRendering3dView::RenderablesRenderPath_t eRenderPath,
        CUtlVector<CClientRenderablesList::CEntry *,CUtlMemory<CClientRenderablesList::CEntry *,int> > *pDeferClippedOpaqueRenderables)
{
  CClientRenderablesList::CEntry **m_pMemory; // eax
  int v5; // edi
  CClientRenderablesList::CEntry *v6; // eax
  IClientRenderable *m_pRenderable; // ebx
  int v8; // esi
  float v9[3]; // [esp+0h] [ebp-14h] BYREF
  int nCount; // [esp+Ch] [ebp-8h]
  CClientRenderablesList::CEntry **ppEntities; // [esp+10h] [ebp-4h]
  bool bShadowDepth; // [esp+20h] [ebp+Ch]

  if ( pDeferClippedOpaqueRenderables != nullptr )
  {
    m_pMemory = pDeferClippedOpaqueRenderables->m_Memory.m_pMemory;
    bShadowDepth = eRenderPath > RENDERABLES_RENDER_PATH_NORMAL;
    v5 = 0;
    nCount = pDeferClippedOpaqueRenderables->m_Size;
    ppEntities = m_pMemory;
    if ( nCount > 0 )
    {
      do
      {
        v6 = ppEntities[v5];
        m_pRenderable = v6->m_pRenderable;
        v8 = 1;
        if ( *((char *)v6 + 7) < 0 )
          v8 = 9;
        if ( bShadowDepth )
        {
          v8 |= 0x40000000u;
        }
        else
        {
          m_pRenderable->GetColorModulation(this: m_pRenderable, a2: v9);
          render->SetColorModulation(this: render, a2: v9);
        }
        HIBYTE(pDeferClippedOpaqueRenderables) = -1;
        DrawRenderable(
          pEnt: m_pRenderable,
          a2: (int)m_pRenderable,
          flags: v8,
          instance: (const RenderableInstance_t *)&pDeferClippedOpaqueRenderables + 3,
          bShadowDepth);
        ++v5;
      }
      while ( v5 < nCount );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019F900
// Name: protected: void CRendering3dView::DrawTranslucentRenderablesNoWorld(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CRendering3dView::DrawTranslucentRenderablesNoWorld(
        CRendering3dView *this@<ecx>,
        _BYTE *a2@<ebx>,
        float a3@<edi>,
        bool bInSkybox)
{
  const ConVar *m_pDrawEntities; // eax
  ConVar *m_pParent; // eax
  CClientRenderablesList *m_pRenderablesList; // edi
  int v8; // eax
  const RenderableInstance_t *p_m_InstanceData; // edi
  IClientRenderable *v10; // esi
  int v11; // ebx
  __int64 *v12; // eax
  int v13; // eax
  _BYTE v16[12]; // [esp+18h] [ebp-10h] BYREF
  int iCurTranslucentEntity; // [esp+24h] [ebp-4h]
  bool bShadowDepth; // [esp+30h] [ebp+8h]

  m_pDrawEntities = this->m_pMainView->m_pDrawEntities;
  if ( (m_pDrawEntities == nullptr
     || (m_pParent = m_pDrawEntities->m_pParent) != nullptr && m_pParent->m_Value.m_nValue != 0)
    && r_drawtranslucentrenderables.m_pParent != nullptr
    && r_drawtranslucentrenderables.m_pParent->m_Value.m_nValue != 0 )
  {
    DrawParticleSingletons(bInSkybox);
    m_pRenderablesList = this->m_pRenderablesList;
    v8 = m_pRenderablesList->m_RenderGroupCounts[1] - 1;
    bShadowDepth = (this->m_DrawFlags & 0x100000) != 0;
    iCurTranslucentEntity = v8;
    if ( v8 >= 0 )
    {
      p_m_InstanceData = &m_pRenderablesList->m_RenderGroups[1][v8].m_InstanceData;
      do
      {
        v10 = *(IClientRenderable **)&p_m_InstanceData[-6].m_nAlpha;
        v11 = ((int (__thiscall *)(IClientRenderable *, _BYTE *, float))v10->GetRenderFlags)(
                a1: v10,
                a2,
                a3: COERCE_FLOAT(LODWORD(a3)));
        if ( (v11 & 1) != 0 )
          UpdateRefractTexture(a1: (int)p_m_InstanceData);
        if ( (v11 & 2) != 0 )
        {
          v12 = (__int64 *)view->GetViewSetup(this: view);
          UpdateScreenEffectTexture(
            a1: v11,
            a2: (int)v10,
            textureIndex: 0,
            x: *v12,
            w: v12[1],
            bDestFullScreen: false,
            pActualRect: nullptr);
        }
        LOBYTE(v11) = p_m_InstanceData[1].m_nAlpha >> 7;
        a3 = (float)p_m_InstanceData->m_nAlpha * 0.0039215689;
        ((void (*)(void))render->SetBlend)();
        a2 = v16;
        ((void (__thiscall *)(IClientRenderable *))v10->GetColorModulation)(a1: v10);
        render->SetColorModulation(this: render, a2: (const float *)v16);
        v13 = -2147483647;
        if ( (_BYTE)v11 != 0 )
          v13 = -2147483639;
        if ( bShadowDepth )
          v13 |= 0x40000000u;
        DrawRenderable(pEnt: v10, a2: v11, flags: v13, instance: p_m_InstanceData, bShadowDepth);
        p_m_InstanceData -= 8;
        --iCurTranslucentEntity;
      }
      while ( iCurTranslucentEntity >= 0 );
    }
    ((void (__stdcall *)(int))render->SetBlend)(a1: 1065353216);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019FA80
// Name: protected: void CRendering3dView::DrawNoZBufferTranslucentRenderables(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CRendering3dView::DrawNoZBufferTranslucentRenderables(
        CRendering3dView *this@<ecx>,
        _BYTE *a2@<ebx>,
        float a3@<edi>,
        _BYTE *a4@<esi>)
{
  const ConVar *m_pDrawEntities; // eax
  ConVar *m_pParent; // eax
  CClientRenderablesList *m_pRenderablesList; // edi
  int v7; // eax
  const RenderableInstance_t *p_m_InstanceData; // edi
  IClientRenderable *v9; // esi
  int v10; // ebx
  __int64 *v11; // eax
  int v12; // eax
  _BYTE v16[12]; // [esp+14h] [ebp-14h] BYREF
  int iCurTranslucentEntity; // [esp+20h] [ebp-8h]
  BOOL bShadowDepth; // [esp+24h] [ebp-4h]

  m_pDrawEntities = this->m_pMainView->m_pDrawEntities;
  if ( (m_pDrawEntities == nullptr
     || (m_pParent = m_pDrawEntities->m_pParent) != nullptr && m_pParent->m_Value.m_nValue != 0)
    && r_drawtranslucentrenderables.m_pParent != nullptr
    && r_drawtranslucentrenderables.m_pParent->m_Value.m_nValue != 0 )
  {
    m_pRenderablesList = this->m_pRenderablesList;
    LOBYTE(bShadowDepth) = (this->m_DrawFlags & 0x100000) != 0;
    v7 = m_pRenderablesList->m_RenderGroupCounts[2] - 1;
    iCurTranslucentEntity = v7;
    if ( v7 >= 0 )
    {
      p_m_InstanceData = &m_pRenderablesList->m_RenderGroups[2][v7].m_InstanceData;
      do
      {
        v9 = *(IClientRenderable **)&p_m_InstanceData[-6].m_nAlpha;
        v10 = ((int (__thiscall *)(IClientRenderable *, _BYTE *, _BYTE *, float))v9->GetRenderFlags)(
                a1: v9,
                a2: a4,
                a3: a2,
                a4: COERCE_FLOAT(LODWORD(a3)));
        if ( (v10 & 1) != 0 )
          UpdateRefractTexture(a1: (int)p_m_InstanceData);
        if ( (v10 & 2) != 0 )
        {
          v11 = (__int64 *)view->GetViewSetup(this: view);
          UpdateScreenEffectTexture(
            a1: v10,
            a2: (int)v9,
            textureIndex: 0,
            x: *v11,
            w: v11[1],
            bDestFullScreen: false,
            pActualRect: nullptr);
        }
        LOBYTE(v10) = p_m_InstanceData[1].m_nAlpha >> 7;
        a3 = (float)p_m_InstanceData->m_nAlpha * 0.0039215689;
        ((void (*)(void))render->SetBlend)();
        a2 = v16;
        ((void (__thiscall *)(IClientRenderable *))v9->GetColorModulation)(a1: v9);
        a4 = v16;
        ((void (__thiscall *)(IVRenderView *))render->SetColorModulation)(a1: render);
        v12 = -2147483647;
        if ( (_BYTE)v10 != 0 )
          v12 = -2147483639;
        if ( bShadowDepth )
          v12 |= 0x40000000u;
        DrawRenderable(pEnt: v9, a2: v10, flags: v12, instance: p_m_InstanceData, bShadowDepth);
        p_m_InstanceData -= 8;
        --iCurTranslucentEntity;
      }
      while ( iCurTranslucentEntity >= 0 );
    }
    ((void (__stdcall *)(int))render->SetBlend)(a1: 1065353216);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019FBE0
// Name: UpdateNecessaryRenderTargets
// Source: json
//------------------------------------------------------------------------------
void __usercall UpdateNecessaryRenderTargets(int a1@<edi>, int a2@<esi>, CMatRenderContextPtr nRenderFlags)
{
  char m_pObject; // bl
  IMatRenderContext *v4; // edi
  int v5; // esi
  int v6; // edi
  int (__thiscall *v7)(int); // eax
  IMatRenderContext *v8; // eax
  IMatRenderContext *v9; // esi
  ITexture *FullFrameFrameBufferTexture; // edi
  int v11; // eax
  __int64 v14; // [esp+14h] [ebp-18h] BYREF
  int v15; // [esp+1Ch] [ebp-10h]
  int v16; // [esp+20h] [ebp-Ch]
  int v17; // [esp+24h] [ebp-8h] BYREF
  int v18; // [esp+28h] [ebp-4h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+34h] [ebp+8h]

  m_pObject = (char)nRenderFlags.m_pObject;
  if ( nRenderFlags.m_pObject != nullptr )
  {
    v4 = materials->GetRenderContext(this: materials);
    pRenderContext.m_pObject = v4;
    if ( v4 != nullptr )
      v4->BeginRender(this: v4);
    v5 = (int)v4->GetRenderTarget(this: v4);
    if ( (m_pObject & 4) != 0
      && (m_pObject & 1) != 0
      && *(_DWORD *)(gpGlobals.m_Index + 4) == g_viewscene_refractUpdateFrame
      && (r_unlimitedrefract.m_pParent == nullptr || r_unlimitedrefract.m_pParent->m_Value.m_nValue == 0) )
    {
      m_pObject &= ~1u;
    }
    if ( v5 != 0 )
    {
      if ( (m_pObject & 2) != 0 )
      {
        v6 = (*(int (__thiscall **)(int, int, int))(*(_DWORD *)v5 + 16))(a1: v5, a2: a1, a3: a2);
        v7 = *(int (__thiscall **)(int))(*(_DWORD *)v5 + 12);
        v14 = 0;
        v15 = v7(a1: v5);
        v16 = v6;
        v8 = materials->GetRenderContext(this: materials);
        v9 = v8;
        if ( v8 != nullptr )
          v8->BeginRender(this: v8);
        FullFrameFrameBufferTexture = GetFullFrameFrameBufferTexture(textureIndex: 0);
        v9->GetRenderTargetDimensions(this: v9, a2: &v17, a3: &v18);
        FullFrameFrameBufferTexture->GetActualWidth(this: FullFrameFrameBufferTexture);
        FullFrameFrameBufferTexture->GetActualHeight(this: FullFrameFrameBufferTexture);
        v9->CopyRenderTargetToTextureEx(
          this: v9,
          a2: FullFrameFrameBufferTexture,
          a3: 0,
          a4: (Rect_t *)&v14,
          a5: nullptr);
        v9->SetFrameBufferCopyTexture(this: v9, a2: FullFrameFrameBufferTexture, a3: 0);
        v9->EndRender(this: v9);
        v9->Release(this: v9);
        v4 = pRenderContext.m_pObject;
      }
      else if ( (m_pObject & 1) != 0 )
      {
        v11 = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)v5 + 16))(a1: v5, a2: 0);
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v5 + 12))(a1: v5, a2: v11);
        UpdateRefractTexture(a1: (int)v4, a2: v5);
      }
    }
    else if ( (m_pObject & 1) != 0 )
    {
      UpdateRefractTexture(a1: (int)v4);
    }
    v4->EndRender(this: v4);
    v4->Release(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019FD70
// Name: public: bool CSkyboxView::Setup(class CViewSetup const __near &,int __near *,enum SkyboxVisibility_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSkyboxView::Setup(
        CSkyboxView *this,
        const CViewSetup *view,
        int *pClearFlags,
        SkyboxVisibility_t *pSkyboxVisible)
{
  SkyboxVisibility_t v5; // eax
  C_BasePlayer *LocalPlayer; // eax

  CRendering3dView::Setup(this, setup: view);
  v5 = this->ComputeSkyboxVisibility(this);
  *pSkyboxVisible = v5;
  if ( v5 == SKYBOX_3DSKYBOX_VISIBLE || r_3dsky.m_pParent != nullptr && r_3dsky.m_pParent->m_Value.m_nValue == 2 )
  {
    if ( r_3dsky.m_pParent != nullptr && r_3dsky.m_pParent->m_Value.m_nValue != 0 )
    {
      LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
      if ( LocalPlayer != nullptr )
      {
        if ( LocalPlayer->m_Local.m_skybox3d.area.m_Value == 255 )
          LocalPlayer = nullptr;
        else
          LocalPlayer = (C_BasePlayer *)((char *)LocalPlayer + 5040);
      }
    }
    else
    {
      LocalPlayer = nullptr;
    }
  }
  else
  {
    LocalPlayer = nullptr;
  }
  this->m_pSky3dParams = (sky3dparams_t *)LocalPlayer;
  if ( LocalPlayer == nullptr )
    return 0;
  this->m_ClearFlags = *pClearFlags;
  *pClearFlags = *pClearFlags & 0xFFFFFFD8 | 2;
  this->m_DrawFlags = 112;
  if ( r_skybox.m_pParent != nullptr && r_skybox.m_pParent->m_Value.m_nValue != 0 )
    this->m_DrawFlags = 2160;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1019FE30
// Name: public: void CFreezeFrameView::Setup(class CViewSetup const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFreezeFrameView::Setup(CFreezeFrameView *this, const CViewSetup *shadowViewIn)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi

  CRendering3dView::Setup(this, setup: shadowViewIn);
  VGui_GetTrueScreenSize(w: this->m_nScreenSize, h: &this->m_nScreenSize[1]);
  VGui_GetPanelBounds(
    slot: 0,
    x: this->m_nSubRect,
    y: &this->m_nSubRect[1],
    w: &this->m_nSubRect[2],
    h: &this->m_nSubRect[3]);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "UnlitGeneric");
  else
    v4 = nullptr;
  KeyValues::SetString(this: v4, keyName: "$basetexture", value: "_rt_FullScreen");
  KeyValues::SetInt(this: v4, keyName: "$nocull", value: 1);
  KeyValues::SetInt(this: v4, keyName: "$nofog", value: 1);
  KeyValues::SetInt(this: v4, keyName: "$ignorez", value: 1);
  CMaterialReference::Init(
    this: &this->m_pFreezeFrame,
    pMaterialName: "FreezeFrame_FullScreen",
    pTextureGroupName: "Other textures",
    pVMTKeyValues: v4);
  this->m_pFreezeFrame.m_pMaterial->Refresh(this: this->m_pFreezeFrame.m_pMaterial);
  CMaterialReference::Init(
    this: &this->m_TranslucentSingleColor,
    pMaterialName: "debug/debugtranslucentsinglecolor",
    pTextureGroupName: "Other textures",
    bComplain: true);
}

//------------------------------------------------------------------------------
// Address: 0x1019FF20
// Name: public: virtual void CFreezeFrameView::Draw(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFreezeFrameView::Draw(CFreezeFrameView *this)
{
  IMatRenderContext *v2; // ebx
  IMaterial *m_pMaterial; // edi
  int v4; // eax

  v2 = materials->GetRenderContext(this: materials);
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  v2->DrawScreenSpaceRectangle(
    this: v2,
    a2: this->m_pFreezeFrame.m_pMaterial,
    a3: this->x,
    a4: this->y,
    a5: this->width,
    a6: this->height,
    a7: (float)this->m_nSubRect[0],
    a8: (float)this->m_nSubRect[1],
    a9: (float)(this->m_nSubRect[2] + this->m_nSubRect[0] - 1),
    a10: (float)(this->m_nSubRect[1] + this->m_nSubRect[3] - 1),
    a11: this->m_nScreenSize[0],
    a12: this->m_nScreenSize[1],
    a13: nullptr,
    a14: 1,
    a15: 1);
  if ( g_flFreezeFlash[this->m_nSlot] >= *(float *)(gpGlobals.m_Index + 12) && !engine->IsTakingScreenshot(this: engine) )
  {
    m_pMaterial = this->m_TranslucentSingleColor.m_pMaterial;
    v4 = (int)(float)((float)(g_flFreezeFlash[this->m_nSlot] - *(float *)(gpGlobals.m_Index + 12)) * 340.0);
    if ( v4 >= 255 )
      v4 = 255;
    ((void (__thiscall *)(IMaterial *, _DWORD))m_pMaterial->AlphaModulate)(
      a1: this->m_TranslucentSingleColor.m_pMaterial,
      a2: (float)(v4 < 0 ? 0 : v4) * 0.0039215689);
    ((void (__thiscall *)(IMaterial *, int, int, int))m_pMaterial->ColorModulate)(
      a1: m_pMaterial,
      a2: 1065353216,
      a3: 1065353216,
      a4: 1065353216);
    m_pMaterial->SetMaterialVarFlag(this: m_pMaterial, a2: MATERIAL_VAR_IGNOREZ, a3: true);
    v2->DrawScreenSpaceRectangle(
      this: v2,
      a2: m_pMaterial,
      a3: this->x,
      a4: this->y,
      a5: this->width,
      a6: this->height,
      a7: (float)this->m_nSubRect[0],
      a8: (float)this->m_nSubRect[1],
      a9: (float)(this->m_nSubRect[2] + this->m_nSubRect[0] - 1),
      a10: (float)(this->m_nSubRect[1] + this->m_nSubRect[3] - 1),
      a11: this->m_nScreenSize[0],
      a12: this->m_nScreenSize[1],
      a13: nullptr,
      a14: 1,
      a15: 1);
  }
  v2->EndRender(this: v2);
  v2->Release(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x101A0140
// Name: protected: virtual void CBaseWorldView::PushView(float)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge CBaseWorldView::PushView(
        CBaseWorldView *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        float waterHeight)
{
  int m_DrawFlags; // eax
  float v7; // xmm0_4
  int v8; // ebx
  int v9; // esi
  int v10; // eax
  IVRenderView_vtbl *v11; // ebx
  ITexture *WaterRefractionTexture; // eax
  float v13; // xmm2_4
  float m_fValue; // xmm0_4
  float z; // xmm1_4
  int m_ClearFlags; // eax
  VPlane *m_Frustum; // [esp+10h] [ebp-14h]
  ITexture *pTexture; // [esp+20h] [ebp-4h]
  VPlane *savedregs; // [esp+24h] [ebp+0h]
  float waterHeighta; // [esp+2Ch] [ebp+8h]

  m_DrawFlags = this->m_DrawFlags;
  if ( (m_DrawFlags & 0x1000) != 0 )
    v7 = waterHeight + 2.0;
  else
    v7 = waterHeight - 2.0;
  v8 = 0;
  waterHeighta = v7;
  if ( (m_DrawFlags & 4) != 0 && mat_clipz.m_pParent != nullptr && mat_clipz.m_pParent->m_Value.m_nValue != 0 )
    v8 = 2 - ((m_DrawFlags & 8) != 0);
  v9 = ((int (__thiscall *)(IMaterialSystem *, int, int))materials->GetRenderContext)(a1: materials, a2: a3, a3: a4);
  if ( v9 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 8))(a1: v9);
  v10 = this->m_DrawFlags;
  if ( (v10 & 1) != 0 )
  {
    (*(void (__thiscall **)(int, float))(*(_DWORD *)v9 + 188))(a1: v9, a2: COERCE_FLOAT(LODWORD(v7)));
    (*(void (__thiscall **)(int, float))(*(_DWORD *)v9 + 172))(a1: v9, a2: COERCE_FLOAT(LODWORD(v7)));
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v9 + 168))(a1: v9, a2: v8);
    v11 = render->__vftable;
    m_Frustum = this->m_Frustum;
    WaterRefractionTexture = GetWaterRefractionTexture();
    v11->Push3DView_2(
      this: render,
      a2: (IMatRenderContext *)v9,
      a3: &this->CViewSetup,
      a4: this->m_ClearFlags,
      a5: WaterRefractionTexture,
      a6: m_Frustum);
LABEL_27:
    (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 12))(a1: v9);
    (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 4))(a1: v9);
    return;
  }
  if ( (v10 & 2) == 0 )
  {
    m_ClearFlags = this->m_ClearFlags;
    if ( (m_ClearFlags & 0x23) != 0 )
    {
      if ( (m_ClearFlags & 0x10) != 0 )
      {
        (*(void (__thiscall **)(int, int, bool))(*(_DWORD *)v9 + 524))(
          a1: v9,
          a2: this->m_ClearFlags & 1,
          a3: (this->m_ClearFlags & 2) != 0);
      }
      else
      {
        if ( r_shadow_deferred.m_pParent != nullptr
          && r_shadow_deferred.m_pParent->m_Value.m_nValue != 0
          && (m_ClearFlags & 2) != 0 )
        {
          this->m_ClearFlags = m_ClearFlags | 0x20;
        }
        (*(void (__thiscall **)(int, int, bool, bool))(*(_DWORD *)v9 + 48))(
          a1: v9,
          a2: this->m_ClearFlags & 1,
          a3: (this->m_ClearFlags & 2) != 0,
          a4: (this->m_ClearFlags & 0x20) != 0);
      }
    }
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v9 + 168))(a1: v9, a2: v8);
    if ( v8 != 0 )
      (*(void (__thiscall **)(int, float))(*(_DWORD *)v9 + 172))(a1: v9, a2: COERCE_FLOAT(LODWORD(v7)));
    goto LABEL_27;
  }
  pTexture = GetWaterReflectionTexture();
  (*(void (__thiscall **)(int, float, int, CBaseWorldView *))(*(_DWORD *)v9 + 188))(
    a1: v9,
    a2: COERCE_FLOAT(LODWORD(v7)),
    a3: a2,
    a4: this);
  v13 = v7;
  if ( g_pMaterialSystemHardwareConfig->UseFastClipping(this: g_pMaterialSystemHardwareConfig) )
  {
    m_fValue = r_eyewaterepsilon.m_pParent->m_Value.m_fValue;
    z = this->origin.z;
    if ( z > (float)(waterHeighta - m_fValue) )
      v13 = m_fValue + z;
  }
  (*(void (__thiscall **)(int, float, ITexture *))(*(_DWORD *)v9 + 172))(
    a1: v9,
    a2: COERCE_FLOAT(LODWORD(v13)),
    a3: pTexture);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v9 + 168))(a1: v9, a2: v8);
  savedregs = this->m_Frustum;
  ((void (__thiscall *)(IVRenderView *, int, CViewSetup *, int))render->Push3DView_2)(
    a1: render,
    a2: v9,
    a3: &this->CViewSetup,
    a4: this->m_ClearFlags);
  SetLightmapScaleForWater(a1: v9);
  (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 12))(a1: v9);
  (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 4))(a1: v9);
}

//------------------------------------------------------------------------------
// Address: 0x101A03C0
// Name: protected: virtual void CBaseWorldView::PopView(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseWorldView::PopView(CBaseWorldView *this)
{
  IMatRenderContext *v2; // esi

  v2 = materials->GetRenderContext(this: materials);
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  v2->SetHeightClipMode(this: v2, a2: MATERIAL_HEIGHTCLIPMODE_DISABLE);
  if ( (this->m_DrawFlags & 3) != 0 )
  {
    render->PopView(this: render, a2: v2, a3: this->m_Frustum);
    if ( s_vSavedLinearLightMapScale.x >= 0.0 )
    {
      v2->SetToneMappingScaleLinear(this: v2, a2: &s_vSavedLinearLightMapScale);
      s_vSavedLinearLightMapScale.x = -1.0;
    }
  }
  v2->EndRender(this: v2);
  v2->Release(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x101A0460
// Name: public: void CSimpleWorldView::Setup(class CViewSetup const __near &,int,bool,struct VisibleFogVolumeInfo_t const __near &,struct WaterRenderInfo_t const __near &,struct ViewCustomVisibility_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleWorldView::Setup(
        CSimpleWorldView *this,
        const CViewSetup *view,
        int nClearFlags,
        bool bDrawSkybox,
        const VisibleFogVolumeInfo_t *fogInfo,
        const WaterRenderInfo_t *waterInfo,
        ViewCustomVisibility_t *pCustomVisibility)
{
  CRendering3dView::Setup(this, setup: view);
  this->m_ClearFlags = nClearFlags;
  this->m_DrawFlags = 0x2000;
  if ( (*(_BYTE *)waterInfo & 0x40) != 0 )
  {
    if ( DoesViewPlaneIntersectWater(
           a1: (int)fogInfo,
           a2: (int)waterInfo,
           a3: (int)this,
           waterZ: fogInfo->m_flWaterHeight,
           leafWaterDataID: fogInfo->m_nVisibleFogVolume) )
    {
      this->m_DrawFlags |= 0x30u;
    }
    else if ( fogInfo->m_bEyeInFogVolume )
    {
      this->m_DrawFlags |= 0x10u;
    }
    else
    {
      this->m_DrawFlags |= 0x20u;
    }
  }
  else
  {
    this->m_DrawFlags = 8240;
  }
  if ( (*(_BYTE *)waterInfo & 0x20) != 0 )
  {
    if ( *(_BYTE *)waterInfo >= 0 )
      this->m_DrawFlags |= 0x40u;
    else
      this->m_DrawFlags |= 0x100u;
  }
  if ( !fogInfo->m_bEyeInFogVolume && bDrawSkybox )
    this->m_DrawFlags |= 0x800u;
  this->m_pCustomVisibility = pCustomVisibility;
  this->m_fogInfo = *fogInfo;
}

//------------------------------------------------------------------------------
// Address: 0x101A0540
// Name: public: void CAboveWaterView::Setup(class CViewSetup const __near &,bool,struct VisibleFogVolumeInfo_t const __near &,struct WaterRenderInfo_t const __near &,struct ViewCustomVisibility_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAboveWaterView::Setup(
        CAboveWaterView *this,
        const CViewSetup *view,
        bool bDrawSkybox,
        const VisibleFogVolumeInfo_t *fogInfo,
        const WaterRenderInfo_t *waterInfo,
        ViewCustomVisibility_t *pCustomVisibility)
{
  bool v7; // al
  float v8; // xmm0_4
  float m_fValue; // xmm1_4
  bool v10; // cc
  float z; // xmm0_4
  float v12; // xmm0_4

  CRendering3dView::Setup(this, setup: view);
  v7 = g_pMaterialSystemHardwareConfig->UseFastClipping(this: g_pMaterialSystemHardwareConfig);
  this->m_bSoftwareUserClipPlane = v7;
  this->m_waterHeight = fogInfo->m_flWaterHeight;
  if ( v7 )
  {
    v8 = this->origin.z - fogInfo->m_flWaterHeight;
    m_fValue = r_eyewaterepsilon.m_pParent->m_Value.m_fValue;
    this->m_waterZAdjust = 0.0;
    if ( m_fValue > COERCE_FLOAT(LODWORD(v8) & _mask__AbsFloat_) )
    {
      v10 = v8 <= 0.0;
      z = this->origin.z;
      if ( v10 )
        v12 = z + m_fValue;
      else
        v12 = z - m_fValue;
      this->m_waterHeight = v12;
      this->m_waterZAdjust = v12 - fogInfo->m_flWaterHeight;
    }
  }
  else
  {
    this->m_waterZAdjust = 0.0;
  }
  if ( this->m_waterZAdjust == 0.0 )
    this->m_bSoftwareUserClipPlane = false;
  this->m_DrawFlags = 8224;
  this->m_ClearFlags = 2;
  if ( bDrawSkybox )
    this->m_DrawFlags = 10272;
  if ( (*(_BYTE *)waterInfo & 0x20) != 0 )
  {
    if ( *(_BYTE *)waterInfo >= 0 )
      this->m_DrawFlags |= 0x40u;
    else
      this->m_DrawFlags |= 0x100u;
  }
  if ( (*(_BYTE *)waterInfo & 0x44) == 0 )
    this->m_DrawFlags |= 0x10u;
  this->m_fogInfo = *fogInfo;
  this->m_waterInfo = *waterInfo;
  this->m_pCustomVisibility = pCustomVisibility;
}

//------------------------------------------------------------------------------
// Address: 0x101A0680
// Name: public: void CAboveWaterView::CReflectionView::Setup(bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAboveWaterView::CReflectionView::Setup(
        CAboveWaterView::CReflectionView *this,
        bool bReflectEntities,
        bool bReflectOnlyMarkedEntities,
        int bReflect2DSkybox)
{
  const CViewSetup *v5; // eax
  int nSimpleWorldModelRecursionLevel; // [esp+4h] [ebp-8h] BYREF
  float flSimpleWorldModelDrawBeyondDistance; // [esp+8h] [ebp-4h] BYREF

  if ( this == (CAboveWaterView::CReflectionView *)620 )
    v5 = nullptr;
  else
    v5 = (CViewSetup *)((char *)&this->CViewSetup - 620);
  CRendering3dView::Setup(this, setup: v5);
  this->m_ClearFlags = 2;
  this->m_DrawFlags = 46;
  if ( (_BYTE)bReflect2DSkybox != 0 )
    this->m_DrawFlags = 2094;
  else
    this->m_ClearFlags = 3;
  GetSimpleWorldModelConfiguration(
    bSimpleWorldModeWaterReflectionOut: (bool *)&bReflect2DSkybox + 3,
    nSimpleWorldModelRecursionLevelOut: &nSimpleWorldModelRecursionLevel,
    flSimpleWorldModelDrawBeyondDistanceOut: &flSimpleWorldModelDrawBeyondDistance);
  if ( HIBYTE(bReflect2DSkybox) != 0 )
  {
    this->m_DrawFlags |= 0x282000u;
  }
  else if ( bReflectEntities )
  {
    this->m_DrawFlags |= 0x2000u;
  }
  else if ( bReflectOnlyMarkedEntities )
  {
    this->m_DrawFlags |= 0x202000u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A0730
// Name: public: void CAboveWaterView::CIntersectionView::Setup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAboveWaterView::CIntersectionView::Setup(CAboveWaterView::CIntersectionView *this)
{
  if ( this == (CAboveWaterView::CIntersectionView *)1196 )
  {
    CRendering3dView::Setup(this: (CRendering3dView *)0x4AC, setup: nullptr);
    MEMORY[0x5B4] = 8212;
  }
  else
  {
    CRendering3dView::Setup(this, setup: (const CViewSetup *)((char *)&this->CViewSetup - 1196));
    this->m_DrawFlags = 8212;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A0770
// Name: public: void CUnderWaterView::Setup(class CViewSetup const __near &,bool,struct VisibleFogVolumeInfo_t const __near &,struct WaterRenderInfo_t const __near &,struct ViewCustomVisibility_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUnderWaterView::Setup(
        CUnderWaterView *this,
        const CViewSetup *view,
        bool bDrawSkybox,
        const VisibleFogVolumeInfo_t *fogInfo,
        const WaterRenderInfo_t *waterInfo,
        ViewCustomVisibility_t *pCustomVisibility)
{
  bool v7; // al
  float v8; // xmm0_4
  float v9; // xmm0_4
  float m_fValue; // xmm1_4
  bool v11; // cc
  float z; // xmm0_4
  float v13; // xmm0_4
  IMaterialVar *v14; // eax
  IMaterialVar *v15; // edi
  const char *v16; // eax
  IMaterial *v17; // eax
  bool v18; // zf

  CRendering3dView::Setup(this, setup: view);
  v7 = g_pMaterialSystemHardwareConfig->UseFastClipping(this: g_pMaterialSystemHardwareConfig);
  this->m_bSoftwareUserClipPlane = v7;
  this->m_waterHeight = fogInfo->m_flWaterHeight;
  if ( !v7 )
  {
    v8 = 0.0;
LABEL_8:
    this->m_waterZAdjust = v8;
    goto LABEL_9;
  }
  v9 = this->origin.z - fogInfo->m_flWaterHeight;
  m_fValue = r_eyewaterepsilon.m_pParent->m_Value.m_fValue;
  this->m_waterZAdjust = 0.0;
  if ( m_fValue > COERCE_FLOAT(LODWORD(v9) & _mask__AbsFloat_) )
  {
    v11 = v9 <= 0.0;
    z = this->origin.z;
    if ( v11 )
      v13 = z + m_fValue;
    else
      v13 = z - m_fValue;
    this->m_waterHeight = v13;
    v8 = v13 - fogInfo->m_flWaterHeight;
    goto LABEL_8;
  }
LABEL_9:
  v14 = fogInfo->m_pFogVolumeMaterial->FindVar(
          this: fogInfo->m_pFogVolumeMaterial,
          a2: "$underwateroverlay",
          a3: 0,
          a4: 0);
  v15 = v14;
  if ( v14 != nullptr && v14->IsDefined(this: v14) )
  {
    v16 = v15->GetStringValue(this: v15);
    if ( *v16 != 48 )
    {
      v17 = materials->FindMaterial(this: materials, a2: v16, a3: "Other textures", a4: 1, a5: 0);
      CMaterialReference::Init(this: &this->m_pMainView->m_UnderWaterOverlayMaterial, pMaterial: v17);
    }
  }
  v18 = !this->m_bSoftwareUserClipPlane;
  this->m_DrawFlags = 12304;
  this->m_ClearFlags = 2;
  if ( v18 )
    this->m_DrawFlags = 12308;
  if ( (*(_BYTE *)waterInfo & 0x20) != 0 )
  {
    if ( *(_BYTE *)waterInfo >= 0 )
      this->m_DrawFlags |= 0x40u;
    else
      this->m_DrawFlags |= 0x100u;
  }
  if ( (*(_BYTE *)waterInfo & 0x44) == 0 )
    this->m_DrawFlags |= 0x20u;
  this->m_fogInfo = *fogInfo;
  this->m_waterInfo = *waterInfo;
  this->m_bDrawSkybox = bDrawSkybox;
  this->m_pCustomVisibility = pCustomVisibility;
}

//------------------------------------------------------------------------------
// Address: 0x101A0900
// Name: public: virtual void CReflectiveGlassView::PushView(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CReflectiveGlassView::PushView(CReflectiveGlassView *this, float waterHeight)
{
  IMatRenderContext *v3; // esi
  IVRenderView_vtbl *v4; // ebx
  ITexture *WaterReflectionTexture; // eax
  VPlane *m_Frustum; // [esp-4h] [ebp-24h]
  Vector4D plane; // [esp+Ch] [ebp-14h] BYREF
  CViewSetup *v8; // [esp+1Ch] [ebp-4h]

  v3 = materials->GetRenderContext(this: materials);
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  if ( this != nullptr )
    v8 = &this->CViewSetup;
  else
    v8 = nullptr;
  v4 = render->__vftable;
  m_Frustum = this->m_Frustum;
  WaterReflectionTexture = GetWaterReflectionTexture();
  v4->Push3DView_2(this: render, a2: v3, a3: v8, a4: this->m_ClearFlags, a5: WaterReflectionTexture, a6: m_Frustum);
  plane.x = this->m_ReflectionPlane.normal.x;
  plane.y = this->m_ReflectionPlane.normal.y;
  plane.z = this->m_ReflectionPlane.normal.z;
  plane.w = this->m_ReflectionPlane.dist + 0.1;
  v3->PushCustomClipPlane(this: v3, a2: &plane.x);
  v3->EndRender(this: v3);
  v3->Release(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x101A09E0
// Name: public: void CReflectiveGlassView::Setup(class CViewSetup const __near &,int,bool,struct VisibleFogVolumeInfo_t const __near &,struct WaterRenderInfo_t const __near &,struct cplane_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CReflectiveGlassView::Setup(
        CRefractiveGlassView *this,
        const CViewSetup *view,
        int nClearFlags,
        bool bDrawSkybox,
        const VisibleFogVolumeInfo_t *fogInfo,
        const WaterRenderInfo_t *waterInfo,
        const cplane_t *reflectionPlane)
{
  CSimpleWorldView::Setup(this, view, nClearFlags, bDrawSkybox, fogInfo, waterInfo, pCustomVisibility: nullptr);
  this->m_ReflectionPlane = *reflectionPlane;
}

//------------------------------------------------------------------------------
// Address: 0x101A0A60
// Name: public: virtual void CRefractiveGlassView::PushView(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRefractiveGlassView::PushView(CRefractiveGlassView *this, float waterHeight)
{
  IMatRenderContext *v3; // esi
  IVRenderView_vtbl *v4; // ebx
  ITexture *WaterRefractionTexture; // eax
  float v6; // xmm0_4
  VPlane *m_Frustum; // [esp-4h] [ebp-24h]
  Vector4D plane; // [esp+Ch] [ebp-14h] BYREF
  CViewSetup *v9; // [esp+1Ch] [ebp-4h]

  v3 = materials->GetRenderContext(this: materials);
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  if ( this != nullptr )
    v9 = &this->CViewSetup;
  else
    v9 = nullptr;
  v4 = render->__vftable;
  m_Frustum = this->m_Frustum;
  WaterRefractionTexture = GetWaterRefractionTexture();
  v4->Push3DView_2(this: render, a2: v3, a3: v9, a4: this->m_ClearFlags, a5: WaterRefractionTexture, a6: m_Frustum);
  plane.x = this->m_ReflectionPlane.normal.x * -1.0;
  plane.y = this->m_ReflectionPlane.normal.y * -1.0;
  v6 = 0.1 - this->m_ReflectionPlane.dist;
  plane.z = this->m_ReflectionPlane.normal.z * -1.0;
  plane.w = v6;
  v3->PushCustomClipPlane(this: v3, a2: &plane.x);
  v3->EndRender(this: v3);
  v3->Release(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x101A0B50
// Name: public: virtual void CRefractiveGlassView::PopView(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRefractiveGlassView::PopView(CRefractiveGlassView *this)
{
  IMatRenderContext *v2; // esi

  v2 = materials->GetRenderContext(this: materials);
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  v2->PopCustomClipPlane(this: v2);
  render->PopView(this: render, a2: v2, a3: this->m_Frustum);
  v2->EndRender(this: v2);
  v2->Release(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x101A0BB0
// Name: public: void CObjectPool<struct ClientWorldListInfo_t,0,1>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CObjectPool<ClientWorldListInfo_t,0,1>::Purge(CObjectPool<ClientWorldListInfo_t,0,1> *this)
{
  TSLNodeBase_t *Next; // esi
  int DepthAndSequence; // eax
  void (__thiscall ***v4)(_DWORD, int); // ebx

  while ( 1 )
  {
    Next = this->m_AvailableObjects.m_Head.value.Next;
    DepthAndSequence = this->m_AvailableObjects.m_Head.value32.DepthAndSequence;
    if ( this->m_AvailableObjects.m_Head.value.Next == nullptr )
      break;
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: this,
                               a2: Next->Next,
                               a3: DepthAndSequence - 1,
                               a4: Next,
                               a5: DepthAndSequence) == 0 )
    {
      _mm_pause();
      Next = this->m_AvailableObjects.m_Head.value.Next;
      DepthAndSequence = this->m_AvailableObjects.m_Head.value32.DepthAndSequence;
      if ( this->m_AvailableObjects.m_Head.value.Next == nullptr )
        return;
    }
    if ( Next == nullptr )
      break;
    v4 = *((void (__thiscall ****)(_DWORD, int))&Next->Next + 1);
    C_BaseEntity::operator delete(pMem: Next);
    if ( v4 != nullptr )
      (**v4)(a1: v4, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A1670
// Name: public: void CWorldListCache::Flush(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorldListCache::Flush(CWorldListCache *this)
{
  CWorldListCache *v1; // edi
  int i; // ebx
  CWorldListCache::Entry_t *m_Data; // esi
  volatile signed __int32 *pListInfo; // edi

  v1 = this;
  for ( i = (unsigned __int16)CUtlRBTree<CWorldListCache::Entry_t *,unsigned short,CWorldListCache::CEntryComparator,CUtlMemory<UtlRBTreeNode_t<CWorldListCache::Entry_t *,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Entries);
        i != 0xFFFF;
        i = (unsigned __int16)CUtlRBTree<CWorldListCache::Entry_t *,unsigned short,CWorldListCache::CEntryComparator,CUtlMemory<UtlRBTreeNode_t<CWorldListCache::Entry_t *,unsigned short>,unsigned short>>::NextInorder(
                                this: &v1->m_Entries,
                                i) )
  {
    m_Data = v1->m_Entries.m_Elements.m_pMemory[(unsigned __int16)i].m_Data;
    if ( m_Data != nullptr )
    {
      if ( m_Data->pList != nullptr )
        m_Data->pList->Release(this: m_Data->pList);
      pListInfo = (volatile signed __int32 *)m_Data->pListInfo;
      if ( pListInfo != nullptr
        && _InterlockedDecrement(pListInfo + 1) == 0
        && (*(unsigned __int8 (__thiscall **)(volatile signed __int32 *))(*pListInfo + 4))(a1: pListInfo) != 0 )
      {
        (**(void (__thiscall ***)(volatile signed __int32 *, int))pListInfo)(a1: pListInfo, a2: 1);
      }
      C_BaseEntity::operator delete(pMem: m_Data);
      v1 = this;
    }
  }
  CUtlRBTree<CWorldListCache::Entry_t *,unsigned short,CWorldListCache::CEntryComparator,CUtlMemory<UtlRBTreeNode_t<CWorldListCache::Entry_t *,unsigned short>,unsigned short>>::RemoveAll(this: &v1->m_Entries);
}

//------------------------------------------------------------------------------
// Address: 0x101A1720
// Name: public: bool CWorldListCache::Find(class CViewSetup const __near &,struct VisOverrideData_t __near *,int,class IWorldRenderList __near * __near *,struct ClientWorldListInfo_t __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CWorldListCache::Find(
        CWorldListCache *this,
        const CViewSetup *viewSetup,
        VisOverrideData_t *pVisOverrideData,
        CWorldListCache::Entry_t *iForceViewLeaf,
        IWorldRenderList **ppList,
        ClientWorldListInfo_t **ppListInfo)
{
  unsigned __int16 v7; // ax
  CWorldListCache::Entry_t *m_Data; // esi
  IWorldRenderList *pList; // ecx
  ClientWorldListInfo_t *v10; // esi
  ClientWorldListInfo_t *pListInfo; // esi
  CWorldListCache::Entry_t lookup; // [esp+4h] [ebp-B8h] BYREF

  CWorldListCache::Entry_t::Entry_t(
    this: &lookup,
    viewSetup,
    pVisOverrideData,
    (int)iForceViewLeaf,
    pList: nullptr,
    pListInfo: nullptr);
  iForceViewLeaf = &lookup;
  v7 = CUtlRBTree<CWorldListCache::Entry_t *,unsigned short,CWorldListCache::CEntryComparator,CUtlMemory<UtlRBTreeNode_t<CWorldListCache::Entry_t *,unsigned short>,unsigned short>>::Find(
         this: &this->m_Entries,
         search: (const CWorldListCache::Entry_t **)&iForceViewLeaf);
  if ( v7 == 0xFFFF )
  {
    if ( lookup.pList != nullptr )
      lookup.pList->Release(this: lookup.pList);
    pListInfo = lookup.pListInfo;
    if ( lookup.pListInfo != nullptr
      && _InterlockedDecrement(&lookup.pListInfo->m_iRefs) == 0
      && pListInfo->OnFinalRelease(this: pListInfo) )
    {
      ((void (__thiscall *)(ClientWorldListInfo_t *, int))pListInfo->dtr_CRefCountServiceBase<1,CRefMT>)(
        a1: pListInfo,
        a2: 1);
    }
    return 0;
  }
  else
  {
    m_Data = this->m_Entries.m_Elements.m_pMemory[v7].m_Data;
    m_Data->pList->AddRef(this: m_Data->pList);
    *ppList = m_Data->pList;
    _InterlockedExchangeAdd(&m_Data->pListInfo->m_iRefs, 1u);
    pList = lookup.pList;
    *ppListInfo = m_Data->pListInfo;
    if ( pList != nullptr )
      pList->Release(this: pList);
    v10 = lookup.pListInfo;
    if ( lookup.pListInfo != nullptr
      && _InterlockedDecrement(&lookup.pListInfo->m_iRefs) == 0
      && v10->OnFinalRelease(this: v10) )
    {
      ((void (__thiscall *)(ClientWorldListInfo_t *, int))v10->dtr_CRefCountServiceBase<1,CRefMT>)(a1: v10, a2: 1);
    }
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A1870
// Name: public: CBaseWaterView::CBaseWaterView(class CViewRender __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseWaterView *__thiscall CBaseWaterView::CBaseWaterView(CBaseWaterView *this, CViewRender *pMainView)
{
  CBase3dView::CBase3dView(this, pMainView);
  this->m_DrawFlags = 0;
  this->m_ClearFlags = 0;
  this->m_pWorldRenderList = nullptr;
  this->m_pRenderablesList = nullptr;
  this->m_pWorldListInfo = nullptr;
  this->m_pCustomVisibility = nullptr;
  this->__vftable = (CBaseWaterView_vtbl *)&CBaseWaterView::`vftable';
  CBase3dView::CBase3dView(this: &this->m_SoftwareIntersectionView, pMainView);
  this->m_SoftwareIntersectionView.m_DrawFlags = 0;
  this->m_SoftwareIntersectionView.m_ClearFlags = 0;
  this->m_SoftwareIntersectionView.m_pWorldRenderList = nullptr;
  this->m_SoftwareIntersectionView.m_pRenderablesList = nullptr;
  this->m_SoftwareIntersectionView.m_pWorldListInfo = nullptr;
  this->m_SoftwareIntersectionView.m_pCustomVisibility = nullptr;
  this->m_SoftwareIntersectionView.__vftable = (CBaseWaterView::CSoftwareIntersectionView_vtbl *)&CBaseWaterView::CSoftwareIntersectionView::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101A1940
// Name: public: CAboveWaterView::CAboveWaterView(class CViewRender __near *)
// Source: json
//------------------------------------------------------------------------------
CAboveWaterView *__thiscall CAboveWaterView::CAboveWaterView(CAboveWaterView *this, CViewRender *pMainView)
{
  CBaseWaterView::CBaseWaterView(this, pMainView);
  this->__vftable = (CAboveWaterView_vtbl *)&CAboveWaterView::`vftable';
  CBase3dView::CBase3dView(this: &this->m_ReflectionView, pMainView);
  this->m_ReflectionView.m_DrawFlags = 0;
  this->m_ReflectionView.m_ClearFlags = 0;
  this->m_ReflectionView.m_pWorldRenderList = nullptr;
  this->m_ReflectionView.m_pRenderablesList = nullptr;
  this->m_ReflectionView.m_pWorldListInfo = nullptr;
  this->m_ReflectionView.m_pCustomVisibility = nullptr;
  this->m_ReflectionView.__vftable = (CAboveWaterView::CReflectionView_vtbl *)&CAboveWaterView::CReflectionView::`vftable';
  CBase3dView::CBase3dView(this: &this->m_RefractionView, pMainView);
  this->m_RefractionView.m_DrawFlags = 0;
  this->m_RefractionView.m_ClearFlags = 0;
  this->m_RefractionView.m_pWorldRenderList = nullptr;
  this->m_RefractionView.m_pRenderablesList = nullptr;
  this->m_RefractionView.m_pWorldListInfo = nullptr;
  this->m_RefractionView.m_pCustomVisibility = nullptr;
  this->m_RefractionView.__vftable = (CAboveWaterView::CRefractionView_vtbl *)&CAboveWaterView::CRefractionView::`vftable';
  CBase3dView::CBase3dView(this: &this->m_IntersectionView, pMainView);
  this->m_IntersectionView.m_DrawFlags = 0;
  this->m_IntersectionView.m_ClearFlags = 0;
  this->m_IntersectionView.m_pWorldRenderList = nullptr;
  this->m_IntersectionView.m_pRenderablesList = nullptr;
  this->m_IntersectionView.m_pWorldListInfo = nullptr;
  this->m_IntersectionView.m_pCustomVisibility = nullptr;
  this->m_IntersectionView.__vftable = (CAboveWaterView::CIntersectionView_vtbl *)&CAboveWaterView::CIntersectionView::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101A1A90
// Name: public: CUnderWaterView::CUnderWaterView(class CViewRender __near *)
// Source: json
//------------------------------------------------------------------------------
CUnderWaterView *__thiscall CUnderWaterView::CUnderWaterView(CUnderWaterView *this, CViewRender *pMainView)
{
  CBaseWaterView::CBaseWaterView(this, pMainView);
  this->__vftable = (CUnderWaterView_vtbl *)&CUnderWaterView::`vftable';
  CBase3dView::CBase3dView(this: &this->m_RefractionView, pMainView);
  this->m_RefractionView.m_DrawFlags = 0;
  this->m_RefractionView.m_ClearFlags = 0;
  this->m_RefractionView.m_pWorldRenderList = nullptr;
  this->m_RefractionView.m_pRenderablesList = nullptr;
  this->m_RefractionView.m_pWorldListInfo = nullptr;
  this->m_RefractionView.m_pCustomVisibility = nullptr;
  this->m_RefractionView.__vftable = (CUnderWaterView::CRefractionView_vtbl *)&CUnderWaterView::CRefractionView::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101A1B40
// Name: public: virtual bool CViewRender::UpdateShadowDepthTexture(class ITexture __near *,class ITexture __near *,class CViewSetup const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CViewRender::UpdateShadowDepthTexture(
        CViewRender *this,
        ITexture *pRenderTarget,
        ITexture *pDepthTexture,
        const CViewSetup *shadowViewIn)
{
  IMatRenderContext *v4; // edi
  CRendering3dView *v5; // esi

  if ( (_S6_49 & 1) == 0 )
  {
    _S6_49 |= 1u;
    counter_2.m_pCounter = CVProfile::FindOrCreateCounter(
                             this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                             a2: "shadow depth textures rendered",
                             a3: COUNTER_GROUP_DEFAULT);
    atexit(func: CViewRender::UpdateShadowDepthTexture_::_4_::_dynamic_atexit_destructor_for___counter__);
  }
  ++*counter_2.m_pCounter;
  v4 = materials->GetRenderContext(this: materials);
  if ( v4 != nullptr )
    v4->BeginRender(this: v4);
  v5 = (CRendering3dView *)MemAlloc_Alloc(nSize: 0x128u);
  if ( v5 != nullptr )
  {
    CBase3dView::CBase3dView(this: v5, pMainView: this);
    v5->m_DrawFlags = 0;
    v5->m_ClearFlags = 0;
    v5->m_pWorldRenderList = nullptr;
    v5->m_pRenderablesList = nullptr;
    v5->m_pWorldListInfo = nullptr;
    v5->m_pCustomVisibility = nullptr;
    v5->__vftable = (CRendering3dView_vtbl *)&CShadowDepthView::`vftable';
  }
  else
  {
    v5 = nullptr;
  }
  CRendering3dView::Setup(this: v5, setup: shadowViewIn);
  v5[1].m_iRefs = (int)pDepthTexture;
  v5[1].__vftable = (CRendering3dView_vtbl *)pRenderTarget;
  this->m_SimpleExecutor.AddView(this: &this->m_SimpleExecutor, a2: v5);
  if ( _InterlockedDecrement(&v5->m_iRefs) == 0 && v5->OnFinalRelease(this: v5) )
    ((void (__thiscall *)(CRendering3dView *, int))v5->dtr_CRefCountServiceBase<1,CRefMT>)(a1: v5, a2: 1);
  if ( v4 != nullptr )
  {
    v4->EndRender(this: v4);
    v4->Release(this: v4);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101A1C70
// Name: protected: void CViewRender::DrawWorldAndEntities(bool,class CViewSetup const __near &,int,struct ViewCustomVisibility_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRender::DrawWorldAndEntities(
        CViewRender *this,
        bool bDrawSkybox,
        const CViewSetup *viewIn,
        int nClearFlags,
        ViewCustomVisibility_t *pCustomVisibility)
{
  CViewRender *v5; // edi
  void (*BeginLock)(void); // edx
  const CViewSetup *v7; // esi
  CRefractiveGlassView *v8; // ebx
  IMaterialVar *(__thiscall *FindVar)(IMaterial *, const char *, bool *, bool); // eax
  int v10; // eax
  CReflectiveGlassView *v11; // eax
  CSimpleRenderExecutor *p_m_SimpleExecutor; // esi
  CRefractiveGlassView *v13; // eax
  CRefractiveGlassView *v14; // edi
  CBase3dView *v15; // eax
  CSimpleWorldView *v16; // esi
  IMaterialVar *(__thiscall *v17)(IMaterial *, const char *, bool *, bool); // eax
  int v18; // eax
  IMaterialVar *(__thiscall *v19)(IMaterial *, const char *, bool *, bool); // eax
  int v20; // eax
  CAboveWaterView *v21; // eax
  CUnderWaterView *v22; // esi
  CUnderWaterView *v23; // eax
  IMaterialVar *(__thiscall *v24)(IMaterial *, const char *, bool *, bool); // eax
  int v25; // eax
  VisibleFogVolumeInfo_t fogVolumeInfo; // [esp+Ch] [ebp-40h] BYREF
  cplane_t glassReflectionPlane; // [esp+24h] [ebp-28h] BYREF
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+3Ch] [ebp-10h]
  CViewRender *v29; // [esp+40h] [ebp-Ch]
  WaterRenderInfo_t info; // [esp+44h] [ebp-8h] BYREF
  char v31; // [esp+4Bh] [ebp-1h] BYREF
  int savedregs; // [esp+4Ch] [ebp+0h] BYREF

  v5 = this;
  BeginLock = (void (*)(void))mdlcache->BeginLock;
  v29 = this;
  cacheCriticalSection.m_pCache = mdlcache;
  BeginLock();
  v7 = viewIn;
  v8 = nullptr;
  render->GetVisibleFogVolume(this: render, a2: &viewIn->origin, a3: nullptr, a4: &fogVolumeInfo);
  CViewRender::DetermineWaterRenderInfo(this: v5, &fogVolumeInfo, &info);
  if ( (*(_BYTE *)&info & 1) != 0 )
  {
    if ( fogVolumeInfo.m_pFogVolumeMaterial != nullptr )
    {
      FindVar = fogVolumeInfo.m_pFogVolumeMaterial->FindVar;
      v31 = 0;
      v10 = (int)FindVar(this: fogVolumeInfo.m_pFogVolumeMaterial, a2: "$depth_feather", a3: (bool *)&v31, a4: false);
      if ( v10 != 0 && v31 != 0 )
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v10 + 20))(a1: v10, a2: 1);
    }
    if ( IsReflectiveGlassInView(a1: (const struct model_t *)&savedregs, view: v7, plane: &glassReflectionPlane) != 0 )
    {
      v11 = (CReflectiveGlassView *)MemAlloc_Alloc(nSize: 0x14Cu);
      if ( v11 != nullptr )
        v8 = (CRefractiveGlassView *)CReflectiveGlassView::CReflectiveGlassView(this: v11, pMainView: v5);
      CReflectiveGlassView::Setup(
        this: v8,
        view: v7,
        nClearFlags: 3,
        bDrawSkybox,
        fogInfo: &fogVolumeInfo,
        waterInfo: &info,
        reflectionPlane: &glassReflectionPlane);
      p_m_SimpleExecutor = &v5->m_SimpleExecutor;
      v5->m_SimpleExecutor.AddView(this: &v5->m_SimpleExecutor, a2: v8);
      v13 = (CRefractiveGlassView *)MemAlloc_Alloc(nSize: 0x14Cu);
      if ( v13 != nullptr )
        v14 = CRefractiveGlassView::CRefractiveGlassView(this: v13, pMainView: v5);
      else
        v14 = nullptr;
      CReflectiveGlassView::Setup(
        this: v14,
        view: viewIn,
        nClearFlags: 3,
        bDrawSkybox,
        fogInfo: &fogVolumeInfo,
        waterInfo: &info,
        reflectionPlane: &glassReflectionPlane);
      p_m_SimpleExecutor->AddView(this: p_m_SimpleExecutor, a2: v14);
      if ( v14 != nullptr && _InterlockedDecrement(&v14->m_iRefs) == 0 && v14->OnFinalRelease(this: v14) )
        ((void (__thiscall *)(CRefractiveGlassView *, int))v14->dtr_CRefCountServiceBase<1,CRefMT>)(a1: v14, a2: 1);
      if ( v8 != nullptr && _InterlockedDecrement(&v8->m_iRefs) == 0 && v8->OnFinalRelease(this: v8) )
        ((void (__thiscall *)(CRefractiveGlassView *, int))v8->dtr_CRefCountServiceBase<1,CRefMT>)(a1: v8, a2: 1);
      v5 = v29;
    }
    v15 = (CBase3dView *)MemAlloc_Alloc(nSize: 0x138u);
    v16 = (CSimpleWorldView *)v15;
    if ( v15 != nullptr )
    {
      CBase3dView::CBase3dView(this: v15, pMainView: v5);
      v16->m_DrawFlags = 0;
      v16->m_ClearFlags = 0;
      v16->m_pWorldRenderList = nullptr;
      v16->m_pRenderablesList = nullptr;
      v16->m_pWorldListInfo = nullptr;
      v16->m_pCustomVisibility = nullptr;
      v16->__vftable = (CSimpleWorldView_vtbl *)&CSimpleWorldView::`vftable';
    }
    else
    {
      v16 = nullptr;
    }
    CSimpleWorldView::Setup(
      this: v16,
      view: viewIn,
      nClearFlags,
      bDrawSkybox,
      fogInfo: &fogVolumeInfo,
      waterInfo: &info,
      pCustomVisibility);
    v5->m_SimpleExecutor.AddView(this: &v5->m_SimpleExecutor, a2: v16);
    if ( fogVolumeInfo.m_pFogVolumeMaterial != nullptr )
    {
      v17 = fogVolumeInfo.m_pFogVolumeMaterial->FindVar;
      HIBYTE(viewIn) = 0;
      v18 = (int)v17(this: fogVolumeInfo.m_pFogVolumeMaterial, a2: "$depth_feather", a3: (bool *)&viewIn + 3, a4: false);
      if ( v18 != 0 && HIBYTE(viewIn) != 0 )
        (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v18 + 20))(a1: v18, a2: 0);
    }
    if ( v16 != nullptr && _InterlockedDecrement(&v16->m_iRefs) == 0 && v16->OnFinalRelease(this: v16) )
      ((void (__thiscall *)(CSimpleWorldView *, int))v16->dtr_CRefCountServiceBase<1,CRefMT>)(a1: v16, a2: 1);
  }
  else
  {
    if ( r_ForceWaterLeaf.m_pParent == nullptr || r_ForceWaterLeaf.m_pParent->m_Value.m_nValue == 0 )
      fogVolumeInfo.m_nVisibleFogVolumeLeaf = -1;
    if ( fogVolumeInfo.m_pFogVolumeMaterial != nullptr )
    {
      v19 = fogVolumeInfo.m_pFogVolumeMaterial->FindVar;
      HIBYTE(pCustomVisibility) = 0;
      v20 = (int)v19(
                   this: fogVolumeInfo.m_pFogVolumeMaterial,
                   a2: "$depth_feather",
                   a3: (bool *)&pCustomVisibility + 3,
                   a4: false);
      if ( v20 != 0 && HIBYTE(pCustomVisibility) != 0 )
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v20 + 20))(a1: v20, a2: 1);
    }
    if ( fogVolumeInfo.m_bEyeInFogVolume )
    {
      v23 = (CUnderWaterView *)MemAlloc_Alloc(nSize: 0x38Cu);
      if ( v23 != nullptr )
        v22 = CUnderWaterView::CUnderWaterView(this: v23, pMainView: v5);
      else
        v22 = nullptr;
      CUnderWaterView::Setup(
        this: v22,
        view: viewIn,
        bDrawSkybox,
        fogInfo: &fogVolumeInfo,
        waterInfo: &info,
        pCustomVisibility: nullptr);
    }
    else
    {
      v21 = (CAboveWaterView *)MemAlloc_Alloc(nSize: 0x5CCu);
      if ( v21 != nullptr )
        v22 = (CUnderWaterView *)CAboveWaterView::CAboveWaterView(this: v21, pMainView: v5);
      else
        v22 = nullptr;
      CAboveWaterView::Setup(
        this: (CAboveWaterView *)v22,
        view: viewIn,
        bDrawSkybox,
        fogInfo: &fogVolumeInfo,
        waterInfo: &info,
        pCustomVisibility: nullptr);
    }
    v5->m_SimpleExecutor.AddView(this: &v5->m_SimpleExecutor, a2: v22);
    if ( v22 != nullptr && _InterlockedDecrement(&v22->m_iRefs) == 0 && v22->OnFinalRelease(this: v22) )
      ((void (__thiscall *)(CUnderWaterView *, int))v22->dtr_CRefCountServiceBase<1,CRefMT>)(a1: v22, a2: 1);
    if ( fogVolumeInfo.m_pFogVolumeMaterial != nullptr )
    {
      v24 = fogVolumeInfo.m_pFogVolumeMaterial->FindVar;
      HIBYTE(viewIn) = 0;
      v25 = (int)v24(this: fogVolumeInfo.m_pFogVolumeMaterial, a2: "$depth_feather", a3: (bool *)&viewIn + 3, a4: false);
      if ( v25 != 0 && HIBYTE(viewIn) != 0 )
        (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v25 + 20))(a1: v25, a2: 0);
    }
  }
  cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
}

//------------------------------------------------------------------------------
// Address: 0x101A2010
// Name: protected: virtual void CViewRender::ViewDrawScene_Intro(class CViewSetup const __near &,int,struct IntroData_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CViewRender::ViewDrawScene_Intro(
        CViewRender *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        const CViewSetup *view,
        int nClearFlags,
        const IntroData_t *introData)
{
  IMatRenderContext *v6; // ebx
  CParticleMgr *v7; // eax
  float x; // xmm0_4
  const CViewSetup *height; // esi
  CViewRender *v10; // esi
  IVRenderView_vtbl *v11; // edi
  unsigned __int8 v12; // al
  IVRenderView_vtbl *v13; // edi
  int v14; // eax
  IVRenderView_vtbl *v15; // edi
  int v16; // eax
  const CViewSetup *v17; // esi
  void (__thiscall *GetScreenFadeDistances)(IViewRender *, float *, float *); // edx
  IMatRenderContext *v19; // edi
  int m_nValue; // eax
  IVRenderView_vtbl *v21; // edi
  unsigned __int8 v22; // al
  IMaterial *v23; // edi
  IMaterialVar *(__thiscall *FindVar)(IMaterial *, const char *, bool *, bool); // eax
  IMaterialVar *v25; // eax
  IMaterial v26; // edx
  IMaterialVar *v27; // eax
  IMatRenderContext_vtbl *v28; // edx
  IMaterialVar *v29; // edi
  int v30; // edx
  IntroDataBlendPass_t *m_pMemory; // ecx
  float m_Alpha; // xmm0_4
  const IntroDataBlendPass_t *v33; // ecx
  int m_BlendMode; // eax
  ITexture *FullFrameFrameBufferTexture; // edi
  ITexture_vtbl *v36; // edx
  int v37; // eax
  int v38; // eax
  IMatRenderContext *v39; // eax
  IMatRenderContext *v40; // edi
  const IntroData_t *width; // eax
  IMaterialVar *v42; // edx
  int v43; // edi
  IVEngineClient_vtbl *v44; // eax
  CParticleMgr *v45; // eax
  float ratio; // [esp+CCh] [ebp-120h]
  CViewSetup playerView; // [esp+D4h] [ebp-118h] BYREF
  Rect_t actualRect; // [esp+1C8h] [ebp-24h] BYREF
  unsigned int visFlags; // [esp+1D8h] [ebp-14h] BYREF
  IMaterial *pOverlayMaterial; // [esp+1DCh] [ebp-10h]
  IMaterialVar *pAlphaVar; // [esp+1E0h] [ebp-Ch]
  IMaterialVar *pModeVar; // [esp+1E4h] [ebp-8h] BYREF
  const IntroDataBlendPass_t *pass; // [esp+1E8h] [ebp-4h]

  pass = (const IntroDataBlendPass_t *)this;
  v6 = materials->GetRenderContext(this: materials);
  if ( v6 != nullptr )
    v6->BeginRender(this: v6);
  g_viewscene_refractUpdateFrame = *(_DWORD *)(gpGlobals.m_Index + 4) - 1;
  ((void (__thiscall *)(IMatRenderContext *, _DWORD, _DWORD, _DWORD, int, int, int))v6->ClearColor4ub)(
    a1: v6,
    a2: 0,
    a3: 0,
    a4: 0,
    a5: 255,
    a6: a2,
    a7: a3);
  v7 = ParticleMgr();
  CParticleMgr::IncrementFrameCode(this: v7);
  if ( introData->m_bDrawPrimary )
  {
    x = introData->m_vecCameraView.x;
    playerView = *view;
    height = view + 1;
    playerView.origin.x = x;
    playerView.origin.y = introData->m_vecCameraView.y;
    playerView.origin.z = introData->m_vecCameraView.z;
    playerView.angles = introData->m_vecCameraViewAngles;
    if ( introData->m_playerViewFOV != 0.0 )
    {
      height = (const CViewSetup *)view->height;
      ratio = ((double (__thiscall *)(IVEngineClient *, int, const CViewSetup *))engine->GetScreenAspectRatio)(
                a1: engine,
                a2: view->width,
                a3: height)
            * 0.75;
      playerView.fov = ScaleFOVByWidthRatio(fovDegrees: introData->m_playerViewFOV, ratio);
    }
    g_pClientShadowMgr->PreRender(this: g_pClientShadowMgr);
    if ( r_flashlightdepthtexture.m_pParent != nullptr && r_flashlightdepthtexture.m_pParent->m_Value.m_nValue != 0 )
      g_pClientShadowMgr->ComputeShadowDepthTextures(this: g_pClientShadowMgr, a2: &playerView);
    SetupCurrentView(
      a1: (int)&actualRect,
      a2: (int)height,
      vecOrigin: &playerView.origin,
      angles: &playerView.angles,
      viewID: VIEW_INTRO_PLAYER,
      bDrawWorldNormal: false,
      bCullFrontFaces: false);
    IGameSystem::PreRenderAllSystems();
    v10 = (CViewRender *)pass;
    v11 = render->__vftable;
    v12 = (*(int (__thiscall **)(const IntroDataBlendPass_t *, int, Vector *, unsigned int *))(pass->m_BlendMode + 160))(
            a1: pass,
            a2: 1,
            a3: &playerView.origin,
            a4: &visFlags);
    ((void (__thiscall *)(IVRenderView *, _DWORD))v11->ViewSetupVisEx)(a1: render, a2: v12);
    v13 = render->__vftable;
    v14 = (int)v10->GetFrustum(this: v10);
    v13->Push3DView_2(this: render, a2: v6, a3: &playerView, a4: 3, a5: nullptr, a6: (VPlane *)v14);
    CViewRender::DrawWorldAndEntities(
      this: v10,
      bDrawSkybox: true,
      viewIn: &playerView,
      nClearFlags: 3,
      pCustomVisibility: nullptr);
    v15 = render->__vftable;
    v16 = (int)v10->GetFrustum(this: v10);
    v15->PopView(this: render, a2: v6, a3: (VPlane *)v16);
    if ( r_flashlightdepthtexture.m_pParent != nullptr && r_flashlightdepthtexture.m_pParent->m_Value.m_nValue != 0 )
      g_pClientShadowMgr->UnlockAllShadowDepthTextures(this: g_pClientShadowMgr);
  }
  else
  {
    v6->ClearBuffers(this: v6, a2: true, a3: true, a4: false);
  }
  v17 = view;
  UpdateScreenEffectTexture(
    a1: (int)v6,
    a2: (int)view,
    textureIndex: 0,
    x: *(_QWORD *)&view->x,
    w: *(_QWORD *)&view->width,
    bDestFullScreen: false,
    pActualRect: &actualRect);
  g_pClientShadowMgr->PreRender(this: g_pClientShadowMgr);
  if ( r_flashlightdepthtexture.m_pParent != nullptr && r_flashlightdepthtexture.m_pParent->m_Value.m_nValue != 0 )
    g_pClientShadowMgr->ComputeShadowDepthTextures(this: g_pClientShadowMgr, a2: v17);
  g_vecCurrentRenderOrigin = v17->origin;
  g_vecCurrentRenderAngles = v17->angles;
  ComputeCameraVariables(
    vecOrigin: &v17->origin,
    vecAngles: &v17->angles,
    pVecForward: &g_vecCurrentVForward,
    pVecRight: &g_vecCurrentVRight,
    pVecUp: &g_vecCurrentVUp,
    pMatCamInverse: &g_matCurrentCamInverse);
  s_bCanAccessCurrentView = true;
  GetScreenFadeDistances = ::view->GetScreenFadeDistances;
  g_CurrentViewID = VIEW_INTRO_CAMERA;
  GetScreenFadeDistances(this: ::view, a2: (float *)&pModeVar, a3: (float *)&view);
  ((void (__thiscall *)(IVModelInfoClient *, IMaterialVar *, const CViewSetup *))modelinfo->SetViewScreenFadeRange)(
    a1: modelinfo,
    a2: pModeVar,
    a3: view);
  v19 = materials->GetRenderContext(this: materials);
  if ( v19 != nullptr )
    v19->BeginRender(this: v19);
  v19->SetIntRenderingParameter(this: v19, a2: 10, a3: 0);
  if ( mat_lpreview_mode.m_pParent != nullptr )
  {
    m_nValue = mat_lpreview_mode.m_pParent->m_Value.m_nValue;
    if ( m_nValue == -1 )
      goto LABEL_23;
  }
  else
  {
    m_nValue = 0;
  }
  v19->SetIntRenderingParameter(this: v19, a2: 0, a3: m_nValue);
LABEL_23:
  v19->EndRender(this: v19);
  v19->Release(this: v19);
  IGameSystem::PreRenderAllSystems();
  v21 = render->__vftable;
  v22 = (*(int (__thiscall **)(const IntroDataBlendPass_t *, int, Vector *, unsigned int *))(pass->m_BlendMode + 160))(
          a1: pass,
          a2: 1,
          a3: &v17->origin,
          a4: &visFlags);
  ((void (__thiscall *)(IVRenderView *, _DWORD))v21->ViewSetupVisEx)(a1: render, a2: v22);
  v6->ClearColor4ub(this: v6, a2: 0, a3: 0, a4: 0, a5: 255u);
  CViewRender::DrawWorldAndEntities(
    this: (CViewRender *)pass,
    bDrawSkybox: true,
    viewIn: v17,
    nClearFlags: 3,
    pCustomVisibility: nullptr);
  UpdateScreenEffectTexture(
    a1: (int)v6,
    a2: (int)v17,
    textureIndex: 1,
    x: *(_QWORD *)&v17->x,
    w: *(_QWORD *)&v17->width,
    bDestFullScreen: false,
    pActualRect: nullptr);
  v23 = materials->FindMaterial(
          this: materials,
          a2: "scripted/intro_screenspaceeffect",
          a3: "Other textures",
          a4: 1,
          a5: 0);
  FindVar = v23->FindVar;
  pOverlayMaterial = v23;
  v25 = FindVar(this: v23, a2: "$mode", a3: nullptr, a4: true);
  v26.__vftable = v23->__vftable;
  pModeVar = v25;
  v27 = v26.FindVar(this: v23, a2: "$alpha", a3: nullptr, a4: true);
  v28 = v6->__vftable;
  v29 = v27;
  pAlphaVar = v27;
  v28->ClearBuffers(this: v6, a2: true, a3: true, a4: false);
  v6->MatrixMode(this: v6, a2: MATERIAL_VIEW);
  v6->PushMatrix(this: v6);
  v6->LoadIdentity(this: v6);
  v6->MatrixMode(this: v6, a2: MATERIAL_PROJECTION);
  v6->PushMatrix(this: v6);
  v6->LoadIdentity(this: v6);
  v30 = 0;
  for ( view = nullptr; v30 < introData->m_Passes.m_Size; view = (const CViewSetup *)v30 )
  {
    m_pMemory = introData->m_Passes.m_Memory.m_pMemory;
    m_Alpha = m_pMemory[v30].m_Alpha;
    v33 = &m_pMemory[v30];
    pass = v33;
    if ( m_Alpha != 0.0 )
    {
      m_BlendMode = v33->m_BlendMode;
      if ( v33->m_BlendMode >= 0 && m_BlendMode <= 9 )
      {
        pModeVar->SetIntValue(this: pModeVar, a2: m_BlendMode);
        v33 = pass;
      }
      ((void (__thiscall *)(IMaterialVar *, _DWORD))v29->SetFloatValue)(a1: v29, a2: LODWORD(v33->m_Alpha));
      FullFrameFrameBufferTexture = GetFullFrameFrameBufferTexture(textureIndex: 0);
      v36 = FullFrameFrameBufferTexture->__vftable;
      pass = (const IntroDataBlendPass_t *)&v6->DrawScreenSpaceRectangle;
      v37 = ((int (__thiscall *)(ITexture *, _DWORD, int, int))v36->GetActualHeight)(
              a1: FullFrameFrameBufferTexture,
              a2: 0,
              a3: 1,
              a4: 1);
      v38 = ((int (__thiscall *)(ITexture *, int))FullFrameFrameBufferTexture->GetActualWidth)(
              a1: FullFrameFrameBufferTexture,
              a2: v37);
      ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))pass->m_BlendMode)(
        a1: v6,
        a2: pOverlayMaterial,
        a3: v17->x,
        a4: v17->y,
        a5: v17->width,
        a6: v17->height,
        a7: (float)actualRect.x,
        a8: (float)actualRect.y,
        a9: (float)(actualRect.width + actualRect.x - 1),
        a10: (float)(actualRect.height + actualRect.y - 1),
        a11: v38);
      v29 = pAlphaVar;
      v30 = (int)view;
    }
    ++v30;
  }
  v6->MatrixMode(this: v6, a2: MATERIAL_VIEW);
  v6->PopMatrix(this: v6);
  v6->MatrixMode(this: v6, a2: MATERIAL_PROJECTION);
  v6->PopMatrix(this: v6);
  v39 = materials->GetRenderContext(this: materials);
  v40 = v39;
  if ( v39 != nullptr )
    v39->BeginRender(this: v39);
  v40->FogMode(this: v40, a2: MATERIAL_FOG_NONE);
  v40->EndRender(this: v40);
  v40->Release(this: v40);
  CGlowOverlay::DrawOverlays(a1: (int)v17, bCacheFullSceneState: *((_BYTE *)v17 + 240) >> 7);
  PixelVisibility_EndCurrentView();
  width = (const IntroData_t *)v17->width;
  v42 = (IMaterialVar *)v17->x;
  v43 = v17->height;
  view = (const CViewSetup *)v17->y;
  introData = width;
  v44 = engine->__vftable;
  pAlphaVar = v42;
  if ( !v44->IsHammerRunning(this: engine) )
    g_pScreenSpaceEffects->RenderEffects(
      this: g_pScreenSpaceEffects,
      a2: (int)pAlphaVar,
      a3: (int)view,
      a4: (int)introData,
      a5: v43);
  engine->Sound_ExtraUpdate(this: engine);
  CDebugViewRender::Draw3DDebuggingInfo(view: v17);
  v45 = ParticleMgr();
  CParticleMgr::PostRender(this: v45);
  s_bCanAccessCurrentView = false;
  if ( r_flashlightdepthtexture.m_pParent != nullptr && r_flashlightdepthtexture.m_pParent->m_Value.m_nValue != 0 )
    g_pClientShadowMgr->UnlockAllShadowDepthTextures(this: g_pClientShadowMgr);
  v6->EndRender(this: v6);
  v6->Release(this: v6);
}

//------------------------------------------------------------------------------
// Address: 0x101A2710
// Name: public: static struct ClientWorldListInfo_t __near * ClientWorldListInfo_t::AllocPooled(struct ClientWorldListInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
ClientWorldListInfo_t *__cdecl ClientWorldListInfo_t::AllocPooled(const ClientWorldListInfo_t *exemplar)
{
  TSLNodeBase_t *v1; // eax
  _DWORD *v2; // edi
  _DWORD *v3; // eax
  char *v4; // ebx
  unsigned int v5; // esi

  v1 = CTSListBase::Pop(this: &ClientWorldListInfo_t::gm_Pool.m_AvailableObjects);
  v2 = nullptr;
  if ( v1 != nullptr )
  {
    v2 = *((_DWORD **)&v1->Next + 1);
    C_BaseEntity::operator delete(pMem: v1);
  }
  else
  {
    v3 = MemAlloc_Alloc(nSize: 0x20u);
    if ( v3 != nullptr )
    {
      v3[1] = 1;
      *v3 = &ClientWorldListInfo_t::`vftable';
      *((_QWORD *)v3 + 1) = 0;
      *((_QWORD *)v3 + 2) = 0;
      v3[6] = 0;
      *((_BYTE *)v3 + 28) = 0;
      v2 = v3;
    }
  }
  v4 = (char *)v2[5];
  v5 = (16 * exemplar->m_LeafCount + 4095) & 0xFFFFF000;
  if ( v4 == nullptr || (_InterlockedExchangeAdd(v2 + 1, 1u), _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: v4) < v5) )
    v4 = (char *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v4, a3: v5);
  v2[5] = v4;
  v2[6] = &v4[8 * exemplar->m_LeafCount];
  *((_BYTE *)v2 + 28) = 1;
  return (ClientWorldListInfo_t *)v2;
}

//------------------------------------------------------------------------------
// Address: 0x101A27D0
// Name: private: virtual bool ClientWorldListInfo_t::OnFinalRelease(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall ClientWorldListInfo_t::OnFinalRelease(ClientWorldListInfo_t *this)
{
  TSLNodeBase_t *v2; // eax

  if ( !this->m_bPooledAlloc )
    return 1;
  v2 = (TSLNodeBase_t *)MemAlloc_Alloc(nSize: 8u);
  if ( v2 != nullptr )
  {
    *((_DWORD *)&v2->Next + 1) = this;
    CTSListBase::Push(this: &ClientWorldListInfo_t::gm_Pool.m_AvailableObjects, pNode: v2);
  }
  else
  {
    CTSListBase::Push(this: &ClientWorldListInfo_t::gm_Pool.m_AvailableObjects, pNode: nullptr);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A2810
// Name: protected: void CRendering3dView::PruneWorldListInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRendering3dView::PruneWorldListInfo(CRendering3dView *this)
{
  CRendering3dView *v1; // ebx
  int v2; // edi
  ClientWorldListInfo_t *m_pWorldListInfo; // eax
  ClientWorldListInfo_t *v4; // esi
  ClientWorldListInfo_t *v5; // eax
  bool v6; // zf
  bool v7; // al
  int v8; // edi
  WorldListLeafData_t *m_pLeafDataList; // eax
  WorldListLeafData_t *v10; // eax
  int m_LeafCount; // edx
  WorldListLeafData_t *v12; // ecx
  volatile signed __int32 *v13; // edi
  bool bRenderingUnderwater; // [esp+Fh] [ebp-1h]

  v1 = this;
  v2 = this->m_DrawFlags & 0x30;
  if ( v2 == 48 || v2 == 32 && !this->m_pWorldListInfo->m_bHasWater )
    return;
  m_pWorldListInfo = this->m_pWorldListInfo;
  v4 = nullptr;
  if ( m_pWorldListInfo->m_LeafCount > 0 && v2 != 0 )
  {
    v5 = ClientWorldListInfo_t::AllocPooled(exemplar: m_pWorldListInfo);
LABEL_9:
    v4 = v5;
    goto LABEL_10;
  }
  v5 = (ClientWorldListInfo_t *)MemAlloc_Alloc(nSize: 0x20u);
  if ( v5 != nullptr )
  {
    v5->m_iRefs = 1;
    v5->__vftable = (ClientWorldListInfo_t_vtbl *)&ClientWorldListInfo_t::`vftable';
    *(_QWORD *)&v5->m_ViewFogVolume = 0;
    *(_QWORD *)&v5->m_bHasWater = 0;
    v5->m_pOriginalLeafIndex = nullptr;
    v5->m_bPooledAlloc = false;
    goto LABEL_9;
  }
LABEL_10:
  v4->m_ViewFogVolume = v1->m_pWorldListInfo->m_ViewFogVolume;
  v4->m_bHasWater = v1->m_pWorldListInfo->m_bHasWater;
  v4->m_LeafCount = 0;
  if ( v2 == 16 )
    v6 = !v1->m_pWorldListInfo->m_bHasWater;
  else
    v6 = v2 == 0;
  if ( !v6 )
  {
    v7 = (v2 & 0x10) != 0;
    v8 = 0;
    for ( bRenderingUnderwater = v7; v8 < v1->m_pWorldListInfo->m_LeafCount; ++v8 )
    {
      m_pLeafDataList = v1->m_pWorldListInfo->m_pLeafDataList;
      v6 = m_pLeafDataList[v8].waterData == -1;
      v10 = &m_pLeafDataList[v8];
      if ( bRenderingUnderwater == !v6 )
      {
        m_LeafCount = v4->m_LeafCount;
        v12 = v4->m_pLeafDataList;
        *(_DWORD *)&v12[m_LeafCount].leafIndex = *(_DWORD *)&v10->leafIndex;
        v1 = this;
        *(_DWORD *)&v12[m_LeafCount].firstTranslucentSurface = *(_DWORD *)&v10->firstTranslucentSurface;
        v4->m_pOriginalLeafIndex[v4->m_LeafCount++] = v8;
      }
    }
  }
  v13 = (volatile signed __int32 *)v1->m_pWorldListInfo;
  if ( _InterlockedDecrement(v13 + 1) == 0
    && (*(unsigned __int8 (__thiscall **)(volatile signed __int32 *))(*v13 + 4))(a1: v13) != 0 )
  {
    (**(void (__thiscall ***)(volatile signed __int32 *, int))v13)(a1: v13, a2: 1);
  }
  v1->m_pWorldListInfo = v4;
}

//------------------------------------------------------------------------------
// Address: 0x101A2B70
// Name: FogOverrideCallback
// Source: json
//------------------------------------------------------------------------------
void __cdecl FogOverrideCallback(IConVar *pConVar)
{
  C_BasePlayer *LocalPlayer; // ebx
  float *v2; // eax
  fogparams_t *v3; // esi
  float value; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm3_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  float m_Value; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  float v13; // xmm2_4
  const char *v14; // eax
  IClientMode *ClientMode; // eax
  bool v16; // al
  C_BasePlayer *v17; // eax
  float v18; // xmm0_4
  C_BasePlayer *v19; // eax
  float v20; // xmm0_4
  C_BasePlayer *v21; // edi
  float v22; // xmm0_4
  IClientMode *v23; // eax
  const char *v24; // eax
  float v25; // xmm1_4
  IClientMode *v26; // eax
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm3_4
  float v30; // xmm2_4
  float fogColor[3]; // [esp+24h] [ebp-14h] BYREF
  ConVarRef var; // [esp+30h] [ebp-8h] BYREF

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
  {
    ConVarRef::ConVarRef(this: &var, pConVar);
    if ( var.m_pConVarState->m_Value.m_nValue == -1 )
    {
      v2 = (float *)LocalPlayer->GetFogParams(this: LocalPlayer);
      v3 = (fogparams_t *)v2;
      if ( v2 != nullptr )
      {
        v5 = v2[15];
        v6 = *(float *)(gpGlobals.m_Index + 12);
        if ( v5 <= v6 || (v7 = v2[8], v8 = v2[12], v7 == v8) )
          value = v2[8];
        else
          value = (float)((float)(1.0 - (float)((float)(v5 - v6) / v2[16])) * (float)(v8 - v7)) + v7;
      }
      else
      {
        value = 0.0;
      }
      ConVar::SetValue(this: (ConVar *)&fog_start.IConVar, value);
      if ( v3 != nullptr )
      {
        m_Value = v3->lerptime.m_Value;
        v11 = *(float *)(gpGlobals.m_Index + 12);
        if ( m_Value <= v11 || (v12 = v3->end.m_Value, v13 = v3->endLerpTo.m_Value, v12 == v13) )
          v9 = v3->end.m_Value;
        else
          v9 = (float)((float)(1.0 - (float)((float)(m_Value - v11) / v3->duration.m_Value)) * (float)(v13 - v12)) + v12;
      }
      else
      {
        v9 = 0.0;
      }
      ConVar::SetValue(this: (ConVar *)&fog_end.IConVar, value: v9);
      GetFogColor(pFogParams: v3, pColor: fogColor, ignoreOverride: true, ignoreHDRColorScale: true);
      v14 = VarArgs(
              format: "%.1f %.1f %.1f",
              (float)(fogColor[0] * 255.0),
              (float)(fogColor[1] * 255.0),
              (float)(fogColor[2] * 255.0));
      ConVar::SetValue(this: (ConVar *)&fog_color.IConVar, value: v14);
      v16 = (cl_leveloverview.m_pParent == nullptr || cl_leveloverview.m_pParent->m_Value.m_nValue == 0)
         && (ClientMode = GetClientMode(), ClientMode->ShouldDrawFog(this: ClientMode))
         && v3 != nullptr
         && v3->enable.m_Value;
      ConVar::SetValue(this: (ConVar *)&fog_enable.IConVar, value: v16);
      v17 = C_BasePlayer::GetLocalPlayer(nSlot: -1);
      if ( v17 != nullptr )
        v18 = v17->m_Local.m_skybox3d.fog.start.m_Value;
      else
        v18 = 0.0;
      ConVar::SetValue(this: (ConVar *)&fog_startskybox.IConVar, value: v18);
      v19 = C_BasePlayer::GetLocalPlayer(nSlot: -1);
      if ( v19 != nullptr )
        v20 = v19->m_Local.m_skybox3d.fog.end.m_Value;
      else
        v20 = 0.0;
      ConVar::SetValue(this: (ConVar *)&fog_endskybox.IConVar, value: v20);
      v21 = C_BasePlayer::GetLocalPlayer(nSlot: -1);
      if ( v21 != nullptr )
      {
        if ( cl_leveloverview.m_pParent != nullptr && cl_leveloverview.m_pParent->m_Value.m_nValue != 0 )
        {
          v22 = 1.0;
        }
        else
        {
          v23 = GetClientMode();
          if ( v23->ShouldDrawFog(this: v23) )
            v22 = v21->m_Local.m_skybox3d.fog.maxdensity.m_Value;
          else
            v22 = 1.0;
        }
      }
      else
      {
        v22 = 1.0;
      }
      ConVar::SetValue(this: (ConVar *)&fog_maxdensityskybox.IConVar, value: v22);
      GetSkyboxFogColor(pColor: fogColor, ignoreOverride: true, ignoreHDRColorScale: true);
      v24 = VarArgs(
              format: "%.1f %.1f %.1f",
              (float)(fogColor[0] * 255.0),
              (float)(fogColor[1] * 255.0),
              (float)(fogColor[2] * 255.0));
      ConVar::SetValue(this: (ConVar *)&fog_colorskybox.IConVar, value: v24);
      ConVar::SetValue(
        this: (ConVar *)&fog_enableskybox.IConVar,
        value: LocalPlayer->m_Local.m_skybox3d.fog.enable.m_Value);
      if ( v3 == nullptr
        || cl_leveloverview.m_pParent != nullptr && cl_leveloverview.m_pParent->m_Value.m_nValue != 0
        || (v26 = GetClientMode(), !v26->ShouldDrawFog(this: v26)) )
      {
        v25 = 1.0;
      }
      else
      {
        v27 = v3->lerptime.m_Value;
        v28 = *(float *)(gpGlobals.m_Index + 12);
        if ( v27 <= v28 || (v29 = v3->maxdensity.m_Value, v30 = v3->maxdensityLerpTo.m_Value, v29 == v30) )
          v25 = v3->maxdensity.m_Value;
        else
          v25 = (float)((float)(1.0 - (float)((float)(v27 - v28) / v3->duration.m_Value)) * (float)(v30 - v29)) + v29;
      }
      ConVar::SetValue(this: (ConVar *)&fog_maxdensity.IConVar, value: v25);
      ConVar::SetValue(this: (ConVar *)&fog_hdrcolorscale.IConVar, value: v3->HDRColorScale.m_Value);
      ConVar::SetValue(
        this: (ConVar *)&fog_hdrcolorscaleskybox.IConVar,
        value: LocalPlayer->m_Local.m_skybox3d.fog.HDRColorScale.m_Value);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A2F30
// Name: protected: void CViewRender::ViewDrawScene(bool,enum SkyboxVisibility_t,class CViewSetup const __near &,int,enum view_id_t,bool,int,struct ViewCustomVisibility_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRender::ViewDrawScene(
        CViewRender *this,
        bool bDrew3dSkybox,
        SkyboxVisibility_t nSkyboxVisible,
        const CViewSetup *view,
        int nClearFlags,
        view_id_t viewID,
        bool bDrawViewModel,
        int baseDrawFlags,
        ViewCustomVisibility_t *pCustomVisibility)
{
  int m_nValue; // eax
  CParticleMgr *v12; // eax
  IMatRenderContext *v13; // edi
  vgui::PropertyPage *v14; // ecx
  unsigned __int8 v15; // al
  IMatRenderContext *v16; // edi
  unsigned int visFlags; // [esp+20h] [ebp-4h] BYREF
  bool drawSkybox; // [esp+34h] [ebp+10h]

  g_viewscene_refractUpdateFrame = *(_DWORD *)(gpGlobals.m_Index + 4) - 1;
  g_pClientShadowMgr->PreRender(this: g_pClientShadowMgr);
  if ( viewID == VIEW_MAIN && (*((_BYTE *)view + 240) & 0x20) == 0 )
    g_pClientShadowMgr->ComputeShadowDepthTextures(this: g_pClientShadowMgr, a2: view);
  this->m_BaseDrawFlags = baseDrawFlags;
  SetupCurrentView(
    a1: (int)this,
    a2: (int)view,
    vecOrigin: &view->origin,
    angles: &view->angles,
    viewID,
    bDrawWorldNormal: (*((_BYTE *)view + 240) & 0x20) != 0,
    bCullFrontFaces: (*((_BYTE *)view + 240) & 0x40) != 0);
  IGameSystem::PreRenderAllSystems();
  CViewRender::SetupVis(this, view, &visFlags, pCustomVisibility);
  if ( !bDrew3dSkybox && nSkyboxVisible == SKYBOX_NOT_VISIBLE && (visFlags & 1) != 0 )
  {
    nClearFlags |= 1u;
    SetClearColorToFogColor();
  }
  if ( r_skybox.m_pParent != nullptr )
    m_nValue = r_skybox.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  drawSkybox = m_nValue != 0;
  if ( bDrew3dSkybox || nSkyboxVisible == SKYBOX_NOT_VISIBLE )
    drawSkybox = false;
  v12 = ParticleMgr();
  CParticleMgr::IncrementFrameCode(this: v12);
  CViewRender::DrawWorldAndEntities(this, bDrawSkybox: drawSkybox, viewIn: view, nClearFlags, pCustomVisibility);
  v13 = materials->GetRenderContext(this: materials);
  if ( v13 != nullptr )
    v13->BeginRender(this: v13);
  v13->FogMode(this: v13, a2: MATERIAL_FOG_NONE);
  v13->EndRender(this: v13);
  v13->Release(this: v13);
  v15 = *((_BYTE *)view + 240);
  if ( (v15 & 0x20) == 0 )
    CGlowOverlay::DrawOverlays(a1: (int)view, bCacheFullSceneState: v15 >> 7);
  if ( g_CurrentViewID == VIEW_MAIN && (*((_BYTE *)view + 240) & 0x20) == 0 )
    PixelVisibility_EndCurrentView();
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: v14);
  if ( r_flashlightvolumetrics.m_pParent != nullptr
    && r_flashlightvolumetrics.m_pParent->m_Value.m_nValue != 0
    && viewID != VIEW_SHADOW_DEPTH_TEXTURE
    && (*((_BYTE *)view + 240) & 0x20) == 0 )
  {
    g_pClientShadowMgr->DrawVolumetrics(this: g_pClientShadowMgr, a2: view);
  }
  engine->Sound_ExtraUpdate(this: engine);
  CDebugViewRender::Draw3DDebuggingInfo(view);
  ((void (__stdcall *)(_DWORD, _DWORD))clienteffects->DrawEffects)(
    a1: COERCE_UNSIGNED_INT64(*(float *)(gpGlobals.m_Index + 16)),
    a2: HIDWORD(COERCE_UNSIGNED_INT64(*(float *)(gpGlobals.m_Index + 16))));
  SetFXCreationAllowed(state: false);
  IGameSystem::PostRenderAllSystems();
  s_bCanAccessCurrentView = false;
  if ( viewID == VIEW_MAIN && (*((_BYTE *)view + 240) & 0x20) == 0 )
    g_pClientShadowMgr->UnlockAllShadowDepthTextures(this: g_pClientShadowMgr);
  v16 = materials->GetRenderContext(this: materials);
  if ( v16 != nullptr )
    v16->BeginRender(this: v16);
  v16->SetIntRenderingParameter(this: v16, a2: 0, a3: 0);
  if ( (*((_BYTE *)view + 240) & 0x40) != 0 )
    v16->FlipCulling(this: v16, a2: false);
  v16->EndRender(this: v16);
  v16->Release(this: v16);
}

//------------------------------------------------------------------------------
// Address: 0x101A3190
// Name: protected: void CViewRender::GetLetterBoxRectangles(int,class CViewSetup const __near &,class CUtlVector<struct vrect_t,class CUtlMemory<struct vrect_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRender::GetLetterBoxRectangles(
        CViewRender *this,
        int nSlot,
        const CViewSetup *view,
        CUtlVector<vrect_t,CUtlMemory<vrect_t,int> > *vecLetterBoxRectangles)
{
  const CViewSetup *v4; // esi
  int width; // ecx
  int v6; // edi
  int v7; // edx
  int v8; // eax
  const CViewSetup *v9; // ecx
  CUtlVector<CHudMenu::ProcessedLine,CUtlMemory<CHudMenu::ProcessedLine,int> > *v10; // ebx
  int m_Size; // ecx
  int y; // edx
  int v13; // eax
  int v14; // edx
  int v15; // edx
  int v16; // ecx
  int v17; // eax
  int v18; // eax
  vrect_t r; // [esp+Ch] [ebp-28h] BYREF
  int w; // [esp+20h] [ebp-14h] BYREF
  int bottom; // [esp+24h] [ebp-10h]
  int x; // [esp+28h] [ebp-Ch] BYREF
  int h; // [esp+2Ch] [ebp-8h] BYREF
  int right; // [esp+30h] [ebp-4h]

  VGui_GetPanelBounds(slot: nSlot, &x, y: &nSlot, &w, &h);
  v4 = view;
  width = view->width;
  v6 = view->y + view->height;
  v7 = view->x;
  right = x + w;
  v8 = h + nSlot;
  v9 = (const CViewSetup *)(v7 + width);
  v10 = (CUtlVector<CHudMenu::ProcessedLine,CUtlMemory<CHudMenu::ProcessedLine,int> > *)vecLetterBoxRectangles;
  bottom = h + nSlot;
  view = v9;
  if ( v7 != x )
  {
    r.x = x;
    r.y = nSlot;
    m_Size = vecLetterBoxRectangles->m_Size;
    r.width = v7 + 1;
    r.height = h;
    CUtlVector<vrect_t,CUtlMemory<vrect_t,int>>::InsertBefore(
      this: (CUtlVector<CHudMenu::ProcessedLine,CUtlMemory<CHudMenu::ProcessedLine,int> > *)vecLetterBoxRectangles,
      elem: m_Size,
      src: (const CHudMenu::ProcessedLine *)&r);
    v8 = bottom;
    v9 = view;
  }
  y = v4->y;
  if ( y != nSlot )
  {
    v13 = v4->x;
    r.y = nSlot;
    r.height = y + 1;
    v14 = v10->m_Size;
    r.x = v13;
    r.width = v4->width;
    CUtlVector<vrect_t,CUtlMemory<vrect_t,int>>::InsertBefore(
      this: v10,
      elem: v14,
      src: (const CHudMenu::ProcessedLine *)&r);
    v8 = bottom;
    v9 = view;
  }
  v15 = right;
  if ( v8 != v6 )
  {
    r.x = v4->x;
    v16 = v4->width;
    r.y = v6 - 1;
    r.height = v8 - v6 + 1;
    v17 = v10->m_Size;
    r.width = v16;
    CUtlVector<vrect_t,CUtlMemory<vrect_t,int>>::InsertBefore(
      this: v10,
      elem: v17,
      src: (const CHudMenu::ProcessedLine *)&r);
    v15 = right;
    v9 = view;
  }
  if ( (const CViewSetup *)v15 != v9 )
  {
    r.x = (int)&v9[-1] + 243;
    r.width = v15 - (_DWORD)v9 + 1;
    r.y = nSlot;
    v18 = v10->m_Size;
    r.height = h;
    CUtlVector<vrect_t,CUtlMemory<vrect_t,int>>::InsertBefore(
      this: v10,
      elem: v18,
      src: (const CHudMenu::ProcessedLine *)&r);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A32B0
// Name: protected: void CViewRender::SetupMain3DView(int,class CViewSetup const __near &,class CViewSetup const __near &,int __near &,class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CViewRender::SetupMain3DView(
        CViewRender *this@<ecx>,
        int a2@<edi>,
        int nSlot,
        const CViewSetup *view,
        const CViewSetup *hudViewSetup,
        int *nClearFlags,
        ITexture *pRenderTarget)
{
  int *v7; // ebx
  int v8; // eax
  int v10; // ecx
  int v11; // edi
  IVRenderView_vtbl *v12; // ebx
  VPlane *v13; // eax
  IVRenderView_vtbl *v14; // ebx
  VPlane *v15; // eax
  IVRenderView_vtbl *v16; // eax
  CViewSetup letterBoxViewSetup; // [esp+8h] [ebp-10Ch] BYREF
  CUtlVector<vrect_t,CUtlMemory<vrect_t,int> > letterbox; // [esp+FCh] [ebp-18h] BYREF
  int nDepthStencilFlags; // [esp+110h] [ebp-4h]
  IVRenderView_vtbl *nSlota; // [esp+11Ch] [ebp+8h]
  IVRenderView_vtbl *nSlotb; // [esp+11Ch] [ebp+8h]
  IVRenderView_vtbl *nSlotc; // [esp+11Ch] [ebp+8h]

  v7 = nClearFlags;
  v8 = *nClearFlags & 0x22;
  *nClearFlags &= ~v8;
  v10 = *nClearFlags;
  nDepthStencilFlags = v8;
  if ( (v10 & 1) != 0 )
    *nClearFlags = v8 | v10;
  v11 = ((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(a1: materials, a2);
  if ( v11 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 8))(a1: v11);
  memset(&letterbox, 0, sizeof(letterbox));
  CViewRender::GetLetterBoxRectangles(this, nSlot, view, vecLetterBoxRectangles: &letterbox);
  if ( letterbox.m_Size != 0 )
  {
    letterBoxViewSetup.m_flAspectRatio = 0.0;
    letterBoxViewSetup.m_flNearBlurDepth = 20.0;
    letterBoxViewSetup.m_flNearFocusDepth = 100.0;
    letterBoxViewSetup.m_flFarFocusDepth = 250.0;
    letterBoxViewSetup.m_nDoFQuality = 0;
    letterBoxViewSetup.m_bCustomViewMatrix = false;
    letterBoxViewSetup.x = 0;
    letterBoxViewSetup.y = 0;
    letterBoxViewSetup.m_flFarBlurDepth = 1000.0;
    letterBoxViewSetup.m_flNearBlurRadius = 10.0;
    letterBoxViewSetup.m_flFarBlurRadius = 5.0;
    letterBoxViewSetup.m_nMotionBlurMode = MOTION_BLUR_GAME;
    *((_BYTE *)&letterBoxViewSetup + 240) = 4;
    VGui_GetTrueScreenSize(w: &letterBoxViewSetup.width, h: &letterBoxViewSetup.height);
    v12 = render->__vftable;
    v13 = this->GetFrustum(this);
    v12->Push2DView(
      this: render,
      a2: (IMatRenderContext *)v11,
      a3: &letterBoxViewSetup,
      a4: 0,
      a5: pRenderTarget,
      a6: v13);
    CViewRender::DrawLetterBoxRectangles(this, nSlot, vecLetterBoxRectangles: &letterbox);
    v14 = render->__vftable;
    v15 = this->GetFrustum(this);
    v14->PopView(this: render, a2: (IMatRenderContext *)v11, a3: v15);
    v7 = nClearFlags;
  }
  if ( g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) == HDR_TYPE_FLOAT )
  {
    if ( (*((_BYTE *)view + 240) & 0x10) != 0 )
    {
      nSlota = render->__vftable;
      letterBoxViewSetup.y = (int)this->GetFrustum(this);
      letterBoxViewSetup.x = (int)pRenderTarget;
      ((void (__thiscall *)(IVRenderView *))nSlota->Push3DView_2)(a1: render);
      goto LABEL_13;
    }
    (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v11 + 464))(a1: v11, a2: 11, a3: 1);
    nSlotb = render->__vftable;
    letterBoxViewSetup.x = ((int (__thiscall *)(CViewRender *, int))this->GetFrustum)(
                             a1: this,
                             a2: letterBoxViewSetup.y);
    v16 = nSlotb;
  }
  else
  {
    nSlotc = render->__vftable;
    letterBoxViewSetup.x = (int)this->GetFrustum(this);
    v16 = nSlotc;
  }
  ((void (__thiscall *)(IVRenderView *, int))v16->Push3DView_2)(a1: render, a2: v11);
LABEL_13:
  if ( v11 != 0 )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 12))(a1: v11);
    (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 4))(a1: v11);
  }
  *v7 ^= nDepthStencilFlags;
  if ( (*v7 & 1) != 0 )
    *v7 &= 0xFFFFFFFA;
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&letterbox);
}

//------------------------------------------------------------------------------
// Address: 0x101A3510
// Name: protected: bool CViewRender::DrawOneMonitor(class ITexture __near *,int,class C_PointCamera __near *,class CViewSetup const __near &,class C_BasePlayer __near *,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
char __thiscall CViewRender::DrawOneMonitor(
        CViewRender *this,
        ITexture *pRenderTarget,
        int cameraNum,
        C_PointCamera *pCameraEnt,
        float cameraView,
        C_BasePlayer *localPlayer,
        int x,
        int y,
        int width,
        int height)
{
  C_PointCamera *v10; // ebx
  bool IsFogEnabled; // al
  fogparams_t *v12; // edi
  bool m_Value; // zf
  double FogStart; // st7
  double FogEnd; // st7
  double v17; // st7
  double FogMaxDensity; // st7
  C_PointCamera_vtbl *v19; // eax
  float *v20; // eax
  const QAngle *(__thiscall *GetAbsAngles)(IClientEntity *); // edx
  float v22; // xmm0_4
  IMatRenderContext *v23; // esi
  IVRenderView_vtbl *v24; // ebx
  VPlane *v25; // eax
  CViewRender *v26; // ebx
  VPlane *(__thiscall *GetFrustum)(struct CViewRender *); // edx
  int v28; // eax
  FlashlightState_t nullFlashlight; // [esp+0h] [ebp-288h] BYREF
  VMatrix matIdentity; // [esp+FCh] [ebp-18Ch] BYREF
  fogparams_t oldFogParams; // [esp+13Ch] [ebp-14Ch] BYREF
  CViewSetup monitorView; // [esp+188h] [ebp-100h] BYREF
  CViewRender *v33; // [esp+27Ch] [ebp-Ch]
  float flOldZFar; // [esp+280h] [ebp-8h]
  bool fogEnabled; // [esp+286h] [ebp-2h]
  unsigned __int8 b; // [esp+287h] [ebp-1h] BYREF

  v33 = this;
  if ( (_S7_20 & 1) == 0 )
  {
    _S7_20 |= 1u;
    counter_3.m_pCounter = CVProfile::FindOrCreateCounter(
                             this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                             a2: "cameras rendered",
                             a3: COUNTER_GROUP_DEFAULT);
    atexit(func: CViewRender::DrawOneMonitor_::_4_::_dynamic_atexit_destructor_for___counter__);
  }
  ++*counter_3.m_pCounter;
  v10 = pCameraEnt;
  oldFogParams.__vftable = (fogparams_t_vtbl *)&fogparams_t::`vftable';
  flOldZFar = 0.0;
  IsFogEnabled = C_PointCamera::IsFogEnabled(this: pCameraEnt);
  monitorView = *(CViewSetup *)cameraView;
  v12 = nullptr;
  fogEnabled = IsFogEnabled;
  if ( IsFogEnabled )
  {
    if ( localPlayer == nullptr )
      return 0;
    v12 = localPlayer->GetFogParams(this: localPlayer);
    fogparams_t::operator=(this: &oldFogParams, __that: v12);
    m_Value = v12->enable.m_Value;
    flOldZFar = *(float *)(LODWORD(cameraView) + 124);
    if ( !m_Value )
    {
      v12->NetworkStateChanged(this: v12, a2: &v12->enable);
      v12->enable.m_Value = true;
    }
    FogStart = C_PointCamera::GetFogStart(this: v10);
    cameraView = FogStart;
    if ( v12->start.m_Value != FogStart )
    {
      v12->NetworkStateChanged(this: v12, a2: &v12->start);
      v12->start.m_Value = cameraView;
    }
    FogEnd = C_PointCamera::GetFogEnd(this: v10);
    cameraView = FogEnd;
    if ( v12->end.m_Value != FogEnd )
    {
      v12->NetworkStateChanged(this: v12, a2: &v12->end);
      v12->end.m_Value = cameraView;
    }
    v17 = C_PointCamera::GetFogEnd(this: v10);
    cameraView = v17;
    if ( v12->farz.m_Value != v17 )
    {
      v12->NetworkStateChanged(this: v12, a2: &v12->farz);
      v12->farz.m_Value = cameraView;
    }
    FogMaxDensity = C_PointCamera::GetFogMaxDensity(this: v10);
    cameraView = FogMaxDensity;
    if ( v12->maxdensity.m_Value != FogMaxDensity )
    {
      v12->NetworkStateChanged(this: v12, a2: &v12->maxdensity);
      v12->maxdensity.m_Value = cameraView;
    }
    C_PointCamera::GetFogColor(
      this: v10,
      r: (unsigned __int8 *)&pCameraEnt + 3,
      g: (unsigned __int8 *)&localPlayer + 3,
      &b);
    LOBYTE(cameraView) = HIBYTE(pCameraEnt);
    if ( v12->colorPrimary.m_Value.r != HIBYTE(pCameraEnt) )
    {
      v12->NetworkStateChanged(this: v12, a2: &v12->colorPrimary);
      v12->colorPrimary.m_Value.r = LOBYTE(cameraView);
    }
    LOBYTE(cameraView) = HIBYTE(localPlayer);
    if ( v12->colorPrimary.m_Value.g != HIBYTE(localPlayer) )
    {
      v12->NetworkStateChanged(this: v12, a2: &v12->colorPrimary);
      v12->colorPrimary.m_Value.g = LOBYTE(cameraView);
    }
    LOBYTE(cameraView) = b;
    if ( v12->colorPrimary.m_Value.b != b )
    {
      v12->NetworkStateChanged(this: v12, a2: &v12->colorPrimary);
      v12->colorPrimary.m_Value.b = LOBYTE(cameraView);
    }
    monitorView.zFar = C_PointCamera::GetFogEnd(this: v10);
  }
  monitorView.width = width;
  monitorView.height = height;
  v19 = v10->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  monitorView.x = x;
  monitorView.y = y;
  v20 = (float *)v19->GetAbsOrigin(this: v10);
  monitorView.origin.x = *v20;
  monitorView.origin.y = v20[1];
  GetAbsAngles = v10->GetAbsAngles;
  monitorView.origin.z = v20[2];
  monitorView.angles = *GetAbsAngles(this: v10);
  monitorView.fov = C_PointCamera::GetFOV(this: v10);
  m_Value = !v10->m_bUseScreenAspectRatio;
  monitorView.m_bOrtho = false;
  if ( m_Value )
    v22 = 1.0;
  else
    v22 = 0.0;
  monitorView.m_flAspectRatio = v22;
  v23 = materials->GetRenderContext(this: materials);
  if ( v23 != nullptr )
    v23->BeginRender(this: v23);
  FlashlightState_t::FlashlightState_t(this: &nullFlashlight);
  MatrixSetIdentity(dst: &matIdentity);
  v23->SetFlashlightState(this: v23, a2: &nullFlashlight, a3: &matIdentity);
  v24 = render->__vftable;
  v25 = v33->GetFrustum(this: v33);
  v24->Push3DView_2(this: render, a2: v23, a3: &monitorView, a4: 3, a5: pRenderTarget, a6: v25);
  v26 = v33;
  CViewRender::ViewDrawScene(
    this: v33,
    bDrew3dSkybox: false,
    nSkyboxVisible: SKYBOX_2DSKYBOX_VISIBLE,
    view: &monitorView,
    nClearFlags: 0,
    viewID: VIEW_MONITOR,
    bDrawViewModel: false,
    baseDrawFlags: 0,
    pCustomVisibility: nullptr);
  GetFrustum = v26->GetFrustum;
  cameraView = *(float *)&render->__vftable;
  v28 = (int)GetFrustum(this: v26);
  (*(void (__thiscall **)(IVRenderView *, IMatRenderContext *, int))(LODWORD(cameraView) + 168))(
    a1: render,
    a2: v23,
    a3: v28);
  if ( fogEnabled )
  {
    if ( v12 != nullptr )
      fogparams_t::operator=(this: v12, __that: &oldFogParams);
    monitorView.zFar = flOldZFar;
  }
  v23->EndRender(this: v23);
  v23->Release(this: v23);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101A38D0
// Name: protected: void CViewRender::DrawMonitors(class CViewSetup const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewRender::DrawMonitors(CViewRender *this, const CViewSetup *cameraView)
{
  C_PointCamera *PointCameraList; // edi
  ITexture *CameraTexture; // esi
  int v4; // ebx
  C_BasePlayer *player; // [esp+8h] [ebp-Ch]
  int width; // [esp+Ch] [ebp-8h]
  int height; // [esp+10h] [ebp-4h]

  PointCameraList = GetPointCameraList();
  if ( PointCameraList != nullptr )
  {
    CameraTexture = GetCameraTexture();
    width = CameraTexture->GetActualWidth(this: CameraTexture);
    height = CameraTexture->GetActualHeight(this: CameraTexture);
    player = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    v4 = 0;
    do
    {
      if ( C_PointCamera::IsActive(this: PointCameraList)
        && !PointCameraList->IsDormant(this: &PointCameraList->IClientNetworkable)
        && CViewRender::DrawOneMonitor(
             this,
             pRenderTarget: CameraTexture,
             cameraNum: v4,
             pCameraEnt: PointCameraList,
             cameraView: *(float *)&cameraView,
             localPlayer: player,
             x: 0,
             y: 0,
             width,
             height) != 0 )
      {
        ++v4;
      }
      PointCameraList = PointCameraList->m_pNext;
    }
    while ( PointCameraList != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A3970
// Name: DrawOpaqueRenderables_DrawBrushModels
// Source: json
//------------------------------------------------------------------------------
void __usercall DrawOpaqueRenderables_DrawBrushModels(
        CUtlMemory<vgui::TreeNode *,int> *pDeferClippedOpaqueRenderables_Out@<eax>,
        CClientRenderablesList::CEntry **pBrushEntities,
        int nBrushEntityCount,
        int bShadowDepth)
{
  int v4; // ebx
  void *v6; // esp
  int v7; // eax
  CClientRenderablesList::CEntry *v8; // esi
  IClientModelRenderable *v9; // eax
  int v10; // eax
  CClientRenderablesList::CEntry *v11; // ebx
  int m_pMemory; // esi
  int m_nAllocationCount; // eax
  CClientRenderablesList::CEntry **v14; // ecx
  int v15; // eax
  CClientRenderablesList::CEntry **v16; // esi
  bool v17; // zf
  IClientRenderable *m_pRenderable; // ecx
  int v19; // esi
  int v20; // edi
  CClientRenderablesList::CEntry *v21; // eax
  IClientRenderable *v22; // ebx
  int v23; // esi
  _BYTE v24[12]; // [esp+0h] [ebp-3Ch] BYREF
  CUtlVector<ModelRenderSystemData_t,CUtlMemory<ModelRenderSystemData_t,int> > arrBrushRenderables; // [esp+Ch] [ebp-30h] BYREF
  ModelRenderSystemData_t data; // [esp+20h] [ebp-1Ch] BYREF
  IClientRenderable *v27; // [esp+2Ch] [ebp-10h]
  int i; // [esp+30h] [ebp-Ch]
  int nRemainingBrushes; // [esp+34h] [ebp-8h]
  RenderableInstance_t instance; // [esp+3Bh] [ebp-1h] BYREF

  v4 = nBrushEntityCount;
  if ( r_drawbrushmodels.m_pParent != nullptr && r_drawbrushmodels.m_pParent->m_Value.m_nValue != 0 )
  {
    nRemainingBrushes = nBrushEntityCount;
    if ( cl_brushfastpath.m_pParent != nullptr && cl_brushfastpath.m_pParent->m_Value.m_nValue != 0 )
    {
      nRemainingBrushes = 0;
      v6 = alloca(12 * nBrushEntityCount);
      arrBrushRenderables.m_Memory.m_pMemory = (ModelRenderSystemData_t *)v24;
      arrBrushRenderables.m_pElements = (ModelRenderSystemData_t *)v24;
      v7 = 0;
      arrBrushRenderables.m_Memory.m_nAllocationCount = nBrushEntityCount;
      arrBrushRenderables.m_Memory.m_nGrowSize = -1;
      arrBrushRenderables.m_Size = 0;
      for ( i = 0; v7 < nBrushEntityCount; i = v7 )
      {
        v8 = pBrushEntities[v7];
        if ( v8->m_pRenderable != nullptr )
        {
          v9 = v8->m_pRenderable->GetClientModelRenderable(this: v8->m_pRenderable);
          if ( v9 != nullptr )
          {
            data.m_pRenderable = v8->m_pRenderable;
            data.m_pModelRenderable = v9;
            data.m_InstanceData.m_nAlpha = v8->m_InstanceData.m_nAlpha;
            CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
              this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&arrBrushRenderables,
              elem: arrBrushRenderables.m_Size,
              src: (const QAngle *)&data);
          }
          else
          {
            v10 = nRemainingBrushes;
            pBrushEntities[nRemainingBrushes] = v8;
            nRemainingBrushes = v10 + 1;
          }
        }
        v7 = i + 1;
      }
      g_pModelRenderSystem->DrawBrushModels(
        this: g_pModelRenderSystem,
        a2: arrBrushRenderables.m_Memory.m_pMemory,
        a3: arrBrushRenderables.m_Size,
        a4: (ModelRenderMode_t)((_BYTE)bShadowDepth != 0));
      CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&arrBrushRenderables);
      v4 = nRemainingBrushes;
    }
    if ( pDeferClippedOpaqueRenderables_Out != nullptr )
    {
      i = 0;
      if ( v4 > 0 )
      {
        do
        {
          v11 = pBrushEntities[i];
          if ( v11->m_pRenderable != nullptr
            && v11->m_pRenderable->GetRenderClipPlane(this: v11->m_pRenderable) != nullptr )
          {
            m_pMemory = (int)pDeferClippedOpaqueRenderables_Out[1].m_pMemory;
            m_nAllocationCount = pDeferClippedOpaqueRenderables_Out->m_nAllocationCount;
            if ( m_pMemory + 1 > m_nAllocationCount )
              CUtlMemory<CChoreoActor *,int>::Grow(
                this: pDeferClippedOpaqueRenderables_Out,
                num: m_pMemory - m_nAllocationCount + 1);
            ++pDeferClippedOpaqueRenderables_Out[1].m_pMemory;
            v14 = (CClientRenderablesList::CEntry **)pDeferClippedOpaqueRenderables_Out->m_pMemory;
            v15 = (int)pDeferClippedOpaqueRenderables_Out[1].m_pMemory - m_pMemory - 1;
            pDeferClippedOpaqueRenderables_Out[1].m_nAllocationCount = (int)pDeferClippedOpaqueRenderables_Out->m_pMemory;
            if ( v15 > 0 )
              _V_memmove(dest: &v14[m_pMemory + 1], src: &v14[m_pMemory], count: 4 * v15);
            v16 = (CClientRenderablesList::CEntry **)&pDeferClippedOpaqueRenderables_Out->m_pMemory[m_pMemory];
            if ( v16 != nullptr )
              *v16 = v11;
          }
          else
          {
            v17 = *((_BYTE *)v11 + 7) >= 0;
            m_pRenderable = v11->m_pRenderable;
            v27 = v11->m_pRenderable;
            v19 = 1;
            if ( !v17 )
              v19 = 9;
            if ( (_BYTE)bShadowDepth != 0 )
            {
              v19 |= 0x40000000u;
            }
            else
            {
              m_pRenderable->GetColorModulation(this: m_pRenderable, a2: (float *)&data);
              render->SetColorModulation(this: render, a2: (const float *)&data);
              m_pRenderable = v27;
            }
            instance.m_nAlpha = -1;
            DrawRenderable(pEnt: m_pRenderable, a2: bShadowDepth, flags: v19, &instance, bShadowDepth);
          }
          ++i;
        }
        while ( i < nRemainingBrushes );
      }
    }
    else
    {
      v20 = 0;
      if ( v4 > 0 )
      {
        do
        {
          v21 = pBrushEntities[v20];
          v22 = v21->m_pRenderable;
          v23 = 1;
          if ( *((char *)v21 + 7) < 0 )
            v23 = 9;
          if ( (_BYTE)bShadowDepth != 0 )
          {
            v23 |= 0x40000000u;
          }
          else
          {
            v22->GetColorModulation(this: v22, a2: (float *)&data);
            render->SetColorModulation(this: render, a2: (const float *)&data);
          }
          instance.m_nAlpha = -1;
          DrawRenderable(pEnt: v22, a2: (int)v22, flags: v23, &instance, bShadowDepth);
          ++v20;
        }
        while ( v20 < nRemainingBrushes );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A3BC0
// Name: DrawOpaqueRenderables_Range
// Source: json
//------------------------------------------------------------------------------
void __usercall DrawOpaqueRenderables_Range(
        CUtlMemory<vgui::TreeNode *,int> *pDeferClippedOpaqueRenderables_Out@<eax>,
        int nCount,
        CClientRenderablesList::CEntry **ppEntities,
        int bShadowDepth)
{
  int v4; // ecx
  CClientRenderablesList::CEntry *v6; // ebx
  int m_pMemory; // esi
  int m_nAllocationCount; // eax
  CClientRenderablesList::CEntry **v9; // ecx
  int v10; // eax
  CClientRenderablesList::CEntry **v11; // esi
  bool v12; // zf
  IClientRenderable *m_pRenderable; // ecx
  int v14; // esi
  CClientRenderablesList::CEntry *v15; // eax
  IClientRenderable *v16; // esi
  int v17; // edi
  float v18[3]; // [esp+Ch] [ebp-18h] BYREF
  IClientRenderable *v19; // [esp+18h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-8h]
  RenderableInstance_t instance; // [esp+23h] [ebp-1h] BYREF

  v4 = 0;
  i = 0;
  if ( pDeferClippedOpaqueRenderables_Out != nullptr )
  {
    if ( nCount > 0 )
    {
      do
      {
        v6 = ppEntities[i];
        if ( v6->m_pRenderable != nullptr && v6->m_pRenderable->GetRenderClipPlane(this: v6->m_pRenderable) != nullptr )
        {
          m_pMemory = (int)pDeferClippedOpaqueRenderables_Out[1].m_pMemory;
          m_nAllocationCount = pDeferClippedOpaqueRenderables_Out->m_nAllocationCount;
          if ( m_pMemory + 1 > m_nAllocationCount )
            CUtlMemory<CChoreoActor *,int>::Grow(
              this: pDeferClippedOpaqueRenderables_Out,
              num: m_pMemory - m_nAllocationCount + 1);
          ++pDeferClippedOpaqueRenderables_Out[1].m_pMemory;
          v9 = (CClientRenderablesList::CEntry **)pDeferClippedOpaqueRenderables_Out->m_pMemory;
          v10 = (int)pDeferClippedOpaqueRenderables_Out[1].m_pMemory - m_pMemory - 1;
          pDeferClippedOpaqueRenderables_Out[1].m_nAllocationCount = (int)pDeferClippedOpaqueRenderables_Out->m_pMemory;
          if ( v10 > 0 )
            _V_memmove(dest: &v9[m_pMemory + 1], src: &v9[m_pMemory], count: 4 * v10);
          v11 = (CClientRenderablesList::CEntry **)&pDeferClippedOpaqueRenderables_Out->m_pMemory[m_pMemory];
          if ( v11 != nullptr )
            *v11 = v6;
        }
        else
        {
          v12 = *((_BYTE *)v6 + 7) >= 0;
          m_pRenderable = v6->m_pRenderable;
          v19 = v6->m_pRenderable;
          v14 = 1;
          if ( !v12 )
            v14 = 9;
          if ( (_BYTE)bShadowDepth != 0 )
          {
            v14 |= 0x40000000u;
          }
          else
          {
            m_pRenderable->GetColorModulation(this: m_pRenderable, a2: v18);
            render->SetColorModulation(this: render, a2: v18);
            m_pRenderable = v19;
          }
          instance.m_nAlpha = -1;
          DrawRenderable(pEnt: m_pRenderable, a2: bShadowDepth, flags: v14, &instance, bShadowDepth);
        }
        ++i;
      }
      while ( i < nCount );
    }
  }
  else if ( nCount > 0 )
  {
    do
    {
      v15 = ppEntities[v4];
      v16 = v15->m_pRenderable;
      if ( v15->m_pRenderable != nullptr )
      {
        v17 = 1;
        if ( *((char *)v15 + 7) < 0 )
          v17 = 9;
        if ( (_BYTE)bShadowDepth != 0 )
        {
          v17 |= 0x40000000u;
        }
        else
        {
          v16->GetColorModulation(this: v16, a2: v18);
          render->SetColorModulation(this: render, a2: v18);
        }
        instance.m_nAlpha = -1;
        DrawRenderable(pEnt: v16, a2: bShadowDepth, flags: v17, &instance, bShadowDepth);
        v4 = i;
      }
      i = ++v4;
    }
    while ( v4 < nCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A3D30
// Name: protected: void CRendering3dView::DrawOpaqueRenderables(class IMatRenderContext __near *,enum CRendering3dView::RenderablesRenderPath_t,class CUtlVector<struct CClientRenderablesList::CEntry __near *,class CUtlMemory<struct CClientRenderablesList::CEntry __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRendering3dView::DrawOpaqueRenderables(
        CRendering3dView *this,
        IMatRenderContext *pRenderContext,
        CRendering3dView::RenderablesRenderPath_t eRenderPath,
        CUtlVector<CClientRenderablesList::CEntry *,CUtlMemory<CClientRenderablesList::CEntry *,int> > *pDeferClippedOpaqueRenderables_Out)
{
  const ConVar *m_pDrawEntities; // eax
  ConVar *m_pParent; // eax
  CRopeManager *v7; // eax
  CClientRenderablesList *m_pRenderablesList; // ebx
  int v9; // edi
  void *v10; // esp
  void *v11; // esp
  void *v12; // esp
  CClientRenderablesList::CEntry *v13; // eax
  int v14; // ebx
  int v15; // esi
  int v16; // edx
  int m_nValue; // eax
  void *v18; // esp
  int v19; // esi
  int m_Size; // edi
  void *v21; // esp
  ModelRenderSystemData_t *v22; // ebx
  int v23; // esi
  int v24; // eax
  CClientRenderablesList::CEntry *v25; // ebx
  IClientRenderable *m_pRenderable; // ecx
  IClientModelRenderable *v27; // eax
  IClientRenderable *v28; // ecx
  unsigned __int8 m_nAlpha; // dl
  int v30; // eax
  CClientRenderablesList::CEntry *v31; // edi
  IClientModelRenderable *v32; // eax
  int v33; // eax
  int v34; // eax
  int v35; // eax
  int v36; // ebx
  CClientRenderablesList::CEntry **m_pMemory; // esi
  CClientRenderablesList::CEntry **v38; // esi
  int v39; // eax
  IClientRenderable *v40; // edx
  int v41; // edi
  ModelRenderSystemData_t *v42; // eax
  int v43; // esi
  CRopeManager *v44; // eax
  CClientRenderablesList::CEntry *v45[3]; // [esp+4h] [ebp-60h] BYREF
  CUtlVector<CClientRenderablesList::CEntry *,CUtlMemory<CClientRenderablesList::CEntry *,int> > arrRenderEntsNpcsFirst; // [esp+10h] [ebp-54h] BYREF
  CUtlVector<ModelRenderSystemData_t,CUtlMemory<ModelRenderSystemData_t,int> > arrModelRenderables; // [esp+24h] [ebp-40h] BYREF
  ModelRenderSystemData_t data; // [esp+38h] [ebp-2Ch] BYREF
  CClientRenderablesList::CEntry *itEntity; // [esp+44h] [ebp-20h]
  int i; // [esp+48h] [ebp-1Ch]
  int nRemainingOther; // [esp+4Ch] [ebp-18h]
  int bShadowDepth; // [esp+50h] [ebp-14h]
  int nOtherCount; // [esp+54h] [ebp-10h]
  CClientRenderablesList::CEntry **pStaticProps; // [esp+58h] [ebp-Ch]
  CClientRenderablesList::CEntry **pOtherRenderables; // [esp+5Ch] [ebp-8h]
  int nStaticCount; // [esp+60h] [ebp-4h]
  int bUseFastPath; // [esp+70h] [ebp+Ch]
  bool bUseFastPath_3; // [esp+73h] [ebp+Fh]

  LOBYTE(bShadowDepth) = eRenderPath > RENDERABLES_RENDER_PATH_NORMAL;
  if ( r_drawopaquerenderables.m_pParent != nullptr && r_drawopaquerenderables.m_pParent->m_Value.m_nValue != 0 )
  {
    m_pDrawEntities = this->m_pMainView->m_pDrawEntities;
    if ( m_pDrawEntities == nullptr
      || (m_pParent = m_pDrawEntities->m_pParent) != nullptr && m_pParent->m_Value.m_nValue != 0 )
    {
      ((void (__stdcall *)(int))render->SetBlend)(a1: 1065353216);
      v7 = RopeManager();
      v7->ResetRenderCache(this: v7);
      CParticleSystemMgr::ResetRenderCache(this: g_pParticleSystemMgr);
      m_pRenderablesList = this->m_pRenderablesList;
      v9 = m_pRenderablesList->m_RenderGroupCounts[0];
      v10 = alloca(4 * v9);
      v11 = alloca(4 * v9);
      pStaticProps = v45;
      v12 = alloca(4 * v9);
      v13 = m_pRenderablesList->m_RenderGroups[0];
      v14 = 0;
      v15 = 0;
      v16 = 0;
      pOtherRenderables = v45;
      nStaticCount = 0;
      nOtherCount = 0;
      if ( v9 > 0 )
      {
        do
        {
          if ( (*((_BYTE *)v13 + 7) & 0x3F) == 2 )
          {
            pStaticProps[v14++] = v13;
          }
          else if ( (*((_BYTE *)v13 + 7) & 0x3F) == 3 )
          {
            v45[v16++] = v13;
          }
          else
          {
            v45[v15++] = v13;
          }
          ++v13;
          --v9;
        }
        while ( v9 != 0 );
        nStaticCount = v14;
        nOtherCount = v15;
      }
      DrawOpaqueRenderables_DrawBrushModels(
        (CUtlMemory<vgui::TreeNode *,int> *)pDeferClippedOpaqueRenderables_Out,
        pBrushEntities: v45,
        nBrushEntityCount: v16,
        bShadowDepth);
      if ( cl_modelfastpath.m_pParent != nullptr )
        m_nValue = cl_modelfastpath.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      bUseFastPath_3 = m_nValue != 0;
      v18 = alloca(8 * v15);
      arrRenderEntsNpcsFirst.m_Memory.m_pMemory = v45;
      arrRenderEntsNpcsFirst.m_pElements = v45;
      arrRenderEntsNpcsFirst.m_Memory.m_nAllocationCount = v15;
      v19 = v14 + v15;
      m_Size = 0;
      arrRenderEntsNpcsFirst.m_Memory.m_nGrowSize = -1;
      arrRenderEntsNpcsFirst.m_Size = 0;
      v21 = alloca(12 * v19);
      v22 = (ModelRenderSystemData_t *)v45;
      arrModelRenderables.m_Memory.m_nAllocationCount = v19;
      v23 = 0;
      arrModelRenderables.m_pElements = (ModelRenderSystemData_t *)v45;
      arrModelRenderables.m_Memory.m_pMemory = (ModelRenderSystemData_t *)v45;
      arrModelRenderables.m_Memory.m_nGrowSize = -1;
      arrModelRenderables.m_Size = 0;
      nRemainingOther = 0;
      if ( r_drawothermodels.m_pParent != nullptr && r_drawothermodels.m_pParent->m_Value.m_nValue != 0 )
      {
        v24 = 0;
        i = 0;
        if ( nOtherCount > 0 )
        {
          while ( 1 )
          {
            v25 = pOtherRenderables[v24];
            m_pRenderable = v25->m_pRenderable;
            itEntity = v25;
            if ( m_pRenderable != nullptr )
            {
              v27 = m_pRenderable->GetClientModelRenderable(this: m_pRenderable);
              if ( bUseFastPath_3 && v27 != nullptr )
              {
                v28 = v25->m_pRenderable;
                m_nAlpha = v25->m_InstanceData.m_nAlpha;
                data.m_pModelRenderable = v27;
                data.m_pRenderable = v28;
                data.m_InstanceData.m_nAlpha = m_nAlpha;
                CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
                  this: (CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)&arrModelRenderables,
                  elem: v23,
                  src: (const QAngle *)&data);
              }
              else
              {
                v34 = (int)v25->m_pRenderable->GetIClientUnknown(this: v25->m_pRenderable);
                v35 = (*(int (__thiscall **)(int))(*(_DWORD *)v34 + 28))(a1: v34);
                if ( v35 == 0 || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v35 + 596))(a1: v35) == 0 )
                {
                  v39 = nRemainingOther;
                  pOtherRenderables[nRemainingOther] = v25;
                  nRemainingOther = v39 + 1;
                  goto LABEL_25;
                }
                v36 = m_Size;
                if ( m_Size + 1 > arrRenderEntsNpcsFirst.m_Memory.m_nAllocationCount )
                {
                  CUtlMemory<CChoreoActor *,int>::Grow(
                    this: (CUtlMemory<vgui::TreeNode *,int> *)&arrRenderEntsNpcsFirst,
                    num: m_Size - arrRenderEntsNpcsFirst.m_Memory.m_nAllocationCount + 1);
                  m_Size = arrRenderEntsNpcsFirst.m_Size;
                }
                m_pMemory = arrRenderEntsNpcsFirst.m_Memory.m_pMemory;
                arrRenderEntsNpcsFirst.m_Size = ++m_Size;
                arrRenderEntsNpcsFirst.m_pElements = arrRenderEntsNpcsFirst.m_Memory.m_pMemory;
                if ( m_Size - v36 - 1 > 0 )
                  _V_memmove(
                    dest: (unsigned __int8 *)&arrRenderEntsNpcsFirst.m_Memory.m_pMemory[v36 + 1],
                    src: (unsigned __int8 *)&arrRenderEntsNpcsFirst.m_Memory.m_pMemory[v36],
                    count: 4 * (m_Size - v36 - 1));
                v38 = &m_pMemory[v36];
                if ( v38 != nullptr )
                  *v38 = itEntity;
              }
              v23 = arrModelRenderables.m_Size;
            }
LABEL_25:
            v24 = i + 1;
            i = v24;
            if ( v24 >= nOtherCount )
            {
              v22 = arrModelRenderables.m_Memory.m_pMemory;
              break;
            }
          }
        }
      }
      v30 = 0;
      nOtherCount = 0;
      if ( bUseFastPath_3 )
      {
        bUseFastPath = 0;
        if ( nStaticCount > 0 )
        {
          do
          {
            v31 = pStaticProps[v30];
            if ( v31->m_pRenderable != nullptr )
            {
              v32 = v31->m_pRenderable->GetClientModelRenderable(this: v31->m_pRenderable);
              if ( v32 != nullptr )
              {
                v40 = v31->m_pRenderable;
                data.m_pModelRenderable = v32;
                data.m_InstanceData.m_nAlpha = v31->m_InstanceData.m_nAlpha;
                data.m_pRenderable = v40;
                v41 = v23;
                if ( v23 + 1 > arrModelRenderables.m_Memory.m_nAllocationCount )
                {
                  CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
                    this: (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)&arrModelRenderables,
                    num: v23 - arrModelRenderables.m_Memory.m_nAllocationCount + 1);
                  v23 = arrModelRenderables.m_Size;
                  v22 = arrModelRenderables.m_Memory.m_pMemory;
                }
                arrModelRenderables.m_Size = ++v23;
                arrModelRenderables.m_pElements = v22;
                if ( v23 - v41 - 1 > 0 )
                  _V_memmove(
                    dest: (unsigned __int8 *)&v22[v41 + 1],
                    src: (unsigned __int8 *)&v22[v41],
                    count: 12 * (v23 - v41 - 1));
                v42 = &v22[v41];
                if ( v42 != nullptr )
                  *v42 = data;
              }
              else
              {
                v33 = nOtherCount;
                pStaticProps[nOtherCount] = v31;
                nOtherCount = v33 + 1;
              }
            }
            v30 = bUseFastPath + 1;
            bUseFastPath = v30;
          }
          while ( v30 < nStaticCount );
          m_Size = arrRenderEntsNpcsFirst.m_Size;
        }
      }
      else
      {
        nOtherCount = nStaticCount;
      }
      g_pModelRenderSystem->DrawModels(this: g_pModelRenderSystem, a2: v22, a3: v23, a4: (_BYTE)bShadowDepth != 0);
      v43 = bShadowDepth;
      DrawOpaqueRenderables_Range(
        (CUtlMemory<vgui::TreeNode *,int> *)pDeferClippedOpaqueRenderables_Out,
        nCount: nRemainingOther,
        ppEntities: pOtherRenderables,
        bShadowDepth);
      DrawOpaqueRenderables_DrawStaticProps(nCount: nOtherCount, ppEntities: pStaticProps, bShadowDepth: v43);
      DrawOpaqueRenderables_Range(
        (CUtlMemory<vgui::TreeNode *,int> *)pDeferClippedOpaqueRenderables_Out,
        nCount: m_Size,
        ppEntities: arrRenderEntsNpcsFirst.m_Memory.m_pMemory,
        bShadowDepth: v43);
      v44 = RopeManager();
      v44->DrawRenderCache(this: v44, a2: pRenderContext, a3: v43);
      CParticleSystemMgr::DrawRenderCache(this: g_pParticleSystemMgr, pRenderContext, bShadowDepth);
      if ( arrModelRenderables.m_Memory.m_nGrowSize >= 0 && v22 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v22);
      if ( arrRenderEntsNpcsFirst.m_Memory.m_nGrowSize >= 0 && arrRenderEntsNpcsFirst.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: arrRenderEntsNpcsFirst.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A4140
// Name: public: CViewModelRenderablesList::~CViewModelRenderablesList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewModelRenderablesList::~CViewModelRenderablesList(CViewModelRenderablesList *this)
{
  CViewModelRenderablesList *v1; // esi
  int i; // ebx
  CViewModelRenderablesList::CEntry *m_pMemory; // eax

  v1 = this + 1;
  for ( i = 1; i >= 0; --i )
  {
    v1 = (CViewModelRenderablesList *)((char *)v1 - 280);
    v1->m_RenderGroups[0].m_Size = 0;
    if ( v1->m_RenderGroups[0].m_Memory.m_nGrowSize >= 0 )
    {
      if ( v1->m_RenderGroups[0].m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1->m_RenderGroups[0].m_Memory.m_pMemory);
        v1->m_RenderGroups[0].m_Memory.m_pMemory = nullptr;
      }
      v1->m_RenderGroups[0].m_Memory.m_nAllocationCount = 0;
    }
    m_pMemory = v1->m_RenderGroups[0].m_Memory.m_pMemory;
    v1->m_RenderGroups[0].m_pElements = v1->m_RenderGroups[0].m_Memory.m_pMemory;
    if ( v1->m_RenderGroups[0].m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
        v1->m_RenderGroups[0].m_Memory.m_pMemory = nullptr;
      }
      v1->m_RenderGroups[0].m_Memory.m_nAllocationCount = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A41B0
// Name: protected: void CRendering3dView::DrawTranslucentWorldInLeaves(class IMatRenderContext __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRendering3dView::DrawTranslucentWorldInLeaves(
        CRendering3dView *this,
        IMatRenderContext *pRenderContext,
        int bShadowDepth)
{
  ClientWorldListInfo_t *m_pWorldListInfo; // edi
  int *m_pFixedMemory; // eax
  int m_Size; // edx
  int v7; // esi
  unsigned __int16 *m_pOriginalLeafIndex; // eax
  CUtlVectorFixedGrowable<int,32> transSortIndexList; // [esp+4h] [ebp-98h] BYREF

  if ( (_BYTE)bShadowDepth == 0 )
  {
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "CViewRender::DrawTranslucentWorldInLeaves",
      a3: 0,
      a4: "World Rendering",
      a5: false,
      a6: 4);
    m_pWorldListInfo = this->m_pWorldListInfo;
    m_pFixedMemory = transSortIndexList.m_Memory.m_pFixedMemory;
    m_Size = 0;
    transSortIndexList.m_Memory.m_pMemory = transSortIndexList.m_Memory.m_pFixedMemory;
    transSortIndexList.m_Memory.m_nAllocationCount = 32;
    transSortIndexList.m_Memory.m_nGrowSize = -1;
    transSortIndexList.m_Memory.m_nMallocGrowSize = 0;
    transSortIndexList.m_Size = 0;
    transSortIndexList.m_pElements = transSortIndexList.m_Memory.m_pFixedMemory;
    v7 = m_pWorldListInfo->m_LeafCount - 1;
    if ( v7 >= 0 )
    {
      do
      {
        if ( m_pWorldListInfo->m_pLeafDataList[v7].translucentSurfaceCount != 0 )
        {
          m_pOriginalLeafIndex = m_pWorldListInfo->m_pOriginalLeafIndex;
          if ( m_pOriginalLeafIndex != nullptr )
            bShadowDepth = m_pOriginalLeafIndex[v7];
          else
            bShadowDepth = v7;
          CUtlVector<int,CUtlMemoryFixedGrowable<int,32,int>>::InsertBefore(
            this: &transSortIndexList,
            elem: m_Size,
            src: &bShadowDepth);
          m_Size = transSortIndexList.m_Size;
        }
        --v7;
      }
      while ( v7 >= 0 );
      if ( m_Size != 0 )
        render->DrawTranslucentSurfaces(
          this: render,
          a2: pRenderContext,
          a3: this->m_pWorldRenderList,
          a4: transSortIndexList.m_Memory.m_pMemory,
          a5: m_Size,
          a6: this->m_DrawFlags);
      m_pFixedMemory = transSortIndexList.m_Memory.m_pMemory;
    }
    transSortIndexList.m_Size = 0;
    if ( transSortIndexList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pFixedMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pFixedMemory);
        m_pFixedMemory = nullptr;
        transSortIndexList.m_Memory.m_pMemory = nullptr;
      }
      transSortIndexList.m_Memory.m_nAllocationCount = 0;
    }
    transSortIndexList.m_pElements = m_pFixedMemory;
    if ( transSortIndexList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( m_pFixedMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pFixedMemory);
        transSortIndexList.m_Memory.m_pMemory = nullptr;
      }
      transSortIndexList.m_Memory.m_nAllocationCount = 0;
    }
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A4310
// Name: protected: void CRendering3dView::DrawTranslucentWorldAndDetailPropsInLeaves(class IMatRenderContext __near *,int,int,int,int __near &,unsigned short __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRendering3dView::DrawTranslucentWorldAndDetailPropsInLeaves(
        CRendering3dView *this,
        IMatRenderContext *pRenderContext,
        int iCurLeafIndex,
        int iFinalLeafIndex,
        unsigned int nEngineDrawFlags,
        int *nDetailLeafCount,
        unsigned __int16 *pDetailLeafList,
        bool bShadowDepth)
{
  int v9; // ecx
  ClientWorldListInfo_t *m_pWorldListInfo; // eax
  unsigned __int16 *m_pOriginalLeafIndex; // eax
  IClientLeafSystem *v12; // edi
  IClientLeafSystem_vtbl *v13; // esi
  int v14; // eax
  int *m_pMemory; // eax
  CUtlVectorFixedGrowable<int,32> transSortIndexList; // [esp+4h] [ebp-9Ch] BYREF
  int nActualLeafIndex; // [esp+9Ch] [ebp-4h] BYREF
  const ClientWorldListInfo_t *info; // [esp+C0h] [ebp+20h]

  if ( !bShadowDepth )
  {
    transSortIndexList.m_Memory.m_pMemory = transSortIndexList.m_Memory.m_pFixedMemory;
    transSortIndexList.m_pElements = transSortIndexList.m_Memory.m_pFixedMemory;
    transSortIndexList.m_Memory.m_nAllocationCount = 32;
    transSortIndexList.m_Memory.m_nGrowSize = -1;
    transSortIndexList.m_Memory.m_nMallocGrowSize = 0;
    transSortIndexList.m_Size = 0;
    CVProfile::EnterScope(
      this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
      a2: "CViewRender::DrawTranslucentWorldAndDetailPropsInLeaves",
      a3: 0,
      a4: "World Rendering",
      a5: false,
      a6: 4);
    v9 = iCurLeafIndex;
    m_pWorldListInfo = this->m_pWorldListInfo;
    info = m_pWorldListInfo;
    if ( iCurLeafIndex >= iFinalLeafIndex )
    {
      while ( 1 )
      {
        if ( m_pWorldListInfo->m_pLeafDataList[v9].translucentSurfaceCount != 0 )
        {
          m_pOriginalLeafIndex = m_pWorldListInfo->m_pOriginalLeafIndex;
          if ( m_pOriginalLeafIndex != nullptr )
            nActualLeafIndex = m_pOriginalLeafIndex[v9];
          else
            nActualLeafIndex = v9;
          if ( *nDetailLeafCount != 0 )
          {
            g_pDetailObjectSystem->RenderTranslucentDetailObjects(
              this: g_pDetailObjectSystem,
              a2: &this->m_pRenderablesList->m_DetailFade,
              a3: &g_vecCurrentRenderOrigin,
              a4: &g_vecCurrentVForward,
              a5: &g_vecCurrentVRight,
              a6: &g_vecCurrentVUp,
              a7: *nDetailLeafCount,
              a8: pDetailLeafList);
            *nDetailLeafCount = 0;
          }
          CUtlVector<int,CUtlMemoryFixedGrowable<int,32,int>>::InsertBefore(
            this: &transSortIndexList,
            elem: transSortIndexList.m_Size,
            src: &nActualLeafIndex);
        }
        v12 = g_pClientLeafSystem;
        v13 = g_pClientLeafSystem->IClientLeafSystemEngine::__vftable;
        v14 = this->m_pMainView->BuildWorldListsNumber(this: this->m_pMainView);
        if ( v13->ShouldDrawDetailObjectsInLeaf(this: v12, a2: info->m_pLeafDataList[iCurLeafIndex].leafIndex, a3: v14) )
        {
          if ( transSortIndexList.m_Size != 0 )
            render->DrawTranslucentSurfaces(
              this: render,
              a2: pRenderContext,
              a3: this->m_pWorldRenderList,
              a4: transSortIndexList.m_Memory.m_pMemory,
              a5: transSortIndexList.m_Size,
              a6: nEngineDrawFlags);
          pDetailLeafList[(*nDetailLeafCount)++] = info->m_pLeafDataList[iCurLeafIndex].leafIndex;
        }
        if ( --iCurLeafIndex < iFinalLeafIndex )
          break;
        m_pWorldListInfo = (ClientWorldListInfo_t *)info;
        v9 = iCurLeafIndex;
      }
    }
    if ( transSortIndexList.m_Size != 0 )
      render->DrawTranslucentSurfaces(
        this: render,
        a2: pRenderContext,
        a3: this->m_pWorldRenderList,
        a4: transSortIndexList.m_Memory.m_pMemory,
        a5: transSortIndexList.m_Size,
        a6: nEngineDrawFlags);
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    m_pMemory = transSortIndexList.m_Memory.m_pMemory;
    transSortIndexList.m_Size = 0;
    if ( transSortIndexList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( transSortIndexList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: transSortIndexList.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        transSortIndexList.m_Memory.m_pMemory = nullptr;
      }
      transSortIndexList.m_Memory.m_nAllocationCount = 0;
    }
    transSortIndexList.m_pElements = m_pMemory;
    if ( transSortIndexList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A4520
// Name: protected: void CRendering3dView::DrawTranslucentRenderables(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CRendering3dView::DrawTranslucentRenderables(
        CRendering3dView *this@<ecx>,
        int m_DrawFlags@<ebx>,
        int a3@<edi>,
        bool bInSkybox,
        bool bShadowDepth)
{
  CRendering3dView *v5; // esi
  IMatRenderContext *v6; // eax
  IMatRenderContext *v7; // eax
  float v8; // edi
  const ClientWorldListInfo_t *m_pWorldListInfo; // eax
  int m_LeafCount; // eax
  void *v11; // esp
  unsigned __int16 *v12; // edi
  unsigned int v13; // eax
  IDetailObjectSystem_vtbl *v14; // edx
  const ConVar *m_pDrawEntities; // eax
  ConVar *m_pParent; // eax
  void (*BeginLock)(void); // eax
  int m_pRenderablesList; // ebx
  int v19; // esi
  int v20; // edi
  void *v21; // esp
  void *v22; // esp
  void *v23; // esp
  void *v24; // esp
  int m_nValue; // eax
  int v26; // eax
  bool v27; // zf
  IMaterial *(__thiscall *GetFastPathColorMaterial)(IModelRenderSystem *); // eax
  int (*v29)(void); // eax
  int v30; // edx
  int v31; // eax
  int v32; // eax
  ModelRenderSystemData_t *v33; // ecx
  int v34; // esi
  WorldListLeafData_t *m_pLeafDataList; // eax
  int leafIndex; // ecx
  IClientLeafSystem_vtbl *v37; // esi
  CViewRender *m_pMainView; // ecx
  int v39; // eax
  IClientRenderable *v40; // esi
  const Vector *v41; // eax
  CMatRenderContextPtr v42; // eax
  int v43; // edx
  int v44; // eax
  int v45; // ecx
  IClientRenderable *v46; // esi
  CMatRenderContextPtr v47; // eax
  int v48; // eax
  int v49; // edx
  int v50; // eax
  int v51; // ecx
  IMatRenderContext *m_pObject; // ebx
  _BYTE v53[12]; // [esp+78h] [ebp-88h] BYREF
  CUtlVector<ModelRenderSystemData_t,CUtlMemory<ModelRenderSystemData_t,int> > fastPathData; // [esp+84h] [ebp-7Ch] BYREF
  float v55[3]; // [esp+98h] [ebp-68h] BYREF
  float v56[3]; // [esp+A4h] [ebp-5Ch] BYREF
  TranslucentTempData_t tempData; // [esp+B0h] [ebp-50h] BYREF
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+BCh] [ebp-44h]
  const ClientWorldListInfo_t *info; // [esp+C0h] [ebp-40h]
  IClientModelRenderable *pModelRenderable; // [esp+C4h] [ebp-3Ch]
  int (__thiscall **p_GetModelType)(struct IVModelInfoClient *, const struct model_t *); // [esp+C8h] [ebp-38h]
  CMatRenderContextPtr pRenderContext; // [esp+CCh] [ebp-34h]
  unsigned int nEngineDrawFlags; // [esp+D0h] [ebp-30h]
  IMaterial *pFastPathColorMaterial; // [esp+D4h] [ebp-2Ch]
  int iPrevLeaf; // [esp+D8h] [ebp-28h]
  int nLeaf; // [esp+DCh] [ebp-24h]
  unsigned __int16 *pDetailLeafList; // [esp+E0h] [ebp-20h]
  TranslucentInstanceRenderData_t *pRenderData; // [esp+E4h] [ebp-1Ch]
  int *pFastPathIndex; // [esp+E8h] [ebp-18h]
  int nDetailLeafCount; // [esp+ECh] [ebp-14h] BYREF
  int iThisLeaf; // [esp+F0h] [ebp-10h]
  CRendering3dView *v72; // [esp+F4h] [ebp-Ch]
  char v73; // [esp+F8h] [ebp-8h]
  bool bColorizeFastPath; // [esp+FEh] [ebp-2h]
  bool bRenderingWaterRenderTargets; // [esp+FFh] [ebp-1h]
  bool bInSkybox_3; // [esp+10Bh] [ebp+Bh]

  v5 = this;
  v72 = this;
  if ( g_CurrentViewID != VIEW_MAIN )
  {
    v6 = materials->GetRenderContext(this: materials);
    v6->SetFullScreenDepthTextureValidityFlag(this: v6, a2: false);
  }
  else
  {
    UpdateFullScreenDepthTexture(a1: a3, a2: (int)this);
  }
  v7 = materials->GetRenderContext(this: materials);
  v8 = *(float *)&v7;
  pRenderContext.m_pObject = v7;
  if ( v7 != nullptr )
    v7->BeginRender(this: v7);
  m_pWorldListInfo = v5->m_pWorldListInfo;
  info = m_pWorldListInfo;
  if ( r_drawtranslucentworld.m_pParent != nullptr && r_drawtranslucentworld.m_pParent->m_Value.m_nValue != 0 )
  {
    m_DrawFlags = v5->m_DrawFlags;
    if ( (m_DrawFlags & 0x480000) == 0 )
    {
      m_LeafCount = m_pWorldListInfo->m_LeafCount;
      iPrevLeaf = m_LeafCount - 1;
      nDetailLeafCount = 0;
      v11 = alloca(2 * m_LeafCount);
      v12 = (unsigned __int16 *)v53;
      pDetailLeafList = (unsigned __int16 *)v53;
      v13 = BuildEngineDrawWorldListFlags(nDrawFlags: m_DrawFlags & 0xFFFFF7FF);
      v14 = g_pDetailObjectSystem->__vftable;
      nEngineDrawFlags = v13;
      v14->BeginTranslucentDetailRendering(this: g_pDetailObjectSystem);
      m_pDrawEntities = v5->m_pMainView->m_pDrawEntities;
      if ( m_pDrawEntities != nullptr
        && ((m_pParent = m_pDrawEntities->m_pParent) == nullptr || m_pParent->m_Value.m_nValue == 0)
        || r_drawtranslucentrenderables.m_pParent == nullptr
        || r_drawtranslucentrenderables.m_pParent->m_Value.m_nValue == 0 )
      {
LABEL_69:
        m_pObject = pRenderContext.m_pObject;
        CRendering3dView::DrawTranslucentWorldAndDetailPropsInLeaves(
          this: v5,
          pRenderContext: pRenderContext.m_pObject,
          iCurLeafIndex: iPrevLeaf,
          iFinalLeafIndex: 0,
          nEngineDrawFlags,
          &nDetailLeafCount,
          pDetailLeafList: v12,
          bShadowDepth);
        g_pDetailObjectSystem->RenderTranslucentDetailObjects(
          this: g_pDetailObjectSystem,
          a2: &v5->m_pRenderablesList->m_DetailFade,
          a3: &g_vecCurrentRenderOrigin,
          a4: &g_vecCurrentVForward,
          a5: &g_vecCurrentVRight,
          a6: &g_vecCurrentVUp,
          a7: nDetailLeafCount,
          a8: v12);
        ((void (__stdcall *)(int))render->SetBlend)(a1: 1065353216);
        if ( m_pObject != nullptr )
        {
          m_pObject->EndRender(this: m_pObject);
          m_pObject->Release(this: m_pObject);
        }
        return;
      }
      CVProfile::EnterScope(
        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
        a2: "DrawTranslucentEntities",
        a3: 0,
        a4: "DrawTranslucentEntities",
        a5: false,
        a6: 4);
      BeginLock = (void (*)(void))mdlcache->BeginLock;
      cacheCriticalSection.m_pCache = mdlcache;
      BeginLock();
      DrawParticleSingletons(bInSkybox);
      m_pRenderablesList = (int)v5->m_pRenderablesList;
      v19 = *(_DWORD *)(m_pRenderablesList + 98328);
      v20 = v19 - 1;
      v21 = alloca(4 * v19);
      pFastPathIndex = (int *)v53;
      v22 = alloca(12 * v19);
      fastPathData.m_Memory.m_pMemory = (ModelRenderSystemData_t *)v53;
      fastPathData.m_pElements = (ModelRenderSystemData_t *)v53;
      fastPathData.m_Memory.m_nAllocationCount = v19;
      fastPathData.m_Memory.m_nGrowSize = -1;
      fastPathData.m_Size = 0;
      v23 = alloca(8 * v19);
      pRenderData = (TranslucentInstanceRenderData_t *)v53;
      v24 = alloca(4 * v19);
      tempData.m_pColorMeshHandles = (memhandle_t__ **)v53;
      if ( cl_tlucfastpath.m_pParent != nullptr )
        m_nValue = cl_tlucfastpath.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      bInSkybox_3 = m_nValue != 0;
      if ( cl_colorfastpath.m_pParent != nullptr )
        v26 = cl_colorfastpath.m_pParent->m_Value.m_nValue;
      else
        v26 = 0;
      v27 = v26 == 0;
      GetFastPathColorMaterial = g_pModelRenderSystem->GetFastPathColorMaterial;
      bColorizeFastPath = !v27;
      pFastPathColorMaterial = GetFastPathColorMaterial(this: g_pModelRenderSystem);
      if ( bInSkybox_3 )
      {
        for ( iThisLeaf = 0; iThisLeaf < v19; ++iThisLeaf )
        {
          v29 = *(int (**)(void))(**(_DWORD **)(m_pRenderablesList + 8 * iThisLeaf + 32788) + 176);
          nLeaf = *(_DWORD *)(m_pRenderablesList + 8 * iThisLeaf + 32788);
          pModelRenderable = (IClientModelRenderable *)v29();
          if ( pModelRenderable != nullptr
            && (v30 = *(_DWORD *)nLeaf,
                p_GetModelType = &modelinfo->GetModelType,
                v31 = (*(int (__thiscall **)(int))(v30 + 32))(a1: nLeaf),
                (*p_GetModelType)(this: modelinfo, a2: (const struct model_t *)v31) == 3) )
          {
            v32 = CUtlVector<OcclusionHandleViewIDPair_t,CUtlMemory<OcclusionHandleViewIDPair_t,int>>::AddToTail(this: (CUtlVector<OcclusionHandleViewIDPair_t,CUtlMemory<OcclusionHandleViewIDPair_t,int> > *)&fastPathData);
            v33 = &fastPathData.m_Memory.m_pMemory[v32];
            v33->m_pRenderable = (IClientRenderable *)nLeaf;
            v33->m_pModelRenderable = pModelRenderable;
            v33->m_InstanceData.m_nAlpha = *(_BYTE *)(m_pRenderablesList + 8 * iThisLeaf + 32794);
            pFastPathIndex[iThisLeaf] = v32;
          }
          else
          {
            pFastPathIndex[iThisLeaf] = -1;
          }
        }
        g_pModelRenderSystem->ComputeTranslucentRenderData(
          this: g_pModelRenderSystem,
          a2: fastPathData.m_Memory.m_pMemory,
          a3: fastPathData.m_Size,
          a4: pRenderData,
          a5: &tempData);
      }
      bRenderingWaterRenderTargets = (v72->m_DrawFlags & 3) != 0;
      if ( v20 < 0 )
      {
LABEL_66:
        if ( bInSkybox_3 )
          g_pModelRenderSystem->CleanupTranslucentTempData(this: g_pModelRenderSystem, a2: &tempData);
        CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&fastPathData);
        cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
        CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
        v12 = pDetailLeafList;
        v5 = v72;
        goto LABEL_69;
      }
      while ( 1 )
      {
        v34 = *(unsigned __int16 *)(m_pRenderablesList + 8 * v20 + 32792);
        iThisLeaf = v34;
        CRendering3dView::DrawTranslucentWorldAndDetailPropsInLeaves(
          this: v72,
          pRenderContext: pRenderContext.m_pObject,
          iCurLeafIndex: iPrevLeaf,
          iFinalLeafIndex: v34,
          nEngineDrawFlags,
          &nDetailLeafCount,
          pDetailLeafList,
          bShadowDepth);
        m_pLeafDataList = info->m_pLeafDataList;
        iPrevLeaf = v34 - 1;
        leafIndex = m_pLeafDataList[v34].leafIndex;
        v37 = g_pClientLeafSystem->IClientLeafSystemEngine::__vftable;
        nLeaf = leafIndex;
        m_pMainView = v72->m_pMainView;
        pModelRenderable = (IClientModelRenderable *)g_pClientLeafSystem;
        v39 = m_pMainView->BuildWorldListsNumber(this: m_pMainView);
        if ( v37->ShouldDrawDetailObjectsInLeaf(this: (IClientLeafSystem *)pModelRenderable, a2: nLeaf, a3: v39) )
        {
          g_pDetailObjectSystem->RenderTranslucentDetailObjects(
            this: g_pDetailObjectSystem,
            a2: &v72->m_pRenderablesList->m_DetailFade,
            a3: &g_vecCurrentRenderOrigin,
            a4: &g_vecCurrentVForward,
            a5: &g_vecCurrentVRight,
            a6: &g_vecCurrentVUp,
            a7: nDetailLeafCount - 1,
            a8: pDetailLeafList);
          if ( *(unsigned __int16 *)(m_pRenderablesList + 8 * v20 + 32792) == iThisLeaf )
          {
            while ( 1 )
            {
              if ( v20 < 0 )
                goto LABEL_47;
              v40 = *(IClientRenderable **)(m_pRenderablesList + 8 * v20 + 32788);
              v41 = v40->GetRenderOrigin(this: v40);
              g_pDetailObjectSystem->RenderTranslucentDetailObjectsInLeaf(
                this: g_pDetailObjectSystem,
                a2: &v72->m_pRenderablesList->m_DetailFade,
                a3: &g_vecCurrentRenderOrigin,
                a4: &g_vecCurrentVForward,
                a5: &g_vecCurrentVRight,
                a6: &g_vecCurrentVUp,
                a7: nLeaf,
                a8: v41);
              v42.m_pObject = (IMatRenderContext *)v40->GetRenderFlags(this: v40);
              if ( ((int)v42.m_pObject & 3) == 0 || bShadowDepth )
                goto LABEL_36;
              if ( !bRenderingWaterRenderTargets )
                break;
LABEL_46:
              v45 = *(unsigned __int16 *)(m_pRenderablesList + 8 * v20-- + 32784);
              if ( v45 != iThisLeaf )
                goto LABEL_47;
            }
            UpdateNecessaryRenderTargets(a1: v20, a2: (int)v40, nRenderFlags: v42);
LABEL_36:
            if ( bInSkybox_3 && pFastPathIndex[v20] >= 0 )
            {
              if ( bColorizeFastPath )
                g_pStudioRender->ForcedMaterialOverride(
                  this: g_pStudioRender,
                  a2: pFastPathColorMaterial,
                  a3: OVERRIDE_NORMAL);
              g_pStudioRender->DrawModelArray_2(
                this: g_pStudioRender,
                a2: pRenderData[pFastPathIndex[v20]].m_pModelInfo,
                a3: 1,
                a4: pRenderData[pFastPathIndex[v20]].m_pInstanceData,
                a5: 68,
                a6: (*(unsigned __int8 *)(m_pRenderablesList + 8 * v20 + 32795) >> 6) & 2);
              g_pStudioRender->ForcedMaterialOverride(this: g_pStudioRender, a2: nullptr, a3: OVERRIDE_NORMAL);
            }
            else
            {
              v43 = *(unsigned __int8 *)(m_pRenderablesList + 8 * v20 + 32794);
              v73 = *(_BYTE *)(m_pRenderablesList + 8 * v20 + 32795) >> 7;
              ((void (__stdcall *)(_DWORD))render->SetBlend)(a1: (float)v43 * 0.0039215689);
              v40->GetColorModulation(this: v40, a2: v56);
              render->SetColorModulation(this: render, a2: v56);
              v44 = -2147483647;
              if ( v73 != 0 )
                v44 = -2147483639;
              if ( bShadowDepth )
                v44 |= 0x40000000u;
              DrawRenderable(
                pEnt: v40,
                a2: m_pRenderablesList,
                flags: v44,
                instance: (const RenderableInstance_t *)(m_pRenderablesList + 8 * v20 + 32794),
                bShadowDepth);
            }
            goto LABEL_46;
          }
LABEL_47:
          g_pDetailObjectSystem->RenderTranslucentDetailObjectsInLeaf(
            this: g_pDetailObjectSystem,
            a2: &v72->m_pRenderablesList->m_DetailFade,
            a3: &g_vecCurrentRenderOrigin,
            a4: &g_vecCurrentVForward,
            a5: &g_vecCurrentVRight,
            a6: &g_vecCurrentVUp,
            a7: nLeaf,
            a8: nullptr);
          goto LABEL_65;
        }
        g_pDetailObjectSystem->RenderTranslucentDetailObjects(
          this: g_pDetailObjectSystem,
          a2: &v72->m_pRenderablesList->m_DetailFade,
          a3: &g_vecCurrentRenderOrigin,
          a4: &g_vecCurrentVForward,
          a5: &g_vecCurrentVRight,
          a6: &g_vecCurrentVUp,
          a7: nDetailLeafCount,
          a8: pDetailLeafList);
        if ( *(unsigned __int16 *)(m_pRenderablesList + 8 * v20 + 32792) == iThisLeaf )
          break;
LABEL_65:
        nDetailLeafCount = 0;
        if ( v20 < 0 )
          goto LABEL_66;
      }
      while ( 1 )
      {
        if ( v20 < 0 )
          goto LABEL_65;
        v46 = *(IClientRenderable **)(m_pRenderablesList + 8 * v20 + 32788);
        v47.m_pObject = (IMatRenderContext *)v46->GetRenderFlags(this: v46);
        if ( ((int)v47.m_pObject & 3) == 0 || bShadowDepth )
          goto LABEL_54;
        if ( !bRenderingWaterRenderTargets )
          break;
LABEL_64:
        v51 = *(unsigned __int16 *)(m_pRenderablesList + 8 * v20-- + 32784);
        if ( v51 != iThisLeaf )
          goto LABEL_65;
      }
      UpdateNecessaryRenderTargets(a1: v20, a2: (int)v46, nRenderFlags: v47);
LABEL_54:
      if ( bInSkybox_3 && (v48 = pFastPathIndex[v20], pModelRenderable = (IClientModelRenderable *)v48, v48 >= 0) )
      {
        if ( bColorizeFastPath )
        {
          g_pStudioRender->ForcedMaterialOverride(
            this: g_pStudioRender,
            a2: pFastPathColorMaterial,
            a3: OVERRIDE_NORMAL);
          v48 = (int)pModelRenderable;
        }
        g_pStudioRender->DrawModelArray_2(
          this: g_pStudioRender,
          a2: pRenderData[v48].m_pModelInfo,
          a3: 1,
          a4: pRenderData[v48].m_pInstanceData,
          a5: 68,
          a6: (*(unsigned __int8 *)(m_pRenderablesList + 8 * v20 + 32795) >> 6) & 2);
        g_pStudioRender->ForcedMaterialOverride(this: g_pStudioRender, a2: nullptr, a3: OVERRIDE_NORMAL);
      }
      else
      {
        v49 = *(unsigned __int8 *)(m_pRenderablesList + 8 * v20 + 32794);
        v73 = *(_BYTE *)(m_pRenderablesList + 8 * v20 + 32795) >> 7;
        ((void (__stdcall *)(_DWORD))render->SetBlend)(a1: (float)v49 * 0.0039215689);
        v46->GetColorModulation(this: v46, a2: v55);
        render->SetColorModulation(this: render, a2: v55);
        v50 = -2147483647;
        if ( v73 != 0 )
          v50 = -2147483639;
        if ( bShadowDepth )
          v50 |= 0x40000000u;
        DrawRenderable(
          pEnt: v46,
          a2: m_pRenderablesList,
          flags: v50,
          instance: (const RenderableInstance_t *)(m_pRenderablesList + 8 * v20 + 32794),
          bShadowDepth);
      }
      goto LABEL_64;
    }
  }
  CRendering3dView::DrawTranslucentRenderablesNoWorld(this: v5, a2: (_BYTE *)m_DrawFlags, a3: v8, bInSkybox);
  if ( v8 != 0.0 )
  {
    (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(v8) + 12))(a1: COERCE_FLOAT(LODWORD(v8)));
    (*(void (__thiscall **)(float))(*(_DWORD *)LODWORD(v8) + 4))(a1: COERCE_FLOAT(LODWORD(v8)));
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A4D00
// Name: protected: void CBaseWorldView::DrawExecute(float,enum view_id_t,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseWorldView::DrawExecute(
        CBaseWorldView *this,
        float waterHeight,
        CUtlVector<CClientRenderablesList::CEntry *,CUtlMemory<CClientRenderablesList::CEntry *,int> > *viewID,
        float waterZAdjust)
{
  view_id_t v5; // eax
  CViewRender *m_pMainView; // edx
  int m_BaseDrawFlags; // ecx
  CBaseWorldView_vtbl *v8; // edx
  int v9; // ecx
  void (__thiscall *PushView)(CBaseWorldView *, float); // eax
  IMatRenderContext *v11; // eax
  IMatRenderContext *v12; // edi
  int v13; // eax
  IMatRenderContext_vtbl *v14; // ebx
  ITexture *PowerOfTwoFrameBufferTexture; // eax
  int v16; // ebx
  void *v17; // esp
  int m_DrawFlags; // ebx
  IMatRenderContext *v19; // ebx
  _BYTE v20[12]; // [esp+20h] [ebp-28h] BYREF
  CUtlVector<CClientRenderablesList::CEntry *,CUtlMemory<CClientRenderablesList::CEntry *,int> > arrFastClippedOpaqueRenderables; // [esp+2Ch] [ebp-1Ch] BYREF
  int savedViewID; // [esp+40h] [ebp-8h]
  int iDrawFlagsBackup; // [esp+44h] [ebp-4h]
  ITexture *pSaveFrameBufferCopyTexture; // [esp+50h] [ebp+8h]
  CUtlVector<CClientRenderablesList::CEntry *,CUtlMemory<CClientRenderablesList::CEntry *,int> > *pArrFastClippedOpaqueRenderables; // [esp+54h] [ebp+Ch]

  if ( (this->m_DrawFlags & 0x480000) == 0 )
    g_pClientShadowMgr->ComputeShadowTextures(
      this: g_pClientShadowMgr,
      a2: &this->CViewSetup,
      a3: this->m_pWorldListInfo->m_LeafCount,
      a4: this->m_pWorldListInfo->m_pLeafDataList);
  engine->Sound_ExtraUpdate(this: engine);
  v5 = g_CurrentViewID;
  m_pMainView = this->m_pMainView;
  g_CurrentViewID = (view_id_t)viewID;
  m_BaseDrawFlags = m_pMainView->m_BaseDrawFlags;
  v8 = this->__vftable;
  savedViewID = v5;
  v9 = this->m_DrawFlags | m_BaseDrawFlags;
  iDrawFlagsBackup = this->m_DrawFlags;
  PushView = v8->PushView;
  this->m_DrawFlags = v9;
  ((void (__thiscall *)(CBaseWorldView *, _DWORD))PushView)(a1: this, a2: LODWORD(waterHeight));
  v11 = materials->GetRenderContext(this: materials);
  v12 = v11;
  if ( v11 != nullptr )
    v11->BeginRender(this: v11);
  v13 = (int)v12->GetFrameBufferCopyTexture(this: v12, a2: 0);
  v14 = v12->__vftable;
  pSaveFrameBufferCopyTexture = (ITexture *)v13;
  PowerOfTwoFrameBufferTexture = GetPowerOfTwoFrameBufferTexture();
  v14->SetFrameBufferCopyTexture(this: v12, a2: PowerOfTwoFrameBufferTexture, a3: 0);
  v16 = this->m_pRenderablesList->m_RenderGroupCounts[0];
  v17 = alloca(4 * v16);
  arrFastClippedOpaqueRenderables.m_Memory.m_pMemory = (CClientRenderablesList::CEntry **)v20;
  arrFastClippedOpaqueRenderables.m_Memory.m_nAllocationCount = v16;
  arrFastClippedOpaqueRenderables.m_pElements = (CClientRenderablesList::CEntry **)v20;
  arrFastClippedOpaqueRenderables.m_Memory.m_nGrowSize = -1;
  arrFastClippedOpaqueRenderables.m_Size = 0;
  if ( r_deferopaquefastclipped.m_pParent != nullptr
    && r_deferopaquefastclipped.m_pParent->m_Value.m_nValue != 0
    && (*((_BYTE *)&this->CViewSetup + 240) & 0x20) == 0
    && r_entityclips.m_pParent != nullptr
    && r_entityclips.m_pParent->m_Value.m_nValue != 0
    && materials->UsingFastClipping(this: materials) )
  {
    pArrFastClippedOpaqueRenderables = &arrFastClippedOpaqueRenderables;
  }
  else
  {
    pArrFastClippedOpaqueRenderables = nullptr;
  }
  this->m_DrawFlags |= 0x8000u;
  CRendering3dView::DrawWorld(this, pRenderContext: v12, waterZAdjust);
  this->m_DrawFlags &= ~0x8000u;
  if ( (this->m_DrawFlags & 0x2000) != 0 )
    CRendering3dView::DrawOpaqueRenderables(
      this,
      pRenderContext: v12,
      eRenderPath: RENDERABLES_RENDER_PATH_NORMAL,
      pDeferClippedOpaqueRenderables_Out: pArrFastClippedOpaqueRenderables);
  m_DrawFlags = this->m_DrawFlags;
  if ( (m_DrawFlags & 0x100) != 0 )
  {
    this->m_DrawFlags = m_DrawFlags & 0xFFFF778F | 0x8040;
    CRendering3dView::DrawWorld(this, pRenderContext: v12, waterZAdjust);
    this->m_DrawFlags = m_DrawFlags;
  }
  this->m_DrawFlags |= 0x4000u;
  if ( (this->m_DrawFlags & 0x480000) == 0 )
    CRendering3dView::DrawWorld(this, pRenderContext: v12, waterZAdjust);
  this->m_DrawFlags &= ~0x4000u;
  if ( (*((_BYTE *)&this->CViewSetup + 240) & 0x20) == 0 )
  {
    if ( (this->m_DrawFlags & 0x2000) != 0 )
    {
      CRendering3dView::DrawDeferredClippedOpaqueRenderables(
        this,
        pRenderContext: v12,
        eRenderPath: RENDERABLES_RENDER_PATH_NORMAL,
        pDeferClippedOpaqueRenderables: pArrFastClippedOpaqueRenderables);
      CRendering3dView::DrawTranslucentRenderables(
        this,
        m_DrawFlags,
        a3: (int)v12,
        bInSkybox: false,
        bShadowDepth: false);
      CRendering3dView::DrawNoZBufferTranslucentRenderables(
        this,
        a2: (_BYTE *)m_DrawFlags,
        a3: *(float *)&v12,
        a4: this);
    }
    else
    {
      CRendering3dView::DrawTranslucentWorldInLeaves(this, pRenderContext: v12, bShadowDepth: 0);
    }
  }
  if ( g_CurrentViewID != VIEW_MAIN && g_CurrentViewID != VIEW_INTRO_CAMERA )
    PixelVisibility_EndCurrentView();
  v19 = materials->GetRenderContext(this: materials);
  v12->EndRender(this: v12);
  v12->Release(this: v12);
  if ( v19 != nullptr )
    v19->AddRef(this: v19);
  v19->BeginRender(this: v19);
  v19->SetFrameBufferCopyTexture(this: v19, a2: pSaveFrameBufferCopyTexture, a3: 0);
  this->PopView(this);
  g_CurrentViewID = savedViewID;
  this->m_DrawFlags = iDrawFlagsBackup;
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&arrFastClippedOpaqueRenderables);
  v19->EndRender(this: v19);
  v19->Release(this: v19);
}

//------------------------------------------------------------------------------
// Address: 0x101A4FD0
// Name: public: void CWorldListCache::Add(class CViewSetup const __near &,struct VisOverrideData_t __near *,int,class IWorldRenderList __near *,struct ClientWorldListInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CWorldListCache::Add(
        CWorldListCache *this@<ecx>,
        const char *a2@<edi>,
        const CViewSetup *viewSetup,
        VisOverrideData_t *pVisOverrideData,
        int iForceViewLeaf,
        IWorldRenderList *pList,
        ClientWorldListInfo_t *pListInfo)
{
  CWorldListCache::Entry_t *v8; // eax
  ClientWorldListInfo_t *v9; // ebx
  unsigned __int16 v10; // ax
  int v11; // edi
  UtlRBTreeNode_t<CWorldListCache::Entry_t *,unsigned short> *m_pMemory; // edx

  v8 = (CWorldListCache::Entry_t *)MemAlloc_Alloc(nSize: 0xB8u);
  if ( v8 != nullptr )
    v9 = (ClientWorldListInfo_t *)CWorldListCache::Entry_t::Entry_t(
                                    this: v8,
                                    viewSetup,
                                    pVisOverrideData,
                                    iForceViewLeaf,
                                    pList,
                                    pListInfo);
  else
    v9 = nullptr;
  pListInfo = v9;
  iForceViewLeaf = 0xFFFF;
  LOBYTE(pList) = 0;
  CUtlRBTree<CWorldListCache::Entry_t *,unsigned short,CWorldListCache::CEntryComparator,CUtlMemory<UtlRBTreeNode_t<CWorldListCache::Entry_t *,unsigned short>,unsigned short>>::FindInsertionPosition(
    this: &this->m_Entries,
    insert: (const CWorldListCache::Entry_t **)&pListInfo,
    parent: (unsigned __int16 *)&iForceViewLeaf,
    leftchild: (bool *)&pList);
  v10 = CUtlRBTree<CWorldListCache::Entry_t *,unsigned short,CWorldListCache::CEntryComparator,CUtlMemory<UtlRBTreeNode_t<CWorldListCache::Entry_t *,unsigned short>,unsigned short>>::NewNode(
          (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)this,
          a2);
  v11 = v10;
  CUtlRBTree<CWorldListCache::Entry_t *,unsigned short,CWorldListCache::CEntryComparator,CUtlMemory<UtlRBTreeNode_t<CWorldListCache::Entry_t *,unsigned short>,unsigned short>>::LinkToParent(
    this: &this->m_Entries,
    i: v10,
    parent: iForceViewLeaf,
    isLeft: (bool)pList);
  m_pMemory = this->m_Entries.m_Elements.m_pMemory;
  ++this->m_Entries.m_NumElements;
  if ( &m_pMemory[v11] != (UtlRBTreeNode_t<CWorldListCache::Entry_t *,unsigned short> *)-8 )
    m_pMemory[v11].m_Data = (CWorldListCache::Entry_t *)v9;
}

//------------------------------------------------------------------------------
// Address: 0x101A5070
// Name: protected: void CRendering3dView::BuildWorldRenderLists(bool,int,bool,bool,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRendering3dView::BuildWorldRenderLists(
        CRendering3dView *this,
        bool bDrawEntities,
        int iForceViewLeaf,
        bool bUseCacheIfEnabled,
        BOOL bShadowDepth,
        float *pReflectionWaterHeight)
{
  ViewCustomVisibility_t *m_pCustomVisibility; // ecx
  VisOverrideData_t *p_m_VisData; // edx
  bool v9; // al
  int m_iForceViewLeaf; // edi
  ClientWorldListInfo_t *v11; // eax
  WorldListInfo_t *v12; // eax
  VisOverrideData_t *pVisData; // [esp+Ch] [ebp-4h]
  bool bUseCache; // [esp+23h] [ebp+13h]

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "BuildWorldRenderLists",
    a3: 0,
    a4: "World Render Setup",
    a5: false,
    a6: 4);
  UpdateClientRenderableInPVSStatus();
  ++this->m_pMainView->m_BuildWorldListsNumber;
  m_pCustomVisibility = this->m_pCustomVisibility;
  if ( m_pCustomVisibility == nullptr || m_pCustomVisibility->m_VisData.m_fDistToAreaPortalTolerance == 3.4028235e38 )
    p_m_VisData = nullptr;
  else
    p_m_VisData = &m_pCustomVisibility->m_VisData;
  pVisData = p_m_VisData;
  v9 = bUseCacheIfEnabled && r_worldlistcache.m_pParent != nullptr && r_worldlistcache.m_pParent->m_Value.m_nValue != 0;
  bUseCache = v9;
  if ( m_pCustomVisibility != nullptr )
    m_iForceViewLeaf = m_pCustomVisibility->m_iForceViewLeaf;
  else
    m_iForceViewLeaf = iForceViewLeaf;
  if ( !v9
    || !CWorldListCache::Find(
          this: &g_WorldListCache,
          viewSetup: &this->CViewSetup,
          pVisOverrideData: p_m_VisData,
          iForceViewLeaf: m_iForceViewLeaf,
          ppList: &this->m_pWorldRenderList,
          ppListInfo: &this->m_pWorldListInfo) )
  {
    this->m_pWorldRenderList = render->CreateWorldList(this: render);
    v11 = (ClientWorldListInfo_t *)MemAlloc_Alloc(nSize: 0x20u);
    if ( v11 != nullptr )
    {
      v11->m_iRefs = 1;
      v11->__vftable = (ClientWorldListInfo_t_vtbl *)&ClientWorldListInfo_t::`vftable';
      *(_QWORD *)&v11->m_ViewFogVolume = 0;
      *(_QWORD *)&v11->m_bHasWater = 0;
      v11->m_pOriginalLeafIndex = nullptr;
      v11->m_bPooledAlloc = false;
    }
    else
    {
      v11 = nullptr;
    }
    this->m_pWorldListInfo = v11;
    if ( v11 != nullptr )
      v12 = &v11->WorldListInfo_t;
    else
      v12 = nullptr;
    render->BuildWorldLists(
      this: render,
      a2: this->m_pWorldRenderList,
      a3: v12,
      a4: m_iForceViewLeaf,
      a5: pVisData,
      a6: bShadowDepth,
      a7: pReflectionWaterHeight);
    if ( bUseCache )
      CWorldListCache::Add(
        this: &g_WorldListCache,
        viewSetup: &this->CViewSetup,
        pVisOverrideData: pVisData,
        iForceViewLeaf: m_iForceViewLeaf,
        pList: this->m_pWorldRenderList,
        pListInfo: this->m_pWorldListInfo);
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x101A51E0
// Name: protected: void CSkyboxView::DrawInternal(enum view_id_t,bool,class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSkyboxView::DrawInternal(
        CSkyboxView *this,
        int iSkyBoxViewID,
        int bInvokePreAndPostRender,
        ITexture *pRenderTarget)
{
  unsigned __int8 **v5; // eax
  sky3dparams_t *m_pSky3dParams; // ecx
  IMaterial *v7; // edi
  unsigned __int8 *v8; // eax
  int m_Value; // edx
  sky3dparams_t *v10; // eax
  int v11; // ecx
  float v12; // xmm0_4
  Vector *p_origin; // edi
  float z; // edx
  float v15; // xmm0_4
  float v16; // xmm0_4
  IMatRenderContext *v17; // ebx
  C_BasePlayer *v18; // eax
  IMatRenderContext *v19; // ebx
  IMatRenderContext *v20; // eax
  IMatRenderContext *v21; // edi
  IMatRenderContext *v22; // eax
  IMatRenderContext *v23; // edi
  IMatRenderContext *v24; // ebx
  float v25; // xmm0_4
  C_BasePlayer *v26; // ecx
  float m_fValue; // xmm0_4
  C_BasePlayer *v28; // ecx
  float v29; // xmm0_4
  IClientMode *ClientMode; // eax
  float v31; // xmm0_4
  unsigned __int8 tmpbits[32]; // [esp+78h] [ebp-48h] BYREF
  Vector vTransformedSkyOrigin; // [esp+98h] [ebp-28h] BYREF
  Vector vSkyOrigin; // [esp+A4h] [ebp-1Ch] BYREF
  IMaterial *pMat; // [esp+B0h] [ebp-10h]
  unsigned __int8 *savebits; // [esp+B4h] [ebp-Ch]
  C_BasePlayer *LocalPlayer; // [esp+B8h] [ebp-8h]
  float scale; // [esp+BCh] [ebp-4h]

  v5 = render->GetAreaBits(this: render);
  m_pSky3dParams = this->m_pSky3dParams;
  v7 = (IMaterial *)v5;
  v8 = *v5;
  memset(tmpbits, 0, sizeof(tmpbits));
  m_Value = m_pSky3dParams->area.m_Value;
  savebits = v8;
  tmpbits[m_Value >> 3] |= 1 << (m_Value & 7);
  v7->__vftable = (IMaterial_vtbl *)tmpbits;
  v10 = this->m_pSky3dParams;
  this->zNear = 2.0;
  this->zFar = 56755.84;
  v11 = v10->scale.m_Value;
  v12 = 1.0;
  pMat = v7;
  if ( v11 > 0 )
    v12 = 1.0 / (float)v11;
  p_origin = &this->origin;
  *(_QWORD *)&vSkyOrigin.x = *(_QWORD *)&v10->origin.m_Value.x;
  z = v10->origin.m_Value.z;
  this->origin.CRendering3dView::CBase3dView::CViewSetup::x = this->origin.CRendering3dView::CBase3dView::CViewSetup::x
                                                            * v12;
  this->origin.y = this->origin.y * v12;
  this->origin.z = this->origin.z * v12;
  scale = v12;
  this->origin.CRendering3dView::CBase3dView::CViewSetup::x = this->origin.CRendering3dView::CBase3dView::CViewSetup::x
                                                            + vSkyOrigin.x;
  this->origin.y = this->origin.y + vSkyOrigin.y;
  v15 = this->origin.z;
  vSkyOrigin.z = z;
  this->origin.z = v15 + z;
  if ( this->m_bCustomViewMatrix )
  {
    VectorRotate(in1: &vSkyOrigin.x, in2: &this->m_matCustomViewMatrix, out: &vTransformedSkyOrigin.x);
    v16 = scale;
    this->m_matCustomViewMatrix.m_flMatVal[0][3] = (float)(this->m_matCustomViewMatrix.m_flMatVal[0][3] * scale)
                                                 - vTransformedSkyOrigin.x;
    this->m_matCustomViewMatrix.m_flMatVal[1][3] = (float)(this->m_matCustomViewMatrix.m_flMatVal[1][3] * v16)
                                                 - vTransformedSkyOrigin.y;
    this->m_matCustomViewMatrix.m_flMatVal[2][3] = (float)(this->m_matCustomViewMatrix.m_flMatVal[2][3] * v16)
                                                 - vTransformedSkyOrigin.z;
  }
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
  {
    v17 = materials->GetRenderContext(this: materials);
    if ( v17 != nullptr )
      v17->BeginRender(this: v17);
    v18 = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    if ( v18 == nullptr )
      goto LABEL_13;
    if ( fog_override.m_pParent != nullptr && fog_override.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( fog_enableskybox.m_pParent == nullptr || fog_enableskybox.m_pParent->m_Value.m_nValue == 0 )
        goto LABEL_13;
    }
    else if ( !v18->m_Local.m_skybox3d.fog.enable.m_Value )
    {
LABEL_13:
      v17->FogMode(this: v17, a2: MATERIAL_FOG_NONE);
      goto LABEL_14;
    }
    GetSkyboxFogColor(pColor: &vTransformedSkyOrigin.x, ignoreOverride: false, ignoreHDRColorScale: false);
    v25 = (float)LocalPlayer->m_Local.m_skybox3d.scale.m_Value;
    scale = 1.0;
    if ( v25 > 0.0 )
      scale = 1.0 / v25;
    v17->FogMode(this: v17, a2: MATERIAL_FOG_LINEAR);
    v17->FogColor3fv(this: v17, a2: &vTransformedSkyOrigin.x);
    v26 = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    if ( v26 != nullptr )
    {
      if ( fog_override.m_pParent == nullptr
        || fog_override.m_pParent->m_Value.m_nValue == 0
        || (m_fValue = fog_startskybox.m_pParent->m_Value.m_fValue) == -1.0 )
      {
        m_fValue = v26->m_Local.m_skybox3d.fog.start.m_Value;
      }
    }
    else
    {
      m_fValue = 0.0;
    }
    ((void (__thiscall *)(IMatRenderContext *, _DWORD))v17->FogStart)(a1: v17, a2: m_fValue * scale);
    v28 = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    if ( v28 != nullptr )
    {
      if ( fog_override.m_pParent == nullptr
        || fog_override.m_pParent->m_Value.m_nValue == 0
        || (v29 = fog_endskybox.m_pParent->m_Value.m_fValue) == -1.0 )
      {
        v29 = v28->m_Local.m_skybox3d.fog.end.m_Value;
      }
    }
    else
    {
      v29 = 0.0;
    }
    ((void (__thiscall *)(IMatRenderContext *, _DWORD))v17->FogEnd)(a1: v17, a2: v29 * scale);
    scale = COERCE_FLOAT(C_BasePlayer::GetLocalPlayer(nSlot: -1));
    if ( scale != 0.0 && (cl_leveloverview.m_pParent == nullptr || cl_leveloverview.m_pParent->m_Value.m_nValue == 0) )
    {
      ClientMode = GetClientMode();
      if ( ClientMode->ShouldDrawFog(this: ClientMode) )
      {
        if ( fog_override.m_pParent != nullptr && fog_override.m_pParent->m_Value.m_nValue != 0 )
        {
          v31 = fog_maxdensityskybox.m_pParent->m_Value.m_fValue;
          if ( v31 == -1.0 )
          {
            ((void (__thiscall *)(IMatRenderContext *, _DWORD))v17->FogMaxDensity)(
              a1: v17,
              a2: *(_DWORD *)(LODWORD(scale) + 5108));
            goto LABEL_14;
          }
        }
        else
        {
          v31 = *(float *)(LODWORD(scale) + 5108);
        }
        v17->FogMaxDensity(this: v17, a2: COERCE_FLOAT(LODWORD(v31)));
        goto LABEL_14;
      }
    }
    ((void (__thiscall *)(IMatRenderContext *, int))v17->FogMaxDensity)(a1: v17, a2: 1065353216);
LABEL_14:
    v17->EndRender(this: v17);
    v17->Release(this: v17);
  }
  render->ViewSetupVis(this: render, a2: false, a3: 1, a4: (const Vector *)&this->m_pSky3dParams->origin);
  v19 = materials->GetRenderContext(this: materials);
  if ( v19 != nullptr )
    v19->BeginRender(this: v19);
  render->Push3DView_2(
    this: render,
    a2: v19,
    a3: &this->CViewSetup,
    a4: this->m_ClearFlags,
    a5: pRenderTarget,
    a6: this->m_Frustum);
  SetupCurrentView(
    a1: (int)p_origin,
    a2: (int)this,
    vecOrigin: &this->origin,
    angles: &this->angles,
    viewID: (view_id_t)iSkyBoxViewID,
    bDrawWorldNormal: false,
    bCullFrontFaces: false);
  if ( (_BYTE)bInvokePreAndPostRender != 0 )
    IGameSystem::PreRenderAllSystems();
  render->BeginUpdateLightmaps(this: render);
  CRendering3dView::BuildWorldRenderLists(
    this,
    bDrawEntities: true,
    iForceViewLeaf: -1,
    bUseCacheIfEnabled: true,
    bShadowDepth: false,
    pReflectionWaterHeight: nullptr);
  CRendering3dView::BuildRenderableRenderLists(
    this,
    viewID: iSkyBoxViewID,
    bFastEntityRendering: false,
    bDrawDepthViewNonCachedObjectsOnly: false);
  render->EndUpdateLightmaps(this: render);
  CRendering3dView::DrawWorld(this, pRenderContext: v19, waterZAdjust: 0.0);
  CRendering3dView::DrawOpaqueRenderables(
    this,
    pRenderContext: v19,
    eRenderPath: RENDERABLES_RENDER_PATH_NORMAL,
    pDeferClippedOpaqueRenderables_Out: nullptr);
  CRendering3dView::DrawTranslucentRenderables(
    this,
    m_DrawFlags: (int)v19,
    a3: (int)p_origin,
    bInSkybox: true,
    bShadowDepth: false);
  CRendering3dView::DrawNoZBufferTranslucentRenderables(this, a2: v19, a3: *(float *)&p_origin, a4: this);
  v20 = materials->GetRenderContext(this: materials);
  v21 = v20;
  if ( v20 != nullptr )
    v20->BeginRender(this: v20);
  v21->FogMode(this: v21, a2: MATERIAL_FOG_NONE);
  v21->EndRender(this: v21);
  v21->Release(this: v21);
  CGlowOverlay::UpdateSkyOverlays(zFar: this->zFar, bCacheFullSceneState: *((_BYTE *)&this->CViewSetup + 240) >> 7);
  PixelVisibility_EndCurrentView();
  pMat->__vftable = (IMaterial_vtbl *)savebits;
  if ( v19 != nullptr )
  {
    v19->EndRender(this: v19);
    v19->Release(this: v19);
  }
  if ( (_BYTE)bInvokePreAndPostRender != 0 )
  {
    IGameSystem::PostRenderAllSystems();
    s_bCanAccessCurrentView = false;
  }
  if ( IsDepthOfFieldEnabled() )
  {
    pMat = materials->FindMaterial(this: materials, a2: "dev/clearalpha", a3: "Other textures", a4: 1, a5: 0);
    if ( pMat != nullptr )
    {
      pRenderTarget = nullptr;
      iSkyBoxViewID = 0;
      bInvokePreAndPostRender = 0;
      v22 = materials->GetRenderContext(this: materials);
      v23 = v22;
      if ( v22 != nullptr )
        v22->BeginRender(this: v22);
      v23->GetViewport(
        this: v23,
        a2: &bInvokePreAndPostRender,
        a3: &bInvokePreAndPostRender,
        a4: (int *)&pRenderTarget,
        a5: &iSkyBoxViewID);
      ((void (__thiscall *)(IMatRenderContext *, IMaterial *, _DWORD, _DWORD, ITexture *, int, _DWORD, _DWORD, float, float, ITexture *, int, _DWORD, int, int))v23->DrawScreenSpaceRectangle)(
        a1: v23,
        a2: pMat,
        a3: 0,
        a4: 0,
        a5: pRenderTarget,
        a6: iSkyBoxViewID,
        a7: 0,
        a8: 0,
        a9: (float)((int)&pRenderTarget[-1].__vftable + 3),
        a10: (float)(iSkyBoxViewID - 1),
        a11: pRenderTarget,
        a12: iSkyBoxViewID,
        a13: 0,
        a14: 1,
        a15: 1);
      v23->EndRender(this: v23);
      v23->Release(this: v23);
    }
  }
  v24 = materials->GetRenderContext(this: materials);
  if ( v24 != nullptr )
    v24->AddRef(this: v24);
  v24->BeginRender(this: v24);
  render->PopView(this: render, a2: v24, a3: this->m_Frustum);
  v24->EndRender(this: v24);
  v24->Release(this: v24);
}

//------------------------------------------------------------------------------
// Address: 0x101A58A0
// Name: public: virtual void CSkyboxView::Draw(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSkyboxView::Draw(CSkyboxView *this)
{
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CViewRender::Draw3dSkyboxworld",
    a3: 0,
    a4: "3D Skybox",
    a5: false,
    a6: 4);
  CSkyboxView::DrawInternal(this, iSkyBoxViewID: 1, bInvokePreAndPostRender: 1, pRenderTarget: nullptr);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x101A58E0
// Name: public: virtual void CShadowDepthView::Draw(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShadowDepthView::Draw(CShadowDepthView *this)
{
  CViewSetup *v2; // eax
  IVRenderView_vtbl *v3; // edi
  unsigned __int8 v4; // al
  IMatRenderContext *v5; // edi
  void (__thiscall *GetScreenFadeDistances)(IViewRender *, float *, float *); // edx
  IMatRenderContext *v7; // ebx
  int m_nValue; // eax
  IMDLCache *v9; // ebx
  VPlane *m_Frustum; // edx
  unsigned int visFlags; // [esp+78h] [ebp-Ch] BYREF
  int v12; // [esp+7Ch] [ebp-8h] BYREF
  int v13; // [esp+80h] [ebp-4h] BYREF

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CShadowDepthView::Draw",
    a3: 0,
    a4: "Flashlight Shadows",
    a5: false,
    a6: 4);
  if ( this != nullptr )
    v2 = &this->CViewSetup;
  else
    v2 = nullptr;
  v3 = render->__vftable;
  v4 = ((int (__thiscall *)(CViewRender *, int, Vector *, unsigned int *))this->m_pMainView->ShouldForceNoVis)(
         a1: this->m_pMainView,
         a2: 1,
         a3: &v2->origin,
         a4: &visFlags);
  ((void (__thiscall *)(IVRenderView *, _DWORD))v3->ViewSetupVisEx)(a1: render, a2: v4);
  v5 = materials->GetRenderContext(this: materials);
  if ( v5 != nullptr )
    v5->BeginRender(this: v5);
  v5->ClearColor3ub(this: v5, a2: 255u, a3: 255u, a4: 255u);
  render->Push3DView(
    this: render,
    a2: v5,
    a3: &this->CViewSetup,
    a4: 2,
    a5: this->m_pRenderTarget,
    a6: this->m_Frustum,
    a7: this->m_pDepthTexture);
  g_vecCurrentRenderOrigin = this->origin;
  g_vecCurrentRenderAngles = this->angles;
  ComputeCameraVariables(
    vecOrigin: &this->origin,
    vecAngles: &this->angles,
    pVecForward: &g_vecCurrentVForward,
    pVecRight: &g_vecCurrentVRight,
    pVecUp: &g_vecCurrentVUp,
    pMatCamInverse: &g_matCurrentCamInverse);
  s_bCanAccessCurrentView = true;
  GetScreenFadeDistances = view->GetScreenFadeDistances;
  g_CurrentViewID = VIEW_SHADOW_DEPTH_TEXTURE;
  GetScreenFadeDistances(this: view, a2: (float *)&v12, a3: (float *)&v13);
  ((void (__thiscall *)(IVModelInfoClient *, int, int))modelinfo->SetViewScreenFadeRange)(
    a1: modelinfo,
    a2: v12,
    a3: v13);
  v7 = materials->GetRenderContext(this: materials);
  if ( v7 != nullptr )
    v7->BeginRender(this: v7);
  v7->SetIntRenderingParameter(this: v7, a2: 10, a3: 0);
  if ( mat_lpreview_mode.m_pParent == nullptr )
  {
    m_nValue = 0;
LABEL_12:
    v7->SetIntRenderingParameter(this: v7, a2: 0, a3: m_nValue);
    goto LABEL_13;
  }
  m_nValue = mat_lpreview_mode.m_pParent->m_Value.m_nValue;
  if ( m_nValue != -1 )
    goto LABEL_12;
LABEL_13:
  v7->EndRender(this: v7);
  v7->Release(this: v7);
  v9 = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  CRendering3dView::BuildWorldRenderLists(
    this,
    bDrawEntities: true,
    iForceViewLeaf: -1,
    bUseCacheIfEnabled: true,
    bShadowDepth: true,
    pReflectionWaterHeight: nullptr);
  CRendering3dView::BuildRenderableRenderLists(
    this,
    viewID: g_CurrentViewID,
    bFastEntityRendering: false,
    bDrawDepthViewNonCachedObjectsOnly: false);
  engine->Sound_ExtraUpdate(this: engine);
  this->m_DrawFlags = this->m_pMainView->m_BaseDrawFlags | 0x100030;
  CRendering3dView::DrawWorld(this, pRenderContext: v5, waterZAdjust: 0.0);
  modelrender->ForcedMaterialOverride(this: modelrender, a2: nullptr, a3: OVERRIDE_DEPTH_WRITE);
  CRendering3dView::DrawOpaqueRenderables(
    this,
    pRenderContext: v5,
    eRenderPath: RENDERABLES_RENDER_PATH_SHADOWDEPTH_DEFAULT,
    pDeferClippedOpaqueRenderables_Out: nullptr);
  if ( r_flashlightdepth_drawtranslucents.m_pParent != nullptr
    && r_flashlightdepth_drawtranslucents.m_pParent->m_Value.m_nValue != 0 )
  {
    CRendering3dView::DrawTranslucentRenderables(
      this,
      m_DrawFlags: (int)v9,
      a3: (int)v5,
      bInSkybox: false,
      bShadowDepth: true);
  }
  modelrender->ForcedMaterialOverride(this: modelrender, a2: nullptr, a3: OVERRIDE_NORMAL);
  m_Frustum = this->m_Frustum;
  this->m_DrawFlags = 0;
  render->PopView(this: render, a2: v5, a3: m_Frustum);
  v9->EndLock(this: v9);
  v5->EndRender(this: v5);
  v5->Release(this: v5);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x101A5BE0
// Name: protected: void CBaseWorldView::DrawSetup(class IMatRenderContext __near *,float,int,float,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseWorldView::DrawSetup(
        CBaseWorldView *this@<ecx>,
        const char *a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        IMatRenderContext *pRenderContext,
        float waterHeight,
        BOOL nSetupFlags,
        float waterZAdjust,
        int iForceViewLeaf)
{
  view_id_t v9; // ebx
  bool (__thiscall *AdjustView)(CBaseWorldView *, float); // edx
  BOOL v12; // edi
  view_id_t savedViewID; // [esp+10h] [ebp-8h]
  char bViewChanged; // [esp+17h] [ebp-1h]

  v9 = g_CurrentViewID;
  AdjustView = this->AdjustView;
  savedViewID = g_CurrentViewID;
  g_CurrentViewID = VIEW_ILLEGAL;
  bViewChanged = ((int (__stdcall *)(_DWORD, int, int))AdjustView)(a1: LODWORD(waterHeight), a2: a3, a3: a4);
  if ( bViewChanged != 0 )
    render->Push3DView_2(
      this: render,
      a2: pRenderContext,
      a3: &this->CViewSetup,
      a4: 0,
      a5: nullptr,
      a6: this->m_Frustum);
  v12 = nSetupFlags;
  if ( (nSetupFlags & 0x480000) != 0 )
  {
    LOBYTE(nSetupFlags) = (nSetupFlags & 0x200000) != 0;
    if ( (v12 & 0x2000) != 0 && (v12 & 0x200000) != 0 )
      CRendering3dView::BuildRenderableRenderLists(
        this,
        viewID: v9,
        bFastEntityRendering: nSetupFlags,
        bDrawDepthViewNonCachedObjectsOnly: false);
    else
      _Error(this: (ISceneTokenProcessor *)&stru_10497390, a2);
  }
  else
  {
    render->BeginUpdateLightmaps(this: render);
    LOBYTE(nSetupFlags) = (v12 & 0x2000) != 0;
    CRendering3dView::BuildWorldRenderLists(
      this,
      bDrawEntities: nSetupFlags,
      iForceViewLeaf,
      bUseCacheIfEnabled: true,
      bShadowDepth: false,
      pReflectionWaterHeight: (v12 & 2) != 0 ? &waterHeight : nullptr);
    CRendering3dView::PruneWorldListInfo(this);
    if ( (v12 & 0x2000) != 0 )
      CRendering3dView::BuildRenderableRenderLists(
        this,
        viewID: savedViewID,
        bFastEntityRendering: (v12 & 0x200000) != 0,
        bDrawDepthViewNonCachedObjectsOnly: false);
    render->EndUpdateLightmaps(this: render);
    v9 = savedViewID;
  }
  if ( bViewChanged != 0 )
    render->PopView(this: render, a2: pRenderContext, a3: this->m_Frustum);
  g_CurrentViewID = v9;
}

//------------------------------------------------------------------------------
// Address: 0x101A5D30
// Name: public: virtual void CSimpleWorldView::Draw(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall CSimpleWorldView::Draw(CSimpleWorldView *this@<ecx>, int a2@<edi>)
{
  IMatRenderContext *v3; // esi
  int v4; // eax
  int v5; // edi
  fogparams_t *v6; // esi
  C_BasePlayer *LocalPlayer; // eax
  IClientMode *ClientMode; // eax
  float m_fValue; // xmm0_4
  float v10; // xmm0_4
  float m_Value; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm2_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm3_4
  float v18; // xmm2_4
  IClientMode *v19; // eax
  IMatRenderContext *v20; // eax
  IMatRenderContext *v21; // esi
  IMatRenderContext *v22; // eax
  IMatRenderContext *v23; // esi
  float pColor; // [esp+30h] [ebp-Ch] BYREF
  unsigned __int8 ucFogColor[8]; // [esp+34h] [ebp-8h] OVERLAPPED BYREF

  v3 = materials->GetRenderContext(this: materials);
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  CBaseWorldView::DrawSetup(
    this,
    a2: (const char *)this,
    a3: a2,
    a4: (int)v3,
    pRenderContext: v3,
    waterHeight: 0.0,
    nSetupFlags: this->m_DrawFlags,
    waterZAdjust: 0.0,
    iForceViewLeaf: -1);
  if ( v3 != nullptr )
  {
    v3->EndRender(this: v3);
    v3->Release(this: v3);
  }
  if ( !this->m_fogInfo.m_bEyeInFogVolume )
  {
    v4 = ((int (__thiscall *)(IMaterialSystem *, int))materials->GetRenderContext)(a1: materials, a2);
    v5 = v4;
    if ( v4 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
    v6 = nullptr;
    LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    if ( LocalPlayer != nullptr )
      v6 = LocalPlayer->GetFogParams(this: LocalPlayer);
    if ( cl_leveloverview.m_pParent != nullptr && cl_leveloverview.m_pParent->m_Value.m_nValue != 0 )
      goto LABEL_17;
    ClientMode = GetClientMode();
    if ( !ClientMode->ShouldDrawFog(this: ClientMode) )
      goto LABEL_17;
    if ( fog_override.m_pParent != nullptr && fog_override.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( fog_enable.m_pParent == nullptr || fog_enable.m_pParent->m_Value.m_nValue == 0 )
      {
LABEL_17:
        (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 176))(a1: v5);
LABEL_18:
        (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 12))(a1: v5);
        (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 4))(a1: v5);
        goto LABEL_48;
      }
    }
    else if ( v6 == nullptr || !v6->enable.m_Value )
    {
      goto LABEL_17;
    }
    GetFogColor(pFogParams: v6, &pColor, ignoreOverride: false, ignoreHDRColorScale: false);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v5 + 176))(a1: v5, a2: 1);
    (*(void (__thiscall **)(int, float *))(*(_DWORD *)v5 + 200))(a1: v5, a2: &pColor);
    if ( v6 == nullptr )
    {
      m_fValue = 0.0;
      goto LABEL_27;
    }
    if ( fog_override.m_pParent != nullptr && fog_override.m_pParent->m_Value.m_nValue != 0 )
    {
      m_fValue = fog_start.m_pParent->m_Value.m_fValue;
      if ( m_fValue != -1.0 )
        goto LABEL_27;
    }
    else
    {
      m_Value = v6->lerptime.m_Value;
      v12 = *(float *)(gpGlobals.m_Index + 12);
      if ( m_Value > v12 )
      {
        v13 = v6->start.m_Value;
        v14 = v6->startLerpTo.m_Value;
        if ( v13 != v14 )
        {
          m_fValue = (float)((float)(1.0 - (float)((float)(m_Value - v12) / v6->duration.m_Value)) * (float)(v14 - v13))
                   + v13;
LABEL_27:
          (*(void (__thiscall **)(int, float))(*(_DWORD *)v5 + 180))(a1: v5, a2: COERCE_FLOAT(LODWORD(m_fValue)));
          if ( v6 == nullptr )
          {
            v10 = 0.0;
            goto LABEL_36;
          }
          if ( fog_override.m_pParent != nullptr && fog_override.m_pParent->m_Value.m_nValue != 0 )
          {
            v10 = fog_end.m_pParent->m_Value.m_fValue;
            if ( v10 != -1.0 )
              goto LABEL_36;
          }
          else
          {
            v15 = v6->lerptime.m_Value;
            v16 = *(float *)(gpGlobals.m_Index + 12);
            if ( v15 > v16 )
            {
              v17 = v6->end.m_Value;
              v18 = v6->endLerpTo.m_Value;
              if ( v17 != v18 )
              {
                v10 = (float)((float)(1.0 - (float)((float)(v15 - v16) / v6->duration.m_Value)) * (float)(v18 - v17))
                    + v17;
LABEL_36:
                (*(void (__thiscall **)(int, float))(*(_DWORD *)v5 + 184))(a1: v5, a2: COERCE_FLOAT(LODWORD(v10)));
                if ( v6 != nullptr
                  && (cl_leveloverview.m_pParent == nullptr || cl_leveloverview.m_pParent->m_Value.m_nValue == 0) )
                {
                  v19 = GetClientMode();
                  v19->ShouldDrawFog(this: v19);
                }
                (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 636))(a1: v5);
                goto LABEL_18;
              }
            }
          }
          v10 = v6->end.m_Value;
          goto LABEL_36;
        }
      }
    }
    m_fValue = v6->start.m_Value;
    goto LABEL_27;
  }
  this->m_ClearFlags |= 1u;
  render->SetFogVolumeState(this: render, a2: this->m_fogInfo.m_nVisibleFogVolume, a3: false);
  v20 = materials->GetRenderContext(this: materials);
  v21 = v20;
  if ( v20 != nullptr )
    v20->AddRef(this: v20);
  v21->BeginRender(this: v21);
  v21->GetFogColor(this: v21, a2: ucFogColor);
  v21->ClearColor4ub(
    this: v21,
    a2: *(_DWORD *)ucFogColor,
    a3: *(_DWORD *)&ucFogColor[1],
    a4: *(_DWORD *)&ucFogColor[2],
    a5: 255u);
  v21->EndRender(this: v21);
  v21->Release(this: v21);
LABEL_48:
  CBaseWorldView::DrawExecute(
    this,
    waterHeight: 0.0,
    viewID: (CUtlVector<CClientRenderablesList::CEntry *,CUtlMemory<CClientRenderablesList::CEntry *,int> > *)g_CurrentViewID,
    waterZAdjust: 0.0);
  v22 = materials->GetRenderContext(this: materials);
  v23 = v22;
  if ( v22 != nullptr )
    v22->AddRef(this: v22);
  v23->BeginRender(this: v23);
  v23->ClearColor4ub(this: v23, a2: 0, a3: 0, a4: 0, a5: 255u);
  v23->EndRender(this: v23);
  v23->Release(this: v23);
}

//------------------------------------------------------------------------------
// Address: 0x101A61B0
// Name: public: virtual void CBaseWaterView::CSoftwareIntersectionView::Draw(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseWaterView::CSoftwareIntersectionView::Draw(
        CBaseWaterView::CSoftwareIntersectionView *this@<ecx>,
        const char *a2@<ebx>)
{
  IMatRenderContext *v3; // edi

  v3 = materials->GetRenderContext(this: materials);
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  CBaseWorldView::DrawSetup(
    this,
    a2,
    a3: (int)v3,
    a4: (int)this,
    pRenderContext: v3,
    waterHeight: *((float *)this + 73),
    nSetupFlags: this->m_DrawFlags,
    waterZAdjust: *((float *)this + 74),
    iForceViewLeaf: -1);
  CBaseWorldView::DrawExecute(
    this,
    waterHeight: *((float *)this + 73),
    viewID: (CUtlVector<CClientRenderablesList::CEntry *,CUtlMemory<CClientRenderablesList::CEntry *,int> > *)g_CurrentViewID,
    waterZAdjust: *((float *)this + 74));
  if ( v3 != nullptr )
  {
    v3->EndRender(this: v3);
    v3->Release(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A6250
// Name: public: virtual void CAboveWaterView::Draw(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAboveWaterView::Draw(CAboveWaterView *this@<ecx>, void *p_m_ReflectionView@<edi>)
{
  IMatRenderContext *v3; // ebx
  char m_waterInfo; // al
  bool v5; // zf
  const CViewSetup *v6; // eax
  bool v7; // al
  IMatRenderContext *v8; // eax
  IMatRenderContext *v9; // ebx
  fogparams_t *v10; // edi
  C_BasePlayer *LocalPlayer; // eax
  IClientMode *ClientMode; // eax
  CViewSetup *v13; // eax
  float m_fValue; // xmm0_4
  float v15; // xmm0_4
  float m_Value; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm3_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm3_4
  float v23; // xmm2_4
  IClientMode *v24; // eax
  float v25; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm3_4
  float v29; // xmm2_4
  IMatRenderContext *m_pObject; // esi
  float pColor[3]; // [esp+28h] [ebp-14h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+34h] [ebp-8h]
  bool bViewIntersectsWater; // [esp+3Bh] [ebp-1h]

  v3 = materials->GetRenderContext(this: materials);
  pRenderContext.m_pObject = v3;
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  m_waterInfo = (char)this->m_waterInfo;
  if ( (m_waterInfo & 2) != 0 )
  {
    p_m_ReflectionView = &this->m_ReflectionView;
    CAboveWaterView::CReflectionView::Setup(
      this: &this->m_ReflectionView,
      bReflectEntities: (m_waterInfo & 8) != 0,
      bReflectOnlyMarkedEntities: (m_waterInfo & 0x10) != 0,
      bReflect2DSkybox: *((_BYTE *)&this->m_waterInfo + 1) & 1);
    this->m_pMainView->m_SimpleExecutor.AddView(this: &this->m_pMainView->m_SimpleExecutor, a2: &this->m_ReflectionView);
  }
  v5 = (*(_BYTE *)&this->m_waterInfo & 4) == 0;
  bViewIntersectsWater = false;
  if ( !v5 )
  {
    p_m_ReflectionView = &this->m_RefractionView;
    v6 = this != nullptr ? &this->CViewSetup : nullptr;
    CRendering3dView::Setup(this: &this->m_RefractionView, setup: v6);
    this->m_RefractionView.m_ClearFlags = 3;
    this->m_RefractionView.m_DrawFlags = 12309;
    this->m_pMainView->m_SimpleExecutor.AddView(this: &this->m_pMainView->m_SimpleExecutor, a2: &this->m_RefractionView);
    if ( !this->m_bSoftwareUserClipPlane )
      bViewIntersectsWater = DoesViewPlaneIntersectWater(
                               a1: (int)v3,
                               a2: (int)p_m_ReflectionView,
                               a3: (int)this,
                               waterZ: this->m_fogInfo.m_flWaterHeight,
                               leafWaterDataID: this->m_fogInfo.m_nVisibleFogVolume);
  }
  v7 = !g_pMaterialSystemHardwareConfig->UseFastClipping(this: g_pMaterialSystemHardwareConfig);
  if ( bViewIntersectsWater && v7 )
    this->m_DrawFlags |= 0xCu;
  CBaseWorldView::DrawSetup(
    this,
    a2: (const char *)v3,
    a3: (int)p_m_ReflectionView,
    a4: (int)this,
    pRenderContext: v3,
    waterHeight: this->m_waterHeight,
    nSetupFlags: this->m_DrawFlags,
    waterZAdjust: this->m_waterZAdjust,
    iForceViewLeaf: -1);
  v8 = materials->GetRenderContext(this: materials);
  v9 = v8;
  if ( v8 != nullptr )
    v8->BeginRender(this: v8);
  v10 = nullptr;
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
    v10 = LocalPlayer->GetFogParams(this: LocalPlayer);
  if ( cl_leveloverview.m_pParent != nullptr && cl_leveloverview.m_pParent->m_Value.m_nValue != 0 )
    goto LABEL_25;
  ClientMode = GetClientMode();
  if ( !ClientMode->ShouldDrawFog(this: ClientMode) )
    goto LABEL_25;
  if ( fog_override.m_pParent != nullptr && fog_override.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( fog_enable.m_pParent == nullptr || fog_enable.m_pParent->m_Value.m_nValue == 0 )
    {
LABEL_25:
      v9->FogMode(this: v9, a2: MATERIAL_FOG_NONE);
      goto LABEL_26;
    }
  }
  else if ( v10 == nullptr || !v10->enable.m_Value )
  {
    goto LABEL_25;
  }
  GetFogColor(pFogParams: v10, pColor, ignoreOverride: false, ignoreHDRColorScale: false);
  v9->FogMode(this: v9, a2: MATERIAL_FOG_LINEAR);
  v9->FogColor3fv(this: v9, a2: pColor);
  if ( v10 == nullptr )
  {
    m_fValue = 0.0;
    goto LABEL_38;
  }
  if ( fog_override.m_pParent != nullptr && fog_override.m_pParent->m_Value.m_nValue != 0 )
  {
    m_fValue = fog_start.m_pParent->m_Value.m_fValue;
    if ( m_fValue != -1.0 )
      goto LABEL_38;
    goto LABEL_37;
  }
  m_Value = v10->lerptime.m_Value;
  v17 = *(float *)(gpGlobals.m_Index + 12);
  if ( m_Value <= v17 || (v18 = v10->start.m_Value, v19 = v10->startLerpTo.m_Value, v18 == v19) )
  {
LABEL_37:
    m_fValue = v10->start.m_Value;
    goto LABEL_38;
  }
  m_fValue = (float)((float)(1.0 - (float)((float)(m_Value - v17) / v10->duration.m_Value)) * (float)(v19 - v18)) + v18;
LABEL_38:
  v9->FogStart(this: v9, a2: COERCE_FLOAT(LODWORD(m_fValue)));
  if ( v10 == nullptr )
  {
    v15 = 0.0;
    goto LABEL_47;
  }
  if ( fog_override.m_pParent != nullptr && fog_override.m_pParent->m_Value.m_nValue != 0 )
  {
    v15 = fog_end.m_pParent->m_Value.m_fValue;
    if ( v15 != -1.0 )
      goto LABEL_47;
    goto LABEL_46;
  }
  v20 = v10->lerptime.m_Value;
  v21 = *(float *)(gpGlobals.m_Index + 12);
  if ( v20 <= v21 || (v22 = v10->end.m_Value, v23 = v10->endLerpTo.m_Value, v22 == v23) )
  {
LABEL_46:
    v15 = v10->end.m_Value;
    goto LABEL_47;
  }
  v15 = (float)((float)(1.0 - (float)((float)(v20 - v21) / v10->duration.m_Value)) * (float)(v23 - v22)) + v22;
LABEL_47:
  v9->FogEnd(this: v9, a2: COERCE_FLOAT(LODWORD(v15)));
  if ( v10 == nullptr
    || cl_leveloverview.m_pParent != nullptr && cl_leveloverview.m_pParent->m_Value.m_nValue != 0
    || (v24 = GetClientMode(), !v24->ShouldDrawFog(this: v24)) )
  {
    ((void (__thiscall *)(IMatRenderContext *, int))v9->FogMaxDensity)(a1: v9, a2: 1065353216);
    goto LABEL_26;
  }
  if ( fog_override.m_pParent != nullptr && fog_override.m_pParent->m_Value.m_nValue != 0 )
  {
    v25 = fog_maxdensity.m_pParent->m_Value.m_fValue;
    if ( v25 != -1.0 )
    {
LABEL_60:
      v9->FogMaxDensity(this: v9, a2: COERCE_FLOAT(LODWORD(v25)));
      goto LABEL_26;
    }
LABEL_59:
    v25 = v10->maxdensity.m_Value;
    goto LABEL_60;
  }
  v26 = v10->lerptime.m_Value;
  v27 = *(float *)(gpGlobals.m_Index + 12);
  if ( v26 <= v27 )
    goto LABEL_59;
  v28 = v10->maxdensity.m_Value;
  v29 = v10->maxdensityLerpTo.m_Value;
  if ( v28 == v29 )
    goto LABEL_59;
  ((void (__thiscall *)(IMatRenderContext *, _DWORD))v9->FogMaxDensity)(
    a1: v9,
    a2: (float)((float)(1.0 - (float)((float)(v26 - v27) / v10->duration.m_Value)) * (float)(v29 - v28)) + v28);
LABEL_26:
  v9->EndRender(this: v9);
  v9->Release(this: v9);
  CBaseWorldView::DrawExecute(
    this,
    waterHeight: this->m_waterHeight,
    viewID: (CUtlVector<CClientRenderablesList::CEntry *,CUtlMemory<CClientRenderablesList::CEntry *,int> > *)g_CurrentViewID,
    waterZAdjust: this->m_waterZAdjust);
  if ( (*(_BYTE *)&this->m_waterInfo & 4) != 0 )
  {
    if ( this->m_bSoftwareUserClipPlane )
    {
      if ( this != nullptr )
        v13 = &this->CViewSetup;
      else
        v13 = nullptr;
      CRendering3dView::Setup(this: &this->m_SoftwareIntersectionView, setup: v13);
      this->m_SoftwareIntersectionView.m_DrawFlags = 16;
      this->m_SoftwareIntersectionView.Draw(this: &this->m_SoftwareIntersectionView);
    }
    else if ( bViewIntersectsWater )
    {
      CAboveWaterView::CIntersectionView::Setup(this: &this->m_IntersectionView);
      this->m_pMainView->m_SimpleExecutor.AddView(
        this: &this->m_pMainView->m_SimpleExecutor,
        a2: &this->m_IntersectionView);
    }
  }
  m_pObject = pRenderContext.m_pObject;
  if ( pRenderContext.m_pObject != nullptr )
  {
    pRenderContext.m_pObject->EndRender(this: pRenderContext.m_pObject);
    m_pObject->Release(this: m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A6790
// Name: public: virtual void CAboveWaterView::CReflectionView::Draw(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAboveWaterView::CReflectionView::Draw(CAboveWaterView::CReflectionView *this)
{
  IMatRenderContext *(__thiscall *GetRenderContext)(IMaterialSystem *); // edx
  char *v3; // ebx
  float x; // xmm0_4
  float z; // xmm0_4
  float v6; // xmm0_4
  void (__thiscall *GetScreenFadeDistances)(IViewRender *, float *, float *); // eax
  IMatRenderContext *v8; // eax
  int v9; // esi
  int m_nValue; // eax
  int v11; // eax
  IMatRenderContext *v12; // esi
  fogparams_t *v13; // edi
  C_BasePlayer *LocalPlayer; // eax
  IClientMode *ClientMode; // eax
  float m_fValue; // xmm0_4
  float v17; // xmm0_4
  float m_Value; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm3_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  float v23; // xmm0_4
  float v24; // xmm3_4
  float v25; // xmm2_4
  IClientMode *v26; // eax
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm3_4
  float v31; // xmm2_4
  float pColor[3]; // [esp+4Ch] [ebp-38h] BYREF
  Vector vecOldOrigin; // [esp+58h] [ebp-2Ch] BYREF
  QAngle vecOldAngles; // [esp+64h] [ebp-20h] BYREF
  int nSaveViewID; // [esp+70h] [ebp-14h]
  CBaseWorldView *v36; // [esp+74h] [ebp-10h]
  int v37; // [esp+78h] [ebp-Ch] BYREF
  int v38; // [esp+7Ch] [ebp-8h] BYREF
  bool bVisOcclusion; // [esp+83h] [ebp-1h]

  GetRenderContext = materials->GetRenderContext;
  v36 = this;
  v3 = (char *)GetRenderContext(this: materials);
  if ( v3 != nullptr )
    (*(void (__thiscall **)(char *))(*(_DWORD *)v3 + 8))(a1: v3);
  *(_QWORD *)&vecOldOrigin.x = *(_QWORD *)&g_vecCurrentRenderOrigin.x;
  *(_QWORD *)&vecOldAngles.x = *(_QWORD *)&g_vecCurrentRenderAngles.x;
  x = this->origin.CBaseWorldView::CRendering3dView::CBase3dView::CViewSetup::x;
  vecOldOrigin.z = g_vecCurrentRenderOrigin.z;
  g_vecCurrentRenderOrigin.x = x;
  g_vecCurrentRenderOrigin.y = this->origin.y;
  z = this->origin.z;
  nSaveViewID = g_CurrentViewID;
  g_vecCurrentRenderOrigin.z = z;
  g_vecCurrentRenderAngles.x = this->angles.CBaseWorldView::CRendering3dView::CBase3dView::CViewSetup::x;
  g_vecCurrentRenderAngles.y = this->angles.y;
  v6 = this->angles.z;
  vecOldAngles.z = g_vecCurrentRenderAngles.z;
  g_vecCurrentRenderAngles.z = v6;
  ComputeCameraVariables(
    vecOrigin: &this->origin,
    vecAngles: &this->angles,
    pVecForward: &g_vecCurrentVForward,
    pVecRight: &g_vecCurrentVRight,
    pVecUp: &g_vecCurrentVUp,
    pMatCamInverse: &g_matCurrentCamInverse);
  s_bCanAccessCurrentView = true;
  GetScreenFadeDistances = view->GetScreenFadeDistances;
  g_CurrentViewID = VIEW_REFLECTION;
  GetScreenFadeDistances(this: view, a2: (float *)&v37, a3: (float *)&v38);
  ((void (__thiscall *)(IVModelInfoClient *, int, int))modelinfo->SetViewScreenFadeRange)(
    a1: modelinfo,
    a2: v37,
    a3: v38);
  v8 = materials->GetRenderContext(this: materials);
  v9 = (int)v8;
  if ( v8 != nullptr )
    v8->BeginRender(this: v8);
  (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v9 + 464))(a1: v9, a2: 10, a3: 0);
  if ( mat_lpreview_mode.m_pParent != nullptr )
  {
    m_nValue = mat_lpreview_mode.m_pParent->m_Value.m_nValue;
    if ( m_nValue == -1 )
      goto LABEL_10;
  }
  else
  {
    m_nValue = 0;
  }
  (*(void (__thiscall **)(int, _DWORD, int))(*(_DWORD *)v9 + 464))(a1: v9, a2: 0, a3: m_nValue);
LABEL_10:
  (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 12))(a1: v9);
  (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 4))(a1: v9);
  if ( r_visocclusion.m_pParent != nullptr )
    v11 = r_visocclusion.m_pParent->m_Value.m_nValue;
  else
    v11 = 0;
  bVisOcclusion = v11 != 0;
  ConVar::SetValue(this: (ConVar *)&r_visocclusion.IConVar, value: 0);
  CBaseWorldView::DrawSetup(
    this,
    a2: v3,
    a3: (int)this,
    a4: v9,
    pRenderContext: (IMatRenderContext *)v3,
    waterHeight: *((float *)this - 3),
    nSetupFlags: this->m_DrawFlags,
    waterZAdjust: 0.0,
    iForceViewLeaf: *((_DWORD *)this - 6));
  v12 = materials->GetRenderContext(this: materials);
  if ( v12 != nullptr )
    v12->BeginRender(this: v12);
  v13 = nullptr;
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
    v13 = LocalPlayer->GetFogParams(this: LocalPlayer);
  if ( cl_leveloverview.m_pParent != nullptr && cl_leveloverview.m_pParent->m_Value.m_nValue != 0 )
    goto LABEL_24;
  ClientMode = GetClientMode();
  if ( !ClientMode->ShouldDrawFog(this: ClientMode) )
    goto LABEL_24;
  if ( fog_override.m_pParent == nullptr || fog_override.m_pParent->m_Value.m_nValue == 0 )
  {
    if ( v13 == nullptr || !v13->enable.m_Value )
      goto LABEL_24;
LABEL_28:
    GetFogColor(pFogParams: v13, pColor, ignoreOverride: false, ignoreHDRColorScale: false);
    v12->FogMode(this: v12, a2: MATERIAL_FOG_LINEAR);
    v12->FogColor3fv(this: v12, a2: pColor);
    if ( v13 == nullptr )
    {
      m_fValue = 0.0;
      goto LABEL_34;
    }
    if ( fog_override.m_pParent != nullptr && fog_override.m_pParent->m_Value.m_nValue != 0 )
    {
      m_fValue = fog_start.m_pParent->m_Value.m_fValue;
      if ( m_fValue != -1.0 )
        goto LABEL_34;
    }
    else
    {
      m_Value = v13->lerptime.m_Value;
      v19 = *(float *)(gpGlobals.m_Index + 12);
      if ( m_Value > v19 )
      {
        v20 = v13->start.m_Value;
        v21 = v13->startLerpTo.m_Value;
        if ( v20 != v21 )
        {
          m_fValue = (float)((float)(1.0 - (float)((float)(m_Value - v19) / v13->duration.m_Value)) * (float)(v21 - v20))
                   + v20;
LABEL_34:
          v12->FogStart(this: v12, a2: COERCE_FLOAT(LODWORD(m_fValue)));
          if ( v13 == nullptr )
          {
            v17 = 0.0;
            goto LABEL_43;
          }
          if ( fog_override.m_pParent != nullptr && fog_override.m_pParent->m_Value.m_nValue != 0 )
          {
            v17 = fog_end.m_pParent->m_Value.m_fValue;
            if ( v17 != -1.0 )
              goto LABEL_43;
          }
          else
          {
            v22 = v13->lerptime.m_Value;
            v23 = *(float *)(gpGlobals.m_Index + 12);
            if ( v22 > v23 )
            {
              v24 = v13->end.m_Value;
              v25 = v13->endLerpTo.m_Value;
              if ( v24 != v25 )
              {
                v17 = (float)((float)(1.0 - (float)((float)(v22 - v23) / v13->duration.m_Value)) * (float)(v25 - v24))
                    + v24;
LABEL_43:
                v12->FogEnd(this: v12, a2: COERCE_FLOAT(LODWORD(v17)));
                if ( v13 == nullptr
                  || cl_leveloverview.m_pParent != nullptr && cl_leveloverview.m_pParent->m_Value.m_nValue != 0
                  || (v26 = GetClientMode(), !v26->ShouldDrawFog(this: v26)) )
                {
                  ((void (__thiscall *)(IMatRenderContext *, int))v12->FogMaxDensity)(a1: v12, a2: 1065353216);
                  goto LABEL_25;
                }
                if ( fog_override.m_pParent != nullptr && fog_override.m_pParent->m_Value.m_nValue != 0 )
                {
                  v27 = fog_maxdensity.m_pParent->m_Value.m_fValue;
                  if ( v27 != -1.0 )
                  {
LABEL_55:
                    v12->FogMaxDensity(this: v12, a2: COERCE_FLOAT(LODWORD(v27)));
                    goto LABEL_25;
                  }
                }
                else
                {
                  v28 = v13->lerptime.m_Value;
                  v29 = *(float *)(gpGlobals.m_Index + 12);
                  if ( v28 > v29 )
                  {
                    v30 = v13->maxdensity.m_Value;
                    v31 = v13->maxdensityLerpTo.m_Value;
                    if ( v30 != v31 )
                    {
                      ((void (__thiscall *)(IMatRenderContext *, _DWORD))v12->FogMaxDensity)(
                        a1: v12,
                        a2: (float)((float)(1.0 - (float)((float)(v28 - v29) / v13->duration.m_Value)) * (float)(v31 - v30))
                      + v30);
                      goto LABEL_25;
                    }
                  }
                }
                v27 = v13->maxdensity.m_Value;
                goto LABEL_55;
              }
            }
          }
          v17 = v13->end.m_Value;
          goto LABEL_43;
        }
      }
    }
    m_fValue = v13->start.m_Value;
    goto LABEL_34;
  }
  if ( fog_enable.m_pParent != nullptr && fog_enable.m_pParent->m_Value.m_nValue != 0 )
    goto LABEL_28;
LABEL_24:
  v12->FogMode(this: v12, a2: MATERIAL_FOG_NONE);
LABEL_25:
  v12->EndRender(this: v12);
  v12->Release(this: v12);
  (*(void (__thiscall **)(char *, _DWORD, _DWORD, _DWORD, int))(*(_DWORD *)v3 + 296))(
    a1: v3,
    a2: 0,
    a3: 0,
    a4: 0,
    a5: 255);
  CBaseWorldView::DrawExecute(
    this: v36,
    waterHeight: *(float *)&v36[-1].m_pRenderablesList,
    viewID: (CUtlVector<CClientRenderablesList::CEntry *,CUtlMemory<CClientRenderablesList::CEntry *,int> > *)3,
    waterZAdjust: 0.0);
  ConVar::SetValue(this: (ConVar *)&r_visocclusion.IConVar, value: bVisOcclusion);
  SetupCurrentView(
    a1: (int)v13,
    a2: (int)v12,
    vecOrigin: &vecOldOrigin,
    angles: &vecOldAngles,
    viewID: (view_id_t)nSaveViewID,
    bDrawWorldNormal: false,
    bCullFrontFaces: false);
  (*(void (__thiscall **)(char *, _DWORD))(*(_DWORD *)v3 + 16))(a1: v3, a2: 0);
  (*(void (__thiscall **)(char *))(*(_DWORD *)v3 + 12))(a1: v3);
  (*(void (__thiscall **)(char *))(*(_DWORD *)v3 + 4))(a1: v3);
}

//------------------------------------------------------------------------------
// Address: 0x101A6CD0
// Name: public: virtual void CAboveWaterView::CRefractionView::Draw(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAboveWaterView::CRefractionView::Draw(CAboveWaterView::CRefractionView *this)
{
  IMatRenderContext *v2; // edi
  float x; // xmm0_4
  float z; // xmm0_4
  float v5; // xmm0_4
  void (__thiscall *GetScreenFadeDistances)(IViewRender *, float *, float *); // eax
  IMatRenderContext *v7; // eax
  const char *v8; // ebx
  int m_nValue; // eax
  Vector vecOldOrigin; // [esp+40h] [ebp-24h] BYREF
  QAngle vecOldAngles; // [esp+4Ch] [ebp-18h] BYREF
  int nSaveViewID; // [esp+58h] [ebp-Ch]
  int v13; // [esp+5Ch] [ebp-8h] BYREF
  int v14; // [esp+60h] [ebp-4h] BYREF

  v2 = materials->GetRenderContext(this: materials);
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  *(_QWORD *)&vecOldOrigin.x = *(_QWORD *)&g_vecCurrentRenderOrigin.x;
  *(_QWORD *)&vecOldAngles.x = *(_QWORD *)&g_vecCurrentRenderAngles.x;
  x = this->origin.CBaseWorldView::CRendering3dView::CBase3dView::CViewSetup::x;
  vecOldOrigin.z = g_vecCurrentRenderOrigin.z;
  g_vecCurrentRenderOrigin.x = x;
  g_vecCurrentRenderOrigin.y = this->origin.y;
  z = this->origin.z;
  nSaveViewID = g_CurrentViewID;
  g_vecCurrentRenderOrigin.z = z;
  g_vecCurrentRenderAngles.x = this->angles.CBaseWorldView::CRendering3dView::CBase3dView::CViewSetup::x;
  g_vecCurrentRenderAngles.y = this->angles.y;
  v5 = this->angles.z;
  vecOldAngles.z = g_vecCurrentRenderAngles.z;
  g_vecCurrentRenderAngles.z = v5;
  ComputeCameraVariables(
    vecOrigin: &this->origin,
    vecAngles: &this->angles,
    pVecForward: &g_vecCurrentVForward,
    pVecRight: &g_vecCurrentVRight,
    pVecUp: &g_vecCurrentVUp,
    pMatCamInverse: &g_matCurrentCamInverse);
  s_bCanAccessCurrentView = true;
  GetScreenFadeDistances = view->GetScreenFadeDistances;
  g_CurrentViewID = VIEW_REFRACTION;
  GetScreenFadeDistances(this: view, a2: (float *)&v13, a3: (float *)&v14);
  ((void (__thiscall *)(IVModelInfoClient *, int, int))modelinfo->SetViewScreenFadeRange)(
    a1: modelinfo,
    a2: v13,
    a3: v14);
  v7 = materials->GetRenderContext(this: materials);
  v8 = (const char *)v7;
  if ( v7 != nullptr )
    v7->BeginRender(this: v7);
  (*(void (__thiscall **)(const char *, int, _DWORD))(*(_DWORD *)v8 + 464))(a1: v8, a2: 10, a3: 0);
  if ( mat_lpreview_mode.m_pParent == nullptr )
  {
    m_nValue = 0;
LABEL_9:
    (*(void (__thiscall **)(const char *, _DWORD, int))(*(_DWORD *)v8 + 464))(a1: v8, a2: 0, a3: m_nValue);
    goto LABEL_10;
  }
  m_nValue = mat_lpreview_mode.m_pParent->m_Value.m_nValue;
  if ( m_nValue != -1 )
    goto LABEL_9;
LABEL_10:
  (*(void (__thiscall **)(const char *))(*(_DWORD *)v8 + 12))(a1: v8);
  (*(void (__thiscall **)(const char *))(*(_DWORD *)v8 + 4))(a1: v8);
  CBaseWorldView::DrawSetup(
    this,
    a2: v8,
    a3: (int)v2,
    a4: (int)this,
    pRenderContext: v2,
    waterHeight: *((float *)this - 82),
    nSetupFlags: this->m_DrawFlags,
    waterZAdjust: *((float *)this - 81),
    iForceViewLeaf: -1);
  render->SetFogVolumeState(this: render, a2: *((_DWORD *)this - 79), a3: true);
  SetClearColorToFogColor();
  CBaseWorldView::DrawExecute(
    this,
    waterHeight: *((float *)this - 82),
    viewID: (CUtlVector<CClientRenderablesList::CEntry *,CUtlMemory<CClientRenderablesList::CEntry *,int> > *)4,
    waterZAdjust: *((float *)this - 81));
  SetupCurrentView(
    a1: (int)v2,
    a2: (int)this,
    vecOrigin: &vecOldOrigin,
    angles: &vecOldAngles,
    viewID: (view_id_t)nSaveViewID,
    bDrawWorldNormal: false,
    bCullFrontFaces: false);
  v2->ClearColor4ub(this: v2, a2: 0, a3: 0, a4: 0, a5: 255u);
  v2->Flush(this: v2, a2: false);
  v2->EndRender(this: v2);
  v2->Release(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x101A6F20
// Name: public: virtual void CAboveWaterView::CIntersectionView::Draw(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAboveWaterView::CIntersectionView::Draw(
        CAboveWaterView::CIntersectionView *this@<ecx>,
        const char *a2@<ebx>)
{
  IMatRenderContext *v3; // esi

  v3 = materials->GetRenderContext(this: materials);
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  CBaseWorldView::DrawSetup(
    this,
    a2,
    a3: (int)this,
    a4: (int)v3,
    pRenderContext: v3,
    waterHeight: *((float *)this - 147),
    nSetupFlags: this->m_DrawFlags,
    waterZAdjust: 0.0,
    iForceViewLeaf: -1);
  render->SetFogVolumeState(this: render, a2: *((_DWORD *)this - 151), a3: true);
  SetClearColorToFogColor();
  CBaseWorldView::DrawExecute(
    this,
    waterHeight: *((float *)this - 147),
    viewID: (CUtlVector<CClientRenderablesList::CEntry *,CUtlMemory<CClientRenderablesList::CEntry *,int> > *)0xFFFFFFFF,
    waterZAdjust: 0.0);
  v3->ClearColor4ub(this: v3, a2: 0, a3: 0, a4: 0, a5: 255u);
  v3->EndRender(this: v3);
  v3->Release(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x101A6FE0
// Name: public: virtual void CUnderWaterView::Draw(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall CUnderWaterView::Draw(CUnderWaterView *this@<ecx>, const char *a2@<ebx>)
{
  IMatRenderContext *v3; // edi
  CViewSetup *v4; // eax
  bool v5; // zf
  float m_waterZAdjust; // xmm0_4
  CViewSetup *v7; // eax
  unsigned __int8 ucFogColor[8]; // [esp+3Ch] [ebp-8h] OVERLAPPED BYREF

  v3 = materials->GetRenderContext(this: materials);
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  if ( (*(_BYTE *)&this->m_waterInfo & 4) == 0 )
    goto LABEL_10;
  if ( this != nullptr )
    v4 = &this->CViewSetup;
  else
    v4 = nullptr;
  CRendering3dView::Setup(this: &this->m_RefractionView, setup: v4);
  v5 = !this->m_bDrawSkybox;
  this->m_RefractionView.m_DrawFlags = 8236;
  this->m_RefractionView.m_ClearFlags = 2;
  if ( !v5 )
  {
    this->m_RefractionView.m_ClearFlags = 3;
    this->m_RefractionView.m_DrawFlags = 272428;
  }
  this->m_pMainView->m_SimpleExecutor.AddView(this: &this->m_pMainView->m_SimpleExecutor, a2: &this->m_RefractionView);
  if ( (*(_BYTE *)&this->m_waterInfo & 4) == 0 )
  {
LABEL_10:
    render->SetFogVolumeState(this: render, a2: this->m_fogInfo.m_nVisibleFogVolume, a3: true);
    v3->GetFogColor(this: v3, a2: ucFogColor);
    v3->ClearColor4ub(
      this: v3,
      a2: *(_DWORD *)ucFogColor,
      a3: *(_DWORD *)&ucFogColor[1],
      a4: *(_DWORD *)&ucFogColor[2],
      a5: 255u);
  }
  CBaseWorldView::DrawSetup(
    this,
    a2,
    a3: (int)v3,
    a4: (int)this,
    pRenderContext: v3,
    waterHeight: this->m_waterHeight,
    nSetupFlags: this->m_DrawFlags,
    waterZAdjust: this->m_waterZAdjust,
    iForceViewLeaf: -1);
  render->SetFogVolumeState(this: render, a2: this->m_fogInfo.m_nVisibleFogVolume, a3: false);
  CBaseWorldView::DrawExecute(
    this,
    waterHeight: this->m_waterHeight,
    viewID: (CUtlVector<CClientRenderablesList::CEntry *,CUtlMemory<CClientRenderablesList::CEntry *,int> > *)g_CurrentViewID,
    waterZAdjust: this->m_waterZAdjust);
  m_waterZAdjust = this->m_waterZAdjust;
  this->m_ClearFlags = 0;
  if ( m_waterZAdjust != 0.0 && this->m_bSoftwareUserClipPlane && (*(_BYTE *)&this->m_waterInfo & 4) != 0 )
  {
    if ( this != nullptr )
      v7 = &this->CViewSetup;
    else
      v7 = nullptr;
    CRendering3dView::Setup(this: &this->m_SoftwareIntersectionView, setup: v7);
    this->m_SoftwareIntersectionView.m_DrawFlags = 32;
    this->m_SoftwareIntersectionView.Draw(this: &this->m_SoftwareIntersectionView);
  }
  v3->ClearColor4ub(this: v3, a2: 0, a3: 0, a4: 0, a5: 255u);
  v3->EndRender(this: v3);
  v3->Release(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x101A71D0
// Name: public: virtual void CUnderWaterView::CRefractionView::Draw(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall CUnderWaterView::CRefractionView::Draw(CUnderWaterView::CRefractionView *this@<ecx>, int a2@<esi>)
{
  IMatRenderContext *v3; // edi
  IMatRenderContext *v4; // eax
  IMatRenderContext *v5; // esi
  C_BasePlayer *LocalPlayer; // eax
  IClientMode *ClientMode; // eax
  int y; // edx
  int width; // eax
  int height; // ecx
  ITexture *WaterRefractionTexture; // eax
  fogparams_t *v12; // eax
  float m_fValue; // xmm0_4
  float v14; // xmm0_4
  float m_Value; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm3_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm3_4
  float v22; // xmm2_4
  IClientMode *v23; // eax
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm3_4
  float v28; // xmm2_4
  Rect_t srcRect; // [esp+3Ch] [ebp-28h] BYREF
  float pColor[3]; // [esp+4Ch] [ebp-18h] BYREF
  unsigned __int8 ucFogColor[8]; // [esp+58h] [ebp-Ch] OVERLAPPED BYREF
  fogparams_t *pFogParams; // [esp+60h] [ebp-4h]

  v3 = materials->GetRenderContext(this: materials);
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  render->SetFogVolumeState(this: render, a2: *((_DWORD *)this - 7), a3: true);
  v3->GetFogColor(this: v3, a2: ucFogColor);
  v3->ClearColor4ub(
    this: v3,
    a2: *(_DWORD *)ucFogColor,
    a3: *(_DWORD *)&ucFogColor[1],
    a4: *(_DWORD *)&ucFogColor[2],
    a5: 255u);
  CBaseWorldView::DrawSetup(
    this,
    a2: (const char *)this,
    a3: (int)v3,
    a4: a2,
    pRenderContext: v3,
    waterHeight: *((float *)this - 10),
    nSetupFlags: this->m_DrawFlags,
    waterZAdjust: *((float *)this - 9),
    iForceViewLeaf: -1);
  v4 = materials->GetRenderContext(this: materials);
  v5 = v4;
  if ( v4 != nullptr )
    v4->BeginRender(this: v4);
  pFogParams = nullptr;
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
    pFogParams = LocalPlayer->GetFogParams(this: LocalPlayer);
  if ( cl_leveloverview.m_pParent != nullptr && cl_leveloverview.m_pParent->m_Value.m_nValue != 0 )
    goto LABEL_14;
  ClientMode = GetClientMode();
  if ( !ClientMode->ShouldDrawFog(this: ClientMode) )
    goto LABEL_14;
  if ( fog_override.m_pParent != nullptr && fog_override.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( fog_enable.m_pParent == nullptr || fog_enable.m_pParent->m_Value.m_nValue == 0 )
    {
LABEL_14:
      v5->FogMode(this: v5, a2: MATERIAL_FOG_NONE);
      goto LABEL_15;
    }
    v12 = pFogParams;
  }
  else
  {
    v12 = pFogParams;
    if ( pFogParams == nullptr || !pFogParams->enable.m_Value )
      goto LABEL_14;
  }
  GetFogColor(pFogParams: v12, pColor, ignoreOverride: false, ignoreHDRColorScale: false);
  v5->FogMode(this: v5, a2: MATERIAL_FOG_LINEAR);
  v5->FogColor3fv(this: v5, a2: pColor);
  if ( pFogParams == nullptr )
  {
    m_fValue = 0.0;
    goto LABEL_26;
  }
  if ( fog_override.m_pParent != nullptr && fog_override.m_pParent->m_Value.m_nValue != 0 )
  {
    m_fValue = fog_start.m_pParent->m_Value.m_fValue;
    if ( m_fValue != -1.0 )
      goto LABEL_26;
    goto LABEL_25;
  }
  m_Value = pFogParams->lerptime.m_Value;
  v16 = *(float *)(gpGlobals.m_Index + 12);
  if ( m_Value <= v16 || (v17 = pFogParams->start.m_Value, v18 = pFogParams->startLerpTo.m_Value, v17 == v18) )
  {
LABEL_25:
    m_fValue = pFogParams->start.m_Value;
    goto LABEL_26;
  }
  m_fValue = (float)((float)(1.0 - (float)((float)(m_Value - v16) / pFogParams->duration.m_Value)) * (float)(v18 - v17))
           + v17;
LABEL_26:
  v5->FogStart(this: v5, a2: COERCE_FLOAT(LODWORD(m_fValue)));
  if ( pFogParams != nullptr )
  {
    if ( fog_override.m_pParent != nullptr && fog_override.m_pParent->m_Value.m_nValue != 0 )
    {
      v14 = fog_end.m_pParent->m_Value.m_fValue;
      if ( v14 != -1.0 )
        goto LABEL_35;
    }
    else
    {
      v19 = pFogParams->lerptime.m_Value;
      v20 = *(float *)(gpGlobals.m_Index + 12);
      if ( v19 > v20 )
      {
        v21 = pFogParams->end.m_Value;
        v22 = pFogParams->endLerpTo.m_Value;
        if ( v21 != v22 )
        {
          v14 = (float)((float)(1.0 - (float)((float)(v19 - v20) / pFogParams->duration.m_Value)) * (float)(v22 - v21))
              + v21;
          goto LABEL_35;
        }
      }
    }
    v14 = pFogParams->end.m_Value;
    goto LABEL_35;
  }
  v14 = 0.0;
LABEL_35:
  v5->FogEnd(this: v5, a2: COERCE_FLOAT(LODWORD(v14)));
  if ( pFogParams != nullptr
    && (cl_leveloverview.m_pParent == nullptr || cl_leveloverview.m_pParent->m_Value.m_nValue == 0) )
  {
    v23 = GetClientMode();
    if ( v23->ShouldDrawFog(this: v23) )
    {
      if ( fog_override.m_pParent != nullptr && fog_override.m_pParent->m_Value.m_nValue != 0 )
      {
        v24 = fog_maxdensity.m_pParent->m_Value.m_fValue;
        if ( v24 == -1.0 )
        {
          ((void (__thiscall *)(IMatRenderContext *, _DWORD))v5->FogMaxDensity)(
            a1: v5,
            a2: LODWORD(pFogParams->maxdensity.m_Value));
          goto LABEL_15;
        }
      }
      else
      {
        v25 = pFogParams->lerptime.m_Value;
        v26 = *(float *)(gpGlobals.m_Index + 12);
        if ( v25 > v26 )
        {
          v27 = pFogParams->maxdensity.m_Value;
          v28 = pFogParams->maxdensityLerpTo.m_Value;
          if ( v27 != v28 )
          {
            ((void (__thiscall *)(IMatRenderContext *, _DWORD))v5->FogMaxDensity)(
              a1: v5,
              a2: (float)((float)(1.0 - (float)((float)(v25 - v26) / pFogParams->duration.m_Value)) * (float)(v28 - v27))
            + v27);
            goto LABEL_15;
          }
        }
        v24 = pFogParams->maxdensity.m_Value;
      }
      v5->FogMaxDensity(this: v5, a2: COERCE_FLOAT(LODWORD(v24)));
      goto LABEL_15;
    }
  }
  ((void (__thiscall *)(IMatRenderContext *, int))v5->FogMaxDensity)(a1: v5, a2: 1065353216);
LABEL_15:
  v5->EndRender(this: v5);
  v5->Release(this: v5);
  CBaseWorldView::DrawExecute(
    this,
    waterHeight: *((float *)this - 10),
    viewID: (CUtlVector<CClientRenderablesList::CEntry *,CUtlMemory<CClientRenderablesList::CEntry *,int> > *)4,
    waterZAdjust: *((float *)this - 9));
  y = this->y;
  width = this->width;
  srcRect.x = this->x;
  height = this->height;
  srcRect.y = y;
  srcRect.width = width;
  srcRect.height = height;
  WaterRefractionTexture = GetWaterRefractionTexture();
  v3->CopyRenderTargetToTextureEx(this: v3, a2: WaterRefractionTexture, a3: 0, a4: &srcRect, a5: nullptr);
  v3->EndRender(this: v3);
  v3->Release(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x101A75F0
// Name: public: virtual void CReflectiveGlassView::Draw(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CReflectiveGlassView::Draw(CReflectiveGlassView *this)
{
  IMatRenderContext *v2; // esi
  int m_nValue; // edi

  v2 = materials->GetRenderContext(this: materials);
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  if ( r_visocclusion.m_pParent != nullptr )
    m_nValue = r_visocclusion.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  ConVar::SetValue(this: (ConVar *)&r_visocclusion.IConVar, value: 0);
  CSimpleWorldView::Draw(this);
  ConVar::SetValue(this: (ConVar *)&r_visocclusion.IConVar, value: m_nValue != 0);
  v2->ClearColor4ub(this: v2, a2: 0, a3: 0, a4: 0, a5: 255u);
  v2->Flush(this: v2, a2: false);
  v2->EndRender(this: v2);
  v2->Release(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x101A7680
// Name: public: virtual void CRefractiveGlassView::Draw(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRefractiveGlassView::Draw(CRefractiveGlassView *this)
{
  IMatRenderContext *v2; // esi

  v2 = materials->GetRenderContext(this: materials);
  if ( v2 != nullptr )
    v2->BeginRender(this: v2);
  CSimpleWorldView::Draw(this);
  v2->ClearColor4ub(this: v2, a2: 0, a3: 0, a4: 0, a5: 255u);
  v2->Flush(this: v2, a2: false);
  v2->EndRender(this: v2);
  v2->Release(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x101A76E0
// Name: protected: void CViewRender::DrawViewModels(class CViewSetup const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CViewRender::DrawViewModels(
        CViewRender *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        const CViewSetup *view,
        bool drawViewmodel)
{
  bool v5; // al
  IMatRenderContext *v6; // eax
  IMatRenderContext *v7; // ebx
  void (__thiscall *BeginLock)(IMDLCache *); // eax
  float zNearViewmodel; // xmm0_4
  int height; // esi
  int width; // eax
  CViewRender *v12; // edi
  VPlane *v13; // eax
  int v14; // esi
  IClientRenderable *m_pRenderable; // edi
  int v16; // eax
  bool v17; // al
  int m_Size; // ecx
  CViewModelRenderablesList::CEntry *m_pMemory; // eax
  int v21; // esi
  IClientRenderable *v22; // edi
  int v23; // eax
  bool v24; // al
  bool v25; // zf
  int v26; // ecx
  CViewModelRenderablesList::CEntry *v27; // eax
  IVRenderView_vtbl *v28; // esi
  int v29; // eax
  VPlane *(__thiscall *GetFrustum)(struct CViewRender *); // eax
  IVRenderView_vtbl *v31; // esi
  int v32; // eax
  IVRenderView_vtbl *v33; // esi
  int v34; // eax
  CViewSetup viewModelSetup; // [esp+6Ch] [ebp-560h] BYREF
  CViewModelRenderablesList listNormalFOV; // [esp+160h] [ebp-46Ch] BYREF
  CViewModelRenderablesList list; // [esp+390h] [ebp-23Ch] BYREF
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+5C0h] [ebp-Ch]
  CViewRender *v39; // [esp+5C4h] [ebp-8h]
  bool bShouldDrawPlayerViewModel; // [esp+5CAh] [ebp-2h]
  bool bShouldDrawToolViewModels; // [esp+5CBh] [ebp-1h]
  char bUpdatedRefractForOpaque_3; // [esp+5D7h] [ebp+Bh]
  IVRenderView_vtbl *drawViewmodela; // [esp+5D8h] [ebp+Ch]
  bool drawViewmodel_3; // [esp+5DBh] [ebp+Fh]
  char drawViewmodel_3a; // [esp+5DBh] [ebp+Fh]

  v39 = this;
  bShouldDrawPlayerViewModel = CViewRender::ShouldDrawViewModel(this, bDrawViewmodel: drawViewmodel);
  v5 = ToolsEnabled();
  bShouldDrawToolViewModels = v5;
  if ( !bShouldDrawPlayerViewModel && !v5 )
    return;
  v6 = materials->GetRenderContext(this: materials);
  v7 = v6;
  if ( v6 != nullptr )
    v6->BeginRender(this: v6);
  BeginLock = mdlcache->BeginLock;
  cacheCriticalSection.m_pCache = mdlcache;
  ((void (__stdcall *)(int, int))BeginLock)(a1: a2, a2: a3);
  v7->MatrixMode(this: v7, a2: MATERIAL_PROJECTION);
  v7->PushMatrix(this: v7);
  zNearViewmodel = view->zNearViewmodel;
  viewModelSetup = *view;
  height = view->height;
  viewModelSetup.zNear = zNearViewmodel;
  viewModelSetup.zFar = view->zFarViewmodel;
  width = view->width;
  viewModelSetup.fov = view->fovViewmodel;
  viewModelSetup.m_flAspectRatio = engine->GetScreenAspectRatio(this: engine, a2: width, a3: height);
  v12 = v39;
  drawViewmodela = render->__vftable;
  v13 = v39->GetFrustum(this: v39);
  drawViewmodela->Push3DView_2(this: render, a2: v7, a3: &viewModelSetup, a4: 0, a5: nullptr, a6: v13);
  ((void (__thiscall *)(IMatRenderContext *, _DWORD, int))v7->DepthRange)(a1: v7, a2: 0, a3: 1036831949);
  list.m_RenderGroups[0].m_Memory.m_pMemory = list.m_RenderGroups[0].m_Memory.m_pFixedMemory;
  list.m_RenderGroups[0].m_pElements = list.m_RenderGroups[0].m_Memory.m_pFixedMemory;
  list.m_RenderGroups[0].m_Memory.m_nGrowSize = -1;
  list.m_RenderGroups[1].m_Memory.m_nGrowSize = -1;
  list.m_RenderGroups[0].m_Memory.m_nAllocationCount = 32;
  list.m_RenderGroups[0].m_Memory.m_nMallocGrowSize = 0;
  list.m_RenderGroups[0].m_Size = 0;
  list.m_RenderGroups[1].m_Memory.m_pMemory = list.m_RenderGroups[1].m_Memory.m_pFixedMemory;
  list.m_RenderGroups[1].m_Memory.m_nAllocationCount = 32;
  list.m_RenderGroups[1].m_Memory.m_nMallocGrowSize = 0;
  list.m_RenderGroups[1].m_Size = 0;
  list.m_RenderGroups[1].m_pElements = list.m_RenderGroups[1].m_Memory.m_pFixedMemory;
  g_pClientLeafSystem->CollateViewModelRenderables(this: g_pClientLeafSystem, a2: &list);
  listNormalFOV.m_RenderGroups[0].m_Memory.m_pMemory = listNormalFOV.m_RenderGroups[0].m_Memory.m_pFixedMemory;
  listNormalFOV.m_RenderGroups[0].m_pElements = listNormalFOV.m_RenderGroups[0].m_Memory.m_pFixedMemory;
  listNormalFOV.m_RenderGroups[0].m_Memory.m_nGrowSize = -1;
  listNormalFOV.m_RenderGroups[1].m_Memory.m_nGrowSize = -1;
  listNormalFOV.m_RenderGroups[0].m_Memory.m_nAllocationCount = 32;
  listNormalFOV.m_RenderGroups[0].m_Memory.m_nMallocGrowSize = 0;
  listNormalFOV.m_RenderGroups[0].m_Size = 0;
  listNormalFOV.m_RenderGroups[1].m_Memory.m_pMemory = listNormalFOV.m_RenderGroups[1].m_Memory.m_pFixedMemory;
  listNormalFOV.m_RenderGroups[1].m_Memory.m_nAllocationCount = 32;
  listNormalFOV.m_RenderGroups[1].m_Memory.m_nMallocGrowSize = 0;
  listNormalFOV.m_RenderGroups[1].m_Size = 0;
  listNormalFOV.m_RenderGroups[1].m_pElements = listNormalFOV.m_RenderGroups[1].m_Memory.m_pFixedMemory;
  drawViewmodel_3 = ToolsEnabled() && (!bShouldDrawPlayerViewModel || !bShouldDrawToolViewModels);
  v14 = list.m_RenderGroups[0].m_Size - 1;
  if ( list.m_RenderGroups[0].m_Size - 1 >= 0 )
  {
    while ( 1 )
    {
      m_pRenderable = list.m_RenderGroups[0].m_Memory.m_pMemory[v14].m_pRenderable;
      v16 = m_pRenderable->GetIClientUnknown(this: m_pRenderable);
      v17 = (*(int (__thiscall **)(int))(*(_DWORD *)v16 + 28))(a1: v16) != 0;
      if ( drawViewmodel_3 && (v17 ? !bShouldDrawPlayerViewModel : !bShouldDrawToolViewModels) )
        goto LABEL_18;
      if ( __RTDynamicCast(
             inptr: m_pRenderable,
             VfDelta: 0,
             SrcType: &IClientRenderable `RTTI Type Descriptor',
             TargetType: &C_BaseViewModel `RTTI Type Descriptor',
             isReference: 0) == nullptr )
        break;
LABEL_22:
      if ( --v14 < 0 )
      {
        v12 = v39;
        goto LABEL_24;
      }
    }
    CUtlVector<CViewModelRenderablesList::CEntry,CUtlMemoryFixedGrowable<CViewModelRenderablesList::CEntry,32,int>>::InsertBefore(
      this: (CUtlVector<CViewModelRenderablesList::CEntry,CUtlMemoryFixedGrowable<CViewModelRenderablesList::CEntry,32,int> > *)&listNormalFOV,
      elem: listNormalFOV.m_RenderGroups[0].m_Size,
      src: &list.m_RenderGroups[0].m_Memory.m_pMemory[v14]);
LABEL_18:
    m_Size = list.m_RenderGroups[0].m_Size;
    if ( list.m_RenderGroups[0].m_Size > 0 )
    {
      if ( v14 != list.m_RenderGroups[0].m_Size - 1 )
      {
        m_pMemory = list.m_RenderGroups[0].m_Memory.m_pMemory;
        list.m_RenderGroups[0].m_Memory.m_pMemory[v14].m_pRenderable = list.m_RenderGroups[0].m_Memory.m_pMemory[list.m_RenderGroups[0].m_Size - 1].m_pRenderable;
        *(_DWORD *)&list.m_RenderGroups[0].m_Memory.m_pMemory[v14].m_InstanceData.m_nAlpha = *(_DWORD *)&m_pMemory[m_Size - 1].m_InstanceData.m_nAlpha;
        m_Size = list.m_RenderGroups[0].m_Size;
      }
      list.m_RenderGroups[0].m_Size = m_Size - 1;
    }
    goto LABEL_22;
  }
LABEL_24:
  v21 = list.m_RenderGroups[1].m_Size - 1;
  if ( list.m_RenderGroups[1].m_Size - 1 < 0 )
    goto LABEL_38;
  do
  {
    v22 = list.m_RenderGroups[1].m_Memory.m_pMemory[v21].m_pRenderable;
    v23 = v22->GetIClientUnknown(this: v22);
    v24 = (*(int (__thiscall **)(int))(*(_DWORD *)v23 + 28))(a1: v23) != 0;
    if ( !drawViewmodel_3 || (!v24 ? (v25 = !bShouldDrawToolViewModels) : (v25 = !bShouldDrawPlayerViewModel), !v25) )
    {
      if ( __RTDynamicCast(
             inptr: v22,
             VfDelta: 0,
             SrcType: &IClientRenderable `RTTI Type Descriptor',
             TargetType: &C_BaseViewModel `RTTI Type Descriptor',
             isReference: 0) != nullptr )
        goto LABEL_36;
      CUtlVector<CViewModelRenderablesList::CEntry,CUtlMemoryFixedGrowable<CViewModelRenderablesList::CEntry,32,int>>::InsertBefore(
        this: &listNormalFOV.m_RenderGroups[1],
        elem: listNormalFOV.m_RenderGroups[1].m_Size,
        src: &list.m_RenderGroups[1].m_Memory.m_pMemory[v21]);
    }
    v26 = list.m_RenderGroups[1].m_Size;
    if ( list.m_RenderGroups[1].m_Size > 0 )
    {
      if ( v21 != list.m_RenderGroups[1].m_Size - 1 )
      {
        v27 = list.m_RenderGroups[1].m_Memory.m_pMemory;
        list.m_RenderGroups[1].m_Memory.m_pMemory[v21].m_pRenderable = list.m_RenderGroups[1].m_Memory.m_pMemory[list.m_RenderGroups[1].m_Size - 1].m_pRenderable;
        *(_DWORD *)&list.m_RenderGroups[1].m_Memory.m_pMemory[v21].m_InstanceData.m_nAlpha = *(_DWORD *)&v27[v26 - 1].m_InstanceData.m_nAlpha;
        v26 = list.m_RenderGroups[1].m_Size;
      }
      list.m_RenderGroups[1].m_Size = v26 - 1;
    }
LABEL_36:
    --v21;
  }
  while ( v21 >= 0 );
  v12 = v39;
LABEL_38:
  drawViewmodel_3a = CViewRender::UpdateRefractIfNeededByList(this: v12, list: list.m_RenderGroups);
  CViewRender::DrawRenderablesInList(this: v12, renderGroups: list.m_RenderGroups, flags: 0);
  if ( drawViewmodel_3a == 0 )
    CViewRender::UpdateRefractIfNeededByList(this: v12, list: &list.m_RenderGroups[1]);
  CViewRender::DrawRenderablesInList(this: v12, renderGroups: &list.m_RenderGroups[1], flags: 0x80000000);
  ((void (__thiscall *)(IMatRenderContext *, _DWORD))v7->DepthRange)(a1: v7, a2: 0);
  v28 = render->__vftable;
  v29 = (int)v12->GetFrustum(this: v12);
  v28->PopView(this: render, a2: v7, a3: (VPlane *)v29);
  if ( listNormalFOV.m_RenderGroups[0].m_Size > 0 || listNormalFOV.m_RenderGroups[1].m_Size > 0 )
  {
    GetFrustum = v12->GetFrustum;
    viewModelSetup.fov = view->fov;
    v31 = render->__vftable;
    v32 = ((int (__thiscall *)(CViewRender *, int))GetFrustum)(a1: v12, a2: 1065353216);
    v31->Push3DView_2(this: render, a2: v7, a3: &viewModelSetup, a4: 0, a5: nullptr, a6: (VPlane *)v32);
    ((void (__thiscall *)(IMatRenderContext *, _DWORD, int))v7->DepthRange)(a1: v7, a2: 0, a3: 1036831949);
    bUpdatedRefractForOpaque_3 = CViewRender::UpdateRefractIfNeededByList(this: v12, list: listNormalFOV.m_RenderGroups);
    CViewRender::DrawRenderablesInList(this: v12, renderGroups: listNormalFOV.m_RenderGroups, flags: 0);
    if ( bUpdatedRefractForOpaque_3 == 0 )
      CViewRender::UpdateRefractIfNeededByList(this: v12, list: &listNormalFOV.m_RenderGroups[1]);
    CViewRender::DrawRenderablesInList(this: v12, renderGroups: &listNormalFOV.m_RenderGroups[1], flags: 0x80000000);
    ((void (__thiscall *)(IMatRenderContext *, _DWORD))v7->DepthRange)(a1: v7, a2: 0);
    v33 = render->__vftable;
    v34 = (int)v12->GetFrustum(this: v12);
    v33->PopView(this: render, a2: v7, a3: (VPlane *)v34);
  }
  v7->MatrixMode(this: v7, a2: MATERIAL_PROJECTION);
  v7->PopMatrix(this: v7);
  CViewModelRenderablesList::~CViewModelRenderablesList(this: &listNormalFOV);
  CViewModelRenderablesList::~CViewModelRenderablesList(this: &list);
  cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
  v7->EndRender(this: v7);
  v7->Release(this: v7);
}

//------------------------------------------------------------------------------
// Address: 0x101A7C50
// Name: public: virtual void CViewRender::RenderView(class CViewSetup const __near &,class CViewSetup const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CViewRender::RenderView(
        CViewRender *this@<ecx>,
        int a2@<esi>,
        CViewSetup *view,
        const CViewSetup *hudViewSetup,
        IVRenderView_vtbl *nClearFlags,
        unsigned int whatToDraw)
{
  CViewRender *v6; // edi
  const CViewSetup *v7; // ebx
  void (__thiscall *BeginLock)(IMDLCache *); // edx
  int i; // eax
  int v10; // esi
  C_BaseCombatWeapon *v11; // eax
  IClientNetworkable_vtbl *v12; // edx
  IMatRenderContext *v13; // esi
  bool v14; // zf
  CFreezeFrameView *v15; // eax
  CFreezeFrameView *v16; // esi
  void (__thiscall *RenderPreScene)(CViewRender *, const CViewSetup *); // edx
  CBase3dView *v18; // eax
  CSkyboxView *v19; // esi
  IMDLCache *v20; // esi
  IMDLCache *v21; // esi
  IMatRenderContext *v22; // eax
  const CViewSetup *v23; // esi
  IMatRenderContext *v24; // eax
  CViewEffects *ViewEffects; // eax
  IMatRenderContext *v26; // esi
  IMatRenderContext *v27; // esi
  int v28; // ecx
  int v29; // eax
  double v30; // st7
  C_BasePlayer *LocalPlayer; // eax
  int width; // eax
  C_BaseCombatWeapon *x; // edx
  int height; // esi
  IVEngineClient_vtbl *v35; // eax
  IClientMode *ClientMode; // eax
  IMatRenderContext *v37; // eax
  IMatRenderContext *v38; // esi
  ITexture *FullscreenTexture; // eax
  IMatRenderContext *v40; // eax
  IMatRenderContext *v41; // esi
  CViewRender *v42; // esi
  int m_OverlayDrawFlags; // ecx
  int m_OverlayClearFlags; // edx
  void (__thiscall *RenderView)(struct CViewRender *, const CViewSetup *, const CViewSetup *, int, int); // eax
  CViewRender *v46; // ecx
  IMatRenderContext *v47; // eax
  IMatRenderContext *v48; // esi
  int v49; // eax
  int y; // eax
  const CViewSetup *v51; // eax
  const CViewSetup *v52; // eax
  VPlane *(__thiscall *GetFrustum)(struct CViewRender *); // edx
  int v54; // eax
  const CViewSetup *v55; // esi
  int m_Size; // esi
  int v57; // eax
  int v58; // esi
  unsigned int *v59; // eax
  int v60; // esi
  unsigned int *v61; // eax
  IClientMode *v62; // eax
  VPlane *(__thiscall *v63)(struct CViewRender *); // edx
  int v64; // eax
  const CViewSetup *v65; // [esp+88h] [ebp-234h]
  int fovDegrees_4; // [esp+90h] [ebp-22Ch]
  int v67; // [esp+94h] [ebp-228h]
  CViewSetup currentView; // [esp+9Ch] [ebp-220h] BYREF
  CViewSetup tempView; // [esp+190h] [ebp-12Ch] BYREF
  ITexture *saveRenderTarget; // [esp+288h] [ebp-34h]
  CViewRender *v71; // [esp+28Ch] [ebp-30h]
  CViewSetup *blend; // [esp+290h] [ebp-2Ch] BYREF
  unsigned __int8 color[8]; // [esp+294h] [ebp-28h] BYREF
  SkyboxVisibility_t nSkyboxVisible; // [esp+29Ch] [ebp-20h] BYREF
  C_BaseCombatWeapon *bDrew3dSkybox; // [esp+2A0h] [ebp-1Ch]
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > vecHudPanels; // [esp+2A4h] [ebp-18h] BYREF
  C_BaseAnimating::AutoAllowBoneAccess boneaccess; // [esp+2BBh] [ebp-1h] BYREF
  int savedregs; // [esp+2BCh] [ebp+0h] BYREF

  v6 = this;
  v71 = this;
  CMaterialReference::Shutdown(this: &this->m_UnderWaterOverlayMaterial, bDeleteIfUnreferenced: false);
  v7 = view;
  CViewSetup::operator=(this: &v6->m_CurrentView, __that: view);
  C_BaseAnimating::AutoAllowBoneAccess::AutoAllowBoneAccess(
    this: &boneaccess,
    bAllowForNormalModels: true,
    bAllowForViewModels: true);
  if ( g_pMaterialSystemHardwareConfig->GetDXSupportLevel(this: g_pMaterialSystemHardwareConfig) >= 90 )
  {
    BeginLock = mdlcache->BeginLock;
    nSkyboxVisible = (SkyboxVisibility_t)mdlcache;
    ((void (__stdcall *)(int))BeginLock)(a1: a2);
    view = (CViewSetup *)C_BaseCombatWeapon::GetWeaponList();
    for ( i = LOWORD(view->height); i != 0xFFFF; i = *(unsigned __int16 *)(v10 + view->x + 6) )
    {
      v10 = 8 * (unsigned __int16)i;
      v11 = *(C_BaseCombatWeapon **)(v10 + view->x);
      v12 = v11->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable;
      bDrew3dSkybox = v11;
      if ( !v12->IsDormant(this: &v11->IClientNetworkable) )
        C_BaseCombatWeapon::EnsureCorrectRenderingModel(this: bDrew3dSkybox);
    }
    (*(void (__thiscall **)(SkyboxVisibility_t))(*(_DWORD *)nSkyboxVisible + 124))(a1: nSkyboxVisible);
    v13 = materials->GetRenderContext(this: materials);
    if ( v13 != nullptr )
      v13->BeginRender(this: v13);
    saveRenderTarget = v13->GetRenderTarget(this: v13);
    v13->EndRender(this: v13);
    v13->Release(this: v13);
    v14 = !v6->m_FreezeParams[0].m_bTakeFreezeFrame;
    view = nullptr;
    if ( v14 && v6->m_FreezeParams[0].m_flFreezeFrameUntil > *(float *)(gpGlobals.m_Index + 12) )
    {
      v15 = (CFreezeFrameView *)MemAlloc_Alloc(nSize: 0x140u);
      if ( v15 != nullptr )
        v16 = CFreezeFrameView::CFreezeFrameView(this: v15, pMainView: v6);
      else
        v16 = nullptr;
      CFreezeFrameView::Setup(this: v16, shadowViewIn: v7);
      v6->m_SimpleExecutor.AddView(this: &v6->m_SimpleExecutor, a2: v16);
      g_bRenderingView = true;
      s_bCanAccessCurrentView = true;
      if ( v16 != nullptr && _InterlockedDecrement(&v16->m_iRefs) == 0 && v16->OnFinalRelease(this: v16) )
        ((void (__thiscall *)(CFreezeFrameView *, int))v16->dtr_CRefCountServiceBase<1,CRefMT>)(a1: v16, a2: 1);
    }
    else
    {
      g_flFreezeFlash[0] = 0.0;
      if ( cl_drawmonitors.m_pParent != nullptr
        && cl_drawmonitors.m_pParent->m_Value.m_nValue != 0
        && (whatToDraw & 4) == 0 )
      {
        CViewRender::DrawMonitors(this: v6, cameraView: v7);
      }
      if ( materials->IsStereoSupported(this: materials) )
        materials->NVStereoUpdate(this: materials);
      RenderPreScene = v6->RenderPreScene;
      g_bRenderingView = true;
      RenderPreScene(this: v6, a2: v7);
      render->SceneBegin(this: render);
      CColorCorrectionMgr::UpdateColorCorrection(this: g_pColorCorrectionMgr);
      UpdateMaterialSystemTonemapScalar();
      CViewRender::SetupMain3DView(
        this: v6,
        a2: (int)v6,
        nSlot: 0,
        view: v7,
        hudViewSetup,
        (int *)&nClearFlags,
        pRenderTarget: saveRenderTarget);
      g_pClientShadowMgr->UpdateSplitscreenLocalPlayerShadowSkip(this: g_pClientShadowMgr);
      v14 = (*((_BYTE *)v7 + 240) & 0x20) == 0;
      LOBYTE(bDrew3dSkybox) = 0;
      nSkyboxVisible = SKYBOX_NOT_VISIBLE;
      if ( v14 )
      {
        v18 = (CBase3dView *)MemAlloc_Alloc(nSize: 0x124u);
        v19 = (CSkyboxView *)v18;
        if ( v18 != nullptr )
        {
          CBase3dView::CBase3dView(this: v18, pMainView: v6);
          v19->m_DrawFlags = 0;
          v19->m_ClearFlags = 0;
          v19->m_pWorldRenderList = nullptr;
          v19->m_pRenderablesList = nullptr;
          v19->m_pWorldListInfo = nullptr;
          v19->m_pCustomVisibility = nullptr;
          v19->__vftable = (CSkyboxView_vtbl *)&CSkyboxView::`vftable';
          v19->m_pSky3dParams = nullptr;
        }
        else
        {
          v19 = nullptr;
        }
        LOBYTE(bDrew3dSkybox) = CSkyboxView::Setup(
                                  this: v19,
                                  view: v7,
                                  pClearFlags: (int *)&nClearFlags,
                                  pSkyboxVisible: &nSkyboxVisible);
        if ( (_BYTE)bDrew3dSkybox != 0 )
          v6->m_SimpleExecutor.AddView(this: &v6->m_SimpleExecutor, a2: v19);
        if ( v19 != nullptr && _InterlockedDecrement(&v19->m_iRefs) == 0 && v19->OnFinalRelease(this: v19) )
          ((void (__thiscall *)(CSkyboxView *, int))v19->dtr_CRefCountServiceBase<1,CRefMT>)(a1: v19, a2: 1);
      }
      if ( ((unsigned __int8)nClearFlags & 1) == 0 )
      {
        v20 = mdlcache;
        mdlcache->BeginLock(this: mdlcache);
        if ( enginetrace->GetPointContents(this: enginetrace, a2: &v7->origin, a3: -1, a4: nullptr) == 1 )
          nClearFlags = (IVRenderView_vtbl *)((unsigned int)nClearFlags | 1);
        v20->EndLock(this: v20);
      }
      v6->PreViewDrawScene(this: v6, a2: v7);
      v21 = mdlcache;
      if ( g_pIntroData != nullptr )
      {
        mdlcache->BeginLock(this: mdlcache);
        v6->ViewDrawScene_Intro(this: v6, a2: v7, a3: (int)nClearFlags, a4: g_pIntroData);
      }
      else
      {
        mdlcache->BeginLock(this: mdlcache);
        CViewRender::ViewDrawScene(
          this: v6,
          (bool)bDrew3dSkybox,
          nSkyboxVisible,
          view: v7,
          (int)nClearFlags,
          viewID: VIEW_MAIN,
          bDrawViewModel: whatToDraw & 1,
          baseDrawFlags: 0,
          pCustomVisibility: nullptr);
      }
      v21->EndLock(this: v21);
      s_bCanAccessCurrentView = true;
      v6->PostViewDrawScene(this: v6, a2: v7);
      engine->DrawPortals(this: engine);
      v22 = materials->GetRenderContext(this: materials);
      v23 = (const CViewSetup *)v22;
      if ( v22 != nullptr )
        v22->BeginRender(this: v22);
      (*(void (__thiscall **)(const CViewSetup *, _DWORD))(v23->x + 176))(a1: v23, a2: 0);
      (*(void (__thiscall **)(const CViewSetup *))(v23->x + 12))(a1: v23);
      (*(void (__thiscall **)(const CViewSetup *))(v23->x + 4))(a1: v23);
      render->SceneEnd(this: render);
      render->DrawLights(this: render);
      v6->RenderPlayerSprites(this: v6);
      if ( building_cubemaps.m_pParent == nullptr || building_cubemaps.m_pParent->m_Value.m_nValue == 0 )
      {
        if ( IsDepthOfFieldEnabled() )
        {
          v24 = materials->GetRenderContext(this: materials);
          v23 = (const CViewSetup *)v24;
          if ( v24 != nullptr )
            v24->AddRef(this: v24);
          (*(void (__thiscall **)(const CViewSetup *))(v23->x + 8))(a1: v23);
          DoDepthOfField(a1: (int)v7, a2: (int)v6, a3: (int)v23, view: v7);
          (*(void (__thiscall **)(const CViewSetup *))(v23->x + 12))(a1: v23);
          (*(void (__thiscall **)(const CViewSetup *))(v23->x + 4))(a1: v23);
          view = nullptr;
        }
        if ( v7->m_nMotionBlurMode != MOTION_BLUR_DISABLE
          && mat_motion_blur_enabled.m_pParent != nullptr
          && mat_motion_blur_enabled.m_pParent->m_Value.m_nValue != 0
          && !v6->m_FreezeParams[0].m_bTakeFreezeFrame )
        {
          CMatRenderContextPtr::GetFrom(this: (CMatRenderContextPtr *)&view, pFrom: materials);
          DoImageSpaceMotionBlur(a1: (int)&savedregs, view: v7);
          v23 = view;
          if ( view != nullptr )
          {
            (*(void (__thiscall **)(CViewSetup *))(view->x + 12))(a1: view);
            (*(void (__thiscall **)(const CViewSetup *))(v23->x + 4))(a1: v23);
          }
        }
      }
      CViewRender::DrawViewModels(this: v6, a2: (int)v6, a3: (int)v23, view: v7, drawViewmodel: whatToDraw & 1);
      CViewRender::DrawUnderwaterOverlay(this: v6, a2: (int)v7, a3: (int)v6, a4: (int)v23);
      PixelVisibility_EndScene();
      ViewEffects = GetViewEffects();
      ViewEffects->GetFadeParams(
        this: ViewEffects,
        a2: color,
        a3: &color[1],
        a4: &color[2],
        a5: &color[3],
        a6: (bool *)&blend);
      SetViewFadeParams(r: color[0], g: color[1], b: color[2], a: color[3], bModulate: (bool)blend);
      DrawSmokeFogOverlay(a1: (int)v7, a2: (int)v6, a3: (int)v23);
      CViewRender::PerformScreenOverlay(this: v6, a2: (int)v6, x: v7->x, y: v7->y, w: v7->width, h: v7->height);
      engine->Sound_ExtraUpdate(this: engine);
      if ( g_pMaterialSystemHardwareConfig->GetHDRType(this: g_pMaterialSystemHardwareConfig) != HDR_TYPE_NONE )
      {
        v26 = materials->GetRenderContext(this: materials);
        if ( v26 != nullptr )
          v26->AddRef(this: v26);
        v26->BeginRender(this: v26);
        vecHudPanels.m_Memory.m_nGrowSize = 1065353216;
        vecHudPanels.m_Size = 1065353216;
        vecHudPanels.m_pElements = (unsigned int *)1065353216;
        v26->SetToneMappingScaleLinear(this: v26, a2: (const Vector *)&vecHudPanels.m_Memory.m_nGrowSize);
        v26->EndRender(this: v26);
        v26->Release(this: v26);
      }
      if ( (building_cubemaps.m_pParent == nullptr || building_cubemaps.m_pParent->m_Value.m_nValue == 0)
        && (*((_BYTE *)v7 + 240) & 4) != 0 )
      {
        v27 = materials->GetRenderContext(this: materials);
        if ( v27 != nullptr )
          v27->AddRef(this: v27);
        v27->BeginRender(this: v27);
        if ( !bAlreadyShowedLoadTime )
        {
          bAlreadyShowedLoadTime = true;
          v29 = _CommandLine(a1: v28);
          if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v29 + 12))(a1: v29, a2: "-timeload", a3: 0) != 0 )
          {
            v30 = _Plat_FloatTime(a1: v67);
            _Warning(a1: "time to initial render = %f\n", v30);
          }
        }
        LOBYTE(nClearFlags) = 0;
        LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
        if ( LocalPlayer != nullptr )
          LOBYTE(nClearFlags) = (LocalPlayer->m_fEffects & 4) != 0;
        DoEnginePostProcessing(
          a1: (int)v27,
          x: v7->x,
          y: v7->y,
          w: v7->width,
          h: v7->height,
          bFlashlightIsOn: (bool)nClearFlags,
          bPostVGui: false);
        v27->EndRender(this: v27);
        v27->Release(this: v27);
      }
      engine->GrabPreColorCorrectedFrame(this: engine, a2: v7->x, a3: v7->y, a4: v7->width, a5: v7->height);
      width = v7->width;
      x = (C_BaseCombatWeapon *)v7->x;
      height = v7->height;
      view = (CViewSetup *)v7->y;
      nClearFlags = (IVRenderView_vtbl *)width;
      v35 = engine->__vftable;
      bDrew3dSkybox = x;
      if ( !v35->IsHammerRunning(this: engine) )
        g_pScreenSpaceEffects->RenderEffects(
          this: g_pScreenSpaceEffects,
          a2: (int)bDrew3dSkybox,
          a3: (int)view,
          a4: (int)nClearFlags,
          a5: height);
      ClientMode = GetClientMode();
      ClientMode->DoPostScreenSpaceEffects(this: ClientMode, a2: v7);
      CViewRender::CleanupMain3DView(this: v6, view: v7);
      if ( v6->m_FreezeParams[0].m_bTakeFreezeFrame )
      {
        v37 = materials->GetRenderContext(this: materials);
        v38 = v37;
        if ( v37 != nullptr )
          v37->BeginRender(this: v37);
        nClearFlags = (IVRenderView_vtbl *)&v38->CopyRenderTargetToTextureEx;
        FullscreenTexture = GetFullscreenTexture();
        ((void (__thiscall *)(IMatRenderContext *, ITexture *, _DWORD, _DWORD, _DWORD))nClearFlags->DrawBrushModel)(
          a1: v38,
          a2: FullscreenTexture,
          a3: 0,
          a4: 0,
          a5: 0);
        v38->EndRender(this: v38);
        v38->Release(this: v38);
        v6->m_FreezeParams[0].m_bTakeFreezeFrame = false;
      }
      v40 = materials->GetRenderContext(this: materials);
      v41 = v40;
      if ( v40 != nullptr )
        v40->BeginRender(this: v40);
      v41->SetRenderTarget(this: v41, a2: saveRenderTarget);
      v41->EndRender(this: v41);
      v41->Release(this: v41);
      if ( v6->m_bDrawOverlay )
      {
        currentView = v6->m_CurrentView;
        tempView = v6->m_OverlayViewSetup;
        tempView.fov = ScaleFOVByWidthRatio(fovDegrees: tempView.fov, ratio: tempView.m_flAspectRatio * 0.75);
        v42 = v71;
        m_OverlayDrawFlags = v71->m_OverlayDrawFlags;
        m_OverlayClearFlags = v71->m_OverlayClearFlags;
        RenderView = v71->RenderView;
        *((_BYTE *)&tempView + 240) &= ~4u;
        fovDegrees_4 = m_OverlayDrawFlags;
        v65 = hudViewSetup;
        v46 = v71;
        tempView.m_nMotionBlurMode = MOTION_BLUR_DISABLE;
        v71->m_bDrawOverlay = false;
        RenderView(this: v46, a2: &tempView, a3: v65, a4: m_OverlayClearFlags, a5: fovDegrees_4);
        CViewSetup::operator=(this: &v42->m_CurrentView, __that: &currentView);
        v6 = v42;
      }
    }
    if ( VGui_IsSplitScreen() )
    {
      v47 = materials->GetRenderContext(this: materials);
      v48 = v47;
      if ( v47 != nullptr )
        v47->BeginRender(this: v47);
      v48->PushRenderTargetAndViewport_4(this: v48);
      g_pMaterialSystem->GetBackBufferDimensions(this: g_pMaterialSystem, a2: (int *)&nClearFlags, a3: (int *)&view);
      if ( v7->x != 0 )
      {
        v48->Viewport(this: v48, a2: v7->x, a3: v7->y, a4: 1, a5: v7->height);
        v48->ClearColor3ub(this: v48, a2: 0, a3: 0, a4: 0);
        v48->ClearBuffers(this: v48, a2: true, a3: false, a4: false);
      }
      v49 = v7->x + v7->width;
      if ( (IVRenderView_vtbl *)v49 != nClearFlags )
      {
        v48->Viewport(this: v48, a2: v49 - 1, a3: v7->y, a4: 1, a5: v7->height);
        v48->ClearColor3ub(this: v48, a2: 0, a3: 0, a4: 0);
        v48->ClearBuffers(this: v48, a2: true, a3: false, a4: false);
      }
      y = v7->y;
      if ( y != 0 )
      {
        v48->Viewport(this: v48, a2: v7->x, a3: y, a4: v7->width, a5: 1);
        v48->ClearColor3ub(this: v48, a2: 0, a3: 0, a4: 0);
        v48->ClearBuffers(this: v48, a2: true, a3: false, a4: false);
      }
      v51 = (const CViewSetup *)(v7->y + v7->height);
      if ( v51 != view )
      {
        v48->Viewport(this: v48, a2: v7->x, a3: (int)&v51[-1] + 243, a4: v7->width, a5: 1);
        v48->ClearColor3ub(this: v48, a2: 0, a3: 0, a4: 0);
        v48->ClearBuffers(this: v48, a2: true, a3: false, a4: false);
      }
      v48->PopRenderTargetAndViewport(this: v48);
      v48->Release(this: v48);
      v48->EndRender(this: v48);
      v48->Release(this: v48);
    }
    blend = &v6->m_CurrentView;
    CViewSetup::operator=(this: &v6->m_CurrentView, __that: hudViewSetup);
    v52 = (const CViewSetup *)materials->GetRenderContext(this: materials);
    view = (CViewSetup *)v52;
    if ( v52 != nullptr )
      (*(void (__thiscall **)(const CViewSetup *))(v52->x + 8))(a1: v52);
    GetFrustum = v6->GetFrustum;
    nClearFlags = render->__vftable;
    v54 = (int)GetFrustum(this: v6);
    v55 = view;
    nClearFlags->Push2DView(
      this: render,
      a2: (IMatRenderContext *)view,
      a3: hudViewSetup,
      a4: 0,
      a5: saveRenderTarget,
      a6: (VPlane *)v54);
    v6->Render2DEffectsPreHUD(this: v6, a2: hudViewSetup);
    if ( (whatToDraw & 2) != 0 )
    {
      CVProfile::EnterScope(
        this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
        a2: "VGui_DrawHud",
        a3: 0,
        a4: "VGUI",
        a5: false,
        a6: 4);
      VGui_PreRender(a1: 0);
      memset(&vecHudPanels, 0, sizeof(vecHudPanels));
      nClearFlags = (IVRenderView_vtbl *)VGui_GetClientDLLRootPanel();
      CUtlMemory<CChoreoActor *,int>::Grow(this: (CUtlMemory<vgui::TreeNode *,int> *)&vecHudPanels, num: 1);
      m_Size = vecHudPanels.m_Size + 1;
      vecHudPanels.m_pElements = vecHudPanels.m_Memory.m_pMemory;
      v57 = vecHudPanels.m_Size++;
      if ( v57 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)vecHudPanels.m_Memory.m_pMemory + 4,
          src: (unsigned __int8 *)vecHudPanels.m_Memory.m_pMemory,
          count: 4 * v57);
      if ( vecHudPanels.m_Memory.m_pMemory != nullptr )
        *vecHudPanels.m_Memory.m_pMemory = (unsigned int)nClearFlags;
      whatToDraw = VGui_GetFullscreenRootVPANEL();
      nClearFlags = (IVRenderView_vtbl *)m_Size;
      if ( m_Size + 1 > vecHudPanels.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&vecHudPanels,
          num: m_Size - vecHudPanels.m_Memory.m_nAllocationCount + 1);
        m_Size = vecHudPanels.m_Size;
      }
      v58 = m_Size + 1;
      vecHudPanels.m_Size = v58;
      vecHudPanels.m_pElements = vecHudPanels.m_Memory.m_pMemory;
      if ( v58 - (int)nClearFlags - 1 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&vecHudPanels.m_Memory.m_pMemory[(_DWORD)nClearFlags + 1],
          src: (unsigned __int8 *)&vecHudPanels.m_Memory.m_pMemory[(_DWORD)nClearFlags],
          count: 4 * (v58 - (_DWORD)nClearFlags - 1));
      v59 = &vecHudPanels.m_Memory.m_pMemory[(_DWORD)nClearFlags];
      if ( v59 != nullptr )
        *v59 = whatToDraw;
      whatToDraw = enginevgui->GetPanel(this: enginevgui, a2: PANEL_CLIENTDLL_TOOLS);
      nClearFlags = (IVRenderView_vtbl *)v58;
      if ( v58 + 1 > vecHudPanels.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&vecHudPanels,
          num: v58 - vecHudPanels.m_Memory.m_nAllocationCount + 1);
        v58 = vecHudPanels.m_Size;
      }
      vecHudPanels.m_Size = v58 + 1;
      vecHudPanels.m_pElements = vecHudPanels.m_Memory.m_pMemory;
      v60 = v58 - (_DWORD)nClearFlags;
      if ( v60 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&vecHudPanels.m_Memory.m_pMemory[(_DWORD)nClearFlags + 1],
          src: (unsigned __int8 *)&vecHudPanels.m_Memory.m_pMemory[(_DWORD)nClearFlags],
          count: 4 * v60);
      v61 = &vecHudPanels.m_Memory.m_pMemory[(_DWORD)nClearFlags];
      if ( v61 != nullptr )
        *v61 = whatToDraw;
      PositionHudPanels(list: &vecHudPanels, view: hudViewSetup);
      s_bCanAccessCurrentView = true;
      render->VGui_Paint(this: render, a2: 2);
      s_bCanAccessCurrentView = false;
      VGui_PostRender();
      v62 = GetClientMode();
      v62->PostRenderVGui(this: v62);
      v55 = view;
      (*(void (__thiscall **)(CViewSetup *, int, int, int, int, int))(view->x + 776))(
        a1: view,
        a2: 2,
        a3: hudViewSetup->x,
        a4: hudViewSetup->y,
        a5: hudViewSetup->width,
        a6: hudViewSetup->height);
      (*(void (__thiscall **)(const CViewSetup *, int))(v55->x + 780))(a1: v55, a2: 2);
      (*(void (__thiscall **)(const CViewSetup *, _DWORD))(v55->x + 16))(a1: v55, a2: 0);
      CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&vecHudPanels);
      CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
    }
    CDebugViewRender::Draw2DDebuggingInfo(view: hudViewSetup);
    v6->Render2DEffectsPostHUD(this: v6, a2: hudViewSetup);
    g_bRenderingView = false;
    s_bCanAccessCurrentView = false;
    CDebugViewRender::GenerateOverdrawForTesting();
    v63 = v6->GetFrustum;
    hudViewSetup = (const CViewSetup *)render->__vftable;
    v64 = (int)v63(this: v6);
    ((void (__thiscall *)(IVRenderView *, const CViewSetup *, int))hudViewSetup->m_nMotionBlurMode)(
      a1: render,
      a2: v55,
      a3: v64);
    if ( v55 != nullptr )
    {
      (*(void (__thiscall **)(const CViewSetup *))(v55->x + 12))(a1: v55);
      (*(void (__thiscall **)(const CViewSetup *))(v55->x + 4))(a1: v55);
    }
    CWorldListCache::Flush(this: &g_WorldListCache);
    CViewSetup::operator=(this: blend, __that: v7);
    ParticleUsageDemo(a1: (int)v6);
    C_BaseAnimating::AutoAllowBoneAccess::~AutoAllowBoneAccess(this: &boneaccess);
  }
  else
  {
    if ( bFirstTime_0 )
    {
      bFirstTime_0 = false;
      _Msg(a1: "This game has a minimum requirement of Shader Model 2.0 to run properly.\n");
    }
    C_BaseAnimating::AutoAllowBoneAccess::~AutoAllowBoneAccess(this: &boneaccess);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10414860
// Name: _dynamic_initializer_for__CClientRenderablesList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CClientRenderablesList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CClientRenderablesList::s_Allocator,
    blockSize: 0x18124u,
    numElements: 1,
    growMode: 2,
    pszAllocOwner: "CClientRenderablesList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CClientRenderablesList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x1041FD30
// Name: PrecachePostProcessingEffectsPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
CBaseResourcePrecacher *PrecachePostProcessingEffectsPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  CBaseResourcePrecacher *result; // eax

  result = CBaseResourcePrecacher::sm_pFirst[0];
  PrecachePostProcessingEffectsPrecache::s_ResourcePrecacher.m_pNext = CBaseResourcePrecacher::sm_pFirst[0];
  CBaseResourcePrecacher::sm_pFirst[0] = &PrecachePostProcessingEffectsPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10431080
// Name: _dynamic_atexit_destructor_for__CClientRenderablesList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CClientRenderablesList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CClientRenderablesList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x10434D70
// Name: _CViewRender::UpdateShadowDepthTexture_::_4_::_dynamic_atexit_destructor_for___counter__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CViewRender::UpdateShadowDepthTexture_::_4_::_dynamic_atexit_destructor_for___counter__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10434D90
// Name: _CViewRender::DrawOneMonitor_::_4_::_dynamic_atexit_destructor_for___counter__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CViewRender::DrawOneMonitor_::_4_::_dynamic_atexit_destructor_for___counter__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10434DA0
// Name: _CRendering3dView::DrawWorld_::_4_::_dynamic_atexit_destructor_for___counter__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CRendering3dView::DrawWorld_::_4_::_dynamic_atexit_destructor_for___counter__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1041FD50
// Name: _dynamic_initializer_for__mat_lpreview_mode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_lpreview_mode__()
{
  ConVar::ConVar(this: &mat_lpreview_mode, pName: "mat_lpreview_mode", pDefaultValue: "-1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_lpreview_mode__);
}

//------------------------------------------------------------------------------
// Address: 0x1041FD80
// Name: _dynamic_initializer_for__r_fade360style__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_fade360style__()
{
  ConVar::ConVar(this: &r_fade360style, pName: "r_fade360style", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_fade360style__);
}

//------------------------------------------------------------------------------
// Address: 0x1041FDB0
// Name: _dynamic_initializer_for__r_particle_demo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_particle_demo__()
{
  ConVar::ConVar(this: &r_particle_demo, pName: "r_particle_demo", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_particle_demo__);
}

//------------------------------------------------------------------------------
// Address: 0x1041FDE0
// Name: _dynamic_initializer_for__ClientWorldListInfo_t::gm_Pool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1041FE10
// Name: _dynamic_initializer_for__g_material_WriteZ__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_material_WriteZ__()
{
  CMaterialReference::CMaterialReference(
    this: &g_material_WriteZ,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  return atexit(func: dynamic_atexit_destructor_for__g_material_WriteZ__);
}

//------------------------------------------------------------------------------
// Address: 0x1041FE30
// Name: _dynamic_initializer_for__cl_brushfastpath__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_brushfastpath__()
{
  ConVar::ConVar(this: &cl_brushfastpath, pName: "cl_brushfastpath", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__cl_brushfastpath__);
}

//------------------------------------------------------------------------------
// Address: 0x1041FE60
// Name: _dynamic_initializer_for__r_drawbrushmodels__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_drawbrushmodels__()
{
  ConVar::ConVar(
    this: &r_drawbrushmodels,
    pName: "r_drawbrushmodels",
    pDefaultValue: "1",
    flags: 0x4000,
    pHelpString: "Render brush models. 0=Off, 1=Normal, 2=Wireframe");
  return atexit(func: dynamic_atexit_destructor_for__r_drawbrushmodels__);
}

//------------------------------------------------------------------------------
// Address: 0x1041FE90
// Name: _dynamic_initializer_for__cl_modelfastpath__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_modelfastpath__()
{
  ConVar::ConVar(this: &cl_modelfastpath, pName: "cl_modelfastpath", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__cl_modelfastpath__);
}

//------------------------------------------------------------------------------
// Address: 0x1041FEC0
// Name: _dynamic_initializer_for__cl_skipslowpath__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_skipslowpath__()
{
  ConVar::ConVar(
    this: &cl_skipslowpath,
    pName: "cl_skipslowpath",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Set to 1 to skip any models that don't go through the model fast path");
  return atexit(func: dynamic_atexit_destructor_for__cl_skipslowpath__);
}

//------------------------------------------------------------------------------
// Address: 0x1041FEF0
// Name: _dynamic_initializer_for__r_unlimitedrefract__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_unlimitedrefract__()
{
  ConVar::ConVar(this: &r_unlimitedrefract, pName: "r_unlimitedrefract", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_unlimitedrefract__);
}

//------------------------------------------------------------------------------
// Address: 0x1041FF20
// Name: _dynamic_initializer_for__cl_tlucfastpath__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_tlucfastpath__()
{
  ConVar::ConVar(this: &cl_tlucfastpath, pName: "cl_tlucfastpath", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__cl_tlucfastpath__);
}

//------------------------------------------------------------------------------
// Address: 0x10431090
// Name: _dynamic_atexit_destructor_for__r_drawallrenderables__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_drawallrenderables__()
{
  ConVar::~ConVar(this: &r_drawallrenderables);
}

//------------------------------------------------------------------------------
// Address: 0x104310A0
// Name: _dynamic_atexit_destructor_for__r_fastreflectionfastpath__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_fastreflectionfastpath__()
{
  ConVar::~ConVar(this: &r_fastreflectionfastpath);
}

//------------------------------------------------------------------------------
// Address: 0x104310B0
// Name: _dynamic_atexit_destructor_for__r_highlight_translucent_renderables__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_highlight_translucent_renderables__()
{
  ConVar::~ConVar(this: &r_highlight_translucent_renderables);
}

//------------------------------------------------------------------------------
// Address: 0x10434D80
// Name: _dynamic_atexit_destructor_for__r_particle_demo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_particle_demo__()
{
  ConVar::~ConVar(this: &r_particle_demo);
}

//------------------------------------------------------------------------------
// Address: 0x10434DB0
// Name: _dynamic_atexit_destructor_for__g_material_WriteZ__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_material_WriteZ__()
{
  CMaterialReference::~CMaterialReference(this: &g_material_WriteZ);
}

//------------------------------------------------------------------------------
// Address: 0x10434DC0
// Name: _dynamic_atexit_destructor_for__cl_brushfastpath__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_brushfastpath__()
{
  ConVar::~ConVar(this: &cl_brushfastpath);
}

//------------------------------------------------------------------------------
// Address: 0x10434DD0
// Name: _dynamic_atexit_destructor_for__r_drawbrushmodels__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_drawbrushmodels__()
{
  ConVar::~ConVar(this: &r_drawbrushmodels);
}

//------------------------------------------------------------------------------
// Address: 0x10434DE0
// Name: _dynamic_atexit_destructor_for__cl_modelfastpath__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_modelfastpath__()
{
  ConVar::~ConVar(this: &cl_modelfastpath);
}

//------------------------------------------------------------------------------
// Address: 0x10434DF0
// Name: _dynamic_atexit_destructor_for__cl_skipslowpath__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_skipslowpath__()
{
  ConVar::~ConVar(this: &cl_skipslowpath);
}

//------------------------------------------------------------------------------
// Address: 0x10434E00
// Name: _dynamic_atexit_destructor_for__r_unlimitedrefract__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__r_unlimitedrefract__()
{
  ConVar::~ConVar(this: &r_unlimitedrefract);
}

//------------------------------------------------------------------------------
// Address: 0x10434E10
// Name: _dynamic_atexit_destructor_for__cl_tlucfastpath__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_tlucfastpath__()
{
  ConVar::~ConVar(this: &cl_tlucfastpath);
}

//------------------------------------------------------------------------------
// Address: 0x10434E20
// Name: _dynamic_atexit_destructor_for__g_Precipitations___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Precipitations___0()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_Precipitations_0);
}

//------------------------------------------------------------------------------
// Address: 0x10434E30
// Name: _dynamic_atexit_destructor_for__ClientWorldListInfo_t::gm_Pool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ClientWorldListInfo_t::gm_Pool__()
{
  TSLNodeBase_t *v0; // eax
  TSLNodeBase_t *Next; // esi

  CObjectPool<ClientWorldListInfo_t,0,1>::Purge(this: &ClientWorldListInfo_t::gm_Pool);
  v0 = CTSListBase::Detach(this: &ClientWorldListInfo_t::gm_Pool.m_AvailableObjects);
  if ( v0 != nullptr )
  {
    do
    {
      Next = v0->Next;
      C_BaseEntity::operator delete(pMem: v0);
      v0 = Next;
    }
    while ( Next != nullptr );
  }
  CTSListBase::Detach(this: &ClientWorldListInfo_t::gm_Pool.m_AvailableObjects);
}

//------------------------------------------------------------------------------
// Address: 0x10434E70
// Name: _dynamic_atexit_destructor_for__g_WorldListCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_WorldListCache__()
{
  CUtlRBTree<CWorldListCache::Entry_t *,unsigned short,CWorldListCache::CEntryComparator,CUtlMemory<UtlRBTreeNode_t<CWorldListCache::Entry_t *,unsigned short>,unsigned short>>::~CUtlRBTree<CWorldListCache::Entry_t *,unsigned short,CWorldListCache::CEntryComparator,CUtlMemory<UtlRBTreeNode_t<CWorldListCache::Entry_t *,unsigned short>,unsigned short>>(this: &g_WorldListCache.m_Entries);
}
