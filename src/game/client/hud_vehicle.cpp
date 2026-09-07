// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/hud_vehicle.cpp
// Functions: 9
// ============================================================

#include "game\client\hud_vehicle.h"

//------------------------------------------------------------------------------
// Address: 0x10110520
// Name: public: static char const __near * CHudVehicle::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CHudVehicle::GetPanelClassName()
{
  return "CHudVehicle";
}

//------------------------------------------------------------------------------
// Address: 0x10110530
// Name: public: CHudVehicle::CHudVehicle(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CHudVehicle *__thiscall CHudVehicle::CHudVehicle(CHudVehicle *this, const char *pElementName)
{
  vgui::PanelMessageMap *v3; // ebx
  PanelAnimationMap *v4; // ebx
  vgui::PanelKeyBindingMap *v5; // ebx
  IClientMode *ClientMode; // eax
  vgui::Panel *v7; // eax

  CHudElement::CHudElement(this, pElementName);
  vgui::Panel::Panel(this: &this->vgui::Panel, parent: nullptr, panelName: "HudVehicle");
  this->CHudElement::CGameEventListener::IGameEventListener2::__vftable = (CHudVehicle_vtbl *)&CHudVehicle::`vftable'{for `CHudElement'};
  this->vgui::Panel::vgui::IClientPanel::__vftable = (vgui::Panel_vtbl *)&CHudVehicle::`vftable'{for `vgui::Panel'};
  if ( `CHudVehicle::ChainToMap'::`2'::chained == 0 )
  {
    `CHudVehicle::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CHudVehicle");
    v3->pfnClassName = CHudVehicle::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CHudVehicle::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CHudVehicle::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CHudVehicle");
    v4->pfnClassName = CHudVehicle::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CHudVehicle::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CHudVehicle::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CHudVehicle");
    v5->pfnClassName = CHudVehicle::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  ClientMode = GetClientMode();
  v7 = ClientMode->GetViewport(this: ClientMode);
  vgui::Panel::SetParent(this: &this->vgui::Panel, newParent: v7);
  CTraceFilterSkipTwoEntities::SetPassEntity2(
    (CTraceFilterSkipTwoEntities *)this,
    pPassEntity2: (const IHandleEntity *)0x210);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10110630
// Name: public: virtual struct vgui::PanelMessageMap __near * CHudVehicle::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CHudVehicle::GetMessageMap(CHudVehicle *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CHudVehicle::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudVehicle::GetMessageMap'::`2'::s_pMap;
  `CHudVehicle::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CHudVehicle");
  `CHudVehicle::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10110660
// Name: public: virtual struct PanelAnimationMap __near * CHudVehicle::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CHudVehicle::GetAnimMap(CHudVehicle *this)
{
  return FindOrAddPanelAnimationMap(className: "CHudVehicle");
}

//------------------------------------------------------------------------------
// Address: 0x10110670
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CHudVehicle::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CHudVehicle::GetKBMap(CHudVehicle *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CHudVehicle::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudVehicle::GetKBMap'::`2'::s_pMap;
  `CHudVehicle::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CHudVehicle");
  `CHudVehicle::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101106A0
// Name: Create_CHudVehicle
// Source: json
//------------------------------------------------------------------------------
CHudVehicle *__cdecl Create_CHudVehicle()
{
  unsigned __int8 *v0; // esi

  v0 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 392);
  memset(dst: v0, value: 0, count: 0x188u);
  if ( v0 != nullptr )
    return CHudVehicle::CHudVehicle(this: (CHudVehicle *)v0, pElementName: "CHudVehicle");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101106E0
// Name: private: class IClientVehicle __near * CHudVehicle::GetLocalPlayerVehicle(void)
// Source: json
//------------------------------------------------------------------------------
IClientVehicle *__thiscall CHudVehicle::GetLocalPlayerVehicle(CHudVehicle *this)
{
  C_BasePlayer *LocalPlayer; // eax
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax
  IHandleEntity *m_pEntity; // eax

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer == nullptr )
    return nullptr;
  m_Index = LocalPlayer->m_hVehicle.m_Index;
  if ( m_Index == -1 )
    return nullptr;
  v3 = (unsigned __int16)m_Index;
  v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  v5 = HIWORD(m_Index);
  if ( v4->m_SerialNumber == v5
    && v4->m_pEntity != nullptr
    && (v6 = v3, v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5, v8 = &g_pEntityList->m_EntPtrArray[v6], v7)
    && (m_pEntity = v8->m_pEntity) != nullptr )
  {
    return ((IClientVehicle *(__thiscall *)(IHandleEntity *))m_pEntity->__vftable[31].dtr_IHandleEntity)(a1: m_pEntity);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10110740
// Name: public: virtual bool CHudVehicle::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHudVehicle::ShouldDraw(CHudVehicle *this)
{
  IClientVehicle *LocalPlayerVehicle; // eax
  _BYTE *v3; // eax

  LocalPlayerVehicle = CHudVehicle::GetLocalPlayerVehicle(this);
  if ( LocalPlayerVehicle == nullptr )
    return 0;
  v3 = __RTDynamicCast(
         inptr: LocalPlayerVehicle,
         VfDelta: 0,
         SrcType: &IClientVehicle `RTTI Type Descriptor',
         TargetType: &C_PropVehicleDriveable `RTTI Type Descriptor',
         isReference: 0);
  if ( v3 != nullptr && (v3[3320] != 0 || v3[3321] != 0) )
    return 0;
  else
    return CHudElement::ShouldDraw(this);
}

//------------------------------------------------------------------------------
// Address: 0x10110790
// Name: public: virtual void CHudVehicle::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudVehicle::Paint(CHudVehicle *this)
{
  IClientVehicle *LocalPlayerVehicle; // eax

  LocalPlayerVehicle = CHudVehicle::GetLocalPlayerVehicle(this: (CHudVehicle *)((char *)this - 56));
  if ( LocalPlayerVehicle != nullptr )
    LocalPlayerVehicle->DrawHudElements(this: LocalPlayerVehicle);
}
