// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/vgui_debugoverlaypanel.cpp
// Functions: 6
// ============================================================

#include "game\client\vgui_debugoverlaypanel.h"

//------------------------------------------------------------------------------
// Address: 0x10181290
// Name: public: virtual void CDebugOverlay::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDebugOverlay::ApplySchemeSettings(CDebugOverlay *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  unsigned int v4; // eax
  int v5; // eax
  int w; // [esp+8h] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  v4 = v2->GetFont(this: v2, a2: "DebugOverlay", a3: false);
  this->m_hFont = v4;
  if ( v4 != 0 )
  {
    v5 = (int)(float)((float)g_pVGuiSurface->GetFontTall(this: g_pVGuiSurface, a2: v4) * 0.69999999);
    this->m_LineSpacing = v5;
    if ( v5 <= 13 )
      v5 = 13;
    this->m_LineSpacing = v5;
  }
  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &w, a3: (int *)&pScheme);
  vgui::Panel::SetSize(this, wide: w, tall: (int)pScheme);
  vgui::Panel::SetPos(this, x: 0, y: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10181370
// Name: public: virtual bool CDebugOverlay::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDebugOverlay::ShouldDraw(CDebugOverlay *this)
{
  return debugoverlay->GetFirst(this: debugoverlay) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10181390
// Name: public: CDebugOverlay::CDebugOverlay(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CDebugOverlay *__thiscall CDebugOverlay::CDebugOverlay(CDebugOverlay *this, unsigned int parent)
{
  int w; // [esp+8h] [ebp-8h] BYREF
  int h; // [esp+Ch] [ebp-4h] BYREF

  vgui::Panel::Panel(this, parent: nullptr, panelName: "CDebugOverlay");
  this->__vftable = (CDebugOverlay_vtbl *)&CDebugOverlay::`vftable';
  g_pVGuiSurface->GetScreenSize(this: g_pVGuiSurface, a2: &w, a3: &h);
  vgui::Panel::SetParent(this, newParent: parent);
  vgui::Panel::SetSize(this, wide: w, tall: h);
  vgui::Panel::SetPos(this, x: 0, y: 0);
  vgui::Panel::SetVisible(this, state: 0);
  vgui::Panel::SetCursor(this, cursor: 0);
  this->m_hFont = 0;
  this->m_LineSpacing = 13;
  vgui::Panel::SetFgColor(this, color: 0);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetScheme(this, tag: "ClientScheme");
  g_pVGui->AddTickSignal(this: g_pVGui, a2: this->_vpanel, a3: 250);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10181480
// Name: public: virtual void CDebugOverlay::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDebugOverlay::Paint(CDebugOverlay *this)
{
  OverlayText_t *i; // esi
  bool v3; // zf
  int v4; // edx
  int v5; // eax
  int r; // ebx
  IVDebugOverlay_vtbl *v7; // eax
  int v8; // eax
  Vector screenPos; // [esp+18h] [ebp-18h] BYREF
  int g; // [esp+24h] [ebp-Ch]
  int b; // [esp+28h] [ebp-8h]
  int a; // [esp+2Ch] [ebp-4h]

  for ( i = debugoverlay->GetFirst(this: debugoverlay); i != nullptr; i = debugoverlay->GetNext(
                                                                            this: debugoverlay,
                                                                            a2: i) )
  {
    if ( i != (OverlayText_t *)-28 )
    {
      v3 = !i->bUseOrigin;
      v4 = i->a;
      v5 = i->g;
      r = i->r;
      b = i->b;
      a = v4;
      g = v5;
      v7 = debugoverlay->__vftable;
      if ( v3 )
        v8 = ((int (__stdcall *)(_DWORD, _DWORD, Vector *))v7->ScreenPosition)(
               a1: LODWORD(i->flXPos),
               a2: LODWORD(i->flYPos),
               a3: &screenPos);
      else
        v8 = ((int (__stdcall *)(OverlayText_t *, Vector *))v7->ScreenPosition_2)(a1: i, a2: &screenPos);
      if ( v8 == 0 )
        g_pMatSystemSurface->DrawColoredText(
          this: g_pMatSystemSurface,
          a2: this->m_hFont,
          a3: (int)screenPos.x,
          a4: (int)(float)((float)(i->lineOffset * this->m_LineSpacing) + screenPos.y),
          a5: r,
          a6: g,
          a7: b,
          a8: a,
          a9: i->text);
    }
  }
  debugoverlay->ClearDeadOverlays(this: debugoverlay);
}

//------------------------------------------------------------------------------
// Address: 0x10181590
// Name: public: virtual void CDebugOverlayPanel::Create(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDebugOverlayPanel::Create(CDebugOverlayPanel *this, unsigned int parent)
{
  CDebugOverlay *v3; // eax

  v3 = (CDebugOverlay *)MemAlloc_Alloc(nSize: 0x154u);
  if ( v3 != nullptr )
    this->debugOverlayPanel = CDebugOverlay::CDebugOverlay(this: v3, parent);
  else
    this->debugOverlayPanel = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101815D0
// Name: void DebugDrawLine(class Vector const __near &,class Vector const __near &,int,int,int,bool,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DebugDrawLine(
        const Vector *vecAbsStart,
        const Vector *vecAbsEnd,
        int r,
        int g,
        int b,
        int test,
        float duration)
{
  float v7; // xmm1_4
  float v8[3]; // [esp+4h] [ebp-18h] BYREF
  _DWORD v9[3]; // [esp+10h] [ebp-Ch] BYREF

  v7 = vecAbsEnd->z + 0.1;
  v9[0] = LODWORD(vecAbsEnd->x);
  v9[1] = LODWORD(vecAbsEnd->y);
  *(float *)&v9[2] = v7;
  v8[0] = vecAbsStart->x;
  v8[1] = vecAbsStart->y;
  v8[2] = vecAbsStart->z + 0.1;
  ((void (__thiscall *)(IVDebugOverlay *, float *, _DWORD *, int, int, int, int, _DWORD))debugoverlay->AddLineOverlay)(
    a1: debugoverlay,
    a2: v8,
    a3: v9,
    a4: r,
    a5: g,
    a6: b,
    a7: test,
    a8: LODWORD(duration));
}
