// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/hud_flashbang.cpp
// Functions: 6
// ============================================================

#include "game\client\cstrike15\hud_flashbang.h"

//------------------------------------------------------------------------------
// Address: 0x10204C70
// Name: public: static char const __near * CHudFlashbang::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CHudFlashbang::GetPanelClassName()
{
  return "CHudFlashbang";
}

//------------------------------------------------------------------------------
// Address: 0x10204C80
// Name: public: CHudFlashbang::CHudFlashbang(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CHudFlashbang *__thiscall CHudFlashbang::CHudFlashbang(CHudFlashbang *this, const char *pName)
{
  vgui::PanelMessageMap *v3; // ebx
  PanelAnimationMap *v4; // ebx
  vgui::PanelKeyBindingMap *v5; // ebx
  IClientMode *ClientMode; // eax
  vgui::Panel *v7; // eax

  CHudElement::CHudElement(this, pElementName: pName);
  vgui::Panel::Panel(this: &this->vgui::Panel, parent: nullptr, panelName: "HudFlashbang");
  this->CHudElement::CGameEventListener::IGameEventListener2::__vftable = (CHudFlashbang_vtbl *)&CHudFlashbang::`vftable'{for `CHudElement'};
  this->vgui::Panel::vgui::IClientPanel::__vftable = (vgui::Panel_vtbl *)&CHudFlashbang::`vftable'{for `vgui::Panel'};
  if ( `CHudFlashbang::ChainToMap'::`2'::chained == 0 )
  {
    `CHudFlashbang::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CHudFlashbang");
    v3->pfnClassName = CHudFlashbang::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CHudFlashbang::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CHudFlashbang::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CHudFlashbang");
    v4->pfnClassName = CHudFlashbang::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CHudFlashbang::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CHudFlashbang::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CHudFlashbang");
    v5->pfnClassName = CHudFlashbang::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  ClientMode = GetClientMode();
  v7 = ClientMode->GetViewport(this: ClientMode);
  vgui::Panel::SetParent(this: &this->vgui::Panel, newParent: v7);
  this->m_iAdditiveWhiteID = 0;
  CTraceFilterSkipTwoEntities::SetPassEntity2(
    (CTraceFilterSkipTwoEntities *)this,
    pPassEntity2: (const IHandleEntity *)0x10);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10204D80
// Name: public: virtual struct vgui::PanelMessageMap __near * CHudFlashbang::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CHudFlashbang::GetMessageMap(CHudFlashbang *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CHudFlashbang::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudFlashbang::GetMessageMap'::`2'::s_pMap;
  `CHudFlashbang::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CHudFlashbang");
  `CHudFlashbang::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10204DB0
// Name: public: virtual struct PanelAnimationMap __near * CHudFlashbang::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CHudFlashbang::GetAnimMap(CHudFlashbang *this)
{
  return FindOrAddPanelAnimationMap(className: "CHudFlashbang");
}

//------------------------------------------------------------------------------
// Address: 0x10204DC0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CHudFlashbang::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CHudFlashbang::GetKBMap(CHudFlashbang *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CHudFlashbang::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudFlashbang::GetKBMap'::`2'::s_pMap;
  `CHudFlashbang::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CHudFlashbang");
  `CHudFlashbang::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10204DF0
// Name: Create_CHudFlashbang
// Source: json
//------------------------------------------------------------------------------
CHudFlashbang *__cdecl Create_CHudFlashbang()
{
  unsigned __int8 *v0; // esi

  v0 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 396);
  memset(dst: v0, value: 0, count: 0x18Cu);
  if ( v0 != nullptr )
    return CHudFlashbang::CHudFlashbang(this: (CHudFlashbang *)v0, pName: "CHudFlashbang");
  else
    return nullptr;
}
