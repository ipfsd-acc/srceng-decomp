// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/vgui_controls/propertydialog.cpp
// Functions: 15
// ============================================================

#include "vgui2\vgui_controls\propertydialog.h"

//------------------------------------------------------------------------------
// Address: 0x102D2460
// Name: private: static void __near * vgui::PropertyDialog::GetVar_m_iSheetInsetBottom(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
int *__cdecl vgui::PropertyDialog::GetVar_m_iSheetInsetBottom(vgui::Panel *panel)
{
  return &panel[1].m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount;
}

//------------------------------------------------------------------------------
// Address: 0x102D2470
// Name: public: virtual vgui::PropertyDialog::~PropertyDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyDialog::~PropertyDialog(vgui::PropertyDialog *this)
{
  this->__vftable = (vgui::PropertyDialog_vtbl *)&vgui::PropertyDialog::`vftable';
  vgui::Frame::~Frame(this);
}

//------------------------------------------------------------------------------
// Address: 0x102D24A0
// Name: public: virtual void vgui::PropertyDialog::AddPage(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyDialog::AddPage(vgui::PropertyDialog *this, vgui::Panel *page, const char *title)
{
  this->_propertySheet->AddPage(this: this->_propertySheet, a2: page, a3: title, a4: nullptr, a5: false, a6: -1);
}

//------------------------------------------------------------------------------
// Address: 0x102D24D0
// Name: public: virtual void vgui::PropertyDialog::ResetAllData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyDialog::ResetAllData(vgui::PropertyDialog *this)
{
  this->_propertySheet->ResetAllData(this: this->_propertySheet);
}

//------------------------------------------------------------------------------
// Address: 0x102D24E0
// Name: public: virtual void vgui::PropertyDialog::ApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyDialog::ApplyChanges(vgui::PropertyDialog *this)
{
  this->OnCommand(this, a2: "Apply");
}

//------------------------------------------------------------------------------
// Address: 0x102D24F0
// Name: protected: virtual void vgui::PropertyDialog::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyDialog::PerformLayout(vgui::PropertyDialog *this)
{
  int m_iSheetInsetBottom; // edi
  vgui::ISchemeManager *v3; // ebx
  vgui::PropertyDialog_vtbl *v4; // edx
  int v5; // eax
  vgui::PropertyDialog_vtbl *v6; // edx
  int v7; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // eax
  vgui::ISchemeManager *v9; // edi
  vgui::ISchemeManager_vtbl *v10; // ebx
  int v11; // eax
  int v12; // eax
  vgui::ISchemeManager *v13; // edi
  vgui::ISchemeManager_vtbl *v14; // ebx
  int v15; // eax
  int v16; // eax
  vgui::PropertyDialog_vtbl *v17; // edx
  vgui::ISchemeManager *v18; // edi
  vgui::ISchemeManager_vtbl *v19; // ebx
  int v20; // eax
  int v21; // eax
  vgui::ISchemeManager *v22; // edi
  vgui::PropertyDialog_vtbl *v23; // edx
  int v24; // eax
  int v25; // eax
  vgui::ISchemeManager *v26; // edi
  vgui::ISchemeManager_vtbl *v27; // ecx
  vgui::PropertyDialog_vtbl *v28; // edx
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v30; // eax
  vgui::Button *applyButton; // ecx
  vgui::Button_vtbl *v32; // edx
  int v33; // edi
  int tall; // [esp+Ch] [ebp-20h] BYREF
  int nBottomOffset; // [esp+10h] [ebp-1Ch]
  int y; // [esp+14h] [ebp-18h] BYREF
  int wide; // [esp+18h] [ebp-14h] BYREF
  int x; // [esp+1Ch] [ebp-10h] BYREF
  int nRightOffset; // [esp+20h] [ebp-Ch]
  int nButtonGap; // [esp+24h] [ebp-8h]
  int nButtonHeight; // [esp+28h] [ebp-4h]

  vgui::Frame::PerformLayout(this);
  m_iSheetInsetBottom = this->m_iSheetInsetBottom;
  if ( this->IsProportional(this) )
  {
    v3 = g_pVGuiSchemeManager;
    v4 = this->__vftable;
    nBottomOffset = (int)g_pVGuiSchemeManager->__vftable;
    v5 = ((int (__thiscall *)(vgui::PropertyDialog *, int))v4->GetScheme)(a1: this, a2: m_iSheetInsetBottom);
    m_iSheetInsetBottom = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(nBottomOffset + 52))(a1: v3, a2: v5);
  }
  this->GetClientArea(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  vgui::Panel::SetBounds(this: this->_propertySheet, x, y, wide, tall: tall - m_iSheetInsetBottom);
  v6 = this->__vftable;
  nRightOffset = 80;
  v7 = 72;
  nButtonGap = 80;
  IsProportional = v6->IsProportional;
  nBottomOffset = 28;
  nButtonHeight = 24;
  if ( IsProportional(this) )
  {
    v9 = g_pVGuiSchemeManager;
    v10 = g_pVGuiSchemeManager->__vftable;
    v11 = ((int (__thiscall *)(vgui::PropertyDialog *, int))this->GetScheme)(a1: this, a2: 80);
    v12 = ((int (__thiscall *)(vgui::ISchemeManager *, int))v10->GetProportionalScaledValueEx)(a1: v9, a2: v11);
    v13 = g_pVGuiSchemeManager;
    v14 = g_pVGuiSchemeManager->__vftable;
    nRightOffset = v12;
    v15 = ((int (__thiscall *)(vgui::PropertyDialog *, int))this->GetScheme)(a1: this, a2: 28);
    v16 = ((int (__thiscall *)(vgui::ISchemeManager *, int))v14->GetProportionalScaledValueEx)(a1: v13, a2: v15);
    v17 = this->__vftable;
    v18 = g_pVGuiSchemeManager;
    v19 = g_pVGuiSchemeManager->__vftable;
    nBottomOffset = v16;
    v20 = ((int (__thiscall *)(vgui::PropertyDialog *, int))v17->GetScheme)(a1: this, a2: 72);
    v21 = ((int (__thiscall *)(vgui::ISchemeManager *, int))v19->GetProportionalScaledValueEx)(a1: v18, a2: v20);
    v22 = g_pVGuiSchemeManager;
    v23 = this->__vftable;
    v7 = v21;
    nButtonGap = (int)g_pVGuiSchemeManager->__vftable;
    v24 = ((int (__thiscall *)(vgui::PropertyDialog *, int))v23->GetScheme)(a1: this, a2: 24);
    v25 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(nButtonGap + 52))(a1: v22, a2: v24);
    v26 = g_pVGuiSchemeManager;
    v27 = g_pVGuiSchemeManager->__vftable;
    v28 = this->__vftable;
    nButtonHeight = v25;
    GetScheme = v28->GetScheme;
    nButtonGap = (int)v27;
    v30 = ((int (__thiscall *)(vgui::PropertyDialog *, int))GetScheme)(a1: this, a2: 80);
    nButtonGap = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(nButtonGap + 52))(a1: v26, a2: v30);
  }
  applyButton = this->_applyButton;
  v32 = applyButton->__vftable;
  v33 = wide + x - nRightOffset;
  nRightOffset = tall + y - nBottomOffset;
  if ( v32->IsVisible(this: applyButton) )
  {
    vgui::Panel::SetBounds(this: this->_applyButton, x: v33, y: nRightOffset, wide: v7, tall: nButtonHeight);
    v33 -= nButtonGap;
  }
  if ( this->_cancelButton->IsVisible(this: this->_cancelButton) )
  {
    vgui::Panel::SetBounds(this: this->_cancelButton, x: v33, y: nRightOffset, wide: v7, tall: nButtonHeight);
    v33 -= nButtonGap;
  }
  vgui::Panel::SetBounds(this: this->_okButton, x: v33, y: nRightOffset, wide: v7, tall: nButtonHeight);
  this->_propertySheet->InvalidateLayout(this: this->_propertySheet, a2: false, a3: false);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x102D26F0
// Name: protected: virtual void vgui::PropertyDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyDialog::OnCommand(vgui::PropertyDialog *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "OK") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "Cancel") != 0 )
    {
      if ( _V_stricmp(s1: command, s2: "Apply") != 0 )
      {
        vgui::Frame::OnCommand(this, command);
      }
      else
      {
        this->OnOK(this, a2: true);
        this->_applyButton->SetEnabled(this: this->_applyButton, a2: false);
        this->InvalidateLayout(this, a2: false, a3: false);
      }
    }
    else
    {
      this->OnCancel(this);
      this->Close(this);
    }
  }
  else
  {
    if ( this->OnOK(this, a2: false) )
      this->OnCommand(this, a2: "Close");
    this->_applyButton->SetEnabled(this: this->_applyButton, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D27D0
// Name: protected: virtual void vgui::PropertyDialog::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyDialog::OnKeyCodeTyped(vgui::PropertyDialog *this, ButtonCode_t code)
{
  vgui::Frame::OnKeyCodeTyped(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x102D27E0
// Name: protected: virtual bool vgui::PropertyDialog::OnOK(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::PropertyDialog::OnOK(vgui::PropertyDialog *this, bool applyOnly)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  this->_propertySheet->ApplyChanges(this: this->_propertySheet);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ApplyChanges");
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102D2840
// Name: protected: virtual void vgui::PropertyDialog::ActivateBuildMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyDialog::ActivateBuildMode(vgui::PropertyDialog *this)
{
  vgui::Panel *v1; // eax
  void *v2; // eax

  v1 = this->GetActivePage(this);
  v2 = __RTDynamicCast(
         inptr: v1,
         VfDelta: 0,
         SrcType: &vgui::Panel `RTTI Type Descriptor',
         TargetType: &vgui::EditablePanel `RTTI Type Descriptor',
         isReference: 0);
  if ( v2 != nullptr )
    (*(void (__thiscall **)(void *))(*(_DWORD *)v2 + 860))(a1: v2);
}

//------------------------------------------------------------------------------
// Address: 0x102D2880
// Name: protected: virtual void vgui::PropertyDialog::RequestFocus(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyDialog::RequestFocus(vgui::PropertyDialog *this, int direction)
{
  this->_propertySheet->RequestFocus(this: this->_propertySheet, a2: direction);
}

//------------------------------------------------------------------------------
// Address: 0x102D28D0
// Name: protected: virtual void vgui::PropertyDialog::OnApplyButtonEnable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyDialog::OnApplyButtonEnable(vgui::PropertyDialog *this)
{
  if ( !this->_applyButton->IsEnabled(this: this->_applyButton) )
  {
    this->_applyButton->SetEnabled(this: this->_applyButton, a2: true);
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D2910
// Name: public: static void vgui::PropertyDialog::PanelMessageFunc_OnApplyButtonEnable::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyDialog::PanelMessageFunc_OnApplyButtonEnable::InitVar(int a1@<ebp>)
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
  if ( !`vgui::PropertyDialog::PanelMessageFunc_OnApplyButtonEnable::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyDialog::PanelMessageFunc_OnApplyButtonEnable::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "PropertyDialog");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ApplyButtonEnable";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D29A0
// Name: public: static void vgui::PropertyDialog::PanelAnimationVar_m_iSheetInsetBottom::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::PropertyDialog::PanelAnimationVar_m_iSheetInsetBottom::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`vgui::PropertyDialog::PanelAnimationVar_m_iSheetInsetBottom::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyDialog::PanelAnimationVar_m_iSheetInsetBottom::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "PropertyDialog");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "sheetinset_bottom";
    src.m_pszVariable = "m_iSheetInsetBottom";
    src.m_pszType = "int";
    src.m_pszDefaultValue = "32";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))vgui::PropertyDialog::GetVar_m_iSheetInsetBottom;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D2A00
// Name: public: vgui::PropertyDialog::PropertyDialog(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::PropertyDialog *__thiscall vgui::PropertyDialog::PropertyDialog(
        vgui::PropertyDialog *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::PropertySheet *v7; // eax
  vgui::PropertySheet *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::FocusNavGroup *FocusNavGroup; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  vgui::Button *v14; // eax
  vgui::Button *v15; // eax

  vgui::Frame::Frame(this, parent, panelName, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (vgui::PropertyDialog_vtbl *)&vgui::PropertyDialog::`vftable';
  if ( `vgui::PropertyDialog::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::PropertyDialog::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "PropertyDialog");
    v4->pfnClassName = vgui::PropertyDialog::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Frame");
  }
  if ( `vgui::PropertyDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::PropertyDialog::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "PropertyDialog");
    v5->pfnClassName = vgui::PropertyDialog::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `vgui::PropertyDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::PropertyDialog::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "PropertyDialog");
    v6->pfnClassName = vgui::PropertyDialog::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  }
  vgui::PropertyDialog::PanelMessageFunc_OnApplyButtonEnable::InitVar();
  vgui::PropertyDialog::PanelAnimationVar_m_iSheetInsetBottom::InitVar();
  v7 = (vgui::PropertySheet *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v7 != nullptr )
    v8 = vgui::PropertySheet::PropertySheet(this: v7, parent: this, panelName: "Sheet", draggableTabs: false);
  else
    v8 = nullptr;
  this->_propertySheet = v8;
  v8->AddActionSignalTarget_2(this: v8, a2: this);
  this->_propertySheet->SetTabPosition(this: this->_propertySheet, a2: 1);
  v9 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "OKButton",
            text: "#PropertyDialog_OK",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v10 = nullptr;
  this->_okButton = v10;
  v10->AddActionSignalTarget_2(this: v10, a2: this);
  this->_okButton->SetTabPosition(this: this->_okButton, a2: 2);
  this->_okButton->SetCommand(this: this->_okButton, a2: "OK");
  FocusNavGroup = vgui::EditablePanel::GetFocusNavGroup(this);
  FocusNavGroup->SetDefaultButton(this: FocusNavGroup, a2: this->_okButton);
  v12 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v12 != nullptr )
    v13 = vgui::Button::Button(
            this: v12,
            parent: this,
            panelName: "CancelButton",
            text: "#PropertyDialog_Cancel",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v13 = nullptr;
  this->_cancelButton = v13;
  v13->AddActionSignalTarget_2(this: v13, a2: this);
  this->_cancelButton->SetTabPosition(this: this->_cancelButton, a2: 3);
  this->_cancelButton->SetCommand(this: this->_cancelButton, a2: "Cancel");
  v14 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v14 != nullptr )
    v15 = vgui::Button::Button(
            this: v14,
            parent: this,
            panelName: "ApplyButton",
            text: "#PropertyDialog_Apply",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v15 = nullptr;
  this->_applyButton = v15;
  v15->AddActionSignalTarget_2(this: v15, a2: this);
  this->_applyButton->SetTabPosition(this: this->_applyButton, a2: 4);
  this->_applyButton->SetVisible(this: this->_applyButton, a2: false);
  this->_applyButton->SetEnabled(this: this->_applyButton, a2: false);
  this->_applyButton->SetCommand(this: this->_applyButton, a2: "Apply");
  vgui::Frame::SetSizeable(this, state: false);
  return this;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102D2500
// Name: private: static void __near * vgui::PropertyDialog::GetVar_m_iSheetInsetBottom(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
int *__cdecl vgui::PropertyDialog::GetVar_m_iSheetInsetBottom(vgui::Panel *panel)
{
  return &panel[1].m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount;
}

//------------------------------------------------------------------------------
// Address: 0x102D2510
// Name: public: virtual vgui::PropertyDialog::~PropertyDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyDialog::~PropertyDialog(vgui::PropertyDialog *this)
{
  this->__vftable = (vgui::PropertyDialog_vtbl *)&vgui::PropertyDialog::`vftable';
  vgui::Frame::~Frame(this);
}

//------------------------------------------------------------------------------
// Address: 0x102D2530
// Name: public: virtual void vgui::PropertyDialog::AddPage(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyDialog::AddPage(vgui::PropertyDialog *this, vgui::Panel *page, const char *title)
{
  this->_propertySheet->AddPage(this: this->_propertySheet, a2: page, a3: title, a4: nullptr, a5: false, a6: -1);
}

//------------------------------------------------------------------------------
// Address: 0x102D2560
// Name: public: virtual void vgui::PropertyDialog::ResetAllData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyDialog::ResetAllData(vgui::PropertyDialog *this)
{
  this->_propertySheet->ResetAllData(this: this->_propertySheet);
}

//------------------------------------------------------------------------------
// Address: 0x102D2570
// Name: public: virtual void vgui::PropertyDialog::ApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyDialog::ApplyChanges(vgui::PropertyDialog *this)
{
  this->OnCommand(this, a2: "Apply");
}

//------------------------------------------------------------------------------
// Address: 0x102D2580
// Name: protected: virtual void vgui::PropertyDialog::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyDialog::PerformLayout(vgui::PropertyDialog *this)
{
  int m_iSheetInsetBottom; // edi
  vgui::ISchemeManager *v3; // ebx
  vgui::PropertyDialog_vtbl *v4; // edx
  int v5; // eax
  vgui::PropertyDialog_vtbl *v6; // edx
  int v7; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // eax
  vgui::ISchemeManager *v9; // edi
  vgui::ISchemeManager_vtbl *v10; // ebx
  int v11; // eax
  int v12; // eax
  vgui::ISchemeManager *v13; // edi
  vgui::ISchemeManager_vtbl *v14; // ebx
  int v15; // eax
  int v16; // eax
  vgui::PropertyDialog_vtbl *v17; // edx
  vgui::ISchemeManager *v18; // edi
  vgui::ISchemeManager_vtbl *v19; // ebx
  int v20; // eax
  int v21; // eax
  vgui::ISchemeManager *v22; // edi
  vgui::PropertyDialog_vtbl *v23; // edx
  int v24; // eax
  int v25; // eax
  vgui::ISchemeManager *v26; // edi
  vgui::ISchemeManager_vtbl *v27; // ecx
  vgui::PropertyDialog_vtbl *v28; // edx
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v30; // eax
  vgui::Button *applyButton; // ecx
  vgui::Button_vtbl *v32; // edx
  int v33; // edi
  int tall; // [esp+Ch] [ebp-20h] BYREF
  int nBottomOffset; // [esp+10h] [ebp-1Ch]
  int y; // [esp+14h] [ebp-18h] BYREF
  int wide; // [esp+18h] [ebp-14h] BYREF
  int x; // [esp+1Ch] [ebp-10h] BYREF
  int nRightOffset; // [esp+20h] [ebp-Ch]
  int nButtonGap; // [esp+24h] [ebp-8h]
  int nButtonHeight; // [esp+28h] [ebp-4h]

  vgui::Frame::PerformLayout(this);
  m_iSheetInsetBottom = this->m_iSheetInsetBottom;
  if ( this->IsProportional(this) )
  {
    v3 = g_pVGuiSchemeManager;
    v4 = this->__vftable;
    nBottomOffset = (int)g_pVGuiSchemeManager->__vftable;
    v5 = ((int (__thiscall *)(vgui::PropertyDialog *, int))v4->GetScheme)(a1: this, a2: m_iSheetInsetBottom);
    m_iSheetInsetBottom = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(nBottomOffset + 52))(a1: v3, a2: v5);
  }
  this->GetClientArea(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  vgui::Panel::SetBounds(this: this->_propertySheet, x, y, wide, tall: tall - m_iSheetInsetBottom);
  v6 = this->__vftable;
  nRightOffset = 80;
  v7 = 72;
  nButtonGap = 80;
  IsProportional = v6->IsProportional;
  nBottomOffset = 28;
  nButtonHeight = 24;
  if ( IsProportional(this) )
  {
    v9 = g_pVGuiSchemeManager;
    v10 = g_pVGuiSchemeManager->__vftable;
    v11 = ((int (__thiscall *)(vgui::PropertyDialog *, int))this->GetScheme)(a1: this, a2: 80);
    v12 = ((int (__thiscall *)(vgui::ISchemeManager *, int))v10->GetProportionalScaledValueEx)(a1: v9, a2: v11);
    v13 = g_pVGuiSchemeManager;
    v14 = g_pVGuiSchemeManager->__vftable;
    nRightOffset = v12;
    v15 = ((int (__thiscall *)(vgui::PropertyDialog *, int))this->GetScheme)(a1: this, a2: 28);
    v16 = ((int (__thiscall *)(vgui::ISchemeManager *, int))v14->GetProportionalScaledValueEx)(a1: v13, a2: v15);
    v17 = this->__vftable;
    v18 = g_pVGuiSchemeManager;
    v19 = g_pVGuiSchemeManager->__vftable;
    nBottomOffset = v16;
    v20 = ((int (__thiscall *)(vgui::PropertyDialog *, int))v17->GetScheme)(a1: this, a2: 72);
    v21 = ((int (__thiscall *)(vgui::ISchemeManager *, int))v19->GetProportionalScaledValueEx)(a1: v18, a2: v20);
    v22 = g_pVGuiSchemeManager;
    v23 = this->__vftable;
    v7 = v21;
    nButtonGap = (int)g_pVGuiSchemeManager->__vftable;
    v24 = ((int (__thiscall *)(vgui::PropertyDialog *, int))v23->GetScheme)(a1: this, a2: 24);
    v25 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(nButtonGap + 52))(a1: v22, a2: v24);
    v26 = g_pVGuiSchemeManager;
    v27 = g_pVGuiSchemeManager->__vftable;
    v28 = this->__vftable;
    nButtonHeight = v25;
    GetScheme = v28->GetScheme;
    nButtonGap = (int)v27;
    v30 = ((int (__thiscall *)(vgui::PropertyDialog *, int))GetScheme)(a1: this, a2: 80);
    nButtonGap = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(nButtonGap + 52))(a1: v26, a2: v30);
  }
  applyButton = this->_applyButton;
  v32 = applyButton->__vftable;
  v33 = wide + x - nRightOffset;
  nRightOffset = tall + y - nBottomOffset;
  if ( v32->IsVisible(this: applyButton) )
  {
    vgui::Panel::SetBounds(this: this->_applyButton, x: v33, y: nRightOffset, wide: v7, tall: nButtonHeight);
    v33 -= nButtonGap;
  }
  if ( this->_cancelButton->IsVisible(this: this->_cancelButton) )
  {
    vgui::Panel::SetBounds(this: this->_cancelButton, x: v33, y: nRightOffset, wide: v7, tall: nButtonHeight);
    v33 -= nButtonGap;
  }
  vgui::Panel::SetBounds(this: this->_okButton, x: v33, y: nRightOffset, wide: v7, tall: nButtonHeight);
  this->_propertySheet->InvalidateLayout(this: this->_propertySheet, a2: false, a3: false);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x102D2780
// Name: protected: virtual void vgui::PropertyDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyDialog::OnCommand(vgui::PropertyDialog *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "OK") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "Cancel") != 0 )
    {
      if ( _V_stricmp(s1: command, s2: "Apply") != 0 )
      {
        vgui::Frame::OnCommand(this, command);
      }
      else
      {
        this->OnOK(this, a2: true);
        this->_applyButton->SetEnabled(this: this->_applyButton, a2: false);
        this->InvalidateLayout(this, a2: false, a3: false);
      }
    }
    else
    {
      this->OnCancel(this);
      this->Close(this);
    }
  }
  else
  {
    if ( this->OnOK(this, a2: false) )
      this->OnCommand(this, a2: "Close");
    this->_applyButton->SetEnabled(this: this->_applyButton, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D2860
// Name: protected: virtual void vgui::PropertyDialog::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyDialog::OnKeyCodeTyped(vgui::PropertyDialog *this, ButtonCode_t code)
{
  vgui::Frame::OnKeyCodeTyped(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x102D2870
// Name: protected: virtual bool vgui::PropertyDialog::OnOK(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::PropertyDialog::OnOK(vgui::PropertyDialog *this, bool applyOnly)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  this->_propertySheet->ApplyChanges(this: this->_propertySheet);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ApplyChanges");
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102D2960
// Name: protected: virtual void vgui::PropertyDialog::OnApplyButtonEnable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyDialog::OnApplyButtonEnable(vgui::PropertyDialog *this)
{
  if ( !this->_applyButton->IsEnabled(this: this->_applyButton) )
  {
    this->_applyButton->SetEnabled(this: this->_applyButton, a2: true);
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D2A30
// Name: public: static void vgui::PropertyDialog::PanelAnimationVar_m_iSheetInsetBottom::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::PropertyDialog::PanelAnimationVar_m_iSheetInsetBottom::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`vgui::PropertyDialog::PanelAnimationVar_m_iSheetInsetBottom::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyDialog::PanelAnimationVar_m_iSheetInsetBottom::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "PropertyDialog");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "sheetinset_bottom";
    src.m_pszVariable = "m_iSheetInsetBottom";
    src.m_pszType = "int";
    src.m_pszDefaultValue = "32";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))vgui::PropertyDialog::GetVar_m_iSheetInsetBottom;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D2A90
// Name: public: vgui::PropertyDialog::PropertyDialog(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::PropertyDialog *__thiscall vgui::PropertyDialog::PropertyDialog(
        vgui::PropertyDialog *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::PropertySheet *v7; // eax
  vgui::PropertySheet *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::FocusNavGroup *FocusNavGroup; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  vgui::Button *v14; // eax
  vgui::Button *v15; // eax

  vgui::Frame::Frame(this, parent, panelName, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (vgui::PropertyDialog_vtbl *)&vgui::PropertyDialog::`vftable';
  if ( `vgui::PropertyDialog::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::PropertyDialog::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: (void **)"PropertyDialog");
    v4->pfnClassName = vgui::PropertyDialog::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: (void **)"Frame");
  }
  if ( `vgui::PropertyDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::PropertyDialog::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "PropertyDialog");
    v5->pfnClassName = vgui::PropertyDialog::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `vgui::PropertyDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::PropertyDialog::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"PropertyDialog");
    v6->pfnClassName = vgui::PropertyDialog::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: (void **)"Frame");
  }
  vgui::PropertyDialog::PanelMessageFunc_OnApplyButtonEnable::InitVar();
  vgui::PropertyDialog::PanelAnimationVar_m_iSheetInsetBottom::InitVar();
  v7 = (vgui::PropertySheet *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v7 != nullptr )
    v8 = vgui::PropertySheet::PropertySheet(this: v7, parent: this, panelName: "Sheet", draggableTabs: false);
  else
    v8 = nullptr;
  this->_propertySheet = v8;
  v8->AddActionSignalTarget_2(this: v8, a2: this);
  this->_propertySheet->SetTabPosition(this: this->_propertySheet, a2: 1);
  v9 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "OKButton",
            text: "#PropertyDialog_OK",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v10 = nullptr;
  this->_okButton = v10;
  v10->AddActionSignalTarget_2(this: v10, a2: this);
  this->_okButton->SetTabPosition(this: this->_okButton, a2: 2);
  this->_okButton->SetCommand(this: this->_okButton, a2: "OK");
  FocusNavGroup = vgui::EditablePanel::GetFocusNavGroup(this);
  FocusNavGroup->SetDefaultButton(this: FocusNavGroup, a2: this->_okButton);
  v12 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v12 != nullptr )
    v13 = vgui::Button::Button(
            this: v12,
            parent: this,
            panelName: "CancelButton",
            text: "#PropertyDialog_Cancel",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v13 = nullptr;
  this->_cancelButton = v13;
  v13->AddActionSignalTarget_2(this: v13, a2: this);
  this->_cancelButton->SetTabPosition(this: this->_cancelButton, a2: 3);
  this->_cancelButton->SetCommand(this: this->_cancelButton, a2: "Cancel");
  v14 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v14 != nullptr )
    v15 = vgui::Button::Button(
            this: v14,
            parent: this,
            panelName: "ApplyButton",
            text: "#PropertyDialog_Apply",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v15 = nullptr;
  this->_applyButton = v15;
  v15->AddActionSignalTarget_2(this: v15, a2: this);
  this->_applyButton->SetTabPosition(this: this->_applyButton, a2: 4);
  this->_applyButton->SetVisible(this: this->_applyButton, a2: false);
  this->_applyButton->SetEnabled(this: this->_applyButton, a2: false);
  this->_applyButton->SetCommand(this: this->_applyButton, a2: "Apply");
  vgui::Frame::SetSizeable(this, state: false);
  return this;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x103A3900
// Name: public: virtual class vgui::PropertySheet __near * vgui::PropertyDialog::GetPropertySheet(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PropertySheet *__thiscall vgui::PropertyDialog::GetPropertySheet(vgui::PropertyDialog *this)
{
  return this->_propertySheet;
}

//------------------------------------------------------------------------------
// Address: 0x103BEC90
// Name: public: static char const __near * vgui::PropertyDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::PropertyDialog::GetPanelClassName()
{
  return "PropertyDialog";
}

//------------------------------------------------------------------------------
// Address: 0x103BECA0
// Name: private: static void __near * vgui::PropertyDialog::GetVar_m_iSheetInsetBottom(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
int *__cdecl vgui::PropertyDialog::GetVar_m_iSheetInsetBottom(vgui::Panel *panel)
{
  return &panel[1].m_sNavDownName.m_Storage.m_Memory.m_nAllocationCount;
}

//------------------------------------------------------------------------------
// Address: 0x103BECB0
// Name: public: virtual vgui::PropertyDialog::~PropertyDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyDialog::~PropertyDialog(vgui::PropertyDialog *this)
{
  this->__vftable = (vgui::PropertyDialog_vtbl *)&vgui::PropertyDialog::`vftable';
  vgui::Frame::~Frame(this);
}

//------------------------------------------------------------------------------
// Address: 0x103BECC0
// Name: public: virtual class vgui::Panel __near * vgui::PropertyDialog::GetActivePage(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::PropertyDialog::GetActivePage(vgui::PropertyDialog *this)
{
  return this->_propertySheet->GetActivePage(this: this->_propertySheet);
}

//------------------------------------------------------------------------------
// Address: 0x103BECD0
// Name: public: virtual void vgui::PropertyDialog::AddPage(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyDialog::AddPage(vgui::PropertyDialog *this, vgui::Panel *page, const char *title)
{
  this->_propertySheet->AddPage(this: this->_propertySheet, a2: page, a3: title, a4: nullptr, a5: false, a6: -1);
}

//------------------------------------------------------------------------------
// Address: 0x103BED00
// Name: public: virtual void vgui::PropertyDialog::ResetAllData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyDialog::ResetAllData(vgui::PropertyDialog *this)
{
  this->_propertySheet->ResetAllData(this: this->_propertySheet);
}

//------------------------------------------------------------------------------
// Address: 0x103BED10
// Name: public: virtual void vgui::PropertyDialog::ApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyDialog::ApplyChanges(vgui::PropertyDialog *this)
{
  this->OnCommand(this, a2: "Apply");
}

//------------------------------------------------------------------------------
// Address: 0x103BED20
// Name: protected: virtual void vgui::PropertyDialog::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyDialog::PerformLayout(vgui::PropertyDialog *this)
{
  int m_iSheetInsetBottom; // edi
  vgui::ISchemeManager *v3; // ebx
  vgui::PropertyDialog_vtbl *v4; // edx
  int v5; // eax
  vgui::PropertyDialog_vtbl *v6; // edx
  int v7; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // eax
  vgui::ISchemeManager *v9; // edi
  vgui::ISchemeManager_vtbl *v10; // ebx
  int v11; // eax
  int v12; // eax
  vgui::ISchemeManager *v13; // edi
  vgui::ISchemeManager_vtbl *v14; // ebx
  int v15; // eax
  int v16; // eax
  vgui::PropertyDialog_vtbl *v17; // edx
  vgui::ISchemeManager *v18; // edi
  vgui::ISchemeManager_vtbl *v19; // ebx
  int v20; // eax
  int v21; // eax
  vgui::ISchemeManager *v22; // edi
  vgui::PropertyDialog_vtbl *v23; // edx
  int v24; // eax
  int v25; // eax
  vgui::ISchemeManager *v26; // edi
  vgui::ISchemeManager_vtbl *v27; // ecx
  vgui::PropertyDialog_vtbl *v28; // edx
  unsigned int (__thiscall *GetScheme)(vgui::IClientPanel *); // eax
  int v30; // eax
  vgui::Button *applyButton; // ecx
  vgui::Button_vtbl *v32; // edx
  int v33; // edi
  int tall; // [esp+Ch] [ebp-20h] BYREF
  int nBottomOffset; // [esp+10h] [ebp-1Ch]
  int y; // [esp+14h] [ebp-18h] BYREF
  int wide; // [esp+18h] [ebp-14h] BYREF
  int x; // [esp+1Ch] [ebp-10h] BYREF
  int nRightOffset; // [esp+20h] [ebp-Ch]
  int nButtonGap; // [esp+24h] [ebp-8h]
  int nButtonHeight; // [esp+28h] [ebp-4h]

  vgui::Frame::PerformLayout(this);
  m_iSheetInsetBottom = this->m_iSheetInsetBottom;
  if ( this->IsProportional(this) )
  {
    v3 = g_pVGuiSchemeManager;
    v4 = this->__vftable;
    nBottomOffset = (int)g_pVGuiSchemeManager->__vftable;
    v5 = ((int (__thiscall *)(vgui::PropertyDialog *, int))v4->GetScheme)(a1: this, a2: m_iSheetInsetBottom);
    m_iSheetInsetBottom = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(nBottomOffset + 52))(a1: v3, a2: v5);
  }
  this->GetClientArea(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  vgui::Panel::SetBounds(this: this->_propertySheet, x, y, wide, tall: tall - m_iSheetInsetBottom);
  v6 = this->__vftable;
  nRightOffset = 80;
  v7 = 72;
  nButtonGap = 80;
  IsProportional = v6->IsProportional;
  nBottomOffset = 28;
  nButtonHeight = 24;
  if ( IsProportional(this) )
  {
    v9 = g_pVGuiSchemeManager;
    v10 = g_pVGuiSchemeManager->__vftable;
    v11 = ((int (__thiscall *)(vgui::PropertyDialog *, int))this->GetScheme)(a1: this, a2: 80);
    v12 = ((int (__thiscall *)(vgui::ISchemeManager *, int))v10->GetProportionalScaledValueEx)(a1: v9, a2: v11);
    v13 = g_pVGuiSchemeManager;
    v14 = g_pVGuiSchemeManager->__vftable;
    nRightOffset = v12;
    v15 = ((int (__thiscall *)(vgui::PropertyDialog *, int))this->GetScheme)(a1: this, a2: 28);
    v16 = ((int (__thiscall *)(vgui::ISchemeManager *, int))v14->GetProportionalScaledValueEx)(a1: v13, a2: v15);
    v17 = this->__vftable;
    v18 = g_pVGuiSchemeManager;
    v19 = g_pVGuiSchemeManager->__vftable;
    nBottomOffset = v16;
    v20 = ((int (__thiscall *)(vgui::PropertyDialog *, int))v17->GetScheme)(a1: this, a2: 72);
    v21 = ((int (__thiscall *)(vgui::ISchemeManager *, int))v19->GetProportionalScaledValueEx)(a1: v18, a2: v20);
    v22 = g_pVGuiSchemeManager;
    v23 = this->__vftable;
    v7 = v21;
    nButtonGap = (int)g_pVGuiSchemeManager->__vftable;
    v24 = ((int (__thiscall *)(vgui::PropertyDialog *, int))v23->GetScheme)(a1: this, a2: 24);
    v25 = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(nButtonGap + 52))(a1: v22, a2: v24);
    v26 = g_pVGuiSchemeManager;
    v27 = g_pVGuiSchemeManager->__vftable;
    v28 = this->__vftable;
    nButtonHeight = v25;
    GetScheme = v28->GetScheme;
    nButtonGap = (int)v27;
    v30 = ((int (__thiscall *)(vgui::PropertyDialog *, int))GetScheme)(a1: this, a2: 80);
    nButtonGap = (*(int (__thiscall **)(vgui::ISchemeManager *, int))(nButtonGap + 52))(a1: v26, a2: v30);
  }
  applyButton = this->_applyButton;
  v32 = applyButton->__vftable;
  v33 = wide + x - nRightOffset;
  nRightOffset = tall + y - nBottomOffset;
  if ( v32->IsVisible(this: applyButton) )
  {
    vgui::Panel::SetBounds(this: this->_applyButton, x: v33, y: nRightOffset, wide: v7, tall: nButtonHeight);
    v33 -= nButtonGap;
  }
  if ( this->_cancelButton->IsVisible(this: this->_cancelButton) )
  {
    vgui::Panel::SetBounds(this: this->_cancelButton, x: v33, y: nRightOffset, wide: v7, tall: nButtonHeight);
    v33 -= nButtonGap;
  }
  vgui::Panel::SetBounds(this: this->_okButton, x: v33, y: nRightOffset, wide: v7, tall: nButtonHeight);
  this->_propertySheet->InvalidateLayout(this: this->_propertySheet, a2: false, a3: false);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x103BEF20
// Name: protected: virtual void vgui::PropertyDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyDialog::OnCommand(vgui::PropertyDialog *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "OK") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "Cancel") != 0 )
    {
      if ( _V_stricmp(s1: command, s2: "Apply") != 0 )
      {
        vgui::Frame::OnCommand(this, command);
      }
      else
      {
        this->OnOK(this, a2: true);
        this->_applyButton->SetEnabled(this: this->_applyButton, a2: false);
        this->InvalidateLayout(this, a2: false, a3: false);
      }
    }
    else
    {
      this->OnCancel(this);
      this->Close(this);
    }
  }
  else
  {
    if ( this->OnOK(this, a2: false) )
      this->OnCommand(this, a2: "Close");
    this->_applyButton->SetEnabled(this: this->_applyButton, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BF000
// Name: protected: virtual void vgui::PropertyDialog::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyDialog::OnKeyCodeTyped(vgui::PropertyDialog *this, unsigned int code)
{
  vgui::Frame::OnKeyCodeTyped(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x103BF010
// Name: protected: virtual bool vgui::PropertyDialog::OnOK(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::PropertyDialog::OnOK(vgui::PropertyDialog *this, bool applyOnly)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  this->_propertySheet->ApplyChanges(this: this->_propertySheet);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ApplyChanges");
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103BF070
// Name: protected: virtual void vgui::PropertyDialog::ActivateBuildMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyDialog::ActivateBuildMode(vgui::PropertyDialog *this)
{
  vgui::Panel *v1; // eax
  void *v2; // eax

  v1 = this->GetActivePage(this);
  v2 = __RTDynamicCast(
         inptr: v1,
         VfDelta: 0,
         SrcType: &vgui::Panel `RTTI Type Descriptor',
         TargetType: &vgui::EditablePanel `RTTI Type Descriptor',
         isReference: 0);
  if ( v2 != nullptr )
    (*(void (__thiscall **)(void *))(*(_DWORD *)v2 + 860))(a1: v2);
}

//------------------------------------------------------------------------------
// Address: 0x103BF0B0
// Name: public: void vgui::PropertyDialog::SetOKButtonText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyDialog::SetOKButtonText(vgui::PropertyDialog *this, const char *text)
{
  this->_okButton->SetText(this: this->_okButton, a2: text);
}

//------------------------------------------------------------------------------
// Address: 0x103BF0D0
// Name: public: void vgui::PropertyDialog::SetApplyButtonVisible(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyDialog::SetApplyButtonVisible(vgui::PropertyDialog *this, BOOL state)
{
  this->_applyButton->SetVisible(this: this->_applyButton, a2: state);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x103BF100
// Name: protected: void vgui::PropertyDialog::EnableApplyButton(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyDialog::EnableApplyButton(vgui::PropertyDialog *this, BOOL bEnable)
{
  this->_applyButton->SetEnabled(this: this->_applyButton, a2: bEnable);
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x103BF130
// Name: protected: virtual void vgui::PropertyDialog::RequestFocus(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyDialog::RequestFocus(vgui::PropertyDialog *this, int direction)
{
  this->_propertySheet->RequestFocus(this: this->_propertySheet, a2: direction);
}

//------------------------------------------------------------------------------
// Address: 0x103BF150
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::PropertyDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::PropertyDialog::GetMessageMap(vgui::PropertyDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::PropertyDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::PropertyDialog::GetMessageMap'::`2'::s_pMap;
  `vgui::PropertyDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "PropertyDialog");
  `vgui::PropertyDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103BF180
// Name: public: virtual struct PanelAnimationMap __near * vgui::PropertyDialog::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::PropertyDialog::GetAnimMap(vgui::PropertyDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "PropertyDialog");
}

//------------------------------------------------------------------------------
// Address: 0x103BF190
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::PropertyDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::PropertyDialog::GetKBMap(vgui::PropertyDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::PropertyDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::PropertyDialog::GetKBMap'::`2'::s_pMap;
  `vgui::PropertyDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "PropertyDialog");
  `vgui::PropertyDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103BF1F0
// Name: protected: virtual void vgui::PropertyDialog::OnApplyButtonEnable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::PropertyDialog::OnApplyButtonEnable(vgui::PropertyDialog *this)
{
  if ( !this->_applyButton->IsEnabled(this: this->_applyButton) )
  {
    this->_applyButton->SetEnabled(this: this->_applyButton, a2: true);
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BF230
// Name: public: static void vgui::PropertyDialog::PanelMessageFunc_OnApplyButtonEnable::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::PropertyDialog::PanelMessageFunc_OnApplyButtonEnable::InitVar(int a1@<ebp>)
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
  if ( !`vgui::PropertyDialog::PanelMessageFunc_OnApplyButtonEnable::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyDialog::PanelMessageFunc_OnApplyButtonEnable::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "PropertyDialog");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ApplyButtonEnable";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BF2C0
// Name: public: static void vgui::PropertyDialog::PanelAnimationVar_m_iSheetInsetBottom::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl vgui::PropertyDialog::PanelAnimationVar_m_iSheetInsetBottom::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`vgui::PropertyDialog::PanelAnimationVar_m_iSheetInsetBottom::InitVar'::`2'::bAdded )
  {
    `vgui::PropertyDialog::PanelAnimationVar_m_iSheetInsetBottom::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "PropertyDialog");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "sheetinset_bottom";
    src.m_pszVariable = "m_iSheetInsetBottom";
    src.m_pszType = "int";
    src.m_pszDefaultValue = "32";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))vgui::PropertyDialog::GetVar_m_iSheetInsetBottom;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BF320
// Name: public: vgui::PropertyDialog::PropertyDialog(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::PropertyDialog *__thiscall vgui::PropertyDialog::PropertyDialog(
        vgui::PropertyDialog *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::PropertySheet *v7; // eax
  vgui::PropertySheet *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::FocusNavGroup *FocusNavGroup; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  vgui::Button *v14; // eax
  vgui::Button *v15; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName, showTaskbarIcon: 1, bPopup: true);
  this->__vftable = (vgui::PropertyDialog_vtbl *)&vgui::PropertyDialog::`vftable';
  if ( `vgui::PropertyDialog::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::PropertyDialog::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "PropertyDialog");
    v4->pfnClassName = vgui::PropertyDialog::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Frame");
  }
  if ( `vgui::PropertyDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::PropertyDialog::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "PropertyDialog");
    v5->pfnClassName = vgui::PropertyDialog::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Frame");
  }
  if ( `vgui::PropertyDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::PropertyDialog::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "PropertyDialog");
    v6->pfnClassName = vgui::PropertyDialog::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  }
  vgui::PropertyDialog::PanelMessageFunc_OnApplyButtonEnable::InitVar(a1: (int)&savedregs);
  vgui::PropertyDialog::PanelAnimationVar_m_iSheetInsetBottom::InitVar();
  v7 = (vgui::PropertySheet *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v7 != nullptr )
    v8 = vgui::PropertySheet::PropertySheet(this: v7, parent: this, panelName: "Sheet", draggableTabs: false);
  else
    v8 = nullptr;
  this->_propertySheet = v8;
  v8->AddActionSignalTarget_2(this: v8, a2: this);
  this->_propertySheet->SetTabPosition(this: this->_propertySheet, a2: 1);
  v9 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "OKButton",
            text: "#PropertyDialog_OK",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v10 = nullptr;
  this->_okButton = v10;
  v10->AddActionSignalTarget_2(this: v10, a2: this);
  this->_okButton->SetTabPosition(this: this->_okButton, a2: 2);
  this->_okButton->SetCommand(this: this->_okButton, a2: "OK");
  FocusNavGroup = vgui::EditablePanel::GetFocusNavGroup(this);
  FocusNavGroup->SetDefaultButton(this: FocusNavGroup, a2: this->_okButton);
  v12 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v12 != nullptr )
    v13 = vgui::Button::Button(
            this: v12,
            parent: this,
            panelName: "CancelButton",
            text: "#PropertyDialog_Cancel",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v13 = nullptr;
  this->_cancelButton = v13;
  v13->AddActionSignalTarget_2(this: v13, a2: this);
  this->_cancelButton->SetTabPosition(this: this->_cancelButton, a2: 3);
  this->_cancelButton->SetCommand(this: this->_cancelButton, a2: "Cancel");
  v14 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v14 != nullptr )
    v15 = vgui::Button::Button(
            this: v14,
            parent: this,
            panelName: "ApplyButton",
            text: "#PropertyDialog_Apply",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v15 = nullptr;
  this->_applyButton = v15;
  v15->AddActionSignalTarget_2(this: v15, a2: this);
  this->_applyButton->SetTabPosition(this: this->_applyButton, a2: 4);
  this->_applyButton->SetVisible(this: this->_applyButton, a2: false);
  this->_applyButton->SetEnabled(this: this->_applyButton, a2: false);
  this->_applyButton->SetCommand(this: this->_applyButton, a2: "Apply");
  vgui::Frame::SetSizeable(this, state: false);
  return this;
}

} // namespace client
