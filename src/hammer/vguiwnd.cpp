// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/vguiwnd.cpp
// Functions: 68
// ============================================================

#include "hammer\vguiwnd.h"

//------------------------------------------------------------------------------
// Address: 0x100BA0F0
// Name: public: virtual struct CRuntimeClass __near * CVGuiPanelWnd::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CVGuiPanelWnd::GetRuntimeClass(CVGuiPanelWnd *this)
{
  return &CVGuiPanelWnd::classCVGuiPanelWnd;
}

//------------------------------------------------------------------------------
// Address: 0x100BA100
// Name: public: CVGuiWnd::CVGuiWnd(void)
// Source: json
//------------------------------------------------------------------------------
CVGuiWnd *__thiscall CVGuiWnd::CVGuiWnd(CVGuiWnd *this)
{
  this->__vftable = (CVGuiWnd_vtbl *)&CVGuiWnd::`vftable';
  this->m_ClearColor = 0;
  this->m_pMainPanel = nullptr;
  this->m_pParentWnd = nullptr;
  this->m_hVGuiContext = -1;
  *(_WORD *)&this->m_bIsDrawing = 0;
  *(Color *)((char *)&this->m_ClearColor + 1) = (Color)33488896;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100BA130
// Name: public: void CVGuiWnd::SetParentWindow(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiWnd::SetParentWindow(CVGuiWnd *this, CWnd *pParent)
{
  this->m_pParentWnd = pParent;
  CWnd::EnableWindow(this: pParent, bEnable: 1);
  CWnd::SetFocus(this: this->m_pParentWnd);
}

//------------------------------------------------------------------------------
// Address: 0x100BA150
// Name: public: void CVGuiWnd::SetCursor(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiWnd::SetCursor(CVGuiWnd *this, unsigned int cursor)
{
  if ( this->m_pMainPanel != nullptr )
    this->m_pMainPanel->SetCursor(this: this->m_pMainPanel, a2: cursor);
}

//------------------------------------------------------------------------------
// Address: 0x100BA170
// Name: public: void CVGuiWnd::SetCursor(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiWnd::SetCursor(CVGuiWnd *this, const char *filename)
{
  unsigned int v3; // eax

  v3 = g_pVGuiSurface->CreateCursorFromFile(this: g_pVGuiSurface, a2: filename, a3: nullptr);
  this->m_pMainPanel->SetCursor(this: this->m_pMainPanel, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100BA1A0
// Name: public: void CVGuiWnd::SetMainPanel(class vgui::EditablePanel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiWnd::SetMainPanel(CVGuiWnd *this, vgui::EditablePanel *pPanel)
{
  vgui::EditablePanel_vtbl *v3; // edi
  unsigned int v4; // eax
  int v5; // eax
  vgui::EditablePanel *m_pMainPanel; // ecx
  vgui::IVGui *v7; // edi
  vgui::IVGui_vtbl *v8; // ebx
  int v9; // eax

  this->m_pMainPanel = pPanel;
  v3 = pPanel->__vftable;
  v4 = g_pVGuiSurface->GetEmbeddedPanel(this: g_pVGuiSurface);
  v3->SetParent(this: this->m_pMainPanel, a2: v4);
  this->m_pMainPanel->SetVisible(this: this->m_pMainPanel, a2: true);
  this->m_pMainPanel->SetPaintBackgroundEnabled(this: this->m_pMainPanel, a2: false);
  this->m_pMainPanel->SetCursor(this: this->m_pMainPanel, a2: 2u);
  this->m_pMainPanel->SetMouseInputEnabled(this: this->m_pMainPanel, a2: false);
  v5 = g_pVGui->CreateContext(this: g_pVGui);
  m_pMainPanel = this->m_pMainPanel;
  this->m_hVGuiContext = v5;
  v7 = g_pVGui;
  v8 = g_pVGui->__vftable;
  v9 = m_pMainPanel->GetVPanel(this: m_pMainPanel);
  v8->AssociatePanelWithContext(this: v7, a2: this->m_hVGuiContext, a3: v9);
}

//------------------------------------------------------------------------------
// Address: 0x100BA250
// Name: public: class CWnd __near * CVGuiWnd::GetParentWnd(void)
// Source: json
//------------------------------------------------------------------------------
CMapClass *__thiscall CVGuiWnd::GetParentWnd(CMapClass *this)
{
  return (CMapClass *)this->m_pParent;
}

//------------------------------------------------------------------------------
// Address: 0x100BA260
// Name: protected: virtual struct AFX_MSGMAP const __near * CVGuiPanelWnd::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CVGuiPanelWnd::GetMessageMap(CVGuiPanelWnd *this)
{
  if ( (_S1_13 & 1) == 0 )
  {
    _S1_13 |= 1u;
    dword_1072F27C = (int)CParticleBrowser::OnEraseBkgnd;
    dword_1072F280 = 0;
    dword_1072F284 = 0;
    dword_1072F288 = 0;
    dword_1072F28C = 0;
    dword_1072F290 = 0;
    dword_1072F294 = 0;
  }
  return (const AFX_MSGMAP *)&off_105E7EC8;
}

//------------------------------------------------------------------------------
// Address: 0x100BA2E0
// Name: public: CVGuiWnd::~CVGuiWnd(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiWnd::~CVGuiWnd(CVGuiWnd *this)
{
  CHammerVGui *v2; // eax
  CHammerVGui *v3; // eax
  CWnd *m_pParentWnd; // eax
  vgui::EditablePanel *m_pMainPanel; // ecx

  this->__vftable = (CVGuiWnd_vtbl *)&CVGuiWnd::`vftable';
  v2 = HammerVGui();
  if ( CHammerVGui::HasFocus(this: v2, pWnd: this) )
  {
    v3 = HammerVGui();
    CHammerVGui::SetFocus(this: v3, pVGuiWnd: nullptr);
  }
  if ( this->m_hVGuiContext != -1 )
  {
    g_pVGui->DestroyContext(this: g_pVGui, a2: this->m_hVGuiContext);
    this->m_hVGuiContext = -1;
  }
  m_pParentWnd = this->m_pParentWnd;
  if ( m_pParentWnd != nullptr )
    m_pParentWnd = (CWnd *)m_pParentWnd->m_hWnd;
  KillTimer(hWnd: (HWND)m_pParentWnd, uIDEvent: 0x412u);
  m_pMainPanel = this->m_pMainPanel;
  if ( m_pMainPanel != nullptr )
    m_pMainPanel->MarkForDeletion(this: m_pMainPanel);
}

//------------------------------------------------------------------------------
// Address: 0x100BA350
// Name: public: void CVGuiWnd::SetRepaintInterval(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiWnd::SetRepaintInterval(CVGuiWnd *this, UINT msecs)
{
  CWnd *m_pParentWnd; // eax

  m_pParentWnd = this->m_pParentWnd;
  if ( m_pParentWnd != nullptr )
    m_pParentWnd = (CWnd *)m_pParentWnd->m_hWnd;
  SetTimer(hWnd: (HWND)m_pParentWnd, nIDEvent: 0x412u, uElapse: msecs, lpTimerFunc: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100BA380
// Name: protected: void CVGuiWnd::DrawVGuiPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CVGuiWnd::DrawVGuiPanel(CVGuiWnd *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  CWnd *m_pParentWnd; // eax
  HWND m_hWnd; // ebx
  int v6; // eax
  int v7; // edi
  CHammerVGui *v8; // eax
  unsigned int v9; // ebx
  bool (__thiscall *IsVisible)(vgui::IPanel *, unsigned int); // eax
  vgui::ISurface *v11; // ebx
  int v12; // eax
  vgui::ISurface *v13; // ebx
  int v14; // eax
  IMaterialSystem *v15; // ebx
  IEngineTool_vtbl *v16; // edx
  int v17; // eax
  tagRECT Rect; // [esp+8h] [ebp-34h] BYREF
  int v20; // [esp+18h] [ebp-24h]
  void (__thiscall **v21)(vgui::ISurface *, int); // [esp+1Ch] [ebp-20h]
  int tall; // [esp+20h] [ebp-1Ch] BYREF
  int wide; // [esp+24h] [ebp-18h] BYREF
  unsigned int v24; // [esp+28h] [ebp-14h]
  int v25; // [esp+2Ch] [ebp-10h]
  int v26; // [esp+38h] [ebp-4h]

  if ( this->m_pMainPanel != nullptr )
  {
    m_pParentWnd = this->m_pParentWnd;
    if ( m_pParentWnd != nullptr && !this->m_bIsDrawing )
    {
      this->m_bIsDrawing = true;
      m_hWnd = m_pParentWnd->m_hWnd;
      GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
      v6 = ((int (__thiscall *)(IMaterialSystem *, int, int))materials->GetRenderContext)(a1: materials, a2: a3, a3: a2);
      v7 = v6;
      v20 = v6;
      v26 = 0;
      if ( v6 != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
      v26 = 1;
      materials->SetView(this: materials, a2: m_hWnd);
      (*(void (__thiscall **)(int, _DWORD, _DWORD, int, int))(*(_DWORD *)v7 + 152))(
        a1: v7,
        a2: 0,
        a3: 0,
        a4: Rect.right,
        a5: Rect.bottom);
      (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v7 + 296))(
        a1: v7,
        a2: this->m_ClearColor._color[0],
        a3: this->m_ClearColor._color[1],
        a4: this->m_ClearColor._color[2],
        a5: this->m_ClearColor._color[3]);
      (*(void (__thiscall **)(int, int, bool, _DWORD))(*(_DWORD *)v7 + 48))(
        a1: v7,
        a2: 1,
        a3: this->m_bClearZBuffer,
        a4: 0);
      ((void (__stdcall *)(_DWORD))materials->BeginFrame)(a1: 0);
      g_pStudioRender->BeginFrame(this: g_pStudioRender);
      vgui::Panel::GetSize(this: this->m_pMainPanel, &wide, &tall);
      if ( wide != Rect.right || tall != Rect.bottom )
      {
        vgui::Panel::SetBounds(this: this->m_pMainPanel, x: 0, y: 0, wide: Rect.right, tall: Rect.bottom);
        this->m_pMainPanel->Repaint(this: this->m_pMainPanel);
      }
      v8 = HammerVGui();
      CHammerVGui::Simulate(this: v8);
      v25 = -1;
      v24 = 0;
      if ( LOBYTE(AfxGetModuleState()->m_pCurrentWinApp[4].m_dwRef) != 0 && enginevgui != nullptr )
      {
        v9 = enginevgui->GetPanel(this: enginevgui, a2: PANEL_ROOT);
        IsVisible = g_pVGuiPanel->IsVisible;
        v24 = v9;
        v25 = IsVisible(this: g_pVGuiPanel, a2: v9);
        g_pVGuiPanel->SetVisible(this: g_pVGuiPanel, a2: v9, a3: false);
      }
      v11 = g_pVGuiSurface;
      v21 = (void (__thiscall **)(vgui::ISurface *, int))g_pVGuiSurface->__vftable;
      v12 = ((int (__thiscall *)(vgui::EditablePanel *, int))this->m_pMainPanel->GetVPanel)(
              a1: this->m_pMainPanel,
              a2: 1);
      v21[61](a1: v11, a2: v12);
      v13 = g_pVGuiSurface;
      v21 = (void (__thiscall **)(vgui::ISurface *, int))g_pVGuiSurface->__vftable;
      v14 = ((int (__thiscall *)(vgui::EditablePanel *, int))this->m_pMainPanel->GetVPanel)(
              a1: this->m_pMainPanel,
              a2: 1);
      v21[117](a1: v13, a2: v14);
      g_pVGuiSurface->RestrictPaintToSinglePanel(this: g_pVGuiSurface, a2: 0, a3: false);
      if ( v25 != -1 )
        g_pVGuiPanel->SetVisible(this: g_pVGuiPanel, a2: v24, a3: v25 != 0);
      g_pStudioRender->EndFrame(this: g_pStudioRender);
      materials->EndFrame(this: materials);
      materials->SwapBuffers(this: materials);
      if ( enginetools != nullptr )
      {
        v15 = materials;
        v16 = enginetools->__vftable;
        v21 = (void (__thiscall **)(vgui::ISurface *, int))materials->__vftable;
        v17 = (int)v16->GetEngineHwnd(this: enginetools);
        v21[39](a1: (vgui::ISurface *)v15, a2: v17);
      }
      this->m_bIsDrawing = false;
      v26 = 2;
      (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 12))(a1: v7);
      v26 = -1;
      (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 4))(a1: v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BA630
// Name: protected: long CVGuiWnd::WindowProcVGui(unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CVGuiWnd::WindowProcVGui@<eax>(
        CVGuiWnd *this@<ecx>,
        int a2@<ebx>,
        unsigned int uMsg,
        unsigned int wParam,
        int lParam)
{
  int result; // eax
  CHammerVGui *v7; // eax
  CWnd *m_pParentWnd; // esi

  if ( uMsg > 0x113 )
  {
    switch ( uMsg )
    {
      case 0x200u:
      case 0x201u:
      case 0x204u:
      case 0x207u:
        v7 = HammerVGui();
        CHammerVGui::SetFocus(this: v7, pVGuiWnd: this);
        if ( uMsg == 512 )
          return 0;
        InvalidateRect(hWnd: this->m_pParentWnd->m_hWnd, lpRect: nullptr, bErase: true);
        CWnd::SetFocus(this: this->m_pParentWnd);
        result = 0;
        break;
      case 0x202u:
      case 0x203u:
      case 0x205u:
      case 0x206u:
      case 0x208u:
      case 0x209u:
      case 0x20Au:
$LN2_21:
        m_pParentWnd = this->m_pParentWnd;
        if ( m_pParentWnd != nullptr )
          InvalidateRect(hWnd: m_pParentWnd->m_hWnd, lpRect: nullptr, bErase: true);
        return 0;
      default:
        return 0;
    }
  }
  else if ( uMsg == 275 )
  {
    if ( wParam == 1042 )
    {
      InvalidateRect(hWnd: this->m_pParentWnd->m_hWnd, lpRect: nullptr, bErase: true);
      return 0;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    switch ( uMsg )
    {
      case 8u:
        if ( this->m_pMainPanel == nullptr )
          return 0;
        this->m_pMainPanel->SetCursor(this: this->m_pMainPanel, a2: 2u);
        result = 0;
        break;
      case 0xFu:
        CVGuiWnd::DrawVGuiPanel(this, a2, a3: uMsg);
        result = 0;
        break;
      case 0x20u:
        result = 1;
        break;
      case 0x87u:
        result = 132;
        break;
      case 0x100u:
      case 0x101u:
      case 0x102u:
      case 0x104u:
      case 0x105u:
      case 0x106u:
        goto $LN2_21;
      default:
        return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BA870
// Name: public: static class CObject __near * CVGuiPanelWnd::CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CVGuiPanelWnd *__stdcall CVGuiPanelWnd::CreateObject()
{
  CVGuiPanelWnd *v0; // eax

  v0 = (CVGuiPanelWnd *)operator new(nSize: 0x8Cu);
  if ( v0 != nullptr )
    return CVGuiPanelWnd::CVGuiPanelWnd(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100BA8D0
// Name: public: virtual long CVGuiPanelWnd::WindowProc(unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVGuiPanelWnd::WindowProc(CVGuiPanelWnd *this, unsigned int message, unsigned int wParam, int lParam)
{
  if ( CVGuiWnd::WindowProcVGui(this: &this->CVGuiWnd, a2: wParam, uMsg: message, wParam, lParam) != 0 )
    return 1;
  else
    return CWnd::WindowProc(this, message, wParam, lParam);
}

//------------------------------------------------------------------------------
// Address: 0x103C9026
// Name: public: virtual class CWnd __near * CMFCRibbonBaseElement::GetParentWnd(void)const
// Source: json
//------------------------------------------------------------------------------
CMFCRibbonBar *__thiscall CMFCRibbonBaseElement::GetParentWnd(CMFCRibbonBaseElement *this)
{
  CMFCRibbonBar *result; // eax
  CMFCRibbonCategory *m_pParent; // ecx

  result = this->m_pRibbonBar;
  if ( result == nullptr )
  {
    result = (CMFCRibbonBar *)this->m_pParentMenu;
    if ( result == nullptr )
    {
      m_pParent = this->m_pParent;
      if ( m_pParent != nullptr )
        return m_pParent->m_pParentRibbonBar;
      else
        return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103D20A2
// Name: protected: class CWnd __near * CMFCRibbonPanel::GetParentWnd(void)const
// Source: json
//------------------------------------------------------------------------------
CMFCRibbonPanelMenuBar *__thiscall CMFCRibbonPanel::GetParentWnd(CMFCRibbonPanel *this)
{
  CMFCRibbonPanelMenuBar *result; // eax
  CMFCRibbonCategory *m_pParent; // ecx

  result = nullptr;
  if ( this->m_pParentMenuBar != nullptr )
    return this->m_pParentMenuBar;
  m_pParent = this->m_pParent;
  if ( m_pParent != nullptr )
    return (CMFCRibbonPanelMenuBar *)m_pParent->m_pParentRibbonBar;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C287
// Name: protected: virtual class CWnd __near * CMFCRibbonGalleryIcon::GetParentWnd(void)const
// Source: json
//------------------------------------------------------------------------------
CMFCRibbonBar *__thiscall CMFCRibbonGalleryIcon::GetParentWnd(CMFCRibbonGalleryIcon *this)
{
  if ( this->m_pOwner != nullptr )
    return (CMFCRibbonBar *)this->m_pOwner->GetParentWnd(this: this->m_pOwner);
  else
    return CMFCRibbonBaseElement::GetParentWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x103C9045
// Name: public: virtual class CMFCRibbonPanel __near * CMFCRibbonBaseElement::GetParentPanel(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonPanel *__thiscall CMFCRibbonBaseElement::GetParentPanel(CMFCRibbonBaseElement *this)
{
  CMFCRibbonPanelMenuBar *m_pParentMenu; // eax
  CMFCRibbonCategory *m_pCategory; // ecx

  m_pParentMenu = this->m_pParentMenu;
  if ( m_pParentMenu != nullptr )
  {
    m_pCategory = m_pParentMenu->m_pCategory;
    if ( m_pCategory != nullptr )
      return CMFCRibbonCategory::FindPanelWithElem(this: m_pCategory, pElement: this);
    return m_pParentMenu->m_pPanel;
  }
  else
  {
    m_pCategory = this->m_pParent;
    if ( m_pCategory != nullptr )
      return CMFCRibbonCategory::FindPanelWithElem(this: m_pCategory, pElement: this);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C9070
// Name: public: int CMFCRibbonBaseElement::IsMenuMode(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonBaseElement::IsMenuMode(CMFCRibbonBaseElement *this)
{
  CMFCRibbonPanelMenuBar *m_pParentMenu; // eax
  CMFCRibbonPanel *m_pPanel; // eax

  m_pParentMenu = this->m_pParentMenu;
  if ( m_pParentMenu != nullptr && (m_pPanel = m_pParentMenu->m_pPanel) != nullptr )
    return m_pPanel->m_bMenuMode;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103C9088
// Name: public: virtual void CMFCRibbonBaseElement::ClosePopupMenu(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonBaseElement::ClosePopupMenu(CMFCRibbonBaseElement *this)
{
  CMFCPopupMenu *m_pPopupMenu; // eax

  m_pPopupMenu = this->m_pPopupMenu;
  if ( m_pPopupMenu != nullptr && IsWindow(hWnd: m_pPopupMenu->m_hWnd) )
  {
    if ( this->m_pPopupMenu->InCommand(this: this->m_pPopupMenu) != 0 )
      return;
    this->m_pPopupMenu->m_bAutoDestroyParent = 0;
    CMFCPopupMenu::CloseMenu(this: this->m_pPopupMenu, bSetFocusToBar: 0);
  }
  this->m_pPopupMenu = nullptr;
  this->m_bOnBeforeShowItemMenuIsSent = 0;
}

//------------------------------------------------------------------------------
// Address: 0x103C90D1
// Name: public: virtual int CMFCRibbonBaseElement::CanBeAddedToQuickAccessToolBar(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCRibbonBaseElement::CanBeAddedToQuickAccessToolBar(CMFCRibbonBaseElement *this)
{
  unsigned int m_nID; // eax

  m_nID = this->m_nID;
  return m_nID != 0 && m_nID != -1 && IsStandardCommand(uiCmd: this->m_nID) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x103C90ED
// Name: public: virtual int CMFCRibbonBaseElement::OnAddToQAToolbar(class CMFCRibbonQuickAccessToolBar __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonBaseElement::OnAddToQAToolbar(CMFCRibbonBaseElement *this, CMFCRibbonQuickAccessToolBar *qat)
{
  CMFCRibbonQuickAccessToolBar::Add(this: qat, pElem: this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103C9102
// Name: public: virtual int CMFCRibbonBaseElement::StretchToWholeRow(class CDC __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonBaseElement::StretchToWholeRow(CMFCRibbonBaseElement *this, CDC *__formal, int nHeight)
{
  if ( this->CanBeStretched(this) == 0 || this->m_bCompactMode != 0 || this->m_bIntermediateMode != 0 )
    return 0;
  this->m_rect.bottom = nHeight + this->m_rect.top;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103C9137
// Name: protected: virtual int CMFCRibbonBaseElement::GetDropDownImageWidth(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonBaseElement::GetDropDownImageWidth(CMFCRibbonBaseElement *this)
{
  CSize v2; // [esp+0h] [ebp-8h] BYREF

  return CMenuImages::Size(result: &v2)->cx;
}

//------------------------------------------------------------------------------
// Address: 0x103C914B
// Name: protected: virtual void CMFCRibbonSeparator::OnDraw(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonSeparator::OnDraw(CMFCRibbonSeparator *this, CDC *pDC)
{
  CRect *p_m_rect; // esi
  int *p_top; // esi
  CMFCVisualManager *Instance; // eax
  CMFCRibbonPanelMenuBar *m_pParentMenu; // eax
  CMFCRibbonPanelMenuBar *v7; // eax
  CMFCVisualManager *v8; // eax
  int v9; // eax
  CMFCVisualManager *v10; // eax
  CMFCRibbonPanelMenuBar *v11; // ebx
  int bDisableSideBarInXPMode; // [esp+Ch] [ebp-20h]
  CBasePane *pParentBar; // [esp+14h] [ebp-18h]
  CRect rect; // [esp+18h] [ebp-14h] BYREF

  p_m_rect = &this->m_rect;
  if ( !IsRectEmpty(lprc: &this->m_rect) )
  {
    rect.left = p_m_rect->left;
    p_top = &p_m_rect->top;
    rect.top = *p_top++;
    rect.right = *p_top;
    rect.bottom = p_top[1];
    if ( this->m_bQuickAccessMode != 0 )
    {
      rect.left = (rect.right + rect.left) / 2 - 1;
      rect.right = rect.left + 2;
      InflateRect(lprc: &rect, dx: 0, dy: -3);
      Instance = CMFCVisualManager::GetInstance();
      ((void (__thiscall *)(CMFCVisualManager *, CDC *, CMFCRibbonSeparator *, int, int, int, int))Instance->OnDrawRibbonQuickAccessToolBarSeparator)(
        a1: Instance,
        a2: pDC,
        a3: this,
        a4: rect.left,
        a5: rect.top,
        a6: rect.right,
        a7: rect.bottom);
    }
    else
    {
      if ( this->m_bIsHoriz != 0 )
      {
        rect.top = (rect.bottom + rect.top) / 2;
        rect.bottom = rect.top + 1;
      }
      else
      {
        rect.left = (rect.right + rect.left) / 2;
        rect.right = rect.left + 1;
        InflateRect(lprc: &rect, dx: 0, dy: -5);
      }
      m_pParentMenu = this->m_pParentMenu;
      if ( m_pParentMenu == nullptr )
        m_pParentMenu = (CMFCRibbonPanelMenuBar *)CMFCRibbonBaseElement::GetTopLevelRibbonBar(this);
      pParentBar = m_pParentMenu;
      if ( m_pParentMenu != nullptr )
      {
        bDisableSideBarInXPMode = 0;
        if ( this->m_bIsDefaultMenuLook != 0 )
        {
          v7 = this->m_pParentMenu;
          if ( v7 != nullptr )
          {
            bDisableSideBarInXPMode = v7->m_bDisableSideBarInXPMode;
            v8 = CMFCVisualManager::GetInstance();
            v9 = v8->GetMenuImageMargin(this: v8);
            rect.left += 2 * v9 + 2;
            this->m_pParentMenu->m_bDisableSideBarInXPMode = 0;
          }
        }
        v10 = CMFCVisualManager::GetInstance();
        ((void (__thiscall *)(CMFCVisualManager *, CDC *, CBasePane *, int, int, int, int, bool))v10->OnDrawSeparator)(
          a1: v10,
          a2: pDC,
          a3: pParentBar,
          a4: rect.left,
          a5: rect.top,
          a6: rect.right,
          a7: rect.bottom,
          a8: this->m_bIsHoriz == 0);
        v11 = this->m_pParentMenu;
        if ( v11 != nullptr )
          v11->m_bDisableSideBarInXPMode = bDisableSideBarInXPMode;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C92A6
// Name: protected: void CMFCRibbonBaseElement::SetDroppedDown(class CMFCPopupMenu __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonBaseElement::SetDroppedDown(CMFCRibbonBaseElement *this, CMFCPopupMenu *pPopupMenu)
{
  int m_bIsDroppedDown; // edx
  int v4; // ecx
  CMFCRibbonPanelMenuBar *m_pParentMenu; // eax
  HWND Parent; // eax

  this->m_pPopupMenu = pPopupMenu;
  if ( pPopupMenu != nullptr )
    CMFCPopupMenu::SetParentRibbonElement(this: pPopupMenu, pElem: this);
  else
    this->NotifyHighlightListItem(this, a2: -1);
  m_bIsDroppedDown = this->m_bIsDroppedDown;
  v4 = pPopupMenu != nullptr;
  this->m_bIsDroppedDown = v4;
  if ( pPopupMenu == nullptr )
  {
    this->m_bIsPressed &= v4;
    this->m_bIsHighlighted &= v4;
  }
  if ( m_bIsDroppedDown != v4 )
    this->Redraw(this);
  m_pParentMenu = this->m_pParentMenu;
  if ( m_pParentMenu != nullptr && m_pParentMenu->m_hWnd != nullptr && pPopupMenu == nullptr )
  {
    Parent = GetParent(hWnd: m_pParentMenu->m_hWnd);
    CMFCPopupMenu::m_pActivePopupMenu = (HWND)CWnd::FromHandle(hWnd: Parent);
  }
  this->m_bOnBeforeShowItemMenuIsSent = 0;
}

//------------------------------------------------------------------------------
// Address: 0x103C932A
// Name: public: virtual void CMFCRibbonBaseElement::Redraw(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonBaseElement::Redraw(CMFCRibbonBaseElement *this)
{
  CRect *p_m_rect; // edi
  CMFCRibbonPanelMenuBar *m_pParentMenu; // eax
  CWnd *v4; // eax
  HWND m_hWnd; // eax

  p_m_rect = &this->m_rect;
  if ( !IsRectEmpty(lprc: &this->m_rect) )
  {
    m_pParentMenu = this->m_pParentMenu;
    if ( m_pParentMenu != nullptr && m_pParentMenu->m_hWnd != nullptr )
    {
      RedrawWindow(hWnd: m_pParentMenu->m_hWnd, lprcUpdate: p_m_rect, hrgnUpdate: nullptr, flags: 0x105u);
    }
    else
    {
      v4 = this->GetParentWnd(this);
      if ( v4 != nullptr )
      {
        m_hWnd = v4->m_hWnd;
        if ( m_hWnd != nullptr )
          RedrawWindow(hWnd: m_hWnd, lprcUpdate: p_m_rect, hrgnUpdate: nullptr, flags: 0x105u);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C937F
// Name: public: int CMFCRibbonBaseElement::NotifyCommand(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonBaseElement::NotifyCommand(CMFCRibbonBaseElement *this, int bWithDelay)
{
  CMFCRibbonBaseElement_vtbl *v3; // eax
  unsigned int v4; // eax
  CMFCRibbonBar *TopLevelRibbonBar; // eax
  HWND Parent; // eax
  CWnd *v7; // ebx
  CMFCRibbonBaseElement_vtbl *v8; // eax
  CMFCRibbonBar *v9; // eax
  CFrameWnd *TopLevelFrame; // eax
  CObject *v11; // esi
  HWND m_hWnd; // [esp-10h] [ebp-54h]
  UINT v14; // [esp-Ch] [ebp-50h]
  WPARAM v15; // [esp-8h] [ebp-4Ch]
  HWND__ *hwndMDIChild; // [esp+Ch] [ebp-38h]
  unsigned int uiID; // [esp+10h] [ebp-34h]
  tagWINDOWPLACEMENT wndpl; // [esp+14h] [ebp-30h] BYREF

  while ( this->m_pOriginal != nullptr )
  {
    if ( this->m_bQuickAccessMode != 0
      && (this->m_bIsHighlighted != 0 || this->m_bIsPressed != 0 || this->m_bIsFocused != 0) )
    {
      v3 = this->__vftable;
      this->m_bIsFocused = 0;
      this->m_bIsPressed = 0;
      this->m_bIsHighlighted = 0;
      v3->Redraw(this);
    }
    this = this->m_pOriginal;
  }
  v4 = this->GetNotifyID(this);
  uiID = v4;
  if ( v4 == 0 )
    return 0;
  if ( v4 == -1 )
    return 0;
  TopLevelRibbonBar = CMFCRibbonBaseElement::GetTopLevelRibbonBar(this);
  if ( TopLevelRibbonBar == nullptr )
    return 0;
  Parent = GetParent(hWnd: TopLevelRibbonBar->m_hWnd);
  v7 = CWnd::FromHandle(hWnd: Parent);
  if ( v7 == nullptr )
    return 0;
  v8 = this->__vftable;
  this->m_bIsFocused = 0;
  this->m_bIsPressed = 0;
  this->m_bIsHighlighted = 0;
  v8->Redraw(this);
  if ( uiID == 65280
    && (hwndMDIChild = (HWND__ *)this->m_dwData, IsWindow(hWnd: hwndMDIChild))
    && (v9 = CMFCRibbonBaseElement::GetTopLevelRibbonBar(this)) != nullptr
    && (TopLevelFrame = CWnd::GetTopLevelFrame(this: v9),
        (v11 = AfxDynamicDownCast(pClass: &CMDIFrameWndEx::classCMDIFrameWndEx, pObject: TopLevelFrame)) != nullptr) )
  {
    wndpl.length = 44;
    GetWindowPlacement(hWnd: hwndMDIChild, lpwndpl: &wndpl);
    if ( wndpl.showCmd == 2 )
      ShowWindow(hWnd: hwndMDIChild, nCmdShow: 9);
    v15 = (WPARAM)hwndMDIChild;
    v14 = 546;
    m_hWnd = (HWND)v11[68].__vftable;
  }
  else
  {
    v15 = uiID;
    v14 = 273;
    m_hWnd = v7->m_hWnd;
  }
  if ( bWithDelay != 0 )
    PostMessageA(hWnd: m_hWnd, Msg: v14, wParam: v15, lParam: 0);
  else
    SendMessageA(hWnd: m_hWnd, Msg: v14, wParam: v15, lParam: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103C94CB
// Name: public: void CMFCRibbonBaseElement::PostMenuCommand(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonBaseElement::PostMenuCommand(CMFCRibbonBaseElement *this, unsigned int __formal)
{
  CMFCRibbonBaseElement_vtbl *v3; // eax
  CMFCRibbonPanelMenuBar *m_pParentMenu; // esi
  HWND Parent; // eax
  CWnd *v6; // eax

  v3 = this->__vftable;
  this->m_bIsDroppedDown = 0;
  ((void (*)(void))v3->Redraw)();
  m_pParentMenu = this->m_pParentMenu;
  if ( m_pParentMenu != nullptr )
  {
    Parent = GetParent(hWnd: m_pParentMenu->m_hWnd);
    v6 = CWnd::FromHandle(hWnd: Parent);
    SendMessageA(hWnd: v6->m_hWnd, Msg: 0x10u, wParam: 0, lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C9508
// Name: public: virtual int CMFCRibbonBaseElement::OnKey(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonBaseElement::OnKey(CMFCRibbonBaseElement *this, int bIsMenuKey)
{
  CMFCRibbonPanel *v4; // eax
  CMFCRibbonPanel *v5; // edi
  CMFCRibbonBar *TopLevelRibbonBar; // edi
  CFrameWnd *v7; // eax
  CFrameWnd *TopLevelFrame; // eax
  CMFCRibbonBar *v9; // eax
  CMFCRibbonPanelMenu *v10; // eax
  CMFCRibbonBaseElement *v11; // eax

  if ( this->m_bIsDisabled != 0 )
    return 0;
  if ( !IsRectEmpty(lprc: &this->m_rect) )
    return CMFCRibbonBaseElement::NotifyCommand(this, bWithDelay: 1);
  v4 = this->GetParentPanel(this);
  v5 = v4;
  if ( v4 == nullptr || CMFCRibbonPanel::IsCollapsed(this: v4) == 0 )
    return 0;
  if ( this->HasMenu(this) == 0 )
  {
    if ( CMFCRibbonBaseElement::NotifyCommand(this, bWithDelay: 1) != 0 )
    {
      if ( this->m_pParentMenu != nullptr )
      {
        TopLevelRibbonBar = CMFCRibbonBaseElement::GetTopLevelRibbonBar(this);
        v7 = AFXGetParentFrame(pWnd: this->m_pParentMenu);
        v7->DestroyWindow(this: v7);
        if ( TopLevelRibbonBar != nullptr && CWnd::GetTopLevelFrame(this: TopLevelRibbonBar) != nullptr )
        {
          TopLevelFrame = CWnd::GetTopLevelFrame(this: TopLevelRibbonBar);
          CWnd::SetFocus(this: TopLevelFrame);
        }
      }
      return 1;
    }
    return 0;
  }
  v9 = CMFCRibbonBaseElement::GetTopLevelRibbonBar(this);
  if ( v9 != nullptr )
    CMFCRibbonBar::HideKeyTips(this: v9);
  v10 = CMFCRibbonPanel::ShowPopup(this: v5, pButton: nullptr);
  if ( v10 == nullptr )
    return 0;
  v11 = CMFCRibbonPanelMenuBar::FindByOrigin(this: &v10->m_wndRibbonBar, pOrigin: this);
  if ( v11 == nullptr )
    return 0;
  return v11->OnKey(this: v11, a2: bIsMenuKey);
}

//------------------------------------------------------------------------------
// Address: 0x103C95F6
// Name: public: virtual void CMFCRibbonBaseElement::NotifyHighlightListItem(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonBaseElement::NotifyHighlightListItem(CMFCRibbonBaseElement *this, WPARAM nIndex)
{
  CMFCRibbonBar *TopLevelRibbonBar; // eax
  HWND Parent; // eax
  CWnd *v5; // eax

  TopLevelRibbonBar = CMFCRibbonBaseElement::GetTopLevelRibbonBar(this);
  if ( TopLevelRibbonBar != nullptr )
  {
    Parent = GetParent(hWnd: TopLevelRibbonBar->m_hWnd);
    v5 = CWnd::FromHandle(hWnd: Parent);
    if ( v5 != nullptr )
      SendMessageA(hWnd: v5->m_hWnd, Msg: AFX_WM_ON_HIGHLIGHT_RIBBON_LIST_ITEM, wParam: nIndex, lParam: (LPARAM)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C9632
// Name: public: virtual void CMFCRibbonBaseElement::OnShowPopupMenu(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonBaseElement::OnShowPopupMenu(CMFCRibbonBaseElement *this)
{
  CMFCRibbonBar *TopLevelRibbonBar; // eax
  HWND Parent; // eax
  CWnd *v4; // eax

  TopLevelRibbonBar = CMFCRibbonBaseElement::GetTopLevelRibbonBar(this);
  if ( TopLevelRibbonBar != nullptr )
  {
    Parent = GetParent(hWnd: TopLevelRibbonBar->m_hWnd);
    v4 = CWnd::FromHandle(hWnd: Parent);
    if ( v4 != nullptr && this->m_bOnBeforeShowItemMenuIsSent == 0 )
    {
      this->m_bOnBeforeShowItemMenuIsSent = 1;
      SendMessageA(hWnd: v4->m_hWnd, Msg: AFX_WM_ON_BEFORE_SHOW_RIBBON_ITEM_MENU, wParam: 0, lParam: (LPARAM)this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C967A
// Name: public: virtual void CMFCRibbonBaseElement::GetElementsByID(unsigned int,class CArray<class CMFCRibbonBaseElement __near *,class CMFCRibbonBaseElement __near *> __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonBaseElement::GetElementsByID(
        CMFCRibbonBaseElement *this,
        unsigned int uiCmdID,
        CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *arElements)
{
  if ( uiCmdID == this->m_nID )
    CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
      this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)arElements,
      nIndex: arElements->m_nSize,
      newElement: (CMFCRibbonKeyTip *)this);
}

//------------------------------------------------------------------------------
// Address: 0x103C9697
// Name: protected: virtual void CMFCRibbonBaseElement::GetItemIDsList(class CList<unsigned int,unsigned int> __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonBaseElement::GetItemIDsList(
        CMFCRibbonBaseElement *this,
        CList<unsigned int,unsigned int> *lstItems)
{
  HWND__ *m_nID; // eax

  m_nID = (HWND__ *)this->m_nID;
  if ( m_nID != nullptr
    && m_nID != (HWND__ *)-1
    && CList<unsigned int,unsigned int>::Find(
         this: (CList<HWND__ *,HWND__ *> *)lstItems,
         searchValue: m_nID,
         startAfter: nullptr) == nullptr )
  {
    CList<CFrameWnd *,CFrameWnd *>::AddTail(
      this: (CList<CFrameWnd *,CFrameWnd *> *)lstItems,
      newElement: (CFrameWnd *)this->m_nID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103C96CA
// Name: public: virtual void CMFCRibbonBaseElement::GetVisibleElements(class CArray<class CMFCRibbonBaseElement __near *,class CMFCRibbonBaseElement __near *> __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonBaseElement::GetVisibleElements(
        CMFCRibbonBaseElement *this,
        CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *> *arElements)
{
  if ( !IsRectEmpty(lprc: &this->m_rect) )
    CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *>::SetAtGrow(
      this: (CArray<CMFCRibbonKeyTip *,CMFCRibbonKeyTip *> *)arElements,
      nIndex: arElements->m_nSize,
      newElement: (CMFCRibbonKeyTip *)this);
}

//------------------------------------------------------------------------------
// Address: 0x103C96F1
// Name: protected: virtual void CMFCRibbonSeparator::OnDrawOnList(class CDC __near *,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,int,class CRect,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonSeparator::OnDrawOnList(
        CMFCRibbonSeparator *this,
        CDC *pDC,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strText,
        int nTextOffset,
        CRect rect,
        int __formal,
        int a7)
{
  int m_bIsDisabled; // ebx

  m_bIsDisabled = this->m_bIsDisabled;
  this->m_bIsDisabled = 0;
  InflateRect(lprc: &rect, dx: -3, dy: 0);
  rect.left += nTextOffset;
  pDC->DrawTextA(this: pDC, a2: strText.m_pszData, a3: *((_DWORD *)strText.m_pszData - 3), a4: &rect, a5: 2084u);
  this->m_bIsDisabled = m_bIsDisabled;
  ATL::CStringData::Release(this: (ATL::CStringData *)strText.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x103C974D
// Name: public: CMFCRibbonBaseElement::CMFCRibbonBaseElement(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonBaseElement *__thiscall CMFCRibbonBaseElement::CMFCRibbonBaseElement(CMFCRibbonBaseElement *this)
{
  CAfxStringMgr *StringManager; // eax
  CAfxStringMgr *v3; // eax
  CAfxStringMgr *v4; // eax
  CAfxStringMgr *v5; // eax
  CAfxStringMgr *v6; // eax

  this->__vftable = (CMFCRibbonBaseElement_vtbl *)&CMFCRibbonBaseElement::`vftable';
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strText, pStringMgr: StringManager);
  v3 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strKeys, pStringMgr: v3);
  v4 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strMenuKeys, pStringMgr: v4);
  v5 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strToolTip, pStringMgr: v5);
  v6 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strDescription, pStringMgr: v6);
  this->m_rect.left = 0;
  this->m_rect.top = 0;
  this->m_rect.right = 0;
  this->m_rect.bottom = 0;
  this->m_Location = RibbonElementNotInGroup;
  this->m_nID = 0;
  this->m_dwData = 0;
  SetRectEmpty(lprc: &this->m_rect);
  this->m_nRow = -1;
  this->m_pParent = nullptr;
  this->m_pParentGroup = nullptr;
  this->m_pParentMenu = nullptr;
  this->m_bCompactMode = 0;
  this->m_bIntermediateMode = 0;
  this->m_bFloatyMode = 0;
  this->m_bQuickAccessMode = 0;
  this->m_bIsHighlighted = 0;
  this->m_bIsFocused = 0;
  this->m_bIsPressed = 0;
  this->m_bIsDisabled = 0;
  this->m_bIsChecked = 0;
  this->m_bIsRadio = 0;
  this->m_bIsDroppedDown = 0;
  this->m_pOriginal = nullptr;
  this->m_pRibbonBar = nullptr;
  this->m_bDontNotify = 0;
  this->m_bTextAlwaysOnRight = 0;
  this->m_pPopupMenu = nullptr;
  this->m_nImageOffset = 0;
  this->m_bShowGroupBorder = 0;
  this->m_bIsDefaultMenuLook = 0;
  this->m_bIsAlwaysLarge = 0;
  this->m_bIsOnPaletteTop = 0;
  this->m_bOnBeforeShowItemMenuIsSent = 0;
  this->m_bIsVisible = 1;
  this->m_bDrawDefaultIcon = 1;
  this->m_bEnableUpdateTooltipInfo = 1;
  this->m_bEnableTooltipInfoShortcut = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103C9843
// Name: protected: virtual class CSize CMFCRibbonGalleryIcon::GetCompactSize(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CMFCRibbonGalleryIcon::GetCompactSize(CMFCRibbonBaseElement *this, CSize *result, CDC *pDC)
{
  this->GetRegularSize(this, result, a3: pDC);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103C985A
// Name: public: virtual class CRect CMFCRibbonBaseElement::GetKeyTipRect(class CDC __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRect *__thiscall CMFCRibbonBaseElement::GetKeyTipRect(
        CMFCRibbonBaseElement *this,
        CRect *result,
        CDC *__formal,
        int a4)
{
  result->left = 0;
  result->top = 0;
  result->right = 0;
  result->bottom = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103C9873
// Name: public: virtual CMFCRibbonBaseElement::~CMFCRibbonBaseElement(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonBaseElement::~CMFCRibbonBaseElement(CMFCRibbonBaseElement *this)
{
  CMFCPopupMenu *m_pPopupMenu; // eax

  this->__vftable = (CMFCRibbonBaseElement_vtbl *)&CMFCRibbonBaseElement::`vftable';
  m_pPopupMenu = this->m_pPopupMenu;
  if ( m_pPopupMenu != nullptr )
  {
    if ( m_pPopupMenu->m_pParentRibbonElement != this )
      AfxThrowInvalidArgException();
    m_pPopupMenu->m_pParentRibbonElement = nullptr;
    CMFCRibbonBaseElement::ClosePopupMenu(this);
  }
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strDescription.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strToolTip.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strMenuKeys.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strKeys.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strText.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x103D20C2
// Name: public: class CMFCRibbonBaseElement __near * CMFCRibbonPanel::GetHighlighted(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonBaseElement *__thiscall CMFCRibbonPanel::GetHighlighted(CMFCRibbonPanel *this)
{
  return this->m_pHighlighted;
}

//------------------------------------------------------------------------------
// Address: 0x103D20C9
// Name: public: class CRect CMFCRibbonPanel::GetGalleryRect(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRect *__thiscall CMFCRibbonPanel::GetGalleryRect(CMFCRibbonPanel *this, CRect *result)
{
  *result = this->m_rect;
  if ( !IsRectEmpty(lprc: &this->m_rectMenuAreaTop) )
    result->top = this->m_rectMenuAreaTop.bottom;
  if ( !IsRectEmpty(lprc: &this->m_rectMenuAreaBottom) )
    result->bottom = this->m_rectMenuAreaBottom.top;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C2A3
// Name: protected: virtual int CMFCRibbonGalleryIcon::IsGalleryIcon(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCRibbonGalleryIcon::IsGalleryIcon(CMFCRibbonGalleryIcon *this)
{
  return this->m_pOwner == nullptr || this->m_pOwner->IsItemMenuLook(this: this->m_pOwner) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1041C2C6
// Name: protected: virtual void CMFCRibbonGalleryIcon::OnDraw(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonGalleryIcon::OnDraw(CMFCRibbonGalleryIcon *this, CDC *pDC)
{
  CMFCRibbonGallery *m_pOwner; // ecx
  unsigned int v4; // eax
  CMFCRibbonGallery *v5; // eax
  CMFCVisualManager *Instance; // eax
  int m_nIndex; // ecx
  bool v8; // zf
  CSize sizeImageDest; // [esp+Ch] [ebp-34h] BYREF
  CMenuImages::IMAGES_IDS id; // [esp+14h] [ebp-2Ch]
  CDC *v11; // [esp+18h] [ebp-28h]
  CRect rectWhite; // [esp+1Ch] [ebp-24h] BYREF
  CRect rectImage; // [esp+2Ch] [ebp-14h] BYREF

  v11 = pDC;
  if ( !IsRectEmpty(lprc: &this->m_rect) )
  {
    if ( this->m_nIndex < 0 )
    {
      Instance = CMFCVisualManager::GetInstance();
      Instance->OnDrawRibbonGalleryButton(this: Instance, a2: pDC, a3: this);
      m_nIndex = this->m_nIndex;
      if ( m_nIndex == -1 )
        id = IdArrowUp;
      else
        id = m_nIndex != -2 ? IdCustomizeArrowDown : IdArrowDown;
      rectImage = this->m_rect;
      if ( m_nIndex == -3 && rectImage.bottom - rectImage.top > rectImage.right - rectImage.left + 2 )
        rectImage.bottom = rectImage.right - rectImage.left + rectImage.top + 2;
      rectWhite = rectImage;
      OffsetRect(lprc: &rectWhite, dx: 0, dy: 1);
      sizeImageDest.cx = 0;
      sizeImageDest.cy = 0;
      CMenuImages::Draw(pDC: v11, id, rectImage: &rectWhite, state: ImageWhite, &sizeImageDest);
      v8 = this->m_bIsDisabled == 0;
      sizeImageDest.cx = 0;
      sizeImageDest.cy = 0;
      CMenuImages::Draw(pDC: v11, id, &rectImage, state: (CMenuImages::IMAGE_STATE)!v8, &sizeImageDest);
    }
    else if ( this->m_pOwner->IsDisabled(this: this->m_pOwner) == 0 )
    {
      m_pOwner = this->m_pOwner;
      v4 = -1;
      if ( m_pOwner->m_bDefaultButtonStyle != 0 || m_pOwner->m_bIsOwnerDraw == 0 )
        v4 = this->OnFillBackground(this, a2: pDC);
      ((void (__thiscall *)(CMFCRibbonGallery *, CDC *, int, int, int, int, int, CMFCRibbonGalleryIcon *, unsigned int))this->m_pOwner->OnDrawPaletteIcon)(
        a1: this->m_pOwner,
        a2: v11,
        a3: this->m_rect.left,
        a4: this->m_rect.top,
        a5: this->m_rect.right,
        a6: this->m_rect.bottom,
        a7: this->m_nIndex,
        a8: this,
        a9: v4);
      v5 = this->m_pOwner;
      if ( v5->m_bDefaultButtonStyle != 0 || v5->m_bIsOwnerDraw == 0 )
        this->OnDrawBorder(this, a2: v11);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041C451
// Name: protected: virtual void CMFCRibbonGalleryIcon::OnLButtonDown(class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonGalleryIcon::OnLButtonDown(CMFCRibbonGalleryIcon *this, CPoint point)
{
  CMFCRibbonGalleryIcon_vtbl *v3; // eax

  if ( this->m_nIndex == -3 )
  {
    v3 = this->__vftable;
    this->m_bIsPressed = 0;
    this->m_bIsHighlighted = 0;
    ((void (*)(void))v3->Redraw)();
    this->m_pOwner->OnShowPopupMenu(this: this->m_pOwner);
  }
  else
  {
    CMFCRibbonButton::OnLButtonDown(this, point);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041C492
// Name: protected: virtual void CMFCRibbonGalleryIcon::CopyFrom(class CMFCRibbonBaseElement const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonGalleryIcon::CopyFrom(CMFCRibbonGalleryIcon *this, const CMFCRibbonBaseElement *s)
{
  CMFCRibbonButton::CopyFrom(this, s);
  this->m_nIndex = (int)s[2].m_strToolTip.m_pszData;
  this->m_pOwner = (CMFCRibbonGallery *)s[2].m_strMenuKeys.m_pszData;
  this->m_bIsChecked = s->m_bIsChecked;
}

//------------------------------------------------------------------------------
// Address: 0x1041C4C8
// Name: protected: virtual class CSize CMFCRibbonGalleryIcon::GetRegularSize(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CMFCRibbonGalleryIcon::GetRegularSize(CMFCRibbonGalleryIcon *this, CSize *result, CDC *__formal)
{
  CMFCRibbonGallery **p_m_pOwner; // esi

  p_m_pOwner = &this->m_pOwner;
  this->m_pOwner->GetIconSize(this: this->m_pOwner, result);
  if ( (*p_m_pOwner)->m_bSmallIcons == 0 )
  {
    result->cx += 8;
    result->cy += 8;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C4FD
// Name: protected: virtual int CMFCRibbonGalleryIcon::IsAutoRepeatMode(int __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCRibbonGalleryIcon::IsAutoRepeatMode(CMFCRibbonGalleryIcon *this, int *__formal)
{
  int m_nIndex; // eax

  m_nIndex = this->m_nIndex;
  return m_nIndex == -1 || m_nIndex == -2;
}

//------------------------------------------------------------------------------
// Address: 0x1041C517
// Name: protected: virtual int CMFCRibbonGalleryIcon::OnAutoRepeat(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonGalleryIcon::OnAutoRepeat(CMFCRibbonGalleryIcon *this)
{
  if ( this->m_bIsDisabled != 0 )
    return 0;
  this->m_pOwner->OnClickPaletteIcon(this: this->m_pOwner, a2: this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1041C535
// Name: protected: virtual int CMFCRibbonGalleryIcon::OnAddToQAToolbar(class CMFCRibbonQuickAccessToolBar __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonGalleryIcon::OnAddToQAToolbar(CMFCRibbonGalleryIcon *this, CMFCRibbonQuickAccessToolBar *qat)
{
  this->m_pOwner->OnAddToQAToolbar(this: this->m_pOwner, a2: qat);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1041C552
// Name: public: virtual struct CRuntimeClass __near * CMFCRibbonGallery::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCRibbonGallery::GetRuntimeClass(CMFCRibbonGallery *this)
{
  return &CMFCRibbonGallery::classCMFCRibbonGallery;
}

//------------------------------------------------------------------------------
// Address: 0x1041C558
// Name: public: void CMFCRibbonGallery::AddSubItem(class CMFCRibbonBaseElement __near *,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonGallery::AddSubItem(
        CMFCRibbonGallery *this,
        CMFCRibbonBaseElement *pSubItem,
        int nIndex,
        int bOnTop)
{
  pSubItem->m_bIsOnPaletteTop = bOnTop;
  CMFCRibbonButton::AddSubItem(this, pSubItem, nIndex);
}

//------------------------------------------------------------------------------
// Address: 0x1041C576
// Name: protected: void CMFCRibbonGallery::CommonInit(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonGallery::CommonInit(CMFCRibbonGallery *this)
{
  this->m_nIconsInRow = -1;
  this->m_bIsDefaultCommand = 0;
  this->m_bIsButtonMode = 0;
  this->m_nImagesInRow = 0;
  this->m_nImagesInColumn = 0;
  this->m_bSmallIcons = 0;
  this->m_nScrollOffset = 0;
  this->m_nScrollTotal = 0;
  this->m_nSelected = 0;
  this->m_bEnableMenuResize = 0;
  this->m_bMenuResizeVertical = 0;
  this->m_nPaletteID = 0;
  this->m_bNotifyPaletteID = 0;
  this->m_nPanelColumns = 6;
  this->m_bIsOwnerDraw = 0;
  this->m_bDefaultButtonStyle = 1;
  this->m_bMenuSideBar = 0;
  this->m_bIsCollapsed = 0;
  this->m_nIcons = 0;
  this->m_bResetColumns = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1041C5FA
// Name: public: virtual class CSize CMFCRibbonGallery::GetCompactSize(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CMFCRibbonGallery::GetCompactSize(CMFCRibbonGallery *this, CSize *result, CDC *pDC)
{
  if ( CMFCRibbonGallery::IsButtonLook(this) != 0 )
    CMFCRibbonButton::GetCompactSize(this, result, __formal: pDC);
  else
    CMFCRibbonButton::GetRegularSize(this, result, pDC);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C627
// Name: protected: virtual void CMFCRibbonGallery::OnDrawPaletteIcon(class CDC __near *,class CRect,int,class CMFCRibbonGalleryIcon __near *,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonGallery::OnDrawPaletteIcon(
        CMFCRibbonGallery *this,
        CDC *pDC,
        CRect rectIcon,
        int nIconIndex,
        CMFCRibbonGalleryIcon *__formal,
        unsigned int a6)
{
  int v7; // eax

  if ( this->m_bIsOwnerDraw == 0 )
  {
    if ( this->m_bSmallIcons == 0 )
      InflateRect(lprc: &rectIcon, dx: -4, dy: -4);
    v7 = this->IsDisabled(this);
    CMFCToolBarImages::Draw(
      this: &this->m_imagesPalette,
      pDCDest: pDC,
      xDest: rectIcon.left,
      yDest: rectIcon.top,
      iImage: nIconIndex,
      bHilite: 0,
      bDisabled: v7,
      bIndeterminate: 0,
      bShadow: 0,
      bInactive: 0,
      alphaSrc: 0xFFu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041C681
// Name: protected: int CMFCRibbonGallery::GetMenuRowHeight(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMFCRibbonGallery::GetMenuRowHeight(CMFCRibbonGallery *this)
{
  unsigned int v1; // esi
  CSize sizeImage; // [esp+4h] [ebp-8h] BYREF

  v1 = this->m_bSmallIcons != 0 ? 0xFFFFFFFC : 0;
  ((void (__stdcall *)(CSize *))this->GetIconSize)(a1: &sizeImage);
  return sizeImage.cy + 2 * v1 + 8;
}

//------------------------------------------------------------------------------
// Address: 0x1041C6AC
// Name: protected: void CMFCRibbonGallery::SetNotifyParentID(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonGallery::SetNotifyParentID(CMFCRibbonGallery *this, CObject_vtbl *bSet)
{
  CMFCRibbonBaseElement *m_pOriginal; // ecx
  CObject *v3; // eax

  this->m_bNotifyPaletteID = (int)bSet;
  m_pOriginal = this->m_pOriginal;
  if ( m_pOriginal != nullptr )
  {
    v3 = AfxDynamicDownCast(pClass: &CMFCRibbonGallery::classCMFCRibbonGallery, pObject: m_pOriginal);
    if ( v3 != nullptr )
      v3[186].__vftable = bSet;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041C6DE
// Name: protected: virtual int CMFCRibbonGallery::OnKey(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonGallery::OnKey(CMFCRibbonGallery *this, int __formal)
{
  return CMFCRibbonButton::OnKey(this, bIsMenuKey: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1041C6E8
// Name: protected: virtual class CSize CMFCRibbonGallery::GetIconSize(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CMFCRibbonGallery::GetIconSize(CMFCRibbonGallery *this, CSize *result)
{
  int cx; // edx
  int cy; // ecx

  cx = this->m_imagesPalette.m_sizeImage.cx;
  cy = this->m_imagesPalette.m_sizeImage.cy;
  result->cx = cx;
  result->cy = cy;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C705
// Name: public: virtual void CMFCRibbonGallery::OnRTLChanged(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonGallery::OnRTLChanged(CMFCRibbonGallery *this, int bIsRTL)
{
  CMFCToolBarImages::Mirror(this: &this->m_imagesPalette);
}

//------------------------------------------------------------------------------
// Address: 0x1041C713
// Name: public: static class CObject __near * CMFCRibbonGalleryIcon::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonGalleryIcon *__stdcall CMFCRibbonGalleryIcon::CreateObject()
{
  CMFCRibbonGalleryIcon *v0; // ecx
  CMFCRibbonGalleryIcon *result; // eax

  v0 = (CMFCRibbonGalleryIcon *)operator new(nSize: 0x17Cu);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCRibbonGalleryIcon::CMFCRibbonGalleryIcon(this: v0, pOwner: nullptr, nIndex: 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C745
// Name: protected: virtual void CMFCRibbonGalleryIcon::OnClick(class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonGalleryIcon::OnClick(CMFCRibbonGalleryIcon *this, CPoint point)
{
  CMFCRibbonGalleryIcon *m_pOriginal; // eax
  CMFCRibbonPanelMenuBar *m_pParentMenu; // edi
  CMFCRibbonGallery *v5; // ecx
  CMFCRibbonGallery *m_pOwner; // ecx

  m_pOriginal = (CMFCRibbonGalleryIcon *)this->m_pOriginal;
  if ( m_pOriginal == nullptr )
    m_pOriginal = this;
  this->m_pOwner->OnClickPaletteIcon(this: this->m_pOwner, a2: m_pOriginal);
  if ( this->m_nIndex >= 0 )
  {
    m_pParentMenu = this->m_pParentMenu;
    if ( m_pParentMenu != nullptr || (v5 = this->m_pOwner, (m_pParentMenu = v5->m_pParentMenu) != nullptr) )
    {
      m_pOwner = this->m_pOwner;
      if ( m_pOwner->m_nPaletteID != 0 )
        CMFCRibbonGallery::SetNotifyParentID(this: m_pOwner, bSet: (CObject_vtbl *)1);
      this->m_pOwner->m_bIsFocused = 0;
      this->m_pOwner->OnSetFocus(this: this->m_pOwner, a2: 0);
      ((void (__thiscall *)(CMFCRibbonPanelMenuBar *, CMFCRibbonGallery *, int, int))m_pParentMenu->OnClickButton)(
        a1: m_pParentMenu,
        a2: this->m_pOwner,
        a3: point.x,
        a4: point.y);
    }
    else
    {
      CMFCRibbonBaseElement::NotifyCommand(this: v5, bWithDelay: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041C7D7
// Name: protected: virtual void CMFCRibbonGalleryIcon::OnHighlight(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CMFCRibbonGalleryIcon::OnHighlight(CMFCRibbonGalleryIcon *this@<ecx>, int a2@<esi>, int bHighlight)
{
  CMFCRibbonPanelMenuBar *m_pParentMenu; // eax
  CMFCRibbonPanel *v5; // eax
  CObject *v6; // eax
  CObject *v7; // eax
  int v8; // eax
  CObject *v9; // eax
  int m_nIndex; // eax
  CPoint ptCursor; // [esp+8h] [ebp-8h] BYREF

  if ( bHighlight == 0 )
  {
    ptCursor.x = 0;
    ptCursor.y = 0;
    GetCursorPos(lpPoint: &ptCursor);
    m_pParentMenu = this->m_pParentMenu;
    if ( m_pParentMenu == nullptr )
    {
      v8 = ((int (__thiscall *)(CMFCRibbonGallery *, int))this->m_pOwner->GetParentWnd)(a1: this->m_pOwner, a2);
      ScreenToClient(hWnd: *(HWND *)(v8 + 32), lpPoint: &ptCursor);
      v9 = (CObject *)((int (__thiscall *)(CMFCRibbonGallery *, int, int))this->m_pOwner->HitTest)(
                        a1: this->m_pOwner,
                        a2: ptCursor.x,
                        a3: ptCursor.y);
      v7 = AfxDynamicDownCast(pClass: &CMFCRibbonGalleryIcon::classCMFCRibbonGalleryIcon, pObject: v9);
      goto LABEL_6;
    }
    ScreenToClient(hWnd: m_pParentMenu->m_hWnd, lpPoint: &ptCursor);
    v5 = this->GetParentPanel(this);
    if ( v5 != nullptr )
    {
      v6 = (CObject *)((int (__thiscall *)(CMFCRibbonPanel *, int, int, _DWORD))v5->HitTest)(
                        a1: v5,
                        a2: ptCursor.x,
                        a3: ptCursor.y,
                        a4: 0);
      v7 = AfxDynamicDownCast(pClass: &CMFCRibbonGalleryIcon::classCMFCRibbonGalleryIcon, pObject: v6);
LABEL_6:
      if ( v7 != nullptr && (int)v7[90].__vftable >= 0 )
        return;
    }
  }
  m_nIndex = this->m_nIndex;
  if ( m_nIndex >= 0 )
  {
    if ( bHighlight == 0 )
      m_nIndex = -1;
    this->m_pOwner->NotifyHighlightListItem(this: this->m_pOwner, a2: m_nIndex);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041C8AD
// Name: public: CMFCRibbonGallery::CMFCRibbonGallery(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonGallery *__thiscall CMFCRibbonGallery::CMFCRibbonGallery(CMFCRibbonGallery *this)
{
  CMFCRibbonButton::CMFCRibbonButton(this);
  this->__vftable = (CMFCRibbonGallery_vtbl *)&CMFCRibbonGallery::`vftable';
  this->m_arIcons.__vftable = (CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>_vtbl *)&CArray<CMFCRibbonBaseElement *,CMFCRibbonBaseElement *>::`vftable';
  this->m_arIcons.m_pData = nullptr;
  this->m_arIcons.m_nGrowBy = 0;
  this->m_arIcons.m_nMaxSize = 0;
  this->m_arIcons.m_nSize = 0;
  CStringArray::CStringArray(this: &this->m_arGroupNames);
  this->m_arGroupLen.__vftable = (CArray<int,int>_vtbl *)&CArray<int,int>::`vftable';
  this->m_arGroupLen.m_pData = nullptr;
  this->m_arGroupLen.m_nGrowBy = 0;
  this->m_arGroupLen.m_nMaxSize = 0;
  this->m_arGroupLen.m_nSize = 0;
  CMFCToolBarImages::CMFCToolBarImages(this: &this->m_imagesPalette);
  CStringArray::CStringArray(this: &this->m_arToolTips);
  CMFCRibbonGallery::CommonInit(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1041C94E
// Name: public: virtual int CMFCRibbonGallery::SetACCData(class CWnd __near *,class CAccessibilityData __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonGallery::SetACCData(CMFCRibbonGallery *this, CWnd *pParent, CAccessibilityData *data)
{
  CMFCRibbonButton::SetACCData(this, pParent, data);
  data->m_nAccRole = this->IsCommandAreaHighlighted(this) != 0 ? 62 : 58;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1041C983
// Name: protected: virtual int CMFCRibbonGallery::CanBeStretchedHorizontally(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCRibbonGallery::CanBeStretchedHorizontally(CMFCRibbonGallery *this)
{
  BOOL result; // eax

  result = false;
  if ( this->m_bIsButtonMode == 0 )
    return this->m_bIsCollapsed == 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041C997
// Name: protected: virtual void CMFCRibbonGallery::SetInitialMode(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonGallery::SetInitialMode(CMFCRibbonGallery *this, int bOneRow)
{
  CMFCRibbonBaseElement::SetInitialMode(this, bOneRow);
  this->m_bIsCollapsed = 0;
  this->m_bResetColumns = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1041C9BD
// Name: protected: virtual void CMFCRibbonGallery::StretchHorizontally(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonGallery::StretchHorizontally(CMFCRibbonGallery *this)
{
  int m_nPanelColumns; // edx

  if ( this->m_bSmallIcons != 0 || (m_nPanelColumns = this->m_nPanelColumns) <= 3 )
    this->m_bIsCollapsed = 1;
  else
    this->m_nPanelColumns = m_nPanelColumns - 1;
}
