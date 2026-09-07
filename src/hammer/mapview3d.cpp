// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mapview3d.cpp
// Functions: 310
// ============================================================

#include "hammer\mapview3d.h"

//------------------------------------------------------------------------------
// Address: 0x10081B10
// Name: public: virtual struct CRuntimeClass __near * CMapView3D::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMapView3D::GetRuntimeClass(CMapView3D *this)
{
  return &CMapView3D::classCMapView3D;
}

//------------------------------------------------------------------------------
// Address: 0x10081B20
// Name: protected: CMapView3D::CMapView3D(void)
// Source: json
//------------------------------------------------------------------------------
CMapView3D *__thiscall CMapView3D::CMapView3D(CMapView3D *this)
{
  CView::CView(this);
  CMapView::CMapView(this: &this->CMapView);
  this->CView::CWnd::CCmdTarget::CObject::__vftable = (CMapView3D_vtbl *)&CMapView3D::`vftable'{for `CView'};
  this->CMapView::__vftable = (CMapView_vtbl *)&CMapView3D::`vftable'{for `CMapView'};
  this->m_ptLastMouseMovement.x = 0;
  this->m_ptLastMouseMovement.y = 0;
  CKeyboard::CKeyboard(this: &this->m_Keyboard);
  this->m_eDrawType = VIEW3D_WIREFRAME;
  this->m_pRender = nullptr;
  this->m_pCamera = nullptr;
  this->m_dwTimeLastInputSample = 0;
  this->m_fForwardSpeed = 0.0;
  this->m_fStrafeSpeed = 0.0;
  this->m_fVerticalSpeed = 0.0;
  this->m_pwndTitle = nullptr;
  this->m_bLightingPreview = false;
  *(_WORD *)&this->m_bMouseLook = 0;
  this->m_bRotating = false;
  this->m_ptLastMouseMovement.x = 0;
  this->m_ptLastMouseMovement.y = 0;
  this->m_nLastRaytracedBitmapRenderTimeStamp = -1;
  *(_WORD *)&this->m_bCameraPosChanged = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10081C10
// Name: public: virtual class CMapDoc __near * CMapView3D::GetMapDoc(void)
// Source: json
//------------------------------------------------------------------------------
CMapDoc *__thiscall CMapView3D::GetMapDoc(CMapView2DBase *this)
{
  return *((CMapDoc **)this - 2);
}

//------------------------------------------------------------------------------
// Address: 0x10081C30
// Name: public: virtual CMapView3D::~CMapView3D(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::~CMapView3D(CMapView3D *this)
{
  CCamera *m_pCamera; // ecx
  CRender3D *m_pRender; // ecx
  CRender3D *v4; // ecx
  CTitleWnd *m_pwndTitle; // ecx

  this->CView::CWnd::CCmdTarget::CObject::__vftable = (CMapView3D_vtbl *)&CMapView3D::`vftable'{for `CView'};
  this->CMapView::__vftable = (CMapView_vtbl *)&CMapView3D::`vftable'{for `CMapView'};
  m_pCamera = this->m_pCamera;
  if ( m_pCamera != nullptr )
    ((void (__thiscall *)(CCamera *, int))m_pCamera->dtr_CCamera)(a1: m_pCamera, a2: 1);
  m_pRender = this->m_pRender;
  if ( m_pRender != nullptr )
  {
    CRender3D::ShutDown(this: m_pRender);
    v4 = this->m_pRender;
    if ( v4 != nullptr )
      ((void (__thiscall *)(CRender3D *, int))v4->dtr_CRender)(a1: v4, a2: 1);
  }
  m_pwndTitle = this->m_pwndTitle;
  if ( m_pwndTitle != nullptr )
    ((void (__thiscall *)(CTitleWnd *, int))m_pwndTitle->dtr_CObject)(a1: m_pwndTitle, a2: 1);
  CDmeFXClip::OnDestruction(this: (vgui::ToolWindow *)&this->m_Keyboard);
  CView::~CView(this);
}

//------------------------------------------------------------------------------
// Address: 0x10081CE0
// Name: public: virtual void CMapView3D::SetDrawType(enum DrawType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::SetDrawType(CMapView3D *this, DrawType_t eDrawType)
{
  CMainFrame *MainWnd; // eax
  CTitleWnd *m_nModalResult; // ecx
  DrawType_t v5; // edi
  EditorRenderMode_t v6; // eax
  CMainFrame *v7; // eax
  CRender *m_pDropTarget; // ecx

  if ( this->m_nFlags == 7 )
  {
    MainWnd = GetMainWnd();
    if ( MainWnd != nullptr )
      CWnd::ShowWindow(this: &MainWnd->m_SmoothingGroupDlg, nCmdShow: 0);
  }
  m_nModalResult = (CTitleWnd *)this->m_nModalResult;
  if ( m_nModalResult != nullptr )
    CTitleWnd::SetTitle(this: m_nModalResult, pszTitle: "camera");
  v5 = eDrawType;
  LOBYTE(this->m_pfnSuper) = 0;
  switch ( eDrawType )
  {
    case VIEW3D_WIREFRAME:
      goto $LN11_14;
    case VIEW3D_POLYGON:
      v6 = RENDER_MODE_FLAT;
      break;
    case VIEW3D_TEXTURED:
      v6 = RENDER_MODE_TEXTURED;
      break;
    case VIEW3D_LIGHTMAP_GRID:
      v6 = RENDER_MODE_LIGHTMAP_GRID;
      break;
    case VIEW3D_SMOOTHING_GROUP:
      v7 = GetMainWnd();
      if ( v7 != nullptr )
        CWnd::ShowWindow(this: &v7->m_SmoothingGroupDlg, nCmdShow: 5);
      *(_DWORD *)&this->GetTypeLibCache(this)[14].m_guidInfo.Data2 = 0;
      v6 = RENDER_MODE_SMOOTHING_GROUP;
      break;
    case VIEW3D_TEXTURED_SHADED:
      v6 = RENDER_MODE_TEXTURED_SHADED;
      break;
    case VIEW3D_LIGHTING_PREVIEW2:
      v6 = RENDER_MODE_LIGHT_PREVIEW2;
      break;
    case VIEW3D_LIGHTING_PREVIEW_RAYTRACED:
      v6 = RENDER_MODE_LIGHT_PREVIEW_RAYTRACED;
      break;
    default:
      v5 = VIEW3D_WIREFRAME;
$LN11_14:
      v6 = RENDER_MODE_WIREFRAME;
      break;
  }
  m_pDropTarget = (CRender *)this->m_pDropTarget;
  this->m_nFlags = v5;
  if ( m_pDropTarget != nullptr )
  {
    CRender::SetDefaultRenderMode(this: m_pDropTarget, eRenderMode: v6);
    ((void (__thiscall *)(COleDropTarget *, _DWORD))this->m_pDropTarget->GetTypeLib)(
      a1: this->m_pDropTarget,
      a2: LOBYTE(this->m_pfnSuper));
    CRender3D::ResetFocus(this: (CRender3D *)this->m_pDropTarget);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10081DF0
// Name: public: void CMapView3D::SetCamera(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::SetCamera(CMapView3D *this, const Vector *vecPos, const Vector *vecLookAt)
{
  CCamera::SetViewPoint(this: this->m_pCamera, ViewPoint: vecPos);
  CCamera::SetViewTarget(this: this->m_pCamera, a2: (int)this, ViewTarget: vecLookAt);
}

//------------------------------------------------------------------------------
// Address: 0x10081E20
// Name: protected: virtual int CMapView3D::OnPreparePrinting(struct CPrintInfo __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapView3D::OnPreparePrinting(CMapView3D *this, CPrintInfo *pInfo)
{
  return CView::DoPreparePrinting(this, pInfo);
}

//------------------------------------------------------------------------------
// Address: 0x10081E30
// Name: private: void CMapView3D::InitializeKeyMap(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::InitializeKeyMap(CMapView3D *this)
{
  CKeyboard *p_m_Keyboard; // esi

  p_m_Keyboard = &this->m_Keyboard;
  CKeyboard::RemoveAllKeyMaps(this: &this->m_Keyboard);
  if ( Options.view2d.bNudge == 0 )
  {
    CKeyboard::AddKeyMap(this: p_m_Keyboard, uChar: 0x25u, uModifierKeys: 0, uLogicalKey: 8u);
    CKeyboard::AddKeyMap(this: p_m_Keyboard, uChar: 0x27u, uModifierKeys: 0, uLogicalKey: 9u);
    CKeyboard::AddKeyMap(this: p_m_Keyboard, uChar: 0x28u, uModifierKeys: 0, uLogicalKey: 7u);
    CKeyboard::AddKeyMap(this: p_m_Keyboard, uChar: 0x26u, uModifierKeys: 0, uLogicalKey: 6u);
    CKeyboard::AddKeyMap(this: p_m_Keyboard, uChar: 0x25u, uModifierKeys: 1u, uLogicalKey: 2u);
    CKeyboard::AddKeyMap(this: p_m_Keyboard, uChar: 0x27u, uModifierKeys: 1u, uLogicalKey: 3u);
    CKeyboard::AddKeyMap(this: p_m_Keyboard, uChar: 0x28u, uModifierKeys: 1u, uLogicalKey: 5u);
    CKeyboard::AddKeyMap(this: p_m_Keyboard, uChar: 0x26u, uModifierKeys: 1u, uLogicalKey: 4u);
  }
  if ( Options.view3d.bUseMouseLook != 0 )
  {
    CKeyboard::AddKeyMap(this: p_m_Keyboard, uChar: 0x57u, uModifierKeys: 0, uLogicalKey: 0);
    CKeyboard::AddKeyMap(this: p_m_Keyboard, uChar: 0x41u, uModifierKeys: 0, uLogicalKey: 2u);
    CKeyboard::AddKeyMap(this: p_m_Keyboard, uChar: 0x44u, uModifierKeys: 0, uLogicalKey: 3u);
    CKeyboard::AddKeyMap(this: p_m_Keyboard, uChar: 0x53u, uModifierKeys: 0, uLogicalKey: 1u);
  }
  else
  {
    CKeyboard::AddKeyMap(this: p_m_Keyboard, uChar: 0x44u, uModifierKeys: 0, uLogicalKey: 0);
    CKeyboard::AddKeyMap(this: p_m_Keyboard, uChar: 0x43u, uModifierKeys: 0, uLogicalKey: 1u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10081F10
// Name: protected: void CMapView3D::OnContextMenu(class CWnd __near *,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::OnContextMenu(CMapView3D *this, CWnd *pWnd, CPoint point)
{
  CToolManager *m_pToolManager; // ecx
  int ActiveTool; // eax
  void (__thiscall *v6)(int, CMapView3D *, _DWORD, float *); // edx
  float v7[2]; // [esp+4h] [ebp-8h] BYREF

  m_pToolManager = this->m_pToolManager;
  if ( m_pToolManager != nullptr )
  {
    ActiveTool = CToolManager::GetActiveTool(this: (CSelection *)m_pToolManager);
    if ( ActiveTool != 0 )
    {
      v6 = *(void (__thiscall **)(int, CMapView3D *, _DWORD, float *))(*(_DWORD *)ActiveTool + 56);
      v7[0] = (float)point.x;
      v7[1] = (float)point.y;
      v6(a1: ActiveTool, a2: this, a3: 0, a4: v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10081F60
// Name: class Vector const __near & ClosestAxis(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
const Vector *__cdecl ClosestAxis(const Vector *v)
{
  float z; // eax
  float v2; // xmm1_4
  const Vector *result; // eax
  Vector vNormal; // [esp+0h] [ebp-1Ch] BYREF
  float fBestDot; // [esp+Ch] [ebp-10h]
  int v6; // [esp+18h] [ebp-4h]

  if ( (_S2_1 & 1) == 0 )
  {
    _S2_1 |= 1u;
    v6 = -1;
  }
  z = v->z;
  fBestDot = -1.0;
  *(_QWORD *)&vNormal.x = *(_QWORD *)&v->x;
  vNormal.z = z;
  VectorNormalize(vec: &vNormal);
  vBestAxis.x = 0.0;
  vBestAxis.y = 0.0;
  vBestAxis.z = 0.0;
  v2 = (float)((float)(v->y * 0.0) + v->x) + (float)(v->z * 0.0);
  if ( v2 <= -1.0 )
  {
    v2 = fBestDot;
  }
  else
  {
    vBestAxis.x = 1.0;
    vBestAxis.y = 0.0;
    vBestAxis.z = 0.0;
  }
  if ( (float)((float)((float)(v->x * 0.0) + v->y) + (float)(v->z * 0.0)) > v2 )
  {
    v2 = (float)((float)(v->x * 0.0) + v->y) + (float)(v->z * 0.0);
    vBestAxis.x = 0.0;
    vBestAxis.y = 1.0;
    vBestAxis.z = 0.0;
  }
  if ( (float)((float)((float)(v->y + v->x) * 0.0) + v->z) > v2 )
  {
    v2 = (float)((float)(v->y + v->x) * 0.0) + v->z;
    vBestAxis.x = 0.0;
    vBestAxis.y = 0.0;
    vBestAxis.z = 1.0;
  }
  if ( (float)((float)((float)(v->y * 0.0) - (float)(v->x * 1.0)) + (float)(v->z * 0.0)) > v2 )
  {
    v2 = (float)((float)(v->y * 0.0) - (float)(v->x * 1.0)) + (float)(v->z * 0.0);
    vBestAxis.x = -1.0;
    vBestAxis.y = 0.0;
    vBestAxis.z = 0.0;
  }
  if ( (float)((float)((float)(v->x * 0.0) - (float)(v->y * 1.0)) + (float)(v->z * 0.0)) > v2 )
  {
    v2 = (float)((float)(v->x * 0.0) - (float)(v->y * 1.0)) + (float)(v->z * 0.0);
    vBestAxis.x = 0.0;
    vBestAxis.y = -1.0;
    vBestAxis.z = 0.0;
  }
  result = &vBestAxis;
  if ( (float)((float)((float)(v->y + v->x) * 0.0) - (float)(v->z * 1.0)) > v2 )
  {
    vBestAxis.x = 0.0;
    vBestAxis.y = 0.0;
    vBestAxis.z = -1.0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10082170
// Name: public: virtual void CMapView3D::GetBestTransformPlane(class Vector __near &,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::GetBestTransformPlane(
        CMapView3D *this,
        Vector *horzAxis,
        Vector *vertAxis,
        Vector *thirdAxis)
{
  Vector vAxis; // [esp+4h] [ebp-Ch] BYREF

  CCamera::GetViewRight(this: (CCamera *)this->m_xDispatch.m_vtbl, ViewRight: &vAxis);
  *horzAxis = *ClosestAxis(v: &vAxis);
  CMapPoint::GetOrigin(this: (CCamera *)this->m_xDispatch.m_vtbl, ViewUp: &vAxis);
  *vertAxis = *ClosestAxis(v: &vAxis);
  CCamera::GetViewForward(this: (CCamera *)this->m_xDispatch.m_vtbl, ViewForward: &vAxis);
  *thirdAxis = *ClosestAxis(v: &vAxis);
}

//------------------------------------------------------------------------------
// Address: 0x10082210
// Name: public: void CMapView3D::UpdateCameraVariables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::UpdateCameraVariables(CMapView3D *this)
{
  CBaseTool *ToolForID; // eax
  Camera3D *v3; // eax
  CCamera *m_pCamera; // ecx
  Camera3D *v5; // edi
  Vector viewPoint; // [esp+8h] [ebp-18h] BYREF
  Vector viewForward; // [esp+14h] [ebp-Ch] BYREF

  ToolForID = CToolManager::GetToolForID(this: this->m_pToolManager, eToolID: TOOL_CAMERA);
  v3 = (Camera3D *)__RTDynamicCast(
                     inptr: ToolForID,
                     VfDelta: 0,
                     SrcType: &CBaseTool `RTTI Type Descriptor',
                     TargetType: &Camera3D `RTTI Type Descriptor',
                     isReference: 0);
  m_pCamera = this->m_pCamera;
  v5 = v3;
  if ( m_pCamera != nullptr && v3 != nullptr )
  {
    CCamera::GetViewPoint(this: m_pCamera, ViewPoint: &viewPoint);
    CCamera::GetViewForward(this: this->m_pCamera, ViewForward: &viewForward);
    Camera3D::UpdateActiveCamera(this: v5, vViewPos: &viewPoint, vDir: &viewForward);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10082280
// Name: protected: void CMapView3D::OnLButtonDblClk(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::OnLButtonDblClk(CMapView3D *this, unsigned int nFlags, CPoint point)
{
  CToolManager *m_pToolManager; // ecx
  int ActiveTool; // eax
  void (__thiscall *v6)(int, CMapView3D *, unsigned int, Vector2D *); // edx
  Vector2D vPoint; // [esp+4h] [ebp-8h] BYREF

  if ( GetAsyncKeyState(vKey: 32) >= 0 )
  {
    m_pToolManager = this->m_pToolManager;
    if ( m_pToolManager != nullptr )
    {
      ActiveTool = CToolManager::GetActiveTool(this: (CSelection *)m_pToolManager);
      if ( ActiveTool != 0 )
      {
        v6 = *(void (__thiscall **)(int, CMapView3D *, unsigned int, Vector2D *))(*(_DWORD *)ActiveTool + 68);
        vPoint.x = (float)point.x;
        vPoint.y = (float)point.y;
        v6(a1: ActiveTool, a2: this, a3: nFlags, a4: &vPoint);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100822F0
// Name: protected: void CMapView3D::OnView3dWireframe(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::OnView3dWireframe(CMapView3D *this)
{
  this->SetDrawType(this: &this->CMapView, a2: VIEW3D_WIREFRAME);
}

//------------------------------------------------------------------------------
// Address: 0x10082300
// Name: protected: void CMapView3D::OnView3dPolygon(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::OnView3dPolygon(CMapView3D *this)
{
  this->SetDrawType(this: &this->CMapView, a2: VIEW3D_POLYGON);
}

//------------------------------------------------------------------------------
// Address: 0x10082310
// Name: protected: void CMapView3D::OnView3dTextured(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::OnView3dTextured(CMapView3D *this)
{
  this->SetDrawType(this: &this->CMapView, a2: VIEW3D_TEXTURED);
}

//------------------------------------------------------------------------------
// Address: 0x10082320
// Name: protected: void CMapView3D::OnView3dLightmapGrid(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::OnView3dLightmapGrid(CMapView3D *this)
{
  this->SetDrawType(this: &this->CMapView, a2: VIEW3D_LIGHTMAP_GRID);
}

//------------------------------------------------------------------------------
// Address: 0x10082330
// Name: protected: void CMapView3D::OnView3dLightingPreview(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::OnView3dLightingPreview(CMapView3D *this)
{
  this->SetDrawType(this: &this->CMapView, a2: VIEW3D_LIGHTING_PREVIEW2);
}

//------------------------------------------------------------------------------
// Address: 0x10082340
// Name: protected: void CMapView3D::OnView3dLightingPreviewRayTraced(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::OnView3dLightingPreviewRayTraced(CMapView3D *this)
{
  this->SetDrawType(this: &this->CMapView, a2: VIEW3D_LIGHTING_PREVIEW_RAYTRACED);
}

//------------------------------------------------------------------------------
// Address: 0x10082350
// Name: public: virtual void CMapView3D::ActivateView(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::ActivateView(CMapView3D *this, bool bActivate)
{
  CMapDoc *v3; // edi

  CMapView::ActivateView((CMapView *)this, bActivate);
  if ( bActivate )
  {
    v3 = (CMapDoc *)this->GetTypeLibCache(this);
    CMapDoc::SetActiveMapDoc(pDoc: v3);
    if ( IsWindow(hWnd: *((HWND *)this - 23)) )
    {
      SetStatusText(nIndex: 4, pszText: &var);
      SetStatusText(nIndex: 2, pszText: &var);
    }
    CMapDoc::UpdateTitle(this: v3, pView: (CMapView3D *)((char *)this - 124));
    CKeyboard::ClearKeyStates(this: (CKeyboard *)&this->m_pCtrlCont);
    this->m_xAccessible.CView::CWnd::__vftable = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100823D0
// Name: public: virtual bool CMapView3D::ShouldRender(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapView3D::ShouldRender(CMapView3D *this)
{
  if ( this->m_nFlags != 12
    && Options.view3d.bAnimateModels != 0
    && (double)(timeGetTime() - this->m_xInnerUnknown) * 0.001 > 0.050000001 )
  {
    BYTE1(this->m_dwRef) = 1;
  }
  return CMapView::ShouldRender((CMapView *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10082430
// Name: protected: void CMapView3D::OnSetFocus(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::OnSetFocus(CMapView3D *this, CWnd *pOldWnd)
{
  this->m_bUpdateView = true;
}

//------------------------------------------------------------------------------
// Address: 0x10082440
// Name: protected: void CMapView3D::OnNcPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::OnNcPaint(CMapView3D *this)
{
  this->m_bUpdateView = true;
}

//------------------------------------------------------------------------------
// Address: 0x10082450
// Name: public: virtual void CMapView3D::UpdateView(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::UpdateView(CMapView3D *this, __int16 nFlags)
{
  float v3; // xmm0_4
  float fFOV; // xmm0_4
  CTypeLibCache *v5; // eax
  COleDropTarget *m_pDropTarget; // ecx

  if ( this->m_pDropTarget != nullptr && (nFlags & 0xA0) == 0 )
  {
    if ( (nFlags & 0x100) != 0 )
    {
      CMapView3D::InitializeKeyMap(this: (CMapView3D *)((char *)this - 124));
      CMapStudioModel::SetRenderDistance(fRenderDistance: (float)Options.view3d.nModelDistance);
      CMapStudioModel::EnableAnimation(bEnable: Options.view3d.bAnimateModels);
      CRender3D::RenderEnable(
        this: (CRender3D *)this->m_pDropTarget,
        eRenderState: RENDER_REVERSE_SELECTION,
        bEnable: Options.view3d.bReverseSelection == 1);
      *(float *)&this->m_ptGestureFrom.y = (float)Options.view3d.nForwardSpeedMax;
      *(float *)&this->m_ulGestureArg = (float)Options.view3d.nForwardSpeedMax * 0.75;
      *((float *)&this->m_ulGestureArg + 1) = (float)Options.view3d.nForwardSpeedMax * 0.5;
      if ( Options.view3d.nTimeToMaxSpeed != 0 )
      {
        *(float *)&this->m_bGestureInited = *(float *)&this->m_ptGestureFrom.y
                                          / (float)((float)Options.view3d.nTimeToMaxSpeed * 0.001);
        *(float *)&this->m_pCurrentGestureInfo = *(float *)&this->m_ulGestureArg
                                               / (float)((float)Options.view3d.nTimeToMaxSpeed * 0.001);
        v3 = *((float *)&this->m_ulGestureArg + 1) / (float)((float)Options.view3d.nTimeToMaxSpeed * 0.001);
      }
      else
      {
        v3 = 0.0;
        this->m_bGestureInited = 0;
        this->m_pCurrentGestureInfo = nullptr;
      }
      *(float *)&this->m_hWndOwner = v3;
      if ( CMapEntity::s_bShowDotACamera )
        fFOV = 65.0;
      else
        fFOV = Options.view3d.fFOV;
      CCamera::SetPerspective(
        this: (CCamera *)this->m_xDispatch.m_vtbl,
        fHorizontalFOV: fFOV,
        fNearClip: 8.0,
        fFarClip: (float)Options.view3d.iBackPlane);
      v5 = this->GetTypeLibCache(this);
      if ( v5 != nullptr )
      {
        m_pDropTarget = this->m_pDropTarget;
        if ( m_pDropTarget != nullptr )
        {
          CRender3D::RenderEnable(
            this: (CRender3D *)m_pDropTarget,
            eRenderState: RENDER_GRID,
            bEnable: (bool)v5[13].m_ptlib);
          CRender3D::RenderEnable(
            this: (CRender3D *)this->m_pDropTarget,
            eRenderState: RENDER_FILTER_TEXTURES,
            bEnable: Options.view3d.bFilterTextures == 1);
        }
      }
    }
    CMapView::UpdateView((CMapView *)this, nFlags);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10082610
// Name: public: virtual bool CMapView3D::HitTest(class Vector2D const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapView3D::HitTest(CMapView3D *this, const Vector2D *vPoint, const Vector *mins, const Vector *maxs)
{
  Vector vStart; // [esp+0h] [ebp-18h] BYREF
  Vector vEnd; // [esp+Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  ((void (__thiscall *)(CMapView3D *, const Vector2D *, Vector *, Vector *))this->GetDispatchMap)(
    a1: this,
    a2: vPoint,
    a3: &vStart,
    a4: &vEnd);
  return IntersectionLineAABBox(a1: (int)&savedregs, mins, maxs, &vStart, &vEnd, nFace: (int *)&vPoint) >= 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10082670
// Name: public: virtual int CMapView3D::ObjectsAt(class Vector2D const __near &,struct HitInfo_s __near *,int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapView3D::ObjectsAt(
        CMapView3D *this,
        const Vector2D *vPoint,
        HitInfo_s *pObjects,
        int nMaxObjects,
        unsigned int nFlags)
{
  COleDropTarget *m_pDropTarget; // ecx

  m_pDropTarget = this->m_pDropTarget;
  if ( m_pDropTarget != nullptr )
    return CRender3D::ObjectsAt(
             this: (CRender3D *)m_pDropTarget,
             x: vPoint->x,
             y: vPoint->y,
             fWidth: 1.0,
             fHeight: 1.0,
             pObjects,
             nMaxObjects,
             nFlags);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100826D0
// Name: public: void CMapView3D::RenderPreloadObject(class CMapAtom __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::RenderPreloadObject(CMapView3D *this, CMapAtom *pObject)
{
  CRender3D *m_pRender; // eax

  if ( pObject != nullptr )
  {
    m_pRender = this->m_pRender;
    if ( m_pRender != nullptr )
      ((void (__stdcall *)(CRender3D *, _DWORD))pObject->RenderPreload)(a1: m_pRender, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10082700
// Name: public: void CMapView3D::ReleaseVideoMemory(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::ReleaseVideoMemory(CMapView3D *this)
{
  CDmeFXClip::OnDestruction(this: (vgui::ToolWindow *)this->m_pRender);
}

//------------------------------------------------------------------------------
// Address: 0x10082710
// Name: public: virtual void CMapView3D::WorldToClient(class Vector2D __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::WorldToClient(CMapView3D *this, Vector2D *vClient, const Vector *vWorld)
{
  CCamera::WorldToView(this: (CCamera *)this->m_xDispatch.m_vtbl, vWorld, vView: vClient);
}

//------------------------------------------------------------------------------
// Address: 0x10082730
// Name: public: virtual void CMapView3D::ClientToWorld(class Vector __near &,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::ClientToWorld(CMapView3D *this, Vector *vWorld, const Vector2D *vClient)
{
  CCamera::ViewToWorld(this: (CCamera *)this->m_xDispatch.m_vtbl, vView: vClient, vWorld);
}

//------------------------------------------------------------------------------
// Address: 0x10082750
// Name: public: virtual long CMapView3D::WindowProc(unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapView3D::WindowProc(CMapView3D *this, unsigned int message, unsigned int wParam, int lParam)
{
  if ( message == 8 )
    CKeyboard::ClearKeyStates(this: &this->m_Keyboard);
  return CWnd::WindowProc(this, message, wParam, lParam);
}

//------------------------------------------------------------------------------
// Address: 0x10082780
// Name: public: static class CObject __near * CMapView3D::CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CMapView3D *__stdcall CMapView3D::CreateObject()
{
  CMapView3D *v0; // eax

  v0 = (CMapView3D *)operator new(nSize: 0x14ECu);
  if ( v0 != nullptr )
    return CMapView3D::CMapView3D(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10082810
// Name: protected: void CMapView3D::OnTimer(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::OnTimer(CMapView3D *this, unsigned int nIDEvent)
{
  CMapDoc *(__thiscall *GetMapDoc)(CMapView *); // edx
  int v4; // eax

  if ( nIDEvent == 0 && !s_bPicking )
  {
    GetMapDoc = this->GetMapDoc;
    s_bPicking = true;
    v4 = (int)GetMapDoc(this: &this->CMapView);
    CSelection::SetCurrentHit(this: *(CSelection **)(v4 + 440), iIndex: -1, bCascading: false);
    s_bPicking = false;
  }
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x10082860
// Name: public: virtual int CMapView3D::DestroyWindow(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapView3D::DestroyWindow(CMapView3D *this)
{
  KillTimer(hWnd: this->m_hWnd, uIDEvent: 0);
  return CWnd::DestroyWindow(this);
}

//------------------------------------------------------------------------------
// Address: 0x10082880
// Name: protected: void CMapView3D::OnKeyUp(unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::OnKeyUp(CMapView3D *this, unsigned int nChar, unsigned int nRepCnt, unsigned int nFlags)
{
  CToolManager *m_pToolManager; // ecx
  int ActiveTool; // eax

  m_pToolManager = this->m_pToolManager;
  if ( m_pToolManager == nullptr )
    goto LABEL_5;
  ActiveTool = CToolManager::GetActiveTool(this: (CSelection *)m_pToolManager);
  if ( ActiveTool == 0
    || (*(unsigned __int8 (__thiscall **)(int, CMapView3D *, unsigned int, unsigned int, unsigned int))(*(_DWORD *)ActiveTool + 92))(
         a1: ActiveTool,
         a2: this,
         a3: nChar,
         a4: nRepCnt,
         a5: nFlags) == 0 )
  {
    CKeyboard::OnKeyUp(this: &this->m_Keyboard, nChar, nRepCnt, nFlags);
    CMapView3D::UpdateCameraVariables(this);
LABEL_5:
    CWnd::Default(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100828E0
// Name: protected: void CMapView3D::OnSize(unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::OnSize(CMapView3D *this, unsigned int nType, int cx, int cy)
{
  CCamera *m_pCamera; // ecx

  m_pCamera = this->m_pCamera;
  if ( m_pCamera != nullptr )
    CCamera::SetViewPort(this: m_pCamera, width: cx, height: cy);
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x10082910
// Name: public: void CMapView3D::BeginPick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::BeginPick(CMapView3D *this)
{
  SetTimer(hWnd: this->m_hWnd, nIDEvent: 0, uElapse: 0x1F4u, lpTimerFunc: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10082930
// Name: public: void CMapView3D::EndPick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::EndPick(CMapView3D *this)
{
  KillTimer(hWnd: this->m_hWnd, uIDEvent: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10082940
// Name: public: virtual void CMapView3D::OnInitialUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::OnInitialUpdate(CMapView3D *this)
{
  CTitleWnd *TitleWnd; // eax
  CRender3D *v3; // eax
  CRender3D *v4; // eax
  CMapDoc *v5; // ebx
  DrawType_t m_eDrawType; // ecx
  CCamera *v7; // eax
  CCamera *v8; // eax
  float v9; // xmm0_4
  float fHorizontalFOV; // xmm0_4
  CBaseTool *ToolForID; // eax
  Camera3D *v12; // eax
  HWND__ *fNearClip; // [esp+4h] [ebp-4Ch]
  tagRECT Rect; // [esp+18h] [ebp-38h] BYREF
  Vector vLookAt; // [esp+28h] [ebp-28h] BYREF
  CRect rect; // [esp+34h] [ebp-1Ch] BYREF
  Vector vecLookAt; // [esp+44h] [ebp-Ch]

  CMapView3D::InitializeKeyMap(this);
  TitleWnd = CTitleWnd::CreateTitleWnd(pwndParent: this, uID: 0x70u);
  this->m_pwndTitle = TitleWnd;
  if ( TitleWnd != nullptr )
    CTitleWnd::SetTitle(this: TitleWnd, pszTitle: "camera");
  if ( this->m_pRender == nullptr )
  {
    v3 = (CRender3D *)operator new(nSize: 0x9E08u);
    rect.bottom = (int)v3;
    vecLookAt.z = 0.0;
    v4 = v3 != nullptr ? CRender3D::CRender3D(this: v3) : nullptr;
    vecLookAt.z = NAN;
    this->m_pRender = v4;
    v5 = this->GetMapDoc(this: &this->CMapView);
    if ( v5 != nullptr )
    {
      this->m_pRender->SetView(this: this->m_pRender, a2: &this->CMapView);
      m_eDrawType = this->m_eDrawType;
      this->m_pToolManager = v5->m_pToolManager;
      this->SetDrawType(this: &this->CMapView, a2: m_eDrawType);
      v7 = (CCamera *)operator new(nSize: 0x140u);
      rect.bottom = (int)v7;
      LODWORD(vecLookAt.z) = 1;
      v8 = v7 != nullptr ? CCamera::CCamera(this: v7) : nullptr;
      vecLookAt.z = NAN;
      this->m_pCamera = v8;
      if ( v8 != nullptr )
      {
        fNearClip = this->m_hWnd;
        memset(&Rect, 0, sizeof(Rect));
        GetClientRect(hWnd: fNearClip, lpRect: &Rect);
        CCamera::SetViewPort(this: this->m_pCamera, width: Rect.right - Rect.left, height: Rect.bottom - Rect.top);
        this->m_fForwardSpeedMax = (float)Options.view3d.nForwardSpeedMax;
        this->m_fStrafeSpeedMax = (float)Options.view3d.nForwardSpeedMax * 0.75;
        this->m_fVerticalSpeedMax = (float)Options.view3d.nForwardSpeedMax * 0.5;
        if ( Options.view3d.nTimeToMaxSpeed != 0 )
        {
          this->m_fForwardAcceleration = this->m_fForwardSpeedMax
                                       / (float)((float)Options.view3d.nTimeToMaxSpeed * 0.001);
          this->m_fStrafeAcceleration = this->m_fStrafeSpeedMax / (float)((float)Options.view3d.nTimeToMaxSpeed * 0.001);
          v9 = this->m_fVerticalSpeedMax / (float)((float)Options.view3d.nTimeToMaxSpeed * 0.001);
        }
        else
        {
          v9 = 0.0;
          this->m_fForwardAcceleration = 0.0;
          this->m_fStrafeAcceleration = 0.0;
        }
        this->m_fVerticalAcceleration = v9;
        if ( CMapEntity::s_bShowDotACamera )
          fHorizontalFOV = 65.0;
        else
          fHorizontalFOV = Options.view3d.fFOV;
        CCamera::SetPerspective(
          this: this->m_pCamera,
          fHorizontalFOV,
          fNearClip: 8.0,
          fFarClip: (float)Options.view3d.iBackPlane);
        CMapStudioModel::SetRenderDistance(fRenderDistance: (float)Options.view3d.nModelDistance);
        CMapStudioModel::EnableAnimation(bEnable: Options.view3d.bAnimateModels);
        CRender3D::RenderEnable(
          this: this->m_pRender,
          eRenderState: RENDER_REVERSE_SELECTION,
          bEnable: Options.view3d.bReverseSelection == 1);
        CRender3D::RenderEnable(this: this->m_pRender, eRenderState: RENDER_GRID, bEnable: v5->m_bShow3DGrid);
        CRender3D::RenderEnable(
          this: this->m_pRender,
          eRenderState: RENDER_FILTER_TEXTURES,
          bEnable: Options.view3d.bFilterTextures == 1);
        ToolForID = CToolManager::GetToolForID(this: this->m_pToolManager, eToolID: TOOL_CAMERA);
        v12 = (Camera3D *)__RTDynamicCast(
                            inptr: ToolForID,
                            VfDelta: 0,
                            SrcType: &CBaseTool `RTTI Type Descriptor',
                            TargetType: &Camera3D `RTTI Type Descriptor',
                            isReference: 0);
        if ( v12 != nullptr )
        {
          Camera3D::GetCameraPos(this: v12, vViewPos: (Vector *)&rect, &vLookAt);
          CCamera::SetViewPoint(this: this->m_pCamera, ViewPoint: (const Vector *)&rect);
          CCamera::SetViewTarget(this: this->m_pCamera, a2: (int)this, ViewTarget: &vLookAt);
        }
        CView::OnInitialUpdate(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10082C80
// Name: protected: virtual void CMapView3D::OnDraw(class CDC __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::OnDraw(CMapView3D *this, CDC *pDC)
{
  HWND ForegroundWindow; // eax
  CWnd *v4; // eax

  ForegroundWindow = GetForegroundWindow();
  v4 = CWnd::FromHandle(hWnd: ForegroundWindow);
  if ( v4 != nullptr && v4->ContinueModal(this: v4) != 0 )
    this->RenderView(this: &this->CMapView);
  else
    this->m_bUpdateView = true;
}

//------------------------------------------------------------------------------
// Address: 0x10082CC0
// Name: public: class CMapClass __near * CMapView3D::NearestObjectAt(class Vector2D const __near &,unsigned long __near &,unsigned int,class VMatrix __near *)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__thiscall CMapView3D::NearestObjectAt(
        CMapView3D *this,
        const Vector2D *vPoint,
        unsigned int *ulFace,
        unsigned int nFlags,
        VMatrix *pLocalMatrix)
{
  CRender3D *m_pRender; // ecx
  CMapClass *pObject; // edi
  void *v8; // esi
  HitInfo_s y; // [esp+20h] [ebp-4Ch] BYREF

  *ulFace = 0;
  m_pRender = this->m_pRender;
  if ( m_pRender == nullptr
    || CRender3D::ObjectsAt(
         this: m_pRender,
         x: vPoint->x,
         y: vPoint->y,
         fWidth: 1.0,
         fHeight: 1.0,
         pObjects: &y,
         nMaxObjects: 1,
         nFlags) == 0 )
  {
    return nullptr;
  }
  pObject = y.pObject;
  v8 = __RTDynamicCast(
         inptr: y.pObject,
         VfDelta: 0,
         SrcType: &CMapAtom `RTTI Type Descriptor',
         TargetType: &CMapSolid `RTTI Type Descriptor',
         isReference: 0);
  if ( pLocalMatrix != nullptr )
    VMatrix::operator=(this: pLocalMatrix, mOther: &y.m_LocalMatrix);
  if ( v8 == nullptr )
    return pObject;
  *ulFace = y.uData;
  return (CMapClass *)v8;
}

//------------------------------------------------------------------------------
// Address: 0x10082D80
// Name: protected: void CMapView3D::OnMouseMove(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::OnMouseMove(CMapView3D *this, unsigned int nFlags, CPoint point)
{
  CMapDoc *v4; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  HWND Focus; // eax

  if ( !this->m_bActive )
  {
    v4 = this->GetMapDoc(this: &this->CMapView);
    CMapDoc::SetActiveView(this: v4, pViewActivate: &this->CMapView);
  }
  ModuleState = AfxGetModuleState();
  if ( CHammer::IsActiveApp(this: (CHammer *)ModuleState->m_pCurrentWinApp) )
  {
    Focus = GetFocus();
    if ( CWnd::FromHandle(hWnd: Focus) != this )
      CWnd::SetFocus(this);
  }
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x10082DE0
// Name: private: void CMapView3D::ProcessMovementKeys(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::ProcessMovementKeys(CMapView3D *this, float fElapsedTime)
{
  float v3; // xmm6_4
  float m_fForwardAcceleration; // xmm1_4
  float m_fForwardSpeed; // xmm3_4
  float m_fForwardSpeedMax; // xmm2_4
  bool v7; // cc
  float v8; // xmm1_4
  float v9; // xmm5_4
  float v10; // xmm2_4
  float m_fStrafeAcceleration; // xmm1_4
  float m_fStrafeSpeed; // xmm3_4
  float m_fStrafeSpeedMax; // xmm2_4
  bool v14; // cc
  float v15; // xmm1_4
  float v16; // xmm2_4
  float m_fVerticalSpeed; // xmm3_4
  float m_fVerticalSpeedMax; // xmm2_4
  float m_fVerticalAcceleration; // xmm1_4
  bool v20; // cc
  float v21; // xmm1_4
  float v22; // xmm2_4
  CMapDoc *m_pDocument; // edi
  float z; // xmm3_4
  float x; // xmm1_4
  float y; // xmm0_4
  CCamera *m_pCamera; // ecx
  float v28; // xmm3_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  CCamera *v32; // ecx
  float v33; // xmm2_4
  float v34; // xmm1_4
  float v35; // xmm1_4
  Vector vDelta; // [esp+Ch] [ebp-64h] BYREF
  float v37; // [esp+18h] [ebp-58h] BYREF
  Vector vForward; // [esp+1Ch] [ebp-54h]
  Vector vNewViewpoint; // [esp+28h] [ebp-48h] BYREF
  Vector vDirection; // [esp+34h] [ebp-3Ch] BYREF
  Vector vViewpoint; // [esp+40h] [ebp-30h] BYREF
  Vector vHitLoc; // [esp+4Ch] [ebp-24h]
  float fYawLeft; // [esp+58h] [ebp-18h]
  float fYawRight; // [esp+5Ch] [ebp-14h]
  float fPitchUp; // [esp+60h] [ebp-10h]
  float fPitchDown; // [esp+64h] [ebp-Ch]
  float fBack; // [esp+68h] [ebp-8h]
  float fMoveRight; // [esp+6Ch] [ebp-4h]

  fPitchDown = CKeyboard::GetKeyScale(this: &this->m_Keyboard, uLogicalKey: 1u);
  fMoveRight = CKeyboard::GetKeyScale(this: &this->m_Keyboard, uLogicalKey: 0) - fPitchDown;
  fPitchDown = CKeyboard::GetKeyScale(this: &this->m_Keyboard, uLogicalKey: 2u);
  fBack = CKeyboard::GetKeyScale(this: &this->m_Keyboard, uLogicalKey: 3u) - fPitchDown;
  fPitchDown = CKeyboard::GetKeyScale(this: &this->m_Keyboard, uLogicalKey: 5u);
  fPitchDown = CKeyboard::GetKeyScale(this: &this->m_Keyboard, uLogicalKey: 4u) - fPitchDown;
  fYawRight = CKeyboard::GetKeyScale(this: &this->m_Keyboard, uLogicalKey: 6u);
  fPitchUp = CKeyboard::GetKeyScale(this: &this->m_Keyboard, uLogicalKey: 7u);
  vHitLoc.z = CKeyboard::GetKeyScale(this: &this->m_Keyboard, uLogicalKey: 8u);
  fYawLeft = CKeyboard::GetKeyScale(this: &this->m_Keyboard, uLogicalKey: 9u);
  v3 = fElapsedTime;
  if ( (float)(fPitchUp - fYawRight) != 0.0 )
  {
    CCamera::Pitch(this: this->m_pCamera, fDegrees: (float)((float)(fPitchUp - fYawRight) * fElapsedTime) * 180.0);
    v3 = fElapsedTime;
    this->m_bUpdateView = true;
  }
  if ( (float)(fYawLeft - vHitLoc.z) != 0.0 )
  {
    CCamera::Yaw(this: this->m_pCamera, fDegrees: (float)((float)(fYawLeft - vHitLoc.z) * v3) * 180.0);
    v3 = fElapsedTime;
    this->m_bUpdateView = true;
  }
  m_fForwardAcceleration = this->m_fForwardAcceleration;
  m_fForwardSpeed = this->m_fForwardSpeed;
  m_fForwardSpeedMax = this->m_fForwardSpeedMax;
  if ( m_fForwardAcceleration == 0.0 )
  {
    if ( fMoveRight != 0.0 )
    {
      v9 = m_fForwardSpeedMax * fMoveRight;
      goto LABEL_20;
    }
    goto LABEL_19;
  }
  if ( fMoveRight == 0.0 )
  {
LABEL_19:
    v9 = 0.0;
    goto LABEL_20;
  }
  if ( fMoveRight > 0.0 )
  {
    v7 = m_fForwardSpeed >= 0.0;
    goto LABEL_11;
  }
  if ( fMoveRight < 0.0 )
  {
    v7 = m_fForwardSpeed <= 0.0;
LABEL_11:
    if ( !v7 )
      m_fForwardSpeed = 0.0;
  }
  v8 = (float)((float)(m_fForwardAcceleration * fMoveRight) * v3) + m_fForwardSpeed;
  v9 = v8;
  if ( v8 <= m_fForwardSpeedMax )
  {
    v10 = -m_fForwardSpeedMax;
    if ( v10 > v8 )
      v9 = v10;
  }
  else
  {
    v9 = this->m_fForwardSpeedMax;
  }
LABEL_20:
  m_fStrafeAcceleration = this->m_fStrafeAcceleration;
  m_fStrafeSpeed = this->m_fStrafeSpeed;
  m_fStrafeSpeedMax = this->m_fStrafeSpeedMax;
  this->m_fForwardSpeed = v9;
  if ( m_fStrafeAcceleration == 0.0 )
  {
    if ( fBack != 0.0 )
    {
      v15 = m_fStrafeSpeedMax * fBack;
      goto LABEL_35;
    }
    goto LABEL_34;
  }
  if ( fBack == 0.0 )
  {
LABEL_34:
    v15 = 0.0;
    goto LABEL_35;
  }
  if ( fBack > 0.0 )
  {
    v14 = m_fStrafeSpeed >= 0.0;
    goto LABEL_26;
  }
  if ( fBack < 0.0 )
  {
    v14 = m_fStrafeSpeed <= 0.0;
LABEL_26:
    if ( !v14 )
      m_fStrafeSpeed = 0.0;
  }
  v15 = (float)((float)(m_fStrafeAcceleration * fBack) * v3) + m_fStrafeSpeed;
  if ( v15 <= m_fStrafeSpeedMax )
  {
    v16 = -m_fStrafeSpeedMax;
    if ( v16 > v15 )
      v15 = v16;
  }
  else
  {
    v15 = m_fStrafeSpeedMax;
  }
LABEL_35:
  m_fVerticalSpeed = this->m_fVerticalSpeed;
  m_fVerticalSpeedMax = this->m_fVerticalSpeedMax;
  this->m_fStrafeSpeed = v15;
  m_fVerticalAcceleration = this->m_fVerticalAcceleration;
  if ( m_fVerticalAcceleration == 0.0 )
  {
    if ( fPitchDown != 0.0 )
    {
      v21 = fPitchDown * m_fVerticalSpeedMax;
      goto LABEL_50;
    }
    goto LABEL_49;
  }
  if ( fPitchDown == 0.0 )
  {
LABEL_49:
    v21 = 0.0;
    goto LABEL_50;
  }
  if ( fPitchDown > 0.0 )
  {
    v20 = m_fVerticalSpeed >= 0.0;
    goto LABEL_41;
  }
  if ( fPitchDown < 0.0 )
  {
    v20 = m_fVerticalSpeed <= 0.0;
LABEL_41:
    if ( !v20 )
      m_fVerticalSpeed = 0.0;
  }
  v21 = (float)((float)(m_fVerticalAcceleration * fPitchDown) * v3) + m_fVerticalSpeed;
  if ( v21 <= m_fVerticalSpeedMax )
  {
    v22 = -m_fVerticalSpeedMax;
    if ( v22 > v21 )
      v21 = v22;
  }
  else
  {
    v21 = m_fVerticalSpeedMax;
  }
LABEL_50:
  this->m_fVerticalSpeed = v21;
  if ( CMapEntity::s_bShowDotACamera )
  {
    m_pDocument = (CMapDoc *)this->m_pDocument;
    CCamera::GetViewForward(this: this->m_pCamera, ViewForward: (Vector *)&v37);
    CCamera::GetViewPoint(this: this->m_pCamera, ViewPoint: (Vector *)&vDirection.z);
    if ( CMapDoc::PickTrace(
           this: m_pDocument,
           vPosition: (Vector *)&vDirection.z,
           vDirection: (const Vector *)&v37,
           pHitPosition: (Vector *)&vViewpoint.z) != 0 )
    {
      y = vHitLoc.y;
      x = vHitLoc.x;
      z = vViewpoint.z;
    }
    else
    {
      z = (float)(v37 * 1500.0) + vDirection.z;
      x = (float)(vForward.x * 1500.0) + vViewpoint.x;
      y = (float)(vForward.y * 1500.0) + vViewpoint.y;
      vViewpoint.z = z;
      vHitLoc.x = x;
      vHitLoc.y = y;
    }
    vNewViewpoint.z = z - vDirection.z;
    vDirection.x = x - vViewpoint.x;
    vDirection.y = y - vViewpoint.y;
    VectorNormalize(vec: (Vector *)&vNewViewpoint.z);
    m_pCamera = this->m_pCamera;
    v28 = vViewpoint.z - (float)(vNewViewpoint.z * 1500.0);
    v29 = this->m_fForwardSpeed * 2.0;
    vNewViewpoint.x = vHitLoc.x - (float)(vDirection.x * 1500.0);
    v30 = vHitLoc.y - (float)(vDirection.y * 1500.0);
    this->m_fForwardSpeed = v29;
    v31 = this->m_fStrafeSpeed * 2.0;
    vNewViewpoint.y = v30;
    vForward.z = v28;
    this->m_fStrafeSpeed = v31;
    CCamera::SetPitch(this: m_pCamera, fDegrees: 65.0);
    CCamera::SetRoll(this: this->m_pCamera, fDegrees: 0.0);
    CCamera::SetYaw(this: this->m_pCamera, fDegrees: 0.0);
    v32 = this->m_pCamera;
    v33 = this->m_fForwardSpeed * fElapsedTime;
    vDelta.x = (float)(vForward.z - vDirection.z) + (float)(this->m_fStrafeSpeed * fElapsedTime);
    vDelta.y = (float)(vNewViewpoint.x - vViewpoint.x) + v33;
    vDelta.z = vNewViewpoint.y - vViewpoint.y;
    CCamera::Move(this: v32, &vDelta);
    goto LABEL_61;
  }
  if ( v9 != 0.0 )
  {
    CCamera::MoveForward(this: this->m_pCamera, fUnits: v9 * v3);
    v3 = fElapsedTime;
    this->m_bUpdateView = true;
    this->m_bCameraPosChanged = true;
  }
  v34 = this->m_fStrafeSpeed;
  if ( v34 != 0.0 )
  {
    CCamera::MoveRight(this: this->m_pCamera, fUnits: v34 * v3);
    v3 = fElapsedTime;
    this->m_bUpdateView = true;
    this->m_bCameraPosChanged = true;
  }
  v35 = this->m_fVerticalSpeed;
  if ( v35 != 0.0 )
  {
    CCamera::MoveUp(this: this->m_pCamera, fUnits: v35 * v3);
LABEL_61:
    this->m_bCameraPosChanged = true;
    this->m_bUpdateView = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083360
// Name: private: bool CMapView3D::ControlCamera(class CPoint const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapView3D::ControlCamera(CMapView3D *this, const CPoint *point)
{
  SHORT AsyncKeyState; // ax
  HWND__ *m_hWnd; // ecx
  int v6; // edi
  int v7; // edx
  CCamera *v8; // ecx
  CCamera *m_pCamera; // ecx
  CCamera *v10; // ecx
  float fDegrees; // xmm0_4
  CCamera *v12; // ecx
  CCamera *v13; // ecx
  tagRECT Rect; // [esp+10h] [ebp-1Ch] BYREF
  tagPOINT Point; // [esp+20h] [ebp-Ch] BYREF
  CPoint WindowCenter; // [esp+28h] [ebp-4h]

  if ( !this->m_bStrafing && !this->m_bRotating && !this->m_bMouseLook )
    return 0;
  AsyncKeyState = GetAsyncKeyState(vKey: 16);
  m_hWnd = this->m_hWnd;
  memset(&Rect, 0, sizeof(Rect));
  HIBYTE(WindowCenter.x) = AsyncKeyState < 0;
  GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
  v6 = point->x - (Rect.left + Rect.right) / 2;
  v7 = point->y - (Rect.bottom + Rect.top) / 2;
  Point.x = (Rect.left + Rect.right) / 2;
  Point.y = (Rect.bottom + Rect.top) / 2;
  if ( this->m_bStrafing )
  {
    if ( HIBYTE(WindowCenter.x) != 0 || this->m_bRotating )
    {
      m_pCamera = this->m_pCamera;
      if ( m_pCamera != nullptr )
        CCamera::MoveForward(this: m_pCamera, fUnits: (float)(-2 * v7));
    }
    else
    {
      v8 = this->m_pCamera;
      if ( v8 != nullptr )
        CCamera::MoveUp(this: v8, fUnits: (float)(-2 * v7));
    }
    v10 = this->m_pCamera;
    if ( v10 != nullptr )
      CCamera::MoveRight(this: v10, fUnits: (float)(2 * v6));
    this->m_bCameraPosChanged = true;
  }
  else
  {
    if ( v7 != 0 )
    {
      fDegrees = (double)v7 * 0.4;
      if ( Options.view3d.bReverseY != 0 )
        LODWORD(fDegrees) ^= _mask__NegFloat_;
      v12 = this->m_pCamera;
      if ( v12 != nullptr )
        CCamera::Pitch(this: v12, fDegrees);
    }
    if ( v6 != 0 )
    {
      v13 = this->m_pCamera;
      if ( v13 != nullptr )
        CCamera::Yaw(this: v13, fDegrees: (double)v6 * 0.4);
    }
  }
  ClientToScreen(hWnd: this->m_hWnd, lpPoint: &Point);
  SetCursorPos(X: Point.x, Y: Point.y);
  this->m_bUpdateView = true;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10083500
// Name: private: void CMapView3D::ProcessMouse(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::ProcessMouse(CMapView3D *this)
{
  int v1; // edi
  int x; // edx
  int ActiveTool; // ebx
  void (__thiscall *v5)(int, CMapView3D *, int, Vector2D *); // edx
  Vector2D vPoint; // [esp+8h] [ebp-10h] BYREF
  CPoint point; // [esp+10h] [ebp-8h] BYREF

  v1 = 0;
  point.x = 0;
  point.y = 0;
  GetCursorPos(lpPoint: &point);
  ScreenToClient(hWnd: this->m_hWnd, lpPoint: &point);
  x = point.x;
  if ( point.x != this->m_ptLastMouseMovement.x || point.y != this->m_ptLastMouseMovement.y )
  {
    this->m_ptLastMouseMovement.y = point.y;
    this->m_ptLastMouseMovement.x = x;
    if ( CMapView3D::ControlCamera(this, &point) == 0 )
    {
      ActiveTool = CToolManager::GetActiveTool(this: (CSelection *)this->m_pToolManager);
      if ( ActiveTool != 0 )
      {
        if ( GetAsyncKeyState(vKey: 17) < 0 )
          v1 = 8;
        if ( GetAsyncKeyState(vKey: 16) < 0 )
          v1 |= 4u;
        v5 = *(void (__thiscall **)(int, CMapView3D *, int, Vector2D *))(*(_DWORD *)ActiveTool + 80);
        vPoint.x = (float)point.x;
        vPoint.y = (float)point.y;
        v5(a1: ActiveTool, a2: this, a3: v1, a4: &vPoint);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100835D0
// Name: protected: int CMapView3D::OnMouseWheel(unsigned int,short,class CPoint)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapView3D::OnMouseWheel(CMapView3D *this, unsigned int nFlags, unsigned int zDelta, CPoint point)
{
  CToolManager *m_pToolManager; // ecx
  int ActiveTool; // eax
  unsigned __int8 (__thiscall *v7)(int, CMapView3D *, unsigned int, unsigned int, float *); // edx
  CToolManager *v9; // ecx
  CBaseTool *ToolForID; // eax
  Camera3D *v11; // eax
  CCamera *m_pCamera; // ecx
  Camera3D *v13; // edi
  Vector ViewPoint; // [esp+Ch] [ebp-18h] BYREF
  Vector ViewForward; // [esp+18h] [ebp-Ch] BYREF

  m_pToolManager = this->m_pToolManager;
  if ( m_pToolManager != nullptr )
  {
    ActiveTool = CToolManager::GetActiveTool(this: (CSelection *)m_pToolManager);
    if ( ActiveTool != 0 )
    {
      v7 = *(unsigned __int8 (__thiscall **)(int, CMapView3D *, unsigned int, unsigned int, float *))(*(_DWORD *)ActiveTool + 84);
      ViewForward.y = (float)point.x;
      ViewForward.z = (float)point.y;
      if ( v7(a1: ActiveTool, a2: this, a3: nFlags, a4: zDelta, a5: &ViewForward.y) != 0 )
        return 1;
    }
  }
  CCamera::MoveForward(this: this->m_pCamera, fUnits: (float)((__int16)zDelta / 2));
  v9 = this->m_pToolManager;
  this->m_bUpdateView = true;
  this->m_bCameraPosChanged = true;
  ToolForID = CToolManager::GetToolForID(this: v9, eToolID: TOOL_CAMERA);
  v11 = (Camera3D *)__RTDynamicCast(
                      inptr: ToolForID,
                      VfDelta: 0,
                      SrcType: &CBaseTool `RTTI Type Descriptor',
                      TargetType: &Camera3D `RTTI Type Descriptor',
                      isReference: 0);
  m_pCamera = this->m_pCamera;
  v13 = v11;
  if ( m_pCamera != nullptr && v11 != nullptr )
  {
    CCamera::GetViewPoint(this: m_pCamera, &ViewPoint);
    CCamera::GetViewForward(this: this->m_pCamera, &ViewForward);
    Camera3D::UpdateActiveCamera(this: v13, vViewPos: &ViewPoint, vDir: &ViewForward);
  }
  return CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x100836D0
// Name: protected: void CMapView3D::OnChar(unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::OnChar(CMapView3D *this, unsigned int nChar, unsigned int nRepCnt, unsigned int nFlags)
{
  CToolManager *m_pToolManager; // ecx
  int ActiveTool; // eax

  m_pToolManager = this->m_pToolManager;
  if ( m_pToolManager == nullptr
    || (ActiveTool = CToolManager::GetActiveTool(this: (CSelection *)m_pToolManager)) == 0
    || (*(unsigned __int8 (__thiscall **)(int, CMapView3D *, unsigned int, unsigned int, unsigned int))(*(_DWORD *)ActiveTool + 96))(
         a1: ActiveTool,
         a2: this,
         a3: nChar,
         a4: nRepCnt,
         a5: nFlags) == 0 )
  {
    CWnd::Default(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083710
// Name: private: void CMapView3D::EnableCrosshair(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::EnableCrosshair(CMapView3D *this, bool bEnable)
{
  HWND__ *m_hWnd; // [esp-8h] [ebp-20h]
  CRect Rect; // [esp+8h] [ebp-10h] BYREF

  m_hWnd = this->m_hWnd;
  memset(&Rect, 0, sizeof(Rect));
  GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
  CWnd::ClientToScreen(this, lpRect: &Rect);
  SetCursorPos(X: (Rect.right + Rect.left) / 2, Y: (Rect.top + Rect.bottom) / 2);
  if ( bEnable )
    ClipCursor(lpRect: &Rect);
  else
    ClipCursor(lpRect: nullptr);
  ShowCursor(bShow: !bEnable);
  CRender3D::RenderEnable(this: this->m_pRender, eRenderState: RENDER_CENTER_CROSSHAIR, bEnable);
}

//------------------------------------------------------------------------------
// Address: 0x100837A0
// Name: public: void CMapView3D::EnableMouseLook(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::EnableMouseLook(CMapView3D *this, bool bEnable)
{
  if ( this->m_bMouseLook != bEnable )
  {
    if ( !this->m_bStrafing && !this->m_bRotating )
      CMapView3D::EnableCrosshair(this, bEnable);
    this->m_bMouseLook = bEnable;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100837E0
// Name: public: void CMapView3D::EnableRotating(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::EnableRotating(CMapView3D *this, bool bEnable)
{
  if ( this->m_bRotating != bEnable )
  {
    if ( !this->m_bStrafing && !this->m_bMouseLook )
      CMapView3D::EnableCrosshair(this, bEnable);
    this->m_bRotating = bEnable;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083820
// Name: public: void CMapView3D::EnableStrafing(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::EnableStrafing(CMapView3D *this, bool bEnable)
{
  if ( this->m_bStrafing != bEnable )
  {
    if ( !this->m_bMouseLook && !this->m_bRotating )
      CMapView3D::EnableCrosshair(this, bEnable);
    this->m_bStrafing = bEnable;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083860
// Name: public: void CMapView3D::SetCursor(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::SetCursor(CMapView3D *this, unsigned int hCursor)
{
  HCURSOR v2; // eax
  HCURSOR v3; // eax
  HCURSOR v4; // eax
  HCURSOR v5; // eax
  HCURSOR v6; // eax
  HCURSOR CursorA; // eax
  HCURSOR v8; // eax

  switch ( hCursor )
  {
    case 6u:
      AfxGetModuleState();
      CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F03);
      SetCursor(hCursor: CursorA);
      break;
    case 8u:
      AfxGetModuleState();
      v2 = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F82);
      SetCursor(hCursor: v2);
      break;
    case 9u:
      AfxGetModuleState();
      v3 = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F83);
      SetCursor(hCursor: v3);
      break;
    case 0xAu:
      AfxGetModuleState();
      v4 = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F84);
      SetCursor(hCursor: v4);
      break;
    case 0xBu:
      AfxGetModuleState();
      v5 = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F85);
      SetCursor(hCursor: v5);
      break;
    case 0xCu:
      AfxGetModuleState();
      v6 = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F86);
      SetCursor(hCursor: v6);
      break;
    default:
      AfxGetModuleState();
      v8 = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
      SetCursor(hCursor: v8);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083970
// Name: protected: void CMapView3D::OnKillFocus(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::OnKillFocus(CMapView3D *this, CWnd *pNewWnd)
{
  HWND__ *m_hWnd; // [esp-8h] [ebp-24h]
  HWND__ *v4; // [esp-8h] [ebp-24h]
  HWND__ *v5; // [esp-8h] [ebp-24h]
  tagRECT Rect; // [esp+Ch] [ebp-10h] BYREF

  if ( this->m_bMouseLook )
  {
    if ( !this->m_bStrafing && !this->m_bRotating )
    {
      m_hWnd = this->m_hWnd;
      memset(&Rect, 0, sizeof(Rect));
      GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
      CWnd::ClientToScreen(this, lpRect: &Rect);
      SetCursorPos(X: (Rect.left + Rect.right) / 2, Y: (Rect.top + Rect.bottom) / 2);
      ClipCursor(lpRect: nullptr);
      ShowCursor(bShow: true);
      CRender3D::RenderEnable(this: this->m_pRender, eRenderState: RENDER_CENTER_CROSSHAIR, bEnable: false);
    }
    this->m_bMouseLook = false;
  }
  if ( this->m_bRotating )
  {
    if ( !this->m_bStrafing && !this->m_bMouseLook )
    {
      v4 = this->m_hWnd;
      memset(&Rect, 0, sizeof(Rect));
      GetClientRect(hWnd: v4, lpRect: &Rect);
      CWnd::ClientToScreen(this, lpRect: &Rect);
      SetCursorPos(X: (Rect.right + Rect.left) / 2, Y: (Rect.bottom + Rect.top) / 2);
      ClipCursor(lpRect: nullptr);
      ShowCursor(bShow: true);
      CRender3D::RenderEnable(this: this->m_pRender, eRenderState: RENDER_CENTER_CROSSHAIR, bEnable: false);
    }
    this->m_bRotating = false;
  }
  if ( this->m_bStrafing )
  {
    if ( !this->m_bMouseLook && !this->m_bRotating )
    {
      v5 = this->m_hWnd;
      memset(&Rect, 0, sizeof(Rect));
      GetClientRect(hWnd: v5, lpRect: &Rect);
      CWnd::ClientToScreen(this, lpRect: &Rect);
      SetCursorPos(X: (Rect.right + Rect.left) / 2, Y: (Rect.top + Rect.bottom) / 2);
      ClipCursor(lpRect: nullptr);
      ShowCursor(bShow: true);
      CRender3D::RenderEnable(this: this->m_pRender, eRenderState: RENDER_CENTER_CROSSHAIR, bEnable: false);
    }
    this->m_bStrafing = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083B00
// Name: protected: void CMapView3D::OnKeyDown(unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::OnKeyDown(CMapView3D *this, int nChar, unsigned int nRepCnt, unsigned int nFlags)
{
  CToolManager *m_pToolManager; // ecx
  int ActiveTool; // eax
  double FarClip; // st7
  double v8; // st7
  CMapDoc *v9; // [esp+10h] [ebp-4h]
  float nFlagsa; // [esp+24h] [ebp+10h]
  float nFlagsb; // [esp+24h] [ebp+10h]

  v9 = this->GetMapDoc(this: &this->CMapView);
  if ( v9 != nullptr )
  {
    if ( (unsigned __int8)tolower(c: nChar) == 122 && (nFlags & 0x4000) == 0 && Options.view3d.bUseMouseLook != 0 )
    {
      if ( this->GetMapDoc(this: &this->CMapView) != nullptr )
      {
        CMapView3D::EnableMouseLook(this, bEnable: !this->m_bMouseLook);
        if ( !this->m_bMouseLook )
          CMapView3D::UpdateCameraVariables(this);
      }
    }
    else
    {
      m_pToolManager = this->m_pToolManager;
      if ( m_pToolManager == nullptr
        || (ActiveTool = CToolManager::GetActiveTool(this: (CSelection *)m_pToolManager)) == 0
        || (*(unsigned __int8 (__thiscall **)(int, CMapView3D *, int, unsigned int, unsigned int))(*(_DWORD *)ActiveTool
                                                                                                 + 88))(
             a1: ActiveTool,
             a2: this,
             a3: nChar,
             a4: nRepCnt,
             a5: nFlags) == 0 )
      {
        CKeyboard::OnKeyDown(this: &this->m_Keyboard, nChar, nRepCnt, nFlags);
        switch ( nChar )
        {
          case '!':
            v9->OnCmdMsg(this: v9, a2: 32924u, a3: 0, a4: nullptr, a5: nullptr);
            CWnd::Default(this);
            break;
          case '"':
            v9->OnCmdMsg(this: v9, a2: 32923u, a3: 0, a4: nullptr, a5: nullptr);
            CWnd::Default(this);
            break;
          case '.':
            v9->OnCmdMsg(this: v9, a2: 32858u, a3: 0, a4: nullptr, a5: nullptr);
            CWnd::Default(this);
            break;
          case '1':
            FarClip = CCamera::GetFarClip(this: this->m_pCamera);
            nFlagsa = FarClip;
            if ( FarClip < 2000.0 )
            {
              if ( nFlagsa > 500.0 )
              {
                CCamera::SetFarClip(this: this->m_pCamera, fFarClip: nFlagsa - 250.0);
                Options.view3d.iBackPlane = (int)nFlagsa;
              }
              goto LABEL_19;
            }
            CCamera::SetFarClip(this: this->m_pCamera, fFarClip: nFlagsa - 1000.0);
            Options.view3d.iBackPlane = (int)nFlagsa;
            this->m_bUpdateView = true;
            this->m_bClippingChanged = true;
            CWnd::Default(this);
            break;
          case '2':
            v8 = CCamera::GetFarClip(this: this->m_pCamera);
            nFlagsb = v8;
            if ( v8 > 9000.0 || nFlagsb <= 1000.0 )
            {
              if ( nFlagsb < 10000.0 )
              {
                CCamera::SetFarClip(this: this->m_pCamera, fFarClip: nFlagsb + 250.0);
                Options.view3d.iBackPlane = (int)nFlagsb;
              }
LABEL_19:
              this->m_bUpdateView = true;
              this->m_bClippingChanged = true;
              CWnd::Default(this);
            }
            else
            {
              CCamera::SetFarClip(this: this->m_pCamera, fFarClip: nFlagsb + 1000.0);
              Options.view3d.iBackPlane = (int)nFlagsb;
              this->m_bUpdateView = true;
              this->m_bClippingChanged = true;
              CWnd::Default(this);
            }
            break;
          case 'I':
          case 'i':
            CRender3D::DebugHook2(this: this->m_pRender, pData: nullptr);
            CWnd::Default(this);
            break;
          case 'O':
          case 'o':
            CRender3D::DebugHook1(this: this->m_pRender, pData: nullptr);
            CWnd::Default(this);
            break;
          case 'P':
          case 'p':
            CMapDoc::OnToggle3DGrid(this: v9);
            goto LABEL_29;
          default:
LABEL_29:
            CWnd::Default(this);
            break;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083E80
// Name: protected: void CMapView3D::OnLButtonDown(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::OnLButtonDown(CMapView3D *this, unsigned int nFlags, CPoint point)
{
  CToolManager *m_pToolManager; // ecx
  int ActiveTool; // eax
  unsigned __int8 (__thiscall *v6)(int, CMapView3D *, unsigned int, int *); // edx
  HWND__ *m_hWnd; // [esp-8h] [ebp-1Ch]
  tagRECT Rect; // [esp+4h] [ebp-10h] BYREF

  if ( GetAsyncKeyState(vKey: 32) >= 0 )
  {
    m_pToolManager = this->m_pToolManager;
    if ( m_pToolManager == nullptr
      || (ActiveTool = CToolManager::GetActiveTool(this: (CSelection *)m_pToolManager)) == 0
      || (v6 = *(unsigned __int8 (__thiscall **)(int, CMapView3D *, unsigned int, int *))(*(_DWORD *)ActiveTool + 60),
          *(float *)&Rect.right = (float)point.x,
          *(float *)&Rect.bottom = (float)point.y,
          v6(a1: ActiveTool, a2: this, a3: nFlags, a4: &Rect.right) == 0) )
    {
      CWnd::Default(this);
    }
  }
  else if ( !this->m_bRotating )
  {
    if ( !this->m_bStrafing && !this->m_bMouseLook )
    {
      m_hWnd = this->m_hWnd;
      memset(&Rect, 0, sizeof(Rect));
      GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
      CWnd::ClientToScreen(this, lpRect: &Rect);
      SetCursorPos(X: (Rect.right + Rect.left) / 2, Y: (Rect.bottom + Rect.top) / 2);
      ClipCursor(lpRect: &Rect);
      ShowCursor(bShow: false);
      CRender3D::RenderEnable(this: this->m_pRender, eRenderState: RENDER_CENTER_CROSSHAIR, bEnable: true);
    }
    this->m_bRotating = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083FA0
// Name: protected: void CMapView3D::OnLButtonUp(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::OnLButtonUp(CMapView3D *this, unsigned int nFlags, CPoint point)
{
  CToolManager *m_pToolManager; // ecx
  int ActiveTool; // eax
  unsigned __int8 (__thiscall *v6)(int, CMapView3D *, unsigned int, int *); // edx
  HWND__ *m_hWnd; // [esp-8h] [ebp-20h]
  tagRECT Rect; // [esp+8h] [ebp-10h] BYREF

  if ( this->m_bRotating )
  {
    if ( !this->m_bStrafing && !this->m_bMouseLook )
    {
      m_hWnd = this->m_hWnd;
      memset(&Rect, 0, sizeof(Rect));
      GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
      CWnd::ClientToScreen(this, lpRect: &Rect);
      SetCursorPos(X: (Rect.left + Rect.right) / 2, Y: (Rect.bottom + Rect.top) / 2);
      ClipCursor(lpRect: nullptr);
      ShowCursor(bShow: true);
      CRender3D::RenderEnable(this: this->m_pRender, eRenderState: RENDER_CENTER_CROSSHAIR, bEnable: false);
    }
    this->m_bRotating = false;
    CMapView3D::UpdateCameraVariables(this);
  }
  else
  {
    m_pToolManager = this->m_pToolManager;
    if ( m_pToolManager == nullptr
      || (ActiveTool = CToolManager::GetActiveTool(this: (CSelection *)m_pToolManager)) == 0
      || (v6 = *(unsigned __int8 (__thiscall **)(int, CMapView3D *, unsigned int, int *))(*(_DWORD *)ActiveTool + 64),
          *(float *)&Rect.right = (float)point.x,
          *(float *)&Rect.bottom = (float)point.y,
          v6(a1: ActiveTool, a2: this, a3: nFlags, a4: &Rect.right) == 0) )
    {
      CWnd::Default(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10084090
// Name: public: void CMapView3D::RenderView2(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::RenderView2(CMapView3D *this, bool bRenderingOverEngine)
{
  CRender3D *m_pRender; // ecx
  CTitleWnd *m_pwndTitle; // eax

  m_pRender = this->m_pRender;
  if ( m_pRender != nullptr )
    CRender3D::Render(this: m_pRender, bRenderingOverEngine);
  m_pwndTitle = this->m_pwndTitle;
  if ( m_pwndTitle != nullptr )
  {
    BringWindowToTop(hWnd: m_pwndTitle->m_hWnd);
    InvalidateRect(hWnd: this->m_pwndTitle->m_hWnd, lpRect: nullptr, bErase: true);
    UpdateWindow(hWnd: this->m_pwndTitle->m_hWnd);
  }
  this->m_bUpdateView = false;
}

//------------------------------------------------------------------------------
// Address: 0x100840F0
// Name: public: virtual void CMapView3D::ProcessInput(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::ProcessInput(CMapView3D *this)
{
  CWnd::XAccessible_vtbl *Time; // eax
  double v3; // st7
  float v4; // xmm0_4
  CMapDoc *v5; // eax
  float v6; // [esp+8h] [ebp-4h]

  if ( this->m_xAccessible.CView::CWnd::__vftable == nullptr )
    this->m_xAccessible.CView::CWnd::__vftable = (CWnd::XAccessible_vtbl *)timeGetTime();
  Time = (CWnd::XAccessible_vtbl *)timeGetTime();
  v3 = (double)(unsigned int)((char *)Time - (char *)this->m_xAccessible.CView::CWnd::__vftable) * 0.001;
  this->m_xAccessible.CView::CWnd::__vftable = Time;
  if ( v3 <= 0.30000001 )
  {
    v4 = v3;
    v6 = v3;
    if ( v6 <= 0.0 )
      return;
  }
  else
  {
    v4 = 0.30000001;
  }
  CMapView3D::ProcessMovementKeys(this: (CMapView3D *)((char *)this - 124), fElapsedTime: v4);
  CKeyboard::ClearImpulseFlags(this: (CKeyboard *)&this->m_pCtrlCont);
  CMapView3D::ProcessMouse(this: (CMapView3D *)((char *)this - 124));
  if ( Options.general.bRadiusCulling != 0
    && (LOBYTE(this->m_Keyboard.g_uKeyMap[246].uChar) != 0 || BYTE1(this->m_Keyboard.g_uKeyMap[246].uChar) != 0) )
  {
    v5 = (CMapDoc *)this->GetTypeLibCache(this);
    CMapDoc::UpdateVisibilityAll(this: v5);
    LOWORD(this->m_Keyboard.g_uKeyMap[246].uChar) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100841B0
// Name: protected: void CMapView3D::OnRButtonDown(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::OnRButtonDown(CMapView3D *this, unsigned int nFlags, CPoint point)
{
  CToolManager *m_pToolManager; // ecx
  int ActiveTool; // eax
  unsigned __int8 (__thiscall *v6)(int, CMapView3D *, unsigned int, int *); // edx
  HWND__ *m_hWnd; // [esp-8h] [ebp-1Ch]
  tagRECT Rect; // [esp+4h] [ebp-10h] BYREF

  if ( GetAsyncKeyState(vKey: 32) >= 0 )
  {
    m_pToolManager = this->m_pToolManager;
    if ( m_pToolManager == nullptr
      || (ActiveTool = CToolManager::GetActiveTool(this: (CSelection *)m_pToolManager)) == 0
      || (v6 = *(unsigned __int8 (__thiscall **)(int, CMapView3D *, unsigned int, int *))(*(_DWORD *)ActiveTool + 72),
          *(float *)&Rect.right = (float)point.x,
          *(float *)&Rect.bottom = (float)point.y,
          v6(a1: ActiveTool, a2: this, a3: nFlags, a4: &Rect.right) == 0) )
    {
      CWnd::Default(this);
    }
  }
  else if ( !this->m_bStrafing )
  {
    if ( !this->m_bMouseLook && !this->m_bRotating )
    {
      m_hWnd = this->m_hWnd;
      memset(&Rect, 0, sizeof(Rect));
      GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
      CWnd::ClientToScreen(this, lpRect: &Rect);
      SetCursorPos(X: (Rect.right + Rect.left) / 2, Y: (Rect.bottom + Rect.top) / 2);
      ClipCursor(lpRect: &Rect);
      ShowCursor(bShow: false);
      CRender3D::RenderEnable(this: this->m_pRender, eRenderState: RENDER_CENTER_CROSSHAIR, bEnable: true);
    }
    this->m_bStrafing = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100842D0
// Name: protected: void CMapView3D::OnRButtonUp(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::OnRButtonUp(CMapView3D *this, unsigned int nFlags, CPoint point)
{
  CToolManager *m_pToolManager; // ecx
  int ActiveTool; // eax
  unsigned __int8 (__thiscall *v6)(int, CMapView3D *, unsigned int, int *); // edx
  HWND__ *m_hWnd; // [esp-8h] [ebp-20h]
  tagRECT Rect; // [esp+8h] [ebp-10h] BYREF

  if ( this->m_bStrafing )
  {
    if ( !this->m_bMouseLook && !this->m_bRotating )
    {
      m_hWnd = this->m_hWnd;
      memset(&Rect, 0, sizeof(Rect));
      GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
      CWnd::ClientToScreen(this, lpRect: &Rect);
      SetCursorPos(X: (Rect.left + Rect.right) / 2, Y: (Rect.bottom + Rect.top) / 2);
      ClipCursor(lpRect: nullptr);
      ShowCursor(bShow: true);
      CRender3D::RenderEnable(this: this->m_pRender, eRenderState: RENDER_CENTER_CROSSHAIR, bEnable: false);
    }
    this->m_bStrafing = false;
    CMapView3D::UpdateCameraVariables(this);
  }
  else
  {
    m_pToolManager = this->m_pToolManager;
    if ( m_pToolManager == nullptr
      || (ActiveTool = CToolManager::GetActiveTool(this: (CSelection *)m_pToolManager)) == 0
      || (v6 = *(unsigned __int8 (__thiscall **)(int, CMapView3D *, unsigned int, int *))(*(_DWORD *)ActiveTool + 76),
          *(float *)&Rect.right = (float)point.x,
          *(float *)&Rect.bottom = (float)point.y,
          v6(a1: ActiveTool, a2: this, a3: nFlags, a4: &Rect.right) == 0) )
    {
      CWnd::Default(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100843C0
// Name: public: void CMapView3D::Foundry_OnLButtonDown(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::Foundry_OnLButtonDown(CMapView3D *this, unsigned int x, unsigned int y)
{
  CMapView3D::OnLButtonDown(this, nFlags: 0, point: (CPoint)__PAIR64__(y, x));
}

//------------------------------------------------------------------------------
// Address: 0x100843E0
// Name: public: virtual void CMapView3D::RenderView(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView3D::RenderView(CMapView3D *this)
{
  COleDropTarget *m_pDropTarget; // ecx
  int m_nModalResult; // eax

  m_pDropTarget = this->m_pDropTarget;
  if ( m_pDropTarget != nullptr )
    CRender3D::Render(this: (CRender3D *)m_pDropTarget, bRenderingOverEngine: false);
  m_nModalResult = this->m_nModalResult;
  if ( m_nModalResult != 0 )
  {
    BringWindowToTop(hWnd: *(HWND *)(m_nModalResult + 32));
    InvalidateRect(hWnd: *(HWND *)(this->m_nModalResult + 32), lpRect: nullptr, bErase: true);
    UpdateWindow(hWnd: *(HWND *)(this->m_nModalResult + 32));
  }
  BYTE1(this->m_dwRef) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10084430
// Name: protected: virtual struct AFX_MSGMAP const __near * CMapView3D::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMapView3D::GetMessageMap(CMapView3D *this)
{
  return (const AFX_MSGMAP *)&off_105E2DE4;
}

//------------------------------------------------------------------------------
// Address: 0x10084440
// Name: public: virtual int CMapView3D::PreCreateWindow(struct tagCREATESTRUCTA __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapView3D::PreCreateWindow(CMapView3D *this, tagCREATESTRUCTA *cs)
{
  CAfxStringMgr *StringManager; // eax
  HBRUSH__ *StockObject; // eax
  const char *v5; // eax
  int v6; // ecx

  if ( (_S1_5 & 1) == 0 )
  {
    _S1_5 |= 1u;
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    className_0.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
    atexit(func: CMapView3D::PreCreateWindow_::_2_::_dynamic_atexit_destructor_for__className__);
  }
  if ( *((_DWORD *)className_0.m_pszData - 3) == 0 )
  {
    StockObject = (HBRUSH__ *)GetStockObject(i: 4);
    v5 = AfxRegisterWndClass(nClassStyle: 0x102Bu, hCursor: nullptr, hbrBackground: StockObject, hIcon: nullptr);
    if ( v5 != nullptr )
      v6 = strlen(v5);
    else
      v6 = 0;
    ATL::CSimpleStringT<char,0>::SetString(this: &className_0, pszSrc: v5, nLength: v6);
  }
  cs->lpszClass = className_0.m_pszData;
  return CView::PreCreateWindow(this, cs);
}

//------------------------------------------------------------------------------
// Address: 0x1034F932
// Name: protected: void CToolBar::OnNcPaint(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CToolBar::OnNcPaint(CDockBar *this)
{
  CControlBar::EraseNonClient(this);
}

//------------------------------------------------------------------------------
// Address: 0x10362386
// Name: protected: void CMDIChildWndEx::OnNcPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDIChildWndEx::OnNcPaint(CMDIChildWndEx *this)
{
  CMDIFrameWndEx *m_pMDIFrame; // eax
  CMFCVisualManager *Instance; // eax

  m_pMDIFrame = this->m_pMDIFrame;
  if ( m_pMDIFrame != nullptr && m_pMDIFrame->m_wndClientArea.m_bIsMDITabbedGroup != 0
    || IsZoomed(hWnd: this->m_hWnd)
    || (Instance = CMFCVisualManager::GetInstance(), Instance->IsOwnerDrawCaption(this: Instance) == 0)
    || CFrameImpl::OnNcPaint(this: &this->m_Impl) == 0 )
  {
    CWnd::Default(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10382544
// Name: protected: int CFrameImpl::OnNcPaint(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFrameImpl::OnNcPaint(CFrameImpl *this)
{
  CMFCRibbonBar *m_pRibbonBar; // eax
  BOOL v3; // edi
  CMFCVisualManager *Instance; // eax

  m_pRibbonBar = this->m_pRibbonBar;
  v3 = false;
  if ( m_pRibbonBar != nullptr
    && m_pRibbonBar->m_hWnd != nullptr
    && (IsWindowVisible(hWnd: m_pRibbonBar->m_hWnd) || !IsWindowVisible(hWnd: this->m_pFrame->m_hWnd))
    && this->m_pRibbonBar->m_bReplaceFrameCaption != 0 )
  {
    v3 = AFX_GLOBAL_DATA::DwmIsCompositionEnabled(this: &afxGlobalData) == 0;
  }
  if ( CFrameImpl::IsOwnerDrawCaption(this) == 0 && !v3 || afxGlobalData.m_bInSettingChange != 0 )
    return 0;
  Instance = CMFCVisualManager::GetInstance();
  return ((int (__thiscall *)(CMFCVisualManager *, CFrameWnd *, CObList *, int, int, int, int))Instance->OnNcPaint)(
           a1: Instance,
           a2: this->m_pFrame,
           a3: &this->m_lstCaptionSysButtons,
           a4: this->m_rectRedraw.left,
           a5: this->m_rectRedraw.top,
           a6: this->m_rectRedraw.right,
           a7: this->m_rectRedraw.bottom);
}

//------------------------------------------------------------------------------
// Address: 0x1038E644
// Name: protected: void CMDIFrameWndEx::OnNcPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDIFrameWndEx::OnNcPaint(CMDIFrameWndEx *this)
{
  if ( CFrameImpl::OnNcPaint(this: &this->m_Impl) == 0 )
    CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x10395E59
// Name: protected: void CPaneFrameWnd::OnNcPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaneFrameWnd::OnNcPaint(CPaneFrameWnd *this)
{
  CDockingManager *m_pDockManager; // eax
  CWnd *v3; // eax
  HDC CompatibleDC; // eax
  HBITMAP CompatibleBitmap; // eax
  HRGN RectRgnIndirect; // eax
  CPaneFrameWnd_vtbl *v7; // eax
  CDockingManager *DockingManager; // eax
  CWnd *v9; // eax
  CMFCVisualManager *Instance; // eax
  CDC *v11; // esi
  int v12; // eax
  CObList::CNode *m_pNodeHead; // edi
  CObject *data; // esi
  bool v15; // zf
  CObject_vtbl *v16; // eax
  tagRECT *v17; // ecx
  int v18; // eax
  char *v19; // ecx
  int *v20; // eax
  CDC *v21; // esi
  void *m_hObject; // edi
  int ClipBox; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-138h]
  HWND__ *v25; // [esp-8h] [ebp-138h]
  CDC v26; // [esp+10h] [ebp-120h] BYREF
  CWindowDC v27; // [esp+20h] [ebp-110h] BYREF
  CGdiObject v28; // [esp+34h] [ebp-FCh] BYREF
  CGdiObject *v29; // [esp+3Ch] [ebp-F4h]
  const char *v30; // [esp+40h] [ebp-F0h] BYREF
  CGdiObject v31; // [esp+44h] [ebp-ECh] BYREF
  int v32; // [esp+4Ch] [ebp-E4h]
  int v33; // [esp+50h] [ebp-E0h]
  int v34; // [esp+54h] [ebp-DCh]
  int v35; // [esp+58h] [ebp-D8h]
  CDC *v36; // [esp+5Ch] [ebp-D4h]
  char v37; // [esp+60h] [ebp-D0h] BYREF
  char v38[16]; // [esp+70h] [ebp-C0h] BYREF
  char v39; // [esp+80h] [ebp-B0h] BYREF
  char v40[16]; // [esp+90h] [ebp-A0h] BYREF
  char v41; // [esp+A0h] [ebp-90h] BYREF
  tagRECT v42; // [esp+B0h] [ebp-80h] BYREF
  tagRECT v43; // [esp+C0h] [ebp-70h] BYREF
  tagRECT v44; // [esp+D0h] [ebp-60h] BYREF
  tagRECT v45; // [esp+E0h] [ebp-50h] BYREF
  tagRECT Rect; // [esp+F0h] [ebp-40h] BYREF
  tagRECT rc; // [esp+100h] [ebp-30h] BYREF
  tagRECT v48; // [esp+110h] [ebp-20h] BYREF
  int v49; // [esp+12Ch] [ebp-4h]

  m_pDockManager = this->m_pDockManager;
  if ( m_pDockManager != nullptr
    || (v3 = CWnd::FromHandlePermanent(hWnd: this->m_hParentWnd),
        (m_pDockManager = CGlobalUtils::GetDockingManager(this: &afxGlobalUtils, pWnd: v3)) != nullptr) )
  {
    if ( m_pDockManager->m_bLockUpdate == 0 )
    {
      CWindowDC::CWindowDC(this: &v27, pWnd: this);
      v49 = 0;
      v36 = &v27;
      v32 = 0;
      CDC::CDC(this: &v26);
      v28.m_hObject = nullptr;
      v28.__vftable = (CGdiObject_vtbl *)&CBitmap::`vftable';
      m_hWnd = this->m_hWnd;
      LOBYTE(v49) = 2;
      v29 = nullptr;
      memset(&Rect, 0, sizeof(Rect));
      GetWindowRect(hWnd: m_hWnd, lpRect: &Rect);
      memset(&rc, 0, sizeof(rc));
      SetRect(lprc: &rc, xLeft: 0, yTop: 0, xRight: Rect.right - Rect.left, yBottom: Rect.bottom - Rect.top);
      CompatibleDC = CreateCompatibleDC(hdc: v27.m_hDC);
      if ( CDC::Attach(this: &v26, hDC: CompatibleDC) != 0 )
      {
        CompatibleBitmap = CreateCompatibleBitmap(hdc: v27.m_hDC, cx: rc.right - rc.left, cy: rc.bottom - rc.top);
        if ( CGdiObject::Attach(this: &v28, hObject: CompatibleBitmap) != 0 )
        {
          v32 = 1;
          v29 = CDC::SelectGdiObject(hDC: v26.m_hDC, h: v28.m_hObject);
          v36 = &v26;
        }
      }
      v25 = this->m_hWnd;
      memset(&v44, 0, sizeof(v44));
      memset(&v43, 0, sizeof(v43));
      GetWindowRect(hWnd: v25, lpRect: &v43);
      GetClientRect(hWnd: this->m_hWnd, lpRect: &v44);
      CWnd::ClientToScreen(this, lpRect: &v44);
      OffsetRect(lprc: &v44, dx: -v43.left, dy: -v43.top);
      CDC::ExcludeClipRect(this: &v27, lpRect: &v44);
      v31.m_hObject = nullptr;
      v31.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
      LOBYTE(v49) = 3;
      if ( !IsRectEmpty(lprc: &this->m_rectRedraw) )
      {
        RectRgnIndirect = CreateRectRgnIndirect(lprect: &this->m_rectRedraw);
        CGdiObject::Attach(this: &v31, hObject: RectRgnIndirect);
        CDC::SelectClipRgn(this: &v27, pRgn: (CRgn *)&v31);
      }
      this->OnDrawBorder(this, a2: v36);
      v7 = this->__vftable;
      memset(&v45, 0, sizeof(v45));
      v7->GetCaptionRect(this, a2: (CRect *)&v45);
      DockingManager = this->m_pDockManager;
      if ( DockingManager == nullptr )
      {
        v9 = CWnd::FromHandlePermanent(hWnd: this->m_hParentWnd);
        DockingManager = CGlobalUtils::GetDockingManager(this: &afxGlobalUtils, pWnd: v9);
      }
      if ( DockingManager->m_bLockUpdate != 0 )
        SetRectEmpty(lprc: &v45);
      this->GetCaptionRect(this, a2: (CRect *)&v45);
      Instance = CMFCVisualManager::GetInstance();
      v11 = v36;
      v12 = ((int (__thiscall *)(CMFCVisualManager *, CDC *, int, int, int, int, CPaneFrameWnd *, int))Instance->OnFillMiniFrameCaption)(
              a1: Instance,
              a2: v36,
              a3: v45.left,
              a4: v45.top,
              a5: v45.right,
              a6: v45.bottom,
              a7: this,
              a8: this->m_bActive);
      m_pNodeHead = this->m_lstCaptionButtons.m_pNodeHead;
      v35 = -1;
      v34 = -1;
      v33 = v12;
      if ( m_pNodeHead != nullptr )
      {
        while ( 1 )
        {
          data = m_pNodeHead->data;
          v15 = data[3].__vftable == nullptr;
          m_pNodeHead = m_pNodeHead->pNext;
          data[8].__vftable = (CObject_vtbl *)v33;
          if ( v15 )
          {
            v16 = data->__vftable;
            if ( data[6].__vftable != nullptr )
            {
              if ( v34 == -1 )
              {
                v17 = &v48;
LABEL_20:
                v34 = *(_DWORD *)(((int (__thiscall *)(CObject *, tagRECT *))v16[1].GetRuntimeClass)(a1: data, a2: v17)
                                + 8)
                    + 2;
                goto LABEL_26;
              }
              v18 = ((int (__thiscall *)(CObject *, char *))v16[1].GetRuntimeClass)(a1: data, a2: v40);
              if ( v34 <= *(_DWORD *)(v18 + 8) + 2 )
              {
                v16 = data->__vftable;
                v17 = (tagRECT *)&v39;
                goto LABEL_20;
              }
            }
            else
            {
              if ( v35 == -1 )
              {
                v19 = &v37;
LABEL_25:
                v35 = *(_DWORD *)((int (__thiscall *)(CObject *, char *))v16[1].GetRuntimeClass)(a1: data, a2: v19);
                goto LABEL_26;
              }
              v20 = (int *)((int (__thiscall *)(CObject *, char *))v16[1].GetRuntimeClass)(a1: data, a2: v38);
              if ( v35 >= *v20 )
              {
                v16 = data->__vftable;
                v19 = &v41;
                goto LABEL_25;
              }
            }
          }
LABEL_26:
          if ( m_pNodeHead == nullptr )
          {
            v11 = v36;
            break;
          }
        }
      }
      CDC::SetBkMode(this: v11, nBkMode: 1);
      v11->SetTextColor(this: v11, a2: v33);
      v33 = (int)v11->SelectObject(this: v11, a2: &afxGlobalData.fontBold);
      this->GetCaptionText(this, result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v30);
      v42 = v45;
      LOBYTE(v49) = 4;
      if ( v35 != -1 )
        v42.right = v35;
      if ( v34 != -1 )
        v42.left = v34;
      InflateRect(lprc: &v42, dx: -2, dy: 0);
      v21 = v36;
      v36->DrawTextA(this: v36, a2: v30, a3: *((_DWORD *)v30 - 3), a4: &v42, a5: 32804u);
      v21->SelectObject(this: v21, a2: (CFont *)v33);
      m_hObject = nullptr;
      CDC::SelectClipRgn(this: v21, pRgn: nullptr);
      this->OnDrawCaptionButtons(this, a2: v21);
      if ( v32 != 0 )
      {
        memset(&v48, 0, sizeof(v48));
        ClipBox = CDC::GetClipBox(this: &v27, lpRect: &v48);
        if ( ClipBox != 1 )
        {
          if ( ClipBox != 2 )
          {
            v48 = rc;
            m_hObject = nullptr;
          }
          BitBlt(
            hdc: v27.m_hDC,
            x: v48.left,
            y: v48.top,
            cx: v48.right - v48.left,
            cy: v48.bottom - v48.top,
            hdcSrc: v26.m_hDC,
            x1: v48.left,
            y1: v48.top,
            rop: 0xCC0020u);
        }
        if ( v29 != nullptr )
          m_hObject = v29->m_hObject;
        CDC::SelectGdiObject(hDC: v26.m_hDC, h: m_hObject);
      }
      CWnd::Default(this);
      ATL::CStringData::Release(this: (ATL::CStringData *)v30 - 1);
      LOBYTE(v49) = 2;
      v31.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
      CGdiObject::~CGdiObject(this: &v31);
      LOBYTE(v49) = 1;
      v28.__vftable = (CGdiObject_vtbl *)&CBitmap::`vftable';
      CGdiObject::~CGdiObject(this: &v28);
      LOBYTE(v49) = 0;
      CDC::~CDC(this: &v26);
      v49 = -1;
      CWindowDC::~CWindowDC(this: &v27);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039B698
// Name: protected: void CMFCPropertyGridCtrl::OnNcPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::OnNcPaint(CMFCPropertyGridCtrl *this)
{
  CMFCPropertyGridCtrl_vtbl *v2; // eax
  CMFCVisualManager *Instance; // eax

  if ( this->m_nDescrHeight == -1 )
  {
    v2 = this->__vftable;
    this->m_nDescrHeight = this->m_nRowHeight / 2 + this->m_nRowHeight * this->m_nDescrRows;
    v2->AdjustLayout(this);
  }
  if ( (CWnd::GetStyle(this) & 0x800000) != 0 )
  {
    Instance = CMFCVisualManager::GetInstance();
    Instance->OnDrawControlBorder(this: Instance, a2: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A42F7
// Name: protected: void CMFCEditBrowseCtrl::OnNcPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCEditBrowseCtrl::OnNcPaint(CMFCEditBrowseCtrl *this)
{
  int top; // eax
  HRGN v3; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-74h]
  HWND__ *v5; // [esp-8h] [ebp-74h]
  CWindowDC v6; // [esp+10h] [ebp-5Ch] BYREF
  CGdiObject v7; // [esp+24h] [ebp-48h] BYREF
  tagRECT rc; // [esp+2Ch] [ebp-40h] BYREF
  tagRECT v9; // [esp+3Ch] [ebp-30h] BYREF
  tagRECT Rect; // [esp+4Ch] [ebp-20h] BYREF
  int v11; // [esp+68h] [ebp-4h]

  CWnd::Default(this);
  if ( this->m_Mode != BrowseMode_None )
  {
    CWindowDC::CWindowDC(this: &v6, pWnd: this);
    m_hWnd = this->m_hWnd;
    v11 = 0;
    memset(&Rect, 0, sizeof(Rect));
    GetWindowRect(hWnd: m_hWnd, lpRect: &Rect);
    this->m_rectBtn = (CRect)Rect;
    v5 = this->m_hWnd;
    this->m_rectBtn.left = this->m_rectBtn.right - this->m_nBrowseButtonWidth;
    memset(&v9, 0, sizeof(v9));
    GetClientRect(hWnd: v5, lpRect: &v9);
    CWnd::ClientToScreen(this, lpRect: &v9);
    OffsetRect(lprc: &this->m_rectBtn, dx: v9.right + this->m_nBrowseButtonWidth - Rect.right, dy: 0);
    top = Rect.top;
    this->m_rectBtn.top += v9.top - Rect.top;
    this->m_rectBtn.bottom += v9.bottom - Rect.bottom;
    rc = (tagRECT)this->m_rectBtn;
    OffsetRect(lprc: &rc, dx: -Rect.left, dy: -top);
    v7.m_hObject = nullptr;
    v7.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
    LOBYTE(v11) = 1;
    v3 = CreateRectRgnIndirect(lprect: &rc);
    CGdiObject::Attach(this: &v7, hObject: v3);
    CDC::SelectClipRgn(this: &v6, pRgn: (CRgn *)&v7);
    ((void (__thiscall *)(CMFCEditBrowseCtrl *, CWindowDC *, int, int, int, int, int, int))this->OnDrawBrowseButton)(
      a1: this,
      a2: &v6,
      a3: rc.left,
      a4: rc.top,
      a5: rc.right,
      a6: rc.bottom,
      a7: this->m_bIsButtonPressed,
      a8: this->m_bIsButtonHighlighted);
    CDC::SelectClipRgn(this: &v6, pRgn: nullptr);
    CWnd::ScreenToClient(this, lpRect: &this->m_rectBtn);
    LOBYTE(v11) = 0;
    v7.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
    CGdiObject::~CGdiObject(this: &v7);
    v11 = -1;
    CWindowDC::~CWindowDC(this: &v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A905D
// Name: public: void CFrameWndEx::OnNcPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFrameWndEx::OnNcPaint(CFrameWndEx *this)
{
  if ( CFrameImpl::OnNcPaint(this: &this->m_Impl) == 0 )
    CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x103AB046
// Name: protected: void CMFCToolBar::OnNcPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::OnNcPaint(CMFCToolBar *this)
{
  CMFCControlBarImpl::DrawNcArea(this: &this->m_Impl);
}

//------------------------------------------------------------------------------
// Address: 0x103CF277
// Name: protected: void CMFCCaptionBar::OnNcPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCCaptionBar::OnNcPaint(CMFCCaptionBar *this)
{
  int v2; // ecx
  CMFCCaptionBar_vtbl *v3; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-70h]
  HWND__ *v5; // [esp-8h] [ebp-70h]
  CWindowDC v6; // [esp+10h] [ebp-58h] BYREF
  int top; // [esp+24h] [ebp-44h]
  tagRECT Rect; // [esp+28h] [ebp-40h] BYREF
  tagRECT v9; // [esp+38h] [ebp-30h] BYREF
  tagRECT rc; // [esp+48h] [ebp-20h] BYREF
  int v11; // [esp+64h] [ebp-4h]

  CWindowDC::CWindowDC(this: &v6, pWnd: this);
  m_hWnd = this->m_hWnd;
  v11 = 0;
  memset(&Rect, 0, sizeof(Rect));
  GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
  v5 = this->m_hWnd;
  memset(&v9, 0, sizeof(v9));
  GetWindowRect(hWnd: v5, lpRect: &v9);
  rc = v9;
  CWnd::ScreenToClient(this, lpRect: &v9);
  OffsetRect(lprc: &Rect, dx: -v9.left, dy: -v9.top);
  CDC::ExcludeClipRect(this: &v6, lpRect: &Rect);
  OffsetRect(lprc: &rc, dx: -rc.left, dy: -rc.top);
  top = rc.top;
  rc.top = rc.bottom - this->m_nBorderSize;
  ((void (__thiscall *)(CMFCCaptionBar *, CWindowDC *, int, int, int, int))this->OnDrawBorder)(
    a1: this,
    a2: &v6,
    a3: rc.left,
    a4: rc.top,
    a5: rc.right,
    a6: rc.bottom);
  v2 = top + this->m_nBorderSize;
  rc.top = top;
  v3 = this->__vftable;
  rc.bottom = v2;
  ((void (__thiscall *)(CMFCCaptionBar *, CWindowDC *, int, int, int, int))v3->OnDrawBorder)(
    a1: this,
    a2: &v6,
    a3: rc.left,
    a4: top,
    a5: rc.right,
    a6: v2);
  CDC::SelectClipRgn(this: &v6, pRgn: nullptr);
  v11 = -1;
  CWindowDC::~CWindowDC(this: &v6);
}

//------------------------------------------------------------------------------
// Address: 0x103D7AFE
// Name: public: virtual int CMFCVisualManager::OnNcPaint(class CWnd __near *,class CObList const __near &,class CRect)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMFCVisualManager::OnNcPaint(
        CBasePane *this,
        unsigned int dwAlignment,
        const tagRECT *lpRect,
        const tagRECT *dwDockFlags,
        CBasePane *pRelativeBar,
        CBasePane *nRelativeIndex,
        int bOuterEdge)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103EB00A
// Name: protected: void CDockablePane::OnNcPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDockablePane::OnNcPaint(CDockablePane *this)
{
  HDC CompatibleDC; // eax
  HBITMAP CompatibleBitmap; // eax
  HRGN RectRgnIndirect; // eax
  CMFCVisualManager *Instance; // eax
  int v6; // esi
  int v7; // eax
  void *m_hObject; // eax
  CObject **m_pData; // ecx
  CMFCCaptionButton *v10; // edi
  unsigned int v11; // eax
  CMFCCaptionButton_vtbl *v12; // esi
  int v13; // eax
  HWND__ *m_hWnd; // [esp-Ch] [ebp-B4h]
  HWND__ *v15; // [esp-8h] [ebp-B0h]
  HWND__ *v16; // [esp-8h] [ebp-B0h]
  CDC v17; // [esp+10h] [ebp-98h] BYREF
  CWindowDC v18; // [esp+20h] [ebp-88h] BYREF
  CGdiObject *v19; // [esp+34h] [ebp-74h]
  CGdiObject v20; // [esp+38h] [ebp-70h] BYREF
  int v21; // [esp+40h] [ebp-68h]
  CGdiObject v22; // [esp+44h] [ebp-64h] BYREF
  int m_bPinState; // [esp+4Ch] [ebp-5Ch]
  int v24; // [esp+50h] [ebp-58h]
  CWindowDC *v25; // [esp+54h] [ebp-54h]
  tagRECT Rect; // [esp+58h] [ebp-50h] BYREF
  tagRECT rc; // [esp+68h] [ebp-40h] BYREF
  tagRECT v28; // [esp+78h] [ebp-30h] BYREF
  tagRECT v29; // [esp+88h] [ebp-20h] BYREF
  int v30; // [esp+A4h] [ebp-4h]

  if ( CBasePane::m_bMultiThreaded != 0 )
    EnterCriticalSection(lpCriticalSection: &CBasePane::m_CriticalSection.m_sect);
  CWindowDC::CWindowDC(this: &v18, pWnd: &this->CPane);
  m_hWnd = this->m_hWnd;
  v30 = 0;
  memset(&Rect, 0, sizeof(Rect));
  GetUpdateRect(hWnd: m_hWnd, lpRect: &Rect, bErase: false);
  v15 = this->m_hWnd;
  memset(&rc, 0, sizeof(rc));
  memset(&v29, 0, sizeof(v29));
  GetClientRect(hWnd: v15, lpRect: &rc);
  CWnd::ClientToScreen(this: &this->CPane, lpRect: &rc);
  GetWindowRect(hWnd: this->m_hWnd, lpRect: &v29);
  OffsetRect(lprc: &rc, dx: -v29.left, dy: -v29.top);
  OffsetRect(lprc: &v29, dx: -v29.left, dy: -v29.top);
  v25 = &v18;
  v21 = 0;
  CDC::CDC(this: &v17);
  v22.m_hObject = nullptr;
  v22.__vftable = (CGdiObject_vtbl *)&CBitmap::`vftable';
  LOBYTE(v30) = 2;
  v19 = nullptr;
  CompatibleDC = CreateCompatibleDC(hdc: v18.m_hDC);
  if ( CDC::Attach(this: &v17, hDC: CompatibleDC) != 0 )
  {
    CompatibleBitmap = CreateCompatibleBitmap(hdc: v18.m_hDC, cx: v29.right - v29.left, cy: v29.bottom - v29.top);
    if ( CGdiObject::Attach(this: &v22, hObject: CompatibleBitmap) != 0 )
    {
      v21 = 1;
      v19 = CDC::SelectGdiObject(hDC: v17.m_hDC, h: v22.m_hObject);
      v25 = (CWindowDC *)&v17;
    }
  }
  CDC::ExcludeClipRect(this: &v18, lpRect: &rc);
  v20.m_hObject = nullptr;
  v20.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
  LOBYTE(v30) = 3;
  if ( !IsRectEmpty(lprc: &this->m_rectRedraw) )
  {
    RectRgnIndirect = CreateRectRgnIndirect(lprect: &this->m_rectRedraw);
    CGdiObject::Attach(this: &v20, hObject: RectRgnIndirect);
    CDC::SelectClipRgn(this: &v18, pRgn: (CRgn *)&v20);
  }
  CDC::IntersectClipRect(this: &v18, lpRect: &v29);
  Instance = CMFCVisualManager::GetInstance();
  ((void (__thiscall *)(CMFCVisualManager *, CWindowDC *, CDockablePane *, int, int, int, int, int, int, int, int, int))Instance->OnFillBarBackground)(
    a1: Instance,
    a2: v25,
    a3: this,
    a4: v29.left,
    a5: v29.top,
    a6: v29.right,
    a7: v29.bottom,
    a8: v29.left,
    a9: v29.top,
    a10: v29.right,
    a11: v29.bottom,
    a12: 1);
  v6 = this->GetCaptionHeight((CBasePane *)this);
  if ( v6 > 0 )
  {
    v16 = this->m_hWnd;
    memset(&v28, 0, sizeof(v28));
    GetWindowRect(hWnd: v16, lpRect: &v28);
    CWnd::ScreenToClient(this: &this->CPane, lpRect: &v28);
    OffsetRect(lprc: &v28, dx: -v28.left, dy: -v28.top);
    InflateRect(lprc: &v28, dx: 0, dy: -1);
    --v28.top;
    v28.left = rc.left;
    v28.bottom = v28.top + v6 - 2;
    ((void (__thiscall *)(CDockablePane *, CWindowDC *, int, int, int, int))this->DrawCaption)(
      a1: this,
      a2: v25,
      a3: rc.left,
      a4: v28.top,
      a5: v28.right,
      a6: v28.bottom);
    v7 = 0;
    v24 = 0;
    if ( this->m_arrButtons.m_nSize > 0 )
    {
      while ( 1 )
      {
        if ( v7 < 0 || v7 >= this->m_arrButtons.m_nSize )
          AfxThrowInvalidArgException();
        m_pData = this->m_arrButtons.m_pData;
        m_bPinState = 0;
        v10 = (CMFCCaptionButton *)m_pData[v7];
        v11 = CMFCCaptionButton::GetHit(this: v10) - 8;
        if ( v11 != 0 )
        {
          if ( v11 == 1 )
            m_bPinState = this->m_bPinState;
        }
        else
        {
          m_bPinState = 1;
        }
        v12 = v10->__vftable;
        v13 = ((int (__thiscall *)(CDockablePane *, int, _DWORD))this->IsHorizontal)(a1: this, a2: m_bPinState, a3: 0);
        ((void (__thiscall *)(CMFCCaptionButton *, CWindowDC *, int, int))v12->OnDraw)(
          a1: v10,
          a2: v25,
          a3: this->m_bActive,
          a4: v13);
        v10->m_clrForeground = -1;
        if ( ++v24 >= this->m_arrButtons.m_nSize )
          break;
        v7 = v24;
      }
    }
  }
  if ( v21 != 0 )
  {
    BitBlt(
      hdc: v18.m_hDC,
      x: v29.left,
      y: v29.top,
      cx: v29.right - v29.left,
      cy: v29.bottom - v29.top,
      hdcSrc: v17.m_hDC,
      x1: v29.left,
      y1: v29.top,
      rop: 0xCC0020u);
    if ( v19 != nullptr )
      m_hObject = v19->m_hObject;
    else
      m_hObject = nullptr;
    CDC::SelectGdiObject(hDC: v17.m_hDC, h: m_hObject);
  }
  CDC::SelectClipRgn(this: &v18, pRgn: nullptr);
  if ( CBasePane::m_bMultiThreaded != 0 )
    LeaveCriticalSection(lpCriticalSection: &CBasePane::m_CriticalSection.m_sect);
  LOBYTE(v30) = 2;
  v20.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
  CGdiObject::~CGdiObject(this: &v20);
  LOBYTE(v30) = 1;
  v22.__vftable = (CGdiObject_vtbl *)&CBitmap::`vftable';
  CGdiObject::~CGdiObject(this: &v22);
  LOBYTE(v30) = 0;
  CDC::~CDC(this: &v17);
  v30 = -1;
  CWindowDC::~CWindowDC(this: &v18);
}

//------------------------------------------------------------------------------
// Address: 0x1040882C
// Name: protected: void CMFCColorBar::OnNcPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCColorBar::OnNcPaint(CMFCColorBar *this)
{
  if ( this->m_bIsTearOff != 0 )
    CMFCToolBar::OnNcPaint(this);
  else
    CMultiPaneFrameWnd::AdjustLayout((CMFCRibbonBaseElement *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1041E54F
// Name: protected: void CMFCTasksPaneFrameWnd::OnNcPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCTasksPaneFrameWnd::OnNcPaint(CMFCTasksPaneFrameWnd *this)
{
  CMFCTasksPaneFrameWnd *v1; // edi
  CObject *v2; // eax
  CObject *v3; // ebx
  CObList::CNode *m_pNodeHead; // esi
  CObList::CNode *v5; // eax
  CMFCCaptionButton *data; // edi
  int v7; // eax
  BOOL v8; // eax
  BOOL v9; // eax
  int bUseNavigationToolbar; // [esp+10h] [ebp-8h]
  int bMultiPages; // [esp+14h] [ebp-4h]

  v1 = this;
  v2 = (CObject *)((int (__fastcall *)(CMFCTasksPaneFrameWnd *))this->GetPane)(a1: this);
  v3 = AfxDynamicDownCast(pClass: &CMFCTasksPane::classCMFCTasksPane, pObject: v2);
  if ( v3 == nullptr || (bMultiPages = 1, (int)v3[278].__vftable <= 1) )
    bMultiPages = 0;
  if ( v3 == nullptr || (bUseNavigationToolbar = 1, v3[213].__vftable == nullptr) )
    bUseNavigationToolbar = 0;
  m_pNodeHead = v1->m_lstCaptionButtons.m_pNodeHead;
  if ( m_pNodeHead != nullptr )
  {
    do
    {
      v5 = m_pNodeHead;
      data = (CMFCCaptionButton *)m_pNodeHead->data;
      m_pNodeHead = m_pNodeHead->pNext;
      if ( CMFCCaptionButton::GetHit(this: (CMFCCaptionButton *)v5->data) - 23 <= 2 )
      {
        v7 = 0;
        if ( bMultiPages == 0 || bUseNavigationToolbar != 0 )
          v7 = 1;
        data->m_bHidden = v7;
      }
      if ( CMFCCaptionButton::GetHit(this: data) == 23 )
      {
        v8 = false;
        if ( v3 != nullptr )
          v8 = (int)v3[221].__vftable > 0;
        data->m_bEnabled = v8;
      }
      if ( CMFCCaptionButton::GetHit(this: data) == 24 )
      {
        v9 = v3 != nullptr && (int)v3[221].__vftable < (int)&v3[323].__vftable[-1].Serialize + 3;
        data->m_bEnabled = v9;
      }
    }
    while ( m_pNodeHead != nullptr );
    v1 = this;
  }
  CPaneFrameWnd::UpdateTooltips(this: v1);
  CPaneFrameWnd::OnNcPaint(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x105CA990
// Name: _CMapView3D::PreCreateWindow_::_2_::_dynamic_atexit_destructor_for__className__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMapView3D::PreCreateWindow_::_2_::_dynamic_atexit_destructor_for__className__()
{
  char *v0; // eax

  v0 = className_0.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)className_0.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v0 + 4))(a1: v0);
}

//------------------------------------------------------------------------------
// Address: 0x1034F937
// Name: protected: virtual int CStatusBar::OnChildNotify(unsigned int,unsigned int,long,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CStatusBar::OnChildNotify(
        CStatusBar *this,
        unsigned int message,
        unsigned int wParam,
        tagDRAWITEMSTRUCT *lParam,
        int *pResult)
{
  if ( message != 43 )
    return CWnd::OnChildNotify(this, uMsg: message, wParam, (int)lParam, pResult);
  this->DrawItem(this, a2: lParam);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1034F95A
// Name: protected: long CStatusBar::OnSetMinHeight(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CStatusBar::OnSetMinHeight(CStatusBar *this, unsigned int wParam, int __formal)
{
  int result; // eax

  result = CWnd::Default(this);
  this->m_nMinHeight = wParam;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1034F975
// Name: public: virtual struct CRuntimeClass __near * CStatusBar::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CStatusBar::GetRuntimeClass(CStatusBar *this)
{
  return &CStatusBar::classCStatusBar;
}

//------------------------------------------------------------------------------
// Address: 0x1034F97B
// Name: public: virtual int CStatusBar::CreateEx(class CWnd __near *,unsigned long,unsigned long,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CStatusBar::CreateEx(
        CStatusBar *this,
        CWnd *pParentWnd,
        unsigned int dwCtrlStyle,
        unsigned int dwStyle,
        unsigned int nID)
{
  CRect rect; // [esp+Ch] [ebp-14h] BYREF
  unsigned int dwStylea; // [esp+30h] [ebp+10h]

  this->m_dwStyle = dwStyle & 0x40FFFF;
  dwStylea = dwStyle & 0xFFBF0000 | 0x4E;
  if ( (CWnd::GetStyle(this: pParentWnd) & 0x40000) != 0 )
    dwStylea |= 0x100u;
  AfxEndDeferRegisterClass(fToRegister: 4096);
  memset(&rect, 0, sizeof(rect));
  SetRectEmpty(lprc: &rect);
  return CWnd::Create(
           this,
           lpszClassName: "msctls_statusbar32",
           lpszWindowName: nullptr,
           dwStyle: dwStylea | dwCtrlStyle,
           &rect,
           pParentWnd,
           nID,
           pContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1034FA16
// Name: public: virtual class CSize CStatusBar::CalcFixedLayout(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CStatusBar::CalcFixedLayout(CStatusBar *this, CSize *result, int __formal, int bHorz)
{
  void *v5; // eax
  int v6; // ebx
  int v7; // eax
  int m_nMinHeight; // esi
  CClientDC dc; // [esp+Ch] [ebp-70h] BYREF
  void *hOldFont; // [esp+20h] [ebp-5Ch]
  tagTEXTMETRICA tm; // [esp+24h] [ebp-58h] BYREF
  CRect rect; // [esp+5Ch] [ebp-20h] BYREF
  int rgBorders[3]; // [esp+6Ch] [ebp-10h] BYREF

  CClientDC::CClientDC(this: &dc, pWnd: nullptr);
  v5 = (void *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x31u, wParam: 0, lParam: 0);
  hOldFont = nullptr;
  if ( v5 != nullptr )
    hOldFont = SelectObject(hdc: dc.m_hDC, h: v5);
  GetTextMetricsA(hdc: dc.m_hAttribDC, lptm: &tm);
  if ( hOldFont != nullptr )
    SelectObject(hdc: dc.m_hDC, h: hOldFont);
  CClientDC::~CClientDC(this: &dc);
  memset(&rect, 0, sizeof(rect));
  SetRectEmpty(lprc: &rect);
  this->CalcInsideRect(this, a2: &rect, a3: bHorz);
  this->DefWindowProcA(this, a2: 1031u, a3: 0, a4: (int)rgBorders);
  result->cy = 0;
  v6 = rect.bottom - rect.top;
  result->cx = 0x7FFF;
  v7 = 2 * (rgBorders[1] + GetSystemMetrics(nIndex: 6)) - v6 - tm.tmInternalLeading + tm.tmHeight - 1;
  result->cy = v7;
  m_nMinHeight = this->m_nMinHeight;
  if ( v7 < m_nMinHeight )
    result->cy = m_nMinHeight;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1034FB08
// Name: protected: void CStatusBar::OnNcCalcSize(int,struct tagNCCALCSIZE_PARAMS __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CStatusBar::OnNcCalcSize(CStatusBar *this, int __formal, tagNCCALCSIZE_PARAMS *lpncsp)
{
  CRect rect; // [esp+8h] [ebp-14h] BYREF

  memset(&rect, 0, sizeof(rect));
  SetRectEmpty(lprc: &rect);
  CControlBar::CalcInsideRect(this, &rect, bHorz: 1);
  lpncsp->rgrc[0].left += rect.left;
  lpncsp->rgrc[0].top += rect.top - 2;
  lpncsp->rgrc[0].right += rect.right;
  lpncsp->rgrc[0].bottom += rect.bottom;
}

//------------------------------------------------------------------------------
// Address: 0x103623D7
// Name: protected: int CMDIChildWndEx::OnNcActivate(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIChildWndEx::OnNcActivate(CMDIChildWndEx *this, CDC *bActive)
{
  CWinApp *m_pCurrentWinApp; // eax
  int v4; // eax
  int bIsOwnerDraw; // [esp+Ch] [ebp-4h]
  int bRes; // [esp+18h] [ebp+8h]

  bIsOwnerDraw = CFrameImpl::OnNcActivate(this: &this->m_Impl, (int)bActive);
  if ( bIsOwnerDraw != 0 )
    SendMessageA(hWnd: this->m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
  bRes = CWnd::OnEraseBkgnd((CToolBar *)this, __formal: bActive);
  if ( bIsOwnerDraw != 0 )
  {
    SendMessageA(hWnd: this->m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
    RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x585u);
  }
  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  if ( m_pCurrentWinApp != nullptr )
  {
    v4 = (int)m_pCurrentWinApp->GetDataRecoveryHandler(this: m_pCurrentWinApp);
    if ( v4 == 0 || (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 48))(a1: v4) == 0 )
      CMDIChildWndEx::InvalidateIconicBitmaps(this);
  }
  return bRes;
}

//------------------------------------------------------------------------------
// Address: 0x1036246A
// Name: protected: void CMDIChildWndEx::OnNcMouseMove(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIChildWndEx::OnNcMouseMove(CMDIChildWndEx *this, unsigned int nHitTest, CPoint point)
{
  CFrameImpl::OnNcMouseMove(this: &this->m_Impl, __formal: nHitTest, point);
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x10362492
// Name: protected: long CMDIChildWndEx::OnNcHitTest(class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIChildWndEx::OnNcHitTest(CMDIChildWndEx *this, CPoint point)
{
  int result; // eax

  result = CFrameImpl::OnNcHitTest(this: &this->m_Impl, point);
  if ( result == 0 )
    return CWnd::Default(this);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103624BB
// Name: protected: void CMDIChildWndEx::OnNcCalcSize(int,struct tagNCCALCSIZE_PARAMS __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIChildWndEx::OnNcCalcSize(CMDIChildWndEx *this, int bCalcValidRects, tagNCCALCSIZE_PARAMS *lpncsp)
{
  CMDIFrameWndEx *m_pMDIFrame; // eax
  CMFCVisualManager *Instance; // eax

  m_pMDIFrame = this->m_pMDIFrame;
  if ( (m_pMDIFrame == nullptr || m_pMDIFrame->m_wndClientArea.m_bIsMDITabbedGroup == 0)
    && !IsZoomed(hWnd: this->m_hWnd) )
  {
    Instance = CMFCVisualManager::GetInstance();
    if ( Instance->IsOwnerDrawCaption(this: Instance) != 0 && (CWnd::GetStyle(this) & 0x800000) == 0 )
      lpncsp->rgrc[0].top += GetSystemMetrics(nIndex: 4);
  }
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x10362520
// Name: protected: void CMDIChildWndEx::OnLButtonUp(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIChildWndEx::OnLButtonUp(CMDIChildWndEx *this, unsigned int nFlags, CPoint point)
{
  CFrameImpl::OnLButtonUp(this: &this->m_Impl, __formal: point);
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x10362545
// Name: protected: void CMDIChildWndEx::OnMouseMove(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIChildWndEx::OnMouseMove(CMDIChildWndEx *this, unsigned int nFlags, CPoint point)
{
  CFrameImpl::OnMouseMove(this: &this->m_Impl, point);
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1036256A
// Name: protected: void CMDIChildWndEx::OnLButtonDown(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIChildWndEx::OnLButtonDown(CMDIChildWndEx *this, unsigned int nFlags, CPoint point)
{
  CFrameImpl::OnLButtonDown(this: &this->m_Impl, __formal: point);
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1036258F
// Name: public: void CMDIChildWndEx::AddTabbedPane(class CDockablePane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIChildWndEx::AddTabbedPane(CMDIChildWndEx *this, CDockablePane *pControlBar)
{
  this->m_pTabbedControlBar = pControlBar;
  pControlBar->OnBeforeChangeParent(this: (CBasePane *)pControlBar, a2: this, a3: 0);
  this->m_pTabbedControlBar->EnableGripper(this: (CBasePane *)this->m_pTabbedControlBar, a2: 0);
  CWnd::SetParent(this: &this->m_pTabbedControlBar->CPane, pWndNewParent: this);
  CWnd::ShowWindow(this: &this->m_pTabbedControlBar->CPane, nCmdShow: 5);
  this->m_pTabbedControlBar->m_bIsMDITabbed = 1;
  CDockingManager::RemoveHiddenMDITabbedBar(this: &this->m_pMDIFrame->m_dockManager, pBar: this->m_pTabbedControlBar);
  CMDIChildWndEx::AdjustClientArea(this);
}

//------------------------------------------------------------------------------
// Address: 0x10362607
// Name: protected: void CMDIChildWndEx::OnNcRButtonUp(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIChildWndEx::OnNcRButtonUp(CMDIChildWndEx *this, unsigned int nHitTest, CPoint point)
{
  if ( this->m_pTabbedControlBar != nullptr && nHitTest == 2 && !IsZoomed(hWnd: this->m_hWnd) )
    ((void (__thiscall *)(CDockablePane *, int, int))this->m_pTabbedControlBar->OnShowControlBarMenu)(
      a1: this->m_pTabbedControlBar,
      a2: point.x,
      a3: point.y);
  else
    CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1036264F
// Name: public: virtual class CWnd __near * CMDIChildWndEx::GetTaskbarPreviewWnd(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMDIChildWndEx *__thiscall CMDIChildWndEx::GetTaskbarPreviewWnd(CMDIChildWndEx *this)
{
  CWnd *DescendantWindow; // eax
  CWnd *v3; // ebx
  HWND Parent; // eax
  CMDIChildWndEx *v5; // eax
  CMDIChildWndEx *v6; // esi
  HWND Window; // eax

  DescendantWindow = CWnd::GetDescendantWindow(hWnd: this->m_hWnd, nID: 59648, bOnlyPerm: 0);
  v3 = DescendantWindow;
  if ( DescendantWindow != nullptr && DescendantWindow->m_hWnd != nullptr )
  {
    Parent = GetParent(hWnd: DescendantWindow->m_hWnd);
    v5 = (CMDIChildWndEx *)CWnd::FromHandle(hWnd: Parent);
    v6 = v5;
    if ( v5 != this
      && v5 != nullptr
      && v5->m_hWnd != nullptr
      && CObject::IsKindOf(this: v5, pClass: &CSplitterWnd::classCSplitterWnd) != 0 )
    {
      return v6;
    }
  }
  else
  {
    Window = GetWindow(hWnd: this->m_hWnd, uCmd: 5u);
    return (CMDIChildWndEx *)CWnd::FromHandle(hWnd: Window);
  }
  return (CMDIChildWndEx *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x103626BC
// Name: public: virtual void CMDIChildWndEx::OnPressTaskbarThmbnailCloseButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIChildWndEx::OnPressTaskbarThmbnailCloseButton(CMDIChildWndEx *this)
{
  CFrameWnd *TopLevelFrame; // eax
  CWnd *v3; // eax
  CDocument *v4; // eax

  TopLevelFrame = CWnd::GetTopLevelFrame(this);
  v3 = (CWnd *)AfxDynamicDownCast(pClass: &CMDIFrameWndEx::classCMDIFrameWndEx, pObject: TopLevelFrame);
  if ( v3 != nullptr && CWnd::IsWindowEnabled(this: v3) != 0 )
  {
    v4 = this->GetActiveDocument(this);
    if ( v4 != nullptr && v4->IsModified(this: v4) != 0 )
      this->ActivateTopLevelFrame(this);
    PostMessageA(hWnd: this->m_hWnd, Msg: 0x10u, wParam: 0, lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10362716
// Name: public: virtual class CRect CMDIChildWndEx::GetTaskbarThumbnailClipRect(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRect *__thiscall CMDIChildWndEx::GetTaskbarThumbnailClipRect(CMDIChildWndEx *this, CRect *result)
{
  result->left = 0;
  result->top = 0;
  result->right = 0;
  result->bottom = 0;
  GetWindowRect(hWnd: this->m_hWnd, lpRect: result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1036273D
// Name: protected: virtual int CMDIChildWndEx::SetTaskbarThumbnailClipRect(class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMDIChildWndEx::SetTaskbarThumbnailClipRect(CMDIChildWndEx *this, CRect rect)
{
  CFrameWnd *TopLevelFrame; // eax
  CMDIFrameWnd *v5; // eax
  CWnd *v6; // edi
  ITaskbarList3 *ITaskbarList3; // esi
  CRect *p_rect; // eax

  if ( afxGlobalData.bIsWindows7 == 0 )
    return false;
  TopLevelFrame = CWnd::GetTopLevelFrame(this);
  v5 = (CMDIFrameWnd *)AfxDynamicDownCast(pClass: &CMDIFrameWndEx::classCMDIFrameWndEx, pObject: TopLevelFrame);
  v6 = v5;
  if ( v5 == nullptr || CMDIFrameWnd::MDIGetActive(this: v5, pbMaximized: nullptr) != this )
    return false;
  if ( !CRect::IsRectNull(this: &rect) )
    CWnd::ScreenToClient(this: v6, lpRect: &rect);
  ITaskbarList3 = AFX_GLOBAL_DATA::GetITaskbarList3(this: &afxGlobalData);
  if ( ITaskbarList3 == nullptr )
    return false;
  if ( CRect::IsRectNull(this: &rect) || IsRectEmpty(lprc: &rect) )
    p_rect = nullptr;
  else
    p_rect = &rect;
  return ITaskbarList3->SetThumbnailClip(this: ITaskbarList3, a2: v6->m_hWnd, a3: p_rect) >= 0;
}

//------------------------------------------------------------------------------
// Address: 0x103627E1
// Name: protected: virtual void CMDIChildWndEx::ActivateTopLevelFrame(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIChildWndEx::ActivateTopLevelFrame(CMDIChildWndEx *this)
{
  CFrameWnd *TopLevelFrame; // eax
  CWnd *v3; // esi

  TopLevelFrame = CWnd::GetTopLevelFrame(this);
  v3 = (CWnd *)AfxDynamicDownCast(pClass: &CMDIFrameWndEx::classCMDIFrameWndEx, pObject: TopLevelFrame);
  if ( v3 != nullptr )
  {
    this->ActivateFrame(this, a2: -1);
    SetForegroundWindow(hWnd: v3->m_hWnd);
    if ( IsIconic(hWnd: v3->m_hWnd) )
      CWnd::ShowWindow(this: v3, nCmdShow: 9);
    else
      CWnd::ShowWindow(this: v3, nCmdShow: 5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10362831
// Name: public: static class CObject __near * CMDITabProxyWnd::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMDITabProxyWnd *__stdcall CMDITabProxyWnd::CreateObject()
{
  CMDITabProxyWnd *v0; // ecx
  CMDITabProxyWnd *result; // eax

  v0 = (CMDITabProxyWnd *)operator new(nSize: 0x78u);
  result = nullptr;
  if ( v0 != nullptr )
    return CMDITabProxyWnd::CMDITabProxyWnd(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10362885
// Name: protected: int CMDITabProxyWnd::IsMDIChildActive(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMDITabProxyWnd::IsMDIChildActive(CMDITabProxyWnd *this)
{
  CFrameWnd *TopLevelFrame; // eax
  CMDIFrameWnd *v3; // edi

  TopLevelFrame = CWnd::GetTopLevelFrame(this: this->m_pRelatedMDIChildFrame);
  v3 = (CMDIFrameWnd *)AfxDynamicDownCast(pClass: &CMDIFrameWndEx::classCMDIFrameWndEx, pObject: TopLevelFrame);
  return !IsIconic(hWnd: v3->m_hWnd)
      && this->m_pRelatedMDIChildFrame == CMDIFrameWnd::MDIGetActive(this: v3, pbMaximized: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1038E662
// Name: protected: long CMDIFrameWndEx::OnSetText(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWndEx::OnSetText(CMDIFrameWndEx *this, unsigned int __formal, const char *lParam)
{
  int v4; // edi

  v4 = CWnd::Default(this);
  CFrameImpl::OnSetText(this: &this->m_Impl, __formal: lParam);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1038E688
// Name: protected: int CMDIFrameWndEx::OnNcActivate(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWndEx::OnNcActivate(CMDIFrameWndEx *this, int bActive)
{
  if ( CFrameImpl::OnNcActivate(this: &this->m_Impl, bActive) != 0 )
    return 1;
  else
    return CFrameWnd::OnNcActivate(this, bActive);
}

//------------------------------------------------------------------------------
// Address: 0x1038E6B6
// Name: protected: long CMDIFrameWndEx::OnChangeVisualManager(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWndEx::OnChangeVisualManager(
        CMDIFrameWndEx *this,
        unsigned int __formal,
        unsigned int __formala)
{
  CFrameImpl::OnChangeVisualManager(this: &this->m_Impl);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1038E6C6
// Name: public: int CMDIFrameWndEx::GetRegisteredWithTaskBarMDIChildCount(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWndEx::GetRegisteredWithTaskBarMDIChildCount(CMDIFrameWndEx *this)
{
  int v1; // ebx
  HWND i; // eax
  CWnd *v3; // eax
  CMDIChildWndEx *v4; // eax
  HWND v5; // edi

  v1 = 0;
  for ( i = GetWindow(hWnd: this->m_hWndMDIClient, uCmd: 5u); ; i = GetWindow(hWnd: v5, uCmd: 2u) )
  {
    v5 = i;
    if ( i == nullptr )
      break;
    v3 = CWnd::FromHandle(hWnd: i);
    v4 = (CMDIChildWndEx *)AfxDynamicDownCast(pClass: &CMDIChildWndEx::classCMDIChildWndEx, pObject: v3);
    if ( v4 != nullptr && CMDIChildWndEx::IsRegisteredWithTaskbarTabs(this: v4) != 0 )
      ++v1;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x1038E711
// Name: protected: long CMDIFrameWndEx::OnDWMCompositionChanged(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWndEx::OnDWMCompositionChanged(
        CMDIFrameWndEx *this,
        unsigned int __formal,
        unsigned int __formala)
{
  CFrameImpl::OnDWMCompositionChanged(this: &this->m_Impl);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1038E721
// Name: protected: long CMDIFrameWndEx::OnPowerBroadcast(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMDIFrameWndEx::OnPowerBroadcast(CFrameWndEx *this, unsigned int wp, int __formal)
{
  int v3; // esi

  v3 = CWnd::Default(this);
  if ( wp == 7 )
    AFX_GLOBAL_DATA::Resume(this: &afxGlobalData);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1038E745
// Name: protected: void CMDIFrameWndEx::OnWindowPosChanged(struct tagWINDOWPOS __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIFrameWndEx::OnWindowPosChanged(CMDIFrameWndEx *this, tagWINDOWPOS *lpwndpos)
{
  CMDIChildWnd *v3; // eax
  CMDIChildWnd *v4; // eax

  if ( (lpwndpos->flags & 0x20) != 0 )
    CFrameImpl::OnWindowPosChanging(this: &this->m_Impl, lpwndpos);
  CWnd::Default(this);
  if ( this->m_Impl.m_pMenuBar != nullptr )
  {
    v3 = CMDIFrameWnd::MDIGetActive(this, pbMaximized: (int *)&lpwndpos);
    if ( v3 != nullptr && lpwndpos != nullptr )
      CMFCMenuBar::SetMaximizeMode(this: this->m_Impl.m_pMenuBar, bMax: 1, pWnd: v3, bRecalcLayout: 1);
    else
      CMFCMenuBar::SetMaximizeMode(this: this->m_Impl.m_pMenuBar, bMax: 0, pWnd: nullptr, bRecalcLayout: 1);
  }
  if ( this->m_Impl.m_pRibbonBar != nullptr )
  {
    v4 = CMDIFrameWnd::MDIGetActive(this, pbMaximized: (int *)&lpwndpos);
    if ( v4 != nullptr && lpwndpos != nullptr )
      CMFCRibbonBar::SetMaximizeMode(this: this->m_Impl.m_pRibbonBar, bMax: 1, pWnd: v4);
    else
      CMFCRibbonBar::SetMaximizeMode(this: this->m_Impl.m_pRibbonBar, bMax: 0, pWnd: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1038E7D2
// Name: public: virtual int CMDIFrameWndEx::PreTranslateMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMDIFrameWndEx::PreTranslateMessage(CMDIFrameWndEx *this, CWnd *pMsg)
{
  unsigned int m_dwRef; // eax
  int v5; // eax
  unsigned int v6; // eax
  CMFCRibbonBar *v7; // ecx
  CSmartDockingManager *m_pSDManager; // ecx
  HWND Capture; // eax
  CWnd *v11; // eax
  CObject *v12; // eax
  CMFCRibbonBar *m_pRibbonBar; // ecx
  int v14; // ebx
  HIMC Context; // eax
  unsigned int m_pOuterUnknown; // eax
  HWND Focus; // eax
  CWnd *v18; // eax
  CWnd *m_pMenuBar; // ecx
  CWnd *v20; // eax
  tagPOINT v21; // [esp-Ch] [ebp-24h]
  HWND__ *v22; // [esp-4h] [ebp-1Ch]
  HWND__ *v23; // [esp-4h] [ebp-1Ch]
  tagPOINT Point; // [esp+Ch] [ebp-Ch] BYREF
  int bIMEActive; // [esp+14h] [ebp-4h]
  CWnd *pWnd; // [esp+20h] [ebp+8h]
  CWnd *pWnda; // [esp+20h] [ebp+8h]

  m_dwRef = pMsg->m_dwRef;
  if ( m_dwRef > 0x105 )
  {
    if ( m_dwRef == 512 )
    {
      v23 = (HWND__ *)pMsg->__vftable;
      Point.x = SLOWORD(pMsg->m_xInnerUnknown);
      Point.y = SHIWORD(pMsg->m_xInnerUnknown);
      v20 = CWnd::FromHandle(hWnd: v23);
      if ( v20 != nullptr )
        ClientToScreen(hWnd: v20->m_hWnd, lpPoint: &Point);
      v5 = CFrameImpl::ProcessMouseMove(this: &this->m_Impl, pt: Point);
    }
    else
    {
      if ( m_dwRef == 513 )
        goto LABEL_64;
      if ( m_dwRef <= 0x203 )
        return CMDIFrameWnd::PreTranslateMessage(this, (tagMSG *)pMsg);
      if ( m_dwRef <= 0x205 )
        goto LABEL_64;
      if ( m_dwRef <= 0x206 )
        return CMDIFrameWnd::PreTranslateMessage(this, (tagMSG *)pMsg);
      if ( m_dwRef <= 0x208 )
      {
LABEL_64:
        v22 = (HWND__ *)pMsg->__vftable;
        Point.x = SLOWORD(pMsg->m_xInnerUnknown);
        Point.y = SHIWORD(pMsg->m_xInnerUnknown);
        pWnda = CWnd::FromHandle(hWnd: v22);
        if ( pWnda != nullptr && IsWindow(hWnd: (HWND)pMsg->__vftable) )
          ClientToScreen(hWnd: pWnda->m_hWnd, lpPoint: &Point);
        if ( CFrameImpl::ProcessMouseClick(
               this: &this->m_Impl,
               uiMsg: pMsg->m_dwRef,
               pt: Point,
               hwnd: (HWND__ *)pMsg->__vftable) == 0
          && IsWindow(hWnd: (HWND)pMsg->__vftable) )
        {
          return CMDIFrameWnd::PreTranslateMessage(this, (tagMSG *)pMsg);
        }
        return true;
      }
      if ( m_dwRef != 522 )
        return CMDIFrameWnd::PreTranslateMessage(this, (tagMSG *)pMsg);
      v5 = CFrameImpl::ProcessMouseWheel(
             this: &this->m_Impl,
             wParam: (unsigned int)pMsg->m_pOuterUnknown,
             lParam: pMsg->m_xInnerUnknown);
    }
    goto LABEL_23;
  }
  if ( m_dwRef == 261 )
  {
    m_pRibbonBar = this->m_Impl.m_pRibbonBar;
    if ( m_pRibbonBar != nullptr
      && CMFCRibbonBar::OnSysKeyUp(
           this: m_pRibbonBar,
           pFrameWnd: this,
           wParam: (unsigned int)pMsg->m_pOuterUnknown,
           __formal: pMsg->m_xInnerUnknown) != 0 )
    {
      return true;
    }
    Point.y = GetKeyState(nVirtKey: 17) < 0;
    v14 = (unsigned __int16)GetKeyState(nVirtKey: 16) >> 15;
    Context = ImmGetContext(a1: this->m_hWnd);
    pWnd = (CWnd *)Context;
    bIMEActive = Context != nullptr && ImmGetOpenStatus(a1: Context);
    if ( pWnd != nullptr )
      ImmReleaseContext(a1: this->m_hWnd, a2: (HIMC)pWnd);
    if ( this->m_Impl.m_pMenuBar != nullptr )
    {
      m_pOuterUnknown = (unsigned int)pMsg->m_pOuterUnknown;
      if ( m_pOuterUnknown == 18 || m_pOuterUnknown == 121 && Point.y == 0 && v14 == 0 && bIMEActive == 0 )
      {
        Focus = GetFocus();
        v18 = CWnd::FromHandle(hWnd: Focus);
        m_pMenuBar = this->m_Impl.m_pMenuBar;
        if ( m_pMenuBar == v18 )
        {
          m_pMenuBar = this;
        }
        else if ( (pMsg->m_xInnerUnknown & 0x20000000) != 0 )
        {
          return true;
        }
        CWnd::SetFocus(this: m_pMenuBar);
        return true;
      }
    }
    if ( CMFCPopupMenu::m_pActivePopupMenu == nullptr )
      return CMDIFrameWnd::PreTranslateMessage(this, (tagMSG *)pMsg);
    v5 = IsWindow(hWnd: *((HWND *)CMFCPopupMenu::m_pActivePopupMenu + 8));
    goto LABEL_23;
  }
  if ( m_dwRef <= 0xA8 )
  {
    if ( m_dwRef >= 0xA7 )
    {
LABEL_9:
      v21.y = SHIWORD(pMsg->m_xInnerUnknown);
      v21.x = SLOWORD(pMsg->m_xInnerUnknown);
      v5 = CFrameImpl::ProcessMouseClick(this: &this->m_Impl, uiMsg: m_dwRef, pt: v21, hwnd: (HWND__ *)pMsg->__vftable);
LABEL_23:
      if ( v5 == 0 )
        return CMDIFrameWnd::PreTranslateMessage(this, (tagMSG *)pMsg);
      return true;
    }
    if ( m_dwRef != 123 )
    {
      if ( m_dwRef <= 0xA0 || m_dwRef > 0xA2 && m_dwRef - 164 > 1 )
        return CMDIFrameWnd::PreTranslateMessage(this, (tagMSG *)pMsg);
      goto LABEL_9;
    }
LABEL_15:
    if ( afxGlobalData.m_bSysUnderlineKeyboardShortcuts == 0 && afxGlobalData.m_bUnderlineKeyboardShortcuts == 0 )
    {
      afxGlobalData.m_bUnderlineKeyboardShortcuts = 1;
      CMFCToolBar::RedrawUnderlines();
    }
    if ( CMFCPopupMenu::m_pActivePopupMenu != nullptr
      && IsWindow(hWnd: *((HWND *)CMFCPopupMenu::m_pActivePopupMenu + 8))
      && pMsg->m_pOuterUnknown == (IUnknown *)18 )
    {
      SendMessageA(hWnd: *((HWND *)CMFCPopupMenu::m_pActivePopupMenu + 8), Msg: 0x10u, wParam: 0, lParam: 0);
      return true;
    }
    v5 = CFrameImpl::ProcessKeyboard(this: &this->m_Impl, nKey: (int)pMsg->m_pOuterUnknown, pbProcessAccel: nullptr);
    goto LABEL_23;
  }
  v6 = m_dwRef - 256;
  if ( v6 == 0 )
  {
    if ( CFrameImpl::IsHelpKey(lpMsg: (tagMSG *)pMsg) != 0
      || CFrameImpl::ProcessKeyboard(this: &this->m_Impl, nKey: (int)pMsg->m_pOuterUnknown, pbProcessAccel: nullptr) == 0 )
    {
      if ( pMsg->m_pOuterUnknown != (IUnknown *)27 )
        return CMDIFrameWnd::PreTranslateMessage(this, (tagMSG *)pMsg);
      if ( this->m_Impl.m_FullScreenMgr.m_bFullScreen != 0 )
        CFullScreenImpl::RestoreState(this: &this->m_Impl.m_FullScreenMgr, pFrame: this);
      m_pSDManager = this->m_dockManager.m_pSDManager;
      if ( m_pSDManager != nullptr && m_pSDManager->m_bCreated != 0 && m_pSDManager->m_bStarted != 0 )
        CSmartDockingManager::CauseCancelMode(this: m_pSDManager);
      Capture = GetCapture();
      v11 = CWnd::FromHandle(hWnd: Capture);
      v12 = AfxDynamicDownCast(pClass: &CPaneDivider::classCPaneDivider, pObject: v11);
      if ( v12 == nullptr )
        return CMDIFrameWnd::PreTranslateMessage(this, (tagMSG *)pMsg);
      SendMessageA(hWnd: (HWND)v12[8].__vftable, Msg: 0x1Fu, wParam: 0, lParam: 0);
    }
    return true;
  }
  if ( v6 == 4 )
  {
    v7 = this->m_Impl.m_pRibbonBar;
    if ( v7 != nullptr
      && CMFCRibbonBar::OnSysKeyDown(
           this: v7,
           pFrameWnd: this,
           wParam: (unsigned int)pMsg->m_pOuterUnknown,
           lParam: pMsg->m_xInnerUnknown) != 0 )
    {
      return true;
    }
    goto LABEL_15;
  }
  return CMDIFrameWnd::PreTranslateMessage(this, (tagMSG *)pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x1038EB56
// Name: protected: void CMDIFrameWndEx::OnClose(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIFrameWndEx::OnClose(CMDIFrameWndEx *this)
{
  CFrameWnd *m_pPrintPreviewFrame; // eax
  CMDIFrameWndEx_vtbl *v3; // eax
  COleClientItem *v4; // eax

  m_pPrintPreviewFrame = this->m_pPrintPreviewFrame;
  if ( m_pPrintPreviewFrame != nullptr )
  {
    SendMessageA(hWnd: m_pPrintPreviewFrame->m_hWnd, Msg: 0x10u, wParam: 0, lParam: 0);
    this->m_pPrintPreviewFrame = nullptr;
  }
  else
  {
    if ( CFrameImpl::IsPrintPreview(this: &this->m_Impl) == 0 )
    {
      v3 = this->__vftable;
      this->m_bClosing = 1;
      v4 = v3->GetInPlaceActiveItem(this);
      if ( v4 != nullptr )
        COleClientItem::Deactivate(this: v4);
      CFrameImpl::OnCloseFrame(this: &this->m_Impl);
    }
    CFrameWnd::OnClose(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1038EBC1
// Name: public: virtual void CMDIFrameWndEx::OnClosePopupMenu(class CMFCPopupMenu __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIFrameWndEx::OnClosePopupMenu(CMDIFrameWndEx *this, CMFCPopupMenu *pMenuPopup)
{
  CMFCPopupMenu *ParentPopupMenu; // eax

  if ( afxGlobalData.m_bEnableAccessibility != 0 && pMenuPopup != nullptr )
  {
    ParentPopupMenu = CMFCPopupMenu::GetParentPopupMenu(this: pMenuPopup);
    if ( pMenuPopup->m_bEscClose != 0 || ParentPopupMenu != nullptr || pMenuPopup->m_pParentBtn == nullptr )
      NotifyWinEvent(event: 7u, hwnd: pMenuPopup->m_hWnd, idObject: 0, idChild: 0);
    else
      NotifyWinEvent(event: 5u, hwnd: pMenuPopup->m_hWnd, idObject: 0, idChild: 0);
  }
  if ( CMFCPopupMenu::m_pActivePopupMenu == (HWND)pMenuPopup )
    CMFCPopupMenu::m_pActivePopupMenu = nullptr;
  CDockingManager::OnClosePopupMenu(this: &this->m_dockManager);
}

//------------------------------------------------------------------------------
// Address: 0x1038EC2F
// Name: protected: virtual void CMDIFrameWndEx::HtmlHelpA(unsigned long,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMDIFrameWndEx::HtmlHelpA(CMDIFrameWndEx *this, unsigned int dwData, unsigned int nCmd)
{
  if ( dwData != 0 || this->m_bContextHelp == 0 )
    CWnd::HtmlHelpA(this, dwData, nCmd);
  else
    CMDIFrameWndEx::OnContextHelp(this);
}

//------------------------------------------------------------------------------
// Address: 0x1039634F
// Name: protected: virtual void CPaneFrameWnd::OnPressButtons(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneFrameWnd::OnPressButtons(CPaneFrameWnd *this, unsigned int nHit)
{
  CWnd *v3; // eax
  CObject *v4; // edi
  CObject *v5; // esi
  CAfxStringMgr *StringManager; // eax
  HINSTANCE__ *StringResourceHandle; // eax
  int v8; // eax
  char *v9; // eax
  CMFCPopupMenu *v10; // esi
  char *v11; // eax
  const CMFCToolBarMenuButton *v12; // eax
  CMFCPopupMenuBar *v13; // eax
  HMENU__ *v14; // eax
  char *v15; // eax
  CMFCPopupMenu *v16; // edi
  CAfxStringMgr *v17; // eax
  HINSTANCE__ *v18; // eax
  int v19; // eax
  int v20; // eax
  HMENU__ *v21; // eax
  CMFCPopupMenu_vtbl *v22; // edx
  int cy; // edi
  unsigned int v24; // [esp-14h] [ebp-408h]
  char *m_pszData; // [esp-8h] [ebp-3FCh]
  char *v26; // [esp-8h] [ebp-3FCh]
  char *v27; // [esp-4h] [ebp-3F8h]
  CSize v28; // [esp+10h] [ebp-3E4h] BYREF
  tagPOINT Point; // [esp+18h] [ebp-3DCh] BYREF
  CMFCCaptionButton *v30; // [esp+20h] [ebp-3D4h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > result; // [esp+24h] [ebp-3D0h] BYREF
  CMFCPopupMenu *v32; // [esp+28h] [ebp-3CCh]
  ATL::CSimpleStringT<char,0> v33; // [esp+2Ch] [ebp-3C8h] BYREF
  ATL::CSimpleStringT<char,0> v34; // [esp+30h] [ebp-3C4h] BYREF
  CMFCToolBarMenuButton v35; // [esp+34h] [ebp-3C0h] BYREF
  CMFCToolBarMenuButton v36; // [esp+11Ch] [ebp-2D8h] BYREF
  CMFCToolBarMenuButton button; // [esp+204h] [ebp-1F0h] BYREF
  CMFCToolBarMenuButton v38; // [esp+2ECh] [ebp-108h] BYREF
  tagPOINT v39; // [esp+3D4h] [ebp-20h] BYREF
  int v40; // [esp+3F0h] [ebp-4h]

  v28.cy = (int)this;
  if ( CMFCToolBar::m_bCustomizeMode == 0 && nHit == 25 )
  {
    v30 = CPaneFrameWnd::FindButton(this, uiHit: 0x19u);
    if ( v30 != nullptr )
    {
      v3 = this->GetPane(this);
      v4 = v3;
      if ( v3 != nullptr
        && v3->m_hWnd != nullptr
        && CObject::IsKindOf(this: v3, pClass: &CMFCToolBar::classCMFCToolBar) != 0 )
      {
        v5 = AfxDynamicDownCast(pClass: &CMFCToolBar::classCMFCToolBar, pObject: v4);
        v33.m_pszData = (char *)v5[808].__vftable;
        if ( v33.m_pszData != nullptr && v5[725].__vftable != nullptr )
        {
          v30->m_bPushed = 1;
          StringManager = AfxGetStringManager();
          ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v34, pStringMgr: StringManager);
          v40 = 0;
          CWnd::GetWindowTextA(
            this: (CWnd *)v5,
            rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v34);
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::TrimLeft(this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v34);
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::TrimRight(this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v34);
          if ( *((_DWORD *)v34.m_pszData - 3) == 0 )
          {
            StringResourceHandle = AfxFindStringResourceHandle(__formal: 0x3EE8u);
            v8 = StringResourceHandle != nullptr
               ? ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
                   this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v34,
                   hInstance: StringResourceHandle,
                   nID: 0x3EE8u)
               : 0;
            if ( v8 == 0 )
              goto LABEL_14;
          }
          v9 = (char *)operator new(nSize: 0x10C4u);
          result.m_pszData = v9;
          LOBYTE(v40) = 1;
          v10 = v9 != nullptr ? CMFCPopupMenu::CMFCPopupMenu(this: (CMFCPopupMenu *)v9) : nullptr;
          LOBYTE(v40) = 0;
          v11 = (char *)operator new(nSize: 0x10C4u);
          result.m_pszData = v11;
          LOBYTE(v40) = 2;
          v32 = v11 != nullptr ? CMFCPopupMenu::CMFCPopupMenu(this: (CMFCPopupMenu *)v11) : nullptr;
          LOBYTE(v40) = 0;
          v12 = CMFCToolBarMenuButton::CMFCToolBarMenuButton(
                  this: &v35,
                  uiID: 1u,
                  hMenu: nullptr,
                  iImage: -1,
                  lpszText: "DUMMY",
                  bUserButton: 0);
          LOBYTE(v40) = 3;
          CMFCPopupMenu::InsertItem(this: v32, button: v12, iInsertAt: -1);
          LOBYTE(v40) = 0;
          CMFCToolBarMenuButton::~CMFCToolBarMenuButton(this: &v35);
          v13 = v32->GetMenuBar(this: v32);
          m_pszData = v34.m_pszData;
          v14 = v13->ExportToMenu(this: v13);
          CMFCToolBarMenuButton::CMFCToolBarMenuButton(
            this: &button,
            uiID: 0xFFFFFFFF,
            hMenu: v14,
            iImage: -1,
            lpszText: m_pszData,
            bUserButton: 0);
          LOBYTE(v40) = 4;
          v26 = CMFCCustomizeButton::GetCustomizeText(this: (CHelpComboBoxButton *)v33.m_pszData, &result)->m_pszData;
          v24 = *((_DWORD *)v33.m_pszData + 58);
          LOBYTE(v40) = 5;
          CMFCToolBarMenuButton::CMFCToolBarMenuButton(
            this: &v36,
            uiID: v24,
            hMenu: nullptr,
            iImage: -1,
            lpszText: v26,
            bUserButton: 0);
          LOBYTE(v40) = 7;
          ATL::CStringData::Release(this: (ATL::CStringData *)result.m_pszData - 1);
          v15 = (char *)operator new(nSize: 0x10C4u);
          v33.m_pszData = v15;
          LOBYTE(v40) = 8;
          v16 = v15 != nullptr ? CMFCPopupMenu::CMFCPopupMenu(this: (CMFCPopupMenu *)v15) : nullptr;
          LOBYTE(v40) = 7;
          CMFCPopupMenu::InsertItem(this: v16, &button, iInsertAt: -1);
          CMFCPopupMenu::InsertItem(this: v16, button: &v36, iInsertAt: -1);
          v17 = AfxGetStringManager();
          ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v33, pStringMgr: v17);
          LOBYTE(v40) = 9;
          v18 = AfxFindStringResourceHandle(__formal: 0x427Au);
          v19 = v18 != nullptr
              ? ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
                  this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v33,
                  hInstance: v18,
                  nID: 0x427Au)
              : 0;
          if ( v19 == 0 )
LABEL_14:
            AfxThrowInvalidArgException();
          v20 = (int)v16->GetMenuBar(this: v16);
          v27 = v33.m_pszData;
          v21 = (HMENU__ *)(*(int (__thiscall **)(int))(*(_DWORD *)v20 + 1080))(a1: v20);
          CMFCToolBarMenuButton::CMFCToolBarMenuButton(
            this: &v38,
            uiID: 0xFFFFFFFF,
            hMenu: v21,
            iImage: -1,
            lpszText: v27,
            bUserButton: 0);
          v38.m_bQuickCustomMode = 1;
          v22 = v32->__vftable;
          LOBYTE(v40) = 10;
          ((void (__thiscall *)(CMFCPopupMenu *, int))v22->dtr_CObject)(a1: v32, a2: 1);
          ((void (__thiscall *)(CMFCPopupMenu *, int))v16->dtr_CObject)(a1: v16, a2: 1);
          CMFCPopupMenu::InsertItem(this: v10, button: &v38, iInsertAt: -1);
          v30->GetRect(this: v30, result: (CRect *)&v39);
          cy = v28.cy;
          Point = v39;
          ClientToScreen(hWnd: *(HWND *)(v28.cy + 32), lpPoint: &Point);
          CMFCCaptionButton::GetSize(result: &v28);
          v10->Create(this: v10, a2: (CWnd *)cy, a3: Point.x - 2, a4: Point.y - 9, a5: nullptr, a6: 0, a7: 0);
          v10->m_bAutoDestroy = 1;
          v10->m_hWndOwner = *(HWND__ **)(cy + 32);
          CMFCPopupMenu::SetQuickMode(this: v10);
          v10->m_QuickType = QUICK_CUSTOMIZE_ADDREMOVE;
          LOBYTE(v40) = 9;
          CMFCToolBarMenuButton::~CMFCToolBarMenuButton(this: &v38);
          ATL::CStringData::Release(this: (ATL::CStringData *)v33.m_pszData - 1);
          LOBYTE(v40) = 4;
          CMFCToolBarMenuButton::~CMFCToolBarMenuButton(this: &v36);
          LOBYTE(v40) = 0;
          CMFCToolBarMenuButton::~CMFCToolBarMenuButton(this: &button);
          ATL::CStringData::Release(this: (ATL::CStringData *)v34.m_pszData - 1);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039B6EC
// Name: protected: long CMFCPropertyGridCtrl::OnGetObject(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPropertyGridCtrl::OnGetObject(CMFCPropertyGridCtrl *this, unsigned int wParam, int lParam)
{
  if ( afxGlobalData.m_bEnableAccessibility != 0 )
    return CWnd::OnGetObject(this, wParam, lParam);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1039B706
// Name: public: virtual long CMFCPropertyGridCtrl::get_accChildCount(long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall CMFCPropertyGridCtrl::get_accChildCount(CBasePane *this, int *pcountChildren)
{
  if ( pcountChildren == nullptr )
    return -2147024809;
  *pcountChildren = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1039B722
// Name: public: virtual long CMFCPropertyGridCtrl::get_accChild(struct tagVARIANT,struct IDispatch __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall CMFCPropertyGridCtrl::get_accChild(
        CMFCPropertyGridCtrl *this,
        tagVARIANT __formal,
        IDispatch **ppdispChild)
{
  if ( *ppdispChild == nullptr )
    return -2147024809;
  *ppdispChild = this->m_pStdObject;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1039B741
// Name: public: virtual long CMFCPropertyGridCtrl::get_accRole(struct tagVARIANT,struct tagVARIANT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall CMFCPropertyGridCtrl::get_accRole(
        CMFCPropertyGridCtrl *this,
        tagVARIANT varChild,
        tagVARIANT *pvarRole)
{
  if ( pvarRole != nullptr )
  {
    if ( varChild.vt == 3 )
    {
      if ( varChild.decVal.Lo32 == 0 )
      {
        pvarRole->decVal.Lo32 = 33;
        goto LABEL_7;
      }
LABEL_4:
      pvarRole->decVal.Lo32 = 28;
LABEL_7:
      pvarRole->vt = 3;
      return 0;
    }
    if ( varChild.decVal.Lo32 == 0 )
      goto LABEL_4;
  }
  return -2147024809;
}

//------------------------------------------------------------------------------
// Address: 0x1039B783
// Name: public: virtual long CMFCPropertyGridCtrl::get_accState(struct tagVARIANT,struct tagVARIANT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall CMFCPropertyGridCtrl::get_accState(
        CMFCPropertyGridCtrl *this,
        tagVARIANT varChild,
        tagVARIANT *pvarState)
{
  CMFCPropertyGridProperty **p_m_pAccProp; // esi
  CMFCPropertyGridProperty *m_pAccProp; // ecx
  CMFCPropertyGridProperty *v5; // esi
  BOOL v6; // eax

  if ( varChild.vt != 3 || varChild.decVal.Lo32 != 0 )
  {
    p_m_pAccProp = &this->m_pAccProp;
    pvarState->vt = 3;
    pvarState->decVal.Lo32 = 3145728;
    m_pAccProp = this->m_pAccProp;
    if ( m_pAccProp != nullptr )
    {
      if ( m_pAccProp->IsSelected(this: m_pAccProp) != 0 )
        pvarState->decVal.Lo32 |= 6u;
      v5 = *p_m_pAccProp;
      v6 = v5->m_bGroup != 0 && v5->m_bIsValueList == 0;
      if ( v5->m_bEnabled == 0 || v6 )
        pvarState->decVal.Lo32 |= 0x40u;
    }
  }
  else
  {
    pvarState->vt = 3;
    pvarState->decVal.Lo32 = 0;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1039B7FC
// Name: public: virtual long CMFCPropertyGridCtrl::get_accHelpTopic(wchar_t __near * __near *,struct tagVARIANT,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall CMFCPropertyGridCtrl::get_accHelpTopic(
        CBasePane *this,
        wchar_t **__formal,
        tagVARIANT __formala,
        int *a4)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1039B802
// Name: public: virtual long CMFCPropertyGridCtrl::get_accKeyboardShortcut(struct tagVARIANT,wchar_t __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall CMFCPropertyGridCtrl::get_accKeyboardShortcut(
        CMFCPropertyGridCtrl *this,
        tagVARIANT __formal,
        wchar_t **__formal_12)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1039B808
// Name: public: virtual long CMFCPropertyGridCtrl::get_accDefaultAction(struct tagVARIANT,wchar_t __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall CMFCPropertyGridCtrl::get_accDefaultAction(
        CMFCPropertyGridCtrl *this,
        tagVARIANT __formal,
        wchar_t **__formal_12)
{
  return -2147352573;
}

//------------------------------------------------------------------------------
// Address: 0x1039B810
// Name: public: virtual long CBasePane::accSelect(long,struct tagVARIANT)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall CBasePane::accSelect(CBasePane *this, int flagsSelect, tagVARIANT varChild)
{
  IAccessible *m_pStdObject; // eax

  m_pStdObject = this->m_pStdObject;
  if ( m_pStdObject != nullptr )
    return ((HRESULT (__stdcall *)(IAccessible *, int, _DWORD, unsigned int, unsigned int, unsigned int))m_pStdObject->accSelect)(
             a1: m_pStdObject,
             a2: flagsSelect,
             a3: *(_DWORD *)&varChild.vt,
             a4: varChild.decVal.Hi32,
             a5: varChild.decVal.Lo32,
             a6: varChild.decVal.Mid32);
  else
    return -2147024809;
}

//------------------------------------------------------------------------------
// Address: 0x1039B840
// Name: protected: long CMFCPropertyGridCtrl::OnPrintClient(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPropertyGridCtrl::OnPrintClient(CMFCPropertyGridCtrl *this, HDC__ *wp, char lp)
{
  CDC *v4; // eax

  if ( (lp & 4) != 0 )
  {
    v4 = CDC::FromHandle(hDC: wp);
    this->OnDraw(this, a2: v4);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1039B868
// Name: public: CList<class CMFCPropertyGridProperty __near *,class CMFCPropertyGridProperty __near *>::CList<class CMFCPropertyGridProperty __near *,class CMFCPropertyGridProperty __near *>(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *> *__thiscall CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>(
        CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *> *this,
        int nBlockSize)
{
  this->m_nCount = 0;
  this->m_pNodeFree = nullptr;
  this->m_pNodeTail = nullptr;
  this->m_pNodeHead = nullptr;
  this->m_pBlocks = nullptr;
  this->__vftable = (CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>_vtbl *)&CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::`vftable';
  this->m_nBlockSize = nBlockSize;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1039B890
// Name: public: virtual CList<class CMFCPropertyGridProperty __near *,class CMFCPropertyGridProperty __near *>::~CList<class CMFCPropertyGridProperty __near *,class CMFCPropertyGridProperty __near *>(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::~CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>(
        CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *> *this)
{
  this->__vftable = (CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>_vtbl *)&CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::`vftable';
  CList<HWND__ *,HWND__ * &>::RemoveAll((CList<HWND__ *,HWND__ * &> *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1039B8C2
// Name: public: int CMFCPropertyGridProperty::GetExpandedSubItems(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPropertyGridProperty::GetExpandedSubItems(CMFCPropertyGridProperty *this, int bIncludeHidden)
{
  CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::CNode *m_pNodeHead; // esi
  int v4; // edi
  CMFCPropertyGridProperty *data; // ecx

  if ( this->m_bExpanded == 0 )
    return 0;
  m_pNodeHead = this->m_lstSubItems.m_pNodeHead;
  v4 = 0;
  while ( m_pNodeHead != nullptr )
  {
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( bIncludeHidden != 0 || data->m_bIsVisible != 0 )
      v4 += CMFCPropertyGridProperty::GetExpandedSubItems(this: data, bIncludeHidden) + 1;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1039B906
// Name: public: class CMFCPropertyGridProperty __near * CMFCPropertyGridProperty::HitTest(class CPoint,enum CMFCPropertyGridProperty::ClickArea __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCPropertyGridProperty *__thiscall CMFCPropertyGridProperty::HitTest(
        CMFCPropertyGridProperty *this,
        CPoint point,
        CMFCPropertyGridProperty::ClickArea *pnArea)
{
  CRect *p_m_Rect; // edi
  CMFCPropertyGridProperty *result; // eax
  CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::CNode *m_pNodeHead; // esi
  CMFCPropertyGridProperty *data; // ecx

  p_m_Rect = &this->m_Rect;
  if ( PtInRect(lprc: &this->m_Rect, pt: point.tagPOINT) )
  {
    if ( pnArea != nullptr )
    {
      if ( this->m_bGroup != 0 && point.x < p_m_Rect->left + p_m_Rect->bottom - p_m_Rect->top )
      {
        *pnArea = ClickExpandBox;
      }
      else if ( this->HasValueField(this) != 0
             && point.x > this->m_pWndList->m_rectList.left + this->m_pWndList->m_nLeftColumnWidth )
      {
        *pnArea = ClickValue;
      }
      else
      {
        *pnArea = ClickName;
      }
    }
    return this;
  }
  else
  {
    m_pNodeHead = this->m_lstSubItems.m_pNodeHead;
    while ( m_pNodeHead != nullptr )
    {
      data = m_pNodeHead->data;
      m_pNodeHead = m_pNodeHead->pNext;
      result = CMFCPropertyGridProperty::HitTest(this: data, point, pnArea);
      if ( result != nullptr )
        return result;
    }
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039B9A6
// Name: public: void CMFCPropertyGridProperty::Expand(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridProperty::Expand(CMFCPropertyGridProperty *this, int bExpand)
{
  CMFCPropertyGridCtrl *m_pWndList; // ecx
  CMFCPropertyGridCtrl *v4; // eax
  int top; // ecx
  CRect rectRedraw; // [esp+4h] [ebp-14h] BYREF

  if ( this->m_bExpanded != bExpand && this->m_lstSubItems.m_nCount != 0 )
  {
    m_pWndList = this->m_pWndList;
    this->m_bExpanded = bExpand;
    if ( m_pWndList != nullptr && m_pWndList->m_hWnd != nullptr )
    {
      m_pWndList->AdjustLayout(this: m_pWndList);
      v4 = this->m_pWndList;
      top = this->m_Rect.top;
      rectRedraw = v4->m_rectList;
      rectRedraw.top = top;
      RedrawWindow(hWnd: v4->m_hWnd, lprcUpdate: &rectRedraw, hrgnUpdate: nullptr, flags: 0x105u);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039BA27
// Name: public: void CMFCPropertyGridProperty::Redraw(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridProperty::Redraw(CMFCPropertyGridProperty *this)
{
  CMFCPropertyGridCtrl *m_pWndList; // eax
  CMFCPropertyGridProperty *m_pParent; // eax
  CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::CNode *m_pNodeHead; // edi
  CMFCPropertyGridProperty *data; // eax

  m_pWndList = this->m_pWndList;
  if ( m_pWndList != nullptr )
  {
    InvalidateRect(hWnd: m_pWndList->m_hWnd, lpRect: &this->m_Rect, bErase: true);
    m_pParent = this->m_pParent;
    if ( m_pParent != nullptr && m_pParent->m_bIsValueList != 0 )
      InvalidateRect(hWnd: this->m_pWndList->m_hWnd, lpRect: &m_pParent->m_Rect, bErase: true);
    if ( this->m_bIsValueList != 0 )
    {
      m_pNodeHead = this->m_lstSubItems.m_pNodeHead;
      while ( m_pNodeHead != nullptr )
      {
        data = m_pNodeHead->data;
        m_pNodeHead = m_pNodeHead->pNext;
        InvalidateRect(hWnd: this->m_pWndList->m_hWnd, lpRect: &data->m_Rect, bErase: true);
      }
    }
    UpdateWindow(hWnd: this->m_pWndList->m_hWnd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039BAA5
// Name: protected: void CMFCPropertyGridProperty::Reposition(int __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridProperty::Reposition(CMFCPropertyGridProperty *this, int *y)
{
  CRect *p_m_Rect; // edx
  int v4; // edi
  CMFCPropertyGridCtrl *m_pWndList; // esi
  CMFCPropertyGridProperty *m_pParent; // eax
  int m_bAlphabeticMode; // edx
  int m_nRowHeight; // edi
  int v9; // eax
  int v10; // ecx
  int right; // ecx
  CMFCPropertyGridCtrl *v12; // eax
  int v13; // ecx
  bool v14; // zf
  HWND p_m_ToolTip; // eax
  CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::CNode *m_pNodeHead; // esi
  CMFCPropertyGridProperty *data; // ecx
  CRect rectValue; // [esp+20h] [ebp-24h] BYREF
  CRect rectName; // [esp+30h] [ebp-14h] BYREF
  CRect rectOld; // 0:^1C.16

  p_m_Rect = &this->m_Rect;
  rectOld = this->m_Rect;
  v4 = 0;
  if ( this->m_bIsVisible != 0
    && (CMFCPropertyGridProperty::IsParentExpanded(this) != 0 || this->m_pWndList->m_bAlphabeticMode != 0) )
  {
    v4 = 1;
  }
  m_pWndList = this->m_pWndList;
  if ( m_pWndList->m_bAlphabeticMode != 0 )
  {
    m_pParent = this->m_pParent;
    if ( m_pParent != nullptr && m_pParent->m_bIsValueList != 0 && CMFCPropertyGridProperty::IsParentExpanded(this) == 0 )
      v4 = 0;
  }
  if ( v4 != 0 )
  {
    m_bAlphabeticMode = m_pWndList->m_bAlphabeticMode;
    m_nRowHeight = m_pWndList->m_nRowHeight;
    if ( m_bAlphabeticMode != 0 )
      v9 = m_pWndList->m_nRowHeight;
    else
      v9 = m_nRowHeight * CMFCPropertyGridProperty::GetHierarchyLevel(this);
    if ( m_bAlphabeticMode != 0 && this->m_bIsValueList != 0 )
      v9 = 0;
    v10 = v9 + m_pWndList->m_rectList.left;
    rectName.top = *y;
    rectName.left = v10;
    right = m_pWndList->m_rectList.right;
    rectName.bottom = m_nRowHeight + rectName.top;
    rectName.right = right;
    this->m_Rect = rectName;
    if ( !IsRectEmpty(lprc: &this->m_rectButton) )
    {
      this->m_rectButton.top = this->m_Rect.top + 1;
      this->m_rectButton.bottom = this->m_Rect.bottom;
    }
    *y += this->m_pWndList->m_nRowHeight;
    v12 = this->m_pWndList;
    rectName = this->m_Rect;
    v13 = v12->m_rectList.left + v12->m_nLeftColumnWidth;
    v14 = &v12->m_ToolTip == nullptr;
    p_m_ToolTip = (HWND)&v12->m_ToolTip;
    rectName.right = v13;
    if ( !v14 )
      p_m_ToolTip = *((HWND *)p_m_ToolTip + 8);
    if ( IsWindow(hWnd: p_m_ToolTip) )
    {
      CToolTipCtrl::AddTool(
        this: &this->m_pWndList->m_ToolTip,
        pWnd: this->m_pWndList,
        lpszText: (const char *)0xFFFFFFFF,
        lpRectTool: &rectName,
        nIDTool: this->m_pWndList->m_nTooltipsCount + 1);
      ++this->m_pWndList->m_nTooltipsCount;
      if ( this->m_bGroup == 0 )
      {
        rectValue = this->m_Rect;
        rectValue.left = rectName.right + 1;
        CToolTipCtrl::AddTool(
          this: &this->m_pWndList->m_ToolTip,
          pWnd: this->m_pWndList,
          lpszText: (const char *)0xFFFFFFFF,
          lpRectTool: &rectValue,
          nIDTool: this->m_pWndList->m_nTooltipsCount + 1);
        ++this->m_pWndList->m_nTooltipsCount;
      }
    }
  }
  else
  {
    SetRectEmpty(lprc: p_m_Rect);
    SetRectEmpty(lprc: &this->m_rectButton);
  }
  m_pNodeHead = this->m_lstSubItems.m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    CMFCPropertyGridProperty::Reposition(this: data, y);
  }
  ((void (__thiscall *)(CMFCPropertyGridProperty *, int, int, int, int))this->OnPosSizeChanged)(
    a1: this,
    a2: rectOld.left,
    a3: rectOld.top,
    a4: rectOld.right,
    a5: rectOld.bottom);
}

//------------------------------------------------------------------------------
// Address: 0x1039BC8D
// Name: protected: void CMFCPropertyGridProperty::SetModifiedFlag(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridProperty::SetModifiedFlag(CMFCPropertyGridProperty *this)
{
  int v2; // eax
  CMFCPropertyGridProperty *m_pParent; // ecx
  CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::CNode *m_pNodeHead; // eax
  CMFCPropertyGridProperty *data; // edx
  CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::CNode *v6; // eax
  CMFCPropertyGridProperty *v7; // ecx
  CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::CNode *v8; // esi
  CMFCPropertyGridProperty *v9; // ecx
  CWnd *m_pWndInPlace; // ecx
  CMFCPropertyGridCtrl *m_pWndList; // eax
  bool v12; // zf
  CFont *p_m_fontBold; // eax
  WPARAM m_hObject; // eax
  CWnd *v15; // eax
  CMFCPropertyGridCtrl *v16; // eax
  int v17; // esi
  int left; // eax
  CRect rectInPlace; // [esp+Ch] [ebp-14h] BYREF

  v2 = this->IsValueChanged(this);
  if ( this->m_bIsModified != v2 || this->m_bIsValueList != 0 )
  {
    m_pParent = this->m_pParent;
    this->m_bIsModified = v2;
    if ( m_pParent != nullptr && m_pParent->m_bIsValueList != 0 )
    {
      if ( v2 != 0 )
      {
LABEL_10:
        m_pParent->m_bIsModified = 1;
      }
      else
      {
        m_pParent->m_bIsModified = 0;
        m_pParent = this->m_pParent;
        m_pNodeHead = m_pParent->m_lstSubItems.m_pNodeHead;
        while ( m_pNodeHead != nullptr )
        {
          data = m_pNodeHead->data;
          m_pNodeHead = m_pNodeHead->pNext;
          if ( data->m_bIsModified != 0 )
            goto LABEL_10;
        }
      }
    }
    if ( this->m_bIsValueList != 0 )
    {
      v6 = this->m_lstSubItems.m_pNodeHead;
      while ( v6 != nullptr )
      {
        v7 = v6->data;
        v6 = v6->pNext;
        if ( v7->m_bIsModified != 0 )
        {
          this->m_bIsModified = 1;
          break;
        }
      }
    }
    v8 = this->m_lstSubItems.m_pNodeHead;
    while ( v8 != nullptr )
    {
      v9 = v8->data;
      v8 = v8->pNext;
      CMFCPropertyGridProperty::SetModifiedFlag(this: v9);
    }
    if ( this->m_pWndList->m_bMarkModifiedProperties != 0 )
    {
      ((void (__thiscall *)(CMFCPropertyGridProperty *, int, int, int, int))this->OnPosSizeChanged)(
        a1: this,
        a2: this->m_Rect.left,
        a3: this->m_Rect.top,
        a4: this->m_Rect.right,
        a5: this->m_Rect.bottom);
      m_pWndInPlace = this->m_pWndInPlace;
      if ( m_pWndInPlace != nullptr && m_pWndInPlace->m_hWnd != nullptr )
      {
        if ( this->m_bIsModified != 0 )
        {
          m_pWndList = this->m_pWndList;
          v12 = &m_pWndList->m_fontBold == nullptr;
          p_m_fontBold = &m_pWndList->m_fontBold;
        }
        else
        {
          p_m_fontBold = CWnd::GetFont(this: this->m_pWndList);
          m_pWndInPlace = this->m_pWndInPlace;
          v12 = p_m_fontBold == nullptr;
        }
        if ( v12 )
          m_hObject = 0;
        else
          m_hObject = (WPARAM)p_m_fontBold->m_hObject;
        SendMessageA(hWnd: m_pWndInPlace->m_hWnd, Msg: 0x30u, wParam: m_hObject, lParam: 1);
        v15 = this->m_pWndInPlace;
        memset(&rectInPlace, 0, sizeof(rectInPlace));
        GetWindowRect(hWnd: v15->m_hWnd, lpRect: &rectInPlace);
        CWnd::ScreenToClient(this: this->m_pWndList, lpRect: &rectInPlace);
        v16 = this->m_pWndList;
        v17 = v16->m_nBoldEditLeftMargin - v16->m_nEditLeftMargin;
        if ( this->m_bIsModified != 0 )
          v17 = v16->m_nEditLeftMargin - v16->m_nBoldEditLeftMargin;
        if ( this->HasButton(this) != 0 )
        {
          this->AdjustButtonRect(this);
          left = this->m_rectButton.left;
          rectInPlace.right = left;
        }
        else
        {
          left = rectInPlace.right;
        }
        CWnd::SetWindowPos(
          this: this->m_pWndInPlace,
          pWndInsertAfter: nullptr,
          x: v17 + rectInPlace.left,
          y: rectInPlace.top,
          cx: left - rectInPlace.left - v17,
          cy: rectInPlace.bottom - rectInPlace.top,
          nFlags: 0x14u);
      }
      CMFCPropertyGridProperty::Redraw(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1039BE4E
// Name: protected: int CMFCPropertyGridCtrl::OnCreate(struct tagCREATESTRUCTA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPropertyGridCtrl::OnCreate(CMFCPropertyGridCtrl *this, tagCREATESTRUCTA *lpCreateStruct)
{
  int result; // eax

  result = CWnd::Default(this);
  if ( result != -1 )
  {
    this->Init(this);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1039BE71
// Name: protected: void CMFCPropertyGridCtrl::OnSize(unsigned int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::OnSize(CMFCPropertyGridCtrl *this, unsigned int nType, int cx, int cy)
{
  CWnd::Default(this);
  this->EndEditItem(this, a2: 1);
  this->m_nLeftColumnWidth = cx / 2;
  this->AdjustLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x1039BEA7
// Name: protected: void CMFCPropertyGridCtrl::CreateBoldFont(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::CreateBoldFont(CMFCPropertyGridCtrl *this)
{
  CFont *p_m_fontBold; // esi
  HFONT__ *m_hFont; // edi
  HGDIOBJ StockObject; // eax
  CGdiObject *v5; // edi
  HFONT v6; // eax
  tagLOGFONTA lf; // [esp+8h] [ebp-40h] BYREF

  p_m_fontBold = &this->m_fontBold;
  if ( this != (CMFCPropertyGridCtrl *)-736 && this->m_fontBold.m_hObject != nullptr )
    CGdiObject::DeleteObject(this: &this->m_fontBold);
  m_hFont = this->m_hFont;
  if ( m_hFont != nullptr )
    StockObject = m_hFont;
  else
    StockObject = GetStockObject(i: 17);
  v5 = CGdiObject::FromHandle(h: StockObject);
  memset(dst: (unsigned __int8 *)&lf, value: 0, count: sizeof(lf));
  GetObjectA(h: v5->m_hObject, c: 60, pv: &lf);
  lf.lfWeight = 700;
  v6 = CreateFontIndirectA(lplf: &lf);
  CGdiObject::Attach(this: p_m_fontBold, hObject: v6);
}

//------------------------------------------------------------------------------
// Address: 0x1039BF38
// Name: protected: void CMFCPropertyGridCtrl::CalcEditMargin(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::CalcEditMargin(CMFCPropertyGridCtrl *this)
{
  CFont *Font; // eax
  WPARAM m_hObject; // eax
  void *p_m_fontBold; // eax
  CWnd v5; // [esp+10h] [ebp-94h] BYREF
  tagRECT rect; // [esp+84h] [ebp-20h] BYREF
  int v7; // [esp+A0h] [ebp-4h]

  CWnd::CWnd(this: &v5);
  v5.__vftable = (CWnd_vtbl *)&CEdit::`vftable';
  v7 = 0;
  rect.left = 0;
  rect.top = 0;
  rect.right = 100;
  rect.bottom = 20;
  CEdit::Create(this: (CEdit *)&v5, dwStyle: 0x40000000u, &rect, pParentWnd: this, nID: 0xFFFFFFFF);
  Font = CWnd::GetFont(this);
  if ( Font != nullptr )
    m_hObject = (WPARAM)Font->m_hObject;
  else
    m_hObject = 0;
  SendMessageA(hWnd: v5.m_hWnd, Msg: 0x30u, wParam: m_hObject, lParam: 1);
  this->m_nEditLeftMargin = (unsigned __int16)SendMessageA(hWnd: v5.m_hWnd, Msg: 0xD4u, wParam: 0, lParam: 0);
  p_m_fontBold = &this->m_fontBold;
  if ( this != (CMFCPropertyGridCtrl *)-736 )
    p_m_fontBold = this->m_fontBold.m_hObject;
  SendMessageA(hWnd: v5.m_hWnd, Msg: 0x30u, wParam: (WPARAM)p_m_fontBold, lParam: 1);
  this->m_nBoldEditLeftMargin = (unsigned __int16)SendMessageA(hWnd: v5.m_hWnd, Msg: 0xD4u, wParam: 0, lParam: 0);
  CWnd::DestroyWindow(this: &v5);
  v7 = -1;
  CEdit::~CEdit(this: (CEdit *)&v5);
}

//------------------------------------------------------------------------------
// Address: 0x1039C010
// Name: protected: struct HFONT__ __near * CMFCPropertyGridCtrl::SetCurrFont(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HFONT__ *__thiscall CMFCPropertyGridCtrl::SetCurrFont(CMFCPropertyGridCtrl *this, HDC__ *pDC)
{
  void *m_hFont; // eax
  HDC__ *v3; // ecx

  m_hFont = this->m_hFont;
  if ( m_hFont == nullptr )
    m_hFont = GetStockObject(i: 17);
  v3 = pDC;
  if ( pDC != nullptr )
    v3 = *((HDC__ **)pDC + 1);
  return (HFONT__ *)SelectObject(hdc: v3, h: m_hFont);
}

//------------------------------------------------------------------------------
// Address: 0x1039C03D
// Name: protected: virtual void CMFCPropertyGridCtrl::OnDraw(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::OnDraw(CMFCPropertyGridCtrl *this, CDC *pDCSrc)
{
  CDC *p_m_dcMem; // eax
  CMFCVisualManager *Instance; // eax
  CDC *v5; // esi
  unsigned int m_clrText; // eax
  int bottom; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-8Ch]
  HFONT__ *h; // [esp+10h] [ebp-74h]
  CDC *pDC; // [esp+14h] [ebp-70h]
  CMemDC v11; // [esp+18h] [ebp-6Ch] BYREF
  tagRECT rc; // [esp+54h] [ebp-30h] BYREF
  tagRECT Rect; // [esp+64h] [ebp-20h] BYREF
  int v14; // [esp+80h] [ebp-4h]

  CMemDC::CMemDC(this: &v11, dc: pDCSrc, pWnd: (HDC__ *)this);
  v14 = 0;
  p_m_dcMem = &v11.m_dcMem;
  if ( v11.m_bMemDC == 0 )
    p_m_dcMem = v11.m_dc;
  pDC = p_m_dcMem;
  Instance = CMFCVisualManager::GetInstance();
  this->m_clrGray = Instance->GetPropertyGridGroupColor(this: Instance, a2: this);
  m_hWnd = this->m_hWnd;
  memset(&Rect, 0, sizeof(Rect));
  GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
  v5 = pDC;
  ((void (__thiscall *)(CMFCPropertyGridCtrl *, CDC *, int, int, int, int))this->OnFillBackground)(
    a1: this,
    a2: pDC,
    a3: Rect.left,
    a4: Rect.top,
    a5: Rect.right,
    a6: Rect.bottom);
  h = CMFCPropertyGridCtrl::SetCurrFont(this, (HDC__ *)pDC);
  m_clrText = this->m_clrText;
  if ( m_clrText == -1 )
    m_clrText = afxGlobalData.clrWindowText;
  pDC->SetTextColor(this: pDC, a2: m_clrText);
  CDC::SetBkMode(this: pDC, nBkMode: 1);
  this->OnDrawList(this, a2: pDC);
  if ( this->m_bDescriptionArea != 0 )
  {
    bottom = this->m_rectList.bottom;
    rc.left = Rect.left;
    rc.right = Rect.right;
    rc.bottom = Rect.bottom;
    rc.top = bottom;
    if ( Rect.bottom - bottom > 0 )
    {
      InflateRect(lprc: &rc, dx: -1, dy: -1);
      ((void (__thiscall *)(CMFCPropertyGridCtrl *, CDC *, int, int, int, int))this->OnDrawDescription)(
        a1: this,
        a2: pDC,
        a3: rc.left,
        a4: rc.top,
        a5: rc.right,
        a6: rc.bottom);
    }
    v5 = pDC;
  }
  SelectObject(hdc: v5->m_hDC, h);
  v14 = -1;
  CMemDC::~CMemDC(this: &v11);
}

//------------------------------------------------------------------------------
// Address: 0x1039C15B
// Name: protected: virtual void CMFCPropertyGridCtrl::OnFillBackground(class CDC __near *,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::OnFillBackground(CMFCPropertyGridCtrl *this, CDC *pDC, CRect rectClient)
{
  HBRUSH m_hObject; // eax

  if ( this != (CMFCPropertyGridCtrl *)-956 && (m_hObject = (HBRUSH)this->m_brBackground.m_hObject) != nullptr )
    FillRect(hDC: pDC->m_hDC, lprc: &rectClient, hbr: m_hObject);
  else
    FillRect(hDC: pDC->m_hDC, lprc: &rectClient, hbr: (HBRUSH)afxGlobalData.brWindow.m_hObject);
}

//------------------------------------------------------------------------------
// Address: 0x1039C18D
// Name: public: void CMFCPropertyGridCtrl::EnableHeaderCtrl(int,char const __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::EnableHeaderCtrl(
        CMFCPropertyGridCtrl *this,
        int bEnable,
        char *lpszLeftColumn,
        char *lpszRightColumn)
{
  CMFCPropertyGridProperty *m_pSel; // ecx
  CMFCHeaderCtrl *v6; // eax
  CMFCHeaderCtrl *v7; // eax
  _HD_ITEMA hdItem; // [esp+8h] [ebp-30h] BYREF

  if ( lpszLeftColumn == nullptr || lpszRightColumn == nullptr )
    AfxThrowInvalidArgException();
  m_pSel = this->m_pSel;
  if ( m_pSel != nullptr )
    m_pSel->OnEndEdit(this: m_pSel);
  this->m_bHeaderCtrl = bEnable;
  if ( bEnable != 0 )
  {
    hdItem.pszText = lpszLeftColumn;
    hdItem.mask = 2;
    hdItem.cchTextMax = lstrlenA(lpString: lpszLeftColumn) + 1;
    v6 = this->GetHeaderCtrl(this);
    SendMessageA(hWnd: v6->m_hWnd, Msg: 0x1204u, wParam: 0, lParam: (LPARAM)&hdItem);
    hdItem.pszText = lpszRightColumn;
    hdItem.cchTextMax = lstrlenA(lpString: lpszRightColumn) + 1;
    v7 = this->GetHeaderCtrl(this);
    SendMessageA(hWnd: v7->m_hWnd, Msg: 0x1204u, wParam: 1u, lParam: (LPARAM)&hdItem);
  }
  this->AdjustLayout(this);
  RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
}

//------------------------------------------------------------------------------
// Address: 0x1039C249
// Name: public: void CMFCPropertyGridCtrl::EnableDescriptionArea(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::EnableDescriptionArea(CMFCPropertyGridCtrl *this, int bEnable)
{
  HWND__ *m_hWnd; // esi

  this->m_bDescriptionArea = bEnable;
  this->AdjustLayout(this);
  m_hWnd = this->m_hWnd;
  if ( m_hWnd != nullptr )
    RedrawWindow(hWnd: m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
}

//------------------------------------------------------------------------------
// Address: 0x1039C27E
// Name: protected: void CMFCPropertyGridCtrl::OnSpinDeltaPos(struct tagNMHDR __near *,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::OnSpinDeltaPos(CMFCPropertyGridCtrl *this, tagNMHDR *__formal, int *pResult)
{
  *pResult = 0;
  PostMessageA(hWnd: this->m_hWnd, Msg: 0x465u, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1039C29E
// Name: protected: void CMFCPropertyGridCtrl::TrackHeader(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::TrackHeader(CMFCPropertyGridCtrl *this, int nOffset)
{
  int v3; // esi
  int v4; // esi
  int v5; // esi
  CMFCPropertyGridCtrl_vtbl *v6; // eax
  int v7; // eax
  CMFCHeaderCtrl *v8; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-80h]
  LPARAM lParam; // [esp+10h] [ebp-68h] BYREF
  int v11; // [esp+14h] [ebp-64h]
  CClientDC v12; // [esp+40h] [ebp-38h] BYREF
  int m_nRowHeight; // [esp+54h] [ebp-24h]
  tagRECT Rect; // [esp+58h] [ebp-20h] BYREF
  int v15; // [esp+74h] [ebp-4h]

  CClientDC::CClientDC(this: &v12, pWnd: this);
  v15 = 0;
  if ( !IsRectEmpty(lprc: &this->m_rectTrackHeader) && this->m_bShowDragContext == 0 )
    InvertRect(hDC: v12.m_hDC, lprc: &this->m_rectTrackHeader);
  if ( nOffset >= 0 )
  {
    this->m_rectTrackHeader.left = this->m_rectList.left;
    this->m_rectTrackHeader.top = this->m_rectList.top;
    this->m_rectTrackHeader.right = this->m_rectList.right;
    this->m_rectTrackHeader.bottom = this->m_rectList.bottom;
    this->m_rectTrackHeader.left += nOffset;
    this->m_rectTrackHeader.right = this->m_rectTrackHeader.left + 1;
    if ( this->m_bShowDragContext != 0 )
    {
      m_hWnd = this->m_hWnd;
      memset(&Rect, 0, sizeof(Rect));
      GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
      m_nRowHeight = this->m_nRowHeight;
      if ( m_nRowHeight <= nOffset )
        m_nRowHeight = nOffset;
      v3 = Rect.right - Rect.left;
      if ( m_nRowHeight >= v3 - GetSystemMetrics(nIndex: 21) - 5 )
      {
        v5 = Rect.right - Rect.left;
        v4 = v5 - GetSystemMetrics(nIndex: 21) - 5;
      }
      else
      {
        v4 = this->m_nRowHeight;
        if ( v4 <= nOffset )
          v4 = nOffset;
      }
      v6 = this->__vftable;
      this->m_nLeftColumnWidth = v4;
      lParam = 1;
      v11 = v4 + 2;
      v7 = (int)v6->GetHeaderCtrl(this);
      SendMessageA(hWnd: *(HWND *)(v7 + 32), Msg: 0x1204u, wParam: 0, (LPARAM)&lParam);
      v11 = Rect.right - Rect.left + 10;
      v8 = this->GetHeaderCtrl(this);
      SendMessageA(hWnd: v8->m_hWnd, Msg: 0x1204u, wParam: 1u, (LPARAM)&lParam);
    }
    else
    {
      InvertRect(hDC: v12.m_hDC, lprc: &this->m_rectTrackHeader);
    }
  }
  else
  {
    SetRectEmpty(lprc: &this->m_rectTrackHeader);
  }
  v15 = -1;
  CClientDC::~CClientDC(this: &v12);
}

//------------------------------------------------------------------------------
// Address: 0x1039C3F3
// Name: protected: void CMFCPropertyGridCtrl::TrackDescr(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::TrackDescr(CMFCPropertyGridCtrl *this, int nOffset)
{
  int m_nRowHeight; // ecx
  HDC__ *m_hDC; // [esp-Ch] [ebp-40h]
  RECT *v5; // [esp-8h] [ebp-3Ch]
  CClientDC dc; // [esp+8h] [ebp-2Ch] BYREF
  RECT *lprc; // [esp+1Ch] [ebp-18h]
  CRect rectClient; // [esp+20h] [ebp-14h] BYREF

  CClientDC::CClientDC(this: &dc, pWnd: this);
  lprc = &this->m_rectTrackDescr;
  if ( !IsRectEmpty(lprc: &this->m_rectTrackDescr) )
    InvertRect(hDC: dc.m_hDC, lprc: &this->m_rectTrackDescr);
  if ( nOffset == 0x80000000 )
  {
    SetRectEmpty(lprc: &this->m_rectTrackDescr);
  }
  else
  {
    memset(&rectClient, 0, sizeof(rectClient));
    GetClientRect(hWnd: this->m_hWnd, lpRect: &rectClient);
    m_nRowHeight = this->m_nRowHeight;
    if ( nOffset <= rectClient.top + m_nRowHeight + this->m_nHeaderHeight )
      nOffset = rectClient.top + m_nRowHeight + this->m_nHeaderHeight;
    if ( nOffset >= rectClient.bottom - m_nRowHeight )
      nOffset = rectClient.bottom - m_nRowHeight;
    v5 = lprc;
    m_hDC = dc.m_hDC;
    this->m_rectTrackDescr = rectClient;
    this->m_rectTrackDescr.top = nOffset - 1;
    this->m_rectTrackDescr.bottom = nOffset - 1 + 2;
    InvertRect(hDC: m_hDC, lprc: v5);
  }
  CClientDC::~CClientDC(this: &dc);
}

//------------------------------------------------------------------------------
// Address: 0x1039C4C3
// Name: public: class CMFCPropertyGridProperty __near * CMFCPropertyGridCtrl::HitTest(class CPoint,enum CMFCPropertyGridProperty::ClickArea __near *,int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCPropertyGridProperty *__thiscall CMFCPropertyGridCtrl::HitTest(
        CMFCPropertyGridCtrl *this,
        CPoint pt,
        CMFCPropertyGridProperty::ClickArea *pnArea,
        int bPropsOnly)
{
  int bottom; // eax
  CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *> *p_m_lstTerminalProps; // ebx
  CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::CNode *m_pNodeHead; // esi
  CMFCPropertyGridProperty *data; // ecx
  CMFCPropertyGridProperty *result; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-3Ch]
  CRect rectDescr; // [esp+10h] [ebp-24h] BYREF
  CRect rectClient; // [esp+20h] [ebp-14h] BYREF

  if ( PtInRect(lprc: &this->m_rectList, pt: pt.tagPOINT) || bPropsOnly != 0 )
  {
    if ( this->m_bAlphabeticMode != 0 )
      p_m_lstTerminalProps = &this->m_lstTerminalProps;
    else
      p_m_lstTerminalProps = &this->m_lstProps;
    m_pNodeHead = p_m_lstTerminalProps->m_pNodeHead;
    while ( m_pNodeHead != nullptr )
    {
      data = m_pNodeHead->data;
      m_pNodeHead = m_pNodeHead->pNext;
      result = CMFCPropertyGridProperty::HitTest(this: data, point: pt, pnArea);
      if ( result != nullptr )
        return result;
    }
  }
  else
  {
    m_hWnd = this->m_hWnd;
    memset(&rectClient, 0, sizeof(rectClient));
    GetClientRect(hWnd: m_hWnd, lpRect: &rectClient);
    bottom = this->m_rectList.bottom;
    rectDescr.left = rectClient.left;
    rectDescr.right = rectClient.right;
    rectDescr.bottom = rectClient.bottom;
    rectDescr.top = bottom;
    if ( pnArea != nullptr && PtInRect(lprc: &rectDescr, pt: pt.tagPOINT) )
      *pnArea = ClickDescription;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1039C596
// Name: public: void CMFCPropertyGridCtrl::SetCurSel(class CMFCPropertyGridProperty __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::SetCurSel(
        CMFCPropertyGridCtrl *this,
        CMFCPropertyGridProperty *pProp,
        int bRedraw)
{
  CMFCPropertyGridProperty *v3; // esi
  CMFCPropertyGridProperty *m_pSel; // edi
  CMFCPropertyGridCtrl_vtbl *v6; // eax
  int m_bGroup; // eax
  int right; // eax
  int *p_left; // esi
  int v10; // eax
  int bottom; // eax
  CRect rectDescr; // [esp+14h] [ebp-24h] BYREF
  CRect rectClient; // [esp+24h] [ebp-14h] BYREF

  v3 = pProp;
  m_pSel = this->m_pSel;
  if ( m_pSel == pProp )
  {
    ((void (__stdcall *)(CMFCPropertyGridProperty *))this->NotifyAccessibility)(a1: m_pSel);
    return;
  }
  if ( m_pSel != nullptr && m_pSel->m_bInPlaceEdit != 0 )
    this->EndEditItem(this, a2: 1);
  v6 = this->__vftable;
  this->m_pSel = pProp;
  v6->OnChangeSelection(this, a2: pProp, a3: m_pSel);
  if ( m_pSel != nullptr )
  {
    m_pSel->OnKillSelection(this: m_pSel, a2: pProp);
    rectDescr = m_pSel->m_rectButton;
    SetRectEmpty(lprc: &m_pSel->m_rectButton);
    if ( bRedraw != 0 )
    {
      m_bGroup = m_pSel->m_bGroup;
      rectClient = m_pSel->m_Rect;
      if ( m_bGroup != 0 || ((int (*)(void))m_pSel->HasValueField)() == 0 )
      {
        right = rectClient.right;
      }
      else
      {
        right = rectClient.left + this->m_nLeftColumnWidth;
        rectClient.right = right;
      }
      if ( rectDescr.right > right )
        rectClient.right = rectDescr.right;
      InvalidateRect(hWnd: this->m_hWnd, lpRect: &rectDescr, bErase: true);
      InvalidateRect(hWnd: this->m_hWnd, lpRect: &rectClient, bErase: true);
    }
    v3 = pProp;
  }
  if ( v3 != nullptr )
  {
    v3->OnSetSelection(this: v3, a2: m_pSel);
    if ( v3->HasButton(this: v3) != 0 )
      v3->AdjustButtonRect(this: v3);
    if ( bRedraw == 0 )
      goto LABEL_31;
    p_left = &v3->m_Rect.left;
    rectClient.left = *p_left++;
    rectClient.top = *p_left++;
    rectClient.right = *p_left;
    rectClient.bottom = p_left[1];
    if ( pProp->m_bGroup != 0 || pProp->HasValueField(this: pProp) == 0 )
    {
      v10 = rectClient.right;
    }
    else
    {
      v10 = rectClient.left + this->m_nLeftColumnWidth;
      rectClient.right = v10;
    }
    if ( pProp->m_rectButton.right > v10 )
      rectClient.right = pProp->m_rectButton.right;
    InvalidateRect(hWnd: this->m_hWnd, lpRect: &rectClient, bErase: true);
    InvalidateRect(hWnd: this->m_hWnd, lpRect: &pProp->m_rectButton, bErase: true);
  }
  if ( bRedraw != 0 )
  {
    if ( this->m_bDescriptionArea != 0 )
    {
      memset(&rectClient, 0, sizeof(rectClient));
      GetClientRect(hWnd: this->m_hWnd, lpRect: &rectClient);
      bottom = this->m_rectList.bottom;
      rectDescr.left = rectClient.left;
      rectDescr.right = rectClient.right;
      rectDescr.bottom = rectClient.bottom;
      rectDescr.top = bottom;
      InflateRect(lprc: &rectDescr, dx: -4, dy: -4);
      InvalidateRect(hWnd: this->m_hWnd, lpRect: &rectDescr, bErase: true);
    }
    UpdateWindow(hWnd: this->m_hWnd);
  }
LABEL_31:
  ((void (__stdcall *)(CMFCPropertyGridProperty *))this->NotifyAccessibility)(a1: this->m_pSel);
}

//------------------------------------------------------------------------------
// Address: 0x1039C796
// Name: public: virtual int CMFCPropertyGridCtrl::EditItem(class CMFCPropertyGridProperty __near *,struct tagPOINT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPropertyGridCtrl::EditItem(
        CMFCPropertyGridCtrl *this,
        CMFCPropertyGridProperty *pProp,
        tagPOINT *lptClick)
{
  int result; // eax
  HWND v5; // eax

  result = this->EndEditItem(this, a2: 1);
  if ( result != 0 )
  {
    if ( pProp->m_bGroup == 0 || pProp->m_bIsValueList != 0 )
    {
      if ( pProp->OnEdit(this: pProp, a2: lptClick) != 0 )
      {
        CMFCPropertyGridProperty::Redraw(this: pProp);
        CMFCPropertyGridCtrl::SetCurSel(this, pProp, bRedraw: 1);
        v5 = SetCapture(hWnd: this->m_hWnd);
        CWnd::FromHandle(hWnd: v5);
      }
      return 1;
    }
    else
    {
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1039C7F7
// Name: public: virtual int CMFCPropertyGridCtrl::EndEditItem(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPropertyGridCtrl::EndEditItem(CMFCPropertyGridCtrl *this, int bUpdateData)
{
  CMFCPropertyGridProperty *m_pSel; // eax
  HWND__ *m_hWnd; // edi
  CMFCPropertyGridProperty *v6; // ecx

  m_pSel = this->m_pSel;
  if ( m_pSel != nullptr && m_pSel->m_bInPlaceEdit != 0 )
  {
    if ( bUpdateData != 0
      && (this->ValidateItemData(this, a2: this->m_pSel) == 0 || this->m_pSel->OnUpdateValue(this: this->m_pSel) == 0)
      || this->m_pSel != nullptr && this->m_pSel->OnEndEdit(this: this->m_pSel) == 0 )
    {
      return 0;
    }
    m_hWnd = this->m_hWnd;
    if ( GetCapture() == m_hWnd )
      ReleaseCapture();
    v6 = this->m_pSel;
    if ( v6 != nullptr )
      CMFCPropertyGridProperty::Redraw(this: v6);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1039C879
// Name: protected: void CMFCPropertyGridCtrl::OnCancelMode(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::OnCancelMode(CMFCPropertyGridCtrl *this)
{
  HWND__ *m_hWnd; // ebx
  HWND__ *v3; // ebx
  HWND__ *v4; // ebx

  if ( this->m_bTracking != 0 )
  {
    CMFCPropertyGridCtrl::TrackHeader(this, nOffset: -1);
    this->m_bTracking = 0;
    m_hWnd = this->m_hWnd;
    if ( GetCapture() == m_hWnd )
      ReleaseCapture();
  }
  if ( this->m_bTrackingDescr != 0 )
  {
    CMFCPropertyGridCtrl::TrackDescr(this, nOffset: 0x80000000);
    this->m_bTrackingDescr = 0;
    v3 = this->m_hWnd;
    if ( GetCapture() == v3 )
      ReleaseCapture();
  }
  v4 = this->m_hWnd;
  if ( GetCapture() == v4 )
    ReleaseCapture();
  CMFCPropertyGridToolTipCtrl::Deactivate(this: &this->m_IPToolTip);
  this->EndEditItem(this, a2: 1);
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1039C907
// Name: protected: void CMFCPropertyGridCtrl::OnSetFocus(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::OnSetFocus(CMFCPropertyGridCtrl *this, CWnd *pOldWnd)
{
  CMFCPropertyGridProperty *m_pSel; // eax

  CWnd::OnSetFocus(this, __formal: pOldWnd);
  m_pSel = this->m_pSel;
  this->m_bFocused = 1;
  if ( m_pSel != nullptr )
    RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: &m_pSel->m_Rect, hrgnUpdate: nullptr, flags: 0x105u);
}

//------------------------------------------------------------------------------
// Address: 0x1039C944
// Name: protected: void CMFCPropertyGridCtrl::OnKillFocus(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::OnKillFocus(CMFCPropertyGridCtrl *this, CWnd *pNewWnd)
{
  HWND__ *m_hWnd; // eax
  CMFCPropertyGridProperty *m_pSel; // ecx
  CMFCPropertyGridProperty *v5; // ecx

  if ( pNewWnd != nullptr )
    m_hWnd = pNewWnd->m_hWnd;
  else
    m_hWnd = nullptr;
  if ( !IsChild(hWndParent: this->m_hWnd, hWnd: m_hWnd) )
  {
    m_pSel = this->m_pSel;
    if ( m_pSel == nullptr || m_pSel->OnKillFocus(this: m_pSel, a2: pNewWnd) != 0 )
    {
      this->EndEditItem(this, a2: 1);
      v5 = this->m_pSel;
      this->m_bFocused = 0;
      if ( v5 != nullptr )
        CMFCPropertyGridProperty::Redraw(this: v5);
    }
  }
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1039C9AF
// Name: protected: void CMFCPropertyGridCtrl::OnStyleChanged(int,struct tagSTYLESTRUCT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::OnStyleChanged(
        CMFCPropertyGridCtrl *this,
        int nStyleType,
        tagSTYLESTRUCT *lpStyleStruct)
{
  CWnd::Default(this);
  this->AdjustLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x1039C9C7
// Name: protected: int CMFCPropertyGridCtrl::GetTotalItems(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPropertyGridCtrl::GetTotalItems(CMFCPropertyGridCtrl *this, int bIncludeHidden)
{
  int v2; // esi
  CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::CNode *m_pNodeHead; // eax
  CMFCPropertyGridProperty *data; // ecx
  CList<CMFCPropertyGridProperty *,CMFCPropertyGridProperty *>::CNode *i; // edx

  v2 = 0;
  if ( this->m_bAlphabeticMode != 0 )
  {
    if ( bIncludeHidden != 0 )
      return this->m_lstTerminalProps.m_nCount;
    m_pNodeHead = this->m_lstTerminalProps.m_pNodeHead;
    while ( m_pNodeHead != nullptr )
    {
      data = m_pNodeHead->data;
      m_pNodeHead = m_pNodeHead->pNext;
      if ( data->m_bIsVisible != 0 )
        ++v2;
    }
  }
  else
  {
    for ( i = this->m_lstProps.m_pNodeHead;
          i != nullptr;
          v2 += CMFCPropertyGridProperty::GetExpandedSubItems(this: i->data, bIncludeHidden) + 1 )
    {
      ;
    }
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1039CA22
// Name: public: virtual class CScrollBar __near * CMFCPropertyGridCtrl::GetScrollBarCtrl(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CScrollBar *__thiscall CMFCPropertyGridCtrl::GetScrollBarCtrl(CMFCPropertyGridCtrl *this, int nBar)
{
  CScrollBar *result; // eax

  if ( nBar == 0 )
    return nullptr;
  result = &this->m_wndScrollVert;
  if ( this == (CMFCPropertyGridCtrl *)-580 || this->m_wndScrollVert.m_hWnd == nullptr )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1039CA43
// Name: protected: void CMFCPropertyGridCtrl::OnLButtonDblClk(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridCtrl::OnLButtonDblClk(CMFCPropertyGridCtrl *this, unsigned int nFlags, CPoint point)
{
  int v4; // eax
  CMFCPropertyGridCtrl_vtbl *v5; // eax
  int v6; // eax
  CMFCHeaderCtrl *v7; // eax
  CMFCPropertyGridProperty *m_pSel; // ecx
  CWnd *m_pWndInPlace; // eax
  CRect *p_m_Rect; // esi
  HWND__ *m_hWnd; // [esp-8h] [ebp-58h]
  _HD_ITEMA hdItem; // [esp+Ch] [ebp-44h] BYREF
  CRect rectClient; // [esp+3Ch] [ebp-14h] BYREF

  CWnd::Default(this);
  if ( point.y > this->m_rectList.bottom || abs(lnumber: point.x - this->m_rectList.left - this->m_nLeftColumnWidth) > 2 )
  {
    m_pSel = this->m_pSel;
    if ( m_pSel != nullptr )
    {
      if ( m_pSel->m_bGroup == 0
        || m_pSel->m_bIsValueList != 0 && point.x >= this->m_rectList.left + this->m_nLeftColumnWidth )
      {
        if ( m_pSel->m_bEnabled != 0 )
        {
          if ( this->EditItem(this, a2: m_pSel, a3: nullptr) != 0 )
          {
            m_pWndInPlace = this->m_pSel->m_pWndInPlace;
            if ( m_pWndInPlace != nullptr )
            {
              SendMessageA(hWnd: m_pWndInPlace->m_hWnd, Msg: 0x201u, wParam: 0, lParam: 0);
              SendMessageA(hWnd: this->m_pSel->m_pWndInPlace->m_hWnd, Msg: 0x202u, wParam: 0, lParam: 0);
            }
          }
          p_m_Rect = &this->m_pSel->m_Rect;
          rectClient.left = p_m_Rect->left;
          p_m_Rect = (CRect *)((char *)p_m_Rect + 4);
          rectClient.top = p_m_Rect->left;
          p_m_Rect = (CRect *)((char *)p_m_Rect + 4);
          rectClient.right = p_m_Rect->left;
          rectClient.bottom = p_m_Rect->top;
          if ( PtInRect(lprc: &rectClient, pt: point.tagPOINT) )
            ((void (__thiscall *)(CMFCPropertyGridProperty *, int, int))this->m_pSel->OnDblClk)(
              a1: this->m_pSel,
              a2: point.x,
              a3: point.y);
        }
      }
      else
      {
        CMFCPropertyGridProperty::Expand(this: m_pSel, bExpand: m_pSel->m_bExpanded == 0);
      }
    }
  }
  else
  {
    m_hWnd = this->m_hWnd;
    memset(&rectClient, 0, sizeof(rectClient));
    GetClientRect(hWnd: m_hWnd, lpRect: &rectClient);
    v4 = (rectClient.right - rectClient.left) / 2;
    this->m_nLeftColumnWidth = v4;
    hdItem.cxy = v4 + 2;
    v5 = this->__vftable;
    hdItem.mask = 1;
    v6 = (int)v5->GetHeaderCtrl(this);
    SendMessageA(hWnd: *(HWND *)(v6 + 32), Msg: 0x1204u, wParam: 0, lParam: (LPARAM)&hdItem);
    hdItem.cxy = rectClient.right - rectClient.left + 10;
    v7 = this->GetHeaderCtrl(this);
    SendMessageA(hWnd: v7->m_hWnd, Msg: 0x1204u, wParam: 1u, lParam: (LPARAM)&hdItem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A4456
// Name: public: void CMFCEditBrowseCtrl::EnableBrowseButton(int,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCEditBrowseCtrl::EnableBrowseButton(CMFCEditBrowseCtrl *this, int bEnable, const char *szLabel)
{
  CMFCEditBrowseCtrl_vtbl *v4; // eax

  if ( this == nullptr || this->m_hWnd == nullptr || szLabel == nullptr )
    AfxThrowInvalidArgException();
  this->m_Mode = bEnable != 0;
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strLabel, pszSrc: szLabel);
  CImageList::DeleteImageList(this: &this->m_ImageBrowse);
  this->m_sizeImage.cx = 0;
  v4 = this->__vftable;
  this->m_sizeImage.cy = 0;
  v4->OnChangeLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A44B9
// Name: public: void CMFCEditBrowseCtrl::EnableFileBrowseButton(char const __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCEditBrowseCtrl::EnableFileBrowseButton(
        CMFCEditBrowseCtrl *this,
        const char *lpszDefExt,
        const char *lpszFilter)
{
  const char *v4; // eax
  const char *v5; // edi

  if ( this == nullptr || this->m_hWnd == nullptr )
    AfxThrowInvalidArgException();
  v4 = lpszDefExt;
  this->m_Mode = BrowseMode_File;
  v5 = &var;
  if ( lpszDefExt == nullptr )
    v4 = &var;
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strDefFileExt, pszSrc: v4);
  if ( lpszFilter != nullptr )
    v5 = lpszFilter;
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strFileFilter, pszSrc: v5);
  CMFCEditBrowseCtrl::SetInternalImage(this);
  this->OnChangeLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A4521
// Name: protected: long CMFCEditBrowseCtrl::OnInitControl(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCEditBrowseCtrl::OnInitControl(CMFCEditBrowseCtrl *this, unsigned int wParam, const char *lParam)
{
  CAfxStringMgr *StringManager; // eax
  CAfxStringMgr *v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  CTagManager tagManager; // [esp+10h] [ebp-1Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strDst; // [esp+18h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strBrowseMode; // [esp+1Ch] [ebp-10h] BYREF
  int v13; // [esp+28h] [ebp-4h]

  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strDst, pStringMgr: StringManager);
  v13 = 0;
  CMFCControlContainer::UTF8ToString(lpSrc: lParam, &strDst, nLength: wParam);
  CTagManager::CTagManager(this: &tagManager, lpszBuffer: strDst.m_pszData);
  LOBYTE(v13) = 1;
  v5 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strBrowseMode, pStringMgr: v5);
  LOBYTE(v13) = 2;
  if ( CTagManager::ExcludeTag(
         this: &tagManager,
         lpszTag: "MFCEditBrowse_Mode",
         strTag: &strBrowseMode,
         bIsCharsList: 0) != 0
    && *((_DWORD *)strBrowseMode.m_pszData - 3) != 0 )
  {
    v6 = atoi(nptr: strBrowseMode.m_pszData);
    if ( v6 != 0 )
    {
      v7 = v6 - 1;
      if ( v7 != 0 )
      {
        v8 = v7 - 1;
        if ( v8 != 0 )
        {
          if ( v8 == 1 )
            CMFCEditBrowseCtrl::EnableBrowseButton(this, bEnable: 1, szLabel: "...");
        }
        else
        {
          CMFCEditBrowseCtrl::EnableFolderBrowseButton(this);
        }
      }
      else
      {
        CMFCEditBrowseCtrl::EnableFileBrowseButton(this, lpszDefExt: nullptr, lpszFilter: nullptr);
      }
    }
    else
    {
      CMFCEditBrowseCtrl::EnableBrowseButton(this, bEnable: 0, szLabel: "...");
    }
  }
  ATL::CStringData::Release(this: (ATL::CStringData *)strBrowseMode.m_pszData - 1);
  LOBYTE(v13) = 0;
  CTagManager::~CTagManager(this: &tagManager);
  ATL::CStringData::Release(this: (ATL::CStringData *)strDst.m_pszData - 1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103A45F9
// Name: public: virtual void CMFCEditBrowseCtrl::OnBrowse(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCEditBrowseCtrl::OnBrowse(CMFCEditBrowseCtrl *this)
{
  HWND__ *m_hWnd; // eax
  CAfxStringMgr *v3; // eax
  CAfxStringMgr *v4; // eax
  char *v5; // ecx
  CAfxStringMgr *StringManager; // eax
  const unsigned __int8 *v7; // eax
  int v8; // eax
  HWND Parent; // eax
  HWND v10; // eax
  CWnd *v11; // eax
  char *m_pszData; // [esp-4h] [ebp-348h]
  char *v13; // [esp-4h] [ebp-348h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > result; // [esp+10h] [ebp-334h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v15; // [esp+14h] [ebp-330h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v16; // [esp+18h] [ebp-32Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v17; // [esp+1Ch] [ebp-328h] BYREF
  ATL::CSimpleStringT<char,0> v18; // [esp+20h] [ebp-324h] BYREF
  ATL::CSimpleStringT<char,0> v19; // [esp+24h] [ebp-320h] BYREF
  ATL::CSimpleStringT<char,0> v20; // [esp+28h] [ebp-31Ch] BYREF
  char v21; // [esp+2Fh] [ebp-315h]
  CFileDialog v22; // [esp+30h] [ebp-314h] BYREF
  char _Filename[268]; // [esp+234h] [ebp-110h] BYREF
  int v24; // [esp+340h] [ebp-4h]

  v19.m_pszData = nullptr;
  if ( this != nullptr )
    m_hWnd = this->m_hWnd;
  else
    m_hWnd = nullptr;
  if ( m_hWnd == nullptr )
    AfxThrowInvalidArgException();
  if ( this->m_Mode == BrowseMode_File )
  {
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v20, pStringMgr: StringManager);
    v24 = 2;
    CWnd::GetWindowTextA(this, rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v20);
    if ( *((_DWORD *)v20.m_pszData - 3) != 0 )
    {
      _splitpath_s(
        _Path: v20.m_pszData,
        _Drive: nullptr,
        _DriveSize: 0,
        _Dir: nullptr,
        _DirSize: 0,
        _Filename,
        _FilenameSize: 0x100u,
        _Ext: nullptr,
        _ExtSize: 0);
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
        this: &v17,
        pszSrc: _Filename);
      LOBYTE(v24) = 3;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::TrimLeft(this: &v17);
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::TrimRight(this: &v17);
      if ( *((_DWORD *)v17.m_pszData - 3) == 0 )
        ATL::CSimpleStringT<char,0>::Empty(this: &v20);
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
        this: &v16,
        pszSrc: "*?<>|");
      LOBYTE(v24) = 4;
      v7 = _mbspbrk(string: (const unsigned __int8 *)v20.m_pszData, charset: (const unsigned __int8 *)v16.m_pszData);
      if ( v7 != nullptr
        && v7 - (const unsigned __int8 *)v20.m_pszData >= 0
        && this->OnIllegalFileName(this, a2: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v20) == 0 )
      {
        CWnd::SetFocus(this);
        ATL::CStringData::Release(this: (ATL::CStringData *)v16.m_pszData - 1);
        ATL::CStringData::Release(this: (ATL::CStringData *)v17.m_pszData - 1);
        ATL::CStringData::Release(this: (ATL::CStringData *)v20.m_pszData - 1);
        return;
      }
      ATL::CStringData::Release(this: (ATL::CStringData *)v16.m_pszData - 1);
      LOBYTE(v24) = 2;
      ATL::CStringData::Release(this: (ATL::CStringData *)v17.m_pszData - 1);
    }
    CFileDialog::CFileDialog(
      this: &v22,
      bOpenFileDialog: 1,
      lpszDefExt: *((_DWORD *)this->m_strDefFileExt.m_pszData - 3) != 0 ? this->m_strDefFileExt.m_pszData : nullptr,
      lpszFileName: v20.m_pszData,
      dwFlags: 0,
      lpszFilter: *((_DWORD *)this->m_strFileFilter.m_pszData - 3) != 0 ? this->m_strFileFilter.m_pszData : nullptr,
      pParentWnd: nullptr,
      dwSize: 0,
      bVistaStyle: 1);
    LOBYTE(v24) = 5;
    if ( CFileDialog::DoModal(this: &v22) != 1
      || (m_pszData = CFileDialog::GetPathName(this: &v22, &result)->m_pszData,
          LOBYTE(v24) = 6,
          v19.m_pszData = (char *)1,
          v8 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(
                 this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v20,
                 psz: m_pszData),
          v21 = 1,
          v8 == 0) )
    {
      v21 = 0;
    }
    v24 = 5;
    if ( ((int)v19.m_pszData & 1) != 0 )
      ATL::CStringData::Release(this: (ATL::CStringData *)result.m_pszData - 1);
    if ( v21 != 0 )
    {
      v13 = CFileDialog::GetPathName(this: &v22, result: &v15)->m_pszData;
      LOBYTE(v24) = 7;
      CWnd::SetWindowTextA(this, lpszString: v13);
      LOBYTE(v24) = 5;
      ATL::CStringData::Release(this: (ATL::CStringData *)v15.m_pszData - 1);
      SendMessageA(hWnd: this->m_hWnd, Msg: 0xB9u, wParam: 1u, lParam: 0);
      this->OnAfterUpdate(this);
    }
    Parent = GetParent(hWnd: this->m_hWnd);
    if ( CWnd::FromHandle(hWnd: Parent) != nullptr )
    {
      v10 = GetParent(hWnd: this->m_hWnd);
      v11 = CWnd::FromHandle(hWnd: v10);
      RedrawWindow(hWnd: v11->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x481u);
    }
    LOBYTE(v24) = 2;
    CFileDialog::~CFileDialog(this: &v22);
    v5 = v20.m_pszData;
  }
  else
  {
    if ( this->m_Mode != BrowseMode_Folder || afxShellManager == nullptr )
      goto LABEL_32;
    v3 = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v19, pStringMgr: v3);
    v24 = 0;
    CWnd::GetWindowTextA(this, rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v19);
    v4 = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v18, pStringMgr: v4);
    LOBYTE(v24) = 1;
    if ( CShellManager::BrowseForFolder(
           this: afxShellManager,
           strFolder: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v18,
           pWndParent: this,
           lplszInitialFolder: v19.m_pszData,
           lpszTitle: nullptr,
           ulFlags: 1u,
           piFolderImage: nullptr) != 0
      && ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(
           this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v18,
           psz: v19.m_pszData) != 0 )
    {
      CWnd::SetWindowTextA(this, lpszString: v18.m_pszData);
      SendMessageA(hWnd: this->m_hWnd, Msg: 0xB9u, wParam: 1u, lParam: 0);
      this->OnAfterUpdate(this);
    }
    ATL::CStringData::Release(this: (ATL::CStringData *)v18.m_pszData - 1);
    v5 = v19.m_pszData;
  }
  v24 = -1;
  ATL::CStringData::Release(this: (ATL::CStringData *)v5 - 1);
LABEL_32:
  CWnd::SetFocus(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A4980
// Name: protected: static struct AFX_MSGMAP const __near * CMFCEditBrowseCtrl::GetThisMessageMap(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCEditBrowseCtrl::GetThisMessageMap(CMFCEditBrowseCtrl *this)
{
  return &messageMap_33;
}

//------------------------------------------------------------------------------
// Address: 0x103A4986
// Name: public: virtual struct CRuntimeClass __near * CMFCColorButton::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCColorButton::GetRuntimeClass(CMFCColorButton *this)
{
  return &CMFCColorButton::classCMFCColorButton;
}

//------------------------------------------------------------------------------
// Address: 0x103A498C
// Name: public: virtual class CSize CMFCMenuButton::SizeToContent(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CMFCMenuButton::SizeToContent(CMFCColorButton *this, CSize *result, int bCalcOnly)
{
  CSize v5; // [esp+8h] [ebp-8h] BYREF

  CMFCButton::SizeToContent(this, result, bCalcOnly: 0);
  result->cx += CMenuImages::Size(result: &v5)->cx;
  if ( bCalcOnly == 0 )
    CWnd::SetWindowPos(this, pWndInsertAfter: nullptr, x: -1, y: -1, cx: result->cx, cy: result->cy, nFlags: 0x16u);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103A49D2
// Name: protected: virtual void CMFCColorButton::OnDrawBorder(class CDC __near *,class CRect __near &,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorButton::OnDrawBorder(
        CMFCColorButton *this,
        CDC *pDC,
        CRect *rectClient,
        unsigned int __formal)
{
  CWnd *v4; // esi
  CMFCVisualManager *Instance; // eax
  CMFCVisualManager_vtbl *v6; // ebx
  int IsWindowEnabled; // eax
  CMFCVisualManager *v9; // [esp+10h] [ebp-4h]

  v4 = this;
  if ( CMFCButton::m_bWinXPTheme != 0 )
  {
    Instance = CMFCVisualManager::GetInstance();
    v6 = Instance->__vftable;
    v9 = Instance;
    IsWindowEnabled = CWnd::IsWindowEnabled(this: v4);
    if ( ((int (__thiscall *)(CMFCVisualManager *, CDC *, int, int, int, int, bool, _DWORD, int))v6->DrawComboBorderWinXP)(
           a1: v9,
           a2: pDC,
           a3: rectClient->left,
           a4: rectClient->top,
           a5: rectClient->right,
           a6: rectClient->bottom,
           a7: IsWindowEnabled == 0,
           a8: 0,
           a9: 1) != 0 )
      return;
    v4 = this;
  }
  CDC::Draw3dRect(
    this: pDC,
    lpRect: rectClient,
    clrTopLeft: afxGlobalData.clrBtnDkShadow,
    clrBottomRight: afxGlobalData.clrBtnHilite);
  InflateRect(lprc: rectClient, dx: -1, dy: -1);
  if ( v4[1].__vftable == nullptr || v4[1].m_xAccessibleServer.__vftable != nullptr )
    CDC::Draw3dRect(
      this: pDC,
      lpRect: rectClient,
      clrTopLeft: afxGlobalData.clrBtnShadow,
      clrBottomRight: afxGlobalData.clrBtnLight);
}

//------------------------------------------------------------------------------
// Address: 0x103A4A75
// Name: protected: virtual void CMFCColorButton::OnDrawFocusRect(class CDC __near *,class CRect const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorButton::OnDrawFocusRect(CMFCColorButton *this, CDC *pDC, const CRect *rectClient)
{
  CSize sizeArrow; // [esp+Ch] [ebp-20h] BYREF
  CMFCButton *v4; // [esp+14h] [ebp-18h]
  CRect rectColor; // [esp+18h] [ebp-14h] BYREF

  v4 = this;
  CMenuImages::Size(result: &sizeArrow);
  rectColor = *rectClient;
  rectColor.right += -8 - sizeArrow.cx;
  CMFCButton::OnDrawFocusRect(this: v4, pDC, rectClient: &rectColor);
}

//------------------------------------------------------------------------------
// Address: 0x103A4ACA
// Name: protected: void CMFCColorButton::OnLButtonDown(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorButton::OnLButtonDown(CMFCColorButton *this, unsigned int __formal, CPoint __formala)
{
  CWnd::SetFocus(this);
  this->OnShowColorPopup(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A4AE2
// Name: protected: int CMFCColorButton::IsDrawXPTheme(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCColorButton::IsDrawXPTheme(CMFCColorButton *this)
{
  CMFCVisualManager *Instance; // eax
  BOOL result; // eax

  result = false;
  if ( CMFCButton::m_bWinXPTheme != 0 )
  {
    Instance = CMFCVisualManager::GetInstance();
    if ( Instance->IsWindowsThemingSupported(this: Instance) != 0 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103A907B
// Name: public: long CFrameWndEx::OnSetText(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWndEx::OnSetText(CFrameWndEx *this, unsigned int __formal, const char *lParam)
{
  int v4; // edi

  v4 = CWnd::Default(this);
  CFrameImpl::OnSetText(this: &this->m_Impl, __formal: lParam);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x103A90A1
// Name: public: int CFrameWndEx::OnNcActivate(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWndEx::OnNcActivate(CFrameWndEx *this, int bActive)
{
  if ( CFrameImpl::OnNcActivate(this: &this->m_Impl, bActive) != 0 )
    return 1;
  else
    return CFrameWnd::OnNcActivate(this, bActive);
}

//------------------------------------------------------------------------------
// Address: 0x103A90CF
// Name: public: long CFrameWndEx::OnChangeVisualManager(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWndEx::OnChangeVisualManager(CFrameWndEx *this, unsigned int __formal, unsigned int __formala)
{
  CFrameImpl::OnChangeVisualManager(this: &this->m_Impl);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103A90DF
// Name: public: long CFrameWndEx::OnDWMCompositionChanged(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWndEx::OnDWMCompositionChanged(CFrameWndEx *this, unsigned int __formal, unsigned int __formala)
{
  CFrameImpl::OnDWMCompositionChanged(this: &this->m_Impl);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103A90EF
// Name: public: static class CObject __near * CFrameWndEx::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFrameWndEx *__stdcall CFrameWndEx::CreateObject()
{
  CFrameWndEx *v0; // ecx
  CFrameWndEx *result; // eax

  v0 = (CFrameWndEx *)operator new(nSize: 0x41Cu);
  result = nullptr;
  if ( v0 != nullptr )
    return CFrameWndEx::CFrameWndEx(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103A9140
// Name: public: virtual int CFrameWndEx::PreTranslateMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CFrameWndEx::PreTranslateMessage(CFrameWndEx *this, CWnd *pMsg)
{
  unsigned int m_dwRef; // eax
  int v5; // eax
  unsigned int v7; // eax
  CMFCRibbonBar *v8; // ecx
  int v9; // eax
  CSmartDockingManager *m_pSDManager; // ecx
  HWND Capture; // eax
  CWnd *v12; // eax
  CObject *v13; // eax
  CMFCRibbonBar *m_pRibbonBar; // ecx
  int v15; // ebx
  HIMC Context; // eax
  unsigned int m_pOuterUnknown; // eax
  HWND Focus; // eax
  CWnd *v19; // eax
  CWnd *m_pMenuBar; // ecx
  CWnd *v21; // eax
  tagPOINT v22; // [esp-Ch] [ebp-28h]
  HWND__ *v23; // [esp-4h] [ebp-20h]
  HWND__ *v24; // [esp-4h] [ebp-20h]
  tagPOINT Point; // [esp+Ch] [ebp-10h] BYREF
  int bIMEActive; // [esp+14h] [ebp-8h]
  int bProcessAccel; // [esp+18h] [ebp-4h] BYREF
  CWnd *pWnd; // [esp+24h] [ebp+8h]
  CWnd *pWnda; // [esp+24h] [ebp+8h]

  m_dwRef = pMsg->m_dwRef;
  bProcessAccel = 1;
  if ( m_dwRef > 0x105 )
  {
    if ( m_dwRef == 512 )
    {
      v24 = (HWND__ *)pMsg->__vftable;
      Point.x = SLOWORD(pMsg->m_xInnerUnknown);
      Point.y = SHIWORD(pMsg->m_xInnerUnknown);
      v21 = CWnd::FromHandle(hWnd: v24);
      if ( v21 != nullptr )
        ClientToScreen(hWnd: v21->m_hWnd, lpPoint: &Point);
      v5 = CFrameImpl::ProcessMouseMove(this: &this->m_Impl, pt: Point);
    }
    else
    {
      if ( m_dwRef == 513 )
        goto LABEL_69;
      if ( m_dwRef <= 0x203 )
        return CFrameWnd::PreTranslateMessage(this, (tagMSG *)pMsg);
      if ( m_dwRef <= 0x205 )
        goto LABEL_69;
      if ( m_dwRef <= 0x206 )
        return CFrameWnd::PreTranslateMessage(this, (tagMSG *)pMsg);
      if ( m_dwRef <= 0x208 )
      {
LABEL_69:
        v23 = (HWND__ *)pMsg->__vftable;
        Point.x = SLOWORD(pMsg->m_xInnerUnknown);
        Point.y = SHIWORD(pMsg->m_xInnerUnknown);
        pWnda = CWnd::FromHandle(hWnd: v23);
        if ( pWnda != nullptr && IsWindow(hWnd: (HWND)pMsg->__vftable) )
          ClientToScreen(hWnd: pWnda->m_hWnd, lpPoint: &Point);
        if ( CFrameImpl::ProcessMouseClick(
               this: &this->m_Impl,
               uiMsg: pMsg->m_dwRef,
               pt: Point,
               hwnd: (HWND__ *)pMsg->__vftable) == 0
          && IsWindow(hWnd: (HWND)pMsg->__vftable) )
        {
          return CFrameWnd::PreTranslateMessage(this, (tagMSG *)pMsg);
        }
        return 1;
      }
      if ( m_dwRef != 522 )
        return CFrameWnd::PreTranslateMessage(this, (tagMSG *)pMsg);
      v5 = CFrameImpl::ProcessMouseWheel(
             this: &this->m_Impl,
             wParam: (unsigned int)pMsg->m_pOuterUnknown,
             lParam: pMsg->m_xInnerUnknown);
    }
LABEL_10:
    if ( v5 == 0 )
      return CFrameWnd::PreTranslateMessage(this, (tagMSG *)pMsg);
    return 1;
  }
  if ( m_dwRef == 261 )
  {
    m_pRibbonBar = this->m_Impl.m_pRibbonBar;
    if ( m_pRibbonBar == nullptr
      || CMFCRibbonBar::OnSysKeyUp(
           this: m_pRibbonBar,
           pFrameWnd: this,
           wParam: (unsigned int)pMsg->m_pOuterUnknown,
           __formal: pMsg->m_xInnerUnknown) == 0 )
    {
      Point.y = GetKeyState(nVirtKey: 17) < 0;
      v15 = (unsigned __int16)GetKeyState(nVirtKey: 16) >> 15;
      Context = ImmGetContext(a1: this->m_hWnd);
      pWnd = (CWnd *)Context;
      bIMEActive = Context != nullptr && ImmGetOpenStatus(a1: Context);
      if ( pWnd != nullptr )
        ImmReleaseContext(a1: this->m_hWnd, a2: (HIMC)pWnd);
      if ( this->m_Impl.m_pMenuBar != nullptr )
      {
        m_pOuterUnknown = (unsigned int)pMsg->m_pOuterUnknown;
        if ( m_pOuterUnknown == 18 || m_pOuterUnknown == 121 && Point.y == 0 && v15 == 0 && bIMEActive == 0 )
        {
          Focus = GetFocus();
          v19 = CWnd::FromHandle(hWnd: Focus);
          m_pMenuBar = this->m_Impl.m_pMenuBar;
          if ( m_pMenuBar == v19 )
          {
            m_pMenuBar = this;
          }
          else if ( (pMsg->m_xInnerUnknown & 0x20000000) != 0 )
          {
            return 1;
          }
          CWnd::SetFocus(this: m_pMenuBar);
          return 1;
        }
      }
      if ( CMFCPopupMenu::m_pActivePopupMenu == nullptr )
        return CFrameWnd::PreTranslateMessage(this, (tagMSG *)pMsg);
      v9 = IsWindow(hWnd: *((HWND *)CMFCPopupMenu::m_pActivePopupMenu + 8));
      goto LABEL_25;
    }
    return 1;
  }
  if ( m_dwRef <= 0xA8 )
  {
    if ( m_dwRef >= 0xA7 )
    {
LABEL_9:
      v22.y = SHIWORD(pMsg->m_xInnerUnknown);
      v22.x = SLOWORD(pMsg->m_xInnerUnknown);
      v5 = CFrameImpl::ProcessMouseClick(this: &this->m_Impl, uiMsg: m_dwRef, pt: v22, hwnd: (HWND__ *)pMsg->__vftable);
      goto LABEL_10;
    }
    if ( m_dwRef != 123 )
    {
      if ( m_dwRef <= 0xA0 || m_dwRef > 0xA2 && m_dwRef - 164 > 1 )
        return CFrameWnd::PreTranslateMessage(this, (tagMSG *)pMsg);
      goto LABEL_9;
    }
LABEL_17:
    if ( afxGlobalData.m_bSysUnderlineKeyboardShortcuts == 0 && afxGlobalData.m_bUnderlineKeyboardShortcuts == 0 )
    {
      afxGlobalData.m_bUnderlineKeyboardShortcuts = 1;
      CMFCToolBar::RedrawUnderlines();
    }
    if ( CMFCPopupMenu::m_pActivePopupMenu != nullptr
      && IsWindow(hWnd: *((HWND *)CMFCPopupMenu::m_pActivePopupMenu + 8))
      && pMsg->m_pOuterUnknown == (IUnknown *)18 )
    {
      SendMessageA(hWnd: *((HWND *)CMFCPopupMenu::m_pActivePopupMenu + 8), Msg: 0x10u, wParam: 0, lParam: 0);
      return 1;
    }
    v9 = CFrameImpl::ProcessKeyboard(this: &this->m_Impl, nKey: (int)pMsg->m_pOuterUnknown, pbProcessAccel: nullptr);
LABEL_25:
    if ( v9 == 0 )
      return CFrameWnd::PreTranslateMessage(this, (tagMSG *)pMsg);
    return 1;
  }
  v7 = m_dwRef - 256;
  if ( v7 != 0 )
  {
    if ( v7 != 4 )
      return CFrameWnd::PreTranslateMessage(this, (tagMSG *)pMsg);
    v8 = this->m_Impl.m_pRibbonBar;
    if ( v8 != nullptr
      && CMFCRibbonBar::OnSysKeyDown(
           this: v8,
           pFrameWnd: this,
           wParam: (unsigned int)pMsg->m_pOuterUnknown,
           lParam: pMsg->m_xInnerUnknown) != 0 )
    {
      return 1;
    }
    goto LABEL_17;
  }
  if ( CFrameImpl::IsHelpKey(lpMsg: (tagMSG *)pMsg) == 0
    && CFrameImpl::ProcessKeyboard(
         this: &this->m_Impl,
         nKey: (int)pMsg->m_pOuterUnknown,
         pbProcessAccel: &bProcessAccel) != 0 )
  {
    return 1;
  }
  if ( pMsg->m_pOuterUnknown == (IUnknown *)27 )
  {
    if ( this->m_Impl.m_FullScreenMgr.m_bFullScreen != 0 )
      CFullScreenImpl::RestoreState(this: &this->m_Impl.m_FullScreenMgr, pFrame: this);
    m_pSDManager = this->m_dockManager.m_pSDManager;
    if ( m_pSDManager != nullptr && m_pSDManager->m_bCreated != 0 && m_pSDManager->m_bStarted != 0 )
      CSmartDockingManager::CauseCancelMode(this: m_pSDManager);
    Capture = GetCapture();
    v12 = CWnd::FromHandle(hWnd: Capture);
    v13 = AfxDynamicDownCast(pClass: &CPaneDivider::classCPaneDivider, pObject: v12);
    if ( v13 != nullptr )
    {
      SendMessageA(hWnd: (HWND)v13[8].__vftable, Msg: 0x1Fu, wParam: 0, lParam: 0);
      return 1;
    }
  }
  if ( bProcessAccel != 0 )
    return CFrameWnd::PreTranslateMessage(this, (tagMSG *)pMsg);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103A94D8
// Name: public: virtual void CFrameWndEx::OnClosePopupMenu(class CMFCPopupMenu __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWndEx::OnClosePopupMenu(CFrameWndEx *this, CMFCPopupMenu *pMenuPopup)
{
  CMFCPopupMenu *ParentPopupMenu; // eax

  if ( afxGlobalData.m_bEnableAccessibility != 0 && pMenuPopup != nullptr )
  {
    ParentPopupMenu = CMFCPopupMenu::GetParentPopupMenu(this: pMenuPopup);
    if ( pMenuPopup->m_bEscClose != 0 || ParentPopupMenu != nullptr || pMenuPopup->m_pParentBtn == nullptr )
      NotifyWinEvent(event: 7u, hwnd: pMenuPopup->m_hWnd, idObject: 0, idChild: 0);
    else
      NotifyWinEvent(event: 5u, hwnd: pMenuPopup->m_hWnd, idObject: 0, idChild: 0);
  }
  if ( CMFCPopupMenu::m_pActivePopupMenu == (HWND)pMenuPopup )
    CMFCPopupMenu::m_pActivePopupMenu = nullptr;
  CDockingManager::OnClosePopupMenu(this: &this->m_dockManager);
}

//------------------------------------------------------------------------------
// Address: 0x103A9546
// Name: public: void CFrameWndEx::OnClose(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWndEx::OnClose(CFrameWndEx *this)
{
  CFrameWnd *m_pPrintPreviewFrame; // eax
  COleClientItem *v3; // eax

  m_pPrintPreviewFrame = this->m_pPrintPreviewFrame;
  if ( m_pPrintPreviewFrame != nullptr )
  {
    SendMessageA(hWnd: m_pPrintPreviewFrame->m_hWnd, Msg: 0x111u, wParam: 0xE300u, lParam: 0);
    this->m_pPrintPreviewFrame = nullptr;
  }
  else
  {
    v3 = this->GetInPlaceActiveItem(this);
    if ( v3 != nullptr )
      COleClientItem::Deactivate(this: v3);
    CFrameImpl::OnCloseFrame(this: &this->m_Impl);
    CFrameWnd::OnClose(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103A959C
// Name: protected: virtual void CFrameWndEx::HtmlHelpA(unsigned long,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFrameWndEx::HtmlHelpA(CFrameWndEx *this, unsigned int dwData, unsigned int nCmd)
{
  if ( dwData != 0 || this->m_bContextHelp == 0 )
    CWnd::HtmlHelpA(this, dwData, nCmd);
  else
    CFrameWndEx::OnContextHelp(this);
}

//------------------------------------------------------------------------------
// Address: 0x103AB051
// Name: public: static class CSize CMFCToolBar::GetMenuImageSize(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__stdcall CMFCToolBar::GetMenuImageSize(CSize *result)
{
  CSize *v1; // eax
  int cx; // ecx
  int cy; // eax
  long double m_dblRibbonImageScale; // st6
  int m_bIsRibbonImageScale; // ecx
  long double v6; // st5
  long double v7; // st5
  long double v8; // st7

  v1 = &CMFCToolBar::m_sizeImage;
  if ( CMFCToolBar::m_sizeMenuImage.cx != -1 )
    v1 = &CMFCToolBar::m_sizeMenuImage;
  cx = v1->cx;
  cy = v1->cy;
  m_dblRibbonImageScale = afxGlobalData.m_dblRibbonImageScale;
  result->cx = cx;
  m_bIsRibbonImageScale = afxGlobalData.m_bIsRibbonImageScale;
  result->cy = cy;
  if ( m_bIsRibbonImageScale != 0 )
    v6 = m_dblRibbonImageScale;
  else
    v6 = 1.0;
  if ( 1.0 != v6 )
  {
    if ( m_bIsRibbonImageScale != 0 )
      v7 = m_dblRibbonImageScale;
    else
      v7 = 1.0;
    if ( m_bIsRibbonImageScale == 0 )
      m_dblRibbonImageScale = 1.0;
    v8 = v7 * (double)result->cy + 0.5;
    result->cx = (int)(m_dblRibbonImageScale * (double)result->cx + 0.5);
    result->cy = (int)v8;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103AB0E3
// Name: public: static class CSize CMFCToolBar::GetMenuButtonSize(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__stdcall CMFCToolBar::GetMenuButtonSize(CSize *result)
{
  CSize *v1; // eax
  int cy; // ecx

  v1 = result;
  if ( CMFCToolBar::m_sizeMenuButton.cx == -1 )
  {
    result->cx = CMFCToolBar::m_sizeButton.cx;
    cy = CMFCToolBar::m_sizeButton.cy;
  }
  else
  {
    result->cx = CMFCToolBar::m_sizeMenuButton.cx;
    cy = CMFCToolBar::m_sizeMenuButton.cy;
  }
  result->cy = cy;
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x103AB115
// Name: public: class CMFCToolBarMenuButton __near * CMFCToolBar::GetDroppedDownMenu(int __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolBarMenuButton *__thiscall CMFCToolBar::GetDroppedDownMenu(CMFCToolBar *this, int *pIndex)
{
  int v2; // ebx
  CObList::CNode *m_pNodeHead; // esi
  CObject *v5; // edi
  CObject *data; // [esp-Ch] [ebp-10h]

  v2 = 0;
  if ( this->m_Buttons.m_nCount == 0 )
    return nullptr;
  m_pNodeHead = this->m_Buttons.m_pNodeHead;
  if ( m_pNodeHead != nullptr )
  {
    while ( 1 )
    {
      data = m_pNodeHead->data;
      m_pNodeHead = m_pNodeHead->pNext;
      v5 = AfxDynamicDownCast(pClass: &CMFCToolBarMenuButton::classCMFCToolBarMenuButton, pObject: data);
      if ( v5 != nullptr && ((int (__thiscall *)(CObject *))v5->__vftable[9].dtr_CObject)(a1: v5) != 0 )
        break;
      ++v2;
      if ( m_pNodeHead == nullptr )
        goto LABEL_7;
    }
    if ( pIndex != nullptr )
      *pIndex = v2;
    return (CMFCToolBarMenuButton *)v5;
  }
  else
  {
LABEL_7:
    if ( pIndex != nullptr )
      *pIndex = -1;
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AB187
// Name: public: void CMFCToolBar::EnableLargeIcons(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::EnableLargeIcons(CMFCToolBar *this, int bEnable)
{
  this->m_bLargeIconsAreEnbaled = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x103AB199
// Name: public: void CMFCToolBar::EnableTextLabels(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::EnableTextLabels(CMFCToolBar *this, int bEnable)
{
  if ( this->m_bMenuMode == 0 )
  {
    this->m_bTextLabels = bEnable;
    this->AdjustLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AB1BC
// Name: public: virtual void CMFCToolBar::ResetImages(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::ResetImages(CMFCToolBar *this)
{
  CObList::CNode *m_pNodeHead; // esi
  CObject *data; // ecx

  if ( this->m_bLocked == 0 )
  {
    m_pNodeHead = this->m_Buttons.m_pNodeHead;
    while ( m_pNodeHead != nullptr )
    {
      data = m_pNodeHead->data;
      m_pNodeHead = m_pNodeHead->pNext;
      data->__vftable[12].GetRuntimeClass(this: data);
    }
    if ( this->IsFloating(this) != 0 )
      this->AdjustLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AB20B
// Name: public: virtual int CMFCToolBar::OnUserToolTip(class CMFCToolBarButton __near *,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::OnUserToolTip(
        CMFCToolBar *this,
        CMFCToolBarButton *pButton,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *strTTText)
{
  CFrameWnd *v3; // eax
  CFrameWnd *v4; // esi
  const CWnd *v5; // eax
  CObject *v6; // eax
  CObject *v8; // eax
  CObject *v9; // eax
  CObject *v10; // eax

  v3 = AFXGetParentFrame(pWnd: this);
  v4 = v3;
  if ( v3 == nullptr )
    return 0;
  v5 = (const CWnd *)AfxDynamicDownCast(pClass: &CMFCDropDownFrame::classCMFCDropDownFrame, pObject: v3);
  if ( v5 != nullptr )
  {
    v4 = AFXGetParentFrame(pWnd: v5);
    if ( v4 == nullptr )
      return 0;
  }
  v6 = AfxDynamicDownCast(pClass: &CMDIFrameWndEx::classCMDIFrameWndEx, pObject: v4);
  if ( v6 != nullptr )
    return ((int (__thiscall *)(CObject *, CMFCToolBarButton *, ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *))v6->__vftable[41].dtr_CObject)(
             a1: v6,
             a2: pButton,
             a3: strTTText);
  v8 = AfxDynamicDownCast(pClass: &CFrameWndEx::classCFrameWndEx, pObject: v4);
  if ( v8 != nullptr )
    return ((int (__thiscall *)(CObject *, CMFCToolBarButton *, ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *))v8->__vftable[39].Serialize)(
             a1: v8,
             a2: pButton,
             a3: strTTText);
  v9 = AfxDynamicDownCast(pClass: &CMDIChildWndEx::classCMDIChildWndEx, pObject: v4);
  if ( v9 != nullptr )
    return ((int (__thiscall *)(CObject *, CMFCToolBarButton *, ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *))v9->__vftable[38].GetRuntimeClass)(
             a1: v9,
             a2: pButton,
             a3: strTTText);
  v10 = AfxDynamicDownCast(pClass: &COleIPFrameWndEx::classCOleIPFrameWndEx, pObject: nullptr);
  if ( v10 != nullptr )
    return ((int (__thiscall *)(CObject *, CMFCToolBarButton *, ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *))v10->__vftable[42].GetRuntimeClass)(
             a1: v10,
             a2: pButton,
             a3: strTTText);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103AB2BC
// Name: public: static class CObList const __near & CMFCToolBar::GetAllToolbars(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const CObList *__stdcall CMFCToolBar::GetAllToolbars()
{
  return &afxAllToolBars;
}

//------------------------------------------------------------------------------
// Address: 0x103CF383
// Name: protected: virtual void CMFCCaptionBar::OnDrawImage(class CDC __near *,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCCaptionBar::OnDrawImage(CMFCCaptionBar *this, CDC *pDC, CRect rect)
{
  HICON__ *m_hIcon; // edx
  HDC__ *m_hDC; // eax
  int v5; // eax
  int v6; // esi
  CMFCToolBarImages *p_m_Bitmap; // ebx
  tagAFXDrawState v8; // [esp+4h] [ebp-Ch] BYREF

  m_hIcon = this->m_hIcon;
  if ( m_hIcon != nullptr )
  {
    if ( pDC != nullptr )
      m_hDC = pDC->m_hDC;
    else
      m_hDC = nullptr;
    DrawIconEx(
      hdc: m_hDC,
      xLeft: rect.left,
      yTop: rect.top,
      hIcon: m_hIcon,
      cxWidth: rect.right - rect.left,
      cyWidth: rect.bottom - rect.top,
      istepIfAniCur: 0,
      hbrFlickerFreeDraw: nullptr,
      diFlags: 3u);
  }
  else if ( this->m_Bitmap.m_iCount > 0 )
  {
    if ( this->m_bStretchImage != 0 )
    {
      v5 = rect.right - rect.left;
      v6 = rect.bottom - rect.top;
    }
    else
    {
      v5 = this->m_rectImage.right - this->m_rectImage.left;
      v6 = this->m_rectImage.bottom - this->m_rectImage.top;
    }
    p_m_Bitmap = &this->m_Bitmap;
    CMFCToolBarImages::PrepareDrawImage(
      this: &this->m_Bitmap,
      ds: &v8,
      sizeImageDest: (CSize)__PAIR64__(v6, v5),
      bFadeInactive: 0);
    CMFCToolBarImages::Draw(
      this: p_m_Bitmap,
      pDCDest: pDC,
      xDest: rect.left,
      yDest: rect.top,
      iImage: 0,
      bHilite: 0,
      bDisabled: 0,
      bIndeterminate: 0,
      bShadow: 0,
      bInactive: 0,
      alphaSrc: 0xFFu);
    CMFCToolBarImages::EndDrawImage(this: p_m_Bitmap, ds: &v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103CF441
// Name: protected: void CMFCCaptionBar::OnMouseMove(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCCaptionBar::OnMouseMove(CMFCCaptionBar *this, unsigned int nFlags, CPoint point)
{
  int v4; // eax
  BOOL v5; // eax
  int v6; // eax
  BOOL v7; // eax
  HWND__ *v8; // eax
  HWND__ *m_hWnd; // [esp-Ch] [ebp-28h]
  HWND__ *v10; // [esp-Ch] [ebp-28h]
  tagTRACKMOUSEEVENT trackmouseevent; // [esp+Ch] [ebp-10h] BYREF

  CPane::OnMouseMove(this, nFlags, point);
  if ( this->m_uiBtnID != 0 && this->m_bBtnEnabled != 0 )
  {
    v4 = PtInRect(lprc: &this->m_rectButton, pt: point.tagPOINT);
    if ( this->m_bIsBtnHighlighted != v4 )
    {
      this->m_bIsBtnHighlighted = v4;
      v5 = (nFlags & 1) != 0 && v4 != 0;
      m_hWnd = this->m_hWnd;
      this->m_bIsBtnPressed = v5;
      InvalidateRect(hWnd: m_hWnd, lpRect: &this->m_rectButton, bErase: true);
      UpdateWindow(hWnd: this->m_hWnd);
    }
  }
  if ( !IsRectEmpty(lprc: &this->m_rectClose) )
  {
    v6 = PtInRect(lprc: &this->m_rectClose, pt: point.tagPOINT);
    if ( this->m_bIsCloseBtnHighlighted != v6 )
    {
      this->m_bIsCloseBtnHighlighted = v6;
      v7 = (nFlags & 1) != 0 && v6 != 0;
      v10 = this->m_hWnd;
      this->m_bIsCloseBtnPressed = v7;
      InvalidateRect(hWnd: v10, lpRect: &this->m_rectClose, bErase: true);
      UpdateWindow(hWnd: this->m_hWnd);
    }
  }
  if ( this->m_bTracked == 0 )
  {
    v8 = this->m_hWnd;
    trackmouseevent.dwHoverTime = -1;
    trackmouseevent.hwndTrack = v8;
    this->m_bTracked = 1;
    trackmouseevent.cbSize = 16;
    trackmouseevent.dwFlags = 2;
    AFXTrackMouse(ptme: &trackmouseevent);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D7B03
// Name: public: virtual unsigned int CDockSite::GetDockSiteID(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CDockSite::GetDockSiteID(CDockSite *this)
{
  return this->m_nDockBarID;
}

//------------------------------------------------------------------------------
// Address: 0x103D7B0A
// Name: public: virtual CDockSite::~CDockSite(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockSite::~CDockSite(CDockSite *this)
{
  CObject *v2; // eax
  CObList *p_m_lstDockBarRows; // ecx

  this->__vftable = (CDockSite_vtbl *)&CDockSite::`vftable';
  while ( 1 )
  {
    p_m_lstDockBarRows = &this->m_lstDockBarRows;
    if ( this->m_lstDockBarRows.m_nCount == 0 )
      break;
    v2 = CObList::RemoveHead(this: p_m_lstDockBarRows);
    if ( v2 != nullptr )
      ((void (__thiscall *)(CObject *, int))v2->dtr_CObject)(a1: v2, a2: 1);
  }
  CObList::~CObList(this: p_m_lstDockBarRows);
  CObList::~CObList(this: &this->m_lstControlBars);
  CBasePane::~CBasePane(this);
}

//------------------------------------------------------------------------------
// Address: 0x103D7B74
// Name: protected: class CDockingPanesRow __near * CDockSite::FindNextVisibleRow(struct __POSITION __near * __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDockingPanesRow *__thiscall CDockSite::FindNextVisibleRow(CDockSite *this, __POSITION **pos, int bForward)
{
  __POSITION *m_pNodeHead; // eax
  CObList *p_m_lstDockBarRows; // ecx
  CObList *v8; // ecx
  CObject **v9; // eax
  CObject *v10; // ebx
  __POSITION *posSave; // [esp+10h] [ebp+8h]

  if ( this->m_lstDockBarRows.m_nCount != 0 )
  {
    if ( *pos != nullptr )
    {
      p_m_lstDockBarRows = &this->m_lstDockBarRows;
      if ( bForward != 0 )
        CObList::GetNext(this: p_m_lstDockBarRows, rPosition: pos);
      else
        CObList::GetPrev(this: p_m_lstDockBarRows, rPosition: pos);
    }
    else
    {
      if ( bForward != 0 )
        m_pNodeHead = (__POSITION *)this->m_lstDockBarRows.m_pNodeHead;
      else
        m_pNodeHead = (__POSITION *)this->m_lstDockBarRows.m_pNodeTail;
      *pos = m_pNodeHead;
    }
    if ( *pos != nullptr )
    {
      while ( 1 )
      {
        posSave = *pos;
        v8 = &this->m_lstDockBarRows;
        v9 = bForward != 0 ? CObList::GetNext(this: v8, rPosition: pos) : CObList::GetPrev(this: v8, rPosition: pos);
        v10 = *v9;
        if ( ((int (__thiscall *)(CObject *))(*v9)->__vftable[7].dtr_CObject)(a1: *v9) != 0 )
          break;
        if ( *pos == nullptr )
          return nullptr;
      }
      *pos = posSave;
      return (CDockingPanesRow *)v10;
    }
    else
    {
      return nullptr;
    }
  }
  else
  {
    *pos = nullptr;
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D7C0F
// Name: protected: virtual void CDockSite::CalcWindowRect(struct tagRECT __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockSite::CalcWindowRect(CDockSite *this, tagRECT *lpClientRect, unsigned int nAdjustType)
{
  CWnd::CalcWindowRect(this, lpClientRect, nAdjustType);
}

//------------------------------------------------------------------------------
// Address: 0x103D7C1A
// Name: public: virtual void CDockSite::RemovePane(class CPane __near *,enum AFX_DOCK_METHOD)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockSite::RemovePane(CDockSite *this, CPane *pControlBar, AFX_DOCK_METHOD __formal)
{
  CObList *p_m_lstControlBars; // esi
  __POSITION *v4; // eax
  CDockingPanesRow *m_pDockBarRow; // ecx

  if ( this->m_lstControlBars.m_nCount != 0 )
  {
    p_m_lstControlBars = &this->m_lstControlBars;
    v4 = (__POSITION *)CPtrList::Find(this: &this->m_lstControlBars, searchValue: pControlBar, startAfter: nullptr);
    if ( v4 != nullptr )
    {
      CPtrList::RemoveAt(this: p_m_lstControlBars, position: v4);
      m_pDockBarRow = pControlBar->m_pDockBarRow;
      if ( m_pDockBarRow != nullptr )
        m_pDockBarRow->RemovePane(this: m_pDockBarRow, a2: pControlBar);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D7C5F
// Name: public: virtual void CDockSite::FixupVirtualRects(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockSite::FixupVirtualRects(CDockSite *this)
{
  CObList::CNode *m_pNodeHead; // esi
  CDockingPanesRow *data; // ecx

  m_pNodeHead = this->m_lstDockBarRows.m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    data = (CDockingPanesRow *)m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    CDockingPanesRow::FixupVirtualRects(this: data, bMoveBackToVirtualRect: false, pBarToExclude: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D7C8A
// Name: public: virtual class CDockingPanesRow __near * CDockSite::CreateRow(class CDockSite __near *,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDockingPanesRow *__thiscall CDockSite::CreateRow(CDockSite *this, CDockSite *__formal, int nOffset, int nRowHeight)
{
  CDockingPanesRow *v5; // ecx
  CDockingPanesRow *v6; // esi

  v5 = (CDockingPanesRow *)operator new(nSize: 0x48u);
  if ( v5 != nullptr )
    v6 = CDockingPanesRow::CDockingPanesRow(this: v5, pParentDockBar: this, nOffset, nHeight: nRowHeight);
  else
    v6 = nullptr;
  if ( v6->Create(this: v6) != 0 )
    return v6;
  ((void (__thiscall *)(CDockingPanesRow *, int))v6->dtr_CObject)(a1: v6, a2: 1);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103D7CE5
// Name: public: virtual void CDockSite::OnInsertRow(struct __POSITION __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockSite::OnInsertRow(CDockSite *this, __POSITION *pos)
{
  _DWORD *v2; // esi
  int v3; // edi
  int v4; // ecx

  if ( pos == nullptr )
    AfxThrowInvalidArgException();
  v2 = *(_DWORD **)pos;
  v3 = *(_DWORD *)(*(_DWORD *)&pos[8] + 12);
  while ( v2 != nullptr )
  {
    v4 = v2[2];
    v2 = (_DWORD *)*v2;
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 56))(a1: v4, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D7D1D
// Name: public: virtual void CDockSite::OnRemoveRow(struct __POSITION __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockSite::OnRemoveRow(CDockSite *this, __POSITION *pos, int bByShow)
{
  _DWORD *v3; // esi
  _DWORD *v4; // edi
  int v5; // edi
  int v6; // ecx

  if ( pos == nullptr )
    AfxThrowInvalidArgException();
  v3 = *(_DWORD **)pos;
  v4 = *(_DWORD **)&pos[8];
  if ( (*(int (__thiscall **)(_DWORD *))(*v4 + 88))(a1: v4) != 0 || bByShow != 0 )
  {
    v5 = v4[3];
    while ( v3 != nullptr )
    {
      v6 = v3[2];
      v3 = (_DWORD *)*v3;
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 56))(a1: v6, a2: -v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D7D69
// Name: public: virtual void CDockSite::OnShowRow(struct __POSITION __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockSite::OnShowRow(CDockSite *this, __POSITION *pos, int bShow)
{
  CDockSite_vtbl *v3; // eax

  if ( pos == nullptr )
    AfxThrowInvalidArgException();
  v3 = this->__vftable;
  if ( bShow != 0 )
    ((void (__stdcall *)(__POSITION *))v3->OnInsertRow)(a1: pos);
  else
    ((void (__stdcall *)(__POSITION *, int))v3->OnRemoveRow)(a1: pos, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x103D7D9B
// Name: public: virtual int CDockSite::OnResizeRow(class CDockingPanesRow __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockSite::OnResizeRow(CDockSite *this, CDockingPanesRow *pRowToResize, int nOffset)
{
  int v4; // ebx
  int result; // eax
  CObList::CNode *v6; // eax
  CObList::CNode *pNext; // esi
  CObject *data; // ecx

  v4 = pRowToResize->Resize(this: pRowToResize, a2: nOffset);
  result = pRowToResize->IsVisible(this: pRowToResize);
  if ( result != 0 )
  {
    v6 = CPtrList::Find(this: &this->m_lstDockBarRows, searchValue: pRowToResize, startAfter: nullptr);
    if ( v6 == nullptr )
      AfxThrowInvalidArgException();
    pNext = v6->pNext;
    while ( pNext != nullptr )
    {
      data = pNext->data;
      pNext = pNext->pNext;
      data->__vftable[4].Serialize(this: data, a2: (CArchive *)v4);
    }
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103D7DF8
// Name: public: void CDockSite::SwapRows(class CDockingPanesRow __near *,class CDockingPanesRow __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockSite::SwapRows(CDockSite *this, CDockingPanesRow *pFirstRow, CDockingPanesRow *pSecondRow)
{
  CObList *p_m_lstDockBarRows; // esi
  __POSITION *v4; // edi
  CObList::CNode *v5; // eax
  __POSITION *v6; // ebx
  int m_nRowHeight; // eax
  int v8; // eax
  __POSITION *posTmp; // [esp+10h] [ebp-8h] BYREF
  bool bSwapDown; // [esp+17h] [ebp-1h]

  p_m_lstDockBarRows = &this->m_lstDockBarRows;
  v4 = (__POSITION *)CPtrList::Find(this: &this->m_lstDockBarRows, searchValue: pFirstRow, startAfter: nullptr);
  v5 = CPtrList::Find(this: p_m_lstDockBarRows, searchValue: pSecondRow, startAfter: nullptr);
  v6 = (__POSITION *)v5;
  if ( v4 == nullptr || v5 == nullptr )
    AfxThrowInvalidArgException();
  posTmp = v4;
  CDockSite::FindNextVisibleRow(this, pos: &posTmp, bForward: 1);
  bSwapDown = posTmp == v6;
  if ( posTmp == v6 || (posTmp = v4, CDockSite::FindNextVisibleRow(this, pos: &posTmp, bForward: 0), posTmp == v6) )
  {
    CObList::InsertAfter(this: p_m_lstDockBarRows, position: v4, newElement: pSecondRow);
    CObList::InsertAfter(this: p_m_lstDockBarRows, position: v6, newElement: pFirstRow);
    CPtrList::RemoveAt(this: p_m_lstDockBarRows, position: v4);
    CPtrList::RemoveAt(this: p_m_lstDockBarRows, position: v6);
    m_nRowHeight = pFirstRow->m_nRowHeight;
    if ( bSwapDown )
      m_nRowHeight = -m_nRowHeight;
    pSecondRow->Move(this: pSecondRow, a2: m_nRowHeight);
    v8 = pSecondRow->m_nRowHeight;
    if ( !bSwapDown )
      v8 = -v8;
    pFirstRow->Move(this: pFirstRow, a2: v8);
    this->FixupVirtualRects(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D7ECD
// Name: protected: class CDockingPanesRow __near * CDockSite::RowFromPane(class CBasePane __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDockingPanesRow *__thiscall CDockSite::RowFromPane(CDockSite *this, CBasePane *pBar)
{
  CObList::CNode *m_pNodeHead; // esi
  CObject *data; // edi

  m_pNodeHead = this->m_lstDockBarRows.m_pNodeHead;
  do
  {
    if ( m_pNodeHead == nullptr )
      return nullptr;
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
  }
  while ( CPtrList::Find(this: (CObList *)&data[9], searchValue: pBar, startAfter: nullptr) == nullptr );
  return (CDockingPanesRow *)data;
}

//------------------------------------------------------------------------------
// Address: 0x103D7F0D
// Name: public: virtual int CDockSite::ShowPane(class CBasePane __near *,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockSite::ShowPane(CDockSite *this, CBasePane *pBar, int bShow, int bDelay, int __formal)
{
  CDockingPanesRow *v5; // esi
  CObject *v6; // eax

  v5 = CDockSite::RowFromPane(this, pBar);
  if ( v5 != nullptr && (v6 = AfxDynamicDownCast(pClass: &CPane::classCPane, pObject: pBar)) != nullptr )
    return v5->ShowPane(this: v5, a2: (CPane *)v6, a3: bShow, a4: bDelay);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103D7F4B
// Name: protected: void CDockSite::OnPaint(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockSite::OnPaint(CDockablePane *this)
{
  CPaintDC dc; // [esp+0h] [ebp-58h] BYREF

  CPaintDC::CPaintDC(this: &dc, pWnd: &this->CPane);
  CPaintDC::~CPaintDC(this: &dc);
}

//------------------------------------------------------------------------------
// Address: 0x103D7F7A
// Name: public: virtual int CDockSite::CanAcceptPane(class CBasePane const __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CDockSite::CanAcceptPane(CDockSite *this, const CBasePane *pBar)
{
  return pBar != nullptr && this->IsResizable(this) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x103D7F9A
// Name: public: virtual int CDockSite::OnSetWindowPos(class CWnd const __near *,class CRect const __near &,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CDockSite::OnSetWindowPos(
        CDockSite *this,
        const CWnd *pWndInsertAfter,
        const CRect *rectWnd,
        unsigned int nFlags)
{
  return this->SetWindowPos(
           this,
           a2: pWndInsertAfter,
           a3: rectWnd->left,
           a4: rectWnd->top,
           a5: rectWnd->right - rectWnd->left,
           a6: rectWnd->bottom - rectWnd->top,
           a7: nFlags | 0x10,
           a8: 0) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103D7FDE
// Name: protected: void CDockSite::OnNcDestroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockSite::OnNcDestroy(CDockSite *this)
{
  CWnd::OnNcDestroy(this);
  if ( this != nullptr )
    ((void (__thiscall *)(CDockSite *, int))this->dtr_CObject)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x103D7FF7
// Name: public: virtual void CDockSite::AdjustLayout(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockSite::AdjustLayout(CDockSite *this)
{
  CObList::CNode *m_pNodeHead; // esi
  CObject *data; // ecx

  m_pNodeHead = this->m_lstControlBars.m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    data->__vftable[43].dtr_CObject(this: data);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D8021
// Name: public: int CDockSite::FindRowIndex(class CDockingPanesRow __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockSite::FindRowIndex(CDockSite *this, CDockingPanesRow *pRow)
{
  int result; // eax
  CObList::CNode *m_pNodeHead; // ecx
  CObList::CNode *v4; // edx

  result = 0;
  if ( pRow != nullptr )
  {
    m_pNodeHead = this->m_lstDockBarRows.m_pNodeHead;
    while ( m_pNodeHead != nullptr )
    {
      v4 = m_pNodeHead;
      m_pNodeHead = m_pNodeHead->pNext;
      if ( v4->data == pRow )
        return result;
      ++result;
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103D8057
// Name: protected: void CDockSite::OnContextMenu(class CWnd __near *,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockSite::OnContextMenu(CDockSite *this, CWnd *__formal, CPoint point)
{
  CFrameWnd *TopLevelFrame; // eax

  if ( CMFCPopupMenu::m_pActivePopupMenu == nullptr && CMFCToolBar::m_bCustomizeMode == 0 && this->IsDragMode(this) == 0 )
  {
    TopLevelFrame = (CFrameWnd *)g_pTopLevelFrame;
    if ( g_pTopLevelFrame != nullptr || (TopLevelFrame = CWnd::GetTopLevelFrame(this)) != nullptr )
      ((void (__thiscall *)(CDockSite *, CFrameWnd *, int, int))this->OnPaneContextMenu)(
        a1: this,
        a2: TopLevelFrame,
        a3: point.x,
        a4: point.y);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D80A7
// Name: public: virtual int CDockSite::IsDragMode(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockSite::IsDragMode(CDockSite *this)
{
  CObList::CNode *m_pNodeHead; // esi
  CObject *v2; // eax
  CObject *data; // [esp-4h] [ebp-8h]

  m_pNodeHead = this->m_lstControlBars.m_pNodeHead;
  do
  {
    if ( m_pNodeHead == nullptr )
      return 0;
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    v2 = AfxDynamicDownCast(pClass: &CPane::classCPane, pObject: data);
  }
  while ( v2 == nullptr || ((int (__thiscall *)(CObject *))v2->__vftable[51].dtr_CObject)(a1: v2) == 0 );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103D80ED
// Name: public: class CPane __near * CDockSite::FindPaneByID(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPane *__thiscall CDockSite::FindPaneByID(CDockSite *this, unsigned int nID)
{
  CObList::CNode *m_pNodeHead; // esi
  CObList::CNode *v3; // eax
  CObject *data; // edi
  CWnd *v5; // eax
  CWnd *DlgItem; // eax
  CPane *result; // eax

  m_pNodeHead = this->m_lstControlBars.m_pNodeHead;
  while ( 1 )
  {
    if ( m_pNodeHead == nullptr )
      return nullptr;
    v3 = m_pNodeHead;
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( CWnd::GetDlgCtrlID(this: (CWnd *)v3->data) == nID )
      break;
    v5 = (CWnd *)AfxDynamicDownCast(pClass: &CMFCReBar::classCMFCReBar, pObject: data);
    if ( v5 != nullptr )
    {
      DlgItem = CWnd::GetDlgItem(this: v5, nID);
      result = (CPane *)AfxDynamicDownCast(pClass: &CPane::classCPane, pObject: DlgItem);
      if ( result != nullptr )
        return result;
    }
  }
  return (CPane *)data;
}

//------------------------------------------------------------------------------
// Address: 0x103D8154
// Name: protected: void CDockSite::OnDestroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockSite::OnDestroy(CDockSite *this)
{
  CBasePane::RemovePaneFromDockManager(
    this,
    pBar: this,
    bDestroy: 0,
    bAdjustLayout: 0,
    bAutoHide: 0,
    pBarReplacement: nullptr);
  CWnd::OnDestroy(this);
}

//------------------------------------------------------------------------------
// Address: 0x103D816D
// Name: public: static class CObject __near * CDockSite::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDockSite *__stdcall CDockSite::CreateObject()
{
  CDockSite *v0; // ecx
  CDockSite *result; // eax

  v0 = (CDockSite *)operator new(nSize: 0x13Cu);
  result = nullptr;
  if ( v0 != nullptr )
    return CDockSite::CDockSite(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103D81BE
// Name: public: virtual int CDockSite::DockPaneLeftOf(class CPane __near *,class CPane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockSite::DockPaneLeftOf(CDockSite *this, CPane *pBarToDock, CPane *pTargetBar)
{
  CDockingPanesRow *v4; // edi
  int result; // eax
  int v6; // eax
  CDockingPanesRow_vtbl *v7; // eax
  __POSITION *v8; // eax
  CSize szBarSize; // [esp+10h] [ebp-30h] BYREF
  CObject *searchValue; // [esp+18h] [ebp-28h]
  CRect rectFinal; // [esp+1Ch] [ebp-24h] BYREF
  CRect rectTargetBar; // [esp+2Ch] [ebp-14h] BYREF

  searchValue = pTargetBar;
  v4 = CDockSite::RowFromPane(this, pBar: pTargetBar);
  result = 0;
  if ( v4 != nullptr )
  {
    memset(&rectTargetBar, 0, sizeof(rectTargetBar));
    GetWindowRect(hWnd: (HWND)searchValue[8].__vftable, lpRect: &rectTargetBar);
    CWnd::ScreenToClient(this, lpRect: &rectTargetBar);
    v6 = this->IsHorizontal(this);
    pBarToDock->CalcFixedLayout(this: pBarToDock, result: &szBarSize, a3: 0, a4: v6 != 0);
    memset(&rectFinal, 0, sizeof(rectFinal));
    if ( this->IsHorizontal(this) != 0 )
      SetRect(
        lprc: &rectFinal,
        xLeft: rectTargetBar.left - szBarSize.cx - 10,
        yTop: rectTargetBar.top,
        xRight: rectTargetBar.left - 10,
        yBottom: rectTargetBar.bottom);
    else
      SetRect(
        lprc: &rectFinal,
        xLeft: rectTargetBar.left,
        yTop: rectTargetBar.top - szBarSize.cy - 10,
        xRight: rectTargetBar.right,
        yBottom: rectTargetBar.top - 10);
    pBarToDock->PrepareToDock(this: pBarToDock, a2: this, a3: DM_RECT);
    CWnd::ClientToScreen(this, lpRect: &rectFinal);
    v7 = v4->__vftable;
    v4->m_bIgnoreBarVisibility = 1;
    v7->AddPane(this: v4, a2: pBarToDock, a3: DM_RECT, a4: &rectFinal, a5: 0);
    v8 = (__POSITION *)CPtrList::Find(this: &this->m_lstControlBars, searchValue, startAfter: nullptr);
    if ( v8 == nullptr )
      AfxThrowInvalidArgException();
    CObList::InsertBefore(this: &this->m_lstControlBars, position: v8, newElement: pBarToDock);
    this->AdjustDockingLayout(this);
    this->FixupVirtualRects(this);
    v4->m_bIgnoreBarVisibility = 0;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103D830E
// Name: public: virtual void CDockSite::RepositionPanes(class CRect __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockSite::RepositionPanes(CDockSite *this, CRect *rectNewClientArea)
{
  int v4; // eax
  int v5; // ecx
  int v6; // edi
  CObList::CNode *v7; // ebx
  __POSITION *pNext; // ecx
  CObject *v9; // ebx
  CObject_vtbl *v10; // edi
  int v11; // eax
  CObject_vtbl *v12; // edi
  int v13; // eax
  CObList::CNode *m_pNodeHead; // ebx
  CDockingPanesRow *data; // ecx
  __POSITION *pos; // [esp+Ch] [ebp-20h]
  int nHorzOffset; // [esp+10h] [ebp-1Ch]
  int nVertOffset; // [esp+14h] [ebp-18h]
  CRect rectOldArea; // [esp+18h] [ebp-14h] BYREF

  memset(&rectOldArea, 0, sizeof(rectOldArea));
  GetClientRect(hWnd: this->m_hWnd, lpRect: &rectOldArea);
  v4 = rectNewClientArea->right - rectNewClientArea->left;
  v5 = rectNewClientArea->bottom - rectNewClientArea->top;
  v6 = rectOldArea.bottom - rectOldArea.top;
  if ( v4 == rectOldArea.right - rectOldArea.left && v5 == v6 )
  {
    m_pNodeHead = this->m_lstDockBarRows.m_pNodeHead;
    while ( m_pNodeHead != nullptr )
    {
      data = (CDockingPanesRow *)m_pNodeHead->data;
      m_pNodeHead = m_pNodeHead->pNext;
      CDockingPanesRow::ExpandStretchedPanesRect(this: data);
    }
  }
  else
  {
    v7 = this->m_lstDockBarRows.m_pNodeHead;
    nHorzOffset = v4 - (rectOldArea.right - rectOldArea.left);
    nVertOffset = v5 - v6;
    if ( v7 != nullptr )
    {
      while ( 1 )
      {
        pNext = (__POSITION *)v7->pNext;
        v9 = v7->data;
        pos = pNext;
        if ( nHorzOffset != 0 )
        {
          v10 = v9->__vftable;
          v11 = abs(lnumber: nHorzOffset);
          ((void (__thiscall *)(CObject *, CRect *, int, bool, int))v10[5].GetRuntimeClass)(
            a1: v9,
            a2: rectNewClientArea,
            a3: 2,
            a4: nHorzOffset > 0,
            a5: v11);
        }
        if ( nVertOffset != 0 )
        {
          v12 = v9->__vftable;
          v13 = abs(lnumber: nVertOffset);
          ((void (__thiscall *)(CObject *, CRect *, int, bool, int))v12[5].GetRuntimeClass)(
            a1: v9,
            a2: rectNewClientArea,
            a3: 6,
            a4: nVertOffset > 0,
            a5: v13);
        }
        if ( pos == nullptr )
          break;
        v7 = (CObList::CNode *)pos;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D840D
// Name: protected: class CDockingPanesRow __near * CDockSite::RowFromPoint(class CPoint,bool __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDockingPanesRow *__thiscall CDockSite::RowFromPoint(CDockSite *this, CPoint pt, bool *bOuterRow)
{
  CObList::CNode *m_pNodeHead; // esi
  CDockingPanesRow *data; // ecx
  HWND__ *m_hWnd; // [esp-8h] [ebp-40h]
  CDockingPanesRow *pRow; // [esp+10h] [ebp-28h]
  CRect rectRow; // [esp+14h] [ebp-24h] BYREF
  CRect rectWnd; // [esp+24h] [ebp-14h] BYREF

  *bOuterRow = false;
  m_pNodeHead = this->m_lstDockBarRows.m_pNodeHead;
  memset(&rectRow, 0, sizeof(rectRow));
  while ( m_pNodeHead != nullptr )
  {
    data = (CDockingPanesRow *)m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    pRow = data;
    if ( ((int (__fastcall *)(CDockingPanesRow *))data->IsVisible)(a1: data) != 0 )
    {
      CDockingPanesRow::GetWindowRect(this: pRow, rect: &rectRow);
      if ( PtInRect(lprc: &rectRow, pt: pt.tagPOINT) )
        return pRow;
    }
  }
  m_hWnd = this->m_hWnd;
  memset(&rectWnd, 0, sizeof(rectWnd));
  GetWindowRect(hWnd: m_hWnd, lpRect: &rectWnd);
  if ( this->IsHorizontal(this) != 0 && pt.y < rectWnd.top || this->IsHorizontal(this) == 0 && pt.x < rectWnd.left )
    *bOuterRow = true;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103D84E9
// Name: protected: void CDockSite::ResizeDockSiteByOffset(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockSite::ResizeDockSiteByOffset(CDockSite *this, int nOffset, int bAdjustLayout)
{
  HWND Parent; // eax
  CWnd *v5; // eax
  unsigned int v6; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-24h]
  CRect rect; // [esp+8h] [ebp-14h] BYREF

  m_hWnd = this->m_hWnd;
  memset(&rect, 0, sizeof(rect));
  GetWindowRect(hWnd: m_hWnd, lpRect: &rect);
  Parent = GetParent(hWnd: this->m_hWnd);
  v5 = CWnd::FromHandle(hWnd: Parent);
  CWnd::ScreenToClient(this: v5, lpRect: &rect);
  v6 = this->GetCurrentAlignment(this);
  switch ( v6 )
  {
    case 0x1000u:
      rect.right += nOffset;
      break;
    case 0x2000u:
      rect.bottom += nOffset;
      break;
    case 0x4000u:
      rect.left -= nOffset;
      break;
    case 0x8000u:
      rect.top -= nOffset;
      break;
    default:
      break;
  }
  this->MoveWindow(this, a2: &rect, a3: 1, a4: nullptr);
  if ( bAdjustLayout != 0 )
    this->AdjustDockingLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x103D85A8
// Name: public: virtual class CPane __near * CDockSite::PaneFromPoint(class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPane *__thiscall CDockSite::PaneFromPoint(CDockSite *this, CPoint pt)
{
  CObList::CNode *m_pNodeHead; // esi
  CObject *data; // edi
  CRect rectBar; // [esp+8h] [ebp-14h] BYREF

  memset(&rectBar, 0, sizeof(rectBar));
  m_pNodeHead = this->m_lstControlBars.m_pNodeHead;
  do
  {
    if ( m_pNodeHead == nullptr )
      return nullptr;
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    GetWindowRect(hWnd: (HWND)data[8].__vftable, lpRect: &rectBar);
  }
  while ( !PtInRect(lprc: &rectBar, pt: pt.tagPOINT) );
  return (CPane *)data;
}

//------------------------------------------------------------------------------
// Address: 0x103D861F
// Name: protected: int CDockSite::OnEraseBkgnd(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockSite::OnEraseBkgnd(CDockSite *this, CDC *pDC)
{
  CMFCVisualManager *Instance; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-2Ch]
  CRect rect; // [esp+10h] [ebp-14h] BYREF

  m_hWnd = this->m_hWnd;
  memset(&rect, 0, sizeof(rect));
  GetClientRect(hWnd: m_hWnd, lpRect: &rect);
  Instance = CMFCVisualManager::GetInstance();
  ((void (__thiscall *)(CMFCVisualManager *, CDC *, CDockSite *, int, int, int, int, int, int, int, int, _DWORD))Instance->OnFillBarBackground)(
    a1: Instance,
    a2: pDC,
    a3: this,
    a4: rect.left,
    a5: rect.top,
    a6: rect.right,
    a7: rect.bottom,
    a8: rect.left,
    a9: rect.top,
    a10: rect.right,
    a11: rect.bottom,
    a12: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103D8694
// Name: public: virtual void CDockSite::AdjustDockingLayout(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockSite::AdjustDockingLayout(CDockSite *this)
{
  HWND Parent; // eax
  CWnd *v2; // esi
  int IsKindOf; // eax
  CWnd *v4; // ecx
  int v5; // eax
  CWnd *v6; // ecx
  int v7; // eax
  int v8; // eax
  CWnd *MainWnd; // eax

  Parent = GetParent(hWnd: this->m_hWnd);
  v2 = CWnd::FromHandle(hWnd: Parent);
  if ( CObject::IsKindOf(this: v2, pClass: &CFrameWndEx::classCFrameWndEx) != 0 )
  {
    ((void (__thiscall *)(CWnd *, _DWORD))v2->__vftable[1].CreateEx)(a1: v2, a2: 0);
    return;
  }
  IsKindOf = CObject::IsKindOf(this: v2, pClass: &CMDIFrameWndEx::classCMDIFrameWndEx);
  v4 = v2;
  if ( IsKindOf != 0 )
    goto LABEL_10;
  v5 = CObject::IsKindOf(this: v2, pClass: &COleIPFrameWndEx::classCOleIPFrameWndEx);
  v6 = v2;
  if ( v5 != 0
    || (v7 = CObject::IsKindOf(this: v2, pClass: &COleDocIPFrameWndEx::classCOleDocIPFrameWndEx), v6 = v2, v7 != 0) )
  {
    ((void (__thiscall *)(CWnd *, _DWORD))v2->__vftable[1].WinHelpA)(a1: v6, a2: 0);
    return;
  }
  if ( CObject::IsKindOf(this: v2, pClass: &COleCntrFrameWndEx::classCOleCntrFrameWndEx) != 0 )
  {
    ((void (__thiscall *)(CWnd *, _DWORD))v2->__vftable[1].CreateEx_2)(a1: v2, a2: 0);
    return;
  }
  v8 = CObject::IsKindOf(this: v2, pClass: &CMDIChildWndEx::classCMDIChildWndEx);
  v4 = v2;
  if ( v8 != 0 )
  {
LABEL_10:
    ((void (__thiscall *)(CWnd *, _DWORD))v2->__vftable[1].DestroyWindow)(a1: v4, a2: 0);
  }
  else if ( CObject::IsKindOf(this: v2, pClass: &CDialog::classCDialog) != 0 )
  {
    if ( v2 != nullptr )
      v2 = (CWnd *)v2->m_hWnd;
    MainWnd = AfxGetMainWnd();
    if ( MainWnd != nullptr )
      MainWnd = (CWnd *)MainWnd->m_hWnd;
    if ( v2 == MainWnd )
      afxGlobalUtils.m_bDialogApp = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D876B
// Name: protected: class CDockingPanesRow __near * CDockSite::FindRowByRect(class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDockingPanesRow *__thiscall CDockSite::FindRowByRect(CDockSite *this, CRect rectRow)
{
  CPoint pt; // [esp+4h] [ebp-Ch] BYREF
  bool b; // [esp+Fh] [ebp-1h] BYREF

  pt = *(CPoint *)&rectRow.left;
  ClientToScreen(hWnd: this->m_hWnd, lpPoint: &pt);
  return CDockSite::RowFromPoint(this, pt, bOuterRow: &b);
}

//------------------------------------------------------------------------------
// Address: 0x103D87A5
// Name: public: class CDockingPanesRow __near * CDockSite::AddRow(struct __POSITION __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDockingPanesRow *__thiscall CDockSite::AddRow(CDockSite *this, __POSITION *posRowBefore, int nRowHeight)
{
  CObList::CNode *m_pNodeHead; // edi
  CObject *data; // ebx
  CDockingPanesRow *result; // eax
  CDockingPanesRow *v7; // edi
  CObList *p_m_lstDockBarRows; // ecx
  __POSITION *v9; // eax
  int nOffset; // [esp+8h] [ebp-4h]

  nOffset = 0;
  m_pNodeHead = this->m_lstDockBarRows.m_pNodeHead;
  while ( m_pNodeHead != (CObList::CNode *)posRowBefore )
  {
    if ( m_pNodeHead == nullptr )
      AfxThrowInvalidArgException();
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( ((int (__thiscall *)(CObject *))data->__vftable[7].dtr_CObject)(a1: data) != 0 )
      nOffset += (int)data[3].__vftable;
  }
  CDockSite::ResizeDockSiteByOffset(this, nOffset: nRowHeight, bAdjustLayout: 1);
  result = this->CreateRow(this, a2: this, a3: nOffset, a4: nRowHeight);
  v7 = result;
  if ( result != nullptr )
  {
    p_m_lstDockBarRows = &this->m_lstDockBarRows;
    if ( posRowBefore != nullptr )
    {
      v9 = (__POSITION *)CObList::InsertBefore(this: p_m_lstDockBarRows, position: posRowBefore, newElement: result);
      this->OnInsertRow(this, a2: v9);
    }
    else
    {
      CPtrList::AddTail(this: p_m_lstDockBarRows, newElement: result);
    }
    return v7;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103D883A
// Name: public: void CDockSite::RemoveRow(class CDockingPanesRow __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockSite::RemoveRow(CDockSite *this, __POSITION *pRow)
{
  int v3; // ebx
  __POSITION *v5; // eax
  __POSITION *pos; // [esp+14h] [ebp+8h]

  v3 = *(_DWORD *)&pRow[12];
  if ( (*(int (__thiscall **)(__POSITION *))(*(_DWORD *)pRow + 88))(a1: pRow) != 0 )
    CDockSite::ResizeDockSiteByOffset(this, nOffset: -v3, bAdjustLayout: 1);
  v5 = (__POSITION *)CPtrList::Find(this: &this->m_lstDockBarRows, searchValue: (CObject *)pRow, startAfter: nullptr);
  pos = v5;
  if ( v5 != nullptr )
  {
    this->OnRemoveRow(this, a2: v5, a3: 0);
    CPtrList::RemoveAt(this: &this->m_lstDockBarRows, position: pos);
    (*(void (__thiscall **)(__POSITION *, int))(*(_DWORD *)pRow + 4))(a1: pRow, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D88A1
// Name: public: int CDockSite::ResizeRow(class CDockingPanesRow __near *,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockSite::ResizeRow(CDockSite *this, CDockingPanesRow *pRow, int nNewSize, int bAdjustLayout)
{
  int v5; // ebx
  int v7; // eax
  int v9; // edi
  CSize size; // [esp+Ch] [ebp-8h] BYREF
  CDockingPanesRow *pRowa; // [esp+1Ch] [ebp+8h]

  v5 = nNewSize - pRow->m_nRowHeight;
  if ( v5 < 0 && pRow->IsEmpty(this: pRow) == 0 )
  {
    pRowa = (CDockingPanesRow *)pRow->__vftable;
    v7 = this->IsHorizontal(this);
    ((void (__thiscall *)(CDockingPanesRow *, CSize *, int, int))pRowa->m_nRowOffset)(
      a1: pRow,
      a2: &size,
      a3: 1,
      a4: v7);
    if ( this->IsHorizontal(this) != 0 && nNewSize - size.cy < 0 )
      return 0;
    if ( this->IsHorizontal(this) == 0 && nNewSize - size.cx < 0 )
      return 0;
  }
  v9 = this->OnResizeRow(this, a2: pRow, a3: v5);
  CDockSite::ResizeDockSiteByOffset(this, nOffset: v9, bAdjustLayout);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x103D8933
// Name: public: void CDockSite::ShowRow(class CDockingPanesRow __near *,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockSite::ShowRow(CDockSite *this, CDockingPanesRow *pRow, int bShow, int bAdjustLayout)
{
  __POSITION *v5; // eax
  int m_nRowHeight; // eax

  v5 = (__POSITION *)CPtrList::Find(this: &this->m_lstDockBarRows, searchValue: pRow, startAfter: nullptr);
  this->OnShowRow(this, a2: v5, a3: bShow);
  m_nRowHeight = pRow->m_nRowHeight;
  if ( bShow == 0 )
    m_nRowHeight = -m_nRowHeight;
  CDockSite::ResizeDockSiteByOffset(this, nOffset: m_nRowHeight, bAdjustLayout);
}

//------------------------------------------------------------------------------
// Address: 0x103D8977
// Name: public: virtual class CSize CDockSite::CalcFixedLayout(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CDockSite::CalcFixedLayout(CDockSite *this, CSize *result, int bStretch, int bHorz)
{
  CSize *v4; // esi
  CDockSite_vtbl *v6; // eax
  int v7; // eax
  CObList::CNode *m_pNodeHead; // ebx
  CDockingPanesRow *data; // esi
  int cy; // eax
  CSize sizeRowRequired; // [esp+Ch] [ebp-28h] BYREF
  int bHorzBar; // [esp+14h] [ebp-20h]
  int nCurrHeight; // [esp+18h] [ebp-1Ch]
  CSize *v15; // [esp+1Ch] [ebp-18h]
  CRect rectWnd; // [esp+20h] [ebp-14h] BYREF

  v4 = result;
  v6 = this->__vftable;
  v15 = result;
  v7 = v6->IsHorizontal(this);
  m_pNodeHead = this->m_lstDockBarRows.m_pNodeHead;
  bHorzBar = v7;
  if ( m_pNodeHead != nullptr )
  {
    do
    {
      data = (CDockingPanesRow *)m_pNodeHead->data;
      m_pNodeHead = m_pNodeHead->pNext;
      if ( data->IsVisible(this: data) != 0 )
      {
        nCurrHeight = data->m_nRowHeight;
        data->CalcFixedLayout(this: data, result: &sizeRowRequired, a3: bStretch, a4: bHorz);
        cy = sizeRowRequired.cy;
        if ( bHorzBar == 0 )
          cy = sizeRowRequired.cx;
        if ( cy != nCurrHeight && cy > 0 )
          CDockSite::ResizeRow(this, pRow: data, nNewSize: cy, bAdjustLayout: 0);
      }
    }
    while ( m_pNodeHead != nullptr );
    v4 = v15;
  }
  memset(&rectWnd, 0, sizeof(rectWnd));
  GetWindowRect(hWnd: this->m_hWnd, lpRect: &rectWnd);
  v4->cx = rectWnd.right - rectWnd.left;
  v4->cy = rectWnd.bottom - rectWnd.top;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x103D8A46
// Name: protected: static struct AFX_MSGMAP const __near * CDockSite::GetThisMessageMap(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CDockSite::GetThisMessageMap(CDockSite *this)
{
  return &messageMap_38;
}

//------------------------------------------------------------------------------
// Address: 0x103D8A4C
// Name: public: virtual int CDockSite::CreateEx(unsigned long,unsigned long,struct tagRECT const __near &,class CWnd __near *,unsigned long,struct CCreateContext __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockSite::CreateEx(
        CDockSite *this,
        unsigned int dwStyleEx,
        unsigned int dwStyle,
        const tagRECT *rect,
        CWnd *pParentWnd,
        unsigned int dwControlBarStyle,
        CCreateContext *pContext)
{
  unsigned int v8; // eax
  CDockSite_vtbl *v9; // eax
  int v10; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v11; // eax
  int v12; // esi
  const char *m_pszData; // [esp-1Ch] [ebp-68h]
  unsigned int m_nDockBarID; // [esp-8h] [ebp-54h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v16; // [esp+18h] [ebp-34h] BYREF
  tagRECT rcDst; // [esp+1Ch] [ebp-30h] BYREF
  tagRECT Rect; // [esp+2Ch] [ebp-20h] BYREF
  int v19; // [esp+48h] [ebp-4h]
  unsigned int dwStylea; // [esp+58h] [ebp+Ch]

  v8 = this->GetEnabledAlignment(this);
  this->EnableDocking(this, a2: dwStyle | v8);
  this->SetPaneAlignment(this, a2: dwStyle);
  dwStylea = dwStyle | 0x46000000;
  CopyRect(lprcDst: &rcDst, lprcSrc: rect);
  memset(&Rect, 0, sizeof(Rect));
  GetClientRect(hWnd: pParentWnd->m_hWnd, lpRect: &Rect);
  v9 = this->__vftable;
  rcDst = Rect;
  v10 = v9->GetCurrentAlignment(this);
  switch ( v10 )
  {
    case 0x1000:
      rcDst.right = 0;
      this->m_nDockBarID = 59420;
      break;
    case 0x2000:
      rcDst.bottom = Rect.top;
      this->m_nDockBarID = 59419;
      break;
    case 0x4000:
      rcDst.left = Rect.right;
      this->m_nDockBarID = 59421;
      break;
    case 0x8000:
      rcDst.top = Rect.bottom;
      this->m_nDockBarID = 59422;
      break;
    default:
      break;
  }
  this->m_dwControlBarStyle = dwControlBarStyle;
  this->m_pDockSite = pParentWnd;
  v11 = AFX_GLOBAL_DATA::RegisterWindowClass(this: &afxGlobalData, result: &v16, lpszClassNamePrefix: "Afx:DockPane");
  m_nDockBarID = this->m_nDockBarID;
  m_pszData = v11->m_pszData;
  v19 = 0;
  v12 = CWnd::CreateEx(
          this,
          dwExStyle: 0,
          lpszClassName: m_pszData,
          lpszWindowName: nullptr,
          dwStyle: dwStylea,
          rect: &rcDst,
          pParentWnd,
          nID: m_nDockBarID,
          lpParam: pContext);
  ATL::CStringData::Release(this: (ATL::CStringData *)v16.m_pszData - 1);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x103D8B8B
// Name: public: virtual int CDockSite::MovePane(class CPane __near *,unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockSite::MovePane(CDockSite *this, CPane *pControlBar, unsigned int __formal, CPoint ptOffset)
{
  CDockingPanesRow *m_pDockBarRow; // edi
  CPane_vtbl *v6; // eax
  CPane *v7; // ebx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  CDockingPanesRow *v12; // eax
  int v13; // esi
  CPoint v14; // [esp-Ch] [ebp-5Ch]
  CDockingPanesRow *v15; // [esp-8h] [ebp-58h]
  CDockingPanesRow *v16; // [esp-4h] [ebp-54h]
  CPoint ptMouse; // [esp+Ch] [ebp-44h] BYREF
  CBasePane *pDockBar; // [esp+14h] [ebp-3Ch] BYREF
  CDockingPanesRow *pNextRow; // [esp+18h] [ebp-38h]
  int nBaseLineOffset; // [esp+1Ch] [ebp-34h]
  bool bOuterRow; // [esp+23h] [ebp-2Dh] BYREF
  CPane *v22; // [esp+24h] [ebp-2Ch]
  void *hdwp; // [esp+28h] [ebp-28h] BYREF
  CRect rectRow; // [esp+2Ch] [ebp-24h] BYREF
  CRect rectVirtual; // [esp+3Ch] [ebp-14h] BYREF

  m_pDockBarRow = pControlBar->m_pDockBarRow;
  v22 = pControlBar;
  memset(&rectVirtual, 0, sizeof(rectVirtual));
  CPane::GetVirtualRect(this: pControlBar, &rectVirtual);
  OffsetRect(lprc: &rectVirtual, dx: ptOffset.x, dy: ptOffset.y);
  ptMouse.x = 0;
  ptMouse.y = 0;
  GetCursorPos(lpPoint: &ptMouse);
  memset(&rectRow, 0, sizeof(rectRow));
  CDockingPanesRow::GetWindowRect(this: m_pDockBarRow, rect: &rectRow);
  v6 = v22->__vftable;
  pDockBar = nullptr;
  if ( v6->IsChangeState(this: v22, a2: 15, a3: &pDockBar) != CS_NOTHING )
  {
    v7 = v22;
    CPane::UpdateVirtualRect(this: v22, ptOffset);
    CPane::GetVirtualRect(this: v7, &rectVirtual);
    ((void (__thiscall *)(CPane *, int, int, int, int, int, int))v7->FloatPane)(
      a1: v7,
      a2: rectVirtual.left,
      a3: rectVirtual.top,
      a4: rectVirtual.right,
      a5: rectVirtual.bottom,
      a6: 1,
      a7: 1);
    return 1;
  }
  bOuterRow = false;
  v14.y = (rectVirtual.top + rectVirtual.bottom) / 2;
  v14.x = (rectVirtual.left + rectVirtual.right) / 2;
  pNextRow = CDockSite::RowFromPoint(this, pt: v14, &bOuterRow);
  if ( this->IsHorizontal(this) != 0 )
  {
    nBaseLineOffset = rectRow.bottom - rectVirtual.bottom;
    if ( rectRow.bottom - rectVirtual.bottom >= rectRow.top - rectVirtual.top )
      nBaseLineOffset = rectRow.top - rectVirtual.top;
    v9 = rectVirtual.bottom - rectVirtual.top;
  }
  else
  {
    nBaseLineOffset = rectRow.right - rectVirtual.right;
    if ( rectRow.right - rectVirtual.right >= rectRow.left - rectVirtual.left )
      nBaseLineOffset = rectRow.left - rectVirtual.left;
    v9 = rectVirtual.right - rectVirtual.left;
  }
  hdwp = (void *)(2 * v9 / 3);
  v10 = abs(lnumber: nBaseLineOffset);
  if ( v10 > (int)hdwp )
  {
    if ( m_pDockBarRow->m_lstControlBars.m_nCount > 1 && nBaseLineOffset < m_pDockBarRow->m_nRowHeight )
    {
      hdwp = CPtrList::Find(this: &this->m_lstDockBarRows, searchValue: m_pDockBarRow, startAfter: nullptr);
      if ( hdwp == nullptr )
        AfxThrowInvalidArgException();
      if ( nBaseLineOffset < 0 )
        CDockSite::FindNextVisibleRow(this, pos: (__POSITION **)&hdwp, bForward: 1);
      m_pDockBarRow->RemovePane(this: m_pDockBarRow, a2: v22);
      if ( this->IsHorizontal(this) != 0 )
        v11 = rectVirtual.bottom - rectVirtual.top;
      else
        v11 = rectVirtual.right - rectVirtual.left;
      v12 = CDockSite::AddRow(this, posRowBefore: (__POSITION *)hdwp, nRowHeight: v11);
      v12->AddPaneFromRow(this: v12, a2: v22, a3: DM_MOUSE);
      return 0;
    }
    if ( m_pDockBarRow != pNextRow && pNextRow != nullptr )
    {
      SendMessageA(hWnd: this->m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
      if ( m_pDockBarRow->IsExclusiveRow(this: m_pDockBarRow) != 0 )
      {
        v16 = m_pDockBarRow;
        v15 = pNextRow;
      }
      else
      {
        if ( pNextRow->IsExclusiveRow(this: pNextRow) == 0 )
        {
          m_pDockBarRow->RemovePane(this: m_pDockBarRow, a2: v22);
          pNextRow->AddPaneFromRow(this: pNextRow, a2: v22, a3: DM_MOUSE);
          goto LABEL_29;
        }
        v16 = pNextRow;
        v15 = m_pDockBarRow;
      }
      CDockSite::SwapRows(this, pFirstRow: v15, pSecondRow: v16);
LABEL_29:
      v22->m_bDisableMove = true;
      SendMessageA(hWnd: this->m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
      RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x185u);
      return 0;
    }
  }
  v13 = rectRow.bottom - rectRow.top;
  if ( abs(lnumber: nBaseLineOffset) < v13 )
  {
    hdwp = BeginDeferWindowPos(nNumWindows: m_pDockBarRow->m_lstControlBars.m_nCount);
    CDockingPanesRow::MovePane(this: m_pDockBarRow, pControlBar: v22, ptOffset, bSwapControlBars: 1, &hdwp);
    EndDeferWindowPos(hWinPosInfo: hdwp);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103D8E2F
// Name: public: virtual void CDockSite::DockPane(class CPane __near *,enum AFX_DOCK_METHOD,struct tagRECT const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockSite::DockPane(
        CDockSite *this,
        CPane *pControlBar,
        AFX_DOCK_METHOD dockMethod,
        const tagRECT *lpRect)
{
  CPane *v4; // esi
  int v6; // eax
  CDockingPanesRow *data; // ebx
  CDockSite *v8; // esi
  CDockSite *v9; // edi
  CObject *v10; // esi
  int m_nCount; // ebx
  int v12; // eax
  int v13; // eax
  CObject_vtbl *v14; // eax
  __POSITION *Index; // eax
  __POSITION *v16; // eax
  CDockingPanesRow *RowByRect; // eax
  int v18; // eax
  __POSITION *m_pNodeHead; // eax
  int cy; // ecx
  int cx; // eax
  CRect v22; // [esp-10h] [ebp-70h] BYREF
  CSize sizeBarNew; // [esp+Ch] [ebp-54h] BYREF
  CPoint ptMouse; // [esp+14h] [ebp-4Ch] BYREF
  BOOL v25; // [esp+1Ch] [ebp-44h]
  CSize szBarSize; // [esp+20h] [ebp-40h] BYREF
  int bVertDock; // [esp+28h] [ebp-38h]
  CDockSite *v28; // [esp+2Ch] [ebp-34h]
  CObject *newElement; // [esp+30h] [ebp-30h]
  int i; // [esp+34h] [ebp-2Ch]
  bool bOuterRow; // [esp+3Bh] [ebp-25h] BYREF
  CRect rectDockArea; // [esp+3Ch] [ebp-24h] BYREF
  CRect rectDockBar; // [esp+4Ch] [ebp-14h] BYREF

  v4 = pControlBar;
  i = (int)lpRect;
  v28 = this;
  newElement = pControlBar;
  memset(&rectDockArea, 0, sizeof(rectDockArea));
  SetRectEmpty(lprc: &rectDockArea);
  if ( lpRect != nullptr )
  {
    CopyRect(lprcDst: &rectDockBar, lprcSrc: (const RECT *)i);
    rectDockArea = rectDockBar;
    v4 = (CPane *)newElement;
  }
  v6 = this->IsHorizontal(this);
  bVertDock = v6 == 0;
  v25 = v6 != 0;
  v4->CalcFixedLayout(this: v4, result: &szBarSize, a3: 0, a4: v25);
  if ( CPtrList::Find(this: &this->m_lstControlBars, searchValue: v4, startAfter: nullptr) == nullptr )
  {
    data = nullptr;
    bOuterRow = false;
    switch ( dockMethod )
    {
      case DM_MOUSE:
        ptMouse = 0;
        GetCursorPos(lpPoint: &ptMouse);
        v8 = v28;
        v22.bottom = (int)&rectDockBar;
        v22.right = (int)v28->m_hWnd;
        memset(&rectDockBar, 0, sizeof(rectDockBar));
        GetWindowRect(hWnd: (HWND)v22.right, lpRect: &rectDockBar);
        data = CDockSite::RowFromPoint(this: v8, pt: ptMouse, &bOuterRow);
LABEL_36:
        i = 0;
        if ( data == nullptr )
          goto LABEL_47;
        if ( data->IsExclusiveRow(this: data) == 0
          && (((int (__thiscall *)(CObject *))newElement->__vftable[53].dtr_CObject)(a1: newElement) != 0
           || data->IsEmpty(this: data) != 0) )
        {
          m_pNodeHead = (__POSITION *)i;
LABEL_43:
          if ( data != nullptr )
          {
LABEL_53:
            data->AddPane(this: data, a2: (CPane *)newElement, a3: dockMethod, a4: &rectDockArea, a5: 0);
            ((void (__thiscall *)(CObject *, CSize *, _DWORD, BOOL))newElement->__vftable[50].dtr_CObject)(
              a1: newElement,
              a2: &sizeBarNew,
              a3: 0,
              a4: v25);
            cx = sizeBarNew.cx;
            if ( sizeBarNew.cx != szBarSize.cx || sizeBarNew.cy != szBarSize.cy )
            {
              if ( bVertDock == 0 )
                cx = sizeBarNew.cy;
              CDockSite::ResizeRow(this: v8, pRow: data, nNewSize: cx, bAdjustLayout: 1);
            }
            CPtrList::AddTail(this: &v8->m_lstControlBars, newElement);
            v8->AdjustDockingLayout(this: v8);
            CWnd::ShowWindow(this: v8, nCmdShow: 5);
            return;
          }
          if ( m_pNodeHead != nullptr )
          {
            if ( !bOuterRow )
              m_pNodeHead = *(__POSITION **)m_pNodeHead;
            goto LABEL_50;
          }
LABEL_47:
          if ( bOuterRow )
            m_pNodeHead = (__POSITION *)v8->m_lstDockBarRows.m_pNodeHead;
          else
            m_pNodeHead = nullptr;
LABEL_50:
          cy = szBarSize.cx;
          if ( bVertDock == 0 )
            cy = szBarSize.cy;
          data = CDockSite::AddRow(this: v8, posRowBefore: m_pNodeHead, nRowHeight: cy);
          goto LABEL_53;
        }
        m_pNodeHead = (__POSITION *)CPtrList::Find(this: &v8->m_lstDockBarRows, searchValue: data, startAfter: nullptr);
        if ( m_pNodeHead != nullptr )
        {
          data = nullptr;
          goto LABEL_43;
        }
LABEL_16:
        AfxThrowInvalidArgException();
      case DM_DBL_CLICK:
        v10 = newElement;
        v9 = v28;
        if ( CPtrList::Find(
               this: &v28->m_lstDockBarRows,
               searchValue: (CObject *)newElement[126].__vftable,
               startAfter: nullptr) != nullptr )
        {
          data = (CDockingPanesRow *)v10[126].__vftable;
          goto LABEL_34;
        }
        break;
      case DM_RECT:
        v9 = v28;
        v10 = newElement;
        break;
      default:
LABEL_35:
        v8 = v28;
        goto LABEL_36;
    }
    m_nCount = v9->m_lstDockBarRows.m_nCount;
    v12 = (int)v10[124].__vftable;
    if ( CDockingManager::m_bRestoringDockState != 0 )
    {
      if ( v12 > m_nCount - 1 )
      {
        i = 0;
        if ( v12 - m_nCount + 1 > 0 )
        {
          do
          {
            v13 = szBarSize.cx;
            if ( bVertDock == 0 )
              v13 = szBarSize.cy;
            CDockSite::AddRow(this: v9, posRowBefore: nullptr, nRowHeight: v13);
            v14 = v10[124].__vftable;
            ++i;
          }
          while ( i < (int)&v14->GetRuntimeClass - m_nCount + 1 );
        }
      }
      Index = CStringList::FindIndex(
                this: (CList<unsigned long,unsigned long> *)&v9->m_lstDockBarRows,
                nIndex: (int)v10[124].__vftable);
      if ( Index == nullptr )
        goto LABEL_16;
      data = *(CDockingPanesRow **)&Index[8];
LABEL_30:
      if ( data == nullptr )
        goto LABEL_31;
LABEL_34:
      CopyRect(lprcDst: &rectDockBar, lprcSrc: (const RECT *)&v10[130]);
      rectDockArea = rectDockBar;
      CWnd::ClientToScreen(this: v28, lpRect: &rectDockArea);
      goto LABEL_35;
    }
    if ( v12 >= m_nCount )
    {
      if ( dockMethod == DM_DBL_CLICK )
      {
        if ( !IsRectEmpty(lprc: (const RECT *)&v10[130]) )
        {
          RowByRect = CDockSite::FindRowByRect(this: v28, rectRow: *(CRect *)&v10[130].__vftable);
          v9 = v28;
          v10 = newElement;
LABEL_29:
          data = RowByRect;
          goto LABEL_30;
        }
LABEL_31:
        v18 = szBarSize.cx;
        if ( bVertDock == 0 )
          v18 = szBarSize.cy;
        CDockSite::AddRow(this: v9, posRowBefore: nullptr, nRowHeight: v18);
        data = (CDockingPanesRow *)v9->m_lstDockBarRows.m_pNodeTail->data;
        goto LABEL_34;
      }
    }
    else if ( dockMethod == DM_DBL_CLICK )
    {
      v16 = CStringList::FindIndex(this: (CList<unsigned long,unsigned long> *)&v9->m_lstDockBarRows, nIndex: v12);
      if ( v16 == nullptr )
        goto LABEL_16;
      data = *(CDockingPanesRow **)&v16[8];
      bOuterRow = true;
      goto LABEL_30;
    }
    if ( i != 0 )
    {
      CopyRect(lprcDst: &v22, lprcSrc: (const RECT *)i);
      RowByRect = CDockSite::FindRowByRect(this: v9, rectRow: v22);
      goto LABEL_29;
    }
    goto LABEL_31;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D9194
// Name: public: virtual int CDockSite::Create(unsigned long,struct tagRECT const __near &,class CWnd __near *,unsigned long,struct CCreateContext __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockSite::Create(
        CDockSite *this,
        unsigned int dwStyle,
        const tagRECT *rect,
        CWnd *pParentWnd,
        unsigned int dwControlBarStyle,
        CCreateContext *pContext)
{
  return CDockSite::CreateEx(this, dwStyleEx: 0, dwStyle, rect, pParentWnd, dwControlBarStyle, pContext);
}

//------------------------------------------------------------------------------
// Address: 0x103D91B3
// Name: protected: int CTooltipManager::CreateToolTipObject(class CToolTipCtrl __near * __near &,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CTooltipManager::CreateToolTipObject(CTooltipManager *this, CToolTipCtrl **pToolTip, unsigned int nType)
{
  CMFCToolTipInfo *v3; // esi
  CRuntimeClass *v4; // ecx
  CToolTipCtrl *v5; // ecx
  CToolTipCtrl *v6; // eax
  CObject *Object; // eax
  CMFCToolTipCtrl *v8; // eax

  if ( nType >= 0xB )
    return 0;
  v3 = &this->m_Params[nType];
  v4 = this->m_pRTC[nType];
  if ( v4 != nullptr )
  {
    Object = CRuntimeClass::CreateObject(this: v4);
    v6 = (CToolTipCtrl *)AfxDynamicDownCast(pClass: &CToolTipCtrl::classCToolTipCtrl, pObject: Object);
  }
  else
  {
    v5 = (CToolTipCtrl *)operator new(nSize: 0x90u);
    v6 = v5 != nullptr ? CToolTipCtrl::CToolTipCtrl(this: v5) : nullptr;
  }
  *pToolTip = v6;
  if ( v6 == nullptr )
    return 0;
  v8 = (CMFCToolTipCtrl *)AfxDynamicDownCast(pClass: &CMFCToolTipCtrl::classCMFCToolTipCtrl, pObject: v6);
  if ( v8 != nullptr )
    CMFCToolTipCtrl::SetParams(this: v8, pParams: v3);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103D9247
// Name: public: void CTooltipManager::UpdateTooltips(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CTooltipManager::UpdateTooltips(CTooltipManager *this)
{
  CList<HWND__ *,HWND__ *>::CNode *m_pNodeHead; // esi
  HWND data; // edi

  m_pNodeHead = this->m_lstOwners.m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( IsWindow(hWnd: data) )
      SendMessageA(hWnd: data, Msg: AFX_WM_UPDATETOOLTIPS, wParam: 0xFFFFu, lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D9280
// Name: public: static void CTooltipManager::DeleteToolTip(class CToolTipCtrl __near * __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CTooltipManager::DeleteToolTip(CToolTipCtrl **pToolTip)
{
  struct CToolTipCtrl *v1; // eax
  HWND Parent; // eax
  CWnd *v3; // eax
  HWND__ *m_hWnd; // ecx
  __POSITION *v5; // eax

  v1 = *pToolTip;
  if ( *pToolTip != nullptr )
  {
    if ( v1->m_hWnd != nullptr )
    {
      Parent = GetParent(hWnd: v1->m_hWnd);
      v3 = CWnd::FromHandle(hWnd: Parent);
      if ( v3 != nullptr )
        m_hWnd = v3->m_hWnd;
      else
        m_hWnd = nullptr;
      if ( afxTooltipManager != nullptr && m_hWnd != nullptr )
      {
        v5 = CList<unsigned int,unsigned int>::Find(
               this: &afxTooltipManager->m_lstOwners,
               searchValue: m_hWnd,
               startAfter: nullptr);
        if ( v5 != nullptr )
          CList<HWND__ *,HWND__ *>::RemoveAt(
            this: (CList<unsigned int,unsigned int> *)&afxTooltipManager->m_lstOwners,
            position: v5);
      }
      (*pToolTip)->DestroyWindow(this: *pToolTip);
    }
    if ( *pToolTip != nullptr )
      ((void (__thiscall *)(_DWORD, int))(*pToolTip)->dtr_CObject)(a1: *pToolTip, a2: 1);
    *pToolTip = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D92FC
// Name: public: static int CTooltipManager::CreateToolTip(class CToolTipCtrl __near * __near &,class CWnd __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall CTooltipManager::CreateToolTip(CToolTipCtrl **pToolTip, CWnd *pWndParent, unsigned int nType)
{
  int v3; // eax
  unsigned int v4; // ebx
  _DWORD *v6; // ecx
  CToolTipCtrl *v7; // eax
  CToolTipCtrl *v8; // eax
  HWND__ *m_hWnd; // ecx

  v3 = 1;
  v4 = 0;
  while ( v3 != nType )
  {
    v3 *= 2;
    if ( (int)++v4 >= 11 )
      return 0;
  }
  if ( v4 == -1 )
    return 0;
  v6 = *pToolTip;
  if ( *pToolTip != nullptr )
  {
    if ( v6[8] != 0 )
      (*(void (__thiscall **)(_DWORD *))(*v6 + 96))(a1: v6);
    if ( *pToolTip != nullptr )
      ((void (__thiscall *)(_DWORD, int))(*pToolTip)->dtr_CObject)(a1: *pToolTip, a2: 1);
    *pToolTip = nullptr;
  }
  if ( afxTooltipManager != nullptr )
  {
    if ( CTooltipManager::CreateToolTipObject(this: afxTooltipManager, pToolTip, nType: v4) == 0 )
      return 0;
  }
  else
  {
    v7 = (CToolTipCtrl *)operator new(nSize: 0x90u);
    v8 = v7 != nullptr ? CToolTipCtrl::CToolTipCtrl(this: v7) : nullptr;
    *pToolTip = v8;
  }
  if ( (*pToolTip)->Create_2(this: *pToolTip, a2: pWndParent, a3: 3u) == 0 )
    return 0;
  SendMessageA(hWnd: (*pToolTip)->m_hWnd, Msg: 0x401u, wParam: 1u, lParam: 0);
  if ( afxGlobalData.m_nMaxToolTipWidth != -1 )
    SendMessageA(hWnd: (*pToolTip)->m_hWnd, Msg: 0x418u, wParam: 0, lParam: afxGlobalData.m_nMaxToolTipWidth);
  if ( pWndParent != nullptr )
  {
    m_hWnd = pWndParent->m_hWnd;
    if ( m_hWnd != nullptr
      && afxTooltipManager != nullptr
      && CList<unsigned int,unsigned int>::Find(
           this: &afxTooltipManager->m_lstOwners,
           searchValue: m_hWnd,
           startAfter: nullptr) == nullptr )
    {
      CList<CFrameWnd *,CFrameWnd *>::AddTail(
        this: (CList<CFrameWnd *,CFrameWnd *> *)&afxTooltipManager->m_lstOwners,
        newElement: (CFrameWnd *)pWndParent->m_hWnd);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103D9410
// Name: public: static void CTooltipManager::SetTooltipText(struct tagTOOLINFOA __near *,class CToolTipCtrl __near *,unsigned int,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CTooltipManager::SetTooltipText(
        tagTOOLINFOA *pTI,
        CToolTipCtrl *pToolTip,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > nType,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strText,
        const char *lpszDescr)
{
  int v5; // edi
  int v6; // eax
  char *m_pszData; // esi
  const char *v8; // eax
  char *v9; // eax
  CObject *v10; // edi
  ATL::CStringData *v11; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strTipText; // [esp+10h] [ebp-10h] BYREF
  int v13; // [esp+1Ch] [ebp-4h]

  v5 = 0;
  v13 = 0;
  if ( pToolTip != nullptr && pTI != nullptr )
  {
    v6 = 1;
    while ( (char *)v6 != nType.m_pszData )
    {
      v6 *= 2;
      if ( ++v5 >= 11 )
        goto LABEL_19;
    }
    if ( v5 != -1 )
    {
      m_pszData = (char *)&ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)strText.m_pszData - 1)[1];
      strTipText.m_pszData = m_pszData;
      v8 = lpszDescr;
      LOBYTE(v13) = 1;
      if ( lpszDescr == nullptr )
        v8 = &var;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
        this: &nType,
        pszSrc: v8);
      LOBYTE(v13) = 2;
      if ( afxTooltipManager != nullptr && afxTooltipManager->m_Params[v5].m_bBalloonTooltip != 0 )
      {
        if ( *((_DWORD *)nType.m_pszData - 3) != 0 )
        {
          SendMessageA(hWnd: pToolTip->m_hWnd, Msg: 0x420u, wParam: 1u, lParam: (LPARAM)strText.m_pszData);
          ATL::CSimpleStringT<char,0>::operator=(this: &strTipText, strSrc: (ATL::CStringData *)&nType);
          m_pszData = strTipText.m_pszData;
        }
        else
        {
          SendMessageA(hWnd: pToolTip->m_hWnd, Msg: 0x420u, wParam: 1u, lParam: (LPARAM)nType.m_pszData);
        }
      }
      v9 = (char *)calloc(count: *((_DWORD *)m_pszData - 3) + 1, size: 1u);
      pTI->lpszText = v9;
      if ( v9 != nullptr )
      {
        lstrcpyA(lpString1: v9, lpString2: m_pszData);
        v10 = AfxDynamicDownCast(pClass: &CMFCToolTipCtrl::classCMFCToolTipCtrl, pObject: pToolTip);
        if ( v10 != nullptr )
        {
          v11 = ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)nType.m_pszData - 1);
          ((void (__thiscall *)(CObject *, ATL::CStringData *))v10->__vftable[30].dtr_CObject)(a1: v10, a2: &v11[1]);
        }
      }
      ATL::CStringData::Release(this: (ATL::CStringData *)nType.m_pszData - 1);
      ATL::CStringData::Release(this: (ATL::CStringData *)m_pszData - 1);
    }
  }
LABEL_19:
  ATL::CStringData::Release(this: (ATL::CStringData *)strText.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x103D9553
// Name: public: virtual struct CRuntimeClass __near * CTabbedPane::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CTabbedPane::GetRuntimeClass(CTabbedPane *this)
{
  return &CTabbedPane::classCTabbedPane;
}

//------------------------------------------------------------------------------
// Address: 0x103D9559
// Name: public: virtual int CDockablePane::CanAcceptPane(class CBasePane const __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CDockablePane::CanAcceptPane(CDockablePane *this, const CBasePane *pBar)
{
  return pBar != nullptr
      && CObject::IsKindOf(this: &pBar->CWnd, pClass: &CDockablePane::classCDockablePane) != 0
      && (this->IsDocked((CBasePane *)this) != 0 || this->IsInFloatingMultiPaneFrameWnd((CBasePane *)this) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x103D959E
// Name: public: virtual int CDockablePane::IsAutoHideMode(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockablePane::IsAutoHideMode(CDockablePane *this)
{
  return this->m_bPinState;
}

//------------------------------------------------------------------------------
// Address: 0x103D95A5
// Name: public: virtual int CDockablePane::IsAutohideAllEnabled(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockablePane::IsAutohideAllEnabled(CDockablePane *this)
{
  return this->m_bEnableAutoHideAll;
}

//------------------------------------------------------------------------------
// Address: 0x103D95AC
// Name: public: virtual void CDockablePane::OnAfterDockFromMiniFrame(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockablePane::OnAfterDockFromMiniFrame(CDockablePane *this)
{
  ((void (__stdcall *)(CDockablePane *, _DWORD, _DWORD))this->OnAfterDock)(a1: this, a2: 0, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103D95BA
// Name: public: virtual int CDockablePane::DockToRecentPos(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockablePane::DockToRecentPos(CDockablePane *this)
{
  return this->Dock((CPane *)this, a2: nullptr, a3: nullptr, a4: DM_SHOW);
}

//------------------------------------------------------------------------------
// Address: 0x103D95C9
// Name: public: virtual int CDockablePane::IsHideInAutoHideMode(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockablePane::IsHideInAutoHideMode(CDockablePane *this)
{
  return CDockablePane::m_bHideInAutoHideMode;
}

//------------------------------------------------------------------------------
// Address: 0x103D95CF
// Name: public: virtual int CDockablePane::CanAdjustLayout(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockablePane::CanAdjustLayout(CDockablePane *this)
{
  int result; // eax

  result = 0;
  if ( this->m_bIsSliding == 0 || this->m_bIsHiding == 0 )
    return 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103D95E5
// Name: public: virtual unsigned int CDockablePane::GetAHSlideMode(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CDockablePane::GetAHSlideMode(CDockablePane *this)
{
  return this->m_ahSlideMode;
}

//------------------------------------------------------------------------------
// Address: 0x103D95EC
// Name: public: virtual class CMFCBaseTabCtrl __near * CBaseTabbedPane::GetUnderlyingWindow(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCBaseTabCtrl *__thiscall CBaseTabbedPane::GetUnderlyingWindow(CBaseTabbedPane *this)
{
  return this->m_pTabWnd;
}

//------------------------------------------------------------------------------
// Address: 0x103D95F3
// Name: public: virtual int CBaseTabbedPane::GetTabsNum(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CBaseTabbedPane::GetTabsNum(CBaseTabbedPane *this)
{
  if ( this->m_pTabWnd != nullptr )
    return this->m_pTabWnd->GetTabsNum(this: this->m_pTabWnd);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103D960F
// Name: public: virtual int CBaseTabbedPane::GetVisibleTabsNum(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CBaseTabbedPane::GetVisibleTabsNum(CBaseTabbedPane *this)
{
  if ( this->m_pTabWnd != nullptr )
    return this->m_pTabWnd->GetVisibleTabsNum(this: this->m_pTabWnd);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103D962B
// Name: public: virtual int CBaseTabbedPane::IsHideSingleTab(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CBaseTabbedPane::IsHideSingleTab(CBaseTabbedPane *this)
{
  if ( this->m_pTabWnd != nullptr )
    return this->m_pTabWnd->IsHideSingleTab(this: this->m_pTabWnd);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103D9647
// Name: public: virtual void CBaseTabbedPane::EnableSetCaptionTextToTabName(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CBaseTabbedPane::EnableSetCaptionTextToTabName(CBaseTabbedPane *this, int bEnable)
{
  this->m_bSetCaptionTextToTabName = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x103D9659
// Name: public: virtual int CBaseTabbedPane::CanSetCaptionTextToTabName(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CBaseTabbedPane::CanSetCaptionTextToTabName(CBaseTabbedPane *this)
{
  return this->m_bSetCaptionTextToTabName;
}

//------------------------------------------------------------------------------
// Address: 0x103D9660
// Name: public: virtual int CTabbedPane::FloatTab(class CWnd __near *,int,enum AFX_DOCK_METHOD,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CTabbedPane::FloatTab(CTabbedPane *this, CWnd *pBar, int nTabID, AFX_DOCK_METHOD dockMethod, int bHide)
{
  CObject *v6; // eax

  v6 = AfxDynamicDownCast(pClass: &CMFCTabCtrl::classCMFCTabCtrl, pObject: this->m_pTabWnd);
  if ( ((int (__thiscall *)(CObject *))v6->__vftable[35].dtr_CObject)(a1: v6) <= 1 )
    return 0;
  else
    return CBaseTabbedPane::FloatTab(this, pBar, nTabID, dockMethod, bHide);
}

//------------------------------------------------------------------------------
// Address: 0x103D96A5
// Name: public: virtual int CTabbedPane::DetachPane(class CWnd __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CTabbedPane::DetachPane(CTabbedPane *this, CWnd *pBar, int bHide)
{
  CObject *v4; // eax

  v4 = AfxDynamicDownCast(pClass: &CMFCTabCtrl::classCMFCTabCtrl, pObject: this->m_pTabWnd);
  if ( ((int (__thiscall *)(CObject *))v4->__vftable[35].dtr_CObject)(a1: v4) <= 0 )
    return 0;
  else
    return CBaseTabbedPane::DetachPane(this, pBar, bHide);
}

//------------------------------------------------------------------------------
// Address: 0x103D96E3
// Name: public: virtual void CTabbedPane::GetTabArea(class CRect __near &,class CRect __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CTabbedPane::GetTabArea(CTabbedPane *this, CRect *rectTabAreaTop, CRect *rectTabAreaBottom)
{
  int v4; // eax
  CObject *v5; // eax
  CObject *v6; // eax
  CWnd *v7; // eax
  CRect *v8; // [esp-4h] [ebp-Ch]
  CMFCBaseTabCtrl *m_pTabWnd; // [esp+0h] [ebp-8h]

  SetRectEmpty(lprc: rectTabAreaTop);
  SetRectEmpty(lprc: rectTabAreaBottom);
  v4 = this->IsTabLocationBottom(this);
  m_pTabWnd = this->m_pTabWnd;
  if ( v4 != 0 )
  {
    v5 = AfxDynamicDownCast(pClass: &CMFCTabCtrl::classCMFCTabCtrl, pObject: m_pTabWnd);
    v5->__vftable[31].Serialize(this: v5, a2: (CArchive *)rectTabAreaBottom);
    v8 = rectTabAreaBottom;
  }
  else
  {
    v6 = AfxDynamicDownCast(pClass: &CMFCTabCtrl::classCMFCTabCtrl, pObject: m_pTabWnd);
    v6->__vftable[31].Serialize(this: v6, a2: (CArchive *)rectTabAreaTop);
    v8 = rectTabAreaTop;
  }
  v7 = (CWnd *)AfxDynamicDownCast(pClass: &CMFCTabCtrl::classCMFCTabCtrl, pObject: this->m_pTabWnd);
  CWnd::ClientToScreen(this: v7, lpRect: v8);
}

//------------------------------------------------------------------------------
// Address: 0x103D9761
// Name: public: virtual int CTabbedPane::IsTabLocationBottom(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CTabbedPane::IsTabLocationBottom(CTabbedPane *this)
{
  return AfxDynamicDownCast(pClass: &CMFCTabCtrl::classCMFCTabCtrl, pObject: this->m_pTabWnd)[33].__vftable == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103D9781
// Name: public: static class CObject __near * CTabbedPane::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseTabbedPane *__stdcall CTabbedPane::CreateObject()
{
  CBaseTabbedPane *v0; // esi
  CBaseTabbedPane *result; // eax

  v0 = (CBaseTabbedPane *)operator new(nSize: 0x370u);
  result = nullptr;
  if ( v0 != nullptr )
  {
    CBaseTabbedPane::CBaseTabbedPane(this: v0, bAutoDestroy: 0);
    v0->__vftable = (CBaseTabbedPane_vtbl *)&CTabbedPane::`vftable';
    return v0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103D97E3
// Name: protected: virtual void CTabbedPane::OnPressCloseButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CTabbedPane::OnPressCloseButton(CTabbedPane *this@<ecx>, int a2@<ebx>)
{
  CWnd *v3; // ebx
  CFrameWnd *v4; // eax
  CObject *v5; // eax
  int v6; // eax

  if ( this->m_pTabWnd != nullptr )
  {
    v3 = this->m_pTabWnd->GetActiveWnd(this: this->m_pTabWnd);
    v4 = AFXGetParentFrame(pWnd: this);
    v5 = AfxDynamicDownCast(pClass: &CFrameWnd::classCFrameWnd, pObject: v4);
    if ( v5 == nullptr
      || SendMessageA(hWnd: (HWND)v5[8].__vftable, Msg: AFX_WM_ON_PRESS_CLOSE_BUTTON, wParam: 0, lParam: (LPARAM)v3) == 0 )
    {
      if ( ((int (__thiscall *)(CMFCBaseTabCtrl *, int))this->m_pTabWnd->GetVisibleTabsNum)(a1: this->m_pTabWnd, a2) == 1 )
        CDockablePane::OnPressCloseButton(this);
      v6 = this->m_pTabWnd->GetActiveTab(this: this->m_pTabWnd);
      this->m_pTabWnd->ShowTab(this: this->m_pTabWnd, a2: v6, a3: 0, a4: 1, a5: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D9870
// Name: public: static void CTabbedPane::ResetTabs(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static void __stdcall CTabbedPane::ResetTabs()
{
  CList<HWND__ *,HWND__ *>::CNode *m_pNodeHead; // ebx
  HWND__ *data; // esi
  CWnd *v2; // eax
  CObject *v3; // eax
  CMFCTabCtrl *v4; // esi
  CMFCVisualManager *Instance; // eax
  CMFCTabCtrl_vtbl *v6; // edi
  int v7; // eax
  CMFCVisualManager *v8; // eax
  int v9; // eax
  CArray<unsigned long,unsigned long> arTabsAutoColors; // [esp+10h] [ebp-20h] BYREF
  int v11; // [esp+2Ch] [ebp-4h]

  m_pNodeHead = CTabbedPane::m_lstTabbedControlBars.m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( IsWindow(hWnd: data) )
    {
      v2 = CWnd::FromHandlePermanent(hWnd: data);
      v3 = AfxDynamicDownCast(pClass: &CTabbedPane::classCTabbedPane, pObject: v2);
      if ( v3 != nullptr )
      {
        v4 = (CMFCTabCtrl *)AfxDynamicDownCast(
                              pClass: &CMFCTabCtrl::classCMFCTabCtrl,
                              pObject: (CObject *)v3[214].__vftable);
        Instance = CMFCVisualManager::GetInstance();
        v6 = v4->__vftable;
        v7 = ((int (__thiscall *)(CMFCVisualManager *, int))Instance->GetDockingTabsBordersSize)(a1: Instance, a2: 1);
        ((void (__thiscall *)(CMFCTabCtrl *, int))v6->SetTabBorderSize)(a1: v4, a2: v7);
        v8 = CMFCVisualManager::GetInstance();
        v9 = v8->IsDockingTabHasBorder(this: v8);
        CMFCTabCtrl::SetDrawFrame(this: v4, bDraw: v9);
        CMFCTabCtrl::ModifyTabStyle(this: v4, style: CTabbedPane::m_StyleTabWnd);
        v4->RecalcLayout(this: v4);
        if ( CTabbedPane::m_bIsTabsAutoColor != 0 )
        {
          CMFCBaseTabCtrl::EnableAutoColor(this: v4, bEnable: 1);
          CMFCBaseTabCtrl::SetAutoColors(this: v4, arColors: &CTabbedPane::m_arTabsAutoColors);
        }
        else
        {
          CMFCBaseTabCtrl::EnableAutoColor(this: v4, bEnable: 0);
          arTabsAutoColors.__vftable = (CArray<unsigned long,unsigned long>_vtbl *)&CArray<unsigned long,unsigned long>::`vftable';
          memset(&arTabsAutoColors.m_pData, 0, 16);
          v11 = 0;
          CMFCBaseTabCtrl::SetAutoColors(this: v4, arColors: &arTabsAutoColors);
          v11 = -1;
          CArray<unsigned long,unsigned long>::~CArray<unsigned long,unsigned long>(this: &arTabsAutoColors);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103D9976
// Name: protected: int CTabbedPane::OnCreate(struct tagCREATESTRUCTA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CTabbedPane::OnCreate(CTabbedPane *this, tagCREATESTRUCTA *lpCreateStruct)
{
  int result; // eax
  int cy; // eax
  CObject *Object; // eax
  CMFCTabCtrl *v6; // eax
  CMFCBaseTabCtrl *v7; // esi
  CMFCBaseTabCtrl *m_pTabWnd; // ecx
  CMFCBaseTabCtrl_vtbl *v9; // eax
  CMFCVisualManager *Instance; // eax
  int v11; // eax
  CMFCBaseTabCtrl_vtbl *v12; // [esp+8h] [ebp-18h]
  CRect rectClient; // [esp+Ch] [ebp-14h] BYREF

  result = CDockablePane::OnCreate(this, lpCreateStruct);
  if ( result != -1 )
  {
    rectClient.right = lpCreateStruct->cx;
    cy = lpCreateStruct->cy;
    rectClient.left = 0;
    rectClient.top = 0;
    rectClient.bottom = cy;
    if ( this->m_pTabWnd != nullptr || CTabbedPane::m_pTabWndRTC == nullptr )
      AfxThrowInvalidArgException();
    Object = CRuntimeClass::CreateObject(this: CTabbedPane::m_pTabWndRTC);
    v6 = (CMFCTabCtrl *)AfxDynamicDownCast(pClass: &CMFCTabCtrl::classCMFCTabCtrl, pObject: Object);
    v7 = v6;
    this->m_pTabWnd = v6;
    if ( v6 == nullptr )
      return -1;
    if ( CMFCTabCtrl::Create(
           this: v6,
           style: CTabbedPane::m_StyleTabWnd,
           rect: &rectClient,
           pParentWnd: this,
           nID: 0x65u,
           location: (CMFCBaseTabCtrl::Location)(CTabbedPane::m_bTabsAlwaysTop != 0),
           bCloseBtn: 0) == 0 )
    {
      m_pTabWnd = this->m_pTabWnd;
      if ( m_pTabWnd != nullptr )
        ((void (__thiscall *)(CMFCBaseTabCtrl *, int))m_pTabWnd->dtr_CObject)(a1: m_pTabWnd, a2: 1);
      this->m_pTabWnd = nullptr;
      return -1;
    }
    this->m_pTabWnd->m_bActivateTabOnRightClick = 1;
    if ( CTabbedPane::m_bIsTabsAutoColor != 0 )
    {
      CMFCBaseTabCtrl::EnableAutoColor(this: v7, bEnable: 1);
      CMFCBaseTabCtrl::SetAutoColors(this: v7, arColors: &CTabbedPane::m_arTabsAutoColors);
    }
    v9 = v7->__vftable;
    v7->m_bAutoDestroyWindow = 0;
    v9->HideSingleTab(this: v7, a2: 1);
    Instance = CMFCVisualManager::GetInstance();
    v12 = v7->__vftable;
    v11 = ((int (__thiscall *)(CMFCVisualManager *, int))Instance->GetDockingTabsBordersSize)(a1: Instance, a2: 1);
    ((void (__thiscall *)(CMFCBaseTabCtrl *, int))v12->SetTabBorderSize)(a1: v7, a2: v11);
    v7->m_bEnableWrapping = 1;
    CList<CFrameWnd *,CFrameWnd *>::AddTail(
      this: (CList<CFrameWnd *,CFrameWnd *> *)&CTabbedPane::m_lstTabbedControlBars,
      newElement: (CFrameWnd *)this->m_hWnd);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103D9AAE
// Name: protected: void CTabbedPane::OnDestroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CTabbedPane::OnDestroy(CTabbedPane *this)
{
  HWND__ *m_hWnd; // eax
  __POSITION *v3; // eax

  if ( this != nullptr )
    m_hWnd = this->m_hWnd;
  else
    m_hWnd = nullptr;
  v3 = CList<unsigned int,unsigned int>::Find(
         this: &CTabbedPane::m_lstTabbedControlBars,
         searchValue: m_hWnd,
         startAfter: nullptr);
  if ( v3 != nullptr )
    CList<HWND__ *,HWND__ *>::RemoveAt(
      this: (CList<unsigned int,unsigned int> *)&CTabbedPane::m_lstTabbedControlBars,
      position: v3);
  CDockablePane::OnDestroy(this);
}

//------------------------------------------------------------------------------
// Address: 0x103D9AE3
// Name: protected: virtual struct AFX_MSGMAP const __near * CTabbedPane::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CTabbedPane::GetMessageMap(CTabbedPane *this)
{
  return (const AFX_MSGMAP *)&off_1068566C;
}

//------------------------------------------------------------------------------
// Address: 0x103D9AE9
// Name: public: virtual struct CRuntimeClass __near * CMFCAutoHideButton::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCAutoHideButton::GetRuntimeClass(CMFCAutoHideButton *this)
{
  return &CMFCAutoHideButton::classCMFCAutoHideButton;
}

//------------------------------------------------------------------------------
// Address: 0x103D9AEF
// Name: public: CMFCAutoHideButton::CMFCAutoHideButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCAutoHideButton *__thiscall CMFCAutoHideButton::CMFCAutoHideButton(CMFCAutoHideButton *this)
{
  this->__vftable = (CMFCAutoHideButton_vtbl *)&CMFCAutoHideButton::`vftable';
  this->m_rect.left = 0;
  this->m_rect.top = 0;
  this->m_rect.right = 0;
  this->m_rect.bottom = 0;
  this->m_bTop = 0;
  this->m_pParentBar = nullptr;
  this->m_pAutoHideWindow = nullptr;
  this->m_dwAlignment = 0;
  this->m_bVisible = 0;
  this->m_bHighlighted = 0;
  SetRectEmpty(lprc: &this->m_rect);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103D9B27
// Name: public: virtual int CMFCAutoHideButton::IsHighlighted(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCAutoHideButton::IsHighlighted(CMFCAutoHideButton *this)
{
  return this->m_bHighlighted;
}

//------------------------------------------------------------------------------
// Address: 0x103D9B2B
// Name: public: virtual void CMFCAutoHideButton::OnFillBackground(class CDC __near *,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCAutoHideButton::OnFillBackground(CMFCAutoHideButton *this, CDC *pDC, CRect rect)
{
  CMFCVisualManager *Instance; // eax

  Instance = CMFCVisualManager::GetInstance();
  ((void (__thiscall *)(CMFCVisualManager *, CDC *, int, int, int, int, CMFCAutoHideButton *))Instance->OnFillAutoHideButtonBackground)(
    a1: Instance,
    a2: pDC,
    a3: rect.left,
    a4: rect.top,
    a5: rect.right,
    a6: rect.bottom,
    a7: this);
}

//------------------------------------------------------------------------------
// Address: 0x103D9B59
// Name: public: virtual void CMFCAutoHideButton::OnDrawBorder(class CDC __near *,class CRect,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCAutoHideButton::OnDrawBorder(
        CMFCAutoHideButton *this,
        CDC *pDC,
        CRect rectBounds,
        CRect rectBorderSize)
{
  CMFCVisualManager *Instance; // eax

  Instance = CMFCVisualManager::GetInstance();
  ((void (__thiscall *)(CMFCVisualManager *, CDC *, int, int, int, int, int, int, int, int, CMFCAutoHideButton *))Instance->OnDrawAutoHideButtonBorder)(
    a1: Instance,
    a2: pDC,
    a3: rectBounds.left,
    a4: rectBounds.top,
    a5: rectBounds.right,
    a6: rectBounds.bottom,
    a7: rectBorderSize.left,
    a8: rectBorderSize.top,
    a9: rectBorderSize.right,
    a10: rectBorderSize.bottom,
    a11: this);
}

//------------------------------------------------------------------------------
// Address: 0x103D9B93
// Name: public: int CMFCAutoHideButton::IsHorizontal(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCAutoHideButton::IsHorizontal(CMFCAutoHideButton *this)
{
  return (this->m_dwAlignment & 0xA000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x103D9BA0
// Name: public: virtual void CMFCAutoHideButton::ShowButton(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCAutoHideButton::ShowButton(CMFCAutoHideButton *this, int bShow)
{
  this->m_bVisible = bShow;
}

//------------------------------------------------------------------------------
// Address: 0x103D9BAF
// Name: public: virtual void CMFCAutoHideButton::HighlightButton(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCAutoHideButton::HighlightButton(CMFCAutoHideButton *this, int bHighlight)
{
  this->m_bHighlighted = bHighlight;
}

//------------------------------------------------------------------------------
// Address: 0x103D9BBE
// Name: public: virtual void CMFCAutoHideButton::UnSetAutoHideMode(class CDockablePane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCAutoHideButton::UnSetAutoHideMode(CMFCAutoHideButton *this, CDockablePane *pFirstBarInGroup)
{
  if ( this->m_pAutoHideWindow != nullptr )
    this->m_pAutoHideWindow->UnSetAutoHideMode(this: this->m_pAutoHideWindow, a2: pFirstBarInGroup);
}

//------------------------------------------------------------------------------
// Address: 0x103D9BD9
// Name: public: static class CObject __near * CMFCAutoHideButton::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCAutoHideButton *__stdcall CMFCAutoHideButton::CreateObject()
{
  CMFCAutoHideButton *v0; // eax

  v0 = (CMFCAutoHideButton *)operator new(nSize: 0x30u);
  if ( v0 != nullptr )
    return CMFCAutoHideButton::CMFCAutoHideButton(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103D9C11
// Name: public: class CSize CMFCAutoHideButton::GetSize(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CMFCAutoHideButton::GetSize(CMFCAutoHideButton *this, CSize *result)
{
  CMFCVisualManager *Instance; // eax
  int v4; // eax
  bool v5; // zf
  int v7; // eax
  HICON__ *v8; // ebx
  int cy; // ecx
  int cx; // eax
  int v11; // edx
  int v12; // edx
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // ecx
  CDockingPanesRow *m_pDockBarRow; // ecx
  int m_nExtraSpace; // edi
  int v19; // eax
  CSize sizeText; // [esp+8h] [ebp-14h] BYREF
  CSize sizeIcon; // [esp+10h] [ebp-Ch]
  int bIsOverlapped; // [esp+18h] [ebp-4h]
  BOOL bHorz; // [esp+24h] [ebp+8h]

  Instance = CMFCVisualManager::GetInstance();
  v4 = Instance->HasOverlappedAutoHideButtons(this: Instance);
  v5 = this->m_pAutoHideWindow == nullptr;
  bIsOverlapped = v4;
  v7 = CMFCAutoHideButton::m_nMarginSize + 2 * CMFCAutoHideButton::m_nBorderSize;
  result->cx = v7;
  result->cy = v7;
  if ( !v5 )
  {
    bHorz = CMFCAutoHideButton::IsHorizontal(this);
    v8 = this->m_pAutoHideWindow->GetPaneIcon(this: this->m_pAutoHideWindow, a2: 0);
    this->GetTextSize(this, result: &sizeText);
    sizeIcon.cx = 0;
    sizeIcon.cy = 0;
    if ( v8 != nullptr )
      sizeIcon = afxGlobalData.m_sizeSmallIcon;
    if ( bIsOverlapped != 0 )
    {
      if ( bHorz )
      {
        cy = sizeText.cy;
        if ( sizeIcon.cy > sizeText.cy )
          cy = sizeIcon.cy;
        cx = result->cy;
      }
      else
      {
        cy = sizeText.cx;
        if ( sizeIcon.cx > sizeText.cx )
          cy = sizeIcon.cx;
        cx = result->cx;
      }
      v11 = afxGlobalData.m_nTextHeightHorz + 2 * (cy + cx) / 3;
    }
    else if ( v8 != nullptr )
    {
      if ( (sizeText.cx <= 0 || !bHorz) && (sizeText.cy <= 0 || bHorz) )
      {
        v11 = CMFCAutoHideButton::m_nMarginSize + 1;
      }
      else
      {
        v5 = !CMFCAutoHideButton::IsHorizontal(this);
        v13 = sizeIcon.cx;
        if ( v5 )
          v13 = sizeIcon.cy;
        v11 = v13 + v12;
      }
    }
    else
    {
      v11 = CMFCAutoHideButton::m_nMarginSize + CMFCAutoHideButton::m_nTextSizeNoIcon;
    }
    v14 = sizeText.cx;
    if ( bHorz )
    {
      result->cx += v11 + sizeIcon.cx + sizeText.cx;
      v15 = sizeText.cy;
      if ( sizeIcon.cy > sizeText.cy )
        v15 = sizeIcon.cy;
      result->cy += v15;
    }
    else
    {
      if ( sizeIcon.cx > sizeText.cx )
        v14 = sizeIcon.cx;
      v16 = sizeIcon.cy + sizeText.cy;
      result->cx += v14;
      result->cy += v11 + v16;
    }
    m_pDockBarRow = this->m_pParentBar->m_pDockBarRow;
    if ( m_pDockBarRow != nullptr )
    {
      m_nExtraSpace = m_pDockBarRow->m_nExtraSpace;
      v19 = CDockingPanesRow::GetMaxPaneSize(this: m_pDockBarRow, bSkipHiddenBars: 1) - m_nExtraSpace;
      if ( bHorz )
      {
        if ( result->cy > v19 )
          v19 = result->cy;
        result->cy = v19;
      }
      else
      {
        if ( result->cx > v19 )
          v19 = result->cx;
        result->cx = v19;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103D9D8B
// Name: public: void CMFCAutoHideButton::ShowAttachedWindow(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCAutoHideButton::ShowAttachedWindow(CMFCAutoHideButton *this, int bShow)
{
  BOOL v3; // eax

  v3 = IsWindowVisible(hWnd: this->m_pAutoHideWindow->m_hWnd);
  if ( bShow != 0 )
  {
    if ( v3 )
      goto LABEL_6;
    goto LABEL_5;
  }
  if ( v3 )
LABEL_5:
    this->m_pAutoHideWindow->Slide(this: this->m_pAutoHideWindow, a2: bShow, a3: 1);
LABEL_6:
  this->m_pParentBar->SetActiveInGroup(this: this->m_pParentBar, a2: bShow);
}

//------------------------------------------------------------------------------
// Address: 0x103D9DCC
// Name: public: virtual int CMFCAutoHideButton::Create(class CMFCAutoHideBar __near *,class CDockablePane __near *,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCAutoHideButton::Create(
        CMFCAutoHideButton *this,
        CMFCAutoHideBar *pParentBar,
        CDockablePane *pAutoHideWnd,
        unsigned int dwAlignment)
{
  CSize size; // [esp+4h] [ebp-8h] BYREF

  this->m_pParentBar = pParentBar;
  this->m_pAutoHideWindow = pAutoHideWnd;
  this->m_dwAlignment = dwAlignment;
  CDockablePane::SetAutoHideParents(this: pAutoHideWnd, pToolBar: pParentBar, pBtn: this);
  CMFCAutoHideButton::GetSize(this, result: &size);
  SetRect(lprc: &this->m_rect, xLeft: 0, yTop: 0, xRight: size.cx, yBottom: size.cy);
  this->m_bVisible = 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103D9E19
// Name: public: virtual void CMFCAutoHideButton::OnDraw(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCAutoHideButton::OnDraw(CMFCAutoHideButton *this, CDC *pDC)
{
  CMFCVisualManager *Instance; // eax
  int v4; // eax
  unsigned int v5; // eax
  unsigned int m_dwAlignment; // eax
  int v7; // eax
  int v8; // edi
  int cy; // esi
  int v10; // edx
  CMFCAutoHideButton *v11; // ecx
  int v12; // eax
  CDC *v13; // esi
  HDC__ *m_hDC; // edx
  BOOL IsHorizontal; // eax
  CAfxStringMgr *StringManager; // eax
  CDockablePane *m_pAutoHideWindow; // ecx
  bool v18; // zf
  CFont *p_fontRegular; // eax
  CMFCVisualManager *v20; // eax
  CDC_vtbl *v21; // edi
  int v22; // eax
  HICON hIcon; // [esp+10h] [ebp-A0h]
  HICON hIcona; // [esp+10h] [ebp-A0h]
  int v25; // [esp+14h] [ebp-9Ch]
  CSize result; // [esp+18h] [ebp-98h] BYREF
  CDC *v27; // [esp+20h] [ebp-90h]
  ATL::CSimpleStringT<char,0> v28; // [esp+24h] [ebp-8Ch] BYREF
  tagTEXTMETRICA tm; // [esp+28h] [ebp-88h] BYREF
  _DWORD v30[4]; // [esp+60h] [ebp-50h] BYREF
  tagRECT rc; // [esp+70h] [ebp-40h] BYREF
  CRect rect; // [esp+80h] [ebp-30h] BYREF
  tagRECT m_rect; // [esp+90h] [ebp-20h] BYREF
  int v34; // [esp+ACh] [ebp-4h]

  v27 = pDC;
  Instance = CMFCVisualManager::GetInstance();
  v28.m_pszData = (char *)Instance->HasOverlappedAutoHideButtons(this: Instance);
  if ( v28.m_pszData != nullptr )
    v4 = CMFCAutoHideButton::IsHorizontal(this) ? 5 : 7;
  else
    v4 = CMFCAutoHideButton::m_nTextMargin;
  v25 = v4;
  CMFCAutoHideButton::GetSize(this, &result);
  SetRect(lprc: &this->m_rect, xLeft: 0, yTop: 0, xRight: result.cx, yBottom: result.cy);
  rect.left = CMFCAutoHideButton::m_nBorderSize;
  rect.right = CMFCAutoHideButton::m_nBorderSize;
  rect.bottom = CMFCAutoHideButton::m_nBorderSize;
  v5 = this->m_dwAlignment & 0xF000;
  rect.top = 0;
  switch ( v5 )
  {
    case 0x1000u:
      CGlobalUtils::FlipRect(this: &afxGlobalUtils, &rect, nDegrees: -90);
      break;
    case 0x4000u:
      CGlobalUtils::FlipRect(this: &afxGlobalUtils, &rect, nDegrees: 90);
      break;
    case 0x8000u:
      CGlobalUtils::FlipRect(this: &afxGlobalUtils, &rect, nDegrees: 180);
      break;
    default:
      break;
  }
  if ( v28.m_pszData != nullptr && this->m_pParentBar->m_bFirstInGroup == 0 )
  {
    m_dwAlignment = this->m_dwAlignment;
    rc = (tagRECT)this->m_rect;
    v7 = m_dwAlignment & 0xF000;
    if ( v7 != 4096 )
    {
      if ( v7 == 0x2000 )
        goto LABEL_16;
      if ( v7 != 0x4000 )
      {
        if ( v7 != 0x8000 )
        {
LABEL_18:
          ((void (__thiscall *)(CMFCAutoHideButton *, CDC *, int, int, int, int))this->OnFillBackground)(
            a1: this,
            a2: v27,
            a3: rc.left,
            a4: rc.top,
            a5: rc.right,
            a6: rc.bottom);
          ((void (__thiscall *)(CMFCAutoHideButton *, CDC *, int, int, int, int, int, int, int, int))this->OnDrawBorder)(
            a1: this,
            a2: v27,
            a3: rc.left,
            a4: rc.top,
            a5: rc.right,
            a6: rc.bottom,
            a7: rect.left,
            a8: rect.top,
            a9: rect.right,
            a10: rect.bottom);
          goto LABEL_19;
        }
LABEL_16:
        OffsetRect(lprc: &rc, dx: this->m_rect.left + result.cy / 2 - this->m_rect.right, dy: 0);
        goto LABEL_18;
      }
    }
    OffsetRect(lprc: &rc, dx: 0, dy: result.cx / 2 + this->m_rect.top - this->m_rect.bottom);
    goto LABEL_18;
  }
LABEL_19:
  ((void (__thiscall *)(CMFCAutoHideButton *, CDC *, int, int, int, int))this->OnFillBackground)(
    a1: this,
    a2: v27,
    a3: this->m_rect.left,
    a4: this->m_rect.top,
    a5: this->m_rect.right,
    a6: this->m_rect.bottom);
  ((void (__thiscall *)(CMFCAutoHideButton *, CDC *, int, int, int, int, int, int, int, int))this->OnDrawBorder)(
    a1: this,
    a2: v27,
    a3: this->m_rect.left,
    a4: this->m_rect.top,
    a5: this->m_rect.right,
    a6: this->m_rect.bottom,
    a7: rect.left,
    a8: rect.top,
    a9: rect.right,
    a10: rect.bottom);
  if ( this->m_pAutoHideWindow != nullptr )
  {
    m_rect = (tagRECT)this->m_rect;
    if ( v28.m_pszData == nullptr )
    {
      m_rect.left += rect.left;
      m_rect.top += rect.top;
      m_rect.right -= rect.right;
      m_rect.bottom -= rect.bottom;
    }
    InflateRect(lprc: &m_rect, dx: -CMFCAutoHideButton::m_nMarginSize, dy: -CMFCAutoHideButton::m_nMarginSize);
    v8 = 0;
    if ( v28.m_pszData != nullptr )
    {
      if ( CMFCAutoHideButton::IsHorizontal(this) )
        InflateRect(lprc: &m_rect, dx: 2 * (m_rect.bottom - m_rect.top) / -3, dy: 0);
      else
        InflateRect(lprc: &m_rect, dx: 0, dy: 2 * (m_rect.right - m_rect.left) / -3);
    }
    if ( this->m_pAutoHideWindow != nullptr )
    {
      hIcon = this->m_pAutoHideWindow->GetPaneIcon(this: this->m_pAutoHideWindow, a2: 0);
      if ( hIcon != nullptr )
      {
        cy = afxGlobalData.m_sizeSmallIcon.cy;
        result = afxGlobalData.m_sizeSmallIcon;
        if ( !CMFCAutoHideButton::IsHorizontal(this) )
          v8 = (m_rect.right - m_rect.left - v10) / 2;
        if ( CMFCAutoHideButton::IsHorizontal(this: v11) )
          v12 = (m_rect.bottom - m_rect.top - cy) / 2;
        else
          v12 = 0;
        v13 = v27;
        if ( v27 != nullptr )
          m_hDC = v27->m_hDC;
        else
          m_hDC = nullptr;
        DrawIconEx(
          hdc: m_hDC,
          xLeft: v8 + m_rect.left,
          yTop: v12 + m_rect.top,
          hIcon,
          cxWidth: result.cx,
          cyWidth: result.cy,
          istepIfAniCur: 0,
          hbrFlickerFreeDraw: nullptr,
          diFlags: 3u);
        if ( CMFCAutoHideButton::IsHorizontal(this) )
          m_rect.left += v25 + result.cx;
        else
          m_rect.top += v25 + result.cy;
      }
      else
      {
        IsHorizontal = CMFCAutoHideButton::IsHorizontal(this);
        v13 = v27;
        if ( IsHorizontal )
          m_rect.left += CMFCAutoHideButton::m_nMarginSize;
        else
          m_rect.top += CMFCAutoHideButton::m_nMarginSize;
      }
      StringManager = AfxGetStringManager();
      ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v28, pStringMgr: StringManager);
      m_pAutoHideWindow = this->m_pAutoHideWindow;
      v34 = 0;
      CWnd::GetWindowTextA(
        this: &m_pAutoHideWindow->CPane,
        rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v28);
      if ( *((_DWORD *)v28.m_pszData - 3) != 0 && this->m_pParentBar->m_bActiveInGroup != 0
        || hIcon == nullptr
        || CMFCAutoHideButton::m_bOverlappingTabs == 0 )
      {
        result.cy = CDC::SetBkMode(this: v13, nBkMode: 1);
        v18 = !CMFCAutoHideButton::IsHorizontal(this);
        p_fontRegular = &afxGlobalData.fontRegular;
        if ( v18 )
          p_fontRegular = &afxGlobalData.fontVert;
        hIcona = (HICON)v13->SelectObject(this: v13, a2: p_fontRegular);
        if ( hIcona == nullptr )
          AfxThrowInvalidArgException();
        v20 = CMFCVisualManager::GetInstance();
        v21 = v13->__vftable;
        v22 = v20->GetAutoHideButtonTextColor(this: v20, a2: this);
        v21->SetTextColor(this: v13, a2: v22);
        if ( CMFCAutoHideButton::IsHorizontal(this) )
        {
          v13->DrawTextA(this: v13, a2: v28.m_pszData, a3: *((_DWORD *)v28.m_pszData - 3), a4: &m_rect, a5: 36u);
        }
        else
        {
          GetTextMetricsA(hdc: v13->m_hAttribDC, lptm: &tm);
          v30[1] = m_rect.top;
          v30[2] = m_rect.right;
          v30[3] = v25 + m_rect.top;
          v30[0] = m_rect.right - (m_rect.right - tm.tmHeight - m_rect.left + 1) / 2;
          v27->DrawTextA(this: v27, a2: v28.m_pszData, a3: *((_DWORD *)v28.m_pszData - 3), a4: (tagRECT *)v30, a5: 292u);
          v13 = v27;
        }
        v13->SelectObject(this: v13, a2: (CFont *)hIcona);
        CDC::SetBkMode(this: v13, nBkMode: result.cy);
      }
      ATL::CStringData::Release(this: (ATL::CStringData *)v28.m_pszData - 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103EB3A2
// Name: protected: long CDockablePane::OnSetText(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockablePane::OnSetText(CDockablePane *this, unsigned int __formal, const char *lParam)
{
  HWND Parent; // eax
  CWnd *v6; // eax
  HWND *v7; // edi
  HWND v8; // eax
  CWnd *v9; // eax
  int v10; // esi
  CAfxStringMgr *StringManager; // eax
  HWND v12; // eax
  CPaneFrameWnd *v13; // eax
  int lRes; // [esp+10h] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strLabel; // [esp+14h] [ebp-10h] BYREF
  int v16; // [esp+20h] [ebp-4h]

  lRes = CWnd::Default(this: &this->CPane);
  if ( lRes == 0 )
    return 0;
  if ( this->IsTabbed((CBasePane *)this) != 0 )
  {
    Parent = GetParent(hWnd: this->m_hWnd);
    v6 = CWnd::FromHandle(hWnd: Parent);
    v7 = (HWND *)AfxDynamicDownCast(pClass: &CMFCBaseTabCtrl::classCMFCBaseTabCtrl, pObject: v6);
    v8 = GetParent(hWnd: v7[8]);
    v9 = CWnd::FromHandle(hWnd: v8);
    if ( AfxDynamicDownCast(pClass: &CBaseTabbedPane::classCBaseTabbedPane, pObject: v9) != nullptr )
    {
      v10 = (*((int (__thiscall **)(HWND *, HWND__ *))*v7 + 134))(a1: v7, a2: this->m_hWnd);
      StringManager = AfxGetStringManager();
      ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strLabel, pStringMgr: StringManager);
      v16 = 0;
      if ( v10 >= 0 && v10 < (*((int (__thiscall **)(HWND *))*v7 + 106))(a1: v7) )
      {
        (*((void (__thiscall **)(HWND *, int, ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *))*v7 + 110))(
          a1: v7,
          a2: v10,
          a3: &strLabel);
        if ( ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(this: &strLabel, psz: lParam) != 0 )
        {
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
            this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&lParam,
            pszSrc: lParam);
          v12 = *v7;
          LOBYTE(v16) = 1;
          (*((void (__thiscall **)(HWND *, int, const char **))v12 + 111))(a1: v7, a2: v10, a3: &lParam);
          ATL::CStringData::Release(this: (ATL::CStringData *)lParam - 1);
        }
      }
      ATL::CStringData::Release(this: (ATL::CStringData *)strLabel.m_pszData - 1);
    }
  }
  else
  {
    v13 = this->GetParentMiniFrame(this, a2: 0);
    if ( v13 != nullptr )
    {
      CWnd::SetWindowPos(this: v13, pWndInsertAfter: nullptr, x: 0, y: 0, cx: 0, cy: 0, nFlags: 0x37u);
    }
    else if ( this->IsAutoHideMode((CBasePane *)this) != 0 )
    {
      RedrawWindow(hWnd: this->m_pAutoHideBar->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
      this->SetWindowPos((CBasePane *)this, a2: nullptr, a3: 0, a4: 0, a5: 0, a6: 0, a7: 55u, a8: nullptr);
      this->AdjustDockingLayout((CBasePane *)this, a2: nullptr);
    }
    else
    {
      this->SetWindowPos((CBasePane *)this, a2: nullptr, a3: 0, a4: 0, a5: 0, a6: 0, a7: 55u, a8: nullptr);
    }
  }
  return lRes;
}

//------------------------------------------------------------------------------
// Address: 0x103EB51E
// Name: protected: virtual struct AFX_MSGMAP const __near * CDockablePane::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CDockablePane::GetMessageMap(CDockablePane *this)
{
  return &messageMap_42;
}

//------------------------------------------------------------------------------
// Address: 0x103EB524
// Name: public: virtual struct CRuntimeClass __near * CMFCToolBarButton::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCToolBarButton::GetRuntimeClass(CMFCToolBarButton *this)
{
  return &CMFCToolBarButton::classCMFCToolBarButton;
}

//------------------------------------------------------------------------------
// Address: 0x103EB52A
// Name: protected: void CMFCToolBarButton::Initialize(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarButton::Initialize(CMFCToolBarButton *this)
{
  this->m_iImage = -1;
  this->m_iUserImage = -1;
  this->m_nID = 0;
  this->m_nStyle = 0;
  this->m_bUserButton = 0;
  this->m_bDragFromCollection = 0;
  this->m_bText = 0;
  this->m_bImage = 1;
  this->m_bWrap = 0;
  this->m_bWholeText = 1;
  this->m_bLocked = 0;
  this->m_bIsHidden = 0;
  this->m_bTextBelow = 0;
  this->m_dwdItemData = 0;
  SetRectEmpty(lprc: &this->m_rect);
  this->m_bDisableFill = 0;
  this->m_bExtraSize = 0;
  this->m_pWndParent = nullptr;
  this->m_bHorz = 1;
  this->m_bVisible = 1;
  this->m_sizeText.cx = 0;
  this->m_sizeText.cy = 0;
}

//------------------------------------------------------------------------------
// Address: 0x103EB589
// Name: public: virtual void CMFCToolBarButton::SetImage(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarButton::SetImage(CMFCToolBarButton *this, int iImage)
{
  int m_bUserButton; // edx
  _STATIC_CREATOR_ *v4; // eax
  _STATIC_CREATOR_ *CmdMgr; // eax
  int CmdImage; // eax
  _STATIC_CREATOR_ *v7; // eax
  unsigned int v8; // [esp-10h] [ebp-18h]
  unsigned int v9; // [esp-Ch] [ebp-14h]
  unsigned int m_nID; // [esp-Ch] [ebp-14h]
  int v11; // [esp-8h] [ebp-10h]

  if ( (this->m_nStyle & 1) != 0 )
  {
    this->m_iImage = iImage;
    return;
  }
  m_bUserButton = this->m_bUserButton;
  if ( m_bUserButton != 0 )
    this->m_iUserImage = iImage;
  else
    this->m_iImage = iImage;
  if ( this->m_bLocked == 0 && this->m_nID != 0 )
  {
    if ( iImage == -1 )
    {
      v9 = MEMORY[0x1F];
      CmdMgr = GetCmdMgr();
      CmdImage = CCommandManager::GetCmdImage(this: &CmdMgr->s_TheCmdMgr, uiCmd: v9, bUserImage: 0);
      m_nID = this->m_nID;
      this->m_iImage = CmdImage;
      v7 = GetCmdMgr();
      this->m_iUserImage = CCommandManager::GetCmdImage(this: &v7->s_TheCmdMgr, uiCmd: m_nID, bUserImage: 1);
      if ( this->m_iImage == -1 )
        this->m_bUserButton = this->m_bUserButton == 0;
    }
    else if ( CMFCToolBarButton::m_bUpdateImages != 0 || m_bUserButton != 0 )
    {
      v11 = m_bUserButton;
      v8 = this->m_nID;
      v4 = GetCmdMgr();
      CCommandManager::SetCmdImage(this: &v4->s_TheCmdMgr, uiCmd: v8, iImage, bUserImage: v11);
    }
  }
  if ( this->m_bUserButton != 0 )
  {
    if ( this->m_iUserImage >= 0 )
      return;
    goto LABEL_20;
  }
  if ( this->m_iImage < 0 )
  {
LABEL_20:
    this->m_bImage = 0;
    this->m_bText = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103EB651
// Name: protected: void CMFCToolBarButton::FillInterior(class CDC __near *,class CRect const __near &,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarButton::FillInterior(
        CMFCToolBarButton *this,
        CDC *pDC,
        const CRect *rect,
        int bHighlight,
        int bMenuImage)
{
  int v6; // esi
  CMFCVisualManager *Instance; // eax

  if ( this->m_bDisableFill == 0 )
  {
    v6 = 0;
    if ( CMFCToolBar::m_bCustomizeMode == 0 || CMFCToolBar::m_bAltCustomizeMode != 0 || this->m_bLocked != 0 )
    {
      if ( bHighlight != 0 )
      {
        v6 = 2;
      }
      else if ( (this->m_nStyle & 0x30000) != 0 )
      {
        v6 = 1;
      }
    }
    Instance = CMFCVisualManager::GetInstance();
    if ( bMenuImage != 0 )
      ((void (__thiscall *)(CMFCVisualManager *, CDC *, CMFCToolBarButton *, int, int, int, int, int))Instance->OnFillMenuImageRect)(
        a1: Instance,
        a2: pDC,
        a3: this,
        a4: rect->left,
        a5: rect->top,
        a6: rect->right,
        a7: rect->bottom,
        a8: v6);
    else
      ((void (__thiscall *)(CMFCVisualManager *, CDC *, CMFCToolBarButton *, int, int, int, int, int))Instance->OnFillButtonInterior)(
        a1: Instance,
        a2: pDC,
        a3: this,
        a4: rect->left,
        a5: rect->top,
        a6: rect->right,
        a7: rect->bottom,
        a8: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103EB6DD
// Name: public: virtual int CMFCToolBarButton::CompareWith(class CMFCToolBarButton const __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCToolBarButton::CompareWith(CMFCToolBarButton *this, const CMFCToolBarButton *other)
{
  return other->m_nID == this->m_nID;
}

//------------------------------------------------------------------------------
// Address: 0x103EB6F4
// Name: public: virtual void CMFCToolBarButton::OnChangeParentWnd(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarButton::OnChangeParentWnd(CMFCToolBarButton *this, CWnd *pWndParent)
{
  CObject *v3; // eax

  this->m_bExtraSize = 0;
  this->m_pWndParent = pWndParent;
  if ( pWndParent != nullptr )
  {
    v3 = AfxDynamicDownCast(pClass: &CMFCToolBar::classCMFCToolBar, pObject: pWndParent);
    if ( v3 != nullptr && ((int (__thiscall *)(CObject *))v3->__vftable[71].Serialize)(a1: v3) != 0 )
      this->m_bExtraSize = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103EB735
// Name: public: virtual int CMFCToolBarButton::IsFirstInGroup(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCToolBarButton::IsFirstInGroup(CMFCToolBarButton *this)
{
  CMFCToolBar *v2; // eax
  CMFCToolBar *v3; // esi
  int v5; // ebx
  CMFCToolBarButton *Button; // eax
  BOOL bIsFirstInGroup; // [esp+8h] [ebp-4h]

  v2 = (CMFCToolBar *)AfxDynamicDownCast(pClass: &CMFCToolBar::classCMFCToolBar, pObject: this->m_pWndParent);
  v3 = v2;
  if ( v2 == nullptr || this == v2->m_pCustomizeBtn )
    return false;
  bIsFirstInGroup = true;
  v5 = 0;
  if ( CMFCToolBar::GetCount(this: v2) <= 0 )
    return false;
  while ( 1 )
  {
    Button = CMFCToolBar::GetButton(this: v3, nIndex: v5);
    if ( Button == this )
      break;
    if ( Button->m_bVisible != 0 )
      bIsFirstInGroup = Button->m_bWrap != 0 || (Button->m_nStyle & 1) != 0 || Button->GetHwnd(this: Button) != nullptr;
    if ( ++v5 >= CMFCToolBar::GetCount(this: v3) )
      return false;
  }
  return bIsFirstInGroup;
}

//------------------------------------------------------------------------------
// Address: 0x103EB7C2
// Name: public: virtual int CMFCToolBarButton::IsLastInGroup(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolBar *__thiscall CMFCToolBarButton::IsLastInGroup(CMFCToolBarButton *this)
{
  CMFCToolBar *result; // eax
  CMFCToolBar *v3; // edi
  CMFCToolBarButton *m_pCustomizeBtn; // esi
  BOOL v5; // ebx
  int Count; // eax
  int v7; // esi
  CMFCToolBarButton *Button; // eax

  result = (CMFCToolBar *)AfxDynamicDownCast(pClass: &CMFCToolBar::classCMFCToolBar, pObject: this->m_pWndParent);
  v3 = result;
  if ( result != nullptr )
  {
    m_pCustomizeBtn = result->m_pCustomizeBtn;
    if ( this == m_pCustomizeBtn )
      return nullptr;
    v5 = true;
    Count = CMFCToolBar::GetCount(this: result);
    if ( m_pCustomizeBtn != nullptr )
      --Count;
    v7 = Count - 1;
    if ( Count - 1 < 0 )
      return nullptr;
    while ( 1 )
    {
      Button = CMFCToolBar::GetButton(this: v3, nIndex: v7);
      if ( Button == this )
        break;
      if ( Button->m_bVisible != 0 )
        v5 = (Button->m_nStyle & 1) != 0 || Button->GetHwnd(this: Button) != nullptr;
      if ( --v7 < 0 )
        return nullptr;
    }
    return (CMFCToolBar *)(v5 || Button->m_bWrap != 0);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103EB848
// Name: public: virtual int CMFCToolBarButton::OnToolHitTest(class CWnd const __near *,struct tagTOOLINFOA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarButton::OnToolHitTest(CMFCToolBarButton *this, CWnd *pWnd, tagTOOLINFOA *pTI)
{
  CFrameWnd *TopLevelFrame; // eax
  CObject *v5; // edi
  CObject *v6; // eax
  CObject *v8; // eax
  CObject *v9; // eax

  if ( pWnd != nullptr )
  {
    TopLevelFrame = (CFrameWnd *)g_pTopLevelFrame;
    if ( g_pTopLevelFrame == nullptr )
      TopLevelFrame = CWnd::GetTopLevelFrame(this: pWnd);
  }
  else
  {
    TopLevelFrame = (CFrameWnd *)AfxGetMainWnd();
  }
  v5 = TopLevelFrame;
  v6 = AfxDynamicDownCast(pClass: &CMDIFrameWndEx::classCMDIFrameWndEx, pObject: TopLevelFrame);
  if ( v6 != nullptr )
    return ((int (__thiscall *)(CObject *, CMFCToolBarButton *, tagTOOLINFOA *))v6->__vftable[41].GetRuntimeClass)(
             a1: v6,
             a2: this,
             a3: pTI);
  v8 = AfxDynamicDownCast(pClass: &CFrameWndEx::classCFrameWndEx, pObject: v5);
  if ( v8 != nullptr )
    return ((int (__thiscall *)(CObject *, CMFCToolBarButton *, tagTOOLINFOA *))v8->__vftable[39].dtr_CObject)(
             a1: v8,
             a2: this,
             a3: pTI);
  v9 = AfxDynamicDownCast(pClass: &COleIPFrameWndEx::classCOleIPFrameWndEx, pObject: nullptr);
  if ( v9 != nullptr )
    return ((int (__thiscall *)(CObject *, CMFCToolBarButton *, tagTOOLINFOA *))v9->__vftable[41].Serialize)(
             a1: v9,
             a2: this,
             a3: pTI);
  v8 = AfxDynamicDownCast(pClass: &CFrameWndEx::classCFrameWndEx, pObject: v5);
  if ( v8 != nullptr )
    return ((int (__thiscall *)(CObject *, CMFCToolBarButton *, tagTOOLINFOA *))v8->__vftable[39].dtr_CObject)(
             a1: v8,
             a2: this,
             a3: pTI);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103EB8EA
// Name: public: static int CMFCToolBar::GetDefaultImage(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall CMFCToolBar::GetDefaultImage(unsigned int uiID)
{
  if ( CMap<CWnd *,CWnd *,CImageList *,CImageList *>::Lookup(
         this: (CMap<unsigned int,unsigned int,CPane *,CPane *> *)&CMFCToolBar::m_DefaultImages,
         key: uiID,
         rValue: (CPane **)&uiID) != 0 )
    return uiID;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x103EB910
// Name: public: CMFCToolBarButton::CMFCToolBarButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolBarButton *__thiscall CMFCToolBarButton::CMFCToolBarButton(CMFCToolBarButton *this)
{
  CAfxStringMgr *StringManager; // eax
  CAfxStringMgr *v3; // eax

  this->__vftable = (CMFCToolBarButton_vtbl *)&CMFCToolBarButton::`vftable';
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strText, pStringMgr: StringManager);
  v3 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strTextCustom, pStringMgr: v3);
  this->m_rect.left = 0;
  this->m_rect.top = 0;
  this->m_rect.right = 0;
  this->m_rect.bottom = 0;
  this->m_sizeText.cx = 0;
  this->m_sizeText.cy = 0;
  CMFCToolBarButton::Initialize(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103EB956
// Name: public: virtual CMFCToolBarButton::~CMFCToolBarButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarButton::~CMFCToolBarButton(CMFCToolBarButton *this)
{
  ATL::CStringData *v2; // ecx

  v2 = (ATL::CStringData *)(this->m_strTextCustom.m_pszData - 16);
  this->__vftable = (CMFCToolBarButton_vtbl *)&CMFCToolBarButton::`vftable';
  ATL::CStringData::Release(this: v2);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strText.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x103EB978
// Name: public: virtual int CMFCToolBarButton::OnDrawOnCustomizeList(class CDC __near *,class CRect const __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarButton::OnDrawOnCustomizeList(
        CMFCToolBarButton *this,
        CDC *pDC,
        const CRect *rect,
        int bSelected)
{
  int m_bText; // eax
  int m_bUserButton; // eax
  CMFCVisualManager *Instance; // eax
  int v8; // eax
  CMFCVisualManager *v9; // eax
  CMFCVisualManager *v10; // eax
  CMFCVisualManager *v11; // eax
  int v12; // eax
  int m_iUserImage; // eax
  CMFCToolBarImages *v14; // esi
  CDC *v15; // esi
  int cx; // edx
  int cy; // ecx
  long double m_dblRibbonImageScale; // st6
  int x; // ecx
  long double v20; // st7
  int v21; // eax
  int v22; // eax
  int v23; // ecx
  int m_iImage; // eax
  int v25; // eax
  int v26; // edi
  int v27; // edi
  int v28; // eax
  CSize v30; // [esp+Ch] [ebp-68h] BYREF
  int bText; // [esp+14h] [ebp-60h]
  CRect rectLeftBtn; // [esp+18h] [ebp-5Ch] BYREF
  CSize sizeButton; // [esp+28h] [ebp-4Ch]
  int iWidth; // [esp+30h] [ebp-44h]
  CSize sizeMenuImage; // [esp+34h] [ebp-40h] BYREF
  int bDrawImageShadow; // [esp+3Ch] [ebp-38h]
  int bFadeImage; // [esp+40h] [ebp-34h]
  CPoint pt; // [esp+44h] [ebp-30h]
  CDC *pDCDest; // [esp+4Ch] [ebp-28h]
  CRect rectText; // [esp+50h] [ebp-24h] BYREF
  CRect rectImage; // [esp+60h] [ebp-14h] BYREF

  pDCDest = pDC;
  m_bText = this->m_bText;
  this->m_bText = 0;
  bText = m_bText;
  m_bUserButton = this->m_bUserButton;
  pt.y = (int)rect;
  bFadeImage = (int)&CMFCToolBar::m_Images;
  if ( m_bUserButton != 0 )
  {
    bFadeImage = (int)CMFCToolBar::m_pUserImages;
  }
  else if ( CMFCToolBar::m_MenuImages.m_iCount == CMFCToolBar::m_Images.m_iCount )
  {
    bFadeImage = (int)&CMFCToolBar::m_MenuImages;
  }
  bDrawImageShadow = 0;
  if ( afxUserToolsManager != nullptr && m_bUserButton == 0 )
    bDrawImageShadow = (int)CUserToolsManager::FindTool(this: afxUserToolsManager, uiCmdId: this->m_nID);
  CMFCToolBar::GetMenuImageSize(result: &sizeMenuImage);
  rectImage = *rect;
  sizeButton.cx = sizeMenuImage.cx + 6;
  if ( bSelected != 0 )
  {
    Instance = CMFCVisualManager::GetInstance();
    if ( Instance->IsHighlightWholeMenuItem(this: Instance) == 0 )
    {
      v8 = this->m_bUserButton != 0 ? this->m_iUserImage : this->m_iImage;
      if ( v8 >= 0 && bFadeImage != 0 )
      {
        rectImage.left += sizeButton.cx;
        rectLeftBtn = *(CRect *)pt.y;
        rectLeftBtn.right = rectImage.left;
        v9 = CMFCVisualManager::GetInstance();
        ((void (__thiscall *)(CMFCVisualManager *, CDC *, CMFCToolBarButton *, int, int, int, int, int))v9->OnFillButtonInterior)(
          a1: v9,
          a2: pDCDest,
          a3: this,
          a4: rectLeftBtn.left,
          a5: rectLeftBtn.top,
          a6: rectLeftBtn.right,
          a7: rectLeftBtn.bottom,
          a8: 2);
        v10 = CMFCVisualManager::GetInstance();
        ((void (__thiscall *)(CMFCVisualManager *, CDC *, CMFCToolBarButton *, int, int, int, int, int))v10->OnDrawButtonBorder)(
          a1: v10,
          a2: pDCDest,
          a3: this,
          a4: rectLeftBtn.left,
          a5: rectLeftBtn.top,
          a6: rectLeftBtn.right,
          a7: rectLeftBtn.bottom,
          a8: 2);
      }
    }
  }
  v11 = CMFCVisualManager::GetInstance();
  v12 = ((int (__thiscall *)(CMFCVisualManager *, CDC *, int, int, int, int, int))v11->OnFillCommandsListBackground)(
          a1: v11,
          a2: pDCDest,
          a3: rectImage.left,
          a4: rectImage.top,
          a5: rectImage.right,
          a6: rectImage.bottom,
          a7: bSelected);
  rectText.left = *(_DWORD *)pt.y;
  rectText.top = *(_DWORD *)(pt.y + 4);
  rectText.right = *(_DWORD *)(pt.y + 8);
  v30.cy = v12;
  rectText.bottom = *(_DWORD *)(pt.y + 12);
  rectText.left += sizeMenuImage.cx + 10;
  iWidth = sizeButton.cx;
  if ( this->m_bUserButton != 0 )
    m_iUserImage = this->m_iUserImage;
  else
    m_iUserImage = this->m_iImage;
  if ( m_iUserImage < 0 )
    goto LABEL_58;
  v14 = (CMFCToolBarImages *)bFadeImage;
  if ( bFadeImage == 0 )
    goto LABEL_58;
  if ( bDrawImageShadow != 0 )
  {
    rectImage = *(CRect *)pt.y;
    v15 = pDCDest;
    rectImage.right = sizeButton.cx + rectImage.left;
    CUserTool::DrawToolIcon(this: (CUserTool *)bDrawImageShadow, pDC: pDCDest, &rectImage);
    goto LABEL_59;
  }
  if ( bSelected == 0 && CMFCVisualManager::GetInstance()->m_bFadeInactiveImage != 0 )
  {
    bFadeImage = 1;
LABEL_30:
    bDrawImageShadow = 0;
    goto LABEL_31;
  }
  bFadeImage = 0;
  if ( bSelected == 0 )
    goto LABEL_30;
  if ( CMFCVisualManager::GetInstance()->m_bShadowHighlightedImage == 0 )
    goto LABEL_30;
  if ( afxGlobalData.m_bIsWhiteHighContrast != 0 )
    goto LABEL_30;
  bDrawImageShadow = 1;
  if ( afxGlobalData.m_bIsBlackHighContrast != 0 )
    goto LABEL_30;
LABEL_31:
  cx = 0;
  cy = 0;
  if ( afxGlobalData.m_bIsRibbonImageScale != 0 )
    m_dblRibbonImageScale = afxGlobalData.m_dblRibbonImageScale;
  else
    m_dblRibbonImageScale = 1.0;
  if ( m_dblRibbonImageScale != 1.0 && CMFCToolBar::m_bDontScaleImages == 0 )
  {
    cx = sizeMenuImage.cx;
    cy = sizeMenuImage.cy;
  }
  CMFCToolBarImages::PrepareDrawImage(
    this: v14,
    ds: (tagAFXDrawState *)&rectImage.top,
    sizeImageDest: (CSize)__PAIR64__(cy, cx),
    bFadeInactive: bFadeImage);
  x = *(_DWORD *)pt.y + 3;
  pt.y = *(_DWORD *)(pt.y + 4) + 3;
  if ( afxGlobalData.m_bIsRibbonImageScale != 0 )
    v20 = afxGlobalData.m_dblRibbonImageScale;
  else
    v20 = 1.0;
  if ( 1.0 != v20 && CMFCToolBar::m_bDontScaleImages != 0 )
  {
    rectLeftBtn.bottom = v14->m_sizeImage.cy;
    if ( (sizeMenuImage.cx - v14->m_sizeImage.cx) / 2 >= 0 )
    {
      rectLeftBtn.bottom = v14->m_sizeImage.cy;
      v21 = (sizeMenuImage.cx - v14->m_sizeImage.cx) / 2;
    }
    else
    {
      v21 = 0;
    }
    x += v21;
    rectLeftBtn.right = v14->m_sizeImage.cx;
    if ( (sizeMenuImage.cy - v14->m_sizeImage.cy) / 2 >= 0 )
    {
      rectLeftBtn.right = v14->m_sizeImage.cx;
      v22 = (sizeMenuImage.cy - v14->m_sizeImage.cy) / 2;
    }
    else
    {
      v22 = 0;
    }
    pt.y += v22;
  }
  if ( bDrawImageShadow != 0 )
  {
    v23 = x + 1;
    ++pt.y;
    pt.x = v23;
    if ( this->m_bUserButton != 0 )
      m_iImage = this->m_iUserImage;
    else
      m_iImage = this->m_iImage;
    CMFCToolBarImages::Draw(
      this: v14,
      pDCDest,
      xDest: v23,
      yDest: pt.y,
      iImage: m_iImage,
      bHilite: 0,
      bDisabled: 0,
      bIndeterminate: 0,
      bShadow: 1,
      bInactive: 0,
      alphaSrc: 0xFFu);
    pt.x -= 2;
    pt.y -= 2;
    x = pt.x;
  }
  if ( this->m_bUserButton != 0 )
    v25 = this->m_iUserImage;
  else
    v25 = this->m_iImage;
  CMFCToolBarImages::Draw(
    this: v14,
    pDCDest,
    xDest: x,
    yDest: pt.y,
    iImage: v25,
    bHilite: 0,
    bDisabled: 0,
    bIndeterminate: 0,
    bShadow: 0,
    bInactive: bFadeImage,
    alphaSrc: 0xFFu);
  CMFCToolBarImages::EndDrawImage(this: v14, ds: (tagAFXDrawState *)&rectImage.top);
LABEL_58:
  v15 = pDCDest;
LABEL_59:
  if ( *((_DWORD *)this->m_strText.m_pszData - 3) != 0 )
  {
    v26 = v15->SetTextColor(this: v15, a2: v30.cy);
    CDC::SetBkMode(this: v15, nBkMode: 1);
    v15->DrawTextA(
      this: v15,
      a2: this->m_strText.m_pszData,
      a3: *((_DWORD *)this->m_strText.m_pszData - 3),
      a4: &rectText,
      a5: 36u);
    v15->SetTextColor(this: v15, a2: v26);
    v27 = rectText.right - rectText.left;
    if ( v27 >= CDC::GetTextExtent(this: v15, result: (CSize *)&rectLeftBtn.right, str: &this->m_strText)->cx )
      v28 = CDC::GetTextExtent(this: v15, result: &v30, str: &this->m_strText)->cx;
    else
      v28 = rectText.right - rectText.left;
    iWidth = sizeButton.cx + v28;
  }
  this->m_bText = bText;
  return iWidth;
}

//------------------------------------------------------------------------------
// Address: 0x103EBD33
// Name: public: static class CObject __near * CMFCToolBarButton::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolBarButton *__stdcall CMFCToolBarButton::CreateObject()
{
  CMFCToolBarButton *v0; // ecx
  CMFCToolBarButton *result; // eax

  v0 = (CMFCToolBarButton *)operator new(nSize: 0x70u);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCToolBarButton::CMFCToolBarButton(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103EBD60
// Name: public: static unsigned short CMFCToolBarButton::GetClipboardFormat(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int16 __stdcall CMFCToolBarButton::GetClipboardFormat()
{
  ATL::CStringData *v0; // eax
  char *m_pszData; // esi
  CWnd *MainWnd; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strFormat; // [esp+10h] [ebp-10h] BYREF
  int v5; // [esp+1Ch] [ebp-4h]

  if ( CMFCToolBarButton::m_cFormat == 0 )
  {
    v0 = ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)CMFCToolBarButton::m_strClipboardFormatName.m_pszData - 1);
    m_pszData = (char *)&v0[1];
    strFormat.m_pszData = (char *)&v0[1];
    v5 = 0;
    if ( v0->nDataLength == 0 )
    {
      MainWnd = AfxGetMainWnd();
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
        this: &strFormat,
        pszFormat: "ToolbarButton%p",
        MainWnd);
      m_pszData = strFormat.m_pszData;
    }
    CMFCToolBarButton::m_cFormat = RegisterClipboardFormatA(lpszFormat: m_pszData);
    if ( CMFCToolBarButton::m_cFormat == 0 )
      AfxThrowInvalidArgException();
    ATL::CStringData::Release(this: (ATL::CStringData *)m_pszData - 1);
  }
  return CMFCToolBarButton::m_cFormat;
}

//------------------------------------------------------------------------------
// Address: 0x103EBDDA
// Name: public: static class CMFCToolBarButton __near * CMFCToolBarButton::CreateFromOleData(class COleDataObject __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolBarButton *__stdcall CMFCToolBarButton::CreateFromOleData(COleDataObject *pDataObject)
{
  unsigned __int16 ClipboardFormat; // ax
  CFile *FileData; // eax
  CFile *v3; // edi
  CRuntimeClass *v4; // eax
  CObject *Object; // esi
  bool v6; // zf
  CObject v7; // eax
  CArchive ar; // [esp+10h] [ebp-68h] BYREF
  int __afx_condVal; // [esp+64h] [ebp-14h]
  int v11; // [esp+74h] [ebp-4h]

  if ( pDataObject != nullptr
    && COleDataObject::IsDataAvailable(this: pDataObject, cfFormat: CMFCToolBarButton::m_cFormat, lpFormatEtc: nullptr) )
  {
    __afx_condVal = 0;
    v11 = 0;
    ClipboardFormat = CMFCToolBarButton::GetClipboardFormat();
    FileData = COleDataObject::GetFileData(this: pDataObject, cfFormat: ClipboardFormat, lpFormatEtc: nullptr);
    v3 = FileData;
    if ( FileData == nullptr )
      return nullptr;
    CArchive::CArchive(this: &ar, pFile: FileData, nMode: 1u, nBufSize: 4096, lpBuf: nullptr);
    LOBYTE(v11) = 1;
    v4 = CArchive::ReadClass(this: &ar, pClassRefRequested: nullptr, pSchema: nullptr, pObTag: nullptr);
    if ( v4 != nullptr )
    {
      Object = CRuntimeClass::CreateObject(this: v4);
      __afx_condVal = (int)Object;
      if ( Object != nullptr )
      {
        v6 = CObject::IsKindOf(this: Object, pClass: &CMFCToolBarButton::classCMFCToolBarButton) == 0;
        v7.__vftable = Object->__vftable;
        if ( v6 )
        {
          ((void (__thiscall *)(CObject *, int))v7.dtr_CObject)(a1: Object, a2: 1);
          Object = nullptr;
          __afx_condVal = 0;
        }
        else
        {
          v7.Serialize(this: Object, a2: &ar);
        }
        CArchive::Close(this: &ar);
        ((void (__thiscall *)(CFile *, int))v3->dtr_CObject)(a1: v3, a2: 1);
        LOBYTE(v11) = 0;
        CArchive::~CArchive(this: &ar);
        return (CMFCToolBarButton *)Object;
      }
    }
  }
  AfxThrowInvalidArgException();
}

//------------------------------------------------------------------------------
// Address: 0x103EBF1D
// Name: public: virtual struct tagSIZE CMFCToolBarButton::OnCalculateSize(class CDC __near *,class CSize const __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDC *__thiscall CMFCToolBarButton::OnCalculateSize(
        CMFCToolBarButton *this,
        CDC *pDC,
        const CSize *sizeDefault,
        int *bHorz,
        int a5)
{
  CDC *v5; // edx
  bool v7; // zf
  int v8; // eax
  int v9; // edi
  int m_iImage; // eax
  CMFCVisualManager *Instance; // eax
  CSize *v12; // eax
  int cx; // ecx
  int cy; // eax
  char *m_pszData; // eax
  char *v16; // eax
  int v17; // ecx
  int v18; // edx
  char *v19; // ecx
  int v20; // eax
  int v21; // edi
  CSize v23; // [esp+10h] [ebp-34h] BYREF
  CDC *v24; // [esp+18h] [ebp-2Ch]
  int v25; // [esp+1Ch] [ebp-28h]
  int v26; // [esp+20h] [ebp-24h]
  int v27; // [esp+24h] [ebp-20h] BYREF
  int v28; // [esp+28h] [ebp-1Ch]
  int v29; // [esp+2Ch] [ebp-18h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+30h] [ebp-14h] BYREF
  int v31; // [esp+40h] [ebp-4h]

  v5 = pDC;
  v24 = pDC;
  v23.cy = (int)sizeDefault;
  if ( this->m_bVisible != 0 )
  {
    v7 = (this->m_nStyle & 1) == 0;
    v8 = bHorz[1];
    v25 = *bHorz;
    v26 = v8;
    if ( v7 )
    {
      v9 = 1;
      if ( CMFCToolBarButton::IsDrawImage(this) == 0
        || (this->m_bUserButton == 0 ? (m_iImage = this->m_iImage) : (m_iImage = this->m_iUserImage), m_iImage < 0) )
      {
        v9 = 0;
        if ( this->m_bExtraSize != 0 )
        {
          Instance = CMFCVisualManager::GetInstance();
          v12 = Instance->GetButtonExtraBorder(this: Instance, result: (CSize *)&v29);
        }
        else
        {
          v29 = 0;
          str.m_pszData = nullptr;
          v12 = (CSize *)&v29;
        }
        cx = v12->cx;
        cy = v12->cy;
        if ( a5 != 0 )
          v25 = cx;
        else
          v26 = cy;
      }
      this->m_sizeText.cx = 0;
      m_pszData = this->m_strText.m_pszData;
      this->m_sizeText.cy = 0;
      if ( *((_DWORD *)m_pszData - 3) != 0 )
      {
        if ( this->m_bTextBelow != 0 && a5 != 0 )
        {
          v16 = (char *)bHorz[1];
          v17 = 3 * *bHorz;
          v27 = 0;
          v28 = 0;
          v29 = v17;
          str.m_pszData = v16;
          v18 = 1025;
          if ( CMFCToolBarButton::m_bWrapText != 0 )
            v18 = 1041;
          (*(void (__thiscall **)(int, char *, _DWORD, int *, int))(*(_DWORD *)v23.cy + 104))(
            a1: v23.cy,
            a2: this->m_strText.m_pszData,
            a3: *((_DWORD *)this->m_strText.m_pszData - 3),
            a4: &v27,
            a5: v18);
          v19 = &str.m_pszData[-v28];
          this->m_sizeText.cx = v29 - v27;
          this->m_sizeText.cx += 6;
          v20 = this->m_sizeText.cx;
          this->m_sizeText.cy = (int)v19;
          if ( v25 > v20 )
            v20 = v25;
          v25 = v20 + 12;
          v26 += (int)(v19 + 1);
        }
        else if ( this->m_bText != 0 )
        {
          str.m_pszData = (char *)&ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)m_pszData - 1)[1];
          v31 = 0;
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Replace(
            this: &str,
            pszOld: "&&",
            pszNew: strDummyAmpSeq_0.m_pszData);
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Remove(this: &str, chRemove: 38);
          ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Replace(
            this: &str,
            pszOld: strDummyAmpSeq_0.m_pszData,
            pszNew: "&");
          v21 = CDC::GetTextExtent(this: (CDC *)v23.cy, result: &v23, &str)->cx + (v9 != 0 ? 6 : 9);
          if ( a5 != 0 )
            v25 += v21;
          else
            v26 += v21;
          ATL::CStringData::Release(this: (ATL::CStringData *)str.m_pszData - 1);
        }
      }
      v5 = v24;
    }
    else if ( a5 != 0 )
    {
      if ( this->m_iImage <= 0 )
        v25 = 8;
      else
        v25 = this->m_iImage;
    }
    else
    {
      v26 = 8;
    }
    v5->__vftable = (CDC_vtbl *)v25;
    v5->m_hDC = (HDC__ *)v26;
  }
  else
  {
    pDC->__vftable = nullptr;
    pDC->m_hDC = nullptr;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x103EC10F
// Name: public: virtual int CMFCToolBarButton::PrepareDrag(class COleDataSource __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarButton::PrepareDrag(CMFCToolBarButton *this, COleDataSource *srcItem)
{
  CMFCToolBarButton_vtbl *v4; // eax
  const CRuntimeClass *v5; // eax
  HBITMAP__ *v6; // esi
  unsigned __int16 ClipboardFormat; // ax
  CArchive ar; // [esp+10h] [ebp-98h] BYREF
  CSharedFile globFile; // [esp+58h] [ebp-50h] BYREF
  int v10; // [esp+A4h] [ebp-4h]

  if ( this->CanBeStored(this) != 0 )
  {
    v10 = 0;
    CSharedFile::CSharedFile(this: &globFile, nAllocFlags: 2u, nGrowBytes: 0x1000u);
    LOBYTE(v10) = 1;
    CArchive::CArchive(this: &ar, pFile: &globFile, nMode: 0, nBufSize: 4096, lpBuf: nullptr);
    v4 = this->__vftable;
    LOBYTE(v10) = 2;
    v5 = v4->GetRuntimeClass(this);
    if ( v5 == nullptr )
      AfxThrowInvalidArgException();
    CArchive::WriteClass(this: &ar, pClassRef: v5);
    this->Serialize(this, a2: &ar);
    CArchive::Close(this: &ar);
    v6 = (HBITMAP__ *)CSharedFile::Detach(this: &globFile);
    ClipboardFormat = CMFCToolBarButton::GetClipboardFormat();
    COleDataSource::CacheGlobalData(this: srcItem, cfFormat: ClipboardFormat, hGlobal: v6, lpFormatEtc: nullptr);
    LOBYTE(v10) = 1;
    CArchive::~CArchive(this: &ar);
    LOBYTE(v10) = 0;
    CSharedFile::~CSharedFile(this: &globFile);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103EC1FD
// Name: public: virtual void CMFCToolBarButton::CopyFrom(class CMFCToolBarButton const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarButton::CopyFrom(CMFCToolBarButton *this, const CMFCToolBarButton *src)
{
  int m_iUserImage; // eax
  unsigned int m_dwdItemData; // eax

  this->m_nID = src->m_nID;
  this->m_bLocked = src->m_bLocked;
  this->m_bUserButton = src->m_bUserButton;
  this->m_nStyle = src->m_nStyle;
  if ( src->m_bUserButton != 0 )
    m_iUserImage = src->m_iUserImage;
  else
    m_iUserImage = src->m_iImage;
  this->SetImage(this, a2: m_iUserImage);
  ATL::CSimpleStringT<char,0>::operator=(this: &this->m_strText, strSrc: (ATL::CStringData *)&src->m_strText);
  this->m_bText = src->m_bText;
  this->m_bImage = src->m_bImage;
  this->m_bWrap = src->m_bWrap;
  ATL::CSimpleStringT<char,0>::operator=(
    this: &this->m_strTextCustom,
    strSrc: (ATL::CStringData *)&src->m_strTextCustom);
  this->m_bVisible = src->m_bVisible;
  m_dwdItemData = src->m_dwdItemData;
  this->m_bDragFromCollection = 0;
  this->m_dwdItemData = m_dwdItemData;
}

//------------------------------------------------------------------------------
// Address: 0x103EC278
// Name: public: virtual void CMFCToolBarButton::OnDraw(class CDC __near *,class CRect const __near &,class CMFCToolBarImages __near *,int,int,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarButton::OnDraw(
        CMFCToolBarButton *this,
        CDC *pDC,
        const CRect *rect,
        CMFCToolBarImages *pImages,
        int bHorz,
        int bCustomizeMode,
        int bHighlight,
        int bDrawBorder,
        int bGrayDisabledButtons)
{
  int cy; // ecx
  CMFCVisualManager *Instance; // eax
  CSize *p_result; // eax
  CMFCToolBarButton *v13; // edi
  int v14; // esi
  int IsDrawImage; // eax
  int m_bTextBelow; // ecx
  int v17; // eax
  int right; // eax
  int bottom; // eax
  int v20; // edi
  bool v21; // zf
  CMFCVisualManager *v22; // eax
  CMFCVisualManager *v23; // eax
  unsigned int m_nStyle; // eax
  int m_iUserImage; // eax
  int m_iImage; // eax
  int v27; // edi
  int v28; // eax
  BOOL v29; // ecx
  int v30; // eax
  CMFCVisualManager *v31; // eax
  CMFCToolBarButton *v32; // esi
  unsigned int v33; // eax
  int v34; // esi
  int cx; // ecx
  int v36; // eax
  int v37; // eax
  CMFCVisualManager *v38; // eax
  int v39; // eax
  const char *m_pszData; // ecx
  int v41; // eax
  CDC_vtbl *v42; // edx
  ATL::CStringData *v43; // eax
  int v44; // edi
  int v45; // eax
  COLORREF TextColor; // eax
  CMFCToolBarButton *v47; // edi
  unsigned int v48; // eax
  CMFCVisualManager *v49; // eax
  int v50; // [esp-Ch] [ebp-DCh]
  ATL::CStringData *v51; // [esp-4h] [ebp-D4h]
  CMFCVisualManager::AFX_BUTTON_STATE v52; // [esp-4h] [ebp-D4h]
  unsigned int v53; // [esp-4h] [ebp-D4h]
  HDC__ *m_hAttribDC; // [esp-4h] [ebp-D4h]
  HDC__ *v55; // [esp-4h] [ebp-D4h]
  int v56; // [esp-4h] [ebp-D4h]
  int v57; // [esp+10h] [ebp-C0h]
  int v58; // [esp+10h] [ebp-C0h]
  CSize result; // [esp+18h] [ebp-B8h] BYREF
  CMFCToolBarImages *v60; // [esp+20h] [ebp-B0h]
  CPoint v61; // [esp+24h] [ebp-ACh] BYREF
  char v62; // [esp+2Ch] [ebp-A4h] BYREF
  int v63; // [esp+30h] [ebp-A0h]
  CUserTool *Tool; // [esp+34h] [ebp-9Ch]
  ATL::CStringData str; // [esp+38h] [ebp-98h] BYREF
  ATL::CSimpleStringT<char,0> v66; // [esp+48h] [ebp-88h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v67; // [esp+4Ch] [ebp-84h] BYREF
  int bInactive; // [esp+50h] [ebp-80h]
  CMFCToolBarButton *v69; // [esp+54h] [ebp-7Ch]
  tagTEXTMETRICA tm; // [esp+58h] [ebp-78h] BYREF
  tagRECT rc; // [esp+90h] [ebp-40h] BYREF
  tagRECT v72; // [esp+A0h] [ebp-30h] BYREF
  CRect rectImage; // [esp+B0h] [ebp-20h] BYREF
  int v74; // [esp+CCh] [ebp-4h]

  this->m_bHorz = bHorz;
  v69 = this;
  v60 = pImages;
  CMFCToolBarButton::FillInterior(this, pDC, rect, bHighlight, bMenuImage: 0);
  if ( pImages != nullptr )
  {
    v61.x = pImages->m_sizeImageDest.cx;
    cy = pImages->m_sizeImageDest.cy;
  }
  else
  {
    cy = 0;
    v61.x = 0;
  }
  v61.y = cy;
  Tool = nullptr;
  if ( afxUserToolsManager != nullptr && this->m_bUserButton == 0 )
    Tool = CUserToolsManager::FindTool(this: afxUserToolsManager, uiCmdId: this->m_nID);
  rc = rect->tagRECT;
  if ( v69->m_bExtraSize != 0 )
  {
    Instance = CMFCVisualManager::GetInstance();
    p_result = Instance->GetButtonExtraBorder(this: Instance, result: (CSize *)&v62);
  }
  else
  {
    result.cx = 0;
    result.cy = 0;
    p_result = &result;
  }
  InflateRect(lprc: &rc, dx: p_result->cx / -2, dy: p_result->cy / -2);
  v13 = v69;
  str.nDataLength = rc.left;
  v66.m_pszData = (char *)rc.top;
  v14 = 0;
  v51 = (ATL::CStringData *)(v69->m_strText.m_pszData - 16);
  bInactive = 0;
  str.pStringMgr = (ATL::IAtlStringMgr *)&ATL::CSimpleStringT<char,0>::CloneData(pData: v51)[1];
  v74 = 0;
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Replace(
    this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&str,
    pszOld: "&&",
    pszNew: strDummyAmpSeq_0.m_pszData);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Remove(
    this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&str,
    chRemove: 38);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Replace(
    this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&str,
    pszOld: strDummyAmpSeq_0.m_pszData,
    pszNew: "&");
  CDC::GetTextExtent(this: pDC, &result, (const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&str);
  if ( v13->m_bText != 0 && *((_DWORD *)v13->m_strText.m_pszData - 3) != 0 && (v13->m_bTextBelow == 0 || bHorz == 0) )
  {
    IsDrawImage = CMFCToolBarButton::IsDrawImage(this: v13);
    bInactive = (IsDrawImage != 0 ? 0 : 3) + result.cx;
  }
  m_bTextBelow = v13->m_bTextBelow;
  if ( m_bTextBelow != 0 )
  {
    if ( bHorz != 0 )
    {
      v67.m_pszData = (char *)(rc.right - rc.left);
      v17 = v61.y + 6;
      goto LABEL_24;
    }
    goto LABEL_20;
  }
  if ( bHorz == 0 )
  {
LABEL_20:
    right = rc.right;
    goto LABEL_21;
  }
  right = rc.right - bInactive;
LABEL_21:
  v67.m_pszData = (char *)(right - rc.left);
  bottom = rc.bottom;
  if ( bHorz == 0 )
    bottom = rc.bottom - bInactive;
  v17 = bottom - rc.top;
LABEL_24:
  bInactive = v17;
  v20 = (int)&v67.m_pszData[-v61.x] / 2;
  v63 = (v17 - v61.y) / 2;
  v72.right = 3;
  v72.bottom = 3;
  if ( v69->m_bText != 0 && *((_DWORD *)v69->m_strText.m_pszData - 3) != 0 && (m_bTextBelow == 0 || bHorz == 0) )
  {
    GetTextMetricsA(hdc: pDC->m_hAttribDC, lptm: &tm);
    if ( bHorz != 0 )
    {
      v20 -= 3;
      v72.bottom = (bInactive - tm.tmHeight - 1) / 2;
    }
    else
    {
      v63 -= 3;
      v72.right = (int)&v67.m_pszData[-tm.tmHeight + 1] / 2;
    }
  }
  if ( bHighlight == 0
    || bCustomizeMode != 0
    || v69->IsDroppedDown(this: v69) != 0
    || CMFCVisualManager::GetInstance()->m_bShadowHighlightedImage == 0
    || afxGlobalData.m_bIsWhiteHighContrast != 0
    || afxGlobalData.m_bIsBlackHighContrast != 0
    || (v21 = (v69->m_nStyle & 0x70000) == 0, v67.m_pszData = (char *)1, !v21) )
  {
    v67.m_pszData = nullptr;
  }
  if ( (v69->m_nStyle & 0x30000) != 0
    && bCustomizeMode == 0
    && CMFCVisualManager::GetInstance()->m_bShadowHighlightedImage == 0 )
  {
    v22 = CMFCVisualManager::GetInstance();
    if ( v22->IsOffsetPressedButton(this: v22) != 0 )
    {
      ++v20;
      ++v63;
      ++v72.bottom;
      if ( bHorz != 0 )
        ++v72.right;
      else
        --v72.right;
    }
  }
  if ( bHighlight != 0 || (v23 = CMFCVisualManager::GetInstance(), bInactive = 1, v23->m_bFadeInactiveImage == 0) )
    bInactive = 0;
  m_nStyle = v69->m_nStyle;
  v57 = 0;
  if ( (m_nStyle & 0x20000) == 0 && (m_nStyle & 0x40000) != 0 && bCustomizeMode == 0 )
    goto LABEL_73;
  if ( CMFCToolBarButton::IsDrawImage(this: v69) != 0 && v60 != nullptr )
  {
    if ( Tool != nullptr )
    {
      rectImage.left = v20 + str.nDataLength;
      rectImage.top = (int)&v66.m_pszData[v63];
      rectImage.bottom = (int)&v66.m_pszData[v63 + v61.y];
      rectImage.right = v20 + str.nDataLength + v61.x;
      CUserTool::DrawToolIcon(this: Tool, pDC, &rectImage);
    }
    else
    {
      str.nAllocLength = v20;
      str.nRefs = v63;
      if ( v67.m_pszData != nullptr )
      {
        ++str.nRefs;
        str.nAllocLength = v20 + 1;
        if ( v69->m_bUserButton != 0 )
          m_iUserImage = v69->m_iUserImage;
        else
          m_iUserImage = v69->m_iImage;
        CMFCToolBarImages::Draw(
          this: v60,
          pDCDest: pDC,
          xDest: str.nDataLength + str.nAllocLength,
          yDest: (int)&v66.m_pszData[str.nRefs],
          iImage: m_iUserImage,
          bHilite: 0,
          bDisabled: 0,
          bIndeterminate: 0,
          bShadow: 1,
          bInactive: 0,
          alphaSrc: 0xFFu);
        str.nAllocLength -= 2;
        str.nRefs -= 2;
      }
      if ( v69->m_bUserButton != 0 )
        m_iImage = v69->m_iUserImage;
      else
        m_iImage = v69->m_iImage;
      CMFCToolBarImages::Draw(
        this: v60,
        pDCDest: pDC,
        xDest: str.nDataLength + str.nAllocLength,
        yDest: (int)&v66.m_pszData[str.nRefs],
        iImage: m_iImage,
        bHilite: 0,
        bDisabled: 0,
        bIndeterminate: 0,
        bShadow: 0,
        bInactive,
        alphaSrc: 0xFFu);
    }
  }
  v57 = 1;
  if ( bCustomizeMode == 0 )
  {
LABEL_73:
    if ( (v69->m_nStyle & 0x40000) == 0 )
      goto LABEL_67;
LABEL_74:
    str.nRefs = 1;
    goto LABEL_68;
  }
  if ( v69->IsEditable(this: v69) == 0 )
    goto LABEL_74;
LABEL_67:
  str.nRefs = 0;
LABEL_68:
  if ( v57 == 0 && CMFCToolBarButton::IsDrawImage(this: v69) != 0 && v60 != nullptr )
  {
    if ( Tool != nullptr )
    {
      rectImage.left = v20 + str.nDataLength;
      rectImage.top = (int)&v66.m_pszData[v63];
      rectImage.bottom = (int)&v66.m_pszData[v63 + v61.y];
      rectImage.right = v20 + str.nDataLength + v61.x;
      CUserTool::DrawToolIcon(this: Tool, pDC, &rectImage);
    }
    else
    {
      if ( v67.m_pszData != nullptr )
      {
        v27 = v20 + 1;
        ++v63;
        if ( v69->m_bUserButton != 0 )
          v28 = v69->m_iUserImage;
        else
          v28 = v69->m_iImage;
        CMFCToolBarImages::Draw(
          this: v60,
          pDCDest: pDC,
          xDest: v27 + str.nDataLength,
          yDest: (int)&v66.m_pszData[v63],
          iImage: v28,
          bHilite: 0,
          bDisabled: 0,
          bIndeterminate: 0,
          bShadow: 1,
          bInactive: 0,
          alphaSrc: 0xFFu);
        v20 = v27 - 2;
        v63 -= 2;
      }
      v29 = str.nRefs != 0 && bGrayDisabledButtons != 0;
      if ( v69->m_bUserButton != 0 )
        v30 = v69->m_iUserImage;
      else
        v30 = v69->m_iImage;
      CMFCToolBarImages::Draw(
        this: v60,
        pDCDest: pDC,
        xDest: str.nDataLength + v20,
        yDest: (int)&v66.m_pszData[v63],
        iImage: v30,
        bHilite: 0,
        bDisabled: v29,
        bIndeterminate: 0,
        bShadow: 0,
        bInactive,
        alphaSrc: 0xFFu);
    }
  }
  if ( v69->m_bTextBelow != 0 && bHorz != 0 || v69->m_bText != 0 && *((_DWORD *)v69->m_strText.m_pszData - 3) != 0 )
  {
    if ( bHighlight != 0 )
    {
      v14 = 2;
    }
    else if ( (v69->m_nStyle & 0x30000) != 0 )
    {
      v14 = 1;
    }
    v31 = CMFCVisualManager::GetInstance();
    v52 = v14;
    v32 = v69;
    v33 = v31->GetToolbarButtonTextColor(this: v31, a2: v69, a3: v52);
    pDC->SetTextColor(this: pDC, a2: v33);
    v66.m_pszData = (char *)&ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)v32->m_strText.m_pszData - 1)[1];
    rectImage = (CRect)rc;
    v34 = v69->m_bTextBelow;
    LOBYTE(v74) = 1;
    if ( v34 != 0 && bHorz != 0 )
    {
      v72.bottom += v61.y + 3;
      v67.m_pszData = (char *)1;
      if ( CMFCToolBarButton::m_bWrapText != 0 )
        v67.m_pszData = (char *)17;
      cx = v69->m_sizeText.cx;
      rectImage.left = v72.right + (rc.left + rc.right - cx) / 2;
      rectImage.right = (rc.left + cx + rc.right) / 2;
    }
    else
    {
      if ( CMFCToolBarButton::IsDrawImage(this: v69) != 0 )
      {
        v36 = CMFCToolBar::m_bLargeIcons != 0 ? 6 : 0;
        if ( bHorz != 0 )
          v72.right += v36 + v61.x;
        else
          v72.bottom += v36 + v61.y;
        v37 = v72.right + str.nDataLength + 3;
      }
      else
      {
        v37 = str.nDataLength + 4;
      }
      rectImage.left = v37;
      v67.m_pszData = (char *)32;
    }
    if ( bHorz != 0 )
    {
      rectImage.top += v72.bottom;
      if ( v34 != 0 && v69->m_bExtraSize != 0 )
      {
        v38 = CMFCVisualManager::GetInstance();
        v39 = (int)v38->GetButtonExtraBorder(this: v38, &result);
        OffsetRect(lprc: &rectImage, dx: 0, dy: *(_DWORD *)(v39 + 4) / 2);
      }
      if ( afxGlobalData.m_bUnderlineKeyboardShortcuts == 0 && CMFCToolBar::m_bCustomizeMode == 0 )
        ATL::CSimpleStringT<char,0>::operator=(this: &v66, strSrc: &str);
      m_pszData = v66.m_pszData;
      v53 = (unsigned int)v67.m_pszData;
    }
    else
    {
      rectImage = (CRect)rc;
      v58 = result.cy / 2;
      v41 = (rc.bottom - (rc.top + v72.bottom) - result.cx) / 2;
      if ( v41 < 0 )
        v41 = 0;
      rectImage.left = (rc.right + rc.left) / 2 - result.cy / 2 + result.cy;
      rectImage.right = (rc.right + rc.left) / 2 - result.cy / 2;
      rectImage.top = v41 + rc.top + v72.bottom;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Replace(
        this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v66,
        pszOld: "&&",
        pszNew: strDummyAmpSeq_0.m_pszData);
      bInactive = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Find(
                    this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v66,
                    ch: 0x26u,
                    iStart: 0);
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Remove(
        this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v66,
        chRemove: 38);
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Replace(
        this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v66,
        pszOld: strDummyAmpSeq_0.m_pszData,
        pszNew: "&&");
      if ( bInactive >= 0 && afxGlobalData.m_bUnderlineKeyboardShortcuts != 0 && CMFCToolBar::m_bCustomizeMode == 0 )
      {
        memset(&v72, 0, sizeof(v72));
        SetRectEmpty(lprc: &v72);
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Left(
          this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v66,
          result: &v67,
          nCount: bInactive + 1);
        v42 = pDC->__vftable;
        v50 = *((_DWORD *)v67.m_pszData - 3);
        LOBYTE(v74) = 2;
        v42->DrawTextA(this: pDC, a2: v67.m_pszData, a3: v50, a4: &v72, a5: 1312u);
        Tool = (CUserTool *)v72.right;
        SetRectEmpty(lprc: &v72);
        v43 = (ATL::CStringData *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Left(
                                    this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v66,
                                    result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&str.nRefs,
                                    nCount: bInactive);
        LOBYTE(v74) = 3;
        ATL::CSimpleStringT<char,0>::operator=(this: &v67, strSrc: v43);
        LOBYTE(v74) = 2;
        ATL::CStringData::Release(this: (ATL::CStringData *)(str.nRefs - 16));
        pDC->DrawTextA(this: pDC, a2: v67.m_pszData, a3: *((_DWORD *)v67.m_pszData - 3), a4: &v72, a5: 1312u);
        v44 = v72.right;
        pDC->DrawTextA(
          this: pDC,
          a2: (const char *)str.pStringMgr,
          a3: (int)str.pStringMgr[-3].__vftable,
          a4: &rectImage,
          a5: 288u);
        v45 = rect->left + rect->right;
        m_hAttribDC = pDC->m_hAttribDC;
        bInactive = 0;
        str.nRefs = v45 / 2 - v58;
        TextColor = GetTextColor(hdc: m_hAttribDC);
        CPen::CPen(this: (CPen *)&result, nPenStyle: 0, nWidth: 1, crColor: TextColor);
        v55 = pDC->m_hAttribDC;
        LOBYTE(v74) = 4;
        if ( GetTextColor(hdc: v55) != 0 )
          bInactive = (int)CDC::SelectObject(this: pDC, pFont: (CFont *)&result);
        CDC::MoveTo(this: pDC, result: &v61, x: str.nRefs, y: (int)Tool + rectImage.top);
        CDC::LineTo(this: pDC, x: str.nRefs, y: rectImage.top + v44);
        if ( bInactive != 0 )
          CDC::SelectObject(this: pDC, pFont: (CFont *)bInactive);
        LOBYTE(v74) = 2;
        result.cx = (int)&CPen::`vftable';
        CGdiObject::~CGdiObject(this: (CGdiObject *)&result);
        ATL::CStringData::Release(this: (ATL::CStringData *)v67.m_pszData - 1);
        goto LABEL_128;
      }
      m_pszData = (const char *)str.pStringMgr;
      v53 = 288;
    }
    pDC->DrawTextA(this: pDC, a2: m_pszData, a3: *((_DWORD *)m_pszData - 3), a4: &rectImage, a5: v53);
LABEL_128:
    LOBYTE(v74) = 0;
    ATL::CStringData::Release(this: (ATL::CStringData *)v66.m_pszData - 1);
  }
  if ( bCustomizeMode == 0 )
  {
    v47 = v69;
    if ( v69->HaveHotBorder(this: v69) != 0 && bDrawBorder != 0 )
    {
      v48 = v47->m_nStyle;
      if ( (v48 & 0x30000) != 0 )
      {
        v49 = CMFCVisualManager::GetInstance();
        v56 = 1;
LABEL_137:
        ((void (__thiscall *)(CMFCVisualManager *, CDC *, CMFCToolBarButton *, int, int, int, int, int))v49->OnDrawButtonBorder)(
          a1: v49,
          a2: pDC,
          a3: v69,
          a4: rect->left,
          a5: rect->top,
          a6: rect->right,
          a7: rect->bottom,
          a8: v56);
        goto LABEL_138;
      }
      if ( bHighlight != 0 && (v48 & 0x150000) == 0 )
      {
        v49 = CMFCVisualManager::GetInstance();
        v56 = 2;
        goto LABEL_137;
      }
    }
  }
LABEL_138:
  ATL::CStringData::Release(this: (ATL::CStringData *)&str.pStringMgr[-4]);
}

//------------------------------------------------------------------------------
// Address: 0x103ECCCF
// Name: public: virtual int CMFCToolBarButton::ExportToMenuButton(class CMFCToolBarMenuButton __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarButton::ExportToMenuButton(CMFCToolBarButton *this, CMFCToolBarMenuButton *menuButton)
{
  CAfxStringMgr *StringManager; // eax
  unsigned int m_nID; // esi
  HINSTANCE__ *StringResourceHandle; // eax
  int v6; // eax
  ATL::CStringData *v7; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v9; // [esp+10h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strMessage; // [esp+14h] [ebp-10h] BYREF
  int v11; // [esp+20h] [ebp-4h]

  if ( *((_DWORD *)this->m_strText.m_pszData - 3) == 0 && this->m_nID != 0 )
  {
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strMessage, pStringMgr: StringManager);
    m_nID = this->m_nID;
    v11 = 0;
    StringResourceHandle = AfxFindStringResourceHandle(__formal: m_nID);
    if ( StringResourceHandle != nullptr
      && ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
           this: &strMessage,
           hInstance: StringResourceHandle,
           nID: m_nID) != 0 )
    {
      v6 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Find(this: &strMessage, ch: 0xAu, iStart: 0);
      if ( v6 != -1 )
      {
        v7 = (ATL::CStringData *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Mid(
                                   this: &strMessage,
                                   result: &v9,
                                   iFirst: v6 + 1);
        LOBYTE(v11) = 1;
        ATL::CSimpleStringT<char,0>::operator=(this: &menuButton->m_strText, strSrc: v7);
        ATL::CStringData::Release(this: (ATL::CStringData *)v9.m_pszData - 1);
      }
    }
    ATL::CStringData::Release(this: (ATL::CStringData *)strMessage.m_pszData - 1);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103ECD69
// Name: public: virtual void CMFCToolBarButton::ResetImageToDefault(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarButton::ResetImageToDefault(CMFCToolBarButton *this)
{
  int m_bImage; // edi
  int DefaultImage; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *p_m_strText; // edi
  char *m_pszData; // eax
  CAfxStringMgr *StringManager; // eax
  unsigned int m_nID; // esi
  HINSTANCE__ *StringResourceHandle; // eax
  int v9; // eax
  ATL::CStringData *v10; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > result; // [esp+10h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strMessage; // [esp+14h] [ebp-10h] BYREF
  int v13; // [esp+20h] [ebp-4h]

  if ( this->m_bUserButton == 0
    && (int)this->m_nID > 0
    && (afxUserToolsManager == nullptr
     || CUserToolsManager::FindTool(this: afxUserToolsManager, uiCmdId: this->m_nID) == nullptr) )
  {
    m_bImage = this->m_bImage;
    DefaultImage = CMFCToolBar::GetDefaultImage(uiID: this->m_nID);
    if ( DefaultImage < 0 )
    {
      if ( m_bImage != 0 )
      {
        p_m_strText = &this->m_strText;
        m_pszData = this->m_strText.m_pszData;
        this->m_bImage = 0;
        this->m_bText = 1;
        if ( *((_DWORD *)m_pszData - 3) == 0 )
        {
          StringManager = AfxGetStringManager();
          ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strMessage, pStringMgr: StringManager);
          m_nID = this->m_nID;
          v13 = 0;
          StringResourceHandle = AfxFindStringResourceHandle(__formal: m_nID);
          if ( StringResourceHandle != nullptr
            && ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
                 this: &strMessage,
                 hInstance: StringResourceHandle,
                 nID: m_nID) != 0 )
          {
            v9 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Find(
                   this: &strMessage,
                   ch: 0xAu,
                   iStart: 0);
            if ( v9 != -1 )
            {
              v10 = (ATL::CStringData *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Mid(
                                          this: &strMessage,
                                          &result,
                                          iFirst: v9 + 1);
              LOBYTE(v13) = 1;
              ATL::CSimpleStringT<char,0>::operator=(this: p_m_strText, strSrc: v10);
              ATL::CStringData::Release(this: (ATL::CStringData *)result.m_pszData - 1);
            }
          }
          ATL::CStringData::Release(this: (ATL::CStringData *)strMessage.m_pszData - 1);
        }
      }
    }
    else
    {
      this->SetImage(this, a2: DefaultImage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103ECE52
// Name: public: CMFCToolBarButton::CMFCToolBarButton(unsigned int,int,char const __near *,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolBarButton *__thiscall CMFCToolBarButton::CMFCToolBarButton(
        CMFCToolBarButton *this,
        unsigned int uiID,
        int iImage,
        const char *lpszText,
        int bUserButton,
        int bLocked)
{
  CAfxStringMgr *StringManager; // eax
  CAfxStringMgr *v8; // eax
  const char *v9; // eax
  int m_iUserImage; // ecx
  _STATIC_CREATOR_ *CmdMgr; // eax
  _STATIC_CREATOR_ *v12; // eax
  _STATIC_CREATOR_ *v13; // eax
  unsigned int v15; // [esp-Ch] [ebp-2Ch]
  unsigned int m_nID; // [esp-8h] [ebp-28h]
  int v17; // [esp-8h] [ebp-28h]
  unsigned int v18; // [esp-8h] [ebp-28h]
  int v19; // [esp-4h] [ebp-24h]

  this->__vftable = (CMFCToolBarButton_vtbl *)&CMFCToolBarButton::`vftable';
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strText, pStringMgr: StringManager);
  v8 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strTextCustom, pStringMgr: v8);
  this->m_rect.left = 0;
  this->m_rect.top = 0;
  this->m_rect.right = 0;
  this->m_rect.bottom = 0;
  this->m_sizeText.cx = 0;
  this->m_sizeText.cy = 0;
  CMFCToolBarButton::Initialize(this);
  this->m_bLocked = bLocked;
  this->m_nID = uiID;
  this->m_bUserButton = bUserButton;
  CMFCToolBarButton::SetImage(this, iImage);
  v9 = lpszText;
  if ( lpszText == nullptr )
    v9 = &var;
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strText, pszSrc: v9);
  if ( this->m_nID != 0 && this->m_bLocked == 0 )
  {
    if ( this->m_bUserButton != 0 )
    {
      m_iUserImage = this->m_iUserImage;
      v19 = 1;
      if ( m_iUserImage == -1 )
      {
        m_nID = this->m_nID;
        CmdMgr = GetCmdMgr();
        this->m_iUserImage = CCommandManager::GetCmdImage(this: &CmdMgr->s_TheCmdMgr, uiCmd: m_nID, bUserImage: 1);
        return this;
      }
    }
    else
    {
      m_iUserImage = this->m_iImage;
      v19 = 0;
      if ( m_iUserImage == -1 )
      {
        v18 = this->m_nID;
        v13 = GetCmdMgr();
        this->m_iImage = CCommandManager::GetCmdImage(this: &v13->s_TheCmdMgr, uiCmd: v18, bUserImage: 0);
        return this;
      }
    }
    v17 = m_iUserImage;
    v15 = this->m_nID;
    v12 = GetCmdMgr();
    CCommandManager::SetCmdImage(this: &v12->s_TheCmdMgr, uiCmd: v15, iImage: v17, bUserImage: v19);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1040883F
// Name: public: CMFCColorBarCmdUI::CMFCColorBarCmdUI(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCColorBarCmdUI *__thiscall CMFCColorBarCmdUI::CMFCColorBarCmdUI(CMFCColorBarCmdUI *this)
{
  CCmdUI::CCmdUI(this);
  this->__vftable = (CMFCColorBarCmdUI_vtbl *)&CMFCColorBarCmdUI::`vftable';
  this->m_bEnabled = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1040885A
// Name: protected: void CMFCColorBar::OnMouseMove(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorBar::OnMouseMove(CMFCColorBar *this, unsigned int nFlags, CPoint point)
{
  if ( CMFCToolBar::m_bCustomizeMode == 0 || this->m_bInternal != 0 )
    CMFCToolBar::OnMouseMove(this, nFlags, point);
}

//------------------------------------------------------------------------------
// Address: 0x10408883
// Name: protected: void CMFCColorBar::OnLButtonDown(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorBar::OnLButtonDown(CMFCColorBar *this, unsigned int nFlags, CPoint point)
{
  if ( (CMFCToolBar::m_bCustomizeMode == 0 || this->m_bInternal != 0)
    && ((int (__thiscall *)(CMFCColorBar *, int, int))this->HitTest)(a1: this, a2: point.x, a3: point.y) == -1 )
  {
    CMFCToolBar::OnLButtonDown(this, nFlags, point);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104088C5
// Name: protected: void CMFCColorBar::OnLButtonUp(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorBar::OnLButtonUp(CMFCColorBar *this, unsigned int nFlags, CPoint point)
{
  int v4; // eax

  if ( CMFCToolBar::m_bCustomizeMode == 0 || this->m_bInternal != 0 )
  {
    v4 = ((int (__thiscall *)(CMFCColorBar *, int, int))this->HitTest)(a1: this, a2: point.x, a3: point.y);
    if ( v4 >= 0 )
      this->m_iButtonCapture = v4;
    CMFCToolBar::OnLButtonUp(this, nFlags, point);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040890C
// Name: protected: void CMFCColorBar::OnLButtonDblClk(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorBar::OnLButtonDblClk(CMFCColorBar *this, unsigned int nFlags, CPoint point)
{
  if ( CMFCToolBar::m_bCustomizeMode == 0 || this->m_bInternal != 0 )
    CMFCToolBar::OnLButtonDblClk(this, nFlags, point);
}

//------------------------------------------------------------------------------
// Address: 0x10408935
// Name: protected: void CMFCColorBar::OnDestroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorBar::OnDestroy(CMFCColorBar *this)
{
  if ( this->m_pParentBtn != nullptr )
  {
    this->m_pParentBtn->m_pPopup = nullptr;
    CWnd::SetFocus(this: this->m_pParentBtn);
  }
  else if ( this->m_pWndPropList != nullptr )
  {
    this->m_pWndPropList->CloseColorPopup(this: this->m_pWndPropList);
    CWnd::SetFocus(this: this->m_pWndPropList);
  }
  CMFCPopupMenuBar::OnDestroy(this);
}

//------------------------------------------------------------------------------
// Address: 0x10408988
// Name: protected: virtual void CMFCColorBar::OnChangeHot(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorBar::OnChangeHot(CMFCColorBar *this, int iHot)
{
  int v2; // edi
  CMFCToolBarButton *Button; // eax
  CObject *v5; // eax

  v2 = iHot;
  CMFCPopupMenuBar::OnChangeHot(this, iHot);
  if ( this->m_pParentRibbonBtn != nullptr )
  {
    Button = CMFCToolBar::GetButton(this, nIndex: iHot);
    v5 = AfxDynamicDownCast(pClass: &CMFCToolBarColorButton::classCMFCToolBarColorButton, pObject: Button);
    if ( v5 == nullptr || v5[31].__vftable != nullptr || v5[32].__vftable != nullptr )
      v2 = -1;
    this->m_pParentRibbonBtn->NotifyHighlightListItem(this: this->m_pParentRibbonBtn, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104089E3
// Name: public: void CMFCColorBar::SetVertMargin(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorBar::SetVertMargin(CMFCColorBar *this, int nVertMargin)
{
  this->m_nVertMargin = nVertMargin;
  this->AdjustLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x104089FD
// Name: public: void CMFCColorBar::SetHorzMargin(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorBar::SetHorzMargin(CMFCColorBar *this, int nHorzMargin)
{
  this->m_nHorzMargin = nHorzMargin;
  this->AdjustLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x1041E640
// Name: protected: int CMFCTasksPaneFrameWnd::OnNeedTipText(unsigned int,struct tagNMHDR __near *,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCTasksPaneFrameWnd::OnNeedTipText(
        CMFCTasksPaneFrameWnd *this,
        unsigned int id,
        tagNMHDR *pNMH,
        int *pResult)
{
  CAfxStringMgr *StringManager; // eax
  CToolTipCtrl *m_pToolTip; // eax
  signed int idFrom; // eax
  __POSITION *Index; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  char *v11; // ebx
  int v12; // eax

  if ( (_S1_46 & 1) == 0 )
  {
    _S1_46 |= 1u;
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strTipText_5, pStringMgr: StringManager);
    atexit(func: CMFCTasksPaneFrameWnd::OnNeedTipText_::_2_::_dynamic_atexit_destructor_for__strTipText__);
  }
  if ( pNMH == nullptr )
    AfxThrowInvalidArgException();
  m_pToolTip = this->m_pToolTip;
  if ( m_pToolTip == nullptr || m_pToolTip->m_hWnd == nullptr || pNMH->hwndFrom != m_pToolTip->m_hWnd )
    return 0;
  idFrom = pNMH->idFrom;
  if ( idFrom != 0 && idFrom <= this->m_lstCaptionButtons.m_nCount )
  {
    Index = CStringList::FindIndex(
              this: (CList<unsigned long,unsigned long> *)&this->m_lstCaptionButtons,
              nIndex: idFrom - 1);
    if ( Index != nullptr )
    {
      v9 = CMFCCaptionButton::GetHit(this: *(CMFCCaptionButton **)&Index[8]) - 23;
      if ( v9 == 0 )
      {
        v11 = "Back";
        goto LABEL_17;
      }
      v10 = v9 - 1;
      if ( v10 == 0 )
      {
        v11 = "Forward";
        goto LABEL_17;
      }
      if ( v10 == 1 )
      {
        v11 = "Other Tasks Pane";
LABEL_17:
        strlen(buf: (unsigned __int8 *)v11);
        ATL::CSimpleStringT<char,0>::SetString(this: &strTipText_5, pszSrc: v11, nLength: v12);
        pNMH[1].hwndFrom = (HWND__ *)strTipText_5.m_pszData;
        return 1;
      }
    }
  }
  return CPaneFrameWnd::OnNeedTipText(this, __formal: id, pNMH, __formal: pResult);
}

//------------------------------------------------------------------------------
// Address: 0x1041E71E
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCTasksPaneFrameWnd::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCTasksPaneFrameWnd::GetMessageMap(CMFCTasksPaneFrameWnd *this)
{
  return (const AFX_MSGMAP *)&off_1068F874;
}

//------------------------------------------------------------------------------
// Address: 0x1041E724
// Name: public: OLE_DATA::OLE_DATA(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
OLE_DATA *__thiscall OLE_DATA::OLE_DATA(OLE_DATA *this)
{
  this->cfNative = RegisterClipboardFormatA(lpszFormat: "Native");
  this->cfOwnerLink = RegisterClipboardFormatA(lpszFormat: "OwnerLink");
  this->cfObjectLink = RegisterClipboardFormatA(lpszFormat: "ObjectLink");
  this->cfEmbeddedObject = RegisterClipboardFormatA(lpszFormat: "Embedded Object");
  this->cfEmbedSource = RegisterClipboardFormatA(lpszFormat: "Embed Source");
  this->cfLinkSource = RegisterClipboardFormatA(lpszFormat: "Link Source");
  this->cfObjectDescriptor = RegisterClipboardFormatA(lpszFormat: "Object Descriptor");
  this->cfLinkSourceDescriptor = RegisterClipboardFormatA(lpszFormat: "Link Source Descriptor");
  this->cfFileName = RegisterClipboardFormatA(lpszFormat: "FileName");
  this->cfFileNameW = RegisterClipboardFormatA(lpszFormat: "FileNameW");
  this->cfRichTextFormat = RegisterClipboardFormatA(lpszFormat: "Rich Text Format");
  this->cfRichTextAndObjects = RegisterClipboardFormatA(lpszFormat: "RichEdit Text and Objects");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1041E7AC
// Name: public: CSharedFile::CSharedFile(unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSharedFile *__thiscall CSharedFile::CSharedFile(CSharedFile *this, unsigned int nAllocFlags, unsigned int nGrowBytes)
{
  CMemFile::CMemFile(this, nGrowBytes);
  this->m_hGlobalMemory = nullptr;
  this->m_nAllocFlags = nAllocFlags;
  this->__vftable = (CSharedFile_vtbl *)&CSharedFile::`vftable';
  this->m_bAllowGrow = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1041E7DA
// Name: public: virtual CSharedFile::~CSharedFile(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSharedFile::~CSharedFile(CSharedFile *this)
{
  this->__vftable = (CSharedFile_vtbl *)&CSharedFile::`vftable';
  if ( this->m_lpBuffer != nullptr )
    CMemFile::Close(this);
  CMemFile::~CMemFile(this);
}
