// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tools/toolutils/toolui.cpp
// Functions: 9
// ============================================================

#include "tools\toolutils\toolui.h"

//------------------------------------------------------------------------------
// Address: 0x102C3730
// Name: public: static char const __near * CToolUI::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CToolUI::GetPanelClassName()
{
  return "CToolUI";
}

//------------------------------------------------------------------------------
// Address: 0x102C3740
// Name: public: class vgui::Panel __near * CToolUI::GetClientArea(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CToolUI::GetClientArea(vgui::TreeView *this)
{
  return this->m_NodeList.m_Memory.m_nAllocationCount;
}

//------------------------------------------------------------------------------
// Address: 0x102C3750
// Name: public: virtual void CToolUI::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolUI::PerformLayout(CToolUI *this)
{
  vgui::Panel *v2; // ecx
  unsigned int v3; // eax
  int v4; // edi
  vgui::Panel *m_pStatusBar; // ecx
  int iHeight; // [esp+8h] [ebp-8h] BYREF
  int iWidth; // [esp+Ch] [ebp-4h] BYREF

  vgui::Panel::PerformLayout(this);
  if ( this->GetParent(this) != nullptr )
  {
    v2 = this->GetParent(this);
    v3 = ((int (__fastcall *)(vgui::Panel *))v2->GetVPanel)(a1: v2);
  }
  else
  {
    v3 = ((int (__fastcall *)(vgui::ISurface *))g_pVGuiSurface->GetEmbeddedPanel)(a1: g_pVGuiSurface);
  }
  g_pVGuiPanel->GetSize(this: g_pVGuiPanel, a2: v3, a3: &iWidth, a4: &iHeight);
  vgui::Panel::SetSize(this, wide: iWidth, tall: iHeight);
  v4 = 0;
  vgui::Panel::SetSize(this: this->m_pMenuBar, wide: iWidth, tall: 28);
  m_pStatusBar = this->m_pStatusBar;
  if ( m_pStatusBar != nullptr )
  {
    v4 = 24;
    vgui::Panel::SetBounds(this: m_pStatusBar, x: 0, y: iHeight - 24, wide: iWidth, tall: 24);
  }
  vgui::Panel::SetBounds(this: this->m_pClientArea, x: 0, y: 28, wide: iWidth, tall: iHeight - v4 - 28);
}

//------------------------------------------------------------------------------
// Address: 0x102C3810
// Name: public: virtual void CToolUI::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolUI::OnCommand(CToolUI *this, const char *cmd)
{
  this->m_pBaseToolSystem->OnCommand(this: this->m_pBaseToolSystem, a2: cmd);
}

//------------------------------------------------------------------------------
// Address: 0x102C3830
// Name: public: virtual void CToolUI::UpdateMenuBarTitle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolUI::UpdateMenuBarTitle(CToolUI *this)
{
  CToolMenuBar *v2; // edi
  char title[64]; // [esp+8h] [ebp-40h] BYREF

  v2 = (CToolMenuBar *)__RTDynamicCast(
                         inptr: this->m_pMenuBar,
                         VfDelta: 0,
                         SrcType: &vgui::MenuBar `RTTI Type Descriptor',
                         TargetType: &CToolFileMenuBar `RTTI Type Descriptor',
                         isReference: 0);
  if ( v2 != nullptr )
  {
    this->m_pBaseToolSystem->ComputeMenuBarTitle(this: this->m_pBaseToolSystem, a2: title, a3: 64u);
    CToolMenuBar::SetInfo(this: v2, pInfo: title);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102C3890
// Name: public: CToolUI::CToolUI(class vgui::Panel __near *,char const __near *,class CBaseToolSystem __near *)
// Source: json
//------------------------------------------------------------------------------
CToolUI *__thiscall CToolUI::CToolUI(
        CToolUI *this,
        vgui::Panel *pParent,
        const char *panelName,
        CBaseToolSystem *pBaseToolSystem)
{
  vgui::Panel *v4; // ebx
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  vgui::MenuBar *v9; // eax
  vgui::Panel *v10; // eax
  vgui::Panel *v11; // eax
  vgui::Panel *v12; // eax

  v4 = pParent;
  vgui::Panel::Panel(this, parent: pParent, panelName);
  this->__vftable = (CToolUI_vtbl *)&CToolUI::`vftable';
  if ( `CToolUI::ChainToMap'::`2'::chained == 0 )
  {
    `CToolUI::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "CToolUI");
    v6->pfnClassName = CToolUI::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CToolUI::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CToolUI::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CToolUI");
    v7->pfnClassName = CToolUI::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CToolUI::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CToolUI::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "CToolUI");
    v8->pfnClassName = CToolUI::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  this->m_pBaseToolSystem = pBaseToolSystem;
  this->m_pClientArea = nullptr;
  vgui::Panel::SetPaintEnabled(this, state: false);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintBorderEnabled(this, state: false);
  vgui::Panel::GetSize(this: v4, wide: (int *)&panelName, tall: (int *)&pParent);
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: (int)panelName, tall: (int)pParent);
  v9 = (vgui::MenuBar *)((int (__stdcall *)(CBaseToolSystem *))this->m_pBaseToolSystem->CreateMenuBar)(a1: this->m_pBaseToolSystem);
  this->m_pMenuBar = v9;
  v9->SetParent_2(this: v9, a2: this);
  vgui::Panel::SetSize(this: this->m_pMenuBar, wide: (int)panelName, tall: 28);
  v10 = this->m_pBaseToolSystem->CreateStatusBar(this: this->m_pBaseToolSystem, a2: this);
  this->m_pStatusBar = v10;
  v10->SetParent_2(this: v10, a2: this);
  v11 = (vgui::Panel *)operator new(nSize: 0x14Cu);
  if ( v11 != nullptr )
    v12 = vgui::Panel::Panel(this: v11, parent: this, panelName: "ClientArea");
  else
    v12 = nullptr;
  this->m_pClientArea = v12;
  v12->SetMouseInputEnabled(this: v12, a2: false);
  this->m_pClientArea->SetCursor(this: this->m_pClientArea, a2: 1u);
  vgui::Panel::SetBounds(
    this: this->m_pClientArea,
    x: 0,
    y: 28,
    wide: (int)panelName,
    tall: (int)&pParent[-1].m_nBgTextureId2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C3A60
// Name: public: virtual struct vgui::PanelMessageMap __near * CToolUI::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CToolUI::GetMessageMap(CToolUI *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CToolUI::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CToolUI::GetMessageMap'::`2'::s_pMap;
  `CToolUI::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CToolUI");
  `CToolUI::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C3A90
// Name: public: virtual struct PanelAnimationMap __near * CToolUI::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CToolUI::GetAnimMap(CToolUI *this)
{
  return FindOrAddPanelAnimationMap(className: "CToolUI");
}

//------------------------------------------------------------------------------
// Address: 0x102C3AA0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CToolUI::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CToolUI::GetKBMap(CToolUI *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CToolUI::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CToolUI::GetKBMap'::`2'::s_pMap;
  `CToolUI::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CToolUI");
  `CToolUI::GetKBMap'::`2'::s_pMap = result;
  return result;
}
