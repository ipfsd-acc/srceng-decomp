// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/bitmapimagepanel.cpp
// Functions: 5
// ============================================================

#include "game\client\cstrike15\gameui\bitmapimagepanel.h"

//------------------------------------------------------------------------------
// Address: 0x101D16A0
// Name: public: CBitmapImagePanel::CBitmapImagePanel(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBitmapImagePanel *__thiscall CBitmapImagePanel::CBitmapImagePanel(
        CBitmapImagePanel *this,
        vgui::Panel *parent,
        const char *panelName,
        char *filename)
{
  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (CBitmapImagePanel_vtbl *)&CBitmapImagePanel::`vftable';
  this->m_szTexture[0] = 0;
  this->m_bUploaded = false;
  this->m_nTextureId = -1;
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: 100, tall: 100);
  if ( filename != nullptr && *filename != 0 )
    V_strncpy(pDest: this->m_szTexture, pSrc: filename, maxLen: 128);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101D1710
// Name: private: void CBitmapImagePanel::forceUpload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitmapImagePanel::forceUpload(CBitmapImagePanel *this)
{
  char *m_szTexture; // edi
  int v3; // eax

  m_szTexture = this->m_szTexture;
  if ( this->m_szTexture[0] != 0 )
  {
    this->m_bUploaded = true;
    v3 = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
    this->m_nTextureId = v3;
    g_pVGuiSurface->DrawSetTextureFile(this: g_pVGuiSurface, a2: v3, a3: m_szTexture, a4: 0, a5: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D1760
// Name: public: virtual void CBitmapImagePanel::forceReload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitmapImagePanel::forceReload(CBitmapImagePanel *this)
{
  if ( this->m_bUploaded )
    g_pVGuiSurface->DrawSetTextureFile(
      this: g_pVGuiSurface,
      a2: this->m_nTextureId,
      a3: this->m_szTexture,
      a4: 0,
      a5: true);
}

//------------------------------------------------------------------------------
// Address: 0x101D1790
// Name: public: virtual void CBitmapImagePanel::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitmapImagePanel::PaintBackground(CBitmapImagePanel *this)
{
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // edx
  int w; // [esp+4h] [ebp-Ch] BYREF
  int h; // [esp+8h] [ebp-8h] BYREF
  int v5; // [esp+Ch] [ebp-4h]

  if ( this->m_szTexture[0] != 0 )
  {
    if ( !this->m_bUploaded )
      CBitmapImagePanel::forceUpload(this);
    vgui::Panel::GetSize(this, wide: &w, tall: &h);
    DrawSetColor = g_pVGuiSurface->DrawSetColor;
    v5 = -1;
    ((void (__thiscall *)(vgui::ISurface *, int))DrawSetColor)(a1: g_pVGuiSurface, a2: -1);
    g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: this->m_nTextureId);
    g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: w, a5: h);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D1810
// Name: public: virtual void CBitmapImagePanel::setTexture(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBitmapImagePanel::setTexture(CBitmapImagePanel *this, char *filename)
{
  char *m_szTexture; // edi
  int v4; // eax

  m_szTexture = this->m_szTexture;
  V_strncpy(pDest: this->m_szTexture, pSrc: filename, maxLen: 128);
  if ( this->m_bUploaded )
  {
    this->forceReload(this);
  }
  else if ( *m_szTexture != 0 )
  {
    this->m_bUploaded = true;
    v4 = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
    this->m_nTextureId = v4;
    g_pVGuiSurface->DrawSetTextureFile(this: g_pVGuiSurface, a2: v4, a3: m_szTexture, a4: 0, a5: true);
  }
}
