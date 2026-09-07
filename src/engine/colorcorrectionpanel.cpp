// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/colorcorrectionpanel.cpp
// Functions: 355
// ============================================================

#include "engine\colorcorrectionpanel.h"

//------------------------------------------------------------------------------
// Address: 0x1005E970
// Name: public: virtual enum ColorCorrectionTool_t CSelectedHSVOperation::ToolID(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSelectedHSVOperation::ToolID(CTraceFilterDAS *this)
{
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x1009FCA0
// Name: public: static char const __near * CPrecisionSlider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPrecisionSlider::GetPanelClassName()
{
  return "CPrecisionSlider";
}

//------------------------------------------------------------------------------
// Address: 0x1009FCB0
// Name: public: virtual void CPrecisionSlider::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecisionSlider::OnSizeChanged(CPrecisionSlider *this, int wide, int tall)
{
  vgui::Panel::SetBounds(
    this: this->m_pTextEntry,
    x: wide - this->m_nTextEntryWidth,
    y: 0,
    wide: this->m_nTextEntryWidth,
    tall: tall - 12);
  vgui::Slider::OnSizeChanged(this, wide, tall);
}

//------------------------------------------------------------------------------
// Address: 0x1009FCF0
// Name: public: virtual void CPrecisionSlider::GetTrackRect(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecisionSlider::GetTrackRect(CPrecisionSlider *this, int *x, int *y, int *w, int *h)
{
  __m128i v6; // xmm0
  int tall; // [esp+4h] [ebp-8h] BYREF
  int wide; // [esp+8h] [ebp-4h] BYREF

  this->GetPaintSize(this, a2: &wide, a3: &tall);
  v6 = _mm_cvtsi32_si128(wide);
  *x = 0;
  *y = 8;
  *w = (int)(float)(_mm_cvtepi32_ps(v6).m128_f32[0]
                  - (float)((float)((float)this->m_nTextEntryWidth + this->_nobSize) + (float)this->m_nSpacing));
  *h = 4;
}

//------------------------------------------------------------------------------
// Address: 0x1009FD70
// Name: public: virtual void CPrecisionSlider::SetValue(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecisionSlider::SetValue(CPrecisionSlider *this, int value, bool bTriggerChangeMessage)
{
  char szValueString[256]; // [esp+4h] [ebp-100h] BYREF

  vgui::Slider::SetValue(this, value, bTriggerChangeMessage);
  sprintf(string: szValueString, format: "%d", this->_value);
  this->m_pTextEntry->SetText(this: this->m_pTextEntry, a2: szValueString);
}

//------------------------------------------------------------------------------
// Address: 0x1009FDD0
// Name: public: virtual void CPrecisionSlider::SetEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecisionSlider::SetEnabled(CPrecisionSlider *this, int state)
{
  vgui::Panel::SetEnabled(this, state);
  this->m_pTextEntry->SetEnabled(this: this->m_pTextEntry, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x1009FE00
// Name: protected: virtual void CPrecisionSlider::OnTextNewLine(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecisionSlider::OnTextNewLine(CPrecisionSlider *this, KeyValues *data)
{
  char buf[256]; // [esp+4h] [ebp-104h] BYREF
  int value; // [esp+104h] [ebp-4h] BYREF

  this->m_pTextEntry->GetText_2(this: this->m_pTextEntry, a2: buf, a3: 256);
  sscanf(string: buf, format: "%d", &value);
  this->SetValue(this, a2: value, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x1009FE60
// Name: public: static char const __near * CColorCorrectionUIChildPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CColorCorrectionUIChildPanel::GetPanelClassName()
{
  return "CColorCorrectionUIChildPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1009FE70
// Name: public: virtual void CColorCorrectionUIChildPanel::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionUIChildPanel::OnClose(CColorCorrectionUIChildPanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  CColorCorrectionUIChildPanel_vtbl *v4; // ebx
  int v5; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "OpPanelClose");
  else
    v3 = nullptr;
  KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
  v4 = this->__vftable;
  v5 = ((int (__thiscall *)(CColorCorrectionUIChildPanel *, KeyValues *, _DWORD))this->GetParent)(
         a1: this,
         a2: v3,
         a3: 0.0);
  ((void (__thiscall *)(CColorCorrectionUIChildPanel *, int))v4->PostMessage)(a1: this, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1009FED0
// Name: public: virtual void CColorCorrectionUIChildPanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionUIChildPanel::OnKeyCodeTyped(CColorCorrectionUIChildPanel *this, ButtonCode_t code)
{
  if ( code == KEY_ESCAPE )
    ShowHideColorCorrectionUI();
}

//------------------------------------------------------------------------------
// Address: 0x1009FEF0
// Name: public: virtual void CCurvesColorOperation::SetBlendFactor(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurvesColorOperation::SetBlendFactor(CCurvesColorOperation *this, float flBlend)
{
  this->m_flBlendFactor = flBlend;
  colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
}

//------------------------------------------------------------------------------
// Address: 0x1009FF20
// Name: public: static char const __near * CColorCurvesEditPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CColorCurvesEditPanel::GetPanelClassName()
{
  return "CColorCurvesEditPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1009FF30
// Name: public: static char const __near * CColorCurvesUIPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CColorCurvesUIPanel::GetPanelClassName()
{
  return "CColorCurvesUIPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1009FF40
// Name: public: virtual class IColorOperation __near * CColorLevelsUIPanel::GetOperation(void)
// Source: json
//------------------------------------------------------------------------------
CLevelsColorOperation *__thiscall CColorLevelsUIPanel::GetOperation(CColorLevelsUIPanel *this)
{
  return this->m_pLevelsOp;
}

//------------------------------------------------------------------------------
// Address: 0x1009FF60
// Name: public: virtual void CColorCurvesUIPanel::OnMessage(class KeyValues const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCurvesUIPanel::OnMessage(
        CColorCurvesUIPanel *this,
        KeyValues *params,
        const KeyValues *fromPanel)
{
  const char *Name; // eax
  void *Ptr; // eax
  CCurvesColorOperation_vtbl *v6; // edi
  float v7; // xmm0_4
  KeyValues *v8; // eax
  KeyValues *v9; // eax
  CColorCurvesUIPanel_vtbl *v10; // edi
  int v11; // eax

  vgui::Panel::OnMessage(this, params, ifromPanel: fromPanel);
  Name = KeyValues::GetName(this: params);
  if ( _V_stricmp(s1: "SliderMoved", s2: Name) == 0 )
  {
    Ptr = KeyValues::GetPtr(this: params, keyName: "panel", defaultValue: nullptr);
    if ( __RTDynamicCast(
           inptr: Ptr,
           VfDelta: 0,
           SrcType: &vgui::Panel `RTTI Type Descriptor',
           TargetType: &CPrecisionSlider `RTTI Type Descriptor',
           isReference: 0) == this->m_pBlendFactorSlider )
    {
      v6 = this->m_pColorOp->__vftable;
      v7 = (float)this->m_pBlendFactorSlider->GetValue(this: this->m_pBlendFactorSlider) * 0.0039215689;
      ((void (__thiscall *)(CCurvesColorOperation *, _DWORD))v6->SetBlendFactor)(a1: this->m_pColorOp, a2: LODWORD(v7));
    }
    v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v8 != nullptr )
      v9 = KeyValues::KeyValues(this: v8, setName: "command", firstKey: "command", firstValue: "BlendFactorUpdate");
    else
      v9 = nullptr;
    v10 = this->__vftable;
    v11 = ((int (__thiscall *)(CColorCurvesUIPanel *, KeyValues *, _DWORD))this->GetParent)(a1: this, a2: v9, a3: 0.0);
    ((void (__thiscall *)(CColorCurvesUIPanel *, int))v10->PostMessage)(a1: this, a2: v11);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A0050
// Name: private: void CColorCurvesUIPanel::OnColorMaskSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCurvesUIPanel::OnColorMaskSelected(CColorCurvesUIPanel *this)
{
  switch ( vgui::ComboBox::GetActiveItem(this: this->m_pColorMask) )
  {
    case 0:
      this->m_pColorOp->m_nChannelMask = 7;
      colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
      break;
    case 1:
      this->m_pColorOp->m_nChannelMask = 1;
      colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
      break;
    case 2:
      this->m_pColorOp->m_nChannelMask = 2;
      colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
      break;
    case 3:
      this->m_pColorOp->m_nChannelMask = 4;
      colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A0100
// Name: private: virtual void CColorCurvesUIPanel::OnTextChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCurvesUIPanel::OnTextChanged(CColorCurvesUIPanel *this, KeyValues *data)
{
  void *Ptr; // eax

  Ptr = KeyValues::GetPtr(this: data, keyName: "panel", defaultValue: nullptr);
  if ( __RTDynamicCast(
         inptr: Ptr,
         VfDelta: 0,
         SrcType: &vgui::Panel `RTTI Type Descriptor',
         TargetType: &vgui::ComboBox `RTTI Type Descriptor',
         isReference: 0) == this->m_pColorMask )
    CColorCurvesUIPanel::OnColorMaskSelected(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A0140
// Name: public: virtual void CLevelsColorOperation::SetBlendFactor(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLevelsColorOperation::SetBlendFactor(CLevelsColorOperation *this, float flBlend)
{
  this->m_flBlendFactor = flBlend;
  colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
}

//------------------------------------------------------------------------------
// Address: 0x100A0170
// Name: public: static char const __near * CColorHistogramPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CColorHistogramPanel::GetPanelClassName()
{
  return "CColorHistogramPanel";
}

//------------------------------------------------------------------------------
// Address: 0x100A0180
// Name: public: static char const __near * CColorSlider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CColorSlider::GetPanelClassName()
{
  return "CColorSlider";
}

//------------------------------------------------------------------------------
// Address: 0x100A0190
// Name: public: static char const __near * CColorLevelsUIPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CColorLevelsUIPanel::GetPanelClassName()
{
  return "CColorLevelsUIPanel";
}

//------------------------------------------------------------------------------
// Address: 0x100A01A0
// Name: private: void CColorLevelsUIPanel::OnColorMaskSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorLevelsUIPanel::OnColorMaskSelected(CColorLevelsUIPanel *this)
{
  switch ( vgui::ComboBox::GetActiveItem(this: this->m_pColorMask) )
  {
    case 0:
      this->m_pLevelsOp->m_nChannelMask = 7;
      colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
      this->m_pHistogramPanel->m_Type = RGB;
      break;
    case 1:
      this->m_pLevelsOp->m_nChannelMask = 1;
      colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
      this->m_pHistogramPanel->m_Type = 0;
      break;
    case 2:
      this->m_pLevelsOp->m_nChannelMask = 2;
      colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
      this->m_pHistogramPanel->m_Type = GREEN;
      break;
    case 3:
      this->m_pLevelsOp->m_nChannelMask = 4;
      colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
      this->m_pHistogramPanel->m_Type = BLUE;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A0290
// Name: private: virtual void CColorLevelsUIPanel::OnTextChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorLevelsUIPanel::OnTextChanged(CColorLevelsUIPanel *this, KeyValues *data)
{
  void *Ptr; // eax

  Ptr = KeyValues::GetPtr(this: data, keyName: "panel", defaultValue: nullptr);
  if ( __RTDynamicCast(
         inptr: Ptr,
         VfDelta: 0,
         SrcType: &vgui::Panel `RTTI Type Descriptor',
         TargetType: &vgui::ComboBox `RTTI Type Descriptor',
         isReference: 0) == this->m_pColorMask )
    CColorLevelsUIPanel::OnColorMaskSelected(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A02D0
// Name: float FuzzyLessThan(float,float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl FuzzyLessThan(float a, float b, float fuzziness)
{
  float v4; // xmm0_4

  if ( fuzziness >= 0.0039215689 )
  {
    v4 = b + fuzziness;
    if ( (float)(b - fuzziness) <= a )
    {
      if ( a <= v4 )
        return 1.0 - (a - (float)(b - fuzziness)) / (v4 - (float)(b - fuzziness));
      else
        return 0.0;
    }
    else
    {
      return 1.0;
    }
  }
  else if ( b < a )
  {
    return 0.0;
  }
  else
  {
    return 1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A0360
// Name: float FuzzyGreaterThan(float,float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl FuzzyGreaterThan(float a, float b, float fuzziness)
{
  float v4; // xmm1_4

  if ( fuzziness >= 0.0039215689 )
  {
    v4 = b - fuzziness;
    if ( a <= (float)(b + fuzziness) )
    {
      if ( v4 <= a )
        return (a - v4) / ((float)(b + fuzziness) - v4);
      else
        return 0.0;
    }
    else
    {
      return 1.0;
    }
  }
  else if ( a < b )
  {
    return 0.0;
  }
  else
  {
    return 1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A03F0
// Name: public: virtual void CSelectedHSVOperation::SetBlendFactor(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectedHSVOperation::SetBlendFactor(CSelectedHSVOperation *this, float blend_factor)
{
  this->m_flBlendFactor = blend_factor;
  colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
}

//------------------------------------------------------------------------------
// Address: 0x100A0410
// Name: public: static char const __near * CFullScreenSelectionPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CFullScreenSelectionPanel::GetPanelClassName()
{
  return "CFullScreenSelectionPanel";
}

//------------------------------------------------------------------------------
// Address: 0x100A0420
// Name: public: virtual void CFullScreenSelectionPanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFullScreenSelectionPanel::OnKeyCodeTyped(CFullScreenSelectionPanel *this, ButtonCode_t code)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( code == KEY_ESCAPE )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
    {
      v4 = KeyValues::KeyValues(this: v3, setName: "Command", firstKey: "Command", firstValue: "ToggleSelection");
      this->PostActionSignal(this, a2: v4);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A0480
// Name: public: static char const __near * CUncorrectedImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CUncorrectedImagePanel::GetPanelClassName()
{
  return "CUncorrectedImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x100A0490
// Name: public: virtual void CUncorrectedImagePanel::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUncorrectedImagePanel::OnMouseReleased(CUncorrectedImagePanel *this, const char *code)
{
  CBaseServer::RemoveClientFromGame(this, panelName: code);
  if ( code == (const char *)107 )
    this->m_bMouseDown = false;
}

//------------------------------------------------------------------------------
// Address: 0x100A04C0
// Name: public: static char const __near * CSelectedHSVUIPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSelectedHSVUIPanel::GetPanelClassName()
{
  return "CSelectedHSVUIPanel";
}

//------------------------------------------------------------------------------
// Address: 0x100A04D0
// Name: public: virtual void CSelectedHSVUIPanel::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectedHSVUIPanel::Init(CSelectedHSVUIPanel *this)
{
  this->m_pUncorrectedImage->Init(this: this->m_pUncorrectedImage, a2: 128, a3: 128, a4: true);
}

//------------------------------------------------------------------------------
// Address: 0x100A04F0
// Name: public: virtual void CSelectedHSVUIPanel::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectedHSVUIPanel::Shutdown(CSelectedHSVUIPanel *this)
{
  this->m_pUncorrectedImage->Shutdown(this: this->m_pUncorrectedImage);
}

//------------------------------------------------------------------------------
// Address: 0x100A0500
// Name: private: void CSelectedHSVUIPanel::UpdateDeltaHSV(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectedHSVUIPanel::UpdateDeltaHSV(CSelectedHSVUIPanel *this)
{
  int v2; // eax
  CPrecisionSlider *m_pToleranceSlider; // ecx
  float v4; // xmm0_4
  CSelectedHSVOperation *m_pHSVOperation; // eax
  int v6; // eax
  CPrecisionSlider *m_pFuzzinessSlider; // ecx
  CPrecisionSlider_vtbl *v8; // edx
  float deltaHSV; // [esp+4h] [ebp-Ch]
  float deltaHSV_4; // [esp+8h] [ebp-8h]

  deltaHSV = (float)this->m_pHueSlider->GetValue(this: this->m_pHueSlider);
  deltaHSV_4 = (float)this->m_pSaturationSlider->GetValue(this: this->m_pSaturationSlider) * 0.0039215689;
  v2 = this->m_pValueSlider->GetValue(this: this->m_pValueSlider);
  m_pToleranceSlider = this->m_pToleranceSlider;
  v4 = (float)v2;
  m_pHSVOperation = this->m_pHSVOperation;
  m_pHSVOperation->m_DeltaHSV.x = deltaHSV;
  m_pHSVOperation->m_DeltaHSV.y = deltaHSV_4;
  m_pHSVOperation->m_DeltaHSV.z = v4 * 0.0039215689;
  v6 = m_pToleranceSlider->GetValue(this: m_pToleranceSlider);
  m_pFuzzinessSlider = this->m_pFuzzinessSlider;
  v8 = m_pFuzzinessSlider->__vftable;
  this->m_pHSVOperation->m_Tolerance = (float)v6 * 0.0039215689;
  this->m_pHSVOperation->m_Fuzziness = (float)v8->GetValue(this: m_pFuzzinessSlider) * 0.0039215689;
  colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
}

//------------------------------------------------------------------------------
// Address: 0x100A05F0
// Name: private: void CSelectedHSVUIPanel::ResetHSVSliders(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectedHSVUIPanel::ResetHSVSliders(CSelectedHSVUIPanel *this)
{
  CSelectedHSVOperation *m_pHSVOperation; // eax
  float deltaHSV_4; // [esp+8h] [ebp-8h]
  float deltaHSV_8; // [esp+Ch] [ebp-4h]

  m_pHSVOperation = this->m_pHSVOperation;
  deltaHSV_4 = m_pHSVOperation->m_DeltaHSV.y;
  deltaHSV_8 = m_pHSVOperation->m_DeltaHSV.z;
  this->m_pHueSlider->SetValue(this: this->m_pHueSlider, a2: (int)m_pHSVOperation->m_DeltaHSV.x, a3: true);
  this->m_pSaturationSlider->SetValue(this: this->m_pSaturationSlider, a2: (int)(float)(deltaHSV_4 * 255.0), a3: true);
  this->m_pValueSlider->SetValue(this: this->m_pValueSlider, a2: (int)(float)(deltaHSV_8 * 255.0), a3: true);
  this->m_pToleranceSlider->SetValue(
    this: this->m_pToleranceSlider,
    a2: (int)(float)(this->m_pHSVOperation->m_Tolerance * 255.0),
    a3: true);
  this->m_pFuzzinessSlider->SetValue(
    this: this->m_pFuzzinessSlider,
    a2: (int)(float)(this->m_pHSVOperation->m_Fuzziness * 255.0),
    a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x100A06D0
// Name: private: void CSelectedHSVUIPanel::OnSelectionMethodSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectedHSVUIPanel::OnSelectionMethodSelected(CSelectedHSVUIPanel *this)
{
  CSelectedHSVOperation::SelectionMethod_t ActiveItem; // edi

  CSelectedHSVUIPanel::ResetHSVSliders(this);
  ActiveItem = vgui::ComboBox::GetActiveItem(this: this->m_pSelectionMethod);
  this->m_pHSVOperation->m_SelectionMethod = ActiveItem;
  colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
  if ( ActiveItem == SELECT_NEARBY_RGB
    || ActiveItem == SELECT_NEARBY_HUE
    || ActiveItem == SELECT_NEARBY_SATURATION
    || ActiveItem == SELECT_NEARBY_VALUE )
  {
    this->m_pToleranceSlider->SetEnabled(this: this->m_pToleranceSlider, a2: true);
  }
  else
  {
    this->m_pToleranceSlider->SetEnabled(this: this->m_pToleranceSlider, a2: false);
  }
  this->m_pFuzzinessSlider->SetEnabled(this: this->m_pFuzzinessSlider, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x100A0740
// Name: public: virtual void CSelectedHSVUIPanel::ReadUncorrectedImage(struct Rect_t __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectedHSVUIPanel::ReadUncorrectedImage(
        CSelectedHSVUIPanel *this,
        Rect_t *pSrcRect,
        unsigned __int8 *pPreviewImage)
{
  int v3; // esi
  int ImageBuffer; // eax
  Rect_t dstRect; // [esp+Ch] [ebp-10h] BYREF

  v3 = 0;
  dstRect.x = 0;
  dstRect.y = 0;
  dstRect.width = 128;
  dstRect.height = 96;
  do
  {
    ImageBuffer = CProceduralTexturePanel::GetImageBuffer(this: (vgui::TreeView *)this->m_pUncorrectedImage);
    _V_memcpy(dest: (void *)(v3 + ImageBuffer), src: &pPreviewImage[v3], count: 512);
    v3 += 512;
  }
  while ( v3 < 49152 );
  CProceduralTexturePanel::SetTextureSubRect(this: this->m_pUncorrectedImage, subRect: &dstRect);
  CProceduralTexturePanel::DownloadTexture(this: this->m_pUncorrectedImage);
}

//------------------------------------------------------------------------------
// Address: 0x100A07C0
// Name: public: virtual void CSelectedHSVUIPanel::OnMessage(class KeyValues const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectedHSVUIPanel::OnMessage(
        CSelectedHSVUIPanel *this,
        KeyValues *params,
        const KeyValues *fromPanel)
{
  const char *Name; // eax
  void *v5; // eax
  CPrecisionSlider *v6; // eax
  CSelectedHSVOperation_vtbl *v7; // edi
  float v8; // xmm0_4
  KeyValues *v9; // eax
  KeyValues *v10; // eax
  CSelectedHSVUIPanel_vtbl *v11; // edi
  int v12; // eax
  const char *v13; // eax
  void *Ptr; // eax
  vgui::CheckButton *v15; // eax

  vgui::Panel::OnMessage(this, params, ifromPanel: fromPanel);
  Name = KeyValues::GetName(this: params);
  if ( _V_stricmp(s1: "SliderMoved", s2: Name) != 0 )
  {
    v13 = KeyValues::GetName(this: params);
    if ( _V_stricmp(s1: "CheckButtonChecked", s2: v13) == 0 )
    {
      Ptr = KeyValues::GetPtr(this: params, keyName: "panel", defaultValue: nullptr);
      v15 = (vgui::CheckButton *)__RTDynamicCast(
                                   inptr: Ptr,
                                   VfDelta: 0,
                                   SrcType: &vgui::Panel `RTTI Type Descriptor',
                                   TargetType: &vgui::CheckButton `RTTI Type Descriptor',
                                   isReference: 0);
      if ( v15 == this->m_pColorizeButton )
      {
        this->m_pHSVOperation->m_bColorize = v15->IsSelected(this: v15);
        colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
      }
      else if ( v15 == this->m_pInvertSelectionButton )
      {
        this->m_pHSVOperation->m_bInvertSelection = ((int (*)(void))v15->IsSelected)();
        colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
      }
    }
  }
  else
  {
    v5 = KeyValues::GetPtr(this: params, keyName: "panel", defaultValue: nullptr);
    v6 = (CPrecisionSlider *)__RTDynamicCast(
                               inptr: v5,
                               VfDelta: 0,
                               SrcType: &vgui::Panel `RTTI Type Descriptor',
                               TargetType: &CPrecisionSlider `RTTI Type Descriptor',
                               isReference: 0);
    if ( v6 == this->m_pBlendFactorSlider )
    {
      v7 = this->m_pHSVOperation->__vftable;
      v8 = (float)v6->GetValue(this: v6) * 0.0039215689;
      ((void (__thiscall *)(CSelectedHSVOperation *, _DWORD))v7->SetBlendFactor)(
        a1: this->m_pHSVOperation,
        a2: LODWORD(v8));
      v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v9 != nullptr )
        v10 = KeyValues::KeyValues(this: v9, setName: "command", firstKey: "command", firstValue: "BlendFactorUpdate");
      else
        v10 = nullptr;
      v11 = this->__vftable;
      v12 = ((int (__thiscall *)(CSelectedHSVUIPanel *, KeyValues *, _DWORD))this->GetParent)(
              a1: this,
              a2: v10,
              a3: 0.0);
      ((void (__thiscall *)(CSelectedHSVUIPanel *, int))v11->PostMessage)(a1: this, a2: v12);
    }
    else
    {
      CSelectedHSVUIPanel::UpdateDeltaHSV(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A0950
// Name: public: void CSelectedHSVUIPanel::EnableSelectionMode(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectedHSVUIPanel::EnableSelectionMode(CSelectedHSVUIPanel *this, BOOL bEnable)
{
  vgui::Button *m_pSelectionButton; // ecx

  if ( bEnable )
    ((void (__stdcall *)(CSelectedHSVOperation *))colorcorrectiontools->SetFinalOperation)(a1: this->m_pHSVOperation);
  else
    ((void (__stdcall *)(_DWORD))colorcorrectiontools->SetFinalOperation)(a1: 0);
  m_pSelectionButton = this->m_pSelectionButton;
  this->m_bSelectionEnable = bEnable;
  m_pSelectionButton->ForceDepressed(this: m_pSelectionButton, a2: bEnable);
  this->m_pFullScreenSelection->SetEnabled(this: this->m_pFullScreenSelection, a2: bEnable);
  this->m_pFullScreenSelection->SetVisible(this: this->m_pFullScreenSelection, a2: bEnable);
  this->m_pFullScreenSelection->SetMouseInputEnabled(this: this->m_pFullScreenSelection, a2: bEnable);
}

//------------------------------------------------------------------------------
// Address: 0x100A09D0
// Name: public: CColorLookupOperation::CColorLookupOperation(void)
// Source: json
//------------------------------------------------------------------------------
CColorLookupOperation *__thiscall CColorLookupOperation::CColorLookupOperation(CColorLookupOperation *this)
{
  this->m_Resolution = 0;
  this->m_LookupTable = nullptr;
  this->__vftable = (CColorLookupOperation_vtbl *)&CColorLookupOperation::`vftable';
  this->m_flBlendFactor = 1.0;
  _V_strcpy(dest: this->m_pName, src: "Lookup");
  _V_strcpy(dest: this->m_pFilename, src: defaultValue);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A0A20
// Name: public: virtual char const __near * CColorLookupOperation::GetName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CColorLookupOperation::GetName(CColorLookupOperation *this)
{
  return this->m_pName;
}

//------------------------------------------------------------------------------
// Address: 0x100A0A30
// Name: public: virtual void CColorLookupOperation::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorLookupOperation::SetName(CColorLookupOperation *this, const char *pName)
{
  _V_strcpy(dest: this->m_pName, src: pName);
}

//------------------------------------------------------------------------------
// Address: 0x100A0A50
// Name: public: virtual bool CColorLookupOperation::IsEnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CColorLookupOperation::IsEnabled(CColorLookupOperation *this)
{
  return this->m_bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x100A0A60
// Name: public: virtual void CColorLookupOperation::SetEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorLookupOperation::SetEnabled(CColorLookupOperation *this, bool bEnable)
{
  this->m_bEnable = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x100A0A70
// Name: public: virtual float CColorLookupOperation::GetBlendFactor(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CColorLookupOperation::GetBlendFactor(CBaseServer *this)
{
  return this->m_flTimescale;
}

//------------------------------------------------------------------------------
// Address: 0x100A0A80
// Name: public: void CColorLookupOperation::GetLookupValue(int,int,int,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorLookupOperation::GetLookupValue(CColorLookupOperation *this, int r, int g, int b, Vector *out)
{
  color24 *m_LookupTable; // ebx
  int v6; // esi
  int v7; // edi
  int v8; // edx
  int m_Resolution; // ecx
  int v10; // eax
  int v11; // ecx
  __int16 v12; // ax

  m_LookupTable = this->m_LookupTable;
  if ( m_LookupTable != nullptr )
  {
    v6 = r;
    if ( r < 0 )
      v6 = 0;
    v7 = g;
    if ( g < 0 )
      v7 = 0;
    v8 = b;
    if ( b < 0 )
      v8 = 0;
    m_Resolution = this->m_Resolution;
    v10 = m_Resolution - 1;
    if ( v6 > m_Resolution - 1 )
      v6 = m_Resolution - 1;
    if ( v7 > v10 )
      v7 = m_Resolution - 1;
    if ( v8 > v10 )
      v8 = m_Resolution - 1;
    v11 = (int)m_LookupTable
        + 2 * v6
        + 2 * m_Resolution * (v7 + v8 * m_Resolution)
        + v6
        + m_Resolution * (v7 + v8 * m_Resolution);
    v12 = *(_WORD *)v11;
    LOBYTE(v11) = *(_BYTE *)(v11 + 2);
    out->x = (float)(unsigned __int8)v12 * 0.0039215689;
    out->y = (float)HIBYTE(v12) * 0.0039215689;
    out->z = (float)(unsigned __int8)v11 * 0.0039215689;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A0B40
// Name: public: virtual void CColorLookupOperation::SetBlendFactor(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorLookupOperation::SetBlendFactor(CColorLookupOperation *this, float flBlend)
{
  this->m_flBlendFactor = flBlend;
  colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
}

//------------------------------------------------------------------------------
// Address: 0x100A0B70
// Name: public: virtual class IColorOperation __near * CColorLookupOperation::Clone(void)
// Source: json
//------------------------------------------------------------------------------
IColorOperation *__thiscall CColorLookupOperation::Clone(CColorLookupOperation *this)
{
  char *v2; // edi
  void *v3; // eax

  v2 = (char *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v2 != nullptr )
  {
    *((_DWORD *)v2 + 66) = 0;
    *((_DWORD *)v2 + 67) = 0;
    *(_DWORD *)v2 = &CColorLookupOperation::`vftable';
    *((_DWORD *)v2 + 68) = 1065353216;
    _V_strcpy(dest: v2 + 277, src: "Lookup");
    _V_strcpy(dest: v2 + 4, src: defaultValue);
  }
  else
  {
    v2 = nullptr;
  }
  _V_memcpy(dest: v2 + 4, src: this->m_pFilename, count: 260);
  *((_DWORD *)v2 + 66) = this->m_Resolution;
  *((float *)v2 + 68) = this->m_flBlendFactor;
  v2[276] = this->m_bEnable;
  _V_memcpy(dest: v2 + 277, src: this->m_pName, count: 256);
  v3 = MemAlloc_Alloc(
         nSize: (3 * (unsigned __int64)(unsigned int)(this->m_Resolution * this->m_Resolution * this->m_Resolution)) >> 32 != 0
       ? -1
       : 3 * this->m_Resolution * this->m_Resolution * this->m_Resolution);
  *((_DWORD *)v2 + 67) = v3;
  _V_memcpy(dest: v3, src: this->m_LookupTable, count: 3 * this->m_Resolution * this->m_Resolution * this->m_Resolution);
  return (IColorOperation *)v2;
}

//------------------------------------------------------------------------------
// Address: 0x100A0C70
// Name: public: static char const __near * CColorLookupUIPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CColorLookupUIPanel::GetPanelClassName()
{
  return "CColorLookupUIPanel";
}

//------------------------------------------------------------------------------
// Address: 0x100A0C80
// Name: public: virtual void CColorLookupUIPanel::OnMessage(class KeyValues const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorLookupUIPanel::OnMessage(
        CColorLookupUIPanel *this,
        KeyValues *params,
        const KeyValues *fromPanel)
{
  const char *Name; // eax
  CColorLookupOperation_vtbl *v5; // edi
  float v6; // xmm0_4
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  CColorLookupUIPanel_vtbl *v9; // edi
  int v10; // eax

  vgui::Panel::OnMessage(this, params, ifromPanel: fromPanel);
  Name = KeyValues::GetName(this: params);
  if ( _V_stricmp(s1: "SliderMoved", s2: Name) == 0
    && KeyValues::GetPtr(this: params, keyName: "panel", defaultValue: nullptr) == this->m_pBlendFactorSlider )
  {
    v5 = this->m_pLookupOp->__vftable;
    v6 = (float)this->m_pBlendFactorSlider->GetValue(this: this->m_pBlendFactorSlider) * 0.0039215689;
    ((void (__thiscall *)(CColorLookupOperation *, _DWORD))v5->SetBlendFactor)(a1: this->m_pLookupOp, a2: LODWORD(v6));
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
      v8 = KeyValues::KeyValues(this: v7, setName: "command", firstKey: "command", firstValue: "BlendFactorUpdate");
    else
      v8 = nullptr;
    v9 = this->__vftable;
    v10 = ((int (__thiscall *)(CColorLookupUIPanel *, KeyValues *, _DWORD))this->GetParent)(a1: this, a2: v8, a3: 0.0);
    ((void (__thiscall *)(CColorLookupUIPanel *, int))v9->PostMessage)(a1: this, a2: v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A0D50
// Name: private: void CColorLookupUIPanel::ResetBlendFactorSlider(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorLookupUIPanel::ResetBlendFactorSlider(CColorLookupUIPanel *this)
{
  float v2; // xmm0_4
  float flBlend; // [esp+4h] [ebp-4h]

  if ( this->m_pLookupOp != nullptr )
  {
    flBlend = this->m_pLookupOp->GetBlendFactor(this: this->m_pLookupOp);
    v2 = flBlend;
  }
  else
  {
    v2 = 0.0;
  }
  this->m_pBlendFactorSlider->SetValue(this: this->m_pBlendFactorSlider, a2: (int)(float)(v2 * 255.0), a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x100A0DA0
// Name: public: virtual char const __near * CColorBalanceOperation::GetName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CColorBalanceOperation::GetName(CColorBalanceOperation *this)
{
  return this->m_pName;
}

//------------------------------------------------------------------------------
// Address: 0x100A0DB0
// Name: public: virtual void CColorBalanceOperation::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorBalanceOperation::SetName(CColorBalanceOperation *this, const char *pName)
{
  _V_strcpy(dest: this->m_pName, src: pName);
}

//------------------------------------------------------------------------------
// Address: 0x100A0DD0
// Name: public: virtual bool CColorBalanceOperation::IsEnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CColorBalanceOperation::IsEnabled(CColorBalanceOperation *this)
{
  return this->m_bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x100A0DE0
// Name: public: virtual void CColorBalanceOperation::SetEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorBalanceOperation::SetEnabled(CColorBalanceOperation *this, bool bEnable)
{
  this->m_bEnable = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x100A0DF0
// Name: public: virtual float CColorBalanceOperation::GetBlendFactor(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CColorBalanceOperation::GetBlendFactor(CColorBalanceOperation *this)
{
  return this->m_flBlendFactor;
}

//------------------------------------------------------------------------------
// Address: 0x100A0E00
// Name: void HSLToRGB(int __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HSLToRGB(int *hue, int *saturation, int *lightness)
{
  float v5; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm5_4
  double v9; // st7
  double v10; // st6
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm5_4
  int v17; // ecx
  float v18; // xmm0_4
  float l; // [esp+8h] [ebp+8h]
  float la; // [esp+8h] [ebp+8h]
  float lb; // [esp+8h] [ebp+8h]
  float m2; // [esp+Ch] [ebp+Ch]
  float m1; // [esp+10h] [ebp+10h]

  v5 = (float)*saturation;
  v7 = (float)*lightness;
  v8 = (float)*hue;
  if ( v5 == 0.0 )
  {
    *hue = (int)v7;
    *lightness = (int)v7;
    *saturation = (int)v7;
    return;
  }
  v9 = v7;
  if ( v7 >= 128.0 )
    v10 = 0.00392156862745098 * (v7 + v5 - v5 * v7 * 0.00392156862745098);
  else
    v10 = (v5 + 255.0) * v7 * 0.00001537870049980777;
  m2 = v10;
  v11 = v8 + 85.0;
  l = v8 + 85.0;
  m1 = v9 * 0.007843137254901961 - v10;
  if ( (float)(v8 + 85.0) <= 255.0 )
  {
    if ( v11 >= 0.0 )
      goto LABEL_11;
    v11 = v11 + 255.0;
  }
  else
  {
    v11 = v11 - 255.0;
  }
  l = v11;
LABEL_11:
  v12 = v9 * 0.007843137254901961 - v10;
  if ( v11 >= 42.5 )
  {
    if ( l >= 127.5 )
    {
      if ( v11 >= 170.0 )
        v13 = v9 * 0.007843137254901961 - v10;
      else
        v13 = (float)((float)((float)(170.0 - v11) * 0.023529412) * (float)(m2 - m1)) + m1;
    }
    else
    {
      v13 = v10;
    }
  }
  else
  {
    v13 = (float)((float)(m2 - m1) * (float)(v11 * 0.023529412)) + m1;
  }
  v14 = v8;
  *hue = (int)(float)(v13 * 255.0);
  la = v8;
  if ( v8 <= 255.0 )
  {
    if ( v8 >= 0.0 )
      goto LABEL_23;
    v14 = v8 + 255.0;
  }
  else
  {
    v14 = v8 - 255.0;
  }
  la = v14;
LABEL_23:
  if ( v14 >= 42.5 )
  {
    if ( la >= 127.5 )
    {
      if ( v14 >= 170.0 )
        v15 = v9 * 0.007843137254901961 - v10;
      else
        v15 = (float)((float)((float)(170.0 - v14) * 0.023529412) * (float)(m2 - m1)) + m1;
    }
    else
    {
      v15 = v10;
    }
  }
  else
  {
    v15 = (float)((float)(m2 - m1) * (float)(v14 * 0.023529412)) + m1;
  }
  v16 = v8 - 85.0;
  v17 = (int)(float)(v15 * 255.0);
  v18 = v16;
  *saturation = v17;
  lb = v16;
  if ( v16 <= 255.0 )
  {
    if ( v16 >= 0.0 )
      goto LABEL_35;
    v18 = v16 + 255.0;
  }
  else
  {
    v18 = v16 - 255.0;
  }
  lb = v18;
LABEL_35:
  if ( v18 >= 42.5 )
  {
    if ( lb >= 127.5 )
    {
      if ( v18 < 170.0 )
        v12 = m1 + (float)((float)((float)(170.0 - v18) * 0.023529412) * (float)(m2 - m1));
      *lightness = (int)(float)(v12 * 255.0);
    }
    else
    {
      *lightness = (int)(float)(m2 * 255.0);
    }
  }
  else
  {
    *lightness = (int)(float)((float)(m1 + (float)((float)(m2 - m1) * (float)(v18 * 0.023529412))) * 255.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A1070
// Name: void RGBToHSL(int __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RGBToHSL(int *red, int *green, int *blue)
{
  int v3; // esi
  int v4; // edi
  int v5; // ecx
  int v6; // edx
  int v7; // eax
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float l; // [esp+Ch] [ebp-8h]

  v3 = *red;
  v4 = *green;
  v5 = *blue;
  if ( *red > *green )
  {
    v6 = *red;
    if ( v3 <= v5 )
      v6 = *blue;
    if ( v4 < v5 )
    {
      v7 = *green;
      goto LABEL_10;
    }
    goto LABEL_9;
  }
  v6 = *green;
  if ( v4 <= v5 )
    v6 = *blue;
  v7 = *red;
  if ( v3 >= v5 )
LABEL_9:
    v7 = *blue;
LABEL_10:
  l = (double)(v7 + v6) * 0.5;
  if ( v6 == v7 )
  {
    v8 = 0.0;
    v9 = 0.0;
  }
  else
  {
    v10 = (float)(v6 - v7);
    if ( l >= 128.0 )
      v11 = (float)(511 - v7 - v6);
    else
      v11 = (float)(v7 + v6);
    v9 = (float)(v10 * 255.0) / v11;
    if ( v3 == v6 )
    {
      v12 = (float)(v4 - v5) / v10;
    }
    else if ( v4 == v6 )
    {
      v12 = (float)((float)(v5 - v3) / v10) + 2.0;
    }
    else
    {
      v12 = (float)((float)(v3 - v4) / v10) + 4.0;
    }
    v8 = v12 * 42.5;
    if ( v8 >= 0.0 )
    {
      if ( v8 > 255.0 )
        v8 = v8 - 255.0;
    }
    else
    {
      v8 = v8 + 255.0;
    }
  }
  *red = (int)v8;
  *green = (int)v9;
  *blue = (int)l;
}

//------------------------------------------------------------------------------
// Address: 0x100A11A0
// Name: public: virtual void CColorBalanceOperation::Apply(class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorBalanceOperation::Apply(CColorBalanceOperation *this, int inRGB, Vector *outRGB)
{
  bool v4; // zf
  const Vector *v5; // ebx
  int v6; // ecx
  int v7; // esi
  int v8; // edx
  int v9; // eax
  Vector *v10; // eax
  __m128i v11; // xmm2
  __m128i v12; // xmm3
  float v13; // xmm1_4
  float m_flBlendFactor; // xmm6_4
  float y; // xmm4_4
  float v16; // xmm0_4
  int greenIn; // [esp+4h] [ebp-10h]
  int redIn; // [esp+8h] [ebp-Ch]
  int greenOut; // [esp+Ch] [ebp-8h] BYREF
  int redOut; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_bEnable )
  {
    v4 = !this->m_PreserveLuminosity;
    v5 = (const Vector *)inRGB;
    redIn = (int)(float)(*(float *)inRGB * 255.0);
    greenIn = (int)(float)(*(float *)(inRGB + 4) * 255.0);
    v6 = this->m_pGreenLookup[greenIn];
    v7 = (int)(float)(*(float *)(inRGB + 8) * 255.0);
    v8 = this->m_pBlueLookup[v7];
    redOut = this->m_pRedLookup[redIn];
    greenOut = v6;
    inRGB = v8;
    if ( !v4 )
    {
      RGBToHSL(red: &redOut, green: &greenOut, blue: &inRGB);
      if ( redIn <= greenIn )
      {
        v9 = greenIn;
        if ( greenIn <= v7 )
          v9 = v7;
        if ( redIn < v7 )
          v7 = redIn;
      }
      else
      {
        v9 = redIn;
        if ( redIn <= v7 )
          v9 = v7;
        if ( greenIn < v7 )
          v7 = greenIn;
      }
      inRGB = (int)(float)((float)(v9 + v7) * 0.5);
      HSLToRGB(hue: &redOut, saturation: &greenOut, lightness: &inRGB);
    }
    v10 = outRGB;
    v11 = _mm_cvtsi32_si128(greenOut);
    v12 = _mm_cvtsi32_si128(inRGB);
    v13 = (float)redOut * 0.0039215689;
    outRGB->x = v13;
    *(float *)v12.m128i_i32 = _mm_cvtepi32_ps(v12).m128_f32[0] * 0.0039215689;
    LODWORD(v10->z) = v12.m128i_i32[0];
    *(float *)v11.m128i_i32 = _mm_cvtepi32_ps(v11).m128_f32[0] * 0.0039215689;
    LODWORD(v10->y) = v11.m128i_i32[0];
    m_flBlendFactor = this->m_flBlendFactor;
    y = v5->y;
    v16 = (float)(1.0 - m_flBlendFactor) * v5->z;
    v10->x = (float)(v13 * m_flBlendFactor) + (float)(v5->x * (float)(1.0 - m_flBlendFactor));
    v10->y = (float)(y * (float)(1.0 - m_flBlendFactor)) + (float)(*(float *)v11.m128i_i32 * m_flBlendFactor);
    v10->z = (float)(*(float *)v12.m128i_i32 * m_flBlendFactor) + v16;
  }
  else
  {
    *outRGB = *(Vector *)inRGB;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A1330
// Name: public: virtual void CColorBalanceOperation::SetBlendFactor(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorBalanceOperation::SetBlendFactor(CColorBalanceOperation *this, float flBlend)
{
  this->m_flBlendFactor = flBlend;
  colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
}

//------------------------------------------------------------------------------
// Address: 0x100A1360
// Name: public: static char const __near * CColorBalanceUIPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CColorBalanceUIPanel::GetPanelClassName()
{
  return "CColorBalanceUIPanel";
}

//------------------------------------------------------------------------------
// Address: 0x100A1370
// Name: public: enum ColorBalanceMode_t CColorBalanceUIPanel::GetCurrentMode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CColorBalanceUIPanel::GetCurrentMode(CColorBalanceUIPanel *this)
{
  if ( this->m_pShadowModeButton->IsSelected(this: this->m_pShadowModeButton) )
    return 0;
  if ( this->m_pMidtoneModeButton->IsSelected(this: this->m_pMidtoneModeButton) )
    return 1;
  return this->m_pHighlightModeButton->IsSelected(this: this->m_pHighlightModeButton) ? 2 : 0;
}

//------------------------------------------------------------------------------
// Address: 0x100A13D0
// Name: private: void CColorBalanceUIPanel::ResetSliders(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorBalanceUIPanel::ResetSliders(CColorBalanceUIPanel *this)
{
  int CurrentMode; // edi

  if ( this->m_pBalanceOp != nullptr )
  {
    CurrentMode = CColorBalanceUIPanel::GetCurrentMode(this);
    this->m_pCyanRedSlider->SetValue(
      this: this->m_pCyanRedSlider,
      a2: (int)this->m_pBalanceOp->m_CyanRedBalance[CurrentMode],
      a3: false);
    this->m_pMagentaGreenSlider->SetValue(
      this: this->m_pMagentaGreenSlider,
      a2: (int)this->m_pBalanceOp->m_MagentaGreenBalance[CurrentMode],
      a3: false);
    this->m_pYellowBlueSlider->SetValue(
      this: this->m_pYellowBlueSlider,
      a2: (int)this->m_pBalanceOp->m_YellowBlueBalance[CurrentMode],
      a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A1450
// Name: public: static char const __near * CLookupViewPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CLookupViewPanel::GetPanelClassName()
{
  return "CLookupViewPanel";
}

//------------------------------------------------------------------------------
// Address: 0x100A1460
// Name: public: static char const __near * CLookupViewWindow::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CLookupViewWindow::GetPanelClassName()
{
  return "CLookupViewWindow";
}

//------------------------------------------------------------------------------
// Address: 0x100A1470
// Name: public: virtual void CLookupViewWindow::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLookupViewWindow::Init(CLookupViewWindow *this)
{
  CLookupViewPanel *m_pLookupPanel; // ecx
  Rect_t rect; // [esp+4h] [ebp-10h] BYREF

  this->m_pLookupPanel->Init(this: this->m_pLookupPanel, a2: 128, a3: 256, a4: false);
  m_pLookupPanel = this->m_pLookupPanel;
  rect.x = 0;
  rect.y = 0;
  rect.width = 128;
  rect.height = 256;
  CProceduralTexturePanel::SetTextureSubRect(this: m_pLookupPanel, subRect: &rect);
  CProceduralTexturePanel::DownloadTexture(this: this->m_pLookupPanel);
}

//------------------------------------------------------------------------------
// Address: 0x100A14D0
// Name: public: virtual void CLookupViewWindow::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLookupViewWindow::Shutdown(CLookupViewWindow *this)
{
  this->m_pLookupPanel->Shutdown(this: this->m_pLookupPanel);
}

//------------------------------------------------------------------------------
// Address: 0x100A14E0
// Name: public: static char const __near * CNewOperationDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CNewOperationDialog::GetPanelClassName()
{
  return "CNewOperationDialog";
}

//------------------------------------------------------------------------------
// Address: 0x100A14F0
// Name: public: static char const __near * COperationListPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl COperationListPanel::GetPanelClassName()
{
  return "COperationListPanel";
}

//------------------------------------------------------------------------------
// Address: 0x100A1500
// Name: public: virtual void COperationListPanel::AddSelectedItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationListPanel::AddSelectedItem(COperationListPanel *this, int itemID)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  vgui::ListPanel::AddSelectedItem(this, itemID);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "Command", firstKey: "Command", firstValue: "SelectedItemChanged");
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A1560
// Name: public: virtual void COperationListPanel::ClearSelectedItems(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationListPanel::ClearSelectedItems(COperationListPanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  vgui::ListPanel::ClearSelectedItems(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "Command", firstKey: "Command", firstValue: "SelectedItemChanged");
    this->PostActionSignal(this, a2: v3);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A15B0
// Name: public: virtual void COperationListPanel::RemoveItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationListPanel::RemoveItem(COperationListPanel *this, int itemID)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  vgui::ListPanel::RemoveItem(this, itemID);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "Command", firstKey: "Command", firstValue: "SelectedItemChanged");
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A1610
// Name: public: virtual void COperationListPanel::SetSortColumn(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationListPanel::SetSortColumn(COperationListPanel *this, int column)
{
  int v3; // edi
  unsigned int v4; // eax
  int i; // edi
  KeyValues *v6; // eax
  unsigned int v7; // eax

  if ( column == 0 )
  {
    HIBYTE(column) = 1;
    v3 = this->FirstItem(this);
    if ( v3 != this->InvalidItemID(this) )
    {
      while ( 1 )
      {
        v4 = this->GetItemUserData(this, a2: v3);
        if ( (*(unsigned __int8 (__thiscall **)(unsigned int))(*(_DWORD *)v4 + 24))(a1: v4) == 0 )
          break;
        v3 = this->NextItem(this, a2: v3);
        if ( v3 == this->InvalidItemID(this) )
          goto LABEL_7;
      }
      HIBYTE(column) = 0;
    }
LABEL_7:
    for ( i = this->FirstItem(this); i != this->InvalidItemID(this); i = this->NextItem(this, a2: i) )
    {
      v6 = this->GetItem(this, a2: i);
      KeyValues::SetInt(this: v6, keyName: "image", value: HIBYTE(column) == 0);
      v7 = this->GetItemUserData(this, a2: i);
      LOBYTE(column) = HIBYTE(column) == 0;
      (*(void (__thiscall **)(unsigned int, int))(*(_DWORD *)v7 + 28))(a1: v7, a2: column);
    }
    colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A1720
// Name: public: virtual void COperationListPanel::OnTextNewLine(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationListPanel::OnTextNewLine(COperationListPanel *this, KeyValues *data)
{
  unsigned int v3; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  void (__thiscall *LeaveEditMode)(vgui::ListPanel *); // eax
  vgui::TextEntry *m_pNameEditPanel; // ecx
  char newName[256]; // [esp+4h] [ebp-100h] BYREF

  this->m_pNameEditPanel->GetText_2(this: this->m_pNameEditPanel, a2: newName, a3: 256);
  if ( this->m_nEditItem != -1 )
  {
    v3 = this->GetItemUserData(this, a2: this->m_nEditItem);
    (*(void (__thiscall **)(unsigned int, char *))(*(_DWORD *)v3 + 12))(a1: v3, a2: newName);
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "Command", firstKey: "Command", firstValue: "UpdateList");
    else
      v5 = nullptr;
    this->PostActionSignal(this, a2: v5);
  }
  LeaveEditMode = this->LeaveEditMode;
  this->m_nEditItem = -1;
  LeaveEditMode(this);
  m_pNameEditPanel = this->m_pNameEditPanel;
  if ( m_pNameEditPanel != nullptr )
    ((void (__thiscall *)(vgui::TextEntry *, int))m_pNameEditPanel->dtr_Panel)(a1: m_pNameEditPanel, a2: 1);
  this->m_pNameEditPanel = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100A17F0
// Name: public: static char const __near * CColorOperationListPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CColorOperationListPanel::GetPanelClassName()
{
  return "CColorOperationListPanel";
}

//------------------------------------------------------------------------------
// Address: 0x100A1800
// Name: private: virtual void CColorOperationListPanel::OnCheckButtonChecked(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CColorOperationListPanel::OnCheckButtonChecked(CColorOperationListPanel *this, KeyValues *data)
{
  vgui::CheckButton *Ptr; // eax
  vgui::CheckButton *m_pEnableButton; // ecx
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  vgui::CheckButton *m_pEnableEntitiesButton; // ecx

  Ptr = (vgui::CheckButton *)KeyValues::GetPtr(this: data, keyName: "panel", defaultValue: nullptr);
  m_pEnableButton = this->m_pEnableButton;
  if ( Ptr == m_pEnableButton )
  {
    if ( m_pEnableButton->IsSelected(this: m_pEnableButton) )
    {
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
        v6 = KeyValues::KeyValues(
               this: v5,
               setName: "Command",
               firstKey: "Command",
               firstValue: "EnableColorCorrection");
      else
        v6 = nullptr;
      this->PostActionSignal(this, a2: v6);
      this->m_bEnable = true;
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_colcorrection_editor.IConVar, value: 1);
    }
    else
    {
      v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v7 != nullptr )
        v8 = KeyValues::KeyValues(
               this: v7,
               setName: "Command",
               firstKey: "Command",
               firstValue: "DisableColorCorrection");
      else
        v8 = nullptr;
      this->PostActionSignal(this, a2: v8);
      this->m_bEnable = false;
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_colcorrection_editor.IConVar, value: 0);
    }
  }
  else
  {
    m_pEnableEntitiesButton = this->m_pEnableEntitiesButton;
    if ( Ptr == m_pEnableEntitiesButton )
    {
      if ( m_pEnableEntitiesButton->IsSelected(this: m_pEnableEntitiesButton) )
      {
        this->m_bEnableEntities = true;
        CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_colcorrection_disableentities.IConVar, value: 0);
      }
      else
      {
        this->m_bEnableEntities = false;
        CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_colcorrection_disableentities.IConVar, value: 1);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A1910
// Name: public: virtual void CColorOperationListPanel::SetupFileOpenDialog(class vgui::FileOpenDialog __near *,bool,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorOperationListPanel::SetupFileOpenDialog(
        CColorOperationListPanel *this,
        vgui::FileOpenDialog *pDialog,
        bool bOpenFile,
        const char *pFileFormat,
        KeyValues *pContextKeyValues)
{
  char pStartingDir[260]; // [esp+4h] [ebp-104h] BYREF

  GetModContentSubdirectory(pSubDir: "materialsrc/correction", pBuf: pStartingDir, nBufLen: 260);
  g_pFullFileSystem->CreateDirHierarchy(this: g_pFullFileSystem, a2: pStartingDir, a3: nullptr);
  pDialog->SetTitle_2(this: pDialog, a2: "Choose VCC File", a3: true);
  vgui::FileOpenDialog::SetStartDirectoryContext(
    this: pDialog,
    pStartDirContext: "vcc_session",
    pDefaultDir: pStartingDir);
  vgui::FileOpenDialog::AddFilter(
    this: pDialog,
    filter: "*.vcc",
    filterName: "Valve Color Correction File (*.vcc)",
    bActive: true,
    pFilterInfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100A1990
// Name: public: virtual void CColorOperationListPanel::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorOperationListPanel::OnThink(CColorOperationListPanel *this)
{
  vgui::Panel::OnThink(this);
  if ( this->m_bEnable )
    ((void (__thiscall *)(IColorCorrectionSystem *, unsigned int, _DWORD))colorcorrection->SetLookupWeight)(
      a1: colorcorrection,
      a2: this->m_CCHandle,
      a3: 1.0);
  else
    ((void (__thiscall *)(IColorCorrectionSystem *, unsigned int, _DWORD))colorcorrection->SetLookupWeight)(
      a1: colorcorrection,
      a2: this->m_CCHandle,
      a3: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x100A19E0
// Name: private: void CColorOperationListPanel::ResetSlider(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorOperationListPanel::ResetSlider(CColorOperationListPanel *this)
{
  int v2; // edi
  unsigned int v3; // eax
  float flBlend; // [esp+8h] [ebp-4h]

  v2 = this->m_pOperationListPanel->GetSelectedItem(this: this->m_pOperationListPanel, a2: 0);
  if ( v2 < 0 || v2 >= this->m_pOperationListPanel->GetItemCount(this: this->m_pOperationListPanel) )
  {
    this->m_pBlendFactorSlider->SetValue(this: this->m_pBlendFactorSlider, a2: 0, a3: true);
    this->m_pBlendFactorSlider->SetEnabled(this: this->m_pBlendFactorSlider, a2: false);
  }
  else
  {
    v3 = this->m_pOperationListPanel->GetItemUserData(this: this->m_pOperationListPanel, a2: v2);
    flBlend = ((double (__thiscall *)(unsigned int))*(_DWORD *)(*(_DWORD *)v3 + 36))(a1: v3);
    this->m_pBlendFactorSlider->SetValue(this: this->m_pBlendFactorSlider, a2: (int)(float)(flBlend * 255.0), a3: true);
    this->m_pBlendFactorSlider->SetEnabled(this: this->m_pBlendFactorSlider, a2: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A1A90
// Name: public: static char const __near * CColorCorrectionUIPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CColorCorrectionUIPanel::GetPanelClassName()
{
  return "CColorCorrectionUIPanel";
}

//------------------------------------------------------------------------------
// Address: 0x100A1AA0
// Name: public: virtual void CColorCorrectionUIPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionUIPanel::OnCommand(CColorCorrectionUIPanel *this, const char *command)
{
  unsigned int m_CCHandle; // edx

  vgui::Frame::OnCommand(this, command);
  if ( _V_stricmp(s1: "EnableColorCorrection", s2: command) != 0 )
  {
    if ( _V_stricmp(s1: "DisableColorCorrection", s2: command) == 0 )
    {
      this->m_bEnable = false;
      colorcorrection->SetResetable(this: colorcorrection, a2: this->m_CCHandle, a3: true);
    }
  }
  else
  {
    m_CCHandle = this->m_CCHandle;
    this->m_nCurrentRow = 0;
    this->m_bEnable = true;
    colorcorrection->SetResetable(this: colorcorrection, a2: m_CCHandle, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A1B50
// Name: public: virtual void CColorCorrectionTools::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionTools::Init(CColorCorrectionTools *this)
{
  if ( g_pColorCorrectionUI != nullptr )
    g_pColorCorrectionUI->m_pOperationListPanel->m_pLookupViewWindow->Init(this: g_pColorCorrectionUI->m_pOperationListPanel->m_pLookupViewWindow);
  this->m_pPreviewImage = (BGRA8888_t *)MemAlloc_Alloc(nSize: 0xC000u);
}

//------------------------------------------------------------------------------
// Address: 0x100A1B90
// Name: public: virtual void CColorCorrectionTools::UpdateColorCorrection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionTools::UpdateColorCorrection(CColorCorrectionTools *this)
{
  if ( g_pColorCorrectionUI->m_bEnable )
    g_pColorCorrectionUI->m_nCurrentRow = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100A1BB0
// Name: public: virtual void CColorCorrectionTools::SetFinalOperation(class IColorOperation __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionTools::SetFinalOperation(CColorCorrectionTools *this, IColorOperation *pOp)
{
  CColorCorrectionUIPanel *v2; // eax
  bool v3; // zf

  v2 = g_pColorCorrectionUI;
  v3 = !g_pColorCorrectionUI->m_bEnable;
  g_pColorCorrectionUI->m_pFinalOperation = pOp;
  if ( !v3 )
    v2->m_nCurrentRow = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100A1BE0
// Name: void ShowHideColorCorrectionUI(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowHideColorCorrectionUI()
{
  int v0; // eax
  bool v1; // al
  CColorCorrectionUIPanel_vtbl *v2; // edx

  if ( g_pColorCorrectionUI != nullptr )
  {
    v1 = g_pColorCorrectionUI->IsVisible(this: g_pColorCorrectionUI);
    v2 = g_pColorCorrectionUI->__vftable;
    if ( v1 )
      ((void (*)(void))v2->Close)();
    else
      ((void (*)(void))v2->Activate)();
  }
  else
  {
    v0 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v0 + 12))(a1: v0, a2: "-tools", a3: 0) == 0 )
      _Warning(a1: "colorcorrectionui is only available when running with -tools!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A1C40
// Name: void PrintColorCorrection(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrintColorCorrection()
{
  double v0; // st7
  double v1; // st7
  double v2; // st7
  double v3; // st7
  double v4; // st7

  v0 = ((double (__thiscall *)(IColorCorrectionSystem *, int))colorcorrection->GetLookupWeight)(
         a1: colorcorrection,
         a2: -1);
  ConMsg(a1: "Default weight : %0.5f\n", v0);
  v1 = ((double (__thiscall *)(IColorCorrectionSystem *, _DWORD))colorcorrection->GetLookupWeight)(
         a1: colorcorrection,
         a2: 0);
  ConMsg(a1: "Weight 0       : %0.5f\n", v1);
  v2 = ((double (__thiscall *)(IColorCorrectionSystem *, int))colorcorrection->GetLookupWeight)(
         a1: colorcorrection,
         a2: 1);
  ConMsg(a1: "Weight 1       : %0.5f\n", v2);
  v3 = ((double (__thiscall *)(IColorCorrectionSystem *, int))colorcorrection->GetLookupWeight)(
         a1: colorcorrection,
         a2: 2);
  ConMsg(a1: "Weight 2       : %0.5f\n", v3);
  v4 = ((double (__thiscall *)(IColorCorrectionSystem *, int))colorcorrection->GetLookupWeight)(
         a1: colorcorrection,
         a2: 3);
  ConMsg(a1: "Weight 3       : %0.5f\n", v4);
}

//------------------------------------------------------------------------------
// Address: 0x100A1D10
// Name: public: virtual struct vgui::PanelMessageMap __near * CPrecisionSlider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPrecisionSlider::GetMessageMap(CPrecisionSlider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPrecisionSlider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPrecisionSlider::GetMessageMap'::`2'::s_pMap;
  `CPrecisionSlider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPrecisionSlider");
  `CPrecisionSlider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A1D40
// Name: public: virtual struct PanelAnimationMap __near * CPrecisionSlider::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPrecisionSlider::GetAnimMap(CPrecisionSlider *this)
{
  return FindOrAddPanelAnimationMap(className: "CPrecisionSlider");
}

//------------------------------------------------------------------------------
// Address: 0x100A1D50
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPrecisionSlider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPrecisionSlider::GetKBMap(CPrecisionSlider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPrecisionSlider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPrecisionSlider::GetKBMap'::`2'::s_pMap;
  `CPrecisionSlider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPrecisionSlider");
  `CPrecisionSlider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A1DC0
// Name: protected: virtual void CPrecisionSlider::OnMouseWheeled(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPrecisionSlider::OnMouseWheeled(CPrecisionSlider *this@<ecx>, int a2@<edi>, int delta)
{
  int v4; // edi

  vgui::Panel::OnMouseWheeled(this, delta);
  if ( this->IsEnabled(this) )
  {
    v4 = ((int (__thiscall *)(CPrecisionSlider *, int))this->GetValue)(a1: this, a2);
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
      || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL) )
    {
      ((void (__thiscall *)(CPrecisionSlider *, int))this->SetValue)(a1: this, a2: v4 + 4 * delta);
    }
    else
    {
      ((void (__thiscall *)(CPrecisionSlider *, int))this->SetValue)(a1: this, a2: delta + v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A1E50
// Name: ComputeSplinePoint
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeSplinePoint(const Vector **pControlPoints@<edi>, Vector *vecOut@<esi>, float flInColor)
{
  Vector *v3; // ecx
  Vector *v4; // edx
  float x; // xmm1_4
  float v6; // xmm1_4
  float t; // [esp+8h] [ebp-Ch]
  float v8; // [esp+Ch] [ebp-8h]
  float flStart; // [esp+10h] [ebp-4h]

  v3 = (Vector *)pControlPoints[2];
  v4 = (Vector *)pControlPoints[1];
  x = v3->x;
  if ( v3->x == v4->x )
  {
    vecOut->x = v4->x + x;
    v6 = vecOut->x;
    vecOut->y = v4->y + v3->y;
    vecOut->z = v4->z + v3->z;
    vecOut->x = v6 * 0.5;
    vecOut->y = vecOut->y * 0.5;
    vecOut->z = vecOut->z * 0.5;
  }
  else
  {
    t = 0.0;
    v8 = 1.0;
    flStart = (float)(flInColor - v4->x) / (float)(x - v4->x);
    Catmull_Rom_Spline(p1: *pControlPoints, p2: v4, p3: v3, p4: pControlPoints[3], t: flStart, output: vecOut);
    while ( fabs(vecOut->x - flInColor) >= 0.00001 )
    {
      if ( vecOut->x <= flInColor )
        t = flStart;
      else
        v8 = flStart;
      flStart = (v8 + t) * 0.5;
      Catmull_Rom_Spline(
        p1: *pControlPoints,
        p2: pControlPoints[1],
        p3: pControlPoints[2],
        p4: pControlPoints[3],
        t: flStart,
        output: vecOut);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A1F80
// Name: public: virtual struct vgui::PanelMessageMap __near * CColorCorrectionUIChildPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CColorCorrectionUIChildPanel::GetMessageMap(CColorCorrectionUIChildPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CColorCorrectionUIChildPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorCorrectionUIChildPanel::GetMessageMap'::`2'::s_pMap;
  `CColorCorrectionUIChildPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CColorCorrectionUIChildPanel");
  `CColorCorrectionUIChildPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A1FB0
// Name: public: virtual struct PanelAnimationMap __near * CColorCorrectionUIChildPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CColorCorrectionUIChildPanel::GetAnimMap(CColorCorrectionUIChildPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CColorCorrectionUIChildPanel");
}

//------------------------------------------------------------------------------
// Address: 0x100A1FC0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CColorCorrectionUIChildPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CColorCorrectionUIChildPanel::GetKBMap(CColorCorrectionUIChildPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CColorCorrectionUIChildPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorCorrectionUIChildPanel::GetKBMap'::`2'::s_pMap;
  `CColorCorrectionUIChildPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CColorCorrectionUIChildPanel");
  `CColorCorrectionUIChildPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A1FF0
// Name: public: CColorCorrectionUIChildPanel::CColorCorrectionUIChildPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CColorCorrectionUIChildPanel *__thiscall CColorCorrectionUIChildPanel::CColorCorrectionUIChildPanel(
        CColorCorrectionUIChildPanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Frame::Frame(this, parent, panelName: name, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CColorCorrectionUIChildPanel_vtbl *)&CColorCorrectionUIChildPanel::`vftable';
  if ( `CColorCorrectionUIChildPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CColorCorrectionUIChildPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CColorCorrectionUIChildPanel");
    v4->pfnClassName = CColorCorrectionUIChildPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CColorCorrectionUIChildPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CColorCorrectionUIChildPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CColorCorrectionUIChildPanel");
    v5->pfnClassName = CColorCorrectionUIChildPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CColorCorrectionUIChildPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CColorCorrectionUIChildPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CColorCorrectionUIChildPanel");
    v6->pfnClassName = CColorCorrectionUIChildPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A20C0
// Name: public: virtual void CCurvesColorOperation::Apply(class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurvesColorOperation::Apply(CCurvesColorOperation *this, const Vector *inRGB, Vector *outRGB)
{
  double x; // st7
  Vector *v4; // edx
  double y; // st7
  double z; // st7
  float v7; // xmm2_4
  float m_flBlendFactor; // xmm0_4

  if ( this->m_bEnable )
  {
    x = inRGB->x;
    if ( (this->m_nChannelMask & 1) != 0 )
      x = CLevelsColorOperation::ComputeCorrectedLevel((CLevelsColorOperation *)this, flInLevel: inRGB->x);
    v4 = outRGB;
    outRGB->x = x;
    y = inRGB->y;
    if ( (this->m_nChannelMask & 2) != 0 )
      y = CLevelsColorOperation::ComputeCorrectedLevel((CLevelsColorOperation *)this, flInLevel: inRGB->y);
    v4->y = y;
    z = inRGB->z;
    if ( (this->m_nChannelMask & 4) != 0 )
      z = CLevelsColorOperation::ComputeCorrectedLevel((CLevelsColorOperation *)this, flInLevel: inRGB->z);
    v7 = v4->x;
    v4->z = z;
    m_flBlendFactor = this->m_flBlendFactor;
    v4->x = (float)((float)(v7 - inRGB->x) * m_flBlendFactor) + inRGB->x;
    v4->y = (float)((float)(v4->y - inRGB->y) * m_flBlendFactor) + inRGB->y;
    v4->z = (float)((float)(v4->z - inRGB->z) * m_flBlendFactor) + inRGB->z;
  }
  else
  {
    *outRGB = *inRGB;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A2190
// Name: public: virtual struct vgui::PanelMessageMap __near * CColorCurvesEditPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CColorCurvesEditPanel::GetMessageMap(CColorCurvesEditPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CColorCurvesEditPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorCurvesEditPanel::GetMessageMap'::`2'::s_pMap;
  `CColorCurvesEditPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CColorCurvesEditPanel");
  `CColorCurvesEditPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A21C0
// Name: public: virtual struct PanelAnimationMap __near * CColorCurvesEditPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CColorCurvesEditPanel::GetAnimMap(CColorCurvesEditPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CColorCurvesEditPanel");
}

//------------------------------------------------------------------------------
// Address: 0x100A21D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CColorCurvesEditPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CColorCurvesEditPanel::GetKBMap(CColorCurvesEditPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CColorCurvesEditPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorCurvesEditPanel::GetKBMap'::`2'::s_pMap;
  `CColorCurvesEditPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CColorCurvesEditPanel");
  `CColorCurvesEditPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A2200
// Name: public: CColorCurvesEditPanel::CColorCurvesEditPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CColorCurvesEditPanel *__thiscall CColorCurvesEditPanel::CColorCurvesEditPanel(
        CColorCurvesEditPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CCurveEditorPanel::CCurveEditorPanel(this, pParent, pName);
  this->__vftable = (CColorCurvesEditPanel_vtbl *)&CColorCurvesEditPanel::`vftable';
  if ( `CColorCurvesEditPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CColorCurvesEditPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CColorCurvesEditPanel");
    v4->pfnClassName = CColorCurvesEditPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CCurveEditorPanel");
  }
  if ( `CColorCurvesEditPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CColorCurvesEditPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CColorCurvesEditPanel");
    v5->pfnClassName = CColorCurvesEditPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CCurveEditorPanel");
  }
  if ( `CColorCurvesEditPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CColorCurvesEditPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CColorCurvesEditPanel");
    v6->pfnClassName = CColorCurvesEditPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CCurveEditorPanel");
  }
  this->m_pCurvesOp = nullptr;
  vgui::Panel::SetVisible(this, state: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A2300
// Name: protected: virtual float CColorCurvesEditPanel::GetValue(float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CColorCurvesEditPanel::GetValue(CColorCurvesEditPanel *this, float flIn)
{
  CCurvesColorOperation *m_pCurvesOp; // ecx
  int v3; // eax

  m_pCurvesOp = this->m_pCurvesOp;
  v3 = (int)(float)(flIn * 255.0);
  if ( v3 < 0 )
  {
    v3 = 0;
    return (float)((float)((float)(m_pCurvesOp->m_pOutValue[v3 + 1] - m_pCurvesOp->m_pOutValue[v3])
                         * (float)((float)(flIn * 255.0) - (float)v3))
                 + m_pCurvesOp->m_pOutValue[v3]);
  }
  if ( v3 <= 254 )
    return (float)((float)((float)(m_pCurvesOp->m_pOutValue[v3 + 1] - m_pCurvesOp->m_pOutValue[v3])
                         * (float)((float)(flIn * 255.0) - (float)v3))
                 + m_pCurvesOp->m_pOutValue[v3]);
  return m_pCurvesOp->m_pOutValue[255];
}

//------------------------------------------------------------------------------
// Address: 0x100A2370
// Name: protected: virtual int CColorCurvesEditPanel::ControlPointCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CColorCurvesEditPanel::ControlPointCount(CColorCurvesEditPanel *this)
{
  return this->m_pCurvesOp->m_ControlPoints.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100A2380
// Name: public: virtual struct vgui::PanelMessageMap __near * CColorCurvesUIPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CColorCurvesUIPanel::GetMessageMap(CColorCurvesUIPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CColorCurvesUIPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorCurvesUIPanel::GetMessageMap'::`2'::s_pMap;
  `CColorCurvesUIPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CColorCurvesUIPanel");
  `CColorCurvesUIPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A23B0
// Name: public: virtual struct PanelAnimationMap __near * CColorCurvesUIPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CColorCurvesUIPanel::GetAnimMap(CColorCurvesUIPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CColorCurvesUIPanel");
}

//------------------------------------------------------------------------------
// Address: 0x100A23C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CColorCurvesUIPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CColorCurvesUIPanel::GetKBMap(CColorCurvesUIPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CColorCurvesUIPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorCurvesUIPanel::GetKBMap'::`2'::s_pMap;
  `CColorCurvesUIPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CColorCurvesUIPanel");
  `CColorCurvesUIPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A2440
// Name: private: void CLevelsColorOperation::UpdateOutputLevelArray(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLevelsColorOperation::UpdateOutputLevelArray(CLevelsColorOperation *this)
{
  float v2; // ecx
  float x; // eax
  float m_flMinInputLevel; // xmm4_4
  float v5; // xmm2_4
  float y; // xmm2_4
  float m_flMaxInputLevel; // xmm3_4
  float m_flMidInputLevel; // xmm1_4
  float v9; // xmm1_4
  float flInColor[3]; // [esp+0h] [ebp-58h] BYREF
  float v11; // [esp+Ch] [ebp-4Ch] BYREF
  int v12; // [esp+10h] [ebp-48h]
  int v13; // [esp+14h] [ebp-44h]
  float v14; // [esp+18h] [ebp-40h] BYREF
  int v15; // [esp+1Ch] [ebp-3Ch]
  int v16; // [esp+20h] [ebp-38h]
  _DWORD v17[3]; // [esp+24h] [ebp-34h] BYREF
  Vector *v18[4]; // [esp+30h] [ebp-28h] BYREF
  Vector pControlPoints; // [esp+40h] [ebp-18h] BYREF
  float v20; // [esp+4Ch] [ebp-Ch]
  Vector vecOut; // [esp+50h] [ebp-8h]

  v2 = 0.0;
  LODWORD(x) = this->m_pOutValue;
  vecOut.y = 0.0;
  LODWORD(vecOut.x) = this->m_pOutValue;
  do
  {
    m_flMinInputLevel = this->m_flMinInputLevel;
    v5 = (float)SLODWORD(v2) * 0.0039215689;
    v20 = v5;
    if ( m_flMinInputLevel < v5 )
    {
      m_flMaxInputLevel = this->m_flMaxInputLevel;
      if ( v5 < m_flMaxInputLevel )
      {
        m_flMidInputLevel = this->m_flMidInputLevel;
        flInColor[0] = m_flMinInputLevel;
        flInColor[1] = 0.0;
        flInColor[2] = 0.0;
        *(float *)v17 = m_flMaxInputLevel;
        v17[1] = 1065353216;
        v17[2] = 0;
        v13 = 0;
        v16 = 0;
        if ( m_flMidInputLevel <= v5 )
        {
          v11 = m_flMidInputLevel;
          v12 = 1056964608;
          v14 = m_flMaxInputLevel;
          v15 = 1065353216;
        }
        else
        {
          v11 = m_flMinInputLevel;
          v12 = 0;
          v14 = m_flMidInputLevel;
          v15 = 1056964608;
        }
        v18[0] = (Vector *)flInColor;
        v18[1] = (Vector *)&v11;
        v18[2] = (Vector *)&v14;
        v18[3] = (Vector *)v17;
        ComputeSplinePoint(flInColor: v20, pControlPoints: v18, vecOut: &pControlPoints);
        y = pControlPoints.y;
        x = vecOut.x;
        v2 = vecOut.y;
      }
      else
      {
        y = 1.0;
      }
    }
    else
    {
      y = 0.0;
    }
    *(float *)LODWORD(x) = y;
    v9 = (float)(this->m_flMaxOutputLevel - this->m_flMinOutputLevel) * y;
    *(float *)LODWORD(x) = v9;
    ++LODWORD(v2);
    *(float *)LODWORD(x) = this->m_flMinOutputLevel + v9;
    LODWORD(x) += 4;
    vecOut.y = v2;
    vecOut.x = x;
  }
  while ( SLODWORD(v2) < 256 );
}

//------------------------------------------------------------------------------
// Address: 0x100A25B0
// Name: private: float CLevelsColorOperation::ComputeCorrectedLevel(float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CLevelsColorOperation::ComputeCorrectedLevel(CLevelsColorOperation *this, float flInLevel)
{
  int v2; // eax
  double v3; // st7
  int v5; // [esp+0h] [ebp-4h]
  float v6; // [esp+Ch] [ebp+8h]

  v2 = (int)(float)(flInLevel * 255.0);
  v6 = flInLevel * 255.0;
  if ( v2 < 0 )
  {
    v2 = 0;
    v5 = 0;
LABEL_3:
    v3 = this->m_pOutValue[v2];
    return v3 + (this->m_pOutValue[v2 + 1] - v3) * (v6 - (double)v5);
  }
  if ( v2 <= 255 )
  {
    v5 = v2;
    if ( v2 != 255 )
      goto LABEL_3;
  }
  return this->m_pOutValue[255];
}

//------------------------------------------------------------------------------
// Address: 0x100A2610
// Name: public: virtual void CLevelsColorOperation::Apply(class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLevelsColorOperation::Apply(CLevelsColorOperation *this, const Vector *inRGB, Vector *outRGB)
{
  double x; // st7
  Vector *v4; // edx
  double y; // st7
  double z; // st7
  float v7; // xmm2_4
  float m_flBlendFactor; // xmm0_4

  if ( this->m_bEnable )
  {
    x = inRGB->x;
    if ( (this->m_nChannelMask & 1) != 0 )
      x = CLevelsColorOperation::ComputeCorrectedLevel(this, flInLevel: inRGB->x);
    v4 = outRGB;
    outRGB->x = x;
    y = inRGB->y;
    if ( (this->m_nChannelMask & 2) != 0 )
      y = CLevelsColorOperation::ComputeCorrectedLevel(this, flInLevel: inRGB->y);
    v4->y = y;
    z = inRGB->z;
    if ( (this->m_nChannelMask & 4) != 0 )
      z = CLevelsColorOperation::ComputeCorrectedLevel(this, flInLevel: inRGB->z);
    v7 = v4->x;
    v4->z = z;
    m_flBlendFactor = this->m_flBlendFactor;
    v4->x = (float)((float)(v7 - inRGB->x) * m_flBlendFactor) + inRGB->x;
    v4->y = (float)((float)(v4->y - inRGB->y) * m_flBlendFactor) + inRGB->y;
    v4->z = (float)((float)(v4->z - inRGB->z) * m_flBlendFactor) + inRGB->z;
  }
  else
  {
    *outRGB = *inRGB;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A26E0
// Name: public: virtual struct vgui::PanelMessageMap __near * CColorHistogramPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CColorHistogramPanel::GetMessageMap(CColorHistogramPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CColorHistogramPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorHistogramPanel::GetMessageMap'::`2'::s_pMap;
  `CColorHistogramPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CColorHistogramPanel");
  `CColorHistogramPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A2710
// Name: public: virtual struct PanelAnimationMap __near * CColorHistogramPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CColorHistogramPanel::GetAnimMap(CColorHistogramPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CColorHistogramPanel");
}

//------------------------------------------------------------------------------
// Address: 0x100A2720
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CColorHistogramPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CColorHistogramPanel::GetKBMap(CColorHistogramPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CColorHistogramPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorHistogramPanel::GetKBMap'::`2'::s_pMap;
  `CColorHistogramPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CColorHistogramPanel");
  `CColorHistogramPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A2750
// Name: public: CColorHistogramPanel::CColorHistogramPanel(class vgui::Panel __near *,char const __near *,class CLevelsColorOperation __near *)
// Source: json
//------------------------------------------------------------------------------
CColorHistogramPanel *__thiscall CColorHistogramPanel::CColorHistogramPanel(
        CColorHistogramPanel *this,
        vgui::Panel *pParent,
        const char *pName,
        CLevelsColorOperation *pOp)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::Panel::Panel(this, parent: pParent, panelName: pName);
  this->__vftable = (CColorHistogramPanel_vtbl *)&CColorHistogramPanel::`vftable';
  if ( `CColorHistogramPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CColorHistogramPanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CColorHistogramPanel");
    v5->pfnClassName = CColorHistogramPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CColorHistogramPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CColorHistogramPanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CColorHistogramPanel");
    v6->pfnClassName = CColorHistogramPanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CColorHistogramPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CColorHistogramPanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CColorHistogramPanel");
    v7->pfnClassName = CColorHistogramPanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  memset(this->m_pHistogram, 0, sizeof(this->m_pHistogram));
  this->m_Type = RGB;
  this->m_pOp = pOp;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A2860
// Name: public: virtual void CColorHistogramPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorHistogramPanel::Paint(CColorHistogramPanel *this)
{
  float m_flMax; // xmm1_4
  float v3; // xmm0_4
  int v4; // esi
  int v5; // [esp-Ch] [ebp-2Ch]
  int v6; // [esp-8h] [ebp-28h]
  int h; // [esp+10h] [ebp-10h] BYREF
  int w; // [esp+14h] [ebp-Ch] BYREF
  float flOOMax; // [esp+18h] [ebp-8h]
  float *m_pHistogram; // [esp+1Ch] [ebp-4h]

  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  switch ( this->m_Type )
  {
    case 0:
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 0, a4: 0, a5: 255);
      break;
    case 1:
      v6 = 0;
      v5 = 255;
      goto LABEL_7;
    case 2:
      v6 = 255;
      goto LABEL_6;
    case 3:
      v6 = 0;
LABEL_6:
      v5 = 0;
LABEL_7:
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 0, a3: v5, a4: v6, a5: 255);
      break;
    default:
      break;
  }
  m_flMax = this->m_flMax;
  v3 = 1.0;
  if ( m_flMax != 0.0 )
    v3 = 1.0 / m_flMax;
  v4 = 0;
  flOOMax = v3;
  m_pHistogram = this->m_pHistogram;
  while ( 1 )
  {
    g_pVGuiSurface->DrawLine(
      this: g_pVGuiSurface,
      a2: (int)(float)((float)((float)(w - 1) * (float)v4) * 0.0039215689),
      a3: h - 1,
      a4: (int)(float)((float)((float)(w - 1) * (float)v4) * 0.0039215689),
      a5: h - (int)(float)((float)((float)(h - 1) * *m_pHistogram++) * v3) - 1);
    if ( ++v4 >= 256 )
      break;
    v3 = flOOMax;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A2990
// Name: public: virtual struct vgui::PanelMessageMap __near * CColorSlider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CColorSlider::GetMessageMap(CColorSlider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CColorSlider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorSlider::GetMessageMap'::`2'::s_pMap;
  `CColorSlider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CColorSlider");
  `CColorSlider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A29C0
// Name: public: virtual struct PanelAnimationMap __near * CColorSlider::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CColorSlider::GetAnimMap(CColorSlider *this)
{
  return FindOrAddPanelAnimationMap(className: "CColorSlider");
}

//------------------------------------------------------------------------------
// Address: 0x100A29D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CColorSlider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CColorSlider::GetKBMap(CColorSlider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CColorSlider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorSlider::GetKBMap'::`2'::s_pMap;
  `CColorSlider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CColorSlider");
  `CColorSlider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A2A00
// Name: public: CColorSlider::CColorSlider(class vgui::Panel __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CColorSlider *__thiscall CColorSlider::CColorSlider(
        CColorSlider *this,
        vgui::Panel *pParent,
        const char *pName,
        int nKnobCount)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  int v8; // eax

  vgui::Panel::Panel(this, parent: pParent, panelName: pName);
  this->__vftable = (CColorSlider_vtbl *)&CColorSlider::`vftable';
  if ( `CColorSlider::ChainToMap'::`2'::chained == 0 )
  {
    `CColorSlider::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CColorSlider");
    v5->pfnClassName = CColorSlider::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CColorSlider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CColorSlider::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CColorSlider");
    v6->pfnClassName = CColorSlider::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CColorSlider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CColorSlider::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CColorSlider");
    v7->pfnClassName = CColorSlider::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  this->m_flKnobPosition[0] = 0.0;
  this->m_flKnobPosition[1] = 1.0;
  this->m_nKnobCount = nKnobCount;
  *(_QWORD *)&this->m_flKnobPosition[2] = 1056964608;
  this->m_nMaxValue = 1;
  this->m_nSelectedKnob = -1;
  v8 = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
  this->m_nWhiteMaterial = v8;
  g_pVGuiSurface->DrawSetTextureFile(this: g_pVGuiSurface, a2: v8, a3: "vgui/white", a4: 1, a5: false);
  vgui::Panel::SetMouseInputEnabled(this, state: 1);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A2B80
// Name: public: void CColorSlider::SetNormalizedValue(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorSlider::SetNormalizedValue(CColorSlider *this, int nKnobIndex, float flValue)
{
  float v3; // xmm0_4
  bool v5; // cc
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  v3 = 0.0;
  if ( flValue >= 0.0 )
  {
    v3 = 1.0;
    if ( flValue <= 1.0 )
      v3 = flValue;
  }
  this->m_flKnobPosition[nKnobIndex] = v3;
  if ( nKnobIndex != 0 )
  {
    if ( nKnobIndex != 1 )
    {
      if ( nKnobIndex == 2 )
      {
        if ( this->m_flKnobPosition[0] > v3 )
          this->m_flKnobPosition[0] = v3;
        if ( v3 > this->m_flKnobPosition[1] )
          this->m_flKnobPosition[1] = v3;
      }
      goto LABEL_19;
    }
    if ( this->m_flKnobPosition[0] > v3 )
      this->m_flKnobPosition[0] = v3;
    v5 = this->m_flKnobPosition[2] <= v3;
  }
  else
  {
    if ( v3 > this->m_flKnobPosition[1] )
      this->m_flKnobPosition[1] = v3;
    v5 = v3 <= this->m_flKnobPosition[2];
  }
  if ( !v5 )
    this->m_flKnobPosition[2] = v3;
LABEL_19:
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
  {
    v7 = KeyValues::KeyValues(this: v6, setName: "SliderMoved", firstKey: "knob", firstValue: nKnobIndex);
    this->PostActionSignal(this, a2: v7);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A2C80
// Name: public: virtual void CColorSlider::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorSlider::OnMousePressed(CColorSlider *this, const char *code)
{
  const char *v2; // edi
  vgui::IInput *v4; // ebx
  vgui::IInput_vtbl *v5; // edi
  int v6; // eax
  float v7; // xmm0_4
  int v8; // edi
  int v9; // ecx
  int tall[2]; // [esp+Ch] [ebp-10h] BYREF
  int wide; // [esp+14h] [ebp-8h] BYREF
  int v12; // [esp+18h] [ebp-4h] BYREF

  v2 = code;
  CBaseServer::RemoveClientFromGame(this, panelName: code);
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: (int *)&code, a3: &v12);
  vgui::Panel::ScreenToLocal(this, x: (int *)&code, y: &v12);
  if ( v2 == (const char *)107 )
  {
    v4 = g_pVGuiInput;
    v5 = g_pVGuiInput->__vftable;
    v6 = this->GetVPanel(this);
    v5->SetMouseCapture(this: v4, a2: v6);
    vgui::Panel::GetSize(this, &wide, tall);
    v7 = (float)(int)code / (float)(wide - 1);
    v8 = 0;
    v9 = 1;
    *(float *)&tall[1] = v7;
    for ( this->m_nSelectedKnob = 0; v9 < this->m_nKnobCount; ++v9 )
    {
      if ( fabs(v7 - this->m_flKnobPosition[v8]) > fabs(v7 - this->m_flKnobPosition[v9]) )
      {
        v8 = v9;
        this->m_nSelectedKnob = v9;
      }
    }
    CColorSlider::SetNormalizedValue(this, nKnobIndex: this->m_nSelectedKnob, flValue: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A2D70
// Name: public: virtual void CColorSlider::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorSlider::OnMouseReleased(CColorSlider *this, const char *code)
{
  CBaseServer::RemoveClientFromGame(this, panelName: code);
  if ( code == (const char *)107 && this->m_nSelectedKnob >= 0 )
  {
    g_pVGuiInput->SetMouseCapture(this: g_pVGuiInput, a2: 0);
    this->m_nSelectedKnob = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A2DB0
// Name: public: virtual void CColorSlider::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorSlider::OnCursorMoved(CColorSlider *this, int x, int y)
{
  int v3; // edi
  int m_nSelectedKnob; // eax
  float v6; // xmm0_4
  int v7; // xmm1_4
  KeyValues *v8; // eax
  KeyValues *v9; // eax
  int tall; // [esp+Ch] [ebp-8h] BYREF
  int h; // [esp+10h] [ebp-4h]

  v3 = x;
  CColorBalanceUIPanel::ReadUncorrectedImage((vgui::TreeView *)this, itemIndex: x, msg: (KeyValues *)y);
  if ( this->m_nSelectedKnob >= 0 )
  {
    vgui::Panel::GetSize(this, wide: &x, &tall);
    m_nSelectedKnob = this->m_nSelectedKnob;
    *(float *)&y = (float)v3 / (float)(x - 1);
    if ( m_nSelectedKnob < 2 && this->m_nKnobCount == 3 )
    {
      *(float *)&h = (float)(this->m_flKnobPosition[2] - this->m_flKnobPosition[0])
                   / (float)(this->m_flKnobPosition[1] - this->m_flKnobPosition[0]);
      CColorSlider::SetNormalizedValue(this, nKnobIndex: m_nSelectedKnob, flValue: *(float *)&y);
      v6 = (float)((float)(this->m_flKnobPosition[1] - this->m_flKnobPosition[0]) * *(float *)&h)
         + this->m_flKnobPosition[0];
      v7 = 0;
      if ( v6 < 0.0 || (v7 = 1065353216, v6 > 1.0) )
        v6 = *(float *)&v7;
      this->m_flKnobPosition[2] = v6;
      if ( this->m_flKnobPosition[0] > v6 )
        this->m_flKnobPosition[0] = v6;
      if ( v6 > this->m_flKnobPosition[1] )
        this->m_flKnobPosition[1] = v6;
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
      {
        v9 = KeyValues::KeyValues(this: v8, setName: "SliderMoved", firstKey: "knob", firstValue: 2);
        this->PostActionSignal(this, a2: v9);
      }
      else
      {
        this->PostActionSignal(this, a2: nullptr);
      }
    }
    else
    {
      CColorSlider::SetNormalizedValue(this, nKnobIndex: m_nSelectedKnob, flValue: *(float *)&y);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A2F20
// Name: private: void CColorSlider::PaintKnob(float,unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorSlider::PaintKnob(
        CColorSlider *this,
        float flPosition,
        unsigned __int8 r,
        unsigned __int8 g,
        unsigned __int8 b)
{
  float v6; // xmm2_4
  FontVertex_t triangle[3]; // [esp+4h] [ebp-38h] BYREF
  int h; // [esp+34h] [ebp-8h] BYREF
  int w; // [esp+38h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  v6 = (float)(h - 1);
  triangle[0].m_Position.x = (float)(w - 1) * flPosition;
  triangle[0].m_Position.y = 0.0;
  triangle[0].m_TexCoord.x = 0.0;
  triangle[0].m_TexCoord.y = 0.0;
  triangle[1].m_Position.x = v6 + triangle[0].m_Position.x;
  triangle[1].m_Position.y = v6;
  triangle[1].m_TexCoord.x = 0.0;
  triangle[1].m_TexCoord.y = 0.0;
  triangle[2].m_Position.x = triangle[0].m_Position.x - v6;
  triangle[2].m_Position.y = v6;
  triangle[2].m_TexCoord.x = 0.0;
  triangle[2].m_TexCoord.y = 0.0;
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: 255);
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_nWhiteMaterial);
  g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: triangle, a4: true);
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 0, a3: 0, a4: 0, a5: 255);
  g_pVGuiSurface->DrawTexturedPolyLine(this: g_pVGuiSurface, a2: triangle, a3: 3);
}

//------------------------------------------------------------------------------
// Address: 0x100A3030
// Name: public: virtual void CColorSlider::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorSlider::Paint(CColorSlider *this)
{
  CColorSlider::PaintKnob(this, flPosition: this->m_flKnobPosition[0], r: 0, g: 0, b: 0);
  if ( this->m_nKnobCount == 3 )
    CColorSlider::PaintKnob(this, flPosition: this->m_flKnobPosition[2], r: 0x80u, g: 0x80u, b: 0x80u);
  CColorSlider::PaintKnob(this, flPosition: this->m_flKnobPosition[1], r: 0xFFu, g: 0xFFu, b: 0xFFu);
}

//------------------------------------------------------------------------------
// Address: 0x100A30A0
// Name: public: virtual void CColorCurvesUIPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCurvesUIPanel::OnCommand(CColorLevelsUIPanel *this, const char *command)
{
  float v3; // xmm0_4
  float commanda; // [esp+10h] [ebp+8h]

  vgui::Frame::OnCommand(this, command);
  if ( _V_stricmp(s1: "BlendFactorUpdate", s2: command) == 0 )
  {
    if ( this->m_pLevelsOp != nullptr )
    {
      commanda = this->m_pLevelsOp->GetBlendFactor(this: this->m_pLevelsOp);
      v3 = commanda;
    }
    else
    {
      v3 = 0.0;
    }
    this->m_pBlendFactorSlider->SetValue(this: this->m_pBlendFactorSlider, a2: (int)(float)(v3 * 255.0), a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A3110
// Name: public: virtual struct vgui::PanelMessageMap __near * CFullScreenSelectionPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CFullScreenSelectionPanel::GetMessageMap(CFullScreenSelectionPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CFullScreenSelectionPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CFullScreenSelectionPanel::GetMessageMap'::`2'::s_pMap;
  `CFullScreenSelectionPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CFullScreenSelectionPanel");
  `CFullScreenSelectionPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A3140
// Name: public: virtual struct PanelAnimationMap __near * CFullScreenSelectionPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CFullScreenSelectionPanel::GetAnimMap(CFullScreenSelectionPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CFullScreenSelectionPanel");
}

//------------------------------------------------------------------------------
// Address: 0x100A3150
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CFullScreenSelectionPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CFullScreenSelectionPanel::GetKBMap(CFullScreenSelectionPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CFullScreenSelectionPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CFullScreenSelectionPanel::GetKBMap'::`2'::s_pMap;
  `CFullScreenSelectionPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CFullScreenSelectionPanel");
  `CFullScreenSelectionPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A3180
// Name: public: CFullScreenSelectionPanel::CFullScreenSelectionPanel(char const __near *,class CSelectedHSVOperation __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CFullScreenSelectionPanel *__thiscall CFullScreenSelectionPanel::CFullScreenSelectionPanel(
        CFullScreenSelectionPanel *this,
        const char *pName,
        CSelectedHSVOperation *pOp,
        vgui::Panel *pParent)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::Panel::Panel(this, parent: pParent, panelName: pName);
  this->__vftable = (CFullScreenSelectionPanel_vtbl *)&CFullScreenSelectionPanel::`vftable';
  if ( `CFullScreenSelectionPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CFullScreenSelectionPanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CFullScreenSelectionPanel");
    v5->pfnClassName = CFullScreenSelectionPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CFullScreenSelectionPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CFullScreenSelectionPanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CFullScreenSelectionPanel");
    v6->pfnClassName = CFullScreenSelectionPanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CFullScreenSelectionPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CFullScreenSelectionPanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CFullScreenSelectionPanel");
    v7->pfnClassName = CFullScreenSelectionPanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  this->m_bMouseDown = false;
  vgui::Panel::SetZPos(this, z: -1000);
  this->m_pOp = pOp;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A3290
// Name: public: virtual void CFullScreenSelectionPanel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFullScreenSelectionPanel::OnMousePressed(CFullScreenSelectionPanel *this, const char *code)
{
  int x; // [esp+4h] [ebp-8h] BYREF
  int y; // [esp+8h] [ebp-4h] BYREF

  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  this->m_bMouseDown = true;
  CBaseServer::RemoveClientFromGame(this, panelName: code);
}

//------------------------------------------------------------------------------
// Address: 0x100A32D0
// Name: public: virtual void CFullScreenSelectionPanel::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFullScreenSelectionPanel::OnMouseReleased(CFullScreenSelectionPanel *this, const char *code)
{
  int x; // [esp+4h] [ebp-8h] BYREF
  int y; // [esp+8h] [ebp-4h] BYREF

  this->m_bMouseDown = false;
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  CBaseServer::RemoveClientFromGame(this, panelName: code);
}

//------------------------------------------------------------------------------
// Address: 0x100A3310
// Name: public: virtual struct vgui::PanelMessageMap __near * CUncorrectedImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CUncorrectedImagePanel::GetMessageMap(CUncorrectedImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CUncorrectedImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CUncorrectedImagePanel::GetMessageMap'::`2'::s_pMap;
  `CUncorrectedImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CUncorrectedImagePanel");
  `CUncorrectedImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A3340
// Name: public: virtual struct PanelAnimationMap __near * CUncorrectedImagePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CUncorrectedImagePanel::GetAnimMap(CUncorrectedImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CUncorrectedImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x100A3350
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CUncorrectedImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CUncorrectedImagePanel::GetKBMap(CUncorrectedImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CUncorrectedImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CUncorrectedImagePanel::GetKBMap'::`2'::s_pMap;
  `CUncorrectedImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CUncorrectedImagePanel");
  `CUncorrectedImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A3380
// Name: public: CUncorrectedImagePanel::CUncorrectedImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUncorrectedImagePanel *__thiscall CUncorrectedImagePanel::CUncorrectedImagePanel(
        CUncorrectedImagePanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CProceduralTexturePanel::CProceduralTexturePanel(this, pParent, pName);
  this->CProceduralTexturePanel::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CUncorrectedImagePanel_vtbl *)&CUncorrectedImagePanel::`vftable'{for `vgui::EditablePanel'};
  this->CProceduralTexturePanel::ITextureRegenerator::__vftable = (ITextureRegenerator_vtbl *)&CUncorrectedImagePanel::`vftable'{for `ITextureRegenerator'};
  if ( `CUncorrectedImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CUncorrectedImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CUncorrectedImagePanel");
    v4->pfnClassName = CUncorrectedImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CProceduralTexturePanel");
  }
  if ( `CUncorrectedImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CUncorrectedImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CUncorrectedImagePanel");
    v5->pfnClassName = CUncorrectedImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CProceduralTexturePanel");
  }
  if ( `CUncorrectedImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CUncorrectedImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CUncorrectedImagePanel");
    v6->pfnClassName = CUncorrectedImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CProceduralTexturePanel");
  }
  this->m_bMouseDown = false;
  vgui::Panel::SetMouseInputEnabled(this, state: 1);
  CProceduralTexturePanel::MaintainProportions(this, bEnable: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A34A0
// Name: public: virtual void CUncorrectedImagePanel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUncorrectedImagePanel::OnMousePressed(CUncorrectedImagePanel *this, const char *code)
{
  const char *v2; // edi
  int x; // [esp+8h] [ebp-4h] BYREF

  v2 = code;
  CBaseServer::RemoveClientFromGame(this, panelName: code);
  if ( v2 == (const char *)107 )
  {
    this->m_bMouseDown = true;
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: (int *)&code);
    vgui::Panel::ScreenToLocal(this, &x, y: (int *)&code);
    this->OnCursorMoved(this, a2: x, a3: (int)code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A3500
// Name: private: void CSelectedHSVUIPanel::PopulateControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectedHSVUIPanel::PopulateControls(CSelectedHSVUIPanel *this)
{
  const char **v2; // edi

  vgui::ComboBox::RemoveAll(this: this->m_pSelectionMethod);
  v2 = CSelectedHSVUIPanel::s_pSelectionMethodNames;
  do
    this->m_pSelectionMethod->AddItem_2(this: this->m_pSelectionMethod, a2: *v2++, a3: nullptr);
  while ( (int)v2 < (int)&colorcorrectiontools );
  this->m_pSelectionMethod->AddActionSignalTarget_2(this: this->m_pSelectionMethod, a2: this);
  this->m_pSelectionMethod->ActivateItem(this: this->m_pSelectionMethod, a2: this->m_pHSVOperation->m_SelectionMethod);
  this->m_pColorEntry1->SetText(this: this->m_pColorEntry1, a2: "0");
  this->m_pColorEntry2->SetText(this: this->m_pColorEntry2, a2: "0");
  this->m_pColorEntry3->SetText(this: this->m_pColorEntry3, a2: "0");
}

//------------------------------------------------------------------------------
// Address: 0x100A35B0
// Name: protected: virtual void CSelectedHSVUIPanel::OnTextChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectedHSVUIPanel::OnTextChanged(CSelectedHSVUIPanel *this, KeyValues *data)
{
  void *Ptr; // eax

  Ptr = KeyValues::GetPtr(this: data, keyName: "panel", defaultValue: nullptr);
  if ( __RTDynamicCast(
         inptr: Ptr,
         VfDelta: 0,
         SrcType: &vgui::Panel `RTTI Type Descriptor',
         TargetType: &vgui::ComboBox `RTTI Type Descriptor',
         isReference: 0) == this->m_pSelectionMethod )
    CSelectedHSVUIPanel::OnSelectionMethodSelected(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A35F0
// Name: public: virtual void CColorLookupOperation::Apply(class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorLookupOperation::Apply(CColorLookupOperation *this, const Vector *inRGB, Vector *outRGB)
{
  float v4; // xmm0_4
  float x; // xmm4_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  int v9; // edi
  float v10; // xmm2_4
  int v11; // ebx
  float v12; // xmm3_4
  float v13; // xmm7_4
  float v14; // xmm1_4
  float v15; // xmm5_4
  float v16; // xmm6_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm6_4
  float v20; // xmm2_4
  float v21; // xmm5_4
  float v22; // xmm3_4
  float v23; // xmm0_4
  float v24; // xmm3_4
  float m_flBlendFactor; // xmm0_4
  float y; // xmm1_4
  float v27; // xmm5_4
  float z; // xmm2_4
  float v29; // xmm6_4
  float v30; // xmm7_4
  float v31; // xmm0_4
  float v32; // xmm5_4
  float v33; // xmm3_4
  float v34; // xmm7_4
  float v35; // xmm1_4
  float v36; // xmm2_4
  Vector interp_cube[8]; // [esp+4h] [ebp-A4h] BYREF
  Vector b; // [esp+64h] [ebp-44h]
  Vector c; // [esp+70h] [ebp-38h]
  Vector bottom; // [esp+7Ch] [ebp-2Ch]
  int g; // [esp+88h] [ebp-20h]
  Vector d; // [esp+8Ch] [ebp-1Ch]
  float v43; // [esp+98h] [ebp-10h]
  float v44; // [esp+9Ch] [ebp-Ch]
  float v45; // [esp+A0h] [ebp-8h]
  int ib; // [esp+A4h] [ebp-4h]

  if ( this->m_LookupTable != nullptr && this->m_bEnable )
  {
    v4 = (float)(this->m_Resolution - 1);
    x = inRGB->x;
    v6 = inRGB->x * v4;
    v7 = v4 * inRGB->y;
    v8 = v4 * inRGB->z;
    v9 = (int)v6;
    v10 = v6 - (float)(int)v6;
    v11 = (int)v7;
    v12 = v7 - (float)(int)v7;
    ib = (int)v8;
    v13 = v8 - (float)(int)v8;
    CColorLookupOperation::GetLookupValue(this, r: v9, g: v11, b: (int)v8, out: interp_cube);
    CColorLookupOperation::GetLookupValue(this, r: v9 + 1, g: v11, b: ib, out: &interp_cube[1]);
    g = v11 + 1;
    CColorLookupOperation::GetLookupValue(this, r: v9, g: v11 + 1, b: ib, out: &interp_cube[2]);
    CColorLookupOperation::GetLookupValue(this, r: v9 + 1, g, b: ib++, out: &interp_cube[3]);
    CColorLookupOperation::GetLookupValue(this, r: v9, g: v11, b: ib, out: &interp_cube[4]);
    CColorLookupOperation::GetLookupValue(this, r: v9 + 1, g: v11, b: ib, out: &interp_cube[5]);
    CColorLookupOperation::GetLookupValue(this, r: v9, g, b: ib, out: &interp_cube[6]);
    CColorLookupOperation::GetLookupValue(this, r: v9 + 1, g, b: ib, out: &interp_cube[7]);
    bottom.z = (float)((float)(1.0 - v10) * interp_cube[0].z) + (float)(interp_cube[1].z * v10);
    bottom.x = (float)((float)(1.0 - v10) * interp_cube[0].x) + (float)(interp_cube[1].x * v10);
    bottom.y = (float)((float)(1.0 - v10) * interp_cube[0].y) + (float)(interp_cube[1].y * v10);
    b.z = (float)((float)(1.0 - v10) * interp_cube[2].z) + (float)(interp_cube[3].z * v10);
    b.x = (float)((float)(1.0 - v10) * interp_cube[2].x) + (float)(interp_cube[3].x * v10);
    b.y = (float)((float)(1.0 - v10) * interp_cube[2].y) + (float)(interp_cube[3].y * v10);
    c.z = (float)((float)(1.0 - v10) * interp_cube[4].z) + (float)(interp_cube[5].z * v10);
    v45 = interp_cube[7].z * v10;
    v14 = (float)(1.0 - v10) * interp_cube[6].x;
    c.x = (float)((float)(1.0 - v10) * interp_cube[4].x) + (float)(interp_cube[5].x * v10);
    v15 = interp_cube[7].x * v10;
    c.y = (float)((float)(1.0 - v10) * interp_cube[4].y) + (float)(interp_cube[5].y * v10);
    v16 = interp_cube[7].y * v10;
    v17 = 1.0 - v10;
    d.z = (float)(v17 * interp_cube[6].z) + v45;
    v43 = b.x * v12;
    v44 = b.y * v12;
    v45 = b.z * v12;
    d.x = v14 + v15;
    bottom.z = (float)((float)(1.0 - v12) * bottom.z) + (float)(b.z * v12);
    bottom.x = (float)((float)(1.0 - v12) * bottom.x) + (float)(b.x * v12);
    v18 = (float)(v14 + v15) * v12;
    v19 = (float)(v16 + (float)(v17 * interp_cube[6].y)) * v12;
    bottom.y = (float)((float)(1.0 - v12) * bottom.y) + (float)(b.y * v12);
    v20 = d.z * v12;
    v21 = (float)(1.0 - v12) * c.y;
    v22 = 1.0 - v12;
    v23 = v22 * c.z;
    v24 = (float)(v22 * c.x) + v18;
    b.z = v23 + v20;
    m_flBlendFactor = this->m_flBlendFactor;
    d.x = x * m_flBlendFactor;
    y = inRGB->y;
    v27 = v21 + v19;
    d.y = y * m_flBlendFactor;
    z = inRGB->z;
    v29 = z * m_flBlendFactor;
    c.x = v24 * v13;
    c.y = v27 * v13;
    c.z = b.z * v13;
    v30 = 1.0 - v13;
    v31 = (float)(v30 * bottom.x) + c.x;
    v32 = (float)(bottom.y * v30) + c.y;
    v33 = bottom.z * v30;
    v34 = this->m_flBlendFactor;
    v35 = (float)(y + (float)(v32 * v34)) - d.y;
    v36 = (float)(z + (float)((float)(v33 + c.z) * v34)) - v29;
    outRGB->x = (float)(x + (float)(v31 * v34)) - d.x;
    outRGB->y = v35;
    outRGB->z = v36;
  }
  else
  {
    *outRGB = *inRGB;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A3A70
// Name: private: void CColorLookupOperation::SetResolution(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorLookupOperation::SetResolution(CColorLookupOperation *this, int res)
{
  color24 *v3; // eax
  color24 *m_LookupTable; // [esp-4h] [ebp-Ch]

  if ( this->m_LookupTable != nullptr )
  {
    m_LookupTable = this->m_LookupTable;
    this->m_Resolution = 0;
    free(pMem: m_LookupTable);
  }
  v3 = (color24 *)MemAlloc_Alloc(nSize: (3 * (unsigned __int64)(unsigned int)(res * res * res)) >> 32 != 0 ? -1 : 3 * res * res * res);
  this->m_Resolution = res;
  this->m_LookupTable = v3;
}

//------------------------------------------------------------------------------
// Address: 0x100A3AD0
// Name: public: virtual void CColorLookupUIPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorLookupUIPanel::OnCommand(CColorLookupUIPanel *this, const char *command)
{
  vgui::FileOpenDialog *v3; // eax
  vgui::FileOpenDialog *v4; // esi

  if ( V_strcasecmp(s1: command, s2: "LoadLookup") != 0 )
  {
    if ( _V_stricmp(s1: "BlendFactorUpdate", s2: command) == 0 )
      CColorLookupUIPanel::ResetBlendFactorSlider(this);
    vgui::Frame::OnCommand(this, command);
  }
  else
  {
    v3 = (vgui::FileOpenDialog *)MemAlloc_Alloc(nSize: 0x6B0u);
    if ( v3 != nullptr )
      v4 = vgui::FileOpenDialog::FileOpenDialog(
             this: v3,
             parent: this,
             title: "File Open",
             bOpenOnly: true,
             pContextKeyValues: nullptr);
    else
      v4 = nullptr;
    v4->AddActionSignalTarget_2(this: v4, a2: this);
    vgui::FileOpenDialog::AddFilter(
      this: v4,
      filter: "*.raw",
      filterName: ".RAW files",
      bActive: true,
      pFilterInfo: nullptr);
    vgui::FileOpenDialog::DoModal(this: v4, bUnused: true);
    vgui::Frame::OnCommand(this, command);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A3B80
// Name: private: void CColorBalanceOperation::CreateLookupTables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorBalanceOperation::CreateLookupTables(CColorBalanceOperation *this)
{
  CColorBalanceOperation *v1; // edx
  float v2; // xmm1_4
  int v3; // eax
  float *m_MagentaGreenBalance; // edi
  int v5; // esi
  int v6; // ebx
  int j; // edx
  int v8; // esi
  int v9; // ecx
  int v10; // eax
  float *yellow_blue_transfer[3]; // [esp+0h] [ebp-34h]
  float *magenta_green_transfer[3]; // [esp+Ch] [ebp-28h]
  float *cyan_red_transfer[3]; // [esp+18h] [ebp-1Ch]
  CColorBalanceOperation *v14; // [esp+24h] [ebp-10h]
  int i; // [esp+28h] [ebp-Ch]
  int v16; // [esp+2Ch] [ebp-8h]
  int v17; // [esp+30h] [ebp-4h]

  v1 = this;
  v2 = this->m_CyanRedBalance[0];
  v14 = this;
  if ( v2 <= 0.0 )
    cyan_red_transfer[0] = this->m_ShadowsSubTransfer;
  else
    cyan_red_transfer[0] = this->m_ShadowsAddTransfer;
  if ( this->m_CyanRedBalance[1] <= 0.0 )
    cyan_red_transfer[1] = this->m_MidtonesSubTransfer;
  else
    cyan_red_transfer[1] = this->m_MidtonesAddTransfer;
  if ( this->m_CyanRedBalance[2] <= 0.0 )
    cyan_red_transfer[2] = this->m_HighlightsSubTransfer;
  else
    cyan_red_transfer[2] = this->m_HighlightsAddTransfer;
  if ( this->m_MagentaGreenBalance[0] <= 0.0 )
    magenta_green_transfer[0] = this->m_ShadowsSubTransfer;
  else
    magenta_green_transfer[0] = this->m_ShadowsAddTransfer;
  if ( this->m_MagentaGreenBalance[1] <= 0.0 )
    magenta_green_transfer[1] = this->m_MidtonesSubTransfer;
  else
    magenta_green_transfer[1] = this->m_MidtonesAddTransfer;
  if ( this->m_MagentaGreenBalance[2] <= 0.0 )
    magenta_green_transfer[2] = this->m_HighlightsSubTransfer;
  else
    magenta_green_transfer[2] = this->m_HighlightsAddTransfer;
  if ( this->m_YellowBlueBalance[0] <= 0.0 )
    yellow_blue_transfer[0] = this->m_ShadowsSubTransfer;
  else
    yellow_blue_transfer[0] = this->m_ShadowsAddTransfer;
  if ( this->m_YellowBlueBalance[1] <= 0.0 )
    yellow_blue_transfer[1] = this->m_MidtonesSubTransfer;
  else
    yellow_blue_transfer[1] = this->m_MidtonesAddTransfer;
  if ( this->m_YellowBlueBalance[2] <= 0.0 )
    yellow_blue_transfer[2] = this->m_HighlightsSubTransfer;
  else
    yellow_blue_transfer[2] = this->m_HighlightsAddTransfer;
  v3 = 0;
  i = 0;
  do
  {
    m_MagentaGreenBalance = v1->m_MagentaGreenBalance;
    v5 = v3;
    v6 = v3;
    for ( j = 0; j <= 2; ++j )
    {
      v8 = (int)(float)((float)(cyan_red_transfer[j][v5] * *(m_MagentaGreenBalance - 3)) + (float)v5);
      v6 = (int)(float)((float)(magenta_green_transfer[j][v6] * *m_MagentaGreenBalance) + (float)v6);
      v9 = (int)(float)((float)(yellow_blue_transfer[j][v3] * m_MagentaGreenBalance[3]) + (float)v3);
      if ( v8 >= 0 )
      {
        v17 = 255;
        if ( v8 <= 255 )
          v17 = v8;
      }
      else
      {
        v17 = 0;
      }
      v5 = v17;
      if ( v6 >= 0 )
      {
        if ( v6 > 255 )
          v6 = 255;
      }
      else
      {
        v6 = 0;
      }
      v16 = v6;
      if ( v9 >= 0 )
      {
        if ( v9 > 255 )
          v9 = 255;
      }
      else
      {
        v9 = 0;
      }
      ++m_MagentaGreenBalance;
      v3 = v9;
    }
    v10 = i;
    v1 = v14;
    v14->m_pRedLookup[i] = v17;
    v1->m_pGreenLookup[v10] = v16;
    v1->m_pBlueLookup[v10] = v9;
    v3 = v10 + 1;
    i = v3;
  }
  while ( v3 < 256 );
}

//------------------------------------------------------------------------------
// Address: 0x100A3DA0
// Name: public: virtual void CColorBalanceUIPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorBalanceUIPanel::OnCommand(CColorBalanceUIPanel *this, const char *command)
{
  float v3; // xmm0_4
  float commanda; // [esp+10h] [ebp+8h]

  vgui::Frame::OnCommand(this, command);
  if ( _V_stricmp(s1: "BlendFactorUpdate", s2: command) == 0 )
  {
    if ( this->m_pBalanceOp != nullptr )
    {
      commanda = this->m_pBalanceOp->GetBlendFactor(this: this->m_pBalanceOp);
      v3 = commanda;
    }
    else
    {
      v3 = 0.0;
    }
    this->m_pBlendFactorSlider->SetValue(this: this->m_pBlendFactorSlider, a2: (int)(float)(v3 * 255.0), a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A3E10
// Name: private: virtual void CColorBalanceUIPanel::OnRadioButtonHit(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CColorBalanceUIPanel::OnRadioButtonHit(CColorBalanceUIPanel *this)
{
  CColorBalanceUIPanel::ResetSliders(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A3E20
// Name: public: virtual struct vgui::PanelMessageMap __near * CLookupViewPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CLookupViewPanel::GetMessageMap(CLookupViewPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CLookupViewPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CLookupViewPanel::GetMessageMap'::`2'::s_pMap;
  `CLookupViewPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CLookupViewPanel");
  `CLookupViewPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A3E50
// Name: public: virtual struct PanelAnimationMap __near * CLookupViewPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CLookupViewPanel::GetAnimMap(CLookupViewPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CLookupViewPanel");
}

//------------------------------------------------------------------------------
// Address: 0x100A3E60
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CLookupViewPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CLookupViewPanel::GetKBMap(CLookupViewPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CLookupViewPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CLookupViewPanel::GetKBMap'::`2'::s_pMap;
  `CLookupViewPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CLookupViewPanel");
  `CLookupViewPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A3E90
// Name: public: CLookupViewPanel::CLookupViewPanel(class vgui::Panel __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CLookupViewPanel *__thiscall CLookupViewPanel::CLookupViewPanel(
        CLookupViewPanel *this,
        vgui::Panel *parent,
        unsigned int CCHandle)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CProceduralTexturePanel::CProceduralTexturePanel(this, pParent: parent, pName: "LookupViewPanel");
  this->CProceduralTexturePanel::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CLookupViewPanel_vtbl *)&CLookupViewPanel::`vftable'{for `vgui::EditablePanel'};
  this->CProceduralTexturePanel::ITextureRegenerator::__vftable = (ITextureRegenerator_vtbl *)&CLookupViewPanel::`vftable'{for `ITextureRegenerator'};
  if ( `CLookupViewPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CLookupViewPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CLookupViewPanel");
    v4->pfnClassName = CLookupViewPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CProceduralTexturePanel");
  }
  if ( `CLookupViewPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CLookupViewPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CLookupViewPanel");
    v5->pfnClassName = CLookupViewPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CProceduralTexturePanel");
  }
  if ( `CLookupViewPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CLookupViewPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CLookupViewPanel");
    v6->pfnClassName = CLookupViewPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CProceduralTexturePanel");
  }
  this->m_CCHandle = CCHandle;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A3FB0
// Name: public: virtual void CLookupViewPanel::RegenerateTextureBits(class ITexture __near *,class IVTFTexture __near *,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CLookupViewPanel::RegenerateTextureBits(
        CLookupViewPanel *this,
        ITexture *pTexture,
        IVTFTexture *pVTFTexture,
        Rect_t *pRect)
{
  IVTFTexture *v4; // esi
  IVTFTexture_vtbl *v5; // eax
  int v6; // edx
  __int16 v7; // bx
  char v8; // al
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  unsigned int v12; // edx
  unsigned int v13; // edx
  int v14; // eax
  __int64 v15; // rax
  __int64 v16; // rax
  unsigned __int64 v17; // rdi
  int pixelWriter_4; // [esp+10h] [ebp-50h]
  unsigned __int8 pixelWriter_10; // [esp+16h] [ebp-4Ah]
  int pixelWriter_12; // [esp+18h] [ebp-48h]
  int pixelWriter_16; // [esp+1Ch] [ebp-44h]
  char pixelWriter_20; // [esp+20h] [ebp-40h]
  char pixelWriter_24; // [esp+24h] [ebp-3Ch]
  char pixelWriter_28; // [esp+28h] [ebp-38h]
  unsigned __int8 pixelWriter_32; // [esp+2Ch] [ebp-34h]
  int nWidth; // [esp+38h] [ebp-28h] BYREF
  int nHeight; // [esp+3Ch] [ebp-24h] BYREF
  int nDepth; // [esp+40h] [ebp-20h] BYREF
  CLookupViewPanel *v29; // [esp+44h] [ebp-1Ch]
  int v30; // [esp+48h] [ebp-18h]
  int v31; // [esp+4Ch] [ebp-14h]
  int inColor; // [esp+50h] [ebp-10h] OVERLAPPED
  int y; // [esp+54h] [ebp-Ch]
  int x; // [esp+58h] [ebp-8h]
  int v35; // [esp+5Ch] [ebp-4h]

  v4 = pVTFTexture;
  v5 = pVTFTexture->__vftable;
  v29 = this;
  v5->ComputeMipLevelDimensions(this: pVTFTexture, a2: 0, a3: &nWidth, a4: &nHeight, a5: &nDepth);
  v4->RowSizeInBytes(this: v4, a2: 0);
  pixelWriter_4 = (int)v4->ImageData_2(this: v4, a2: 0, a3: 0, a4: 0);
  switch ( v4->Format(this: v4) )
  {
    case IMAGE_FORMAT_RGBA8888:
    case IMAGE_FORMAT_UVWQ8888:
      pixelWriter_12 = 0x80000;
      v7 = 16;
      pixelWriter_16 = 1572880;
      goto LABEL_6;
    case IMAGE_FORMAT_BGR888:
      pixelWriter_10 = 3;
      pixelWriter_12 = 524304;
      pixelWriter_20 = -1;
      pixelWriter_24 = -1;
      pixelWriter_28 = -1;
      goto LABEL_20;
    case IMAGE_FORMAT_I8:
      pixelWriter_10 = 1;
      goto LABEL_18;
    case IMAGE_FORMAT_A8:
      pixelWriter_10 = 1;
      pixelWriter_12 = 0;
      v7 = 0;
      v6 = 0;
      pixelWriter_16 = 0;
      pixelWriter_20 = 0;
      pixelWriter_24 = 0;
      pixelWriter_28 = 0;
      pixelWriter_32 = -1;
      y = 0;
      v35 = 1;
      goto LABEL_22;
    case IMAGE_FORMAT_BGRA8888:
      pixelWriter_12 = 524304;
      v7 = 0;
      pixelWriter_16 = 1572864;
LABEL_6:
      pixelWriter_10 = 4;
      v8 = -1;
      goto LABEL_7;
    case IMAGE_FORMAT_BGRX8888:
      pixelWriter_10 = 4;
      v7 = 0;
      v6 = 0;
      pixelWriter_12 = 524304;
      pixelWriter_16 = 1572864;
      pixelWriter_20 = -1;
      pixelWriter_24 = -1;
      pixelWriter_28 = -1;
      pixelWriter_32 = 0;
      y = 0;
      v35 = 4;
      goto LABEL_22;
    case IMAGE_FORMAT_BGR565:
      pixelWriter_10 = 2;
      v6 = 0;
      pixelWriter_12 = 196616;
      v7 = -3;
      pixelWriter_16 = 65533;
      pixelWriter_20 = -8;
      pixelWriter_24 = -4;
      pixelWriter_28 = -8;
      pixelWriter_32 = 0;
      y = 0;
      v35 = 2;
      goto LABEL_22;
    case IMAGE_FORMAT_BGRX5551:
    case IMAGE_FORMAT_BGRA5551:
      pixelWriter_10 = 2;
      v6 = 0;
      pixelWriter_12 = 131079;
      v7 = -3;
      pixelWriter_16 = 589821;
      pixelWriter_20 = -8;
      pixelWriter_24 = -8;
      pixelWriter_28 = -8;
      pixelWriter_32 = 0x80;
      y = 0;
      v35 = 2;
      goto LABEL_22;
    case IMAGE_FORMAT_BGRA4444:
      pixelWriter_10 = 2;
      pixelWriter_12 = 4;
      v7 = -4;
      pixelWriter_16 = 589820;
      v8 = -16;
LABEL_7:
      v6 = 0;
      pixelWriter_20 = v8;
      pixelWriter_24 = v8;
      pixelWriter_28 = v8;
      pixelWriter_32 = v8;
      y = 0;
      v35 = pixelWriter_10;
      goto LABEL_22;
    case IMAGE_FORMAT_RGBA16161616F:
    case IMAGE_FORMAT_RGBA16161616:
      pixelWriter_10 = 8;
      v6 = 0;
      pixelWriter_12 = 0x100000;
      v7 = 32;
      pixelWriter_16 = 3145760;
      pixelWriter_20 = -1;
      pixelWriter_24 = -1;
      pixelWriter_28 = -1;
      pixelWriter_32 = -1;
      y = 0;
      v35 = 8;
      goto LABEL_22;
    case IMAGE_FORMAT_R32F:
      pixelWriter_10 = 4;
      pixelWriter_20 = -1;
      goto LABEL_19;
    case IMAGE_FORMAT_RGBA32323232F:
      pixelWriter_10 = 16;
      v6 = 0;
      pixelWriter_12 = 0x200000;
      v7 = 64;
      pixelWriter_16 = 6291520;
      pixelWriter_20 = -1;
      pixelWriter_24 = -1;
      pixelWriter_28 = -1;
      pixelWriter_32 = -1;
      y = 0;
      v35 = 16;
      goto LABEL_22;
    case IMAGE_FORMAT_BGRA1010102:
      pixelWriter_10 = 4;
      v7 = 0;
      v6 = 0;
      pixelWriter_12 = 655380;
      pixelWriter_16 = 1966080;
      pixelWriter_20 = -1;
      pixelWriter_24 = -1;
      pixelWriter_28 = -1;
      pixelWriter_32 = 3;
      y = 0;
      v35 = 4;
      goto LABEL_22;
    default:
      pixelWriter_10 = 0;
LABEL_18:
      pixelWriter_20 = -1;
LABEL_19:
      pixelWriter_12 = 0;
      pixelWriter_24 = 0;
      pixelWriter_28 = 0;
LABEL_20:
      v7 = 0;
      v6 = 0;
      pixelWriter_16 = 0;
      pixelWriter_32 = 0;
      y = 0;
      v35 = pixelWriter_10;
LABEL_22:
      while ( 1 )
      {
        v9 = 0;
        v10 = v6 & 0x1F;
        v11 = v6 >> 5;
        x = 0;
        v31 = v10;
        v30 = v11;
        while ( 1 )
        {
          LOWORD(inColor) = inColor & 0x8000
                          | ((unsigned __int8)(v9 >> 5) + 4 * (_BYTE)v11) & 0x1F
                          | (32 * (v9 & 0x1F | (32 * (v10 & 0x1F))));
          ((void (__thiscall *)(IColorCorrectionSystem *, IVTFTexture **, unsigned int, int))colorcorrection->GetLookup)(
            a1: colorcorrection,
            a2: &pVTFTexture,
            a3: v29->_vpanel,
            a4: inColor);
          if ( pixelWriter_10 != 0 )
          {
            if ( pixelWriter_10 >= 5u )
            {
              v15 = (unsigned __int8)(BYTE2(pVTFTexture) & pixelWriter_28);
              if ( v7 <= 0 )
                v16 = v15 >> -(char)v7;
              else
                v16 = v15 << v7;
              v17 = v16
                  | ((unsigned __int64)pixelWriter_32 << SBYTE2(pixelWriter_16))
                  | ((unsigned __int64)(unsigned __int8)((unsigned __int8)pVTFTexture & pixelWriter_20) << pixelWriter_12)
                  | ((unsigned __int64)(unsigned __int8)(BYTE1(pVTFTexture) & pixelWriter_24) << SBYTE2(pixelWriter_12));
              if ( v35 == 6 )
              {
                *(_DWORD *)pixelWriter_4 = v17;
                *(_WORD *)(pixelWriter_4 + 4) = WORD2(v17);
              }
              else if ( v35 == 8 )
              {
                *(_QWORD *)pixelWriter_4 = v17;
              }
            }
            else
            {
              v12 = (unsigned __int8)(BYTE2(pVTFTexture) & pixelWriter_28);
              if ( v7 <= 0 )
                v13 = v12 >> -(char)pixelWriter_16;
              else
                v13 = v12 << pixelWriter_16;
              v14 = v13
                  | (pixelWriter_32 << SBYTE2(pixelWriter_16))
                  | ((unsigned __int8)((unsigned __int8)pVTFTexture & pixelWriter_20) << pixelWriter_12)
                  | ((unsigned __int8)(BYTE1(pVTFTexture) & pixelWriter_24) << SBYTE2(pixelWriter_12));
              switch ( v35 )
              {
                case 1:
                  *(_BYTE *)pixelWriter_4 = v14;
                  break;
                case 2:
                  *(_WORD *)pixelWriter_4 = v14;
                  break;
                case 3:
                  *(_WORD *)pixelWriter_4 = v14;
                  *(_BYTE *)(pixelWriter_4 + 2) = BYTE2(v14);
                  break;
                case 4:
                  *(_DWORD *)pixelWriter_4 = v14;
                  break;
                default:
                  break;
              }
            }
          }
          pixelWriter_4 += v35;
          if ( ++x >= 128 )
            break;
          LOBYTE(v10) = v31;
          LOBYTE(v11) = v30;
          v9 = x;
        }
        if ( ++y >= 256 )
          return;
        v6 = y;
      }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A44A0
// Name: public: virtual struct vgui::PanelMessageMap __near * CLookupViewWindow::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CLookupViewWindow::GetMessageMap(CLookupViewWindow *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CLookupViewWindow::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CLookupViewWindow::GetMessageMap'::`2'::s_pMap;
  `CLookupViewWindow::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CLookupViewWindow");
  `CLookupViewWindow::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A44D0
// Name: public: virtual struct PanelAnimationMap __near * CLookupViewWindow::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CLookupViewWindow::GetAnimMap(CLookupViewWindow *this)
{
  return FindOrAddPanelAnimationMap(className: "CLookupViewWindow");
}

//------------------------------------------------------------------------------
// Address: 0x100A44E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CLookupViewWindow::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CLookupViewWindow::GetKBMap(CLookupViewWindow *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CLookupViewWindow::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CLookupViewWindow::GetKBMap'::`2'::s_pMap;
  `CLookupViewWindow::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CLookupViewWindow");
  `CLookupViewWindow::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A4510
// Name: public: CLookupViewWindow::CLookupViewWindow(class vgui::Panel __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CLookupViewWindow *__thiscall CLookupViewWindow::CLookupViewWindow(
        CLookupViewWindow *this,
        vgui::Panel *parent,
        unsigned int CCHandle)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CLookupViewPanel *v7; // eax
  CLookupViewPanel *v8; // eax

  vgui::Frame::Frame(this, parent, panelName: "LookupViewWindow", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CLookupViewWindow_vtbl *)&CLookupViewWindow::`vftable';
  if ( `CLookupViewWindow::ChainToMap'::`2'::chained == 0 )
  {
    `CLookupViewWindow::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CLookupViewWindow");
    v4->pfnClassName = CLookupViewWindow::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CLookupViewWindow::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CLookupViewWindow::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CLookupViewWindow");
    v5->pfnClassName = CLookupViewWindow::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CLookupViewWindow::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CLookupViewWindow::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CLookupViewWindow");
    v6->pfnClassName = CLookupViewWindow::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  vgui::Panel::SetSize(this, wide: 146, tall: 298);
  vgui::Panel::SetPos(this, x: 32, y: 32);
  v7 = (CLookupViewPanel *)MemAlloc_Alloc(nSize: 0x1C8u);
  if ( v7 != nullptr )
    v8 = CLookupViewPanel::CLookupViewPanel(this: v7, parent: this, CCHandle);
  else
    v8 = nullptr;
  this->m_pLookupPanel = v8;
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource\\LookupViewWindow.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  this->m_CCHandle = CCHandle;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A4670
// Name: public: virtual struct vgui::PanelMessageMap __near * CNewOperationDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CNewOperationDialog::GetMessageMap(CNewOperationDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CNewOperationDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CNewOperationDialog::GetMessageMap'::`2'::s_pMap;
  `CNewOperationDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CNewOperationDialog");
  `CNewOperationDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A46A0
// Name: public: virtual struct PanelAnimationMap __near * CNewOperationDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CNewOperationDialog::GetAnimMap(CNewOperationDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CNewOperationDialog");
}

//------------------------------------------------------------------------------
// Address: 0x100A46B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CNewOperationDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CNewOperationDialog::GetKBMap(CNewOperationDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CNewOperationDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CNewOperationDialog::GetKBMap'::`2'::s_pMap;
  `CNewOperationDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CNewOperationDialog");
  `CNewOperationDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A4710
// Name: private: void CNewOperationDialog::PopulateControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewOperationDialog::PopulateControls(CNewOperationDialog *this)
{
  const char **v2; // esi

  vgui::ComboBox::RemoveAll(this: this->m_pOperationType);
  v2 = &s_pColorCorrectionToolNames[1];
  do
    this->m_pOperationType->AddItem_2(this: this->m_pOperationType, a2: *v2++, a3: nullptr);
  while ( (int)v2 < (int)s_pColorCorrectionDmxElementNames );
  this->m_pOperationType->AddActionSignalTarget_2(this: this->m_pOperationType, a2: this);
  this->m_pOperationType->ActivateItem(this: this->m_pOperationType, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100A4770
// Name: public: virtual struct vgui::PanelMessageMap __near * COperationListPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall COperationListPanel::GetMessageMap(COperationListPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`COperationListPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `COperationListPanel::GetMessageMap'::`2'::s_pMap;
  `COperationListPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "COperationListPanel");
  `COperationListPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A47A0
// Name: public: virtual struct PanelAnimationMap __near * COperationListPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall COperationListPanel::GetAnimMap(COperationListPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "COperationListPanel");
}

//------------------------------------------------------------------------------
// Address: 0x100A47B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * COperationListPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall COperationListPanel::GetKBMap(COperationListPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`COperationListPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `COperationListPanel::GetKBMap'::`2'::s_pMap;
  `COperationListPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "COperationListPanel");
  `COperationListPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A4810
// Name: public: virtual void COperationListPanel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall COperationListPanel::OnMousePressed(COperationListPanel *this, ButtonCode_t code)
{
  int v3; // ebx
  unsigned int v4; // edi
  KeyValues *v5; // eax
  unsigned __int64 row; // [esp+4h] [ebp-10h] OVERLAPPED BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  if ( code == KEY_COUNT )
  {
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
    this->GetCellAtPos(this, a2: x, a3: y, a4: (int *)&row, a5: (int *)((char *)&row + 4));
    if ( row >= 0xFFFFFFFF )
    {
      vgui::ListPanel::OnMousePressed(this, code: KEY_COUNT);
    }
    else
    {
      v3 = this->GetItemIDFromRow(this, a2: row);
      v4 = this->GetItemUserData(this, a2: v3);
      LOBYTE(code) = (*(unsigned __int8 (__thiscall **)(unsigned int))(*(_DWORD *)v4 + 24))(a1: v4) == 0;
      v5 = this->GetItem(this, a2: v3);
      KeyValues::SetInt(this: v5, keyName: "image", value: (_BYTE)code != BUTTON_CODE_NONE);
      (*(void (__thiscall **)(unsigned int, ButtonCode_t))(*(_DWORD *)v4 + 28))(a1: v4, a2: code);
      colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A48F0
// Name: public: virtual void COperationListPanel::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationListPanel::OnMouseDoublePressed(COperationListPanel *this, ButtonCode_t code)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  int v5; // edi
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  vgui::TextEntry *v9; // eax
  vgui::TextEntry *v10; // eax
  int x; // [esp+4h] [ebp-10h] BYREF
  int y; // [esp+8h] [ebp-Ch] BYREF
  int column; // [esp+Ch] [ebp-8h] BYREF
  int row; // [esp+10h] [ebp-4h] BYREF

  if ( code != KEY_COUNT )
  {
    vgui::ListPanel::OnMouseDoublePressed(this, code);
    return;
  }
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  this->GetCellAtPos(this, a2: x, a3: y, a4: &row, a5: &column);
  if ( column != 0 && row == -1 )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
    {
      v4 = KeyValues::KeyValues(this: v3, setName: "Command", firstKey: "Command", firstValue: "NewOperation");
LABEL_7:
      this->PostActionSignal(this, a2: v4);
      return;
    }
LABEL_8:
    this->PostActionSignal(this, a2: nullptr);
    return;
  }
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL) )
  {
    if ( this->m_pNameEditPanel == nullptr )
    {
      this->m_nEditItem = this->GetItemIDFromRow(this, a2: row);
      v9 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
      if ( v9 != nullptr )
        v10 = vgui::TextEntry::TextEntry(this: v9, parent: this, panelName: "Name");
      else
        v10 = nullptr;
      this->m_pNameEditPanel = v10;
      v10->SendNewLine(this: v10, a2: true);
      this->m_pNameEditPanel->SetCatchEnterKey(this: this->m_pNameEditPanel, a2: true);
      this->m_pNameEditPanel->AddActionSignalTarget_2(this: this->m_pNameEditPanel, a2: this);
      vgui::Panel::SetSize(this: this->m_pNameEditPanel, wide: 226, tall: 24);
      ((void (__thiscall *)(vgui::TextEntry *, int))this->m_pNameEditPanel->SetBgColor)(
        a1: this->m_pNameEditPanel,
        a2: -1);
      this->EnterEditMode(this, a2: row, a3: column, a4: this->m_pNameEditPanel);
    }
  }
  else
  {
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
      || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT) )
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
      {
        v4 = KeyValues::KeyValues(this: v8, setName: "Command", firstKey: "Command", firstValue: "CloneOperation");
        goto LABEL_7;
      }
      goto LABEL_8;
    }
    v5 = this->GetSelectedItem(this, a2: 0);
    if ( v5 < 0 )
    {
      vgui::ListPanel::OnMouseDoublePressed(this, code: KEY_COUNT);
    }
    else
    {
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "LaunchOperation", firstKey: "item", firstValue: v5);
      else
        v7 = nullptr;
      this->PostActionSignal(this, a2: v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A4B30
// Name: public: virtual struct vgui::PanelMessageMap __near * CColorCorrectionUIPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CColorCorrectionUIPanel::GetMessageMap(CColorCorrectionUIPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CColorCorrectionUIPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorCorrectionUIPanel::GetMessageMap'::`2'::s_pMap;
  `CColorCorrectionUIPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CColorCorrectionUIPanel");
  `CColorCorrectionUIPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A4B60
// Name: public: virtual struct PanelAnimationMap __near * CColorCorrectionUIPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CColorCorrectionUIPanel::GetAnimMap(CColorCorrectionUIPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CColorCorrectionUIPanel");
}

//------------------------------------------------------------------------------
// Address: 0x100A4B70
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CColorCorrectionUIPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CColorCorrectionUIPanel::GetKBMap(CColorCorrectionUIPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CColorCorrectionUIPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorCorrectionUIPanel::GetKBMap'::`2'::s_pMap;
  `CColorCorrectionUIPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CColorCorrectionUIPanel");
  `CColorCorrectionUIPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A4BE0
// Name: public: void CColorOperationList::Apply(struct color24,struct color24 __near &,class IColorOperation __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorOperationList::Apply(
        CColorOperationList *this,
        color24 in,
        color24 *out,
        IColorOperation *pFinalOp)
{
  int m_Size; // edi
  int v6; // esi
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  int v10; // eax
  float v11; // xmm1_4
  float v12; // xmm2_4
  int v13; // ecx
  int v14; // edx
  int v15; // eax
  int v16; // eax
  Vector temp; // [esp+8h] [ebp-18h] BYREF
  Vector rgb; // [esp+14h] [ebp-Ch] BYREF

  m_Size = this->m_OpList.m_Size;
  if ( m_Size != 0 )
  {
    v6 = 0;
    x = (float)in.r * 0.0039215689;
    y = (float)in.g * 0.0039215689;
    z = (float)in.b * 0.0039215689;
    rgb.x = x;
    rgb.y = y;
    for ( rgb.z = z; v6 < m_Size; rgb = temp )
    {
      if ( this->m_OpList.m_Memory.m_pMemory[v6] == pFinalOp )
        break;
      this->m_OpList.m_Memory.m_pMemory[v6]->Apply(this: this->m_OpList.m_Memory.m_pMemory[v6], a2: &rgb, a3: &temp);
      x = temp.x;
      y = temp.y;
      z = temp.z;
      ++v6;
    }
    v10 = (int)(float)((float)(x * 255.0) + 0.5);
    v11 = (float)(y * 255.0) + 0.5;
    v12 = (float)(z * 255.0) + 0.5;
    v13 = (int)v11;
    v14 = (int)v12;
    if ( v10 >= 0 )
    {
      if ( v10 > 255 )
        LOBYTE(v10) = -1;
    }
    else
    {
      LOBYTE(v10) = 0;
    }
    out->r = v10;
    if ( v13 >= 0 )
    {
      LOBYTE(v15) = -1;
      if ( v13 <= 255 )
        v15 = (int)v11;
    }
    else
    {
      LOBYTE(v15) = 0;
    }
    out->g = v15;
    if ( v14 >= 0 )
    {
      LOBYTE(v16) = -1;
      if ( v14 <= 255 )
        v16 = (int)v12;
      out->b = v16;
    }
    else
    {
      out->b = 0;
    }
  }
  else
  {
    *out = in;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A4D30
// Name: public: class IColorOperation __near * CColorOperationList::GetOperation(int)
// Source: json
//------------------------------------------------------------------------------
IColorOperation *__thiscall CColorOperationList::GetOperation(CColorOperationList *this, int opIndex)
{
  if ( opIndex >= 0 && opIndex < this->m_OpList.m_Size )
    return this->m_OpList.m_Memory.m_pMemory[opIndex];
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100A4D50
// Name: public: int CCurvesColorOperation::FindControlPoint(float,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCurvesColorOperation::FindControlPoint(CCurvesColorOperation *this, float flInValue, float flTolerance)
{
  int v3; // edx
  Vector *i; // ecx

  v3 = this->m_ControlPoints.m_Size - 1;
  if ( v3 < 0 )
    return -1;
  for ( i = &this->m_ControlPoints.m_Memory.m_pMemory[v3]; flTolerance <= fabs(i->x - flInValue); --i )
  {
    if ( --v3 < 0 )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100A4DA0
// Name: protected: virtual int CColorCurvesEditPanel::FindControlPoint(float,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CColorCurvesEditPanel::FindControlPoint(CColorCurvesEditPanel *this, float flIn, float flTolerance)
{
  return CCurvesColorOperation::FindControlPoint(this: this->m_pCurvesOp, flInValue: flIn, flTolerance);
}

//------------------------------------------------------------------------------
// Address: 0x100A4DD0
// Name: protected: virtual void CColorCurvesEditPanel::GetControlPoint(int,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCurvesEditPanel::GetControlPoint(
        CColorCurvesEditPanel *this,
        int nPoint,
        float *pIn,
        float *pOut)
{
  Vector *v4; // eax

  v4 = &this->m_pCurvesOp->m_ControlPoints.m_Memory.m_pMemory[nPoint];
  *pIn = v4->x;
  *pOut = v4->y;
}

//------------------------------------------------------------------------------
// Address: 0x100A4E00
// Name: public: CLevelsColorOperation::CLevelsColorOperation(class CColorOperationList __near *)
// Source: json
//------------------------------------------------------------------------------
CLevelsColorOperation *__thiscall CLevelsColorOperation::CLevelsColorOperation(
        CLevelsColorOperation *this,
        CColorOperationList *pList)
{
  this->m_flMidInputLevel = 0.5;
  this->__vftable = (CLevelsColorOperation_vtbl *)&CLevelsColorOperation::`vftable';
  this->m_pOpList = pList;
  this->m_flMinInputLevel = 0.0;
  this->m_flMaxInputLevel = 1.0;
  this->m_flMinOutputLevel = 0.0;
  this->m_flMaxOutputLevel = 1.0;
  this->m_flBlendFactor = 1.0;
  this->m_nChannelMask = 7;
  this->m_bEnable = true;
  CLevelsColorOperation::UpdateOutputLevelArray(this);
  _V_strcpy(dest: this->m_pName, src: "Levels");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A4E90
// Name: public: virtual void CLevelsColorOperation::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLevelsColorOperation::Release(CLevelsColorOperation *this)
{
  free(pMem: this);
}

//------------------------------------------------------------------------------
// Address: 0x100A4EA0
// Name: public: virtual char const __near * CLevelsColorOperation::GetName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CLevelsColorOperation::GetName(CLevelsColorOperation *this)
{
  return this->m_pName;
}

//------------------------------------------------------------------------------
// Address: 0x100A4EB0
// Name: public: virtual void CLevelsColorOperation::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLevelsColorOperation::SetName(CLevelsColorOperation *this, const char *pName)
{
  _V_strcpy(dest: this->m_pName, src: pName);
}

//------------------------------------------------------------------------------
// Address: 0x100A4ED0
// Name: public: virtual bool CLevelsColorOperation::IsEnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CLevelsColorOperation::IsEnabled(CLevelsColorOperation *this)
{
  return this->m_bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x100A4EE0
// Name: public: virtual void CLevelsColorOperation::SetEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLevelsColorOperation::SetEnabled(CLevelsColorOperation *this, bool bEnable)
{
  this->m_bEnable = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x100A4EF0
// Name: public: virtual float CLevelsColorOperation::GetBlendFactor(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CLevelsColorOperation::GetBlendFactor(CLevelsColorOperation *this)
{
  return this->m_flBlendFactor;
}

//------------------------------------------------------------------------------
// Address: 0x100A4F00
// Name: public: void CLevelsColorOperation::SetInputLevels(float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLevelsColorOperation::SetInputLevels(
        CLevelsColorOperation *this,
        float flMinValue,
        float flMidValue,
        float flMaxValue)
{
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm0_4

  v4 = 0.0;
  v5 = flMinValue;
  if ( flMinValue >= 0.0 )
  {
    if ( flMinValue > 1.0 )
      v5 = 1.0;
  }
  else
  {
    v5 = 0.0;
  }
  this->m_flMinInputLevel = v5;
  v6 = flMidValue;
  if ( flMidValue >= 0.0 )
  {
    if ( flMidValue > 1.0 )
      v6 = 1.0;
  }
  else
  {
    v6 = 0.0;
  }
  this->m_flMidInputLevel = v6;
  if ( flMaxValue >= 0.0 )
  {
    if ( flMaxValue <= 1.0 )
      v4 = flMaxValue;
    else
      v4 = 1.0;
  }
  this->m_flMaxInputLevel = v4;
  CLevelsColorOperation::UpdateOutputLevelArray(this);
  colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
}

//------------------------------------------------------------------------------
// Address: 0x100A4F90
// Name: public: void CLevelsColorOperation::SetOutputLevels(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLevelsColorOperation::SetOutputLevels(CLevelsColorOperation *this, float flMinValue, float flMaxValue)
{
  float v3; // xmm0_4
  float v4; // xmm0_4

  v3 = flMinValue;
  if ( flMinValue >= 0.0 )
  {
    if ( flMinValue > 1.0 )
      v3 = 1.0;
  }
  else
  {
    v3 = 0.0;
  }
  this->m_flMinOutputLevel = v3;
  v4 = flMaxValue;
  if ( flMaxValue >= 0.0 )
  {
    if ( flMaxValue > 1.0 )
      v4 = 1.0;
  }
  else
  {
    v4 = 0.0;
  }
  this->m_flMaxOutputLevel = v4;
  CLevelsColorOperation::UpdateOutputLevelArray(this);
  colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
}

//------------------------------------------------------------------------------
// Address: 0x100A5000
// Name: public: virtual class IColorOperation __near * CLevelsColorOperation::Clone(void)
// Source: json
//------------------------------------------------------------------------------
CLevelsColorOperation *__thiscall CLevelsColorOperation::Clone(CLevelsColorOperation *this)
{
  CLevelsColorOperation *v2; // eax
  CLevelsColorOperation *v3; // esi
  double m_flMinInputLevel; // st7
  char *m_pName; // edi

  v2 = (CLevelsColorOperation *)MemAlloc_Alloc(nSize: 0x528u);
  if ( v2 != nullptr )
    v3 = CLevelsColorOperation::CLevelsColorOperation(this: v2, pList: this->m_pOpList);
  else
    v3 = nullptr;
  _V_memcpy(dest: v3->m_pOutValue, src: this->m_pOutValue, count: 1024);
  v3->m_nChannelMask = this->m_nChannelMask;
  v3->m_flBlendFactor = this->m_flBlendFactor;
  m_flMinInputLevel = this->m_flMinInputLevel;
  m_pName = this->m_pName;
  v3->m_flMinInputLevel = m_flMinInputLevel;
  v3->m_flMidInputLevel = *(float *)(m_pName - 17);
  v3->m_flMaxInputLevel = *(float *)(m_pName - 13);
  v3->m_flMinOutputLevel = *(float *)(m_pName - 9);
  v3->m_flMaxOutputLevel = *(float *)(m_pName - 5);
  v3->m_bEnable = *(m_pName - 1);
  _V_memcpy(dest: v3->m_pName, src: m_pName, count: 256);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100A50B0
// Name: public: void CColorHistogramPanel::ComputeHistogram(struct Rect_t __near &,unsigned char __near *,enum ImageFormat,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorHistogramPanel::ComputeHistogram(
        CColorHistogramPanel *this,
        Rect_t *srcRect,
        unsigned __int8 *pBits,
        ImageFormat format,
        int nStride)
{
  ImageFormat v5; // esi
  Rect_t *v6; // edi
  int m_nNumBytes; // eax
  unsigned __int8 *v8; // ecx
  char v9; // bl
  int v10; // eax
  int v11; // eax
  int v12; // edx
  int v13; // esi
  int v14; // eax
  int v15; // edx
  char v16; // cl
  unsigned __int8 v17; // dl
  float *v18; // esi
  int v19; // eax
  float v20; // xmm1_4
  float *v21; // eax
  int i; // edx
  float v23; // xmm0_4
  float v24; // xmm0_4
  float v25; // xmm0_4
  float v26; // xmm0_4
  color24 v27; // [esp-Ch] [ebp-54h]
  unsigned __int8 *writer_4; // [esp+10h] [ebp-38h]
  char writer_12; // [esp+18h] [ebp-30h]
  char writer_14; // [esp+1Ah] [ebp-2Eh]
  char writer_16; // [esp+1Ch] [ebp-2Ch]
  int writer_20; // [esp+20h] [ebp-28h]
  int writer_24; // [esp+24h] [ebp-24h]
  int writer_28; // [esp+28h] [ebp-20h]
  int nPixelCount; // [esp+30h] [ebp-18h]
  int v36; // [esp+34h] [ebp-14h]
  int nSizeInBytes; // [esp+38h] [ebp-10h]
  unsigned __int8 *v39; // [esp+40h] [ebp-8h]
  int y; // [esp+44h] [ebp-4h]
  int x; // [esp+54h] [ebp+Ch]

  v5 = format;
  memset(this->m_pHistogram, 0, sizeof(this->m_pHistogram));
  v6 = srcRect;
  nPixelCount = srcRect->width * srcRect->height;
  m_nNumBytes = ImageLoader::ImageFormatInfo(fmt: v5)->m_nNumBytes;
  v8 = &pBits[nStride * v6->y + m_nNumBytes * v6->x];
  nSizeInBytes = m_nNumBytes;
  switch ( v5 )
  {
    case IMAGE_FORMAT_RGBA8888:
    case IMAGE_FORMAT_UVWQ8888:
      writer_12 = 0;
      writer_14 = 8;
      writer_16 = 16;
      v10 = 255;
      v9 = 4;
      writer_20 = 255;
      goto LABEL_17;
    case IMAGE_FORMAT_BGR888:
      writer_12 = 16;
      writer_14 = 8;
      writer_16 = 0;
      v10 = 255;
      v9 = 3;
      writer_20 = 255;
      goto LABEL_17;
    case IMAGE_FORMAT_I8:
      v9 = 1;
      goto LABEL_15;
    case IMAGE_FORMAT_A8:
      v10 = 0;
      v9 = 1;
      writer_12 = 0;
      writer_14 = 0;
      writer_16 = 0;
      writer_20 = 0;
      goto LABEL_17;
    case IMAGE_FORMAT_BGRA8888:
    case IMAGE_FORMAT_BGRX8888:
      writer_12 = 16;
      writer_14 = 8;
      writer_16 = 0;
      v10 = 255;
      v9 = 4;
      writer_20 = 255;
      goto LABEL_17;
    case IMAGE_FORMAT_BGR565:
      writer_12 = 8;
      writer_14 = 3;
      writer_16 = -3;
      v10 = 248;
      v9 = 2;
      writer_20 = 248;
      writer_24 = 252;
      goto LABEL_18;
    case IMAGE_FORMAT_BGRX5551:
    case IMAGE_FORMAT_BGRA5551:
      writer_12 = 7;
      writer_14 = 2;
      writer_16 = -3;
      v10 = 248;
      v9 = 2;
      writer_20 = 248;
      goto LABEL_17;
    case IMAGE_FORMAT_BGRA4444:
      writer_12 = 4;
      writer_14 = 0;
      writer_16 = -4;
      v10 = 240;
      v9 = 2;
      writer_20 = 240;
      goto LABEL_17;
    case IMAGE_FORMAT_RGBA16161616F:
    case IMAGE_FORMAT_RGBA16161616:
      writer_12 = 0;
      writer_14 = 16;
      writer_16 = 32;
      v10 = 0xFFFF;
      v9 = 8;
      writer_20 = 0xFFFF;
      goto LABEL_17;
    case IMAGE_FORMAT_R32F:
      v9 = 4;
      writer_20 = -1;
      goto LABEL_16;
    case IMAGE_FORMAT_RGBA32323232F:
      writer_12 = 0;
      writer_14 = 32;
      writer_16 = 64;
      v10 = -1;
      v9 = 16;
      writer_20 = -1;
      goto LABEL_17;
    case IMAGE_FORMAT_BGRA1010102:
      writer_12 = 20;
      writer_14 = 10;
      writer_16 = 0;
      v10 = 1023;
      v9 = 4;
      writer_20 = 1023;
      goto LABEL_17;
    default:
      v9 = 0;
LABEL_15:
      writer_20 = 255;
LABEL_16:
      v10 = 0;
      writer_12 = 0;
      writer_14 = 0;
      writer_16 = 0;
LABEL_17:
      writer_24 = v10;
LABEL_18:
      writer_28 = v10;
      y = 0;
      if ( srcRect->height > 0 )
      {
        v36 = (unsigned __int16)nStride;
        v39 = v8;
        do
        {
          writer_4 = v8;
          x = 0;
          if ( v6->width > 0 )
          {
            do
            {
              v11 = *v8;
              if ( (unsigned __int8)v9 > 1u )
              {
                v11 = *(unsigned __int16 *)v8;
                if ( (unsigned __int8)v9 > 2u )
                {
                  v11 |= v8[2] << 16;
                  if ( (unsigned __int8)v9 > 3u )
                    v11 |= v8[3] << 24;
                }
              }
              v12 = v11 >> writer_12;
              v13 = writer_24 & (v11 >> writer_14);
              v14 = writer_28 & (v11 >> writer_16);
              v15 = writer_20 & v12;
              if ( v15 >= 0 )
              {
                if ( v15 > 255 )
                  LOBYTE(v15) = -1;
              }
              else
              {
                LOBYTE(v15) = 0;
              }
              LOBYTE(nStride) = v15;
              if ( v13 >= 0 )
              {
                v16 = -1;
                if ( v13 <= 255 )
                  v16 = v13;
              }
              else
              {
                v16 = 0;
              }
              BYTE1(nStride) = v16;
              if ( v14 >= 0 )
              {
                v17 = -1;
                if ( v14 <= 255 )
                  v17 = v14;
              }
              else
              {
                v17 = 0;
              }
              *(_WORD *)&v27.r = nStride;
              v27.b = v17;
              CColorOperationList::Apply(
                this: this->m_pOp->m_pOpList,
                in: v27,
                out: (color24 *)&format,
                pFinalOp: this->m_pOp);
              switch ( this->m_Type )
              {
                case 0:
                  v18 = &this->m_pHistogram[(unsigned __int8)format];
                  goto LABEL_39;
                case 1:
                  v18 = &this->m_pHistogram[BYTE1(format)];
                  goto LABEL_39;
                case 2:
                  v18 = &this->m_pHistogram[BYTE2(format)];
LABEL_39:
                  *v18 = *v18 + 1.0;
                  break;
                case 3:
                  v19 = (int)(float)((float)((float)((float)((float)BYTE1(format) * 0.58700001)
                                                   + (float)((float)(unsigned __int8)format * 0.29899999))
                                           + (float)((float)BYTE2(format) * 0.114))
                                   + 0.5);
                  if ( v19 >= 0 )
                  {
                    if ( v19 > 255 )
                      v19 = 255;
                  }
                  else
                  {
                    v19 = 0;
                  }
                  this->m_pHistogram[v19] = this->m_pHistogram[v19] + 1.0;
                  break;
                default:
                  break;
              }
              v8 = &writer_4[nSizeInBytes];
              v6 = srcRect;
              writer_4 += nSizeInBytes;
              ++x;
            }
            while ( x < srcRect->width );
          }
          v8 = &v39[v36];
          ++y;
          v39 += v36;
        }
        while ( y < v6->height );
      }
      this->m_flMax = 0.0;
      v20 = 1.0 / (float)nPixelCount;
      v21 = &this->m_pHistogram[1];
      for ( i = 64; i != 0; --i )
      {
        v23 = v20 * *(v21 - 1);
        *(v21 - 1) = v23;
        if ( v23 > this->m_flMax )
          this->m_flMax = v23;
        v24 = v20 * *v21;
        *v21 = v24;
        if ( v24 > this->m_flMax )
          this->m_flMax = v24;
        v25 = v20 * v21[1];
        v21[1] = v25;
        if ( v25 > this->m_flMax )
          this->m_flMax = v25;
        v26 = v20 * v21[2];
        v21[2] = v26;
        if ( v26 > this->m_flMax )
          this->m_flMax = v26;
        v21 += 4;
      }
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A55E0
// Name: public: virtual void CColorLevelsUIPanel::ReadUncorrectedImage(struct Rect_t __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorLevelsUIPanel::ReadUncorrectedImage(
        CColorLevelsUIPanel *this,
        Rect_t *pSrcRect,
        unsigned __int8 *pPreviewImage)
{
  CColorHistogramPanel *m_pHistogramPanel; // ecx
  Rect_t dstRect; // [esp+0h] [ebp-10h] BYREF

  m_pHistogramPanel = this->m_pHistogramPanel;
  dstRect.x = 0;
  dstRect.y = 0;
  dstRect.width = 128;
  dstRect.height = 96;
  CColorHistogramPanel::ComputeHistogram(
    this: m_pHistogramPanel,
    srcRect: &dstRect,
    pBits: pPreviewImage,
    format: IMAGE_FORMAT_BGRX8888,
    nStride: 512);
}

//------------------------------------------------------------------------------
// Address: 0x100A5620
// Name: public: virtual void CColorLevelsUIPanel::OnMessage(class KeyValues const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorLevelsUIPanel::OnMessage(
        CColorLevelsUIPanel *this,
        KeyValues *params,
        const KeyValues *fromPanel)
{
  const char *Name; // eax
  CColorSlider *Ptr; // eax
  CLevelsColorOperation_vtbl *v6; // edi
  float v7; // xmm0_4
  KeyValues *v8; // eax
  KeyValues *v9; // eax
  CColorLevelsUIPanel_vtbl *v10; // edi
  int v11; // eax
  CColorSlider *m_pInputLevelSlider; // eax
  int m_nMinValue; // ecx
  CColorSlider *m_pOutputLevelSlider; // eax

  vgui::Panel::OnMessage(this, params, ifromPanel: fromPanel);
  Name = KeyValues::GetName(this: params);
  if ( _V_stricmp(s1: "SliderMoved", s2: Name) == 0 )
  {
    Ptr = (CColorSlider *)KeyValues::GetPtr(this: params, keyName: "panel", defaultValue: nullptr);
    if ( Ptr == (CColorSlider *)this->m_pBlendFactorSlider )
    {
      v6 = this->m_pLevelsOp->__vftable;
      v7 = (float)this->m_pBlendFactorSlider->GetValue(this: this->m_pBlendFactorSlider) * 0.0039215689;
      ((void (__thiscall *)(CLevelsColorOperation *, _DWORD))v6->SetBlendFactor)(a1: this->m_pLevelsOp, a2: LODWORD(v7));
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "command", firstKey: "command", firstValue: "BlendFactorUpdate");
      else
        v9 = nullptr;
      v10 = this->__vftable;
      v11 = ((int (__thiscall *)(CColorLevelsUIPanel *, KeyValues *, _DWORD))this->GetParent)(a1: this, a2: v9, a3: 0.0);
      ((void (__thiscall *)(CColorLevelsUIPanel *, int))v10->PostMessage)(a1: this, a2: v11);
    }
    else if ( Ptr == this->m_pInputLevelSlider )
    {
      m_pInputLevelSlider = this->m_pInputLevelSlider;
      m_nMinValue = m_pInputLevelSlider->m_nMinValue;
      CLevelsColorOperation::SetInputLevels(
        this: this->m_pLevelsOp,
        flMinValue: (float)(int)(float)((float)((float)(m_pInputLevelSlider->m_nMaxValue - m_nMinValue)
                                  * m_pInputLevelSlider->m_flKnobPosition[0])
                          + (float)m_nMinValue)
      * 0.0039215689,
        flMidValue: (float)(int)(float)((float)((float)(m_pInputLevelSlider->m_nMaxValue - m_nMinValue)
                                  * m_pInputLevelSlider->m_flKnobPosition[2])
                          + (float)m_nMinValue)
      * 0.0039215689,
        flMaxValue: (float)(int)(float)((float)((float)(m_pInputLevelSlider->m_nMaxValue - m_nMinValue)
                                  * m_pInputLevelSlider->m_flKnobPosition[1])
                          + (float)m_nMinValue)
      * 0.0039215689);
    }
    else if ( Ptr == this->m_pOutputLevelSlider )
    {
      m_pOutputLevelSlider = this->m_pOutputLevelSlider;
      CLevelsColorOperation::SetOutputLevels(
        this: this->m_pLevelsOp,
        flMinValue: (float)(int)(float)((float)((float)(m_pOutputLevelSlider->m_nMaxValue - m_pOutputLevelSlider->m_nMinValue)
                                  * m_pOutputLevelSlider->m_flKnobPosition[0])
                          + (float)m_pOutputLevelSlider->m_nMinValue)
      * 0.0039215689,
        flMaxValue: (float)(int)(float)((float)((float)(m_pOutputLevelSlider->m_nMaxValue - m_pOutputLevelSlider->m_nMinValue)
                                  * m_pOutputLevelSlider->m_flKnobPosition[1])
                          + (float)m_pOutputLevelSlider->m_nMinValue)
      * 0.0039215689);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A5870
// Name: public: float CSelectedHSVOperation::GetSelectionAmount(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
double __userpurge CSelectedHSVOperation::GetSelectionAmount@<st0>(
        CSelectedHSVOperation *this@<ecx>,
        int a2@<ebp>,
        const Vector *rgb)
{
  CSelectedHSVOperation::SelectionMethod_t m_SelectionMethod; // eax
  int v6; // edi
  float v7; // xmm0_4
  float m_Fuzziness; // xmm4_4
  Vector *m_pMemory; // eax
  float v10; // xmm0_4
  double v11; // st7
  Vector *v12; // eax
  double v13; // st7
  Vector *v14; // eax
  float v15; // xmm1_4
  Vector *v16; // eax
  long double v17; // st7
  double v18; // st7
  Vector *v19; // eax
  double v20; // st7
  Vector *v21; // eax
  float v22; // xmm1_4
  Vector *v23; // eax
  long double v24; // st7
  double v25; // st7
  Vector *v26; // eax
  double v27; // st7
  Vector *v28; // eax
  Vector *v29; // eax
  float x; // xmm0_4
  float v31; // xmm3_4
  float v32; // xmm2_4
  float v33; // [esp+0h] [ebp-68h]
  float v34; // [esp+0h] [ebp-68h]
  float v35; // [esp+4h] [ebp-64h]
  float v36; // [esp+8h] [ebp-60h]
  float v37; // [esp+8h] [ebp-60h]
  float v38; // [esp+8h] [ebp-60h]
  float v39; // [esp+8h] [ebp-60h]
  float v40; // [esp+8h] [ebp-60h]
  float v41; // [esp+8h] [ebp-60h]
  float v42; // [esp+8h] [ebp-60h]
  Vector v43; // [esp+30h] [ebp-38h] BYREF
  float a; // [esp+3Ch] [ebp-2Ch]
  float b; // [esp+40h] [ebp-28h]
  float fuzziness; // [esp+44h] [ebp-24h]
  float m_Tolerance; // [esp+48h] [ebp-20h]
  int v48; // [esp+4Ch] [ebp-1Ch]
  float v49; // [esp+50h] [ebp-18h]
  float i; // [esp+54h] [ebp-14h]
  float v51; // [esp+58h] [ebp-10h]
  int v52; // [esp+5Ch] [ebp-Ch]
  int v53; // [esp+60h] [ebp-8h]
  int vars0; // [esp+68h] [ebp+0h]

  v52 = a2;
  v53 = vars0;
  m_SelectionMethod = this->m_SelectionMethod;
  if ( m_SelectionMethod == SELECT_ALL )
    return 1.0;
  v6 = 0;
  if ( m_SelectionMethod == SELECT_NONE )
    return 0.0;
  v7 = 0.0;
  v49 = 0.0;
  v48 = 0;
  if ( this->m_SelectedRGBs.m_Size > 0 )
  {
    m_Fuzziness = this->m_Fuzziness;
    for ( i = m_Fuzziness; ; m_Fuzziness = i )
    {
      switch ( this->m_SelectionMethod )
      {
        case SELECT_LESSER_RED:
          v51 = FuzzyLessThan(a: rgb->x, b: this->m_SelectedRGBs.m_Memory.m_pMemory[v6].x, fuzziness: i);
          break;
        case SELECT_GREATER_GREEN:
          v51 = FuzzyGreaterThan(a: rgb->y, b: this->m_SelectedRGBs.m_Memory.m_pMemory[v6].y, fuzziness: i);
          break;
        case SELECT_LESSER_GREEN:
          v51 = FuzzyLessThan(a: rgb->y, b: this->m_SelectedRGBs.m_Memory.m_pMemory[v6].y, fuzziness: i);
          break;
        case SELECT_GREATER_BLUE:
          v51 = FuzzyGreaterThan(a: rgb->z, b: this->m_SelectedRGBs.m_Memory.m_pMemory[v6].z, fuzziness: i);
          break;
        case SELECT_LESSER_BLUE:
          v51 = FuzzyLessThan(a: rgb->z, b: this->m_SelectedRGBs.m_Memory.m_pMemory[v6].z, fuzziness: i);
          break;
        case SELECT_NEARBY_RGB:
          m_pMemory = this->m_SelectedRGBs.m_Memory.m_pMemory;
          v10 = fsqrt(
                  (float)((float)((float)(rgb->y - m_pMemory[v6].y) * (float)(rgb->y - m_pMemory[v6].y))
                        + (float)((float)(rgb->z - m_pMemory[v6].z) * (float)(rgb->z - m_pMemory[v6].z)))
                + (float)((float)(rgb->x - m_pMemory[v6].x) * (float)(rgb->x - m_pMemory[v6].x)));
          m_Tolerance = this->m_Tolerance;
          v51 = FuzzyLessThan(a: v10, b: m_Tolerance, fuzziness: m_Tolerance * m_Fuzziness);
          break;
        case SELECT_GREATER_HUE:
          RGBtoHSV(rgb, hsv: &v43);
          v11 = this->m_Fuzziness;
          v12 = this->m_SelectedHSVs.m_Memory.m_pMemory;
          i = this->m_Fuzziness;
          v36 = v11;
          v51 = FuzzyGreaterThan(a: v43.x, b: v12[v6].x, fuzziness: v36);
          break;
        case SELECT_LESSER_HUE:
          RGBtoHSV(rgb, hsv: &v43);
          v13 = this->m_Fuzziness;
          v14 = this->m_SelectedHSVs.m_Memory.m_pMemory;
          i = this->m_Fuzziness;
          v37 = v13;
          v51 = FuzzyLessThan(a: v43.x, b: v14[v6].x, fuzziness: v37);
          break;
        case SELECT_NEARBY_HUE:
          RGBtoHSV(rgb, hsv: &v43);
          v15 = this->m_Fuzziness;
          v16 = this->m_SelectedHSVs.m_Memory.m_pMemory;
          fuzziness = this->m_Tolerance;
          v17 = v43.x - v16[v6].x;
          i = v15;
          v33 = fabs(v17) * 0.0027777778;
          v51 = FuzzyLessThan(a: v33, b: fuzziness, fuzziness: fuzziness * v15);
          break;
        case SELECT_GREATER_SATURATION:
          RGBtoHSV(rgb, hsv: &v43);
          v18 = this->m_Fuzziness;
          v19 = this->m_SelectedHSVs.m_Memory.m_pMemory;
          i = this->m_Fuzziness;
          v38 = v18;
          v51 = FuzzyGreaterThan(a: v43.y, b: v19[v6].y, fuzziness: v38);
          break;
        case SELECT_LESSER_SATURATION:
          RGBtoHSV(rgb, hsv: &v43);
          v20 = this->m_Fuzziness;
          v21 = this->m_SelectedHSVs.m_Memory.m_pMemory;
          i = this->m_Fuzziness;
          v39 = v20;
          v51 = FuzzyLessThan(a: v43.y, b: v21[v6].y, fuzziness: v39);
          break;
        case SELECT_NEARBY_SATURATION:
          RGBtoHSV(rgb, hsv: &v43);
          v22 = this->m_Fuzziness;
          v23 = this->m_SelectedHSVs.m_Memory.m_pMemory;
          b = this->m_Tolerance;
          v40 = b * v22;
          v35 = b;
          v24 = v43.y - v23[v6].y;
          goto LABEL_21;
        case SELECT_GREATER_VALUE:
          RGBtoHSV(rgb, hsv: &v43);
          v25 = this->m_Fuzziness;
          v26 = this->m_SelectedHSVs.m_Memory.m_pMemory;
          i = this->m_Fuzziness;
          v41 = v25;
          v51 = FuzzyGreaterThan(a: v43.z, b: v26[v6].z, fuzziness: v41);
          break;
        case SELECT_LESSER_VALUE:
          RGBtoHSV(rgb, hsv: &v43);
          v27 = this->m_Fuzziness;
          v28 = this->m_SelectedHSVs.m_Memory.m_pMemory;
          i = this->m_Fuzziness;
          v42 = v27;
          v51 = FuzzyLessThan(a: v43.z, b: v28[v6].z, fuzziness: v42);
          break;
        case SELECT_NEARBY_VALUE:
          RGBtoHSV(rgb, hsv: &v43);
          v22 = this->m_Fuzziness;
          v29 = this->m_SelectedHSVs.m_Memory.m_pMemory;
          a = this->m_Tolerance;
          v40 = a * v22;
          v35 = a;
          v24 = v43.z - v29[v6].z;
LABEL_21:
          v34 = fabs(v24);
          i = v22;
          v51 = FuzzyLessThan(a: v34, b: v35, fuzziness: v40);
          break;
        default:
          x = rgb->x;
          v31 = this->m_SelectedRGBs.m_Memory.m_pMemory[v6].x;
          if ( m_Fuzziness >= 0.0039215689 )
          {
            v32 = v31 - m_Fuzziness;
            if ( x <= (float)(m_Fuzziness + v31) )
            {
              if ( v32 <= x )
                v51 = (float)(x - v32) / (float)((float)(m_Fuzziness + v31) - v32);
              else
                v51 = 0.0;
            }
            else
            {
              v51 = 1.0;
            }
          }
          else if ( x < v31 )
          {
            v51 = 0.0;
          }
          else
          {
            v51 = 1.0;
          }
          break;
      }
      v7 = v49;
      if ( v51 > v49 )
      {
        v7 = v51;
        v49 = v51;
      }
      ++v6;
      if ( ++v48 >= this->m_SelectedRGBs.m_Size )
        break;
    }
  }
  if ( this->m_bInvertSelection )
    return (float)(1.0 - v7);
  return v49;
}

//------------------------------------------------------------------------------
// Address: 0x100A5D80
// Name: public: virtual void CSelectedHSVOperation::Apply(class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectedHSVOperation::Apply(CSelectedHSVOperation *this, const Vector *inRGB, Vector *outRGB)
{
  double SelectionAmount; // st7
  long double v6; // st7
  float y; // xmm0_4
  float x; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  Vector hsv; // [esp+8h] [ebp-Ch] BYREF
  float flSelectionAmount; // [esp+1Ch] [ebp+8h]

  SelectionAmount = CSelectedHSVOperation::GetSelectionAmount(this, rgb: inRGB);
  flSelectionAmount = SelectionAmount;
  if ( SelectionAmount == 0.0 || !this->m_bEnable )
  {
    *outRGB = *inRGB;
  }
  else
  {
    RGBtoHSV(rgb: inRGB, &hsv);
    if ( this->m_bColorize )
    {
      x = this->m_DeltaHSV.x;
      if ( x < 0.0 )
        x = x + 360.0;
      hsv.x = x;
      y = this->m_DeltaHSV.y;
    }
    else
    {
      v6 = fmod(this->m_DeltaHSV.x + hsv.x, 360.0);
      hsv.x = v6;
      if ( v6 < 0.0 )
        hsv.x = hsv.x + 360.0;
      y = (float)(this->m_DeltaHSV.y + 1.0) * hsv.y;
    }
    if ( y >= 0.0 )
    {
      if ( y <= 1.0 )
        v9 = y;
      else
        v9 = 1.0;
    }
    else
    {
      v9 = 0.0;
    }
    v10 = this->m_DeltaHSV.z + hsv.z;
    hsv.y = v9;
    if ( v10 >= 0.0 )
    {
      if ( v10 > 1.0 )
        v10 = 1.0;
    }
    else
    {
      v10 = 0.0;
    }
    hsv.z = v10;
    if ( v9 == 0.0 )
      hsv.x = -1.0;
    HSVtoRGB(&hsv, rgb: outRGB);
    v11 = this->m_flBlendFactor * flSelectionAmount;
    outRGB->x = (float)((float)(outRGB->x - inRGB->x) * v11) + inRGB->x;
    outRGB->y = (float)((float)(outRGB->y - inRGB->y) * v11) + inRGB->y;
    outRGB->z = (float)((float)(outRGB->z - inRGB->z) * v11) + inRGB->z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A5F10
// Name: public: virtual void CUncorrectedImagePanel::RegenerateTextureBits(class ITexture __near *,class IVTFTexture __near *,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUncorrectedImagePanel::RegenerateTextureBits(
        CUncorrectedImagePanel *this,
        ITexture *pTexture,
        IVTFTexture *pVTFTexture,
        Rect_t *pRect)
{
  IVTFTexture *v4; // esi
  IVTFTexture_vtbl *v5; // eax
  __int16 v6; // bx
  int v7; // edx
  int v8; // eax
  int v9; // ecx
  BGRA8888_t *v10; // eax
  unsigned __int8 g; // cl
  unsigned __int8 b; // dl
  unsigned int vpanel; // eax
  CSelectedHSVOperation *v14; // ecx
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm0_4
  int v19; // ecx
  int v20; // edx
  unsigned int v21; // edx
  unsigned int v22; // edx
  int v23; // eax
  unsigned __int64 v24; // rdi
  __int64 v25; // rax
  __int64 v26; // rax
  int a; // ecx
  unsigned __int64 v28; // rdi
  color24 v29; // [esp-Ch] [ebp-90h]
  int pixelWriter; // [esp+Ch] [ebp-78h]
  int pixelWriter_4; // [esp+10h] [ebp-74h]
  unsigned __int8 pixelWriter_10; // [esp+16h] [ebp-6Eh]
  int pixelWriter_12; // [esp+18h] [ebp-6Ch]
  int pixelWriter_16; // [esp+1Ch] [ebp-68h]
  int pixelWriter_20; // [esp+20h] [ebp-64h]
  int pixelWriter_24; // [esp+24h] [ebp-60h]
  int pixelWriter_28; // [esp+28h] [ebp-5Ch]
  int pixelWriter_32; // [esp+2Ch] [ebp-58h]
  Vector rgb; // [esp+30h] [ebp-54h] BYREF
  __int64 v40; // [esp+3Ch] [ebp-48h]
  int nDepth; // [esp+44h] [ebp-40h] BYREF
  int v42; // [esp+48h] [ebp-3Ch]
  float v43; // [esp+4Ch] [ebp-38h]
  float v44; // [esp+50h] [ebp-34h]
  float v45; // [esp+54h] [ebp-30h]
  int nHeight; // [esp+58h] [ebp-2Ch] BYREF
  int v47; // [esp+5Ch] [ebp-28h]
  int y; // [esp+60h] [ebp-24h]
  int nWidth; // [esp+64h] [ebp-20h] BYREF
  int x; // [esp+68h] [ebp-1Ch]
  int v51; // [esp+6Ch] [ebp-18h]
  CUncorrectedImagePanel *v52; // [esp+70h] [ebp-14h]
  int flSelectionAmount; // [esp+74h] [ebp-10h]
  BGRA8888_t *pTexel; // [esp+78h] [ebp-Ch]
  int v55; // [esp+7Ch] [ebp-8h]
  color24 inColor; // [esp+80h] [ebp-4h]
  int savedregs; // [esp+84h] [ebp+0h] BYREF

  v4 = pVTFTexture;
  v5 = pVTFTexture->__vftable;
  v52 = this;
  v5->ComputeMipLevelDimensions(this: pVTFTexture, a2: 0, a3: &nWidth, a4: &nHeight, a5: &nDepth);
  pVTFTexture = (IVTFTexture *)v4->RowSizeInBytes(this: v4, a2: 0);
  pixelWriter = (int)v4->ImageData_2(this: v4, a2: 0, a3: 0, a4: 0);
  switch ( v4->Format(this: v4) )
  {
    case IMAGE_FORMAT_RGBA8888:
    case IMAGE_FORMAT_UVWQ8888:
      pixelWriter_12 = 0x80000;
      v6 = 16;
      pixelWriter_16 = 1572880;
      goto LABEL_6;
    case IMAGE_FORMAT_BGR888:
      pixelWriter_10 = 3;
      pixelWriter_12 = 524304;
      pixelWriter_20 = 255;
      pixelWriter_24 = 255;
      pixelWriter_28 = 255;
      goto LABEL_19;
    case IMAGE_FORMAT_I8:
      pixelWriter_10 = 1;
      goto LABEL_17;
    case IMAGE_FORMAT_A8:
      v6 = 0;
      pixelWriter_10 = 1;
      pixelWriter_12 = 0;
      pixelWriter_16 = 0;
      pixelWriter_20 = 0;
      pixelWriter_24 = 0;
      pixelWriter_28 = 0;
      pixelWriter_32 = 255;
      goto LABEL_21;
    case IMAGE_FORMAT_BGRA8888:
      pixelWriter_12 = 524304;
      v6 = 0;
      pixelWriter_16 = 1572864;
LABEL_6:
      pixelWriter_10 = 4;
      pixelWriter_20 = 255;
      pixelWriter_24 = 255;
      pixelWriter_28 = 255;
      pixelWriter_32 = 255;
      goto LABEL_21;
    case IMAGE_FORMAT_BGRX8888:
      pixelWriter_10 = 4;
      pixelWriter_12 = 524304;
      v6 = 0;
      pixelWriter_16 = 1572864;
      pixelWriter_20 = 255;
      pixelWriter_24 = 255;
      pixelWriter_28 = 255;
      goto LABEL_20;
    case IMAGE_FORMAT_BGR565:
      pixelWriter_10 = 2;
      pixelWriter_12 = 196616;
      v6 = -3;
      pixelWriter_16 = 65533;
      pixelWriter_20 = 248;
      pixelWriter_24 = 252;
      pixelWriter_28 = 248;
      goto LABEL_20;
    case IMAGE_FORMAT_BGRX5551:
    case IMAGE_FORMAT_BGRA5551:
      pixelWriter_10 = 2;
      pixelWriter_12 = 131079;
      v6 = -3;
      pixelWriter_16 = 589821;
      pixelWriter_20 = 248;
      pixelWriter_24 = 248;
      pixelWriter_28 = 248;
      pixelWriter_32 = 128;
      goto LABEL_21;
    case IMAGE_FORMAT_BGRA4444:
      pixelWriter_10 = 2;
      pixelWriter_12 = 4;
      v6 = -4;
      pixelWriter_16 = 589820;
      pixelWriter_20 = 240;
      pixelWriter_24 = 240;
      pixelWriter_28 = 240;
      pixelWriter_32 = 240;
      goto LABEL_21;
    case IMAGE_FORMAT_RGBA16161616F:
    case IMAGE_FORMAT_RGBA16161616:
      pixelWriter_10 = 8;
      pixelWriter_12 = 0x100000;
      v6 = 32;
      pixelWriter_16 = 3145760;
      pixelWriter_20 = 0xFFFF;
      pixelWriter_24 = 0xFFFF;
      pixelWriter_28 = 0xFFFF;
      pixelWriter_32 = 0xFFFF;
      goto LABEL_21;
    case IMAGE_FORMAT_R32F:
      pixelWriter_10 = 4;
      pixelWriter_20 = -1;
      goto LABEL_18;
    case IMAGE_FORMAT_RGBA32323232F:
      pixelWriter_10 = 16;
      pixelWriter_12 = 0x200000;
      v6 = 64;
      pixelWriter_16 = 6291520;
      pixelWriter_20 = -1;
      pixelWriter_24 = -1;
      pixelWriter_28 = -1;
      pixelWriter_32 = -1;
      goto LABEL_21;
    case IMAGE_FORMAT_BGRA1010102:
      pixelWriter_10 = 4;
      pixelWriter_12 = 655380;
      v6 = 0;
      pixelWriter_16 = 1966080;
      pixelWriter_20 = 1023;
      pixelWriter_24 = 1023;
      pixelWriter_28 = 1023;
      pixelWriter_32 = 3;
      goto LABEL_21;
    default:
      pixelWriter_10 = 0;
LABEL_17:
      pixelWriter_20 = 255;
LABEL_18:
      pixelWriter_12 = 0;
      pixelWriter_24 = 0;
      pixelWriter_28 = 0;
LABEL_19:
      v6 = 0;
      pixelWriter_16 = 0;
LABEL_20:
      pixelWriter_32 = 0;
LABEL_21:
      v7 = 0;
      y = 0;
      if ( nHeight > 0 )
      {
        v8 = pixelWriter;
        v42 = (unsigned __int16)pVTFTexture;
        v9 = nWidth;
        v47 = pixelWriter;
        do
        {
          pixelWriter_4 = v8;
          v10 = (BGRA8888_t *)(*(_DWORD *)&v52->m_OnCommand_register + 4 * v7 * *(_DWORD *)&v52->m_OnDelete_register);
          pTexel = v10;
          x = 0;
          if ( v9 > 0 )
          {
            v51 = pixelWriter_10;
            while ( 1 )
            {
              g = v10->g;
              inColor.r = v10->r;
              b = v10->b;
              vpanel = v52->_vpanel;
              inColor.g = g;
              *(_WORD *)&v29.r = *(_WORD *)&inColor.r;
              v29.b = b;
              CColorOperationList::Apply(
                this: *(CColorOperationList **)(vpanel + 4),
                in: v29,
                out: (color24 *)&pVTFTexture,
                pFinalOp: (IColorOperation *)vpanel);
              v14 = (CSelectedHSVOperation *)v52->_vpanel;
              v45 = (float)(unsigned __int8)pVTFTexture;
              v44 = (float)BYTE1(pVTFTexture);
              v43 = (float)BYTE2(pVTFTexture);
              rgb.x = v45 * 0.0039215689;
              rgb.y = v44 * 0.0039215689;
              rgb.z = v43 * 0.0039215689;
              *(float *)&flSelectionAmount = CSelectedHSVOperation::GetSelectionAmount(
                                               this: v14,
                                               a2: (int)&savedregs,
                                               &rgb)
                                           * 0.5;
              v15 = (float)(1.0 - *(float *)&flSelectionAmount) * 0.0039215689;
              v16 = (float)((float)(v15 * v45) + *(float *)&flSelectionAmount) * 255.0;
              v17 = (float)(v15 * v44) * 255.0;
              v18 = (float)(v15 * v43) * 255.0;
              v19 = (int)v17;
              v20 = (int)v18;
              if ( (int)v16 >= 0 )
              {
                flSelectionAmount = 255;
                if ( (int)v16 <= 255 )
                  flSelectionAmount = (int)v16;
              }
              else
              {
                *(float *)&flSelectionAmount = 0.0;
              }
              if ( v19 >= 0 )
              {
                if ( v19 > 255 )
                  v19 = 255;
              }
              else
              {
                v19 = 0;
              }
              if ( v20 >= 0 )
              {
                v55 = 255;
                if ( v20 <= 255 )
                  v55 = (int)v18;
              }
              else
              {
                v55 = 0;
              }
              if ( pixelWriter_10 != 0 )
              {
                if ( pixelWriter_10 >= 5u )
                {
                  v24 = ((unsigned __int64)(flSelectionAmount & (unsigned int)pixelWriter_20) << pixelWriter_12)
                      | ((unsigned __int64)(v19 & (unsigned int)pixelWriter_24) << SBYTE2(pixelWriter_12));
                  v25 = v55 & (unsigned int)pixelWriter_28;
                  if ( v6 <= 0 )
                    v26 = v25 >> -(char)v6;
                  else
                    v26 = v25 << v6;
                  a = pTexel->a;
                  v40 = v26;
                  v28 = v26 | ((unsigned __int64)(a & (unsigned int)pixelWriter_32) << SBYTE2(pixelWriter_16)) | v24;
                  if ( v51 == 6 )
                  {
                    *(_DWORD *)pixelWriter_4 = v28;
                    *(_WORD *)(pixelWriter_4 + 4) = WORD2(v28);
                  }
                  else if ( v51 == 8 )
                  {
                    *(_QWORD *)pixelWriter_4 = v28;
                  }
                }
                else
                {
                  v21 = v55 & pixelWriter_28;
                  if ( v6 <= 0 )
                    v22 = v21 >> -(char)pixelWriter_16;
                  else
                    v22 = v21 << pixelWriter_16;
                  v23 = v22
                      | ((unsigned __int8)(pTexel->a & pixelWriter_32) << SBYTE2(pixelWriter_16))
                      | ((flSelectionAmount & pixelWriter_20) << pixelWriter_12)
                      | ((v19 & pixelWriter_24) << SBYTE2(pixelWriter_12));
                  switch ( v51 )
                  {
                    case 1:
                      *(_BYTE *)pixelWriter_4 = v23;
                      break;
                    case 2:
                      *(_WORD *)pixelWriter_4 = v23;
                      break;
                    case 3:
                      *(_WORD *)pixelWriter_4 = v23;
                      *(_BYTE *)(pixelWriter_4 + 2) = BYTE2(v23);
                      break;
                    case 4:
                      *(_DWORD *)pixelWriter_4 = v23;
                      break;
                    default:
                      break;
                  }
                }
              }
              v9 = nWidth;
              pixelWriter_4 += v51;
              ++pTexel;
              if ( ++x >= nWidth )
                break;
              v10 = pTexel;
            }
            v7 = y;
          }
          v8 = v42 + v47;
          y = ++v7;
          v47 += v42;
        }
        while ( v7 < nHeight );
      }
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A64D0
// Name: public: void CColorLookupOperation::LoadLookupTable(char const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CColorLookupOperation::LoadLookupTable(
        CColorLookupOperation *this@<ecx>,
        int a2@<edi>,
        const char *pFilename)
{
  void *v3; // ebx
  unsigned int v4; // edi
  long double v5; // st7
  int v6; // esi
  int v7; // edi
  char v8; // cl
  color24 *m_LookupTable; // eax
  unsigned int color; // [esp+8h] [ebp-4h] OVERLAPPED BYREF

  v3 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: pFilename, a3: "rb", a4: 0);
  if ( v3 != nullptr )
  {
    v4 = ((int (__thiscall *)(IBaseFileSystem *, void *, int))g_pFileSystem->Size_2)(
           a1: &g_pFileSystem->IBaseFileSystem,
           a2: v3,
           a3: a2);
    color = v4 / 3;
    v5 = pow((double)(v4 / 3), 0.3333333432674408);
    v6 = (int)v5 * (int)v5 * (int)v5;
    if ( 3 * v6 == v4 )
    {
      CColorLookupOperation::SetResolution(this, res: (int)v5);
      if ( v6 > 0 )
      {
        v7 = 0;
        do
        {
          g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: &color, a3: 3, a4: v3);
          v8 = BYTE2(color);
          BYTE2(color) = color;
          m_LookupTable = this->m_LookupTable;
          LOBYTE(color) = v8;
          *(_WORD *)&m_LookupTable[v7].r = color;
          m_LookupTable[v7++].b = BYTE2(color);
          --v6;
        }
        while ( v6 != 0 );
      }
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v3);
      _V_strcpy(dest: this->m_pFilename, src: pFilename);
      colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
    }
    else
    {
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A6600
// Name: private: virtual void CColorLookupUIPanel::OnFileSelected(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CColorLookupUIPanel::OnFileSelected(
        CColorLookupUIPanel *this@<ecx>,
        int a2@<edi>,
        const char *filename)
{
  CColorLookupOperation *m_pLookupOp; // eax
  vgui::Button_vtbl *v5; // edx

  CColorLookupOperation::LoadLookupTable(this: this->m_pLookupOp, a2, pFilename: filename);
  m_pLookupOp = this->m_pLookupOp;
  v5 = this->m_pLoadButton->__vftable;
  if ( m_pLookupOp->m_LookupTable != nullptr )
    ((void (__stdcall *)(char *))v5->SetText)(a1: m_pLookupOp->m_pFilename);
  else
    ((void (__stdcall *)(const char *))v5->SetText)(a1: "No File Loaded");
}

//------------------------------------------------------------------------------
// Address: 0x100A6650
// Name: public: virtual void CColorBalanceOperation::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorBalanceOperation::Release(CColorBalanceOperation *this)
{
  if ( this != nullptr )
  {
    this->__vftable = (CColorBalanceOperation_vtbl *)&CColorBalanceOperation::`vftable';
    free(pMem: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A6670
// Name: public: CColorBalanceOperation::CColorBalanceOperation(void)
// Source: json
//------------------------------------------------------------------------------
CColorBalanceOperation *__thiscall CColorBalanceOperation::CColorBalanceOperation(CColorBalanceOperation *this)
{
  int v2; // ecx
  float *m_HighlightsAddTransfer; // eax
  float v4; // xmm0_4
  float v5; // xmm1_4

  this->__vftable = (CColorBalanceOperation_vtbl *)&CColorBalanceOperation::`vftable';
  this->m_PreserveLuminosity = true;
  this->m_CyanRedBalance[0] = 0.0;
  this->m_MagentaGreenBalance[0] = 0.0;
  this->m_YellowBlueBalance[0] = 0.0;
  this->m_CyanRedBalance[1] = 0.0;
  this->m_MagentaGreenBalance[1] = 0.0;
  this->m_YellowBlueBalance[1] = 0.0;
  this->m_CyanRedBalance[2] = 0.0;
  this->m_MagentaGreenBalance[2] = 0.0;
  this->m_YellowBlueBalance[2] = 0.0;
  v2 = 0;
  m_HighlightsAddTransfer = this->m_HighlightsAddTransfer;
  do
  {
    v4 = (float)(1.0
               - (float)((float)((float)((float)v2 - 127.0) * 0.0078740157)
                       * (float)((float)((float)v2 - 127.0) * 0.0078740157)))
       * 0.667;
    v5 = 1.075 - (float)(1.0 / (float)((float)((float)v2 * 0.0625) + 1.0));
    *(m_HighlightsAddTransfer - 1280) = v5;
    *m_HighlightsAddTransfer = v5;
    *(m_HighlightsAddTransfer - 1024) = v4;
    *(m_HighlightsAddTransfer - 256) = v4;
    *(m_HighlightsAddTransfer - 768) = v4;
    *(m_HighlightsAddTransfer - 512) = v4;
    ++v2;
    ++m_HighlightsAddTransfer;
  }
  while ( v2 < 256 );
  this->m_bEnable = true;
  this->m_flBlendFactor = 1.0;
  CColorBalanceOperation::CreateLookupTables(this);
  _V_strcpy(dest: this->m_pName, src: "Balance");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A6790
// Name: public: virtual class IColorOperation __near * CColorBalanceOperation::Clone(void)
// Source: json
//------------------------------------------------------------------------------
CColorBalanceOperation *__thiscall CColorBalanceOperation::Clone(CColorBalanceOperation *this)
{
  CColorBalanceOperation *v2; // eax
  CColorBalanceOperation *v3; // esi

  v2 = (CColorBalanceOperation *)MemAlloc_Alloc(nSize: 0x1C34u);
  if ( v2 != nullptr )
    v3 = CColorBalanceOperation::CColorBalanceOperation(this: v2);
  else
    v3 = nullptr;
  v3->m_PreserveLuminosity = this->m_PreserveLuminosity;
  v3->m_flBlendFactor = this->m_flBlendFactor;
  v3->m_bEnable = this->m_bEnable;
  _V_memcpy(dest: (unsigned __int8 *)v3->m_CyanRedBalance, src: (unsigned __int8 *)this->m_CyanRedBalance, count: 0xCu);
  _V_memcpy(
    dest: (unsigned __int8 *)v3->m_MagentaGreenBalance,
    src: (unsigned __int8 *)this->m_MagentaGreenBalance,
    count: 0xCu);
  _V_memcpy(
    dest: (unsigned __int8 *)v3->m_YellowBlueBalance,
    src: (unsigned __int8 *)this->m_YellowBlueBalance,
    count: 0xCu);
  _V_memcpy(
    dest: (unsigned __int8 *)v3->m_ShadowsSubTransfer,
    src: (unsigned __int8 *)this->m_ShadowsSubTransfer,
    count: 0x400u);
  _V_memcpy(
    dest: (unsigned __int8 *)v3->m_MidtonesSubTransfer,
    src: (unsigned __int8 *)this->m_MidtonesSubTransfer,
    count: 0x400u);
  _V_memcpy(
    dest: (unsigned __int8 *)v3->m_HighlightsSubTransfer,
    src: (unsigned __int8 *)this->m_HighlightsSubTransfer,
    count: 0x400u);
  _V_memcpy(
    dest: (unsigned __int8 *)v3->m_ShadowsAddTransfer,
    src: (unsigned __int8 *)this->m_ShadowsAddTransfer,
    count: 0x400u);
  _V_memcpy(
    dest: (unsigned __int8 *)v3->m_MidtonesAddTransfer,
    src: (unsigned __int8 *)this->m_MidtonesAddTransfer,
    count: 0x400u);
  _V_memcpy(
    dest: (unsigned __int8 *)v3->m_HighlightsAddTransfer,
    src: (unsigned __int8 *)this->m_HighlightsAddTransfer,
    count: 0x400u);
  _V_memcpy(dest: v3->m_pRedLookup, src: this->m_pRedLookup, count: 0x100u);
  _V_memcpy(dest: v3->m_pGreenLookup, src: this->m_pGreenLookup, count: 0x100u);
  _V_memcpy(dest: v3->m_pBlueLookup, src: this->m_pBlueLookup, count: 0x100u);
  _V_memcpy(dest: (unsigned __int8 *)v3->m_pName, src: (unsigned __int8 *)this->m_pName, count: 0x100u);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100A6900
// Name: public: CNewOperationDialog::CNewOperationDialog(class vgui::Panel __near *,class CColorOperationList __near *)
// Source: json
//------------------------------------------------------------------------------
CNewOperationDialog *__thiscall CNewOperationDialog::CNewOperationDialog(
        CNewOperationDialog *this,
        vgui::Panel *parent,
        CColorOperationList *pOpList)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::ComboBox *v7; // eax
  vgui::ComboBox *v8; // eax
  vgui::TextEntry *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  vgui::Button *v14; // eax

  vgui::Frame::Frame(this, parent, panelName: "NewOperation", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CNewOperationDialog_vtbl *)&CNewOperationDialog::`vftable';
  if ( `CNewOperationDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CNewOperationDialog::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CNewOperationDialog");
    v4->pfnClassName = CNewOperationDialog::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CNewOperationDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CNewOperationDialog::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CNewOperationDialog");
    v5->pfnClassName = CNewOperationDialog::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CNewOperationDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CNewOperationDialog::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CNewOperationDialog");
    v6->pfnClassName = CNewOperationDialog::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  v7 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v7 != nullptr )
    v8 = vgui::ComboBox::ComboBox(this: v7, parent: this, panelName: "OperationType", numLines: 6, allowEdit: false);
  else
    v8 = nullptr;
  this->m_pOperationType = v8;
  v9 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v9 != nullptr )
    v10 = vgui::TextEntry::TextEntry(this: v9, parent: this, panelName: "Name");
  else
    v10 = nullptr;
  this->m_pName = v10;
  v11 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: this,
            panelName: "Create",
            text: "Create",
            pActionSignalTarget: this,
            pCmd: "Create");
  else
    v12 = nullptr;
  this->m_pCreateButton = v12;
  v13 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v13 != nullptr )
    v14 = vgui::Button::Button(
            this: v13,
            parent: this,
            panelName: "Cancel",
            text: "Cancel",
            pActionSignalTarget: this,
            pCmd: "Cancel");
  else
    v14 = nullptr;
  this->m_pCancelButton = v14;
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource\\NewOperationDialog.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  CNewOperationDialog::PopulateControls(this);
  this->m_pOpList = pOpList;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A6AA0
// Name: private: virtual void CColorOperationListPanel::OnSliderMoved(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorOperationListPanel::OnSliderMoved(CColorOperationListPanel *this, KeyValues *data)
{
  int v3; // edi
  IColorOperation *v4; // ebx
  IColorOperation_vtbl *v5; // edi
  int v6; // eax
  int i; // edi
  CColorCorrectionUIChildPanel *v8; // ecx
  KeyValues *v9; // eax
  KeyValues *v10; // eax

  if ( KeyValues::GetPtr(this: data, keyName: "panel", defaultValue: nullptr) == this->m_pBlendFactorSlider )
  {
    v3 = this->m_pOperationListPanel->GetSelectedItem(this: this->m_pOperationListPanel, a2: 0);
    if ( v3 >= 0 && this->m_pOperationListPanel->IsValidItemID(this: this->m_pOperationListPanel, a2: v3) )
    {
      v4 = (IColorOperation *)this->m_pOperationListPanel->GetItemUserData(this: this->m_pOperationListPanel, a2: v3);
      v5 = v4->__vftable;
      v6 = this->m_pBlendFactorSlider->GetValue(this: this->m_pBlendFactorSlider);
      ((void (__thiscall *)(IColorOperation *, _DWORD))v5->SetBlendFactor)(a1: v4, a2: (float)v6 * 0.0039215689);
      for ( i = 0; i < this->m_OpPanelList.m_Size; ++i )
      {
        v8 = this->m_OpPanelList.m_Memory.m_pMemory[i];
        if ( v8->GetOperation(this: v8) == v4 )
        {
          v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v9 != nullptr )
            v10 = KeyValues::KeyValues(
                    this: v9,
                    setName: "command",
                    firstKey: "command",
                    firstValue: "BlendFactorUpdate");
          else
            v10 = nullptr;
          ((void (__thiscall *)(CColorOperationListPanel *, CColorCorrectionUIChildPanel *, KeyValues *, _DWORD))this->PostMessage)(
            a1: this,
            a2: this->m_OpPanelList.m_Memory.m_pMemory[i],
            a3: v10,
            a4: 0.0);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A6BB0
// Name: public: void CColorOperationListPanel::PopulateList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorOperationListPanel::PopulateList(CColorOperationListPanel *this)
{
  int m_Size; // ecx
  int v3; // eax
  IColorOperation *v4; // esi
  KeyValues *v5; // edi
  const char *v6; // eax
  KeyValues *v7; // edi
  bool v8; // al
  int numItems; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  this->m_pOperationListPanel->DeleteAllItems(this: this->m_pOperationListPanel);
  m_Size = this->m_OperationList.m_OpList.m_Size;
  v3 = 0;
  numItems = m_Size;
  for ( i = 0; v3 < m_Size; i = v3 )
  {
    if ( v3 >= 0 && v3 < this->m_OperationList.m_OpList.m_Size )
    {
      v4 = this->m_OperationList.m_OpList.m_Memory.m_pMemory[v3];
      if ( v4 != nullptr )
      {
        v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v5 != nullptr )
        {
          v6 = v4->GetName(this: v4);
          v7 = KeyValues::KeyValues(this: v5, setName: "operation", firstKey: "layer", firstValue: v6);
        }
        else
        {
          v7 = nullptr;
        }
        v8 = v4->IsEnabled(this: v4);
        KeyValues::SetInt(this: v7, keyName: "image", value: v8);
        this->m_pOperationListPanel->AddItem(
          this: this->m_pOperationListPanel,
          a2: v7,
          a3: (unsigned int)v4,
          a4: false,
          a5: false);
        v3 = i;
        m_Size = numItems;
      }
    }
    ++v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A6C80
// Name: public: void CColorOperationListPanel::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorOperationListPanel::Shutdown(CColorOperationListPanel *this)
{
  int i; // esi
  IColorOperation *v3; // ecx

  this->m_pLookupViewWindow->Shutdown(this: this->m_pLookupViewWindow);
  for ( i = this->m_OperationList.m_OpList.m_Size - 1; i >= 0; --i )
  {
    v3 = this->m_OperationList.m_OpList.m_Memory.m_pMemory[i];
    v3->Release(this: v3);
  }
  this->m_OperationList.m_OpList.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100A6CC0
// Name: public: virtual void CColorCorrectionUIPanel::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionUIPanel::OnThink(CColorCorrectionUIPanel *this)
{
  int m_nCurrentRow; // ecx
  __int16 v3; // bx
  __int16 v4; // bx
  unsigned __int16 v5; // bx
  int v6; // eax
  char *v7; // esi
  double v8; // st7
  double v9; // st7
  bool v10; // zf
  color24 v11; // [esp-8h] [ebp-48h]
  float flLinearValue; // [esp+0h] [ebp-40h]
  float flLinearValuea; // [esp+0h] [ebp-40h]
  float flLinearValueb; // [esp+0h] [ebp-40h]
  float flLinearValuec; // [esp+0h] [ebp-40h]
  float flLinearValued; // [esp+0h] [ebp-40h]
  float flLinearValuee; // [esp+0h] [ebp-40h]
  int i; // [esp+14h] [ebp-2Ch]
  int v19; // [esp+18h] [ebp-28h]
  int v20; // [esp+1Ch] [ebp-24h]
  __int16 v21; // [esp+20h] [ebp-20h]
  unsigned __int16 v22; // [esp+20h] [ebp-20h]
  __int16 fl360GammaValue; // [esp+24h] [ebp-1Ch]
  __int16 v24; // [esp+28h] [ebp-18h]
  _BYTE v25[4]; // [esp+2Ch] [ebp-14h] BYREF
  color24 in; // [esp+30h] [ebp-10h] BYREF
  int v27; // [esp+34h] [ebp-Ch] BYREF
  color24 out; // [esp+38h] [ebp-8h] BYREF

  vgui::Frame::OnThink(this);
  if ( this->m_bForceReset )
  {
    colorcorrection->LockLookup(this: colorcorrection, a2: this->m_CCHandle);
    colorcorrection->ResetLookup_2(this: colorcorrection, a2: this->m_CCHandle);
    colorcorrection->UnlockLookup(this: colorcorrection, a2: this->m_CCHandle, a3: true);
    this->m_bForceReset = false;
  }
  m_nCurrentRow = this->m_nCurrentRow;
  if ( m_nCurrentRow != -1 )
  {
    v3 = ((unsigned __int8)v21 ^ (unsigned __int8)m_nCurrentRow) & 0x1F ^ v21;
    v20 = this->m_nCurrentRow;
    if ( m_nCurrentRow < 32 )
    {
      while ( m_nCurrentRow < this->m_nCurrentRow + 32 / this->m_nRowStep )
      {
        v4 = v3 & 0xFC1F;
        for ( i = 32; i != 0; --i )
        {
          v5 = v4 & 0x83FF;
          v22 = v5;
          v19 = 32;
          do
          {
            ((void (__thiscall *)(IColorCorrectionSystem *, int *, unsigned __int16))colorcorrection->ConvertToColor24)(
              a1: colorcorrection,
              a2: &v27,
              a3: v22);
            if ( this->m_bEnable )
              CColorOperationList::Apply(
                this: &this->m_pOperationListPanel->m_OperationList,
                in: (color24)v27,
                out: &in,
                pFinalOp: this->m_pFinalOperation);
            else
              in = (color24)v27;
            v6 = 32 * (((v5 >> 5) & 0x1F) + 32 * ((v5 >> 10) & 0x1F));
            v7 = (char *)this + 2 * (v5 & 0x1F) + 2 * v6 + (v5 & 0x1F) + v6;
            *(color24 *)(v7 + 556) = in;
            ((void (__thiscall *)(IColorCorrectionSystem *, _BYTE *, unsigned __int16))colorcorrection->ConvertToColor24)(
              a1: colorcorrection,
              a2: v25,
              a3: v22);
            flLinearValue = X360GammaToLinear(fl360GammaValue: (float)v25[0] * 0.0039215689);
            LOBYTE(v24) = (int)(SrgbLinearToGamma(flLinearValue) * 255.0);
            flLinearValuea = X360GammaToLinear(fl360GammaValue: (float)v25[1] * 0.0039215689);
            HIBYTE(v24) = (int)(SrgbLinearToGamma(flLinearValue: flLinearValuea) * 255.0);
            flLinearValueb = X360GammaToLinear(fl360GammaValue: (float)v25[2] * 0.0039215689);
            v8 = SrgbLinearToGamma(flLinearValue: flLinearValueb) * 255.0;
            if ( this->m_bEnable )
            {
              *(_WORD *)&v11.r = v24;
              v11.b = (int)v8;
              CColorOperationList::Apply(
                this: &this->m_pOperationListPanel->m_OperationList,
                in: v11,
                &out,
                pFinalOp: this->m_pFinalOperation);
            }
            else
            {
              *(_WORD *)&out.r = v24;
              out.b = (int)v8;
            }
            flLinearValuec = SrgbGammaToLinear(flSrgbGammaValue: (float)out.r * 0.0039215689);
            LOBYTE(fl360GammaValue) = (int)(X360LinearToGamma(flLinearValue: flLinearValuec) * 255.0);
            flLinearValued = SrgbGammaToLinear(flSrgbGammaValue: (float)out.g * 0.0039215689);
            HIBYTE(fl360GammaValue) = (int)(X360LinearToGamma(flLinearValue: flLinearValued) * 255.0);
            flLinearValuee = SrgbGammaToLinear(flSrgbGammaValue: (float)out.b * 0.0039215689);
            v9 = X360LinearToGamma(flLinearValue: flLinearValuee);
            v5 ^= (v22 ^ ((v22 & 0xFC00) + 1024)) & 0x7C00;
            v10 = v19-- == 1;
            *((_WORD *)v7 + 49430) = fl360GammaValue;
            v7[98862] = (int)(v9 * 255.0);
            v22 = v5;
          }
          while ( !v10 );
          v4 = (v5 ^ ((v5 & 0xFFE0) + 32)) & 0x3E0 ^ v5;
        }
        v3 = ((unsigned __int8)v4 ^ (unsigned __int8)(v4 + 1)) & 0x1F ^ v4;
        if ( ++v20 >= 32 )
          break;
        m_nCurrentRow = v20;
      }
    }
    this->m_nCurrentRow += 32 / this->m_nRowStep;
    if ( this->m_nCurrentRow == 32 )
    {
      colorcorrection->LockLookup(this: colorcorrection, a2: this->m_CCHandle);
      colorcorrection->CopyLookup(this: colorcorrection, a2: this->m_CCHandle, a3: this->m_pLookupCache);
      colorcorrection->UnlockLookup(this: colorcorrection, a2: this->m_CCHandle, a3: true);
      CProceduralTexturePanel::DownloadTexture(this: this->m_pOperationListPanel->m_pLookupViewWindow->m_pLookupPanel);
      this->m_nCurrentRow = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A7140
// Name: public: void CColorCorrectionUIPanel::ReadUncorrectedImage(struct Rect_t __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionUIPanel::ReadUncorrectedImage(
        CColorCorrectionUIPanel *this,
        Rect_t *pSrcRect,
        unsigned __int8 *pPreviewImage)
{
  CColorOperationListPanel *m_pOperationListPanel; // edi
  int i; // esi
  CColorCorrectionUIChildPanel *v5; // ecx

  m_pOperationListPanel = this->m_pOperationListPanel;
  for ( i = 0; i < m_pOperationListPanel->m_OpPanelList.m_Size; ++i )
  {
    v5 = m_pOperationListPanel->m_OpPanelList.m_Memory.m_pMemory[i];
    v5->ReadUncorrectedImage(this: v5, a2: pSrcRect, a3: pPreviewImage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A7190
// Name: public: virtual void CColorCorrectionTools::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionTools::Shutdown(CColorCorrectionTools *this)
{
  CColorOperationListPanel *m_pOperationListPanel; // ecx

  if ( g_pColorCorrectionUI != nullptr )
  {
    m_pOperationListPanel = g_pColorCorrectionUI->m_pOperationListPanel;
    if ( m_pOperationListPanel != nullptr )
      CColorOperationListPanel::Shutdown(this: m_pOperationListPanel);
  }
  free(pMem: this->m_pPreviewImage);
}

//------------------------------------------------------------------------------
// Address: 0x100A71C0
// Name: public: int CUtlSortVector<class Vector,class CCurvesColorOperation::CurvesLessFunc>::Find(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<Vector,CCurvesColorOperation::CurvesLessFunc>::Find(
        CUtlSortVector<Vector,CCurvesColorOperation::CurvesLessFunc> *this,
        const Vector *src)
{
  int v3; // edx
  int v4; // ecx
  Vector *m_pMemory; // esi
  float x; // xmm1_4
  int result; // eax
  float v8; // xmm0_4

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
         215,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/utlsortvector.h",
                            a2: 215,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
      a2: 215);
  }
  v3 = 0;
  v4 = this->m_Size - 1;
  if ( v4 >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    x = src->x;
    do
    {
      result = (v4 + v3) >> 1;
      v8 = m_pMemory[result].x;
      if ( x <= v8 )
      {
        if ( v8 <= x )
          return result;
        v4 = result - 1;
      }
      else
      {
        v3 = result + 1;
      }
    }
    while ( v3 <= v4 );
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100A7270
// Name: public: int CUtlSortVector<class Vector,class CCurvesColorOperation::CurvesLessFunc>::FindLessOrEqual(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<Vector,CCurvesColorOperation::CurvesLessFunc>::FindLessOrEqual(
        CUtlSortVector<Vector,CCurvesColorOperation::CurvesLessFunc> *this,
        const Vector *src)
{
  int v3; // edx
  int v4; // ecx
  Vector *m_pMemory; // esi
  float x; // xmm1_4
  int result; // eax
  float v8; // xmm0_4

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
         277,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/utlsortvector.h",
                            a2: 277,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
      a2: 277);
  }
  v3 = 0;
  v4 = this->m_Size - 1;
  if ( v4 >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    x = src->x;
    do
    {
      result = (v4 + v3) >> 1;
      v8 = m_pMemory[result].x;
      if ( x <= v8 )
      {
        if ( v8 <= x )
          return result;
        v4 = result - 1;
      }
      else
      {
        v3 = result + 1;
      }
    }
    while ( v3 <= v4 );
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100A7320
// Name: public: void CColorOperationList::DeleteOperation(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorOperationList::DeleteOperation(CColorOperationList *this, int opIndex)
{
  int m_Size; // eax
  int v4; // eax

  if ( opIndex >= 0 )
  {
    m_Size = this->m_OpList.m_Size;
    if ( opIndex < m_Size )
    {
      v4 = m_Size - opIndex - 1;
      if ( v4 > 0 )
        _V_memmove(
          dest: &this->m_OpList.m_Memory.m_pMemory[opIndex],
          src: &this->m_OpList.m_Memory.m_pMemory[opIndex + 1],
          count: 4 * v4);
      --this->m_OpList.m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A7360
// Name: private: void CCurvesColorOperation::UpdateOutColorArray(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurvesColorOperation::UpdateOutColorArray(CCurvesColorOperation *this)
{
  CCurvesColorOperation *v1; // esi
  float v2; // edi
  CUtlSortVector<Vector,CCurvesColorOperation::CurvesLessFunc> *p_m_ControlPoints; // ebx
  float v4; // xmm0_4
  int LessOrEqual; // eax
  float y; // xmm0_4
  int m_Size; // ecx
  Vector *m_pMemory; // esi
  int v9; // eax
  float x; // eax
  Vector *flInColor; // [esp+0h] [ebp-38h] BYREF
  int v12; // [esp+4h] [ebp-34h]
  int v13; // [esp+8h] [ebp-30h]
  int v14; // [esp+Ch] [ebp-2Ch]
  Vector pControlPoints; // [esp+10h] [ebp-28h] BYREF
  Vector v16; // [esp+1Ch] [ebp-1Ch] BYREF
  CCurvesColorOperation *v17; // [esp+28h] [ebp-10h]
  Vector src; // [esp+2Ch] [ebp-Ch]

  v1 = this;
  v2 = 0.0;
  v17 = this;
  src.y = 0.0;
  v16.y = 0.0;
  v16.z = 0.0;
  p_m_ControlPoints = &this->m_ControlPoints;
  LODWORD(src.x) = this->m_pOutValue;
  do
  {
    v4 = (float)SLODWORD(v2) * 0.0039215689;
    if ( v4 >= 0.0 )
    {
      if ( v4 > 1.0 )
        v4 = 1.0;
    }
    else
    {
      v4 = 0.0;
    }
    src.z = v4;
    v16.x = v4;
    LessOrEqual = CUtlSortVector<Vector,CCurvesColorOperation::CurvesLessFunc>::FindLessOrEqual(
                    this: p_m_ControlPoints,
                    src: &v16);
    if ( LessOrEqual >= 0 )
    {
      m_Size = v1->m_ControlPoints.m_Size;
      if ( LessOrEqual == m_Size - 1 )
      {
        y = p_m_ControlPoints->m_Memory.m_pMemory[m_Size - 1].y;
      }
      else
      {
        m_pMemory = p_m_ControlPoints->m_Memory.m_pMemory;
        if ( LessOrEqual < 1 )
          flInColor = p_m_ControlPoints->m_Memory.m_pMemory;
        else
          flInColor = &m_pMemory[LessOrEqual - 1];
        v12 = (int)&p_m_ControlPoints->m_Memory.m_pMemory[LessOrEqual];
        v9 = LessOrEqual + 2;
        v13 = v12 + 12;
        if ( v9 >= m_Size )
          v14 = (int)&m_pMemory[m_Size - 1];
        else
          v14 = (int)&m_pMemory[v9];
        ComputeSplinePoint(flInColor: src.z, pControlPoints: &flInColor, vecOut: &pControlPoints);
        y = pControlPoints.y;
        v1 = v17;
        v2 = src.y;
      }
    }
    else
    {
      y = p_m_ControlPoints->m_Memory.m_pMemory->y;
    }
    x = src.x;
    ++LODWORD(v2);
    *(float *)LODWORD(src.x) = y;
    src.y = v2;
    LODWORD(src.x) = LODWORD(x) + 4;
  }
  while ( SLODWORD(v2) < 256 );
}

//------------------------------------------------------------------------------
// Address: 0x100A7480
// Name: public: virtual bool CLevelsColorOperation::Serialize(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CLevelsColorOperation::Serialize(CLevelsColorOperation *this, CDmxElement *pElement)
{
  CDmxAttribute *v3; // edi
  _DWORD *m_pData; // edi
  CDmxAttribute *v5; // edi
  float *v6; // edi
  CDmxAttribute *v7; // edi
  _BYTE *v8; // edi
  CDmxAttribute *v9; // edi
  float *v10; // edi
  CDmxAttribute *v11; // edi
  float *v12; // edi
  CDmxAttribute *v13; // edi
  float *v14; // edi
  CDmxAttribute *v15; // edi
  float *v16; // edi
  CDmxAttribute *v17; // edi
  float *v18; // edi

  CDmxElement::SetName(this: pElement, pName: this->m_pName);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v3 = CDmxElement::AddAttribute(this: pElement, pAttributeName: (CDmxAttribute *)"channelMask");
  CDmxAttribute::AllocateDataMemory(this: v3, type: AT_INT);
  m_pData = v3->m_pData;
  if ( m_pData != nullptr )
    *m_pData = this->m_nChannelMask;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v5 = CDmxElement::AddAttribute(this: pElement, pAttributeName: (CDmxAttribute *)"blendFactor");
  CDmxAttribute::AllocateDataMemory(this: v5, type: AT_FLOAT);
  v6 = (float *)v5->m_pData;
  if ( v6 != nullptr )
    *v6 = this->m_flBlendFactor;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v7 = CDmxElement::AddAttribute(this: pElement, pAttributeName: (CDmxAttribute *)"enabled");
  CDmxAttribute::AllocateDataMemory(this: v7, type: AT_BOOL);
  v8 = v7->m_pData;
  if ( v8 != nullptr )
    *v8 = this->m_bEnable;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v9 = CDmxElement::AddAttribute(this: pElement, pAttributeName: (CDmxAttribute *)"minInputLevel");
  CDmxAttribute::AllocateDataMemory(this: v9, type: AT_FLOAT);
  v10 = (float *)v9->m_pData;
  if ( v10 != nullptr )
    *v10 = this->m_flMinInputLevel;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v11 = CDmxElement::AddAttribute(this: pElement, pAttributeName: (CDmxAttribute *)"midInputLevel");
  CDmxAttribute::AllocateDataMemory(this: v11, type: AT_FLOAT);
  v12 = (float *)v11->m_pData;
  if ( v12 != nullptr )
    *v12 = this->m_flMidInputLevel;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v13 = CDmxElement::AddAttribute(this: pElement, pAttributeName: (CDmxAttribute *)"maxInputLevel");
  CDmxAttribute::AllocateDataMemory(this: v13, type: AT_FLOAT);
  v14 = (float *)v13->m_pData;
  if ( v14 != nullptr )
    *v14 = this->m_flMaxInputLevel;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v15 = CDmxElement::AddAttribute(this: pElement, pAttributeName: (CDmxAttribute *)"minOutputLevel");
  CDmxAttribute::AllocateDataMemory(this: v15, type: AT_FLOAT);
  v16 = (float *)v15->m_pData;
  if ( v16 != nullptr )
    *v16 = this->m_flMinOutputLevel;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v17 = CDmxElement::AddAttribute(this: pElement, pAttributeName: (CDmxAttribute *)"maxOutputLevel");
  CDmxAttribute::AllocateDataMemory(this: v17, type: AT_FLOAT);
  v18 = (float *)v17->m_pData;
  if ( v18 != nullptr )
    *v18 = this->m_flMaxOutputLevel;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A7690
// Name: public: virtual bool CLevelsColorOperation::Unserialize(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CLevelsColorOperation::Unserialize(CLevelsColorOperation *this, CDmxElement *pElement)
{
  const char *Name; // eax
  const CDmxAttribute *Attribute; // eax
  int *m_pData; // eax
  const CDmxAttribute *v6; // eax
  int *v7; // eax
  const CDmxAttribute *v8; // eax
  char *v9; // eax
  const CDmxAttribute *v10; // eax
  int *v11; // eax
  const CDmxAttribute *v12; // eax
  int *v13; // eax
  const CDmxAttribute *v14; // eax
  int *v15; // eax
  const CDmxAttribute *v16; // eax
  int *v17; // eax
  const CDmxAttribute *v18; // eax
  int *v19; // eax

  Name = CDmxElement::GetName(this: pElement);
  V_strncpy(pDest: this->m_pName, pSrc: Name, maxLen: 256);
  Attribute = CDmxElement::GetAttribute(this: pElement, pAttributeName: "channelMask");
  if ( Attribute != nullptr )
  {
    if ( Attribute->m_Type == AT_INT )
    {
      m_pData = (int *)Attribute->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<int>'::`4'::defaultValue = 0;
      m_pData = &`CDmxAttribute::GetValue<int>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<int>'::`4'::defaultValue = 0;
    m_pData = &`CDmxElement::GetValue<int>'::`4'::defaultValue;
  }
  this->m_nChannelMask = *m_pData;
  v6 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "blendFactor");
  if ( v6 != nullptr )
  {
    if ( v6->m_Type == AT_FLOAT )
    {
      v7 = (int *)v6->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
      v7 = &`CDmxAttribute::GetValue<float>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
    v7 = &`CDmxElement::GetValue<float>'::`4'::defaultValue;
  }
  this->m_flBlendFactor = *(float *)v7;
  v8 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "enabled");
  if ( v8 != nullptr )
  {
    if ( v8->m_Type == AT_BOOL )
    {
      v9 = (char *)v8->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<bool>'::`4'::defaultValue = 0;
      v9 = &`CDmxAttribute::GetValue<bool>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<bool>'::`4'::defaultValue = 0;
    v9 = &`CDmxElement::GetValue<bool>'::`4'::defaultValue;
  }
  this->m_bEnable = *v9;
  v10 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "minInputLevel");
  if ( v10 != nullptr )
  {
    if ( v10->m_Type == AT_FLOAT )
    {
      v11 = (int *)v10->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
      v11 = &`CDmxAttribute::GetValue<float>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
    v11 = &`CDmxElement::GetValue<float>'::`4'::defaultValue;
  }
  this->m_flMinInputLevel = *(float *)v11;
  v12 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "midInputLevel");
  if ( v12 != nullptr )
  {
    if ( v12->m_Type == AT_FLOAT )
    {
      v13 = (int *)v12->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
      v13 = &`CDmxAttribute::GetValue<float>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
    v13 = &`CDmxElement::GetValue<float>'::`4'::defaultValue;
  }
  this->m_flMidInputLevel = *(float *)v13;
  v14 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "maxInputLevel");
  if ( v14 != nullptr )
  {
    if ( v14->m_Type == AT_FLOAT )
    {
      v15 = (int *)v14->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
      v15 = &`CDmxAttribute::GetValue<float>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
    v15 = &`CDmxElement::GetValue<float>'::`4'::defaultValue;
  }
  this->m_flMaxInputLevel = *(float *)v15;
  v16 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "minOutputLevel");
  if ( v16 != nullptr )
  {
    if ( v16->m_Type == AT_FLOAT )
    {
      v17 = (int *)v16->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
      v17 = &`CDmxAttribute::GetValue<float>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
    v17 = &`CDmxElement::GetValue<float>'::`4'::defaultValue;
  }
  this->m_flMinOutputLevel = *(float *)v17;
  v18 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "maxOutputLevel");
  if ( v18 != nullptr )
  {
    if ( v18->m_Type == AT_FLOAT )
    {
      v19 = (int *)v18->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
      v19 = &`CDmxAttribute::GetValue<float>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
    v19 = &`CDmxElement::GetValue<float>'::`4'::defaultValue;
  }
  this->m_flMaxOutputLevel = *(float *)v19;
  CLevelsColorOperation::UpdateOutputLevelArray(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A78E0
// Name: public: virtual void CColorLookupOperation::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorLookupOperation::Release(CColorLookupOperation *this)
{
  color24 *m_LookupTable; // eax

  if ( this != nullptr )
  {
    m_LookupTable = this->m_LookupTable;
    this->__vftable = (CColorLookupOperation_vtbl *)&CColorLookupOperation::`vftable';
    if ( m_LookupTable != nullptr )
    {
      this->m_Resolution = 0;
      free(pMem: m_LookupTable);
    }
    free(pMem: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A7920
// Name: public: virtual bool CColorLookupOperation::Serialize(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CColorLookupOperation::Serialize(CColorLookupOperation *this, CDmxElement *pElement)
{
  CDmxAttribute *v3; // edi
  float *m_pData; // edi
  CDmxAttribute *v5; // edi
  _BYTE *v6; // edi
  CDmxAttribute *v7; // eax

  CDmxElement::SetName(this: pElement, pName: this->m_pName);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v3 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "blendFactor");
  CDmxAttribute::AllocateDataMemory(this: v3, type: AT_FLOAT);
  m_pData = (float *)v3->m_pData;
  if ( m_pData != nullptr )
    *m_pData = this->m_flBlendFactor;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v5 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "enabled");
  CDmxAttribute::AllocateDataMemory(this: v5, type: AT_BOOL);
  v6 = v5->m_pData;
  if ( v6 != nullptr )
    *v6 = this->m_bEnable;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v7 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "fileName");
  CDmxAttribute::SetValue(this: v7, pString: this->m_pFilename);
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A79F0
// Name: public: virtual bool CColorLookupOperation::Unserialize(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CColorLookupOperation::Unserialize(CColorLookupOperation *this, CDmxElement *pElement)
{
  const char *Name; // eax
  const CDmxAttribute *Attribute; // eax
  int *m_pData; // eax
  const CDmxAttribute *v6; // eax
  char *v7; // eax
  const CDmxAttribute *v8; // eax
  const char *v9; // eax

  Name = CDmxElement::GetName(this: pElement);
  V_strncpy(pDest: this->m_pName, pSrc: Name, maxLen: 256);
  Attribute = CDmxElement::GetAttribute(this: pElement, pAttributeName: "blendFactor");
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
  this->m_flBlendFactor = *(float *)m_pData;
  v6 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "enabled");
  if ( v6 != nullptr )
  {
    if ( v6->m_Type == AT_BOOL )
    {
      v7 = (char *)v6->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<bool>'::`4'::defaultValue = 0;
      v7 = &`CDmxAttribute::GetValue<bool>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<bool>'::`4'::defaultValue = 0;
    v7 = &`CDmxElement::GetValue<bool>'::`4'::defaultValue;
  }
  this->m_bEnable = *v7;
  v8 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "fileName");
  if ( v8 != nullptr && v8->m_Type == AT_STRING )
  {
    v9 = CUtlString::operator char const *(this: (CUtlString *)v8->m_pData);
    CColorLookupOperation::LoadLookupTable(this, pFilename: v9);
    return 1;
  }
  else
  {
    CColorLookupOperation::LoadLookupTable(this, pFilename: defaultValue);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A7AE0
// Name: public: void CColorBalanceOperation::SetYellowBlueBalance(enum ColorBalanceMode_t,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorBalanceOperation::SetYellowBlueBalance(
        CColorBalanceOperation *this,
        ColorBalanceMode_t mode,
        float value)
{
  this->m_YellowBlueBalance[mode] = value;
  CColorBalanceOperation::CreateLookupTables(this);
  colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
}

//------------------------------------------------------------------------------
// Address: 0x100A7B10
// Name: public: virtual void CColorBalanceUIPanel::OnMessage(class KeyValues const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorBalanceUIPanel::OnMessage(
        CColorBalanceUIPanel *this,
        KeyValues *params,
        const KeyValues *fromPanel)
{
  const char *Name; // eax
  CPrecisionSlider *Ptr; // eax
  CColorBalanceOperation_vtbl *v6; // edi
  float v7; // xmm0_4
  KeyValues *v8; // eax
  KeyValues *v9; // eax
  CColorBalanceUIPanel_vtbl *v10; // edi
  int v11; // eax
  ColorBalanceMode_t CurrentMode; // eax
  CColorBalanceOperation *m_pBalanceOp; // ecx
  ColorBalanceMode_t v14; // eax
  ColorBalanceMode_t v15; // eax
  const char *v16; // eax
  int Int; // eax
  float v18; // [esp+0h] [ebp-Ch]
  float v19; // [esp+18h] [ebp+Ch]
  float v20; // [esp+18h] [ebp+Ch]

  vgui::Panel::OnMessage(this, params, ifromPanel: fromPanel);
  Name = KeyValues::GetName(this: params);
  if ( _V_stricmp(s1: "SliderMoved", s2: Name) != 0 )
  {
    v16 = KeyValues::GetName(this: params);
    if ( _V_stricmp(s1: "CheckButtonChecked", s2: v16) != 0
      || KeyValues::GetPtr(this: params, keyName: "panel", defaultValue: nullptr) != this->m_pPreserveLuminosityButton )
    {
      return;
    }
    Int = KeyValues::GetInt(this: params, keyName: "state", defaultValue: 0);
    m_pBalanceOp = this->m_pBalanceOp;
    m_pBalanceOp->m_PreserveLuminosity = Int != 0;
LABEL_16:
    CColorBalanceOperation::CreateLookupTables(this: m_pBalanceOp);
    colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
    return;
  }
  Ptr = (CPrecisionSlider *)KeyValues::GetPtr(this: params, keyName: "panel", defaultValue: nullptr);
  if ( Ptr == this->m_pBlendFactorSlider )
  {
    v6 = this->m_pBalanceOp->__vftable;
    v7 = (float)this->m_pBlendFactorSlider->GetValue(this: this->m_pBlendFactorSlider) * 0.0039215689;
    ((void (__thiscall *)(CColorBalanceOperation *, _DWORD))v6->SetBlendFactor)(a1: this->m_pBalanceOp, a2: LODWORD(v7));
    v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v8 != nullptr )
      v9 = KeyValues::KeyValues(this: v8, setName: "command", firstKey: "command", firstValue: "BlendFactorUpdate");
    else
      v9 = nullptr;
    v10 = this->__vftable;
    v11 = ((int (__thiscall *)(CColorBalanceUIPanel *, KeyValues *, _DWORD))this->GetParent)(a1: this, a2: v9, a3: 0.0);
    ((void (__thiscall *)(CColorBalanceUIPanel *, int))v10->PostMessage)(a1: this, a2: v11);
    return;
  }
  if ( Ptr == this->m_pCyanRedSlider )
  {
    v19 = (float)this->m_pCyanRedSlider->GetValue(this: this->m_pCyanRedSlider);
    CurrentMode = CColorBalanceUIPanel::GetCurrentMode(this);
    m_pBalanceOp = this->m_pBalanceOp;
    m_pBalanceOp->m_CyanRedBalance[CurrentMode] = v19;
    goto LABEL_16;
  }
  if ( Ptr == this->m_pMagentaGreenSlider )
  {
    v20 = (float)this->m_pMagentaGreenSlider->GetValue(this: this->m_pMagentaGreenSlider);
    v14 = CColorBalanceUIPanel::GetCurrentMode(this);
    m_pBalanceOp = this->m_pBalanceOp;
    m_pBalanceOp->m_MagentaGreenBalance[v14] = v20;
    goto LABEL_16;
  }
  if ( Ptr == this->m_pYellowBlueSlider )
  {
    v18 = (float)this->m_pYellowBlueSlider->GetValue(this: this->m_pYellowBlueSlider);
    v15 = CColorBalanceUIPanel::GetCurrentMode(this);
    CColorBalanceOperation::SetYellowBlueBalance(this: this->m_pBalanceOp, mode: v15, value: v18);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A7D10
// Name: private: virtual void CColorOperationListPanel::OnOpPanelClose(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorOperationListPanel::OnOpPanelClose(CColorOperationListPanel *this, KeyValues *data)
{
  CColorCorrectionUIChildPanel *Ptr; // edi
  int m_Size; // ecx
  int v5; // eax
  CColorCorrectionUIChildPanel **m_pMemory; // edx
  int v7; // ecx

  Ptr = (CColorCorrectionUIChildPanel *)KeyValues::GetPtr(this: data, keyName: "panel", defaultValue: nullptr);
  if ( Ptr != nullptr )
  {
    m_Size = this->m_OpPanelList.m_Size;
    v5 = 0;
    if ( m_Size <= 0 )
    {
LABEL_6:
      v7 = -1;
    }
    else
    {
      m_pMemory = this->m_OpPanelList.m_Memory.m_pMemory;
      while ( *m_pMemory != Ptr )
      {
        ++v5;
        ++m_pMemory;
        if ( v5 >= m_Size )
          goto LABEL_6;
      }
      v7 = v5;
    }
    if ( this->m_OpPanelList.m_Size - v7 - 1 > 0 )
      _V_memmove(
        dest: &this->m_OpPanelList.m_Memory.m_pMemory[v7],
        src: &this->m_OpPanelList.m_Memory.m_pMemory[v7 + 1],
        count: 4 * (this->m_OpPanelList.m_Size - v7 - 1));
    --this->m_OpPanelList.m_Size;
    Ptr->Shutdown(this: Ptr);
    ((void (__thiscall *)(CColorCorrectionUIChildPanel *, int))Ptr->dtr_Panel)(a1: Ptr, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A7DB0
// Name: private: bool CColorOperationListPanel::SaveRawFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __thiscall CColorOperationListPanel::SaveRawFile(CColorOperationListPanel *this, const char *pFullPath)
{
  const char *v2; // edi
  CP4File *v3; // esi
  bool (__thiscall *Edit)(CP4File *); // edx
  void *v5; // ebx
  __int16 v7; // si
  RGBX5551_t v8; // si
  RGBX5551_t v9; // si
  int j; // edi
  int v11; // eax
  char *v12; // edx
  bool v13; // zf
  CP4File *v14; // edi
  bool (__thiscall *v15)(CP4File *); // edx
  void *v16; // ebx
  CP4File *v17; // esi
  __int16 v18; // si
  RGBX5551_t v19; // si
  RGBX5551_t v20; // si
  int m; // edi
  int v22; // eax
  char *v23; // edx
  CP4File *v24; // esi
  CP4File *m_p; // esi
  char pFilename360[260]; // [esp+Ch] [ebp-118h] BYREF
  CP4AutoEditAddFile co; // [esp+110h] [ebp-14h]
  CP4File *outColor; // [esp+114h] [ebp-10h] OVERLAPPED BYREF
  int i; // [esp+118h] [ebp-Ch]
  int k; // [esp+11Ch] [ebp-8h]
  RGBX5551_t inColor; // [esp+120h] [ebp-4h]

  v2 = pFullPath;
  v3 = CP4Factory::AccessFile(this: g_p4factory, szFilename: pFullPath);
  Edit = v3->Edit;
  co.m_spImpl.m_p = v3;
  Edit(this: v3);
  v5 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: v2, a3: "wb", a4: 0);
  if ( v5 != nullptr )
  {
    v7 = *(_WORD *)&inColor & 0x83FF;
    for ( i = 32; i != 0; --i )
    {
      v8 = (RGBX5551_t)(v7 & 0xFC1F);
      k = 32;
      do
      {
        v9 = (RGBX5551_t)(*(_WORD *)&v8 & 0xFFE0);
        inColor = v9;
        for ( j = 32; j != 0; --j )
        {
          v11 = (*(_BYTE *)&v9 & 0x1F)
              + 32 * (((*(unsigned __int16 *)&v9 >> 5) & 0x1F) + 32 * ((*(unsigned __int16 *)&v9 >> 10) & 0x1F));
          v12 = (char *)g_pColorCorrectionUI + 2 * v11;
          LOWORD(outColor) = *(_WORD *)&v12[v11 + 556];
          BYTE2(outColor) = v12[v11 + 558];
          g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: &outColor, a3: 3, a4: v5);
          v9 = (RGBX5551_t)((*(_BYTE *)&inColor ^ (unsigned __int8)(*(_BYTE *)&inColor + 1)) & 0x1F ^ *(_WORD *)&v9);
          inColor = v9;
        }
        v8 = (RGBX5551_t)((*(_WORD *)&inColor ^ ((*(_WORD *)&inColor & 0xFFE0) + 32)) & 0x3E0 ^ *(_WORD *)&v9);
        v13 = k-- == 1;
        inColor = v8;
      }
      while ( !v13 );
      v7 = (*(_WORD *)&inColor ^ ((*(_WORD *)&inColor & 0xFC00) + 1024)) & 0x7C00 ^ *(_WORD *)&v8;
    }
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v5);
    memset(pFilename360, 0, sizeof(pFilename360));
    V_StripExtension(in: pFullPath, out: pFilename360, outSize: 260);
    V_DefaultExtension(path: pFilename360, extension: ".pwl.raw", pathStringLength: 260);
    v14 = CP4Factory::AccessFile(this: g_p4factory, szFilename: pFilename360);
    v15 = v14->Edit;
    outColor = v14;
    v15(this: v14);
    v16 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: pFilename360, a3: "wb", a4: 0);
    if ( v16 != nullptr )
    {
      v18 = v7 & 0x83FF;
      for ( k = 32; k != 0; --k )
      {
        v19 = (RGBX5551_t)(v18 & 0xFC1F);
        i = 32;
        do
        {
          v20 = (RGBX5551_t)(*(_WORD *)&v19 & 0xFFE0);
          inColor = v20;
          for ( m = 32; m != 0; --m )
          {
            v22 = (*(_BYTE *)&v20 & 0x1F)
                + 32 * (((*(unsigned __int16 *)&v20 >> 5) & 0x1F) + 32 * ((*(unsigned __int16 *)&v20 >> 10) & 0x1F));
            v23 = (char *)g_pColorCorrectionUI + 2 * v22;
            LOWORD(pFullPath) = *(_WORD *)&v23[v22 + 98860];
            BYTE2(pFullPath) = v23[v22 + 98862];
            g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: &pFullPath, a3: 3, a4: v16);
            v20 = (RGBX5551_t)((*(_BYTE *)&inColor ^ (unsigned __int8)(*(_BYTE *)&inColor + 1)) & 0x1F ^ *(_WORD *)&v20);
            inColor = v20;
          }
          v19 = (RGBX5551_t)((*(_WORD *)&inColor ^ ((*(_WORD *)&inColor & 0xFFE0) + 32)) & 0x3E0 ^ *(_WORD *)&v20);
          v13 = i-- == 1;
          inColor = v19;
        }
        while ( !v13 );
        v18 = (*(_WORD *)&inColor ^ ((*(_WORD *)&inColor & 0xFC00) + 1024)) & 0x7C00 ^ *(_WORD *)&v19;
      }
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v16);
      v24 = outColor;
      outColor->Add(this: outColor);
      ((void (__thiscall *)(CP4File *, int))v24->dtr_CP4File)(a1: v24, a2: 1);
      m_p = co.m_spImpl.m_p;
      co.m_spImpl.m_p->Add(this: co.m_spImpl.m_p);
      ((void (__thiscall *)(CP4File *, int))m_p->dtr_CP4File)(a1: m_p, a2: 1);
      return 1;
    }
    else
    {
      v14->Add(this: v14);
      ((void (__thiscall *)(CP4File *, int))v14->dtr_CP4File)(a1: v14, a2: 1);
      v17 = co.m_spImpl.m_p;
      co.m_spImpl.m_p->Add(this: co.m_spImpl.m_p);
      ((void (__thiscall *)(CP4File *, int))v17->dtr_CP4File)(a1: v17, a2: 1);
      return 0;
    }
  }
  else
  {
    v3->Add(this: v3);
    ((void (__thiscall *)(CP4File *, int))v3->dtr_CP4File)(a1: v3, a2: 1);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A8120
// Name: public: virtual void CColorCorrectionTools::GrabPreColorCorrectedFrame(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CColorCorrectionTools::GrabPreColorCorrectedFrame(
        CColorCorrectionTools *this@<ecx>,
        int a2@<esi>,
        int x,
        int y,
        int width,
        int height)
{
  int v7; // esi
  BGRA8888_t *m_pPreviewImage; // eax
  Rect_t dstRect; // [esp+4h] [ebp-20h] BYREF
  Rect_t srcRect; // [esp+14h] [ebp-10h] BYREF

  if ( g_pColorCorrectionUI != nullptr && g_pColorCorrectionUI->IsVisible(this: g_pColorCorrectionUI) )
  {
    v7 = ((int (__thiscall *)(IMaterialSystem *, int))g_pMaterialSystem->GetRenderContext)(a1: g_pMaterialSystem, a2);
    if ( v7 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 8))(a1: v7);
    srcRect.x = y;
    srcRect.y = y;
    srcRect.width = width;
    m_pPreviewImage = this->m_pPreviewImage;
    srcRect.height = height;
    dstRect.x = 0;
    dstRect.y = 0;
    dstRect.width = 128;
    dstRect.height = 96;
    (*(void (__thiscall **)(int, Rect_t *, Rect_t *, BGRA8888_t *, int))(*(_DWORD *)v7 + 412))(
      a1: v7,
      a2: &srcRect,
      a3: &dstRect,
      a4: m_pPreviewImage,
      a5: 16);
    CColorCorrectionUIPanel::ReadUncorrectedImage(
      this: g_pColorCorrectionUI,
      pSrcRect: &srcRect,
      pPreviewImage: (unsigned __int8 *)this->m_pPreviewImage);
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 12))(a1: v7);
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 4))(a1: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A8270
// Name: public: void CColorOperationList::BringForward(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorOperationList::BringForward(CColorOperationList *this, IColorOperation *opIndex)
{
  IColorOperation *v2; // esi
  IColorOperation *m_Size; // eax
  IColorOperation **v5; // ecx
  int v6; // eax

  v2 = opIndex;
  if ( (int)opIndex >= 0 )
  {
    m_Size = (IColorOperation *)this->m_OpList.m_Size;
    if ( (int)opIndex < (int)m_Size && opIndex != nullptr )
    {
      v5 = &this->m_OpList.m_Memory.m_pMemory[(_DWORD)opIndex];
      v6 = (char *)m_Size - (char *)opIndex - 1;
      opIndex = this->m_OpList.m_Memory.m_pMemory[(_DWORD)opIndex];
      if ( v6 > 0 )
        _V_memmove(dest: v5, src: v5 + 1, count: 4 * v6);
      --this->m_OpList.m_Size;
      CUtlVector<RequestContext *,CUtlMemory<RequestContext *,int>>::InsertBefore(
        (CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *)this,
        elem: (int)&v2[-1].__vftable + 3,
        src: (vgui::PageTab *const *)&opIndex);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A82D0
// Name: public: void CColorOperationList::PushBack(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorOperationList::PushBack(CColorOperationList *this, int opIndex)
{
  int m_Size; // eax
  int v4; // eax
  IColorOperation **v5; // ecx
  IColorOperation *v6; // ebx
  int v7; // eax
  int m_nAllocationCount; // ecx
  int v9; // edi
  IColorOperation **m_pMemory; // ecx
  int v11; // eax
  IColorOperation **v12; // eax

  if ( opIndex >= 0 )
  {
    m_Size = this->m_OpList.m_Size;
    if ( opIndex < m_Size && opIndex != m_Size - 1 )
    {
      v4 = m_Size - opIndex - 1;
      v5 = &this->m_OpList.m_Memory.m_pMemory[opIndex];
      v6 = *v5;
      if ( v4 > 0 )
        _V_memmove(dest: v5, src: v5 + 1, count: 4 * v4);
      v7 = --this->m_OpList.m_Size;
      m_nAllocationCount = this->m_OpList.m_Memory.m_nAllocationCount;
      v9 = opIndex + 1;
      if ( v7 + 1 > m_nAllocationCount )
        CUtlMemory<INetMessage *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: v7 - m_nAllocationCount + 1);
      ++this->m_OpList.m_Size;
      m_pMemory = this->m_OpList.m_Memory.m_pMemory;
      v11 = this->m_OpList.m_Size - v9 - 1;
      this->m_OpList.m_pElements = this->m_OpList.m_Memory.m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: &m_pMemory[v9 + 1], src: &m_pMemory[v9], count: 4 * v11);
      v12 = &this->m_OpList.m_Memory.m_pMemory[v9];
      if ( v12 != nullptr )
        *v12 = v6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A8370
// Name: public: virtual CColorOperationListPanel::~CColorOperationListPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorOperationListPanel::~CColorOperationListPanel(CColorOperationListPanel *this)
{
  bool v2; // sf

  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CColorOperationListPanel_vtbl *)&CColorOperationListPanel::`vftable'{for `vgui::EditablePanel'};
  this->vgui::IFileOpenStateMachineClient::__vftable = (vgui::IFileOpenStateMachineClient_vtbl *)&CColorOperationListPanel::`vftable'{for `vgui::IFileOpenStateMachineClient'};
  v2 = this->m_FileName.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_FileName.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_FileName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FileName.m_Storage.m_Memory.m_pMemory);
      this->m_FileName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_FileName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_OpPanelList);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_OperationList);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A83F0
// Name: public: virtual struct vgui::PanelMessageMap __near * CColorOperationListPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CColorOperationListPanel::GetMessageMap(CColorOperationListPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CColorOperationListPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorOperationListPanel::GetMessageMap'::`2'::s_pMap;
  `CColorOperationListPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CColorOperationListPanel");
  `CColorOperationListPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A8420
// Name: public: virtual struct PanelAnimationMap __near * CColorOperationListPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CColorOperationListPanel::GetAnimMap(CColorOperationListPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CColorOperationListPanel");
}

//------------------------------------------------------------------------------
// Address: 0x100A8430
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CColorOperationListPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CColorOperationListPanel::GetKBMap(CColorOperationListPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CColorOperationListPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorOperationListPanel::GetKBMap'::`2'::s_pMap;
  `CColorOperationListPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CColorOperationListPanel");
  `CColorOperationListPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A8460
// Name: public: int CUtlSortVector<class Vector,class CCurvesColorOperation::CurvesLessFunc>::Insert(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<Vector,CCurvesColorOperation::CurvesLessFunc>::Insert(
        CUtlSortVector<Vector,CCurvesColorOperation::CurvesLessFunc> *this,
        const Vector *src)
{
  int LessOrEqual; // eax
  int m_nAllocationCount; // ecx
  int v5; // edi
  int m_Size; // eax
  Vector *m_pMemory; // ecx
  int v8; // eax
  Vector *v9; // eax

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
         150,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/utlsortvector.h",
                            a2: 150,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
      a2: 150);
  }
  LessOrEqual = CUtlSortVector<Vector,CCurvesColorOperation::CurvesLessFunc>::FindLessOrEqual(this, src);
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  v5 = LessOrEqual + 1;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - v5 - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: 12 * v8);
  v9 = &this->m_Memory.m_pMemory[v5];
  if ( v9 != nullptr )
    *v9 = *src;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100A8550
// Name: public: static void CPrecisionSlider::PanelMessageFunc_OnTextNewLine::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CPrecisionSlider::PanelMessageFunc_OnTextNewLine::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CPrecisionSlider::PanelMessageFunc_OnTextNewLine::InitVar'::`2'::bAdded )
  {
    `CPrecisionSlider::PanelMessageFunc_OnTextNewLine::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CPrecisionSlider");
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "TextNewLine";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::PropertyPage::`vcall'{944,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][0]) = 1;
    *(_QWORD *)&v3.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A85F0
// Name: public: CPrecisionSlider::CPrecisionSlider(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CPrecisionSlider *__thiscall CPrecisionSlider::CPrecisionSlider(
        CPrecisionSlider *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::TextEntry *v7; // eax
  vgui::TextEntry *v8; // eax

  vgui::Slider::Slider(this, parent, panelName);
  this->__vftable = (CPrecisionSlider_vtbl *)&CPrecisionSlider::`vftable';
  if ( `CPrecisionSlider::ChainToMap'::`2'::chained == 0 )
  {
    `CPrecisionSlider::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CPrecisionSlider");
    v4->pfnClassName = CPrecisionSlider::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Slider");
  }
  if ( `CPrecisionSlider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPrecisionSlider::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CPrecisionSlider");
    v5->pfnClassName = CPrecisionSlider::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Slider");
  }
  if ( `CPrecisionSlider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPrecisionSlider::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CPrecisionSlider");
    v6->pfnClassName = CPrecisionSlider::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Slider");
  }
  CPrecisionSlider::PanelMessageFunc_OnTextNewLine::InitVar();
  v7 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v7 != nullptr )
    v8 = vgui::TextEntry::TextEntry(this: v7, parent: this, panelName: "PrecisionEditPanel");
  else
    v8 = nullptr;
  this->m_pTextEntry = v8;
  v8->SendNewLine(this: v8, a2: true);
  this->m_pTextEntry->SetCatchEnterKey(this: this->m_pTextEntry, a2: true);
  this->m_pTextEntry->AddActionSignalTarget_2(this: this->m_pTextEntry, a2: this);
  this->m_nTextEntryWidth = 32;
  this->m_nSpacing = 8;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A8720
// Name: public: void CColorOperationList::AddOperation(class IColorOperation __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorOperationList::AddOperation(CColorOperationList *this, IColorOperation *pOp)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  IColorOperation **m_pMemory; // ecx
  int v6; // eax
  IColorOperation **v7; // eax

  m_nAllocationCount = this->m_OpList.m_Memory.m_nAllocationCount;
  m_Size = this->m_OpList.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_OpList.m_Size;
  m_pMemory = this->m_OpList.m_Memory.m_pMemory;
  v6 = this->m_OpList.m_Size - m_Size - 1;
  this->m_OpList.m_pElements = this->m_OpList.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_OpList.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = pOp;
}

//------------------------------------------------------------------------------
// Address: 0x100A8780
// Name: public: int CCurvesColorOperation::ModifyControlPoint(int,float,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCurvesColorOperation::ModifyControlPoint(
        CCurvesColorOperation *this,
        int nPoint,
        float flInValue,
        float flOutValue)
{
  Vector *m_pMemory; // eax
  float y; // ebx
  int v7; // eax
  int v8; // esi
  Vector temp; // [esp+Ch] [ebp-Ch] BYREF

  m_pMemory = this->m_ControlPoints.m_Memory.m_pMemory;
  temp.x = m_pMemory[nPoint].x;
  y = m_pMemory[nPoint].y;
  temp.z = m_pMemory[nPoint].z;
  v7 = this->m_ControlPoints.m_Size - nPoint - 1;
  temp.y = y;
  if ( v7 > 0 )
    _V_memmove(
      dest: &this->m_ControlPoints.m_Memory.m_pMemory[nPoint],
      src: &this->m_ControlPoints.m_Memory.m_pMemory[nPoint + 1],
      count: 12 * v7);
  --this->m_ControlPoints.m_Size;
  temp.x = flInValue;
  temp.y = flOutValue;
  CUtlSortVector<Vector,CCurvesColorOperation::CurvesLessFunc>::Insert(this: &this->m_ControlPoints, src: &temp);
  v8 = CUtlSortVector<Vector,CCurvesColorOperation::CurvesLessFunc>::Find(this: &this->m_ControlPoints, src: &temp);
  CCurvesColorOperation::UpdateOutColorArray(this);
  colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x100A8830
// Name: public: void CCurvesColorOperation::RemoveControlPoint(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurvesColorOperation::RemoveControlPoint(CCurvesColorOperation *this, int nPoint)
{
  if ( nPoint != 0 && nPoint != this->m_ControlPoints.m_Size - 1 )
  {
    if ( this->m_ControlPoints.m_Size - nPoint - 1 > 0 )
      _V_memmove(
        dest: &this->m_ControlPoints.m_Memory.m_pMemory[nPoint],
        src: &this->m_ControlPoints.m_Memory.m_pMemory[nPoint + 1],
        count: 12 * (this->m_ControlPoints.m_Size - nPoint - 1));
    --this->m_ControlPoints.m_Size;
    CCurvesColorOperation::UpdateOutColorArray(this);
    colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A88A0
// Name: protected: virtual int CColorCurvesEditPanel::FindOrAddControlPoint(float,float,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CColorCurvesEditPanel::FindOrAddControlPoint(
        CColorCurvesEditPanel *this,
        float flIn,
        float flTolerance,
        float flOut)
{
  CCurvesColorOperation *m_pCurvesOp; // esi
  int result; // eax
  int v6; // edi
  Vector v7; // [esp+Ch] [ebp-Ch] BYREF

  m_pCurvesOp = this->m_pCurvesOp;
  result = CCurvesColorOperation::FindControlPoint(this: m_pCurvesOp, flInValue: flIn, flTolerance);
  if ( result == -1 )
  {
    v7.x = flIn;
    v7.y = flOut;
    v7.z = 0.0;
    CUtlSortVector<Vector,CCurvesColorOperation::CurvesLessFunc>::Insert(this: &m_pCurvesOp->m_ControlPoints, src: &v7);
    v6 = CUtlSortVector<Vector,CCurvesColorOperation::CurvesLessFunc>::Find(
           this: &m_pCurvesOp->m_ControlPoints,
           src: &v7);
    CCurvesColorOperation::UpdateOutColorArray(this: m_pCurvesOp);
    colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A8930
// Name: protected: virtual int CColorCurvesEditPanel::ModifyControlPoint(int,float,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CColorCurvesEditPanel::ModifyControlPoint(
        CColorCurvesEditPanel *this,
        int nPoint,
        float flIn,
        float flOut)
{
  CCurvesColorOperation::ModifyControlPoint(this: this->m_pCurvesOp, nPoint, flInValue: flIn, flOutValue: flOut);
  return nPoint;
}

//------------------------------------------------------------------------------
// Address: 0x100A8960
// Name: protected: virtual void CColorCurvesEditPanel::RemoveControlPoint(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCurvesEditPanel::RemoveControlPoint(CColorCurvesEditPanel *this, int nPoint)
{
  CCurvesColorOperation::RemoveControlPoint(this: this->m_pCurvesOp, nPoint);
}

//------------------------------------------------------------------------------
// Address: 0x100A8970
// Name: public: static void CColorCurvesUIPanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CColorCurvesUIPanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CColorCurvesUIPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CColorCurvesUIPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CColorCurvesUIPanel");
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "TextChanged";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::FileOpenDialog::`vcall'{1132,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][0]) = 1;
    *(_QWORD *)&v3.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A8A10
// Name: public: CColorCurvesUIPanel::CColorCurvesUIPanel(class vgui::Panel __near *,class CCurvesColorOperation __near *)
// Source: json
//------------------------------------------------------------------------------
CColorCurvesUIPanel *__thiscall CColorCurvesUIPanel::CColorCurvesUIPanel(
        CColorCurvesUIPanel *this,
        vgui::Panel *pParent,
        CCurvesColorOperation *pOp)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::ComboBox *v7; // eax
  vgui::ComboBox *v8; // eax
  const char **v9; // edi
  CPrecisionSlider *v10; // eax
  CPrecisionSlider *v11; // eax
  CColorCurvesEditPanel *v12; // eax
  CColorCurvesEditPanel *v13; // eax
  CCurvesColorOperation *m_pColorOp; // ecx
  void (__thiscall *SetVisible)(vgui::Panel *, bool); // edx
  vgui::ComboBox *m_pColorMask; // ecx
  void (__thiscall *ActivateItem)(vgui::ComboBox *, int); // edx
  CPrecisionSlider_vtbl *v18; // edi
  double v19; // st7
  int v21; // [esp-4h] [ebp-10h]

  CColorCorrectionUIChildPanel::CColorCorrectionUIChildPanel(this, parent: pParent, name: "ColorCurvesUIPanel");
  this->__vftable = (CColorCurvesUIPanel_vtbl *)&CColorCurvesUIPanel::`vftable';
  if ( `CColorCurvesUIPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CColorCurvesUIPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CColorCurvesUIPanel");
    v4->pfnClassName = CColorCurvesUIPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CColorCorrectionUIChildPanel");
  }
  if ( `CColorCurvesUIPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CColorCurvesUIPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CColorCurvesUIPanel");
    v5->pfnClassName = CColorCurvesUIPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CColorCorrectionUIChildPanel");
  }
  if ( `CColorCurvesUIPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CColorCurvesUIPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CColorCurvesUIPanel");
    v6->pfnClassName = CColorCurvesUIPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CColorCorrectionUIChildPanel");
  }
  CColorCurvesUIPanel::PanelMessageFunc_OnTextChanged::InitVar();
  v7 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v7 != nullptr )
    v8 = vgui::ComboBox::ComboBox(this: v7, parent: this, panelName: "ColorMask", numLines: 4, allowEdit: false);
  else
    v8 = nullptr;
  this->m_pColorMask = v8;
  v9 = CColorCurvesUIPanel::s_pColorMaskLabel;
  do
    this->m_pColorMask->AddItem_2(this: this->m_pColorMask, a2: *v9++, a3: nullptr);
  while ( (int)v9 < (int)CColorLevelsUIPanel::s_pColorMaskLabel );
  this->m_pColorMask->AddActionSignalTarget_2(this: this->m_pColorMask, a2: this);
  v10 = (CPrecisionSlider *)MemAlloc_Alloc(nSize: 0x1BCu);
  if ( v10 != nullptr )
    v11 = CPrecisionSlider::CPrecisionSlider(this: v10, parent: this, panelName: "BlendFactorSlider");
  else
    v11 = nullptr;
  this->m_pBlendFactorSlider = v11;
  v11->SetRange(this: v11, a2: 0, a3: 255);
  this->m_pBlendFactorSlider->AddActionSignalTarget_2(this: this->m_pBlendFactorSlider, a2: this);
  this->m_pColorOp = pOp;
  v12 = (CColorCurvesEditPanel *)MemAlloc_Alloc(nSize: 0x160u);
  if ( v12 != nullptr )
    v13 = CColorCurvesEditPanel::CColorCurvesEditPanel(this: v12, pParent: this, pName: "CurveEditor");
  else
    v13 = nullptr;
  m_pColorOp = this->m_pColorOp;
  this->m_pCurveEditor = v13;
  SetVisible = v13->SetVisible;
  v13->m_pCurvesOp = m_pColorOp;
  SetVisible(this: v13, a2: m_pColorOp != nullptr);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource\\ColorCurvesUIPanel.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  m_pColorMask = this->m_pColorMask;
  if ( pOp->m_nChannelMask == 1 )
  {
    v21 = 1;
    goto LABEL_25;
  }
  if ( pOp->m_nChannelMask == 2 )
  {
    v21 = 2;
LABEL_25:
    ((void (__stdcall *)(int))m_pColorMask->ActivateItem)(a1: v21);
    goto LABEL_26;
  }
  ActivateItem = m_pColorMask->ActivateItem;
  if ( pOp->m_nChannelMask == 4 )
    ((void (__stdcall *)(int))ActivateItem)(a1: 3);
  else
    ((void (__stdcall *)(_DWORD))ActivateItem)(a1: 0);
LABEL_26:
  v18 = this->m_pBlendFactorSlider->__vftable;
  v19 = ((double (__thiscall *)(CCurvesColorOperation *, int))pOp->GetBlendFactor)(a1: pOp, a2: 1) * 255.0;
  ((void (__thiscall *)(CPrecisionSlider *, int))v18->SetValue)(a1: this->m_pBlendFactorSlider, a2: (int)v19);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A8C50
// Name: public: static void CColorLevelsUIPanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CColorLevelsUIPanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CColorLevelsUIPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CColorLevelsUIPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CColorLevelsUIPanel");
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "TextChanged";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::FileOpenDialog::`vcall'{1132,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][0]) = 1;
    *(_QWORD *)&v3.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A8CF0
// Name: public: CColorLevelsUIPanel::CColorLevelsUIPanel(class vgui::Panel __near *,class CLevelsColorOperation __near *)
// Source: json
//------------------------------------------------------------------------------
CColorLevelsUIPanel *__thiscall CColorLevelsUIPanel::CColorLevelsUIPanel(
        CColorLevelsUIPanel *this,
        vgui::Panel *pParent,
        CLevelsColorOperation *pOp)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::ComboBox *v7; // eax
  vgui::ComboBox *v8; // eax
  const char **v9; // edi
  CPrecisionSlider *v10; // eax
  CPrecisionSlider *v11; // eax
  CColorSlider *v12; // eax
  CColorSlider *v13; // eax
  CColorSlider *v14; // eax
  CColorSlider *v15; // eax
  CColorHistogramPanel *v17; // eax
  CColorHistogramPanel *v18; // eax
  CPrecisionSlider_vtbl *v19; // edi
  double v20; // st7
  CColorSlider *m_pInputLevelSlider; // edi
  float m_flMinInputLevel; // xmm0_4
  bool v23; // cc
  KeyValues *v24; // eax
  KeyValues *v25; // eax
  float v26; // xmm0_4
  CColorSlider *v27; // edi
  float v28; // xmm1_4
  KeyValues *v29; // eax
  KeyValues *v30; // eax
  float v31; // xmm0_4
  CColorSlider *v32; // edi
  float v33; // xmm1_4
  KeyValues *v34; // eax
  KeyValues *v35; // eax
  float m_flMinOutputLevel; // xmm1_4
  CColorSlider *m_pOutputLevelSlider; // edi
  float v38; // xmm0_4
  KeyValues *v39; // eax
  KeyValues *v40; // eax
  float v41; // xmm0_4
  CColorSlider *v42; // edi
  float v43; // xmm1_4
  KeyValues *v44; // eax
  KeyValues *v45; // eax
  int v46; // ebx
  void (__thiscall *ActivateItem)(vgui::ComboBox *, int); // eax
  int v48; // ebx
  CLevelsColorOperation *m_pLevelsOp; // ecx
  float v50; // xmm0_4
  int savedregs; // [esp+Ch] [ebp+0h] BYREF
  float flMaxValue; // [esp+14h] [ebp+8h]
  float flMaxValuea; // [esp+14h] [ebp+8h]
  float flMaxValueb; // [esp+14h] [ebp+8h]
  float flMidValue; // [esp+18h] [ebp+Ch]

  CColorCorrectionUIChildPanel::CColorCorrectionUIChildPanel(this, parent: pParent, name: "LevelsUIPanel");
  this->__vftable = (CColorLevelsUIPanel_vtbl *)&CColorLevelsUIPanel::`vftable';
  if ( `CColorLevelsUIPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CColorLevelsUIPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CColorLevelsUIPanel");
    v4->pfnClassName = CColorLevelsUIPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CColorCorrectionUIChildPanel");
  }
  if ( `CColorLevelsUIPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CColorLevelsUIPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CColorLevelsUIPanel");
    v5->pfnClassName = CColorLevelsUIPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CColorCorrectionUIChildPanel");
  }
  if ( `CColorLevelsUIPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CColorLevelsUIPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CColorLevelsUIPanel");
    v6->pfnClassName = CColorLevelsUIPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CColorCorrectionUIChildPanel");
  }
  CColorLevelsUIPanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  v7 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v7 != nullptr )
    v8 = vgui::ComboBox::ComboBox(this: v7, parent: this, panelName: "ColorMask", numLines: 4, allowEdit: false);
  else
    v8 = nullptr;
  this->m_pColorMask = v8;
  v9 = CColorLevelsUIPanel::s_pColorMaskLabel;
  do
    this->m_pColorMask->AddItem_2(this: this->m_pColorMask, a2: *v9++, a3: nullptr);
  while ( (int)v9 < (int)CSelectedHSVUIPanel::s_pSelectionMethodNames );
  this->m_pColorMask->AddActionSignalTarget_2(this: this->m_pColorMask, a2: this);
  v10 = (CPrecisionSlider *)MemAlloc_Alloc(nSize: 0x1BCu);
  if ( v10 != nullptr )
    v11 = CPrecisionSlider::CPrecisionSlider(this: v10, parent: this, panelName: "BlendFactorSlider");
  else
    v11 = nullptr;
  this->m_pBlendFactorSlider = v11;
  v11->SetRange(this: v11, a2: 0, a3: 255);
  this->m_pBlendFactorSlider->AddActionSignalTarget_2(this: this->m_pBlendFactorSlider, a2: this);
  v12 = (CColorSlider *)MemAlloc_Alloc(nSize: 0x170u);
  if ( v12 != nullptr )
    v13 = CColorSlider::CColorSlider(this: v12, pParent: this, pName: "InputLevelSlider", nKnobCount: 3);
  else
    v13 = nullptr;
  this->m_pInputLevelSlider = v13;
  v13->m_nMinValue = 0;
  v13->m_nMaxValue = 255;
  this->m_pInputLevelSlider->AddActionSignalTarget_2(this: this->m_pInputLevelSlider, a2: this);
  v14 = (CColorSlider *)MemAlloc_Alloc(nSize: 0x170u);
  if ( v14 != nullptr )
    v15 = CColorSlider::CColorSlider(this: v14, pParent: this, pName: "OutputLevelSlider", nKnobCount: 2);
  else
    v15 = nullptr;
  this->m_pOutputLevelSlider = v15;
  v15->m_nMinValue = 0;
  v15->m_nMaxValue = 255;
  this->m_pOutputLevelSlider->AddActionSignalTarget_2(this: this->m_pOutputLevelSlider, a2: this);
  this->m_pLevelsOp = pOp;
  v17 = (CColorHistogramPanel *)MemAlloc_Alloc(nSize: 0x55Cu);
  if ( v17 != nullptr )
    v18 = CColorHistogramPanel::CColorHistogramPanel(this: v17, pParent: this, pName: "Histogram", pOp);
  else
    v18 = nullptr;
  this->m_pHistogramPanel = v18;
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource\\ColorLevelsUIPanel.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  v19 = this->m_pBlendFactorSlider->__vftable;
  v20 = ((double (__thiscall *)(CLevelsColorOperation *, int))pOp->GetBlendFactor)(a1: pOp, a2: 1) * 255.0;
  ((void (__thiscall *)(CPrecisionSlider *, int))v19->SetValue)(a1: this->m_pBlendFactorSlider, a2: (int)v20);
  m_pInputLevelSlider = this->m_pInputLevelSlider;
  flMidValue = pOp->m_flMidInputLevel;
  flMaxValue = pOp->m_flMaxInputLevel;
  m_flMinInputLevel = pOp->m_flMinInputLevel;
  if ( m_flMinInputLevel >= 0.0 )
  {
    if ( m_flMinInputLevel > 1.0 )
      m_flMinInputLevel = 1.0;
  }
  else
  {
    m_flMinInputLevel = 0.0;
  }
  v23 = m_flMinInputLevel <= m_pInputLevelSlider->m_flKnobPosition[1];
  m_pInputLevelSlider->m_flKnobPosition[0] = m_flMinInputLevel;
  if ( !v23 )
    m_pInputLevelSlider->m_flKnobPosition[1] = m_flMinInputLevel;
  if ( m_flMinInputLevel > m_pInputLevelSlider->m_flKnobPosition[2] )
    m_pInputLevelSlider->m_flKnobPosition[2] = m_flMinInputLevel;
  v24 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v24 != nullptr )
    v25 = KeyValues::KeyValues(this: v24, setName: "SliderMoved", firstKey: "knob", firstValue: 0);
  else
    v25 = nullptr;
  m_pInputLevelSlider->PostActionSignal(this: m_pInputLevelSlider, a2: v25);
  v26 = 0.0;
  v27 = this->m_pInputLevelSlider;
  if ( flMidValue >= 0.0 )
  {
    v26 = 1.0;
    if ( flMidValue <= 1.0 )
      v26 = flMidValue;
  }
  v28 = v27->m_flKnobPosition[0];
  v27->m_flKnobPosition[2] = v26;
  if ( v28 > v26 )
    v27->m_flKnobPosition[0] = v26;
  if ( v26 > v27->m_flKnobPosition[1] )
    v27->m_flKnobPosition[1] = v26;
  v29 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v29 != nullptr )
    v30 = KeyValues::KeyValues(this: v29, setName: "SliderMoved", firstKey: "knob", firstValue: 2);
  else
    v30 = nullptr;
  v27->PostActionSignal(this: v27, a2: v30);
  v31 = 0.0;
  v32 = this->m_pInputLevelSlider;
  if ( flMaxValue >= 0.0 )
  {
    v31 = 1.0;
    if ( flMaxValue <= 1.0 )
      v31 = flMaxValue;
  }
  v33 = v32->m_flKnobPosition[0];
  v32->m_flKnobPosition[1] = v31;
  if ( v33 > v31 )
    v32->m_flKnobPosition[0] = v31;
  if ( v32->m_flKnobPosition[2] > v31 )
    v32->m_flKnobPosition[2] = v31;
  v34 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v34 != nullptr )
    v35 = KeyValues::KeyValues(this: v34, setName: "SliderMoved", firstKey: "knob", firstValue: 1);
  else
    v35 = nullptr;
  v32->PostActionSignal(this: v32, a2: v35);
  m_flMinOutputLevel = pOp->m_flMinOutputLevel;
  m_pOutputLevelSlider = this->m_pOutputLevelSlider;
  flMaxValuea = pOp->m_flMaxOutputLevel;
  v38 = 0.0;
  if ( m_flMinOutputLevel >= 0.0 )
  {
    v38 = 1.0;
    if ( m_flMinOutputLevel <= 1.0 )
      v38 = pOp->m_flMinOutputLevel;
  }
  v23 = v38 <= m_pOutputLevelSlider->m_flKnobPosition[1];
  m_pOutputLevelSlider->m_flKnobPosition[0] = v38;
  if ( !v23 )
    m_pOutputLevelSlider->m_flKnobPosition[1] = v38;
  if ( v38 > m_pOutputLevelSlider->m_flKnobPosition[2] )
    m_pOutputLevelSlider->m_flKnobPosition[2] = v38;
  v39 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v39 != nullptr )
    v40 = KeyValues::KeyValues(this: v39, setName: "SliderMoved", firstKey: "knob", firstValue: 0);
  else
    v40 = nullptr;
  m_pOutputLevelSlider->PostActionSignal(this: m_pOutputLevelSlider, a2: v40);
  v41 = 0.0;
  v42 = this->m_pOutputLevelSlider;
  if ( flMaxValuea >= 0.0 )
  {
    v41 = 1.0;
    if ( flMaxValuea <= 1.0 )
      v41 = flMaxValuea;
  }
  v43 = v42->m_flKnobPosition[0];
  v42->m_flKnobPosition[1] = v41;
  if ( v43 > v41 )
    v42->m_flKnobPosition[0] = v41;
  if ( v42->m_flKnobPosition[2] > v41 )
    v42->m_flKnobPosition[2] = v41;
  v44 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v44 != nullptr )
    v45 = KeyValues::KeyValues(this: v44, setName: "SliderMoved", firstKey: "knob", firstValue: 1);
  else
    v45 = nullptr;
  v42->PostActionSignal(this: v42, a2: v45);
  v46 = pOp->m_nChannelMask - 1;
  ActivateItem = this->m_pColorMask->ActivateItem;
  if ( v46 != 0 )
  {
    v48 = v46 - 1;
    if ( v48 != 0 )
    {
      if ( v48 == 2 )
        ((void (__stdcall *)(int))ActivateItem)(a1: 3);
      else
        ((void (__stdcall *)(_DWORD))ActivateItem)(a1: 0);
    }
    else
    {
      ((void (__stdcall *)(int))ActivateItem)(a1: 2);
    }
  }
  else
  {
    ((void (__stdcall *)(int))ActivateItem)(a1: 1);
  }
  m_pLevelsOp = this->m_pLevelsOp;
  if ( m_pLevelsOp != nullptr )
  {
    flMaxValueb = m_pLevelsOp->GetBlendFactor(this: m_pLevelsOp);
    v50 = flMaxValueb;
  }
  else
  {
    v50 = 0.0;
  }
  this->m_pBlendFactorSlider->SetValue(this: this->m_pBlendFactorSlider, a2: (int)(float)(v50 * 255.0), a3: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A9290
// Name: public: virtual struct vgui::PanelMessageMap __near * CColorLevelsUIPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CColorLevelsUIPanel::GetMessageMap(CColorLevelsUIPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CColorLevelsUIPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorLevelsUIPanel::GetMessageMap'::`2'::s_pMap;
  `CColorLevelsUIPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CColorLevelsUIPanel");
  `CColorLevelsUIPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A92C0
// Name: public: virtual struct PanelAnimationMap __near * CColorLevelsUIPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CColorLevelsUIPanel::GetAnimMap(CColorLevelsUIPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CColorLevelsUIPanel");
}

//------------------------------------------------------------------------------
// Address: 0x100A92D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CColorLevelsUIPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CColorLevelsUIPanel::GetKBMap(CColorLevelsUIPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CColorLevelsUIPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorLevelsUIPanel::GetKBMap'::`2'::s_pMap;
  `CColorLevelsUIPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CColorLevelsUIPanel");
  `CColorLevelsUIPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A9330
// Name: public: CSelectedHSVOperation::CSelectedHSVOperation(class CColorOperationList __near *)
// Source: json
//------------------------------------------------------------------------------
CSelectedHSVOperation *__thiscall CSelectedHSVOperation::CSelectedHSVOperation(
        CSelectedHSVOperation *this,
        CColorOperationList *pList)
{
  this->m_pOpList = pList;
  this->__vftable = (CSelectedHSVOperation_vtbl *)&CSelectedHSVOperation::`vftable';
  this->m_SelectedRGBs.m_Memory.m_pMemory = nullptr;
  this->m_SelectedRGBs.m_Memory.m_nAllocationCount = 0;
  this->m_SelectedRGBs.m_Memory.m_nGrowSize = 0;
  this->m_SelectedRGBs.m_Size = 0;
  this->m_SelectedRGBs.m_pElements = nullptr;
  this->m_SelectedHSVs.m_Memory.m_pMemory = nullptr;
  this->m_SelectedHSVs.m_Memory.m_nAllocationCount = 0;
  this->m_SelectedHSVs.m_Memory.m_nGrowSize = 0;
  this->m_SelectedHSVs.m_Size = 0;
  this->m_SelectedHSVs.m_pElements = nullptr;
  this->m_SelectionMethod = SELECT_NEARBY_RGB;
  this->m_DeltaHSV.x = 0.0;
  this->m_DeltaHSV.y = 0.0;
  this->m_DeltaHSV.z = 0.0;
  this->m_Fuzziness = 0.0;
  this->m_Tolerance = 0.2;
  *(_WORD *)&this->m_bColorize = 0;
  this->m_flBlendFactor = 1.0;
  this->m_bEnable = true;
  _V_strcpy(dest: this->m_pName, src: "HSV");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A93C0
// Name: public: virtual char const __near * CSelectedHSVOperation::GetName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSelectedHSVOperation::GetName(CSelectedHSVOperation *this)
{
  return this->m_pName;
}

//------------------------------------------------------------------------------
// Address: 0x100A93D0
// Name: public: virtual void CSelectedHSVOperation::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectedHSVOperation::SetName(CSelectedHSVOperation *this, const char *pName)
{
  _V_strcpy(dest: this->m_pName, src: pName);
}

//------------------------------------------------------------------------------
// Address: 0x100A93F0
// Name: public: virtual bool CSelectedHSVOperation::IsEnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSelectedHSVOperation::IsEnabled(CSelectedHSVOperation *this)
{
  return this->m_bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x100A9400
// Name: public: virtual void CSelectedHSVOperation::SetEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectedHSVOperation::SetEnabled(CSelectedHSVOperation *this, bool bEnable)
{
  this->m_bEnable = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x100A9410
// Name: public: virtual float CSelectedHSVOperation::GetBlendFactor(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CSelectedHSVOperation::GetBlendFactor(CSelectedHSVOperation *this)
{
  return this->m_flBlendFactor;
}

//------------------------------------------------------------------------------
// Address: 0x100A9420
// Name: public: static void CSelectedHSVUIPanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSelectedHSVUIPanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CSelectedHSVUIPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CSelectedHSVUIPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSelectedHSVUIPanel");
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "TextChanged";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::FileOpenDialog::`vcall'{1132,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][0]) = 1;
    *(_QWORD *)&v3.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A94C0
// Name: public: CSelectedHSVUIPanel::CSelectedHSVUIPanel(class vgui::Panel __near *,class CSelectedHSVOperation __near *)
// Source: json
//------------------------------------------------------------------------------
CSelectedHSVUIPanel *__thiscall CSelectedHSVUIPanel::CSelectedHSVUIPanel(
        CSelectedHSVUIPanel *this,
        vgui::Panel *parent,
        CSelectedHSVOperation *pOp)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::ComboBox *v7; // eax
  vgui::ComboBox *v8; // eax
  CPrecisionSlider *v9; // eax
  CPrecisionSlider *v10; // eax
  CPrecisionSlider *v11; // eax
  CPrecisionSlider *v12; // eax
  CPrecisionSlider *v13; // eax
  CPrecisionSlider *v14; // eax
  CPrecisionSlider *v15; // eax
  CPrecisionSlider *v16; // eax
  CPrecisionSlider *v17; // eax
  CPrecisionSlider *v18; // eax
  CPrecisionSlider *v19; // eax
  CPrecisionSlider *v20; // eax
  vgui::CheckButton *v21; // eax
  vgui::CheckButton *v22; // eax
  vgui::CheckButton *v23; // eax
  vgui::CheckButton *v24; // eax
  vgui::Button *v25; // eax
  vgui::Button *v26; // eax
  vgui::Button *v27; // eax
  vgui::Button *v28; // eax
  vgui::Button *v29; // eax
  vgui::Button *v30; // eax
  vgui::TextEntry *v31; // eax
  vgui::TextEntry *v32; // eax
  vgui::TextEntry *v33; // eax
  vgui::TextEntry *v34; // eax
  vgui::TextEntry *v35; // eax
  vgui::TextEntry *v36; // eax
  CUncorrectedImagePanel *v37; // eax
  CUncorrectedImagePanel *v38; // eax
  CSelectedHSVOperation *m_pHSVOperation; // ecx
  CSelectedHSVOperation *v40; // ecx
  float v41; // xmm0_4
  IMatRenderContext *v42; // edi
  CFullScreenSelectionPanel *v43; // eax
  CFullScreenSelectionPanel *v44; // eax
  int v46; // [esp-8h] [ebp-24h]
  int v47; // [esp-4h] [ebp-20h]
  int x; // [esp+Ch] [ebp-10h] BYREF
  int y; // [esp+10h] [ebp-Ch] BYREF
  int w; // [esp+14h] [ebp-8h] BYREF
  int h; // [esp+18h] [ebp-4h] BYREF
  float parenta; // [esp+24h] [ebp+8h]

  CColorCorrectionUIChildPanel::CColorCorrectionUIChildPanel(this, parent, name: "SelectedHSVUIPanel");
  this->__vftable = (CSelectedHSVUIPanel_vtbl *)&CSelectedHSVUIPanel::`vftable';
  if ( `CSelectedHSVUIPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CSelectedHSVUIPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CSelectedHSVUIPanel");
    v4->pfnClassName = CSelectedHSVUIPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CColorCorrectionUIChildPanel");
  }
  if ( `CSelectedHSVUIPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSelectedHSVUIPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CSelectedHSVUIPanel");
    v5->pfnClassName = CSelectedHSVUIPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CColorCorrectionUIChildPanel");
  }
  if ( `CSelectedHSVUIPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSelectedHSVUIPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CSelectedHSVUIPanel");
    v6->pfnClassName = CSelectedHSVUIPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CColorCorrectionUIChildPanel");
  }
  CSelectedHSVUIPanel::PanelMessageFunc_OnTextChanged::InitVar();
  v7 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v7 != nullptr )
    v8 = vgui::ComboBox::ComboBox(this: v7, parent: this, panelName: "SelectionMethod", numLines: 10, allowEdit: false);
  else
    v8 = nullptr;
  this->m_pSelectionMethod = v8;
  this->m_pHSVOperation = pOp;
  v9 = (CPrecisionSlider *)MemAlloc_Alloc(nSize: 0x1BCu);
  if ( v9 != nullptr )
    v10 = CPrecisionSlider::CPrecisionSlider(this: v9, parent: this, panelName: "HueSlider");
  else
    v10 = nullptr;
  this->m_pHueSlider = v10;
  v11 = (CPrecisionSlider *)MemAlloc_Alloc(nSize: 0x1BCu);
  if ( v11 != nullptr )
    v12 = CPrecisionSlider::CPrecisionSlider(this: v11, parent: this, panelName: "SaturationSlider");
  else
    v12 = nullptr;
  this->m_pSaturationSlider = v12;
  v13 = (CPrecisionSlider *)MemAlloc_Alloc(nSize: 0x1BCu);
  if ( v13 != nullptr )
    v14 = CPrecisionSlider::CPrecisionSlider(this: v13, parent: this, panelName: "ValueSlider");
  else
    v14 = nullptr;
  this->m_pValueSlider = v14;
  v15 = (CPrecisionSlider *)MemAlloc_Alloc(nSize: 0x1BCu);
  if ( v15 != nullptr )
    v16 = CPrecisionSlider::CPrecisionSlider(this: v15, parent: this, panelName: "ToleranceSlider");
  else
    v16 = nullptr;
  this->m_pToleranceSlider = v16;
  v17 = (CPrecisionSlider *)MemAlloc_Alloc(nSize: 0x1BCu);
  if ( v17 != nullptr )
    v18 = CPrecisionSlider::CPrecisionSlider(this: v17, parent: this, panelName: "FuzzinessSlider");
  else
    v18 = nullptr;
  this->m_pFuzzinessSlider = v18;
  v19 = (CPrecisionSlider *)MemAlloc_Alloc(nSize: 0x1BCu);
  if ( v19 != nullptr )
    v20 = CPrecisionSlider::CPrecisionSlider(this: v19, parent: this, panelName: "BlendFactorSlider");
  else
    v20 = nullptr;
  this->m_pBlendFactorSlider = v20;
  v21 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v21 != nullptr )
    v22 = vgui::CheckButton::CheckButton(this: v21, parent: this, panelName: "ColorizeButton", text: "Colorize");
  else
    v22 = nullptr;
  this->m_pColorizeButton = v22;
  v23 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v23 != nullptr )
    v24 = vgui::CheckButton::CheckButton(
            this: v23,
            parent: this,
            panelName: "InvertSelectionButton",
            text: "Invert Selection");
  else
    v24 = nullptr;
  this->m_pInvertSelectionButton = v24;
  v25 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v25 != nullptr )
    v26 = vgui::Button::Button(
            this: v25,
            parent: this,
            panelName: "SelectionButton",
            text: "Select",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v26 = nullptr;
  this->m_pSelectionButton = v26;
  v26->AddActionSignalTarget_2(this: v26, a2: this);
  v27 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v27 != nullptr )
    v28 = vgui::Button::Button(
            this: v27,
            parent: this,
            panelName: "RGBPickButton",
            text: "RGB",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v28 = nullptr;
  this->m_pPickRGBButton = v28;
  v28->AddActionSignalTarget_2(this: v28, a2: this);
  v29 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v29 != nullptr )
    v30 = vgui::Button::Button(
            this: v29,
            parent: this,
            panelName: "HSVPickButton",
            text: "HSV",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v30 = nullptr;
  this->m_pPickHSVButton = v30;
  v30->AddActionSignalTarget_2(this: v30, a2: this);
  v31 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v31 != nullptr )
    v32 = vgui::TextEntry::TextEntry(this: v31, parent: this, panelName: "ColorEntry1");
  else
    v32 = nullptr;
  this->m_pColorEntry1 = v32;
  v33 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v33 != nullptr )
    v34 = vgui::TextEntry::TextEntry(this: v33, parent: this, panelName: "ColorEntry2");
  else
    v34 = nullptr;
  this->m_pColorEntry2 = v34;
  v35 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v35 != nullptr )
    v36 = vgui::TextEntry::TextEntry(this: v35, parent: this, panelName: "ColorEntry3");
  else
    v36 = nullptr;
  this->m_pColorEntry3 = v36;
  v37 = (CUncorrectedImagePanel *)MemAlloc_Alloc(nSize: 0x1CCu);
  if ( v37 != nullptr )
    v38 = CUncorrectedImagePanel::CUncorrectedImagePanel(this: v37, pParent: this, pName: "UncorrectedImage");
  else
    v38 = nullptr;
  m_pHSVOperation = this->m_pHSVOperation;
  this->m_pUncorrectedImage = v38;
  v38->m_pHSVOp = m_pHSVOperation;
  this->m_pHueSlider->SetRange(this: this->m_pHueSlider, a2: -360, a3: 360);
  this->m_pHueSlider->AddActionSignalTarget_2(this: this->m_pHueSlider, a2: this);
  this->m_pSaturationSlider->SetRange(this: this->m_pSaturationSlider, a2: -255, a3: 255);
  this->m_pSaturationSlider->AddActionSignalTarget_2(this: this->m_pSaturationSlider, a2: this);
  this->m_pValueSlider->SetRange(this: this->m_pValueSlider, a2: -255, a3: 255);
  this->m_pValueSlider->AddActionSignalTarget_2(this: this->m_pValueSlider, a2: this);
  this->m_pToleranceSlider->SetRange(this: this->m_pToleranceSlider, a2: 0, a3: 255);
  this->m_pToleranceSlider->AddActionSignalTarget_2(this: this->m_pToleranceSlider, a2: this);
  this->m_pFuzzinessSlider->SetRange(this: this->m_pFuzzinessSlider, a2: 0, a3: 255);
  this->m_pFuzzinessSlider->AddActionSignalTarget_2(this: this->m_pFuzzinessSlider, a2: this);
  this->m_pBlendFactorSlider->SetRange(this: this->m_pBlendFactorSlider, a2: 0, a3: 255);
  this->m_pBlendFactorSlider->AddActionSignalTarget_2(this: this->m_pBlendFactorSlider, a2: this);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource\\SelectedHSVUIPanel.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  CSelectedHSVUIPanel::PopulateControls(this);
  this->m_pColorizeButton->SetSelected(this: this->m_pColorizeButton, a2: this->m_pHSVOperation->m_bColorize);
  this->m_pColorizeButton->AddActionSignalTarget_2(this: this->m_pColorizeButton, a2: this);
  this->m_pInvertSelectionButton->SetSelected(
    this: this->m_pInvertSelectionButton,
    a2: this->m_pHSVOperation->m_bInvertSelection);
  this->m_pInvertSelectionButton->AddActionSignalTarget_2(this: this->m_pInvertSelectionButton, a2: this);
  CSelectedHSVUIPanel::ResetHSVSliders(this);
  v40 = this->m_pHSVOperation;
  if ( v40 != nullptr )
  {
    parenta = v40->GetBlendFactor(this: v40);
    v41 = parenta;
  }
  else
  {
    v41 = 0.0;
  }
  this->m_pBlendFactorSlider->SetValue(this: this->m_pBlendFactorSlider, a2: (int)(float)(v41 * 255.0), a3: true);
  v42 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v42 != nullptr )
    v42->BeginRender(this: v42);
  v42->GetViewport(this: v42, a2: &x, a3: &y, a4: &w, a5: &h);
  v43 = (CFullScreenSelectionPanel *)MemAlloc_Alloc(nSize: 0x158u);
  if ( v43 != nullptr )
    v44 = CFullScreenSelectionPanel::CFullScreenSelectionPanel(this: v43, pName: "SelectionPanel", pOp, pParent: this);
  else
    v44 = nullptr;
  v47 = h;
  v46 = w;
  this->m_pFullScreenSelection = v44;
  vgui::Panel::SetSize(this: v44, wide: v46, tall: v47);
  vgui::Panel::SetPos(this: this->m_pFullScreenSelection, x, y);
  this->m_pFullScreenSelection->SetEnabled(this: this->m_pFullScreenSelection, a2: false);
  this->m_pFullScreenSelection->SetVisible(this: this->m_pFullScreenSelection, a2: false);
  this->m_pFullScreenSelection->SetMouseInputEnabled(this: this->m_pFullScreenSelection, a2: false);
  vgui::Panel::MakePopup(this: this->m_pFullScreenSelection, showTaskbarIcon: true, disabled: false);
  this->m_pFullScreenSelection->AddActionSignalTarget_2(this: this->m_pFullScreenSelection, a2: this);
  this->m_bSelectionEnable = false;
  v42->EndRender(this: v42);
  v42->Release(this: v42);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A9B10
// Name: public: virtual class IColorOperation __near * CSelectedHSVUIPanel::GetOperation(void)
// Source: json
//------------------------------------------------------------------------------
CSelectedHSVOperation *__thiscall CSelectedHSVUIPanel::GetOperation(CSelectedHSVUIPanel *this)
{
  return this->m_pHSVOperation;
}

//------------------------------------------------------------------------------
// Address: 0x100A9B20
// Name: public: virtual struct vgui::PanelMessageMap __near * CSelectedHSVUIPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSelectedHSVUIPanel::GetMessageMap(CSelectedHSVUIPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSelectedHSVUIPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSelectedHSVUIPanel::GetMessageMap'::`2'::s_pMap;
  `CSelectedHSVUIPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSelectedHSVUIPanel");
  `CSelectedHSVUIPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A9B50
// Name: public: virtual struct PanelAnimationMap __near * CSelectedHSVUIPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSelectedHSVUIPanel::GetAnimMap(CSelectedHSVUIPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CSelectedHSVUIPanel");
}

//------------------------------------------------------------------------------
// Address: 0x100A9B60
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSelectedHSVUIPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSelectedHSVUIPanel::GetKBMap(CSelectedHSVUIPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSelectedHSVUIPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSelectedHSVUIPanel::GetKBMap'::`2'::s_pMap;
  `CSelectedHSVUIPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSelectedHSVUIPanel");
  `CSelectedHSVUIPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A9B90
// Name: public: static void CColorLookupUIPanel::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CColorLookupUIPanel::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CColorLookupUIPanel::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `CColorLookupUIPanel::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CColorLookupUIPanel");
    *(_QWORD *)&v3.m[2][0] = 0x100000001LL;
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "FileSelected";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::FileOpenDialog::`vcall'{1132,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][2]) = "fullpath";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A9C30
// Name: public: CColorLookupUIPanel::CColorLookupUIPanel(class vgui::Panel __near *,class CColorLookupOperation __near *)
// Source: json
//------------------------------------------------------------------------------
CColorLookupUIPanel *__thiscall CColorLookupUIPanel::CColorLookupUIPanel(
        CColorLookupUIPanel *this,
        vgui::Panel *pParent,
        CColorLookupOperation *pOp)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Button *v7; // eax
  vgui::Button *v8; // eax
  CPrecisionSlider *v9; // eax
  CPrecisionSlider *v10; // eax
  CPrecisionSlider_vtbl *v11; // edi
  double v12; // st7
  CColorLookupOperation *m_pLookupOp; // eax
  vgui::Button *m_pLoadButton; // ecx

  CColorCorrectionUIChildPanel::CColorCorrectionUIChildPanel(this, parent: pParent, name: "LookupUIPanel");
  this->__vftable = (CColorLookupUIPanel_vtbl *)&CColorLookupUIPanel::`vftable';
  if ( `CColorLookupUIPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CColorLookupUIPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CColorLookupUIPanel");
    v4->pfnClassName = CColorLookupUIPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CColorCorrectionUIChildPanel");
  }
  if ( `CColorLookupUIPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CColorLookupUIPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CColorLookupUIPanel");
    v5->pfnClassName = CColorLookupUIPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CColorCorrectionUIChildPanel");
  }
  if ( `CColorLookupUIPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CColorLookupUIPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CColorLookupUIPanel");
    v6->pfnClassName = CColorLookupUIPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CColorCorrectionUIChildPanel");
  }
  CColorLookupUIPanel::PanelMessageFunc_OnFileSelected::InitVar();
  this->m_pLookupOp = pOp;
  v7 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v7 != nullptr )
    v8 = vgui::Button::Button(
           this: v7,
           parent: this,
           panelName: "Load Lookup",
           text: defaultValue,
           pActionSignalTarget: this,
           pCmd: "LoadLookup");
  else
    v8 = nullptr;
  this->m_pLoadButton = v8;
  v9 = (CPrecisionSlider *)MemAlloc_Alloc(nSize: 0x1BCu);
  if ( v9 != nullptr )
    v10 = CPrecisionSlider::CPrecisionSlider(this: v9, parent: this, panelName: "BlendFactorSlider");
  else
    v10 = nullptr;
  this->m_pBlendFactorSlider = v10;
  v10->SetRange(this: v10, a2: 0, a3: 255);
  this->m_pBlendFactorSlider->AddActionSignalTarget_2(this: this->m_pBlendFactorSlider, a2: this);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource\\ColorLookupUIPanel.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  v11 = this->m_pBlendFactorSlider->__vftable;
  v12 = ((double (__thiscall *)(CColorLookupOperation *, int))pOp->GetBlendFactor)(a1: pOp, a2: 1) * 255.0;
  ((void (__thiscall *)(CPrecisionSlider *, int))v11->SetValue)(a1: this->m_pBlendFactorSlider, a2: (int)v12);
  m_pLookupOp = this->m_pLookupOp;
  m_pLoadButton = this->m_pLoadButton;
  if ( m_pLookupOp->m_LookupTable != nullptr )
    m_pLoadButton->SetText(this: m_pLoadButton, a2: m_pLookupOp->m_pFilename);
  else
    m_pLoadButton->SetText(this: m_pLoadButton, a2: "No File Loaded");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A9DF0
// Name: public: virtual class IColorOperation __near * CColorLookupUIPanel::GetOperation(void)
// Source: json
//------------------------------------------------------------------------------
CColorLookupOperation *__thiscall CColorLookupUIPanel::GetOperation(CColorLookupUIPanel *this)
{
  return this->m_pLookupOp;
}

//------------------------------------------------------------------------------
// Address: 0x100A9E00
// Name: public: virtual struct vgui::PanelMessageMap __near * CColorLookupUIPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CColorLookupUIPanel::GetMessageMap(CColorLookupUIPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CColorLookupUIPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorLookupUIPanel::GetMessageMap'::`2'::s_pMap;
  `CColorLookupUIPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CColorLookupUIPanel");
  `CColorLookupUIPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A9E30
// Name: public: virtual struct PanelAnimationMap __near * CColorLookupUIPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CColorLookupUIPanel::GetAnimMap(CColorLookupUIPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CColorLookupUIPanel");
}

//------------------------------------------------------------------------------
// Address: 0x100A9E40
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CColorLookupUIPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CColorLookupUIPanel::GetKBMap(CColorLookupUIPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CColorLookupUIPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorLookupUIPanel::GetKBMap'::`2'::s_pMap;
  `CColorLookupUIPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CColorLookupUIPanel");
  `CColorLookupUIPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A9E70
// Name: public: static void CColorBalanceUIPanel::PanelMessageFunc_OnRadioButtonHit::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CColorBalanceUIPanel::PanelMessageFunc_OnRadioButtonHit::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CColorBalanceUIPanel::PanelMessageFunc_OnRadioButtonHit::InitVar'::`2'::bAdded )
  {
    `CColorBalanceUIPanel::PanelMessageFunc_OnRadioButtonHit::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CColorBalanceUIPanel");
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "RadioButtonChecked";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::FileOpenDialog::`vcall'{1132,{flat}};
    memset(&v3.m[1][1], 0, 44);
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A9F00
// Name: public: CColorBalanceUIPanel::CColorBalanceUIPanel(class vgui::Panel __near *,class CColorBalanceOperation __near *)
// Source: json
//------------------------------------------------------------------------------
CColorBalanceUIPanel *__thiscall CColorBalanceUIPanel::CColorBalanceUIPanel(
        CColorBalanceUIPanel *this,
        vgui::Panel *pParent,
        CColorBalanceOperation *pOp)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::CheckButton *v7; // eax
  vgui::CheckButton *v8; // eax
  vgui::RadioButton *v9; // eax
  vgui::RadioButton *v10; // eax
  vgui::RadioButton *v11; // eax
  vgui::RadioButton *v12; // eax
  vgui::RadioButton *v13; // eax
  vgui::RadioButton *v14; // eax
  CPrecisionSlider *v15; // eax
  CPrecisionSlider *v16; // eax
  CPrecisionSlider *v17; // eax
  CPrecisionSlider *v18; // eax
  CPrecisionSlider *v19; // eax
  CPrecisionSlider *v20; // eax
  CPrecisionSlider *v21; // eax
  CPrecisionSlider *v22; // eax
  CPrecisionSlider_vtbl *v23; // edi
  double v24; // st7
  float bIsPreservingLuminosity; // [esp+14h] [ebp+8h]

  CColorCorrectionUIChildPanel::CColorCorrectionUIChildPanel(this, parent: pParent, name: "BalanceUIPanel");
  this->__vftable = (CColorBalanceUIPanel_vtbl *)&CColorBalanceUIPanel::`vftable';
  if ( `CColorBalanceUIPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CColorBalanceUIPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CColorBalanceUIPanel");
    v4->pfnClassName = CColorBalanceUIPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CColorCorrectionUIChildPanel");
  }
  if ( `CColorBalanceUIPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CColorBalanceUIPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CColorBalanceUIPanel");
    v5->pfnClassName = CColorBalanceUIPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CColorCorrectionUIChildPanel");
  }
  if ( `CColorBalanceUIPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CColorBalanceUIPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CColorBalanceUIPanel");
    v6->pfnClassName = CColorBalanceUIPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CColorCorrectionUIChildPanel");
  }
  CColorBalanceUIPanel::PanelMessageFunc_OnRadioButtonHit::InitVar();
  LOBYTE(pParent) = pOp->m_PreserveLuminosity;
  v7 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v7 != nullptr )
    v8 = vgui::CheckButton::CheckButton(
           this: v7,
           parent: this,
           panelName: "PreserveLuminosity",
           text: "Preserve Luminosity");
  else
    v8 = nullptr;
  this->m_pPreserveLuminosityButton = v8;
  v9 = (vgui::RadioButton *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v9 != nullptr )
    v10 = vgui::RadioButton::RadioButton(this: v9, parent: this, panelName: "ShadowMode", text: "Shadows");
  else
    v10 = nullptr;
  this->m_pShadowModeButton = v10;
  v11 = (vgui::RadioButton *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v11 != nullptr )
    v12 = vgui::RadioButton::RadioButton(this: v11, parent: this, panelName: "MidtoneMode", text: "Midtones");
  else
    v12 = nullptr;
  this->m_pMidtoneModeButton = v12;
  v13 = (vgui::RadioButton *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v13 != nullptr )
    v14 = vgui::RadioButton::RadioButton(this: v13, parent: this, panelName: "HighlightMode", text: "Highlights");
  else
    v14 = nullptr;
  this->m_pHighlightModeButton = v14;
  v15 = (CPrecisionSlider *)MemAlloc_Alloc(nSize: 0x1BCu);
  if ( v15 != nullptr )
    v16 = CPrecisionSlider::CPrecisionSlider(this: v15, parent: this, panelName: "CyanRedSlider");
  else
    v16 = nullptr;
  this->m_pCyanRedSlider = v16;
  v16->SetRange(this: v16, a2: -100, a3: 100);
  this->m_pCyanRedSlider->SetValue(this: this->m_pCyanRedSlider, a2: 0, a3: true);
  this->m_pCyanRedSlider->AddActionSignalTarget_2(this: this->m_pCyanRedSlider, a2: this);
  v17 = (CPrecisionSlider *)MemAlloc_Alloc(nSize: 0x1BCu);
  if ( v17 != nullptr )
    v18 = CPrecisionSlider::CPrecisionSlider(this: v17, parent: this, panelName: "MagentaGreenSlider");
  else
    v18 = nullptr;
  this->m_pMagentaGreenSlider = v18;
  v18->SetRange(this: v18, a2: -100, a3: 100);
  this->m_pMagentaGreenSlider->SetValue(this: this->m_pMagentaGreenSlider, a2: 0, a3: true);
  this->m_pMagentaGreenSlider->AddActionSignalTarget_2(this: this->m_pMagentaGreenSlider, a2: this);
  v19 = (CPrecisionSlider *)MemAlloc_Alloc(nSize: 0x1BCu);
  if ( v19 != nullptr )
    v20 = CPrecisionSlider::CPrecisionSlider(this: v19, parent: this, panelName: "YellowBlueSlider");
  else
    v20 = nullptr;
  this->m_pYellowBlueSlider = v20;
  v20->SetRange(this: v20, a2: -100, a3: 100);
  this->m_pYellowBlueSlider->SetValue(this: this->m_pYellowBlueSlider, a2: 0, a3: true);
  this->m_pYellowBlueSlider->AddActionSignalTarget_2(this: this->m_pYellowBlueSlider, a2: this);
  v21 = (CPrecisionSlider *)MemAlloc_Alloc(nSize: 0x1BCu);
  if ( v21 != nullptr )
    v22 = CPrecisionSlider::CPrecisionSlider(this: v21, parent: this, panelName: "BlendFactorSlider");
  else
    v22 = nullptr;
  this->m_pBlendFactorSlider = v22;
  v22->SetRange(this: v22, a2: 0, a3: 255);
  this->m_pBlendFactorSlider->AddActionSignalTarget_2(this: this->m_pBlendFactorSlider, a2: this);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource\\ColorBalanceUIPanel.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  this->m_pPreserveLuminosityButton->SetSelected(this: this->m_pPreserveLuminosityButton, a2: (bool)pParent);
  v23 = this->m_pBlendFactorSlider->__vftable;
  v24 = ((double (__thiscall *)(CColorBalanceOperation *, int))pOp->GetBlendFactor)(a1: pOp, a2: 1) * 255.0;
  ((void (__thiscall *)(CPrecisionSlider *, int))v23->SetValue)(a1: this->m_pBlendFactorSlider, a2: (int)v24);
  this->m_pBalanceOp = pOp;
  bIsPreservingLuminosity = pOp->GetBlendFactor(this: pOp);
  this->m_pBlendFactorSlider->SetValue(
    this: this->m_pBlendFactorSlider,
    a2: (int)(float)(bIsPreservingLuminosity * 255.0),
    a3: true);
  CColorBalanceUIPanel::ResetSliders(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100AA280
// Name: public: virtual struct vgui::PanelMessageMap __near * CColorBalanceUIPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CColorBalanceUIPanel::GetMessageMap(CColorBalanceUIPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CColorBalanceUIPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorBalanceUIPanel::GetMessageMap'::`2'::s_pMap;
  `CColorBalanceUIPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CColorBalanceUIPanel");
  `CColorBalanceUIPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AA2B0
// Name: public: virtual struct PanelAnimationMap __near * CColorBalanceUIPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CColorBalanceUIPanel::GetAnimMap(CColorBalanceUIPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CColorBalanceUIPanel");
}

//------------------------------------------------------------------------------
// Address: 0x100AA2C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CColorBalanceUIPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CColorBalanceUIPanel::GetKBMap(CColorBalanceUIPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CColorBalanceUIPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorBalanceUIPanel::GetKBMap'::`2'::s_pMap;
  `CColorBalanceUIPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CColorBalanceUIPanel");
  `CColorBalanceUIPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AA2F0
// Name: public: static void COperationListPanel::PanelMessageFunc_OnTextNewLine::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COperationListPanel::PanelMessageFunc_OnTextNewLine::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`COperationListPanel::PanelMessageFunc_OnTextNewLine::InitVar'::`2'::bAdded )
  {
    `COperationListPanel::PanelMessageFunc_OnTextNewLine::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COperationListPanel");
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "TextNewLine";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::BuildModeDialog::`vcall'{1120,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][0]) = 1;
    *(_QWORD *)&v3.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AA390
// Name: public: COperationListPanel::COperationListPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
COperationListPanel *__thiscall COperationListPanel::COperationListPanel(
        COperationListPanel *this,
        vgui::Panel *parent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::ListPanel::ListPanel(this, parent, panelName: pName);
  this->__vftable = (COperationListPanel_vtbl *)&COperationListPanel::`vftable';
  if ( `COperationListPanel::ChainToMap'::`2'::chained == 0 )
  {
    `COperationListPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "COperationListPanel");
    v4->pfnClassName = COperationListPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::ListPanel");
  }
  if ( `COperationListPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `COperationListPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "COperationListPanel");
    v5->pfnClassName = COperationListPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::ListPanel");
  }
  if ( `COperationListPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `COperationListPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "COperationListPanel");
    v6->pfnClassName = COperationListPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::ListPanel");
  }
  COperationListPanel::PanelMessageFunc_OnTextNewLine::InitVar();
  this->m_pNameEditPanel = nullptr;
  this->m_nEditItem = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100AA470
// Name: public: static void CColorOperationListPanel::PanelMessageFunc_OnOpPanelClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CColorOperationListPanel::PanelMessageFunc_OnOpPanelClose::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CColorOperationListPanel::PanelMessageFunc_OnOpPanelClose::InitVar'::`2'::bAdded )
  {
    `CColorOperationListPanel::PanelMessageFunc_OnOpPanelClose::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CColorOperationListPanel");
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "OpPanelClose";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::PropertyPage::`vcall'{944,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][0]) = 1;
    *(_QWORD *)&v3.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AA510
// Name: public: static void CColorOperationListPanel::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CColorOperationListPanel::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CColorOperationListPanel::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `CColorOperationListPanel::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CColorOperationListPanel");
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "SliderMoved";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::TextEntry::`vcall'{948,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][0]) = 1;
    *(_QWORD *)&v3.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AA5B0
// Name: public: static void CColorOperationListPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CColorOperationListPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CColorOperationListPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `CColorOperationListPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CColorOperationListPanel");
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "CheckButtonChecked";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][0]) = 1;
    *(_QWORD *)&v3.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AA650
// Name: public: static void CColorOperationListPanel::PanelMessageFunc_OnLaunchOperation::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CColorOperationListPanel::PanelMessageFunc_OnLaunchOperation::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CColorOperationListPanel::PanelMessageFunc_OnLaunchOperation::InitVar'::`2'::bAdded )
  {
    `CColorOperationListPanel::PanelMessageFunc_OnLaunchOperation::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CColorOperationListPanel");
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "LaunchOperation";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::PropertyPage::`vcall'{956,{flat}};
    memset(&v3.m[1][1], 0, 12);
    *(_QWORD *)&v3.m[2][0] = 0x200000001LL;
    LODWORD(v3.m[2][2]) = "item";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AA6F0
// Name: public: CColorOperationListPanel::CColorOperationListPanel(class vgui::Panel __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CColorOperationListPanel *__thiscall CColorOperationListPanel::CColorOperationListPanel(
        CColorOperationListPanel *this,
        vgui::Panel *parent,
        unsigned int CCHandle)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Button *v7; // eax
  vgui::Button *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  vgui::Button *v14; // eax
  vgui::Button *v15; // eax
  vgui::Button *v16; // eax
  vgui::Button *v17; // eax
  vgui::Button *v18; // eax
  vgui::Button *v19; // eax
  vgui::Button *v20; // eax
  vgui::CheckButton *v21; // eax
  vgui::CheckButton *v22; // eax
  vgui::CheckButton *v23; // eax
  vgui::CheckButton *v24; // eax
  CPrecisionSlider *v25; // eax
  CPrecisionSlider *v26; // eax
  COperationListPanel *v27; // eax
  COperationListPanel *v28; // eax
  vgui::ImageList *v29; // eax
  vgui::Dar<unsigned long> *v30; // edi
  vgui::IImage *v31; // eax
  CLookupViewWindow *v32; // eax
  CLookupViewWindow *v33; // eax
  vgui::FileOpenStateMachine *v34; // eax
  vgui::FileOpenStateMachine *v35; // eax

  vgui::EditablePanel::EditablePanel(this, parent, panelName: "ColorOperationListPanel");
  this->vgui::IFileOpenStateMachineClient::__vftable = (vgui::IFileOpenStateMachineClient_vtbl *)&vgui::IFileOpenStateMachineClient::`vftable';
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CColorOperationListPanel_vtbl *)&CColorOperationListPanel::`vftable'{for `vgui::EditablePanel'};
  this->vgui::IFileOpenStateMachineClient::__vftable = (vgui::IFileOpenStateMachineClient_vtbl *)&CColorOperationListPanel::`vftable'{for `vgui::IFileOpenStateMachineClient'};
  if ( `CColorOperationListPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CColorOperationListPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CColorOperationListPanel");
    v4->pfnClassName = CColorOperationListPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CColorOperationListPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CColorOperationListPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CColorOperationListPanel");
    v5->pfnClassName = CColorOperationListPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CColorOperationListPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CColorOperationListPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CColorOperationListPanel");
    v6->pfnClassName = CColorOperationListPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CColorOperationListPanel::PanelMessageFunc_OnOpPanelClose::InitVar();
  CColorOperationListPanel::PanelMessageFunc_OnSliderMoved::InitVar();
  CColorOperationListPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar();
  CColorOperationListPanel::PanelMessageFunc_OnLaunchOperation::InitVar();
  this->m_OperationList.m_OpList.m_Memory.m_pMemory = nullptr;
  this->m_OperationList.m_OpList.m_Memory.m_nAllocationCount = 0;
  this->m_OperationList.m_OpList.m_Memory.m_nGrowSize = 0;
  this->m_OperationList.m_OpList.m_Size = 0;
  this->m_OperationList.m_OpList.m_pElements = nullptr;
  this->m_OpPanelList.m_Memory.m_pMemory = nullptr;
  this->m_OpPanelList.m_Memory.m_nAllocationCount = 0;
  this->m_OpPanelList.m_Memory.m_nGrowSize = 0;
  this->m_OpPanelList.m_Size = 0;
  this->m_OpPanelList.m_pElements = nullptr;
  CUtlString::CUtlString(this: &this->m_FileName);
  v7 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v7 != nullptr )
    v8 = vgui::Button::Button(
           this: v7,
           parent: this,
           panelName: "NewOperation",
           text: "New",
           pActionSignalTarget: this,
           pCmd: "NewOperation");
  else
    v8 = nullptr;
  this->m_pNewOperationButton = v8;
  v9 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "DeleteOperation",
            text: "Delete",
            pActionSignalTarget: this,
            pCmd: "DeleteOperation");
  else
    v10 = nullptr;
  this->m_pDeleteOperationButton = v10;
  v11 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: this,
            panelName: "BringForward",
            text: "Up",
            pActionSignalTarget: this,
            pCmd: "BringForward");
  else
    v12 = nullptr;
  this->m_pBringForwardButton = v12;
  v13 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v13 != nullptr )
    v14 = vgui::Button::Button(
            this: v13,
            parent: this,
            panelName: "PushBack",
            text: "Down",
            pActionSignalTarget: this,
            pCmd: "PushBack");
  else
    v14 = nullptr;
  this->m_pPushBackButton = v14;
  v15 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v15 != nullptr )
    v16 = vgui::Button::Button(
            this: v15,
            parent: this,
            panelName: "Save",
            text: "Save",
            pActionSignalTarget: this,
            pCmd: "Save");
  else
    v16 = nullptr;
  this->m_pSaveButton = v16;
  v17 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v17 != nullptr )
    v18 = vgui::Button::Button(
            this: v17,
            parent: this,
            panelName: "SaveAs",
            text: "Save As",
            pActionSignalTarget: this,
            pCmd: "SaveAs");
  else
    v18 = nullptr;
  this->m_pSaveAsButton = v18;
  v19 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v19 != nullptr )
    v20 = vgui::Button::Button(
            this: v19,
            parent: this,
            panelName: "Load",
            text: "Load",
            pActionSignalTarget: this,
            pCmd: "Load");
  else
    v20 = nullptr;
  this->m_pLoadButton = v20;
  v21 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v21 != nullptr )
    v22 = vgui::CheckButton::CheckButton(this: v21, parent: this, panelName: "Enable", text: "Enable");
  else
    v22 = nullptr;
  this->m_pEnableButton = v22;
  v22->SetSelected(this: v22, a2: false);
  this->m_pEnableButton->AddActionSignalTarget_2(this: this->m_pEnableButton, a2: this);
  v23 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v23 != nullptr )
    v24 = vgui::CheckButton::CheckButton(this: v23, parent: this, panelName: "EnableEntities", text: "Enable Entities");
  else
    v24 = nullptr;
  this->m_pEnableEntitiesButton = v24;
  v24->SetSelected(this: v24, a2: true);
  this->m_pEnableEntitiesButton->AddActionSignalTarget_2(this: this->m_pEnableEntitiesButton, a2: this);
  v25 = (CPrecisionSlider *)MemAlloc_Alloc(nSize: 0x1BCu);
  if ( v25 != nullptr )
    v26 = CPrecisionSlider::CPrecisionSlider(this: v25, parent: this, panelName: "BlendFactorSlider");
  else
    v26 = nullptr;
  this->m_pBlendFactorSlider = v26;
  v26->SetRange(this: v26, a2: 0, a3: 255);
  this->m_pBlendFactorSlider->SetValue(this: this->m_pBlendFactorSlider, a2: 255, a3: true);
  this->m_pBlendFactorSlider->AddActionSignalTarget_2(this: this->m_pBlendFactorSlider, a2: this);
  v27 = (COperationListPanel *)MemAlloc_Alloc(nSize: 0x258u);
  if ( v27 != nullptr )
    v28 = COperationListPanel::COperationListPanel(this: v27, parent: this, pName: "OperationList");
  else
    v28 = nullptr;
  this->m_pOperationListPanel = v28;
  vgui::Panel::SetBuildModeEditable(this: v28, state: true);
  this->m_pOperationListPanel->AddColumnHeader(
    this: this->m_pOperationListPanel,
    a2: 0,
    a3: "image",
    a4: defaultValue,
    a5: 24,
    a6: 4);
  this->m_pOperationListPanel->AddColumnHeader(
    this: this->m_pOperationListPanel,
    a2: 1,
    a3: "layer",
    a4: defaultValue,
    a5: 226,
    a6: 0);
  this->m_pOperationListPanel->SetSelectIndividualCells(this: this->m_pOperationListPanel, a2: false);
  this->m_pOperationListPanel->SetEmptyListText_2(this: this->m_pOperationListPanel, a2: defaultValue);
  this->m_pOperationListPanel->SetDragEnabled(this: this->m_pOperationListPanel, a2: false);
  this->m_pOperationListPanel->SetColumnSortable(this: this->m_pOperationListPanel, a2: 0, a3: true);
  this->m_pOperationListPanel->SetColumnSortable(this: this->m_pOperationListPanel, a2: 1, a3: false);
  this->m_pOperationListPanel->AddActionSignalTarget_2(this: this->m_pOperationListPanel, a2: this);
  v29 = (vgui::ImageList *)MemAlloc_Alloc(nSize: 0x18u);
  if ( v29 != nullptr )
    v30 = (vgui::Dar<unsigned long> *)vgui::ImageList::ImageList(this: v29, deleteImagesWhenDone: false);
  else
    v30 = nullptr;
  v31 = g_pVGuiSchemeManager->GetImage(this: g_pVGuiSchemeManager, a2: "Resource/icon_hlicon1", a3: 0);
  vgui::Dar<unsigned long>::AddElement(this: v30, elem: (unsigned int)v31);
  this->m_pOperationListPanel->SetImageList(this: this->m_pOperationListPanel, a2: (vgui::ImageList *)v30, a3: true);
  v32 = (CLookupViewWindow *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v32 != nullptr )
    v33 = CLookupViewWindow::CLookupViewWindow(this: v32, parent: this, CCHandle);
  else
    v33 = nullptr;
  this->m_pLookupViewWindow = v33;
  v33->SetTitle_2(this: v33, a2: "Lookup View", a3: true);
  vgui::Panel::SetSize(this: this->m_pLookupViewWindow, wide: 148, tall: 298);
  this->m_pLookupViewWindow->SetEnabled(this: this->m_pLookupViewWindow, a2: true);
  this->m_pLookupViewWindow->SetSizeable(this: this->m_pLookupViewWindow, a2: false);
  this->m_pLookupViewWindow->AddActionSignalTarget_2(this: this->m_pLookupViewWindow, a2: this);
  this->m_pLookupViewWindow->Activate(this: this->m_pLookupViewWindow);
  v34 = (vgui::FileOpenStateMachine *)MemAlloc_Alloc(nSize: 0x1B0u);
  if ( v34 != nullptr )
    v35 = vgui::FileOpenStateMachine::FileOpenStateMachine(
            this: v34,
            pParent: this,
            pClient: &this->vgui::IFileOpenStateMachineClient);
  else
    v35 = nullptr;
  this->m_pFileOpenStateMachine = v35;
  v35->AddActionSignalTarget_2(this: v35, a2: this);
  this->m_pNewDialog = nullptr;
  *(_WORD *)&this->m_bEnable = 257;
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "Resource\\ColorOperationListPanel.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Panel::SetVisible(this, state: 1);
  CColorOperationListPanel::ResetSlider(this);
  CColorOperationListPanel::PopulateList(this);
  this->m_CCHandle = CCHandle;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100AACE0
// Name: public: virtual void CColorOperationListPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CColorOperationListPanel::OnCommand(
        CColorOperationListPanel *this@<ecx>,
        int a2@<ebx>,
        const char *command)
{
  CNewOperationDialog *v4; // eax
  CNewOperationDialog *v5; // eax
  int v6; // eax
  CColorOperationList *p_m_OperationList; // ecx
  IColorOperation *v8; // ebx
  int v9; // edi
  CColorCorrectionUIChildPanel *v10; // ecx
  CColorCorrectionUIChildPanel *v11; // ecx
  int v12; // edi
  IColorOperation *v13; // ebx
  int v14; // edi
  char *v15; // ebx
  int v16; // edi
  int v17; // ebx
  int v18; // edi
  int v19; // ebx
  const char *v20; // eax
  int v21; // eax
  const char *v22; // eax
  CNewOperationDialog *v23; // ecx
  COperationListPanel *m_pOperationListPanel; // ecx
  COperationListPanel_vtbl *v25; // edi
  int v26; // eax
  CNewOperationDialog *m_pNewDialog; // ecx
  int v28; // eax
  IColorOperation *Operation; // eax
  IColorOperation *v30; // eax
  BOOL v31; // [esp-8h] [ebp-10h]
  int v32; // [esp-8h] [ebp-10h]

  if ( _V_stricmp(s1: command, s2: "NewOperation") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "DeleteOperation") != 0 )
    {
      if ( _V_stricmp(s1: command, s2: "BringForward") != 0 )
      {
        if ( _V_stricmp(s1: command, s2: "PushBack") != 0 )
        {
          if ( _V_stricmp(s1: command, s2: "Save") == 0 )
          {
            CP4Factory::SetDummyMode(this: g_p4factory, bDummyMode: p4 == nullptr);
            CP4Factory::SetOpenFileChangeList(this: g_p4factory, szChangeListName: "Color Correction Auto Checkout");
            v31 = p4 != nullptr;
            v20 = CUtlString::Get(this: &this->m_FileName);
            vgui::FileOpenStateMachine::SaveFile(
              this: this->m_pFileOpenStateMachine,
              pContextKeyValues: nullptr,
              pFileName: v20,
              pFileType: "vcc",
              nFlags: v31);
            return;
          }
          if ( _V_stricmp(s1: command, s2: "SaveAs") == 0 )
          {
            CP4Factory::SetDummyMode(this: g_p4factory, bDummyMode: p4 == nullptr);
            CP4Factory::SetOpenFileChangeList(this: g_p4factory, szChangeListName: "Color Correction Auto Checkout");
            vgui::FileOpenStateMachine::SaveFile(
              this: this->m_pFileOpenStateMachine,
              pContextKeyValues: nullptr,
              pFileName: nullptr,
              pFileType: "vcc",
              nFlags: p4 != nullptr);
            return;
          }
          if ( _V_stricmp(s1: command, s2: "Load") != 0 )
          {
            if ( _V_stricmp(s1: command, s2: "NewComplete") != 0 )
            {
              if ( _V_stricmp(s1: command, s2: "NewCancel") != 0 )
              {
                if ( _V_stricmp(s1: command, s2: "SelectedItemChanged") == 0
                  || _V_stricmp(s1: command, s2: "BlendFactorUpdate") == 0 )
                {
                  CColorOperationListPanel::ResetSlider(this);
                  return;
                }
                if ( _V_stricmp(s1: command, s2: "UpdateList") != 0 )
                {
                  if ( _V_stricmp(s1: command, s2: "CloneOperation") != 0 )
                    return;
                  v28 = this->m_pOperationListPanel->GetSelectedItem(this: this->m_pOperationListPanel, a2: 0);
                  Operation = CColorOperationList::GetOperation(this: &this->m_OperationList, opIndex: v28);
                  v30 = Operation->Clone(this: Operation);
                  CColorOperationList::AddOperation(this: &this->m_OperationList, pOp: v30);
                }
                CColorOperationListPanel::PopulateList(this);
              }
              else
              {
                m_pNewDialog = this->m_pNewDialog;
                if ( m_pNewDialog != nullptr )
                {
                  ((void (__thiscall *)(CNewOperationDialog *, int))m_pNewDialog->dtr_Panel)(a1: m_pNewDialog, a2: 1);
                  this->m_pNewDialog = nullptr;
                }
              }
            }
            else
            {
              v23 = this->m_pNewDialog;
              if ( v23 != nullptr )
              {
                ((void (__thiscall *)(CNewOperationDialog *, int))v23->dtr_Panel)(a1: v23, a2: 1);
                this->m_pNewDialog = nullptr;
              }
              CColorOperationListPanel::PopulateList(this);
              m_pOperationListPanel = this->m_pOperationListPanel;
              v25 = m_pOperationListPanel->__vftable;
              v26 = m_pOperationListPanel->GetItemCount(this: m_pOperationListPanel);
              v25->SetSingleSelectedItem(this: this->m_pOperationListPanel, a2: v26 - 1);
              this->OnKeyCodeTyped(this, a2: KEY_ENTER);
            }
          }
          else
          {
            CP4Factory::SetDummyMode(this: g_p4factory, bDummyMode: p4 == nullptr);
            CP4Factory::SetOpenFileChangeList(this: g_p4factory, szChangeListName: "Color Correction Auto Checkout");
            v21 = 2;
            if ( p4 != nullptr )
              v21 = 3;
            v32 = v21;
            v22 = CUtlString::Get(this: &this->m_FileName);
            vgui::FileOpenStateMachine::OpenFile(
              this: this->m_pFileOpenStateMachine,
              pOpenFileName: nullptr,
              pOpenFileType: "vcc",
              pContextKeyValues: nullptr,
              pSaveFileName: v22,
              pSaveFileType: "vcc",
              nFlags: v32);
          }
        }
        else
        {
          v16 = this->m_pOperationListPanel->GetSelectedItem(this: this->m_pOperationListPanel, a2: 0);
          v17 = this->m_pOperationListPanel->GetItemCurrentRow(this: this->m_pOperationListPanel, a2: v16);
          if ( this->m_pOperationListPanel->IsValidItemID(this: this->m_pOperationListPanel, a2: v16)
            && v17 < this->m_OperationList.m_OpList.m_Size - 1 )
          {
            CColorOperationList::PushBack(this: &this->m_OperationList, opIndex: v17);
            CColorOperationListPanel::PopulateList(this);
            colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
            v18 = this->m_pOperationListPanel->FirstItem(this: this->m_pOperationListPanel);
            if ( v18 != this->m_pOperationListPanel->InvalidItemID(this: this->m_pOperationListPanel) )
            {
              v19 = v17 + 1;
              do
              {
                if ( ((int (__thiscall *)(COperationListPanel *, int, int))this->m_pOperationListPanel->GetItemCurrentRow)(
                       a1: this->m_pOperationListPanel,
                       a2: v18,
                       a3: a2) == v19 )
                  this->m_pOperationListPanel->SetSingleSelectedItem(this: this->m_pOperationListPanel, a2: v18);
                a2 = v18;
                v18 = ((int (__thiscall *)(COperationListPanel *))this->m_pOperationListPanel->NextItem)(a1: this->m_pOperationListPanel);
              }
              while ( v18 != this->m_pOperationListPanel->InvalidItemID(this: this->m_pOperationListPanel) );
            }
          }
        }
      }
      else
      {
        v12 = this->m_pOperationListPanel->GetSelectedItem(this: this->m_pOperationListPanel, a2: 0);
        v13 = (IColorOperation *)this->m_pOperationListPanel->GetItemCurrentRow(
                                   this: this->m_pOperationListPanel,
                                   a2: v12);
        if ( this->m_pOperationListPanel->IsValidItemID(this: this->m_pOperationListPanel, a2: v12) && v13 != nullptr )
        {
          CColorOperationList::BringForward(this: &this->m_OperationList, opIndex: v13);
          CColorOperationListPanel::PopulateList(this);
          colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
          v14 = this->m_pOperationListPanel->FirstItem(this: this->m_pOperationListPanel);
          if ( v14 != this->m_pOperationListPanel->InvalidItemID(this: this->m_pOperationListPanel) )
          {
            v15 = (char *)&v13[-1].__vftable + 3;
            do
            {
              if ( (char *)((int (__thiscall *)(COperationListPanel *, int, int))this->m_pOperationListPanel->GetItemCurrentRow)(
                             a1: this->m_pOperationListPanel,
                             a2: v14,
                             a3: a2) == v15 )
                this->m_pOperationListPanel->SetSingleSelectedItem(this: this->m_pOperationListPanel, a2: v14);
              a2 = v14;
              v14 = ((int (__thiscall *)(COperationListPanel *))this->m_pOperationListPanel->NextItem)(a1: this->m_pOperationListPanel);
            }
            while ( v14 != this->m_pOperationListPanel->InvalidItemID(this: this->m_pOperationListPanel) );
          }
        }
      }
    }
    else if ( this->m_pOperationListPanel->GetSelectedItemsCount(this: this->m_pOperationListPanel) != 0 )
    {
      v6 = this->m_pOperationListPanel->GetSelectedItem(this: this->m_pOperationListPanel, a2: 0);
      p_m_OperationList = &this->m_OperationList;
      if ( v6 >= 0 && v6 < this->m_OperationList.m_OpList.m_Size )
        v8 = p_m_OperationList->m_OpList.m_Memory.m_pMemory[v6];
      else
        v8 = nullptr;
      CColorOperationList::DeleteOperation(this: p_m_OperationList, opIndex: v6);
      v9 = 0;
      if ( this->m_OpPanelList.m_Size > 0 )
      {
        while ( 1 )
        {
          v10 = this->m_OpPanelList.m_Memory.m_pMemory[v9];
          if ( v10->GetOperation(this: v10) == v8 )
            break;
          if ( ++v9 >= this->m_OpPanelList.m_Size )
            goto LABEL_22;
        }
        v11 = this->m_OpPanelList.m_Memory.m_pMemory[v9];
        if ( v11 != nullptr )
          ((void (__thiscall *)(CColorCorrectionUIChildPanel *, int))v11->dtr_Panel)(a1: v11, a2: 1);
        if ( this->m_OpPanelList.m_Size - v9 - 1 > 0 )
          _V_memmove(
            dest: &this->m_OpPanelList.m_Memory.m_pMemory[v9],
            src: &this->m_OpPanelList.m_Memory.m_pMemory[v9 + 1],
            count: 4 * (this->m_OpPanelList.m_Size - v9 - 1));
        --this->m_OpPanelList.m_Size;
      }
LABEL_22:
      CColorOperationListPanel::PopulateList(this);
      colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
    }
  }
  else if ( this->m_pNewDialog == nullptr )
  {
    v4 = (CNewOperationDialog *)MemAlloc_Alloc(nSize: 0x228u);
    if ( v4 != nullptr )
      v5 = CNewOperationDialog::CNewOperationDialog(this: v4, parent: this, pOpList: &this->m_OperationList);
    else
      v5 = nullptr;
    this->m_pNewDialog = v5;
    v5->AddActionSignalTarget_2(this: v5, a2: this);
    this->m_pNewDialog->Activate(this: this->m_pNewDialog);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AB2F0
// Name: private: void CColorOperationListPanel::LaunchOperationPanel(class IColorOperation __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CColorOperationListPanel::LaunchOperationPanel(
        CColorOperationListPanel *this@<ecx>,
        int a2@<esi>,
        CCurvesColorOperation *pOp)
{
  CColorCorrectionUIChildPanel *v5; // esi
  CColorCurvesUIPanel *v6; // esi
  CColorBalanceUIPanel *v7; // eax
  CColorCurvesUIPanel *v8; // eax
  CColorLevelsUIPanel *v9; // eax
  CColorLookupUIPanel *v10; // eax
  CSelectedHSVUIPanel *v11; // eax
  vgui::Panel *v12; // eax
  int v13; // eax
  int v14; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CColorCorrectionUIChildPanel **m_pMemory; // ecx
  int v18; // eax
  CColorCorrectionUIChildPanel **v19; // ebx
  int parentX; // [esp+8h] [ebp-8h] BYREF
  int parentY; // [esp+Ch] [ebp-4h] BYREF
  int i; // [esp+18h] [ebp+8h]
  int ia; // [esp+18h] [ebp+8h]
  void (__thiscall **ib)(CColorCurvesUIPanel *, int); // [esp+18h] [ebp+8h]

  if ( pOp != nullptr )
  {
    i = 0;
    if ( this->m_OpPanelList.m_Size <= 0 )
    {
LABEL_5:
      v6 = nullptr;
      switch ( ((int (__thiscall *)(CCurvesColorOperation *, int))pOp->ToolID)(a1: pOp, a2) )
      {
        case 1:
          v8 = (CColorCurvesUIPanel *)MemAlloc_Alloc(nSize: 0x228u);
          if ( v8 == nullptr )
            goto LABEL_17;
          v6 = CColorCurvesUIPanel::CColorCurvesUIPanel(this: v8, pParent: this, pOp);
          break;
        case 2:
          v9 = (CColorLevelsUIPanel *)MemAlloc_Alloc(nSize: 0x230u);
          if ( v9 == nullptr )
            goto LABEL_17;
          v6 = (CColorCurvesUIPanel *)CColorLevelsUIPanel::CColorLevelsUIPanel(
                                        this: v9,
                                        pParent: this,
                                        (CLevelsColorOperation *)pOp);
          break;
        case 3:
          v11 = (CSelectedHSVUIPanel *)MemAlloc_Alloc(nSize: 0x264u);
          if ( v11 == nullptr )
            goto LABEL_17;
          v6 = (CColorCurvesUIPanel *)CSelectedHSVUIPanel::CSelectedHSVUIPanel(
                                        this: v11,
                                        parent: this,
                                        (CSelectedHSVOperation *)pOp);
          break;
        case 4:
          v10 = (CColorLookupUIPanel *)MemAlloc_Alloc(nSize: 0x224u);
          if ( v10 == nullptr )
            goto LABEL_17;
          v6 = (CColorCurvesUIPanel *)CColorLookupUIPanel::CColorLookupUIPanel(
                                        this: v10,
                                        pParent: this,
                                        (CColorLookupOperation *)pOp);
          break;
        case 5:
          v7 = (CColorBalanceUIPanel *)MemAlloc_Alloc(nSize: 0x23Cu);
          if ( v7 != nullptr )
            v6 = (CColorCurvesUIPanel *)CColorBalanceUIPanel::CColorBalanceUIPanel(
                                          this: v7,
                                          pParent: this,
                                          (CColorBalanceOperation *)pOp);
          else
LABEL_17:
            v6 = nullptr;
          break;
        default:
          break;
      }
      v12 = this->GetParent(this);
      vgui::Panel::GetPos(this: v12, x: &parentX, y: &parentY);
      v13 = parentX / 250;
      if ( this->m_OpPanelList.m_Size + 1 < parentX / 250 )
        v13 = this->m_OpPanelList.m_Size + 1;
      ia = parentX - 250 * v13;
      if ( pOp->ToolID(this: pOp) == CC_TOOL_SELECTED_HSV )
      {
        vgui::Panel::SetPos(this: v6, x: ia, y: parentY - 40);
        vgui::Panel::SetSize(this: v6, wide: 250, tall: 520);
      }
      else
      {
        vgui::Panel::SetPos(this: v6, x: ia, y: parentY);
        vgui::Panel::SetSize(this: v6, wide: 250, tall: 480);
      }
      ib = (void (__thiscall **)(CColorCurvesUIPanel *, int))&v6->SetTitle_2;
      v14 = ((int (__thiscall *)(CCurvesColorOperation *, int))pOp->GetName)(a1: pOp, a2: 1);
      (*ib)(a1: v6, a2: v14);
      v6->AddActionSignalTarget_2(this: v6, a2: this);
      v6->SetSizeable(this: v6, a2: false);
      v6->SetVisible(this: v6, a2: true);
      v6->Init(this: v6);
      m_Size = this->m_OpPanelList.m_Size;
      m_nAllocationCount = this->m_OpPanelList.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<INetMessage *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&this->m_OpPanelList,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_OpPanelList.m_Size;
      m_pMemory = this->m_OpPanelList.m_Memory.m_pMemory;
      v18 = this->m_OpPanelList.m_Size - m_Size - 1;
      this->m_OpPanelList.m_pElements = m_pMemory;
      if ( v18 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v18);
      v19 = &this->m_OpPanelList.m_Memory.m_pMemory[m_Size];
      if ( v19 != nullptr )
        *v19 = v6;
    }
    else
    {
      while ( 1 )
      {
        v5 = this->m_OpPanelList.m_Memory.m_pMemory[i];
        if ( v5->GetOperation(this: v5) == pOp )
          break;
        if ( ++i >= this->m_OpPanelList.m_Size )
          goto LABEL_5;
      }
      v5->Activate(this: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AB580
// Name: public: CColorCorrectionUIPanel::CColorCorrectionUIPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CColorCorrectionUIPanel *__thiscall CColorCorrectionUIPanel::CColorCorrectionUIPanel(
        CColorCorrectionUIPanel *this,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  CColorOperationListPanel *m_pOperationListPanel; // ecx
  unsigned int v8; // eax
  CColorOperationListPanel *v9; // eax
  CColorOperationListPanel *v10; // eax
  int v11; // edi
  int v12; // eax

  vgui::Frame::Frame(this, parent, panelName: "ColorCorrectionUIPanel", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CColorCorrectionUIPanel_vtbl *)&CColorCorrectionUIPanel::`vftable';
  if ( `CColorCorrectionUIPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CColorCorrectionUIPanel::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CColorCorrectionUIPanel");
    v3->pfnClassName = CColorCorrectionUIPanel::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CColorCorrectionUIPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CColorCorrectionUIPanel::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CColorCorrectionUIPanel");
    v4->pfnClassName = CColorCorrectionUIPanel::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CColorCorrectionUIPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CColorCorrectionUIPanel::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CColorCorrectionUIPanel");
    v5->pfnClassName = CColorCorrectionUIPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  if ( colorcorrection != nullptr )
  {
    v8 = colorcorrection->AddLookup(this: colorcorrection, a2: "editable");
    this->m_CCHandle = v8;
    colorcorrection->SetResetable(this: colorcorrection, a2: v8, a3: true);
    this->m_bForceReset = true;
    this->m_bEnable = false;
    vgui::Frame::SetTitle(this, title: "Color Correction Tools", surfaceTitle: true);
    v9 = (CColorOperationListPanel *)MemAlloc_Alloc(nSize: 0x200u);
    if ( v9 != nullptr )
      v10 = CColorOperationListPanel::CColorOperationListPanel(this: v9, parent: this, CCHandle: this->m_CCHandle);
    else
      v10 = nullptr;
    this->m_pOperationListPanel = v10;
    v10->AddActionSignalTarget_2(this: v10, a2: this);
    vgui::Frame::LoadControlSettings(
      this,
      dialogResourceName: "Resource\\ColorCorrectionUIPanel.res",
      pathID: nullptr,
      pPreloadedKeyValues: nullptr,
      pConditions: nullptr);
    vgui::Panel::SetVisible(this, state: 0);
    vgui::Frame::SetSizeable(this, state: false);
    vgui::Frame::SetMoveable(this, state: true);
    v11 = videomode->GetModeWidth(this: videomode) - 360;
    v12 = videomode->GetModeHeight(this: videomode);
    vgui::Panel::SetBounds(this, x: v11, y: v12 - 490, wide: 350, tall: 480);
    CColorOperationListPanel::PopulateList(this: this->m_pOperationListPanel);
    _V_memset(dest: this->m_pLookupCache, fill: 0, count: 98304);
    _V_memset(dest: this->m_pLookupCache360, fill: 0, count: 98304);
    this->m_nCurrentRow = -1;
    this->m_nRowStep = 4;
    this->m_pFinalOperation = nullptr;
  }
  else
  {
    this->m_pOperationListPanel = nullptr;
    this->m_CCHandle = 0;
    _Warning(a1: "Could not get the color correction interface!");
    m_pOperationListPanel = this->m_pOperationListPanel;
    if ( m_pOperationListPanel != nullptr )
    {
      CColorOperationListPanel::Shutdown(this: m_pOperationListPanel);
      return this;
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100AB7A0
// Name: private: bool CColorOperationListPanel::SaveVCCFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CColorOperationListPanel::SaveVCCFile(CColorOperationListPanel *this, const char *pFullPath)
{
  CColorOperationListPanel *v2; // ebx
  CDmxElement *DmxElement; // edi
  CDmxAttribute *v4; // eax
  CDmxAttribute *v5; // esi
  _DWORD *m_pData; // eax
  CUtlMemory<S3RGBA,int> *v7; // esi
  int v8; // eax
  IColorOperation *v9; // edi
  int v10; // eax
  CDmxElement *v11; // ebx
  S3RGBA *m_pMemory; // edi
  int m_nAllocationCount; // eax
  S3RGBA *v14; // ecx
  int v15; // eax
  CDmxElement **v16; // eax
  const char *v17; // eax
  int nCount; // [esp+Ch] [ebp-18h]
  CDmxElement *modify; // [esp+14h] [ebp-10h]
  CDmxElement *pColorOperaterList; // [esp+18h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-8h]
  bool bOk; // [esp+23h] [ebp-1h]

  v2 = this;
  BeginDMXContext();
  DmxElement = CreateDmxElement(pType: "DmeColorCorrectionOperatorList");
  pColorOperaterList = DmxElement;
  modify = DmxElement;
  CDmxElement::LockForChanges(this: DmxElement, bLock: true);
  v4 = CDmxElement::AddAttribute(this: DmxElement, pAttributeName: "operators");
  v5 = v4;
  if ( v4->m_Type != AT_FIRST_ARRAY_TYPE )
  {
    CDmxAttribute::AllocateDataMemory(this: v4, type: AT_FIRST_ARRAY_TYPE);
    m_pData = v5->m_pData;
    if ( m_pData != nullptr )
    {
      *m_pData = 0;
      m_pData[1] = 0;
      m_pData[2] = 0;
      m_pData[3] = 0;
      m_pData[4] = 0;
    }
  }
  v7 = (CUtlMemory<S3RGBA,int> *)v5->m_pData;
  v8 = 0;
  bOk = true;
  nCount = v2->m_OperationList.m_OpList.m_Size;
  i = 0;
  if ( nCount > 0 )
  {
    while ( 1 )
    {
      v9 = v8 >= 0 && v8 < v2->m_OperationList.m_OpList.m_Size
         ? v2->m_OperationList.m_OpList.m_Memory.m_pMemory[v8]
         : nullptr;
      v10 = v9->ToolID(this: v9);
      v11 = CreateDmxElement(pType: s_pColorCorrectionDmxElementNames[v10]);
      CDmxElement::LockForChanges(this: v11, bLock: true);
      if ( !v9->Serialize(this: v9, a2: v11) )
        break;
      m_pMemory = v7[1].m_pMemory;
      m_nAllocationCount = v7->m_nAllocationCount;
      if ( (int)&m_pMemory->g > m_nAllocationCount )
        CUtlMemory<INetMessage *,int>::Grow(this: v7, num: (int)(&m_pMemory->g - m_nAllocationCount));
      ++v7[1].m_pMemory;
      v14 = v7->m_pMemory;
      v15 = (char *)v7[1].m_pMemory - (char *)m_pMemory - 1;
      v7[1].m_nAllocationCount = (int)v7->m_pMemory;
      if ( v15 > 0 )
        _V_memmove(dest: &v14[(_DWORD)m_pMemory + 1], src: &v14[(_DWORD)m_pMemory], count: 4 * v15);
      v16 = (CDmxElement **)&v7->m_pMemory[(_DWORD)m_pMemory];
      if ( v16 != nullptr )
        *v16 = v11;
      if ( v11 != nullptr )
        CDmxElement::LockForChanges(this: v11, bLock: false);
      if ( ++i >= nCount )
        goto LABEL_24;
      v2 = this;
      v8 = i;
    }
    bOk = false;
    v17 = v9->GetName(this: v9);
    _Warning(a1: "Error serializing color operator %s\n", v17);
    if ( v11 != nullptr )
      CDmxElement::LockForChanges(this: v11, bLock: false);
LABEL_24:
    DmxElement = pColorOperaterList;
  }
  if ( DmxElement != nullptr )
  {
    CDmxElement::LockForChanges(this: DmxElement, bLock: false);
    modify = nullptr;
  }
  if ( bOk )
    SerializeDMX(pFileName: pFullPath, pPathID: "MOD", bTextMode: true, pRoot: DmxElement);
  EndDMXContext(bDecommitMemory: true);
  if ( modify != nullptr )
    CDmxElement::LockForChanges(this: modify, bLock: false);
  return bOk;
}

//------------------------------------------------------------------------------
// Address: 0x100AB960
// Name: public: virtual void CColorCorrectionTools::InstallColorCorrectionUI(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionTools::InstallColorCorrectionUI(CColorCorrectionTools *this, vgui::Panel *parent)
{
  int v2; // eax
  CColorCorrectionUIPanel *v3; // eax

  if ( g_pColorCorrectionUI == nullptr )
  {
    v2 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 12))(a1: v2, a2: "-tools", a3: 0) != 0 )
    {
      v3 = (CColorCorrectionUIPanel *)MemAlloc_Alloc(nSize: 0x30230u);
      if ( v3 != nullptr )
        g_pColorCorrectionUI = CColorCorrectionUIPanel::CColorCorrectionUIPanel(this: v3, parent);
      else
        g_pColorCorrectionUI = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ABA60
// Name: public: CCurvesColorOperation::CCurvesColorOperation(void)
// Source: json
//------------------------------------------------------------------------------
CCurvesColorOperation *__thiscall CCurvesColorOperation::CCurvesColorOperation(CCurvesColorOperation *this)
{
  Vector endpt; // [esp+0h] [ebp-18h] BYREF
  Vector startpt; // [esp+Ch] [ebp-Ch] BYREF

  this->__vftable = (CCurvesColorOperation_vtbl *)&CCurvesColorOperation::`vftable';
  this->m_ControlPoints.m_Memory.m_pMemory = nullptr;
  this->m_ControlPoints.m_Memory.m_nAllocationCount = 0;
  this->m_ControlPoints.m_Memory.m_nGrowSize = 0;
  this->m_ControlPoints.m_Size = 0;
  this->m_ControlPoints.m_pElements = nullptr;
  this->m_ControlPoints.m_pLessContext = nullptr;
  this->m_ControlPoints.m_bNeedsSort = false;
  memset(&startpt, 0, sizeof(startpt));
  endpt.x = 1.0;
  endpt.y = 1.0;
  endpt.z = 0.0;
  CUtlSortVector<Vector,CCurvesColorOperation::CurvesLessFunc>::Insert(this: &this->m_ControlPoints, src: &startpt);
  CUtlSortVector<Vector,CCurvesColorOperation::CurvesLessFunc>::Insert(this: &this->m_ControlPoints, src: &endpt);
  this->m_flBlendFactor = 1.0;
  this->m_nChannelMask = 7;
  this->m_bEnable = true;
  CCurvesColorOperation::UpdateOutColorArray(this);
  _V_strcpy(dest: this->m_pName, src: "Curves");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100ABB30
// Name: public: virtual char const __near * CCurvesColorOperation::GetName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CCurvesColorOperation::GetName(CCurvesColorOperation *this)
{
  return this->m_pName;
}

//------------------------------------------------------------------------------
// Address: 0x100ABB40
// Name: public: virtual void CCurvesColorOperation::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurvesColorOperation::SetName(CCurvesColorOperation *this, const char *pName)
{
  _V_strcpy(dest: this->m_pName, src: pName);
}

//------------------------------------------------------------------------------
// Address: 0x100ABB60
// Name: public: virtual bool CCurvesColorOperation::IsEnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCurvesColorOperation::IsEnabled(CCurvesColorOperation *this)
{
  return this->m_bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x100ABB70
// Name: public: virtual void CCurvesColorOperation::SetEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurvesColorOperation::SetEnabled(CCurvesColorOperation *this, bool bEnable)
{
  this->m_bEnable = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x100ABB80
// Name: public: virtual float CCurvesColorOperation::GetBlendFactor(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCurvesColorOperation::GetBlendFactor(CCurvesColorOperation *this)
{
  return this->m_flBlendFactor;
}

//------------------------------------------------------------------------------
// Address: 0x100ABB90
// Name: public: virtual bool CCurvesColorOperation::Serialize(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCurvesColorOperation::Serialize(CCurvesColorOperation *this, CDmxElement *pElement)
{
  CCurvesColorOperation *v2; // ebx
  CDmxAttribute *v3; // edi
  _DWORD *m_pData; // edi
  CDmxAttribute *v5; // edi
  float *v6; // edi
  CDmxAttribute *v7; // edi
  _BYTE *v8; // eax
  int *p_m_Size; // edi
  CDmxAttribute *v10; // eax
  CDmxAttribute *v11; // esi
  _DWORD *v12; // eax
  CUtlMemory<CVTFTexture::ResourceMemorySection,int> *v13; // esi
  int m_nAllocationCount; // eax
  int *v15; // ebx
  CVTFTexture::ResourceMemorySection *m_pMemory; // edi
  CVTFTexture::ResourceMemorySection *v17; // ecx
  int v18; // eax
  CVTFTexture::ResourceMemorySection *v19; // eax
  bool v20; // zf
  int m_Size; // [esp+10h] [ebp-4h]
  CDmxElement *pElementa; // [esp+1Ch] [ebp+8h]

  v2 = this;
  CDmxElement::SetName(this: pElement, pName: this->m_pName);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v3 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "channelMask");
  CDmxAttribute::AllocateDataMemory(this: v3, type: AT_INT);
  m_pData = v3->m_pData;
  if ( m_pData != nullptr )
    *m_pData = v2->m_nChannelMask;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v5 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "blendFactor");
  CDmxAttribute::AllocateDataMemory(this: v5, type: AT_FLOAT);
  v6 = (float *)v5->m_pData;
  if ( v6 != nullptr )
    *v6 = v2->m_flBlendFactor;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v7 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "enabled");
  CDmxAttribute::AllocateDataMemory(this: v7, type: AT_BOOL);
  v8 = v7->m_pData;
  p_m_Size = nullptr;
  if ( v8 != nullptr )
    *v8 = v2->m_bEnable;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  v10 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "controlPoints");
  v11 = v10;
  if ( v10->m_Type != AT_VECTOR3_ARRAY )
  {
    CDmxAttribute::AllocateDataMemory(this: v10, type: AT_VECTOR3_ARRAY);
    v12 = v11->m_pData;
    if ( v12 != nullptr )
    {
      *v12 = 0;
      v12[1] = 0;
      v12[2] = 0;
      v12[3] = 0;
      v12[4] = 0;
    }
  }
  v13 = (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)v11->m_pData;
  if ( v2->m_ControlPoints.m_Size > 0 )
  {
    pElementa = nullptr;
    m_Size = v2->m_ControlPoints.m_Size;
    while ( 1 )
    {
      m_nAllocationCount = v13->m_nAllocationCount;
      v15 = (int *)((char *)p_m_Size + (unsigned int)v2->m_ControlPoints.m_Memory.m_pMemory);
      m_pMemory = v13[1].m_pMemory;
      if ( (int)&m_pMemory->m_nDataAllocSize + 1 > m_nAllocationCount )
        CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
          this: v13,
          num: (int)&m_pMemory->m_nDataAllocSize - m_nAllocationCount + 1);
      ++v13[1].m_pMemory;
      v17 = v13->m_pMemory;
      v18 = (char *)v13[1].m_pMemory - (char *)m_pMemory - 1;
      v13[1].m_nAllocationCount = (int)v13->m_pMemory;
      if ( v18 > 0 )
        _V_memmove(dest: &v17[(int)m_pMemory + 1], src: &v17[(_DWORD)m_pMemory], count: 12 * v18);
      v19 = &v13->m_pMemory[(_DWORD)m_pMemory];
      if ( v19 != nullptr )
      {
        v19->m_nDataAllocSize = *v15;
        v19->m_nDataLength = v15[1];
        v19->m_pData = (unsigned __int8 *)v15[2];
      }
      p_m_Size = &pElementa->m_Attributes.m_Size;
      v20 = m_Size-- == 1;
      pElementa = (CDmxElement *)((char *)pElementa + 12);
      if ( v20 )
        break;
      v2 = this;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100ABD40
// Name: public: virtual bool CSelectedHSVOperation::Serialize(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSelectedHSVOperation::Serialize(CSelectedHSVOperation *this, CDmxElement *pElement)
{
  CSelectedHSVOperation *v3; // edi
  CDmxAttribute *v4; // esi
  float *m_pData; // esi
  CDmxAttribute *v6; // esi
  _BYTE *v7; // esi
  CDmxAttribute *v8; // eax
  CDmxAttribute *v9; // esi
  _DWORD *v10; // eax
  CUtlMemory<CVTFTexture::ResourceMemorySection,int> *v11; // esi
  Vector *m_pMemory; // ecx
  CVTFTexture::ResourceMemorySection *v13; // edi
  _DWORD *v14; // ecx
  int m_nAllocationCount; // eax
  CVTFTexture::ResourceMemorySection *v16; // edx
  int v17; // eax
  CVTFTexture::ResourceMemorySection *v18; // eax
  bool v19; // zf
  CDmxAttribute *v20; // eax
  CDmxAttribute *v21; // esi
  _DWORD *v22; // eax
  CUtlMemory<CVTFTexture::ResourceMemorySection,int> *v23; // esi
  Vector *v24; // ecx
  CVTFTexture::ResourceMemorySection *v25; // edi
  _DWORD *v26; // ecx
  int v27; // eax
  CVTFTexture::ResourceMemorySection *v28; // edx
  int v29; // eax
  CVTFTexture::ResourceMemorySection *v30; // eax
  CDmxAttribute *v31; // esi
  _DWORD *v32; // esi
  CDmxAttribute *v33; // esi
  _DWORD *v34; // eax
  CDmxAttribute *v35; // esi
  float *v36; // esi
  CDmxAttribute *v37; // esi
  float *v38; // esi
  CDmxAttribute *v39; // esi
  _BYTE *v40; // esi
  CDmxAttribute *v41; // esi
  _BYTE *v42; // esi
  int m_Size; // [esp+Ch] [ebp-Ch]
  _DWORD *v45; // [esp+Ch] [ebp-Ch]
  _DWORD *v46; // [esp+10h] [ebp-8h]
  int v47; // [esp+10h] [ebp-8h]
  CDmxElement *pElementa; // [esp+20h] [ebp+8h]
  CDmxElement *pElementb; // [esp+20h] [ebp+8h]
  CDmxElement *pElementc; // [esp+20h] [ebp+8h]

  v3 = this;
  CDmxElement::SetName(this: pElement, pName: this->m_pName);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v4 = CDmxElement::AddAttribute(this: pElement, pAttributeName: (CDmxAttribute *)"blendFactor");
  CDmxAttribute::AllocateDataMemory(this: v4, type: AT_FLOAT);
  m_pData = (float *)v4->m_pData;
  if ( m_pData != nullptr )
    *m_pData = v3->m_flBlendFactor;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v6 = CDmxElement::AddAttribute(this: pElement, pAttributeName: (CDmxAttribute *)"enabled");
  CDmxAttribute::AllocateDataMemory(this: v6, type: AT_BOOL);
  v7 = v6->m_pData;
  if ( v7 != nullptr )
    *v7 = v3->m_bEnable;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  v8 = CDmxElement::AddAttribute(this: pElement, pAttributeName: (CDmxAttribute *)"selectedRGBs");
  v9 = v8;
  if ( v8->m_Type != AT_VECTOR3_ARRAY )
  {
    CDmxAttribute::AllocateDataMemory(this: v8, type: AT_VECTOR3_ARRAY);
    v10 = v9->m_pData;
    if ( v10 != nullptr )
    {
      *v10 = 0;
      v10[1] = 0;
      v10[2] = 0;
      v10[3] = 0;
      v10[4] = 0;
    }
  }
  v11 = (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)v9->m_pData;
  if ( v3->m_SelectedRGBs.m_Size > 0 )
  {
    pElementa = nullptr;
    m_Size = v3->m_SelectedRGBs.m_Size;
    do
    {
      m_pMemory = v3->m_SelectedRGBs.m_Memory.m_pMemory;
      v13 = v11[1].m_pMemory;
      v14 = (_DWORD *)((int)&m_pMemory->x + (_DWORD)pElementa);
      m_nAllocationCount = v11->m_nAllocationCount;
      v46 = v14;
      if ( (int)&v13->m_nDataAllocSize + 1 > m_nAllocationCount )
      {
        CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
          this: v11,
          num: (int)&v13->m_nDataAllocSize - m_nAllocationCount + 1);
        v14 = v46;
      }
      ++v11[1].m_pMemory;
      v16 = v11->m_pMemory;
      v17 = (char *)v11[1].m_pMemory - (char *)v13 - 1;
      v11[1].m_nAllocationCount = (int)v11->m_pMemory;
      if ( v17 > 0 )
      {
        _V_memmove(dest: &v16[(int)v13 + 1], src: &v16[(_DWORD)v13], count: 12 * v17);
        v14 = v46;
      }
      v18 = &v11->m_pMemory[(_DWORD)v13];
      if ( v18 != nullptr )
      {
        v18->m_nDataAllocSize = *v14;
        v18->m_nDataLength = v14[1];
        v18->m_pData = (unsigned __int8 *)v14[2];
      }
      pElementa = (CDmxElement *)((char *)pElementa + 12);
      v19 = m_Size-- == 1;
      v3 = this;
    }
    while ( !v19 );
  }
  v20 = CDmxElement::AddAttribute(this: pElement, pAttributeName: (CDmxAttribute *)"selectedHSVs");
  v21 = v20;
  if ( v20->m_Type != AT_VECTOR3_ARRAY )
  {
    CDmxAttribute::AllocateDataMemory(this: v20, type: AT_VECTOR3_ARRAY);
    v22 = v21->m_pData;
    if ( v22 != nullptr )
    {
      *v22 = 0;
      v22[1] = 0;
      v22[2] = 0;
      v22[3] = 0;
      v22[4] = 0;
    }
  }
  v23 = (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)v21->m_pData;
  if ( v3->m_SelectedHSVs.m_Size > 0 )
  {
    pElementb = nullptr;
    v47 = v3->m_SelectedHSVs.m_Size;
    do
    {
      v24 = v3->m_SelectedHSVs.m_Memory.m_pMemory;
      v25 = v23[1].m_pMemory;
      v26 = (_DWORD *)((int)&v24->x + (_DWORD)pElementb);
      v27 = v23->m_nAllocationCount;
      v45 = v26;
      if ( (int)&v25->m_nDataAllocSize + 1 > v27 )
      {
        CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
          this: v23,
          num: (int)&v25->m_nDataAllocSize - v27 + 1);
        v26 = v45;
      }
      ++v23[1].m_pMemory;
      v28 = v23->m_pMemory;
      v29 = (char *)v23[1].m_pMemory - (char *)v25 - 1;
      v23[1].m_nAllocationCount = (int)v23->m_pMemory;
      if ( v29 > 0 )
      {
        _V_memmove(dest: &v28[(int)v25 + 1], src: &v28[(_DWORD)v25], count: 12 * v29);
        v26 = v45;
      }
      v30 = &v23->m_pMemory[(_DWORD)v25];
      if ( v30 != nullptr )
      {
        v30->m_nDataAllocSize = *v26;
        v30->m_nDataLength = v26[1];
        v30->m_pData = (unsigned __int8 *)v26[2];
      }
      pElementb = (CDmxElement *)((char *)pElementb + 12);
      v19 = v47-- == 1;
      v3 = this;
    }
    while ( !v19 );
  }
  pElementc = (CDmxElement *)v3->m_SelectionMethod;
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v31 = CDmxElement::AddAttribute(this: pElement, pAttributeName: (CDmxAttribute *)"selectionMethod");
  CDmxAttribute::AllocateDataMemory(this: v31, type: AT_INT);
  v32 = v31->m_pData;
  if ( v32 != nullptr )
    *v32 = pElementc;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v33 = CDmxElement::AddAttribute(this: pElement, pAttributeName: (CDmxAttribute *)"deltaHSV");
  CDmxAttribute::AllocateDataMemory(this: v33, type: AT_VECTOR3);
  v34 = v33->m_pData;
  if ( v34 != nullptr )
  {
    *v34 = LODWORD(v3->m_DeltaHSV.x);
    v34[1] = LODWORD(v3->m_DeltaHSV.y);
    v34[2] = LODWORD(v3->m_DeltaHSV.z);
  }
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v35 = CDmxElement::AddAttribute(this: pElement, pAttributeName: (CDmxAttribute *)"tolerance");
  CDmxAttribute::AllocateDataMemory(this: v35, type: AT_FLOAT);
  v36 = (float *)v35->m_pData;
  if ( v36 != nullptr )
    *v36 = v3->m_Tolerance;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v37 = CDmxElement::AddAttribute(this: pElement, pAttributeName: (CDmxAttribute *)"fuzziness");
  CDmxAttribute::AllocateDataMemory(this: v37, type: AT_FLOAT);
  v38 = (float *)v37->m_pData;
  if ( v38 != nullptr )
    *v38 = v3->m_Fuzziness;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v39 = CDmxElement::AddAttribute(this: pElement, pAttributeName: (CDmxAttribute *)"colorize");
  CDmxAttribute::AllocateDataMemory(this: v39, type: AT_BOOL);
  v40 = v39->m_pData;
  if ( v40 != nullptr )
    *v40 = v3->m_bColorize;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v41 = CDmxElement::AddAttribute(this: pElement, pAttributeName: (CDmxAttribute *)"invertSelection");
  CDmxAttribute::AllocateDataMemory(this: v41, type: AT_BOOL);
  v42 = v41->m_pData;
  if ( v42 != nullptr )
    *v42 = v3->m_bInvertSelection;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100AC0F0
// Name: public: virtual void CFullScreenSelectionPanel::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CFullScreenSelectionPanel::OnCursorMoved(
        CFullScreenSelectionPanel *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        int x,
        KeyValues *y)
{
  int v6; // esi
  CSelectedHSVOperation *m_pOp; // eax
  CSelectedHSVOperation *v8; // edi
  Vector hsv; // [esp+4h] [ebp-1Ch] BYREF
  Vector rgb; // [esp+10h] [ebp-10h] BYREF
  BGRA8888_t pixelValue; // [esp+1Ch] [ebp-4h]

  if ( this->m_bMouseDown )
  {
    v6 = ((int (__thiscall *)(IMaterialSystem *, int, int))materials->GetRenderContext)(a1: materials, a2, a3);
    if ( v6 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
    (*(void (__thiscall **)(int, int, KeyValues *, int, int))(*(_DWORD *)v6 + 52))(a1: v6, a2: x, a3: y, a4: 1, a5: 1);
    if ( !g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
      && !g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL) )
    {
      m_pOp = this->m_pOp;
      m_pOp->m_SelectedRGBs.m_Size = 0;
      m_pOp->m_SelectedHSVs.m_Size = 0;
    }
    v8 = this->m_pOp;
    rgb.x = (float)pixelValue.r * 0.0039215689;
    rgb.y = (float)pixelValue.g * 0.0039215689;
    rgb.z = (float)pixelValue.b * 0.0039215689;
    RGBtoHSV(&rgb, &hsv);
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: &v8->m_SelectedRGBs,
      elem: v8->m_SelectedRGBs.m_Size,
      src: &rgb);
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: &v8->m_SelectedHSVs,
      elem: v8->m_SelectedHSVs.m_Size,
      src: &hsv);
    colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
  }
  CColorBalanceUIPanel::ReadUncorrectedImage((vgui::TreeView *)this, itemIndex: x, msg: y);
}

//------------------------------------------------------------------------------
// Address: 0x100AC230
// Name: public: virtual void CUncorrectedImagePanel::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUncorrectedImagePanel::OnCursorMoved(CUncorrectedImagePanel *this, int x, int y)
{
  bool v4; // bl
  int m_nWidth; // edi
  int v6; // ecx
  float v7; // xmm0_4
  int v8; // ecx
  int m_nHeight; // eax
  BGRA8888_t *v10; // eax
  CSelectedHSVOperation *m_pHSVOp; // ecx
  unsigned __int8 r; // cl
  unsigned __int8 g; // dl
  unsigned __int8 b; // al
  CSelectedHSVOperation *v15; // ecx
  CSelectedHSVOperation *v16; // esi
  color24 v17; // [esp-Ch] [ebp-38h]
  Vector hsv; // [esp+Ch] [ebp-20h] BYREF
  Vector rgb; // [esp+18h] [ebp-14h] BYREF
  int sy; // [esp+24h] [ebp-8h] BYREF
  int sx; // [esp+28h] [ebp-4h] BYREF

  if ( this->m_bMouseDown )
  {
    v4 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
      || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL);
    vgui::Panel::GetSize(this, wide: &sx, tall: &sy);
    m_nWidth = this->m_nWidth;
    v6 = (int)(float)((float)((float)((float)this->m_TextureSubRect.width * (float)x) / (float)sx)
                    + (float)this->m_TextureSubRect.x);
    v7 = (float)((float)((float)this->m_TextureSubRect.height * (float)y) / (float)sy) + (float)this->m_TextureSubRect.y;
    if ( v6 >= m_nWidth )
      v6 = this->m_nWidth;
    v8 = v6 < 0 ? 0 : v6;
    m_nHeight = this->m_nHeight;
    if ( (int)v7 < m_nHeight )
      m_nHeight = (int)v7;
    v10 = &this->m_pImageBuffer[v8 + m_nWidth * (m_nHeight < 0 ? 0 : m_nHeight)];
    if ( !v4 )
    {
      m_pHSVOp = this->m_pHSVOp;
      m_pHSVOp->m_SelectedRGBs.m_Size = 0;
      m_pHSVOp->m_SelectedHSVs.m_Size = 0;
    }
    r = v10->r;
    g = v10->g;
    b = v10->b;
    LOBYTE(x) = r;
    v15 = this->m_pHSVOp;
    BYTE1(x) = g;
    *(_WORD *)&v17.r = x;
    v17.b = b;
    CColorOperationList::Apply(this: v15->m_pOpList, in: v17, out: (color24 *)&x, pFinalOp: v15);
    v16 = this->m_pHSVOp;
    rgb.x = (float)(unsigned __int8)x * 0.0039215689;
    rgb.y = (float)BYTE1(x) * 0.0039215689;
    rgb.z = (float)BYTE2(x) * 0.0039215689;
    RGBtoHSV(&rgb, &hsv);
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: &v16->m_SelectedRGBs,
      elem: v16->m_SelectedRGBs.m_Size,
      src: &rgb);
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: &v16->m_SelectedHSVs,
      elem: v16->m_SelectedHSVs.m_Size,
      src: &hsv);
    colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AC400
// Name: private: void CSelectedHSVUIPanel::PickColorFromTextEntry(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectedHSVUIPanel::PickColorFromTextEntry(CSelectedHSVUIPanel *this, bool bRGB)
{
  unsigned __int8 v3; // bl
  int v4; // eax
  vgui::TextEntry *m_pColorEntry3; // ecx
  unsigned __int8 v6; // al
  CSelectedHSVOperation *m_pHSVOperation; // ecx
  CSelectedHSVOperation *v8; // esi
  Vector *p_hsv; // eax
  Vector hsv; // [esp+8h] [ebp-1Ch] BYREF
  Vector rgb; // [esp+14h] [ebp-10h] BYREF
  int g; // [esp+20h] [ebp-4h]

  v3 = this->m_pColorEntry1->GetValueAsInt(this: this->m_pColorEntry1);
  v4 = this->m_pColorEntry2->GetValueAsInt(this: this->m_pColorEntry2);
  m_pColorEntry3 = this->m_pColorEntry3;
  g = v4;
  v6 = m_pColorEntry3->GetValueAsInt(this: m_pColorEntry3);
  m_pHSVOperation = this->m_pHSVOperation;
  m_pHSVOperation->m_SelectedRGBs.m_Size = 0;
  m_pHSVOperation->m_SelectedHSVs.m_Size = 0;
  v8 = this->m_pHSVOperation;
  rgb.x = (float)v3 * 0.0039215689;
  rgb.y = (float)(unsigned __int8)g * 0.0039215689;
  rgb.z = (float)v6 * 0.0039215689;
  if ( bRGB )
  {
    RGBtoHSV(&rgb, &hsv);
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: &v8->m_SelectedRGBs,
      elem: v8->m_SelectedRGBs.m_Size,
      src: &rgb);
    p_hsv = &hsv;
  }
  else
  {
    HSVtoRGB(hsv: &rgb, rgb: &hsv);
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: &v8->m_SelectedRGBs,
      elem: v8->m_SelectedRGBs.m_Size,
      src: &hsv);
    p_hsv = &rgb;
  }
  CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
    this: &v8->m_SelectedHSVs,
    elem: v8->m_SelectedHSVs.m_Size,
    src: p_hsv);
  colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
}

//------------------------------------------------------------------------------
// Address: 0x100AC500
// Name: public: virtual bool CColorBalanceOperation::Serialize(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CColorBalanceOperation::Serialize(CColorBalanceOperation *this, CDmxElement *pElement)
{
  CDmxAttribute *v3; // edi
  float *m_pData; // eax
  CDmxAttribute *v5; // ebx
  _BYTE *v6; // ebx
  CDmxAttribute *v7; // ebx
  _BYTE *v8; // ebx
  CDmxAttribute *v9; // ebx
  CDmxAttribute *v10; // edi
  CDmxAttribute *v11; // esi
  _DWORD *v12; // eax
  _DWORD *v13; // eax
  CUtlMemory<S3RGBA,int> *v14; // ebx
  _DWORD *v15; // eax
  CUtlMemory<S3RGBA,int> *v16; // edi
  CUtlMemory<S3RGBA,int> *v17; // edx
  S3RGBA *m_pMemory; // esi
  int m_nAllocationCount; // eax
  S3RGBA *v20; // ecx
  int v21; // eax
  float *v22; // esi
  S3RGBA *v23; // esi
  int v24; // eax
  S3RGBA *v25; // ecx
  int v26; // eax
  float *v27; // esi
  S3RGBA *v28; // esi
  int v29; // eax
  S3RGBA *v30; // ecx
  int v31; // eax
  float *v32; // esi
  int i; // [esp+Ch] [ebp-8h]
  float *m_MagentaGreenBalance; // [esp+10h] [ebp-4h]
  CUtlMemory<S3RGBA,int> *cyanRedBalance; // [esp+1Ch] [ebp+8h]

  CDmxElement::SetName(this: pElement, pName: this->m_pName);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v3 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "blendFactor");
  CDmxAttribute::AllocateDataMemory(this: v3, type: AT_FLOAT);
  m_pData = (float *)v3->m_pData;
  if ( m_pData != nullptr )
    *m_pData = this->m_flBlendFactor;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v5 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "enabled");
  CDmxAttribute::AllocateDataMemory(this: v5, type: AT_BOOL);
  v6 = v5->m_pData;
  if ( v6 != nullptr )
    *v6 = this->m_bEnable;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v7 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "preserveLuminosity");
  CDmxAttribute::AllocateDataMemory(this: v7, type: AT_BOOL);
  v8 = v7->m_pData;
  if ( v8 != nullptr )
    *v8 = this->m_PreserveLuminosity;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  v9 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "cyanRedBalance");
  v10 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "magentaGreenBalance");
  v11 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "yellowBlueBalance");
  if ( v9->m_Type == AT_FLOAT_ARRAY )
  {
    cyanRedBalance = (CUtlMemory<S3RGBA,int> *)v9->m_pData;
  }
  else
  {
    CDmxAttribute::AllocateDataMemory(this: v9, type: AT_FLOAT_ARRAY);
    v12 = v9->m_pData;
    if ( v12 != nullptr )
    {
      *v12 = 0;
      v12[1] = 0;
      v12[2] = 0;
      v12[3] = 0;
      v12[4] = 0;
    }
    cyanRedBalance = (CUtlMemory<S3RGBA,int> *)v9->m_pData;
  }
  if ( v10->m_Type != AT_FLOAT_ARRAY )
  {
    CDmxAttribute::AllocateDataMemory(this: v10, type: AT_FLOAT_ARRAY);
    v13 = v10->m_pData;
    if ( v13 != nullptr )
    {
      *v13 = 0;
      v13[1] = 0;
      v13[2] = 0;
      v13[3] = 0;
      v13[4] = 0;
    }
  }
  v14 = (CUtlMemory<S3RGBA,int> *)v10->m_pData;
  if ( v11->m_Type != AT_FLOAT_ARRAY )
  {
    CDmxAttribute::AllocateDataMemory(this: v11, type: AT_FLOAT_ARRAY);
    v15 = v11->m_pData;
    if ( v15 != nullptr )
    {
      *v15 = 0;
      v15[1] = 0;
      v15[2] = 0;
      v15[3] = 0;
      v15[4] = 0;
    }
  }
  v16 = (CUtlMemory<S3RGBA,int> *)v11->m_pData;
  m_MagentaGreenBalance = this->m_MagentaGreenBalance;
  for ( i = 3; i != 0; --i )
  {
    v17 = cyanRedBalance;
    m_pMemory = cyanRedBalance[1].m_pMemory;
    m_nAllocationCount = cyanRedBalance->m_nAllocationCount;
    if ( (int)&m_pMemory->g > m_nAllocationCount )
    {
      CUtlMemory<INetMessage *,int>::Grow(this: cyanRedBalance, num: (int)(&m_pMemory->g - m_nAllocationCount));
      v17 = cyanRedBalance;
    }
    ++v17[1].m_pMemory;
    v20 = v17->m_pMemory;
    v21 = (char *)v17[1].m_pMemory - (char *)m_pMemory - 1;
    v17[1].m_nAllocationCount = (int)v17->m_pMemory;
    if ( v21 > 0 )
    {
      _V_memmove(dest: &v20[(_DWORD)m_pMemory + 1], src: &v20[(_DWORD)m_pMemory], count: 4 * v21);
      v17 = cyanRedBalance;
    }
    v22 = (float *)&v17->m_pMemory[(_DWORD)m_pMemory];
    if ( v22 != nullptr )
      *v22 = *(m_MagentaGreenBalance - 3);
    v23 = v14[1].m_pMemory;
    v24 = v14->m_nAllocationCount;
    if ( (int)&v23->g > v24 )
      CUtlMemory<INetMessage *,int>::Grow(this: v14, num: (int)(&v23->g - v24));
    ++v14[1].m_pMemory;
    v25 = v14->m_pMemory;
    v26 = (char *)v14[1].m_pMemory - (char *)v23 - 1;
    v14[1].m_nAllocationCount = (int)v14->m_pMemory;
    if ( v26 > 0 )
      _V_memmove(dest: &v25[(_DWORD)v23 + 1], src: &v25[(_DWORD)v23], count: 4 * v26);
    v27 = (float *)&v14->m_pMemory[(_DWORD)v23];
    if ( v27 != nullptr )
      *v27 = *m_MagentaGreenBalance;
    v28 = v16[1].m_pMemory;
    v29 = v16->m_nAllocationCount;
    if ( (int)&v28->g > v29 )
      CUtlMemory<INetMessage *,int>::Grow(this: v16, num: (int)(&v28->g - v29));
    ++v16[1].m_pMemory;
    v30 = v16->m_pMemory;
    v31 = (char *)v16[1].m_pMemory - (char *)v28 - 1;
    v16[1].m_nAllocationCount = (int)v16->m_pMemory;
    if ( v31 > 0 )
      _V_memmove(dest: &v30[(_DWORD)v28 + 1], src: &v30[(_DWORD)v28], count: 4 * v31);
    v32 = (float *)&v16->m_pMemory[(_DWORD)v28];
    if ( v32 != nullptr )
      *v32 = m_MagentaGreenBalance[3];
    ++m_MagentaGreenBalance;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100AC7C0
// Name: CreateColorOp
// Source: json
//------------------------------------------------------------------------------
CCurvesColorOperation *__usercall CreateColorOp@<eax>(
        ColorCorrectionTool_t nToolId@<eax>,
        CColorOperationList *pOpList@<esi>)
{
  CColorBalanceOperation *v2; // eax
  CCurvesColorOperation *result; // eax
  CCurvesColorOperation *v4; // eax
  CColorLookupOperation *v5; // eax
  CLevelsColorOperation *v6; // eax
  CSelectedHSVOperation *v7; // eax

  switch ( nToolId )
  {
    case CC_TOOL_CURVES:
      v4 = (CCurvesColorOperation *)MemAlloc_Alloc(nSize: 0x52Cu);
      if ( v4 == nullptr )
        goto LABEL_12;
      result = CCurvesColorOperation::CCurvesColorOperation(this: v4);
      break;
    case CC_TOOL_LEVELS:
      v6 = (CLevelsColorOperation *)MemAlloc_Alloc(nSize: 0x528u);
      if ( v6 == nullptr )
        goto LABEL_12;
      result = (CCurvesColorOperation *)CLevelsColorOperation::CLevelsColorOperation(this: v6, pList: pOpList);
      break;
    case CC_TOOL_SELECTED_HSV:
      v7 = (CSelectedHSVOperation *)MemAlloc_Alloc(nSize: 0x154u);
      if ( v7 == nullptr )
        goto LABEL_12;
      result = (CCurvesColorOperation *)CSelectedHSVOperation::CSelectedHSVOperation(this: v7, pList: pOpList);
      break;
    case CC_TOOL_LOOKUP:
      v5 = (CColorLookupOperation *)MemAlloc_Alloc(nSize: 0x218u);
      if ( v5 == nullptr )
        goto LABEL_12;
      result = (CCurvesColorOperation *)CColorLookupOperation::CColorLookupOperation(this: v5);
      break;
    case CC_TOOL_BALANCE:
      v2 = (CColorBalanceOperation *)MemAlloc_Alloc(nSize: 0x1C34u);
      if ( v2 == nullptr )
        goto LABEL_12;
      result = (CCurvesColorOperation *)CColorBalanceOperation::CColorBalanceOperation(this: v2);
      break;
    default:
LABEL_12:
      result = nullptr;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AC870
// Name: public: virtual void CNewOperationDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewOperationDialog::OnCommand(CNewOperationDialog *this, const char *command)
{
  int ActiveItem; // eax
  IColorOperation *ColorOp; // esi
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  char buf[256]; // [esp+8h] [ebp-100h] BYREF

  if ( _V_stricmp(s1: command, s2: "Create") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "Cancel") != 0 )
      return;
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
    {
      v6 = KeyValues::KeyValues(this: v7, setName: "Command", firstKey: "Command", firstValue: "NewCancel");
      goto LABEL_11;
    }
    goto LABEL_10;
  }
  ActiveItem = vgui::ComboBox::GetActiveItem(this: this->m_pOperationType);
  ColorOp = CreateColorOp(nToolId: (ColorCorrectionTool_t)(ActiveItem + 1), pOpList: this->m_pOpList);
  if ( this->m_pName->GetTextLength(this: this->m_pName) > 0 )
  {
    this->m_pName->GetText_2(this: this->m_pName, a2: buf, a3: 256);
    ColorOp->SetName(this: ColorOp, a2: buf);
  }
  CColorOperationList::AddOperation(this: this->m_pOpList, pOp: ColorOp);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 == nullptr )
  {
LABEL_10:
    v6 = nullptr;
    goto LABEL_11;
  }
  v6 = KeyValues::KeyValues(this: v5, setName: "Command", firstKey: "Command", firstValue: "NewComplete");
LABEL_11:
  this->PostActionSignal(this, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x100AC960
// Name: public: virtual bool CColorOperationListPanel::OnWriteFileToDisk(char const __near *,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CColorOperationListPanel::OnWriteFileToDisk(
        CColorOperationListPanel *this,
        const char *pFileName,
        const char *pFileFormat,
        KeyValues *pContextKeyValues)
{
  bool result; // al
  char *v6; // eax
  unsigned __int8 *v7; // esi
  int v8; // eax
  char pRawPath[260]; // [esp+Ch] [ebp-104h] BYREF

  result = CColorOperationListPanel::SaveVCCFile(
             this: (CColorOperationListPanel *)((char *)this - 380),
             pFullPath: pFileName);
  if ( result )
  {
    CUtlString::operator=(this: (CUtlString *)&this->_actionSignalTargetDar.m_Size, src: pFileName);
    ComputeModFilename(pContentFileName: pFileName, pBuf: pRawPath, nBufLen: 0x104u);
    v6 = V_stristr(pStr: pRawPath, pSearch: "\\materialsrc\\");
    if ( v6 != nullptr )
    {
      v7 = (unsigned __int8 *)(v6 + 12);
      v8 = _V_strlen(str: v6 + 12);
      memmove(dst: v7 - 2, src: v7, count: v8 + 1);
    }
    V_SetExtension(path: pRawPath, extension: ".raw", pathStringLength: 260);
    return CColorOperationListPanel::SaveRawFile(
             this: (CColorOperationListPanel *)((char *)this - 380),
             pFullPath: pRawPath);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100ACA10
// Name: private: virtual void CColorOperationListPanel::OnLaunchOperation(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorOperationListPanel::OnLaunchOperation(CColorOperationListPanel *this, int item)
{
  if ( item >= 0 && item < this->m_OperationList.m_OpList.m_Size )
    CColorOperationListPanel::LaunchOperationPanel(this, pOp: this->m_OperationList.m_OpList.m_Memory.m_pMemory[item]);
  else
    CColorOperationListPanel::LaunchOperationPanel(this, pOp: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100ACA50
// Name: private: virtual void CColorOperationListPanel::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorOperationListPanel::OnMouseDoublePressed(CColorOperationListPanel *this, const char *code)
{
  int v3; // eax

  CBaseServer::RemoveClientFromGame(this, panelName: code);
  if ( code == (const char *)107 )
  {
    v3 = this->m_pOperationListPanel->GetSelectedItem(this: this->m_pOperationListPanel, a2: 0);
    if ( v3 >= 0 && v3 < this->m_OperationList.m_OpList.m_Size )
      CColorOperationListPanel::LaunchOperationPanel(this, pOp: this->m_OperationList.m_OpList.m_Memory.m_pMemory[v3]);
    else
      CColorOperationListPanel::LaunchOperationPanel(this, pOp: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ACAB0
// Name: private: virtual void CColorOperationListPanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorOperationListPanel::OnKeyCodeTyped(CColorOperationListPanel *this, ButtonCode_t code)
{
  int v3; // eax

  if ( code == KEY_ENTER )
  {
    v3 = this->m_pOperationListPanel->GetSelectedItem(this: this->m_pOperationListPanel, a2: 0);
    if ( v3 >= 0 && v3 < this->m_OperationList.m_OpList.m_Size )
    {
      CColorOperationListPanel::LaunchOperationPanel(this, pOp: this->m_OperationList.m_OpList.m_Memory.m_pMemory[v3]);
      vgui::EditablePanel::OnKeyCodeTyped(this, code: KEY_ENTER);
    }
    else
    {
      CColorOperationListPanel::LaunchOperationPanel(this, pOp: nullptr);
      vgui::EditablePanel::OnKeyCodeTyped(this, code: KEY_ENTER);
    }
  }
  else
  {
    if ( code == KEY_ESCAPE )
      ShowHideColorCorrectionUI();
    vgui::EditablePanel::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ACC60
// Name: public: virtual bool CCurvesColorOperation::Unserialize(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCurvesColorOperation::Unserialize(CCurvesColorOperation *this, CDmxElement *pElement)
{
  CCurvesColorOperation *v2; // esi
  const char *Name; // eax
  const CDmxAttribute *Attribute; // eax
  int *m_pData; // eax
  const CDmxAttribute *v6; // eax
  int *v7; // eax
  const CDmxAttribute *v8; // eax
  char *v9; // eax
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *v10; // edi
  int v11; // esi
  int m_Size; // ebx

  v2 = this;
  Name = CDmxElement::GetName(this: pElement);
  V_strncpy(pDest: v2->m_pName, pSrc: Name, maxLen: 256);
  Attribute = CDmxElement::GetAttribute(this: pElement, pAttributeName: "channelMask");
  if ( Attribute != nullptr )
  {
    if ( Attribute->m_Type == AT_INT )
    {
      m_pData = (int *)Attribute->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<int>'::`4'::defaultValue = 0;
      m_pData = &`CDmxAttribute::GetValue<int>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<int>'::`4'::defaultValue = 0;
    m_pData = &`CDmxElement::GetValue<int>'::`4'::defaultValue;
  }
  v2->m_nChannelMask = *m_pData;
  v6 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "blendFactor");
  if ( v6 != nullptr )
  {
    if ( v6->m_Type == AT_FLOAT )
    {
      v7 = (int *)v6->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
      v7 = &`CDmxAttribute::GetValue<float>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
    v7 = &`CDmxElement::GetValue<float>'::`4'::defaultValue;
  }
  v2->m_flBlendFactor = *(float *)v7;
  v8 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "enabled");
  if ( v8 != nullptr )
  {
    if ( v8->m_Type == AT_BOOL )
    {
      v9 = (char *)v8->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<bool>'::`4'::defaultValue = 0;
      v9 = &`CDmxAttribute::GetValue<bool>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<bool>'::`4'::defaultValue = 0;
    v9 = &`CDmxElement::GetValue<bool>'::`4'::defaultValue;
  }
  v2->m_bEnable = *v9;
  v10 = CDmxElement::GetArray<Vector>(this: pElement, pAttributeName: "controlPoints");
  if ( v10->m_Size > 0 )
  {
    v11 = 0;
    m_Size = v10->m_Size;
    do
    {
      CUtlSortVector<Vector,CCurvesColorOperation::CurvesLessFunc>::Insert(
        this: &this->m_ControlPoints,
        src: &v10->m_Memory.m_pMemory[v11++]);
      --m_Size;
    }
    while ( m_Size != 0 );
    v2 = this;
  }
  CCurvesColorOperation::UpdateOutColorArray(this: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100ACD90
// Name: public: virtual void CSelectedHSVOperation::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectedHSVOperation::Release(CSelectedHSVOperation *this)
{
  if ( this != nullptr )
  {
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_SelectedHSVs);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_SelectedRGBs);
    free(pMem: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ACDC0
// Name: public: virtual bool CSelectedHSVOperation::Unserialize(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSelectedHSVOperation::Unserialize(CSelectedHSVOperation *this, CDmxElement *pElement)
{
  CDmxElement *v2; // edi
  CSelectedHSVOperation *v3; // esi
  const char *Name; // eax
  const CDmxAttribute *Attribute; // eax
  int *m_pData; // eax
  const CDmxAttribute *v7; // eax
  char *v8; // eax
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *v9; // ecx
  int v10; // edi
  int m_nAllocationCount; // eax
  _DWORD *v12; // ebx
  Vector *m_pMemory; // ecx
  int v14; // eax
  _DWORD *p_x; // eax
  const CDmxAttribute *v16; // eax
  int v17; // edi
  int v18; // eax
  _DWORD *v19; // ebx
  Vector *v20; // ecx
  int v21; // eax
  _DWORD *v22; // eax
  const CDmxAttribute *v23; // eax
  int *v24; // eax
  const CDmxAttribute *v25; // eax
  float *v26; // eax
  const CDmxAttribute *v27; // eax
  int *v28; // eax
  const CDmxAttribute *v29; // eax
  int *v30; // eax
  const CDmxAttribute *v31; // eax
  char *v32; // eax
  const CDmxAttribute *v33; // eax
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *selectedRGBs; // [esp+10h] [ebp-Ch]
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *selectedRGBsa; // [esp+10h] [ebp-Ch]
  int m_Size; // [esp+14h] [ebp-8h]
  int v39; // [esp+14h] [ebp-8h]
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *selectedHSVs; // [esp+18h] [ebp-4h]
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *selectedHSVsa; // [esp+18h] [ebp-4h]

  v2 = pElement;
  v3 = this;
  Name = CDmxElement::GetName(this: pElement);
  V_strncpy(pDest: v3->m_pName, pSrc: Name, maxLen: 256);
  Attribute = CDmxElement::GetAttribute(this: pElement, pAttributeName: "blendFactor");
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
  v3->m_flBlendFactor = *(float *)m_pData;
  v7 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "enabled");
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
  v3->m_bEnable = *v8;
  v9 = CDmxElement::GetArray<Vector>(this: pElement, pAttributeName: "selectedRGBs");
  selectedRGBs = v9;
  if ( v9->m_Size > 0 )
  {
    selectedHSVs = nullptr;
    m_Size = v9->m_Size;
    while ( 1 )
    {
      v10 = v3->m_SelectedRGBs.m_Size;
      m_nAllocationCount = v3->m_SelectedRGBs.m_Memory.m_nAllocationCount;
      v12 = (Vector **)((char *)&selectedHSVs->m_Memory.m_pMemory + (unsigned int)v9->m_Memory.m_pMemory);
      if ( v10 + 1 > m_nAllocationCount )
        CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
          this: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&v3->m_SelectedRGBs,
          num: v10 - m_nAllocationCount + 1);
      ++v3->m_SelectedRGBs.m_Size;
      m_pMemory = v3->m_SelectedRGBs.m_Memory.m_pMemory;
      v14 = v3->m_SelectedRGBs.m_Size - v10 - 1;
      v3->m_SelectedRGBs.m_pElements = m_pMemory;
      if ( v14 > 0 )
        _V_memmove(dest: &m_pMemory[v10 + 1], src: &m_pMemory[v10], count: 12 * v14);
      p_x = (_DWORD *)&v3->m_SelectedRGBs.m_Memory.m_pMemory[v10].x;
      if ( p_x != nullptr )
      {
        *p_x = *v12;
        p_x[1] = v12[1];
        p_x[2] = v12[2];
      }
      selectedHSVs = (const CUtlVector<Vector,CUtlMemory<Vector,int> > *)((char *)selectedHSVs + 12);
      if ( --m_Size == 0 )
        break;
      v9 = selectedRGBs;
    }
    v2 = pElement;
  }
  v16 = CDmxElement::GetAttribute(this: v2, pAttributeName: "selectedHSVs");
  if ( v16 != nullptr )
  {
    if ( v16->m_Type == AT_VECTOR3_ARRAY )
    {
      selectedHSVsa = (const CUtlVector<Vector,CUtlMemory<Vector,int> > *)v16->m_pData;
    }
    else
    {
      if ( (`CDmxAttribute::GetArray<Vector>'::`4'::`local static guard' & 1) == 0 )
      {
        `CDmxAttribute::GetArray<Vector>'::`4'::`local static guard' |= 1u;
        `CDmxAttribute::GetArray<Vector>'::`4'::defaultArray.m_Memory.m_pMemory = nullptr;
        `CDmxAttribute::GetArray<Vector>'::`4'::defaultArray.m_Memory.m_nAllocationCount = 0;
        `CDmxAttribute::GetArray<Vector>'::`4'::defaultArray.m_Memory.m_nGrowSize = 0;
        `CDmxAttribute::GetArray<Vector>'::`4'::defaultArray.m_Size = 0;
        `CDmxAttribute::GetArray<Vector>'::`4'::defaultArray.m_pElements = nullptr;
        atexit(func: `CDmxAttribute::GetArray<Vector>'::`4'::`dynamic atexit destructor for 'defaultArray'');
      }
      selectedHSVsa = &`CDmxAttribute::GetArray<Vector>'::`4'::defaultArray;
    }
  }
  else
  {
    if ( (`CDmxElement::GetArray<Vector>'::`4'::`local static guard' & 1) == 0 )
    {
      `CDmxElement::GetArray<Vector>'::`4'::`local static guard' |= 1u;
      `CDmxElement::GetArray<Vector>'::`4'::defaultValue.m_Memory.m_pMemory = nullptr;
      `CDmxElement::GetArray<Vector>'::`4'::defaultValue.m_Memory.m_nAllocationCount = 0;
      `CDmxElement::GetArray<Vector>'::`4'::defaultValue.m_Memory.m_nGrowSize = 0;
      `CDmxElement::GetArray<Vector>'::`4'::defaultValue.m_Size = 0;
      `CDmxElement::GetArray<Vector>'::`4'::defaultValue.m_pElements = nullptr;
      atexit(func: `CDmxElement::GetArray<Vector>'::`4'::`dynamic atexit destructor for 'defaultValue'');
    }
    selectedHSVsa = &`CDmxElement::GetArray<Vector>'::`4'::defaultValue;
  }
  if ( selectedHSVsa->m_Size > 0 )
  {
    v39 = 0;
    selectedRGBsa = (const CUtlVector<Vector,CUtlMemory<Vector,int> > *)selectedHSVsa->m_Size;
    do
    {
      v17 = v3->m_SelectedHSVs.m_Size;
      v18 = v3->m_SelectedHSVs.m_Memory.m_nAllocationCount;
      v19 = (_DWORD *)&selectedHSVsa->m_Memory.m_pMemory[v39].x;
      if ( v17 + 1 > v18 )
        CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
          this: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&v3->m_SelectedHSVs,
          num: v17 - v18 + 1);
      ++v3->m_SelectedHSVs.m_Size;
      v20 = v3->m_SelectedHSVs.m_Memory.m_pMemory;
      v21 = v3->m_SelectedHSVs.m_Size - v17 - 1;
      v3->m_SelectedHSVs.m_pElements = v20;
      if ( v21 > 0 )
        _V_memmove(dest: &v20[v17 + 1], src: &v20[v17], count: 12 * v21);
      v22 = (_DWORD *)&v3->m_SelectedHSVs.m_Memory.m_pMemory[v17].x;
      if ( v22 != nullptr )
      {
        *v22 = *v19;
        v22[1] = v19[1];
        v22[2] = v19[2];
      }
      ++v39;
      selectedRGBsa = (const CUtlVector<Vector,CUtlMemory<Vector,int> > *)((char *)selectedRGBsa - 1);
    }
    while ( selectedRGBsa != nullptr );
    v2 = pElement;
    v3 = this;
  }
  v23 = CDmxElement::GetAttribute(this: v2, pAttributeName: "selectionMethod");
  if ( v23 != nullptr )
  {
    if ( v23->m_Type == AT_INT )
    {
      v24 = (int *)v23->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<int>'::`4'::defaultValue = 0;
      v24 = &`CDmxAttribute::GetValue<int>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<int>'::`4'::defaultValue = 0;
    v24 = &`CDmxElement::GetValue<int>'::`4'::defaultValue;
  }
  v3->m_SelectionMethod = *v24;
  v25 = CDmxElement::GetAttribute(this: v2, pAttributeName: "deltaHSV");
  if ( v25 != nullptr )
  {
    if ( v25->m_Type == AT_VECTOR3 )
    {
      v26 = (float *)v25->m_pData;
    }
    else
    {
      if ( (`CDmxAttribute::GetValue<Vector>'::`4'::`local static guard' & 1) == 0 )
        `CDmxAttribute::GetValue<Vector>'::`4'::`local static guard' |= 1u;
      `CDmxAttribute::GetValue<Vector>'::`4'::defaultValue = 0;
      dword_104EEE04 = 0;
      dword_104EEE08 = 0;
      v26 = (float *)&`CDmxAttribute::GetValue<Vector>'::`4'::defaultValue;
    }
  }
  else
  {
    if ( (`CDmxElement::GetValue<Vector>'::`4'::`local static guard' & 1) == 0 )
      `CDmxElement::GetValue<Vector>'::`4'::`local static guard' |= 1u;
    `CDmxElement::GetValue<Vector>'::`4'::defaultValue = 0;
    dword_104EEE20 = 0;
    dword_104EEE24 = 0;
    v26 = (float *)&`CDmxElement::GetValue<Vector>'::`4'::defaultValue;
  }
  v3->m_DeltaHSV.x = *v26;
  v3->m_DeltaHSV.y = v26[1];
  v3->m_DeltaHSV.z = v26[2];
  v27 = CDmxElement::GetAttribute(this: v2, pAttributeName: "tolerance");
  if ( v27 != nullptr )
  {
    if ( v27->m_Type == AT_FLOAT )
    {
      v28 = (int *)v27->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
      v28 = &`CDmxAttribute::GetValue<float>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
    v28 = &`CDmxElement::GetValue<float>'::`4'::defaultValue;
  }
  v3->m_Tolerance = *(float *)v28;
  v29 = CDmxElement::GetAttribute(this: v2, pAttributeName: "fuzziness");
  if ( v29 != nullptr )
  {
    if ( v29->m_Type == AT_FLOAT )
    {
      v30 = (int *)v29->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
      v30 = &`CDmxAttribute::GetValue<float>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
    v30 = &`CDmxElement::GetValue<float>'::`4'::defaultValue;
  }
  v3->m_Fuzziness = *(float *)v30;
  v31 = CDmxElement::GetAttribute(this: v2, pAttributeName: "colorize");
  if ( v31 != nullptr )
  {
    if ( v31->m_Type == AT_BOOL )
    {
      v32 = (char *)v31->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<bool>'::`4'::defaultValue = 0;
      v32 = &`CDmxAttribute::GetValue<bool>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<bool>'::`4'::defaultValue = 0;
    v32 = &`CDmxElement::GetValue<bool>'::`4'::defaultValue;
  }
  v3->m_bColorize = *v32;
  v33 = CDmxElement::GetAttribute(this: v2, pAttributeName: "invertSelection");
  if ( v33 != nullptr )
  {
    if ( v33->m_Type == AT_BOOL )
    {
      v3->m_bInvertSelection = *(_BYTE *)v33->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<bool>'::`4'::defaultValue = 0;
      v3->m_bInvertSelection = false;
    }
    return 1;
  }
  else
  {
    `CDmxElement::GetValue<bool>'::`4'::defaultValue = 0;
    v3->m_bInvertSelection = false;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AD220
// Name: public: virtual void CSelectedHSVUIPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectedHSVUIPanel::OnCommand(CSelectedHSVUIPanel *this, const char *command)
{
  float v3; // xmm0_4
  float commanda; // [esp+10h] [ebp+8h]

  vgui::Frame::OnCommand(this, command);
  if ( _V_stricmp(s1: "BlendFactorUpdate", s2: command) != 0 )
  {
    if ( _V_stricmp(s1: "ToggleSelection", s2: command) != 0 )
    {
      if ( _V_stricmp(s1: "PickRGB", s2: command) != 0 )
      {
        if ( _V_stricmp(s1: "PickHSV", s2: command) == 0 )
          CSelectedHSVUIPanel::PickColorFromTextEntry(this, bRGB: false);
      }
      else
      {
        CSelectedHSVUIPanel::PickColorFromTextEntry(this, bRGB: true);
      }
    }
    else
    {
      CSelectedHSVUIPanel::EnableSelectionMode(this, bEnable: !this->m_bSelectionEnable);
    }
  }
  else
  {
    if ( this->m_pHSVOperation != nullptr )
    {
      commanda = this->m_pHSVOperation->GetBlendFactor(this: this->m_pHSVOperation);
      v3 = commanda;
    }
    else
    {
      v3 = 0.0;
    }
    this->m_pBlendFactorSlider->SetValue(this: this->m_pBlendFactorSlider, a2: (int)(float)(v3 * 255.0), a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AD300
// Name: public: virtual bool CColorBalanceOperation::Unserialize(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CColorBalanceOperation::Unserialize(CColorBalanceOperation *this, CDmxElement *pElement)
{
  const char *Name; // eax
  const CDmxAttribute *Attribute; // eax
  int *m_pData; // eax
  const CDmxAttribute *v7; // eax
  char *v8; // eax
  const CDmxAttribute *v9; // eax
  char *v10; // eax
  const CUtlVector<float,CUtlMemory<float,int> > *v11; // ebx
  const CUtlVector<float,CUtlMemory<float,int> > *v12; // eax
  int m_Size; // ecx
  const CUtlVector<float,CUtlMemory<float,int> > *magentaGreenBalance; // [esp+14h] [ebp+8h]

  Name = CDmxElement::GetName(this: pElement);
  V_strncpy(pDest: this->m_pName, pSrc: Name, maxLen: 256);
  Attribute = CDmxElement::GetAttribute(this: pElement, pAttributeName: "blendFactor");
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
  this->m_flBlendFactor = *(float *)m_pData;
  v7 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "enabled");
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
  this->m_bEnable = *v8;
  v9 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "preserveLuminosity");
  if ( v9 != nullptr )
  {
    if ( v9->m_Type == AT_BOOL )
    {
      v10 = (char *)v9->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<bool>'::`4'::defaultValue = 0;
      v10 = &`CDmxAttribute::GetValue<bool>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<bool>'::`4'::defaultValue = 0;
    v10 = &`CDmxElement::GetValue<bool>'::`4'::defaultValue;
  }
  this->m_PreserveLuminosity = *v10;
  v11 = CDmxElement::GetArray<float>(this: pElement, pAttributeName: "cyanRedBalance");
  magentaGreenBalance = CDmxElement::GetArray<float>(this: pElement, pAttributeName: "magentaGreenBalance");
  v12 = CDmxElement::GetArray<float>(this: pElement, pAttributeName: "yellowBlueBalance");
  m_Size = v11->m_Size;
  if ( magentaGreenBalance->m_Size != m_Size || v12->m_Size != m_Size || m_Size != 3 )
    return 0;
  this->m_CyanRedBalance[0] = *v11->m_Memory.m_pMemory;
  this->m_MagentaGreenBalance[0] = *magentaGreenBalance->m_Memory.m_pMemory;
  this->m_YellowBlueBalance[0] = *v12->m_Memory.m_pMemory;
  this->m_CyanRedBalance[1] = v11->m_Memory.m_pMemory[1];
  this->m_MagentaGreenBalance[1] = magentaGreenBalance->m_Memory.m_pMemory[1];
  this->m_YellowBlueBalance[1] = v12->m_Memory.m_pMemory[1];
  this->m_CyanRedBalance[2] = v11->m_Memory.m_pMemory[2];
  this->m_MagentaGreenBalance[2] = magentaGreenBalance->m_Memory.m_pMemory[2];
  this->m_YellowBlueBalance[2] = v12->m_Memory.m_pMemory[2];
  CColorBalanceOperation::CreateLookupTables(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100AD480
// Name: private: bool CColorOperationListPanel::LoadVCCFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CColorOperationListPanel::LoadVCCFile(CColorOperationListPanel *this, const char *pFullPath)
{
  CDmxAttribute *Attribute; // eax
  const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *v4; // eax
  int m_Size; // ecx
  CDmxElement *v6; // ebx
  ColorCorrectionTool_t j; // edi
  const char *TypeString; // eax
  IColorOperation *ColorOp; // edi
  int v10; // eax
  int v11; // esi
  IColorOperation **m_pMemory; // ebx
  int v13; // eax
  IColorOperation **v14; // esi
  CUtlMemory<S3RGBA,int> *v15; // esi
  int k; // edi
  S3RGBA v17; // ecx
  int v18; // edi
  int v19; // ecx
  int v20; // ecx
  int m; // ebx
  S3RGBA *v22; // edi
  int m_nAllocationCount; // eax
  S3RGBA *v24; // ecx
  int v25; // eax
  IColorOperation **v26; // edi
  const char *v27; // [esp-Ch] [ebp-38h]
  const char *Name; // [esp-Ch] [ebp-38h]
  CUtlVector<IColorOperation *,CUtlMemory<IColorOperation *,int> > loadedOps; // [esp+4h] [ebp-28h] BYREF
  const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *operators; // [esp+18h] [ebp-14h]
  CDmxElement *pColorOperaterList; // [esp+1Ch] [ebp-10h] BYREF
  int nCount; // [esp+20h] [ebp-Ch]
  CColorOperationListPanel *v33; // [esp+24h] [ebp-8h]
  int i; // [esp+28h] [ebp-4h]
  int bOk; // [esp+34h] [ebp+8h]
  IColorOperation *bOka; // [esp+34h] [ebp+8h]
  char bOk_3; // [esp+37h] [ebp+Bh]

  v33 = this;
  BeginDMXContext();
  if ( UnserializeDMX(pFileName: pFullPath, pPathID: "GAME", bTextMode: true, ppRoot: &pColorOperaterList) )
  {
    Attribute = (CDmxAttribute *)CDmxElement::GetAttribute(this: pColorOperaterList, pAttributeName: "operators");
    if ( Attribute != nullptr )
    {
      v4 = CDmxAttribute::GetArray<CDmxElement *>(this: Attribute);
      m_Size = v4->m_Size;
      operators = v4;
      bOk_3 = 1;
      memset(&loadedOps, 0, sizeof(loadedOps));
      nCount = m_Size;
      i = 0;
      if ( m_Size > 0 )
      {
        while ( 1 )
        {
          v6 = v4->m_Memory.m_pMemory[i];
          for ( j = CC_TOOL_NONE; j < CC_TOOL_COUNT; ++j )
          {
            TypeString = CDmxElement::GetTypeString(this: v6);
            if ( _V_stricmp(s1: s_pColorCorrectionDmxElementNames[j], s2: TypeString) == 0 )
              break;
          }
          if ( j == CC_TOOL_COUNT )
          {
            v27 = CDmxElement::GetTypeString(this: v6);
            _Warning(a1: "Unknown color correction operator %s\n", v27);
            goto LABEL_23;
          }
          ColorOp = CreateColorOp(nToolId: j, pOpList: &v33->m_OperationList);
          if ( !ColorOp->Unserialize(this: ColorOp, a2: v6) )
            break;
          v10 = loadedOps.m_Size;
          v11 = loadedOps.m_Size;
          if ( loadedOps.m_Size + 1 > loadedOps.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<INetMessage *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)&loadedOps,
              num: loadedOps.m_Size - loadedOps.m_Memory.m_nAllocationCount + 1);
            v10 = loadedOps.m_Size;
          }
          m_pMemory = loadedOps.m_Memory.m_pMemory;
          loadedOps.m_Size = v10 + 1;
          v13 = v10 - v11;
          loadedOps.m_pElements = loadedOps.m_Memory.m_pMemory;
          if ( v13 > 0 )
            _V_memmove(
              dest: &loadedOps.m_Memory.m_pMemory[v11 + 1],
              src: &loadedOps.m_Memory.m_pMemory[v11],
              count: 4 * v13);
          v14 = &m_pMemory[v11];
          if ( v14 != nullptr )
            *v14 = ColorOp;
          if ( ++i >= nCount )
            goto LABEL_24;
          v4 = operators;
        }
        Name = CDmxElement::GetName(this: v6);
        _Warning(a1: "Error unserializing color correction operator %s\n", Name);
LABEL_23:
        bOk_3 = 0;
      }
LABEL_24:
      EndDMXContext(bDecommitMemory: true);
      if ( bOk_3 != 0 )
      {
        v15 = (CUtlMemory<S3RGBA,int> *)v33;
        for ( k = v33->m_OperationList.m_OpList.m_Size - 1; k >= 0; --k )
        {
          v17 = v15[37].m_pMemory[k];
          (*(void (__thiscall **)(S3RGBA))(**(_DWORD **)&v17 + 4))(a1: v17);
        }
        v18 = 0;
        v15[38].m_pMemory = nullptr;
        bOk = v15[40].m_nAllocationCount;
        if ( bOk > 0 )
        {
          do
          {
            v19 = *(_DWORD *)(v15[39].m_nAllocationCount + 4 * v18);
            (*(void (__thiscall **)(int))(*(_DWORD *)v19 + 1120))(a1: v19);
            v20 = *(_DWORD *)(v15[39].m_nAllocationCount + 4 * v18);
            if ( v20 != 0 )
              (*(void (__thiscall **)(int, int))(*(_DWORD *)v20 + 128))(a1: v20, a2: 1);
            ++v18;
          }
          while ( v18 < bOk );
        }
        v15[40].m_nAllocationCount = 0;
        for ( m = 0; m < nCount; ++m )
        {
          v22 = v15[38].m_pMemory;
          m_nAllocationCount = v15[37].m_nAllocationCount;
          bOka = loadedOps.m_Memory.m_pMemory[m];
          if ( (int)&v22->g > m_nAllocationCount )
            CUtlMemory<INetMessage *,int>::Grow(this: v15 + 37, num: (int)(&v22->g - m_nAllocationCount));
          ++v15[38].m_pMemory;
          v24 = v15[37].m_pMemory;
          v25 = (char *)v15[38].m_pMemory - (char *)v22 - 1;
          v15[38].m_nAllocationCount = (int)v24;
          if ( v25 > 0 )
            _V_memmove(dest: &v24[(_DWORD)v22 + 1], src: &v24[(_DWORD)v22], count: 4 * v25);
          v26 = (IColorOperation **)&v15[37].m_pMemory[(_DWORD)v22];
          if ( v26 != nullptr )
            *v26 = bOka;
        }
        if ( loadedOps.m_Memory.m_nGrowSize >= 0 && loadedOps.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: loadedOps.m_Memory.m_pMemory);
        return 1;
      }
      else
      {
        if ( loadedOps.m_Memory.m_nGrowSize >= 0 && loadedOps.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: loadedOps.m_Memory.m_pMemory);
        return 0;
      }
    }
    else
    {
      _Warning(a1: "File %s !\n", pFullPath);
      EndDMXContext(bDecommitMemory: true);
      return 0;
    }
  }
  else
  {
    _Warning(a1: "Error loading file %s!\n", pFullPath);
    EndDMXContext(bDecommitMemory: true);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AD880
// Name: public: virtual void CCurvesColorOperation::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurvesColorOperation::Release(CCurvesColorOperation *this)
{
  if ( this != nullptr )
  {
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_ControlPoints);
    free(pMem: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AD8A0
// Name: public: virtual class IColorOperation __near * CSelectedHSVOperation::Clone(void)
// Source: json
//------------------------------------------------------------------------------
CSelectedHSVOperation *__thiscall CSelectedHSVOperation::Clone(CSelectedHSVOperation *this)
{
  CSelectedHSVOperation *v2; // eax
  CSelectedHSVOperation *v3; // esi

  v2 = (CSelectedHSVOperation *)MemAlloc_Alloc(nSize: 0x154u);
  if ( v2 != nullptr )
    v3 = CSelectedHSVOperation::CSelectedHSVOperation(this: v2, pList: this->m_pOpList);
  else
    v3 = nullptr;
  CUtlVector<Vector,CUtlMemory<Vector,int>>::operator=(this: &v3->m_SelectedRGBs, other: &this->m_SelectedRGBs);
  CUtlVector<Vector,CUtlMemory<Vector,int>>::operator=(this: &v3->m_SelectedHSVs, other: &this->m_SelectedHSVs);
  v3->m_SelectionMethod = this->m_SelectionMethod;
  v3->m_DeltaHSV.x = this->m_DeltaHSV.x;
  v3->m_DeltaHSV.y = this->m_DeltaHSV.y;
  v3->m_DeltaHSV.z = this->m_DeltaHSV.z;
  v3->m_Tolerance = this->m_Tolerance;
  v3->m_Fuzziness = this->m_Fuzziness;
  v3->m_bColorize = this->m_bColorize;
  v3->m_bInvertSelection = this->m_bInvertSelection;
  v3->m_flBlendFactor = this->m_flBlendFactor;
  v3->m_bEnable = this->m_bEnable;
  v3->m_pOpList = this->m_pOpList;
  _V_memcpy(dest: v3->m_pName, src: this->m_pName, count: 256);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100AD940
// Name: public: virtual bool CColorOperationListPanel::OnReadFileFromDisk(char const __near *,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CColorOperationListPanel::OnReadFileFromDisk(
        CColorOperationListPanel *this,
        const char *pFileName,
        const char *pFileFormat,
        KeyValues *pContextKeyValues)
{
  bool VCCFile; // bl

  VCCFile = CColorOperationListPanel::LoadVCCFile(
              this: (CColorOperationListPanel *)((char *)this - 380),
              pFullPath: pFileName);
  if ( VCCFile )
  {
    CUtlString::operator=(this: (CUtlString *)&this->_actionSignalTargetDar.m_Size, src: pFileName);
    CColorOperationListPanel::PopulateList(this: (CColorOperationListPanel *)((char *)this - 380));
    colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
  }
  return VCCFile;
}

//------------------------------------------------------------------------------
// Address: 0x100AD990
// Name: public: virtual class IColorOperation __near * CCurvesColorOperation::Clone(void)
// Source: json
//------------------------------------------------------------------------------
CCurvesColorOperation *__thiscall CCurvesColorOperation::Clone(CCurvesColorOperation *this)
{
  CCurvesColorOperation *v2; // eax
  CCurvesColorOperation *v3; // esi

  v2 = (CCurvesColorOperation *)MemAlloc_Alloc(nSize: 0x52Cu);
  if ( v2 != nullptr )
    v3 = CCurvesColorOperation::CCurvesColorOperation(this: v2);
  else
    v3 = nullptr;
  _V_memcpy(dest: v3->m_pOutValue, src: this->m_pOutValue, count: 1024);
  v3->m_nChannelMask = this->m_nChannelMask;
  CUtlVector<Vector,CUtlMemory<Vector,int>>::operator=(this: &v3->m_ControlPoints, other: &this->m_ControlPoints);
  v3->m_ControlPoints.m_pLessContext = this->m_ControlPoints.m_pLessContext;
  v3->m_ControlPoints.m_bNeedsSort = this->m_ControlPoints.m_bNeedsSort;
  v3->m_flBlendFactor = this->m_flBlendFactor;
  _V_memcpy(dest: v3->m_pName, src: this->m_pName, count: 256);
  v3->m_bEnable = this->m_bEnable;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101A67F0
// Name: public: virtual void CColorBalanceUIPanel::ReadUncorrectedImage(struct Rect_t __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorBalanceUIPanel::ReadUncorrectedImage(vgui::TreeView *this, int itemIndex, KeyValues *msg)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10248DA0
// Name: public: class CUtlString const __near & CDmxElement::GetValue<class CUtlString>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CUtlString *__thiscall CDmxElement::GetValue<CUtlString>(CDmxElement *this, const char *pAttributeName)
{
  int v3; // edi
  CDmxAttribute *v4; // eax
  CDmxAttribute v6; // [esp+8h] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  CDmxAttribute::CDmxAttribute(this: &v6, pAttributeName);
  pAttributeName = (const char *)&v6;
  v3 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
         this: &this->m_Attributes,
         src: (CDmxAttribute *const *)&pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v6);
  if ( v3 >= 0 && (v4 = this->m_Attributes.m_Memory.m_pMemory[v3]) != nullptr )
  {
    if ( v4->m_Type == AT_STRING )
    {
      return (const CUtlString *)v4->m_pData;
    }
    else
    {
      if ( (`CDmxAttribute::GetValue<CUtlString>'::`4'::`local static guard' & 1) == 0 )
      {
        `CDmxAttribute::GetValue<CUtlString>'::`4'::`local static guard' |= 1u;
        CUtlString::CUtlString(this: &`CDmxAttribute::GetValue<CUtlString>'::`4'::defaultValue);
        atexit(func: `CDmxAttribute::GetValue<CUtlString>'::`4'::`dynamic atexit destructor for 'defaultValue'');
      }
      CUtlString::Set(this: &`CDmxAttribute::GetValue<CUtlString>'::`4'::defaultValue, pValue: nullptr);
      return &`CDmxAttribute::GetValue<CUtlString>'::`4'::defaultValue;
    }
  }
  else
  {
    if ( (`CDmxElement::GetValue<CUtlString>'::`4'::`local static guard' & 1) == 0 )
    {
      `CDmxElement::GetValue<CUtlString>'::`4'::`local static guard' |= 1u;
      CUtlString::CUtlString(this: &`CDmxElement::GetValue<CUtlString>'::`4'::defaultValue);
      atexit(func: `CDmxElement::GetValue<CUtlString>'::`4'::`dynamic atexit destructor for 'defaultValue'');
    }
    CUtlString::Set(this: &`CDmxElement::GetValue<CUtlString>'::`4'::defaultValue, pValue: nullptr);
    return &`CDmxElement::GetValue<CUtlString>'::`4'::defaultValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10249280
// Name: private: void CDmxAttribute::SerializeType<class DmeTime_t,class DmeTime_t>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<DmeTime_t,DmeTime_t>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  bool v3; // al
  DmeTime_t temp; // [esp+0h] [ebp-4h] BYREF

  temp.m_tms = (int)this;
  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (const DmeTime_t *)this->m_pData);
  }
  else
  {
    temp.m_tms = 0;
    v3 = Serialize(buf, src: &temp);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x102492B0
// Name: private: void CDmxAttribute::SerializeType<class Color,class Color>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<Color,Color>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  const Color *m_pData; // eax
  bool v4; // al
  Color temp; // [esp+0h] [ebp-4h] BYREF

  temp = (Color)this;
  m_pData = (const Color *)this->m_pData;
  if ( m_pData != nullptr )
  {
    v4 = Serialize(buf, src: m_pData);
  }
  else
  {
    temp = (Color)-16777216;
    v4 = Serialize(buf, src: &temp);
  }
  *bSuccess = v4;
}

//------------------------------------------------------------------------------
// Address: 0x102492F0
// Name: private: void CDmxAttribute::SerializeType<class Vector2D,class Vector2D>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<Vector2D,Vector2D>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  bool v3; // al
  Vector2D temp; // [esp+0h] [ebp-8h] BYREF

  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (const Vector2D *)this->m_pData);
  }
  else
  {
    temp.x = 0.0;
    temp.y = 0.0;
    v3 = Serialize(buf, src: &temp);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x10249330
// Name: private: void CDmxAttribute::SerializeType<class Vector,class Vector>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<Vector,Vector>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  bool v3; // al
  QAngle temp; // [esp+0h] [ebp-Ch] BYREF

  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (const QAngle *)this->m_pData);
  }
  else
  {
    memset((void *)&temp, 0, sizeof(temp));
    v3 = Serialize(buf, src: &temp);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x10249370
// Name: private: void CDmxAttribute::SerializeType<class Vector4D,class Vector4D>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<Vector4D,Vector4D>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  bool v3; // al
  Vector4D temp; // [esp+0h] [ebp-10h] BYREF

  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (const Quaternion *)this->m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    v3 = Serialize(buf, src: (const Quaternion *)&temp);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x102493C0
// Name: private: void CDmxAttribute::SerializeType<class Quaternion,class Quaternion>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<Quaternion,Quaternion>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v3; // al
  Quaternion temp; // [esp+0h] [ebp-10h] BYREF

  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (const Quaternion *)this->m_pData);
  }
  else
  {
    memset(&temp, 0, 12);
    temp.w = 1.0;
    v3 = Serialize(buf, src: &temp);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x10249410
// Name: private: void CDmxAttribute::SerializeType<class VMatrix,class VMatrix>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<VMatrix,VMatrix>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  bool v3; // al
  VMatrix temp; // [esp+0h] [ebp-40h] BYREF

  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (const VMatrix *)this->m_pData);
  }
  else
  {
    MatrixSetIdentity(dst: &temp);
    v3 = Serialize(buf, src: &temp);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x10249550
// Name: private: void CDmxAttribute::SerializeTypedElement<class CUtlVector<int,class CUtlMemory<int,int>>,int>(bool __near &,int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeTypedElement<CUtlVector<int,CUtlMemory<int,int>>,int>(
        CDmxAttribute *this,
        bool *bSuccess,
        int nIndex,
        CUtlBuffer *buf)
{
  _DWORD *m_pData; // eax
  bool v5; // al

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    v5 = Serialize(buf, src: (const int *)(*m_pData + 4 * nIndex));
  }
  else
  {
    nIndex = 0;
    v5 = Serialize(buf, src: &nIndex);
  }
  *bSuccess = v5;
}

//------------------------------------------------------------------------------
// Address: 0x102495A0
// Name: private: void CDmxAttribute::SerializeTypedElement<class CUtlVector<float,class CUtlMemory<float,int>>,float>(bool __near &,int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeTypedElement<CUtlVector<float,CUtlMemory<float,int>>,float>(
        CDmxAttribute *this,
        bool *bSuccess,
        int nIndex,
        CUtlBuffer *buf)
{
  _DWORD *m_pData; // eax
  bool v5; // al

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    v5 = Serialize(buf, src: (const float *)(*m_pData + 4 * nIndex));
  }
  else
  {
    nIndex = 0;
    v5 = Serialize(buf, src: (const float *)&nIndex);
  }
  *bSuccess = v5;
}

//------------------------------------------------------------------------------
// Address: 0x102495F0
// Name: private: void CDmxAttribute::SerializeTypedElement<class CUtlVector<bool,class CUtlMemory<bool,int>>,bool>(bool __near &,int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeTypedElement<CUtlVector<bool,CUtlMemory<bool,int>>,bool>(
        CDmxAttribute *this,
        bool *bSuccess,
        int nIndex,
        CUtlBuffer *buf)
{
  _DWORD *m_pData; // eax
  bool v5; // al

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    v5 = Serialize(buf, src: (const bool *)(nIndex + *m_pData));
  }
  else
  {
    HIBYTE(nIndex) = 0;
    v5 = Serialize(buf, src: (const bool *)&nIndex + 3);
  }
  *bSuccess = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10249620
// Name: private: void CDmxAttribute::SerializeTypedElement<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>,class DmeTime_t>(bool __near &,int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeTypedElement<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(
        CDmxAttribute *this,
        bool *bSuccess,
        DmeTime_t nIndex,
        CUtlBuffer *buf)
{
  _DWORD *m_pData; // eax
  bool v5; // al

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    v5 = Serialize(buf, src: (const DmeTime_t *)(*m_pData + 4 * nIndex.m_tms));
  }
  else
  {
    nIndex.m_tms = 0;
    v5 = Serialize(buf, src: &nIndex);
  }
  *bSuccess = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10249670
// Name: private: void CDmxAttribute::SerializeTypedElement<class CUtlVector<class Color,class CUtlMemory<class Color,int>>,class Color>(bool __near &,int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeTypedElement<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(
        CDmxAttribute *this,
        bool *bSuccess,
        Color nIndex,
        CUtlBuffer *buf)
{
  _DWORD *m_pData; // eax
  bool v5; // al

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    v5 = Serialize(buf, src: (const Color *)(*m_pData + 4 * *(_DWORD *)&nIndex));
  }
  else
  {
    nIndex = (Color)-16777216;
    v5 = Serialize(buf, src: &nIndex);
  }
  *bSuccess = v5;
}

//------------------------------------------------------------------------------
// Address: 0x102496C0
// Name: private: void CDmxAttribute::SerializeTypedElement<class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>,class Vector2D>(bool __near &,int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeTypedElement<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(
        CDmxAttribute *this,
        bool *bSuccess,
        int nIndex,
        CUtlBuffer *buf)
{
  _DWORD *m_pData; // eax
  bool v5; // al
  Vector2D temp; // [esp+0h] [ebp-8h] BYREF

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    v5 = Serialize(buf, src: (const Vector2D *)(*m_pData + 8 * nIndex));
  }
  else
  {
    temp.x = 0.0;
    temp.y = 0.0;
    v5 = Serialize(buf, src: &temp);
  }
  *bSuccess = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10249720
// Name: private: void CDmxAttribute::SerializeTypedElement<class CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>,class Vector4D>(bool __near &,int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeTypedElement<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>,Vector4D>(
        CDmxAttribute *this,
        bool *bSuccess,
        int nIndex,
        CUtlBuffer *buf)
{
  _DWORD *m_pData; // ecx
  bool v5; // al
  Vector4D temp; // [esp+0h] [ebp-10h] BYREF

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    v5 = Serialize(buf, src: (const Quaternion *)(*m_pData + 16 * nIndex));
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    v5 = Serialize(buf, src: (const Quaternion *)&temp);
  }
  *bSuccess = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10249770
// Name: private: void CDmxAttribute::SerializeTypedElement<class CUtlVector<class QAngle,class CUtlMemory<class QAngle,int>>,class QAngle>(bool __near &,int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeTypedElement<CUtlVector<QAngle,CUtlMemory<QAngle,int>>,QAngle>(
        CDmxAttribute *this,
        bool *bSuccess,
        int nIndex,
        CUtlBuffer *buf)
{
  _DWORD *m_pData; // ecx
  bool v5; // al
  QAngle temp; // [esp+0h] [ebp-Ch] BYREF

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    v5 = Serialize(buf, src: (const QAngle *)(*m_pData + 12 * nIndex));
  }
  else
  {
    memset((void *)&temp, 0, sizeof(temp));
    v5 = Serialize(buf, src: &temp);
  }
  *bSuccess = v5;
}

//------------------------------------------------------------------------------
// Address: 0x102497D0
// Name: private: void CDmxAttribute::SerializeTypedElement<class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>,class Quaternion>(bool __near &,int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeTypedElement<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(
        CDmxAttribute *this,
        bool *bSuccess,
        int nIndex,
        CUtlBuffer *buf)
{
  _DWORD *m_pData; // ecx
  bool v5; // al
  Quaternion temp; // [esp+0h] [ebp-10h] BYREF

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    v5 = Serialize(buf, src: (const Quaternion *)(*m_pData + 16 * nIndex));
  }
  else
  {
    memset(&temp, 0, 12);
    temp.w = 1.0;
    v5 = Serialize(buf, src: &temp);
  }
  *bSuccess = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10249830
// Name: private: void CDmxAttribute::SerializeTypedElement<class CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>,class VMatrix>(bool __near &,int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeTypedElement<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(
        CDmxAttribute *this,
        bool *bSuccess,
        int nIndex,
        CUtlBuffer *buf)
{
  _DWORD *m_pData; // ecx
  bool v5; // al
  VMatrix temp; // [esp+0h] [ebp-40h] BYREF

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    v5 = Serialize(buf, src: (const VMatrix *)(*m_pData + (nIndex << 6)));
  }
  else
  {
    MatrixSetIdentity(dst: &temp);
    v5 = Serialize(buf, src: &temp);
  }
  *bSuccess = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10249AE0
// Name: private: void CDmxAttribute::SerializeType<class CUtlBinaryBlock,class CUtlBinaryBlock>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlBinaryBlock,CUtlBinaryBlock>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v3; // al
  bool v4; // sf
  CUtlBinaryBlock temp; // [esp+0h] [ebp-10h] BYREF

  if ( this->m_pData != nullptr )
  {
    *bSuccess = Serialize(buf, src: (const CUtlBinaryBlock *)this->m_pData);
  }
  else
  {
    CUtlBinaryBlock::CUtlBinaryBlock(this: &temp, growSize: 0, initSize: 0);
    CUtlBinaryBlock::Set(this: &temp, pValue: nullptr, nLen: 0);
    v3 = Serialize(buf, src: &temp);
    v4 = temp.m_Memory.m_nGrowSize < 0;
    *bSuccess = v3;
    temp.m_nActualLength = 0;
    if ( !v4 && temp.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: temp.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10249B60
// Name: private: void CDmxAttribute::SerializeTypedElement<class CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>,class CUtlBinaryBlock>(bool __near &,int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeTypedElement<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        CDmxAttribute *this,
        bool *bSuccess,
        int nIndex,
        CUtlBuffer *buf)
{
  _DWORD *m_pData; // ecx
  bool v5; // al
  bool v6; // sf
  CUtlBinaryBlock temp; // [esp+0h] [ebp-10h] BYREF

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize(buf, src: (const CUtlBinaryBlock *)(*m_pData + 16 * nIndex));
  }
  else
  {
    CUtlBinaryBlock::CUtlBinaryBlock(this: &temp, growSize: 0, initSize: 0);
    CUtlBinaryBlock::Set(this: &temp, pValue: nullptr, nLen: 0);
    v5 = Serialize(buf, src: &temp);
    v6 = temp.m_Memory.m_nGrowSize < 0;
    *bSuccess = v5;
    temp.m_nActualLength = 0;
    if ( !v6 && temp.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: temp.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10249DC0
// Name: private: void CDmxAttribute::ConstructDataMemory<class CUtlVector<class Color,class CUtlMemory<class Color,int>>,class Color>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::ConstructDataMemory<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(CDmxAttribute *this)
{
  _DWORD *m_pData; // eax

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    *m_pData = 0;
    m_pData[1] = 0;
    m_pData[2] = 0;
    m_pData[3] = 0;
    m_pData[4] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10249DE0
// Name: private: void CDmxAttribute::SerializeType<class CUtlString,class CUtlString>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlString,CUtlString>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v3; // al
  bool v4; // sf
  CUtlString temp; // [esp+0h] [ebp-10h] BYREF

  if ( this->m_pData != nullptr )
  {
    *bSuccess = Serialize(buf, src: (const CUtlString *)this->m_pData);
  }
  else
  {
    CUtlString::CUtlString(this: &temp);
    CUtlString::Set(this: &temp, pValue: nullptr);
    v3 = Serialize(buf, src: &temp);
    v4 = temp.m_Storage.m_Memory.m_nGrowSize < 0;
    *bSuccess = v3;
    temp.m_Storage.m_nActualLength = 0;
    if ( !v4 && temp.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: temp.m_Storage.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10249E60
// Name: private: void CDmxAttribute::SerializeTypedElement<class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>,class CUtlString>(bool __near &,int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeTypedElement<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(
        CDmxAttribute *this,
        bool *bSuccess,
        int nIndex,
        CUtlBuffer *buf)
{
  _DWORD *m_pData; // ecx
  bool v5; // al
  bool v6; // sf
  CUtlString temp; // [esp+0h] [ebp-10h] BYREF

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize(buf, src: (const CUtlString *)(*m_pData + 16 * nIndex));
  }
  else
  {
    CUtlString::CUtlString(this: &temp);
    CUtlString::Set(this: &temp, pValue: nullptr);
    v5 = Serialize(buf, src: &temp);
    v6 = temp.m_Storage.m_Memory.m_nGrowSize < 0;
    *bSuccess = v5;
    temp.m_Storage.m_nActualLength = 0;
    if ( !v6 && temp.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: temp.m_Storage.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024AB00
// Name: private: void CDmxAttribute::DestructDataMemory<class CUtlBinaryBlock,class CUtlBinaryBlock>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::DestructDataMemory<CUtlBinaryBlock,CUtlBinaryBlock>(CDmxAttribute *this)
{
  int *m_pData; // esi
  bool v2; // sf

  m_pData = (int *)this->m_pData;
  v2 = m_pData[2] < 0;
  m_pData[3] = 0;
  if ( !v2 )
  {
    if ( *m_pData != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)*m_pData);
      *m_pData = 0;
    }
    m_pData[1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024AB40
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<int,class CUtlMemory<int,int>>,int>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<int,CUtlMemory<int,int>>,int>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<int,CUtlMemory<int,int> > *m_pData; // eax
  CUtlVector<int,CUtlMemory<int,int> > temp; // [esp+0h] [ebp-14h] BYREF

  m_pData = (const CUtlVector<int,CUtlMemory<int,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<int>(buf, src: m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    *bSuccess = Serialize<int>(buf, src: &temp);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&temp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024ABA0
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<float,class CUtlMemory<float,int>>,float>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<float,CUtlMemory<float,int>>,float>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<float,CUtlMemory<float,int> > *m_pData; // eax
  CUtlVector<float,CUtlMemory<float,int> > temp; // [esp+0h] [ebp-14h] BYREF

  m_pData = (const CUtlVector<float,CUtlMemory<float,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<float>(buf, src: m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    *bSuccess = Serialize<float>(buf, src: &temp);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&temp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024AC00
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<bool,class CUtlMemory<bool,int>>,bool>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<bool,CUtlMemory<bool,int>>,bool>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<bool,CUtlMemory<bool,int> > *m_pData; // eax
  CUtlVector<bool,CUtlMemory<bool,int> > temp; // [esp+0h] [ebp-14h] BYREF

  m_pData = (const CUtlVector<bool,CUtlMemory<bool,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<bool>(buf, src: m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    *bSuccess = Serialize<bool>(buf, src: &temp);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&temp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024AC60
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>,class DmeTime_t>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *m_pData; // eax
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > temp; // [esp+0h] [ebp-14h] BYREF

  m_pData = (const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<DmeTime_t>(buf, src: m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    *bSuccess = Serialize<DmeTime_t>(buf, src: &temp);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&temp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024ACC0
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<class Color,class CUtlMemory<class Color,int>>,class Color>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<Color,CUtlMemory<Color,int> > *m_pData; // eax
  CUtlVector<Color,CUtlMemory<Color,int> > temp; // [esp+0h] [ebp-14h] BYREF

  m_pData = (const CUtlVector<Color,CUtlMemory<Color,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<Color>(buf, src: m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    *bSuccess = Serialize<Color>(buf, src: &temp);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&temp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024AD20
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>,class Vector2D>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *m_pData; // eax
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > temp; // [esp+0h] [ebp-14h] BYREF

  m_pData = (const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<Vector2D>(buf, src: m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    *bSuccess = Serialize<Vector2D>(buf, src: &temp);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&temp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024AD80
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>,class Quaternion>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *m_pData; // eax
  CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > temp; // [esp+0h] [ebp-14h] BYREF

  m_pData = (const CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<Quaternion>(buf, src: m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    *bSuccess = Serialize<Quaternion>(buf, src: &temp);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&temp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024ADE0
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<class Vector,class CUtlMemory<class Vector,int>>,class Vector>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<Vector,CUtlMemory<Vector,int>>,Vector>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<QAngle,CUtlMemory<QAngle,int> > *m_pData; // eax
  CUtlVector<QAngle,CUtlMemory<QAngle,int> > temp; // [esp+0h] [ebp-14h] BYREF

  m_pData = (const CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<Vector>(buf, src: m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    *bSuccess = Serialize<Vector>(buf, src: &temp);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&temp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024AE40
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>,class VMatrix>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *m_pData; // eax
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > temp; // [esp+0h] [ebp-14h] BYREF

  m_pData = (const CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<VMatrix>(buf, src: m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    *bSuccess = Serialize<VMatrix>(buf, src: &temp);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&temp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024AEA0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<int,class CUtlMemory<int,int>>,int>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<int,CUtlMemory<int,int>>,int>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlMemory<S3RGBA,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  S3RGBA *m_pMemory; // edi
  S3RGBA *v8; // ecx
  int v9; // eax
  S3RGBA *v10; // eax

  v4 = Unserialize(buf, dest: (int *)&buf);
  *bSuccess = v4;
  if ( v4 )
  {
    m_pData = (CUtlMemory<S3RGBA,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)&m_pMemory->g > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(this: m_pData, num: (int)(&m_pMemory->g - m_nAllocationCount));
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = (char *)m_pData[1].m_pMemory - (char *)m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[(_DWORD)m_pMemory + 1], src: &v8[(_DWORD)m_pMemory], count: 4 * v9);
    v10 = &m_pData->m_pMemory[(_DWORD)m_pMemory];
    if ( v10 != nullptr )
      *v10 = (S3RGBA)buf;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024AF20
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<float,class CUtlMemory<float,int>>,float>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<float,CUtlMemory<float,int>>,float>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlMemory<S3RGBA,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  S3RGBA *m_pMemory; // edi
  S3RGBA *v8; // ecx
  int v9; // eax
  S3RGBA *v10; // eax

  v4 = Unserialize(buf, dest: (float *)&buf);
  *bSuccess = v4;
  if ( v4 )
  {
    m_pData = (CUtlMemory<S3RGBA,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)&m_pMemory->g > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(this: m_pData, num: (int)(&m_pMemory->g - m_nAllocationCount));
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = (char *)m_pData[1].m_pMemory - (char *)m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[(_DWORD)m_pMemory + 1], src: &v8[(_DWORD)m_pMemory], count: 4 * v9);
    v10 = &m_pData->m_pMemory[(_DWORD)m_pMemory];
    if ( v10 != nullptr )
      *v10 = (S3RGBA)buf;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024AFA0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<bool,class CUtlMemory<bool,int>>,bool>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<bool,CUtlMemory<bool,int>>,bool>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlMemory<char,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  char *m_pMemory; // edi
  char *v8; // ecx
  int v9; // eax
  char *v10; // esi

  v4 = Unserialize(buf, dest: (bool *)&buf + 3);
  *bSuccess = v4;
  if ( v4 )
  {
    m_pData = (CUtlMemory<char,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)(m_pMemory + 1) > m_nAllocationCount )
      CUtlMemory<bool,int>::Grow(this: m_pData, num: (int)&m_pMemory[-m_nAllocationCount + 1]);
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = m_pData[1].m_pMemory - m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[(_DWORD)m_pMemory + 1], src: &v8[(_DWORD)m_pMemory], count: v9);
    v10 = &m_pMemory[(unsigned int)m_pData->m_pMemory];
    if ( v10 != nullptr )
      *v10 = HIBYTE(buf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024B010
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>,class CUtlString>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlString temp; // [esp+4h] [ebp-10h] BYREF

  CUtlString::CUtlString(this: &temp);
  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
      this: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
  temp.m_Storage.m_nActualLength = 0;
  if ( temp.m_Storage.m_Memory.m_nGrowSize >= 0 && temp.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: temp.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1024B080
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>,class CUtlBinaryBlock>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlBinaryBlock temp; // [esp+4h] [ebp-10h] BYREF

  CUtlBinaryBlock::CUtlBinaryBlock(this: &temp, growSize: 0, initSize: 0);
  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertBefore(
      this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
  temp.m_nActualLength = 0;
  if ( temp.m_Memory.m_nGrowSize >= 0 && temp.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: temp.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1024B0F0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>,class DmeTime_t>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlMemory<S3RGBA,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  S3RGBA *m_pMemory; // edi
  S3RGBA *v8; // ecx
  int v9; // eax
  DmeTime_t *v10; // eax
  DmeTime_t temp; // [esp+4h] [ebp-4h] BYREF

  temp.m_tms = 0x80000000;
  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
  {
    m_pData = (CUtlMemory<S3RGBA,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)&m_pMemory->g > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(this: m_pData, num: (int)(&m_pMemory->g - m_nAllocationCount));
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = (char *)m_pData[1].m_pMemory - (char *)m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[(_DWORD)m_pMemory + 1], src: &v8[(_DWORD)m_pMemory], count: 4 * v9);
    v10 = (DmeTime_t *)&m_pData->m_pMemory[(_DWORD)m_pMemory];
    if ( v10 != nullptr )
      v10->m_tms = temp.m_tms;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024B180
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Color,class CUtlMemory<class Color,int>>,class Color>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlMemory<S3RGBA,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  S3RGBA *m_pMemory; // edi
  S3RGBA *v8; // ecx
  int v9; // eax
  Color *v10; // eax
  Color temp; // [esp+4h] [ebp-4h] BYREF

  temp = 0;
  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
  {
    m_pData = (CUtlMemory<S3RGBA,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)&m_pMemory->g > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(this: m_pData, num: (int)(&m_pMemory->g - m_nAllocationCount));
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = (char *)m_pData[1].m_pMemory - (char *)m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[(_DWORD)m_pMemory + 1], src: &v8[(_DWORD)m_pMemory], count: 4 * v9);
    v10 = (Color *)&m_pData->m_pMemory[(_DWORD)m_pMemory];
    if ( v10 != nullptr )
      *v10 = temp;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024B210
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>,class Vector2D>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  Vector2D temp; // [esp+4h] [ebp-8h] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: (CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x1024B250
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Vector,class CUtlMemory<class Vector,int>>,class Vector>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector,CUtlMemory<Vector,int>>,Vector>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  Vector temp; // [esp+4h] [ebp-Ch] BYREF

  v4 = Unserialize(buf, dest: (QAngle *)&temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x1024B290
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>,class Vector4D>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>,Vector4D>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  Vector4D temp; // [esp+4h] [ebp-10h] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::InsertBefore(
      this: (CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x1024B2D0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class QAngle,class CUtlMemory<class QAngle,int>>,class QAngle>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<QAngle,CUtlMemory<QAngle,int>>,QAngle>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  QAngle temp; // [esp+4h] [ebp-Ch] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertBefore(
      this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: (const CVTFTexture::ResourceMemorySection *)&temp);
}

//------------------------------------------------------------------------------
// Address: 0x1024B310
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>,class Quaternion>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  Quaternion temp; // [esp+4h] [ebp-10h] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
      this: (CUtlVector<CSosOperator::InputData_t,CUtlMemory<CSosOperator::InputData_t,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: (const CSosOperator::InputData_t *)&temp);
}

//------------------------------------------------------------------------------
// Address: 0x1024B350
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>,class VMatrix>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  VMatrix temp; // [esp+4h] [ebp-40h] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x1024C3B0
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>,class CUtlString>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *m_pData; // eax
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > temp; // [esp+0h] [ebp-14h] BYREF

  m_pData = (const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<CUtlString>(buf, src: m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&temp);
    *bSuccess = Serialize<CUtlString>(buf, src: &temp);
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&temp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024C420
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>,class CUtlBinaryBlock>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *m_pData; // eax
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > temp; // [esp+0h] [ebp-14h] BYREF

  m_pData = (const CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<CUtlBinaryBlock>(buf, src: m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: &temp);
    *bSuccess = Serialize<CUtlBinaryBlock>(buf, src: &temp);
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: &temp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10263C90
// Name: public: virtual void CColorHistogramPanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorHistogramPanel::PaintBackground(CCurveEditorPanel *this)
{
  int h; // [esp+4h] [ebp-8h] BYREF
  int w; // [esp+8h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: w, a5: h);
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 128, a3: 128, a4: 128, a5: 255);
  g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: 0, a3: h / 4, a4: w, a5: h / 4);
  g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: 0, a3: h / 2, a4: w, a5: h / 2);
  g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: 0, a3: 3 * h / 4, a4: w, a5: 3 * h / 4);
  g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: w / 4, a3: 0, a4: w / 4, a5: h);
  g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: w / 2, a3: 0, a4: w / 2, a5: h);
  g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: 3 * w / 4, a3: 0, a4: 3 * w / 4, a5: h);
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 0, a3: 0, a4: 0, a5: 255);
  g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: 0, a3: 0, a4: w, a5: 0);
  g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: w, a3: 0, a4: w, a5: h);
  g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: w, a3: h, a4: 0, a5: h);
  g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: 0, a3: h, a4: 0, a5: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10285450
// Name: public: virtual void CColorBalanceUIPanel::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorBalanceUIPanel::Init(vgui::PropertyPage *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1029C5B0
// Name: public: virtual class vgui::Panel __near * vgui::TextEntry::GetDragPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::TextEntry::GetDragPanel(vgui::TextEntry *this)
{
  int v2; // edi
  int cx1; // [esp+4h] [ebp-10h] BYREF
  int cx0; // [esp+8h] [ebp-Ch] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  if ( !g_pVGuiInput->IsMouseDown(this: g_pVGuiInput, a2: KEY_COUNT) )
    return vgui::Panel::GetDragPanel(this);
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  vgui::Panel::ScreenToLocal(this, &x, &y);
  v2 = this->PixelToCursorSpace(this, a2: x, a3: y);
  if ( this->GetSelectedRange(this, a2: &cx0, a3: &cx1) && v2 >= cx0 && v2 < cx1 )
    return vgui::Panel::GetDragPanel(this);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1029FD90
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::TextEntry::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::TextEntry::GetMessageMap(vgui::TextEntry *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::TextEntry::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TextEntry::GetMessageMap'::`2'::s_pMap;
  `vgui::TextEntry::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  `vgui::TextEntry::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029FDC0
// Name: public: virtual struct PanelAnimationMap __near * vgui::TextEntry::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::TextEntry::GetAnimMap(vgui::TextEntry *this)
{
  return FindOrAddPanelAnimationMap(className: "TextEntry");
}

//------------------------------------------------------------------------------
// Address: 0x1029FDD0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::TextEntry::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::TextEntry::GetKBMap(vgui::TextEntry *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::TextEntry::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TextEntry::GetKBMap'::`2'::s_pMap;
  `vgui::TextEntry::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  `vgui::TextEntry::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103200C0
// Name: _dynamic_initializer_for__CDmxElement::s_TypeSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmxElement::s_TypeSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>(this: &CDmxElement::s_TypeSymbols);
  return atexit(func: dynamic_atexit_destructor_for__CDmxElement::s_TypeSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x103200E0
// Name: _dynamic_initializer_for__CDmxAttribute::s_AttributeNameSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmxAttribute::s_AttributeNameSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>(this: &CDmxAttribute::s_AttributeNameSymbols);
  return atexit(func: dynamic_atexit_destructor_for__CDmxAttribute::s_AttributeNameSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x10327790
// Name: _dynamic_atexit_destructor_for__CDmxElement::s_TypeSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmxElement::s_TypeSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::RemoveAll(this: &CDmxElement::s_TypeSymbols);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&CDmxElement::s_TypeSymbols.m_StringPools);
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(this: &CDmxElement::s_TypeSymbols.m_Lookup);
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmxElement::s_TypeSymbols.m_Lookup.m_EntryMemory);
}

//------------------------------------------------------------------------------
// Address: 0x103277C0
// Name: _dynamic_atexit_destructor_for__CDmxAttribute::s_AttributeNameSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmxAttribute::s_AttributeNameSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::RemoveAll(this: &CDmxAttribute::s_AttributeNameSymbols);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&CDmxAttribute::s_AttributeNameSymbols.m_StringPools);
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(this: &CDmxAttribute::s_AttributeNameSymbols.m_Lookup);
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmxAttribute::s_AttributeNameSymbols.m_Lookup.m_EntryMemory);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10057450
// Name: public: virtual enum ColorCorrectionTool_t CSelectedHSVOperation::ToolID(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSelectedHSVOperation::ToolID(CTraceFilterDAS *this)
{
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x1006E000
// Name: public: virtual float CColorLookupOperation::GetBlendFactor(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CColorLookupOperation::GetBlendFactor(CBaseServer *this)
{
  return this->m_flTimescale;
}

//------------------------------------------------------------------------------
// Address: 0x1009F970
// Name: public: static char const __near * CPrecisionSlider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPrecisionSlider::GetPanelClassName()
{
  return "CPrecisionSlider";
}

//------------------------------------------------------------------------------
// Address: 0x1009F980
// Name: public: virtual void CPrecisionSlider::OnSizeChanged(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecisionSlider::OnSizeChanged(CPrecisionSlider *this, int wide, int tall)
{
  vgui::Panel::SetBounds(
    this: this->m_pTextEntry,
    x: wide - this->m_nTextEntryWidth,
    y: 0,
    wide: this->m_nTextEntryWidth,
    tall: tall - 12);
  vgui::Slider::OnSizeChanged(this, wide, tall);
}

//------------------------------------------------------------------------------
// Address: 0x1009F9C0
// Name: public: virtual void CPrecisionSlider::GetTrackRect(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecisionSlider::GetTrackRect(CPrecisionSlider *this, int *x, int *y, int *w, int *h)
{
  __m128i v6; // xmm0
  int tall; // [esp+4h] [ebp-8h] BYREF
  int wide; // [esp+8h] [ebp-4h] BYREF

  this->GetPaintSize(this, a2: &wide, a3: &tall);
  v6 = _mm_cvtsi32_si128(wide);
  *x = 0;
  *y = 8;
  *w = (int)(float)(_mm_cvtepi32_ps(v6).m128_f32[0]
                  - (float)((float)((float)this->m_nTextEntryWidth + this->_nobSize) + (float)this->m_nSpacing));
  *h = 4;
}

//------------------------------------------------------------------------------
// Address: 0x1009FA40
// Name: public: virtual void CPrecisionSlider::SetValue(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecisionSlider::SetValue(CPrecisionSlider *this, int value, bool bTriggerChangeMessage)
{
  char szValueString[256]; // [esp+4h] [ebp-100h] BYREF

  vgui::Slider::SetValue(this, value, bTriggerChangeMessage);
  sprintf(string: szValueString, format: "%d", this->_value);
  this->m_pTextEntry->SetText(this: this->m_pTextEntry, a2: szValueString);
}

//------------------------------------------------------------------------------
// Address: 0x1009FAA0
// Name: public: virtual void CPrecisionSlider::SetEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecisionSlider::SetEnabled(CPrecisionSlider *this, BOOL state)
{
  vgui::Panel::SetEnabled(this, state);
  this->m_pTextEntry->SetEnabled(this: this->m_pTextEntry, a2: state);
}

//------------------------------------------------------------------------------
// Address: 0x1009FAD0
// Name: protected: virtual void CPrecisionSlider::OnTextNewLine(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPrecisionSlider::OnTextNewLine(CPrecisionSlider *this, KeyValues *data)
{
  char buf[256]; // [esp+4h] [ebp-104h] BYREF
  int value; // [esp+104h] [ebp-4h] BYREF

  this->m_pTextEntry->GetText_2(this: this->m_pTextEntry, a2: buf, a3: 256);
  sscanf(string: buf, format: "%d", &value);
  this->SetValue(this, a2: value, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x1009FB30
// Name: public: static char const __near * CColorCorrectionUIChildPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CColorCorrectionUIChildPanel::GetPanelClassName()
{
  return "CColorCorrectionUIChildPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1009FB40
// Name: public: virtual void CColorCorrectionUIChildPanel::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionUIChildPanel::OnClose(CColorCorrectionUIChildPanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  CColorCorrectionUIChildPanel_vtbl *v4; // ebx
  int v5; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "OpPanelClose");
  else
    v3 = nullptr;
  KeyValues::SetPtr(this: v3, keyName: "panel", value: this);
  v4 = this->__vftable;
  v5 = ((int (__thiscall *)(CColorCorrectionUIChildPanel *, KeyValues *, _DWORD))this->GetParent)(
         a1: this,
         a2: v3,
         a3: 0.0);
  ((void (__thiscall *)(CColorCorrectionUIChildPanel *, int))v4->PostMessage)(a1: this, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1009FBA0
// Name: public: virtual void CColorCorrectionUIChildPanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionUIChildPanel::OnKeyCodeTyped(CColorCorrectionUIChildPanel *this, ButtonCode_t code)
{
  if ( code == KEY_ESCAPE )
    ShowHideColorCorrectionUI();
}

//------------------------------------------------------------------------------
// Address: 0x1009FBC0
// Name: public: virtual void CCurvesColorOperation::SetBlendFactor(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurvesColorOperation::SetBlendFactor(CCurvesColorOperation *this, float flBlend)
{
  this->m_flBlendFactor = flBlend;
  colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
}

//------------------------------------------------------------------------------
// Address: 0x1009FBF0
// Name: public: static char const __near * CColorCurvesEditPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CColorCurvesEditPanel::GetPanelClassName()
{
  return "CColorCurvesEditPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1009FC00
// Name: public: static char const __near * CColorCurvesUIPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CColorCurvesUIPanel::GetPanelClassName()
{
  return "CColorCurvesUIPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1009FC10
// Name: public: virtual void CColorCurvesUIPanel::OnMessage(class KeyValues const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCurvesUIPanel::OnMessage(CColorCurvesUIPanel *this, KeyValues *params, unsigned int fromPanel)
{
  const char *Name; // eax
  void *Ptr; // eax
  CCurvesColorOperation_vtbl *v6; // edi
  float v7; // xmm0_4
  KeyValues *v8; // eax
  KeyValues *v9; // eax
  CColorCurvesUIPanel_vtbl *v10; // edi
  int v11; // eax

  vgui::Panel::OnMessage(this, params, ifromPanel: fromPanel);
  Name = KeyValues::GetName(this: params);
  if ( _V_stricmp(s1: "SliderMoved", s2: Name) == 0 )
  {
    Ptr = KeyValues::GetPtr(this: params, keyName: "panel", defaultValue: nullptr);
    if ( __RTDynamicCast(
           inptr: Ptr,
           VfDelta: 0,
           SrcType: &vgui::Panel `RTTI Type Descriptor',
           TargetType: &CPrecisionSlider `RTTI Type Descriptor',
           isReference: 0) == this->m_pBlendFactorSlider )
    {
      v6 = this->m_pColorOp->__vftable;
      v7 = (float)this->m_pBlendFactorSlider->GetValue(this: this->m_pBlendFactorSlider) * 0.0039215689;
      ((void (__thiscall *)(CCurvesColorOperation *, _DWORD))v6->SetBlendFactor)(a1: this->m_pColorOp, a2: LODWORD(v7));
    }
    v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v8 != nullptr )
      v9 = KeyValues::KeyValues(this: v8, setName: "command", firstKey: "command", firstValue: "BlendFactorUpdate");
    else
      v9 = nullptr;
    v10 = this->__vftable;
    v11 = ((int (__thiscall *)(CColorCurvesUIPanel *, KeyValues *, _DWORD))this->GetParent)(a1: this, a2: v9, a3: 0.0);
    ((void (__thiscall *)(CColorCurvesUIPanel *, int))v10->PostMessage)(a1: this, a2: v11);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009FD00
// Name: private: void CColorCurvesUIPanel::OnColorMaskSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCurvesUIPanel::OnColorMaskSelected(CColorCurvesUIPanel *this)
{
  switch ( vgui::ComboBox::GetActiveItem(this: this->m_pColorMask) )
  {
    case 0:
      this->m_pColorOp->m_nChannelMask = 7;
      colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
      break;
    case 1:
      this->m_pColorOp->m_nChannelMask = 1;
      colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
      break;
    case 2:
      this->m_pColorOp->m_nChannelMask = 2;
      colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
      break;
    case 3:
      this->m_pColorOp->m_nChannelMask = 4;
      colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009FDB0
// Name: private: virtual void CColorCurvesUIPanel::OnTextChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCurvesUIPanel::OnTextChanged(CColorCurvesUIPanel *this, KeyValues *data)
{
  void *Ptr; // eax

  Ptr = KeyValues::GetPtr(this: data, keyName: "panel", defaultValue: nullptr);
  if ( __RTDynamicCast(
         inptr: Ptr,
         VfDelta: 0,
         SrcType: &vgui::Panel `RTTI Type Descriptor',
         TargetType: &vgui::ComboBox `RTTI Type Descriptor',
         isReference: 0) == this->m_pColorMask )
    CColorCurvesUIPanel::OnColorMaskSelected(this);
}

//------------------------------------------------------------------------------
// Address: 0x1009FDF0
// Name: public: virtual void CLevelsColorOperation::SetBlendFactor(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLevelsColorOperation::SetBlendFactor(CLevelsColorOperation *this, float flBlend)
{
  this->m_flBlendFactor = flBlend;
  colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
}

//------------------------------------------------------------------------------
// Address: 0x1009FE20
// Name: public: static char const __near * CColorHistogramPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CColorHistogramPanel::GetPanelClassName()
{
  return "CColorHistogramPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1009FE30
// Name: public: static char const __near * CColorSlider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CColorSlider::GetPanelClassName()
{
  return "CColorSlider";
}

//------------------------------------------------------------------------------
// Address: 0x1009FE40
// Name: public: static char const __near * CColorLevelsUIPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CColorLevelsUIPanel::GetPanelClassName()
{
  return "CColorLevelsUIPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1009FE50
// Name: private: void CColorLevelsUIPanel::OnColorMaskSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorLevelsUIPanel::OnColorMaskSelected(CColorLevelsUIPanel *this)
{
  switch ( vgui::ComboBox::GetActiveItem(this: this->m_pColorMask) )
  {
    case 0:
      this->m_pLevelsOp->m_nChannelMask = 7;
      colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
      this->m_pHistogramPanel->m_Type = RGB;
      break;
    case 1:
      this->m_pLevelsOp->m_nChannelMask = 1;
      colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
      this->m_pHistogramPanel->m_Type = 0;
      break;
    case 2:
      this->m_pLevelsOp->m_nChannelMask = 2;
      colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
      this->m_pHistogramPanel->m_Type = GREEN;
      break;
    case 3:
      this->m_pLevelsOp->m_nChannelMask = 4;
      colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
      this->m_pHistogramPanel->m_Type = BLUE;
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009FF80
// Name: float FuzzyLessThan(float,float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl FuzzyLessThan(float a, float b, float fuzziness)
{
  float v4; // xmm0_4

  if ( fuzziness >= 0.0039215689 )
  {
    v4 = b + fuzziness;
    if ( (float)(b - fuzziness) <= a )
    {
      if ( a <= v4 )
        return 1.0 - (a - (float)(b - fuzziness)) / (v4 - (float)(b - fuzziness));
      else
        return 0.0;
    }
    else
    {
      return 1.0;
    }
  }
  else if ( b < a )
  {
    return 0.0;
  }
  else
  {
    return 1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A0010
// Name: float FuzzyGreaterThan(float,float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl FuzzyGreaterThan(float a, float b, float fuzziness)
{
  float v4; // xmm1_4

  if ( fuzziness >= 0.0039215689 )
  {
    v4 = b - fuzziness;
    if ( a <= (float)(b + fuzziness) )
    {
      if ( v4 <= a )
        return (a - v4) / ((float)(b + fuzziness) - v4);
      else
        return 0.0;
    }
    else
    {
      return 1.0;
    }
  }
  else if ( a < b )
  {
    return 0.0;
  }
  else
  {
    return 1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A00A0
// Name: public: virtual void CSelectedHSVOperation::SetBlendFactor(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectedHSVOperation::SetBlendFactor(CSelectedHSVOperation *this, float blend_factor)
{
  this->m_flBlendFactor = blend_factor;
  colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
}

//------------------------------------------------------------------------------
// Address: 0x100A00C0
// Name: public: static char const __near * CFullScreenSelectionPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CFullScreenSelectionPanel::GetPanelClassName()
{
  return "CFullScreenSelectionPanel";
}

//------------------------------------------------------------------------------
// Address: 0x100A00D0
// Name: public: virtual void CFullScreenSelectionPanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFullScreenSelectionPanel::OnKeyCodeTyped(CFullScreenSelectionPanel *this, ButtonCode_t code)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( code == KEY_ESCAPE )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
    {
      v4 = KeyValues::KeyValues(this: v3, setName: "Command", firstKey: "Command", firstValue: "ToggleSelection");
      this->PostActionSignal(this, a2: v4);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A0130
// Name: public: static char const __near * CUncorrectedImagePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CUncorrectedImagePanel::GetPanelClassName()
{
  return "CUncorrectedImagePanel";
}

//------------------------------------------------------------------------------
// Address: 0x100A01B0
// Name: private: void CSelectedHSVUIPanel::UpdateDeltaHSV(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectedHSVUIPanel::UpdateDeltaHSV(CSelectedHSVUIPanel *this)
{
  int v2; // eax
  CPrecisionSlider *m_pToleranceSlider; // ecx
  float v4; // xmm0_4
  CSelectedHSVOperation *m_pHSVOperation; // eax
  int v6; // eax
  CPrecisionSlider *m_pFuzzinessSlider; // ecx
  CPrecisionSlider_vtbl *v8; // edx
  float deltaHSV; // [esp+4h] [ebp-Ch]
  float deltaHSV_4; // [esp+8h] [ebp-8h]

  deltaHSV = (float)this->m_pHueSlider->GetValue(this: this->m_pHueSlider);
  deltaHSV_4 = (float)this->m_pSaturationSlider->GetValue(this: this->m_pSaturationSlider) * 0.0039215689;
  v2 = this->m_pValueSlider->GetValue(this: this->m_pValueSlider);
  m_pToleranceSlider = this->m_pToleranceSlider;
  v4 = (float)v2;
  m_pHSVOperation = this->m_pHSVOperation;
  m_pHSVOperation->m_DeltaHSV.x = deltaHSV;
  m_pHSVOperation->m_DeltaHSV.y = deltaHSV_4;
  m_pHSVOperation->m_DeltaHSV.z = v4 * 0.0039215689;
  v6 = m_pToleranceSlider->GetValue(this: m_pToleranceSlider);
  m_pFuzzinessSlider = this->m_pFuzzinessSlider;
  v8 = m_pFuzzinessSlider->__vftable;
  this->m_pHSVOperation->m_Tolerance = (float)v6 * 0.0039215689;
  this->m_pHSVOperation->m_Fuzziness = (float)v8->GetValue(this: m_pFuzzinessSlider) * 0.0039215689;
  colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
}

//------------------------------------------------------------------------------
// Address: 0x100A02A0
// Name: private: void CSelectedHSVUIPanel::ResetHSVSliders(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectedHSVUIPanel::ResetHSVSliders(CSelectedHSVUIPanel *this)
{
  CSelectedHSVOperation *m_pHSVOperation; // eax
  float deltaHSV_4; // [esp+8h] [ebp-8h]
  float deltaHSV_8; // [esp+Ch] [ebp-4h]

  m_pHSVOperation = this->m_pHSVOperation;
  deltaHSV_4 = m_pHSVOperation->m_DeltaHSV.y;
  deltaHSV_8 = m_pHSVOperation->m_DeltaHSV.z;
  this->m_pHueSlider->SetValue(this: this->m_pHueSlider, a2: (int)m_pHSVOperation->m_DeltaHSV.x, a3: true);
  this->m_pSaturationSlider->SetValue(this: this->m_pSaturationSlider, a2: (int)(float)(deltaHSV_4 * 255.0), a3: true);
  this->m_pValueSlider->SetValue(this: this->m_pValueSlider, a2: (int)(float)(deltaHSV_8 * 255.0), a3: true);
  this->m_pToleranceSlider->SetValue(
    this: this->m_pToleranceSlider,
    a2: (int)(float)(this->m_pHSVOperation->m_Tolerance * 255.0),
    a3: true);
  this->m_pFuzzinessSlider->SetValue(
    this: this->m_pFuzzinessSlider,
    a2: (int)(float)(this->m_pHSVOperation->m_Fuzziness * 255.0),
    a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x100A0380
// Name: private: void CSelectedHSVUIPanel::OnSelectionMethodSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectedHSVUIPanel::OnSelectionMethodSelected(CSelectedHSVUIPanel *this)
{
  CSelectedHSVOperation::SelectionMethod_t ActiveItem; // edi

  CSelectedHSVUIPanel::ResetHSVSliders(this);
  ActiveItem = vgui::ComboBox::GetActiveItem(this: this->m_pSelectionMethod);
  this->m_pHSVOperation->m_SelectionMethod = ActiveItem;
  colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
  if ( ActiveItem == SELECT_NEARBY_RGB
    || ActiveItem == SELECT_NEARBY_HUE
    || ActiveItem == SELECT_NEARBY_SATURATION
    || ActiveItem == SELECT_NEARBY_VALUE )
  {
    this->m_pToleranceSlider->SetEnabled(this: this->m_pToleranceSlider, a2: true);
  }
  else
  {
    this->m_pToleranceSlider->SetEnabled(this: this->m_pToleranceSlider, a2: false);
  }
  this->m_pFuzzinessSlider->SetEnabled(this: this->m_pFuzzinessSlider, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x100A0470
// Name: public: virtual void CSelectedHSVUIPanel::OnMessage(class KeyValues const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectedHSVUIPanel::OnMessage(CSelectedHSVUIPanel *this, KeyValues *params, unsigned int fromPanel)
{
  const char *Name; // eax
  void *v5; // eax
  CPrecisionSlider *v6; // eax
  CSelectedHSVOperation_vtbl *v7; // edi
  float v8; // xmm0_4
  KeyValues *v9; // eax
  KeyValues *v10; // eax
  CSelectedHSVUIPanel_vtbl *v11; // edi
  int v12; // eax
  const char *v13; // eax
  void *Ptr; // eax
  vgui::CheckButton *v15; // eax

  vgui::Panel::OnMessage(this, params, ifromPanel: fromPanel);
  Name = KeyValues::GetName(this: params);
  if ( _V_stricmp(s1: "SliderMoved", s2: Name) != 0 )
  {
    v13 = KeyValues::GetName(this: params);
    if ( _V_stricmp(s1: "CheckButtonChecked", s2: v13) == 0 )
    {
      Ptr = KeyValues::GetPtr(this: params, keyName: "panel", defaultValue: nullptr);
      v15 = (vgui::CheckButton *)__RTDynamicCast(
                                   inptr: Ptr,
                                   VfDelta: 0,
                                   SrcType: &vgui::Panel `RTTI Type Descriptor',
                                   TargetType: &vgui::CheckButton `RTTI Type Descriptor',
                                   isReference: 0);
      if ( v15 == this->m_pColorizeButton )
      {
        this->m_pHSVOperation->m_bColorize = v15->IsSelected(this: v15);
        colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
      }
      else if ( v15 == this->m_pInvertSelectionButton )
      {
        this->m_pHSVOperation->m_bInvertSelection = ((int (*)(void))v15->IsSelected)();
        colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
      }
    }
  }
  else
  {
    v5 = KeyValues::GetPtr(this: params, keyName: "panel", defaultValue: nullptr);
    v6 = (CPrecisionSlider *)__RTDynamicCast(
                               inptr: v5,
                               VfDelta: 0,
                               SrcType: &vgui::Panel `RTTI Type Descriptor',
                               TargetType: &CPrecisionSlider `RTTI Type Descriptor',
                               isReference: 0);
    if ( v6 == this->m_pBlendFactorSlider )
    {
      v7 = this->m_pHSVOperation->__vftable;
      v8 = (float)v6->GetValue(this: v6) * 0.0039215689;
      ((void (__thiscall *)(CSelectedHSVOperation *, _DWORD))v7->SetBlendFactor)(
        a1: this->m_pHSVOperation,
        a2: LODWORD(v8));
      v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v9 != nullptr )
        v10 = KeyValues::KeyValues(this: v9, setName: "command", firstKey: "command", firstValue: "BlendFactorUpdate");
      else
        v10 = nullptr;
      v11 = this->__vftable;
      v12 = ((int (__thiscall *)(CSelectedHSVUIPanel *, KeyValues *, _DWORD))this->GetParent)(
              a1: this,
              a2: v10,
              a3: 0.0);
      ((void (__thiscall *)(CSelectedHSVUIPanel *, int))v11->PostMessage)(a1: this, a2: v12);
    }
    else
    {
      CSelectedHSVUIPanel::UpdateDeltaHSV(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A0600
// Name: public: void CSelectedHSVUIPanel::EnableSelectionMode(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectedHSVUIPanel::EnableSelectionMode(CSelectedHSVUIPanel *this, BOOL bEnable)
{
  vgui::Button *m_pSelectionButton; // ecx

  if ( bEnable )
    ((void (__stdcall *)(CSelectedHSVOperation *))colorcorrectiontools->SetFinalOperation)(a1: this->m_pHSVOperation);
  else
    ((void (__stdcall *)(_DWORD))colorcorrectiontools->SetFinalOperation)(a1: 0);
  m_pSelectionButton = this->m_pSelectionButton;
  this->m_bSelectionEnable = bEnable;
  m_pSelectionButton->ForceDepressed(this: m_pSelectionButton, a2: bEnable);
  this->m_pFullScreenSelection->SetEnabled(this: this->m_pFullScreenSelection, a2: bEnable);
  this->m_pFullScreenSelection->SetVisible(this: this->m_pFullScreenSelection, a2: bEnable);
  this->m_pFullScreenSelection->SetMouseInputEnabled(this: this->m_pFullScreenSelection, a2: bEnable);
}

//------------------------------------------------------------------------------
// Address: 0x100A0680
// Name: public: CColorLookupOperation::CColorLookupOperation(void)
// Source: json
//------------------------------------------------------------------------------
CColorLookupOperation *__thiscall CColorLookupOperation::CColorLookupOperation(CColorLookupOperation *this)
{
  this->m_Resolution = 0;
  this->m_LookupTable = nullptr;
  this->__vftable = (CColorLookupOperation_vtbl *)&CColorLookupOperation::`vftable';
  this->m_flBlendFactor = 1.0;
  _V_strcpy(dest: this->m_pName, src: "Lookup");
  _V_strcpy(dest: this->m_pFilename, src: defaultValue);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A06E0
// Name: public: virtual void CColorLookupOperation::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorLookupOperation::SetName(CColorLookupOperation *this, const char *pName)
{
  _V_strcpy(dest: this->m_pName, src: pName);
}

//------------------------------------------------------------------------------
// Address: 0x100A0700
// Name: public: virtual bool CColorLookupOperation::IsEnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CColorLookupOperation::IsEnabled(CColorLookupOperation *this)
{
  return this->m_bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x100A0710
// Name: public: virtual void CColorLookupOperation::SetEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorLookupOperation::SetEnabled(CColorLookupOperation *this, bool bEnable)
{
  this->m_bEnable = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x100A0720
// Name: public: void CColorLookupOperation::GetLookupValue(int,int,int,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorLookupOperation::GetLookupValue(CColorLookupOperation *this, int r, int g, int b, Vector *out)
{
  color24 *m_LookupTable; // ebx
  int v6; // esi
  int v7; // edi
  int v8; // edx
  int m_Resolution; // ecx
  int v10; // eax
  int v11; // ecx
  __int16 v12; // ax

  m_LookupTable = this->m_LookupTable;
  if ( m_LookupTable != nullptr )
  {
    v6 = r;
    if ( r < 0 )
      v6 = 0;
    v7 = g;
    if ( g < 0 )
      v7 = 0;
    v8 = b;
    if ( b < 0 )
      v8 = 0;
    m_Resolution = this->m_Resolution;
    v10 = m_Resolution - 1;
    if ( v6 > m_Resolution - 1 )
      v6 = m_Resolution - 1;
    if ( v7 > v10 )
      v7 = m_Resolution - 1;
    if ( v8 > v10 )
      v8 = m_Resolution - 1;
    v11 = (int)m_LookupTable
        + 2 * v6
        + 2 * m_Resolution * (v7 + v8 * m_Resolution)
        + v6
        + m_Resolution * (v7 + v8 * m_Resolution);
    v12 = *(_WORD *)v11;
    LOBYTE(v11) = *(_BYTE *)(v11 + 2);
    out->x = (float)(unsigned __int8)v12 * 0.0039215689;
    out->y = (float)HIBYTE(v12) * 0.0039215689;
    out->z = (float)(unsigned __int8)v11 * 0.0039215689;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A07E0
// Name: public: virtual void CColorLookupOperation::SetBlendFactor(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorLookupOperation::SetBlendFactor(CColorLookupOperation *this, float flBlend)
{
  this->m_flBlendFactor = flBlend;
  colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
}

//------------------------------------------------------------------------------
// Address: 0x100A0810
// Name: public: virtual class IColorOperation __near * CColorLookupOperation::Clone(void)
// Source: json
//------------------------------------------------------------------------------
IColorOperation *__thiscall CColorLookupOperation::Clone(CColorLookupOperation *this)
{
  char *v2; // edi
  void *v3; // eax

  v2 = (char *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v2 != nullptr )
  {
    *((_DWORD *)v2 + 66) = 0;
    *((_DWORD *)v2 + 67) = 0;
    *(_DWORD *)v2 = &CColorLookupOperation::`vftable';
    *((_DWORD *)v2 + 68) = 1065353216;
    _V_strcpy(dest: v2 + 277, src: "Lookup");
    _V_strcpy(dest: v2 + 4, src: defaultValue);
  }
  else
  {
    v2 = nullptr;
  }
  _V_memcpy(dest: v2 + 4, src: this->m_pFilename, count: 260);
  *((_DWORD *)v2 + 66) = this->m_Resolution;
  *((float *)v2 + 68) = this->m_flBlendFactor;
  v2[276] = this->m_bEnable;
  _V_memcpy(dest: v2 + 277, src: this->m_pName, count: 256);
  v3 = MemAlloc_Alloc(
         nSize: (3 * (unsigned __int64)(unsigned int)(this->m_Resolution * this->m_Resolution * this->m_Resolution)) >> 32 != 0
       ? -1
       : 3 * this->m_Resolution * this->m_Resolution * this->m_Resolution);
  *((_DWORD *)v2 + 67) = v3;
  _V_memcpy(dest: v3, src: this->m_LookupTable, count: 3 * this->m_Resolution * this->m_Resolution * this->m_Resolution);
  return (IColorOperation *)v2;
}

//------------------------------------------------------------------------------
// Address: 0x100A0910
// Name: public: static char const __near * CColorLookupUIPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CColorLookupUIPanel::GetPanelClassName()
{
  return "CColorLookupUIPanel";
}

//------------------------------------------------------------------------------
// Address: 0x100A0920
// Name: public: virtual void CColorLookupUIPanel::OnMessage(class KeyValues const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorLookupUIPanel::OnMessage(CColorLookupUIPanel *this, KeyValues *params, unsigned int fromPanel)
{
  const char *Name; // eax
  CColorLookupOperation_vtbl *v5; // edi
  float v6; // xmm0_4
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  CColorLookupUIPanel_vtbl *v9; // edi
  int v10; // eax

  vgui::Panel::OnMessage(this, params, ifromPanel: fromPanel);
  Name = KeyValues::GetName(this: params);
  if ( _V_stricmp(s1: "SliderMoved", s2: Name) == 0
    && KeyValues::GetPtr(this: params, keyName: "panel", defaultValue: nullptr) == this->m_pBlendFactorSlider )
  {
    v5 = this->m_pLookupOp->__vftable;
    v6 = (float)this->m_pBlendFactorSlider->GetValue(this: this->m_pBlendFactorSlider) * 0.0039215689;
    ((void (__thiscall *)(CColorLookupOperation *, _DWORD))v5->SetBlendFactor)(a1: this->m_pLookupOp, a2: LODWORD(v6));
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
      v8 = KeyValues::KeyValues(this: v7, setName: "command", firstKey: "command", firstValue: "BlendFactorUpdate");
    else
      v8 = nullptr;
    v9 = this->__vftable;
    v10 = ((int (__thiscall *)(CColorLookupUIPanel *, KeyValues *, _DWORD))this->GetParent)(a1: this, a2: v8, a3: 0.0);
    ((void (__thiscall *)(CColorLookupUIPanel *, int))v9->PostMessage)(a1: this, a2: v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A09F0
// Name: private: void CColorLookupUIPanel::ResetBlendFactorSlider(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorLookupUIPanel::ResetBlendFactorSlider(CColorLookupUIPanel *this)
{
  float v2; // xmm0_4
  float flBlend; // [esp+4h] [ebp-4h]

  if ( this->m_pLookupOp != nullptr )
  {
    flBlend = this->m_pLookupOp->GetBlendFactor(this: this->m_pLookupOp);
    v2 = flBlend;
  }
  else
  {
    v2 = 0.0;
  }
  this->m_pBlendFactorSlider->SetValue(this: this->m_pBlendFactorSlider, a2: (int)(float)(v2 * 255.0), a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x100A0A40
// Name: public: virtual char const __near * CColorBalanceOperation::GetName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CColorBalanceOperation::GetName(CColorBalanceOperation *this)
{
  return this->m_pName;
}

//------------------------------------------------------------------------------
// Address: 0x100A0A90
// Name: public: virtual float CColorBalanceOperation::GetBlendFactor(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CColorBalanceOperation::GetBlendFactor(CColorBalanceOperation *this)
{
  return this->m_flBlendFactor;
}

//------------------------------------------------------------------------------
// Address: 0x100A0AA0
// Name: void HSLToRGB(int __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HSLToRGB(int *hue, int *saturation, int *lightness)
{
  float v5; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm5_4
  double v9; // st7
  double v10; // st6
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm5_4
  int v17; // ecx
  float v18; // xmm0_4
  float l; // [esp+8h] [ebp+8h]
  float la; // [esp+8h] [ebp+8h]
  float lb; // [esp+8h] [ebp+8h]
  float m2; // [esp+Ch] [ebp+Ch]
  float m1; // [esp+10h] [ebp+10h]

  v5 = (float)*saturation;
  v7 = (float)*lightness;
  v8 = (float)*hue;
  if ( v5 == 0.0 )
  {
    *hue = (int)v7;
    *lightness = (int)v7;
    *saturation = (int)v7;
    return;
  }
  v9 = v7;
  if ( v7 >= 128.0 )
    v10 = 0.00392156862745098 * (v7 + v5 - v5 * v7 * 0.00392156862745098);
  else
    v10 = (v5 + 255.0) * v7 * 0.00001537870049980777;
  m2 = v10;
  v11 = v8 + 85.0;
  l = v8 + 85.0;
  m1 = v9 * 0.007843137254901961 - v10;
  if ( (float)(v8 + 85.0) <= 255.0 )
  {
    if ( v11 >= 0.0 )
      goto LABEL_11;
    v11 = v11 + 255.0;
  }
  else
  {
    v11 = v11 - 255.0;
  }
  l = v11;
LABEL_11:
  v12 = v9 * 0.007843137254901961 - v10;
  if ( v11 >= 42.5 )
  {
    if ( l >= 127.5 )
    {
      if ( v11 >= 170.0 )
        v13 = v9 * 0.007843137254901961 - v10;
      else
        v13 = (float)((float)((float)(170.0 - v11) * 0.023529412) * (float)(m2 - m1)) + m1;
    }
    else
    {
      v13 = v10;
    }
  }
  else
  {
    v13 = (float)((float)(m2 - m1) * (float)(v11 * 0.023529412)) + m1;
  }
  v14 = v8;
  *hue = (int)(float)(v13 * 255.0);
  la = v8;
  if ( v8 <= 255.0 )
  {
    if ( v8 >= 0.0 )
      goto LABEL_23;
    v14 = v8 + 255.0;
  }
  else
  {
    v14 = v8 - 255.0;
  }
  la = v14;
LABEL_23:
  if ( v14 >= 42.5 )
  {
    if ( la >= 127.5 )
    {
      if ( v14 >= 170.0 )
        v15 = v9 * 0.007843137254901961 - v10;
      else
        v15 = (float)((float)((float)(170.0 - v14) * 0.023529412) * (float)(m2 - m1)) + m1;
    }
    else
    {
      v15 = v10;
    }
  }
  else
  {
    v15 = (float)((float)(m2 - m1) * (float)(v14 * 0.023529412)) + m1;
  }
  v16 = v8 - 85.0;
  v17 = (int)(float)(v15 * 255.0);
  v18 = v16;
  *saturation = v17;
  lb = v16;
  if ( v16 <= 255.0 )
  {
    if ( v16 >= 0.0 )
      goto LABEL_35;
    v18 = v16 + 255.0;
  }
  else
  {
    v18 = v16 - 255.0;
  }
  lb = v18;
LABEL_35:
  if ( v18 >= 42.5 )
  {
    if ( lb >= 127.5 )
    {
      if ( v18 < 170.0 )
        v12 = m1 + (float)((float)((float)(170.0 - v18) * 0.023529412) * (float)(m2 - m1));
      *lightness = (int)(float)(v12 * 255.0);
    }
    else
    {
      *lightness = (int)(float)(m2 * 255.0);
    }
  }
  else
  {
    *lightness = (int)(float)((float)(m1 + (float)((float)(m2 - m1) * (float)(v18 * 0.023529412))) * 255.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A0D10
// Name: void RGBToHSL(int __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RGBToHSL(int *red, int *green, int *blue)
{
  int v3; // esi
  int v4; // edi
  int v5; // ecx
  int v6; // edx
  int v7; // eax
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float l; // [esp+Ch] [ebp-8h]

  v3 = *red;
  v4 = *green;
  v5 = *blue;
  if ( *red > *green )
  {
    v6 = *red;
    if ( v3 <= v5 )
      v6 = *blue;
    if ( v4 < v5 )
    {
      v7 = *green;
      goto LABEL_10;
    }
    goto LABEL_9;
  }
  v6 = *green;
  if ( v4 <= v5 )
    v6 = *blue;
  v7 = *red;
  if ( v3 >= v5 )
LABEL_9:
    v7 = *blue;
LABEL_10:
  l = (double)(v7 + v6) * 0.5;
  if ( v6 == v7 )
  {
    v8 = 0.0;
    v9 = 0.0;
  }
  else
  {
    v10 = (float)(v6 - v7);
    if ( l >= 128.0 )
      v11 = (float)(511 - v7 - v6);
    else
      v11 = (float)(v7 + v6);
    v9 = (float)(v10 * 255.0) / v11;
    if ( v3 == v6 )
    {
      v12 = (float)(v4 - v5) / v10;
    }
    else if ( v4 == v6 )
    {
      v12 = (float)((float)(v5 - v3) / v10) + 2.0;
    }
    else
    {
      v12 = (float)((float)(v3 - v4) / v10) + 4.0;
    }
    v8 = v12 * 42.5;
    if ( v8 >= 0.0 )
    {
      if ( v8 > 255.0 )
        v8 = v8 - 255.0;
    }
    else
    {
      v8 = v8 + 255.0;
    }
  }
  *red = (int)v8;
  *green = (int)v9;
  *blue = (int)l;
}

//------------------------------------------------------------------------------
// Address: 0x100A0E40
// Name: public: virtual void CColorBalanceOperation::Apply(class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorBalanceOperation::Apply(CColorBalanceOperation *this, int inRGB, Vector *outRGB)
{
  bool v4; // zf
  const Vector *v5; // ebx
  int v6; // ecx
  int v7; // esi
  int v8; // edx
  int v9; // eax
  Vector *v10; // eax
  __m128i v11; // xmm2
  __m128i v12; // xmm3
  float v13; // xmm1_4
  float m_flBlendFactor; // xmm6_4
  float y; // xmm4_4
  float v16; // xmm0_4
  int greenIn; // [esp+4h] [ebp-10h]
  int redIn; // [esp+8h] [ebp-Ch]
  int greenOut; // [esp+Ch] [ebp-8h] BYREF
  int redOut; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_bEnable )
  {
    v4 = !this->m_PreserveLuminosity;
    v5 = (const Vector *)inRGB;
    redIn = (int)(float)(*(float *)inRGB * 255.0);
    greenIn = (int)(float)(*(float *)(inRGB + 4) * 255.0);
    v6 = this->m_pGreenLookup[greenIn];
    v7 = (int)(float)(*(float *)(inRGB + 8) * 255.0);
    v8 = this->m_pBlueLookup[v7];
    redOut = this->m_pRedLookup[redIn];
    greenOut = v6;
    inRGB = v8;
    if ( !v4 )
    {
      RGBToHSL(red: &redOut, green: &greenOut, blue: &inRGB);
      if ( redIn <= greenIn )
      {
        v9 = greenIn;
        if ( greenIn <= v7 )
          v9 = v7;
        if ( redIn < v7 )
          v7 = redIn;
      }
      else
      {
        v9 = redIn;
        if ( redIn <= v7 )
          v9 = v7;
        if ( greenIn < v7 )
          v7 = greenIn;
      }
      inRGB = (int)(float)((float)(v9 + v7) * 0.5);
      HSLToRGB(hue: &redOut, saturation: &greenOut, lightness: &inRGB);
    }
    v10 = outRGB;
    v11 = _mm_cvtsi32_si128(greenOut);
    v12 = _mm_cvtsi32_si128(inRGB);
    v13 = (float)redOut * 0.0039215689;
    outRGB->x = v13;
    *(float *)v12.m128i_i32 = _mm_cvtepi32_ps(v12).m128_f32[0] * 0.0039215689;
    LODWORD(v10->z) = v12.m128i_i32[0];
    *(float *)v11.m128i_i32 = _mm_cvtepi32_ps(v11).m128_f32[0] * 0.0039215689;
    LODWORD(v10->y) = v11.m128i_i32[0];
    m_flBlendFactor = this->m_flBlendFactor;
    y = v5->y;
    v16 = (float)(1.0 - m_flBlendFactor) * v5->z;
    v10->x = (float)(v13 * m_flBlendFactor) + (float)(v5->x * (float)(1.0 - m_flBlendFactor));
    v10->y = (float)(y * (float)(1.0 - m_flBlendFactor)) + (float)(*(float *)v11.m128i_i32 * m_flBlendFactor);
    v10->z = (float)(*(float *)v12.m128i_i32 * m_flBlendFactor) + v16;
  }
  else
  {
    *outRGB = *(Vector *)inRGB;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A0FD0
// Name: public: virtual void CColorBalanceOperation::SetBlendFactor(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorBalanceOperation::SetBlendFactor(CColorBalanceOperation *this, float flBlend)
{
  this->m_flBlendFactor = flBlend;
  colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
}

//------------------------------------------------------------------------------
// Address: 0x100A1000
// Name: public: static char const __near * CColorBalanceUIPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CColorBalanceUIPanel::GetPanelClassName()
{
  return "CColorBalanceUIPanel";
}

//------------------------------------------------------------------------------
// Address: 0x100A1010
// Name: public: enum ColorBalanceMode_t CColorBalanceUIPanel::GetCurrentMode(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CColorBalanceUIPanel::GetCurrentMode(CColorBalanceUIPanel *this)
{
  if ( this->m_pShadowModeButton->IsSelected(this: this->m_pShadowModeButton) )
    return 0;
  if ( this->m_pMidtoneModeButton->IsSelected(this: this->m_pMidtoneModeButton) )
    return 1;
  return this->m_pHighlightModeButton->IsSelected(this: this->m_pHighlightModeButton) ? 2 : 0;
}

//------------------------------------------------------------------------------
// Address: 0x100A10F0
// Name: public: static char const __near * CLookupViewPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CLookupViewPanel::GetPanelClassName()
{
  return "CLookupViewPanel";
}

//------------------------------------------------------------------------------
// Address: 0x100A1100
// Name: public: static char const __near * CLookupViewWindow::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CLookupViewWindow::GetPanelClassName()
{
  return "CLookupViewWindow";
}

//------------------------------------------------------------------------------
// Address: 0x100A1110
// Name: public: virtual void CLookupViewWindow::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLookupViewWindow::Init(CLookupViewWindow *this)
{
  CLookupViewPanel *m_pLookupPanel; // ecx
  Rect_t rect; // [esp+4h] [ebp-10h] BYREF

  this->m_pLookupPanel->Init(this: this->m_pLookupPanel, a2: 128, a3: 256, a4: false);
  m_pLookupPanel = this->m_pLookupPanel;
  rect.x = 0;
  rect.y = 0;
  rect.width = 128;
  rect.height = 256;
  CProceduralTexturePanel::SetTextureSubRect(this: m_pLookupPanel, subRect: &rect);
  CProceduralTexturePanel::DownloadTexture(this: this->m_pLookupPanel);
}

//------------------------------------------------------------------------------
// Address: 0x100A1170
// Name: public: virtual void CLookupViewWindow::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLookupViewWindow::Shutdown(CLookupViewWindow *this)
{
  this->m_pLookupPanel->Shutdown(this: this->m_pLookupPanel);
}

//------------------------------------------------------------------------------
// Address: 0x100A1180
// Name: public: static char const __near * CNewOperationDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CNewOperationDialog::GetPanelClassName()
{
  return "CNewOperationDialog";
}

//------------------------------------------------------------------------------
// Address: 0x100A1190
// Name: public: static char const __near * COperationListPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl COperationListPanel::GetPanelClassName()
{
  return "COperationListPanel";
}

//------------------------------------------------------------------------------
// Address: 0x100A1200
// Name: public: virtual void COperationListPanel::ClearSelectedItems(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationListPanel::ClearSelectedItems(COperationListPanel *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  vgui::ListPanel::ClearSelectedItems(this);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: "Command", firstKey: "Command", firstValue: "SelectedItemChanged");
    this->PostActionSignal(this, a2: v3);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A1250
// Name: public: virtual void COperationListPanel::RemoveItem(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationListPanel::RemoveItem(COperationListPanel *this, int itemID)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  vgui::ListPanel::RemoveItem(this, itemID);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "Command", firstKey: "Command", firstValue: "SelectedItemChanged");
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A12B0
// Name: public: virtual void COperationListPanel::SetSortColumn(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationListPanel::SetSortColumn(COperationListPanel *this, int column)
{
  int v3; // edi
  unsigned int v4; // eax
  int i; // edi
  KeyValues *v6; // eax
  unsigned int v7; // eax

  if ( column == 0 )
  {
    HIBYTE(column) = 1;
    v3 = this->FirstItem(this);
    if ( v3 != this->InvalidItemID(this) )
    {
      while ( 1 )
      {
        v4 = this->GetItemUserData(this, a2: v3);
        if ( (*(unsigned __int8 (__thiscall **)(unsigned int))(*(_DWORD *)v4 + 24))(a1: v4) == 0 )
          break;
        v3 = this->NextItem(this, a2: v3);
        if ( v3 == this->InvalidItemID(this) )
          goto LABEL_7;
      }
      HIBYTE(column) = 0;
    }
LABEL_7:
    for ( i = this->FirstItem(this); i != this->InvalidItemID(this); i = this->NextItem(this, a2: i) )
    {
      v6 = this->GetItem(this, a2: i);
      KeyValues::SetInt(this: v6, keyName: "image", value: HIBYTE(column) == 0);
      v7 = this->GetItemUserData(this, a2: i);
      LOBYTE(column) = HIBYTE(column) == 0;
      (*(void (__thiscall **)(unsigned int, int))(*(_DWORD *)v7 + 28))(a1: v7, a2: column);
    }
    colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A13C0
// Name: public: virtual void COperationListPanel::OnTextNewLine(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationListPanel::OnTextNewLine(COperationListPanel *this, KeyValues *data)
{
  unsigned int v3; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  void (__thiscall *LeaveEditMode)(vgui::ListPanel *); // eax
  vgui::TextEntry *m_pNameEditPanel; // ecx
  char newName[256]; // [esp+4h] [ebp-100h] BYREF

  this->m_pNameEditPanel->GetText_2(this: this->m_pNameEditPanel, a2: newName, a3: 256);
  if ( this->m_nEditItem != -1 )
  {
    v3 = this->GetItemUserData(this, a2: this->m_nEditItem);
    (*(void (__thiscall **)(unsigned int, char *))(*(_DWORD *)v3 + 12))(a1: v3, a2: newName);
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "Command", firstKey: "Command", firstValue: "UpdateList");
    else
      v5 = nullptr;
    this->PostActionSignal(this, a2: v5);
  }
  LeaveEditMode = this->LeaveEditMode;
  this->m_nEditItem = -1;
  LeaveEditMode(this);
  m_pNameEditPanel = this->m_pNameEditPanel;
  if ( m_pNameEditPanel != nullptr )
    ((void (__thiscall *)(vgui::TextEntry *, int))m_pNameEditPanel->dtr_Panel)(a1: m_pNameEditPanel, a2: 1);
  this->m_pNameEditPanel = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100A1490
// Name: public: static char const __near * CColorOperationListPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CColorOperationListPanel::GetPanelClassName()
{
  return "CColorOperationListPanel";
}

//------------------------------------------------------------------------------
// Address: 0x100A14A0
// Name: private: virtual void CColorOperationListPanel::OnCheckButtonChecked(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CColorOperationListPanel::OnCheckButtonChecked(CColorOperationListPanel *this, KeyValues *data)
{
  vgui::CheckButton *Ptr; // eax
  vgui::CheckButton *m_pEnableButton; // ecx
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  vgui::CheckButton *m_pEnableEntitiesButton; // ecx

  Ptr = (vgui::CheckButton *)KeyValues::GetPtr(this: data, keyName: "panel", defaultValue: nullptr);
  m_pEnableButton = this->m_pEnableButton;
  if ( Ptr == m_pEnableButton )
  {
    if ( m_pEnableButton->IsSelected(this: m_pEnableButton) )
    {
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
        v6 = KeyValues::KeyValues(
               this: v5,
               setName: "Command",
               firstKey: "Command",
               firstValue: "EnableColorCorrection");
      else
        v6 = nullptr;
      this->PostActionSignal(this, a2: v6);
      this->m_bEnable = true;
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_colcorrection_editor.IConVar, value: 1);
    }
    else
    {
      v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v7 != nullptr )
        v8 = KeyValues::KeyValues(
               this: v7,
               setName: "Command",
               firstKey: "Command",
               firstValue: "DisableColorCorrection");
      else
        v8 = nullptr;
      this->PostActionSignal(this, a2: v8);
      this->m_bEnable = false;
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_colcorrection_editor.IConVar, value: 0);
    }
  }
  else
  {
    m_pEnableEntitiesButton = this->m_pEnableEntitiesButton;
    if ( Ptr == m_pEnableEntitiesButton )
    {
      if ( m_pEnableEntitiesButton->IsSelected(this: m_pEnableEntitiesButton) )
      {
        this->m_bEnableEntities = true;
        CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_colcorrection_disableentities.IConVar, value: 0);
      }
      else
      {
        this->m_bEnableEntities = false;
        CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_colcorrection_disableentities.IConVar, value: 1);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A1630
// Name: public: virtual void CColorOperationListPanel::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorOperationListPanel::OnThink(CColorOperationListPanel *this)
{
  vgui::Panel::OnThink(this);
  if ( this->m_bEnable )
    ((void (__thiscall *)(IColorCorrectionSystem *, unsigned int, _DWORD))colorcorrection->SetLookupWeight)(
      a1: colorcorrection,
      a2: this->m_CCHandle,
      a3: 1.0);
  else
    ((void (__thiscall *)(IColorCorrectionSystem *, unsigned int, _DWORD))colorcorrection->SetLookupWeight)(
      a1: colorcorrection,
      a2: this->m_CCHandle,
      a3: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x100A1680
// Name: private: void CColorOperationListPanel::ResetSlider(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorOperationListPanel::ResetSlider(CColorOperationListPanel *this)
{
  int v2; // edi
  unsigned int v3; // eax
  float flBlend; // [esp+8h] [ebp-4h]

  v2 = this->m_pOperationListPanel->GetSelectedItem(this: this->m_pOperationListPanel, a2: 0);
  if ( v2 < 0 || v2 >= this->m_pOperationListPanel->GetItemCount(this: this->m_pOperationListPanel) )
  {
    this->m_pBlendFactorSlider->SetValue(this: this->m_pBlendFactorSlider, a2: 0, a3: true);
    this->m_pBlendFactorSlider->SetEnabled(this: this->m_pBlendFactorSlider, a2: false);
  }
  else
  {
    v3 = this->m_pOperationListPanel->GetItemUserData(this: this->m_pOperationListPanel, a2: v2);
    flBlend = ((double (__thiscall *)(unsigned int))*(_DWORD *)(*(_DWORD *)v3 + 36))(a1: v3);
    this->m_pBlendFactorSlider->SetValue(this: this->m_pBlendFactorSlider, a2: (int)(float)(flBlend * 255.0), a3: true);
    this->m_pBlendFactorSlider->SetEnabled(this: this->m_pBlendFactorSlider, a2: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A1730
// Name: public: static char const __near * CColorCorrectionUIPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CColorCorrectionUIPanel::GetPanelClassName()
{
  return "CColorCorrectionUIPanel";
}

//------------------------------------------------------------------------------
// Address: 0x100A1750
// Name: public: virtual void CColorCorrectionUIPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionUIPanel::OnCommand(CColorCorrectionUIPanel *this, const char *command)
{
  unsigned int m_CCHandle; // edx

  vgui::Frame::OnCommand(this, command);
  if ( _V_stricmp(s1: "EnableColorCorrection", s2: command) != 0 )
  {
    if ( _V_stricmp(s1: "DisableColorCorrection", s2: command) == 0 )
    {
      this->m_bEnable = false;
      colorcorrection->SetResetable(this: colorcorrection, a2: this->m_CCHandle, a3: true);
    }
  }
  else
  {
    m_CCHandle = this->m_CCHandle;
    this->m_nCurrentRow = 0;
    this->m_bEnable = true;
    colorcorrection->SetResetable(this: colorcorrection, a2: m_CCHandle, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A17D0
// Name: public: virtual void CColorCorrectionTools::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionTools::Init(CColorCorrectionTools *this)
{
  if ( g_pColorCorrectionUI != nullptr )
    g_pColorCorrectionUI->m_pOperationListPanel->m_pLookupViewWindow->Init(this: g_pColorCorrectionUI->m_pOperationListPanel->m_pLookupViewWindow);
  this->m_pPreviewImage = (BGRA8888_t *)MemAlloc_Alloc(nSize: 0xC000u);
}

//------------------------------------------------------------------------------
// Address: 0x100A1810
// Name: public: virtual void CColorCorrectionTools::UpdateColorCorrection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionTools::UpdateColorCorrection(CColorCorrectionTools *this)
{
  if ( g_pColorCorrectionUI->m_bEnable )
    g_pColorCorrectionUI->m_nCurrentRow = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100A1830
// Name: public: virtual void CColorCorrectionTools::SetFinalOperation(class IColorOperation __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionTools::SetFinalOperation(CColorCorrectionTools *this, IColorOperation *pOp)
{
  CColorCorrectionUIPanel *v2; // eax
  bool v3; // zf

  v2 = g_pColorCorrectionUI;
  v3 = !g_pColorCorrectionUI->m_bEnable;
  g_pColorCorrectionUI->m_pFinalOperation = pOp;
  if ( !v3 )
    v2->m_nCurrentRow = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100A1860
// Name: void ShowHideColorCorrectionUI(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShowHideColorCorrectionUI()
{
  int v0; // eax
  bool v1; // al
  CColorCorrectionUIPanel_vtbl *v2; // edx

  if ( g_pColorCorrectionUI != nullptr )
  {
    v1 = g_pColorCorrectionUI->IsVisible(this: g_pColorCorrectionUI);
    v2 = g_pColorCorrectionUI->__vftable;
    if ( v1 )
      ((void (*)(void))v2->Close)();
    else
      ((void (*)(void))v2->Activate)();
  }
  else
  {
    v0 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v0 + 12))(a1: v0, a2: "-tools", a3: 0) == 0 )
      _Warning(a1: "colorcorrectionui is only available when running with -tools!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A18C0
// Name: void PrintColorCorrection(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrintColorCorrection()
{
  double v0; // st7
  double v1; // st7
  double v2; // st7
  double v3; // st7
  double v4; // st7

  v0 = ((double (__thiscall *)(IColorCorrectionSystem *, int))colorcorrection->GetLookupWeight)(
         a1: colorcorrection,
         a2: -1);
  ConMsg(a1: "Default weight : %0.5f\n", v0);
  v1 = ((double (__thiscall *)(IColorCorrectionSystem *, _DWORD))colorcorrection->GetLookupWeight)(
         a1: colorcorrection,
         a2: 0);
  ConMsg(a1: "Weight 0       : %0.5f\n", v1);
  v2 = ((double (__thiscall *)(IColorCorrectionSystem *, int))colorcorrection->GetLookupWeight)(
         a1: colorcorrection,
         a2: 1);
  ConMsg(a1: "Weight 1       : %0.5f\n", v2);
  v3 = ((double (__thiscall *)(IColorCorrectionSystem *, int))colorcorrection->GetLookupWeight)(
         a1: colorcorrection,
         a2: 2);
  ConMsg(a1: "Weight 2       : %0.5f\n", v3);
  v4 = ((double (__thiscall *)(IColorCorrectionSystem *, int))colorcorrection->GetLookupWeight)(
         a1: colorcorrection,
         a2: 3);
  ConMsg(a1: "Weight 3       : %0.5f\n", v4);
}

//------------------------------------------------------------------------------
// Address: 0x100A19A0
// Name: public: virtual struct vgui::PanelMessageMap __near * CPrecisionSlider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPrecisionSlider::GetMessageMap(CPrecisionSlider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPrecisionSlider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPrecisionSlider::GetMessageMap'::`2'::s_pMap;
  `CPrecisionSlider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPrecisionSlider");
  `CPrecisionSlider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A19D0
// Name: public: virtual struct PanelAnimationMap __near * CPrecisionSlider::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPrecisionSlider::GetAnimMap(CPrecisionSlider *this)
{
  return FindOrAddPanelAnimationMap(className: "CPrecisionSlider");
}

//------------------------------------------------------------------------------
// Address: 0x100A1A50
// Name: protected: virtual void CPrecisionSlider::OnMouseWheeled(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPrecisionSlider::OnMouseWheeled(CPrecisionSlider *this@<ecx>, int a2@<edi>, int delta)
{
  int v4; // edi

  vgui::Panel::OnMouseWheeled(this, delta);
  if ( this->IsEnabled(this) )
  {
    v4 = ((int (__thiscall *)(CPrecisionSlider *, int))this->GetValue)(a1: this, a2);
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
      || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL) )
    {
      ((void (__thiscall *)(CPrecisionSlider *, int))this->SetValue)(a1: this, a2: v4 + 4 * delta);
    }
    else
    {
      ((void (__thiscall *)(CPrecisionSlider *, int))this->SetValue)(a1: this, a2: delta + v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A1AE0
// Name: ComputeSplinePoint
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeSplinePoint(const Vector **pControlPoints@<edi>, Vector *vecOut@<esi>, float flInColor)
{
  Vector *v3; // ecx
  Vector *v4; // edx
  float x; // xmm1_4
  float v6; // xmm1_4
  float flStart; // [esp+8h] [ebp-Ch]
  float flEnd; // [esp+Ch] [ebp-8h]
  float flMid; // [esp+10h] [ebp-4h]

  v3 = (Vector *)pControlPoints[2];
  v4 = (Vector *)pControlPoints[1];
  x = v3->x;
  if ( v3->x == v4->x )
  {
    vecOut->x = v4->x + x;
    v6 = vecOut->x;
    vecOut->y = v4->y + v3->y;
    vecOut->z = v4->z + v3->z;
    vecOut->x = v6 * 0.5;
    vecOut->y = vecOut->y * 0.5;
    vecOut->z = vecOut->z * 0.5;
  }
  else
  {
    flStart = 0.0;
    flEnd = 1.0;
    flMid = (float)(flInColor - v4->x) / (float)(x - v4->x);
    Catmull_Rom_Spline(p1: *pControlPoints, p2: v4, p3: v3, p4: pControlPoints[3], t: flMid, output: vecOut);
    while ( fabs(vecOut->x - flInColor) >= 0.00001 )
    {
      if ( vecOut->x <= flInColor )
        flStart = flMid;
      else
        flEnd = flMid;
      flMid = (flEnd + flStart) * 0.5;
      Catmull_Rom_Spline(
        p1: *pControlPoints,
        p2: pControlPoints[1],
        p3: pControlPoints[2],
        p4: pControlPoints[3],
        t: flMid,
        output: vecOut);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A1C10
// Name: public: virtual struct vgui::PanelMessageMap __near * CColorCorrectionUIChildPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CColorCorrectionUIChildPanel::GetMessageMap(CColorCorrectionUIChildPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CColorCorrectionUIChildPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorCorrectionUIChildPanel::GetMessageMap'::`2'::s_pMap;
  `CColorCorrectionUIChildPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CColorCorrectionUIChildPanel");
  `CColorCorrectionUIChildPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A1C50
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CColorCorrectionUIChildPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CColorCorrectionUIChildPanel::GetKBMap(CColorCorrectionUIChildPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CColorCorrectionUIChildPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorCorrectionUIChildPanel::GetKBMap'::`2'::s_pMap;
  `CColorCorrectionUIChildPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CColorCorrectionUIChildPanel");
  `CColorCorrectionUIChildPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A1C80
// Name: public: CColorCorrectionUIChildPanel::CColorCorrectionUIChildPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CColorCorrectionUIChildPanel *__thiscall CColorCorrectionUIChildPanel::CColorCorrectionUIChildPanel(
        CColorCorrectionUIChildPanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Frame::Frame(this, parent, panelName: name, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CColorCorrectionUIChildPanel_vtbl *)&CColorCorrectionUIChildPanel::`vftable';
  if ( `CColorCorrectionUIChildPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CColorCorrectionUIChildPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CColorCorrectionUIChildPanel");
    v4->pfnClassName = CColorCorrectionUIChildPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CColorCorrectionUIChildPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CColorCorrectionUIChildPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CColorCorrectionUIChildPanel");
    v5->pfnClassName = CColorCorrectionUIChildPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CColorCorrectionUIChildPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CColorCorrectionUIChildPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CColorCorrectionUIChildPanel");
    v6->pfnClassName = CColorCorrectionUIChildPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A1E20
// Name: public: virtual struct vgui::PanelMessageMap __near * CColorCurvesEditPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CColorCurvesEditPanel::GetMessageMap(CColorCurvesEditPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CColorCurvesEditPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorCurvesEditPanel::GetMessageMap'::`2'::s_pMap;
  `CColorCurvesEditPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CColorCurvesEditPanel");
  `CColorCurvesEditPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A1E60
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CColorCurvesEditPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CColorCurvesEditPanel::GetKBMap(CColorCurvesEditPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CColorCurvesEditPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorCurvesEditPanel::GetKBMap'::`2'::s_pMap;
  `CColorCurvesEditPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CColorCurvesEditPanel");
  `CColorCurvesEditPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A1E90
// Name: public: CColorCurvesEditPanel::CColorCurvesEditPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CColorCurvesEditPanel *__thiscall CColorCurvesEditPanel::CColorCurvesEditPanel(
        CColorCurvesEditPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CCurveEditorPanel::CCurveEditorPanel(this, pParent, pName);
  this->__vftable = (CColorCurvesEditPanel_vtbl *)&CColorCurvesEditPanel::`vftable';
  if ( `CColorCurvesEditPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CColorCurvesEditPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CColorCurvesEditPanel");
    v4->pfnClassName = CColorCurvesEditPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CCurveEditorPanel");
  }
  if ( `CColorCurvesEditPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CColorCurvesEditPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CColorCurvesEditPanel");
    v5->pfnClassName = CColorCurvesEditPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CCurveEditorPanel");
  }
  if ( `CColorCurvesEditPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CColorCurvesEditPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CColorCurvesEditPanel");
    v6->pfnClassName = CColorCurvesEditPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CCurveEditorPanel");
  }
  this->m_pCurvesOp = nullptr;
  vgui::Panel::SetVisible(this, state: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A1F90
// Name: protected: virtual float CColorCurvesEditPanel::GetValue(float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CColorCurvesEditPanel::GetValue(CColorCurvesEditPanel *this, float flIn)
{
  CCurvesColorOperation *m_pCurvesOp; // ecx
  int v3; // eax

  m_pCurvesOp = this->m_pCurvesOp;
  v3 = (int)(float)(flIn * 255.0);
  if ( v3 < 0 )
  {
    v3 = 0;
    return (float)((float)((float)(m_pCurvesOp->m_pOutValue[v3 + 1] - m_pCurvesOp->m_pOutValue[v3])
                         * (float)((float)(flIn * 255.0) - (float)v3))
                 + m_pCurvesOp->m_pOutValue[v3]);
  }
  if ( v3 <= 254 )
    return (float)((float)((float)(m_pCurvesOp->m_pOutValue[v3 + 1] - m_pCurvesOp->m_pOutValue[v3])
                         * (float)((float)(flIn * 255.0) - (float)v3))
                 + m_pCurvesOp->m_pOutValue[v3]);
  return m_pCurvesOp->m_pOutValue[255];
}

//------------------------------------------------------------------------------
// Address: 0x100A2000
// Name: protected: virtual int CColorCurvesEditPanel::ControlPointCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CColorCurvesEditPanel::ControlPointCount(CColorCurvesEditPanel *this)
{
  return this->m_pCurvesOp->m_ControlPoints.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100A2010
// Name: public: virtual struct vgui::PanelMessageMap __near * CColorCurvesUIPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CColorCurvesUIPanel::GetMessageMap(CColorCurvesUIPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CColorCurvesUIPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorCurvesUIPanel::GetMessageMap'::`2'::s_pMap;
  `CColorCurvesUIPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CColorCurvesUIPanel");
  `CColorCurvesUIPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A2040
// Name: public: virtual struct PanelAnimationMap __near * CColorCurvesUIPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CColorCurvesUIPanel::GetAnimMap(CColorCurvesUIPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CColorCurvesUIPanel");
}

//------------------------------------------------------------------------------
// Address: 0x100A2050
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CColorCurvesUIPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CColorCurvesUIPanel::GetKBMap(CColorCurvesUIPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CColorCurvesUIPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorCurvesUIPanel::GetKBMap'::`2'::s_pMap;
  `CColorCurvesUIPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CColorCurvesUIPanel");
  `CColorCurvesUIPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A20D0
// Name: public: virtual void CColorCurvesUIPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCurvesUIPanel::OnCommand(CColorLevelsUIPanel *this, const char *command)
{
  float v3; // xmm0_4
  float commanda; // [esp+10h] [ebp+8h]

  vgui::Frame::OnCommand(this, command);
  if ( _V_stricmp(s1: "BlendFactorUpdate", s2: command) == 0 )
  {
    if ( this->m_pLevelsOp != nullptr )
    {
      commanda = this->m_pLevelsOp->GetBlendFactor(this: this->m_pLevelsOp);
      v3 = commanda;
    }
    else
    {
      v3 = 0.0;
    }
    this->m_pBlendFactorSlider->SetValue(this: this->m_pBlendFactorSlider, a2: (int)(float)(v3 * 255.0), a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A2140
// Name: private: void CLevelsColorOperation::UpdateOutputLevelArray(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLevelsColorOperation::UpdateOutputLevelArray(CLevelsColorOperation *this)
{
  int v2; // ecx
  float *m_pOutValue; // eax
  float m_flMinInputLevel; // xmm4_4
  float v5; // xmm2_4
  float y; // xmm2_4
  float m_flMaxInputLevel; // xmm3_4
  float m_flMidInputLevel; // xmm1_4
  float v9; // xmm1_4
  _DWORD v10[3]; // [esp+10h] [ebp-58h] BYREF
  float v11; // [esp+1Ch] [ebp-4Ch] BYREF
  int v12; // [esp+20h] [ebp-48h]
  int v13; // [esp+24h] [ebp-44h]
  float v14; // [esp+28h] [ebp-40h] BYREF
  int v15; // [esp+2Ch] [ebp-3Ch]
  int v16; // [esp+30h] [ebp-38h]
  _DWORD v17[3]; // [esp+34h] [ebp-34h] BYREF
  Vector *pControlPoints[4]; // [esp+40h] [ebp-28h] BYREF
  Vector vecOut; // [esp+50h] [ebp-18h] BYREF
  float flInColor; // [esp+5Ch] [ebp-Ch]
  float *v21; // [esp+60h] [ebp-8h]
  int i; // [esp+64h] [ebp-4h]

  v2 = 0;
  m_pOutValue = this->m_pOutValue;
  i = 0;
  v21 = this->m_pOutValue;
  do
  {
    m_flMinInputLevel = this->m_flMinInputLevel;
    v5 = (float)v2 * 0.0039215689;
    flInColor = v5;
    if ( m_flMinInputLevel < v5 )
    {
      m_flMaxInputLevel = this->m_flMaxInputLevel;
      if ( v5 < m_flMaxInputLevel )
      {
        m_flMidInputLevel = this->m_flMidInputLevel;
        *(float *)v10 = m_flMinInputLevel;
        v10[1] = 0;
        v10[2] = 0;
        *(float *)v17 = m_flMaxInputLevel;
        v17[1] = 1065353216;
        v17[2] = 0;
        v13 = 0;
        v16 = 0;
        if ( m_flMidInputLevel <= v5 )
        {
          v11 = m_flMidInputLevel;
          v12 = 1056964608;
          v14 = m_flMaxInputLevel;
          v15 = 1065353216;
        }
        else
        {
          v11 = m_flMinInputLevel;
          v12 = 0;
          v14 = m_flMidInputLevel;
          v15 = 1056964608;
        }
        pControlPoints[0] = (Vector *)v10;
        pControlPoints[1] = (Vector *)&v11;
        pControlPoints[2] = (Vector *)&v14;
        pControlPoints[3] = (Vector *)v17;
        ComputeSplinePoint((const Vector **)pControlPoints, &vecOut, flInColor);
        y = vecOut.y;
        m_pOutValue = v21;
        v2 = i;
      }
      else
      {
        y = 1.0;
      }
    }
    else
    {
      y = 0.0;
    }
    *m_pOutValue = y;
    v9 = (float)(this->m_flMaxOutputLevel - this->m_flMinOutputLevel) * y;
    *m_pOutValue = v9;
    ++v2;
    *m_pOutValue++ = this->m_flMinOutputLevel + v9;
    i = v2;
    v21 = m_pOutValue;
  }
  while ( v2 < 256 );
}

//------------------------------------------------------------------------------
// Address: 0x100A22B0
// Name: private: float CLevelsColorOperation::ComputeCorrectedLevel(float)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CLevelsColorOperation::ComputeCorrectedLevel(CLevelsColorOperation *this, float flInLevel)
{
  int v2; // eax
  double v3; // st7
  int v5; // [esp+0h] [ebp-4h]
  float flInLevela; // [esp+Ch] [ebp+8h]

  v2 = (int)(float)(flInLevel * 255.0);
  flInLevela = flInLevel * 255.0;
  if ( v2 < 0 )
  {
    v2 = 0;
    v5 = 0;
LABEL_3:
    v3 = this->m_pOutValue[v2];
    return v3 + (this->m_pOutValue[v2 + 1] - v3) * (flInLevela - (double)v5);
  }
  if ( v2 <= 255 )
  {
    v5 = v2;
    if ( v2 != 255 )
      goto LABEL_3;
  }
  return this->m_pOutValue[255];
}

//------------------------------------------------------------------------------
// Address: 0x100A2310
// Name: public: virtual void CLevelsColorOperation::Apply(class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLevelsColorOperation::Apply(CLevelsColorOperation *this, const Vector *inRGB, Vector *outRGB)
{
  double x; // st7
  Vector *v4; // edx
  double y; // st7
  double z; // st7
  float v7; // xmm2_4
  float m_flBlendFactor; // xmm0_4

  if ( this->m_bEnable )
  {
    x = inRGB->x;
    if ( (this->m_nChannelMask & 1) != 0 )
      x = CLevelsColorOperation::ComputeCorrectedLevel(this, flInLevel: inRGB->x);
    v4 = outRGB;
    outRGB->x = x;
    y = inRGB->y;
    if ( (this->m_nChannelMask & 2) != 0 )
      y = CLevelsColorOperation::ComputeCorrectedLevel(this, flInLevel: inRGB->y);
    v4->y = y;
    z = inRGB->z;
    if ( (this->m_nChannelMask & 4) != 0 )
      z = CLevelsColorOperation::ComputeCorrectedLevel(this, flInLevel: inRGB->z);
    v7 = v4->x;
    v4->z = z;
    m_flBlendFactor = this->m_flBlendFactor;
    v4->x = (float)((float)(v7 - inRGB->x) * m_flBlendFactor) + inRGB->x;
    v4->y = (float)((float)(v4->y - inRGB->y) * m_flBlendFactor) + inRGB->y;
    v4->z = (float)((float)(v4->z - inRGB->z) * m_flBlendFactor) + inRGB->z;
  }
  else
  {
    *outRGB = *inRGB;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A23E0
// Name: public: virtual struct vgui::PanelMessageMap __near * CColorHistogramPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CColorHistogramPanel::GetMessageMap(CColorHistogramPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CColorHistogramPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorHistogramPanel::GetMessageMap'::`2'::s_pMap;
  `CColorHistogramPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CColorHistogramPanel");
  `CColorHistogramPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A2410
// Name: public: virtual struct PanelAnimationMap __near * CColorHistogramPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CColorHistogramPanel::GetAnimMap(CColorHistogramPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CColorHistogramPanel");
}

//------------------------------------------------------------------------------
// Address: 0x100A2420
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CColorHistogramPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CColorHistogramPanel::GetKBMap(CColorHistogramPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CColorHistogramPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorHistogramPanel::GetKBMap'::`2'::s_pMap;
  `CColorHistogramPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CColorHistogramPanel");
  `CColorHistogramPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A2450
// Name: public: CColorHistogramPanel::CColorHistogramPanel(class vgui::Panel __near *,char const __near *,class CLevelsColorOperation __near *)
// Source: json
//------------------------------------------------------------------------------
CColorHistogramPanel *__thiscall CColorHistogramPanel::CColorHistogramPanel(
        CColorHistogramPanel *this,
        vgui::Panel *pParent,
        const char *pName,
        CLevelsColorOperation *pOp)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::Panel::Panel(this, parent: pParent, panelName: pName);
  this->__vftable = (CColorHistogramPanel_vtbl *)&CColorHistogramPanel::`vftable';
  if ( `CColorHistogramPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CColorHistogramPanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CColorHistogramPanel");
    v5->pfnClassName = CColorHistogramPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CColorHistogramPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CColorHistogramPanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CColorHistogramPanel");
    v6->pfnClassName = CColorHistogramPanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CColorHistogramPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CColorHistogramPanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CColorHistogramPanel");
    v7->pfnClassName = CColorHistogramPanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  memset(this->m_pHistogram, 0, sizeof(this->m_pHistogram));
  this->m_Type = RGB;
  this->m_pOp = pOp;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A2560
// Name: public: virtual void CColorHistogramPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorHistogramPanel::Paint(CColorHistogramPanel *this)
{
  float m_flMax; // xmm1_4
  float v3; // xmm0_4
  int v4; // esi
  int v5; // [esp-Ch] [ebp-2Ch]
  int v6; // [esp-8h] [ebp-28h]
  int h; // [esp+10h] [ebp-10h] BYREF
  int w; // [esp+14h] [ebp-Ch] BYREF
  float flOOMax; // [esp+18h] [ebp-8h]
  float *m_pHistogram; // [esp+1Ch] [ebp-4h]

  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  switch ( this->m_Type )
  {
    case 0:
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 0, a4: 0, a5: 255);
      break;
    case 1:
      v6 = 0;
      v5 = 255;
      goto LABEL_7;
    case 2:
      v6 = 255;
      goto LABEL_6;
    case 3:
      v6 = 0;
LABEL_6:
      v5 = 0;
LABEL_7:
      g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 0, a3: v5, a4: v6, a5: 255);
      break;
    default:
      break;
  }
  m_flMax = this->m_flMax;
  v3 = 1.0;
  if ( m_flMax != 0.0 )
    v3 = 1.0 / m_flMax;
  v4 = 0;
  flOOMax = v3;
  m_pHistogram = this->m_pHistogram;
  while ( 1 )
  {
    g_pVGuiSurface->DrawLine(
      this: g_pVGuiSurface,
      a2: (int)(float)((float)((float)(w - 1) * (float)v4) * 0.0039215689),
      a3: h - 1,
      a4: (int)(float)((float)((float)(w - 1) * (float)v4) * 0.0039215689),
      a5: h - (int)(float)((float)((float)(h - 1) * *m_pHistogram++) * v3) - 1);
    if ( ++v4 >= 256 )
      break;
    v3 = flOOMax;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A2690
// Name: public: virtual struct vgui::PanelMessageMap __near * CColorSlider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CColorSlider::GetMessageMap(CColorSlider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CColorSlider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorSlider::GetMessageMap'::`2'::s_pMap;
  `CColorSlider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CColorSlider");
  `CColorSlider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A26C0
// Name: public: virtual struct PanelAnimationMap __near * CColorSlider::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CColorSlider::GetAnimMap(CColorSlider *this)
{
  return FindOrAddPanelAnimationMap(className: "CColorSlider");
}

//------------------------------------------------------------------------------
// Address: 0x100A26D0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CColorSlider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CColorSlider::GetKBMap(CColorSlider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CColorSlider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorSlider::GetKBMap'::`2'::s_pMap;
  `CColorSlider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CColorSlider");
  `CColorSlider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A2700
// Name: public: CColorSlider::CColorSlider(class vgui::Panel __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CColorSlider *__thiscall CColorSlider::CColorSlider(
        CColorSlider *this,
        vgui::Panel *pParent,
        const char *pName,
        int nKnobCount)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  int v8; // eax

  vgui::Panel::Panel(this, parent: pParent, panelName: pName);
  this->__vftable = (CColorSlider_vtbl *)&CColorSlider::`vftable';
  if ( `CColorSlider::ChainToMap'::`2'::chained == 0 )
  {
    `CColorSlider::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CColorSlider");
    v5->pfnClassName = CColorSlider::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CColorSlider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CColorSlider::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CColorSlider");
    v6->pfnClassName = CColorSlider::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CColorSlider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CColorSlider::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CColorSlider");
    v7->pfnClassName = CColorSlider::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  this->m_flKnobPosition[0] = 0.0;
  this->m_flKnobPosition[1] = 1.0;
  this->m_nKnobCount = nKnobCount;
  *(_QWORD *)&this->m_flKnobPosition[2] = 1056964608;
  this->m_nMaxValue = 1;
  this->m_nSelectedKnob = -1;
  v8 = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
  this->m_nWhiteMaterial = v8;
  g_pVGuiSurface->DrawSetTextureFile(this: g_pVGuiSurface, a2: v8, a3: "vgui/white", a4: 1, a5: false);
  vgui::Panel::SetMouseInputEnabled(this, state: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A2880
// Name: public: void CColorSlider::SetNormalizedValue(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorSlider::SetNormalizedValue(CColorSlider *this, int nKnobIndex, float flValue)
{
  float v3; // xmm0_4
  bool v5; // cc
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  v3 = 0.0;
  if ( flValue >= 0.0 )
  {
    v3 = 1.0;
    if ( flValue <= 1.0 )
      v3 = flValue;
  }
  this->m_flKnobPosition[nKnobIndex] = v3;
  if ( nKnobIndex != 0 )
  {
    if ( nKnobIndex != 1 )
    {
      if ( nKnobIndex == 2 )
      {
        if ( this->m_flKnobPosition[0] > v3 )
          this->m_flKnobPosition[0] = v3;
        if ( v3 > this->m_flKnobPosition[1] )
          this->m_flKnobPosition[1] = v3;
      }
      goto LABEL_19;
    }
    if ( this->m_flKnobPosition[0] > v3 )
      this->m_flKnobPosition[0] = v3;
    v5 = this->m_flKnobPosition[2] <= v3;
  }
  else
  {
    if ( v3 > this->m_flKnobPosition[1] )
      this->m_flKnobPosition[1] = v3;
    v5 = v3 <= this->m_flKnobPosition[2];
  }
  if ( !v5 )
    this->m_flKnobPosition[2] = v3;
LABEL_19:
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
  {
    v7 = KeyValues::KeyValues(this: v6, setName: "SliderMoved", firstKey: "knob", firstValue: nKnobIndex);
    this->PostActionSignal(this, a2: v7);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A2980
// Name: public: virtual void CColorSlider::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorSlider::OnMousePressed(CColorSlider *this, const char *code)
{
  const char *v2; // edi
  vgui::IInput *v4; // ebx
  vgui::IInput_vtbl *v5; // edi
  int v6; // eax
  float flValue; // xmm0_4
  int v8; // edi
  int v9; // ecx
  int h; // [esp+18h] [ebp-10h] BYREF
  float flNormalizedVal; // [esp+1Ch] [ebp-Ch]
  int w; // [esp+20h] [ebp-8h] BYREF
  int y; // [esp+24h] [ebp-4h] BYREF

  v2 = code;
  CBaseServer::RemoveClientFromGame(this, panelName: code);
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: (int *)&code, a3: &y);
  vgui::Panel::ScreenToLocal(this, x: (int *)&code, &y);
  if ( v2 == (const char *)107 )
  {
    v4 = g_pVGuiInput;
    v5 = g_pVGuiInput->__vftable;
    v6 = this->GetVPanel(this);
    v5->SetMouseCapture(this: v4, a2: v6);
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    flValue = (float)(int)code / (float)(w - 1);
    v8 = 0;
    v9 = 1;
    flNormalizedVal = flValue;
    for ( this->m_nSelectedKnob = 0; v9 < this->m_nKnobCount; ++v9 )
    {
      if ( fabs(flValue - this->m_flKnobPosition[v8]) > fabs(flValue - this->m_flKnobPosition[v9]) )
      {
        v8 = v9;
        this->m_nSelectedKnob = v9;
      }
    }
    CColorSlider::SetNormalizedValue(this, nKnobIndex: this->m_nSelectedKnob, flValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A2A70
// Name: public: virtual void CColorSlider::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorSlider::OnMouseReleased(CColorSlider *this, const char *code)
{
  CBaseServer::RemoveClientFromGame(this, panelName: code);
  if ( code == (const char *)107 && this->m_nSelectedKnob >= 0 )
  {
    g_pVGuiInput->SetMouseCapture(this: g_pVGuiInput, a2: 0);
    this->m_nSelectedKnob = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A2AB0
// Name: public: virtual void CColorSlider::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorSlider::OnCursorMoved(CColorSlider *this, int x, float y)
{
  int v3; // edi
  int m_nSelectedKnob; // eax
  float v6; // xmm0_4
  int v7; // xmm1_4
  KeyValues *v8; // eax
  KeyValues *v9; // eax
  int h; // [esp+Ch] [ebp-8h] BYREF
  float fOldRelGrey; // [esp+10h] [ebp-4h]

  v3 = x;
  CColorBalanceUIPanel::ReadUncorrectedImage((vgui::TreeView *)this, itemIndex: x, msg: (KeyValues *)LODWORD(y));
  if ( this->m_nSelectedKnob >= 0 )
  {
    vgui::Panel::GetSize(this, wide: &x, tall: &h);
    m_nSelectedKnob = this->m_nSelectedKnob;
    y = (float)v3 / (float)(x - 1);
    if ( m_nSelectedKnob < 2 && this->m_nKnobCount == 3 )
    {
      fOldRelGrey = (float)(this->m_flKnobPosition[2] - this->m_flKnobPosition[0])
                  / (float)(this->m_flKnobPosition[1] - this->m_flKnobPosition[0]);
      CColorSlider::SetNormalizedValue(this, nKnobIndex: m_nSelectedKnob, flValue: y);
      v6 = (float)((float)(this->m_flKnobPosition[1] - this->m_flKnobPosition[0]) * fOldRelGrey)
         + this->m_flKnobPosition[0];
      v7 = 0;
      if ( v6 < 0.0 || (v7 = 1065353216, v6 > 1.0) )
        v6 = *(float *)&v7;
      this->m_flKnobPosition[2] = v6;
      if ( this->m_flKnobPosition[0] > v6 )
        this->m_flKnobPosition[0] = v6;
      if ( v6 > this->m_flKnobPosition[1] )
        this->m_flKnobPosition[1] = v6;
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
      {
        v9 = KeyValues::KeyValues(this: v8, setName: "SliderMoved", firstKey: "knob", firstValue: 2);
        this->PostActionSignal(this, a2: v9);
      }
      else
      {
        this->PostActionSignal(this, a2: nullptr);
      }
    }
    else
    {
      CColorSlider::SetNormalizedValue(this, nKnobIndex: m_nSelectedKnob, flValue: y);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A2C20
// Name: private: void CColorSlider::PaintKnob(float,unsigned char,unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorSlider::PaintKnob(
        CColorSlider *this,
        float flPosition,
        unsigned __int8 r,
        unsigned __int8 g,
        unsigned __int8 b)
{
  float v6; // xmm2_4
  FontVertex_t triangle[3]; // [esp+4h] [ebp-38h] BYREF
  int h; // [esp+34h] [ebp-8h] BYREF
  int w; // [esp+38h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  v6 = (float)(h - 1);
  triangle[0].m_Position.x = (float)(w - 1) * flPosition;
  triangle[0].m_Position.y = 0.0;
  triangle[0].m_TexCoord.x = 0.0;
  triangle[0].m_TexCoord.y = 0.0;
  triangle[1].m_Position.x = v6 + triangle[0].m_Position.x;
  triangle[1].m_Position.y = v6;
  triangle[1].m_TexCoord.x = 0.0;
  triangle[1].m_TexCoord.y = 0.0;
  triangle[2].m_Position.x = triangle[0].m_Position.x - v6;
  triangle[2].m_Position.y = v6;
  triangle[2].m_TexCoord.x = 0.0;
  triangle[2].m_TexCoord.y = 0.0;
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: 255);
  g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_nWhiteMaterial);
  g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 3, a3: triangle, a4: true);
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 0, a3: 0, a4: 0, a5: 255);
  g_pVGuiSurface->DrawTexturedPolyLine(this: g_pVGuiSurface, a2: triangle, a3: 3);
}

//------------------------------------------------------------------------------
// Address: 0x100A2D30
// Name: public: virtual void CColorSlider::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorSlider::Paint(CColorSlider *this)
{
  CColorSlider::PaintKnob(this, flPosition: this->m_flKnobPosition[0], r: 0, g: 0, b: 0);
  if ( this->m_nKnobCount == 3 )
    CColorSlider::PaintKnob(this, flPosition: this->m_flKnobPosition[2], r: 0x80u, g: 0x80u, b: 0x80u);
  CColorSlider::PaintKnob(this, flPosition: this->m_flKnobPosition[1], r: 0xFFu, g: 0xFFu, b: 0xFFu);
}

//------------------------------------------------------------------------------
// Address: 0x100A2DA0
// Name: public: virtual struct vgui::PanelMessageMap __near * CFullScreenSelectionPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CFullScreenSelectionPanel::GetMessageMap(CFullScreenSelectionPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CFullScreenSelectionPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CFullScreenSelectionPanel::GetMessageMap'::`2'::s_pMap;
  `CFullScreenSelectionPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CFullScreenSelectionPanel");
  `CFullScreenSelectionPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A2DD0
// Name: public: virtual struct PanelAnimationMap __near * CFullScreenSelectionPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CFullScreenSelectionPanel::GetAnimMap(CFullScreenSelectionPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CFullScreenSelectionPanel");
}

//------------------------------------------------------------------------------
// Address: 0x100A2DE0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CFullScreenSelectionPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CFullScreenSelectionPanel::GetKBMap(CFullScreenSelectionPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CFullScreenSelectionPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CFullScreenSelectionPanel::GetKBMap'::`2'::s_pMap;
  `CFullScreenSelectionPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CFullScreenSelectionPanel");
  `CFullScreenSelectionPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A2E10
// Name: public: CFullScreenSelectionPanel::CFullScreenSelectionPanel(char const __near *,class CSelectedHSVOperation __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CFullScreenSelectionPanel *__thiscall CFullScreenSelectionPanel::CFullScreenSelectionPanel(
        CFullScreenSelectionPanel *this,
        const char *pName,
        CSelectedHSVOperation *pOp,
        vgui::Panel *pParent)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::Panel::Panel(this, parent: pParent, panelName: pName);
  this->__vftable = (CFullScreenSelectionPanel_vtbl *)&CFullScreenSelectionPanel::`vftable';
  if ( `CFullScreenSelectionPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CFullScreenSelectionPanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CFullScreenSelectionPanel");
    v5->pfnClassName = CFullScreenSelectionPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CFullScreenSelectionPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CFullScreenSelectionPanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CFullScreenSelectionPanel");
    v6->pfnClassName = CFullScreenSelectionPanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CFullScreenSelectionPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CFullScreenSelectionPanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CFullScreenSelectionPanel");
    v7->pfnClassName = CFullScreenSelectionPanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  this->m_bMouseDown = false;
  vgui::Panel::SetZPos(this, z: -1000);
  this->m_pOp = pOp;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A2F60
// Name: public: virtual void CFullScreenSelectionPanel::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFullScreenSelectionPanel::OnMouseReleased(CFullScreenSelectionPanel *this, const char *code)
{
  int x; // [esp+4h] [ebp-8h] BYREF
  int y; // [esp+8h] [ebp-4h] BYREF

  this->m_bMouseDown = false;
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  CBaseServer::RemoveClientFromGame(this, panelName: code);
}

//------------------------------------------------------------------------------
// Address: 0x100A2FA0
// Name: public: virtual struct vgui::PanelMessageMap __near * CUncorrectedImagePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CUncorrectedImagePanel::GetMessageMap(CUncorrectedImagePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CUncorrectedImagePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CUncorrectedImagePanel::GetMessageMap'::`2'::s_pMap;
  `CUncorrectedImagePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CUncorrectedImagePanel");
  `CUncorrectedImagePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A2FD0
// Name: public: virtual struct PanelAnimationMap __near * CUncorrectedImagePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CUncorrectedImagePanel::GetAnimMap(CUncorrectedImagePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CUncorrectedImagePanel");
}

//------------------------------------------------------------------------------
// Address: 0x100A2FE0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CUncorrectedImagePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CUncorrectedImagePanel::GetKBMap(CUncorrectedImagePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CUncorrectedImagePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CUncorrectedImagePanel::GetKBMap'::`2'::s_pMap;
  `CUncorrectedImagePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CUncorrectedImagePanel");
  `CUncorrectedImagePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A3010
// Name: public: CUncorrectedImagePanel::CUncorrectedImagePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CUncorrectedImagePanel *__thiscall CUncorrectedImagePanel::CUncorrectedImagePanel(
        CUncorrectedImagePanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CProceduralTexturePanel::CProceduralTexturePanel(this, pParent, pName);
  this->CProceduralTexturePanel::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CUncorrectedImagePanel_vtbl *)&CUncorrectedImagePanel::`vftable'{for `vgui::EditablePanel'};
  this->CProceduralTexturePanel::ITextureRegenerator::__vftable = (ITextureRegenerator_vtbl *)&CUncorrectedImagePanel::`vftable'{for `ITextureRegenerator'};
  if ( `CUncorrectedImagePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CUncorrectedImagePanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CUncorrectedImagePanel");
    v4->pfnClassName = CUncorrectedImagePanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CProceduralTexturePanel");
  }
  if ( `CUncorrectedImagePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CUncorrectedImagePanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CUncorrectedImagePanel");
    v5->pfnClassName = CUncorrectedImagePanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CProceduralTexturePanel");
  }
  if ( `CUncorrectedImagePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CUncorrectedImagePanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CUncorrectedImagePanel");
    v6->pfnClassName = CUncorrectedImagePanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CProceduralTexturePanel");
  }
  this->m_bMouseDown = false;
  vgui::Panel::SetMouseInputEnabled(this, state: true);
  CProceduralTexturePanel::MaintainProportions(this, bEnable: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A3130
// Name: public: virtual void CUncorrectedImagePanel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUncorrectedImagePanel::OnMousePressed(CUncorrectedImagePanel *this, const char *code)
{
  const char *v2; // edi
  int x; // [esp+8h] [ebp-4h] BYREF

  v2 = code;
  CBaseServer::RemoveClientFromGame(this, panelName: code);
  if ( v2 == (const char *)107 )
  {
    this->m_bMouseDown = true;
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: (int *)&code);
    vgui::Panel::ScreenToLocal(this, &x, y: (int *)&code);
    this->OnCursorMoved(this, a2: x, a3: (int)code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A3190
// Name: private: void CSelectedHSVUIPanel::PopulateControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectedHSVUIPanel::PopulateControls(CSelectedHSVUIPanel *this)
{
  const char **v2; // edi

  vgui::ComboBox::RemoveAll(this: this->m_pSelectionMethod);
  v2 = CSelectedHSVUIPanel::s_pSelectionMethodNames;
  do
    this->m_pSelectionMethod->AddItem_2(this: this->m_pSelectionMethod, a2: *v2++, a3: nullptr);
  while ( (int)v2 < (int)&colorcorrectiontools );
  this->m_pSelectionMethod->AddActionSignalTarget_2(this: this->m_pSelectionMethod, a2: this);
  this->m_pSelectionMethod->ActivateItem(this: this->m_pSelectionMethod, a2: this->m_pHSVOperation->m_SelectionMethod);
  this->m_pColorEntry1->SetText(this: this->m_pColorEntry1, a2: "0");
  this->m_pColorEntry2->SetText(this: this->m_pColorEntry2, a2: "0");
  this->m_pColorEntry3->SetText(this: this->m_pColorEntry3, a2: "0");
}

//------------------------------------------------------------------------------
// Address: 0x100A3240
// Name: protected: virtual void CSelectedHSVUIPanel::OnTextChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectedHSVUIPanel::OnTextChanged(CSelectedHSVUIPanel *this, KeyValues *data)
{
  void *Ptr; // eax

  Ptr = KeyValues::GetPtr(this: data, keyName: "panel", defaultValue: nullptr);
  if ( __RTDynamicCast(
         inptr: Ptr,
         VfDelta: 0,
         SrcType: &vgui::Panel `RTTI Type Descriptor',
         TargetType: &vgui::ComboBox `RTTI Type Descriptor',
         isReference: 0) == this->m_pSelectionMethod )
    CSelectedHSVUIPanel::OnSelectionMethodSelected(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A3280
// Name: public: virtual void CColorLookupOperation::Apply(class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorLookupOperation::Apply(CColorLookupOperation *this, const Vector *inRGB, Vector *outRGB)
{
  float v4; // xmm0_4
  float x; // xmm4_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  int v9; // edi
  float v10; // xmm2_4
  int v11; // ebx
  float v12; // xmm3_4
  float v13; // xmm7_4
  float v14; // xmm1_4
  float v15; // xmm5_4
  float v16; // xmm6_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  float v19; // xmm6_4
  float v20; // xmm2_4
  float v21; // xmm5_4
  float v22; // xmm3_4
  float v23; // xmm0_4
  float v24; // xmm3_4
  float m_flBlendFactor; // xmm0_4
  float y; // xmm1_4
  float v27; // xmm5_4
  float z; // xmm2_4
  float v29; // xmm6_4
  float v30; // xmm7_4
  float v31; // xmm0_4
  float v32; // xmm5_4
  float v33; // xmm3_4
  float v34; // xmm7_4
  float v35; // xmm1_4
  float v36; // xmm2_4
  Vector interp_cube[8]; // [esp+4h] [ebp-A4h] BYREF
  Vector b; // [esp+64h] [ebp-44h]
  Vector c; // [esp+70h] [ebp-38h]
  Vector bottom; // [esp+7Ch] [ebp-2Ch]
  int g; // [esp+88h] [ebp-20h]
  Vector d; // [esp+8Ch] [ebp-1Ch]
  float v43; // [esp+98h] [ebp-10h]
  float v44; // [esp+9Ch] [ebp-Ch]
  float v45; // [esp+A0h] [ebp-8h]
  int ib; // [esp+A4h] [ebp-4h]

  if ( this->m_LookupTable != nullptr && this->m_bEnable )
  {
    v4 = (float)(this->m_Resolution - 1);
    x = inRGB->x;
    v6 = inRGB->x * v4;
    v7 = v4 * inRGB->y;
    v8 = v4 * inRGB->z;
    v9 = (int)v6;
    v10 = v6 - (float)(int)v6;
    v11 = (int)v7;
    v12 = v7 - (float)(int)v7;
    ib = (int)v8;
    v13 = v8 - (float)(int)v8;
    CColorLookupOperation::GetLookupValue(this, r: v9, g: v11, b: (int)v8, out: interp_cube);
    CColorLookupOperation::GetLookupValue(this, r: v9 + 1, g: v11, b: ib, out: &interp_cube[1]);
    g = v11 + 1;
    CColorLookupOperation::GetLookupValue(this, r: v9, g: v11 + 1, b: ib, out: &interp_cube[2]);
    CColorLookupOperation::GetLookupValue(this, r: v9 + 1, g, b: ib++, out: &interp_cube[3]);
    CColorLookupOperation::GetLookupValue(this, r: v9, g: v11, b: ib, out: &interp_cube[4]);
    CColorLookupOperation::GetLookupValue(this, r: v9 + 1, g: v11, b: ib, out: &interp_cube[5]);
    CColorLookupOperation::GetLookupValue(this, r: v9, g, b: ib, out: &interp_cube[6]);
    CColorLookupOperation::GetLookupValue(this, r: v9 + 1, g, b: ib, out: &interp_cube[7]);
    bottom.z = (float)((float)(1.0 - v10) * interp_cube[0].z) + (float)(interp_cube[1].z * v10);
    bottom.x = (float)((float)(1.0 - v10) * interp_cube[0].x) + (float)(interp_cube[1].x * v10);
    bottom.y = (float)((float)(1.0 - v10) * interp_cube[0].y) + (float)(interp_cube[1].y * v10);
    b.z = (float)((float)(1.0 - v10) * interp_cube[2].z) + (float)(interp_cube[3].z * v10);
    b.x = (float)((float)(1.0 - v10) * interp_cube[2].x) + (float)(interp_cube[3].x * v10);
    b.y = (float)((float)(1.0 - v10) * interp_cube[2].y) + (float)(interp_cube[3].y * v10);
    c.z = (float)((float)(1.0 - v10) * interp_cube[4].z) + (float)(interp_cube[5].z * v10);
    v45 = interp_cube[7].z * v10;
    v14 = (float)(1.0 - v10) * interp_cube[6].x;
    c.x = (float)((float)(1.0 - v10) * interp_cube[4].x) + (float)(interp_cube[5].x * v10);
    v15 = interp_cube[7].x * v10;
    c.y = (float)((float)(1.0 - v10) * interp_cube[4].y) + (float)(interp_cube[5].y * v10);
    v16 = interp_cube[7].y * v10;
    v17 = 1.0 - v10;
    d.z = (float)(v17 * interp_cube[6].z) + v45;
    v43 = b.x * v12;
    v44 = b.y * v12;
    v45 = b.z * v12;
    d.x = v14 + v15;
    bottom.z = (float)((float)(1.0 - v12) * bottom.z) + (float)(b.z * v12);
    bottom.x = (float)((float)(1.0 - v12) * bottom.x) + (float)(b.x * v12);
    v18 = (float)(v14 + v15) * v12;
    v19 = (float)(v16 + (float)(v17 * interp_cube[6].y)) * v12;
    bottom.y = (float)((float)(1.0 - v12) * bottom.y) + (float)(b.y * v12);
    v20 = d.z * v12;
    v21 = (float)(1.0 - v12) * c.y;
    v22 = 1.0 - v12;
    v23 = v22 * c.z;
    v24 = (float)(v22 * c.x) + v18;
    b.z = v23 + v20;
    m_flBlendFactor = this->m_flBlendFactor;
    d.x = x * m_flBlendFactor;
    y = inRGB->y;
    v27 = v21 + v19;
    d.y = y * m_flBlendFactor;
    z = inRGB->z;
    v29 = z * m_flBlendFactor;
    c.x = v24 * v13;
    c.y = v27 * v13;
    c.z = b.z * v13;
    v30 = 1.0 - v13;
    v31 = (float)(v30 * bottom.x) + c.x;
    v32 = (float)(bottom.y * v30) + c.y;
    v33 = bottom.z * v30;
    v34 = this->m_flBlendFactor;
    v35 = (float)(y + (float)(v32 * v34)) - d.y;
    v36 = (float)(z + (float)((float)(v33 + c.z) * v34)) - v29;
    outRGB->x = (float)(x + (float)(v31 * v34)) - d.x;
    outRGB->y = v35;
    outRGB->z = v36;
  }
  else
  {
    *outRGB = *inRGB;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A3700
// Name: private: void CColorLookupOperation::SetResolution(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorLookupOperation::SetResolution(CColorLookupOperation *this, int res)
{
  color24 *v3; // eax
  color24 *m_LookupTable; // [esp-4h] [ebp-Ch]

  if ( this->m_LookupTable != nullptr )
  {
    m_LookupTable = this->m_LookupTable;
    this->m_Resolution = 0;
    free(pMem: m_LookupTable);
  }
  v3 = (color24 *)MemAlloc_Alloc(nSize: (3 * (unsigned __int64)(unsigned int)(res * res * res)) >> 32 != 0 ? -1 : 3 * res * res * res);
  this->m_Resolution = res;
  this->m_LookupTable = v3;
}

//------------------------------------------------------------------------------
// Address: 0x100A3760
// Name: public: virtual void CColorLookupUIPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorLookupUIPanel::OnCommand(CColorLookupUIPanel *this, const char *command)
{
  vgui::FileOpenDialog *v3; // eax
  vgui::FileOpenDialog *v4; // esi

  if ( V_strcasecmp(s1: command, s2: "LoadLookup") != 0 )
  {
    if ( _V_stricmp(s1: "BlendFactorUpdate", s2: command) == 0 )
      CColorLookupUIPanel::ResetBlendFactorSlider(this);
    vgui::Frame::OnCommand(this, command);
  }
  else
  {
    v3 = (vgui::FileOpenDialog *)MemAlloc_Alloc(nSize: 0x6B0u);
    if ( v3 != nullptr )
      v4 = vgui::FileOpenDialog::FileOpenDialog(
             this: v3,
             parent: this,
             title: "File Open",
             bOpenOnly: true,
             pContextKeyValues: nullptr);
    else
      v4 = nullptr;
    v4->AddActionSignalTarget_2(this: v4, a2: this);
    vgui::FileOpenDialog::AddFilter(
      this: v4,
      filter: "*.raw",
      filterName: ".RAW files",
      bActive: true,
      pFilterInfo: nullptr);
    vgui::FileOpenDialog::DoModal(this: v4, bUnused: true);
    vgui::Frame::OnCommand(this, command);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A3810
// Name: private: void CColorBalanceOperation::CreateLookupTables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorBalanceOperation::CreateLookupTables(CColorBalanceOperation *this)
{
  CColorBalanceOperation *v1; // edx
  float v2; // xmm1_4
  int v3; // eax
  float *m_MagentaGreenBalance; // edi
  int v5; // esi
  int v6; // ebx
  int j; // edx
  int v8; // esi
  int v9; // ecx
  int v10; // eax
  float *yellow_blue_transfer[3]; // [esp+0h] [ebp-34h]
  float *magenta_green_transfer[3]; // [esp+Ch] [ebp-28h]
  float *cyan_red_transfer[3]; // [esp+18h] [ebp-1Ch]
  CColorBalanceOperation *v14; // [esp+24h] [ebp-10h]
  int i; // [esp+28h] [ebp-Ch]
  int v16; // [esp+2Ch] [ebp-8h]
  int v17; // [esp+30h] [ebp-4h]

  v1 = this;
  v2 = this->m_CyanRedBalance[0];
  v14 = this;
  if ( v2 <= 0.0 )
    cyan_red_transfer[0] = this->m_ShadowsSubTransfer;
  else
    cyan_red_transfer[0] = this->m_ShadowsAddTransfer;
  if ( this->m_CyanRedBalance[1] <= 0.0 )
    cyan_red_transfer[1] = this->m_MidtonesSubTransfer;
  else
    cyan_red_transfer[1] = this->m_MidtonesAddTransfer;
  if ( this->m_CyanRedBalance[2] <= 0.0 )
    cyan_red_transfer[2] = this->m_HighlightsSubTransfer;
  else
    cyan_red_transfer[2] = this->m_HighlightsAddTransfer;
  if ( this->m_MagentaGreenBalance[0] <= 0.0 )
    magenta_green_transfer[0] = this->m_ShadowsSubTransfer;
  else
    magenta_green_transfer[0] = this->m_ShadowsAddTransfer;
  if ( this->m_MagentaGreenBalance[1] <= 0.0 )
    magenta_green_transfer[1] = this->m_MidtonesSubTransfer;
  else
    magenta_green_transfer[1] = this->m_MidtonesAddTransfer;
  if ( this->m_MagentaGreenBalance[2] <= 0.0 )
    magenta_green_transfer[2] = this->m_HighlightsSubTransfer;
  else
    magenta_green_transfer[2] = this->m_HighlightsAddTransfer;
  if ( this->m_YellowBlueBalance[0] <= 0.0 )
    yellow_blue_transfer[0] = this->m_ShadowsSubTransfer;
  else
    yellow_blue_transfer[0] = this->m_ShadowsAddTransfer;
  if ( this->m_YellowBlueBalance[1] <= 0.0 )
    yellow_blue_transfer[1] = this->m_MidtonesSubTransfer;
  else
    yellow_blue_transfer[1] = this->m_MidtonesAddTransfer;
  if ( this->m_YellowBlueBalance[2] <= 0.0 )
    yellow_blue_transfer[2] = this->m_HighlightsSubTransfer;
  else
    yellow_blue_transfer[2] = this->m_HighlightsAddTransfer;
  v3 = 0;
  i = 0;
  do
  {
    m_MagentaGreenBalance = v1->m_MagentaGreenBalance;
    v5 = v3;
    v6 = v3;
    for ( j = 0; j <= 2; ++j )
    {
      v8 = (int)(float)((float)(cyan_red_transfer[j][v5] * *(m_MagentaGreenBalance - 3)) + (float)v5);
      v6 = (int)(float)((float)(magenta_green_transfer[j][v6] * *m_MagentaGreenBalance) + (float)v6);
      v9 = (int)(float)((float)(yellow_blue_transfer[j][v3] * m_MagentaGreenBalance[3]) + (float)v3);
      if ( v8 >= 0 )
      {
        v17 = 255;
        if ( v8 <= 255 )
          v17 = v8;
      }
      else
      {
        v17 = 0;
      }
      v5 = v17;
      if ( v6 >= 0 )
      {
        if ( v6 > 255 )
          v6 = 255;
      }
      else
      {
        v6 = 0;
      }
      v16 = v6;
      if ( v9 >= 0 )
      {
        if ( v9 > 255 )
          v9 = 255;
      }
      else
      {
        v9 = 0;
      }
      ++m_MagentaGreenBalance;
      v3 = v9;
    }
    v10 = i;
    v1 = v14;
    v14->m_pRedLookup[i] = v17;
    v1->m_pGreenLookup[v10] = v16;
    v1->m_pBlueLookup[v10] = v9;
    v3 = v10 + 1;
    i = v3;
  }
  while ( v3 < 256 );
}

//------------------------------------------------------------------------------
// Address: 0x100A3A30
// Name: public: virtual void CColorBalanceUIPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorBalanceUIPanel::OnCommand(CColorBalanceUIPanel *this, const char *command)
{
  float v3; // xmm0_4
  float commanda; // [esp+10h] [ebp+8h]

  vgui::Frame::OnCommand(this, command);
  if ( _V_stricmp(s1: "BlendFactorUpdate", s2: command) == 0 )
  {
    if ( this->m_pBalanceOp != nullptr )
    {
      commanda = this->m_pBalanceOp->GetBlendFactor(this: this->m_pBalanceOp);
      v3 = commanda;
    }
    else
    {
      v3 = 0.0;
    }
    this->m_pBlendFactorSlider->SetValue(this: this->m_pBlendFactorSlider, a2: (int)(float)(v3 * 255.0), a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A3AA0
// Name: private: virtual void CColorBalanceUIPanel::OnRadioButtonHit(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CColorBalanceUIPanel::OnRadioButtonHit(CColorBalanceUIPanel *this)
{
  CColorBalanceUIPanel::ResetSliders(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A3AB0
// Name: public: virtual struct vgui::PanelMessageMap __near * CLookupViewPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CLookupViewPanel::GetMessageMap(CLookupViewPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CLookupViewPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CLookupViewPanel::GetMessageMap'::`2'::s_pMap;
  `CLookupViewPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CLookupViewPanel");
  `CLookupViewPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A3AE0
// Name: public: virtual struct PanelAnimationMap __near * CLookupViewPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CLookupViewPanel::GetAnimMap(CLookupViewPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CLookupViewPanel");
}

//------------------------------------------------------------------------------
// Address: 0x100A3AF0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CLookupViewPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CLookupViewPanel::GetKBMap(CLookupViewPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CLookupViewPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CLookupViewPanel::GetKBMap'::`2'::s_pMap;
  `CLookupViewPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CLookupViewPanel");
  `CLookupViewPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A3B20
// Name: public: CLookupViewPanel::CLookupViewPanel(class vgui::Panel __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CLookupViewPanel *__thiscall CLookupViewPanel::CLookupViewPanel(
        CLookupViewPanel *this,
        vgui::Panel *parent,
        unsigned int CCHandle)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  CProceduralTexturePanel::CProceduralTexturePanel(this, pParent: parent, pName: "LookupViewPanel");
  this->CProceduralTexturePanel::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CLookupViewPanel_vtbl *)&CLookupViewPanel::`vftable'{for `vgui::EditablePanel'};
  this->CProceduralTexturePanel::ITextureRegenerator::__vftable = (ITextureRegenerator_vtbl *)&CLookupViewPanel::`vftable'{for `ITextureRegenerator'};
  if ( `CLookupViewPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CLookupViewPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CLookupViewPanel");
    v4->pfnClassName = CLookupViewPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CProceduralTexturePanel");
  }
  if ( `CLookupViewPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CLookupViewPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CLookupViewPanel");
    v5->pfnClassName = CLookupViewPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CProceduralTexturePanel");
  }
  if ( `CLookupViewPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CLookupViewPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CLookupViewPanel");
    v6->pfnClassName = CLookupViewPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CProceduralTexturePanel");
  }
  this->m_CCHandle = CCHandle;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A3C40
// Name: public: virtual void CLookupViewPanel::RegenerateTextureBits(class ITexture __near *,class IVTFTexture __near *,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CLookupViewPanel::RegenerateTextureBits(
        CLookupViewPanel *this,
        ITexture *pTexture,
        IVTFTexture *pVTFTexture,
        Rect_t *pRect)
{
  IVTFTexture *v4; // esi
  IVTFTexture_vtbl *v5; // eax
  int v6; // edx
  __int16 v7; // bx
  char v8; // al
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  unsigned int v12; // edx
  unsigned int v13; // edx
  int v14; // eax
  __int64 v15; // rax
  __int64 v16; // rax
  unsigned __int64 v17; // rdi
  int pixelWriter_4; // [esp+10h] [ebp-50h]
  unsigned __int8 pixelWriter_10; // [esp+16h] [ebp-4Ah]
  int pixelWriter_12; // [esp+18h] [ebp-48h]
  int pixelWriter_16; // [esp+1Ch] [ebp-44h]
  char pixelWriter_20; // [esp+20h] [ebp-40h]
  char pixelWriter_24; // [esp+24h] [ebp-3Ch]
  char pixelWriter_28; // [esp+28h] [ebp-38h]
  unsigned __int8 pixelWriter_32; // [esp+2Ch] [ebp-34h]
  int nWidth; // [esp+38h] [ebp-28h] BYREF
  int nHeight; // [esp+3Ch] [ebp-24h] BYREF
  int nDepth; // [esp+40h] [ebp-20h] BYREF
  CLookupViewPanel *v29; // [esp+44h] [ebp-1Ch]
  int v30; // [esp+48h] [ebp-18h]
  int v31; // [esp+4Ch] [ebp-14h]
  int inColor; // [esp+50h] [ebp-10h] OVERLAPPED
  int y; // [esp+54h] [ebp-Ch]
  int x; // [esp+58h] [ebp-8h]
  int v35; // [esp+5Ch] [ebp-4h]

  v4 = pVTFTexture;
  v5 = pVTFTexture->__vftable;
  v29 = this;
  v5->ComputeMipLevelDimensions(this: pVTFTexture, a2: 0, a3: &nWidth, a4: &nHeight, a5: &nDepth);
  v4->RowSizeInBytes(this: v4, a2: 0);
  pixelWriter_4 = (int)v4->ImageData_2(this: v4, a2: 0, a3: 0, a4: 0);
  switch ( v4->Format(this: v4) )
  {
    case IMAGE_FORMAT_RGBA8888:
    case IMAGE_FORMAT_UVWQ8888:
      pixelWriter_12 = 0x80000;
      v7 = 16;
      pixelWriter_16 = 1572880;
      goto LABEL_6;
    case IMAGE_FORMAT_BGR888:
      pixelWriter_10 = 3;
      pixelWriter_12 = 524304;
      pixelWriter_20 = -1;
      pixelWriter_24 = -1;
      pixelWriter_28 = -1;
      goto LABEL_20;
    case IMAGE_FORMAT_I8:
      pixelWriter_10 = 1;
      goto LABEL_18;
    case IMAGE_FORMAT_A8:
      pixelWriter_10 = 1;
      pixelWriter_12 = 0;
      v7 = 0;
      v6 = 0;
      pixelWriter_16 = 0;
      pixelWriter_20 = 0;
      pixelWriter_24 = 0;
      pixelWriter_28 = 0;
      pixelWriter_32 = -1;
      y = 0;
      v35 = 1;
      goto LABEL_22;
    case IMAGE_FORMAT_BGRA8888:
      pixelWriter_12 = 524304;
      v7 = 0;
      pixelWriter_16 = 1572864;
LABEL_6:
      pixelWriter_10 = 4;
      v8 = -1;
      goto LABEL_7;
    case IMAGE_FORMAT_BGRX8888:
      pixelWriter_10 = 4;
      v7 = 0;
      v6 = 0;
      pixelWriter_12 = 524304;
      pixelWriter_16 = 1572864;
      pixelWriter_20 = -1;
      pixelWriter_24 = -1;
      pixelWriter_28 = -1;
      pixelWriter_32 = 0;
      y = 0;
      v35 = 4;
      goto LABEL_22;
    case IMAGE_FORMAT_BGR565:
      pixelWriter_10 = 2;
      v6 = 0;
      pixelWriter_12 = 196616;
      v7 = -3;
      pixelWriter_16 = 65533;
      pixelWriter_20 = -8;
      pixelWriter_24 = -4;
      pixelWriter_28 = -8;
      pixelWriter_32 = 0;
      y = 0;
      v35 = 2;
      goto LABEL_22;
    case IMAGE_FORMAT_BGRX5551:
    case IMAGE_FORMAT_BGRA5551:
      pixelWriter_10 = 2;
      v6 = 0;
      pixelWriter_12 = 131079;
      v7 = -3;
      pixelWriter_16 = 589821;
      pixelWriter_20 = -8;
      pixelWriter_24 = -8;
      pixelWriter_28 = -8;
      pixelWriter_32 = 0x80;
      y = 0;
      v35 = 2;
      goto LABEL_22;
    case IMAGE_FORMAT_BGRA4444:
      pixelWriter_10 = 2;
      pixelWriter_12 = 4;
      v7 = -4;
      pixelWriter_16 = 589820;
      v8 = -16;
LABEL_7:
      v6 = 0;
      pixelWriter_20 = v8;
      pixelWriter_24 = v8;
      pixelWriter_28 = v8;
      pixelWriter_32 = v8;
      y = 0;
      v35 = pixelWriter_10;
      goto LABEL_22;
    case IMAGE_FORMAT_RGBA16161616F:
    case IMAGE_FORMAT_RGBA16161616:
      pixelWriter_10 = 8;
      v6 = 0;
      pixelWriter_12 = 0x100000;
      v7 = 32;
      pixelWriter_16 = 3145760;
      pixelWriter_20 = -1;
      pixelWriter_24 = -1;
      pixelWriter_28 = -1;
      pixelWriter_32 = -1;
      y = 0;
      v35 = 8;
      goto LABEL_22;
    case IMAGE_FORMAT_R32F:
      pixelWriter_10 = 4;
      pixelWriter_20 = -1;
      goto LABEL_19;
    case IMAGE_FORMAT_RGBA32323232F:
      pixelWriter_10 = 16;
      v6 = 0;
      pixelWriter_12 = 0x200000;
      v7 = 64;
      pixelWriter_16 = 6291520;
      pixelWriter_20 = -1;
      pixelWriter_24 = -1;
      pixelWriter_28 = -1;
      pixelWriter_32 = -1;
      y = 0;
      v35 = 16;
      goto LABEL_22;
    case IMAGE_FORMAT_BGRA1010102:
      pixelWriter_10 = 4;
      v7 = 0;
      v6 = 0;
      pixelWriter_12 = 655380;
      pixelWriter_16 = 1966080;
      pixelWriter_20 = -1;
      pixelWriter_24 = -1;
      pixelWriter_28 = -1;
      pixelWriter_32 = 3;
      y = 0;
      v35 = 4;
      goto LABEL_22;
    default:
      pixelWriter_10 = 0;
LABEL_18:
      pixelWriter_20 = -1;
LABEL_19:
      pixelWriter_12 = 0;
      pixelWriter_24 = 0;
      pixelWriter_28 = 0;
LABEL_20:
      v7 = 0;
      v6 = 0;
      pixelWriter_16 = 0;
      pixelWriter_32 = 0;
      y = 0;
      v35 = pixelWriter_10;
LABEL_22:
      while ( 1 )
      {
        v9 = 0;
        v10 = v6 & 0x1F;
        v11 = v6 >> 5;
        x = 0;
        v31 = v10;
        v30 = v11;
        while ( 1 )
        {
          LOWORD(inColor) = inColor & 0x8000
                          | ((unsigned __int8)(v9 >> 5) + 4 * (_BYTE)v11) & 0x1F
                          | (32 * (v9 & 0x1F | (32 * (v10 & 0x1F))));
          ((void (__thiscall *)(IColorCorrectionSystem *, IVTFTexture **, unsigned int, int))colorcorrection->GetLookup)(
            a1: colorcorrection,
            a2: &pVTFTexture,
            a3: v29->_vpanel,
            a4: inColor);
          if ( pixelWriter_10 != 0 )
          {
            if ( pixelWriter_10 >= 5u )
            {
              v15 = (unsigned __int8)(BYTE2(pVTFTexture) & pixelWriter_28);
              if ( v7 <= 0 )
                v16 = v15 >> -(char)v7;
              else
                v16 = v15 << v7;
              v17 = v16
                  | ((unsigned __int64)pixelWriter_32 << SBYTE2(pixelWriter_16))
                  | ((unsigned __int64)(unsigned __int8)((unsigned __int8)pVTFTexture & pixelWriter_20) << pixelWriter_12)
                  | ((unsigned __int64)(unsigned __int8)(BYTE1(pVTFTexture) & pixelWriter_24) << SBYTE2(pixelWriter_12));
              if ( v35 == 6 )
              {
                *(_DWORD *)pixelWriter_4 = v17;
                *(_WORD *)(pixelWriter_4 + 4) = WORD2(v17);
              }
              else if ( v35 == 8 )
              {
                *(_QWORD *)pixelWriter_4 = v17;
              }
            }
            else
            {
              v12 = (unsigned __int8)(BYTE2(pVTFTexture) & pixelWriter_28);
              if ( v7 <= 0 )
                v13 = v12 >> -(char)pixelWriter_16;
              else
                v13 = v12 << pixelWriter_16;
              v14 = v13
                  | (pixelWriter_32 << SBYTE2(pixelWriter_16))
                  | ((unsigned __int8)((unsigned __int8)pVTFTexture & pixelWriter_20) << pixelWriter_12)
                  | ((unsigned __int8)(BYTE1(pVTFTexture) & pixelWriter_24) << SBYTE2(pixelWriter_12));
              switch ( v35 )
              {
                case 1:
                  *(_BYTE *)pixelWriter_4 = v14;
                  break;
                case 2:
                  *(_WORD *)pixelWriter_4 = v14;
                  break;
                case 3:
                  *(_WORD *)pixelWriter_4 = v14;
                  *(_BYTE *)(pixelWriter_4 + 2) = BYTE2(v14);
                  break;
                case 4:
                  *(_DWORD *)pixelWriter_4 = v14;
                  break;
                default:
                  break;
              }
            }
          }
          pixelWriter_4 += v35;
          if ( ++x >= 128 )
            break;
          LOBYTE(v10) = v31;
          LOBYTE(v11) = v30;
          v9 = x;
        }
        if ( ++y >= 256 )
          return;
        v6 = y;
      }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A4130
// Name: public: virtual struct vgui::PanelMessageMap __near * CLookupViewWindow::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CLookupViewWindow::GetMessageMap(CLookupViewWindow *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CLookupViewWindow::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CLookupViewWindow::GetMessageMap'::`2'::s_pMap;
  `CLookupViewWindow::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CLookupViewWindow");
  `CLookupViewWindow::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A4160
// Name: public: virtual struct PanelAnimationMap __near * CLookupViewWindow::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CLookupViewWindow::GetAnimMap(CLookupViewWindow *this)
{
  return FindOrAddPanelAnimationMap(className: "CLookupViewWindow");
}

//------------------------------------------------------------------------------
// Address: 0x100A4170
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CLookupViewWindow::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CLookupViewWindow::GetKBMap(CLookupViewWindow *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CLookupViewWindow::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CLookupViewWindow::GetKBMap'::`2'::s_pMap;
  `CLookupViewWindow::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CLookupViewWindow");
  `CLookupViewWindow::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A41A0
// Name: public: CLookupViewWindow::CLookupViewWindow(class vgui::Panel __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CLookupViewWindow *__thiscall CLookupViewWindow::CLookupViewWindow(
        CLookupViewWindow *this,
        vgui::Panel *parent,
        unsigned int CCHandle)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CLookupViewPanel *v7; // eax
  CLookupViewPanel *v8; // eax

  vgui::Frame::Frame(this, parent, panelName: "LookupViewWindow", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CLookupViewWindow_vtbl *)&CLookupViewWindow::`vftable';
  if ( `CLookupViewWindow::ChainToMap'::`2'::chained == 0 )
  {
    `CLookupViewWindow::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CLookupViewWindow");
    v4->pfnClassName = CLookupViewWindow::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CLookupViewWindow::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CLookupViewWindow::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CLookupViewWindow");
    v5->pfnClassName = CLookupViewWindow::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CLookupViewWindow::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CLookupViewWindow::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CLookupViewWindow");
    v6->pfnClassName = CLookupViewWindow::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  vgui::Panel::SetSize(this, wide: 146, tall: 298);
  vgui::Panel::SetPos(this, x: 32, y: 32);
  v7 = (CLookupViewPanel *)MemAlloc_Alloc(nSize: 0x1C8u);
  if ( v7 != nullptr )
    v8 = CLookupViewPanel::CLookupViewPanel(this: v7, parent: this, CCHandle);
  else
    v8 = nullptr;
  this->m_pLookupPanel = v8;
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource\\LookupViewWindow.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  this->m_CCHandle = CCHandle;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A4300
// Name: public: virtual struct vgui::PanelMessageMap __near * CNewOperationDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CNewOperationDialog::GetMessageMap(CNewOperationDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CNewOperationDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CNewOperationDialog::GetMessageMap'::`2'::s_pMap;
  `CNewOperationDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CNewOperationDialog");
  `CNewOperationDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A4330
// Name: public: virtual struct PanelAnimationMap __near * CNewOperationDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CNewOperationDialog::GetAnimMap(CNewOperationDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CNewOperationDialog");
}

//------------------------------------------------------------------------------
// Address: 0x100A4340
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CNewOperationDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CNewOperationDialog::GetKBMap(CNewOperationDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CNewOperationDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CNewOperationDialog::GetKBMap'::`2'::s_pMap;
  `CNewOperationDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CNewOperationDialog");
  `CNewOperationDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A43A0
// Name: private: void CNewOperationDialog::PopulateControls(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewOperationDialog::PopulateControls(CNewOperationDialog *this)
{
  const char **v2; // esi

  vgui::ComboBox::RemoveAll(this: this->m_pOperationType);
  v2 = &s_pColorCorrectionToolNames[1];
  do
    this->m_pOperationType->AddItem_2(this: this->m_pOperationType, a2: *v2++, a3: nullptr);
  while ( (int)v2 < (int)s_pColorCorrectionDmxElementNames );
  this->m_pOperationType->AddActionSignalTarget_2(this: this->m_pOperationType, a2: this);
  this->m_pOperationType->ActivateItem(this: this->m_pOperationType, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100A4400
// Name: public: virtual struct vgui::PanelMessageMap __near * COperationListPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall COperationListPanel::GetMessageMap(COperationListPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`COperationListPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `COperationListPanel::GetMessageMap'::`2'::s_pMap;
  `COperationListPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "COperationListPanel");
  `COperationListPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A4430
// Name: public: virtual struct PanelAnimationMap __near * COperationListPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall COperationListPanel::GetAnimMap(COperationListPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "COperationListPanel");
}

//------------------------------------------------------------------------------
// Address: 0x100A4440
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * COperationListPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall COperationListPanel::GetKBMap(COperationListPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`COperationListPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `COperationListPanel::GetKBMap'::`2'::s_pMap;
  `COperationListPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "COperationListPanel");
  `COperationListPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A4580
// Name: public: virtual void COperationListPanel::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COperationListPanel::OnMouseDoublePressed(COperationListPanel *this, ButtonCode_t code)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  int v5; // edi
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  vgui::TextEntry *v9; // eax
  vgui::TextEntry *v10; // eax
  int x; // [esp+4h] [ebp-10h] BYREF
  int y; // [esp+8h] [ebp-Ch] BYREF
  int column; // [esp+Ch] [ebp-8h] BYREF
  int row; // [esp+10h] [ebp-4h] BYREF

  if ( code != KEY_COUNT )
  {
    vgui::ListPanel::OnMouseDoublePressed(this, code);
    return;
  }
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  this->GetCellAtPos(this, a2: x, a3: y, a4: &row, a5: &column);
  if ( column != 0 && row == -1 )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
    {
      v4 = KeyValues::KeyValues(this: v3, setName: "Command", firstKey: "Command", firstValue: "NewOperation");
LABEL_7:
      this->PostActionSignal(this, a2: v4);
      return;
    }
LABEL_8:
    this->PostActionSignal(this, a2: nullptr);
    return;
  }
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL) )
  {
    if ( this->m_pNameEditPanel == nullptr )
    {
      this->m_nEditItem = this->GetItemIDFromRow(this, a2: row);
      v9 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
      if ( v9 != nullptr )
        v10 = vgui::TextEntry::TextEntry(this: v9, parent: this, panelName: "Name");
      else
        v10 = nullptr;
      this->m_pNameEditPanel = v10;
      v10->SendNewLine(this: v10, a2: true);
      this->m_pNameEditPanel->SetCatchEnterKey(this: this->m_pNameEditPanel, a2: true);
      this->m_pNameEditPanel->AddActionSignalTarget_2(this: this->m_pNameEditPanel, a2: this);
      vgui::Panel::SetSize(this: this->m_pNameEditPanel, wide: 226, tall: 24);
      ((void (__thiscall *)(vgui::TextEntry *, int))this->m_pNameEditPanel->SetBgColor)(
        a1: this->m_pNameEditPanel,
        a2: -1);
      this->EnterEditMode(this, a2: row, a3: column, a4: this->m_pNameEditPanel);
    }
  }
  else
  {
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LALT)
      || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RALT) )
    {
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
      {
        v4 = KeyValues::KeyValues(this: v8, setName: "Command", firstKey: "Command", firstValue: "CloneOperation");
        goto LABEL_7;
      }
      goto LABEL_8;
    }
    v5 = this->GetSelectedItem(this, a2: 0);
    if ( v5 < 0 )
    {
      vgui::ListPanel::OnMouseDoublePressed(this, code: KEY_COUNT);
    }
    else
    {
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "LaunchOperation", firstKey: "item", firstValue: v5);
      else
        v7 = nullptr;
      this->PostActionSignal(this, a2: v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A47C0
// Name: public: virtual struct vgui::PanelMessageMap __near * CColorCorrectionUIPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CColorCorrectionUIPanel::GetMessageMap(CColorCorrectionUIPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CColorCorrectionUIPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorCorrectionUIPanel::GetMessageMap'::`2'::s_pMap;
  `CColorCorrectionUIPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CColorCorrectionUIPanel");
  `CColorCorrectionUIPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A47F0
// Name: public: virtual struct PanelAnimationMap __near * CColorCorrectionUIPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CColorCorrectionUIPanel::GetAnimMap(CColorCorrectionUIPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CColorCorrectionUIPanel");
}

//------------------------------------------------------------------------------
// Address: 0x100A4800
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CColorCorrectionUIPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CColorCorrectionUIPanel::GetKBMap(CColorCorrectionUIPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CColorCorrectionUIPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorCorrectionUIPanel::GetKBMap'::`2'::s_pMap;
  `CColorCorrectionUIPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CColorCorrectionUIPanel");
  `CColorCorrectionUIPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A4870
// Name: public: void CColorOperationList::Apply(struct color24,struct color24 __near &,class IColorOperation __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorOperationList::Apply(
        CColorOperationList *this,
        color24 in,
        color24 *out,
        IColorOperation *pFinalOp)
{
  int m_Size; // edi
  int v6; // esi
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  int v10; // eax
  float v11; // xmm1_4
  float v12; // xmm2_4
  int v13; // ecx
  int v14; // edx
  int v15; // eax
  int v16; // eax
  Vector temp; // [esp+8h] [ebp-18h] BYREF
  Vector rgb; // [esp+14h] [ebp-Ch] BYREF

  m_Size = this->m_OpList.m_Size;
  if ( m_Size != 0 )
  {
    v6 = 0;
    x = (float)in.r * 0.0039215689;
    y = (float)in.g * 0.0039215689;
    z = (float)in.b * 0.0039215689;
    rgb.x = x;
    rgb.y = y;
    for ( rgb.z = z; v6 < m_Size; rgb = temp )
    {
      if ( this->m_OpList.m_Memory.m_pMemory[v6] == pFinalOp )
        break;
      this->m_OpList.m_Memory.m_pMemory[v6]->Apply(this: this->m_OpList.m_Memory.m_pMemory[v6], a2: &rgb, a3: &temp);
      x = temp.x;
      y = temp.y;
      z = temp.z;
      ++v6;
    }
    v10 = (int)(float)((float)(x * 255.0) + 0.5);
    v11 = (float)(y * 255.0) + 0.5;
    v12 = (float)(z * 255.0) + 0.5;
    v13 = (int)v11;
    v14 = (int)v12;
    if ( v10 >= 0 )
    {
      if ( v10 > 255 )
        LOBYTE(v10) = -1;
    }
    else
    {
      LOBYTE(v10) = 0;
    }
    out->r = v10;
    if ( v13 >= 0 )
    {
      LOBYTE(v15) = -1;
      if ( v13 <= 255 )
        v15 = (int)v11;
    }
    else
    {
      LOBYTE(v15) = 0;
    }
    out->g = v15;
    if ( v14 >= 0 )
    {
      LOBYTE(v16) = -1;
      if ( v14 <= 255 )
        v16 = (int)v12;
      out->b = v16;
    }
    else
    {
      out->b = 0;
    }
  }
  else
  {
    *out = in;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A49C0
// Name: public: class IColorOperation __near * CColorOperationList::GetOperation(int)
// Source: json
//------------------------------------------------------------------------------
IColorOperation *__thiscall CColorOperationList::GetOperation(CColorOperationList *this, int opIndex)
{
  if ( opIndex >= 0 && opIndex < this->m_OpList.m_Size )
    return this->m_OpList.m_Memory.m_pMemory[opIndex];
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100A49E0
// Name: public: int CCurvesColorOperation::FindControlPoint(float,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCurvesColorOperation::FindControlPoint(CCurvesColorOperation *this, float flInValue, float flTolerance)
{
  int v3; // edx
  Vector *i; // ecx

  v3 = this->m_ControlPoints.m_Size - 1;
  if ( v3 < 0 )
    return -1;
  for ( i = &this->m_ControlPoints.m_Memory.m_pMemory[v3]; flTolerance <= fabs(i->x - flInValue); --i )
  {
    if ( --v3 < 0 )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100A4A30
// Name: protected: virtual int CColorCurvesEditPanel::FindControlPoint(float,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CColorCurvesEditPanel::FindControlPoint(CColorCurvesEditPanel *this, float flIn, float flTolerance)
{
  return CCurvesColorOperation::FindControlPoint(this: this->m_pCurvesOp, flInValue: flIn, flTolerance);
}

//------------------------------------------------------------------------------
// Address: 0x100A4A60
// Name: protected: virtual void CColorCurvesEditPanel::GetControlPoint(int,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCurvesEditPanel::GetControlPoint(
        CColorCurvesEditPanel *this,
        int nPoint,
        float *pIn,
        float *pOut)
{
  Vector *v4; // eax

  v4 = &this->m_pCurvesOp->m_ControlPoints.m_Memory.m_pMemory[nPoint];
  *pIn = v4->x;
  *pOut = v4->y;
}

//------------------------------------------------------------------------------
// Address: 0x100A4A90
// Name: public: CLevelsColorOperation::CLevelsColorOperation(class CColorOperationList __near *)
// Source: json
//------------------------------------------------------------------------------
CLevelsColorOperation *__thiscall CLevelsColorOperation::CLevelsColorOperation(
        CLevelsColorOperation *this,
        CColorOperationList *pList)
{
  this->m_flMidInputLevel = 0.5;
  this->__vftable = (CLevelsColorOperation_vtbl *)&CLevelsColorOperation::`vftable';
  this->m_pOpList = pList;
  this->m_flMinInputLevel = 0.0;
  this->m_flMaxInputLevel = 1.0;
  this->m_flMinOutputLevel = 0.0;
  this->m_flMaxOutputLevel = 1.0;
  this->m_flBlendFactor = 1.0;
  this->m_nChannelMask = 7;
  this->m_bEnable = true;
  CLevelsColorOperation::UpdateOutputLevelArray(this);
  _V_strcpy(dest: this->m_pName, src: "Levels");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A4B20
// Name: public: virtual void CLevelsColorOperation::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLevelsColorOperation::Release(CLevelsColorOperation *this)
{
  free(pMem: this);
}

//------------------------------------------------------------------------------
// Address: 0x100A4B40
// Name: public: virtual void CLevelsColorOperation::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLevelsColorOperation::SetName(CLevelsColorOperation *this, const char *pName)
{
  _V_strcpy(dest: this->m_pName, src: pName);
}

//------------------------------------------------------------------------------
// Address: 0x100A4B80
// Name: public: virtual float CLevelsColorOperation::GetBlendFactor(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CLevelsColorOperation::GetBlendFactor(CLevelsColorOperation *this)
{
  return this->m_flBlendFactor;
}

//------------------------------------------------------------------------------
// Address: 0x100A4B90
// Name: public: void CLevelsColorOperation::SetInputLevels(float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLevelsColorOperation::SetInputLevels(
        CLevelsColorOperation *this,
        float flMinValue,
        float flMidValue,
        float flMaxValue)
{
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm0_4

  v4 = 0.0;
  v5 = flMinValue;
  if ( flMinValue >= 0.0 )
  {
    if ( flMinValue > 1.0 )
      v5 = 1.0;
  }
  else
  {
    v5 = 0.0;
  }
  this->m_flMinInputLevel = v5;
  v6 = flMidValue;
  if ( flMidValue >= 0.0 )
  {
    if ( flMidValue > 1.0 )
      v6 = 1.0;
  }
  else
  {
    v6 = 0.0;
  }
  this->m_flMidInputLevel = v6;
  if ( flMaxValue >= 0.0 )
  {
    if ( flMaxValue <= 1.0 )
      v4 = flMaxValue;
    else
      v4 = 1.0;
  }
  this->m_flMaxInputLevel = v4;
  CLevelsColorOperation::UpdateOutputLevelArray(this);
  colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
}

//------------------------------------------------------------------------------
// Address: 0x100A4C20
// Name: public: void CLevelsColorOperation::SetOutputLevels(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLevelsColorOperation::SetOutputLevels(CLevelsColorOperation *this, float flMinValue, float flMaxValue)
{
  float v3; // xmm0_4
  float v4; // xmm0_4

  v3 = flMinValue;
  if ( flMinValue >= 0.0 )
  {
    if ( flMinValue > 1.0 )
      v3 = 1.0;
  }
  else
  {
    v3 = 0.0;
  }
  this->m_flMinOutputLevel = v3;
  v4 = flMaxValue;
  if ( flMaxValue >= 0.0 )
  {
    if ( flMaxValue > 1.0 )
      v4 = 1.0;
  }
  else
  {
    v4 = 0.0;
  }
  this->m_flMaxOutputLevel = v4;
  CLevelsColorOperation::UpdateOutputLevelArray(this);
  colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
}

//------------------------------------------------------------------------------
// Address: 0x100A4C90
// Name: public: virtual class IColorOperation __near * CLevelsColorOperation::Clone(void)
// Source: json
//------------------------------------------------------------------------------
CLevelsColorOperation *__thiscall CLevelsColorOperation::Clone(CLevelsColorOperation *this)
{
  CLevelsColorOperation *v2; // eax
  CLevelsColorOperation *v3; // esi
  double m_flMinInputLevel; // st7
  char *m_pName; // edi

  v2 = (CLevelsColorOperation *)MemAlloc_Alloc(nSize: 0x528u);
  if ( v2 != nullptr )
    v3 = CLevelsColorOperation::CLevelsColorOperation(this: v2, pList: this->m_pOpList);
  else
    v3 = nullptr;
  _V_memcpy(dest: v3->m_pOutValue, src: this->m_pOutValue, count: 1024);
  v3->m_nChannelMask = this->m_nChannelMask;
  v3->m_flBlendFactor = this->m_flBlendFactor;
  m_flMinInputLevel = this->m_flMinInputLevel;
  m_pName = this->m_pName;
  v3->m_flMinInputLevel = m_flMinInputLevel;
  v3->m_flMidInputLevel = *(float *)(m_pName - 17);
  v3->m_flMaxInputLevel = *(float *)(m_pName - 13);
  v3->m_flMinOutputLevel = *(float *)(m_pName - 9);
  v3->m_flMaxOutputLevel = *(float *)(m_pName - 5);
  v3->m_bEnable = *(m_pName - 1);
  _V_memcpy(dest: v3->m_pName, src: m_pName, count: 256);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100A4D40
// Name: public: void CColorHistogramPanel::ComputeHistogram(struct Rect_t __near &,unsigned char __near *,enum ImageFormat,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorHistogramPanel::ComputeHistogram(
        CColorHistogramPanel *this,
        Rect_t *srcRect,
        unsigned __int8 *pBits,
        ImageFormat format,
        int nStride)
{
  ImageFormat v5; // esi
  Rect_t *v6; // edi
  int m_nNumBytes; // eax
  unsigned __int8 *v8; // ecx
  char v9; // bl
  int v10; // eax
  int v11; // eax
  int v12; // edx
  int v13; // esi
  int v14; // eax
  int v15; // edx
  char v16; // cl
  unsigned __int8 v17; // dl
  float *v18; // esi
  int v19; // eax
  float v20; // xmm1_4
  float *v21; // eax
  int i; // edx
  float v23; // xmm0_4
  float v24; // xmm0_4
  float v25; // xmm0_4
  float v26; // xmm0_4
  color24 v27; // [esp-Ch] [ebp-54h]
  unsigned __int8 *writer_4; // [esp+10h] [ebp-38h]
  char writer_12; // [esp+18h] [ebp-30h]
  char writer_14; // [esp+1Ah] [ebp-2Eh]
  char writer_16; // [esp+1Ch] [ebp-2Ch]
  int writer_20; // [esp+20h] [ebp-28h]
  int writer_24; // [esp+24h] [ebp-24h]
  int writer_28; // [esp+28h] [ebp-20h]
  int nPixelCount; // [esp+30h] [ebp-18h]
  int v36; // [esp+34h] [ebp-14h]
  int nSizeInBytes; // [esp+38h] [ebp-10h]
  unsigned __int8 *v39; // [esp+40h] [ebp-8h]
  int y; // [esp+44h] [ebp-4h]
  int x; // [esp+54h] [ebp+Ch]

  v5 = format;
  memset(this->m_pHistogram, 0, sizeof(this->m_pHistogram));
  v6 = srcRect;
  nPixelCount = srcRect->width * srcRect->height;
  m_nNumBytes = ImageLoader::ImageFormatInfo(fmt: v5)->m_nNumBytes;
  v8 = &pBits[nStride * v6->y + m_nNumBytes * v6->x];
  nSizeInBytes = m_nNumBytes;
  switch ( v5 )
  {
    case IMAGE_FORMAT_RGBA8888:
    case IMAGE_FORMAT_UVWQ8888:
      writer_12 = 0;
      writer_14 = 8;
      writer_16 = 16;
      v10 = 255;
      v9 = 4;
      writer_20 = 255;
      goto LABEL_17;
    case IMAGE_FORMAT_BGR888:
      writer_12 = 16;
      writer_14 = 8;
      writer_16 = 0;
      v10 = 255;
      v9 = 3;
      writer_20 = 255;
      goto LABEL_17;
    case IMAGE_FORMAT_I8:
      v9 = 1;
      goto LABEL_15;
    case IMAGE_FORMAT_A8:
      v10 = 0;
      v9 = 1;
      writer_12 = 0;
      writer_14 = 0;
      writer_16 = 0;
      writer_20 = 0;
      goto LABEL_17;
    case IMAGE_FORMAT_BGRA8888:
    case IMAGE_FORMAT_BGRX8888:
      writer_12 = 16;
      writer_14 = 8;
      writer_16 = 0;
      v10 = 255;
      v9 = 4;
      writer_20 = 255;
      goto LABEL_17;
    case IMAGE_FORMAT_BGR565:
      writer_12 = 8;
      writer_14 = 3;
      writer_16 = -3;
      v10 = 248;
      v9 = 2;
      writer_20 = 248;
      writer_24 = 252;
      goto LABEL_18;
    case IMAGE_FORMAT_BGRX5551:
    case IMAGE_FORMAT_BGRA5551:
      writer_12 = 7;
      writer_14 = 2;
      writer_16 = -3;
      v10 = 248;
      v9 = 2;
      writer_20 = 248;
      goto LABEL_17;
    case IMAGE_FORMAT_BGRA4444:
      writer_12 = 4;
      writer_14 = 0;
      writer_16 = -4;
      v10 = 240;
      v9 = 2;
      writer_20 = 240;
      goto LABEL_17;
    case IMAGE_FORMAT_RGBA16161616F:
    case IMAGE_FORMAT_RGBA16161616:
      writer_12 = 0;
      writer_14 = 16;
      writer_16 = 32;
      v10 = 0xFFFF;
      v9 = 8;
      writer_20 = 0xFFFF;
      goto LABEL_17;
    case IMAGE_FORMAT_R32F:
      v9 = 4;
      writer_20 = -1;
      goto LABEL_16;
    case IMAGE_FORMAT_RGBA32323232F:
      writer_12 = 0;
      writer_14 = 32;
      writer_16 = 64;
      v10 = -1;
      v9 = 16;
      writer_20 = -1;
      goto LABEL_17;
    case IMAGE_FORMAT_BGRA1010102:
      writer_12 = 20;
      writer_14 = 10;
      writer_16 = 0;
      v10 = 1023;
      v9 = 4;
      writer_20 = 1023;
      goto LABEL_17;
    default:
      v9 = 0;
LABEL_15:
      writer_20 = 255;
LABEL_16:
      v10 = 0;
      writer_12 = 0;
      writer_14 = 0;
      writer_16 = 0;
LABEL_17:
      writer_24 = v10;
LABEL_18:
      writer_28 = v10;
      y = 0;
      if ( srcRect->height > 0 )
      {
        v36 = (unsigned __int16)nStride;
        v39 = v8;
        do
        {
          writer_4 = v8;
          x = 0;
          if ( v6->width > 0 )
          {
            do
            {
              v11 = *v8;
              if ( (unsigned __int8)v9 > 1u )
              {
                v11 = *(unsigned __int16 *)v8;
                if ( (unsigned __int8)v9 > 2u )
                {
                  v11 |= v8[2] << 16;
                  if ( (unsigned __int8)v9 > 3u )
                    v11 |= v8[3] << 24;
                }
              }
              v12 = v11 >> writer_12;
              v13 = writer_24 & (v11 >> writer_14);
              v14 = writer_28 & (v11 >> writer_16);
              v15 = writer_20 & v12;
              if ( v15 >= 0 )
              {
                if ( v15 > 255 )
                  LOBYTE(v15) = -1;
              }
              else
              {
                LOBYTE(v15) = 0;
              }
              LOBYTE(nStride) = v15;
              if ( v13 >= 0 )
              {
                v16 = -1;
                if ( v13 <= 255 )
                  v16 = v13;
              }
              else
              {
                v16 = 0;
              }
              BYTE1(nStride) = v16;
              if ( v14 >= 0 )
              {
                v17 = -1;
                if ( v14 <= 255 )
                  v17 = v14;
              }
              else
              {
                v17 = 0;
              }
              *(_WORD *)&v27.r = nStride;
              v27.b = v17;
              CColorOperationList::Apply(
                this: this->m_pOp->m_pOpList,
                in: v27,
                out: (color24 *)&format,
                pFinalOp: this->m_pOp);
              switch ( this->m_Type )
              {
                case 0:
                  v18 = &this->m_pHistogram[(unsigned __int8)format];
                  goto LABEL_39;
                case 1:
                  v18 = &this->m_pHistogram[BYTE1(format)];
                  goto LABEL_39;
                case 2:
                  v18 = &this->m_pHistogram[BYTE2(format)];
LABEL_39:
                  *v18 = *v18 + 1.0;
                  break;
                case 3:
                  v19 = (int)(float)((float)((float)((float)((float)BYTE1(format) * 0.58700001)
                                                   + (float)((float)(unsigned __int8)format * 0.29899999))
                                           + (float)((float)BYTE2(format) * 0.114))
                                   + 0.5);
                  if ( v19 >= 0 )
                  {
                    if ( v19 > 255 )
                      v19 = 255;
                  }
                  else
                  {
                    v19 = 0;
                  }
                  this->m_pHistogram[v19] = this->m_pHistogram[v19] + 1.0;
                  break;
                default:
                  break;
              }
              v8 = &writer_4[nSizeInBytes];
              v6 = srcRect;
              writer_4 += nSizeInBytes;
              ++x;
            }
            while ( x < srcRect->width );
          }
          v8 = &v39[v36];
          ++y;
          v39 += v36;
        }
        while ( y < v6->height );
      }
      this->m_flMax = 0.0;
      v20 = 1.0 / (float)nPixelCount;
      v21 = &this->m_pHistogram[1];
      for ( i = 64; i != 0; --i )
      {
        v23 = v20 * *(v21 - 1);
        *(v21 - 1) = v23;
        if ( v23 > this->m_flMax )
          this->m_flMax = v23;
        v24 = v20 * *v21;
        *v21 = v24;
        if ( v24 > this->m_flMax )
          this->m_flMax = v24;
        v25 = v20 * v21[1];
        v21[1] = v25;
        if ( v25 > this->m_flMax )
          this->m_flMax = v25;
        v26 = v20 * v21[2];
        v21[2] = v26;
        if ( v26 > this->m_flMax )
          this->m_flMax = v26;
        v21 += 4;
      }
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A5270
// Name: public: virtual void CColorLevelsUIPanel::ReadUncorrectedImage(struct Rect_t __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorLevelsUIPanel::ReadUncorrectedImage(
        CColorLevelsUIPanel *this,
        Rect_t *pSrcRect,
        unsigned __int8 *pPreviewImage)
{
  CColorHistogramPanel *m_pHistogramPanel; // ecx
  Rect_t dstRect; // [esp+0h] [ebp-10h] BYREF

  m_pHistogramPanel = this->m_pHistogramPanel;
  dstRect.x = 0;
  dstRect.y = 0;
  dstRect.width = 128;
  dstRect.height = 96;
  CColorHistogramPanel::ComputeHistogram(
    this: m_pHistogramPanel,
    srcRect: &dstRect,
    pBits: pPreviewImage,
    format: IMAGE_FORMAT_BGRX8888,
    nStride: 512);
}

//------------------------------------------------------------------------------
// Address: 0x100A52B0
// Name: public: virtual void CColorLevelsUIPanel::OnMessage(class KeyValues const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorLevelsUIPanel::OnMessage(CColorLevelsUIPanel *this, KeyValues *params, unsigned int fromPanel)
{
  const char *Name; // eax
  CColorSlider *Ptr; // eax
  CLevelsColorOperation_vtbl *v6; // edi
  float v7; // xmm0_4
  KeyValues *v8; // eax
  KeyValues *v9; // eax
  CColorLevelsUIPanel_vtbl *v10; // edi
  int v11; // eax
  CColorSlider *m_pInputLevelSlider; // eax
  int m_nMinValue; // ecx
  CColorSlider *m_pOutputLevelSlider; // eax

  vgui::Panel::OnMessage(this, params, ifromPanel: fromPanel);
  Name = KeyValues::GetName(this: params);
  if ( _V_stricmp(s1: "SliderMoved", s2: Name) == 0 )
  {
    Ptr = (CColorSlider *)KeyValues::GetPtr(this: params, keyName: "panel", defaultValue: nullptr);
    if ( Ptr == (CColorSlider *)this->m_pBlendFactorSlider )
    {
      v6 = this->m_pLevelsOp->__vftable;
      v7 = (float)this->m_pBlendFactorSlider->GetValue(this: this->m_pBlendFactorSlider) * 0.0039215689;
      ((void (__thiscall *)(CLevelsColorOperation *, _DWORD))v6->SetBlendFactor)(a1: this->m_pLevelsOp, a2: LODWORD(v7));
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
        v9 = KeyValues::KeyValues(this: v8, setName: "command", firstKey: "command", firstValue: "BlendFactorUpdate");
      else
        v9 = nullptr;
      v10 = this->__vftable;
      v11 = ((int (__thiscall *)(CColorLevelsUIPanel *, KeyValues *, _DWORD))this->GetParent)(a1: this, a2: v9, a3: 0.0);
      ((void (__thiscall *)(CColorLevelsUIPanel *, int))v10->PostMessage)(a1: this, a2: v11);
    }
    else if ( Ptr == this->m_pInputLevelSlider )
    {
      m_pInputLevelSlider = this->m_pInputLevelSlider;
      m_nMinValue = m_pInputLevelSlider->m_nMinValue;
      CLevelsColorOperation::SetInputLevels(
        this: this->m_pLevelsOp,
        flMinValue: (float)(int)(float)((float)((float)(m_pInputLevelSlider->m_nMaxValue - m_nMinValue)
                                  * m_pInputLevelSlider->m_flKnobPosition[0])
                          + (float)m_nMinValue)
      * 0.0039215689,
        flMidValue: (float)(int)(float)((float)((float)(m_pInputLevelSlider->m_nMaxValue - m_nMinValue)
                                  * m_pInputLevelSlider->m_flKnobPosition[2])
                          + (float)m_nMinValue)
      * 0.0039215689,
        flMaxValue: (float)(int)(float)((float)((float)(m_pInputLevelSlider->m_nMaxValue - m_nMinValue)
                                  * m_pInputLevelSlider->m_flKnobPosition[1])
                          + (float)m_nMinValue)
      * 0.0039215689);
    }
    else if ( Ptr == this->m_pOutputLevelSlider )
    {
      m_pOutputLevelSlider = this->m_pOutputLevelSlider;
      CLevelsColorOperation::SetOutputLevels(
        this: this->m_pLevelsOp,
        flMinValue: (float)(int)(float)((float)((float)(m_pOutputLevelSlider->m_nMaxValue - m_pOutputLevelSlider->m_nMinValue)
                                  * m_pOutputLevelSlider->m_flKnobPosition[0])
                          + (float)m_pOutputLevelSlider->m_nMinValue)
      * 0.0039215689,
        flMaxValue: (float)(int)(float)((float)((float)(m_pOutputLevelSlider->m_nMaxValue - m_pOutputLevelSlider->m_nMinValue)
                                  * m_pOutputLevelSlider->m_flKnobPosition[1])
                          + (float)m_pOutputLevelSlider->m_nMinValue)
      * 0.0039215689);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A5500
// Name: public: float CSelectedHSVOperation::GetSelectionAmount(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
double __userpurge CSelectedHSVOperation::GetSelectionAmount@<st0>(
        CSelectedHSVOperation *this@<ecx>,
        float a2@<ebp>,
        const Vector *rgb)
{
  CSelectedHSVOperation::SelectionMethod_t m_SelectionMethod; // eax
  int v6; // edi
  float v7; // xmm0_4
  float m_Fuzziness; // xmm4_4
  Vector *m_pMemory; // eax
  float v10; // xmm0_4
  double v11; // st7
  Vector *v12; // eax
  double v13; // st7
  Vector *v14; // eax
  float v15; // xmm1_4
  Vector *v16; // eax
  long double v17; // st7
  double v18; // st7
  Vector *v19; // eax
  double v20; // st7
  Vector *v21; // eax
  float v22; // xmm1_4
  Vector *v23; // eax
  long double v24; // st7
  double v25; // st7
  Vector *v26; // eax
  double v27; // st7
  Vector *v28; // eax
  Vector *v29; // eax
  float x; // xmm0_4
  float v31; // xmm3_4
  float v32; // xmm2_4
  float a; // [esp+0h] [ebp-68h]
  float aa; // [esp+0h] [ebp-68h]
  float b; // [esp+4h] [ebp-64h]
  float fuzzinessa; // [esp+8h] [ebp-60h]
  float fuzzinessb; // [esp+8h] [ebp-60h]
  float fuzzinessc; // [esp+8h] [ebp-60h]
  float fuzzinessd; // [esp+8h] [ebp-60h]
  float fuzziness; // [esp+8h] [ebp-60h]
  float fuzzinesse; // [esp+8h] [ebp-60h]
  float fuzzinessf; // [esp+8h] [ebp-60h]
  Vector v43; // [esp+30h] [ebp-38h] BYREF
  Vector hsv; // [esp+3Ch] [ebp-2Ch]
  float m_Tolerance; // [esp+48h] [ebp-20h]
  int v46; // [esp+4Ch] [ebp-1Ch]
  float v47; // [esp+50h] [ebp-18h]
  float j; // [esp+54h] [ebp-14h]
  int i; // [esp+58h] [ebp-10h]
  float flSelAmount; // [esp+5Ch] [ebp-Ch]
  void *v51; // [esp+60h] [ebp-8h]
  void *retaddr; // [esp+68h] [ebp+0h]

  flSelAmount = a2;
  v51 = retaddr;
  m_SelectionMethod = this->m_SelectionMethod;
  if ( m_SelectionMethod == SELECT_ALL )
    return 1.0;
  v6 = 0;
  if ( m_SelectionMethod == SELECT_NONE )
    return 0.0;
  v7 = 0.0;
  v47 = 0.0;
  v46 = 0;
  if ( this->m_SelectedRGBs.m_Size > 0 )
  {
    m_Fuzziness = this->m_Fuzziness;
    for ( j = m_Fuzziness; ; m_Fuzziness = j )
    {
      switch ( this->m_SelectionMethod )
      {
        case SELECT_LESSER_RED:
          *(float *)&i = FuzzyLessThan(a: rgb->x, b: this->m_SelectedRGBs.m_Memory.m_pMemory[v6].x, fuzziness: j);
          break;
        case SELECT_GREATER_GREEN:
          *(float *)&i = FuzzyGreaterThan(a: rgb->y, b: this->m_SelectedRGBs.m_Memory.m_pMemory[v6].y, fuzziness: j);
          break;
        case SELECT_LESSER_GREEN:
          *(float *)&i = FuzzyLessThan(a: rgb->y, b: this->m_SelectedRGBs.m_Memory.m_pMemory[v6].y, fuzziness: j);
          break;
        case SELECT_GREATER_BLUE:
          *(float *)&i = FuzzyGreaterThan(a: rgb->z, b: this->m_SelectedRGBs.m_Memory.m_pMemory[v6].z, fuzziness: j);
          break;
        case SELECT_LESSER_BLUE:
          *(float *)&i = FuzzyLessThan(a: rgb->z, b: this->m_SelectedRGBs.m_Memory.m_pMemory[v6].z, fuzziness: j);
          break;
        case SELECT_NEARBY_RGB:
          m_pMemory = this->m_SelectedRGBs.m_Memory.m_pMemory;
          v10 = fsqrt(
                  (float)((float)((float)(rgb->y - m_pMemory[v6].y) * (float)(rgb->y - m_pMemory[v6].y))
                        + (float)((float)(rgb->z - m_pMemory[v6].z) * (float)(rgb->z - m_pMemory[v6].z)))
                + (float)((float)(rgb->x - m_pMemory[v6].x) * (float)(rgb->x - m_pMemory[v6].x)));
          m_Tolerance = this->m_Tolerance;
          *(float *)&i = FuzzyLessThan(a: v10, b: m_Tolerance, fuzziness: m_Tolerance * m_Fuzziness);
          break;
        case SELECT_GREATER_HUE:
          RGBtoHSV(rgb, hsv: &v43);
          v11 = this->m_Fuzziness;
          v12 = this->m_SelectedHSVs.m_Memory.m_pMemory;
          j = this->m_Fuzziness;
          fuzzinessa = v11;
          *(float *)&i = FuzzyGreaterThan(a: v43.x, b: v12[v6].x, fuzziness: fuzzinessa);
          break;
        case SELECT_LESSER_HUE:
          RGBtoHSV(rgb, hsv: &v43);
          v13 = this->m_Fuzziness;
          v14 = this->m_SelectedHSVs.m_Memory.m_pMemory;
          j = this->m_Fuzziness;
          fuzzinessb = v13;
          *(float *)&i = FuzzyLessThan(a: v43.x, b: v14[v6].x, fuzziness: fuzzinessb);
          break;
        case SELECT_NEARBY_HUE:
          RGBtoHSV(rgb, hsv: &v43);
          v15 = this->m_Fuzziness;
          v16 = this->m_SelectedHSVs.m_Memory.m_pMemory;
          hsv.z = this->m_Tolerance;
          v17 = v43.x - v16[v6].x;
          j = v15;
          a = fabs(v17) * 0.0027777778;
          *(float *)&i = FuzzyLessThan(a, b: hsv.z, fuzziness: hsv.z * v15);
          break;
        case SELECT_GREATER_SATURATION:
          RGBtoHSV(rgb, hsv: &v43);
          v18 = this->m_Fuzziness;
          v19 = this->m_SelectedHSVs.m_Memory.m_pMemory;
          j = this->m_Fuzziness;
          fuzzinessc = v18;
          *(float *)&i = FuzzyGreaterThan(a: v43.y, b: v19[v6].y, fuzziness: fuzzinessc);
          break;
        case SELECT_LESSER_SATURATION:
          RGBtoHSV(rgb, hsv: &v43);
          v20 = this->m_Fuzziness;
          v21 = this->m_SelectedHSVs.m_Memory.m_pMemory;
          j = this->m_Fuzziness;
          fuzzinessd = v20;
          *(float *)&i = FuzzyLessThan(a: v43.y, b: v21[v6].y, fuzziness: fuzzinessd);
          break;
        case SELECT_NEARBY_SATURATION:
          RGBtoHSV(rgb, hsv: &v43);
          v22 = this->m_Fuzziness;
          v23 = this->m_SelectedHSVs.m_Memory.m_pMemory;
          hsv.y = this->m_Tolerance;
          fuzziness = hsv.y * v22;
          b = hsv.y;
          v24 = v43.y - v23[v6].y;
          goto LABEL_21;
        case SELECT_GREATER_VALUE:
          RGBtoHSV(rgb, hsv: &v43);
          v25 = this->m_Fuzziness;
          v26 = this->m_SelectedHSVs.m_Memory.m_pMemory;
          j = this->m_Fuzziness;
          fuzzinesse = v25;
          *(float *)&i = FuzzyGreaterThan(a: v43.z, b: v26[v6].z, fuzziness: fuzzinesse);
          break;
        case SELECT_LESSER_VALUE:
          RGBtoHSV(rgb, hsv: &v43);
          v27 = this->m_Fuzziness;
          v28 = this->m_SelectedHSVs.m_Memory.m_pMemory;
          j = this->m_Fuzziness;
          fuzzinessf = v27;
          *(float *)&i = FuzzyLessThan(a: v43.z, b: v28[v6].z, fuzziness: fuzzinessf);
          break;
        case SELECT_NEARBY_VALUE:
          RGBtoHSV(rgb, hsv: &v43);
          v22 = this->m_Fuzziness;
          v29 = this->m_SelectedHSVs.m_Memory.m_pMemory;
          hsv.x = this->m_Tolerance;
          fuzziness = hsv.x * v22;
          b = hsv.x;
          v24 = v43.z - v29[v6].z;
LABEL_21:
          aa = fabs(v24);
          j = v22;
          *(float *)&i = FuzzyLessThan(a: aa, b, fuzziness);
          break;
        default:
          x = rgb->x;
          v31 = this->m_SelectedRGBs.m_Memory.m_pMemory[v6].x;
          if ( m_Fuzziness >= 0.0039215689 )
          {
            v32 = v31 - m_Fuzziness;
            if ( x <= (float)(m_Fuzziness + v31) )
            {
              if ( v32 <= x )
                *(float *)&i = (float)(x - v32) / (float)((float)(m_Fuzziness + v31) - v32);
              else
                *(float *)&i = 0.0;
            }
            else
            {
              *(float *)&i = 1.0;
            }
          }
          else if ( x < v31 )
          {
            *(float *)&i = 0.0;
          }
          else
          {
            *(float *)&i = 1.0;
          }
          break;
      }
      v7 = v47;
      if ( *(float *)&i > v47 )
      {
        v7 = *(float *)&i;
        v47 = *(float *)&i;
      }
      ++v6;
      if ( ++v46 >= this->m_SelectedRGBs.m_Size )
        break;
    }
  }
  if ( this->m_bInvertSelection )
    return (float)(1.0 - v7);
  return v47;
}

//------------------------------------------------------------------------------
// Address: 0x100A5A10
// Name: public: virtual void CSelectedHSVOperation::Apply(class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectedHSVOperation::Apply(CSelectedHSVOperation *this, const Vector *inRGB, Vector *outRGB)
{
  double SelectionAmount; // st7
  long double v6; // st7
  float y; // xmm0_4
  float x; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  Vector hsv; // [esp+8h] [ebp-Ch] BYREF
  int savedregs; // [esp+14h] [ebp+0h] BYREF
  float flSelectionAmount; // [esp+1Ch] [ebp+8h]

  SelectionAmount = CSelectedHSVOperation::GetSelectionAmount(this, a2: COERCE_FLOAT(&savedregs), rgb: inRGB);
  flSelectionAmount = SelectionAmount;
  if ( SelectionAmount == 0.0 || !this->m_bEnable )
  {
    *outRGB = *inRGB;
  }
  else
  {
    RGBtoHSV(rgb: inRGB, &hsv);
    if ( this->m_bColorize )
    {
      x = this->m_DeltaHSV.x;
      if ( x < 0.0 )
        x = x + 360.0;
      hsv.x = x;
      y = this->m_DeltaHSV.y;
    }
    else
    {
      v6 = fmod(this->m_DeltaHSV.x + hsv.x, 360.0);
      hsv.x = v6;
      if ( v6 < 0.0 )
        hsv.x = hsv.x + 360.0;
      y = (float)(this->m_DeltaHSV.y + 1.0) * hsv.y;
    }
    if ( y >= 0.0 )
    {
      if ( y <= 1.0 )
        v9 = y;
      else
        v9 = 1.0;
    }
    else
    {
      v9 = 0.0;
    }
    v10 = this->m_DeltaHSV.z + hsv.z;
    hsv.y = v9;
    if ( v10 >= 0.0 )
    {
      if ( v10 > 1.0 )
        v10 = 1.0;
    }
    else
    {
      v10 = 0.0;
    }
    hsv.z = v10;
    if ( v9 == 0.0 )
      hsv.x = -1.0;
    HSVtoRGB(&hsv, rgb: outRGB);
    v11 = this->m_flBlendFactor * flSelectionAmount;
    outRGB->x = (float)((float)(outRGB->x - inRGB->x) * v11) + inRGB->x;
    outRGB->y = (float)((float)(outRGB->y - inRGB->y) * v11) + inRGB->y;
    outRGB->z = (float)((float)(outRGB->z - inRGB->z) * v11) + inRGB->z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A5BA0
// Name: public: virtual void CUncorrectedImagePanel::RegenerateTextureBits(class ITexture __near *,class IVTFTexture __near *,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUncorrectedImagePanel::RegenerateTextureBits(
        CUncorrectedImagePanel *this,
        ITexture *pTexture,
        IVTFTexture *pVTFTexture,
        Rect_t *pRect)
{
  IVTFTexture *v4; // esi
  IVTFTexture_vtbl *v5; // eax
  __int16 v6; // bx
  int v7; // edx
  int v8; // eax
  int v9; // ecx
  BGRA8888_t *v10; // eax
  unsigned __int8 g; // cl
  unsigned __int8 b; // dl
  unsigned int vpanel; // eax
  CSelectedHSVOperation *v14; // ecx
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm0_4
  int v19; // ecx
  int v20; // edx
  unsigned int v21; // edx
  unsigned int v22; // edx
  int v23; // eax
  unsigned __int64 v24; // rdi
  __int64 v25; // rax
  __int64 v26; // rax
  int a; // ecx
  unsigned __int64 v28; // rdi
  color24 v29; // [esp-Ch] [ebp-90h]
  int pixelWriter; // [esp+Ch] [ebp-78h]
  int pixelWriter_4; // [esp+10h] [ebp-74h]
  unsigned __int8 pixelWriter_10; // [esp+16h] [ebp-6Eh]
  int pixelWriter_12; // [esp+18h] [ebp-6Ch]
  int pixelWriter_16; // [esp+1Ch] [ebp-68h]
  int pixelWriter_20; // [esp+20h] [ebp-64h]
  int pixelWriter_24; // [esp+24h] [ebp-60h]
  int pixelWriter_28; // [esp+28h] [ebp-5Ch]
  int pixelWriter_32; // [esp+2Ch] [ebp-58h]
  Vector rgb; // [esp+30h] [ebp-54h] BYREF
  __int64 v40; // [esp+3Ch] [ebp-48h]
  int nDepth; // [esp+44h] [ebp-40h] BYREF
  int v42; // [esp+48h] [ebp-3Ch]
  float v43; // [esp+4Ch] [ebp-38h]
  float v44; // [esp+50h] [ebp-34h]
  float v45; // [esp+54h] [ebp-30h]
  int nHeight; // [esp+58h] [ebp-2Ch] BYREF
  int v47; // [esp+5Ch] [ebp-28h]
  int y; // [esp+60h] [ebp-24h]
  int nWidth; // [esp+64h] [ebp-20h] BYREF
  int x; // [esp+68h] [ebp-1Ch]
  int v51; // [esp+6Ch] [ebp-18h]
  CUncorrectedImagePanel *v52; // [esp+70h] [ebp-14h]
  int flSelectionAmount; // [esp+74h] [ebp-10h]
  BGRA8888_t *pTexel; // [esp+78h] [ebp-Ch]
  int v55; // [esp+7Ch] [ebp-8h]
  color24 inColor; // [esp+80h] [ebp-4h]
  int savedregs; // [esp+84h] [ebp+0h] BYREF

  v4 = pVTFTexture;
  v5 = pVTFTexture->__vftable;
  v52 = this;
  v5->ComputeMipLevelDimensions(this: pVTFTexture, a2: 0, a3: &nWidth, a4: &nHeight, a5: &nDepth);
  pVTFTexture = (IVTFTexture *)v4->RowSizeInBytes(this: v4, a2: 0);
  pixelWriter = (int)v4->ImageData_2(this: v4, a2: 0, a3: 0, a4: 0);
  switch ( v4->Format(this: v4) )
  {
    case IMAGE_FORMAT_RGBA8888:
    case IMAGE_FORMAT_UVWQ8888:
      pixelWriter_12 = 0x80000;
      v6 = 16;
      pixelWriter_16 = 1572880;
      goto LABEL_6;
    case IMAGE_FORMAT_BGR888:
      pixelWriter_10 = 3;
      pixelWriter_12 = 524304;
      pixelWriter_20 = 255;
      pixelWriter_24 = 255;
      pixelWriter_28 = 255;
      goto LABEL_19;
    case IMAGE_FORMAT_I8:
      pixelWriter_10 = 1;
      goto LABEL_17;
    case IMAGE_FORMAT_A8:
      v6 = 0;
      pixelWriter_10 = 1;
      pixelWriter_12 = 0;
      pixelWriter_16 = 0;
      pixelWriter_20 = 0;
      pixelWriter_24 = 0;
      pixelWriter_28 = 0;
      pixelWriter_32 = 255;
      goto LABEL_21;
    case IMAGE_FORMAT_BGRA8888:
      pixelWriter_12 = 524304;
      v6 = 0;
      pixelWriter_16 = 1572864;
LABEL_6:
      pixelWriter_10 = 4;
      pixelWriter_20 = 255;
      pixelWriter_24 = 255;
      pixelWriter_28 = 255;
      pixelWriter_32 = 255;
      goto LABEL_21;
    case IMAGE_FORMAT_BGRX8888:
      pixelWriter_10 = 4;
      pixelWriter_12 = 524304;
      v6 = 0;
      pixelWriter_16 = 1572864;
      pixelWriter_20 = 255;
      pixelWriter_24 = 255;
      pixelWriter_28 = 255;
      goto LABEL_20;
    case IMAGE_FORMAT_BGR565:
      pixelWriter_10 = 2;
      pixelWriter_12 = 196616;
      v6 = -3;
      pixelWriter_16 = 65533;
      pixelWriter_20 = 248;
      pixelWriter_24 = 252;
      pixelWriter_28 = 248;
      goto LABEL_20;
    case IMAGE_FORMAT_BGRX5551:
    case IMAGE_FORMAT_BGRA5551:
      pixelWriter_10 = 2;
      pixelWriter_12 = 131079;
      v6 = -3;
      pixelWriter_16 = 589821;
      pixelWriter_20 = 248;
      pixelWriter_24 = 248;
      pixelWriter_28 = 248;
      pixelWriter_32 = 128;
      goto LABEL_21;
    case IMAGE_FORMAT_BGRA4444:
      pixelWriter_10 = 2;
      pixelWriter_12 = 4;
      v6 = -4;
      pixelWriter_16 = 589820;
      pixelWriter_20 = 240;
      pixelWriter_24 = 240;
      pixelWriter_28 = 240;
      pixelWriter_32 = 240;
      goto LABEL_21;
    case IMAGE_FORMAT_RGBA16161616F:
    case IMAGE_FORMAT_RGBA16161616:
      pixelWriter_10 = 8;
      pixelWriter_12 = 0x100000;
      v6 = 32;
      pixelWriter_16 = 3145760;
      pixelWriter_20 = 0xFFFF;
      pixelWriter_24 = 0xFFFF;
      pixelWriter_28 = 0xFFFF;
      pixelWriter_32 = 0xFFFF;
      goto LABEL_21;
    case IMAGE_FORMAT_R32F:
      pixelWriter_10 = 4;
      pixelWriter_20 = -1;
      goto LABEL_18;
    case IMAGE_FORMAT_RGBA32323232F:
      pixelWriter_10 = 16;
      pixelWriter_12 = 0x200000;
      v6 = 64;
      pixelWriter_16 = 6291520;
      pixelWriter_20 = -1;
      pixelWriter_24 = -1;
      pixelWriter_28 = -1;
      pixelWriter_32 = -1;
      goto LABEL_21;
    case IMAGE_FORMAT_BGRA1010102:
      pixelWriter_10 = 4;
      pixelWriter_12 = 655380;
      v6 = 0;
      pixelWriter_16 = 1966080;
      pixelWriter_20 = 1023;
      pixelWriter_24 = 1023;
      pixelWriter_28 = 1023;
      pixelWriter_32 = 3;
      goto LABEL_21;
    default:
      pixelWriter_10 = 0;
LABEL_17:
      pixelWriter_20 = 255;
LABEL_18:
      pixelWriter_12 = 0;
      pixelWriter_24 = 0;
      pixelWriter_28 = 0;
LABEL_19:
      v6 = 0;
      pixelWriter_16 = 0;
LABEL_20:
      pixelWriter_32 = 0;
LABEL_21:
      v7 = 0;
      y = 0;
      if ( nHeight > 0 )
      {
        v8 = pixelWriter;
        v42 = (unsigned __int16)pVTFTexture;
        v9 = nWidth;
        v47 = pixelWriter;
        do
        {
          pixelWriter_4 = v8;
          v10 = (BGRA8888_t *)(*(_DWORD *)&v52->m_OnCommand_register + 4 * v7 * *(_DWORD *)&v52->m_OnDelete_register);
          pTexel = v10;
          x = 0;
          if ( v9 > 0 )
          {
            v51 = pixelWriter_10;
            while ( 1 )
            {
              g = v10->g;
              inColor.r = v10->r;
              b = v10->b;
              vpanel = v52->_vpanel;
              inColor.g = g;
              *(_WORD *)&v29.r = *(_WORD *)&inColor.r;
              v29.b = b;
              CColorOperationList::Apply(
                this: *(CColorOperationList **)(vpanel + 4),
                in: v29,
                out: (color24 *)&pVTFTexture,
                pFinalOp: (IColorOperation *)vpanel);
              v14 = (CSelectedHSVOperation *)v52->_vpanel;
              v45 = (float)(unsigned __int8)pVTFTexture;
              v44 = (float)BYTE1(pVTFTexture);
              v43 = (float)BYTE2(pVTFTexture);
              rgb.x = v45 * 0.0039215689;
              rgb.y = v44 * 0.0039215689;
              rgb.z = v43 * 0.0039215689;
              *(float *)&flSelectionAmount = CSelectedHSVOperation::GetSelectionAmount(
                                               this: v14,
                                               a2: COERCE_FLOAT(&savedregs),
                                               &rgb)
                                           * 0.5;
              v15 = (float)(1.0 - *(float *)&flSelectionAmount) * 0.0039215689;
              v16 = (float)((float)(v15 * v45) + *(float *)&flSelectionAmount) * 255.0;
              v17 = (float)(v15 * v44) * 255.0;
              v18 = (float)(v15 * v43) * 255.0;
              v19 = (int)v17;
              v20 = (int)v18;
              if ( (int)v16 >= 0 )
              {
                flSelectionAmount = 255;
                if ( (int)v16 <= 255 )
                  flSelectionAmount = (int)v16;
              }
              else
              {
                *(float *)&flSelectionAmount = 0.0;
              }
              if ( v19 >= 0 )
              {
                if ( v19 > 255 )
                  v19 = 255;
              }
              else
              {
                v19 = 0;
              }
              if ( v20 >= 0 )
              {
                v55 = 255;
                if ( v20 <= 255 )
                  v55 = (int)v18;
              }
              else
              {
                v55 = 0;
              }
              if ( pixelWriter_10 != 0 )
              {
                if ( pixelWriter_10 >= 5u )
                {
                  v24 = ((unsigned __int64)(flSelectionAmount & (unsigned int)pixelWriter_20) << pixelWriter_12)
                      | ((unsigned __int64)(v19 & (unsigned int)pixelWriter_24) << SBYTE2(pixelWriter_12));
                  v25 = v55 & (unsigned int)pixelWriter_28;
                  if ( v6 <= 0 )
                    v26 = v25 >> -(char)v6;
                  else
                    v26 = v25 << v6;
                  a = pTexel->a;
                  v40 = v26;
                  v28 = v26 | ((unsigned __int64)(a & (unsigned int)pixelWriter_32) << SBYTE2(pixelWriter_16)) | v24;
                  if ( v51 == 6 )
                  {
                    *(_DWORD *)pixelWriter_4 = v28;
                    *(_WORD *)(pixelWriter_4 + 4) = WORD2(v28);
                  }
                  else if ( v51 == 8 )
                  {
                    *(_QWORD *)pixelWriter_4 = v28;
                  }
                }
                else
                {
                  v21 = v55 & pixelWriter_28;
                  if ( v6 <= 0 )
                    v22 = v21 >> -(char)pixelWriter_16;
                  else
                    v22 = v21 << pixelWriter_16;
                  v23 = v22
                      | ((unsigned __int8)(pTexel->a & pixelWriter_32) << SBYTE2(pixelWriter_16))
                      | ((flSelectionAmount & pixelWriter_20) << pixelWriter_12)
                      | ((v19 & pixelWriter_24) << SBYTE2(pixelWriter_12));
                  switch ( v51 )
                  {
                    case 1:
                      *(_BYTE *)pixelWriter_4 = v23;
                      break;
                    case 2:
                      *(_WORD *)pixelWriter_4 = v23;
                      break;
                    case 3:
                      *(_WORD *)pixelWriter_4 = v23;
                      *(_BYTE *)(pixelWriter_4 + 2) = BYTE2(v23);
                      break;
                    case 4:
                      *(_DWORD *)pixelWriter_4 = v23;
                      break;
                    default:
                      break;
                  }
                }
              }
              v9 = nWidth;
              pixelWriter_4 += v51;
              ++pTexel;
              if ( ++x >= nWidth )
                break;
              v10 = pTexel;
            }
            v7 = y;
          }
          v8 = v42 + v47;
          y = ++v7;
          v47 += v42;
        }
        while ( v7 < nHeight );
      }
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A6160
// Name: public: void CColorLookupOperation::LoadLookupTable(char const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CColorLookupOperation::LoadLookupTable(
        CColorLookupOperation *this@<ecx>,
        int a2@<edi>,
        const char *pFilename)
{
  void *v3; // ebx
  unsigned int v4; // edi
  long double v5; // st7
  int v6; // esi
  int v7; // edi
  char v8; // cl
  color24 *m_LookupTable; // eax
  unsigned int color; // [esp+8h] [ebp-4h] OVERLAPPED BYREF

  v3 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: pFilename, a3: "rb", a4: 0);
  if ( v3 != nullptr )
  {
    v4 = ((int (__thiscall *)(IBaseFileSystem *, void *, int))g_pFileSystem->Size_2)(
           a1: &g_pFileSystem->IBaseFileSystem,
           a2: v3,
           a3: a2);
    color = v4 / 3;
    v5 = pow((double)(v4 / 3), 0.3333333432674408);
    v6 = (int)v5 * (int)v5 * (int)v5;
    if ( 3 * v6 == v4 )
    {
      CColorLookupOperation::SetResolution(this, res: (int)v5);
      if ( v6 > 0 )
      {
        v7 = 0;
        do
        {
          g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: &color, a3: 3, a4: v3);
          v8 = BYTE2(color);
          BYTE2(color) = color;
          m_LookupTable = this->m_LookupTable;
          LOBYTE(color) = v8;
          *(_WORD *)&m_LookupTable[v7].r = color;
          m_LookupTable[v7++].b = BYTE2(color);
          --v6;
        }
        while ( v6 != 0 );
      }
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v3);
      _V_strcpy(dest: this->m_pFilename, src: pFilename);
      colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
    }
    else
    {
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A6290
// Name: private: virtual void CColorLookupUIPanel::OnFileSelected(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CColorLookupUIPanel::OnFileSelected(
        CColorLookupUIPanel *this@<ecx>,
        int a2@<edi>,
        const char *filename)
{
  CColorLookupOperation *m_pLookupOp; // eax
  vgui::Button_vtbl *v5; // edx

  CColorLookupOperation::LoadLookupTable(this: this->m_pLookupOp, a2, pFilename: filename);
  m_pLookupOp = this->m_pLookupOp;
  v5 = this->m_pLoadButton->__vftable;
  if ( m_pLookupOp->m_LookupTable != nullptr )
    ((void (__stdcall *)(char *))v5->SetText)(a1: m_pLookupOp->m_pFilename);
  else
    ((void (__stdcall *)(const char *))v5->SetText)(a1: "No File Loaded");
}

//------------------------------------------------------------------------------
// Address: 0x100A62E0
// Name: public: virtual void CColorBalanceOperation::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorBalanceOperation::Release(CColorBalanceOperation *this)
{
  if ( this != nullptr )
  {
    this->__vftable = (CColorBalanceOperation_vtbl *)&CColorBalanceOperation::`vftable';
    free(pMem: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A6300
// Name: public: CColorBalanceOperation::CColorBalanceOperation(void)
// Source: json
//------------------------------------------------------------------------------
CColorBalanceOperation *__thiscall CColorBalanceOperation::CColorBalanceOperation(CColorBalanceOperation *this)
{
  int v2; // ecx
  float *m_HighlightsAddTransfer; // eax
  float v4; // xmm0_4
  float v5; // xmm1_4

  this->__vftable = (CColorBalanceOperation_vtbl *)&CColorBalanceOperation::`vftable';
  this->m_PreserveLuminosity = true;
  this->m_CyanRedBalance[0] = 0.0;
  this->m_MagentaGreenBalance[0] = 0.0;
  this->m_YellowBlueBalance[0] = 0.0;
  this->m_CyanRedBalance[1] = 0.0;
  this->m_MagentaGreenBalance[1] = 0.0;
  this->m_YellowBlueBalance[1] = 0.0;
  this->m_CyanRedBalance[2] = 0.0;
  this->m_MagentaGreenBalance[2] = 0.0;
  this->m_YellowBlueBalance[2] = 0.0;
  v2 = 0;
  m_HighlightsAddTransfer = this->m_HighlightsAddTransfer;
  do
  {
    v4 = (float)(1.0
               - (float)((float)((float)((float)v2 - 127.0) * 0.0078740157)
                       * (float)((float)((float)v2 - 127.0) * 0.0078740157)))
       * 0.667;
    v5 = 1.075 - (float)(1.0 / (float)((float)((float)v2 * 0.0625) + 1.0));
    *(m_HighlightsAddTransfer - 1280) = v5;
    *m_HighlightsAddTransfer = v5;
    *(m_HighlightsAddTransfer - 1024) = v4;
    *(m_HighlightsAddTransfer - 256) = v4;
    *(m_HighlightsAddTransfer - 768) = v4;
    *(m_HighlightsAddTransfer - 512) = v4;
    ++v2;
    ++m_HighlightsAddTransfer;
  }
  while ( v2 < 256 );
  this->m_bEnable = true;
  this->m_flBlendFactor = 1.0;
  CColorBalanceOperation::CreateLookupTables(this);
  _V_strcpy(dest: this->m_pName, src: "Balance");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A6420
// Name: public: virtual class IColorOperation __near * CColorBalanceOperation::Clone(void)
// Source: json
//------------------------------------------------------------------------------
CColorBalanceOperation *__thiscall CColorBalanceOperation::Clone(CColorBalanceOperation *this)
{
  CColorBalanceOperation *v2; // eax
  CColorBalanceOperation *v3; // esi

  v2 = (CColorBalanceOperation *)MemAlloc_Alloc(nSize: 0x1C34u);
  if ( v2 != nullptr )
    v3 = CColorBalanceOperation::CColorBalanceOperation(this: v2);
  else
    v3 = nullptr;
  v3->m_PreserveLuminosity = this->m_PreserveLuminosity;
  v3->m_flBlendFactor = this->m_flBlendFactor;
  v3->m_bEnable = this->m_bEnable;
  _V_memcpy(dest: v3->m_CyanRedBalance, src: this->m_CyanRedBalance, count: 12);
  _V_memcpy(dest: v3->m_MagentaGreenBalance, src: this->m_MagentaGreenBalance, count: 12);
  _V_memcpy(dest: v3->m_YellowBlueBalance, src: this->m_YellowBlueBalance, count: 12);
  _V_memcpy(dest: v3->m_ShadowsSubTransfer, src: this->m_ShadowsSubTransfer, count: 1024);
  _V_memcpy(dest: v3->m_MidtonesSubTransfer, src: this->m_MidtonesSubTransfer, count: 1024);
  _V_memcpy(dest: v3->m_HighlightsSubTransfer, src: this->m_HighlightsSubTransfer, count: 1024);
  _V_memcpy(dest: v3->m_ShadowsAddTransfer, src: this->m_ShadowsAddTransfer, count: 1024);
  _V_memcpy(dest: v3->m_MidtonesAddTransfer, src: this->m_MidtonesAddTransfer, count: 1024);
  _V_memcpy(dest: v3->m_HighlightsAddTransfer, src: this->m_HighlightsAddTransfer, count: 1024);
  _V_memcpy(dest: v3->m_pRedLookup, src: this->m_pRedLookup, count: 256);
  _V_memcpy(dest: v3->m_pGreenLookup, src: this->m_pGreenLookup, count: 256);
  _V_memcpy(dest: v3->m_pBlueLookup, src: this->m_pBlueLookup, count: 256);
  _V_memcpy(dest: v3->m_pName, src: this->m_pName, count: 256);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100A6590
// Name: public: CNewOperationDialog::CNewOperationDialog(class vgui::Panel __near *,class CColorOperationList __near *)
// Source: json
//------------------------------------------------------------------------------
CNewOperationDialog *__thiscall CNewOperationDialog::CNewOperationDialog(
        CNewOperationDialog *this,
        vgui::Panel *parent,
        CColorOperationList *pOpList)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::ComboBox *v7; // eax
  vgui::ComboBox *v8; // eax
  vgui::TextEntry *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  vgui::Button *v14; // eax

  vgui::Frame::Frame(this, parent, panelName: "NewOperation", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CNewOperationDialog_vtbl *)&CNewOperationDialog::`vftable';
  if ( `CNewOperationDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CNewOperationDialog::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CNewOperationDialog");
    v4->pfnClassName = CNewOperationDialog::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CNewOperationDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CNewOperationDialog::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CNewOperationDialog");
    v5->pfnClassName = CNewOperationDialog::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CNewOperationDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CNewOperationDialog::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CNewOperationDialog");
    v6->pfnClassName = CNewOperationDialog::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  v7 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v7 != nullptr )
    v8 = vgui::ComboBox::ComboBox(this: v7, parent: this, panelName: "OperationType", numLines: 6, allowEdit: false);
  else
    v8 = nullptr;
  this->m_pOperationType = v8;
  v9 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v9 != nullptr )
    v10 = vgui::TextEntry::TextEntry(this: v9, parent: this, panelName: "Name");
  else
    v10 = nullptr;
  this->m_pName = v10;
  v11 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: this,
            panelName: "Create",
            text: "Create",
            pActionSignalTarget: this,
            pCmd: "Create");
  else
    v12 = nullptr;
  this->m_pCreateButton = v12;
  v13 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v13 != nullptr )
    v14 = vgui::Button::Button(
            this: v13,
            parent: this,
            panelName: "Cancel",
            text: "Cancel",
            pActionSignalTarget: this,
            pCmd: "Cancel");
  else
    v14 = nullptr;
  this->m_pCancelButton = v14;
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource\\NewOperationDialog.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  CNewOperationDialog::PopulateControls(this);
  this->m_pOpList = pOpList;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A6730
// Name: private: virtual void CColorOperationListPanel::OnSliderMoved(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorOperationListPanel::OnSliderMoved(CColorOperationListPanel *this, KeyValues *data)
{
  int v3; // edi
  IColorOperation *v4; // ebx
  IColorOperation_vtbl *v5; // edi
  int v6; // eax
  int i; // edi
  CColorCorrectionUIChildPanel *v8; // ecx
  KeyValues *v9; // eax
  KeyValues *v10; // eax

  if ( KeyValues::GetPtr(this: data, keyName: "panel", defaultValue: nullptr) == this->m_pBlendFactorSlider )
  {
    v3 = this->m_pOperationListPanel->GetSelectedItem(this: this->m_pOperationListPanel, a2: 0);
    if ( v3 >= 0 && this->m_pOperationListPanel->IsValidItemID(this: this->m_pOperationListPanel, a2: v3) )
    {
      v4 = (IColorOperation *)this->m_pOperationListPanel->GetItemUserData(this: this->m_pOperationListPanel, a2: v3);
      v5 = v4->__vftable;
      v6 = this->m_pBlendFactorSlider->GetValue(this: this->m_pBlendFactorSlider);
      ((void (__thiscall *)(IColorOperation *, _DWORD))v5->SetBlendFactor)(a1: v4, a2: (float)v6 * 0.0039215689);
      for ( i = 0; i < this->m_OpPanelList.m_Size; ++i )
      {
        v8 = this->m_OpPanelList.m_Memory.m_pMemory[i];
        if ( v8->GetOperation(this: v8) == v4 )
        {
          v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v9 != nullptr )
            v10 = KeyValues::KeyValues(
                    this: v9,
                    setName: "command",
                    firstKey: "command",
                    firstValue: "BlendFactorUpdate");
          else
            v10 = nullptr;
          ((void (__thiscall *)(CColorOperationListPanel *, CColorCorrectionUIChildPanel *, KeyValues *, _DWORD))this->PostMessage)(
            a1: this,
            a2: this->m_OpPanelList.m_Memory.m_pMemory[i],
            a3: v10,
            a4: 0.0);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A6840
// Name: public: void CColorOperationListPanel::PopulateList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorOperationListPanel::PopulateList(CColorOperationListPanel *this)
{
  int m_Size; // ecx
  int v3; // eax
  IColorOperation *v4; // esi
  KeyValues *v5; // edi
  const char *v6; // eax
  KeyValues *v7; // edi
  bool v8; // al
  int numItems; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  this->m_pOperationListPanel->DeleteAllItems(this: this->m_pOperationListPanel);
  m_Size = this->m_OperationList.m_OpList.m_Size;
  v3 = 0;
  numItems = m_Size;
  for ( i = 0; v3 < m_Size; i = v3 )
  {
    if ( v3 >= 0 && v3 < this->m_OperationList.m_OpList.m_Size )
    {
      v4 = this->m_OperationList.m_OpList.m_Memory.m_pMemory[v3];
      if ( v4 != nullptr )
      {
        v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v5 != nullptr )
        {
          v6 = v4->GetName(this: v4);
          v7 = KeyValues::KeyValues(this: v5, setName: "operation", firstKey: "layer", firstValue: v6);
        }
        else
        {
          v7 = nullptr;
        }
        v8 = v4->IsEnabled(this: v4);
        KeyValues::SetInt(this: v7, keyName: "image", value: v8);
        this->m_pOperationListPanel->AddItem(
          this: this->m_pOperationListPanel,
          a2: v7,
          a3: (unsigned int)v4,
          a4: false,
          a5: false);
        v3 = i;
        m_Size = numItems;
      }
    }
    ++v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A6910
// Name: public: void CColorOperationListPanel::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorOperationListPanel::Shutdown(CColorOperationListPanel *this)
{
  int i; // esi
  IColorOperation *v3; // ecx

  this->m_pLookupViewWindow->Shutdown(this: this->m_pLookupViewWindow);
  for ( i = this->m_OperationList.m_OpList.m_Size - 1; i >= 0; --i )
  {
    v3 = this->m_OperationList.m_OpList.m_Memory.m_pMemory[i];
    v3->Release(this: v3);
  }
  this->m_OperationList.m_OpList.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100A6950
// Name: public: virtual void CColorCorrectionUIPanel::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionUIPanel::OnThink(CColorCorrectionUIPanel *this)
{
  int m_nCurrentRow; // ecx
  __int16 v3; // bx
  __int16 v4; // bx
  RGBX5551_t v5; // bx
  int v6; // eax
  char *v7; // esi
  double v8; // st7
  double v9; // st7
  bool v10; // zf
  color24 v11; // [esp+18h] [ebp-48h]
  float fl360GammaValue; // [esp+20h] [ebp-40h]
  float fl360GammaValuea; // [esp+20h] [ebp-40h]
  float fl360GammaValueb; // [esp+20h] [ebp-40h]
  float fl360GammaValuec; // [esp+20h] [ebp-40h]
  float fl360GammaValued; // [esp+20h] [ebp-40h]
  float fl360GammaValuee; // [esp+20h] [ebp-40h]
  int i; // [esp+34h] [ebp-2Ch]
  int v19; // [esp+38h] [ebp-28h]
  int r; // [esp+3Ch] [ebp-24h]
  RGBX5551_t inColor; // [esp+40h] [ebp-20h]
  RGBX5551_t inColora; // [esp+40h] [ebp-20h]
  __int16 vPwlOutColor; // [esp+44h] [ebp-1Ch]
  __int16 vPwlInputColorAsSrgb; // [esp+48h] [ebp-18h]
  color24 vPwlInputColor; // [esp+4Ch] [ebp-14h] BYREF
  color24 vSrgbOutColor; // [esp+50h] [ebp-10h] BYREF
  color24 vSrgbInputColor; // [esp+54h] [ebp-Ch] BYREF
  color24 vPwlOutColorAsSrgb; // [esp+58h] [ebp-8h] BYREF

  vgui::Frame::OnThink(this);
  if ( this->m_bForceReset )
  {
    colorcorrection->LockLookup(this: colorcorrection, a2: this->m_CCHandle);
    colorcorrection->ResetLookup_2(this: colorcorrection, a2: this->m_CCHandle);
    colorcorrection->UnlockLookup(this: colorcorrection, a2: this->m_CCHandle, a3: true);
    this->m_bForceReset = false;
  }
  m_nCurrentRow = this->m_nCurrentRow;
  if ( m_nCurrentRow != -1 )
  {
    v3 = (*(_BYTE *)&inColor ^ (unsigned __int8)m_nCurrentRow) & 0x1F ^ *(_WORD *)&inColor;
    r = this->m_nCurrentRow;
    if ( m_nCurrentRow < 32 )
    {
      while ( m_nCurrentRow < this->m_nCurrentRow + 32 / this->m_nRowStep )
      {
        v4 = v3 & 0xFC1F;
        for ( i = 32; i != 0; --i )
        {
          v5 = (RGBX5551_t)(v4 & 0x83FF);
          inColora = v5;
          v19 = 32;
          do
          {
            ((void (__thiscall *)(_DWORD, _DWORD, _WORD))colorcorrection->ConvertToColor24)(
              a1: colorcorrection,
              a2: &vSrgbInputColor,
              a3: inColora);
            if ( this->m_bEnable )
              CColorOperationList::Apply(
                this: &this->m_pOperationListPanel->m_OperationList,
                in: vSrgbInputColor,
                out: &vSrgbOutColor,
                pFinalOp: this->m_pFinalOperation);
            else
              vSrgbOutColor = vSrgbInputColor;
            v6 = 32 * (((*(unsigned __int16 *)&v5 >> 5) & 0x1F) + 32 * ((*(unsigned __int16 *)&v5 >> 10) & 0x1F));
            v7 = (char *)this + 2 * (*(_BYTE *)&v5 & 0x1F) + 2 * v6 + (*(_BYTE *)&v5 & 0x1F) + v6;
            *(color24 *)(v7 + 556) = vSrgbOutColor;
            ((void (__thiscall *)(_DWORD, _DWORD, _WORD))colorcorrection->ConvertToColor24)(
              a1: colorcorrection,
              a2: &vPwlInputColor,
              a3: inColora);
            fl360GammaValue = X360GammaToLinear(fl360GammaValue: (float)vPwlInputColor.r * 0.0039215689);
            LOBYTE(vPwlInputColorAsSrgb) = (int)(SrgbLinearToGamma(flLinearValue: fl360GammaValue) * 255.0);
            fl360GammaValuea = X360GammaToLinear(fl360GammaValue: (float)vPwlInputColor.g * 0.0039215689);
            HIBYTE(vPwlInputColorAsSrgb) = (int)(SrgbLinearToGamma(flLinearValue: fl360GammaValuea) * 255.0);
            fl360GammaValueb = X360GammaToLinear(fl360GammaValue: (float)vPwlInputColor.b * 0.0039215689);
            v8 = SrgbLinearToGamma(flLinearValue: fl360GammaValueb) * 255.0;
            if ( this->m_bEnable )
            {
              *(_WORD *)&v11.r = vPwlInputColorAsSrgb;
              v11.b = (int)v8;
              CColorOperationList::Apply(
                this: &this->m_pOperationListPanel->m_OperationList,
                in: v11,
                out: &vPwlOutColorAsSrgb,
                pFinalOp: this->m_pFinalOperation);
            }
            else
            {
              *(_WORD *)&vPwlOutColorAsSrgb.r = vPwlInputColorAsSrgb;
              vPwlOutColorAsSrgb.b = (int)v8;
            }
            fl360GammaValuec = SrgbGammaToLinear(flSrgbGammaValue: (float)vPwlOutColorAsSrgb.r * 0.0039215689);
            LOBYTE(vPwlOutColor) = (int)(X360LinearToGamma(flLinearValue: fl360GammaValuec) * 255.0);
            fl360GammaValued = SrgbGammaToLinear(flSrgbGammaValue: (float)vPwlOutColorAsSrgb.g * 0.0039215689);
            HIBYTE(vPwlOutColor) = (int)(X360LinearToGamma(flLinearValue: fl360GammaValued) * 255.0);
            fl360GammaValuee = SrgbGammaToLinear(flSrgbGammaValue: (float)vPwlOutColorAsSrgb.b * 0.0039215689);
            v9 = X360LinearToGamma(flLinearValue: fl360GammaValuee);
            v5 = (RGBX5551_t)((*(_WORD *)&inColora ^ ((*(_WORD *)&inColora & 0xFC00) + 1024)) & 0x7C00 ^ *(_WORD *)&v5);
            v10 = v19-- == 1;
            *((_WORD *)v7 + 49430) = vPwlOutColor;
            v7[98862] = (int)(v9 * 255.0);
            inColora = v5;
          }
          while ( !v10 );
          v4 = (*(_WORD *)&v5 ^ ((*(_WORD *)&v5 & 0xFFE0) + 32)) & 0x3E0 ^ *(_WORD *)&v5;
        }
        v3 = ((unsigned __int8)v4 ^ (unsigned __int8)(v4 + 1)) & 0x1F ^ v4;
        if ( ++r >= 32 )
          break;
        m_nCurrentRow = r;
      }
    }
    this->m_nCurrentRow += 32 / this->m_nRowStep;
    if ( this->m_nCurrentRow == 32 )
    {
      colorcorrection->LockLookup(this: colorcorrection, a2: this->m_CCHandle);
      colorcorrection->CopyLookup(this: colorcorrection, a2: this->m_CCHandle, a3: this->m_pLookupCache);
      colorcorrection->UnlockLookup(this: colorcorrection, a2: this->m_CCHandle, a3: true);
      CProceduralTexturePanel::DownloadTexture(this: this->m_pOperationListPanel->m_pLookupViewWindow->m_pLookupPanel);
      this->m_nCurrentRow = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A6DD0
// Name: public: void CColorCorrectionUIPanel::ReadUncorrectedImage(struct Rect_t __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionUIPanel::ReadUncorrectedImage(
        CColorCorrectionUIPanel *this,
        Rect_t *pSrcRect,
        unsigned __int8 *pPreviewImage)
{
  CColorOperationListPanel *m_pOperationListPanel; // edi
  int i; // esi
  CColorCorrectionUIChildPanel *v5; // ecx

  m_pOperationListPanel = this->m_pOperationListPanel;
  for ( i = 0; i < m_pOperationListPanel->m_OpPanelList.m_Size; ++i )
  {
    v5 = m_pOperationListPanel->m_OpPanelList.m_Memory.m_pMemory[i];
    v5->ReadUncorrectedImage(this: v5, a2: pSrcRect, a3: pPreviewImage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A6E20
// Name: public: virtual void CColorCorrectionTools::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionTools::Shutdown(CColorCorrectionTools *this)
{
  CColorOperationListPanel *m_pOperationListPanel; // ecx

  if ( g_pColorCorrectionUI != nullptr )
  {
    m_pOperationListPanel = g_pColorCorrectionUI->m_pOperationListPanel;
    if ( m_pOperationListPanel != nullptr )
      CColorOperationListPanel::Shutdown(this: m_pOperationListPanel);
  }
  free(pMem: this->m_pPreviewImage);
}

//------------------------------------------------------------------------------
// Address: 0x100A6E50
// Name: public: int CUtlSortVector<class Vector,class CCurvesColorOperation::CurvesLessFunc>::Find(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<Vector,CCurvesColorOperation::CurvesLessFunc>::Find(
        CUtlSortVector<Vector,CCurvesColorOperation::CurvesLessFunc> *this,
        const Vector *src)
{
  int v3; // edx
  int v4; // ecx
  Vector *m_pMemory; // esi
  float x; // xmm1_4
  int result; // eax
  float v8; // xmm0_4

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
         215,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/utlsortvector.h",
                            a2: 215,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
      a2: 215);
  }
  v3 = 0;
  v4 = this->m_Size - 1;
  if ( v4 >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    x = src->x;
    do
    {
      result = (v4 + v3) >> 1;
      v8 = m_pMemory[result].x;
      if ( x <= v8 )
      {
        if ( v8 <= x )
          return result;
        v4 = result - 1;
      }
      else
      {
        v3 = result + 1;
      }
    }
    while ( v3 <= v4 );
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100A6F00
// Name: public: int CUtlSortVector<class Vector,class CCurvesColorOperation::CurvesLessFunc>::FindLessOrEqual(class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<Vector,CCurvesColorOperation::CurvesLessFunc>::FindLessOrEqual(
        CUtlSortVector<Vector,CCurvesColorOperation::CurvesLessFunc> *this,
        const Vector *src)
{
  int v3; // edx
  int v4; // ecx
  Vector *m_pMemory; // esi
  float x; // xmm1_4
  int result; // eax
  float v8; // xmm0_4

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
         277,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/utlsortvector.h",
                            a2: 277,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
      a2: 277);
  }
  v3 = 0;
  v4 = this->m_Size - 1;
  if ( v4 >= 0 )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    x = src->x;
    do
    {
      result = (v4 + v3) >> 1;
      v8 = m_pMemory[result].x;
      if ( x <= v8 )
      {
        if ( v8 <= x )
          return result;
        v4 = result - 1;
      }
      else
      {
        v3 = result + 1;
      }
    }
    while ( v3 <= v4 );
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100A6FB0
// Name: public: void CColorOperationList::DeleteOperation(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorOperationList::DeleteOperation(CColorOperationList *this, int opIndex)
{
  int m_Size; // eax
  int v4; // eax

  if ( opIndex >= 0 )
  {
    m_Size = this->m_OpList.m_Size;
    if ( opIndex < m_Size )
    {
      v4 = m_Size - opIndex - 1;
      if ( v4 > 0 )
        _V_memmove(
          dest: &this->m_OpList.m_Memory.m_pMemory[opIndex],
          src: &this->m_OpList.m_Memory.m_pMemory[opIndex + 1],
          count: 4 * v4);
      --this->m_OpList.m_Size;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A6FF0
// Name: private: void CCurvesColorOperation::UpdateOutColorArray(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurvesColorOperation::UpdateOutColorArray(CCurvesColorOperation *this)
{
  CCurvesColorOperation *v1; // esi
  int v2; // edi
  CUtlSortVector<Vector,CCurvesColorOperation::CurvesLessFunc> *p_m_ControlPoints; // ebx
  float v4; // xmm0_4
  int LessOrEqual; // eax
  float y; // xmm0_4
  int m_Size; // ecx
  Vector *m_pMemory; // esi
  int v9; // eax
  float *v10; // eax
  Vector *pControlPoints; // [esp+10h] [ebp-38h] BYREF
  int v12; // [esp+14h] [ebp-34h]
  int v13; // [esp+18h] [ebp-30h]
  int v14; // [esp+1Ch] [ebp-2Ch]
  Vector vecOut; // [esp+20h] [ebp-28h] BYREF
  Vector src; // [esp+2Ch] [ebp-1Ch] BYREF
  CCurvesColorOperation *v17; // [esp+38h] [ebp-10h]
  float *m_pOutValue; // [esp+3Ch] [ebp-Ch]
  int i; // [esp+40h] [ebp-8h]
  float flInColor; // [esp+44h] [ebp-4h]

  v1 = this;
  v2 = 0;
  v17 = this;
  i = 0;
  src.y = 0.0;
  src.z = 0.0;
  p_m_ControlPoints = &this->m_ControlPoints;
  m_pOutValue = this->m_pOutValue;
  do
  {
    v4 = (float)v2 * 0.0039215689;
    if ( v4 >= 0.0 )
    {
      if ( v4 > 1.0 )
        v4 = 1.0;
    }
    else
    {
      v4 = 0.0;
    }
    flInColor = v4;
    src.x = v4;
    LessOrEqual = CUtlSortVector<Vector,CCurvesColorOperation::CurvesLessFunc>::FindLessOrEqual(
                    this: p_m_ControlPoints,
                    &src);
    if ( LessOrEqual >= 0 )
    {
      m_Size = v1->m_ControlPoints.m_Size;
      if ( LessOrEqual == m_Size - 1 )
      {
        y = p_m_ControlPoints->m_Memory.m_pMemory[m_Size - 1].y;
      }
      else
      {
        m_pMemory = p_m_ControlPoints->m_Memory.m_pMemory;
        if ( LessOrEqual < 1 )
          pControlPoints = p_m_ControlPoints->m_Memory.m_pMemory;
        else
          pControlPoints = &m_pMemory[LessOrEqual - 1];
        v12 = (int)&p_m_ControlPoints->m_Memory.m_pMemory[LessOrEqual];
        v9 = LessOrEqual + 2;
        v13 = v12 + 12;
        if ( v9 >= m_Size )
          v14 = (int)&m_pMemory[m_Size - 1];
        else
          v14 = (int)&m_pMemory[v9];
        ComputeSplinePoint((const Vector **)&pControlPoints, &vecOut, flInColor);
        y = vecOut.y;
        v1 = v17;
        v2 = i;
      }
    }
    else
    {
      y = p_m_ControlPoints->m_Memory.m_pMemory->y;
    }
    v10 = m_pOutValue;
    ++v2;
    *m_pOutValue = y;
    i = v2;
    m_pOutValue = v10 + 1;
  }
  while ( v2 < 256 );
}

//------------------------------------------------------------------------------
// Address: 0x100A7110
// Name: public: virtual bool CLevelsColorOperation::Serialize(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CLevelsColorOperation::Serialize(CLevelsColorOperation *this, CDmxElement *pElement)
{
  CDmxAttribute *v3; // edi
  _DWORD *m_pData; // edi
  CDmxAttribute *v5; // edi
  float *v6; // edi
  CDmxAttribute *v7; // edi
  _BYTE *v8; // edi
  CDmxAttribute *v9; // edi
  float *v10; // edi
  CDmxAttribute *v11; // edi
  float *v12; // edi
  CDmxAttribute *v13; // edi
  float *v14; // edi
  CDmxAttribute *v15; // edi
  float *v16; // edi
  CDmxAttribute *v17; // edi
  float *v18; // edi

  CDmxElement::SetName(this: pElement, pName: this->m_pName);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v3 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "channelMask");
  CDmxAttribute::AllocateDataMemory(this: v3, type: AT_INT);
  m_pData = v3->m_pData;
  if ( m_pData != nullptr )
    *m_pData = this->m_nChannelMask;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v5 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "blendFactor");
  CDmxAttribute::AllocateDataMemory(this: v5, type: AT_FLOAT);
  v6 = (float *)v5->m_pData;
  if ( v6 != nullptr )
    *v6 = this->m_flBlendFactor;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v7 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "enabled");
  CDmxAttribute::AllocateDataMemory(this: v7, type: AT_BOOL);
  v8 = v7->m_pData;
  if ( v8 != nullptr )
    *v8 = this->m_bEnable;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v9 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "minInputLevel");
  CDmxAttribute::AllocateDataMemory(this: v9, type: AT_FLOAT);
  v10 = (float *)v9->m_pData;
  if ( v10 != nullptr )
    *v10 = this->m_flMinInputLevel;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v11 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "midInputLevel");
  CDmxAttribute::AllocateDataMemory(this: v11, type: AT_FLOAT);
  v12 = (float *)v11->m_pData;
  if ( v12 != nullptr )
    *v12 = this->m_flMidInputLevel;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v13 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "maxInputLevel");
  CDmxAttribute::AllocateDataMemory(this: v13, type: AT_FLOAT);
  v14 = (float *)v13->m_pData;
  if ( v14 != nullptr )
    *v14 = this->m_flMaxInputLevel;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v15 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "minOutputLevel");
  CDmxAttribute::AllocateDataMemory(this: v15, type: AT_FLOAT);
  v16 = (float *)v15->m_pData;
  if ( v16 != nullptr )
    *v16 = this->m_flMinOutputLevel;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v17 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "maxOutputLevel");
  CDmxAttribute::AllocateDataMemory(this: v17, type: AT_FLOAT);
  v18 = (float *)v17->m_pData;
  if ( v18 != nullptr )
    *v18 = this->m_flMaxOutputLevel;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A7570
// Name: public: virtual void CColorLookupOperation::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorLookupOperation::Release(CColorLookupOperation *this)
{
  color24 *m_LookupTable; // eax

  if ( this != nullptr )
  {
    m_LookupTable = this->m_LookupTable;
    this->__vftable = (CColorLookupOperation_vtbl *)&CColorLookupOperation::`vftable';
    if ( m_LookupTable != nullptr )
    {
      this->m_Resolution = 0;
      free(pMem: m_LookupTable);
    }
    free(pMem: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A75B0
// Name: public: virtual bool CColorLookupOperation::Serialize(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CColorLookupOperation::Serialize(CColorLookupOperation *this, CDmxElement *pElement)
{
  CDmxAttribute *v3; // edi
  float *m_pData; // edi
  CDmxAttribute *v5; // edi
  _BYTE *v6; // edi
  CDmxAttribute *v7; // eax

  CDmxElement::SetName(this: pElement, pName: this->m_pName);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v3 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "blendFactor");
  CDmxAttribute::AllocateDataMemory(this: v3, type: AT_FLOAT);
  m_pData = (float *)v3->m_pData;
  if ( m_pData != nullptr )
    *m_pData = this->m_flBlendFactor;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v5 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "enabled");
  CDmxAttribute::AllocateDataMemory(this: v5, type: AT_BOOL);
  v6 = v5->m_pData;
  if ( v6 != nullptr )
    *v6 = this->m_bEnable;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v7 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "fileName");
  CDmxAttribute::SetValue(this: v7, pString: this->m_pFilename);
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A7680
// Name: public: virtual bool CColorLookupOperation::Unserialize(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CColorLookupOperation::Unserialize(CColorLookupOperation *this, CDmxElement *pElement)
{
  const char *Name; // eax
  const CDmxAttribute *Attribute; // eax
  int *m_pData; // eax
  const CDmxAttribute *v6; // eax
  char *v7; // eax
  const CDmxAttribute *v8; // eax
  const char *v9; // eax

  Name = CDmxElement::GetName(this: pElement);
  V_strncpy(pDest: this->m_pName, pSrc: Name, maxLen: 256);
  Attribute = CDmxElement::GetAttribute(this: pElement, pAttributeName: "blendFactor");
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
  this->m_flBlendFactor = *(float *)m_pData;
  v6 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "enabled");
  if ( v6 != nullptr )
  {
    if ( v6->m_Type == AT_BOOL )
    {
      v7 = (char *)v6->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<bool>'::`4'::defaultValue = 0;
      v7 = &`CDmxAttribute::GetValue<bool>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<bool>'::`4'::defaultValue = 0;
    v7 = &`CDmxElement::GetValue<bool>'::`4'::defaultValue;
  }
  this->m_bEnable = *v7;
  v8 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "fileName");
  if ( v8 != nullptr && v8->m_Type == AT_STRING )
  {
    v9 = CUtlString::operator char const *(this: (CUtlString *)v8->m_pData);
    CColorLookupOperation::LoadLookupTable(this, a2: (int)this, pFilename: v9);
    return 1;
  }
  else
  {
    CColorLookupOperation::LoadLookupTable(this, a2: (int)this, pFilename: defaultValue);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A7770
// Name: public: void CColorBalanceOperation::SetYellowBlueBalance(enum ColorBalanceMode_t,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorBalanceOperation::SetYellowBlueBalance(
        CColorBalanceOperation *this,
        ColorBalanceMode_t mode,
        float value)
{
  this->m_YellowBlueBalance[mode] = value;
  CColorBalanceOperation::CreateLookupTables(this);
  colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
}

//------------------------------------------------------------------------------
// Address: 0x100A77A0
// Name: public: virtual void CColorBalanceUIPanel::OnMessage(class KeyValues const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorBalanceUIPanel::OnMessage(CColorBalanceUIPanel *this, KeyValues *params, unsigned int fromPanel)
{
  const char *Name; // eax
  CPrecisionSlider *Ptr; // eax
  CColorBalanceOperation_vtbl *v6; // edi
  float v7; // xmm0_4
  KeyValues *v8; // eax
  KeyValues *v9; // eax
  CColorBalanceUIPanel_vtbl *v10; // edi
  int v11; // eax
  int CurrentMode; // eax
  CColorBalanceOperation *m_pBalanceOp; // ecx
  int v14; // eax
  ColorBalanceMode_t v15; // eax
  const char *v16; // eax
  int Int; // eax
  float value; // [esp+4h] [ebp-Ch]
  float fromPanela; // [esp+1Ch] [ebp+Ch]
  float fromPanelb; // [esp+1Ch] [ebp+Ch]

  vgui::Panel::OnMessage(this, params, ifromPanel: fromPanel);
  Name = KeyValues::GetName(this: params);
  if ( _V_stricmp(s1: "SliderMoved", s2: Name) != 0 )
  {
    v16 = KeyValues::GetName(this: params);
    if ( _V_stricmp(s1: "CheckButtonChecked", s2: v16) != 0
      || KeyValues::GetPtr(this: params, keyName: "panel", defaultValue: nullptr) != this->m_pPreserveLuminosityButton )
    {
      return;
    }
    Int = KeyValues::GetInt(this: params, keyName: "state", defaultValue: 0);
    m_pBalanceOp = this->m_pBalanceOp;
    m_pBalanceOp->m_PreserveLuminosity = Int != 0;
LABEL_16:
    CColorBalanceOperation::CreateLookupTables(this: m_pBalanceOp);
    colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
    return;
  }
  Ptr = (CPrecisionSlider *)KeyValues::GetPtr(this: params, keyName: "panel", defaultValue: nullptr);
  if ( Ptr == this->m_pBlendFactorSlider )
  {
    v6 = this->m_pBalanceOp->__vftable;
    v7 = (float)this->m_pBlendFactorSlider->GetValue(this: this->m_pBlendFactorSlider) * 0.0039215689;
    ((void (__thiscall *)(CColorBalanceOperation *, _DWORD))v6->SetBlendFactor)(a1: this->m_pBalanceOp, a2: LODWORD(v7));
    v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v8 != nullptr )
      v9 = KeyValues::KeyValues(this: v8, setName: "command", firstKey: "command", firstValue: "BlendFactorUpdate");
    else
      v9 = nullptr;
    v10 = this->__vftable;
    v11 = ((int (__thiscall *)(CColorBalanceUIPanel *, KeyValues *, _DWORD))this->GetParent)(a1: this, a2: v9, a3: 0.0);
    ((void (__thiscall *)(CColorBalanceUIPanel *, int))v10->PostMessage)(a1: this, a2: v11);
    return;
  }
  if ( Ptr == this->m_pCyanRedSlider )
  {
    fromPanela = (float)this->m_pCyanRedSlider->GetValue(this: this->m_pCyanRedSlider);
    CurrentMode = CColorBalanceUIPanel::GetCurrentMode(this);
    m_pBalanceOp = this->m_pBalanceOp;
    m_pBalanceOp->m_CyanRedBalance[CurrentMode] = fromPanela;
    goto LABEL_16;
  }
  if ( Ptr == this->m_pMagentaGreenSlider )
  {
    fromPanelb = (float)this->m_pMagentaGreenSlider->GetValue(this: this->m_pMagentaGreenSlider);
    v14 = CColorBalanceUIPanel::GetCurrentMode(this);
    m_pBalanceOp = this->m_pBalanceOp;
    m_pBalanceOp->m_MagentaGreenBalance[v14] = fromPanelb;
    goto LABEL_16;
  }
  if ( Ptr == this->m_pYellowBlueSlider )
  {
    value = (float)this->m_pYellowBlueSlider->GetValue(this: this->m_pYellowBlueSlider);
    v15 = CColorBalanceUIPanel::GetCurrentMode(this);
    CColorBalanceOperation::SetYellowBlueBalance(this: this->m_pBalanceOp, mode: v15, value);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A79A0
// Name: private: virtual void CColorOperationListPanel::OnOpPanelClose(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorOperationListPanel::OnOpPanelClose(CColorOperationListPanel *this, KeyValues *data)
{
  CColorCorrectionUIChildPanel *Ptr; // edi
  int m_Size; // ecx
  int v5; // eax
  CColorCorrectionUIChildPanel **m_pMemory; // edx
  int v7; // ecx

  Ptr = (CColorCorrectionUIChildPanel *)KeyValues::GetPtr(this: data, keyName: "panel", defaultValue: nullptr);
  if ( Ptr != nullptr )
  {
    m_Size = this->m_OpPanelList.m_Size;
    v5 = 0;
    if ( m_Size <= 0 )
    {
LABEL_6:
      v7 = -1;
    }
    else
    {
      m_pMemory = this->m_OpPanelList.m_Memory.m_pMemory;
      while ( *m_pMemory != Ptr )
      {
        ++v5;
        ++m_pMemory;
        if ( v5 >= m_Size )
          goto LABEL_6;
      }
      v7 = v5;
    }
    if ( this->m_OpPanelList.m_Size - v7 - 1 > 0 )
      _V_memmove(
        dest: &this->m_OpPanelList.m_Memory.m_pMemory[v7],
        src: &this->m_OpPanelList.m_Memory.m_pMemory[v7 + 1],
        count: 4 * (this->m_OpPanelList.m_Size - v7 - 1));
    --this->m_OpPanelList.m_Size;
    Ptr->Shutdown(this: Ptr);
    ((void (__thiscall *)(CColorCorrectionUIChildPanel *, int))Ptr->dtr_Panel)(a1: Ptr, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A7A40
// Name: private: bool CColorOperationListPanel::SaveRawFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __thiscall CColorOperationListPanel::SaveRawFile(CColorOperationListPanel *this, const char *pFullPath)
{
  const char *v2; // edi
  CP4File *v3; // esi
  bool (__thiscall *Edit)(CP4File *); // edx
  void *v5; // ebx
  __int16 v7; // si
  RGBX5551_t v8; // si
  RGBX5551_t v9; // si
  int j; // edi
  int v11; // eax
  char *v12; // edx
  bool v13; // zf
  CP4File *v14; // edi
  bool (__thiscall *v15)(CP4File *); // edx
  void *v16; // ebx
  CP4File *v17; // esi
  __int16 v18; // si
  RGBX5551_t v19; // si
  RGBX5551_t v20; // si
  int m; // edi
  int v22; // eax
  char *v23; // edx
  CP4File *v24; // esi
  CP4File *m_p; // esi
  char pFilename360[260]; // [esp+Ch] [ebp-118h] BYREF
  CP4AutoEditAddFile co; // [esp+110h] [ebp-14h]
  CP4File *outColor; // [esp+114h] [ebp-10h] OVERLAPPED BYREF
  int i; // [esp+118h] [ebp-Ch]
  int k; // [esp+11Ch] [ebp-8h]
  RGBX5551_t inColor; // [esp+120h] [ebp-4h]

  v2 = pFullPath;
  v3 = CP4Factory::AccessFile(this: g_p4factory, szFilename: pFullPath);
  Edit = v3->Edit;
  co.m_spImpl.m_p = v3;
  Edit(this: v3);
  v5 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: v2, a3: "wb", a4: 0);
  if ( v5 != nullptr )
  {
    v7 = *(_WORD *)&inColor & 0x83FF;
    for ( i = 32; i != 0; --i )
    {
      v8 = (RGBX5551_t)(v7 & 0xFC1F);
      k = 32;
      do
      {
        v9 = (RGBX5551_t)(*(_WORD *)&v8 & 0xFFE0);
        inColor = v9;
        for ( j = 32; j != 0; --j )
        {
          v11 = (*(_BYTE *)&v9 & 0x1F)
              + 32 * (((*(unsigned __int16 *)&v9 >> 5) & 0x1F) + 32 * ((*(unsigned __int16 *)&v9 >> 10) & 0x1F));
          v12 = (char *)g_pColorCorrectionUI + 2 * v11;
          LOWORD(outColor) = *(_WORD *)&v12[v11 + 556];
          BYTE2(outColor) = v12[v11 + 558];
          g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: &outColor, a3: 3, a4: v5);
          v9 = (RGBX5551_t)((*(_BYTE *)&inColor ^ (unsigned __int8)(*(_BYTE *)&inColor + 1)) & 0x1F ^ *(_WORD *)&v9);
          inColor = v9;
        }
        v8 = (RGBX5551_t)((*(_WORD *)&inColor ^ ((*(_WORD *)&inColor & 0xFFE0) + 32)) & 0x3E0 ^ *(_WORD *)&v9);
        v13 = k-- == 1;
        inColor = v8;
      }
      while ( !v13 );
      v7 = (*(_WORD *)&inColor ^ ((*(_WORD *)&inColor & 0xFC00) + 1024)) & 0x7C00 ^ *(_WORD *)&v8;
    }
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v5);
    memset(pFilename360, 0, sizeof(pFilename360));
    V_StripExtension(in: pFullPath, out: pFilename360, outSize: 260);
    V_DefaultExtension(path: pFilename360, extension: ".pwl.raw", pathStringLength: 260);
    v14 = CP4Factory::AccessFile(this: g_p4factory, szFilename: pFilename360);
    v15 = v14->Edit;
    outColor = v14;
    v15(this: v14);
    v16 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: pFilename360, a3: "wb", a4: 0);
    if ( v16 != nullptr )
    {
      v18 = v7 & 0x83FF;
      for ( k = 32; k != 0; --k )
      {
        v19 = (RGBX5551_t)(v18 & 0xFC1F);
        i = 32;
        do
        {
          v20 = (RGBX5551_t)(*(_WORD *)&v19 & 0xFFE0);
          inColor = v20;
          for ( m = 32; m != 0; --m )
          {
            v22 = (*(_BYTE *)&v20 & 0x1F)
                + 32 * (((*(unsigned __int16 *)&v20 >> 5) & 0x1F) + 32 * ((*(unsigned __int16 *)&v20 >> 10) & 0x1F));
            v23 = (char *)g_pColorCorrectionUI + 2 * v22;
            LOWORD(pFullPath) = *(_WORD *)&v23[v22 + 98860];
            BYTE2(pFullPath) = v23[v22 + 98862];
            g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: &pFullPath, a3: 3, a4: v16);
            v20 = (RGBX5551_t)((*(_BYTE *)&inColor ^ (unsigned __int8)(*(_BYTE *)&inColor + 1)) & 0x1F ^ *(_WORD *)&v20);
            inColor = v20;
          }
          v19 = (RGBX5551_t)((*(_WORD *)&inColor ^ ((*(_WORD *)&inColor & 0xFFE0) + 32)) & 0x3E0 ^ *(_WORD *)&v20);
          v13 = i-- == 1;
          inColor = v19;
        }
        while ( !v13 );
        v18 = (*(_WORD *)&inColor ^ ((*(_WORD *)&inColor & 0xFC00) + 1024)) & 0x7C00 ^ *(_WORD *)&v19;
      }
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v16);
      v24 = outColor;
      outColor->Add(this: outColor);
      ((void (__thiscall *)(CP4File *, int))v24->dtr_CP4File)(a1: v24, a2: 1);
      m_p = co.m_spImpl.m_p;
      co.m_spImpl.m_p->Add(this: co.m_spImpl.m_p);
      ((void (__thiscall *)(CP4File *, int))m_p->dtr_CP4File)(a1: m_p, a2: 1);
      return 1;
    }
    else
    {
      v14->Add(this: v14);
      ((void (__thiscall *)(CP4File *, int))v14->dtr_CP4File)(a1: v14, a2: 1);
      v17 = co.m_spImpl.m_p;
      co.m_spImpl.m_p->Add(this: co.m_spImpl.m_p);
      ((void (__thiscall *)(CP4File *, int))v17->dtr_CP4File)(a1: v17, a2: 1);
      return 0;
    }
  }
  else
  {
    v3->Add(this: v3);
    ((void (__thiscall *)(CP4File *, int))v3->dtr_CP4File)(a1: v3, a2: 1);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A7F00
// Name: public: void CColorOperationList::BringForward(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorOperationList::BringForward(CColorOperationList *this, IColorOperation *opIndex)
{
  IColorOperation *v2; // esi
  IColorOperation *m_Size; // eax
  IColorOperation **v5; // ecx
  int v6; // eax

  v2 = opIndex;
  if ( (int)opIndex >= 0 )
  {
    m_Size = (IColorOperation *)this->m_OpList.m_Size;
    if ( (int)opIndex < (int)m_Size && opIndex != nullptr )
    {
      v5 = &this->m_OpList.m_Memory.m_pMemory[(_DWORD)opIndex];
      v6 = (char *)m_Size - (char *)opIndex - 1;
      opIndex = this->m_OpList.m_Memory.m_pMemory[(_DWORD)opIndex];
      if ( v6 > 0 )
        _V_memmove(dest: v5, src: v5 + 1, count: 4 * v6);
      --this->m_OpList.m_Size;
      CUtlVector<RequestContext *,CUtlMemory<RequestContext *,int>>::InsertBefore(
        (CUtlVector<vgui::PageTab *,CUtlMemory<vgui::PageTab *,int> > *)this,
        elem: (int)&v2[-1].__vftable + 3,
        src: (vgui::PageTab **)&opIndex);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A7F60
// Name: public: void CColorOperationList::PushBack(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorOperationList::PushBack(CColorOperationList *this, int opIndex)
{
  int m_Size; // eax
  int v4; // eax
  IColorOperation **v5; // ecx
  IColorOperation *v6; // ebx
  int v7; // eax
  int m_nAllocationCount; // ecx
  int v9; // edi
  IColorOperation **m_pMemory; // ecx
  int v11; // eax
  IColorOperation **v12; // eax

  if ( opIndex >= 0 )
  {
    m_Size = this->m_OpList.m_Size;
    if ( opIndex < m_Size && opIndex != m_Size - 1 )
    {
      v4 = m_Size - opIndex - 1;
      v5 = &this->m_OpList.m_Memory.m_pMemory[opIndex];
      v6 = *v5;
      if ( v4 > 0 )
        _V_memmove(dest: v5, src: v5 + 1, count: 4 * v4);
      v7 = --this->m_OpList.m_Size;
      m_nAllocationCount = this->m_OpList.m_Memory.m_nAllocationCount;
      v9 = opIndex + 1;
      if ( v7 + 1 > m_nAllocationCount )
        CUtlMemory<INetMessage *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: v7 - m_nAllocationCount + 1);
      ++this->m_OpList.m_Size;
      m_pMemory = this->m_OpList.m_Memory.m_pMemory;
      v11 = this->m_OpList.m_Size - v9 - 1;
      this->m_OpList.m_pElements = this->m_OpList.m_Memory.m_pMemory;
      if ( v11 > 0 )
        _V_memmove(dest: &m_pMemory[v9 + 1], src: &m_pMemory[v9], count: 4 * v11);
      v12 = &this->m_OpList.m_Memory.m_pMemory[v9];
      if ( v12 != nullptr )
        *v12 = v6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A8000
// Name: public: virtual CColorOperationListPanel::~CColorOperationListPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorOperationListPanel::~CColorOperationListPanel(CColorOperationListPanel *this)
{
  bool v2; // sf

  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CColorOperationListPanel_vtbl *)&CColorOperationListPanel::`vftable'{for `vgui::EditablePanel'};
  this->vgui::IFileOpenStateMachineClient::__vftable = (vgui::IFileOpenStateMachineClient_vtbl *)&CColorOperationListPanel::`vftable'{for `vgui::IFileOpenStateMachineClient'};
  v2 = this->m_FileName.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_FileName.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_FileName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FileName.m_Storage.m_Memory.m_pMemory);
      this->m_FileName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_FileName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_OpPanelList);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_OperationList);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A8080
// Name: public: virtual struct vgui::PanelMessageMap __near * CColorOperationListPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CColorOperationListPanel::GetMessageMap(CColorOperationListPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CColorOperationListPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorOperationListPanel::GetMessageMap'::`2'::s_pMap;
  `CColorOperationListPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CColorOperationListPanel");
  `CColorOperationListPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A80B0
// Name: public: virtual struct PanelAnimationMap __near * CColorOperationListPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CColorOperationListPanel::GetAnimMap(CColorOperationListPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CColorOperationListPanel");
}

//------------------------------------------------------------------------------
// Address: 0x100A80C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CColorOperationListPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CColorOperationListPanel::GetKBMap(CColorOperationListPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CColorOperationListPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorOperationListPanel::GetKBMap'::`2'::s_pMap;
  `CColorOperationListPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CColorOperationListPanel");
  `CColorOperationListPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A80F0
// Name: public: int CUtlSortVector<class Vector,class CCurvesColorOperation::CurvesLessFunc>::Insert(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlSortVector<Vector,CCurvesColorOperation::CurvesLessFunc>::Insert(
        CUtlSortVector<Vector,CCurvesColorOperation::CurvesLessFunc> *this,
        const Vector *src)
{
  int LessOrEqual; // eax
  int m_nAllocationCount; // ecx
  int v5; // edi
  int m_Size; // eax
  Vector *m_pMemory; // ecx
  int v8; // eax
  Vector *v9; // eax

  if ( this->m_bNeedsSort
    && _LoggingSystem_LogAssert(
         a1: "%s (%d) : %s\n",
         "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
         150,
         "Assertion Failed: !m_bNeedsSort") == 1 )
  {
    if ( (unsigned __int8)_ShouldUseNewAssertDialog() == 0
      || (unsigned __int8)_DoNewAssertDialog(
                            a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier"
                            "1/utlsortvector.h",
                            a2: 150,
                            a3: "Assertion Failed: !m_bNeedsSort") != 0 )
    {
      __debugbreak();
    }
    __ExitOnFatalAssert(
      a1: "C:\\buildbot\\slave\\cstrike15_win32_xbox_daily\\build\\source\\cstrike15\\src\\public\\tier1/utlsortvector.h",
      a2: 150);
  }
  LessOrEqual = CUtlSortVector<Vector,CCurvesColorOperation::CurvesLessFunc>::FindLessOrEqual(this, src);
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  v5 = LessOrEqual + 1;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size - v5 - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v5 + 1], src: &m_pMemory[v5], count: 12 * v8);
  v9 = &this->m_Memory.m_pMemory[v5];
  if ( v9 != nullptr )
    *v9 = *src;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100A81E0
// Name: public: static void CPrecisionSlider::PanelMessageFunc_OnTextNewLine::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CPrecisionSlider::PanelMessageFunc_OnTextNewLine::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CPrecisionSlider::PanelMessageFunc_OnTextNewLine::InitVar'::`2'::bAdded )
  {
    `CPrecisionSlider::PanelMessageFunc_OnTextNewLine::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CPrecisionSlider");
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "TextNewLine";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::PropertyPage::`vcall'{944,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][0]) = 1;
    *(_QWORD *)&v3.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A8280
// Name: public: CPrecisionSlider::CPrecisionSlider(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CPrecisionSlider *__thiscall CPrecisionSlider::CPrecisionSlider(
        CPrecisionSlider *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::TextEntry *v7; // eax
  vgui::TextEntry *v8; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Slider::Slider(this, parent, panelName);
  this->__vftable = (CPrecisionSlider_vtbl *)&CPrecisionSlider::`vftable';
  if ( `CPrecisionSlider::ChainToMap'::`2'::chained == 0 )
  {
    `CPrecisionSlider::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CPrecisionSlider");
    v4->pfnClassName = CPrecisionSlider::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Slider");
  }
  if ( `CPrecisionSlider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPrecisionSlider::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CPrecisionSlider");
    v5->pfnClassName = CPrecisionSlider::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Slider");
  }
  if ( `CPrecisionSlider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPrecisionSlider::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CPrecisionSlider");
    v6->pfnClassName = CPrecisionSlider::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Slider");
  }
  CPrecisionSlider::PanelMessageFunc_OnTextNewLine::InitVar(a1: (int)&savedregs);
  v7 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v7 != nullptr )
    v8 = vgui::TextEntry::TextEntry(this: v7, parent: this, panelName: "PrecisionEditPanel");
  else
    v8 = nullptr;
  this->m_pTextEntry = v8;
  v8->SendNewLine(this: v8, a2: true);
  this->m_pTextEntry->SetCatchEnterKey(this: this->m_pTextEntry, a2: true);
  this->m_pTextEntry->AddActionSignalTarget_2(this: this->m_pTextEntry, a2: this);
  this->m_nTextEntryWidth = 32;
  this->m_nSpacing = 8;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A83B0
// Name: public: void CColorOperationList::AddOperation(class IColorOperation __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorOperationList::AddOperation(CColorOperationList *this, IColorOperation *pOp)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  IColorOperation **m_pMemory; // ecx
  int v6; // eax
  IColorOperation **v7; // eax

  m_nAllocationCount = this->m_OpList.m_Memory.m_nAllocationCount;
  m_Size = this->m_OpList.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow((CUtlMemory<S3RGBA,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_OpList.m_Size;
  m_pMemory = this->m_OpList.m_Memory.m_pMemory;
  v6 = this->m_OpList.m_Size - m_Size - 1;
  this->m_OpList.m_pElements = this->m_OpList.m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &this->m_OpList.m_Memory.m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = pOp;
}

//------------------------------------------------------------------------------
// Address: 0x100A8410
// Name: public: int CCurvesColorOperation::ModifyControlPoint(int,float,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCurvesColorOperation::ModifyControlPoint(
        CCurvesColorOperation *this,
        int nPoint,
        float flInValue,
        float flOutValue)
{
  Vector *m_pMemory; // eax
  float y; // ebx
  int v7; // eax
  int v8; // esi
  Vector temp; // [esp+Ch] [ebp-Ch] BYREF

  m_pMemory = this->m_ControlPoints.m_Memory.m_pMemory;
  temp.x = m_pMemory[nPoint].x;
  y = m_pMemory[nPoint].y;
  temp.z = m_pMemory[nPoint].z;
  v7 = this->m_ControlPoints.m_Size - nPoint - 1;
  temp.y = y;
  if ( v7 > 0 )
    _V_memmove(
      dest: &this->m_ControlPoints.m_Memory.m_pMemory[nPoint],
      src: &this->m_ControlPoints.m_Memory.m_pMemory[nPoint + 1],
      count: 12 * v7);
  --this->m_ControlPoints.m_Size;
  temp.x = flInValue;
  temp.y = flOutValue;
  CUtlSortVector<Vector,CCurvesColorOperation::CurvesLessFunc>::Insert(this: &this->m_ControlPoints, src: &temp);
  v8 = CUtlSortVector<Vector,CCurvesColorOperation::CurvesLessFunc>::Find(this: &this->m_ControlPoints, src: &temp);
  CCurvesColorOperation::UpdateOutColorArray(this);
  colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x100A84C0
// Name: public: void CCurvesColorOperation::RemoveControlPoint(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurvesColorOperation::RemoveControlPoint(CCurvesColorOperation *this, int nPoint)
{
  if ( nPoint != 0 && nPoint != this->m_ControlPoints.m_Size - 1 )
  {
    if ( this->m_ControlPoints.m_Size - nPoint - 1 > 0 )
      _V_memmove(
        dest: &this->m_ControlPoints.m_Memory.m_pMemory[nPoint],
        src: &this->m_ControlPoints.m_Memory.m_pMemory[nPoint + 1],
        count: 12 * (this->m_ControlPoints.m_Size - nPoint - 1));
    --this->m_ControlPoints.m_Size;
    CCurvesColorOperation::UpdateOutColorArray(this);
    colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A8530
// Name: protected: virtual int CColorCurvesEditPanel::FindOrAddControlPoint(float,float,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CColorCurvesEditPanel::FindOrAddControlPoint(
        CColorCurvesEditPanel *this,
        float flIn,
        float flTolerance,
        float flOut)
{
  CCurvesColorOperation *m_pCurvesOp; // esi
  int result; // eax
  int v6; // edi
  Vector src; // [esp+Ch] [ebp-Ch] BYREF

  m_pCurvesOp = this->m_pCurvesOp;
  result = CCurvesColorOperation::FindControlPoint(this: m_pCurvesOp, flInValue: flIn, flTolerance);
  if ( result == -1 )
  {
    src.x = flIn;
    src.y = flOut;
    src.z = 0.0;
    CUtlSortVector<Vector,CCurvesColorOperation::CurvesLessFunc>::Insert(this: &m_pCurvesOp->m_ControlPoints, &src);
    v6 = CUtlSortVector<Vector,CCurvesColorOperation::CurvesLessFunc>::Find(this: &m_pCurvesOp->m_ControlPoints, &src);
    CCurvesColorOperation::UpdateOutColorArray(this: m_pCurvesOp);
    colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A85C0
// Name: protected: virtual int CColorCurvesEditPanel::ModifyControlPoint(int,float,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CColorCurvesEditPanel::ModifyControlPoint(
        CColorCurvesEditPanel *this,
        int nPoint,
        float flIn,
        float flOut)
{
  CCurvesColorOperation::ModifyControlPoint(this: this->m_pCurvesOp, nPoint, flInValue: flIn, flOutValue: flOut);
  return nPoint;
}

//------------------------------------------------------------------------------
// Address: 0x100A8600
// Name: public: static void CColorCurvesUIPanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CColorCurvesUIPanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CColorCurvesUIPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CColorCurvesUIPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CColorCurvesUIPanel");
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "TextChanged";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::FileOpenDialog::`vcall'{1132,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][0]) = 1;
    *(_QWORD *)&v3.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A86A0
// Name: public: CColorCurvesUIPanel::CColorCurvesUIPanel(class vgui::Panel __near *,class CCurvesColorOperation __near *)
// Source: json
//------------------------------------------------------------------------------
CColorCurvesUIPanel *__thiscall CColorCurvesUIPanel::CColorCurvesUIPanel(
        CColorCurvesUIPanel *this,
        vgui::Panel *pParent,
        CCurvesColorOperation *pOp)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::ComboBox *v7; // eax
  vgui::ComboBox *v8; // eax
  const char **v9; // edi
  CPrecisionSlider *v10; // eax
  CPrecisionSlider *v11; // eax
  CColorCurvesEditPanel *v12; // eax
  CColorCurvesEditPanel *v13; // eax
  CCurvesColorOperation *m_pColorOp; // ecx
  void (__thiscall *SetVisible)(vgui::Panel *, bool); // edx
  vgui::ComboBox *m_pColorMask; // ecx
  void (__thiscall *ActivateItem)(vgui::ComboBox *, int); // edx
  CPrecisionSlider_vtbl *v18; // edi
  double v19; // st7
  int v21; // [esp-4h] [ebp-10h]
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  CColorCorrectionUIChildPanel::CColorCorrectionUIChildPanel(this, parent: pParent, name: "ColorCurvesUIPanel");
  this->__vftable = (CColorCurvesUIPanel_vtbl *)&CColorCurvesUIPanel::`vftable';
  if ( `CColorCurvesUIPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CColorCurvesUIPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CColorCurvesUIPanel");
    v4->pfnClassName = CColorCurvesUIPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CColorCorrectionUIChildPanel");
  }
  if ( `CColorCurvesUIPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CColorCurvesUIPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CColorCurvesUIPanel");
    v5->pfnClassName = CColorCurvesUIPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CColorCorrectionUIChildPanel");
  }
  if ( `CColorCurvesUIPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CColorCurvesUIPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CColorCurvesUIPanel");
    v6->pfnClassName = CColorCurvesUIPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CColorCorrectionUIChildPanel");
  }
  CColorCurvesUIPanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  v7 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v7 != nullptr )
    v8 = vgui::ComboBox::ComboBox(this: v7, parent: this, panelName: "ColorMask", numLines: 4, allowEdit: false);
  else
    v8 = nullptr;
  this->m_pColorMask = v8;
  v9 = CColorCurvesUIPanel::s_pColorMaskLabel;
  do
    this->m_pColorMask->AddItem_2(this: this->m_pColorMask, a2: *v9++, a3: nullptr);
  while ( (int)v9 < (int)CColorLevelsUIPanel::s_pColorMaskLabel );
  this->m_pColorMask->AddActionSignalTarget_2(this: this->m_pColorMask, a2: this);
  v10 = (CPrecisionSlider *)MemAlloc_Alloc(nSize: 0x1BCu);
  if ( v10 != nullptr )
    v11 = CPrecisionSlider::CPrecisionSlider(this: v10, parent: this, panelName: "BlendFactorSlider");
  else
    v11 = nullptr;
  this->m_pBlendFactorSlider = v11;
  v11->SetRange(this: v11, a2: 0, a3: 255);
  this->m_pBlendFactorSlider->AddActionSignalTarget_2(this: this->m_pBlendFactorSlider, a2: this);
  this->m_pColorOp = pOp;
  v12 = (CColorCurvesEditPanel *)MemAlloc_Alloc(nSize: 0x160u);
  if ( v12 != nullptr )
    v13 = CColorCurvesEditPanel::CColorCurvesEditPanel(this: v12, pParent: this, pName: "CurveEditor");
  else
    v13 = nullptr;
  m_pColorOp = this->m_pColorOp;
  this->m_pCurveEditor = v13;
  SetVisible = v13->SetVisible;
  v13->m_pCurvesOp = m_pColorOp;
  SetVisible(this: v13, a2: m_pColorOp != nullptr);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource\\ColorCurvesUIPanel.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  m_pColorMask = this->m_pColorMask;
  if ( pOp->m_nChannelMask == 1 )
  {
    v21 = 1;
    goto LABEL_25;
  }
  if ( pOp->m_nChannelMask == 2 )
  {
    v21 = 2;
LABEL_25:
    ((void (__stdcall *)(int))m_pColorMask->ActivateItem)(a1: v21);
    goto LABEL_26;
  }
  ActivateItem = m_pColorMask->ActivateItem;
  if ( pOp->m_nChannelMask == 4 )
    ((void (__stdcall *)(int))ActivateItem)(a1: 3);
  else
    ((void (__stdcall *)(_DWORD))ActivateItem)(a1: 0);
LABEL_26:
  v18 = this->m_pBlendFactorSlider->__vftable;
  v19 = ((double (__thiscall *)(CCurvesColorOperation *, int))pOp->GetBlendFactor)(a1: pOp, a2: 1) * 255.0;
  ((void (__thiscall *)(CPrecisionSlider *, int))v18->SetValue)(a1: this->m_pBlendFactorSlider, a2: (int)v19);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A88E0
// Name: public: static void CColorLevelsUIPanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CColorLevelsUIPanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CColorLevelsUIPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CColorLevelsUIPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CColorLevelsUIPanel");
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "TextChanged";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::FileOpenDialog::`vcall'{1132,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][0]) = 1;
    *(_QWORD *)&v3.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A8980
// Name: public: CColorLevelsUIPanel::CColorLevelsUIPanel(class vgui::Panel __near *,class CLevelsColorOperation __near *)
// Source: json
//------------------------------------------------------------------------------
CColorLevelsUIPanel *__thiscall CColorLevelsUIPanel::CColorLevelsUIPanel(
        CColorLevelsUIPanel *this,
        vgui::Panel *pParent,
        CLevelsColorOperation *pOp)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::ComboBox *v7; // eax
  vgui::ComboBox *v8; // eax
  const char **v9; // edi
  CPrecisionSlider *v10; // eax
  CPrecisionSlider *v11; // eax
  CColorSlider *v12; // eax
  CColorSlider *v13; // eax
  CColorSlider *v14; // eax
  CColorSlider *v15; // eax
  CColorHistogramPanel *v17; // eax
  CColorHistogramPanel *v18; // eax
  CPrecisionSlider_vtbl *v19; // edi
  double v20; // st7
  CColorSlider *m_pInputLevelSlider; // edi
  float m_flMinInputLevel; // xmm0_4
  bool v23; // cc
  KeyValues *v24; // eax
  KeyValues *v25; // eax
  float v26; // xmm0_4
  CColorSlider *v27; // edi
  float v28; // xmm1_4
  KeyValues *v29; // eax
  KeyValues *v30; // eax
  float v31; // xmm0_4
  CColorSlider *v32; // edi
  float v33; // xmm1_4
  KeyValues *v34; // eax
  KeyValues *v35; // eax
  float m_flMinOutputLevel; // xmm1_4
  CColorSlider *m_pOutputLevelSlider; // edi
  float v38; // xmm0_4
  KeyValues *v39; // eax
  KeyValues *v40; // eax
  float v41; // xmm0_4
  CColorSlider *v42; // edi
  float v43; // xmm1_4
  KeyValues *v44; // eax
  KeyValues *v45; // eax
  int v46; // ebx
  void (__thiscall *ActivateItem)(vgui::ComboBox *, int); // eax
  int v48; // ebx
  CLevelsColorOperation *m_pLevelsOp; // ecx
  float v50; // xmm0_4
  int savedregs; // [esp+Ch] [ebp+0h] BYREF
  float flMaxValue; // [esp+14h] [ebp+8h]
  float flMaxValuea; // [esp+14h] [ebp+8h]
  float flMaxValueb; // [esp+14h] [ebp+8h]
  float flMidValue; // [esp+18h] [ebp+Ch]

  CColorCorrectionUIChildPanel::CColorCorrectionUIChildPanel(this, parent: pParent, name: "LevelsUIPanel");
  this->__vftable = (CColorLevelsUIPanel_vtbl *)&CColorLevelsUIPanel::`vftable';
  if ( `CColorLevelsUIPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CColorLevelsUIPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CColorLevelsUIPanel");
    v4->pfnClassName = CColorLevelsUIPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CColorCorrectionUIChildPanel");
  }
  if ( `CColorLevelsUIPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CColorLevelsUIPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CColorLevelsUIPanel");
    v5->pfnClassName = CColorLevelsUIPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CColorCorrectionUIChildPanel");
  }
  if ( `CColorLevelsUIPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CColorLevelsUIPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CColorLevelsUIPanel");
    v6->pfnClassName = CColorLevelsUIPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CColorCorrectionUIChildPanel");
  }
  CColorLevelsUIPanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  v7 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v7 != nullptr )
    v8 = vgui::ComboBox::ComboBox(this: v7, parent: this, panelName: "ColorMask", numLines: 4, allowEdit: false);
  else
    v8 = nullptr;
  this->m_pColorMask = v8;
  v9 = CColorLevelsUIPanel::s_pColorMaskLabel;
  do
    this->m_pColorMask->AddItem_2(this: this->m_pColorMask, a2: *v9++, a3: nullptr);
  while ( (int)v9 < (int)CSelectedHSVUIPanel::s_pSelectionMethodNames );
  this->m_pColorMask->AddActionSignalTarget_2(this: this->m_pColorMask, a2: this);
  v10 = (CPrecisionSlider *)MemAlloc_Alloc(nSize: 0x1BCu);
  if ( v10 != nullptr )
    v11 = CPrecisionSlider::CPrecisionSlider(this: v10, parent: this, panelName: "BlendFactorSlider");
  else
    v11 = nullptr;
  this->m_pBlendFactorSlider = v11;
  v11->SetRange(this: v11, a2: 0, a3: 255);
  this->m_pBlendFactorSlider->AddActionSignalTarget_2(this: this->m_pBlendFactorSlider, a2: this);
  v12 = (CColorSlider *)MemAlloc_Alloc(nSize: 0x170u);
  if ( v12 != nullptr )
    v13 = CColorSlider::CColorSlider(this: v12, pParent: this, pName: "InputLevelSlider", nKnobCount: 3);
  else
    v13 = nullptr;
  this->m_pInputLevelSlider = v13;
  v13->m_nMinValue = 0;
  v13->m_nMaxValue = 255;
  this->m_pInputLevelSlider->AddActionSignalTarget_2(this: this->m_pInputLevelSlider, a2: this);
  v14 = (CColorSlider *)MemAlloc_Alloc(nSize: 0x170u);
  if ( v14 != nullptr )
    v15 = CColorSlider::CColorSlider(this: v14, pParent: this, pName: "OutputLevelSlider", nKnobCount: 2);
  else
    v15 = nullptr;
  this->m_pOutputLevelSlider = v15;
  v15->m_nMinValue = 0;
  v15->m_nMaxValue = 255;
  this->m_pOutputLevelSlider->AddActionSignalTarget_2(this: this->m_pOutputLevelSlider, a2: this);
  this->m_pLevelsOp = pOp;
  v17 = (CColorHistogramPanel *)MemAlloc_Alloc(nSize: 0x55Cu);
  if ( v17 != nullptr )
    v18 = CColorHistogramPanel::CColorHistogramPanel(this: v17, pParent: this, pName: "Histogram", pOp);
  else
    v18 = nullptr;
  this->m_pHistogramPanel = v18;
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource\\ColorLevelsUIPanel.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  v19 = this->m_pBlendFactorSlider->__vftable;
  v20 = ((double (__thiscall *)(CLevelsColorOperation *, int))pOp->GetBlendFactor)(a1: pOp, a2: 1) * 255.0;
  ((void (__thiscall *)(CPrecisionSlider *, int))v19->SetValue)(a1: this->m_pBlendFactorSlider, a2: (int)v20);
  m_pInputLevelSlider = this->m_pInputLevelSlider;
  flMidValue = pOp->m_flMidInputLevel;
  flMaxValue = pOp->m_flMaxInputLevel;
  m_flMinInputLevel = pOp->m_flMinInputLevel;
  if ( m_flMinInputLevel >= 0.0 )
  {
    if ( m_flMinInputLevel > 1.0 )
      m_flMinInputLevel = 1.0;
  }
  else
  {
    m_flMinInputLevel = 0.0;
  }
  v23 = m_flMinInputLevel <= m_pInputLevelSlider->m_flKnobPosition[1];
  m_pInputLevelSlider->m_flKnobPosition[0] = m_flMinInputLevel;
  if ( !v23 )
    m_pInputLevelSlider->m_flKnobPosition[1] = m_flMinInputLevel;
  if ( m_flMinInputLevel > m_pInputLevelSlider->m_flKnobPosition[2] )
    m_pInputLevelSlider->m_flKnobPosition[2] = m_flMinInputLevel;
  v24 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v24 != nullptr )
    v25 = KeyValues::KeyValues(this: v24, setName: "SliderMoved", firstKey: "knob", firstValue: 0);
  else
    v25 = nullptr;
  m_pInputLevelSlider->PostActionSignal(this: m_pInputLevelSlider, a2: v25);
  v26 = 0.0;
  v27 = this->m_pInputLevelSlider;
  if ( flMidValue >= 0.0 )
  {
    v26 = 1.0;
    if ( flMidValue <= 1.0 )
      v26 = flMidValue;
  }
  v28 = v27->m_flKnobPosition[0];
  v27->m_flKnobPosition[2] = v26;
  if ( v28 > v26 )
    v27->m_flKnobPosition[0] = v26;
  if ( v26 > v27->m_flKnobPosition[1] )
    v27->m_flKnobPosition[1] = v26;
  v29 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v29 != nullptr )
    v30 = KeyValues::KeyValues(this: v29, setName: "SliderMoved", firstKey: "knob", firstValue: 2);
  else
    v30 = nullptr;
  v27->PostActionSignal(this: v27, a2: v30);
  v31 = 0.0;
  v32 = this->m_pInputLevelSlider;
  if ( flMaxValue >= 0.0 )
  {
    v31 = 1.0;
    if ( flMaxValue <= 1.0 )
      v31 = flMaxValue;
  }
  v33 = v32->m_flKnobPosition[0];
  v32->m_flKnobPosition[1] = v31;
  if ( v33 > v31 )
    v32->m_flKnobPosition[0] = v31;
  if ( v32->m_flKnobPosition[2] > v31 )
    v32->m_flKnobPosition[2] = v31;
  v34 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v34 != nullptr )
    v35 = KeyValues::KeyValues(this: v34, setName: "SliderMoved", firstKey: "knob", firstValue: 1);
  else
    v35 = nullptr;
  v32->PostActionSignal(this: v32, a2: v35);
  m_flMinOutputLevel = pOp->m_flMinOutputLevel;
  m_pOutputLevelSlider = this->m_pOutputLevelSlider;
  flMaxValuea = pOp->m_flMaxOutputLevel;
  v38 = 0.0;
  if ( m_flMinOutputLevel >= 0.0 )
  {
    v38 = 1.0;
    if ( m_flMinOutputLevel <= 1.0 )
      v38 = pOp->m_flMinOutputLevel;
  }
  v23 = v38 <= m_pOutputLevelSlider->m_flKnobPosition[1];
  m_pOutputLevelSlider->m_flKnobPosition[0] = v38;
  if ( !v23 )
    m_pOutputLevelSlider->m_flKnobPosition[1] = v38;
  if ( v38 > m_pOutputLevelSlider->m_flKnobPosition[2] )
    m_pOutputLevelSlider->m_flKnobPosition[2] = v38;
  v39 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v39 != nullptr )
    v40 = KeyValues::KeyValues(this: v39, setName: "SliderMoved", firstKey: "knob", firstValue: 0);
  else
    v40 = nullptr;
  m_pOutputLevelSlider->PostActionSignal(this: m_pOutputLevelSlider, a2: v40);
  v41 = 0.0;
  v42 = this->m_pOutputLevelSlider;
  if ( flMaxValuea >= 0.0 )
  {
    v41 = 1.0;
    if ( flMaxValuea <= 1.0 )
      v41 = flMaxValuea;
  }
  v43 = v42->m_flKnobPosition[0];
  v42->m_flKnobPosition[1] = v41;
  if ( v43 > v41 )
    v42->m_flKnobPosition[0] = v41;
  if ( v42->m_flKnobPosition[2] > v41 )
    v42->m_flKnobPosition[2] = v41;
  v44 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v44 != nullptr )
    v45 = KeyValues::KeyValues(this: v44, setName: "SliderMoved", firstKey: "knob", firstValue: 1);
  else
    v45 = nullptr;
  v42->PostActionSignal(this: v42, a2: v45);
  v46 = pOp->m_nChannelMask - 1;
  ActivateItem = this->m_pColorMask->ActivateItem;
  if ( v46 != 0 )
  {
    v48 = v46 - 1;
    if ( v48 != 0 )
    {
      if ( v48 == 2 )
        ((void (__stdcall *)(int))ActivateItem)(a1: 3);
      else
        ((void (__stdcall *)(_DWORD))ActivateItem)(a1: 0);
    }
    else
    {
      ((void (__stdcall *)(int))ActivateItem)(a1: 2);
    }
  }
  else
  {
    ((void (__stdcall *)(int))ActivateItem)(a1: 1);
  }
  m_pLevelsOp = this->m_pLevelsOp;
  if ( m_pLevelsOp != nullptr )
  {
    flMaxValueb = m_pLevelsOp->GetBlendFactor(this: m_pLevelsOp);
    v50 = flMaxValueb;
  }
  else
  {
    v50 = 0.0;
  }
  this->m_pBlendFactorSlider->SetValue(this: this->m_pBlendFactorSlider, a2: (int)(float)(v50 * 255.0), a3: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A8F20
// Name: public: virtual class IColorOperation __near * CColorLevelsUIPanel::GetOperation(void)
// Source: json
//------------------------------------------------------------------------------
CLevelsColorOperation *__thiscall CColorLevelsUIPanel::GetOperation(CColorLevelsUIPanel *this)
{
  return this->m_pLevelsOp;
}

//------------------------------------------------------------------------------
// Address: 0x100A8F30
// Name: public: virtual struct vgui::PanelMessageMap __near * CColorLevelsUIPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CColorLevelsUIPanel::GetMessageMap(CColorLevelsUIPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CColorLevelsUIPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorLevelsUIPanel::GetMessageMap'::`2'::s_pMap;
  `CColorLevelsUIPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CColorLevelsUIPanel");
  `CColorLevelsUIPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A8F60
// Name: public: virtual struct PanelAnimationMap __near * CColorLevelsUIPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CColorLevelsUIPanel::GetAnimMap(CColorLevelsUIPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CColorLevelsUIPanel");
}

//------------------------------------------------------------------------------
// Address: 0x100A8F70
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CColorLevelsUIPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CColorLevelsUIPanel::GetKBMap(CColorLevelsUIPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CColorLevelsUIPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorLevelsUIPanel::GetKBMap'::`2'::s_pMap;
  `CColorLevelsUIPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CColorLevelsUIPanel");
  `CColorLevelsUIPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A8FB0
// Name: public: CSelectedHSVOperation::CSelectedHSVOperation(class CColorOperationList __near *)
// Source: json
//------------------------------------------------------------------------------
CSelectedHSVOperation *__thiscall CSelectedHSVOperation::CSelectedHSVOperation(
        CSelectedHSVOperation *this,
        CColorOperationList *pList)
{
  this->m_pOpList = pList;
  this->__vftable = (CSelectedHSVOperation_vtbl *)&CSelectedHSVOperation::`vftable';
  this->m_SelectedRGBs.m_Memory.m_pMemory = nullptr;
  this->m_SelectedRGBs.m_Memory.m_nAllocationCount = 0;
  this->m_SelectedRGBs.m_Memory.m_nGrowSize = 0;
  this->m_SelectedRGBs.m_Size = 0;
  this->m_SelectedRGBs.m_pElements = nullptr;
  this->m_SelectedHSVs.m_Memory.m_pMemory = nullptr;
  this->m_SelectedHSVs.m_Memory.m_nAllocationCount = 0;
  this->m_SelectedHSVs.m_Memory.m_nGrowSize = 0;
  this->m_SelectedHSVs.m_Size = 0;
  this->m_SelectedHSVs.m_pElements = nullptr;
  this->m_SelectionMethod = SELECT_NEARBY_RGB;
  this->m_DeltaHSV.x = 0.0;
  this->m_DeltaHSV.y = 0.0;
  this->m_DeltaHSV.z = 0.0;
  this->m_Fuzziness = 0.0;
  this->m_Tolerance = 0.2;
  *(_WORD *)&this->m_bColorize = 0;
  this->m_flBlendFactor = 1.0;
  this->m_bEnable = true;
  _V_strcpy(dest: this->m_pName, src: "HSV");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A9040
// Name: public: virtual char const __near * CSelectedHSVOperation::GetName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSelectedHSVOperation::GetName(CSelectedHSVOperation *this)
{
  return this->m_pName;
}

//------------------------------------------------------------------------------
// Address: 0x100A9050
// Name: public: virtual void CSelectedHSVOperation::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectedHSVOperation::SetName(CSelectedHSVOperation *this, const char *pName)
{
  _V_strcpy(dest: this->m_pName, src: pName);
}

//------------------------------------------------------------------------------
// Address: 0x100A9070
// Name: public: virtual bool CSelectedHSVOperation::IsEnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSelectedHSVOperation::IsEnabled(CSelectedHSVOperation *this)
{
  return this->m_bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x100A9080
// Name: public: virtual void CSelectedHSVOperation::SetEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectedHSVOperation::SetEnabled(CSelectedHSVOperation *this, bool bEnable)
{
  this->m_bEnable = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x100A9090
// Name: public: virtual float CSelectedHSVOperation::GetBlendFactor(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CSelectedHSVOperation::GetBlendFactor(CSelectedHSVOperation *this)
{
  return this->m_flBlendFactor;
}

//------------------------------------------------------------------------------
// Address: 0x100A90A0
// Name: public: static void CSelectedHSVUIPanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSelectedHSVUIPanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CSelectedHSVUIPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CSelectedHSVUIPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSelectedHSVUIPanel");
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "TextChanged";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::FileOpenDialog::`vcall'{1132,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][0]) = 1;
    *(_QWORD *)&v3.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A9140
// Name: public: CSelectedHSVUIPanel::CSelectedHSVUIPanel(class vgui::Panel __near *,class CSelectedHSVOperation __near *)
// Source: json
//------------------------------------------------------------------------------
CSelectedHSVUIPanel *__thiscall CSelectedHSVUIPanel::CSelectedHSVUIPanel(
        CSelectedHSVUIPanel *this,
        vgui::Panel *parent,
        CSelectedHSVOperation *pOp)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::ComboBox *v7; // eax
  vgui::ComboBox *v8; // eax
  CPrecisionSlider *v9; // eax
  CPrecisionSlider *v10; // eax
  CPrecisionSlider *v11; // eax
  CPrecisionSlider *v12; // eax
  CPrecisionSlider *v13; // eax
  CPrecisionSlider *v14; // eax
  CPrecisionSlider *v15; // eax
  CPrecisionSlider *v16; // eax
  CPrecisionSlider *v17; // eax
  CPrecisionSlider *v18; // eax
  CPrecisionSlider *v19; // eax
  CPrecisionSlider *v20; // eax
  vgui::CheckButton *v21; // eax
  vgui::CheckButton *v22; // eax
  vgui::CheckButton *v23; // eax
  vgui::CheckButton *v24; // eax
  vgui::Button *v25; // eax
  vgui::Button *v26; // eax
  vgui::Button *v27; // eax
  vgui::Button *v28; // eax
  vgui::Button *v29; // eax
  vgui::Button *v30; // eax
  vgui::TextEntry *v31; // eax
  vgui::TextEntry *v32; // eax
  vgui::TextEntry *v33; // eax
  vgui::TextEntry *v34; // eax
  vgui::TextEntry *v35; // eax
  vgui::TextEntry *v36; // eax
  CUncorrectedImagePanel *v37; // eax
  CUncorrectedImagePanel *v38; // eax
  CSelectedHSVOperation *m_pHSVOperation; // ecx
  CSelectedHSVOperation *v40; // ecx
  float v41; // xmm0_4
  IMatRenderContext *v42; // edi
  CFullScreenSelectionPanel *v43; // eax
  CFullScreenSelectionPanel *v44; // eax
  int v46; // [esp-8h] [ebp-24h]
  int v47; // [esp-4h] [ebp-20h]
  int x; // [esp+Ch] [ebp-10h] BYREF
  int y; // [esp+10h] [ebp-Ch] BYREF
  int w; // [esp+14h] [ebp-8h] BYREF
  int h; // [esp+18h] [ebp-4h] BYREF
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF
  float parenta; // [esp+24h] [ebp+8h]

  CColorCorrectionUIChildPanel::CColorCorrectionUIChildPanel(this, parent, name: "SelectedHSVUIPanel");
  this->__vftable = (CSelectedHSVUIPanel_vtbl *)&CSelectedHSVUIPanel::`vftable';
  if ( `CSelectedHSVUIPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CSelectedHSVUIPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CSelectedHSVUIPanel");
    v4->pfnClassName = CSelectedHSVUIPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CColorCorrectionUIChildPanel");
  }
  if ( `CSelectedHSVUIPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSelectedHSVUIPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CSelectedHSVUIPanel");
    v5->pfnClassName = CSelectedHSVUIPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CColorCorrectionUIChildPanel");
  }
  if ( `CSelectedHSVUIPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSelectedHSVUIPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CSelectedHSVUIPanel");
    v6->pfnClassName = CSelectedHSVUIPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CColorCorrectionUIChildPanel");
  }
  CSelectedHSVUIPanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  v7 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v7 != nullptr )
    v8 = vgui::ComboBox::ComboBox(this: v7, parent: this, panelName: "SelectionMethod", numLines: 10, allowEdit: false);
  else
    v8 = nullptr;
  this->m_pSelectionMethod = v8;
  this->m_pHSVOperation = pOp;
  v9 = (CPrecisionSlider *)MemAlloc_Alloc(nSize: 0x1BCu);
  if ( v9 != nullptr )
    v10 = CPrecisionSlider::CPrecisionSlider(this: v9, parent: this, panelName: "HueSlider");
  else
    v10 = nullptr;
  this->m_pHueSlider = v10;
  v11 = (CPrecisionSlider *)MemAlloc_Alloc(nSize: 0x1BCu);
  if ( v11 != nullptr )
    v12 = CPrecisionSlider::CPrecisionSlider(this: v11, parent: this, panelName: "SaturationSlider");
  else
    v12 = nullptr;
  this->m_pSaturationSlider = v12;
  v13 = (CPrecisionSlider *)MemAlloc_Alloc(nSize: 0x1BCu);
  if ( v13 != nullptr )
    v14 = CPrecisionSlider::CPrecisionSlider(this: v13, parent: this, panelName: "ValueSlider");
  else
    v14 = nullptr;
  this->m_pValueSlider = v14;
  v15 = (CPrecisionSlider *)MemAlloc_Alloc(nSize: 0x1BCu);
  if ( v15 != nullptr )
    v16 = CPrecisionSlider::CPrecisionSlider(this: v15, parent: this, panelName: "ToleranceSlider");
  else
    v16 = nullptr;
  this->m_pToleranceSlider = v16;
  v17 = (CPrecisionSlider *)MemAlloc_Alloc(nSize: 0x1BCu);
  if ( v17 != nullptr )
    v18 = CPrecisionSlider::CPrecisionSlider(this: v17, parent: this, panelName: "FuzzinessSlider");
  else
    v18 = nullptr;
  this->m_pFuzzinessSlider = v18;
  v19 = (CPrecisionSlider *)MemAlloc_Alloc(nSize: 0x1BCu);
  if ( v19 != nullptr )
    v20 = CPrecisionSlider::CPrecisionSlider(this: v19, parent: this, panelName: "BlendFactorSlider");
  else
    v20 = nullptr;
  this->m_pBlendFactorSlider = v20;
  v21 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v21 != nullptr )
    v22 = vgui::CheckButton::CheckButton(this: v21, parent: this, panelName: "ColorizeButton", text: "Colorize");
  else
    v22 = nullptr;
  this->m_pColorizeButton = v22;
  v23 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v23 != nullptr )
    v24 = vgui::CheckButton::CheckButton(
            this: v23,
            parent: this,
            panelName: "InvertSelectionButton",
            text: "Invert Selection");
  else
    v24 = nullptr;
  this->m_pInvertSelectionButton = v24;
  v25 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v25 != nullptr )
    v26 = vgui::Button::Button(
            this: v25,
            parent: this,
            panelName: "SelectionButton",
            text: "Select",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v26 = nullptr;
  this->m_pSelectionButton = v26;
  v26->AddActionSignalTarget_2(this: v26, a2: this);
  v27 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v27 != nullptr )
    v28 = vgui::Button::Button(
            this: v27,
            parent: this,
            panelName: "RGBPickButton",
            text: "RGB",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v28 = nullptr;
  this->m_pPickRGBButton = v28;
  v28->AddActionSignalTarget_2(this: v28, a2: this);
  v29 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v29 != nullptr )
    v30 = vgui::Button::Button(
            this: v29,
            parent: this,
            panelName: "HSVPickButton",
            text: "HSV",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v30 = nullptr;
  this->m_pPickHSVButton = v30;
  v30->AddActionSignalTarget_2(this: v30, a2: this);
  v31 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v31 != nullptr )
    v32 = vgui::TextEntry::TextEntry(this: v31, parent: this, panelName: "ColorEntry1");
  else
    v32 = nullptr;
  this->m_pColorEntry1 = v32;
  v33 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v33 != nullptr )
    v34 = vgui::TextEntry::TextEntry(this: v33, parent: this, panelName: "ColorEntry2");
  else
    v34 = nullptr;
  this->m_pColorEntry2 = v34;
  v35 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v35 != nullptr )
    v36 = vgui::TextEntry::TextEntry(this: v35, parent: this, panelName: "ColorEntry3");
  else
    v36 = nullptr;
  this->m_pColorEntry3 = v36;
  v37 = (CUncorrectedImagePanel *)MemAlloc_Alloc(nSize: 0x1CCu);
  if ( v37 != nullptr )
    v38 = CUncorrectedImagePanel::CUncorrectedImagePanel(this: v37, pParent: this, pName: "UncorrectedImage");
  else
    v38 = nullptr;
  m_pHSVOperation = this->m_pHSVOperation;
  this->m_pUncorrectedImage = v38;
  v38->m_pHSVOp = m_pHSVOperation;
  this->m_pHueSlider->SetRange(this: this->m_pHueSlider, a2: -360, a3: 360);
  this->m_pHueSlider->AddActionSignalTarget_2(this: this->m_pHueSlider, a2: this);
  this->m_pSaturationSlider->SetRange(this: this->m_pSaturationSlider, a2: -255, a3: 255);
  this->m_pSaturationSlider->AddActionSignalTarget_2(this: this->m_pSaturationSlider, a2: this);
  this->m_pValueSlider->SetRange(this: this->m_pValueSlider, a2: -255, a3: 255);
  this->m_pValueSlider->AddActionSignalTarget_2(this: this->m_pValueSlider, a2: this);
  this->m_pToleranceSlider->SetRange(this: this->m_pToleranceSlider, a2: 0, a3: 255);
  this->m_pToleranceSlider->AddActionSignalTarget_2(this: this->m_pToleranceSlider, a2: this);
  this->m_pFuzzinessSlider->SetRange(this: this->m_pFuzzinessSlider, a2: 0, a3: 255);
  this->m_pFuzzinessSlider->AddActionSignalTarget_2(this: this->m_pFuzzinessSlider, a2: this);
  this->m_pBlendFactorSlider->SetRange(this: this->m_pBlendFactorSlider, a2: 0, a3: 255);
  this->m_pBlendFactorSlider->AddActionSignalTarget_2(this: this->m_pBlendFactorSlider, a2: this);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource\\SelectedHSVUIPanel.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  CSelectedHSVUIPanel::PopulateControls(this);
  this->m_pColorizeButton->SetSelected(this: this->m_pColorizeButton, a2: this->m_pHSVOperation->m_bColorize);
  this->m_pColorizeButton->AddActionSignalTarget_2(this: this->m_pColorizeButton, a2: this);
  this->m_pInvertSelectionButton->SetSelected(
    this: this->m_pInvertSelectionButton,
    a2: this->m_pHSVOperation->m_bInvertSelection);
  this->m_pInvertSelectionButton->AddActionSignalTarget_2(this: this->m_pInvertSelectionButton, a2: this);
  CSelectedHSVUIPanel::ResetHSVSliders(this);
  v40 = this->m_pHSVOperation;
  if ( v40 != nullptr )
  {
    parenta = v40->GetBlendFactor(this: v40);
    v41 = parenta;
  }
  else
  {
    v41 = 0.0;
  }
  this->m_pBlendFactorSlider->SetValue(this: this->m_pBlendFactorSlider, a2: (int)(float)(v41 * 255.0), a3: true);
  v42 = g_pMaterialSystem->GetRenderContext(this: g_pMaterialSystem);
  if ( v42 != nullptr )
    v42->BeginRender(this: v42);
  v42->GetViewport(this: v42, a2: &x, a3: &y, a4: &w, a5: &h);
  v43 = (CFullScreenSelectionPanel *)MemAlloc_Alloc(nSize: 0x158u);
  if ( v43 != nullptr )
    v44 = CFullScreenSelectionPanel::CFullScreenSelectionPanel(this: v43, pName: "SelectionPanel", pOp, pParent: this);
  else
    v44 = nullptr;
  v47 = h;
  v46 = w;
  this->m_pFullScreenSelection = v44;
  vgui::Panel::SetSize(this: v44, wide: v46, tall: v47);
  vgui::Panel::SetPos(this: this->m_pFullScreenSelection, x, y);
  this->m_pFullScreenSelection->SetEnabled(this: this->m_pFullScreenSelection, a2: false);
  this->m_pFullScreenSelection->SetVisible(this: this->m_pFullScreenSelection, a2: false);
  this->m_pFullScreenSelection->SetMouseInputEnabled(this: this->m_pFullScreenSelection, a2: false);
  vgui::Panel::MakePopup(this: this->m_pFullScreenSelection, showTaskbarIcon: true, disabled: false);
  this->m_pFullScreenSelection->AddActionSignalTarget_2(this: this->m_pFullScreenSelection, a2: this);
  this->m_bSelectionEnable = false;
  v42->EndRender(this: v42);
  v42->Release(this: v42);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A9790
// Name: public: virtual class IColorOperation __near * CSelectedHSVUIPanel::GetOperation(void)
// Source: json
//------------------------------------------------------------------------------
CSelectedHSVOperation *__thiscall CSelectedHSVUIPanel::GetOperation(CSelectedHSVUIPanel *this)
{
  return this->m_pHSVOperation;
}

//------------------------------------------------------------------------------
// Address: 0x100A97A0
// Name: public: virtual struct vgui::PanelMessageMap __near * CSelectedHSVUIPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSelectedHSVUIPanel::GetMessageMap(CSelectedHSVUIPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSelectedHSVUIPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSelectedHSVUIPanel::GetMessageMap'::`2'::s_pMap;
  `CSelectedHSVUIPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSelectedHSVUIPanel");
  `CSelectedHSVUIPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A97D0
// Name: public: virtual struct PanelAnimationMap __near * CSelectedHSVUIPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSelectedHSVUIPanel::GetAnimMap(CSelectedHSVUIPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CSelectedHSVUIPanel");
}

//------------------------------------------------------------------------------
// Address: 0x100A97E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSelectedHSVUIPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSelectedHSVUIPanel::GetKBMap(CSelectedHSVUIPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSelectedHSVUIPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSelectedHSVUIPanel::GetKBMap'::`2'::s_pMap;
  `CSelectedHSVUIPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSelectedHSVUIPanel");
  `CSelectedHSVUIPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A9840
// Name: public: static void CColorLookupUIPanel::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CColorLookupUIPanel::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CColorLookupUIPanel::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `CColorLookupUIPanel::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CColorLookupUIPanel");
    *(_QWORD *)&v3.m[2][0] = 0x100000001LL;
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "FileSelected";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::FileOpenDialog::`vcall'{1132,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][2]) = "fullpath";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A98E0
// Name: public: CColorLookupUIPanel::CColorLookupUIPanel(class vgui::Panel __near *,class CColorLookupOperation __near *)
// Source: json
//------------------------------------------------------------------------------
CColorLookupUIPanel *__thiscall CColorLookupUIPanel::CColorLookupUIPanel(
        CColorLookupUIPanel *this,
        vgui::Panel *pParent,
        CColorLookupOperation *pOp)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Button *v7; // eax
  vgui::Button *v8; // eax
  CPrecisionSlider *v9; // eax
  CPrecisionSlider *v10; // eax
  CPrecisionSlider_vtbl *v11; // edi
  double v12; // st7
  CColorLookupOperation *m_pLookupOp; // eax
  vgui::Button *m_pLoadButton; // ecx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  CColorCorrectionUIChildPanel::CColorCorrectionUIChildPanel(this, parent: pParent, name: "LookupUIPanel");
  this->__vftable = (CColorLookupUIPanel_vtbl *)&CColorLookupUIPanel::`vftable';
  if ( `CColorLookupUIPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CColorLookupUIPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CColorLookupUIPanel");
    v4->pfnClassName = CColorLookupUIPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CColorCorrectionUIChildPanel");
  }
  if ( `CColorLookupUIPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CColorLookupUIPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CColorLookupUIPanel");
    v5->pfnClassName = CColorLookupUIPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CColorCorrectionUIChildPanel");
  }
  if ( `CColorLookupUIPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CColorLookupUIPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CColorLookupUIPanel");
    v6->pfnClassName = CColorLookupUIPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CColorCorrectionUIChildPanel");
  }
  CColorLookupUIPanel::PanelMessageFunc_OnFileSelected::InitVar(a1: (int)&savedregs);
  this->m_pLookupOp = pOp;
  v7 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v7 != nullptr )
    v8 = vgui::Button::Button(
           this: v7,
           parent: this,
           panelName: "Load Lookup",
           text: defaultValue,
           pActionSignalTarget: this,
           pCmd: "LoadLookup");
  else
    v8 = nullptr;
  this->m_pLoadButton = v8;
  v9 = (CPrecisionSlider *)MemAlloc_Alloc(nSize: 0x1BCu);
  if ( v9 != nullptr )
    v10 = CPrecisionSlider::CPrecisionSlider(this: v9, parent: this, panelName: "BlendFactorSlider");
  else
    v10 = nullptr;
  this->m_pBlendFactorSlider = v10;
  v10->SetRange(this: v10, a2: 0, a3: 255);
  this->m_pBlendFactorSlider->AddActionSignalTarget_2(this: this->m_pBlendFactorSlider, a2: this);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource\\ColorLookupUIPanel.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  v11 = this->m_pBlendFactorSlider->__vftable;
  v12 = ((double (__thiscall *)(CColorLookupOperation *, int))pOp->GetBlendFactor)(a1: pOp, a2: 1) * 255.0;
  ((void (__thiscall *)(CPrecisionSlider *, int))v11->SetValue)(a1: this->m_pBlendFactorSlider, a2: (int)v12);
  m_pLookupOp = this->m_pLookupOp;
  m_pLoadButton = this->m_pLoadButton;
  if ( m_pLookupOp->m_LookupTable != nullptr )
    m_pLoadButton->SetText(this: m_pLoadButton, a2: m_pLookupOp->m_pFilename);
  else
    m_pLoadButton->SetText(this: m_pLoadButton, a2: "No File Loaded");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A9AA0
// Name: public: virtual class IColorOperation __near * CColorLookupUIPanel::GetOperation(void)
// Source: json
//------------------------------------------------------------------------------
CColorLookupOperation *__thiscall CColorLookupUIPanel::GetOperation(CColorLookupUIPanel *this)
{
  return this->m_pLookupOp;
}

//------------------------------------------------------------------------------
// Address: 0x100A9AB0
// Name: public: virtual struct vgui::PanelMessageMap __near * CColorLookupUIPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CColorLookupUIPanel::GetMessageMap(CColorLookupUIPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CColorLookupUIPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorLookupUIPanel::GetMessageMap'::`2'::s_pMap;
  `CColorLookupUIPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CColorLookupUIPanel");
  `CColorLookupUIPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A9AE0
// Name: public: virtual struct PanelAnimationMap __near * CColorLookupUIPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CColorLookupUIPanel::GetAnimMap(CColorLookupUIPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CColorLookupUIPanel");
}

//------------------------------------------------------------------------------
// Address: 0x100A9AF0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CColorLookupUIPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CColorLookupUIPanel::GetKBMap(CColorLookupUIPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CColorLookupUIPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorLookupUIPanel::GetKBMap'::`2'::s_pMap;
  `CColorLookupUIPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CColorLookupUIPanel");
  `CColorLookupUIPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A9BB0
// Name: public: CColorBalanceUIPanel::CColorBalanceUIPanel(class vgui::Panel __near *,class CColorBalanceOperation __near *)
// Source: json
//------------------------------------------------------------------------------
CColorBalanceUIPanel *__thiscall CColorBalanceUIPanel::CColorBalanceUIPanel(
        CColorBalanceUIPanel *this,
        vgui::Panel *pParent,
        CColorBalanceOperation *pOp)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::CheckButton *v7; // eax
  vgui::CheckButton *v8; // eax
  vgui::RadioButton *v9; // eax
  vgui::RadioButton *v10; // eax
  vgui::RadioButton *v11; // eax
  vgui::RadioButton *v12; // eax
  vgui::RadioButton *v13; // eax
  vgui::RadioButton *v14; // eax
  CPrecisionSlider *v15; // eax
  CPrecisionSlider *v16; // eax
  CPrecisionSlider *v17; // eax
  CPrecisionSlider *v18; // eax
  CPrecisionSlider *v19; // eax
  CPrecisionSlider *v20; // eax
  CPrecisionSlider *v21; // eax
  CPrecisionSlider *v22; // eax
  CPrecisionSlider_vtbl *v23; // edi
  double v24; // st7
  float bIsPreservingLuminosity; // [esp+14h] [ebp+8h]

  CColorCorrectionUIChildPanel::CColorCorrectionUIChildPanel(this, parent: pParent, name: "BalanceUIPanel");
  this->__vftable = (CColorBalanceUIPanel_vtbl *)&CColorBalanceUIPanel::`vftable';
  if ( `CColorBalanceUIPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CColorBalanceUIPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CColorBalanceUIPanel");
    v4->pfnClassName = CColorBalanceUIPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CColorCorrectionUIChildPanel");
  }
  if ( `CColorBalanceUIPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CColorBalanceUIPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CColorBalanceUIPanel");
    v5->pfnClassName = CColorBalanceUIPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CColorCorrectionUIChildPanel");
  }
  if ( `CColorBalanceUIPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CColorBalanceUIPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CColorBalanceUIPanel");
    v6->pfnClassName = CColorBalanceUIPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CColorCorrectionUIChildPanel");
  }
  CColorBalanceUIPanel::PanelMessageFunc_OnRadioButtonHit::InitVar();
  LOBYTE(pParent) = pOp->m_PreserveLuminosity;
  v7 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v7 != nullptr )
    v8 = vgui::CheckButton::CheckButton(
           this: v7,
           parent: this,
           panelName: "PreserveLuminosity",
           text: "Preserve Luminosity");
  else
    v8 = nullptr;
  this->m_pPreserveLuminosityButton = v8;
  v9 = (vgui::RadioButton *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v9 != nullptr )
    v10 = vgui::RadioButton::RadioButton(this: v9, parent: this, panelName: "ShadowMode", text: "Shadows");
  else
    v10 = nullptr;
  this->m_pShadowModeButton = v10;
  v11 = (vgui::RadioButton *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v11 != nullptr )
    v12 = vgui::RadioButton::RadioButton(this: v11, parent: this, panelName: "MidtoneMode", text: "Midtones");
  else
    v12 = nullptr;
  this->m_pMidtoneModeButton = v12;
  v13 = (vgui::RadioButton *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v13 != nullptr )
    v14 = vgui::RadioButton::RadioButton(this: v13, parent: this, panelName: "HighlightMode", text: "Highlights");
  else
    v14 = nullptr;
  this->m_pHighlightModeButton = v14;
  v15 = (CPrecisionSlider *)MemAlloc_Alloc(nSize: 0x1BCu);
  if ( v15 != nullptr )
    v16 = CPrecisionSlider::CPrecisionSlider(this: v15, parent: this, panelName: "CyanRedSlider");
  else
    v16 = nullptr;
  this->m_pCyanRedSlider = v16;
  v16->SetRange(this: v16, a2: -100, a3: 100);
  this->m_pCyanRedSlider->SetValue(this: this->m_pCyanRedSlider, a2: 0, a3: true);
  this->m_pCyanRedSlider->AddActionSignalTarget_2(this: this->m_pCyanRedSlider, a2: this);
  v17 = (CPrecisionSlider *)MemAlloc_Alloc(nSize: 0x1BCu);
  if ( v17 != nullptr )
    v18 = CPrecisionSlider::CPrecisionSlider(this: v17, parent: this, panelName: "MagentaGreenSlider");
  else
    v18 = nullptr;
  this->m_pMagentaGreenSlider = v18;
  v18->SetRange(this: v18, a2: -100, a3: 100);
  this->m_pMagentaGreenSlider->SetValue(this: this->m_pMagentaGreenSlider, a2: 0, a3: true);
  this->m_pMagentaGreenSlider->AddActionSignalTarget_2(this: this->m_pMagentaGreenSlider, a2: this);
  v19 = (CPrecisionSlider *)MemAlloc_Alloc(nSize: 0x1BCu);
  if ( v19 != nullptr )
    v20 = CPrecisionSlider::CPrecisionSlider(this: v19, parent: this, panelName: "YellowBlueSlider");
  else
    v20 = nullptr;
  this->m_pYellowBlueSlider = v20;
  v20->SetRange(this: v20, a2: -100, a3: 100);
  this->m_pYellowBlueSlider->SetValue(this: this->m_pYellowBlueSlider, a2: 0, a3: true);
  this->m_pYellowBlueSlider->AddActionSignalTarget_2(this: this->m_pYellowBlueSlider, a2: this);
  v21 = (CPrecisionSlider *)MemAlloc_Alloc(nSize: 0x1BCu);
  if ( v21 != nullptr )
    v22 = CPrecisionSlider::CPrecisionSlider(this: v21, parent: this, panelName: "BlendFactorSlider");
  else
    v22 = nullptr;
  this->m_pBlendFactorSlider = v22;
  v22->SetRange(this: v22, a2: 0, a3: 255);
  this->m_pBlendFactorSlider->AddActionSignalTarget_2(this: this->m_pBlendFactorSlider, a2: this);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource\\ColorBalanceUIPanel.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  this->m_pPreserveLuminosityButton->SetSelected(this: this->m_pPreserveLuminosityButton, a2: (bool)pParent);
  v23 = this->m_pBlendFactorSlider->__vftable;
  v24 = ((double (__thiscall *)(CColorBalanceOperation *, int))pOp->GetBlendFactor)(a1: pOp, a2: 1) * 255.0;
  ((void (__thiscall *)(CPrecisionSlider *, int))v23->SetValue)(a1: this->m_pBlendFactorSlider, a2: (int)v24);
  this->m_pBalanceOp = pOp;
  bIsPreservingLuminosity = pOp->GetBlendFactor(this: pOp);
  this->m_pBlendFactorSlider->SetValue(
    this: this->m_pBlendFactorSlider,
    a2: (int)(float)(bIsPreservingLuminosity * 255.0),
    a3: true);
  CColorBalanceUIPanel::ResetSliders(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A9F20
// Name: public: virtual struct vgui::PanelMessageMap __near * CColorBalanceUIPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CColorBalanceUIPanel::GetMessageMap(CColorBalanceUIPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CColorBalanceUIPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorBalanceUIPanel::GetMessageMap'::`2'::s_pMap;
  `CColorBalanceUIPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CColorBalanceUIPanel");
  `CColorBalanceUIPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A9F50
// Name: public: virtual struct PanelAnimationMap __near * CColorBalanceUIPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CColorBalanceUIPanel::GetAnimMap(CColorBalanceUIPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CColorBalanceUIPanel");
}

//------------------------------------------------------------------------------
// Address: 0x100A9F60
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CColorBalanceUIPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CColorBalanceUIPanel::GetKBMap(CColorBalanceUIPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CColorBalanceUIPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorBalanceUIPanel::GetKBMap'::`2'::s_pMap;
  `CColorBalanceUIPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CColorBalanceUIPanel");
  `CColorBalanceUIPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A9F90
// Name: public: static void COperationListPanel::PanelMessageFunc_OnTextNewLine::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COperationListPanel::PanelMessageFunc_OnTextNewLine::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`COperationListPanel::PanelMessageFunc_OnTextNewLine::InitVar'::`2'::bAdded )
  {
    `COperationListPanel::PanelMessageFunc_OnTextNewLine::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COperationListPanel");
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "TextNewLine";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::BuildModeDialog::`vcall'{1120,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][0]) = 1;
    *(_QWORD *)&v3.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AA030
// Name: public: COperationListPanel::COperationListPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
COperationListPanel *__thiscall COperationListPanel::COperationListPanel(
        COperationListPanel *this,
        vgui::Panel *parent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::ListPanel::ListPanel(this, parent, panelName: pName);
  this->__vftable = (COperationListPanel_vtbl *)&COperationListPanel::`vftable';
  if ( `COperationListPanel::ChainToMap'::`2'::chained == 0 )
  {
    `COperationListPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "COperationListPanel");
    v4->pfnClassName = COperationListPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::ListPanel");
  }
  if ( `COperationListPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `COperationListPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "COperationListPanel");
    v5->pfnClassName = COperationListPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::ListPanel");
  }
  if ( `COperationListPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `COperationListPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "COperationListPanel");
    v6->pfnClassName = COperationListPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::ListPanel");
  }
  COperationListPanel::PanelMessageFunc_OnTextNewLine::InitVar(a1: (int)&savedregs);
  this->m_pNameEditPanel = nullptr;
  this->m_nEditItem = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100AA110
// Name: public: static void CColorOperationListPanel::PanelMessageFunc_OnOpPanelClose::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CColorOperationListPanel::PanelMessageFunc_OnOpPanelClose::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CColorOperationListPanel::PanelMessageFunc_OnOpPanelClose::InitVar'::`2'::bAdded )
  {
    `CColorOperationListPanel::PanelMessageFunc_OnOpPanelClose::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CColorOperationListPanel");
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "OpPanelClose";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::PropertyPage::`vcall'{944,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][0]) = 1;
    *(_QWORD *)&v3.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AA1B0
// Name: public: static void CColorOperationListPanel::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CColorOperationListPanel::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CColorOperationListPanel::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `CColorOperationListPanel::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CColorOperationListPanel");
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "SliderMoved";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::TextEntry::`vcall'{948,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][0]) = 1;
    *(_QWORD *)&v3.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AA250
// Name: public: static void CColorOperationListPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CColorOperationListPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CColorOperationListPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `CColorOperationListPanel::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CColorOperationListPanel");
    memset(&v3.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "CheckButtonChecked";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset(&v3.m[1][1], 0, 12);
    LODWORD(v3.m[2][0]) = 1;
    *(_QWORD *)&v3.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AA980
// Name: public: virtual void CColorOperationListPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CColorOperationListPanel::OnCommand(
        CColorOperationListPanel *this@<ecx>,
        int a2@<ebx>,
        const char *command)
{
  CNewOperationDialog *v4; // eax
  CNewOperationDialog *v5; // eax
  int v6; // eax
  CColorOperationList *p_m_OperationList; // ecx
  IColorOperation *v8; // ebx
  int v9; // edi
  CColorCorrectionUIChildPanel *v10; // ecx
  CColorCorrectionUIChildPanel *v11; // ecx
  int v12; // edi
  IColorOperation *v13; // ebx
  int v14; // edi
  char *v15; // ebx
  int v16; // edi
  int v17; // ebx
  int v18; // edi
  int v19; // ebx
  const char *v20; // eax
  int v21; // eax
  const char *v22; // eax
  CNewOperationDialog *v23; // ecx
  COperationListPanel *m_pOperationListPanel; // ecx
  COperationListPanel_vtbl *v25; // edi
  int v26; // eax
  CNewOperationDialog *m_pNewDialog; // ecx
  int v28; // eax
  IColorOperation *Operation; // eax
  IColorOperation *v30; // eax
  BOOL v31; // [esp-8h] [ebp-10h]
  int v32; // [esp-8h] [ebp-10h]

  if ( _V_stricmp(s1: command, s2: "NewOperation") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "DeleteOperation") != 0 )
    {
      if ( _V_stricmp(s1: command, s2: "BringForward") != 0 )
      {
        if ( _V_stricmp(s1: command, s2: "PushBack") != 0 )
        {
          if ( _V_stricmp(s1: command, s2: "Save") == 0 )
          {
            CP4Factory::SetDummyMode(this: g_p4factory, bDummyMode: p4 == nullptr);
            CP4Factory::SetOpenFileChangeList(this: g_p4factory, szChangeListName: "Color Correction Auto Checkout");
            v31 = p4 != nullptr;
            v20 = CUtlString::Get(this: &this->m_FileName);
            vgui::FileOpenStateMachine::SaveFile(
              this: this->m_pFileOpenStateMachine,
              pContextKeyValues: nullptr,
              pFileName: v20,
              pFileType: "vcc",
              nFlags: v31);
            return;
          }
          if ( _V_stricmp(s1: command, s2: "SaveAs") == 0 )
          {
            CP4Factory::SetDummyMode(this: g_p4factory, bDummyMode: p4 == nullptr);
            CP4Factory::SetOpenFileChangeList(this: g_p4factory, szChangeListName: "Color Correction Auto Checkout");
            vgui::FileOpenStateMachine::SaveFile(
              this: this->m_pFileOpenStateMachine,
              pContextKeyValues: nullptr,
              pFileName: nullptr,
              pFileType: "vcc",
              nFlags: p4 != nullptr);
            return;
          }
          if ( _V_stricmp(s1: command, s2: "Load") != 0 )
          {
            if ( _V_stricmp(s1: command, s2: "NewComplete") != 0 )
            {
              if ( _V_stricmp(s1: command, s2: "NewCancel") != 0 )
              {
                if ( _V_stricmp(s1: command, s2: "SelectedItemChanged") == 0
                  || _V_stricmp(s1: command, s2: "BlendFactorUpdate") == 0 )
                {
                  CColorOperationListPanel::ResetSlider(this);
                  return;
                }
                if ( _V_stricmp(s1: command, s2: "UpdateList") != 0 )
                {
                  if ( _V_stricmp(s1: command, s2: "CloneOperation") != 0 )
                    return;
                  v28 = this->m_pOperationListPanel->GetSelectedItem(this: this->m_pOperationListPanel, a2: 0);
                  Operation = CColorOperationList::GetOperation(this: &this->m_OperationList, opIndex: v28);
                  v30 = Operation->Clone(this: Operation);
                  CColorOperationList::AddOperation(this: &this->m_OperationList, pOp: v30);
                }
                CColorOperationListPanel::PopulateList(this);
              }
              else
              {
                m_pNewDialog = this->m_pNewDialog;
                if ( m_pNewDialog != nullptr )
                {
                  ((void (__thiscall *)(CNewOperationDialog *, int))m_pNewDialog->dtr_Panel)(a1: m_pNewDialog, a2: 1);
                  this->m_pNewDialog = nullptr;
                }
              }
            }
            else
            {
              v23 = this->m_pNewDialog;
              if ( v23 != nullptr )
              {
                ((void (__thiscall *)(CNewOperationDialog *, int))v23->dtr_Panel)(a1: v23, a2: 1);
                this->m_pNewDialog = nullptr;
              }
              CColorOperationListPanel::PopulateList(this);
              m_pOperationListPanel = this->m_pOperationListPanel;
              v25 = m_pOperationListPanel->__vftable;
              v26 = m_pOperationListPanel->GetItemCount(this: m_pOperationListPanel);
              v25->SetSingleSelectedItem(this: this->m_pOperationListPanel, a2: v26 - 1);
              this->OnKeyCodeTyped(this, a2: KEY_ENTER);
            }
          }
          else
          {
            CP4Factory::SetDummyMode(this: g_p4factory, bDummyMode: p4 == nullptr);
            CP4Factory::SetOpenFileChangeList(this: g_p4factory, szChangeListName: "Color Correction Auto Checkout");
            v21 = 2;
            if ( p4 != nullptr )
              v21 = 3;
            v32 = v21;
            v22 = CUtlString::Get(this: &this->m_FileName);
            vgui::FileOpenStateMachine::OpenFile(
              this: this->m_pFileOpenStateMachine,
              pOpenFileName: nullptr,
              pOpenFileType: "vcc",
              pContextKeyValues: nullptr,
              pSaveFileName: v22,
              pSaveFileType: "vcc",
              nFlags: v32);
          }
        }
        else
        {
          v16 = this->m_pOperationListPanel->GetSelectedItem(this: this->m_pOperationListPanel, a2: 0);
          v17 = this->m_pOperationListPanel->GetItemCurrentRow(this: this->m_pOperationListPanel, a2: v16);
          if ( this->m_pOperationListPanel->IsValidItemID(this: this->m_pOperationListPanel, a2: v16)
            && v17 < this->m_OperationList.m_OpList.m_Size - 1 )
          {
            CColorOperationList::PushBack(this: &this->m_OperationList, opIndex: v17);
            CColorOperationListPanel::PopulateList(this);
            colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
            v18 = this->m_pOperationListPanel->FirstItem(this: this->m_pOperationListPanel);
            if ( v18 != this->m_pOperationListPanel->InvalidItemID(this: this->m_pOperationListPanel) )
            {
              v19 = v17 + 1;
              do
              {
                if ( ((int (__thiscall *)(COperationListPanel *, int, int))this->m_pOperationListPanel->GetItemCurrentRow)(
                       a1: this->m_pOperationListPanel,
                       a2: v18,
                       a3: a2) == v19 )
                  this->m_pOperationListPanel->SetSingleSelectedItem(this: this->m_pOperationListPanel, a2: v18);
                a2 = v18;
                v18 = ((int (__thiscall *)(COperationListPanel *))this->m_pOperationListPanel->NextItem)(a1: this->m_pOperationListPanel);
              }
              while ( v18 != this->m_pOperationListPanel->InvalidItemID(this: this->m_pOperationListPanel) );
            }
          }
        }
      }
      else
      {
        v12 = this->m_pOperationListPanel->GetSelectedItem(this: this->m_pOperationListPanel, a2: 0);
        v13 = (IColorOperation *)this->m_pOperationListPanel->GetItemCurrentRow(
                                   this: this->m_pOperationListPanel,
                                   a2: v12);
        if ( this->m_pOperationListPanel->IsValidItemID(this: this->m_pOperationListPanel, a2: v12) && v13 != nullptr )
        {
          CColorOperationList::BringForward(this: &this->m_OperationList, opIndex: v13);
          CColorOperationListPanel::PopulateList(this);
          colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
          v14 = this->m_pOperationListPanel->FirstItem(this: this->m_pOperationListPanel);
          if ( v14 != this->m_pOperationListPanel->InvalidItemID(this: this->m_pOperationListPanel) )
          {
            v15 = (char *)&v13[-1].__vftable + 3;
            do
            {
              if ( (char *)((int (__thiscall *)(COperationListPanel *, int, int))this->m_pOperationListPanel->GetItemCurrentRow)(
                             a1: this->m_pOperationListPanel,
                             a2: v14,
                             a3: a2) == v15 )
                this->m_pOperationListPanel->SetSingleSelectedItem(this: this->m_pOperationListPanel, a2: v14);
              a2 = v14;
              v14 = ((int (__thiscall *)(COperationListPanel *))this->m_pOperationListPanel->NextItem)(a1: this->m_pOperationListPanel);
            }
            while ( v14 != this->m_pOperationListPanel->InvalidItemID(this: this->m_pOperationListPanel) );
          }
        }
      }
    }
    else if ( this->m_pOperationListPanel->GetSelectedItemsCount(this: this->m_pOperationListPanel) != 0 )
    {
      v6 = this->m_pOperationListPanel->GetSelectedItem(this: this->m_pOperationListPanel, a2: 0);
      p_m_OperationList = &this->m_OperationList;
      if ( v6 >= 0 && v6 < this->m_OperationList.m_OpList.m_Size )
        v8 = p_m_OperationList->m_OpList.m_Memory.m_pMemory[v6];
      else
        v8 = nullptr;
      CColorOperationList::DeleteOperation(this: p_m_OperationList, opIndex: v6);
      v9 = 0;
      if ( this->m_OpPanelList.m_Size > 0 )
      {
        while ( 1 )
        {
          v10 = this->m_OpPanelList.m_Memory.m_pMemory[v9];
          if ( v10->GetOperation(this: v10) == v8 )
            break;
          if ( ++v9 >= this->m_OpPanelList.m_Size )
            goto LABEL_22;
        }
        v11 = this->m_OpPanelList.m_Memory.m_pMemory[v9];
        if ( v11 != nullptr )
          ((void (__thiscall *)(CColorCorrectionUIChildPanel *, int))v11->dtr_Panel)(a1: v11, a2: 1);
        if ( this->m_OpPanelList.m_Size - v9 - 1 > 0 )
          _V_memmove(
            dest: &this->m_OpPanelList.m_Memory.m_pMemory[v9],
            src: &this->m_OpPanelList.m_Memory.m_pMemory[v9 + 1],
            count: 4 * (this->m_OpPanelList.m_Size - v9 - 1));
        --this->m_OpPanelList.m_Size;
      }
LABEL_22:
      CColorOperationListPanel::PopulateList(this);
      colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
    }
  }
  else if ( this->m_pNewDialog == nullptr )
  {
    v4 = (CNewOperationDialog *)MemAlloc_Alloc(nSize: 0x228u);
    if ( v4 != nullptr )
      v5 = CNewOperationDialog::CNewOperationDialog(this: v4, parent: this, pOpList: &this->m_OperationList);
    else
      v5 = nullptr;
    this->m_pNewDialog = v5;
    v5->AddActionSignalTarget_2(this: v5, a2: this);
    this->m_pNewDialog->Activate(this: this->m_pNewDialog);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AAF90
// Name: private: void CColorOperationListPanel::LaunchOperationPanel(class IColorOperation __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CColorOperationListPanel::LaunchOperationPanel(
        CColorOperationListPanel *this@<ecx>,
        int a2@<esi>,
        CCurvesColorOperation *pOp)
{
  CColorCorrectionUIChildPanel *v5; // esi
  CColorCurvesUIPanel *v6; // esi
  CColorBalanceUIPanel *v7; // eax
  CColorCurvesUIPanel *v8; // eax
  CColorLevelsUIPanel *v9; // eax
  CColorLookupUIPanel *v10; // eax
  CSelectedHSVUIPanel *v11; // eax
  vgui::Panel *v12; // eax
  int v13; // eax
  int v14; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CColorCorrectionUIChildPanel **m_pMemory; // ecx
  int v18; // eax
  CColorCorrectionUIChildPanel **v19; // ebx
  int parentX; // [esp+8h] [ebp-8h] BYREF
  int parentY; // [esp+Ch] [ebp-4h] BYREF
  int i; // [esp+18h] [ebp+8h]
  int ia; // [esp+18h] [ebp+8h]
  void (__thiscall **ib)(CColorCurvesUIPanel *, int); // [esp+18h] [ebp+8h]

  if ( pOp != nullptr )
  {
    i = 0;
    if ( this->m_OpPanelList.m_Size <= 0 )
    {
LABEL_5:
      v6 = nullptr;
      switch ( ((int (__thiscall *)(CCurvesColorOperation *, int))pOp->ToolID)(a1: pOp, a2) )
      {
        case 1:
          v8 = (CColorCurvesUIPanel *)MemAlloc_Alloc(nSize: 0x228u);
          if ( v8 == nullptr )
            goto LABEL_17;
          v6 = CColorCurvesUIPanel::CColorCurvesUIPanel(this: v8, pParent: this, pOp);
          break;
        case 2:
          v9 = (CColorLevelsUIPanel *)MemAlloc_Alloc(nSize: 0x230u);
          if ( v9 == nullptr )
            goto LABEL_17;
          v6 = (CColorCurvesUIPanel *)CColorLevelsUIPanel::CColorLevelsUIPanel(
                                        this: v9,
                                        pParent: this,
                                        (CLevelsColorOperation *)pOp);
          break;
        case 3:
          v11 = (CSelectedHSVUIPanel *)MemAlloc_Alloc(nSize: 0x264u);
          if ( v11 == nullptr )
            goto LABEL_17;
          v6 = (CColorCurvesUIPanel *)CSelectedHSVUIPanel::CSelectedHSVUIPanel(
                                        this: v11,
                                        parent: this,
                                        (CSelectedHSVOperation *)pOp);
          break;
        case 4:
          v10 = (CColorLookupUIPanel *)MemAlloc_Alloc(nSize: 0x224u);
          if ( v10 == nullptr )
            goto LABEL_17;
          v6 = (CColorCurvesUIPanel *)CColorLookupUIPanel::CColorLookupUIPanel(
                                        this: v10,
                                        pParent: this,
                                        (CColorLookupOperation *)pOp);
          break;
        case 5:
          v7 = (CColorBalanceUIPanel *)MemAlloc_Alloc(nSize: 0x23Cu);
          if ( v7 != nullptr )
            v6 = (CColorCurvesUIPanel *)CColorBalanceUIPanel::CColorBalanceUIPanel(
                                          this: v7,
                                          pParent: this,
                                          (CColorBalanceOperation *)pOp);
          else
LABEL_17:
            v6 = nullptr;
          break;
        default:
          break;
      }
      v12 = this->GetParent(this);
      vgui::Panel::GetPos(this: v12, x: &parentX, y: &parentY);
      v13 = parentX / 250;
      if ( this->m_OpPanelList.m_Size + 1 < parentX / 250 )
        v13 = this->m_OpPanelList.m_Size + 1;
      ia = parentX - 250 * v13;
      if ( pOp->ToolID(this: pOp) == CC_TOOL_SELECTED_HSV )
      {
        vgui::Panel::SetPos(this: v6, x: ia, y: parentY - 40);
        vgui::Panel::SetSize(this: v6, wide: 250, tall: 520);
      }
      else
      {
        vgui::Panel::SetPos(this: v6, x: ia, y: parentY);
        vgui::Panel::SetSize(this: v6, wide: 250, tall: 480);
      }
      ib = (void (__thiscall **)(CColorCurvesUIPanel *, int))&v6->SetTitle_2;
      v14 = ((int (__thiscall *)(CCurvesColorOperation *, int))pOp->GetName)(a1: pOp, a2: 1);
      (*ib)(a1: v6, a2: v14);
      v6->AddActionSignalTarget_2(this: v6, a2: this);
      v6->SetSizeable(this: v6, a2: false);
      v6->SetVisible(this: v6, a2: true);
      v6->Init(this: v6);
      m_Size = this->m_OpPanelList.m_Size;
      m_nAllocationCount = this->m_OpPanelList.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<INetMessage *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&this->m_OpPanelList,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_OpPanelList.m_Size;
      m_pMemory = this->m_OpPanelList.m_Memory.m_pMemory;
      v18 = this->m_OpPanelList.m_Size - m_Size - 1;
      this->m_OpPanelList.m_pElements = m_pMemory;
      if ( v18 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v18);
      v19 = &this->m_OpPanelList.m_Memory.m_pMemory[m_Size];
      if ( v19 != nullptr )
        *v19 = v6;
    }
    else
    {
      while ( 1 )
      {
        v5 = this->m_OpPanelList.m_Memory.m_pMemory[i];
        if ( v5->GetOperation(this: v5) == pOp )
          break;
        if ( ++i >= this->m_OpPanelList.m_Size )
          goto LABEL_5;
      }
      v5->Activate(this: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AB220
// Name: public: CColorCorrectionUIPanel::CColorCorrectionUIPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CColorCorrectionUIPanel *__thiscall CColorCorrectionUIPanel::CColorCorrectionUIPanel(
        CColorCorrectionUIPanel *this,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  CColorOperationListPanel *m_pOperationListPanel; // ecx
  unsigned int v8; // eax
  CColorOperationListPanel *v9; // eax
  CColorOperationListPanel *v10; // eax
  int v11; // edi
  int v12; // eax

  vgui::Frame::Frame(this, parent, panelName: "ColorCorrectionUIPanel", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CColorCorrectionUIPanel_vtbl *)&CColorCorrectionUIPanel::`vftable';
  if ( `CColorCorrectionUIPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CColorCorrectionUIPanel::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CColorCorrectionUIPanel");
    v3->pfnClassName = CColorCorrectionUIPanel::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CColorCorrectionUIPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CColorCorrectionUIPanel::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CColorCorrectionUIPanel");
    v4->pfnClassName = CColorCorrectionUIPanel::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CColorCorrectionUIPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CColorCorrectionUIPanel::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CColorCorrectionUIPanel");
    v5->pfnClassName = CColorCorrectionUIPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  if ( colorcorrection != nullptr )
  {
    v8 = colorcorrection->AddLookup(this: colorcorrection, a2: "editable");
    this->m_CCHandle = v8;
    colorcorrection->SetResetable(this: colorcorrection, a2: v8, a3: true);
    this->m_bForceReset = true;
    this->m_bEnable = false;
    vgui::Frame::SetTitle(this, title: "Color Correction Tools", surfaceTitle: true);
    v9 = (CColorOperationListPanel *)MemAlloc_Alloc(nSize: 0x200u);
    if ( v9 != nullptr )
      v10 = CColorOperationListPanel::CColorOperationListPanel(this: v9, parent: this, CCHandle: this->m_CCHandle);
    else
      v10 = nullptr;
    this->m_pOperationListPanel = v10;
    v10->AddActionSignalTarget_2(this: v10, a2: this);
    vgui::Frame::LoadControlSettings(
      this,
      dialogResourceName: "Resource\\ColorCorrectionUIPanel.res",
      pathID: nullptr,
      pPreloadedKeyValues: nullptr,
      pConditions: nullptr);
    vgui::Panel::SetVisible(this, state: false);
    vgui::Frame::SetSizeable(this, state: false);
    vgui::Frame::SetMoveable(this, state: true);
    v11 = videomode->GetModeWidth(this: videomode) - 360;
    v12 = videomode->GetModeHeight(this: videomode);
    vgui::Panel::SetBounds(this, x: v11, y: v12 - 490, wide: 350, tall: 480);
    CColorOperationListPanel::PopulateList(this: this->m_pOperationListPanel);
    _V_memset(dest: this->m_pLookupCache, fill: 0, count: 98304);
    _V_memset(dest: this->m_pLookupCache360, fill: 0, count: 98304);
    this->m_nCurrentRow = -1;
    this->m_nRowStep = 4;
    this->m_pFinalOperation = nullptr;
  }
  else
  {
    this->m_pOperationListPanel = nullptr;
    this->m_CCHandle = 0;
    _Warning(a1: "Could not get the color correction interface!");
    m_pOperationListPanel = this->m_pOperationListPanel;
    if ( m_pOperationListPanel != nullptr )
    {
      CColorOperationListPanel::Shutdown(this: m_pOperationListPanel);
      return this;
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100AB440
// Name: private: bool CColorOperationListPanel::SaveVCCFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CColorOperationListPanel::SaveVCCFile(CColorOperationListPanel *this, const char *pFullPath)
{
  CColorOperationListPanel *v2; // ebx
  CDmxElement *DmxElement; // edi
  CDmxAttribute *v4; // eax
  CDmxAttribute *v5; // esi
  _DWORD *m_pData; // eax
  CUtlMemory<S3RGBA,int> *v7; // esi
  int v8; // eax
  IColorOperation *v9; // edi
  int v10; // eax
  CDmxElement *v11; // ebx
  S3RGBA *m_pMemory; // edi
  int m_nAllocationCount; // eax
  S3RGBA *v14; // ecx
  int v15; // eax
  CDmxElement **v16; // eax
  const char *v17; // eax
  int nCount; // [esp+Ch] [ebp-18h]
  CDmxElement *modify; // [esp+14h] [ebp-10h]
  CDmxElement *pColorOperaterList; // [esp+18h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-8h]
  bool bOk; // [esp+23h] [ebp-1h]

  v2 = this;
  BeginDMXContext();
  DmxElement = CreateDmxElement(pType: "DmeColorCorrectionOperatorList");
  pColorOperaterList = DmxElement;
  modify = DmxElement;
  CDmxElement::LockForChanges(this: DmxElement, bLock: true);
  v4 = CDmxElement::AddAttribute(this: DmxElement, pAttributeName: "operators");
  v5 = v4;
  if ( v4->m_Type != AT_FIRST_ARRAY_TYPE )
  {
    CDmxAttribute::AllocateDataMemory(this: v4, type: AT_FIRST_ARRAY_TYPE);
    m_pData = v5->m_pData;
    if ( m_pData != nullptr )
    {
      *m_pData = 0;
      m_pData[1] = 0;
      m_pData[2] = 0;
      m_pData[3] = 0;
      m_pData[4] = 0;
    }
  }
  v7 = (CUtlMemory<S3RGBA,int> *)v5->m_pData;
  v8 = 0;
  bOk = true;
  nCount = v2->m_OperationList.m_OpList.m_Size;
  i = 0;
  if ( nCount > 0 )
  {
    while ( 1 )
    {
      v9 = v8 >= 0 && v8 < v2->m_OperationList.m_OpList.m_Size
         ? v2->m_OperationList.m_OpList.m_Memory.m_pMemory[v8]
         : nullptr;
      v10 = v9->ToolID(this: v9);
      v11 = CreateDmxElement(pType: s_pColorCorrectionDmxElementNames[v10]);
      CDmxElement::LockForChanges(this: v11, bLock: true);
      if ( !v9->Serialize(this: v9, a2: v11) )
        break;
      m_pMemory = v7[1].m_pMemory;
      m_nAllocationCount = v7->m_nAllocationCount;
      if ( (int)&m_pMemory->g > m_nAllocationCount )
        CUtlMemory<INetMessage *,int>::Grow(this: v7, num: (int)(&m_pMemory->g - m_nAllocationCount));
      ++v7[1].m_pMemory;
      v14 = v7->m_pMemory;
      v15 = (char *)v7[1].m_pMemory - (char *)m_pMemory - 1;
      v7[1].m_nAllocationCount = (int)v7->m_pMemory;
      if ( v15 > 0 )
        _V_memmove(dest: &v14[(_DWORD)m_pMemory + 1], src: &v14[(_DWORD)m_pMemory], count: 4 * v15);
      v16 = (CDmxElement **)&v7->m_pMemory[(_DWORD)m_pMemory];
      if ( v16 != nullptr )
        *v16 = v11;
      if ( v11 != nullptr )
        CDmxElement::LockForChanges(this: v11, bLock: false);
      if ( ++i >= nCount )
        goto LABEL_24;
      v2 = this;
      v8 = i;
    }
    bOk = false;
    v17 = v9->GetName(this: v9);
    _Warning(a1: "Error serializing color operator %s\n", v17);
    if ( v11 != nullptr )
      CDmxElement::LockForChanges(this: v11, bLock: false);
LABEL_24:
    DmxElement = pColorOperaterList;
  }
  if ( DmxElement != nullptr )
  {
    CDmxElement::LockForChanges(this: DmxElement, bLock: false);
    modify = nullptr;
  }
  if ( bOk )
    SerializeDMX(pFileName: pFullPath, pPathID: "MOD", bTextMode: true, pRoot: DmxElement);
  EndDMXContext(bDecommitMemory: true);
  if ( modify != nullptr )
    CDmxElement::LockForChanges(this: modify, bLock: false);
  return bOk;
}

//------------------------------------------------------------------------------
// Address: 0x100AB600
// Name: public: virtual void CColorCorrectionTools::InstallColorCorrectionUI(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorCorrectionTools::InstallColorCorrectionUI(CColorCorrectionTools *this, vgui::Panel *parent)
{
  int v2; // eax
  CColorCorrectionUIPanel *v3; // eax

  if ( g_pColorCorrectionUI == nullptr )
  {
    v2 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v2 + 12))(a1: v2, a2: "-tools", a3: 0) != 0 )
    {
      v3 = (CColorCorrectionUIPanel *)MemAlloc_Alloc(nSize: 0x30230u);
      if ( v3 != nullptr )
        g_pColorCorrectionUI = CColorCorrectionUIPanel::CColorCorrectionUIPanel(this: v3, parent);
      else
        g_pColorCorrectionUI = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AB700
// Name: public: CCurvesColorOperation::CCurvesColorOperation(void)
// Source: json
//------------------------------------------------------------------------------
CCurvesColorOperation *__thiscall CCurvesColorOperation::CCurvesColorOperation(CCurvesColorOperation *this)
{
  Vector endpt; // [esp+0h] [ebp-18h] BYREF
  Vector startpt; // [esp+Ch] [ebp-Ch] BYREF

  this->__vftable = (CCurvesColorOperation_vtbl *)&CCurvesColorOperation::`vftable';
  this->m_ControlPoints.m_Memory.m_pMemory = nullptr;
  this->m_ControlPoints.m_Memory.m_nAllocationCount = 0;
  this->m_ControlPoints.m_Memory.m_nGrowSize = 0;
  this->m_ControlPoints.m_Size = 0;
  this->m_ControlPoints.m_pElements = nullptr;
  this->m_ControlPoints.m_pLessContext = nullptr;
  this->m_ControlPoints.m_bNeedsSort = false;
  memset(&startpt, 0, sizeof(startpt));
  endpt.x = 1.0;
  endpt.y = 1.0;
  endpt.z = 0.0;
  CUtlSortVector<Vector,CCurvesColorOperation::CurvesLessFunc>::Insert(this: &this->m_ControlPoints, src: &startpt);
  CUtlSortVector<Vector,CCurvesColorOperation::CurvesLessFunc>::Insert(this: &this->m_ControlPoints, src: &endpt);
  this->m_flBlendFactor = 1.0;
  this->m_nChannelMask = 7;
  this->m_bEnable = true;
  CCurvesColorOperation::UpdateOutColorArray(this);
  _V_strcpy(dest: this->m_pName, src: "Curves");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100AB7D0
// Name: public: virtual char const __near * CCurvesColorOperation::GetName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CCurvesColorOperation::GetName(CCurvesColorOperation *this)
{
  return this->m_pName;
}

//------------------------------------------------------------------------------
// Address: 0x100AB7E0
// Name: public: virtual void CCurvesColorOperation::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurvesColorOperation::SetName(CCurvesColorOperation *this, const char *pName)
{
  _V_strcpy(dest: this->m_pName, src: pName);
}

//------------------------------------------------------------------------------
// Address: 0x100AB800
// Name: public: virtual bool CCurvesColorOperation::IsEnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCurvesColorOperation::IsEnabled(CCurvesColorOperation *this)
{
  return this->m_bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x100AB810
// Name: public: virtual void CCurvesColorOperation::SetEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurvesColorOperation::SetEnabled(CCurvesColorOperation *this, bool bEnable)
{
  this->m_bEnable = bEnable;
}

//------------------------------------------------------------------------------
// Address: 0x100AB820
// Name: public: virtual float CCurvesColorOperation::GetBlendFactor(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCurvesColorOperation::GetBlendFactor(CCurvesColorOperation *this)
{
  return this->m_flBlendFactor;
}

//------------------------------------------------------------------------------
// Address: 0x100AB830
// Name: public: virtual bool CCurvesColorOperation::Serialize(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCurvesColorOperation::Serialize(CCurvesColorOperation *this, CDmxElement *pElement)
{
  CCurvesColorOperation *v2; // ebx
  CDmxAttribute *v3; // edi
  _DWORD *m_pData; // edi
  CDmxAttribute *v5; // edi
  float *v6; // edi
  CDmxAttribute *v7; // edi
  _BYTE *v8; // eax
  int *p_m_Size; // edi
  CDmxAttribute *v10; // eax
  CDmxAttribute *v11; // esi
  _DWORD *v12; // eax
  CUtlMemory<CVTFTexture::ResourceMemorySection,int> *v13; // esi
  int m_nAllocationCount; // eax
  int *v15; // ebx
  CVTFTexture::ResourceMemorySection *m_pMemory; // edi
  CVTFTexture::ResourceMemorySection *v17; // ecx
  int v18; // eax
  CVTFTexture::ResourceMemorySection *v19; // eax
  bool v20; // zf
  int m_Size; // [esp+10h] [ebp-4h]
  CDmxElement *pElementa; // [esp+1Ch] [ebp+8h]

  v2 = this;
  CDmxElement::SetName(this: pElement, pName: this->m_pName);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v3 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "channelMask");
  CDmxAttribute::AllocateDataMemory(this: v3, type: AT_INT);
  m_pData = v3->m_pData;
  if ( m_pData != nullptr )
    *m_pData = v2->m_nChannelMask;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v5 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "blendFactor");
  CDmxAttribute::AllocateDataMemory(this: v5, type: AT_FLOAT);
  v6 = (float *)v5->m_pData;
  if ( v6 != nullptr )
    *v6 = v2->m_flBlendFactor;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v7 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "enabled");
  CDmxAttribute::AllocateDataMemory(this: v7, type: AT_BOOL);
  v8 = v7->m_pData;
  p_m_Size = nullptr;
  if ( v8 != nullptr )
    *v8 = v2->m_bEnable;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  v10 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "controlPoints");
  v11 = v10;
  if ( v10->m_Type != AT_VECTOR3_ARRAY )
  {
    CDmxAttribute::AllocateDataMemory(this: v10, type: AT_VECTOR3_ARRAY);
    v12 = v11->m_pData;
    if ( v12 != nullptr )
    {
      *v12 = 0;
      v12[1] = 0;
      v12[2] = 0;
      v12[3] = 0;
      v12[4] = 0;
    }
  }
  v13 = (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)v11->m_pData;
  if ( v2->m_ControlPoints.m_Size > 0 )
  {
    pElementa = nullptr;
    m_Size = v2->m_ControlPoints.m_Size;
    while ( 1 )
    {
      m_nAllocationCount = v13->m_nAllocationCount;
      v15 = (int *)((char *)p_m_Size + (unsigned int)v2->m_ControlPoints.m_Memory.m_pMemory);
      m_pMemory = v13[1].m_pMemory;
      if ( (int)&m_pMemory->m_nDataAllocSize + 1 > m_nAllocationCount )
        CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
          this: v13,
          num: (int)&m_pMemory->m_nDataAllocSize - m_nAllocationCount + 1);
      ++v13[1].m_pMemory;
      v17 = v13->m_pMemory;
      v18 = (char *)v13[1].m_pMemory - (char *)m_pMemory - 1;
      v13[1].m_nAllocationCount = (int)v13->m_pMemory;
      if ( v18 > 0 )
        _V_memmove(dest: &v17[(int)m_pMemory + 1], src: &v17[(_DWORD)m_pMemory], count: 12 * v18);
      v19 = &v13->m_pMemory[(_DWORD)m_pMemory];
      if ( v19 != nullptr )
      {
        v19->m_nDataAllocSize = *v15;
        v19->m_nDataLength = v15[1];
        v19->m_pData = (unsigned __int8 *)v15[2];
      }
      p_m_Size = &pElementa->m_Attributes.m_Size;
      v20 = m_Size-- == 1;
      pElementa = (CDmxElement *)((char *)pElementa + 12);
      if ( v20 )
        break;
      v2 = this;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100AB9E0
// Name: public: virtual bool CSelectedHSVOperation::Serialize(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSelectedHSVOperation::Serialize(CSelectedHSVOperation *this, CDmxElement *pElement)
{
  CSelectedHSVOperation *v3; // edi
  CDmxAttribute *v4; // esi
  float *m_pData; // esi
  CDmxAttribute *v6; // esi
  _BYTE *v7; // esi
  CDmxAttribute *v8; // eax
  CDmxAttribute *v9; // esi
  _DWORD *v10; // eax
  CUtlMemory<CVTFTexture::ResourceMemorySection,int> *v11; // esi
  Vector *m_pMemory; // ecx
  CVTFTexture::ResourceMemorySection *v13; // edi
  _DWORD *v14; // ecx
  int m_nAllocationCount; // eax
  CVTFTexture::ResourceMemorySection *v16; // edx
  int v17; // eax
  CVTFTexture::ResourceMemorySection *v18; // eax
  bool v19; // zf
  CDmxAttribute *v20; // eax
  CDmxAttribute *v21; // esi
  _DWORD *v22; // eax
  CUtlMemory<CVTFTexture::ResourceMemorySection,int> *v23; // esi
  Vector *v24; // ecx
  CVTFTexture::ResourceMemorySection *v25; // edi
  _DWORD *v26; // ecx
  int v27; // eax
  CVTFTexture::ResourceMemorySection *v28; // edx
  int v29; // eax
  CVTFTexture::ResourceMemorySection *v30; // eax
  CDmxAttribute *v31; // esi
  _DWORD *v32; // esi
  CDmxAttribute *v33; // esi
  _DWORD *v34; // eax
  CDmxAttribute *v35; // esi
  float *v36; // esi
  CDmxAttribute *v37; // esi
  float *v38; // esi
  CDmxAttribute *v39; // esi
  _BYTE *v40; // esi
  CDmxAttribute *v41; // esi
  _BYTE *v42; // esi
  int m_Size; // [esp+Ch] [ebp-Ch]
  _DWORD *v45; // [esp+Ch] [ebp-Ch]
  _DWORD *v46; // [esp+10h] [ebp-8h]
  int v47; // [esp+10h] [ebp-8h]
  CDmxElement *pElementa; // [esp+20h] [ebp+8h]
  CDmxElement *pElementb; // [esp+20h] [ebp+8h]
  CDmxElement *pElementc; // [esp+20h] [ebp+8h]

  v3 = this;
  CDmxElement::SetName(this: pElement, pName: this->m_pName);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v4 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "blendFactor");
  CDmxAttribute::AllocateDataMemory(this: v4, type: AT_FLOAT);
  m_pData = (float *)v4->m_pData;
  if ( m_pData != nullptr )
    *m_pData = v3->m_flBlendFactor;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v6 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "enabled");
  CDmxAttribute::AllocateDataMemory(this: v6, type: AT_BOOL);
  v7 = v6->m_pData;
  if ( v7 != nullptr )
    *v7 = v3->m_bEnable;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  v8 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "selectedRGBs");
  v9 = v8;
  if ( v8->m_Type != AT_VECTOR3_ARRAY )
  {
    CDmxAttribute::AllocateDataMemory(this: v8, type: AT_VECTOR3_ARRAY);
    v10 = v9->m_pData;
    if ( v10 != nullptr )
    {
      *v10 = 0;
      v10[1] = 0;
      v10[2] = 0;
      v10[3] = 0;
      v10[4] = 0;
    }
  }
  v11 = (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)v9->m_pData;
  if ( v3->m_SelectedRGBs.m_Size > 0 )
  {
    pElementa = nullptr;
    m_Size = v3->m_SelectedRGBs.m_Size;
    do
    {
      m_pMemory = v3->m_SelectedRGBs.m_Memory.m_pMemory;
      v13 = v11[1].m_pMemory;
      v14 = (_DWORD *)((int)&m_pMemory->x + (_DWORD)pElementa);
      m_nAllocationCount = v11->m_nAllocationCount;
      v46 = v14;
      if ( (int)&v13->m_nDataAllocSize + 1 > m_nAllocationCount )
      {
        CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
          this: v11,
          num: (int)&v13->m_nDataAllocSize - m_nAllocationCount + 1);
        v14 = v46;
      }
      ++v11[1].m_pMemory;
      v16 = v11->m_pMemory;
      v17 = (char *)v11[1].m_pMemory - (char *)v13 - 1;
      v11[1].m_nAllocationCount = (int)v11->m_pMemory;
      if ( v17 > 0 )
      {
        _V_memmove(dest: &v16[(int)v13 + 1], src: &v16[(_DWORD)v13], count: 12 * v17);
        v14 = v46;
      }
      v18 = &v11->m_pMemory[(_DWORD)v13];
      if ( v18 != nullptr )
      {
        v18->m_nDataAllocSize = *v14;
        v18->m_nDataLength = v14[1];
        v18->m_pData = (unsigned __int8 *)v14[2];
      }
      pElementa = (CDmxElement *)((char *)pElementa + 12);
      v19 = m_Size-- == 1;
      v3 = this;
    }
    while ( !v19 );
  }
  v20 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "selectedHSVs");
  v21 = v20;
  if ( v20->m_Type != AT_VECTOR3_ARRAY )
  {
    CDmxAttribute::AllocateDataMemory(this: v20, type: AT_VECTOR3_ARRAY);
    v22 = v21->m_pData;
    if ( v22 != nullptr )
    {
      *v22 = 0;
      v22[1] = 0;
      v22[2] = 0;
      v22[3] = 0;
      v22[4] = 0;
    }
  }
  v23 = (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)v21->m_pData;
  if ( v3->m_SelectedHSVs.m_Size > 0 )
  {
    pElementb = nullptr;
    v47 = v3->m_SelectedHSVs.m_Size;
    do
    {
      v24 = v3->m_SelectedHSVs.m_Memory.m_pMemory;
      v25 = v23[1].m_pMemory;
      v26 = (_DWORD *)((int)&v24->x + (_DWORD)pElementb);
      v27 = v23->m_nAllocationCount;
      v45 = v26;
      if ( (int)&v25->m_nDataAllocSize + 1 > v27 )
      {
        CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
          this: v23,
          num: (int)&v25->m_nDataAllocSize - v27 + 1);
        v26 = v45;
      }
      ++v23[1].m_pMemory;
      v28 = v23->m_pMemory;
      v29 = (char *)v23[1].m_pMemory - (char *)v25 - 1;
      v23[1].m_nAllocationCount = (int)v23->m_pMemory;
      if ( v29 > 0 )
      {
        _V_memmove(dest: &v28[(int)v25 + 1], src: &v28[(_DWORD)v25], count: 12 * v29);
        v26 = v45;
      }
      v30 = &v23->m_pMemory[(_DWORD)v25];
      if ( v30 != nullptr )
      {
        v30->m_nDataAllocSize = *v26;
        v30->m_nDataLength = v26[1];
        v30->m_pData = (unsigned __int8 *)v26[2];
      }
      pElementb = (CDmxElement *)((char *)pElementb + 12);
      v19 = v47-- == 1;
      v3 = this;
    }
    while ( !v19 );
  }
  pElementc = (CDmxElement *)v3->m_SelectionMethod;
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v31 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "selectionMethod");
  CDmxAttribute::AllocateDataMemory(this: v31, type: AT_INT);
  v32 = v31->m_pData;
  if ( v32 != nullptr )
    *v32 = pElementc;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v33 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "deltaHSV");
  CDmxAttribute::AllocateDataMemory(this: v33, type: AT_VECTOR3);
  v34 = v33->m_pData;
  if ( v34 != nullptr )
  {
    *v34 = LODWORD(v3->m_DeltaHSV.x);
    v34[1] = LODWORD(v3->m_DeltaHSV.y);
    v34[2] = LODWORD(v3->m_DeltaHSV.z);
  }
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v35 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "tolerance");
  CDmxAttribute::AllocateDataMemory(this: v35, type: AT_FLOAT);
  v36 = (float *)v35->m_pData;
  if ( v36 != nullptr )
    *v36 = v3->m_Tolerance;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v37 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "fuzziness");
  CDmxAttribute::AllocateDataMemory(this: v37, type: AT_FLOAT);
  v38 = (float *)v37->m_pData;
  if ( v38 != nullptr )
    *v38 = v3->m_Fuzziness;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v39 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "colorize");
  CDmxAttribute::AllocateDataMemory(this: v39, type: AT_BOOL);
  v40 = v39->m_pData;
  if ( v40 != nullptr )
    *v40 = v3->m_bColorize;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v41 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "invertSelection");
  CDmxAttribute::AllocateDataMemory(this: v41, type: AT_BOOL);
  v42 = v41->m_pData;
  if ( v42 != nullptr )
    *v42 = v3->m_bInvertSelection;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100ABD90
// Name: public: virtual void CFullScreenSelectionPanel::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CFullScreenSelectionPanel::OnCursorMoved(
        CFullScreenSelectionPanel *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        int x,
        KeyValues *y)
{
  int v6; // esi
  CSelectedHSVOperation *m_pOp; // eax
  CSelectedHSVOperation *v8; // edi
  Vector hsv; // [esp+4h] [ebp-1Ch] BYREF
  Vector rgb; // [esp+10h] [ebp-10h] BYREF
  BGRA8888_t pixelValue; // [esp+1Ch] [ebp-4h]

  if ( this->m_bMouseDown )
  {
    v6 = ((int (__thiscall *)(IMaterialSystem *, int, int))materials->GetRenderContext)(a1: materials, a2, a3);
    if ( v6 != 0 )
      (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 8))(a1: v6);
    (*(void (__thiscall **)(int, int, KeyValues *, int, int))(*(_DWORD *)v6 + 52))(a1: v6, a2: x, a3: y, a4: 1, a5: 1);
    if ( !g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
      && !g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL) )
    {
      m_pOp = this->m_pOp;
      m_pOp->m_SelectedRGBs.m_Size = 0;
      m_pOp->m_SelectedHSVs.m_Size = 0;
    }
    v8 = this->m_pOp;
    rgb.x = (float)pixelValue.r * 0.0039215689;
    rgb.y = (float)pixelValue.g * 0.0039215689;
    rgb.z = (float)pixelValue.b * 0.0039215689;
    RGBtoHSV(&rgb, &hsv);
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: &v8->m_SelectedRGBs,
      elem: v8->m_SelectedRGBs.m_Size,
      src: &rgb);
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: &v8->m_SelectedHSVs,
      elem: v8->m_SelectedHSVs.m_Size,
      src: &hsv);
    colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 12))(a1: v6);
    (*(void (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6);
  }
  CColorBalanceUIPanel::ReadUncorrectedImage((vgui::TreeView *)this, itemIndex: x, msg: y);
}

//------------------------------------------------------------------------------
// Address: 0x100ABED0
// Name: public: virtual void CUncorrectedImagePanel::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUncorrectedImagePanel::OnCursorMoved(CUncorrectedImagePanel *this, int x, int y)
{
  bool v4; // bl
  int m_nWidth; // edi
  int v6; // ecx
  float v7; // xmm0_4
  int v8; // ecx
  int m_nHeight; // eax
  BGRA8888_t *v10; // eax
  CSelectedHSVOperation *m_pHSVOp; // ecx
  unsigned __int8 r; // cl
  unsigned __int8 g; // dl
  unsigned __int8 b; // al
  CSelectedHSVOperation *v15; // ecx
  CSelectedHSVOperation *v16; // esi
  color24 v17; // [esp-Ch] [ebp-38h]
  Vector hsv; // [esp+Ch] [ebp-20h] BYREF
  Vector rgb; // [esp+18h] [ebp-14h] BYREF
  int sy; // [esp+24h] [ebp-8h] BYREF
  int sx; // [esp+28h] [ebp-4h] BYREF

  if ( this->m_bMouseDown )
  {
    v4 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
      || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL);
    vgui::Panel::GetSize(this, wide: &sx, tall: &sy);
    m_nWidth = this->m_nWidth;
    v6 = (int)(float)((float)((float)((float)this->m_TextureSubRect.width * (float)x) / (float)sx)
                    + (float)this->m_TextureSubRect.x);
    v7 = (float)((float)((float)this->m_TextureSubRect.height * (float)y) / (float)sy) + (float)this->m_TextureSubRect.y;
    if ( v6 >= m_nWidth )
      v6 = this->m_nWidth;
    v8 = v6 < 0 ? 0 : v6;
    m_nHeight = this->m_nHeight;
    if ( (int)v7 < m_nHeight )
      m_nHeight = (int)v7;
    v10 = &this->m_pImageBuffer[v8 + m_nWidth * (m_nHeight < 0 ? 0 : m_nHeight)];
    if ( !v4 )
    {
      m_pHSVOp = this->m_pHSVOp;
      m_pHSVOp->m_SelectedRGBs.m_Size = 0;
      m_pHSVOp->m_SelectedHSVs.m_Size = 0;
    }
    r = v10->r;
    g = v10->g;
    b = v10->b;
    LOBYTE(x) = r;
    v15 = this->m_pHSVOp;
    BYTE1(x) = g;
    *(_WORD *)&v17.r = x;
    v17.b = b;
    CColorOperationList::Apply(this: v15->m_pOpList, in: v17, out: (color24 *)&x, pFinalOp: v15);
    v16 = this->m_pHSVOp;
    rgb.x = (float)(unsigned __int8)x * 0.0039215689;
    rgb.y = (float)BYTE1(x) * 0.0039215689;
    rgb.z = (float)BYTE2(x) * 0.0039215689;
    RGBtoHSV(&rgb, &hsv);
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: &v16->m_SelectedRGBs,
      elem: v16->m_SelectedRGBs.m_Size,
      src: &rgb);
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: &v16->m_SelectedHSVs,
      elem: v16->m_SelectedHSVs.m_Size,
      src: &hsv);
    colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AC0A0
// Name: private: void CSelectedHSVUIPanel::PickColorFromTextEntry(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectedHSVUIPanel::PickColorFromTextEntry(CSelectedHSVUIPanel *this, bool bRGB)
{
  unsigned __int8 v3; // bl
  int v4; // eax
  vgui::TextEntry *m_pColorEntry3; // ecx
  unsigned __int8 v6; // al
  CSelectedHSVOperation *m_pHSVOperation; // ecx
  CSelectedHSVOperation *v8; // esi
  Vector *p_hsv; // eax
  Vector hsv; // [esp+8h] [ebp-1Ch] BYREF
  Vector rgb; // [esp+14h] [ebp-10h] BYREF
  int g; // [esp+20h] [ebp-4h]

  v3 = this->m_pColorEntry1->GetValueAsInt(this: this->m_pColorEntry1);
  v4 = this->m_pColorEntry2->GetValueAsInt(this: this->m_pColorEntry2);
  m_pColorEntry3 = this->m_pColorEntry3;
  g = v4;
  v6 = m_pColorEntry3->GetValueAsInt(this: m_pColorEntry3);
  m_pHSVOperation = this->m_pHSVOperation;
  m_pHSVOperation->m_SelectedRGBs.m_Size = 0;
  m_pHSVOperation->m_SelectedHSVs.m_Size = 0;
  v8 = this->m_pHSVOperation;
  rgb.x = (float)v3 * 0.0039215689;
  rgb.y = (float)(unsigned __int8)g * 0.0039215689;
  rgb.z = (float)v6 * 0.0039215689;
  if ( bRGB )
  {
    RGBtoHSV(&rgb, &hsv);
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: &v8->m_SelectedRGBs,
      elem: v8->m_SelectedRGBs.m_Size,
      src: &rgb);
    p_hsv = &hsv;
  }
  else
  {
    HSVtoRGB(hsv: &rgb, rgb: &hsv);
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: &v8->m_SelectedRGBs,
      elem: v8->m_SelectedRGBs.m_Size,
      src: &hsv);
    p_hsv = &rgb;
  }
  CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
    this: &v8->m_SelectedHSVs,
    elem: v8->m_SelectedHSVs.m_Size,
    src: p_hsv);
  colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
}

//------------------------------------------------------------------------------
// Address: 0x100AC1A0
// Name: public: virtual bool CColorBalanceOperation::Serialize(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CColorBalanceOperation::Serialize(CColorBalanceOperation *this, CDmxElement *pElement)
{
  CDmxAttribute *v3; // edi
  float *m_pData; // eax
  CDmxAttribute *v5; // ebx
  _BYTE *v6; // ebx
  CDmxAttribute *v7; // ebx
  _BYTE *v8; // ebx
  CDmxAttribute *v9; // ebx
  CDmxAttribute *v10; // edi
  CDmxAttribute *v11; // esi
  _DWORD *v12; // eax
  _DWORD *v13; // eax
  CUtlMemory<S3RGBA,int> *v14; // ebx
  _DWORD *v15; // eax
  CUtlMemory<S3RGBA,int> *v16; // edi
  CUtlMemory<S3RGBA,int> *v17; // edx
  S3RGBA *m_pMemory; // esi
  int m_nAllocationCount; // eax
  S3RGBA *v20; // ecx
  int v21; // eax
  float *v22; // esi
  S3RGBA *v23; // esi
  int v24; // eax
  S3RGBA *v25; // ecx
  int v26; // eax
  float *v27; // esi
  S3RGBA *v28; // esi
  int v29; // eax
  S3RGBA *v30; // ecx
  int v31; // eax
  float *v32; // esi
  int i; // [esp+Ch] [ebp-8h]
  float *m_MagentaGreenBalance; // [esp+10h] [ebp-4h]
  CUtlMemory<S3RGBA,int> *cyanRedBalance; // [esp+1Ch] [ebp+8h]

  CDmxElement::SetName(this: pElement, pName: this->m_pName);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v3 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "blendFactor");
  CDmxAttribute::AllocateDataMemory(this: v3, type: AT_FLOAT);
  m_pData = (float *)v3->m_pData;
  if ( m_pData != nullptr )
    *m_pData = this->m_flBlendFactor;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v5 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "enabled");
  CDmxAttribute::AllocateDataMemory(this: v5, type: AT_BOOL);
  v6 = v5->m_pData;
  if ( v6 != nullptr )
    *v6 = this->m_bEnable;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  CDmxElement::LockForChanges(this: pElement, bLock: true);
  v7 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "preserveLuminosity");
  CDmxAttribute::AllocateDataMemory(this: v7, type: AT_BOOL);
  v8 = v7->m_pData;
  if ( v8 != nullptr )
    *v8 = this->m_PreserveLuminosity;
  if ( pElement != nullptr )
    CDmxElement::LockForChanges(this: pElement, bLock: false);
  v9 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "cyanRedBalance");
  v10 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "magentaGreenBalance");
  v11 = CDmxElement::AddAttribute(this: pElement, pAttributeName: "yellowBlueBalance");
  if ( v9->m_Type == AT_FLOAT_ARRAY )
  {
    cyanRedBalance = (CUtlMemory<S3RGBA,int> *)v9->m_pData;
  }
  else
  {
    CDmxAttribute::AllocateDataMemory(this: v9, type: AT_FLOAT_ARRAY);
    v12 = v9->m_pData;
    if ( v12 != nullptr )
    {
      *v12 = 0;
      v12[1] = 0;
      v12[2] = 0;
      v12[3] = 0;
      v12[4] = 0;
    }
    cyanRedBalance = (CUtlMemory<S3RGBA,int> *)v9->m_pData;
  }
  if ( v10->m_Type != AT_FLOAT_ARRAY )
  {
    CDmxAttribute::AllocateDataMemory(this: v10, type: AT_FLOAT_ARRAY);
    v13 = v10->m_pData;
    if ( v13 != nullptr )
    {
      *v13 = 0;
      v13[1] = 0;
      v13[2] = 0;
      v13[3] = 0;
      v13[4] = 0;
    }
  }
  v14 = (CUtlMemory<S3RGBA,int> *)v10->m_pData;
  if ( v11->m_Type != AT_FLOAT_ARRAY )
  {
    CDmxAttribute::AllocateDataMemory(this: v11, type: AT_FLOAT_ARRAY);
    v15 = v11->m_pData;
    if ( v15 != nullptr )
    {
      *v15 = 0;
      v15[1] = 0;
      v15[2] = 0;
      v15[3] = 0;
      v15[4] = 0;
    }
  }
  v16 = (CUtlMemory<S3RGBA,int> *)v11->m_pData;
  m_MagentaGreenBalance = this->m_MagentaGreenBalance;
  for ( i = 3; i != 0; --i )
  {
    v17 = cyanRedBalance;
    m_pMemory = cyanRedBalance[1].m_pMemory;
    m_nAllocationCount = cyanRedBalance->m_nAllocationCount;
    if ( (int)&m_pMemory->g > m_nAllocationCount )
    {
      CUtlMemory<INetMessage *,int>::Grow(this: cyanRedBalance, num: (int)(&m_pMemory->g - m_nAllocationCount));
      v17 = cyanRedBalance;
    }
    ++v17[1].m_pMemory;
    v20 = v17->m_pMemory;
    v21 = (char *)v17[1].m_pMemory - (char *)m_pMemory - 1;
    v17[1].m_nAllocationCount = (int)v17->m_pMemory;
    if ( v21 > 0 )
    {
      _V_memmove(dest: &v20[(_DWORD)m_pMemory + 1], src: &v20[(_DWORD)m_pMemory], count: 4 * v21);
      v17 = cyanRedBalance;
    }
    v22 = (float *)&v17->m_pMemory[(_DWORD)m_pMemory];
    if ( v22 != nullptr )
      *v22 = *(m_MagentaGreenBalance - 3);
    v23 = v14[1].m_pMemory;
    v24 = v14->m_nAllocationCount;
    if ( (int)&v23->g > v24 )
      CUtlMemory<INetMessage *,int>::Grow(this: v14, num: (int)(&v23->g - v24));
    ++v14[1].m_pMemory;
    v25 = v14->m_pMemory;
    v26 = (char *)v14[1].m_pMemory - (char *)v23 - 1;
    v14[1].m_nAllocationCount = (int)v14->m_pMemory;
    if ( v26 > 0 )
      _V_memmove(dest: &v25[(_DWORD)v23 + 1], src: &v25[(_DWORD)v23], count: 4 * v26);
    v27 = (float *)&v14->m_pMemory[(_DWORD)v23];
    if ( v27 != nullptr )
      *v27 = *m_MagentaGreenBalance;
    v28 = v16[1].m_pMemory;
    v29 = v16->m_nAllocationCount;
    if ( (int)&v28->g > v29 )
      CUtlMemory<INetMessage *,int>::Grow(this: v16, num: (int)(&v28->g - v29));
    ++v16[1].m_pMemory;
    v30 = v16->m_pMemory;
    v31 = (char *)v16[1].m_pMemory - (char *)v28 - 1;
    v16[1].m_nAllocationCount = (int)v16->m_pMemory;
    if ( v31 > 0 )
      _V_memmove(dest: &v30[(_DWORD)v28 + 1], src: &v30[(_DWORD)v28], count: 4 * v31);
    v32 = (float *)&v16->m_pMemory[(_DWORD)v28];
    if ( v32 != nullptr )
      *v32 = m_MagentaGreenBalance[3];
    ++m_MagentaGreenBalance;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100AC460
// Name: CreateColorOp
// Source: json
//------------------------------------------------------------------------------
CCurvesColorOperation *__usercall CreateColorOp@<eax>(
        ColorCorrectionTool_t nToolId@<eax>,
        CColorOperationList *pOpList@<esi>)
{
  CColorBalanceOperation *v2; // eax
  CCurvesColorOperation *result; // eax
  CCurvesColorOperation *v4; // eax
  CColorLookupOperation *v5; // eax
  CLevelsColorOperation *v6; // eax
  CSelectedHSVOperation *v7; // eax

  switch ( nToolId )
  {
    case CC_TOOL_CURVES:
      v4 = (CCurvesColorOperation *)MemAlloc_Alloc(nSize: 0x52Cu);
      if ( v4 == nullptr )
        goto LABEL_12;
      result = CCurvesColorOperation::CCurvesColorOperation(this: v4);
      break;
    case CC_TOOL_LEVELS:
      v6 = (CLevelsColorOperation *)MemAlloc_Alloc(nSize: 0x528u);
      if ( v6 == nullptr )
        goto LABEL_12;
      result = (CCurvesColorOperation *)CLevelsColorOperation::CLevelsColorOperation(this: v6, pList: pOpList);
      break;
    case CC_TOOL_SELECTED_HSV:
      v7 = (CSelectedHSVOperation *)MemAlloc_Alloc(nSize: 0x154u);
      if ( v7 == nullptr )
        goto LABEL_12;
      result = (CCurvesColorOperation *)CSelectedHSVOperation::CSelectedHSVOperation(this: v7, pList: pOpList);
      break;
    case CC_TOOL_LOOKUP:
      v5 = (CColorLookupOperation *)MemAlloc_Alloc(nSize: 0x218u);
      if ( v5 == nullptr )
        goto LABEL_12;
      result = (CCurvesColorOperation *)CColorLookupOperation::CColorLookupOperation(this: v5);
      break;
    case CC_TOOL_BALANCE:
      v2 = (CColorBalanceOperation *)MemAlloc_Alloc(nSize: 0x1C34u);
      if ( v2 == nullptr )
        goto LABEL_12;
      result = (CCurvesColorOperation *)CColorBalanceOperation::CColorBalanceOperation(this: v2);
      break;
    default:
LABEL_12:
      result = nullptr;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AC510
// Name: public: virtual void CNewOperationDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewOperationDialog::OnCommand(CNewOperationDialog *this, const char *command)
{
  int ActiveItem; // eax
  CCurvesColorOperation *ColorOp; // esi
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  char buf[256]; // [esp+8h] [ebp-100h] BYREF

  if ( _V_stricmp(s1: command, s2: "Create") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "Cancel") != 0 )
      return;
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
    {
      v6 = KeyValues::KeyValues(this: v7, setName: "Command", firstKey: "Command", firstValue: "NewCancel");
      goto LABEL_11;
    }
    goto LABEL_10;
  }
  ActiveItem = vgui::ComboBox::GetActiveItem(this: this->m_pOperationType);
  ColorOp = CreateColorOp(nToolId: (ColorCorrectionTool_t)(ActiveItem + 1), pOpList: this->m_pOpList);
  if ( this->m_pName->GetTextLength(this: this->m_pName) > 0 )
  {
    this->m_pName->GetText_2(this: this->m_pName, a2: buf, a3: 256);
    ColorOp->SetName(this: ColorOp, a2: buf);
  }
  CColorOperationList::AddOperation(this: this->m_pOpList, pOp: ColorOp);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 == nullptr )
  {
LABEL_10:
    v6 = nullptr;
    goto LABEL_11;
  }
  v6 = KeyValues::KeyValues(this: v5, setName: "Command", firstKey: "Command", firstValue: "NewComplete");
LABEL_11:
  this->PostActionSignal(this, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x100AC600
// Name: public: virtual bool CColorOperationListPanel::OnWriteFileToDisk(char const __near *,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CColorOperationListPanel::OnWriteFileToDisk(
        CColorOperationListPanel *this,
        const char *pFileName,
        const char *pFileFormat,
        KeyValues *pContextKeyValues)
{
  char result; // al
  char *v6; // eax
  const __m128i *v7; // esi
  int v8; // eax
  char pRawPath[260]; // [esp+Ch] [ebp-104h] BYREF

  result = CColorOperationListPanel::SaveVCCFile(
             this: (CColorOperationListPanel *)((char *)this - 380),
             pFullPath: pFileName);
  if ( result != 0 )
  {
    CUtlString::operator=(this: (CUtlString *)&this->_actionSignalTargetDar.m_Size, src: pFileName);
    ComputeModFilename(pContentFileName: pFileName, pBuf: pRawPath, nBufLen: 0x104u);
    v6 = V_stristr(pStr: pRawPath, pSearch: "\\materialsrc\\");
    if ( v6 != nullptr )
    {
      v7 = (const __m128i *)(v6 + 12);
      v8 = _V_strlen(str: v6 + 12);
      memmove(dst: (__m128i *)((char *)&v7[-1].m128i_u64[1] + 6), src: v7, count: v8 + 1);
    }
    V_SetExtension(path: pRawPath, extension: ".raw", pathStringLength: 260);
    return CColorOperationListPanel::SaveRawFile(
             this: (CColorOperationListPanel *)((char *)this - 380),
             pFullPath: pRawPath);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AC6B0
// Name: private: virtual void CColorOperationListPanel::OnLaunchOperation(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CColorOperationListPanel::OnLaunchOperation(
        CColorOperationListPanel *this@<ecx>,
        int a2@<esi>,
        int item)
{
  if ( item >= 0 && item < this->m_OperationList.m_OpList.m_Size )
    CColorOperationListPanel::LaunchOperationPanel(
      this,
      a2,
      pOp: (CCurvesColorOperation *)this->m_OperationList.m_OpList.m_Memory.m_pMemory[item]);
  else
    CColorOperationListPanel::LaunchOperationPanel(this, a2, pOp: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100AC6F0
// Name: private: virtual void CColorOperationListPanel::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorOperationListPanel::OnMouseDoublePressed(CColorOperationListPanel *this, const char *code)
{
  int v3; // eax

  CBaseServer::RemoveClientFromGame(this, panelName: code);
  if ( code == (const char *)107 )
  {
    v3 = this->m_pOperationListPanel->GetSelectedItem(this: this->m_pOperationListPanel, a2: 0);
    if ( v3 >= 0 && v3 < this->m_OperationList.m_OpList.m_Size )
      CColorOperationListPanel::LaunchOperationPanel(
        this,
        a2: (int)this,
        pOp: (CCurvesColorOperation *)this->m_OperationList.m_OpList.m_Memory.m_pMemory[v3]);
    else
      CColorOperationListPanel::LaunchOperationPanel(this, a2: (int)this, pOp: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AC750
// Name: private: virtual void CColorOperationListPanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorOperationListPanel::OnKeyCodeTyped(CColorOperationListPanel *this, ButtonCode_t code)
{
  int v3; // eax

  if ( code == KEY_ENTER )
  {
    v3 = this->m_pOperationListPanel->GetSelectedItem(this: this->m_pOperationListPanel, a2: 0);
    if ( v3 >= 0 && v3 < this->m_OperationList.m_OpList.m_Size )
    {
      CColorOperationListPanel::LaunchOperationPanel(
        this,
        a2: (int)this,
        pOp: (CCurvesColorOperation *)this->m_OperationList.m_OpList.m_Memory.m_pMemory[v3]);
      vgui::EditablePanel::OnKeyCodeTyped(this, code: KEY_ENTER);
    }
    else
    {
      CColorOperationListPanel::LaunchOperationPanel(this, a2: (int)this, pOp: nullptr);
      vgui::EditablePanel::OnKeyCodeTyped(this, code: KEY_ENTER);
    }
  }
  else
  {
    if ( code == KEY_ESCAPE )
      ShowHideColorCorrectionUI();
    vgui::EditablePanel::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AC900
// Name: public: virtual bool CCurvesColorOperation::Unserialize(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCurvesColorOperation::Unserialize(CCurvesColorOperation *this, CDmxElement *pElement)
{
  CCurvesColorOperation *v2; // esi
  const char *Name; // eax
  const CDmxAttribute *Attribute; // eax
  int *m_pData; // eax
  const CDmxAttribute *v6; // eax
  int *v7; // eax
  const CDmxAttribute *v8; // eax
  char *v9; // eax
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *v10; // edi
  int v11; // esi
  int m_Size; // ebx

  v2 = this;
  Name = CDmxElement::GetName(this: pElement);
  V_strncpy(pDest: v2->m_pName, pSrc: Name, maxLen: 256);
  Attribute = CDmxElement::GetAttribute(this: pElement, pAttributeName: "channelMask");
  if ( Attribute != nullptr )
  {
    if ( Attribute->m_Type == AT_INT )
    {
      m_pData = (int *)Attribute->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<int>'::`4'::defaultValue = 0;
      m_pData = &`CDmxAttribute::GetValue<int>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<int>'::`4'::defaultValue = 0;
    m_pData = &`CDmxElement::GetValue<int>'::`4'::defaultValue;
  }
  v2->m_nChannelMask = *m_pData;
  v6 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "blendFactor");
  if ( v6 != nullptr )
  {
    if ( v6->m_Type == AT_FLOAT )
    {
      v7 = (int *)v6->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
      v7 = &`CDmxAttribute::GetValue<float>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
    v7 = &`CDmxElement::GetValue<float>'::`4'::defaultValue;
  }
  v2->m_flBlendFactor = *(float *)v7;
  v8 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "enabled");
  if ( v8 != nullptr )
  {
    if ( v8->m_Type == AT_BOOL )
    {
      v9 = (char *)v8->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<bool>'::`4'::defaultValue = 0;
      v9 = &`CDmxAttribute::GetValue<bool>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<bool>'::`4'::defaultValue = 0;
    v9 = &`CDmxElement::GetValue<bool>'::`4'::defaultValue;
  }
  v2->m_bEnable = *v9;
  v10 = CDmxElement::GetArray<Vector>(this: pElement, pAttributeName: "controlPoints");
  if ( v10->m_Size > 0 )
  {
    v11 = 0;
    m_Size = v10->m_Size;
    do
    {
      CUtlSortVector<Vector,CCurvesColorOperation::CurvesLessFunc>::Insert(
        this: &this->m_ControlPoints,
        src: &v10->m_Memory.m_pMemory[v11++]);
      --m_Size;
    }
    while ( m_Size != 0 );
    v2 = this;
  }
  CCurvesColorOperation::UpdateOutColorArray(this: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100ACA30
// Name: public: virtual void CSelectedHSVOperation::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectedHSVOperation::Release(CSelectedHSVOperation *this)
{
  if ( this != nullptr )
  {
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_SelectedHSVs);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_SelectedRGBs);
    free(pMem: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ACA60
// Name: public: virtual bool CSelectedHSVOperation::Unserialize(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSelectedHSVOperation::Unserialize(CSelectedHSVOperation *this, CDmxElement *pElement)
{
  CDmxElement *v2; // edi
  CSelectedHSVOperation *v3; // esi
  const char *Name; // eax
  const CDmxAttribute *Attribute; // eax
  int *m_pData; // eax
  const CDmxAttribute *v7; // eax
  char *v8; // eax
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *v9; // ecx
  int v10; // edi
  int m_nAllocationCount; // eax
  _DWORD *v12; // ebx
  Vector *m_pMemory; // ecx
  int v14; // eax
  _DWORD *p_x; // eax
  const CDmxAttribute *v16; // eax
  int v17; // edi
  int v18; // eax
  _DWORD *v19; // ebx
  Vector *v20; // ecx
  int v21; // eax
  _DWORD *v22; // eax
  const CDmxAttribute *v23; // eax
  int *v24; // eax
  const CDmxAttribute *v25; // eax
  float *v26; // eax
  const CDmxAttribute *v27; // eax
  int *v28; // eax
  const CDmxAttribute *v29; // eax
  int *v30; // eax
  const CDmxAttribute *v31; // eax
  char *v32; // eax
  const CDmxAttribute *v33; // eax
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *selectedRGBs; // [esp+10h] [ebp-Ch]
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *selectedRGBsa; // [esp+10h] [ebp-Ch]
  int m_Size; // [esp+14h] [ebp-8h]
  int v39; // [esp+14h] [ebp-8h]
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *selectedHSVs; // [esp+18h] [ebp-4h]
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *selectedHSVsa; // [esp+18h] [ebp-4h]

  v2 = pElement;
  v3 = this;
  Name = CDmxElement::GetName(this: pElement);
  V_strncpy(pDest: v3->m_pName, pSrc: Name, maxLen: 256);
  Attribute = CDmxElement::GetAttribute(this: pElement, pAttributeName: "blendFactor");
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
  v3->m_flBlendFactor = *(float *)m_pData;
  v7 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "enabled");
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
  v3->m_bEnable = *v8;
  v9 = CDmxElement::GetArray<Vector>(this: pElement, pAttributeName: "selectedRGBs");
  selectedRGBs = v9;
  if ( v9->m_Size > 0 )
  {
    selectedHSVs = nullptr;
    m_Size = v9->m_Size;
    while ( 1 )
    {
      v10 = v3->m_SelectedRGBs.m_Size;
      m_nAllocationCount = v3->m_SelectedRGBs.m_Memory.m_nAllocationCount;
      v12 = (Vector **)((char *)&selectedHSVs->m_Memory.m_pMemory + (unsigned int)v9->m_Memory.m_pMemory);
      if ( v10 + 1 > m_nAllocationCount )
        CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
          this: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&v3->m_SelectedRGBs,
          num: v10 - m_nAllocationCount + 1);
      ++v3->m_SelectedRGBs.m_Size;
      m_pMemory = v3->m_SelectedRGBs.m_Memory.m_pMemory;
      v14 = v3->m_SelectedRGBs.m_Size - v10 - 1;
      v3->m_SelectedRGBs.m_pElements = m_pMemory;
      if ( v14 > 0 )
        _V_memmove(dest: &m_pMemory[v10 + 1], src: &m_pMemory[v10], count: 12 * v14);
      p_x = (_DWORD *)&v3->m_SelectedRGBs.m_Memory.m_pMemory[v10].x;
      if ( p_x != nullptr )
      {
        *p_x = *v12;
        p_x[1] = v12[1];
        p_x[2] = v12[2];
      }
      selectedHSVs = (const CUtlVector<Vector,CUtlMemory<Vector,int> > *)((char *)selectedHSVs + 12);
      if ( --m_Size == 0 )
        break;
      v9 = selectedRGBs;
    }
    v2 = pElement;
  }
  v16 = CDmxElement::GetAttribute(this: v2, pAttributeName: "selectedHSVs");
  if ( v16 != nullptr )
  {
    if ( v16->m_Type == AT_VECTOR3_ARRAY )
    {
      selectedHSVsa = (const CUtlVector<Vector,CUtlMemory<Vector,int> > *)v16->m_pData;
    }
    else
    {
      if ( (`CDmxAttribute::GetArray<Vector>'::`4'::`local static guard' & 1) == 0 )
      {
        `CDmxAttribute::GetArray<Vector>'::`4'::`local static guard' |= 1u;
        `CDmxAttribute::GetArray<Vector>'::`4'::defaultArray.m_Memory.m_pMemory = nullptr;
        `CDmxAttribute::GetArray<Vector>'::`4'::defaultArray.m_Memory.m_nAllocationCount = 0;
        `CDmxAttribute::GetArray<Vector>'::`4'::defaultArray.m_Memory.m_nGrowSize = 0;
        `CDmxAttribute::GetArray<Vector>'::`4'::defaultArray.m_Size = 0;
        `CDmxAttribute::GetArray<Vector>'::`4'::defaultArray.m_pElements = nullptr;
        atexit(func: `CDmxAttribute::GetArray<Vector>'::`4'::`dynamic atexit destructor for 'defaultArray'');
      }
      selectedHSVsa = &`CDmxAttribute::GetArray<Vector>'::`4'::defaultArray;
    }
  }
  else
  {
    if ( (`CDmxElement::GetArray<Vector>'::`4'::`local static guard' & 1) == 0 )
    {
      `CDmxElement::GetArray<Vector>'::`4'::`local static guard' |= 1u;
      `CDmxElement::GetArray<Vector>'::`4'::defaultValue.m_Memory.m_pMemory = nullptr;
      `CDmxElement::GetArray<Vector>'::`4'::defaultValue.m_Memory.m_nAllocationCount = 0;
      `CDmxElement::GetArray<Vector>'::`4'::defaultValue.m_Memory.m_nGrowSize = 0;
      `CDmxElement::GetArray<Vector>'::`4'::defaultValue.m_Size = 0;
      `CDmxElement::GetArray<Vector>'::`4'::defaultValue.m_pElements = nullptr;
      atexit(func: `CDmxElement::GetArray<Vector>'::`4'::`dynamic atexit destructor for 'defaultValue'');
    }
    selectedHSVsa = &`CDmxElement::GetArray<Vector>'::`4'::defaultValue;
  }
  if ( selectedHSVsa->m_Size > 0 )
  {
    v39 = 0;
    selectedRGBsa = (const CUtlVector<Vector,CUtlMemory<Vector,int> > *)selectedHSVsa->m_Size;
    do
    {
      v17 = v3->m_SelectedHSVs.m_Size;
      v18 = v3->m_SelectedHSVs.m_Memory.m_nAllocationCount;
      v19 = (_DWORD *)&selectedHSVsa->m_Memory.m_pMemory[v39].x;
      if ( v17 + 1 > v18 )
        CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
          this: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&v3->m_SelectedHSVs,
          num: v17 - v18 + 1);
      ++v3->m_SelectedHSVs.m_Size;
      v20 = v3->m_SelectedHSVs.m_Memory.m_pMemory;
      v21 = v3->m_SelectedHSVs.m_Size - v17 - 1;
      v3->m_SelectedHSVs.m_pElements = v20;
      if ( v21 > 0 )
        _V_memmove(dest: &v20[v17 + 1], src: &v20[v17], count: 12 * v21);
      v22 = (_DWORD *)&v3->m_SelectedHSVs.m_Memory.m_pMemory[v17].x;
      if ( v22 != nullptr )
      {
        *v22 = *v19;
        v22[1] = v19[1];
        v22[2] = v19[2];
      }
      ++v39;
      selectedRGBsa = (const CUtlVector<Vector,CUtlMemory<Vector,int> > *)((char *)selectedRGBsa - 1);
    }
    while ( selectedRGBsa != nullptr );
    v2 = pElement;
    v3 = this;
  }
  v23 = CDmxElement::GetAttribute(this: v2, pAttributeName: "selectionMethod");
  if ( v23 != nullptr )
  {
    if ( v23->m_Type == AT_INT )
    {
      v24 = (int *)v23->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<int>'::`4'::defaultValue = 0;
      v24 = &`CDmxAttribute::GetValue<int>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<int>'::`4'::defaultValue = 0;
    v24 = &`CDmxElement::GetValue<int>'::`4'::defaultValue;
  }
  v3->m_SelectionMethod = *v24;
  v25 = CDmxElement::GetAttribute(this: v2, pAttributeName: "deltaHSV");
  if ( v25 != nullptr )
  {
    if ( v25->m_Type == AT_VECTOR3 )
    {
      v26 = (float *)v25->m_pData;
    }
    else
    {
      if ( (`CDmxAttribute::GetValue<Vector>'::`4'::`local static guard' & 1) == 0 )
        `CDmxAttribute::GetValue<Vector>'::`4'::`local static guard' |= 1u;
      `CDmxAttribute::GetValue<Vector>'::`4'::defaultValue = 0;
      dword_104EEE04 = 0;
      dword_104EEE08 = 0;
      v26 = (float *)&`CDmxAttribute::GetValue<Vector>'::`4'::defaultValue;
    }
  }
  else
  {
    if ( (`CDmxElement::GetValue<Vector>'::`4'::`local static guard' & 1) == 0 )
      `CDmxElement::GetValue<Vector>'::`4'::`local static guard' |= 1u;
    `CDmxElement::GetValue<Vector>'::`4'::defaultValue = 0;
    dword_104EEE20 = 0;
    dword_104EEE24 = 0;
    v26 = (float *)&`CDmxElement::GetValue<Vector>'::`4'::defaultValue;
  }
  v3->m_DeltaHSV.x = *v26;
  v3->m_DeltaHSV.y = v26[1];
  v3->m_DeltaHSV.z = v26[2];
  v27 = CDmxElement::GetAttribute(this: v2, pAttributeName: "tolerance");
  if ( v27 != nullptr )
  {
    if ( v27->m_Type == AT_FLOAT )
    {
      v28 = (int *)v27->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
      v28 = &`CDmxAttribute::GetValue<float>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
    v28 = &`CDmxElement::GetValue<float>'::`4'::defaultValue;
  }
  v3->m_Tolerance = *(float *)v28;
  v29 = CDmxElement::GetAttribute(this: v2, pAttributeName: "fuzziness");
  if ( v29 != nullptr )
  {
    if ( v29->m_Type == AT_FLOAT )
    {
      v30 = (int *)v29->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
      v30 = &`CDmxAttribute::GetValue<float>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
    v30 = &`CDmxElement::GetValue<float>'::`4'::defaultValue;
  }
  v3->m_Fuzziness = *(float *)v30;
  v31 = CDmxElement::GetAttribute(this: v2, pAttributeName: "colorize");
  if ( v31 != nullptr )
  {
    if ( v31->m_Type == AT_BOOL )
    {
      v32 = (char *)v31->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<bool>'::`4'::defaultValue = 0;
      v32 = &`CDmxAttribute::GetValue<bool>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<bool>'::`4'::defaultValue = 0;
    v32 = &`CDmxElement::GetValue<bool>'::`4'::defaultValue;
  }
  v3->m_bColorize = *v32;
  v33 = CDmxElement::GetAttribute(this: v2, pAttributeName: "invertSelection");
  if ( v33 != nullptr )
  {
    if ( v33->m_Type == AT_BOOL )
    {
      v3->m_bInvertSelection = *(_BYTE *)v33->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<bool>'::`4'::defaultValue = 0;
      v3->m_bInvertSelection = false;
    }
    return 1;
  }
  else
  {
    `CDmxElement::GetValue<bool>'::`4'::defaultValue = 0;
    v3->m_bInvertSelection = false;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ACEC0
// Name: public: virtual void CSelectedHSVUIPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectedHSVUIPanel::OnCommand(CSelectedHSVUIPanel *this, const char *command)
{
  float v3; // xmm0_4
  float commanda; // [esp+10h] [ebp+8h]

  vgui::Frame::OnCommand(this, command);
  if ( _V_stricmp(s1: "BlendFactorUpdate", s2: command) != 0 )
  {
    if ( _V_stricmp(s1: "ToggleSelection", s2: command) != 0 )
    {
      if ( _V_stricmp(s1: "PickRGB", s2: command) != 0 )
      {
        if ( _V_stricmp(s1: "PickHSV", s2: command) == 0 )
          CSelectedHSVUIPanel::PickColorFromTextEntry(this, bRGB: false);
      }
      else
      {
        CSelectedHSVUIPanel::PickColorFromTextEntry(this, bRGB: true);
      }
    }
    else
    {
      CSelectedHSVUIPanel::EnableSelectionMode(this, bEnable: !this->m_bSelectionEnable);
    }
  }
  else
  {
    if ( this->m_pHSVOperation != nullptr )
    {
      commanda = this->m_pHSVOperation->GetBlendFactor(this: this->m_pHSVOperation);
      v3 = commanda;
    }
    else
    {
      v3 = 0.0;
    }
    this->m_pBlendFactorSlider->SetValue(this: this->m_pBlendFactorSlider, a2: (int)(float)(v3 * 255.0), a3: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ACFA0
// Name: public: virtual bool CColorBalanceOperation::Unserialize(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CColorBalanceOperation::Unserialize(CColorBalanceOperation *this, CDmxElement *pElement)
{
  const char *Name; // eax
  const CDmxAttribute *Attribute; // eax
  int *m_pData; // eax
  const CDmxAttribute *v7; // eax
  char *v8; // eax
  const CDmxAttribute *v9; // eax
  char *v10; // eax
  const CUtlVector<float,CUtlMemory<float,int> > *v11; // ebx
  const CUtlVector<float,CUtlMemory<float,int> > *v12; // eax
  int m_Size; // ecx
  const CUtlVector<float,CUtlMemory<float,int> > *magentaGreenBalance; // [esp+14h] [ebp+8h]

  Name = CDmxElement::GetName(this: pElement);
  V_strncpy(pDest: this->m_pName, pSrc: Name, maxLen: 256);
  Attribute = CDmxElement::GetAttribute(this: pElement, pAttributeName: "blendFactor");
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
  this->m_flBlendFactor = *(float *)m_pData;
  v7 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "enabled");
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
  this->m_bEnable = *v8;
  v9 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "preserveLuminosity");
  if ( v9 != nullptr )
  {
    if ( v9->m_Type == AT_BOOL )
    {
      v10 = (char *)v9->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<bool>'::`4'::defaultValue = 0;
      v10 = &`CDmxAttribute::GetValue<bool>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<bool>'::`4'::defaultValue = 0;
    v10 = &`CDmxElement::GetValue<bool>'::`4'::defaultValue;
  }
  this->m_PreserveLuminosity = *v10;
  v11 = CDmxElement::GetArray<float>(this: pElement, pAttributeName: "cyanRedBalance");
  magentaGreenBalance = CDmxElement::GetArray<float>(this: pElement, pAttributeName: "magentaGreenBalance");
  v12 = CDmxElement::GetArray<float>(this: pElement, pAttributeName: "yellowBlueBalance");
  m_Size = v11->m_Size;
  if ( magentaGreenBalance->m_Size != m_Size || v12->m_Size != m_Size || m_Size != 3 )
    return 0;
  this->m_CyanRedBalance[0] = *v11->m_Memory.m_pMemory;
  this->m_MagentaGreenBalance[0] = *magentaGreenBalance->m_Memory.m_pMemory;
  this->m_YellowBlueBalance[0] = *v12->m_Memory.m_pMemory;
  this->m_CyanRedBalance[1] = v11->m_Memory.m_pMemory[1];
  this->m_MagentaGreenBalance[1] = magentaGreenBalance->m_Memory.m_pMemory[1];
  this->m_YellowBlueBalance[1] = v12->m_Memory.m_pMemory[1];
  this->m_CyanRedBalance[2] = v11->m_Memory.m_pMemory[2];
  this->m_MagentaGreenBalance[2] = magentaGreenBalance->m_Memory.m_pMemory[2];
  this->m_YellowBlueBalance[2] = v12->m_Memory.m_pMemory[2];
  CColorBalanceOperation::CreateLookupTables(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100AD120
// Name: private: bool CColorOperationListPanel::LoadVCCFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CColorOperationListPanel::LoadVCCFile(CColorOperationListPanel *this, const char *pFullPath)
{
  CDmxAttribute *Attribute; // eax
  const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *v4; // eax
  int m_Size; // ecx
  CDmxElement *v6; // ebx
  ColorCorrectionTool_t j; // edi
  const char *TypeString; // eax
  CCurvesColorOperation *ColorOp; // edi
  int v10; // eax
  int v11; // esi
  IColorOperation **m_pMemory; // ebx
  int v13; // eax
  CCurvesColorOperation **v14; // esi
  CUtlMemory<S3RGBA,int> *v15; // esi
  int k; // edi
  S3RGBA v17; // ecx
  int v18; // edi
  int v19; // ecx
  int v20; // ecx
  int m; // ebx
  S3RGBA *v22; // edi
  int m_nAllocationCount; // eax
  S3RGBA *v24; // ecx
  int v25; // eax
  IColorOperation **v26; // edi
  const char *v27; // [esp-Ch] [ebp-38h]
  const char *Name; // [esp-Ch] [ebp-38h]
  CUtlVector<IColorOperation *,CUtlMemory<IColorOperation *,int> > loadedOps; // [esp+4h] [ebp-28h] BYREF
  const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *operators; // [esp+18h] [ebp-14h]
  CDmxElement *pColorOperaterList; // [esp+1Ch] [ebp-10h] BYREF
  int nCount; // [esp+20h] [ebp-Ch]
  CColorOperationListPanel *v33; // [esp+24h] [ebp-8h]
  int i; // [esp+28h] [ebp-4h]
  int bOk; // [esp+34h] [ebp+8h]
  IColorOperation *bOka; // [esp+34h] [ebp+8h]
  char bOk_3; // [esp+37h] [ebp+Bh]

  v33 = this;
  BeginDMXContext();
  if ( UnserializeDMX(pFileName: pFullPath, pPathID: "GAME", bTextMode: true, ppRoot: &pColorOperaterList) )
  {
    Attribute = (CDmxAttribute *)CDmxElement::GetAttribute(this: pColorOperaterList, pAttributeName: "operators");
    if ( Attribute != nullptr )
    {
      v4 = CDmxAttribute::GetArray<CDmxElement *>(this: Attribute);
      m_Size = v4->m_Size;
      operators = v4;
      bOk_3 = 1;
      memset(&loadedOps, 0, sizeof(loadedOps));
      nCount = m_Size;
      i = 0;
      if ( m_Size > 0 )
      {
        while ( 1 )
        {
          v6 = v4->m_Memory.m_pMemory[i];
          for ( j = CC_TOOL_NONE; j < CC_TOOL_COUNT; ++j )
          {
            TypeString = CDmxElement::GetTypeString(this: v6);
            if ( _V_stricmp(s1: s_pColorCorrectionDmxElementNames[j], s2: TypeString) == 0 )
              break;
          }
          if ( j == CC_TOOL_COUNT )
          {
            v27 = CDmxElement::GetTypeString(this: v6);
            _Warning(a1: "Unknown color correction operator %s\n", v27);
            goto LABEL_23;
          }
          ColorOp = CreateColorOp(nToolId: j, pOpList: &v33->m_OperationList);
          if ( !ColorOp->Unserialize(this: ColorOp, a2: v6) )
            break;
          v10 = loadedOps.m_Size;
          v11 = loadedOps.m_Size;
          if ( loadedOps.m_Size + 1 > loadedOps.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<INetMessage *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)&loadedOps,
              num: loadedOps.m_Size - loadedOps.m_Memory.m_nAllocationCount + 1);
            v10 = loadedOps.m_Size;
          }
          m_pMemory = loadedOps.m_Memory.m_pMemory;
          loadedOps.m_Size = v10 + 1;
          v13 = v10 - v11;
          loadedOps.m_pElements = loadedOps.m_Memory.m_pMemory;
          if ( v13 > 0 )
            _V_memmove(
              dest: &loadedOps.m_Memory.m_pMemory[v11 + 1],
              src: &loadedOps.m_Memory.m_pMemory[v11],
              count: 4 * v13);
          v14 = (CCurvesColorOperation **)&m_pMemory[v11];
          if ( v14 != nullptr )
            *v14 = ColorOp;
          if ( ++i >= nCount )
            goto LABEL_24;
          v4 = operators;
        }
        Name = CDmxElement::GetName(this: v6);
        _Warning(a1: "Error unserializing color correction operator %s\n", Name);
LABEL_23:
        bOk_3 = 0;
      }
LABEL_24:
      EndDMXContext(bDecommitMemory: true);
      if ( bOk_3 != 0 )
      {
        v15 = (CUtlMemory<S3RGBA,int> *)v33;
        for ( k = v33->m_OperationList.m_OpList.m_Size - 1; k >= 0; --k )
        {
          v17 = v15[37].m_pMemory[k];
          (*(void (__thiscall **)(S3RGBA))(**(_DWORD **)&v17 + 4))(a1: v17);
        }
        v18 = 0;
        v15[38].m_pMemory = nullptr;
        bOk = v15[40].m_nAllocationCount;
        if ( bOk > 0 )
        {
          do
          {
            v19 = *(_DWORD *)(v15[39].m_nAllocationCount + 4 * v18);
            (*(void (__thiscall **)(int))(*(_DWORD *)v19 + 1120))(a1: v19);
            v20 = *(_DWORD *)(v15[39].m_nAllocationCount + 4 * v18);
            if ( v20 != 0 )
              (*(void (__thiscall **)(int, int))(*(_DWORD *)v20 + 128))(a1: v20, a2: 1);
            ++v18;
          }
          while ( v18 < bOk );
        }
        v15[40].m_nAllocationCount = 0;
        for ( m = 0; m < nCount; ++m )
        {
          v22 = v15[38].m_pMemory;
          m_nAllocationCount = v15[37].m_nAllocationCount;
          bOka = loadedOps.m_Memory.m_pMemory[m];
          if ( (int)&v22->g > m_nAllocationCount )
            CUtlMemory<INetMessage *,int>::Grow(this: v15 + 37, num: (int)(&v22->g - m_nAllocationCount));
          ++v15[38].m_pMemory;
          v24 = v15[37].m_pMemory;
          v25 = (char *)v15[38].m_pMemory - (char *)v22 - 1;
          v15[38].m_nAllocationCount = (int)v24;
          if ( v25 > 0 )
            _V_memmove(dest: &v24[(_DWORD)v22 + 1], src: &v24[(_DWORD)v22], count: 4 * v25);
          v26 = (IColorOperation **)&v15[37].m_pMemory[(_DWORD)v22];
          if ( v26 != nullptr )
            *v26 = bOka;
        }
        if ( loadedOps.m_Memory.m_nGrowSize >= 0 && loadedOps.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: loadedOps.m_Memory.m_pMemory);
        return 1;
      }
      else
      {
        if ( loadedOps.m_Memory.m_nGrowSize >= 0 && loadedOps.m_Memory.m_pMemory != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: loadedOps.m_Memory.m_pMemory);
        return 0;
      }
    }
    else
    {
      _Warning(a1: "File %s !\n", pFullPath);
      EndDMXContext(bDecommitMemory: true);
      return 0;
    }
  }
  else
  {
    _Warning(a1: "Error loading file %s!\n", pFullPath);
    EndDMXContext(bDecommitMemory: true);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AD520
// Name: public: virtual void CCurvesColorOperation::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCurvesColorOperation::Release(CCurvesColorOperation *this)
{
  if ( this != nullptr )
  {
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_ControlPoints);
    free(pMem: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AD540
// Name: public: virtual class IColorOperation __near * CSelectedHSVOperation::Clone(void)
// Source: json
//------------------------------------------------------------------------------
CSelectedHSVOperation *__thiscall CSelectedHSVOperation::Clone(CSelectedHSVOperation *this)
{
  CSelectedHSVOperation *v2; // eax
  CSelectedHSVOperation *v3; // esi

  v2 = (CSelectedHSVOperation *)MemAlloc_Alloc(nSize: 0x154u);
  if ( v2 != nullptr )
    v3 = CSelectedHSVOperation::CSelectedHSVOperation(this: v2, pList: this->m_pOpList);
  else
    v3 = nullptr;
  CUtlVector<Vector,CUtlMemory<Vector,int>>::operator=(this: &v3->m_SelectedRGBs, other: &this->m_SelectedRGBs);
  CUtlVector<Vector,CUtlMemory<Vector,int>>::operator=(this: &v3->m_SelectedHSVs, other: &this->m_SelectedHSVs);
  v3->m_SelectionMethod = this->m_SelectionMethod;
  v3->m_DeltaHSV.x = this->m_DeltaHSV.x;
  v3->m_DeltaHSV.y = this->m_DeltaHSV.y;
  v3->m_DeltaHSV.z = this->m_DeltaHSV.z;
  v3->m_Tolerance = this->m_Tolerance;
  v3->m_Fuzziness = this->m_Fuzziness;
  v3->m_bColorize = this->m_bColorize;
  v3->m_bInvertSelection = this->m_bInvertSelection;
  v3->m_flBlendFactor = this->m_flBlendFactor;
  v3->m_bEnable = this->m_bEnable;
  v3->m_pOpList = this->m_pOpList;
  _V_memcpy(dest: v3->m_pName, src: this->m_pName, count: 256);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100AD5E0
// Name: public: virtual bool CColorOperationListPanel::OnReadFileFromDisk(char const __near *,char const __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CColorOperationListPanel::OnReadFileFromDisk(
        CColorOperationListPanel *this,
        const char *pFileName,
        const char *pFileFormat,
        KeyValues *pContextKeyValues)
{
  char VCCFile; // bl

  VCCFile = CColorOperationListPanel::LoadVCCFile(
              this: (CColorOperationListPanel *)((char *)this - 380),
              pFullPath: pFileName);
  if ( VCCFile != 0 )
  {
    CUtlString::operator=(this: (CUtlString *)&this->_actionSignalTargetDar.m_Size, src: pFileName);
    CColorOperationListPanel::PopulateList(this: (CColorOperationListPanel *)((char *)this - 380));
    colorcorrectiontools->UpdateColorCorrection(this: colorcorrectiontools);
  }
  return VCCFile;
}

//------------------------------------------------------------------------------
// Address: 0x100AD630
// Name: public: virtual class IColorOperation __near * CCurvesColorOperation::Clone(void)
// Source: json
//------------------------------------------------------------------------------
CCurvesColorOperation *__thiscall CCurvesColorOperation::Clone(CCurvesColorOperation *this)
{
  CCurvesColorOperation *v2; // eax
  CCurvesColorOperation *v3; // esi

  v2 = (CCurvesColorOperation *)MemAlloc_Alloc(nSize: 0x52Cu);
  if ( v2 != nullptr )
    v3 = CCurvesColorOperation::CCurvesColorOperation(this: v2);
  else
    v3 = nullptr;
  _V_memcpy(dest: v3->m_pOutValue, src: this->m_pOutValue, count: 1024);
  v3->m_nChannelMask = this->m_nChannelMask;
  CUtlVector<Vector,CUtlMemory<Vector,int>>::operator=(this: &v3->m_ControlPoints, other: &this->m_ControlPoints);
  v3->m_ControlPoints.m_pLessContext = this->m_ControlPoints.m_pLessContext;
  v3->m_ControlPoints.m_bNeedsSort = this->m_ControlPoints.m_bNeedsSort;
  v3->m_flBlendFactor = this->m_flBlendFactor;
  _V_memcpy(dest: v3->m_pName, src: this->m_pName, count: 256);
  v3->m_bEnable = this->m_bEnable;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101A6BE0
// Name: public: virtual void CColorBalanceUIPanel::ReadUncorrectedImage(struct Rect_t __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorBalanceUIPanel::ReadUncorrectedImage(vgui::TreeView *this, int itemIndex, KeyValues *msg)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10248F00
// Name: public: class CUtlString const __near & CDmxElement::GetValue<class CUtlString>(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CUtlString *__thiscall CDmxElement::GetValue<CUtlString>(CDmxElement *this, const char *pAttributeName)
{
  int v3; // edi
  CDmxAttribute *v4; // eax
  CDmxAttribute v6; // [esp+8h] [ebp-Ch] BYREF

  CDmxElement::Resort(this);
  CDmxAttribute::CDmxAttribute(this: &v6, pAttributeName);
  pAttributeName = (const char *)&v6;
  v3 = CUtlSortVector<CDmxAttribute *,CDmxAttributeLess>::Find(
         this: &this->m_Attributes,
         src: (CDmxAttribute *const **)&pAttributeName);
  CDmxAttribute::~CDmxAttribute(this: &v6);
  if ( v3 >= 0 && (v4 = this->m_Attributes.m_Memory.m_pMemory[v3]) != nullptr )
  {
    if ( v4->m_Type == AT_STRING )
    {
      return (const CUtlString *)v4->m_pData;
    }
    else
    {
      if ( (`CDmxAttribute::GetValue<CUtlString>'::`4'::`local static guard' & 1) == 0 )
      {
        `CDmxAttribute::GetValue<CUtlString>'::`4'::`local static guard' |= 1u;
        CUtlString::CUtlString(this: &`CDmxAttribute::GetValue<CUtlString>'::`4'::defaultValue);
        atexit(func: `CDmxAttribute::GetValue<CUtlString>'::`4'::`dynamic atexit destructor for 'defaultValue'');
      }
      CUtlString::Set(this: &`CDmxAttribute::GetValue<CUtlString>'::`4'::defaultValue, pValue: nullptr);
      return &`CDmxAttribute::GetValue<CUtlString>'::`4'::defaultValue;
    }
  }
  else
  {
    if ( (`CDmxElement::GetValue<CUtlString>'::`4'::`local static guard' & 1) == 0 )
    {
      `CDmxElement::GetValue<CUtlString>'::`4'::`local static guard' |= 1u;
      CUtlString::CUtlString(this: &`CDmxElement::GetValue<CUtlString>'::`4'::defaultValue);
      atexit(func: `CDmxElement::GetValue<CUtlString>'::`4'::`dynamic atexit destructor for 'defaultValue'');
    }
    CUtlString::Set(this: &`CDmxElement::GetValue<CUtlString>'::`4'::defaultValue, pValue: nullptr);
    return &`CDmxElement::GetValue<CUtlString>'::`4'::defaultValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102493E0
// Name: private: void CDmxAttribute::SerializeType<class DmeTime_t,class DmeTime_t>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<DmeTime_t,DmeTime_t>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  bool v3; // al
  DmeTime_t temp; // [esp+0h] [ebp-4h] BYREF

  temp.m_tms = (int)this;
  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (const DmeTime_t *)this->m_pData);
  }
  else
  {
    temp.m_tms = 0;
    v3 = Serialize(buf, src: &temp);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x10249450
// Name: private: void CDmxAttribute::SerializeType<class Vector2D,class Vector2D>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<Vector2D,Vector2D>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  bool v3; // al
  Vector2D temp; // [esp+0h] [ebp-8h] BYREF

  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (const Vector2D *)this->m_pData);
  }
  else
  {
    temp.x = 0.0;
    temp.y = 0.0;
    v3 = Serialize(buf, src: &temp);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x10249490
// Name: private: void CDmxAttribute::SerializeType<class Vector4D,class Vector4D>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<Vector4D,Vector4D>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  bool v3; // al
  Vector4D temp; // [esp+0h] [ebp-10h] BYREF

  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (const Quaternion *)this->m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    v3 = Serialize(buf, src: (const Quaternion *)&temp);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x102494E0
// Name: private: void CDmxAttribute::SerializeType<class Vector,class Vector>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<Vector,Vector>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  bool v3; // al
  QAngle temp; // [esp+0h] [ebp-Ch] BYREF

  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (const QAngle *)this->m_pData);
  }
  else
  {
    memset((void *)&temp, 0, sizeof(temp));
    v3 = Serialize(buf, src: &temp);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x10249520
// Name: private: void CDmxAttribute::SerializeType<class Quaternion,class Quaternion>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<Quaternion,Quaternion>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v3; // al
  Quaternion temp; // [esp+0h] [ebp-10h] BYREF

  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (const Quaternion *)this->m_pData);
  }
  else
  {
    memset(&temp, 0, 12);
    temp.w = 1.0;
    v3 = Serialize(buf, src: &temp);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x10249570
// Name: private: void CDmxAttribute::SerializeType<class VMatrix,class VMatrix>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<VMatrix,VMatrix>(CDmxAttribute *this, bool *bSuccess, CUtlBuffer *buf)
{
  bool v3; // al
  VMatrix temp; // [esp+0h] [ebp-40h] BYREF

  if ( this->m_pData != nullptr )
  {
    v3 = Serialize(buf, src: (const VMatrix *)this->m_pData);
  }
  else
  {
    MatrixSetIdentity(dst: &temp);
    v3 = Serialize(buf, src: &temp);
  }
  *bSuccess = v3;
}

//------------------------------------------------------------------------------
// Address: 0x102496B0
// Name: private: void CDmxAttribute::SerializeTypedElement<class CUtlVector<int,class CUtlMemory<int,int>>,int>(bool __near &,int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeTypedElement<CUtlVector<int,CUtlMemory<int,int>>,int>(
        CDmxAttribute *this,
        bool *bSuccess,
        int nIndex,
        CUtlBuffer *buf)
{
  _DWORD *m_pData; // eax
  bool v5; // al

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    v5 = Serialize(buf, src: (const int *)(*m_pData + 4 * nIndex));
  }
  else
  {
    nIndex = 0;
    v5 = Serialize(buf, src: &nIndex);
  }
  *bSuccess = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10249700
// Name: private: void CDmxAttribute::SerializeTypedElement<class CUtlVector<float,class CUtlMemory<float,int>>,float>(bool __near &,int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeTypedElement<CUtlVector<float,CUtlMemory<float,int>>,float>(
        CDmxAttribute *this,
        bool *bSuccess,
        int nIndex,
        CUtlBuffer *buf)
{
  _DWORD *m_pData; // eax
  bool v5; // al

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    v5 = Serialize(buf, src: (const float *)(*m_pData + 4 * nIndex));
  }
  else
  {
    nIndex = 0;
    v5 = Serialize(buf, src: (const float *)&nIndex);
  }
  *bSuccess = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10249750
// Name: private: void CDmxAttribute::SerializeTypedElement<class CUtlVector<bool,class CUtlMemory<bool,int>>,bool>(bool __near &,int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeTypedElement<CUtlVector<bool,CUtlMemory<bool,int>>,bool>(
        CDmxAttribute *this,
        bool *bSuccess,
        int nIndex,
        CUtlBuffer *buf)
{
  _DWORD *m_pData; // eax
  bool v5; // al

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    v5 = Serialize(buf, src: (const bool *)(nIndex + *m_pData));
  }
  else
  {
    HIBYTE(nIndex) = 0;
    v5 = Serialize(buf, src: (const bool *)&nIndex + 3);
  }
  *bSuccess = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10249780
// Name: private: void CDmxAttribute::SerializeTypedElement<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>,class DmeTime_t>(bool __near &,int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeTypedElement<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(
        CDmxAttribute *this,
        bool *bSuccess,
        DmeTime_t nIndex,
        CUtlBuffer *buf)
{
  _DWORD *m_pData; // eax
  bool v5; // al

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    v5 = Serialize(buf, src: (const DmeTime_t *)(*m_pData + 4 * nIndex.m_tms));
  }
  else
  {
    nIndex.m_tms = 0;
    v5 = Serialize(buf, src: &nIndex);
  }
  *bSuccess = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10249820
// Name: private: void CDmxAttribute::SerializeTypedElement<class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>,class Vector2D>(bool __near &,int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeTypedElement<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(
        CDmxAttribute *this,
        bool *bSuccess,
        int nIndex,
        CUtlBuffer *buf)
{
  _DWORD *m_pData; // eax
  bool v5; // al
  Vector2D temp; // [esp+0h] [ebp-8h] BYREF

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    v5 = Serialize(buf, src: (const Vector2D *)(*m_pData + 8 * nIndex));
  }
  else
  {
    temp.x = 0.0;
    temp.y = 0.0;
    v5 = Serialize(buf, src: &temp);
  }
  *bSuccess = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10249880
// Name: private: void CDmxAttribute::SerializeTypedElement<class CUtlVector<class QAngle,class CUtlMemory<class QAngle,int>>,class QAngle>(bool __near &,int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeTypedElement<CUtlVector<QAngle,CUtlMemory<QAngle,int>>,QAngle>(
        CDmxAttribute *this,
        bool *bSuccess,
        int nIndex,
        CUtlBuffer *buf)
{
  _DWORD *m_pData; // ecx
  bool v5; // al
  QAngle temp; // [esp+0h] [ebp-Ch] BYREF

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    v5 = Serialize(buf, src: (const QAngle *)(*m_pData + 12 * nIndex));
  }
  else
  {
    memset((void *)&temp, 0, sizeof(temp));
    v5 = Serialize(buf, src: &temp);
  }
  *bSuccess = v5;
}

//------------------------------------------------------------------------------
// Address: 0x102498E0
// Name: private: void CDmxAttribute::SerializeTypedElement<class CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>,class Vector4D>(bool __near &,int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeTypedElement<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>,Vector4D>(
        CDmxAttribute *this,
        bool *bSuccess,
        int nIndex,
        CUtlBuffer *buf)
{
  _DWORD *m_pData; // ecx
  bool v5; // al
  Vector4D temp; // [esp+0h] [ebp-10h] BYREF

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    v5 = Serialize(buf, src: (const Quaternion *)(*m_pData + 16 * nIndex));
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    v5 = Serialize(buf, src: (const Quaternion *)&temp);
  }
  *bSuccess = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10249930
// Name: private: void CDmxAttribute::SerializeTypedElement<class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>,class Quaternion>(bool __near &,int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeTypedElement<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(
        CDmxAttribute *this,
        bool *bSuccess,
        int nIndex,
        CUtlBuffer *buf)
{
  _DWORD *m_pData; // ecx
  bool v5; // al
  Quaternion temp; // [esp+0h] [ebp-10h] BYREF

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    v5 = Serialize(buf, src: (const Quaternion *)(*m_pData + 16 * nIndex));
  }
  else
  {
    memset(&temp, 0, 12);
    temp.w = 1.0;
    v5 = Serialize(buf, src: &temp);
  }
  *bSuccess = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10249990
// Name: private: void CDmxAttribute::SerializeTypedElement<class CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>,class VMatrix>(bool __near &,int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeTypedElement<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(
        CDmxAttribute *this,
        bool *bSuccess,
        int nIndex,
        CUtlBuffer *buf)
{
  _DWORD *m_pData; // ecx
  bool v5; // al
  VMatrix temp; // [esp+0h] [ebp-40h] BYREF

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    v5 = Serialize(buf, src: (const VMatrix *)(*m_pData + (nIndex << 6)));
  }
  else
  {
    MatrixSetIdentity(dst: &temp);
    v5 = Serialize(buf, src: &temp);
  }
  *bSuccess = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10249C40
// Name: private: void CDmxAttribute::SerializeType<class CUtlBinaryBlock,class CUtlBinaryBlock>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlBinaryBlock,CUtlBinaryBlock>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v3; // al
  bool v4; // sf
  CUtlBinaryBlock temp; // [esp+0h] [ebp-10h] BYREF

  if ( this->m_pData != nullptr )
  {
    *bSuccess = Serialize(buf, src: (const CUtlBinaryBlock *)this->m_pData);
  }
  else
  {
    CUtlBinaryBlock::CUtlBinaryBlock(this: &temp, growSize: 0, initSize: 0);
    CUtlBinaryBlock::Set(this: &temp, pValue: nullptr, nLen: 0);
    v3 = Serialize(buf, src: &temp);
    v4 = temp.m_Memory.m_nGrowSize < 0;
    *bSuccess = v3;
    temp.m_nActualLength = 0;
    if ( !v4 && temp.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: temp.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10249CC0
// Name: private: void CDmxAttribute::SerializeTypedElement<class CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>,class CUtlBinaryBlock>(bool __near &,int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeTypedElement<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        CDmxAttribute *this,
        bool *bSuccess,
        int nIndex,
        CUtlBuffer *buf)
{
  _DWORD *m_pData; // ecx
  bool v5; // al
  bool v6; // sf
  CUtlBinaryBlock temp; // [esp+0h] [ebp-10h] BYREF

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize(buf, src: (const CUtlBinaryBlock *)(*m_pData + 16 * nIndex));
  }
  else
  {
    CUtlBinaryBlock::CUtlBinaryBlock(this: &temp, growSize: 0, initSize: 0);
    CUtlBinaryBlock::Set(this: &temp, pValue: nullptr, nLen: 0);
    v5 = Serialize(buf, src: &temp);
    v6 = temp.m_Memory.m_nGrowSize < 0;
    *bSuccess = v5;
    temp.m_nActualLength = 0;
    if ( !v6 && temp.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: temp.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10249F20
// Name: private: void CDmxAttribute::ConstructDataMemory<class CUtlVector<class Color,class CUtlMemory<class Color,int>>,class Color>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::ConstructDataMemory<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(CDmxAttribute *this)
{
  _DWORD *m_pData; // eax

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    *m_pData = 0;
    m_pData[1] = 0;
    m_pData[2] = 0;
    m_pData[3] = 0;
    m_pData[4] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10249F40
// Name: private: void CDmxAttribute::SerializeType<class CUtlString,class CUtlString>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlString,CUtlString>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v3; // al
  bool v4; // sf
  CUtlString temp; // [esp+0h] [ebp-10h] BYREF

  if ( this->m_pData != nullptr )
  {
    *bSuccess = Serialize(buf, src: (const CUtlString *)this->m_pData);
  }
  else
  {
    CUtlString::CUtlString(this: &temp);
    CUtlString::Set(this: &temp, pValue: nullptr);
    v3 = Serialize(buf, src: &temp);
    v4 = temp.m_Storage.m_Memory.m_nGrowSize < 0;
    *bSuccess = v3;
    temp.m_Storage.m_nActualLength = 0;
    if ( !v4 && temp.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: temp.m_Storage.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10249FC0
// Name: private: void CDmxAttribute::SerializeTypedElement<class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>,class CUtlString>(bool __near &,int,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeTypedElement<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(
        CDmxAttribute *this,
        bool *bSuccess,
        int nIndex,
        CUtlBuffer *buf)
{
  _DWORD *m_pData; // ecx
  bool v5; // al
  bool v6; // sf
  CUtlString temp; // [esp+0h] [ebp-10h] BYREF

  m_pData = this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize(buf, src: (const CUtlString *)(*m_pData + 16 * nIndex));
  }
  else
  {
    CUtlString::CUtlString(this: &temp);
    CUtlString::Set(this: &temp, pValue: nullptr);
    v5 = Serialize(buf, src: &temp);
    v6 = temp.m_Storage.m_Memory.m_nGrowSize < 0;
    *bSuccess = v5;
    temp.m_Storage.m_nActualLength = 0;
    if ( !v6 && temp.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: temp.m_Storage.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024ABF0
// Name: private: void CDmxAttribute::DestructDataMemory<class CUtlBinaryBlock,class CUtlBinaryBlock>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::DestructDataMemory<CUtlBinaryBlock,CUtlBinaryBlock>(CDmxAttribute *this)
{
  int *m_pData; // esi
  bool v2; // sf

  m_pData = (int *)this->m_pData;
  v2 = m_pData[2] < 0;
  m_pData[3] = 0;
  if ( !v2 )
  {
    if ( *m_pData != 0 )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)*m_pData);
      *m_pData = 0;
    }
    m_pData[1] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024AC30
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<int,class CUtlMemory<int,int>>,int>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<int,CUtlMemory<int,int>>,int>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<int,CUtlMemory<int,int> > *m_pData; // eax
  CUtlVector<int,CUtlMemory<int,int> > temp; // [esp+0h] [ebp-14h] BYREF

  m_pData = (const CUtlVector<int,CUtlMemory<int,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<int>(buf, src: m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    *bSuccess = Serialize<int>(buf, src: &temp);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&temp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024AC90
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<float,class CUtlMemory<float,int>>,float>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<float,CUtlMemory<float,int>>,float>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<float,CUtlMemory<float,int> > *m_pData; // eax
  CUtlVector<float,CUtlMemory<float,int> > temp; // [esp+0h] [ebp-14h] BYREF

  m_pData = (const CUtlVector<float,CUtlMemory<float,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<float>(buf, src: m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    *bSuccess = Serialize<float>(buf, src: &temp);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&temp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024ACF0
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<bool,class CUtlMemory<bool,int>>,bool>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<bool,CUtlMemory<bool,int>>,bool>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<bool,CUtlMemory<bool,int> > *m_pData; // eax
  CUtlVector<bool,CUtlMemory<bool,int> > temp; // [esp+0h] [ebp-14h] BYREF

  m_pData = (const CUtlVector<bool,CUtlMemory<bool,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<bool>(buf, src: m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    *bSuccess = Serialize<bool>(buf, src: &temp);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&temp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024AD50
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>,class DmeTime_t>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *m_pData; // eax
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > temp; // [esp+0h] [ebp-14h] BYREF

  m_pData = (const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<DmeTime_t>(buf, src: m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    *bSuccess = Serialize<DmeTime_t>(buf, src: &temp);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&temp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024ADB0
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<class Color,class CUtlMemory<class Color,int>>,class Color>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<Color,CUtlMemory<Color,int> > *m_pData; // eax
  CUtlVector<Color,CUtlMemory<Color,int> > temp; // [esp+0h] [ebp-14h] BYREF

  m_pData = (const CUtlVector<Color,CUtlMemory<Color,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<Color>(buf, src: m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    *bSuccess = Serialize<Color>(buf, src: &temp);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&temp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024AE10
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>,class Vector2D>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *m_pData; // eax
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > temp; // [esp+0h] [ebp-14h] BYREF

  m_pData = (const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<Vector2D>(buf, src: m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    *bSuccess = Serialize<Vector2D>(buf, src: &temp);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&temp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024AE70
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<class Vector,class CUtlMemory<class Vector,int>>,class Vector>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<Vector,CUtlMemory<Vector,int>>,Vector>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<QAngle,CUtlMemory<QAngle,int> > *m_pData; // eax
  CUtlVector<QAngle,CUtlMemory<QAngle,int> > temp; // [esp+0h] [ebp-14h] BYREF

  m_pData = (const CUtlVector<QAngle,CUtlMemory<QAngle,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<Vector>(buf, src: m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    *bSuccess = Serialize<Vector>(buf, src: &temp);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&temp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024AED0
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>,class Quaternion>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *m_pData; // eax
  CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > temp; // [esp+0h] [ebp-14h] BYREF

  m_pData = (const CUtlVector<Quaternion,CUtlMemory<Quaternion,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<Quaternion>(buf, src: m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    *bSuccess = Serialize<Quaternion>(buf, src: &temp);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&temp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024AF30
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>,class VMatrix>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *m_pData; // eax
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > temp; // [esp+0h] [ebp-14h] BYREF

  m_pData = (const CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<VMatrix>(buf, src: m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    *bSuccess = Serialize<VMatrix>(buf, src: &temp);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&temp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024AF90
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<int,class CUtlMemory<int,int>>,int>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<int,CUtlMemory<int,int>>,int>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlMemory<S3RGBA,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  S3RGBA *m_pMemory; // edi
  S3RGBA *v8; // ecx
  int v9; // eax
  S3RGBA *v10; // eax

  v4 = Unserialize(buf, dest: (int *)&buf);
  *bSuccess = v4;
  if ( v4 )
  {
    m_pData = (CUtlMemory<S3RGBA,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)&m_pMemory->g > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(this: m_pData, num: (int)(&m_pMemory->g - m_nAllocationCount));
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = (char *)m_pData[1].m_pMemory - (char *)m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[(_DWORD)m_pMemory + 1], src: &v8[(_DWORD)m_pMemory], count: 4 * v9);
    v10 = &m_pData->m_pMemory[(_DWORD)m_pMemory];
    if ( v10 != nullptr )
      *v10 = (S3RGBA)buf;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024B090
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<bool,class CUtlMemory<bool,int>>,bool>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<bool,CUtlMemory<bool,int>>,bool>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlMemory<char,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  char *m_pMemory; // edi
  char *v8; // ecx
  int v9; // eax
  char *v10; // esi

  v4 = Unserialize(buf, dest: (bool *)&buf + 3);
  *bSuccess = v4;
  if ( v4 )
  {
    m_pData = (CUtlMemory<char,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)(m_pMemory + 1) > m_nAllocationCount )
      CUtlMemory<bool,int>::Grow(this: m_pData, num: (int)&m_pMemory[-m_nAllocationCount + 1]);
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = m_pData[1].m_pMemory - m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[(_DWORD)m_pMemory + 1], src: &v8[(_DWORD)m_pMemory], count: v9);
    v10 = &m_pMemory[(unsigned int)m_pData->m_pMemory];
    if ( v10 != nullptr )
      *v10 = HIBYTE(buf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024B100
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>,class CUtlString>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlString temp; // [esp+4h] [ebp-10h] BYREF

  CUtlString::CUtlString(this: &temp);
  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
      this: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
  temp.m_Storage.m_nActualLength = 0;
  if ( temp.m_Storage.m_Memory.m_nGrowSize >= 0 && temp.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: temp.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1024B170
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>,class CUtlBinaryBlock>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlBinaryBlock temp; // [esp+4h] [ebp-10h] BYREF

  CUtlBinaryBlock::CUtlBinaryBlock(this: &temp, growSize: 0, initSize: 0);
  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::InsertBefore(
      this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
  temp.m_nActualLength = 0;
  if ( temp.m_Memory.m_nGrowSize >= 0 && temp.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: temp.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1024B1E0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class DmeTime_t,class CUtlMemory<class DmeTime_t,int>>,class DmeTime_t>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int>>,DmeTime_t>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlMemory<S3RGBA,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  S3RGBA *m_pMemory; // edi
  S3RGBA *v8; // ecx
  int v9; // eax
  DmeTime_t *v10; // eax
  DmeTime_t temp; // [esp+4h] [ebp-4h] BYREF

  temp.m_tms = 0x80000000;
  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
  {
    m_pData = (CUtlMemory<S3RGBA,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)&m_pMemory->g > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(this: m_pData, num: (int)(&m_pMemory->g - m_nAllocationCount));
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = (char *)m_pData[1].m_pMemory - (char *)m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[(_DWORD)m_pMemory + 1], src: &v8[(_DWORD)m_pMemory], count: 4 * v9);
    v10 = (DmeTime_t *)&m_pData->m_pMemory[(_DWORD)m_pMemory];
    if ( v10 != nullptr )
      v10->m_tms = temp.m_tms;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024B270
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Color,class CUtlMemory<class Color,int>>,class Color>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Color,CUtlMemory<Color,int>>,Color>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  CUtlMemory<S3RGBA,int> *m_pData; // esi
  int m_nAllocationCount; // eax
  S3RGBA *m_pMemory; // edi
  S3RGBA *v8; // ecx
  int v9; // eax
  Color *v10; // eax
  Color temp; // [esp+4h] [ebp-4h] BYREF

  temp = 0;
  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
  {
    m_pData = (CUtlMemory<S3RGBA,int> *)this->m_pData;
    m_nAllocationCount = m_pData->m_nAllocationCount;
    m_pMemory = m_pData[1].m_pMemory;
    if ( (int)&m_pMemory->g > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(this: m_pData, num: (int)(&m_pMemory->g - m_nAllocationCount));
    ++m_pData[1].m_pMemory;
    v8 = m_pData->m_pMemory;
    v9 = (char *)m_pData[1].m_pMemory - (char *)m_pMemory - 1;
    m_pData[1].m_nAllocationCount = (int)m_pData->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[(_DWORD)m_pMemory + 1], src: &v8[(_DWORD)m_pMemory], count: 4 * v9);
    v10 = (Color *)&m_pData->m_pMemory[(_DWORD)m_pMemory];
    if ( v10 != nullptr )
      *v10 = temp;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024B300
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Vector2D,class CUtlMemory<class Vector2D,int>>,class Vector2D>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>,Vector2D>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  Vector2D temp; // [esp+4h] [ebp-8h] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: (CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x1024B340
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Vector,class CUtlMemory<class Vector,int>>,class Vector>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector,CUtlMemory<Vector,int>>,Vector>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  Vector temp; // [esp+4h] [ebp-Ch] BYREF

  v4 = Unserialize(buf, dest: (QAngle *)&temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x1024B380
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Vector4D,class CUtlMemory<class Vector4D,int>>,class Vector4D>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>,Vector4D>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  Vector4D temp; // [esp+4h] [ebp-10h] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<Vector4D,CUtlMemory<Vector4D,int>>::InsertBefore(
      this: (CUtlVector<Vector4D,CUtlMemory<Vector4D,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x1024B3C0
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class QAngle,class CUtlMemory<class QAngle,int>>,class QAngle>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<QAngle,CUtlMemory<QAngle,int>>,QAngle>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  QAngle temp; // [esp+4h] [ebp-Ch] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<QAngle,CUtlMemory<QAngle,int>>::InsertBefore(
      this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: (const CVTFTexture::ResourceMemorySection *)&temp);
}

//------------------------------------------------------------------------------
// Address: 0x1024B400
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class Quaternion,class CUtlMemory<class Quaternion,int>>,class Quaternion>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<Quaternion,CUtlMemory<Quaternion,int>>,Quaternion>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  Quaternion temp; // [esp+4h] [ebp-10h] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<DispCollPlaneIndex_t,CUtlMemory<DispCollPlaneIndex_t,int>>::InsertBefore(
      this: (CUtlVector<CSosOperator::InputData_t,CUtlMemory<CSosOperator::InputData_t,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: (const CSosOperator::InputData_t *)&temp);
}

//------------------------------------------------------------------------------
// Address: 0x1024B440
// Name: private: void CDmxAttribute::UnserializeTypedElement<class CUtlVector<class VMatrix,class CUtlMemory<class VMatrix,int>>,class VMatrix>(bool __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::UnserializeTypedElement<CUtlVector<VMatrix,CUtlMemory<VMatrix,int>>,VMatrix>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  bool v4; // al
  VMatrix temp; // [esp+4h] [ebp-40h] BYREF

  v4 = Unserialize(buf, dest: &temp);
  *bSuccess = v4;
  if ( v4 )
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)this->m_pData,
      elem: *((_DWORD *)this->m_pData + 3),
      src: &temp);
}

//------------------------------------------------------------------------------
// Address: 0x1024C4A0
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>,class CUtlString>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>,CUtlString>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *m_pData; // eax
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > temp; // [esp+0h] [ebp-14h] BYREF

  m_pData = (const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<CUtlString>(buf, src: m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&temp);
    *bSuccess = Serialize<CUtlString>(buf, src: &temp);
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&temp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024C510
// Name: private: void CDmxAttribute::SerializeType<class CUtlVector<class CUtlBinaryBlock,class CUtlMemory<class CUtlBinaryBlock,int>>,class CUtlBinaryBlock>(bool __near &,class CUtlBuffer __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxAttribute::SerializeType<CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>,CUtlBinaryBlock>(
        CDmxAttribute *this,
        bool *bSuccess,
        CUtlBuffer *buf)
{
  const CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *m_pData; // eax
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > temp; // [esp+0h] [ebp-14h] BYREF

  m_pData = (const CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)this->m_pData;
  if ( m_pData != nullptr )
  {
    *bSuccess = Serialize<CUtlBinaryBlock>(buf, src: m_pData);
  }
  else
  {
    memset(&temp, 0, sizeof(temp));
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: &temp);
    *bSuccess = Serialize<CUtlBinaryBlock>(buf, src: &temp);
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: &temp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10263CC0
// Name: public: virtual void CColorHistogramPanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorHistogramPanel::PaintBackground(CCurveEditorPanel *this)
{
  int h; // [esp+4h] [ebp-8h] BYREF
  int w; // [esp+8h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: w, a5: h);
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 128, a3: 128, a4: 128, a5: 255);
  g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: 0, a3: h / 4, a4: w, a5: h / 4);
  g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: 0, a3: h / 2, a4: w, a5: h / 2);
  g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: 0, a3: 3 * h / 4, a4: w, a5: 3 * h / 4);
  g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: w / 4, a3: 0, a4: w / 4, a5: h);
  g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: w / 2, a3: 0, a4: w / 2, a5: h);
  g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: 3 * w / 4, a3: 0, a4: 3 * w / 4, a5: h);
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 0, a3: 0, a4: 0, a5: 255);
  g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: 0, a3: 0, a4: w, a5: 0);
  g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: w, a3: 0, a4: w, a5: h);
  g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: w, a3: h, a4: 0, a5: h);
  g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: 0, a3: h, a4: 0, a5: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102821F0
// Name: public: virtual void CColorBalanceUIPanel::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorBalanceUIPanel::Init(vgui::PropertyPage *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1029C6E0
// Name: public: virtual class vgui::Panel __near * vgui::TextEntry::GetDragPanel(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall vgui::TextEntry::GetDragPanel(vgui::TextEntry *this)
{
  int v2; // edi
  int cx1; // [esp+4h] [ebp-10h] BYREF
  int cx0; // [esp+8h] [ebp-Ch] BYREF
  int x; // [esp+Ch] [ebp-8h] BYREF
  int y; // [esp+10h] [ebp-4h] BYREF

  if ( !g_pVGuiInput->IsMouseDown(this: g_pVGuiInput, a2: KEY_COUNT) )
    return vgui::Panel::GetDragPanel(this);
  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  vgui::Panel::ScreenToLocal(this, &x, &y);
  v2 = this->PixelToCursorSpace(this, a2: x, a3: y);
  if ( this->GetSelectedRange(this, a2: &cx0, a3: &cx1) && v2 >= cx0 && v2 < cx1 )
    return vgui::Panel::GetDragPanel(this);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1029FE70
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::TextEntry::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::TextEntry::GetMessageMap(vgui::TextEntry *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::TextEntry::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TextEntry::GetMessageMap'::`2'::s_pMap;
  `vgui::TextEntry::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "TextEntry");
  `vgui::TextEntry::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1029FEA0
// Name: public: virtual struct PanelAnimationMap __near * vgui::TextEntry::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::TextEntry::GetAnimMap(vgui::TextEntry *this)
{
  return FindOrAddPanelAnimationMap(className: "TextEntry");
}

//------------------------------------------------------------------------------
// Address: 0x1029FEB0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::TextEntry::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::TextEntry::GetKBMap(vgui::TextEntry *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::TextEntry::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TextEntry::GetKBMap'::`2'::s_pMap;
  `vgui::TextEntry::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "TextEntry");
  `vgui::TextEntry::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10320290
// Name: _dynamic_initializer_for__CDmxElement::s_TypeSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmxElement::s_TypeSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>(this: &CDmxElement::s_TypeSymbols);
  return atexit(func: dynamic_atexit_destructor_for__CDmxElement::s_TypeSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x103202B0
// Name: _dynamic_initializer_for__CDmxAttribute::s_AttributeNameSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmxAttribute::s_AttributeNameSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>(this: &CDmxAttribute::s_AttributeNameSymbols);
  return atexit(func: dynamic_atexit_destructor_for__CDmxAttribute::s_AttributeNameSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x10327980
// Name: _dynamic_atexit_destructor_for__CDmxElement::s_TypeSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmxElement::s_TypeSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::RemoveAll(this: &CDmxElement::s_TypeSymbols);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&CDmxElement::s_TypeSymbols.m_StringPools);
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(this: &CDmxElement::s_TypeSymbols.m_Lookup);
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmxElement::s_TypeSymbols.m_Lookup.m_EntryMemory);
}

//------------------------------------------------------------------------------
// Address: 0x103279B0
// Name: _dynamic_atexit_destructor_for__CDmxAttribute::s_AttributeNameSymbols__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmxAttribute::s_AttributeNameSymbols__()
{
  CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::RemoveAll(this: &CDmxAttribute::s_AttributeNameSymbols);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&CDmxAttribute::s_AttributeNameSymbols.m_StringPools);
  CUtlTSHash<CUtlSymbolTableLargeBaseTreeEntry_t *,2048,CUtlSymbolTableLargeBaseTreeEntry_t *,CCThreadsafeTreeHashMethod<2048,CUtlSymbolTableLargeBaseTreeEntry_t *,0>,0>::RemoveAll(this: &CDmxAttribute::s_AttributeNameSymbols.m_Lookup);
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmxAttribute::s_AttributeNameSymbols.m_Lookup.m_EntryMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1006E010
// Name: __CreateCEngineClientIVEngineClient_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CEngineClient *__cdecl _CreateCEngineClientIVEngineClient_interface()
{
  return &s_VEngineClient;
}

} // namespace engine_xlsp
