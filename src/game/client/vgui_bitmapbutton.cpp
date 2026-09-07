// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/vgui_bitmapbutton.cpp
// Functions: 8
// ============================================================

#include "game\client\vgui_bitmapbutton.h"

//------------------------------------------------------------------------------
// Address: 0x1017FF80
// Name: public: virtual void CBitmapButton::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitmapButton::ApplySettings(CBitmapButton *this, KeyValues *pInitData)
{
  int v3; // esi
  BitmapImage *m_pImage; // ebx
  const char *pSectionName[4]; // [esp+Ch] [ebp-10h]

  vgui::Button::ApplySettings(this, inResourceData: pInitData);
  pSectionName[0] = "enabledImage";
  pSectionName[1] = "mouseOverImage";
  pSectionName[2] = "pressedImage";
  pSectionName[3] = "disabledImage";
  v3 = 0;
  m_pImage = this->m_pImage;
  do
  {
    this->m_bImageLoaded[v3] = InitializeImage(
                                 pInitData,
                                 pSectionName: pSectionName[v3],
                                 pParent: this,
                                 pBitmapImage: m_pImage);
    ++v3;
    ++m_pImage;
  }
  while ( v3 < 4 );
}

//------------------------------------------------------------------------------
// Address: 0x1017FFF0
// Name: public: virtual void CBitmapButton::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitmapButton::Paint(CBitmapButton *this)
{
  int v2; // edi
  unsigned int v3; // eax

  v2 = 0;
  if ( this->IsArmed(this) )
  {
    v2 = this->IsDepressed(this) + 1;
  }
  else if ( !this->IsEnabled(this) )
  {
    v2 = 3;
  }
  if ( this->m_bImageLoaded[v2] )
  {
    v3 = this->GetVPanel(this);
    BitmapImage::DoPaint(this: &this->m_pImage[v2], pPanel: v3, yaw: 0.0, flAlphaModulate: 1.0);
  }
  vgui::Button::Paint(this);
}

//------------------------------------------------------------------------------
// Address: 0x10180080
// Name: public: virtual void CBitmapButton::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitmapButton::OnMouseDoublePressed(CBitmapButton *this, ButtonCode_t code)
{
  KeyValues *doublePressedActionMessage; // ecx
  CBitmapButton_vtbl *v4; // edi
  KeyValues *Copy; // eax

  vgui::ScrollBarSlider::OnMouseDoublePressed((vgui::ToggleButton *)this, code);
  doublePressedActionMessage = this->_doublePressedActionMessage;
  if ( doublePressedActionMessage != nullptr )
  {
    v4 = this->__vftable;
    Copy = KeyValues::MakeCopy(this: doublePressedActionMessage);
    v4->PostActionSignal(this, a2: Copy);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101800C0
// Name: public: CBitmapButton::CBitmapButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBitmapButton *__thiscall CBitmapButton::CBitmapButton(
        CBitmapButton *this,
        vgui::Panel *pParent,
        const char *pName,
        const char *pText)
{
  BitmapImage *m_pImage; // esi
  int i; // ebx

  vgui::Button::Button(
    this,
    parent: pParent,
    panelName: pName,
    text: pText,
    pActionSignalTarget: nullptr,
    pCmd: nullptr);
  this->__vftable = (CBitmapButton_vtbl *)&CBitmapButton::`vftable';
  m_pImage = this->m_pImage;
  for ( i = 3; i >= 0; --i )
    BitmapImage::BitmapImage(this: m_pImage++);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  *(_DWORD *)this->m_bImageLoaded = 0;
  this->_doublePressedActionMessage = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10180120
// Name: public: static char const __near * vgui::Button::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Button::GetPanelClassName()
{
  return "Button";
}

//------------------------------------------------------------------------------
// Address: 0x10180130
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Button::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Button::GetMessageMap(vgui::Button *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Button::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Button::GetMessageMap'::`2'::s_pMap;
  `vgui::Button::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Button");
  `vgui::Button::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10180170
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Button::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Button::GetKBMap(vgui::Button *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Button::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Button::GetKBMap'::`2'::s_pMap;
  `vgui::Button::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  `vgui::Button::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1039CE90
// Name: protected: virtual class vgui::IBorder __near * vgui::Button::GetBorder(bool,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::IBorder *__thiscall vgui::Button::GetBorder(
        vgui::Button *this,
        bool depressed,
        bool armed,
        bool selected,
        bool keyfocus)
{
  if ( (this->_buttonFlags.m_nFlags & 8) != 0 )
  {
    if ( depressed )
      return this->_depressedBorder;
    if ( keyfocus || this->IsEnabled(this) && (this->_buttonFlags.m_nFlags & 0x40) != 0 )
      return this->_keyFocusBorder;
  }
  else if ( depressed )
  {
    return this->_depressedBorder;
  }
  return this->_defaultBorder;
}
