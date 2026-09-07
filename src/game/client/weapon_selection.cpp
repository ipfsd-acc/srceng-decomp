// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/weapon_selection.cpp
// Functions: 49
// ============================================================

#include "game\client\weapon_selection.h"

//------------------------------------------------------------------------------
// Address: 0x101AD2A0
// Name: void __CmdFunc_Slot3(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __CmdFunc_Slot3()
{
  CHud *Hud; // eax
  CHudElement *Element; // eax

  Hud = GetHud(nSlot: -1);
  Element = CHud::FindElement(this: Hud, pName: "CHudWeaponSelection");
  if ( Element != nullptr )
    Element->__vftable[2].dtr_IGameEventListener2(this: Element);
}

//------------------------------------------------------------------------------
// Address: 0x101AD2D0
// Name: void __CmdFunc_Slot4(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __CmdFunc_Slot4()
{
  CHud *Hud; // eax
  CHudElement *Element; // eax

  Hud = GetHud(nSlot: -1);
  Element = CHud::FindElement(this: Hud, pName: "CHudWeaponSelection");
  if ( Element != nullptr )
    ((void (__thiscall *)(CHudElement *))Element->__vftable[2].FireGameEvent)(a1: Element);
}

//------------------------------------------------------------------------------
// Address: 0x101AD300
// Name: void __CmdFunc_Slot6(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __CmdFunc_Slot6()
{
  CHud *Hud; // eax
  CHudElement *Element; // eax

  Hud = GetHud(nSlot: -1);
  Element = CHud::FindElement(this: Hud, pName: "CHudWeaponSelection");
  if ( Element != nullptr )
    Element->__vftable[2].GetEventDebugID(this: Element);
}

//------------------------------------------------------------------------------
// Address: 0x101AD330
// Name: void __CmdFunc_Slot7(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __CmdFunc_Slot7()
{
  CHud *Hud; // eax
  CHudElement *Element; // eax

  Hud = GetHud(nSlot: -1);
  Element = CHud::FindElement(this: Hud, pName: "CHudWeaponSelection");
  if ( Element != nullptr )
    ((void (__thiscall *)(CHudElement *))Element->__vftable[2].SetHud)(a1: Element);
}

//------------------------------------------------------------------------------
// Address: 0x101AD360
// Name: void __CmdFunc_Slot8(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __CmdFunc_Slot8()
{
  CHud *Hud; // eax
  CHudElement *Element; // eax

  Hud = GetHud(nSlot: -1);
  Element = CHud::FindElement(this: Hud, pName: "CHudWeaponSelection");
  if ( Element != nullptr )
    Element->__vftable[2].Init(this: Element);
}

//------------------------------------------------------------------------------
// Address: 0x101AD390
// Name: void __CmdFunc_Slot9(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __CmdFunc_Slot9()
{
  CHud *Hud; // eax
  CHudElement *Element; // eax

  Hud = GetHud(nSlot: -1);
  Element = CHud::FindElement(this: Hud, pName: "CHudWeaponSelection");
  if ( Element != nullptr )
    Element->__vftable[2].VidInit(this: Element);
}

//------------------------------------------------------------------------------
// Address: 0x101AD3C0
// Name: void __CmdFunc_Slot10(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __CmdFunc_Slot10()
{
  CHud *Hud; // eax
  CHudElement *Element; // eax

  Hud = GetHud(nSlot: -1);
  Element = CHud::FindElement(this: Hud, pName: "CHudWeaponSelection");
  if ( Element != nullptr )
    Element->__vftable[2].LevelInit(this: Element);
}

//------------------------------------------------------------------------------
// Address: 0x101AD3F0
// Name: class CBaseHudWeaponSelection __near * GetHudWeaponSelection(void)
// Source: json
//------------------------------------------------------------------------------
CBaseHudWeaponSelection *__cdecl GetHudWeaponSelection()
{
  return CBaseHudWeaponSelection::s_pInstance[0];
}

//------------------------------------------------------------------------------
// Address: 0x101AD400
// Name: public: virtual void CBaseHudWeaponSelection::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudWeaponSelection::Init(CBaseHudWeaponSelection *this)
{
  this->Reset(this);
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&gWR);
  this->m_flSelectionTime = *(float *)(gpGlobals.m_Index + 12);
}

//------------------------------------------------------------------------------
// Address: 0x101AD430
// Name: public: virtual void CBaseHudWeaponSelection::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudWeaponSelection::Reset(CBaseHudWeaponSelection *this)
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&gWR);
  this->m_bSelectionVisible = false;
  this->m_flSelectionTime = *(float *)(gpGlobals.m_Index + 12);
}

//------------------------------------------------------------------------------
// Address: 0x101AD450
// Name: public: virtual void CBaseHudWeaponSelection::VidInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudWeaponSelection::VidInit(CBaseHudWeaponSelection *this)
{
  WeaponsResource::LoadAllWeaponSprites(this: &gWR);
  this->Reset(this);
}

//------------------------------------------------------------------------------
// Address: 0x101AD470
// Name: public: virtual bool CBaseHudWeaponSelection::IsInSelectionMode(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseHudWeaponSelection::IsInSelectionMode(CBaseHudWeaponSelection *this)
{
  return this->m_bSelectionVisible;
}

//------------------------------------------------------------------------------
// Address: 0x101AD480
// Name: public: virtual void CBaseHudWeaponSelection::OpenSelection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudWeaponSelection::OpenSelection(CBaseHudWeaponSelection *this)
{
  this->m_bSelectionVisible = true;
}

//------------------------------------------------------------------------------
// Address: 0x101AD490
// Name: public: virtual void CBaseHudWeaponSelection::HideSelection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudWeaponSelection::HideSelection(CBaseHudWeaponSelection *this)
{
  this->m_bSelectionVisible = false;
}

//------------------------------------------------------------------------------
// Address: 0x101AD4A0
// Name: public: virtual void CBaseHudWeaponSelection::UserCmd_Slot6(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudWeaponSelection::UserCmd_Slot6(CBaseHudWeaponSelection *this)
{
  this->SelectSlot(this, a2: 6);
}

//------------------------------------------------------------------------------
// Address: 0x101AD4B0
// Name: public: virtual void CBaseHudWeaponSelection::UserCmd_Slot7(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudWeaponSelection::UserCmd_Slot7(CBaseHudWeaponSelection *this)
{
  this->SelectSlot(this, a2: 7);
}

//------------------------------------------------------------------------------
// Address: 0x101AD4C0
// Name: public: virtual void CBaseHudWeaponSelection::UserCmd_Slot8(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudWeaponSelection::UserCmd_Slot8(CBaseHudWeaponSelection *this)
{
  this->SelectSlot(this, a2: 8);
}

//------------------------------------------------------------------------------
// Address: 0x101AD4D0
// Name: public: virtual void CBaseHudWeaponSelection::UserCmd_Slot9(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudWeaponSelection::UserCmd_Slot9(CBaseHudWeaponSelection *this)
{
  this->SelectSlot(this, a2: 9);
}

//------------------------------------------------------------------------------
// Address: 0x101AD4E0
// Name: public: virtual void CBaseHudWeaponSelection::UserCmd_Slot10(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudWeaponSelection::UserCmd_Slot10(CBaseHudWeaponSelection *this)
{
  this->SelectSlot(this, a2: 10);
}

//------------------------------------------------------------------------------
// Address: 0x101AD4F0
// Name: public: virtual bool CBaseHudWeaponSelection::IsHudMenuTakingInput(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseHudWeaponSelection::IsHudMenuTakingInput(CBaseHudWeaponSelection *this)
{
  CHud *Hud; // eax
  CHudMenu *Element; // eax

  Hud = GetHud(nSlot: -1);
  Element = (CHudMenu *)CHud::FindElement(this: Hud, pName: "CHudMenu");
  return Element != nullptr && CHudMenu::IsMenuOpen(this: Element);
}

//------------------------------------------------------------------------------
// Address: 0x101AD520
// Name: public: bool CBaseHudWeaponSelection::HandleHudMenuInput(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseHudWeaponSelection::HandleHudMenuInput(CBaseHudWeaponSelection *this, int iSlot)
{
  CHud *Hud; // eax
  CHudMenu *Element; // eax
  CHudMenu *v4; // esi

  Hud = GetHud(nSlot: -1);
  Element = (CHudMenu *)CHud::FindElement(this: Hud, pName: "CHudMenu");
  v4 = Element;
  if ( Element == nullptr || !CHudMenu::IsMenuOpen(this: Element) )
    return 0;
  CHudMenu::SelectMenuItem(this: v4, menu_item: iSlot);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101AD570
// Name: public: virtual void CBaseHudWeaponSelection::SelectSlot(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudWeaponSelection::SelectSlot(CBaseHudWeaponSelection *this, int iSlot)
{
  CHud *Hud; // eax
  CHudMenu *Element; // eax
  CHudMenu *v5; // esi
  CBaseHudWeaponSelection_vtbl *v6; // edx

  Hud = GetHud(nSlot: -1);
  Element = (CHudMenu *)CHud::FindElement(this: Hud, pName: "CHudMenu");
  v5 = Element;
  if ( Element != nullptr && CHudMenu::IsMenuOpen(this: Element) )
  {
    CHudMenu::SelectMenuItem(this: v5, menu_item: iSlot);
  }
  else if ( CHudElement::ShouldDraw(this) != 0 )
  {
    v6 = this->__vftable;
    this->m_flSelectionTime = *(float *)(gpGlobals.m_Index + 12);
    v6->SelectWeaponSlot(this, a2: iSlot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AD5E0
// Name: public: virtual void CBaseHudWeaponSelection::SwitchToLastWeapon(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudWeaponSelection::SwitchToLastWeapon(CBaseHudWeaponSelection *this)
{
  C_BasePlayer *LocalPlayer; // eax
  IInput_vtbl *v2; // esi
  int v3; // eax

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
  {
    v2 = input->__vftable;
    v3 = (int)LocalPlayer->GetLastWeapon(this: LocalPlayer);
    v2->MakeWeaponSelection(this: input, a2: (C_BaseCombatWeapon *)v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AD620
// Name: public: virtual void CBaseHudWeaponSelection::SetWeaponSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudWeaponSelection::SetWeaponSelected(CBaseHudWeaponSelection *this)
{
  IInput_vtbl *v1; // esi
  C_BaseCombatWeapon *v2; // eax

  v1 = input->__vftable;
  v2 = this->GetSelectedWeapon(this);
  v1->MakeWeaponSelection(this: input, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x101AD640
// Name: public: virtual class C_BaseCombatWeapon __near * CBaseHudWeaponSelection::GetFirstPos(int)
// Source: json
//------------------------------------------------------------------------------
C_BaseCombatWeapon *__thiscall CBaseHudWeaponSelection::GetFirstPos(CBaseHudWeaponSelection *this, int iSlot)
{
  int v2; // edi
  C_BasePlayer *LocalPlayer; // ebx
  int v5; // esi
  C_BaseCombatWeapon *pFirstWeapon; // [esp+8h] [ebp-8h]
  int iLowestPosition; // [esp+Ch] [ebp-4h]

  v2 = 0;
  iLowestPosition = 20;
  pFirstWeapon = nullptr;
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer == nullptr )
    return nullptr;
  do
  {
    v5 = (int)LocalPlayer->GetWeapon(this: LocalPlayer, a2: v2);
    if ( v5 != 0
      && (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 1288))(a1: v5) == iSlot
      && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 924))(a1: v5) != 0
      && (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 1292))(a1: v5) <= iLowestPosition )
    {
      iLowestPosition = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 1292))(a1: v5);
      pFirstWeapon = (C_BaseCombatWeapon *)v5;
    }
    ++v2;
  }
  while ( v2 < 64 );
  return pFirstWeapon;
}

//------------------------------------------------------------------------------
// Address: 0x101AD6E0
// Name: void __CmdFunc_Slot5(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __CmdFunc_Slot5()
{
  CHud *Hud; // eax
  CHudElement *Element; // eax

  Hud = GetHud(nSlot: -1);
  Element = CHud::FindElement(this: Hud, pName: "CHudWeaponSelection");
  if ( Element != nullptr )
    ((void (__thiscall *)(CHudElement *, int))Element->__vftable[2].LevelShutdown)(a1: Element, a2: 5);
}

//------------------------------------------------------------------------------
// Address: 0x101AD710
// Name: void __CmdFunc_Slot0(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __CmdFunc_Slot0()
{
  CHud *Hud; // eax
  CHudElement *Element; // eax

  Hud = GetHud(nSlot: -1);
  Element = CHud::FindElement(this: Hud, pName: "CHudWeaponSelection");
  if ( Element != nullptr )
    ((void (__thiscall *)(CHudElement *, _DWORD))Element->__vftable[2].LevelShutdown)(a1: Element, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101AD740
// Name: void __CmdFunc_Close(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __CmdFunc_Close()
{
  CHud *Hud; // eax
  CHudElement *Element; // eax

  Hud = GetHud(nSlot: -1);
  Element = CHud::FindElement(this: Hud, pName: "CHudWeaponSelection");
  if ( Element != nullptr )
    ((void (__thiscall *)(CHudElement *))Element->__vftable[1].SetHud)(a1: Element);
}

//------------------------------------------------------------------------------
// Address: 0x101AD770
// Name: void __CmdFunc_LastWeapon(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __CmdFunc_LastWeapon()
{
  CHud *Hud; // eax
  CHudElement *Element; // eax
  CHudElement *v2; // esi

  Hud = GetHud(nSlot: -1);
  Element = CHud::FindElement(this: Hud, pName: "CHudWeaponSelection");
  v2 = Element;
  if ( Element != nullptr && CHudElement::ShouldDraw(this: Element) != 0 )
    v2->__vftable[1].LevelInit(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x101AD7B0
// Name: public: virtual void CBaseHudWeaponSelection::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudWeaponSelection::OnThink(CBaseHudWeaponSelection *this)
{
  C_BasePlayer *LocalPlayer; // eax

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( ((LocalPlayer->m_fFlags & 0x40) != 0 || C_BasePlayer::IsPlayerDead(this: LocalPlayer))
    && this->IsInSelectionMode(this) )
  {
    this->CancelWeaponSelection(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AD7F0
// Name: public: virtual void CBaseHudWeaponSelection::ProcessInput(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudWeaponSelection::ProcessInput(CBaseHudWeaponSelection *this)
{
  C_BasePlayer *LocalPlayer; // eax
  C_BasePlayer *v3; // esi
  CHud *v4; // eax
  CHud *Hud; // eax

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  v3 = LocalPlayer;
  if ( LocalPlayer != nullptr )
  {
    if ( !C_BasePlayer::IsInVGuiInputMode(this: LocalPlayer) || C_BasePlayer::IsInViewModelVGuiInputMode(this: v3) )
    {
      if ( (GetHud(nSlot: -1)->m_iKeyBits & 0x80801) != 0 && this->IsWeaponSelectable(this) )
      {
        if ( hud_fastswitch.m_pParent == nullptr || hud_fastswitch.m_pParent->m_Value.m_nValue != 2 )
        {
          Hud = GetHud(nSlot: -1);
          Hud->m_iKeyBits &= 0xFFF7F7FE;
          input->ClearInputButton(this: input, a2: 1);
          input->ClearInputButton(this: input, a2: 2048);
          input->ClearInputButton(this: input, a2: 0x80000);
        }
        this->SelectWeapon(this);
      }
    }
    else if ( (GetHud(nSlot: -1)->m_iKeyBits & 1) != 0 )
    {
      if ( hud_fastswitch.m_pParent == nullptr || hud_fastswitch.m_pParent->m_Value.m_nValue != 2 )
      {
        v4 = GetHud(nSlot: -1);
        v4->m_iKeyBits &= ~1u;
        input->ClearInputButton(this: input, a2: 1);
      }
      engine->ClientCmd(this: engine, a2: "cancelselect\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AD900
// Name: protected: bool CBaseHudWeaponSelection::CanBeSelectedInHUD(class C_BaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseHudWeaponSelection::CanBeSelectedInHUD(CBaseHudWeaponSelection *this, C_BaseCombatWeapon *pWeapon)
{
  bool result; // al

  if ( hud_fastswitch.m_pParent != nullptr && hud_fastswitch.m_pParent->m_Value.m_nValue == 2 )
    return pWeapon->VisibleInWeaponSelection(this: pWeapon);
  result = pWeapon->VisibleInWeaponSelection(this: pWeapon);
  if ( result )
    return pWeapon->CanBeSelected(this: pWeapon);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AD950
// Name: public: virtual int CBaseHudWeaponSelection::KeyInput(int,enum ButtonCode_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseHudWeaponSelection::KeyInput(
        CBaseHudWeaponSelection *this,
        int down,
        ButtonCode_t keynum,
        const char *pszCurrentBinding)
{
  if ( this->IsInSelectionMode(this)
    && pszCurrentBinding != nullptr
    && _V_stricmp(s1: pszCurrentBinding, s2: "cancelselect") == 0 )
  {
    this->HideSelection(this);
    return false;
  }
  return down < 1
      || (unsigned int)(keynum - 2) > 8
      || CBaseHudWeaponSelection::HandleHudMenuInput(this, iSlot: keynum - 1) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101AD9C0
// Name: public: virtual void CBaseHudWeaponSelection::UserCmd_Slot3(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudWeaponSelection::UserCmd_Slot3(CBaseHudWeaponSelection *this)
{
  if ( hud_fastswitch.m_pParent != nullptr && hud_fastswitch.m_pParent->m_Value.m_nValue == 3 )
    engine->ClientCmd(this: engine, a2: "phys_swap");
  else
    this->SelectSlot(this, a2: 3);
}

//------------------------------------------------------------------------------
// Address: 0x101AD9F0
// Name: public: virtual bool CBaseHudWeaponSelection::IsHudMenuPreventingWeaponSelection(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseHudWeaponSelection::IsHudMenuPreventingWeaponSelection(CBaseHudWeaponSelection *this)
{
  C_BasePlayer *LocalPlayer; // eax

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  return (LocalPlayer->m_fFlags & 0x40) != 0
      || C_BasePlayer::IsPlayerDead(this: LocalPlayer)
      || this->IsHudMenuTakingInput(this);
}

//------------------------------------------------------------------------------
// Address: 0x101ADA30
// Name: public: virtual class C_BaseCombatWeapon __near * CBaseHudWeaponSelection::GetNextActivePos(int,int)
// Source: json
//------------------------------------------------------------------------------
C_BaseCombatWeapon *__thiscall CBaseHudWeaponSelection::GetNextActivePos(
        CBaseHudWeaponSelection *this,
        int iSlot,
        int iSlotPos)
{
  int v3; // edi
  C_BasePlayer *LocalPlayer; // ebx
  C_BaseCombatWeapon *v6; // eax
  C_BaseCombatWeapon *v7; // esi
  C_BaseCombatWeapon *pNextWeapon; // [esp+4h] [ebp-8h]
  int iLowestPosition; // [esp+8h] [ebp-4h]

  if ( iSlotPos >= 20 || iSlot >= 11 )
    return nullptr;
  v3 = 0;
  iLowestPosition = 20;
  pNextWeapon = nullptr;
  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer == nullptr )
    return nullptr;
  do
  {
    v6 = LocalPlayer->GetWeapon(this: LocalPlayer, a2: v3);
    v7 = v6;
    if ( v6 != nullptr
      && CBaseHudWeaponSelection::CanBeSelectedInHUD(this, pWeapon: v6)
      && v7->GetSlot(this: v7) == iSlot
      && v7->GetPosition(this: v7) <= iLowestPosition
      && v7->GetPosition(this: v7) >= iSlotPos )
    {
      iLowestPosition = v7->GetPosition(this: v7);
      pNextWeapon = v7;
    }
    ++v3;
  }
  while ( v3 < 64 );
  return pNextWeapon;
}

//------------------------------------------------------------------------------
// Address: 0x101ADB00
// Name: void __CmdFunc_Slot1(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __CmdFunc_Slot1()
{
  CHud *Hud; // eax
  CHudElement *Element; // esi

  Hud = GetHud(nSlot: -1);
  Element = CHud::FindElement(this: Hud, pName: "CHudWeaponSelection");
  if ( Element != nullptr )
  {
    if ( hud_fastswitch.m_pParent != nullptr && hud_fastswitch.m_pParent->m_Value.m_nValue == 3 )
    {
      if ( CHudElement::ShouldDraw(this: Element) != 0 )
        Element->__vftable[1].LevelInit(this: Element);
    }
    else
    {
      ((void (__thiscall *)(CHudElement *, int))Element->__vftable[2].LevelShutdown)(a1: Element, a2: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ADB60
// Name: void __CmdFunc_NextWeapon(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __CmdFunc_NextWeapon()
{
  CHud *Hud; // eax
  CHudElement *Element; // eax
  float *v2; // esi

  Hud = GetHud(nSlot: -1);
  Element = CHud::FindElement(this: Hud, pName: "CHudWeaponSelection");
  v2 = (float *)Element;
  if ( Element != nullptr && CHudElement::ShouldDraw(this: Element) != 0 )
  {
    (*(void (__thiscall **)(float *))(*(_DWORD *)v2 + 88))(a1: v2);
    if ( hud_fastswitch.m_pParent != nullptr && hud_fastswitch.m_pParent->m_Value.m_nValue > 0 )
      (*(void (__thiscall **)(float *))(*(_DWORD *)v2 + 128))(a1: v2);
    v2[14] = *(float *)(gpGlobals.m_Index + 12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ADBC0
// Name: void __CmdFunc_PrevWeapon(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __CmdFunc_PrevWeapon()
{
  CHud *Hud; // eax
  CHudElement *Element; // eax
  float *v2; // esi

  Hud = GetHud(nSlot: -1);
  Element = CHud::FindElement(this: Hud, pName: "CHudWeaponSelection");
  v2 = (float *)Element;
  if ( Element != nullptr && CHudElement::ShouldDraw(this: Element) != 0 )
  {
    (*(void (__thiscall **)(float *))(*(_DWORD *)v2 + 92))(a1: v2);
    if ( hud_fastswitch.m_pParent != nullptr && hud_fastswitch.m_pParent->m_Value.m_nValue > 0 )
      (*(void (__thiscall **)(float *))(*(_DWORD *)v2 + 128))(a1: v2);
    v2[14] = *(float *)(gpGlobals.m_Index + 12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ADC20
// Name: void __CmdFunc_NextGrenadeWeapon(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __CmdFunc_NextGrenadeWeapon()
{
  CHud *Hud; // eax
  CHudElement *Element; // eax
  float *v2; // esi

  Hud = GetHud(nSlot: -1);
  Element = CHud::FindElement(this: Hud, pName: "CHudWeaponSelection");
  v2 = (float *)Element;
  if ( Element != nullptr && CHudElement::ShouldDraw(this: Element) != 0 )
  {
    (*(void (__thiscall **)(float *))(*(_DWORD *)v2 + 100))(a1: v2);
    if ( hud_fastswitch.m_pParent != nullptr && hud_fastswitch.m_pParent->m_Value.m_nValue > 0 )
      (*(void (__thiscall **)(float *))(*(_DWORD *)v2 + 128))(a1: v2);
    v2[14] = *(float *)(gpGlobals.m_Index + 12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ADC80
// Name: void __CmdFunc_NextNonGrenadeWeapon(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __CmdFunc_NextNonGrenadeWeapon()
{
  CHud *Hud; // eax
  CHudElement *Element; // eax
  float *v2; // esi

  Hud = GetHud(nSlot: -1);
  Element = CHud::FindElement(this: Hud, pName: "CHudWeaponSelection");
  v2 = (float *)Element;
  if ( Element != nullptr && CHudElement::ShouldDraw(this: Element) != 0 )
  {
    (*(void (__thiscall **)(float *))(*(_DWORD *)v2 + 104))(a1: v2);
    if ( hud_fastswitch.m_pParent != nullptr && hud_fastswitch.m_pParent->m_Value.m_nValue > 0 )
      (*(void (__thiscall **)(float *))(*(_DWORD *)v2 + 128))(a1: v2);
    v2[14] = *(float *)(gpGlobals.m_Index + 12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ADCE0
// Name: public: CBaseHudWeaponSelection::CBaseHudWeaponSelection(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseHudWeaponSelection *__thiscall CBaseHudWeaponSelection::CBaseHudWeaponSelection(
        CBaseHudWeaponSelection *this,
        const char *pElementName)
{
  CHudElement::CHudElement(this, pElementName);
  this->__vftable = (CBaseHudWeaponSelection_vtbl *)&CBaseHudWeaponSelection::`vftable';
  this->m_hSelectedWeapon.m_Index = -1;
  CBaseHudWeaponSelection::s_pInstance[0] = this;
  CTraceFilterSkipTwoEntities::SetPassEntity2(
    (CTraceFilterSkipTwoEntities *)this,
    pPassEntity2: (const IHandleEntity *)0x431);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101ADD20
// Name: protected: virtual bool CBaseHudWeaponSelection::IsWeaponSelectable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseHudWeaponSelection::IsWeaponSelectable(CBaseHudWeaponSelection *this)
{
  return this->IsInSelectionMode(this);
}

//------------------------------------------------------------------------------
// Address: 0x101ADD60
// Name: public: void CBaseHudWeaponSelection::UserCmd_Slot2(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudWeaponSelection::UserCmd_Slot2(CBaseHudWeaponSelection *this)
{
  if ( hud_fastswitch.m_pParent != nullptr && hud_fastswitch.m_pParent->m_Value.m_nValue == 3 )
  {
    if ( CHudElement::ShouldDraw(this) != 0 )
    {
      this->CycleToNextWeapon(this);
      if ( hud_fastswitch.m_pParent != nullptr && hud_fastswitch.m_pParent->m_Value.m_nValue > 0 )
        this->SelectWeapon(this);
      this->m_flSelectionTime = *(float *)(gpGlobals.m_Index + 12);
    }
  }
  else
  {
    this->SelectSlot(this, a2: 2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ADDC0
// Name: public: virtual void CBaseHudWeaponSelection::UserCmd_Slot4(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudWeaponSelection::UserCmd_Slot4(CBaseHudWeaponSelection *this)
{
  if ( hud_fastswitch.m_pParent != nullptr && hud_fastswitch.m_pParent->m_Value.m_nValue == 3 )
  {
    if ( CHudElement::ShouldDraw(this) != 0 )
    {
      this->CycleToPrevWeapon(this);
      if ( hud_fastswitch.m_pParent != nullptr && hud_fastswitch.m_pParent->m_Value.m_nValue > 0 )
        this->SelectWeapon(this);
      this->m_flSelectionTime = *(float *)(gpGlobals.m_Index + 12);
    }
  }
  else
  {
    this->SelectSlot(this, a2: 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ADE20
// Name: void __CmdFunc_Slot2(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __CmdFunc_Slot2()
{
  CHud *Hud; // eax
  CBaseHudWeaponSelection *Element; // eax

  Hud = GetHud(nSlot: -1);
  Element = (CBaseHudWeaponSelection *)CHud::FindElement(this: Hud, pName: "CHudWeaponSelection");
  if ( Element != nullptr )
    CBaseHudWeaponSelection::UserCmd_Slot2(this: Element);
}

//------------------------------------------------------------------------------
// Address: 0x101ADE50
// Name: public: virtual void CBaseHudWeaponSelection::SelectWeapon(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudWeaponSelection::SelectWeapon(CBaseHudWeaponSelection *this)
{
  C_BasePlayer *LocalPlayer; // edi
  C_BaseCombatWeapon *v3; // eax

  if ( this->GetSelectedWeapon(this) != nullptr )
  {
    LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    if ( LocalPlayer != nullptr )
    {
      v3 = this->GetSelectedWeapon(this);
      if ( v3->CanBeSelected(this: v3) )
      {
        this->SetWeaponSelected(this);
        this->m_hSelectedWeapon.m_Index = -1;
        engine->ClientCmd(this: engine, a2: "cancelselect\n");
        C_BaseEntity::EmitSound(this: LocalPlayer, soundname: "Player.WeaponSelected", soundtime: 0, duration: nullptr);
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
// Address: 0x101ADF00
// Name: public: virtual void CBaseHudWeaponSelection::CancelWeaponSelection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudWeaponSelection::CancelWeaponSelection(CBaseHudWeaponSelection *this)
{
  C_BasePlayer *LocalPlayer; // edi

  LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
  if ( LocalPlayer != nullptr )
  {
    if ( this->ShouldDraw(this) )
    {
      this->HideSelection(this);
      this->m_hSelectedWeapon.m_Index = -1;
      C_BaseEntity::EmitSound(
        this: LocalPlayer,
        soundname: "Player.WeaponSelectionClose",
        soundtime: 0,
        duration: nullptr);
    }
    else
    {
      engine->ClientCmd(this: engine, a2: "escape");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102DE5F0
// Name: public: virtual void CBaseHudWeaponSelection::DrawWList(class C_BasePlayer __near *,class C_BaseCombatWeapon __near *,bool,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseHudWeaponSelection::DrawWList(
        CDefaultParticleSystemQuery *this,
        const Vector *origin,
        const Vector *target,
        const Vector *r,
        int g,
        int b,
        bool noDepthTest,
        float duration)
{
  ;
}
