// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/game_controls/typedlog.cpp
// Functions: 17
// ============================================================

#include "vgui2\game_controls\typedlog.h"

//------------------------------------------------------------------------------
// Address: 0x00426D70
// Name: public: void CTypedLog<float>::GetValue(class DmeTime_t,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTypedLog<float>::GetValue(CTypedLog<float> *this, DmeTime_t time, float *pOutValue)
{
  int m_tms; // edi
  int ValueForTime; // eax
  float v6; // xmm0_4
  float v7; // xmm1_4

  if ( this->m_UseDefaultValue )
  {
    *pOutValue = this->m_DefaultValue;
  }
  else if ( this->m_values.m_Size != 0 )
  {
    CTypedLog<color32_s>::AdjustTimeByLogAttributes((CTypedLog<CUtlString> *)this, &time);
    m_tms = time.m_tms;
    ValueForTime = CTypedLog<CUtlString>::GetValueForTime((CTypedLog<CUtlString> *)this, time);
    if ( ValueForTime != 0 )
    {
      v6 = this->m_values.m_Memory.m_pMemory[ValueForTime - 1];
      v7 = (double)(m_tms - this->m_times.m_Memory.m_pMemory[ValueForTime - 1].m_tms)
         / (double)(this->m_times.m_Memory.m_pMemory[ValueForTime].m_tms
                  - this->m_times.m_Memory.m_pMemory[ValueForTime - 1].m_tms);
      *pOutValue = (float)(v7 * (float)(this->m_values.m_Memory.m_pMemory[ValueForTime] - v6)) + v6;
    }
    else
    {
      *pOutValue = *this->m_values.m_Memory.m_pMemory;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427320
// Name: private: bool CTypedLog<float>::UnSerializeValues(class CDmxAttribute __near *,class CDmxAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTypedLog<float>::UnSerializeValues(
        CTypedLog<float> *this,
        const CUtlVector<float,CUtlMemory<float,int> > *pLogValues,
        CDmxAttribute *pLogTimes)
{
  int v4; // eax
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *p_m_times; // esi
  int v6; // ebp
  float *v7; // ebx
  int m_nAllocationCount; // eax
  float *m_pMemory; // ecx
  int v10; // eax
  bool v11; // zf
  float *v12; // ebp
  int v13; // ebp
  DmeTime_t *v14; // ebx
  int v15; // eax
  DmeTime_t *v16; // ecx
  int v17; // eax
  DmeTime_t *v18; // ebp
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *nCount; // [esp+8h] [ebp-8h]
  int m_Size; // [esp+Ch] [ebp-4h]
  const CUtlVector<float,CUtlMemory<float,int> > *logvalues; // [esp+14h] [ebp+4h]
  int i; // [esp+18h] [ebp+8h]

  if ( pLogValues->m_Memory.m_pMemory == (float *)17 )
  {
    logvalues = (const CUtlVector<float,CUtlMemory<float,int> > *)pLogValues->m_Memory.m_nGrowSize;
  }
  else
  {
    if ( (`CDmxAttribute::GetArray<float>'::`4'::`local static guard' & 1) == 0 )
    {
      `CDmxAttribute::GetArray<float>'::`4'::`local static guard' |= 1u;
      `CDmxAttribute::GetArray<float>'::`4'::defaultArray.m_Memory.m_pMemory = nullptr;
      `CDmxAttribute::GetArray<float>'::`4'::defaultArray.m_Memory.m_nAllocationCount = 0;
      `CDmxAttribute::GetArray<float>'::`4'::defaultArray.m_Memory.m_nGrowSize = 0;
      `CDmxAttribute::GetArray<float>'::`4'::defaultArray.m_Size = 0;
      `CDmxAttribute::GetArray<float>'::`4'::defaultArray.m_pElements = nullptr;
      atexit(func: `CDmxAttribute::GetArray<float>'::`4'::`dynamic atexit destructor for 'defaultArray'');
    }
    logvalues = &`CDmxAttribute::GetArray<float>'::`4'::defaultArray;
  }
  if ( pLogTimes->m_Type == AT_TIME_ARRAY )
  {
    nCount = (CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)pLogTimes->m_pData;
  }
  else
  {
    if ( (`CDmxAttribute::GetArray<DmeTime_t>'::`4'::`local static guard' & 1) == 0 )
    {
      `CDmxAttribute::GetArray<DmeTime_t>'::`4'::`local static guard' |= 1u;
      `CDmxAttribute::GetArray<DmeTime_t>'::`4'::defaultArray.m_Memory.m_pMemory = nullptr;
      `CDmxAttribute::GetArray<DmeTime_t>'::`4'::defaultArray.m_Memory.m_nAllocationCount = 0;
      `CDmxAttribute::GetArray<DmeTime_t>'::`4'::defaultArray.m_Memory.m_nGrowSize = 0;
      `CDmxAttribute::GetArray<DmeTime_t>'::`4'::defaultArray.m_Size = 0;
      `CDmxAttribute::GetArray<DmeTime_t>'::`4'::defaultArray.m_pElements = nullptr;
      atexit(func: `CDmxAttribute::GetArray<DmeTime_t>'::`4'::`dynamic atexit destructor for 'defaultArray'');
    }
    nCount = &`CDmxAttribute::GetArray<DmeTime_t>'::`4'::defaultArray;
  }
  v4 = 0;
  m_Size = logvalues->m_Size;
  i = 0;
  if ( m_Size > 0 )
  {
    p_m_times = &this->m_times;
    do
    {
      v6 = this->m_values.m_Size;
      v7 = &logvalues->m_Memory.m_pMemory[v4];
      m_nAllocationCount = this->m_values.m_Memory.m_nAllocationCount;
      if ( v6 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: v6 - m_nAllocationCount + 1);
      ++this->m_values.m_Size;
      m_pMemory = this->m_values.m_Memory.m_pMemory;
      v10 = this->m_values.m_Size - v6 - 1;
      v11 = this->m_values.m_Size - v6 == 1;
      this->m_values.m_pElements = this->m_values.m_Memory.m_pMemory;
      if ( v10 >= 0 && !v11 )
        _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * v10);
      v12 = &this->m_values.m_Memory.m_pMemory[v6];
      if ( v12 != nullptr )
        *v12 = *v7;
      v13 = this->m_times.m_Size;
      v14 = &nCount->m_Memory.m_pMemory[i];
      v15 = this->m_times.m_Memory.m_nAllocationCount;
      if ( v13 + 1 > v15 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&this->m_times, num: v13 - v15 + 1);
      ++this->m_times.m_Size;
      v16 = p_m_times->m_Memory.m_pMemory;
      v17 = this->m_times.m_Size - v13 - 1;
      v11 = this->m_times.m_Size - v13 == 1;
      this->m_times.m_pElements = this->m_times.m_Memory.m_pMemory;
      if ( v17 >= 0 && !v11 )
        _V_memmove(dest: &v16[v13 + 1], src: &v16[v13], count: 4 * v17);
      v18 = &p_m_times->m_Memory.m_pMemory[v13];
      if ( v18 != nullptr )
        v18->m_tms = v14->m_tms;
      v4 = ++i;
    }
    while ( i < m_Size );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00427650
// Name: public: bool CTypedLog<float>::Unserialize(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTypedLog<float>::Unserialize(CTypedLog<float> *this, CDmxElement *pElement)
{
  const CDmxAttribute *Attribute; // eax
  int *m_pData; // eax
  const CDmxAttribute *v5; // eax
  char *v6; // eax
  const CDmxAttribute *v7; // eax
  char *v8; // eax
  const CDmxAttribute *v9; // eax
  int *v10; // eax
  const CDmxAttribute *v11; // eax
  const CUtlVector<float,CUtlMemory<float,int> > *v12; // esi
  const CDmxAttribute *v14; // eax
  CDmxAttribute *v15; // ebp

  Attribute = CDmxElement::GetAttribute(this: pElement, pAttributeName: "animationrate");
  if ( Attribute != nullptr )
  {
    if ( Attribute->m_Type == AT_FLOAT )
    {
      m_pData = (int *)Attribute->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
      m_pData = &`CDmxAttribute::GetValue<float>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
    m_pData = &`CDmxElement::GetValue<float>'::`4'::defaultValue;
  }
  this->m_fAnimationRateMultiplier = *(float *)m_pData;
  v5 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "loop");
  if ( v5 != nullptr )
  {
    if ( v5->m_Type == AT_BOOL )
    {
      v6 = (char *)v5->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<bool>'::`4'::defaultValue = 0;
      v6 = &`CDmxAttribute::GetValue<bool>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<bool>'::`4'::defaultValue = 0;
    v6 = &`CDmxElement::GetValue<bool>'::`4'::defaultValue;
  }
  this->m_bLoop = *v6;
  v7 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "usedefault");
  if ( v7 != nullptr )
  {
    if ( v7->m_Type == AT_BOOL )
    {
      v8 = (char *)v7->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<bool>'::`4'::defaultValue = 0;
      v8 = &`CDmxAttribute::GetValue<bool>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<bool>'::`4'::defaultValue = 0;
    v8 = &`CDmxElement::GetValue<bool>'::`4'::defaultValue;
  }
  this->m_UseDefaultValue = *v8;
  v9 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "defaultvalue");
  if ( v9 != nullptr )
  {
    if ( v9->m_Type == AT_FLOAT )
    {
      v10 = (int *)v9->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
      v10 = &`CDmxAttribute::GetValue<float>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
    v10 = &`CDmxElement::GetValue<float>'::`4'::defaultValue;
  }
  this->m_DefaultValue = *(float *)v10;
  v11 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "logvalues");
  v12 = (const CUtlVector<float,CUtlMemory<float,int> > *)v11;
  if ( v11 == nullptr || v11->m_Type != AT_FLOAT_ARRAY )
    return 1;
  v14 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "logtimes");
  v15 = (CDmxAttribute *)v14;
  if ( v14 == nullptr || v14->m_Type != AT_TIME_ARRAY )
    return 0;
  if ( this->m_UseDefaultValue )
    _Warning(a1: "Warning: Possible unintended behavior: CTypedLog is set to use a default value when there are log entries.\n");
  return CTypedLog<float>::UnSerializeValues(this, pLogValues: v12, pLogTimes: v15);
}

//------------------------------------------------------------------------------
// Address: 0x0046A740
// Name: public: virtual class Color vgui::Button::GetButtonFgColor(void)
// Source: json
//------------------------------------------------------------------------------
Color *__userpurge vgui::Button::GetButtonFgColor@<eax>(vgui::Button *this@<ecx>, __m128i a2@<xmm0>, Color *result)
{
  Color *v4; // eax
  double v5; // xmm0_8
  float v6; // xmm0_4
  Color depressedFgColor; // [esp+4h] [ebp-4h]

  if ( (this->_buttonFlags.m_nFlags & 0x200) != 0 )
  {
    if ( (this->_buttonFlags.m_nFlags & 2) != 0 )
    {
      depressedFgColor = this->_depressedFgColor;
    }
    else if ( (this->_buttonFlags.m_nFlags & 1) != 0 )
    {
      depressedFgColor = this->_armedFgColor;
    }
    else
    {
      depressedFgColor = this->_defaultFgColor;
    }
    *(double *)a2.m128i_i64 = (float)((float)g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) * 0.0099999998);
    __libm_sse2_sin(X: a2);
    *(float *)&v5 = v5;
    v6 = (float)(*(float *)&v5 + 1.0) * 0.5;
    if ( (this->_buttonFlags.m_nFlags & 0x200) != 0 )
    {
      depressedFgColor._color[0] = (int)(float)((float)((float)this->_blinkFgColor._color[0] * (float)(1.0 - v6))
                                              + (float)((float)depressedFgColor._color[0] * v6));
      depressedFgColor._color[1] = (int)(float)((float)((float)this->_blinkFgColor._color[1] * (float)(1.0 - v6))
                                              + (float)((float)depressedFgColor._color[1] * v6));
      depressedFgColor._color[2] = (int)(float)((float)((float)this->_blinkFgColor._color[2] * (float)(1.0 - v6))
                                              + (float)((float)depressedFgColor._color[2] * v6));
      depressedFgColor._color[3] = (int)(float)((float)((float)this->_blinkFgColor._color[3] * (float)(1.0 - v6))
                                              + (float)((float)depressedFgColor._color[3] * v6));
    }
    *result = depressedFgColor;
    return result;
  }
  else
  {
    v4 = result;
    if ( (this->_buttonFlags.m_nFlags & 2) != 0 )
    {
      *result = this->_depressedFgColor;
    }
    else if ( (this->_buttonFlags.m_nFlags & 1) != 0 )
    {
      *result = this->_armedFgColor;
    }
    else
    {
      *result = this->_defaultFgColor;
    }
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0046A8C0
// Name: public: virtual class Color vgui::Button::GetButtonBgColor(void)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall vgui::Button::GetButtonBgColor(vgui::Button *this, Color *result)
{
  Color *v2; // eax

  if ( (this->_buttonFlags.m_nFlags & 2) != 0 )
  {
    *result = this->_depressedBgColor;
    return result;
  }
  else
  {
    v2 = result;
    if ( (this->_buttonFlags.m_nFlags & 1) != 0 )
      *result = this->_armedBgColor;
    else
      *result = this->_defaultBgColor;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0046CBB0
// Name: public: virtual class Color vgui::ImagePanel::GetDrawColor(void)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall vgui::ImagePanel::GetDrawColor(vgui::ImagePanel *this, Color *result)
{
  *result = this->m_DrawColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046DC50
// Name: public: virtual class Color vgui::Label::GetFgColor(void)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall vgui::Label::GetFgColor(vgui::Label *this, Color *result)
{
  vgui::Panel::GetFgColor(this, result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046DC90
// Name: public: virtual class Color vgui::Label::GetDisabledFgColor1(void)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall vgui::Label::GetDisabledFgColor1(vgui::Label *this, Color *result)
{
  *result = this->_disabledFgColor1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046DCA0
// Name: public: virtual class Color vgui::Label::GetDisabledFgColor2(void)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall vgui::Label::GetDisabledFgColor2(vgui::Label *this, Color *result)
{
  *result = this->_disabledFgColor2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00471520
// Name: public: virtual class Color vgui::Panel::GetBgColor(void)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall vgui::Panel::GetBgColor(vgui::Panel *this, Color *result)
{
  *result = this->_bgColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00471530
// Name: public: virtual class Color vgui::Panel::GetFgColor(void)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall vgui::Panel::GetFgColor(vgui::Panel *this, Color *result)
{
  *result = this->_fgColor;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004719C0
// Name: public: virtual class Color vgui::Panel::GetSchemeColor(char const __near *,class Color,class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall vgui::Panel::GetSchemeColor(
        vgui::Panel *this,
        Color *result,
        const char *keyName,
        Color defaultColor,
        vgui::IScheme *pScheme)
{
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD))pScheme->GetColor)(
    a1: pScheme,
    a2: result,
    a3: keyName,
    a4: defaultColor);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004748C0
// Name: public: virtual class Color vgui::Panel::GetSchemeColor(char const __near *,class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall vgui::Panel::GetSchemeColor(
        vgui::Panel *this,
        Color *result,
        const char *keyName,
        vgui::IScheme *pScheme)
{
  ((void (__thiscall *)(vgui::IScheme *, Color *, const char *, int))pScheme->GetColor)(
    a1: pScheme,
    a2: result,
    a3: keyName,
    a4: -1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004800F0
// Name: protected: virtual class Color vgui::ToggleButton::GetButtonFgColor(void)
// Source: json
//------------------------------------------------------------------------------
Color *__userpurge vgui::ToggleButton::GetButtonFgColor@<eax>(
        vgui::ToggleButton *this@<ecx>,
        __m128i a2@<xmm0>,
        Color *result)
{
  if ( this->IsSelected(this) )
  {
    *result = this->_selectedColor;
    return result;
  }
  else
  {
    vgui::Button::GetButtonFgColor(this, a2, result);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004816F0
// Name: protected: virtual class Color vgui::CheckButton::GetButtonFgColor(void)
// Source: json
//------------------------------------------------------------------------------
Color *__userpurge vgui::CheckButton::GetButtonFgColor@<eax>(
        vgui::CheckButton *this@<ecx>,
        __m128i a2@<xmm0>,
        Color *result)
{
  if ( this->IsArmed(this) )
  {
    *result = this->_highlightFgColor;
    return result;
  }
  else if ( this->IsSelected(this) )
  {
    *result = this->_selectedFgColor;
    return result;
  }
  else
  {
    vgui::ToggleButton::GetButtonFgColor(this, a2, result);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00481E20
// Name: public: virtual class Color vgui::ComboBoxButton::GetButtonBgColor(void)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall vgui::ComboBoxButton::GetButtonBgColor(vgui::ComboBoxButton *this, Color *result)
{
  if ( this->IsEnabled(this) )
  {
    vgui::Button::GetButtonBgColor(this, result);
    return result;
  }
  else
  {
    *result = this->m_DisabledBgColor;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B3B80
// Name: public: virtual class Color vgui::Image::GetColor(void)
// Source: json
//------------------------------------------------------------------------------
Color *__thiscall vgui::Image::GetColor(vgui::Image *this, Color *result)
{
  *result = this->_color;
  return result;
}
