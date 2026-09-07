// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/vgui/scrollingwindow.cpp
// Functions: 13
// ============================================================

#include "missionchooser\vgui\scrollingwindow.h"

//------------------------------------------------------------------------------
// Address: 0x1002BB90
// Name: public: static char const __near * CScrollingWindow::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CScrollingWindow::GetPanelClassName()
{
  return "CScrollingWindow";
}

//------------------------------------------------------------------------------
// Address: 0x1002BBC0
// Name: public: void CScrollingWindow::MoveToTopLeft(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScrollingWindow::MoveToTopLeft(CScrollingWindow *this)
{
  vgui::ScrollBarSlider *v2; // eax
  vgui::ScrollBarSlider *v3; // eax
  vgui::ScrollBarSlider *v4; // eax
  vgui::ScrollBarSlider *v5; // eax
  int hmax; // [esp+4h] [ebp-8h] BYREF
  int hmin; // [esp+8h] [ebp-4h] BYREF

  this->m_pHorizScrollbar->GetRange(this: this->m_pHorizScrollbar, a2: &hmin, a3: &hmax);
  this->m_pHorizScrollbar->SetValue(this: this->m_pHorizScrollbar, a2: hmin);
  this->m_pVertScrollbar->GetRange(this: this->m_pVertScrollbar, a2: &hmin, a3: &hmax);
  this->m_pVertScrollbar->SetValue(this: this->m_pVertScrollbar, a2: hmin);
  this->InvalidateLayout(this, a2: false, a3: false);
  this->m_pHorizScrollbar->InvalidateLayout(this: this->m_pHorizScrollbar, a2: false, a3: false);
  v2 = this->m_pHorizScrollbar->GetSlider(this: this->m_pHorizScrollbar);
  v2->InvalidateLayout(this: v2, a2: false, a3: false);
  this->m_pVertScrollbar->InvalidateLayout(this: this->m_pVertScrollbar, a2: false, a3: false);
  v3 = this->m_pVertScrollbar->GetSlider(this: this->m_pVertScrollbar);
  v3->InvalidateLayout(this: v3, a2: false, a3: false);
  this->Repaint(this);
  this->m_pHorizScrollbar->Repaint(this: this->m_pHorizScrollbar);
  v4 = this->m_pHorizScrollbar->GetSlider(this: this->m_pHorizScrollbar);
  v4->Repaint(this: v4);
  this->m_pVertScrollbar->Repaint(this: this->m_pVertScrollbar);
  v5 = this->m_pVertScrollbar->GetSlider(this: this->m_pVertScrollbar);
  v5->Repaint(this: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1002BD00
// Name: public: void CScrollingWindow::MoveToLowerCenter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScrollingWindow::MoveToLowerCenter(CScrollingWindow *this)
{
  vgui::ScrollBar *m_pHorizScrollbar; // ecx
  vgui::ScrollBar_vtbl *v3; // edi
  int v4; // eax
  vgui::ScrollBar *m_pVertScrollbar; // ecx
  vgui::ScrollBar_vtbl *v6; // edi
  int v7; // eax
  float v8; // [esp+8h] [ebp-Ch]
  int hmin; // [esp+Ch] [ebp-8h] BYREF
  int hmax; // [esp+10h] [ebp-4h] BYREF

  this->m_pHorizScrollbar->GetRange(this: this->m_pHorizScrollbar, a2: &hmin, a3: &hmax);
  m_pHorizScrollbar = this->m_pHorizScrollbar;
  v3 = m_pHorizScrollbar->__vftable;
  v8 = (float)((float)(hmax - hmin) * 0.5) + (float)hmin;
  v4 = m_pHorizScrollbar->GetRangeWindow(this: m_pHorizScrollbar);
  v3->SetValue(this: this->m_pHorizScrollbar, a2: (int)(float)(v8 - (float)((float)v4 * 0.5)));
  this->m_pVertScrollbar->GetRange(this: this->m_pVertScrollbar, a2: &hmin, a3: &hmax);
  m_pVertScrollbar = this->m_pVertScrollbar;
  v6 = m_pVertScrollbar->__vftable;
  v7 = ((int (*)(void))m_pVertScrollbar->GetRangeWindow)();
  v6->SetValue(this: this->m_pVertScrollbar, a2: hmax - 2 * v7);
}

//------------------------------------------------------------------------------
// Address: 0x1002BDD0
// Name: public: virtual void CScrollingWindow::OnMouseWheeled(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScrollingWindow::OnMouseWheeled(CScrollingWindow *this, int delta)
{
  int v3; // eax

  v3 = this->m_pVertScrollbar->GetValue(this: this->m_pVertScrollbar);
  this->m_pVertScrollbar->SetValue(this: this->m_pVertScrollbar, a2: v3 - 30 * delta);
}

//------------------------------------------------------------------------------
// Address: 0x1002BE10
// Name: public: virtual struct vgui::PanelMessageMap __near * CScrollingWindow::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CScrollingWindow::GetMessageMap(CScrollingWindow *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CScrollingWindow::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CScrollingWindow::GetMessageMap'::`2'::s_pMap;
  `CScrollingWindow::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CScrollingWindow");
  `CScrollingWindow::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002BE40
// Name: public: virtual struct PanelAnimationMap __near * CScrollingWindow::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CScrollingWindow::GetAnimMap(CScrollingWindow *this)
{
  return FindOrAddPanelAnimationMap(className: "CScrollingWindow");
}

//------------------------------------------------------------------------------
// Address: 0x1002BE50
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CScrollingWindow::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CScrollingWindow::GetKBMap(CScrollingWindow *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CScrollingWindow::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CScrollingWindow::GetKBMap'::`2'::s_pMap;
  `CScrollingWindow::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CScrollingWindow");
  `CScrollingWindow::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002BEB0
// Name: public: virtual void CScrollingWindow::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScrollingWindow::PerformLayout(CScrollingWindow *this)
{
  int Wide; // eax
  int Tall; // eax
  int v4; // eax
  vgui::Panel *v5; // eax
  int v6; // ebx
  vgui::Panel *v7; // eax
  vgui::ScrollBar_vtbl *v8; // ebx
  vgui::ScrollBar_vtbl *v9; // ebx
  int v10; // eax
  vgui::ScrollBar_vtbl *v11; // ebx
  int v12; // eax
  vgui::ScrollBar_vtbl *v13; // ebx
  int v14; // eax
  vgui::Panel *v15; // eax
  vgui::ScrollBar *m_pHorizScrollbar; // edi
  vgui::Panel *v17; // ebx
  int v18; // eax
  int v19; // eax
  int v20; // [esp-8h] [ebp-20h]
  int v21; // [esp-8h] [ebp-20h]
  int v22; // [esp-4h] [ebp-1Ch]
  int v23; // [esp-4h] [ebp-1Ch]
  int cw; // [esp+8h] [ebp-10h]
  int ct; // [esp+Ch] [ebp-Ch]
  int yrange; // [esp+10h] [ebp-8h]
  int xrange; // [esp+14h] [ebp-4h]

  vgui::Panel::PerformLayout(this);
  v22 = vgui::Panel::GetTall(this) - 30;
  Wide = vgui::Panel::GetWide(this);
  vgui::Panel::SetBounds(this: this->m_pVertScrollbar, x: Wide - 20, y: 0, wide: 20, tall: v22);
  v20 = vgui::Panel::GetWide(this) - 30;
  Tall = vgui::Panel::GetTall(this);
  vgui::Panel::SetBounds(this: this->m_pHorizScrollbar, x: 0, y: Tall - 20, wide: v20, tall: 20);
  v23 = vgui::Panel::GetTall(this) - 30;
  v4 = vgui::Panel::GetWide(this);
  vgui::Panel::SetBounds(this: this->m_pView, x: 0, y: 0, wide: v4 - 30, tall: v23);
  if ( vgui::PHandle::Get(this: &this->m_hChildPanel) != nullptr )
  {
    v5 = vgui::PHandle::Get(this: &this->m_hChildPanel);
    v6 = vgui::Panel::GetWide(this: v5);
    cw = v6;
    v7 = vgui::PHandle::Get(this: &this->m_hChildPanel);
    ct = vgui::Panel::GetTall(this: v7);
    if ( v6 - vgui::Panel::GetWide(this: this->m_pView) >= 0 )
      xrange = v6 - vgui::Panel::GetWide(this: this->m_pView);
    else
      xrange = 0;
    if ( ct - vgui::Panel::GetTall(this: this->m_pView) >= 0 )
      yrange = ct - vgui::Panel::GetTall(this: this->m_pView);
    else
      yrange = 0;
    v8 = this->m_pHorizScrollbar->__vftable;
    v21 = xrange + vgui::Panel::GetWide(this: this->m_pView);
    ((void (__thiscall *)(vgui::ScrollBar *, _DWORD))v8->SetRange)(a1: this->m_pHorizScrollbar, a2: 0);
    v9 = this->m_pHorizScrollbar->__vftable;
    v10 = vgui::Panel::GetWide(this: this->m_pView);
    v9->SetRangeWindow(this: this->m_pHorizScrollbar, a2: v10);
    v11 = this->m_pVertScrollbar->__vftable;
    v12 = vgui::Panel::GetTall(this: this->m_pView);
    v11->SetRange(this: this->m_pVertScrollbar, a2: 0, a3: yrange + v12);
    v13 = this->m_pVertScrollbar->__vftable;
    v14 = vgui::Panel::GetTall(this: this->m_pView);
    v13->SetRangeWindow(this: this->m_pVertScrollbar, a2: v14);
    v15 = vgui::PHandle::Get(this: &this->m_hChildPanel);
    m_pHorizScrollbar = this->m_pHorizScrollbar;
    v17 = v15;
    v18 = this->m_pVertScrollbar->GetValue(this: this->m_pVertScrollbar);
    v19 = ((int (__thiscall *)(vgui::ScrollBar *, int))m_pHorizScrollbar->GetValue)(a1: m_pHorizScrollbar, a2: -v18);
    vgui::Panel::SetPos(this: v17, x: -v19, y: v21);
    this->m_iChildTall = cw;
    this->m_iChildWide = ct;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C0B0
// Name: public: virtual void CScrollingWindow::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScrollingWindow::ApplySchemeSettings(CScrollingWindow *this, vgui::IScheme *pScheme)
{
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  this->m_pView->SetPaintBackgroundEnabled(this: this->m_pView, a2: true);
  this->m_pView->SetPaintBackgroundType(this: this->m_pView, a2: 0);
  ((void (__thiscall *)(vgui::Panel *, int))this->m_pView->SetBgColor)(a1: this->m_pView, a2: -16777216);
}

//------------------------------------------------------------------------------
// Address: 0x1002C110
// Name: public: virtual void CScrollingWindow::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScrollingWindow::OnThink(CScrollingWindow *this)
{
  vgui::Panel *v2; // eax
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax

  vgui::Panel::OnThink(this);
  if ( vgui::PHandle::Get(this: &this->m_hChildPanel) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &this->m_hChildPanel);
    if ( vgui::Panel::GetTall(this: v2) != this->m_iChildTall
      || (v3 = vgui::PHandle::Get(this: &this->m_hChildPanel), vgui::Panel::GetWide(this: v3) != this->m_iChildWide) )
    {
      this->InvalidateLayout(this, a2: true, a3: false);
      v4 = vgui::PHandle::Get(this: &this->m_hChildPanel);
      this->m_iChildTall = vgui::Panel::GetTall(this: v4);
      v5 = vgui::PHandle::Get(this: &this->m_hChildPanel);
      this->m_iChildWide = vgui::Panel::GetWide(this: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C1A0
// Name: public: void CScrollingWindow::SetChildPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScrollingWindow::SetChildPanel(CScrollingWindow *this, vgui::Panel *pPanel)
{
  if ( pPanel != nullptr )
  {
    if ( pPanel != vgui::PHandle::Get(this: &this->m_hChildPanel) )
    {
      this->m_iChildTall = 0;
      this->m_iChildWide = 0;
    }
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hChildPanel, pPanel);
    pPanel->SetParent_2(this: pPanel, a2: this->m_pView);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C200
// Name: public: static void CScrollingWindow::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CScrollingWindow::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CScrollingWindow::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `CScrollingWindow::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{844,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CScrollingWindow");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "ScrollBarSliderMoved";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "position";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002C2A0
// Name: public: CScrollingWindow::CScrollingWindow(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CScrollingWindow *__thiscall CScrollingWindow::CScrollingWindow(
        CScrollingWindow *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::ScrollBar *v9; // eax
  vgui::ScrollBar *v10; // eax
  vgui::ScrollBar *v11; // eax
  vgui::ScrollBar *v12; // eax
  vgui::ScrollBar *m_pVertScrollbar; // ecx
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (CScrollingWindow_vtbl *)&CScrollingWindow::`vftable';
  if ( `CScrollingWindow::ChainToMap'::`2'::chained == 0 )
  {
    `CScrollingWindow::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CScrollingWindow");
    v4->pfnClassName = CScrollingWindow::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CScrollingWindow::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CScrollingWindow::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CScrollingWindow");
    v5->pfnClassName = CScrollingWindow::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CScrollingWindow::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CScrollingWindow::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CScrollingWindow");
    v6->pfnClassName = CScrollingWindow::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  CScrollingWindow::PanelMessageFunc_OnSliderMoved::InitVar(a1: (int)&savedregs);
  this->m_hChildPanel.m_iPanelID = -1;
  v7 = (vgui::Panel *)operator new(nSize: 0x14Cu);
  if ( v7 != nullptr )
    v8 = vgui::Panel::Panel(this: v7, parent: this, panelName: "View");
  else
    v8 = nullptr;
  this->m_pView = v8;
  v9 = (vgui::ScrollBar *)operator new(nSize: 0x17Cu);
  if ( v9 != nullptr )
    v10 = vgui::ScrollBar::ScrollBar(this: v9, parent: this, panelName: "VertScrollbar", vertical: true);
  else
    v10 = nullptr;
  this->m_pVertScrollbar = v10;
  v11 = (vgui::ScrollBar *)operator new(nSize: 0x17Cu);
  if ( v11 != nullptr )
    v12 = vgui::ScrollBar::ScrollBar(this: v11, parent: this, panelName: "HorizScrollbar", vertical: false);
  else
    v12 = nullptr;
  m_pVertScrollbar = this->m_pVertScrollbar;
  this->m_pHorizScrollbar = v12;
  m_pVertScrollbar->SetButtonPressedScrollValue(this: m_pVertScrollbar, a2: 160);
  this->m_pHorizScrollbar->SetButtonPressedScrollValue(this: this->m_pHorizScrollbar, a2: 160);
  this->m_pHorizScrollbar->AddActionSignalTarget_2(this: this->m_pHorizScrollbar, a2: this);
  this->m_pVertScrollbar->SetValue(this: this->m_pVertScrollbar, a2: 0);
  this->m_pHorizScrollbar->SetValue(this: this->m_pHorizScrollbar, a2: 0);
  this->m_pVertScrollbar->AddActionSignalTarget_2(this: this->m_pVertScrollbar, a2: this);
  this->m_iChildTall = 0;
  this->m_iChildWide = 0;
  return this;
}

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x004096D0
// Name: public: static char const __near * CScrollingWindow::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CScrollingWindow::GetPanelClassName()
{
  return "CScrollingWindow";
}

//------------------------------------------------------------------------------
// Address: 0x00409700
// Name: public: virtual void CScrollingWindow::OnMouseWheeled(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScrollingWindow::OnMouseWheeled(CScrollingWindow *this, int delta)
{
  int v3; // eax

  v3 = this->m_pVertScrollbar->GetValue(this: this->m_pVertScrollbar);
  this->m_pVertScrollbar->SetValue(this: this->m_pVertScrollbar, a2: v3 - 30 * delta);
}

//------------------------------------------------------------------------------
// Address: 0x00409750
// Name: public: virtual struct vgui::PanelMessageMap __near * CScrollingWindow::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CScrollingWindow::GetMessageMap(CScrollingWindow *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CScrollingWindow::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CScrollingWindow::GetMessageMap'::`2'::s_pMap;
  `CScrollingWindow::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CScrollingWindow");
  `CScrollingWindow::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00409780
// Name: public: virtual struct PanelAnimationMap __near * CScrollingWindow::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CScrollingWindow::GetAnimMap(CScrollingWindow *this)
{
  return FindOrAddPanelAnimationMap(className: "CScrollingWindow");
}

//------------------------------------------------------------------------------
// Address: 0x00409790
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CScrollingWindow::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CScrollingWindow::GetKBMap(CScrollingWindow *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CScrollingWindow::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CScrollingWindow::GetKBMap'::`2'::s_pMap;
  `CScrollingWindow::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CScrollingWindow");
  `CScrollingWindow::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004097F0
// Name: public: virtual void CScrollingWindow::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScrollingWindow::PerformLayout(CScrollingWindow *this)
{
  int Wide; // eax
  int Tall; // eax
  int v4; // eax
  vgui::Panel *v5; // eax
  int v6; // ebx
  vgui::Panel *v7; // eax
  vgui::ScrollBar_vtbl *v8; // ebx
  vgui::ScrollBar_vtbl *v9; // ebx
  int v10; // eax
  vgui::ScrollBar_vtbl *v11; // ebx
  int v12; // eax
  vgui::ScrollBar_vtbl *v13; // ebx
  int v14; // eax
  vgui::Panel *v15; // eax
  vgui::ScrollBar *m_pHorizScrollbar; // edi
  vgui::Panel *v17; // ebx
  int v18; // eax
  int v19; // eax
  int v20; // [esp-8h] [ebp-20h]
  int v21; // [esp-8h] [ebp-20h]
  int v22; // [esp-4h] [ebp-1Ch]
  int v23; // [esp-4h] [ebp-1Ch]
  int cw; // [esp+8h] [ebp-10h]
  int ct; // [esp+Ch] [ebp-Ch]
  int yrange; // [esp+10h] [ebp-8h]
  int xrange; // [esp+14h] [ebp-4h]

  vgui::Panel::PerformLayout(this);
  v22 = vgui::Panel::GetTall(this) - 30;
  Wide = vgui::Panel::GetWide(this);
  vgui::Panel::SetBounds(this: this->m_pVertScrollbar, x: Wide - 20, y: 0, wide: 20, tall: v22);
  v20 = vgui::Panel::GetWide(this) - 30;
  Tall = vgui::Panel::GetTall(this);
  vgui::Panel::SetBounds(this: this->m_pHorizScrollbar, x: 0, y: Tall - 20, wide: v20, tall: 20);
  v23 = vgui::Panel::GetTall(this) - 30;
  v4 = vgui::Panel::GetWide(this);
  vgui::Panel::SetBounds(this: this->m_pView, x: 0, y: 0, wide: v4 - 30, tall: v23);
  if ( vgui::PHandle::Get(this: &this->m_hChildPanel) != nullptr )
  {
    v5 = vgui::PHandle::Get(this: &this->m_hChildPanel);
    v6 = vgui::Panel::GetWide(this: v5);
    cw = v6;
    v7 = vgui::PHandle::Get(this: &this->m_hChildPanel);
    ct = vgui::Panel::GetTall(this: v7);
    if ( v6 - vgui::Panel::GetWide(this: this->m_pView) >= 0 )
      xrange = v6 - vgui::Panel::GetWide(this: this->m_pView);
    else
      xrange = 0;
    if ( ct - vgui::Panel::GetTall(this: this->m_pView) >= 0 )
      yrange = ct - vgui::Panel::GetTall(this: this->m_pView);
    else
      yrange = 0;
    v8 = this->m_pHorizScrollbar->__vftable;
    v21 = xrange + vgui::Panel::GetWide(this: this->m_pView);
    ((void (__thiscall *)(vgui::ScrollBar *, _DWORD))v8->SetRange)(a1: this->m_pHorizScrollbar, a2: 0);
    v9 = this->m_pHorizScrollbar->__vftable;
    v10 = vgui::Panel::GetWide(this: this->m_pView);
    v9->SetRangeWindow(this: this->m_pHorizScrollbar, a2: v10);
    v11 = this->m_pVertScrollbar->__vftable;
    v12 = vgui::Panel::GetTall(this: this->m_pView);
    v11->SetRange(this: this->m_pVertScrollbar, a2: 0, a3: yrange + v12);
    v13 = this->m_pVertScrollbar->__vftable;
    v14 = vgui::Panel::GetTall(this: this->m_pView);
    v13->SetRangeWindow(this: this->m_pVertScrollbar, a2: v14);
    v15 = vgui::PHandle::Get(this: &this->m_hChildPanel);
    m_pHorizScrollbar = this->m_pHorizScrollbar;
    v17 = v15;
    v18 = this->m_pVertScrollbar->GetValue(this: this->m_pVertScrollbar);
    v19 = ((int (__thiscall *)(vgui::ScrollBar *, int))m_pHorizScrollbar->GetValue)(a1: m_pHorizScrollbar, a2: -v18);
    vgui::Panel::SetPos(this: v17, x: -v19, y: v21);
    this->m_iChildTall = cw;
    this->m_iChildWide = ct;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004099F0
// Name: public: virtual void CScrollingWindow::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScrollingWindow::ApplySchemeSettings(CScrollingWindow *this, vgui::IScheme *pScheme)
{
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  this->m_pView->SetPaintBackgroundEnabled(this: this->m_pView, a2: true);
  this->m_pView->SetPaintBackgroundType(this: this->m_pView, a2: 0);
  ((void (__thiscall *)(vgui::Panel *, int))this->m_pView->SetBgColor)(a1: this->m_pView, a2: -16777216);
}

//------------------------------------------------------------------------------
// Address: 0x00409A50
// Name: public: virtual void CScrollingWindow::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScrollingWindow::OnThink(CScrollingWindow *this)
{
  vgui::Panel *v2; // eax
  vgui::Panel *v3; // eax
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax

  vgui::Panel::OnThink(this);
  if ( vgui::PHandle::Get(this: &this->m_hChildPanel) != nullptr )
  {
    v2 = vgui::PHandle::Get(this: &this->m_hChildPanel);
    if ( vgui::Panel::GetTall(this: v2) != this->m_iChildTall
      || (v3 = vgui::PHandle::Get(this: &this->m_hChildPanel), vgui::Panel::GetWide(this: v3) != this->m_iChildWide) )
    {
      this->InvalidateLayout(this, a2: true, a3: false);
      v4 = vgui::PHandle::Get(this: &this->m_hChildPanel);
      this->m_iChildTall = vgui::Panel::GetTall(this: v4);
      v5 = vgui::PHandle::Get(this: &this->m_hChildPanel);
      this->m_iChildWide = vgui::Panel::GetWide(this: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409AE0
// Name: public: void CScrollingWindow::SetChildPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScrollingWindow::SetChildPanel(CScrollingWindow *this, vgui::Panel *pPanel)
{
  if ( pPanel != nullptr )
  {
    if ( pPanel != vgui::PHandle::Get(this: &this->m_hChildPanel) )
    {
      this->m_iChildTall = 0;
      this->m_iChildWide = 0;
    }
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hChildPanel, pPanel);
    pPanel->SetParent_2(this: pPanel, a2: this->m_pView);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409B40
// Name: public: static void CScrollingWindow::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CScrollingWindow::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CScrollingWindow::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `CScrollingWindow::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{844,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CScrollingWindow");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "ScrollBarSliderMoved";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "position";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00409BE0
// Name: public: CScrollingWindow::CScrollingWindow(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CScrollingWindow *__thiscall CScrollingWindow::CScrollingWindow(
        CScrollingWindow *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  vgui::ScrollBar *v9; // eax
  vgui::ScrollBar *v10; // eax
  vgui::ScrollBar *v11; // eax
  vgui::ScrollBar *v12; // eax
  vgui::ScrollBar *m_pVertScrollbar; // ecx
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (CScrollingWindow_vtbl *)&CScrollingWindow::`vftable';
  if ( `CScrollingWindow::ChainToMap'::`2'::chained == 0 )
  {
    `CScrollingWindow::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CScrollingWindow");
    v4->pfnClassName = CScrollingWindow::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CScrollingWindow::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CScrollingWindow::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CScrollingWindow");
    v5->pfnClassName = CScrollingWindow::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CScrollingWindow::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CScrollingWindow::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CScrollingWindow");
    v6->pfnClassName = CScrollingWindow::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  CScrollingWindow::PanelMessageFunc_OnSliderMoved::InitVar(a1: (int)&savedregs);
  this->m_hChildPanel.m_iPanelID = -1;
  v7 = (vgui::Panel *)operator new(nSize: 0x14Cu);
  if ( v7 != nullptr )
    v8 = vgui::Panel::Panel(this: v7, parent: this, panelName: "View");
  else
    v8 = nullptr;
  this->m_pView = v8;
  v9 = (vgui::ScrollBar *)operator new(nSize: 0x17Cu);
  if ( v9 != nullptr )
    v10 = vgui::ScrollBar::ScrollBar(this: v9, parent: this, panelName: "VertScrollbar", vertical: true);
  else
    v10 = nullptr;
  this->m_pVertScrollbar = v10;
  v11 = (vgui::ScrollBar *)operator new(nSize: 0x17Cu);
  if ( v11 != nullptr )
    v12 = vgui::ScrollBar::ScrollBar(this: v11, parent: this, panelName: "HorizScrollbar", vertical: false);
  else
    v12 = nullptr;
  m_pVertScrollbar = this->m_pVertScrollbar;
  this->m_pHorizScrollbar = v12;
  m_pVertScrollbar->SetButtonPressedScrollValue(this: m_pVertScrollbar, a2: 160);
  this->m_pHorizScrollbar->SetButtonPressedScrollValue(this: this->m_pHorizScrollbar, a2: 160);
  this->m_pHorizScrollbar->AddActionSignalTarget_2(this: this->m_pHorizScrollbar, a2: this);
  this->m_pVertScrollbar->SetValue(this: this->m_pVertScrollbar, a2: 0);
  this->m_pHorizScrollbar->SetValue(this: this->m_pHorizScrollbar, a2: 0);
  this->m_pVertScrollbar->AddActionSignalTarget_2(this: this->m_pVertScrollbar, a2: this);
  this->m_iChildTall = 0;
  this->m_iChildWide = 0;
  return this;
}

} // namespace vgui_editor
