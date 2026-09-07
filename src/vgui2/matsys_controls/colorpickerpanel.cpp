// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/matsys_controls/colorpickerpanel.cpp
// Functions: 52
// ============================================================

#include "vgui2\matsys_controls\colorpickerpanel.h"

//------------------------------------------------------------------------------
// Address: 0x004C2420
// Name: public: static char const __near * CColorPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CColorPickerPanel::GetPanelClassName()
{
  return "CColorPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x004C2430
// Name: public: static char const __near * CColorPickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CColorPickerFrame::GetPanelClassName()
{
  return "CColorPickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x004C24B0
// Name: public: static char const __near * CColorXYPreview::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CColorXYPreview::GetPanelClassName()
{
  return "CColorXYPreview";
}

//------------------------------------------------------------------------------
// Address: 0x004C24C0
// Name: public: void CColorZPreview::SetMode(enum ColorType_t,enum ColorChannel_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorZPreview::SetMode(CColorZPreview *this, ColorType_t type, ColorChannel_t channel)
{
  if ( this->m_Type != type || this->m_Channel != channel )
  {
    this->m_Type = type;
    this->m_Channel = channel;
    CProceduralTexturePanel::DownloadTexture(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C24F0
// Name: private: void CColorXYPreview::ComputeHSVColorForPoint(int,int,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorXYPreview::ComputeHSVColorForPoint(CColorXYPreview *this, int x, int y, Vector *vscHSV)
{
  float *v5; // ebx

  *vscHSV = this->m_CurrentHSVColor;
  *(&vscHSV->x + CColorXYPreview::s_pHSVRemapX[this->m_Channel]) = (float)x * 0.0039215689;
  v5 = &vscHSV->x + CColorXYPreview::s_pHSVRemapY[this->m_Channel];
  *v5 = (float)(CElementTreeViewListControl::GetTreeColumnWidth(this) - y - 1) * 0.0039215689;
  if ( vscHSV->y == 0.0 )
    vscHSV->x = -1.0;
  if ( this->m_Channel != CHANNEL_RED && vscHSV->x != -1.0 )
    vscHSV->x = vscHSV->x * 360.0;
}

//------------------------------------------------------------------------------
// Address: 0x004C25B0
// Name: public: virtual void CColorXYPreview::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorXYPreview::Paint(CColorXYPreview *this)
{
  float z; // eax
  ColorChannel_t v3; // ecx
  ColorChannel_t v4; // edx
  int v5; // ebx
  int TreeColumnWidth; // eax
  int v7; // edi
  int v8; // esi
  int v9; // edi
  Vector vecHSVNormalized; // [esp+Ch] [ebp-18h] BYREF
  int h; // [esp+18h] [ebp-Ch] BYREF
  int w; // [esp+1Ch] [ebp-8h] BYREF
  float *v13; // [esp+20h] [ebp-4h]

  CProceduralTexturePanel::Paint(this);
  if ( this->m_Type != COLOR_TYPE_RGB )
  {
    z = this->m_CurrentHSVColor.z;
    *(_QWORD *)&vecHSVNormalized.x = *(_QWORD *)&this->m_CurrentHSVColor.x;
    vecHSVNormalized.z = z;
    if ( vecHSVNormalized.x != -1.0 )
      vecHSVNormalized.x = vecHSVNormalized.x * 0.70833331;
    v3 = CColorXYPreview::s_pHSVRemapX[this->m_Channel];
    v4 = CColorXYPreview::s_pHSVRemapY[this->m_Channel];
    vecHSVNormalized.y = vecHSVNormalized.y * 255.0;
    vecHSVNormalized.z = vecHSVNormalized.z * 255.0;
    v5 = (int)(float)(*(&vecHSVNormalized.x + v3) + 0.5);
    v13 = &vecHSVNormalized.x + v4;
    TreeColumnWidth = CElementTreeViewListControl::GetTreeColumnWidth(this);
    v7 = TreeColumnWidth - (int)(float)(*v13 + 0.5);
  }
  else
  {
    v5 = *(&this->m_CurrentColor.r + CColorXYPreview::s_pRGBRemapX[this->m_Channel]);
    v7 = CElementTreeViewListControl::GetTreeColumnWidth(this)
       - *(&this->m_CurrentColor.r + CColorXYPreview::s_pRGBRemapY[this->m_Channel]);
  }
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  v8 = (int)(float)((float)((float)((float)w * (float)v5) * 0.0039215689) + 0.5);
  v9 = (int)(float)((float)((float)((float)h * (float)(v7 - 1)) * 0.0039215689) + 0.5);
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
  g_pVGuiSurface->DrawOutlinedCircle(this: g_pVGuiSurface, a2: v8, a3: v9, a4: 5, a5: 8);
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 0, a3: 0, a4: 0, a5: 255);
  g_pVGuiSurface->DrawOutlinedCircle(this: g_pVGuiSurface, a2: v8, a3: v9, a4: 6, a5: 8);
}

//------------------------------------------------------------------------------
// Address: 0x004C2780
// Name: public: virtual void CColorXYPreview::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorXYPreview::OnMouseReleased(CColorXYPreview *this, const char *code)
{
  vgui::Panel::OnMousePressed(this, panelName: code);
  if ( code == (const char *)107 && this->m_bDraggingMouse )
  {
    this->m_bDraggingMouse = false;
    g_pVGuiInput->SetMouseCapture(this: g_pVGuiInput, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C27C0
// Name: public: static char const __near * CColorZPreview::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CColorZPreview::GetPanelClassName()
{
  return "CColorZPreview";
}

//------------------------------------------------------------------------------
// Address: 0x004C27D0
// Name: public: void CColorZPreview::SetColor(struct RGB888_t const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorZPreview::SetColor(CColorZPreview *this, const RGB888_t *color, const Vector *hsvColor)
{
  if ( color->r != this->m_CurrentColor.r
    || color->g != this->m_CurrentColor.g
    || color->b != this->m_CurrentColor.b
    || hsvColor->x != this->m_CurrentHSVColor.x
    || hsvColor->y != this->m_CurrentHSVColor.y
    || hsvColor->z != this->m_CurrentHSVColor.z )
  {
    this->m_CurrentColor = *color;
    this->m_CurrentHSVColor = *hsvColor;
    CProceduralTexturePanel::DownloadTexture(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C2870
// Name: public: virtual void CColorZPreview::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorZPreview::PerformLayout(CColorZPreview *this)
{
  Rect_t r; // [esp+4h] [ebp-18h] BYREF
  int h; // [esp+14h] [ebp-8h] BYREF
  int w; // [esp+18h] [ebp-4h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  r.x = 6;
  r.y = 6;
  r.width = w - 12;
  r.height = h - 12;
  CProceduralTexturePanel::SetPaintRect(this, pPaintRect: &r);
}

//------------------------------------------------------------------------------
// Address: 0x004C28C0
// Name: public: virtual void CColorZPreview::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorZPreview::OnMouseReleased(CColorZPreview *this, const char *code)
{
  vgui::Panel::OnMousePressed(this, panelName: code);
  if ( code == (const char *)107 && this->m_bDraggingMouse )
  {
    this->m_bDraggingMouse = false;
    g_pVGuiInput->SetMouseCapture(this: g_pVGuiInput, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C2900
// Name: public: virtual void CColorZPreview::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorZPreview::Paint(CColorZPreview *this)
{
  float z; // eax
  ColorChannel_t m_Channel; // ecx
  int TreeColumnWidth; // eax
  int v5; // esi
  float v6; // xmm0_4
  int v7; // esi
  int py[3]; // [esp+8h] [ebp-30h] BYREF
  int px[3]; // [esp+14h] [ebp-24h] BYREF
  Vector vecHSVNormalized; // [esp+20h] [ebp-18h] BYREF
  int w; // [esp+2Ch] [ebp-Ch] BYREF
  float *v12; // [esp+30h] [ebp-8h]
  int h; // [esp+34h] [ebp-4h] BYREF

  CProceduralTexturePanel::Paint(this);
  if ( this->m_Type != COLOR_TYPE_RGB )
  {
    z = this->m_CurrentHSVColor.z;
    *(_QWORD *)&vecHSVNormalized.x = *(_QWORD *)&this->m_CurrentHSVColor.x;
    vecHSVNormalized.z = z;
    if ( vecHSVNormalized.x != -1.0 )
      vecHSVNormalized.x = vecHSVNormalized.x * 0.70833331;
    m_Channel = this->m_Channel;
    vecHSVNormalized.y = vecHSVNormalized.y * 255.0;
    vecHSVNormalized.z = vecHSVNormalized.z * 255.0;
    v12 = &vecHSVNormalized.x + m_Channel;
    TreeColumnWidth = CElementTreeViewListControl::GetTreeColumnWidth(this);
    v5 = TreeColumnWidth - (int)(float)(*v12 + 0.5);
  }
  else
  {
    v5 = CElementTreeViewListControl::GetTreeColumnWidth(this) - *(&this->m_CurrentColor.r + this->m_Channel);
  }
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  v6 = (float)(h - 12);
  h -= 12;
  v7 = (int)(float)((float)((float)(v6 * (float)(v5 - 1)) * 0.0039215689) + 0.5);
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
  py[1] = v7 + 12;
  py[0] = v7;
  px[0] = 0;
  px[1] = 0;
  px[2] = 6;
  py[2] = v7 + 6;
  g_pVGuiSurface->DrawPolyLine(this: g_pVGuiSurface, a2: px, a3: py, a4: 3);
  px[1] = w - 1;
  px[0] = w - 1;
  px[2] = w - 7;
  g_pVGuiSurface->DrawPolyLine(this: g_pVGuiSurface, a2: px, a3: py, a4: 3);
}

//------------------------------------------------------------------------------
// Address: 0x004C2A90
// Name: private: void CColorPickerPanel::UpdatePreviewColors(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerPanel::UpdatePreviewColors(CColorPickerPanel *this)
{
  Color c; // [esp+4h] [ebp-4h]

  *(RGB888_t *)c._color = this->m_InitialColor;
  c._color[3] = -1;
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pInitialColor->SetBgColor)(a1: this->m_pInitialColor, a2: c);
  *(RGB888_t *)c._color = this->m_CurrentColor;
  c._color[3] = -1;
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pCurrentColor->SetBgColor)(a1: this->m_pCurrentColor, a2: c);
}

//------------------------------------------------------------------------------
// Address: 0x004C2B10
// Name: public: virtual void CColorPickerPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerPanel::ApplySchemeSettings(CColorPickerPanel *this, vgui::IScheme *pScheme)
{
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  CColorPickerPanel::UpdatePreviewColors(this);
}

//------------------------------------------------------------------------------
// Address: 0x004C2B30
// Name: private: virtual void CColorPickerPanel::OnRadioButtonChecked(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerPanel::OnRadioButtonChecked(CColorPickerPanel *this, KeyValues *pKeyValues)
{
  vgui::RadioButton *Ptr; // eax
  CColorXYPreview *m_pColorXYPreview; // ecx
  CColorZPreview *m_pColorZPreview; // ecx
  int v6; // edi
  CColorXYPreview *v7; // ecx
  CColorZPreview *v8; // ecx

  Ptr = (vgui::RadioButton *)KeyValues::GetPtr(this: pKeyValues, keyName: "panel", defaultValue: nullptr);
  if ( Ptr == this->m_pRedRadio )
  {
    m_pColorXYPreview = this->m_pColorXYPreview;
    if ( m_pColorXYPreview->m_Type != COLOR_TYPE_RGB || m_pColorXYPreview->m_Channel != CHANNEL_RED )
    {
      m_pColorXYPreview->m_Type = COLOR_TYPE_RGB;
      m_pColorXYPreview->m_Channel = CHANNEL_RED;
      CProceduralTexturePanel::DownloadTexture(this: m_pColorXYPreview);
    }
    m_pColorZPreview = this->m_pColorZPreview;
    if ( m_pColorZPreview->m_Type != COLOR_TYPE_RGB || m_pColorZPreview->m_Channel != CHANNEL_RED )
    {
      m_pColorZPreview->m_Type = COLOR_TYPE_RGB;
      m_pColorZPreview->m_Channel = CHANNEL_RED;
      CProceduralTexturePanel::DownloadTexture(this: m_pColorZPreview);
    }
    return;
  }
  if ( Ptr == this->m_pGreenRadio )
  {
    v6 = 1;
    goto LABEL_12;
  }
  if ( Ptr == this->m_pBlueRadio )
  {
    v6 = 2;
LABEL_12:
    v7 = this->m_pColorXYPreview;
    if ( v7->m_Type != COLOR_TYPE_RGB || v7->m_Channel != v6 )
    {
      v7->m_Type = COLOR_TYPE_RGB;
      v7->m_Channel = v6;
      CProceduralTexturePanel::DownloadTexture(this: v7);
    }
    v8 = this->m_pColorZPreview;
    if ( v8->m_Type != COLOR_TYPE_RGB || v8->m_Channel != v6 )
    {
      v8->m_Type = COLOR_TYPE_RGB;
      v8->m_Channel = v6;
      CProceduralTexturePanel::DownloadTexture(this: v8);
    }
    return;
  }
  if ( Ptr == this->m_pHueRadio )
  {
    CColorZPreview::SetMode(this: (CColorZPreview *)this->m_pColorXYPreview, type: COLOR_TYPE_HSV, channel: CHANNEL_RED);
    CColorZPreview::SetMode(this: this->m_pColorZPreview, type: COLOR_TYPE_HSV, channel: CHANNEL_RED);
  }
  else if ( Ptr == this->m_pSaturationRadio )
  {
    CColorZPreview::SetMode(
      this: (CColorZPreview *)this->m_pColorXYPreview,
      type: COLOR_TYPE_HSV,
      channel: CHANNEL_GREEN);
    CColorZPreview::SetMode(this: this->m_pColorZPreview, type: COLOR_TYPE_HSV, channel: CHANNEL_GREEN);
  }
  else if ( Ptr == this->m_pValueRadio )
  {
    CColorZPreview::SetMode(
      this: (CColorZPreview *)this->m_pColorXYPreview,
      type: COLOR_TYPE_HSV,
      channel: CHANNEL_BLUE);
    CColorZPreview::SetMode(this: this->m_pColorZPreview, type: COLOR_TYPE_HSV, channel: CHANNEL_BLUE);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C2CB0
// Name: private: void CColorPickerPanel::OnColorChanged(class vgui::TextEntry __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerPanel::OnColorChanged(CColorPickerPanel *this, vgui::TextEntry *pChanged)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  char temp[256]; // [esp+8h] [ebp-100h] BYREF

  if ( pChanged != this->m_pRedText )
  {
    V_snprintf(pDest: temp, maxLen: 256, pFormat: "%d", this->m_CurrentColor.r);
    this->m_pRedText->SetText(this: this->m_pRedText, a2: temp);
  }
  if ( pChanged != this->m_pGreenText )
  {
    V_snprintf(pDest: temp, maxLen: 256, pFormat: "%d", this->m_CurrentColor.g);
    this->m_pGreenText->SetText(this: this->m_pGreenText, a2: temp);
  }
  if ( pChanged != this->m_pBlueText )
  {
    V_snprintf(pDest: temp, maxLen: 256, pFormat: "%d", this->m_CurrentColor.b);
    this->m_pBlueText->SetText(this: this->m_pBlueText, a2: temp);
  }
  if ( pChanged != this->m_pAlphaText )
  {
    V_snprintf(pDest: temp, maxLen: 256, pFormat: "%d", this->m_CurrentAlpha);
    this->m_pAlphaText->SetText(this: this->m_pAlphaText, a2: temp);
  }
  if ( pChanged != this->m_pHueText )
  {
    V_snprintf(pDest: temp, maxLen: 256, pFormat: "%d", (int)(float)(this->m_CurrentHSVColor.x + 0.5));
    this->m_pHueText->SetText(this: this->m_pHueText, a2: temp);
  }
  if ( pChanged != this->m_pSaturationText )
  {
    V_snprintf(pDest: temp, maxLen: 256, pFormat: "%d", (int)(float)((float)(this->m_CurrentHSVColor.y * 100.0) + 0.5));
    this->m_pSaturationText->SetText(this: this->m_pSaturationText, a2: temp);
  }
  if ( pChanged != this->m_pValueText )
  {
    V_snprintf(pDest: temp, maxLen: 256, pFormat: "%d", (int)(float)((float)(this->m_CurrentHSVColor.z * 100.0) + 0.5));
    this->m_pValueText->SetText(this: this->m_pValueText, a2: temp);
  }
  CColorZPreview::SetColor(
    this: (CColorZPreview *)this->m_pColorXYPreview,
    color: &this->m_CurrentColor,
    hsvColor: &this->m_CurrentHSVColor);
  CColorZPreview::SetColor(
    this: this->m_pColorZPreview,
    color: &this->m_CurrentColor,
    hsvColor: &this->m_CurrentHSVColor);
  CColorPickerPanel::UpdatePreviewColors(this);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "command", firstKey: "command", firstValue: "preview");
  else
    v4 = nullptr;
  this->PostActionSignal(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004C2F30
// Name: public: virtual void CColorPickerFrame::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerFrame::OnCommand(CColorPickerFrame *this, const char *pCommand)
{
  CColorPickerPanel *m_pPicker; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  KeyValues *v6; // eax
  CColorPickerPanel *v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  KeyValues *m_pContextKeys; // ecx
  KeyValues *Copy; // eax
  Color c; // [esp+10h] [ebp+8h]
  Color ca; // [esp+10h] [ebp+8h]

  if ( _V_stricmp(s1: pCommand, s2: "Ok") == 0 )
  {
    m_pPicker = this->m_pPicker;
    c._color[0] = m_pPicker->m_CurrentColor.r;
    *(_WORD *)&c._color[1] = *(_WORD *)&m_pPicker->m_CurrentColor.g;
    c._color[3] = m_pPicker->m_CurrentAlpha;
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "ColorPickerPicked");
    else
      v5 = nullptr;
    KeyValues::SetColor(this: v5, keyName: "color", value: c);
    if ( this->m_pContextKeys != nullptr )
    {
      KeyValues::AddSubKey(this: v5, pSubkey: this->m_pContextKeys);
      this->m_pContextKeys = nullptr;
    }
LABEL_7:
    this->CloseModal(this);
    this->PostActionSignal(this, a2: v5);
    return;
  }
  if ( _V_stricmp(s1: pCommand, s2: "Cancel") == 0 )
  {
    g_pVGuiInput->ReleaseAppModalSurface(this: g_pVGuiInput);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v5 = KeyValues::KeyValues(this: v6, setName: "ColorPickerCancel");
    else
      v5 = nullptr;
    if ( this->m_pContextKeys != nullptr )
    {
      KeyValues::AddSubKey(this: v5, pSubkey: this->m_pContextKeys);
      this->m_pContextKeys = nullptr;
    }
    goto LABEL_7;
  }
  if ( _V_stricmp(s1: pCommand, s2: "Preview") != 0 )
  {
    vgui::Frame::OnCommand(this, command: pCommand);
  }
  else
  {
    v7 = this->m_pPicker;
    ca._color[0] = v7->m_CurrentColor.r;
    *(_WORD *)&ca._color[1] = *(_WORD *)&v7->m_CurrentColor.g;
    ca._color[3] = v7->m_CurrentAlpha;
    v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v8 != nullptr )
      v9 = KeyValues::KeyValues(this: v8, setName: "ColorPickerPreview");
    else
      v9 = nullptr;
    KeyValues::SetColor(this: v9, keyName: "color", value: ca);
    m_pContextKeys = this->m_pContextKeys;
    if ( m_pContextKeys != nullptr )
    {
      Copy = KeyValues::MakeCopy(this: m_pContextKeys);
      KeyValues::AddSubKey(this: v9, pSubkey: Copy);
    }
    this->PostActionSignal(this, a2: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C3120
// Name: VectorToRGB888
// Source: json
//------------------------------------------------------------------------------
void __usercall VectorToRGB888(const Vector *inVector@<eax>, RGB888_t *outColor@<esi>)
{
  int v2; // ecx
  int v3; // edx
  int v4; // eax

  v2 = (int)(float)((float)(inVector->x * 255.0) + 0.5);
  v3 = (int)(float)((float)(inVector->y * 255.0) + 0.5);
  v4 = (int)(float)((float)(inVector->z * 255.0) + 0.5);
  if ( v2 >= 0 )
  {
    if ( v2 > 255 )
      LOBYTE(v2) = -1;
  }
  else
  {
    LOBYTE(v2) = 0;
  }
  outColor->r = v2;
  if ( v3 >= 0 )
  {
    if ( v3 > 255 )
      LOBYTE(v3) = -1;
  }
  else
  {
    LOBYTE(v3) = 0;
  }
  outColor->g = v3;
  if ( v4 >= 0 )
  {
    if ( v4 > 255 )
      LOBYTE(v4) = -1;
    outColor->b = v4;
  }
  else
  {
    outColor->b = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C31D0
// Name: public: CColorXYPreview::CColorXYPreview(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CColorXYPreview *__thiscall CColorXYPreview::CColorXYPreview(
        CColorXYPreview *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  unsigned int v7; // eax

  CProceduralTexturePanel::CProceduralTexturePanel(this, pParent, pName);
  this->CProceduralTexturePanel::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CColorXYPreview_vtbl *)&CColorXYPreview::`vftable'{for `vgui::EditablePanel'};
  this->CProceduralTexturePanel::ITextureRegenerator::__vftable = (ITextureRegenerator_vtbl *)&CColorXYPreview::`vftable'{for `ITextureRegenerator'};
  if ( `CColorXYPreview::ChainToMap'::`2'::chained == 0 )
  {
    `CColorXYPreview::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CColorXYPreview");
    v4->pfnClassName = CColorXYPreview::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CProceduralTexturePanel");
  }
  if ( `CColorXYPreview::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CColorXYPreview::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CColorXYPreview");
    v5->pfnClassName = CColorXYPreview::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CProceduralTexturePanel");
  }
  if ( `CColorXYPreview::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CColorXYPreview::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CColorXYPreview");
    v6->pfnClassName = CColorXYPreview::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CProceduralTexturePanel");
  }
  CProceduralTexturePanel::Init(this, nWidth: 256, nHeight: 256, bAllocateImageBuffer: false);
  *(_WORD *)&this->m_CurrentColor.g = -1;
  this->m_CurrentColor.r = -1;
  if ( this->m_Type != COLOR_TYPE_HSV || this->m_Channel != CHANNEL_RED )
  {
    this->m_Type = COLOR_TYPE_HSV;
    this->m_Channel = CHANNEL_RED;
    CProceduralTexturePanel::DownloadTexture(this);
  }
  vgui::Panel::SetMouseInputEnabled(this, state: true);
  v7 = g_pVGuiSurface->CreateCursorFromFile(this: g_pVGuiSurface, a2: "resource/colorpicker.cur", a3: nullptr);
  this->m_hPickerCursor = v7;
  vgui::Panel::SetCursor(this, cursor: v7);
  this->m_bDraggingMouse = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C3320
// Name: public: virtual struct vgui::PanelMessageMap __near * CColorXYPreview::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CColorXYPreview::GetMessageMap(CColorXYPreview *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CColorXYPreview::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorXYPreview::GetMessageMap'::`2'::s_pMap;
  `CColorXYPreview::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CColorXYPreview");
  `CColorXYPreview::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C3350
// Name: public: virtual struct PanelAnimationMap __near * CColorXYPreview::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CColorXYPreview::GetAnimMap(CColorXYPreview *this)
{
  return FindOrAddPanelAnimationMap(className: "CColorXYPreview");
}

//------------------------------------------------------------------------------
// Address: 0x004C3360
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CColorXYPreview::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CColorXYPreview::GetKBMap(CColorXYPreview *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CColorXYPreview::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorXYPreview::GetKBMap'::`2'::s_pMap;
  `CColorXYPreview::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CColorXYPreview");
  `CColorXYPreview::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C3390
// Name: public: virtual void CColorXYPreview::RegenerateTextureBits(class ITexture __near *,class IVTFTexture __near *,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorXYPreview::RegenerateTextureBits(
        CColorXYPreview *this,
        ITexture *pTexture,
        IVTFTexture *pVTFTexture,
        Rect_t *pRect)
{
  IVTFTexture *v4; // esi
  CColorXYPreview *v5; // ebx
  void (__thiscall *ComputeMipLevelDimensions)(IVTFTexture *, int, int *, int *, int *); // edx
  unsigned __int16 v7; // di
  int v8; // eax
  int v9; // esi
  int v10; // eax
  int v11; // edx
  int v12; // ecx
  IVTFTexture *v13; // edi
  int v14; // ecx
  unsigned __int8 *m_pMemory; // eax
  int *p_m_nAllocationCount; // esi
  int v17; // ebx
  int TreeColumnWidth; // eax
  float v19; // xmm0_4
  int v20; // eax
  int v21; // ecx
  float v22; // xmm2_4
  int v23; // esi
  char v24; // dl
  int v25; // eax
  char v26; // cl
  int v27; // eax
  char v28; // al
  unsigned __int8 *v29; // edx
  int v30; // esi
  int v31; // eax
  unsigned int v32; // edx
  unsigned int v33; // edx
  int v34; // eax
  unsigned __int64 v35; // rdi
  __int64 v36; // rax
  __int64 v37; // rax
  int v38; // ebx
  unsigned __int64 v39; // rax
  IVTFTexture *pixelWriter_4; // [esp+10h] [ebp-6Ch]
  unsigned __int8 pixelWriter_10; // [esp+16h] [ebp-66h]
  int pixelWriter_12; // [esp+18h] [ebp-64h]
  int pixelWriter_16; // [esp+1Ch] [ebp-60h]
  char pixelWriter_20; // [esp+20h] [ebp-5Ch]
  char pixelWriter_24; // [esp+24h] [ebp-58h]
  int pixelWriter_28; // [esp+28h] [ebp-54h]
  unsigned __int8 pixelWriter_32; // [esp+2Ch] [ebp-50h]
  Vector rgb; // [esp+30h] [ebp-4Ch] BYREF
  Vector vecHSV; // [esp+3Ch] [ebp-40h] BYREF
  int v50; // [esp+4Ch] [ebp-30h]
  int nDepth; // [esp+50h] [ebp-2Ch] BYREF
  int v52; // [esp+54h] [ebp-28h]
  int nHeight; // [esp+58h] [ebp-24h] BYREF
  IVTFTexture *v54; // [esp+5Ch] [ebp-20h]
  CColorXYPreview *v55; // [esp+60h] [ebp-1Ch]
  int nWidth; // [esp+64h] [ebp-18h] BYREF
  int v57; // [esp+68h] [ebp-14h]
  int v58; // [esp+6Ch] [ebp-10h]
  int y; // [esp+70h] [ebp-Ch]
  int x; // [esp+74h] [ebp-8h]
  int v61; // [esp+78h] [ebp-4h]

  v4 = pVTFTexture;
  v5 = this;
  ComputeMipLevelDimensions = pVTFTexture->ComputeMipLevelDimensions;
  v55 = this;
  ComputeMipLevelDimensions(this: pVTFTexture, a2: 0, a3: &nWidth, a4: &nHeight, a5: &nDepth);
  v7 = v4->RowSizeInBytes(this: v4, a2: 0);
  pVTFTexture = (IVTFTexture *)v4->ImageData_2(this: v4, a2: 0, a3: 0, a4: 0);
  v8 = v4->Format(this: v4);
  v9 = v8;
  switch ( v8 )
  {
    case 0:
    case 23:
      v10 = 255;
      pixelWriter_10 = 4;
      pixelWriter_12 = 0x80000;
      pixelWriter_16 = 1572880;
      pixelWriter_20 = -1;
      goto LABEL_19;
    case 3:
      v10 = 255;
      pixelWriter_10 = 3;
      pixelWriter_12 = 524304;
      pixelWriter_16 = 0;
      pixelWriter_20 = -1;
      pixelWriter_32 = 0;
      goto LABEL_20;
    case 5:
      pixelWriter_10 = 1;
      pixelWriter_12 = 0;
      pixelWriter_16 = 0;
      goto LABEL_17;
    case 8:
      v10 = 0;
      pixelWriter_10 = 1;
      pixelWriter_12 = 0;
      pixelWriter_16 = 0;
      pixelWriter_20 = 0;
      pixelWriter_32 = -1;
      goto LABEL_20;
    case 12:
      v10 = 255;
      pixelWriter_10 = 4;
      pixelWriter_12 = 524304;
      pixelWriter_16 = 1572864;
      pixelWriter_20 = -1;
      goto LABEL_19;
    case 16:
      v10 = 255;
      pixelWriter_10 = 4;
      pixelWriter_12 = 524304;
      pixelWriter_16 = 1572864;
      pixelWriter_20 = -1;
      pixelWriter_32 = 0;
      goto LABEL_20;
    case 17:
      v10 = 248;
      pixelWriter_10 = 2;
      pixelWriter_12 = 196616;
      pixelWriter_16 = 65533;
      pixelWriter_20 = -8;
      pixelWriter_24 = -4;
      pixelWriter_32 = 0;
      goto LABEL_21;
    case 18:
    case 21:
      v10 = 248;
      pixelWriter_10 = 2;
      pixelWriter_12 = 131079;
      pixelWriter_16 = 589821;
      pixelWriter_20 = -8;
      pixelWriter_32 = 0x80;
      goto LABEL_20;
    case 19:
      v10 = 240;
      pixelWriter_10 = 2;
      pixelWriter_12 = 4;
      pixelWriter_16 = 589820;
      pixelWriter_20 = -16;
      goto LABEL_19;
    case 24:
    case 25:
      v10 = 0xFFFF;
      pixelWriter_10 = 8;
      pixelWriter_12 = 0x100000;
      pixelWriter_16 = 3145760;
      pixelWriter_20 = -1;
      goto LABEL_19;
    case 27:
      pixelWriter_10 = 4;
      pixelWriter_12 = 0;
      pixelWriter_16 = 0;
      pixelWriter_20 = -1;
      goto LABEL_18;
    case 29:
      v10 = -1;
      pixelWriter_10 = 16;
      pixelWriter_12 = 0x200000;
      pixelWriter_16 = (int)&loc_60003E + 2;
      pixelWriter_20 = -1;
      goto LABEL_19;
    default:
      if ( `CPixelWriter::SetPixelMemory'::`10'::format_error_printed[v8] == 0 )
      {
        _Msg(a1: "CPixelWriter::SetPixelMemory:  Unsupported image format %i\n", v8);
        `CPixelWriter::SetPixelMemory'::`10'::format_error_printed[v9] = 1;
      }
      pixelWriter_10 = 0;
      pixelWriter_12 = 0;
      pixelWriter_16 = 0;
LABEL_17:
      pixelWriter_20 = -1;
LABEL_18:
      v10 = 0;
LABEL_19:
      pixelWriter_32 = v10;
LABEL_20:
      pixelWriter_24 = v10;
LABEL_21:
      pixelWriter_28 = v10;
      y = 0;
      if ( nHeight > 0 )
      {
        v11 = nWidth;
        v12 = v7;
        v13 = pVTFTexture;
        v52 = v12;
        v58 = -1;
        v54 = pVTFTexture;
        do
        {
          v14 = 0;
          pixelWriter_4 = v13;
          x = 0;
          if ( v11 > 0 )
          {
            v61 = pixelWriter_10;
            while ( 1 )
            {
              if ( v5->_vpanel != 0 )
              {
                m_pMemory = v5->_panelName.m_Storage.m_Memory.m_pMemory;
                p_m_nAllocationCount = &v5[-1]._actionSignalTargetDar.m_Memory.m_nAllocationCount;
                vecHSV = *(Vector *)&v5->_panelName.m_Storage.m_Memory.m_nGrowSize;
                m_pMemory = (unsigned __int8 *)(2 * (_DWORD)m_pMemory);
                v17 = *(ColorChannel_t *)((char *)CColorXYPreview::s_pHSVRemapY + 2 * (_DWORD)m_pMemory);
                *(&vecHSV.x + *(ColorChannel_t *)((char *)CColorXYPreview::s_pHSVRemapX + 2 * (_DWORD)m_pMemory)) = (float)v14 * 0.0039215689;
                TreeColumnWidth = CElementTreeViewListControl::GetTreeColumnWidth(this: (CProceduralTexturePanel *)p_m_nAllocationCount);
                *(&vecHSV.x + v17) = (float)(v58 + TreeColumnWidth) * 0.0039215689;
                if ( vecHSV.y == 0.0 )
                {
                  v19 = -1.0;
                  vecHSV.x = -1.0;
                }
                else
                {
                  v19 = vecHSV.x;
                }
                if ( p_m_nAllocationCount[114] != 0 && v19 != -1.0 )
                  vecHSV.x = v19 * 360.0;
                HSVtoRGB(hsv: &vecHSV, &rgb);
                v20 = (int)(float)((float)(rgb.x * 255.0) + 0.5);
                v21 = (int)(float)((float)(rgb.y * 255.0) + 0.5);
                v22 = (float)(rgb.z * 255.0) + 0.5;
                v23 = (int)v22;
                if ( v20 >= 0 )
                {
                  if ( v20 > 255 )
                    LOBYTE(v20) = -1;
                }
                else
                {
                  LOBYTE(v20) = 0;
                }
                v24 = v20;
                if ( v21 >= 0 )
                {
                  LOBYTE(v25) = -1;
                  if ( v21 <= 255 )
                    v25 = (int)(float)((float)(rgb.y * 255.0) + 0.5);
                }
                else
                {
                  LOBYTE(v25) = 0;
                }
                v26 = v25;
                if ( v23 >= 0 )
                {
                  LOBYTE(v27) = -1;
                  if ( v23 <= 255 )
                    v27 = (int)v22;
                }
                else
                {
                  LOBYTE(v27) = 0;
                }
              }
              else
              {
                v28 = BYTE2(v5->_panelName.m_Storage.m_Memory.m_nAllocationCount);
                LOWORD(pVTFTexture) = v5->_panelName.m_Storage.m_Memory.m_nAllocationCount;
                v29 = v5->_panelName.m_Storage.m_Memory.m_pMemory;
                BYTE2(pVTFTexture) = v28;
                *((_BYTE *)&pVTFTexture + CColorXYPreview::s_pRGBRemapX[(_DWORD)v29]) = v14;
                LOBYTE(v27) = CElementTreeViewListControl::GetTreeColumnWidth(this: (CColorXYPreview *)((char *)v5 - 380));
                *((_BYTE *)&pVTFTexture + CColorXYPreview::s_pRGBRemapY[(int)v5->_panelName.m_Storage.m_Memory.m_pMemory]) = -1 - y + v27;
                LOBYTE(v27) = BYTE2(pVTFTexture);
                v26 = BYTE1(pVTFTexture);
                v24 = (char)pVTFTexture;
              }
              v30 = (unsigned __int8)v27;
              v57 = (unsigned __int8)v27;
              if ( pixelWriter_10 != 0 )
              {
                if ( pixelWriter_10 >= 5u )
                {
                  v35 = ((unsigned __int64)(unsigned __int8)(v26 & pixelWriter_24) << SBYTE2(pixelWriter_12))
                      | ((unsigned __int64)(unsigned __int8)(v24 & pixelWriter_20) << pixelWriter_12);
                  v36 = v57 & (unsigned int)pixelWriter_28;
                  if ( (__int16)pixelWriter_16 <= 0 )
                    v37 = v36 >> -(char)pixelWriter_16;
                  else
                    v37 = v36 << pixelWriter_16;
                  v50 = HIDWORD(v37);
                  v38 = v37;
                  v39 = (unsigned __int64)pixelWriter_32 << SBYTE2(pixelWriter_16);
                  LODWORD(v35) = v38 | v39 | v35;
                  HIDWORD(v35) |= v50 | HIDWORD(v39);
                  if ( v61 == 6 )
                  {
                    pixelWriter_4->__vftable = (IVTFTexture_vtbl *)v35;
                    LOWORD(pixelWriter_4[1].__vftable) = WORD2(v35);
                  }
                  else if ( v61 == 8 )
                  {
                    *(_QWORD *)&pixelWriter_4->__vftable = v35;
                  }
                  v13 = pixelWriter_4;
                }
                else
                {
                  v31 = ((unsigned __int8)(v26 & pixelWriter_24) << SBYTE2(pixelWriter_12))
                      | ((unsigned __int8)(v24 & pixelWriter_20) << pixelWriter_12);
                  v32 = v30 & pixelWriter_28;
                  if ( (__int16)pixelWriter_16 <= 0 )
                    v33 = v32 >> -(char)pixelWriter_16;
                  else
                    v33 = v32 << pixelWriter_16;
                  v34 = v33 | (pixelWriter_32 << SBYTE2(pixelWriter_16)) | v31;
                  switch ( v61 )
                  {
                    case 1:
                      LOBYTE(v13->__vftable) = v34;
                      break;
                    case 2:
                      LOWORD(v13->__vftable) = v34;
                      break;
                    case 3:
                      LOWORD(v13->__vftable) = v34;
                      BYTE2(v13->__vftable) = BYTE2(v34);
                      break;
                    case 4:
                      v13->__vftable = (IVTFTexture_vtbl *)v34;
                      break;
                    default:
                      break;
                  }
                }
              }
              v13 = (IVTFTexture *)((char *)v13 + v61);
              v11 = nWidth;
              v5 = v55;
              pixelWriter_4 = v13;
              if ( ++x >= nWidth )
                break;
              v14 = x;
            }
          }
          v13 = (IVTFTexture *)((char *)v54 + v52);
          --v58;
          ++y;
          v54 = (IVTFTexture *)((char *)v54 + v52);
        }
        while ( y < nHeight );
      }
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C3980
// Name: private: void CColorXYPreview::UpdateColorFromMouse(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorXYPreview::UpdateColorFromMouse(CColorXYPreview *this, float x, float y)
{
  float v4; // xmm0_4
  float v5; // xmm1_4
  int ImageWidth; // eax
  int v7; // ebx
  int TreeColumnWidth; // eax
  bool v9; // zf
  float v10; // xmm0_4
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  Vector *p_rgb; // eax
  unsigned __int8 b; // al
  ColorChannel_t m_Channel; // ecx
  ColorChannel_t v16; // edx
  char v17; // al
  unsigned __int8 v18; // bl
  KeyValues *v19; // eax
  KeyValues *v20; // esi
  Vector rgb; // [esp+10h] [ebp-20h] BYREF
  Vector vecHSV; // [esp+1Ch] [ebp-14h] BYREF
  int h; // [esp+28h] [ebp-8h] BYREF
  int w; // [esp+2Ch] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  v4 = (float)SLODWORD(x) / (float)(w - 1);
  v5 = (float)SLODWORD(y) / (float)(h - 1);
  if ( v4 >= 0.0 )
  {
    if ( v4 <= 1.0 )
      x = (float)SLODWORD(x) / (float)(w - 1);
    else
      x = 1.0;
  }
  else
  {
    x = 0.0;
  }
  if ( v5 >= 0.0 )
  {
    if ( v5 <= 1.0 )
      y = (float)SLODWORD(y) / (float)(h - 1);
    else
      y = 1.0;
  }
  else
  {
    y = 0.0;
  }
  ImageWidth = CProceduralTexturePanel::GetImageWidth(this);
  v7 = (int)(float)((float)((float)(ImageWidth - 1) * x) + 0.5);
  TreeColumnWidth = CElementTreeViewListControl::GetTreeColumnWidth(this);
  v9 = this->m_Type == COLOR_TYPE_RGB;
  v10 = (float)((float)(TreeColumnWidth - 1) * y) + 0.5;
  LODWORD(y) = (int)v10;
  if ( v9 )
  {
    b = this->m_CurrentColor.b;
    m_Channel = this->m_Channel;
    LOWORD(x) = *(_WORD *)&this->m_CurrentColor.r;
    v16 = CColorXYPreview::s_pRGBRemapX[m_Channel];
    BYTE2(x) = b;
    *((_BYTE *)&x + v16) = v7;
    v17 = CElementTreeViewListControl::GetTreeColumnWidth(this);
    *((_BYTE *)&x + CColorXYPreview::s_pRGBRemapY[this->m_Channel]) = -1 - LOBYTE(y) + v17;
    v18 = LOBYTE(x);
    LOWORD(y) = LOWORD(x);
    BYTE2(y) = BYTE2(x);
    HIBYTE(y) = -1;
    v19 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v19 != nullptr )
      v20 = KeyValues::KeyValues(this: v19, setName: "ColorSelected");
    else
      v20 = nullptr;
    KeyValues::SetColor(this: v20, keyName: "color", value: LODWORD(y));
    this->PostActionSignal(this, a2: v20);
    vecHSV.x = (float)v18 * 0.0039215689;
    vecHSV.y = (float)BYTE1(x) * 0.0039215689;
    vecHSV.z = (float)BYTE2(x) * 0.0039215689;
    RGBtoHSV(rgb: &vecHSV, hsv: &rgb);
    p_rgb = &rgb;
  }
  else
  {
    CColorXYPreview::ComputeHSVColorForPoint(this, x: v7, y: (int)v10, vscHSV: &vecHSV);
    v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v11 != nullptr )
      v12 = KeyValues::KeyValues(this: v11, setName: "HSVSelected");
    else
      v12 = nullptr;
    KeyValues::SetFloat(this: v12, keyName: "hue", value: vecHSV.x);
    KeyValues::SetFloat(this: v12, keyName: "saturation", value: vecHSV.y);
    KeyValues::SetFloat(this: v12, keyName: "value", value: vecHSV.z);
    this->PostActionSignal(this, a2: v12);
    HSVtoRGB(hsv: &vecHSV, &rgb);
    VectorToRGB888(inVector: &rgb, outColor: (RGB888_t *)&x);
    p_rgb = &vecHSV;
  }
  CColorZPreview::SetColor((CColorZPreview *)this, color: (const RGB888_t *)&x, hsvColor: p_rgb);
}

//------------------------------------------------------------------------------
// Address: 0x004C3C10
// Name: public: virtual void CColorXYPreview::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorXYPreview::OnMousePressed(CColorXYPreview *this, const char *code)
{
  const char *v2; // edi
  unsigned int (__thiscall *GetVPanel)(vgui::IClientPanel *); // edx
  vgui::IInput *v5; // edi
  vgui::IInput_vtbl *v6; // ebx
  int v7; // eax
  int x; // [esp+8h] [ebp-4h] BYREF

  v2 = code;
  vgui::Panel::OnMousePressed(this, panelName: code);
  if ( v2 == (const char *)107 && !this->m_bDraggingMouse )
  {
    GetVPanel = this->GetVPanel;
    this->m_bDraggingMouse = true;
    v5 = g_pVGuiInput;
    v6 = g_pVGuiInput->__vftable;
    v7 = GetVPanel(this);
    v6->SetMouseCapture(this: v5, a2: v7);
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: (int *)&code);
    vgui::Panel::ScreenToLocal(this, &x, y: (int *)&code);
    CColorXYPreview::UpdateColorFromMouse(this, x: *(float *)&x, y: *(float *)&code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C3C90
// Name: public: virtual void CColorXYPreview::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorXYPreview::OnCursorMoved(CColorXYPreview *this, int x, KeyValues *y)
{
  BlankImage::SetSize((vgui::TreeView *)this, itemIndex: x, msg: y);
  if ( this->m_bDraggingMouse )
    CColorXYPreview::UpdateColorFromMouse(this, x: *(float *)&x, y: *(float *)&y);
}

//------------------------------------------------------------------------------
// Address: 0x004C3CC0
// Name: public: CColorZPreview::CColorZPreview(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CColorZPreview *__thiscall CColorZPreview::CColorZPreview(
        CColorZPreview *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  __int16 v7; // dx
  int b; // eax
  Vector vecRGB; // [esp+Ch] [ebp-Ch] BYREF

  CProceduralTexturePanel::CProceduralTexturePanel(this, pParent, pName);
  this->CProceduralTexturePanel::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CColorZPreview_vtbl *)&CColorZPreview::`vftable'{for `vgui::EditablePanel'};
  this->CProceduralTexturePanel::ITextureRegenerator::__vftable = (ITextureRegenerator_vtbl *)&CColorZPreview::`vftable'{for `ITextureRegenerator'};
  if ( `CColorZPreview::ChainToMap'::`2'::chained == 0 )
  {
    `CColorZPreview::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CColorZPreview");
    v4->pfnClassName = CColorZPreview::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CProceduralTexturePanel");
  }
  if ( `CColorZPreview::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CColorZPreview::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CColorZPreview");
    v5->pfnClassName = CColorZPreview::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CProceduralTexturePanel");
  }
  if ( `CColorZPreview::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CColorZPreview::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CColorZPreview");
    v6->pfnClassName = CColorZPreview::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CProceduralTexturePanel");
  }
  CProceduralTexturePanel::Init(this, nWidth: 8, nHeight: 256, bAllocateImageBuffer: false);
  *(_WORD *)&this->m_CurrentColor.g = -1;
  this->m_CurrentColor.r = -1;
  v7 = *(_WORD *)&this->m_CurrentColor.r;
  b = this->m_CurrentColor.b;
  vecRGB.x = (float)(unsigned __int8)v7 * 0.0039215689;
  vecRGB.y = (float)HIBYTE(v7) * 0.0039215689;
  vecRGB.z = (float)b * 0.0039215689;
  RGBtoHSV(rgb: &vecRGB, hsv: &this->m_CurrentHSVColor);
  this->m_bDraggingMouse = false;
  vgui::Panel::SetMouseInputEnabled(this, state: true);
  if ( this->m_Type != COLOR_TYPE_HSV || this->m_Channel != CHANNEL_RED )
  {
    this->m_Type = COLOR_TYPE_HSV;
    this->m_Channel = CHANNEL_RED;
    CProceduralTexturePanel::DownloadTexture(this);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C3E50
// Name: public: virtual struct vgui::PanelMessageMap __near * CColorZPreview::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CColorZPreview::GetMessageMap(CColorZPreview *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CColorZPreview::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorZPreview::GetMessageMap'::`2'::s_pMap;
  `CColorZPreview::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CColorZPreview");
  `CColorZPreview::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C3E80
// Name: public: virtual struct PanelAnimationMap __near * CColorZPreview::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CColorZPreview::GetAnimMap(CColorZPreview *this)
{
  return FindOrAddPanelAnimationMap(className: "CColorZPreview");
}

//------------------------------------------------------------------------------
// Address: 0x004C3E90
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CColorZPreview::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CColorZPreview::GetKBMap(CColorZPreview *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CColorZPreview::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorZPreview::GetKBMap'::`2'::s_pMap;
  `CColorZPreview::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CColorZPreview");
  `CColorZPreview::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C3EF0
// Name: public: virtual void CColorZPreview::RegenerateTextureBits(class ITexture __near *,class IVTFTexture __near *,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorZPreview::RegenerateTextureBits(
        CColorZPreview *this,
        ITexture *pTexture,
        IVTFTexture *pVTFTexture,
        Rect_t *pRect)
{
  IVTFTexture *v4; // esi
  CColorZPreview *v5; // edi
  void (__thiscall *ComputeMipLevelDimensions)(IVTFTexture *, int, int *, int *, int *); // edx
  int v7; // eax
  int v8; // esi
  float v9; // xmm0_4
  float *p_actionSignalTargetDar; // esi
  int v11; // edi
  int TreeColumnWidth; // eax
  int v13; // eax
  int v14; // edx
  int v15; // ecx
  int v16; // ebx
  int v17; // eax
  __int16 m_nAllocationCount; // ax
  int v19; // esi
  int v20; // ecx
  unsigned __int8 v21; // al
  int v22; // edi
  unsigned int v23; // edx
  unsigned int v24; // edx
  int v25; // eax
  unsigned __int64 v26; // rdi
  __int64 v27; // rax
  __int64 v28; // rax
  int v29; // ebx
  unsigned __int64 v30; // rax
  int pixelWriter_4; // [esp+10h] [ebp-74h]
  unsigned __int8 pixelWriter_10; // [esp+16h] [ebp-6Eh]
  int pixelWriter_12; // [esp+18h] [ebp-6Ch]
  int pixelWriter_16; // [esp+1Ch] [ebp-68h]
  int pixelWriter_20; // [esp+20h] [ebp-64h]
  int pixelWriter_24; // [esp+24h] [ebp-60h]
  int pixelWriter_28; // [esp+28h] [ebp-5Ch]
  unsigned __int8 pixelWriter_32; // [esp+2Ch] [ebp-58h]
  Vector rgb; // [esp+30h] [ebp-54h] BYREF
  Vector vecHSV; // [esp+3Ch] [ebp-48h] BYREF
  int v41; // [esp+4Ch] [ebp-38h]
  int nDepth; // [esp+50h] [ebp-34h] BYREF
  int v43; // [esp+54h] [ebp-30h]
  int v44; // [esp+58h] [ebp-2Ch]
  int v45; // [esp+5Ch] [ebp-28h]
  CColorZPreview *v46; // [esp+60h] [ebp-24h]
  int nHeight; // [esp+64h] [ebp-20h] BYREF
  int nWidth; // [esp+68h] [ebp-1Ch] BYREF
  int x; // [esp+6Ch] [ebp-18h]
  int v50; // [esp+70h] [ebp-14h]
  int v51; // [esp+74h] [ebp-10h]
  int v52; // [esp+78h] [ebp-Ch]
  int y; // [esp+7Ch] [ebp-8h]
  int v54; // [esp+80h] [ebp-4h]

  v4 = pVTFTexture;
  v5 = this;
  ComputeMipLevelDimensions = pVTFTexture->ComputeMipLevelDimensions;
  v46 = this;
  ComputeMipLevelDimensions(this: pVTFTexture, a2: 0, a3: &nWidth, a4: &nHeight, a5: &nDepth);
  pVTFTexture = (IVTFTexture *)v4->RowSizeInBytes(this: v4, a2: 0);
  x = (int)v4->ImageData_2(this: v4, a2: 0, a3: 0, a4: 0);
  v7 = v4->Format(this: v4);
  v8 = v7;
  switch ( v7 )
  {
    case 0:
    case 23:
      pixelWriter_12 = 0x80000;
      pixelWriter_16 = 1572880;
      goto LABEL_6;
    case 3:
      pixelWriter_10 = 3;
      pixelWriter_12 = 524304;
      pixelWriter_16 = 0;
      pixelWriter_20 = 255;
      pixelWriter_24 = 255;
      pixelWriter_28 = 255;
      goto LABEL_20;
    case 5:
      pixelWriter_10 = 1;
      pixelWriter_12 = 0;
      pixelWriter_16 = 0;
      goto LABEL_18;
    case 8:
      pixelWriter_10 = 1;
      pixelWriter_12 = 0;
      pixelWriter_16 = 0;
      pixelWriter_20 = 0;
      pixelWriter_24 = 0;
      pixelWriter_28 = 0;
      pixelWriter_32 = -1;
      goto LABEL_21;
    case 12:
      pixelWriter_12 = 524304;
      pixelWriter_16 = 1572864;
LABEL_6:
      pixelWriter_10 = 4;
      pixelWriter_20 = 255;
      pixelWriter_24 = 255;
      pixelWriter_28 = 255;
      pixelWriter_32 = -1;
      goto LABEL_21;
    case 16:
      pixelWriter_10 = 4;
      pixelWriter_12 = 524304;
      pixelWriter_16 = 1572864;
      pixelWriter_20 = 255;
      pixelWriter_24 = 255;
      pixelWriter_28 = 255;
      goto LABEL_20;
    case 17:
      pixelWriter_10 = 2;
      pixelWriter_12 = 196616;
      pixelWriter_16 = 65533;
      pixelWriter_20 = 248;
      pixelWriter_24 = 252;
      pixelWriter_28 = 248;
      goto LABEL_20;
    case 18:
    case 21:
      pixelWriter_10 = 2;
      pixelWriter_12 = 131079;
      pixelWriter_16 = 589821;
      pixelWriter_20 = 248;
      pixelWriter_24 = 248;
      pixelWriter_28 = 248;
      pixelWriter_32 = 0x80;
      goto LABEL_21;
    case 19:
      pixelWriter_10 = 2;
      pixelWriter_12 = 4;
      pixelWriter_16 = 589820;
      pixelWriter_20 = 240;
      pixelWriter_24 = 240;
      pixelWriter_28 = 240;
      pixelWriter_32 = -16;
      goto LABEL_21;
    case 24:
    case 25:
      pixelWriter_10 = 8;
      pixelWriter_12 = 0x100000;
      pixelWriter_16 = 3145760;
      pixelWriter_20 = 0xFFFF;
      pixelWriter_24 = 0xFFFF;
      pixelWriter_28 = 0xFFFF;
      pixelWriter_32 = -1;
      goto LABEL_21;
    case 27:
      pixelWriter_10 = 4;
      pixelWriter_12 = 0;
      pixelWriter_16 = 0;
      pixelWriter_20 = -1;
      goto LABEL_19;
    case 29:
      pixelWriter_10 = 16;
      pixelWriter_12 = 0x200000;
      pixelWriter_16 = (int)&loc_60003E + 2;
      pixelWriter_20 = -1;
      pixelWriter_24 = -1;
      pixelWriter_28 = -1;
      pixelWriter_32 = -1;
      goto LABEL_21;
    default:
      if ( `CPixelWriter::SetPixelMemory'::`10'::format_error_printed[v7] == 0 )
      {
        _Msg(a1: "CPixelWriter::SetPixelMemory:  Unsupported image format %i\n", v7);
        `CPixelWriter::SetPixelMemory'::`10'::format_error_printed[v8] = 1;
      }
      pixelWriter_10 = 0;
      pixelWriter_12 = 0;
      pixelWriter_16 = 0;
LABEL_18:
      pixelWriter_20 = 255;
LABEL_19:
      pixelWriter_24 = 0;
      pixelWriter_28 = 0;
LABEL_20:
      pixelWriter_32 = 0;
LABEL_21:
      y = 0;
      if ( nHeight > 0 )
      {
        v43 = (unsigned __int16)pVTFTexture;
        v51 = -1;
        v52 = x;
        while ( 1 )
        {
          pixelWriter_4 = v52;
          if ( v5->_vpanel != 0 )
          {
            v9 = *(float *)&v5->_panelName.m_Storage.m_Memory.m_nGrowSize;
            p_actionSignalTargetDar = (float *)&v5[-1]._actionSignalTargetDar;
            v11 = *((_DWORD *)&v5[-1]._actionSignalTargetDar + 114);
            vecHSV.x = v9;
            vecHSV.y = p_actionSignalTargetDar[117];
            vecHSV.z = p_actionSignalTargetDar[118];
            TreeColumnWidth = CElementTreeViewListControl::GetTreeColumnWidth(this: (CProceduralTexturePanel *)p_actionSignalTargetDar);
            *(&vecHSV.x + v11) = (float)(v51 + TreeColumnWidth) * 0.0039215689;
            if ( *((_DWORD *)p_actionSignalTargetDar + 114) == 0 )
            {
              if ( vecHSV.x != -1.0 )
                vecHSV.x = vecHSV.x * 360.0;
              vecHSV.y = 1.0;
              vecHSV.z = 1.0;
            }
            HSVtoRGB(hsv: &vecHSV, &rgb);
            v13 = (int)(float)((float)(rgb.x * 255.0) + 0.5);
            v14 = (int)(float)((float)(rgb.y * 255.0) + 0.5);
            v15 = (int)(float)((float)(rgb.z * 255.0) + 0.5);
            if ( v13 >= 0 )
            {
              if ( v13 > 255 )
                LOBYTE(v13) = -1;
            }
            else
            {
              LOBYTE(v13) = 0;
            }
            LOBYTE(v16) = v13;
            if ( v14 >= 0 )
            {
              LOBYTE(v17) = -1;
              if ( v14 <= 255 )
                v17 = (int)(float)((float)(rgb.y * 255.0) + 0.5);
            }
            else
            {
              LOBYTE(v17) = 0;
            }
            if ( v15 >= 0 )
            {
              if ( v15 > 255 )
                LOBYTE(v15) = -1;
            }
            else
            {
              LOBYTE(v15) = 0;
            }
          }
          else
          {
            m_nAllocationCount = v5->_panelName.m_Storage.m_Memory.m_nAllocationCount;
            BYTE2(pVTFTexture) = BYTE2(v5->_panelName.m_Storage.m_Memory.m_nAllocationCount);
            LOWORD(pVTFTexture) = m_nAllocationCount;
            LOBYTE(v17) = CElementTreeViewListControl::GetTreeColumnWidth(this: (CColorZPreview *)((char *)v5 - 380));
            *((_BYTE *)&pVTFTexture + (unsigned int)v5->_panelName.m_Storage.m_Memory.m_pMemory) = -1 - y + v17;
            LOBYTE(v15) = BYTE2(pVTFTexture);
            LOBYTE(v17) = BYTE1(pVTFTexture);
            LOBYTE(v16) = (_BYTE)pVTFTexture;
          }
          x = 0;
          if ( nWidth > 0 )
          {
            v19 = (unsigned __int8)v15;
            v20 = (unsigned __int8)v17;
            v21 = pixelWriter_10;
            v16 = (unsigned __int8)v16;
            v22 = pixelWriter_10;
            v54 = v19;
            v45 = v20;
            v44 = (unsigned __int8)v16;
            v50 = pixelWriter_10;
            while ( 1 )
            {
              if ( v21 != 0 )
              {
                if ( v21 >= 5u )
                {
                  v26 = ((unsigned __int64)(v16 & (unsigned int)pixelWriter_20) << pixelWriter_12)
                      | ((unsigned __int64)(v20 & (unsigned int)pixelWriter_24) << SBYTE2(pixelWriter_12));
                  v27 = v54 & (unsigned int)pixelWriter_28;
                  if ( (__int16)pixelWriter_16 <= 0 )
                    v28 = v27 >> -(char)pixelWriter_16;
                  else
                    v28 = v27 << pixelWriter_16;
                  v41 = HIDWORD(v28);
                  v29 = v28;
                  v30 = (unsigned __int64)pixelWriter_32 << SBYTE2(pixelWriter_16);
                  LODWORD(v26) = v29 | v30 | v26;
                  HIDWORD(v26) |= v41 | HIDWORD(v30);
                  if ( v50 == 6 )
                  {
                    *(_DWORD *)pixelWriter_4 = v26;
                    *(_WORD *)(pixelWriter_4 + 4) = WORD2(v26);
                  }
                  else if ( v50 == 8 )
                  {
                    *(_QWORD *)pixelWriter_4 = v26;
                  }
                }
                else
                {
                  v23 = v19 & pixelWriter_28;
                  if ( (__int16)pixelWriter_16 <= 0 )
                    v24 = v23 >> -(char)pixelWriter_16;
                  else
                    v24 = v23 << pixelWriter_16;
                  v25 = v24
                      | (pixelWriter_32 << SBYTE2(pixelWriter_16))
                      | ((v16 & pixelWriter_20) << pixelWriter_12)
                      | ((v20 & pixelWriter_24) << SBYTE2(pixelWriter_12));
                  switch ( v22 )
                  {
                    case 1:
                      *(_BYTE *)pixelWriter_4 = v25;
                      break;
                    case 2:
                      *(_WORD *)pixelWriter_4 = v25;
                      break;
                    case 3:
                      *(_WORD *)pixelWriter_4 = v25;
                      *(_BYTE *)(pixelWriter_4 + 2) = BYTE2(v25);
                      break;
                    case 4:
                      *(_DWORD *)pixelWriter_4 = v25;
                      break;
                    default:
                      break;
                  }
                }
              }
              v22 = v50;
              pixelWriter_4 += v50;
              if ( ++x >= nWidth )
                break;
              v20 = v45;
              v16 = v44;
              v19 = v54;
              v21 = pixelWriter_10;
            }
          }
          v52 += v43;
          --v51;
          if ( ++y >= nHeight )
            break;
          v5 = v46;
        }
      }
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C44B0
// Name: private: void CColorZPreview::UpdateColorFromMouse(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorZPreview::UpdateColorFromMouse(CColorZPreview *this, int x, float y)
{
  float v4; // xmm0_4
  int TreeColumnWidth; // eax
  int v6; // ebx
  ColorChannel_t m_Channel; // esi
  int v8; // eax
  bool v9; // zf
  KeyValues *v10; // eax
  KeyValues *v11; // esi
  Vector *p_vecHSV; // edx
  unsigned __int8 b; // dl
  unsigned __int8 v14; // bl
  KeyValues *v15; // eax
  KeyValues *v16; // esi
  Vector rgb; // [esp+10h] [ebp-24h] BYREF
  Vector vecHSV; // [esp+1Ch] [ebp-18h] BYREF
  int w; // [esp+28h] [ebp-Ch] BYREF
  int h; // [esp+2Ch] [ebp-8h] BYREF
  Color c; // [esp+30h] [ebp-4h]

  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  h -= 12;
  v4 = (float)(LODWORD(y) - 6) / (float)(h - 1);
  if ( v4 >= 0.0 )
  {
    if ( v4 <= 1.0 )
      y = (float)(LODWORD(y) - 6) / (float)(h - 1);
    else
      y = 1.0;
  }
  else
  {
    y = 0.0;
  }
  TreeColumnWidth = CElementTreeViewListControl::GetTreeColumnWidth(this);
  v6 = (int)(float)((float)((float)(TreeColumnWidth - 1) * y) + 0.5);
  if ( this->m_Type != COLOR_TYPE_RGB )
  {
    m_Channel = this->m_Channel;
    vecHSV = this->m_CurrentHSVColor;
    v8 = CElementTreeViewListControl::GetTreeColumnWidth(this);
    v9 = this->m_Channel == CHANNEL_RED;
    *(&vecHSV.x + m_Channel) = (float)(v8 - v6 - 1) * 0.0039215689;
    if ( v9 && vecHSV.x != -1.0 )
      vecHSV.x = vecHSV.x * 360.0;
    v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v10 != nullptr )
      v11 = KeyValues::KeyValues(this: v10, setName: "HSVSelected");
    else
      v11 = nullptr;
    KeyValues::SetFloat(this: v11, keyName: "hue", value: vecHSV.x);
    KeyValues::SetFloat(this: v11, keyName: "saturation", value: vecHSV.y);
    KeyValues::SetFloat(this: v11, keyName: "value", value: vecHSV.z);
    this->PostActionSignal(this, a2: v11);
    HSVtoRGB(hsv: &vecHSV, &rgb);
    VectorToRGB888(inVector: &rgb, outColor: (RGB888_t *)&y);
    p_vecHSV = &vecHSV;
  }
  else
  {
    b = this->m_CurrentColor.b;
    LOWORD(y) = *(_WORD *)&this->m_CurrentColor.r;
    BYTE2(y) = b;
    *((_BYTE *)&y + this->m_Channel) = -1 - v6 + CElementTreeViewListControl::GetTreeColumnWidth(this);
    v14 = LOBYTE(y);
    *(_WORD *)c._color = LOWORD(y);
    c._color[2] = BYTE2(y);
    c._color[3] = -1;
    v15 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v15 != nullptr )
      v16 = KeyValues::KeyValues(this: v15, setName: "ColorSelected");
    else
      v16 = nullptr;
    KeyValues::SetColor(this: v16, keyName: "color", value: c);
    this->PostActionSignal(this, a2: v16);
    vecHSV.x = (float)v14 * 0.0039215689;
    vecHSV.y = (float)BYTE1(y) * 0.0039215689;
    vecHSV.z = (float)BYTE2(y) * 0.0039215689;
    RGBtoHSV(rgb: &vecHSV, hsv: &rgb);
    p_vecHSV = &rgb;
  }
  CColorZPreview::SetColor(this, color: (const RGB888_t *)&y, hsvColor: p_vecHSV);
}

//------------------------------------------------------------------------------
// Address: 0x004C4740
// Name: public: virtual void CColorZPreview::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorZPreview::OnMousePressed(CColorZPreview *this, const char *code)
{
  const char *v2; // edi
  unsigned int (__thiscall *GetVPanel)(vgui::IClientPanel *); // edx
  vgui::IInput *v5; // edi
  vgui::IInput_vtbl *v6; // ebx
  int v7; // eax
  int x; // [esp+8h] [ebp-4h] BYREF

  v2 = code;
  vgui::Panel::OnMousePressed(this, panelName: code);
  if ( v2 == (const char *)107 && !this->m_bDraggingMouse )
  {
    GetVPanel = this->GetVPanel;
    this->m_bDraggingMouse = true;
    v5 = g_pVGuiInput;
    v6 = g_pVGuiInput->__vftable;
    v7 = GetVPanel(this);
    v6->SetMouseCapture(this: v5, a2: v7);
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: (int *)&code);
    vgui::Panel::ScreenToLocal(this, &x, y: (int *)&code);
    CColorZPreview::UpdateColorFromMouse(this, x, y: *(float *)&code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C47C0
// Name: public: virtual void CColorZPreview::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorZPreview::OnCursorMoved(CColorZPreview *this, int x, KeyValues *y)
{
  BlankImage::SetSize((vgui::TreeView *)this, itemIndex: x, msg: y);
  if ( this->m_bDraggingMouse )
    CColorZPreview::UpdateColorFromMouse(this, x, y: *(float *)&y);
}

//------------------------------------------------------------------------------
// Address: 0x004C47F0
// Name: public: void CColorPickerPanel::SetInitialColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerPanel::SetInitialColor(CColorPickerPanel *this, Color initialColor)
{
  __int16 v3; // dx
  Vector *p_m_CurrentHSVColor; // edi
  Vector rgb; // [esp+0h] [ebp-10h] BYREF
  __int16 v6; // [esp+Ch] [ebp-4h]

  this->m_InitialColor.r = initialColor._color[0];
  this->m_InitialColor.g = initialColor._color[1];
  this->m_InitialColor.b = initialColor._color[2];
  this->m_CurrentAlpha = initialColor._color[3];
  this->m_InitialAlpha = initialColor._color[3];
  v3 = *(_WORD *)&this->m_InitialColor.r;
  *(_WORD *)&this->m_CurrentColor.r = v3;
  this->m_CurrentColor.b = initialColor._color[2];
  rgb.x = (float)(unsigned __int8)v3 * 0.0039215689;
  v6 = v3;
  rgb.y = (float)HIBYTE(v3) * 0.0039215689;
  p_m_CurrentHSVColor = &this->m_CurrentHSVColor;
  rgb.z = (float)initialColor._color[2] * 0.0039215689;
  RGBtoHSV(&rgb, hsv: &this->m_CurrentHSVColor);
  if ( p_m_CurrentHSVColor->x == -1.0 )
    p_m_CurrentHSVColor->x = 0.0;
  CColorPickerPanel::OnColorChanged(this, pChanged: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004C48D0
// Name: public: virtual void CColorPickerPanel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerPanel::OnMousePressed(CColorPickerPanel *this, const char *code)
{
  const char *v2; // edi
  unsigned __int8 b; // dl
  unsigned __int8 m_InitialAlpha; // cl
  int tall; // [esp+8h] [ebp-14h] BYREF
  int cy; // [esp+Ch] [ebp-10h] BYREF
  int cw; // [esp+10h] [ebp-Ch] BYREF
  int v9; // [esp+14h] [ebp-8h] BYREF
  int y; // [esp+18h] [ebp-4h] BYREF

  v2 = code;
  vgui::Panel::OnMousePressed(this, panelName: code);
  if ( v2 == (const char *)107 )
  {
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: (int *)&code, a3: &y);
    vgui::Panel::ScreenToLocal(this, x: (int *)&code, &y);
    vgui::Panel::GetBounds(this: this->m_pInitialColor, x: &v9, y: &cy, wide: &cw, &tall);
    if ( v9 <= (int)code && cw + v9 > (int)code && cy <= y && tall + cy > y )
    {
      b = this->m_InitialColor.b;
      *(_WORD *)&this->m_CurrentColor.r = *(_WORD *)&this->m_InitialColor.r;
      m_InitialAlpha = this->m_InitialAlpha;
      this->m_CurrentColor.b = b;
      this->m_CurrentAlpha = m_InitialAlpha;
      RGBtoHSV(rgb: &this->m_CurrentColor, hsv: &this->m_CurrentHSVColor);
      if ( this->m_CurrentHSVColor.x == -1.0 )
        this->m_CurrentHSVColor.x = 0.0;
      CColorPickerPanel::OnColorChanged(this, pChanged: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C49B0
// Name: private: virtual void CColorPickerPanel::OnHSVSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerPanel::OnHSVSelected(CColorPickerPanel *this, KeyValues *data)
{
  Vector rgb; // [esp+10h] [ebp-Ch] BYREF

  this->m_CurrentHSVColor.x = KeyValues::GetFloat(this: data, keyName: "hue", defaultValue: 0.0);
  this->m_CurrentHSVColor.y = KeyValues::GetFloat(this: data, keyName: "saturation", defaultValue: 0.0);
  this->m_CurrentHSVColor.z = KeyValues::GetFloat(this: data, keyName: "value", defaultValue: 0.0);
  HSVtoRGB(hsv: &this->m_CurrentHSVColor, &rgb);
  VectorToRGB888(inVector: &rgb, outColor: &this->m_CurrentColor);
  CColorPickerPanel::OnColorChanged(this, pChanged: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004C4A40
// Name: private: virtual void CColorPickerPanel::OnColorSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerPanel::OnColorSelected(CColorPickerPanel *this, KeyValues *data)
{
  unsigned __int8 v3; // ah
  unsigned __int8 v4; // dl
  Vector rgb; // [esp+8h] [ebp-14h] BYREF
  Color c; // [esp+14h] [ebp-8h] BYREF
  Color defaultColor; // [esp+18h] [ebp-4h] BYREF
  __int16 dataa; // [esp+24h] [ebp+8h]

  defaultColor = 0;
  KeyValues::GetColor(this: data, result: &c, keyName: "color", &defaultColor);
  v3 = c._color[1];
  v4 = c._color[2];
  this->m_CurrentColor.r = c._color[0];
  this->m_CurrentColor.b = v4;
  this->m_CurrentColor.g = v3;
  dataa = *(_WORD *)&this->m_CurrentColor.r;
  rgb.x = (float)(unsigned __int8)dataa * 0.0039215689;
  rgb.y = (float)HIBYTE(dataa) * 0.0039215689;
  rgb.z = (float)v4 * 0.0039215689;
  RGBtoHSV(&rgb, hsv: &this->m_CurrentHSVColor);
  CColorPickerPanel::OnColorChanged(this, pChanged: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004C4AF0
// Name: private: virtual void CColorPickerPanel::OnTextChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerPanel::OnTextChanged(CColorPickerPanel *this, KeyValues *data)
{
  vgui::TextEntry *Ptr; // eax
  vgui::TextEntry *m_pRedText; // ecx
  vgui::TextEntry *v5; // esi
  Vector *p_m_CurrentHSVColor; // ebx
  int v7; // eax
  __int16 v8; // dx
  int b; // eax
  vgui::TextEntry *m_pGreenText; // ecx
  int v11; // eax
  __int16 v12; // cx
  int v13; // edx
  vgui::TextEntry *m_pBlueText; // ecx
  int v15; // eax
  vgui::TextEntry *m_pAlphaText; // ecx
  int v17; // eax
  vgui::TextEntry *m_pHueText; // ecx
  int v19; // eax
  vgui::TextEntry *m_pSaturationText; // ecx
  int v21; // eax
  vgui::TextEntry *m_pValueText; // ecx
  int v23; // eax
  char buf[256]; // [esp+Ch] [ebp-110h] BYREF
  float flHue; // [esp+10Ch] [ebp-10h]
  Vector rgb; // [esp+110h] [ebp-Ch] BYREF
  vgui::Panel *pPanel; // [esp+124h] [ebp+8h]

  Ptr = (vgui::TextEntry *)KeyValues::GetPtr(this: data, keyName: "panel", defaultValue: nullptr);
  m_pRedText = this->m_pRedText;
  v5 = Ptr;
  p_m_CurrentHSVColor = &this->m_CurrentHSVColor;
  pPanel = Ptr;
  flHue = this->m_CurrentHSVColor.x;
  if ( Ptr == m_pRedText )
  {
    m_pRedText->GetText_2(this: m_pRedText, a2: buf, a3: 256);
    v7 = atoi(nptr: buf);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    this->m_CurrentColor.r = v7;
    v8 = *(_WORD *)&this->m_CurrentColor.r;
    b = this->m_CurrentColor.b;
    rgb.x = (float)(unsigned __int8)v8 * 0.0039215689;
    rgb.y = (float)HIBYTE(v8) * 0.0039215689;
    rgb.z = (float)b * 0.0039215689;
    RGBtoHSV(&rgb, hsv: &this->m_CurrentHSVColor);
  }
  else
  {
    m_pGreenText = this->m_pGreenText;
    if ( Ptr == m_pGreenText )
    {
      m_pGreenText->GetText_2(this: m_pGreenText, a2: buf, a3: 256);
      v11 = atoi(nptr: buf);
      if ( v11 >= 0 )
      {
        if ( v11 > 255 )
          LOBYTE(v11) = -1;
      }
      else
      {
        LOBYTE(v11) = 0;
      }
      this->m_CurrentColor.g = v11;
      v12 = *(_WORD *)&this->m_CurrentColor.r;
      v13 = this->m_CurrentColor.b;
      rgb.x = (float)(unsigned __int8)v12 * 0.0039215689;
      rgb.y = (float)HIBYTE(v12) * 0.0039215689;
      rgb.z = (float)v13 * 0.0039215689;
      RGBtoHSV(&rgb, hsv: &this->m_CurrentHSVColor);
    }
    else
    {
      m_pBlueText = this->m_pBlueText;
      if ( Ptr == m_pBlueText )
      {
        m_pBlueText->GetText_2(this: m_pBlueText, a2: buf, a3: 256);
        v15 = atoi(nptr: buf);
        if ( v15 >= 0 )
        {
          if ( v15 > 255 )
            LOBYTE(v15) = -1;
        }
        else
        {
          LOBYTE(v15) = 0;
        }
        this->m_CurrentColor.b = v15;
        RGBtoHSV(rgb: &this->m_CurrentColor, hsv: &this->m_CurrentHSVColor);
      }
      else
      {
        m_pAlphaText = this->m_pAlphaText;
        if ( Ptr == m_pAlphaText )
        {
          m_pAlphaText->GetText_2(this: m_pAlphaText, a2: buf, a3: 256);
          v17 = atoi(nptr: buf);
          if ( v17 >= 0 )
          {
            if ( v17 > 255 )
              LOBYTE(v17) = -1;
            this->m_CurrentAlpha = v17;
          }
          else
          {
            this->m_CurrentAlpha = 0;
          }
        }
        else
        {
          m_pHueText = this->m_pHueText;
          if ( Ptr == m_pHueText )
          {
            m_pHueText->GetText_2(this: m_pHueText, a2: buf, a3: 256);
            v19 = atoi(nptr: buf);
            if ( v19 >= 0 )
            {
              if ( v19 > 360 )
                v19 = 360;
              p_m_CurrentHSVColor->x = (float)v19;
            }
            else
            {
              p_m_CurrentHSVColor->x = (float)0;
            }
          }
          else
          {
            m_pSaturationText = this->m_pSaturationText;
            if ( Ptr == m_pSaturationText )
            {
              m_pSaturationText->GetText_2(this: m_pSaturationText, a2: buf, a3: 256);
              v21 = atoi(nptr: buf);
              if ( v21 >= 0 )
              {
                if ( v21 > 100 )
                  v21 = 100;
              }
              else
              {
                v21 = 0;
              }
              this->m_CurrentHSVColor.y = (float)v21 * 0.0099999998;
            }
            else
            {
              m_pValueText = this->m_pValueText;
              if ( Ptr != m_pValueText )
                goto LABEL_44;
              m_pValueText->GetText_2(this: m_pValueText, a2: buf, a3: 256);
              v23 = atoi(nptr: buf);
              if ( v23 >= 0 )
              {
                if ( v23 > 100 )
                  v23 = 100;
              }
              else
              {
                v23 = 0;
              }
              this->m_CurrentHSVColor.z = (float)v23 * 0.0099999998;
            }
          }
          HSVtoRGB(hsv: &this->m_CurrentHSVColor, rgb: &this->m_CurrentColor);
          v5 = (vgui::TextEntry *)pPanel;
        }
      }
    }
  }
LABEL_44:
  if ( p_m_CurrentHSVColor->x == -1.0 )
    p_m_CurrentHSVColor->x = flHue;
  CColorPickerPanel::OnColorChanged(this, pChanged: v5);
}

//------------------------------------------------------------------------------
// Address: 0x004C4E90
// Name: public: virtual struct vgui::PanelMessageMap __near * CColorPickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CColorPickerFrame::GetMessageMap(CColorPickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CColorPickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorPickerFrame::GetMessageMap'::`2'::s_pMap;
  `CColorPickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CColorPickerFrame");
  `CColorPickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C4EC0
// Name: public: virtual struct PanelAnimationMap __near * CColorPickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CColorPickerFrame::GetAnimMap(CColorPickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CColorPickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x004C4ED0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CColorPickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CColorPickerFrame::GetKBMap(CColorPickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CColorPickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorPickerFrame::GetKBMap'::`2'::s_pMap;
  `CColorPickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CColorPickerFrame");
  `CColorPickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C4F00
// Name: public: void CColorPickerFrame::DoModal(class Color,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerFrame::DoModal(CColorPickerFrame *this, Color initialColor, KeyValues *pContextKeys)
{
  KeyValues *m_pContextKeys; // ecx

  m_pContextKeys = this->m_pContextKeys;
  if ( m_pContextKeys != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeys);
    this->m_pContextKeys = nullptr;
  }
  CColorPickerPanel::SetInitialColor(this: this->m_pPicker, initialColor);
  this->m_pContextKeys = pContextKeys;
  vgui::Frame::DoModal(this);
}

//------------------------------------------------------------------------------
// Address: 0x004C4FA0
// Name: public: static void CColorPickerPanel::PanelMessageFunc_OnRadioButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CColorPickerPanel::PanelMessageFunc_OnRadioButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`CColorPickerPanel::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded )
  {
    `CColorPickerPanel::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CColorPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "RadioButtonChecked";
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
// Address: 0x004C5030
// Name: public: static void CColorPickerPanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CColorPickerPanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CColorPickerPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CColorPickerPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CColorPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextChanged";
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
// Address: 0x004C50C0
// Name: public: static void CColorPickerPanel::PanelMessageFunc_OnHSVSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CColorPickerPanel::PanelMessageFunc_OnHSVSelected::InitVar(int a1@<ebp>)
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
  if ( !`CColorPickerPanel::PanelMessageFunc_OnHSVSelected::InitVar'::`2'::bAdded )
  {
    `CColorPickerPanel::PanelMessageFunc_OnHSVSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CColorPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "HSVSelected";
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
// Address: 0x004C5150
// Name: public: static void CColorPickerPanel::PanelMessageFunc_OnColorSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CColorPickerPanel::PanelMessageFunc_OnColorSelected::InitVar(int a1@<ebp>)
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
  if ( !`CColorPickerPanel::PanelMessageFunc_OnColorSelected::InitVar'::`2'::bAdded )
  {
    `CColorPickerPanel::PanelMessageFunc_OnColorSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CColorPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ColorSelected";
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
// Address: 0x004C51E0
// Name: public: CColorPickerPanel::CColorPickerPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CColorPickerPanel *__thiscall CColorPickerPanel::CColorPickerPanel(
        CColorPickerPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CColorXYPreview *v7; // eax
  CColorXYPreview *v8; // eax
  CColorZPreview *v9; // eax
  CColorZPreview *v10; // eax
  CColorXYPreview *m_pColorXYPreview; // ecx
  vgui::RadioButton *v12; // eax
  vgui::RadioButton *v13; // eax
  vgui::RadioButton *v14; // eax
  vgui::RadioButton *v15; // eax
  vgui::RadioButton *v16; // eax
  vgui::RadioButton *v17; // eax
  vgui::RadioButton *v18; // eax
  vgui::RadioButton *v19; // eax
  vgui::RadioButton *v20; // eax
  vgui::RadioButton *v21; // eax
  vgui::RadioButton *v22; // eax
  vgui::RadioButton *v23; // eax
  vgui::TextEntry *v24; // eax
  vgui::TextEntry *v25; // eax
  vgui::TextEntry *v26; // eax
  vgui::TextEntry *v27; // eax
  vgui::TextEntry *v28; // eax
  vgui::TextEntry *v29; // eax
  vgui::TextEntry *v30; // eax
  vgui::TextEntry *v31; // eax
  vgui::TextEntry *v32; // eax
  vgui::TextEntry *v33; // eax
  vgui::TextEntry *v34; // eax
  vgui::TextEntry *v35; // eax
  vgui::TextEntry *v36; // eax
  vgui::TextEntry *v37; // eax
  vgui::Panel *v38; // eax
  vgui::Panel *v39; // eax
  vgui::Panel *v40; // eax
  vgui::Panel *v41; // eax
  vgui::Panel *m_pInitialColor; // ecx
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->__vftable = (CColorPickerPanel_vtbl *)&CColorPickerPanel::`vftable';
  if ( `CColorPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CColorPickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CColorPickerPanel");
    v4->pfnClassName = CColorPickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CColorPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CColorPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CColorPickerPanel");
    v5->pfnClassName = CColorPickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CColorPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CColorPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CColorPickerPanel");
    v6->pfnClassName = CColorPickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CColorPickerPanel::PanelMessageFunc_OnRadioButtonChecked::InitVar(a1: (int)&savedregs);
  CColorPickerPanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  CColorPickerPanel::PanelMessageFunc_OnHSVSelected::InitVar(a1: (int)&savedregs);
  CColorPickerPanel::PanelMessageFunc_OnColorSelected::InitVar(a1: (int)&savedregs);
  v7 = (CColorXYPreview *)MemAlloc_Alloc(nSize: 0x1E4u);
  if ( v7 != nullptr )
    v8 = CColorXYPreview::CColorXYPreview(this: v7, pParent: this, pName: "ColorXYPreview");
  else
    v8 = nullptr;
  this->m_pColorXYPreview = v8;
  v9 = (CColorZPreview *)MemAlloc_Alloc(nSize: 0x1E0u);
  if ( v9 != nullptr )
    v10 = CColorZPreview::CColorZPreview(this: v9, pParent: this, pName: "ColorZPreview");
  else
    v10 = nullptr;
  m_pColorXYPreview = this->m_pColorXYPreview;
  this->m_pColorZPreview = v10;
  m_pColorXYPreview->AddActionSignalTarget_2(this: m_pColorXYPreview, a2: this);
  v12 = (vgui::RadioButton *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v12 != nullptr )
    v13 = vgui::RadioButton::RadioButton(this: v12, parent: this, panelName: "HueRadio", text: "H");
  else
    v13 = nullptr;
  this->m_pHueRadio = v13;
  v14 = (vgui::RadioButton *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v14 != nullptr )
    v15 = vgui::RadioButton::RadioButton(this: v14, parent: this, panelName: "SaturationRadio", text: "S");
  else
    v15 = nullptr;
  this->m_pSaturationRadio = v15;
  v16 = (vgui::RadioButton *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v16 != nullptr )
    v17 = vgui::RadioButton::RadioButton(this: v16, parent: this, panelName: "ValueRadio", text: "V");
  else
    v17 = nullptr;
  this->m_pValueRadio = v17;
  v18 = (vgui::RadioButton *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v18 != nullptr )
    v19 = vgui::RadioButton::RadioButton(this: v18, parent: this, panelName: "RedRadio", text: "R");
  else
    v19 = nullptr;
  this->m_pRedRadio = v19;
  v20 = (vgui::RadioButton *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v20 != nullptr )
    v21 = vgui::RadioButton::RadioButton(this: v20, parent: this, panelName: "GreenRadio", text: "G");
  else
    v21 = nullptr;
  this->m_pGreenRadio = v21;
  v22 = (vgui::RadioButton *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v22 != nullptr )
    v23 = vgui::RadioButton::RadioButton(this: v22, parent: this, panelName: "BlueRadio", text: "B");
  else
    v23 = nullptr;
  this->m_pBlueRadio = v23;
  v24 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v24 != nullptr )
    v25 = vgui::TextEntry::TextEntry(this: v24, parent: this, panelName: "HueText");
  else
    v25 = nullptr;
  this->m_pHueText = v25;
  v26 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v26 != nullptr )
    v27 = vgui::TextEntry::TextEntry(this: v26, parent: this, panelName: "SaturationText");
  else
    v27 = nullptr;
  this->m_pSaturationText = v27;
  v28 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v28 != nullptr )
    v29 = vgui::TextEntry::TextEntry(this: v28, parent: this, panelName: "ValueText");
  else
    v29 = nullptr;
  this->m_pValueText = v29;
  v30 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v30 != nullptr )
    v31 = vgui::TextEntry::TextEntry(this: v30, parent: this, panelName: "RedText");
  else
    v31 = nullptr;
  this->m_pRedText = v31;
  v32 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v32 != nullptr )
    v33 = vgui::TextEntry::TextEntry(this: v32, parent: this, panelName: "GreenText");
  else
    v33 = nullptr;
  this->m_pGreenText = v33;
  v34 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v34 != nullptr )
    v35 = vgui::TextEntry::TextEntry(this: v34, parent: this, panelName: "BlueText");
  else
    v35 = nullptr;
  this->m_pBlueText = v35;
  v36 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v36 != nullptr )
    v37 = vgui::TextEntry::TextEntry(this: v36, parent: this, panelName: "AlphaText");
  else
    v37 = nullptr;
  this->m_pAlphaText = v37;
  v38 = (vgui::Panel *)MemAlloc_Alloc(nSize: 0x14Cu);
  if ( v38 != nullptr )
    v39 = vgui::Panel::Panel(this: v38, parent: this, panelName: "InitialColor");
  else
    v39 = nullptr;
  this->m_pInitialColor = v39;
  v40 = (vgui::Panel *)MemAlloc_Alloc(nSize: 0x14Cu);
  if ( v40 != nullptr )
    v41 = vgui::Panel::Panel(this: v40, parent: this, panelName: "CurrentColor");
  else
    v41 = nullptr;
  m_pInitialColor = this->m_pInitialColor;
  this->m_pCurrentColor = v41;
  m_pInitialColor->SetVisible(this: m_pInitialColor, a2: true);
  this->m_pCurrentColor->SetVisible(this: this->m_pCurrentColor, a2: true);
  this->m_pInitialColor->SetPaintBackgroundEnabled(this: this->m_pInitialColor, a2: true);
  this->m_pCurrentColor->SetPaintBackgroundEnabled(this: this->m_pCurrentColor, a2: true);
  this->m_pInitialColor->SetMouseInputEnabled(this: this->m_pInitialColor, a2: false);
  vgui::Panel::SetMouseInputEnabled(this, state: true);
  CColorPickerPanel::SetInitialColor(this, initialColor: (Color)-1);
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "resource/colorpicker.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004C5610
// Name: public: virtual struct vgui::PanelMessageMap __near * CColorPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CColorPickerPanel::GetMessageMap(CColorPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CColorPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CColorPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CColorPickerPanel");
  `CColorPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C5640
// Name: public: virtual struct PanelAnimationMap __near * CColorPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CColorPickerPanel::GetAnimMap(CColorPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CColorPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x004C5650
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CColorPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CColorPickerPanel::GetKBMap(CColorPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CColorPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorPickerPanel::GetKBMap'::`2'::s_pMap;
  `CColorPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CColorPickerPanel");
  `CColorPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004C5680
// Name: public: CColorPickerFrame::CColorPickerFrame(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CColorPickerFrame *__thiscall CColorPickerFrame::CColorPickerFrame(
        CColorPickerFrame *this,
        vgui::Panel *pParent,
        const char *pTitle)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CColorPickerPanel *v7; // eax
  CColorPickerPanel *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  int w; // [esp+8h] [ebp-4h] BYREF

  vgui::Frame::Frame(this, parent: pParent, panelName: "ColorPickerFrame", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CColorPickerFrame_vtbl *)&CColorPickerFrame::`vftable';
  if ( `CColorPickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CColorPickerFrame::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CColorPickerFrame");
    v4->pfnClassName = CColorPickerFrame::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CColorPickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CColorPickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CColorPickerFrame");
    v5->pfnClassName = CColorPickerFrame::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CColorPickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CColorPickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CColorPickerFrame");
    v6->pfnClassName = CColorPickerFrame::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  this->m_pContextKeys = nullptr;
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  v7 = (CColorPickerPanel *)MemAlloc_Alloc(nSize: 0x1DCu);
  if ( v7 != nullptr )
    v8 = CColorPickerPanel::CColorPickerPanel(this: v7, pParent: this, pName: "ColorPicker");
  else
    v8 = nullptr;
  this->m_pPicker = v8;
  v8->AddActionSignalTarget_2(this: v8, a2: this);
  v9 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "OkButton",
            text: "Ok",
            pActionSignalTarget: this,
            pCmd: "Ok");
  else
    v10 = nullptr;
  this->m_pOpenButton = v10;
  v11 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: this,
            panelName: "CancelButton",
            text: "#FileOpenDialog_Cancel",
            pActionSignalTarget: this,
            pCmd: "Cancel");
  else
    v12 = nullptr;
  this->m_pCancelButton = v12;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "resource/colorpickerframe.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Panel::GetSize(this, wide: &w, tall: (int *)&pParent);
  vgui::Panel::SetMinimumSize(this, wide: w, tall: (int)pParent);
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1010AD50
// Name: public: virtual struct DmxElementUnpackStructure_t const __near * vgui::Button::GetUnpackStructure(void)const
// Source: rtti_class
//------------------------------------------------------------------------------
const DmxElementUnpackStructure_t *__thiscall vgui::Button::GetUnpackStructure(vgui::Button *this)
{
  return vgui::Button::s_pUnpackParams;
}

//------------------------------------------------------------------------------
// Address: 0x102DF2E0
// Name: public: virtual class Color vgui::Button::GetButtonFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Button::GetButtonFgColor(vgui::Button *this, Color *result)
{
  Color *v3; // eax
  float v4; // xmm0_4
  float v5; // xmm0_4
  long double v6; // [esp+0h] [ebp-8h]
  Color cBlendedColor; // [esp+4h] [ebp-4h]

  if ( (this->_buttonFlags.m_nFlags & 0x200) != 0 )
  {
    if ( (this->_buttonFlags.m_nFlags & 2) != 0 )
    {
      HIDWORD(v6) = this->_depressedFgColor;
    }
    else if ( (this->_buttonFlags.m_nFlags & 1) != 0 )
    {
      HIDWORD(v6) = this->_armedFgColor;
    }
    else
    {
      HIDWORD(v6) = this->_defaultFgColor;
    }
    v4 = (float)g_pVGuiSystem->GetTimeMillis(this: g_pVGuiSystem) * 0.0099999998;
    __libm_sse2_sin(x: v6);
    v5 = (float)(v4 + 1.0) * 0.5;
    if ( (this->_buttonFlags.m_nFlags & 0x200) != 0 )
    {
      cBlendedColor._color[0] = (int)(float)((float)((float)this->_blinkFgColor._color[0] * (float)(1.0 - v5))
                                           + (float)((float)cBlendedColor._color[0] * v5));
      cBlendedColor._color[1] = (int)(float)((float)((float)this->_blinkFgColor._color[1] * (float)(1.0 - v5))
                                           + (float)((float)cBlendedColor._color[1] * v5));
      cBlendedColor._color[2] = (int)(float)((float)((float)this->_blinkFgColor._color[2] * (float)(1.0 - v5))
                                           + (float)((float)cBlendedColor._color[2] * v5));
      cBlendedColor._color[3] = (int)(float)((float)((float)this->_blinkFgColor._color[3] * (float)(1.0 - v5))
                                           + (float)((float)cBlendedColor._color[3] * v5));
    }
    *result = cBlendedColor;
    return result;
  }
  else
  {
    v3 = result;
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
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x102DF480
// Name: public: virtual class Color vgui::Button::GetButtonBgColor(void)
// Source: rtti_class
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
// Address: 0x102E8380
// Name: public: virtual class Color vgui::Label::GetFgColor(void)
// Source: rtti_class
//------------------------------------------------------------------------------
Color *__thiscall vgui::Label::GetFgColor(vgui::Label *this, Color *result)
{
  vgui::Panel::GetFgColor(this, result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104C5680
// Name: public: static char const __near * CColorPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CColorPickerPanel::GetPanelClassName()
{
  return "CColorPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x104C5690
// Name: public: static char const __near * CColorPickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CColorPickerFrame::GetPanelClassName()
{
  return "CColorPickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x104C56A0
// Name: public: static char const __near * CColorPickerButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CColorPickerButton::GetPanelClassName()
{
  return "CColorPickerButton";
}

//------------------------------------------------------------------------------
// Address: 0x104C5720
// Name: public: static char const __near * CColorXYPreview::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CColorXYPreview::GetPanelClassName()
{
  return "CColorXYPreview";
}

//------------------------------------------------------------------------------
// Address: 0x104C5730
// Name: private: void CColorXYPreview::ComputeHSVColorForPoint(int,int,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorXYPreview::ComputeHSVColorForPoint(CColorXYPreview *this, int x, int y, Vector *vscHSV)
{
  float *v5; // ebx

  *vscHSV = this->m_CurrentHSVColor;
  *(&vscHSV->x + CColorXYPreview::s_pHSVRemapX[this->m_Channel]) = (float)x * 0.0039215689;
  v5 = &vscHSV->x + CColorXYPreview::s_pHSVRemapY[this->m_Channel];
  *v5 = (float)(CElementTreeViewListControl::GetTreeColumnWidth(this) - y - 1) * 0.0039215689;
  if ( vscHSV->y == 0.0 )
    vscHSV->x = -1.0;
  if ( this->m_Channel != CHANNEL_RED && vscHSV->x != -1.0 )
    vscHSV->x = vscHSV->x * 360.0;
}

//------------------------------------------------------------------------------
// Address: 0x104C57F0
// Name: public: virtual void CColorXYPreview::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorXYPreview::Paint(CColorXYPreview *this)
{
  float z; // eax
  ColorChannel_t v3; // ecx
  ColorChannel_t v4; // edx
  int v5; // ebx
  int TreeColumnWidth; // eax
  int v7; // edi
  int v8; // esi
  int v9; // edi
  Vector vecHSVNormalized; // [esp+Ch] [ebp-18h] BYREF
  int h; // [esp+18h] [ebp-Ch] BYREF
  int w; // [esp+1Ch] [ebp-8h] BYREF
  float *v13; // [esp+20h] [ebp-4h]

  CProceduralTexturePanel::Paint(this);
  if ( this->m_Type != COLOR_TYPE_RGB )
  {
    z = this->m_CurrentHSVColor.z;
    *(_QWORD *)&vecHSVNormalized.x = *(_QWORD *)&this->m_CurrentHSVColor.x;
    vecHSVNormalized.z = z;
    if ( vecHSVNormalized.x != -1.0 )
      vecHSVNormalized.x = vecHSVNormalized.x * 0.70833331;
    v3 = CColorXYPreview::s_pHSVRemapX[this->m_Channel];
    v4 = CColorXYPreview::s_pHSVRemapY[this->m_Channel];
    vecHSVNormalized.y = vecHSVNormalized.y * 255.0;
    vecHSVNormalized.z = vecHSVNormalized.z * 255.0;
    v5 = (int)(float)(*(&vecHSVNormalized.x + v3) + 0.5);
    v13 = &vecHSVNormalized.x + v4;
    TreeColumnWidth = CElementTreeViewListControl::GetTreeColumnWidth(this);
    v7 = TreeColumnWidth - (int)(float)(*v13 + 0.5);
  }
  else
  {
    v5 = *(&this->m_CurrentColor.r + CColorXYPreview::s_pRGBRemapX[this->m_Channel]);
    v7 = CElementTreeViewListControl::GetTreeColumnWidth(this)
       - *(&this->m_CurrentColor.r + CColorXYPreview::s_pRGBRemapY[this->m_Channel]);
  }
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  v8 = (int)(float)((float)((float)((float)w * (float)v5) * 0.0039215689) + 0.5);
  v9 = (int)(float)((float)((float)((float)h * (float)(v7 - 1)) * 0.0039215689) + 0.5);
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
  g_pVGuiSurface->DrawOutlinedCircle(this: g_pVGuiSurface, a2: v8, a3: v9, a4: 5, a5: 8);
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 0, a3: 0, a4: 0, a5: 255);
  g_pVGuiSurface->DrawOutlinedCircle(this: g_pVGuiSurface, a2: v8, a3: v9, a4: 6, a5: 8);
}

//------------------------------------------------------------------------------
// Address: 0x104C59C0
// Name: public: virtual void CColorXYPreview::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorXYPreview::OnMouseReleased(CColorXYPreview *this, ButtonCode_t code)
{
  CToolEntitySprinkle::RenderTool2D((vgui::TreeView *)this, itemIndex: code);
  if ( code == KEY_COUNT && this->m_bDraggingMouse )
  {
    this->m_bDraggingMouse = false;
    g_pVGuiInput->SetMouseCapture(this: g_pVGuiInput, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C5A00
// Name: public: static char const __near * CColorZPreview::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CColorZPreview::GetPanelClassName()
{
  return "CColorZPreview";
}

//------------------------------------------------------------------------------
// Address: 0x104C5A10
// Name: public: void CColorZPreview::SetMode(enum ColorType_t,enum ColorChannel_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorZPreview::SetMode(CColorZPreview *this, ColorType_t type, ColorChannel_t channel)
{
  if ( this->m_Type != type || this->m_Channel != channel )
  {
    this->m_Type = type;
    this->m_Channel = channel;
    CProceduralTexturePanel::DownloadTexture(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C5A40
// Name: public: void CColorZPreview::SetColor(struct RGB888_t const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorZPreview::SetColor(CColorZPreview *this, const RGB888_t *color, const Vector *hsvColor)
{
  if ( color->r != this->m_CurrentColor.r
    || color->g != this->m_CurrentColor.g
    || color->b != this->m_CurrentColor.b
    || hsvColor->x != this->m_CurrentHSVColor.x
    || hsvColor->y != this->m_CurrentHSVColor.y
    || hsvColor->z != this->m_CurrentHSVColor.z )
  {
    this->m_CurrentColor = *color;
    this->m_CurrentHSVColor = *hsvColor;
    CProceduralTexturePanel::DownloadTexture(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C5AE0
// Name: public: virtual void CColorZPreview::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorZPreview::PerformLayout(CColorZPreview *this)
{
  Rect_t r; // [esp+4h] [ebp-18h] BYREF
  int h; // [esp+14h] [ebp-8h] BYREF
  int w; // [esp+18h] [ebp-4h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  r.x = 6;
  r.y = 6;
  r.width = w - 12;
  r.height = h - 12;
  CProceduralTexturePanel::SetPaintRect(this, pPaintRect: &r);
}

//------------------------------------------------------------------------------
// Address: 0x104C5B30
// Name: public: virtual void CColorZPreview::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorZPreview::OnMouseReleased(CColorZPreview *this, ButtonCode_t code)
{
  CToolEntitySprinkle::RenderTool2D((vgui::TreeView *)this, itemIndex: code);
  if ( code == KEY_COUNT && this->m_bDraggingMouse )
  {
    this->m_bDraggingMouse = false;
    g_pVGuiInput->SetMouseCapture(this: g_pVGuiInput, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C5B70
// Name: public: virtual void CColorZPreview::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorZPreview::Paint(CColorZPreview *this)
{
  float z; // eax
  ColorChannel_t m_Channel; // ecx
  int TreeColumnWidth; // eax
  int v5; // esi
  float v6; // xmm0_4
  int v7; // esi
  int py[3]; // [esp+8h] [ebp-30h] BYREF
  int px[3]; // [esp+14h] [ebp-24h] BYREF
  Vector vecHSVNormalized; // [esp+20h] [ebp-18h] BYREF
  int w; // [esp+2Ch] [ebp-Ch] BYREF
  float *v12; // [esp+30h] [ebp-8h]
  int h; // [esp+34h] [ebp-4h] BYREF

  CProceduralTexturePanel::Paint(this);
  if ( this->m_Type != COLOR_TYPE_RGB )
  {
    z = this->m_CurrentHSVColor.z;
    *(_QWORD *)&vecHSVNormalized.x = *(_QWORD *)&this->m_CurrentHSVColor.x;
    vecHSVNormalized.z = z;
    if ( vecHSVNormalized.x != -1.0 )
      vecHSVNormalized.x = vecHSVNormalized.x * 0.70833331;
    m_Channel = this->m_Channel;
    vecHSVNormalized.y = vecHSVNormalized.y * 255.0;
    vecHSVNormalized.z = vecHSVNormalized.z * 255.0;
    v12 = &vecHSVNormalized.x + m_Channel;
    TreeColumnWidth = CElementTreeViewListControl::GetTreeColumnWidth(this);
    v5 = TreeColumnWidth - (int)(float)(*v12 + 0.5);
  }
  else
  {
    v5 = CElementTreeViewListControl::GetTreeColumnWidth(this) - *(&this->m_CurrentColor.r + this->m_Channel);
  }
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  v6 = (float)(h - 12);
  h -= 12;
  v7 = (int)(float)((float)((float)(v6 * (float)(v5 - 1)) * 0.0039215689) + 0.5);
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
  py[1] = v7 + 12;
  py[0] = v7;
  px[0] = 0;
  px[1] = 0;
  px[2] = 6;
  py[2] = v7 + 6;
  g_pVGuiSurface->DrawPolyLine(this: g_pVGuiSurface, a2: px, a3: py, a4: 3);
  px[1] = w - 1;
  px[0] = w - 1;
  px[2] = w - 7;
  g_pVGuiSurface->DrawPolyLine(this: g_pVGuiSurface, a2: px, a3: py, a4: 3);
}

//------------------------------------------------------------------------------
// Address: 0x104C5D00
// Name: private: void CColorPickerPanel::UpdatePreviewColors(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerPanel::UpdatePreviewColors(CColorPickerPanel *this)
{
  Color c; // [esp+4h] [ebp-4h]

  *(RGB888_t *)c._color = this->m_InitialColor;
  c._color[3] = -1;
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pInitialColor->SetBgColor)(a1: this->m_pInitialColor, a2: c);
  *(RGB888_t *)c._color = this->m_CurrentColor;
  c._color[3] = -1;
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pCurrentColor->SetBgColor)(a1: this->m_pCurrentColor, a2: c);
}

//------------------------------------------------------------------------------
// Address: 0x104C5D80
// Name: public: virtual void CColorPickerPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerPanel::ApplySchemeSettings(CColorPickerPanel *this, vgui::IScheme *pScheme)
{
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  CColorPickerPanel::UpdatePreviewColors(this);
}

//------------------------------------------------------------------------------
// Address: 0x104C5DA0
// Name: private: virtual void CColorPickerPanel::OnRadioButtonChecked(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerPanel::OnRadioButtonChecked(CColorPickerPanel *this, KeyValues *pKeyValues)
{
  vgui::RadioButton *Ptr; // eax
  CColorXYPreview *m_pColorXYPreview; // ecx
  CColorZPreview *m_pColorZPreview; // ecx
  int v6; // edi
  CColorXYPreview *v7; // ecx
  CColorZPreview *v8; // ecx

  Ptr = (vgui::RadioButton *)KeyValues::GetPtr(this: pKeyValues, keyName: "panel", defaultValue: nullptr);
  if ( Ptr == this->m_pRedRadio )
  {
    m_pColorXYPreview = this->m_pColorXYPreview;
    if ( m_pColorXYPreview->m_Type != COLOR_TYPE_RGB || m_pColorXYPreview->m_Channel != CHANNEL_RED )
    {
      m_pColorXYPreview->m_Type = COLOR_TYPE_RGB;
      m_pColorXYPreview->m_Channel = CHANNEL_RED;
      CProceduralTexturePanel::DownloadTexture(this: m_pColorXYPreview);
    }
    m_pColorZPreview = this->m_pColorZPreview;
    if ( m_pColorZPreview->m_Type != COLOR_TYPE_RGB || m_pColorZPreview->m_Channel != CHANNEL_RED )
    {
      m_pColorZPreview->m_Type = COLOR_TYPE_RGB;
      m_pColorZPreview->m_Channel = CHANNEL_RED;
      CProceduralTexturePanel::DownloadTexture(this: m_pColorZPreview);
    }
    return;
  }
  if ( Ptr == this->m_pGreenRadio )
  {
    v6 = 1;
    goto LABEL_12;
  }
  if ( Ptr == this->m_pBlueRadio )
  {
    v6 = 2;
LABEL_12:
    v7 = this->m_pColorXYPreview;
    if ( v7->m_Type != COLOR_TYPE_RGB || v7->m_Channel != v6 )
    {
      v7->m_Type = COLOR_TYPE_RGB;
      v7->m_Channel = v6;
      CProceduralTexturePanel::DownloadTexture(this: v7);
    }
    v8 = this->m_pColorZPreview;
    if ( v8->m_Type != COLOR_TYPE_RGB || v8->m_Channel != v6 )
    {
      v8->m_Type = COLOR_TYPE_RGB;
      v8->m_Channel = v6;
      CProceduralTexturePanel::DownloadTexture(this: v8);
    }
    return;
  }
  if ( Ptr == this->m_pHueRadio )
  {
    CColorZPreview::SetMode(this: (CColorZPreview *)this->m_pColorXYPreview, type: COLOR_TYPE_HSV, channel: CHANNEL_RED);
    CColorZPreview::SetMode(this: this->m_pColorZPreview, type: COLOR_TYPE_HSV, channel: CHANNEL_RED);
  }
  else if ( Ptr == this->m_pSaturationRadio )
  {
    CColorZPreview::SetMode(
      this: (CColorZPreview *)this->m_pColorXYPreview,
      type: COLOR_TYPE_HSV,
      channel: CHANNEL_GREEN);
    CColorZPreview::SetMode(this: this->m_pColorZPreview, type: COLOR_TYPE_HSV, channel: CHANNEL_GREEN);
  }
  else if ( Ptr == this->m_pValueRadio )
  {
    CColorZPreview::SetMode(
      this: (CColorZPreview *)this->m_pColorXYPreview,
      type: COLOR_TYPE_HSV,
      channel: CHANNEL_BLUE);
    CColorZPreview::SetMode(this: this->m_pColorZPreview, type: COLOR_TYPE_HSV, channel: CHANNEL_BLUE);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C5F20
// Name: private: void CColorPickerPanel::OnColorChanged(class vgui::TextEntry __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerPanel::OnColorChanged(CColorPickerPanel *this, vgui::TextEntry *pChanged)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  char temp[256]; // [esp+8h] [ebp-100h] BYREF

  if ( pChanged != this->m_pRedText )
  {
    V_snprintf(pDest: temp, maxLen: 256, pFormat: "%d", this->m_CurrentColor.r);
    this->m_pRedText->SetText(this: this->m_pRedText, a2: temp);
  }
  if ( pChanged != this->m_pGreenText )
  {
    V_snprintf(pDest: temp, maxLen: 256, pFormat: "%d", this->m_CurrentColor.g);
    this->m_pGreenText->SetText(this: this->m_pGreenText, a2: temp);
  }
  if ( pChanged != this->m_pBlueText )
  {
    V_snprintf(pDest: temp, maxLen: 256, pFormat: "%d", this->m_CurrentColor.b);
    this->m_pBlueText->SetText(this: this->m_pBlueText, a2: temp);
  }
  if ( pChanged != this->m_pAlphaText )
  {
    V_snprintf(pDest: temp, maxLen: 256, pFormat: "%d", this->m_CurrentAlpha);
    this->m_pAlphaText->SetText(this: this->m_pAlphaText, a2: temp);
  }
  if ( pChanged != this->m_pHueText )
  {
    V_snprintf(pDest: temp, maxLen: 256, pFormat: "%d", (int)(float)(this->m_CurrentHSVColor.x + 0.5));
    this->m_pHueText->SetText(this: this->m_pHueText, a2: temp);
  }
  if ( pChanged != this->m_pSaturationText )
  {
    V_snprintf(pDest: temp, maxLen: 256, pFormat: "%d", (int)(float)((float)(this->m_CurrentHSVColor.y * 100.0) + 0.5));
    this->m_pSaturationText->SetText(this: this->m_pSaturationText, a2: temp);
  }
  if ( pChanged != this->m_pValueText )
  {
    V_snprintf(pDest: temp, maxLen: 256, pFormat: "%d", (int)(float)((float)(this->m_CurrentHSVColor.z * 100.0) + 0.5));
    this->m_pValueText->SetText(this: this->m_pValueText, a2: temp);
  }
  CColorZPreview::SetColor(
    this: (CColorZPreview *)this->m_pColorXYPreview,
    color: &this->m_CurrentColor,
    hsvColor: &this->m_CurrentHSVColor);
  CColorZPreview::SetColor(
    this: this->m_pColorZPreview,
    color: &this->m_CurrentColor,
    hsvColor: &this->m_CurrentHSVColor);
  CColorPickerPanel::UpdatePreviewColors(this);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "command", firstKey: "command", firstValue: "preview");
  else
    v4 = nullptr;
  this->PostActionSignal(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x104C61A0
// Name: public: virtual void CColorPickerFrame::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerFrame::OnCommand(CColorPickerFrame *this, const char *pCommand)
{
  CColorPickerPanel *m_pPicker; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  KeyValues *v6; // eax
  CColorPickerPanel *v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  KeyValues *m_pContextKeys; // ecx
  KeyValues *Copy; // eax
  Color c; // [esp+10h] [ebp+8h]
  Color ca; // [esp+10h] [ebp+8h]

  if ( _V_stricmp(s1: pCommand, s2: "Ok") == 0 )
  {
    m_pPicker = this->m_pPicker;
    c._color[0] = m_pPicker->m_CurrentColor.r;
    *(_WORD *)&c._color[1] = *(_WORD *)&m_pPicker->m_CurrentColor.g;
    c._color[3] = m_pPicker->m_CurrentAlpha;
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "ColorPickerPicked");
    else
      v5 = nullptr;
    KeyValues::SetColor(this: v5, keyName: "color", value: c);
    if ( this->m_pContextKeys != nullptr )
    {
      KeyValues::AddSubKey(this: v5, pSubkey: this->m_pContextKeys);
      this->m_pContextKeys = nullptr;
    }
LABEL_7:
    this->CloseModal(this);
    this->PostActionSignal(this, a2: v5);
    return;
  }
  if ( _V_stricmp(s1: pCommand, s2: "Cancel") == 0 )
  {
    g_pVGuiInput->ReleaseAppModalSurface(this: g_pVGuiInput);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v5 = KeyValues::KeyValues(this: v6, setName: "ColorPickerCancel");
    else
      v5 = nullptr;
    if ( this->m_pContextKeys != nullptr )
    {
      KeyValues::AddSubKey(this: v5, pSubkey: this->m_pContextKeys);
      this->m_pContextKeys = nullptr;
    }
    goto LABEL_7;
  }
  if ( _V_stricmp(s1: pCommand, s2: "Preview") != 0 )
  {
    vgui::Frame::OnCommand(this, command: pCommand);
  }
  else
  {
    v7 = this->m_pPicker;
    ca._color[0] = v7->m_CurrentColor.r;
    *(_WORD *)&ca._color[1] = *(_WORD *)&v7->m_CurrentColor.g;
    ca._color[3] = v7->m_CurrentAlpha;
    v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v8 != nullptr )
      v9 = KeyValues::KeyValues(this: v8, setName: "ColorPickerPreview");
    else
      v9 = nullptr;
    KeyValues::SetColor(this: v9, keyName: "color", value: ca);
    m_pContextKeys = this->m_pContextKeys;
    if ( m_pContextKeys != nullptr )
    {
      Copy = KeyValues::MakeCopy(this: m_pContextKeys);
      KeyValues::AddSubKey(this: v9, pSubkey: Copy);
    }
    this->PostActionSignal(this, a2: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C6390
// Name: private: virtual void CColorPickerButton::OnCancelled(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerButton::OnCancelled(CColorPickerButton *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi

  this->SetSelected(this, a2: false);
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "ColorPickerCancel");
  else
    v3 = nullptr;
  KeyValues::SetColor(this: v3, keyName: "startingColor", value: this->m_CurrentColor);
  this->PostActionSignal(this, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x104C6410
// Name: public: virtual struct vgui::PanelMessageMap __near * CColorPickerButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CColorPickerButton::GetMessageMap(CColorPickerButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CColorPickerButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorPickerButton::GetMessageMap'::`2'::s_pMap;
  `CColorPickerButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CColorPickerButton");
  `CColorPickerButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104C6440
// Name: public: virtual struct PanelAnimationMap __near * CColorPickerButton::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CColorPickerButton::GetAnimMap(CColorPickerButton *this)
{
  return FindOrAddPanelAnimationMap(className: "CColorPickerButton");
}

//------------------------------------------------------------------------------
// Address: 0x104C6450
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CColorPickerButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CColorPickerButton::GetKBMap(CColorPickerButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CColorPickerButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorPickerButton::GetKBMap'::`2'::s_pMap;
  `CColorPickerButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CColorPickerButton");
  `CColorPickerButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104C6480
// Name: VectorToRGB888
// Source: json
//------------------------------------------------------------------------------
void __usercall VectorToRGB888(const Vector *inVector@<eax>, RGB888_t *outColor@<esi>)
{
  int v2; // ecx
  int v3; // edx
  int v4; // eax

  v2 = (int)(float)((float)(inVector->x * 255.0) + 0.5);
  v3 = (int)(float)((float)(inVector->y * 255.0) + 0.5);
  v4 = (int)(float)((float)(inVector->z * 255.0) + 0.5);
  if ( v2 >= 0 )
  {
    if ( v2 > 255 )
      LOBYTE(v2) = -1;
  }
  else
  {
    LOBYTE(v2) = 0;
  }
  outColor->r = v2;
  if ( v3 >= 0 )
  {
    if ( v3 > 255 )
      LOBYTE(v3) = -1;
  }
  else
  {
    LOBYTE(v3) = 0;
  }
  outColor->g = v3;
  if ( v4 >= 0 )
  {
    if ( v4 > 255 )
      LOBYTE(v4) = -1;
    outColor->b = v4;
  }
  else
  {
    outColor->b = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C6530
// Name: public: CColorXYPreview::CColorXYPreview(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CColorXYPreview *__thiscall CColorXYPreview::CColorXYPreview(
        CColorXYPreview *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  unsigned int v7; // eax

  CProceduralTexturePanel::CProceduralTexturePanel(this, pParent, pName);
  this->CProceduralTexturePanel::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CColorXYPreview_vtbl *)&CColorXYPreview::`vftable'{for `vgui::EditablePanel'};
  this->CProceduralTexturePanel::ITextureRegenerator::__vftable = (ITextureRegenerator_vtbl *)&CColorXYPreview::`vftable'{for `ITextureRegenerator'};
  if ( `CColorXYPreview::ChainToMap'::`2'::chained == 0 )
  {
    `CColorXYPreview::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CColorXYPreview");
    v4->pfnClassName = CColorXYPreview::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CProceduralTexturePanel");
  }
  if ( `CColorXYPreview::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CColorXYPreview::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CColorXYPreview");
    v5->pfnClassName = CColorXYPreview::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CProceduralTexturePanel");
  }
  if ( `CColorXYPreview::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CColorXYPreview::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CColorXYPreview");
    v6->pfnClassName = CColorXYPreview::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CProceduralTexturePanel");
  }
  CProceduralTexturePanel::Init(this, nWidth: 256, nHeight: 256, bAllocateImageBuffer: false);
  *(_WORD *)&this->m_CurrentColor.g = -1;
  this->m_CurrentColor.r = -1;
  if ( this->m_Type != COLOR_TYPE_HSV || this->m_Channel != CHANNEL_RED )
  {
    this->m_Type = COLOR_TYPE_HSV;
    this->m_Channel = CHANNEL_RED;
    CProceduralTexturePanel::DownloadTexture(this);
  }
  vgui::Panel::SetMouseInputEnabled(this, state: true);
  v7 = g_pVGuiSurface->CreateCursorFromFile(this: g_pVGuiSurface, a2: "resource/colorpicker.cur", a3: nullptr);
  this->m_hPickerCursor = v7;
  vgui::Panel::SetCursor(this, cursor: v7);
  this->m_bDraggingMouse = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104C6680
// Name: public: virtual struct vgui::PanelMessageMap __near * CColorXYPreview::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CColorXYPreview::GetMessageMap(CColorXYPreview *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CColorXYPreview::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorXYPreview::GetMessageMap'::`2'::s_pMap;
  `CColorXYPreview::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CColorXYPreview");
  `CColorXYPreview::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104C66B0
// Name: public: virtual struct PanelAnimationMap __near * CColorXYPreview::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CColorXYPreview::GetAnimMap(CColorXYPreview *this)
{
  return FindOrAddPanelAnimationMap(className: "CColorXYPreview");
}

//------------------------------------------------------------------------------
// Address: 0x104C66C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CColorXYPreview::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CColorXYPreview::GetKBMap(CColorXYPreview *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CColorXYPreview::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorXYPreview::GetKBMap'::`2'::s_pMap;
  `CColorXYPreview::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CColorXYPreview");
  `CColorXYPreview::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104C6720
// Name: public: virtual void CColorXYPreview::RegenerateTextureBits(class ITexture __near *,class IVTFTexture __near *,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorXYPreview::RegenerateTextureBits(
        CColorXYPreview *this,
        ITexture *pTexture,
        IVTFTexture *pVTFTexture,
        Rect_t *pRect)
{
  IVTFTexture *v4; // esi
  CColorXYPreview *v5; // ebx
  void (__thiscall *ComputeMipLevelDimensions)(IVTFTexture *, int, int *, int *, int *); // edx
  unsigned __int16 v7; // di
  int v8; // eax
  int v9; // edx
  _BYTE *v10; // edi
  int v11; // edx
  int v12; // ecx
  unsigned __int8 *m_pMemory; // eax
  int *p_m_nAllocationCount; // esi
  int v15; // ebx
  int TreeColumnWidth; // eax
  float v17; // xmm0_4
  int v18; // eax
  int v19; // ecx
  float v20; // xmm2_4
  int v21; // esi
  char v22; // dl
  int v23; // eax
  char v24; // cl
  int v25; // eax
  char v26; // al
  unsigned __int8 *v27; // edx
  int v28; // esi
  int v29; // eax
  unsigned int v30; // edx
  unsigned int v31; // edx
  int v32; // eax
  unsigned __int64 v33; // rdi
  __int64 v34; // rax
  __int64 v35; // rax
  int v36; // ebx
  unsigned __int64 v37; // rax
  int pixelWriter; // [esp+Ch] [ebp-70h]
  _BYTE *pixelWriter_4; // [esp+10h] [ebp-6Ch]
  unsigned __int8 pixelWriter_10; // [esp+16h] [ebp-66h]
  int pixelWriter_12; // [esp+18h] [ebp-64h]
  int pixelWriter_16; // [esp+1Ch] [ebp-60h]
  char pixelWriter_20; // [esp+20h] [ebp-5Ch]
  char pixelWriter_24; // [esp+24h] [ebp-58h]
  int pixelWriter_28; // [esp+28h] [ebp-54h]
  unsigned __int8 pixelWriter_32; // [esp+2Ch] [ebp-50h]
  Vector rgb; // [esp+30h] [ebp-4Ch] BYREF
  Vector vecHSV; // [esp+3Ch] [ebp-40h] BYREF
  int v49; // [esp+4Ch] [ebp-30h]
  int nDepth; // [esp+50h] [ebp-2Ch] BYREF
  int v51; // [esp+54h] [ebp-28h]
  int nHeight; // [esp+58h] [ebp-24h] BYREF
  int v53; // [esp+5Ch] [ebp-20h]
  CColorXYPreview *v54; // [esp+60h] [ebp-1Ch]
  int nWidth; // [esp+64h] [ebp-18h] BYREF
  int v56; // [esp+68h] [ebp-14h]
  int v57; // [esp+6Ch] [ebp-10h]
  int y; // [esp+70h] [ebp-Ch]
  int x; // [esp+74h] [ebp-8h]
  int v60; // [esp+78h] [ebp-4h]

  v4 = pVTFTexture;
  v5 = this;
  ComputeMipLevelDimensions = pVTFTexture->ComputeMipLevelDimensions;
  v54 = this;
  ComputeMipLevelDimensions(this: pVTFTexture, a2: 0, a3: &nWidth, a4: &nHeight, a5: &nDepth);
  v7 = v4->RowSizeInBytes(this: v4, a2: 0);
  pixelWriter = (int)v4->ImageData_2(this: v4, a2: 0, a3: 0, a4: 0);
  switch ( v4->Format(this: v4) )
  {
    case IMAGE_FORMAT_RGBA8888:
    case IMAGE_FORMAT_UVWQ8888:
      v8 = 255;
      pixelWriter_10 = 4;
      pixelWriter_12 = 0x80000;
      pixelWriter_16 = 1572880;
      pixelWriter_20 = -1;
      goto LABEL_18;
    case IMAGE_FORMAT_BGR888:
      v8 = 255;
      pixelWriter_10 = 3;
      pixelWriter_12 = 524304;
      pixelWriter_16 = 0;
      pixelWriter_20 = -1;
      pixelWriter_32 = 0;
      goto LABEL_19;
    case IMAGE_FORMAT_I8:
      pixelWriter_10 = 1;
      goto LABEL_16;
    case IMAGE_FORMAT_A8:
      v8 = 0;
      pixelWriter_10 = 1;
      pixelWriter_12 = 0;
      pixelWriter_16 = 0;
      pixelWriter_20 = 0;
      pixelWriter_32 = -1;
      goto LABEL_19;
    case IMAGE_FORMAT_BGRA8888:
      v8 = 255;
      pixelWriter_10 = 4;
      pixelWriter_12 = 524304;
      pixelWriter_16 = 1572864;
      pixelWriter_20 = -1;
      goto LABEL_18;
    case IMAGE_FORMAT_BGRX8888:
      v8 = 255;
      pixelWriter_10 = 4;
      pixelWriter_12 = 524304;
      pixelWriter_16 = 1572864;
      pixelWriter_20 = -1;
      pixelWriter_32 = 0;
      goto LABEL_19;
    case IMAGE_FORMAT_BGR565:
      v8 = 248;
      pixelWriter_10 = 2;
      pixelWriter_12 = 196616;
      pixelWriter_16 = 65533;
      pixelWriter_20 = -8;
      pixelWriter_24 = -4;
      pixelWriter_32 = 0;
      goto LABEL_20;
    case IMAGE_FORMAT_BGRX5551:
    case IMAGE_FORMAT_BGRA5551:
      v8 = 248;
      pixelWriter_10 = 2;
      pixelWriter_12 = 131079;
      pixelWriter_16 = 589821;
      pixelWriter_20 = -8;
      pixelWriter_32 = 0x80;
      goto LABEL_19;
    case IMAGE_FORMAT_BGRA4444:
      v8 = 240;
      pixelWriter_10 = 2;
      pixelWriter_12 = 4;
      pixelWriter_16 = 589820;
      pixelWriter_20 = -16;
      goto LABEL_18;
    case IMAGE_FORMAT_RGBA16161616F:
    case IMAGE_FORMAT_RGBA16161616:
      v8 = 0xFFFF;
      pixelWriter_10 = 8;
      pixelWriter_12 = 0x100000;
      pixelWriter_16 = 3145760;
      pixelWriter_20 = -1;
      goto LABEL_18;
    case IMAGE_FORMAT_R32F:
      pixelWriter_10 = 4;
      pixelWriter_20 = -1;
      goto LABEL_17;
    case IMAGE_FORMAT_RGBA32323232F:
      pixelWriter_10 = 16;
      pixelWriter_12 = 0x200000;
      pixelWriter_16 = 6291520;
      pixelWriter_20 = -1;
      pixelWriter_24 = -1;
      pixelWriter_28 = -1;
      pixelWriter_32 = -1;
      goto LABEL_21;
    case IMAGE_FORMAT_BGRA1010102:
      v8 = 1023;
      pixelWriter_10 = 4;
      pixelWriter_12 = 655380;
      pixelWriter_16 = 1966080;
      pixelWriter_20 = -1;
      pixelWriter_32 = 3;
      goto LABEL_19;
    default:
      pixelWriter_10 = 0;
LABEL_16:
      pixelWriter_20 = -1;
LABEL_17:
      pixelWriter_12 = 0;
      pixelWriter_16 = 0;
      v8 = 0;
LABEL_18:
      pixelWriter_32 = v8;
LABEL_19:
      pixelWriter_24 = v8;
LABEL_20:
      pixelWriter_28 = v8;
LABEL_21:
      y = 0;
      if ( nHeight > 0 )
      {
        v9 = v7;
        v10 = (_BYTE *)pixelWriter;
        v51 = v9;
        v11 = nWidth;
        v57 = -1;
        v53 = pixelWriter;
        do
        {
          v12 = 0;
          pixelWriter_4 = v10;
          x = 0;
          if ( v11 > 0 )
          {
            v60 = pixelWriter_10;
            while ( 1 )
            {
              if ( v5->_vpanel != 0 )
              {
                m_pMemory = v5->_panelName.m_Storage.m_Memory.m_pMemory;
                p_m_nAllocationCount = &v5[-1]._actionSignalTargetDar.m_Memory.m_nAllocationCount;
                vecHSV = *(Vector *)&v5->_panelName.m_Storage.m_Memory.m_nGrowSize;
                m_pMemory = (unsigned __int8 *)(2 * (_DWORD)m_pMemory);
                v15 = *(ColorChannel_t *)((char *)CColorXYPreview::s_pHSVRemapY + 2 * (_DWORD)m_pMemory);
                *(&vecHSV.x + *(ColorChannel_t *)((char *)CColorXYPreview::s_pHSVRemapX + 2 * (_DWORD)m_pMemory)) = (float)v12 * 0.0039215689;
                TreeColumnWidth = CElementTreeViewListControl::GetTreeColumnWidth(this: (CProceduralTexturePanel *)p_m_nAllocationCount);
                *(&vecHSV.x + v15) = (float)(v57 + TreeColumnWidth) * 0.0039215689;
                if ( vecHSV.y == 0.0 )
                {
                  v17 = -1.0;
                  vecHSV.x = -1.0;
                }
                else
                {
                  v17 = vecHSV.x;
                }
                if ( p_m_nAllocationCount[114] != 0 && v17 != -1.0 )
                  vecHSV.x = v17 * 360.0;
                HSVtoRGB(hsv: &vecHSV, &rgb);
                v18 = (int)(float)((float)(rgb.x * 255.0) + 0.5);
                v19 = (int)(float)((float)(rgb.y * 255.0) + 0.5);
                v20 = (float)(rgb.z * 255.0) + 0.5;
                v21 = (int)v20;
                if ( v18 >= 0 )
                {
                  if ( v18 > 255 )
                    LOBYTE(v18) = -1;
                }
                else
                {
                  LOBYTE(v18) = 0;
                }
                v22 = v18;
                if ( v19 >= 0 )
                {
                  LOBYTE(v23) = -1;
                  if ( v19 <= 255 )
                    v23 = (int)(float)((float)(rgb.y * 255.0) + 0.5);
                }
                else
                {
                  LOBYTE(v23) = 0;
                }
                v24 = v23;
                if ( v21 >= 0 )
                {
                  LOBYTE(v25) = -1;
                  if ( v21 <= 255 )
                    v25 = (int)v20;
                }
                else
                {
                  LOBYTE(v25) = 0;
                }
              }
              else
              {
                v26 = BYTE2(v5->_panelName.m_Storage.m_Memory.m_nAllocationCount);
                LOWORD(pVTFTexture) = v5->_panelName.m_Storage.m_Memory.m_nAllocationCount;
                v27 = v5->_panelName.m_Storage.m_Memory.m_pMemory;
                BYTE2(pVTFTexture) = v26;
                *((_BYTE *)&pVTFTexture + CColorXYPreview::s_pRGBRemapX[(_DWORD)v27]) = v12;
                LOBYTE(v25) = CElementTreeViewListControl::GetTreeColumnWidth(this: (CColorXYPreview *)((char *)v5 - 380));
                *((_BYTE *)&pVTFTexture + CColorXYPreview::s_pRGBRemapY[(int)v5->_panelName.m_Storage.m_Memory.m_pMemory]) = -1 - y + v25;
                LOBYTE(v25) = BYTE2(pVTFTexture);
                v24 = BYTE1(pVTFTexture);
                v22 = (char)pVTFTexture;
              }
              v28 = (unsigned __int8)v25;
              v56 = (unsigned __int8)v25;
              if ( pixelWriter_10 != 0 )
              {
                if ( pixelWriter_10 >= 5u )
                {
                  v33 = ((unsigned __int64)(unsigned __int8)(v24 & pixelWriter_24) << SBYTE2(pixelWriter_12))
                      | ((unsigned __int64)(unsigned __int8)(v22 & pixelWriter_20) << pixelWriter_12);
                  v34 = v56 & (unsigned int)pixelWriter_28;
                  if ( (__int16)pixelWriter_16 <= 0 )
                    v35 = v34 >> -(char)pixelWriter_16;
                  else
                    v35 = v34 << pixelWriter_16;
                  v49 = HIDWORD(v35);
                  v36 = v35;
                  v37 = (unsigned __int64)pixelWriter_32 << SBYTE2(pixelWriter_16);
                  LODWORD(v33) = v36 | v37 | v33;
                  HIDWORD(v33) |= v49 | HIDWORD(v37);
                  if ( v60 == 6 )
                  {
                    *(_DWORD *)pixelWriter_4 = v33;
                    *((_WORD *)pixelWriter_4 + 2) = WORD2(v33);
                  }
                  else if ( v60 == 8 )
                  {
                    *(_QWORD *)pixelWriter_4 = v33;
                  }
                  v10 = pixelWriter_4;
                }
                else
                {
                  v29 = ((unsigned __int8)(v24 & pixelWriter_24) << SBYTE2(pixelWriter_12))
                      | ((unsigned __int8)(v22 & pixelWriter_20) << pixelWriter_12);
                  v30 = v28 & pixelWriter_28;
                  if ( (__int16)pixelWriter_16 <= 0 )
                    v31 = v30 >> -(char)pixelWriter_16;
                  else
                    v31 = v30 << pixelWriter_16;
                  v32 = v31 | (pixelWriter_32 << SBYTE2(pixelWriter_16)) | v29;
                  switch ( v60 )
                  {
                    case 1:
                      *v10 = v32;
                      break;
                    case 2:
                      *(_WORD *)v10 = v32;
                      break;
                    case 3:
                      *(_WORD *)v10 = v32;
                      v10[2] = BYTE2(v32);
                      break;
                    case 4:
                      *(_DWORD *)v10 = v32;
                      break;
                    default:
                      break;
                  }
                }
              }
              v10 += v60;
              v11 = nWidth;
              v5 = v54;
              pixelWriter_4 = v10;
              if ( ++x >= nWidth )
                break;
              v12 = x;
            }
          }
          v10 = (_BYTE *)(v51 + v53);
          --v57;
          ++y;
          v53 += v51;
        }
        while ( y < nHeight );
      }
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C6CF0
// Name: private: void CColorXYPreview::UpdateColorFromMouse(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorXYPreview::UpdateColorFromMouse(CColorXYPreview *this, float x, float y)
{
  float v4; // xmm0_4
  float v5; // xmm1_4
  int ImageWidth; // eax
  int v7; // ebx
  int TreeColumnWidth; // eax
  bool v9; // zf
  float v10; // xmm0_4
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  Vector *p_rgb; // eax
  unsigned __int8 b; // al
  ColorChannel_t m_Channel; // ecx
  ColorChannel_t v16; // edx
  char v17; // al
  unsigned __int8 v18; // bl
  KeyValues *v19; // eax
  KeyValues *v20; // esi
  Vector rgb; // [esp+10h] [ebp-20h] BYREF
  Vector hsvColor; // [esp+1Ch] [ebp-14h] BYREF
  int v23; // [esp+28h] [ebp-8h] BYREF
  int h; // [esp+2Ch] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &h, tall: &v23);
  v4 = (float)SLODWORD(x) / (float)(h - 1);
  v5 = (float)SLODWORD(y) / (float)(v23 - 1);
  if ( v4 >= 0.0 )
  {
    if ( v4 <= 1.0 )
      x = (float)SLODWORD(x) / (float)(h - 1);
    else
      x = 1.0;
  }
  else
  {
    x = 0.0;
  }
  if ( v5 >= 0.0 )
  {
    if ( v5 <= 1.0 )
      y = (float)SLODWORD(y) / (float)(v23 - 1);
    else
      y = 1.0;
  }
  else
  {
    y = 0.0;
  }
  ImageWidth = CProceduralTexturePanel::GetImageWidth(this);
  v7 = (int)(float)((float)((float)(ImageWidth - 1) * x) + 0.5);
  TreeColumnWidth = CElementTreeViewListControl::GetTreeColumnWidth(this);
  v9 = this->m_Type == COLOR_TYPE_RGB;
  v10 = (float)((float)(TreeColumnWidth - 1) * y) + 0.5;
  LODWORD(y) = (int)v10;
  if ( v9 )
  {
    b = this->m_CurrentColor.b;
    m_Channel = this->m_Channel;
    LOWORD(x) = *(_WORD *)&this->m_CurrentColor.r;
    v16 = CColorXYPreview::s_pRGBRemapX[m_Channel];
    BYTE2(x) = b;
    *((_BYTE *)&x + v16) = v7;
    v17 = CElementTreeViewListControl::GetTreeColumnWidth(this);
    *((_BYTE *)&x + CColorXYPreview::s_pRGBRemapY[this->m_Channel]) = -1 - LOBYTE(y) + v17;
    v18 = LOBYTE(x);
    LOWORD(y) = LOWORD(x);
    BYTE2(y) = BYTE2(x);
    HIBYTE(y) = -1;
    v19 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v19 != nullptr )
      v20 = KeyValues::KeyValues(this: v19, setName: "ColorSelected");
    else
      v20 = nullptr;
    KeyValues::SetColor(this: v20, keyName: "color", value: LODWORD(y));
    this->PostActionSignal(this, a2: v20);
    hsvColor.x = (float)v18 * 0.0039215689;
    hsvColor.y = (float)BYTE1(x) * 0.0039215689;
    hsvColor.z = (float)BYTE2(x) * 0.0039215689;
    RGBtoHSV(rgb: &hsvColor, hsv: &rgb);
    p_rgb = &rgb;
  }
  else
  {
    CColorXYPreview::ComputeHSVColorForPoint(this, x: v7, y: (int)v10, vscHSV: &hsvColor);
    v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v11 != nullptr )
      v12 = KeyValues::KeyValues(this: v11, setName: "HSVSelected");
    else
      v12 = nullptr;
    KeyValues::SetFloat(this: v12, keyName: "hue", value: hsvColor.x);
    KeyValues::SetFloat(this: v12, keyName: "saturation", value: hsvColor.y);
    KeyValues::SetFloat(this: v12, keyName: "value", value: hsvColor.z);
    this->PostActionSignal(this, a2: v12);
    HSVtoRGB(hsv: &hsvColor, &rgb);
    VectorToRGB888(inVector: &rgb, outColor: (RGB888_t *)&x);
    p_rgb = &hsvColor;
  }
  CColorZPreview::SetColor((CColorZPreview *)this, color: (const RGB888_t *)&x, hsvColor: p_rgb);
}

//------------------------------------------------------------------------------
// Address: 0x104C6F80
// Name: public: virtual void CColorXYPreview::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorXYPreview::OnMousePressed(CColorXYPreview *this, int code)
{
  int v2; // edi
  unsigned int (__thiscall *GetVPanel)(vgui::IClientPanel *); // edx
  vgui::IInput *v5; // edi
  vgui::IInput_vtbl *v6; // ebx
  int v7; // eax
  int x; // [esp+8h] [ebp-4h] BYREF

  v2 = code;
  CToolEntitySprinkle::RenderTool2D((vgui::TreeView *)this, itemIndex: code);
  if ( v2 == 107 && !this->m_bDraggingMouse )
  {
    GetVPanel = this->GetVPanel;
    this->m_bDraggingMouse = true;
    v5 = g_pVGuiInput;
    v6 = g_pVGuiInput->__vftable;
    v7 = GetVPanel(this);
    v6->SetMouseCapture(this: v5, a2: v7);
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &code);
    vgui::Panel::ScreenToLocal(this, &x, y: &code);
    CColorXYPreview::UpdateColorFromMouse(this, x: *(float *)&x, y: *(float *)&code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C7000
// Name: public: virtual void CColorXYPreview::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorXYPreview::OnCursorMoved(CColorXYPreview *this, int x, KeyValues *y)
{
  BlankImage::SetSize((vgui::TreeView *)this, itemIndex: x, msg: y);
  if ( this->m_bDraggingMouse )
    CColorXYPreview::UpdateColorFromMouse(this, x: *(float *)&x, y: *(float *)&y);
}

//------------------------------------------------------------------------------
// Address: 0x104C7030
// Name: public: CColorZPreview::CColorZPreview(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CColorZPreview *__thiscall CColorZPreview::CColorZPreview(
        CColorZPreview *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  __int16 v7; // dx
  int b; // eax
  Vector vecRGB; // [esp+Ch] [ebp-Ch] BYREF

  CProceduralTexturePanel::CProceduralTexturePanel(this, pParent, pName);
  this->CProceduralTexturePanel::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CColorZPreview_vtbl *)&CColorZPreview::`vftable'{for `vgui::EditablePanel'};
  this->CProceduralTexturePanel::ITextureRegenerator::__vftable = (ITextureRegenerator_vtbl *)&CColorZPreview::`vftable'{for `ITextureRegenerator'};
  if ( `CColorZPreview::ChainToMap'::`2'::chained == 0 )
  {
    `CColorZPreview::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CColorZPreview");
    v4->pfnClassName = CColorZPreview::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CProceduralTexturePanel");
  }
  if ( `CColorZPreview::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CColorZPreview::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CColorZPreview");
    v5->pfnClassName = CColorZPreview::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CProceduralTexturePanel");
  }
  if ( `CColorZPreview::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CColorZPreview::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CColorZPreview");
    v6->pfnClassName = CColorZPreview::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CProceduralTexturePanel");
  }
  CProceduralTexturePanel::Init(this, nWidth: 8, nHeight: 256, bAllocateImageBuffer: false);
  *(_WORD *)&this->m_CurrentColor.g = -1;
  this->m_CurrentColor.r = -1;
  v7 = *(_WORD *)&this->m_CurrentColor.r;
  b = this->m_CurrentColor.b;
  vecRGB.x = (float)(unsigned __int8)v7 * 0.0039215689;
  vecRGB.y = (float)HIBYTE(v7) * 0.0039215689;
  vecRGB.z = (float)b * 0.0039215689;
  RGBtoHSV(rgb: &vecRGB, hsv: &this->m_CurrentHSVColor);
  this->m_bDraggingMouse = false;
  vgui::Panel::SetMouseInputEnabled(this, state: true);
  if ( this->m_Type != COLOR_TYPE_HSV || this->m_Channel != CHANNEL_RED )
  {
    this->m_Type = COLOR_TYPE_HSV;
    this->m_Channel = CHANNEL_RED;
    CProceduralTexturePanel::DownloadTexture(this);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104C71C0
// Name: public: virtual struct vgui::PanelMessageMap __near * CColorZPreview::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CColorZPreview::GetMessageMap(CColorZPreview *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CColorZPreview::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorZPreview::GetMessageMap'::`2'::s_pMap;
  `CColorZPreview::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CColorZPreview");
  `CColorZPreview::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104C71F0
// Name: public: virtual struct PanelAnimationMap __near * CColorZPreview::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CColorZPreview::GetAnimMap(CColorZPreview *this)
{
  return FindOrAddPanelAnimationMap(className: "CColorZPreview");
}

//------------------------------------------------------------------------------
// Address: 0x104C7200
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CColorZPreview::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CColorZPreview::GetKBMap(CColorZPreview *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CColorZPreview::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorZPreview::GetKBMap'::`2'::s_pMap;
  `CColorZPreview::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CColorZPreview");
  `CColorZPreview::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104C7230
// Name: public: virtual void CColorZPreview::RegenerateTextureBits(class ITexture __near *,class IVTFTexture __near *,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorZPreview::RegenerateTextureBits(
        CColorZPreview *this,
        ITexture *pTexture,
        IVTFTexture *pVTFTexture,
        Rect_t *pRect)
{
  IVTFTexture *v4; // esi
  IVTFTexture_vtbl *v5; // eax
  __int16 v6; // bx
  unsigned __int8 *m_pMemory; // edi
  vgui::Dar<unsigned long> *p_actionSignalTargetDar; // esi
  int TreeColumnWidth; // eax
  bool v10; // zf
  int v11; // eax
  int v12; // esi
  int v13; // ecx
  unsigned __int8 v14; // dl
  int v15; // eax
  char v16; // al
  int v17; // esi
  int v18; // ecx
  unsigned __int8 v19; // al
  unsigned int v20; // edx
  unsigned int v21; // edx
  int v22; // eax
  __int64 v23; // rax
  __int64 v24; // rax
  unsigned __int64 v25; // rdi
  int pixelWriter; // [esp+Ch] [ebp-78h]
  int pixelWriter_4; // [esp+10h] [ebp-74h]
  unsigned __int8 pixelWriter_10; // [esp+16h] [ebp-6Eh]
  int pixelWriter_12; // [esp+18h] [ebp-6Ch]
  int pixelWriter_16; // [esp+1Ch] [ebp-68h]
  int pixelWriter_20; // [esp+20h] [ebp-64h]
  int pixelWriter_24; // [esp+24h] [ebp-60h]
  int pixelWriter_28; // [esp+28h] [ebp-5Ch]
  unsigned __int8 pixelWriter_32; // [esp+2Ch] [ebp-58h]
  Vector rgb; // [esp+30h] [ebp-54h] BYREF
  Vector vecHSV; // [esp+3Ch] [ebp-48h] BYREF
  __int64 v37; // [esp+48h] [ebp-3Ch]
  int nDepth; // [esp+50h] [ebp-34h] BYREF
  int v39; // [esp+54h] [ebp-30h]
  int v40; // [esp+58h] [ebp-2Ch]
  int nHeight; // [esp+5Ch] [ebp-28h] BYREF
  int nWidth; // [esp+60h] [ebp-24h] BYREF
  int x; // [esp+64h] [ebp-20h]
  int v44; // [esp+68h] [ebp-1Ch]
  CColorZPreview *v45; // [esp+6Ch] [ebp-18h]
  int v46; // [esp+70h] [ebp-14h]
  int v47; // [esp+74h] [ebp-10h]
  int y; // [esp+78h] [ebp-Ch]
  int v49; // [esp+7Ch] [ebp-8h]
  int v50; // [esp+80h] [ebp-4h]

  v4 = pVTFTexture;
  v5 = pVTFTexture->__vftable;
  v45 = this;
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
      pixelWriter_12 = 0;
      goto LABEL_17;
    case IMAGE_FORMAT_A8:
      v6 = 0;
      pixelWriter_10 = 1;
      pixelWriter_12 = 0;
      pixelWriter_16 = 0;
      pixelWriter_20 = 0;
      pixelWriter_24 = 0;
      pixelWriter_28 = 0;
      pixelWriter_32 = -1;
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
      pixelWriter_32 = -1;
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
      pixelWriter_32 = 0x80;
      goto LABEL_21;
    case IMAGE_FORMAT_BGRA4444:
      pixelWriter_10 = 2;
      pixelWriter_12 = 4;
      v6 = -4;
      pixelWriter_16 = 589820;
      pixelWriter_20 = 240;
      pixelWriter_24 = 240;
      pixelWriter_28 = 240;
      pixelWriter_32 = -16;
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
      pixelWriter_32 = -1;
      goto LABEL_21;
    case IMAGE_FORMAT_R32F:
      pixelWriter_10 = 4;
      pixelWriter_12 = 0;
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
      pixelWriter_12 = 0;
LABEL_17:
      pixelWriter_20 = 255;
LABEL_18:
      pixelWriter_24 = 0;
      pixelWriter_28 = 0;
LABEL_19:
      v6 = 0;
      pixelWriter_16 = 0;
LABEL_20:
      pixelWriter_32 = 0;
LABEL_21:
      y = 0;
      if ( nHeight > 0 )
      {
        v39 = (unsigned __int16)pVTFTexture;
        v46 = -1;
        v47 = pixelWriter;
        do
        {
          pixelWriter_4 = v47;
          if ( v45->_vpanel != 0 )
          {
            m_pMemory = v45->_panelName.m_Storage.m_Memory.m_pMemory;
            p_actionSignalTargetDar = &v45[-1]._actionSignalTargetDar;
            vecHSV = *(Vector *)&v45->_panelName.m_Storage.m_Memory.m_nGrowSize;
            TreeColumnWidth = CElementTreeViewListControl::GetTreeColumnWidth(this: (CColorZPreview *)((char *)v45 - 380));
            v10 = p_actionSignalTargetDar[22].m_pElements == nullptr;
            *(&vecHSV.x + (_DWORD)m_pMemory) = (float)(v46 + TreeColumnWidth) * 0.0039215689;
            if ( v10 )
            {
              if ( vecHSV.x != -1.0 )
                vecHSV.x = vecHSV.x * 360.0;
              vecHSV.y = 1.0;
              vecHSV.z = 1.0;
            }
            HSVtoRGB(hsv: &vecHSV, &rgb);
            v11 = (int)(float)((float)(rgb.x * 255.0) + 0.5);
            v12 = (int)(float)((float)(rgb.y * 255.0) + 0.5);
            v13 = (int)(float)((float)(rgb.z * 255.0) + 0.5);
            if ( v11 >= 0 )
            {
              if ( v11 > 255 )
                LOBYTE(v11) = -1;
            }
            else
            {
              LOBYTE(v11) = 0;
            }
            v14 = v11;
            if ( v12 >= 0 )
            {
              LOBYTE(v15) = -1;
              if ( v12 <= 255 )
                v15 = (int)(float)((float)(rgb.y * 255.0) + 0.5);
            }
            else
            {
              LOBYTE(v15) = 0;
            }
            if ( v13 >= 0 )
            {
              if ( v13 > 255 )
                LOBYTE(v13) = -1;
            }
            else
            {
              LOBYTE(v13) = 0;
            }
          }
          else
          {
            v16 = BYTE2(v45->_panelName.m_Storage.m_Memory.m_nAllocationCount);
            LOWORD(pVTFTexture) = v45->_panelName.m_Storage.m_Memory.m_nAllocationCount;
            BYTE2(pVTFTexture) = v16;
            LOBYTE(v15) = CElementTreeViewListControl::GetTreeColumnWidth(this: (CColorZPreview *)((char *)v45 - 380));
            *((_BYTE *)&pVTFTexture + (unsigned int)v45->_panelName.m_Storage.m_Memory.m_pMemory) = -1 - y + v15;
            LOBYTE(v13) = BYTE2(pVTFTexture);
            LOBYTE(v15) = BYTE1(pVTFTexture);
            v14 = (unsigned __int8)pVTFTexture;
          }
          x = 0;
          if ( nWidth > 0 )
          {
            v17 = (unsigned __int8)v13;
            v18 = (unsigned __int8)v15;
            v19 = pixelWriter_10;
            v44 = v14;
            v50 = v17;
            v40 = v18;
            v49 = pixelWriter_10;
            while ( 1 )
            {
              if ( v19 != 0 )
              {
                if ( v19 >= 5u )
                {
                  v23 = v50 & (unsigned int)pixelWriter_28;
                  if ( v6 <= 0 )
                    v24 = v23 >> -(char)v6;
                  else
                    v24 = v23 << v6;
                  v37 = v24;
                  v25 = v24
                      | ((unsigned __int64)pixelWriter_32 << SBYTE2(pixelWriter_16))
                      | ((unsigned __int64)(v44 & (unsigned int)pixelWriter_20) << pixelWriter_12)
                      | ((unsigned __int64)(v18 & (unsigned int)pixelWriter_24) << SBYTE2(pixelWriter_12));
                  if ( v49 == 6 )
                  {
                    *(_DWORD *)pixelWriter_4 = v25;
                    *(_WORD *)(pixelWriter_4 + 4) = WORD2(v25);
                  }
                  else if ( v49 == 8 )
                  {
                    *(_QWORD *)pixelWriter_4 = v25;
                  }
                }
                else
                {
                  v20 = v17 & pixelWriter_28;
                  if ( v6 <= 0 )
                    v21 = v20 >> -(char)pixelWriter_16;
                  else
                    v21 = v20 << pixelWriter_16;
                  v22 = v21
                      | (pixelWriter_32 << SBYTE2(pixelWriter_16))
                      | ((v44 & pixelWriter_20) << pixelWriter_12)
                      | ((v18 & pixelWriter_24) << SBYTE2(pixelWriter_12));
                  switch ( v49 )
                  {
                    case 1:
                      *(_BYTE *)pixelWriter_4 = v22;
                      break;
                    case 2:
                      *(_WORD *)pixelWriter_4 = v22;
                      break;
                    case 3:
                      *(_WORD *)pixelWriter_4 = v22;
                      *(_BYTE *)(pixelWriter_4 + 2) = BYTE2(v22);
                      break;
                    case 4:
                      *(_DWORD *)pixelWriter_4 = v22;
                      break;
                    default:
                      break;
                  }
                }
              }
              pixelWriter_4 += v49;
              if ( ++x >= nWidth )
                break;
              v19 = pixelWriter_10;
              v18 = v40;
              v17 = v50;
            }
          }
          v47 += v39;
          --v46;
          ++y;
        }
        while ( y < nHeight );
      }
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C7810
// Name: private: void CColorZPreview::UpdateColorFromMouse(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorZPreview::UpdateColorFromMouse(CColorZPreview *this, int x, float y)
{
  float v4; // xmm0_4
  int TreeColumnWidth; // eax
  int v6; // ebx
  ColorChannel_t m_Channel; // esi
  int v8; // eax
  bool v9; // zf
  KeyValues *v10; // eax
  KeyValues *v11; // esi
  Vector *p_hsvColor; // edx
  unsigned __int8 b; // dl
  unsigned __int8 v14; // bl
  KeyValues *v15; // eax
  KeyValues *v16; // esi
  Vector rgb; // [esp+10h] [ebp-24h] BYREF
  Vector hsvColor; // [esp+1Ch] [ebp-18h] BYREF
  int v19; // [esp+28h] [ebp-Ch] BYREF
  int w; // [esp+2Ch] [ebp-8h] BYREF
  int h; // [esp+30h] [ebp-4h]

  vgui::Panel::GetSize(this, wide: &v19, tall: &w);
  w -= 12;
  v4 = (float)(LODWORD(y) - 6) / (float)(w - 1);
  if ( v4 >= 0.0 )
  {
    if ( v4 <= 1.0 )
      y = (float)(LODWORD(y) - 6) / (float)(w - 1);
    else
      y = 1.0;
  }
  else
  {
    y = 0.0;
  }
  TreeColumnWidth = CElementTreeViewListControl::GetTreeColumnWidth(this);
  v6 = (int)(float)((float)((float)(TreeColumnWidth - 1) * y) + 0.5);
  if ( this->m_Type != COLOR_TYPE_RGB )
  {
    m_Channel = this->m_Channel;
    hsvColor = this->m_CurrentHSVColor;
    v8 = CElementTreeViewListControl::GetTreeColumnWidth(this);
    v9 = this->m_Channel == CHANNEL_RED;
    *(&hsvColor.x + m_Channel) = (float)(v8 - v6 - 1) * 0.0039215689;
    if ( v9 && hsvColor.x != -1.0 )
      hsvColor.x = hsvColor.x * 360.0;
    v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v10 != nullptr )
      v11 = KeyValues::KeyValues(this: v10, setName: "HSVSelected");
    else
      v11 = nullptr;
    KeyValues::SetFloat(this: v11, keyName: "hue", value: hsvColor.x);
    KeyValues::SetFloat(this: v11, keyName: "saturation", value: hsvColor.y);
    KeyValues::SetFloat(this: v11, keyName: "value", value: hsvColor.z);
    this->PostActionSignal(this, a2: v11);
    HSVtoRGB(hsv: &hsvColor, &rgb);
    VectorToRGB888(inVector: &rgb, outColor: (RGB888_t *)&y);
    p_hsvColor = &hsvColor;
  }
  else
  {
    b = this->m_CurrentColor.b;
    LOWORD(y) = *(_WORD *)&this->m_CurrentColor.r;
    BYTE2(y) = b;
    *((_BYTE *)&y + this->m_Channel) = -1 - v6 + CElementTreeViewListControl::GetTreeColumnWidth(this);
    v14 = LOBYTE(y);
    LOWORD(h) = LOWORD(y);
    BYTE2(h) = BYTE2(y);
    HIBYTE(h) = -1;
    v15 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v15 != nullptr )
      v16 = KeyValues::KeyValues(this: v15, setName: "ColorSelected");
    else
      v16 = nullptr;
    KeyValues::SetColor(this: v16, keyName: "color", value: (Color)h);
    this->PostActionSignal(this, a2: v16);
    hsvColor.x = (float)v14 * 0.0039215689;
    hsvColor.y = (float)BYTE1(y) * 0.0039215689;
    hsvColor.z = (float)BYTE2(y) * 0.0039215689;
    RGBtoHSV(rgb: &hsvColor, hsv: &rgb);
    p_hsvColor = &rgb;
  }
  CColorZPreview::SetColor(this, color: (const RGB888_t *)&y, hsvColor: p_hsvColor);
}

//------------------------------------------------------------------------------
// Address: 0x104C7AA0
// Name: public: virtual void CColorZPreview::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorZPreview::OnMousePressed(CColorZPreview *this, int code)
{
  int v2; // edi
  unsigned int (__thiscall *GetVPanel)(vgui::IClientPanel *); // edx
  vgui::IInput *v5; // edi
  vgui::IInput_vtbl *v6; // ebx
  int v7; // eax
  int x; // [esp+8h] [ebp-4h] BYREF

  v2 = code;
  CToolEntitySprinkle::RenderTool2D((vgui::TreeView *)this, itemIndex: code);
  if ( v2 == 107 && !this->m_bDraggingMouse )
  {
    GetVPanel = this->GetVPanel;
    this->m_bDraggingMouse = true;
    v5 = g_pVGuiInput;
    v6 = g_pVGuiInput->__vftable;
    v7 = GetVPanel(this);
    v6->SetMouseCapture(this: v5, a2: v7);
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &code);
    vgui::Panel::ScreenToLocal(this, &x, y: &code);
    CColorZPreview::UpdateColorFromMouse(this, x, y: *(float *)&code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C7B20
// Name: public: virtual void CColorZPreview::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorZPreview::OnCursorMoved(CColorZPreview *this, int x, KeyValues *y)
{
  BlankImage::SetSize((vgui::TreeView *)this, itemIndex: x, msg: y);
  if ( this->m_bDraggingMouse )
    CColorZPreview::UpdateColorFromMouse(this, x, y: *(float *)&y);
}

//------------------------------------------------------------------------------
// Address: 0x104C7B50
// Name: public: void CColorPickerPanel::SetInitialColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerPanel::SetInitialColor(CColorPickerPanel *this, Color initialColor)
{
  __int16 v3; // dx
  Vector *p_m_CurrentHSVColor; // edi
  Vector rgb; // [esp+0h] [ebp-10h] BYREF
  __int16 v6; // [esp+Ch] [ebp-4h]

  this->m_InitialColor.r = initialColor._color[0];
  this->m_InitialColor.g = initialColor._color[1];
  this->m_InitialColor.b = initialColor._color[2];
  this->m_CurrentAlpha = initialColor._color[3];
  this->m_InitialAlpha = initialColor._color[3];
  v3 = *(_WORD *)&this->m_InitialColor.r;
  *(_WORD *)&this->m_CurrentColor.r = v3;
  this->m_CurrentColor.b = initialColor._color[2];
  rgb.x = (float)(unsigned __int8)v3 * 0.0039215689;
  v6 = v3;
  rgb.y = (float)HIBYTE(v3) * 0.0039215689;
  p_m_CurrentHSVColor = &this->m_CurrentHSVColor;
  rgb.z = (float)initialColor._color[2] * 0.0039215689;
  RGBtoHSV(&rgb, hsv: &this->m_CurrentHSVColor);
  if ( p_m_CurrentHSVColor->x == -1.0 )
    p_m_CurrentHSVColor->x = 0.0;
  CColorPickerPanel::OnColorChanged(this, pChanged: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x104C7C30
// Name: public: virtual void CColorPickerPanel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerPanel::OnMousePressed(CColorPickerPanel *this, int code)
{
  int v2; // edi
  unsigned __int8 b; // dl
  unsigned __int8 m_InitialAlpha; // cl
  int tall; // [esp+8h] [ebp-14h] BYREF
  int cy; // [esp+Ch] [ebp-10h] BYREF
  int cw; // [esp+10h] [ebp-Ch] BYREF
  int v9; // [esp+14h] [ebp-8h] BYREF
  int y; // [esp+18h] [ebp-4h] BYREF

  v2 = code;
  CToolEntitySprinkle::RenderTool2D((vgui::TreeView *)this, itemIndex: code);
  if ( v2 == 107 )
  {
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &code, a3: &y);
    vgui::Panel::ScreenToLocal(this, x: &code, &y);
    vgui::Panel::GetBounds(this: this->m_pInitialColor, x: &v9, y: &cy, wide: &cw, &tall);
    if ( v9 <= code && cw + v9 > code && cy <= y && tall + cy > y )
    {
      b = this->m_InitialColor.b;
      *(_WORD *)&this->m_CurrentColor.r = *(_WORD *)&this->m_InitialColor.r;
      m_InitialAlpha = this->m_InitialAlpha;
      this->m_CurrentColor.b = b;
      this->m_CurrentAlpha = m_InitialAlpha;
      RGBtoHSV(rgb: &this->m_CurrentColor, hsv: &this->m_CurrentHSVColor);
      if ( this->m_CurrentHSVColor.x == -1.0 )
        this->m_CurrentHSVColor.x = 0.0;
      CColorPickerPanel::OnColorChanged(this, pChanged: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C7D10
// Name: private: virtual void CColorPickerPanel::OnHSVSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerPanel::OnHSVSelected(CColorPickerPanel *this, KeyValues *data)
{
  Vector inVector; // [esp+10h] [ebp-Ch] BYREF

  this->m_CurrentHSVColor.x = KeyValues::GetFloat(this: data, keyName: "hue", defaultValue: 0.0);
  this->m_CurrentHSVColor.y = KeyValues::GetFloat(this: data, keyName: "saturation", defaultValue: 0.0);
  this->m_CurrentHSVColor.z = KeyValues::GetFloat(this: data, keyName: "value", defaultValue: 0.0);
  HSVtoRGB(hsv: &this->m_CurrentHSVColor, rgb: &inVector);
  VectorToRGB888(&inVector, outColor: &this->m_CurrentColor);
  CColorPickerPanel::OnColorChanged(this, pChanged: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x104C7DA0
// Name: private: virtual void CColorPickerPanel::OnColorSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerPanel::OnColorSelected(CColorPickerPanel *this, KeyValues *data)
{
  unsigned __int8 v3; // ah
  unsigned __int8 v4; // dl
  Vector rgb; // [esp+8h] [ebp-14h] BYREF
  Color c; // [esp+14h] [ebp-8h] BYREF
  Color defaultColor; // [esp+18h] [ebp-4h] BYREF
  __int16 dataa; // [esp+24h] [ebp+8h]

  defaultColor = 0;
  KeyValues::GetColor(this: data, result: &c, keyName: "color", &defaultColor);
  v3 = c._color[1];
  v4 = c._color[2];
  this->m_CurrentColor.r = c._color[0];
  this->m_CurrentColor.b = v4;
  this->m_CurrentColor.g = v3;
  dataa = *(_WORD *)&this->m_CurrentColor.r;
  rgb.x = (float)(unsigned __int8)dataa * 0.0039215689;
  rgb.y = (float)HIBYTE(dataa) * 0.0039215689;
  rgb.z = (float)v4 * 0.0039215689;
  RGBtoHSV(&rgb, hsv: &this->m_CurrentHSVColor);
  CColorPickerPanel::OnColorChanged(this, pChanged: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x104C7E50
// Name: private: virtual void CColorPickerPanel::OnTextChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerPanel::OnTextChanged(CColorPickerPanel *this, KeyValues *data)
{
  vgui::TextEntry *Ptr; // eax
  vgui::TextEntry *m_pRedText; // ecx
  vgui::TextEntry *v5; // esi
  Vector *p_m_CurrentHSVColor; // ebx
  int v7; // eax
  __int16 v8; // dx
  int b; // eax
  vgui::TextEntry *m_pGreenText; // ecx
  int v11; // eax
  __int16 v12; // cx
  int v13; // edx
  vgui::TextEntry *m_pBlueText; // ecx
  int v15; // eax
  vgui::TextEntry *m_pAlphaText; // ecx
  int v17; // eax
  vgui::TextEntry *m_pHueText; // ecx
  int v19; // eax
  vgui::TextEntry *m_pSaturationText; // ecx
  int v21; // eax
  vgui::TextEntry *m_pValueText; // ecx
  int v23; // eax
  char buf[256]; // [esp+Ch] [ebp-110h] BYREF
  float flHue; // [esp+10Ch] [ebp-10h]
  Vector rgb; // [esp+110h] [ebp-Ch] BYREF
  vgui::Panel *pPanel; // [esp+124h] [ebp+8h]

  Ptr = (vgui::TextEntry *)KeyValues::GetPtr(this: data, keyName: "panel", defaultValue: nullptr);
  m_pRedText = this->m_pRedText;
  v5 = Ptr;
  p_m_CurrentHSVColor = &this->m_CurrentHSVColor;
  pPanel = Ptr;
  flHue = this->m_CurrentHSVColor.x;
  if ( Ptr == m_pRedText )
  {
    m_pRedText->GetText_2(this: m_pRedText, a2: buf, a3: 256);
    v7 = atoi(nptr: buf);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    this->m_CurrentColor.r = v7;
    v8 = *(_WORD *)&this->m_CurrentColor.r;
    b = this->m_CurrentColor.b;
    rgb.x = (float)(unsigned __int8)v8 * 0.0039215689;
    rgb.y = (float)HIBYTE(v8) * 0.0039215689;
    rgb.z = (float)b * 0.0039215689;
    RGBtoHSV(&rgb, hsv: &this->m_CurrentHSVColor);
  }
  else
  {
    m_pGreenText = this->m_pGreenText;
    if ( Ptr == m_pGreenText )
    {
      m_pGreenText->GetText_2(this: m_pGreenText, a2: buf, a3: 256);
      v11 = atoi(nptr: buf);
      if ( v11 >= 0 )
      {
        if ( v11 > 255 )
          LOBYTE(v11) = -1;
      }
      else
      {
        LOBYTE(v11) = 0;
      }
      this->m_CurrentColor.g = v11;
      v12 = *(_WORD *)&this->m_CurrentColor.r;
      v13 = this->m_CurrentColor.b;
      rgb.x = (float)(unsigned __int8)v12 * 0.0039215689;
      rgb.y = (float)HIBYTE(v12) * 0.0039215689;
      rgb.z = (float)v13 * 0.0039215689;
      RGBtoHSV(&rgb, hsv: &this->m_CurrentHSVColor);
    }
    else
    {
      m_pBlueText = this->m_pBlueText;
      if ( Ptr == m_pBlueText )
      {
        m_pBlueText->GetText_2(this: m_pBlueText, a2: buf, a3: 256);
        v15 = atoi(nptr: buf);
        if ( v15 >= 0 )
        {
          if ( v15 > 255 )
            LOBYTE(v15) = -1;
        }
        else
        {
          LOBYTE(v15) = 0;
        }
        this->m_CurrentColor.b = v15;
        RGBtoHSV(rgb: &this->m_CurrentColor, hsv: &this->m_CurrentHSVColor);
      }
      else
      {
        m_pAlphaText = this->m_pAlphaText;
        if ( Ptr == m_pAlphaText )
        {
          m_pAlphaText->GetText_2(this: m_pAlphaText, a2: buf, a3: 256);
          v17 = atoi(nptr: buf);
          if ( v17 >= 0 )
          {
            if ( v17 > 255 )
              LOBYTE(v17) = -1;
            this->m_CurrentAlpha = v17;
          }
          else
          {
            this->m_CurrentAlpha = 0;
          }
        }
        else
        {
          m_pHueText = this->m_pHueText;
          if ( Ptr == m_pHueText )
          {
            m_pHueText->GetText_2(this: m_pHueText, a2: buf, a3: 256);
            v19 = atoi(nptr: buf);
            if ( v19 >= 0 )
            {
              if ( v19 > 360 )
                v19 = 360;
              p_m_CurrentHSVColor->x = (float)v19;
            }
            else
            {
              p_m_CurrentHSVColor->x = (float)0;
            }
          }
          else
          {
            m_pSaturationText = this->m_pSaturationText;
            if ( Ptr == m_pSaturationText )
            {
              m_pSaturationText->GetText_2(this: m_pSaturationText, a2: buf, a3: 256);
              v21 = atoi(nptr: buf);
              if ( v21 >= 0 )
              {
                if ( v21 > 100 )
                  v21 = 100;
              }
              else
              {
                v21 = 0;
              }
              this->m_CurrentHSVColor.y = (float)v21 * 0.0099999998;
            }
            else
            {
              m_pValueText = this->m_pValueText;
              if ( Ptr != m_pValueText )
                goto LABEL_44;
              m_pValueText->GetText_2(this: m_pValueText, a2: buf, a3: 256);
              v23 = atoi(nptr: buf);
              if ( v23 >= 0 )
              {
                if ( v23 > 100 )
                  v23 = 100;
              }
              else
              {
                v23 = 0;
              }
              this->m_CurrentHSVColor.z = (float)v23 * 0.0099999998;
            }
          }
          HSVtoRGB(hsv: &this->m_CurrentHSVColor, rgb: &this->m_CurrentColor);
          v5 = (vgui::TextEntry *)pPanel;
        }
      }
    }
  }
LABEL_44:
  if ( p_m_CurrentHSVColor->x == -1.0 )
    p_m_CurrentHSVColor->x = flHue;
  CColorPickerPanel::OnColorChanged(this, pChanged: v5);
}

//------------------------------------------------------------------------------
// Address: 0x104C81F0
// Name: public: virtual struct vgui::PanelMessageMap __near * CColorPickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CColorPickerFrame::GetMessageMap(CColorPickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CColorPickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorPickerFrame::GetMessageMap'::`2'::s_pMap;
  `CColorPickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CColorPickerFrame");
  `CColorPickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104C8220
// Name: public: virtual struct PanelAnimationMap __near * CColorPickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CColorPickerFrame::GetAnimMap(CColorPickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CColorPickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x104C8230
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CColorPickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CColorPickerFrame::GetKBMap(CColorPickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CColorPickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorPickerFrame::GetKBMap'::`2'::s_pMap;
  `CColorPickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CColorPickerFrame");
  `CColorPickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104C8260
// Name: public: void CColorPickerFrame::DoModal(class Color,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerFrame::DoModal(CColorPickerFrame *this, Color initialColor, KeyValues *pContextKeys)
{
  KeyValues *m_pContextKeys; // ecx

  m_pContextKeys = this->m_pContextKeys;
  if ( m_pContextKeys != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeys);
    this->m_pContextKeys = nullptr;
  }
  CColorPickerPanel::SetInitialColor(this: this->m_pPicker, initialColor);
  this->m_pContextKeys = pContextKeys;
  vgui::Frame::DoModal(this);
}

//------------------------------------------------------------------------------
// Address: 0x104C82E0
// Name: public: virtual void CColorPickerButton::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerButton::ApplySchemeSettings(CColorPickerButton *this, vgui::IScheme *pScheme)
{
  vgui::Button::ApplySchemeSettings(this, pScheme);
  ((void (__thiscall *)(CColorPickerButton *, _DWORD, _DWORD))this->SetDefaultColor)(
    a1: this,
    a2: *(_DWORD *)&this->m_CurrentColor,
    a3: *(_DWORD *)&this->m_CurrentColor);
  ((void (__thiscall *)(CColorPickerButton *, _DWORD, _DWORD))this->SetArmedColor)(
    a1: this,
    a2: *(_DWORD *)&this->m_CurrentColor,
    a3: *(_DWORD *)&this->m_CurrentColor);
  ((void (__thiscall *)(CColorPickerButton *, _DWORD, _DWORD))this->SetDepressedColor)(
    a1: this,
    a2: *(_DWORD *)&this->m_CurrentColor,
    a3: *(_DWORD *)&this->m_CurrentColor);
}

//------------------------------------------------------------------------------
// Address: 0x104C8330
// Name: private: virtual void CColorPickerButton::OnPreview(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerButton::OnPreview(CColorPickerButton *this, KeyValues *data)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  Color *Color; // eax
  Color defaultColor; // [esp+Ch] [ebp-4h] BYREF

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "ColorPickerPreview");
  else
    v4 = nullptr;
  defaultColor = 0;
  Color = KeyValues::GetColor(this: data, result: (Color *)&data, keyName: "color", &defaultColor);
  KeyValues::SetColor(this: v4, keyName: "color", value: *Color);
  this->PostActionSignal(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x104C83A0
// Name: public: void CColorPickerButton::SetColor(class Color const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerButton::SetColor(CColorPickerButton *this, const Color *clr)
{
  Color v3; // ecx

  v3 = *clr;
  this->m_CurrentColor = *clr;
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))this->SetDefaultColor)(a1: this, a2: v3, a3: v3);
  ((void (__thiscall *)(CColorPickerButton *, _DWORD, _DWORD))this->SetArmedColor)(
    a1: this,
    a2: *(_DWORD *)&this->m_CurrentColor,
    a3: *(_DWORD *)&this->m_CurrentColor);
  ((void (__thiscall *)(CColorPickerButton *, _DWORD, _DWORD))this->SetDepressedColor)(
    a1: this,
    a2: *(_DWORD *)&this->m_CurrentColor,
    a3: *(_DWORD *)&this->m_CurrentColor);
}

//------------------------------------------------------------------------------
// Address: 0x104C8440
// Name: private: virtual void CColorPickerButton::OnPicked(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerButton::OnPicked(CColorPickerButton *this, KeyValues *data)
{
  Color *Color; // eax
  Color v4; // edx
  KeyValues *v5; // eax
  KeyValues *v6; // edi
  Color defaultColor; // [esp+Ch] [ebp-4h] BYREF

  defaultColor = 0;
  Color = KeyValues::GetColor(this: data, result: (Color *)&data, keyName: "color", &defaultColor);
  v4 = *Color;
  this->m_CurrentColor = *Color;
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))this->SetDefaultColor)(a1: this, a2: v4, a3: v4);
  ((void (__thiscall *)(CColorPickerButton *, _DWORD, _DWORD))this->SetArmedColor)(
    a1: this,
    a2: *(_DWORD *)&this->m_CurrentColor,
    a3: *(_DWORD *)&this->m_CurrentColor);
  ((void (__thiscall *)(CColorPickerButton *, _DWORD, _DWORD))this->SetDepressedColor)(
    a1: this,
    a2: *(_DWORD *)&this->m_CurrentColor,
    a3: *(_DWORD *)&this->m_CurrentColor);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "ColorPickerPicked");
  else
    v6 = nullptr;
  KeyValues::SetColor(this: v6, keyName: "color", value: this->m_CurrentColor);
  this->PostActionSignal(this, a2: v6);
  vgui::Button::PlayButtonReleasedSound(this);
  this->SetSelected(this, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x104C8500
// Name: public: static void CColorPickerPanel::PanelMessageFunc_OnRadioButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CColorPickerPanel::PanelMessageFunc_OnRadioButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`CColorPickerPanel::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded )
  {
    `CColorPickerPanel::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSystemPreviewPanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CColorPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "RadioButtonChecked";
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
// Address: 0x104C8590
// Name: public: static void CColorPickerPanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CColorPickerPanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CColorPickerPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CColorPickerPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CColorPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextChanged";
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
// Address: 0x104C8620
// Name: public: static void CColorPickerPanel::PanelMessageFunc_OnHSVSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CColorPickerPanel::PanelMessageFunc_OnHSVSelected::InitVar(int a1@<ebp>)
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
  if ( !`CColorPickerPanel::PanelMessageFunc_OnHSVSelected::InitVar'::`2'::bAdded )
  {
    `CColorPickerPanel::PanelMessageFunc_OnHSVSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSnapshotGrid::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CColorPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "HSVSelected";
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
// Address: 0x104C86B0
// Name: public: static void CColorPickerPanel::PanelMessageFunc_OnColorSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CColorPickerPanel::PanelMessageFunc_OnColorSelected::InitVar(int a1@<ebp>)
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
  if ( !`CColorPickerPanel::PanelMessageFunc_OnColorSelected::InitVar'::`2'::bAdded )
  {
    `CColorPickerPanel::PanelMessageFunc_OnColorSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CColorPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ColorSelected";
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
// Address: 0x104C8740
// Name: public: static void CColorPickerButton::PanelMessageFunc_OnPicked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CColorPickerButton::PanelMessageFunc_OnPicked::InitVar(int a1@<ebp>)
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
  if ( !`CColorPickerButton::PanelMessageFunc_OnPicked::InitVar'::`2'::bAdded )
  {
    `CColorPickerButton::PanelMessageFunc_OnPicked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerButton::`vcall'{1144,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CColorPickerButton");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ColorPickerPicked";
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
// Address: 0x104C87D0
// Name: public: static void CColorPickerButton::PanelMessageFunc_OnPreview::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CColorPickerButton::PanelMessageFunc_OnPreview::InitVar(int a1@<ebp>)
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
  if ( !`CColorPickerButton::PanelMessageFunc_OnPreview::InitVar'::`2'::bAdded )
  {
    `CColorPickerButton::PanelMessageFunc_OnPreview::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CColorPickerButton");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ColorPickerPreview";
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
// Address: 0x104C8860
// Name: public: static void CColorPickerButton::PanelMessageFunc_OnCancelled::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CColorPickerButton::PanelMessageFunc_OnCancelled::InitVar(int a1@<ebp>)
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
  if ( !`CColorPickerButton::PanelMessageFunc_OnCancelled::InitVar'::`2'::bAdded )
  {
    `CColorPickerButton::PanelMessageFunc_OnCancelled::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerButton::`vcall'{1152,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CColorPickerButton");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ColorPickerCancel";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104C88F0
// Name: public: CColorPickerPanel::CColorPickerPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CColorPickerPanel *__thiscall CColorPickerPanel::CColorPickerPanel(
        CColorPickerPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CColorXYPreview *v7; // eax
  CColorXYPreview *v8; // eax
  CColorZPreview *v9; // eax
  CColorZPreview *v10; // eax
  CColorXYPreview *m_pColorXYPreview; // ecx
  vgui::RadioButton *v12; // eax
  vgui::RadioButton *v13; // eax
  vgui::RadioButton *v14; // eax
  vgui::RadioButton *v15; // eax
  vgui::RadioButton *v16; // eax
  vgui::RadioButton *v17; // eax
  vgui::RadioButton *v18; // eax
  vgui::RadioButton *v19; // eax
  vgui::RadioButton *v20; // eax
  vgui::RadioButton *v21; // eax
  vgui::RadioButton *v22; // eax
  vgui::RadioButton *v23; // eax
  vgui::TextEntry *v24; // eax
  vgui::TextEntry *v25; // eax
  vgui::TextEntry *v26; // eax
  vgui::TextEntry *v27; // eax
  vgui::TextEntry *v28; // eax
  vgui::TextEntry *v29; // eax
  vgui::TextEntry *v30; // eax
  vgui::TextEntry *v31; // eax
  vgui::TextEntry *v32; // eax
  vgui::TextEntry *v33; // eax
  vgui::TextEntry *v34; // eax
  vgui::TextEntry *v35; // eax
  vgui::TextEntry *v36; // eax
  vgui::TextEntry *v37; // eax
  vgui::Panel *v38; // eax
  vgui::Panel *v39; // eax
  vgui::Panel *v40; // eax
  vgui::Panel *v41; // eax
  vgui::Panel *m_pInitialColor; // ecx
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->__vftable = (CColorPickerPanel_vtbl *)&CColorPickerPanel::`vftable';
  if ( `CColorPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CColorPickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CColorPickerPanel");
    v4->pfnClassName = CColorPickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CColorPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CColorPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CColorPickerPanel");
    v5->pfnClassName = CColorPickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CColorPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CColorPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CColorPickerPanel");
    v6->pfnClassName = CColorPickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CColorPickerPanel::PanelMessageFunc_OnRadioButtonChecked::InitVar(a1: (int)&savedregs);
  CColorPickerPanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  CColorPickerPanel::PanelMessageFunc_OnHSVSelected::InitVar(a1: (int)&savedregs);
  CColorPickerPanel::PanelMessageFunc_OnColorSelected::InitVar(a1: (int)&savedregs);
  v7 = (CColorXYPreview *)operator new(nSize: 0x1E4u);
  if ( v7 != nullptr )
    v8 = CColorXYPreview::CColorXYPreview(this: v7, pParent: this, pName: "ColorXYPreview");
  else
    v8 = nullptr;
  this->m_pColorXYPreview = v8;
  v9 = (CColorZPreview *)operator new(nSize: 0x1E0u);
  if ( v9 != nullptr )
    v10 = CColorZPreview::CColorZPreview(this: v9, pParent: this, pName: "ColorZPreview");
  else
    v10 = nullptr;
  m_pColorXYPreview = this->m_pColorXYPreview;
  this->m_pColorZPreview = v10;
  m_pColorXYPreview->AddActionSignalTarget_2(this: m_pColorXYPreview, a2: this);
  v12 = (vgui::RadioButton *)operator new(nSize: 0x210u);
  if ( v12 != nullptr )
    v13 = vgui::RadioButton::RadioButton(this: v12, parent: this, panelName: "HueRadio", text: "H");
  else
    v13 = nullptr;
  this->m_pHueRadio = v13;
  v14 = (vgui::RadioButton *)operator new(nSize: 0x210u);
  if ( v14 != nullptr )
    v15 = vgui::RadioButton::RadioButton(this: v14, parent: this, panelName: "SaturationRadio", text: "S");
  else
    v15 = nullptr;
  this->m_pSaturationRadio = v15;
  v16 = (vgui::RadioButton *)operator new(nSize: 0x210u);
  if ( v16 != nullptr )
    v17 = vgui::RadioButton::RadioButton(this: v16, parent: this, panelName: "ValueRadio", text: "V");
  else
    v17 = nullptr;
  this->m_pValueRadio = v17;
  v18 = (vgui::RadioButton *)operator new(nSize: 0x210u);
  if ( v18 != nullptr )
    v19 = vgui::RadioButton::RadioButton(this: v18, parent: this, panelName: "RedRadio", text: "R");
  else
    v19 = nullptr;
  this->m_pRedRadio = v19;
  v20 = (vgui::RadioButton *)operator new(nSize: 0x210u);
  if ( v20 != nullptr )
    v21 = vgui::RadioButton::RadioButton(this: v20, parent: this, panelName: "GreenRadio", text: "G");
  else
    v21 = nullptr;
  this->m_pGreenRadio = v21;
  v22 = (vgui::RadioButton *)operator new(nSize: 0x210u);
  if ( v22 != nullptr )
    v23 = vgui::RadioButton::RadioButton(this: v22, parent: this, panelName: "BlueRadio", text: "B");
  else
    v23 = nullptr;
  this->m_pBlueRadio = v23;
  v24 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v24 != nullptr )
    v25 = vgui::TextEntry::TextEntry(this: v24, parent: this, panelName: "HueText");
  else
    v25 = nullptr;
  this->m_pHueText = v25;
  v26 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v26 != nullptr )
    v27 = vgui::TextEntry::TextEntry(this: v26, parent: this, panelName: "SaturationText");
  else
    v27 = nullptr;
  this->m_pSaturationText = v27;
  v28 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v28 != nullptr )
    v29 = vgui::TextEntry::TextEntry(this: v28, parent: this, panelName: "ValueText");
  else
    v29 = nullptr;
  this->m_pValueText = v29;
  v30 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v30 != nullptr )
    v31 = vgui::TextEntry::TextEntry(this: v30, parent: this, panelName: "RedText");
  else
    v31 = nullptr;
  this->m_pRedText = v31;
  v32 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v32 != nullptr )
    v33 = vgui::TextEntry::TextEntry(this: v32, parent: this, panelName: "GreenText");
  else
    v33 = nullptr;
  this->m_pGreenText = v33;
  v34 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v34 != nullptr )
    v35 = vgui::TextEntry::TextEntry(this: v34, parent: this, panelName: "BlueText");
  else
    v35 = nullptr;
  this->m_pBlueText = v35;
  v36 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v36 != nullptr )
    v37 = vgui::TextEntry::TextEntry(this: v36, parent: this, panelName: "AlphaText");
  else
    v37 = nullptr;
  this->m_pAlphaText = v37;
  v38 = (vgui::Panel *)operator new(nSize: 0x14Cu);
  if ( v38 != nullptr )
    v39 = vgui::Panel::Panel(this: v38, parent: this, panelName: "InitialColor");
  else
    v39 = nullptr;
  this->m_pInitialColor = v39;
  v40 = (vgui::Panel *)operator new(nSize: 0x14Cu);
  if ( v40 != nullptr )
    v41 = vgui::Panel::Panel(this: v40, parent: this, panelName: "CurrentColor");
  else
    v41 = nullptr;
  m_pInitialColor = this->m_pInitialColor;
  this->m_pCurrentColor = v41;
  m_pInitialColor->SetVisible(this: m_pInitialColor, a2: true);
  this->m_pCurrentColor->SetVisible(this: this->m_pCurrentColor, a2: true);
  this->m_pInitialColor->SetPaintBackgroundEnabled(this: this->m_pInitialColor, a2: true);
  this->m_pCurrentColor->SetPaintBackgroundEnabled(this: this->m_pCurrentColor, a2: true);
  this->m_pInitialColor->SetMouseInputEnabled(this: this->m_pInitialColor, a2: false);
  vgui::Panel::SetMouseInputEnabled(this, state: true);
  CColorPickerPanel::SetInitialColor(this, initialColor: (Color)-1);
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "resource/colorpicker.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104C8D20
// Name: public: virtual struct vgui::PanelMessageMap __near * CColorPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CColorPickerPanel::GetMessageMap(CColorPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CColorPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CColorPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CColorPickerPanel");
  `CColorPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104C8D50
// Name: public: virtual struct PanelAnimationMap __near * CColorPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CColorPickerPanel::GetAnimMap(CColorPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CColorPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x104C8D60
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CColorPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CColorPickerPanel::GetKBMap(CColorPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CColorPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorPickerPanel::GetKBMap'::`2'::s_pMap;
  `CColorPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CColorPickerPanel");
  `CColorPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104C8D90
// Name: public: CColorPickerFrame::CColorPickerFrame(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CColorPickerFrame *__thiscall CColorPickerFrame::CColorPickerFrame(
        CColorPickerFrame *this,
        vgui::Panel *pParent,
        const char *pTitle)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CColorPickerPanel *v7; // eax
  CColorPickerPanel *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  int w; // [esp+8h] [ebp-4h] BYREF

  vgui::Frame::Frame(this, parent: pParent, panelName: "ColorPickerFrame", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CColorPickerFrame_vtbl *)&CColorPickerFrame::`vftable';
  if ( `CColorPickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CColorPickerFrame::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CColorPickerFrame");
    v4->pfnClassName = CColorPickerFrame::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CColorPickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CColorPickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CColorPickerFrame");
    v5->pfnClassName = CColorPickerFrame::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CColorPickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CColorPickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CColorPickerFrame");
    v6->pfnClassName = CColorPickerFrame::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  this->m_pContextKeys = nullptr;
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  v7 = (CColorPickerPanel *)operator new(nSize: 0x1DCu);
  if ( v7 != nullptr )
    v8 = CColorPickerPanel::CColorPickerPanel(this: v7, pParent: this, pName: "ColorPicker");
  else
    v8 = nullptr;
  this->m_pPicker = v8;
  v8->AddActionSignalTarget_2(this: v8, a2: this);
  v9 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "OkButton",
            text: "Ok",
            pActionSignalTarget: this,
            pCmd: "Ok");
  else
    v10 = nullptr;
  this->m_pOpenButton = v10;
  v11 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: this,
            panelName: "CancelButton",
            text: "#FileOpenDialog_Cancel",
            pActionSignalTarget: this,
            pCmd: "Cancel");
  else
    v12 = nullptr;
  this->m_pCancelButton = v12;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "resource/colorpickerframe.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Panel::GetSize(this, wide: &w, tall: (int *)&pParent);
  vgui::Panel::SetMinimumSize(this, wide: w, tall: (int)pParent);
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104C8F60
// Name: public: CColorPickerButton::CColorPickerButton(class vgui::Panel __near *,char const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CColorPickerButton *__thiscall CColorPickerButton::CColorPickerButton(
        CColorPickerButton *this,
        vgui::Panel *pParent,
        const char *pName,
        vgui::Panel *pActionSignalTarget)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Button::Button(this, parent: pParent, panelName: pName, text: &var, pActionSignalTarget: nullptr, pCmd: nullptr);
  this->__vftable = (CColorPickerButton_vtbl *)&CColorPickerButton::`vftable';
  if ( `CColorPickerButton::ChainToMap'::`2'::chained == 0 )
  {
    `CColorPickerButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CColorPickerButton");
    v5->pfnClassName = CColorPickerButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Button");
  }
  if ( `CColorPickerButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CColorPickerButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CColorPickerButton");
    v6->pfnClassName = CColorPickerButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Button");
  }
  if ( `CColorPickerButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CColorPickerButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CColorPickerButton");
    v7->pfnClassName = CColorPickerButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Button");
  }
  CColorPickerButton::PanelMessageFunc_OnPicked::InitVar(a1: (int)&savedregs);
  CColorPickerButton::PanelMessageFunc_OnPreview::InitVar(a1: (int)&savedregs);
  CColorPickerButton::PanelMessageFunc_OnCancelled::InitVar(a1: (int)&savedregs);
  this->m_CurrentColor = 0;
  this->m_CurrentColor = (Color)-1;
  if ( pActionSignalTarget != nullptr )
    vgui::Panel::AddActionSignalTarget(this, messageTarget: pActionSignalTarget);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104C9060
// Name: public: virtual void CColorPickerButton::DoClick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerButton::DoClick(CColorPickerButton *this)
{
  CColorPickerFrame *v2; // eax
  CColorPickerFrame *v3; // esi
  KeyValues *m_pContextKeys; // ecx
  Color m_CurrentColor; // edi

  this->SetSelected(this, a2: true);
  v2 = (CColorPickerFrame *)operator new(nSize: 0x224u);
  if ( v2 != nullptr )
    v3 = CColorPickerFrame::CColorPickerFrame(this: v2, pParent: this, pTitle: "Select Color");
  else
    v3 = nullptr;
  v3->AddActionSignalTarget_2(this: v3, a2: this);
  m_pContextKeys = v3->m_pContextKeys;
  m_CurrentColor = this->m_CurrentColor;
  if ( m_pContextKeys != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeys);
    v3->m_pContextKeys = nullptr;
  }
  CColorPickerPanel::SetInitialColor(this: v3->m_pPicker, initialColor: m_CurrentColor);
  v3->m_pContextKeys = nullptr;
  vgui::Frame::DoModal(this: v3);
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004D5E50
// Name: public: static char const __near * CColorPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CColorPickerPanel::GetPanelClassName()
{
  return "CColorPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x004D5E60
// Name: public: static char const __near * CColorPickerFrame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CColorPickerFrame::GetPanelClassName()
{
  return "CColorPickerFrame";
}

//------------------------------------------------------------------------------
// Address: 0x004D5EE0
// Name: public: static char const __near * CColorXYPreview::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CColorXYPreview::GetPanelClassName()
{
  return "CColorXYPreview";
}

//------------------------------------------------------------------------------
// Address: 0x004D5EF0
// Name: public: void CColorZPreview::SetMode(enum ColorType_t,enum ColorChannel_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorZPreview::SetMode(CColorZPreview *this, ColorType_t type, ColorChannel_t channel)
{
  if ( this->m_Type != type || this->m_Channel != channel )
  {
    this->m_Type = type;
    this->m_Channel = channel;
    CProceduralTexturePanel::DownloadTexture(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D5F20
// Name: private: void CColorXYPreview::ComputeHSVColorForPoint(int,int,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorXYPreview::ComputeHSVColorForPoint(CColorXYPreview *this, int x, int y, Vector *vscHSV)
{
  float *v5; // ebx

  *vscHSV = this->m_CurrentHSVColor;
  *(&vscHSV->x + CColorXYPreview::s_pHSVRemapX[this->m_Channel]) = (float)x * 0.0039215689;
  v5 = &vscHSV->x + CColorXYPreview::s_pHSVRemapY[this->m_Channel];
  *v5 = (float)(CElementTreeViewListControl::GetTreeColumnWidth(this) - y - 1) * 0.0039215689;
  if ( vscHSV->y == 0.0 )
    vscHSV->x = -1.0;
  if ( this->m_Channel != CHANNEL_RED && vscHSV->x != -1.0 )
    vscHSV->x = vscHSV->x * 360.0;
}

//------------------------------------------------------------------------------
// Address: 0x004D5FE0
// Name: public: virtual void CColorXYPreview::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorXYPreview::Paint(CColorXYPreview *this)
{
  float z; // eax
  ColorChannel_t v3; // ecx
  ColorChannel_t v4; // edx
  int v5; // ebx
  int TreeColumnWidth; // eax
  int v7; // edi
  int v8; // esi
  int v9; // edi
  Vector vecHSVNormalized; // [esp+Ch] [ebp-18h] BYREF
  int h; // [esp+18h] [ebp-Ch] BYREF
  int w; // [esp+1Ch] [ebp-8h] BYREF
  float *v13; // [esp+20h] [ebp-4h]

  CProceduralTexturePanel::Paint(this);
  if ( this->m_Type != COLOR_TYPE_RGB )
  {
    z = this->m_CurrentHSVColor.z;
    *(_QWORD *)&vecHSVNormalized.x = *(_QWORD *)&this->m_CurrentHSVColor.x;
    vecHSVNormalized.z = z;
    if ( vecHSVNormalized.x != -1.0 )
      vecHSVNormalized.x = vecHSVNormalized.x * 0.70833331;
    v3 = CColorXYPreview::s_pHSVRemapX[this->m_Channel];
    v4 = CColorXYPreview::s_pHSVRemapY[this->m_Channel];
    vecHSVNormalized.y = vecHSVNormalized.y * 255.0;
    vecHSVNormalized.z = vecHSVNormalized.z * 255.0;
    v5 = (int)(float)(*(&vecHSVNormalized.x + v3) + 0.5);
    v13 = &vecHSVNormalized.x + v4;
    TreeColumnWidth = CElementTreeViewListControl::GetTreeColumnWidth(this);
    v7 = TreeColumnWidth - (int)(float)(*v13 + 0.5);
  }
  else
  {
    v5 = *(&this->m_CurrentColor.r + CColorXYPreview::s_pRGBRemapX[this->m_Channel]);
    v7 = CElementTreeViewListControl::GetTreeColumnWidth(this)
       - *(&this->m_CurrentColor.r + CColorXYPreview::s_pRGBRemapY[this->m_Channel]);
  }
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  v8 = (int)(float)((float)((float)((float)w * (float)v5) * 0.0039215689) + 0.5);
  v9 = (int)(float)((float)((float)((float)h * (float)(v7 - 1)) * 0.0039215689) + 0.5);
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
  g_pVGuiSurface->DrawOutlinedCircle(this: g_pVGuiSurface, a2: v8, a3: v9, a4: 5, a5: 8);
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 0, a3: 0, a4: 0, a5: 255);
  g_pVGuiSurface->DrawOutlinedCircle(this: g_pVGuiSurface, a2: v8, a3: v9, a4: 6, a5: 8);
}

//------------------------------------------------------------------------------
// Address: 0x004D61B0
// Name: public: virtual void CColorXYPreview::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorXYPreview::OnMouseReleased(CColorXYPreview *this, const char *code)
{
  vgui::Panel::OnMousePressed(this, panelName: code);
  if ( code == (const char *)107 && this->m_bDraggingMouse )
  {
    this->m_bDraggingMouse = false;
    g_pVGuiInput->SetMouseCapture(this: g_pVGuiInput, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D61F0
// Name: public: static char const __near * CColorZPreview::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CColorZPreview::GetPanelClassName()
{
  return "CColorZPreview";
}

//------------------------------------------------------------------------------
// Address: 0x004D6200
// Name: public: void CColorZPreview::SetColor(struct RGB888_t const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorZPreview::SetColor(CColorZPreview *this, const RGB888_t *color, const Vector *hsvColor)
{
  if ( color->r != this->m_CurrentColor.r
    || color->g != this->m_CurrentColor.g
    || color->b != this->m_CurrentColor.b
    || hsvColor->x != this->m_CurrentHSVColor.x
    || hsvColor->y != this->m_CurrentHSVColor.y
    || hsvColor->z != this->m_CurrentHSVColor.z )
  {
    this->m_CurrentColor = *color;
    this->m_CurrentHSVColor = *hsvColor;
    CProceduralTexturePanel::DownloadTexture(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D62A0
// Name: public: virtual void CColorZPreview::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorZPreview::PerformLayout(CColorZPreview *this)
{
  Rect_t r; // [esp+4h] [ebp-18h] BYREF
  int h; // [esp+14h] [ebp-8h] BYREF
  int w; // [esp+18h] [ebp-4h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  r.x = 6;
  r.y = 6;
  r.width = w - 12;
  r.height = h - 12;
  CProceduralTexturePanel::SetPaintRect(this, pPaintRect: &r);
}

//------------------------------------------------------------------------------
// Address: 0x004D62F0
// Name: public: virtual void CColorZPreview::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorZPreview::OnMouseReleased(CColorZPreview *this, const char *code)
{
  vgui::Panel::OnMousePressed(this, panelName: code);
  if ( code == (const char *)107 && this->m_bDraggingMouse )
  {
    this->m_bDraggingMouse = false;
    g_pVGuiInput->SetMouseCapture(this: g_pVGuiInput, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D6330
// Name: public: virtual void CColorZPreview::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorZPreview::Paint(CColorZPreview *this)
{
  float z; // eax
  ColorChannel_t m_Channel; // ecx
  int TreeColumnWidth; // eax
  int v5; // esi
  float v6; // xmm0_4
  int v7; // esi
  int py[3]; // [esp+8h] [ebp-30h] BYREF
  int px[3]; // [esp+14h] [ebp-24h] BYREF
  Vector vecHSVNormalized; // [esp+20h] [ebp-18h] BYREF
  int w; // [esp+2Ch] [ebp-Ch] BYREF
  float *v12; // [esp+30h] [ebp-8h]
  int h; // [esp+34h] [ebp-4h] BYREF

  CProceduralTexturePanel::Paint(this);
  if ( this->m_Type != COLOR_TYPE_RGB )
  {
    z = this->m_CurrentHSVColor.z;
    *(_QWORD *)&vecHSVNormalized.x = *(_QWORD *)&this->m_CurrentHSVColor.x;
    vecHSVNormalized.z = z;
    if ( vecHSVNormalized.x != -1.0 )
      vecHSVNormalized.x = vecHSVNormalized.x * 0.70833331;
    m_Channel = this->m_Channel;
    vecHSVNormalized.y = vecHSVNormalized.y * 255.0;
    vecHSVNormalized.z = vecHSVNormalized.z * 255.0;
    v12 = &vecHSVNormalized.x + m_Channel;
    TreeColumnWidth = CElementTreeViewListControl::GetTreeColumnWidth(this);
    v5 = TreeColumnWidth - (int)(float)(*v12 + 0.5);
  }
  else
  {
    v5 = CElementTreeViewListControl::GetTreeColumnWidth(this) - *(&this->m_CurrentColor.r + this->m_Channel);
  }
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  v6 = (float)(h - 12);
  h -= 12;
  v7 = (int)(float)((float)((float)(v6 * (float)(v5 - 1)) * 0.0039215689) + 0.5);
  g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
  py[1] = v7 + 12;
  py[0] = v7;
  px[0] = 0;
  px[1] = 0;
  px[2] = 6;
  py[2] = v7 + 6;
  g_pVGuiSurface->DrawPolyLine(this: g_pVGuiSurface, a2: px, a3: py, a4: 3);
  px[1] = w - 1;
  px[0] = w - 1;
  px[2] = w - 7;
  g_pVGuiSurface->DrawPolyLine(this: g_pVGuiSurface, a2: px, a3: py, a4: 3);
}

//------------------------------------------------------------------------------
// Address: 0x004D64C0
// Name: private: void CColorPickerPanel::UpdatePreviewColors(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerPanel::UpdatePreviewColors(CColorPickerPanel *this)
{
  Color c; // [esp+4h] [ebp-4h]

  *(RGB888_t *)c._color = this->m_InitialColor;
  c._color[3] = -1;
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pInitialColor->SetBgColor)(a1: this->m_pInitialColor, a2: c);
  *(RGB888_t *)c._color = this->m_CurrentColor;
  c._color[3] = -1;
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pCurrentColor->SetBgColor)(a1: this->m_pCurrentColor, a2: c);
}

//------------------------------------------------------------------------------
// Address: 0x004D6540
// Name: public: virtual void CColorPickerPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerPanel::ApplySchemeSettings(CColorPickerPanel *this, vgui::IScheme *pScheme)
{
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  CColorPickerPanel::UpdatePreviewColors(this);
}

//------------------------------------------------------------------------------
// Address: 0x004D6560
// Name: private: virtual void CColorPickerPanel::OnRadioButtonChecked(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerPanel::OnRadioButtonChecked(CColorPickerPanel *this, KeyValues *pKeyValues)
{
  vgui::RadioButton *Ptr; // eax
  CColorXYPreview *m_pColorXYPreview; // ecx
  CColorZPreview *m_pColorZPreview; // ecx
  int v6; // edi
  CColorXYPreview *v7; // ecx
  CColorZPreview *v8; // ecx

  Ptr = (vgui::RadioButton *)KeyValues::GetPtr(this: pKeyValues, keyName: "panel", defaultValue: nullptr);
  if ( Ptr == this->m_pRedRadio )
  {
    m_pColorXYPreview = this->m_pColorXYPreview;
    if ( m_pColorXYPreview->m_Type != COLOR_TYPE_RGB || m_pColorXYPreview->m_Channel != CHANNEL_RED )
    {
      m_pColorXYPreview->m_Type = COLOR_TYPE_RGB;
      m_pColorXYPreview->m_Channel = CHANNEL_RED;
      CProceduralTexturePanel::DownloadTexture(this: m_pColorXYPreview);
    }
    m_pColorZPreview = this->m_pColorZPreview;
    if ( m_pColorZPreview->m_Type != COLOR_TYPE_RGB || m_pColorZPreview->m_Channel != CHANNEL_RED )
    {
      m_pColorZPreview->m_Type = COLOR_TYPE_RGB;
      m_pColorZPreview->m_Channel = CHANNEL_RED;
      CProceduralTexturePanel::DownloadTexture(this: m_pColorZPreview);
    }
    return;
  }
  if ( Ptr == this->m_pGreenRadio )
  {
    v6 = 1;
    goto LABEL_12;
  }
  if ( Ptr == this->m_pBlueRadio )
  {
    v6 = 2;
LABEL_12:
    v7 = this->m_pColorXYPreview;
    if ( v7->m_Type != COLOR_TYPE_RGB || v7->m_Channel != v6 )
    {
      v7->m_Type = COLOR_TYPE_RGB;
      v7->m_Channel = v6;
      CProceduralTexturePanel::DownloadTexture(this: v7);
    }
    v8 = this->m_pColorZPreview;
    if ( v8->m_Type != COLOR_TYPE_RGB || v8->m_Channel != v6 )
    {
      v8->m_Type = COLOR_TYPE_RGB;
      v8->m_Channel = v6;
      CProceduralTexturePanel::DownloadTexture(this: v8);
    }
    return;
  }
  if ( Ptr == this->m_pHueRadio )
  {
    CColorZPreview::SetMode(this: (CColorZPreview *)this->m_pColorXYPreview, type: COLOR_TYPE_HSV, channel: CHANNEL_RED);
    CColorZPreview::SetMode(this: this->m_pColorZPreview, type: COLOR_TYPE_HSV, channel: CHANNEL_RED);
  }
  else if ( Ptr == this->m_pSaturationRadio )
  {
    CColorZPreview::SetMode(
      this: (CColorZPreview *)this->m_pColorXYPreview,
      type: COLOR_TYPE_HSV,
      channel: CHANNEL_GREEN);
    CColorZPreview::SetMode(this: this->m_pColorZPreview, type: COLOR_TYPE_HSV, channel: CHANNEL_GREEN);
  }
  else if ( Ptr == this->m_pValueRadio )
  {
    CColorZPreview::SetMode(
      this: (CColorZPreview *)this->m_pColorXYPreview,
      type: COLOR_TYPE_HSV,
      channel: CHANNEL_BLUE);
    CColorZPreview::SetMode(this: this->m_pColorZPreview, type: COLOR_TYPE_HSV, channel: CHANNEL_BLUE);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D66E0
// Name: private: void CColorPickerPanel::OnColorChanged(class vgui::TextEntry __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerPanel::OnColorChanged(CColorPickerPanel *this, vgui::TextEntry *pChanged)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  char temp[256]; // [esp+8h] [ebp-100h] BYREF

  if ( pChanged != this->m_pRedText )
  {
    V_snprintf(pDest: temp, maxLen: 256, pFormat: "%d", this->m_CurrentColor.r);
    this->m_pRedText->SetText(this: this->m_pRedText, a2: temp);
  }
  if ( pChanged != this->m_pGreenText )
  {
    V_snprintf(pDest: temp, maxLen: 256, pFormat: "%d", this->m_CurrentColor.g);
    this->m_pGreenText->SetText(this: this->m_pGreenText, a2: temp);
  }
  if ( pChanged != this->m_pBlueText )
  {
    V_snprintf(pDest: temp, maxLen: 256, pFormat: "%d", this->m_CurrentColor.b);
    this->m_pBlueText->SetText(this: this->m_pBlueText, a2: temp);
  }
  if ( pChanged != this->m_pAlphaText )
  {
    V_snprintf(pDest: temp, maxLen: 256, pFormat: "%d", this->m_CurrentAlpha);
    this->m_pAlphaText->SetText(this: this->m_pAlphaText, a2: temp);
  }
  if ( pChanged != this->m_pHueText )
  {
    V_snprintf(pDest: temp, maxLen: 256, pFormat: "%d", (int)(float)(this->m_CurrentHSVColor.x + 0.5));
    this->m_pHueText->SetText(this: this->m_pHueText, a2: temp);
  }
  if ( pChanged != this->m_pSaturationText )
  {
    V_snprintf(pDest: temp, maxLen: 256, pFormat: "%d", (int)(float)((float)(this->m_CurrentHSVColor.y * 100.0) + 0.5));
    this->m_pSaturationText->SetText(this: this->m_pSaturationText, a2: temp);
  }
  if ( pChanged != this->m_pValueText )
  {
    V_snprintf(pDest: temp, maxLen: 256, pFormat: "%d", (int)(float)((float)(this->m_CurrentHSVColor.z * 100.0) + 0.5));
    this->m_pValueText->SetText(this: this->m_pValueText, a2: temp);
  }
  CColorZPreview::SetColor(
    this: (CColorZPreview *)this->m_pColorXYPreview,
    color: &this->m_CurrentColor,
    hsvColor: &this->m_CurrentHSVColor);
  CColorZPreview::SetColor(
    this: this->m_pColorZPreview,
    color: &this->m_CurrentColor,
    hsvColor: &this->m_CurrentHSVColor);
  CColorPickerPanel::UpdatePreviewColors(this);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "command", firstKey: "command", firstValue: "preview");
  else
    v4 = nullptr;
  this->PostActionSignal(this, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004D6960
// Name: public: virtual void CColorPickerFrame::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerFrame::OnCommand(CColorPickerFrame *this, const char *pCommand)
{
  CColorPickerPanel *m_pPicker; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // edi
  KeyValues *v6; // eax
  CColorPickerPanel *v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  KeyValues *m_pContextKeys; // ecx
  KeyValues *Copy; // eax
  Color c; // [esp+10h] [ebp+8h]
  Color ca; // [esp+10h] [ebp+8h]

  if ( _V_stricmp(s1: pCommand, s2: "Ok") == 0 )
  {
    m_pPicker = this->m_pPicker;
    c._color[0] = m_pPicker->m_CurrentColor.r;
    *(_WORD *)&c._color[1] = *(_WORD *)&m_pPicker->m_CurrentColor.g;
    c._color[3] = m_pPicker->m_CurrentAlpha;
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "ColorPickerPicked");
    else
      v5 = nullptr;
    KeyValues::SetColor(this: v5, keyName: "color", value: c);
    if ( this->m_pContextKeys != nullptr )
    {
      KeyValues::AddSubKey(this: v5, pSubkey: this->m_pContextKeys);
      this->m_pContextKeys = nullptr;
    }
LABEL_7:
    this->CloseModal(this);
    this->PostActionSignal(this, a2: v5);
    return;
  }
  if ( _V_stricmp(s1: pCommand, s2: "Cancel") == 0 )
  {
    g_pVGuiInput->ReleaseAppModalSurface(this: g_pVGuiInput);
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v5 = KeyValues::KeyValues(this: v6, setName: "ColorPickerCancel");
    else
      v5 = nullptr;
    if ( this->m_pContextKeys != nullptr )
    {
      KeyValues::AddSubKey(this: v5, pSubkey: this->m_pContextKeys);
      this->m_pContextKeys = nullptr;
    }
    goto LABEL_7;
  }
  if ( _V_stricmp(s1: pCommand, s2: "Preview") != 0 )
  {
    vgui::Frame::OnCommand(this, command: pCommand);
  }
  else
  {
    v7 = this->m_pPicker;
    ca._color[0] = v7->m_CurrentColor.r;
    *(_WORD *)&ca._color[1] = *(_WORD *)&v7->m_CurrentColor.g;
    ca._color[3] = v7->m_CurrentAlpha;
    v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v8 != nullptr )
      v9 = KeyValues::KeyValues(this: v8, setName: "ColorPickerPreview");
    else
      v9 = nullptr;
    KeyValues::SetColor(this: v9, keyName: "color", value: ca);
    m_pContextKeys = this->m_pContextKeys;
    if ( m_pContextKeys != nullptr )
    {
      Copy = KeyValues::MakeCopy(this: m_pContextKeys);
      KeyValues::AddSubKey(this: v9, pSubkey: Copy);
    }
    this->PostActionSignal(this, a2: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D6B50
// Name: VectorToRGB888
// Source: json
//------------------------------------------------------------------------------
void __usercall VectorToRGB888(const Vector *inVector@<eax>, RGB888_t *outColor@<esi>)
{
  int v2; // ecx
  int v3; // edx
  int v4; // eax

  v2 = (int)(float)((float)(inVector->x * 255.0) + 0.5);
  v3 = (int)(float)((float)(inVector->y * 255.0) + 0.5);
  v4 = (int)(float)((float)(inVector->z * 255.0) + 0.5);
  if ( v2 >= 0 )
  {
    if ( v2 > 255 )
      LOBYTE(v2) = -1;
  }
  else
  {
    LOBYTE(v2) = 0;
  }
  outColor->r = v2;
  if ( v3 >= 0 )
  {
    if ( v3 > 255 )
      LOBYTE(v3) = -1;
  }
  else
  {
    LOBYTE(v3) = 0;
  }
  outColor->g = v3;
  if ( v4 >= 0 )
  {
    if ( v4 > 255 )
      LOBYTE(v4) = -1;
    outColor->b = v4;
  }
  else
  {
    outColor->b = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D6C00
// Name: public: CColorXYPreview::CColorXYPreview(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CColorXYPreview *__thiscall CColorXYPreview::CColorXYPreview(
        CColorXYPreview *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  unsigned int v7; // eax

  CProceduralTexturePanel::CProceduralTexturePanel(this, pParent, pName);
  this->CProceduralTexturePanel::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CColorXYPreview_vtbl *)&CColorXYPreview::`vftable'{for `vgui::EditablePanel'};
  this->CProceduralTexturePanel::ITextureRegenerator::__vftable = (ITextureRegenerator_vtbl *)&CColorXYPreview::`vftable'{for `ITextureRegenerator'};
  if ( `CColorXYPreview::ChainToMap'::`2'::chained == 0 )
  {
    `CColorXYPreview::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CColorXYPreview");
    v4->pfnClassName = CColorXYPreview::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CProceduralTexturePanel");
  }
  if ( `CColorXYPreview::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CColorXYPreview::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CColorXYPreview");
    v5->pfnClassName = CColorXYPreview::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CProceduralTexturePanel");
  }
  if ( `CColorXYPreview::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CColorXYPreview::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CColorXYPreview");
    v6->pfnClassName = CColorXYPreview::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CProceduralTexturePanel");
  }
  CProceduralTexturePanel::Init(this, nWidth: 256, nHeight: 256, bAllocateImageBuffer: false);
  *(_WORD *)&this->m_CurrentColor.g = -1;
  this->m_CurrentColor.r = -1;
  if ( this->m_Type != COLOR_TYPE_HSV || this->m_Channel != CHANNEL_RED )
  {
    this->m_Type = COLOR_TYPE_HSV;
    this->m_Channel = CHANNEL_RED;
    CProceduralTexturePanel::DownloadTexture(this);
  }
  vgui::Panel::SetMouseInputEnabled(this, state: true);
  v7 = g_pVGuiSurface->CreateCursorFromFile(this: g_pVGuiSurface, a2: "resource/colorpicker.cur", a3: nullptr);
  this->m_hPickerCursor = v7;
  vgui::Panel::SetCursor(this, cursor: v7);
  this->m_bDraggingMouse = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004D6D50
// Name: public: virtual struct vgui::PanelMessageMap __near * CColorXYPreview::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CColorXYPreview::GetMessageMap(CColorXYPreview *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CColorXYPreview::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorXYPreview::GetMessageMap'::`2'::s_pMap;
  `CColorXYPreview::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CColorXYPreview");
  `CColorXYPreview::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D6D80
// Name: public: virtual struct PanelAnimationMap __near * CColorXYPreview::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CColorXYPreview::GetAnimMap(CColorXYPreview *this)
{
  return FindOrAddPanelAnimationMap(className: "CColorXYPreview");
}

//------------------------------------------------------------------------------
// Address: 0x004D6D90
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CColorXYPreview::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CColorXYPreview::GetKBMap(CColorXYPreview *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CColorXYPreview::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorXYPreview::GetKBMap'::`2'::s_pMap;
  `CColorXYPreview::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CColorXYPreview");
  `CColorXYPreview::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D6DC0
// Name: public: virtual void CColorXYPreview::RegenerateTextureBits(class ITexture __near *,class IVTFTexture __near *,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorXYPreview::RegenerateTextureBits(
        CColorXYPreview *this,
        ITexture *pTexture,
        IVTFTexture *pVTFTexture,
        Rect_t *pRect)
{
  IVTFTexture *v4; // esi
  CColorXYPreview *v5; // ebx
  void (__thiscall *ComputeMipLevelDimensions)(IVTFTexture *, int, int *, int *, int *); // edx
  unsigned __int16 v7; // di
  int v8; // eax
  int v9; // esi
  int v10; // eax
  int v11; // edx
  int v12; // ecx
  IVTFTexture *v13; // edi
  int v14; // ecx
  unsigned __int8 *m_pMemory; // eax
  int *p_m_nAllocationCount; // esi
  int v17; // ebx
  int TreeColumnWidth; // eax
  float v19; // xmm0_4
  int v20; // eax
  int v21; // ecx
  float v22; // xmm2_4
  int v23; // esi
  char v24; // dl
  int v25; // eax
  char v26; // cl
  int v27; // eax
  char v28; // al
  unsigned __int8 *v29; // edx
  int v30; // esi
  int v31; // eax
  unsigned int v32; // edx
  unsigned int v33; // edx
  int v34; // eax
  unsigned __int64 v35; // rdi
  __int64 v36; // rax
  __int64 v37; // rax
  int v38; // ebx
  unsigned __int64 v39; // rax
  IVTFTexture *pixelWriter_4; // [esp+10h] [ebp-6Ch]
  unsigned __int8 pixelWriter_10; // [esp+16h] [ebp-66h]
  int pixelWriter_12; // [esp+18h] [ebp-64h]
  int pixelWriter_16; // [esp+1Ch] [ebp-60h]
  char pixelWriter_20; // [esp+20h] [ebp-5Ch]
  char pixelWriter_24; // [esp+24h] [ebp-58h]
  int pixelWriter_28; // [esp+28h] [ebp-54h]
  unsigned __int8 pixelWriter_32; // [esp+2Ch] [ebp-50h]
  Vector rgb; // [esp+30h] [ebp-4Ch] BYREF
  Vector vecHSV; // [esp+3Ch] [ebp-40h] BYREF
  int v50; // [esp+4Ch] [ebp-30h]
  int nDepth; // [esp+50h] [ebp-2Ch] BYREF
  int v52; // [esp+54h] [ebp-28h]
  int nHeight; // [esp+58h] [ebp-24h] BYREF
  IVTFTexture *v54; // [esp+5Ch] [ebp-20h]
  CColorXYPreview *v55; // [esp+60h] [ebp-1Ch]
  int nWidth; // [esp+64h] [ebp-18h] BYREF
  int v57; // [esp+68h] [ebp-14h]
  int v58; // [esp+6Ch] [ebp-10h]
  int y; // [esp+70h] [ebp-Ch]
  int x; // [esp+74h] [ebp-8h]
  int v61; // [esp+78h] [ebp-4h]

  v4 = pVTFTexture;
  v5 = this;
  ComputeMipLevelDimensions = pVTFTexture->ComputeMipLevelDimensions;
  v55 = this;
  ComputeMipLevelDimensions(this: pVTFTexture, a2: 0, a3: &nWidth, a4: &nHeight, a5: &nDepth);
  v7 = v4->RowSizeInBytes(this: v4, a2: 0);
  pVTFTexture = (IVTFTexture *)v4->ImageData_2(this: v4, a2: 0, a3: 0, a4: 0);
  v8 = v4->Format(this: v4);
  v9 = v8;
  switch ( v8 )
  {
    case 0:
    case 23:
      v10 = 255;
      pixelWriter_10 = 4;
      pixelWriter_12 = 0x80000;
      pixelWriter_16 = 1572880;
      pixelWriter_20 = -1;
      goto LABEL_19;
    case 3:
      v10 = 255;
      pixelWriter_10 = 3;
      pixelWriter_12 = 524304;
      pixelWriter_16 = 0;
      pixelWriter_20 = -1;
      pixelWriter_32 = 0;
      goto LABEL_20;
    case 5:
      pixelWriter_10 = 1;
      pixelWriter_12 = 0;
      pixelWriter_16 = 0;
      goto LABEL_17;
    case 8:
      v10 = 0;
      pixelWriter_10 = 1;
      pixelWriter_12 = 0;
      pixelWriter_16 = 0;
      pixelWriter_20 = 0;
      pixelWriter_32 = -1;
      goto LABEL_20;
    case 12:
      v10 = 255;
      pixelWriter_10 = 4;
      pixelWriter_12 = 524304;
      pixelWriter_16 = 1572864;
      pixelWriter_20 = -1;
      goto LABEL_19;
    case 16:
      v10 = 255;
      pixelWriter_10 = 4;
      pixelWriter_12 = 524304;
      pixelWriter_16 = 1572864;
      pixelWriter_20 = -1;
      pixelWriter_32 = 0;
      goto LABEL_20;
    case 17:
      v10 = 248;
      pixelWriter_10 = 2;
      pixelWriter_12 = 196616;
      pixelWriter_16 = 65533;
      pixelWriter_20 = -8;
      pixelWriter_24 = -4;
      pixelWriter_32 = 0;
      goto LABEL_21;
    case 18:
    case 21:
      v10 = 248;
      pixelWriter_10 = 2;
      pixelWriter_12 = 131079;
      pixelWriter_16 = 589821;
      pixelWriter_20 = -8;
      pixelWriter_32 = 0x80;
      goto LABEL_20;
    case 19:
      v10 = 240;
      pixelWriter_10 = 2;
      pixelWriter_12 = 4;
      pixelWriter_16 = 589820;
      pixelWriter_20 = -16;
      goto LABEL_19;
    case 24:
    case 25:
      v10 = 0xFFFF;
      pixelWriter_10 = 8;
      pixelWriter_12 = 0x100000;
      pixelWriter_16 = 3145760;
      pixelWriter_20 = -1;
      goto LABEL_19;
    case 27:
      pixelWriter_10 = 4;
      pixelWriter_12 = 0;
      pixelWriter_16 = 0;
      pixelWriter_20 = -1;
      goto LABEL_18;
    case 29:
      v10 = -1;
      pixelWriter_10 = 16;
      pixelWriter_12 = 0x200000;
      pixelWriter_16 = (int)&loc_60003D + 3;
      pixelWriter_20 = -1;
      goto LABEL_19;
    default:
      if ( `CPixelWriter::SetPixelMemory'::`10'::format_error_printed[v8] == 0 )
      {
        _Msg(a1: "CPixelWriter::SetPixelMemory:  Unsupported image format %i\n", v8);
        `CPixelWriter::SetPixelMemory'::`10'::format_error_printed[v9] = 1;
      }
      pixelWriter_10 = 0;
      pixelWriter_12 = 0;
      pixelWriter_16 = 0;
LABEL_17:
      pixelWriter_20 = -1;
LABEL_18:
      v10 = 0;
LABEL_19:
      pixelWriter_32 = v10;
LABEL_20:
      pixelWriter_24 = v10;
LABEL_21:
      pixelWriter_28 = v10;
      y = 0;
      if ( nHeight > 0 )
      {
        v11 = nWidth;
        v12 = v7;
        v13 = pVTFTexture;
        v52 = v12;
        v58 = -1;
        v54 = pVTFTexture;
        do
        {
          v14 = 0;
          pixelWriter_4 = v13;
          x = 0;
          if ( v11 > 0 )
          {
            v61 = pixelWriter_10;
            while ( 1 )
            {
              if ( v5->_vpanel != 0 )
              {
                m_pMemory = v5->_panelName.m_Storage.m_Memory.m_pMemory;
                p_m_nAllocationCount = &v5[-1]._actionSignalTargetDar.m_Memory.m_nAllocationCount;
                vecHSV = *(Vector *)&v5->_panelName.m_Storage.m_Memory.m_nGrowSize;
                m_pMemory = (unsigned __int8 *)(2 * (_DWORD)m_pMemory);
                v17 = *(ColorChannel_t *)((char *)CColorXYPreview::s_pHSVRemapY + 2 * (_DWORD)m_pMemory);
                *(&vecHSV.x + *(ColorChannel_t *)((char *)CColorXYPreview::s_pHSVRemapX + 2 * (_DWORD)m_pMemory)) = (float)v14 * 0.0039215689;
                TreeColumnWidth = CElementTreeViewListControl::GetTreeColumnWidth(this: (CProceduralTexturePanel *)p_m_nAllocationCount);
                *(&vecHSV.x + v17) = (float)(v58 + TreeColumnWidth) * 0.0039215689;
                if ( vecHSV.y == 0.0 )
                {
                  v19 = -1.0;
                  vecHSV.x = -1.0;
                }
                else
                {
                  v19 = vecHSV.x;
                }
                if ( p_m_nAllocationCount[114] != 0 && v19 != -1.0 )
                  vecHSV.x = v19 * 360.0;
                HSVtoRGB(hsv: &vecHSV, &rgb);
                v20 = (int)(float)((float)(rgb.x * 255.0) + 0.5);
                v21 = (int)(float)((float)(rgb.y * 255.0) + 0.5);
                v22 = (float)(rgb.z * 255.0) + 0.5;
                v23 = (int)v22;
                if ( v20 >= 0 )
                {
                  if ( v20 > 255 )
                    LOBYTE(v20) = -1;
                }
                else
                {
                  LOBYTE(v20) = 0;
                }
                v24 = v20;
                if ( v21 >= 0 )
                {
                  LOBYTE(v25) = -1;
                  if ( v21 <= 255 )
                    v25 = (int)(float)((float)(rgb.y * 255.0) + 0.5);
                }
                else
                {
                  LOBYTE(v25) = 0;
                }
                v26 = v25;
                if ( v23 >= 0 )
                {
                  LOBYTE(v27) = -1;
                  if ( v23 <= 255 )
                    v27 = (int)v22;
                }
                else
                {
                  LOBYTE(v27) = 0;
                }
              }
              else
              {
                v28 = BYTE2(v5->_panelName.m_Storage.m_Memory.m_nAllocationCount);
                LOWORD(pVTFTexture) = v5->_panelName.m_Storage.m_Memory.m_nAllocationCount;
                v29 = v5->_panelName.m_Storage.m_Memory.m_pMemory;
                BYTE2(pVTFTexture) = v28;
                *((_BYTE *)&pVTFTexture + CColorXYPreview::s_pRGBRemapX[(_DWORD)v29]) = v14;
                LOBYTE(v27) = CElementTreeViewListControl::GetTreeColumnWidth(this: (CColorXYPreview *)((char *)v5 - 380));
                *((_BYTE *)&pVTFTexture + CColorXYPreview::s_pRGBRemapY[(int)v5->_panelName.m_Storage.m_Memory.m_pMemory]) = -1 - y + v27;
                LOBYTE(v27) = BYTE2(pVTFTexture);
                v26 = BYTE1(pVTFTexture);
                v24 = (char)pVTFTexture;
              }
              v30 = (unsigned __int8)v27;
              v57 = (unsigned __int8)v27;
              if ( pixelWriter_10 != 0 )
              {
                if ( pixelWriter_10 >= 5u )
                {
                  v35 = ((unsigned __int64)(unsigned __int8)(v26 & pixelWriter_24) << SBYTE2(pixelWriter_12))
                      | ((unsigned __int64)(unsigned __int8)(v24 & pixelWriter_20) << pixelWriter_12);
                  v36 = v57 & (unsigned int)pixelWriter_28;
                  if ( (__int16)pixelWriter_16 <= 0 )
                    v37 = v36 >> -(char)pixelWriter_16;
                  else
                    v37 = v36 << pixelWriter_16;
                  v50 = HIDWORD(v37);
                  v38 = v37;
                  v39 = (unsigned __int64)pixelWriter_32 << SBYTE2(pixelWriter_16);
                  LODWORD(v35) = v38 | v39 | v35;
                  HIDWORD(v35) |= v50 | HIDWORD(v39);
                  if ( v61 == 6 )
                  {
                    pixelWriter_4->__vftable = (IVTFTexture_vtbl *)v35;
                    LOWORD(pixelWriter_4[1].__vftable) = WORD2(v35);
                  }
                  else if ( v61 == 8 )
                  {
                    *(_QWORD *)&pixelWriter_4->__vftable = v35;
                  }
                  v13 = pixelWriter_4;
                }
                else
                {
                  v31 = ((unsigned __int8)(v26 & pixelWriter_24) << SBYTE2(pixelWriter_12))
                      | ((unsigned __int8)(v24 & pixelWriter_20) << pixelWriter_12);
                  v32 = v30 & pixelWriter_28;
                  if ( (__int16)pixelWriter_16 <= 0 )
                    v33 = v32 >> -(char)pixelWriter_16;
                  else
                    v33 = v32 << pixelWriter_16;
                  v34 = v33 | (pixelWriter_32 << SBYTE2(pixelWriter_16)) | v31;
                  switch ( v61 )
                  {
                    case 1:
                      LOBYTE(v13->__vftable) = v34;
                      break;
                    case 2:
                      LOWORD(v13->__vftable) = v34;
                      break;
                    case 3:
                      LOWORD(v13->__vftable) = v34;
                      BYTE2(v13->__vftable) = BYTE2(v34);
                      break;
                    case 4:
                      v13->__vftable = (IVTFTexture_vtbl *)v34;
                      break;
                    default:
                      break;
                  }
                }
              }
              v13 = (IVTFTexture *)((char *)v13 + v61);
              v11 = nWidth;
              v5 = v55;
              pixelWriter_4 = v13;
              if ( ++x >= nWidth )
                break;
              v14 = x;
            }
          }
          v13 = (IVTFTexture *)((char *)v54 + v52);
          --v58;
          ++y;
          v54 = (IVTFTexture *)((char *)v54 + v52);
        }
        while ( y < nHeight );
      }
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D73B0
// Name: private: void CColorXYPreview::UpdateColorFromMouse(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorXYPreview::UpdateColorFromMouse(CColorXYPreview *this, float x, float y)
{
  float v4; // xmm0_4
  float v5; // xmm1_4
  int ImageWidth; // eax
  int v7; // ebx
  int TreeColumnWidth; // eax
  bool v9; // zf
  float v10; // xmm0_4
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  Vector *p_rgb; // eax
  unsigned __int8 b; // al
  ColorChannel_t m_Channel; // ecx
  ColorChannel_t v16; // edx
  char v17; // al
  unsigned __int8 v18; // bl
  KeyValues *v19; // eax
  KeyValues *v20; // esi
  Vector rgb; // [esp+10h] [ebp-20h] BYREF
  Vector vecHSV; // [esp+1Ch] [ebp-14h] BYREF
  int h; // [esp+28h] [ebp-8h] BYREF
  int w; // [esp+2Ch] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  v4 = (float)SLODWORD(x) / (float)(w - 1);
  v5 = (float)SLODWORD(y) / (float)(h - 1);
  if ( v4 >= 0.0 )
  {
    if ( v4 <= 1.0 )
      x = (float)SLODWORD(x) / (float)(w - 1);
    else
      x = 1.0;
  }
  else
  {
    x = 0.0;
  }
  if ( v5 >= 0.0 )
  {
    if ( v5 <= 1.0 )
      y = (float)SLODWORD(y) / (float)(h - 1);
    else
      y = 1.0;
  }
  else
  {
    y = 0.0;
  }
  ImageWidth = CProceduralTexturePanel::GetImageWidth(this);
  v7 = (int)(float)((float)((float)(ImageWidth - 1) * x) + 0.5);
  TreeColumnWidth = CElementTreeViewListControl::GetTreeColumnWidth(this);
  v9 = this->m_Type == COLOR_TYPE_RGB;
  v10 = (float)((float)(TreeColumnWidth - 1) * y) + 0.5;
  LODWORD(y) = (int)v10;
  if ( v9 )
  {
    b = this->m_CurrentColor.b;
    m_Channel = this->m_Channel;
    LOWORD(x) = *(_WORD *)&this->m_CurrentColor.r;
    v16 = CColorXYPreview::s_pRGBRemapX[m_Channel];
    BYTE2(x) = b;
    *((_BYTE *)&x + v16) = v7;
    v17 = CElementTreeViewListControl::GetTreeColumnWidth(this);
    *((_BYTE *)&x + CColorXYPreview::s_pRGBRemapY[this->m_Channel]) = -1 - LOBYTE(y) + v17;
    v18 = LOBYTE(x);
    LOWORD(y) = LOWORD(x);
    BYTE2(y) = BYTE2(x);
    HIBYTE(y) = -1;
    v19 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v19 != nullptr )
      v20 = KeyValues::KeyValues(this: v19, setName: "ColorSelected");
    else
      v20 = nullptr;
    KeyValues::SetColor(this: v20, keyName: "color", value: LODWORD(y));
    this->PostActionSignal(this, a2: v20);
    vecHSV.x = (float)v18 * 0.0039215689;
    vecHSV.y = (float)BYTE1(x) * 0.0039215689;
    vecHSV.z = (float)BYTE2(x) * 0.0039215689;
    RGBtoHSV(rgb: &vecHSV, hsv: &rgb);
    p_rgb = &rgb;
  }
  else
  {
    CColorXYPreview::ComputeHSVColorForPoint(this, x: v7, y: (int)v10, vscHSV: &vecHSV);
    v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v11 != nullptr )
      v12 = KeyValues::KeyValues(this: v11, setName: "HSVSelected");
    else
      v12 = nullptr;
    KeyValues::SetFloat(this: v12, keyName: "hue", value: vecHSV.x);
    KeyValues::SetFloat(this: v12, keyName: "saturation", value: vecHSV.y);
    KeyValues::SetFloat(this: v12, keyName: "value", value: vecHSV.z);
    this->PostActionSignal(this, a2: v12);
    HSVtoRGB(hsv: &vecHSV, &rgb);
    VectorToRGB888(inVector: &rgb, outColor: (RGB888_t *)&x);
    p_rgb = &vecHSV;
  }
  CColorZPreview::SetColor((CColorZPreview *)this, color: (const RGB888_t *)&x, hsvColor: p_rgb);
}

//------------------------------------------------------------------------------
// Address: 0x004D7640
// Name: public: virtual void CColorXYPreview::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorXYPreview::OnMousePressed(CColorXYPreview *this, const char *code)
{
  const char *v2; // edi
  unsigned int (__thiscall *GetVPanel)(vgui::IClientPanel *); // edx
  vgui::IInput *v5; // edi
  vgui::IInput_vtbl *v6; // ebx
  int v7; // eax
  int x; // [esp+8h] [ebp-4h] BYREF

  v2 = code;
  vgui::Panel::OnMousePressed(this, panelName: code);
  if ( v2 == (const char *)107 && !this->m_bDraggingMouse )
  {
    GetVPanel = this->GetVPanel;
    this->m_bDraggingMouse = true;
    v5 = g_pVGuiInput;
    v6 = g_pVGuiInput->__vftable;
    v7 = GetVPanel(this);
    v6->SetMouseCapture(this: v5, a2: v7);
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: (int *)&code);
    vgui::Panel::ScreenToLocal(this, &x, y: (int *)&code);
    CColorXYPreview::UpdateColorFromMouse(this, x: *(float *)&x, y: *(float *)&code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D76C0
// Name: public: virtual void CColorXYPreview::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorXYPreview::OnCursorMoved(CColorXYPreview *this, int x, KeyValues *y)
{
  BlankImage::SetSize((vgui::TreeView *)this, itemIndex: x, msg: y);
  if ( this->m_bDraggingMouse )
    CColorXYPreview::UpdateColorFromMouse(this, x: *(float *)&x, y: *(float *)&y);
}

//------------------------------------------------------------------------------
// Address: 0x004D76F0
// Name: public: CColorZPreview::CColorZPreview(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CColorZPreview *__thiscall CColorZPreview::CColorZPreview(
        CColorZPreview *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  __int16 v7; // dx
  int b; // eax
  Vector vecRGB; // [esp+Ch] [ebp-Ch] BYREF

  CProceduralTexturePanel::CProceduralTexturePanel(this, pParent, pName);
  this->CProceduralTexturePanel::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CColorZPreview_vtbl *)&CColorZPreview::`vftable'{for `vgui::EditablePanel'};
  this->CProceduralTexturePanel::ITextureRegenerator::__vftable = (ITextureRegenerator_vtbl *)&CColorZPreview::`vftable'{for `ITextureRegenerator'};
  if ( `CColorZPreview::ChainToMap'::`2'::chained == 0 )
  {
    `CColorZPreview::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CColorZPreview");
    v4->pfnClassName = CColorZPreview::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CProceduralTexturePanel");
  }
  if ( `CColorZPreview::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CColorZPreview::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CColorZPreview");
    v5->pfnClassName = CColorZPreview::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CProceduralTexturePanel");
  }
  if ( `CColorZPreview::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CColorZPreview::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CColorZPreview");
    v6->pfnClassName = CColorZPreview::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CProceduralTexturePanel");
  }
  CProceduralTexturePanel::Init(this, nWidth: 8, nHeight: 256, bAllocateImageBuffer: false);
  *(_WORD *)&this->m_CurrentColor.g = -1;
  this->m_CurrentColor.r = -1;
  v7 = *(_WORD *)&this->m_CurrentColor.r;
  b = this->m_CurrentColor.b;
  vecRGB.x = (float)(unsigned __int8)v7 * 0.0039215689;
  vecRGB.y = (float)HIBYTE(v7) * 0.0039215689;
  vecRGB.z = (float)b * 0.0039215689;
  RGBtoHSV(rgb: &vecRGB, hsv: &this->m_CurrentHSVColor);
  this->m_bDraggingMouse = false;
  vgui::Panel::SetMouseInputEnabled(this, state: true);
  if ( this->m_Type != COLOR_TYPE_HSV || this->m_Channel != CHANNEL_RED )
  {
    this->m_Type = COLOR_TYPE_HSV;
    this->m_Channel = CHANNEL_RED;
    CProceduralTexturePanel::DownloadTexture(this);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004D7880
// Name: public: virtual struct vgui::PanelMessageMap __near * CColorZPreview::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CColorZPreview::GetMessageMap(CColorZPreview *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CColorZPreview::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorZPreview::GetMessageMap'::`2'::s_pMap;
  `CColorZPreview::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CColorZPreview");
  `CColorZPreview::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D78B0
// Name: public: virtual struct PanelAnimationMap __near * CColorZPreview::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CColorZPreview::GetAnimMap(CColorZPreview *this)
{
  return FindOrAddPanelAnimationMap(className: "CColorZPreview");
}

//------------------------------------------------------------------------------
// Address: 0x004D78C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CColorZPreview::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CColorZPreview::GetKBMap(CColorZPreview *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CColorZPreview::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorZPreview::GetKBMap'::`2'::s_pMap;
  `CColorZPreview::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CColorZPreview");
  `CColorZPreview::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D7920
// Name: public: virtual void CColorZPreview::RegenerateTextureBits(class ITexture __near *,class IVTFTexture __near *,struct Rect_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorZPreview::RegenerateTextureBits(
        CColorZPreview *this,
        ITexture *pTexture,
        IVTFTexture *pVTFTexture,
        Rect_t *pRect)
{
  IVTFTexture *v4; // esi
  CColorZPreview *v5; // edi
  void (__thiscall *ComputeMipLevelDimensions)(IVTFTexture *, int, int *, int *, int *); // edx
  int v7; // eax
  int v8; // esi
  float v9; // xmm0_4
  float *p_actionSignalTargetDar; // esi
  int v11; // edi
  int TreeColumnWidth; // eax
  int v13; // eax
  int v14; // edx
  int v15; // ecx
  int v16; // ebx
  int v17; // eax
  __int16 m_nAllocationCount; // ax
  int v19; // esi
  int v20; // ecx
  unsigned __int8 v21; // al
  int v22; // edi
  unsigned int v23; // edx
  unsigned int v24; // edx
  int v25; // eax
  unsigned __int64 v26; // rdi
  __int64 v27; // rax
  __int64 v28; // rax
  int v29; // ebx
  unsigned __int64 v30; // rax
  int pixelWriter_4; // [esp+10h] [ebp-74h]
  unsigned __int8 pixelWriter_10; // [esp+16h] [ebp-6Eh]
  int pixelWriter_12; // [esp+18h] [ebp-6Ch]
  int pixelWriter_16; // [esp+1Ch] [ebp-68h]
  int pixelWriter_20; // [esp+20h] [ebp-64h]
  int pixelWriter_24; // [esp+24h] [ebp-60h]
  int pixelWriter_28; // [esp+28h] [ebp-5Ch]
  unsigned __int8 pixelWriter_32; // [esp+2Ch] [ebp-58h]
  Vector rgb; // [esp+30h] [ebp-54h] BYREF
  Vector vecHSV; // [esp+3Ch] [ebp-48h] BYREF
  int v41; // [esp+4Ch] [ebp-38h]
  int nDepth; // [esp+50h] [ebp-34h] BYREF
  int v43; // [esp+54h] [ebp-30h]
  int v44; // [esp+58h] [ebp-2Ch]
  int v45; // [esp+5Ch] [ebp-28h]
  CColorZPreview *v46; // [esp+60h] [ebp-24h]
  int nHeight; // [esp+64h] [ebp-20h] BYREF
  int nWidth; // [esp+68h] [ebp-1Ch] BYREF
  int x; // [esp+6Ch] [ebp-18h]
  int v50; // [esp+70h] [ebp-14h]
  int v51; // [esp+74h] [ebp-10h]
  int v52; // [esp+78h] [ebp-Ch]
  int y; // [esp+7Ch] [ebp-8h]
  int v54; // [esp+80h] [ebp-4h]

  v4 = pVTFTexture;
  v5 = this;
  ComputeMipLevelDimensions = pVTFTexture->ComputeMipLevelDimensions;
  v46 = this;
  ComputeMipLevelDimensions(this: pVTFTexture, a2: 0, a3: &nWidth, a4: &nHeight, a5: &nDepth);
  pVTFTexture = (IVTFTexture *)v4->RowSizeInBytes(this: v4, a2: 0);
  x = (int)v4->ImageData_2(this: v4, a2: 0, a3: 0, a4: 0);
  v7 = v4->Format(this: v4);
  v8 = v7;
  switch ( v7 )
  {
    case 0:
    case 23:
      pixelWriter_12 = 0x80000;
      pixelWriter_16 = 1572880;
      goto LABEL_6;
    case 3:
      pixelWriter_10 = 3;
      pixelWriter_12 = 524304;
      pixelWriter_16 = 0;
      pixelWriter_20 = 255;
      pixelWriter_24 = 255;
      pixelWriter_28 = 255;
      goto LABEL_20;
    case 5:
      pixelWriter_10 = 1;
      pixelWriter_12 = 0;
      pixelWriter_16 = 0;
      goto LABEL_18;
    case 8:
      pixelWriter_10 = 1;
      pixelWriter_12 = 0;
      pixelWriter_16 = 0;
      pixelWriter_20 = 0;
      pixelWriter_24 = 0;
      pixelWriter_28 = 0;
      pixelWriter_32 = -1;
      goto LABEL_21;
    case 12:
      pixelWriter_12 = 524304;
      pixelWriter_16 = 1572864;
LABEL_6:
      pixelWriter_10 = 4;
      pixelWriter_20 = 255;
      pixelWriter_24 = 255;
      pixelWriter_28 = 255;
      pixelWriter_32 = -1;
      goto LABEL_21;
    case 16:
      pixelWriter_10 = 4;
      pixelWriter_12 = 524304;
      pixelWriter_16 = 1572864;
      pixelWriter_20 = 255;
      pixelWriter_24 = 255;
      pixelWriter_28 = 255;
      goto LABEL_20;
    case 17:
      pixelWriter_10 = 2;
      pixelWriter_12 = 196616;
      pixelWriter_16 = 65533;
      pixelWriter_20 = 248;
      pixelWriter_24 = 252;
      pixelWriter_28 = 248;
      goto LABEL_20;
    case 18:
    case 21:
      pixelWriter_10 = 2;
      pixelWriter_12 = 131079;
      pixelWriter_16 = 589821;
      pixelWriter_20 = 248;
      pixelWriter_24 = 248;
      pixelWriter_28 = 248;
      pixelWriter_32 = 0x80;
      goto LABEL_21;
    case 19:
      pixelWriter_10 = 2;
      pixelWriter_12 = 4;
      pixelWriter_16 = 589820;
      pixelWriter_20 = 240;
      pixelWriter_24 = 240;
      pixelWriter_28 = 240;
      pixelWriter_32 = -16;
      goto LABEL_21;
    case 24:
    case 25:
      pixelWriter_10 = 8;
      pixelWriter_12 = 0x100000;
      pixelWriter_16 = 3145760;
      pixelWriter_20 = 0xFFFF;
      pixelWriter_24 = 0xFFFF;
      pixelWriter_28 = 0xFFFF;
      pixelWriter_32 = -1;
      goto LABEL_21;
    case 27:
      pixelWriter_10 = 4;
      pixelWriter_12 = 0;
      pixelWriter_16 = 0;
      pixelWriter_20 = -1;
      goto LABEL_19;
    case 29:
      pixelWriter_10 = 16;
      pixelWriter_12 = 0x200000;
      pixelWriter_16 = (int)&loc_60003D + 3;
      pixelWriter_20 = -1;
      pixelWriter_24 = -1;
      pixelWriter_28 = -1;
      pixelWriter_32 = -1;
      goto LABEL_21;
    default:
      if ( `CPixelWriter::SetPixelMemory'::`10'::format_error_printed[v7] == 0 )
      {
        _Msg(a1: "CPixelWriter::SetPixelMemory:  Unsupported image format %i\n", v7);
        `CPixelWriter::SetPixelMemory'::`10'::format_error_printed[v8] = 1;
      }
      pixelWriter_10 = 0;
      pixelWriter_12 = 0;
      pixelWriter_16 = 0;
LABEL_18:
      pixelWriter_20 = 255;
LABEL_19:
      pixelWriter_24 = 0;
      pixelWriter_28 = 0;
LABEL_20:
      pixelWriter_32 = 0;
LABEL_21:
      y = 0;
      if ( nHeight > 0 )
      {
        v43 = (unsigned __int16)pVTFTexture;
        v51 = -1;
        v52 = x;
        while ( 1 )
        {
          pixelWriter_4 = v52;
          if ( v5->_vpanel != 0 )
          {
            v9 = *(float *)&v5->_panelName.m_Storage.m_Memory.m_nGrowSize;
            p_actionSignalTargetDar = (float *)&v5[-1]._actionSignalTargetDar;
            v11 = *((_DWORD *)&v5[-1]._actionSignalTargetDar + 114);
            vecHSV.x = v9;
            vecHSV.y = p_actionSignalTargetDar[117];
            vecHSV.z = p_actionSignalTargetDar[118];
            TreeColumnWidth = CElementTreeViewListControl::GetTreeColumnWidth(this: (CProceduralTexturePanel *)p_actionSignalTargetDar);
            *(&vecHSV.x + v11) = (float)(v51 + TreeColumnWidth) * 0.0039215689;
            if ( *((_DWORD *)p_actionSignalTargetDar + 114) == 0 )
            {
              if ( vecHSV.x != -1.0 )
                vecHSV.x = vecHSV.x * 360.0;
              vecHSV.y = 1.0;
              vecHSV.z = 1.0;
            }
            HSVtoRGB(hsv: &vecHSV, &rgb);
            v13 = (int)(float)((float)(rgb.x * 255.0) + 0.5);
            v14 = (int)(float)((float)(rgb.y * 255.0) + 0.5);
            v15 = (int)(float)((float)(rgb.z * 255.0) + 0.5);
            if ( v13 >= 0 )
            {
              if ( v13 > 255 )
                LOBYTE(v13) = -1;
            }
            else
            {
              LOBYTE(v13) = 0;
            }
            LOBYTE(v16) = v13;
            if ( v14 >= 0 )
            {
              LOBYTE(v17) = -1;
              if ( v14 <= 255 )
                v17 = (int)(float)((float)(rgb.y * 255.0) + 0.5);
            }
            else
            {
              LOBYTE(v17) = 0;
            }
            if ( v15 >= 0 )
            {
              if ( v15 > 255 )
                LOBYTE(v15) = -1;
            }
            else
            {
              LOBYTE(v15) = 0;
            }
          }
          else
          {
            m_nAllocationCount = v5->_panelName.m_Storage.m_Memory.m_nAllocationCount;
            BYTE2(pVTFTexture) = BYTE2(v5->_panelName.m_Storage.m_Memory.m_nAllocationCount);
            LOWORD(pVTFTexture) = m_nAllocationCount;
            LOBYTE(v17) = CElementTreeViewListControl::GetTreeColumnWidth(this: (CColorZPreview *)((char *)v5 - 380));
            *((_BYTE *)&pVTFTexture + (unsigned int)v5->_panelName.m_Storage.m_Memory.m_pMemory) = -1 - y + v17;
            LOBYTE(v15) = BYTE2(pVTFTexture);
            LOBYTE(v17) = BYTE1(pVTFTexture);
            LOBYTE(v16) = (_BYTE)pVTFTexture;
          }
          x = 0;
          if ( nWidth > 0 )
          {
            v19 = (unsigned __int8)v15;
            v20 = (unsigned __int8)v17;
            v21 = pixelWriter_10;
            v16 = (unsigned __int8)v16;
            v22 = pixelWriter_10;
            v54 = v19;
            v45 = v20;
            v44 = (unsigned __int8)v16;
            v50 = pixelWriter_10;
            while ( 1 )
            {
              if ( v21 != 0 )
              {
                if ( v21 >= 5u )
                {
                  v26 = ((unsigned __int64)(v16 & (unsigned int)pixelWriter_20) << pixelWriter_12)
                      | ((unsigned __int64)(v20 & (unsigned int)pixelWriter_24) << SBYTE2(pixelWriter_12));
                  v27 = v54 & (unsigned int)pixelWriter_28;
                  if ( (__int16)pixelWriter_16 <= 0 )
                    v28 = v27 >> -(char)pixelWriter_16;
                  else
                    v28 = v27 << pixelWriter_16;
                  v41 = HIDWORD(v28);
                  v29 = v28;
                  v30 = (unsigned __int64)pixelWriter_32 << SBYTE2(pixelWriter_16);
                  LODWORD(v26) = v29 | v30 | v26;
                  HIDWORD(v26) |= v41 | HIDWORD(v30);
                  if ( v50 == 6 )
                  {
                    *(_DWORD *)pixelWriter_4 = v26;
                    *(_WORD *)(pixelWriter_4 + 4) = WORD2(v26);
                  }
                  else if ( v50 == 8 )
                  {
                    *(_QWORD *)pixelWriter_4 = v26;
                  }
                }
                else
                {
                  v23 = v19 & pixelWriter_28;
                  if ( (__int16)pixelWriter_16 <= 0 )
                    v24 = v23 >> -(char)pixelWriter_16;
                  else
                    v24 = v23 << pixelWriter_16;
                  v25 = v24
                      | (pixelWriter_32 << SBYTE2(pixelWriter_16))
                      | ((v16 & pixelWriter_20) << pixelWriter_12)
                      | ((v20 & pixelWriter_24) << SBYTE2(pixelWriter_12));
                  switch ( v22 )
                  {
                    case 1:
                      *(_BYTE *)pixelWriter_4 = v25;
                      break;
                    case 2:
                      *(_WORD *)pixelWriter_4 = v25;
                      break;
                    case 3:
                      *(_WORD *)pixelWriter_4 = v25;
                      *(_BYTE *)(pixelWriter_4 + 2) = BYTE2(v25);
                      break;
                    case 4:
                      *(_DWORD *)pixelWriter_4 = v25;
                      break;
                    default:
                      break;
                  }
                }
              }
              v22 = v50;
              pixelWriter_4 += v50;
              if ( ++x >= nWidth )
                break;
              v20 = v45;
              v16 = v44;
              v19 = v54;
              v21 = pixelWriter_10;
            }
          }
          v52 += v43;
          --v51;
          if ( ++y >= nHeight )
            break;
          v5 = v46;
        }
      }
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D7EE0
// Name: private: void CColorZPreview::UpdateColorFromMouse(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorZPreview::UpdateColorFromMouse(CColorZPreview *this, int x, float y)
{
  float v4; // xmm0_4
  int TreeColumnWidth; // eax
  int v6; // ebx
  ColorChannel_t m_Channel; // esi
  int v8; // eax
  bool v9; // zf
  KeyValues *v10; // eax
  KeyValues *v11; // esi
  Vector *p_vecHSV; // edx
  unsigned __int8 b; // dl
  unsigned __int8 v14; // bl
  KeyValues *v15; // eax
  KeyValues *v16; // esi
  Vector rgb; // [esp+10h] [ebp-24h] BYREF
  Vector vecHSV; // [esp+1Ch] [ebp-18h] BYREF
  int w; // [esp+28h] [ebp-Ch] BYREF
  int h; // [esp+2Ch] [ebp-8h] BYREF
  Color c; // [esp+30h] [ebp-4h]

  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  h -= 12;
  v4 = (float)(LODWORD(y) - 6) / (float)(h - 1);
  if ( v4 >= 0.0 )
  {
    if ( v4 <= 1.0 )
      y = (float)(LODWORD(y) - 6) / (float)(h - 1);
    else
      y = 1.0;
  }
  else
  {
    y = 0.0;
  }
  TreeColumnWidth = CElementTreeViewListControl::GetTreeColumnWidth(this);
  v6 = (int)(float)((float)((float)(TreeColumnWidth - 1) * y) + 0.5);
  if ( this->m_Type != COLOR_TYPE_RGB )
  {
    m_Channel = this->m_Channel;
    vecHSV = this->m_CurrentHSVColor;
    v8 = CElementTreeViewListControl::GetTreeColumnWidth(this);
    v9 = this->m_Channel == CHANNEL_RED;
    *(&vecHSV.x + m_Channel) = (float)(v8 - v6 - 1) * 0.0039215689;
    if ( v9 && vecHSV.x != -1.0 )
      vecHSV.x = vecHSV.x * 360.0;
    v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v10 != nullptr )
      v11 = KeyValues::KeyValues(this: v10, setName: "HSVSelected");
    else
      v11 = nullptr;
    KeyValues::SetFloat(this: v11, keyName: "hue", value: vecHSV.x);
    KeyValues::SetFloat(this: v11, keyName: "saturation", value: vecHSV.y);
    KeyValues::SetFloat(this: v11, keyName: "value", value: vecHSV.z);
    this->PostActionSignal(this, a2: v11);
    HSVtoRGB(hsv: &vecHSV, &rgb);
    VectorToRGB888(inVector: &rgb, outColor: (RGB888_t *)&y);
    p_vecHSV = &vecHSV;
  }
  else
  {
    b = this->m_CurrentColor.b;
    LOWORD(y) = *(_WORD *)&this->m_CurrentColor.r;
    BYTE2(y) = b;
    *((_BYTE *)&y + this->m_Channel) = -1 - v6 + CElementTreeViewListControl::GetTreeColumnWidth(this);
    v14 = LOBYTE(y);
    *(_WORD *)c._color = LOWORD(y);
    c._color[2] = BYTE2(y);
    c._color[3] = -1;
    v15 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v15 != nullptr )
      v16 = KeyValues::KeyValues(this: v15, setName: "ColorSelected");
    else
      v16 = nullptr;
    KeyValues::SetColor(this: v16, keyName: "color", value: c);
    this->PostActionSignal(this, a2: v16);
    vecHSV.x = (float)v14 * 0.0039215689;
    vecHSV.y = (float)BYTE1(y) * 0.0039215689;
    vecHSV.z = (float)BYTE2(y) * 0.0039215689;
    RGBtoHSV(rgb: &vecHSV, hsv: &rgb);
    p_vecHSV = &rgb;
  }
  CColorZPreview::SetColor(this, color: (const RGB888_t *)&y, hsvColor: p_vecHSV);
}

//------------------------------------------------------------------------------
// Address: 0x004D8170
// Name: public: virtual void CColorZPreview::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorZPreview::OnMousePressed(CColorZPreview *this, const char *code)
{
  const char *v2; // edi
  unsigned int (__thiscall *GetVPanel)(vgui::IClientPanel *); // edx
  vgui::IInput *v5; // edi
  vgui::IInput_vtbl *v6; // ebx
  int v7; // eax
  int x; // [esp+8h] [ebp-4h] BYREF

  v2 = code;
  vgui::Panel::OnMousePressed(this, panelName: code);
  if ( v2 == (const char *)107 && !this->m_bDraggingMouse )
  {
    GetVPanel = this->GetVPanel;
    this->m_bDraggingMouse = true;
    v5 = g_pVGuiInput;
    v6 = g_pVGuiInput->__vftable;
    v7 = GetVPanel(this);
    v6->SetMouseCapture(this: v5, a2: v7);
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: (int *)&code);
    vgui::Panel::ScreenToLocal(this, &x, y: (int *)&code);
    CColorZPreview::UpdateColorFromMouse(this, x, y: *(float *)&code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D81F0
// Name: public: virtual void CColorZPreview::OnCursorMoved(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorZPreview::OnCursorMoved(CColorZPreview *this, int x, KeyValues *y)
{
  BlankImage::SetSize((vgui::TreeView *)this, itemIndex: x, msg: y);
  if ( this->m_bDraggingMouse )
    CColorZPreview::UpdateColorFromMouse(this, x, y: *(float *)&y);
}

//------------------------------------------------------------------------------
// Address: 0x004D8220
// Name: public: void CColorPickerPanel::SetInitialColor(class Color)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerPanel::SetInitialColor(CColorPickerPanel *this, Color initialColor)
{
  __int16 v3; // dx
  Vector *p_m_CurrentHSVColor; // edi
  Vector rgb; // [esp+0h] [ebp-10h] BYREF
  __int16 v6; // [esp+Ch] [ebp-4h]

  this->m_InitialColor.r = initialColor._color[0];
  this->m_InitialColor.g = initialColor._color[1];
  this->m_InitialColor.b = initialColor._color[2];
  this->m_CurrentAlpha = initialColor._color[3];
  this->m_InitialAlpha = initialColor._color[3];
  v3 = *(_WORD *)&this->m_InitialColor.r;
  *(_WORD *)&this->m_CurrentColor.r = v3;
  this->m_CurrentColor.b = initialColor._color[2];
  rgb.x = (float)(unsigned __int8)v3 * 0.0039215689;
  v6 = v3;
  rgb.y = (float)HIBYTE(v3) * 0.0039215689;
  p_m_CurrentHSVColor = &this->m_CurrentHSVColor;
  rgb.z = (float)initialColor._color[2] * 0.0039215689;
  RGBtoHSV(&rgb, hsv: &this->m_CurrentHSVColor);
  if ( p_m_CurrentHSVColor->x == -1.0 )
    p_m_CurrentHSVColor->x = 0.0;
  CColorPickerPanel::OnColorChanged(this, pChanged: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004D8300
// Name: public: virtual void CColorPickerPanel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerPanel::OnMousePressed(CColorPickerPanel *this, const char *code)
{
  const char *v2; // edi
  unsigned __int8 b; // dl
  unsigned __int8 m_InitialAlpha; // cl
  int tall; // [esp+8h] [ebp-14h] BYREF
  int cy; // [esp+Ch] [ebp-10h] BYREF
  int cw; // [esp+10h] [ebp-Ch] BYREF
  int v9; // [esp+14h] [ebp-8h] BYREF
  int y; // [esp+18h] [ebp-4h] BYREF

  v2 = code;
  vgui::Panel::OnMousePressed(this, panelName: code);
  if ( v2 == (const char *)107 )
  {
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: (int *)&code, a3: &y);
    vgui::Panel::ScreenToLocal(this, x: (int *)&code, &y);
    vgui::Panel::GetBounds(this: this->m_pInitialColor, x: &v9, y: &cy, wide: &cw, &tall);
    if ( v9 <= (int)code && cw + v9 > (int)code && cy <= y && tall + cy > y )
    {
      b = this->m_InitialColor.b;
      *(_WORD *)&this->m_CurrentColor.r = *(_WORD *)&this->m_InitialColor.r;
      m_InitialAlpha = this->m_InitialAlpha;
      this->m_CurrentColor.b = b;
      this->m_CurrentAlpha = m_InitialAlpha;
      RGBtoHSV(rgb: &this->m_CurrentColor, hsv: &this->m_CurrentHSVColor);
      if ( this->m_CurrentHSVColor.x == -1.0 )
        this->m_CurrentHSVColor.x = 0.0;
      CColorPickerPanel::OnColorChanged(this, pChanged: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004D83E0
// Name: private: virtual void CColorPickerPanel::OnHSVSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerPanel::OnHSVSelected(CColorPickerPanel *this, KeyValues *data)
{
  Vector rgb; // [esp+10h] [ebp-Ch] BYREF

  this->m_CurrentHSVColor.x = KeyValues::GetFloat(this: data, keyName: "hue", defaultValue: 0.0);
  this->m_CurrentHSVColor.y = KeyValues::GetFloat(this: data, keyName: "saturation", defaultValue: 0.0);
  this->m_CurrentHSVColor.z = KeyValues::GetFloat(this: data, keyName: "value", defaultValue: 0.0);
  HSVtoRGB(hsv: &this->m_CurrentHSVColor, &rgb);
  VectorToRGB888(inVector: &rgb, outColor: &this->m_CurrentColor);
  CColorPickerPanel::OnColorChanged(this, pChanged: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004D8470
// Name: private: virtual void CColorPickerPanel::OnColorSelected(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerPanel::OnColorSelected(CColorPickerPanel *this, KeyValues *data)
{
  unsigned __int8 v3; // ah
  unsigned __int8 v4; // dl
  Vector rgb; // [esp+8h] [ebp-14h] BYREF
  Color c; // [esp+14h] [ebp-8h] BYREF
  Color defaultColor; // [esp+18h] [ebp-4h] BYREF
  __int16 dataa; // [esp+24h] [ebp+8h]

  defaultColor = 0;
  KeyValues::GetColor(this: data, result: &c, keyName: "color", &defaultColor);
  v3 = c._color[1];
  v4 = c._color[2];
  this->m_CurrentColor.r = c._color[0];
  this->m_CurrentColor.b = v4;
  this->m_CurrentColor.g = v3;
  dataa = *(_WORD *)&this->m_CurrentColor.r;
  rgb.x = (float)(unsigned __int8)dataa * 0.0039215689;
  rgb.y = (float)HIBYTE(dataa) * 0.0039215689;
  rgb.z = (float)v4 * 0.0039215689;
  RGBtoHSV(&rgb, hsv: &this->m_CurrentHSVColor);
  CColorPickerPanel::OnColorChanged(this, pChanged: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004D8520
// Name: private: virtual void CColorPickerPanel::OnTextChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerPanel::OnTextChanged(CColorPickerPanel *this, KeyValues *data)
{
  vgui::TextEntry *Ptr; // eax
  vgui::TextEntry *m_pRedText; // ecx
  vgui::TextEntry *v5; // esi
  Vector *p_m_CurrentHSVColor; // ebx
  int v7; // eax
  __int16 v8; // dx
  int b; // eax
  vgui::TextEntry *m_pGreenText; // ecx
  int v11; // eax
  __int16 v12; // cx
  int v13; // edx
  vgui::TextEntry *m_pBlueText; // ecx
  int v15; // eax
  vgui::TextEntry *m_pAlphaText; // ecx
  int v17; // eax
  vgui::TextEntry *m_pHueText; // ecx
  int v19; // eax
  vgui::TextEntry *m_pSaturationText; // ecx
  int v21; // eax
  vgui::TextEntry *m_pValueText; // ecx
  int v23; // eax
  char buf[256]; // [esp+Ch] [ebp-110h] BYREF
  float flHue; // [esp+10Ch] [ebp-10h]
  Vector rgb; // [esp+110h] [ebp-Ch] BYREF
  vgui::Panel *pPanel; // [esp+124h] [ebp+8h]

  Ptr = (vgui::TextEntry *)KeyValues::GetPtr(this: data, keyName: "panel", defaultValue: nullptr);
  m_pRedText = this->m_pRedText;
  v5 = Ptr;
  p_m_CurrentHSVColor = &this->m_CurrentHSVColor;
  pPanel = Ptr;
  flHue = this->m_CurrentHSVColor.x;
  if ( Ptr == m_pRedText )
  {
    m_pRedText->GetText_2(this: m_pRedText, a2: buf, a3: 256);
    v7 = atoi(nptr: buf);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    this->m_CurrentColor.r = v7;
    v8 = *(_WORD *)&this->m_CurrentColor.r;
    b = this->m_CurrentColor.b;
    rgb.x = (float)(unsigned __int8)v8 * 0.0039215689;
    rgb.y = (float)HIBYTE(v8) * 0.0039215689;
    rgb.z = (float)b * 0.0039215689;
    RGBtoHSV(&rgb, hsv: &this->m_CurrentHSVColor);
  }
  else
  {
    m_pGreenText = this->m_pGreenText;
    if ( Ptr == m_pGreenText )
    {
      m_pGreenText->GetText_2(this: m_pGreenText, a2: buf, a3: 256);
      v11 = atoi(nptr: buf);
      if ( v11 >= 0 )
      {
        if ( v11 > 255 )
          LOBYTE(v11) = -1;
      }
      else
      {
        LOBYTE(v11) = 0;
      }
      this->m_CurrentColor.g = v11;
      v12 = *(_WORD *)&this->m_CurrentColor.r;
      v13 = this->m_CurrentColor.b;
      rgb.x = (float)(unsigned __int8)v12 * 0.0039215689;
      rgb.y = (float)HIBYTE(v12) * 0.0039215689;
      rgb.z = (float)v13 * 0.0039215689;
      RGBtoHSV(&rgb, hsv: &this->m_CurrentHSVColor);
    }
    else
    {
      m_pBlueText = this->m_pBlueText;
      if ( Ptr == m_pBlueText )
      {
        m_pBlueText->GetText_2(this: m_pBlueText, a2: buf, a3: 256);
        v15 = atoi(nptr: buf);
        if ( v15 >= 0 )
        {
          if ( v15 > 255 )
            LOBYTE(v15) = -1;
        }
        else
        {
          LOBYTE(v15) = 0;
        }
        this->m_CurrentColor.b = v15;
        RGBtoHSV(rgb: &this->m_CurrentColor, hsv: &this->m_CurrentHSVColor);
      }
      else
      {
        m_pAlphaText = this->m_pAlphaText;
        if ( Ptr == m_pAlphaText )
        {
          m_pAlphaText->GetText_2(this: m_pAlphaText, a2: buf, a3: 256);
          v17 = atoi(nptr: buf);
          if ( v17 >= 0 )
          {
            if ( v17 > 255 )
              LOBYTE(v17) = -1;
            this->m_CurrentAlpha = v17;
          }
          else
          {
            this->m_CurrentAlpha = 0;
          }
        }
        else
        {
          m_pHueText = this->m_pHueText;
          if ( Ptr == m_pHueText )
          {
            m_pHueText->GetText_2(this: m_pHueText, a2: buf, a3: 256);
            v19 = atoi(nptr: buf);
            if ( v19 >= 0 )
            {
              if ( v19 > 360 )
                v19 = 360;
              p_m_CurrentHSVColor->x = (float)v19;
            }
            else
            {
              p_m_CurrentHSVColor->x = (float)0;
            }
          }
          else
          {
            m_pSaturationText = this->m_pSaturationText;
            if ( Ptr == m_pSaturationText )
            {
              m_pSaturationText->GetText_2(this: m_pSaturationText, a2: buf, a3: 256);
              v21 = atoi(nptr: buf);
              if ( v21 >= 0 )
              {
                if ( v21 > 100 )
                  v21 = 100;
              }
              else
              {
                v21 = 0;
              }
              this->m_CurrentHSVColor.y = (float)v21 * 0.0099999998;
            }
            else
            {
              m_pValueText = this->m_pValueText;
              if ( Ptr != m_pValueText )
                goto LABEL_44;
              m_pValueText->GetText_2(this: m_pValueText, a2: buf, a3: 256);
              v23 = atoi(nptr: buf);
              if ( v23 >= 0 )
              {
                if ( v23 > 100 )
                  v23 = 100;
              }
              else
              {
                v23 = 0;
              }
              this->m_CurrentHSVColor.z = (float)v23 * 0.0099999998;
            }
          }
          HSVtoRGB(hsv: &this->m_CurrentHSVColor, rgb: &this->m_CurrentColor);
          v5 = (vgui::TextEntry *)pPanel;
        }
      }
    }
  }
LABEL_44:
  if ( p_m_CurrentHSVColor->x == -1.0 )
    p_m_CurrentHSVColor->x = flHue;
  CColorPickerPanel::OnColorChanged(this, pChanged: v5);
}

//------------------------------------------------------------------------------
// Address: 0x004D88C0
// Name: public: virtual struct vgui::PanelMessageMap __near * CColorPickerFrame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CColorPickerFrame::GetMessageMap(CColorPickerFrame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CColorPickerFrame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorPickerFrame::GetMessageMap'::`2'::s_pMap;
  `CColorPickerFrame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CColorPickerFrame");
  `CColorPickerFrame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D88F0
// Name: public: virtual struct PanelAnimationMap __near * CColorPickerFrame::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CColorPickerFrame::GetAnimMap(CColorPickerFrame *this)
{
  return FindOrAddPanelAnimationMap(className: "CColorPickerFrame");
}

//------------------------------------------------------------------------------
// Address: 0x004D8900
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CColorPickerFrame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CColorPickerFrame::GetKBMap(CColorPickerFrame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CColorPickerFrame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorPickerFrame::GetKBMap'::`2'::s_pMap;
  `CColorPickerFrame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CColorPickerFrame");
  `CColorPickerFrame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D8930
// Name: public: void CColorPickerFrame::DoModal(class Color,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorPickerFrame::DoModal(CColorPickerFrame *this, Color initialColor, KeyValues *pContextKeys)
{
  KeyValues *m_pContextKeys; // ecx

  m_pContextKeys = this->m_pContextKeys;
  if ( m_pContextKeys != nullptr )
  {
    KeyValues::deleteThis(this: m_pContextKeys);
    this->m_pContextKeys = nullptr;
  }
  CColorPickerPanel::SetInitialColor(this: this->m_pPicker, initialColor);
  this->m_pContextKeys = pContextKeys;
  vgui::Frame::DoModal(this);
}

//------------------------------------------------------------------------------
// Address: 0x004D89D0
// Name: public: static void CColorPickerPanel::PanelMessageFunc_OnRadioButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CColorPickerPanel::PanelMessageFunc_OnRadioButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`CColorPickerPanel::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded )
  {
    `CColorPickerPanel::PanelMessageFunc_OnRadioButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CColorPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "RadioButtonChecked";
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
// Address: 0x004D8A60
// Name: public: static void CColorPickerPanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CColorPickerPanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CColorPickerPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CColorPickerPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CColorPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "TextChanged";
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
// Address: 0x004D8AF0
// Name: public: static void CColorPickerPanel::PanelMessageFunc_OnHSVSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CColorPickerPanel::PanelMessageFunc_OnHSVSelected::InitVar(int a1@<ebp>)
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
  if ( !`CColorPickerPanel::PanelMessageFunc_OnHSVSelected::InitVar'::`2'::bAdded )
  {
    `CColorPickerPanel::PanelMessageFunc_OnHSVSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CColorPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "HSVSelected";
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
// Address: 0x004D8B80
// Name: public: static void CColorPickerPanel::PanelMessageFunc_OnColorSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CColorPickerPanel::PanelMessageFunc_OnColorSelected::InitVar(int a1@<ebp>)
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
  if ( !`CColorPickerPanel::PanelMessageFunc_OnColorSelected::InitVar'::`2'::bAdded )
  {
    `CColorPickerPanel::PanelMessageFunc_OnColorSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CColorPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "ColorSelected";
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
// Address: 0x004D8C10
// Name: public: CColorPickerPanel::CColorPickerPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CColorPickerPanel *__thiscall CColorPickerPanel::CColorPickerPanel(
        CColorPickerPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CColorXYPreview *v7; // eax
  CColorXYPreview *v8; // eax
  CColorZPreview *v9; // eax
  CColorZPreview *v10; // eax
  CColorXYPreview *m_pColorXYPreview; // ecx
  vgui::RadioButton *v12; // eax
  vgui::RadioButton *v13; // eax
  vgui::RadioButton *v14; // eax
  vgui::RadioButton *v15; // eax
  vgui::RadioButton *v16; // eax
  vgui::RadioButton *v17; // eax
  vgui::RadioButton *v18; // eax
  vgui::RadioButton *v19; // eax
  vgui::RadioButton *v20; // eax
  vgui::RadioButton *v21; // eax
  vgui::RadioButton *v22; // eax
  vgui::RadioButton *v23; // eax
  vgui::TextEntry *v24; // eax
  vgui::TextEntry *v25; // eax
  vgui::TextEntry *v26; // eax
  vgui::TextEntry *v27; // eax
  vgui::TextEntry *v28; // eax
  vgui::TextEntry *v29; // eax
  vgui::TextEntry *v30; // eax
  vgui::TextEntry *v31; // eax
  vgui::TextEntry *v32; // eax
  vgui::TextEntry *v33; // eax
  vgui::TextEntry *v34; // eax
  vgui::TextEntry *v35; // eax
  vgui::TextEntry *v36; // eax
  vgui::TextEntry *v37; // eax
  vgui::Panel *v38; // eax
  vgui::Panel *v39; // eax
  vgui::Panel *v40; // eax
  vgui::Panel *v41; // eax
  vgui::Panel *m_pInitialColor; // ecx
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->__vftable = (CColorPickerPanel_vtbl *)&CColorPickerPanel::`vftable';
  if ( `CColorPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CColorPickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CColorPickerPanel");
    v4->pfnClassName = CColorPickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CColorPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CColorPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CColorPickerPanel");
    v5->pfnClassName = CColorPickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CColorPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CColorPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CColorPickerPanel");
    v6->pfnClassName = CColorPickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CColorPickerPanel::PanelMessageFunc_OnRadioButtonChecked::InitVar(a1: (int)&savedregs);
  CColorPickerPanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  CColorPickerPanel::PanelMessageFunc_OnHSVSelected::InitVar(a1: (int)&savedregs);
  CColorPickerPanel::PanelMessageFunc_OnColorSelected::InitVar(a1: (int)&savedregs);
  v7 = (CColorXYPreview *)MemAlloc_Alloc(nSize: 0x1E4u);
  if ( v7 != nullptr )
    v8 = CColorXYPreview::CColorXYPreview(this: v7, pParent: this, pName: "ColorXYPreview");
  else
    v8 = nullptr;
  this->m_pColorXYPreview = v8;
  v9 = (CColorZPreview *)MemAlloc_Alloc(nSize: 0x1E0u);
  if ( v9 != nullptr )
    v10 = CColorZPreview::CColorZPreview(this: v9, pParent: this, pName: "ColorZPreview");
  else
    v10 = nullptr;
  m_pColorXYPreview = this->m_pColorXYPreview;
  this->m_pColorZPreview = v10;
  m_pColorXYPreview->AddActionSignalTarget_2(this: m_pColorXYPreview, a2: this);
  v12 = (vgui::RadioButton *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v12 != nullptr )
    v13 = vgui::RadioButton::RadioButton(this: v12, parent: this, panelName: "HueRadio", text: "H");
  else
    v13 = nullptr;
  this->m_pHueRadio = v13;
  v14 = (vgui::RadioButton *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v14 != nullptr )
    v15 = vgui::RadioButton::RadioButton(this: v14, parent: this, panelName: "SaturationRadio", text: "S");
  else
    v15 = nullptr;
  this->m_pSaturationRadio = v15;
  v16 = (vgui::RadioButton *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v16 != nullptr )
    v17 = vgui::RadioButton::RadioButton(this: v16, parent: this, panelName: "ValueRadio", text: "V");
  else
    v17 = nullptr;
  this->m_pValueRadio = v17;
  v18 = (vgui::RadioButton *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v18 != nullptr )
    v19 = vgui::RadioButton::RadioButton(this: v18, parent: this, panelName: "RedRadio", text: "R");
  else
    v19 = nullptr;
  this->m_pRedRadio = v19;
  v20 = (vgui::RadioButton *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v20 != nullptr )
    v21 = vgui::RadioButton::RadioButton(this: v20, parent: this, panelName: "GreenRadio", text: "G");
  else
    v21 = nullptr;
  this->m_pGreenRadio = v21;
  v22 = (vgui::RadioButton *)MemAlloc_Alloc(nSize: 0x210u);
  if ( v22 != nullptr )
    v23 = vgui::RadioButton::RadioButton(this: v22, parent: this, panelName: "BlueRadio", text: "B");
  else
    v23 = nullptr;
  this->m_pBlueRadio = v23;
  v24 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v24 != nullptr )
    v25 = vgui::TextEntry::TextEntry(this: v24, parent: this, panelName: "HueText");
  else
    v25 = nullptr;
  this->m_pHueText = v25;
  v26 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v26 != nullptr )
    v27 = vgui::TextEntry::TextEntry(this: v26, parent: this, panelName: "SaturationText");
  else
    v27 = nullptr;
  this->m_pSaturationText = v27;
  v28 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v28 != nullptr )
    v29 = vgui::TextEntry::TextEntry(this: v28, parent: this, panelName: "ValueText");
  else
    v29 = nullptr;
  this->m_pValueText = v29;
  v30 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v30 != nullptr )
    v31 = vgui::TextEntry::TextEntry(this: v30, parent: this, panelName: "RedText");
  else
    v31 = nullptr;
  this->m_pRedText = v31;
  v32 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v32 != nullptr )
    v33 = vgui::TextEntry::TextEntry(this: v32, parent: this, panelName: "GreenText");
  else
    v33 = nullptr;
  this->m_pGreenText = v33;
  v34 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v34 != nullptr )
    v35 = vgui::TextEntry::TextEntry(this: v34, parent: this, panelName: "BlueText");
  else
    v35 = nullptr;
  this->m_pBlueText = v35;
  v36 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v36 != nullptr )
    v37 = vgui::TextEntry::TextEntry(this: v36, parent: this, panelName: "AlphaText");
  else
    v37 = nullptr;
  this->m_pAlphaText = v37;
  v38 = (vgui::Panel *)MemAlloc_Alloc(nSize: 0x14Cu);
  if ( v38 != nullptr )
    v39 = vgui::Panel::Panel(this: v38, parent: this, panelName: "InitialColor");
  else
    v39 = nullptr;
  this->m_pInitialColor = v39;
  v40 = (vgui::Panel *)MemAlloc_Alloc(nSize: 0x14Cu);
  if ( v40 != nullptr )
    v41 = vgui::Panel::Panel(this: v40, parent: this, panelName: "CurrentColor");
  else
    v41 = nullptr;
  m_pInitialColor = this->m_pInitialColor;
  this->m_pCurrentColor = v41;
  m_pInitialColor->SetVisible(this: m_pInitialColor, a2: true);
  this->m_pCurrentColor->SetVisible(this: this->m_pCurrentColor, a2: true);
  this->m_pInitialColor->SetPaintBackgroundEnabled(this: this->m_pInitialColor, a2: true);
  this->m_pCurrentColor->SetPaintBackgroundEnabled(this: this->m_pCurrentColor, a2: true);
  this->m_pInitialColor->SetMouseInputEnabled(this: this->m_pInitialColor, a2: false);
  vgui::Panel::SetMouseInputEnabled(this, state: true);
  CColorPickerPanel::SetInitialColor(this, initialColor: (Color)-1);
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "resource/colorpicker.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004D9040
// Name: public: virtual struct vgui::PanelMessageMap __near * CColorPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CColorPickerPanel::GetMessageMap(CColorPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CColorPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CColorPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CColorPickerPanel");
  `CColorPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D9070
// Name: public: virtual struct PanelAnimationMap __near * CColorPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CColorPickerPanel::GetAnimMap(CColorPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CColorPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x004D9080
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CColorPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CColorPickerPanel::GetKBMap(CColorPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CColorPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CColorPickerPanel::GetKBMap'::`2'::s_pMap;
  `CColorPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CColorPickerPanel");
  `CColorPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004D90B0
// Name: public: CColorPickerFrame::CColorPickerFrame(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CColorPickerFrame *__thiscall CColorPickerFrame::CColorPickerFrame(
        CColorPickerFrame *this,
        vgui::Panel *pParent,
        const char *pTitle)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CColorPickerPanel *v7; // eax
  CColorPickerPanel *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  int w; // [esp+8h] [ebp-4h] BYREF

  vgui::Frame::Frame(this, parent: pParent, panelName: "ColorPickerFrame", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CColorPickerFrame_vtbl *)&CColorPickerFrame::`vftable';
  if ( `CColorPickerFrame::ChainToMap'::`2'::chained == 0 )
  {
    `CColorPickerFrame::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CColorPickerFrame");
    v4->pfnClassName = CColorPickerFrame::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CColorPickerFrame::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CColorPickerFrame::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CColorPickerFrame");
    v5->pfnClassName = CColorPickerFrame::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CColorPickerFrame::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CColorPickerFrame::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CColorPickerFrame");
    v6->pfnClassName = CColorPickerFrame::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  this->m_pContextKeys = nullptr;
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  v7 = (CColorPickerPanel *)MemAlloc_Alloc(nSize: 0x1DCu);
  if ( v7 != nullptr )
    v8 = CColorPickerPanel::CColorPickerPanel(this: v7, pParent: this, pName: "ColorPicker");
  else
    v8 = nullptr;
  this->m_pPicker = v8;
  v8->AddActionSignalTarget_2(this: v8, a2: this);
  v9 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "OkButton",
            text: "Ok",
            pActionSignalTarget: this,
            pCmd: "Ok");
  else
    v10 = nullptr;
  this->m_pOpenButton = v10;
  v11 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: this,
            panelName: "CancelButton",
            text: "#FileOpenDialog_Cancel",
            pActionSignalTarget: this,
            pCmd: "Cancel");
  else
    v12 = nullptr;
  this->m_pCancelButton = v12;
  vgui::Panel::SetBlockDragChaining(this, block: true);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "resource/colorpickerframe.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Panel::GetSize(this, wide: &w, tall: (int *)&pParent);
  vgui::Panel::SetMinimumSize(this, wide: w, tall: (int)pParent);
  vgui::Frame::SetTitle(this, title: pTitle, surfaceTitle: false);
  return this;
}

} // namespace sceneviewer
