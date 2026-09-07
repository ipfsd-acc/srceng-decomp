// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/cs_hud_weaponselection.cpp
// Functions: 111
// ============================================================

#include "game\client\cstrike15\cs_hud_weaponselection.h"

//------------------------------------------------------------------------------
// Address: 0x10203410
// Name: public: static char const __near * CHudWeaponSelection::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CHudWeaponSelection::GetPanelClassName()
{
  return "CHudWeaponSelection";
}

//------------------------------------------------------------------------------
// Address: 0x10203420
// Name: private: static void __near * CHudWeaponSelection::GetVar_m_hNumberFont(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::Panel_RegisterMap *__cdecl CHudWeaponSelection::GetVar_m_hNumberFont(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1].m_RegisterClass;
  else
    return (vgui::Panel::Panel_RegisterMap *)404;
}

//------------------------------------------------------------------------------
// Address: 0x10203440
// Name: private: static void __near * CHudWeaponSelection::GetVar_m_hTextFont(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::PanelMessageFunc_OnDelete *__cdecl CHudWeaponSelection::GetVar_m_hTextFont(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1].m_OnDelete_register;
  else
    return (vgui::Panel::PanelMessageFunc_OnDelete *)412;
}

//------------------------------------------------------------------------------
// Address: 0x10203460
// Name: private: static void __near * CHudWeaponSelection::GetVar_m_flSmallBoxSize(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::NAV_DIRECTION *__cdecl CHudWeaponSelection::GetVar_m_flSmallBoxSize(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1].m_LastNavDirection;
  else
    return (vgui::Panel::NAV_DIRECTION *)420;
}

//------------------------------------------------------------------------------
// Address: 0x10203480
// Name: private: static void __near * CHudWeaponSelection::GetVar_m_flLargeBoxWide(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::PanelMessageFunc_InternalMouseDoublePressed *__cdecl CHudWeaponSelection::GetVar_m_flLargeBoxWide(
        vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1].m_InternalMouseDoublePressed_register;
  else
    return (vgui::Panel::PanelMessageFunc_InternalMouseDoublePressed *)428;
}

//------------------------------------------------------------------------------
// Address: 0x102034A0
// Name: private: static void __near * CHudWeaponSelection::GetVar_m_flLargeBoxTall(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel::PanelMessageFunc_InternalKeyFocusTicked *__cdecl CHudWeaponSelection::GetVar_m_flLargeBoxTall(
        vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1].m_InternalKeyFocusTicked_register;
  else
    return (vgui::Panel::PanelMessageFunc_InternalKeyFocusTicked *)436;
}

//------------------------------------------------------------------------------
// Address: 0x102034C0
// Name: private: static void __near * CHudWeaponSelection::GetVar_m_flBoxGap(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
Color *__cdecl CHudWeaponSelection::GetVar_m_flBoxGap(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1].m_clrDragFrame;
  else
    return (Color *)444;
}

//------------------------------------------------------------------------------
// Address: 0x102034E0
// Name: private: static void __near * CHudWeaponSelection::GetVar_m_flSelectionNumberXPos(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Tooltip **__cdecl CHudWeaponSelection::GetVar_m_flSelectionNumberXPos(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1].m_pTooltips;
  else
    return (vgui::Tooltip **)452;
}

//------------------------------------------------------------------------------
// Address: 0x10203500
// Name: private: static void __near * CHudWeaponSelection::GetVar_m_flSelectionNumberYPos(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl CHudWeaponSelection::GetVar_m_flSelectionNumberYPos(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1].m_lLastDoublePressTime;
  else
    return (void *)460;
}

//------------------------------------------------------------------------------
// Address: 0x10203520
// Name: private: static void __near * CHudWeaponSelection::GetVar_m_flIconXPos(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::KeyBindingContextHandle_t *__cdecl CHudWeaponSelection::GetVar_m_flIconXPos(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1].m_hKeyBindingsContext;
  else
    return (vgui::KeyBindingContextHandle_t *)468;
}

//------------------------------------------------------------------------------
// Address: 0x10203540
// Name: private: static void __near * CHudWeaponSelection::GetVar_m_flIconYPos(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlString *__cdecl CHudWeaponSelection::GetVar_m_flIconYPos(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1]._panelName;
  else
    return (CUtlString *)476;
}

//------------------------------------------------------------------------------
// Address: 0x10203560
// Name: private: static void __near * CHudWeaponSelection::GetVar_m_flTextYPos(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl CHudWeaponSelection::GetVar_m_flTextYPos(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1]._panelName.m_Storage.m_Memory.m_nGrowSize;
  else
    return (void *)484;
}

//------------------------------------------------------------------------------
// Address: 0x10203580
// Name: private: static void __near * CHudWeaponSelection::GetVar_m_flAlphaOverride(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::IBorder **__cdecl CHudWeaponSelection::GetVar_m_flAlphaOverride(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1]._border;
  else
    return (vgui::IBorder **)492;
}

//------------------------------------------------------------------------------
// Address: 0x102035A0
// Name: private: static void __near * CHudWeaponSelection::GetVar_m_flSelectionAlphaOverride(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::Dar<unsigned long> *__cdecl CHudWeaponSelection::GetVar_m_flSelectionAlphaOverride(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1]._actionSignalTargetDar;
  else
    return (vgui::Dar<unsigned long> *)500;
}

//------------------------------------------------------------------------------
// Address: 0x102035C0
// Name: private: static void __near * CHudWeaponSelection::GetVar_m_TextColor(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CHudWeaponSelection::GetVar_m_TextColor(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return (int)&panel[1]._actionSignalTargetDar.m_Memory.m_nAllocationCount + 1;
  else
    return 505;
}

//------------------------------------------------------------------------------
// Address: 0x102035E0
// Name: private: static void __near * CHudWeaponSelection::GetVar_m_NumberColor(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CHudWeaponSelection::GetVar_m_NumberColor(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return (int)&panel[1]._actionSignalTargetDar.m_Memory.m_nGrowSize + 2;
  else
    return 510;
}

//------------------------------------------------------------------------------
// Address: 0x10203600
// Name: private: static void __near * CHudWeaponSelection::GetVar_m_EmptyBoxColor(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CHudWeaponSelection::GetVar_m_EmptyBoxColor(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return (int)&panel[1]._actionSignalTargetDar.m_Size + 3;
  else
    return 515;
}

//------------------------------------------------------------------------------
// Address: 0x10203620
// Name: private: static void __near * CHudWeaponSelection::GetVar_m_BoxColor(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int> > *__cdecl CHudWeaponSelection::GetVar_m_BoxColor(
        vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1].m_OverridableColorEntries;
  else
    return (CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int> > *)520;
}

//------------------------------------------------------------------------------
// Address: 0x10203640
// Name: private: static void __near * CHudWeaponSelection::GetVar_m_SelectedBoxColor(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CHudWeaponSelection::GetVar_m_SelectedBoxColor(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return (int)&panel[1].m_OverridableColorEntries.m_Memory.m_nAllocationCount + 1;
  else
    return 525;
}

//------------------------------------------------------------------------------
// Address: 0x10203660
// Name: private: static void __near * CHudWeaponSelection::GetVar_m_flWeaponPickupGrowTime(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl CHudWeaponSelection::GetVar_m_flWeaponPickupGrowTime(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1].m_OverridableColorEntries.m_Size;
  else
    return (void *)532;
}

//------------------------------------------------------------------------------
// Address: 0x10203680
// Name: private: static void __near * CHudWeaponSelection::GetVar_m_flTextScan(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
Color *__cdecl CHudWeaponSelection::GetVar_m_flTextScan(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1]._fgColor;
  else
    return (Color *)540;
}

//------------------------------------------------------------------------------
// Address: 0x102036A0
// Name: private: static void __near * CHudWeaponSelection::GetVar_m_iMaxSlots(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlHandle<vgui::BuildGroup> *__cdecl CHudWeaponSelection::GetVar_m_iMaxSlots(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return &panel[1]._buildGroup;
  else
    return (CUtlHandle<vgui::BuildGroup> *)548;
}

//------------------------------------------------------------------------------
// Address: 0x102036C0
// Name: private: static void __near * CHudWeaponSelection::GetVar_m_bPlaySelectionSounds(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CHudWeaponSelection::GetVar_m_bPlaySelectionSounds(vgui::Panel *panel)
{
  if ( panel != nullptr )
    return (int)&panel[1].m_nPinDeltaX + 1;
  else
    return 553;
}

//------------------------------------------------------------------------------
// Address: 0x102036E0
// Name: public: virtual void CHudWeaponSelection::OnWeaponPickup(class C_BaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudWeaponSelection::OnWeaponPickup(CHudWeaponSelection *this, C_BaseCombatWeapon *pWeapon)
{
  void *v2; // eax
  CSWeaponID v3; // eax
  CCSWeaponInfo *WeaponInfo; // eax
  CHud *Hud; // eax
  SFItemHistory *Element; // eax

  v2 = __RTDynamicCast(
         inptr: pWeapon,
         VfDelta: 0,
         SrcType: &C_BaseCombatWeapon `RTTI Type Descriptor',
         TargetType: &C_WeaponCSBase `RTTI Type Descriptor',
         isReference: 0);
  if ( v2 != nullptr )
  {
    v3 = (*(int (__thiscall **)(void *))(*(_DWORD *)v2 + 1492))(a1: v2);
    WeaponInfo = GetWeaponInfo(weaponID: v3);
    if ( WeaponInfo != nullptr && WeaponInfo->m_WeaponType != WEAPONTYPE_GRENADE )
    {
      Hud = GetHud(nSlot: -1);
      Element = (SFItemHistory *)CHud::FindElement(this: Hud, pName: "SFItemHistory");
      if ( Element != nullptr )
        SFItemHistory::AddToHistory(this: Element, pWeapon);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10203750
// Name: protected: virtual bool CHudWeaponSelection::IsHudMenuTakingInput(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
BOOL __thiscall CHudWeaponSelection::IsHudMenuTakingInput(CHudWeaponSelection *this)
{
  return CBaseHudWeaponSelection::IsHudMenuTakingInput(this);
}

//------------------------------------------------------------------------------
// Address: 0x10203760
// Name: public: virtual bool CHudWeaponSelection::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHudWeaponSelection::ShouldDraw(CHudWeaponSelection *this)
{
  if ( C_BasePlayer::GetLocalPlayer(nSlot: -1) == nullptr )
  {
    if ( this->IsInSelectionMode(this) )
      this->HideSelection(this);
  }
  else if ( CHudElement::ShouldDraw(this) != 0 )
  {
    return this->m_bSelectionVisible;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x102037A0
// Name: protected: virtual void CHudWeaponSelection::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudWeaponSelection::ApplySchemeSettings(CHudWeaponSelection *this, vgui::IScheme *pScheme)
{
  int x; // [esp+4h] [ebp-Ch] BYREF
  int screenWide; // [esp+8h] [ebp-8h] BYREF
  int y; // [esp+Ch] [ebp-4h] BYREF

  vgui::Panel::ApplySchemeSettings((vgui::Panel *)this, (int)pScheme);
  ((void (__thiscall *)(CHudWeaponSelection *, _DWORD))this->CBaseHudWeaponSelection::CHudElement::CGameEventListener::IGameEventListener2::__vftable[1].HideSelection)(
    a1: this,
    a2: 0);
  vgui::Panel::GetPos((vgui::Panel *)this, &x, &y);
  GetHudSize(w: &screenWide, h: (int *)&pScheme);
  vgui::Panel::SetBounds((vgui::Panel *)this, x: 0, y, wide: screenWide, tall: (int)pScheme - y);
}

//------------------------------------------------------------------------------
// Address: 0x10203800
// Name: public: virtual void CHudWeaponSelection::OpenSelection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudWeaponSelection::OpenSelection(CHudWeaponSelection *this)
{
  IClientMode *ClientMode; // eax
  vgui::AnimationController *v2; // eax

  CBaseHudWeaponSelection::OpenSelection(this);
  ClientMode = GetClientMode();
  v2 = ClientMode->GetViewportAnimationController(this: ClientMode);
  vgui::AnimationController::StartAnimationSequence(this: v2, sequenceName: "OpenWeaponSelectionMenu");
}

//------------------------------------------------------------------------------
// Address: 0x10203820
// Name: public: virtual void CHudWeaponSelection::HideSelection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudWeaponSelection::HideSelection(CHudWeaponSelection *this)
{
  IClientMode *ClientMode; // eax
  vgui::AnimationController *v2; // eax

  CBaseHudWeaponSelection::HideSelection(this);
  ClientMode = GetClientMode();
  v2 = ClientMode->GetViewportAnimationController(this: ClientMode);
  vgui::AnimationController::StartAnimationSequence(this: v2, sequenceName: "CloseWeaponSelectionMenu");
}

//------------------------------------------------------------------------------
// Address: 0x10203840
// Name: private: class C_BaseCombatWeapon __near * CHudWeaponSelection::FindNextWeaponInWeaponSelection(int,int,enum CHudWeaponSelection::WEAPON_SELECTION_MODE)
// Source: json
//------------------------------------------------------------------------------
C_BaseCombatWeapon *__thiscall CHudWeaponSelection::FindNextWeaponInWeaponSelection(
        CHudWeaponSelection *this,
        int iCurrentSlot,
        int iCurrentPosition,
        CHudWeaponSelection::WEAPON_SELECTION_MODE selectionMode)
{
  C_BasePlayer *LocalPlayer; // eax
  int v5; // edx
  int v7; // ebx
  C_BaseCombatWeapon *v8; // eax
  C_BaseCombatWeapon *v9; // esi
  C_WeaponCSBase *v10; // eax
  C_WeaponCSBase *v11; // edi
  bool v12; // al
  int v13; // edi
  int v14; // eax
  C_BasePlayer *pPlayer; // [esp+0h] [ebp-10h]
  C_BaseCombatWeapon *pNextWeapon; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  int iLowestNextPosition; // [esp+Ch] [ebp-4h]

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  v5 = 0;
  pPlayer = LocalPlayer;
  if ( LocalPlayer == nullptr )
    return nullptr;
  pNextWeapon = nullptr;
  v7 = 11;
  iLowestNextPosition = 20;
  i = 0;
  while ( 1 )
  {
    v8 = LocalPlayer->GetWeapon(this: LocalPlayer, a2: v5);
    v9 = v8;
    if ( v8 == nullptr )
      goto LABEL_25;
    if ( selectionMode != WEAPON_SELECTION_NORMAL )
    {
      v10 = (C_WeaponCSBase *)__RTDynamicCast(
                                inptr: v8,
                                VfDelta: 0,
                                SrcType: &C_BaseCombatWeapon `RTTI Type Descriptor',
                                TargetType: &C_WeaponCSBase `RTTI Type Descriptor',
                                isReference: 0);
      v11 = v10;
      if ( v10 == nullptr )
        goto LABEL_25;
      v12 = C_WeaponCSBase::GetCSWpnData(this: v10)->m_WeaponType == WEAPONTYPE_C4
         || C_WeaponCSBase::GetCSWpnData(this: v11)->m_WeaponType == WEAPONTYPE_GRENADE;
      if ( selectionMode == WEAPON_SELECTION_GRENADE_AND_BOMB )
      {
        if ( !v12 )
          goto LABEL_25;
      }
      else if ( selectionMode == WEAPON_SELECTION_NO_GRENADE_AND_BOMB && v12 )
      {
        goto LABEL_25;
      }
    }
    if ( v9->CanBeSelected(this: v9) )
    {
      v13 = v9->GetSlot(this: v9);
      v14 = v9->GetPosition(this: v9);
      if ( (v13 > iCurrentSlot || v13 == iCurrentSlot && v14 > iCurrentPosition)
        && (v13 < v7 || v13 == v7 && v14 < iLowestNextPosition) )
      {
        v7 = v13;
        iLowestNextPosition = v14;
        pNextWeapon = v9;
      }
    }
LABEL_25:
    v5 = i + 1;
    i = v5;
    if ( v5 >= 64 )
      return pNextWeapon;
    LocalPlayer = pPlayer;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10203960
// Name: private: class C_BaseCombatWeapon __near * CHudWeaponSelection::FindPrevWeaponInWeaponSelection(int,int)
// Source: json
//------------------------------------------------------------------------------
C_BaseCombatWeapon *__thiscall CHudWeaponSelection::FindPrevWeaponInWeaponSelection(
        CHudWeaponSelection *this,
        int iCurrentSlot,
        int iCurrentPosition)
{
  int v3; // ebx
  C_BasePlayer *LocalPlayer; // edi
  C_BaseCombatWeapon *result; // eax
  int v6; // esi
  int v7; // edi
  int v8; // eax
  C_BaseCombatWeapon *pPrevWeapon; // [esp+8h] [ebp-10h]
  C_BasePlayer *pPlayer; // [esp+Ch] [ebp-Ch]
  int iLowestPrevPosition; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  v3 = -1;
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  result = nullptr;
  pPlayer = LocalPlayer;
  if ( LocalPlayer != nullptr )
  {
    pPrevWeapon = nullptr;
    iLowestPrevPosition = -1;
    for ( i = 0; i < 64; ++i )
    {
      v6 = (int)LocalPlayer->GetWeapon(this: LocalPlayer, a2: i);
      if ( v6 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v6 + 920))(a1: v6) != 0 )
      {
        v7 = (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 1288))(a1: v6);
        v8 = (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 1292))(a1: v6);
        if ( (v7 < iCurrentSlot || v7 == iCurrentSlot && v8 < iCurrentPosition)
          && (v7 > v3 || v7 == v3 && v8 > iLowestPrevPosition) )
        {
          v3 = v7;
          iLowestPrevPosition = v8;
          pPrevWeapon = (C_BaseCombatWeapon *)v6;
        }
        LocalPlayer = pPlayer;
      }
    }
    return pPrevWeapon;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10203A10
// Name: private: void CHudWeaponSelection::SelectSpecificWeapon(enum CSWeaponID)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudWeaponSelection::SelectSpecificWeapon(CHudWeaponSelection *this, CSWeaponID weaponID)
{
  C_CSPlayer *LocalPlayer; // ebx
  CCSWeaponInfo *WeaponInfo; // edi
  C_BaseCombatWeapon *v5; // eax

  LocalPlayer = CClientTools::GetLocalPlayer();
  if ( LocalPlayer != nullptr )
  {
    WeaponInfo = GetWeaponInfo(weaponID);
    if ( WeaponInfo != nullptr && LocalPlayer->IsAllowedToSwitchWeapons(this: LocalPlayer) )
    {
      v5 = this->GetNextActivePos(this, a2: WeaponInfo->iSlot, a3: WeaponInfo->iPosition);
      if ( v5 != nullptr )
      {
        this->SetSelectedWeapon(this, a2: v5);
        this->SelectWeapon(this);
        if ( this->m_bPlaySelectionSounds )
          C_BaseEntity::EmitSound(
            this: LocalPlayer,
            soundname: "Player.WeaponSelectionMoveSlot",
            soundtime: 0,
            duration: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10203AA0
// Name: public: virtual void CHudWeaponSelection::UserCmd_Slot6(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudWeaponSelection::UserCmd_Slot6(CHudWeaponSelection *this)
{
  CHudWeaponSelection::SelectSpecificWeapon(this, weaponID: WEAPON_HEGRENADE);
}

//------------------------------------------------------------------------------
// Address: 0x10203AB0
// Name: public: virtual void CHudWeaponSelection::UserCmd_Slot7(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudWeaponSelection::UserCmd_Slot7(CHudWeaponSelection *this)
{
  CHudWeaponSelection::SelectSpecificWeapon(this, weaponID: WEAPON_FLASHBANG);
}

//------------------------------------------------------------------------------
// Address: 0x10203AC0
// Name: public: virtual void CHudWeaponSelection::UserCmd_Slot8(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudWeaponSelection::UserCmd_Slot8(CHudWeaponSelection *this)
{
  CHudWeaponSelection::SelectSpecificWeapon(this, weaponID: WEAPON_SMOKEGRENADE);
}

//------------------------------------------------------------------------------
// Address: 0x10203AD0
// Name: public: virtual void CHudWeaponSelection::UserCmd_Slot9(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudWeaponSelection::UserCmd_Slot9(CHudWeaponSelection *this)
{
  CHudWeaponSelection::SelectSpecificWeapon(this, weaponID: WEAPON_DECOY);
}

//------------------------------------------------------------------------------
// Address: 0x10203AE0
// Name: public: virtual void CHudWeaponSelection::UserCmd_Slot10(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudWeaponSelection::UserCmd_Slot10(CHudWeaponSelection *this)
{
  CHudWeaponSelection::SelectSpecificWeapon(this, weaponID: WEAPON_MOLOTOV);
}

//------------------------------------------------------------------------------
// Address: 0x10203AF0
// Name: public: virtual void CHudWeaponSelection::UserCmd_Slot3(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudWeaponSelection::UserCmd_Slot3(CHudWeaponSelection *this)
{
  CHudWeaponSelection::SelectSpecificWeapon(this, weaponID: WEAPON_KNIFE);
}

//------------------------------------------------------------------------------
// Address: 0x10203B00
// Name: public: virtual void CHudWeaponSelection::UserCmd_Slot4(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudWeaponSelection::UserCmd_Slot4(CHudWeaponSelection *this)
{
  CHudWeaponSelection::SelectSpecificWeapon(this, weaponID: WEAPON_TASER);
}

//------------------------------------------------------------------------------
// Address: 0x10203B10
// Name: public: virtual class C_BaseCombatWeapon __near * CHudWeaponSelection::GetWeaponInSlot(int,int)
// Source: json
//------------------------------------------------------------------------------
C_BaseCombatWeapon *__thiscall CHudWeaponSelection::GetWeaponInSlot(CHudWeaponSelection *this, int iSlot, int iSlotPos)
{
  C_BasePlayer *LocalPlayer; // eax
  C_BasePlayer *v4; // ebx
  int v6; // edi
  int v7; // esi

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  v4 = LocalPlayer;
  if ( LocalPlayer == nullptr || C_BasePlayer::IsPlayerDead(this: LocalPlayer) )
    return nullptr;
  v6 = 0;
  while ( 1 )
  {
    v7 = (int)v4->GetWeapon(this: v4, a2: v6);
    if ( v7 != 0
      && (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 1288))(a1: v7) == iSlot
      && (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 1292))(a1: v7) == iSlotPos )
    {
      break;
    }
    if ( ++v6 >= 64 )
      return nullptr;
  }
  return (C_BaseCombatWeapon *)v7;
}

//------------------------------------------------------------------------------
// Address: 0x10203B90
// Name: public: virtual void CHudWeaponSelection::LevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudWeaponSelection::LevelInit(CHudWeaponSelection *this)
{
  int m_iMaxSlots; // eax

  m_iMaxSlots = this->m_iMaxSlots;
  if ( m_iMaxSlots >= 0 )
  {
    if ( m_iMaxSlots > 11 )
      m_iMaxSlots = 11;
    this->m_iMaxSlots = m_iMaxSlots;
  }
  else
  {
    this->m_iMaxSlots = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10203BC0
// Name: public: void CHudWeaponSelection::CycleToNextWeapon(enum CHudWeaponSelection::WEAPON_SELECTION_MODE)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudWeaponSelection::CycleToNextWeapon(
        CHudWeaponSelection *this,
        CHudWeaponSelection::WEAPON_SELECTION_MODE selectionMode)
{
  C_BasePlayer *LocalPlayer; // edi
  C_BaseCombatWeapon *v4; // edi
  int v5; // eax
  C_BaseCombatWeapon *NextWeaponInWeaponSelection; // eax
  int soundtime; // [esp+4h] [ebp-18h]
  C_BasePlayer *pPlayer; // [esp+18h] [ebp-4h]

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  pPlayer = LocalPlayer;
  if ( LocalPlayer == nullptr )
    return;
  if ( this->IsInSelectionMode(this) )
  {
    v4 = this->GetSelectedWeapon(this);
    if ( v4 == nullptr )
      return;
  }
  else
  {
    v4 = LocalPlayer->GetActiveWeapon(this: LocalPlayer);
    if ( v4 == nullptr )
      goto LABEL_7;
  }
  soundtime = v4->GetPosition(this: v4);
  v5 = v4->GetSlot(this: v4);
  NextWeaponInWeaponSelection = CHudWeaponSelection::FindNextWeaponInWeaponSelection(
                                  this,
                                  iCurrentSlot: v5,
                                  iCurrentPosition: soundtime,
                                  selectionMode);
  if ( NextWeaponInWeaponSelection == nullptr )
  {
LABEL_7:
    NextWeaponInWeaponSelection = CHudWeaponSelection::FindNextWeaponInWeaponSelection(
                                    this,
                                    iCurrentSlot: -1,
                                    iCurrentPosition: -1,
                                    selectionMode);
    if ( NextWeaponInWeaponSelection == nullptr )
      return;
  }
  this->SetSelectedWeapon(this, a2: NextWeaponInWeaponSelection);
  if ( hud_fastswitch.m_pParent != nullptr && hud_fastswitch.m_pParent->m_Value.m_nValue > 0 )
  {
    this->SelectWeapon(this);
  }
  else if ( !this->IsInSelectionMode(this) )
  {
    this->OpenSelection(this);
  }
  if ( this->m_bPlaySelectionSounds )
    C_BaseEntity::EmitSound(this: pPlayer, soundname: "Player.WeaponSelectionMoveSlot", soundtime: 0, duration: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10203CC0
// Name: public: virtual void CHudWeaponSelection::CycleToPrevWeapon(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudWeaponSelection::CycleToPrevWeapon(CHudWeaponSelection *this)
{
  C_BasePlayer *LocalPlayer; // eax
  C_BaseEntity *v3; // ebx
  C_BaseCombatWeapon *v4; // edi
  int v5; // eax
  C_BaseCombatWeapon *PrevWeaponInWeaponSelection; // eax
  int v7; // [esp+8h] [ebp-10h]

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  v3 = LocalPlayer;
  if ( LocalPlayer == nullptr || C_BasePlayer::IsPlayerDead(this: LocalPlayer) )
    return;
  if ( this->IsInSelectionMode(this) )
  {
    v4 = this->GetSelectedWeapon(this);
    if ( v4 == nullptr )
      return;
  }
  else
  {
    v4 = (C_BaseCombatWeapon *)((int (__thiscall *)(C_BaseEntity *))v3->IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].VPhysicsUpdate)(a1: v3);
    if ( v4 == nullptr )
      goto LABEL_8;
  }
  v7 = v4->GetPosition(this: v4);
  v5 = v4->GetSlot(this: v4);
  PrevWeaponInWeaponSelection = CHudWeaponSelection::FindPrevWeaponInWeaponSelection(
                                  this,
                                  iCurrentSlot: v5,
                                  iCurrentPosition: v7);
  if ( PrevWeaponInWeaponSelection == nullptr )
  {
LABEL_8:
    PrevWeaponInWeaponSelection = CHudWeaponSelection::FindPrevWeaponInWeaponSelection(
                                    this,
                                    iCurrentSlot: 11,
                                    iCurrentPosition: 20);
    if ( PrevWeaponInWeaponSelection == nullptr )
      return;
  }
  this->SetSelectedWeapon(this, a2: PrevWeaponInWeaponSelection);
  if ( hud_fastswitch.m_pParent != nullptr && hud_fastswitch.m_pParent->m_Value.m_nValue > 0 )
  {
    this->SelectWeapon(this);
  }
  else if ( !this->IsInSelectionMode(this) )
  {
    this->OpenSelection(this);
  }
  if ( this->m_bPlaySelectionSounds )
    C_BaseEntity::EmitSound(this: v3, soundname: "Player.WeaponSelectionMoveSlot", soundtime: 0, duration: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10203DC0
// Name: public: virtual void CHudWeaponSelection::SwitchToLastWeapon(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CHudWeaponSelection::SwitchToLastWeapon(CHudWeaponSelection *this@<ecx>, int a2@<edi>)
{
  C_BasePlayer *LocalPlayer; // eax
  C_BaseCombatCharacter *v3; // esi
  int v4; // edi
  C_BaseCombatWeapon *v5; // eax
  int i; // ebx
  int v7; // edi
  C_BaseCombatWeapon *activeWeapon; // [esp+4h] [ebp-8h]
  C_BaseCombatWeapon *lastWeapon; // [esp+8h] [ebp-4h]

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  v3 = LocalPlayer;
  if ( LocalPlayer != nullptr && !C_BasePlayer::IsPlayerDead(this: LocalPlayer) )
  {
    v4 = ((int (__thiscall *)(C_BaseCombatCharacter *, int))v3->C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].SetClassname)(
           a1: v3,
           a2);
    lastWeapon = (C_BaseCombatWeapon *)v4;
    v5 = v3->GetActiveWeapon(this: v3);
    activeWeapon = v5;
    if ( (C_BaseCombatWeapon *)v4 != v5 && v4 != 0 )
    {
      for ( i = 0; i < 64; ++i )
      {
        v7 = (int)v3->GetWeapon(this: v3, a2: i);
        if ( v7 != 0
          && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v7 + 920))(a1: v7) != 0
          && (C_BaseCombatWeapon *)v7 == lastWeapon )
        {
          break;
        }
      }
      if ( i != 64 )
        goto LABEL_13;
      v5 = activeWeapon;
    }
    lastWeapon = g_pGameRules->GetNextBestWeapon(this: g_pGameRules, a2: v3, a3: v5);
LABEL_13:
    input->MakeWeaponSelection(this: input, a2: lastWeapon);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10203E80
// Name: public: virtual void CHudWeaponSelection::SelectWeaponSlot(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CHudWeaponSelection::SelectWeaponSlot(
        CHudWeaponSelection *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int iSlot)
{
  C_BasePlayer *LocalPlayer; // eax
  int v6; // ebx
  int v7; // edi
  C_BaseCombatWeapon *v8; // ebx
  CHudWeaponSelection_vtbl *v9; // edi
  int v10; // eax
  int v11; // eax
  char v12; // cl
  C_BasePlayer *pPlayer; // [esp+28h] [ebp-8h]
  int i; // [esp+2Ch] [ebp-4h]
  int bMultipleWeaponsInSlot; // [esp+38h] [ebp+8h]

  bMultipleWeaponsInSlot = iSlot - 1;
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  pPlayer = LocalPlayer;
  if ( LocalPlayer != nullptr
    && bMultipleWeaponsInSlot <= 11
    && LocalPlayer->IsAllowedToSwitchWeapons(this: LocalPlayer) )
  {
    v6 = 0;
    v7 = ((int (__thiscall *)(CHudWeaponSelection *, int, int))this->GetSelectedWeapon)(a1: this, a2: a3, a3: a2);
    if ( this->IsInSelectionMode(this)
      && v7 != 0
      && (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 1288))(a1: v7) == bMultipleWeaponsInSlot )
    {
      v6 = (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 1292))(a1: v7) + 1;
    }
    v8 = this->GetNextActivePos(this, a2: bMultipleWeaponsInSlot, a3: v6);
    if ( v8 != nullptr || (v8 = this->GetNextActivePos(this, a2: bMultipleWeaponsInSlot, a3: 0)) != nullptr )
    {
      this->SetSelectedWeapon(this, a2: v8);
      i = 0;
      while ( 1 )
      {
        v9 = this->CBaseHudWeaponSelection::CHudElement::CGameEventListener::IGameEventListener2::__vftable;
        v10 = ((int (__thiscall *)(C_BaseCombatWeapon *, int))v8->GetSlot)(a1: v8, a2: i);
        v11 = ((int (__thiscall *)(CHudWeaponSelection *, int))v9->GetWeaponInSlot)(a1: this, a2: v10);
        if ( v11 != 0 && (C_BaseCombatWeapon *)v11 != v8 )
          break;
        if ( ++i >= 20 )
        {
          v12 = 0;
          goto LABEL_16;
        }
      }
      v12 = 1;
LABEL_16:
      if ( hud_fastswitch.m_pParent == nullptr || hud_fastswitch.m_pParent->m_Value.m_nValue <= 0 || v12 != 0 )
      {
        if ( !this->IsInSelectionMode(this) )
          this->OpenSelection(this);
      }
      else
      {
        this->SelectWeapon(this);
      }
    }
    if ( this->m_bPlaySelectionSounds )
      C_BaseEntity::EmitSound(
        this: pPlayer,
        soundname: "Player.WeaponSelectionMoveSlot",
        soundtime: 0,
        duration: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10203FF0
// Name: public: virtual void CHudWeaponSelection::CycleToNextWeapon(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudWeaponSelection::CycleToNextWeapon(CHudWeaponSelection *this)
{
  CHudWeaponSelection::CycleToNextWeapon(this, selectionMode: WEAPON_SELECTION_NORMAL);
}

//------------------------------------------------------------------------------
// Address: 0x10204000
// Name: public: virtual void CHudWeaponSelection::CycleToNextGrenadeOrBomb(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudWeaponSelection::CycleToNextGrenadeOrBomb(CHudWeaponSelection *this)
{
  CHudWeaponSelection::CycleToNextWeapon(this, selectionMode: WEAPON_SELECTION_GRENADE_AND_BOMB);
}

//------------------------------------------------------------------------------
// Address: 0x10204010
// Name: public: virtual void CHudWeaponSelection::CycleToNextNonGrenadeOrBomb(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudWeaponSelection::CycleToNextNonGrenadeOrBomb(CHudWeaponSelection *this)
{
  CHudWeaponSelection::CycleToNextWeapon(this, selectionMode: WEAPON_SELECTION_NO_GRENADE_AND_BOMB);
}

//------------------------------------------------------------------------------
// Address: 0x10204020
// Name: public: virtual void CHudWeaponSelection::SelectWeapon(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CHudWeaponSelection::SelectWeapon(CHudWeaponSelection *this@<ecx>, int a2@<ebx>)
{
  C_BasePlayer *LocalPlayer; // edi
  int v4; // ebx
  C_BaseCombatWeapon *v5; // eax

  if ( this->GetSelectedWeapon(this) != nullptr )
  {
    LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    if ( LocalPlayer != nullptr )
    {
      v4 = (int)LocalPlayer->GetActiveWeapon(this: LocalPlayer);
      v5 = this->GetSelectedWeapon(this);
      if ( v5->CanBeSelected(this: v5) )
      {
        if ( ((int (__thiscall *)(CHudWeaponSelection *, int))this->GetSelectedWeapon)(a1: this, a2) != v4 )
          C_BaseEntity::EmitSound(
            this: LocalPlayer,
            soundname: "Player.WeaponSelected",
            soundtime: 0,
            duration: nullptr);
        this->SetWeaponSelected(this);
        this->m_hSelectedWeapon.m_Index = -1;
        engine->ClientCmd(this: engine, a2: "cancelselect\n");
      }
      else
      {
        C_BaseEntity::EmitSound(
          this: LocalPlayer,
          soundname: "Player.DenyWeaponSelection",
          soundtime: 0,
          duration: nullptr);
      }
    }
  }
  else
  {
    engine->ClientCmd(this: engine, a2: "cancelselect\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x102040F0
// Name: public: virtual void CHudWeaponSelection::CancelWeaponSelection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudWeaponSelection::CancelWeaponSelection(CHudWeaponSelection *this)
{
  if ( C_BasePlayer::GetLocalPlayer(nSlot: -1) != nullptr && this->ShouldDraw(this) )
  {
    this->HideSelection(this);
    this->m_hSelectedWeapon.m_Index = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10204120
// Name: public: static void CHudWeaponSelection::PanelAnimationVar_m_hNumberFont::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudWeaponSelection::PanelAnimationVar_m_hNumberFont::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudWeaponSelection::PanelAnimationVar_m_hNumberFont::InitVar'::`2'::bAdded )
  {
    `CHudWeaponSelection::PanelAnimationVar_m_hNumberFont::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudWeaponSelection");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "NumberFont";
    src.m_pszVariable = "m_hNumberFont";
    src.m_pszType = "vgui::HFont";
    src.m_pszDefaultValue = "HudSelectionNumbers";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudWeaponSelection::GetVar_m_hNumberFont;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10204180
// Name: public: static void CHudWeaponSelection::PanelAnimationVar_m_hTextFont::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudWeaponSelection::PanelAnimationVar_m_hTextFont::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudWeaponSelection::PanelAnimationVar_m_hTextFont::InitVar'::`2'::bAdded )
  {
    `CHudWeaponSelection::PanelAnimationVar_m_hTextFont::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudWeaponSelection");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "TextFont";
    src.m_pszVariable = "m_hTextFont";
    src.m_pszType = "vgui::HFont";
    src.m_pszDefaultValue = "HudSelectionText";
    src.m_pfnLookup = CHudWeaponSelection::GetVar_m_hTextFont;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102041E0
// Name: public: static void CHudWeaponSelection::PanelAnimationVar_m_flSmallBoxSize::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudWeaponSelection::PanelAnimationVar_m_flSmallBoxSize::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudWeaponSelection::PanelAnimationVar_m_flSmallBoxSize::InitVar'::`2'::bAdded )
  {
    `CHudWeaponSelection::PanelAnimationVar_m_flSmallBoxSize::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudWeaponSelection");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "SmallBoxSize";
    src.m_pszVariable = "m_flSmallBoxSize";
    src.m_pszType = "proportional_float";
    src.m_pszDefaultValue = "32";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudWeaponSelection::GetVar_m_flSmallBoxSize;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10204240
// Name: public: static void CHudWeaponSelection::PanelAnimationVar_m_flLargeBoxWide::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudWeaponSelection::PanelAnimationVar_m_flLargeBoxWide::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudWeaponSelection::PanelAnimationVar_m_flLargeBoxWide::InitVar'::`2'::bAdded )
  {
    `CHudWeaponSelection::PanelAnimationVar_m_flLargeBoxWide::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudWeaponSelection");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "LargeBoxWide";
    src.m_pszVariable = "m_flLargeBoxWide";
    src.m_pszType = "proportional_float";
    src.m_pszDefaultValue = "108";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudWeaponSelection::GetVar_m_flLargeBoxWide;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102042A0
// Name: public: static void CHudWeaponSelection::PanelAnimationVar_m_flLargeBoxTall::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudWeaponSelection::PanelAnimationVar_m_flLargeBoxTall::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudWeaponSelection::PanelAnimationVar_m_flLargeBoxTall::InitVar'::`2'::bAdded )
  {
    `CHudWeaponSelection::PanelAnimationVar_m_flLargeBoxTall::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudWeaponSelection");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "LargeBoxTall";
    src.m_pszVariable = "m_flLargeBoxTall";
    src.m_pszType = "proportional_float";
    src.m_pszDefaultValue = "72";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudWeaponSelection::GetVar_m_flLargeBoxTall;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10204300
// Name: public: static void CHudWeaponSelection::PanelAnimationVar_m_flBoxGap::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudWeaponSelection::PanelAnimationVar_m_flBoxGap::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudWeaponSelection::PanelAnimationVar_m_flBoxGap::InitVar'::`2'::bAdded )
  {
    `CHudWeaponSelection::PanelAnimationVar_m_flBoxGap::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudWeaponSelection");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "BoxGap";
    src.m_pszVariable = "m_flBoxGap";
    src.m_pszType = "proportional_float";
    src.m_pszDefaultValue = "12";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudWeaponSelection::GetVar_m_flBoxGap;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10204360
// Name: public: static void CHudWeaponSelection::PanelAnimationVar_m_flSelectionNumberXPos::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudWeaponSelection::PanelAnimationVar_m_flSelectionNumberXPos::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudWeaponSelection::PanelAnimationVar_m_flSelectionNumberXPos::InitVar'::`2'::bAdded )
  {
    `CHudWeaponSelection::PanelAnimationVar_m_flSelectionNumberXPos::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudWeaponSelection");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "SelectionNumberXPos";
    src.m_pszVariable = "m_flSelectionNumberXPos";
    src.m_pszType = "proportional_float";
    src.m_pszDefaultValue = "4";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudWeaponSelection::GetVar_m_flSelectionNumberXPos;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102043C0
// Name: public: static void CHudWeaponSelection::PanelAnimationVar_m_flSelectionNumberYPos::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudWeaponSelection::PanelAnimationVar_m_flSelectionNumberYPos::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudWeaponSelection::PanelAnimationVar_m_flSelectionNumberYPos::InitVar'::`2'::bAdded )
  {
    `CHudWeaponSelection::PanelAnimationVar_m_flSelectionNumberYPos::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudWeaponSelection");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "SelectionNumberYPos";
    src.m_pszVariable = "m_flSelectionNumberYPos";
    src.m_pszType = "proportional_float";
    src.m_pszDefaultValue = "4";
    src.m_pfnLookup = CHudWeaponSelection::GetVar_m_flSelectionNumberYPos;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10204420
// Name: public: static void CHudWeaponSelection::PanelAnimationVar_m_flIconXPos::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudWeaponSelection::PanelAnimationVar_m_flIconXPos::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudWeaponSelection::PanelAnimationVar_m_flIconXPos::InitVar'::`2'::bAdded )
  {
    `CHudWeaponSelection::PanelAnimationVar_m_flIconXPos::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudWeaponSelection");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "IconXPos";
    src.m_pszVariable = "m_flIconXPos";
    src.m_pszType = "proportional_float";
    src.m_pszDefaultValue = "16";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudWeaponSelection::GetVar_m_flIconXPos;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10204480
// Name: public: static void CHudWeaponSelection::PanelAnimationVar_m_flIconYPos::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudWeaponSelection::PanelAnimationVar_m_flIconYPos::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudWeaponSelection::PanelAnimationVar_m_flIconYPos::InitVar'::`2'::bAdded )
  {
    `CHudWeaponSelection::PanelAnimationVar_m_flIconYPos::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudWeaponSelection");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "IconYPos";
    src.m_pszVariable = "m_flIconYPos";
    src.m_pszType = "proportional_float";
    src.m_pszDefaultValue = "8";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudWeaponSelection::GetVar_m_flIconYPos;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102044E0
// Name: public: static void CHudWeaponSelection::PanelAnimationVar_m_flTextYPos::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudWeaponSelection::PanelAnimationVar_m_flTextYPos::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudWeaponSelection::PanelAnimationVar_m_flTextYPos::InitVar'::`2'::bAdded )
  {
    `CHudWeaponSelection::PanelAnimationVar_m_flTextYPos::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudWeaponSelection");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "TextYPos";
    src.m_pszVariable = "m_flTextYPos";
    src.m_pszType = "proportional_float";
    src.m_pszDefaultValue = "54";
    src.m_pfnLookup = CHudWeaponSelection::GetVar_m_flTextYPos;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10204540
// Name: public: static void CHudWeaponSelection::PanelAnimationVar_m_flAlphaOverride::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudWeaponSelection::PanelAnimationVar_m_flAlphaOverride::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudWeaponSelection::PanelAnimationVar_m_flAlphaOverride::InitVar'::`2'::bAdded )
  {
    `CHudWeaponSelection::PanelAnimationVar_m_flAlphaOverride::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudWeaponSelection");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "Alpha";
    src.m_pszVariable = "m_flAlphaOverride";
    src.m_pszType = "float";
    src.m_pszDefaultValue = "255";
    src.m_pfnLookup = CHudWeaponSelection::GetVar_m_flAlphaOverride;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102045A0
// Name: public: static void CHudWeaponSelection::PanelAnimationVar_m_flSelectionAlphaOverride::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudWeaponSelection::PanelAnimationVar_m_flSelectionAlphaOverride::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudWeaponSelection::PanelAnimationVar_m_flSelectionAlphaOverride::InitVar'::`2'::bAdded )
  {
    `CHudWeaponSelection::PanelAnimationVar_m_flSelectionAlphaOverride::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudWeaponSelection");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "SelectionAlpha";
    src.m_pszVariable = "m_flSelectionAlphaOverride";
    src.m_pszType = "float";
    src.m_pszDefaultValue = "255";
    src.m_pfnLookup = CHudWeaponSelection::GetVar_m_flSelectionAlphaOverride;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10204600
// Name: public: static void CHudWeaponSelection::PanelAnimationVar_m_TextColor::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudWeaponSelection::PanelAnimationVar_m_TextColor::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudWeaponSelection::PanelAnimationVar_m_TextColor::InitVar'::`2'::bAdded )
  {
    `CHudWeaponSelection::PanelAnimationVar_m_TextColor::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudWeaponSelection");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "TextColor";
    src.m_pszVariable = "m_TextColor";
    src.m_pszType = "Color";
    src.m_pszDefaultValue = "SelectionTextFg";
    src.m_pfnLookup = CHudWeaponSelection::GetVar_m_TextColor;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10204660
// Name: public: static void CHudWeaponSelection::PanelAnimationVar_m_NumberColor::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudWeaponSelection::PanelAnimationVar_m_NumberColor::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudWeaponSelection::PanelAnimationVar_m_NumberColor::InitVar'::`2'::bAdded )
  {
    `CHudWeaponSelection::PanelAnimationVar_m_NumberColor::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudWeaponSelection");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "NumberColor";
    src.m_pszVariable = "m_NumberColor";
    src.m_pszType = "Color";
    src.m_pszDefaultValue = "SelectionNumberFg";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudWeaponSelection::GetVar_m_NumberColor;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102046C0
// Name: public: static void CHudWeaponSelection::PanelAnimationVar_m_EmptyBoxColor::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudWeaponSelection::PanelAnimationVar_m_EmptyBoxColor::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudWeaponSelection::PanelAnimationVar_m_EmptyBoxColor::InitVar'::`2'::bAdded )
  {
    `CHudWeaponSelection::PanelAnimationVar_m_EmptyBoxColor::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudWeaponSelection");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "EmptyBoxColor";
    src.m_pszVariable = "m_EmptyBoxColor";
    src.m_pszType = "Color";
    src.m_pszDefaultValue = "SelectionEmptyBoxBg";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudWeaponSelection::GetVar_m_EmptyBoxColor;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10204720
// Name: public: static void CHudWeaponSelection::PanelAnimationVar_m_BoxColor::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudWeaponSelection::PanelAnimationVar_m_BoxColor::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudWeaponSelection::PanelAnimationVar_m_BoxColor::InitVar'::`2'::bAdded )
  {
    `CHudWeaponSelection::PanelAnimationVar_m_BoxColor::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudWeaponSelection");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "BoxColor";
    src.m_pszVariable = "m_BoxColor";
    src.m_pszType = "Color";
    src.m_pszDefaultValue = "SelectionBoxBg";
    src.m_pfnLookup = CHudWeaponSelection::GetVar_m_BoxColor;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10204780
// Name: public: static void CHudWeaponSelection::PanelAnimationVar_m_SelectedBoxColor::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudWeaponSelection::PanelAnimationVar_m_SelectedBoxColor::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudWeaponSelection::PanelAnimationVar_m_SelectedBoxColor::InitVar'::`2'::bAdded )
  {
    `CHudWeaponSelection::PanelAnimationVar_m_SelectedBoxColor::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudWeaponSelection");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "SelectedBoxClor";
    src.m_pszVariable = "m_SelectedBoxColor";
    src.m_pszType = "Color";
    src.m_pszDefaultValue = "SelectionSelectedBoxBg";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudWeaponSelection::GetVar_m_SelectedBoxColor;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102047E0
// Name: public: static void CHudWeaponSelection::PanelAnimationVar_m_flWeaponPickupGrowTime::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudWeaponSelection::PanelAnimationVar_m_flWeaponPickupGrowTime::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudWeaponSelection::PanelAnimationVar_m_flWeaponPickupGrowTime::InitVar'::`2'::bAdded )
  {
    `CHudWeaponSelection::PanelAnimationVar_m_flWeaponPickupGrowTime::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudWeaponSelection");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "SelectionGrowTime";
    src.m_pszVariable = "m_flWeaponPickupGrowTime";
    src.m_pszType = "float";
    src.m_pszDefaultValue = "0.1";
    src.m_pfnLookup = CHudWeaponSelection::GetVar_m_flWeaponPickupGrowTime;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10204840
// Name: public: static void CHudWeaponSelection::PanelAnimationVar_m_flTextScan::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudWeaponSelection::PanelAnimationVar_m_flTextScan::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudWeaponSelection::PanelAnimationVar_m_flTextScan::InitVar'::`2'::bAdded )
  {
    `CHudWeaponSelection::PanelAnimationVar_m_flTextScan::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudWeaponSelection");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "TextScan";
    src.m_pszVariable = "m_flTextScan";
    src.m_pszType = "float";
    src.m_pszDefaultValue = "1.0";
    src.m_pfnLookup = CHudWeaponSelection::GetVar_m_flTextScan;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102048A0
// Name: public: static void CHudWeaponSelection::PanelAnimationVar_m_iMaxSlots::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudWeaponSelection::PanelAnimationVar_m_iMaxSlots::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudWeaponSelection::PanelAnimationVar_m_iMaxSlots::InitVar'::`2'::bAdded )
  {
    `CHudWeaponSelection::PanelAnimationVar_m_iMaxSlots::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudWeaponSelection");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "MaxSlots";
    src.m_pszVariable = "m_iMaxSlots";
    src.m_pszType = "int";
    src.m_pszDefaultValue = "6";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudWeaponSelection::GetVar_m_iMaxSlots;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10204900
// Name: public: static void CHudWeaponSelection::PanelAnimationVar_m_bPlaySelectionSounds::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHudWeaponSelection::PanelAnimationVar_m_bPlaySelectionSounds::InitVar()
{
  PanelAnimationMap *v0; // eax
  int m_Size; // [esp-8h] [ebp-20h]
  PanelAnimationMapEntry src; // [esp+0h] [ebp-18h] BYREF

  if ( !`CHudWeaponSelection::PanelAnimationVar_m_bPlaySelectionSounds::InitVar'::`2'::bAdded )
  {
    `CHudWeaponSelection::PanelAnimationVar_m_bPlaySelectionSounds::InitVar'::`2'::bAdded = true;
    v0 = FindOrAddPanelAnimationMap(className: "CHudWeaponSelection");
    m_Size = v0->entries.m_Size;
    src.m_pszScriptName = "PlaySelectSounds";
    src.m_pszVariable = "m_bPlaySelectionSounds";
    src.m_pszType = "bool";
    src.m_pszDefaultValue = "1";
    src.m_pfnLookup = (void *(__cdecl *)(vgui::Panel *))CHudWeaponSelection::GetVar_m_bPlaySelectionSounds;
    src.m_bArray = false;
    CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
      this: &v0->entries,
      elem: m_Size,
      &src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10204960
// Name: public: CHudWeaponSelection::CHudWeaponSelection(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CHudWeaponSelection *__thiscall CHudWeaponSelection::CHudWeaponSelection(
        CHudWeaponSelection *this,
        const char *pElementName)
{
  vgui::PanelMessageMap *v3; // ebx
  PanelAnimationMap *v4; // ebx
  vgui::PanelKeyBindingMap *v5; // ebx
  IClientMode *ClientMode; // eax
  vgui::Panel *v7; // eax

  CBaseHudWeaponSelection::CBaseHudWeaponSelection(this, pElementName);
  vgui::Panel::Panel(this: &this->vgui::Panel, parent: nullptr, panelName: "HudWeaponSelection");
  this->CBaseHudWeaponSelection::CHudElement::CGameEventListener::IGameEventListener2::__vftable = (CHudWeaponSelection_vtbl *)&CHudWeaponSelection::`vftable'{for `CBaseHudWeaponSelection'};
  this->vgui::Panel::vgui::IClientPanel::__vftable = (vgui::Panel_vtbl *)&CHudWeaponSelection::`vftable'{for `vgui::Panel'};
  if ( `CHudWeaponSelection::ChainToMap'::`2'::chained == 0 )
  {
    `CHudWeaponSelection::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CHudWeaponSelection");
    v3->pfnClassName = CHudWeaponSelection::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CHudWeaponSelection::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CHudWeaponSelection::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CHudWeaponSelection");
    v4->pfnClassName = CHudWeaponSelection::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CHudWeaponSelection::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CHudWeaponSelection::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CHudWeaponSelection");
    v5->pfnClassName = CHudWeaponSelection::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  CHudWeaponSelection::PanelAnimationVar_m_hNumberFont::InitVar();
  CHudWeaponSelection::PanelAnimationVar_m_hTextFont::InitVar();
  CHudWeaponSelection::PanelAnimationVar_m_flSmallBoxSize::InitVar();
  CHudWeaponSelection::PanelAnimationVar_m_flLargeBoxWide::InitVar();
  CHudWeaponSelection::PanelAnimationVar_m_flLargeBoxTall::InitVar();
  CHudWeaponSelection::PanelAnimationVar_m_flBoxGap::InitVar();
  CHudWeaponSelection::PanelAnimationVar_m_flSelectionNumberXPos::InitVar();
  CHudWeaponSelection::PanelAnimationVar_m_flSelectionNumberYPos::InitVar();
  CHudWeaponSelection::PanelAnimationVar_m_flIconXPos::InitVar();
  CHudWeaponSelection::PanelAnimationVar_m_flIconYPos::InitVar();
  CHudWeaponSelection::PanelAnimationVar_m_flTextYPos::InitVar();
  CHudWeaponSelection::PanelAnimationVar_m_flAlphaOverride::InitVar();
  CHudWeaponSelection::PanelAnimationVar_m_flSelectionAlphaOverride::InitVar();
  CHudWeaponSelection::PanelAnimationVar_m_TextColor::InitVar();
  this->m_TextColor = 0;
  CHudWeaponSelection::PanelAnimationVar_m_NumberColor::InitVar();
  this->m_NumberColor = 0;
  CHudWeaponSelection::PanelAnimationVar_m_EmptyBoxColor::InitVar();
  this->m_EmptyBoxColor = 0;
  CHudWeaponSelection::PanelAnimationVar_m_BoxColor::InitVar();
  this->m_BoxColor = 0;
  CHudWeaponSelection::PanelAnimationVar_m_SelectedBoxColor::InitVar();
  this->m_SelectedBoxColor = 0;
  CHudWeaponSelection::PanelAnimationVar_m_flWeaponPickupGrowTime::InitVar();
  CHudWeaponSelection::PanelAnimationVar_m_flTextScan::InitVar();
  CHudWeaponSelection::PanelAnimationVar_m_iMaxSlots::InitVar();
  CHudWeaponSelection::PanelAnimationVar_m_bPlaySelectionSounds::InitVar();
  ClientMode = GetClientMode();
  v7 = ClientMode->GetViewport(this: ClientMode);
  vgui::Panel::SetParent(this: &this->vgui::Panel, newParent: v7);
  CTraceFilterSkipTwoEntities::SetPassEntity2(
    (CTraceFilterSkipTwoEntities *)this,
    pPassEntity2: (const IHandleEntity *)0x11);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10204AF0
// Name: protected: virtual bool CHudWeaponSelection::IsWeaponSelectable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHudWeaponSelection::IsWeaponSelectable(CHudWeaponSelection *this)
{
  return this->IsInSelectionMode(this);
}

//------------------------------------------------------------------------------
// Address: 0x10204B20
// Name: public: virtual struct vgui::PanelMessageMap __near * CHudWeaponSelection::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CHudWeaponSelection::GetMessageMap(CHudWeaponSelection *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CHudWeaponSelection::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudWeaponSelection::GetMessageMap'::`2'::s_pMap;
  `CHudWeaponSelection::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CHudWeaponSelection");
  `CHudWeaponSelection::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10204B50
// Name: public: virtual struct PanelAnimationMap __near * CHudWeaponSelection::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CHudWeaponSelection::GetAnimMap(CHudWeaponSelection *this)
{
  return FindOrAddPanelAnimationMap(className: "CHudWeaponSelection");
}

//------------------------------------------------------------------------------
// Address: 0x10204B60
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CHudWeaponSelection::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CHudWeaponSelection::GetKBMap(CHudWeaponSelection *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CHudWeaponSelection::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CHudWeaponSelection::GetKBMap'::`2'::s_pMap;
  `CHudWeaponSelection::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CHudWeaponSelection");
  `CHudWeaponSelection::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10204BD0
// Name: public: virtual class C_BaseCombatWeapon __near * CHudWeaponSelection::GetSelectedWeapon(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseCombatWeapon *__thiscall CHudWeaponSelection::GetSelectedWeapon(CHudWeaponSelection *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hSelectedWeapon.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (C_BaseCombatWeapon *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x10204C00
// Name: private: virtual void CHudWeaponSelection::SetSelectedWeapon(class C_BaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHudWeaponSelection::SetSelectedWeapon(CHudWeaponSelection *this, C_BaseCombatWeapon *pWeapon)
{
  if ( pWeapon != nullptr )
    this->m_hSelectedWeapon.m_Index = pWeapon->GetRefEHandle(this: pWeapon)->m_Index;
  else
    this->m_hSelectedWeapon.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10204C30
// Name: Create_CHudWeaponSelection
// Source: json
//------------------------------------------------------------------------------
CHudWeaponSelection *__cdecl Create_CHudWeaponSelection()
{
  unsigned __int8 *v0; // esi

  v0 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 556);
  memset(dst: v0, value: 0, count: 0x22Cu);
  if ( v0 != nullptr )
    return CHudWeaponSelection::CHudWeaponSelection(
             this: (CHudWeaponSelection *)v0,
             pElementName: "CHudWeaponSelection");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10423780
// Name: _dynamic_initializer_for__weapon_accuracy_logging__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_accuracy_logging__()
{
  ConVar::ConVar(this: &weapon_accuracy_logging, pName: "weapon_accuracy_logging", pDefaultValue: "0", flags: 8322);
  return atexit(func: dynamic_atexit_destructor_for__weapon_accuracy_logging__);
}

//------------------------------------------------------------------------------
// Address: 0x10427F80
// Name: _dynamic_initializer_for__weapon_recoil_decay__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_recoil_decay__()
{
  ConVar::ConVar(
    this: &weapon_recoil_decay,
    pName: "weapon_recoil_decay",
    pDefaultValue: "3.5",
    flags: 8320,
    pHelpString: "Decay factor for weapon recoil");
  return atexit(func: dynamic_atexit_destructor_for__weapon_recoil_decay__);
}

//------------------------------------------------------------------------------
// Address: 0x10427FB0
// Name: _dynamic_initializer_for__weapon_recoil_legacy__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_recoil_legacy__()
{
  ConVar::ConVar(
    this: &weapon_recoil_legacy,
    pName: "weapon_recoil_legacy",
    pDefaultValue: "0",
    flags: 8320,
    pHelpString: "Use legacy recoil system");
  return atexit(func: dynamic_atexit_destructor_for__weapon_recoil_legacy__);
}

//------------------------------------------------------------------------------
// Address: 0x10427FF0
// Name: _dynamic_initializer_for__weapon_recoil_extra__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_recoil_extra__()
{
  ConVar::ConVar(
    this: &weapon_recoil_extra,
    pName: "weapon_recoil_extra",
    pDefaultValue: "0.6",
    flags: 8320,
    pHelpString: "Additional recoil offset multiplier for weapons");
  return atexit(func: dynamic_atexit_destructor_for__weapon_recoil_extra__);
}

//------------------------------------------------------------------------------
// Address: 0x10428300
// Name: _dynamic_initializer_for__weapon_debug_spread_show__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_debug_spread_show__()
{
  ConVar::ConVar(
    this: &weapon_debug_spread_show,
    pName: "weapon_debug_spread_show",
    pDefaultValue: "1",
    flags: 32904,
    pHelpString: "Enables display of weapon accuracy; 1: show accuracy box, 3: show accuracy with dynamic crosshair");
  return atexit(func: dynamic_atexit_destructor_for__weapon_debug_spread_show__);
}

//------------------------------------------------------------------------------
// Address: 0x10428330
// Name: _dynamic_initializer_for__weapon_debug_spread_gap__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__weapon_debug_spread_gap__()
{
  ConVar::ConVar(this: &weapon_debug_spread_gap, pName: "weapon_debug_spread_gap", pDefaultValue: "0.67", flags: 32904);
  return atexit(func: dynamic_atexit_destructor_for__weapon_debug_spread_gap__);
}

//------------------------------------------------------------------------------
// Address: 0x10435850
// Name: _dynamic_atexit_destructor_for__weapon_accuracy_logging__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__weapon_accuracy_logging__()
{
  ConVar::~ConVar(this: &weapon_accuracy_logging);
}

//------------------------------------------------------------------------------
// Address: 0x10435E80
// Name: _dynamic_atexit_destructor_for__weapon_recoil_decay__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__weapon_recoil_decay__()
{
  ConVar::~ConVar(this: &weapon_recoil_decay);
}

//------------------------------------------------------------------------------
// Address: 0x10435E90
// Name: _dynamic_atexit_destructor_for__weapon_recoil_legacy__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__weapon_recoil_legacy__()
{
  ConVar::~ConVar(this: &weapon_recoil_legacy);
}

//------------------------------------------------------------------------------
// Address: 0x10435EA0
// Name: _dynamic_atexit_destructor_for__weapon_recoil_extra__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__weapon_recoil_extra__()
{
  ConVar::~ConVar(this: &weapon_recoil_extra);
}

//------------------------------------------------------------------------------
// Address: 0x10435F80
// Name: _dynamic_atexit_destructor_for__weapon_debug_spread_show__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__weapon_debug_spread_show__()
{
  ConVar::~ConVar(this: &weapon_debug_spread_show);
}

//------------------------------------------------------------------------------
// Address: 0x10435F90
// Name: _dynamic_atexit_destructor_for__weapon_debug_spread_gap__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__weapon_debug_spread_gap__()
{
  ConVar::~ConVar(this: &weapon_debug_spread_gap);
}

//------------------------------------------------------------------------------
// Address: 0x104237B0
// Name: _dynamic_initializer_for__g_GroupedSounds__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_GroupedSounds__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_GroupedSounds__);
}

//------------------------------------------------------------------------------
// Address: 0x104237C0
// Name: _dynamic_initializer_for__ClientEffectReg_CStrike_FX_EjectBrass_9mm_Callback__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CClientEffectRegistration *dynamic_initializer_for__ClientEffectReg_CStrike_FX_EjectBrass_9mm_Callback__()
{
  return CClientEffectRegistration::CClientEffectRegistration(
           this: &ClientEffectReg_CStrike_FX_EjectBrass_9mm_Callback,
           pEffectName: "EjectBrass_9mm",
           fn: (void (__cdecl *)(const CEffectData *))CStrike_FX_EjectBrass_556_Callback);
}

//------------------------------------------------------------------------------
// Address: 0x10428020
// Name: _dynamic_initializer_for____g_C_WeaponCSBaseClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_WeaponCSBaseClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_WeaponCSBaseClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_WeaponCSBaseClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10428360
// Name: _dynamic_initializer_for__cl_bobcycle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_bobcycle__()
{
  ConVar::ConVar(this: &cl_bobcycle, pName: "cl_bobcycle", pDefaultValue: "1.0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__cl_bobcycle__);
}

//------------------------------------------------------------------------------
// Address: 0x10428390
// Name: _dynamic_initializer_for__cl_bob__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_bob__()
{
  ConVar::ConVar(this: &cl_bob, pName: "cl_bob", pDefaultValue: "0.002", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__cl_bob__);
}

//------------------------------------------------------------------------------
// Address: 0x104283C0
// Name: _dynamic_initializer_for__cl_bobup__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_bobup__()
{
  ConVar::ConVar(this: &cl_bobup, pName: "cl_bobup", pDefaultValue: "0.5", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__cl_bobup__);
}

//------------------------------------------------------------------------------
// Address: 0x104283F0
// Name: _dynamic_initializer_for__cl_use_new_headbob__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_use_new_headbob__()
{
  ConVar::ConVar(this: &cl_use_new_headbob, pName: "cl_use_new_headbob", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__cl_use_new_headbob__);
}

//------------------------------------------------------------------------------
// Address: 0x10428420
// Name: _dynamic_initializer_for__cl_bobamt_vert__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_bobamt_vert__()
{
  ConVar::ConVar(this: &cl_bobamt_vert, pName: "cl_bobamt_vert", pDefaultValue: "0.13", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__cl_bobamt_vert__);
}

//------------------------------------------------------------------------------
// Address: 0x10428450
// Name: _dynamic_initializer_for__cl_bobamt_lat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_bobamt_lat__()
{
  ConVar::ConVar(this: &cl_bobamt_lat, pName: "cl_bobamt_lat", pDefaultValue: "0.32", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__cl_bobamt_lat__);
}

//------------------------------------------------------------------------------
// Address: 0x10428480
// Name: _dynamic_initializer_for__cl_bob_lower_amt__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_bob_lower_amt__()
{
  ConVar::ConVar(this: &cl_bob_lower_amt, pName: "cl_bob_lower_amt", pDefaultValue: "8", flags: 128);
  return atexit(func: dynamic_atexit_destructor_for__cl_bob_lower_amt__);
}

//------------------------------------------------------------------------------
// Address: 0x104284B0
// Name: _dynamic_initializer_for____g_C_WeaponCSBaseGunClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_WeaponCSBaseGunClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_WeaponCSBaseGunClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_WeaponCSBaseGunClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10435860
// Name: _dynamic_atexit_destructor_for__g_GroupedSounds__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_GroupedSounds__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_GroupedSounds);
}

//------------------------------------------------------------------------------
// Address: 0x10435FA0
// Name: _dynamic_atexit_destructor_for__cl_bobcycle__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_bobcycle__()
{
  ConVar::~ConVar(this: &cl_bobcycle);
}

//------------------------------------------------------------------------------
// Address: 0x10435FB0
// Name: _dynamic_atexit_destructor_for__cl_bob__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_bob__()
{
  ConVar::~ConVar(this: &cl_bob);
}

//------------------------------------------------------------------------------
// Address: 0x10435FC0
// Name: _dynamic_atexit_destructor_for__cl_bobup__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_bobup__()
{
  ConVar::~ConVar(this: &cl_bobup);
}

//------------------------------------------------------------------------------
// Address: 0x10435FD0
// Name: _dynamic_atexit_destructor_for__cl_use_new_headbob__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_use_new_headbob__()
{
  ConVar::~ConVar(this: &cl_use_new_headbob);
}

//------------------------------------------------------------------------------
// Address: 0x10435FE0
// Name: _dynamic_atexit_destructor_for__cl_bobamt_vert__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_bobamt_vert__()
{
  ConVar::~ConVar(this: &cl_bobamt_vert);
}

//------------------------------------------------------------------------------
// Address: 0x10435FF0
// Name: _dynamic_atexit_destructor_for__cl_bobamt_lat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_bobamt_lat__()
{
  ConVar::~ConVar(this: &cl_bobamt_lat);
}

//------------------------------------------------------------------------------
// Address: 0x10436000
// Name: _dynamic_atexit_destructor_for__cl_bob_lower_amt__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_bob_lower_amt__()
{
  ConVar::~ConVar(this: &cl_bob_lower_amt);
}
