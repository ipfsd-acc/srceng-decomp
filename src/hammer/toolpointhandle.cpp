// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/toolpointhandle.cpp
// Functions: 12
// ============================================================

#include "hammer\toolpointhandle.h"

//------------------------------------------------------------------------------
// Address: 0x101663A0
// Name: public: CToolPointHandle::CToolPointHandle(void)
// Source: json
//------------------------------------------------------------------------------
CToolPointHandle *__thiscall CToolPointHandle::CToolPointHandle(CToolPointHandle *this)
{
  this->__vftable = (CToolPointHandle_vtbl *)&CBaseTool::`vftable';
  *(_WORD *)&this->m_bActiveTool = 256;
  this->m_pDocument = nullptr;
  this->__vftable = (CToolPointHandle_vtbl *)&CToolPointHandle::`vftable';
  this->m_pPoint = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10166410
// Name: public: virtual bool CToolPointHandle::OnLMouseUp2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolPointHandle::OnLMouseUp2D(
        CToolPointHandle *this,
        CMapView2D *pView,
        CMapView2D *nFlags,
        const Vector2D *VPoint)
{
  CToolManager *v5; // eax

  CMapPointHandle::UpdateOrigin(this: this->m_pPoint, vecOrigin: &this->m_pPoint->m_Origin);
  v5 = ToolManager();
  CToolManager::PopTool(this: v5);
  ReleaseCapture();
  this->m_pDocument->SetModifiedFlag(this: this->m_pDocument, a2: 1);
  CMapDoc::UpdateAllViews(this: this->m_pDocument, nFlags: 16, ub: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10166450
// Name: public: virtual bool CToolPointHandle::OnMouseMove2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolPointHandle::OnMouseMove2D(
        CToolPointHandle *this,
        CMapView2D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  CMapPointHandle *m_pPoint; // eax
  char string[28]; // [esp+18h] [ebp-90h] BYREF
  char szBuf_104[128]; // [esp+9Ch] [ebp-Ch] BYREF

  CMapView2DBase::ToolScrollToPoint(this: pView, ptClient: vPoint);
  pView->ClientToWorld(this: &pView->CMapView, a2: (Vector *)szBuf_104, a3: vPoint);
  CMapDoc::Snap(this: this->m_pDocument, pt: (Vector *)szBuf_104, nFlags: 16);
  m_pPoint = this->m_pPoint;
  *(&m_pPoint->m_Origin.x + pView->axHorz) = *(float *)&szBuf_104[4 * pView->axHorz];
  *(&m_pPoint->m_Origin.x + pView->axVert) = *(float *)&szBuf_104[4 * pView->axVert];
  sprintf(
    string: &string[4],
    format: " @%.0f, %.0f ",
    *(&m_pPoint->m_Origin.x + pView->axHorz),
    *(&m_pPoint->m_Origin.x + pView->axVert));
  SetStatusText(nIndex: 2, pszText: &string[4]);
  CMapDoc::UpdateAllViews(this: this->m_pDocument, nFlags: 16, ub: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10166510
// Name: public: virtual void CToolPointHandle::RenderTool2D(class CRender2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolPointHandle::RenderTool2D(CToolPointHandle *this, CRender2D *pRender)
{
  SelectionState_t v3; // edi

  v3 = this->m_pPoint->SetSelectionState(this: this->m_pPoint, a2: SELECT_MODIFY);
  this->m_pPoint->Render2D(this: this->m_pPoint, a2: pRender);
  this->m_pPoint->SetSelectionState(this: this->m_pPoint, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10166550
// Name: public: void CToolPointHandle::CenterOnParent(class CMapView __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolPointHandle::CenterOnParent(CToolPointHandle *this, CMapView *pView)
{
  CHistory *History; // eax
  CHistory *v4; // eax
  CMapClass *v5; // eax
  const CUtlReferenceVector<CMapClass> *List; // [esp-Ch] [ebp-1Ch]
  CMapPointHandle *m_pPoint; // [esp-4h] [ebp-14h]
  Vector vecCenter; // [esp+4h] [ebp-Ch] BYREF

  if ( this->m_pPoint != nullptr )
  {
    List = CSelection::GetList(this: this->m_pDocument->m_pSelection);
    History = GetHistory();
    CHistory::MarkUndoPosition(this: History, pSelection: List, pszName: "Center Origin", bFromOpposite: 0);
    m_pPoint = this->m_pPoint;
    v4 = GetHistory();
    CHistory::Keep(this: v4, pObject: m_pPoint);
    v5 = this->m_pPoint->GetParent(this: this->m_pPoint);
    BoundBox::GetBoundsCenter(this: &v5->m_Render2DBox, ptdest: &vecCenter);
    CMapPointHandle::UpdateOrigin(this: this->m_pPoint, vecOrigin: &vecCenter);
    this->m_pDocument->SetModifiedFlag(this: this->m_pDocument, a2: 1);
    CMapDoc::UpdateAllViews(this: this->m_pDocument, nFlags: 16, ub: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101665E0
// Name: public: bool CToolPointHandleMsgWnd::Create(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CToolPointHandleMsgWnd::Create(CToolPointHandleMsgWnd *this)
{
  tagWNDCLASSA wndcls; // [esp+4h] [ebp-38h] BYREF
  tagRECT rect; // [esp+2Ch] [ebp-10h] BYREF

  wndcls.style = 0;
  memset(&wndcls.cbClsExtra, 0, 32);
  wndcls.lpfnWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))AfxGetAfxWndProc();
  wndcls.hInstance = AfxGetModuleState()->m_hCurrentInstanceHandle;
  wndcls.lpszClassName = g_pszClassName_2;
  if ( AfxRegisterClass(lpWndClass: &wndcls) == 0 )
    return false;
  rect.right = 10;
  rect.bottom = 10;
  rect.left = 0;
  rect.top = 0;
  return CWnd::CreateEx(
           this,
           dwExStyle: 0,
           lpszClassName: g_pszClassName_2,
           lpszWindowName: g_pszClassName_2,
           dwStyle: 0,
           &rect,
           pParentWnd: nullptr,
           nID: nullptr,
           lpParam: nullptr) == 1;
}

//------------------------------------------------------------------------------
// Address: 0x10166670
// Name: protected: void CToolPointHandleMsgWnd::OnCenter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolPointHandleMsgWnd::OnCenter(CToolPointHandleMsgWnd *this)
{
  CToolPointHandle *m_pToolPointHandle; // ecx
  CMapView2D *m_pView2D; // eax

  m_pToolPointHandle = this->m_pToolPointHandle;
  if ( m_pToolPointHandle != nullptr )
  {
    m_pView2D = this->m_pView2D;
    if ( m_pView2D != nullptr )
      CToolPointHandle::CenterOnParent(this: m_pToolPointHandle, pView: &m_pView2D->CMapView);
    else
      CToolPointHandle::CenterOnParent(this: m_pToolPointHandle, pView: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101666F0
// Name: public: virtual bool CToolPointHandle::OnLMouseDown2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolPointHandle::OnLMouseDown2D(
        CToolPointHandle *this,
        CMapView2D *pView,
        unsigned int nFlags,
        const Vector2D *VPoint)
{
  CToolManager *v5; // eax
  HWND v6; // eax
  CHistory *History; // eax
  CHistory *v8; // eax
  const CUtlReferenceVector<CMapClass> *List; // [esp-Ch] [ebp-10h]
  CMapPointHandle *m_pPoint; // [esp-4h] [ebp-8h]

  v5 = ToolManager();
  CToolManager::PushTool(this: v5, eToolID: TOOL_POINT_HANDLE);
  v6 = SetCapture(hWnd: pView->m_hWnd);
  CWnd::FromHandle(hWnd: v6);
  List = CSelection::GetList(this: this->m_pDocument->m_pSelection);
  History = GetHistory();
  CHistory::MarkUndoPosition(this: History, pSelection: List, pszName: "Modify Origin", bFromOpposite: 0);
  m_pPoint = this->m_pPoint;
  v8 = GetHistory();
  CHistory::Keep(this: v8, pObject: m_pPoint);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10166750
// Name: public: virtual bool CToolPointHandle::OnContextMenu2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolPointHandle::OnContextMenu2D(
        CToolPointHandle *this,
        CMapView2D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  AFX_MODULE_STATE *ModuleState; // eax
  HMENU MenuW; // eax
  HMENU SubMenu; // eax
  float x; // xmm1_4
  float y; // xmm0_4
  HWND__ *m_hWnd; // [esp-8h] [ebp-24h]
  CPoint ptScreen; // [esp+4h] [ebp-18h] BYREF
  CToolPointHandle *v12; // [esp+Ch] [ebp-10h]
  int v13; // [esp+18h] [ebp-4h]

  v12 = this;
  if ( (_S1_25 & 1) == 0 )
  {
    _S1_25 |= 1u;
    menu_3.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
    menu_3.m_hMenu = nullptr;
    atexit(func: CToolPointHandle::OnContextMenu2D_::_2_::_dynamic_atexit_destructor_for__menu__);
    v13 = -1;
  }
  if ( (_S1_25 & 2) == 0 )
  {
    _S1_25 |= 2u;
    menuCreate_1.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
    menuCreate_1.m_hMenu = nullptr;
    atexit(func: CToolPointHandle::OnContextMenu2D_::_2_::_dynamic_atexit_destructor_for__menuCreate__);
    v13 = -1;
  }
  if ( !bInit_9 )
  {
    bInit_9 = true;
    ModuleState = AfxGetModuleState();
    MenuW = LoadMenuW(hInstance: ModuleState->m_hCurrentResourceHandle, lpMenuName: (LPCWSTR)0xB6);
    CMenu::Attach(this: &menu_3, hMenu: MenuW);
    SubMenu = GetSubMenu(hMenu: menu_3.m_hMenu, nPos: 7);
    CMenu::Attach(this: &menuCreate_1, hMenu: SubMenu);
    CToolPointHandleMsgWnd::Create(this: &s_wndToolMessage_1);
  }
  x = vPoint->x;
  if ( vPoint->x < 0.0 )
    return 0;
  y = vPoint->y;
  if ( y < 0.0 || (float)pView->m_ClientWidth <= x || (float)pView->m_ClientHeight <= y )
    return 0;
  ptScreen.x = (int)x;
  m_hWnd = pView->m_hWnd;
  ptScreen.y = (int)y;
  ClientToScreen(hWnd: m_hWnd, lpPoint: &ptScreen);
  s_wndToolMessage_1.m_pToolPointHandle = v12;
  s_wndToolMessage_1.m_pView2D = pView;
  CMenu::TrackPopupMenu(
    this: &menuCreate_1,
    nFlags: 2u,
    x: ptScreen.x,
    y: ptScreen.y,
    pWnd: &s_wndToolMessage_1,
    lpRect: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101668F0
// Name: protected: virtual struct AFX_MSGMAP const __near * CToolPointHandleMsgWnd::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CToolPointHandleMsgWnd::GetMessageMap(CToolPointHandleMsgWnd *this)
{
  return (const AFX_MSGMAP *)&off_105FC128;
}

//------------------------------------------------------------------------------
// Address: 0x105CB8F0
// Name: _CToolPointHandle::OnContextMenu2D_::_2_::_dynamic_atexit_destructor_for__menuCreate__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CToolPointHandle::OnContextMenu2D_::_2_::_dynamic_atexit_destructor_for__menuCreate__()
{
  menuCreate_1.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  CMenu::DestroyMenu(this: &menuCreate_1);
}

//------------------------------------------------------------------------------
// Address: 0x105CB910
// Name: _CToolPointHandle::OnContextMenu2D_::_2_::_dynamic_atexit_destructor_for__menu__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CToolPointHandle::OnContextMenu2D_::_2_::_dynamic_atexit_destructor_for__menu__()
{
  menu_3.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  CMenu::DestroyMenu(this: &menu_3);
}
