// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mapview2dbase.cpp
// Functions: 82
// ============================================================

#include "hammer\mapview2dbase.h"

//------------------------------------------------------------------------------
// Address: 0x1007DC50
// Name: public: int CPoint::operator==(struct tagPOINT)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CPoint::operator==(CPoint *this, tagPOINT point)
{
  return *this == point;
}

//------------------------------------------------------------------------------
// Address: 0x1007DC80
// Name: public: void CRect::NormalizeRect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRect::NormalizeRect(CRect *this)
{
  int left; // eax
  int right; // edx
  int top; // eax
  int bottom; // edx

  left = this->left;
  right = this->right;
  if ( this->left > right )
  {
    this->left = right;
    this->right = left;
  }
  top = this->top;
  bottom = this->bottom;
  if ( top > bottom )
  {
    this->top = bottom;
    this->bottom = top;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007DCA0
// Name: public: virtual struct CRuntimeClass __near * CMapView2DBase::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMapView2DBase::GetRuntimeClass(CMapView2DBase *this)
{
  return &CMapView2DBase::classCMapView2DBase;
}

//------------------------------------------------------------------------------
// Address: 0x1007DCB0
// Name: public: static char const __near * vgui::EditablePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::EditablePanel::GetPanelClassName()
{
  return "EditablePanel";
}

//------------------------------------------------------------------------------
// Address: 0x1007DCD0
// Name: public: virtual void CMapView2DBasePanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2DBasePanel::Paint(CMapView2DBasePanel *this)
{
  this->m_pMapView->Render(this: this->m_pMapView);
}

//------------------------------------------------------------------------------
// Address: 0x1007DCE0
// Name: protected: CMapView2DBase::CMapView2DBase(void)
// Source: json
//------------------------------------------------------------------------------
CMapView2DBase *__thiscall CMapView2DBase::CMapView2DBase(CMapView2DBase *this)
{
  CCamera *v2; // eax
  CCamera *v3; // eax
  CRender2D *v4; // eax
  CRender2D *v5; // eax

  CView::CView(this);
  CMapView::CMapView(this: &this->CMapView);
  *(_WORD *)&this->bInvertHorz = 0;
  this->axHorz = 0;
  this->axVert = 1;
  this->axThird = 2;
  CVGuiWnd::CVGuiWnd(this: &this->CVGuiWnd);
  this->CView::CWnd::CCmdTarget::CObject::__vftable = (CMapView2DBase_vtbl *)&CMapView2DBase::`vftable'{for `CView'};
  this->CMapView::__vftable = (CMapView_vtbl *)&CMapView2DBase::`vftable'{for `CMapView'};
  this->CVGuiWnd::__vftable = (CVGuiWnd_vtbl *)&CMapView2DBase::`vftable'{for `CVGuiWnd'};
  this->m_clrGrid = 0;
  this->m_clrGrid1024 = 0;
  this->m_clrGridCustom = 0;
  this->m_clrGridDot = 0;
  this->m_clrAxis = 0;
  this->m_flMinZoom = 0.02125;
  this->m_fZoom = -1.0;
  this->m_pwndTitle = nullptr;
  this->m_vViewOrigin.x = 0.0;
  this->m_vViewOrigin.y = 0.0;
  this->m_vViewOrigin.z = 0.0;
  this->m_ViewMin.x = 0.0;
  this->m_ViewMin.y = 0.0;
  this->m_ViewMin.z = 0.0;
  this->m_ViewMax.x = 0.0;
  this->m_ViewMax.y = 0.0;
  this->m_ViewMax.z = 0.0;
  this->m_yScroll = 0;
  this->m_xScroll = 0;
  this->m_bActive = false;
  this->m_bMouseDrag = false;
  v2 = (CCamera *)operator new(nSize: 0x140u);
  if ( v2 != nullptr )
    v3 = CCamera::CCamera(this: v2);
  else
    v3 = nullptr;
  this->m_pCamera = v3;
  CCamera::SetOrthographic(this: v3, fZoom: 0.25, fNearClip: -99999.0, fFarClip: 99999.0);
  v4 = (CRender2D *)operator new(nSize: 0x420u);
  if ( v4 != nullptr )
    v5 = CRender2D::CRender2D(this: v4);
  else
    v5 = nullptr;
  this->m_pRender = v5;
  v5->SetView(this: v5, a2: &this->CMapView);
  CRender::SetDefaultRenderMode(this: this->m_pRender, eRenderMode: RENDER_MODE_FLAT_NOZ);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1007DED0
// Name: protected: virtual CMapView2DBase::~CMapView2DBase(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2DBase::~CMapView2DBase(CMapView2DBase *this)
{
  CTitleWnd *m_pwndTitle; // ecx
  CCamera *m_pCamera; // ecx
  CRender2D *m_pRender; // ecx

  this->CView::CWnd::CCmdTarget::CObject::__vftable = (CMapView2DBase_vtbl *)&CMapView2DBase::`vftable'{for `CView'};
  this->CMapView::__vftable = (CMapView_vtbl *)&CMapView2DBase::`vftable'{for `CMapView'};
  this->CVGuiWnd::__vftable = (CVGuiWnd_vtbl *)&CMapView2DBase::`vftable'{for `CVGuiWnd'};
  m_pwndTitle = this->m_pwndTitle;
  if ( m_pwndTitle != nullptr )
    ((void (__thiscall *)(CTitleWnd *, int))m_pwndTitle->dtr_CObject)(a1: m_pwndTitle, a2: 1);
  m_pCamera = this->m_pCamera;
  if ( m_pCamera != nullptr )
    ((void (__thiscall *)(CCamera *, int))m_pCamera->dtr_CCamera)(a1: m_pCamera, a2: 1);
  m_pRender = this->m_pRender;
  if ( m_pRender != nullptr )
    ((void (__thiscall *)(CRender2D *, int))m_pRender->dtr_CRender)(a1: m_pRender, a2: 1);
  CVGuiWnd::~CVGuiWnd(this: &this->CVGuiWnd);
  CView::~CView(this);
}

//------------------------------------------------------------------------------
// Address: 0x1007DF80
// Name: protected: void CMapView2DBase::CreateTitleWindow(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2DBase::CreateTitleWindow(CMapView2DBase *this)
{
  CTitleWnd *TitleWnd; // eax

  TitleWnd = CTitleWnd::CreateTitleWnd(pwndParent: this, uID: 0x70u);
  this->m_pwndTitle = TitleWnd;
  if ( TitleWnd != nullptr && IsWindow(hWnd: TitleWnd->m_hWnd) )
  {
    CWnd::SetWindowPos(this: this->m_pwndTitle, pWndInsertAfter: nullptr, x: 0, y: 0, cx: 0, cy: 0, nFlags: 5u);
    CWnd::ShowWindow(this: this->m_pwndTitle, nCmdShow: 5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007DFD0
// Name: protected: bool CMapView2DBase::HighlightGridLine(class CRender2D __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMapView2DBase::HighlightGridLine(CMapView2DBase *this, CRender2D *pRender, int nGridLine)
{
  if ( nGridLine != 0 )
  {
    if ( Options.view2d.bGridHigh1024 == 0 || nGridLine % 1024 != 0 )
    {
      if ( (Options.view2d.bGridHigh64 == 0 || nGridLine % 64 != 0 || s_bGridDots)
        && (Options.view2d.bGridHigh10 == 0 || nGridLine % s_iCustomGridSpacing != 0 || s_bGridDots) )
      {
        return 0;
      }
      else
      {
        CRender::SetDrawColor(this: pRender, color: &this->m_clrGridCustom);
        return 1;
      }
    }
    else
    {
      CRender::SetDrawColor(this: pRender, color: &this->m_clrGrid1024);
      return 1;
    }
  }
  else
  {
    CRender::SetDrawColor(this: pRender, color: &this->m_clrAxis);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007E080
// Name: protected: void CMapView2DBase::DrawGridLogical(class CRender2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2DBase::DrawGridLogical(CMapView2DBase *this, CRender2D *pRender)
{
  CMapDoc *(__thiscall *GetMapDoc)(CMapView *); // edx
  float v4; // xmm0_4
  float v5; // xmm1_4
  int v6; // eax
  float v7; // xmm0_4
  float v8; // xmm3_4
  int v9; // ecx
  float v10; // xmm0_4
  float v11; // xmm3_4
  int v12; // edi
  float v13; // xmm0_4
  float v14; // xmm2_4
  int v15; // ebx
  int v16; // edi
  Color *p_m_clrGrid; // ebx
  Vector vPointMin; // [esp+4h] [ebp-28h] BYREF
  Vector vPointMax; // [esp+10h] [ebp-1Ch] BYREF
  int yMin; // [esp+1Ch] [ebp-10h]
  int xMin; // [esp+20h] [ebp-Ch]
  int xMax; // [esp+24h] [ebp-8h]
  CMapView2DBase *v23; // [esp+28h] [ebp-4h]

  GetMapDoc = this->GetMapDoc;
  v23 = this;
  if ( (int)GetMapDoc(this: &this->CMapView) != 0 )
  {
    v4 = this->m_ViewMin.x - 1024.0;
    s_iCustomGridSpacing = 1024;
    s_bGridDots = false;
    if ( g_MIN_MAP_COORD <= v4 )
      v5 = v4;
    else
      v5 = g_MIN_MAP_COORD;
    if ( g_MIN_MAP_COORD > v4 )
      v4 = g_MIN_MAP_COORD;
    v6 = (int)v5 - (int)v4 % 1024;
    v7 = this->m_ViewMax.x + 1024.0;
    xMin = v6;
    if ( v7 <= g_MAX_MAP_COORD )
      v8 = v7;
    else
      v8 = g_MAX_MAP_COORD;
    if ( v7 > g_MAX_MAP_COORD )
      v7 = g_MAX_MAP_COORD;
    v9 = (int)v8 - (int)v7 % 1024;
    v10 = this->m_ViewMin.y - 1024.0;
    xMax = v9;
    if ( g_MIN_MAP_COORD <= v10 )
      v11 = v10;
    else
      v11 = g_MIN_MAP_COORD;
    if ( g_MIN_MAP_COORD > v10 )
      v10 = g_MIN_MAP_COORD;
    v12 = (int)v11 - (int)v10 % 1024;
    v13 = this->m_ViewMax.y + 1024.0;
    yMin = v12;
    if ( v13 <= g_MAX_MAP_COORD )
      v14 = v13;
    else
      v14 = g_MAX_MAP_COORD;
    if ( v13 > g_MAX_MAP_COORD )
      v13 = g_MAX_MAP_COORD;
    vPointMin.y = 0.0;
    vPointMin.z = 0.0;
    vPointMax.y = 0.0;
    vPointMax.z = 0.0;
    vPointMin.x = (float)v6;
    v15 = (int)v14 - (int)v13 % 1024;
    vPointMax.x = (float)v9;
    if ( v12 <= v15 )
    {
      do
      {
        CRender::SetDrawColor(this: pRender, color: &v23->m_clrGrid);
        CMapView2DBase::HighlightGridLine(this: v23, pRender, nGridLine: v12);
        vPointMax.y = (float)v12;
        vPointMin.y = (float)v12;
        CRender::DrawLine(this: pRender, vStart: &vPointMin, vEnd: &vPointMax);
        v12 += 1024;
      }
      while ( v12 <= v15 );
      v6 = xMin;
      v9 = xMax;
      v12 = yMin;
    }
    vPointMin.y = (float)v12;
    vPointMax.y = (float)v15;
    v16 = v6;
    if ( v6 <= v9 )
    {
      p_m_clrGrid = &v23->m_clrGrid;
      do
      {
        CRender::SetDrawColor(this: pRender, color: p_m_clrGrid);
        CMapView2DBase::HighlightGridLine(this: v23, pRender, nGridLine: v16);
        vPointMax.x = (float)v16;
        vPointMin.x = (float)v16;
        CRender::DrawLine(this: pRender, vStart: &vPointMin, vEnd: &vPointMax);
        v16 += 1024;
      }
      while ( v16 <= xMax );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007E2C0
// Name: public: bool CMapView2DBase::CheckDistance(class Vector2D const __near &,class Vector2D const __near &,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMapView2DBase::CheckDistance(
        CMapView2DBase *this,
        const Vector2D *vecCheck,
        const Vector2D *vecRef,
        int nDist)
{
  return (float)nDist >= fabs(vecRef->x - vecCheck->x) && (float)nDist >= fabs(vecRef->y - vecCheck->y);
}

//------------------------------------------------------------------------------
// Address: 0x1007E310
// Name: public: void CMapView2DBase::GetCenterPoint(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2DBase::GetCenterPoint(CMapView2DBase *this, Vector *pt)
{
  int v3; // eax
  float v4; // xmm0_4
  void (__thiscall *ClientToWorld)(CMapView *, Vector *, const Vector2D *); // eax
  int axHorz; // edx
  Vector vCenter; // [esp+4h] [ebp-14h] BYREF
  Vector2D ptCenter; // [esp+10h] [ebp-8h] BYREF

  v3 = this->m_ClientHeight / 2;
  ptCenter.x = (float)(this->m_ClientWidth / 2);
  v4 = (float)v3;
  ClientToWorld = this->ClientToWorld;
  ptCenter.y = v4;
  ClientToWorld(this: &this->CMapView, a2: &vCenter, a3: &ptCenter);
  axHorz = this->axHorz;
  if ( *(&pt->x + axHorz) == 99999.0 )
    *(&pt->x + axHorz) = *(&vCenter.x + axHorz);
  if ( *(&pt->x + this->axVert) == 99999.0 )
    *(&pt->x + this->axVert) = *(&vCenter.x + this->axVert);
}

//------------------------------------------------------------------------------
// Address: 0x1007E3C0
// Name: public: virtual bool CMapView2DBase::HitTest(class Vector2D const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMapView2DBase::HitTest(
        CMapView2DBase *this,
        const Vector2D *vPoint,
        const Vector *mins,
        const Vector *maxs)
{
  POINT v6; // [esp-8h] [ebp-2Ch]
  CRect rect; // [esp+4h] [ebp-20h] BYREF
  Vector2D vecMaxClient; // [esp+14h] [ebp-10h] BYREF
  Vector2D vecMinClient; // [esp+1Ch] [ebp-8h] BYREF

  ((void (__thiscall *)(CMapView2DBase *, Vector2D *, const Vector *))this->GetMessageMap)(
    a1: this,
    a2: &vecMinClient,
    a3: mins);
  ((void (__thiscall *)(CMapView2DBase *, Vector2D *, const Vector *))this->GetMessageMap)(
    a1: this,
    a2: &vecMaxClient,
    a3: maxs);
  rect.left = (int)vecMinClient.x;
  rect.top = (int)vecMinClient.y;
  rect.right = (int)vecMaxClient.x;
  rect.bottom = (int)vecMaxClient.y;
  if ( (int)vecMinClient.x > (int)vecMaxClient.x )
  {
    rect.left = (int)vecMaxClient.x;
    rect.right = (int)vecMinClient.x;
  }
  if ( (int)vecMinClient.y > (int)vecMaxClient.y )
  {
    rect.top = (int)vecMaxClient.y;
    rect.bottom = (int)vecMinClient.y;
  }
  v6.y = (int)vPoint->y;
  v6.x = (int)vPoint->x;
  return PtInRect(lprc: &rect, pt: v6);
}

//------------------------------------------------------------------------------
// Address: 0x1007E450
// Name: protected: void CMapView2DBase::OnLButtonDblClk(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapView2DBase::OnLButtonDblClk(
        CMapView2DBase *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        unsigned int nFlags,
        CPoint point)
{
  CToolManager *m_pToolManager; // ecx
  int ActiveTool; // esi
  bool (__thiscall *IsLogical)(CMapView2DBase *); // eax
  Vector2D vPoint; // [esp+4h] [ebp-8h] BYREF

  if ( GetAsyncKeyState(vKey: 32) >= 0 )
  {
    m_pToolManager = this->m_pToolManager;
    if ( m_pToolManager != nullptr )
    {
      ActiveTool = CToolManager::GetActiveTool(this: (CSelection *)m_pToolManager);
      if ( ActiveTool != 0 )
      {
        IsLogical = this->IsLogical;
        vPoint.x = (float)point.x;
        vPoint.y = (float)point.y;
        if ( ((unsigned __int8 (__thiscall *)(CMapView2DBase *, int, int))IsLogical)(a1: this, a2, a3) != 0 )
        {
          (*(void (__thiscall **)(int, CMapView2DBase *))(*(_DWORD *)ActiveTool + 156))(a1: ActiveTool, a2: this);
          (*(void (__thiscall **)(int, CMapView2DBase *, unsigned int, Vector2D *))(*(_DWORD *)ActiveTool + 148))(
            a1: ActiveTool,
            a2: this,
            a3: nFlags,
            a4: &vPoint);
        }
        else
        {
          (*(void (__thiscall **)(int, CMapView2DBase *))(*(_DWORD *)ActiveTool + 112))(a1: ActiveTool, a2: this);
          (*(void (__thiscall **)(int, CMapView2DBase *, unsigned int, Vector2D *))(*(_DWORD *)ActiveTool + 104))(
            a1: ActiveTool,
            a2: this,
            a3: nFlags,
            a4: &vPoint);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007E510
// Name: public: virtual void CMapView2DBase::ActivateView(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2DBase::ActivateView(CMapView2DBase *this, bool bActivate)
{
  CMapDoc *v3; // edi
  CView *v4; // esi
  char pszText[8]; // [esp+10h] [ebp-80h] BYREF

  CMapView::ActivateView((CMapView *)this, bActivate);
  if ( bActivate )
  {
    v3 = (CMapDoc *)this->GetTypeLibCache(this);
    CMapDoc::SetActiveMapDoc(pDoc: v3);
    v4 = (CMapView2DBase *)((char *)this - 124);
    CMapDoc::UpdateTitle(this: v3, pView: v4);
    if ( IsWindow(hWnd: v4->m_hWnd) )
    {
      sprintf(string: pszText, format: " Zoom: %.2f ", *(float *)&v4[1].m_pDropTarget);
      SetStatusText(nIndex: 4, pszText);
    }
  }
  else
  {
    this->m_pMainPanel = nullptr;
    this->CVGuiWnd::__vftable = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007E5B0
// Name: protected: void CMapView2DBase::OnEditProperties(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2DBase::OnEditProperties(CMapView2DBase *this)
{
  CMainFrame *MainWnd; // eax

  MainWnd = GetMainWnd();
  CWnd::ShowWindow(this: MainWnd->pObjectProperties, nCmdShow: 5);
}

//------------------------------------------------------------------------------
// Address: 0x1007E5D0
// Name: protected: void CMapView2DBase::OnUpdateEditFunction(class CCmdUI __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2DBase::OnUpdateEditFunction(CMapView2DBase *this, CCmdUI *pCmdUI)
{
  CMainFrame *MainWnd; // eax

  if ( CToolManager::GetActiveToolID(this: this->m_pToolManager) == TOOL_FACEEDIT_MATERIAL
    || (MainWnd = GetMainWnd(), CMainFrame::IsShellSessionActive(this: MainWnd)) )
  {
    pCmdUI->Enable(this: pCmdUI, a2: 0);
  }
  else
  {
    pCmdUI->Enable(this: pCmdUI, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007E630
// Name: public: virtual void CMapView2DBase::WorldToClient(class Vector2D __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2DBase::WorldToClient(CMapView2DBase *this, Vector2D *ptClient, const Vector *vecWorld)
{
  ptClient->x = (float)((float)(*(&vecWorld->x + this->m_ptGestureFrom.x)
                              - *((float *)&this->m_nFlags + this->m_ptGestureFrom.x))
                      * *(float *)&this->m_pDropTarget)
              + *(float *)&this->m_pCtrlCont;
  ptClient->y = (float)((float)(*((float *)&this->m_nFlags + this->m_ptGestureFrom.y)
                              - *(&vecWorld->x + this->m_ptGestureFrom.y))
                      * *(float *)&this->m_pDropTarget)
              + *(float *)&this->m_pCtrlSite;
}

//------------------------------------------------------------------------------
// Address: 0x1007E680
// Name: public: virtual void CMapView2DBase::ClientToWorld(class Vector __near &,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2DBase::ClientToWorld(CMapView2DBase *this, Vector *vecWorld, const Vector2D *ptClient)
{
  *(&vecWorld->x + this->m_ptGestureFrom.x) = ptClient->x - *(float *)&this->m_pCtrlCont;
  *(&vecWorld->x + this->m_ptGestureFrom.y) = ptClient->y - *(float *)&this->m_pCtrlSite;
  *((_DWORD *)&vecWorld->x + LODWORD(this->m_ulGestureArg)) = 0;
  *(&vecWorld->x + this->m_ptGestureFrom.x) = *(&vecWorld->x + this->m_ptGestureFrom.x) / *(float *)&this->m_pDropTarget;
  *(&vecWorld->x + this->m_ptGestureFrom.y) = *(&vecWorld->x + this->m_ptGestureFrom.y) / *(float *)&this->m_pDropTarget;
  if ( LOBYTE(this->m_bIsTouchWindowRegistered) != 0 )
    *(&vecWorld->x + this->m_ptGestureFrom.x) = -*(&vecWorld->x + this->m_ptGestureFrom.x);
  if ( BYTE1(this->m_bIsTouchWindowRegistered) != 0 )
    *(&vecWorld->x + this->m_ptGestureFrom.y) = -*(&vecWorld->x + this->m_ptGestureFrom.y);
  vecWorld->x = *(float *)&this->m_nFlags + vecWorld->x;
  vecWorld->y = *(float *)&this->m_pfnSuper + vecWorld->y;
  vecWorld->z = *(float *)&this->m_nModalResult + vecWorld->z;
}

//------------------------------------------------------------------------------
// Address: 0x1007E750
// Name: public: virtual void CMapView2DBase::BuildRay(class Vector2D const __near &,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2DBase::BuildRay(CMapView2DBase *this, const Vector2D *ptClient, Vector *vStart, Vector *vEnd)
{
  ((void (__thiscall *)(CMapView2DBase *, Vector *, const Vector2D *))this->GetCommandMap)(
    a1: this,
    a2: vStart,
    a3: ptClient);
  *vEnd = *vStart;
  *((_DWORD *)&vStart->x + LODWORD(this->m_ulGestureArg)) = -943501440;
  *((_DWORD *)&vEnd->x + LODWORD(this->m_ulGestureArg)) = 1203982208;
}

//------------------------------------------------------------------------------
// Address: 0x1007E7B0
// Name: public: virtual void CMapView2DBase::GetBestTransformPlane(class Vector __near &,class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2DBase::GetBestTransformPlane(
        CMapView2DBase *this,
        Vector *horzAxis,
        Vector *vertAxis,
        Vector *thirdAxis)
{
  horzAxis->x = 0.0;
  horzAxis->y = 0.0;
  horzAxis->z = 0.0;
  *((_DWORD *)&horzAxis->x + this->m_ptGestureFrom.x) = 1065353216;
  vertAxis->x = 0.0;
  vertAxis->y = 0.0;
  vertAxis->z = 0.0;
  *((_DWORD *)&vertAxis->x + this->m_ptGestureFrom.y) = 1065353216;
  thirdAxis->x = 0.0;
  thirdAxis->y = 0.0;
  thirdAxis->z = 0.0;
  *((_DWORD *)&thirdAxis->x + LODWORD(this->m_ulGestureArg)) = 1065353216;
}

//------------------------------------------------------------------------------
// Address: 0x1007E810
// Name: public: bool CMapView2DBase::IsBoxFullyVisible(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapView2DBase::IsBoxFullyVisible(
        CMapView2DBase *this,
        const Vector *minsWorld,
        const Vector *maxsWorld)
{
  float m_ClientWidth; // xmm4_4
  float m_ClientHeight; // xmm3_4
  BOOL result; // eax
  Vector2D maxsClient; // [esp+8h] [ebp-10h] BYREF
  Vector2D minsClient; // [esp+10h] [ebp-8h] BYREF

  this->WorldToClient(this: &this->CMapView, a2: &minsClient, a3: minsWorld);
  this->WorldToClient(this: &this->CMapView, a2: &maxsClient, a3: maxsWorld);
  result = false;
  if ( minsClient.x >= 0.0 && minsClient.y >= 0.0 )
  {
    m_ClientWidth = (float)this->m_ClientWidth;
    if ( m_ClientWidth > minsClient.x )
    {
      m_ClientHeight = (float)this->m_ClientHeight;
      if ( m_ClientHeight > minsClient.y
        && maxsClient.x >= 0.0
        && maxsClient.y >= 0.0
        && m_ClientWidth > maxsClient.x
        && m_ClientHeight > maxsClient.y )
      {
        return true;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007E8B0
// Name: public: bool CMapView2DBase::CanBoxFitInView(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMapView2DBase::CanBoxFitInView(CMapView2DBase *this, const Vector *minsWorld, const Vector *maxsWorld)
{
  Vector2D minsClient; // [esp+8h] [ebp-10h] BYREF
  Vector2D maxsClient; // [esp+10h] [ebp-8h] BYREF

  this->WorldToClient(this: &this->CMapView, a2: &minsClient, a3: minsWorld);
  this->WorldToClient(this: &this->CMapView, a2: &maxsClient, a3: maxsWorld);
  return (float)this->m_ClientWidth > (float)(maxsClient.x - minsClient.x)
      && (float)this->m_ClientHeight > (float)(maxsClient.y - minsClient.y);
}

//------------------------------------------------------------------------------
// Address: 0x1007E930
// Name: public: virtual void CMapView2DBase::RenderView(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2DBase::RenderView(CMapView2DBase *this)
{
  CVGuiWnd::DrawVGuiPanel(this: (CVGuiWnd *)&this->m_hWnd);
  BYTE1(this->m_dwRef) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1007E950
// Name: public: virtual long CMapView2DBase::WindowProc(unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapView2DBase::WindowProc(CMapView2DBase *this, unsigned int message, unsigned int wParam, int lParam)
{
  int result; // eax
  HWND ForegroundWindow; // eax
  CWnd *v7; // eax

  switch ( message )
  {
    case 0xFu:
      ForegroundWindow = GetForegroundWindow();
      v7 = CWnd::FromHandle(hWnd: ForegroundWindow);
      if ( v7 != nullptr && v7->ContinueModal(this: v7) != 0 )
        this->RenderView(this: &this->CMapView);
      else
        this->m_bUpdateView = true;
      goto $LN5_20;
    case 0x100u:
    case 0x101u:
    case 0x102u:
    case 0x104u:
    case 0x105u:
    case 0x106u:
$LN5_20:
      result = CWnd::WindowProc(this, message, wParam, lParam);
      break;
    default:
      if ( CVGuiWnd::WindowProcVGui(this: &this->CVGuiWnd, uMsg: message, wParam, lParam) != 0 )
        result = 1;
      else
        result = CWnd::WindowProc(this, message, wParam, lParam);
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007EB00
// Name: public: bool CMapView2DBase::IsInClientView(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMapView2DBase::IsInClientView(CMapView2DBase *this, const Vector *vecMin, const Vector *vecMax)
{
  return vecMin->x <= this->m_ViewMax.x
      && this->m_ViewMin.x <= vecMax->x
      && vecMin->y <= this->m_ViewMax.y
      && this->m_ViewMin.y <= vecMax->y
      && vecMin->z <= this->m_ViewMax.z
      && this->m_ViewMin.z <= vecMax->z;
}

//------------------------------------------------------------------------------
// Address: 0x1007EB70
// Name: public: virtual class Vector const __near & CMapView2DBase::GetViewAxis(void)
// Source: json
//------------------------------------------------------------------------------
CMFCControlContainer **__thiscall CMapView2DBase::GetViewAxis(CMapView2DBase *this)
{
  return &this->m_pMFCCtrlContainer;
}

//------------------------------------------------------------------------------
// Address: 0x1007EB90
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::EditablePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::EditablePanel::GetMessageMap(vgui::EditablePanel *this)
{
  if ( (`vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' & 1) == 0 )
  {
    `vgui::EditablePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
    `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  return `vgui::EditablePanel::GetMessageMap'::`2'::s_pMap;
}

//------------------------------------------------------------------------------
// Address: 0x1007EBF0
// Name: public: virtual struct PanelAnimationMap __near * vgui::EditablePanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::EditablePanel::GetAnimMap(vgui::EditablePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "EditablePanel");
}

//------------------------------------------------------------------------------
// Address: 0x1007EC00
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::EditablePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::EditablePanel::GetKBMap(vgui::EditablePanel *this)
{
  if ( (`vgui::EditablePanel::GetKBMap'::`2'::`local static guard' & 1) == 0 )
  {
    `vgui::EditablePanel::GetKBMap'::`2'::`local static guard' |= 1u;
    `vgui::EditablePanel::GetKBMap'::`2'::s_pMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  return `vgui::EditablePanel::GetKBMap'::`2'::s_pMap;
}

//------------------------------------------------------------------------------
// Address: 0x1007EC60
// Name: public: static class CObject __near * CMapView2DBase::CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CMapView2DBase *__stdcall CMapView2DBase::CreateObject()
{
  CMapView2DBase *v0; // eax

  v0 = (CMapView2DBase *)operator new(nSize: 0x140u);
  if ( v0 != nullptr )
    return CMapView2DBase::CMapView2DBase(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1007ECF0
// Name: public: void CMapView2DBase::ToolScrollToPoint(class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2DBase::ToolScrollToPoint(CMapView2DBase *this, const Vector2D *ptClient)
{
  int v3; // edi
  HWND Capture; // eax
  float v5; // xmm1_4
  float y; // xmm1_4

  v3 = (int)(float)(10.0 / this->m_fZoom);
  Capture = GetCapture();
  if ( CWnd::FromHandle(hWnd: Capture) == this
    && (ptClient->x < 0.0
     || (v5 = ptClient->y) < 0.0
     || ptClient->x >= (float)this->m_ClientWidth
     || v5 >= (float)this->m_ClientHeight) )
  {
    this->m_yScroll = 0;
    this->m_xScroll = 0;
    if ( ptClient->x >= 0.0 )
    {
      if ( ptClient->x >= (float)this->m_ClientWidth )
        this->m_xScroll = v3;
    }
    else
    {
      this->m_xScroll = -v3;
    }
    y = ptClient->y;
    if ( y >= 0.0 )
    {
      if ( y < (float)this->m_ClientHeight )
      {
LABEL_14:
        SetTimer(hWnd: this->m_hWnd, nIDEvent: 1u, uElapse: 0xAu, lpTimerFunc: nullptr);
        return;
      }
      v3 = -v3;
    }
    this->m_yScroll = v3;
    goto LABEL_14;
  }
  this->m_yScroll = 0;
  this->m_xScroll = 0;
  KillTimer(hWnd: this->m_hWnd, uIDEvent: 1u);
}

//------------------------------------------------------------------------------
// Address: 0x1007EDF0
// Name: protected: void CMapView2DBase::AdjustColorIntensity(class Color __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2DBase::AdjustColorIntensity(CMapView2DBase *this, Color *color, int nIntensity)
{
  int v3; // edi
  int v4; // ebx
  int v5; // ecx
  int v6; // eax
  int nIntensitya; // [esp+18h] [ebp+Ch]

  if ( Options.view2d.bWhiteOnBlack != 0 )
    v3 = nIntensity;
  else
    v3 = 100 - nIntensity;
  if ( v3 >= 0 )
  {
    if ( v3 > 100 )
      v3 = 100;
  }
  else
  {
    v3 = 0;
  }
  LOBYTE(v4) = -1;
  nIntensitya = v3 * color->_color[2] / 100;
  if ( nIntensitya >= 255 )
    LOBYTE(nIntensitya) = -1;
  v5 = v3 * color->_color[1];
  if ( v5 / 100 < 255 )
    v4 = v5 / 100;
  v6 = v3 * color->_color[0] / 100;
  if ( v6 >= 255 )
    LOBYTE(v6) = -1;
  color->_color[0] = v6;
  color->_color[1] = v4;
  color->_color[2] = nIntensitya;
}

//------------------------------------------------------------------------------
// Address: 0x1007EEA0
// Name: protected: void CMapView2DBase::SetColorMode(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2DBase::SetColorMode(CMapView2DBase *this, bool bWhiteOnBlack)
{
  unsigned __int8 v2; // eax^2
  Color *p_m_clrGrid; // ecx
  unsigned __int8 v5; // dh
  unsigned __int8 v6; // eax^2
  unsigned __int8 v7; // dh
  unsigned __int8 v8; // eax^2
  unsigned __int8 v9; // dh
  unsigned __int8 v10; // eax^2
  unsigned __int8 v11; // dh
  unsigned __int8 v12; // eax^2
  unsigned __int8 v13; // dh
  unsigned int clrBackground; // eax

  v2 = BYTE2(Options.colors.clrGrid);
  p_m_clrGrid = &this->m_clrGrid;
  v5 = BYTE1(Options.colors.clrGrid);
  p_m_clrGrid->_color[0] = Options.colors.clrGrid;
  p_m_clrGrid->_color[1] = v5;
  p_m_clrGrid->_color[2] = v2;
  p_m_clrGrid->_color[3] = -1;
  if ( Options.colors.bScaleGridColor )
    CMapView2DBase::AdjustColorIntensity(this, color: p_m_clrGrid, nIntensity: Options.view2d.iGridIntensity);
  v6 = BYTE2(Options.colors.clrGrid10);
  v7 = BYTE1(Options.colors.clrGrid10);
  this->m_clrGridCustom._color[0] = Options.colors.clrGrid10;
  this->m_clrGridCustom._color[1] = v7;
  this->m_clrGridCustom._color[2] = v6;
  this->m_clrGridCustom._color[3] = -1;
  if ( Options.colors.bScaleGrid10Color )
    CMapView2DBase::AdjustColorIntensity(
      this,
      color: &this->m_clrGridCustom,
      nIntensity: (int)((double)Options.view2d.iGridIntensity * 1.5));
  v8 = BYTE2(Options.colors.clrGrid1024);
  v9 = BYTE1(Options.colors.clrGrid1024);
  this->m_clrGrid1024._color[0] = Options.colors.clrGrid1024;
  this->m_clrGrid1024._color[1] = v9;
  this->m_clrGrid1024._color[2] = v8;
  this->m_clrGrid1024._color[3] = -1;
  if ( Options.colors.bScaleGrid1024Color )
    CMapView2DBase::AdjustColorIntensity(this, color: &this->m_clrGrid1024, nIntensity: Options.view2d.iGridIntensity);
  v10 = BYTE2(Options.colors.clrGridDot);
  v11 = BYTE1(Options.colors.clrGridDot);
  this->m_clrGridDot._color[0] = Options.colors.clrGridDot;
  this->m_clrGridDot._color[1] = v11;
  this->m_clrGridDot._color[2] = v10;
  this->m_clrGridDot._color[3] = -1;
  if ( Options.colors.bScaleGridDotColor )
    CMapView2DBase::AdjustColorIntensity(
      this,
      color: &this->m_clrGridDot,
      nIntensity: Options.view2d.iGridIntensity + 20);
  v12 = BYTE2(Options.colors.clrAxis);
  v13 = BYTE1(Options.colors.clrAxis);
  this->m_clrAxis._color[0] = Options.colors.clrAxis;
  this->m_clrAxis._color[1] = v13;
  this->m_clrAxis._color[2] = v12;
  this->m_clrAxis._color[3] = -1;
  if ( Options.colors.bScaleAxisColor )
    CMapView2DBase::AdjustColorIntensity(this, color: &this->m_clrAxis, nIntensity: Options.view2d.iGridIntensity);
  clrBackground = Options.colors.clrBackground;
  this->m_ClearColor._color[0] = Options.colors.clrBackground;
  this->m_ClearColor._color[3] = -1;
  this->m_ClearColor._color[1] = BYTE1(clrBackground);
  this->m_ClearColor._color[2] = BYTE2(clrBackground);
  this->m_bClearZBuffer = false;
}

//------------------------------------------------------------------------------
// Address: 0x1007F000
// Name: public: void CMapView2DBase::UpdateClientView(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CMapView2DBase::UpdateClientView(CMapView2DBase *this)
{
  int v2; // ecx
  float v3; // xmm0_4
  float v4; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm4_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  int axHorz; // ecx
  int v11; // eax
  double v12; // st7
  float m_fClientHeightHalf; // xmm0_4
  int axVert; // eax
  int v15; // eax
  float v16; // xmm1_4
  float v17; // xmm2_4
  int axThird; // eax
  int v19; // eax
  void (__thiscall *ClientToWorld)(CMapView *, Vector *, const Vector2D *); // edx
  HWND__ *m_hWnd; // [esp-4h] [ebp-E4h]
  HWND__ *v22; // [esp+0h] [ebp-E0h]
  char pszText[8]; // [esp+10h] [ebp-D0h] BYREF
  float v24[2]; // [esp+90h] [ebp-50h] BYREF
  _DWORD v25[2]; // [esp+98h] [ebp-48h] BYREF
  tagSCROLLINFO ScrollInfo; // [esp+A0h] [ebp-40h] BYREF
  __int64 v27; // [esp+BCh] [ebp-24h]
  tagRECT v28; // [esp+C4h] [ebp-1Ch] BYREF
  __int64 v29; // [esp+D4h] [ebp-Ch]
  float rectClient; // [esp+DCh] [ebp-4h] OVERLAPPED

  if ( IsWindow(hWnd: this->m_hWnd) )
  {
    this->m_fZoom = CCamera::GetZoom(this: this->m_pCamera);
    CCamera::GetViewPoint(this: this->m_pCamera, ViewPoint: &this->m_vViewOrigin);
    m_hWnd = this->m_hWnd;
    memset(&v28, 0, sizeof(v28));
    GetClientRect(hWnd: m_hWnd, lpRect: &v28);
    v2 = v28.bottom - v28.top;
    v3 = (float)(v28.right - v28.left);
    v4 = 1.0 / this->m_fZoom;
    rectClient = v3 * v4;
    v5 = (float)(v28.bottom - v28.top);
    *((float *)&v29 + 1) = v5 * v4;
    this->m_ClientWidth = v28.right - v28.left;
    this->m_ClientHeight = v2;
    v6 = v3 * 0.5;
    this->m_fClientWidthHalf = v3 * 0.5;
    this->m_fClientHeightHalf = v5 * 0.5;
    v7 = 1.0
       / (float)(COERCE_FLOAT(LODWORD(g_MIN_MAP_COORD) & _mask__AbsFloat_)
               + COERCE_FLOAT(LODWORD(g_MAX_MAP_COORD) & _mask__AbsFloat_));
    v8 = v3 * v7;
    v9 = v5 * v7;
    if ( v9 <= v8 )
      v8 = v9;
    this->m_flMinZoom = v8;
    if ( Options.view2d.bScrollbars != 0 )
    {
      HIDWORD(v27) = HIWORD(rectClient) | 0xC00;
      ScrollInfo.nMin = (int)(float)(g_MIN_MAP_COORD - v6);
      axHorz = this->axHorz;
      ScrollInfo.cbSize = 28;
      ScrollInfo.fMask = 7;
      v27 = (__int64)rectClient;
      ScrollInfo.nMax = (int)(float)(v6 + g_MAX_MAP_COORD);
      ScrollInfo.nPage = v27;
      v11 = (int)*(&this->m_vViewOrigin.x + axHorz);
      ScrollInfo.nPos = v11;
      if ( this->bInvertHorz )
        ScrollInfo.nPos = -v11;
      CWnd::SetScrollInfo(this, nBar: 0, lpScrollInfo: &ScrollInfo, bRedraw: 1);
      v12 = *((float *)&v29 + 1);
      m_fClientHeightHalf = this->m_fClientHeightHalf;
      ScrollInfo.nMin = (int)(float)(g_MIN_MAP_COORD - m_fClientHeightHalf);
      HIDWORD(v29) = HIWORD(rectClient) | 0xC00;
      axVert = this->axVert;
      ScrollInfo.nMax = (int)(float)(m_fClientHeightHalf + g_MAX_MAP_COORD);
      v29 = (__int64)v12;
      ScrollInfo.nPage = (__int64)v12;
      v15 = (int)*(&this->m_vViewOrigin.x + axVert);
      ScrollInfo.nPos = v15;
      if ( this->bInvertVert )
        ScrollInfo.nPos = -v15;
      CWnd::SetScrollInfo(this, nBar: 1, lpScrollInfo: &ScrollInfo, bRedraw: 1);
    }
    else
    {
      ShowScrollBar(hWnd: this->m_hWnd, wBar: 0, bShow: false);
      ShowScrollBar(hWnd: this->m_hWnd, wBar: 1, bShow: false);
    }
    this->m_vViewAxis.x = 0.0;
    this->m_vViewAxis.y = 0.0;
    this->m_vViewAxis.z = 0.0;
    *((_DWORD *)&this->m_vViewAxis.x + this->axThird) = 1065353216;
    if ( this->bInvertHorz && this->bInvertVert )
    {
      v16 = -this->m_vViewAxis.y;
      v17 = -this->m_vViewAxis.z;
      this->m_vViewAxis.x = -this->m_vViewAxis.x;
      this->m_vViewAxis.y = v16;
      this->m_vViewAxis.z = v17;
    }
    CCamera::SetViewPort(this: this->m_pCamera, width: this->m_ClientWidth, height: this->m_ClientHeight);
    CCamera::SetYaw(this: this->m_pCamera, fDegrees: 0.0);
    CCamera::SetPitch(this: this->m_pCamera, fDegrees: 0.0);
    CCamera::SetRoll(this: this->m_pCamera, fDegrees: 0.0);
    axThird = this->axThird;
    if ( axThird != 0 )
    {
      v19 = axThird - 1;
      if ( v19 != 0 )
      {
        if ( v19 == 1 )
          CCamera::SetPitch(this: this->m_pCamera, fDegrees: 90.0);
      }
      else
      {
        CCamera::SetRoll(this: this->m_pCamera, fDegrees: 0.0);
      }
    }
    else
    {
      CCamera::SetYaw(this: this->m_pCamera, fDegrees: -90.0);
    }
    ClientToWorld = this->ClientToWorld;
    v25[0] = 0;
    v25[1] = 0;
    v24[0] = (float)this->m_ClientWidth;
    v24[1] = (float)this->m_ClientHeight;
    ClientToWorld(this: &this->CMapView, a2: &this->m_ViewMin, a3: (const Vector2D *)v25);
    this->ClientToWorld(this: &this->CMapView, a2: &this->m_ViewMax, a3: (const Vector2D *)v24);
    *(&this->m_ViewMin.x + this->axThird) = g_MIN_MAP_COORD;
    *(&this->m_ViewMax.x + this->axThird) = g_MAX_MAP_COORD;
    NormalizeBox(mins: &this->m_ViewMin, maxs: &this->m_ViewMax);
    this->OnRenderListDirty(this);
    v22 = this->m_hWnd;
    this->m_bUpdateView = true;
    if ( IsWindow(hWnd: v22) )
    {
      sprintf(string: pszText, format: " Zoom: %.2f ", this->m_fZoom);
      SetStatusText(nIndex: 4, pszText);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007F460
// Name: protected: void CMapView2DBase::OnKeyUp(unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapView2DBase::OnKeyUp(
        CMapView2DBase *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        unsigned int nChar,
        unsigned int nRepCnt,
        unsigned int nFlags)
{
  CToolManager *m_pToolManager; // ecx
  int ActiveTool; // esi
  char v9; // al

  m_pToolManager = this->m_pToolManager;
  if ( m_pToolManager != nullptr )
  {
    if ( nChar == 32 )
    {
      CVGuiWnd::SetCursor(this: &this->CVGuiWnd, cursor: 2u);
      CWnd::Default(this);
    }
    else
    {
      ActiveTool = CToolManager::GetActiveTool(this: (CSelection *)m_pToolManager);
      if ( ActiveTool == 0
        || (((unsigned __int8 (__thiscall *)(CMapView2DBase *, int, int))this->IsLogical)(a1: this, a2: a3, a3: a2) == 0
          ? (v9 = (*(int (__thiscall **)(int, CMapView2DBase *, unsigned int))(*(_DWORD *)ActiveTool + 136))(
                    a1: ActiveTool,
                    a2: this,
                    a3: nChar))
          : (v9 = (*(int (__thiscall **)(int, CMapView2DBase *, unsigned int))(*(_DWORD *)ActiveTool + 180))(
                    a1: ActiveTool,
                    a2: this,
                    a3: nChar)),
            v9 == 0) )
      {
        CWnd::Default(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007F4F0
// Name: protected: void CMapView2DBase::OnChar(unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapView2DBase::OnChar(
        CMapView2DBase *this@<ecx>,
        int a2@<esi>,
        unsigned int nChar,
        unsigned int nRepCnt,
        unsigned int nFlags)
{
  CToolManager *m_pToolManager; // ecx
  int *ActiveTool; // esi
  char v8; // al
  bool v9; // zf
  int v10; // eax
  char v11; // al

  m_pToolManager = this->m_pToolManager;
  if ( m_pToolManager != nullptr )
  {
    ActiveTool = (int *)CToolManager::GetActiveTool(this: (CSelection *)m_pToolManager);
    if ( ActiveTool == nullptr
      || ((v8 = ((int (__thiscall *)(CMapView2DBase *, int))this->IsLogical)(a1: this, a2),
           v9 = v8 == 0,
           v10 = *ActiveTool,
           v9)
        ? (v11 = (*(int (__stdcall **)(CMapView2DBase *))(v10 + 140))(a1: this))
        : (v11 = (*(int (__stdcall **)(CMapView2DBase *))(v10 + 184))(a1: this)),
          v11 == 0) )
    {
      CWnd::Default(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007F550
// Name: protected: void CMapView2DBase::OnLButtonDown(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapView2DBase::OnLButtonDown(
        CMapView2DBase *this@<ecx>,
        int a2@<edi>,
        unsigned int nFlags,
        CPoint point)
{
  HWND v5; // eax
  int ActiveTool; // edi
  char v7; // al
  HWND__ *m_hWnd; // [esp-4h] [ebp-10h]

  if ( this->m_pToolManager != nullptr )
  {
    if ( GetAsyncKeyState(vKey: 32) >= 0 )
    {
      ActiveTool = CToolManager::GetActiveTool(this: (CSelection *)this->m_pToolManager);
      if ( ActiveTool == 0
        || (((unsigned __int8 (__thiscall *)(CMapView2DBase *, int))this->IsLogical)(a1: this, a2) == 0
          ? (v7 = (*(int (__thiscall **)(int, CMapView2DBase *, unsigned int))(*(_DWORD *)ActiveTool + 104))(
                    a1: ActiveTool,
                    a2: this,
                    a3: nFlags))
          : (v7 = (*(int (__thiscall **)(int, CMapView2DBase *, unsigned int))(*(_DWORD *)ActiveTool + 148))(
                    a1: ActiveTool,
                    a2: this,
                    a3: nFlags)),
            v7 == 0) )
      {
        this->m_ptLDownClient = point.tagPOINT;
        CWnd::Default(this);
      }
    }
    else
    {
      m_hWnd = this->m_hWnd;
      this->m_bMouseDrag = true;
      this->m_ptLDownClient = point.tagPOINT;
      s_fDragRestY = 0.0;
      s_fDragRestX = 0.0;
      v5 = SetCapture(hWnd: m_hWnd);
      CWnd::FromHandle(hWnd: v5);
      CVGuiWnd::SetCursor(this: &this->CVGuiWnd, filename: "Resource/ifm_grab.cur");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007F660
// Name: public: virtual void CMapView2DBase::UpdateView(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2DBase::UpdateView(CMapView2DBase *this, __int16 nFlags)
{
  __int16 v2; // bx
  int m_hVGuiContext; // eax

  v2 = nFlags;
  if ( (nFlags & 0x40) == 0 )
  {
    if ( (*(unsigned __int8 (__thiscall **)(char *))(*((_DWORD *)this - 31) + 436))(a1: (char *)this - 124) != 0 )
    {
      if ( (nFlags & 0x20) != 0 )
        return;
    }
    else if ( (nFlags & 0x80u) != 0 )
    {
      return;
    }
    if ( (nFlags & 0x100) != 0 )
    {
      ShowScrollBar(hWnd: *((HWND *)this - 23), wBar: 0, bShow: Options.view2d.bScrollbars);
      ShowScrollBar(hWnd: *((HWND *)this - 23), wBar: 1, bShow: Options.view2d.bScrollbars);
      CMapView2DBase::SetColorMode(
        this: (CMapView2DBase *)((char *)this - 124),
        bWhiteOnBlack: Options.view2d.bWhiteOnBlack != 0);
      CMapView2DBase::UpdateClientView(this: (CMapView2DBase *)((char *)this - 124));
      v2 = nFlags;
    }
    if ( (v2 & 0x601) != 0 )
      (*(void (__thiscall **)(char *))(*((_DWORD *)this - 31) + 440))(a1: (char *)this - 124);
    m_hVGuiContext = this->m_hVGuiContext;
    if ( m_hVGuiContext != 0 )
      InvalidateRect(hWnd: *(HWND *)(m_hVGuiContext + 32), lpRect: nullptr, bErase: false);
    CMapView::UpdateView((CMapView *)this, nFlags: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007F730
// Name: protected: void CMapView2DBase::OnRButtonDown(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapView2DBase::OnRButtonDown(
        CMapView2DBase *this@<ecx>,
        int a2@<esi>,
        unsigned int nFlags,
        CPoint point)
{
  CToolManager *m_pToolManager; // ecx
  int ActiveTool; // esi
  char v7; // al

  m_pToolManager = this->m_pToolManager;
  if ( m_pToolManager != nullptr )
  {
    ActiveTool = CToolManager::GetActiveTool(this: (CSelection *)m_pToolManager);
    if ( ActiveTool == 0
      || (((unsigned __int8 (__thiscall *)(CMapView2DBase *, int))this->IsLogical)(a1: this, a2) == 0
        ? (v7 = (*(int (__thiscall **)(int, CMapView2DBase *, unsigned int))(*(_DWORD *)ActiveTool + 116))(
                  a1: ActiveTool,
                  a2: this,
                  a3: nFlags))
        : (v7 = (*(int (__thiscall **)(int, CMapView2DBase *, unsigned int))(*(_DWORD *)ActiveTool + 160))(
                  a1: ActiveTool,
                  a2: this,
                  a3: nFlags)),
          v7 == 0) )
    {
      CWnd::Default(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007F7C0
// Name: public: void CMapView2DBase::OnContextMenu(unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapView2DBase::OnContextMenu(
        CMapView2DBase *this@<ecx>,
        int a2@<esi>,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  CToolManager *m_pToolManager; // ecx
  int ActiveTool; // esi
  char v7; // al
  AFX_MODULE_STATE *ModuleState; // eax
  HMENU MenuW; // eax
  HMENU SubMenu; // eax
  float x; // xmm1_4
  float y; // xmm0_4
  HWND__ *m_hWnd; // [esp-Ch] [ebp-24h]
  CPoint ptScreen; // [esp+4h] [ebp-14h] BYREF
  int v16; // [esp+14h] [ebp-4h]

  if ( !this->m_bMouseDrag )
  {
    m_pToolManager = this->m_pToolManager;
    if ( m_pToolManager != nullptr )
    {
      ActiveTool = CToolManager::GetActiveTool(this: (CSelection *)m_pToolManager);
      if ( ActiveTool == 0
        || (((unsigned __int8 (__thiscall *)(CMapView2DBase *, int))this->IsLogical)(a1: this, a2) == 0
          ? (v7 = (*(int (__thiscall **)(int, CMapView2DBase *, unsigned int))(*(_DWORD *)ActiveTool + 100))(
                    a1: ActiveTool,
                    a2: this,
                    a3: nFlags))
          : (v7 = (*(int (__thiscall **)(int, CMapView2DBase *, unsigned int))(*(_DWORD *)ActiveTool + 144))(
                    a1: ActiveTool,
                    a2: this,
                    a3: nFlags)),
            v7 == 0) )
      {
        if ( (_S3_1 & 1) == 0 )
        {
          _S3_1 |= 1u;
          menu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
          menu.m_hMenu = nullptr;
          atexit(func: CMapView2DBase::OnContextMenu_::_17_::_dynamic_atexit_destructor_for__menu__);
          v16 = -1;
        }
        if ( (_S3_1 & 2) == 0 )
        {
          _S3_1 |= 2u;
          menuDefault.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
          menuDefault.m_hMenu = nullptr;
          atexit(func: CMapView2DBase::OnContextMenu_::_17_::_dynamic_atexit_destructor_for__menuDefault__);
          v16 = -1;
        }
        if ( !bInit )
        {
          bInit = true;
          ModuleState = AfxGetModuleState();
          MenuW = LoadMenuW(hInstance: ModuleState->m_hCurrentResourceHandle, lpMenuName: (LPCWSTR)0xB6);
          CMenu::Attach(this: &menu, hMenu: MenuW);
          SubMenu = GetSubMenu(hMenu: menu.m_hMenu, nPos: 2);
          CMenu::Attach(this: &menuDefault, hMenu: SubMenu);
        }
        x = vPoint->x;
        if ( vPoint->x >= 0.0 )
        {
          y = vPoint->y;
          if ( y >= 0.0 && (float)this->m_ClientWidth > x && (float)this->m_ClientHeight > y )
          {
            ptScreen.x = (int)x;
            m_hWnd = this->m_hWnd;
            ptScreen.y = (int)y;
            ClientToScreen(hWnd: m_hWnd, lpPoint: &ptScreen);
            CMenu::TrackPopupMenu(
              this: &menuDefault,
              nFlags: 2u,
              x: ptScreen.x,
              y: ptScreen.y,
              pWnd: this,
              lpRect: nullptr);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007F980
// Name: protected: void CMapView2DBase::OnSize(unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2DBase::OnSize(CMapView2DBase *this, unsigned int nType, unsigned int cx, int cy)
{
  CWnd::Default(this);
  CMapView2DBase::UpdateClientView(this);
}

//------------------------------------------------------------------------------
// Address: 0x1007F9A0
// Name: protected: void CMapView2DBase::OnRButtonUp(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapView2DBase::OnRButtonUp(
        CMapView2DBase *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        unsigned int nFlags,
        CPoint point)
{
  CToolManager *m_pToolManager; // ecx
  int *ActiveTool; // esi
  char v8; // al
  bool v9; // zf
  int v10; // eax
  Vector2D vPoint; // [esp+4h] [ebp-8h] BYREF

  m_pToolManager = this->m_pToolManager;
  if ( m_pToolManager != nullptr )
  {
    ActiveTool = (int *)CToolManager::GetActiveTool(this: (CSelection *)m_pToolManager);
    if ( ActiveTool != nullptr )
    {
      v8 = ((int (__thiscall *)(CMapView2DBase *, int, int))this->IsLogical)(a1: this, a2: a3, a3: a2);
      vPoint.x = (float)point.x;
      v9 = v8 == 0;
      v10 = *ActiveTool;
      vPoint.y = (float)point.y;
      if ( v9 )
        (*(void (__fastcall **)(int *))(v10 + 120))(a1: ActiveTool);
      else
        (*(void (__fastcall **)(int *))(v10 + 164))(a1: ActiveTool);
    }
    vPoint.x = (float)point.x;
    vPoint.y = (float)point.y;
    CMapView2DBase::OnContextMenu(this, a2: (int)ActiveTool, nFlags, &vPoint);
    CWnd::Default(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007FA40
// Name: protected: void CMapView2DBase::DrawGrid(class CRender2D __near *,int,int,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapView2DBase::DrawGrid(
        CMapView2DBase *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        CRender2D *pRender,
        int xAxis,
        int yAxis,
        float depth,
        bool bNoSmallGrid)
{
  CMapDoc *v9; // eax
  int m_nGridSpacing; // eax
  int v11; // edi
  float m_fZoom; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  int v17; // edx
  float v18; // xmm0_4
  int v19; // ecx
  float v20; // xmm4_4
  int v21; // eax
  float v22; // xmm0_4
  float v23; // xmm4_4
  float v24; // xmm0_4
  float v25; // xmm2_4
  int v26; // eax
  CRender2D *v27; // edi
  IMatRenderContext *v28; // eax
  IMatRenderContext *v29; // ebx
  void (__thiscall *WorldToClient)(CMapView *, Vector2D *, const Vector *); // edx
  int v31; // edi
  int v32; // ebx
  float v33; // xmm2_4
  float *m_pCurrPosition; // eax
  int v35; // ecx
  float v36; // xmm0_4
  float *v37; // eax
  float v38; // xmm1_4
  int m_nVertexCount; // eax
  int v40; // ebx
  char v41; // al
  int i; // ebx
  char v43; // al
  float *v44; // eax
  int m_nIndexCount; // [esp-8h] [ebp-26Ch]
  CMeshBuilder *p_meshBuilder; // [esp-4h] [ebp-268h]
  CMeshBuilder meshBuilder; // [esp+4h] [ebp-260h] BYREF
  CMatRenderContextPtr pRenderContext; // [esp+1ECh] [ebp-78h]
  float v50; // [esp+1F0h] [ebp-74h]
  float *v51; // [esp+1F4h] [ebp-70h]
  float v52; // [esp+1F8h] [ebp-6Ch]
  Vector vPoint; // [esp+1FCh] [ebp-68h] BYREF
  int v54; // [esp+208h] [ebp-5Ch]
  IMatRenderContext *v55; // [esp+20Ch] [ebp-58h]
  float roundfx; // [esp+210h] [ebp-54h]
  float *v57; // [esp+214h] [ebp-50h]
  float fOffset; // [esp+218h] [ebp-4Ch]
  Vector vPointMax; // [esp+21Ch] [ebp-48h] BYREF
  Vector vPointMin; // [esp+228h] [ebp-3Ch] BYREF
  Vector2D v2D; // [esp+234h] [ebp-30h] BYREF
  int y; // [esp+23Ch] [ebp-28h]
  int xMin; // [esp+240h] [ebp-24h]
  int yMin; // [esp+244h] [ebp-20h]
  int xMax; // [esp+248h] [ebp-1Ch]
  int yMax; // [esp+24Ch] [ebp-18h]
  IMesh *pMesh; // [esp+250h] [ebp-14h]
  int nGridSpacing; // [esp+254h] [ebp-10h]
  int v69; // [esp+260h] [ebp-4h]
  float *xAxisa; // [esp+270h] [ebp+Ch]

  v9 = this->GetMapDoc(this: &this->CMapView);
  if ( v9 != nullptr )
  {
    m_nGridSpacing = v9->m_nGridSpacing;
    if ( m_nGridSpacing <= 1 )
    {
      nGridSpacing = 1;
      v11 = 1;
    }
    else
    {
      v11 = m_nGridSpacing;
      nGridSpacing = m_nGridSpacing;
    }
    m_fZoom = this->m_fZoom;
    if ( (float)((float)v11 * m_fZoom) < 2.0 )
    {
      do
      {
        v13 = (float)(2 * v11) * m_fZoom;
        nGridSpacing = 2 * v11;
        v11 *= 2;
      }
      while ( v13 < 2.0 );
    }
    v14 = (float)v11;
    v52 = (float)v11;
    if ( (float)(m_fZoom * (float)v11) < 4.0 && Options.view2d.bHideSmallGrid != 0 )
      bNoSmallGrid = true;
    s_bGridDots = Options.view2d.bGridDots != 0;
    v15 = *(&this->m_ViewMin.x + xAxis) - v14;
    s_iCustomGridSpacing = v11 * Options.view2d.iGridHighSpec;
    if ( g_MIN_MAP_COORD <= v15 )
      v16 = v15;
    else
      v16 = g_MIN_MAP_COORD;
    if ( g_MIN_MAP_COORD > v15 )
      v15 = g_MIN_MAP_COORD;
    v17 = (int)v15 % v11;
    v18 = *(&this->m_ViewMax.x + xAxis) + v14;
    v19 = (int)v16 - v17;
    xMin = v19;
    if ( v18 <= g_MAX_MAP_COORD )
      v20 = v18;
    else
      v20 = g_MAX_MAP_COORD;
    if ( v18 > g_MAX_MAP_COORD )
      v18 = g_MAX_MAP_COORD;
    v21 = (int)v20 - (int)v18 % v11;
    v22 = *(&this->m_ViewMin.x + yAxis) - v14;
    xMax = v21;
    if ( g_MIN_MAP_COORD <= v22 )
      v23 = v22;
    else
      v23 = g_MIN_MAP_COORD;
    if ( g_MIN_MAP_COORD > v22 )
      v22 = g_MIN_MAP_COORD;
    yMin = (int)v23 - (int)v22 % v11;
    v24 = *(&this->m_ViewMax.x + yAxis) + v14;
    if ( v24 <= g_MAX_MAP_COORD )
      v25 = *(&this->m_ViewMax.x + yAxis) + v14;
    else
      v25 = g_MAX_MAP_COORD;
    if ( v24 > g_MAX_MAP_COORD )
      v24 = g_MAX_MAP_COORD;
    vPointMin.x = depth;
    vPointMin.y = depth;
    vPointMin.z = depth;
    vPointMax.x = depth;
    vPointMax.y = depth;
    vPointMax.z = depth;
    *(&vPointMin.x + xAxis) = (float)v19;
    v50 = (float)v19;
    *(&vPointMax.x + xAxis) = (float)xMax;
    v26 = (int)v25 - (int)v24 % v11;
    v57 = &vPointMin.x + xAxis;
    yMax = v26;
    v51 = &vPointMax.x + xAxis;
    if ( !s_bGridDots || bNoSmallGrid )
    {
      v27 = pRender;
    }
    else
    {
      v27 = pRender;
      CRender::BeginClientSpace(this: pRender);
      CMeshBuilder::CMeshBuilder(this: &meshBuilder);
      v69 = 0;
      v28 = (IMatRenderContext *)((int (__thiscall *)(IMaterialSystem *, int, int))materials->GetRenderContext)(
                                   a1: materials,
                                   a2,
                                   a3);
      v29 = v28;
      v55 = v28;
      pRenderContext.m_pObject = v28;
      LOBYTE(v69) = 1;
      if ( v28 != nullptr )
        v28->BeginRender(this: v28);
      LOBYTE(v69) = 2;
      p_meshBuilder = nullptr;
      m_nIndexCount = 0;
      pMesh = (IMesh *)((int (__thiscall *)(IMatRenderContext *, int, _DWORD))v29->GetDynamicMesh)(
                         a1: v29,
                         a2: 1,
                         a3: 0);
      y = yMin;
      if ( yMin <= yMax )
      {
        xAxisa = &vPoint.x + xAxis;
        v54 = (int)abs32(xMax - xMin) / nGridSpacing + 1;
        do
        {
          WorldToClient = this->WorldToClient;
          vPoint.x = depth;
          vPoint.y = depth;
          vPoint.z = depth;
          *(&vPoint.x + yAxis) = (float)y;
          *xAxisa = v50;
          ((void (__thiscall *)(CMapView *, Vector2D *, Vector *, int, CMeshBuilder *))WorldToClient)(
            a1: &this->CMapView,
            a2: &v2D,
            a3: &vPoint,
            a4: m_nIndexCount,
            a5: p_meshBuilder);
          v31 = v54;
          v2D.y = (float)(int)(float)(v2D.y + 0.5);
          meshBuilder.m_pMesh = pMesh;
          meshBuilder.m_bGenerateIndices = true;
          meshBuilder.m_Type = MATERIAL_LINES;
          v32 = 2 * v54;
          pMesh->SetPrimitiveType(this: pMesh, a2: MATERIAL_LINES);
          meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: v32, a3: v32, a4: &meshBuilder, a5: nullptr);
          meshBuilder.m_IndexBuilder.m_pIndexBuffer = &pMesh->IIndexBuffer;
          meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
          meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
          meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
          meshBuilder.m_IndexBuilder.m_bModify = false;
          meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
          meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
          meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v32;
          CVertexBuilder::AttachBegin(
            this: &meshBuilder.m_VertexBuilder,
            pMesh,
            nMaxVertexCount: v32,
            desc: &meshBuilder);
          meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
          CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
          v33 = v52 * this->m_fZoom;
          fOffset = v33;
          if ( v31 > 0 )
          {
            while ( 1 )
            {
              m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
              v35 = (int)(float)(v2D.x + 0.5);
              v2D.x = v2D.x + v33;
              v36 = v2D.y;
              *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)v35;
              m_pCurrPosition[1] = v36;
              m_pCurrPosition[2] = 0.0;
              *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_clrGridDot._color[2]
                                                                  | ((this->m_clrGridDot._color[1]
                                                                    | ((this->m_clrGridDot._color[0]
                                                                      | (this->m_clrGridDot._color[3] << 8)) << 8)) << 8);
              roundfx = (float)v35;
              CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
              v37 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
              v38 = v2D.y;
              *meshBuilder.m_VertexBuilder.m_pCurrPosition = roundfx + 1.0;
              v37[1] = v38;
              v37[2] = 0.0;
              *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = this->m_clrGridDot._color[2]
                                                                  | ((this->m_clrGridDot._color[1]
                                                                    | ((this->m_clrGridDot._color[0]
                                                                      | (this->m_clrGridDot._color[3] << 8)) << 8)) << 8);
              CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
              if ( --v31 <= 0 )
                break;
              v33 = fOffset;
            }
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
          p_meshBuilder = &meshBuilder;
          m_nIndexCount = meshBuilder.m_IndexBuilder.m_nIndexCount;
          ((void (__thiscall *)(IMesh *, int))meshBuilder.m_pMesh->UnlockMesh)(
            a1: meshBuilder.m_pMesh,
            a2: meshBuilder.m_VertexBuilder.m_nVertexCount);
          meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
          meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
          meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
          meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
          meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
          meshBuilder.m_pMesh = nullptr;
          pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
          y += nGridSpacing;
        }
        while ( y <= yMax );
        v27 = pRender;
        v29 = v55;
      }
      CRender::EndClientSpace(this: v27);
      LOBYTE(v69) = 3;
      v29->EndRender(this: v29);
      LOBYTE(v69) = 0;
      v29->Release(this: v29);
      v69 = -1;
      CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
      v26 = yMax;
      v19 = xMin;
    }
    v40 = yMin;
    if ( yMin <= v26 )
    {
      do
      {
        CRender::SetDrawColor(this: v27, color: &this->m_clrGrid);
        v41 = CMapView2DBase::HighlightGridLine(this, pRender: v27, nGridLine: v40);
        if ( (v41 != 0 || !bNoSmallGrid)
          && (!s_bGridDots || v41 != 0 || (float)v40 == g_MAX_MAP_COORD || (float)v40 == g_MIN_MAP_COORD) )
        {
          *(&vPointMax.x + yAxis) = (float)v40;
          *(&vPointMin.x + yAxis) = (float)v40;
          CRender::DrawLine(this: v27, vStart: &vPointMin, vEnd: &vPointMax);
        }
        v40 += nGridSpacing;
      }
      while ( v40 <= yMax );
      v26 = yMax;
      v19 = xMin;
    }
    *(&vPointMin.x + yAxis) = (float)yMin;
    *(&vPointMax.x + yAxis) = (float)v26;
    for ( i = v19; i <= xMax; i += nGridSpacing )
    {
      CRender::SetDrawColor(this: v27, color: &this->m_clrGrid);
      v43 = CMapView2DBase::HighlightGridLine(this, pRender: v27, nGridLine: i);
      if ( (v43 != 0 || !bNoSmallGrid)
        && (!s_bGridDots || v43 != 0 || (float)i == g_MAX_MAP_COORD || (float)i == g_MIN_MAP_COORD) )
      {
        v44 = v57;
        *v51 = (float)i;
        *v44 = (float)i;
        CRender::DrawLine(this: v27, vStart: &vPointMin, vEnd: &vPointMax);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100801A0
// Name: public: void CMapView2DBase::SetViewOrigin(float,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2DBase::SetViewOrigin(CMapView2DBase *this, float fHorz, float fVert, bool bRelative)
{
  int axHorz; // ecx
  bool v6; // zf
  float *v7; // ecx
  int axVert; // eax
  int axThird; // eax
  Vector vCurPos; // [esp+4h] [ebp-Ch] BYREF

  CCamera::GetViewPoint(this: this->m_pCamera, ViewPoint: &vCurPos);
  if ( bRelative )
  {
    if ( fHorz == 0.0 && fVert == 0.0 )
      return;
    *(&vCurPos.x + this->axHorz) = *(&vCurPos.x + this->axHorz) + fHorz;
    *(&vCurPos.x + this->axVert) = *(&vCurPos.x + this->axVert) + fVert;
  }
  else
  {
    axHorz = this->axHorz;
    v6 = fHorz == *(&vCurPos.x + axHorz);
    v7 = &vCurPos.x + axHorz;
    if ( v6 && fVert == *(&vCurPos.x + this->axVert) )
      return;
    axVert = this->axVert;
    *v7 = fHorz;
    *(&vCurPos.x + axVert) = fVert;
  }
  axThird = this->axThird;
  if ( axThird == 1 )
    vCurPos.y = g_MIN_MAP_COORD;
  else
    *(&vCurPos.x + axThird) = g_MAX_MAP_COORD;
  CCamera::SetViewPoint(this: this->m_pCamera, ViewPoint: &vCurPos);
  CMapView2DBase::UpdateClientView(this);
}

//------------------------------------------------------------------------------
// Address: 0x100802A0
// Name: public: void CMapView2DBase::SetZoom(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2DBase::SetZoom(CMapView2DBase *this, float fNewZoom)
{
  float m_flMinZoom; // xmm0_4
  float y_low; // xmm1_4
  bool v5; // zf
  int v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm2_4
  CCamera *m_pCamera; // ecx
  int v10; // xmm1_4
  int axHorz; // ecx
  float *v12; // ecx
  int axThird; // eax
  int v14; // [esp+8h] [ebp-30h] BYREF
  Vector vecWorld; // [esp+14h] [ebp-24h] BYREF
  Vector ViewPoint; // [esp+20h] [ebp-18h] BYREF
  tagPOINT ptClient; // [esp+2Ch] [ebp-Ch] BYREF
  Vector2D newOrigin; // [esp+34h] [ebp-4h]
  float fOldZoom; // [esp+40h] [ebp+8h]

  newOrigin.x = CCamera::GetZoom(this: this->m_pCamera);
  m_flMinZoom = this->m_flMinZoom;
  if ( m_flMinZoom <= fNewZoom )
  {
    m_flMinZoom = 256.0;
    if ( fNewZoom <= 256.0 )
      m_flMinZoom = fNewZoom;
  }
  fOldZoom = m_flMinZoom;
  if ( newOrigin.x != m_flMinZoom && IsWindow(hWnd: this->m_hWnd) )
  {
    GetCursorPos(lpPoint: (LPPOINT)&ViewPoint);
    ScreenToClient(hWnd: this->m_hWnd, lpPoint: (LPPOINT)&ViewPoint);
    y_low = (float)SLODWORD(ViewPoint.y);
    *(float *)&ptClient.y = (float)SLODWORD(ViewPoint.x);
    newOrigin.x = (float)SLODWORD(ViewPoint.y);
    if ( (float)SLODWORD(ViewPoint.x) < 0.0
      || y_low < 0.0
      || (float)this->m_ClientWidth <= (float)SLODWORD(ViewPoint.x)
      || (float)this->m_ClientHeight <= y_low )
    {
      ptClient.y = LODWORD(this->m_fClientWidthHalf);
      newOrigin.x = this->m_fClientHeightHalf;
    }
    this->ClientToWorld(this: &this->CMapView, a2: (Vector *)&v14, a3: (const Vector2D *)&ptClient.y);
    v5 = !this->bInvertVert;
    *(float *)&v6 = (float)(1.0 / m_flMinZoom) * (float)(*(float *)&ptClient.y - this->m_fClientWidthHalf);
    v7 = (float)(1.0 / m_flMinZoom) * (float)(newOrigin.x - this->m_fClientHeightHalf);
    *(float *)&ptClient.y = (float)(1.0 / fOldZoom) * (float)(*(float *)&ptClient.y - this->m_fClientWidthHalf);
    newOrigin.x = v7;
    if ( !v5 )
    {
      v7 = -v7;
      newOrigin.x = v7;
    }
    if ( this->bInvertHorz )
    {
      *(float *)&v6 = -*(float *)&v6;
      ptClient.y = v6;
    }
    v8 = *((float *)&v14 + this->axHorz) - *(float *)&v6;
    m_pCamera = this->m_pCamera;
    *(float *)&v10 = *((float *)&v14 + this->axVert) - v7;
    ViewPoint.z = v8;
    ptClient.x = v10;
    CCamera::SetZoom(this: m_pCamera, fScale: fOldZoom);
    CCamera::GetViewPoint(this: this->m_pCamera, ViewPoint: &vecWorld);
    axHorz = this->axHorz;
    v5 = ViewPoint.z == *(&vecWorld.x + axHorz);
    v12 = &vecWorld.x + axHorz;
    if ( !v5 || *(float *)&ptClient.x != *(&vecWorld.x + this->axVert) )
    {
      axThird = this->axThird;
      *v12 = ViewPoint.z;
      *((_DWORD *)&vecWorld.x + this->axVert) = ptClient.x;
      if ( axThird == 1 )
        vecWorld.y = g_MIN_MAP_COORD;
      else
        *(&vecWorld.x + axThird) = g_MAX_MAP_COORD;
      CCamera::SetViewPoint(this: this->m_pCamera, ViewPoint: &vecWorld);
      CMapView2DBase::UpdateClientView(this);
    }
    CMapView2DBase::UpdateClientView(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100804E0
// Name: protected: void CMapView2DBase::OnMouseMove(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2DBase::OnMouseMove(CMapView2DBase *this, unsigned int nFlags, CPoint point)
{
  CMapView *v4; // edi
  CMapDoc *v5; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  HWND Focus; // eax
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  int v11; // ecx
  int v12; // eax
  int ActiveTool; // edi
  bool (__thiscall *IsLogical)(CMapView2DBase *); // eax
  char v15; // al
  SHORT AsyncKeyState; // ax
  CVGuiWnd *v17; // ecx
  float var8[3]; // [esp+14h] [ebp-8h] BYREF

  v4 = &this->CMapView;
  v5 = this->GetMapDoc(this: &this->CMapView);
  if ( v5 != nullptr && this->m_pToolManager != nullptr )
  {
    if ( !this->m_bActive )
      CMapDoc::SetActiveView(this: v5, pViewActivate: v4);
    ModuleState = AfxGetModuleState();
    if ( CHammer::IsActiveApp(this: (CHammer *)ModuleState->m_pCurrentWinApp) )
    {
      Focus = GetFocus();
      if ( CWnd::FromHandle(hWnd: Focus) != this )
        CWnd::SetFocus(this);
    }
    if ( this->m_bMouseDrag )
    {
      if ( point != *(_QWORD *)&this->m_ptLDownClient )
      {
        v8 = 1.0 / this->m_fZoom;
        v9 = (float)(point.x - this->m_ptLDownClient.x) * v8;
        v10 = (float)(point.y - this->m_ptLDownClient.y) * v8;
        if ( this->bInvertHorz )
          v10 = -v10;
        if ( this->bInvertVert )
          v9 = -v9;
        v11 = (int)(float)(s_fDragRestY + v10);
        v12 = (int)(float)(s_fDragRestX + v9);
        if ( v11 != 0 || v12 != 0 )
        {
          s_fDragRestX = (float)(s_fDragRestX + v9) - (float)v12;
          s_fDragRestY = (float)(s_fDragRestY + v10) - (float)v11;
          CMapView2DBase::SetViewOrigin(this, fHorz: (float)v12, fVert: (float)v11, bRelative: true);
          CVGuiWnd::SetCursor(this: &this->CVGuiWnd, filename: "Resource/ifm_grab.cur");
          this->m_ptLDownClient.x = point.x;
          this->m_ptLDownClient.y = point.y;
        }
      }
    }
    else
    {
      ActiveTool = CToolManager::GetActiveTool(this: (CSelection *)this->m_pToolManager);
      if ( ActiveTool == 0
        || ((IsLogical = this->IsLogical, var8[0] = (float)point.x, var8[1] = (float)point.y, !IsLogical(this))
          ? (v15 = (*(int (__thiscall **)(int, CMapView2DBase *, unsigned int, float *))(*(_DWORD *)ActiveTool + 124))(
                     a1: ActiveTool,
                     a2: this,
                     a3: nFlags,
                     a4: var8))
          : (v15 = (*(int (__thiscall **)(int, CMapView2DBase *, unsigned int, float *))(*(_DWORD *)ActiveTool + 168))(
                     a1: ActiveTool,
                     a2: this,
                     a3: nFlags,
                     a4: var8)),
            v15 == 0) )
      {
        AsyncKeyState = GetAsyncKeyState(vKey: 32);
        v17 = &this->CVGuiWnd;
        if ( AsyncKeyState >= 0 )
          CVGuiWnd::SetCursor(this: v17, cursor: 2u);
        else
          CVGuiWnd::SetCursor(this: v17, filename: "Resource/ifm_move.cur");
        CWnd::Default(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080700
// Name: public: void CMapView2DBase::EnsureVisible(class Vector __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2DBase::EnsureVisible(CMapView2DBase *this, Vector *vecPos, float flMargin)
{
  float v4; // xmm2_4
  float m_ClientWidth; // xmm0_4
  float v6; // xmm0_4
  float m_ClientHeight; // xmm0_4
  int axThird; // eax
  Vector ViewPoint; // [esp+4h] [ebp-14h] BYREF
  Vector2D pt; // [esp+10h] [ebp-8h] BYREF

  this->WorldToClient(this: &this->CMapView, a2: &pt, a3: vecPos);
  if ( pt.x >= 0.0 )
  {
    m_ClientWidth = (float)this->m_ClientWidth;
    if ( pt.x <= m_ClientWidth )
      v4 = 0.0;
    else
      v4 = (float)(m_ClientWidth - pt.x) - flMargin;
  }
  else
  {
    v4 = flMargin - pt.x;
  }
  pt.x = v4;
  if ( pt.y >= 0.0 )
  {
    m_ClientHeight = (float)this->m_ClientHeight;
    if ( pt.y <= m_ClientHeight )
      v6 = 0.0;
    else
      v6 = (float)(m_ClientHeight - pt.y) - flMargin;
  }
  else
  {
    v6 = flMargin - pt.y;
  }
  pt.y = v6;
  if ( v4 != 0.0 || v6 != 0.0 )
  {
    CCamera::GetViewPoint(this: this->m_pCamera, &ViewPoint);
    if ( v4 != 0.0 || v6 != 0.0 )
    {
      *(&ViewPoint.x + this->axHorz) = v4 + *(&ViewPoint.x + this->axHorz);
      *(&ViewPoint.x + this->axVert) = v6 + *(&ViewPoint.x + this->axVert);
      axThird = this->axThird;
      if ( axThird == 1 )
        ViewPoint.y = g_MIN_MAP_COORD;
      else
        *(&ViewPoint.x + axThird) = g_MAX_MAP_COORD;
      CCamera::SetViewPoint(this: this->m_pCamera, &ViewPoint);
      CMapView2DBase::UpdateClientView(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080850
// Name: protected: void CMapView2DBase::OnLButtonUp(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapView2DBase::OnLButtonUp(
        CMapView2DBase *this@<ecx>,
        int a2@<edi>,
        unsigned int nFlags,
        CPoint point)
{
  CMapDoc *v5; // ebx
  int ActiveTool; // edi
  char v7; // al
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  v5 = this->GetMapDoc(this: &this->CMapView);
  if ( v5 != nullptr && this->m_pToolManager != nullptr )
  {
    ReleaseCapture();
    if ( this->m_bMouseDrag )
    {
      this->m_bMouseDrag = false;
      CMapView2DBase::OnMouseMove(this, nFlags, point);
    }
    else
    {
      ActiveTool = CToolManager::GetActiveTool(this: (CSelection *)this->m_pToolManager);
      if ( ActiveTool == 0
        || (((unsigned __int8 (__thiscall *)(CMapView2DBase *, int))this->IsLogical)(a1: this, a2) == 0
          ? (v7 = (*(int (__thiscall **)(int, CMapView2DBase *, unsigned int))(*(_DWORD *)ActiveTool + 108))(
                    a1: ActiveTool,
                    a2: this,
                    a3: nFlags))
          : (v7 = (*(int (__thiscall **)(int, CMapView2DBase *, unsigned int))(*(_DWORD *)ActiveTool + 152))(
                    a1: ActiveTool,
                    a2: this,
                    a3: nFlags)),
            v7 == 0) )
      {
        CMapDoc::UpdateStatusbar(this: v5, a2: COERCE_FLOAT(&savedregs), a3: ActiveTool, a4: (int)this);
        CWnd::Default(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080930
// Name: public: void CMapView2DBase::CenterView(class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2DBase::CenterView(CMapView2DBase *this, Vector *pCenter)
{
  CMapDoc *v3; // eax
  int axVert; // edx
  float v5; // xmm0_4
  int v6; // eax
  int axHorz; // ecx
  bool v8; // zf
  float *v9; // ecx
  int v10; // eax
  int axThird; // eax
  Vector vecMins; // [esp+4h] [ebp-1Ch] BYREF
  Vector vecMaxs; // [esp+10h] [ebp-10h] BYREF
  float fPointX; // [esp+1Ch] [ebp-4h]

  v3 = this->GetMapDoc(this: &this->CMapView);
  if ( pCenter != nullptr )
  {
    axVert = this->axVert;
    fPointX = *(&pCenter->x + this->axHorz);
    v5 = *(&pCenter->x + axVert);
  }
  else
  {
    CMapClass::GetRender2DBox(this: v3->m_pWorld, mins: &vecMins, maxs: &vecMaxs);
    v6 = 2 * this->axVert;
    fPointX = (float)(*(&vecMaxs.x + this->axHorz) + *(&vecMins.x + this->axHorz)) * 0.5;
    v5 = (float)(*(float *)((char *)&vecMaxs.x + 2 * v6) + *(float *)((char *)&vecMins.x + 2 * v6)) * 0.5;
  }
  CCamera::GetViewPoint(this: this->m_pCamera, ViewPoint: &vecMaxs);
  axHorz = this->axHorz;
  v8 = fPointX == *(&vecMaxs.x + axHorz);
  v9 = &vecMaxs.x + axHorz;
  if ( !v8 || v5 != *(&vecMaxs.x + this->axVert) )
  {
    v10 = this->axVert;
    *v9 = fPointX;
    *(&vecMaxs.x + v10) = v5;
    axThird = this->axThird;
    if ( axThird == 1 )
      vecMaxs.y = g_MIN_MAP_COORD;
    else
      *(&vecMaxs.x + axThird) = g_MAX_MAP_COORD;
    CCamera::SetViewPoint(this: this->m_pCamera, ViewPoint: &vecMaxs);
    CMapView2DBase::UpdateClientView(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080A60
// Name: protected: void CMapView2DBase::OnHScroll(unsigned int,unsigned int,class CScrollBar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2DBase::OnHScroll(CMapView2DBase *this, unsigned int nSBCode, int nPos, CScrollBar *pScrollBar)
{
  int v4; // eax
  float v6; // xmm0_4
  float v7; // xmm0_4
  int axThird; // eax
  Vector fVert; // [esp+10h] [ebp-Ch] BYREF
  float v10; // [esp+28h] [ebp+Ch]

  v4 = nPos;
  v6 = (float)this->m_ClientWidth / this->m_fZoom;
  switch ( nSBCode )
  {
    case 0u:
      v7 = v6 * -0.25;
      goto LABEL_3;
    case 1u:
      v7 = v6 * 0.25;
      goto LABEL_3;
    case 2u:
      v7 = v6 * -0.5;
      goto LABEL_3;
    case 3u:
      v7 = v6 * 0.5;
LABEL_3:
      v4 = (int)v7;
      goto LABEL_4;
    case 4u:
    case 5u:
      if ( this->bInvertHorz )
        v4 = -nPos;
      CMapView2DBase::SetViewOrigin(
        this,
        fHorz: (float)v4,
        fVert: *(&this->m_vViewOrigin.x + this->axVert),
        bRelative: false);
      return;
    default:
LABEL_4:
      if ( this->bInvertHorz )
        v4 = -v4;
      v10 = (float)v4;
      CCamera::GetViewPoint(this: this->m_pCamera, ViewPoint: &fVert);
      if ( v10 != 0.0 )
      {
        *(&fVert.x + this->axHorz) = *(&fVert.x + this->axHorz) + v10;
        axThird = this->axThird;
        if ( axThird == 1 )
          fVert.y = g_MIN_MAP_COORD;
        else
          *(&fVert.x + axThird) = g_MAX_MAP_COORD;
        CCamera::SetViewPoint(this: this->m_pCamera, ViewPoint: &fVert);
        CMapView2DBase::UpdateClientView(this);
      }
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080BB0
// Name: protected: void CMapView2DBase::OnVScroll(unsigned int,unsigned int,class CScrollBar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2DBase::OnVScroll(CMapView2DBase *this, unsigned int nSBCode, int nPos, CScrollBar *pScrollBar)
{
  int v4; // eax
  float v6; // xmm0_4
  float v7; // xmm0_4
  int axThird; // eax
  Vector fVert; // [esp+10h] [ebp-Ch] BYREF
  float v10; // [esp+28h] [ebp+Ch]

  v4 = nPos;
  v6 = (float)this->m_ClientHeight / this->m_fZoom;
  switch ( nSBCode )
  {
    case 0u:
      v7 = v6 * -0.25;
      goto LABEL_3;
    case 1u:
      v7 = v6 * 0.25;
      goto LABEL_3;
    case 2u:
      v7 = v6 * -0.5;
      goto LABEL_3;
    case 3u:
      v7 = v6 * 0.5;
LABEL_3:
      v4 = (int)v7;
      goto LABEL_4;
    case 4u:
    case 5u:
      if ( this->bInvertVert )
        v4 = -nPos;
      CMapView2DBase::SetViewOrigin(
        this,
        fHorz: *(&this->m_vViewOrigin.x + this->axHorz),
        fVert: (float)v4,
        bRelative: false);
      return;
    default:
LABEL_4:
      if ( this->bInvertVert )
        v4 = -v4;
      v10 = (float)v4;
      CCamera::GetViewPoint(this: this->m_pCamera, ViewPoint: &fVert);
      if ( v10 != 0.0 )
      {
        *(&fVert.x + this->axVert) = *(&fVert.x + this->axVert) + v10;
        axThird = this->axThird;
        if ( axThird == 1 )
          fVert.y = g_MIN_MAP_COORD;
        else
          *(&fVert.x + axThird) = g_MAX_MAP_COORD;
        CCamera::SetViewPoint(this: this->m_pCamera, ViewPoint: &fVert);
        CMapView2DBase::UpdateClientView(this);
      }
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080D00
// Name: protected: void CMapView2DBase::OnTimer(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2DBase::OnTimer(CMapView2DBase *this, unsigned int nIDEvent)
{
  int m_xScroll; // eax
  CPoint fVert; // [esp+4h] [ebp-8h] BYREF

  if ( nIDEvent == 1 )
  {
    KillTimer(hWnd: this->m_hWnd, uIDEvent: 1u);
    m_xScroll = this->m_xScroll;
    if ( m_xScroll != 0 || this->m_yScroll != 0 )
    {
      CMapView2DBase::SetViewOrigin(this, fHorz: (float)m_xScroll, fVert: (float)this->m_yScroll, bRelative: true);
      fVert = 0;
      GetCursorPos(lpPoint: &fVert);
      ScreenToClient(hWnd: this->m_hWnd, lpPoint: &fVert);
      CMapView2DBase::OnMouseMove(this, nFlags: 0, point: fVert);
    }
  }
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x10080DA0
// Name: public: void CMapView2DBase::ZoomIn(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2DBase::ZoomIn(CMapView2DBase *this, int bAllViews)
{
  CMapView_vtbl *v3; // edx
  CMapDoc *(__thiscall *GetMapDoc)(CMapView *); // eax
  CMapDoc *v5; // eax
  VIEW2DINFO vi; // [esp+4h] [ebp-18h] BYREF
  float v7; // [esp+18h] [ebp-4h]

  v7 = this->m_fZoom * 1.2;
  CMapView2DBase::SetZoom(this, fNewZoom: v7);
  if ( bAllViews != 0 )
  {
    v3 = this->CMapView::__vftable;
    vi.wFlags = 1;
    GetMapDoc = v3->GetMapDoc;
    vi.fZoom = v7;
    v5 = GetMapDoc(this: &this->CMapView);
    if ( v5 != nullptr )
      CMapDoc::SetView2dInfo(this: v5, &vi);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080E10
// Name: public: void CMapView2DBase::ZoomOut(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2DBase::ZoomOut(CMapView2DBase *this, int bAllViews)
{
  CMapView_vtbl *v3; // edx
  float m_fZoom; // xmm0_4
  CMapDoc *(__thiscall *GetMapDoc)(CMapView *); // eax
  CMapDoc *v6; // eax
  VIEW2DINFO vi; // [esp+4h] [ebp-14h] BYREF

  CMapView2DBase::SetZoom(this, fNewZoom: this->m_fZoom * 0.8333333333333334);
  if ( bAllViews != 0 )
  {
    v3 = this->CMapView::__vftable;
    m_fZoom = this->m_fZoom;
    vi.wFlags = 1;
    GetMapDoc = v3->GetMapDoc;
    vi.fZoom = m_fZoom;
    v6 = GetMapDoc(this: &this->CMapView);
    if ( v6 != nullptr )
      CMapDoc::SetView2dInfo(this: v6, &vi);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080E80
// Name: protected: virtual void CMapView2DBase::OnInitialUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapView2DBase::OnInitialUpdate(CMapView2DBase *this)
{
  vgui::EditablePanel *v2; // eax
  vgui::EditablePanel *v3; // edi
  CVGuiWnd *v4; // [esp+8h] [ebp-10h]

  v4 = &this->CVGuiWnd;
  if ( vgui::Tooltip::GetText(this: (vgui::Tooltip *)&this->CVGuiWnd) == nullptr )
  {
    this->m_pToolManager = this->GetMapDoc(this: &this->CMapView)->m_pToolManager;
    CMapView2DBase::CenterView(this, pCenter: nullptr);
    CMapView2DBase::SetColorMode(this, bWhiteOnBlack: Options.view2d.bWhiteOnBlack != 0);
    ShowScrollBar(hWnd: this->m_hWnd, wBar: 0, bShow: Options.view2d.bScrollbars);
    ShowScrollBar(hWnd: this->m_hWnd, wBar: 1, bShow: Options.view2d.bScrollbars);
    CView::OnInitialUpdate(this);
    v2 = (vgui::EditablePanel *)operator new(nSize: 0x180u);
    v3 = v2;
    if ( v2 != nullptr )
    {
      vgui::EditablePanel::EditablePanel(this: v2, parent: nullptr, panelName: "MapView2DPanel");
      v3->__vftable = (vgui::EditablePanel_vtbl *)&CMapView2DBasePanel::`vftable';
      v3[1].__vftable = (vgui::EditablePanel_vtbl *)this;
    }
    else
    {
      v3 = nullptr;
    }
    CVGuiWnd::SetParentWindow(this: v4, pParent: this);
    CVGuiWnd::SetMainPanel(this: v4, pPanel: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10080F90
// Name: protected: void CMapView2DBase::OnKeyDown(unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMapView2DBase::OnKeyDown(
        CMapView2DBase *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        unsigned int nChar,
        unsigned int nRepCnt,
        char nFlags)
{
  CToolManager *m_pToolManager; // ecx
  CVGuiWnd *v8; // ecx
  int ActiveTool; // edi
  char v10; // al
  bool v11; // cl
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int axThird; // eax
  int v18; // eax
  int v19; // eax
  char v20; // cl
  Vector v22; // [esp+10h] [ebp-Ch] BYREF
  float ViewPoint; // [esp+2Ch] [ebp+10h]
  float ViewPointa; // [esp+2Ch] [ebp+10h]
  float ViewPointb; // [esp+2Ch] [ebp+10h]
  float ViewPointc; // [esp+2Ch] [ebp+10h]

  if ( this->GetMapDoc(this: &this->CMapView) != nullptr )
  {
    m_pToolManager = this->m_pToolManager;
    if ( m_pToolManager != nullptr )
    {
      if ( nChar == 32 )
      {
        v8 = &this->CVGuiWnd;
        if ( this->m_bMouseDrag )
          CVGuiWnd::SetCursor(this: v8, filename: "Resource/ifm_grab.cur");
        else
          CVGuiWnd::SetCursor(this: v8, filename: "Resource/ifm_move.cur");
      }
      else
      {
        ActiveTool = CToolManager::GetActiveTool(this: (CSelection *)m_pToolManager);
        if ( ActiveTool == 0
          || (((unsigned __int8 (__thiscall *)(CMapView2DBase *, int, int))this->IsLogical)(a1: this, a2: a3, a3: a2) == 0
            ? (v10 = (*(int (__thiscall **)(int, CMapView2DBase *, unsigned int))(*(_DWORD *)ActiveTool + 132))(
                       a1: ActiveTool,
                       a2: this,
                       a3: nChar))
            : (v10 = (*(int (__thiscall **)(int, CMapView2DBase *, unsigned int))(*(_DWORD *)ActiveTool + 176))(
                       a1: ActiveTool,
                       a2: this,
                       a3: nChar)),
              v10 == 0) )
        {
          v11 = (nFlags & 8) != 0;
          switch ( nChar )
          {
            case '%':
              v16 = (int)(float)((float)((float)this->m_ClientWidth / this->m_fZoom) * -0.25);
              if ( this->bInvertHorz )
                v16 = -v16;
              ViewPointb = (float)v16;
              CCamera::GetViewPoint(this: this->m_pCamera, ViewPoint: &v22);
              if ( ViewPointb == 0.0 )
                goto LABEL_42;
              *(&v22.x + this->axHorz) = ViewPointb + *(&v22.x + this->axHorz);
              axThird = this->axThird;
              if ( axThird == 1 )
                v22.y = g_MIN_MAP_COORD;
              else
                *(&v22.x + axThird) = g_MAX_MAP_COORD;
              goto LABEL_21;
            case '&':
              v12 = (int)(float)((float)((float)this->m_ClientHeight / this->m_fZoom) * -0.25);
              if ( this->bInvertVert )
                v12 = -v12;
              ViewPoint = (float)v12;
              CCamera::GetViewPoint(this: this->m_pCamera, ViewPoint: &v22);
              if ( ViewPoint == 0.0 )
                goto LABEL_42;
              *(&v22.x + this->axVert) = ViewPoint + *(&v22.x + this->axVert);
              v13 = this->axThird;
              if ( v13 == 1 )
                goto LABEL_19;
              *(&v22.x + v13) = g_MAX_MAP_COORD;
              goto LABEL_21;
            case '\'':
              v18 = (int)(float)((float)((float)this->m_ClientWidth / this->m_fZoom) * 0.25);
              if ( this->bInvertHorz )
                v18 = -v18;
              ViewPointc = (float)v18;
              CCamera::GetViewPoint(this: this->m_pCamera, ViewPoint: &v22);
              if ( ViewPointc == 0.0 )
                goto LABEL_42;
              *(&v22.x + this->axHorz) = *(&v22.x + this->axHorz) + ViewPointc;
              v19 = this->axThird;
              if ( v19 == 1 )
LABEL_19:
                v22.y = g_MIN_MAP_COORD;
              else
                *(&v22.x + v19) = g_MAX_MAP_COORD;
              goto LABEL_21;
            case '(':
              v14 = (int)(float)((float)((float)this->m_ClientHeight / this->m_fZoom) * 0.25);
              if ( this->bInvertVert )
                v14 = -v14;
              ViewPointa = (float)v14;
              CCamera::GetViewPoint(this: this->m_pCamera, ViewPoint: &v22);
              if ( ViewPointa == 0.0 )
                goto LABEL_42;
              *(&v22.x + this->axVert) = ViewPointa + *(&v22.x + this->axVert);
              v15 = this->axThird;
              if ( v15 == 1 )
                v22.y = g_MIN_MAP_COORD;
              else
                *(&v22.x + v15) = g_MAX_MAP_COORD;
LABEL_21:
              CCamera::SetViewPoint(this: this->m_pCamera, ViewPoint: &v22);
              CMapView2DBase::UpdateClientView(this);
              CWnd::Default(this);
              break;
            case '+':
            case 'k':
              CMapView2DBase::ZoomIn(this, bAllViews: v11);
              CWnd::Default(this);
              return;
            case '-':
            case 'm':
              CMapView2DBase::ZoomOut(this, bAllViews: v11);
              CWnd::Default(this);
              return;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
              v20 = nChar - 49;
              if ( nChar == 48 )
                v20 = 9;
              CMapView2DBase::SetZoom(this, fNewZoom: (float)(1 << v20) * this->m_flMinZoom);
              goto LABEL_42;
            default:
LABEL_42:
              CWnd::Default(this);
              break;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100813F0
// Name: protected: virtual int CMapView2DBase::OnMouseWheel(unsigned int,short,class CPoint)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CMapView2DBase::OnMouseWheel@<eax>(
        CMapView2DBase *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        unsigned int nFlags,
        __int16 zDelta,
        CPoint point)
{
  CToolManager *m_pToolManager; // ecx
  int ActiveTool; // esi
  unsigned int v10; // [esp-Ch] [ebp-18h]

  m_pToolManager = this->m_pToolManager;
  if ( m_pToolManager == nullptr )
    return 1;
  ActiveTool = CToolManager::GetActiveTool(this: (CSelection *)m_pToolManager);
  if ( ActiveTool != 0 )
  {
    if ( ((unsigned __int8 (__thiscall *)(CMapView2DBase *, int, int))this->IsLogical)(a1: this, a2, a3) != 0 )
    {
      if ( (*(unsigned __int8 (__thiscall **)(int, CMapView2DBase *, unsigned int))(*(_DWORD *)ActiveTool + 172))(
             a1: ActiveTool,
             a2: this,
             a3: nFlags) != 0 )
        return 1;
    }
    else if ( (*(unsigned __int8 (__thiscall **)(int, CMapView2DBase *, unsigned int))(*(_DWORD *)ActiveTool + 128))(
                a1: ActiveTool,
                a2: this,
                a3: nFlags) != 0 )
    {
      return 1;
    }
  }
  v10 = nFlags & 8;
  if ( zDelta < 0 )
  {
    CMapView2DBase::ZoomOut(this, bAllViews: v10);
    return 1;
  }
  CMapView2DBase::ZoomIn(this, bAllViews: v10);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100814C0
// Name: protected: static struct AFX_MSGMAP const __near * CMapView2DBase::GetThisMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__stdcall CMapView2DBase::GetThisMessageMap()
{
  if ( (_S1_4 & 1) == 0 )
  {
    _S1_4 |= 1u;
    messageEntries_43[6].nSig = 42;
    messageEntries_43[7].nSig = 42;
    messageEntries_43[0].pfn = (void (__thiscall *)(CCmdTarget *))CMapView2DBase::OnKeyDown;
    messageEntries_43[1].nMessage = 513;
    messageEntries_43[1].nCode = 0;
    messageEntries_43[1].nID = 0;
    messageEntries_43[1].nLastID = 0;
    messageEntries_43[1].nSig = 53;
    messageEntries_43[1].pfn = (void (__thiscall *)(CCmdTarget *))CMapView2DBase::OnLButtonDown;
    messageEntries_43[2].nMessage = 512;
    messageEntries_43[2].nCode = 0;
    messageEntries_43[2].nID = 0;
    messageEntries_43[2].nLastID = 0;
    messageEntries_43[2].nSig = 53;
    messageEntries_43[2].pfn = (void (__thiscall *)(CCmdTarget *))CMapView2DBase::OnMouseMove;
    messageEntries_43[3].nMessage = 522;
    messageEntries_43[3].nCode = 0;
    messageEntries_43[3].nID = 0;
    messageEntries_43[3].nLastID = 0;
    messageEntries_43[3].nSig = 55;
    messageEntries_43[3].pfn = (void (__thiscall *)(CCmdTarget *)) __thiscall CMapView2DBase::`vcall'{444,{flat}};
    messageEntries_43[4].nMessage = 514;
    messageEntries_43[4].nCode = 0;
    messageEntries_43[4].nID = 0;
    messageEntries_43[4].nLastID = 0;
    messageEntries_43[4].nSig = 53;
    messageEntries_43[4].pfn = (void (__thiscall *)(CCmdTarget *))CMapView2DBase::OnLButtonUp;
    messageEntries_43[5].nMessage = 515;
    messageEntries_43[5].nCode = 0;
    messageEntries_43[5].nID = 0;
    messageEntries_43[5].nLastID = 0;
    messageEntries_43[5].nSig = 53;
    messageEntries_43[5].pfn = (void (__thiscall *)(CCmdTarget *))CMapView2DBase::OnLButtonDblClk;
    messageEntries_43[6].nMessage = 276;
    messageEntries_43[6].nCode = 0;
    messageEntries_43[6].nID = 0;
    messageEntries_43[6].nLastID = 0;
    messageEntries_43[6].pfn = (void (__thiscall *)(CCmdTarget *))CMapView2DBase::OnHScroll;
    messageEntries_43[7].nMessage = 277;
    messageEntries_43[7].nCode = 0;
    messageEntries_43[7].nID = 0;
    messageEntries_43[7].nLastID = 0;
    messageEntries_43[7].pfn = (void (__thiscall *)(CCmdTarget *))CMapView2DBase::OnVScroll;
    messageEntries_43[8].nMessage = 516;
    messageEntries_43[8].nCode = 0;
    messageEntries_43[8].nID = 0;
    messageEntries_43[8].nLastID = 0;
    messageEntries_43[8].nSig = 53;
    messageEntries_43[8].pfn = (void (__thiscall *)(CCmdTarget *))CMapView2DBase::OnRButtonDown;
    messageEntries_43[9].nMessage = 275;
    messageEntries_43[9].nCode = 0;
    messageEntries_43[9].nID = 0;
    messageEntries_43[9].nLastID = 0;
    messageEntries_43[9].nSig = 20;
    messageEntries_43[9].pfn = (void (__thiscall *)(CCmdTarget *))CMapView2DBase::OnTimer;
    messageEntries_43[10].nMessage = 5;
    messageEntries_43[10].nCode = 0;
    messageEntries_43[10].nID = 0;
    messageEntries_43[10].nLastID = 0;
    messageEntries_43[10].nSig = 25;
    messageEntries_43[10].pfn = (void (__thiscall *)(CCmdTarget *))CMapView2DBase::OnSize;
    messageEntries_43[11].nMessage = 273;
    messageEntries_43[11].nCode = 0;
    messageEntries_43[11].nID = 32819;
    messageEntries_43[11].nLastID = 32819;
    messageEntries_43[11].nSig = 57;
    messageEntries_43[11].pfn = (void (__thiscall *)(CCmdTarget *))CMapView2DBase::OnEditProperties;
    messageEntries_43[12].nMessage = 257;
    messageEntries_43[12].nCode = 0;
    messageEntries_43[12].nID = 0;
    messageEntries_43[12].nLastID = 0;
    messageEntries_43[12].nSig = 24;
    messageEntries_43[12].pfn = (void (__thiscall *)(CCmdTarget *))CMapView2DBase::OnKeyUp;
    messageEntries_43[13].nSig = 24;
    messageEntries_43[14].nSig = 53;
    messageEntries_43[15].nID = 32899;
    messageEntries_43[15].nLastID = 32899;
    messageEntries_43[13].nMessage = 258;
    messageEntries_43[13].nCode = 0;
    messageEntries_43[13].nID = 0;
    messageEntries_43[13].nLastID = 0;
    messageEntries_43[13].pfn = (void (__thiscall *)(CCmdTarget *))CMapView2DBase::OnChar;
    messageEntries_43[14].nMessage = 517;
    messageEntries_43[14].nCode = 0;
    messageEntries_43[14].nID = 0;
    messageEntries_43[14].nLastID = 0;
    messageEntries_43[14].pfn = (void (__thiscall *)(CCmdTarget *))CMapView2DBase::OnRButtonUp;
    messageEntries_43[15].nMessage = 273;
    messageEntries_43[15].nCode = -1;
    messageEntries_43[15].nSig = 65;
    messageEntries_43[15].pfn = (void (__thiscall *)(CCmdTarget *))CMapView2DBase::OnUpdateEditFunction;
    messageEntries_43[16].nMessage = 20;
    messageEntries_43[16].nCode = 0;
    messageEntries_43[16].nID = 0;
    messageEntries_43[16].nLastID = 0;
    messageEntries_43[16].nSig = 1;
    messageEntries_43[16].pfn = (void (__thiscall *)(CCmdTarget *))CParticleBrowser::OnEraseBkgnd;
    messageEntries_43[17].nMessage = 273;
    messageEntries_43[17].nCode = -1;
    messageEntries_43[17].nID = 32819;
    messageEntries_43[17].nLastID = 32819;
    messageEntries_43[17].nSig = 65;
    messageEntries_43[17].pfn = (void (__thiscall *)(CCmdTarget *))CMapView2DBase::OnUpdateEditFunction;
    messageEntries_43[18].nMessage = 0;
    messageEntries_43[18].nCode = 0;
    messageEntries_43[18].nID = 0;
    messageEntries_43[18].nLastID = 0;
    messageEntries_43[18].nSig = 0;
    messageEntries_43[18].pfn = nullptr;
  }
  return &messageMap_2;
}

//------------------------------------------------------------------------------
// Address: 0x10081830
// Name: protected: virtual struct AFX_MSGMAP const __near * CMapView2DBase::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
const AFX_MSGMAP *__thiscall CMapView2DBase::GetMessageMap(CMapView2DBase *this)
{
  return CMapView2DBase::GetThisMessageMap();
}

//------------------------------------------------------------------------------
// Address: 0x10081840
// Name: public: int CMapView2DBase::ObjectsAt(class CMapWorld __near *,class Vector2D const __near &,struct HitInfo_s __near *,int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapView2DBase::ObjectsAt(
        CMapView2DBase *this,
        CMapWorld *pWorld,
        const Vector2D *vPoint,
        HitInfo_s *pHitData,
        int nMaxObjects,
        unsigned int nFlags)
{
  int v6; // esi
  int v7; // edi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v10; // ecx
  void *v11; // esi
  CMapWorld *v12; // eax
  char v13; // al
  CUtlReference<CMapClass> *m_pHead; // [esp+Ch] [ebp-1Ch] BYREF
  CUtlReference<CMapClass> *v16; // [esp+10h] [ebp-18h]
  void *inptr; // [esp+14h] [ebp-14h]
  int pos; // [esp+18h] [ebp-10h]
  int v19; // [esp+24h] [ebp-4h]

  v6 = 0;
  v7 = 0;
  pos = 0;
  if ( pWorld->m_Children.m_Size > 0 )
  {
    while ( 1 )
    {
      m_pObject = pWorld->m_Children.m_Memory.m_pMemory[v6 >> ((unsigned __int64)*((int *)&pWorld->m_Children.m_Memory
                                                                                 + 2) >> 27)][v6
                                                                                            & ((32
                                                                                              * *((_DWORD *)&pWorld->m_Children.m_Memory
                                                                                                + 2)) >> 5)].m_pObject;
      if ( m_pObject != nullptr )
      {
        inptr = pWorld->m_Children.m_Memory.m_pMemory[v6 >> ((unsigned __int64)*((int *)&pWorld->m_Children.m_Memory + 2) >> 27)][v6 & ((32 * *((_DWORD *)&pWorld->m_Children.m_Memory + 2)) >> 5)].m_pObject;
        m_pHead = m_pObject->m_References.m_pHead;
        v10 = m_pObject->m_References.m_pHead;
        if ( v10 != nullptr )
          v10->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
        v16 = nullptr;
        m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
      }
      v11 = inptr;
      v19 = -1;
      if ( inptr != nullptr )
      {
        if ( v16 != nullptr )
        {
          v16->m_pNext = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = v16;
        }
        else if ( *((CUtlReference<CMapClass> ***)inptr + 8) == &m_pHead )
        {
          *((_DWORD *)inptr + 8) = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = nullptr;
        }
        v16 = nullptr;
        m_pHead = nullptr;
        inptr = nullptr;
      }
      v12 = (CMapWorld *)__RTDynamicCast(
                           inptr: v11,
                           VfDelta: 0,
                           SrcType: &CMapClass `RTTI Type Descriptor',
                           TargetType: &CMapWorld `RTTI Type Descriptor',
                           isReference: 0);
      if ( v12 != nullptr )
      {
        v7 += CMapView2DBase::ObjectsAt(
                this,
                pWorld: v12,
                vPoint,
                pHitData: &pHitData[v7],
                nMaxObjects: nMaxObjects - v7,
                nFlags: 0);
      }
      else
      {
        v13 = this->IsLogical(this)
            ? (*(int (__thiscall **)(void *, CMapView2DBase *, const Vector2D *, HitInfo_s *))(*(_DWORD *)v11 + 224))(
                a1: v11,
                a2: this,
                a3: vPoint,
                a4: &pHitData[v7])
            : (*(unsigned int (__thiscall **)(void *, CMapView2DBase *, const Vector2D *, HitInfo_s *))(*(_DWORD *)v11 + 220))(
                a1: v11,
                a2: this,
                a3: vPoint,
                a4: &pHitData[v7]);
        if ( v13 != 0 )
          ++v7;
      }
      if ( ++pos >= pWorld->m_Children.m_Size )
        break;
      v6 = pos;
    }
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x100819E0
// Name: protected: virtual int CMapView2DBase::PreCreateWindow(struct tagCREATESTRUCTA __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapView2DBase::PreCreateWindow(CMapView2DBase *this, tagCREATESTRUCTA *cs)
{
  CAfxStringMgr *StringManager; // eax
  HCURSOR CursorA; // eax
  const char *v5; // eax
  int v6; // ecx

  if ( (_S2_0 & 1) == 0 )
  {
    _S2_0 |= 1u;
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    className.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
    atexit(func: CMapView2DBase::PreCreateWindow_::_2_::_dynamic_atexit_destructor_for__className__);
  }
  if ( *((_DWORD *)className.m_pszData - 3) == 0 )
  {
    AfxGetModuleState();
    CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
    v5 = AfxRegisterWndClass(nClassStyle: 0x1008u, hCursor: CursorA, hbrBackground: nullptr, hIcon: nullptr);
    if ( v5 != nullptr )
      v6 = strlen(v5);
    else
      v6 = 0;
    ATL::CSimpleStringT<char,0>::SetString(this: &className, pszSrc: v5, nLength: v6);
  }
  cs->lpszClass = className.m_pszData;
  return CView::PreCreateWindow(this, cs);
}

//------------------------------------------------------------------------------
// Address: 0x10081AD0
// Name: public: virtual int CMapView2DBase::ObjectsAt(class Vector2D const __near &,struct HitInfo_s __near *,int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapView2DBase::ObjectsAt(
        CMapView2DBase *this,
        const Vector2D *vPoint,
        HitInfo_s *pHitData,
        int nMaxObjects,
        unsigned int nFlags)
{
  CTypeLibCache *v6; // eax

  v6 = this->GetTypeLibCache(this);
  return CMapView2DBase::ObjectsAt(
           this: (CMapView2DBase *)((char *)this - 124),
           pWorld: (CMapWorld *)v6[10].m_ptinfo,
           vPoint,
           pHitData,
           nMaxObjects,
           nFlags);
}

//------------------------------------------------------------------------------
// Address: 0x102DD670
// Name: protected: virtual class vgui::FocusNavGroup __near & vgui::EditablePanel::GetFocusNavGroup(void)
// Source: json
//------------------------------------------------------------------------------
vgui::FocusNavGroup *__thiscall vgui::EditablePanel::GetFocusNavGroup(vgui::EditablePanel *this)
{
  return &this->m_NavGroup;
}

//------------------------------------------------------------------------------
// Address: 0x102DD8B0
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::HasHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::HasHotkey(vgui::EditablePanel *this, int key)
{
  int v3; // edi
  vgui::Panel *Child; // eax
  int v5; // esi

  if ( !this->IsVisible(this) || !this->IsEnabled(this) )
    return nullptr;
  v3 = 0;
  if ( vgui::Panel::GetChildCount(this) <= 0 )
    return nullptr;
  while ( 1 )
  {
    Child = vgui::Panel::GetChild(this, index: v3);
    v5 = (int)Child->HasHotkey(this: Child, a2: key);
    if ( v5 != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 136))(a1: v5) != 0
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 224))(a1: v5) != 0 )
    {
      break;
    }
    if ( ++v3 >= vgui::Panel::GetChildCount(this) )
      return nullptr;
  }
  return (vgui::Panel *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x102DDD50
// Name: public: virtual class vgui::Panel __near * vgui::EditablePanel::CreateControlByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::EditablePanel::CreateControlByName(vgui::EditablePanel *this, const char *controlName)
{
  return vgui::CBuildFactoryHelper::InstancePanel(className: controlName);
}

//------------------------------------------------------------------------------
// Address: 0x1033FFEB
// Name: public: int CRect::IsRectNull(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CRect::IsRectNull(CRect *this)
{
  BOOL result; // eax

  result = false;
  if ( this->left == 0 && this->right == 0 && this->top == 0 )
    return this->bottom == 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10398784
// Name: public: int CPoint::operator!=(struct tagPOINT)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CPoint::operator!=(CPoint *this, tagPOINT point)
{
  return *this != point;
}

//------------------------------------------------------------------------------
// Address: 0x105CA900
// Name: _CMapView2DBase::OnContextMenu_::_17_::_dynamic_atexit_destructor_for__menuDefault__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMapView2DBase::OnContextMenu_::_17_::_dynamic_atexit_destructor_for__menuDefault__()
{
  menuDefault.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  CMenu::DestroyMenu(this: &menuDefault);
}

//------------------------------------------------------------------------------
// Address: 0x105CA920
// Name: _CMapView2DBase::OnContextMenu_::_17_::_dynamic_atexit_destructor_for__menu__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMapView2DBase::OnContextMenu_::_17_::_dynamic_atexit_destructor_for__menu__()
{
  menu.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  CMenu::DestroyMenu(this: &menu);
}

//------------------------------------------------------------------------------
// Address: 0x105CA940
// Name: _CMapView2DBase::PreCreateWindow_::_2_::_dynamic_atexit_destructor_for__className__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMapView2DBase::PreCreateWindow_::_2_::_dynamic_atexit_destructor_for__className__()
{
  char *v0; // eax

  v0 = className.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)className.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v0 + 4))(a1: v0);
}

//------------------------------------------------------------------------------
// Address: 0x103987A3
// Name: public: CVSListBoxEditCtrl::CVSListBoxEditCtrl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVSListBoxEditCtrl *__thiscall CVSListBoxEditCtrl::CVSListBoxEditCtrl(CVSListBoxEditCtrl *this)
{
  CMFCEditBrowseCtrl::CMFCEditBrowseCtrl(this);
  this->m_bLocked = 0;
  this->m_pParentList = nullptr;
  this->__vftable = (CVSListBoxEditCtrl_vtbl *)&CVSListBoxEditCtrl::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103987C5
// Name: public: virtual CVSListBoxEditCtrl::~CVSListBoxEditCtrl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVSListBoxEditCtrl::~CVSListBoxEditCtrl(CVSListBoxEditCtrl *this)
{
  this->__vftable = (CVSListBoxEditCtrl_vtbl *)&CVSListBoxEditCtrl::`vftable';
  CMFCEditBrowseCtrl::~CMFCEditBrowseCtrl(this);
}

//------------------------------------------------------------------------------
// Address: 0x103987D0
// Name: protected: void CVSListBoxEditCtrl::OnNcCalcSize(int,struct tagNCCALCSIZE_PARAMS __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVSListBoxEditCtrl::OnNcCalcSize(
        CVSListBoxEditCtrl *this,
        int bCalcValidRects,
        tagNCCALCSIZE_PARAMS *lpncsp)
{
  if ( this->m_bLocked == 0 )
    CMFCEditBrowseCtrl::OnNcCalcSize(this, bCalcValidRects, lpncsp);
}

//------------------------------------------------------------------------------
// Address: 0x103987E8
// Name: protected: void CVSListBoxBase::OnSetFocus(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVSListBoxBase::OnSetFocus(CVSListBoxBase *this, CWnd *__formal)
{
  HWND__ *v2; // eax
  CWnd *v3; // eax

  v2 = this->GetListHwnd(this);
  v3 = CWnd::FromHandle(hWnd: v2);
  if ( v3 != nullptr )
    CWnd::SetFocus(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10398804
// Name: public: virtual void CVSListBoxBase::OnKey(unsigned short,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVSListBoxBase::OnKey(CVSListBoxBase *this, unsigned __int16 wKey, unsigned __int8 fFlags)
{
  int v4; // edi
  char v5; // al

  v4 = this->GetSelItem(this);
  v5 = MapVirtualKeyA(uCode: wKey, uMapType: 2u);
  if ( fFlags == 0 && v4 >= 0 && (v5 == 32 || wKey == 113) )
    this->EditItem(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1039884A
// Name: protected: unsigned int CVSListBoxBase::OnGetDlgCode(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CVSListBoxBase::OnGetDlgCode(CVSListBoxBase *this)
{
  return 4;
}

//------------------------------------------------------------------------------
// Address: 0x1039884E
// Name: protected: void CVSListBox::OnDblclkList(struct tagNMHDR __near *,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVSListBox::OnDblclkList(CVSListBox *this, tagNMHDR *__formal, int *pResult)
{
  int v4; // eax

  *pResult = 0;
  v4 = this->GetSelItem(this);
  if ( (this->m_uiStandardBtns & 1) != 0 && v4 == -1 )
  {
    this->CreateNewItem(this);
  }
  else if ( v4 >= 0 )
  {
    this->EditItem(this, a2: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10398892
// Name: protected: void CVSListBox::OnGetdispinfo(struct tagNMHDR __near *,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVSListBox::OnGetdispinfo(CVSListBox *this, tagNMHDR *pNMHDR, int *pResult)
{
  if ( pNMHDR == nullptr || pNMHDR == (tagNMHDR *)-12 )
    AfxThrowInvalidArgException();
  if ( ((int)pNMHDR[1].hwndFrom & 2) != 0 )
    pNMHDR[3].idFrom = ((int (__thiscall *)(CVSListBox *))this->OnGetImage)(a1: this);
  *pResult = 0;
}

//------------------------------------------------------------------------------
// Address: 0x103988C7
// Name: protected: void CVSListBox::OnItemChanged(struct tagNMHDR __near *,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVSListBox::OnItemChanged(CVSListBox *this, tagNMHDR *pNMHDR, int *pResult)
{
  if ( pNMHDR == nullptr )
    AfxThrowInvalidArgException();
  if ( pNMHDR[2].idFrom == 8 && ((LOBYTE(pNMHDR[1].code) ^ LOBYTE(pNMHDR[2].hwndFrom)) & 2) != 0 )
    this->OnSelectionChanged(this);
  *pResult = 0;
}

//------------------------------------------------------------------------------
// Address: 0x103988FB
// Name: public: CList<class CMFCButton __near *,class CMFCButton __near *>::CList<class CMFCButton __near *,class CMFCButton __near *>(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CList<CMFCButton *,CMFCButton *> *__thiscall CList<CMFCButton *,CMFCButton *>::CList<CMFCButton *,CMFCButton *>(
        CList<CMFCButton *,CMFCButton *> *this,
        int nBlockSize)
{
  this->m_nCount = 0;
  this->m_pNodeFree = nullptr;
  this->m_pNodeTail = nullptr;
  this->m_pNodeHead = nullptr;
  this->m_pBlocks = nullptr;
  this->__vftable = (CList<CMFCButton *,CMFCButton *>_vtbl *)&CList<CMFCButton *,CMFCButton *>::`vftable';
  this->m_nBlockSize = nBlockSize;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10398923
// Name: public: CList<unsigned long,unsigned long>::CList<unsigned long,unsigned long>(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CList<unsigned long,unsigned long> *__thiscall CList<unsigned long,unsigned long>::CList<unsigned long,unsigned long>(
        CList<unsigned long,unsigned long> *this,
        int nBlockSize)
{
  this->m_nCount = 0;
  this->m_pNodeFree = nullptr;
  this->m_pNodeTail = nullptr;
  this->m_pNodeHead = nullptr;
  this->m_pBlocks = nullptr;
  this->__vftable = (CList<unsigned long,unsigned long>_vtbl *)&CList<unsigned long,unsigned long>::`vftable';
  this->m_nBlockSize = nBlockSize;
  return this;
}
