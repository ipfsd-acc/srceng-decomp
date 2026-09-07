// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/vgui_basepanel.cpp
// Functions: 4
// ============================================================

#include "engine\vgui_basepanel.h"

//------------------------------------------------------------------------------
// Address: 0x102054C0
// Name: public: virtual CBasePanel::~CBasePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePanel::~CBasePanel(CBasePanel *this)
{
  this->__vftable = (CBasePanel_vtbl *)&CBasePanel::`vftable';
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x102054F0
// Name: int DrawTextLen(unsigned long,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __usercall DrawTextLen@<eax>(int a1@<ebx>, int a2@<edi>, int a3@<esi>, unsigned int font, const wchar_t *text)
{
  signed int v5; // kr00_4
  int v6; // edi
  signed int i; // esi
  int c; // [esp+0h] [ebp-Ch] BYREF
  int b; // [esp+4h] [ebp-8h] BYREF
  int a; // [esp+8h] [ebp-4h] BYREF

  v5 = wcslen(text);
  v6 = 0;
  ((void (__thiscall *)(vgui::ISurface *, unsigned int, int, int, int))g_pVGuiSurface->DrawSetTextFont)(
    a1: g_pVGuiSurface,
    a2: font,
    a3: a2,
    a4: a3,
    a5: a1);
  for ( i = 0; i < v5; ++i )
  {
    ((void (__stdcall *)(unsigned int, _DWORD, int *, int *, int *))g_pVGuiSurface->GetCharABCwide)(
      a1: font,
      a2: text[i],
      a3: &a,
      a4: &b,
      a5: &c);
    if ( i != 0 )
      v6 += a;
    v6 += b;
    if ( i != v5 - 1 )
      v6 += c;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10205580
// Name: void DrawColoredText(unsigned long,int,int,int,int,int,int,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawColoredText(unsigned int font, int x, int y, int r, int g, int b, int a, const wchar_t *text)
{
  int v8; // esi

  v8 = wcslen(text);
  if ( v8 > 0 )
  {
    g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: font);
    g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x, a3: y);
    g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
    g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: text, a3: v8, a4: FONT_DRAW_DEFAULT);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10205600
// Name: public: CBasePanel::CBasePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBasePanel *__thiscall CBasePanel::CBasePanel(CBasePanel *this, vgui::Panel *parent, const char *panelName)
{
  unsigned int vpanel; // eax

  vgui::Panel::Panel(this, parent, panelName);
  vpanel = this->_vpanel;
  this->__vftable = (CBasePanel_vtbl *)&CBasePanel::`vftable';
  g_pVGui->AddTickSignal(this: g_pVGui, a2: vpanel, a3: 0);
  return this;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102056D0
// Name: public: virtual CBasePanel::~CBasePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePanel::~CBasePanel(CBasePanel *this)
{
  this->__vftable = (CBasePanel_vtbl *)&CBasePanel::`vftable';
  vgui::Panel::~Panel(this);
}

//------------------------------------------------------------------------------
// Address: 0x102056E0
// Name: int DrawTextLen(unsigned long,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __usercall DrawTextLen@<eax>(int a1@<ebx>, int a2@<edi>, int a3@<esi>, unsigned int font, const wchar_t *text)
{
  signed int v5; // kr00_4
  int v6; // edi
  signed int i; // esi
  int c; // [esp+0h] [ebp-Ch] BYREF
  int b; // [esp+4h] [ebp-8h] BYREF
  int a; // [esp+8h] [ebp-4h] BYREF

  v5 = wcslen(text);
  v6 = 0;
  ((void (__thiscall *)(vgui::ISurface *, unsigned int, int, int, int))g_pVGuiSurface->DrawSetTextFont)(
    a1: g_pVGuiSurface,
    a2: font,
    a3: a2,
    a4: a3,
    a5: a1);
  for ( i = 0; i < v5; ++i )
  {
    ((void (__stdcall *)(unsigned int, _DWORD, int *, int *, int *))g_pVGuiSurface->GetCharABCwide)(
      a1: font,
      a2: text[i],
      a3: &a,
      a4: &b,
      a5: &c);
    if ( i != 0 )
      v6 += a;
    v6 += b;
    if ( i != v5 - 1 )
      v6 += c;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10205770
// Name: void DrawColoredText(unsigned long,int,int,int,int,int,int,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawColoredText(unsigned int font, int x, int y, int r, int g, int b, int a, const wchar_t *text)
{
  int v8; // esi

  v8 = wcslen(text);
  if ( v8 > 0 )
  {
    g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: font);
    g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: x, a3: y);
    g_pVGuiSurface->DrawSetTextColor_2(this: g_pVGuiSurface, a2: r, a3: g, a4: b, a5: a);
    g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: text, a3: v8, a4: FONT_DRAW_DEFAULT);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102057F0
// Name: public: CBasePanel::CBasePanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBasePanel *__thiscall CBasePanel::CBasePanel(CBasePanel *this, vgui::Panel *parent, const char *panelName)
{
  unsigned int vpanel; // eax

  vgui::Panel::Panel(this, parent, panelName);
  vpanel = this->_vpanel;
  this->__vftable = (CBasePanel_vtbl *)&CBasePanel::`vftable';
  g_pVGui->AddTickSignal(this: g_pVGui, a2: vpanel, a3: 0);
  return this;
}

} // namespace engine_xlsp
