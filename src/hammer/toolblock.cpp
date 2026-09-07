// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/toolblock.cpp
// Functions: 14
// ============================================================

#include "hammer\toolblock.h"

//------------------------------------------------------------------------------
// Address: 0x10157800
// Name: public: virtual bool CToolBlock::OnLMouseDown3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolBlock::OnLMouseDown3D(
        CToolBlock *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  CMapView *v5; // eax
  CMapView *v6; // eax

  Tool3D::OnLMouseDown3D(this, pView, nFlags, vPoint);
  if ( !this->IsEmpty(this) )
  {
    v5 = pView != nullptr ? &pView->CMapView : nullptr;
    if ( this->HitTest(this, a2: v5, a3: vPoint, a4: true) != 0 )
    {
      if ( pView != nullptr )
        v6 = &pView->CMapView;
      else
        v6 = nullptr;
      this->StartTranslation(this, a2: v6, a3: vPoint, a4: &this->m_LastHitTestHandle, a5: nullptr, a6: nullptr);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10157880
// Name: public: virtual bool CToolBlock::OnLMouseDown2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolBlock::OnLMouseDown2D(
        CToolBlock *this,
        CMapView2D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  CMapView *v5; // eax
  CMapView *v6; // eax

  Tool3D::OnLMouseDown2D(this, pView, nFlags, vPoint);
  if ( !this->IsEmpty(this) )
  {
    v5 = pView != nullptr ? &pView->CMapView : nullptr;
    if ( this->HitTest(this, a2: v5, a3: vPoint, a4: true) != 0 )
    {
      if ( pView != nullptr )
        v6 = &pView->CMapView;
      else
        v6 = nullptr;
      this->StartTranslation(this, a2: v6, a3: vPoint, a4: &this->m_LastHitTestHandle, a5: nullptr, a6: nullptr);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10157950
// Name: public: virtual bool CToolBlock::OnMouseMove2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolBlock::OnMouseMove2D(
        CToolBlock *this,
        CMapView2D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  unsigned int (__thiscall *GetConstraints)(struct CToolBlock *, unsigned int); // edx
  CMapView *v7; // edi
  int v9; // eax
  double v10; // st7
  float v11; // xmm0_4
  const Vector *(__thiscall *GetViewAxis)(CMapView *); // edx
  float *v13; // eax
  unsigned int updated; // eax
  char string[32]; // [esp+18h] [ebp-D0h] BYREF
  char szBuf[128]; // [esp+38h] [ebp-B0h] BYREF
  Vector bmaxs; // [esp+B8h] [ebp-30h] BYREF
  Vector vecStart; // [esp+C4h] [ebp-24h] BYREF
  Vector vecSize; // [esp+D0h] [ebp-18h]
  Vector vecWorld; // [esp+DCh] [ebp-Ch]
  int nFlagsa; // [esp+F4h] [ebp+Ch]

  GetConstraints = this->GetConstraints;
  LODWORD(vecWorld.z) = 2;
  nFlagsa = GetConstraints(this, a2: nFlags);
  Tool3D::OnMouseMove2D(this, pView, nFlags, vPoint);
  v7 = &pView->CMapView;
  v7->ClientToWorld(this: v7, a2: (Vector *)&bmaxs.z, a3: vPoint);
  if ( (nFlagsa & 4) != 0 )
    CMapDoc::Snap(this: this->m_pDocument, pt: (Vector *)&bmaxs.z, nFlags: nFlagsa);
  sprintf(string: &string[4], format: " @%.0f, %.0f ", *(&bmaxs.z + pView->axHorz), *(&bmaxs.z + pView->axVert));
  SetStatusText(nIndex: 2, pszText: &string[4]);
  if ( this->IsTranslating(this) )
  {
    Tool3D::UpdateTranslation(this, pView: &pView->CMapView, vPoint, nFlags: nFlagsa);
    return 1;
  }
  if ( this->m_bMouseDragged[0] )
  {
    CVGuiWnd::SetCursor(this: &pView->CVGuiWnd, filename: "Resource/block.cur");
    v7->ClientToWorld(this: &pView->CMapView, a2: (Vector *)&szBuf[112], a3: this->m_vMouseStart);
    if ( (nFlagsa & 4) != 0 )
      CMapDoc::Snap(this: this->m_pDocument, pt: (Vector *)&szBuf[112], nFlags: nFlagsa);
    CSelection::GetLastValidBounds(
      this: this->m_pDocument->m_pSelection,
      vecMins: (Vector *)&vecStart.z,
      vecMaxs: (Vector *)&szBuf[100]);
    v9 = 4 * pView->axThird;
    v10 = *(float *)((char *)&vecStart.z + v9);
    vecSize.z = *(float *)&szBuf[100] - vecStart.z;
    v11 = *(float *)&szBuf[104];
    *(float *)&szBuf[v9 + 112] = v10;
    GetViewAxis = v7->GetViewAxis;
    vecWorld.x = v11 - vecSize.x;
    vecWorld.y = *(float *)&szBuf[108] - vecSize.y;
    v13 = (float *)GetViewAxis(this: &pView->CMapView);
    *(float *)&szBuf[124] = vecSize.z * *v13;
    bmaxs.x = v13[1] * vecWorld.x;
    bmaxs.y = v13[2] * vecWorld.y;
    Box3D::StartNew(
      this,
      pView: &pView->CMapView,
      vPoint,
      vecStart: (const Vector *)&szBuf[112],
      vecSize: (const Vector *)&szBuf[124]);
  }
  else if ( !this->IsEmpty(this) && this->HitTest(this, a2: &pView->CMapView, a3: vPoint, a4: true) != 0 )
  {
    updated = Box3D::UpdateCursor(
                this,
                pView: &pView->CMapView,
                vHandleHit: &this->m_LastHitTestHandle,
                eTransformMode: this->m_TranslateMode);
    if ( updated == 1 )
      return 1;
    goto LABEL_10;
  }
  updated = LODWORD(vecWorld.z);
LABEL_10:
  CVGuiWnd::SetCursor(this: &pView->CVGuiWnd, cursor: updated);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10157B70
// Name: public: virtual bool CToolBlock::OnMouseMove3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolBlock::OnMouseMove3D(
        CToolBlock *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  unsigned int v5; // eax
  CMapView *v6; // ecx

  Tool3D::OnMouseMove3D(this, pView, nFlags, vPoint);
  if ( this->IsTranslating(this) )
  {
    v5 = this->GetConstraints(this, a2: nFlags);
    if ( pView != nullptr )
      v6 = &pView->CMapView;
    else
      v6 = nullptr;
    Tool3D::UpdateTranslation(this, pView: v6, vPoint, nFlags: v5);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10157BD0
// Name: public: bool CToolBlockMessageWnd::Create(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CToolBlockMessageWnd::Create(CToolBlockMessageWnd *this)
{
  tagWNDCLASSA wndcls; // [esp+4h] [ebp-38h] BYREF
  tagRECT rect; // [esp+2Ch] [ebp-10h] BYREF

  wndcls.style = 0;
  memset(&wndcls.cbClsExtra, 0, 32);
  wndcls.lpfnWndProc = (int (__stdcall *)(HWND__ *, unsigned int, unsigned int, int))AfxGetAfxWndProc();
  wndcls.hInstance = AfxGetModuleState()->m_hCurrentInstanceHandle;
  wndcls.lpszClassName = g_pszClassName_0;
  if ( AfxRegisterClass(lpWndClass: &wndcls) == 0 )
    return false;
  rect.right = 10;
  rect.bottom = 10;
  rect.left = 0;
  rect.top = 0;
  return CWnd::CreateEx(
           this,
           dwExStyle: 0,
           lpszClassName: g_pszClassName_0,
           lpszWindowName: g_pszClassName_0,
           dwStyle: 0,
           &rect,
           pParentWnd: nullptr,
           nID: nullptr,
           lpParam: nullptr) == 1;
}

//------------------------------------------------------------------------------
// Address: 0x10157C60
// Name: private: void CToolBlock::CreateMapObject(class CMapView __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolBlock::CreateMapObject(CToolBlock *this, CMapView *pView)
{
  float v3; // xmm1_4
  float z; // edx
  float v5; // eax
  __int32 v6; // eax
  CMainFrame *MainWnd; // eax
  CMapSolid *v8; // eax
  CMapClass *v9; // edi
  CHistory *History; // eax
  DrawType_t (__thiscall *GetDrawType)(CMapView *); // eax
  int v12; // eax
  CHistory *v13; // eax
  const CUtlReferenceVector<CMapClass> *List; // [esp-18h] [ebp-50h]
  BoundBox NewBox; // [esp+0h] [ebp-38h] BYREF
  Vector center; // [esp+1Ch] [ebp-1Ch] BYREF
  QAngle angles; // [esp+28h] [ebp-10h] BYREF
  CMapWorld *pWorld; // [esp+34h] [ebp-4h]

  v3 = this->bmaxs.x - this->bmins.x;
  pWorld = this->m_pDocument->m_pWorld;
  if ( v3 == 0.0 || (float)(this->bmaxs.y - this->bmins.y) == 0.0 || (float)(this->bmaxs.z - this->bmins.z) == 0.0 )
  {
    AfxMessageBox(lpszText: "The box is empty.", nType: 0, nIDHelp: 0);
    this->SetEmpty(this);
  }
  else
  {
    z = this->bmins.z;
    v5 = this->bmaxs.z;
    *(_QWORD *)&NewBox.bmins.x = *(_QWORD *)&this->bmins.x;
    NewBox.__vftable = (BoundBox_vtbl *)&BoundBox::`vftable';
    NewBox.bmins.z = z;
    *(_QWORD *)&NewBox.bmaxs.x = *(_QWORD *)&this->bmaxs.x;
    NewBox.bmaxs.z = v5;
    if ( Options.view2d.bOrientPrimitives != 0 )
    {
      v6 = pView->GetDrawType(this: pView) - 1;
      if ( v6 != 0 )
      {
        if ( v6 == 1 )
          BoundBox::Rotate90(this: &NewBox, axis: 0);
      }
      else
      {
        BoundBox::Rotate90(this: &NewBox, axis: 1);
      }
    }
    MainWnd = GetMainWnd();
    v8 = CObjectBar::CreateInBox(this: &MainWnd->m_ObjectBar, pBox: &NewBox, pView);
    v9 = v8;
    if ( v8 != nullptr )
    {
      CMapDoc::ExpandObjectKeywords(this: this->m_pDocument, pObject: v8, pWorld);
      List = CSelection::GetList(this: this->m_pDocument->m_pSelection);
      History = GetHistory();
      CHistory::MarkUndoPosition(this: History, pSelection: List, pszName: "New Object", bFromOpposite: 0);
      this->m_pDocument->AddObjectToWorld(this: this->m_pDocument, a2: v9, a3: nullptr);
      if ( Options.view2d.bOrientPrimitives != 0 )
      {
        BoundBox::GetBoundsCenter(this: &v9->m_Render2DBox, ptdest: &center);
        GetDrawType = pView->GetDrawType;
        memset(&angles, 0, sizeof(angles));
        v12 = ((int (__thiscall *)(CMapView *, BoundBox_vtbl *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))GetDrawType)(
                a1: pView,
                a2: NewBox.__vftable,
                a3: LODWORD(NewBox.bmins.x),
                a4: LODWORD(NewBox.bmins.y),
                a5: LODWORD(NewBox.bmins.z),
                a6: LODWORD(NewBox.bmaxs.x),
                a7: LODWORD(NewBox.bmaxs.y),
                a8: LODWORD(NewBox.bmaxs.z))
            - 1;
        if ( v12 != 0 )
        {
          if ( v12 == 1 )
          {
            angles.x = 90.0;
            CMapAtom::TransRotate(this: v9, RefPoint: &center, Angles: &angles);
          }
        }
        else
        {
          angles.y = 90.0;
          CMapAtom::TransRotate(this: v9, RefPoint: &center, Angles: &angles);
        }
      }
      v13 = GetHistory();
      CHistory::KeepNew(this: v13, pObject: v9, bKeepChildren: true);
      CMapDoc::SelectObject(this: this->m_pDocument, pObj: v9, cmd: 1042);
      ((void (__thiscall *)(CMapDoc *, int, BoundBox_vtbl *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))this->m_pDocument->SetModifiedFlag)(
        a1: this->m_pDocument,
        a2: 1,
        a3: NewBox.__vftable,
        a4: LODWORD(NewBox.bmins.x),
        a5: LODWORD(NewBox.bmins.y),
        a6: LODWORD(NewBox.bmins.z),
        a7: LODWORD(NewBox.bmaxs.x),
        a8: LODWORD(NewBox.bmaxs.y),
        a9: LODWORD(NewBox.bmaxs.z),
        a10: LODWORD(center.x),
        a11: LODWORD(center.y),
        a12: LODWORD(center.z),
        a13: LODWORD(angles.x));
      this->SetEmpty(this);
      BoundBox::ResetBounds(this: &this->BoundBox);
    }
    else
    {
      this->SetEmpty(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10157E60
// Name: protected: void CToolBlockMessageWnd::OnCreateObject(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolBlockMessageWnd::OnCreateObject(CToolBlockMessageWnd *this)
{
  CMapView2D *m_pView2D; // eax

  m_pView2D = this->m_pView2D;
  if ( m_pView2D != nullptr )
    CToolBlock::CreateMapObject(this: this->m_pToolBlock, pView: &m_pView2D->CMapView);
  else
    CToolBlock::CreateMapObject(this: this->m_pToolBlock, pView: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10157E80
// Name: public: CToolBlock::CToolBlock(void)
// Source: json
//------------------------------------------------------------------------------
CToolBlock *__thiscall CToolBlock::CToolBlock(CToolBlock *this)
{
  unsigned int v3; // [esp-4h] [ebp-18h]

  Box3D::Box3D(this);
  v3 = this->m_dwDrawFlags | 8;
  this->Box3D::Tool3D::CBaseTool::__vftable = (CToolBlock_vtbl *)&CToolBlock::`vftable'{for `Tool3D'};
  this->Box3D::BoundBox::__vftable = (BoundBox_vtbl *)&CToolBlock::`vftable'{for `BoundBox'};
  Box3D::SetDrawFlags(this, dwFlags: v3);
  Box3D::SetDrawColors(this, dwHandleColor: Options.colors.clrToolHandle, dwBoxColor: Options.colors.clrToolBlock);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10157F70
// Name: public: virtual bool CToolBlock::OnContextMenu2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolBlock::OnContextMenu2D(
        CToolBlock *this,
        CMapView2D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  AFX_MODULE_STATE *ModuleState; // eax
  HMENU MenuW; // eax
  HMENU SubMenu; // eax
  float x; // xmm1_4
  float y; // xmm0_4
  int v12; // eax
  HWND__ *m_hWnd; // edx
  CPoint ptScreen; // [esp+Ch] [ebp-14h] BYREF
  int v15; // [esp+1Ch] [ebp-4h]
  const Vector2D *vPointa; // [esp+30h] [ebp+10h]

  if ( (_S1_22 & 1) == 0 )
  {
    _S1_22 |= 1u;
    menu_0.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
    menu_0.m_hMenu = nullptr;
    atexit(func: CToolBlock::OnContextMenu2D_::_2_::_dynamic_atexit_destructor_for__menu__);
    v15 = -1;
  }
  if ( (_S1_22 & 2) == 0 )
  {
    _S1_22 |= 2u;
    menuCreate.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
    menuCreate.m_hMenu = nullptr;
    atexit(func: CToolBlock::OnContextMenu2D_::_2_::_dynamic_atexit_destructor_for__menuCreate__);
    v15 = -1;
  }
  if ( !bInit_6 )
  {
    bInit_6 = true;
    ModuleState = AfxGetModuleState();
    MenuW = LoadMenuW(hInstance: ModuleState->m_hCurrentResourceHandle, lpMenuName: (LPCWSTR)0xB6);
    CMenu::Attach(this: &menu_0, hMenu: MenuW);
    SubMenu = GetSubMenu(hMenu: menu_0.m_hMenu, nPos: 1);
    CMenu::Attach(this: &menuCreate, hMenu: SubMenu);
    CToolBlockMessageWnd::Create(this: &s_wndToolMessage);
  }
  x = vPoint->x;
  if ( vPoint->x < 0.0 )
    return 0;
  y = vPoint->y;
  vPointa = (const Vector2D *)&vPoint->y;
  if ( y < 0.0 || (float)pView->m_ClientWidth <= x || (float)pView->m_ClientHeight <= y )
    return 0;
  if ( !this->IsEmpty(this) && this->HitTest(this, a2: &pView->CMapView, a3: vPoint, a4: false) != 0 )
  {
    v12 = (int)vPointa->x;
    m_hWnd = pView->m_hWnd;
    ptScreen.x = (int)vPoint->x;
    ptScreen.y = v12;
    ClientToScreen(hWnd: m_hWnd, lpPoint: &ptScreen);
    s_wndToolMessage.m_pToolBlock = this;
    s_wndToolMessage.m_pView2D = pView;
    CMenu::TrackPopupMenu(
      this: &menuCreate,
      nFlags: 2u,
      x: ptScreen.x,
      y: ptScreen.y,
      pWnd: &s_wndToolMessage,
      lpRect: nullptr);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10158130
// Name: public: virtual bool CToolBlock::OnKeyDown3D(class CMapView3D __near *,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolBlock::OnKeyDown3D(
        CToolBlock *this,
        CMapView3D *pView,
        unsigned int nChar,
        unsigned int nRepCnt,
        unsigned int nFlags)
{
  CToolManager *v7; // eax

  if ( nChar == 13 )
  {
    if ( !this->IsEmpty(this) )
    {
      if ( pView != nullptr )
      {
        CToolBlock::CreateMapObject(this, pView: &pView->CMapView);
        return 1;
      }
      CToolBlock::CreateMapObject(this, pView: nullptr);
    }
    return 1;
  }
  else if ( nChar == 27 )
  {
    if ( this->IsEmpty(this) )
    {
      v7 = ToolManager();
      CToolManager::SetTool(this: v7, eNewTool: TOOL_POINTER);
    }
    else
    {
      this->SetEmpty(this);
    }
    return 1;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101581B0
// Name: protected: virtual struct AFX_MSGMAP const __near * CToolBlockMessageWnd::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CToolBlockMessageWnd::GetMessageMap(CToolBlockMessageWnd *this)
{
  return (const AFX_MSGMAP *)&off_105FAF7C;
}

//------------------------------------------------------------------------------
// Address: 0x105CB7A0
// Name: _CToolBlock::OnContextMenu2D_::_2_::_dynamic_atexit_destructor_for__menuCreate__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CToolBlock::OnContextMenu2D_::_2_::_dynamic_atexit_destructor_for__menuCreate__()
{
  menuCreate.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  CMenu::DestroyMenu(this: &menuCreate);
}

//------------------------------------------------------------------------------
// Address: 0x105CB7C0
// Name: _CToolBlock::OnContextMenu2D_::_2_::_dynamic_atexit_destructor_for__menu__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CToolBlock::OnContextMenu2D_::_2_::_dynamic_atexit_destructor_for__menu__()
{
  menu_0.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
  CMenu::DestroyMenu(this: &menu_0);
}

//------------------------------------------------------------------------------
// Address: 0x105CB7E0
// Name: _dynamic_atexit_destructor_for__s_wndToolMessage___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_wndToolMessage___0()
{
  CWnd::~CWnd(this: &s_wndToolMessage_0);
}
