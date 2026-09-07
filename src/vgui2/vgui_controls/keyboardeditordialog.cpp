// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/keyboardeditordialog.cpp
// Functions: 59
// ============================================================

#include "vgui2\vgui_controls\keyboardeditordialog.h"

//------------------------------------------------------------------------------
// Address: 0x1031F210
// Name: public: static char const __near * vgui::CKeyBoardEditorPage::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CKeyBoardEditorPage::GetPanelClassName()
{
  return "CKeyBoardEditorPage";
}

//------------------------------------------------------------------------------
// Address: 0x1031F220
// Name: public: static char const __near * vgui::CKeyBoardEditorSheet::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CKeyBoardEditorSheet::GetPanelClassName()
{
  return "CKeyBoardEditorSheet";
}

//------------------------------------------------------------------------------
// Address: 0x1031F230
// Name: public: static char const __near * vgui::CKeyBoardEditorDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::CKeyBoardEditorDialog::GetPanelClassName()
{
  return "CKeyBoardEditorDialog";
}

//------------------------------------------------------------------------------
// Address: 0x1031F240
// Name: public: static char const __near * VControlsListPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl VControlsListPanel::GetPanelClassName()
{
  return "VControlsListPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1031F250
// Name: public: static char const __near * CInlineEditPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CInlineEditPanel::GetPanelClassName()
{
  return "CInlineEditPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1031F260
// Name: private: virtual void VControlsListPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VControlsListPanel::ApplySchemeSettings(VControlsListPanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme_vtbl *v3; // ebx
  bool v4; // al

  vgui::ListPanel::ApplySchemeSettings(this, pScheme);
  v3 = pScheme->__vftable;
  v4 = this->IsProportional(this);
  this->m_hFont = v3->GetFont(this: pScheme, a2: "DefaultVerySmall", a3: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1031F2A0
// Name: public: virtual void VControlsListPanel::StartCaptureMode(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VControlsListPanel::StartCaptureMode(VControlsListPanel *this, unsigned int hCursor)
{
  void (__thiscall *EnterEditMode)(vgui::ListPanel *, int, int, vgui::Panel *); // eax
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
  if ( hCursor != 0 )
  {
    this->m_pInlineEditPanel->SetCursor(this: this->m_pInlineEditPanel, a2: hCursor);
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &this->m_iMouseX, a3: &this->m_iMouseY);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031F340
// Name: public: virtual void VControlsListPanel::OnClearBinding(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VControlsListPanel::OnClearBinding(VControlsListPanel *this)
{
  KeyValues *v2; // edi
  int v3; // eax
  KeyValues *v4; // edi
  vgui::Panel *v5; // eax
  VControlsListPanel_vtbl *v6; // ebx
  int v7; // eax

  if ( !this->m_bCaptureMode && this->GetItemOfInterest(this) >= 0 )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
    {
      v3 = this->GetItemOfInterest(this);
      v4 = KeyValues::KeyValues(this: v2, setName: "ClearBinding", firstKey: "item", firstValue: v3);
    }
    else
    {
      v4 = nullptr;
    }
    v5 = this->GetParent(this);
    v6 = this->__vftable;
    v7 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD))v5->GetVPanel)(a1: v5, a2: v4, a3: 0);
    ((void (__thiscall *)(VControlsListPanel *, int))v6->PostMessage_2)(a1: this, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031F3C0
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
// Address: 0x1031F470
// Name: public: virtual int VControlsListPanel::GetItemOfInterest(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall VControlsListPanel::GetItemOfInterest(VControlsListPanel *this)
{
  return this->m_nClickRow;
}

//------------------------------------------------------------------------------
// Address: 0x1031F480
// Name: public: virtual bool VControlsListPanel::IsCapturing(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall VControlsListPanel::IsCapturing(VControlsListPanel *this)
{
  return this->m_bCaptureMode;
}

//------------------------------------------------------------------------------
// Address: 0x1031F490
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
    vgui::ListPanel::OnMousePressed(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031F4E0
// Name: public: virtual void VControlsListPanel::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VControlsListPanel::OnMouseDoublePressed(VControlsListPanel *this, ButtonCode_t code)
{
  if ( this->GetSelectedItemsCount(this) <= 0 )
    vgui::ListPanel::OnMouseDoublePressed(this, code);
  else
    this->OnKeyCodeTyped(this, a2: KEY_ENTER);
}

//------------------------------------------------------------------------------
// Address: 0x1031F520
// Name: protected: virtual void vgui::CKeyBoardEditorPage::ItemSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CKeyBoardEditorPage::ItemSelected(vgui::CKeyBoardEditorPage *this)
{
  VControlsListPanel *m_pList; // ecx
  VControlsListPanel_vtbl *v3; // edi
  int v4; // eax

  if ( this->m_pList->GetSelectedItemsCount(this: this->m_pList) > 0 )
  {
    m_pList = this->m_pList;
    v3 = m_pList->__vftable;
    v4 = m_pList->GetSelectedItem(this: m_pList, a2: 0);
    v3->SetItemOfInterest(this: this->m_pList, a2: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1031F560
// Name: protected: virtual void vgui::CKeyBoardEditorPage::OnPageHide(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CKeyBoardEditorPage::OnPageHide(vgui::CKeyBoardEditorPage *this)
{
  if ( this->m_pList->IsCapturing(this: this->m_pList) )
    this->m_pList->EndCaptureMode(this: this->m_pList, a2: 2u);
}

//------------------------------------------------------------------------------
// Address: 0x1031F590
// Name: protected: virtual void vgui::CKeyBoardEditorPage::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CKeyBoardEditorPage::OnCommand(vgui::CKeyBoardEditorPage *this, const char *cmd)
{
  if ( this->m_pList->IsCapturing(this: this->m_pList) || _V_stricmp(s1: cmd, s2: "ChangeKey") != 0 )
    vgui::Panel::OnCommand(this, command: cmd);
  else
    this->m_pList->StartCaptureMode(this: this->m_pList, a2: 15u);
}

//------------------------------------------------------------------------------
// Address: 0x1031F630
// Name: public: virtual struct vgui::PanelMessageMap __near * VControlsListPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall VControlsListPanel::GetMessageMap(VControlsListPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`VControlsListPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `VControlsListPanel::GetMessageMap'::`2'::s_pMap;
  `VControlsListPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "VControlsListPanel");
  `VControlsListPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1031F660
// Name: public: virtual struct PanelAnimationMap __near * VControlsListPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall VControlsListPanel::GetAnimMap(VControlsListPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "VControlsListPanel");
}

//------------------------------------------------------------------------------
// Address: 0x1031F670
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * VControlsListPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall VControlsListPanel::GetKBMap(VControlsListPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`VControlsListPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `VControlsListPanel::GetKBMap'::`2'::s_pMap;
  `VControlsListPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "VControlsListPanel");
  `VControlsListPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1031F6A0
// Name: public: CInlineEditPanel::CInlineEditPanel(void)
// Source: json
//------------------------------------------------------------------------------
CInlineEditPanel *__thiscall CInlineEditPanel::CInlineEditPanel(CInlineEditPanel *this)
{
  vgui::PanelMessageMap *v2; // edi
  PanelAnimationMap *v3; // edi
  vgui::PanelKeyBindingMap *v4; // edi

  vgui::Panel::Panel(this, parent: nullptr, panelName: "InlineEditPanel");
  this->__vftable = (CInlineEditPanel_vtbl *)&CInlineEditPanel::`vftable';
  if ( `CInlineEditPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CInlineEditPanel::ChainToMap'::`2'::chained = 1;
    v2 = vgui::FindOrAddPanelMessageMap(className: "CInlineEditPanel");
    v2->pfnClassName = CInlineEditPanel::GetPanelClassName;
    v2->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CInlineEditPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CInlineEditPanel::ChainToAnimationMap'::`2'::chained = 1;
    v3 = FindOrAddPanelAnimationMap(className: "CInlineEditPanel");
    v3->pfnClassName = CInlineEditPanel::GetPanelClassName;
    v3->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CInlineEditPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CInlineEditPanel::KB_ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelKeyBindingMap(className: "CInlineEditPanel");
    v4->pfnClassName = CInlineEditPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1031F760
// Name: public: virtual void CInlineEditPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CInlineEditPanel::Paint(CInlineEditPanel *this)
{
  int wide; // [esp+0h] [ebp-8h] BYREF
  int tall; // [esp+4h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 63, a3: 63, a4: 63, a5: 255);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 0, a3: 255, a4: 0, a5: 255);
  g_pVGuiSurface->DrawOutlinedRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: wide, a5: tall);
}

//------------------------------------------------------------------------------
// Address: 0x1031F7E0
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
// Address: 0x1031F820
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
// Address: 0x1031F860
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
// Address: 0x1031F8A0
// Name: public: virtual struct vgui::PanelMessageMap __near * CInlineEditPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CInlineEditPanel::GetMessageMap(CInlineEditPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CInlineEditPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CInlineEditPanel::GetMessageMap'::`2'::s_pMap;
  `CInlineEditPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CInlineEditPanel");
  `CInlineEditPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1031F8D0
// Name: public: virtual struct PanelAnimationMap __near * CInlineEditPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CInlineEditPanel::GetAnimMap(CInlineEditPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CInlineEditPanel");
}

//------------------------------------------------------------------------------
// Address: 0x1031F8E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CInlineEditPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CInlineEditPanel::GetKBMap(CInlineEditPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CInlineEditPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CInlineEditPanel::GetKBMap'::`2'::s_pMap;
  `CInlineEditPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CInlineEditPanel");
  `CInlineEditPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10320780
// Name: public: static void vgui::CKeyBoardEditorPage::PanelMessageFunc_ItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CKeyBoardEditorPage::PanelMessageFunc_ItemSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::CKeyBoardEditorPage::PanelMessageFunc_ItemSelected::InitVar'::`2'::bAdded )
  {
    `vgui::CKeyBoardEditorPage::PanelMessageFunc_ItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CKeyBoardEditorPage");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ItemSelected";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10320810
// Name: public: static void vgui::CKeyBoardEditorPage::PanelMessageFunc_OnClearBinding::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::CKeyBoardEditorPage::PanelMessageFunc_OnClearBinding::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`vgui::CKeyBoardEditorPage::PanelMessageFunc_OnClearBinding::InitVar'::`2'::bAdded )
  {
    `vgui::CKeyBoardEditorPage::PanelMessageFunc_OnClearBinding::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSnapshotGrid::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CKeyBoardEditorPage");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ClearBinding";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "item";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103208B0
// Name: public: static void VControlsListPanel::KB_AddToMap(char const __near *,enum ButtonCode_t,int,void (vgui::Panel::*)(void),char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall VControlsListPanel::KB_AddToMap(
        const char *a1@<ebp>,
        const char *bindingname,
        ButtonCode_t defaultcode,
        int default_modifiers,
        __int128 function,
        __int64 helpstring,
        bool passive)
{
  vgui::PanelKeyBindingMap *v7; // esi
  _DWORD v8[3]; // [esp-Ch] [ebp-4Ch] BYREF
  vgui::KeyBindingMap_t entry; // [esp+0h] [ebp-40h] BYREF
  vgui::BoundKey_t kb; // [esp+30h] [ebp-10h]
  int retaddr; // [esp+40h] [ebp+0h]

  kb.bindingname = a1;
  kb.keycode = retaddr;
  v7 = vgui::FindOrAddPanelKeyBindingMap(className: "VControlsListPanel");
  vgui::KeyBindingMap_t::KeyBindingMap_t(this: (vgui::KeyBindingMap_t *)v8);
  *(_OWORD *)(&entry.bindingname + 1) = function;
  *(_QWORD *)((char *)&entry.func + 4) = helpstring;
  v8[0] = bindingname;
  BYTE12(entry.func) = passive;
  CUtlVector<vgui::KeyBindingMap_t,CUtlMemory<vgui::KeyBindingMap_t,int>>::InsertBefore(
    this: &v7->entries,
    elem: v7->entries.m_Size,
    src: (const vgui::KeyBindingMap_t *)v8);
  vgui::BoundKey_t::BoundKey_t(this: (vgui::BoundKey_t *)&entry.docstring);
  *((_DWORD *)&entry.passive + 1) = defaultcode;
  LOBYTE(entry.docstring) = 1;
  *(_DWORD *)&entry.passive = bindingname;
  *(_DWORD *)&kb.isbuiltin = default_modifiers;
  CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertBefore(
    this: &v7->defaultkeys,
    elem: v7->defaultkeys.m_Size,
    src: (const vgui::BoundKey_t *)&entry.docstring);
  CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertBefore(
    this: &v7->boundkeys,
    elem: v7->boundkeys.m_Size,
    src: (const vgui::BoundKey_t *)&entry.docstring);
  vgui::BoundKey_t::~BoundKey_t(this: (vgui::BoundKey_t *)&entry.docstring);
  CDmeFXClip::OnDestruction(this: (vgui::ToolWindow *)v8);
}

//------------------------------------------------------------------------------
// Address: 0x10320980
// Name: public: VControlsListPanel::VControlsListPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
VControlsListPanel *__thiscall VControlsListPanel::VControlsListPanel(
        VControlsListPanel *this,
        vgui::Panel *parent,
        const char *listName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CInlineEditPanel *v7; // eax
  CInlineEditPanel *v8; // eax
  __int128 v10; // [esp-1Ch] [ebp-38h]
  __int64 v11; // [esp+14h] [ebp-8h]
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  vgui::ListPanel::ListPanel(this, parent, panelName: listName);
  this->__vftable = (VControlsListPanel_vtbl *)&VControlsListPanel::`vftable';
  if ( `VControlsListPanel::ChainToMap'::`2'::chained == 0 )
  {
    `VControlsListPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "VControlsListPanel");
    v4->pfnClassName = VControlsListPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "ListPanel");
  }
  if ( `VControlsListPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `VControlsListPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "VControlsListPanel");
    v5->pfnClassName = VControlsListPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "ListPanel");
  }
  if ( `VControlsListPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `VControlsListPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "VControlsListPanel");
    v6->pfnClassName = VControlsListPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "ListPanel");
  }
  if ( `VControlsListPanel::PanelKBMapFunc_clearbinding::InitVar'::`2'::bAdded == 0 )
  {
    *(_QWORD *)&v10 = (unsigned int) __thiscall vgui::Button::`vcall'{1140,{flat}};
    v11 = 0;
    `VControlsListPanel::PanelKBMapFunc_clearbinding::InitVar'::`2'::bAdded = 1;
    *((_QWORD *)&v10 + 1) = 0;
    VControlsListPanel::KB_AddToMap(
      a1: (const char *)&savedregs,
      bindingname: "clearbinding",
      defaultcode: KEY_DELETE,
      default_modifiers: 0,
      function: v10,
      helpstring: 0,
      passive: false);
  }
  this->m_bCaptureMode = false;
  this->m_nClickRow = 0;
  v7 = (CInlineEditPanel *)operator new(nSize: 0x150u);
  if ( v7 != nullptr )
    v8 = CInlineEditPanel::CInlineEditPanel(this: v7);
  else
    v8 = nullptr;
  this->m_hFont = 0;
  this->m_pInlineEditPanel = v8;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10320AD0
// Name: public: vgui::CKeyBoardEditorPage::SaveMapping_t::~SaveMapping_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CKeyBoardEditorPage::SaveMapping_t::~SaveMapping_t(
        vgui::CKeyBoardEditorPage::SaveMapping_t *this)
{
  CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::Purge(this: &this->original);
  if ( this->original.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->original.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->original.m_Memory.m_pMemory);
      this->original.m_Memory.m_pMemory = nullptr;
    }
    this->original.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::Purge(this: &this->current);
  if ( this->current.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->current.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->current.m_Memory.m_pMemory);
      this->current.m_Memory.m_pMemory = nullptr;
    }
    this->current.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10320B40
// Name: protected: void vgui::CKeyBoardEditorPage::GetMappingList(class vgui::Panel __near *,class CUtlVector<struct vgui::PanelKeyBindingMap __near *,class CUtlMemory<struct vgui::PanelKeyBindingMap __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CKeyBoardEditorPage::GetMappingList(
        vgui::CKeyBoardEditorPage *this,
        vgui::Panel *panel,
        CUtlMemory<vgui::TreeNode *,int> *maps)
{
  vgui::PanelKeyBindingMap *i; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::PanelKeyBindingMap **v6; // ecx
  int v7; // eax
  vgui::PanelKeyBindingMap **v8; // eax

  for ( i = panel->GetKBMap(this: panel); i != nullptr; i = i->baseMap )
  {
    m_pMemory = (int)maps[1].m_pMemory;
    m_nAllocationCount = maps->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: maps, num: m_pMemory - m_nAllocationCount + 1);
    ++maps[1].m_pMemory;
    v6 = (vgui::PanelKeyBindingMap **)maps->m_pMemory;
    v7 = (int)maps[1].m_pMemory - m_pMemory - 1;
    maps[1].m_nAllocationCount = (int)maps->m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v6[m_pMemory + 1], src: (unsigned __int8 *)&v6[m_pMemory], count: 4 * v7);
    v8 = (vgui::PanelKeyBindingMap **)&maps->m_pMemory[m_pMemory];
    if ( v8 != nullptr )
      *v8 = i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10320BC0
// Name: public: virtual vgui::CKeyBoardEditorPage::~CKeyBoardEditorPage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CKeyBoardEditorPage::~CKeyBoardEditorPage(vgui::CKeyBoardEditorPage *this)
{
  int m_Size; // eax
  int v3; // edi
  vgui::CKeyBoardEditorPage::SaveMapping_t **m_pMemory; // ecx
  vgui::CKeyBoardEditorPage::SaveMapping_t *v5; // ebx
  vgui::CKeyBoardEditorPage::SaveMapping_t **v6; // eax
  int c; // [esp+8h] [ebp-4h]

  m_Size = this->m_Save.m_Size;
  v3 = 0;
  this->__vftable = (vgui::CKeyBoardEditorPage_vtbl *)&vgui::CKeyBoardEditorPage::`vftable';
  for ( c = m_Size; v3 < m_Size; ++v3 )
  {
    m_pMemory = this->m_Save.m_Memory.m_pMemory;
    v5 = m_pMemory[v3];
    if ( v5 != nullptr )
    {
      vgui::CKeyBoardEditorPage::SaveMapping_t::~SaveMapping_t(this: m_pMemory[v3]);
      operator delete(p: v5);
      m_Size = c;
    }
  }
  this->m_Save.m_Size = 0;
  if ( this->m_Save.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Save.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Save.m_Memory.m_pMemory);
      this->m_Save.m_Memory.m_pMemory = nullptr;
    }
    this->m_Save.m_Memory.m_nAllocationCount = 0;
  }
  v6 = this->m_Save.m_Memory.m_pMemory;
  this->m_Save.m_pElements = v6;
  if ( this->m_Save.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v6 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
      this->m_Save.m_Memory.m_pMemory = nullptr;
    }
    this->m_Save.m_Memory.m_nAllocationCount = 0;
  }
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x10320C90
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CKeyBoardEditorPage::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CKeyBoardEditorPage::GetMessageMap(vgui::CKeyBoardEditorPage *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CKeyBoardEditorPage::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CKeyBoardEditorPage::GetMessageMap'::`2'::s_pMap;
  `vgui::CKeyBoardEditorPage::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CKeyBoardEditorPage");
  `vgui::CKeyBoardEditorPage::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10320CC0
// Name: public: virtual struct PanelAnimationMap __near * vgui::CKeyBoardEditorPage::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CKeyBoardEditorPage::GetAnimMap(vgui::CKeyBoardEditorPage *this)
{
  return FindOrAddPanelAnimationMap(className: "CKeyBoardEditorPage");
}

//------------------------------------------------------------------------------
// Address: 0x10320CD0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CKeyBoardEditorPage::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CKeyBoardEditorPage::GetKBMap(vgui::CKeyBoardEditorPage *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CKeyBoardEditorPage::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CKeyBoardEditorPage::GetKBMap'::`2'::s_pMap;
  `vgui::CKeyBoardEditorPage::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CKeyBoardEditorPage");
  `vgui::CKeyBoardEditorPage::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10320D00
// Name: protected: void vgui::CKeyBoardEditorPage::SaveMappings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CKeyBoardEditorPage::SaveMappings(vgui::CKeyBoardEditorPage *this)
{
  vgui::Panel *m_pPanel; // ecx
  vgui::PanelKeyBindingMap *v3; // ebx
  vgui::CKeyBoardEditorPage::SaveMapping_t *v4; // eax
  int v5; // esi
  CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int> > *p_current; // edi
  int v7; // ebx
  int v8; // esi
  vgui::CKeyBoardEditorPage::SaveMapping_t *v9; // edi
  int v10; // esi
  int v11; // ebx
  int v12; // esi
  CUtlMemory<vgui::TreeNode *,int> *v13; // esi
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v16; // ecx
  int v17; // eax
  vgui::CKeyBoardEditorPage::SaveMapping_t **v18; // eax
  int v19; // [esp-8h] [ebp-38h]
  int v20; // [esp-8h] [ebp-38h]
  CUtlVector<vgui::PanelKeyBindingMap *,CUtlMemory<vgui::PanelKeyBindingMap *,int> > maps; // [esp+8h] [ebp-28h] BYREF
  CUtlMemory<vgui::TreeNode *,int> *p_m_Save; // [esp+1Ch] [ebp-14h]
  vgui::PanelKeyBindingMap *m; // [esp+20h] [ebp-10h]
  int num; // [esp+24h] [ebp-Ch]
  int i; // [esp+28h] [ebp-8h]
  vgui::CKeyBoardEditorPage::SaveMapping_t *sm; // [esp+2Ch] [ebp-4h]

  m_pPanel = this->m_pPanel;
  memset(&maps, 0, sizeof(maps));
  vgui::CKeyBoardEditorPage::GetMappingList(this, panel: m_pPanel, (CUtlMemory<vgui::TreeNode *,int> *)&maps);
  i = 0;
  if ( maps.m_Size > 0 )
  {
    p_m_Save = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Save;
    do
    {
      v3 = maps.m_Memory.m_pMemory[i];
      m = v3;
      v4 = (vgui::CKeyBoardEditorPage::SaveMapping_t *)operator new(nSize: 0x2Cu);
      if ( v4 != nullptr )
      {
        v4->map = nullptr;
        v4->current.m_Memory.m_pMemory = nullptr;
        v4->current.m_Memory.m_nAllocationCount = 0;
        v4->current.m_Memory.m_nGrowSize = 0;
        v4->current.m_Size = 0;
        v4->current.m_pElements = nullptr;
        v4->original.m_Memory.m_pMemory = nullptr;
        v4->original.m_Memory.m_nAllocationCount = 0;
        v4->original.m_Memory.m_nGrowSize = 0;
        v4->original.m_Size = 0;
        v4->original.m_pElements = nullptr;
        sm = v4;
      }
      else
      {
        sm = nullptr;
        v4 = nullptr;
      }
      v4->map = v3;
      v5 = v4->current.m_Size - 1;
      p_current = &v4->current;
      num = v3->boundkeys.m_Size;
      if ( v5 >= 0 )
      {
        v7 = v5;
        do
        {
          vgui::BoundKey_t::~BoundKey_t(this: &p_current->m_Memory.m_pMemory[v7--]);
          --v5;
        }
        while ( v5 >= 0 );
        v3 = m;
      }
      v8 = 0;
      v19 = num;
      p_current->m_Size = 0;
      CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertMultipleBefore(
        this: p_current,
        elem: 0,
        num: v19);
      if ( num > 0 )
      {
        do
        {
          vgui::BoundKey_t::operator=(
            this: &p_current->m_Memory.m_pMemory[v8],
            src: &v3->boundkeys.m_Memory.m_pMemory[v8]);
          ++v8;
          --num;
        }
        while ( num != 0 );
      }
      v9 = sm;
      v10 = sm->original.m_Size - 1;
      num = v3->boundkeys.m_Size;
      if ( v10 >= 0 )
      {
        v11 = v10;
        do
        {
          vgui::BoundKey_t::~BoundKey_t(this: &v9->original.m_Memory.m_pMemory[v11--]);
          --v10;
        }
        while ( v10 >= 0 );
        v3 = m;
      }
      v12 = 0;
      v20 = num;
      v9->original.m_Size = 0;
      CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertMultipleBefore(
        this: &v9->original,
        elem: 0,
        num: v20);
      if ( num > 0 )
      {
        for ( m = (vgui::PanelKeyBindingMap *)num; m != nullptr; m = (vgui::PanelKeyBindingMap *)((char *)m - 1) )
        {
          vgui::BoundKey_t::operator=(
            this: &v9->original.m_Memory.m_pMemory[v12],
            src: &v3->boundkeys.m_Memory.m_pMemory[v12]);
          ++v12;
        }
      }
      v13 = p_m_Save;
      m_pMemory = p_m_Save[1].m_pMemory;
      m_nAllocationCount = p_m_Save->m_nAllocationCount;
      if ( (int)m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_Save, num: (int)m_pMemory - m_nAllocationCount + 1);
      ++v13[1].m_pMemory;
      v16 = v13->m_pMemory;
      v17 = (char *)v13[1].m_pMemory - (char *)m_pMemory - 1;
      v13[1].m_nAllocationCount = (int)v13->m_pMemory;
      if ( v17 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&v16[(_DWORD)m_pMemory + 1],
          src: (unsigned __int8 *)&v16[(_DWORD)m_pMemory],
          count: 4 * v17);
      v18 = (vgui::CKeyBoardEditorPage::SaveMapping_t **)&v13->m_pMemory[(_DWORD)m_pMemory];
      if ( v18 != nullptr )
        *v18 = sm;
      ++i;
    }
    while ( i < maps.m_Size );
  }
  if ( maps.m_Memory.m_nGrowSize >= 0 && maps.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: maps.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10320ED0
// Name: protected: void vgui::CKeyBoardEditorPage::UpdateCurrentMappings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CKeyBoardEditorPage::UpdateCurrentMappings(vgui::CKeyBoardEditorPage *this)
{
  vgui::CKeyBoardEditorPage::SaveMapping_t *v1; // edi
  vgui::PanelKeyBindingMap *map; // ebx
  int v3; // esi
  int v4; // eax
  int v5; // esi
  int c; // [esp+0h] [ebp-14h]
  vgui::CKeyBoardEditorPage *v7; // [esp+4h] [ebp-10h]
  int num; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]
  int j; // [esp+10h] [ebp-4h]

  v7 = this;
  c = this->m_Save.m_Size;
  i = 0;
  if ( c > 0 )
  {
    while ( 1 )
    {
      v1 = this->m_Save.m_Memory.m_pMemory[i];
      map = v1->map;
      v3 = v1->current.m_Size - 1;
      num = v1->map->boundkeys.m_Size;
      if ( v3 >= 0 )
      {
        v4 = 16 * v3;
        for ( j = 16 * v3; ; v4 = j )
        {
          vgui::BoundKey_t::~BoundKey_t(this: (vgui::BoundKey_t *)((char *)v1->current.m_Memory.m_pMemory + v4));
          j -= 16;
          if ( --v3 < 0 )
            break;
        }
      }
      v1->current.m_Size = 0;
      CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertMultipleBefore(
        this: &v1->current,
        elem: 0,
        num);
      if ( num > 0 )
      {
        v5 = 0;
        do
        {
          vgui::BoundKey_t::operator=(
            this: &v1->current.m_Memory.m_pMemory[v5],
            src: &map->boundkeys.m_Memory.m_pMemory[v5]);
          ++v5;
          --num;
        }
        while ( num != 0 );
      }
      if ( ++i >= c )
        break;
      this = v7;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10320F90
// Name: protected: void vgui::CKeyBoardEditorPage::RestoreMappings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CKeyBoardEditorPage::RestoreMappings(vgui::CKeyBoardEditorPage *this)
{
  vgui::CKeyBoardEditorPage::SaveMapping_t *v1; // eax
  int v2; // esi
  CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int> > *p_current; // edi
  int v4; // ebx
  int v5; // ebx
  int v6; // esi
  int c; // [esp+0h] [ebp-14h]
  vgui::CKeyBoardEditorPage::SaveMapping_t *sm; // [esp+4h] [ebp-10h]
  vgui::CKeyBoardEditorPage *v9; // [esp+8h] [ebp-Ch]
  int num; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  v9 = this;
  c = this->m_Save.m_Size;
  i = 0;
  if ( c > 0 )
  {
    while ( 1 )
    {
      v1 = this->m_Save.m_Memory.m_pMemory[i];
      v2 = v1->current.m_Size - 1;
      p_current = &v1->current;
      sm = v1;
      num = v1->original.m_Size;
      if ( v2 >= 0 )
      {
        v4 = v2;
        do
        {
          vgui::BoundKey_t::~BoundKey_t(this: &p_current->m_Memory.m_pMemory[v4--]);
          --v2;
        }
        while ( v2 >= 0 );
      }
      p_current->m_Size = 0;
      CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertMultipleBefore(this: p_current, elem: 0, num);
      v5 = num;
      if ( num > 0 )
      {
        v6 = 0;
        do
        {
          vgui::BoundKey_t::operator=(
            this: &p_current->m_Memory.m_pMemory[v6],
            src: &sm->original.m_Memory.m_pMemory[v6]);
          ++v6;
          --v5;
        }
        while ( v5 != 0 );
      }
      if ( ++i >= c )
        break;
      this = v9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10321040
// Name: protected: void vgui::CKeyBoardEditorPage::ApplyMappings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CKeyBoardEditorPage::ApplyMappings(vgui::CKeyBoardEditorPage *this)
{
  vgui::CKeyBoardEditorPage::SaveMapping_t *v1; // eax
  vgui::PanelKeyBindingMap *map; // esi
  int v3; // edi
  int v4; // ebx
  int v5; // ebx
  int v6; // edi
  int c; // [esp+0h] [ebp-14h]
  vgui::CKeyBoardEditorPage::SaveMapping_t *sm; // [esp+4h] [ebp-10h]
  vgui::CKeyBoardEditorPage *v9; // [esp+8h] [ebp-Ch]
  int num; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  v9 = this;
  c = this->m_Save.m_Size;
  i = 0;
  if ( c > 0 )
  {
    while ( 1 )
    {
      v1 = this->m_Save.m_Memory.m_pMemory[i];
      map = v1->map;
      v3 = v1->map->boundkeys.m_Size - 1;
      sm = v1;
      num = v1->current.m_Size;
      if ( v3 >= 0 )
      {
        v4 = v3;
        do
        {
          vgui::BoundKey_t::~BoundKey_t(this: &map->boundkeys.m_Memory.m_pMemory[v4--]);
          --v3;
        }
        while ( v3 >= 0 );
      }
      map->boundkeys.m_Size = 0;
      CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertMultipleBefore(
        this: &map->boundkeys,
        elem: 0,
        num);
      v5 = num;
      if ( num > 0 )
      {
        v6 = 0;
        do
        {
          vgui::BoundKey_t::operator=(
            this: &map->boundkeys.m_Memory.m_pMemory[v6],
            src: &sm->current.m_Memory.m_pMemory[v6]);
          ++v6;
          --v5;
        }
        while ( v5 != 0 );
      }
      if ( ++i >= c )
        break;
      this = v9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103210F0
// Name: protected: void vgui::CKeyBoardEditorPage::PopulateList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CKeyBoardEditorPage::PopulateList(vgui::CKeyBoardEditorPage *this)
{
  vgui::CKeyBoardEditorPage *v1; // esi
  VControlsListPanel *m_pList; // ecx
  void (__thiscall *DeleteAllItems)(vgui::ListPanel *); // edx
  int m_Size; // ecx
  int v5; // eax
  vgui::CKeyBoardEditorPage::SaveMapping_t *v6; // ecx
  int v7; // eax
  vgui::PanelKeyBindingMap *map; // edx
  vgui::BoundKey_t *v9; // esi
  KeyValues *v10; // eax
  const wchar_t *v11; // eax
  wchar_t *v12; // eax
  vgui::PanelKeyBindingMap *v13; // eax
  char *m_nAllocationCount; // edi
  const wchar_t *v15; // eax
  int v16; // eax
  UtlRBTreeNode_t<KeyValues *,int> *m_pMemory; // ecx
  int v18; // edx
  unsigned int v19; // esi
  int v20; // edx
  KeyValues **p_m_Data; // esi
  int v22; // eax
  const char **v23; // esi
  vgui::Panel *m_pPanel; // ecx
  KeyValues *v25; // eax
  const wchar_t *v26; // eax
  char *v27; // edi
  const wchar_t *v28; // eax
  int v29; // eax
  UtlRBTreeNode_t<KeyValues *,int> *v30; // ecx
  int v31; // edx
  unsigned int v32; // esi
  int v33; // edx
  KeyValues **v34; // esi
  vgui::BoundKey_t **v35; // eax
  bool v36; // sf
  int j; // esi
  KeyValues *m_Data; // edi
  char loc[128]; // [esp+Ch] [ebp-1E4h] BYREF
  char ansi[256]; // [esp+8Ch] [ebp-164h] BYREF
  int c; // [esp+18Ch] [ebp-64h]
  vgui::CKeyBoardEditorPage::SaveMapping_t *sm; // [esp+190h] [ebp-60h]
  int i; // [esp+194h] [ebp-5Ch]
  vgui::PanelKeyBindingMap *m; // [esp+198h] [ebp-58h]
  CUtlRBTree<KeyValues *,int,bool (__cdecl*)(KeyValues * const &,KeyValues * const &),CUtlMemory<UtlRBTreeNode_t<KeyValues *,int>,int> > sorted; // [esp+19Ch] [ebp-54h] BYREF
  CUtlVector<vgui::BoundKey_t *,CUtlMemory<vgui::BoundKey_t *,int> > list; // [esp+1C0h] [ebp-30h] BYREF
  vgui::CKeyBoardEditorPage *v47; // [esp+1D4h] [ebp-1Ch]
  int v48; // [esp+1D8h] [ebp-18h] BYREF
  int parent; // [esp+1DCh] [ebp-14h] BYREF
  KeyValues *insert; // [esp+1E0h] [ebp-10h] BYREF
  KeyValues *item; // [esp+1E4h] [ebp-Ch] BYREF
  unsigned int v52; // [esp+1E8h] [ebp-8h]
  bool leftchild; // [esp+1EFh] [ebp-1h] BYREF

  v1 = this;
  m_pList = this->m_pList;
  DeleteAllItems = m_pList->DeleteAllItems;
  v47 = v1;
  DeleteAllItems(this: m_pList);
  m_Size = v1->m_Save.m_Size;
  v5 = 0;
  sorted.m_LessFunc = BindingLessFunc;
  memset(&sorted.m_Elements, 0, sizeof(sorted.m_Elements));
  sorted.m_Root = -1;
  sorted.m_NumElements = 0;
  sorted.m_FirstFree = -1;
  sorted.m_LastAlloc.index = -1;
  sorted.m_pElements = nullptr;
  c = m_Size;
  i = 0;
  if ( m_Size > 0 )
  {
    while ( 1 )
    {
      v6 = v1->m_Save.m_Memory.m_pMemory[v5];
      v7 = v6->current.m_Size;
      map = v6->map;
      sm = v6;
      m = map;
      if ( v7 > 0 )
      {
        v52 = 0;
        v48 = v7;
        while ( 1 )
        {
          v9 = &v6->current.m_Memory.m_pMemory[v52 / 0x10];
          v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v10 != nullptr )
            item = KeyValues::KeyValues(this: v10, setName: "Item");
          else
            item = nullptr;
          V_snprintf(pDest: loc, maxLen: 0x80u, pFormat: "#%s", v9->bindingname);
          ansi[0] = 0;
          v11 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: loc);
          if ( v11 != nullptr )
            g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v11, a3: ansi, a4: 256);
          else
            V_strncpy(pDest: ansi, pSrc: loc, maxLen: 256);
          KeyValues::SetString(this: item, keyName: "Action", value: ansi);
          v12 = vgui::Panel::KeyCodeModifiersToDisplayString(code: (ButtonCode_t)v9->keycode, modifiers: v9->modifiers);
          KeyValues::SetWString(this: item, keyName: "Binding", value: v12);
          v13 = vgui::Panel::LookupBinding(this: v47->m_pPanel, bindingName: v9->bindingname);
          if ( v13 != nullptr )
          {
            m_nAllocationCount = (char *)v13->defaultkeys.m_Memory.m_nAllocationCount;
            if ( m_nAllocationCount != nullptr )
            {
              ansi[0] = 0;
              v15 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: m_nAllocationCount);
              if ( v15 != nullptr )
                g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v15, a3: ansi, a4: 256);
              else
                V_strncpy(pDest: ansi, pSrc: m_nAllocationCount, maxLen: 256);
              KeyValues::SetString(this: item, keyName: "Description", value: ansi);
            }
          }
          KeyValues::SetPtr(this: item, keyName: "Item", value: v9);
          parent = -1;
          leftchild = false;
          CUtlRBTree<KeyValues *,int,bool (__cdecl *)(KeyValues * const &,KeyValues * const &),CUtlMemory<UtlRBTreeNode_t<KeyValues *,int>,int>>::FindInsertionPosition(
            this: &sorted,
            insert: &item,
            &parent,
            &leftchild);
          v16 = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NewNode(
                  this: &sorted,
                  a2: (const char *)0xFFFFFFFF);
          m_pMemory = sorted.m_Elements.m_pMemory;
          v18 = parent;
          v19 = v16;
          sorted.m_Elements.m_pMemory[v19].m_Parent = parent;
          m_pMemory[v19].m_Right = -1;
          m_pMemory[v19].m_Left = -1;
          m_pMemory[v19].m_Tag = 0;
          if ( v18 == -1 )
          {
            sorted.m_Root = v16;
          }
          else
          {
            v20 = v18;
            if ( leftchild )
              m_pMemory[v20].m_Left = v16;
            else
              m_pMemory[v20].m_Right = v16;
          }
          CUtlRBTree<KeyValues *,int,bool (__cdecl *)(KeyValues * const &,KeyValues * const &),CUtlMemory<UtlRBTreeNode_t<KeyValues *,int>,int>>::InsertRebalance(
            this: &sorted,
            elem: v16);
          ++sorted.m_NumElements;
          p_m_Data = &sorted.m_Elements.m_pMemory[v19].m_Data;
          if ( p_m_Data != nullptr )
            *p_m_Data = item;
          v52 += 16;
          if ( --v48 == 0 )
            break;
          v6 = sm;
        }
      }
      v22 = m->entries.m_Size;
      if ( v22 > 0 )
      {
        v52 = 0;
        for ( parent = v22; parent != 0; --parent )
        {
          v23 = (const char **)((char *)&m->entries.m_Memory.m_pMemory->bindingname + v52);
          m_pPanel = v47->m_pPanel;
          memset(&list, 0, sizeof(list));
          vgui::Panel::LookupBoundKeys(this: m_pPanel, bindingName: *v23, (CUtlMemory<vgui::TreeNode *,int> *)&list);
          if ( list.m_Size <= 0 )
          {
            v25 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v25 != nullptr )
              insert = KeyValues::KeyValues(this: v25, setName: "Item");
            else
              insert = nullptr;
            V_snprintf(pDest: loc, maxLen: 0x80u, pFormat: "#%s", *v23);
            ansi[0] = 0;
            v26 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: loc);
            if ( v26 != nullptr )
              g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v26, a3: ansi, a4: 256);
            else
              V_strncpy(pDest: ansi, pSrc: loc, maxLen: 256);
            KeyValues::SetString(this: insert, keyName: "Action", value: ansi);
            KeyValues::SetWString(this: insert, keyName: "Binding", value: (wchar_t *)&byte_105EEA78);
            v27 = (char *)v23[8];
            if ( v27 != nullptr )
            {
              ansi[0] = 0;
              v28 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: v27);
              if ( v28 != nullptr )
                g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v28, a3: ansi, a4: 256);
              else
                V_strncpy(pDest: ansi, pSrc: v27, maxLen: 256);
              KeyValues::SetString(this: insert, keyName: "Description", value: ansi);
            }
            KeyValues::SetPtr(this: insert, keyName: "Unbound", value: v23);
            v48 = -1;
            leftchild = false;
            CUtlRBTree<KeyValues *,int,bool (__cdecl *)(KeyValues * const &,KeyValues * const &),CUtlMemory<UtlRBTreeNode_t<KeyValues *,int>,int>>::FindInsertionPosition(
              this: &sorted,
              &insert,
              parent: &v48,
              &leftchild);
            v29 = CUtlRBTree<CDmElement *,int,bool (__cdecl *)(CDmElement * const &,CDmElement * const &),CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int>>::NewNode(
                    this: &sorted,
                    a2: (const char *)0xFFFFFFFF);
            v30 = sorted.m_Elements.m_pMemory;
            v31 = v48;
            v32 = v29;
            sorted.m_Elements.m_pMemory[v32].m_Parent = v48;
            v30[v32].m_Right = -1;
            v30[v32].m_Left = -1;
            v30[v32].m_Tag = 0;
            if ( v31 == -1 )
            {
              sorted.m_Root = v29;
            }
            else
            {
              v33 = v31;
              if ( leftchild )
                v30[v33].m_Left = v29;
              else
                v30[v33].m_Right = v29;
            }
            CUtlRBTree<KeyValues *,int,bool (__cdecl *)(KeyValues * const &,KeyValues * const &),CUtlMemory<UtlRBTreeNode_t<KeyValues *,int>,int>>::InsertRebalance(
              this: &sorted,
              elem: v29);
            ++sorted.m_NumElements;
            v34 = &sorted.m_Elements.m_pMemory[v32].m_Data;
            if ( v34 != nullptr )
              *v34 = insert;
          }
          v35 = list.m_Memory.m_pMemory;
          list.m_Size = 0;
          v36 = list.m_Memory.m_nGrowSize < 0;
          if ( list.m_Memory.m_nGrowSize >= 0 )
          {
            if ( list.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
              v35 = nullptr;
              list.m_Memory.m_pMemory = nullptr;
            }
            v36 = list.m_Memory.m_nGrowSize < 0;
            list.m_Memory.m_nAllocationCount = 0;
          }
          list.m_pElements = v35;
          if ( !v36 && v35 != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v35);
          v52 += 48;
        }
      }
      v5 = i + 1;
      i = v5;
      if ( v5 >= c )
        break;
      v1 = v47;
    }
  }
  for ( j = CUtlRBTree<KeyValues *,int,bool (__cdecl *)(KeyValues * const &,KeyValues * const &),CUtlMemory<UtlRBTreeNode_t<KeyValues *,int>,int>>::FirstInorder(this: &sorted);
        j != -1;
        j = CUtlRBTree<KeyValues *,int,bool (__cdecl *)(KeyValues * const &,KeyValues * const &),CUtlMemory<UtlRBTreeNode_t<KeyValues *,int>,int>>::NextInorder(
              this: &sorted,
              i: j) )
  {
    m_Data = sorted.m_Elements.m_pMemory[j].m_Data;
    v47->m_pList->AddItem(this: v47->m_pList, a2: m_Data, a3: 0, a4: false, a5: false);
    KeyValues::deleteThis(this: m_Data);
  }
  CUtlRBTree<KeyValues *,int,bool (__cdecl *)(KeyValues * const &,KeyValues * const &),CUtlMemory<UtlRBTreeNode_t<KeyValues *,int>,int>>::RemoveAll(this: &sorted);
  CUtlRBTree<KeyValues *,int,bool (__cdecl *)(KeyValues * const &,KeyValues * const &),CUtlMemory<UtlRBTreeNode_t<KeyValues *,int>,int>>::RemoveAll(this: &sorted);
  if ( sorted.m_Elements.m_nGrowSize >= 0 && sorted.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sorted.m_Elements.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10321630
// Name: protected: virtual void vgui::CKeyBoardEditorPage::OnClearBinding(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CKeyBoardEditorPage::OnClearBinding(vgui::CKeyBoardEditorPage *this, int item)
{
  KeyValues *v3; // eax
  _DWORD *Ptr; // eax

  v3 = this->m_pList->GetItem(this: this->m_pList, a2: item);
  if ( v3 != nullptr )
  {
    Ptr = KeyValues::GetPtr(this: v3, keyName: "Item", defaultValue: nullptr);
    if ( Ptr != nullptr )
    {
      Ptr[2] = 0;
      Ptr[3] = 0;
      vgui::CKeyBoardEditorPage::PopulateList(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10321680
// Name: public: void vgui::CKeyBoardEditorSheet::OnSaveChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CKeyBoardEditorSheet::OnSaveChanges(vgui::CKeyBoardEditorSheet *this)
{
  int v2; // ebx
  int i; // edi
  vgui::CKeyBoardEditorPage *v4; // eax
  vgui::PHandle *p_m_hPanel; // ecx
  char *v6; // eax
  char *v7; // eax
  const char *v8; // [esp-4h] [ebp-10h]

  v2 = this->GetNumPages(this);
  for ( i = 0; i < v2; ++i )
  {
    v4 = (vgui::CKeyBoardEditorPage *)this->GetPage(this, a2: i);
    vgui::CKeyBoardEditorPage::ApplyMappings(this: v4);
  }
  p_m_hPanel = &this->m_hPanel;
  if ( this->m_bSaveToExternalFile )
  {
    vgui::PHandle::Get(this: p_m_hPanel);
    if ( this->m_SaveFilePathID.m_Id == 0xFFFF )
      v6 = nullptr;
    else
      v6 = CUtlSymbol::String(this: &this->m_SaveFilePathID);
    v8 = v6;
    v7 = CUtlSymbol::String(this: &this->m_SaveFileName);
    vgui::Panel::SaveKeyBindingsToFile(handle: this->m_Handle, filename: v7, pathID: v8);
  }
  else
  {
    vgui::PHandle::Get(this: p_m_hPanel);
    vgui::Panel::SaveKeyBindings(handle: (const char *)this->m_Handle);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10321720
// Name: public: vgui::CKeyBoardEditorPage::CKeyBoardEditorPage(class vgui::Panel __near *,class vgui::Panel __near *,enum vgui::KeyBindingContextHandle_t)
// Source: json
//------------------------------------------------------------------------------
vgui::CKeyBoardEditorPage *__thiscall vgui::CKeyBoardEditorPage::CKeyBoardEditorPage(
        vgui::CKeyBoardEditorPage *this,
        vgui::Panel *parent,
        vgui::Panel *panelToEdit,
        vgui::KeyBindingContextHandle_t handle)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  VControlsListPanel *v8; // eax
  VControlsListPanel *v9; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent, panelName: "KeyBoardEditorPage");
  this->__vftable = (vgui::CKeyBoardEditorPage_vtbl *)&vgui::CKeyBoardEditorPage::`vftable';
  if ( `vgui::CKeyBoardEditorPage::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CKeyBoardEditorPage::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CKeyBoardEditorPage");
    v5->pfnClassName = vgui::CKeyBoardEditorPage::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `vgui::CKeyBoardEditorPage::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CKeyBoardEditorPage::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CKeyBoardEditorPage");
    v6->pfnClassName = vgui::CKeyBoardEditorPage::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `vgui::CKeyBoardEditorPage::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CKeyBoardEditorPage::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CKeyBoardEditorPage");
    v7->pfnClassName = vgui::CKeyBoardEditorPage::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  vgui::CKeyBoardEditorPage::PanelMessageFunc_ItemSelected::InitVar(a1: (int)&savedregs);
  vgui::CKeyBoardEditorPage::PanelMessageFunc_OnClearBinding::InitVar(a1: (int)&savedregs);
  this->m_pPanel = panelToEdit;
  this->m_Handle = handle;
  this->m_Save.m_Memory.m_pMemory = nullptr;
  this->m_Save.m_Memory.m_nAllocationCount = 0;
  this->m_Save.m_Memory.m_nGrowSize = 0;
  this->m_Save.m_Size = 0;
  this->m_Save.m_pElements = nullptr;
  v8 = (VControlsListPanel *)operator new(nSize: 0x268u);
  if ( v8 != nullptr )
    v9 = VControlsListPanel::VControlsListPanel(this: v8, parent: this, listName: "KeyBindings");
  else
    v9 = nullptr;
  this->m_pList = v9;
  vgui::ListPanel::SetIgnoreDoubleClick(this: v9, state: true);
  this->m_pList->AddColumnHeader(this: this->m_pList, a2: 0, a3: "Action", a4: "#KBEditorBindingName", a5: 175, a6: 0);
  this->m_pList->AddColumnHeader(this: this->m_pList, a2: 1, a3: "Binding", a4: "#KBEditorBinding", a5: 175, a6: 0);
  this->m_pList->AddColumnHeader(
    this: this->m_pList,
    a2: 2,
    a3: "Description",
    a4: "#KBEditorDescription",
    a5: 300,
    a6: 0);
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "resource/KeyBoardEditorPage.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  vgui::CKeyBoardEditorPage::SaveMappings(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10321900
// Name: public: virtual void vgui::CKeyBoardEditorPage::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CKeyBoardEditorPage::ApplySchemeSettings(vgui::CKeyBoardEditorPage *this, vgui::IScheme *scheme)
{
  vgui::Panel::ApplySchemeSettings(this, pScheme: (int)scheme);
  vgui::CKeyBoardEditorPage::PopulateList(this);
}

//------------------------------------------------------------------------------
// Address: 0x10321920
// Name: protected: void vgui::CKeyBoardEditorPage::BindKey(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CKeyBoardEditorPage::BindKey(vgui::CKeyBoardEditorPage *this, vgui::KeyBindingMap_t *code)
{
  bool v3; // bl
  bool v4; // al
  int v5; // edi
  KeyValues *v6; // eax
  KeyValues *v7; // ebx
  vgui::KeyBindingMap_t *v9; // eax
  const wchar_t *v10; // eax
  vgui::KeyBindingMap_t *v11; // ebx
  const char *bindingname; // [esp-4h] [ebp-1Ch]
  vgui::BoundKey_t *kbMap; // [esp+Ch] [ebp-Ch]
  int modifiers; // [esp+10h] [ebp-8h]
  bool shift; // [esp+17h] [ebp-1h]
  vgui::KeyBindingMap_t *binding; // [esp+20h] [ebp+8h]
  vgui::KeyBindingMap_t *bindinga; // [esp+20h] [ebp+8h]

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
    || (shift = false, g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT)) )
  {
    shift = true;
  }
  v3 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL);
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
    || (v4 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT)) )
  {
    v4 = true;
  }
  modifiers = shift;
  if ( v3 )
    modifiers |= 2u;
  if ( v4 )
    modifiers |= 4u;
  v5 = this->m_pList->GetItemOfInterest(this: this->m_pList);
  this->m_pList->EndCaptureMode(this: this->m_pList, a2: 2u);
  v6 = this->m_pList->GetItem(this: this->m_pList, a2: v5);
  v7 = v6;
  if ( v6 != nullptr )
  {
    kbMap = (vgui::BoundKey_t *)KeyValues::GetPtr(this: v6, keyName: "Item", defaultValue: nullptr);
    if ( kbMap != nullptr )
    {
      v9 = vgui::Panel::LookupBindingByKeyCode(this: this->m_pPanel, (ButtonCode_t)code, modifiers);
      binding = v9;
      if ( v9 != nullptr && _V_stricmp(s1: kbMap->bindingname, s2: v9->bindingname) != 0 )
      {
        bindingname = binding->bindingname;
LABEL_20:
        v10 = vgui::Panel::KeyCodeToDisplayString((ButtonCode_t)code);
        _Warning(a1: "Can't bind to '%ls', key is already bound to '%s'\n", v10, bindingname);
        return;
      }
      kbMap->modifiers = modifiers;
      kbMap->keycode = (int)code;
      vgui::CKeyBoardEditorPage::PopulateList(this);
    }
    bindinga = (vgui::KeyBindingMap_t *)KeyValues::GetPtr(this: v7, keyName: "Unbound", defaultValue: nullptr);
    if ( bindinga != nullptr )
    {
      v11 = vgui::Panel::LookupBindingByKeyCode(this: this->m_pPanel, (ButtonCode_t)code, modifiers);
      if ( v11 != nullptr && _V_stricmp(s1: bindinga->bindingname, s2: v11->bindingname) != 0 )
      {
        bindingname = v11->bindingname;
        goto LABEL_20;
      }
      this->m_pPanel->AddKeyBinding(this: this->m_pPanel, a2: bindinga->bindingname, a3: (int)code, a4: modifiers);
      vgui::CKeyBoardEditorPage::UpdateCurrentMappings(this);
      vgui::CKeyBoardEditorPage::PopulateList(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10321B10
// Name: public: virtual void vgui::CKeyBoardEditorPage::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CKeyBoardEditorPage::OnKeyCodeTyped(vgui::CKeyBoardEditorPage *this, ButtonCode_t code)
{
  bool v3; // al
  vgui::CKeyBoardEditorPage *v4; // ecx
  bool v5; // al
  ButtonCode_t v6; // [esp-4h] [ebp-Ch]

  if ( code == KEY_ENTER )
  {
    v5 = this->m_pList->IsCapturing(this: this->m_pList);
    v4 = this;
    if ( !v5 )
    {
      this->OnCommand(this, a2: "ChangeKey");
      return;
    }
    v6 = KEY_ENTER;
    goto LABEL_9;
  }
  if ( code <= KEY_BREAK || code > KEY_RCONTROL )
  {
    v3 = this->m_pList->IsCapturing(this: this->m_pList);
    v6 = code;
    v4 = this;
    if ( !v3 )
    {
      vgui::EditablePanel::OnKeyCodeTyped(this, code);
      return;
    }
LABEL_9:
    vgui::CKeyBoardEditorPage::BindKey(this: v4, code: (vgui::KeyBindingMap_t *)v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10321B90
// Name: public: vgui::CKeyBoardEditorSheet::CKeyBoardEditorSheet(class vgui::Panel __near *,class vgui::Panel __near *,enum vgui::KeyBindingContextHandle_t)
// Source: json
//------------------------------------------------------------------------------
vgui::CKeyBoardEditorSheet *__thiscall vgui::CKeyBoardEditorSheet::CKeyBoardEditorSheet(
        vgui::CKeyBoardEditorSheet *this,
        vgui::Panel *parent,
        CDragDropHelperPanel *panelToEdit,
        vgui::KeyBindingContextHandle_t handle)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::KeyBindingContextHandle_t v8; // ebx
  vgui::Panel *PanelWithKeyBindings; // eax
  vgui::Panel *v10; // edi
  vgui::CKeyBoardEditorPage *v11; // eax
  vgui::PageTab *v12; // ebx
  const char *v13; // eax
  int subCount; // [esp+Ch] [ebp-8h]
  vgui::CKeyBoardEditorPage *active; // [esp+10h] [ebp-4h]
  int i; // [esp+1Ch] [ebp+8h]

  vgui::PropertySheet::PropertySheet(
    this,
    parent,
    panelName: (vgui::Panel *)"KeyBoardEditorSheet",
    draggableTabs: false);
  this->__vftable = (vgui::CKeyBoardEditorSheet_vtbl *)&vgui::CKeyBoardEditorSheet::`vftable';
  if ( `vgui::CKeyBoardEditorSheet::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CKeyBoardEditorSheet::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CKeyBoardEditorSheet");
    v5->pfnClassName = vgui::CKeyBoardEditorSheet::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "PropertySheet");
  }
  if ( `vgui::CKeyBoardEditorSheet::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CKeyBoardEditorSheet::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CKeyBoardEditorSheet");
    v6->pfnClassName = vgui::CKeyBoardEditorSheet::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "PropertySheet");
  }
  if ( `vgui::CKeyBoardEditorSheet::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CKeyBoardEditorSheet::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CKeyBoardEditorSheet");
    v7->pfnClassName = vgui::CKeyBoardEditorSheet::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "PropertySheet");
  }
  v8 = handle;
  this->m_hPanel.m_iPanelID = -1;
  this->m_Handle = handle;
  this->m_bSaveToExternalFile = false;
  *(_DWORD *)&this->m_SaveFileName.m_Id = -1;
  this->m_clrAlteredItem = 0;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hPanel,
    pPanel: panelToEdit);
  vgui::PropertySheet::SetSmallTabs(this, state: true);
  active = nullptr;
  subCount = vgui::Panel::GetPanelsWithKeyBindingsCount(handle);
  i = 0;
  if ( subCount > 0 )
  {
    do
    {
      PanelWithKeyBindings = vgui::Panel::GetPanelWithKeyBindings(handle: v8, index: i);
      v10 = PanelWithKeyBindings;
      if ( PanelWithKeyBindings != nullptr && vgui::Panel::GetKeyMappingCount(this: PanelWithKeyBindings) != 0 )
      {
        v11 = (vgui::CKeyBoardEditorPage *)operator new(nSize: 0x1A4u);
        if ( v11 != nullptr )
          v12 = (vgui::PageTab *)vgui::CKeyBoardEditorPage::CKeyBoardEditorPage(
                                   this: v11,
                                   parent: this,
                                   panelToEdit: v10,
                                   handle: v8);
        else
          v12 = nullptr;
        v13 = v10->GetName(this: v10);
        vgui::PropertySheet::AddPage(
          this,
          a2: (int)v10,
          page: v12,
          title: v13,
          imageName: nullptr,
          bHasContextMenu: nullptr,
          nInsertBefore: -1);
        if ( v10 == panelToEdit )
          active = (vgui::CKeyBoardEditorPage *)v12;
        v8 = handle;
      }
      ++i;
    }
    while ( i < subCount );
    if ( active != nullptr )
      vgui::PropertySheet::SetActivePage(this, page: active);
  }
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "resource/KeyBoardEditorSheet.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10321D40
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CKeyBoardEditorSheet::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CKeyBoardEditorSheet::GetMessageMap(vgui::CKeyBoardEditorSheet *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CKeyBoardEditorSheet::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CKeyBoardEditorSheet::GetMessageMap'::`2'::s_pMap;
  `vgui::CKeyBoardEditorSheet::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CKeyBoardEditorSheet");
  `vgui::CKeyBoardEditorSheet::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10321D70
// Name: public: virtual struct PanelAnimationMap __near * vgui::CKeyBoardEditorSheet::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CKeyBoardEditorSheet::GetAnimMap(vgui::CKeyBoardEditorSheet *this)
{
  return FindOrAddPanelAnimationMap(className: "CKeyBoardEditorSheet");
}

//------------------------------------------------------------------------------
// Address: 0x10321D80
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CKeyBoardEditorSheet::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CKeyBoardEditorSheet::GetKBMap(vgui::CKeyBoardEditorSheet *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CKeyBoardEditorSheet::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CKeyBoardEditorSheet::GetKBMap'::`2'::s_pMap;
  `vgui::CKeyBoardEditorSheet::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CKeyBoardEditorSheet");
  `vgui::CKeyBoardEditorSheet::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10321DE0
// Name: public: void vgui::CKeyBoardEditorSheet::OnRevert(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CKeyBoardEditorSheet::OnRevert(vgui::CKeyBoardEditorSheet *this)
{
  int v2; // esi
  vgui::CKeyBoardEditorPage *v3; // ebx
  int c; // [esp+8h] [ebp-4h]

  v2 = 0;
  c = this->GetNumPages(this);
  if ( c > 0 )
  {
    do
    {
      v3 = (vgui::CKeyBoardEditorPage *)this->GetPage(this, a2: v2);
      vgui::CKeyBoardEditorPage::RestoreMappings(this: v3);
      vgui::CKeyBoardEditorPage::PopulateList(this: v3);
      ++v2;
    }
    while ( v2 < c );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10321E30
// Name: public: void vgui::CKeyBoardEditorSheet::OnUseDefaults(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CKeyBoardEditorSheet::OnUseDefaults(vgui::CKeyBoardEditorSheet *this)
{
  int v2; // edi
  vgui::CKeyBoardEditorPage *v3; // esi
  int c; // [esp+8h] [ebp-4h]

  v2 = 0;
  c = this->GetNumPages(this);
  if ( c > 0 )
  {
    do
    {
      v3 = (vgui::CKeyBoardEditorPage *)this->GetPage(this, a2: v2);
      vgui::Panel::RevertKeyBindingsToDefault(this: v3->m_pPanel, a2: (int)this);
      vgui::CKeyBoardEditorPage::UpdateCurrentMappings(this: v3);
      vgui::CKeyBoardEditorPage::PopulateList(this: v3);
      ++v2;
    }
    while ( v2 < c );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10321EA0
// Name: public: vgui::CKeyBoardEditorDialog::CKeyBoardEditorDialog(class vgui::Panel __near *,class vgui::Panel __near *,enum vgui::KeyBindingContextHandle_t)
// Source: json
//------------------------------------------------------------------------------
vgui::CKeyBoardEditorDialog *__thiscall vgui::CKeyBoardEditorDialog::CKeyBoardEditorDialog(
        vgui::CKeyBoardEditorDialog *this,
        vgui::Panel *parent,
        CDragDropHelperPanel *panelToEdit,
        vgui::KeyBindingContextHandle_t handle)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Button *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  vgui::Button *v14; // eax
  vgui::Button *v15; // eax
  vgui::CKeyBoardEditorSheet *v16; // eax
  vgui::CKeyBoardEditorSheet *v17; // eax

  vgui::Frame::Frame(this, parent, panelName: "KeyBoardEditorDialog", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (vgui::CKeyBoardEditorDialog_vtbl *)&vgui::CKeyBoardEditorDialog::`vftable';
  if ( `vgui::CKeyBoardEditorDialog::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CKeyBoardEditorDialog::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CKeyBoardEditorDialog");
    v5->pfnClassName = vgui::CKeyBoardEditorDialog::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Frame");
  }
  if ( `vgui::CKeyBoardEditorDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::CKeyBoardEditorDialog::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CKeyBoardEditorDialog");
    v6->pfnClassName = vgui::CKeyBoardEditorDialog::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `vgui::CKeyBoardEditorDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::CKeyBoardEditorDialog::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CKeyBoardEditorDialog");
    v7->pfnClassName = vgui::CKeyBoardEditorDialog::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  }
  v8 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v8 != nullptr )
    v9 = vgui::Button::Button(
           this: v8,
           parent: this,
           panelName: "Save",
           text: "#KBEditorSave",
           pActionSignalTarget: this,
           pCmd: "save");
  else
    v9 = nullptr;
  this->m_pSave = v9;
  v10 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v10 != nullptr )
    v11 = vgui::Button::Button(
            this: v10,
            parent: this,
            panelName: "Cancel",
            text: "#KBEditorCancel",
            pActionSignalTarget: this,
            pCmd: "cancel");
  else
    v11 = nullptr;
  this->m_pCancel = v11;
  v12 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v12 != nullptr )
    v13 = vgui::Button::Button(
            this: v12,
            parent: this,
            panelName: "Revert",
            text: "#KBEditorRevert",
            pActionSignalTarget: this,
            pCmd: "revert");
  else
    v13 = nullptr;
  this->m_pRevert = v13;
  v14 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v14 != nullptr )
    v15 = vgui::Button::Button(
            this: v14,
            parent: this,
            panelName: "Defaults",
            text: "#KBEditorUseDefaults",
            pActionSignalTarget: this,
            pCmd: "defaults");
  else
    v15 = nullptr;
  this->m_pUseDefaults = v15;
  v16 = (vgui::CKeyBoardEditorSheet *)operator new(nSize: 0x228u);
  if ( v16 != nullptr )
    v17 = vgui::CKeyBoardEditorSheet::CKeyBoardEditorSheet(this: v16, parent: this, panelToEdit, handle);
  else
    v17 = nullptr;
  this->m_pKBEditor = v17;
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "resource/KeyBoardEditorDialog.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Frame::SetTitle(this, title: "#KBEditorTitle", surfaceTitle: true);
  vgui::Frame::SetSmallCaption(this, state: true);
  vgui::Panel::SetMinimumSize(this, wide: 640, tall: 200);
  vgui::Frame::SetMinimizeButtonVisible(this, state: false);
  vgui::Frame::SetMaximizeButtonVisible(this, state: false);
  vgui::Frame::SetSizeable(this, state: true);
  vgui::Frame::SetMoveable(this, state: true);
  vgui::Frame::SetMenuButtonVisible(this, state: false);
  vgui::Panel::SetVisible(this, state: 1);
  vgui::Frame::MoveToCenterOfScreen(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103220D0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::CKeyBoardEditorDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::CKeyBoardEditorDialog::GetMessageMap(vgui::CKeyBoardEditorDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::CKeyBoardEditorDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CKeyBoardEditorDialog::GetMessageMap'::`2'::s_pMap;
  `vgui::CKeyBoardEditorDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CKeyBoardEditorDialog");
  `vgui::CKeyBoardEditorDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10322100
// Name: public: virtual struct PanelAnimationMap __near * vgui::CKeyBoardEditorDialog::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::CKeyBoardEditorDialog::GetAnimMap(vgui::CKeyBoardEditorDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CKeyBoardEditorDialog");
}

//------------------------------------------------------------------------------
// Address: 0x10322110
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::CKeyBoardEditorDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::CKeyBoardEditorDialog::GetKBMap(vgui::CKeyBoardEditorDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::CKeyBoardEditorDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::CKeyBoardEditorDialog::GetKBMap'::`2'::s_pMap;
  `vgui::CKeyBoardEditorDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CKeyBoardEditorDialog");
  `vgui::CKeyBoardEditorDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10322140
// Name: public: virtual void vgui::CKeyBoardEditorDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::CKeyBoardEditorDialog::OnCommand(vgui::CKeyBoardEditorDialog *this, const char *cmd)
{
  if ( _V_stricmp(s1: cmd, s2: "save") != 0 )
  {
    if ( _V_stricmp(s1: cmd, s2: "cancel") != 0 && _V_stricmp(s1: cmd, s2: "Close") != 0 )
    {
      if ( _V_stricmp(s1: cmd, s2: "revert") != 0 )
      {
        if ( _V_stricmp(s1: cmd, s2: "defaults") != 0 )
          vgui::Frame::OnCommand(this, command: cmd);
        else
          vgui::CKeyBoardEditorSheet::OnUseDefaults(this: this->m_pKBEditor);
      }
      else
      {
        vgui::CKeyBoardEditorSheet::OnRevert(this: this->m_pKBEditor);
      }
    }
    else
    {
      vgui::CKeyBoardEditorSheet::OnRevert(this: this->m_pKBEditor);
      this->MarkForDeletion(this);
    }
  }
  else
  {
    vgui::CKeyBoardEditorSheet::OnSaveChanges(this: this->m_pKBEditor);
    this->MarkForDeletion(this);
  }
}
