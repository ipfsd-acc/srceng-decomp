// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/cs_hud_scope.cpp
// Functions: 10
// ============================================================

#include "game\client\cstrike15\cs_hud_scope.h"

//------------------------------------------------------------------------------
// Address: 0x10202C00
// Name: public: static char const __near * CHudScope::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CHudScope::GetPanelClassName()
{
  return "CHudScope";
}

//------------------------------------------------------------------------------
// Address: 0x10202C10
// Name: public: virtual void CHudScope::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudScope::Init(CHudScope *this)
{
  int v2; // eax
  int v3; // eax

  v2 = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
  this->m_hKeyBindingsContext = v2;
  g_pVGuiSurface->DrawSetTextureFile(this: g_pVGuiSurface, a2: v2, a3: "sprites/scope_arc", a4: 1, a5: false);
  v3 = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
  this->_vpanel = v3;
  g_pVGuiSurface->DrawSetTextureFile(this: g_pVGuiSurface, a2: v3, a3: "overlays/scope_lens", a4: 1, a5: false);
}

//------------------------------------------------------------------------------
// Address: 0x10202C80
// Name: protected: virtual void CHudScope::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudScope::ApplySchemeSettings(CHudScope *this, vgui::IScheme *scheme)
{
  int screenWide; // [esp+4h] [ebp-4h] BYREF

  vgui::Panel::ApplySchemeSettings(this, pScheme: (int)scheme);
  this->SetPaintBackgroundEnabled(this, a2: false);
  this->SetPaintBorderEnabled(this, a2: false);
  GetHudSize(w: &screenWide, h: (int *)&scheme);
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: screenWide, tall: (int)scheme);
}

//------------------------------------------------------------------------------
// Address: 0x10202CE0
// Name: public: CHudScope::CHudScope(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CHudScope *__thiscall CHudScope::CHudScope(CHudScope *this, const char *pElementName)
{
  vgui::PanelMessageMap *v3; // ebx
  PanelAnimationMap *v4; // ebx
  vgui::PanelKeyBindingMap *v5; // ebx
  IClientMode *ClientMode; // eax
  vgui::Panel *v7; // eax

  vgui::Panel::Panel(this, parent: nullptr, panelName: "HudScope");
  CHudElement::CHudElement(this: &this->CHudElement, pElementName);
  this->vgui::Panel::vgui::IClientPanel::__vftable = (CHudScope_vtbl *)&CHudScope::`vftable'{for `vgui::Panel'};
  this->CHudElement::CGameEventListener::IGameEventListener2::__vftable = (CHudElement_vtbl *)&CHudScope::`vftable'{for `CHudElement'};
  if ( `CHudScope::ChainToMap'::`2'::chained == 0 )
  {
    `CHudScope::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CHudScope");
    v3->pfnClassName = CHudScope::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CHudScope::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CHudScope::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CHudScope");
    v4->pfnClassName = CHudScope::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CHudScope::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CHudScope::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CHudScope");
    v5->pfnClassName = CHudScope::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  CMaterialReference::CMaterialReference(
    this: &this->m_ScopeMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  CMaterialReference::CMaterialReference(
    this: &this->m_DustOverlayMaterial,
    pMaterialName: nullptr,
    pTextureGroupName: nullptr,
    bComplain: true);
  ClientMode = GetClientMode();
  v7 = ClientMode->GetViewport(this: ClientMode);
  vgui::Panel::SetParent(this, newParent: v7);
  CTraceFilterSkipTwoEntities::SetPassEntity2(
    this: (CTraceFilterSkipTwoEntities *)&this->CHudElement,
    pPassEntity2: (const IHandleEntity *)0x10);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10202E10
// Name: public: virtual struct vgui::PanelMessageMap __near * CHudScope::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CHudScope::GetMessageMap(CHudScope *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CHudScope::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudScope::GetMessageMap'::`2'::s_pMap;
  `CHudScope::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CHudScope");
  `CHudScope::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10202E40
// Name: public: virtual struct PanelAnimationMap __near * CHudScope::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CHudScope::GetAnimMap(CHudScope *this)
{
  return FindOrAddPanelAnimationMap(className: "CHudScope");
}

//------------------------------------------------------------------------------
// Address: 0x10202E50
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CHudScope::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CHudScope::GetKBMap(CHudScope *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CHudScope::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudScope::GetKBMap'::`2'::s_pMap;
  `CHudScope::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CHudScope");
  `CHudScope::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10202ED0
// Name: protected: virtual void CHudScope::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudScope::Paint(CHudScope *this)
{
  C_BasePlayer *LocalPlayer; // eax
  C_BasePlayer *v2; // eax
  C_BasePlayer *v3; // esi
  C_WeaponCSBase *ActiveCSWeapon; // edi
  int v5; // ebx
  int v6; // esi
  int v7; // edi
  void (__thiscall *DrawTexturedPolygon)(vgui::ISurface *, int, FontVertex_t *, bool); // edx
  int v9; // esi
  void (__thiscall *v10)(vgui::ISurface *, int, FontVertex_t *, bool); // edx
  FontVertex_t vert[4]; // [esp+4h] [ebp-68h] BYREF
  float v12; // [esp+44h] [ebp-28h]
  float v13; // [esp+48h] [ebp-24h]
  int x1; // [esp+4Ch] [ebp-20h]
  float v15; // [esp+50h] [ebp-1Ch]
  int x2; // [esp+54h] [ebp-18h]
  int y2; // [esp+58h] [ebp-14h]
  float v18; // [esp+5Ch] [ebp-10h]
  float v19; // [esp+60h] [ebp-Ch]
  int screenWide; // [esp+64h] [ebp-8h] BYREF
  int screenTall; // [esp+68h] [ebp-4h] BYREF

  v19 = *(float *)&this;
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  v2 = (C_BasePlayer *)__RTDynamicCast(
                         inptr: LocalPlayer,
                         VfDelta: 0,
                         SrcType: &C_BasePlayer `RTTI Type Descriptor',
                         TargetType: &C_CSPlayer `RTTI Type Descriptor',
                         isReference: 0);
  v3 = v2;
  if ( v2 != nullptr )
  {
    ActiveCSWeapon = (C_WeaponCSBase *)C_CSPlayer::GetActiveCSWeapon(this: v2);
    if ( ActiveCSWeapon != nullptr )
    {
      *(float *)&y2 = v3->GetFOV(this: v3);
      x2 = v3->GetDefaultFOV(this: v3);
      if ( *(float *)&y2 != (double)x2
        && C_WeaponCSBase::GetCSWpnData(this: ActiveCSWeapon)->m_WeaponType == WEAPONTYPE_SNIPER_RIFLE )
      {
        GetHudSize(w: &screenWide, h: &screenTall);
        v5 = screenTall / 16;
        y2 = screenTall - screenTall / 16;
        x1 = screenTall / 16 + (screenWide - screenTall) / 2;
        x2 = screenWide - x1;
        v6 = screenWide / 2;
        v7 = screenTall / 2;
        g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: *(_DWORD *)(LODWORD(v19) + 404));
        g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
        vert[0].m_Position.y = (float)(2 * v7);
        vert[1].m_Position.y = vert[0].m_Position.y;
        vert[0].m_Position.x = (float)(2 * v6);
        vert[0].m_TexCoord.x = 0.99804688;
        vert[0].m_TexCoord.y = 0.001953125;
        vert[1].m_Position.x = (float)0;
        vert[1].m_TexCoord.x = 0.001953125;
        vert[1].m_TexCoord.y = 0.001953125;
        vert[2].m_Position.x = (float)0;
        vert[2].m_Position.y = (float)0;
        vert[2].m_TexCoord.x = 0.001953125;
        vert[2].m_TexCoord.y = 0.99804688;
        vert[3].m_Position.x = vert[0].m_Position.x;
        vert[3].m_Position.y = (float)0;
        vert[3].m_TexCoord.x = 0.99804688;
        vert[3].m_TexCoord.y = 0.99804688;
        g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 4, a3: vert, a4: true);
        g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 0, a3: 0, a4: 0, a5: 255);
        g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: 0, a3: v7, a4: screenWide, a5: v7);
        g_pVGuiSurface->DrawLine(this: g_pVGuiSurface, a2: v6, a3: 0, a4: v6, a5: screenTall);
        g_pVGuiSurface->DrawSetTexture(this: g_pVGuiSurface, a2: *(_DWORD *)(LODWORD(v19) + 400));
        vert[0].m_Position.y = (float)v7;
        vert[1].m_Position.y = (float)v7;
        v18 = (float)v7;
        vert[0].m_Position.x = (float)v6;
        vert[0].m_TexCoord.x = 0.001953125;
        vert[0].m_TexCoord.y = 0.001953125;
        vert[1].m_Position.x = (float)x2;
        vert[1].m_TexCoord.x = 0.99804688;
        vert[1].m_TexCoord.y = 0.001953125;
        vert[2].m_Position.x = (float)x2;
        vert[2].m_Position.y = (float)y2;
        vert[2].m_TexCoord.x = 0.99804688;
        vert[2].m_TexCoord.y = 0.99804688;
        vert[3].m_Position.x = (float)v6;
        vert[3].m_Position.y = (float)y2;
        vert[3].m_TexCoord.x = 0.001953125;
        vert[3].m_TexCoord.y = 0.99804688;
        DrawTexturedPolygon = g_pVGuiSurface->DrawTexturedPolygon;
        v19 = (float)v6;
        v15 = (float)x2;
        v13 = (float)y2;
        DrawTexturedPolygon(this: g_pVGuiSurface, a2: 4, a3: vert, a4: true);
        vert[1].m_Position.y = (float)v5;
        v12 = (float)v5;
        vert[0].m_Position.y = (float)v5;
        vert[0].m_Position.x = (float)(v6 - 1);
        vert[0].m_TexCoord.x = 0.001953125;
        vert[0].m_TexCoord.y = 0.99804688;
        vert[1].m_Position.x = v15;
        vert[1].m_TexCoord.x = 0.99804688;
        vert[1].m_TexCoord.y = 0.99804688;
        vert[2].m_Position.x = v15;
        vert[2].m_Position.y = (float)(v7 + 1);
        vert[2].m_TexCoord.x = 0.99804688;
        vert[2].m_TexCoord.y = 0.001953125;
        vert[3].m_Position.x = vert[0].m_Position.x;
        vert[3].m_Position.y = vert[2].m_Position.y;
        vert[3].m_TexCoord.x = 0.001953125;
        vert[3].m_TexCoord.y = 0.001953125;
        g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 4, a3: vert, a4: true);
        v9 = x1;
        vert[1].m_Position.x = v19;
        vert[2].m_Position.x = v19;
        vert[0].m_Position.x = (float)x1;
        vert[0].m_Position.y = v18;
        vert[0].m_TexCoord.x = 0.99804688;
        vert[0].m_TexCoord.y = 0.001953125;
        vert[1].m_Position.y = v18;
        vert[1].m_TexCoord.x = 0.001953125;
        vert[1].m_TexCoord.y = 0.001953125;
        vert[2].m_Position.y = v13;
        vert[2].m_TexCoord.x = 0.001953125;
        vert[2].m_TexCoord.y = 0.99804688;
        vert[3].m_Position.x = (float)x1;
        vert[3].m_Position.y = v13;
        vert[3].m_TexCoord.x = 0.99804688;
        vert[3].m_TexCoord.y = 0.99804688;
        v10 = g_pVGuiSurface->DrawTexturedPolygon;
        *(float *)&x1 = (float)x1;
        v10(this: g_pVGuiSurface, a2: 4, a3: vert, a4: true);
        vert[0].m_Position.y = v12;
        LODWORD(vert[0].m_Position.x) = x1;
        vert[0].m_TexCoord.x = 0.99804688;
        vert[0].m_TexCoord.y = 0.99804688;
        vert[1].m_Position.x = v19;
        vert[1].m_Position.y = v12;
        vert[2].m_Position.x = v19;
        vert[1].m_TexCoord.x = 0.001953125;
        vert[1].m_TexCoord.y = 0.99804688;
        vert[2].m_Position.y = v18;
        vert[2].m_TexCoord.x = 0.001953125;
        vert[2].m_TexCoord.y = 0.001953125;
        LODWORD(vert[3].m_Position.x) = x1;
        vert[3].m_Position.y = v18;
        vert[3].m_TexCoord.x = 0.99804688;
        vert[3].m_TexCoord.y = 0.001953125;
        g_pVGuiSurface->DrawTexturedPolygon(this: g_pVGuiSurface, a2: 4, a3: vert, a4: true);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: 0, a4: screenWide, a5: v5);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: y2, a4: screenWide, a5: screenTall);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 0, a3: v5, a4: v9, a5: screenTall);
        g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: x2, a3: v5, a4: screenWide, a5: screenTall);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102033C0
// Name: Create_CHudScope
// Source: json
//------------------------------------------------------------------------------
CHudElement *__cdecl Create_CHudScope()
{
  unsigned __int8 *v0; // esi
  CHudScope *v1; // eax

  v0 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 408);
  memset(dst: v0, value: 0, count: 0x198u);
  if ( v0 != nullptr && (v1 = CHudScope::CHudScope(this: (CHudScope *)v0, pElementName: "CHudScope")) != nullptr )
    return &v1->CHudElement;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10374CD0
// Name: public: virtual void CHudScope::LevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudScope::LevelInit(vgui::TextEntry *this)
{
  this->Repaint(this);
}
