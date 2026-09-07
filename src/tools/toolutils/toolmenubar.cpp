// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tools/toolutils/toolmenubar.cpp
// Functions: 15
// ============================================================

#include "tools\toolutils\toolmenubar.h"

//------------------------------------------------------------------------------
// Address: 0x102C09F0
// Name: public: static char const __near * CToolMenuBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CToolMenuBar::GetPanelClassName()
{
  return "CToolMenuBar";
}

//------------------------------------------------------------------------------
// Address: 0x102C0A00
// Name: public: static char const __near * CToolFileMenuBar::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CToolFileMenuBar::GetPanelClassName()
{
  return "CToolFileMenuBar";
}

//------------------------------------------------------------------------------
// Address: 0x102C0A10
// Name: public: void CToolMenuBar::SetToolName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolMenuBar::SetToolName(CToolMenuBar *this, const char *pName)
{
  this->m_pToolName->SetText(this: this->m_pToolName, a2: pName);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102C0A40
// Name: public: void CToolMenuBar::SetInfo(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolMenuBar::SetInfo(CToolMenuBar *this, const char *pInfo)
{
  this->m_pInfo->SetText(this: this->m_pInfo, a2: pInfo);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102C0A70
// Name: public: virtual void CToolMenuBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolMenuBar::PerformLayout(CToolMenuBar *this)
{
  int v2; // esi
  int v3; // [esp+8h] [ebp-10h] BYREF
  int w; // [esp+Ch] [ebp-Ch] BYREF
  int h; // [esp+10h] [ebp-8h] BYREF
  int cw; // [esp+14h] [ebp-4h] BYREF

  vgui::MenuBar::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  this->m_pInfo->GetContentSize(this: this->m_pInfo, a2: &cw, a3: &v3);
  v2 = w - cw - 20;
  vgui::Panel::SetBounds(this: this->m_pInfo, x: v2, y: 0, wide: cw, tall: h);
  this->m_pToolName->GetContentSize(this: this->m_pToolName, a2: &cw, a3: &v3);
  vgui::Panel::SetBounds(this: this->m_pToolName, x: v2 - cw - 5, y: 0, wide: cw, tall: h);
}

//------------------------------------------------------------------------------
// Address: 0x102C0B00
// Name: public: void CToolFileMenuBar::SetFileName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFileMenuBar::SetFileName(CToolFileMenuBar *this, const char *name)
{
  this->m_pFileName->SetText(this: this->m_pFileName, a2: name);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102C0B30
// Name: public: virtual void CToolFileMenuBar::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolFileMenuBar::PerformLayout(CToolFileMenuBar *this)
{
  int v2; // edi
  int v3; // edi
  int bary; // [esp+8h] [ebp-18h] BYREF
  int h; // [esp+Ch] [ebp-14h] BYREF
  int barx; // [esp+10h] [ebp-10h] BYREF
  int w; // [esp+14h] [ebp-Ch] BYREF
  int v8; // [esp+18h] [ebp-8h] BYREF
  int cw; // [esp+1Ch] [ebp-4h] BYREF

  CToolMenuBar::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  this->m_pInfo->GetContentSize(this: this->m_pInfo, a2: &cw, a3: &v8);
  v2 = w - cw;
  this->m_pToolName->GetContentSize(this: this->m_pToolName, a2: &cw, a3: &v8);
  this->GetContentSize(this, a2: &barx, a3: &bary);
  v3 = (int)(float)((float)(barx - cw + v2 - 25) * 0.5);
  this->m_pFileName->GetContentSize(this: this->m_pFileName, a2: &cw, a3: &v8);
  vgui::Panel::SetBounds(
    this: this->m_pFileName,
    x: (int)(float)((float)v3 - (float)((float)cw * 0.5)),
    y: 0,
    wide: cw,
    tall: h);
}

//------------------------------------------------------------------------------
// Address: 0x102C0C10
// Name: public: CToolMenuBar::CToolMenuBar(class CBaseToolSystem __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CToolMenuBar *__thiscall CToolMenuBar::CToolMenuBar(
        CToolMenuBar *this,
        CBaseToolSystem *pParent,
        const char *pPanelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Label *v7; // eax
  vgui::Label *v8; // eax
  vgui::Label *v9; // eax

  vgui::MenuBar::MenuBar(this, parent: pParent, panelName: pPanelName);
  this->__vftable = (CToolMenuBar_vtbl *)&CToolMenuBar::`vftable';
  if ( `CToolMenuBar::ChainToMap'::`2'::chained == 0 )
  {
    `CToolMenuBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CToolMenuBar");
    v4->pfnClassName = CToolMenuBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::MenuBar");
  }
  if ( `CToolMenuBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CToolMenuBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CToolMenuBar");
    v5->pfnClassName = CToolMenuBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::MenuBar");
  }
  if ( `CToolMenuBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CToolMenuBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CToolMenuBar");
    v6->pfnClassName = CToolMenuBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::MenuBar");
  }
  this->m_pToolSystem = pParent;
  v7 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v7 != nullptr )
    v8 = vgui::Label::Label(this: v7, parent: this, panelName: "Info", text: &var);
  else
    v8 = nullptr;
  this->m_pInfo = v8;
  v9 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v9 != nullptr )
    this->m_pToolName = vgui::Label::Label(this: v9, parent: this, panelName: "ToolName", text: &var);
  else
    this->m_pToolName = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C0D40
// Name: public: virtual struct vgui::PanelMessageMap __near * CToolMenuBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CToolMenuBar::GetMessageMap(CToolMenuBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CToolMenuBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CToolMenuBar::GetMessageMap'::`2'::s_pMap;
  `CToolMenuBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CToolMenuBar");
  `CToolMenuBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C0D70
// Name: public: virtual struct PanelAnimationMap __near * CToolMenuBar::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CToolMenuBar::GetAnimMap(CToolMenuBar *this)
{
  return FindOrAddPanelAnimationMap(className: "CToolMenuBar");
}

//------------------------------------------------------------------------------
// Address: 0x102C0D80
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CToolMenuBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CToolMenuBar::GetKBMap(CToolMenuBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CToolMenuBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CToolMenuBar::GetKBMap'::`2'::s_pMap;
  `CToolMenuBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CToolMenuBar");
  `CToolMenuBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C0DE0
// Name: public: CToolFileMenuBar::CToolFileMenuBar(class CBaseToolSystem __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CToolFileMenuBar *__thiscall CToolFileMenuBar::CToolFileMenuBar(
        CToolFileMenuBar *this,
        CBaseToolSystem *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Label *v7; // eax

  CToolMenuBar::CToolMenuBar(this, pParent: parent, pPanelName: panelName);
  this->__vftable = (CToolFileMenuBar_vtbl *)&CToolFileMenuBar::`vftable';
  if ( `CToolFileMenuBar::ChainToMap'::`2'::chained == 0 )
  {
    `CToolFileMenuBar::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CToolFileMenuBar");
    v4->pfnClassName = CToolFileMenuBar::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CToolMenuBar");
  }
  if ( `CToolFileMenuBar::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CToolFileMenuBar::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CToolFileMenuBar");
    v5->pfnClassName = CToolFileMenuBar::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CToolMenuBar");
  }
  if ( `CToolFileMenuBar::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CToolFileMenuBar::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CToolFileMenuBar");
    v6->pfnClassName = CToolFileMenuBar::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CToolMenuBar");
  }
  v7 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v7 != nullptr )
    this->m_pFileName = vgui::Label::Label(this: v7, parent: this, panelName: "FileName", text: &var);
  else
    this->m_pFileName = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102C0EE0
// Name: public: virtual struct vgui::PanelMessageMap __near * CToolFileMenuBar::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CToolFileMenuBar::GetMessageMap(CToolFileMenuBar *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CToolFileMenuBar::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CToolFileMenuBar::GetMessageMap'::`2'::s_pMap;
  `CToolFileMenuBar::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CToolFileMenuBar");
  `CToolFileMenuBar::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102C0F10
// Name: public: virtual struct PanelAnimationMap __near * CToolFileMenuBar::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CToolFileMenuBar::GetAnimMap(CToolFileMenuBar *this)
{
  return FindOrAddPanelAnimationMap(className: "CToolFileMenuBar");
}

//------------------------------------------------------------------------------
// Address: 0x102C0F20
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CToolFileMenuBar::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CToolFileMenuBar::GetKBMap(CToolFileMenuBar *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CToolFileMenuBar::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CToolFileMenuBar::GetKBMap'::`2'::s_pMap;
  `CToolFileMenuBar::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CToolFileMenuBar");
  `CToolFileMenuBar::GetKBMap'::`2'::s_pMap = result;
  return result;
}
