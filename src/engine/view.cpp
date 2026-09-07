// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/view.cpp
// Functions: 66
// ============================================================

#include "engine\view.h"

//------------------------------------------------------------------------------
// Address: 0x100CF790
// Name: void R_DrawBrushModelArray(class IMatRenderContext __near *,int,struct BrushArrayInstanceData_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DrawBrushModelArray(
        IMatRenderContext *pRenderContext,
        int nCount,
        const BrushArrayInstanceData_t *pInstanceData,
        int nModelTypeFlags)
{
  if ( (nModelTypeFlags & 0x40000000) != 0 )
    CBrushBatchRender::DrawBrushModelShadowArray(this: &g_BrushBatchRenderer, pRenderContext, nCount, pInstanceData);
  else
    CBrushBatchRender::DrawBrushModelArray(this: &g_BrushBatchRenderer, pRenderContext, nCount, pInstanceData);
}

//------------------------------------------------------------------------------
// Address: 0x100DC450
// Name: public: struct memhandle_t__ __near * __near * CMatRenderData<struct memhandle_t__ __near *>::Lock(int,struct memhandle_t__ __near * const __near *)
// Source: json
//------------------------------------------------------------------------------
memhandle_t__ **__thiscall CMatRenderData<memhandle_t__ *>::Lock(
        CMatRenderData<memhandle_t__ *> *this,
        int nCount,
        memhandle_t__ **pSrcData)
{
  IMatRenderContext *m_pRenderContext; // ecx
  memhandle_t__ **result; // eax
  unsigned int v6; // ebx
  memhandle_t__ **nCounta; // [esp+14h] [ebp+8h]

  this->m_nCount = nCount;
  if ( pSrcData != nullptr
    && ((unsigned __int8 (__stdcall *)(memhandle_t__ **))this->m_pRenderContext->IsRenderData)(a1: pSrcData) != 0 )
  {
    m_pRenderContext = this->m_pRenderContext;
    this->m_pRenderData = pSrcData;
    m_pRenderContext->AddRefRenderData(this: m_pRenderContext);
    result = this->m_pRenderData;
    this->m_bNeedsUnlock = false;
  }
  else
  {
    v6 = 4 * nCount;
    result = (memhandle_t__ **)this->m_pRenderContext->LockRenderData(this: this->m_pRenderContext, a2: 4 * nCount);
    nCounta = result;
    if ( pSrcData != nullptr && result != nullptr )
    {
      memcpy(dst: (unsigned __int8 *)result, src: (unsigned __int8 *)pSrcData, count: v6);
      result = nCounta;
    }
    this->m_pRenderData = result;
    this->m_bNeedsUnlock = true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100FF540
// Name: public: CMatRenderData<struct memhandle_t__ __near *>::~CMatRenderData<struct memhandle_t__ __near *>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderData<memhandle_t__ *>::~CMatRenderData<memhandle_t__ *>(CMatRenderData<matrix3x4a_t> *this)
{
  IMatRenderContext *m_pRenderContext; // ecx
  IMatRenderContext_vtbl *v3; // edx

  m_pRenderContext = this->m_pRenderContext;
  if ( m_pRenderContext != nullptr && this->m_pRenderData != nullptr )
  {
    v3 = m_pRenderContext->__vftable;
    if ( this->m_bNeedsUnlock )
    {
      ((void (__stdcall *)(matrix3x4a_t *))v3->UnlockRenderData)(a1: this->m_pRenderData);
      this->m_pRenderData = nullptr;
      this->m_nCount = 0;
      this->m_bNeedsUnlock = false;
      return;
    }
    ((void (*)(void))v3->ReleaseRenderData)();
  }
  this->m_pRenderData = nullptr;
  this->m_nCount = 0;
  this->m_bNeedsUnlock = false;
}

//------------------------------------------------------------------------------
// Address: 0x10115450
// Name: bool V_CheckGamma(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl V_CheckGamma()
{
  int m_nValue; // ecx

  if ( r_avglightmap.m_pParent != nullptr )
    m_nValue = r_avglightmap.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( m_nValue != lastLightmap )
  {
    if ( r_avglightmap.m_pParent != nullptr )
    {
      lastLightmap = r_avglightmap.m_pParent->m_Value.m_nValue;
      GL_RebuildLightmaps();
      return 1;
    }
    lastLightmap = 0;
    GL_RebuildLightmaps();
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10115490
// Name: void V_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl V_Init()
{
  BuildGammaTable(gamma: 2.2, texGamma: 2.2, brightness: 0.0, overbright: 2);
}

//------------------------------------------------------------------------------
// Address: 0x101154D0
// Name: public: virtual void CVRenderView::TouchLight(struct dlight_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::TouchLight(CVRenderView *this, dlight_t *light)
{
  unsigned int v2; // ecx

  v2 = light - cl_dlights;
  if ( v2 <= 0x1F )
    r_dlightchanged |= 1 << v2;
}

//------------------------------------------------------------------------------
// Address: 0x10115510
// Name: public: virtual void CVRenderView::DrawBrushModel(class IClientEntity __near *,struct model_t __near *,class Vector const __near &,class QAngle const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::DrawBrushModel(
        CVRenderView *this,
        IClientEntity *baseentity,
        model_t *model,
        const Vector *origin,
        const QAngle *angles,
        bool bUnused)
{
  R_DrawBrushModel(baseentity, model, origin, angles, bShadowDepth: false, bDrawOpaque: true, bDrawTranslucent: true);
}

//------------------------------------------------------------------------------
// Address: 0x10115540
// Name: public: virtual void CVRenderView::DrawBrushModelEx(class IClientEntity __near *,struct model_t __near *,class Vector const __near &,class QAngle const __near &,enum DrawBrushModelMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::DrawBrushModelEx(
        CVRenderView *this,
        IClientEntity *baseentity,
        model_t *model,
        const Vector *origin,
        const QAngle *angles,
        DrawBrushModelMode_t mode)
{
  R_DrawBrushModel(
    baseentity,
    model,
    origin,
    angles,
    bShadowDepth: false,
    bDrawOpaque: mode != DBM_DRAW_TRANSLUCENT_ONLY,
    bDrawTranslucent: mode != DBM_DRAW_OPAQUE_ONLY);
}

//------------------------------------------------------------------------------
// Address: 0x10115580
// Name: public: virtual void CVRenderView::DrawBrushModelShadow(class IClientRenderable __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::DrawBrushModelShadow(CVRenderView *this, IClientRenderable *pRenderable)
{
  R_DrawBrushModelShadow(pRenderable);
}

//------------------------------------------------------------------------------
// Address: 0x101155A0
// Name: public: virtual void CVRenderView::DrawIdentityBrushModel(class IWorldRenderList __near *,struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::DrawIdentityBrushModel(CVRenderView *this, IWorldRenderList *pList, model_t *model)
{
  R_DrawIdentityBrushModel(pRenderListIn: pList, model);
}

//------------------------------------------------------------------------------
// Address: 0x101155C0
// Name: public: virtual void CVRenderView::Draw3DDebugOverlays(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::Draw3DDebugOverlays(CVRenderView *this)
{
  ISpatialPartitionInternal *v1; // eax
  IOcclusionSystem *v2; // eax

  DrawSavedModelDebugOverlays();
  if ( g_pDemoUI != nullptr )
    g_pDemoUI->DrawDebuggingInfo(this: g_pDemoUI);
  if ( g_pDemoUI2 != nullptr )
    g_pDemoUI2->DrawDebuggingInfo(this: g_pDemoUI2);
  v1 = SpatialPartition();
  v1->DrawDebugOverlays(this: v1);
  CDebugOverlay::Draw3DOverlays();
  v2 = OcclusionSystem();
  v2->DrawDebugOverlays(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10115620
// Name: public: virtual void CVRenderView::SetBlend(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::SetBlend(CVRenderView *this, float blend)
{
  r_blend = blend;
  if ( blend != 1.0
    || r_colormod.x != 1.0
    || r_colormod.y != 1.0
    || (g_bIsBlendingOrModulating = false, r_colormod.z != 1.0) )
  {
    g_bIsBlendingOrModulating = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10115690
// Name: public: virtual float CVRenderView::GetBlend(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CVRenderView::GetBlend(CVRenderView *this)
{
  return r_blend;
}

//------------------------------------------------------------------------------
// Address: 0x101156A0
// Name: public: virtual void CVRenderView::SetColorModulation(float const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::SetColorModulation(CVRenderView *this, float *blend)
{
  float v2; // xmm1_4
  float v3; // xmm2_4
  float v4; // xmm3_4

  v2 = *blend;
  r_colormod.x = *blend;
  v3 = blend[1];
  r_colormod.y = v3;
  v4 = blend[2];
  r_colormod.z = v4;
  if ( r_blend != 1.0 || v2 != 1.0 || v3 != 1.0 || (g_bIsBlendingOrModulating = false, v4 != 1.0) )
    g_bIsBlendingOrModulating = true;
}

//------------------------------------------------------------------------------
// Address: 0x10115720
// Name: public: virtual void CVRenderView::GetColorModulation(float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::GetColorModulation(CVRenderView *this, Vector *blend)
{
  *blend = r_colormod;
}

//------------------------------------------------------------------------------
// Address: 0x10115750
// Name: public: virtual void CVRenderView::SceneBegin(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::SceneBegin(CVRenderView *this)
{
  g_EngineRenderer->DrawSceneBegin(this: g_EngineRenderer);
}

//------------------------------------------------------------------------------
// Address: 0x10115760
// Name: public: virtual void CVRenderView::SceneEnd(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::SceneEnd(CVRenderView *this)
{
  g_EngineRenderer->DrawSceneEnd(this: g_EngineRenderer);
}

//------------------------------------------------------------------------------
// Address: 0x10115770
// Name: public: virtual void CVRenderView::GetVisibleFogVolume(class Vector const __near &,struct VisOverrideData_t const __near *,struct VisibleFogVolumeInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::GetVisibleFogVolume(
        CVRenderView *this,
        const Vector *vEyePoint,
        const VisOverrideData_t *pVisOverrideData,
        VisibleFogVolumeInfo_t *pInfo)
{
  R_GetVisibleFogVolume(vEyePoint, pVisOverrideData, pInfo);
}

//------------------------------------------------------------------------------
// Address: 0x10115790
// Name: public: virtual class IWorldRenderList __near * CVRenderView::CreateWorldList(void)
// Source: json
//------------------------------------------------------------------------------
IWorldRenderList *__thiscall CVRenderView::CreateWorldList(CVRenderView *this)
{
  return g_EngineRenderer->CreateWorldList(this: g_EngineRenderer);
}

//------------------------------------------------------------------------------
// Address: 0x101157A0
// Name: public: virtual void CVRenderView::BuildWorldLists(class IWorldRenderList __near *,struct WorldListInfo_t __near *,int,struct VisOverrideData_t const __near *,bool,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::BuildWorldLists(
        CVRenderView *this,
        IWorldRenderList *pList,
        WorldListInfo_t *pInfo,
        int iForceFViewLeaf,
        const VisOverrideData_t *pVisData,
        BOOL bShadowDepth,
        float *pReflectionWaterHeight)
{
  g_EngineRenderer->BuildWorldLists(
    this: g_EngineRenderer,
    a2: pList,
    a3: pInfo,
    a4: iForceFViewLeaf,
    a5: pVisData,
    a6: bShadowDepth,
    a7: pReflectionWaterHeight);
}

//------------------------------------------------------------------------------
// Address: 0x101157C0
// Name: public: virtual void CVRenderView::DrawWorldLists(class IMatRenderContext __near *,class IWorldRenderList __near *,unsigned long,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::DrawWorldLists(
        CVRenderView *this,
        IMatRenderContext *pRenderContext,
        IMatRenderContext *pList,
        IWorldRenderList *flags,
        float waterZAdjust)
{
  ((void (__stdcall *)(IMatRenderContext *, IMatRenderContext *, IWorldRenderList *, _DWORD))g_EngineRenderer->DrawWorldLists)(
    a1: pRenderContext,
    a2: pList,
    a3: flags,
    a4: LODWORD(waterZAdjust));
}

//------------------------------------------------------------------------------
// Address: 0x101157F0
// Name: public: virtual void CVRenderView::GetWorldListIndicesInfo(struct WorldListIndicesInfo_t __near *,class IWorldRenderList __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::GetWorldListIndicesInfo(
        CVRenderView *this,
        WorldListIndicesInfo_t *pIndicesInfoOut,
        IWorldRenderList *pList,
        unsigned int nFlags)
{
  R_GetWorldListIndicesInfo(pInfoOut: pIndicesInfoOut, pRenderListIn: pList, nFlags);
}

//------------------------------------------------------------------------------
// Address: 0x10115810
// Name: public: virtual void CVRenderView::DrawTopView(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::DrawTopView(CVRenderView *this, bool enable)
{
  R_DrawTopView(enable);
}

//------------------------------------------------------------------------------
// Address: 0x10115830
// Name: public: virtual void CVRenderView::TopViewBounds(class Vector2D const __near &,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::TopViewBounds(CVRenderView *this, const Vector2D *mins, const Vector2D *maxs)
{
  R_TopViewBounds(mins, maxs);
}

//------------------------------------------------------------------------------
// Address: 0x10115850
// Name: public: virtual void CVRenderView::DrawLights(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::DrawLights(CVRenderView *this)
{
  DrawLightSprites();
  DrawLightDebuggingInfo();
}

//------------------------------------------------------------------------------
// Address: 0x10115860
// Name: public: virtual void CVRenderView::DrawTranslucentSurfaces(class IMatRenderContext __near *,class IWorldRenderList __near *,int __near *,int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::DrawTranslucentSurfaces(
        CVRenderView *this,
        IMatRenderContext *pRenderContext,
        IWorldRenderList *pList,
        int *pSortList,
        int sortCount,
        unsigned int flags)
{
  Shader_DrawTranslucentSurfaces(pRenderContext, pRenderListIn: pList, pSortList, sortCount, flags);
}

//------------------------------------------------------------------------------
// Address: 0x10115890
// Name: public: virtual bool CVRenderView::LeafContainsTranslucentSurfaces(class IWorldRenderList __near *,int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVRenderView::LeafContainsTranslucentSurfaces(
        CVRenderView *this,
        IWorldRenderList *pList,
        int sortIndex,
        unsigned int flags)
{
  return Shader_LeafContainsTranslucentSurfaces(pRenderListIn: pList, sortIndex, flags);
}

//------------------------------------------------------------------------------
// Address: 0x101158B0
// Name: public: virtual void CVRenderView::DrawLineFile(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CVRenderView::DrawLineFile(CVRenderView *this)
{
  Linefile_Draw();
}

//------------------------------------------------------------------------------
// Address: 0x101158C0
// Name: public: virtual void CVRenderView::DrawLightmaps(class IWorldRenderList __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::DrawLightmaps(CVRenderView *this, IWorldRenderList *pList, int pageId)
{
  R_DrawLightmaps(pList, pageId);
}

//------------------------------------------------------------------------------
// Address: 0x101158E0
// Name: public: virtual void CVRenderView::ViewSetupVis(bool,int,class Vector const __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::ViewSetupVis(CVRenderView *this, BOOL novis, int numorigins, const Vector *origin)
{
  g_EngineRenderer->ViewSetupVis(this: g_EngineRenderer, a2: novis, a3: numorigins, a4: origin);
}

//------------------------------------------------------------------------------
// Address: 0x10115900
// Name: public: virtual void CVRenderView::ViewSetupVisEx(bool,int,class Vector const __near * const,unsigned int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::ViewSetupVisEx(
        CVRenderView *this,
        BOOL novis,
        int numorigins,
        const Vector *origin,
        unsigned int *returnFlags)
{
  g_EngineRenderer->ViewSetupVisEx(this: g_EngineRenderer, a2: novis, a3: numorigins, a4: origin, a5: returnFlags);
}

//------------------------------------------------------------------------------
// Address: 0x10115920
// Name: public: virtual bool CVRenderView::AreAnyLeavesVisible(int __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVRenderView::AreAnyLeavesVisible(CVRenderView *this, int *leafList, int nLeaves)
{
  return Map_AreAnyLeavesVisible(worldbrush: host_state.worldbrush, leafList, nLeaves);
}

//------------------------------------------------------------------------------
// Address: 0x10115940
// Name: public: virtual void CVRenderView::VguiPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::VguiPaint(CVRenderView *this)
{
  IEngineVGuiInternal *v1; // eax

  v1 = EngineVGui();
  v1->BackwardCompatibility_Paint(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10115950
// Name: public: virtual void CVRenderView::VGui_Paint(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::VGui_Paint(CVRenderView *this, PaintMode_t mode)
{
  IEngineVGuiInternal *v2; // eax

  v2 = EngineVGui();
  v2->Paint(this: v2, a2: mode);
}

//------------------------------------------------------------------------------
// Address: 0x10115970
// Name: public: virtual void CVRenderView::ViewDrawFade(unsigned char __near *,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::ViewDrawFade(CVRenderView *this, unsigned __int8 *color, IMaterial *pFadeMaterial)
{
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ViewDrawFade",
    a3: 0,
    a4: &args.m_pArgSBuffer[404],
    a5: false,
    a6: 4);
  g_EngineRenderer->ViewDrawFade(this: g_EngineRenderer, a2: color, a3: pFadeMaterial);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x101159C0
// Name: public: virtual void CVRenderView::OLD_SetOffCenterProjectionMatrix(float,float,float,float,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::OLD_SetOffCenterProjectionMatrix(
        CVRenderView *this,
        float fov,
        float zNear,
        float zFar,
        float flAspectRatio,
        float flBottom,
        float flTop,
        float flLeft,
        float flRight)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x101159D0
// Name: public: virtual void CVRenderView::OLD_SetProjectionMatrixOrtho(float,float,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::OLD_SetProjectionMatrixOrtho(
        CVRenderView *this,
        float left,
        float top,
        float right,
        float bottom,
        float zNear,
        float zFar)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x101159E0
// Name: public: virtual struct colorVec CVRenderView::GetLightAtPoint(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
colorVec *__thiscall CVRenderView::GetLightAtPoint(CVRenderView *this, colorVec *result, Vector *pos)
{
  colorVec *v3; // eax
  unsigned int b; // edx
  unsigned int a; // eax
  colorVec v7; // [esp+0h] [ebp-10h] BYREF

  v3 = R_LightPoint(result: &v7, p: pos);
  result->r = v3->r;
  result->g = v3->g;
  b = v3->b;
  a = v3->a;
  result->b = b;
  result->a = a;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10115A20
// Name: public: virtual int CVRenderView::GetViewEntity(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVRenderView::GetViewEntity(CVRenderView *this)
{
  CClientState *LocalClient; // eax

  LocalClient = GetLocalClient(nSlot: -1);
  return CBaseClientState::GetViewEntity(this: LocalClient);
}

//------------------------------------------------------------------------------
// Address: 0x10115A40
// Name: public: virtual bool CVRenderView::IsViewEntity(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVRenderView::IsViewEntity(CVRenderView *this, int entindex)
{
  int v2; // esi
  CClientState *LocalClient; // eax

  v2 = 0;
  while ( 1 )
  {
    LocalClient = GetLocalClient(nSlot: v2);
    if ( CBaseClientState::GetViewEntity(this: LocalClient) == entindex )
      break;
    if ( ++v2 != 0 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10115A80
// Name: public: virtual float CVRenderView::GetFieldOfView(void)
// Source: json
//------------------------------------------------------------------------------
float __thiscall CVRenderView::GetFieldOfView(CVRenderView *this)
{
  return g_EngineRenderer->GetFov(this: g_EngineRenderer);
}

//------------------------------------------------------------------------------
// Address: 0x10115A90
// Name: public: virtual unsigned char __near * __near * CVRenderView::GetAreaBits(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 **__thiscall CVRenderView::GetAreaBits(CVRenderView *this)
{
  CClientState *BaseLocalClient; // eax

  BaseLocalClient = GetBaseLocalClient();
  return CClientState::GetAreaBits_BackwardCompatibility(this: BaseLocalClient);
}

//------------------------------------------------------------------------------
// Address: 0x10115AA0
// Name: public: virtual void CVRenderView::SetAreaState(unsigned char __near * const,unsigned char __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::SetAreaState(
        CVRenderView *this,
        unsigned __int8 *chAreaBits,
        unsigned __int8 *chAreaPortalBits)
{
  CClientState *BaseLocalClient; // eax

  BaseLocalClient = GetBaseLocalClient();
  *CClientState::GetAreaBits_BackwardCompatibility(this: BaseLocalClient) = nullptr;
  qmemcpy(GetBaseLocalClient()->m_chAreaBits, chAreaBits, sizeof(GetBaseLocalClient()->m_chAreaBits));
  qmemcpy(GetBaseLocalClient()->m_chAreaPortalBits, chAreaPortalBits, sizeof(GetBaseLocalClient()->m_chAreaPortalBits));
  GetBaseLocalClient()->m_bAreaBitsValid = true;
}

//------------------------------------------------------------------------------
// Address: 0x10115B20
// Name: public: virtual void CVRenderView::SetFogVolumeState(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::SetFogVolumeState(CVRenderView *this, int fogVolume, bool useHeightFog)
{
  R_SetFogVolumeState(fogVolume, useHeightFog);
}

//------------------------------------------------------------------------------
// Address: 0x10115B40
// Name: public: virtual void CVRenderView::InstallBrushSurfaceRenderer(class IBrushRenderer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::InstallBrushSurfaceRenderer(CVRenderView *this, IBrushRenderer *pBrushRenderer)
{
  R_InstallBrushRenderOverride(pBrushRenderer);
}

//------------------------------------------------------------------------------
// Address: 0x10115B60
// Name: public: virtual bool CVRenderView::EnumerateLeaf(int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CVRenderView::EnumerateLeaf(CVRenderView *this, int leaf, int context)
{
  if ( *(__int16 *)(*(_DWORD *)(host_state.worldmodel->sprite.numframes + 20) + (leaf << 6) + 50) != *(_DWORD *)(context + 4) )
    return 1;
  *(_BYTE *)context = 1;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10115BA0
// Name: public: virtual bool CVRenderView::DoesBoxIntersectWaterVolume(class Vector const __near &,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVRenderView::DoesBoxIntersectWaterVolume(
        CVRenderView *this,
        const Vector *mins,
        const Vector *maxs,
        int leafWaterDataID)
{
  ISpatialLeafEnumerator *v4; // eax
  CVRenderView::BoxIntersectWaterContext_t context; // [esp+0h] [ebp-8h] BYREF

  v4 = nullptr;
  context.m_bFoundWaterLeaf = false;
  context.m_nLeafWaterDataID = leafWaterDataID;
  if ( this != nullptr )
    v4 = &this->ISpatialLeafEnumerator;
  g_pToolBSPTree->EnumerateLeavesInBox(this: g_pToolBSPTree, a2: mins, a3: maxs, a4: v4, a5: (int)&context);
  return context.m_bFoundWaterLeaf;
}

//------------------------------------------------------------------------------
// Address: 0x10115BE0
// Name: public: virtual void CVRenderView::Push3DView(class IMatRenderContext __near *,class CViewSetup const __near &,int,class ITexture __near *,class VPlane __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::Push3DView(
        CVRenderView *this,
        IMatRenderContext *pRenderContext,
        const CViewSetup *view,
        int nFlags,
        ITexture *pRenderTarget,
        VPlane *frustumPlanes)
{
  g_EngineRenderer->Push3DView(
    this: g_EngineRenderer,
    a2: pRenderContext,
    a3: view,
    a4: nFlags,
    a5: pRenderTarget,
    a6: frustumPlanes,
    a7: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10115C10
// Name: public: virtual void CVRenderView::Push2DView(class IMatRenderContext __near *,class CViewSetup const __near &,int,class ITexture __near *,class VPlane __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::Push2DView(
        CVRenderView *this,
        IMatRenderContext *pRenderContext,
        const CViewSetup *view,
        int nFlags,
        ITexture *pRenderTarget,
        VPlane *frustumPlanes)
{
  g_EngineRenderer->Push2DView(
    this: g_EngineRenderer,
    a2: pRenderContext,
    a3: view,
    a4: nFlags,
    a5: pRenderTarget,
    a6: frustumPlanes);
}

//------------------------------------------------------------------------------
// Address: 0x10115C30
// Name: public: virtual void CVRenderView::PopView(class IMatRenderContext __near *,class VPlane __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::PopView(CVRenderView *this, IMatRenderContext *pRenderContext, VPlane *frustumPlanes)
{
  g_EngineRenderer->PopView(this: g_EngineRenderer, a2: pRenderContext, a3: frustumPlanes);
}

//------------------------------------------------------------------------------
// Address: 0x10115C50
// Name: public: virtual void CVRenderView::OverrideViewFrustum(class VPlane __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::OverrideViewFrustum(CVRenderView *this, VPlane *custom)
{
  g_EngineRenderer->OverrideViewFrustum(this: g_EngineRenderer, a2: custom);
}

//------------------------------------------------------------------------------
// Address: 0x10115C70
// Name: public: virtual void CVRenderView::DrawBrushModelShadowDepth(class IClientEntity __near *,struct model_t __near *,class Vector const __near &,class QAngle const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::DrawBrushModelShadowDepth(
        CVRenderView *this,
        IClientEntity *baseentity,
        model_t *model,
        const Vector *origin,
        const QAngle *angles,
        bool bUnused)
{
  R_DrawBrushModel(baseentity, model, origin, angles, bShadowDepth: true, bDrawOpaque: true, bDrawTranslucent: true);
}

//------------------------------------------------------------------------------
// Address: 0x10115CA0
// Name: public: virtual void CVRenderView::UpdateBrushModelLightmap(struct model_t __near *,class IClientRenderable __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::UpdateBrushModelLightmap(
        CVRenderView *this,
        model_t *model,
        IClientRenderable *pRenderable)
{
  g_EngineRenderer->UpdateBrushModelLightmap(this: g_EngineRenderer, a2: model, a3: pRenderable);
}

//------------------------------------------------------------------------------
// Address: 0x10115CC0
// Name: public: virtual void CVRenderView::BeginUpdateLightmaps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::BeginUpdateLightmaps(CVRenderView *this)
{
  g_EngineRenderer->BeginUpdateLightmaps(this: g_EngineRenderer);
}

//------------------------------------------------------------------------------
// Address: 0x10115CD0
// Name: public: virtual void CVRenderView::EndUpdateLightmaps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::EndUpdateLightmaps(CVRenderView *this)
{
  g_EngineRenderer->EndUpdateLightmaps(this: g_EngineRenderer);
}

//------------------------------------------------------------------------------
// Address: 0x10115CE0
// Name: public: virtual void CVRenderView::Push3DView(class IMatRenderContext __near *,class CViewSetup const __near &,int,class ITexture __near *,class VPlane __near * const,class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::Push3DView(
        CVRenderView *this,
        IMatRenderContext *pRenderContext,
        const CViewSetup *view,
        int nFlags,
        ITexture *pRenderTarget,
        VPlane *frustumPlanes,
        ITexture *pDepthTexture)
{
  g_EngineRenderer->Push3DView(
    this: g_EngineRenderer,
    a2: pRenderContext,
    a3: view,
    a4: nFlags,
    a5: pRenderTarget,
    a6: frustumPlanes,
    a7: pDepthTexture);
}

//------------------------------------------------------------------------------
// Address: 0x10115D00
// Name: public: virtual void CVRenderView::GetMatricesForView(class CViewSetup const __near &,class VMatrix __near *,class VMatrix __near *,class VMatrix __near *,class VMatrix __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::GetMatricesForView(
        CVRenderView *this,
        const CViewSetup *view,
        VMatrix *pWorldToView,
        VMatrix *pViewToProjection,
        VMatrix *pWorldToProjection,
        VMatrix *pWorldToPixels)
{
  ComputeViewMatrices(pWorldToView, pViewToProjection, pWorldToProjection, viewSetup: view);
  ComputeWorldToScreenMatrix(pWorldToScreen: pWorldToPixels, worldToProjection: pWorldToProjection, viewSetup: view);
}

//------------------------------------------------------------------------------
// Address: 0x10115D30
// Name: public: virtual bool CVRenderView::DoesBrushModelNeedPowerOf2Framebuffer(struct model_t const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CVRenderView::DoesBrushModelNeedPowerOf2Framebuffer(CVRenderView *this, const model_t *model)
{
  return (model->flags & 0x10) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10115D50
// Name: public: struct BrushArrayInstanceData_t __near * CMatRenderData<struct BrushArrayInstanceData_t>::Lock(int,struct BrushArrayInstanceData_t const __near *)
// Source: json
//------------------------------------------------------------------------------
BrushArrayInstanceData_t *__thiscall CMatRenderData<BrushArrayInstanceData_t>::Lock(
        CMatRenderData<BrushArrayInstanceData_t> *this,
        int nCount,
        BrushArrayInstanceData_t *pSrcData)
{
  IMatRenderContext *m_pRenderContext; // ecx
  BrushArrayInstanceData_t *result; // eax
  unsigned int v6; // esi
  BrushArrayInstanceData_t *nCounta; // [esp+14h] [ebp+8h]

  this->m_nCount = nCount;
  if ( pSrcData != nullptr
    && ((unsigned __int8 (__stdcall *)(BrushArrayInstanceData_t *))this->m_pRenderContext->IsRenderData)(a1: pSrcData) != 0 )
  {
    m_pRenderContext = this->m_pRenderContext;
    this->m_pRenderData = pSrcData;
    m_pRenderContext->AddRefRenderData(this: m_pRenderContext);
    result = this->m_pRenderData;
    this->m_bNeedsUnlock = false;
  }
  else
  {
    v6 = 28 * nCount;
    result = (BrushArrayInstanceData_t *)this->m_pRenderContext->LockRenderData(
                                           this: this->m_pRenderContext,
                                           a2: 28 * nCount);
    nCounta = result;
    if ( pSrcData != nullptr && result != nullptr )
    {
      memcpy(dst: (unsigned __int8 *)result, src: (unsigned __int8 *)pSrcData, count: v6);
      result = nCounta;
    }
    this->m_pRenderData = result;
    this->m_bNeedsUnlock = true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10115DE0
// Name: public: virtual void CFunctor3<void (*)(int,struct BrushArrayInstanceData_t const __near *,int),int,struct BrushArrayInstanceData_t const __near *,int,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor3<void (__cdecl *)(int,BrushArrayInstanceData_t const *,int),int,BrushArrayInstanceData_t const *,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor3<void (__cdecl*)(int,BrushArrayInstanceData_t const *,int),int,BrushArrayInstanceData_t const *,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  this->m_pfnProxied(a1: this->m_arg1, a2: this->m_arg2, a3: this->m_arg3);
}

//------------------------------------------------------------------------------
// Address: 0x10115E00
// Name: void R_DrawBrushModelArray(int,struct BrushArrayInstanceData_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DrawBrushModelArray(int nCount, const BrushArrayInstanceData_t *pInstanceData, int nModelTypeFlags)
{
  IMatRenderContext *v3; // esi

  v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  R_DrawBrushModelArray(pRenderContext: v3, nCount, pInstanceData, nModelTypeFlags);
  if ( v3 != nullptr )
  {
    v3->EndRender(this: v3);
    v3->Release(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10115E60
// Name: void V_RenderVGuiOnly_NoSwap(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl V_RenderVGuiOnly_NoSwap()
{
  IMatRenderContext *v0; // esi
  IEngineVGuiInternal *v1; // eax

  UpdateMaterialSystemConfig();
  v0 = materials->GetRenderContext(this: materials);
  if ( v0 != nullptr )
    v0->BeginRender(this: v0);
  v0->AntiAliasingHint(this: v0, a2: 8);
  v0->ClearBuffers(this: v0, a2: true, a3: true, a4: false);
  ((void (__thiscall *)(IMatRenderContext *, int))v0->__vftable[1].AddRef)(a1: v0, a2: 1);
  v0->__vftable[1].BeginRender(this: v0);
  v1 = EngineVGui();
  v1->Paint(this: v1, a2: PAINT_UIPANELS);
  v0->EndRender(this: v0);
  v0->Release(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x10115EE0
// Name: void V_RenderVGuiOnly(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl V_RenderVGuiOnly()
{
  IEngineVGuiInternal *v0; // eax

  ((void (__stdcall *)(_DWORD))materials->BeginFrame)(a1: LODWORD(host_frametime));
  v0 = EngineVGui();
  v0->Simulate(this: v0);
  g_EngineRenderer->FrameBegin(this: g_EngineRenderer);
  toolframework->RenderFrameBegin(this: toolframework);
  V_RenderVGuiOnly_NoSwap();
  toolframework->RenderFrameEnd(this: toolframework);
  g_EngineRenderer->FrameEnd(this: g_EngineRenderer);
  materials->EndFrame(this: materials);
  Shader_SwapBuffers();
}

//------------------------------------------------------------------------------
// Address: 0x10115F60
// Name: void V_RenderView(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall V_RenderView(int a1@<esi>)
{
  IMDLCache *v1; // edi
  IEngineVGuiInternal *v2; // eax
  int v3; // eax
  int v4; // esi
  const vrect_t *v5; // eax
  __int64 v6; // [esp+8h] [ebp-14h] BYREF
  _BYTE scr_vrect[12]; // [esp+10h] [ebp-Ch] OVERLAPPED

  v1 = g_pMDLCache;
  g_pMDLCache->BeginCoarseLock(this: g_pMDLCache);
  if ( host_state.worldmodel == nullptr )
    goto LABEL_7;
  if ( GetBaseLocalClient()->m_nSignonState != 6 )
    goto LABEL_7;
  v2 = EngineVGui();
  if ( v2->IsPlayingFullScreenVideo(this: v2) || !toolframework->ShouldGameRenderView(this: toolframework) )
    goto LABEL_7;
  if ( g_bTextMode )
  {
    Sys_Sleep(msec: 15);
LABEL_7:
    V_RenderVGuiOnly_NoSwap();
    v1->EndCoarseLock(this: v1);
    return;
  }
  if ( !g_LostVideoMemory )
  {
    R_CheckForLightingConfigChanges();
    R_CheckForPaintmapChanges();
    v3 = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(
           a1: g_pMaterialSystem,
           a2: a1);
    v4 = v3;
    if ( v3 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 8))(a1: v3);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v4 + 760))(a1: v4, a2: LODWORD(g_ClientGlobalVariables.curtime));
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 4))(a1: v4);
    v5 = videomode->GetClientViewRect(this: videomode);
    v6 = *(_QWORD *)&v5->x;
    *(_DWORD *)scr_vrect = v5->width;
    *(_DWORD *)&scr_vrect[4] = v5->height;
    *(_DWORD *)&scr_vrect[8] = v5->pnext;
    g_ClientDLL->View_Render(this: g_ClientDLL, a2: (vrect_t *)&v6);
  }
  v1->EndCoarseLock(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10116100
// Name: public: virtual void CVRenderView::DrawBrushModelArray(class IMatRenderContext __near *,int,struct BrushArrayInstanceData_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::DrawBrushModelArray(
        CVRenderView *this,
        IMatRenderContext *pRenderContext,
        int nCount,
        const BrushArrayInstanceData_t *pInstanceData,
        int nModelTypeFlags)
{
  ICallQueue *v5; // ebx
  bool (__thiscall *IsRenderData)(IMatRenderContext *, const void *); // edx
  const BrushArrayInstanceData_t *v7; // edi
  CMatRenderData<BrushArrayInstanceData_t> brushArrayData; // [esp+8h] [ebp-10h] BYREF

  v5 = pRenderContext->GetCallQueue(this: pRenderContext);
  if ( v5 != nullptr && r_brush_queue_mode.m_pParent != nullptr && r_brush_queue_mode.m_pParent->m_Value.m_nValue != 0 )
  {
    IsRenderData = pRenderContext->IsRenderData;
    v7 = pInstanceData;
    memset(&brushArrayData.m_pRenderData, 0, 9);
    brushArrayData.m_pRenderContext = pRenderContext;
    if ( !IsRenderData(this: pRenderContext, a2: pInstanceData) )
      pInstanceData = CMatRenderData<BrushArrayInstanceData_t>::Lock(this: &brushArrayData, nCount, pSrcData: v7);
    ICallQueue::QueueCall<void,int,BrushArrayInstanceData_t const *,int,int,BrushArrayInstanceData_t const *,int>(
      this: v5,
      pfnProxied: R_DrawBrushModelArray,
      arg1: &nCount,
      arg2: &pInstanceData,
      arg3: &nModelTypeFlags);
    CMatRenderData<memhandle_t__ *>::~CMatRenderData<memhandle_t__ *>(this: (CMatRenderData<matrix3x4a_t> *)&brushArrayData);
  }
  else
  {
    R_DrawBrushModelArray(pRenderContext, nCount, pInstanceData, nModelTypeFlags);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101154C0
// Name: __CreateCVRenderViewIVRenderView_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVRenderView *__cdecl _CreateCVRenderViewIVRenderView_interface()
{
  return &s_RenderView;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100CF390
// Name: void R_DrawBrushModelArray(class IMatRenderContext __near *,int,struct BrushArrayInstanceData_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DrawBrushModelArray(
        IMatRenderContext *pRenderContext,
        int nCount,
        const BrushArrayInstanceData_t *pInstanceData,
        int nModelTypeFlags)
{
  if ( (nModelTypeFlags & 0x40000000) != 0 )
    CBrushBatchRender::DrawBrushModelShadowArray(this: &g_BrushBatchRenderer, pRenderContext, nCount, pInstanceData);
  else
    CBrushBatchRender::DrawBrushModelArray(this: &g_BrushBatchRenderer, pRenderContext, nCount, pInstanceData);
}

//------------------------------------------------------------------------------
// Address: 0x100DC050
// Name: public: CMatRenderData<struct memhandle_t__ __near *>::~CMatRenderData<struct memhandle_t__ __near *>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatRenderData<memhandle_t__ *>::~CMatRenderData<memhandle_t__ *>(CMatRenderData<matrix3x4a_t> *this)
{
  IMatRenderContext *m_pRenderContext; // ecx
  IMatRenderContext_vtbl *v3; // edx

  m_pRenderContext = this->m_pRenderContext;
  if ( m_pRenderContext != nullptr && this->m_pRenderData != nullptr )
  {
    v3 = m_pRenderContext->__vftable;
    if ( this->m_bNeedsUnlock )
    {
      ((void (__stdcall *)(matrix3x4a_t *))v3->UnlockRenderData)(a1: this->m_pRenderData);
      this->m_pRenderData = nullptr;
      this->m_nCount = 0;
      this->m_bNeedsUnlock = false;
      return;
    }
    ((void (*)(void))v3->ReleaseRenderData)();
  }
  this->m_pRenderData = nullptr;
  this->m_nCount = 0;
  this->m_bNeedsUnlock = false;
}

//------------------------------------------------------------------------------
// Address: 0x100DC0B0
// Name: public: struct memhandle_t__ __near * __near * CMatRenderData<struct memhandle_t__ __near *>::Lock(int,struct memhandle_t__ __near * const __near *)
// Source: json
//------------------------------------------------------------------------------
memhandle_t__ **__thiscall CMatRenderData<memhandle_t__ *>::Lock(
        CMatRenderData<memhandle_t__ *> *this,
        int nCount,
        memhandle_t__ **pSrcData)
{
  IMatRenderContext *m_pRenderContext; // ecx
  memhandle_t__ **result; // eax
  unsigned int v6; // ebx
  memhandle_t__ **nCounta; // [esp+14h] [ebp+8h]

  this->m_nCount = nCount;
  if ( pSrcData != nullptr
    && ((unsigned __int8 (__stdcall *)(memhandle_t__ **))this->m_pRenderContext->IsRenderData)(a1: pSrcData) != 0 )
  {
    m_pRenderContext = this->m_pRenderContext;
    this->m_pRenderData = pSrcData;
    m_pRenderContext->AddRefRenderData(this: m_pRenderContext);
    result = this->m_pRenderData;
    this->m_bNeedsUnlock = false;
  }
  else
  {
    v6 = 4 * nCount;
    result = (memhandle_t__ **)this->m_pRenderContext->LockRenderData(this: this->m_pRenderContext, a2: 4 * nCount);
    nCounta = result;
    if ( pSrcData != nullptr && result != nullptr )
    {
      memcpy(dst: (unsigned __int8 *)result, src: (unsigned __int8 *)pSrcData, count: v6);
      result = nCounta;
    }
    this->m_pRenderData = result;
    this->m_bNeedsUnlock = true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101155F0
// Name: bool V_CheckGamma(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl V_CheckGamma()
{
  int m_nValue; // ecx

  if ( r_avglightmap.m_pParent != nullptr )
    m_nValue = r_avglightmap.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( m_nValue != lastLightmap )
  {
    if ( r_avglightmap.m_pParent != nullptr )
    {
      lastLightmap = r_avglightmap.m_pParent->m_Value.m_nValue;
      GL_RebuildLightmaps();
      return 1;
    }
    lastLightmap = 0;
    GL_RebuildLightmaps();
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10115630
// Name: void V_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl V_Init()
{
  BuildGammaTable(gamma: 2.2, texGamma: 2.2, brightness: 0.0, overbright: 2);
}

//------------------------------------------------------------------------------
// Address: 0x10115670
// Name: public: virtual void CVRenderView::TouchLight(struct dlight_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::TouchLight(CVRenderView *this, dlight_t *light)
{
  unsigned int v2; // ecx

  v2 = light - cl_dlights;
  if ( v2 <= 0x1F )
    r_dlightchanged |= 1 << v2;
}

//------------------------------------------------------------------------------
// Address: 0x101156B0
// Name: public: virtual void CVRenderView::DrawBrushModel(class IClientEntity __near *,struct model_t __near *,class Vector const __near &,class QAngle const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::DrawBrushModel(
        CVRenderView *this,
        IClientEntity *baseentity,
        model_t *model,
        const Vector *origin,
        const QAngle *angles,
        bool bUnused)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  R_DrawBrushModel(
    a1: (unsigned int)&savedregs,
    baseentity,
    model,
    origin,
    angles,
    bShadowDepth: false,
    bDrawOpaque: true,
    bDrawTranslucent: true);
}

//------------------------------------------------------------------------------
// Address: 0x101156E0
// Name: public: virtual void CVRenderView::DrawBrushModelEx(class IClientEntity __near *,struct model_t __near *,class Vector const __near &,class QAngle const __near &,enum DrawBrushModelMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::DrawBrushModelEx(
        CVRenderView *this,
        IClientEntity *baseentity,
        model_t *model,
        const Vector *origin,
        const QAngle *angles,
        DrawBrushModelMode_t mode)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  R_DrawBrushModel(
    a1: (unsigned int)&savedregs,
    baseentity,
    model,
    origin,
    angles,
    bShadowDepth: false,
    bDrawOpaque: mode != DBM_DRAW_TRANSLUCENT_ONLY,
    bDrawTranslucent: mode != DBM_DRAW_OPAQUE_ONLY);
}

//------------------------------------------------------------------------------
// Address: 0x10115740
// Name: public: virtual void CVRenderView::DrawIdentityBrushModel(class IWorldRenderList __near *,struct model_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::DrawIdentityBrushModel(CVRenderView *this, CWorldRenderList *pList, model_t *model)
{
  R_DrawIdentityBrushModel(pRenderListIn: pList, model);
}

//------------------------------------------------------------------------------
// Address: 0x10115840
// Name: public: virtual void CVRenderView::SetColorModulation(float const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::SetColorModulation(CVRenderView *this, float *blend)
{
  float v2; // xmm1_4
  float v3; // xmm2_4
  float v4; // xmm3_4

  v2 = *blend;
  r_colormod.x = *blend;
  v3 = blend[1];
  r_colormod.y = v3;
  v4 = blend[2];
  r_colormod.z = v4;
  if ( r_blend != 1.0 || v2 != 1.0 || v3 != 1.0 || (g_bIsBlendingOrModulating = false, v4 != 1.0) )
    g_bIsBlendingOrModulating = true;
}

//------------------------------------------------------------------------------
// Address: 0x101158F0
// Name: public: virtual void CVRenderView::SceneBegin(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::SceneBegin(CVRenderView *this)
{
  g_EngineRenderer->DrawSceneBegin(this: g_EngineRenderer);
}

//------------------------------------------------------------------------------
// Address: 0x10115910
// Name: public: virtual void CVRenderView::GetVisibleFogVolume(class Vector const __near &,struct VisOverrideData_t const __near *,struct VisibleFogVolumeInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::GetVisibleFogVolume(
        CVRenderView *this,
        const Vector *vEyePoint,
        const VisOverrideData_t *pVisOverrideData,
        VisibleFogVolumeInfo_t *pInfo)
{
  R_GetVisibleFogVolume(vEyePoint, pVisOverrideData, pInfo);
}

//------------------------------------------------------------------------------
// Address: 0x10115930
// Name: public: virtual class IWorldRenderList __near * CVRenderView::CreateWorldList(void)
// Source: json
//------------------------------------------------------------------------------
IWorldRenderList *__thiscall CVRenderView::CreateWorldList(CVRenderView *this)
{
  return g_EngineRenderer->CreateWorldList(this: g_EngineRenderer);
}

//------------------------------------------------------------------------------
// Address: 0x10115960
// Name: public: virtual void CVRenderView::DrawWorldLists(class IMatRenderContext __near *,class IWorldRenderList __near *,unsigned long,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::DrawWorldLists(
        CVRenderView *this,
        IMatRenderContext *pRenderContext,
        IWorldRenderList *pList,
        unsigned int flags,
        float waterZAdjust)
{
  ((void (__stdcall *)(IMatRenderContext *, IWorldRenderList *, unsigned int, _DWORD))g_EngineRenderer->DrawWorldLists)(
    a1: pRenderContext,
    a2: pList,
    a3: flags,
    a4: LODWORD(waterZAdjust));
}

//------------------------------------------------------------------------------
// Address: 0x10115990
// Name: public: virtual void CVRenderView::GetWorldListIndicesInfo(struct WorldListIndicesInfo_t __near *,class IWorldRenderList __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::GetWorldListIndicesInfo(
        CVRenderView *this,
        WorldListIndicesInfo_t *pIndicesInfoOut,
        IWorldRenderList *pList,
        unsigned int nFlags)
{
  R_GetWorldListIndicesInfo(pInfoOut: pIndicesInfoOut, pRenderListIn: pList, nFlags);
}

//------------------------------------------------------------------------------
// Address: 0x101159B0
// Name: public: virtual void CVRenderView::DrawTopView(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::DrawTopView(CVRenderView *this, bool enable)
{
  R_DrawTopView(enable);
}

//------------------------------------------------------------------------------
// Address: 0x101159F0
// Name: public: virtual void CVRenderView::DrawLights(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CVRenderView::DrawLights(CVRenderView *this@<ecx>, float a2@<ebp>)
{
  DrawLightSprites(a1: a2);
  DrawLightDebuggingInfo();
}

//------------------------------------------------------------------------------
// Address: 0x10115A00
// Name: public: virtual void CVRenderView::DrawTranslucentSurfaces(class IMatRenderContext __near *,class IWorldRenderList __near *,int __near *,int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CVRenderView::DrawTranslucentSurfaces(
        CVRenderView *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        IMatRenderContext *pRenderContext,
        IWorldRenderList *pList,
        int *pSortList,
        int sortCount,
        unsigned int flags)
{
  Shader_DrawTranslucentSurfaces(a1: a2, a2: a3, pRenderContext, pRenderListIn: pList, pSortList, sortCount, flags);
}

//------------------------------------------------------------------------------
// Address: 0x10115A30
// Name: public: virtual bool CVRenderView::LeafContainsTranslucentSurfaces(class IWorldRenderList __near *,int,unsigned long)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVRenderView::LeafContainsTranslucentSurfaces(
        CVRenderView *this,
        IWorldRenderList *pList,
        int sortIndex,
        unsigned int flags)
{
  return Shader_LeafContainsTranslucentSurfaces(pRenderListIn: pList, sortIndex);
}

//------------------------------------------------------------------------------
// Address: 0x10115A50
// Name: public: virtual void CVRenderView::DrawLineFile(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CVRenderView::DrawLineFile(CVRenderView *this)
{
  Linefile_Draw();
}

//------------------------------------------------------------------------------
// Address: 0x10115A60
// Name: public: virtual void CVRenderView::DrawLightmaps(class IWorldRenderList __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::DrawLightmaps(CVRenderView *this, IWorldRenderList *pList, int pageId)
{
  R_DrawLightmaps(pList, pageId);
}

//------------------------------------------------------------------------------
// Address: 0x10115AC0
// Name: public: virtual bool CVRenderView::AreAnyLeavesVisible(int __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVRenderView::AreAnyLeavesVisible(CVRenderView *this, int *leafList, int nLeaves)
{
  return Map_AreAnyLeavesVisible(worldbrush: host_state.worldbrush, leafList, nLeaves);
}

//------------------------------------------------------------------------------
// Address: 0x10115AE0
// Name: public: virtual void CVRenderView::VguiPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::VguiPaint(CVRenderView *this)
{
  IEngineVGuiInternal *v1; // eax

  v1 = EngineVGui();
  v1->BackwardCompatibility_Paint(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10115AF0
// Name: public: virtual void CVRenderView::VGui_Paint(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::VGui_Paint(CVRenderView *this, PaintMode_t mode)
{
  IEngineVGuiInternal *v2; // eax

  v2 = EngineVGui();
  v2->Paint(this: v2, a2: mode);
}

//------------------------------------------------------------------------------
// Address: 0x10115B10
// Name: public: virtual void CVRenderView::ViewDrawFade(unsigned char __near *,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::ViewDrawFade(CVRenderView *this, unsigned __int8 *color, IMaterial *pFadeMaterial)
{
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "ViewDrawFade",
    a3: 0,
    a4: &args.m_pArgSBuffer[404],
    a5: false,
    a6: 4);
  g_EngineRenderer->ViewDrawFade(this: g_EngineRenderer, a2: color, a3: pFadeMaterial);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10115B70
// Name: public: virtual void CVRenderView::OLD_SetProjectionMatrixOrtho(float,float,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::OLD_SetProjectionMatrixOrtho(
        CVRenderView *this,
        float left,
        float top,
        float right,
        float bottom,
        float zNear,
        float zFar)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10115B80
// Name: public: virtual struct colorVec CVRenderView::GetLightAtPoint(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
colorVec *__thiscall CVRenderView::GetLightAtPoint(CVRenderView *this, colorVec *result, Vector *pos)
{
  colorVec *v3; // eax
  unsigned int b; // edx
  unsigned int a; // eax
  colorVec v7; // [esp+0h] [ebp-10h] BYREF

  v3 = R_LightPoint(result: &v7, p: pos);
  result->r = v3->r;
  result->g = v3->g;
  b = v3->b;
  a = v3->a;
  result->b = b;
  result->a = a;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10115BC0
// Name: public: virtual int CVRenderView::GetViewEntity(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVRenderView::GetViewEntity(CVRenderView *this)
{
  CClientState *LocalClient; // eax

  LocalClient = GetLocalClient(nSlot: -1);
  return CBaseClientState::GetViewEntity(this: LocalClient);
}

//------------------------------------------------------------------------------
// Address: 0x10115C20
// Name: public: virtual float CVRenderView::GetFieldOfView(void)
// Source: json
//------------------------------------------------------------------------------
float __thiscall CVRenderView::GetFieldOfView(CVRenderView *this)
{
  return g_EngineRenderer->GetFov(this: g_EngineRenderer);
}

//------------------------------------------------------------------------------
// Address: 0x10115C40
// Name: public: virtual void CVRenderView::SetAreaState(unsigned char __near * const,unsigned char __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::SetAreaState(
        CVRenderView *this,
        unsigned __int8 *chAreaBits,
        unsigned __int8 *chAreaPortalBits)
{
  CClientState *BaseLocalClient; // eax

  BaseLocalClient = GetBaseLocalClient();
  *CClientState::GetAreaBits_BackwardCompatibility(this: BaseLocalClient) = nullptr;
  qmemcpy(GetBaseLocalClient()->m_chAreaBits, chAreaBits, sizeof(GetBaseLocalClient()->m_chAreaBits));
  qmemcpy(GetBaseLocalClient()->m_chAreaPortalBits, chAreaPortalBits, sizeof(GetBaseLocalClient()->m_chAreaPortalBits));
  GetBaseLocalClient()->m_bAreaBitsValid = true;
}

//------------------------------------------------------------------------------
// Address: 0x10115D40
// Name: public: virtual bool CVRenderView::DoesBoxIntersectWaterVolume(class Vector const __near &,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVRenderView::DoesBoxIntersectWaterVolume(
        CVRenderView *this,
        const Vector *mins,
        const Vector *maxs,
        int leafWaterDataID)
{
  ISpatialLeafEnumerator *v4; // eax
  CVRenderView::BoxIntersectWaterContext_t context; // [esp+0h] [ebp-8h] BYREF

  v4 = nullptr;
  context.m_bFoundWaterLeaf = false;
  context.m_nLeafWaterDataID = leafWaterDataID;
  if ( this != nullptr )
    v4 = &this->ISpatialLeafEnumerator;
  g_pToolBSPTree->EnumerateLeavesInBox(this: g_pToolBSPTree, a2: mins, a3: maxs, a4: v4, a5: (int)&context);
  return context.m_bFoundWaterLeaf;
}

//------------------------------------------------------------------------------
// Address: 0x10115D80
// Name: public: virtual void CVRenderView::Push3DView(class IMatRenderContext __near *,class CViewSetup const __near &,int,class ITexture __near *,class VPlane __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::Push3DView(
        CVRenderView *this,
        IMatRenderContext *pRenderContext,
        const CViewSetup *view,
        int nFlags,
        ITexture *pRenderTarget,
        VPlane *frustumPlanes)
{
  g_EngineRenderer->Push3DView(
    this: g_EngineRenderer,
    a2: pRenderContext,
    a3: view,
    a4: nFlags,
    a5: pRenderTarget,
    a6: frustumPlanes,
    a7: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10115DB0
// Name: public: virtual void CVRenderView::Push2DView(class IMatRenderContext __near *,class CViewSetup const __near &,int,class ITexture __near *,class VPlane __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::Push2DView(
        CVRenderView *this,
        IMatRenderContext *pRenderContext,
        const CViewSetup *view,
        int nFlags,
        ITexture *pRenderTarget,
        VPlane *frustumPlanes)
{
  g_EngineRenderer->Push2DView(
    this: g_EngineRenderer,
    a2: pRenderContext,
    a3: view,
    a4: nFlags,
    a5: pRenderTarget,
    a6: frustumPlanes);
}

//------------------------------------------------------------------------------
// Address: 0x10115DD0
// Name: public: virtual void CVRenderView::PopView(class IMatRenderContext __near *,class VPlane __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::PopView(CVRenderView *this, IMatRenderContext *pRenderContext, VPlane *frustumPlanes)
{
  g_EngineRenderer->PopView(this: g_EngineRenderer, a2: pRenderContext, a3: frustumPlanes);
}

//------------------------------------------------------------------------------
// Address: 0x10115DF0
// Name: public: virtual void CVRenderView::OverrideViewFrustum(class VPlane __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::OverrideViewFrustum(CVRenderView *this, VPlane *custom)
{
  g_EngineRenderer->OverrideViewFrustum(this: g_EngineRenderer, a2: custom);
}

//------------------------------------------------------------------------------
// Address: 0x10115E10
// Name: public: virtual void CVRenderView::DrawBrushModelShadowDepth(class IClientEntity __near *,struct model_t __near *,class Vector const __near &,class QAngle const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::DrawBrushModelShadowDepth(
        CVRenderView *this,
        IClientEntity *baseentity,
        model_t *model,
        const Vector *origin,
        const QAngle *angles,
        bool bUnused)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  R_DrawBrushModel(
    a1: (unsigned int)&savedregs,
    baseentity,
    model,
    origin,
    angles,
    bShadowDepth: true,
    bDrawOpaque: true,
    bDrawTranslucent: true);
}

//------------------------------------------------------------------------------
// Address: 0x10115E40
// Name: public: virtual void CVRenderView::UpdateBrushModelLightmap(struct model_t __near *,class IClientRenderable __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::UpdateBrushModelLightmap(
        CVRenderView *this,
        model_t *model,
        IClientRenderable *pRenderable)
{
  g_EngineRenderer->UpdateBrushModelLightmap(this: g_EngineRenderer, a2: model, a3: pRenderable);
}

//------------------------------------------------------------------------------
// Address: 0x10115E70
// Name: public: virtual void CVRenderView::EndUpdateLightmaps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::EndUpdateLightmaps(CVRenderView *this)
{
  g_EngineRenderer->EndUpdateLightmaps(this: g_EngineRenderer);
}

//------------------------------------------------------------------------------
// Address: 0x10115E80
// Name: public: virtual void CVRenderView::Push3DView(class IMatRenderContext __near *,class CViewSetup const __near &,int,class ITexture __near *,class VPlane __near * const,class ITexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::Push3DView(
        CVRenderView *this,
        IMatRenderContext *pRenderContext,
        const CViewSetup *view,
        int nFlags,
        ITexture *pRenderTarget,
        VPlane *frustumPlanes,
        ITexture *pDepthTexture)
{
  g_EngineRenderer->Push3DView(
    this: g_EngineRenderer,
    a2: pRenderContext,
    a3: view,
    a4: nFlags,
    a5: pRenderTarget,
    a6: frustumPlanes,
    a7: pDepthTexture);
}

//------------------------------------------------------------------------------
// Address: 0x10115EA0
// Name: public: virtual void CVRenderView::GetMatricesForView(class CViewSetup const __near &,class VMatrix __near *,class VMatrix __near *,class VMatrix __near *,class VMatrix __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::GetMatricesForView(
        CVRenderView *this,
        const CViewSetup *view,
        VMatrix *pWorldToView,
        VMatrix *pViewToProjection,
        VMatrix *pWorldToProjection,
        VMatrix *pWorldToPixels)
{
  ComputeViewMatrices(pWorldToView, pViewToProjection, pWorldToProjection, viewSetup: view);
  ComputeWorldToScreenMatrix(pWorldToScreen: pWorldToPixels, worldToProjection: pWorldToProjection, viewSetup: view);
}

//------------------------------------------------------------------------------
// Address: 0x10115ED0
// Name: public: virtual bool CVRenderView::DoesBrushModelNeedPowerOf2Framebuffer(struct model_t const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CVRenderView::DoesBrushModelNeedPowerOf2Framebuffer(CVRenderView *this, const model_t *model)
{
  return (model->flags & 0x10) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10115EF0
// Name: public: struct BrushArrayInstanceData_t __near * CMatRenderData<struct BrushArrayInstanceData_t>::Lock(int,struct BrushArrayInstanceData_t const __near *)
// Source: json
//------------------------------------------------------------------------------
BrushArrayInstanceData_t *__thiscall CMatRenderData<BrushArrayInstanceData_t>::Lock(
        CMatRenderData<BrushArrayInstanceData_t> *this,
        int nCount,
        BrushArrayInstanceData_t *pSrcData)
{
  IMatRenderContext *m_pRenderContext; // ecx
  BrushArrayInstanceData_t *result; // eax
  unsigned int v6; // esi
  BrushArrayInstanceData_t *nCounta; // [esp+14h] [ebp+8h]

  this->m_nCount = nCount;
  if ( pSrcData != nullptr
    && ((unsigned __int8 (__stdcall *)(BrushArrayInstanceData_t *))this->m_pRenderContext->IsRenderData)(a1: pSrcData) != 0 )
  {
    m_pRenderContext = this->m_pRenderContext;
    this->m_pRenderData = pSrcData;
    m_pRenderContext->AddRefRenderData(this: m_pRenderContext);
    result = this->m_pRenderData;
    this->m_bNeedsUnlock = false;
  }
  else
  {
    v6 = 28 * nCount;
    result = (BrushArrayInstanceData_t *)this->m_pRenderContext->LockRenderData(
                                           this: this->m_pRenderContext,
                                           a2: 28 * nCount);
    nCounta = result;
    if ( pSrcData != nullptr && result != nullptr )
    {
      memcpy(dst: (unsigned __int8 *)result, src: (unsigned __int8 *)pSrcData, count: v6);
      result = nCounta;
    }
    this->m_pRenderData = result;
    this->m_bNeedsUnlock = true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10115F80
// Name: public: virtual void CFunctor3<void (*)(int,struct BrushArrayInstanceData_t const __near *,int),int,struct BrushArrayInstanceData_t const __near *,int,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFunctor3<void (__cdecl *)(int,BrushArrayInstanceData_t const *,int),int,BrushArrayInstanceData_t const *,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>>::operator()(
        CFunctor3<void (__cdecl*)(int,BrushArrayInstanceData_t const *,int),int,BrushArrayInstanceData_t const *,int,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > > *this)
{
  this->m_pfnProxied(a1: this->m_arg1, a2: this->m_arg2, a3: this->m_arg3);
}

//------------------------------------------------------------------------------
// Address: 0x10115FA0
// Name: void R_DrawBrushModelArray(int,struct BrushArrayInstanceData_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl R_DrawBrushModelArray(int nCount, const BrushArrayInstanceData_t *pInstanceData, int nModelTypeFlags)
{
  IMatRenderContext *v3; // esi

  v3 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v3 != nullptr )
    v3->BeginRender(this: v3);
  R_DrawBrushModelArray(pRenderContext: v3, nCount, pInstanceData, nModelTypeFlags);
  if ( v3 != nullptr )
  {
    v3->EndRender(this: v3);
    v3->Release(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10116000
// Name: void V_RenderVGuiOnly_NoSwap(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl V_RenderVGuiOnly_NoSwap()
{
  IMatRenderContext *v0; // esi
  IEngineVGuiInternal *v1; // eax

  UpdateMaterialSystemConfig();
  v0 = materials->GetRenderContext(this: materials);
  if ( v0 != nullptr )
    v0->BeginRender(this: v0);
  v0->AntiAliasingHint(this: v0, a2: 8);
  v0->ClearBuffers(this: v0, a2: true, a3: true, a4: false);
  ((void (__thiscall *)(IMatRenderContext *, int))v0->__vftable[1].AddRef)(a1: v0, a2: 1);
  v0->__vftable[1].BeginRender(this: v0);
  v1 = EngineVGui();
  v1->Paint(this: v1, a2: PAINT_UIPANELS);
  v0->EndRender(this: v0);
  v0->Release(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x10116080
// Name: void V_RenderVGuiOnly(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl V_RenderVGuiOnly()
{
  IEngineVGuiInternal *v0; // eax

  ((void (__stdcall *)(_DWORD))materials->BeginFrame)(a1: LODWORD(host_frametime));
  v0 = EngineVGui();
  v0->Simulate(this: v0);
  g_EngineRenderer->FrameBegin(this: g_EngineRenderer);
  toolframework->RenderFrameBegin(this: toolframework);
  V_RenderVGuiOnly_NoSwap();
  toolframework->RenderFrameEnd(this: toolframework);
  g_EngineRenderer->FrameEnd(this: g_EngineRenderer);
  materials->EndFrame(this: materials);
  Shader_SwapBuffers();
}

//------------------------------------------------------------------------------
// Address: 0x101162A0
// Name: public: virtual void CVRenderView::DrawBrushModelArray(class IMatRenderContext __near *,int,struct BrushArrayInstanceData_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVRenderView::DrawBrushModelArray(
        CVRenderView *this,
        IMatRenderContext *pRenderContext,
        int nCount,
        BrushArrayInstanceData_t *pInstanceData,
        int nModelTypeFlags)
{
  ICallQueue *v5; // ebx
  bool (__thiscall *IsRenderData)(IMatRenderContext *, const void *); // edx
  BrushArrayInstanceData_t *v7; // edi
  CMatRenderData<BrushArrayInstanceData_t> brushArrayData; // [esp+8h] [ebp-10h] BYREF

  v5 = pRenderContext->GetCallQueue(this: pRenderContext);
  if ( v5 != nullptr && r_brush_queue_mode.m_pParent != nullptr && r_brush_queue_mode.m_pParent->m_Value.m_nValue != 0 )
  {
    IsRenderData = pRenderContext->IsRenderData;
    v7 = pInstanceData;
    memset(&brushArrayData.m_pRenderData, 0, 9);
    brushArrayData.m_pRenderContext = pRenderContext;
    if ( !IsRenderData(this: pRenderContext, a2: pInstanceData) )
      pInstanceData = CMatRenderData<BrushArrayInstanceData_t>::Lock(this: &brushArrayData, nCount, pSrcData: v7);
    ICallQueue::QueueCall<void,int,BrushArrayInstanceData_t const *,int,int,BrushArrayInstanceData_t const *,int>(
      this: v5,
      pfnProxied: R_DrawBrushModelArray,
      arg1: &nCount,
      arg2: (const BrushArrayInstanceData_t *const *)&pInstanceData,
      arg3: &nModelTypeFlags);
    CMatRenderData<memhandle_t__ *>::~CMatRenderData<memhandle_t__ *>(this: (CMatRenderData<matrix3x4a_t> *)&brushArrayData);
  }
  else
  {
    R_DrawBrushModelArray(pRenderContext, nCount, pInstanceData, nModelTypeFlags);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10115660
// Name: __CreateCVRenderViewIVRenderView_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVRenderView *__cdecl _CreateCVRenderViewIVRenderView_interface()
{
  return &s_RenderView;
}

} // namespace engine_xlsp
