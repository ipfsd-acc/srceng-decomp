// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/attributeslider.cpp
// Functions: 70
// ============================================================

#include "vgui2\dme_controls\attributeslider.h"

//------------------------------------------------------------------------------
// Address: 0x00489E90
// Name: public: static char const __near * CAttributeSlider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeSlider::GetPanelClassName()
{
  return "CAttributeSlider";
}

//------------------------------------------------------------------------------
// Address: 0x00489EA0
// Name: void ValueBalanceToLeftRight(float __near *,float __near *,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ValueBalanceToLeftRight(float *pLeft, float *pRight, float flValue, float flBalance, float flDefaultValue)
{
  float v5; // xmm1_4
  float v6; // xmm0_4

  v5 = flValue;
  if ( flBalance > 0.5 )
    v6 = (float)((float)((float)(1.0 - flBalance) * 2.0) * (float)(flValue - flDefaultValue)) + flDefaultValue;
  else
    v6 = flValue;
  *pLeft = v6;
  if ( flBalance < 0.5 )
    v5 = (float)((float)(flValue - flDefaultValue) * (float)(flBalance * 2.0)) + flDefaultValue;
  *pRight = v5;
}

//------------------------------------------------------------------------------
// Address: 0x00489F20
// Name: public: static char const __near * CAttributeSliderTextEntry::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeSliderTextEntry::GetPanelClassName()
{
  return "CAttributeSliderTextEntry";
}

//------------------------------------------------------------------------------
// Address: 0x00489F30
// Name: public: void CAttributeSlider::SetValue(enum AnimationControlType_t,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::SetValue(CAttributeSlider *this, AnimationControlType_t type, float flValue)
{
  if ( this->m_Control.m_pValue[type] != flValue )
    this->m_Control.m_pValue[type] = flValue;
}

//------------------------------------------------------------------------------
// Address: 0x00489F60
// Name: public: void CAttributeSlider::SetValue(enum AnimationControlType_t,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::SetValue(CAttributeSlider *this, AnimationControlType_t type, const Vector *vec)
{
  if ( vec->x != this->m_Control.m_Vector.x
    || vec->y != this->m_Control.m_Vector.y
    || vec->z != this->m_Control.m_Vector.z )
  {
    this->m_Control.m_Vector = *vec;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00489FC0
// Name: public: void CAttributeSlider::SetValue(enum AnimationControlType_t,class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::SetValue(CAttributeSlider *this, AnimationControlType_t type, const Quaternion *quat)
{
  if ( this->m_Control.m_Quaternion.x != quat->x
    || this->m_Control.m_Quaternion.y != quat->y
    || this->m_Control.m_Quaternion.z != quat->z
    || this->m_Control.m_Quaternion.w != quat->w )
  {
    this->m_Control.m_Quaternion = *quat;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048A030
// Name: public: struct AttributeValue_t const __near & CAttributeSlider::GetValue(void)const
// Source: json
//------------------------------------------------------------------------------
const AttributeValue_t *__thiscall CAttributeSlider::GetValue(CAttributeSlider *this)
{
  return &this->m_Control;
}

//------------------------------------------------------------------------------
// Address: 0x0048A040
// Name: public: float CAttributeSlider::GetValue(enum AnimationControlType_t)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAttributeSlider::GetValue(CAttributeSlider *this, AnimationControlType_t type)
{
  return this->m_Control.m_pValue[type];
}

//------------------------------------------------------------------------------
// Address: 0x0048A060
// Name: public: void CAttributeSlider::GetValue(enum AnimationControlType_t,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::GetValue(CAttributeSlider *this, AnimationControlType_t type, Vector *out)
{
  *out = this->m_Control.m_Vector;
}

//------------------------------------------------------------------------------
// Address: 0x0048A090
// Name: public: void CAttributeSlider::GetValue(enum AnimationControlType_t,class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::GetValue(CAttributeSlider *this, AnimationControlType_t type, Quaternion *out)
{
  *out = this->m_Control.m_Quaternion;
}

//------------------------------------------------------------------------------
// Address: 0x0048A0C0
// Name: public: float CAttributeSlider::GetPreview(enum AnimationControlType_t)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAttributeSlider::GetPreview(CAttributeSlider *this, AnimationControlType_t type)
{
  return this->m_PreviewCurrent.m_pValue[type];
}

//------------------------------------------------------------------------------
// Address: 0x0048A0E0
// Name: public: void CAttributeSlider::GetPreview(enum AnimationControlType_t,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::GetPreview(CAttributeSlider *this, AnimationControlType_t type, Vector *out)
{
  *out = this->m_PreviewCurrent.m_Vector;
}

//------------------------------------------------------------------------------
// Address: 0x0048A110
// Name: public: void CAttributeSlider::GetPreview(enum AnimationControlType_t,class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::GetPreview(CAttributeSlider *this, AnimationControlType_t type, Quaternion *out)
{
  *out = this->m_PreviewCurrent.m_Quaternion;
}

//------------------------------------------------------------------------------
// Address: 0x0048A140
// Name: public: void CAttributeSlider::SetVisibleComponents(enum LogComponents_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::SetVisibleComponents(CAttributeSlider *this, LogComponents_t componentFlags)
{
  this->m_nVisibleComponents = componentFlags;
}

//------------------------------------------------------------------------------
// Address: 0x0048A150
// Name: public: enum LogComponents_t CAttributeSlider::VisibleComponents(void)const
// Source: json
//------------------------------------------------------------------------------
LogComponents_t __thiscall CAttributeSlider::VisibleComponents(CAttributeSlider *this)
{
  return this->m_nVisibleComponents;
}

//------------------------------------------------------------------------------
// Address: 0x0048A160
// Name: public: virtual void CAttributeSlider::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnCursorEntered(CAttributeSlider *this)
{
  CBaseAnimationSetControl *v2; // eax

  if ( this->m_SliderMode != SLIDER_MODE_DRAG_VALUE )
  {
    CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
    v2 = this->m_pParent->GetController(this: this->m_pParent);
    CBaseAnimationSetControl::SetActiveAttributeSlider(this: v2, pSlider: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048A190
// Name: public: virtual void CAttributeSlider::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnCursorExited(CAttributeSlider *this)
{
  CBaseAnimationSetControl *v2; // eax

  if ( this->m_SliderMode != SLIDER_MODE_DRAG_VALUE )
  {
    CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
    v2 = this->m_pParent->GetController(this: this->m_pParent);
    CBaseAnimationSetControl::SetActiveAttributeSlider(this: v2, pSlider: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048A1C0
// Name: private: void CAttributeSlider::DiscardTextEntryValue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::DiscardTextEntryValue(CAttributeSlider *this)
{
  void (__thiscall *RequestFocus)(vgui::IClientPanel *, int); // edx

  if ( this->m_SliderMode == SLIDER_MODE_TEXT )
  {
    this->m_pTextField->SetVisible(this: this->m_pTextField, a2: false);
    this->m_pTextField->SetEnabled(this: this->m_pTextField, a2: false);
    if ( (*((_BYTE *)this + 656) & 4) != 0 )
    {
      this->m_pRightTextField->SetVisible(this: this->m_pRightTextField, a2: false);
      this->m_pRightTextField->SetEnabled(this: this->m_pRightTextField, a2: false);
    }
    RequestFocus = this->RequestFocus;
    this->m_SliderMode = SLIDER_MODE_NONE;
    RequestFocus(this, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048A240
// Name: public: void CAttributeSlider::SetPreview(struct AttributeValue_t const __near &,struct AttributeValue_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::SetPreview(
        CAttributeSlider *this,
        const AttributeValue_t *value,
        const AttributeValue_t *full)
{
  this->m_PreviewCurrent = *value;
  this->m_PreviewFull = *full;
}

//------------------------------------------------------------------------------
// Address: 0x0048A2F0
// Name: public: struct AttributeValue_t const __near & CAttributeSlider::GetPreview(void)const
// Source: json
//------------------------------------------------------------------------------
const AttributeValue_t *__thiscall CAttributeSlider::GetPreview(CAttributeSlider *this)
{
  return &this->m_PreviewCurrent;
}

//------------------------------------------------------------------------------
// Address: 0x0048A300
// Name: private: void CAttributeSlider::GetControlRect(struct Rect_t __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::GetControlRect(CAttributeSlider *this, Rect_t *pRect)
{
  int v2; // ecx
  BOOL v3; // edx
  int sh; // [esp+0h] [ebp-8h] BYREF
  int sw; // [esp+4h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &sw, tall: &sh);
  pRect->width = sw - 12;
  v2 = sh - 6;
  v3 = sh - 6 < 0;
  pRect->x = 6;
  pRect->y = 3;
  pRect->height = v3 ? 0 : v2;
}

//------------------------------------------------------------------------------
// Address: 0x0048A350
// Name: protected: virtual void CAttributeSlider::OnCurve1(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnCurve1(CAttributeSlider *this)
{
  this->m_pParent->DispatchCurve(this: this->m_pParent, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x0048A370
// Name: protected: virtual void CAttributeSlider::OnCurve2(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnCurve2(CAttributeSlider *this)
{
  this->m_pParent->DispatchCurve(this: this->m_pParent, a2: 2);
}

//------------------------------------------------------------------------------
// Address: 0x0048A390
// Name: protected: virtual void CAttributeSlider::OnCurve3(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnCurve3(CAttributeSlider *this)
{
  this->m_pParent->DispatchCurve(this: this->m_pParent, a2: 3);
}

//------------------------------------------------------------------------------
// Address: 0x0048A3B0
// Name: protected: virtual void CAttributeSlider::OnCurve4(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnCurve4(CAttributeSlider *this)
{
  this->m_pParent->DispatchCurve(this: this->m_pParent, a2: 4);
}

//------------------------------------------------------------------------------
// Address: 0x0048A3D0
// Name: public: void CAttributeSlider::SetDependent(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::SetDependent(CAttributeSlider *this, bool dependent)
{
  *((_BYTE *)this + 656) ^= (*((_BYTE *)this + 656) ^ (8 * dependent)) & 8;
}

//------------------------------------------------------------------------------
// Address: 0x0048A3F0
// Name: float clamp<float,float,float>(float const __near &,float const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl clamp<float,float,float>(const float *val, const float *minVal, const float *maxVal)
{
  if ( *minVal > *val )
    return *minVal;
  if ( *val <= *maxVal )
    return *val;
  return *maxVal;
}

//------------------------------------------------------------------------------
// Address: 0x0048A470
// Name: void BlendValues(bool,struct AttributeValue_t __near *,struct AttributeValue_t const __near &,struct AttributeValue_t const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BlendValues(
        bool bTransform,
        AttributeValue_t *pResult,
        const AttributeValue_t *src,
        const AttributeValue_t *dest,
        float flBlend,
        float flBalanceFilter)
{
  float v6; // xmm4_4
  float v7; // xmm5_4
  float v8; // xmm0_4
  float v9; // xmm1_4

  if ( bTransform )
  {
    v6 = src->m_Vector.y + (float)((float)(dest->m_Vector.y - src->m_Vector.y) * flBlend);
    v7 = src->m_Vector.z + (float)((float)(dest->m_Vector.z - src->m_Vector.z) * flBlend);
    pResult->m_Vector.x = src->m_Vector.x + (float)((float)(dest->m_Vector.x - src->m_Vector.x) * flBlend);
    pResult->m_Vector.y = v6;
    pResult->m_Vector.z = v7;
    QuaternionSlerp(p: &src->m_Quaternion, q: &dest->m_Quaternion, t: flBlend, qt: &pResult->m_Quaternion);
  }
  else
  {
    if ( flBalanceFilter > 0.5 )
      v8 = (float)((float)(1.0 - flBalanceFilter) * 2.0) * flBlend;
    else
      v8 = flBlend;
    if ( flBalanceFilter < 0.5 )
      v9 = (float)(flBalanceFilter * 2.0) * flBlend;
    else
      v9 = flBlend;
    pResult->m_pValue[0] = (float)((float)(dest->m_pValue[0] - src->m_pValue[0]) * flBlend) + src->m_pValue[0];
    pResult->m_pValue[2] = (float)((float)(dest->m_pValue[2] - src->m_pValue[2]) * v8) + src->m_pValue[2];
    pResult->m_pValue[1] = (float)((float)(dest->m_pValue[1] - src->m_pValue[1]) * v9) + src->m_pValue[1];
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048A590
// Name: public: virtual void CAttributeSlider::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::ApplySchemeSettings(CAttributeSlider *this, vgui::IScheme *scheme)
{
  vgui::TextImage_vtbl *v4; // ebx
  unsigned int v5; // eax
  vgui::TextImage_vtbl *v6; // ebx
  unsigned int v7; // eax
  vgui::TextImage_vtbl *v8; // ebx
  unsigned int v9; // eax
  vgui::TextImage_vtbl *v10; // ebx
  unsigned int v11; // eax
  vgui::TextImage_vtbl *v12; // ebx
  unsigned int v13; // eax

  vgui::Panel::ApplySchemeSettings(this, pScheme: scheme);
  v4 = this->m_pName->__vftable;
  v5 = scheme->GetFont(this: scheme, a2: "Default", a3: false);
  v4->SetFont(this: this->m_pName, a2: v5);
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pName->SetColor)(a1: this->m_pName, a2: s_TextColor);
  vgui::TextImage::ResizeImageToContent(this: this->m_pName);
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pValues[0]->SetColor)(a1: this->m_pValues[0], a2: s_TextColor);
  v6 = this->m_pValues[0]->__vftable;
  v7 = scheme->GetFont(this: scheme, a2: "Default", a3: false);
  v6->SetFont(this: this->m_pValues[0], a2: v7);
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pValues[1]->SetColor)(a1: this->m_pValues[1], a2: s_TextColorFocus);
  v8 = this->m_pValues[1]->__vftable;
  v9 = scheme->GetFont(this: scheme, a2: "Default", a3: false);
  v8->SetFont(this: this->m_pValues[1], a2: v9);
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pValues[2]->SetColor)(a1: this->m_pValues[2], a2: s_TextColor);
  v10 = this->m_pValues[2]->__vftable;
  v11 = scheme->GetFont(this: scheme, a2: "Default", a3: false);
  v10->SetFont(this: this->m_pValues[2], a2: v11);
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pValues[3]->SetColor)(a1: this->m_pValues[3], a2: s_TextColor);
  v12 = this->m_pValues[3]->__vftable;
  v13 = scheme->GetFont(this: scheme, a2: "Default", a3: false);
  v12->SetFont(this: this->m_pValues[3], a2: v13);
  ((void (__thiscall *)(CAttributeSlider *, int))this->SetBgColor)(a1: this, a2: -14013910);
  ((void (__thiscall *)(CAttributeSlider *, int))this->SetFgColor)(a1: this, a2: -16746302);
}

//------------------------------------------------------------------------------
// Address: 0x0048A710
// Name: public: void CAttributeSlider::SetValue(struct AttributeValue_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::SetValue(CAttributeSlider *this, const AttributeValue_t *value)
{
  float v2; // xmm0_4
  float v3; // xmm0_4
  float x; // xmm0_4

  if ( this->m_Control.m_pValue[0] != value->m_pValue[0] )
    this->m_Control.m_pValue[0] = value->m_pValue[0];
  v2 = value->m_pValue[1];
  if ( this->m_Control.m_pValue[1] != v2 )
    this->m_Control.m_pValue[1] = v2;
  v3 = value->m_pValue[2];
  if ( this->m_Control.m_pValue[2] != v3 )
    this->m_Control.m_pValue[2] = v3;
  x = value->m_Vector.x;
  if ( x != this->m_Control.m_Vector.x
    || value->m_Vector.y != this->m_Control.m_Vector.y
    || value->m_Vector.z != this->m_Control.m_Vector.z )
  {
    this->m_Control.m_Vector.x = x;
    this->m_Control.m_Vector.y = value->m_Vector.y;
    this->m_Control.m_Vector.z = value->m_Vector.z;
  }
  if ( this->m_Control.m_Quaternion.x != value->m_Quaternion.x
    || this->m_Control.m_Quaternion.y != value->m_Quaternion.y
    || this->m_Control.m_Quaternion.z != value->m_Quaternion.z
    || this->m_Control.m_Quaternion.w != value->m_Quaternion.w )
  {
    this->m_Control.m_Quaternion = value->m_Quaternion;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048A830
// Name: public: virtual void CAttributeSlider::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnCursorMoved(CAttributeSlider *this, int x, int y)
{
  bool v4; // zf
  float v5; // xmm0_4
  CBaseAnimationSetEditor *v6; // eax
  CBaseAnimationSetControl *Controller; // eax
  __m128 v8; // xmm0
  float v9; // xmm7_4
  float v10; // xmm6_4
  float v11; // xmm7_4
  float v12; // xmm1_4
  __m128 v13; // xmm0
  __m128 v14; // xmm2
  __m128 v15; // xmm4
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  int v18; // edi
  double v19; // st7
  int v20; // ecx
  float v21; // xmm0_4
  bool v22; // cf
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm5_4
  __m128 v29; // xmm2
  __m128 v30; // xmm4
  __m128 v31; // xmm1
  __m128 v32; // xmm2
  int v33; // edi
  double v34; // st7
  int v35; // ecx
  float v36; // xmm1_4
  float v37; // xmm0_4
  bool v38; // cc
  int v39; // edx
  Rect_t rect; // [esp+10h] [ebp-28h] BYREF
  float flValue; // [esp+20h] [ebp-18h]
  float flLeftValue; // [esp+24h] [ebp-14h]
  float flBalance; // [esp+28h] [ebp-10h]
  float flMinVal; // [esp+2Ch] [ebp-Ch]
  float flMaxVal; // [esp+30h] [ebp-8h]
  float flFactor; // [esp+34h] [ebp-4h]

  if ( !this->IsEnabled(this) || this->m_SliderMode != SLIDER_MODE_DRAG_VALUE || (*((_BYTE *)this + 656) & 1) != 0 )
    return;
  this->m_nAccum[0] += x - this->m_nDragStartPosition[0];
  v4 = ifm_attributeslider_legacy.m_pParent->m_Value.m_nValue == 0;
  flFactor = 1.0;
  if ( !v4 )
  {
    v5 = ifm_attributeslider_sensitivity.m_pParent->m_Value.m_fValue * 0.0024999999;
LABEL_8:
    flFactor = v5;
    goto LABEL_9;
  }
  CAttributeSlider::GetControlRect(this, pRect: &rect);
  if ( rect.width > 0 )
  {
    v5 = 1.0 / (float)rect.width;
    goto LABEL_8;
  }
LABEL_9:
  v6 = (CBaseAnimationSetEditor *)vgui::PHandle::Get(this: &this->m_pParent->m_hEditor);
  Controller = CBaseAnimationSetEditor::GetController(this: v6);
  if ( Controller->GetRecordingState(this: Controller) == AS_RECORD )
  {
    v8 = (__m128)0xBF800000;
    v9 = 2.0;
    flMinVal = -1.0;
  }
  else
  {
    v8 = 0;
    flMinVal = 0.0;
    v9 = 1.0;
  }
  v4 = (*((_BYTE *)this + 656) & 4) == 0;
  flMaxVal = v9;
  if ( v4 )
  {
    v28 = this->m_dragStartValues.m_pValue[0];
    v29.m128_i32[0] = 1258291200;
    v8.m128_f32[0] = (float)(v8.m128_f32[0] - v28) * (float)(1.0 / flFactor);
    v30 = _mm_and_ps((__m128)0x80000000, v8);
    v29.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v8, v30), v29).m128_f32[0]) & 0x4B000000
                    | v30.m128_i32[0];
    v31 = v8;
    v31.m128_f32[0] = (float)(v8.m128_f32[0] + v29.m128_f32[0]) - v29.m128_f32[0];
    v32 = v31;
    v32.m128_f32[0] = v31.m128_f32[0] - v8.m128_f32[0];
    flValue = v28;
    v33 = (int)(float)(v31.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v32, v30).m128_u32[0] & 0x3F800000));
    v34 = ceil(X: (float)((float)(v9 - v28) * (float)(1.0 / flFactor)));
    v35 = this->m_nAccum[0];
    if ( v35 >= v33 )
    {
      if ( v35 > (int)v34 )
        v35 = (int)v34;
    }
    else
    {
      v35 = v33;
    }
    v36 = flMinVal;
    v37 = (float)((float)v35 * flFactor) + flValue;
    v38 = flMinVal <= v37;
    this->m_nAccum[0] = v35;
    if ( !v38 || (v36 = flMaxVal, v37 > flMaxVal) )
      v37 = v36;
    if ( this->m_Control.m_pValue[0] != v37 )
      this->m_Control.m_pValue[0] = v37;
  }
  else
  {
    flBalance = CBaseAnimSetAttributeSliderPanel::GetBalanceSliderValue(this: this->m_pParent);
    v11 = this->m_dragStartValues.m_pValue[1];
    flLeftValue = this->m_dragStartValues.m_pValue[2];
    v10 = flLeftValue;
    flValue = v11;
    if ( flLeftValue <= v11 )
      v12 = v11;
    else
      v12 = flLeftValue;
    v13 = (__m128)LODWORD(flMinVal);
    v14.m128_i32[0] = 1258291200;
    v13.m128_f32[0] = (float)(flMinVal - v12) * (float)(1.0 / flFactor);
    v15 = _mm_and_ps((__m128)0x80000000, v13);
    v14.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v13, v15), v14).m128_f32[0]) & 0x4B000000
                    | v15.m128_i32[0];
    v16 = v13;
    v16.m128_f32[0] = (float)(v13.m128_f32[0] + v14.m128_f32[0]) - v14.m128_f32[0];
    v17 = v16;
    v17.m128_f32[0] = v16.m128_f32[0] - v13.m128_f32[0];
    v18 = (int)(float)(v16.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v17, v15).m128_u32[0] & 0x3F800000));
    if ( v11 <= flLeftValue )
      v10 = v11;
    v19 = ceil(X: (float)((float)(flMaxVal - v10) * (float)(1.0 / flFactor)));
    v20 = this->m_nAccum[0];
    if ( v20 >= v18 )
    {
      if ( v20 > (int)v19 )
        v20 = (int)v19;
    }
    else
    {
      v20 = v18;
    }
    v21 = flBalance;
    v22 = flBalance > 0.5;
    v23 = (float)v20 * flFactor;
    this->m_nAccum[0] = v20;
    if ( v22 )
      v24 = (float)((float)(1.0 - v21) * 2.0) * v23;
    else
      v24 = v23;
    if ( v21 < 0.5 )
      v25 = (float)(v21 * 2.0) * v23;
    else
      v25 = v23;
    v26 = v24 + flLeftValue;
    if ( flMinVal <= v26 )
    {
      if ( v26 > flMaxVal )
        v26 = flMaxVal;
    }
    else
    {
      v26 = flMinVal;
    }
    v27 = v25 + flValue;
    if ( flMinVal <= v27 )
    {
      if ( v27 > flMaxVal )
        v27 = flMaxVal;
    }
    else
    {
      v27 = flMinVal;
    }
    if ( this->m_Control.m_pValue[2] != v26 )
      this->m_Control.m_pValue[2] = v26;
    if ( this->m_Control.m_pValue[1] != v27 )
      this->m_Control.m_pValue[1] = v27;
  }
  if ( x != this->m_nDragStartPosition[0] || y != this->m_nDragStartPosition[1] )
  {
    v39 = this->m_nDragStartPosition[1];
    x = this->m_nDragStartPosition[0];
    y = v39;
    vgui::Panel::LocalToScreen(this, &x, &y);
    g_pVGuiInput->SetCursorPos(this: g_pVGuiInput, a2: x, a3: y);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048AC20
// Name: public: void CAttributeSlider::UpdateFaderAmount(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::UpdateFaderAmount(CAttributeSlider *this, float flAmount)
{
  bool v2; // zf
  float v3; // xmm4_4
  float v4; // xmm5_4

  v2 = (*((_BYTE *)this + 656) & 1) == 0;
  this->m_flFaderAmount = flAmount;
  if ( v2 )
  {
    this->m_PreviewCurrent.m_pValue[0] = (float)((float)(this->m_PreviewFull.m_pValue[0] - this->m_Control.m_pValue[0])
                                               * flAmount)
                                       + this->m_Control.m_pValue[0];
    this->m_PreviewCurrent.m_pValue[2] = (float)((float)(this->m_PreviewFull.m_pValue[2] - this->m_Control.m_pValue[2])
                                               * flAmount)
                                       + this->m_Control.m_pValue[2];
    this->m_PreviewCurrent.m_pValue[1] = (float)((float)(this->m_PreviewFull.m_pValue[1] - this->m_Control.m_pValue[1])
                                               * flAmount)
                                       + this->m_Control.m_pValue[1];
  }
  else
  {
    v3 = this->m_Control.m_Vector.y
       + (float)((float)(this->m_PreviewFull.m_Vector.y - this->m_Control.m_Vector.y) * flAmount);
    v4 = this->m_Control.m_Vector.z
       + (float)((float)(this->m_PreviewFull.m_Vector.z - this->m_Control.m_Vector.z) * flAmount);
    this->m_PreviewCurrent.m_Vector.x = this->m_Control.m_Vector.x
                                      + (float)((float)(this->m_PreviewFull.m_Vector.x - this->m_Control.m_Vector.x)
                                              * flAmount);
    this->m_PreviewCurrent.m_Vector.y = v3;
    this->m_PreviewCurrent.m_Vector.z = v4;
    QuaternionSlerp(
      p: &this->m_Control.m_Quaternion,
      q: &this->m_PreviewFull.m_Quaternion,
      t: flAmount,
      qt: &this->m_PreviewCurrent.m_Quaternion);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048AD40
// Name: public: float CAttributeSlider::EstimateValueAtPos(int,int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAttributeSlider::EstimateValueAtPos(CAttributeSlider *this, int nLocalX, int nLocalY)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  int tall; // [esp+0h] [ebp-8h] BYREF
  int wide; // [esp+4h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  if ( wide - 12 <= 1 )
    return 0.5;
  v3 = (float)(nLocalX - 6) / (float)(wide - 13);
  v4 = 0.0;
  if ( v3 < 0.0 )
    return v4;
  v4 = 1.0;
  if ( v3 > 1.0 )
    return v4;
  else
    return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0048ADC0
// Name: public: virtual void CAttributeSlider::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::PerformLayout(CAttributeSlider *this)
{
  int v2; // ebx
  CAttributeSliderTextEntry *m_pTextField; // ecx
  int v4; // kr00_4
  int v5; // edi
  int tall; // [esp+4h] [ebp-8h] BYREF
  int wide; // [esp+8h] [ebp-4h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  if ( this->m_pTextField != nullptr )
  {
    vgui::Panel::GetSize(this, &wide, &tall);
    v2 = (tall - 6) & ((tall - 6 < 0) - 1);
    m_pTextField = this->m_pTextField;
    if ( (*((_BYTE *)this + 656) & 4) != 0 )
    {
      v4 = wide - 12;
      v5 = (wide - 12) / 2;
      vgui::Panel::SetBounds(this: m_pTextField, x: 6, y: 3, wide: v5, tall: (tall - 6) & ((tall - 6 < 0) - 1));
      vgui::Panel::SetBounds(this: this->m_pRightTextField, x: v5 + 6, y: 3, wide: v4 / 2, tall: v2);
    }
    else
    {
      vgui::Panel::SetBounds(this: m_pTextField, x: 6, y: 3, wide: wide - 12, tall: (tall - 6) & ((tall - 6 < 0) - 1));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048AE50
// Name: private: void CAttributeSlider::DrawTick(class Color const __near &,struct AttributeValue_t const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::DrawTick(
        CAttributeSlider *this,
        const Color *clr,
        const AttributeValue_t *value,
        int width,
        int inset)
{
  char *v6; // ecx
  float v7; // xmm0_4
  int v8; // edi
  __int64 v9; // rax
  int v10; // esi
  int v11; // ebx
  int v12; // eax
  int v13; // ecx
  int v14; // edi
  vgui::ISurface_vtbl *v15; // ecx
  int v16; // eax
  float v17; // xmm0_4
  int v18; // esi
  int v19; // ecx
  int v20; // [esp+Ch] [ebp-8h]
  int tall; // [esp+10h] [ebp-4h] BYREF

  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: *clr);
  vgui::Panel::GetSize(this, wide: (int *)&clr, &tall);
  v6 = (char *)&clr[-4] + 2;
  v7 = (float)((int)&clr[-4] + 2);
  v8 = ((tall - 6) & ((tall - 6 < 0) - 1)) - 2 - 2 * inset;
  v9 = ((tall - 6) & ((tall - 6 < 0) - 1)) - (((tall - 6) & ((tall - 6 < 0) - 1)) - 2 * inset);
  v10 = (((int)v9 - HIDWORD(v9)) >> 1) + 4;
  if ( (*((_BYTE *)this + 656) & 4) != 0 )
  {
    v11 = width / 2;
    v12 = (int)(float)((float)(value->m_pValue[2] * v7) + 0.5) - width / 2 + 7;
    v13 = (int)&v6[-width + 7];
    v14 = v8 / 2;
    *(float *)&tall = (float)((int)&clr[-4] + 2);
    v20 = v13;
    if ( v12 >= 7 )
    {
      if ( v12 > v13 )
        v12 = v13;
    }
    else
    {
      v12 = 7;
    }
    v15 = g_pVGuiSurface->__vftable;
    clr = (const Color *)(v10 + v14);
    inset = (int)v15;
    v15->DrawFilledRect(this: g_pVGuiSurface, a2: v12, a3: v10, a4: v12 + width, a5: v10 + v14);
    v16 = (int)(float)((float)(value->m_pValue[1] * *(float *)&tall) + 0.5) - v11 + 7;
    if ( v16 >= 7 )
    {
      if ( v16 > v20 )
        v16 = v20;
    }
    else
    {
      v16 = 7;
    }
    g_pVGuiSurface->DrawFilledRect(
      this: g_pVGuiSurface,
      a2: v16,
      a3: (int)clr,
      a4: v16 + width,
      a5: (int)&clr->_color[v14]);
  }
  else
  {
    v17 = (float)(v7 * value->m_pValue[0]) + 0.5;
    clr = (const Color *)(v8 + v10);
    v18 = (int)v17 - width / 2 + 7;
    v19 = (int)&v6[-width + 7];
    if ( v18 >= 7 )
    {
      if ( v18 > v19 )
        v18 = v19;
    }
    else
    {
      v18 = 7;
    }
    g_pVGuiSurface->DrawFilledRect(
      this: g_pVGuiSurface,
      a2: v18,
      a3: (int)clr,
      a4: v18 + width,
      a5: (int)&clr->_color[v8]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048AFF0
// Name: public: virtual void CAttributeSlider::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::Paint(CAttributeSlider *this)
{
  bool v2; // bl
  CBaseAnimationSetControl *v3; // eax
  bool v4; // bl
  CBaseAnimationSetEditor *v5; // eax
  CBaseAnimSetPresetFaderPanel *PresetFader; // eax
  bool v7; // al
  float m_flFaderAmount; // xmm0_4
  Color col; // [esp+4h] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 656) & 1) == 0 )
  {
    CAttributeSlider::DrawTick(this, clr: &s_OldValueTickColor, value: &this->m_Control, width: 1, inset: 0);
    v2 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
      || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT);
    v3 = this->m_pParent->GetController(this: this->m_pParent);
    v4 = vgui::PHandle::Get(this: &v3->m_ActiveAttributeSlider) == this
      && this->m_SliderMode != SLIDER_MODE_DRAG_VALUE
      && v2;
    v5 = (CBaseAnimationSetEditor *)vgui::PHandle::Get(this: &this->m_pParent->m_hEditor);
    PresetFader = CBaseAnimationSetEditor::GetPresetFader(this: v5);
    v7 = CBaseAnimSetPresetFaderPanel::GetActivePresetSlider(this: PresetFader) != nullptr;
    if ( v4 || v7 )
    {
      m_flFaderAmount = this->m_flFaderAmount;
      col = s_PreviewTickColor;
      if ( m_flFaderAmount <= 0.1 )
        m_flFaderAmount = 0.1;
      col._color[3] = (int)(float)((float)s_PreviewTickColor._color[3] * m_flFaderAmount);
      CAttributeSlider::DrawTick(this, clr: &col, value: &this->m_PreviewFull, width: 2, inset: 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048B100
// Name: private: void CAttributeSlider::DrawValueLabel(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAttributeSlider::DrawValueLabel(CAttributeSlider *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // ebx
  int v5; // edi
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  int v9; // xmm1_4
  float v10; // xmm1_4
  char sz[32]; // [esp+50h] [ebp-30h] BYREF
  int tall; // [esp+70h] [ebp-10h] BYREF
  int wide; // [esp+74h] [ebp-Ch] BYREF
  int cw; // [esp+78h] [ebp-8h] BYREF
  int v17; // [esp+7Ch] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 656) & 1) == 0 )
  {
    vgui::Panel::GetSize(this, &wide, &tall);
    v4 = wide - 12;
    v5 = (tall - 6) & ((tall - 6 < 0) - 1);
    V_snprintf(pDest: sz, maxLen: 32, pFormat: "%.1f", 0.0);
    ((void (__thiscall *)(vgui::TextImage *, char *, int, int))this->m_pValues[0]->SetText_2)(
      a1: this->m_pValues[0],
      a2: sz,
      a3,
      a4: a2);
    vgui::TextImage::ResizeImageToContent(this: this->m_pValues[0]);
    this->m_pValues[0]->GetContentSize(this: this->m_pValues[0], a2: &cw, a3: &v17);
    this->m_pValues[0]->SetPos(
      this: this->m_pValues[0],
      a2: 11,
      a3: (int)(float)((float)((float)(v5 - v17) * 0.5) + 3.0));
    this->m_pValues[0]->Paint(this: this->m_pValues[0]);
    V_snprintf(pDest: sz, maxLen: 32, pFormat: "%.1f", 1.0);
    this->m_pValues[1]->SetText_2(this: this->m_pValues[1], a2: sz);
    vgui::TextImage::ResizeImageToContent(this: this->m_pValues[1]);
    this->m_pValues[1]->GetContentSize(this: this->m_pValues[1], a2: &cw, a3: &v17);
    this->m_pValues[1]->SetPos(
      this: this->m_pValues[1],
      a2: v4 - cw + 1,
      a3: (int)(float)((float)((float)(v5 - v17) * 0.5) + 3.0));
    this->m_pValues[1]->Paint(this: this->m_pValues[1]);
    v6 = 0.0;
    if ( (*((_BYTE *)this + 656) & 4) != 0 )
    {
      v7 = this->m_Control.m_pValue[2];
      if ( v7 >= 0.0 )
      {
        if ( v7 <= 1.0 )
          v6 = this->m_Control.m_pValue[2];
        else
          v6 = 1.0;
      }
      V_snprintf(pDest: sz, maxLen: 32, pFormat: "%.3f", v6);
      this->m_pValues[2]->SetText_2(this: this->m_pValues[2], a2: sz);
      vgui::TextImage::ResizeImageToContent(this: this->m_pValues[2]);
      this->m_pValues[2]->GetContentSize(this: this->m_pValues[2], a2: &cw, a3: &v17);
      this->m_pValues[2]->SetPos(
        this: this->m_pValues[2],
        a2: (int)(float)((float)((float)(v4 - cw) * 0.40000001) + 6.0),
        a3: (int)(float)((float)((float)(v5 - v17) * 0.5) + 3.0));
      this->m_pValues[2]->Paint(this: this->m_pValues[2]);
      v8 = this->m_Control.m_pValue[1];
      v9 = 0;
      if ( v8 < 0.0 || (v9 = 1065353216, v8 > 1.0) )
        v8 = *(float *)&v9;
      V_snprintf(pDest: sz, maxLen: 32, pFormat: "%.3f", v8);
      this->m_pValues[3]->SetText_2(this: this->m_pValues[3], a2: sz);
      vgui::TextImage::ResizeImageToContent(this: this->m_pValues[3]);
      ((void (__thiscall *)(vgui::TextImage *))this->m_pValues[3]->GetContentSize)(a1: this->m_pValues[3]);
      this->m_pValues[3]->SetPos(
        this: this->m_pValues[3],
        a2: (int)(float)((float)((float)(v4 - cw) * 0.60000002) + 6.0),
        a3: (int)(float)((float)((float)(v5 - v17) * 0.5) + 3.0));
      this->m_pValues[3]->Paint(this: this->m_pValues[3]);
    }
    else
    {
      v10 = this->m_Control.m_pValue[0];
      if ( v10 >= 0.0 )
      {
        v6 = 1.0;
        if ( v10 <= 1.0 )
          v6 = this->m_Control.m_pValue[0];
      }
      V_snprintf(pDest: sz, maxLen: 32, pFormat: "%.3f", v6);
      this->m_pValues[2]->SetText_2(this: this->m_pValues[2], a2: sz);
      vgui::TextImage::ResizeImageToContent(this: this->m_pValues[2]);
      ((void (__thiscall *)(vgui::TextImage *))this->m_pValues[2]->GetContentSize)(a1: this->m_pValues[2]);
      this->m_pValues[2]->SetPos(
        this: this->m_pValues[2],
        a2: (int)(float)((float)((float)(v4 - cw) * 0.5) + 6.0),
        a3: (int)(float)((float)((float)(v5 - v17) * 0.5) + 3.0));
      this->m_pValues[2]->Paint(this: this->m_pValues[2]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048B4E0
// Name: private: void CAttributeSlider::DrawNameLabel(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAttributeSlider::DrawNameLabel(CAttributeSlider *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  CAttributeSlider::SliderMode_t m_SliderMode; // eax
  vgui::PHandle *v5; // eax
  Rect_t rect; // [esp+4h] [ebp-18h] BYREF
  int cw; // [esp+14h] [ebp-8h] BYREF
  int v8; // [esp+18h] [ebp-4h] BYREF

  m_SliderMode = this->m_SliderMode;
  if ( m_SliderMode == SLIDER_MODE_DRAG_VALUE )
  {
    CAttributeSlider::DrawValueLabel(this, a2, a3);
  }
  else if ( m_SliderMode != SLIDER_MODE_TEXT && this->m_pName != nullptr )
  {
    v5 = (vgui::PHandle *)((int (__thiscall *)(CBaseAnimSetAttributeSliderPanel *, int))this->m_pParent->GetController)(
                            a1: this->m_pParent,
                            a2: a3);
    vgui::PHandle::Get(this: v5 + 27);
    ((void (__thiscall *)(vgui::TextImage *))this->m_pName->SetColor)(a1: this->m_pName);
    this->m_pName->GetContentSize(this: this->m_pName, a2: &cw, a3: &v8);
    CAttributeSlider::GetControlRect(this, pRect: &rect);
    this->m_pName->SetPos(
      this: this->m_pName,
      a2: (int)(float)((float)((float)(rect.width - cw) * 0.5) + (float)rect.x),
      a3: (int)(float)((float)((float)(rect.height - v8) * 0.5) + (float)rect.y));
    this->m_pName->Paint(this: this->m_pName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048B5F0
// Name: public: virtual void CAttributeSlider::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnMousePressed(CAttributeSlider *this, ButtonCode_t code)
{
  CAttributeSlider::SliderMode_t m_SliderMode; // eax
  CDmElement *v4; // eax
  int v5; // edx
  vgui::IInput *v6; // edi
  vgui::IInput_vtbl *v7; // ebx
  int v8; // eax
  int y; // [esp+4h] [ebp-8h] BYREF
  int x; // [esp+8h] [ebp-4h] BYREF

  if ( this->IsEnabled(this) )
  {
    m_SliderMode = this->m_SliderMode;
    if ( m_SliderMode != SLIDER_MODE_TEXT && m_SliderMode != SLIDER_MODE_DRAG_VALUE && code == KEY_COUNT )
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hControl.m_handle);
      this->m_pParent->GetTypeInValueForControl(
        this: this->m_pParent,
        a2: v4,
        a3: (*((_BYTE *)this + 656) & 2) != 0,
        a4: &this->m_InitialTextEntryValue,
        a5: &this->m_Control);
      if ( (*((_BYTE *)this + 656) & 1) == 0 )
      {
        g_pVGuiInput->GetCursorPosition(this: g_pVGuiInput, a2: &x, a3: &y);
        vgui::Panel::ScreenToLocal(this, &x, &y);
        v5 = x;
        this->m_nDragStartPosition[1] = y;
        this->m_SliderMode = SLIDER_MODE_DRAG_VALUE;
        this->m_nDragStartPosition[0] = v5;
        this->m_nAccum[1] = 0;
        this->m_nAccum[0] = 0;
        AttributeValue_t::operator=(this: &this->m_dragStartValues, __that: &this->m_Control);
        v6 = g_pVGuiInput;
        v7 = g_pVGuiInput->__vftable;
        v8 = this->GetVPanel(this);
        v7->SetMouseCapture(this: v6, a2: v8);
        this->SetCursor(this, a2: 15u);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048B710
// Name: private: void CAttributeSlider::StampValueIntoLogs(enum AnimationControlType_t,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::StampValueIntoLogs(
        CAttributeSlider *this,
        AnimationControlType_t type,
        const Vector *vecValue)
{
  CDmElement *v4; // eax

  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hControl.m_handle);
  this->m_pParent->StampValueIntoLogs_2(this: this->m_pParent, a2: v4, a3: type, a4: vecValue);
}

//------------------------------------------------------------------------------
// Address: 0x0048B750
// Name: private: void CAttributeSlider::AcceptTextEntryValue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::AcceptTextEntryValue(CAttributeSlider *this)
{
  CDmElement *v2; // eax
  CDmeTransformControl *v3; // edi
  float v4; // xmm0_4
  DmElementHandle_t m_handle; // eax
  CDmElement *v6; // eax
  float v7; // xmm0_4
  DmElementHandle_t v8; // eax
  CDmElement *v9; // eax
  DmElementHandle_t v10; // eax
  CDmElement *v11; // eax
  CAttributeSlider *v12; // ecx
  const Quaternion *Orientation; // eax
  void (__thiscall *RequestFocus)(vgui::IClientPanel *, int); // eax
  char str[64]; // [esp+8h] [ebp-90h] BYREF
  char buf[64]; // [esp+48h] [ebp-50h] BYREF
  Vector vecValue; // [esp+88h] [ebp-10h] BYREF
  float flRightValue; // [esp+94h] [ebp-4h] BYREF

  if ( this->m_SliderMode == SLIDER_MODE_TEXT )
  {
    this->m_pTextField->GetText_2(this: this->m_pTextField, a2: buf, a3: 64);
    this->m_pTextField->SetVisible(this: this->m_pTextField, a2: false);
    this->m_pTextField->SetEnabled(this: this->m_pTextField, a2: false);
    v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hControl.m_handle);
    v3 = (CDmeTransformControl *)v2;
    if ( v2 == nullptr || !v2->IsA(this: v2, a2: CDmeTransformControl::m_classType) )
      v3 = nullptr;
    if ( (*((_BYTE *)this + 656) & 1) != 0 )
    {
      if ( v3 != nullptr )
      {
        if ( sscanf(string: buf, format: "%f %f %f", &vecValue, &vecValue.y, &vecValue.z) == 3 )
        {
          if ( (*((_BYTE *)this + 656) & 2) != 0 )
          {
            CAttributeSlider::StampValueIntoLogs(this, type: ANIM_CONTROL_TXFORM_ORIENTATION, &vecValue);
            Orientation = CDmeTransformControl::GetOrientation(this: v3);
            CAttributeSlider::SetValue(this, type: ANIM_CONTROL_TXFORM_ORIENTATION, quat: Orientation);
          }
          else
          {
            CAttributeSlider::SetValue(this, type: ANIM_CONTROL_COUNT, vec: &vecValue);
            CAttributeSlider::StampValueIntoLogs(this: v12, type: ANIM_CONTROL_COUNT, &vecValue);
          }
        }
        this->m_pParent->UpdatePreview(this: this->m_pParent, a2: "AcceptTextEntryValue\n");
      }
    }
    else
    {
      flRightValue = V_atof(str: buf);
      v4 = flRightValue;
      if ( (*((_BYTE *)this + 656) & 4) != 0 )
      {
        if ( this->m_Control.m_pValue[2] != flRightValue )
          this->m_Control.m_pValue[2] = flRightValue;
        m_handle = this->m_hControl.m_handle;
        flRightValue = v4;
        v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_handle);
        this->m_pParent->StampValueIntoLogs_3(
          this: this->m_pParent,
          a2: v6,
          a3: ANIM_CONTROL_VALUE_LEFT,
          a4: &flRightValue);
        this->m_pRightTextField->GetText_2(this: this->m_pRightTextField, a2: str, a3: 64);
        flRightValue = V_atof(str);
        this->m_pRightTextField->SetVisible(this: this->m_pRightTextField, a2: false);
        this->m_pRightTextField->SetEnabled(this: this->m_pRightTextField, a2: false);
        v7 = flRightValue;
        if ( this->m_Control.m_pValue[1] != flRightValue )
          this->m_Control.m_pValue[1] = flRightValue;
        v8 = this->m_hControl.m_handle;
        flRightValue = v7;
        v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v8);
        this->m_pParent->StampValueIntoLogs_3(
          this: this->m_pParent,
          a2: v9,
          a3: ANIM_CONTROL_VALUE_RIGHT,
          a4: &flRightValue);
      }
      else
      {
        if ( this->m_Control.m_pValue[0] != flRightValue )
          this->m_Control.m_pValue[0] = flRightValue;
        v10 = this->m_hControl.m_handle;
        flRightValue = v4;
        v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: v10);
        this->m_pParent->StampValueIntoLogs_3(this: this->m_pParent, a2: v11, a3: ANIM_CONTROL_VALUE, a4: &flRightValue);
      }
    }
    RequestFocus = this->RequestFocus;
    this->m_SliderMode = SLIDER_MODE_NONE;
    RequestFocus(this, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048B9E0
// Name: public: virtual void CAttributeSliderTextEntry::OnKillFocus(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSliderTextEntry::OnKillFocus(CAttributeSliderTextEntry *this, KeyValues *pParams)
{
  void *Ptr; // eax
  CAttributeSlider *m_pSlider; // esi
  unsigned int v5; // ebx

  this->SelectNone(this);
  Ptr = KeyValues::GetPtr(this: pParams, keyName: "newPanel", defaultValue: nullptr);
  if ( Ptr == (void *)-1
    || (m_pSlider = this->m_pSlider,
        (v5 = g_pVGuiPanel->GetParent(this: g_pVGuiPanel, a2: (unsigned int)Ptr)) != m_pSlider->GetVPanel(this: m_pSlider)) )
  {
    CAttributeSlider::AcceptTextEntryValue(this: this->m_pSlider);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048BA40
// Name: public: virtual void CAttributeSliderTextEntry::OnMouseWheeled(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSliderTextEntry::OnMouseWheeled(CAttributeSliderTextEntry *this, float delta)
{
  float v3; // xmm0_4
  bool v4; // al
  float v5; // xmm0_4
  void (__thiscall *GetText_2)(vgui::TextEntry *, char *, int); // edx
  double v7; // st7
  bool (__thiscall *IsKeyDown)(vgui::IInput *, ButtonCode_t); // eax
  float v9; // xmm0_4
  CAttributeSlider *m_pSlider; // ecx
  CAttributeSlider *v11; // esi
  CDmElement *v12; // eax
  char sz[64]; // [esp+20h] [ebp-40h] BYREF

  if ( (*((_BYTE *)this->m_pSlider + 656) & 5) == 0 )
  {
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT) )
    {
      v3 = (float)SLODWORD(delta) * 10.0;
    }
    else
    {
      v4 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL);
      v5 = (float)SLODWORD(delta);
      if ( v4 )
        v3 = v5 * 0.01;
      else
        v3 = v5 * 0.1;
    }
    GetText_2 = this->GetText_2;
    delta = v3;
    GetText_2(this, a2: sz, a3: 64);
    v7 = V_atof(str: sz);
    IsKeyDown = g_pVGuiInput->IsKeyDown;
    delta = v7 + delta;
    if ( IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT) )
    {
      v9 = 0.0;
      if ( delta >= 0.0 )
      {
        v9 = 1.0;
        if ( delta <= 1.0 )
          v9 = delta;
      }
      delta = v9;
    }
    V_snprintf(pDest: sz, maxLen: 64, pFormat: "%f", delta);
    this->SetText(this, a2: sz);
    m_pSlider = this->m_pSlider;
    if ( m_pSlider->m_Control.m_pValue[0] != delta )
      m_pSlider->m_Control.m_pValue[0] = delta;
    g_pDataModel->StartUndo(this: g_pDataModel, a2: "Set Slider Value", a3: "Set Slider Value", a4: 9876);
    v11 = this->m_pSlider;
    v12 = g_pDataModel->GetElement(this: g_pDataModel, a2: v11->m_hControl.m_handle);
    v11->m_pParent->StampValueIntoLogs_3(this: v11->m_pParent, a2: v12, a3: ANIM_CONTROL_VALUE, a4: &delta);
    g_pDataModel->FinishUndo(this: g_pDataModel);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048BBE0
// Name: public: virtual void CAttributeSlider::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnKeyCodeTyped(CAttributeSlider *this, ButtonCode_t code)
{
  if ( this->m_SliderMode == SLIDER_MODE_TEXT )
  {
    if ( code == KEY_ENTER )
    {
      CAttributeSlider::AcceptTextEntryValue(this);
    }
    else if ( code == KEY_ESCAPE )
    {
      CAttributeSlider::DiscardTextEntryValue(this);
    }
    else
    {
      vgui::EditablePanel::OnKeyCodeTyped(this, code);
    }
  }
  else
  {
    vgui::EditablePanel::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048BC20
// Name: public: bool CAttributeSlider::IsDependent(class CAttributeSlider const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAttributeSlider::IsDependent(CAttributeSlider *this, const CAttributeSlider *pSlider)
{
  int m_Size; // edx
  int v3; // eax
  const CAttributeSlider **m_pMemory; // ecx

  m_Size = this->m_Dependenices.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    m_pMemory = this->m_Dependenices.m_Memory.m_pMemory;
    while ( *m_pMemory != pSlider )
    {
      ++v3;
      ++m_pMemory;
      if ( v3 >= m_Size )
        goto LABEL_5;
    }
  }
  return v3 != -1;
}

//------------------------------------------------------------------------------
// Address: 0x0048BD30
// Name: public: virtual CAttributeSlider::~CAttributeSlider(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::~CAttributeSlider(CAttributeSlider *this)
{
  vgui::TextImage *m_pName; // ecx
  vgui::TextImage *v3; // ecx
  vgui::TextImage *v4; // ecx
  vgui::TextImage *v5; // ecx
  vgui::TextImage *v6; // ecx

  m_pName = this->m_pName;
  this->__vftable = (CAttributeSlider_vtbl *)&CAttributeSlider::`vftable';
  if ( m_pName != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pName->dtr_IImage)(a1: m_pName, a2: 1);
  v3 = this->m_pValues[0];
  if ( v3 != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))v3->dtr_IImage)(a1: v3, a2: 1);
  v4 = this->m_pValues[1];
  if ( v4 != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))v4->dtr_IImage)(a1: v4, a2: 1);
  v5 = this->m_pValues[2];
  if ( v5 != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))v5->dtr_IImage)(a1: v5, a2: 1);
  v6 = this->m_pValues[3];
  if ( v6 != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))v6->dtr_IImage)(a1: v6, a2: 1);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Dependenices);
  if ( g_pDataModel != nullptr )
    CDmeElementRefHelper::Unref(this: &this->m_hControl, hElement: this->m_hControl.m_handle, handleType: HT_WEAK);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x0048BDD0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeSlider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeSlider::GetMessageMap(CAttributeSlider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeSlider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSlider::GetMessageMap'::`2'::s_pMap;
  `CAttributeSlider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeSlider");
  `CAttributeSlider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048BE00
// Name: public: virtual struct PanelAnimationMap __near * CAttributeSlider::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeSlider::GetAnimMap(CAttributeSlider *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeSlider");
}

//------------------------------------------------------------------------------
// Address: 0x0048BE10
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeSlider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeSlider::GetKBMap(CAttributeSlider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeSlider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSlider::GetKBMap'::`2'::s_pMap;
  `CAttributeSlider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSlider");
  `CAttributeSlider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048BE40
// Name: public: void CAttributeSlider::InitControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::InitControls(CAttributeSlider *this)
{
  char v2; // al
  CDmElement *v3; // eax
  CDmeTransformControl *v4; // edi
  const Quaternion *Orientation; // eax
  const Vector *Position; // eax
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // edx
  CDmElement *v8; // eax
  float m_Storage; // xmm0_4
  CDmElement *v10; // eax
  float v11; // xmm0_4
  CDmElement *v12; // eax
  float v13; // xmm0_4
  DmElementHandle_t m_handle; // [esp-4h] [ebp-Ch]

  v2 = *((_BYTE *)this + 656);
  if ( (v2 & 1) != 0 )
  {
    v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hControl.m_handle);
    v4 = (CDmeTransformControl *)v3;
    if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmeTransformControl::m_classType) )
    {
      if ( (*((_BYTE *)this + 656) & 2) != 0 )
      {
        Orientation = CDmeTransformControl::GetOrientation(this: v4);
        CAttributeSlider::SetValue(this, type: ANIM_CONTROL_TXFORM_ORIENTATION, quat: Orientation);
      }
      else
      {
        Position = CDmeTransformControl::GetPosition(this: v4);
        CAttributeSlider::SetValue(this, type: ANIM_CONTROL_COUNT, vec: Position);
      }
    }
  }
  else
  {
    GetElement = g_pDataModel->GetElement;
    m_handle = this->m_hControl.m_handle;
    if ( (v2 & 4) != 0 )
    {
      v8 = (CDmElement *)((int (__stdcall *)(DmElementHandle_t))GetElement)(a1: m_handle);
      m_Storage = CDmElement::GetValue<float>(this: v8, pAttributeName: "leftValue")->m_Storage;
      if ( this->m_Control.m_pValue[2] != m_Storage )
        this->m_Control.m_pValue[2] = m_Storage;
      v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hControl.m_handle);
      v11 = CDmElement::GetValue<float>(this: v10, pAttributeName: "rightValue")->m_Storage;
      if ( this->m_Control.m_pValue[1] != v11 )
        this->m_Control.m_pValue[1] = v11;
    }
    else
    {
      v12 = (CDmElement *)((int (__stdcall *)(DmElementHandle_t))GetElement)(a1: m_handle);
      v13 = CDmElement::GetValue<float>(this: v12, pAttributeName: "value")->m_Storage;
      if ( this->m_Control.m_pValue[0] != v13 )
        this->m_Control.m_pValue[0] = v13;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048BF70
// Name: private: void CAttributeSlider::SetToDefault(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::SetToDefault(CAttributeSlider *this)
{
  char v2; // al
  CDmElement *v3; // eax
  CDmaVar<Quaternion> *v4; // edi
  CDmElement *v5; // eax
  CDmElement *v6; // eax
  CDmaVar<Vector> *v7; // edi
  CDmElement *v8; // eax
  CDmElement *v9; // eax
  CDmAttribute *Attribute; // eax
  CDmaVar<float> *v11; // eax
  bool v12; // zf
  float m_Storage; // xmm0_4
  DmElementHandle_t v14; // edx
  CDmElement *v15; // eax
  DmElementHandle_t v16; // eax
  CDmElement *v17; // eax
  CBaseAnimSetAttributeSliderPanel *m_pParent; // ecx
  DmElementHandle_t m_handle; // eax
  int v20; // [esp+0h] [ebp-10h]
  int v21; // [esp+0h] [ebp-10h]
  int v22; // [esp+4h] [ebp-Ch]
  float *p_x; // [esp+4h] [ebp-Ch]
  float v24; // [esp+8h] [ebp-8h] BYREF
  float flDefaultValue; // [esp+Ch] [ebp-4h]

  v2 = *((_BYTE *)this + 656);
  if ( (v2 & 1) != 0 )
  {
    if ( (v2 & 2) != 0 )
    {
      v3 = (CDmElement *)((int (__stdcall *)(DmElementHandle_t, int, int))g_pDataModel->GetElement)(
                           a1: this->m_hControl.m_handle,
                           a2: v20,
                           a3: v22);
      v4 = CDmElement::GetValue<Quaternion>(this: v3, pAttributeName: "defaultOrientation");
      CAttributeSlider::SetValue(this, type: ANIM_CONTROL_TXFORM_ORIENTATION, quat: &v4->m_Storage);
      g_pDataModel->StartUndo(
        this: g_pDataModel,
        a2: "Set Slider Value To Default",
        a3: "Set Slider Value To Default",
        a4: 0);
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hControl.m_handle);
      p_x = &v4->m_Storage.x;
      v21 = 4;
      ((void (__stdcall *)(CDmElement *))this->m_pParent->StampValueIntoLogs)(a1: v5);
    }
    else
    {
      v6 = (CDmElement *)((int (__stdcall *)(DmElementHandle_t))g_pDataModel->GetElement)(a1: this->m_hControl.m_handle);
      v7 = CDmElement::GetValue<Vector>(this: v6, pAttributeName: "defaultPosition");
      if ( v7->m_Storage.x != this->m_Control.m_Vector.x
        || v7->m_Storage.y != this->m_Control.m_Vector.y
        || v7->m_Storage.z != this->m_Control.m_Vector.z )
      {
        this->m_Control.m_Vector.x = v7->m_Storage.x;
        this->m_Control.m_Vector.y = v7->m_Storage.y;
        this->m_Control.m_Vector.z = v7->m_Storage.z;
      }
      g_pDataModel->StartUndo(
        this: g_pDataModel,
        a2: "Set Slider Value To Default",
        a3: "Set Slider Value To Default",
        a4: 0);
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hControl.m_handle);
      p_x = &v7->m_Storage.x;
      v21 = 3;
      ((void (__stdcall *)(CDmElement *))this->m_pParent->StampValueIntoLogs_2)(a1: v8);
    }
  }
  else
  {
    v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hControl.m_handle);
    if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
    {
      `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
      `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
      `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
    }
    Attribute = CDmElement::FindAttribute(this: v9, pAttributeName: "defaultValue");
    if ( Attribute != nullptr )
      v11 = CDmAttribute::GetValue<float>(this: Attribute);
    else
      v11 = &`CDmElement::GetValue<float>'::`2'::defaultVal;
    v12 = (*((_BYTE *)this + 656) & 4) == 0;
    m_Storage = v11->m_Storage;
    flDefaultValue = v11->m_Storage;
    if ( v12 )
    {
      if ( this->m_Control.m_pValue[0] != m_Storage )
        this->m_Control.m_pValue[0] = m_Storage;
      g_pDataModel->StartUndo(
        this: g_pDataModel,
        a2: "Set Slider Value To Default",
        a3: "Set Slider Value To Default",
        a4: 0);
      m_handle = this->m_hControl.m_handle;
      v24 = flDefaultValue;
      v17 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_handle);
      m_pParent = this->m_pParent;
      p_x = &v24;
      v21 = 0;
    }
    else
    {
      if ( this->m_Control.m_pValue[2] != m_Storage )
        this->m_Control.m_pValue[2] = m_Storage;
      if ( this->m_Control.m_pValue[1] != m_Storage )
        this->m_Control.m_pValue[1] = m_Storage;
      g_pDataModel->StartUndo(
        this: g_pDataModel,
        a2: "Set Slider Value To Default",
        a3: "Set Slider Value To Default",
        a4: 0);
      v14 = this->m_hControl.m_handle;
      v24 = flDefaultValue;
      v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: v14);
      this->m_pParent->StampValueIntoLogs_3(this: this->m_pParent, a2: v15, a3: ANIM_CONTROL_VALUE_LEFT, a4: &v24);
      v16 = this->m_hControl.m_handle;
      v24 = flDefaultValue;
      v17 = g_pDataModel->GetElement(this: g_pDataModel, a2: v16);
      m_pParent = this->m_pParent;
      p_x = &v24;
      v21 = 1;
    }
    ((void (__stdcall *)(CDmElement *))m_pParent->StampValueIntoLogs_3)(a1: v17);
  }
  ((void (__thiscall *)(IDataModel *, int, float *))g_pDataModel->FinishUndo)(a1: g_pDataModel, a2: v21, a3: p_x);
}

//------------------------------------------------------------------------------
// Address: 0x0048C250
// Name: public: virtual void CAttributeSlider::OnSetToDefault(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CAttributeSlider::OnSetToDefault(CAttributeSlider *this)
{
  CAttributeSlider::SetToDefault(this);
}

//------------------------------------------------------------------------------
// Address: 0x0048C260
// Name: public: virtual void CAttributeSlider::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::PaintBackground(CAttributeSlider *this)
{
  int v1; // edi
  char *v2; // esi
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // eax
  void (__thiscall *v4)(vgui::ISurface *, Color); // eax
  int v5; // ebx
  CAttributeSlider *v6; // esi
  int v7; // ebx
  CBaseAnimationSetControl *v8; // eax
  int v9; // edi
  CBaseAnimationSetControl *v10; // eax
  vgui::IInput_vtbl *v11; // edx
  bool v12; // al
  bool v13; // zf
  bool IsPresetFaderBeingDragged; // al
  CDmElement *v15; // eax
  CDmaVar<float> *v16; // eax
  float v17; // xmm1_4
  float m_Storage; // xmm2_4
  float v19; // xmm0_4
  AttributeValue_t *p_m_PreviewCurrent; // eax
  float v21; // xmm2_4
  float v22; // xmm3_4
  Color v23; // edi
  CBaseAnimationSetControl *v24; // edi
  CBaseAnimationSetControl *v25; // edx
  bool v26; // cc
  int v27; // ebx
  Color v28; // edi
  CBaseAnimationSetControl *v29; // edx
  int rect_8a; // [esp+14h] [ebp-1Ch]
  int rect_8; // [esp+14h] [ebp-1Ch]
  int nLeftValuea; // [esp+1Ch] [ebp-14h]
  int nRightValue; // [esp+20h] [ebp-10h] BYREF
  CBaseAnimationSetControl *pController; // [esp+24h] [ebp-Ch] BYREF
  int v36; // [esp+28h] [ebp-8h]
  bool shiftDown; // [esp+2Fh] [ebp-1h]

  vgui::Panel::GetSize(this, wide: &nRightValue, tall: (int *)&pController);
  v1 = nRightValue - 12;
  v36 = -15198184;
  rect_8a = nRightValue - 12;
  v2 = (int)&pController[-1].m_crossfadePresetControlValues.m_Size + 2 < 0
     ? nullptr
     : (char *)((unsigned int)&pController[-1].m_crossfadePresetControlValues.m_Size + 2);
  ((void (__thiscall *)(vgui::ISurface *, int))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: -15198184);
  v1 += 6;
  g_pVGuiSurface->DrawOutlinedRect(this: g_pVGuiSurface, a2: 6, a3: 3, a4: v1, a5: 4);
  g_pVGuiSurface->DrawOutlinedRect(this: g_pVGuiSurface, a2: 6, a3: 3, a4: 7, a5: (int)(v2 + 3));
  DrawSetColor = g_pVGuiSurface->DrawSetColor;
  v36 = -14606047;
  ((void (__thiscall *)(vgui::ISurface *, int))DrawSetColor)(a1: g_pVGuiSurface, a2: -14606047);
  g_pVGuiSurface->DrawOutlinedRect(this: g_pVGuiSurface, a2: v1 - 1, a3: 3, a4: v1, a5: (int)(v2 + 3));
  v4 = g_pVGuiSurface->DrawSetColor;
  v36 = -13092808;
  ((void (__thiscall *)(vgui::ISurface *, int))v4)(a1: g_pVGuiSurface, a2: -13092808);
  g_pVGuiSurface->DrawOutlinedRect(this: g_pVGuiSurface, a2: 6, a3: (int)(v2 + 2), a4: v1, a5: (int)(v2 + 3));
  rect_8 = rect_8a - 2;
  v5 = (int)(v2 - 2) / 2;
  v36 = (int)(v2 + 2);
  v6 = this;
  v7 = v5 + 4;
  v8 = this->m_pParent->GetController(this: this->m_pParent);
  v9 = 4 * (vgui::PHandle::Get(this: &v8->m_ActiveAttributeSlider) == this);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)((char *)s_ZeroColor + v9));
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 7, a3: 4, a4: rect_8 + 7, a5: v36);
  if ( this->m_SliderMode != SLIDER_MODE_TEXT )
  {
    if ( (*((_BYTE *)this + 656) & 1) == 0 )
    {
      v10 = this->m_pParent->GetController(this: this->m_pParent);
      v11 = g_pVGuiInput->__vftable;
      pController = v10;
      if ( v11->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
        || (v12 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT), shiftDown = false, v12) )
      {
        shiftDown = true;
      }
      if ( vgui::PHandle::Get(this: &pController->m_ActiveAttributeSlider) != this
        || this->m_SliderMode == SLIDER_MODE_DRAG_VALUE
        || (v13 = !shiftDown, shiftDown = true, v13) )
      {
        shiftDown = false;
      }
      IsPresetFaderBeingDragged = CBaseAnimationSetControl::IsPresetFaderBeingDragged(this: pController);
      if ( shiftDown
        || IsPresetFaderBeingDragged
        || (v13 = (*((_BYTE *)pController + 104) & 2) == 0, shiftDown = false, !v13) )
      {
        shiftDown = true;
      }
      v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hControl.m_handle);
      v16 = CDmElement::GetValue<float>(this: v15, pAttributeName: "defaultValue");
      v17 = 0.0;
      if ( v16->m_Storage >= 0.0 )
      {
        if ( v16->m_Storage <= 1.0 )
          m_Storage = v16->m_Storage;
        else
          m_Storage = 1.0;
      }
      else
      {
        m_Storage = 0.0;
      }
      v13 = (*((_BYTE *)this + 656) & 4) == 0;
      v19 = (float)rect_8;
      pController = (CBaseAnimationSetControl *)(int)(float)((float)((float)rect_8 * m_Storage) + 0.5);
      p_m_PreviewCurrent = &this->m_PreviewCurrent;
      if ( v13 )
      {
        if ( !shiftDown )
          p_m_PreviewCurrent = &this->m_Control;
        if ( p_m_PreviewCurrent->m_pValue[0] >= 0.0 )
        {
          if ( p_m_PreviewCurrent->m_pValue[0] <= 1.0 )
            v17 = p_m_PreviewCurrent->m_pValue[0];
          else
            v17 = 1.0;
        }
        v27 = (int)(float)((float)(v19 * v17) + 0.5);
        if ( this->m_SliderMode == SLIDER_MODE_DRAG_VALUE )
          v28 = s_DraggingBarColor;
        else
          v28 = *(Color *)((char *)s_BarColor + v9);
        ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: v28);
        v29 = (CBaseAnimationSetControl *)(int)(float)((float)(v19 * v17) + 0.5);
        if ( v27 > (int)pController || (v29 = pController, v27 >= (int)pController) )
          v27 = (int)pController;
        v7 = v27 + 7;
        g_pVGuiSurface->DrawFilledRect(
          this: g_pVGuiSurface,
          a2: v7,
          a3: 4,
          a4: (int)&v29->m_hFilmClip.m_handle + 3,
          a5: v36);
        v24 = pController;
      }
      else
      {
        if ( !shiftDown )
          p_m_PreviewCurrent = &this->m_Control;
        v21 = p_m_PreviewCurrent->m_pValue[2];
        v22 = p_m_PreviewCurrent->m_pValue[1];
        if ( v21 >= 0.0 )
        {
          if ( v21 > 1.0 )
            v21 = 1.0;
        }
        else
        {
          v21 = 0.0;
        }
        nLeftValuea = (int)(float)((float)(v19 * v21) + 0.5);
        if ( v22 >= 0.0 )
        {
          if ( v22 <= 1.0 )
            v17 = p_m_PreviewCurrent->m_pValue[1];
          else
            v17 = 1.0;
        }
        v13 = v6->m_SliderMode == SLIDER_MODE_DRAG_VALUE;
        nRightValue = (int)(float)((float)(v19 * v17) + 0.5);
        if ( v13 )
          v23 = s_DraggingBarColor;
        else
          v23 = *(Color *)((char *)s_BarColor + v9);
        ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: v23);
        v24 = pController;
        v25 = (CBaseAnimationSetControl *)(int)(float)((float)(v19 * v21) + 0.5);
        v26 = nLeftValuea < (int)pController;
        if ( nLeftValuea > (int)pController
          || (v25 = pController, pController = (CBaseAnimationSetControl *)(int)(float)((float)(v19 * v21) + 0.5), !v26) )
        {
          pController = v24;
        }
        g_pVGuiSurface->DrawFilledRect(
          this: g_pVGuiSurface,
          a2: (int)&pController->m_hFilmClip.m_handle + 3,
          a3: 4,
          a4: (int)&v25->m_hFilmClip.m_handle + 3,
          a5: v7);
        pController = (CBaseAnimationSetControl *)nRightValue;
        if ( nRightValue > (int)v24 || (pController = v24, nRightValue >= (int)v24) )
          nRightValue = (int)v24;
        g_pVGuiSurface->DrawFilledRect(
          this: g_pVGuiSurface,
          a2: nRightValue + 7,
          a3: v7,
          a4: (int)&pController->m_hFilmClip.m_handle + 3,
          a5: v36);
      }
      v9 = (int)&v24->m_hFilmClip.m_handle + 3;
      if ( (*((_BYTE *)v6 + 656) & 1) == 0 )
      {
        ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: s_MidpointColor);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: v9, a3: 4, a4: v9 + 1, a5: v36);
      }
    }
    CAttributeSlider::DrawNameLabel(this: v6, a2: v7, a3: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048C670
// Name: public: static void CAttributeSlider::KB_AddToMap(char const __near *,enum ButtonCode_t,int,void (vgui::Panel::*)(void),char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAttributeSlider::KB_AddToMap(
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
  v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSlider");
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
  CDmeFXClip::OnDestruction(this: (vgui::PropertyPage *)v8);
}

//------------------------------------------------------------------------------
// Address: 0x0048C740
// Name: public: static void CAttributeSlider::PanelMessageFunc_OnSetToDefault::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeSlider::PanelMessageFunc_OnSetToDefault::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeSlider::PanelMessageFunc_OnSetToDefault::InitVar'::`2'::bAdded )
  {
    `CAttributeSlider::PanelMessageFunc_OnSetToDefault::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeSlider");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "SetToDefault";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048C7D0
// Name: public: static void CAttributeSlider::PanelMessageFunc_OnEditMinMaxDefault::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeSlider::PanelMessageFunc_OnEditMinMaxDefault::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeSlider::PanelMessageFunc_OnEditMinMaxDefault::InitVar'::`2'::bAdded )
  {
    `CAttributeSlider::PanelMessageFunc_OnEditMinMaxDefault::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeSlider");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "EditMinMaxDefault";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048C860
// Name: public: static void CAttributeSlider::PanelMessageFunc_OnInputCompleted::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeSlider::PanelMessageFunc_OnInputCompleted::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeSlider::PanelMessageFunc_OnInputCompleted::InitVar'::`2'::bAdded )
  {
    `CAttributeSlider::PanelMessageFunc_OnInputCompleted::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeSlider");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "InputCompleted";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048C8F0
// Name: public: static void CAttributeSliderTextEntry::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeSliderTextEntry::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeSliderTextEntry::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `CAttributeSliderTextEntry::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeSliderTextEntry");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "KillFocus";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048C980
// Name: public: CAttributeSlider::CAttributeSlider(class CBaseAnimSetAttributeSliderPanel __near *)
// Source: json
//------------------------------------------------------------------------------
CAttributeSlider *__thiscall CAttributeSlider::CAttributeSlider(
        CAttributeSlider *this,
        CBaseAnimSetAttributeSliderPanel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::TextImage *v6; // eax
  vgui::TextImage *v7; // eax
  vgui::TextImage *v8; // eax
  vgui::TextImage *v9; // eax
  vgui::TextImage *v10; // eax
  vgui::TextImage *v11; // eax
  vgui::TextImage *v12; // eax
  vgui::TextImage *v13; // eax
  vgui::TextImage *v14; // eax
  vgui::TextImage *v15; // eax
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent, panelName: defaultValue);
  this->__vftable = (CAttributeSlider_vtbl *)&CAttributeSlider::`vftable';
  if ( `CAttributeSlider::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSlider::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CAttributeSlider");
    v3->pfnClassName = CAttributeSlider::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `CAttributeSlider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeSlider::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CAttributeSlider");
    v4->pfnClassName = CAttributeSlider::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `CAttributeSlider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSlider::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSlider");
    v5->pfnClassName = CAttributeSlider::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  CAttributeSlider::PanelMessageFunc_OnSetToDefault::InitVar(a1: (int)&savedregs);
  CAttributeSlider::PanelMessageFunc_OnEditMinMaxDefault::InitVar(a1: (int)&savedregs);
  CAttributeSlider::PanelMessageFunc_OnInputCompleted::InitVar(a1: (int)&savedregs);
  if ( `CAttributeSlider::PanelKBMapFunc_ts_curve_1::InitVar'::`2'::bAdded == 0 )
  {
    `CAttributeSlider::PanelKBMapFunc_ts_curve_1::InitVar'::`2'::bAdded = 1;
    CAttributeSlider::KB_AddToMap(
      a1: (const char *)&savedregs,
      bindingname: "ts_curve_1",
      defaultcode: KEY_1,
      default_modifiers: 0,
      function: (unsigned int) __thiscall CColorPickerPanel::`vcall'{956,{flat}},
      helpstring: (unsigned int)"#ts_curve1_help",
      passive: false);
  }
  if ( `CAttributeSlider::PanelKBMapFunc_ts_curve_2::InitVar'::`2'::bAdded == 0 )
  {
    `CAttributeSlider::PanelKBMapFunc_ts_curve_2::InitVar'::`2'::bAdded = 1;
    CAttributeSlider::KB_AddToMap(
      a1: (const char *)&savedregs,
      bindingname: "ts_curve_2",
      defaultcode: KEY_2,
      default_modifiers: 0,
      function: (unsigned int) __thiscall CDmePanel::`vcall'{960,{flat}},
      helpstring: (unsigned int)"#ts_curve2_help",
      passive: false);
  }
  if ( `CAttributeSlider::PanelKBMapFunc_ts_curve_3::InitVar'::`2'::bAdded == 0 )
  {
    `CAttributeSlider::PanelKBMapFunc_ts_curve_3::InitVar'::`2'::bAdded = 1;
    CAttributeSlider::KB_AddToMap(
      a1: (const char *)&savedregs,
      bindingname: "ts_curve_3",
      defaultcode: KEY_3,
      default_modifiers: 0,
      function: (unsigned int) __thiscall CAttributeSlider::`vcall'{964,{flat}},
      helpstring: (unsigned int)"#ts_curve3_help",
      passive: false);
  }
  if ( `CAttributeSlider::PanelKBMapFunc_ts_curve_4::InitVar'::`2'::bAdded == 0 )
  {
    `CAttributeSlider::PanelKBMapFunc_ts_curve_4::InitVar'::`2'::bAdded = 1;
    CAttributeSlider::KB_AddToMap(
      a1: (const char *)&savedregs,
      bindingname: "ts_curve_4",
      defaultcode: KEY_4,
      default_modifiers: 0,
      function: (unsigned int) __thiscall CAttributeSlider::`vcall'{968,{flat}},
      helpstring: (unsigned int)"#ts_curve4_help",
      passive: false);
  }
  this->m_pParent = parent;
  this->m_hControl.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_Control.m_pValue[0] = 0.0;
  this->m_Control.m_pValue[1] = 0.0;
  this->m_Control.m_pValue[2] = 0.0;
  this->m_Control.m_Vector.x = 0.0;
  this->m_Control.m_Vector.y = 0.0;
  this->m_Control.m_Vector.z = 0.0;
  this->m_Control.m_Quaternion = quat_identity;
  this->m_InitialTextEntryValue.m_pValue[0] = 0.0;
  this->m_InitialTextEntryValue.m_pValue[1] = 0.0;
  this->m_InitialTextEntryValue.m_pValue[2] = 0.0;
  this->m_InitialTextEntryValue.m_Vector.x = 0.0;
  this->m_InitialTextEntryValue.m_Vector.y = 0.0;
  this->m_InitialTextEntryValue.m_Vector.z = 0.0;
  this->m_InitialTextEntryValue.m_Quaternion = quat_identity;
  this->m_pTextField = nullptr;
  this->m_pRightTextField = nullptr;
  this->m_PreviewCurrent.m_pValue[0] = 0.0;
  this->m_PreviewCurrent.m_pValue[1] = 0.0;
  this->m_PreviewCurrent.m_pValue[2] = 0.0;
  this->m_PreviewCurrent.m_Vector.x = 0.0;
  this->m_PreviewCurrent.m_Vector.y = 0.0;
  this->m_PreviewCurrent.m_Vector.z = 0.0;
  this->m_PreviewCurrent.m_Quaternion = quat_identity;
  this->m_PreviewFull.m_pValue[0] = 0.0;
  this->m_PreviewFull.m_pValue[1] = 0.0;
  this->m_PreviewFull.m_pValue[2] = 0.0;
  this->m_PreviewFull.m_Vector.x = 0.0;
  this->m_PreviewFull.m_Vector.y = 0.0;
  this->m_PreviewFull.m_Vector.z = 0.0;
  this->m_PreviewFull.m_Quaternion = quat_identity;
  this->m_flFaderAmount = 1.0;
  this->m_dragStartValues.m_pValue[0] = 0.0;
  this->m_dragStartValues.m_pValue[1] = 0.0;
  this->m_dragStartValues.m_pValue[2] = 0.0;
  this->m_dragStartValues.m_Vector.x = 0.0;
  this->m_dragStartValues.m_Vector.y = 0.0;
  this->m_dragStartValues.m_Vector.z = 0.0;
  this->m_dragStartValues.m_Quaternion = quat_identity;
  *((_BYTE *)this + 656) &= ~8u;
  this->m_nVisibleComponents = LOG_COMPONENTS_ALL;
  this->m_Dependenices.m_Memory.m_pMemory = nullptr;
  this->m_Dependenices.m_Memory.m_nAllocationCount = 0;
  this->m_Dependenices.m_Memory.m_nGrowSize = 0;
  this->m_Dependenices.m_Size = 0;
  this->m_Dependenices.m_pElements = nullptr;
  this->m_hContextMenu.m_iPanelID = -1;
  vgui::Panel::SetPaintBackgroundEnabled(this, state: true);
  vgui::Panel::SetPaintBorderEnabled(this, state: false);
  CDmeTrackGroup::SetMaxTrackCount(this, color: (Color)-14013910);
  v6 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x80u);
  if ( v6 != nullptr )
    v7 = vgui::TextImage::TextImage(this: v6, text: defaultValue);
  else
    v7 = nullptr;
  this->m_pName = v7;
  v8 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x80u);
  if ( v8 != nullptr )
    v9 = vgui::TextImage::TextImage(this: v8, text: defaultValue);
  else
    v9 = nullptr;
  this->m_pValues[0] = v9;
  v10 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x80u);
  if ( v10 != nullptr )
    v11 = vgui::TextImage::TextImage(this: v10, text: defaultValue);
  else
    v11 = nullptr;
  this->m_pValues[1] = v11;
  v12 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x80u);
  if ( v12 != nullptr )
    v13 = vgui::TextImage::TextImage(this: v12, text: defaultValue);
  else
    v13 = nullptr;
  this->m_pValues[2] = v13;
  v14 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x80u);
  if ( v14 != nullptr )
    v15 = vgui::TextImage::TextImage(this: v14, text: defaultValue);
  else
    v15 = nullptr;
  this->m_pValues[3] = v15;
  vgui::Panel::SetSize(this, wide: 100, tall: 20);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0048CEA0
// Name: public: void CAttributeSlider::Init(class CDmElement __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::Init(CAttributeSlider *this, CDmElement *control, bool bOrientation)
{
  const char *m_pAsString; // eax
  DmElementHandle_t BufferType; // eax
  bool HasAttribute; // al
  char v7; // al
  const char *v8; // ecx
  const char *v9; // eax
  const char *v10; // edi
  char *m_szBuf; // [esp-4h] [ebp-11Ch]
  CFmtStrN<256> v12; // [esp+Ch] [ebp-10Ch] BYREF

  m_pAsString = control->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  vgui::Panel::SetName(this, panelName: m_pAsString);
  this->m_SliderMode = SLIDER_MODE_NONE;
  BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)control);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hControl, h: BufferType);
  *((_BYTE *)this + 656) &= 0xFCu;
  if ( ((int (__thiscall *)(_DWORD, _DWORD))control->IsA)(
         a1: control,
         a2: (CUtlSymbolLarge)CDmeTransformControl::m_classType.u.m_Id) )
  {
    *((_BYTE *)this + 656) = *((_BYTE *)this + 656) ^ (*((_BYTE *)this + 656) ^ (2 * bOrientation)) & 2 | 1;
  }
  HasAttribute = CDmElement::HasAttribute(this: control, pAttributeName: "rightValue", type: AT_UNKNOWN);
  this->m_nDragStartPosition[1] = 0;
  this->m_nDragStartPosition[0] = 0;
  this->m_nAccum[1] = 0;
  this->m_nAccum[0] = 0;
  *((_BYTE *)this + 656) ^= (*((_BYTE *)this + 656) ^ (4 * HasAttribute)) & 4;
  this->m_dragStartValues.m_pValue[0] = this->m_Control.m_pValue[0];
  this->m_dragStartValues.m_pValue[1] = this->m_Control.m_pValue[1];
  this->m_dragStartValues.m_pValue[2] = this->m_Control.m_pValue[2];
  this->m_dragStartValues.m_Vector.x = this->m_Control.m_Vector.x;
  this->m_dragStartValues.m_Vector.y = this->m_Control.m_Vector.y;
  this->m_dragStartValues.m_Vector.z = this->m_Control.m_Vector.z;
  *(_QWORD *)&this->m_dragStartValues.m_Quaternion.x = *(_QWORD *)&this->m_Control.m_Quaternion.x;
  *(_QWORD *)&this->m_dragStartValues.m_Quaternion.z = *(_QWORD *)&this->m_Control.m_Quaternion.z;
  this->SetPaintBackgroundEnabled(this, a2: true);
  v7 = *((_BYTE *)this + 656);
  if ( (v7 & 1) != 0 )
  {
    v8 = "%s - rot";
    if ( (v7 & 2) == 0 )
      v8 = "%s - pos";
    v9 = control->m_Name.m_Storage.u.m_pAsString;
    if ( v9 == (const char *)-1 )
      v9 = defaultValue;
    m_szBuf = CFmtStrN<256>::CFmtStrN<256>(this: &v12, pszFormat: v8, v9)->m_szBuf;
    this->m_pName->SetText_2(this: this->m_pName, a2: m_szBuf);
  }
  else
  {
    v10 = control->m_Name.m_Storage.u.m_pAsString;
    if ( v10 == (const char *)-1 )
      v10 = defaultValue;
    this->m_pName->SetText_2(this: this->m_pName, a2: v10);
  }
  vgui::TextImage::ResizeImageToContent(this: this->m_pName);
  CAttributeSlider::InitControls(this);
}

//------------------------------------------------------------------------------
// Address: 0x0048D040
// Name: public: virtual void CAttributeSlider::OnEditMinMaxDefault(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnEditMinMaxDefault(CAttributeSlider *this)
{
  CDmElement *v2; // eax
  CDmeChannel *Value; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmElement *v6; // eax
  vgui::MultiInputDialog *v7; // eax
  vgui::MultiInputDialog *v8; // esi
  float flDefault; // [esp+18h] [ebp-Ch]
  float flMax; // [esp+1Ch] [ebp-8h]
  float flMin; // [esp+20h] [ebp-4h]

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hControl.m_handle);
  Value = CDmElement::GetValueElement<CDmeChannel>(this: v2, pAttributeName: "channel");
  if ( Value != nullptr )
  {
    v4 = CDmeChannel::GetToElement(this: Value);
    v5 = v4;
    if ( v4 != nullptr
      && v4->IsA(this: v4, a2: CDmeExpressionOperator::m_classType)
      && v5 != (CDmElement *)4
      && (*((_BYTE *)this + 656) & 4) == 0 )
    {
      flMin = CDmElement::GetValue<float>(this: v5, pAttributeName: "lo")->m_Storage;
      flMax = CDmElement::GetValue<float>(this: v5, pAttributeName: "hi")->m_Storage;
      v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hControl.m_handle);
      flDefault = (float)((float)(flMax - flMin)
                        * CDmElement::GetValue<float>(this: v6, pAttributeName: "defaultValue")->m_Storage)
                + flMin;
      v7 = (vgui::MultiInputDialog *)MemAlloc_Alloc(nSize: 0x264u);
      if ( v7 != nullptr )
        v8 = vgui::MultiInputDialog::MultiInputDialog(
               this: v7,
               pParent: this,
               pTitle: "Edit Min/Max/Default",
               pOKText: "#VGui_OK",
               pCancelText: "#VGui_Cancel");
      else
        v8 = nullptr;
      vgui::MultiInputDialog::AddEntry(this: v8, pName: "min", pPrompt: "Min:", flDefaultValue: flMin);
      vgui::MultiInputDialog::AddEntry(this: v8, pName: "max", pPrompt: "Max:", flDefaultValue: flMax);
      vgui::MultiInputDialog::AddEntry(this: v8, pName: "default", pPrompt: "Default:", flDefaultValue: flDefault);
      v8->DoModal(this: v8);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048D1B0
// Name: public: virtual void CAttributeSlider::OnInputCompleted(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnInputCompleted(CAttributeSlider *this, float params)
{
  CDmElement *v3; // eax
  CDmeChannel *Value; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  char *v7; // esi
  CBaseAnimationSetControl *v8; // eax
  CDmElement *v9; // esi
  CDmaVar<float> *v10; // eax
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // edx
  CDmElement *v12; // eax
  CDmaVar<float> *v13; // eax
  KeyValues *v14; // edi
  float v15; // xmm2_4
  void (__thiscall *StartUndo)(IDataModel *, const char *, const char *, int); // edx
  CDmAttribute *Attribute; // eax
  CDmAttribute *v18; // eax
  CDmElement *v19; // esi
  CDmAttribute *v20; // eax
  CDmElement *v21; // esi
  CDmAttribute *v22; // eax
  DmElementHandle_t defaultValue; // [esp+24h] [ebp-28h]
  CDmeChannel *pChannel; // [esp+34h] [ebp-18h]
  float flOldMin; // [esp+3Ch] [ebp-10h]
  float flMin; // [esp+40h] [ebp-Ch] BYREF
  float flMax; // [esp+44h] [ebp-8h] BYREF
  float flOldMax; // [esp+48h] [ebp-4h]

  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hControl.m_handle);
  Value = CDmElement::GetValueElement<CDmeChannel>(this: v3, pAttributeName: "channel");
  pChannel = Value;
  if ( Value != nullptr )
  {
    v5 = CDmeChannel::GetToElement(this: Value);
    v6 = v5;
    if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeExpressionOperator::m_classType) )
    {
      v7 = (char *)&v6[-1] + 64;
      if ( v7 != nullptr )
      {
        v8 = this->m_pParent->GetController(this: this->m_pParent);
        v8->OnSliderRangeRemapped(this: v8);
        v9 = (CDmElement *)(v7 + 4);
        flOldMin = CDmElement::GetValue<float>(this: v9, pAttributeName: "lo")->m_Storage;
        v10 = CDmElement::GetValue<float>(this: v9, pAttributeName: "hi");
        GetElement = g_pDataModel->GetElement;
        defaultValue = this->m_hControl.m_handle;
        flOldMax = v10->m_Storage;
        v12 = GetElement(this: g_pDataModel, a2: defaultValue);
        v13 = CDmElement::GetValue<float>(this: v12, pAttributeName: "value");
        v14 = (KeyValues *)LODWORD(params);
        v15 = flOldMax - flOldMin;
        flOldMax = (float)(v13->m_Storage * (float)(flOldMax - flOldMin)) + flOldMin;
        flMin = KeyValues::GetFloat(this: (KeyValues *)LODWORD(params), keyName: "min", defaultValue: 0.0);
        flMax = KeyValues::GetFloat(this: v14, keyName: "max", defaultValue: 0.0);
        params = KeyValues::GetFloat(this: v14, keyName: "default", defaultValue: 0.0);
        StartUndo = g_pDataModel->StartUndo;
        params = (float)(params - flMin) / (float)(flMax - flMin);
        flOldMax = (float)(flOldMax - flMin) / (float)(flMax - flMin);
        StartUndo(this: g_pDataModel, a2: "Set Control Min/Max/Default", a3: "Set Control Min/Max/Default", a4: 0);
        Attribute = CDmElement::FindAttribute(this: v9, pAttributeName: "lo");
        if ( Attribute != nullptr
          || (Attribute = CDmElement::CreateAttribute(this: v9, pAttributeName: "lo", type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: Attribute, value: &flMin);
        }
        v18 = CDmElement::FindAttribute(this: v9, pAttributeName: "hi");
        if ( v18 != nullptr
          || (v18 = CDmElement::CreateAttribute(this: v9, pAttributeName: "hi", type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v18, value: &flMax);
        }
        if ( params >= 0.0 )
        {
          if ( params > 1.0 )
            params = 1.0;
        }
        else
        {
          params = 0.0;
        }
        v19 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hControl.m_handle);
        v20 = CDmElement::FindAttribute(this: v19, pAttributeName: "defaultValue");
        if ( v20 != nullptr
          || (v20 = CDmElement::CreateAttribute(this: v19, pAttributeName: "defaultValue", type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v20, value: &params);
        }
        if ( flOldMax >= 0.0 )
        {
          if ( flOldMax <= 1.0 )
            params = flOldMax;
          else
            params = 1.0;
        }
        else
        {
          params = 0.0;
        }
        v21 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hControl.m_handle);
        v22 = CDmElement::FindAttribute(this: v21, pAttributeName: "value");
        if ( v22 != nullptr
          || (v22 = CDmElement::CreateAttribute(this: v21, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v22, value: &params);
        }
        RemapFloatLogValues(
          pChannel,
          flBias: (float)(flOldMin - flMin) / (float)(flMax - flMin),
          flScale: v15 / (float)(flMax - flMin));
        g_pDataModel->FinishUndo(this: g_pDataModel);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048D4D0
// Name: public: virtual void CAttributeSlider::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAttributeSlider::OnMouseReleased(CAttributeSlider *this@<ecx>, int a2@<ebx>, int a3@<edi>, int code)
{
  vgui::Panel *v5; // eax
  vgui::Menu *v6; // eax
  vgui::Menu *v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // ebx
  vgui::Panel *v10; // eax
  CDmElement *v11; // eax
  CDmeChannel *Value; // eax
  CDmElement *v13; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // ebx
  vgui::Panel *v16; // eax
  vgui::Menu *v17; // eax
  int x; // [esp+4h] [ebp-4h] BYREF

  if ( this->IsEnabled(this) && (*((_BYTE *)this + 656) & 1) == 0 )
  {
    if ( code == 108 )
    {
      if ( vgui::PHandle::Get(this: &this->m_hContextMenu) != nullptr )
      {
        v5 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        if ( v5 != nullptr )
          ((void (__thiscall *)(vgui::Panel *, int))v5->dtr_Panel)(a1: v5, a2: 1);
        vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: nullptr);
      }
      v6 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
      if ( v6 != nullptr )
        v7 = vgui::Menu::Menu(this: v6, parent: this, panelName: "ActionMenu");
      else
        v7 = nullptr;
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: v7);
      ((void (__thiscall *)(vgui::IInput *, int *, int *, int, int))g_pVGuiInput->GetCursorPosition)(
        a1: g_pVGuiInput,
        a2: &x,
        a3: &code,
        a4: a3,
        a5: a2);
      vgui::Panel::ScreenToLocal(this, &x, y: &code);
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "SetToDefault");
      else
        v9 = nullptr;
      v10 = vgui::PHandle::Get(this: &this->m_hContextMenu);
      v10->__vftable[1].PaintTraverse(this: v10, a2: (bool)"Set To Default", a3: (bool)v9);
      v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hControl.m_handle);
      Value = CDmElement::GetValueElement<CDmeChannel>(this: v11, pAttributeName: "channel");
      if ( Value != nullptr )
      {
        v13 = CDmeChannel::GetToElement(this: Value);
        if ( v13 != nullptr && CDmElement::IsA<CDmeExpressionOperator>(this: v13) )
        {
          v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v14 != nullptr )
            v15 = KeyValues::KeyValues(this: v14, setName: "EditMinMaxDefault");
          else
            v15 = nullptr;
          v16 = vgui::PHandle::Get(this: &this->m_hContextMenu);
          ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CAttributeSlider *, _DWORD))v16->__vftable[1].PaintTraverse)(
            a1: v16,
            a2: "Edit Min/Max/Default...",
            a3: v15,
            a4: this,
            a5: 0);
        }
      }
      v17 = (vgui::Menu *)vgui::PHandle::Get(this: &this->m_hContextMenu);
      vgui::Menu::PlaceContextMenu(parent: this, menu: v17);
    }
    else if ( this->m_SliderMode == SLIDER_MODE_DRAG_VALUE )
    {
      this->m_SliderMode = SLIDER_MODE_NONE;
      g_pVGuiInput->SetMouseCapture(this: g_pVGuiInput, a2: 0);
      this->SetCursor(this, a2: 2u);
      this->m_pParent->UpdatePreview(this: this->m_pParent, a2: "Attribute Slider Released");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0048D6C0
// Name: public: CAttributeSliderTextEntry::CAttributeSliderTextEntry(class CAttributeSlider __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAttributeSliderTextEntry *__thiscall CAttributeSliderTextEntry::CAttributeSliderTextEntry(
        CAttributeSliderTextEntry *this,
        CAttributeSlider *slider,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::TextEntry::TextEntry(this, parent: slider, panelName);
  this->__vftable = (CAttributeSliderTextEntry_vtbl *)&CAttributeSliderTextEntry::`vftable';
  if ( `CAttributeSliderTextEntry::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSliderTextEntry::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeSliderTextEntry");
    v4->pfnClassName = CAttributeSliderTextEntry::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  }
  if ( `CAttributeSliderTextEntry::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeSliderTextEntry::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeSliderTextEntry");
    v5->pfnClassName = CAttributeSliderTextEntry::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "TextEntry");
  }
  if ( `CAttributeSliderTextEntry::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSliderTextEntry::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSliderTextEntry");
    v6->pfnClassName = CAttributeSliderTextEntry::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  }
  CAttributeSliderTextEntry::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  this->m_pSlider = slider;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0048D790
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeSliderTextEntry::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeSliderTextEntry::GetMessageMap(CAttributeSliderTextEntry *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeSliderTextEntry::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSliderTextEntry::GetMessageMap'::`2'::s_pMap;
  `CAttributeSliderTextEntry::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeSliderTextEntry");
  `CAttributeSliderTextEntry::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048D7C0
// Name: public: virtual struct PanelAnimationMap __near * CAttributeSliderTextEntry::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeSliderTextEntry::GetAnimMap(CAttributeSliderTextEntry *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeSliderTextEntry");
}

//------------------------------------------------------------------------------
// Address: 0x0048D7D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeSliderTextEntry::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeSliderTextEntry::GetKBMap(CAttributeSliderTextEntry *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeSliderTextEntry::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSliderTextEntry::GetKBMap'::`2'::s_pMap;
  `CAttributeSliderTextEntry::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSliderTextEntry");
  `CAttributeSliderTextEntry::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0048D800
// Name: private: void CAttributeSlider::SetupTextFieldForTextEntryMode(class CAttributeSliderTextEntry __near * __near &,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::SetupTextFieldForTextEntryMode(
        CAttributeSlider *this,
        vgui::Panel **pTextField,
        const char *pText,
        bool bRequestFocus)
{
  CAttributeSliderTextEntry *v5; // ebx
  const char *v6; // eax
  CAttributeSliderTextEntry *v7; // eax

  if ( *pTextField == nullptr )
  {
    v5 = (CAttributeSliderTextEntry *)MemAlloc_Alloc(nSize: 0x444u);
    if ( v5 != nullptr )
    {
      v6 = this->GetName(this);
      v7 = CAttributeSliderTextEntry::CAttributeSliderTextEntry(this: v5, slider: this, panelName: v6);
    }
    else
    {
      v7 = nullptr;
    }
    *pTextField = v7;
    v7->SetVisible(this: v7, a2: false);
    (*pTextField)->SetEnabled(this: *pTextField, a2: false);
    vgui::TextEntry::SelectAllOnFocusAlways(this: (vgui::TextEntry *)*pTextField, status: true);
    this->InvalidateLayout(this, a2: false, a3: false);
  }
  (*pTextField)->SetVisible(this: *pTextField, a2: true);
  (*pTextField)->SetEnabled(this: *pTextField, a2: true);
  ((void (__thiscall *)(vgui::Panel *, const char *))(*pTextField)->__vftable[1].GetVPanel)(a1: *pTextField, a2: pText);
  ((void (__thiscall *)(vgui::Panel *))(*pTextField)->__vftable[1].OnMessage)(a1: *pTextField);
  if ( bRequestFocus )
    (*pTextField)->RequestFocus(this: *pTextField, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0048D8C0
// Name: private: void CAttributeSlider::EnterTextEntryMode(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::EnterTextEntryMode(CAttributeSlider *this, bool bRelatchValues)
{
  char v3; // al
  char *v4; // edx
  char pDest[64]; // [esp+1Ch] [ebp-80h] BYREF
  char val[64]; // [esp+5Ch] [ebp-40h] BYREF

  this->m_SliderMode = SLIDER_MODE_TEXT;
  if ( !bRelatchValues )
    CAttributeSlider::SetValue(this, value: &this->m_InitialTextEntryValue);
  v3 = *((_BYTE *)this + 656);
  if ( (v3 & 1) != 0 )
  {
    V_snprintf(
      pDest,
      maxLen: 128,
      pFormat: "%f %f %f",
      this->m_InitialTextEntryValue.m_Vector.x,
      this->m_InitialTextEntryValue.m_Vector.y,
      this->m_InitialTextEntryValue.m_Vector.z);
    v4 = pDest;
  }
  else
  {
    if ( (v3 & 4) != 0 )
    {
      V_snprintf(pDest: val, maxLen: 64, pFormat: "%f", this->m_InitialTextEntryValue.m_pValue[2]);
      CAttributeSlider::SetupTextFieldForTextEntryMode(
        this,
        pTextField: &this->m_pTextField,
        pText: val,
        bRequestFocus: true);
      V_snprintf(pDest: val, maxLen: 64, pFormat: "%f", this->m_InitialTextEntryValue.m_pValue[1]);
      CAttributeSlider::SetupTextFieldForTextEntryMode(
        this,
        pTextField: &this->m_pRightTextField,
        pText: val,
        bRequestFocus: false);
      return;
    }
    V_snprintf(pDest: val, maxLen: 64, pFormat: "%f", this->m_InitialTextEntryValue.m_pValue[0]);
    v4 = val;
  }
  CAttributeSlider::SetupTextFieldForTextEntryMode(
    this,
    pTextField: &this->m_pTextField,
    pText: v4,
    bRequestFocus: true);
}

//------------------------------------------------------------------------------
// Address: 0x0048DA00
// Name: public: virtual void CAttributeSlider::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnMouseDoublePressed(CAttributeSlider *this, ButtonCode_t code)
{
  int x; // [esp+4h] [ebp-8h] BYREF
  int y; // [esp+8h] [ebp-4h] BYREF

  if ( this->IsEnabled(this) && this->m_SliderMode != SLIDER_MODE_DRAG_VALUE && code == KEY_COUNT )
  {
    g_pVGuiInput->GetCursorPosition(this: g_pVGuiInput, a2: &x, a3: &y);
    vgui::Panel::ScreenToLocal(this, &x, &y);
    CAttributeSlider::EnterTextEntryMode(this, bRelatchValues: false);
  }
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104964F0
// Name: public: static char const __near * CAttributeSlider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeSlider::GetPanelClassName()
{
  return "CAttributeSlider";
}

//------------------------------------------------------------------------------
// Address: 0x10496500
// Name: void ValueBalanceToLeftRight(float __near *,float __near *,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ValueBalanceToLeftRight(float *pLeft, float *pRight, float flValue, float flBalance, float flDefaultValue)
{
  float v5; // xmm1_4
  float v6; // xmm0_4

  v5 = flValue;
  if ( flBalance > 0.5 )
    v6 = (float)((float)((float)(1.0 - flBalance) * 2.0) * (float)(flValue - flDefaultValue)) + flDefaultValue;
  else
    v6 = flValue;
  *pLeft = v6;
  if ( flBalance < 0.5 )
    v5 = (float)((float)(flValue - flDefaultValue) * (float)(flBalance * 2.0)) + flDefaultValue;
  *pRight = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10496580
// Name: public: static char const __near * CAttributeSliderTextEntry::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeSliderTextEntry::GetPanelClassName()
{
  return "CAttributeSliderTextEntry";
}

//------------------------------------------------------------------------------
// Address: 0x10496590
// Name: public: void CAttributeSlider::SetValue(enum AnimationControlType_t,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::SetValue(CAttributeSlider *this, AnimationControlType_t type, float flValue)
{
  if ( this->m_Control.m_pValue[type] != flValue )
    this->m_Control.m_pValue[type] = flValue;
}

//------------------------------------------------------------------------------
// Address: 0x104965C0
// Name: public: void CAttributeSlider::SetValue(enum AnimationControlType_t,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::SetValue(CAttributeSlider *this, AnimationControlType_t type, const Vector *vec)
{
  if ( vec->x != this->m_Control.m_Vector.x
    || vec->y != this->m_Control.m_Vector.y
    || vec->z != this->m_Control.m_Vector.z )
  {
    this->m_Control.m_Vector = *vec;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10496620
// Name: public: void CAttributeSlider::SetValue(enum AnimationControlType_t,class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::SetValue(CAttributeSlider *this, AnimationControlType_t type, const Quaternion *quat)
{
  if ( this->m_Control.m_Quaternion.x != quat->x
    || this->m_Control.m_Quaternion.y != quat->y
    || this->m_Control.m_Quaternion.z != quat->z
    || this->m_Control.m_Quaternion.w != quat->w )
  {
    this->m_Control.m_Quaternion = *quat;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10496690
// Name: public: struct AttributeValue_t const __near & CAttributeSlider::GetValue(void)const
// Source: json
//------------------------------------------------------------------------------
const AttributeValue_t *__thiscall CAttributeSlider::GetValue(CAttributeSlider *this)
{
  return &this->m_Control;
}

//------------------------------------------------------------------------------
// Address: 0x104966A0
// Name: public: float CAttributeSlider::GetValue(enum AnimationControlType_t)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAttributeSlider::GetValue(CAttributeSlider *this, AnimationControlType_t type)
{
  return this->m_Control.m_pValue[type];
}

//------------------------------------------------------------------------------
// Address: 0x104966C0
// Name: public: void CAttributeSlider::GetValue(enum AnimationControlType_t,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::GetValue(CAttributeSlider *this, AnimationControlType_t type, Vector *out)
{
  *out = this->m_Control.m_Vector;
}

//------------------------------------------------------------------------------
// Address: 0x104966F0
// Name: public: void CAttributeSlider::GetValue(enum AnimationControlType_t,class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::GetValue(CAttributeSlider *this, AnimationControlType_t type, Quaternion *out)
{
  *out = this->m_Control.m_Quaternion;
}

//------------------------------------------------------------------------------
// Address: 0x10496720
// Name: public: float CAttributeSlider::GetPreview(enum AnimationControlType_t)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAttributeSlider::GetPreview(CAttributeSlider *this, AnimationControlType_t type)
{
  return this->m_PreviewCurrent.m_pValue[type];
}

//------------------------------------------------------------------------------
// Address: 0x10496740
// Name: public: void CAttributeSlider::GetPreview(enum AnimationControlType_t,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::GetPreview(CAttributeSlider *this, AnimationControlType_t type, Vector *out)
{
  *out = this->m_PreviewCurrent.m_Vector;
}

//------------------------------------------------------------------------------
// Address: 0x10496770
// Name: public: void CAttributeSlider::GetPreview(enum AnimationControlType_t,class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::GetPreview(CAttributeSlider *this, AnimationControlType_t type, Quaternion *out)
{
  *out = this->m_PreviewCurrent.m_Quaternion;
}

//------------------------------------------------------------------------------
// Address: 0x104967A0
// Name: public: void CAttributeSlider::SetVisibleComponents(enum LogComponents_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::SetVisibleComponents(CAttributeSlider *this, LogComponents_t componentFlags)
{
  this->m_nVisibleComponents = componentFlags;
}

//------------------------------------------------------------------------------
// Address: 0x104967B0
// Name: public: enum LogComponents_t CAttributeSlider::VisibleComponents(void)const
// Source: json
//------------------------------------------------------------------------------
LogComponents_t __thiscall CAttributeSlider::VisibleComponents(CAttributeSlider *this)
{
  return this->m_nVisibleComponents;
}

//------------------------------------------------------------------------------
// Address: 0x104967C0
// Name: public: virtual void CAttributeSlider::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnCursorEntered(CAttributeSlider *this)
{
  CBaseAnimationSetControl *v2; // eax

  if ( this->m_SliderMode != SLIDER_MODE_DRAG_VALUE )
  {
    CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
    v2 = this->m_pParent->GetController(this: this->m_pParent);
    CBaseAnimationSetControl::SetActiveAttributeSlider(this: v2, pSlider: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104967F0
// Name: public: virtual void CAttributeSlider::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnCursorExited(CAttributeSlider *this)
{
  CBaseAnimationSetControl *v2; // eax

  if ( this->m_SliderMode != SLIDER_MODE_DRAG_VALUE )
  {
    CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
    v2 = this->m_pParent->GetController(this: this->m_pParent);
    CBaseAnimationSetControl::SetActiveAttributeSlider(this: v2, pSlider: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10496820
// Name: private: void CAttributeSlider::DiscardTextEntryValue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::DiscardTextEntryValue(CAttributeSlider *this)
{
  void (__thiscall *RequestFocus)(vgui::IClientPanel *, int); // edx

  if ( this->m_SliderMode == SLIDER_MODE_TEXT )
  {
    this->m_pTextField->SetVisible(this: this->m_pTextField, a2: false);
    this->m_pTextField->SetEnabled(this: this->m_pTextField, a2: false);
    if ( (*((_BYTE *)this + 656) & 4) != 0 )
    {
      this->m_pRightTextField->SetVisible(this: this->m_pRightTextField, a2: false);
      this->m_pRightTextField->SetEnabled(this: this->m_pRightTextField, a2: false);
    }
    RequestFocus = this->RequestFocus;
    this->m_SliderMode = SLIDER_MODE_NONE;
    RequestFocus(this, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104968A0
// Name: public: void CAttributeSlider::SetPreview(struct AttributeValue_t const __near &,struct AttributeValue_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::SetPreview(
        CAttributeSlider *this,
        const AttributeValue_t *value,
        const AttributeValue_t *full)
{
  this->m_PreviewCurrent = *value;
  this->m_PreviewFull = *full;
}

//------------------------------------------------------------------------------
// Address: 0x10496950
// Name: public: struct AttributeValue_t const __near & CAttributeSlider::GetPreview(void)const
// Source: json
//------------------------------------------------------------------------------
const AttributeValue_t *__thiscall CAttributeSlider::GetPreview(CAttributeSlider *this)
{
  return &this->m_PreviewCurrent;
}

//------------------------------------------------------------------------------
// Address: 0x10496960
// Name: private: void CAttributeSlider::GetControlRect(struct Rect_t __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::GetControlRect(CAttributeSlider *this, Rect_t *pRect)
{
  int v2; // ecx
  BOOL v3; // edx
  int sh; // [esp+0h] [ebp-8h] BYREF
  int sw; // [esp+4h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &sw, tall: &sh);
  pRect->width = sw - 12;
  v2 = sh - 6;
  v3 = sh - 6 < 0;
  pRect->x = 6;
  pRect->y = 3;
  pRect->height = v3 ? 0 : v2;
}

//------------------------------------------------------------------------------
// Address: 0x104969B0
// Name: protected: virtual void CAttributeSlider::OnCurve1(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnCurve1(CAttributeSlider *this)
{
  this->m_pParent->DispatchCurve(this: this->m_pParent, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x104969D0
// Name: protected: virtual void CAttributeSlider::OnCurve2(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnCurve2(CAttributeSlider *this)
{
  this->m_pParent->DispatchCurve(this: this->m_pParent, a2: 2);
}

//------------------------------------------------------------------------------
// Address: 0x104969F0
// Name: protected: virtual void CAttributeSlider::OnCurve3(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnCurve3(CAttributeSlider *this)
{
  this->m_pParent->DispatchCurve(this: this->m_pParent, a2: 3);
}

//------------------------------------------------------------------------------
// Address: 0x10496A10
// Name: protected: virtual void CAttributeSlider::OnCurve4(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnCurve4(CAttributeSlider *this)
{
  this->m_pParent->DispatchCurve(this: this->m_pParent, a2: 4);
}

//------------------------------------------------------------------------------
// Address: 0x10496A30
// Name: public: void CAttributeSlider::SetDependent(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::SetDependent(CAttributeSlider *this, bool dependent)
{
  *((_BYTE *)this + 656) ^= (*((_BYTE *)this + 656) ^ (8 * dependent)) & 8;
}

//------------------------------------------------------------------------------
// Address: 0x10496A70
// Name: void BlendValues(bool,struct AttributeValue_t __near *,struct AttributeValue_t const __near &,struct AttributeValue_t const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __usercall BlendValues(
        int a1@<edi>,
        int a2@<esi>,
        bool bTransform,
        AttributeValue_t *pResult,
        const AttributeValue_t *src,
        const AttributeValue_t *dest,
        float flBlend,
        float flBalanceFilter)
{
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm0_4
  float v11; // xmm1_4

  if ( bTransform )
  {
    v8 = src->m_Vector.y + (float)((float)(dest->m_Vector.y - src->m_Vector.y) * flBlend);
    v9 = src->m_Vector.z + (float)((float)(dest->m_Vector.z - src->m_Vector.z) * flBlend);
    pResult->m_Vector.x = src->m_Vector.x + (float)((float)(dest->m_Vector.x - src->m_Vector.x) * flBlend);
    pResult->m_Vector.y = v8;
    pResult->m_Vector.z = v9;
    QuaternionSlerp(a1, a2, p: &src->m_Quaternion, q: &dest->m_Quaternion, t: flBlend, qt: &pResult->m_Quaternion);
  }
  else
  {
    if ( flBalanceFilter > 0.5 )
      v10 = (float)((float)(1.0 - flBalanceFilter) * 2.0) * flBlend;
    else
      v10 = flBlend;
    if ( flBalanceFilter < 0.5 )
      v11 = (float)(flBalanceFilter * 2.0) * flBlend;
    else
      v11 = flBlend;
    pResult->m_pValue[0] = (float)((float)(dest->m_pValue[0] - src->m_pValue[0]) * flBlend) + src->m_pValue[0];
    pResult->m_pValue[2] = (float)((float)(dest->m_pValue[2] - src->m_pValue[2]) * v10) + src->m_pValue[2];
    pResult->m_pValue[1] = (float)((float)(dest->m_pValue[1] - src->m_pValue[1]) * v11) + src->m_pValue[1];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10496B90
// Name: public: virtual void CAttributeSlider::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::ApplySchemeSettings(CAttributeSlider *this, vgui::IScheme *scheme)
{
  vgui::TextImage_vtbl *v4; // ebx
  unsigned int v5; // eax
  vgui::TextImage_vtbl *v6; // ebx
  unsigned int v7; // eax
  vgui::TextImage_vtbl *v8; // ebx
  unsigned int v9; // eax
  vgui::TextImage_vtbl *v10; // ebx
  unsigned int v11; // eax
  vgui::TextImage_vtbl *v12; // ebx
  unsigned int v13; // eax

  vgui::Panel::ApplySchemeSettings(this, pScheme: (int)scheme);
  v4 = this->m_pName->__vftable;
  v5 = scheme->GetFont(this: scheme, a2: aDefa_0, a3: false);
  v4->SetFont(this: this->m_pName, a2: v5);
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pName->SetColor)(a1: this->m_pName, a2: s_TextColor);
  vgui::TextImage::ResizeImageToContent(this: this->m_pName);
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pValues[0]->SetColor)(a1: this->m_pValues[0], a2: s_TextColor);
  v6 = this->m_pValues[0]->__vftable;
  v7 = scheme->GetFont(this: scheme, a2: aDefa_0, a3: false);
  v6->SetFont(this: this->m_pValues[0], a2: v7);
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pValues[1]->SetColor)(a1: this->m_pValues[1], a2: s_TextColorFocus);
  v8 = this->m_pValues[1]->__vftable;
  v9 = scheme->GetFont(this: scheme, a2: aDefa_0, a3: false);
  v8->SetFont(this: this->m_pValues[1], a2: v9);
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pValues[2]->SetColor)(a1: this->m_pValues[2], a2: s_TextColor);
  v10 = this->m_pValues[2]->__vftable;
  v11 = scheme->GetFont(this: scheme, a2: aDefa_0, a3: false);
  v10->SetFont(this: this->m_pValues[2], a2: v11);
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pValues[3]->SetColor)(a1: this->m_pValues[3], a2: s_TextColor);
  v12 = this->m_pValues[3]->__vftable;
  v13 = scheme->GetFont(this: scheme, a2: aDefa_0, a3: false);
  v12->SetFont(this: this->m_pValues[3], a2: v13);
  ((void (__thiscall *)(CAttributeSlider *, int))this->SetBgColor)(a1: this, a2: -14013910);
  ((void (__thiscall *)(CAttributeSlider *, int))this->SetFgColor)(a1: this, a2: -16746302);
}

//------------------------------------------------------------------------------
// Address: 0x10496D10
// Name: public: void CAttributeSlider::SetValue(struct AttributeValue_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::SetValue(CAttributeSlider *this, const AttributeValue_t *value)
{
  float v2; // xmm0_4
  float v3; // xmm0_4
  float x; // xmm0_4

  if ( this->m_Control.m_pValue[0] != value->m_pValue[0] )
    this->m_Control.m_pValue[0] = value->m_pValue[0];
  v2 = value->m_pValue[1];
  if ( this->m_Control.m_pValue[1] != v2 )
    this->m_Control.m_pValue[1] = v2;
  v3 = value->m_pValue[2];
  if ( this->m_Control.m_pValue[2] != v3 )
    this->m_Control.m_pValue[2] = v3;
  x = value->m_Vector.x;
  if ( x != this->m_Control.m_Vector.x
    || value->m_Vector.y != this->m_Control.m_Vector.y
    || value->m_Vector.z != this->m_Control.m_Vector.z )
  {
    this->m_Control.m_Vector.x = x;
    this->m_Control.m_Vector.y = value->m_Vector.y;
    this->m_Control.m_Vector.z = value->m_Vector.z;
  }
  if ( this->m_Control.m_Quaternion.x != value->m_Quaternion.x
    || this->m_Control.m_Quaternion.y != value->m_Quaternion.y
    || this->m_Control.m_Quaternion.z != value->m_Quaternion.z
    || this->m_Control.m_Quaternion.w != value->m_Quaternion.w )
  {
    this->m_Control.m_Quaternion = value->m_Quaternion;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10496E30
// Name: public: virtual void CAttributeSlider::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnCursorMoved(CAttributeSlider *this, int x, int y)
{
  float v4; // xmm0_4
  CBaseAnimationSetEditor *v5; // eax
  CBaseAnimationSetControl *Controller; // eax
  __m128 v7; // xmm0
  float v8; // xmm7_4
  bool v9; // zf
  int width; // xmm6_4
  float v11; // xmm7_4
  int v12; // xmm1_4
  __m128 v13; // xmm0
  __m128 v14; // xmm2
  __m128 v15; // xmm4
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  int v18; // edi
  double v19; // st7
  int v20; // ecx
  int height; // xmm0_4
  bool v22; // cf
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm5_4
  __m128 v29; // xmm2
  __m128 v30; // xmm4
  __m128 v31; // xmm1
  __m128 v32; // xmm2
  int v33; // edi
  double v34; // st7
  int v35; // ecx
  float v36; // xmm1_4
  float v37; // xmm0_4
  bool v38; // cc
  int v39; // edx
  double X; // [esp+Ch] [ebp-2Ch] BYREF
  int v41; // [esp+18h] [ebp-20h]
  Rect_t rect; // [esp+1Ch] [ebp-1Ch]
  float flValue; // [esp+2Ch] [ebp-Ch]
  float flLeftValue; // [esp+30h] [ebp-8h]
  float flBalance; // [esp+34h] [ebp-4h]

  if ( !this->IsEnabled(this) || this->m_SliderMode != SLIDER_MODE_DRAG_VALUE || (*((_BYTE *)this + 656) & 1) != 0 )
    return;
  this->m_nAccum[0] += x - this->m_nDragStartPosition[0];
  flBalance = 1.0;
  if ( ifm_attributeslider_legacy.m_pParent != nullptr && ifm_attributeslider_legacy.m_pParent->m_Value.m_nValue != 0 )
  {
    v4 = ifm_attributeslider_sensitivity.m_pParent->m_Value.m_fValue * 0.0024999999;
LABEL_9:
    flBalance = v4;
    goto LABEL_10;
  }
  CAttributeSlider::GetControlRect(this, pRect: (Rect_t *)((char *)&X + 4));
  if ( v41 > 0 )
  {
    v4 = 1.0 / (float)v41;
    goto LABEL_9;
  }
LABEL_10:
  v5 = (CBaseAnimationSetEditor *)vgui::PHandle::Get(this: &this->m_pParent->m_hEditor);
  Controller = CBaseAnimationSetEditor::GetController(this: v5);
  if ( Controller->GetRecordingState(this: Controller) == AS_RECORD )
  {
    v7 = (__m128)0xBF800000;
    v8 = 2.0;
    flValue = -1.0;
  }
  else
  {
    v7 = 0;
    flValue = 0.0;
    v8 = 1.0;
  }
  v9 = (*((_BYTE *)this + 656) & 4) == 0;
  flLeftValue = v8;
  if ( v9 )
  {
    v28 = this->m_dragStartValues.m_pValue[0];
    v29.m128_i32[0] = 1258291200;
    v7.m128_f32[0] = (float)(v7.m128_f32[0] - v28) * (float)(1.0 / flBalance);
    v30 = _mm_and_ps((__m128)0x80000000, v7);
    v29.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v7, v30), v29).m128_f32[0]) & 0x4B000000
                    | v30.m128_i32[0];
    v31 = v7;
    v31.m128_f32[0] = (float)(v7.m128_f32[0] + v29.m128_f32[0]) - v29.m128_f32[0];
    v32 = v31;
    v32.m128_f32[0] = v31.m128_f32[0] - v7.m128_f32[0];
    *(float *)&rect.y = v28;
    v33 = (int)(float)(v31.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v32, v30).m128_u32[0] & 0x3F800000));
    v34 = ceil(X: (float)((float)(v8 - v28) * (float)(1.0 / flBalance)));
    v35 = this->m_nAccum[0];
    if ( v35 >= v33 )
    {
      if ( v35 > (int)v34 )
        v35 = (int)v34;
    }
    else
    {
      v35 = v33;
    }
    v36 = flValue;
    v37 = (float)((float)v35 * flBalance) + *(float *)&rect.y;
    v38 = flValue <= v37;
    this->m_nAccum[0] = v35;
    if ( !v38 || (v36 = flLeftValue, v37 > flLeftValue) )
      v37 = v36;
    if ( this->m_Control.m_pValue[0] != v37 )
      this->m_Control.m_pValue[0] = v37;
  }
  else
  {
    *(float *)&rect.height = CBaseAnimSetAttributeSliderPanel::GetBalanceSliderValue(this: this->m_pParent);
    v11 = this->m_dragStartValues.m_pValue[1];
    rect.width = LODWORD(this->m_dragStartValues.m_pValue[2]);
    width = rect.width;
    *(float *)&rect.y = v11;
    if ( *(float *)&rect.width <= v11 )
      *(float *)&v12 = v11;
    else
      v12 = rect.width;
    v13 = (__m128)LODWORD(flValue);
    v14.m128_i32[0] = 1258291200;
    v13.m128_f32[0] = (float)(flValue - *(float *)&v12) * (float)(1.0 / flBalance);
    v15 = _mm_and_ps((__m128)0x80000000, v13);
    v14.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v13, v15), v14).m128_f32[0]) & 0x4B000000
                    | v15.m128_i32[0];
    v16 = v13;
    v16.m128_f32[0] = (float)(v13.m128_f32[0] + v14.m128_f32[0]) - v14.m128_f32[0];
    v17 = v16;
    v17.m128_f32[0] = v16.m128_f32[0] - v13.m128_f32[0];
    v18 = (int)(float)(v16.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v17, v15).m128_u32[0] & 0x3F800000));
    if ( v11 <= *(float *)&rect.width )
      *(float *)&width = v11;
    v19 = ceil(X: (float)((float)(flLeftValue - *(float *)&width) * (float)(1.0 / flBalance)));
    v20 = this->m_nAccum[0];
    if ( v20 >= v18 )
    {
      if ( v20 > (int)v19 )
        v20 = (int)v19;
    }
    else
    {
      v20 = v18;
    }
    height = rect.height;
    v22 = *(float *)&rect.height > 0.5;
    v23 = (float)v20 * flBalance;
    this->m_nAccum[0] = v20;
    if ( v22 )
      v24 = (float)((float)(1.0 - *(float *)&height) * 2.0) * v23;
    else
      v24 = v23;
    if ( *(float *)&height < 0.5 )
      v25 = (float)(*(float *)&height * 2.0) * v23;
    else
      v25 = v23;
    v26 = v24 + *(float *)&rect.width;
    if ( flValue <= v26 )
    {
      if ( v26 > flLeftValue )
        v26 = flLeftValue;
    }
    else
    {
      v26 = flValue;
    }
    v27 = v25 + *(float *)&rect.y;
    if ( flValue <= v27 )
    {
      if ( v27 > flLeftValue )
        v27 = flLeftValue;
    }
    else
    {
      v27 = flValue;
    }
    if ( this->m_Control.m_pValue[2] != v26 )
      this->m_Control.m_pValue[2] = v26;
    if ( this->m_Control.m_pValue[1] != v27 )
      this->m_Control.m_pValue[1] = v27;
  }
  if ( x != this->m_nDragStartPosition[0] || y != this->m_nDragStartPosition[1] )
  {
    v39 = this->m_nDragStartPosition[1];
    x = this->m_nDragStartPosition[0];
    y = v39;
    vgui::Panel::LocalToScreen(this, &x, &y);
    g_pVGuiInput->SetCursorPos(this: g_pVGuiInput, a2: x, a3: y);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10497220
// Name: public: void CAttributeSlider::UpdateFaderAmount(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAttributeSlider::UpdateFaderAmount(
        CAttributeSlider *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        float flAmount)
{
  bool v4; // zf
  float v5; // xmm4_4
  float v6; // xmm5_4

  v4 = (*((_BYTE *)this + 656) & 1) == 0;
  this->m_flFaderAmount = flAmount;
  if ( v4 )
  {
    this->m_PreviewCurrent.m_pValue[0] = (float)((float)(this->m_PreviewFull.m_pValue[0] - this->m_Control.m_pValue[0])
                                               * flAmount)
                                       + this->m_Control.m_pValue[0];
    this->m_PreviewCurrent.m_pValue[2] = (float)((float)(this->m_PreviewFull.m_pValue[2] - this->m_Control.m_pValue[2])
                                               * flAmount)
                                       + this->m_Control.m_pValue[2];
    this->m_PreviewCurrent.m_pValue[1] = (float)((float)(this->m_PreviewFull.m_pValue[1] - this->m_Control.m_pValue[1])
                                               * flAmount)
                                       + this->m_Control.m_pValue[1];
  }
  else
  {
    v5 = this->m_Control.m_Vector.y
       + (float)((float)(this->m_PreviewFull.m_Vector.y - this->m_Control.m_Vector.y) * flAmount);
    v6 = this->m_Control.m_Vector.z
       + (float)((float)(this->m_PreviewFull.m_Vector.z - this->m_Control.m_Vector.z) * flAmount);
    this->m_PreviewCurrent.m_Vector.x = this->m_Control.m_Vector.x
                                      + (float)((float)(this->m_PreviewFull.m_Vector.x - this->m_Control.m_Vector.x)
                                              * flAmount);
    this->m_PreviewCurrent.m_Vector.y = v5;
    this->m_PreviewCurrent.m_Vector.z = v6;
    QuaternionSlerp(
      a1: a2,
      a2: a3,
      p: &this->m_Control.m_Quaternion,
      q: &this->m_PreviewFull.m_Quaternion,
      t: flAmount,
      qt: &this->m_PreviewCurrent.m_Quaternion);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10497340
// Name: public: float CAttributeSlider::EstimateValueAtPos(int,int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAttributeSlider::EstimateValueAtPos(CAttributeSlider *this, int nLocalX, int nLocalY)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  int tall; // [esp+0h] [ebp-8h] BYREF
  int wide; // [esp+4h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  if ( wide - 12 <= 1 )
    return 0.5;
  v3 = (float)(nLocalX - 6) / (float)(wide - 13);
  v4 = 0.0;
  if ( v3 < 0.0 )
    return v4;
  v4 = 1.0;
  if ( v3 > 1.0 )
    return v4;
  else
    return v3;
}

//------------------------------------------------------------------------------
// Address: 0x104973C0
// Name: public: virtual void CAttributeSlider::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::PerformLayout(CAttributeSlider *this)
{
  int v2; // ebx
  CAttributeSliderTextEntry *m_pTextField; // ecx
  int v4; // kr00_4
  int v5; // edi
  int tall; // [esp+4h] [ebp-8h] BYREF
  int wide; // [esp+8h] [ebp-4h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  if ( this->m_pTextField != nullptr )
  {
    vgui::Panel::GetSize(this, &wide, &tall);
    v2 = (tall - 6) & ((tall - 6 < 0) - 1);
    m_pTextField = this->m_pTextField;
    if ( (*((_BYTE *)this + 656) & 4) != 0 )
    {
      v4 = wide - 12;
      v5 = (wide - 12) / 2;
      vgui::Panel::SetBounds(this: m_pTextField, x: 6, y: 3, wide: v5, tall: (tall - 6) & ((tall - 6 < 0) - 1));
      vgui::Panel::SetBounds(this: this->m_pRightTextField, x: v5 + 6, y: 3, wide: v4 / 2, tall: v2);
    }
    else
    {
      vgui::Panel::SetBounds(this: m_pTextField, x: 6, y: 3, wide: wide - 12, tall: (tall - 6) & ((tall - 6 < 0) - 1));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10497450
// Name: private: void CAttributeSlider::DrawTick(class Color const __near &,struct AttributeValue_t const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::DrawTick(
        CAttributeSlider *this,
        const Color *clr,
        const AttributeValue_t *value,
        int width,
        int inset)
{
  char *v6; // ecx
  float v7; // xmm0_4
  int v8; // edi
  __int64 v9; // rax
  int v10; // esi
  int v11; // ebx
  int v12; // eax
  int v13; // ecx
  int v14; // edi
  vgui::ISurface_vtbl *v15; // ecx
  int v16; // eax
  float v17; // xmm0_4
  int v18; // esi
  int v19; // ecx
  int v20; // [esp+Ch] [ebp-8h]
  int tall; // [esp+10h] [ebp-4h] BYREF

  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: *clr);
  vgui::Panel::GetSize(this, wide: (int *)&clr, &tall);
  v6 = (char *)&clr[-4] + 2;
  v7 = (float)((int)&clr[-4] + 2);
  v8 = ((tall - 6) & ((tall - 6 < 0) - 1)) - 2 - 2 * inset;
  v9 = ((tall - 6) & ((tall - 6 < 0) - 1)) - (((tall - 6) & ((tall - 6 < 0) - 1)) - 2 * inset);
  v10 = (((int)v9 - HIDWORD(v9)) >> 1) + 4;
  if ( (*((_BYTE *)this + 656) & 4) != 0 )
  {
    v11 = width / 2;
    v12 = (int)(float)((float)(value->m_pValue[2] * v7) + 0.5) - width / 2 + 7;
    v13 = (int)&v6[-width + 7];
    v14 = v8 / 2;
    *(float *)&tall = (float)((int)&clr[-4] + 2);
    v20 = v13;
    if ( v12 >= 7 )
    {
      if ( v12 > v13 )
        v12 = v13;
    }
    else
    {
      v12 = 7;
    }
    v15 = g_pVGuiSurface->__vftable;
    clr = (const Color *)(v10 + v14);
    inset = (int)v15;
    v15->DrawFilledRect(this: g_pVGuiSurface, a2: v12, a3: v10, a4: v12 + width, a5: v10 + v14);
    v16 = (int)(float)((float)(value->m_pValue[1] * *(float *)&tall) + 0.5) - v11 + 7;
    if ( v16 >= 7 )
    {
      if ( v16 > v20 )
        v16 = v20;
    }
    else
    {
      v16 = 7;
    }
    g_pVGuiSurface->DrawFilledRect(
      this: g_pVGuiSurface,
      a2: v16,
      a3: (int)clr,
      a4: v16 + width,
      a5: (int)&clr->_color[v14]);
  }
  else
  {
    v17 = (float)(v7 * value->m_pValue[0]) + 0.5;
    clr = (const Color *)(v8 + v10);
    v18 = (int)v17 - width / 2 + 7;
    v19 = (int)&v6[-width + 7];
    if ( v18 >= 7 )
    {
      if ( v18 > v19 )
        v18 = v19;
    }
    else
    {
      v18 = 7;
    }
    g_pVGuiSurface->DrawFilledRect(
      this: g_pVGuiSurface,
      a2: v18,
      a3: (int)clr,
      a4: v18 + width,
      a5: (int)&clr->_color[v8]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104975F0
// Name: public: virtual void CAttributeSlider::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::Paint(CAttributeSlider *this)
{
  bool v2; // bl
  CBaseAnimationSetControl *v3; // eax
  bool v4; // bl
  CBaseAnimationSetEditor *v5; // eax
  CBaseAnimSetPresetFaderPanel *PresetFader; // eax
  bool v7; // al
  float m_flFaderAmount; // xmm0_4
  Color col; // [esp+4h] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 656) & 1) == 0 )
  {
    CAttributeSlider::DrawTick(this, clr: &s_OldValueTickColor, value: &this->m_Control, width: 1, inset: 0);
    v2 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
      || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT);
    v3 = this->m_pParent->GetController(this: this->m_pParent);
    v4 = vgui::PHandle::Get(this: &v3->m_ActiveAttributeSlider) == this
      && this->m_SliderMode != SLIDER_MODE_DRAG_VALUE
      && v2;
    v5 = (CBaseAnimationSetEditor *)vgui::PHandle::Get(this: &this->m_pParent->m_hEditor);
    PresetFader = CBaseAnimationSetEditor::GetPresetFader(this: v5);
    v7 = CBaseAnimSetPresetFaderPanel::GetActivePresetSlider(this: PresetFader) != nullptr;
    if ( v4 || v7 )
    {
      m_flFaderAmount = this->m_flFaderAmount;
      col = s_PreviewTickColor;
      if ( m_flFaderAmount <= 0.1 )
        m_flFaderAmount = 0.1;
      col._color[3] = (int)(float)((float)s_PreviewTickColor._color[3] * m_flFaderAmount);
      CAttributeSlider::DrawTick(this, clr: &col, value: &this->m_PreviewFull, width: 2, inset: 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10497700
// Name: private: void CAttributeSlider::DrawValueLabel(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAttributeSlider::DrawValueLabel(CAttributeSlider *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // ebx
  int v5; // edi
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  int v9; // xmm1_4
  float v10; // xmm1_4
  char pDest[32]; // [esp+14h] [ebp-30h] BYREF
  int v14; // [esp+34h] [ebp-10h] BYREF
  int v15; // [esp+38h] [ebp-Ch] BYREF
  int v16; // [esp+3Ch] [ebp-8h] BYREF
  _DWORD var4_1[2]; // [esp+40h] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 656) & 1) == 0 )
  {
    vgui::Panel::GetSize(this, wide: &v15, tall: &v14);
    v4 = v15 - 12;
    v5 = (v14 - 6) & ((v14 - 6 < 0) - 1);
    V_snprintf(pDest, maxLen: 0x20u, pFormat: "%.1f", 0.0);
    ((void (__thiscall *)(vgui::TextImage *, char *, int, int))this->m_pValues[0]->SetText_2)(
      a1: this->m_pValues[0],
      a2: pDest,
      a3,
      a4: a2);
    vgui::TextImage::ResizeImageToContent(this: this->m_pValues[0]);
    this->m_pValues[0]->GetContentSize(this: this->m_pValues[0], a2: &v16, a3: var4_1);
    this->m_pValues[0]->SetPos(
      this: this->m_pValues[0],
      a2: 11,
      a3: (int)(float)((float)((float)(v5 - var4_1[0]) * 0.5) + 3.0));
    this->m_pValues[0]->Paint(this: this->m_pValues[0]);
    V_snprintf(pDest, maxLen: 0x20u, pFormat: "%.1f", 1.0);
    this->m_pValues[1]->SetText_2(this: this->m_pValues[1], a2: pDest);
    vgui::TextImage::ResizeImageToContent(this: this->m_pValues[1]);
    this->m_pValues[1]->GetContentSize(this: this->m_pValues[1], a2: &v16, a3: var4_1);
    this->m_pValues[1]->SetPos(
      this: this->m_pValues[1],
      a2: v4 - v16 + 1,
      a3: (int)(float)((float)((float)(v5 - var4_1[0]) * 0.5) + 3.0));
    this->m_pValues[1]->Paint(this: this->m_pValues[1]);
    v6 = 0.0;
    if ( (*((_BYTE *)this + 656) & 4) != 0 )
    {
      v7 = this->m_Control.m_pValue[2];
      if ( v7 >= 0.0 )
      {
        if ( v7 <= 1.0 )
          v6 = this->m_Control.m_pValue[2];
        else
          v6 = 1.0;
      }
      V_snprintf(pDest, maxLen: 0x20u, pFormat: "%.3f", v6);
      this->m_pValues[2]->SetText_2(this: this->m_pValues[2], a2: pDest);
      vgui::TextImage::ResizeImageToContent(this: this->m_pValues[2]);
      this->m_pValues[2]->GetContentSize(this: this->m_pValues[2], a2: &v16, a3: var4_1);
      this->m_pValues[2]->SetPos(
        this: this->m_pValues[2],
        a2: (int)(float)((float)((float)(v4 - v16) * 0.40000001) + 6.0),
        a3: (int)(float)((float)((float)(v5 - var4_1[0]) * 0.5) + 3.0));
      this->m_pValues[2]->Paint(this: this->m_pValues[2]);
      v8 = this->m_Control.m_pValue[1];
      v9 = 0;
      if ( v8 < 0.0 || (v9 = 1065353216, v8 > 1.0) )
        v8 = *(float *)&v9;
      V_snprintf(pDest, maxLen: 0x20u, pFormat: "%.3f", v8);
      this->m_pValues[3]->SetText_2(this: this->m_pValues[3], a2: pDest);
      vgui::TextImage::ResizeImageToContent(this: this->m_pValues[3]);
      ((void (__thiscall *)(vgui::TextImage *))this->m_pValues[3]->GetContentSize)(a1: this->m_pValues[3]);
      this->m_pValues[3]->SetPos(
        this: this->m_pValues[3],
        a2: (int)(float)((float)((float)(v4 - v16) * 0.60000002) + 6.0),
        a3: (int)(float)((float)((float)(v5 - var4_1[0]) * 0.5) + 3.0));
      this->m_pValues[3]->Paint(this: this->m_pValues[3]);
    }
    else
    {
      v10 = this->m_Control.m_pValue[0];
      if ( v10 >= 0.0 )
      {
        v6 = 1.0;
        if ( v10 <= 1.0 )
          v6 = this->m_Control.m_pValue[0];
      }
      V_snprintf(pDest, maxLen: 0x20u, pFormat: "%.3f", v6);
      this->m_pValues[2]->SetText_2(this: this->m_pValues[2], a2: pDest);
      vgui::TextImage::ResizeImageToContent(this: this->m_pValues[2]);
      ((void (__thiscall *)(vgui::TextImage *))this->m_pValues[2]->GetContentSize)(a1: this->m_pValues[2]);
      this->m_pValues[2]->SetPos(
        this: this->m_pValues[2],
        a2: (int)(float)((float)((float)(v4 - v16) * 0.5) + 6.0),
        a3: (int)(float)((float)((float)(v5 - var4_1[0]) * 0.5) + 3.0));
      this->m_pValues[2]->Paint(this: this->m_pValues[2]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10497AE0
// Name: private: void CAttributeSlider::DrawNameLabel(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAttributeSlider::DrawNameLabel(CAttributeSlider *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  CAttributeSlider::SliderMode_t m_SliderMode; // eax
  vgui::PHandle *v5; // eax
  Rect_t rect; // [esp+4h] [ebp-18h] BYREF
  int cw; // [esp+14h] [ebp-8h] BYREF
  int v8; // [esp+18h] [ebp-4h] BYREF

  m_SliderMode = this->m_SliderMode;
  if ( m_SliderMode == SLIDER_MODE_DRAG_VALUE )
  {
    CAttributeSlider::DrawValueLabel(this, a2, a3);
  }
  else if ( m_SliderMode != SLIDER_MODE_TEXT && this->m_pName != nullptr )
  {
    v5 = (vgui::PHandle *)((int (__thiscall *)(CBaseAnimSetAttributeSliderPanel *, int))this->m_pParent->GetController)(
                            a1: this->m_pParent,
                            a2: a3);
    vgui::PHandle::Get(this: v5 + 27);
    ((void (__thiscall *)(vgui::TextImage *))this->m_pName->SetColor)(a1: this->m_pName);
    this->m_pName->GetContentSize(this: this->m_pName, a2: &cw, a3: &v8);
    CAttributeSlider::GetControlRect(this, pRect: &rect);
    this->m_pName->SetPos(
      this: this->m_pName,
      a2: (int)(float)((float)((float)(rect.width - cw) * 0.5) + (float)rect.x),
      a3: (int)(float)((float)((float)(rect.height - v8) * 0.5) + (float)rect.y));
    this->m_pName->Paint(this: this->m_pName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10497BF0
// Name: public: virtual void CAttributeSlider::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnMousePressed(CAttributeSlider *this, ButtonCode_t code)
{
  CAttributeSlider::SliderMode_t m_SliderMode; // eax
  CDmElement *v4; // eax
  int v5; // edx
  vgui::IInput *v6; // edi
  vgui::IInput_vtbl *v7; // ebx
  int v8; // eax
  int y; // [esp+4h] [ebp-8h] BYREF
  int x; // [esp+8h] [ebp-4h] BYREF

  if ( this->IsEnabled(this) )
  {
    m_SliderMode = this->m_SliderMode;
    if ( m_SliderMode != SLIDER_MODE_TEXT && m_SliderMode != SLIDER_MODE_DRAG_VALUE && code == KEY_COUNT )
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hControl.m_handle);
      this->m_pParent->GetTypeInValueForControl(
        this: this->m_pParent,
        a2: v4,
        a3: (*((_BYTE *)this + 656) & 2) != 0,
        a4: &this->m_InitialTextEntryValue,
        a5: &this->m_Control);
      if ( (*((_BYTE *)this + 656) & 1) == 0 )
      {
        g_pVGuiInput->GetCursorPosition(this: g_pVGuiInput, a2: &x, a3: &y);
        vgui::Panel::ScreenToLocal(this, &x, &y);
        v5 = x;
        this->m_nDragStartPosition[1] = y;
        this->m_SliderMode = SLIDER_MODE_DRAG_VALUE;
        this->m_nDragStartPosition[0] = v5;
        this->m_nAccum[1] = 0;
        this->m_nAccum[0] = 0;
        AttributeValue_t::operator=(this: &this->m_dragStartValues, __that: &this->m_Control);
        v6 = g_pVGuiInput;
        v7 = g_pVGuiInput->__vftable;
        v8 = this->GetVPanel(this);
        v7->SetMouseCapture(this: v6, a2: v8);
        this->SetCursor(this, a2: 15u);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10497D10
// Name: private: void CAttributeSlider::StampValueIntoLogs(enum AnimationControlType_t,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::StampValueIntoLogs(
        CAttributeSlider *this,
        AnimationControlType_t type,
        const Vector *vecValue)
{
  CDmElement *v4; // eax

  v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hControl.m_handle);
  this->m_pParent->StampValueIntoLogs_2(this: this->m_pParent, a2: v4, a3: type, a4: vecValue);
}

//------------------------------------------------------------------------------
// Address: 0x10497D50
// Name: private: void CAttributeSlider::AcceptTextEntryValue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::AcceptTextEntryValue(CAttributeSlider *this)
{
  CDmElement *v2; // eax
  CDmeTransformControl *v3; // edi
  float v4; // xmm0_4
  DmElementHandle_t m_handle; // eax
  CDmElement *v6; // eax
  float v7; // xmm0_4
  DmElementHandle_t v8; // eax
  CDmElement *v9; // eax
  DmElementHandle_t v10; // eax
  CDmElement *v11; // eax
  CAttributeSlider *v12; // ecx
  CDmaVar<Quaternion> *Orientation; // eax
  void (__thiscall *RequestFocus)(vgui::IClientPanel *, int); // eax
  char str[64]; // [esp+8h] [ebp-90h] BYREF
  char buf[64]; // [esp+48h] [ebp-50h] BYREF
  Vector vecValue; // [esp+88h] [ebp-10h] BYREF
  float flRightValue; // [esp+94h] [ebp-4h] BYREF

  if ( this->m_SliderMode == SLIDER_MODE_TEXT )
  {
    this->m_pTextField->GetText_2(this: this->m_pTextField, a2: buf, a3: 64);
    this->m_pTextField->SetVisible(this: this->m_pTextField, a2: false);
    this->m_pTextField->SetEnabled(this: this->m_pTextField, a2: false);
    v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hControl.m_handle);
    v3 = (CDmeTransformControl *)v2;
    if ( v2 == nullptr || !v2->IsA(this: v2, a2: CDmeTransformControl::m_classType) )
      v3 = nullptr;
    if ( (*((_BYTE *)this + 656) & 1) != 0 )
    {
      if ( v3 != nullptr )
      {
        if ( sscanf(string: buf, format: "%f %f %f", &vecValue, &vecValue.y, &vecValue.z) == 3 )
        {
          if ( (*((_BYTE *)this + 656) & 2) != 0 )
          {
            CAttributeSlider::StampValueIntoLogs(this, type: ANIM_CONTROL_TXFORM_ORIENTATION, &vecValue);
            Orientation = CDmeTransformControl::GetOrientation(this: v3);
            CAttributeSlider::SetValue(this, type: ANIM_CONTROL_TXFORM_ORIENTATION, quat: &Orientation->m_Storage);
          }
          else
          {
            CAttributeSlider::SetValue(this, type: ANIM_CONTROL_COUNT, vec: &vecValue);
            CAttributeSlider::StampValueIntoLogs(this: v12, type: ANIM_CONTROL_COUNT, &vecValue);
          }
        }
        this->m_pParent->UpdatePreview(this: this->m_pParent, a2: "AcceptTextEntryValue\n");
      }
    }
    else
    {
      flRightValue = V_atof(str: buf);
      v4 = flRightValue;
      if ( (*((_BYTE *)this + 656) & 4) != 0 )
      {
        if ( this->m_Control.m_pValue[2] != flRightValue )
          this->m_Control.m_pValue[2] = flRightValue;
        m_handle = this->m_hControl.m_handle;
        flRightValue = v4;
        v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_handle);
        this->m_pParent->StampValueIntoLogs_3(
          this: this->m_pParent,
          a2: v6,
          a3: ANIM_CONTROL_VALUE_LEFT,
          a4: &flRightValue);
        this->m_pRightTextField->GetText_2(this: this->m_pRightTextField, a2: str, a3: 64);
        flRightValue = V_atof(str);
        this->m_pRightTextField->SetVisible(this: this->m_pRightTextField, a2: false);
        this->m_pRightTextField->SetEnabled(this: this->m_pRightTextField, a2: false);
        v7 = flRightValue;
        if ( this->m_Control.m_pValue[1] != flRightValue )
          this->m_Control.m_pValue[1] = flRightValue;
        v8 = this->m_hControl.m_handle;
        flRightValue = v7;
        v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: v8);
        this->m_pParent->StampValueIntoLogs_3(
          this: this->m_pParent,
          a2: v9,
          a3: ANIM_CONTROL_VALUE_RIGHT,
          a4: &flRightValue);
      }
      else
      {
        if ( this->m_Control.m_pValue[0] != flRightValue )
          this->m_Control.m_pValue[0] = flRightValue;
        v10 = this->m_hControl.m_handle;
        flRightValue = v4;
        v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: v10);
        this->m_pParent->StampValueIntoLogs_3(this: this->m_pParent, a2: v11, a3: ANIM_CONTROL_VALUE, a4: &flRightValue);
      }
    }
    RequestFocus = this->RequestFocus;
    this->m_SliderMode = SLIDER_MODE_NONE;
    RequestFocus(this, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10497FE0
// Name: public: virtual void CAttributeSliderTextEntry::OnKillFocus(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSliderTextEntry::OnKillFocus(CAttributeSliderTextEntry *this, KeyValues *pParams)
{
  void *Ptr; // eax
  CAttributeSlider *m_pSlider; // esi
  unsigned int v5; // ebx

  this->SelectNone(this);
  Ptr = KeyValues::GetPtr(this: pParams, keyName: "newPanel", defaultValue: nullptr);
  if ( Ptr == (void *)-1
    || (m_pSlider = this->m_pSlider,
        (v5 = g_pVGuiPanel->GetParent(this: g_pVGuiPanel, a2: (unsigned int)Ptr)) != m_pSlider->GetVPanel(this: m_pSlider)) )
  {
    CAttributeSlider::AcceptTextEntryValue(this: this->m_pSlider);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10498040
// Name: public: virtual void CAttributeSliderTextEntry::OnMouseWheeled(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSliderTextEntry::OnMouseWheeled(CAttributeSliderTextEntry *this, float delta)
{
  float v3; // xmm0_4
  bool v4; // al
  float v5; // xmm0_4
  void (__thiscall *GetText_2)(vgui::TextEntry *, char *, int); // edx
  double v7; // st7
  bool (__thiscall *IsKeyDown)(vgui::IInput *, ButtonCode_t); // eax
  float v9; // xmm0_4
  CAttributeSlider *m_pSlider; // ecx
  CAttributeSlider *v11; // esi
  CDmElement *v12; // eax
  char str[28]; // [esp+Ch] [ebp-40h] BYREF

  if ( (*((_BYTE *)this->m_pSlider + 656) & 5) == 0 )
  {
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT) )
    {
      v3 = (float)SLODWORD(delta) * 10.0;
    }
    else
    {
      v4 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL);
      v5 = (float)SLODWORD(delta);
      if ( v4 )
        v3 = v5 * 0.01;
      else
        v3 = v5 * 0.1;
    }
    GetText_2 = this->GetText_2;
    delta = v3;
    GetText_2(this, a2: str, a3: 64);
    v7 = V_atof(str);
    IsKeyDown = g_pVGuiInput->IsKeyDown;
    delta = v7 + delta;
    if ( IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT) )
    {
      v9 = 0.0;
      if ( delta >= 0.0 )
      {
        v9 = 1.0;
        if ( delta <= 1.0 )
          v9 = delta;
      }
      delta = v9;
    }
    V_snprintf(pDest: str, maxLen: 0x40u, pFormat: "%f", delta);
    this->SetText(this, a2: str);
    m_pSlider = this->m_pSlider;
    if ( m_pSlider->m_Control.m_pValue[0] != delta )
      m_pSlider->m_Control.m_pValue[0] = delta;
    g_pDataModel->StartUndo(this: g_pDataModel, a2: "Set Slider Value", a3: "Set Slider Value", a4: 9876);
    v11 = this->m_pSlider;
    v12 = g_pDataModel->GetElement(this: g_pDataModel, a2: v11->m_hControl.m_handle);
    v11->m_pParent->StampValueIntoLogs_3(this: v11->m_pParent, a2: v12, a3: ANIM_CONTROL_VALUE, a4: &delta);
    g_pDataModel->FinishUndo(this: g_pDataModel);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104981E0
// Name: public: virtual void CAttributeSlider::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnKeyCodeTyped(CAttributeSlider *this, ButtonCode_t code)
{
  if ( this->m_SliderMode == SLIDER_MODE_TEXT )
  {
    if ( code == KEY_ENTER )
    {
      CAttributeSlider::AcceptTextEntryValue(this);
    }
    else if ( code == KEY_ESCAPE )
    {
      CAttributeSlider::DiscardTextEntryValue(this);
    }
    else
    {
      vgui::EditablePanel::OnKeyCodeTyped(this, code);
    }
  }
  else
  {
    vgui::EditablePanel::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10498220
// Name: public: bool CAttributeSlider::IsDependent(class CAttributeSlider const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAttributeSlider::IsDependent(CAttributeSlider *this, const CAttributeSlider *pSlider)
{
  int m_Size; // edx
  int v3; // eax
  const CAttributeSlider **m_pMemory; // ecx

  m_Size = this->m_Dependenices.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    m_pMemory = this->m_Dependenices.m_Memory.m_pMemory;
    while ( *m_pMemory != pSlider )
    {
      ++v3;
      ++m_pMemory;
      if ( v3 >= m_Size )
        goto LABEL_5;
    }
  }
  return v3 != -1;
}

//------------------------------------------------------------------------------
// Address: 0x10498330
// Name: public: virtual CAttributeSlider::~CAttributeSlider(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::~CAttributeSlider(CAttributeSlider *this)
{
  vgui::TextImage *m_pName; // ecx
  vgui::TextImage *v3; // ecx
  vgui::TextImage *v4; // ecx
  vgui::TextImage *v5; // ecx
  vgui::TextImage *v6; // ecx

  m_pName = this->m_pName;
  this->__vftable = (CAttributeSlider_vtbl *)&CAttributeSlider::`vftable';
  if ( m_pName != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pName->dtr_IImage)(a1: m_pName, a2: 1);
  v3 = this->m_pValues[0];
  if ( v3 != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))v3->dtr_IImage)(a1: v3, a2: 1);
  v4 = this->m_pValues[1];
  if ( v4 != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))v4->dtr_IImage)(a1: v4, a2: 1);
  v5 = this->m_pValues[2];
  if ( v5 != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))v5->dtr_IImage)(a1: v5, a2: 1);
  v6 = this->m_pValues[3];
  if ( v6 != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))v6->dtr_IImage)(a1: v6, a2: 1);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Dependenices);
  if ( g_pDataModel != nullptr )
    CDmeElementRefHelper::Unref(this: &this->m_hControl, hElement: this->m_hControl.m_handle, handleType: HT_WEAK);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x104983D0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeSlider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeSlider::GetMessageMap(CAttributeSlider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeSlider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSlider::GetMessageMap'::`2'::s_pMap;
  `CAttributeSlider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeSlider");
  `CAttributeSlider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10498400
// Name: public: virtual struct PanelAnimationMap __near * CAttributeSlider::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeSlider::GetAnimMap(CAttributeSlider *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeSlider");
}

//------------------------------------------------------------------------------
// Address: 0x10498410
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeSlider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeSlider::GetKBMap(CAttributeSlider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeSlider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSlider::GetKBMap'::`2'::s_pMap;
  `CAttributeSlider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSlider");
  `CAttributeSlider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10498440
// Name: public: void CAttributeSlider::InitControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::InitControls(CAttributeSlider *this)
{
  char v2; // al
  CDmElement *v3; // eax
  CDmeTransformControl *v4; // edi
  CDmaVar<Quaternion> *Orientation; // eax
  CDmaVar<Vector> *Position; // eax
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // edx
  CDmElement *v8; // eax
  float m_Storage; // xmm0_4
  CDmElement *v10; // eax
  float v11; // xmm0_4
  CDmElement *v12; // eax
  float v13; // xmm0_4
  DmElementHandle_t m_handle; // [esp-4h] [ebp-Ch]

  v2 = *((_BYTE *)this + 656);
  if ( (v2 & 1) != 0 )
  {
    v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hControl.m_handle);
    v4 = (CDmeTransformControl *)v3;
    if ( v3 != nullptr && v3->IsA(this: v3, a2: CDmeTransformControl::m_classType) )
    {
      if ( (*((_BYTE *)this + 656) & 2) != 0 )
      {
        Orientation = CDmeTransformControl::GetOrientation(this: v4);
        CAttributeSlider::SetValue(this, type: ANIM_CONTROL_TXFORM_ORIENTATION, quat: &Orientation->m_Storage);
      }
      else
      {
        Position = CDmeTransformControl::GetPosition(this: v4);
        CAttributeSlider::SetValue(this, type: ANIM_CONTROL_COUNT, vec: &Position->m_Storage);
      }
    }
  }
  else
  {
    GetElement = g_pDataModel->GetElement;
    m_handle = this->m_hControl.m_handle;
    if ( (v2 & 4) != 0 )
    {
      v8 = (CDmElement *)((int (__stdcall *)(DmElementHandle_t))GetElement)(a1: m_handle);
      m_Storage = CDmElement::GetValue<float>(this: v8, pAttributeName: "leftValue")->m_Storage;
      if ( this->m_Control.m_pValue[2] != m_Storage )
        this->m_Control.m_pValue[2] = m_Storage;
      v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hControl.m_handle);
      v11 = CDmElement::GetValue<float>(this: v10, pAttributeName: "rightValue")->m_Storage;
      if ( this->m_Control.m_pValue[1] != v11 )
        this->m_Control.m_pValue[1] = v11;
    }
    else
    {
      v12 = (CDmElement *)((int (__stdcall *)(DmElementHandle_t))GetElement)(a1: m_handle);
      v13 = CDmElement::GetValue<float>(this: v12, pAttributeName: "value")->m_Storage;
      if ( this->m_Control.m_pValue[0] != v13 )
        this->m_Control.m_pValue[0] = v13;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10498560
// Name: private: void CAttributeSlider::SetToDefault(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::SetToDefault(CAttributeSlider *this)
{
  char v2; // al
  CDmElement *v3; // eax
  CDmaVar<Quaternion> *v4; // edi
  CDmElement *v5; // eax
  CDmElement *v6; // eax
  CDmaVar<Vector> *v7; // edi
  CDmElement *v8; // eax
  CDmElement *v9; // eax
  CDmAttribute *Attribute; // eax
  CDmaVar<float> *v11; // eax
  bool v12; // zf
  float m_Storage; // xmm0_4
  DmElementHandle_t v14; // edx
  CDmElement *v15; // eax
  DmElementHandle_t v16; // eax
  CDmElement *v17; // eax
  CBaseAnimSetAttributeSliderPanel *m_pParent; // ecx
  DmElementHandle_t m_handle; // eax
  int v20; // [esp+0h] [ebp-10h]
  int v21; // [esp+0h] [ebp-10h]
  int v22; // [esp+4h] [ebp-Ch]
  float *p_x; // [esp+4h] [ebp-Ch]
  float v24; // [esp+8h] [ebp-8h] BYREF
  float flDefaultValue; // [esp+Ch] [ebp-4h]

  v2 = *((_BYTE *)this + 656);
  if ( (v2 & 1) != 0 )
  {
    if ( (v2 & 2) != 0 )
    {
      v3 = (CDmElement *)((int (__stdcall *)(DmElementHandle_t, int, int))g_pDataModel->GetElement)(
                           a1: this->m_hControl.m_handle,
                           a2: v20,
                           a3: v22);
      v4 = CDmElement::GetValue<Quaternion>(this: v3, pAttributeName: "defaultOrientation");
      CAttributeSlider::SetValue(this, type: ANIM_CONTROL_TXFORM_ORIENTATION, quat: &v4->m_Storage);
      g_pDataModel->StartUndo(
        this: g_pDataModel,
        a2: "Set Slider Value To Default",
        a3: "Set Slider Value To Default",
        a4: 0);
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hControl.m_handle);
      p_x = &v4->m_Storage.x;
      v21 = 4;
      ((void (__stdcall *)(CDmElement *))this->m_pParent->StampValueIntoLogs)(a1: v5);
    }
    else
    {
      v6 = (CDmElement *)((int (__stdcall *)(DmElementHandle_t))g_pDataModel->GetElement)(a1: this->m_hControl.m_handle);
      v7 = CDmElement::GetValue<Vector>(this: v6, pAttributeName: "defaultPosition");
      if ( v7->m_Storage.x != this->m_Control.m_Vector.x
        || v7->m_Storage.y != this->m_Control.m_Vector.y
        || v7->m_Storage.z != this->m_Control.m_Vector.z )
      {
        this->m_Control.m_Vector.x = v7->m_Storage.x;
        this->m_Control.m_Vector.y = v7->m_Storage.y;
        this->m_Control.m_Vector.z = v7->m_Storage.z;
      }
      g_pDataModel->StartUndo(
        this: g_pDataModel,
        a2: "Set Slider Value To Default",
        a3: "Set Slider Value To Default",
        a4: 0);
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hControl.m_handle);
      p_x = &v7->m_Storage.x;
      v21 = 3;
      ((void (__stdcall *)(CDmElement *))this->m_pParent->StampValueIntoLogs_2)(a1: v8);
    }
  }
  else
  {
    v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hControl.m_handle);
    if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
    {
      `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
      `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
      `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
    }
    Attribute = CDmElement::FindAttribute(this: v9, pAttributeName: "defaultValue");
    if ( Attribute != nullptr )
      v11 = CDmAttribute::GetValue<float>(this: Attribute);
    else
      v11 = &`CDmElement::GetValue<float>'::`2'::defaultVal;
    v12 = (*((_BYTE *)this + 656) & 4) == 0;
    m_Storage = v11->m_Storage;
    flDefaultValue = v11->m_Storage;
    if ( v12 )
    {
      if ( this->m_Control.m_pValue[0] != m_Storage )
        this->m_Control.m_pValue[0] = m_Storage;
      g_pDataModel->StartUndo(
        this: g_pDataModel,
        a2: "Set Slider Value To Default",
        a3: "Set Slider Value To Default",
        a4: 0);
      m_handle = this->m_hControl.m_handle;
      v24 = flDefaultValue;
      v17 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_handle);
      m_pParent = this->m_pParent;
      p_x = &v24;
      v21 = 0;
    }
    else
    {
      if ( this->m_Control.m_pValue[2] != m_Storage )
        this->m_Control.m_pValue[2] = m_Storage;
      if ( this->m_Control.m_pValue[1] != m_Storage )
        this->m_Control.m_pValue[1] = m_Storage;
      g_pDataModel->StartUndo(
        this: g_pDataModel,
        a2: "Set Slider Value To Default",
        a3: "Set Slider Value To Default",
        a4: 0);
      v14 = this->m_hControl.m_handle;
      v24 = flDefaultValue;
      v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: v14);
      this->m_pParent->StampValueIntoLogs_3(this: this->m_pParent, a2: v15, a3: ANIM_CONTROL_VALUE_LEFT, a4: &v24);
      v16 = this->m_hControl.m_handle;
      v24 = flDefaultValue;
      v17 = g_pDataModel->GetElement(this: g_pDataModel, a2: v16);
      m_pParent = this->m_pParent;
      p_x = &v24;
      v21 = 1;
    }
    ((void (__stdcall *)(CDmElement *))m_pParent->StampValueIntoLogs_3)(a1: v17);
  }
  ((void (__thiscall *)(IDataModel *, int, float *))g_pDataModel->FinishUndo)(a1: g_pDataModel, a2: v21, a3: p_x);
}

//------------------------------------------------------------------------------
// Address: 0x10498840
// Name: public: virtual void CAttributeSlider::OnSetToDefault(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CAttributeSlider::OnSetToDefault(CAttributeSlider *this)
{
  CAttributeSlider::SetToDefault(this);
}

//------------------------------------------------------------------------------
// Address: 0x10498850
// Name: public: virtual void CAttributeSlider::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::PaintBackground(CAttributeSlider *this)
{
  int v1; // edi
  char *v2; // esi
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // eax
  void (__thiscall *v4)(vgui::ISurface *, Color); // eax
  int v5; // ebx
  CAttributeSlider *v6; // esi
  int v7; // ebx
  CBaseAnimationSetControl *v8; // eax
  int v9; // edi
  CBaseAnimationSetControl *v10; // eax
  vgui::IInput_vtbl *v11; // edx
  bool v12; // al
  bool v13; // zf
  bool IsPresetFaderBeingDragged; // al
  CDmElement *v15; // eax
  CDmaVar<float> *v16; // eax
  float v17; // xmm1_4
  float m_Storage; // xmm2_4
  float v19; // xmm0_4
  AttributeValue_t *p_m_PreviewCurrent; // eax
  float v21; // xmm2_4
  float v22; // xmm3_4
  Color v23; // edi
  CBaseAnimationSetControl *v24; // edi
  CBaseAnimationSetControl *v25; // edx
  bool v26; // cc
  int v27; // ebx
  Color v28; // edi
  CBaseAnimationSetControl *v29; // edx
  int rect_8a; // [esp+14h] [ebp-1Ch]
  int rect_8; // [esp+14h] [ebp-1Ch]
  int nLeftValuea; // [esp+1Ch] [ebp-14h]
  int nRightValue; // [esp+20h] [ebp-10h] BYREF
  CBaseAnimationSetControl *pController; // [esp+24h] [ebp-Ch] BYREF
  int v36; // [esp+28h] [ebp-8h]
  bool shiftDown; // [esp+2Fh] [ebp-1h]

  vgui::Panel::GetSize(this, wide: &nRightValue, tall: (int *)&pController);
  v1 = nRightValue - 12;
  v36 = -15198184;
  rect_8a = nRightValue - 12;
  v2 = (int)&pController[-1].m_crossfadePresetControlValues.m_Size + 2 < 0
     ? nullptr
     : (char *)((unsigned int)&pController[-1].m_crossfadePresetControlValues.m_Size + 2);
  ((void (__thiscall *)(vgui::ISurface *, int))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: -15198184);
  v1 += 6;
  g_pVGuiSurface->DrawOutlinedRect(this: g_pVGuiSurface, a2: 6, a3: 3, a4: v1, a5: 4);
  g_pVGuiSurface->DrawOutlinedRect(this: g_pVGuiSurface, a2: 6, a3: 3, a4: 7, a5: (int)(v2 + 3));
  DrawSetColor = g_pVGuiSurface->DrawSetColor;
  v36 = -14606047;
  ((void (__thiscall *)(vgui::ISurface *, int))DrawSetColor)(a1: g_pVGuiSurface, a2: -14606047);
  g_pVGuiSurface->DrawOutlinedRect(this: g_pVGuiSurface, a2: v1 - 1, a3: 3, a4: v1, a5: (int)(v2 + 3));
  v4 = g_pVGuiSurface->DrawSetColor;
  v36 = -13092808;
  ((void (__thiscall *)(vgui::ISurface *, int))v4)(a1: g_pVGuiSurface, a2: -13092808);
  g_pVGuiSurface->DrawOutlinedRect(this: g_pVGuiSurface, a2: 6, a3: (int)(v2 + 2), a4: v1, a5: (int)(v2 + 3));
  rect_8 = rect_8a - 2;
  v5 = (int)(v2 - 2) / 2;
  v36 = (int)(v2 + 2);
  v6 = this;
  v7 = v5 + 4;
  v8 = this->m_pParent->GetController(this: this->m_pParent);
  v9 = 4 * (vgui::PHandle::Get(this: &v8->m_ActiveAttributeSlider) == this);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)((char *)s_ZeroColor + v9));
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 7, a3: 4, a4: rect_8 + 7, a5: v36);
  if ( this->m_SliderMode != SLIDER_MODE_TEXT )
  {
    if ( (*((_BYTE *)this + 656) & 1) == 0 )
    {
      v10 = this->m_pParent->GetController(this: this->m_pParent);
      v11 = g_pVGuiInput->__vftable;
      pController = v10;
      if ( v11->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
        || (v12 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT), shiftDown = false, v12) )
      {
        shiftDown = true;
      }
      if ( vgui::PHandle::Get(this: &pController->m_ActiveAttributeSlider) != this
        || this->m_SliderMode == SLIDER_MODE_DRAG_VALUE
        || (v13 = !shiftDown, shiftDown = true, v13) )
      {
        shiftDown = false;
      }
      IsPresetFaderBeingDragged = CBaseAnimationSetControl::IsPresetFaderBeingDragged(this: pController);
      if ( shiftDown
        || IsPresetFaderBeingDragged
        || (v13 = (*((_BYTE *)pController + 104) & 2) == 0, shiftDown = false, !v13) )
      {
        shiftDown = true;
      }
      v15 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hControl.m_handle);
      v16 = CDmElement::GetValue<float>(this: v15, pAttributeName: "defaultValue");
      v17 = 0.0;
      if ( v16->m_Storage >= 0.0 )
      {
        if ( v16->m_Storage <= 1.0 )
          m_Storage = v16->m_Storage;
        else
          m_Storage = 1.0;
      }
      else
      {
        m_Storage = 0.0;
      }
      v13 = (*((_BYTE *)this + 656) & 4) == 0;
      v19 = (float)rect_8;
      pController = (CBaseAnimationSetControl *)(int)(float)((float)((float)rect_8 * m_Storage) + 0.5);
      p_m_PreviewCurrent = &this->m_PreviewCurrent;
      if ( v13 )
      {
        if ( !shiftDown )
          p_m_PreviewCurrent = &this->m_Control;
        if ( p_m_PreviewCurrent->m_pValue[0] >= 0.0 )
        {
          if ( p_m_PreviewCurrent->m_pValue[0] <= 1.0 )
            v17 = p_m_PreviewCurrent->m_pValue[0];
          else
            v17 = 1.0;
        }
        v27 = (int)(float)((float)(v19 * v17) + 0.5);
        if ( this->m_SliderMode == SLIDER_MODE_DRAG_VALUE )
          v28 = s_DraggingBarColor;
        else
          v28 = *(Color *)((char *)s_BarColor + v9);
        ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: v28);
        v29 = (CBaseAnimationSetControl *)(int)(float)((float)(v19 * v17) + 0.5);
        if ( v27 > (int)pController || (v29 = pController, v27 >= (int)pController) )
          v27 = (int)pController;
        v7 = v27 + 7;
        g_pVGuiSurface->DrawFilledRect(
          this: g_pVGuiSurface,
          a2: v7,
          a3: 4,
          a4: (int)&v29->m_hFilmClip.m_handle + 3,
          a5: v36);
        v24 = pController;
      }
      else
      {
        if ( !shiftDown )
          p_m_PreviewCurrent = &this->m_Control;
        v21 = p_m_PreviewCurrent->m_pValue[2];
        v22 = p_m_PreviewCurrent->m_pValue[1];
        if ( v21 >= 0.0 )
        {
          if ( v21 > 1.0 )
            v21 = 1.0;
        }
        else
        {
          v21 = 0.0;
        }
        nLeftValuea = (int)(float)((float)(v19 * v21) + 0.5);
        if ( v22 >= 0.0 )
        {
          if ( v22 <= 1.0 )
            v17 = p_m_PreviewCurrent->m_pValue[1];
          else
            v17 = 1.0;
        }
        v13 = v6->m_SliderMode == SLIDER_MODE_DRAG_VALUE;
        nRightValue = (int)(float)((float)(v19 * v17) + 0.5);
        if ( v13 )
          v23 = s_DraggingBarColor;
        else
          v23 = *(Color *)((char *)s_BarColor + v9);
        ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: v23);
        v24 = pController;
        v25 = (CBaseAnimationSetControl *)(int)(float)((float)(v19 * v21) + 0.5);
        v26 = nLeftValuea < (int)pController;
        if ( nLeftValuea > (int)pController
          || (v25 = pController, pController = (CBaseAnimationSetControl *)(int)(float)((float)(v19 * v21) + 0.5), !v26) )
        {
          pController = v24;
        }
        g_pVGuiSurface->DrawFilledRect(
          this: g_pVGuiSurface,
          a2: (int)&pController->m_hFilmClip.m_handle + 3,
          a3: 4,
          a4: (int)&v25->m_hFilmClip.m_handle + 3,
          a5: v7);
        pController = (CBaseAnimationSetControl *)nRightValue;
        if ( nRightValue > (int)v24 || (pController = v24, nRightValue >= (int)v24) )
          nRightValue = (int)v24;
        g_pVGuiSurface->DrawFilledRect(
          this: g_pVGuiSurface,
          a2: nRightValue + 7,
          a3: v7,
          a4: (int)&pController->m_hFilmClip.m_handle + 3,
          a5: v36);
      }
      v9 = (int)&v24->m_hFilmClip.m_handle + 3;
      if ( (*((_BYTE *)v6 + 656) & 1) == 0 )
      {
        ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: s_MidpointColor);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: v9, a3: 4, a4: v9 + 1, a5: v36);
      }
    }
    CAttributeSlider::DrawNameLabel(this: v6, a2: v7, a3: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10498C60
// Name: public: static void CAttributeSlider::KB_AddToMap(char const __near *,enum ButtonCode_t,int,void (vgui::Panel::*)(void),char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAttributeSlider::KB_AddToMap(
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
  v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSlider");
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
// Address: 0x10498D30
// Name: public: static void CAttributeSlider::PanelMessageFunc_OnSetToDefault::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeSlider::PanelMessageFunc_OnSetToDefault::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeSlider::PanelMessageFunc_OnSetToDefault::InitVar'::`2'::bAdded )
  {
    `CAttributeSlider::PanelMessageFunc_OnSetToDefault::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSystemPreviewPanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeSlider");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "SetToDefault";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10498DC0
// Name: public: static void CAttributeSlider::PanelMessageFunc_OnEditMinMaxDefault::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeSlider::PanelMessageFunc_OnEditMinMaxDefault::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeSlider::PanelMessageFunc_OnEditMinMaxDefault::InitVar'::`2'::bAdded )
  {
    `CAttributeSlider::PanelMessageFunc_OnEditMinMaxDefault::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeSlider");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "EditMinMaxDefault";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10498E50
// Name: public: static void CAttributeSlider::PanelMessageFunc_OnInputCompleted::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeSlider::PanelMessageFunc_OnInputCompleted::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeSlider::PanelMessageFunc_OnInputCompleted::InitVar'::`2'::bAdded )
  {
    `CAttributeSlider::PanelMessageFunc_OnInputCompleted::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSnapshotGrid::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeSlider");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "InputCompleted";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10498EE0
// Name: public: static void CAttributeSliderTextEntry::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeSliderTextEntry::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeSliderTextEntry::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `CAttributeSliderTextEntry::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeSliderTextEntry");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "KillFocus";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10498F80
// Name: public: CAttributeSlider::CAttributeSlider(class CBaseAnimSetAttributeSliderPanel __near *)
// Source: json
//------------------------------------------------------------------------------
CAttributeSlider *__thiscall CAttributeSlider::CAttributeSlider(
        CAttributeSlider *this,
        CBaseAnimSetAttributeSliderPanel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::TextImage *v6; // eax
  vgui::TextImage *v7; // eax
  vgui::TextImage *v8; // eax
  vgui::TextImage *v9; // eax
  vgui::TextImage *v10; // eax
  vgui::TextImage *v11; // eax
  vgui::TextImage *v12; // eax
  vgui::TextImage *v13; // eax
  vgui::TextImage *v14; // eax
  vgui::TextImage *v15; // eax
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent, panelName: &var);
  this->__vftable = (CAttributeSlider_vtbl *)&CAttributeSlider::`vftable';
  if ( `CAttributeSlider::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSlider::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CAttributeSlider");
    v3->pfnClassName = CAttributeSlider::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `CAttributeSlider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeSlider::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CAttributeSlider");
    v4->pfnClassName = CAttributeSlider::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `CAttributeSlider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSlider::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSlider");
    v5->pfnClassName = CAttributeSlider::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  CAttributeSlider::PanelMessageFunc_OnSetToDefault::InitVar(a1: (int)&savedregs);
  CAttributeSlider::PanelMessageFunc_OnEditMinMaxDefault::InitVar(a1: (int)&savedregs);
  CAttributeSlider::PanelMessageFunc_OnInputCompleted::InitVar(a1: (int)&savedregs);
  if ( `CAttributeSlider::PanelKBMapFunc_ts_curve_1::InitVar'::`2'::bAdded == 0 )
  {
    `CAttributeSlider::PanelKBMapFunc_ts_curve_1::InitVar'::`2'::bAdded = 1;
    CAttributeSlider::KB_AddToMap(
      a1: (const char *)&savedregs,
      bindingname: "ts_curve_1",
      defaultcode: KEY_1,
      default_modifiers: 0,
      function: (unsigned int) __thiscall CColorPickerPanel::`vcall'{956,{flat}},
      helpstring: (unsigned int)"#ts_curve1_help",
      passive: false);
  }
  if ( `CAttributeSlider::PanelKBMapFunc_ts_curve_2::InitVar'::`2'::bAdded == 0 )
  {
    `CAttributeSlider::PanelKBMapFunc_ts_curve_2::InitVar'::`2'::bAdded = 1;
    CAttributeSlider::KB_AddToMap(
      a1: (const char *)&savedregs,
      bindingname: "ts_curve_2",
      defaultcode: KEY_2,
      default_modifiers: 0,
      function: (unsigned int) __thiscall CParticleSystemPreviewPanel::`vcall'{960,{flat}},
      helpstring: (unsigned int)"#ts_curve2_help",
      passive: false);
  }
  if ( `CAttributeSlider::PanelKBMapFunc_ts_curve_3::InitVar'::`2'::bAdded == 0 )
  {
    `CAttributeSlider::PanelKBMapFunc_ts_curve_3::InitVar'::`2'::bAdded = 1;
    CAttributeSlider::KB_AddToMap(
      a1: (const char *)&savedregs,
      bindingname: "ts_curve_3",
      defaultcode: KEY_3,
      default_modifiers: 0,
      function: (unsigned int) __thiscall CAttributeSlider::`vcall'{964,{flat}},
      helpstring: (unsigned int)"#ts_curve3_help",
      passive: false);
  }
  if ( `CAttributeSlider::PanelKBMapFunc_ts_curve_4::InitVar'::`2'::bAdded == 0 )
  {
    `CAttributeSlider::PanelKBMapFunc_ts_curve_4::InitVar'::`2'::bAdded = 1;
    CAttributeSlider::KB_AddToMap(
      a1: (const char *)&savedregs,
      bindingname: "ts_curve_4",
      defaultcode: KEY_4,
      default_modifiers: 0,
      function: (unsigned int) __thiscall CAttributeSlider::`vcall'{968,{flat}},
      helpstring: (unsigned int)"#ts_curve4_help",
      passive: false);
  }
  this->m_pParent = parent;
  this->m_hControl.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_Control.m_pValue[0] = 0.0;
  this->m_Control.m_pValue[1] = 0.0;
  this->m_Control.m_pValue[2] = 0.0;
  this->m_Control.m_Vector.x = 0.0;
  this->m_Control.m_Vector.y = 0.0;
  this->m_Control.m_Vector.z = 0.0;
  this->m_Control.m_Quaternion = quat_identity;
  this->m_InitialTextEntryValue.m_pValue[0] = 0.0;
  this->m_InitialTextEntryValue.m_pValue[1] = 0.0;
  this->m_InitialTextEntryValue.m_pValue[2] = 0.0;
  this->m_InitialTextEntryValue.m_Vector.x = 0.0;
  this->m_InitialTextEntryValue.m_Vector.y = 0.0;
  this->m_InitialTextEntryValue.m_Vector.z = 0.0;
  this->m_InitialTextEntryValue.m_Quaternion = quat_identity;
  this->m_pTextField = nullptr;
  this->m_pRightTextField = nullptr;
  this->m_PreviewCurrent.m_pValue[0] = 0.0;
  this->m_PreviewCurrent.m_pValue[1] = 0.0;
  this->m_PreviewCurrent.m_pValue[2] = 0.0;
  this->m_PreviewCurrent.m_Vector.x = 0.0;
  this->m_PreviewCurrent.m_Vector.y = 0.0;
  this->m_PreviewCurrent.m_Vector.z = 0.0;
  this->m_PreviewCurrent.m_Quaternion = quat_identity;
  this->m_PreviewFull.m_pValue[0] = 0.0;
  this->m_PreviewFull.m_pValue[1] = 0.0;
  this->m_PreviewFull.m_pValue[2] = 0.0;
  this->m_PreviewFull.m_Vector.x = 0.0;
  this->m_PreviewFull.m_Vector.y = 0.0;
  this->m_PreviewFull.m_Vector.z = 0.0;
  this->m_PreviewFull.m_Quaternion = quat_identity;
  this->m_flFaderAmount = 1.0;
  this->m_dragStartValues.m_pValue[0] = 0.0;
  this->m_dragStartValues.m_pValue[1] = 0.0;
  this->m_dragStartValues.m_pValue[2] = 0.0;
  this->m_dragStartValues.m_Vector.x = 0.0;
  this->m_dragStartValues.m_Vector.y = 0.0;
  this->m_dragStartValues.m_Vector.z = 0.0;
  this->m_dragStartValues.m_Quaternion = quat_identity;
  *((_BYTE *)this + 656) &= ~8u;
  this->m_nVisibleComponents = LOG_COMPONENTS_ALL;
  this->m_Dependenices.m_Memory.m_pMemory = nullptr;
  this->m_Dependenices.m_Memory.m_nAllocationCount = 0;
  this->m_Dependenices.m_Memory.m_nGrowSize = 0;
  this->m_Dependenices.m_Size = 0;
  this->m_Dependenices.m_pElements = nullptr;
  this->m_hContextMenu.m_iPanelID = -1;
  vgui::Panel::SetPaintBackgroundEnabled(this, state: true);
  vgui::Panel::SetPaintBorderEnabled(this, state: false);
  CDmeTrackGroup::SetMaxTrackCount(this, color: (Color)-14013910);
  v6 = (vgui::TextImage *)operator new(nSize: 0x7Cu);
  if ( v6 != nullptr )
    v7 = vgui::TextImage::TextImage(this: v6, text: &var);
  else
    v7 = nullptr;
  this->m_pName = v7;
  v8 = (vgui::TextImage *)operator new(nSize: 0x7Cu);
  if ( v8 != nullptr )
    v9 = vgui::TextImage::TextImage(this: v8, text: &var);
  else
    v9 = nullptr;
  this->m_pValues[0] = v9;
  v10 = (vgui::TextImage *)operator new(nSize: 0x7Cu);
  if ( v10 != nullptr )
    v11 = vgui::TextImage::TextImage(this: v10, text: &var);
  else
    v11 = nullptr;
  this->m_pValues[1] = v11;
  v12 = (vgui::TextImage *)operator new(nSize: 0x7Cu);
  if ( v12 != nullptr )
    v13 = vgui::TextImage::TextImage(this: v12, text: &var);
  else
    v13 = nullptr;
  this->m_pValues[2] = v13;
  v14 = (vgui::TextImage *)operator new(nSize: 0x7Cu);
  if ( v14 != nullptr )
    v15 = vgui::TextImage::TextImage(this: v14, text: &var);
  else
    v15 = nullptr;
  this->m_pValues[3] = v15;
  vgui::Panel::SetSize(this, wide: 100, tall: 20);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104994A0
// Name: public: void CAttributeSlider::Init(class CDmElement __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::Init(CAttributeSlider *this, CDmElement *control, bool bOrientation)
{
  const char *m_pAsString; // eax
  DmElementHandle_t BufferType; // eax
  bool HasAttribute; // al
  char v7; // al
  const char *v8; // ecx
  const char *v9; // eax
  const char *v10; // edi
  char *m_szBuf; // [esp-4h] [ebp-11Ch]
  CFmtStrN<256> v12; // [esp+Ch] [ebp-10Ch] BYREF

  m_pAsString = control->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = &var;
  vgui::Panel::SetName(this, panelName: m_pAsString);
  this->m_SliderMode = SLIDER_MODE_NONE;
  BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)control);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hControl, h: BufferType);
  *((_BYTE *)this + 656) &= 0xFCu;
  if ( ((int (__thiscall *)(_DWORD, _DWORD))control->IsA)(
         a1: control,
         a2: (CUtlSymbolLarge)CDmeTransformControl::m_classType.u.m_Id) )
  {
    *((_BYTE *)this + 656) = *((_BYTE *)this + 656) ^ (*((_BYTE *)this + 656) ^ (2 * bOrientation)) & 2 | 1;
  }
  HasAttribute = CDmElement::HasAttribute(this: control, pAttributeName: "rightValue", type: AT_UNKNOWN);
  this->m_nDragStartPosition[1] = 0;
  this->m_nDragStartPosition[0] = 0;
  this->m_nAccum[1] = 0;
  this->m_nAccum[0] = 0;
  *((_BYTE *)this + 656) ^= (*((_BYTE *)this + 656) ^ (4 * HasAttribute)) & 4;
  this->m_dragStartValues.m_pValue[0] = this->m_Control.m_pValue[0];
  this->m_dragStartValues.m_pValue[1] = this->m_Control.m_pValue[1];
  this->m_dragStartValues.m_pValue[2] = this->m_Control.m_pValue[2];
  this->m_dragStartValues.m_Vector.x = this->m_Control.m_Vector.x;
  this->m_dragStartValues.m_Vector.y = this->m_Control.m_Vector.y;
  this->m_dragStartValues.m_Vector.z = this->m_Control.m_Vector.z;
  *(_QWORD *)&this->m_dragStartValues.m_Quaternion.x = *(_QWORD *)&this->m_Control.m_Quaternion.x;
  *(_QWORD *)&this->m_dragStartValues.m_Quaternion.z = *(_QWORD *)&this->m_Control.m_Quaternion.z;
  this->SetPaintBackgroundEnabled(this, a2: true);
  v7 = *((_BYTE *)this + 656);
  if ( (v7 & 1) != 0 )
  {
    v8 = "%s - rot";
    if ( (v7 & 2) == 0 )
      v8 = "%s - pos";
    v9 = control->m_Name.m_Storage.u.m_pAsString;
    if ( v9 == (const char *)-1 )
      v9 = &var;
    m_szBuf = CFmtStrN<256>::CFmtStrN<256>(this: &v12, pszFormat: v8, v9)->m_szBuf;
    this->m_pName->SetText_2(this: this->m_pName, a2: m_szBuf);
  }
  else
  {
    v10 = control->m_Name.m_Storage.u.m_pAsString;
    if ( v10 == (const char *)-1 )
      v10 = &var;
    this->m_pName->SetText_2(this: this->m_pName, a2: v10);
  }
  vgui::TextImage::ResizeImageToContent(this: this->m_pName);
  CAttributeSlider::InitControls(this);
}

//------------------------------------------------------------------------------
// Address: 0x10499640
// Name: public: virtual void CAttributeSlider::OnEditMinMaxDefault(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnEditMinMaxDefault(CAttributeSlider *this)
{
  CDmElement *v2; // eax
  CDmeChannel *Value; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmElement *v6; // eax
  vgui::MultiInputDialog *v7; // eax
  vgui::MultiInputDialog *v8; // esi
  float v9; // [esp+Ch] [ebp-Ch]
  float flDefaultValue; // [esp+10h] [ebp-8h]
  float m_Storage; // [esp+14h] [ebp-4h]

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hControl.m_handle);
  Value = CDmElement::GetValueElement<CDmeChannel>(this: v2, pAttributeName: "channel");
  if ( Value != nullptr )
  {
    v4 = CDmeChannel::GetToElement(this: Value);
    v5 = v4;
    if ( v4 != nullptr
      && v4->IsA(this: v4, a2: CDmeExpressionOperator::m_classType)
      && v5 != (CDmElement *)4
      && (*((_BYTE *)this + 656) & 4) == 0 )
    {
      m_Storage = CDmElement::GetValue<float>(this: v5, pAttributeName: "lo")->m_Storage;
      flDefaultValue = CDmElement::GetValue<float>(this: v5, pAttributeName: "hi")->m_Storage;
      v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hControl.m_handle);
      v9 = (float)((float)(flDefaultValue - m_Storage)
                 * CDmElement::GetValue<float>(this: v6, pAttributeName: "defaultValue")->m_Storage)
         + m_Storage;
      v7 = (vgui::MultiInputDialog *)operator new(nSize: 0x264u);
      if ( v7 != nullptr )
        v8 = vgui::MultiInputDialog::MultiInputDialog(
               this: v7,
               pParent: this,
               pTitle: "Edit Min/Max/Default",
               pOKText: "#VGui_OK",
               pCancelText: "#VGui_Cancel");
      else
        v8 = nullptr;
      vgui::MultiInputDialog::AddEntry(
        this: v8,
        pName: (vgui::Panel *)"min",
        pPrompt: "Min:",
        flDefaultValue: m_Storage);
      vgui::MultiInputDialog::AddEntry(this: v8, pName: (vgui::Panel *)"max", pPrompt: "Max:", flDefaultValue);
      vgui::MultiInputDialog::AddEntry(this: v8, pName: (vgui::Panel *)aDefa, pPrompt: "Default:", flDefaultValue: v9);
      v8->DoModal(this: v8);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104997B0
// Name: public: virtual void CAttributeSlider::OnInputCompleted(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnInputCompleted(CAttributeSlider *this, float params)
{
  CDmElement *v3; // eax
  CDmeChannel *v4; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  char *v7; // esi
  CBaseAnimationSetControl *v8; // eax
  CDmElement *v9; // esi
  CDmaVar<float> *v10; // eax
  CDmElement *(__thiscall *GetElement)(IDataModel *, DmElementHandle_t); // edx
  CDmElement *v12; // eax
  CDmaVar<float> *v13; // eax
  KeyValues *v14; // edi
  float v15; // xmm2_4
  void (__thiscall *StartUndo)(IDataModel *, const char *, const char *, int); // edx
  CDmAttribute *Attribute; // eax
  CDmAttribute *v18; // eax
  CDmElement *v19; // esi
  CDmAttribute *v20; // eax
  CDmElement *v21; // esi
  CDmAttribute *v22; // eax
  DmElementHandle_t flScale; // [esp+4h] [ebp-28h]
  CDmeChannel *v24; // [esp+14h] [ebp-18h]
  float m_Storage; // [esp+1Ch] [ebp-10h]
  float value; // [esp+20h] [ebp-Ch] BYREF
  float Float; // [esp+24h] [ebp-8h] BYREF
  float flBias; // [esp+28h] [ebp-4h]

  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hControl.m_handle);
  v4 = CDmElement::GetValueElement<CDmeChannel>(this: v3, pAttributeName: "channel");
  v24 = v4;
  if ( v4 != nullptr )
  {
    v5 = CDmeChannel::GetToElement(this: v4);
    v6 = v5;
    if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeExpressionOperator::m_classType) )
    {
      v7 = (char *)&v6[-1] + 64;
      if ( v7 != nullptr )
      {
        v8 = this->m_pParent->GetController(this: this->m_pParent);
        v8->OnSliderRangeRemapped(this: v8);
        v9 = (CDmElement *)(v7 + 4);
        m_Storage = CDmElement::GetValue<float>(this: v9, pAttributeName: "lo")->m_Storage;
        v10 = CDmElement::GetValue<float>(this: v9, pAttributeName: "hi");
        GetElement = g_pDataModel->GetElement;
        flScale = this->m_hControl.m_handle;
        flBias = v10->m_Storage;
        v12 = GetElement(this: g_pDataModel, a2: flScale);
        v13 = CDmElement::GetValue<float>(this: v12, pAttributeName: "value");
        v14 = (KeyValues *)LODWORD(params);
        v15 = flBias - m_Storage;
        flBias = (float)(v13->m_Storage * (float)(flBias - m_Storage)) + m_Storage;
        value = KeyValues::GetFloat(this: (KeyValues *)LODWORD(params), keyName: "min", defaultValue: 0.0);
        Float = KeyValues::GetFloat(this: v14, keyName: "max", defaultValue: 0.0);
        params = KeyValues::GetFloat(this: v14, keyName: aDefa, defaultValue: 0.0);
        StartUndo = g_pDataModel->StartUndo;
        params = (float)(params - value) / (float)(Float - value);
        flBias = (float)(flBias - value) / (float)(Float - value);
        StartUndo(this: g_pDataModel, a2: "Set Control Min/Max/Default", a3: "Set Control Min/Max/Default", a4: 0);
        Attribute = CDmElement::FindAttribute(this: v9, pAttributeName: "lo");
        if ( Attribute != nullptr
          || (Attribute = CDmElement::CreateAttribute(this: v9, pAttributeName: "lo", type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: Attribute, &value);
        }
        v18 = CDmElement::FindAttribute(this: v9, pAttributeName: "hi");
        if ( v18 != nullptr
          || (v18 = CDmElement::CreateAttribute(this: v9, pAttributeName: "hi", type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v18, value: &Float);
        }
        if ( params >= 0.0 )
        {
          if ( params > 1.0 )
            params = 1.0;
        }
        else
        {
          params = 0.0;
        }
        v19 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hControl.m_handle);
        v20 = CDmElement::FindAttribute(this: v19, pAttributeName: "defaultValue");
        if ( v20 != nullptr
          || (v20 = CDmElement::CreateAttribute(this: v19, pAttributeName: "defaultValue", type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v20, value: &params);
        }
        if ( flBias >= 0.0 )
        {
          if ( flBias <= 1.0 )
            params = flBias;
          else
            params = 1.0;
        }
        else
        {
          params = 0.0;
        }
        v21 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hControl.m_handle);
        v22 = CDmElement::FindAttribute(this: v21, pAttributeName: "value");
        if ( v22 != nullptr
          || (v22 = CDmElement::CreateAttribute(this: v21, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v22, value: &params);
        }
        RemapFloatLogValues(
          pChannel: v24,
          flBias: (float)(m_Storage - value) / (float)(Float - value),
          flScale: v15 / (float)(Float - value));
        g_pDataModel->FinishUndo(this: g_pDataModel);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10499AD0
// Name: public: virtual void CAttributeSlider::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAttributeSlider::OnMouseReleased(CAttributeSlider *this@<ecx>, int a2@<ebx>, int a3@<edi>, int code)
{
  vgui::Panel *v5; // eax
  vgui::Menu *v6; // eax
  CDragDropHelperPanel *v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // ebx
  vgui::Panel *v10; // eax
  CDmElement *v11; // eax
  CDmeChannel *Value; // eax
  CDmElement *v13; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // ebx
  vgui::Panel *v16; // eax
  vgui::Menu *v17; // eax
  int x; // [esp+4h] [ebp-4h] BYREF

  if ( this->IsEnabled(this) && (*((_BYTE *)this + 656) & 1) == 0 )
  {
    if ( code == 108 )
    {
      if ( vgui::PHandle::Get(this: &this->m_hContextMenu) != nullptr )
      {
        v5 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        if ( v5 != nullptr )
          ((void (__thiscall *)(vgui::Panel *, int))v5->dtr_Panel)(a1: v5, a2: 1);
        vgui::DHANDLE<CDragDropHelperPanel>::operator=(
          this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hContextMenu,
          pPanel: nullptr);
      }
      v6 = (vgui::Menu *)operator new(nSize: 0x420u);
      if ( v6 != nullptr )
        v7 = (CDragDropHelperPanel *)vgui::Menu::Menu(this: v6, parent: this, panelName: "ActionMenu");
      else
        v7 = nullptr;
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(
        this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hContextMenu,
        pPanel: v7);
      ((void (__thiscall *)(vgui::IInput *, int *, int *, int, int))g_pVGuiInput->GetCursorPosition)(
        a1: g_pVGuiInput,
        a2: &x,
        a3: &code,
        a4: a3,
        a5: a2);
      vgui::Panel::ScreenToLocal(this, &x, y: &code);
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "SetToDefault");
      else
        v9 = nullptr;
      v10 = vgui::PHandle::Get(this: &this->m_hContextMenu);
      v10->__vftable[1].PaintTraverse(this: v10, a2: (bool)"Set To Default", a3: (bool)v9);
      v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hControl.m_handle);
      Value = CDmElement::GetValueElement<CDmeChannel>(this: v11, pAttributeName: "channel");
      if ( Value != nullptr )
      {
        v13 = CDmeChannel::GetToElement(this: Value);
        if ( v13 != nullptr && CDmElement::IsA<CDmeExpressionOperator>(this: v13) )
        {
          v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v14 != nullptr )
            v15 = KeyValues::KeyValues(this: v14, setName: "EditMinMaxDefault");
          else
            v15 = nullptr;
          v16 = vgui::PHandle::Get(this: &this->m_hContextMenu);
          ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CAttributeSlider *, _DWORD))v16->__vftable[1].PaintTraverse)(
            a1: v16,
            a2: "Edit Min/Max/Default...",
            a3: v15,
            a4: this,
            a5: 0);
        }
      }
      v17 = (vgui::Menu *)vgui::PHandle::Get(this: &this->m_hContextMenu);
      vgui::Menu::PlaceContextMenu(a1: a3, parent: this, menu: v17);
    }
    else if ( this->m_SliderMode == SLIDER_MODE_DRAG_VALUE )
    {
      this->m_SliderMode = SLIDER_MODE_NONE;
      g_pVGuiInput->SetMouseCapture(this: g_pVGuiInput, a2: 0);
      this->SetCursor(this, a2: 2u);
      this->m_pParent->UpdatePreview(this: this->m_pParent, a2: "Attribute Slider Released");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10499CC0
// Name: public: CAttributeSliderTextEntry::CAttributeSliderTextEntry(class CAttributeSlider __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAttributeSliderTextEntry *__thiscall CAttributeSliderTextEntry::CAttributeSliderTextEntry(
        CAttributeSliderTextEntry *this,
        CAttributeSlider *slider,
        vgui::Panel *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::TextEntry::TextEntry(this, parent: slider, panelName);
  this->__vftable = (CAttributeSliderTextEntry_vtbl *)&CAttributeSliderTextEntry::`vftable';
  if ( `CAttributeSliderTextEntry::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSliderTextEntry::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeSliderTextEntry");
    v4->pfnClassName = CAttributeSliderTextEntry::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  }
  if ( `CAttributeSliderTextEntry::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeSliderTextEntry::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeSliderTextEntry");
    v5->pfnClassName = CAttributeSliderTextEntry::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "TextEntry");
  }
  if ( `CAttributeSliderTextEntry::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSliderTextEntry::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSliderTextEntry");
    v6->pfnClassName = CAttributeSliderTextEntry::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  }
  CAttributeSliderTextEntry::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  this->m_pSlider = slider;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10499D90
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeSliderTextEntry::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeSliderTextEntry::GetMessageMap(CAttributeSliderTextEntry *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeSliderTextEntry::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSliderTextEntry::GetMessageMap'::`2'::s_pMap;
  `CAttributeSliderTextEntry::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeSliderTextEntry");
  `CAttributeSliderTextEntry::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10499DC0
// Name: public: virtual struct PanelAnimationMap __near * CAttributeSliderTextEntry::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeSliderTextEntry::GetAnimMap(CAttributeSliderTextEntry *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeSliderTextEntry");
}

//------------------------------------------------------------------------------
// Address: 0x10499DD0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeSliderTextEntry::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeSliderTextEntry::GetKBMap(CAttributeSliderTextEntry *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeSliderTextEntry::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSliderTextEntry::GetKBMap'::`2'::s_pMap;
  `CAttributeSliderTextEntry::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSliderTextEntry");
  `CAttributeSliderTextEntry::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10499E00
// Name: private: void CAttributeSlider::SetupTextFieldForTextEntryMode(class CAttributeSliderTextEntry __near * __near &,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::SetupTextFieldForTextEntryMode(
        CAttributeSlider *this,
        vgui::Panel **pTextField,
        const char *pText,
        bool bRequestFocus)
{
  CAttributeSliderTextEntry *v5; // ebx
  vgui::Panel *v6; // eax
  CAttributeSliderTextEntry *v7; // eax

  if ( *pTextField == nullptr )
  {
    v5 = (CAttributeSliderTextEntry *)operator new(nSize: 0x444u);
    if ( v5 != nullptr )
    {
      v6 = (vgui::Panel *)this->GetName(this);
      v7 = CAttributeSliderTextEntry::CAttributeSliderTextEntry(this: v5, slider: this, panelName: v6);
    }
    else
    {
      v7 = nullptr;
    }
    *pTextField = v7;
    v7->SetVisible(this: v7, a2: false);
    (*pTextField)->SetEnabled(this: *pTextField, a2: false);
    vgui::TextEntry::SelectAllOnFocusAlways(this: (vgui::TextEntry *)*pTextField, status: true);
    this->InvalidateLayout(this, a2: false, a3: false);
  }
  (*pTextField)->SetVisible(this: *pTextField, a2: true);
  (*pTextField)->SetEnabled(this: *pTextField, a2: true);
  ((void (__thiscall *)(vgui::Panel *, const char *))(*pTextField)->__vftable[1].GetVPanel)(a1: *pTextField, a2: pText);
  ((void (__thiscall *)(vgui::Panel *))(*pTextField)->__vftable[1].OnMessage)(a1: *pTextField);
  if ( bRequestFocus )
    (*pTextField)->RequestFocus(this: *pTextField, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10499EC0
// Name: private: void CAttributeSlider::EnterTextEntryMode(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::EnterTextEntryMode(CAttributeSlider *this, bool bRelatchValues)
{
  char v3; // al
  char *v4; // edx
  char v5[28]; // [esp+18h] [ebp-84h] BYREF
  char pText[24]; // [esp+5Ch] [ebp-40h] BYREF

  this->m_SliderMode = SLIDER_MODE_TEXT;
  if ( !bRelatchValues )
    CAttributeSlider::SetValue(this, value: &this->m_InitialTextEntryValue);
  v3 = *((_BYTE *)this + 656);
  if ( (v3 & 1) != 0 )
  {
    V_snprintf(
      pDest: &v5[4],
      maxLen: 0x80u,
      pFormat: "%f %f %f",
      this->m_InitialTextEntryValue.m_Vector.x,
      this->m_InitialTextEntryValue.m_Vector.y,
      this->m_InitialTextEntryValue.m_Vector.z);
    v4 = &v5[4];
  }
  else
  {
    if ( (v3 & 4) != 0 )
    {
      V_snprintf(pDest: pText, maxLen: 0x40u, pFormat: "%f", this->m_InitialTextEntryValue.m_pValue[2]);
      CAttributeSlider::SetupTextFieldForTextEntryMode(
        this,
        pTextField: &this->m_pTextField,
        pText,
        bRequestFocus: true);
      V_snprintf(pDest: pText, maxLen: 0x40u, pFormat: "%f", this->m_InitialTextEntryValue.m_pValue[1]);
      CAttributeSlider::SetupTextFieldForTextEntryMode(
        this,
        pTextField: &this->m_pRightTextField,
        pText,
        bRequestFocus: false);
      return;
    }
    V_snprintf(pDest: pText, maxLen: 0x40u, pFormat: "%f", this->m_InitialTextEntryValue.m_pValue[0]);
    v4 = pText;
  }
  CAttributeSlider::SetupTextFieldForTextEntryMode(
    this,
    pTextField: &this->m_pTextField,
    pText: v4,
    bRequestFocus: true);
}

//------------------------------------------------------------------------------
// Address: 0x1049A000
// Name: public: virtual void CAttributeSlider::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnMouseDoublePressed(CAttributeSlider *this, ButtonCode_t code)
{
  int x; // [esp+4h] [ebp-8h] BYREF
  int y; // [esp+8h] [ebp-4h] BYREF

  if ( this->IsEnabled(this) && this->m_SliderMode != SLIDER_MODE_DRAG_VALUE && code == KEY_COUNT )
  {
    g_pVGuiInput->GetCursorPosition(this: g_pVGuiInput, a2: &x, a3: &y);
    vgui::Panel::ScreenToLocal(this, &x, &y);
    CAttributeSlider::EnterTextEntryMode(this, bRelatchValues: false);
  }
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00486500
// Name: public: static char const __near * CAttributeSlider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeSlider::GetPanelClassName()
{
  return "CAttributeSlider";
}

//------------------------------------------------------------------------------
// Address: 0x00486510
// Name: void ValueBalanceToLeftRight(float __near *,float __near *,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ValueBalanceToLeftRight(float *pLeft, float *pRight, float flValue, float flBalance, float flDefaultValue)
{
  float v5; // xmm1_4
  float v6; // xmm0_4

  v5 = flValue;
  if ( flBalance > 0.5 )
    v6 = (float)((float)((float)(1.0 - flBalance) * 2.0) * (float)(flValue - flDefaultValue)) + flDefaultValue;
  else
    v6 = flValue;
  *pLeft = v6;
  if ( flBalance < 0.5 )
    v5 = (float)((float)(flValue - flDefaultValue) * (float)(flBalance * 2.0)) + flDefaultValue;
  *pRight = v5;
}

//------------------------------------------------------------------------------
// Address: 0x00486590
// Name: public: static char const __near * CAttributeSliderTextEntry::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeSliderTextEntry::GetPanelClassName()
{
  return "CAttributeSliderTextEntry";
}

//------------------------------------------------------------------------------
// Address: 0x004865A0
// Name: public: void CAttributeSlider::SetValue(enum AnimationControlType_t,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::SetValue(CAttributeSlider *this, AnimationControlType_t type, float flValue)
{
  if ( this->m_Control.m_pValue[type] != flValue )
    this->m_Control.m_pValue[type] = flValue;
}

//------------------------------------------------------------------------------
// Address: 0x004865D0
// Name: public: void CAttributeSlider::SetValue(enum AnimationControlType_t,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::SetValue(CAttributeSlider *this, AnimationControlType_t type, const Vector *vec)
{
  if ( vec->x != this->m_Control.m_Vector.x
    || vec->y != this->m_Control.m_Vector.y
    || vec->z != this->m_Control.m_Vector.z )
  {
    this->m_Control.m_Vector = *vec;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00486630
// Name: public: void CAttributeSlider::SetValue(enum AnimationControlType_t,class Quaternion const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::SetValue(CAttributeSlider *this, AnimationControlType_t type, const Quaternion *quat)
{
  if ( this->m_Control.m_Quaternion.x != quat->x
    || this->m_Control.m_Quaternion.y != quat->y
    || this->m_Control.m_Quaternion.z != quat->z
    || this->m_Control.m_Quaternion.w != quat->w )
  {
    this->m_Control.m_Quaternion = *quat;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004866A0
// Name: public: struct AttributeValue_t const __near & CAttributeSlider::GetValue(void)const
// Source: json
//------------------------------------------------------------------------------
const AttributeValue_t *__thiscall CAttributeSlider::GetValue(CAttributeSlider *this)
{
  return &this->m_Control;
}

//------------------------------------------------------------------------------
// Address: 0x004866B0
// Name: public: float CAttributeSlider::GetValue(enum AnimationControlType_t)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAttributeSlider::GetValue(CAttributeSlider *this, AnimationControlType_t type)
{
  return this->m_Control.m_pValue[type];
}

//------------------------------------------------------------------------------
// Address: 0x004866D0
// Name: public: void CAttributeSlider::GetValue(enum AnimationControlType_t,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::GetValue(CAttributeSlider *this, AnimationControlType_t type, Vector *out)
{
  *out = this->m_Control.m_Vector;
}

//------------------------------------------------------------------------------
// Address: 0x00486700
// Name: public: void CAttributeSlider::GetValue(enum AnimationControlType_t,class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::GetValue(CAttributeSlider *this, AnimationControlType_t type, Quaternion *out)
{
  *out = this->m_Control.m_Quaternion;
}

//------------------------------------------------------------------------------
// Address: 0x00486730
// Name: public: float CAttributeSlider::GetPreview(enum AnimationControlType_t)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAttributeSlider::GetPreview(CAttributeSlider *this, AnimationControlType_t type)
{
  return this->m_PreviewCurrent.m_pValue[type];
}

//------------------------------------------------------------------------------
// Address: 0x00486750
// Name: public: void CAttributeSlider::GetPreview(enum AnimationControlType_t,class Vector __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::GetPreview(CAttributeSlider *this, AnimationControlType_t type, Vector *out)
{
  *out = this->m_PreviewCurrent.m_Vector;
}

//------------------------------------------------------------------------------
// Address: 0x00486780
// Name: public: void CAttributeSlider::GetPreview(enum AnimationControlType_t,class Quaternion __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::GetPreview(CAttributeSlider *this, AnimationControlType_t type, Quaternion *out)
{
  *out = this->m_PreviewCurrent.m_Quaternion;
}

//------------------------------------------------------------------------------
// Address: 0x004867B0
// Name: public: void CAttributeSlider::SetVisibleComponents(enum LogComponents_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::SetVisibleComponents(CAttributeSlider *this, LogComponents_t componentFlags)
{
  this->m_nVisibleComponents = componentFlags;
}

//------------------------------------------------------------------------------
// Address: 0x004867C0
// Name: public: enum LogComponents_t CAttributeSlider::VisibleComponents(void)const
// Source: json
//------------------------------------------------------------------------------
LogComponents_t __thiscall CAttributeSlider::VisibleComponents(CAttributeSlider *this)
{
  return this->m_nVisibleComponents;
}

//------------------------------------------------------------------------------
// Address: 0x004867D0
// Name: public: virtual void CAttributeSlider::OnCursorEntered(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnCursorEntered(CAttributeSlider *this)
{
  CBaseAnimationSetControl *v2; // eax

  if ( this->m_SliderMode != SLIDER_MODE_DRAG_VALUE )
  {
    CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
    v2 = this->m_pParent->GetController(this: this->m_pParent);
    CBaseAnimationSetControl::SetActiveAttributeSlider(this: v2, pSlider: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00486800
// Name: public: virtual void CAttributeSlider::OnCursorExited(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnCursorExited(CAttributeSlider *this)
{
  CBaseAnimationSetControl *v2; // eax

  if ( this->m_SliderMode != SLIDER_MODE_DRAG_VALUE )
  {
    CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
    v2 = this->m_pParent->GetController(this: this->m_pParent);
    CBaseAnimationSetControl::SetActiveAttributeSlider(this: v2, pSlider: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00486830
// Name: private: void CAttributeSlider::DiscardTextEntryValue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::DiscardTextEntryValue(CAttributeSlider *this)
{
  void (__thiscall *RequestFocus)(vgui::IClientPanel *, int); // edx

  if ( this->m_SliderMode == SLIDER_MODE_TEXT )
  {
    this->m_pTextField->SetVisible(this: this->m_pTextField, a2: false);
    this->m_pTextField->SetEnabled(this: this->m_pTextField, a2: false);
    if ( (*((_BYTE *)this + 656) & 4) != 0 )
    {
      this->m_pRightTextField->SetVisible(this: this->m_pRightTextField, a2: false);
      this->m_pRightTextField->SetEnabled(this: this->m_pRightTextField, a2: false);
    }
    RequestFocus = this->RequestFocus;
    this->m_SliderMode = SLIDER_MODE_NONE;
    RequestFocus(this, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004868B0
// Name: public: void CAttributeSlider::SetPreview(struct AttributeValue_t const __near &,struct AttributeValue_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::SetPreview(
        CAttributeSlider *this,
        const AttributeValue_t *value,
        const AttributeValue_t *full)
{
  this->m_PreviewCurrent = *value;
  this->m_PreviewFull = *full;
}

//------------------------------------------------------------------------------
// Address: 0x00486960
// Name: public: struct AttributeValue_t const __near & CAttributeSlider::GetPreview(void)const
// Source: json
//------------------------------------------------------------------------------
const AttributeValue_t *__thiscall CAttributeSlider::GetPreview(CAttributeSlider *this)
{
  return &this->m_PreviewCurrent;
}

//------------------------------------------------------------------------------
// Address: 0x00486970
// Name: private: void CAttributeSlider::GetControlRect(struct Rect_t __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::GetControlRect(CAttributeSlider *this, Rect_t *pRect)
{
  int v2; // ecx
  BOOL v3; // edx
  int sh; // [esp+0h] [ebp-8h] BYREF
  int sw; // [esp+4h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &sw, tall: &sh);
  pRect->width = sw - 12;
  v2 = sh - 6;
  v3 = sh - 6 < 0;
  pRect->x = 6;
  pRect->y = 3;
  pRect->height = v3 ? 0 : v2;
}

//------------------------------------------------------------------------------
// Address: 0x004869C0
// Name: protected: virtual void CAttributeSlider::OnCurve1(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnCurve1(CAttributeSlider *this)
{
  this->m_pParent->DispatchCurve(this: this->m_pParent, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x004869E0
// Name: protected: virtual void CAttributeSlider::OnCurve2(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnCurve2(CAttributeSlider *this)
{
  this->m_pParent->DispatchCurve(this: this->m_pParent, a2: 2);
}

//------------------------------------------------------------------------------
// Address: 0x00486A00
// Name: protected: virtual void CAttributeSlider::OnCurve3(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnCurve3(CAttributeSlider *this)
{
  this->m_pParent->DispatchCurve(this: this->m_pParent, a2: 3);
}

//------------------------------------------------------------------------------
// Address: 0x00486A20
// Name: protected: virtual void CAttributeSlider::OnCurve4(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnCurve4(CAttributeSlider *this)
{
  this->m_pParent->DispatchCurve(this: this->m_pParent, a2: 4);
}

//------------------------------------------------------------------------------
// Address: 0x00486A40
// Name: public: void CAttributeSlider::SetDependent(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::SetDependent(CAttributeSlider *this, bool dependent)
{
  *((_BYTE *)this + 656) ^= (*((_BYTE *)this + 656) ^ (8 * dependent)) & 8;
}

//------------------------------------------------------------------------------
// Address: 0x00486A60
// Name: float clamp<float,float,float>(float const __near &,float const __near &,float const __near &)
// Source: json
//------------------------------------------------------------------------------
double __cdecl clamp<float,float,float>(const float *val, const float *minVal, const float *maxVal)
{
  if ( *minVal > *val )
    return *minVal;
  if ( *val <= *maxVal )
    return *val;
  return *maxVal;
}

//------------------------------------------------------------------------------
// Address: 0x00486AE0
// Name: void BlendValues(bool,struct AttributeValue_t __near *,struct AttributeValue_t const __near &,struct AttributeValue_t const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BlendValues(
        bool bTransform,
        AttributeValue_t *pResult,
        const AttributeValue_t *src,
        const AttributeValue_t *dest,
        float flBlend,
        float flBalanceFilter)
{
  float v6; // xmm4_4
  float v7; // xmm5_4
  float v8; // xmm0_4
  float v9; // xmm1_4

  if ( bTransform )
  {
    v6 = src->m_Vector.y + (float)((float)(dest->m_Vector.y - src->m_Vector.y) * flBlend);
    v7 = src->m_Vector.z + (float)((float)(dest->m_Vector.z - src->m_Vector.z) * flBlend);
    pResult->m_Vector.x = src->m_Vector.x + (float)((float)(dest->m_Vector.x - src->m_Vector.x) * flBlend);
    pResult->m_Vector.y = v6;
    pResult->m_Vector.z = v7;
    QuaternionSlerp(p: &src->m_Quaternion, q: &dest->m_Quaternion, t: flBlend, qt: &pResult->m_Quaternion);
  }
  else
  {
    if ( flBalanceFilter > 0.5 )
      v8 = (float)((float)(1.0 - flBalanceFilter) * 2.0) * flBlend;
    else
      v8 = flBlend;
    if ( flBalanceFilter < 0.5 )
      v9 = (float)(flBalanceFilter * 2.0) * flBlend;
    else
      v9 = flBlend;
    pResult->m_pValue[0] = (float)((float)(dest->m_pValue[0] - src->m_pValue[0]) * flBlend) + src->m_pValue[0];
    pResult->m_pValue[2] = (float)((float)(dest->m_pValue[2] - src->m_pValue[2]) * v8) + src->m_pValue[2];
    pResult->m_pValue[1] = (float)((float)(dest->m_pValue[1] - src->m_pValue[1]) * v9) + src->m_pValue[1];
  }
}

//------------------------------------------------------------------------------
// Address: 0x00486C00
// Name: public: virtual void CAttributeSlider::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::ApplySchemeSettings(CAttributeSlider *this, vgui::IScheme *scheme)
{
  vgui::TextImage_vtbl *v4; // ebx
  unsigned int v5; // eax
  vgui::TextImage_vtbl *v6; // ebx
  unsigned int v7; // eax
  vgui::TextImage_vtbl *v8; // ebx
  unsigned int v9; // eax
  vgui::TextImage_vtbl *v10; // ebx
  unsigned int v11; // eax
  vgui::TextImage_vtbl *v12; // ebx
  unsigned int v13; // eax

  vgui::Panel::ApplySchemeSettings(this, pScheme: scheme);
  v4 = this->m_pName->__vftable;
  v5 = scheme->GetFont(this: scheme, a2: "Default", a3: false);
  v4->SetFont(this: this->m_pName, a2: v5);
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pName->SetColor)(a1: this->m_pName, a2: s_TextColor);
  vgui::TextImage::ResizeImageToContent(this: this->m_pName);
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pValues[0]->SetColor)(a1: this->m_pValues[0], a2: s_TextColor);
  v6 = this->m_pValues[0]->__vftable;
  v7 = scheme->GetFont(this: scheme, a2: "Default", a3: false);
  v6->SetFont(this: this->m_pValues[0], a2: v7);
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pValues[1]->SetColor)(a1: this->m_pValues[1], a2: s_TextColorFocus);
  v8 = this->m_pValues[1]->__vftable;
  v9 = scheme->GetFont(this: scheme, a2: "Default", a3: false);
  v8->SetFont(this: this->m_pValues[1], a2: v9);
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pValues[2]->SetColor)(a1: this->m_pValues[2], a2: s_TextColor);
  v10 = this->m_pValues[2]->__vftable;
  v11 = scheme->GetFont(this: scheme, a2: "Default", a3: false);
  v10->SetFont(this: this->m_pValues[2], a2: v11);
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pValues[3]->SetColor)(a1: this->m_pValues[3], a2: s_TextColor);
  v12 = this->m_pValues[3]->__vftable;
  v13 = scheme->GetFont(this: scheme, a2: "Default", a3: false);
  v12->SetFont(this: this->m_pValues[3], a2: v13);
  ((void (__thiscall *)(CAttributeSlider *, int))this->SetBgColor)(a1: this, a2: -14013910);
  ((void (__thiscall *)(CAttributeSlider *, int))this->SetFgColor)(a1: this, a2: -16746302);
}

//------------------------------------------------------------------------------
// Address: 0x00486D80
// Name: public: void CAttributeSlider::SetValue(struct AttributeValue_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::SetValue(CAttributeSlider *this, const AttributeValue_t *value)
{
  float v2; // xmm0_4
  float v3; // xmm0_4
  float x; // xmm0_4

  if ( this->m_Control.m_pValue[0] != value->m_pValue[0] )
    this->m_Control.m_pValue[0] = value->m_pValue[0];
  v2 = value->m_pValue[1];
  if ( this->m_Control.m_pValue[1] != v2 )
    this->m_Control.m_pValue[1] = v2;
  v3 = value->m_pValue[2];
  if ( this->m_Control.m_pValue[2] != v3 )
    this->m_Control.m_pValue[2] = v3;
  x = value->m_Vector.x;
  if ( x != this->m_Control.m_Vector.x
    || value->m_Vector.y != this->m_Control.m_Vector.y
    || value->m_Vector.z != this->m_Control.m_Vector.z )
  {
    this->m_Control.m_Vector.x = x;
    this->m_Control.m_Vector.y = value->m_Vector.y;
    this->m_Control.m_Vector.z = value->m_Vector.z;
  }
  if ( this->m_Control.m_Quaternion.x != value->m_Quaternion.x
    || this->m_Control.m_Quaternion.y != value->m_Quaternion.y
    || this->m_Control.m_Quaternion.z != value->m_Quaternion.z
    || this->m_Control.m_Quaternion.w != value->m_Quaternion.w )
  {
    this->m_Control.m_Quaternion = value->m_Quaternion;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00486EA0
// Name: public: virtual void CAttributeSlider::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnCursorMoved(CAttributeSlider *this, int x, int y)
{
  bool v4; // zf
  float v5; // xmm0_4
  CBaseAnimationSetEditor *v6; // eax
  CBaseAnimationSetControl *Controller; // eax
  __m128 v8; // xmm0
  float v9; // xmm7_4
  float v10; // xmm6_4
  float v11; // xmm7_4
  float v12; // xmm1_4
  __m128 v13; // xmm0
  __m128 v14; // xmm2
  __m128 v15; // xmm4
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  int v18; // edi
  double v19; // st7
  int v20; // ecx
  float v21; // xmm0_4
  bool v22; // cf
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm5_4
  __m128 v29; // xmm2
  __m128 v30; // xmm4
  __m128 v31; // xmm1
  __m128 v32; // xmm2
  int v33; // edi
  double v34; // st7
  int v35; // ecx
  float v36; // xmm1_4
  float v37; // xmm0_4
  bool v38; // cc
  int v39; // edx
  Rect_t rect; // [esp+10h] [ebp-28h] BYREF
  float flValue; // [esp+20h] [ebp-18h]
  float flLeftValue; // [esp+24h] [ebp-14h]
  float flBalance; // [esp+28h] [ebp-10h]
  float flMinVal; // [esp+2Ch] [ebp-Ch]
  float flMaxVal; // [esp+30h] [ebp-8h]
  float flFactor; // [esp+34h] [ebp-4h]

  if ( !this->IsEnabled(this) || this->m_SliderMode != SLIDER_MODE_DRAG_VALUE || (*((_BYTE *)this + 656) & 1) != 0 )
    return;
  this->m_nAccum[0] += x - this->m_nDragStartPosition[0];
  v4 = ifm_attributeslider_legacy.m_pParent->m_Value.m_nValue == 0;
  flFactor = 1.0;
  if ( !v4 )
  {
    v5 = ifm_attributeslider_sensitivity.m_pParent->m_Value.m_fValue * 0.0024999999;
LABEL_8:
    flFactor = v5;
    goto LABEL_9;
  }
  CAttributeSlider::GetControlRect(this, pRect: &rect);
  if ( rect.width > 0 )
  {
    v5 = 1.0 / (float)rect.width;
    goto LABEL_8;
  }
LABEL_9:
  v6 = (CBaseAnimationSetEditor *)vgui::PHandle::Get(this: &this->m_pParent->m_hEditor);
  Controller = CBaseAnimationSetEditor::GetController(this: v6);
  if ( Controller->GetRecordingState(this: Controller) == AS_RECORD )
  {
    v8 = (__m128)0xBF800000;
    v9 = 2.0;
    flMinVal = -1.0;
  }
  else
  {
    v8 = 0;
    flMinVal = 0.0;
    v9 = 1.0;
  }
  v4 = (*((_BYTE *)this + 656) & 4) == 0;
  flMaxVal = v9;
  if ( v4 )
  {
    v28 = this->m_dragStartValues.m_pValue[0];
    v29.m128_i32[0] = 1258291200;
    v8.m128_f32[0] = (float)(v8.m128_f32[0] - v28) * (float)(1.0 / flFactor);
    v30 = _mm_and_ps((__m128)0x80000000, v8);
    v29.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v8, v30), v29).m128_f32[0]) & 0x4B000000
                    | v30.m128_i32[0];
    v31 = v8;
    v31.m128_f32[0] = (float)(v8.m128_f32[0] + v29.m128_f32[0]) - v29.m128_f32[0];
    v32 = v31;
    v32.m128_f32[0] = v31.m128_f32[0] - v8.m128_f32[0];
    flValue = v28;
    v33 = (int)(float)(v31.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v32, v30).m128_u32[0] & 0x3F800000));
    v34 = ceil(X: (float)((float)(v9 - v28) * (float)(1.0 / flFactor)));
    v35 = this->m_nAccum[0];
    if ( v35 >= v33 )
    {
      if ( v35 > (int)v34 )
        v35 = (int)v34;
    }
    else
    {
      v35 = v33;
    }
    v36 = flMinVal;
    v37 = (float)((float)v35 * flFactor) + flValue;
    v38 = flMinVal <= v37;
    this->m_nAccum[0] = v35;
    if ( !v38 || (v36 = flMaxVal, v37 > flMaxVal) )
      v37 = v36;
    if ( this->m_Control.m_pValue[0] != v37 )
      this->m_Control.m_pValue[0] = v37;
  }
  else
  {
    flBalance = CBaseAnimSetAttributeSliderPanel::GetBalanceSliderValue(this: this->m_pParent);
    v11 = this->m_dragStartValues.m_pValue[1];
    flLeftValue = this->m_dragStartValues.m_pValue[2];
    v10 = flLeftValue;
    flValue = v11;
    if ( flLeftValue <= v11 )
      v12 = v11;
    else
      v12 = flLeftValue;
    v13 = (__m128)LODWORD(flMinVal);
    v14.m128_i32[0] = 1258291200;
    v13.m128_f32[0] = (float)(flMinVal - v12) * (float)(1.0 / flFactor);
    v15 = _mm_and_ps((__m128)0x80000000, v13);
    v14.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v13, v15), v14).m128_f32[0]) & 0x4B000000
                    | v15.m128_i32[0];
    v16 = v13;
    v16.m128_f32[0] = (float)(v13.m128_f32[0] + v14.m128_f32[0]) - v14.m128_f32[0];
    v17 = v16;
    v17.m128_f32[0] = v16.m128_f32[0] - v13.m128_f32[0];
    v18 = (int)(float)(v16.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v17, v15).m128_u32[0] & 0x3F800000));
    if ( v11 <= flLeftValue )
      v10 = v11;
    v19 = ceil(X: (float)((float)(flMaxVal - v10) * (float)(1.0 / flFactor)));
    v20 = this->m_nAccum[0];
    if ( v20 >= v18 )
    {
      if ( v20 > (int)v19 )
        v20 = (int)v19;
    }
    else
    {
      v20 = v18;
    }
    v21 = flBalance;
    v22 = flBalance > 0.5;
    v23 = (float)v20 * flFactor;
    this->m_nAccum[0] = v20;
    if ( v22 )
      v24 = (float)((float)(1.0 - v21) * 2.0) * v23;
    else
      v24 = v23;
    if ( v21 < 0.5 )
      v25 = (float)(v21 * 2.0) * v23;
    else
      v25 = v23;
    v26 = v24 + flLeftValue;
    if ( flMinVal <= v26 )
    {
      if ( v26 > flMaxVal )
        v26 = flMaxVal;
    }
    else
    {
      v26 = flMinVal;
    }
    v27 = v25 + flValue;
    if ( flMinVal <= v27 )
    {
      if ( v27 > flMaxVal )
        v27 = flMaxVal;
    }
    else
    {
      v27 = flMinVal;
    }
    if ( this->m_Control.m_pValue[2] != v26 )
      this->m_Control.m_pValue[2] = v26;
    if ( this->m_Control.m_pValue[1] != v27 )
      this->m_Control.m_pValue[1] = v27;
  }
  if ( x != this->m_nDragStartPosition[0] || y != this->m_nDragStartPosition[1] )
  {
    v39 = this->m_nDragStartPosition[1];
    x = this->m_nDragStartPosition[0];
    y = v39;
    vgui::Panel::LocalToScreen(this, &x, &y);
    g_pVGuiInput->SetCursorPos(this: g_pVGuiInput, a2: x, a3: y);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00487290
// Name: public: void CAttributeSlider::UpdateFaderAmount(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::UpdateFaderAmount(CAttributeSlider *this, float flAmount)
{
  bool v2; // zf
  float v3; // xmm4_4
  float v4; // xmm5_4

  v2 = (*((_BYTE *)this + 656) & 1) == 0;
  this->m_flFaderAmount = flAmount;
  if ( v2 )
  {
    this->m_PreviewCurrent.m_pValue[0] = (float)((float)(this->m_PreviewFull.m_pValue[0] - this->m_Control.m_pValue[0])
                                               * flAmount)
                                       + this->m_Control.m_pValue[0];
    this->m_PreviewCurrent.m_pValue[2] = (float)((float)(this->m_PreviewFull.m_pValue[2] - this->m_Control.m_pValue[2])
                                               * flAmount)
                                       + this->m_Control.m_pValue[2];
    this->m_PreviewCurrent.m_pValue[1] = (float)((float)(this->m_PreviewFull.m_pValue[1] - this->m_Control.m_pValue[1])
                                               * flAmount)
                                       + this->m_Control.m_pValue[1];
  }
  else
  {
    v3 = this->m_Control.m_Vector.y
       + (float)((float)(this->m_PreviewFull.m_Vector.y - this->m_Control.m_Vector.y) * flAmount);
    v4 = this->m_Control.m_Vector.z
       + (float)((float)(this->m_PreviewFull.m_Vector.z - this->m_Control.m_Vector.z) * flAmount);
    this->m_PreviewCurrent.m_Vector.x = this->m_Control.m_Vector.x
                                      + (float)((float)(this->m_PreviewFull.m_Vector.x - this->m_Control.m_Vector.x)
                                              * flAmount);
    this->m_PreviewCurrent.m_Vector.y = v3;
    this->m_PreviewCurrent.m_Vector.z = v4;
    QuaternionSlerp(
      p: &this->m_Control.m_Quaternion,
      q: &this->m_PreviewFull.m_Quaternion,
      t: flAmount,
      qt: &this->m_PreviewCurrent.m_Quaternion);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004873B0
// Name: public: float CAttributeSlider::EstimateValueAtPos(int,int)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAttributeSlider::EstimateValueAtPos(CAttributeSlider *this, int nLocalX, int nLocalY)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  int tall; // [esp+0h] [ebp-8h] BYREF
  int wide; // [esp+4h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, &wide, &tall);
  if ( wide - 12 <= 1 )
    return 0.5;
  v3 = (float)(nLocalX - 6) / (float)(wide - 13);
  v4 = 0.0;
  if ( v3 < 0.0 )
    return v4;
  v4 = 1.0;
  if ( v3 > 1.0 )
    return v4;
  else
    return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00487430
// Name: public: virtual void CAttributeSlider::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::PerformLayout(CAttributeSlider *this)
{
  int v2; // ebx
  CAttributeSliderTextEntry *m_pTextField; // ecx
  int v4; // kr00_4
  int v5; // edi
  int tall; // [esp+4h] [ebp-8h] BYREF
  int wide; // [esp+8h] [ebp-4h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  if ( this->m_pTextField != nullptr )
  {
    vgui::Panel::GetSize(this, &wide, &tall);
    v2 = (tall - 6) & ((tall - 6 < 0) - 1);
    m_pTextField = this->m_pTextField;
    if ( (*((_BYTE *)this + 656) & 4) != 0 )
    {
      v4 = wide - 12;
      v5 = (wide - 12) / 2;
      vgui::Panel::SetBounds(this: m_pTextField, x: 6, y: 3, wide: v5, tall: (tall - 6) & ((tall - 6 < 0) - 1));
      vgui::Panel::SetBounds(this: this->m_pRightTextField, x: v5 + 6, y: 3, wide: v4 / 2, tall: v2);
    }
    else
    {
      vgui::Panel::SetBounds(this: m_pTextField, x: 6, y: 3, wide: wide - 12, tall: (tall - 6) & ((tall - 6 < 0) - 1));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004874C0
// Name: private: void CAttributeSlider::DrawTick(class Color const __near &,struct AttributeValue_t const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::DrawTick(
        CAttributeSlider *this,
        const Color *clr,
        const AttributeValue_t *value,
        int width,
        int inset)
{
  char *v6; // ecx
  float v7; // xmm0_4
  int v8; // edi
  __int64 v9; // rax
  int v10; // esi
  int v11; // ebx
  int v12; // eax
  int v13; // ecx
  int v14; // edi
  vgui::ISurface_vtbl *v15; // ecx
  int v16; // eax
  float v17; // xmm0_4
  int v18; // esi
  int v19; // ecx
  int v20; // [esp+Ch] [ebp-8h]
  int tall; // [esp+10h] [ebp-4h] BYREF

  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: *clr);
  vgui::Panel::GetSize(this, wide: (int *)&clr, &tall);
  v6 = (char *)&clr[-4] + 2;
  v7 = (float)((int)&clr[-4] + 2);
  v8 = ((tall - 6) & ((tall - 6 < 0) - 1)) - 2 - 2 * inset;
  v9 = ((tall - 6) & ((tall - 6 < 0) - 1)) - (((tall - 6) & ((tall - 6 < 0) - 1)) - 2 * inset);
  v10 = (((int)v9 - HIDWORD(v9)) >> 1) + 4;
  if ( (*((_BYTE *)this + 656) & 4) != 0 )
  {
    v11 = width / 2;
    v12 = (int)(float)((float)(value->m_pValue[2] * v7) + 0.5) - width / 2 + 7;
    v13 = (int)&v6[-width + 7];
    v14 = v8 / 2;
    *(float *)&tall = (float)((int)&clr[-4] + 2);
    v20 = v13;
    if ( v12 >= 7 )
    {
      if ( v12 > v13 )
        v12 = v13;
    }
    else
    {
      v12 = 7;
    }
    v15 = g_pVGuiSurface->__vftable;
    clr = (const Color *)(v10 + v14);
    inset = (int)v15;
    v15->DrawFilledRect(this: g_pVGuiSurface, a2: v12, a3: v10, a4: v12 + width, a5: v10 + v14);
    v16 = (int)(float)((float)(value->m_pValue[1] * *(float *)&tall) + 0.5) - v11 + 7;
    if ( v16 >= 7 )
    {
      if ( v16 > v20 )
        v16 = v20;
    }
    else
    {
      v16 = 7;
    }
    g_pVGuiSurface->DrawFilledRect(
      this: g_pVGuiSurface,
      a2: v16,
      a3: (int)clr,
      a4: v16 + width,
      a5: (int)&clr->_color[v14]);
  }
  else
  {
    v17 = (float)(v7 * value->m_pValue[0]) + 0.5;
    clr = (const Color *)(v8 + v10);
    v18 = (int)v17 - width / 2 + 7;
    v19 = (int)&v6[-width + 7];
    if ( v18 >= 7 )
    {
      if ( v18 > v19 )
        v18 = v19;
    }
    else
    {
      v18 = 7;
    }
    g_pVGuiSurface->DrawFilledRect(
      this: g_pVGuiSurface,
      a2: v18,
      a3: (int)clr,
      a4: v18 + width,
      a5: (int)&clr->_color[v8]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00487660
// Name: public: virtual void CAttributeSlider::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::Paint(CAttributeSlider *this)
{
  bool v2; // bl
  CBaseAnimationSetControl *v3; // eax
  bool v4; // bl
  CBaseAnimationSetEditor *v5; // eax
  CBaseAnimSetPresetFaderPanel *PresetFader; // eax
  bool v7; // al
  float m_flFaderAmount; // xmm0_4
  Color col; // [esp+4h] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 656) & 1) == 0 )
  {
    CAttributeSlider::DrawTick(this, clr: &s_OldValueTickColor, value: &this->m_Control, width: 1, inset: 0);
    v2 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
      || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT);
    v3 = this->m_pParent->GetController(this: this->m_pParent);
    v4 = vgui::PHandle::Get(this: &v3->m_ActiveAttributeSlider) == this
      && this->m_SliderMode != SLIDER_MODE_DRAG_VALUE
      && v2;
    v5 = (CBaseAnimationSetEditor *)vgui::PHandle::Get(this: &this->m_pParent->m_hEditor);
    PresetFader = CBaseAnimationSetEditor::GetPresetFader(this: v5);
    v7 = CBaseAnimSetPresetFaderPanel::GetActivePresetSlider(this: PresetFader) != nullptr;
    if ( v4 || v7 )
    {
      m_flFaderAmount = this->m_flFaderAmount;
      col = s_PreviewTickColor;
      if ( m_flFaderAmount <= 0.1 )
        m_flFaderAmount = 0.1;
      col._color[3] = (int)(float)((float)s_PreviewTickColor._color[3] * m_flFaderAmount);
      CAttributeSlider::DrawTick(this, clr: &col, value: &this->m_PreviewFull, width: 2, inset: 2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00487770
// Name: private: void CAttributeSlider::DrawValueLabel(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAttributeSlider::DrawValueLabel(CAttributeSlider *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int v4; // ebx
  int v5; // edi
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  int v9; // xmm1_4
  float v10; // xmm1_4
  char sz[32]; // [esp+50h] [ebp-30h] BYREF
  int tall; // [esp+70h] [ebp-10h] BYREF
  int wide; // [esp+74h] [ebp-Ch] BYREF
  int cw; // [esp+78h] [ebp-8h] BYREF
  int v17; // [esp+7Ch] [ebp-4h] BYREF

  if ( (*((_BYTE *)this + 656) & 1) == 0 )
  {
    vgui::Panel::GetSize(this, &wide, &tall);
    v4 = wide - 12;
    v5 = (tall - 6) & ((tall - 6 < 0) - 1);
    V_snprintf(pDest: sz, maxLen: 32, pFormat: "%.1f", 0.0);
    ((void (__thiscall *)(vgui::TextImage *, char *, int, int))this->m_pValues[0]->SetText_2)(
      a1: this->m_pValues[0],
      a2: sz,
      a3,
      a4: a2);
    vgui::TextImage::ResizeImageToContent(this: this->m_pValues[0]);
    this->m_pValues[0]->GetContentSize(this: this->m_pValues[0], a2: &cw, a3: &v17);
    this->m_pValues[0]->SetPos(
      this: this->m_pValues[0],
      a2: 11,
      a3: (int)(float)((float)((float)(v5 - v17) * 0.5) + 3.0));
    this->m_pValues[0]->Paint(this: this->m_pValues[0]);
    V_snprintf(pDest: sz, maxLen: 32, pFormat: "%.1f", 1.0);
    this->m_pValues[1]->SetText_2(this: this->m_pValues[1], a2: sz);
    vgui::TextImage::ResizeImageToContent(this: this->m_pValues[1]);
    this->m_pValues[1]->GetContentSize(this: this->m_pValues[1], a2: &cw, a3: &v17);
    this->m_pValues[1]->SetPos(
      this: this->m_pValues[1],
      a2: v4 - cw + 1,
      a3: (int)(float)((float)((float)(v5 - v17) * 0.5) + 3.0));
    this->m_pValues[1]->Paint(this: this->m_pValues[1]);
    v6 = 0.0;
    if ( (*((_BYTE *)this + 656) & 4) != 0 )
    {
      v7 = this->m_Control.m_pValue[2];
      if ( v7 >= 0.0 )
      {
        if ( v7 <= 1.0 )
          v6 = this->m_Control.m_pValue[2];
        else
          v6 = 1.0;
      }
      V_snprintf(pDest: sz, maxLen: 32, pFormat: "%.3f", v6);
      this->m_pValues[2]->SetText_2(this: this->m_pValues[2], a2: sz);
      vgui::TextImage::ResizeImageToContent(this: this->m_pValues[2]);
      this->m_pValues[2]->GetContentSize(this: this->m_pValues[2], a2: &cw, a3: &v17);
      this->m_pValues[2]->SetPos(
        this: this->m_pValues[2],
        a2: (int)(float)((float)((float)(v4 - cw) * 0.40000001) + 6.0),
        a3: (int)(float)((float)((float)(v5 - v17) * 0.5) + 3.0));
      this->m_pValues[2]->Paint(this: this->m_pValues[2]);
      v8 = this->m_Control.m_pValue[1];
      v9 = 0;
      if ( v8 < 0.0 || (v9 = 1065353216, v8 > 1.0) )
        v8 = *(float *)&v9;
      V_snprintf(pDest: sz, maxLen: 32, pFormat: "%.3f", v8);
      this->m_pValues[3]->SetText_2(this: this->m_pValues[3], a2: sz);
      vgui::TextImage::ResizeImageToContent(this: this->m_pValues[3]);
      ((void (__thiscall *)(vgui::TextImage *))this->m_pValues[3]->GetContentSize)(a1: this->m_pValues[3]);
      this->m_pValues[3]->SetPos(
        this: this->m_pValues[3],
        a2: (int)(float)((float)((float)(v4 - cw) * 0.60000002) + 6.0),
        a3: (int)(float)((float)((float)(v5 - v17) * 0.5) + 3.0));
      this->m_pValues[3]->Paint(this: this->m_pValues[3]);
    }
    else
    {
      v10 = this->m_Control.m_pValue[0];
      if ( v10 >= 0.0 )
      {
        v6 = 1.0;
        if ( v10 <= 1.0 )
          v6 = this->m_Control.m_pValue[0];
      }
      V_snprintf(pDest: sz, maxLen: 32, pFormat: "%.3f", v6);
      this->m_pValues[2]->SetText_2(this: this->m_pValues[2], a2: sz);
      vgui::TextImage::ResizeImageToContent(this: this->m_pValues[2]);
      ((void (__thiscall *)(vgui::TextImage *))this->m_pValues[2]->GetContentSize)(a1: this->m_pValues[2]);
      this->m_pValues[2]->SetPos(
        this: this->m_pValues[2],
        a2: (int)(float)((float)((float)(v4 - cw) * 0.5) + 6.0),
        a3: (int)(float)((float)((float)(v5 - v17) * 0.5) + 3.0));
      this->m_pValues[2]->Paint(this: this->m_pValues[2]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00487B50
// Name: private: void CAttributeSlider::DrawNameLabel(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAttributeSlider::DrawNameLabel(CAttributeSlider *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  CAttributeSlider::SliderMode_t m_SliderMode; // eax
  vgui::PHandle *v5; // eax
  Rect_t rect; // [esp+4h] [ebp-18h] BYREF
  int cw; // [esp+14h] [ebp-8h] BYREF
  int v8; // [esp+18h] [ebp-4h] BYREF

  m_SliderMode = this->m_SliderMode;
  if ( m_SliderMode == SLIDER_MODE_DRAG_VALUE )
  {
    CAttributeSlider::DrawValueLabel(this, a2, a3);
  }
  else if ( m_SliderMode != SLIDER_MODE_TEXT && this->m_pName != nullptr )
  {
    v5 = (vgui::PHandle *)((int (__thiscall *)(CBaseAnimSetAttributeSliderPanel *, int))this->m_pParent->GetController)(
                            a1: this->m_pParent,
                            a2: a3);
    vgui::PHandle::Get(this: v5 + 27);
    ((void (__thiscall *)(vgui::TextImage *))this->m_pName->SetColor)(a1: this->m_pName);
    this->m_pName->GetContentSize(this: this->m_pName, a2: &cw, a3: &v8);
    CAttributeSlider::GetControlRect(this, pRect: &rect);
    this->m_pName->SetPos(
      this: this->m_pName,
      a2: (int)(float)((float)((float)(rect.width - cw) * 0.5) + (float)rect.x),
      a3: (int)(float)((float)((float)(rect.height - v8) * 0.5) + (float)rect.y));
    this->m_pName->Paint(this: this->m_pName);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00487C60
// Name: public: virtual void CAttributeSlider::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnMousePressed(CAttributeSlider *this, ButtonCode_t code)
{
  CAttributeSlider::SliderMode_t m_SliderMode; // eax
  CDmElement *v4; // eax
  int v5; // edx
  vgui::IInput *v6; // edi
  vgui::IInput_vtbl *v7; // ebx
  int v8; // eax
  int y; // [esp+4h] [ebp-8h] BYREF
  int x; // [esp+8h] [ebp-4h] BYREF

  if ( this->IsEnabled(this) )
  {
    m_SliderMode = this->m_SliderMode;
    if ( m_SliderMode != SLIDER_MODE_TEXT && m_SliderMode != SLIDER_MODE_DRAG_VALUE && code == KEY_COUNT )
    {
      v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                           a1: g_pDataModel.u,
                           a2: this->m_hControl.m_handle);
      this->m_pParent->GetTypeInValueForControl(
        this: this->m_pParent,
        a2: v4,
        a3: (*((_BYTE *)this + 656) & 2) != 0,
        a4: &this->m_InitialTextEntryValue,
        a5: &this->m_Control);
      if ( (*((_BYTE *)this + 656) & 1) == 0 )
      {
        g_pVGuiInput->GetCursorPosition(this: g_pVGuiInput, a2: &x, a3: &y);
        vgui::Panel::ScreenToLocal(this, &x, &y);
        v5 = x;
        this->m_nDragStartPosition[1] = y;
        this->m_SliderMode = SLIDER_MODE_DRAG_VALUE;
        this->m_nDragStartPosition[0] = v5;
        this->m_nAccum[1] = 0;
        this->m_nAccum[0] = 0;
        AttributeValue_t::operator=(this: &this->m_dragStartValues, __that: &this->m_Control);
        v6 = g_pVGuiInput;
        v7 = g_pVGuiInput->__vftable;
        v8 = this->GetVPanel(this);
        v7->SetMouseCapture(this: v6, a2: v8);
        this->SetCursor(this, a2: 15u);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00487D80
// Name: private: void CAttributeSlider::StampValueIntoLogs(enum AnimationControlType_t,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::StampValueIntoLogs(
        CAttributeSlider *this,
        AnimationControlType_t type,
        const Vector *vecValue)
{
  CDmElement *v4; // eax

  v4 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_hControl.m_handle);
  this->m_pParent->StampValueIntoLogs_2(this: this->m_pParent, a2: v4, a3: type, a4: vecValue);
}

//------------------------------------------------------------------------------
// Address: 0x00487DC0
// Name: private: void CAttributeSlider::AcceptTextEntryValue(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::AcceptTextEntryValue(CAttributeSlider *this)
{
  int v2; // eax
  CDmeTransformControl *v3; // edi
  float v4; // xmm0_4
  DmElementHandle_t m_handle; // eax
  CDmElement *v6; // eax
  float v7; // xmm0_4
  DmElementHandle_t v8; // eax
  CDmElement *v9; // eax
  DmElementHandle_t v10; // eax
  CDmElement *v11; // eax
  CAttributeSlider *v12; // ecx
  const Quaternion *Orientation; // eax
  void (__thiscall *RequestFocus)(vgui::IClientPanel *, int); // eax
  char str[64]; // [esp+8h] [ebp-90h] BYREF
  char buf[64]; // [esp+48h] [ebp-50h] BYREF
  Vector vecValue; // [esp+88h] [ebp-10h] BYREF
  float flRightValue; // [esp+94h] [ebp-4h] BYREF

  if ( this->m_SliderMode == SLIDER_MODE_TEXT )
  {
    this->m_pTextField->GetText_2(this: this->m_pTextField, a2: buf, a3: 64);
    this->m_pTextField->SetVisible(this: this->m_pTextField, a2: false);
    this->m_pTextField->SetEnabled(this: this->m_pTextField, a2: false);
    v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hControl.m_handle);
    v3 = (CDmeTransformControl *)v2;
    if ( v2 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
           a1: v2,
           a2: CDmeTransformControl::m_classType.u) == 0 )
    {
      v3 = nullptr;
    }
    if ( (*((_BYTE *)this + 656) & 1) != 0 )
    {
      if ( v3 != nullptr )
      {
        if ( sscanf(string: buf, format: "%f %f %f", &vecValue, &vecValue.y, &vecValue.z) == 3 )
        {
          if ( (*((_BYTE *)this + 656) & 2) != 0 )
          {
            CAttributeSlider::StampValueIntoLogs(this, type: ANIM_CONTROL_TXFORM_ORIENTATION, &vecValue);
            Orientation = CDmeTransformControl::GetOrientation(this: v3);
            CAttributeSlider::SetValue(this, type: ANIM_CONTROL_TXFORM_ORIENTATION, quat: Orientation);
          }
          else
          {
            CAttributeSlider::SetValue(this, type: ANIM_CONTROL_COUNT, vec: &vecValue);
            CAttributeSlider::StampValueIntoLogs(this: v12, type: ANIM_CONTROL_COUNT, &vecValue);
          }
        }
        this->m_pParent->UpdatePreview(this: this->m_pParent, a2: "AcceptTextEntryValue\n");
      }
    }
    else
    {
      flRightValue = V_atof(str: buf);
      v4 = flRightValue;
      if ( (*((_BYTE *)this + 656) & 4) != 0 )
      {
        if ( this->m_Control.m_pValue[2] != flRightValue )
          this->m_Control.m_pValue[2] = flRightValue;
        m_handle = this->m_hControl.m_handle;
        flRightValue = v4;
        v6 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                             a1: g_pDataModel.u,
                             a2: m_handle);
        this->m_pParent->StampValueIntoLogs_3(
          this: this->m_pParent,
          a2: v6,
          a3: ANIM_CONTROL_VALUE_LEFT,
          a4: &flRightValue);
        this->m_pRightTextField->GetText_2(this: this->m_pRightTextField, a2: str, a3: 64);
        flRightValue = V_atof(str);
        this->m_pRightTextField->SetVisible(this: this->m_pRightTextField, a2: false);
        this->m_pRightTextField->SetEnabled(this: this->m_pRightTextField, a2: false);
        v7 = flRightValue;
        if ( this->m_Control.m_pValue[1] != flRightValue )
          this->m_Control.m_pValue[1] = flRightValue;
        v8 = this->m_hControl.m_handle;
        flRightValue = v7;
        v9 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                             a1: g_pDataModel.u,
                             a2: v8);
        this->m_pParent->StampValueIntoLogs_3(
          this: this->m_pParent,
          a2: v9,
          a3: ANIM_CONTROL_VALUE_RIGHT,
          a4: &flRightValue);
      }
      else
      {
        if ( this->m_Control.m_pValue[0] != flRightValue )
          this->m_Control.m_pValue[0] = flRightValue;
        v10 = this->m_hControl.m_handle;
        flRightValue = v4;
        v11 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                              a1: g_pDataModel.u,
                              a2: v10);
        this->m_pParent->StampValueIntoLogs_3(this: this->m_pParent, a2: v11, a3: ANIM_CONTROL_VALUE, a4: &flRightValue);
      }
    }
    RequestFocus = this->RequestFocus;
    this->m_SliderMode = SLIDER_MODE_NONE;
    RequestFocus(this, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00488050
// Name: public: virtual void CAttributeSliderTextEntry::OnKillFocus(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSliderTextEntry::OnKillFocus(CAttributeSliderTextEntry *this, KeyValues *pParams)
{
  void *Ptr; // eax
  CAttributeSlider *m_pSlider; // esi
  unsigned int v5; // ebx

  this->SelectNone(this);
  Ptr = KeyValues::GetPtr(this: pParams, keyName: "newPanel", defaultValue: nullptr);
  if ( Ptr == (void *)-1
    || (m_pSlider = this->m_pSlider,
        (v5 = g_pVGuiPanel->GetParent(this: g_pVGuiPanel, a2: (unsigned int)Ptr)) != m_pSlider->GetVPanel(this: m_pSlider)) )
  {
    CAttributeSlider::AcceptTextEntryValue(this: this->m_pSlider);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004880B0
// Name: public: virtual void CAttributeSliderTextEntry::OnMouseWheeled(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSliderTextEntry::OnMouseWheeled(CAttributeSliderTextEntry *this, float delta)
{
  float v3; // xmm0_4
  bool v4; // al
  float v5; // xmm0_4
  void (__thiscall *GetText_2)(vgui::TextEntry *, char *, int); // edx
  double v7; // st7
  bool (__thiscall *IsKeyDown)(vgui::IInput *, ButtonCode_t); // eax
  float v9; // xmm0_4
  CAttributeSlider *m_pSlider; // ecx
  CAttributeSlider *v11; // esi
  int v12; // eax
  char sz[64]; // [esp+20h] [ebp-40h] BYREF

  if ( (*((_BYTE *)this->m_pSlider + 656) & 5) == 0 )
  {
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT) )
    {
      v3 = (float)SLODWORD(delta) * 10.0;
    }
    else
    {
      v4 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL);
      v5 = (float)SLODWORD(delta);
      if ( v4 )
        v3 = v5 * 0.01;
      else
        v3 = v5 * 0.1;
    }
    GetText_2 = this->GetText_2;
    delta = v3;
    GetText_2(this, a2: sz, a3: 64);
    v7 = V_atof(str: sz);
    IsKeyDown = g_pVGuiInput->IsKeyDown;
    delta = v7 + delta;
    if ( IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT) )
    {
      v9 = 0.0;
      if ( delta >= 0.0 )
      {
        v9 = 1.0;
        if ( delta <= 1.0 )
          v9 = delta;
      }
      delta = v9;
    }
    V_snprintf(pDest: sz, maxLen: 64, pFormat: "%f", delta);
    this->SetText(this, a2: sz);
    m_pSlider = this->m_pSlider;
    if ( m_pSlider->m_Control.m_pValue[0] != delta )
      m_pSlider->m_Control.m_pValue[0] = delta;
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, int))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 256))(
      a1: g_pDataModel.u,
      a2: "Set Slider Value",
      a3: "Set Slider Value",
      a4: 9876);
    v11 = this->m_pSlider;
    v12 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                      + 72))(
            a1: g_pDataModel.u,
            a2: v11->m_hControl.m_handle);
    v11->m_pParent->StampValueIntoLogs_3(
      this: v11->m_pParent,
      a2: (CDmElement *)v12,
      a3: ANIM_CONTROL_VALUE,
      a4: &delta);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 260))(a1: g_pDataModel.u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00488250
// Name: public: virtual void CAttributeSlider::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnKeyCodeTyped(CAttributeSlider *this, ButtonCode_t code)
{
  if ( this->m_SliderMode == SLIDER_MODE_TEXT )
  {
    if ( code == KEY_ENTER )
    {
      CAttributeSlider::AcceptTextEntryValue(this);
    }
    else if ( code == KEY_ESCAPE )
    {
      CAttributeSlider::DiscardTextEntryValue(this);
    }
    else
    {
      vgui::EditablePanel::OnKeyCodeTyped(this, code);
    }
  }
  else
  {
    vgui::EditablePanel::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00488290
// Name: public: bool CAttributeSlider::IsDependent(class CAttributeSlider const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAttributeSlider::IsDependent(CAttributeSlider *this, const CAttributeSlider *pSlider)
{
  int m_Size; // edx
  int v3; // eax
  const CAttributeSlider **m_pMemory; // ecx

  m_Size = this->m_Dependenices.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
  {
LABEL_5:
    v3 = -1;
  }
  else
  {
    m_pMemory = this->m_Dependenices.m_Memory.m_pMemory;
    while ( *m_pMemory != pSlider )
    {
      ++v3;
      ++m_pMemory;
      if ( v3 >= m_Size )
        goto LABEL_5;
    }
  }
  return v3 != -1;
}

//------------------------------------------------------------------------------
// Address: 0x004883A0
// Name: public: virtual CAttributeSlider::~CAttributeSlider(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::~CAttributeSlider(CAttributeSlider *this)
{
  vgui::TextImage *m_pName; // ecx
  vgui::TextImage *v3; // ecx
  vgui::TextImage *v4; // ecx
  vgui::TextImage *v5; // ecx
  vgui::TextImage *v6; // ecx

  m_pName = this->m_pName;
  this->__vftable = (CAttributeSlider_vtbl *)&CAttributeSlider::`vftable';
  if ( m_pName != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))m_pName->dtr_IImage)(a1: m_pName, a2: 1);
  v3 = this->m_pValues[0];
  if ( v3 != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))v3->dtr_IImage)(a1: v3, a2: 1);
  v4 = this->m_pValues[1];
  if ( v4 != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))v4->dtr_IImage)(a1: v4, a2: 1);
  v5 = this->m_pValues[2];
  if ( v5 != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))v5->dtr_IImage)(a1: v5, a2: 1);
  v6 = this->m_pValues[3];
  if ( v6 != nullptr )
    ((void (__thiscall *)(vgui::TextImage *, int))v6->dtr_IImage)(a1: v6, a2: 1);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_Dependenices);
  if ( g_pDataModel.u.m_Id != 0 )
    CDmeElementRefHelper::Unref(this: &this->m_hControl, hElement: this->m_hControl.m_handle, handleType: HT_WEAK);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x00488440
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeSlider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeSlider::GetMessageMap(CAttributeSlider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeSlider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSlider::GetMessageMap'::`2'::s_pMap;
  `CAttributeSlider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeSlider");
  `CAttributeSlider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00488470
// Name: public: virtual struct PanelAnimationMap __near * CAttributeSlider::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeSlider::GetAnimMap(CAttributeSlider *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeSlider");
}

//------------------------------------------------------------------------------
// Address: 0x00488480
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeSlider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeSlider::GetKBMap(CAttributeSlider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeSlider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSlider::GetKBMap'::`2'::s_pMap;
  `CAttributeSlider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSlider");
  `CAttributeSlider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004884B0
// Name: public: void CAttributeSlider::InitControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::InitControls(CAttributeSlider *this)
{
  char v2; // al
  int v3; // eax
  CDmeTransformControl *v4; // edi
  const Quaternion *Orientation; // eax
  const Vector *Position; // eax
  int (__stdcall *v7)(DmElementHandle_t); // edx
  CDmElement *v8; // eax
  float m_Storage; // xmm0_4
  CDmElement *v10; // eax
  float v11; // xmm0_4
  CDmElement *v12; // eax
  float v13; // xmm0_4
  DmElementHandle_t m_handle; // [esp-4h] [ebp-Ch]

  v2 = *((_BYTE *)this + 656);
  if ( (v2 & 1) != 0 )
  {
    v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hControl.m_handle);
    v4 = (CDmeTransformControl *)v3;
    if ( v3 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
           a1: v3,
           a2: CDmeTransformControl::m_classType.u) != 0 )
    {
      if ( (*((_BYTE *)this + 656) & 2) != 0 )
      {
        Orientation = CDmeTransformControl::GetOrientation(this: v4);
        CAttributeSlider::SetValue(this, type: ANIM_CONTROL_TXFORM_ORIENTATION, quat: Orientation);
      }
      else
      {
        Position = CDmeTransformControl::GetPosition(this: v4);
        CAttributeSlider::SetValue(this, type: ANIM_CONTROL_COUNT, vec: Position);
      }
    }
  }
  else
  {
    v7 = *(int (__stdcall **)(DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72);
    m_handle = this->m_hControl.m_handle;
    if ( (v2 & 4) != 0 )
    {
      v8 = (CDmElement *)v7(a1: m_handle);
      m_Storage = CDmElement::GetValue<float>(this: v8, pAttributeName: "leftValue")->m_Storage;
      if ( this->m_Control.m_pValue[2] != m_Storage )
        this->m_Control.m_pValue[2] = m_Storage;
      v10 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                            a1: g_pDataModel.u,
                            a2: this->m_hControl.m_handle);
      v11 = CDmElement::GetValue<float>(this: v10, pAttributeName: "rightValue")->m_Storage;
      if ( this->m_Control.m_pValue[1] != v11 )
        this->m_Control.m_pValue[1] = v11;
    }
    else
    {
      v12 = (CDmElement *)v7(a1: m_handle);
      v13 = CDmElement::GetValue<float>(this: v12, pAttributeName: "value")->m_Storage;
      if ( this->m_Control.m_pValue[0] != v13 )
        this->m_Control.m_pValue[0] = v13;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004885D0
// Name: private: void CAttributeSlider::SetToDefault(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::SetToDefault(CAttributeSlider *this)
{
  char v2; // al
  CDmElement *v3; // eax
  CDmaVar<Quaternion> *v4; // edi
  int v5; // eax
  CDmElement *v6; // eax
  CDmaVar<Vector> *v7; // edi
  int v8; // eax
  CDmElement *v9; // eax
  CDmAttribute *Attribute; // eax
  CDmaVar<float> *v11; // eax
  bool v12; // zf
  float m_Storage; // xmm0_4
  DmElementHandle_t v14; // edx
  CDmElement *v15; // eax
  DmElementHandle_t v16; // eax
  int v17; // eax
  CBaseAnimSetAttributeSliderPanel *m_pParent; // ecx
  DmElementHandle_t m_handle; // eax
  int v20; // [esp+0h] [ebp-10h]
  int v21; // [esp+0h] [ebp-10h]
  int v22; // [esp+4h] [ebp-Ch]
  float *p_x; // [esp+4h] [ebp-Ch]
  float v24; // [esp+8h] [ebp-8h] BYREF
  float flDefaultValue; // [esp+Ch] [ebp-4h]

  v2 = *((_BYTE *)this + 656);
  if ( (v2 & 1) != 0 )
  {
    if ( (v2 & 2) != 0 )
    {
      v3 = (CDmElement *)(*(int (__stdcall **)(DmElementHandle_t, int, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                           a1: this->m_hControl.m_handle,
                           a2: v20,
                           a3: v22);
      v4 = CDmElement::GetValue<Quaternion>(this: v3, pAttributeName: "defaultOrientation");
      CAttributeSlider::SetValue(this, type: ANIM_CONTROL_TXFORM_ORIENTATION, quat: &v4->m_Storage);
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 256))(
        a1: g_pDataModel.u,
        a2: "Set Slider Value To Default",
        a3: "Set Slider Value To Default",
        a4: 0);
      v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_hControl.m_handle);
      p_x = &v4->m_Storage.x;
      v21 = 4;
      ((void (__stdcall *)(int))this->m_pParent->StampValueIntoLogs)(a1: v5);
    }
    else
    {
      v6 = (CDmElement *)(*(int (__stdcall **)(DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(a1: this->m_hControl.m_handle);
      v7 = CDmElement::GetValue<Vector>(this: v6, pAttributeName: "defaultPosition");
      if ( v7->m_Storage.x != this->m_Control.m_Vector.x
        || v7->m_Storage.y != this->m_Control.m_Vector.y
        || v7->m_Storage.z != this->m_Control.m_Vector.z )
      {
        this->m_Control.m_Vector.x = v7->m_Storage.x;
        this->m_Control.m_Vector.y = v7->m_Storage.y;
        this->m_Control.m_Vector.z = v7->m_Storage.z;
      }
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 256))(
        a1: g_pDataModel.u,
        a2: "Set Slider Value To Default",
        a3: "Set Slider Value To Default",
        a4: 0);
      v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_hControl.m_handle);
      p_x = &v7->m_Storage.x;
      v21 = 3;
      ((void (__stdcall *)(int))this->m_pParent->StampValueIntoLogs_2)(a1: v8);
    }
  }
  else
  {
    v9 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                         a1: g_pDataModel.u,
                         a2: this->m_hControl.m_handle);
    if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
    {
      `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
      `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
      `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
    }
    Attribute = CDmElement::FindAttribute(this: v9, pAttributeName: "defaultValue");
    if ( Attribute != nullptr )
      v11 = (CDmaVar<float> *)CDmAttribute::GetValue<float>(this: Attribute);
    else
      v11 = &`CDmElement::GetValue<float>'::`2'::defaultVal;
    v12 = (*((_BYTE *)this + 656) & 4) == 0;
    m_Storage = v11->m_Storage;
    flDefaultValue = v11->m_Storage;
    if ( v12 )
    {
      if ( this->m_Control.m_pValue[0] != m_Storage )
        this->m_Control.m_pValue[0] = m_Storage;
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 256))(
        a1: g_pDataModel.u,
        a2: "Set Slider Value To Default",
        a3: "Set Slider Value To Default",
        a4: 0);
      m_handle = this->m_hControl.m_handle;
      v24 = flDefaultValue;
      v17 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 72))(
              a1: g_pDataModel.u,
              a2: m_handle);
      m_pParent = this->m_pParent;
      p_x = &v24;
      v21 = 0;
    }
    else
    {
      if ( this->m_Control.m_pValue[2] != m_Storage )
        this->m_Control.m_pValue[2] = m_Storage;
      if ( this->m_Control.m_pValue[1] != m_Storage )
        this->m_Control.m_pValue[1] = m_Storage;
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 256))(
        a1: g_pDataModel.u,
        a2: "Set Slider Value To Default",
        a3: "Set Slider Value To Default",
        a4: 0);
      v14 = this->m_hControl.m_handle;
      v24 = flDefaultValue;
      v15 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                            a1: g_pDataModel.u,
                            a2: v14);
      this->m_pParent->StampValueIntoLogs_3(this: this->m_pParent, a2: v15, a3: ANIM_CONTROL_VALUE_LEFT, a4: &v24);
      v16 = this->m_hControl.m_handle;
      v24 = flDefaultValue;
      v17 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 72))(
              a1: g_pDataModel.u,
              a2: v16);
      m_pParent = this->m_pParent;
      p_x = &v24;
      v21 = 1;
    }
    ((void (__stdcall *)(int))m_pParent->StampValueIntoLogs_3)(a1: v17);
  }
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int, float *))(*(_DWORD *)g_pDataModel.u.m_Id + 260))(
    a1: g_pDataModel.u,
    a2: v21,
    a3: p_x);
}

//------------------------------------------------------------------------------
// Address: 0x004888B0
// Name: public: virtual void CAttributeSlider::OnSetToDefault(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CAttributeSlider::OnSetToDefault(CAttributeSlider *this)
{
  CAttributeSlider::SetToDefault(this);
}

//------------------------------------------------------------------------------
// Address: 0x004888C0
// Name: public: virtual void CAttributeSlider::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::PaintBackground(CAttributeSlider *this)
{
  int v1; // edi
  char *v2; // esi
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // eax
  void (__thiscall *v4)(vgui::ISurface *, Color); // eax
  int v5; // ebx
  CAttributeSlider *v6; // esi
  int v7; // ebx
  CBaseAnimationSetControl *v8; // eax
  int v9; // edi
  CBaseAnimationSetControl *v10; // eax
  vgui::IInput_vtbl *v11; // edx
  bool v12; // al
  bool v13; // zf
  bool IsPresetFaderBeingDragged; // al
  CDmElement *v15; // eax
  CDmaVar<float> *v16; // eax
  float v17; // xmm1_4
  float m_Storage; // xmm2_4
  float v19; // xmm0_4
  AttributeValue_t *p_m_PreviewCurrent; // eax
  float v21; // xmm2_4
  float v22; // xmm3_4
  Color v23; // edi
  CBaseAnimationSetControl *v24; // edi
  CBaseAnimationSetControl *v25; // edx
  bool v26; // cc
  int v27; // ebx
  Color v28; // edi
  CBaseAnimationSetControl *v29; // edx
  int rect_8a; // [esp+14h] [ebp-1Ch]
  int rect_8; // [esp+14h] [ebp-1Ch]
  int nLeftValuea; // [esp+1Ch] [ebp-14h]
  int nRightValue; // [esp+20h] [ebp-10h] BYREF
  CBaseAnimationSetControl *pController; // [esp+24h] [ebp-Ch] BYREF
  int v36; // [esp+28h] [ebp-8h]
  bool shiftDown; // [esp+2Fh] [ebp-1h]

  vgui::Panel::GetSize(this, wide: &nRightValue, tall: (int *)&pController);
  v1 = nRightValue - 12;
  v36 = -15198184;
  rect_8a = nRightValue - 12;
  v2 = (int)&pController[-1].m_crossfadePresetControlValues.m_Size + 2 < 0
     ? nullptr
     : (char *)((unsigned int)&pController[-1].m_crossfadePresetControlValues.m_Size + 2);
  ((void (__thiscall *)(vgui::ISurface *, int))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: -15198184);
  v1 += 6;
  g_pVGuiSurface->DrawOutlinedRect(this: g_pVGuiSurface, a2: 6, a3: 3, a4: v1, a5: 4);
  g_pVGuiSurface->DrawOutlinedRect(this: g_pVGuiSurface, a2: 6, a3: 3, a4: 7, a5: (int)(v2 + 3));
  DrawSetColor = g_pVGuiSurface->DrawSetColor;
  v36 = -14606047;
  ((void (__thiscall *)(vgui::ISurface *, int))DrawSetColor)(a1: g_pVGuiSurface, a2: -14606047);
  g_pVGuiSurface->DrawOutlinedRect(this: g_pVGuiSurface, a2: v1 - 1, a3: 3, a4: v1, a5: (int)(v2 + 3));
  v4 = g_pVGuiSurface->DrawSetColor;
  v36 = -13092808;
  ((void (__thiscall *)(vgui::ISurface *, int))v4)(a1: g_pVGuiSurface, a2: -13092808);
  g_pVGuiSurface->DrawOutlinedRect(this: g_pVGuiSurface, a2: 6, a3: (int)(v2 + 2), a4: v1, a5: (int)(v2 + 3));
  rect_8 = rect_8a - 2;
  v5 = (int)(v2 - 2) / 2;
  v36 = (int)(v2 + 2);
  v6 = this;
  v7 = v5 + 4;
  v8 = this->m_pParent->GetController(this: this->m_pParent);
  v9 = 4 * (vgui::PHandle::Get(this: &v8->m_ActiveAttributeSlider) == this);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)((char *)s_ZeroColor + v9));
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 7, a3: 4, a4: rect_8 + 7, a5: v36);
  if ( this->m_SliderMode != SLIDER_MODE_TEXT )
  {
    if ( (*((_BYTE *)this + 656) & 1) == 0 )
    {
      v10 = this->m_pParent->GetController(this: this->m_pParent);
      v11 = g_pVGuiInput->__vftable;
      pController = v10;
      if ( v11->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
        || (v12 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT), shiftDown = false, v12) )
      {
        shiftDown = true;
      }
      if ( vgui::PHandle::Get(this: &pController->m_ActiveAttributeSlider) != this
        || this->m_SliderMode == SLIDER_MODE_DRAG_VALUE
        || (v13 = !shiftDown, shiftDown = true, v13) )
      {
        shiftDown = false;
      }
      IsPresetFaderBeingDragged = CBaseAnimationSetControl::IsPresetFaderBeingDragged(this: pController);
      if ( shiftDown
        || IsPresetFaderBeingDragged
        || (v13 = (*((_BYTE *)pController + 104) & 2) == 0, shiftDown = false, !v13) )
      {
        shiftDown = true;
      }
      v15 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                            a1: g_pDataModel.u,
                            a2: this->m_hControl.m_handle);
      v16 = CDmElement::GetValue<float>(this: v15, pAttributeName: "defaultValue");
      v17 = 0.0;
      if ( v16->m_Storage >= 0.0 )
      {
        if ( v16->m_Storage <= 1.0 )
          m_Storage = v16->m_Storage;
        else
          m_Storage = 1.0;
      }
      else
      {
        m_Storage = 0.0;
      }
      v13 = (*((_BYTE *)this + 656) & 4) == 0;
      v19 = (float)rect_8;
      pController = (CBaseAnimationSetControl *)(int)(float)((float)((float)rect_8 * m_Storage) + 0.5);
      p_m_PreviewCurrent = &this->m_PreviewCurrent;
      if ( v13 )
      {
        if ( !shiftDown )
          p_m_PreviewCurrent = &this->m_Control;
        if ( p_m_PreviewCurrent->m_pValue[0] >= 0.0 )
        {
          if ( p_m_PreviewCurrent->m_pValue[0] <= 1.0 )
            v17 = p_m_PreviewCurrent->m_pValue[0];
          else
            v17 = 1.0;
        }
        v27 = (int)(float)((float)(v19 * v17) + 0.5);
        if ( this->m_SliderMode == SLIDER_MODE_DRAG_VALUE )
          v28 = s_DraggingBarColor;
        else
          v28 = *(Color *)((char *)s_BarColor + v9);
        ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: v28);
        v29 = (CBaseAnimationSetControl *)(int)(float)((float)(v19 * v17) + 0.5);
        if ( v27 > (int)pController || (v29 = pController, v27 >= (int)pController) )
          v27 = (int)pController;
        v7 = v27 + 7;
        g_pVGuiSurface->DrawFilledRect(
          this: g_pVGuiSurface,
          a2: v7,
          a3: 4,
          a4: (int)&v29->m_hFilmClip.m_handle + 3,
          a5: v36);
        v24 = pController;
      }
      else
      {
        if ( !shiftDown )
          p_m_PreviewCurrent = &this->m_Control;
        v21 = p_m_PreviewCurrent->m_pValue[2];
        v22 = p_m_PreviewCurrent->m_pValue[1];
        if ( v21 >= 0.0 )
        {
          if ( v21 > 1.0 )
            v21 = 1.0;
        }
        else
        {
          v21 = 0.0;
        }
        nLeftValuea = (int)(float)((float)(v19 * v21) + 0.5);
        if ( v22 >= 0.0 )
        {
          if ( v22 <= 1.0 )
            v17 = p_m_PreviewCurrent->m_pValue[1];
          else
            v17 = 1.0;
        }
        v13 = v6->m_SliderMode == SLIDER_MODE_DRAG_VALUE;
        nRightValue = (int)(float)((float)(v19 * v17) + 0.5);
        if ( v13 )
          v23 = s_DraggingBarColor;
        else
          v23 = *(Color *)((char *)s_BarColor + v9);
        ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: v23);
        v24 = pController;
        v25 = (CBaseAnimationSetControl *)(int)(float)((float)(v19 * v21) + 0.5);
        v26 = nLeftValuea < (int)pController;
        if ( nLeftValuea > (int)pController
          || (v25 = pController, pController = (CBaseAnimationSetControl *)(int)(float)((float)(v19 * v21) + 0.5), !v26) )
        {
          pController = v24;
        }
        g_pVGuiSurface->DrawFilledRect(
          this: g_pVGuiSurface,
          a2: (int)&pController->m_hFilmClip.m_handle + 3,
          a3: 4,
          a4: (int)&v25->m_hFilmClip.m_handle + 3,
          a5: v7);
        pController = (CBaseAnimationSetControl *)nRightValue;
        if ( nRightValue > (int)v24 || (pController = v24, nRightValue >= (int)v24) )
          nRightValue = (int)v24;
        g_pVGuiSurface->DrawFilledRect(
          this: g_pVGuiSurface,
          a2: nRightValue + 7,
          a3: v7,
          a4: (int)&pController->m_hFilmClip.m_handle + 3,
          a5: v36);
      }
      v9 = (int)&v24->m_hFilmClip.m_handle + 3;
      if ( (*((_BYTE *)v6 + 656) & 1) == 0 )
      {
        ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: s_MidpointColor);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: v9, a3: 4, a4: v9 + 1, a5: v36);
      }
    }
    CAttributeSlider::DrawNameLabel(this: v6, a2: v7, a3: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00488CD0
// Name: public: static void CAttributeSlider::KB_AddToMap(char const __near *,enum ButtonCode_t,int,void (vgui::Panel::*)(void),char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAttributeSlider::KB_AddToMap(
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
  v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSlider");
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
  CDmeFXClip::OnDestruction(this: (vgui::PropertyPage *)v8);
}

//------------------------------------------------------------------------------
// Address: 0x00488DA0
// Name: public: static void CAttributeSlider::PanelMessageFunc_OnSetToDefault::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeSlider::PanelMessageFunc_OnSetToDefault::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeSlider::PanelMessageFunc_OnSetToDefault::InitVar'::`2'::bAdded )
  {
    `CAttributeSlider::PanelMessageFunc_OnSetToDefault::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeSlider");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "SetToDefault";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00488E30
// Name: public: static void CAttributeSlider::PanelMessageFunc_OnEditMinMaxDefault::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeSlider::PanelMessageFunc_OnEditMinMaxDefault::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeSlider::PanelMessageFunc_OnEditMinMaxDefault::InitVar'::`2'::bAdded )
  {
    `CAttributeSlider::PanelMessageFunc_OnEditMinMaxDefault::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeSlider");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "EditMinMaxDefault";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00488EC0
// Name: public: static void CAttributeSlider::PanelMessageFunc_OnInputCompleted::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeSlider::PanelMessageFunc_OnInputCompleted::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeSlider::PanelMessageFunc_OnInputCompleted::InitVar'::`2'::bAdded )
  {
    `CAttributeSlider::PanelMessageFunc_OnInputCompleted::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeSlider");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "InputCompleted";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00488F50
// Name: public: static void CAttributeSliderTextEntry::PanelMessageFunc_OnKillFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeSliderTextEntry::PanelMessageFunc_OnKillFocus::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeSliderTextEntry::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded )
  {
    `CAttributeSliderTextEntry::PanelMessageFunc_OnKillFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeSliderTextEntry");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "KillFocus";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00489000
// Name: public: CAttributeSlider::CAttributeSlider(class CBaseAnimSetAttributeSliderPanel __near *)
// Source: json
//------------------------------------------------------------------------------
CAttributeSlider *__thiscall CAttributeSlider::CAttributeSlider(
        CAttributeSlider *this,
        CBaseAnimSetAttributeSliderPanel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::TextImage *v6; // eax
  vgui::TextImage *v7; // eax
  vgui::TextImage *v8; // eax
  vgui::TextImage *v9; // eax
  vgui::TextImage *v10; // eax
  vgui::TextImage *v11; // eax
  vgui::TextImage *v12; // eax
  vgui::TextImage *v13; // eax
  vgui::TextImage *v14; // eax
  vgui::TextImage *v15; // eax
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent, panelName: defaultValue);
  this->__vftable = (CAttributeSlider_vtbl *)&CAttributeSlider::`vftable';
  if ( `CAttributeSlider::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSlider::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CAttributeSlider");
    v3->pfnClassName = CAttributeSlider::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "EditablePanel");
  }
  if ( `CAttributeSlider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeSlider::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CAttributeSlider");
    v4->pfnClassName = CAttributeSlider::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "EditablePanel");
  }
  if ( `CAttributeSlider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSlider::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSlider");
    v5->pfnClassName = CAttributeSlider::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "EditablePanel");
  }
  CAttributeSlider::PanelMessageFunc_OnSetToDefault::InitVar(a1: (int)&savedregs);
  CAttributeSlider::PanelMessageFunc_OnEditMinMaxDefault::InitVar(a1: (int)&savedregs);
  CAttributeSlider::PanelMessageFunc_OnInputCompleted::InitVar(a1: (int)&savedregs);
  if ( `CAttributeSlider::PanelKBMapFunc_ts_curve_1::InitVar'::`2'::bAdded == 0 )
  {
    `CAttributeSlider::PanelKBMapFunc_ts_curve_1::InitVar'::`2'::bAdded = 1;
    CAttributeSlider::KB_AddToMap(
      a1: (const char *)&savedregs,
      bindingname: "ts_curve_1",
      defaultcode: KEY_1,
      default_modifiers: 0,
      function: (unsigned int) __thiscall CColorPickerPanel::`vcall'{956,{flat}},
      helpstring: (unsigned int)"#ts_curve1_help",
      passive: false);
  }
  if ( `CAttributeSlider::PanelKBMapFunc_ts_curve_2::InitVar'::`2'::bAdded == 0 )
  {
    `CAttributeSlider::PanelKBMapFunc_ts_curve_2::InitVar'::`2'::bAdded = 1;
    CAttributeSlider::KB_AddToMap(
      a1: (const char *)&savedregs,
      bindingname: "ts_curve_2",
      defaultcode: KEY_2,
      default_modifiers: 0,
      function: (unsigned int) __thiscall CDmePanel::`vcall'{960,{flat}},
      helpstring: (unsigned int)"#ts_curve2_help",
      passive: false);
  }
  if ( `CAttributeSlider::PanelKBMapFunc_ts_curve_3::InitVar'::`2'::bAdded == 0 )
  {
    `CAttributeSlider::PanelKBMapFunc_ts_curve_3::InitVar'::`2'::bAdded = 1;
    CAttributeSlider::KB_AddToMap(
      a1: (const char *)&savedregs,
      bindingname: "ts_curve_3",
      defaultcode: KEY_3,
      default_modifiers: 0,
      function: (unsigned int) __thiscall CAttributeSlider::`vcall'{964,{flat}},
      helpstring: (unsigned int)"#ts_curve3_help",
      passive: false);
  }
  if ( `CAttributeSlider::PanelKBMapFunc_ts_curve_4::InitVar'::`2'::bAdded == 0 )
  {
    `CAttributeSlider::PanelKBMapFunc_ts_curve_4::InitVar'::`2'::bAdded = 1;
    CAttributeSlider::KB_AddToMap(
      a1: (const char *)&savedregs,
      bindingname: "ts_curve_4",
      defaultcode: KEY_4,
      default_modifiers: 0,
      function: (unsigned int) __thiscall CAttributeSlider::`vcall'{968,{flat}},
      helpstring: (unsigned int)"#ts_curve4_help",
      passive: false);
  }
  this->m_pParent = parent;
  this->m_hControl.m_handle = DMELEMENT_HANDLE_INVALID;
  this->m_Control.m_pValue[0] = 0.0;
  this->m_Control.m_pValue[1] = 0.0;
  this->m_Control.m_pValue[2] = 0.0;
  this->m_Control.m_Vector.x = 0.0;
  this->m_Control.m_Vector.y = 0.0;
  this->m_Control.m_Vector.z = 0.0;
  this->m_Control.m_Quaternion = quat_identity;
  this->m_InitialTextEntryValue.m_pValue[0] = 0.0;
  this->m_InitialTextEntryValue.m_pValue[1] = 0.0;
  this->m_InitialTextEntryValue.m_pValue[2] = 0.0;
  this->m_InitialTextEntryValue.m_Vector.x = 0.0;
  this->m_InitialTextEntryValue.m_Vector.y = 0.0;
  this->m_InitialTextEntryValue.m_Vector.z = 0.0;
  this->m_InitialTextEntryValue.m_Quaternion = quat_identity;
  this->m_pTextField = nullptr;
  this->m_pRightTextField = nullptr;
  this->m_PreviewCurrent.m_pValue[0] = 0.0;
  this->m_PreviewCurrent.m_pValue[1] = 0.0;
  this->m_PreviewCurrent.m_pValue[2] = 0.0;
  this->m_PreviewCurrent.m_Vector.x = 0.0;
  this->m_PreviewCurrent.m_Vector.y = 0.0;
  this->m_PreviewCurrent.m_Vector.z = 0.0;
  this->m_PreviewCurrent.m_Quaternion = quat_identity;
  this->m_PreviewFull.m_pValue[0] = 0.0;
  this->m_PreviewFull.m_pValue[1] = 0.0;
  this->m_PreviewFull.m_pValue[2] = 0.0;
  this->m_PreviewFull.m_Vector.x = 0.0;
  this->m_PreviewFull.m_Vector.y = 0.0;
  this->m_PreviewFull.m_Vector.z = 0.0;
  this->m_PreviewFull.m_Quaternion = quat_identity;
  this->m_flFaderAmount = 1.0;
  this->m_dragStartValues.m_pValue[0] = 0.0;
  this->m_dragStartValues.m_pValue[1] = 0.0;
  this->m_dragStartValues.m_pValue[2] = 0.0;
  this->m_dragStartValues.m_Vector.x = 0.0;
  this->m_dragStartValues.m_Vector.y = 0.0;
  this->m_dragStartValues.m_Vector.z = 0.0;
  this->m_dragStartValues.m_Quaternion = quat_identity;
  *((_BYTE *)this + 656) &= ~8u;
  this->m_nVisibleComponents = LOG_COMPONENTS_ALL;
  this->m_Dependenices.m_Memory.m_pMemory = nullptr;
  this->m_Dependenices.m_Memory.m_nAllocationCount = 0;
  this->m_Dependenices.m_Memory.m_nGrowSize = 0;
  this->m_Dependenices.m_Size = 0;
  this->m_Dependenices.m_pElements = nullptr;
  this->m_hContextMenu.m_iPanelID = -1;
  vgui::Panel::SetPaintBackgroundEnabled(this, state: true);
  vgui::Panel::SetPaintBorderEnabled(this, state: false);
  CDmeTrackGroup::SetMaxTrackCount(this, color: (Color)-14013910);
  v6 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x80u);
  if ( v6 != nullptr )
    v7 = vgui::TextImage::TextImage(this: v6, text: defaultValue);
  else
    v7 = nullptr;
  this->m_pName = v7;
  v8 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x80u);
  if ( v8 != nullptr )
    v9 = vgui::TextImage::TextImage(this: v8, text: defaultValue);
  else
    v9 = nullptr;
  this->m_pValues[0] = v9;
  v10 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x80u);
  if ( v10 != nullptr )
    v11 = vgui::TextImage::TextImage(this: v10, text: defaultValue);
  else
    v11 = nullptr;
  this->m_pValues[1] = v11;
  v12 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x80u);
  if ( v12 != nullptr )
    v13 = vgui::TextImage::TextImage(this: v12, text: defaultValue);
  else
    v13 = nullptr;
  this->m_pValues[2] = v13;
  v14 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x80u);
  if ( v14 != nullptr )
    v15 = vgui::TextImage::TextImage(this: v14, text: defaultValue);
  else
    v15 = nullptr;
  this->m_pValues[3] = v15;
  vgui::Panel::SetSize(this, wide: 100, tall: 20);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00489520
// Name: public: void CAttributeSlider::Init(class CDmElement __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::Init(CAttributeSlider *this, CDmElement *control, bool bOrientation)
{
  const char *m_pAsString; // eax
  DmElementHandle_t BufferType; // eax
  bool HasAttribute; // al
  char v7; // al
  const char *v8; // ecx
  const char *v9; // eax
  const char *v10; // edi
  char *m_szBuf; // [esp-4h] [ebp-11Ch]
  CFmtStrN<256> v12; // [esp+Ch] [ebp-10Ch] BYREF

  m_pAsString = control->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  vgui::Panel::SetName(this, panelName: m_pAsString);
  this->m_SliderMode = SLIDER_MODE_NONE;
  BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)control);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hControl, h: BufferType);
  *((_BYTE *)this + 656) &= 0xFCu;
  if ( ((int (__thiscall *)(_DWORD, _DWORD))control->IsA)(
         a1: control,
         a2: (CUtlSymbolLarge)CDmeTransformControl::m_classType.u.m_Id) )
  {
    *((_BYTE *)this + 656) = *((_BYTE *)this + 656) ^ (*((_BYTE *)this + 656) ^ (2 * bOrientation)) & 2 | 1;
  }
  HasAttribute = CDmElement::HasAttribute(this: control, pAttributeName: "rightValue", type: AT_UNKNOWN);
  this->m_nDragStartPosition[1] = 0;
  this->m_nDragStartPosition[0] = 0;
  this->m_nAccum[1] = 0;
  this->m_nAccum[0] = 0;
  *((_BYTE *)this + 656) ^= (*((_BYTE *)this + 656) ^ (4 * HasAttribute)) & 4;
  this->m_dragStartValues.m_pValue[0] = this->m_Control.m_pValue[0];
  this->m_dragStartValues.m_pValue[1] = this->m_Control.m_pValue[1];
  this->m_dragStartValues.m_pValue[2] = this->m_Control.m_pValue[2];
  this->m_dragStartValues.m_Vector.x = this->m_Control.m_Vector.x;
  this->m_dragStartValues.m_Vector.y = this->m_Control.m_Vector.y;
  this->m_dragStartValues.m_Vector.z = this->m_Control.m_Vector.z;
  *(_QWORD *)&this->m_dragStartValues.m_Quaternion.x = *(_QWORD *)&this->m_Control.m_Quaternion.x;
  *(_QWORD *)&this->m_dragStartValues.m_Quaternion.z = *(_QWORD *)&this->m_Control.m_Quaternion.z;
  this->SetPaintBackgroundEnabled(this, a2: true);
  v7 = *((_BYTE *)this + 656);
  if ( (v7 & 1) != 0 )
  {
    v8 = "%s - rot";
    if ( (v7 & 2) == 0 )
      v8 = "%s - pos";
    v9 = control->m_Name.m_Storage.u.m_pAsString;
    if ( v9 == (const char *)-1 )
      v9 = defaultValue;
    m_szBuf = CFmtStrN<256>::CFmtStrN<256>(this: &v12, pszFormat: v8, v9)->m_szBuf;
    this->m_pName->SetText_2(this: this->m_pName, a2: m_szBuf);
  }
  else
  {
    v10 = control->m_Name.m_Storage.u.m_pAsString;
    if ( v10 == (const char *)-1 )
      v10 = defaultValue;
    this->m_pName->SetText_2(this: this->m_pName, a2: v10);
  }
  vgui::TextImage::ResizeImageToContent(this: this->m_pName);
  CAttributeSlider::InitControls(this);
}

//------------------------------------------------------------------------------
// Address: 0x004896C0
// Name: public: virtual void CAttributeSlider::OnEditMinMaxDefault(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnEditMinMaxDefault(CAttributeSlider *this)
{
  CDmElement *v2; // eax
  CDmeChannel *Value; // eax
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmElement *v6; // eax
  vgui::MultiInputDialog *v7; // eax
  vgui::MultiInputDialog *v8; // esi
  float flDefault; // [esp+18h] [ebp-Ch]
  float flMax; // [esp+1Ch] [ebp-8h]
  float flMin; // [esp+20h] [ebp-4h]

  v2 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_hControl.m_handle);
  Value = CDmElement::GetValueElement<CDmeChannel>(this: v2, pAttributeName: "channel");
  if ( Value != nullptr )
  {
    v4 = CDmeChannel::GetToElement(this: Value);
    v5 = v4;
    if ( v4 != nullptr
      && v4->IsA(this: v4, a2: CDmeExpressionOperator::m_classType)
      && v5 != (CDmElement *)4
      && (*((_BYTE *)this + 656) & 4) == 0 )
    {
      flMin = CDmElement::GetValue<float>(this: v5, pAttributeName: "lo")->m_Storage;
      flMax = CDmElement::GetValue<float>(this: v5, pAttributeName: "hi")->m_Storage;
      v6 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                           a1: g_pDataModel.u,
                           a2: this->m_hControl.m_handle);
      flDefault = (float)((float)(flMax - flMin)
                        * CDmElement::GetValue<float>(this: v6, pAttributeName: "defaultValue")->m_Storage)
                + flMin;
      v7 = (vgui::MultiInputDialog *)MemAlloc_Alloc(nSize: 0x264u);
      if ( v7 != nullptr )
        v8 = vgui::MultiInputDialog::MultiInputDialog(
               this: v7,
               pParent: this,
               pTitle: "Edit Min/Max/Default",
               pOKText: "#VGui_OK",
               pCancelText: "#VGui_Cancel");
      else
        v8 = nullptr;
      vgui::MultiInputDialog::AddEntry(this: v8, pName: "min", pPrompt: "Min:", flDefaultValue: flMin);
      vgui::MultiInputDialog::AddEntry(this: v8, pName: "max", pPrompt: "Max:", flDefaultValue: flMax);
      vgui::MultiInputDialog::AddEntry(this: v8, pName: "default", pPrompt: "Default:", flDefaultValue: flDefault);
      v8->DoModal(this: v8);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00489830
// Name: public: virtual void CAttributeSlider::OnInputCompleted(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnInputCompleted(CAttributeSlider *this, float params)
{
  CDmElement *v3; // eax
  CDmeChannel *Value; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  char *v7; // esi
  CBaseAnimationSetControl *v8; // eax
  CDmElement *v9; // esi
  CDmaVar<float> *v10; // eax
  int (__thiscall *v11)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t); // edx
  CDmElement *v12; // eax
  CDmaVar<float> *v13; // eax
  KeyValues *v14; // edi
  float v15; // xmm2_4
  void (__thiscall *v16)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD); // edx
  CDmAttribute *Attribute; // eax
  CDmAttribute *v18; // eax
  CDmElement *v19; // esi
  CDmAttribute *v20; // eax
  CDmElement *v21; // esi
  CDmAttribute *v22; // eax
  DmElementHandle_t defaultValue; // [esp+24h] [ebp-28h]
  CDmeChannel *pChannel; // [esp+34h] [ebp-18h]
  float flOldMin; // [esp+3Ch] [ebp-10h]
  float flMin; // [esp+40h] [ebp-Ch] BYREF
  float flMax; // [esp+44h] [ebp-8h] BYREF
  float flOldMax; // [esp+48h] [ebp-4h]

  v3 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_hControl.m_handle);
  Value = CDmElement::GetValueElement<CDmeChannel>(this: v3, pAttributeName: "channel");
  pChannel = Value;
  if ( Value != nullptr )
  {
    v5 = CDmeChannel::GetToElement(this: Value);
    v6 = v5;
    if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeExpressionOperator::m_classType) )
    {
      v7 = (char *)&v6[-1] + 64;
      if ( v7 != nullptr )
      {
        v8 = this->m_pParent->GetController(this: this->m_pParent);
        v8->OnSliderRangeRemapped(this: v8);
        v9 = (CDmElement *)(v7 + 4);
        flOldMin = CDmElement::GetValue<float>(this: v9, pAttributeName: "lo")->m_Storage;
        v10 = CDmElement::GetValue<float>(this: v9, pAttributeName: "hi");
        v11 = *(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72);
        defaultValue = this->m_hControl.m_handle;
        flOldMax = v10->m_Storage;
        v12 = (CDmElement *)((int (__thiscall *)(_DWORD, _DWORD))v11)(
                              a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
                              a2: defaultValue);
        v13 = CDmElement::GetValue<float>(this: v12, pAttributeName: "value");
        v14 = (KeyValues *)LODWORD(params);
        v15 = flOldMax - flOldMin;
        flOldMax = (float)(v13->m_Storage * (float)(flOldMax - flOldMin)) + flOldMin;
        flMin = KeyValues::GetFloat(this: (KeyValues *)LODWORD(params), keyName: "min", defaultValue: 0.0);
        flMax = KeyValues::GetFloat(this: v14, keyName: "max", defaultValue: 0.0);
        params = KeyValues::GetFloat(this: v14, keyName: "default", defaultValue: 0.0);
        v16 = *(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 256);
        params = (float)(params - flMin) / (float)(flMax - flMin);
        flOldMax = (float)(flOldMax - flMin) / (float)(flMax - flMin);
        ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD))v16)(
          a1: (CUtlSymbolLarge::<unnamed_type_u>)g_pDataModel.u.m_Id,
          a2: "Set Control Min/Max/Default",
          a3: "Set Control Min/Max/Default",
          a4: 0);
        Attribute = CDmElement::FindAttribute(this: v9, pAttributeName: "lo");
        if ( Attribute != nullptr
          || (Attribute = CDmElement::CreateAttribute(this: v9, pAttributeName: "lo", type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: Attribute, value: &flMin);
        }
        v18 = CDmElement::FindAttribute(this: v9, pAttributeName: "hi");
        if ( v18 != nullptr
          || (v18 = CDmElement::CreateAttribute(this: v9, pAttributeName: "hi", type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v18, value: &flMax);
        }
        if ( params >= 0.0 )
        {
          if ( params > 1.0 )
            params = 1.0;
        }
        else
        {
          params = 0.0;
        }
        v19 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                              a1: g_pDataModel.u,
                              a2: this->m_hControl.m_handle);
        v20 = CDmElement::FindAttribute(this: v19, pAttributeName: "defaultValue");
        if ( v20 != nullptr
          || (v20 = CDmElement::CreateAttribute(this: v19, pAttributeName: "defaultValue", type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v20, value: &params);
        }
        if ( flOldMax >= 0.0 )
        {
          if ( flOldMax <= 1.0 )
            params = flOldMax;
          else
            params = 1.0;
        }
        else
        {
          params = 0.0;
        }
        v21 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                              a1: g_pDataModel.u,
                              a2: this->m_hControl.m_handle);
        v22 = CDmElement::FindAttribute(this: v21, pAttributeName: "value");
        if ( v22 != nullptr
          || (v22 = CDmElement::CreateAttribute(this: v21, pAttributeName: "value", type: AT_FLOAT)) != nullptr )
        {
          CDmAttribute::SetValue<float>(this: v22, value: &params);
        }
        RemapFloatLogValues(
          pChannel,
          flBias: (float)(flOldMin - flMin) / (float)(flMax - flMin),
          flScale: v15 / (float)(flMax - flMin));
        (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)g_pDataModel.u.m_Id + 260))(a1: g_pDataModel.u);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00489B50
// Name: public: virtual void CAttributeSlider::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAttributeSlider::OnMouseReleased(CAttributeSlider *this@<ecx>, int a2@<ebx>, int a3@<edi>, int code)
{
  vgui::Panel *v5; // eax
  vgui::Menu *v6; // eax
  vgui::Menu *v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // ebx
  vgui::Panel *v10; // eax
  CDmElement *v11; // eax
  CDmeChannel *Value; // eax
  CDmElement *v13; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // ebx
  vgui::Panel *v16; // eax
  vgui::Menu *v17; // eax
  int x; // [esp+4h] [ebp-4h] BYREF

  if ( this->IsEnabled(this) && (*((_BYTE *)this + 656) & 1) == 0 )
  {
    if ( code == 108 )
    {
      if ( vgui::PHandle::Get(this: &this->m_hContextMenu) != nullptr )
      {
        v5 = vgui::PHandle::Get(this: &this->m_hContextMenu);
        if ( v5 != nullptr )
          ((void (__thiscall *)(vgui::Panel *, int))v5->dtr_Panel)(a1: v5, a2: 1);
        vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: nullptr);
      }
      v6 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
      if ( v6 != nullptr )
        v7 = vgui::Menu::Menu(this: v6, parent: this, panelName: "ActionMenu");
      else
        v7 = nullptr;
      vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hContextMenu, pPanel: v7);
      ((void (__thiscall *)(vgui::IInput *, int *, int *, int, int))g_pVGuiInput->GetCursorPosition)(
        a1: g_pVGuiInput,
        a2: &x,
        a3: &code,
        a4: a3,
        a5: a2);
      vgui::Panel::ScreenToLocal(this, &x, y: &code);
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "SetToDefault");
      else
        v9 = nullptr;
      v10 = vgui::PHandle::Get(this: &this->m_hContextMenu);
      v10->__vftable[1].PaintTraverse(this: v10, a2: (bool)"Set To Default", a3: (bool)v9);
      v11 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                            a1: g_pDataModel.u,
                            a2: this->m_hControl.m_handle);
      Value = CDmElement::GetValueElement<CDmeChannel>(this: v11, pAttributeName: "channel");
      if ( Value != nullptr )
      {
        v13 = CDmeChannel::GetToElement(this: Value);
        if ( v13 != nullptr && CDmElement::IsA<CDmeExpressionOperator>(this: v13) )
        {
          v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v14 != nullptr )
            v15 = KeyValues::KeyValues(this: v14, setName: "EditMinMaxDefault");
          else
            v15 = nullptr;
          v16 = vgui::PHandle::Get(this: &this->m_hContextMenu);
          ((void (__thiscall *)(vgui::Panel *, const char *, KeyValues *, CAttributeSlider *, _DWORD))v16->__vftable[1].PaintTraverse)(
            a1: v16,
            a2: "Edit Min/Max/Default...",
            a3: v15,
            a4: this,
            a5: 0);
        }
      }
      v17 = (vgui::Menu *)vgui::PHandle::Get(this: &this->m_hContextMenu);
      vgui::Menu::PlaceContextMenu(parent: this, menu: v17);
    }
    else if ( this->m_SliderMode == SLIDER_MODE_DRAG_VALUE )
    {
      this->m_SliderMode = SLIDER_MODE_NONE;
      g_pVGuiInput->SetMouseCapture(this: g_pVGuiInput, a2: 0);
      this->SetCursor(this, a2: 2u);
      this->m_pParent->UpdatePreview(this: this->m_pParent, a2: "Attribute Slider Released");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00489D40
// Name: public: CAttributeSliderTextEntry::CAttributeSliderTextEntry(class CAttributeSlider __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CAttributeSliderTextEntry *__thiscall CAttributeSliderTextEntry::CAttributeSliderTextEntry(
        CAttributeSliderTextEntry *this,
        CAttributeSlider *slider,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::TextEntry::TextEntry(this, parent: slider, panelName);
  this->__vftable = (CAttributeSliderTextEntry_vtbl *)&CAttributeSliderTextEntry::`vftable';
  if ( `CAttributeSliderTextEntry::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSliderTextEntry::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeSliderTextEntry");
    v4->pfnClassName = CAttributeSliderTextEntry::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  }
  if ( `CAttributeSliderTextEntry::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeSliderTextEntry::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeSliderTextEntry");
    v5->pfnClassName = CAttributeSliderTextEntry::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "TextEntry");
  }
  if ( `CAttributeSliderTextEntry::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSliderTextEntry::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSliderTextEntry");
    v6->pfnClassName = CAttributeSliderTextEntry::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  }
  CAttributeSliderTextEntry::PanelMessageFunc_OnKillFocus::InitVar(a1: (int)&savedregs);
  this->m_pSlider = slider;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00489E10
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeSliderTextEntry::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeSliderTextEntry::GetMessageMap(CAttributeSliderTextEntry *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeSliderTextEntry::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSliderTextEntry::GetMessageMap'::`2'::s_pMap;
  `CAttributeSliderTextEntry::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeSliderTextEntry");
  `CAttributeSliderTextEntry::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00489E40
// Name: public: virtual struct PanelAnimationMap __near * CAttributeSliderTextEntry::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeSliderTextEntry::GetAnimMap(CAttributeSliderTextEntry *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeSliderTextEntry");
}

//------------------------------------------------------------------------------
// Address: 0x00489E50
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeSliderTextEntry::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeSliderTextEntry::GetKBMap(CAttributeSliderTextEntry *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeSliderTextEntry::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSliderTextEntry::GetKBMap'::`2'::s_pMap;
  `CAttributeSliderTextEntry::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSliderTextEntry");
  `CAttributeSliderTextEntry::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00489E80
// Name: private: void CAttributeSlider::SetupTextFieldForTextEntryMode(class CAttributeSliderTextEntry __near * __near &,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::SetupTextFieldForTextEntryMode(
        CAttributeSlider *this,
        vgui::Panel **pTextField,
        const char *pText,
        bool bRequestFocus)
{
  CAttributeSliderTextEntry *v5; // ebx
  const char *v6; // eax
  CAttributeSliderTextEntry *v7; // eax

  if ( *pTextField == nullptr )
  {
    v5 = (CAttributeSliderTextEntry *)MemAlloc_Alloc(nSize: 0x444u);
    if ( v5 != nullptr )
    {
      v6 = this->GetName(this);
      v7 = CAttributeSliderTextEntry::CAttributeSliderTextEntry(this: v5, slider: this, panelName: v6);
    }
    else
    {
      v7 = nullptr;
    }
    *pTextField = v7;
    v7->SetVisible(this: v7, a2: false);
    (*pTextField)->SetEnabled(this: *pTextField, a2: false);
    vgui::TextEntry::SelectAllOnFocusAlways(this: (vgui::TextEntry *)*pTextField, status: true);
    this->InvalidateLayout(this, a2: false, a3: false);
  }
  (*pTextField)->SetVisible(this: *pTextField, a2: true);
  (*pTextField)->SetEnabled(this: *pTextField, a2: true);
  ((void (__thiscall *)(vgui::Panel *, const char *))(*pTextField)->__vftable[1].GetVPanel)(a1: *pTextField, a2: pText);
  ((void (__thiscall *)(vgui::Panel *))(*pTextField)->__vftable[1].OnMessage)(a1: *pTextField);
  if ( bRequestFocus )
    (*pTextField)->RequestFocus(this: *pTextField, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00489F40
// Name: private: void CAttributeSlider::EnterTextEntryMode(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::EnterTextEntryMode(CAttributeSlider *this, bool bRelatchValues)
{
  char v3; // al
  char *v4; // edx
  char pDest[64]; // [esp+1Ch] [ebp-80h] BYREF
  char val[64]; // [esp+5Ch] [ebp-40h] BYREF

  this->m_SliderMode = SLIDER_MODE_TEXT;
  if ( !bRelatchValues )
    CAttributeSlider::SetValue(this, value: &this->m_InitialTextEntryValue);
  v3 = *((_BYTE *)this + 656);
  if ( (v3 & 1) != 0 )
  {
    V_snprintf(
      pDest,
      maxLen: 128,
      pFormat: "%f %f %f",
      this->m_InitialTextEntryValue.m_Vector.x,
      this->m_InitialTextEntryValue.m_Vector.y,
      this->m_InitialTextEntryValue.m_Vector.z);
    v4 = pDest;
  }
  else
  {
    if ( (v3 & 4) != 0 )
    {
      V_snprintf(pDest: val, maxLen: 64, pFormat: "%f", this->m_InitialTextEntryValue.m_pValue[2]);
      CAttributeSlider::SetupTextFieldForTextEntryMode(
        this,
        pTextField: &this->m_pTextField,
        pText: val,
        bRequestFocus: true);
      V_snprintf(pDest: val, maxLen: 64, pFormat: "%f", this->m_InitialTextEntryValue.m_pValue[1]);
      CAttributeSlider::SetupTextFieldForTextEntryMode(
        this,
        pTextField: &this->m_pRightTextField,
        pText: val,
        bRequestFocus: false);
      return;
    }
    V_snprintf(pDest: val, maxLen: 64, pFormat: "%f", this->m_InitialTextEntryValue.m_pValue[0]);
    v4 = val;
  }
  CAttributeSlider::SetupTextFieldForTextEntryMode(
    this,
    pTextField: &this->m_pTextField,
    pText: v4,
    bRequestFocus: true);
}

//------------------------------------------------------------------------------
// Address: 0x0048A080
// Name: public: virtual void CAttributeSlider::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSlider::OnMouseDoublePressed(CAttributeSlider *this, ButtonCode_t code)
{
  int x; // [esp+4h] [ebp-8h] BYREF
  int y; // [esp+8h] [ebp-4h] BYREF

  if ( this->IsEnabled(this) && this->m_SliderMode != SLIDER_MODE_DRAG_VALUE && code == KEY_COUNT )
  {
    g_pVGuiInput->GetCursorPosition(this: g_pVGuiInput, a2: &x, a3: &y);
    vgui::Panel::ScreenToLocal(this, &x, &y);
    CAttributeSlider::EnterTextEntryMode(this, bRelatchValues: false);
  }
}

} // namespace sceneviewer
