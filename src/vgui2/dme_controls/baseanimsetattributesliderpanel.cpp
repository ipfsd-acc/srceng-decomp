// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/baseanimsetattributesliderpanel.cpp
// Functions: 39
// ============================================================

#include "vgui2\dme_controls\baseanimsetattributesliderpanel.h"

//------------------------------------------------------------------------------
// Address: 0x00488A40
// Name: public: static char const __near * CBaseAnimSetAttributeSliderPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseAnimSetAttributeSliderPanel::GetPanelClassName()
{
  return "CBaseAnimSetAttributeSliderPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00488A50
// Name: public: static char const __near * CPresetSideFilterSlider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPresetSideFilterSlider::GetPanelClassName()
{
  return "CPresetSideFilterSlider";
}

//------------------------------------------------------------------------------
// Address: 0x00488A60
// Name: protected: virtual void CPresetSideFilterSlider::GetTrackRect(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSideFilterSlider::GetTrackRect(CPresetSideFilterSlider *this, int *x, int *y, int *w, int *h)
{
  vgui::Panel::GetSize(this, wide: w, tall: h);
  *x = 0;
  *y = 2;
  *h -= 4;
}

//------------------------------------------------------------------------------
// Address: 0x00488A90
// Name: protected: virtual void CPresetSideFilterSlider::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSideFilterSlider::Paint(CPresetSideFilterSlider *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  int v4; // eax
  int x; // [esp+Ch] [ebp-14h] BYREF
  int wide; // [esp+10h] [ebp-10h] BYREF
  int tall; // [esp+14h] [ebp-Ch] BYREF
  int y; // [esp+18h] [ebp-8h] BYREF
  Color col; // [esp+1Ch] [ebp-4h] BYREF

  this->GetTrackRect(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  this->GetFgColor(this, result: &col);
  ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: col);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = vgui::Panel::GetTall(this);
  v3->DrawFilledRect(this: v2, a2: this->_nobPos[0], a3: 1, a4: this->_nobPos[1], a5: v4 - 1);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_ZeroColor);
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: this->_nobPos[0] - 1,
    a3: y + 1,
    a4: this->_nobPos[0],
    a5: y + tall - 1);
}

//------------------------------------------------------------------------------
// Address: 0x00488B40
// Name: protected: virtual void CPresetSideFilterSlider::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSideFilterSlider::PaintBackground(CPresetSideFilterSlider *this)
{
  Color m_TextColorFocus; // eax
  int cw; // [esp+Ch] [ebp-20h] BYREF
  int w; // [esp+10h] [ebp-1Ch] BYREF
  int v5; // [esp+14h] [ebp-18h] BYREF
  int h; // [esp+18h] [ebp-14h] BYREF
  int tw; // [esp+1Ch] [ebp-10h] BYREF
  int tx; // [esp+20h] [ebp-Ch] BYREF
  int th; // [esp+24h] [ebp-8h] BYREF
  int ty; // [esp+28h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  this->GetTrackRect(this, a2: &tx, a3: &ty, a4: &tw, a5: &th);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_ZeroColor);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: tx, a3: ty, a4: tx + tw, a5: ty + th);
  if ( this->_dragging )
    m_TextColorFocus = this->m_TextColorFocus;
  else
    m_TextColorFocus = this->m_TextColor;
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pName->SetColor)(a1: this->m_pName, a2: m_TextColorFocus);
  this->m_pName->GetContentSize(this: this->m_pName, a2: &cw, a3: &v5);
  this->m_pName->SetPos(
    this: this->m_pName,
    a2: (int)(float)((float)(w - cw) * 0.5),
    a3: (int)(float)((float)(h - v5) * 0.5));
  this->m_pName->Paint(this: this->m_pName);
}

//------------------------------------------------------------------------------
// Address: 0x00488C40
// Name: protected: virtual void CBaseAnimSetAttributeSliderPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetAttributeSliderPanel::OnCommand(
        CBaseAnimSetAttributeSliderPanel *this,
        const char *pCommand)
{
  if ( _V_stricmp(s1: pCommand, s2: "OnLeftOnly") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "OnRightOnly") != 0 )
      vgui::Panel::OnCommand(this, command: pCommand);
    else
      this->m_pPresetSideFilter->SetValue(this: this->m_pPresetSideFilter, a2: 1000, a3: false);
  }
  else
  {
    this->m_pPresetSideFilter->SetValue(this: this->m_pPresetSideFilter, a2: 0, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00488CC0
// Name: protected: virtual void CBaseAnimSetAttributeSliderPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetAttributeSliderPanel::PerformLayout(CBaseAnimSetAttributeSliderPanel *this)
{
  int h; // [esp+4h] [ebp-8h] BYREF
  int w; // [esp+8h] [ebp-4h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  vgui::Panel::SetBounds(this: this->m_pLeftRightBoth[0], x: 15, y: 11, wide: 9, tall: 9);
  vgui::Panel::SetBounds(this: this->m_pLeftRightBoth[1], x: w - 15, y: 11, wide: 9, tall: 9);
  vgui::Panel::SetBounds(this: this->m_pPresetSideFilter, x: 32, y: 4, wide: w - 56, tall: 24);
}

//------------------------------------------------------------------------------
// Address: 0x00488D30
// Name: protected: virtual void CBaseAnimSetAttributeSliderPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetAttributeSliderPanel::OnTick(CBaseAnimSetAttributeSliderPanel *this)
{
  unsigned int v2; // esi

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  if ( !this->IsVisible(this) )
  {
LABEL_6:
    this->OnThink(this);
    return;
  }
  v2 = this->GetVParent(this);
  if ( v2 != 0 )
  {
    while ( g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: v2) )
    {
      v2 = g_pVGuiPanel->GetParent(this: g_pVGuiPanel, a2: v2);
      if ( v2 == 0 )
        return;
    }
    goto LABEL_6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00488DA0
// Name: protected: virtual bool CBaseAnimSetAttributeSliderPanel::ApplySliderValues(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAnimSetAttributeSliderPanel::ApplySliderValues(
        CBaseAnimSetAttributeSliderPanel *this,
        BOOL bForce)
{
  bool v3; // bl

  v3 = CBaseAnimationSetControl::ApplySliderValues(this: this->m_pController, bForce);
  if ( v3 )
    this->UpdatePreview(this, a2: "ApplySliderValues\n");
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00488DE0
// Name: public: float CBaseAnimSetAttributeSliderPanel::GetBalanceSliderValue(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseAnimSetAttributeSliderPanel::GetBalanceSliderValue(CBaseAnimSetAttributeSliderPanel *this)
{
  return (double)((int (__thiscall *)(CPresetSideFilterSlider *, CBaseAnimSetAttributeSliderPanel *))this->m_pPresetSideFilter->GetValue)(
                   a1: this->m_pPresetSideFilter,
                   a2: this)
       * 0.001;
}

//------------------------------------------------------------------------------
// Address: 0x00488E10
// Name: public: virtual struct vgui::PanelMessageMap __near * CPresetSideFilterSlider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPresetSideFilterSlider::GetMessageMap(CPresetSideFilterSlider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPresetSideFilterSlider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPresetSideFilterSlider::GetMessageMap'::`2'::s_pMap;
  `CPresetSideFilterSlider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPresetSideFilterSlider");
  `CPresetSideFilterSlider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00488E40
// Name: public: virtual struct PanelAnimationMap __near * CPresetSideFilterSlider::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPresetSideFilterSlider::GetAnimMap(CPresetSideFilterSlider *this)
{
  return FindOrAddPanelAnimationMap(className: "CPresetSideFilterSlider");
}

//------------------------------------------------------------------------------
// Address: 0x00488E50
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPresetSideFilterSlider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPresetSideFilterSlider::GetKBMap(CPresetSideFilterSlider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPresetSideFilterSlider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPresetSideFilterSlider::GetKBMap'::`2'::s_pMap;
  `CPresetSideFilterSlider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPresetSideFilterSlider");
  `CPresetSideFilterSlider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00488E80
// Name: public: CPresetSideFilterSlider::CPresetSideFilterSlider(class CBaseAnimSetAttributeSliderPanel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CPresetSideFilterSlider *__thiscall CPresetSideFilterSlider::CPresetSideFilterSlider(
        CPresetSideFilterSlider *this,
        CBaseAnimSetAttributeSliderPanel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::TextImage *v7; // eax
  vgui::TextImage *v8; // eax

  vgui::Slider::Slider(this, parent, panelName);
  this->__vftable = (CPresetSideFilterSlider_vtbl *)&CPresetSideFilterSlider::`vftable';
  if ( `CPresetSideFilterSlider::ChainToMap'::`2'::chained == 0 )
  {
    `CPresetSideFilterSlider::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CPresetSideFilterSlider");
    v4->pfnClassName = CPresetSideFilterSlider::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Slider");
  }
  if ( `CPresetSideFilterSlider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPresetSideFilterSlider::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CPresetSideFilterSlider");
    v5->pfnClassName = CPresetSideFilterSlider::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Slider");
  }
  if ( `CPresetSideFilterSlider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPresetSideFilterSlider::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CPresetSideFilterSlider");
    v6->pfnClassName = CPresetSideFilterSlider::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Slider");
  }
  this->m_pParent = parent;
  this->m_ZeroColor = 0;
  this->m_TextColor = 0;
  this->m_TextColorFocus = 0;
  vgui::Slider::SetRange(this, min: 0, max: 1000);
  vgui::Slider::SetDragOnRepositionNob(this, state: true);
  this->SetValue(this, a2: 500, a3: false);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: true);
  v7 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x80u);
  if ( v7 != nullptr )
    v8 = vgui::TextImage::TextImage(this: v7, text: "Preset Side Filter");
  else
    v8 = nullptr;
  this->m_pName = v8;
  CDmeTrackGroup::SetMaxTrackCount(this, color: (Color)-2139062144);
  this->m_ZeroColor = (Color)-14606047;
  this->m_TextColor = (Color)-3618616;
  this->m_TextColorFocus = (Color)-14118960;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00489040
// Name: protected: virtual void CPresetSideFilterSlider::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSideFilterSlider::OnMousePressed(CPresetSideFilterSlider *this, ButtonCode_t code)
{
  if ( code == MOUSE_RIGHT )
    this->SetValue(this, a2: 500, a3: false);
  else
    vgui::Slider::OnMousePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x00489070
// Name: protected: virtual void CPresetSideFilterSlider::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSideFilterSlider::OnMouseDoublePressed(CPresetSideFilterSlider *this, ButtonCode_t code)
{
  if ( code == KEY_COUNT )
    this->SetValue(this, a2: 500, a3: false);
  else
    vgui::ScrollBarSlider::OnMouseDoublePressed((vgui::ToggleButton *)this, code);
}

//------------------------------------------------------------------------------
// Address: 0x004890A0
// Name: protected: virtual void CPresetSideFilterSlider::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSideFilterSlider::ApplySchemeSettings(CPresetSideFilterSlider *this, vgui::IScheme *scheme)
{
  vgui::TextImage_vtbl *v3; // ebx
  unsigned int v4; // eax

  vgui::Slider::ApplySchemeSettings(this, pScheme: scheme);
  v3 = this->m_pName->__vftable;
  v4 = scheme->GetFont(this: scheme, a2: "DefaultBold", a3: false);
  v3->SetFont(this: this->m_pName, a2: v4);
  ((void (__thiscall *)(vgui::TextImage *, _DWORD))this->m_pName->SetColor)(
    a1: this->m_pName,
    a2: *(_DWORD *)&this->m_TextColor);
  vgui::TextImage::ResizeImageToContent(this: this->m_pName);
  ((void (__thiscall *)(CPresetSideFilterSlider *, int))this->SetFgColor)(a1: this, a2: -16746302);
  this->SetThumbWidth(this, a2: 3);
}

//------------------------------------------------------------------------------
// Address: 0x00489130
// Name: public: virtual void CBaseAnimSetAttributeSliderPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetAttributeSliderPanel::ApplySchemeSettings(
        CBaseAnimSetAttributeSliderPanel *this,
        vgui::IScheme *scheme)
{
  vgui::Panel *v3; // eax

  vgui::Panel::ApplySchemeSettings(this, pScheme: scheme);
  v3 = vgui::PHandle::Get(this: &this->m_Sliders);
  ((void (__thiscall *)(vgui::Panel *, int))v3->SetBgColor)(a1: v3, a2: -14013910);
}

//------------------------------------------------------------------------------
// Address: 0x00489170
// Name: public: virtual void CBaseAnimSetAttributeSliderPanel::GetTypeInValueForControl(class CDmElement __near *,bool,struct AttributeValue_t __near &,struct AttributeValue_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetAttributeSliderPanel::GetTypeInValueForControl(
        CBaseAnimSetAttributeSliderPanel *this,
        CDmElement *pControl,
        bool bOrientation,
        AttributeValue_t *controlValue,
        const AttributeValue_t *sliderValue)
{
  QAngle ang; // [esp+0h] [ebp-Ch] BYREF

  if ( pControl != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pControl->IsA)(
         a1: pControl,
         a2: (CUtlSymbolLarge)CDmeTransformControl::m_classType.u.m_Id)
    && bOrientation )
  {
    QuaternionAngles(q: &sliderValue->m_Quaternion, angles: &ang);
    controlValue->m_Vector = (Vector)ang;
  }
  else
  {
    *controlValue = *sliderValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00489220
// Name: public: virtual void CBaseAnimSetAttributeSliderPanel::OnControlSelectionChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetAttributeSliderPanel::OnControlSelectionChanged(CBaseAnimSetAttributeSliderPanel *this)
{
  CBaseAnimSetAttributeSliderPanel *v1; // edi
  CAttributeSlider *v2; // esi
  CDmElement *v3; // eax
  TransformComponent_t SelectionComponentFlags; // eax
  int v5; // edi
  bool v6; // zf
  LogComponents_t v7; // edi
  vgui::PanelListPanel *v8; // eax
  int j; // edi
  int v10; // esi
  vgui::Panel *v11; // eax
  bool bShowSlider; // [esp+4h] [ebp-14h]
  int c; // [esp+8h] [ebp-10h]
  int i; // [esp+10h] [ebp-8h]
  bool visibleSlidersChanged; // [esp+17h] [ebp-1h]

  v1 = this;
  visibleSlidersChanged = false;
  c = *(_DWORD *)&this->m_InternalMouseDoublePressed_register;
  i = 0;
  if ( c > 0 )
  {
    while ( 1 )
    {
      v2 = *(CAttributeSlider **)(*(_DWORD *)&v1->m_OnNavigateFrom_register + 4 * i);
      v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2->m_hControl.m_handle);
      SelectionComponentFlags = CBaseAnimationSetControl::GetSelectionComponentFlags(
                                  this: *(CBaseAnimationSetControl **)&v1->m_clrDropFrame,
                                  pControl: v3);
      if ( (*((_BYTE *)v2 + 656) & 2) != 0 )
      {
        v5 = ((SelectionComponentFlags & 0x10) == 0 ? 0 : 2) | ((SelectionComponentFlags & 0x20) == 0 ? 0 : 4);
        v6 = (SelectionComponentFlags & 8) == 0;
      }
      else
      {
        v5 = ((SelectionComponentFlags & 2) == 0 ? 0 : 2) | ((SelectionComponentFlags & 4) == 0 ? 0 : 4);
        v6 = (SelectionComponentFlags & 1) == 0;
      }
      v7 = !v6 | v5;
      bShowSlider = SelectionComponentFlags != TRANSFORM_COMPONENT_NONE;
      if ( v2->IsVisible(this: v2) != (SelectionComponentFlags != TRANSFORM_COMPONENT_NONE) )
      {
        v2->SetVisible(this: v2, a2: bShowSlider);
        visibleSlidersChanged = true;
      }
      if ( CAttributeSlider::VisibleComponents(this: v2) != v7 )
        CAttributeSlider::SetVisibleComponents(this: v2, componentFlags: v7);
      if ( ++i >= c )
        break;
      v1 = this;
    }
    if ( visibleSlidersChanged )
    {
      v8 = (vgui::PanelListPanel *)vgui::PHandle::Get(this: (vgui::PHandle *)&this->m_OnDelete_register);
      vgui::PanelListPanel::RemoveAll(this: v8);
      for ( j = 0; j < c; ++j )
      {
        v10 = *(_DWORD *)(*(_DWORD *)&this->m_OnNavigateFrom_register + 4 * j);
        if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v10 + 136))(a1: v10) != 0 )
        {
          v11 = vgui::PHandle::Get(this: (vgui::PHandle *)&this->m_OnDelete_register);
          ((void (__thiscall *)(vgui::Panel *, _DWORD, int))v11->__vftable[1].GetVPanel)(a1: v11, a2: 0, a3: v10);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00489370
// Name: protected: void CBaseAnimSetAttributeSliderPanel::UpdateSliderDependencyFlags(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetAttributeSliderPanel::UpdateSliderDependencyFlags(CBaseAnimSetAttributeSliderPanel *this)
{
  CAttributeSlider *v2; // eax
  int m_Size; // edx
  int v4; // edi
  CAttributeSlider **m_pMemory; // ecx
  CAttributeSlider *v6; // esi
  bool v7; // al
  int nSliders; // [esp+8h] [ebp-8h]
  CAttributeSlider *pPrimarySlider; // [esp+Ch] [ebp-4h]

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL) )
  {
    v2 = (CAttributeSlider *)vgui::PHandle::Get(this: &this->m_pController->m_ActiveAttributeSlider);
    pPrimarySlider = v2;
  }
  else
  {
    pPrimarySlider = nullptr;
    v2 = nullptr;
  }
  m_Size = this->m_SliderList.m_Size;
  v4 = 0;
  for ( nSliders = m_Size; v4 < m_Size; ++v4 )
  {
    m_pMemory = this->m_SliderList.m_Memory.m_pMemory;
    v6 = m_pMemory[v4];
    if ( v6 != nullptr )
    {
      v7 = v2 != nullptr && CAttributeSlider::IsDependent(this: v2, pSlider: m_pMemory[v4]);
      CAttributeSlider::SetDependent(this: v6, dependent: v7);
      v2 = pPrimarySlider;
      m_Size = nSliders;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00489410
// Name: protected: int CBaseAnimSetAttributeSliderPanel::FindSliderIndexForControl(class CDmElement const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimSetAttributeSliderPanel::FindSliderIndexForControl(
        CBaseAnimSetAttributeSliderPanel *this,
        const CDmElement *control)
{
  int m_Size; // ebx
  int v4; // esi

  m_Size = this->m_SliderList.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return -1;
  while ( g_pDataModel->GetElement(
            this: g_pDataModel,
            a2: this->m_SliderList.m_Memory.m_pMemory[v4]->m_hControl.m_handle) != control )
  {
    if ( ++v4 >= m_Size )
      return -1;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00489470
// Name: public: bool CBaseAnimSetAttributeSliderPanel::GetSliderValues(struct AttributeValue_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAnimSetAttributeSliderPanel::GetSliderValues(
        CBaseAnimSetAttributeSliderPanel *this,
        AttributeValue_t *pValue,
        int nIndex)
{
  CAttributeSlider *v4; // esi
  vgui::Panel *v5; // ebx
  bool v6; // al
  CBaseAnimationSetControl *m_pController; // ecx
  AttributeValue_t *Preview; // eax

  v4 = this->m_SliderList.m_Memory.m_pMemory[nIndex];
  v5 = vgui::PHandle::Get(this: &this->m_pController->m_ActiveAttributeSlider);
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
    || (v6 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT)) )
  {
    v6 = true;
  }
  if ( v5 == v4 && v6
    || (*((_BYTE *)(m_pController = this->m_pController) + 104) & 2) != 0
    || CBaseAnimationSetControl::IsPresetFaderBeingDragged(this: m_pController) )
  {
    Preview = (AttributeValue_t *)CAttributeSlider::GetPreview(this: v4);
  }
  else
  {
    Preview = (AttributeValue_t *)CAttributeSlider::GetValue(this: v4);
  }
  *pValue = *Preview;
  return v4->IsVisible(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00489540
// Name: protected: virtual void CBaseAnimSetAttributeSliderPanel::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetAttributeSliderPanel::OnThink(CBaseAnimSetAttributeSliderPanel *this)
{
  vgui::Panel::OnThink(this);
  CBaseAnimationSetControl::UpdatePreviewSliderValues(this: this->m_pController);
  CBaseAnimationSetControl::UpdatePreviewSliderTimes(this: this->m_pController);
  this->ApplySliderValues(this, a2: false);
  CBaseAnimSetAttributeSliderPanel::UpdateSliderDependencyFlags(this);
}

//------------------------------------------------------------------------------
// Address: 0x00489580
// Name: protected: class CAttributeSlider __near * CBaseAnimSetAttributeSliderPanel::AllocateSlider(void)
// Source: json
//------------------------------------------------------------------------------
CAttributeSlider *__thiscall CBaseAnimSetAttributeSliderPanel::AllocateSlider(CBaseAnimSetAttributeSliderPanel *this)
{
  int m_Size; // eax
  CAttributeSlider *v3; // edi
  CAttributeSlider *v5; // eax
  CAttributeSlider *v6; // esi

  m_Size = this->m_FreeSliderList.m_Size;
  if ( m_Size <= 0 )
  {
    v5 = (CAttributeSlider *)MemAlloc_Alloc(nSize: 0x2ACu);
    if ( v5 != nullptr )
    {
      v6 = CAttributeSlider::CAttributeSlider(this: v5, parent: this);
      v6->SetVisible(this: v6, a2: true);
      return v6;
    }
    else
    {
      (*(void (__thiscall **)(_DWORD, int))(MEMORY[0] + 132))(a1: 0, a2: 1);
      return nullptr;
    }
  }
  else
  {
    v3 = this->m_FreeSliderList.m_Memory.m_pMemory[m_Size - 1];
    --this->m_FreeSliderList.m_Size;
    v3->SetVisible(this: v3, a2: true);
    return v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00489620
// Name: protected: void CBaseAnimSetAttributeSliderPanel::InitFreeSliderList(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetAttributeSliderPanel::InitFreeSliderList(
        CBaseAnimSetAttributeSliderPanel *this,
        int nCount)
{
  CBaseAnimSetAttributeSliderPanel *v2; // edi
  CUtlMemory<vgui::TreeNode *,int> *p_m_FreeSliderList; // esi
  CAttributeSlider *v4; // eax
  CAttributeSlider *v5; // ebx
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  CAttributeSlider **v10; // eax

  v2 = this;
  if ( nCount > 0 )
  {
    p_m_FreeSliderList = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_FreeSliderList;
    while ( 1 )
    {
      v4 = (CAttributeSlider *)MemAlloc_Alloc(nSize: 0x2ACu);
      if ( v4 != nullptr )
        v5 = CAttributeSlider::CAttributeSlider(this: v4, parent: v2);
      else
        v5 = nullptr;
      v5->SetVisible(this: v5, a2: false);
      m_pMemory = p_m_FreeSliderList[1].m_pMemory;
      m_nAllocationCount = p_m_FreeSliderList->m_nAllocationCount;
      if ( (int)m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_FreeSliderList, num: (int)m_pMemory - m_nAllocationCount + 1);
      ++p_m_FreeSliderList[1].m_pMemory;
      v8 = p_m_FreeSliderList->m_pMemory;
      v9 = (char *)p_m_FreeSliderList[1].m_pMemory - (char *)m_pMemory - 1;
      p_m_FreeSliderList[1].m_nAllocationCount = (int)p_m_FreeSliderList->m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &v8[(_DWORD)m_pMemory + 1], src: &v8[(_DWORD)m_pMemory], count: 4 * v9);
      v10 = (CAttributeSlider **)&p_m_FreeSliderList->m_pMemory[(_DWORD)m_pMemory];
      if ( v10 != nullptr )
        *v10 = v5;
      if ( --nCount == 0 )
        break;
      v2 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004896D0
// Name: public: CBaseAnimSetAttributeSliderPanel::CBaseAnimSetAttributeSliderPanel(class vgui::Panel __near *,char const __near *,class CBaseAnimationSetEditor __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseAnimSetAttributeSliderPanel *__thiscall CBaseAnimSetAttributeSliderPanel::CBaseAnimSetAttributeSliderPanel(
        CBaseAnimSetAttributeSliderPanel *this,
        vgui::Panel *parent,
        const char *className,
        CBaseAnimationSetEditor *editor)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Button *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  CPresetSideFilterSlider *v12; // eax
  CPresetSideFilterSlider *v13; // eax
  vgui::PanelListPanel *v14; // eax
  vgui::PanelListPanel *v15; // eax
  vgui::PanelListPanel *v16; // eax
  vgui::Panel *v17; // eax
  vgui::PanelListPanel *v18; // eax
  CBaseAnimationSetControl *Controller; // eax

  vgui::EditablePanel::EditablePanel(this, parent, panelName: className);
  this->IAnimationSetControlSelectionChangedListener::__vftable = (IAnimationSetControlSelectionChangedListener_vtbl *)&IAnimationSetControlSelectionChangedListener::`vftable';
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CBaseAnimSetAttributeSliderPanel_vtbl *)&CBaseAnimSetAttributeSliderPanel::`vftable'{for `vgui::EditablePanel'};
  this->IAnimationSetControlSelectionChangedListener::__vftable = (IAnimationSetControlSelectionChangedListener_vtbl *)&CBaseAnimSetAttributeSliderPanel::`vftable'{for `IAnimationSetControlSelectionChangedListener'};
  if ( `CBaseAnimSetAttributeSliderPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAnimSetAttributeSliderPanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetAttributeSliderPanel");
    v5->pfnClassName = CBaseAnimSetAttributeSliderPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CBaseAnimSetAttributeSliderPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseAnimSetAttributeSliderPanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CBaseAnimSetAttributeSliderPanel");
    v6->pfnClassName = CBaseAnimSetAttributeSliderPanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CBaseAnimSetAttributeSliderPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAnimSetAttributeSliderPanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAnimSetAttributeSliderPanel");
    v7->pfnClassName = CBaseAnimSetAttributeSliderPanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  this->m_hEditor.m_iPanelID = -1;
  this->m_Sliders.m_iPanelID = -1;
  this->m_SliderList.m_Memory.m_pMemory = nullptr;
  this->m_SliderList.m_Memory.m_nAllocationCount = 0;
  this->m_SliderList.m_Memory.m_nGrowSize = 0;
  this->m_SliderList.m_Size = 0;
  this->m_SliderList.m_pElements = nullptr;
  this->m_pController = nullptr;
  this->m_FreeSliderList.m_Memory.m_pMemory = nullptr;
  this->m_FreeSliderList.m_Memory.m_nAllocationCount = 0;
  this->m_FreeSliderList.m_Memory.m_nGrowSize = 0;
  this->m_FreeSliderList.m_Size = 0;
  this->m_FreeSliderList.m_pElements = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hEditor, pPanel: editor);
  v8 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v8 != nullptr )
    v9 = vgui::Button::Button(
           this: v8,
           parent: this,
           panelName: "AttributeSliderLeftOnly",
           text: defaultValue,
           pActionSignalTarget: this,
           pCmd: "OnLeftOnly");
  else
    v9 = nullptr;
  this->m_pLeftRightBoth[0] = v9;
  v10 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v10 != nullptr )
    v11 = vgui::Button::Button(
            this: v10,
            parent: this,
            panelName: "AttributeSliderRightOnly",
            text: defaultValue,
            pActionSignalTarget: this,
            pCmd: "OnRightOnly");
  else
    v11 = nullptr;
  this->m_pLeftRightBoth[1] = v11;
  v12 = (CPresetSideFilterSlider *)MemAlloc_Alloc(nSize: 0x1C4u);
  if ( v12 != nullptr )
    v13 = CPresetSideFilterSlider::CPresetSideFilterSlider(this: v12, parent: this, panelName: "PresetSideFilter");
  else
    v13 = nullptr;
  this->m_pPresetSideFilter = v13;
  v14 = (vgui::PanelListPanel *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v14 != nullptr )
    v15 = vgui::PanelListPanel::PanelListPanel(this: v14, parent: this, panelName: "AttributeSliders");
  else
    v15 = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_Sliders, pPanel: v15);
  v16 = (vgui::PanelListPanel *)vgui::PHandle::Get(this: &this->m_Sliders);
  vgui::PanelListPanel::SetFirstColumnWidth(this: v16, width: 0);
  v17 = vgui::PHandle::Get(this: &this->m_Sliders);
  vgui::Panel::SetAutoResize(
    this: v17,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 32,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  v18 = (vgui::PanelListPanel *)vgui::PHandle::Get(this: &this->m_Sliders);
  vgui::PanelListPanel::SetVerticalBufferPixels(this: v18, buffer: 0);
  Controller = CBaseAnimationSetEditor::GetController(this: editor);
  this->m_pController = Controller;
  CBaseAnimationSetControl::AddControlSelectionChangedListener(
    this: Controller,
    listener: &this->IAnimationSetControlSelectionChangedListener);
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  CBaseAnimSetAttributeSliderPanel::InitFreeSliderList(this, nCount: 1500);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00489940
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseAnimSetAttributeSliderPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseAnimSetAttributeSliderPanel::GetMessageMap(
        CBaseAnimSetAttributeSliderPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseAnimSetAttributeSliderPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAnimSetAttributeSliderPanel::GetMessageMap'::`2'::s_pMap;
  `CBaseAnimSetAttributeSliderPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetAttributeSliderPanel");
  `CBaseAnimSetAttributeSliderPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00489970
// Name: public: virtual struct PanelAnimationMap __near * CBaseAnimSetAttributeSliderPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseAnimSetAttributeSliderPanel::GetAnimMap(CBaseAnimSetAttributeSliderPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseAnimSetAttributeSliderPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00489980
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseAnimSetAttributeSliderPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseAnimSetAttributeSliderPanel::GetKBMap(CBaseAnimSetAttributeSliderPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseAnimSetAttributeSliderPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAnimSetAttributeSliderPanel::GetKBMap'::`2'::s_pMap;
  `CBaseAnimSetAttributeSliderPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAnimSetAttributeSliderPanel");
  `CBaseAnimSetAttributeSliderPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004899F0
// Name: protected: void CBaseAnimSetAttributeSliderPanel::RebuildSliderLists(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetAttributeSliderPanel::RebuildSliderLists(CBaseAnimSetAttributeSliderPanel *this)
{
  CBaseAnimSetAttributeSliderPanel *v1; // ebx
  CDmElement *m_Size; // eax
  void (__thiscall *SetVisible)(vgui::Panel *, bool); // eax
  int v4; // edi
  int m_nAllocationCount; // eax
  CAttributeSlider **m_pMemory; // ecx
  int v7; // eax
  int *v8; // edi
  CUtlMemory<vgui::TreeNode *,int> *p_m_SliderList; // esi
  vgui::PanelListPanel *v10; // eax
  CBaseAnimationSetControl *m_pController; // ecx
  CDmeTransform *j; // eax
  CDmElement *Position; // eax
  int v14; // edx
  int v15; // ecx
  CDmElement *v16; // eax
  CDmElement *v17; // ebx
  int v18; // edi
  int v19; // eax
  CDmElement **v20; // ecx
  int v21; // eax
  CDmElement **v22; // edi
  CDmElement *v23; // edi
  CAttributeSlider *Slider; // ebx
  vgui::TreeNode **v25; // edi
  int v26; // eax
  vgui::TreeNode **v27; // ecx
  int v28; // eax
  CAttributeSlider **v29; // edi
  CDmElement *v30; // edi
  CAttributeSlider *v31; // ebx
  vgui::TreeNode **v32; // edi
  int v33; // eax
  vgui::TreeNode **v34; // ecx
  int v35; // eax
  CAttributeSlider **v36; // edi
  CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > controlList; // [esp+Ch] [ebp-2Ch] BYREF
  CAnimSetGroupAnimSetTraversal traversal; // [esp+20h] [ebp-18h] BYREF
  CDmElement *control; // [esp+28h] [ebp-10h]
  int controlCount; // [esp+2Ch] [ebp-Ch]
  CBaseAnimSetAttributeSliderPanel *v41; // [esp+30h] [ebp-8h]
  int i; // [esp+34h] [ebp-4h]

  v1 = this;
  m_Size = (CDmElement *)this->m_SliderList.m_Size;
  v41 = this;
  control = m_Size;
  for ( i = 0; i < (int)control; ++i )
  {
    SetVisible = v1->m_SliderList.m_Memory.m_pMemory[i]->SetVisible;
    controlCount = (int)v1->m_SliderList.m_Memory.m_pMemory[i];
    ((void (__stdcall *)(_DWORD))SetVisible)(a1: 0);
    v4 = v1->m_FreeSliderList.m_Size;
    m_nAllocationCount = v1->m_FreeSliderList.m_Memory.m_nAllocationCount;
    if ( v4 + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&v1->m_FreeSliderList,
        num: v4 - m_nAllocationCount + 1);
    ++v1->m_FreeSliderList.m_Size;
    m_pMemory = v1->m_FreeSliderList.m_Memory.m_pMemory;
    v7 = v1->m_FreeSliderList.m_Size - v4 - 1;
    v1->m_FreeSliderList.m_pElements = m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &m_pMemory[v4 + 1], src: &m_pMemory[v4], count: 4 * v7);
    v8 = (int *)&v1->m_FreeSliderList.m_Memory.m_pMemory[v4];
    if ( v8 != nullptr )
      *v8 = controlCount;
  }
  p_m_SliderList = (CUtlMemory<vgui::TreeNode *,int> *)&v1->m_SliderList;
  v1->m_SliderList.m_Size = 0;
  v10 = (vgui::PanelListPanel *)vgui::PHandle::Get(this: &v1->m_Sliders);
  vgui::PanelListPanel::RemoveAll(this: v10);
  m_pController = v1->m_pController;
  memset(&controlList, 0, sizeof(controlList));
  traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: m_pController);
  traversal.m_nIndex = 0;
  for ( j = (CDmeTransform *)CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
        j != nullptr;
        j = (CDmeTransform *)CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
  {
    Position = (CDmElement *)CDmeTransform::GetPosition(this: j);
    v14 = *(_DWORD *)&Position->m_Id.m_Value[8];
    v15 = 0;
    control = Position;
    controlCount = v14;
    i = 0;
    if ( v14 > 0 )
    {
      while ( 1 )
      {
        v16 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&Position->OnAttributeChanged + v15));
        v17 = v16;
        if ( v16 != nullptr && v16->IsA(this: v16, a2: CDmElement::m_classType) )
        {
          v18 = controlList.m_Size;
          v19 = controlList.m_Size;
          if ( controlList.m_Size + 1 > controlList.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&controlList,
              num: controlList.m_Size - controlList.m_Memory.m_nAllocationCount + 1);
            v19 = controlList.m_Size;
          }
          v20 = controlList.m_Memory.m_pMemory;
          controlList.m_Size = v19 + 1;
          v21 = v19 - v18;
          controlList.m_pElements = controlList.m_Memory.m_pMemory;
          if ( v21 > 0 )
          {
            _V_memmove(
              dest: &controlList.m_Memory.m_pMemory[v18 + 1],
              src: &controlList.m_Memory.m_pMemory[v18],
              count: 4 * v21);
            v20 = controlList.m_Memory.m_pMemory;
          }
          v22 = &v20[v18];
          if ( v22 != nullptr )
            *v22 = v17;
        }
        v15 = i + 1;
        i = v15;
        if ( v15 >= controlCount )
          break;
        Position = control;
      }
      v1 = v41;
    }
  }
  i = 0;
  if ( controlList.m_Size > 0 )
  {
    while ( 1 )
    {
      control = controlList.m_Memory.m_pMemory[i];
      v23 = control;
      Slider = CBaseAnimSetAttributeSliderPanel::AllocateSlider(this: v1);
      CAttributeSlider::Init(this: Slider, control: v23, bOrientation: false);
      Slider->SetVisible(this: Slider, a2: false);
      v25 = p_m_SliderList[1].m_pMemory;
      v26 = p_m_SliderList->m_nAllocationCount;
      if ( (int)v25 + 1 > v26 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_SliderList, num: (int)v25 - v26 + 1);
      ++p_m_SliderList[1].m_pMemory;
      v27 = p_m_SliderList->m_pMemory;
      v28 = (char *)p_m_SliderList[1].m_pMemory - (char *)v25 - 1;
      p_m_SliderList[1].m_nAllocationCount = (int)p_m_SliderList->m_pMemory;
      if ( v28 > 0 )
        _V_memmove(dest: &v27[(_DWORD)v25 + 1], src: &v27[(_DWORD)v25], count: 4 * v28);
      v29 = (CAttributeSlider **)&p_m_SliderList->m_pMemory[(_DWORD)v25];
      if ( v29 != nullptr )
        *v29 = Slider;
      v30 = control;
      if ( control != nullptr
        && ((int (__thiscall *)(_DWORD, _DWORD))control->IsA)(
             a1: control,
             a2: (CUtlSymbolLarge)CDmeTransformControl::m_classType.u.m_Id) )
      {
        v31 = CBaseAnimSetAttributeSliderPanel::AllocateSlider(this: v41);
        CAttributeSlider::Init(this: v31, control: v30, bOrientation: true);
        v31->SetVisible(this: v31, a2: false);
        v32 = p_m_SliderList[1].m_pMemory;
        v33 = p_m_SliderList->m_nAllocationCount;
        if ( (int)v32 + 1 > v33 )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_SliderList, num: (int)v32 - v33 + 1);
        ++p_m_SliderList[1].m_pMemory;
        v34 = p_m_SliderList->m_pMemory;
        v35 = (char *)p_m_SliderList[1].m_pMemory - (char *)v32 - 1;
        p_m_SliderList[1].m_nAllocationCount = (int)p_m_SliderList->m_pMemory;
        if ( v35 > 0 )
          _V_memmove(dest: &v34[(_DWORD)v32 + 1], src: &v34[(_DWORD)v32], count: 4 * v35);
        v36 = (CAttributeSlider **)&p_m_SliderList->m_pMemory[(_DWORD)v32];
        if ( v36 != nullptr )
          *v36 = v31;
      }
      if ( ++i >= controlList.m_Size )
        break;
      v1 = v41;
    }
  }
  if ( controlList.m_Memory.m_nGrowSize >= 0 && controlList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: controlList.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00489D20
// Name: public: virtual void CBaseAnimSetAttributeSliderPanel::OnControlsAddedOrRemoved(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetAttributeSliderPanel::OnControlsAddedOrRemoved(CBaseAnimSetAttributeSliderPanel *this)
{
  CBaseAnimSetAttributeSliderPanel *v1; // ebx
  CBaseAnimationSetControl *m_pController; // ecx
  int v3; // edi
  CDmeTransform *v4; // eax
  const CDmaElementArray<CDmElement> *Position; // eax
  int m_Size; // edx
  int v7; // ecx
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  CAttributeSlider *v10; // ebx
  bool v11; // zf
  bool v12; // bl
  DmElementHandle_t m_handle; // [esp-4h] [ebp-2Ch]
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-1Ch] BYREF
  int controlCount; // [esp+14h] [ebp-14h]
  const CDmaElementArray<CDmElement> *controls; // [esp+18h] [ebp-10h]
  int i; // [esp+1Ch] [ebp-Ch]
  CBaseAnimSetAttributeSliderPanel *v18; // [esp+20h] [ebp-8h]
  bool changed; // [esp+27h] [ebp-1h]

  v1 = this;
  m_pController = this->m_pController;
  v18 = v1;
  changed = false;
  v3 = 0;
  traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: m_pController);
  traversal.m_nIndex = 0;
  v4 = (CDmeTransform *)CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  if ( v4 != nullptr )
  {
    do
    {
      Position = (const CDmaElementArray<CDmElement> *)CDmeTransform::GetPosition(this: v4);
      m_Size = Position->m_Storage.m_Size;
      v7 = 0;
      controls = Position;
      controlCount = m_Size;
      i = 0;
      if ( m_Size > 0 )
      {
        while ( 1 )
        {
          v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: Position->m_Storage.m_Memory.m_pMemory[v7]);
          v9 = v8;
          if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmElement::m_classType) )
          {
            if ( v3 >= v1->m_SliderList.m_Size )
              break;
            v10 = v1->m_SliderList.m_Memory.m_pMemory[v3++];
            if ( g_pDataModel->GetElement(this: g_pDataModel, a2: v10->m_hControl.m_handle) != v9 )
              break;
            if ( v9->IsA(this: v9, a2: CDmeTransformControl::m_classType) )
            {
              m_handle = v18->m_SliderList.m_Memory.m_pMemory[v3++]->m_hControl.m_handle;
              v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_handle) == v9;
            }
            else
            {
              v12 = (*((_BYTE *)v10 + 656) & 4) != 0;
              v11 = v12 == CDmElement::HasAttribute(this: v9, pAttributeName: "rightValue", type: AT_UNKNOWN);
            }
            if ( !v11 )
              break;
          }
          v7 = i + 1;
          i = v7;
          if ( v7 >= controlCount )
            goto LABEL_16;
          v1 = v18;
          Position = controls;
        }
        changed = true;
      }
LABEL_16:
      v4 = (CDmeTransform *)CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
      v1 = v18;
    }
    while ( v4 != nullptr );
    if ( changed )
      goto LABEL_19;
  }
  if ( v3 != v1->m_SliderList.m_Size )
LABEL_19:
    CBaseAnimSetAttributeSliderPanel::RebuildSliderLists(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00489E80
// Name: public: virtual void CBaseAnimSetAttributeSliderPanel::ChangeAnimationSetClip(class CDmeFilmClip __near *)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CBaseAnimSetAttributeSliderPanel::ChangeAnimationSetClip(
        CBaseAnimSetAttributeSliderPanel *this,
        CDmeFilmClip *pFilmClip)
{
  CBaseAnimSetAttributeSliderPanel::RebuildSliderLists(this);
}

//------------------------------------------------------------------------------
// Address: 0x00680F00
// Name: _dynamic_initializer_for__panel_test_title_safe__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__panel_test_title_safe__()
{
  ConVar::ConVar(
    this: &panel_test_title_safe,
    pName: "panel_test_title_safe",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Test vgui panel positioning with title safe indentation");
  return atexit(func: dynamic_atexit_destructor_for__panel_test_title_safe__);
}

//------------------------------------------------------------------------------
// Address: 0x006815F0
// Name: _dynamic_initializer_for__anim_3wayblend__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__anim_3wayblend__()
{
  ConVar::ConVar(
    this: &anim_3wayblend,
    pName: "anim_3wayblend",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "Toggle the 3-way animation blending code.");
  return atexit(func: dynamic_atexit_destructor_for__anim_3wayblend__);
}

//------------------------------------------------------------------------------
// Address: 0x006833C0
// Name: _dynamic_atexit_destructor_for__panel_test_title_safe__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__panel_test_title_safe__()
{
  ConVar::~ConVar(this: &panel_test_title_safe);
}

//------------------------------------------------------------------------------
// Address: 0x00683590
// Name: _dynamic_atexit_destructor_for__anim_3wayblend__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__anim_3wayblend__()
{
  ConVar::~ConVar(this: &anim_3wayblend);
}

//------------------------------------------------------------------------------
// Address: 0x00681620
// Name: _dynamic_initializer_for__s_DMXAllocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_DMXAllocator__()
{
  CMemoryStack::CMemoryStack(this: &s_DMXAllocator);
  return atexit(func: dynamic_atexit_destructor_for__s_DMXAllocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006835A0
// Name: _dynamic_atexit_destructor_for__s_DMXAllocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_DMXAllocator__()
{
  CMemoryStack::~CMemoryStack(this: &s_DMXAllocator);
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1048C930
// Name: public: static char const __near * CBaseAnimSetAttributeSliderPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseAnimSetAttributeSliderPanel::GetPanelClassName()
{
  return "CBaseAnimSetAttributeSliderPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1048C940
// Name: public: static char const __near * CPresetSideFilterSlider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPresetSideFilterSlider::GetPanelClassName()
{
  return "CPresetSideFilterSlider";
}

//------------------------------------------------------------------------------
// Address: 0x1048C950
// Name: protected: virtual void CPresetSideFilterSlider::GetTrackRect(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSideFilterSlider::GetTrackRect(CPresetSideFilterSlider *this, int *x, int *y, int *w, int *h)
{
  vgui::Panel::GetSize(this, wide: w, tall: h);
  *x = 0;
  *y = 2;
  *h -= 4;
}

//------------------------------------------------------------------------------
// Address: 0x1048C980
// Name: protected: virtual void CPresetSideFilterSlider::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSideFilterSlider::Paint(CPresetSideFilterSlider *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  int v4; // eax
  int x; // [esp+Ch] [ebp-14h] BYREF
  int wide; // [esp+10h] [ebp-10h] BYREF
  int tall; // [esp+14h] [ebp-Ch] BYREF
  int y; // [esp+18h] [ebp-8h] BYREF
  Color col; // [esp+1Ch] [ebp-4h] BYREF

  this->GetTrackRect(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  this->GetFgColor(this, result: &col);
  ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: col);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = vgui::Panel::GetTall(this);
  v3->DrawFilledRect(this: v2, a2: this->_nobPos[0], a3: 1, a4: this->_nobPos[1], a5: v4 - 1);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_ZeroColor);
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: this->_nobPos[0] - 1,
    a3: y + 1,
    a4: this->_nobPos[0],
    a5: y + tall - 1);
}

//------------------------------------------------------------------------------
// Address: 0x1048CA30
// Name: protected: virtual void CPresetSideFilterSlider::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSideFilterSlider::PaintBackground(CPresetSideFilterSlider *this)
{
  Color m_TextColorFocus; // eax
  int cw; // [esp+Ch] [ebp-20h] BYREF
  int w; // [esp+10h] [ebp-1Ch] BYREF
  int v5; // [esp+14h] [ebp-18h] BYREF
  int h; // [esp+18h] [ebp-14h] BYREF
  int tw; // [esp+1Ch] [ebp-10h] BYREF
  int tx; // [esp+20h] [ebp-Ch] BYREF
  int th; // [esp+24h] [ebp-8h] BYREF
  int ty; // [esp+28h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  this->GetTrackRect(this, a2: &tx, a3: &ty, a4: &tw, a5: &th);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_ZeroColor);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: tx, a3: ty, a4: tx + tw, a5: ty + th);
  if ( this->_dragging )
    m_TextColorFocus = this->m_TextColorFocus;
  else
    m_TextColorFocus = this->m_TextColor;
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pName->SetColor)(a1: this->m_pName, a2: m_TextColorFocus);
  this->m_pName->GetContentSize(this: this->m_pName, a2: &cw, a3: &v5);
  this->m_pName->SetPos(
    this: this->m_pName,
    a2: (int)(float)((float)(w - cw) * 0.5),
    a3: (int)(float)((float)(h - v5) * 0.5));
  this->m_pName->Paint(this: this->m_pName);
}

//------------------------------------------------------------------------------
// Address: 0x1048CB30
// Name: protected: virtual void CBaseAnimSetAttributeSliderPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetAttributeSliderPanel::OnCommand(
        CBaseAnimSetAttributeSliderPanel *this,
        const char *pCommand)
{
  if ( _V_stricmp(s1: pCommand, s2: "OnLeftOnly") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "OnRightOnly") != 0 )
      vgui::Panel::OnCommand(this, command: pCommand);
    else
      this->m_pPresetSideFilter->SetValue(this: this->m_pPresetSideFilter, a2: 1000, a3: false);
  }
  else
  {
    this->m_pPresetSideFilter->SetValue(this: this->m_pPresetSideFilter, a2: 0, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1048CBB0
// Name: protected: virtual void CBaseAnimSetAttributeSliderPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetAttributeSliderPanel::PerformLayout(CBaseAnimSetAttributeSliderPanel *this)
{
  int h; // [esp+4h] [ebp-8h] BYREF
  int w; // [esp+8h] [ebp-4h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  vgui::Panel::SetBounds(this: this->m_pLeftRightBoth[0], x: 15, y: 11, wide: 9, tall: 9);
  vgui::Panel::SetBounds(this: this->m_pLeftRightBoth[1], x: w - 15, y: 11, wide: 9, tall: 9);
  vgui::Panel::SetBounds(this: this->m_pPresetSideFilter, x: 32, y: 4, wide: w - 56, tall: 24);
}

//------------------------------------------------------------------------------
// Address: 0x1048CC20
// Name: protected: virtual void CBaseAnimSetAttributeSliderPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetAttributeSliderPanel::OnTick(CBaseAnimSetAttributeSliderPanel *this)
{
  unsigned int v2; // esi

  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  if ( !this->IsVisible(this) )
  {
LABEL_6:
    this->OnThink(this);
    return;
  }
  v2 = this->GetVParent(this);
  if ( v2 != 0 )
  {
    while ( g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: v2) )
    {
      v2 = g_pVGuiPanel->GetParent(this: g_pVGuiPanel, a2: v2);
      if ( v2 == 0 )
        return;
    }
    goto LABEL_6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1048CC90
// Name: protected: virtual bool CBaseAnimSetAttributeSliderPanel::ApplySliderValues(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAnimSetAttributeSliderPanel::ApplySliderValues(
        CBaseAnimSetAttributeSliderPanel *this,
        bool bForce)
{
  bool v3; // bl

  v3 = CBaseAnimationSetControl::ApplySliderValues(this: this->m_pController, bForce);
  if ( v3 )
    this->UpdatePreview(this, a2: "ApplySliderValues\n");
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1048CCD0
// Name: public: float CBaseAnimSetAttributeSliderPanel::GetBalanceSliderValue(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseAnimSetAttributeSliderPanel::GetBalanceSliderValue(CBaseAnimSetAttributeSliderPanel *this)
{
  return (double)((int (__thiscall *)(CPresetSideFilterSlider *, CBaseAnimSetAttributeSliderPanel *))this->m_pPresetSideFilter->GetValue)(
                   a1: this->m_pPresetSideFilter,
                   a2: this)
       * 0.001;
}

//------------------------------------------------------------------------------
// Address: 0x1048CD00
// Name: public: virtual struct vgui::PanelMessageMap __near * CPresetSideFilterSlider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPresetSideFilterSlider::GetMessageMap(CPresetSideFilterSlider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPresetSideFilterSlider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPresetSideFilterSlider::GetMessageMap'::`2'::s_pMap;
  `CPresetSideFilterSlider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPresetSideFilterSlider");
  `CPresetSideFilterSlider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1048CD30
// Name: public: virtual struct PanelAnimationMap __near * CPresetSideFilterSlider::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPresetSideFilterSlider::GetAnimMap(CPresetSideFilterSlider *this)
{
  return FindOrAddPanelAnimationMap(className: "CPresetSideFilterSlider");
}

//------------------------------------------------------------------------------
// Address: 0x1048CD40
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPresetSideFilterSlider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPresetSideFilterSlider::GetKBMap(CPresetSideFilterSlider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPresetSideFilterSlider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPresetSideFilterSlider::GetKBMap'::`2'::s_pMap;
  `CPresetSideFilterSlider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPresetSideFilterSlider");
  `CPresetSideFilterSlider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1048CD70
// Name: public: CPresetSideFilterSlider::CPresetSideFilterSlider(class CBaseAnimSetAttributeSliderPanel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CPresetSideFilterSlider *__thiscall CPresetSideFilterSlider::CPresetSideFilterSlider(
        CPresetSideFilterSlider *this,
        CBaseAnimSetAttributeSliderPanel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::TextImage *v7; // eax
  vgui::TextImage *v8; // eax

  vgui::Slider::Slider(this, parent, panelName);
  this->__vftable = (CPresetSideFilterSlider_vtbl *)&CPresetSideFilterSlider::`vftable';
  if ( `CPresetSideFilterSlider::ChainToMap'::`2'::chained == 0 )
  {
    `CPresetSideFilterSlider::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CPresetSideFilterSlider");
    v4->pfnClassName = CPresetSideFilterSlider::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Slider");
  }
  if ( `CPresetSideFilterSlider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPresetSideFilterSlider::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CPresetSideFilterSlider");
    v5->pfnClassName = CPresetSideFilterSlider::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Slider");
  }
  if ( `CPresetSideFilterSlider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPresetSideFilterSlider::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CPresetSideFilterSlider");
    v6->pfnClassName = CPresetSideFilterSlider::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Slider");
  }
  this->m_pParent = parent;
  this->m_ZeroColor = 0;
  this->m_TextColor = 0;
  this->m_TextColorFocus = 0;
  vgui::Slider::SetRange(this, min: 0, max: 1000);
  vgui::Slider::SetDragOnRepositionNob(this, state: true);
  this->SetValue(this, a2: 500, a3: false);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: true);
  v7 = (vgui::TextImage *)operator new(nSize: 0x7Cu);
  if ( v7 != nullptr )
    v8 = vgui::TextImage::TextImage(this: v7, text: "Preset Side Filter");
  else
    v8 = nullptr;
  this->m_pName = v8;
  CDmeTrackGroup::SetMaxTrackCount(this, color: (Color)-2139062144);
  this->m_ZeroColor = (Color)-14606047;
  this->m_TextColor = (Color)-3618616;
  this->m_TextColorFocus = (Color)-14118960;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1048CF30
// Name: protected: virtual void CPresetSideFilterSlider::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPresetSideFilterSlider::OnMousePressed(
        CPresetSideFilterSlider *this@<ecx>,
        int a2@<ebx>,
        ButtonCode_t code)
{
  if ( code == MOUSE_RIGHT )
    this->SetValue(this, a2: 500, a3: false);
  else
    vgui::Slider::OnMousePressed(this, a2, code);
}

//------------------------------------------------------------------------------
// Address: 0x1048CF60
// Name: protected: virtual void CPresetSideFilterSlider::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSideFilterSlider::OnMouseDoublePressed(CPresetSideFilterSlider *this, ButtonCode_t code)
{
  if ( code == KEY_COUNT )
    this->SetValue(this, a2: 500, a3: false);
  else
    vgui::ScrollBarSlider::OnMouseDoublePressed((vgui::ToggleButton *)this, code);
}

//------------------------------------------------------------------------------
// Address: 0x1048CF90
// Name: protected: virtual void CPresetSideFilterSlider::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSideFilterSlider::ApplySchemeSettings(CPresetSideFilterSlider *this, vgui::IScheme *scheme)
{
  vgui::TextImage_vtbl *v3; // ebx
  unsigned int v4; // eax

  vgui::Slider::ApplySchemeSettings(this, pScheme: scheme);
  v3 = this->m_pName->__vftable;
  v4 = scheme->GetFont(this: scheme, a2: "DefaultBold", a3: false);
  v3->SetFont(this: this->m_pName, a2: v4);
  ((void (__thiscall *)(vgui::TextImage *, _DWORD))this->m_pName->SetColor)(
    a1: this->m_pName,
    a2: *(_DWORD *)&this->m_TextColor);
  vgui::TextImage::ResizeImageToContent(this: this->m_pName);
  ((void (__thiscall *)(CPresetSideFilterSlider *, int))this->SetFgColor)(a1: this, a2: -16746302);
  this->SetThumbWidth(this, a2: 3);
}

//------------------------------------------------------------------------------
// Address: 0x1048D020
// Name: public: virtual void CBaseAnimSetAttributeSliderPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetAttributeSliderPanel::ApplySchemeSettings(
        CBaseAnimSetAttributeSliderPanel *this,
        vgui::IScheme *scheme)
{
  vgui::Panel *v3; // eax

  vgui::Panel::ApplySchemeSettings(this, pScheme: (int)scheme);
  v3 = vgui::PHandle::Get(this: &this->m_Sliders);
  ((void (__thiscall *)(vgui::Panel *, int))v3->SetBgColor)(a1: v3, a2: -14013910);
}

//------------------------------------------------------------------------------
// Address: 0x1048D060
// Name: public: virtual void CBaseAnimSetAttributeSliderPanel::GetTypeInValueForControl(class CDmElement __near *,bool,struct AttributeValue_t __near &,struct AttributeValue_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetAttributeSliderPanel::GetTypeInValueForControl(
        CBaseAnimSetAttributeSliderPanel *this,
        CDmElement *pControl,
        bool bOrientation,
        AttributeValue_t *controlValue,
        const AttributeValue_t *sliderValue)
{
  QAngle ang; // [esp+0h] [ebp-Ch] BYREF

  if ( pControl != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pControl->IsA)(
         a1: pControl,
         a2: (CUtlSymbolLarge)CDmeTransformControl::m_classType.u.m_Id)
    && bOrientation )
  {
    QuaternionAngles(q: &sliderValue->m_Quaternion, angles: &ang);
    controlValue->m_Vector = (Vector)ang;
  }
  else
  {
    *controlValue = *sliderValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1048D110
// Name: public: virtual void CBaseAnimSetAttributeSliderPanel::OnControlSelectionChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetAttributeSliderPanel::OnControlSelectionChanged(CBaseAnimSetAttributeSliderPanel *this)
{
  CBaseAnimSetAttributeSliderPanel *v1; // edi
  CAttributeSlider *v2; // esi
  CDmElement *v3; // eax
  TransformComponent_t SelectionComponentFlags; // eax
  int v5; // edi
  bool v6; // zf
  LogComponents_t v7; // edi
  vgui::PanelListPanel *v8; // eax
  int j; // edi
  int v10; // esi
  vgui::Panel *v11; // eax
  bool bShowSlider; // [esp+4h] [ebp-14h]
  int c; // [esp+8h] [ebp-10h]
  int i; // [esp+10h] [ebp-8h]
  bool visibleSlidersChanged; // [esp+17h] [ebp-1h]

  v1 = this;
  visibleSlidersChanged = false;
  c = *(_DWORD *)&this->m_InternalMouseDoublePressed_register;
  i = 0;
  if ( c > 0 )
  {
    while ( 1 )
    {
      v2 = *(CAttributeSlider **)(*(_DWORD *)&v1->m_OnNavigateFrom_register + 4 * i);
      v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: v2->m_hControl.m_handle);
      SelectionComponentFlags = CBaseAnimationSetControl::GetSelectionComponentFlags(
                                  this: *(CBaseAnimationSetControl **)&v1->m_clrDropFrame,
                                  pControl: v3);
      if ( (*((_BYTE *)v2 + 656) & 2) != 0 )
      {
        v5 = ((SelectionComponentFlags & 0x10) == 0 ? 0 : 2) | ((SelectionComponentFlags & 0x20) == 0 ? 0 : 4);
        v6 = (SelectionComponentFlags & 8) == 0;
      }
      else
      {
        v5 = ((SelectionComponentFlags & 2) == 0 ? 0 : 2) | ((SelectionComponentFlags & 4) == 0 ? 0 : 4);
        v6 = (SelectionComponentFlags & 1) == 0;
      }
      v7 = !v6 | v5;
      bShowSlider = SelectionComponentFlags != TRANSFORM_COMPONENT_NONE;
      if ( v2->IsVisible(this: v2) != (SelectionComponentFlags != TRANSFORM_COMPONENT_NONE) )
      {
        v2->SetVisible(this: v2, a2: bShowSlider);
        visibleSlidersChanged = true;
      }
      if ( CAttributeSlider::VisibleComponents(this: v2) != v7 )
        CAttributeSlider::SetVisibleComponents(this: v2, componentFlags: v7);
      if ( ++i >= c )
        break;
      v1 = this;
    }
    if ( visibleSlidersChanged )
    {
      v8 = (vgui::PanelListPanel *)vgui::PHandle::Get(this: (vgui::PHandle *)&this->m_OnDelete_register);
      vgui::PanelListPanel::RemoveAll(this: v8);
      for ( j = 0; j < c; ++j )
      {
        v10 = *(_DWORD *)(*(_DWORD *)&this->m_OnNavigateFrom_register + 4 * j);
        if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v10 + 136))(a1: v10) != 0 )
        {
          v11 = vgui::PHandle::Get(this: (vgui::PHandle *)&this->m_OnDelete_register);
          ((void (__thiscall *)(vgui::Panel *, _DWORD, int))v11->__vftable[1].GetVPanel)(a1: v11, a2: 0, a3: v10);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1048D260
// Name: protected: void CBaseAnimSetAttributeSliderPanel::UpdateSliderDependencyFlags(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetAttributeSliderPanel::UpdateSliderDependencyFlags(CBaseAnimSetAttributeSliderPanel *this)
{
  CAttributeSlider *v2; // eax
  int m_Size; // edx
  int v4; // edi
  CAttributeSlider **m_pMemory; // ecx
  CAttributeSlider *v6; // esi
  bool v7; // al
  int nSliders; // [esp+8h] [ebp-8h]
  CAttributeSlider *pPrimarySlider; // [esp+Ch] [ebp-4h]

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL) )
  {
    v2 = (CAttributeSlider *)vgui::PHandle::Get(this: &this->m_pController->m_ActiveAttributeSlider);
    pPrimarySlider = v2;
  }
  else
  {
    pPrimarySlider = nullptr;
    v2 = nullptr;
  }
  m_Size = this->m_SliderList.m_Size;
  v4 = 0;
  for ( nSliders = m_Size; v4 < m_Size; ++v4 )
  {
    m_pMemory = this->m_SliderList.m_Memory.m_pMemory;
    v6 = m_pMemory[v4];
    if ( v6 != nullptr )
    {
      v7 = v2 != nullptr && CAttributeSlider::IsDependent(this: v2, pSlider: m_pMemory[v4]);
      CAttributeSlider::SetDependent(this: v6, dependent: v7);
      v2 = pPrimarySlider;
      m_Size = nSliders;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1048D300
// Name: protected: int CBaseAnimSetAttributeSliderPanel::FindSliderIndexForControl(class CDmElement const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimSetAttributeSliderPanel::FindSliderIndexForControl(
        CBaseAnimSetAttributeSliderPanel *this,
        const CDmElement *control)
{
  int m_Size; // ebx
  int v4; // esi

  m_Size = this->m_SliderList.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return -1;
  while ( g_pDataModel->GetElement(
            this: g_pDataModel,
            a2: this->m_SliderList.m_Memory.m_pMemory[v4]->m_hControl.m_handle) != control )
  {
    if ( ++v4 >= m_Size )
      return -1;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1048D360
// Name: public: bool CBaseAnimSetAttributeSliderPanel::GetSliderValues(struct AttributeValue_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAnimSetAttributeSliderPanel::GetSliderValues(
        CBaseAnimSetAttributeSliderPanel *this,
        AttributeValue_t *pValue,
        int nIndex)
{
  CAttributeSlider *v4; // esi
  vgui::Panel *v5; // ebx
  bool v6; // al
  CBaseAnimationSetControl *m_pController; // ecx
  AttributeValue_t *Preview; // eax

  v4 = this->m_SliderList.m_Memory.m_pMemory[nIndex];
  v5 = vgui::PHandle::Get(this: &this->m_pController->m_ActiveAttributeSlider);
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
    || (v6 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT)) )
  {
    v6 = true;
  }
  if ( v5 == v4 && v6
    || (*((_BYTE *)(m_pController = this->m_pController) + 104) & 2) != 0
    || CBaseAnimationSetControl::IsPresetFaderBeingDragged(this: m_pController) )
  {
    Preview = (AttributeValue_t *)CAttributeSlider::GetPreview(this: v4);
  }
  else
  {
    Preview = (AttributeValue_t *)CAttributeSlider::GetValue(this: v4);
  }
  *pValue = *Preview;
  return v4->IsVisible(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1048D430
// Name: protected: virtual void CBaseAnimSetAttributeSliderPanel::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseAnimSetAttributeSliderPanel::OnThink(CBaseAnimSetAttributeSliderPanel *this@<ecx>, int a2@<ebx>)
{
  vgui::Panel::OnThink(this, a2, a3: (int)this);
  CBaseAnimationSetControl::UpdatePreviewSliderValues(this: this->m_pController);
  CBaseAnimationSetControl::UpdatePreviewSliderTimes(this: this->m_pController);
  this->ApplySliderValues(this, a2: false);
  CBaseAnimSetAttributeSliderPanel::UpdateSliderDependencyFlags(this);
}

//------------------------------------------------------------------------------
// Address: 0x1048D470
// Name: protected: class CAttributeSlider __near * CBaseAnimSetAttributeSliderPanel::AllocateSlider(void)
// Source: json
//------------------------------------------------------------------------------
CAttributeSlider *__thiscall CBaseAnimSetAttributeSliderPanel::AllocateSlider(CBaseAnimSetAttributeSliderPanel *this)
{
  int m_Size; // eax
  CAttributeSlider *v3; // edi
  CAttributeSlider *v5; // eax
  CAttributeSlider *v6; // esi

  m_Size = this->m_FreeSliderList.m_Size;
  if ( m_Size <= 0 )
  {
    v5 = (CAttributeSlider *)operator new(nSize: 0x2ACu);
    if ( v5 != nullptr )
    {
      v6 = CAttributeSlider::CAttributeSlider(this: v5, parent: this);
      v6->SetVisible(this: v6, a2: true);
      return v6;
    }
    else
    {
      (*(void (__thiscall **)(_DWORD, int))(MEMORY[0] + 132))(a1: 0, a2: 1);
      return nullptr;
    }
  }
  else
  {
    v3 = this->m_FreeSliderList.m_Memory.m_pMemory[m_Size - 1];
    --this->m_FreeSliderList.m_Size;
    v3->SetVisible(this: v3, a2: true);
    return v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1048D510
// Name: protected: void CBaseAnimSetAttributeSliderPanel::InitFreeSliderList(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetAttributeSliderPanel::InitFreeSliderList(
        CBaseAnimSetAttributeSliderPanel *this,
        int nCount)
{
  CBaseAnimSetAttributeSliderPanel *v2; // edi
  CUtlMemory<vgui::TreeNode *,int> *p_m_FreeSliderList; // esi
  CAttributeSlider *v4; // eax
  CAttributeSlider *v5; // ebx
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  CAttributeSlider **v10; // eax

  v2 = this;
  if ( nCount > 0 )
  {
    p_m_FreeSliderList = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_FreeSliderList;
    while ( 1 )
    {
      v4 = (CAttributeSlider *)operator new(nSize: 0x2ACu);
      if ( v4 != nullptr )
        v5 = CAttributeSlider::CAttributeSlider(this: v4, parent: v2);
      else
        v5 = nullptr;
      v5->SetVisible(this: v5, a2: false);
      m_pMemory = p_m_FreeSliderList[1].m_pMemory;
      m_nAllocationCount = p_m_FreeSliderList->m_nAllocationCount;
      if ( (int)m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_FreeSliderList, num: (int)m_pMemory - m_nAllocationCount + 1);
      ++p_m_FreeSliderList[1].m_pMemory;
      v8 = p_m_FreeSliderList->m_pMemory;
      v9 = (char *)p_m_FreeSliderList[1].m_pMemory - (char *)m_pMemory - 1;
      p_m_FreeSliderList[1].m_nAllocationCount = (int)p_m_FreeSliderList->m_pMemory;
      if ( v9 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&v8[(_DWORD)m_pMemory + 1],
          src: (unsigned __int8 *)&v8[(_DWORD)m_pMemory],
          count: 4 * v9);
      v10 = (CAttributeSlider **)&p_m_FreeSliderList->m_pMemory[(_DWORD)m_pMemory];
      if ( v10 != nullptr )
        *v10 = v5;
      if ( --nCount == 0 )
        break;
      v2 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1048D5C0
// Name: public: CBaseAnimSetAttributeSliderPanel::CBaseAnimSetAttributeSliderPanel(class vgui::Panel __near *,char const __near *,class CBaseAnimationSetEditor __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseAnimSetAttributeSliderPanel *__thiscall CBaseAnimSetAttributeSliderPanel::CBaseAnimSetAttributeSliderPanel(
        CBaseAnimSetAttributeSliderPanel *this,
        vgui::Panel *parent,
        const char *className,
        CBaseAnimationSetEditor *editor)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Button *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  CPresetSideFilterSlider *v12; // eax
  CPresetSideFilterSlider *v13; // eax
  vgui::PanelListPanel *v14; // eax
  CDragDropHelperPanel *v15; // eax
  vgui::PanelListPanel *v16; // eax
  vgui::Panel *v17; // eax
  vgui::PanelListPanel *v18; // eax
  CBaseAnimationSetControl *Controller; // eax

  vgui::EditablePanel::EditablePanel(this, parent, panelName: className);
  this->IAnimationSetControlSelectionChangedListener::__vftable = (IAnimationSetControlSelectionChangedListener_vtbl *)&IAnimationSetControlSelectionChangedListener::`vftable';
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CBaseAnimSetAttributeSliderPanel_vtbl *)&CBaseAnimSetAttributeSliderPanel::`vftable'{for `vgui::EditablePanel'};
  this->IAnimationSetControlSelectionChangedListener::__vftable = (IAnimationSetControlSelectionChangedListener_vtbl *)&CBaseAnimSetAttributeSliderPanel::`vftable'{for `IAnimationSetControlSelectionChangedListener'};
  if ( `CBaseAnimSetAttributeSliderPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAnimSetAttributeSliderPanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetAttributeSliderPanel");
    v5->pfnClassName = CBaseAnimSetAttributeSliderPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CBaseAnimSetAttributeSliderPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseAnimSetAttributeSliderPanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CBaseAnimSetAttributeSliderPanel");
    v6->pfnClassName = CBaseAnimSetAttributeSliderPanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CBaseAnimSetAttributeSliderPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAnimSetAttributeSliderPanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAnimSetAttributeSliderPanel");
    v7->pfnClassName = CBaseAnimSetAttributeSliderPanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  this->m_hEditor.m_iPanelID = -1;
  this->m_Sliders.m_iPanelID = -1;
  this->m_SliderList.m_Memory.m_pMemory = nullptr;
  this->m_SliderList.m_Memory.m_nAllocationCount = 0;
  this->m_SliderList.m_Memory.m_nGrowSize = 0;
  this->m_SliderList.m_Size = 0;
  this->m_SliderList.m_pElements = nullptr;
  this->m_pController = nullptr;
  this->m_FreeSliderList.m_Memory.m_pMemory = nullptr;
  this->m_FreeSliderList.m_Memory.m_nAllocationCount = 0;
  this->m_FreeSliderList.m_Memory.m_nGrowSize = 0;
  this->m_FreeSliderList.m_Size = 0;
  this->m_FreeSliderList.m_pElements = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_hEditor,
    pPanel: (CDragDropHelperPanel *)editor);
  v8 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v8 != nullptr )
    v9 = vgui::Button::Button(
           this: v8,
           parent: this,
           panelName: "AttributeSliderLeftOnly",
           text: &var,
           pActionSignalTarget: this,
           pCmd: "OnLeftOnly");
  else
    v9 = nullptr;
  this->m_pLeftRightBoth[0] = v9;
  v10 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v10 != nullptr )
    v11 = vgui::Button::Button(
            this: v10,
            parent: this,
            panelName: "AttributeSliderRightOnly",
            text: &var,
            pActionSignalTarget: this,
            pCmd: "OnRightOnly");
  else
    v11 = nullptr;
  this->m_pLeftRightBoth[1] = v11;
  v12 = (CPresetSideFilterSlider *)operator new(nSize: 0x1C4u);
  if ( v12 != nullptr )
    v13 = CPresetSideFilterSlider::CPresetSideFilterSlider(this: v12, parent: this, panelName: "PresetSideFilter");
  else
    v13 = nullptr;
  this->m_pPresetSideFilter = v13;
  v14 = (vgui::PanelListPanel *)operator new(nSize: 0x1ACu);
  if ( v14 != nullptr )
    v15 = (CDragDropHelperPanel *)vgui::PanelListPanel::PanelListPanel(
                                    this: v14,
                                    parent: this,
                                    panelName: "AttributeSliders");
  else
    v15 = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(
    this: (vgui::DHANDLE<CDragDropHelperPanel> *)&this->m_Sliders,
    pPanel: v15);
  v16 = (vgui::PanelListPanel *)vgui::PHandle::Get(this: &this->m_Sliders);
  vgui::PanelListPanel::SetFirstColumnWidth(this: v16, width: 0);
  v17 = vgui::PHandle::Get(this: &this->m_Sliders);
  vgui::Panel::SetAutoResize(
    this: v17,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 32,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  v18 = (vgui::PanelListPanel *)vgui::PHandle::Get(this: &this->m_Sliders);
  vgui::PanelListPanel::SetVerticalBufferPixels(this: v18, buffer: 0);
  Controller = CBaseAnimationSetEditor::GetController(this: editor);
  this->m_pController = Controller;
  CBaseAnimationSetControl::AddControlSelectionChangedListener(
    this: Controller,
    listener: &this->IAnimationSetControlSelectionChangedListener);
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  CBaseAnimSetAttributeSliderPanel::InitFreeSliderList(this, nCount: 1500);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1048D830
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseAnimSetAttributeSliderPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseAnimSetAttributeSliderPanel::GetMessageMap(
        CBaseAnimSetAttributeSliderPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseAnimSetAttributeSliderPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAnimSetAttributeSliderPanel::GetMessageMap'::`2'::s_pMap;
  `CBaseAnimSetAttributeSliderPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetAttributeSliderPanel");
  `CBaseAnimSetAttributeSliderPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1048D860
// Name: public: virtual struct PanelAnimationMap __near * CBaseAnimSetAttributeSliderPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseAnimSetAttributeSliderPanel::GetAnimMap(CBaseAnimSetAttributeSliderPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseAnimSetAttributeSliderPanel");
}

//------------------------------------------------------------------------------
// Address: 0x1048D870
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseAnimSetAttributeSliderPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseAnimSetAttributeSliderPanel::GetKBMap(CBaseAnimSetAttributeSliderPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseAnimSetAttributeSliderPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAnimSetAttributeSliderPanel::GetKBMap'::`2'::s_pMap;
  `CBaseAnimSetAttributeSliderPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAnimSetAttributeSliderPanel");
  `CBaseAnimSetAttributeSliderPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1048D8E0
// Name: protected: void CBaseAnimSetAttributeSliderPanel::RebuildSliderLists(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetAttributeSliderPanel::RebuildSliderLists(CBaseAnimSetAttributeSliderPanel *this)
{
  CBaseAnimSetAttributeSliderPanel *v1; // ebx
  CDmElement *m_Size; // eax
  void (__thiscall *SetVisible)(vgui::Panel *, bool); // eax
  int v4; // edi
  int m_nAllocationCount; // eax
  CAttributeSlider **m_pMemory; // ecx
  int v7; // eax
  int *v8; // edi
  CUtlMemory<vgui::TreeNode *,int> *p_m_SliderList; // esi
  vgui::PanelListPanel *v10; // eax
  CBaseAnimationSetControl *m_pController; // ecx
  CDmeTransform *j; // eax
  CDmElement *Position; // eax
  int v14; // edx
  int v15; // ecx
  CDmElement *v16; // eax
  CDmElement *v17; // ebx
  int v18; // edi
  int v19; // eax
  CDmElement **v20; // ecx
  int v21; // eax
  CDmElement **v22; // edi
  CDmElement *v23; // edi
  CAttributeSlider *Slider; // ebx
  vgui::TreeNode **v25; // edi
  int v26; // eax
  vgui::TreeNode **v27; // ecx
  int v28; // eax
  CAttributeSlider **v29; // edi
  CDmElement *v30; // edi
  CAttributeSlider *v31; // ebx
  vgui::TreeNode **v32; // edi
  int v33; // eax
  vgui::TreeNode **v34; // ecx
  int v35; // eax
  CAttributeSlider **v36; // edi
  CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > controlList; // [esp+Ch] [ebp-2Ch] BYREF
  CAnimSetGroupAnimSetTraversal traversal; // [esp+20h] [ebp-18h] BYREF
  CDmElement *control; // [esp+28h] [ebp-10h]
  int controlCount; // [esp+2Ch] [ebp-Ch]
  CBaseAnimSetAttributeSliderPanel *v41; // [esp+30h] [ebp-8h]
  int i; // [esp+34h] [ebp-4h]

  v1 = this;
  m_Size = (CDmElement *)this->m_SliderList.m_Size;
  v41 = this;
  control = m_Size;
  for ( i = 0; i < (int)control; ++i )
  {
    SetVisible = v1->m_SliderList.m_Memory.m_pMemory[i]->SetVisible;
    controlCount = (int)v1->m_SliderList.m_Memory.m_pMemory[i];
    ((void (__stdcall *)(_DWORD))SetVisible)(a1: 0);
    v4 = v1->m_FreeSliderList.m_Size;
    m_nAllocationCount = v1->m_FreeSliderList.m_Memory.m_nAllocationCount;
    if ( v4 + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&v1->m_FreeSliderList,
        num: v4 - m_nAllocationCount + 1);
    ++v1->m_FreeSliderList.m_Size;
    m_pMemory = v1->m_FreeSliderList.m_Memory.m_pMemory;
    v7 = v1->m_FreeSliderList.m_Size - v4 - 1;
    v1->m_FreeSliderList.m_pElements = m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&m_pMemory[v4 + 1], src: (unsigned __int8 *)&m_pMemory[v4], count: 4 * v7);
    v8 = (int *)&v1->m_FreeSliderList.m_Memory.m_pMemory[v4];
    if ( v8 != nullptr )
      *v8 = controlCount;
  }
  p_m_SliderList = (CUtlMemory<vgui::TreeNode *,int> *)&v1->m_SliderList;
  v1->m_SliderList.m_Size = 0;
  v10 = (vgui::PanelListPanel *)vgui::PHandle::Get(this: &v1->m_Sliders);
  vgui::PanelListPanel::RemoveAll(this: v10);
  m_pController = v1->m_pController;
  memset(&controlList, 0, sizeof(controlList));
  traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: m_pController);
  traversal.m_nIndex = 0;
  for ( j = (CDmeTransform *)CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
        j != nullptr;
        j = (CDmeTransform *)CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
  {
    Position = (CDmElement *)CDmeTransform::GetPosition(this: j);
    v14 = *(_DWORD *)&Position->m_Id.m_Value[8];
    v15 = 0;
    control = Position;
    controlCount = v14;
    i = 0;
    if ( v14 > 0 )
    {
      while ( 1 )
      {
        v16 = g_pDataModel->GetElement(this: g_pDataModel, a2: *((_DWORD *)&Position->OnAttributeChanged + v15));
        v17 = v16;
        if ( v16 != nullptr && v16->IsA(this: v16, a2: CDmElement::m_classType) )
        {
          v18 = controlList.m_Size;
          v19 = controlList.m_Size;
          if ( controlList.m_Size + 1 > controlList.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&controlList,
              num: controlList.m_Size - controlList.m_Memory.m_nAllocationCount + 1);
            v19 = controlList.m_Size;
          }
          v20 = controlList.m_Memory.m_pMemory;
          controlList.m_Size = v19 + 1;
          v21 = v19 - v18;
          controlList.m_pElements = controlList.m_Memory.m_pMemory;
          if ( v21 > 0 )
          {
            _V_memmove(
              dest: (unsigned __int8 *)&controlList.m_Memory.m_pMemory[v18 + 1],
              src: (unsigned __int8 *)&controlList.m_Memory.m_pMemory[v18],
              count: 4 * v21);
            v20 = controlList.m_Memory.m_pMemory;
          }
          v22 = &v20[v18];
          if ( v22 != nullptr )
            *v22 = v17;
        }
        v15 = i + 1;
        i = v15;
        if ( v15 >= controlCount )
          break;
        Position = control;
      }
      v1 = v41;
    }
  }
  i = 0;
  if ( controlList.m_Size > 0 )
  {
    while ( 1 )
    {
      control = controlList.m_Memory.m_pMemory[i];
      v23 = control;
      Slider = CBaseAnimSetAttributeSliderPanel::AllocateSlider(this: v1);
      CAttributeSlider::Init(this: Slider, control: v23, bOrientation: false);
      Slider->SetVisible(this: Slider, a2: false);
      v25 = p_m_SliderList[1].m_pMemory;
      v26 = p_m_SliderList->m_nAllocationCount;
      if ( (int)v25 + 1 > v26 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_SliderList, num: (int)v25 - v26 + 1);
      ++p_m_SliderList[1].m_pMemory;
      v27 = p_m_SliderList->m_pMemory;
      v28 = (char *)p_m_SliderList[1].m_pMemory - (char *)v25 - 1;
      p_m_SliderList[1].m_nAllocationCount = (int)p_m_SliderList->m_pMemory;
      if ( v28 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&v27[(_DWORD)v25 + 1],
          src: (unsigned __int8 *)&v27[(_DWORD)v25],
          count: 4 * v28);
      v29 = (CAttributeSlider **)&p_m_SliderList->m_pMemory[(_DWORD)v25];
      if ( v29 != nullptr )
        *v29 = Slider;
      v30 = control;
      if ( control != nullptr
        && ((int (__thiscall *)(_DWORD, _DWORD))control->IsA)(
             a1: control,
             a2: (CUtlSymbolLarge)CDmeTransformControl::m_classType.u.m_Id) )
      {
        v31 = CBaseAnimSetAttributeSliderPanel::AllocateSlider(this: v41);
        CAttributeSlider::Init(this: v31, control: v30, bOrientation: true);
        v31->SetVisible(this: v31, a2: false);
        v32 = p_m_SliderList[1].m_pMemory;
        v33 = p_m_SliderList->m_nAllocationCount;
        if ( (int)v32 + 1 > v33 )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_SliderList, num: (int)v32 - v33 + 1);
        ++p_m_SliderList[1].m_pMemory;
        v34 = p_m_SliderList->m_pMemory;
        v35 = (char *)p_m_SliderList[1].m_pMemory - (char *)v32 - 1;
        p_m_SliderList[1].m_nAllocationCount = (int)p_m_SliderList->m_pMemory;
        if ( v35 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&v34[(_DWORD)v32 + 1],
            src: (unsigned __int8 *)&v34[(_DWORD)v32],
            count: 4 * v35);
        v36 = (CAttributeSlider **)&p_m_SliderList->m_pMemory[(_DWORD)v32];
        if ( v36 != nullptr )
          *v36 = v31;
      }
      if ( ++i >= controlList.m_Size )
        break;
      v1 = v41;
    }
  }
  if ( controlList.m_Memory.m_nGrowSize >= 0 && controlList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: controlList.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1048DC10
// Name: public: virtual void CBaseAnimSetAttributeSliderPanel::OnControlsAddedOrRemoved(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetAttributeSliderPanel::OnControlsAddedOrRemoved(CBaseAnimSetAttributeSliderPanel *this)
{
  CBaseAnimSetAttributeSliderPanel *v1; // ebx
  CBaseAnimationSetControl *m_pController; // ecx
  int v3; // edi
  CDmeTransform *v4; // eax
  const CDmaElementArray<CDmElement> *Position; // eax
  int m_Size; // edx
  int v7; // ecx
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  CAttributeSlider *v10; // ebx
  bool v11; // zf
  bool v12; // bl
  DmElementHandle_t m_handle; // [esp-4h] [ebp-2Ch]
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-1Ch] BYREF
  int controlCount; // [esp+14h] [ebp-14h]
  const CDmaElementArray<CDmElement> *controls; // [esp+18h] [ebp-10h]
  int i; // [esp+1Ch] [ebp-Ch]
  CBaseAnimSetAttributeSliderPanel *v18; // [esp+20h] [ebp-8h]
  bool changed; // [esp+27h] [ebp-1h]

  v1 = this;
  m_pController = this->m_pController;
  v18 = v1;
  changed = false;
  v3 = 0;
  traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: m_pController);
  traversal.m_nIndex = 0;
  v4 = (CDmeTransform *)CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  if ( v4 != nullptr )
  {
    do
    {
      Position = (const CDmaElementArray<CDmElement> *)CDmeTransform::GetPosition(this: v4);
      m_Size = Position->m_Storage.m_Size;
      v7 = 0;
      controls = Position;
      controlCount = m_Size;
      i = 0;
      if ( m_Size > 0 )
      {
        while ( 1 )
        {
          v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: Position->m_Storage.m_Memory.m_pMemory[v7]);
          v9 = v8;
          if ( v8 != nullptr && v8->IsA(this: v8, a2: CDmElement::m_classType) )
          {
            if ( v3 >= v1->m_SliderList.m_Size )
              break;
            v10 = v1->m_SliderList.m_Memory.m_pMemory[v3++];
            if ( g_pDataModel->GetElement(this: g_pDataModel, a2: v10->m_hControl.m_handle) != v9 )
              break;
            if ( v9->IsA(this: v9, a2: CDmeTransformControl::m_classType) )
            {
              m_handle = v18->m_SliderList.m_Memory.m_pMemory[v3++]->m_hControl.m_handle;
              v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_handle) == v9;
            }
            else
            {
              v12 = (*((_BYTE *)v10 + 656) & 4) != 0;
              v11 = v12 == CDmElement::HasAttribute(this: v9, pAttributeName: "rightValue", type: AT_UNKNOWN);
            }
            if ( !v11 )
              break;
          }
          v7 = i + 1;
          i = v7;
          if ( v7 >= controlCount )
            goto LABEL_16;
          v1 = v18;
          Position = controls;
        }
        changed = true;
      }
LABEL_16:
      v4 = (CDmeTransform *)CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
      v1 = v18;
    }
    while ( v4 != nullptr );
    if ( changed )
      goto LABEL_19;
  }
  if ( v3 != v1->m_SliderList.m_Size )
LABEL_19:
    CBaseAnimSetAttributeSliderPanel::RebuildSliderLists(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1048DD70
// Name: public: virtual void CBaseAnimSetAttributeSliderPanel::ChangeAnimationSetClip(class CDmeFilmClip __near *)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CBaseAnimSetAttributeSliderPanel::ChangeAnimationSetClip(
        CBaseAnimSetAttributeSliderPanel *this,
        CDmeFilmClip *pFilmClip)
{
  CBaseAnimSetAttributeSliderPanel::RebuildSliderLists(this);
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00482D90
// Name: public: static char const __near * CBaseAnimSetAttributeSliderPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBaseAnimSetAttributeSliderPanel::GetPanelClassName()
{
  return "CBaseAnimSetAttributeSliderPanel";
}

//------------------------------------------------------------------------------
// Address: 0x00482DA0
// Name: public: static char const __near * CPresetSideFilterSlider::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPresetSideFilterSlider::GetPanelClassName()
{
  return "CPresetSideFilterSlider";
}

//------------------------------------------------------------------------------
// Address: 0x00482DB0
// Name: protected: virtual void CPresetSideFilterSlider::GetTrackRect(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSideFilterSlider::GetTrackRect(CPresetSideFilterSlider *this, int *x, int *y, int *w, int *h)
{
  vgui::Panel::GetSize(this, wide: w, tall: h);
  *x = 0;
  *y = 2;
  *h -= 4;
}

//------------------------------------------------------------------------------
// Address: 0x00482DE0
// Name: protected: virtual void CPresetSideFilterSlider::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSideFilterSlider::Paint(CPresetSideFilterSlider *this)
{
  vgui::ISurface *v2; // edi
  vgui::ISurface_vtbl *v3; // ebx
  int v4; // eax
  int x; // [esp+Ch] [ebp-14h] BYREF
  int wide; // [esp+10h] [ebp-10h] BYREF
  int tall; // [esp+14h] [ebp-Ch] BYREF
  int y; // [esp+18h] [ebp-8h] BYREF
  Color col; // [esp+1Ch] [ebp-4h] BYREF

  this->GetTrackRect(this, a2: &x, a3: &y, a4: &wide, a5: &tall);
  this->GetFgColor(this, result: &col);
  ((void (__thiscall *)(_DWORD, _DWORD))g_pVGuiSurface->DrawSetColor)(a1: g_pVGuiSurface, a2: col);
  v2 = g_pVGuiSurface;
  v3 = g_pVGuiSurface->__vftable;
  v4 = vgui::Panel::GetTall(this);
  v3->DrawFilledRect(this: v2, a2: this->_nobPos[0], a3: 1, a4: this->_nobPos[1], a5: v4 - 1);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_ZeroColor);
  g_pVGuiSurface->DrawFilledRect(
    this: g_pVGuiSurface,
    a2: this->_nobPos[0] - 1,
    a3: y + 1,
    a4: this->_nobPos[0],
    a5: y + tall - 1);
}

//------------------------------------------------------------------------------
// Address: 0x00482E90
// Name: protected: virtual void CPresetSideFilterSlider::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSideFilterSlider::PaintBackground(CPresetSideFilterSlider *this)
{
  Color m_TextColorFocus; // eax
  int cw; // [esp+Ch] [ebp-20h] BYREF
  int w; // [esp+10h] [ebp-1Ch] BYREF
  int v5; // [esp+14h] [ebp-18h] BYREF
  int h; // [esp+18h] [ebp-14h] BYREF
  int tw; // [esp+1Ch] [ebp-10h] BYREF
  int tx; // [esp+20h] [ebp-Ch] BYREF
  int th; // [esp+24h] [ebp-8h] BYREF
  int ty; // [esp+28h] [ebp-4h] BYREF

  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  this->GetTrackRect(this, a2: &tx, a3: &ty, a4: &tw, a5: &th);
  ((void (__thiscall *)(vgui::ISurface *, _DWORD))g_pVGuiSurface->DrawSetColor)(
    a1: g_pVGuiSurface,
    a2: *(_DWORD *)&this->m_ZeroColor);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: tx, a3: ty, a4: tx + tw, a5: ty + th);
  if ( this->_dragging )
    m_TextColorFocus = this->m_TextColorFocus;
  else
    m_TextColorFocus = this->m_TextColor;
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pName->SetColor)(a1: this->m_pName, a2: m_TextColorFocus);
  this->m_pName->GetContentSize(this: this->m_pName, a2: &cw, a3: &v5);
  this->m_pName->SetPos(
    this: this->m_pName,
    a2: (int)(float)((float)(w - cw) * 0.5),
    a3: (int)(float)((float)(h - v5) * 0.5));
  this->m_pName->Paint(this: this->m_pName);
}

//------------------------------------------------------------------------------
// Address: 0x00482F90
// Name: protected: virtual void CBaseAnimSetAttributeSliderPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetAttributeSliderPanel::OnCommand(
        CBaseAnimSetAttributeSliderPanel *this,
        const char *pCommand)
{
  if ( _V_stricmp(s1: pCommand, s2: "OnLeftOnly") != 0 )
  {
    if ( _V_stricmp(s1: pCommand, s2: "OnRightOnly") != 0 )
      vgui::Panel::OnCommand(this, command: pCommand);
    else
      this->m_pPresetSideFilter->SetValue(this: this->m_pPresetSideFilter, a2: 1000, a3: false);
  }
  else
  {
    this->m_pPresetSideFilter->SetValue(this: this->m_pPresetSideFilter, a2: 0, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00483010
// Name: protected: virtual void CBaseAnimSetAttributeSliderPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetAttributeSliderPanel::PerformLayout(CBaseAnimSetAttributeSliderPanel *this)
{
  int h; // [esp+4h] [ebp-8h] BYREF
  int w; // [esp+8h] [ebp-4h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  vgui::Panel::SetBounds(this: this->m_pLeftRightBoth[0], x: 15, y: 11, wide: 9, tall: 9);
  vgui::Panel::SetBounds(this: this->m_pLeftRightBoth[1], x: w - 15, y: 11, wide: 9, tall: 9);
  vgui::Panel::SetBounds(this: this->m_pPresetSideFilter, x: 32, y: 4, wide: w - 56, tall: 24);
}

//------------------------------------------------------------------------------
// Address: 0x00483080
// Name: protected: virtual void CBaseAnimSetAttributeSliderPanel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetAttributeSliderPanel::OnTick(CBaseAnimSetAttributeSliderPanel *this)
{
  unsigned int v2; // esi

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  if ( !this->IsVisible(this) )
  {
LABEL_6:
    this->OnThink(this);
    return;
  }
  v2 = this->GetVParent(this);
  if ( v2 != 0 )
  {
    while ( g_pVGuiPanel->IsVisible(this: g_pVGuiPanel, a2: v2) )
    {
      v2 = g_pVGuiPanel->GetParent(this: g_pVGuiPanel, a2: v2);
      if ( v2 == 0 )
        return;
    }
    goto LABEL_6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004830F0
// Name: protected: virtual bool CBaseAnimSetAttributeSliderPanel::ApplySliderValues(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAnimSetAttributeSliderPanel::ApplySliderValues(
        CBaseAnimSetAttributeSliderPanel *this,
        BOOL bForce)
{
  bool v3; // bl

  v3 = CBaseAnimationSetControl::ApplySliderValues(this: this->m_pController, bForce);
  if ( v3 )
    this->UpdatePreview(this, a2: "ApplySliderValues\n");
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00483130
// Name: public: float CBaseAnimSetAttributeSliderPanel::GetBalanceSliderValue(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseAnimSetAttributeSliderPanel::GetBalanceSliderValue(CBaseAnimSetAttributeSliderPanel *this)
{
  return (double)((int (__thiscall *)(CPresetSideFilterSlider *, CBaseAnimSetAttributeSliderPanel *))this->m_pPresetSideFilter->GetValue)(
                   a1: this->m_pPresetSideFilter,
                   a2: this)
       * 0.001;
}

//------------------------------------------------------------------------------
// Address: 0x00483160
// Name: public: virtual struct vgui::PanelMessageMap __near * CPresetSideFilterSlider::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPresetSideFilterSlider::GetMessageMap(CPresetSideFilterSlider *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPresetSideFilterSlider::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPresetSideFilterSlider::GetMessageMap'::`2'::s_pMap;
  `CPresetSideFilterSlider::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPresetSideFilterSlider");
  `CPresetSideFilterSlider::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00483190
// Name: public: virtual struct PanelAnimationMap __near * CPresetSideFilterSlider::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPresetSideFilterSlider::GetAnimMap(CPresetSideFilterSlider *this)
{
  return FindOrAddPanelAnimationMap(className: "CPresetSideFilterSlider");
}

//------------------------------------------------------------------------------
// Address: 0x004831A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPresetSideFilterSlider::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPresetSideFilterSlider::GetKBMap(CPresetSideFilterSlider *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPresetSideFilterSlider::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPresetSideFilterSlider::GetKBMap'::`2'::s_pMap;
  `CPresetSideFilterSlider::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPresetSideFilterSlider");
  `CPresetSideFilterSlider::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004831D0
// Name: public: CPresetSideFilterSlider::CPresetSideFilterSlider(class CBaseAnimSetAttributeSliderPanel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CPresetSideFilterSlider *__thiscall CPresetSideFilterSlider::CPresetSideFilterSlider(
        CPresetSideFilterSlider *this,
        CBaseAnimSetAttributeSliderPanel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::TextImage *v7; // eax
  vgui::TextImage *v8; // eax

  vgui::Slider::Slider(this, parent, panelName);
  this->__vftable = (CPresetSideFilterSlider_vtbl *)&CPresetSideFilterSlider::`vftable';
  if ( `CPresetSideFilterSlider::ChainToMap'::`2'::chained == 0 )
  {
    `CPresetSideFilterSlider::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CPresetSideFilterSlider");
    v4->pfnClassName = CPresetSideFilterSlider::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Slider");
  }
  if ( `CPresetSideFilterSlider::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPresetSideFilterSlider::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CPresetSideFilterSlider");
    v5->pfnClassName = CPresetSideFilterSlider::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Slider");
  }
  if ( `CPresetSideFilterSlider::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPresetSideFilterSlider::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CPresetSideFilterSlider");
    v6->pfnClassName = CPresetSideFilterSlider::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Slider");
  }
  this->m_pParent = parent;
  this->m_ZeroColor = 0;
  this->m_TextColor = 0;
  this->m_TextColorFocus = 0;
  vgui::Slider::SetRange(this, min: 0, max: 1000);
  vgui::Slider::SetDragOnRepositionNob(this, state: true);
  this->SetValue(this, a2: 500, a3: false);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: true);
  v7 = (vgui::TextImage *)MemAlloc_Alloc(nSize: 0x80u);
  if ( v7 != nullptr )
    v8 = vgui::TextImage::TextImage(this: v7, text: "Preset Side Filter");
  else
    v8 = nullptr;
  this->m_pName = v8;
  CDmeTrackGroup::SetMaxTrackCount(this, color: (Color)-2139062144);
  this->m_ZeroColor = (Color)-14606047;
  this->m_TextColor = (Color)-3618616;
  this->m_TextColorFocus = (Color)-14118960;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00483380
// Name: protected: virtual void CPresetSideFilterSlider::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSideFilterSlider::OnMousePressed(CPresetSideFilterSlider *this, ButtonCode_t code)
{
  if ( code == MOUSE_RIGHT )
    this->SetValue(this, a2: 500, a3: false);
  else
    vgui::Slider::OnMousePressed(this, code);
}

//------------------------------------------------------------------------------
// Address: 0x004833B0
// Name: protected: virtual void CPresetSideFilterSlider::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSideFilterSlider::OnMouseDoublePressed(CPresetSideFilterSlider *this, ButtonCode_t code)
{
  if ( code == KEY_COUNT )
    this->SetValue(this, a2: 500, a3: false);
  else
    vgui::ScrollBarSlider::OnMouseDoublePressed((vgui::ToggleButton *)this, code);
}

//------------------------------------------------------------------------------
// Address: 0x004833E0
// Name: protected: virtual void CPresetSideFilterSlider::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPresetSideFilterSlider::ApplySchemeSettings(CPresetSideFilterSlider *this, vgui::IScheme *scheme)
{
  vgui::TextImage_vtbl *v3; // ebx
  unsigned int v4; // eax

  vgui::Slider::ApplySchemeSettings(this, pScheme: scheme);
  v3 = this->m_pName->__vftable;
  v4 = scheme->GetFont(this: scheme, a2: "DefaultBold", a3: false);
  v3->SetFont(this: this->m_pName, a2: v4);
  ((void (__thiscall *)(vgui::TextImage *, _DWORD))this->m_pName->SetColor)(
    a1: this->m_pName,
    a2: *(_DWORD *)&this->m_TextColor);
  vgui::TextImage::ResizeImageToContent(this: this->m_pName);
  ((void (__thiscall *)(CPresetSideFilterSlider *, int))this->SetFgColor)(a1: this, a2: -16746302);
  this->SetThumbWidth(this, a2: 3);
}

//------------------------------------------------------------------------------
// Address: 0x00483470
// Name: public: virtual void CBaseAnimSetAttributeSliderPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetAttributeSliderPanel::ApplySchemeSettings(
        CBaseAnimSetAttributeSliderPanel *this,
        vgui::IScheme *scheme)
{
  vgui::Panel *v3; // eax

  vgui::Panel::ApplySchemeSettings(this, pScheme: scheme);
  v3 = vgui::PHandle::Get(this: &this->m_Sliders);
  ((void (__thiscall *)(vgui::Panel *, int))v3->SetBgColor)(a1: v3, a2: -14013910);
}

//------------------------------------------------------------------------------
// Address: 0x004834B0
// Name: public: virtual void CBaseAnimSetAttributeSliderPanel::GetTypeInValueForControl(class CDmElement __near *,bool,struct AttributeValue_t __near &,struct AttributeValue_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetAttributeSliderPanel::GetTypeInValueForControl(
        CBaseAnimSetAttributeSliderPanel *this,
        CDmElement *pControl,
        bool bOrientation,
        AttributeValue_t *controlValue,
        const AttributeValue_t *sliderValue)
{
  QAngle ang; // [esp+0h] [ebp-Ch] BYREF

  if ( pControl != nullptr
    && ((int (__thiscall *)(_DWORD, _DWORD))pControl->IsA)(
         a1: pControl,
         a2: (CUtlSymbolLarge)CDmeTransformControl::m_classType.u.m_Id)
    && bOrientation )
  {
    QuaternionAngles(q: &sliderValue->m_Quaternion, angles: &ang);
    controlValue->m_Vector = (Vector)ang;
  }
  else
  {
    *controlValue = *sliderValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00483560
// Name: public: virtual void CBaseAnimSetAttributeSliderPanel::OnControlSelectionChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetAttributeSliderPanel::OnControlSelectionChanged(CBaseAnimSetAttributeSliderPanel *this)
{
  CBaseAnimSetAttributeSliderPanel *v1; // edi
  CAttributeSlider *v2; // esi
  CDmElement *v3; // eax
  TransformComponent_t SelectionComponentFlags; // eax
  int v5; // edi
  bool v6; // zf
  LogComponents_t v7; // edi
  vgui::PanelListPanel *v8; // eax
  int j; // edi
  int v10; // esi
  vgui::Panel *v11; // eax
  bool bShowSlider; // [esp+4h] [ebp-14h]
  int c; // [esp+8h] [ebp-10h]
  int i; // [esp+10h] [ebp-8h]
  bool visibleSlidersChanged; // [esp+17h] [ebp-1h]

  v1 = this;
  visibleSlidersChanged = false;
  c = *(_DWORD *)&this->m_InternalMouseDoublePressed_register;
  i = 0;
  if ( c > 0 )
  {
    while ( 1 )
    {
      v2 = *(CAttributeSlider **)(*(_DWORD *)&v1->m_OnNavigateFrom_register + 4 * i);
      v3 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                           a1: g_pDataModel.u,
                           a2: v2->m_hControl.m_handle);
      SelectionComponentFlags = CBaseAnimationSetControl::GetSelectionComponentFlags(
                                  this: *(CBaseAnimationSetControl **)&v1->m_clrDropFrame,
                                  pControl: v3);
      if ( (*((_BYTE *)v2 + 656) & 2) != 0 )
      {
        v5 = ((SelectionComponentFlags & 0x10) == 0 ? 0 : 2) | ((SelectionComponentFlags & 0x20) == 0 ? 0 : 4);
        v6 = (SelectionComponentFlags & 8) == 0;
      }
      else
      {
        v5 = ((SelectionComponentFlags & 2) == 0 ? 0 : 2) | ((SelectionComponentFlags & 4) == 0 ? 0 : 4);
        v6 = (SelectionComponentFlags & 1) == 0;
      }
      v7 = !v6 | v5;
      bShowSlider = SelectionComponentFlags != TRANSFORM_COMPONENT_NONE;
      if ( v2->IsVisible(this: v2) != (SelectionComponentFlags != TRANSFORM_COMPONENT_NONE) )
      {
        v2->SetVisible(this: v2, a2: bShowSlider);
        visibleSlidersChanged = true;
      }
      if ( CAttributeSlider::VisibleComponents(this: v2) != v7 )
        CAttributeSlider::SetVisibleComponents(this: v2, componentFlags: v7);
      if ( ++i >= c )
        break;
      v1 = this;
    }
    if ( visibleSlidersChanged )
    {
      v8 = (vgui::PanelListPanel *)vgui::PHandle::Get(this: (vgui::PHandle *)&this->m_OnDelete_register);
      vgui::PanelListPanel::RemoveAll(this: v8);
      for ( j = 0; j < c; ++j )
      {
        v10 = *(_DWORD *)(*(_DWORD *)&this->m_OnNavigateFrom_register + 4 * j);
        if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v10 + 136))(a1: v10) != 0 )
        {
          v11 = vgui::PHandle::Get(this: (vgui::PHandle *)&this->m_OnDelete_register);
          ((void (__thiscall *)(vgui::Panel *, _DWORD, int))v11->__vftable[1].GetVPanel)(a1: v11, a2: 0, a3: v10);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004836B0
// Name: protected: void CBaseAnimSetAttributeSliderPanel::UpdateSliderDependencyFlags(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetAttributeSliderPanel::UpdateSliderDependencyFlags(CBaseAnimSetAttributeSliderPanel *this)
{
  CAttributeSlider *v2; // eax
  int m_Size; // edx
  int v4; // edi
  CAttributeSlider **m_pMemory; // ecx
  CAttributeSlider *v6; // esi
  bool v7; // al
  int nSliders; // [esp+8h] [ebp-8h]
  CAttributeSlider *pPrimarySlider; // [esp+Ch] [ebp-4h]

  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
    || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL) )
  {
    v2 = (CAttributeSlider *)vgui::PHandle::Get(this: &this->m_pController->m_ActiveAttributeSlider);
    pPrimarySlider = v2;
  }
  else
  {
    pPrimarySlider = nullptr;
    v2 = nullptr;
  }
  m_Size = this->m_SliderList.m_Size;
  v4 = 0;
  for ( nSliders = m_Size; v4 < m_Size; ++v4 )
  {
    m_pMemory = this->m_SliderList.m_Memory.m_pMemory;
    v6 = m_pMemory[v4];
    if ( v6 != nullptr )
    {
      v7 = v2 != nullptr && CAttributeSlider::IsDependent(this: v2, pSlider: m_pMemory[v4]);
      CAttributeSlider::SetDependent(this: v6, dependent: v7);
      v2 = pPrimarySlider;
      m_Size = nSliders;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00483750
// Name: protected: int CBaseAnimSetAttributeSliderPanel::FindSliderIndexForControl(class CDmElement const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAnimSetAttributeSliderPanel::FindSliderIndexForControl(
        CBaseAnimSetAttributeSliderPanel *this,
        const CDmElement *control)
{
  int m_Size; // ebx
  int v4; // esi

  m_Size = this->m_SliderList.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return -1;
  while ( (const CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                a1: g_pDataModel.u,
                                a2: this->m_SliderList.m_Memory.m_pMemory[v4]->m_hControl.m_handle) != control )
  {
    if ( ++v4 >= m_Size )
      return -1;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x004837B0
// Name: public: bool CBaseAnimSetAttributeSliderPanel::GetSliderValues(struct AttributeValue_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAnimSetAttributeSliderPanel::GetSliderValues(
        CBaseAnimSetAttributeSliderPanel *this,
        AttributeValue_t *pValue,
        int nIndex)
{
  CAttributeSlider *v4; // esi
  vgui::Panel *v5; // ebx
  bool v6; // al
  CBaseAnimationSetControl *m_pController; // ecx
  AttributeValue_t *Preview; // eax

  v4 = this->m_SliderList.m_Memory.m_pMemory[nIndex];
  v5 = vgui::PHandle::Get(this: &this->m_pController->m_ActiveAttributeSlider);
  if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
    || (v6 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT)) )
  {
    v6 = true;
  }
  if ( v5 == v4 && v6
    || (*((_BYTE *)(m_pController = this->m_pController) + 104) & 2) != 0
    || CBaseAnimationSetControl::IsPresetFaderBeingDragged(this: m_pController) )
  {
    Preview = (AttributeValue_t *)CAttributeSlider::GetPreview(this: v4);
  }
  else
  {
    Preview = (AttributeValue_t *)CAttributeSlider::GetValue(this: v4);
  }
  *pValue = *Preview;
  return v4->IsVisible(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00483880
// Name: protected: virtual void CBaseAnimSetAttributeSliderPanel::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetAttributeSliderPanel::OnThink(CBaseAnimSetAttributeSliderPanel *this)
{
  vgui::Panel::OnThink(this);
  CBaseAnimationSetControl::UpdatePreviewSliderValues(this: this->m_pController);
  CBaseAnimationSetControl::UpdatePreviewSliderTimes(this: this->m_pController);
  this->ApplySliderValues(this, a2: false);
  CBaseAnimSetAttributeSliderPanel::UpdateSliderDependencyFlags(this);
}

//------------------------------------------------------------------------------
// Address: 0x004838C0
// Name: protected: class CAttributeSlider __near * CBaseAnimSetAttributeSliderPanel::AllocateSlider(void)
// Source: json
//------------------------------------------------------------------------------
CAttributeSlider *__thiscall CBaseAnimSetAttributeSliderPanel::AllocateSlider(CBaseAnimSetAttributeSliderPanel *this)
{
  int m_Size; // eax
  CAttributeSlider *v3; // edi
  CAttributeSlider *v5; // eax
  CAttributeSlider *v6; // esi

  m_Size = this->m_FreeSliderList.m_Size;
  if ( m_Size <= 0 )
  {
    v5 = (CAttributeSlider *)MemAlloc_Alloc(nSize: 0x2ACu);
    if ( v5 != nullptr )
    {
      v6 = CAttributeSlider::CAttributeSlider(this: v5, parent: this);
      v6->SetVisible(this: v6, a2: true);
      return v6;
    }
    else
    {
      (*(void (__thiscall **)(_DWORD, int))(MEMORY[0] + 132))(a1: 0, a2: 1);
      return nullptr;
    }
  }
  else
  {
    v3 = this->m_FreeSliderList.m_Memory.m_pMemory[m_Size - 1];
    --this->m_FreeSliderList.m_Size;
    v3->SetVisible(this: v3, a2: true);
    return v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00483960
// Name: protected: void CBaseAnimSetAttributeSliderPanel::InitFreeSliderList(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetAttributeSliderPanel::InitFreeSliderList(
        CBaseAnimSetAttributeSliderPanel *this,
        int nCount)
{
  CBaseAnimSetAttributeSliderPanel *v2; // edi
  CUtlMemory<vgui::TreeNode *,int> *p_m_FreeSliderList; // esi
  CAttributeSlider *v4; // eax
  CAttributeSlider *v5; // ebx
  vgui::TreeNode **m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  CAttributeSlider **v10; // eax

  v2 = this;
  if ( nCount > 0 )
  {
    p_m_FreeSliderList = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_FreeSliderList;
    while ( 1 )
    {
      v4 = (CAttributeSlider *)MemAlloc_Alloc(nSize: 0x2ACu);
      if ( v4 != nullptr )
        v5 = CAttributeSlider::CAttributeSlider(this: v4, parent: v2);
      else
        v5 = nullptr;
      v5->SetVisible(this: v5, a2: false);
      m_pMemory = p_m_FreeSliderList[1].m_pMemory;
      m_nAllocationCount = p_m_FreeSliderList->m_nAllocationCount;
      if ( (int)m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_FreeSliderList, num: (int)m_pMemory - m_nAllocationCount + 1);
      ++p_m_FreeSliderList[1].m_pMemory;
      v8 = p_m_FreeSliderList->m_pMemory;
      v9 = (char *)p_m_FreeSliderList[1].m_pMemory - (char *)m_pMemory - 1;
      p_m_FreeSliderList[1].m_nAllocationCount = (int)p_m_FreeSliderList->m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &v8[(_DWORD)m_pMemory + 1], src: &v8[(_DWORD)m_pMemory], count: 4 * v9);
      v10 = (CAttributeSlider **)&p_m_FreeSliderList->m_pMemory[(_DWORD)m_pMemory];
      if ( v10 != nullptr )
        *v10 = v5;
      if ( --nCount == 0 )
        break;
      v2 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00483A10
// Name: public: CBaseAnimSetAttributeSliderPanel::CBaseAnimSetAttributeSliderPanel(class vgui::Panel __near *,char const __near *,class CBaseAnimationSetEditor __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseAnimSetAttributeSliderPanel *__thiscall CBaseAnimSetAttributeSliderPanel::CBaseAnimSetAttributeSliderPanel(
        CBaseAnimSetAttributeSliderPanel *this,
        vgui::Panel *parent,
        const char *className,
        CBaseAnimationSetEditor *editor)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::Button *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  CPresetSideFilterSlider *v12; // eax
  CPresetSideFilterSlider *v13; // eax
  vgui::PanelListPanel *v14; // eax
  vgui::PanelListPanel *v15; // eax
  vgui::PanelListPanel *v16; // eax
  vgui::Panel *v17; // eax
  vgui::PanelListPanel *v18; // eax
  CBaseAnimationSetControl *Controller; // eax

  vgui::EditablePanel::EditablePanel(this, parent, panelName: className);
  this->IAnimationSetControlSelectionChangedListener::__vftable = (IAnimationSetControlSelectionChangedListener_vtbl *)&IAnimationSetControlSelectionChangedListener::`vftable';
  this->vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CBaseAnimSetAttributeSliderPanel_vtbl *)&CBaseAnimSetAttributeSliderPanel::`vftable'{for `vgui::EditablePanel'};
  this->IAnimationSetControlSelectionChangedListener::__vftable = (IAnimationSetControlSelectionChangedListener_vtbl *)&CBaseAnimSetAttributeSliderPanel::`vftable'{for `IAnimationSetControlSelectionChangedListener'};
  if ( `CBaseAnimSetAttributeSliderPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAnimSetAttributeSliderPanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetAttributeSliderPanel");
    v5->pfnClassName = CBaseAnimSetAttributeSliderPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CBaseAnimSetAttributeSliderPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBaseAnimSetAttributeSliderPanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CBaseAnimSetAttributeSliderPanel");
    v6->pfnClassName = CBaseAnimSetAttributeSliderPanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CBaseAnimSetAttributeSliderPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBaseAnimSetAttributeSliderPanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAnimSetAttributeSliderPanel");
    v7->pfnClassName = CBaseAnimSetAttributeSliderPanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  this->m_hEditor.m_iPanelID = -1;
  this->m_Sliders.m_iPanelID = -1;
  this->m_SliderList.m_Memory.m_pMemory = nullptr;
  this->m_SliderList.m_Memory.m_nAllocationCount = 0;
  this->m_SliderList.m_Memory.m_nGrowSize = 0;
  this->m_SliderList.m_Size = 0;
  this->m_SliderList.m_pElements = nullptr;
  this->m_pController = nullptr;
  this->m_FreeSliderList.m_Memory.m_pMemory = nullptr;
  this->m_FreeSliderList.m_Memory.m_nAllocationCount = 0;
  this->m_FreeSliderList.m_Memory.m_nGrowSize = 0;
  this->m_FreeSliderList.m_Size = 0;
  this->m_FreeSliderList.m_pElements = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_hEditor, pPanel: editor);
  v8 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v8 != nullptr )
    v9 = vgui::Button::Button(
           this: v8,
           parent: this,
           panelName: "AttributeSliderLeftOnly",
           text: defaultValue,
           pActionSignalTarget: this,
           pCmd: "OnLeftOnly");
  else
    v9 = nullptr;
  this->m_pLeftRightBoth[0] = v9;
  v10 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v10 != nullptr )
    v11 = vgui::Button::Button(
            this: v10,
            parent: this,
            panelName: "AttributeSliderRightOnly",
            text: defaultValue,
            pActionSignalTarget: this,
            pCmd: "OnRightOnly");
  else
    v11 = nullptr;
  this->m_pLeftRightBoth[1] = v11;
  v12 = (CPresetSideFilterSlider *)MemAlloc_Alloc(nSize: 0x1C4u);
  if ( v12 != nullptr )
    v13 = CPresetSideFilterSlider::CPresetSideFilterSlider(this: v12, parent: this, panelName: "PresetSideFilter");
  else
    v13 = nullptr;
  this->m_pPresetSideFilter = v13;
  v14 = (vgui::PanelListPanel *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v14 != nullptr )
    v15 = vgui::PanelListPanel::PanelListPanel(this: v14, parent: this, panelName: "AttributeSliders");
  else
    v15 = nullptr;
  vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &this->m_Sliders, pPanel: v15);
  v16 = (vgui::PanelListPanel *)vgui::PHandle::Get(this: &this->m_Sliders);
  vgui::PanelListPanel::SetFirstColumnWidth(this: v16, width: 0);
  v17 = vgui::PHandle::Get(this: &this->m_Sliders);
  vgui::Panel::SetAutoResize(
    this: v17,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 32,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  v18 = (vgui::PanelListPanel *)vgui::PHandle::Get(this: &this->m_Sliders);
  vgui::PanelListPanel::SetVerticalBufferPixels(this: v18, buffer: 0);
  Controller = CBaseAnimationSetEditor::GetController(this: editor);
  this->m_pController = Controller;
  CBaseAnimationSetControl::AddControlSelectionChangedListener(
    this: Controller,
    listener: &this->IAnimationSetControlSelectionChangedListener);
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 0);
  CBaseAnimSetAttributeSliderPanel::InitFreeSliderList(this, nCount: 1500);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00483C80
// Name: public: virtual struct vgui::PanelMessageMap __near * CBaseAnimSetAttributeSliderPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBaseAnimSetAttributeSliderPanel::GetMessageMap(
        CBaseAnimSetAttributeSliderPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBaseAnimSetAttributeSliderPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAnimSetAttributeSliderPanel::GetMessageMap'::`2'::s_pMap;
  `CBaseAnimSetAttributeSliderPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBaseAnimSetAttributeSliderPanel");
  `CBaseAnimSetAttributeSliderPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00483CB0
// Name: public: virtual struct PanelAnimationMap __near * CBaseAnimSetAttributeSliderPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBaseAnimSetAttributeSliderPanel::GetAnimMap(CBaseAnimSetAttributeSliderPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CBaseAnimSetAttributeSliderPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00483CC0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBaseAnimSetAttributeSliderPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBaseAnimSetAttributeSliderPanel::GetKBMap(CBaseAnimSetAttributeSliderPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBaseAnimSetAttributeSliderPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBaseAnimSetAttributeSliderPanel::GetKBMap'::`2'::s_pMap;
  `CBaseAnimSetAttributeSliderPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAnimSetAttributeSliderPanel");
  `CBaseAnimSetAttributeSliderPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00483D30
// Name: protected: void CBaseAnimSetAttributeSliderPanel::RebuildSliderLists(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetAttributeSliderPanel::RebuildSliderLists(CBaseAnimSetAttributeSliderPanel *this)
{
  CBaseAnimSetAttributeSliderPanel *v1; // ebx
  CDmElement *m_Size; // eax
  void (__thiscall *SetVisible)(vgui::Panel *, bool); // eax
  int v4; // edi
  int m_nAllocationCount; // eax
  CAttributeSlider **m_pMemory; // ecx
  int v7; // eax
  int *v8; // edi
  CUtlMemory<vgui::TreeNode *,int> *p_m_SliderList; // esi
  vgui::PanelListPanel *v10; // eax
  CBaseAnimationSetControl *m_pController; // ecx
  CDmeTransform *j; // eax
  CDmElement *Position; // eax
  int v14; // edx
  int v15; // ecx
  int v16; // eax
  int v17; // ebx
  int v18; // edi
  int v19; // eax
  CDmElement **v20; // ecx
  int v21; // eax
  CDmElement **v22; // edi
  CDmElement *v23; // edi
  CAttributeSlider *Slider; // ebx
  vgui::TreeNode **v25; // edi
  int v26; // eax
  vgui::TreeNode **v27; // ecx
  int v28; // eax
  CAttributeSlider **v29; // edi
  CDmElement *v30; // edi
  CAttributeSlider *v31; // ebx
  vgui::TreeNode **v32; // edi
  int v33; // eax
  vgui::TreeNode **v34; // ecx
  int v35; // eax
  CAttributeSlider **v36; // edi
  CUtlVector<CDmElement *,CUtlMemory<CDmElement *,int> > controlList; // [esp+Ch] [ebp-2Ch] BYREF
  CAnimSetGroupAnimSetTraversal traversal; // [esp+20h] [ebp-18h] BYREF
  CDmElement *control; // [esp+28h] [ebp-10h]
  int controlCount; // [esp+2Ch] [ebp-Ch]
  CBaseAnimSetAttributeSliderPanel *v41; // [esp+30h] [ebp-8h]
  int i; // [esp+34h] [ebp-4h]

  v1 = this;
  m_Size = (CDmElement *)this->m_SliderList.m_Size;
  v41 = this;
  control = m_Size;
  for ( i = 0; i < (int)control; ++i )
  {
    SetVisible = v1->m_SliderList.m_Memory.m_pMemory[i]->SetVisible;
    controlCount = (int)v1->m_SliderList.m_Memory.m_pMemory[i];
    ((void (__stdcall *)(_DWORD))SetVisible)(a1: 0);
    v4 = v1->m_FreeSliderList.m_Size;
    m_nAllocationCount = v1->m_FreeSliderList.m_Memory.m_nAllocationCount;
    if ( v4 + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&v1->m_FreeSliderList,
        num: v4 - m_nAllocationCount + 1);
    ++v1->m_FreeSliderList.m_Size;
    m_pMemory = v1->m_FreeSliderList.m_Memory.m_pMemory;
    v7 = v1->m_FreeSliderList.m_Size - v4 - 1;
    v1->m_FreeSliderList.m_pElements = m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &m_pMemory[v4 + 1], src: &m_pMemory[v4], count: 4 * v7);
    v8 = (int *)&v1->m_FreeSliderList.m_Memory.m_pMemory[v4];
    if ( v8 != nullptr )
      *v8 = controlCount;
  }
  p_m_SliderList = (CUtlMemory<vgui::TreeNode *,int> *)&v1->m_SliderList;
  v1->m_SliderList.m_Size = 0;
  v10 = (vgui::PanelListPanel *)vgui::PHandle::Get(this: &v1->m_Sliders);
  vgui::PanelListPanel::RemoveAll(this: v10);
  m_pController = v1->m_pController;
  memset(&controlList, 0, sizeof(controlList));
  traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: m_pController);
  traversal.m_nIndex = 0;
  for ( j = (CDmeTransform *)CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
        j != nullptr;
        j = (CDmeTransform *)CAnimSetGroupAnimSetTraversal::Next(this: &traversal) )
  {
    Position = (CDmElement *)CDmeTransform::GetPosition(this: j);
    v14 = *(_DWORD *)&Position->m_Id.m_Value[8];
    v15 = 0;
    control = Position;
    controlCount = v14;
    i = 0;
    if ( v14 > 0 )
    {
      while ( 1 )
      {
        v16 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                a1: g_pDataModel.u,
                a2: *((_DWORD *)&Position->OnAttributeChanged + v15));
        v17 = v16;
        if ( v16 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v16 + 16))(
               a1: v16,
               a2: CDmElement::m_classType.u) != 0 )
        {
          v18 = controlList.m_Size;
          v19 = controlList.m_Size;
          if ( controlList.m_Size + 1 > controlList.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&controlList,
              num: controlList.m_Size - controlList.m_Memory.m_nAllocationCount + 1);
            v19 = controlList.m_Size;
          }
          v20 = controlList.m_Memory.m_pMemory;
          controlList.m_Size = v19 + 1;
          v21 = v19 - v18;
          controlList.m_pElements = controlList.m_Memory.m_pMemory;
          if ( v21 > 0 )
          {
            _V_memmove(
              dest: &controlList.m_Memory.m_pMemory[v18 + 1],
              src: &controlList.m_Memory.m_pMemory[v18],
              count: 4 * v21);
            v20 = controlList.m_Memory.m_pMemory;
          }
          v22 = &v20[v18];
          if ( v22 != nullptr )
            *v22 = (CDmElement *)v17;
        }
        v15 = i + 1;
        i = v15;
        if ( v15 >= controlCount )
          break;
        Position = control;
      }
      v1 = v41;
    }
  }
  i = 0;
  if ( controlList.m_Size > 0 )
  {
    while ( 1 )
    {
      control = controlList.m_Memory.m_pMemory[i];
      v23 = control;
      Slider = CBaseAnimSetAttributeSliderPanel::AllocateSlider(this: v1);
      CAttributeSlider::Init(this: Slider, control: v23, bOrientation: false);
      Slider->SetVisible(this: Slider, a2: false);
      v25 = p_m_SliderList[1].m_pMemory;
      v26 = p_m_SliderList->m_nAllocationCount;
      if ( (int)v25 + 1 > v26 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_SliderList, num: (int)v25 - v26 + 1);
      ++p_m_SliderList[1].m_pMemory;
      v27 = p_m_SliderList->m_pMemory;
      v28 = (char *)p_m_SliderList[1].m_pMemory - (char *)v25 - 1;
      p_m_SliderList[1].m_nAllocationCount = (int)p_m_SliderList->m_pMemory;
      if ( v28 > 0 )
        _V_memmove(dest: &v27[(_DWORD)v25 + 1], src: &v27[(_DWORD)v25], count: 4 * v28);
      v29 = (CAttributeSlider **)&p_m_SliderList->m_pMemory[(_DWORD)v25];
      if ( v29 != nullptr )
        *v29 = Slider;
      v30 = control;
      if ( control != nullptr
        && ((int (__thiscall *)(_DWORD, _DWORD))control->IsA)(
             a1: control,
             a2: (CUtlSymbolLarge)CDmeTransformControl::m_classType.u.m_Id) )
      {
        v31 = CBaseAnimSetAttributeSliderPanel::AllocateSlider(this: v41);
        CAttributeSlider::Init(this: v31, control: v30, bOrientation: true);
        v31->SetVisible(this: v31, a2: false);
        v32 = p_m_SliderList[1].m_pMemory;
        v33 = p_m_SliderList->m_nAllocationCount;
        if ( (int)v32 + 1 > v33 )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_SliderList, num: (int)v32 - v33 + 1);
        ++p_m_SliderList[1].m_pMemory;
        v34 = p_m_SliderList->m_pMemory;
        v35 = (char *)p_m_SliderList[1].m_pMemory - (char *)v32 - 1;
        p_m_SliderList[1].m_nAllocationCount = (int)p_m_SliderList->m_pMemory;
        if ( v35 > 0 )
          _V_memmove(dest: &v34[(_DWORD)v32 + 1], src: &v34[(_DWORD)v32], count: 4 * v35);
        v36 = (CAttributeSlider **)&p_m_SliderList->m_pMemory[(_DWORD)v32];
        if ( v36 != nullptr )
          *v36 = v31;
      }
      if ( ++i >= controlList.m_Size )
        break;
      v1 = v41;
    }
  }
  if ( controlList.m_Memory.m_nGrowSize >= 0 && controlList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: controlList.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00484060
// Name: public: virtual void CBaseAnimSetAttributeSliderPanel::OnControlsAddedOrRemoved(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAnimSetAttributeSliderPanel::OnControlsAddedOrRemoved(CBaseAnimSetAttributeSliderPanel *this)
{
  CBaseAnimSetAttributeSliderPanel *v1; // ebx
  CBaseAnimationSetControl *m_pController; // ecx
  int v3; // edi
  CDmeTransform *v4; // eax
  const CDmaElementArray<CDmElement> *Position; // eax
  int m_Size; // edx
  int v7; // ecx
  int v8; // eax
  CDmElement *v9; // esi
  CAttributeSlider *v10; // ebx
  bool v11; // zf
  bool v12; // bl
  DmElementHandle_t m_handle; // [esp-4h] [ebp-2Ch]
  CAnimSetGroupAnimSetTraversal traversal; // [esp+Ch] [ebp-1Ch] BYREF
  int controlCount; // [esp+14h] [ebp-14h]
  const CDmaElementArray<CDmElement> *controls; // [esp+18h] [ebp-10h]
  int i; // [esp+1Ch] [ebp-Ch]
  CBaseAnimSetAttributeSliderPanel *v18; // [esp+20h] [ebp-8h]
  bool changed; // [esp+27h] [ebp-1h]

  v1 = this;
  m_pController = this->m_pController;
  v18 = v1;
  changed = false;
  v3 = 0;
  traversal.m_pFilmClip = CBaseAnimationSetControl::GetAnimationSetClip(this: m_pController);
  traversal.m_nIndex = 0;
  v4 = (CDmeTransform *)CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
  if ( v4 != nullptr )
  {
    do
    {
      Position = (const CDmaElementArray<CDmElement> *)CDmeTransform::GetPosition(this: v4);
      m_Size = Position->m_Storage.m_Size;
      v7 = 0;
      controls = Position;
      controlCount = m_Size;
      i = 0;
      if ( m_Size > 0 )
      {
        while ( 1 )
        {
          v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                 a1: g_pDataModel.u,
                 a2: Position->m_Storage.m_Memory.m_pMemory[v7]);
          v9 = (CDmElement *)v8;
          if ( v8 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
                 a1: v8,
                 a2: CDmElement::m_classType.u) != 0 )
          {
            if ( v3 >= v1->m_SliderList.m_Size )
              break;
            v10 = v1->m_SliderList.m_Memory.m_pMemory[v3++];
            if ( (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                 a1: g_pDataModel.u,
                                 a2: v10->m_hControl.m_handle) != v9 )
              break;
            if ( v9->IsA(this: v9, a2: CDmeTransformControl::m_classType) )
            {
              m_handle = v18->m_SliderList.m_Memory.m_pMemory[v3++]->m_hControl.m_handle;
              v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 72))(
                      a1: g_pDataModel.u,
                      a2: m_handle) == (_DWORD)v9;
            }
            else
            {
              v12 = (*((_BYTE *)v10 + 656) & 4) != 0;
              v11 = v12 == CDmElement::HasAttribute(this: v9, pAttributeName: "rightValue", type: AT_UNKNOWN);
            }
            if ( !v11 )
              break;
          }
          v7 = i + 1;
          i = v7;
          if ( v7 >= controlCount )
            goto LABEL_16;
          v1 = v18;
          Position = controls;
        }
        changed = true;
      }
LABEL_16:
      v4 = (CDmeTransform *)CAnimSetGroupAnimSetTraversal::Next(this: &traversal);
      v1 = v18;
    }
    while ( v4 != nullptr );
    if ( changed )
      goto LABEL_19;
  }
  if ( v3 != v1->m_SliderList.m_Size )
LABEL_19:
    CBaseAnimSetAttributeSliderPanel::RebuildSliderLists(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x004841C0
// Name: public: virtual void CBaseAnimSetAttributeSliderPanel::ChangeAnimationSetClip(class CDmeFilmClip __near *)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CBaseAnimSetAttributeSliderPanel::ChangeAnimationSetClip(
        CBaseAnimSetAttributeSliderPanel *this,
        CDmeFilmClip *pFilmClip)
{
  CBaseAnimSetAttributeSliderPanel::RebuildSliderLists(this);
}

} // namespace sceneviewer
