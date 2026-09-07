// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/hud_weapon.cpp
// Functions: 10
// ============================================================

#include "game\client\hud_weapon.h"

//------------------------------------------------------------------------------
// Address: 0x101107B0
// Name: public: static char const __near * CHudWeapon::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CHudWeapon::GetPanelClassName()
{
  return "CHudWeapon";
}

//------------------------------------------------------------------------------
// Address: 0x101107C0
// Name: public: virtual void CHudWeapon::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudWeapon::ApplySchemeSettings(CHudWeapon *this, vgui::IScheme *scheme)
{
  CHud *Hud; // eax

  vgui::Panel::ApplySchemeSettings((vgui::Panel *)this, pScheme: (int)scheme);
  ((void (__thiscall *)(CHudWeapon *, _DWORD))this->CHudElement::CGameEventListener::IGameEventListener2::__vftable[3].OnSplitScreenStateChanged)(
    a1: this,
    a2: 0);
  Hud = GetHud(nSlot: -1);
  LODWORD(this->m_flAlpha) = CHud::FindElement(this: Hud, pName: "CHudCrosshair");
}

//------------------------------------------------------------------------------
// Address: 0x10110800
// Name: public: virtual void CHudWeapon::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudWeapon::PerformLayout(CHudWeapon *this)
{
  vgui::Panel *v2; // eax
  int w; // [esp+4h] [ebp-8h] BYREF
  int h; // [esp+8h] [ebp-4h] BYREF

  vgui::Panel::PerformLayout((vgui::Panel *)this);
  v2 = (vgui::Panel *)((int (__thiscall *)(CHudWeapon *))this->CHudElement::CGameEventListener::IGameEventListener2::__vftable[2].SetHud)(a1: this);
  vgui::Panel::GetSize(this: v2, wide: &w, tall: &h);
  vgui::Panel::SetPos((vgui::Panel *)this, x: 0, y: 0);
  vgui::Panel::SetSize((vgui::Panel *)this, wide: w, tall: h);
}

//------------------------------------------------------------------------------
// Address: 0x10110850
// Name: public: CHudWeapon::CHudWeapon(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CHudWeapon *__thiscall CHudWeapon::CHudWeapon(CHudWeapon *this, const char *pElementName)
{
  vgui::PanelMessageMap *v3; // ebx
  PanelAnimationMap *v4; // ebx
  vgui::PanelKeyBindingMap *v5; // ebx
  IClientMode *ClientMode; // eax
  vgui::Panel *v7; // eax

  CHudElement::CHudElement(this, pElementName);
  vgui::Panel::Panel(this: &this->vgui::Panel, parent: nullptr, panelName: "HudWeapon");
  this->CHudElement::CGameEventListener::IGameEventListener2::__vftable = (CHudWeapon_vtbl *)&CHudWeapon::`vftable'{for `CHudElement'};
  this->vgui::Panel::vgui::IClientPanel::__vftable = (vgui::Panel_vtbl *)&CHudWeapon::`vftable'{for `vgui::Panel'};
  if ( `CHudWeapon::ChainToMap'::`2'::chained == 0 )
  {
    `CHudWeapon::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CHudWeapon");
    v3->pfnClassName = CHudWeapon::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CHudWeapon::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CHudWeapon::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CHudWeapon");
    v4->pfnClassName = CHudWeapon::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CHudWeapon::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CHudWeapon::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CHudWeapon");
    v5->pfnClassName = CHudWeapon::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  ClientMode = GetClientMode();
  v7 = ClientMode->GetViewport(this: ClientMode);
  vgui::Panel::SetParent(this: &this->vgui::Panel, newParent: v7);
  this->m_pCrosshair = nullptr;
  CTraceFilterSkipTwoEntities::SetPassEntity2(
    (CTraceFilterSkipTwoEntities *)this,
    pPassEntity2: (const IHandleEntity *)1);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10110960
// Name: public: virtual struct vgui::PanelMessageMap __near * CHudWeapon::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CHudWeapon::GetMessageMap(CHudWeapon *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CHudWeapon::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudWeapon::GetMessageMap'::`2'::s_pMap;
  `CHudWeapon::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CHudWeapon");
  `CHudWeapon::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10110990
// Name: public: virtual struct PanelAnimationMap __near * CHudWeapon::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CHudWeapon::GetAnimMap(CHudWeapon *this)
{
  return FindOrAddPanelAnimationMap(className: "CHudWeapon");
}

//------------------------------------------------------------------------------
// Address: 0x101109A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CHudWeapon::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CHudWeapon::GetKBMap(CHudWeapon *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CHudWeapon::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudWeapon::GetKBMap'::`2'::s_pMap;
  `CHudWeapon::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CHudWeapon");
  `CHudWeapon::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10110A10
// Name: public: virtual void CHudWeapon::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudWeapon::Paint(CHudWeapon *this)
{
  C_BasePlayer *LocalPlayer; // esi
  IMDLCache *v3; // edi
  int v4; // eax
  float m_flAlpha; // ecx

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
  {
    v3 = mdlcache;
    mdlcache->BeginLock(this: mdlcache);
    v4 = (int)LocalPlayer->GetActiveWeapon(this: LocalPlayer);
    if ( v4 != 0 )
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 1384))(a1: v4);
    }
    else
    {
      m_flAlpha = this->m_flAlpha;
      if ( m_flAlpha != 0.0 )
        CHudCrosshair::ResetCrosshair(this: (CHudCrosshair *)LODWORD(m_flAlpha));
    }
    v3->EndLock(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110A70
// Name: Create_CHudWeapon
// Source: json
//------------------------------------------------------------------------------
CHudWeapon *__cdecl Create_CHudWeapon()
{
  unsigned __int8 *v0; // esi

  v0 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 396);
  memset(dst: v0, value: 0, count: 0x18Cu);
  if ( v0 != nullptr )
    return CHudWeapon::CHudWeapon(this: (CHudWeapon *)v0, pElementName: "CHudWeapon");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10110AB0
// Name: public: virtual bool CHudWeapon::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHudWeapon::ShouldDraw(CHudWeapon *this)
{
  if ( crosshair.m_pParent == nullptr
    || crosshair.m_pParent->m_Value.m_nValue == 0
    || sfcrosshair.m_pParent != nullptr && sfcrosshair.m_pParent->m_Value.m_nValue != 0 )
  {
    return 0;
  }
  else
  {
    return CHudElement::ShouldDraw(this);
  }
}
