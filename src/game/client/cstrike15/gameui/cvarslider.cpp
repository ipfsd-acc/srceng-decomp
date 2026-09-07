// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/cvarslider.cpp
// Functions: 20
// ============================================================

#include "game\client\cstrike15\gameui\cvarslider.h"

//------------------------------------------------------------------------------
// Address: 0x101D4310
// Name: public: static char const __near * CCvarSlider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CCvarSlider::GetPanelClassName()
{
  return "CCvarSlider";
}

//------------------------------------------------------------------------------
// Address: 0x101D4320
// Name: public: virtual void CCvarSlider::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvarSlider::GetSettings(CCvarSlider *this, KeyValues *outResourceData)
{
  vgui::Slider::GetSettings(this, outResourceData);
  if ( !this->m_bCreatedInCode )
  {
    KeyValues::SetFloat(this: outResourceData, keyName: "minvalue", value: this->m_flMinValue);
    KeyValues::SetFloat(this: outResourceData, keyName: "maxvalue", value: this->m_flMaxValue);
    KeyValues::SetString(this: outResourceData, keyName: "cvar_name", value: this->m_szCvarName);
    KeyValues::SetInt(this: outResourceData, keyName: "allowoutofrange", value: this->m_bAllowOutOfRange);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D43A0
// Name: public: virtual void CCvarSlider::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvarSlider::Paint(CCvarSlider *this)
{
  float m_fValue; // xmm0_4
  void (__thiscall *SetValue)(vgui::Slider *, int, bool); // edx
  ConVarRef var; // [esp+4h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &var, pName: this->m_szCvarName);
  if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&var) )
  {
    m_fValue = var.m_pConVarState->m_Value.m_fValue;
    if ( m_fValue != this->m_fStartValue )
    {
      SetValue = this->SetValue;
      this->m_fStartValue = m_fValue;
      this->m_fCurrentValue = m_fValue;
      SetValue(this, a2: (int)(float)(m_fValue * 100.0), a3: true);
      this->m_iStartValue = this->GetValue(this);
    }
    vgui::Slider::Paint(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D4430
// Name: public: void CCvarSlider::ApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvarSlider::ApplyChanges(CCvarSlider *this)
{
  int v2; // eax
  bool v3; // zf
  ConVarRef var; // [esp+8h] [ebp-8h] BYREF

  if ( this->m_bModifiedOnce )
  {
    v2 = this->GetValue(this);
    v3 = !this->m_bAllowOutOfRange;
    this->m_iStartValue = v2;
    if ( v3 )
      this->m_fStartValue = (float)v2 * 0.0099999998;
    else
      this->m_fStartValue = this->m_fCurrentValue;
    ConVarRef::ConVarRef(this: &var, pName: this->m_szCvarName);
    ((void (__stdcall *)(_DWORD))var.m_pConVar->SetValue_3)(a1: LODWORD(this->m_fStartValue));
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D44B0
// Name: public: float CCvarSlider::GetSliderValue(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCvarSlider::GetSliderValue(CCvarSlider *this)
{
  if ( this->m_bAllowOutOfRange )
    return this->m_fCurrentValue;
  else
    return (double)((int (__thiscall *)(CCvarSlider *, CCvarSlider *))this->GetValue)(a1: this, a2: this) * 0.0099999998;
}

//------------------------------------------------------------------------------
// Address: 0x101D44F0
// Name: public: void CCvarSlider::SetSliderValue(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvarSlider::SetSliderValue(CCvarSlider *this, float fValue)
{
  int v3; // eax
  float m_fCurrentValue; // xmm1_4

  this->SetValue(this, a2: (int)(float)(fValue * 100.0), a3: false);
  v3 = this->GetValue(this);
  m_fCurrentValue = this->m_fCurrentValue;
  this->m_iLastSliderValue = v3;
  if ( m_fCurrentValue != fValue )
  {
    this->m_fCurrentValue = fValue;
    this->m_bModifiedOnce = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D4560
// Name: public: void CCvarSlider::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvarSlider::Reset(CCvarSlider *this)
{
  bool IsValid; // al
  CCvarSlider_vtbl *v3; // edx
  void (__thiscall *v4)(vgui::Slider *, int, bool); // eax
  int v5; // eax
  float m_fValue; // xmm0_4
  void (__thiscall *SetValue)(vgui::Slider *, int, bool); // edx
  ConVarRef var; // [esp+4h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &var, pName: this->m_szCvarName);
  IsValid = ConVarRef::IsValid(this: (SplitScreenConVarRef *)&var);
  v3 = this->__vftable;
  if ( IsValid )
  {
    m_fValue = var.m_pConVarState->m_Value.m_fValue;
    SetValue = v3->SetValue;
    this->m_fCurrentValue = m_fValue;
    SetValue(this, a2: (int)(float)(m_fValue * 100.0), a3: true);
  }
  else
  {
    v4 = v3->SetValue;
    this->m_fStartValue = 0.0;
    this->m_fCurrentValue = 0.0;
    v4(this, a2: 0, a3: true);
  }
  v5 = this->GetValue(this);
  this->m_iLastSliderValue = v5;
  this->m_iStartValue = v5;
}

//------------------------------------------------------------------------------
// Address: 0x101D4610
// Name: public: bool CCvarSlider::HasBeenModified(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCvarSlider::HasBeenModified(CCvarSlider *this)
{
  if ( this->GetValue(this) != this->m_iStartValue )
    this->m_bModifiedOnce = true;
  return this->m_bModifiedOnce;
}

//------------------------------------------------------------------------------
// Address: 0x101D4640
// Name: private: virtual void CCvarSlider::OnSliderMoved(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvarSlider::OnSliderMoved(CCvarSlider *this)
{
  int v2; // eax
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( this->GetValue(this) != this->m_iStartValue )
    this->m_bModifiedOnce = true;
  if ( this->m_bModifiedOnce )
  {
    if ( this->m_iLastSliderValue != this->GetValue(this) )
    {
      v2 = this->GetValue(this);
      this->m_iLastSliderValue = v2;
      this->m_fCurrentValue = (float)v2 * 0.0099999998;
    }
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
    {
      v4 = KeyValues::KeyValues(this: v3, setName: "ControlModified");
      this->PostActionSignal(this, a2: v4);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D46E0
// Name: private: virtual void CCvarSlider::OnApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvarSlider::OnApplyChanges(CCvarSlider *this)
{
  if ( !this->m_bCreatedInCode )
    CCvarSlider::ApplyChanges(this);
}

//------------------------------------------------------------------------------
// Address: 0x101D46F0
// Name: public: virtual struct vgui::PanelMessageMap __near * CCvarSlider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CCvarSlider::GetMessageMap(CCvarSlider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CCvarSlider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CCvarSlider::GetMessageMap'::`2'::s_pMap;
  `CCvarSlider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CCvarSlider");
  `CCvarSlider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D4720
// Name: public: virtual struct PanelAnimationMap __near * CCvarSlider::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CCvarSlider::GetAnimMap(CCvarSlider *this)
{
  return FindOrAddPanelAnimationMap(className: "CCvarSlider");
}

//------------------------------------------------------------------------------
// Address: 0x101D4730
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CCvarSlider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CCvarSlider::GetKBMap(CCvarSlider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CCvarSlider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CCvarSlider::GetKBMap'::`2'::s_pMap;
  `CCvarSlider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CCvarSlider");
  `CCvarSlider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D4790
// Name: public: void CCvarSlider::SetupSlider(float,float,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CCvarSlider::SetupSlider(
        CCvarSlider *this@<ecx>,
        int a2@<esi>,
        float minValue,
        float maxValue,
        char *cvarname,
        bool bAllowOutOfRange)
{
  void (__thiscall *SetRange)(vgui::Slider *, int, int); // eax
  char szMin[32]; // [esp+14h] [ebp-40h] BYREF
  char szMax[32]; // [esp+34h] [ebp-20h] BYREF

  SetRange = this->SetRange;
  this->m_flMinValue = minValue;
  this->m_flMaxValue = maxValue;
  ((void (__thiscall *)(CCvarSlider *, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))SetRange)(
    a1: this,
    a2: (int)(float)(minValue * 100.0),
    a3: (int)(float)(maxValue * 100.0),
    a4: a2,
    a5: *(_DWORD *)szMin,
    a6: *(_DWORD *)&szMin[4],
    a7: *(_DWORD *)&szMin[8],
    a8: *(_DWORD *)&szMin[12],
    a9: *(_DWORD *)&szMin[16],
    a10: *(_DWORD *)&szMin[20],
    a11: *(_DWORD *)&szMin[24],
    a12: *(_DWORD *)&szMin[28],
    a13: *(_DWORD *)szMax,
    a14: *(_DWORD *)&szMax[4],
    a15: *(_DWORD *)&szMax[8],
    a16: *(_DWORD *)&szMax[12],
    a17: *(_DWORD *)&szMax[16],
    a18: *(_DWORD *)&szMax[20],
    a19: *(_DWORD *)&szMax[24]);
  V_snprintf(pDest: szMin, maxLen: 0x20u, pFormat: "%.2f", minValue);
  V_snprintf(pDest: szMax, maxLen: 0x20u, pFormat: "%.2f", maxValue);
  this->SetTickCaptions(this, a2: szMin, a3: szMax);
  V_strncpy(pDest: this->m_szCvarName, pSrc: cvarname, maxLen: 64);
  this->m_bModifiedOnce = false;
  this->m_bAllowOutOfRange = bAllowOutOfRange;
  CCvarSlider::Reset(this);
}

//------------------------------------------------------------------------------
// Address: 0x101D4870
// Name: public: virtual void CCvarSlider::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCvarSlider::ApplySettings(CCvarSlider *this, KeyValues *inResourceData)
{
  char *String; // ebx
  vgui::Panel *v4; // eax
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax
  CCvarSlider_vtbl *v7; // edx
  CCvarSlider *v8; // ecx
  int v9; // eax
  float minValue; // [esp+1Ch] [ebp-8h]
  float maxValue; // [esp+20h] [ebp-4h]
  bool bAllowOutOfRange; // [esp+2Ch] [ebp+8h]

  vgui::Slider::ApplySettings(this, inResourceData);
  if ( !this->m_bCreatedInCode )
  {
    minValue = KeyValues::GetFloat(this: inResourceData, keyName: "minvalue", defaultValue: 0.0);
    maxValue = KeyValues::GetFloat(this: inResourceData, keyName: "maxvalue", defaultValue: 1.0);
    String = KeyValues::GetString(this: inResourceData, keyName: "cvar_name", defaultValue: prType);
    bAllowOutOfRange = KeyValues::GetInt(this: inResourceData, keyName: "allowoutofrange", defaultValue: 0) != 0;
    CCvarSlider::SetupSlider(this, a2: (int)this, minValue, maxValue, cvarname: String, bAllowOutOfRange);
    if ( this->GetParent(this) != nullptr )
    {
      v4 = this->GetParent(this);
      if ( __RTDynamicCast(
             inptr: v4,
             VfDelta: 0,
             SrcType: &vgui::Panel `RTTI Type Descriptor',
             TargetType: &vgui::PropertyPage `RTTI Type Descriptor',
             isReference: 0) != nullptr
        && (v5 = this->GetParent(this), v5->GetParent(this: v5) != nullptr) )
      {
        v6 = this->GetParent(this);
        v7 = (CCvarSlider_vtbl *)v6->__vftable;
        v8 = (CCvarSlider *)v6;
      }
      else
      {
        v7 = this->__vftable;
        v8 = this;
      }
      v9 = (int)v7->GetParent(this: v8);
      (*(void (__thiscall **)(int, CCvarSlider *))(*(_DWORD *)v9 + 188))(a1: v9, a2: this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D49A0
// Name: public: static void CCvarSlider::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CCvarSlider::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
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
  if ( !`CCvarSlider::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `CCvarSlider::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CSaveGamePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CCvarSlider");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "SliderMoved";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D4A30
// Name: public: static void CCvarSlider::PanelMessageFunc_OnApplyChanges::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CCvarSlider::PanelMessageFunc_OnApplyChanges::InitVar(int a1@<ebp>)
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
  if ( !`CCvarSlider::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded )
  {
    `CCvarSlider::PanelMessageFunc_OnApplyChanges::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CCvarSlider::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CCvarSlider");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ApplyChanges";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D4AC0
// Name: public: CCvarSlider::CCvarSlider(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CCvarSlider *__thiscall CCvarSlider::CCvarSlider(CCvarSlider *this, vgui::Panel *parent, const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Slider::Slider(this, parent, panelName: name);
  this->__vftable = (CCvarSlider_vtbl *)&CCvarSlider::`vftable';
  if ( `CCvarSlider::ChainToMap'::`2'::chained == 0 )
  {
    `CCvarSlider::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CCvarSlider");
    v4->pfnClassName = CCvarSlider::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Slider");
  }
  if ( `CCvarSlider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CCvarSlider::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CCvarSlider");
    v5->pfnClassName = CCvarSlider::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Slider");
  }
  if ( `CCvarSlider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CCvarSlider::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CCvarSlider");
    v6->pfnClassName = CCvarSlider::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Slider");
  }
  CCvarSlider::PanelMessageFunc_OnSliderMoved::InitVar();
  CCvarSlider::PanelMessageFunc_OnApplyChanges::InitVar();
  CCvarSlider::SetupSlider(
    this,
    a2: (int)this,
    minValue: 0.0,
    maxValue: 1.0,
    cvarname: (char *)prType,
    bAllowOutOfRange: false);
  this->m_bCreatedInCode = false;
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101D4BC0
// Name: public: CCvarSlider::CCvarSlider(class vgui::Panel __near *,char const __near *,char const __near *,float,float,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CCvarSlider *__thiscall CCvarSlider::CCvarSlider(
        CCvarSlider *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *caption,
        float minValue,
        float maxValue,
        char *cvarname,
        bool bAllowOutOfRange)
{
  vgui::PanelMessageMap *v9; // edi
  PanelAnimationMap *v10; // edi
  vgui::PanelKeyBindingMap *v11; // edi

  vgui::Slider::Slider(this, parent, panelName);
  this->__vftable = (CCvarSlider_vtbl *)&CCvarSlider::`vftable';
  if ( `CCvarSlider::ChainToMap'::`2'::chained == 0 )
  {
    `CCvarSlider::ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelMessageMap(className: "CCvarSlider");
    v9->pfnClassName = CCvarSlider::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Slider");
  }
  if ( `CCvarSlider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CCvarSlider::ChainToAnimationMap'::`2'::chained = 1;
    v10 = FindOrAddPanelAnimationMap(className: "CCvarSlider");
    v10->pfnClassName = CCvarSlider::GetPanelClassName;
    v10->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Slider");
  }
  if ( `CCvarSlider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CCvarSlider::KB_ChainToMap'::`2'::chained = 1;
    v11 = vgui::FindOrAddPanelKeyBindingMap(className: "CCvarSlider");
    v11->pfnClassName = CCvarSlider::GetPanelClassName;
    v11->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Slider");
  }
  CCvarSlider::PanelMessageFunc_OnSliderMoved::InitVar();
  CCvarSlider::PanelMessageFunc_OnApplyChanges::InitVar();
  vgui::Panel::AddActionSignalTarget(this, messageTarget: this);
  CCvarSlider::SetupSlider(this, a2: (int)this, minValue, maxValue, cvarname, bAllowOutOfRange);
  this->m_bCreatedInCode = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101D4CC0
// Name: Create_CCvarSlider
// Source: json
//------------------------------------------------------------------------------
CCvarSlider *__cdecl Create_CCvarSlider()
{
  CCvarSlider *v0; // eax

  v0 = (CCvarSlider *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v0 != nullptr )
    return CCvarSlider::CCvarSlider(this: v0, parent: nullptr, name: nullptr);
  else
    return nullptr;
}
