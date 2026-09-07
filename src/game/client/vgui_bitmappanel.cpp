// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/vgui_bitmappanel.cpp
// Functions: 4
// ============================================================

#include "game\client\vgui_bitmappanel.h"

//------------------------------------------------------------------------------
// Address: 0x101808C0
// Name: public: CBitmapPanel::CBitmapPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBitmapPanel *__thiscall CBitmapPanel::CBitmapPanel(CBitmapPanel *this, vgui::Panel *pParent, const char *pName)
{
  vgui::Panel::Panel(this, parent: pParent, panelName: pName);
  this->__vftable = (CBitmapPanel_vtbl *)&CBitmapPanel::`vftable';
  this->m_pImage = nullptr;
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  this->m_a = 255;
  this->m_b = 255;
  this->m_g = 255;
  this->m_r = 255;
  *(_WORD *)&this->m_bOwnsImage = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10180920
// Name: public: virtual void CBitmapPanel::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBitmapPanel::ApplySettings(CBitmapPanel *this@<ecx>, int a2@<edi>, KeyValues *pInitData)
{
  KeyValues *v3; // ebx
  BitmapImage *m_pImage; // ecx
  char *String; // eax
  const char *v7; // edi
  int v8; // edx
  int v9; // eax
  int v10; // ecx
  char *v11; // eax
  const char *v12; // edi
  BitmapImage *v13; // ebx
  unsigned int v14; // eax
  int a; // [esp+Ch] [ebp-Ch] BYREF
  int b; // [esp+10h] [ebp-8h] BYREF
  int g; // [esp+14h] [ebp-4h] BYREF

  v3 = pInitData;
  vgui::Panel::ApplySettings(this, a2: (int)pInitData, a3: a2, inResourceData: pInitData);
  m_pImage = this->m_pImage;
  if ( m_pImage != nullptr && this->m_bOwnsImage )
  {
    ((void (__thiscall *)(BitmapImage *, int))m_pImage->dtr_IImage)(a1: m_pImage, a2: 1);
    this->m_pImage = nullptr;
  }
  this->m_a = 255;
  this->m_b = 255;
  this->m_g = 255;
  this->m_r = 255;
  String = KeyValues::GetString(this: v3, keyName: "color", defaultValue: "255 255 255 255");
  v7 = String;
  if ( String != nullptr && *String != 0 )
  {
    if ( sscanf(string: String, format: "%i %i %i %i", &pInitData, &g, &b, &a) == 4 )
    {
      v8 = g;
      v9 = b;
      this->m_r = (int)pInitData;
      v10 = a;
      this->m_g = v8;
      this->m_b = v9;
      this->m_a = v10;
    }
    else
    {
      _Warning(a1: "Couldn't scan four color values from %s\n", v7);
    }
  }
  this->m_szMouseOverText[0] = 0;
  v11 = KeyValues::GetString(this: v3, keyName: "material", defaultValue: prType);
  v12 = v11;
  if ( v11 != nullptr && *v11 != 0 && this->m_bOwnsImage )
  {
    v13 = (BitmapImage *)MemAlloc_Alloc(nSize: 0x48u);
    if ( v13 != nullptr )
    {
      v14 = this->GetVPanel(this);
      this->m_pImage = BitmapImage::BitmapImage(this: v13, parent: v14, filename: v12);
    }
    else
    {
      this->m_pImage = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10180A60
// Name: public: virtual void CBitmapPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitmapPanel::Paint(CBitmapPanel *this)
{
  BitmapImage *m_pImage; // ecx
  unsigned __int8 m_g; // dl
  unsigned __int8 m_b; // al
  unsigned __int8 m_a; // dl
  int v6; // eax
  Color color; // [esp+Ch] [ebp-4h] BYREF

  m_pImage = this->m_pImage;
  if ( m_pImage != nullptr )
  {
    m_g = this->m_g;
    color = (Color)LOBYTE(this->m_r);
    m_b = this->m_b;
    color._color[1] = m_g;
    m_a = this->m_a;
    color._color[2] = m_b;
    color._color[3] = m_a;
    BitmapImage::SetColor(this: m_pImage, clr: &color);
    v6 = this->GetVPanel(this);
    BitmapImage::DoPaint(this: this->m_pImage, pPanel: v6, yaw: 0, flAlphaModulate: 1.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10180AE0
// Name: public: virtual void CBitmapPanel::SetImage(class BitmapImage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitmapPanel::SetImage(CBitmapPanel *this, BitmapImage *pImage)
{
  BitmapImage *m_pImage; // ecx

  m_pImage = this->m_pImage;
  if ( m_pImage != nullptr && this->m_bOwnsImage )
    ((void (__thiscall *)(BitmapImage *, int))m_pImage->dtr_IImage)(a1: m_pImage, a2: 1);
  this->m_pImage = pImage;
  this->m_bOwnsImage = pImage == nullptr;
  if ( pImage != nullptr )
    BitmapImage::GetColor(this: pImage, r: &this->m_r, g: &this->m_g, b: &this->m_b, a: &this->m_a);
}
