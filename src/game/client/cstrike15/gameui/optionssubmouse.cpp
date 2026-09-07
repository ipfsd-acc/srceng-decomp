// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/optionssubmouse.cpp
// Functions: 16
// ============================================================

#include "game\client\cstrike15\gameui\optionssubmouse.h"

//------------------------------------------------------------------------------
// Address: 0x10110110
// Name: protected: virtual void COptionsSubMouse::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubMouse::ApplySchemeSettings(vgui::RichTextInterior *this, int pScheme)
{
  vgui::Panel::ApplySchemeSettings(this, pScheme);
}

//------------------------------------------------------------------------------
// Address: 0x101DB490
// Name: public: static char const __near * COptionsSubMouse::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl COptionsSubMouse::GetPanelClassName()
{
  return "COptionsSubMouse";
}

//------------------------------------------------------------------------------
// Address: 0x101DB4A0
// Name: protected: virtual void COptionsSubMouse::OnCheckButtonChecked(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubMouse::OnCheckButtonChecked(COptionsSubMouse *this, vgui::Panel *panel)
{
  this->OnControlModified(this, a2: panel);
}

//------------------------------------------------------------------------------
// Address: 0x101DB4B0
// Name: public: virtual void COptionsSubMouse::OnApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubMouse::OnApplyChanges(COptionsSubMouse *this)
{
  bool v2; // al
  ConVarRef m_customacel; // [esp+4h] [ebp-8h] BYREF

  CCvarNegateCheckButton::ApplyChanges(this: this->m_pReverseMouseCheckBox);
  CCvarToggleCheckButton::ApplyChanges(this: this->m_pMouseFilterCheckBox);
  CCvarToggleCheckButton::ApplyChanges(this: this->m_pMouseRawCheckBox);
  CCvarToggleCheckButton::ApplyChanges(this: this->m_pJoystickCheckBox);
  CCvarToggleCheckButton::ApplyChanges(this: this->m_pJoystickSouthpawCheckBox);
  CCvarSlider::ApplyChanges(this: this->m_pMouseSensitivitySlider);
  CCvarSlider::ApplyChanges(this: this->m_pMouseAccelExponentSlider);
  CCvarToggleCheckButton::ApplyChanges(this: this->m_pQuickInfoCheckBox);
  CCvarToggleCheckButton::ApplyChanges(this: this->m_pReverseJoystickCheckBox);
  CCvarSlider::ApplyChanges(this: this->m_pJoyYawSensitivitySlider);
  CCvarSlider::ApplyChanges(this: this->m_pJoyPitchSensitivitySlider);
  engine->ClientCmd_Unrestricted(this: engine, a2: "joyadvancedupdate");
  engine->ClientCmd_Unrestricted(this: engine, a2: "exec userconfig.cfg\nhost_writeconfig\n");
  ConVarRef::ConVarRef(this: &m_customacel, pName: "m_customaccel");
  if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&m_customacel) )
  {
    v2 = this->m_pMouseAccelerationCheckBox->IsSelected(this: this->m_pMouseAccelerationCheckBox);
    m_customacel.m_pConVar->SetValue_2(this: m_customacel.m_pConVar, a2: v2 ? 3 : 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DB5A0
// Name: protected: virtual void COptionsSubMouse::OnTextChanged(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubMouse::OnTextChanged(COptionsSubMouse *this, vgui::TextEntry *panel)
{
  long double v3; // st7
  CCvarSlider *m_pMouseSensitivitySlider; // ecx
  long double v5; // st7
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  char buf[64]; // [esp+10h] [ebp-40h] BYREF
  float fValue; // [esp+58h] [ebp+8h]

  if ( panel == this->m_pMouseSensitivityLabel )
  {
    this->m_pMouseSensitivityLabel->GetText_2(this: this->m_pMouseSensitivityLabel, a2: buf, a3: 64);
    v3 = atof(nptr: buf);
    fValue = v3;
    if ( v3 < 1.0 )
      return;
    m_pMouseSensitivitySlider = this->m_pMouseSensitivitySlider;
    goto LABEL_7;
  }
  if ( panel == this->m_pMouseAccelExponentLabel )
  {
    this->m_pMouseAccelExponentLabel->GetText_2(this: this->m_pMouseAccelExponentLabel, a2: buf, a3: 64);
    v5 = atof(nptr: buf);
    fValue = v5;
    if ( v5 >= 1.0 )
    {
      m_pMouseSensitivitySlider = this->m_pMouseAccelExponentSlider;
LABEL_7:
      CCvarSlider::SetSliderValue(this: m_pMouseSensitivitySlider, fValue);
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
      {
        v7 = KeyValues::KeyValues(this: v6, setName: "ApplyButtonEnable");
        this->PostActionSignal(this, a2: v7);
      }
      else
      {
        this->PostActionSignal(this, a2: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DB690
// Name: protected: void COptionsSubMouse::UpdateAccelerationLabel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubMouse::UpdateAccelerationLabel(COptionsSubMouse *this)
{
  double SliderValue; // st7
  char buf[64]; // [esp+Ch] [ebp-40h] BYREF

  SliderValue = CCvarSlider::GetSliderValue(this: this->m_pMouseAccelExponentSlider);
  V_snprintf(pDest: buf, maxLen: 0x40u, pFormat: " %.2f", SliderValue);
  this->m_pMouseAccelExponentLabel->SetText(this: this->m_pMouseAccelExponentLabel, a2: buf);
}

//------------------------------------------------------------------------------
// Address: 0x101DB6E0
// Name: protected: void COptionsSubMouse::UpdateJoystickPanels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubMouse::UpdateJoystickPanels(COptionsSubMouse *this)
{
  bool bEnabled; // [esp+8h] [ebp-4h]

  bEnabled = this->m_pJoystickCheckBox->IsSelected(this: this->m_pJoystickCheckBox);
  this->m_pReverseJoystickCheckBox->SetEnabled(this: this->m_pReverseJoystickCheckBox, a2: bEnabled);
  this->m_pJoystickSouthpawCheckBox->SetEnabled(this: this->m_pJoystickSouthpawCheckBox, a2: bEnabled);
  this->m_pJoyYawSensitivitySlider->SetEnabled(this: this->m_pJoyYawSensitivitySlider, a2: bEnabled);
  this->m_pJoyYawSensitivityPreLabel->SetEnabled(this: this->m_pJoyYawSensitivityPreLabel, a2: bEnabled);
  this->m_pJoyPitchSensitivitySlider->SetEnabled(this: this->m_pJoyPitchSensitivitySlider, a2: bEnabled);
  this->m_pJoyPitchSensitivityPreLabel->SetEnabled(this: this->m_pJoyPitchSensitivityPreLabel, a2: bEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x101DB770
// Name: public: virtual struct vgui::PanelMessageMap __near * COptionsSubMouse::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall COptionsSubMouse::GetMessageMap(COptionsSubMouse *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`COptionsSubMouse::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `COptionsSubMouse::GetMessageMap'::`2'::s_pMap;
  `COptionsSubMouse::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "COptionsSubMouse");
  `COptionsSubMouse::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DB7A0
// Name: public: virtual struct PanelAnimationMap __near * COptionsSubMouse::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall COptionsSubMouse::GetAnimMap(COptionsSubMouse *this)
{
  return FindOrAddPanelAnimationMap(className: "COptionsSubMouse");
}

//------------------------------------------------------------------------------
// Address: 0x101DB7B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * COptionsSubMouse::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall COptionsSubMouse::GetKBMap(COptionsSubMouse *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`COptionsSubMouse::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `COptionsSubMouse::GetKBMap'::`2'::s_pMap;
  `COptionsSubMouse::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "COptionsSubMouse");
  `COptionsSubMouse::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101DB810
// Name: public: virtual void COptionsSubMouse::OnResetData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubMouse::OnResetData(COptionsSubMouse *this)
{
  ConVarRef m_customacel; // [esp+4h] [ebp-8h] BYREF

  CCvarNegateCheckButton::Reset(this: this->m_pReverseMouseCheckBox);
  CCvarToggleCheckButton::Reset(this: this->m_pMouseFilterCheckBox);
  CCvarToggleCheckButton::Reset(this: this->m_pMouseRawCheckBox);
  CCvarToggleCheckButton::Reset(this: this->m_pJoystickCheckBox);
  CCvarToggleCheckButton::Reset(this: this->m_pJoystickSouthpawCheckBox);
  CCvarSlider::Reset(this: this->m_pMouseSensitivitySlider);
  CCvarSlider::Reset(this: this->m_pMouseAccelExponentSlider);
  CCvarToggleCheckButton::Reset(this: this->m_pQuickInfoCheckBox);
  CCvarToggleCheckButton::Reset(this: this->m_pReverseJoystickCheckBox);
  CCvarSlider::Reset(this: this->m_pJoyYawSensitivitySlider);
  CCvarSlider::Reset(this: this->m_pJoyPitchSensitivitySlider);
  ConVarRef::ConVarRef(this: &m_customacel, pName: "m_customaccel");
  if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&m_customacel) )
    this->m_pMouseAccelerationCheckBox->SetSelected(
      this: this->m_pMouseAccelerationCheckBox,
      a2: m_customacel.m_pConVarState->m_Value.m_nValue != 0);
}

//------------------------------------------------------------------------------
// Address: 0x101DB8D0
// Name: protected: virtual void COptionsSubMouse::OnControlModified(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubMouse::OnControlModified(COptionsSubMouse *this, CCvarToggleCheckButton *panel)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  CCvarSlider *m_pMouseSensitivitySlider; // ecx
  double SliderValue; // st7
  CCvarSlider *m_pMouseAccelExponentSlider; // ecx
  CCvarSlider_vtbl *v8; // edi
  bool v9; // al
  vgui::TextEntry_vtbl *v10; // edi
  bool v11; // al
  char pDest[64]; // [esp+14h] [ebp-40h] BYREF

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "ApplyButtonEnable");
  else
    v4 = nullptr;
  this->PostActionSignal(this, a2: v4);
  m_pMouseSensitivitySlider = this->m_pMouseSensitivitySlider;
  if ( panel == (CCvarToggleCheckButton *)m_pMouseSensitivitySlider
    && CCvarSlider::HasBeenModified(this: m_pMouseSensitivitySlider) )
  {
    SliderValue = CCvarSlider::GetSliderValue(this: this->m_pMouseSensitivitySlider);
    V_snprintf(pDest, maxLen: 0x40u, pFormat: " %.2f", SliderValue);
    this->m_pMouseSensitivityLabel->SetText(this: this->m_pMouseSensitivityLabel, a2: pDest);
  }
  else
  {
    m_pMouseAccelExponentSlider = this->m_pMouseAccelExponentSlider;
    if ( panel == (CCvarToggleCheckButton *)m_pMouseAccelExponentSlider
      && CCvarSlider::HasBeenModified(this: m_pMouseAccelExponentSlider) )
    {
      COptionsSubMouse::UpdateAccelerationLabel(this);
    }
    else if ( panel == this->m_pJoystickCheckBox )
    {
      COptionsSubMouse::UpdateJoystickPanels(this);
    }
    else if ( panel == this->m_pMouseAccelerationCheckBox )
    {
      v8 = this->m_pMouseAccelExponentSlider->__vftable;
      v9 = this->m_pMouseAccelerationCheckBox->IsSelected(this: this->m_pMouseAccelerationCheckBox);
      v8->SetEnabled(this: this->m_pMouseAccelExponentSlider, a2: v9);
      v10 = this->m_pMouseAccelExponentLabel->__vftable;
      v11 = this->m_pMouseAccelerationCheckBox->IsSelected(this: this->m_pMouseAccelerationCheckBox);
      v10->SetEnabled(this: this->m_pMouseAccelExponentLabel, a2: v11);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DBA00
// Name: public: static void COptionsSubMouse::PanelMessageFunc_OnControlModified::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COptionsSubMouse::PanelMessageFunc_OnControlModified::InitVar(int a1@<ebp>)
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
  if ( !`COptionsSubMouse::PanelMessageFunc_OnControlModified::InitVar'::`2'::bAdded )
  {
    `COptionsSubMouse::PanelMessageFunc_OnControlModified::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall COptionsSubMultiplayer::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COptionsSubMouse");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ControlModified";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x400000001LL;
    LODWORD(v4.m[2][2]) = "panel";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DBAA0
// Name: public: static void COptionsSubMouse::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COptionsSubMouse::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`COptionsSubMouse::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `COptionsSubMouse::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall COptionsSubMultiplayer::`vcall'{968,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COptionsSubMouse");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextChanged";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x400000001LL;
    LODWORD(v4.m[2][2]) = "panel";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DBB40
// Name: public: static void COptionsSubMouse::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COptionsSubMouse::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`COptionsSubMouse::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `COptionsSubMouse::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall COptionsSubMultiplayer::`vcall'{972,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COptionsSubMouse");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CheckButtonChecked";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x400000001LL;
    LODWORD(v4.m[2][2]) = "panel";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101DBBE0
// Name: public: COptionsSubMouse::COptionsSubMouse(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
COptionsSubMouse *__thiscall COptionsSubMouse::COptionsSubMouse(COptionsSubMouse *this, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  CCvarNegateCheckButton *v6; // eax
  CCvarNegateCheckButton *v7; // eax
  CCvarToggleCheckButton *v8; // eax
  CCvarToggleCheckButton *v9; // eax
  CCvarToggleCheckButton *v10; // eax
  CCvarToggleCheckButton *v11; // eax
  vgui::CheckButton *v12; // eax
  vgui::CheckButton *v13; // eax
  CCvarToggleCheckButton *v14; // eax
  CCvarToggleCheckButton *v15; // eax
  CCvarToggleCheckButton *v16; // eax
  CCvarToggleCheckButton *v17; // eax
  CCvarToggleCheckButton *v18; // eax
  CCvarToggleCheckButton *v19; // eax
  CCvarToggleCheckButton *v20; // eax
  CCvarToggleCheckButton *v21; // eax
  CCvarSlider *v22; // eax
  CCvarSlider *v23; // eax
  vgui::TextEntry *v24; // eax
  vgui::TextEntry *v25; // eax
  CCvarSlider *v26; // eax
  CCvarSlider *v27; // eax
  vgui::TextEntry *v28; // eax
  vgui::TextEntry *v29; // eax
  CCvarSlider *v30; // eax
  CCvarSlider *v31; // eax
  vgui::Label *v32; // eax
  vgui::Label *v33; // eax
  CCvarSlider *v34; // eax
  CCvarSlider *v35; // eax
  vgui::Label *v36; // eax
  vgui::Label *v37; // eax
  double SliderValue; // st7
  double v39; // st7
  char pDest[64]; // [esp+20h] [ebp-40h] BYREF

  vgui::PropertyPage::PropertyPage(this, parent, panelName: nullptr);
  this->__vftable = (COptionsSubMouse_vtbl *)&COptionsSubMouse::`vftable';
  if ( `COptionsSubMouse::ChainToMap'::`2'::chained == 0 )
  {
    `COptionsSubMouse::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "COptionsSubMouse");
    v3->pfnClassName = COptionsSubMouse::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::PropertyPage");
  }
  if ( `COptionsSubMouse::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `COptionsSubMouse::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "COptionsSubMouse");
    v4->pfnClassName = COptionsSubMouse::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::PropertyPage");
  }
  if ( `COptionsSubMouse::KB_ChainToMap'::`2'::chained == 0 )
  {
    `COptionsSubMouse::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "COptionsSubMouse");
    v5->pfnClassName = COptionsSubMouse::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::PropertyPage");
  }
  COptionsSubMouse::PanelMessageFunc_OnControlModified::InitVar();
  COptionsSubMouse::PanelMessageFunc_OnTextChanged::InitVar();
  COptionsSubMouse::PanelMessageFunc_OnCheckButtonChecked::InitVar();
  v6 = (CCvarNegateCheckButton *)MemAlloc_Alloc(nSize: 0x224u);
  if ( v6 != nullptr )
    v7 = CCvarNegateCheckButton::CCvarNegateCheckButton(
           this: v6,
           parent: this,
           panelName: "ReverseMouse",
           text: "#GameUI_ReverseMouse",
           cvarname: "m_pitch");
  else
    v7 = nullptr;
  this->m_pReverseMouseCheckBox = v7;
  v8 = (CCvarToggleCheckButton *)MemAlloc_Alloc(nSize: 0x224u);
  if ( v8 != nullptr )
    v9 = CCvarToggleCheckButton::CCvarToggleCheckButton(
           this: v8,
           parent: this,
           panelName: "MouseFilter",
           text: "#GameUI_MouseFilter",
           cvarname: "m_filter");
  else
    v9 = nullptr;
  this->m_pMouseFilterCheckBox = v9;
  v10 = (CCvarToggleCheckButton *)MemAlloc_Alloc(nSize: 0x224u);
  if ( v10 != nullptr )
    v11 = CCvarToggleCheckButton::CCvarToggleCheckButton(
            this: v10,
            parent: this,
            panelName: "MouseRaw",
            text: "#GameUI_MouseRaw",
            cvarname: "m_rawinput");
  else
    v11 = nullptr;
  this->m_pMouseRawCheckBox = v11;
  v12 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v12 != nullptr )
    v13 = vgui::CheckButton::CheckButton(
            this: v12,
            parent: this,
            panelName: "MouseAccelerationCheckbox",
            text: "#GameUI_MouseCustomAccel");
  else
    v13 = nullptr;
  this->m_pMouseAccelerationCheckBox = v13;
  v14 = (CCvarToggleCheckButton *)MemAlloc_Alloc(nSize: 0x224u);
  if ( v14 != nullptr )
    v15 = CCvarToggleCheckButton::CCvarToggleCheckButton(
            this: v14,
            parent: this,
            panelName: "Joystick",
            text: "#GameUI_Joystick",
            cvarname: "joystick");
  else
    v15 = nullptr;
  this->m_pJoystickCheckBox = v15;
  v16 = (CCvarToggleCheckButton *)MemAlloc_Alloc(nSize: 0x224u);
  if ( v16 != nullptr )
    v17 = CCvarToggleCheckButton::CCvarToggleCheckButton(
            this: v16,
            parent: this,
            panelName: "JoystickSouthpaw",
            text: "#GameUI_JoystickSouthpaw",
            cvarname: "joy_movement_stick");
  else
    v17 = nullptr;
  this->m_pJoystickSouthpawCheckBox = v17;
  v18 = (CCvarToggleCheckButton *)MemAlloc_Alloc(nSize: 0x224u);
  if ( v18 != nullptr )
    v19 = CCvarToggleCheckButton::CCvarToggleCheckButton(
            this: v18,
            parent: this,
            panelName: "ReverseJoystick",
            text: "#GameUI_ReverseJoystick",
            cvarname: "joy_inverty");
  else
    v19 = nullptr;
  this->m_pReverseJoystickCheckBox = v19;
  v20 = (CCvarToggleCheckButton *)MemAlloc_Alloc(nSize: 0x224u);
  if ( v20 != nullptr )
    v21 = CCvarToggleCheckButton::CCvarToggleCheckButton(
            this: v20,
            parent: this,
            panelName: "HudQuickInfo",
            text: "#GameUI_HudQuickInfo",
            cvarname: "hud_quickinfo");
  else
    v21 = nullptr;
  this->m_pQuickInfoCheckBox = v21;
  v22 = (CCvarSlider *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v22 != nullptr )
    v23 = CCvarSlider::CCvarSlider(
            this: v22,
            parent: this,
            panelName: "Slider",
            caption: "#GameUI_MouseSensitivity",
            minValue: 0.1,
            maxValue: 6.0,
            cvarname: "sensitivity",
            bAllowOutOfRange: true);
  else
    v23 = nullptr;
  this->m_pMouseSensitivitySlider = v23;
  v24 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v24 != nullptr )
    v25 = vgui::TextEntry::TextEntry(this: v24, parent: this, panelName: "SensitivityLabel");
  else
    v25 = nullptr;
  this->m_pMouseSensitivityLabel = v25;
  v25->AddActionSignalTarget_2(this: v25, a2: this);
  v26 = (CCvarSlider *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v26 != nullptr )
    v27 = CCvarSlider::CCvarSlider(
            this: v26,
            parent: this,
            panelName: "MouseAccelerationSlider",
            caption: "#GameUI_MouseAcceleration",
            minValue: 1.0,
            maxValue: 1.4,
            cvarname: "m_customaccel_exponent",
            bAllowOutOfRange: true);
  else
    v27 = nullptr;
  this->m_pMouseAccelExponentSlider = v27;
  v28 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v28 != nullptr )
    v29 = vgui::TextEntry::TextEntry(this: v28, parent: this, panelName: "MouseAccelerationLabel");
  else
    v29 = nullptr;
  this->m_pMouseAccelExponentLabel = v29;
  v29->AddActionSignalTarget_2(this: v29, a2: this);
  v30 = (CCvarSlider *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v30 != nullptr )
    v31 = CCvarSlider::CCvarSlider(
            this: v30,
            parent: this,
            panelName: "JoystickYawSlider",
            caption: "#GameUI_JoystickYawSensitivity",
            minValue: -0.5,
            maxValue: -7.0,
            cvarname: "joy_yawsensitivity",
            bAllowOutOfRange: true);
  else
    v31 = nullptr;
  this->m_pJoyYawSensitivitySlider = v31;
  v32 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v32 != nullptr )
    v33 = vgui::Label::Label(
            this: v32,
            parent: this,
            panelName: "JoystickYawSensitivityPreLabel",
            text: "#GameUI_JoystickLookSpeedYaw");
  else
    v33 = nullptr;
  this->m_pJoyYawSensitivityPreLabel = v33;
  v34 = (CCvarSlider *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v34 != nullptr )
    v35 = CCvarSlider::CCvarSlider(
            this: v34,
            parent: this,
            panelName: "JoystickPitchSlider",
            caption: "#GameUI_JoystickPitchSensitivity",
            minValue: 0.5,
            maxValue: 7.0,
            cvarname: "joy_pitchsensitivity",
            bAllowOutOfRange: true);
  else
    v35 = nullptr;
  this->m_pJoyPitchSensitivitySlider = v35;
  v36 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v36 != nullptr )
    v37 = vgui::Label::Label(
            this: v36,
            parent: this,
            panelName: "JoystickPitchSensitivityPreLabel",
            text: "#GameUI_JoystickLookSpeedPitch");
  else
    v37 = nullptr;
  this->m_pJoyPitchSensitivityPreLabel = v37;
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "Resource\\OptionsSubMouse.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  SliderValue = CCvarSlider::GetSliderValue(this: this->m_pMouseSensitivitySlider);
  V_snprintf(pDest, maxLen: 0x40u, pFormat: " %.2f", SliderValue);
  this->m_pMouseSensitivityLabel->SetText(this: this->m_pMouseSensitivityLabel, a2: pDest);
  v39 = CCvarSlider::GetSliderValue(this: this->m_pMouseAccelExponentSlider);
  V_snprintf(pDest, maxLen: 0x40u, pFormat: " %.2f", v39);
  this->m_pMouseAccelExponentLabel->SetText(this: this->m_pMouseAccelExponentLabel, a2: pDest);
  COptionsSubMouse::UpdateJoystickPanels(this);
  return this;
}
