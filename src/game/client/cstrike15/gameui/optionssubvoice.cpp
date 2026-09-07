// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/optionssubvoice.cpp
// Functions: 23
// ============================================================

#include "game\client\cstrike15\gameui\optionssubvoice.h"

//------------------------------------------------------------------------------
// Address: 0x101D30A0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::PropertyPage::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::PropertyPage::GetMessageMap(vgui::PropertyPage *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::PropertyPage::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::PropertyPage::GetMessageMap'::`2'::s_pMap;
  `vgui::PropertyPage::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "PropertyPage");
  `vgui::PropertyPage::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D30D0
// Name: public: virtual struct PanelAnimationMap __near * vgui::PropertyPage::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::PropertyPage::GetAnimMap(vgui::PropertyPage *this)
{
  return FindOrAddPanelAnimationMap(className: "PropertyPage");
}

//------------------------------------------------------------------------------
// Address: 0x101D30E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::PropertyPage::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::PropertyPage::GetKBMap(vgui::PropertyPage *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::PropertyPage::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::PropertyPage::GetKBMap'::`2'::s_pMap;
  `vgui::PropertyPage::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "PropertyPage");
  `vgui::PropertyPage::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E47E0
// Name: public: static char const __near * COptionsSubVoice::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl COptionsSubVoice::GetPanelClassName()
{
  return "COptionsSubVoice";
}

//------------------------------------------------------------------------------
// Address: 0x101E47F0
// Name: public: virtual void COptionsSubVoice::OnResetData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubVoice::OnResetData(COptionsSubVoice *this)
{
  IVoiceTweak_s *m_pVoiceTweak; // eax
  double v3; // st6
  bool v4; // sf
  bool v5; // of
  bool v6; // cf
  bool v7; // zf
  char v8; // pf
  char v9; // fl
  BOOL v10; // eax
  bool v11; // al
  CCvarSlider *m_pReceiveVolume; // ecx
  int SliderValue; // eax
  CCvarToggleCheckButton *m_pOpenMicEnableCheckButton; // ecx
  bool v15; // al
  CCvarToggleCheckButton *m_pVoiceEnableCheckButton; // ecx
  int v17; // [esp-4h] [ebp-Ch] BYREF
  int v18; // [esp+0h] [ebp-8h] BYREF
  float micVolume; // [esp+4h] [ebp-4h]

  m_pVoiceTweak = this->m_pVoiceTweak;
  if ( m_pVoiceTweak != nullptr )
  {
    micVolume = m_pVoiceTweak->GetControlFloat(a1: MicrophoneVolume);
    this->m_pMicrophoneVolume->SetValue(this: this->m_pMicrophoneVolume, a2: (int)(float)(micVolume * 100.0), a3: true);
    this->m_nMicVolumeValue = this->m_pMicrophoneVolume->GetValue(this: this->m_pMicrophoneVolume);
    v3 = ((double (__cdecl *)(int))this->m_pVoiceTweak->GetControlFloat)(a1: 2);
    v5 = __OFADD__(4, &v17);
    v4 = (int)&v18 < 0;
    v6 = v3 < 0.0;
    v8 = 0;
    v7 = v3 == 0.0;
    BYTE1(v10) = v9;
    LOBYTE(v10) = v3 != 0.0;
    this->m_pMicBoost->SetSelected(this: this->m_pMicBoost, a2: v10);
    v11 = this->m_pMicBoost->IsSelected(this: this->m_pMicBoost);
    m_pReceiveVolume = this->m_pReceiveVolume;
    this->m_bMicBoostSelected = v11;
    CCvarSlider::Reset(this: m_pReceiveVolume);
    this->m_fReceiveVolume = CCvarSlider::GetSliderValue(this: this->m_pReceiveVolume);
    CCvarSlider::Reset(this: this->m_pThresholdVolume);
    SliderValue = (int)CCvarSlider::GetSliderValue(this: this->m_pThresholdVolume);
    m_pOpenMicEnableCheckButton = this->m_pOpenMicEnableCheckButton;
    this->m_nVoiceThresholdValue = SliderValue;
    CCvarToggleCheckButton::Reset(this: m_pOpenMicEnableCheckButton);
    v15 = this->m_pOpenMicEnableCheckButton->IsSelected(this: this->m_pOpenMicEnableCheckButton);
    m_pVoiceEnableCheckButton = this->m_pVoiceEnableCheckButton;
    this->m_bOpenMicSelected = v15;
    CCvarToggleCheckButton::Reset(this: m_pVoiceEnableCheckButton);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E4910
// Name: private: virtual void COptionsSubVoice::OnSliderMoved(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubVoice::OnSliderMoved(COptionsSubVoice *this, int position)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  if ( this->m_pVoiceTweak != nullptr )
  {
    if ( this->m_pMicrophoneVolume->GetValue(this: this->m_pMicrophoneVolume) != this->m_nMicVolumeValue )
    {
      v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v3 != nullptr )
        v4 = KeyValues::KeyValues(this: v3, setName: "ApplyButtonEnable");
      else
        v4 = nullptr;
      this->PostActionSignal(this, a2: v4);
    }
    if ( CCvarSlider::GetSliderValue(this: this->m_pThresholdVolume) != (double)this->m_nVoiceThresholdValue )
    {
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
        v6 = KeyValues::KeyValues(this: v5, setName: "ApplyButtonEnable");
      else
        v6 = nullptr;
      this->PostActionSignal(this, a2: v6);
      CCvarSlider::ApplyChanges(this: this->m_pThresholdVolume);
      this->m_nVoiceThresholdValue = (int)CCvarSlider::GetSliderValue(this: this->m_pThresholdVolume);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E49E0
// Name: private: virtual void COptionsSubVoice::OnCheckButtonChecked(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubVoice::OnCheckButtonChecked(COptionsSubVoice *this, int state)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  if ( this->m_pVoiceTweak != nullptr )
  {
    if ( this->m_pMicBoost->IsSelected(this: this->m_pMicBoost) != this->m_bMicBoostSelected )
    {
      v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v3 != nullptr )
        v4 = KeyValues::KeyValues(this: v3, setName: "ApplyButtonEnable");
      else
        v4 = nullptr;
      this->PostActionSignal(this, a2: v4);
    }
    if ( this->m_pOpenMicEnableCheckButton->IsSelected(this: this->m_pOpenMicEnableCheckButton) != this->m_bOpenMicSelected )
    {
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
        v6 = KeyValues::KeyValues(this: v5, setName: "ApplyButtonEnable");
      else
        v6 = nullptr;
      this->PostActionSignal(this, a2: v6);
      CCvarToggleCheckButton::ApplyChanges(this: this->m_pOpenMicEnableCheckButton);
      this->m_bOpenMicSelected = this->m_pOpenMicEnableCheckButton->IsSelected(this: this->m_pOpenMicEnableCheckButton);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E4AA0
// Name: public: virtual void COptionsSubVoice::OnApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubVoice::OnApplyChanges(COptionsSubVoice *this)
{
  int v2; // eax
  IVoiceTweak_s *m_pVoiceTweak; // ecx
  bool v4; // al
  int v5; // xmm0_4
  int SliderValue; // eax
  CCvarToggleCheckButton *m_pOpenMicEnableCheckButton; // ecx

  if ( this->m_pVoiceTweak != nullptr )
  {
    v2 = this->m_pMicrophoneVolume->GetValue(this: this->m_pMicrophoneVolume);
    m_pVoiceTweak = this->m_pVoiceTweak;
    this->m_nMicVolumeValue = v2;
    ((void (__cdecl *)(_DWORD, _DWORD))m_pVoiceTweak->SetControlFloat)(a1: 0, a2: (float)v2 * 0.0099999998);
    v4 = this->m_pMicBoost->IsSelected(this: this->m_pMicBoost);
    this->m_bMicBoostSelected = v4;
    if ( v4 )
      v5 = 1065353216;
    else
      v5 = 0;
    ((void (__cdecl *)(int, int))this->m_pVoiceTweak->SetControlFloat)(a1: 2, a2: v5);
    CCvarSlider::ApplyChanges(this: this->m_pReceiveVolume);
    this->m_fReceiveVolume = CCvarSlider::GetSliderValue(this: this->m_pReceiveVolume);
    CCvarSlider::ApplyChanges(this: this->m_pThresholdVolume);
    SliderValue = (int)CCvarSlider::GetSliderValue(this: this->m_pThresholdVolume);
    m_pOpenMicEnableCheckButton = this->m_pOpenMicEnableCheckButton;
    this->m_nVoiceThresholdValue = SliderValue;
    CCvarToggleCheckButton::ApplyChanges(this: m_pOpenMicEnableCheckButton);
    CCvarToggleCheckButton::ApplyChanges(this: this->m_pVoiceEnableCheckButton);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E4B80
// Name: private: void COptionsSubVoice::UseCurrentVoiceParameters(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubVoice::UseCurrentVoiceParameters(COptionsSubVoice *this)
{
  int v2; // eax
  int v3; // xmm0_4
  int v4; // eax
  CCvarSlider *m_pReceiveVolume; // ecx
  int v6; // eax
  CCvarSlider *m_pThresholdVolume; // ecx

  v2 = this->m_pMicrophoneVolume->GetValue(this: this->m_pMicrophoneVolume);
  ((void (__cdecl *)(_DWORD, _DWORD))this->m_pVoiceTweak->SetControlFloat)(a1: 0, a2: (float)v2 * 0.0099999998);
  if ( this->m_pMicBoost->IsSelected(this: this->m_pMicBoost) )
    v3 = 1065353216;
  else
    v3 = 0;
  ((void (__cdecl *)(int, int))this->m_pVoiceTweak->SetControlFloat)(a1: 2, a2: v3);
  v4 = this->m_pReceiveVolume->GetValue(this: this->m_pReceiveVolume);
  m_pReceiveVolume = this->m_pReceiveVolume;
  this->m_nReceiveSliderValue = v4;
  CCvarSlider::ApplyChanges(this: m_pReceiveVolume);
  v6 = this->m_pThresholdVolume->GetValue(this: this->m_pThresholdVolume);
  m_pThresholdVolume = this->m_pThresholdVolume;
  this->m_nVoiceThresholdValue = v6;
  CCvarSlider::ApplyChanges(this: m_pThresholdVolume);
}

//------------------------------------------------------------------------------
// Address: 0x101E4C40
// Name: private: void COptionsSubVoice::ResetVoiceParameters(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubVoice::ResetVoiceParameters(COptionsSubVoice *this)
{
  int v2; // xmm0_4
  ConVarRef voice_scale; // [esp+8h] [ebp-8h] BYREF

  ((void (__cdecl *)(_DWORD, _DWORD))this->m_pVoiceTweak->SetControlFloat)(
    a1: 0,
    a2: (float)this->m_nMicVolumeValue * 0.0099999998);
  if ( this->m_bMicBoostSelected )
    v2 = 1065353216;
  else
    v2 = 0;
  ((void (__cdecl *)(int, int))this->m_pVoiceTweak->SetControlFloat)(a1: 2, a2: v2);
  ConVarRef::ConVarRef(this: &voice_scale, pName: "voice_scale");
  ((void (__stdcall *)(_DWORD))voice_scale.m_pConVar->SetValue_3)(a1: LODWORD(this->m_fReceiveVolume));
  CCvarSlider::Reset(this: this->m_pReceiveVolume);
  this->m_pReceiveVolume->SetValue(this: this->m_pReceiveVolume, a2: this->m_nReceiveSliderValue, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x101E4CF0
// Name: private: void COptionsSubVoice::EndTestMicrophone(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubVoice::EndTestMicrophone(COptionsSubVoice *this)
{
  IVoiceTweak_s *m_pVoiceTweak; // eax
  CCvarSlider *m_pReceiveVolume; // ecx

  m_pVoiceTweak = this->m_pVoiceTweak;
  if ( m_pVoiceTweak != nullptr && this->m_bVoiceOn )
  {
    if ( m_pVoiceTweak->IsStillTweaking() )
      this->m_pVoiceTweak->EndVoiceTweakMode();
    COptionsSubVoice::ResetVoiceParameters(this);
    this->m_pTestMicrophoneButton->SetText(this: this->m_pTestMicrophoneButton, a2: "#GameUI_TestMicrophone");
    m_pReceiveVolume = this->m_pReceiveVolume;
    this->m_bVoiceOn = false;
    m_pReceiveVolume->SetEnabled(this: m_pReceiveVolume, a2: true);
    this->m_pMicrophoneVolume->SetEnabled(this: this->m_pMicrophoneVolume, a2: true);
    this->m_pVoiceEnableCheckButton->SetEnabled(this: this->m_pVoiceEnableCheckButton, a2: true);
    this->m_pMicBoost->SetEnabled(this: this->m_pMicBoost, a2: true);
    this->m_pMicrophoneSliderLabel->SetEnabled(this: this->m_pMicrophoneSliderLabel, a2: true);
    this->m_pReceiveSliderLabel->SetEnabled(this: this->m_pReceiveSliderLabel, a2: true);
    this->m_pMicMeter2->SetVisible(this: this->m_pMicMeter2, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E4DD0
// Name: private: virtual void COptionsSubVoice::OnPageHide(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubVoice::OnPageHide(COptionsSubVoice *this)
{
  if ( this->m_bVoiceOn )
    COptionsSubVoice::EndTestMicrophone(this);
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this);
}

//------------------------------------------------------------------------------
// Address: 0x101E4E30
// Name: protected: virtual void COptionsSubVoice::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall COptionsSubVoice::OnThink(COptionsSubVoice *this@<ecx>, int a2@<ebx>)
{
  int v3; // edi
  int wide; // [esp+4h] [ebp-Ch] BYREF
  int tall; // [esp+8h] [ebp-8h] BYREF
  float val; // [esp+Ch] [ebp-4h]

  vgui::Panel::OnThink(this, a2, a3: (int)this);
  if ( this->m_bVoiceOn )
  {
    if ( this->m_pVoiceTweak->IsStillTweaking() )
    {
      val = this->m_pVoiceTweak->GetControlFloat(a1: SpeakingVolume);
      v3 = (int)(float)((float)(val * 32768.0) + 0.5);
      if ( this->m_pOpenMicEnableCheckButton->IsSelected(this: this->m_pOpenMicEnableCheckButton)
        && CCvarSlider::GetSliderValue(this: this->m_pThresholdVolume) * 0.000030517578 > val )
      {
        v3 = 0;
      }
      vgui::Panel::GetSize(this: this->m_pMicMeter2, &wide, &tall);
      vgui::Panel::SetSize(this: this->m_pMicMeter2, wide: 8 * ((160 * v3 / 0x8000 + 7) / 8), tall);
      this->m_pMicMeter2->Repaint(this: this->m_pMicMeter2);
    }
    else
    {
      _DevMsg(a1: 1, a2: "Lost Voice Tweak channels, resetting\n");
      COptionsSubVoice::EndTestMicrophone(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E4F40
// Name: public: virtual struct vgui::PanelMessageMap __near * COptionsSubVoice::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall COptionsSubVoice::GetMessageMap(COptionsSubVoice *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`COptionsSubVoice::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `COptionsSubVoice::GetMessageMap'::`2'::s_pMap;
  `COptionsSubVoice::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "COptionsSubVoice");
  `COptionsSubVoice::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E4F70
// Name: public: virtual struct PanelAnimationMap __near * COptionsSubVoice::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall COptionsSubVoice::GetAnimMap(COptionsSubVoice *this)
{
  return FindOrAddPanelAnimationMap(className: "COptionsSubVoice");
}

//------------------------------------------------------------------------------
// Address: 0x101E4F80
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * COptionsSubVoice::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall COptionsSubVoice::GetKBMap(COptionsSubVoice *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`COptionsSubVoice::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `COptionsSubVoice::GetKBMap'::`2'::s_pMap;
  `COptionsSubVoice::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "COptionsSubVoice");
  `COptionsSubVoice::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E4FB0
// Name: private: void COptionsSubVoice::StartTestMicrophone(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubVoice::StartTestMicrophone(COptionsSubVoice *this)
{
  if ( this->m_pVoiceTweak != nullptr && !this->m_bVoiceOn )
  {
    this->m_bVoiceOn = true;
    COptionsSubVoice::UseCurrentVoiceParameters(this);
    if ( this->m_pVoiceTweak->StartVoiceTweakMode() != 0 )
    {
      this->m_pTestMicrophoneButton->SetText(this: this->m_pTestMicrophoneButton, a2: "#GameUI_StopTestMicrophone");
      this->m_pReceiveVolume->SetEnabled(this: this->m_pReceiveVolume, a2: false);
      this->m_pMicrophoneVolume->SetEnabled(this: this->m_pMicrophoneVolume, a2: false);
      this->m_pVoiceEnableCheckButton->SetEnabled(this: this->m_pVoiceEnableCheckButton, a2: false);
      this->m_pMicBoost->SetEnabled(this: this->m_pMicBoost, a2: false);
      this->m_pMicrophoneSliderLabel->SetEnabled(this: this->m_pMicrophoneSliderLabel, a2: false);
      this->m_pReceiveSliderLabel->SetEnabled(this: this->m_pReceiveSliderLabel, a2: false);
      this->m_pMicMeter2->SetVisible(this: this->m_pMicMeter2, a2: true);
    }
    else
    {
      COptionsSubVoice::ResetVoiceParameters(this);
      this->m_bVoiceOn = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E5090
// Name: private: virtual void COptionsSubVoice::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsSubVoice::OnCommand(COptionsSubVoice *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "TestMicrophone") != 0 )
  {
    vgui::Panel::OnCommand(this, command);
  }
  else if ( this->m_bVoiceOn )
  {
    COptionsSubVoice::EndTestMicrophone(this);
  }
  else
  {
    COptionsSubVoice::StartTestMicrophone(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E5120
// Name: public: static void COptionsSubVoice::PanelMessageFunc_OnPageHide::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COptionsSubVoice::PanelMessageFunc_OnPageHide::InitVar(int a1@<ebp>)
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
  if ( !`COptionsSubVoice::PanelMessageFunc_OnPageHide::InitVar'::`2'::bAdded )
  {
    `COptionsSubVoice::PanelMessageFunc_OnPageHide::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COptionsSubVoice");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PageHide";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E51B0
// Name: public: static void COptionsSubVoice::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COptionsSubVoice::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
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
  if ( !`COptionsSubVoice::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `COptionsSubVoice::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall COptionsSubMultiplayer::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COptionsSubVoice");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "SliderMoved";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "position";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E5250
// Name: public: static void COptionsSubVoice::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COptionsSubVoice::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`COptionsSubVoice::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `COptionsSubVoice::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall COptionsSubMultiplayer::`vcall'{968,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COptionsSubVoice");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CheckButtonChecked";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "state";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E52F0
// Name: public: static void COptionsSubVoice::PanelMessageFunc_OnControlModified::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COptionsSubVoice::PanelMessageFunc_OnControlModified::InitVar(int a1@<ebp>)
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
  if ( !`COptionsSubVoice::PanelMessageFunc_OnControlModified::InitVar'::`2'::bAdded )
  {
    `COptionsSubVoice::PanelMessageFunc_OnControlModified::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall COptionsSubMultiplayer::`vcall'{972,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COptionsSubVoice");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ControlModified";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E5380
// Name: public: COptionsSubVoice::COptionsSubVoice(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
COptionsSubVoice *__thiscall COptionsSubVoice::COptionsSubVoice(COptionsSubVoice *this, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::ImagePanel *v6; // eax
  vgui::ImagePanel *v7; // eax
  vgui::ImagePanel *v8; // eax
  vgui::ImagePanel *v9; // eax
  vgui::Label *v10; // eax
  vgui::Label *v11; // eax
  CCvarSlider *v12; // eax
  CCvarSlider *v13; // eax
  vgui::Label *v14; // eax
  vgui::Label *v15; // eax
  vgui::Slider *v16; // eax
  vgui::Slider *v17; // eax
  CCvarToggleCheckButton *v18; // eax
  CCvarToggleCheckButton *v19; // eax
  vgui::CheckButton *v20; // eax
  vgui::CheckButton *v21; // eax
  vgui::Label *v22; // eax
  vgui::Label *v23; // eax
  CCvarSlider *v24; // eax
  CCvarSlider *v25; // eax
  CCvarToggleCheckButton *v26; // eax
  CCvarToggleCheckButton *v27; // eax
  vgui::Button *v28; // eax
  vgui::Button *v29; // eax
  vgui::ImagePanel *m_pMicMeter2; // ecx
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  vgui::PropertyPage::PropertyPage(this, parent, panelName: nullptr);
  this->__vftable = (COptionsSubVoice_vtbl *)&COptionsSubVoice::`vftable';
  if ( `COptionsSubVoice::ChainToMap'::`2'::chained == 0 )
  {
    `COptionsSubVoice::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "COptionsSubVoice");
    v3->pfnClassName = COptionsSubVoice::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::PropertyPage");
  }
  if ( `COptionsSubVoice::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `COptionsSubVoice::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "COptionsSubVoice");
    v4->pfnClassName = COptionsSubVoice::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::PropertyPage");
  }
  if ( `COptionsSubVoice::KB_ChainToMap'::`2'::chained == 0 )
  {
    `COptionsSubVoice::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "COptionsSubVoice");
    v5->pfnClassName = COptionsSubVoice::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::PropertyPage");
  }
  COptionsSubVoice::PanelMessageFunc_OnPageHide::InitVar();
  COptionsSubVoice::PanelMessageFunc_OnSliderMoved::InitVar(a1: (int)&savedregs);
  COptionsSubVoice::PanelMessageFunc_OnCheckButtonChecked::InitVar(a1: (int)&savedregs);
  COptionsSubVoice::PanelMessageFunc_OnControlModified::InitVar(a1: (int)&savedregs);
  this->m_pVoiceTweak = engine->GetVoiceTweakAPI(this: engine);
  v6 = (vgui::ImagePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v6 != nullptr )
    v7 = vgui::ImagePanel::ImagePanel(this: v6, parent: this, name: "MicMeter");
  else
    v7 = nullptr;
  this->m_pMicMeter = v7;
  v8 = (vgui::ImagePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v8 != nullptr )
    v9 = vgui::ImagePanel::ImagePanel(this: v8, parent: this, name: "MicMeter2");
  else
    v9 = nullptr;
  this->m_pMicMeter2 = v9;
  v10 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v10 != nullptr )
    v11 = vgui::Label::Label(this: v10, parent: this, panelName: "ReceiveLabel", text: "#GameUI_VoiceReceiveVolume");
  else
    v11 = nullptr;
  this->m_pReceiveSliderLabel = v11;
  v12 = (CCvarSlider *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v12 != nullptr )
    v13 = CCvarSlider::CCvarSlider(
            this: v12,
            parent: this,
            panelName: "VoiceReceive",
            caption: "#GameUI_ReceiveVolume",
            minValue: 0.0,
            maxValue: 1.0,
            cvarname: "voice_scale",
            bAllowOutOfRange: false);
  else
    v13 = nullptr;
  this->m_pReceiveVolume = v13;
  v14 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v14 != nullptr )
    v15 = vgui::Label::Label(this: v14, parent: this, panelName: "MicrophoneLabel", text: "#GameUI_VoiceTransmitVolume");
  else
    v15 = nullptr;
  this->m_pMicrophoneSliderLabel = v15;
  v16 = (vgui::Slider *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v16 != nullptr )
    v17 = vgui::Slider::Slider(this: v16, parent: this, panelName: "#GameUI_MicrophoneVolume");
  else
    v17 = nullptr;
  this->m_pMicrophoneVolume = v17;
  v17->SetRange(this: v17, a2: 0, a3: 100);
  this->m_pMicrophoneVolume->AddActionSignalTarget_2(this: this->m_pMicrophoneVolume, a2: this);
  v18 = (CCvarToggleCheckButton *)MemAlloc_Alloc(nSize: 0x224u);
  if ( v18 != nullptr )
    v19 = CCvarToggleCheckButton::CCvarToggleCheckButton(
            this: v18,
            parent: this,
            panelName: "voice_modenable",
            text: "#GameUI_EnableVoice",
            cvarname: "voice_modenable");
  else
    v19 = nullptr;
  this->m_pVoiceEnableCheckButton = v19;
  v20 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v20 != nullptr )
    v21 = vgui::CheckButton::CheckButton(
            this: v20,
            parent: this,
            panelName: "MicBoost",
            text: "#GameUI_BoostMicrophone");
  else
    v21 = nullptr;
  this->m_pMicBoost = v21;
  v21->AddActionSignalTarget_2(this: v21, a2: this);
  v22 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v22 != nullptr )
    v23 = vgui::Label::Label(this: v22, parent: this, panelName: "ThresholdLabel", text: "#GameUI_VoiceThreshold");
  else
    v23 = nullptr;
  this->m_pThresholdSliderLabel = v23;
  v24 = (CCvarSlider *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v24 != nullptr )
    v25 = CCvarSlider::CCvarSlider(
            this: v24,
            parent: this,
            panelName: "VoiceThreshold",
            caption: "#GameUI_VoiceThreshold",
            minValue: 0.0,
            maxValue: 16384.0,
            cvarname: "voice_threshold",
            bAllowOutOfRange: false);
  else
    v25 = nullptr;
  this->m_pThresholdVolume = v25;
  v26 = (CCvarToggleCheckButton *)MemAlloc_Alloc(nSize: 0x224u);
  if ( v26 != nullptr )
    v27 = CCvarToggleCheckButton::CCvarToggleCheckButton(
            this: v26,
            parent: this,
            panelName: "voice_vox",
            text: "#GameUI_EnableOpenMic",
            cvarname: "voice_vox");
  else
    v27 = nullptr;
  this->m_pOpenMicEnableCheckButton = v27;
  v28 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v28 != nullptr )
    v29 = vgui::Button::Button(
            this: v28,
            parent: this,
            panelName: "TestMicrophone",
            text: "#GameUI_TestMicrophone",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v29 = nullptr;
  this->m_pTestMicrophoneButton = v29;
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "Resource\\OptionsSubVoice.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  m_pMicMeter2 = this->m_pMicMeter2;
  this->m_bVoiceOn = false;
  m_pMicMeter2->SetVisible(this: m_pMicMeter2, a2: false);
  if ( this->m_pVoiceTweak != nullptr )
  {
    COptionsSubVoice::OnResetData(this);
  }
  else
  {
    this->m_pReceiveVolume->SetEnabled(this: this->m_pReceiveVolume, a2: false);
    this->m_pMicrophoneVolume->SetEnabled(this: this->m_pMicrophoneVolume, a2: false);
    this->m_pVoiceEnableCheckButton->SetEnabled(this: this->m_pVoiceEnableCheckButton, a2: false);
    this->m_pMicBoost->SetEnabled(this: this->m_pMicBoost, a2: false);
    this->m_pTestMicrophoneButton->SetEnabled(this: this->m_pTestMicrophoneButton, a2: false);
    this->m_pOpenMicEnableCheckButton->SetEnabled(this: this->m_pOpenMicEnableCheckButton, a2: false);
    this->m_pThresholdVolume->SetEnabled(this: this->m_pThresholdVolume, a2: false);
  }
  return this;
}
