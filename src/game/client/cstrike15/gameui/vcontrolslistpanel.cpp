// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/vcontrolslistpanel.cpp
// Functions: 19
// ============================================================

#include "game\client\cstrike15\gameui\vcontrolslistpanel.h"

//------------------------------------------------------------------------------
// Address: 0x101EBE00
// Name: public: virtual void CInlineEditPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInlineEditPanel::Paint(CInlineEditPanel *this)
{
  int wide; // [esp+0h] [ebp-8h] BYREF
  int tall; // [esp+4h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 165, a4: 0, a5: 255);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x101EBE50
// Name: public: virtual void CInlineEditPanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInlineEditPanel::OnKeyCodeTyped(CInlineEditPanel *this, ButtonCode_t code)
{
  vgui::Panel *v3; // eax

  if ( this->GetParent(this) != nullptr )
  {
    v3 = this->GetParent(this);
    v3->OnKeyCodeTyped(this: v3, a2: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EBE90
// Name: public: virtual void CInlineEditPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInlineEditPanel::ApplySchemeSettings(CInlineEditPanel *this, vgui::IScheme *pScheme)
{
  CInlineEditPanel_vtbl *v3; // ebx
  vgui::IBorder *v4; // eax

  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v3 = this->__vftable;
  v4 = pScheme->GetBorder(this: pScheme, a2: "DepressedButtonBorder");
  v3->SetBorder(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101EBED0
// Name: public: virtual void CInlineEditPanel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInlineEditPanel::OnMousePressed(CInlineEditPanel *this, ButtonCode_t code)
{
  vgui::Panel *v3; // eax

  if ( this->GetParent(this) != nullptr )
  {
    v3 = this->GetParent(this);
    v3->OnMousePressed(this: v3, a2: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EBF10
// Name: public: VControlsListPanel::VControlsListPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
VControlsListPanel *__thiscall VControlsListPanel::VControlsListPanel(
        VControlsListPanel *this,
        vgui::Panel *parent,
        const char *listName)
{
  vgui::Panel *v4; // eax
  CInlineEditPanel *v5; // edi

  vgui::SectionedListPanel::SectionedListPanel(this, parent, name: listName);
  this->__vftable = (VControlsListPanel_vtbl *)&VControlsListPanel::`vftable';
  this->m_bCaptureMode = false;
  this->m_nClickRow = 0;
  v4 = (vgui::Panel *)MemAlloc_Alloc(nSize: 0x14Cu);
  v5 = (CInlineEditPanel *)v4;
  if ( v4 != nullptr )
  {
    vgui::Panel::Panel(this: v4, parent: nullptr, panelName: "InlineEditPanel");
    v5->__vftable = (CInlineEditPanel_vtbl *)&CInlineEditPanel::`vftable';
  }
  else
  {
    v5 = nullptr;
  }
  this->m_pInlineEditPanel = v5;
  this->m_hFont = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101EBF80
// Name: public: static char const __near * vgui::SectionedListPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::SectionedListPanel::GetPanelClassName()
{
  return "SectionedListPanel";
}

//------------------------------------------------------------------------------
// Address: 0x101EBF90
// Name: public: virtual void vgui::SectionedListPanel::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::SectionedListPanel::RemoveAll(vgui::SectionedListPanel *this)
{
  this->DeleteAllItems(this);
}

//------------------------------------------------------------------------------
// Address: 0x101EBFA0
// Name: private: virtual void VControlsListPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VControlsListPanel::ApplySchemeSettings(VControlsListPanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme_vtbl *v3; // ebx
  bool v4; // al

  vgui::SectionedListPanel::ApplySchemeSettings(this, pScheme);
  v3 = pScheme->__vftable;
  v4 = this->IsProportional(this);
  this->m_hFont = v3->GetFont(this: pScheme, a2: "Default", a3: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101EBFE0
// Name: public: virtual void VControlsListPanel::StartCaptureMode(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VControlsListPanel::StartCaptureMode(VControlsListPanel *this, unsigned int hCursor)
{
  void (__thiscall *EnterEditMode)(vgui::SectionedListPanel *, int, int, vgui::Panel *); // eax
  vgui::IInput *v4; // edi
  vgui::IInput_vtbl *v5; // ebx
  unsigned int v6; // eax
  vgui::IInput *v7; // edi
  vgui::IInput_vtbl *v8; // ebx
  unsigned int v9; // eax
  int m_nClickRow; // [esp-Ch] [ebp-18h]
  CInlineEditPanel *m_pInlineEditPanel; // [esp-4h] [ebp-10h]

  EnterEditMode = this->EnterEditMode;
  m_pInlineEditPanel = this->m_pInlineEditPanel;
  m_nClickRow = this->m_nClickRow;
  this->m_bCaptureMode = true;
  EnterEditMode(this, a2: m_nClickRow, a3: 1, a4: m_pInlineEditPanel);
  v4 = g_pVGuiInput;
  v5 = g_pVGuiInput->__vftable;
  v6 = this->m_pInlineEditPanel->GetVPanel(this: this->m_pInlineEditPanel);
  v5->SetMouseFocus(this: v4, a2: v6);
  v7 = g_pVGuiInput;
  v8 = g_pVGuiInput->__vftable;
  v9 = this->m_pInlineEditPanel->GetVPanel(this: this->m_pInlineEditPanel);
  v8->SetMouseCapture(this: v7, a2: v9);
  engine->StartKeyTrapMode(this: engine);
  if ( hCursor != 0 )
  {
    this->m_pInlineEditPanel->SetCursor(this: this->m_pInlineEditPanel, a2: hCursor);
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &this->m_iMouseX, a3: &this->m_iMouseY);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EC090
// Name: public: virtual void VControlsListPanel::EndCaptureMode(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VControlsListPanel::EndCaptureMode(VControlsListPanel *this, unsigned int hCursor)
{
  vgui::IInput *v3; // edi
  vgui::IInput_vtbl *v4; // ebx
  int v5; // eax

  this->m_bCaptureMode = false;
  g_pVGuiInput->SetMouseCapture(this: g_pVGuiInput, a2: 0);
  this->LeaveEditMode(this);
  this->RequestFocus(this, a2: 0);
  v3 = g_pVGuiInput;
  v4 = g_pVGuiInput->__vftable;
  v5 = this->GetVPanel(this);
  v4->SetMouseFocus(this: v3, a2: v5);
  if ( hCursor != 0 )
  {
    this->m_pInlineEditPanel->SetCursor(this: this->m_pInlineEditPanel, a2: hCursor);
    g_pVGuiSurface->SetCursor(this: g_pVGuiSurface, a2: hCursor);
    if ( hCursor != 1 )
      g_pVGuiInput->SetCursorPos(this: g_pVGuiInput, a2: this->m_iMouseX, a3: this->m_iMouseY);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EC140
// Name: public: virtual bool VControlsListPanel::IsCapturing(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall VControlsListPanel::IsCapturing(VControlsListPanel *this)
{
  return this->m_bCaptureMode;
}

//------------------------------------------------------------------------------
// Address: 0x101EC150
// Name: public: virtual void VControlsListPanel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VControlsListPanel::OnMousePressed(VControlsListPanel *this, ButtonCode_t code)
{
  vgui::Panel *v3; // eax

  if ( this->IsCapturing(this) )
  {
    if ( this->GetParent(this) != nullptr )
    {
      v3 = this->GetParent(this);
      v3->OnMousePressed(this: v3, a2: code);
    }
  }
  else
  {
    vgui::SectionedListPanel::OnMousePressed(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EC1A0
// Name: public: virtual void VControlsListPanel::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VControlsListPanel::OnMouseDoublePressed(VControlsListPanel *this, ButtonCode_t code)
{
  VControlsListPanel_vtbl *v3; // edi
  int v4; // eax

  v3 = this->__vftable;
  v4 = this->GetSelectedItem(this);
  if ( v3->IsItemIDValid(this, a2: v4) )
    this->OnKeyCodePressed(this, a2: KEY_ENTER);
  else
    CScoreboardScaleform::SetParent((vgui::TreeView *)this, itemIndex: code);
}

//------------------------------------------------------------------------------
// Address: 0x101EC1F0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::SectionedListPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::SectionedListPanel::GetMessageMap(vgui::SectionedListPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::SectionedListPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::SectionedListPanel::GetMessageMap'::`2'::s_pMap;
  `vgui::SectionedListPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "SectionedListPanel");
  `vgui::SectionedListPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101EC220
// Name: public: virtual struct PanelAnimationMap __near * vgui::SectionedListPanel::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::SectionedListPanel::GetAnimMap(vgui::SectionedListPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "SectionedListPanel");
}

//------------------------------------------------------------------------------
// Address: 0x101EC230
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::SectionedListPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::SectionedListPanel::GetKBMap(vgui::SectionedListPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::SectionedListPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::SectionedListPanel::GetKBMap'::`2'::s_pMap;
  `vgui::SectionedListPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "SectionedListPanel");
  `vgui::SectionedListPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103A3510
// Name: public: virtual int vgui::SectionedListPanel::GetLineSpacing(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::SectionedListPanel::GetLineSpacing(vgui::ListPanel *this)
{
  return this->m_iSortColumn;
}

//------------------------------------------------------------------------------
// Address: 0x103B0FC0
// Name: public: virtual void VControlsListPanel::SetItemOfInterest(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VControlsListPanel::SetItemOfInterest(vgui::MenuButton *this, vgui::Menu::MenuDirection_e direction)
{
  this->m_iDirection = direction;
}

//------------------------------------------------------------------------------
// Address: 0x101EC2A0
// Name: __CreateCVGuiSystemModuleLoaderIVGuiModuleLoader_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CVGuiSystemModuleLoader *__cdecl _CreateCVGuiSystemModuleLoaderIVGuiModuleLoader_interface()
{
  return &g_VModuleLoader;
}
