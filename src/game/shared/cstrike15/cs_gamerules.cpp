// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/cs_gamerules.cpp
// Functions: 46
// ============================================================

#include "game\shared\cstrike15\cs_gamerules.h"

//------------------------------------------------------------------------------
// Address: 0x1000D370
// Name: public: bool C_CSGameRules::IsFreezePeriod(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CSGameRules::IsFreezePeriod(CBaseAchievement *this)
{
  return this->m_iProgressMsgIncrement;
}

//------------------------------------------------------------------------------
// Address: 0x100E8800
// Name: public: virtual int C_CSGameRules::DefaultFOV(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_CSGameRules::DefaultFOV(C_GameRules *this)
{
  return 90;
}

//------------------------------------------------------------------------------
// Address: 0x1014B7F0
// Name: public: float C_CSGameRules::GetRoundStartTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_CSGameRules::GetRoundStartTime(C_PhysPropClientside *this)
{
  return *(float *)&this->m_VarMap.m_Entries.m_Memory.m_nGrowSize;
}

//------------------------------------------------------------------------------
// Address: 0x101C5C10
// Name: public: virtual class ClientClass __near * C_CSGameRulesProxy::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_CSGameRulesProxy::GetClientClass(C_CSGameRulesProxy *this)
{
  return &__g_C_CSGameRulesProxyClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x101C5C20
// Name: CC_CSGameRulesProxyFactory
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__cdecl CC_CSGameRulesProxyFactory()
{
  C_GameRulesProxy *v0; // eax
  _DWORD *v1; // esi

  v0 = (C_GameRulesProxy *)C_BaseEntity::operator new(stAllocateBlock: 0x980u);
  v1 = &v0->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v0 == nullptr )
    return nullptr;
  C_GameRulesProxy::C_GameRulesProxy(this: v0);
  *v1 = &C_CSGameRulesProxy::`vftable'{for `IClientUnknown'};
  v1[1] = &C_CSGameRulesProxy::`vftable'{for `IClientRenderable'};
  v1[2] = &C_CSGameRulesProxy::`vftable'{for `IClientNetworkable'};
  v1[3] = &C_CSGameRulesProxy::`vftable'{for `IClientThinkable'};
  v1[4] = &C_CSGameRulesProxy::`vftable';
  return (C_BaseEntity *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x101C5C70
// Name: void RecvProxy_CSGameRules(class RecvProp const __near *,void __near * __near *,void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecvProxy_CSGameRules(const RecvProp *pProp, void **pOut)
{
  *pOut = g_pGameRules;
}

//------------------------------------------------------------------------------
// Address: 0x101C5D10
// Name: public: virtual class C_BaseCombatWeapon __near * C_CSGameRules::GetNextBestWeapon(class C_BaseCombatCharacter __near *,class C_BaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
C_BaseCombatWeapon *__thiscall C_CSGameRules::GetNextBestWeapon(
        C_CSGameRules *this,
        C_BaseCombatCharacter *pPlayer,
        C_BaseCombatWeapon *pCurrentWeapon)
{
  C_BaseCombatWeapon *v3; // edi
  int v4; // eax
  C_BaseCombatWeapon *v5; // eax
  C_BaseCombatWeapon *v6; // esi
  int v7; // ebx
  int v8; // ebx
  int v9; // ebx
  int i; // [esp+Ch] [ebp-4h]

  v3 = nullptr;
  v4 = 0;
  i = 0;
  do
  {
    v5 = pPlayer->GetWeapon(this: pPlayer, a2: v4);
    v6 = v5;
    if ( v5 != nullptr
      && v5->CanBeSelected(this: v5)
      && v6 != pCurrentWeapon
      && (v3 == nullptr
       || (v7 = v6->GetSlot(this: v6)) < v3->GetSlot(this: v3)
       || (v8 = v6->GetSlot(this: v6)) == v3->GetSlot(this: v3)
       && (v9 = v6->GetPosition(this: v6)) < v3->GetPosition(this: v3)) )
    {
      v3 = v6;
    }
    v4 = i + 1;
    i = v4;
  }
  while ( v4 < 64 );
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101C5DD0
// Name: public: virtual class CViewVectors const __near * C_CSGameRules::GetViewVectors(void)const
// Source: json
//------------------------------------------------------------------------------
const CViewVectors *__thiscall C_CSGameRules::GetViewVectors(C_CSGameRules *this)
{
  return &g_CSViewVectors;
}

//------------------------------------------------------------------------------
// Address: 0x101C5DE0
// Name: class CAmmoDef __near * GetAmmoDef(void)
// Source: json
//------------------------------------------------------------------------------
CCSAmmoDef *__cdecl GetAmmoDef()
{
  if ( !bInitted )
  {
    bInitted = true;
    CAmmoDef::AddAmmoType(
      this: &ammoDef,
      name: "BULLET_PLAYER_50AE",
      damageType: 2,
      tracerType: 1,
      plr_cvar: nullptr,
      npc_cvar: nullptr,
      carry_cvar: "ammo_50AE_max",
      physicsForceImpulse: 2400.0,
      nFlags: 0,
      minSplashSize: 10,
      maxSplashSize: 14);
    CAmmoDef::AddAmmoType(
      this: &ammoDef,
      name: "BULLET_PLAYER_762MM",
      damageType: 2,
      tracerType: 1,
      plr_cvar: nullptr,
      npc_cvar: nullptr,
      carry_cvar: "ammo_762mm_max",
      physicsForceImpulse: 2400.0,
      nFlags: 0,
      minSplashSize: 10,
      maxSplashSize: 14);
    CAmmoDef::AddAmmoType(
      this: &ammoDef,
      name: "BULLET_PLAYER_556MM",
      damageType: 2,
      tracerType: 1,
      plr_cvar: nullptr,
      npc_cvar: nullptr,
      carry_cvar: "ammo_556mm_max",
      physicsForceImpulse: 2400.0,
      nFlags: 0,
      minSplashSize: 10,
      maxSplashSize: 14);
    CAmmoDef::AddAmmoType(
      this: &ammoDef,
      name: "BULLET_PLAYER_556MM_BOX",
      damageType: 2,
      tracerType: 1,
      plr_cvar: nullptr,
      npc_cvar: nullptr,
      carry_cvar: "ammo_556mm_box_max",
      physicsForceImpulse: 2400.0,
      nFlags: 0,
      minSplashSize: 10,
      maxSplashSize: 14);
    CAmmoDef::AddAmmoType(
      this: &ammoDef,
      name: "BULLET_PLAYER_338MAG",
      damageType: 2,
      tracerType: 1,
      plr_cvar: nullptr,
      npc_cvar: nullptr,
      carry_cvar: "ammo_338mag_max",
      physicsForceImpulse: 2800.0,
      nFlags: 0,
      minSplashSize: 12,
      maxSplashSize: 16);
    CAmmoDef::AddAmmoType(
      this: &ammoDef,
      name: "BULLET_PLAYER_9MM",
      damageType: 2,
      tracerType: 1,
      plr_cvar: nullptr,
      npc_cvar: nullptr,
      carry_cvar: "ammo_9mm_max",
      physicsForceImpulse: 2000.0,
      nFlags: 0,
      minSplashSize: 5,
      maxSplashSize: 10);
    CAmmoDef::AddAmmoType(
      this: &ammoDef,
      name: "BULLET_PLAYER_BUCKSHOT",
      damageType: 2,
      tracerType: 1,
      plr_cvar: nullptr,
      npc_cvar: nullptr,
      carry_cvar: "ammo_buckshot_max",
      physicsForceImpulse: 600.0,
      nFlags: 0,
      minSplashSize: 3,
      maxSplashSize: 6);
    CAmmoDef::AddAmmoType(
      this: &ammoDef,
      name: "BULLET_PLAYER_45ACP",
      damageType: 2,
      tracerType: 1,
      plr_cvar: nullptr,
      npc_cvar: nullptr,
      carry_cvar: "ammo_45acp_max",
      physicsForceImpulse: 2100.0,
      nFlags: 0,
      minSplashSize: 6,
      maxSplashSize: 10);
    CAmmoDef::AddAmmoType(
      this: &ammoDef,
      name: "BULLET_PLAYER_357SIG",
      damageType: 2,
      tracerType: 1,
      plr_cvar: nullptr,
      npc_cvar: nullptr,
      carry_cvar: "ammo_357sig_max",
      physicsForceImpulse: 2000.0,
      nFlags: 0,
      minSplashSize: 4,
      maxSplashSize: 8);
    CAmmoDef::AddAmmoType(
      this: &ammoDef,
      name: "BULLET_PLAYER_57MM",
      damageType: 2,
      tracerType: 1,
      plr_cvar: nullptr,
      npc_cvar: nullptr,
      carry_cvar: "ammo_57mm_max",
      physicsForceImpulse: 2000.0,
      nFlags: 0,
      minSplashSize: 4,
      maxSplashSize: 8);
    CAmmoDef::AddAmmoType(
      this: &ammoDef,
      name: "AMMO_TYPE_HEGRENADE",
      damageType: 64,
      tracerType: 1,
      plr_cvar: nullptr,
      npc_cvar: nullptr,
      carry_cvar: "ammo_hegrenade_max",
      physicsForceImpulse: 1.0,
      nFlags: 0,
      minSplashSize: 4,
      maxSplashSize: 8);
    CAmmoDef::AddAmmoType(
      this: &ammoDef,
      name: "AMMO_TYPE_FLASHBANG",
      damageType: 0,
      tracerType: 1,
      plr_cvar: nullptr,
      npc_cvar: nullptr,
      carry_cvar: "ammo_flashbang_max",
      physicsForceImpulse: 1.0,
      nFlags: 0,
      minSplashSize: 4,
      maxSplashSize: 8);
    CAmmoDef::AddAmmoType(
      this: &ammoDef,
      name: "AMMO_TYPE_SMOKEGRENADE",
      damageType: 0,
      tracerType: 1,
      plr_cvar: nullptr,
      npc_cvar: nullptr,
      carry_cvar: "ammo_smokegrenade_max",
      physicsForceImpulse: 1.0,
      nFlags: 0,
      minSplashSize: 4,
      maxSplashSize: 8);
    CAmmoDef::AddAmmoType(
      this: &ammoDef,
      name: "AMMO_TYPE_MOLOTOV",
      damageType: 8,
      tracerType: 0,
      plr_cvar: nullptr,
      npc_cvar: nullptr,
      carry_cvar: "ammo_molotov_max",
      physicsForceImpulse: 1.0,
      nFlags: 0,
      minSplashSize: 4,
      maxSplashSize: 8);
    CAmmoDef::AddAmmoType(
      this: &ammoDef,
      name: "AMMO_TYPE_DECOY",
      damageType: 0,
      tracerType: 0,
      plr_cvar: nullptr,
      npc_cvar: nullptr,
      carry_cvar: "ammo_decoy_max",
      physicsForceImpulse: 1.0,
      nFlags: 0,
      minSplashSize: 4,
      maxSplashSize: 8);
    CAmmoDef::AddAmmoType(
      this: &ammoDef,
      name: "AMMO_TYPE_TASERCHARGE",
      damageType: 256,
      tracerType: 3,
      plr_dmg: 0,
      npc_dmg: 0,
      carry: 0,
      physicsForceImpulse: 1.0,
      nFlags: 0,
      minSplashSize: 4,
      maxSplashSize: 8);
    CCSAmmoDef::AddAmmoCost(this: &ammoDef, name: "BULLET_PLAYER_50AE", cost: 0, buySize: 7);
    CCSAmmoDef::AddAmmoCost(this: &ammoDef, name: "BULLET_PLAYER_762MM", cost: 0, buySize: 30);
    CCSAmmoDef::AddAmmoCost(this: &ammoDef, name: "BULLET_PLAYER_556MM", cost: 0, buySize: 30);
    CCSAmmoDef::AddAmmoCost(this: &ammoDef, name: "BULLET_PLAYER_556MM_BOX", cost: 0, buySize: 30);
    CCSAmmoDef::AddAmmoCost(this: &ammoDef, name: "BULLET_PLAYER_338MAG", cost: 0, buySize: 10);
    CCSAmmoDef::AddAmmoCost(this: &ammoDef, name: "BULLET_PLAYER_9MM", cost: 0, buySize: 30);
    CCSAmmoDef::AddAmmoCost(this: &ammoDef, name: "BULLET_PLAYER_BUCKSHOT", cost: 0, buySize: 8);
    CCSAmmoDef::AddAmmoCost(this: &ammoDef, name: "BULLET_PLAYER_45ACP", cost: 0, buySize: 25);
    CCSAmmoDef::AddAmmoCost(this: &ammoDef, name: "BULLET_PLAYER_357SIG", cost: 0, buySize: 13);
    CCSAmmoDef::AddAmmoCost(this: &ammoDef, name: "BULLET_PLAYER_57MM", cost: 0, buySize: 50);
  }
  return &ammoDef;
}

//------------------------------------------------------------------------------
// Address: 0x101C61C0
// Name: public: bool C_CSGameRules::IsPlayingFreestyle(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_CSGameRules::IsPlayingFreestyle(C_CSGameRules *this)
{
  return g_pGameTypes->GetCurrentGameMode(this: g_pGameTypes) == 2
      && g_pGameTypes->GetCurrentGameType(this: g_pGameTypes) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C61F0
// Name: public: bool C_CSGameRules::IsPlayingTraining(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CSGameRules::IsPlayingTraining(C_CSGameRules *this)
{
  return g_pGameTypes->GetCurrentGameType(this: g_pGameTypes) == 2;
}

//------------------------------------------------------------------------------
// Address: 0x101C6210
// Name: public: bool C_CSGameRules::IsPlayingGunGame(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_CSGameRules::IsPlayingGunGame(C_CSGameRules *this)
{
  return g_pGameTypes->GetCurrentGameType(this: g_pGameTypes) == 1;
}

//------------------------------------------------------------------------------
// Address: 0x101C6230
// Name: public: virtual bool C_CSGameRules::ForceSplitScreenPlayersOnToSameTeam(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CSGameRules::ForceSplitScreenPlayersOnToSameTeam(C_CSGameRules *this)
{
  return g_pMatchFramework->IsOnlineGame(this: g_pMatchFramework);
}

//------------------------------------------------------------------------------
// Address: 0x101C6240
// Name: public: struct weeklyprice_t const __near * C_CSGameRules::GetBlackMarketPriceList(void)
// Source: json
//------------------------------------------------------------------------------
const weeklyprice_t *__thiscall C_CSGameRules::GetBlackMarketPriceList(C_CSGameRules *this)
{
  INetworkStringTable *m_StringTableBlackMarket; // edi
  int iSize; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_StringTableBlackMarket == nullptr )
    this->m_StringTableBlackMarket = networkstringtable->FindTable(this: networkstringtable, a2: "BlackMarketTable");
  if ( this->m_pPrices != nullptr )
    goto LABEL_8;
  m_StringTableBlackMarket = this->m_StringTableBlackMarket;
  iSize = 0;
  if ( m_StringTableBlackMarket != nullptr
    && m_StringTableBlackMarket->GetNumStrings(this: m_StringTableBlackMarket) > 0 )
  {
    this->m_pPrices = (const weeklyprice_t *)m_StringTableBlackMarket->GetStringUserData(
                                               this: m_StringTableBlackMarket,
                                               a2: 0,
                                               a3: &iSize);
  }
  if ( this->m_pPrices != nullptr )
LABEL_8:
    PrepareEquipmentInfo();
  return this->m_pPrices;
}

//------------------------------------------------------------------------------
// Address: 0x101C62C0
// Name: public: void C_CSGameRules::OpenBuyMenu(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSGameRules::OpenBuyMenu(C_CSGameRules *this, int nPlayerID)
{
  IViewPort *ViewPortInterface; // eax
  IGameEvent *v3; // esi

  ViewPortInterface = GetViewPortInterface();
  ViewPortInterface->ShowPanel_2(this: ViewPortInterface, a2: "buy", a3: true);
  v3 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "buymenu_open", a3: 0, a4: 0);
  if ( v3 != nullptr )
  {
    v3->SetInt(this: v3, a2: "userid", a3: nPlayerID);
    gameeventmanager->FireEventClientSide(this: gameeventmanager, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C6320
// Name: public: void C_CSGameRules::CloseBuyMenu(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSGameRules::CloseBuyMenu(C_CSGameRules *this, int nPlayerID)
{
  IViewPort *ViewPortInterface; // eax
  IGameEvent *v3; // esi

  ViewPortInterface = GetViewPortInterface();
  ViewPortInterface->ShowPanel_2(this: ViewPortInterface, a2: "buy", a3: false);
  v3 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "buymenu_close", a3: 0, a4: 0);
  if ( v3 != nullptr )
  {
    v3->SetInt(this: v3, a2: "userid", a3: nPlayerID);
    gameeventmanager->FireEventClientSide(this: gameeventmanager, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C6650
// Name: public: float C_CSGameRules::GetMapRemainingTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_CSGameRules::GetMapRemainingTime(C_CSGameRules *this)
{
  int m_nValue; // eax
  float flTimeLeft; // [esp+0h] [ebp-4h]

  if ( mp_timelimit.m_pParent == nullptr )
    return -1.0;
  m_nValue = mp_timelimit.m_pParent->m_Value.m_nValue;
  if ( m_nValue <= 0 )
    return -1.0;
  flTimeLeft = (float)((float)(60 * m_nValue) + this->m_flGameStartTime.m_Value) - *(float *)(gpGlobals.m_Index + 12);
  if ( flTimeLeft < 0.0 )
    return 0.0;
  return flTimeLeft;
}

//------------------------------------------------------------------------------
// Address: 0x101C66B0
// Name: public: float C_CSGameRules::GetRoundRemainingTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_CSGameRules::GetRoundRemainingTime(C_CSGameRules *this)
{
  return (double)this->m_iRoundTime.m_Value + this->m_fRoundStartTime.m_Value - *(float *)(gpGlobals.m_Index + 12);
}

//------------------------------------------------------------------------------
// Address: 0x101C66C0
// Name: public: float C_CSGameRules::GetRoundElapsedTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_CSGameRules::GetRoundElapsedTime(C_CSGameRules *this)
{
  return *(float *)(gpGlobals.m_Index + 12) - this->m_fRoundStartTime.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x101C66D0
// Name: public: virtual bool C_CSGameRules::ShouldCollide(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CSGameRules::ShouldCollide(C_CSGameRules *this, int collisionGroup0, int collisionGroup1)
{
  int v3; // eax
  int v4; // edx

  v3 = collisionGroup0;
  v4 = collisionGroup1;
  if ( collisionGroup0 > collisionGroup1 )
  {
    v3 = collisionGroup1;
    v4 = collisionGroup0;
  }
  if ( v3 == 8 )
  {
    if ( v4 == 11 )
    {
LABEL_5:
      LOBYTE(v3) = 0;
      return v3;
    }
  }
  else if ( v3 != 5 )
  {
    goto LABEL_8;
  }
  if ( v4 == 17 )
    goto LABEL_5;
LABEL_8:
  if ( v3 != 1 || v4 != 17 )
    LOBYTE(v3) = C_GameRules::ShouldCollide(this, collisionGroup0: v3, collisionGroup1: v4);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101C6720
// Name: public: bool C_CSGameRules::IsBombDefuseMap(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CSGameRules::IsBombDefuseMap(C_CSGameRules *this)
{
  return this->m_bMapHasBombTarget.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x101C6730
// Name: public: bool C_CSGameRules::IsHostageRescueMap(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CSGameRules::IsHostageRescueMap(C_CSGameRules *this)
{
  return this->m_bMapHasRescueZone.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x101C6740
// Name: public: bool C_CSGameRules::IsLogoMap(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall C_CSGameRules::IsLogoMap(C_CSGameRules *this)
{
  return this->m_bLogoMap.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x101C6750
// Name: public: float C_CSGameRules::GetBuyTimeLength(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_CSGameRules::GetBuyTimeLength(C_CSGameRules *this)
{
  return mp_buytime.m_pParent->m_Value.m_fValue;
}

//------------------------------------------------------------------------------
// Address: 0x101C6760
// Name: public: bool C_CSGameRules::IsBuyTimeElapsed(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_CSGameRules::IsBuyTimeElapsed(C_CSGameRules *this)
{
  return (float)(*(float *)(gpGlobals.m_Index + 12) - this->m_fRoundStartTime.m_Value) > mp_buytime.m_pParent->m_Value.m_fValue;
}

//------------------------------------------------------------------------------
// Address: 0x101C6790
// Name: class CCSAmmoDef __near * GetCSAmmoDef(void)
// Source: json
//------------------------------------------------------------------------------
CCSAmmoDef *__cdecl GetCSAmmoDef()
{
  GetAmmoDef();
  return &ammoDef;
}

//------------------------------------------------------------------------------
// Address: 0x101C67A0
// Name: public: bool C_CSGameRules::IsPlayingGunGameProgressive(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_CSGameRules::IsPlayingGunGameProgressive(C_CSGameRules *this)
{
  return g_pGameTypes->GetCurrentGameType(this: g_pGameTypes) == 1
      && g_pGameTypes->GetCurrentGameMode(this: g_pGameTypes) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C67D0
// Name: public: bool C_CSGameRules::IsPlayingGunGameSelect(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_CSGameRules::IsPlayingGunGameSelect(C_CSGameRules *this)
{
  int result; // eax

  if ( g_pGameTypes->GetCurrentGameType(this: g_pGameTypes) != 1 )
    return 0;
  result = g_pGameTypes->GetCurrentGameMode(this: g_pGameTypes);
  if ( result != 1 )
    return 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C6800
// Name: public: bool C_CSGameRules::IsPlayingGunGameTRBomb(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_CSGameRules::IsPlayingGunGameTRBomb(C_CSGameRules *this)
{
  return g_pGameTypes->GetCurrentGameType(this: g_pGameTypes) == 1
      && g_pGameTypes->GetCurrentGameMode(this: g_pGameTypes) == 2;
}

//------------------------------------------------------------------------------
// Address: 0x101C6830
// Name: public: bool C_CSGameRules::IsPlayingClassicCompetitive(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_CSGameRules::IsPlayingClassicCompetitive(C_CSGameRules *this)
{
  int result; // eax

  if ( g_pGameTypes->GetCurrentGameType(this: g_pGameTypes) != 0 )
    return 0;
  result = g_pGameTypes->GetCurrentGameMode(this: g_pGameTypes);
  if ( result != 1 )
    return 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101C6860
// Name: public: int C_CSGameRules::GetBlackMarketPriceForWeapon(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_CSGameRules::GetBlackMarketPriceForWeapon(C_CSGameRules *this, int iWeaponID)
{
  const weeklyprice_t *m_pPrices; // esi

  if ( this->m_pPrices == nullptr )
    C_CSGameRules::GetBlackMarketPriceList(this);
  m_pPrices = this->m_pPrices;
  if ( m_pPrices != nullptr )
    return m_pPrices->iCurrentPrice[iWeaponID];
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C68A0
// Name: public: int C_CSGameRules::GetBlackMarketPreviousPriceForWeapon(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_CSGameRules::GetBlackMarketPreviousPriceForWeapon(C_CSGameRules *this, int iWeaponID)
{
  const weeklyprice_t *m_pPrices; // esi

  if ( this->m_pPrices == nullptr )
    C_CSGameRules::GetBlackMarketPriceList(this);
  m_pPrices = this->m_pPrices;
  if ( m_pPrices != nullptr )
    return m_pPrices->iPreviousPrice[iWeaponID];
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101C68E0
// Name: public: void C_CSGameRules::SetBlackMarketPrices(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_CSGameRules::SetBlackMarketPrices(C_CSGameRules *this, bool bSetDefaults)
{
  CSWeaponID i; // esi
  CCSWeaponInfo *WeaponInfo; // eax
  CCSWeaponInfo *v5; // edi
  const weeklyprice_t *m_pPrices; // eax
  int v7; // eax
  const weeklyprice_t *v8; // eax

  for ( i = WEAPON_DEAGLE; i < WEAPON_MAX; ++i )
  {
    if ( i != WEAPON_SHIELDGUN )
    {
      WeaponInfo = GetWeaponInfo(weaponID: i);
      v5 = WeaponInfo;
      if ( WeaponInfo != nullptr )
      {
        if ( bSetDefaults )
        {
          WeaponInfo->m_iWeaponPrice = CCSWeaponInfo::GetDefaultPrice(this: WeaponInfo);
        }
        else
        {
          if ( this->m_pPrices == nullptr )
            C_CSGameRules::GetBlackMarketPriceList(this);
          m_pPrices = this->m_pPrices;
          if ( m_pPrices != nullptr )
            v7 = m_pPrices->iCurrentPrice[i];
          else
            v7 = 0;
          v5->m_iWeaponPrice = v7;
          if ( this->m_pPrices == nullptr )
            C_CSGameRules::GetBlackMarketPriceList(this);
          v8 = this->m_pPrices;
          if ( v8 != nullptr )
            v5->m_iPreviousPrice = v8->iPreviousPrice[i];
          else
            v5->m_iPreviousPrice = 0;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101C6990
// Name: public: int C_CSGameRules::GetMaxSpectatorSlots(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_CSGameRules::GetMaxSpectatorSlots(C_CSGameRules *this)
{
  return this->m_iSpectatorSlotCount.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x101C69A0
// Name: public: int C_CSGameRules::GetCurrentGunGameWeapon(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_CSGameRules::GetCurrentGunGameWeapon(C_CSGameRules *this, int nCurrentWeaponIndex, int nTeamID)
{
  int m_Value; // eax
  int v4; // eax

  if ( nTeamID == 3 )
    m_Value = this->m_iNumGunGameProgressiveWeaponsCT.m_Value;
  else
    m_Value = this->m_iNumGunGameProgressiveWeaponsT.m_Value;
  if ( m_Value == 0 || nCurrentWeaponIndex < 0 )
    return -1;
  v4 = nTeamID == 3 ? this->m_iNumGunGameProgressiveWeaponsCT.m_Value : this->m_iNumGunGameProgressiveWeaponsT.m_Value;
  if ( nCurrentWeaponIndex >= v4 )
    return -1;
  if ( nTeamID == 3 )
    return this->m_GGProgressiveWeaponOrderCT.m_Value[nCurrentWeaponIndex];
  return this->m_GGProgressiveWeaponOrderT.m_Value[nCurrentWeaponIndex];
}

//------------------------------------------------------------------------------
// Address: 0x101C6A00
// Name: public: C_CSGameRules::C_CSGameRules(void)
// Source: json
//------------------------------------------------------------------------------
C_CSGameRules *__thiscall C_CSGameRules::C_CSGameRules(C_CSGameRules *this)
{
  vgui::PropertyPage *v2; // ecx
  bool v4; // [esp+4h] [ebp-4h]

  C_MultiplayRules::C_MultiplayRules(this);
  this->__vftable = (C_CSGameRules_vtbl *)&C_CSGameRules::`vftable';
  g_pGameRules[87].__vftable = nullptr;
  this->m_pPrices = nullptr;
  if ( this->m_bBlackMarket.m_Value )
  {
    C_BaseAnimating::ShutdownBoneSetupThreadPool(this: v2);
    this->m_bBlackMarket.m_Value = false;
  }
  v4 = g_pMatchFramework->IsOnlineGame(this: g_pMatchFramework);
  g_pGameTypes->ApplyConvarsForCurrentMode(this: g_pGameTypes, a2: v4);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101C6A70
// Name: public: virtual unsigned char const __near * C_CSGameRules::GetEncryptionKey(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall C_CSGameRules::GetEncryptionKey(C_CSGameRules *this)
{
  return "d7NSuLq2";
}

//------------------------------------------------------------------------------
// Address: 0x101C6A80
// Name: void __CreateGameRules_CCSGameRules(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __CreateGameRules_CCSGameRules()
{
  C_CSGameRules *v0; // esi

  v0 = (C_CSGameRules *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 1052);
  _V_memset(dest: v0, fill: 0, count: 1052);
  if ( v0 != nullptr )
    C_CSGameRules::C_CSGameRules(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x104228A0
// Name: DT_CSGameRules::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_CSGameRules::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_CSGameRules::g_RecvTable);
  return atexit(func: DT_CSGameRules::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104228C0
// Name: DT_CSGameRules::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_CSGameRules::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_CSGameRules::ignored>();
  DT_CSGameRules::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10422920
// Name: DT_CSGameRulesProxy::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_CSGameRulesProxy::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_CSGameRulesProxy::g_RecvTable);
  return atexit(func: DT_CSGameRulesProxy::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10422940
// Name: DT_CSGameRulesProxy::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_CSGameRulesProxy::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_CSGameRulesProxy::ignored>();
  DT_CSGameRulesProxy::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104354E0
// Name: DT_CSGameRules::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_CSGameRules::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_CSGameRules::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x104354F0
// Name: DT_CSGameRulesProxy::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_CSGameRulesProxy::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_CSGameRulesProxy::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x104228D0
// Name: _dynamic_initializer_for____g_C_CSGameRulesProxyClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_CSGameRulesProxyClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_CSGameRulesProxyClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_CSGameRulesProxyClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104228F0
// Name: _dynamic_initializer_for__g_Ccs_gamerulesFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Ccs_gamerulesFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseEntity *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "cs_gamerules",
             a3: "C_CSGameRulesProxy",
             a4: 2432,
             a5: CC_CSGameRulesProxyFactory);
  __g_C_CSGameRulesProxyClientClass.m_pMapClassname = "cs_gamerules";
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1014C390
// Name: public: virtual int CCSGameRules::DefaultFOV(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSGameRules::DefaultFOV(CGameRules *this)
{
  return 90;
}

//------------------------------------------------------------------------------
// Address: 0x1026D280
// Name: public: virtual class ServerClass __near * CCSGameRulesProxy::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CCSGameRulesProxy::GetServerClass(CCSGameRulesProxy *this)
{
  return &g_CCSGameRulesProxy_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1026D290
// Name: void __near * SendProxy_CSGameRules(class SendProp const __near *,void const __near *,void const __near *,class CSendProxyRecipients __near *,int)
// Source: json
//------------------------------------------------------------------------------
CGameRules *__cdecl SendProxy_CSGameRules()
{
  return g_pGameRules;
}

//------------------------------------------------------------------------------
// Address: 0x1026D2A0
// Name: public: virtual bool CCSGameRules::ClientCommand(class CBaseEntity __near *,class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSGameRules::ClientCommand(CCSGameRules *this, CBaseEntity *pEdict, const CCommand *args)
{
  int *v3; // ebx
  const char *v4; // eax
  const char *v5; // eax
  char *m_pszString; // eax
  char *v7; // eax
  char *v8; // eax
  char *m_pArgSBuffer; // eax
  char szNextMap[32]; // [esp+Ch] [ebp-24h] BYREF
  CTeamplayRules *v12; // [esp+2Ch] [ebp-4h]

  v12 = this;
  if ( pEdict != nullptr && pEdict->IsPlayer(this: pEdict) )
    v3 = (int *)__RTDynamicCast(
                  inptr: pEdict,
                  VfDelta: 0,
                  SrcType: &CBaseEntity `RTTI Type Descriptor',
                  TargetType: &CCSPlayer `RTTI Type Descriptor',
                  isReference: 0);
  else
    v3 = nullptr;
  v4 = locale;
  if ( args->m_nArgc > 0 )
    v4 = args->m_ppArgv[0];
  if ( v4 == "changeteam" || _V_stricmp(s1: v4, s2: "changeteam") == 0 )
    return true;
  v5 = locale;
  if ( args->m_nArgc > 0 )
    v5 = args->m_ppArgv[0];
  if ( v5 == "nextmap" || _V_stricmp(s1: v5, s2: "nextmap") == 0 )
  {
    if ( gpGlobals->curtime <= (float)v3[1233] )
      return true;
    if ( (nextlevel.m_nFlags & 0x1000) != 0 )
      goto LABEL_18;
    m_pszString = nextlevel.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr || *m_pszString == 0 )
      goto LABEL_27;
    if ( (nextlevel.m_nFlags & 0x1000) != 0 )
    {
LABEL_18:
      v7 = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      v7 = nextlevel.m_pParent->m_Value.m_pszString;
      if ( v7 == nullptr )
        v7 = (char *)locale;
    }
    if ( engine->IsMapValid(this: engine, a2: v7) != 0 )
    {
      if ( (nextlevel.m_nFlags & 0x1000) != 0 )
      {
        V_strncpy(pDest: szNextMap, pSrc: "FCVAR_NEVER_AS_STRING", maxLen: 32);
      }
      else
      {
        v8 = nextlevel.m_pParent->m_Value.m_pszString;
        if ( v8 == nullptr )
          v8 = (char *)locale;
        V_strncpy(pDest: szNextMap, pSrc: v8, maxLen: 32);
      }
      goto LABEL_28;
    }
LABEL_27:
    v12->GetNextLevelName(this: v12, a2: szNextMap, a3: 32, a4: false);
LABEL_28:
    ClientPrint(
      player: (CBasePlayer *)v3,
      msg_dest: 3,
      msg_name: "#game_nextmap",
      param1: szNextMap,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
    v3[1233] = (int)(float)(gpGlobals->curtime + 1.0);
    return true;
  }
  if ( (*(unsigned __int8 (__thiscall **)(int *, const CCommand *))(*v3 + 1588))(a1: v3, a2: args) != 0
    || CTeamplayRules::ClientCommand(this: v12, pEdict, args) )
  {
    return true;
  }
  m_pArgSBuffer = args->m_pArgSBuffer;
  if ( args->m_nArgc == 0 )
    m_pArgSBuffer = (char *)locale;
  if ( TheBots->ServerCommand(this: TheBots, a2: m_pArgSBuffer) )
    return true;
  return TheBots->ClientCommand(this: TheBots, a2: (CBasePlayer *)v3, a3: args);
}

//------------------------------------------------------------------------------
// Address: 0x1026D4A0
// Name: public: int CCSGameRules::TeamCashAwardValue(enum TeamCashAwardReason)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSGameRules::TeamCashAwardValue(CCSGameRules *this, TeamCashAwardReason reason)
{
  int result; // eax

  switch ( reason )
  {
    case TEAM_CASH_AWARD_TERRORIST_WIN_BOMB:
      result = 2500;
      break;
    case TEAM_CASH_AWARD_ELIMINATION_HOSTAGE_MAP:
      result = 2000;
      break;
    case TEAM_CASH_AWARD_ELIMINATION_BOMB_MAP:
    case TEAM_CASH_AWARD_WIN_BY_TIME_RUNNING_OUT:
    case TEAM_CASH_AWARD_WIN_BY_DEFUSING_BOMB:
      result = 2250;
      break;
    case TEAM_CASH_AWARD_WIN_BY_HOSTAGE_RESCUE:
      result = 1500;
      break;
    case TEAM_CASH_AWARD_LOSER_BONUS:
    case TEAM_CASH_AWARD_LOSER_BONUS_CONSECUTIVE_ROUNDS:
      result = 500;
      break;
    case TEAM_CASH_AWARD_RESCUED_HOSTAGE:
      result = 250;
      break;
    case TEAM_CASH_AWARD_HOSTAGE_ALIVE:
      result = 150;
      break;
    case TEAM_CASH_AWARD_PLANTED_BOMB:
      result = 800;
      break;
    case TEAM_CASH_AWARD_CT_VIP_ESCAPED:
      result = 3500;
      break;
    case TEAM_CASH_AWARD_TERRORIST_VIP_KILLED:
      result = 3250;
      break;
    case TEAM_CASH_AWARD_HOSTAGE_INTERACTION:
      result = 100;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1026D560
// Name: public: virtual char const __near * CCSGameRules::AIClassText(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSGameRules::AIClassText(CCSGameRules *this, int classType)
{
  if ( classType == 0 )
    return "CLASS_NONE";
  if ( classType == 1 )
    return "CLASS_PLAYER";
  return "MISSING CLASS in ClassifyText()";
}

//------------------------------------------------------------------------------
// Address: 0x1026D590
// Name: public: virtual void CCSGameRules::SetAllowWeaponSwitch(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::SetAllowWeaponSwitch(CCSGameRules *this, bool allow)
{
  this->m_bAllowWeaponSwitch = allow;
}

//------------------------------------------------------------------------------
// Address: 0x1026D5A0
// Name: public: virtual bool CCSGameRules::GetAllowWeaponSwitch(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSGameRules::GetAllowWeaponSwitch(CCSGameRules *this)
{
  return this->m_bAllowWeaponSwitch;
}

//------------------------------------------------------------------------------
// Address: 0x1026D5B0
// Name: public: virtual char const __near * CCSGameRules::SetDefaultPlayerTeam(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSGameRules::SetDefaultPlayerTeam(CCSGameRules *this, CBasePlayer *pPlayer)
{
  return CTeamplayRules::SetDefaultPlayerTeam(this, pPlayer);
}

//------------------------------------------------------------------------------
// Address: 0x1026D5C0
// Name: public: void CCSGameRules::SetRestartVotingEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::SetRestartVotingEnabled(CCSGameRules *this, bool enabled)
{
  IGameEvent *v3; // esi

  this->m_bRestartVotingAllowed = enabled;
  v3 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "enable_restart_voting", a3: 0, a4: 0);
  if ( v3 != nullptr )
  {
    v3->SetBool(this: v3, a2: "enable", a3: this->m_bRestartVotingAllowed);
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v3, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026D620
// Name: public: virtual void CCSGameRules::EndGameFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::EndGameFrame(CCSGameRules *this)
{
  TheBots->StartFrame(this: TheBots);
  CGameRules::EndGameFrame(this);
}

//------------------------------------------------------------------------------
// Address: 0x1026D640
// Name: protected: static void CCSGameRules::SplitScoreAmongPlayersInZone(int,int,class CCSPlayer __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CCSGameRules::SplitScoreAmongPlayersInZone(
        int iPoints,
        int iTeam,
        CCSPlayer *pExcludePlayer,
        unsigned int iPlace)
{
  int v4; // edi
  CCSPlayer *v5; // eax
  CCSPlayer *v6; // esi
  CNavArea *m_lastNavArea; // esi
  CGlobalVars *v8; // ecx
  int v9; // edi
  CCSPlayer *v10; // esi
  int v11; // ebx
  float fWeights[64]; // [esp+4h] [ebp-110h] BYREF
  float v13; // [esp+104h] [ebp-10h]
  float v14; // [esp+108h] [ebp-Ch]
  int v15; // [esp+10Ch] [ebp-8h]
  float fWeightSum; // [esp+110h] [ebp-4h]

  memset(dst: (int)fWeights, value: nullptr, count: sizeof(fWeights));
  v4 = 1;
  fWeightSum = 0.0;
  if ( gpGlobals->maxClients >= 1 )
  {
    do
    {
      v5 = (CCSPlayer *)UTIL_PlayerByIndex(playerIndex: v4);
      v6 = v5;
      if ( v5 != nullptr && v5 != pExcludePlayer && CBaseEntity::GetTeamNumber(this: v5) == iTeam )
      {
        m_lastNavArea = v6->m_lastNavArea;
        if ( m_lastNavArea != nullptr && m_lastNavArea->m_place == iPlace )
        {
          fWeightSum = fWeightSum + 1.0;
          fWeights[v4] = 1.0;
        }
      }
      v8 = gpGlobals;
      ++v4;
    }
    while ( v4 <= gpGlobals->maxClients );
    if ( fWeightSum != 0.0 )
    {
      v9 = 1;
      if ( gpGlobals->maxClients >= 1 )
      {
        do
        {
          v14 = fWeights[v9];
          if ( v14 > 0.0 )
          {
            v10 = (CCSPlayer *)UTIL_PlayerByIndex(playerIndex: v9);
            v13 = (float)((float)iPoints * v14) / fWeightSum;
            v15 = (int)v13;
            v11 = v15;
            CCSPlayer::AddScore(this: v10, iPoints: v15);
            CCSPlayer::AddRoundProximityScore(this: v10, iPoints: v11);
            v8 = gpGlobals;
          }
          ++v9;
        }
        while ( v9 <= v8->maxClients );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026D770
// Name: public: void CCSGameRules::ScorePlayerKill(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::ScorePlayerKill(CCSGameRules *this, CCSPlayer *pPlayer)
{
  int m_nValue; // eax

  if ( pPlayer != nullptr )
  {
    if ( contributionscore_kill.m_pParent != nullptr )
      m_nValue = contributionscore_kill.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    pPlayer->m_iContributionScore += m_nValue;
    CCSPlayer::AddScore(this: pPlayer, iPoints: (int)score_kill_enemy_bonus.m_pParent->m_Value.m_fValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026D7C0
// Name: public: void CCSGameRules::ScorePlayerAssist(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::ScorePlayerAssist(CCSGameRules *this, CCSPlayer *pPlayer)
{
  if ( pPlayer != nullptr )
  {
    if ( contributionscore_assist.m_pParent != nullptr )
      pPlayer->m_iContributionScore += contributionscore_assist.m_pParent->m_Value.m_nValue;
    else
      pPlayer->m_iContributionScore = pPlayer->m_iContributionScore;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026D7F0
// Name: public: void CCSGameRules::ScorePlayerObjectiveKill(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::ScorePlayerObjectiveKill(CCSGameRules *this, CCSPlayer *pPlayer)
{
  if ( pPlayer != nullptr )
  {
    if ( contributionscore_objective_kill.m_pParent != nullptr )
      pPlayer->m_iContributionScore += contributionscore_objective_kill.m_pParent->m_Value.m_nValue;
    else
      pPlayer->m_iContributionScore = pPlayer->m_iContributionScore;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026D820
// Name: public: void CCSGameRules::ScorePlayerTeamKill(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::ScorePlayerTeamKill(CCSGameRules *this, CCSPlayer *pPlayer)
{
  if ( pPlayer != nullptr )
  {
    if ( contributionscore_team_kill.m_pParent != nullptr )
      pPlayer->m_iContributionScore += contributionscore_team_kill.m_pParent->m_Value.m_nValue;
    else
      pPlayer->m_iContributionScore = pPlayer->m_iContributionScore;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026D850
// Name: public: void CCSGameRules::ScoreHostageKilled(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::ScoreHostageKilled(CCSGameRules *this, CCSPlayer *pPlayer)
{
  if ( pPlayer != nullptr )
  {
    if ( contributionscore_hostage_kill.m_pParent != nullptr )
      pPlayer->m_iContributionScore += contributionscore_hostage_kill.m_pParent->m_Value.m_nValue;
    else
      pPlayer->m_iContributionScore = pPlayer->m_iContributionScore;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026D880
// Name: public: void CCSGameRules::ScoreHostageDamage(class CCSPlayer __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::ScoreHostageDamage(CCSGameRules *this, CCSPlayer *pPlayer, float fDamage)
{
  int m_nValue; // eax

  if ( pPlayer != nullptr )
  {
    if ( score_hostage_damage_penalty.m_pParent != nullptr )
      m_nValue = score_hostage_damage_penalty.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    CCSPlayer::AddScore(this: pPlayer, iPoints: -(int)(float)((float)m_nValue * fDamage));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026D8C0
// Name: public: void CCSGameRules::ScoreFriendlyFire(class CCSPlayer __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::ScoreFriendlyFire(CCSGameRules *this, CCSPlayer *pPlayer, float fDamage)
{
  if ( pPlayer != nullptr )
    CCSPlayer::AddScore(this: pPlayer, iPoints: -(int)(float)(score_ff_damage.m_pParent->m_Value.m_fValue * fDamage));
}

//------------------------------------------------------------------------------
// Address: 0x1026D900
// Name: public: void CCSGameRules::ScoreBlindEnemy(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::ScoreBlindEnemy(CCSGameRules *this, CCSPlayer *pPlayer)
{
  if ( pPlayer != nullptr )
  {
    if ( score_blind_enemy_bonus.m_pParent != nullptr )
      CCSPlayer::AddScore(this: pPlayer, iPoints: score_blind_enemy_bonus.m_pParent->m_Value.m_nValue);
    else
      CCSPlayer::AddScore(this: pPlayer, iPoints: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026D930
// Name: public: void CCSGameRules::ScoreBlindFriendly(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::ScoreBlindFriendly(CCSGameRules *this, CCSPlayer *pPlayer)
{
  if ( pPlayer != nullptr )
  {
    if ( score_blind_friendly_penalty.m_pParent != nullptr )
      CCSPlayer::AddScore(this: pPlayer, iPoints: -score_blind_friendly_penalty.m_pParent->m_Value.m_nValue);
    else
      CCSPlayer::AddScore(this: pPlayer, iPoints: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026D960
// Name: void TestMatchWinpanel(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TestMatchWinpanel()
{
  IGameEvent *v0; // esi
  IGameEvent *v1; // esi

  v0 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "round_end", a3: 0, a4: 0);
  v0->SetInt(this: v0, a2: "winner", a3: 2);
  gameeventmanager->FireEvent(this: gameeventmanager, a2: v0, a3: false);
  v1 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "cs_win_panel_match", a3: 0, a4: 0);
  if ( v1 != nullptr )
  {
    v1->SetInt(this: v1, a2: "t_score", a3: 4);
    v1->SetInt(this: v1, a2: "ct_score", a3: 1);
    ((void (__thiscall *)(IGameEvent *, const char *, int))v1->SetFloat)(a1: v1, a2: "t_kd", a3: 1072064102);
    ((void (__thiscall *)(IGameEvent *, const char *, int))v1->SetFloat)(a1: v1, a2: "ct_kd", a3: 1053609165);
    v1->SetInt(this: v1, a2: "t_objectives_done", a3: 5);
    v1->SetInt(this: v1, a2: "ct_objectives_done", a3: 2);
    v1->SetInt(this: v1, a2: "t_money_earned", a3: 30000);
    v1->SetInt(this: v1, a2: "ct_money_earned", a3: 19999);
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v1, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026DA70
// Name: void TestFreezePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TestFreezePanel()
{
  IGameEvent *v0; // eax
  IGameEvent *v1; // eax
  IGameEvent *v2; // esi

  v0 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "freezecam_started", a3: 0, a4: 0);
  if ( v0 != nullptr )
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v0, a3: false);
  v1 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "show_freezepanel", a3: 0, a4: 0);
  v2 = v1;
  if ( v1 != nullptr )
  {
    v1->SetInt(this: v1, a2: "killer", a3: 1);
    v2->SetInt(this: v2, a2: "victim", a3: 1);
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v2, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026DAF0
// Name: public: void CCSGameRules::MarkLivingPlayersOnTeamAsNotReceivingMoneyNextRound(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::MarkLivingPlayersOnTeamAsNotReceivingMoneyNextRound(CCSGameRules *this, int team)
{
  int i; // edi
  CBasePlayer *v3; // eax
  CCSPlayer *v4; // esi

  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: i);
    v4 = (CCSPlayer *)v3;
    if ( v3 != nullptr && CBaseEntity::GetTeamNumber(this: v3) == team && v4->IsAlive(this: v4) )
      CCSPlayer::MarkAsNotReceivingMoneyNextRound(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026DB50
// Name: public: void CCSGameRules::ShowSpawnPoints(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CCSGameRules::ShowSpawnPoints(CCSGameRules *this@<ecx>, int a2@<ebp>)
{
  CBaseEntity *i; // esi
  CBaseEntity *j; // esi
  Vector *p_m_vHullMin; // [esp-8h] [ebp-24h]
  Vector *v6; // [esp-8h] [ebp-24h]
  Vector *v7; // [esp-8h] [ebp-24h]
  Vector *v8; // [esp-8h] [ebp-24h]
  Vector *p_m_vHullMax; // [esp-4h] [ebp-20h]
  Vector *v10; // [esp-4h] [ebp-20h]
  Vector *v11; // [esp-4h] [ebp-20h]
  Vector *v12; // [esp-4h] [ebp-20h]

  for ( i = CGlobalEntityList::FindEntityByClassname(
              this: &gEntList,
              pStartEntity: nullptr,
              szName: "info_player_terrorist");
        i != nullptr;
        i = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: i, szName: "info_player_terrorist") )
  {
    if ( this->IsSpawnPointValid(this, a2: i, a3: nullptr) )
    {
      if ( (i->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: i, a2);
      p_m_vHullMax = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMax;
      p_m_vHullMin = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMin;
      NDebugOverlay::Box(
        origin: &i->m_vecAbsOrigin,
        mins: p_m_vHullMin,
        maxs: p_m_vHullMax,
        r: 0,
        g: 255,
        b: 0,
        a: 200,
        flDuration: 600.0);
    }
    else
    {
      if ( (i->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: i, a2);
      v10 = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMax;
      v6 = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMin;
      NDebugOverlay::Box(origin: &i->m_vecAbsOrigin, mins: v6, maxs: v10, r: 255, g: 0, b: 0, a: 200, flDuration: 600.0);
    }
  }
  for ( j = CGlobalEntityList::FindEntityByClassname(
              this: &gEntList,
              pStartEntity: i,
              szName: "info_player_counterterrorist");
        j != nullptr;
        j = CGlobalEntityList::FindEntityByClassname(
              this: &gEntList,
              pStartEntity: j,
              szName: "info_player_counterterrorist") )
  {
    if ( this->IsSpawnPointValid(this, a2: j, a3: nullptr) )
    {
      if ( (j->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: j, a2);
      v11 = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMax;
      v7 = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMin;
      NDebugOverlay::Box(origin: &j->m_vecAbsOrigin, mins: v7, maxs: v11, r: 0, g: 255, b: 0, a: 200, flDuration: 600.0);
    }
    else
    {
      if ( (j->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: j, a2);
      v12 = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMax;
      v8 = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMin;
      NDebugOverlay::Box(origin: &j->m_vecAbsOrigin, mins: v8, maxs: v12, r: 255, g: 0, b: 0, a: 200, flDuration: 600.0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026DD70
// Name: public: void CCSGameRules::CheckRestartRound(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CCSGameRules::CheckRestartRound(CCSGameRules *this@<ecx>, unsigned int a2@<esi>)
{
  int m_nValue; // esi
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  CGameTrace *v8; // [esp+0h] [ebp-44h]
  char strRestartDelay[64]; // [esp+4h] [ebp-40h] BYREF

  if ( mp_restartgame.m_pParent == nullptr )
    return;
  m_nValue = mp_restartgame.m_pParent->m_Value.m_nValue;
  if ( m_nValue <= 0 )
    return;
  if ( m_nValue > 60 )
  {
    m_nValue = 60;
LABEL_6:
    v4 = "seconds";
    goto LABEL_7;
  }
  v4 = "second";
  if ( m_nValue != 1 )
    goto LABEL_6;
LABEL_7:
  UTIL_LogPrintf(fmt: "World triggered \"Restart_Round_(%i_%s)\"\n", m_nValue, v4);
  UTIL_LogPrintf(fmt: "Team \"CT\" scored \"%i\" with \"%i\" players\n", this->m_iNumCTWins, this->m_iNumCT);
  UTIL_LogPrintf(
    fmt: "Team \"TERRORIST\" scored \"%i\" with \"%i\" players\n",
    this->m_iNumTerroristWins,
    this->m_iNumTerrorist);
  V_snprintf(pDest: strRestartDelay, maxLen: 64, pFormat: "%d", m_nValue);
  v5 = "SECOND";
  if ( m_nValue != 1 )
    v5 = "SECONDS";
  UTIL_ClientPrintAll(
    msg_dest: 4,
    msg_name: "#SFUI_Notice_Game_will_restart_in",
    param1: strRestartDelay,
    param2: v5,
    param3: nullptr,
    param4: nullptr);
  v6 = "SECOND";
  if ( m_nValue != 1 )
    v6 = "SECONDS";
  UTIL_ClientPrintAll(
    msg_dest: 2,
    msg_name: "#SFUI_Notice_Game_will_restart_in",
    param1: strRestartDelay,
    param2: v6,
    param3: nullptr,
    param4: nullptr);
  this->m_flRestartRoundTime = (float)m_nValue + gpGlobals->curtime;
  this->m_bCompleteReset = true;
  CCollisionProperty::TestCollision(this: (ConVar *)&mp_restartgame.IConVar, value: 0, fContentsMask: a2, tr: v8);
}

//------------------------------------------------------------------------------
// Address: 0x1026DE80
// Name: public: int CCSGameRules::GetHumanTeam(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSGameRules::GetHumanTeam(CCSGameRules *this)
{
  char *m_pszString; // eax
  char *v3; // eax

  if ( (mp_humanteam.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = mp_humanteam.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)locale;
  }
  if ( m_pszString == "CT" || _V_stricmp(s1: "CT", s2: m_pszString) == 0 )
    return 3;
  if ( (mp_humanteam.m_nFlags & 0x1000) != 0 )
  {
    v3 = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    v3 = mp_humanteam.m_pParent->m_Value.m_pszString;
    if ( v3 == nullptr )
      v3 = (char *)locale;
  }
  if ( v3 != "T" && _V_stricmp(s1: "T", s2: v3) != 0 )
    return 0;
  else
    return 2;
}

//------------------------------------------------------------------------------
// Address: 0x1026DF10
// Name: public: bool CCSGameRules::TeamStacked(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSGameRules::TeamStacked(CCSGameRules *this, int newTeam_id, unsigned int curTeam_id)
{
  int m_nValue; // eax

  if ( newTeam_id == curTeam_id )
    return false;
  if ( mp_limitteams.m_pParent == nullptr )
    return false;
  m_nValue = mp_limitteams.m_pParent->m_Value.m_nValue;
  if ( m_nValue == 0 )
    return false;
  if ( newTeam_id != 2 )
  {
    if ( newTeam_id == 3 )
    {
      if ( curTeam_id < 2 )
        return this->m_iNumCT + 1 > m_nValue + this->m_iNumTerrorist;
      else
        return this->m_iNumCT + 1 > this->m_iNumTerrorist + m_nValue - 1;
    }
    return false;
  }
  if ( curTeam_id < 2 )
    return this->m_iNumTerrorist + 1 > m_nValue + this->m_iNumCT;
  else
    return this->m_iNumTerrorist + 1 > this->m_iNumCT + m_nValue - 1;
}

//------------------------------------------------------------------------------
// Address: 0x1026DFC0
// Name: public: void CCSGameRules::UpdateTeamScores(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::UpdateTeamScores(CCSGameRules *this)
{
  CTeam *GlobalTeam; // esi
  CTeam *v3; // edi

  GlobalTeam = GetGlobalTeam(iIndex: 2);
  v3 = GetGlobalTeam(iIndex: 3);
  if ( GlobalTeam != nullptr )
    GlobalTeam->SetScore(this: GlobalTeam, a2: this->m_iNumTerroristWins);
  if ( v3 != nullptr )
    v3->SetScore(this: v3, a2: this->m_iNumCTWins);
}

//------------------------------------------------------------------------------
// Address: 0x1026E010
// Name: public: virtual bool CCSGameRules::IsSpawnPointValid(class CBaseEntity __near *,class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSGameRules::IsSpawnPointValid(CCSGameRules *this, CBaseEntity *pSpot, CBasePlayer *pPlayer)
{
  bool result; // al
  const CViewVectors *v5; // eax
  __int64 v6; // xmm0_8
  CCSGameRules_vtbl *v7; // edx
  const CViewVectors *(__thiscall *GetViewVectors)(struct CCSGameRules *); // eax
  int v9; // eax
  float v10; // ecx
  unsigned int v11; // edx
  int m_iEFlags; // eax
  Vector vTestMins; // [esp+Ch] [ebp-30h] BYREF
  Vector vTestMaxs; // [esp+18h] [ebp-24h] BYREF
  Vector maxs; // [esp+24h] [ebp-18h]
  Vector mins; // [esp+30h] [ebp-Ch]
  int savedregs; // [esp+3Ch] [ebp+0h] BYREF

  result = pSpot->IsTriggered(this: pSpot, a2: pPlayer);
  if ( result )
  {
    v5 = this->GetViewVectors(this);
    v6 = *(_QWORD *)&v5->m_vHullMin.x;
    v7 = this->__vftable;
    mins.z = v5->m_vHullMin.z;
    GetViewVectors = v7->GetViewVectors;
    *(_QWORD *)&mins.x = v6;
    v9 = (int)GetViewVectors(this);
    v10 = *(float *)(v9 + 32);
    v11 = (unsigned int)pSpot->m_iEFlags >> 11;
    *(_QWORD *)&maxs.x = *(_QWORD *)(v9 + 24);
    maxs.z = v10;
    if ( (v11 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pSpot, a2: (int)&savedregs);
    m_iEFlags = pSpot->m_iEFlags;
    vTestMins.x = pSpot->m_vecAbsOrigin.x + mins.x;
    vTestMins.y = pSpot->m_vecAbsOrigin.y + mins.y;
    vTestMins.z = pSpot->m_vecAbsOrigin.z + mins.z;
    if ( (m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pSpot, a2: (int)&savedregs);
    vTestMaxs.x = pSpot->m_vecAbsOrigin.x + maxs.x;
    vTestMaxs.y = pSpot->m_vecAbsOrigin.y + maxs.y;
    vTestMaxs.z = pSpot->m_vecAbsOrigin.z + maxs.z;
    return UTIL_IsSpaceEmpty(pMainEnt: pPlayer, vMin: &vTestMins, vMax: &vTestMaxs);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1026E120
// Name: public: bool CCSGameRules::IsThereABomb(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSGameRules::IsThereABomb(CCSGameRules *this)
{
  return CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: nullptr, szName: "weapon_c4") != nullptr
      || CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: nullptr, szName: "planted_c4") != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1026E160
// Name: public: void CCSGameRules::HostageTouched(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::HostageTouched(CCSGameRules *this)
{
  float curtime; // xmm0_4

  curtime = gpGlobals->curtime;
  if ( curtime > this->m_flNextHostageAnnouncement && this->m_iRoundWinStatus == 0 )
    this->m_flNextHostageAnnouncement = curtime + 60.0;
}

//------------------------------------------------------------------------------
// Address: 0x1026E1A0
// Name: public: virtual void CCSGameRules::CreateStandardEntities(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::CreateStandardEntities(CCSGameRules *this)
{
  g_pPlayerResource = (CPlayerResource *)CBaseEntity::Create(
                                           szName: "cs_player_manager",
                                           vecOrigin: &vec3_origin,
                                           vecAngles: &vec3_angle,
                                           pOwner: nullptr);
  CBaseEntity::Create(szName: "cs_gamerules", vecOrigin: &vec3_origin, vecAngles: &vec3_angle, pOwner: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1026E1E0
// Name: bool DataHasChanged(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl DataHasChanged()
{
  int v0; // eax
  __int16 *v1; // eax

  v0 = 0;
  while ( g_iTerroristVictories[v0] == 0 && g_iCounterTVictories[v0] == 0 )
  {
    if ( ++v0 >= 18 )
    {
      v1 = g_iWeaponPurchases;
      while ( *v1 == 0 )
      {
        if ( (int)++v1 >= (int)g_iCounterTVictories )
          return 0;
      }
      return 1;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1026E220
// Name: public: virtual class CBaseCombatWeapon __near * CCSGameRules::GetNextBestWeapon(class CBaseCombatCharacter __near *,class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
const CWeaponCSBase *__thiscall CCSGameRules::GetNextBestWeapon(
        CCSGameRules *this,
        CBaseCombatCharacter *pPlayer,
        const CWeaponCSBase *pCurrentWeapon)
{
  CBaseCombatCharacter *v3; // ebx
  const CWeaponCSBase *v4; // edi
  CBaseCombatWeapon *Weapon; // eax
  const CWeaponCSBase *v6; // esi
  void *v7; // eax
  int v8; // ebx
  int v9; // ebx
  int v10; // ebx
  int i; // [esp+Ch] [ebp-4h]

  v3 = pPlayer;
  v4 = nullptr;
  for ( i = 0; i < 64; ++i )
  {
    Weapon = CBaseCombatCharacter::GetWeapon(this: v3, i);
    v6 = (const CWeaponCSBase *)Weapon;
    if ( Weapon != nullptr
      && Weapon->CanBeSelected(this: Weapon)
      && v6 != pCurrentWeapon
      && (v3 == nullptr
       || !v3->IsPlayer(this: v3)
       || (v7 = __RTDynamicCast(
                  inptr: v3,
                  VfDelta: 0,
                  SrcType: &CBaseEntity `RTTI Type Descriptor',
                  TargetType: &CCSPlayer `RTTI Type Descriptor',
                  isReference: 0)) == nullptr
       || (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)v7 + 1912))(a1: v7) == 0
       || CCSBotManager::IsWeaponUseable(this: (CCSBotManager *)TheBots, weapon: v6)) )
    {
      if ( v4 != nullptr )
      {
        v8 = v6->GetSlot(this: &v6->CBaseCombatWeapon);
        if ( v8 < v4->GetSlot(this: &v4->CBaseCombatWeapon)
          || (v9 = v6->GetSlot(this: &v6->CBaseCombatWeapon)) == v4->GetSlot(this: &v4->CBaseCombatWeapon)
          && (v10 = v6->GetPosition(this: &v6->CBaseCombatWeapon)) < v4->GetPosition(this: &v4->CBaseCombatWeapon) )
        {
          v4 = v6;
        }
        v3 = pPlayer;
      }
      else
      {
        v4 = v6;
      }
    }
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1026E340
// Name: public: virtual class CViewVectors const __near * CCSGameRules::GetViewVectors(void)const
// Source: json
//------------------------------------------------------------------------------
const CViewVectors *__thiscall CCSGameRules::GetViewVectors(CCSGameRules *this)
{
  return &g_CSViewVectors;
}

//------------------------------------------------------------------------------
// Address: 0x1026E350
// Name: class CAmmoDef __near * GetAmmoDef(void)
// Source: json
//------------------------------------------------------------------------------
CCSAmmoDef *__cdecl GetAmmoDef()
{
  if ( !bInitted )
  {
    bInitted = true;
    CAmmoDef::AddAmmoType(
      this: &ammoDef,
      name: "BULLET_PLAYER_50AE",
      damageType: 2,
      tracerType: 1,
      plr_cvar: nullptr,
      npc_cvar: nullptr,
      carry_cvar: "ammo_50AE_max",
      physicsForceImpulse: 2400.0,
      nFlags: 0,
      minSplashSize: 10,
      maxSplashSize: 14);
    CAmmoDef::AddAmmoType(
      this: &ammoDef,
      name: "BULLET_PLAYER_762MM",
      damageType: 2,
      tracerType: 1,
      plr_cvar: nullptr,
      npc_cvar: nullptr,
      carry_cvar: "ammo_762mm_max",
      physicsForceImpulse: 2400.0,
      nFlags: 0,
      minSplashSize: 10,
      maxSplashSize: 14);
    CAmmoDef::AddAmmoType(
      this: &ammoDef,
      name: "BULLET_PLAYER_556MM",
      damageType: 2,
      tracerType: 1,
      plr_cvar: nullptr,
      npc_cvar: nullptr,
      carry_cvar: "ammo_556mm_max",
      physicsForceImpulse: 2400.0,
      nFlags: 0,
      minSplashSize: 10,
      maxSplashSize: 14);
    CAmmoDef::AddAmmoType(
      this: &ammoDef,
      name: "BULLET_PLAYER_556MM_BOX",
      damageType: 2,
      tracerType: 1,
      plr_cvar: nullptr,
      npc_cvar: nullptr,
      carry_cvar: "ammo_556mm_box_max",
      physicsForceImpulse: 2400.0,
      nFlags: 0,
      minSplashSize: 10,
      maxSplashSize: 14);
    CAmmoDef::AddAmmoType(
      this: &ammoDef,
      name: "BULLET_PLAYER_338MAG",
      damageType: 2,
      tracerType: 1,
      plr_cvar: nullptr,
      npc_cvar: nullptr,
      carry_cvar: "ammo_338mag_max",
      physicsForceImpulse: 2800.0,
      nFlags: 0,
      minSplashSize: 12,
      maxSplashSize: 16);
    CAmmoDef::AddAmmoType(
      this: &ammoDef,
      name: "BULLET_PLAYER_9MM",
      damageType: 2,
      tracerType: 1,
      plr_cvar: nullptr,
      npc_cvar: nullptr,
      carry_cvar: "ammo_9mm_max",
      physicsForceImpulse: 2000.0,
      nFlags: 0,
      minSplashSize: 5,
      maxSplashSize: 10);
    CAmmoDef::AddAmmoType(
      this: &ammoDef,
      name: "BULLET_PLAYER_BUCKSHOT",
      damageType: 2,
      tracerType: 1,
      plr_cvar: nullptr,
      npc_cvar: nullptr,
      carry_cvar: "ammo_buckshot_max",
      physicsForceImpulse: 600.0,
      nFlags: 0,
      minSplashSize: 3,
      maxSplashSize: 6);
    CAmmoDef::AddAmmoType(
      this: &ammoDef,
      name: "BULLET_PLAYER_45ACP",
      damageType: 2,
      tracerType: 1,
      plr_cvar: nullptr,
      npc_cvar: nullptr,
      carry_cvar: "ammo_45acp_max",
      physicsForceImpulse: 2100.0,
      nFlags: 0,
      minSplashSize: 6,
      maxSplashSize: 10);
    CAmmoDef::AddAmmoType(
      this: &ammoDef,
      name: "BULLET_PLAYER_357SIG",
      damageType: 2,
      tracerType: 1,
      plr_cvar: nullptr,
      npc_cvar: nullptr,
      carry_cvar: "ammo_357sig_max",
      physicsForceImpulse: 2000.0,
      nFlags: 0,
      minSplashSize: 4,
      maxSplashSize: 8);
    CAmmoDef::AddAmmoType(
      this: &ammoDef,
      name: "BULLET_PLAYER_57MM",
      damageType: 2,
      tracerType: 1,
      plr_cvar: nullptr,
      npc_cvar: nullptr,
      carry_cvar: "ammo_57mm_max",
      physicsForceImpulse: 2000.0,
      nFlags: 0,
      minSplashSize: 4,
      maxSplashSize: 8);
    CAmmoDef::AddAmmoType(
      this: &ammoDef,
      name: "AMMO_TYPE_HEGRENADE",
      damageType: 64,
      tracerType: 1,
      plr_cvar: nullptr,
      npc_cvar: nullptr,
      carry_cvar: "ammo_hegrenade_max",
      physicsForceImpulse: 1.0,
      nFlags: 0,
      minSplashSize: 4,
      maxSplashSize: 8);
    CAmmoDef::AddAmmoType(
      this: &ammoDef,
      name: "AMMO_TYPE_FLASHBANG",
      damageType: 0,
      tracerType: 1,
      plr_cvar: nullptr,
      npc_cvar: nullptr,
      carry_cvar: "ammo_flashbang_max",
      physicsForceImpulse: 1.0,
      nFlags: 0,
      minSplashSize: 4,
      maxSplashSize: 8);
    CAmmoDef::AddAmmoType(
      this: &ammoDef,
      name: "AMMO_TYPE_SMOKEGRENADE",
      damageType: 0,
      tracerType: 1,
      plr_cvar: nullptr,
      npc_cvar: nullptr,
      carry_cvar: "ammo_smokegrenade_max",
      physicsForceImpulse: 1.0,
      nFlags: 0,
      minSplashSize: 4,
      maxSplashSize: 8);
    CAmmoDef::AddAmmoType(
      this: &ammoDef,
      name: "AMMO_TYPE_MOLOTOV",
      damageType: 8,
      tracerType: 0,
      plr_cvar: nullptr,
      npc_cvar: nullptr,
      carry_cvar: "ammo_molotov_max",
      physicsForceImpulse: 1.0,
      nFlags: 0,
      minSplashSize: 4,
      maxSplashSize: 8);
    CAmmoDef::AddAmmoType(
      this: &ammoDef,
      name: "AMMO_TYPE_DECOY",
      damageType: 0,
      tracerType: 0,
      plr_cvar: nullptr,
      npc_cvar: nullptr,
      carry_cvar: "ammo_decoy_max",
      physicsForceImpulse: 1.0,
      nFlags: 0,
      minSplashSize: 4,
      maxSplashSize: 8);
    CAmmoDef::AddAmmoType(
      this: &ammoDef,
      name: "AMMO_TYPE_TASERCHARGE",
      damageType: 256,
      tracerType: 3,
      plr_dmg: 0,
      npc_dmg: 0,
      carry: 0,
      physicsForceImpulse: 1.0,
      nFlags: 0,
      minSplashSize: 4,
      maxSplashSize: 8);
    CCSAmmoDef::AddAmmoCost(this: &ammoDef, name: "BULLET_PLAYER_50AE", cost: 0, buySize: 7);
    CCSAmmoDef::AddAmmoCost(this: &ammoDef, name: "BULLET_PLAYER_762MM", cost: 0, buySize: 30);
    CCSAmmoDef::AddAmmoCost(this: &ammoDef, name: "BULLET_PLAYER_556MM", cost: 0, buySize: 30);
    CCSAmmoDef::AddAmmoCost(this: &ammoDef, name: "BULLET_PLAYER_556MM_BOX", cost: 0, buySize: 30);
    CCSAmmoDef::AddAmmoCost(this: &ammoDef, name: "BULLET_PLAYER_338MAG", cost: 0, buySize: 10);
    CCSAmmoDef::AddAmmoCost(this: &ammoDef, name: "BULLET_PLAYER_9MM", cost: 0, buySize: 30);
    CCSAmmoDef::AddAmmoCost(this: &ammoDef, name: "BULLET_PLAYER_BUCKSHOT", cost: 0, buySize: 8);
    CCSAmmoDef::AddAmmoCost(this: &ammoDef, name: "BULLET_PLAYER_45ACP", cost: 0, buySize: 25);
    CCSAmmoDef::AddAmmoCost(this: &ammoDef, name: "BULLET_PLAYER_357SIG", cost: 0, buySize: 13);
    CCSAmmoDef::AddAmmoCost(this: &ammoDef, name: "BULLET_PLAYER_57MM", cost: 0, buySize: 50);
  }
  return &ammoDef;
}

//------------------------------------------------------------------------------
// Address: 0x1026E730
// Name: public: bool CCSGameRules::IsRoundOver(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCSGameRules::IsRoundOver(CCSGameRules *this)
{
  return this->m_iRoundWinStatus != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1026E740
// Name: map_showspawnpoints
// Source: json
//------------------------------------------------------------------------------
void __usercall map_showspawnpoints(int a1@<ebp>)
{
  CCSGameRules::ShowSpawnPoints(this: (CCSGameRules *)g_pGameRules, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x1026E750
// Name: void DrawSphere(class Vector const __near &,float,int,int,int,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawSphere(const Vector *pos, float radius, int r, int g, int b, float lifetime)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v9; // xmm0_4
  double v10; // st7
  float x; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  double v17; // st7
  Vector target; // [esp+10h] [ebp-24h] BYREF
  Vector lastEdge; // [esp+1Ch] [ebp-18h] BYREF
  Vector edge; // [esp+28h] [ebp-Ch] BYREF
  float angle; // [esp+3Ch] [ebp+8h]
  float anglea; // [esp+3Ch] [ebp+8h]
  float angleb; // [esp+3Ch] [ebp+8h]

  target.x = pos->x;
  target.y = pos->y;
  target.z = pos->z + 50.0;
  NDebugOverlay::Line(origin: pos, &target, r, g, b, noDepthTest: 1, duration: lifetime);
  y = pos->y;
  z = pos->z;
  lastEdge.x = pos->x + radius;
  v9 = 0.0;
  lastEdge.y = y;
  lastEdge.z = z;
  angle = 0.0;
  do
  {
    v10 = BotCOS(angle: v9);
    edge.y = pos->y;
    edge.x = v10 * radius + pos->x;
    edge.z = BotSIN(angle) * radius + pos->z;
    NDebugOverlay::Line(origin: &edge, target: &lastEdge, r, g, b, noDepthTest: 1, duration: lifetime);
    lastEdge.x = edge.x;
    lastEdge.y = edge.y;
    lastEdge.z = edge.z;
    v9 = angle + 22.5;
    angle = angle + 22.5;
  }
  while ( angle <= 360.0 );
  x = pos->x;
  v12 = pos->z;
  lastEdge.y = pos->y + radius;
  v13 = 0.0;
  lastEdge.x = x;
  lastEdge.z = v12;
  anglea = 0.0;
  do
  {
    edge.x = pos->x;
    edge.y = BotCOS(angle: v13) * radius + pos->y;
    edge.z = BotSIN(angle: anglea) * radius + pos->z;
    NDebugOverlay::Line(origin: &edge, target: &lastEdge, r, g, b, noDepthTest: 1, duration: lifetime);
    lastEdge.y = edge.y;
    lastEdge.x = edge.x;
    lastEdge.z = edge.z;
    v13 = anglea + 22.5;
    anglea = anglea + 22.5;
  }
  while ( anglea <= 360.0 );
  v14 = pos->x;
  v15 = pos->z;
  lastEdge.y = pos->y + radius;
  v16 = 0.0;
  lastEdge.x = v14;
  lastEdge.z = v15;
  angleb = 0.0;
  do
  {
    edge.x = BotCOS(angle: v16) * radius + pos->x;
    v17 = BotSIN(angle: angleb);
    edge.z = pos->z;
    edge.y = v17 * radius + pos->y;
    NDebugOverlay::Line(origin: &edge, target: &lastEdge, r, g, b, noDepthTest: 1, duration: lifetime);
    lastEdge.x = edge.x;
    lastEdge.z = edge.z;
    lastEdge.y = edge.y;
    v16 = angleb + 22.5;
    angleb = angleb + 22.5;
  }
  while ( angleb <= 360.0 );
}

//------------------------------------------------------------------------------
// Address: 0x1026E9F0
// Name: map_showbombradius
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __cdecl map_showbombradius()
{
  float m_flBombRadius; // xmm1_4
  CBaseEntity *i; // edi
  const Vector *v2; // esi
  float y; // xmm1_4
  float z; // xmm2_4
  float v5; // xmm0_4
  double v6; // st7
  double v7; // st7
  float x; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  double v11; // st7
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  double v15; // st7
  double v16; // st7
  CBaseEntity *j; // esi
  const Vector *v18; // eax
  Vector target; // [esp+1Ch] [ebp-2Ch] BYREF
  Vector v20; // [esp+28h] [ebp-20h] BYREF
  Vector origin; // [esp+34h] [ebp-14h] BYREF
  float flBombRadius; // [esp+40h] [ebp-8h]
  float angle; // [esp+44h] [ebp-4h]

  m_flBombRadius = 500.0;
  if ( g_pMapInfo != nullptr )
    m_flBombRadius = g_pMapInfo->m_flBombRadius;
  flBombRadius = m_flBombRadius * 3.5;
  _Msg(a1: "Bomb Damage is %.0f, Radius is %.0f\n", m_flBombRadius, (float)(m_flBombRadius * 3.5));
  for ( i = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: nullptr, szName: "func_bomb_target");
        i != nullptr;
        i = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: i, szName: "func_bomb_target") )
  {
    v2 = i->WorldSpaceCenter(this: i);
    target.x = v2->x;
    target.y = v2->y;
    NDebugOverlay::Line(origin: v2, &target, r: 255, g: 255, b: 0, noDepthTest: 1, duration: 10.0);
    y = v2->y;
    z = v2->z;
    v20.x = v2->x + flBombRadius;
    v5 = 0.0;
    v20.y = y;
    v20.z = z;
    angle = 0.0;
    do
    {
      v6 = BotCOS(angle: v5);
      origin.y = v2->y;
      origin.x = v6 * flBombRadius + v2->x;
      v7 = BotSIN(angle);
      origin.z = 10.0;
      LODWORD(origin.y) = 1;
      origin.z = v7 * flBombRadius + v2->z;
      NDebugOverlay::Line(&origin, target: &v20, r: 255, g: 255, b: 0, noDepthTest: 1, duration: origin.z);
      v20.x = origin.x;
      v20.y = origin.y;
      v20.z = origin.z;
      v5 = angle + 22.5;
      angle = angle + 22.5;
    }
    while ( angle <= 360.0 );
    x = v2->x;
    v9 = v2->z;
    v20.y = flBombRadius + v2->y;
    v10 = 0.0;
    v20.x = x;
    v20.z = v9;
    angle = 0.0;
    do
    {
      origin.x = v2->x;
      BotCOS(angle: v10);
      v11 = BotSIN(angle);
      origin.z = 10.0;
      LODWORD(origin.y) = 1;
      origin.z = v11 * flBombRadius + v2->z;
      NDebugOverlay::Line(&origin, target: &v20, r: 255, g: 255, b: 0, noDepthTest: 1, duration: origin.z);
      v20.y = origin.y;
      v20.x = origin.x;
      v20.z = origin.z;
      v10 = angle + 22.5;
      angle = angle + 22.5;
    }
    while ( angle <= 360.0 );
    v12 = v2->x;
    v13 = v2->z;
    v20.y = flBombRadius + v2->y;
    v14 = 0.0;
    v20.x = v12;
    v20.z = v13;
    angle = 0.0;
    do
    {
      v15 = BotCOS(angle: v14);
      origin.z = angle;
      origin.x = v15 * flBombRadius + v2->x;
      v16 = BotSIN(angle);
      origin.z = v2->z;
      origin.y = v16 * flBombRadius + v2->y;
      NDebugOverlay::Line(&origin, target: &v20, r: 255, g: 255, b: 0, noDepthTest: SLODWORD(origin.y), duration: 10.0);
      v20.x = origin.x;
      v20.z = origin.z;
      v20.y = origin.y;
      v14 = angle + 22.5;
      angle = angle + 22.5;
    }
    while ( angle <= 360.0 );
  }
  for ( j = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: nullptr, szName: "planted_c4");
        j != nullptr;
        j = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: j, szName: "planted_c4") )
  {
    v18 = j->WorldSpaceCenter(this: j);
    DrawSphere(pos: v18, radius: flBombRadius, r: 255, g: 0, b: 0, lifetime: 10.0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026EDB0
// Name: map_setbombradius
// Source: json
//------------------------------------------------------------------------------
void __cdecl map_setbombradius(const CCommand *args)
{
  const char *v1; // eax

  if ( args->m_nArgc == 2 && UTIL_IsCommandIssuedByServerAdmin() )
  {
    if ( g_pMapInfo != nullptr
      || (CBaseEntity::Create(
            szName: "info_map_parameters",
            vecOrigin: &vec3_origin,
            vecAngles: &vec3_angle,
            pOwner: nullptr),
          g_pMapInfo != nullptr) )
    {
      v1 = locale;
      if ( args->m_nArgc > 1 )
        v1 = args->m_ppArgv[1];
      g_pMapInfo->m_flBombRadius = atof(nptr: v1);
      map_showbombradius();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026EE20
// Name: void CreateBlackMarketString(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CreateBlackMarketString()
{
  g_StringTableBlackMarket = networkstringtable->CreateStringTable(
                               this: networkstringtable,
                               a2: "BlackMarketTable",
                               a3: 1,
                               a4: 0,
                               a5: 0,
                               a6: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1026EE40
// Name: public: virtual void CCSGameRules::SpawningLatePlayer(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::SpawningLatePlayer(CCSGameRules *this, CCSPlayer *pLatePlayer)
{
  int i; // edi
  CBasePlayer *v3; // eax
  CBasePlayer *v4; // esi
  int TeamNumber; // ebx

  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: i);
    v4 = v3;
    if ( v3 != nullptr )
    {
      TeamNumber = CBaseEntity::GetTeamNumber(this: v3);
      if ( TeamNumber != CBaseEntity::GetTeamNumber(this: pLatePlayer) )
        ++v4[1].m_iAmmo.m_Value[20];
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026EEA0
// Name: public: void CCSGameRules::CloseVote(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::CloseVote(CCSGameRules *this)
{
  int i; // edi
  CBasePlayer *v2; // esi
  _BYTE *v3; // eax
  IGameEvent *v4; // esi

  this->m_voteEndTime = 0.0;
  this->m_currentVote = VoteType_None;
  for ( i = 1; i <= 64; ++i )
  {
    v2 = UTIL_PlayerByIndex(playerIndex: i);
    if ( v2 != nullptr && v2->IsPlayer(this: v2) )
    {
      v3 = __RTDynamicCast(
             inptr: v2,
             VfDelta: 0,
             SrcType: &CBaseEntity `RTTI Type Descriptor',
             TargetType: &CCSPlayer `RTTI Type Descriptor',
             isReference: 0);
      if ( v3 != nullptr )
        v3[6876] = 0;
    }
  }
  v4 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "start_vote", a3: 0, a4: 0);
  if ( v4 != nullptr )
  {
    v4->SetInt(this: v4, a2: "type", a3: 0);
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v4, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026EF50
// Name: public: bool CCSGameRules::IsPlayingFreestyle(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCSGameRules::IsPlayingFreestyle(CCSGameRules *this)
{
  return g_pGameTypes->GetCurrentGameMode(this: g_pGameTypes) == 2
      && g_pGameTypes->GetCurrentGameType(this: g_pGameTypes) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1026EF80
// Name: public: bool CCSGameRules::IsPlayingTraining(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSGameRules::IsPlayingTraining(CCSGameRules *this)
{
  return g_pGameTypes->GetCurrentGameType(this: g_pGameTypes) == 2;
}

//------------------------------------------------------------------------------
// Address: 0x1026EFA0
// Name: public: bool CCSGameRules::IsPlayingClassic(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCSGameRules::IsPlayingClassic(CCSGameRules *this)
{
  return g_pGameTypes->GetCurrentGameType(this: g_pGameTypes) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1026EFC0
// Name: public: bool CCSGameRules::IsPlayingGunGame(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCSGameRules::IsPlayingGunGame(CCSGameRules *this)
{
  return g_pGameTypes->GetCurrentGameType(this: g_pGameTypes) == 1;
}

//------------------------------------------------------------------------------
// Address: 0x1026EFE0
// Name: public: int CCSGameRules::GetFreestyleBotDifficulty(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSGameRules::GetFreestyleBotDifficulty(CCSGameRules *this)
{
  return g_pGameTypes->GetFreestyleBotDifficulty(this: g_pGameTypes);
}

//------------------------------------------------------------------------------
// Address: 0x1026EFF0
// Name: public: virtual bool CCSGameRules::ForceSplitScreenPlayersOnToSameTeam(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSGameRules::ForceSplitScreenPlayersOnToSameTeam(CCSGameRules *this)
{
  return g_pMatchFramework->IsOnlineGame(this: g_pMatchFramework);
}

//------------------------------------------------------------------------------
// Address: 0x1026F000
// Name: public: struct weeklyprice_t const __near * CCSGameRules::GetBlackMarketPriceList(void)
// Source: json
//------------------------------------------------------------------------------
const weeklyprice_t *__thiscall CCSGameRules::GetBlackMarketPriceList(CCSGameRules *this)
{
  INetworkStringTable *m_StringTableBlackMarket; // edi
  int iSize; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_StringTableBlackMarket == nullptr )
    this->m_StringTableBlackMarket = networkstringtable->FindTable(this: networkstringtable, a2: "BlackMarketTable");
  if ( this->m_pPrices != nullptr )
    goto LABEL_8;
  m_StringTableBlackMarket = this->m_StringTableBlackMarket;
  iSize = 0;
  if ( m_StringTableBlackMarket != nullptr
    && m_StringTableBlackMarket->GetNumStrings(this: m_StringTableBlackMarket) > 0 )
  {
    this->m_pPrices = (const weeklyprice_t *)m_StringTableBlackMarket->GetStringUserData(
                                               this: m_StringTableBlackMarket,
                                               a2: 0,
                                               a3: &iSize);
  }
  if ( this->m_pPrices != nullptr )
LABEL_8:
    PrepareEquipmentInfo();
  return this->m_pPrices;
}

//------------------------------------------------------------------------------
// Address: 0x1026F080
// Name: public: bool CCSGameRules::IsIntermission(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCSGameRules::IsIntermission(CCSGameRules *this)
{
  return this->m_flIntermissionEndTime > gpGlobals->curtime;
}

//------------------------------------------------------------------------------
// Address: 0x1026F140
// Name: public: virtual bool CVoiceGameMgrHelper::CanPlayerHearPlayer(class CBasePlayer __near *,class CBasePlayer __near *,bool __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CVoiceGameMgrHelper::CanPlayerHearPlayer(
        CVoiceGameMgrHelper *this,
        CBasePlayer *pListener,
        CBasePlayer *pTalker,
        bool *bProximity)
{
  if ( pTalker->IsAlive(this: pTalker) )
    return CBaseEntity::InSameTeam(this: pListener, pEntity: pTalker);
  if ( pListener->IsAlive(this: pListener) )
    return false;
  return CBaseEntity::InSameTeam(this: pListener, pEntity: pTalker);
}

//------------------------------------------------------------------------------
// Address: 0x1026F190
// Name: class Vector DropToGround(class CBaseEntity __near *,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
Vector *__usercall DropToGround@<eax>(
        int a1@<esi>,
        Vector *result,
        CBaseEntity *pMainEnt,
        const Vector *vPos,
        const Vector *vMins,
        const Vector *vMaxs)
{
  CGameTrace trace; // [esp+0h] [ebp-60h] BYREF
  Vector vecAbsEnd; // [esp+54h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+60h] [ebp+0h] BYREF

  vecAbsEnd.x = vPos->x;
  vecAbsEnd.y = vPos->y;
  vecAbsEnd.z = vPos->z - 500.0;
  UTIL_TraceHull(
    a1: &savedregs,
    a2: a1,
    vecAbsStart: vPos,
    &vecAbsEnd,
    hullMin: vMins,
    hullMax: vMaxs,
    mask: 0x200400Bu,
    ignore: pMainEnt,
    collisionGroup: 0,
    ptr: &trace);
  *result = trace.endpos;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1026F200
// Name: public: bool RevertBotsFunctor::operator()(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall RevertBotsFunctor::operator()(RevertBotsFunctor *this, CBasePlayer *basePlayer)
{
  CCSPlayer *v2; // eax

  if ( basePlayer != nullptr && basePlayer->IsPlayer(this: basePlayer) )
  {
    v2 = (CCSPlayer *)__RTDynamicCast(
                        inptr: basePlayer,
                        VfDelta: 0,
                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                        TargetType: &CCSPlayer `RTTI Type Descriptor',
                        isReference: 0);
    if ( v2 != nullptr && v2->m_bIsControllingBot.m_Value )
      CCSPlayer::ReleaseControlOfBot(this: v2);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1026F250
// Name: public: virtual void CCSGameRules::PlayerSpawn(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::PlayerSpawn(CCSGameRules *this, CBasePlayer *pBasePlayer)
{
  CCSPlayer *v2; // edi
  bool v3; // bl
  CBaseEntity *EntityByClassname; // esi
  const char *v5; // [esp+0h] [ebp-8h]

  if ( pBasePlayer != nullptr && pBasePlayer->IsPlayer(this: pBasePlayer) )
  {
    v2 = (CCSPlayer *)__RTDynamicCast(
                        inptr: pBasePlayer,
                        VfDelta: 0,
                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                        TargetType: &CCSPlayer `RTTI Type Descriptor',
                        isReference: 0);
    if ( v2 != nullptr )
      goto LABEL_5;
  }
  else
  {
    v2 = nullptr;
  }
  _Error(this: (ISceneTokenProcessor *)&stru_104D3920, a2: v5);
LABEL_5:
  if ( v2->m_iPlayerState.m_Value != STATE_ACTIVE )
    return;
  v2->EquipSuit(this: v2, a2: true);
  if ( mp_defuser_allocation.m_pParent != nullptr && mp_defuser_allocation.m_pParent->m_Value.m_nValue == 1 )
    CCSPlayer::RemoveDefuser(this: v2);
  v3 = g_pGameTypes->GetCurrentGameType(this: g_pGameTypes) != 2;
  EntityByClassname = CGlobalEntityList::FindEntityByClassname(
                        this: &gEntList,
                        pStartEntity: nullptr,
                        szName: "game_player_equip");
  if ( EntityByClassname != nullptr )
  {
    do
    {
      if ( v3 )
        v2->RemoveAllItems(this: v2, a2: true);
      EntityByClassname->Touch(this: EntityByClassname, a2: v2);
      v3 = false;
      EntityByClassname = CGlobalEntityList::FindEntityByClassname(
                            this: &gEntList,
                            pStartEntity: EntityByClassname,
                            szName: "game_player_equip");
    }
    while ( EntityByClassname != nullptr );
LABEL_16:
    if ( !v2->m_bIsVIP )
      return;
    goto LABEL_17;
  }
  if ( !v3 )
    goto LABEL_16;
LABEL_17:
  CCSPlayer::GiveDefaultItems(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1026F360
// Name: public: void CCSGameRules::BroadcastSound(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::BroadcastSound(CCSGameRules *this, const char *sound, int team)
{
  CTeam *GlobalTeam; // eax
  CBroadcastRecipientFilter filter; // [esp+4h] [ebp-20h] BYREF

  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&filter);
  if ( team != -1 )
  {
    CRecipientFilter::RemoveAllRecipients(this: &filter);
    GlobalTeam = GetGlobalTeam(iIndex: team);
    CRecipientFilter::AddRecipientsByTeam(this: &filter, team: GlobalTeam);
  }
  UserMessageBegin(&filter, messagename: "SendAudio");
  MessageWriteString(sz: sound);
  MessageEnd();
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x1026F3E0
// Name: private: float CCSGameRules::GetExplosionDamageAdjustment(class Vector __near &,class Vector __near &,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
double __userpurge CCSGameRules::GetExplosionDamageAdjustment@<st0>(
        CCSGameRules *this@<ecx>,
        int a2@<esi>,
        Vector *vecSrc,
        Vector *vecEnd,
        CBaseEntity *pEntityToIgnore)
{
  const Vector *v5; // ebx
  CBaseEntity *v6; // edi
  CBaseEntity *m_pEnt; // esi
  IPhysicsObject *m_pPhysicsObject; // ecx
  int v10; // eax
  float v11; // xmm0_4
  CGameTrace tr; // [esp+0h] [ebp-5Ch] BYREF
  float flThickness; // [esp+54h] [ebp-8h] BYREF
  float retval; // [esp+58h] [ebp-4h]
  IHandleEntity savedregs; // [esp+5Ch] [ebp+0h] BYREF

  v5 = vecEnd;
  v6 = pEntityToIgnore;
  retval = 0.0;
  UTIL_TraceLine(
    a1: &savedregs,
    a2,
    vecAbsStart: vecSrc,
    vecAbsEnd: vecEnd,
    mask: 0x46004003u,
    ignore: pEntityToIgnore,
    collisionGroup: 0,
    ptr: &tr);
  if ( tr.fraction == 1.0 )
  {
    retval = 1.0;
    return 1.0;
  }
  if ( !CGameTrace::DidHitWorld(this: &tr) )
  {
    m_pEnt = tr.m_pEnt;
    if ( tr.m_pEnt != nullptr && tr.m_pEnt != v6 && CBaseEntity::GetOwnerEntity(this: tr.m_pEnt) != v6 )
    {
      UTIL_TraceLine(
        a1: &savedregs,
        a2: (int)m_pEnt,
        vecAbsStart: vecSrc,
        vecAbsEnd: v5,
        mask: 1u,
        ignore: nullptr,
        collisionGroup: 0,
        ptr: &tr);
      if ( tr.fraction == 1.0 )
      {
        if ( m_pEnt != nullptr && (m_pPhysicsObject = m_pEnt->m_pPhysicsObject) != nullptr )
        {
          v10 = m_pPhysicsObject->GetMaterialIndex(this: m_pPhysicsObject);
          physprops->GetPhysicsProperties(
            this: physprops,
            a2: v10,
            a3: (float *)&vecSrc,
            a4: &flThickness,
            a5: (float *)&vecEnd,
            a6: (float *)&pEntityToIgnore);
          v11 = *(float *)&vecSrc * 0.00033333333;
          if ( (float)(*(float *)&vecSrc * 0.00033333333) >= 0.0 && v11 < 1.0 )
            return (float)(1.0 - v11);
          if ( v11 < 0.0 )
          {
            retval = 1.0;
            return 1.0;
          }
        }
        else
        {
          return 0.75;
        }
      }
    }
  }
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x1026F540
// Name: private: float CCSGameRules::GetAmountOfEntityVisible(class Vector __near &,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCSGameRules::GetAmountOfEntityVisible(CCSGameRules *this, Vector *vecSrc, CBaseEntity *entity)
{
  CBaseEntity_vtbl *v6; // eax
  __int64 v7; // xmm0_8
  Vector *(__thiscall *BodyTarget)(CBaseEntity *, Vector *, const Vector *, bool); // edx
  float z; // ecx
  int m_iEFlags; // edx
  unsigned int v11; // eax
  float v12; // ecx
  int v13; // edx
  float v14; // eax
  Vector vecChest; // [esp+Ch] [ebp-48h] BYREF
  Vector vecFeet; // [esp+18h] [ebp-3Ch] BYREF
  Vector vecTarget; // [esp+24h] [ebp-30h] BYREF
  Vector vecRightSide; // [esp+30h] [ebp-24h] BYREF
  Vector vecLeftSide; // [esp+3Ch] [ebp-18h] BYREF
  Vector vecRightFacing; // [esp+48h] [ebp-Ch] BYREF
  int savedregs; // [esp+54h] [ebp+0h] BYREF
  float retval; // [esp+5Ch] [ebp+8h]
  float retvala; // [esp+5Ch] [ebp+8h]
  float retvalb; // [esp+5Ch] [ebp+8h]
  float retvalc; // [esp+5Ch] [ebp+8h]
  float retvald; // [esp+5Ch] [ebp+8h]

  if ( entity->IsPlayer(this: entity) )
  {
    if ( (entity->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: entity, a2: (int)&savedregs);
    v6 = entity->__vftable;
    v7 = *(_QWORD *)&entity->m_vecAbsOrigin.x;
    vecFeet.z = entity->m_vecAbsOrigin.z;
    BodyTarget = v6->BodyTarget;
    *(_QWORD *)&vecFeet.x = v7;
    BodyTarget(this: entity, result: &vecChest, a3: vecSrc, a4: false);
    retval = vecChest.z - vecFeet.z;
    if ( (entity->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: entity, a2: (int)&savedregs);
    z = entity->m_vecAbsOrigin.z;
    m_iEFlags = entity->m_iEFlags;
    *(_QWORD *)&vecTarget.x = *(_QWORD *)&entity->m_vecAbsOrigin.x;
    vecTarget.z = z + 71.0;
    if ( (m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: entity, a2: (int)&savedregs);
    AngleVectors(angles: &entity->m_angAbsRotation, forward: nullptr, right: &vecRightFacing, up: nullptr);
    VectorNormalize(vec: &vecRightFacing);
    v11 = (unsigned int)entity->m_iEFlags >> 11;
    vecRightFacing.x = vecRightFacing.x * 16.0;
    vecRightFacing.y = vecRightFacing.y * 16.0;
    vecRightFacing.z = vecRightFacing.z * 16.0;
    if ( (v11 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: entity, a2: (int)&savedregs);
    v12 = entity->m_vecAbsOrigin.z;
    v13 = entity->m_iEFlags;
    *(_QWORD *)&vecLeftSide.x = *(_QWORD *)&entity->m_vecAbsOrigin.x;
    vecLeftSide.x = vecLeftSide.x - vecRightFacing.x;
    vecLeftSide.y = vecLeftSide.y - vecRightFacing.y;
    vecLeftSide.z = v12 + retval;
    if ( (v13 & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: entity, a2: (int)&savedregs);
    v14 = entity->m_vecAbsOrigin.z;
    *(_QWORD *)&vecRightSide.x = *(_QWORD *)&entity->m_vecAbsOrigin.x;
    vecRightSide.x = vecRightSide.x + vecRightFacing.x;
    vecRightSide.y = vecRightSide.y + vecRightFacing.y;
    vecRightSide.z = v14 + retval;
    retvala = CCSGameRules::GetExplosionDamageAdjustment(
                this,
                a2: (int)entity,
                vecSrc,
                vecEnd: &vecChest,
                pEntityToIgnore: entity)
            * 0.40000001;
    retvalb = CCSGameRules::GetExplosionDamageAdjustment(
                this,
                a2: (int)entity,
                vecSrc,
                vecEnd: &vecTarget,
                pEntityToIgnore: entity)
            * 0.2
            + retvala;
    retvalc = CCSGameRules::GetExplosionDamageAdjustment(
                this,
                a2: (int)entity,
                vecSrc,
                vecEnd: &vecFeet,
                pEntityToIgnore: entity)
            * 0.2
            + retvalb;
    retvald = CCSGameRules::GetExplosionDamageAdjustment(
                this,
                a2: (int)entity,
                vecSrc,
                vecEnd: &vecLeftSide,
                pEntityToIgnore: entity)
            * 0.1
            + retvalc;
    return CCSGameRules::GetExplosionDamageAdjustment(
             this,
             a2: (int)entity,
             vecSrc,
             vecEnd: &vecRightSide,
             pEntityToIgnore: entity)
         * 0.1
         + retvald;
  }
  else
  {
    vecTarget = *entity->BodyTarget(this: entity, result: &vecFeet, a3: vecSrc, a4: 0);
    return CCSGameRules::GetExplosionDamageAdjustment(
             this,
             a2: (int)entity,
             vecSrc,
             vecEnd: &vecTarget,
             pEntityToIgnore: entity);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026F7D0
// Name: public: void CCSGameRules::RadiusDamage(class CTakeDamageInfo const __near &,class Vector const __near &,float,int,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CCSGameRules::RadiusDamage(
        CCSGameRules *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const CTakeDamageInfo *info,
        const Vector *vecSrcIn,
        float flRadius,
        int iClassIgnore,
        bool bIgnoreWorld)
{
  unsigned int m_Index; // eax
  CEntInfo *v10; // ecx
  IHandleEntity *m_pEntity; // esi
  float x; // edi
  unsigned int v13; // eax
  IHandleEntity *v14; // ecx
  const char *v15; // eax
  const char *v16; // eax
  float z; // ecx
  CBaseEntity *CurrentEntity; // esi
  CBaseEntity *v19; // eax
  CBaseEntity *v20; // edi
  bool v21; // zf
  float *v22; // eax
  float y; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4
  double AmountOfEntityVisible; // st7
  __int128 v27; // xmm0
  __int128 v28; // xmm1
  int v29; // eax
  float v30; // xmm0_4
  float v31; // xmm0_4
  unsigned int v32; // eax
  IHandleEntity *v33; // ecx
  float v34; // esi
  int TeamNumber; // edi
  int y_low; // esi
  _DWORD v38[3]; // [esp+24h] [ebp-964h] BYREF
  CEntitySphereQuery sphere; // [esp+30h] [ebp-958h] BYREF
  CGameTrace tr; // [esp+838h] [ebp-150h] BYREF
  int v41; // [esp+890h] [ebp-F8h] BYREF
  float v42; // [esp+89Ch] [ebp-ECh] BYREF
  float v43; // [esp+8A0h] [ebp-E8h]
  float v44; // [esp+8A4h] [ebp-E4h]
  _BYTE adjustedInfo[100]; // [esp+8A8h] [ebp-E0h] OVERLAPPED
  Vector v46; // [esp+910h] [ebp-78h] BYREF
  Vector vecTarget; // [esp+91Ch] [ebp-6Ch]
  Vector vecToTarget; // [esp+928h] [ebp-60h]
  float flAdjustedDamage; // [esp+934h] [ebp-54h]
  Vector vecSpot; // [esp+938h] [ebp-50h]
  Vector v51; // [esp+944h] [ebp-44h] OVERLAPPED BYREF
  Vector dir; // [esp+950h] [ebp-38h] BYREF
  Vector vecEndPos; // [esp+95Ch] [ebp-2Ch]
  __int64 falloff; // [esp+968h] [ebp-20h] OVERLAPPED BYREF
  float radius; // [esp+970h] [ebp-18h]
  Vector vecSrc; // [esp+974h] [ebp-14h] BYREF
  CCSPlayer *pCSExplosionAttacker; // [esp+980h] [ebp-8h]
  CCSPlayer *retaddr; // [esp+988h] [ebp+0h]

  vecSrc.z = a2;
  pCSExplosionAttacker = retaddr;
  m_Index = info->m_hAttacker.m_Index;
  LODWORD(vecSpot.x) = this;
  vecEndPos.y = 0.0;
  if ( m_Index != -1
    && (v10 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
    && (m_pEntity = v10->m_pEntity, v10->m_pEntity != nullptr)
    && ((unsigned __int8 (__thiscall *)(IHandleEntity *, int, int))m_pEntity->__vftable[28].dtr_IHandleEntity)(
         a1: v10->m_pEntity,
         a2: a3,
         a3: a4) != 0 )
  {
    x = COERCE_FLOAT(
          __RTDynamicCast(
            inptr: m_pEntity,
            VfDelta: 0,
            SrcType: &CBaseEntity `RTTI Type Descriptor',
            TargetType: &CCSPlayer `RTTI Type Descriptor',
            isReference: 0));
    vecSrc.x = x;
  }
  else
  {
    vecSrc.x = 0.0;
    x = 0.0;
  }
  v13 = info->m_hInflictor.m_Index;
  if ( v13 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_SerialNumber != HIWORD(v13) )
  {
    vecEndPos.z = 0.0;
LABEL_14:
    BYTE2(vecSrc.y) = 0;
    goto LABEL_15;
  }
  v14 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_pEntity;
  LODWORD(vecEndPos.z) = v14;
  if ( v14 == nullptr )
    goto LABEL_14;
  v15 = (const char *)v14[23].__vftable;
  if ( v15 == nullptr )
    v15 = locale;
  BYTE2(vecSrc.y) = 1;
  if ( _V_strcmp(s1: v15, s2: "hegrenade_projectile") != 0 )
    goto LABEL_14;
LABEL_15:
  if ( LODWORD(vecEndPos.z) == 0 )
    goto LABEL_19;
  v16 = *(const char **)(LODWORD(vecEndPos.z) + 92);
  if ( v16 == nullptr )
    v16 = locale;
  HIBYTE(vecSrc.y) = 1;
  if ( _V_strcmp(s1: v16, s2: "planted_c4") != 0 )
LABEL_19:
    HIBYTE(vecSrc.y) = 0;
  z = vecSrcIn->z;
  falloff = *(_QWORD *)&vecSrcIn->x;
  memset((void *)&dir, 0, sizeof(dir));
  radius = z;
  vecSpot.z = 1.0;
  if ( flRadius == 0.0 )
    vecEndPos.x = 1.0;
  else
    vecEndPos.x = info->m_flDamage / flRadius;
  LODWORD(vecSpot.y) = (enginetrace->GetPointContents(
                          this: enginetrace,
                          a2: (const Vector *)&falloff,
                          a3: 16432,
                          a4: nullptr)
                      & 0x4030) != 0;
  CEntitySphereQuery::CEntitySphereQuery(
    this: (CEntitySphereQuery *)v38,
    center: (const Vector *)&falloff,
    radius: flRadius,
    flagMask: 0);
  CurrentEntity = CEntitySphereQuery::GetCurrentEntity(this: (CEntitySphereQuery *)v38);
  if ( CurrentEntity != nullptr )
  {
    while ( 1 )
    {
      BYTE1(vecSrc.y) = 0;
      if ( CurrentEntity->IsPlayer(this: CurrentEntity) )
      {
        v19 = (CBaseEntity *)__RTDynamicCast(
                               inptr: CurrentEntity,
                               VfDelta: 0,
                               SrcType: &CBaseEntity `RTTI Type Descriptor',
                               TargetType: &CCSPlayer `RTTI Type Descriptor',
                               isReference: 0);
        v20 = v19;
        if ( v19 != nullptr )
          BYTE1(vecSrc.y) = v19->IsAlive(this: v19);
      }
      else
      {
        v20 = nullptr;
      }
      if ( CurrentEntity->m_takedamage.m_Value == 0 )
        goto LABEL_56;
      if ( iClassIgnore == 0 || CurrentEntity->Classify(this: CurrentEntity) != iClassIgnore )
      {
        if ( bIgnoreWorld
          || (LODWORD(vecSpot.y) == 0
            ? (v21 = CurrentEntity->m_nWaterLevel.m_Value == 3)
            : (v21 = CurrentEntity->m_nWaterLevel.m_Value == 0),
              !v21) )
        {
          v22 = (float *)CurrentEntity->BodyTarget(
                           this: CurrentEntity,
                           result: (Vector *)&v41,
                           a3: (const Vector *)&falloff,
                           a4: true);
          y = *v22;
          v24 = v22[1];
          v25 = v22[2];
          vecToTarget.y = *v22;
          vecToTarget.z = v24;
          flAdjustedDamage = v25;
          if ( !bIgnoreWorld )
          {
            AmountOfEntityVisible = CCSGameRules::GetAmountOfEntityVisible(
                                      this: (CCSGameRules *)LODWORD(vecSpot.x),
                                      vecSrc: (Vector *)&falloff,
                                      entity: CurrentEntity);
            vecSpot.z = AmountOfEntityVisible;
            if ( AmountOfEntityVisible <= 0.0 )
              goto LABEL_56;
            y = vecToTarget.y;
            v24 = vecToTarget.z;
            v25 = flAdjustedDamage;
          }
          dir.y = v24;
          dir.x = y;
          vecTarget.x = y - *(float *)&falloff;
          dir.z = v25;
          vecTarget.y = v24 - *((float *)&falloff + 1);
          vecTarget.z = v25 - radius;
          v27 = 0;
          *(float *)&v27 = fsqrt(
                             (float)((float)(vecTarget.y * vecTarget.y) + (float)(vecTarget.z * vecTarget.z))
                           + (float)(vecTarget.x * vecTarget.x));
          *(_OWORD *)&adjustedInfo[84] = v27;
          vecToTarget.x = (float)(info->m_flDamage - (float)(*(float *)&v27 * vecEndPos.x)) * vecSpot.z;
          if ( vecToTarget.x <= 0.0 )
            goto LABEL_56;
          if ( (CTakeDamageInfo::CTakeDamageInfo(this: (CTakeDamageInfo *)&v42, __that: info),
                *(float *)&adjustedInfo[64] = flRadius,
                *(float *)&adjustedInfo[36] = vecToTarget.x,
                v51 = vecTarget,
                VectorNormalize(vec: &v51),
                vec3_origin.x == *(float *)adjustedInfo)
            && vec3_origin.y == *(float *)&adjustedInfo[4]
            && vec3_origin.z == *(float *)&adjustedInfo[8]
            || vec3_origin.x == v42 && vec3_origin.y == v43 && vec3_origin.z == v44 )
          {
            CalculateExplosiveDamageForce(
              info: (CTakeDamageInfo *)&v42,
              vecDir: &v51,
              vecForceOrigin: (const Vector *)&falloff,
              flScale: 1.5);
          }
          else
          {
            v28 = 0;
            *(float *)&v28 = fsqrt((float)((float)(v42 * v42) + (float)(v44 * v44)) + (float)(v43 * v43));
            *(_OWORD *)&adjustedInfo[84] = v28;
            *(_QWORD *)adjustedInfo = falloff;
            v42 = v51.x * (float)(*(float *)&v28 * vecEndPos.x);
            v43 = v51.y * (float)(*(float *)&v28 * vecEndPos.x);
            v44 = v51.z * (float)(*(float *)&v28 * vecEndPos.x);
            *(float *)&adjustedInfo[8] = radius;
          }
          v29 = (int)CurrentEntity->BodyTarget(
                       this: CurrentEntity,
                       result: (Vector *)&tr.m_pEnt,
                       a3: (const Vector *)&falloff,
                       a4: false);
          v30 = *(float *)v29;
          LODWORD(vecSrc.x) = &sphere.m_pList[509];
          radius = 0.0;
          v46.x = v30;
          v31 = *(float *)(v29 + 4);
          HIDWORD(falloff) = 0;
          v46.y = v31;
          v46.z = *(float *)(v29 + 8);
          UTIL_TraceLine(
            a1: (const IHandleEntity *)&vecSrc.z,
            a2: (int)CurrentEntity,
            vecAbsStart: (const Vector *)&falloff,
            vecAbsEnd: &v46,
            mask: 0x46004003u,
            ignore: nullptr,
            collisionGroup: 0,
            ptr: (CGameTrace *)&sphere.m_pList[509]);
          if ( tr.plane.normal.z == 1.0 )
          {
            CBaseEntity::TakeDamage(
              this: CurrentEntity,
              a2: (int)CurrentEntity,
              inputInfo: (const CTakeDamageInfo *)&v42);
          }
          else
          {
            ClearMultiDamage();
            CBaseEntity::DispatchTraceAttack(
              this: CurrentEntity,
              info: (const CTakeDamageInfo *)&v42,
              vecDir: &v51,
              ptr: (CGameTrace *)&sphere.m_pList[509]);
            ApplyMultiDamage();
          }
          CBaseEntity::TraceAttackToTriggers(
            this: CurrentEntity,
            a2: (int)&vecSrc.z,
            info: (const CTakeDamageInfo *)&v42,
            start: (const Vector *)&falloff,
            end: &dir,
            dir: &v51);
          if ( v20 != nullptr )
            break;
        }
      }
LABEL_69:
      ++v38[0];
      CurrentEntity = CEntitySphereQuery::GetCurrentEntity(this: (CEntitySphereQuery *)v38);
      if ( CurrentEntity == nullptr )
      {
        x = vecSrc.x;
        goto LABEL_71;
      }
    }
    if ( LODWORD(vecSrc.x) != 0 && BYTE2(vecSrc.y) != 0 )
      CCSGameStats::IncrementStat(
        this: &CCS_GameStats,
        pPlayer: (CCSPlayer *)LODWORD(vecSrc.x),
        statId: CSSTAT_GRENADE_DAMAGE,
        iDelta: (int)*(float *)&adjustedInfo[36],
        bPlayerOnly: false);
LABEL_56:
    if ( v20 != nullptr )
    {
      if ( HIBYTE(vecSrc.y) != 0 && LODWORD(vecEndPos.z) != 0 )
      {
        v32 = *(_DWORD *)(LODWORD(vecEndPos.z) + 1228);
        if ( v32 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v32].m_SerialNumber != HIWORD(v32) )
          v33 = nullptr;
        else
          v33 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v32].m_pEntity;
        LODWORD(vecSrc.x) = v33;
      }
      v34 = vecSrc.x;
      if ( LODWORD(vecSrc.x) != 0 && !v20->IsAlive(this: v20) && BYTE1(vecSrc.y) != 0 )
      {
        TeamNumber = CBaseEntity::GetTeamNumber(this: v20);
        if ( TeamNumber != CBaseEntity::GetTeamNumber(this: (CBaseEntity *)LODWORD(v34)) )
          ++LODWORD(vecEndPos.y);
      }
    }
    goto LABEL_69;
  }
LABEL_71:
  if ( x != 0.0 )
  {
    y_low = LODWORD(vecEndPos.y);
    if ( BYTE2(vecSrc.y) != 0 && SLODWORD(vecEndPos.y) >= 3 )
    {
      CBaseMultiplayerPlayer::AwardAchievement(
        this: (CBaseMultiplayerPlayer *)LODWORD(x),
        iAchievement: 3035,
        iCount: 1);
      CCSPlayer::CheckMaxGrenadeKills(this: (CCSPlayer *)LODWORD(x), grenadeKills: y_low);
    }
    if ( HIBYTE(vecSrc.y) != 0 && y_low >= 5 )
      CBaseMultiplayerPlayer::AwardAchievement(
        this: (CBaseMultiplayerPlayer *)LODWORD(x),
        iAchievement: 1008,
        iCount: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026FE60
// Name: public: virtual void CCSGameRules::InitDefaultAIRelationships(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::InitDefaultAIRelationships(CCSGameRules *this)
{
  int v1; // ebx
  Class_T i; // edi
  Class_T j; // esi

  CBaseCombatCharacter::AllocateDefaultRelationships();
  if ( g_pGameRules != nullptr )
    v1 = g_pGameRules->NumEntityClasses(this: g_pGameRules);
  else
    v1 = 27;
  for ( i = CLASS_NONE; i < v1; ++i )
  {
    for ( j = CLASS_NONE; j < v1; ++j )
      CBaseCombatCharacter::SetDefaultRelationship(nClass: i, nClassTarget: j, nDisposition: D_NU, nPriority: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1026FEC0
// Name: public: virtual bool CCSGameRules::FShouldSwitchWeapon(class CBasePlayer __near *,class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSGameRules::FShouldSwitchWeapon(CCSGameRules *this, CBasePlayer *pPlayer, CBaseCombatWeapon *pWeapon)
{
  bool v3; // bl
  void *v5; // eax
  edict_t *m_pPev; // eax
  const char *v7; // eax

  v3 = false;
  if ( pPlayer != nullptr && pPlayer->IsPlayer(this: pPlayer) )
  {
    v5 = __RTDynamicCast(
           inptr: pPlayer,
           VfDelta: 0,
           SrcType: &CBaseEntity `RTTI Type Descriptor',
           TargetType: &CCSPlayer `RTTI Type Descriptor',
           isReference: 0);
    if ( v5 != nullptr )
      v3 = (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)v5 + 2032))(a1: v5) != 0;
  }
  if ( CBaseCombatCharacter::GetActiveWeapon(this: pPlayer) != nullptr && pPlayer->IsNetClient(this: pPlayer) && !v3 )
  {
    m_pPev = pPlayer->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      m_pPev -= (int)gpGlobals->pEdicts;
    v7 = engine->GetClientConVarValue(this: engine, a2: m_pPev, a3: "cl_autowepswitch");
    if ( v7 != nullptr && atoi(nptr: v7) <= 0 )
      return false;
  }
  return (!pPlayer->IsBot(this: pPlayer) || v3)
      && this->GetAllowWeaponSwitch(this)
      && CMultiplayRules::FShouldSwitchWeapon(this, pPlayer, pWeapon);
}

//------------------------------------------------------------------------------
// Address: 0x1026FFB0
// Name: public: virtual void CCSGameRules::LevelShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::LevelShutdown(CCSGameRules *this)
{
  const char *pszValue; // eax
  int CSLevelIndex; // eax

  pszValue = gpGlobals->mapname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  CSLevelIndex = GetCSLevelIndex(pLevelName: pszValue);
  if ( CSLevelIndex != -1 )
  {
    g_iTerroristVictories[CSLevelIndex] += this->m_iNumTerroristWins;
    g_iCounterTVictories[CSLevelIndex] += this->m_iNumCTWins;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10270000
// Name: public: void CCSGameRules::InitializePlayerCounts(int __near &,int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::InitializePlayerCounts(
        CCSGameRules *this,
        int *NumAliveTerrorist,
        int *NumAliveCT,
        int *NumDeadTerrorist,
        int *NumDeadCT)
{
  int v6; // edi
  CTeam *GlobalTeam; // ebx
  CBasePlayer *v8; // edi
  _DWORD *v9; // edi
  int v10; // eax
  int *v11; // eax
  int iTeam; // [esp+8h] [ebp-8h]
  int iPlayer; // [esp+Ch] [ebp-4h]

  v6 = 0;
  *NumDeadTerrorist = 0;
  *NumDeadCT = 0;
  *NumAliveCT = 0;
  *NumAliveTerrorist = 0;
  this->m_iNumSpawnableCT = 0;
  this->m_iNumSpawnableTerrorist = 0;
  this->m_iNumCT = 0;
  this->m_iNumTerrorist = 0;
  this->m_iHaveEscaped = 0;
  for ( iTeam = 0; v6 < GetNumberOfTeams(); iTeam = v6 )
  {
    GlobalTeam = GetGlobalTeam(iIndex: v6);
    iPlayer = 0;
    if ( GlobalTeam->GetNumPlayers(this: GlobalTeam) > 0 )
    {
      do
      {
        v8 = GlobalTeam->GetPlayer(this: GlobalTeam, a2: iPlayer);
        if ( v8 != nullptr && v8->IsPlayer(this: v8) )
        {
          v9 = __RTDynamicCast(
                 inptr: v8,
                 VfDelta: 0,
                 SrcType: &CBaseEntity `RTTI Type Descriptor',
                 TargetType: &CCSPlayer `RTTI Type Descriptor',
                 isReference: 0);
          if ( v9 != nullptr )
          {
            v10 = GlobalTeam->GetTeamNumber(this: GlobalTeam) - 2;
            if ( v10 != 0 )
            {
              if ( v10 == 1 )
              {
                ++this->m_iNumCT;
                if ( v9[1206] != 3 )
                  ++this->m_iNumSpawnableCT;
                if ( *((_BYTE *)v9 + 553) != 0 )
                  ++*NumDeadCT;
                else
                  ++*NumAliveCT;
              }
            }
            else
            {
              ++this->m_iNumTerrorist;
              if ( v9[1206] != 3 )
                ++this->m_iNumSpawnableTerrorist;
              v11 = NumDeadTerrorist;
              if ( *((_BYTE *)v9 + 553) == 0 )
                v11 = NumAliveTerrorist;
              ++*v11;
              if ( *((_BYTE *)v9 + 4901) == 1 )
                ++this->m_iHaveEscaped;
            }
          }
        }
        ++iPlayer;
      }
      while ( iPlayer < GlobalTeam->GetNumPlayers(this: GlobalTeam) );
      v6 = iTeam;
    }
    ++v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10270180
// Name: protected: static void CCSGameRules::SplitScoreAmongPlayersInRange(int,int,class CCSPlayer __near *,class Vector const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall CCSGameRules::SplitScoreAmongPlayersInRange(
        int a1@<ebp>,
        int iPoints,
        int iTeam,
        CCSPlayer *pExcludePlayer,
        const Vector *center,
        float fRangeInner,
        float fRangeOuter)
{
  int v7; // edi
  CCSPlayer *v8; // eax
  CBaseEntity *v9; // esi
  const Vector *v10; // eax
  float v11; // xmm1_4
  __int128 v12; // xmm0
  float v13; // xmm0_4
  CGlobalVars *v14; // ecx
  int v15; // edi
  CCSPlayer *v16; // esi
  _BYTE v17[272]; // [esp-Ch] [ebp-12Ch] OVERLAPPED BYREF
  float v18; // [esp+104h] [ebp-1Ch]
  float v19; // [esp+108h] [ebp-18h]
  float v20; // [esp+10Ch] [ebp-14h]
  int v21; // [esp+110h] [ebp-10h]
  int v22; // [esp+114h] [ebp-Ch] BYREF
  float fWeightSum; // [esp+118h] [ebp-8h]
  float retaddr; // [esp+120h] [ebp+0h]

  v22 = a1;
  fWeightSum = retaddr;
  *(float *)&v21 = fRangeOuter * fRangeOuter;
  memset(dst: (int)v17, value: nullptr, count: 0x100u);
  v7 = 1;
  v20 = 0.0;
  if ( gpGlobals->maxClients >= 1 )
  {
    do
    {
      v8 = (CCSPlayer *)UTIL_PlayerByIndex(playerIndex: v7);
      v9 = v8;
      if ( v8 != nullptr && v8 != pExcludePlayer && CBaseEntity::GetTeamNumber(this: v8) == iTeam )
      {
        if ( (v9->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v9, a2: (int)&v22);
        v10 = center;
        if ( *(float *)&v21 >= (float)((float)((float)((float)(center->y - v9->m_vecAbsOrigin.y)
                                                     * (float)(center->y - v9->m_vecAbsOrigin.y))
                                             + (float)((float)(v10->x - v9->m_vecAbsOrigin.x)
                                                     * (float)(v10->x - v9->m_vecAbsOrigin.x)))
                                     + (float)((float)(center->z - v9->m_vecAbsOrigin.z)
                                             * (float)(center->z - v9->m_vecAbsOrigin.z))) )
        {
          if ( (v9->m_iEFlags & 0x800) != 0 )
          {
            CBaseEntity::CalcAbsolutePosition(this: v9, a2: (int)&v22);
            v10 = center;
          }
          v11 = v10->y - v9->m_vecAbsOrigin.y;
          v12 = 0;
          *(float *)&v12 = fsqrt(
                             (float)((float)(v11 * v11)
                                   + (float)((float)(v10->z - v9->m_vecAbsOrigin.z)
                                           * (float)(v10->z - v9->m_vecAbsOrigin.z)))
                           + (float)((float)(v10->x - v9->m_vecAbsOrigin.x) * (float)(v10->x - v9->m_vecAbsOrigin.x)));
          *(_OWORD *)&v17[256] = v12;
          if ( *(float *)&v12 <= fRangeInner )
            v13 = 1.0;
          else
            v13 = (float)(fRangeOuter - *(float *)&v17[256]) / (float)(fRangeOuter - fRangeInner);
          v20 = v13 + v20;
          *(float *)&v17[4 * v7] = v13;
        }
      }
      v14 = gpGlobals;
      ++v7;
    }
    while ( v7 <= gpGlobals->maxClients );
    if ( v20 != 0.0 )
    {
      v15 = 1;
      if ( gpGlobals->maxClients >= 1 )
      {
        do
        {
          v19 = *(float *)&v17[4 * v15];
          if ( v19 > 0.0 )
          {
            v16 = (CCSPlayer *)UTIL_PlayerByIndex(playerIndex: v15);
            v18 = (float)((float)iPoints * v19) / v20;
            v21 = (int)v18;
            CCSPlayer::AddScore(this: v16, iPoints: v21);
            CCSPlayer::AddRoundProximityScore(this: v16, iPoints: v21);
            v14 = gpGlobals;
          }
          ++v15;
        }
        while ( v15 <= v14->maxClients );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102703B0
// Name: public: void CCSGameRules::ScoreHostageRescue(class CCSPlayer __near *,class CHostage __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::ScoreHostageRescue(CCSGameRules *this, CCSPlayer *pPlayer, CHostage *pHostage)
{
  int m_nValue; // eax
  unsigned int v5; // edx
  int v6; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF
  float pPlayera; // [esp+14h] [ebp+8h]
  float pHostagea; // [esp+18h] [ebp+Ch]

  if ( pPlayer != nullptr )
  {
    if ( contributionscore_hostage_rescue.m_pParent != nullptr )
      m_nValue = contributionscore_hostage_rescue.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    pPlayer->m_iContributionScore += m_nValue;
  }
  if ( pHostage != nullptr )
  {
    v5 = (unsigned int)pHostage->m_iEFlags >> 11;
    pPlayera = score_hostage_rescue_radius_outer.m_pParent->m_Value.m_fValue;
    pHostagea = score_hostage_rescue_radius_inner.m_pParent->m_Value.m_fValue;
    if ( (v5 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pHostage, a2: (int)&savedregs);
    if ( score_hostage_rescue_bonus.m_pParent != nullptr )
      v6 = score_hostage_rescue_bonus.m_pParent->m_Value.m_nValue;
    else
      v6 = 0;
    CCSGameRules::SplitScoreAmongPlayersInRange(
      a1: (int)&savedregs,
      iPoints: v6,
      iTeam: 3,
      pExcludePlayer: nullptr,
      center: &pHostage->m_vecAbsOrigin,
      fRangeInner: pHostagea,
      fRangeOuter: pPlayera);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10270450
// Name: public: void CCSGameRules::GetPlayerCounts(struct CCSGameRules::TeamPlayerCounts __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::GetPlayerCounts(CCSGameRules *this, CCSGameRules::TeamPlayerCounts *teamCounts)
{
  int v2; // eax
  CBasePlayer *v3; // eax
  CBasePlayer *v4; // edi
  unsigned int TeamNumber; // eax
  CCSGameRules::TeamPlayerCounts *v6; // esi
  int i; // [esp+4h] [ebp-4h]

  memset(dst: (int)teamCounts, value: nullptr, count: 0x60u);
  v2 = 1;
  for ( i = 1; v2 <= gpGlobals->maxClients; i = v2 )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: v2);
    v4 = v3;
    if ( v3 != nullptr )
    {
      TeamNumber = CBaseEntity::GetTeamNumber(this: v3);
      if ( TeamNumber <= 3 )
      {
        ++teamCounts[TeamNumber].totalPlayers;
        v6 = &teamCounts[TeamNumber];
        if ( v4->IsAlive(this: v4) )
        {
          ++v6->totalAlivePlayers;
        }
        else
        {
          ++v6->totalDeadPlayers;
          if ( LODWORD(v4[1].m_flPrevAnimTime) == 3 )
          {
            ++v6->unenteredPlayers;
          }
          else if ( LOBYTE(v4[1].m_hMyWeapons.m_Value[18].m_Index) != 0 )
          {
            ++v6->suicidedPlayers;
          }
          else
          {
            ++v6->killedPlayers;
          }
        }
      }
    }
    v2 = i + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10270500
// Name: public: bool CCSGameRules::IsThereABomber(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSGameRules::IsThereABomber(CCSGameRules *this)
{
  int v1; // edi
  CCSPlayer *v2; // eax
  CCSPlayer *v3; // esi
  edict_t *m_pPev; // eax

  v1 = 1;
  if ( gpGlobals->maxClients < 1 )
    return 0;
  while ( 1 )
  {
    v2 = CCSPlayer::Instance(iEnt: v1);
    v3 = v2;
    if ( v2 != nullptr )
    {
      m_pPev = v2->m_Network.m_pPev;
      if ( m_pPev != nullptr
        && m_pPev - gpGlobals->pEdicts != 0
        && CBaseEntity::GetTeamNumber(this: v3) != 3
        && CCSPlayer::HasC4(this: v3) )
      {
        break;
      }
    }
    if ( ++v1 > gpGlobals->maxClients )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10270570
// Name: public: void CCSGameRules::UploadGameStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::UploadGameStats(CCSGameRules *this)
{
  const char *pszValue; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  ConVar *v5; // eax
  ConVar *m_pParent; // eax
  __int16 v7; // cx
  const char *v8; // eax
  cs_gamestats_t stats; // [esp+0h] [ebp-E4h] BYREF

  g_flGameStatsUpdateTime = g_flGameStatsUpdateTime - gpGlobals->curtime;
  if ( g_flGameStatsUpdateTime <= 0.0 && this->m_bBlackMarket.m_Value && !this->m_bDontUploadStats )
  {
    if ( DataHasChanged() == 1 )
    {
      memset(dst: (int)&stats, value: nullptr, count: sizeof(stats));
      stats.header.iVersion = 3;
      V_strncpy(pDest: stats.header.szGameName, pSrc: "cstrike15", maxLen: 8);
      pszValue = gpGlobals->mapname.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      V_strncpy(pDest: stats.header.szMapName, pSrc: pszValue, maxLen: 32);
      v2 = ((int (__thiscall *)(ICvar *, const char *, _DWORD))cvar->FindVar_2)(
             a1: cvar,
             a2: "hostip",
             a3: *(_DWORD *)stats.header.szGameName);
      if ( v2 != 0 )
      {
        v3 = *(_DWORD *)(v2 + 28);
        if ( v3 != 0 )
          v4 = *(_DWORD *)(v3 + 48);
        else
          v4 = 0;
        stats.header.ipAddr[0] = HIBYTE(v4);
        stats.header.ipAddr[1] = BYTE2(v4);
        stats.header.ipAddr[2] = BYTE1(v4);
        stats.header.ipAddr[3] = v4;
      }
      v5 = cvar->FindVar_2(this: cvar, a2: "hostip");
      if ( v5 != nullptr )
      {
        m_pParent = v5->m_pParent;
        if ( m_pParent != nullptr )
          stats.header.port = m_pParent->m_Value.m_nValue;
        else
          stats.header.port = 0;
      }
      stats.header.serverid = 0;
      v7 = (int)(float)(gpGlobals->curtime * 0.016666668);
      if ( v7 < 0 )
        v7 = 0;
      stats.iMinutesPlayed = v7;
      qmemcpy(stats.iTerroristVictories, g_iTerroristVictories, sizeof(stats.iTerroristVictories));
      qmemcpy(stats.iCounterTVictories, g_iCounterTVictories, sizeof(stats.iCounterTVictories));
      qmemcpy(stats.iBlackMarketPurchases, g_iWeaponPurchases, sizeof(stats.iBlackMarketPurchases));
      stats.iAutoBuyPurchases = g_iAutoBuyPurchases;
      stats.iReBuyPurchases = g_iReBuyPurchases;
      stats.iAutoBuyM4A1Purchases = g_iAutoBuyM4A1Purchases;
      stats.iAutoBuyAK47Purchases = g_iAutoBuyAK47Purchases;
      stats.iAutoBuyFamasPurchases = g_iAutoBuyFamasPurchases;
      stats.iAutoBuyGalilPurchases = g_iAutoBuyGalilPurchases;
      stats.iAutoBuyVestHelmPurchases = g_iAutoBuyVestHelmPurchases;
      stats.iAutoBuyVestPurchases = g_iAutoBuyVestPurchases;
      if ( gamestatsuploader != nullptr )
      {
        v8 = gpGlobals->mapname.pszValue;
        if ( v8 == nullptr )
          v8 = locale;
        ((void (__stdcall *)(const char *, int, int, cs_gamestats_t *))gamestatsuploader->UploadGameStats)(
          a1: v8,
          a2: 3,
          a3: 228,
          a4: &stats);
      }
      memset(dst: (int)g_iWeaponPurchases, value: nullptr, count: sizeof(g_iWeaponPurchases));
      *(_QWORD *)g_iTerroristVictories = 0;
      *(_QWORD *)&g_iTerroristVictories[4] = 0;
      *(_QWORD *)&g_iTerroristVictories[8] = 0;
      *(_QWORD *)&g_iTerroristVictories[12] = 0;
      *(_DWORD *)&g_iTerroristVictories[16] = 0;
      *(_QWORD *)g_iCounterTVictories = 0;
      *(_QWORD *)&g_iCounterTVictories[4] = 0;
      *(_QWORD *)&g_iCounterTVictories[8] = 0;
      *(_QWORD *)&g_iCounterTVictories[12] = 0;
      *(_DWORD *)&g_iCounterTVictories[16] = 0;
      g_iAutoBuyPurchases = 0;
      g_iReBuyPurchases = 0;
      g_iAutoBuyM4A1Purchases = 0;
      g_iAutoBuyAK47Purchases = 0;
      g_iAutoBuyFamasPurchases = 0;
      g_iAutoBuyGalilPurchases = 0;
      g_iAutoBuyVestHelmPurchases = 0;
      g_iAutoBuyVestPurchases = 0;
    }
    g_flGameStatsUpdateTime = 79200.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102708D0
// Name: public: float CCSGameRules::GetMapRemainingTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCSGameRules::GetMapRemainingTime(CCSGameRules *this)
{
  char *m_pszString; // eax
  char *v3; // eax
  int m_nValue; // eax
  float flTimeLeft; // [esp+4h] [ebp-4h]

  if ( (nextlevel.m_nFlags & 0x1000) != 0 )
    goto LABEL_5;
  m_pszString = nextlevel.m_pParent->m_Value.m_pszString;
  if ( m_pszString != nullptr && *m_pszString != 0 )
  {
    if ( (nextlevel.m_nFlags & 0x1000) != 0 )
    {
LABEL_5:
      v3 = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      v3 = nextlevel.m_pParent->m_Value.m_pszString;
      if ( v3 == nullptr )
        v3 = (char *)locale;
    }
    if ( engine->IsMapValid(this: engine, a2: v3) != 0 )
      return 0.0;
  }
  if ( mp_timelimit.m_pParent == nullptr )
    return -1.0;
  m_nValue = mp_timelimit.m_pParent->m_Value.m_nValue;
  if ( m_nValue <= 0 )
    return -1.0;
  flTimeLeft = (float)((float)(60 * m_nValue) + this->m_flGameStartTime.m_Value) - gpGlobals->curtime;
  if ( flTimeLeft < 0.0 )
    return 0.0;
  return flTimeLeft;
}

//------------------------------------------------------------------------------
// Address: 0x10270990
// Name: public: float CCSGameRules::GetRoundRemainingTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCSGameRules::GetRoundRemainingTime(CCSGameRules *this)
{
  return (double)this->m_iRoundTime.m_Value + this->m_fRoundStartTime.m_Value - gpGlobals->curtime;
}

//------------------------------------------------------------------------------
// Address: 0x102709B0
// Name: public: float CCSGameRules::GetRoundStartTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCSGameRules::GetRoundStartTime(CCSGameRules *this)
{
  return this->m_fRoundStartTime.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x102709C0
// Name: public: float CCSGameRules::GetRoundElapsedTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCSGameRules::GetRoundElapsedTime(CCSGameRules *this)
{
  return gpGlobals->curtime - this->m_fRoundStartTime.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x102709D0
// Name: public: virtual bool CCSGameRules::ShouldCollide(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSGameRules::ShouldCollide(CCSGameRules *this, int collisionGroup0, int collisionGroup1)
{
  int v3; // eax
  int v4; // edx

  v3 = collisionGroup0;
  v4 = collisionGroup1;
  if ( collisionGroup0 > collisionGroup1 )
  {
    v3 = collisionGroup1;
    v4 = collisionGroup0;
  }
  if ( v3 == 8 )
  {
    if ( v4 == 11 )
    {
LABEL_5:
      LOBYTE(v3) = 0;
      return v3;
    }
  }
  else if ( v3 != 5 )
  {
    goto LABEL_8;
  }
  if ( v4 == 17 )
    goto LABEL_5;
LABEL_8:
  if ( v3 != 1 || v4 != 17 )
    LOBYTE(v3) = CGameRules::ShouldCollide(this, collisionGroup0: v3, collisionGroup1: v4);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10270A20
// Name: public: bool CCSGameRules::IsFreezePeriod(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSGameRules::IsFreezePeriod(CCSGameRules *this)
{
  return this->m_bFreezePeriod.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x10270A30
// Name: public: bool CCSGameRules::IsBombDefuseMap(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSGameRules::IsBombDefuseMap(CCSGameRules *this)
{
  return this->m_bMapHasBombTarget.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x10270A40
// Name: public: bool CCSGameRules::IsLogoMap(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSGameRules::IsLogoMap(CCSGameRules *this)
{
  return this->m_bLogoMap.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x10270A50
// Name: public: bool CCSGameRules::IsBuyTimeElapsed(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCSGameRules::IsBuyTimeElapsed(CCSGameRules *this)
{
  return (float)(gpGlobals->curtime - this->m_fRoundStartTime.m_Value) > mp_buytime.m_pParent->m_Value.m_fValue;
}

//------------------------------------------------------------------------------
// Address: 0x10270A80
// Name: class CCSAmmoDef __near * GetCSAmmoDef(void)
// Source: json
//------------------------------------------------------------------------------
CCSAmmoDef *__cdecl GetCSAmmoDef()
{
  GetAmmoDef();
  return &ammoDef;
}

//------------------------------------------------------------------------------
// Address: 0x10270A90
// Name: public: virtual char const __near * CCSGameRules::GetChatPrefix(bool,class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSGameRules::GetChatPrefix(CCSGameRules *this, bool bTeamOnly, CBasePlayer *pPlayer)
{
  const char *v3; // edi

  v3 = nullptr;
  if ( pPlayer == nullptr )
    return locale;
  if ( !bTeamOnly )
  {
    if ( pPlayer->m_lifeState.m_Value != 0 )
    {
      v3 = "*DEAD*";
      if ( CBaseEntity::GetTeamNumber(this: pPlayer) == 1 )
        return "*SPEC*";
      return v3;
    }
    return locale;
  }
  if ( CBaseEntity::GetTeamNumber(this: pPlayer) == 3 )
  {
    if ( pPlayer->m_lifeState.m_Value != 0 )
      return "*DEAD*(Counter-Terrorist)";
    else
      return "(Counter-Terrorist)";
  }
  if ( CBaseEntity::GetTeamNumber(this: pPlayer) != 2 )
  {
    if ( CBaseEntity::GetTeamNumber(this: pPlayer) == 1 )
      return "(Spectator)";
    return v3;
  }
  if ( pPlayer->m_lifeState.m_Value != 0 )
    return "*DEAD*(Terrorist)";
  else
    return "(Terrorist)";
}

//------------------------------------------------------------------------------
// Address: 0x10270B60
// Name: public: virtual char const __near * CCSGameRules::GetChatFormat(bool,class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSGameRules::GetChatFormat(CCSGameRules *this, bool bTeamOnly, CBasePlayer *pPlayer)
{
  const char *v5; // ebx
  const char *v6; // eax
  const char *v7; // eax

  if ( pPlayer == nullptr )
    return nullptr;
  v5 = nullptr;
  if ( !bTeamOnly )
  {
    if ( pPlayer->m_lifeState.m_Value == 0 )
      return "Cstrike_Chat_All";
    v5 = "Cstrike_Chat_AllDead";
    if ( CBaseEntity::GetTeamNumber(this: pPlayer) == 1 )
      return "Cstrike_Chat_AllSpec";
    return v5;
  }
  if ( CBaseEntity::GetTeamNumber(this: pPlayer) == 3 )
  {
    if ( pPlayer->m_lifeState.m_Value != 0 )
      return "Cstrike_Chat_CT_Dead";
    v6 = this->GetChatLocation(this, a2: 1, a3: pPlayer);
    if ( v6 != nullptr && *v6 != 0 )
      return "Cstrike_Chat_CT_Loc";
    else
      return "Cstrike_Chat_CT";
  }
  if ( CBaseEntity::GetTeamNumber(this: pPlayer) != 2 )
  {
    if ( CBaseEntity::GetTeamNumber(this: pPlayer) == 1 )
      return "Cstrike_Chat_Spec";
    return v5;
  }
  if ( pPlayer->m_lifeState.m_Value != 0 )
    return "Cstrike_Chat_T_Dead";
  v7 = this->GetChatLocation(this, a2: 1, a3: pPlayer);
  if ( v7 != nullptr && *v7 != 0 )
    return "Cstrike_Chat_T_Loc";
  else
    return "Cstrike_Chat_T";
}

//------------------------------------------------------------------------------
// Address: 0x10270C80
// Name: public: virtual void CCSGameRules::ClientSettingsChanged(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::ClientSettingsChanged(CCSGameRules *this, CCSPlayer *pPlayer)
{
  edict_t *m_pPev; // eax
  const char *v3; // edi
  const char *v4; // eax
  bool (__thiscall *IsNetClient)(CBaseEntity *); // eax
  edict_t *v6; // eax
  const char *v7; // eax

  m_pPev = pPlayer->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    m_pPev -= (int)gpGlobals->pEdicts;
  v3 = engine->GetClientConVarValue(this: engine, a2: m_pPev, a3: "name");
  v4 = pPlayer->GetPlayerName(this: pPlayer);
  if ( *v4 != 0 && V_strncmp(s1: v4, s2: v3, count: 31) != 0 )
    CCSPlayer::ChangeName(this: pPlayer, pszNewName: v3);
  IsNetClient = pPlayer->IsNetClient;
  pPlayer->m_bShowHints = true;
  if ( IsNetClient(this: pPlayer) )
  {
    v6 = pPlayer->m_Network.m_pPev;
    if ( v6 != nullptr )
      v6 -= (int)gpGlobals->pEdicts;
    v7 = engine->GetClientConVarValue(this: engine, a2: v6, a3: "cl_autohelp");
    if ( v7 != nullptr && atoi(nptr: v7) <= 0 )
      pPlayer->m_bShowHints = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10270D40
// Name: public: int CCSGameRules::GetStartMoney(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSGameRules::GetStartMoney(CCSGameRules *this)
{
  const char *Default; // eax

  if ( this->m_bBlackMarket.m_Value )
  {
    Default = ConVar::GetDefault(this: &mp_startmoney);
    return atoi(nptr: Default);
  }
  else if ( mp_startmoney.m_pParent != nullptr )
  {
    return mp_startmoney.m_pParent->m_Value.m_nValue;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10270D70
// Name: public: bool CCSGameRules::IsPistolRound(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSGameRules::IsPistolRound(CCSGameRules *this)
{
  const char *Default; // eax
  int m_nValue; // eax

  if ( this->m_iTotalRoundsPlayed == 0 )
  {
    if ( this->m_bBlackMarket.m_Value )
    {
      Default = ConVar::GetDefault(this: &mp_startmoney);
      m_nValue = atoi(nptr: Default);
    }
    else
    {
      if ( mp_startmoney.m_pParent == nullptr )
        return 1;
      m_nValue = mp_startmoney.m_pParent->m_Value.m_nValue;
    }
    if ( m_nValue <= 800 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10270DC0
// Name: public: bool CCSGameRules::IsPlayingGunGameProgressive(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCSGameRules::IsPlayingGunGameProgressive(CCSGameRules *this)
{
  return g_pGameTypes->GetCurrentGameType(this: g_pGameTypes) == 1
      && g_pGameTypes->GetCurrentGameMode(this: g_pGameTypes) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10270DF0
// Name: public: bool CCSGameRules::IsPlayingGunGameSelect(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSGameRules::IsPlayingGunGameSelect(CCSGameRules *this)
{
  int result; // eax

  if ( g_pGameTypes->GetCurrentGameType(this: g_pGameTypes) != 1 )
    return 0;
  result = g_pGameTypes->GetCurrentGameMode(this: g_pGameTypes);
  if ( result != 1 )
    return 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10270E20
// Name: public: bool CCSGameRules::IsPlayingGunGameTRBomb(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCSGameRules::IsPlayingGunGameTRBomb(CCSGameRules *this)
{
  return g_pGameTypes->GetCurrentGameType(this: g_pGameTypes) == 1
      && g_pGameTypes->GetCurrentGameMode(this: g_pGameTypes) == 2;
}

//------------------------------------------------------------------------------
// Address: 0x10270E50
// Name: public: int CCSGameRules::GetBlackMarketPriceForWeapon(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSGameRules::GetBlackMarketPriceForWeapon(CCSGameRules *this, int iWeaponID)
{
  const weeklyprice_t *m_pPrices; // esi

  if ( this->m_pPrices == nullptr )
    CCSGameRules::GetBlackMarketPriceList(this);
  m_pPrices = this->m_pPrices;
  if ( m_pPrices != nullptr )
    return m_pPrices->iCurrentPrice[iWeaponID];
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10270E90
// Name: public: int CCSGameRules::GetBlackMarketPreviousPriceForWeapon(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSGameRules::GetBlackMarketPreviousPriceForWeapon(CCSGameRules *this, int iWeaponID)
{
  const weeklyprice_t *m_pPrices; // esi

  if ( this->m_pPrices == nullptr )
    CCSGameRules::GetBlackMarketPriceList(this);
  m_pPrices = this->m_pPrices;
  if ( m_pPrices != nullptr )
    return m_pPrices->iPreviousPrice[iWeaponID];
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10270ED0
// Name: public: int CCSGameRules::GetNumProgressiveGunGameWeapons(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSGameRules::GetNumProgressiveGunGameWeapons(CCSGameRules *this, int nTeamID)
{
  if ( nTeamID == 3 )
    return this->m_iNumGunGameProgressiveWeaponsCT.m_Value;
  else
    return this->m_iNumGunGameProgressiveWeaponsT.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x10271320
// Name: int UTIL_HumansInGame(bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl UTIL_HumansInGame(bool ignoreSpectators)
{
  int v1; // edi
  int i; // ebx
  CCSPlayer *v3; // eax
  CBaseEntity *v4; // esi
  edict_t *m_pPev; // eax
  const char *v6; // eax

  v1 = 1;
  for ( i = 0; v1 <= gpGlobals->maxClients; ++v1 )
  {
    v3 = CCSPlayer::Instance(iEnt: v1);
    v4 = v3;
    if ( v3 != nullptr )
    {
      m_pPev = v3->m_Network.m_pPev;
      if ( m_pPev != nullptr && m_pPev - gpGlobals->pEdicts != 0 )
      {
        v6 = v4->GetPlayerName(this: v4);
        if ( v6 != locale
          && _V_stricmp(s1: v6, s2: locale) != 0
          && (v4->m_fFlags.m_Value & 0x200) == 0
          && (!ignoreSpectators
           || (CBaseEntity::GetTeamNumber(this: v4) == 2 || CBaseEntity::GetTeamNumber(this: v4) == 3)
           && LODWORD(v4[5].m_OnUser1.m_Value.vecVal[1]) != 3) )
        {
          ++i;
        }
      }
    }
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x102713E0
// Name: public: virtual void CCSGameRules::RadiusDamage(class CTakeDamageInfo const __near &,class Vector const __near &,float,int,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSGameRules::RadiusDamage(
        CCSGameRules *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        const CTakeDamageInfo *info,
        const Vector *vecSrcIn,
        float flRadius,
        int iClassIgnore,
        CBaseEntity *pEntityIgnore)
{
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  CCSGameRules::RadiusDamage(
    this,
    a2: COERCE_FLOAT(&savedregs),
    a3: a2,
    a4: a3,
    info,
    vecSrcIn,
    flRadius,
    iClassIgnore,
    bIgnoreWorld: false);
}

//------------------------------------------------------------------------------
// Address: 0x10271410
// Name: public: virtual void CCSGameRules::DeathNotice(class CBasePlayer __near *,class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::DeathNotice(CCSGameRules *this, CBasePlayer *pVictim, const CTakeDamageInfo *info)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ebx
  const char *v5; // edi
  unsigned int v6; // eax
  CBaseEntity *v7; // eax
  CBasePlayer *DeathScorer; // eax
  CBaseCombatCharacter *v9; // esi
  const char *v10; // eax
  bool v11; // zf
  const char *pszValue; // ebx
  IGameEvent *v13; // esi
  int v14; // eax
  int m_registeredNavTeam; // eax
  int killer_ID; // [esp+Ch] [ebp-8h]
  CCSGameRules *bHeadshot; // [esp+10h] [ebp-4h]

  m_Index = info->m_hInflictor.m_Index;
  m_pEntity = nullptr;
  bHeadshot = this;
  v5 = "world";
  killer_ID = 0;
  if ( m_Index != -1 )
  {
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    else
      m_pEntity = nullptr;
  }
  v6 = info->m_hAttacker.m_Index;
  if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
    v7 = nullptr;
  else
    v7 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
  DeathScorer = CMultiplayRules::GetDeathScorer(this, pKiller: v7, pInflictor: m_pEntity);
  v9 = DeathScorer;
  LOBYTE(bHeadshot) = 0;
  if ( DeathScorer == nullptr )
  {
    pszValue = m_pEntity->m_iClassname.pszValue;
    v11 = pszValue == nullptr;
    v5 = pszValue;
LABEL_17:
    if ( !v11 )
      goto LABEL_19;
    goto LABEL_18;
  }
  killer_ID = engine->GetPlayerUserId(this: engine, a2: DeathScorer->m_Network.m_pPev);
  LOBYTE(bHeadshot) = (info->m_bitsDamageType & 0x40000000) != 0;
  if ( m_pEntity != nullptr )
  {
    if ( m_pEntity != v9 )
    {
      v5 = m_pEntity->m_iClassname.pszValue;
      v11 = v5 == nullptr;
      goto LABEL_17;
    }
    if ( CBaseCombatCharacter::GetActiveWeapon(this: v9) == nullptr )
      goto LABEL_19;
    v10 = CBaseCombatCharacter::GetActiveWeapon(this: v9)->m_iClassname.pszValue;
    if ( v10 != nullptr )
    {
      v5 = v10;
      goto LABEL_19;
    }
LABEL_18:
    v5 = locale;
  }
LABEL_19:
  if ( strncmp(first: v5, last: "weapon_", count: 7u) == 0 )
  {
    v5 += 7;
  }
  else if ( strncmp(first: v5, last: "NPC_", count: 8u) == 0 )
  {
    v5 += 8;
  }
  else if ( strncmp(first: v5, last: "func_", count: 5u) == 0 )
  {
    v5 += 5;
  }
  else if ( strncmp(first: v5, last: "hegrenade", count: 9u) == 0 )
  {
    v5 = "hegrenade";
  }
  else if ( strncmp(first: v5, last: "flashbang", count: 9u) == 0 )
  {
    v5 = "flashbang";
  }
  v13 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_death", a3: 0, a4: 0);
  if ( v13 != nullptr )
  {
    v14 = engine->GetPlayerUserId(this: engine, a2: pVictim->m_Network.m_pPev);
    v13->SetInt(this: v13, a2: "userid", a3: v14);
    v13->SetInt(this: v13, a2: "attacker", a3: killer_ID);
    v13->SetString(this: v13, a2: "weapon", a3: v5);
    v13->SetBool(this: v13, a2: "headshot", a3: (bool)bHeadshot);
    v13->SetInt(this: v13, a2: "priority", a3: ((_BYTE)bHeadshot != 0) + 7);
    v13->SetInt(this: v13, a2: "penetrated", a3: info->m_iObjectsPenetrated);
    m_registeredNavTeam = pVictim[1].m_registeredNavTeam;
    if ( (m_registeredNavTeam & 1) != 0 )
    {
      v13->SetInt(this: v13, a2: "dominated", a3: 1);
    }
    else if ( (m_registeredNavTeam & 2) != 0 )
    {
      v13->SetInt(this: v13, a2: "revenge", a3: 1);
    }
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v13, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10271650
// Name: public: virtual void CCSGameRules::PlayerKilled(class CBasePlayer __near *,class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::PlayerKilled(CCSGameRules *this, CCSPlayer *pVictim, const CTakeDamageInfo *info)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // esi
  unsigned int v6; // eax
  CCSPlayer *DeathScorer; // esi
  unsigned int v8; // eax
  CBaseEntity *v9; // ecx
  const char *pszValue; // eax
  int m_nValue; // eax
  int v12; // eax
  IVEngineServer_vtbl *v13; // edi
  char *v14; // eax
  int v15; // eax
  IVEngineServer_vtbl *v16; // edi
  int UserID; // eax
  char *v18; // eax
  unsigned int v19; // eax
  int v20; // eax
  unsigned int m_iDisplayHistoryBits; // eax
  const char *v22; // [esp-8h] [ebp-60h]
  char strTeamKills[64]; // [esp+10h] [ebp-48h] BYREF
  int iDeathFlags; // [esp+50h] [ebp-8h] BYREF
  CBaseEntity *pKiller; // [esp+54h] [ebp-4h]

  m_Index = info->m_hInflictor.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v6 = info->m_hAttacker.m_Index;
  if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
    pKiller = nullptr;
  else
    pKiller = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
  DeathScorer = (CCSPlayer *)CMultiplayRules::GetDeathScorer(this, pKiller, pInflictor: m_pEntity);
  if ( CBaseEntity::GetTeamNumber(this: pVictim) == 2 )
  {
    this->m_bNoTerroristsKilled = false;
    this->m_bNoTerroristsDamaged = false;
  }
  if ( CBaseEntity::GetTeamNumber(this: pVictim) == 3 )
  {
    this->m_bNoCTsKilled = false;
    this->m_bNoCTsDamaged = false;
  }
  this->m_bCanDonateWeapons = false;
  v8 = this->m_pFirstKill.m_Index;
  if ( (v8 == -1
     || g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber != HIWORD(v8)
     || g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_pEntity == nullptr)
    && DeathScorer != pVictim )
  {
    if ( DeathScorer != nullptr )
      this->m_pFirstKill.m_Index = DeathScorer->GetRefEHandle(this: DeathScorer)->m_Index;
    else
      this->m_pFirstKill.m_Index = -1;
    this->m_firstKillTime = gpGlobals->curtime - this->m_fRoundStartTime.m_Value;
  }
  iDeathFlags = 0;
  if ( DeathScorer != nullptr )
  {
    CCSGameStats::CalculateOverkill(this: &CCS_GameStats, pAttacker: DeathScorer, pVictim);
    CCSGameStats::CalcDominationAndRevenge(
      this: &CCS_GameStats,
      pAttacker: DeathScorer,
      pVictim,
      piDeathFlags: &iDeathFlags);
  }
  v9 = pKiller;
  pVictim->m_iDeathFlags = iDeathFlags;
  pszValue = v9->m_iClassname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  if ( _V_strcmp(s1: pszValue, s2: "planted_c4") != 0 )
  {
    if ( pVictim == DeathScorer )
    {
      if ( contributionscore_suicide.m_pParent != nullptr )
        m_nValue = contributionscore_suicide.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      pVictim->m_iContributionScore += m_nValue;
    }
    CTeamplayRules::PlayerKilled(this, pVictim, info);
  }
  else
  {
    FireTargets(targetName: "game_playerdie", pActivator: pVictim, pCaller: pVictim, useType: USE_TOGGLE, value: 0.0);
  }
  if ( DeathScorer != nullptr )
  {
    if ( this->IPointsForKill(this, a2: DeathScorer, a3: pVictim) >= 0 )
    {
      if ( DeathScorer != pVictim )
      {
        if ( CCSPlayer::IsVIP(this: pVictim) )
        {
          CCSPlayer::HintMessage(
            this: DeathScorer,
            pMessage: "#SFUI_Notice_Hint_reward_for_killing_vip",
            bDisplayIfDead: true,
            bOverrideClientSettings: false);
          CCSPlayer::AddAccount(
            this: DeathScorer,
            reason: CASH_AWARD_KILLED_VIP,
            bTrackChange: true,
            bItemBought: false);
        }
        else
        {
          CCSPlayer::AddAccount(
            this: DeathScorer,
            reason: CASH_AWARD_KILLED_ENEMY,
            bTrackChange: true,
            bItemBought: false);
        }
      }
      m_iDisplayHistoryBits = DeathScorer->m_iDisplayHistoryBits;
      if ( (m_iDisplayHistoryBits & 0x800) == 0 )
      {
        v20 = m_iDisplayHistoryBits | 0x800;
        v22 = "#SFUI_Notice_Hint_win_round_by_killing_enemy";
        goto LABEL_51;
      }
    }
    else
    {
      CCSPlayer::AddAccount(this: DeathScorer, reason: CASH_AWARD_KILL_TEAMMATE, bTrackChange: true, bItemBought: false);
      ++DeathScorer->m_iTeamKills;
      DeathScorer->m_bJustKilledTeammate = true;
      ClientPrint(
        player: DeathScorer,
        msg_dest: 4,
        msg_name: "#SFUI_Notice_Killed_Teammate",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      if ( mp_autokick.m_pParent != nullptr && mp_autokick.m_pParent->m_Value.m_nValue != 0 )
      {
        V_snprintf(pDest: strTeamKills, maxLen: 64, pFormat: "%d", DeathScorer->m_iTeamKills);
        ClientPrint(
          player: DeathScorer,
          msg_dest: 2,
          msg_name: "#SFUI_Notice_Game_teammate_kills",
          param1: strTeamKills,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
        if ( DeathScorer->m_iTeamKills < 3 )
        {
          if ( mp_spawnprotectiontime.m_pParent != nullptr )
          {
            v15 = mp_spawnprotectiontime.m_pParent->m_Value.m_nValue;
            if ( v15 > 0 && (float)v15 > (float)(gpGlobals->curtime - this->m_fRoundStartTime.m_Value) )
            {
              ClientPrint(
                player: DeathScorer,
                msg_dest: 2,
                msg_name: "#SFUI_Notice_Banned_For_Killing_Teammates",
                param1: nullptr,
                param2: nullptr,
                param3: nullptr,
                param4: nullptr);
              v16 = engine->__vftable;
              UserID = CBasePlayer::GetUserID(this: DeathScorer);
              v18 = UTIL_VarArgs(format: "kickid %d\n", UserID);
              v16->ServerCommand(this: engine, a2: v18);
            }
          }
        }
        else
        {
          ClientPrint(
            player: DeathScorer,
            msg_dest: 2,
            msg_name: "#SFUI_Notice_Banned_For_Killing_Teammates",
            param1: nullptr,
            param2: nullptr,
            param3: nullptr,
            param4: nullptr);
          v12 = engine->GetPlayerUserId(this: engine, a2: DeathScorer->m_Network.m_pPev);
          v13 = engine->__vftable;
          v14 = UTIL_VarArgs(format: "kickid %d\n", v12);
          v13->ServerCommand(this: engine, a2: v14);
        }
      }
      v19 = DeathScorer->m_iDisplayHistoryBits;
      if ( (v19 & 0x400) == 0 )
      {
        v20 = v19 | 0x400;
        v22 = "#SFUI_Notice_Hint_careful_around_teammates";
LABEL_51:
        DeathScorer->m_iDisplayHistoryBits = v20;
        CCSPlayer::HintMessage(this: DeathScorer, pMessage: v22, bDisplayIfDead: false, bOverrideClientSettings: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102719F0
// Name: public: virtual float CCSGameRules::FlPlayerFallDamage(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCSGameRules::FlPlayerFallDamage(CCSGameRules *this, CBasePlayer *pPlayer)
{
  IGameEvent *v3; // esi
  int v4; // eax
  float fallDamage; // [esp+2Ch] [ebp+8h]

  fallDamage = (float)((float)(pPlayer->m_Local.m_flFallVelocity.m_Value - 580.0) * 0.1923077) * 1.25;
  if ( fallDamage <= 0.0 )
    return fallDamage;
  v3 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_falldamage", a3: 0, a4: 0);
  if ( v3 != nullptr )
  {
    v4 = engine->GetPlayerUserId(this: engine, a2: pPlayer->m_Network.m_pPev);
    v3->SetInt(this: v3, a2: "userid", a3: v4);
    v3->SetFloat(this: v3, a2: "damage", a3: COERCE_FLOAT(LODWORD(fallDamage)));
    v3->SetInt(this: v3, a2: "priority", a3: 4);
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v3, a3: false);
  }
  return fallDamage;
}

//------------------------------------------------------------------------------
// Address: 0x10271AB0
// Name: public: void CCSGameRules::GiveC4ToRandomPlayer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::GiveC4ToRandomPlayer(CCSGameRules *this)
{
  int v1; // ebx
  int v2; // edi
  CBasePlayer *v3; // eax
  CBasePlayer *v4; // esi
  CBaseEntity *v5; // eax
  CBaseEntity *v6; // esi
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  CBaseCombatWeapon *(__thiscall *MyCombatWeaponPointer)(CBaseEntity *); // edx
  int v10; // eax
  int m_nValue; // eax
  BOOL v12; // esi
  int v13; // edi
  int v14; // eax
  int v15; // ecx
  CBasePlayer *v16; // eax
  CBasePlayer *v17; // esi
  CBasePlayer *v18; // esi
  const CBaseHandle *v19; // eax
  CCSGameRules *v20; // edi
  int iTerrorists[2][64]; // [esp+Ch] [ebp-214h]
  int lastBombGuyIndex[2]; // [esp+20Ch] [ebp-14h]
  CCSGameRules *v23; // [esp+214h] [ebp-Ch]
  int numAliveTs[2]; // [esp+218h] [ebp-8h]

  v1 = 0;
  lastBombGuyIndex[0] = -1;
  lastBombGuyIndex[1] = -1;
  v2 = 1;
  v23 = this;
  numAliveTs[0] = 0;
  numAliveTs[1] = 0;
  if ( gpGlobals->maxClients >= 1 )
  {
    do
    {
      v3 = UTIL_PlayerByIndex(playerIndex: v2);
      v4 = v3;
      if ( v3 != nullptr && v3->IsPlayer(this: v3) )
      {
        v5 = (CBaseEntity *)__RTDynamicCast(
                              inptr: v4,
                              VfDelta: 0,
                              SrcType: &CBaseEntity `RTTI Type Descriptor',
                              TargetType: &CCSPlayer `RTTI Type Descriptor',
                              isReference: 0);
        v6 = v5;
        if ( v5 != nullptr && v5->IsAlive(this: v5) && CBaseEntity::GetTeamNumber(this: v6) == 2 && v1 < 64 )
        {
          m_Index = v23->m_pLastBombGuy.m_Index;
          if ( m_Index == -1
            || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
          {
            m_pEntity = nullptr;
          }
          else
          {
            m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
          }
          if ( v6 == m_pEntity )
          {
            lastBombGuyIndex[0] = v1;
            lastBombGuyIndex[1] = numAliveTs[1];
          }
          MyCombatWeaponPointer = v6->__vftable[2].MyCombatWeaponPointer;
          iTerrorists[0][v1++] = v2;
          if ( (unsigned __int8)MyCombatWeaponPointer(this: v6) == 0 )
          {
            v10 = numAliveTs[1];
            iTerrorists[1][numAliveTs[1]] = v2;
            numAliveTs[1] = v10 + 1;
          }
        }
      }
      ++v2;
    }
    while ( v2 <= gpGlobals->maxClients );
    numAliveTs[0] = v1;
  }
  if ( cv_bot_defer_to_human.m_pParent != nullptr )
    m_nValue = cv_bot_defer_to_human.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v12 = m_nValue != 0;
  if ( numAliveTs[1] == 0 )
    v12 = false;
  v13 = numAliveTs[v12];
  if ( v13 <= 0 )
  {
    v23->m_bBombDropped = false;
  }
  else
  {
    v14 = random->RandomInt(this: random, a2: 0, a3: v13 - 1);
    v15 = lastBombGuyIndex[v12];
    if ( v15 >= 0 )
      v14 = (v15 + 1) % v13;
    v16 = UTIL_PlayerByIndex(playerIndex: iTerrorists[v12][v14]);
    v17 = v16;
    if ( v16 != nullptr && v16->IsPlayer(this: v16) )
      v18 = (CBasePlayer *)__RTDynamicCast(
                             inptr: v17,
                             VfDelta: 0,
                             SrcType: &CBaseEntity `RTTI Type Descriptor',
                             TargetType: &CCSPlayer `RTTI Type Descriptor',
                             isReference: 0);
    else
      v18 = nullptr;
    ((void (__thiscall *)(CBasePlayer *, const char *, _DWORD))v18->__vftable[1].GetAIAddOn)(
      a1: v18,
      a2: "weapon_c4",
      a3: 0);
    v19 = v18->GetRefEHandle(this: v18);
    v20 = v23;
    v23->m_pLastBombGuy = (CHandle<CCSPlayer>)v19->m_Index;
    ClientPrint(
      player: v18,
      msg_dest: 4,
      msg_name: "#SFUI_Notice_Have_Bomb",
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
    v20->m_bBombDropped = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10271CC0
// Name: public: void CCSGameRules::GiveDefuserToRandomPlayer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::GiveDefuserToRandomPlayer(CCSGameRules *this)
{
  CGlobalVars *v1; // eax
  int v2; // ecx
  int v3; // edi
  CBasePlayer *v4; // esi
  CBaseEntity *v5; // esi
  int v6; // eax
  int v7; // edi
  int v8; // ebx
  CBasePlayer *v9; // esi
  CBaseEntity *v10; // esi
  int v11; // edi
  int v12; // ebx
  CBasePlayer *v13; // eax
  CBasePlayer *v14; // esi
  CCSPlayer *v15; // esi
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  CBasePlayer *v18; // esi
  const CBaseHandle *v19; // eax
  int iCandidates[64]; // [esp+Ch] [ebp-108h]
  CCSGameRules *v21; // [esp+10Ch] [ebp-8h]
  int iHumanCandidates; // [esp+110h] [ebp-4h]

  v1 = gpGlobals;
  v21 = this;
  v2 = 0;
  v3 = 1;
  iHumanCandidates = 0;
  if ( gpGlobals->maxClients >= 1 )
  {
    do
    {
      v4 = UTIL_PlayerByIndex(playerIndex: v3);
      if ( v4 != nullptr && v4->IsPlayer(this: v4) )
      {
        v5 = (CBaseEntity *)__RTDynamicCast(
                              inptr: v4,
                              VfDelta: 0,
                              SrcType: &CBaseEntity `RTTI Type Descriptor',
                              TargetType: &CCSPlayer `RTTI Type Descriptor',
                              isReference: 0);
        if ( v5 != nullptr
          && v5->IsAlive(this: v5)
          && CBaseEntity::GetTeamNumber(this: v5) == 3
          && v5->__vftable[2].MyCombatWeaponPointer(this: v5) == nullptr )
        {
          v6 = iHumanCandidates;
          iCandidates[iHumanCandidates] = v3;
          iHumanCandidates = v6 + 1;
        }
      }
      v1 = gpGlobals;
      ++v3;
    }
    while ( v3 <= gpGlobals->maxClients );
    v2 = iHumanCandidates;
  }
  v7 = 1;
  v8 = v2;
  if ( v1->maxClients >= 1 )
  {
    do
    {
      v9 = UTIL_PlayerByIndex(playerIndex: v7);
      if ( v9 != nullptr && v9->IsPlayer(this: v9) )
      {
        v10 = (CBaseEntity *)__RTDynamicCast(
                               inptr: v9,
                               VfDelta: 0,
                               SrcType: &CBaseEntity `RTTI Type Descriptor',
                               TargetType: &CCSPlayer `RTTI Type Descriptor',
                               isReference: 0);
        if ( v10 != nullptr
          && v10->IsAlive(this: v10)
          && CBaseEntity::GetTeamNumber(this: v10) == 3
          && v10->__vftable[2].MyCombatWeaponPointer(this: v10) != nullptr )
        {
          iCandidates[v8++] = v7;
        }
      }
      ++v7;
    }
    while ( v7 <= gpGlobals->maxClients );
    v2 = iHumanCandidates;
  }
  if ( cv_bot_defer_to_human.m_pParent == nullptr
    || cv_bot_defer_to_human.m_pParent->m_Value.m_nValue == 0
    || (v11 = v2, v2 <= 0) )
  {
    v11 = v8;
  }
  if ( v11 > 0 )
  {
    v12 = random->RandomInt(this: random, a2: 0, a3: v11 - 1);
    v13 = UTIL_PlayerByIndex(playerIndex: iCandidates[v12]);
    v14 = v13;
    if ( v13 != nullptr && v13->IsPlayer(this: v13) )
      v15 = (CCSPlayer *)__RTDynamicCast(
                           inptr: v14,
                           VfDelta: 0,
                           SrcType: &CBaseEntity `RTTI Type Descriptor',
                           TargetType: &CCSPlayer `RTTI Type Descriptor',
                           isReference: 0);
    else
      v15 = nullptr;
    m_Index = v21->m_pLastDefuserGuy.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( v15 == m_pEntity )
    {
      v18 = UTIL_PlayerByIndex(playerIndex: iCandidates[(v12 + 1) % v11]);
      if ( v18 != nullptr && v18->IsPlayer(this: v18) )
        v15 = (CCSPlayer *)__RTDynamicCast(
                             inptr: v18,
                             VfDelta: 0,
                             SrcType: &CBaseEntity `RTTI Type Descriptor',
                             TargetType: &CCSPlayer `RTTI Type Descriptor',
                             isReference: 0);
      else
        v15 = nullptr;
    }
    CCSPlayer::GiveDefuser(this: v15, bPickedUp: false);
    if ( v15 != nullptr )
    {
      v19 = v15->GetRefEHandle(this: v15);
      v21->m_pLastDefuserGuy = (CHandle<CCSPlayer>)v19->m_Index;
    }
    else
    {
      v21->m_pLastDefuserGuy.m_Index = -1;
    }
    CCSPlayer::HintMessage(
      this: v15,
      pMessage: "#Hint_you_have_the_defuser",
      bDisplayIfDead: false,
      bOverrideClientSettings: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10271F50
// Name: public: bool CCSGameRules::CheckFragLimit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSGameRules::CheckFragLimit(CCSGameRules *this)
{
  int v2; // edi
  CBasePlayer *v3; // esi
  int v4; // eax
  const char *v5; // ebx
  CTeam *Team; // eax
  int v7; // edi
  char *NetworkIDString; // eax
  const char *v9; // eax
  int v10; // [esp-18h] [ebp-1Ch]
  const char *v11; // [esp-14h] [ebp-18h]
  const char *v12; // [esp-10h] [ebp-14h]

  if ( fraglimit.m_pParent == nullptr || fraglimit.m_pParent->m_Value.m_nValue <= 0 )
    return 0;
  v2 = 1;
  if ( gpGlobals->maxClients < 1 )
    return 0;
  while ( 1 )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: v2);
    if ( v3 != nullptr )
    {
      v4 = fraglimit.m_pParent != nullptr ? fraglimit.m_pParent->m_Value.m_nValue : 0;
      if ( v3->m_iFrags >= v4 )
        break;
    }
    if ( ++v2 > gpGlobals->maxClients )
      return 0;
  }
  v5 = "UNKNOWN";
  if ( CBaseEntity::GetTeam(this: v3) != nullptr )
  {
    Team = CBaseEntity::GetTeam(this: v3);
    v5 = Team->GetName(this: Team);
  }
  v7 = engine->GetPlayerUserId(this: engine, a2: v3->m_Network.m_pPev);
  NetworkIDString = CBasePlayer::GetNetworkIDString(this: v3);
  v9 = (const char *)((int (__thiscall *)(CBasePlayer *, int, char *, const char *))v3->GetPlayerName)(
                       a1: v3,
                       a2: v7,
                       a3: NetworkIDString,
                       a4: v5);
  UTIL_LogPrintf(fmt: "\"%s<%i><%s><%s>\" triggered \"Intermission_Kill_Limit\"\n", v9, v10, v11, v12);
  this->GoToIntermission(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10272030
// Name: protected: void CCSGameRules::UpdateMatchStats(class CCSPlayer __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::UpdateMatchStats(CCSGameRules *this, CCSPlayer *pPlayer, int winnerIndex)
{
  const char *pszValue; // eax
  int CSLevelIndex; // eax
  CSStatType_t v6; // eax

  if ( CBaseEntity::GetTeamNumber(this: pPlayer) == winnerIndex )
  {
    CCSGameStats::IncrementStat(
      this: &CCS_GameStats,
      pPlayer,
      statId: CSSTAT_MATCHES_WON,
      iDelta: 1,
      bPlayerOnly: false);
    if ( g_pGameTypes->GetCurrentGameType(this: g_pGameTypes) == 1 )
    {
      if ( g_pGameTypes->GetCurrentGameType(this: g_pGameTypes) == 1
        && g_pGameTypes->GetCurrentGameMode(this: g_pGameTypes) == 0
        && pPlayer->m_bMadeFinalGunGameProgressiveKill )
      {
        CCSGameStats::IncrementStat(
          this: &CCS_GameStats,
          pPlayer,
          statId: CSSTAT_GUN_GAME_MATCHES_WON,
          iDelta: 1,
          bPlayerOnly: false);
      }
      if ( g_pGameTypes->GetCurrentGameType(this: g_pGameTypes) != 1
        || g_pGameTypes->GetCurrentGameMode(this: g_pGameTypes) != 0 )
      {
        if ( g_pGameTypes->GetCurrentGameType(this: g_pGameTypes) == 1
          && g_pGameTypes->GetCurrentGameMode(this: g_pGameTypes) == 1 )
        {
          CCSGameStats::IncrementStat(
            this: &CCS_GameStats,
            pPlayer,
            statId: CSSTAT_GUN_GAME_SELECT_MATCHES_WON,
            iDelta: 1,
            bPlayerOnly: false);
        }
        else if ( CCSGameRules::IsPlayingGunGameTRBomb(this) )
        {
          CCSGameStats::IncrementStat(
            this: &CCS_GameStats,
            pPlayer,
            statId: CSSTAT_GUN_GAME_TRBOMB_MATCHES_WON,
            iDelta: 1,
            bPlayerOnly: false);
        }
      }
      else
      {
        CCSGameStats::IncrementStat(
          this: &CCS_GameStats,
          pPlayer,
          statId: CSSTAT_GUN_GAME_PROGRESSIVE_MATCHES_WON,
          iDelta: 1,
          bPlayerOnly: false);
        if ( !pPlayer->m_wasKilledThisRound && pPlayer->m_bMadeFinalGunGameProgressiveKill )
          CBaseMultiplayerPlayer::AwardAchievement(this: pPlayer, iAchievement: 6033, iCount: 1);
        if ( !pPlayer->m_hasReloaded )
          CBaseMultiplayerPlayer::AwardAchievement(this: pPlayer, iAchievement: 6038, iCount: 1);
      }
    }
    pszValue = gpGlobals->mapname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    CSLevelIndex = GetCSLevelIndex(pLevelName: pszValue);
    if ( CSLevelIndex != -1 )
    {
      v6 = dword_104D9D44[4 * CSLevelIndex];
      if ( v6 != CSSTAT_UNDEFINED )
        CCSGameStats::IncrementStat(this: &CCS_GameStats, pPlayer, statId: v6, iDelta: 1, bPlayerOnly: false);
    }
  }
  else if ( winnerIndex == 1 )
  {
    CCSGameStats::IncrementStat(
      this: &CCS_GameStats,
      pPlayer,
      statId: CSSTAT_MATCHES_DRAW,
      iDelta: 1,
      bPlayerOnly: false);
  }
  CCSGameStats::IncrementStat(
    this: &CCS_GameStats,
    pPlayer,
    statId: CSSTAT_MATCHES_PLAYED,
    iDelta: 1,
    bPlayerOnly: false);
  if ( g_pGameTypes->GetCurrentGameType(this: g_pGameTypes) == 1 )
    CCSGameStats::IncrementStat(
      this: &CCS_GameStats,
      pPlayer,
      statId: CSSTAT_GUN_GAME_MATCHES_PLAYED,
      iDelta: 1,
      bPlayerOnly: false);
}

//------------------------------------------------------------------------------
// Address: 0x10272200
// Name: public: void CCSGameRules::ScorePlayerDamage(class CCSPlayer __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSGameRules::ScorePlayerDamage(
        CCSGameRules *this@<ecx>,
        float a2@<ebp>,
        CCSPlayer *pPlayer,
        float fDamage)
{
  CNavArea *m_lastNavArea; // eax
  unsigned int m_place; // eax
  int v6; // esi
  int TeamNumber; // eax
  float m_fValue; // xmm3_4
  int v9; // eax
  CPlantedC4 *v10; // esi
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  int v16; // esi
  float v17; // xmm3_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  int v20; // eax
  CHostage *v21; // esi
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm0_4
  int v25; // esi
  CBaseEntity *EntityByClassnameNearest; // eax
  CBaseEntity *v27; // esi
  unsigned int m_Index; // eax
  float v29; // xmm0_4
  float v30; // xmm2_4
  float v31; // xmm0_4
  float v32; // xmm0_4
  int v33; // esi
  CBaseEntity *v34; // eax
  CBaseEntity *v35; // esi
  unsigned int v36; // eax
  float v37; // xmm0_4
  float v38; // xmm2_4
  float v39; // xmm0_4
  int v40; // esi
  unsigned int flRadius; // [esp+0h] [ebp-40h]
  float v42; // [esp+14h] [ebp-2Ch]
  __int64 v43; // [esp+18h] [ebp-28h]
  float z; // [esp+20h] [ebp-20h]
  float bombPos; // [esp+24h] [ebp-1Ch]
  float bombPosa; // [esp+24h] [ebp-1Ch]
  float bombPosb; // [esp+24h] [ebp-1Ch]
  float bombPos_4; // [esp+28h] [ebp-18h]
  int bombPos_4a; // [esp+28h] [ebp-18h]
  float bombPos_4b; // [esp+28h] [ebp-18h]
  float bombPos_4c; // [esp+28h] [ebp-18h]
  int bombPos_8; // [esp+2Ch] [ebp-14h]
  float bombPos_8a; // [esp+2Ch] [ebp-14h]
  float fRadiusInner; // [esp+30h] [ebp-10h]
  float fRadiusInnera; // [esp+30h] [ebp-10h]
  float fRadiusOuter; // [esp+34h] [ebp-Ch] BYREF
  int iBomb; // [esp+38h] [ebp-8h]
  int retaddr; // [esp+40h] [ebp+0h]

  fRadiusOuter = a2;
  iBomb = retaddr;
  CCSPlayer::AddScore(this: pPlayer, iPoints: (int)(float)(score_damage.m_pParent->m_Value.m_fValue * fDamage));
  m_lastNavArea = pPlayer->m_lastNavArea;
  if ( m_lastNavArea != nullptr )
    m_place = m_lastNavArea->m_place;
  else
    m_place = 0;
  if ( m_place != 0 )
  {
    v6 = (int)(float)(score_team_damage_bonus.m_pParent->m_Value.m_fValue * fDamage);
    flRadius = m_place;
    TeamNumber = CBaseEntity::GetTeamNumber(this: pPlayer);
    CCSGameRules::SplitScoreAmongPlayersInZone(
      iPoints: v6,
      iTeam: TeamNumber,
      pExcludePlayer: pPlayer,
      iPlace: flRadius);
  }
  m_fValue = score_planted_bomb_proximity_damage_radius_outer.m_pParent->m_Value.m_fValue;
  bombPos = score_planted_bomb_proximity_damage_radius_inner.m_pParent->m_Value.m_fValue;
  v9 = 0;
  fRadiusInner = m_fValue;
  bombPos_4 = m_fValue * m_fValue;
  for ( bombPos_8 = 0; v9 < g_PlantedC4s.m_Size; bombPos_8 = ++v9 )
  {
    v10 = g_PlantedC4s.m_Memory.m_pMemory[v9];
    if ( v10 != nullptr && v10->m_bBombTicking.m_Value )
    {
      if ( (v10->m_iEFlags & 0x800) != 0 )
      {
        CBaseEntity::CalcAbsolutePosition(this: v10, a2: (int)&fRadiusOuter);
        m_fValue = fRadiusInner;
      }
      v43 = *(_QWORD *)&v10->m_vecAbsOrigin.x;
      z = v10->m_vecAbsOrigin.z;
      if ( (pPlayer->m_iEFlags & 0x800) != 0 )
      {
        CBaseEntity::CalcAbsolutePosition(this: pPlayer, a2: (int)&fRadiusOuter);
        m_fValue = fRadiusInner;
      }
      v11 = pPlayer->m_vecAbsOrigin.x - *(float *)&v43;
      v12 = pPlayer->m_vecAbsOrigin.y - *((float *)&v43 + 1);
      v13 = pPlayer->m_vecAbsOrigin.z - z;
      if ( bombPos_4 > (float)((float)((float)(v12 * v12) + (float)(v11 * v11)) + (float)(v13 * v13)) )
      {
        v14 = fsqrt((float)((float)(v12 * v12) + (float)(v13 * v13)) + (float)(v11 * v11));
        if ( v14 <= bombPos )
          v15 = 1.0;
        else
          v15 = (float)(m_fValue - v14) / (float)(m_fValue - bombPos);
        v16 = (int)(float)(score_planted_bomb_proximity_damage_bonus.m_pParent->m_Value.m_fValue * v15);
        CCSPlayer::AddScore(this: pPlayer, iPoints: v16);
        CCSPlayer::AddRoundProximityScore(this: pPlayer, iPoints: v16);
        break;
      }
      v9 = bombPos_8;
    }
  }
  v17 = score_hostage_proximity_damage_radius_inner.m_pParent->m_Value.m_fValue;
  v18 = score_hostage_proximity_damage_radius_outer.m_pParent->m_Value.m_fValue;
  v19 = 3.4028235e38;
  v20 = 0;
  bombPos_8a = v18;
  fRadiusInnera = 3.4028235e38;
  bombPos_4a = 0;
  if ( g_Hostages.m_Size > 0 )
  {
    do
    {
      v21 = g_Hostages.m_Memory.m_pMemory[v20];
      if ( v21->m_iHealth.m_Value > 0 )
      {
        if ( !CHostage::IsRescued(this: g_Hostages.m_Memory.m_pMemory[v20]) )
        {
          if ( (pPlayer->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this: pPlayer, a2: (int)&fRadiusOuter);
          if ( (v21->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this: v21, a2: (int)&fRadiusOuter);
          v22 = v21->m_vecAbsOrigin.x - pPlayer->m_vecAbsOrigin.x;
          if ( fRadiusInnera > (float)((float)((float)((float)(v21->m_vecAbsOrigin.y - pPlayer->m_vecAbsOrigin.y)
                                                     * (float)(v21->m_vecAbsOrigin.y - pPlayer->m_vecAbsOrigin.y))
                                             + (float)(v22 * v22))
                                     + (float)((float)(v21->m_vecAbsOrigin.z - pPlayer->m_vecAbsOrigin.z)
                                             * (float)(v21->m_vecAbsOrigin.z - pPlayer->m_vecAbsOrigin.z))) )
            fRadiusInnera = (float)((float)((float)(v21->m_vecAbsOrigin.y - pPlayer->m_vecAbsOrigin.y)
                                          * (float)(v21->m_vecAbsOrigin.y - pPlayer->m_vecAbsOrigin.y))
                                  + (float)(v22 * v22))
                          + (float)((float)(v21->m_vecAbsOrigin.z - pPlayer->m_vecAbsOrigin.z)
                                  * (float)(v21->m_vecAbsOrigin.z - pPlayer->m_vecAbsOrigin.z));
        }
        v18 = bombPos_8a;
      }
      v20 = bombPos_4a + 1;
      bombPos_4a = v20;
    }
    while ( v20 < g_Hostages.m_Size );
    v19 = fRadiusInnera;
  }
  if ( (float)(v18 * v18) > v19 )
  {
    v23 = fsqrt(v19);
    if ( v23 <= v17 )
      v24 = 1.0;
    else
      v24 = (float)(v18 - v23) / (float)(v18 - v17);
    v25 = (int)(float)((float)(v24 * fDamage) * score_hostage_proximity_damage_bonus.m_pParent->m_Value.m_fValue);
    CCSPlayer::AddScore(this: pPlayer, iPoints: v25);
    CCSPlayer::AddRoundProximityScore(this: pPlayer, iPoints: v25);
  }
  bombPosa = score_dropped_bomb_proximity_damage_bonus_radius_inner.m_pParent->m_Value.m_fValue;
  bombPos_4b = score_dropped_bomb_proximity_damage_bonus_radius_outer.m_pParent->m_Value.m_fValue;
  if ( (pPlayer->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pPlayer, a2: (int)&fRadiusOuter);
  EntityByClassnameNearest = CGlobalEntityList::FindEntityByClassnameNearest(
                               this: &gEntList,
                               szName: "weapon_c4",
                               vecSrc: &pPlayer->m_vecAbsOrigin,
                               flRadius: bombPos_4b);
  v27 = EntityByClassnameNearest;
  if ( EntityByClassnameNearest != nullptr )
  {
    m_Index = EntityByClassnameNearest->m_hOwnerEntity.m_Value.m_Index;
    if ( m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
    {
      if ( (pPlayer->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: pPlayer, a2: (int)&fRadiusOuter);
      if ( (v27->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v27, a2: (int)&fRadiusOuter);
      v29 = v27->m_vecAbsOrigin.x - pPlayer->m_vecAbsOrigin.x;
      v30 = v27->m_vecAbsOrigin.z - pPlayer->m_vecAbsOrigin.z;
      v31 = fsqrt(
              (float)((float)((float)(v27->m_vecAbsOrigin.y - pPlayer->m_vecAbsOrigin.y)
                            * (float)(v27->m_vecAbsOrigin.y - pPlayer->m_vecAbsOrigin.y))
                    + (float)(v30 * v30))
            + (float)(v29 * v29));
      if ( v31 <= bombPosa )
        v32 = 1.0;
      else
        v32 = (float)(bombPos_4b - v31) / (float)(bombPos_4b - bombPosa);
      v33 = (int)(float)((float)(v32 * fDamage) * score_dropped_bomb_proximity_damage_bonus.m_pParent->m_Value.m_fValue);
      CCSPlayer::AddScore(this: pPlayer, iPoints: v33);
      CCSPlayer::AddRoundProximityScore(this: pPlayer, iPoints: v33);
    }
  }
  bombPosb = score_dropped_defuser_proximity_damage_radius_inner.m_pParent->m_Value.m_fValue;
  bombPos_4c = score_dropped_defuser_proximity_damage_radius_outer.m_pParent->m_Value.m_fValue;
  if ( (pPlayer->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pPlayer, a2: (int)&fRadiusOuter);
  v34 = CGlobalEntityList::FindEntityByClassnameNearest(
          this: &gEntList,
          szName: "item_defuser",
          vecSrc: &pPlayer->m_vecAbsOrigin,
          flRadius: bombPos_4c);
  v35 = v34;
  if ( v34 != nullptr )
  {
    v36 = v34->m_hOwnerEntity.m_Value.m_Index;
    if ( v36 == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)v36].m_SerialNumber != HIWORD(v36)
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)v36].m_pEntity == nullptr )
    {
      if ( (pPlayer->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: pPlayer, a2: (int)&fRadiusOuter);
      if ( (v35->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v35, a2: (int)&fRadiusOuter);
      v37 = v35->m_vecAbsOrigin.x - pPlayer->m_vecAbsOrigin.x;
      v38 = v35->m_vecAbsOrigin.z - pPlayer->m_vecAbsOrigin.z;
      v42 = fsqrt(
              (float)((float)((float)(v35->m_vecAbsOrigin.y - pPlayer->m_vecAbsOrigin.y)
                            * (float)(v35->m_vecAbsOrigin.y - pPlayer->m_vecAbsOrigin.y))
                    + (float)(v38 * v38))
            + (float)(v37 * v37));
      if ( v42 <= bombPosb )
        v39 = 1.0;
      else
        v39 = (float)(bombPos_4c - v42) / (float)(bombPos_4c - bombPosb);
      v40 = (int)(float)((float)(v39 * fDamage)
                       * score_dropped_defuser_proximity_damage_bonus.m_pParent->m_Value.m_fValue);
      CCSPlayer::AddScore(this: pPlayer, iPoints: v40);
      CCSPlayer::AddRoundProximityScore(this: pPlayer, iPoints: v40);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10272840
// Name: public: void CCSGameRules::ScoreBombPlant(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::ScoreBombPlant(CCSGameRules *this, CCSPlayer *pPlayer)
{
  int m_nValue; // eax
  CPlantedC4 *v3; // esi
  int v4; // eax
  float fRangeInner; // [esp+Ch] [ebp-4h]
  int savedregs; // [esp+10h] [ebp+0h] BYREF
  float pPlayera; // [esp+18h] [ebp+8h]

  if ( pPlayer != nullptr )
  {
    if ( contributionscore_bomb_planted.m_pParent != nullptr )
      m_nValue = contributionscore_bomb_planted.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    pPlayer->m_iContributionScore += m_nValue;
  }
  v3 = *g_PlantedC4s.m_Memory.m_pMemory;
  if ( *g_PlantedC4s.m_Memory.m_pMemory != nullptr )
  {
    pPlayera = score_bomb_plant_radius_outer.m_pParent->m_Value.m_fValue;
    fRangeInner = score_bomb_plant_radius_inner.m_pParent->m_Value.m_fValue;
    if ( (v3->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v3, a2: (int)&savedregs);
    if ( score_bomb_plant_bonus.m_pParent != nullptr )
      v4 = score_bomb_plant_bonus.m_pParent->m_Value.m_nValue;
    else
      v4 = 0;
    CCSGameRules::SplitScoreAmongPlayersInRange(
      a1: (int)&savedregs,
      iPoints: v4,
      iTeam: 2,
      pExcludePlayer: nullptr,
      center: &v3->m_vecAbsOrigin,
      fRangeInner,
      fRangeOuter: pPlayera);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102728F0
// Name: public: void CCSGameRules::ScoreBombDefuse(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::ScoreBombDefuse(CCSGameRules *this, CCSPlayer *pPlayer)
{
  int m_nValue; // eax
  CPlantedC4 *v3; // esi
  int v4; // eax
  float fRangeInner; // [esp+Ch] [ebp-4h]
  int savedregs; // [esp+10h] [ebp+0h] BYREF
  float pPlayera; // [esp+18h] [ebp+8h]

  if ( pPlayer != nullptr )
  {
    if ( contributionscore_bomb_defuse.m_pParent != nullptr )
      m_nValue = contributionscore_bomb_defuse.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    pPlayer->m_iContributionScore += m_nValue;
  }
  v3 = *g_PlantedC4s.m_Memory.m_pMemory;
  if ( *g_PlantedC4s.m_Memory.m_pMemory != nullptr )
  {
    pPlayera = score_bomb_defuse_radius_outer.m_pParent->m_Value.m_fValue;
    fRangeInner = score_bomb_defuse_radius_inner.m_pParent->m_Value.m_fValue;
    if ( (v3->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v3, a2: (int)&savedregs);
    if ( score_bomb_defuse_bonus.m_pParent != nullptr )
      v4 = score_bomb_defuse_bonus.m_pParent->m_Value.m_nValue;
    else
      v4 = 0;
    CCSGameRules::SplitScoreAmongPlayersInRange(
      a1: (int)&savedregs,
      iPoints: v4,
      iTeam: 3,
      pExcludePlayer: nullptr,
      center: &v3->m_vecAbsOrigin,
      fRangeInner,
      fRangeOuter: pPlayera);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102729A0
// Name: void TestRoundWinpanel(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TestRoundWinpanel()
{
  IGameEvent *v0; // esi
  IGameEvent *v1; // esi
  CBasePlayer *v2; // edi
  const edict_t **v3; // edi
  int v4; // eax
  int v5; // eax
  IGameEvent *v6; // eax
  IGameEvent *v7; // esi

  v0 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "round_end", a3: 0, a4: 0);
  v0->SetInt(this: v0, a2: "winner", a3: 2);
  gameeventmanager->FireEvent(this: gameeventmanager, a2: v0, a3: false);
  v1 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_death", a3: 0, a4: 0);
  if ( v1 != nullptr )
  {
    v2 = UTIL_PlayerByIndex(playerIndex: 1);
    if ( v2 != nullptr && v2->IsPlayer(this: v2) )
      v3 = (const edict_t **)__RTDynamicCast(
                               inptr: v2,
                               VfDelta: 0,
                               SrcType: &CBaseEntity `RTTI Type Descriptor',
                               TargetType: &CCSPlayer `RTTI Type Descriptor',
                               isReference: 0);
    else
      v3 = nullptr;
    v4 = engine->GetPlayerUserId(this: engine, a2: v3[6]);
    v1->SetInt(this: v1, a2: "userid", a3: v4);
    v5 = engine->GetPlayerUserId(this: engine, a2: v3[6]);
    v1->SetInt(this: v1, a2: "attacker", a3: v5);
    v1->SetString(this: v1, a2: "weapon", a3: "Bare Hands");
    v1->SetInt(this: v1, a2: "headshot", a3: 1);
    v1->SetInt(this: v1, a2: "revenge", a3: 1);
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v1, a3: false);
  }
  v6 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "cs_win_panel_round", a3: 0, a4: 0);
  v7 = v6;
  if ( v6 != nullptr )
  {
    v6->SetBool(this: v6, a2: "show_timer_attack", a3: true);
    v7->SetInt(this: v7, a2: "timer_time", a3: 90);
    v7->SetInt(this: v7, a2: "final_event", a3: 8);
    v7->SetString(this: v7, a2: "funfact_token", a3: "#funfact_first_blood");
    v7->SetInt(this: v7, a2: "funfact_player", a3: 1);
    v7->SetInt(this: v7, a2: "funfact_data1", a3: 20);
    v7->SetInt(this: v7, a2: "funfact_data2", a3: 31);
    v7->SetInt(this: v7, a2: "funfact_data3", a3: 45);
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v7, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10272B70
// Name: public: void CCSGameRules::DumpTimers(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::DumpTimers(CCSGameRules *this)
{
  CBasePlayer *CommandClient; // esi
  char *v3; // eax
  char *v4; // eax
  char *v5; // eax
  char *v6; // eax
  char *v7; // eax
  char *v8; // eax
  char *v9; // eax
  char *v10; // eax
  char *v11; // eax
  char *v12; // eax
  char *v13; // eax
  char *v14; // eax
  char *v15; // eax
  int m_nValue; // eax
  char *v17; // eax
  void (*v18)(const char *, ...); // edi
  int v19; // eax
  char *v20; // eax
  int v21; // eax
  char *v22; // eax
  int v23; // eax
  char *v24; // eax
  char *m_pszString; // eax
  char *v26; // eax
  int v27; // eax
  char *v28; // eax
  int v29; // eax
  char *v30; // eax
  char *v31; // eax
  char *v32; // eax
  int v33; // edi
  int v34; // eax
  char *v35; // eax
  CCSGameRules *v36; // edi
  char *v37; // eax
  char *v38; // eax
  char *v39; // eax
  char *v40; // eax
  CFmtStrN<256> str; // [esp+10h] [ebp-110h] BYREF
  CCSGameRules *v42; // [esp+11Ch] [ebp-4h]

  v42 = this;
  CommandClient = UTIL_GetCommandClient();
  str.__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
  *(_WORD *)&str.m_bQuietTruncation = 1;
  str.m_nLength = 0;
  v3 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(
         this: &str,
         pszFormat: "Timers and related info at %f:\n",
         gpGlobals->curtime);
  if ( CommandClient != nullptr )
    ClientPrint(
      player: CommandClient,
      msg_dest: 2,
      msg_name: v3,
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  else
    _Msg(a1: "%s", v3);
  v4 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(
         this: &str,
         pszFormat: "m_bCompleteReset: %d\n",
         this->m_bCompleteReset);
  if ( CommandClient != nullptr )
    ClientPrint(
      player: CommandClient,
      msg_dest: 2,
      msg_name: v4,
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  else
    _Msg(a1: "%s", v4);
  v5 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(
         this: &str,
         pszFormat: "m_iTotalRoundsPlayed: %d\n",
         this->m_iTotalRoundsPlayed);
  if ( CommandClient != nullptr )
    ClientPrint(
      player: CommandClient,
      msg_dest: 2,
      msg_name: v5,
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  else
    _Msg(a1: "%s", v5);
  v6 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(
         this: &str,
         pszFormat: "m_iRoundTime: %d\n",
         this->m_iRoundTime.m_Value);
  if ( CommandClient != nullptr )
    ClientPrint(
      player: CommandClient,
      msg_dest: 2,
      msg_name: v6,
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  else
    _Msg(a1: "%s", v6);
  v7 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(
         this: &str,
         pszFormat: "m_iRoundWinStatus: %d\n",
         this->m_iRoundWinStatus);
  if ( CommandClient != nullptr )
    ClientPrint(
      player: CommandClient,
      msg_dest: 2,
      msg_name: v7,
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  else
    _Msg(a1: "%s", v7);
  v8 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(
         this: &str,
         pszFormat: "first connected: %d\n",
         this->m_bFirstConnected);
  if ( CommandClient != nullptr )
    ClientPrint(
      player: CommandClient,
      msg_dest: 2,
      msg_name: v8,
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  else
    _Msg(a1: "%s", v8);
  v9 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(
         this: &str,
         pszFormat: "intermission end time: %f\n",
         this->m_flIntermissionEndTime);
  if ( CommandClient != nullptr )
    ClientPrint(
      player: CommandClient,
      msg_dest: 2,
      msg_name: v9,
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  else
    _Msg(a1: "%s", v9);
  v10 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(
          this: &str,
          pszFormat: "freeze period: %d\n",
          this->m_bFreezePeriod.m_Value);
  if ( CommandClient != nullptr )
    ClientPrint(
      player: CommandClient,
      msg_dest: 2,
      msg_name: v10,
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  else
    _Msg(a1: "%s", v10);
  v11 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(
          this: &str,
          pszFormat: "round restart time: %f\n",
          this->m_flRestartRoundTime);
  if ( CommandClient != nullptr )
    ClientPrint(
      player: CommandClient,
      msg_dest: 2,
      msg_name: v11,
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  else
    _Msg(a1: "%s", v11);
  v12 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(
          this: &str,
          pszFormat: "game start time: %f\n",
          this->m_flGameStartTime.m_Value);
  if ( CommandClient != nullptr )
    ClientPrint(
      player: CommandClient,
      msg_dest: 2,
      msg_name: v12,
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  else
    _Msg(a1: "%s", v12);
  v13 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(
          this: &str,
          pszFormat: "m_fRoundStartTime: %f\n",
          this->m_fRoundStartTime.m_Value);
  if ( CommandClient != nullptr )
    ClientPrint(
      player: CommandClient,
      msg_dest: 2,
      msg_name: v13,
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  else
    _Msg(a1: "%s", v13);
  v14 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(
          this: &str,
          pszFormat: "freeze time: %d\n",
          this->m_iFreezeTime);
  if ( CommandClient != nullptr )
    ClientPrint(
      player: CommandClient,
      msg_dest: 2,
      msg_name: v14,
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  else
    _Msg(a1: "%s", v14);
  v15 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(
          this: &str,
          pszFormat: "next think: %f\n",
          this->m_tmNextPeriodicThink);
  if ( CommandClient != nullptr )
    ClientPrint(
      player: CommandClient,
      msg_dest: 2,
      msg_name: v15,
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  else
    _Msg(a1: "%s", v15);
  if ( fraglimit.m_pParent != nullptr )
    m_nValue = fraglimit.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v17 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(this: &str, pszFormat: "fraglimit: %d\n", m_nValue);
  if ( CommandClient != nullptr )
  {
    ClientPrint(
      player: CommandClient,
      msg_dest: 2,
      msg_name: v17,
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
    v18 = (void (*)(const char *, ...))_Msg;
  }
  else
  {
    v18 = (void (*)(const char *, ...))_Msg;
    _Msg(a1: "%s", v17);
  }
  if ( mp_maxrounds.m_pParent != nullptr )
    v19 = mp_maxrounds.m_pParent->m_Value.m_nValue;
  else
    v19 = 0;
  v20 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(this: &str, pszFormat: "mp_maxrounds: %d\n", v19);
  if ( CommandClient != nullptr )
    ClientPrint(
      player: CommandClient,
      msg_dest: 2,
      msg_name: v20,
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  else
    v18(a1: "%s", v20);
  if ( mp_winlimit.m_pParent != nullptr )
    v21 = mp_winlimit.m_pParent->m_Value.m_nValue;
  else
    v21 = 0;
  v22 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(this: &str, pszFormat: "mp_winlimit: %d\n", v21);
  if ( CommandClient != nullptr )
    ClientPrint(
      player: CommandClient,
      msg_dest: 2,
      msg_name: v22,
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  else
    v18(a1: "%s", v22);
  if ( cv_bot_quota.m_pParent != nullptr )
    v23 = cv_bot_quota.m_pParent->m_Value.m_nValue;
  else
    v23 = 0;
  v24 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(this: &str, pszFormat: "bot_quota: %d\n", v23);
  if ( CommandClient != nullptr )
    ClientPrint(
      player: CommandClient,
      msg_dest: 2,
      msg_name: v24,
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  else
    v18(a1: "%s", v24);
  if ( (cv_bot_quota_mode.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = cv_bot_quota_mode.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)locale;
  }
  v26 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(this: &str, pszFormat: "bot_quota_mode: %s\n", m_pszString);
  if ( CommandClient != nullptr )
    ClientPrint(
      player: CommandClient,
      msg_dest: 2,
      msg_name: v26,
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  else
    _Msg(a1: "%s", v26);
  if ( cv_bot_join_after_player.m_pParent != nullptr )
    v27 = cv_bot_join_after_player.m_pParent->m_Value.m_nValue;
  else
    v27 = 0;
  v28 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(this: &str, pszFormat: "bot_join_after_player: %d\n", v27);
  if ( CommandClient != nullptr )
    ClientPrint(
      player: CommandClient,
      msg_dest: 2,
      msg_name: v28,
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  else
    _Msg(a1: "%s", v28);
  if ( bot_join_delay.m_pParent != nullptr )
    v29 = bot_join_delay.m_pParent->m_Value.m_nValue;
  else
    v29 = 0;
  v30 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(this: &str, pszFormat: "bot_join_delay: %d\n", v29);
  if ( CommandClient != nullptr )
    ClientPrint(
      player: CommandClient,
      msg_dest: 2,
      msg_name: v30,
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  else
    _Msg(a1: "%s", v30);
  if ( (nextlevel.m_nFlags & 0x1000) != 0 )
  {
    v31 = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    v31 = nextlevel.m_pParent->m_Value.m_pszString;
    if ( v31 == nullptr )
      v31 = (char *)locale;
  }
  v32 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(this: &str, pszFormat: "nextlevel: %s\n", v31);
  if ( CommandClient != nullptr )
    ClientPrint(
      player: CommandClient,
      msg_dest: 2,
      msg_name: v32,
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  else
    _Msg(a1: "%s", v32);
  v33 = UTIL_HumansInGame(ignoreSpectators: true);
  v34 = UTIL_BotsInGame();
  v35 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(
          this: &str,
          pszFormat: "%d humans and %d bots in game\n",
          v33,
          v34);
  if ( CommandClient != nullptr )
    ClientPrint(
      player: CommandClient,
      msg_dest: 2,
      msg_name: v35,
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  else
    _Msg(a1: "%s", v35);
  v36 = v42;
  v37 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(
          this: &str,
          pszFormat: "num CTs (spawnable): %d (%d)\n",
          v42->m_iNumCT,
          v42->m_iNumSpawnableCT);
  if ( CommandClient != nullptr )
    ClientPrint(
      player: CommandClient,
      msg_dest: 2,
      msg_name: v37,
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  else
    _Msg(a1: "%s", v37);
  v38 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(
          this: &str,
          pszFormat: "num Ts (spawnable): %d (%d)\n",
          v36->m_iNumTerrorist,
          v36->m_iNumSpawnableTerrorist);
  if ( CommandClient != nullptr )
    ClientPrint(
      player: CommandClient,
      msg_dest: 2,
      msg_name: v38,
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  else
    _Msg(a1: "%s", v38);
  if ( g_fGameOver )
  {
    v39 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(this: &str, pszFormat: "Game is over!\n");
    if ( CommandClient != nullptr )
      ClientPrint(
        player: CommandClient,
        msg_dest: 2,
        msg_name: v39,
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
    else
      _Msg(a1: "%s", v39);
  }
  v40 = CFmtStrN<256>::use_Q_snprintf_instead_of_sprintf(this: &str, pszFormat: "\n");
  if ( CommandClient != nullptr )
    ClientPrint(
      player: CommandClient,
      msg_dest: 2,
      msg_name: v40,
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  else
    _Msg(a1: "%s", v40);
}

//------------------------------------------------------------------------------
// Address: 0x10273370
// Name: mp_dump_timers
// Source: json
//------------------------------------------------------------------------------
void __cdecl mp_dump_timers()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() && g_pGameRules != nullptr )
    CCSGameRules::DumpTimers(this: (CCSGameRules *)g_pGameRules);
}

//------------------------------------------------------------------------------
// Address: 0x10273390
// Name: public: virtual bool CCSGameRules::FPlayerCanRespawn(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSGameRules::FPlayerCanRespawn(CCSGameRules *this, color32_s pBasePlayer)
{
  CBasePlayer *v2; // edi
  CBaseEntity *v4; // edi
  CTeam *GlobalTeam; // eax
  CTeam *v6; // eax
  int v7; // eax
  const char *v9; // [esp+Ch] [ebp-8h]

  v2 = (CBasePlayer *)pBasePlayer;
  if ( pBasePlayer == 0
    || (*(unsigned __int8 (__thiscall **)(color32_s))(**(_DWORD **)&pBasePlayer + 336))(a1: pBasePlayer) == 0 )
  {
    v4 = nullptr;
    goto LABEL_4;
  }
  v4 = (CBaseEntity *)__RTDynamicCast(
                        inptr: v2,
                        VfDelta: 0,
                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                        TargetType: &CCSPlayer `RTTI Type Descriptor',
                        isReference: 0);
  if ( v4 == nullptr )
LABEL_4:
    _Error(this: (ISceneTokenProcessor *)&stru_104D4478, a2: v9);
  if ( (g_pGameTypes->GetCurrentGameType(this: g_pGameTypes) != 1
     || g_pGameTypes->GetCurrentGameMode(this: g_pGameTypes) != 0)
    && (int)v4[5].m_OnUser4.m_Value.eVal.m_Index > 0
    && this->m_bFirstConnected
    || (float)(this->m_flRestartRoundTime - gpGlobals->curtime) > 5.0
    || CBaseEntity::GetTeamNumber(this: v4) != 3 && CBaseEntity::GetTeamNumber(this: v4) != 2
    || v4[7].m_fFlags.m_Value == 0 )
  {
    return 0;
  }
  if ( (g_pGameTypes->GetCurrentGameType(this: g_pGameTypes) != 1
     || g_pGameTypes->GetCurrentGameMode(this: g_pGameTypes) != 0)
    && !CCSGameRules::IsPlayingGunGameTRBomb(this) )
  {
    GlobalTeam = GetGlobalTeam(iIndex: 3);
    this->m_iNumCT = GlobalTeam->GetNumPlayers(this: GlobalTeam);
    v6 = GetGlobalTeam(iIndex: 2);
    v7 = v6->GetNumPlayers(this: v6);
    this->m_iNumTerrorist = v7;
    if ( v7 > 0 && this->m_iNumCT > 0 && gpGlobals->curtime > (float)(this->m_fRoundStartTime.m_Value + 20.0) )
    {
      pBasePlayer = (color32_s)-16777216;
      if ( mp_fadetoblack.m_pParent != nullptr && mp_fadetoblack.m_pParent->m_Value.m_nValue != 0 )
        UTIL_ScreenFade(pEntity: v4, color: &pBasePlayer, fadeTime: 3.0, fadeHold: 3.0, flags: 10);
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10273550
// Name: public: void CCSGameRules::ProcessEndOfRoundAchievements(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::ProcessEndOfRoundAchievements(CCSGameRules *this, int iWinnerTeam, int iReason)
{
  int v3; // ebx
  CTeam *GlobalTeam; // esi
  CCSPlayer *v5; // esi
  int v6; // edi
  CTeam *v7; // esi
  int v8; // ebx
  int v9; // eax
  void *v10; // edi
  CBaseMultiplayerPlayer *v11; // eax
  CTeam *v12; // esi
  int i; // ebx
  int v14; // eax
  void *v15; // edi
  CBaseMultiplayerPlayer *v16; // eax
  CTeam *v17; // esi
  int j; // ebx
  CBasePlayer *v19; // edi
  CBaseMultiplayerPlayer *v20; // eax
  int ignoreCount; // [esp+0h] [ebp-Ch]
  CTeam *losingTeam; // [esp+4h] [ebp-8h]

  if ( iWinnerTeam != 3 && iWinnerTeam != 2 )
    return;
  v3 = 1;
  GlobalTeam = GetGlobalTeam(iIndex: (iWinnerTeam != 3) + 2);
  losingTeam = GlobalTeam;
  ignoreCount = 0;
  if ( gpGlobals->maxClients >= 1 )
  {
    do
    {
      v5 = (CCSPlayer *)UTIL_PlayerByIndex(playerIndex: v3);
      if ( v5 != nullptr )
      {
        if ( g_pGameTypes->GetCurrentGameType(this: g_pGameTypes) == 1
          && g_pGameTypes->GetCurrentGameMode(this: g_pGameTypes) == 0 )
        {
          CCSGameRules::UpdateMatchStats(this, pPlayer: v5, winnerIndex: iWinnerTeam);
        }
        if ( CBaseEntity::GetTeamNumber(this: v5) == (iWinnerTeam != 3) + 2 && v5->m_wasNotKilledNaturally )
          ++ignoreCount;
      }
      ++v3;
    }
    while ( v3 <= gpGlobals->maxClients );
    GlobalTeam = losingTeam;
  }
  v6 = iReason;
  if ( iReason == 7 )
  {
    if ( !this->m_bNoCTsKilled )
    {
LABEL_29:
      if ( !this->m_bNoCTsDamaged )
        goto LABEL_42;
LABEL_33:
      if ( GlobalTeam != nullptr && GlobalTeam->GetNumPlayers(this: GlobalTeam) - ignoreCount >= 5 )
      {
        v12 = GetGlobalTeam(iIndex: iWinnerTeam);
        for ( i = 0; i < v12->GetNumPlayers(this: v12); ++i )
        {
          v14 = (int)v12->GetPlayer(this: v12, a2: i);
          v15 = (void *)v14;
          if ( v14 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v14 + 336))(a1: v14) != 0 )
          {
            v16 = (CBaseMultiplayerPlayer *)__RTDynamicCast(
                                              inptr: v15,
                                              VfDelta: 0,
                                              SrcType: &CBaseEntity `RTTI Type Descriptor',
                                              TargetType: &CCSPlayer `RTTI Type Descriptor',
                                              isReference: 0);
            if ( v16 != nullptr )
              CBaseMultiplayerPlayer::AwardAchievement(this: v16, iAchievement: 5027, iCount: 1);
          }
        }
        GlobalTeam = losingTeam;
      }
      goto LABEL_42;
    }
  }
  else
  {
    if ( iReason != 8 )
      goto LABEL_28;
    if ( !this->m_bNoTerroristsKilled )
    {
LABEL_32:
      if ( this->m_bNoTerroristsDamaged )
        goto LABEL_33;
      goto LABEL_42;
    }
  }
  if ( GlobalTeam != nullptr && GlobalTeam->GetNumPlayers(this: GlobalTeam) - ignoreCount >= 5 )
  {
    v7 = GetGlobalTeam(iIndex: iWinnerTeam);
    v8 = 0;
    if ( v7->GetNumPlayers(this: v7) > 0 )
    {
      do
      {
        v9 = (int)v7->GetPlayer(this: v7, a2: v8);
        v10 = (void *)v9;
        if ( v9 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v9 + 336))(a1: v9) != 0 )
        {
          v11 = (CBaseMultiplayerPlayer *)__RTDynamicCast(
                                            inptr: v10,
                                            VfDelta: 0,
                                            SrcType: &CBaseEntity `RTTI Type Descriptor',
                                            TargetType: &CCSPlayer `RTTI Type Descriptor',
                                            isReference: 0);
          if ( v11 != nullptr )
            CBaseMultiplayerPlayer::AwardAchievement(this: v11, iAchievement: 5026, iCount: 1);
        }
        ++v8;
      }
      while ( v8 < v7->GetNumPlayers(this: v7) );
      v6 = iReason;
    }
    GlobalTeam = losingTeam;
  }
LABEL_28:
  if ( v6 == 7 )
    goto LABEL_29;
  if ( v6 == 8 )
    goto LABEL_32;
LABEL_42:
  if ( iWinnerTeam == 2
    && this->m_bNoCTsKilled
    && GlobalTeam != nullptr
    && GlobalTeam->GetNumPlayers(this: GlobalTeam) >= 5 )
  {
    v17 = GetGlobalTeam(iIndex: iWinnerTeam);
    for ( j = 0; j < v17->GetNumPlayers(this: v17); ++j )
    {
      v19 = v17->GetPlayer(this: v17, a2: j);
      if ( v19 != nullptr && v19->IsPlayer(this: v19) )
      {
        v20 = (CBaseMultiplayerPlayer *)__RTDynamicCast(
                                          inptr: v19,
                                          VfDelta: 0,
                                          SrcType: &CBaseEntity `RTTI Type Descriptor',
                                          TargetType: &CCSPlayer `RTTI Type Descriptor',
                                          isReference: 0);
        if ( v20 != nullptr )
          CBaseMultiplayerPlayer::AwardAchievement(this: v20, iAchievement: 5040, iCount: 1);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10273880
// Name: public: void CCSGameRules::CleanUpMap(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::CleanUpMap(CCSGameRules *this)
{
  CBaseEntity *Ent; // esi
  void *v2; // edi
  const char *pszValue; // eax
  const char *v4; // eax
  CCSGameRules::CleanUpMap::__l19::CCSMapEntityFilter filter; // [esp+0h] [ebp-8h] BYREF

  if ( !this->m_bLogoMap.m_Value )
  {
    Ent = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: nullptr);
    if ( Ent != nullptr )
    {
      while ( 1 )
      {
        v2 = __RTDynamicCast(
               inptr: Ent,
               VfDelta: 0,
               SrcType: &CBaseEntity `RTTI Type Descriptor',
               TargetType: &CWeaponCSBase `RTTI Type Descriptor',
               isReference: 0);
        if ( v2 == nullptr )
          break;
        (*(void (__thiscall **)(void *))(*(_DWORD *)v2 + 1500))(a1: v2);
        if ( (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)v2 + 1496))(a1: v2) != 0 )
          goto LABEL_10;
LABEL_11:
        Ent = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: Ent);
        if ( Ent == nullptr )
          goto LABEL_12;
      }
      pszValue = Ent->m_iClassname.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      if ( FindInList(pStrings: s_PreserveEnts_0, pToFind: pszValue) || Commentary_IsCommentaryEntity(pEntity: Ent) != 0 )
        goto LABEL_11;
LABEL_10:
      UTIL_Remove(oldObj: Ent);
      goto LABEL_11;
    }
LABEL_12:
    CGlobalEntityList::CleanupDeleteList(this: &gEntList);
    CEventQueue::Init(this: &g_EventQueue);
    filter.m_iIterator = g_MapEntityRefs.m_Head;
    filter.__vftable = (CCSGameRules::CleanUpMap::__l19::CCSMapEntityFilter_vtbl *)`CCSGameRules::CleanUpMap'::`19'::CCSMapEntityFilter::`vftable';
    v4 = engine->GetMapEntitiesString(this: engine);
    MapEntity_ParseAllEntities(pMapData: v4, pFilter: &filter, bActivateEntities: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10273980
// Name: public: int CCSGameRules::GetCurrentGunGameWeapon(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSGameRules::GetCurrentGunGameWeapon(CCSGameRules *this, int nCurrentWeaponIndex, int nTeamID)
{
  int m_Value; // eax
  int v4; // eax

  if ( nTeamID == 3 )
    m_Value = this->m_iNumGunGameProgressiveWeaponsCT.m_Value;
  else
    m_Value = this->m_iNumGunGameProgressiveWeaponsT.m_Value;
  if ( m_Value == 0 || nCurrentWeaponIndex < 0 )
    return -1;
  v4 = nTeamID == 3 ? this->m_iNumGunGameProgressiveWeaponsCT.m_Value : this->m_iNumGunGameProgressiveWeaponsT.m_Value;
  if ( nCurrentWeaponIndex >= v4 )
    return -1;
  if ( nTeamID == 3 )
    return this->m_GGProgressiveWeaponOrderCT.m_Value[nCurrentWeaponIndex];
  return this->m_GGProgressiveWeaponOrderT.m_Value[nCurrentWeaponIndex];
}

//------------------------------------------------------------------------------
// Address: 0x102739F0
// Name: public: int CCSGameRules::GetNextGunGameWeapon(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSGameRules::GetNextGunGameWeapon(CCSGameRules *this, int nCurrentWeaponIndex, int nTeamID)
{
  int m_Value; // eax
  int v4; // eax

  if ( nTeamID == 3 )
    m_Value = this->m_iNumGunGameProgressiveWeaponsCT.m_Value;
  else
    m_Value = this->m_iNumGunGameProgressiveWeaponsT.m_Value;
  if ( m_Value == 0 || nCurrentWeaponIndex < 0 )
    return -1;
  v4 = nTeamID == 3 ? this->m_iNumGunGameProgressiveWeaponsCT.m_Value : this->m_iNumGunGameProgressiveWeaponsT.m_Value;
  if ( nCurrentWeaponIndex >= v4 - 1 )
    return -1;
  if ( nTeamID == 3 )
    return this->m_GGProgressiveWeaponOrderCT.m_Value[nCurrentWeaponIndex + 1];
  return this->m_GGProgressiveWeaponOrderT.m_Value[nCurrentWeaponIndex + 1];
}

//------------------------------------------------------------------------------
// Address: 0x10273A60
// Name: public: int CCSGameRules::GetPreviousGunGameWeapon(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSGameRules::GetPreviousGunGameWeapon(CCSGameRules *this, int nCurrentWeaponIndex, int nTeamID)
{
  int m_Value; // eax
  int v4; // eax

  if ( nTeamID == 3 )
    m_Value = this->m_iNumGunGameProgressiveWeaponsCT.m_Value;
  else
    m_Value = this->m_iNumGunGameProgressiveWeaponsT.m_Value;
  if ( m_Value == 0 || nCurrentWeaponIndex <= 0 )
    return -1;
  v4 = nTeamID == 3 ? this->m_iNumGunGameProgressiveWeaponsCT.m_Value : this->m_iNumGunGameProgressiveWeaponsT.m_Value;
  if ( nCurrentWeaponIndex >= v4 )
    return -1;
  if ( nTeamID == 3 )
    return *(&this->m_iSpectatorSlotCount.m_Value + nCurrentWeaponIndex);
  return this->m_GGProgressiveWeaponOrderCT.m_Value[nCurrentWeaponIndex + 59];
}

//------------------------------------------------------------------------------
// Address: 0x10273AD0
// Name: public: bool CCSGameRules::IsFinalGunGameProgressiveWeapon(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSGameRules::IsFinalGunGameProgressiveWeapon(CCSGameRules *this, int nCurrentWeaponIndex, int nTeamID)
{
  int v3; // eax

  if ( nTeamID == 3 )
    v3 = this->m_iNumGunGameProgressiveWeaponsCT.m_Value - 1;
  else
    v3 = this->m_iNumGunGameProgressiveWeaponsT.m_Value - 1;
  return nCurrentWeaponIndex == v3;
}

//------------------------------------------------------------------------------
// Address: 0x10273B00
// Name: public: int CCSGameRules::GetGunGameNumKillsRequiredForWeapon(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSGameRules::GetGunGameNumKillsRequiredForWeapon(
        CCSGameRules *this,
        int nCurrentWeaponIndex,
        int nTeamID)
{
  int v3; // eax

  if ( nCurrentWeaponIndex < 0 )
    return -1;
  v3 = nTeamID == 3 ? this->m_iNumGunGameProgressiveWeaponsCT.m_Value : this->m_iNumGunGameProgressiveWeaponsT.m_Value;
  if ( nCurrentWeaponIndex > v3 - 1 )
    return -1;
  if ( nTeamID == 3 )
    return this->m_GGProgressiveWeaponKillUpgradeOrderCT.m_Value[nCurrentWeaponIndex];
  return this->m_GGProgressiveWeaponKillUpgradeOrderT.m_Value[nCurrentWeaponIndex];
}

//------------------------------------------------------------------------------
// Address: 0x10273B50
// Name: public: virtual char const __near * CCSGameRules::GetChatLocation(bool,class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer::NetworkVar_m_szLastPlaceName *__thiscall CCSGameRules::GetChatLocation(
        CCSGameRules *this,
        bool bTeamOnly,
        CBasePlayer *pPlayer)
{
  if ( pPlayer != nullptr
    && bTeamOnly
    && (CBaseEntity::GetTeamNumber(this: pPlayer) == 3 || CBaseEntity::GetTeamNumber(this: pPlayer) == 2)
    && pPlayer->IsAlive(this: pPlayer) )
  {
    return &pPlayer->m_szLastPlaceName;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10273BA0
// Name: public: void CCSGameRules::PlayerTookDamage(class CCSPlayer __near *,class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::PlayerTookDamage(
        CCSGameRules *this,
        CCSPlayer *player,
        const CTakeDamageInfo *damageInfo)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // edi
  unsigned int v6; // eax
  CBaseEntity *v7; // eax
  CBasePlayer *DeathScorer; // eax
  CCSPlayer *v9; // edi
  unsigned int v10; // eax
  const CTakeDamageInfo *damageInfoa; // [esp+18h] [ebp+Ch]

  m_Index = damageInfo->m_hInflictor.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v6 = damageInfo->m_hAttacker.m_Index;
  if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
    v7 = nullptr;
  else
    v7 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
  DeathScorer = CMultiplayRules::GetDeathScorer(this, pKiller: v7, pInflictor: m_pEntity);
  v9 = (CCSPlayer *)DeathScorer;
  if ( player != nullptr && DeathScorer != nullptr )
  {
    if ( CBaseEntity::GetTeamNumber(this: player) == 3 )
      this->m_bNoCTsDamaged = false;
    if ( CBaseEntity::GetTeamNumber(this: player) == 2 )
      this->m_bNoTerroristsDamaged = false;
    v10 = this->m_pFirstBlood.m_Index;
    if ( (v10 == -1
       || g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber != HIWORD(v10)
       || g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_pEntity == nullptr)
      && v9 != player )
    {
      damageInfoa = (const CTakeDamageInfo *)CBaseEntity::GetTeamNumber(this: v9);
      if ( damageInfoa != (const CTakeDamageInfo *)CBaseEntity::GetTeamNumber(this: player) )
      {
        CHandle<CBaseEntity>::operator=(this: (CHandle<CBaseEntity> *)&this->m_pFirstBlood, val: v9);
        this->m_firstBloodTime = gpGlobals->curtime - this->m_fRoundStartTime.m_Value;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10273CC0
// Name: public: void CCSGameRules::InitiateVote(enum VoteType,class CCSPlayer __near *,class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSGameRules::InitiateVote(
        CCSGameRules *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        VoteType voteType,
        CCSPlayer *initiatingPlayer,
        CCSPlayer *playerToKick)
{
  int i; // edi
  CBasePlayer *v7; // esi
  _BYTE *v8; // eax
  IGameEvent *v9; // esi
  int v10; // eax
  int v11; // eax

  if ( initiatingPlayer != nullptr && this->m_currentVote == VoteType_None )
  {
    this->m_currentVote = voteType;
    this->m_voteEndTime = mp_vote_time.m_pParent->m_Value.m_fValue + gpGlobals->curtime;
    for ( i = 1; i <= 64; ++i )
    {
      v7 = UTIL_PlayerByIndex(playerIndex: i);
      if ( v7 != nullptr && v7->IsPlayer(this: v7) )
      {
        v8 = __RTDynamicCast(
               inptr: v7,
               VfDelta: 0,
               SrcType: &CBaseEntity `RTTI Type Descriptor',
               TargetType: &CCSPlayer `RTTI Type Descriptor',
               isReference: 0);
        if ( v8 != nullptr )
          v8[6876] = 0;
      }
    }
    v9 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "start_vote", a3: 0, a4: 0);
    if ( v9 != nullptr )
    {
      v10 = ((int (__thiscall *)(IVEngineServer *, edict_t *, int, int))engine->GetPlayerUserId)(
              a1: engine,
              a2: initiatingPlayer->m_Network.m_pPev,
              a3,
              a4: a2);
      v9->SetInt(this: v9, a2: "userid", a3: v10);
      v9->SetInt(this: v9, a2: "type", a3: voteType);
      if ( playerToKick != nullptr )
      {
        v11 = engine->GetPlayerUserId(this: engine, a2: playerToKick->m_Network.m_pPev);
        v9->SetInt(this: v9, a2: "playerToKick", a3: v11);
      }
      ((void (__thiscall *)(IGameEventManager2 *))gameeventmanager->FireEvent)(a1: gameeventmanager);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10273E20
// Name: _CCSGameRules::CleanUpMap_::_19_::CCSMapEntityFilter::ShouldCreateEntity
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSGameRules::CleanUpMap_::_19_::CCSMapEntityFilter::ShouldCreateEntity(
        CCSGameRules::CleanUpMap::__l19::CCSMapEntityFilter *this,
        const char *pClassname)
{
  if ( !FindInList(pStrings: s_PreserveEnts_0, pToFind: pClassname) )
    return 1;
  if ( this->m_iIterator != 0xFFFF )
    this->m_iIterator = g_MapEntityRefs.m_Memory.m_pMemory[LOWORD(this->m_iIterator)].m_Next;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10273E70
// Name: _CCSGameRules::CleanUpMap_::_19_::CCSMapEntityFilter::CreateNextEntity
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CCSGameRules::CleanUpMap_::_19_::CCSMapEntityFilter::CreateNextEntity(
        CCSGameRules::CleanUpMap::__l19::CCSMapEntityFilter *this,
        const char *pClassname)
{
  UtlLinkedListElem_t<CMapEntityRef,unsigned short> *v3; // eax
  int m_iEdict; // eax

  if ( this->m_iIterator == 0xFFFF )
    return nullptr;
  v3 = &g_MapEntityRefs.m_Memory.m_pMemory[LOWORD(this->m_iIterator)];
  this->m_iIterator = v3->m_Next;
  m_iEdict = v3->m_Element.m_iEdict;
  if ( m_iEdict == -1 || gpGlobals->pEdicts != nullptr && (gpGlobals->pEdicts[m_iEdict].m_fStateFlags & 2) == 0 )
    return CreateEntityByName(className: pClassname, iForceEdictIndex: -1, bNotify: true);
  else
    return CreateEntityByName(className: pClassname, iForceEdictIndex: m_iEdict, bNotify: true);
}

//------------------------------------------------------------------------------
// Address: 0x10273EF0
// Name: public: virtual class CBaseEntity __near * CCSGameRules::GetPlayerSpawnSpot(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__userpurge CCSGameRules::GetPlayerSpawnSpot@<eax>(
        CCSGameRules *this@<ecx>,
        int a2@<edi>,
        CBasePlayer *pPlayer)
{
  CBaseEntity *v3; // ebx
  const Vector *v4; // edi
  const CViewVectors *v5; // eax
  CGameTrace ptr; // [esp+8h] [ebp-60h] BYREF
  Vector vecAbsEnd; // [esp+5Ch] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+68h] [ebp+0h] BYREF

  v3 = pPlayer->EntSelectSpawnPoint(this: pPlayer);
  if ( (v3->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: v3, a2: (int)&savedregs);
  v4 = (const Vector *)(((int (__thiscall *)(CGameRules *, int))g_pGameRules->GetViewVectors)(a1: g_pGameRules, a2) + 24);
  v5 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  vecAbsEnd.x = v3->m_vecAbsOrigin.x;
  vecAbsEnd.y = v3->m_vecAbsOrigin.y;
  vecAbsEnd.z = v3->m_vecAbsOrigin.z - 500.0;
  UTIL_TraceHull(
    a1: &savedregs,
    a2: (int)&v3->m_vecAbsOrigin,
    vecAbsStart: &v3->m_vecAbsOrigin,
    &vecAbsEnd,
    hullMin: &v5->m_vHullMin,
    hullMax: v4,
    mask: 0x200400Bu,
    ignore: pPlayer,
    collisionGroup: 0,
    &ptr);
  if ( (v3->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: v3, a2: (int)&savedregs);
  ((void (__thiscall *)(CBasePlayer *, Vector *, CNetworkVectorXYZBase<QAngle,CBaseEntity::NetworkVar_m_angRotation> *, Vector *))pPlayer->Teleport)(
    a1: pPlayer,
    a2: &v3->m_vecAbsOrigin,
    a3: &v3->m_angRotation,
    a4: &vec3_origin);
  if ( vec3_angle.x != pPlayer->m_Local.m_vecPunchAngle.m_Value.x
    || vec3_angle.y != pPlayer->m_Local.m_vecPunchAngle.m_Value.y
    || vec3_angle.z != pPlayer->m_Local.m_vecPunchAngle.m_Value.z )
  {
    pPlayer->m_Local.NetworkStateChanged(this: &pPlayer->m_Local, a2: &pPlayer->m_Local.m_vecPunchAngle);
    pPlayer->m_Local.m_vecPunchAngle.m_Value = vec3_angle;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10274040
// Name: public: virtual void CCSGameRules::CreateCustomNetworkStringTables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::CreateCustomNetworkStringTables(CCSGameRules *this)
{
  CSWeaponID i; // esi
  CCSWeaponInfo *WeaponInfo; // eax

  this->m_StringTableBlackMarket = g_StringTableBlackMarket;
  if ( this->m_bBlackMarket.m_Value )
  {
    CGameRulesProxy::NotifyNetworkStateChanged();
    this->m_bBlackMarket.m_Value = false;
  }
  for ( i = WEAPON_DEAGLE; i < WEAPON_MAX; ++i )
  {
    if ( i != WEAPON_SHIELDGUN )
    {
      WeaponInfo = GetWeaponInfo(weaponID: i);
      if ( WeaponInfo != nullptr )
        WeaponInfo->m_iWeaponPrice = CCSWeaponInfo::GetDefaultPrice(this: WeaponInfo);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102740A0
// Name: protected: void CCSGameRules::GotoTRBombModeHalftime(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::GotoTRBombModeHalftime(CCSGameRules *this)
{
  IGameEvent *v2; // eax

  if ( !this->m_bGunGameTRBombModeHalftime.m_Value )
  {
    CGameRulesProxy::NotifyNetworkStateChanged();
    this->m_bGunGameTRBombModeHalftime.m_Value = true;
  }
  this->m_bFirstHalfOfGunGameTRBombModePlayed = true;
  v2 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "cs_halftime_started", a3: 0, a4: 0);
  if ( v2 != nullptr )
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v2, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102740F0
// Name: protected: void CCSGameRules::CalculateTeamScores(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::CalculateTeamScores(CCSGameRules *this)
{
  int m_iNumTerroristWins; // edi
  int m_iNumCTWins; // edi

  m_iNumTerroristWins = this->m_iNumTerroristWins;
  if ( this->m_iGunGameTRBombTScore.m_Value != m_iNumTerroristWins )
  {
    CGameRulesProxy::NotifyNetworkStateChanged();
    this->m_iGunGameTRBombTScore.m_Value = m_iNumTerroristWins;
  }
  m_iNumCTWins = this->m_iNumCTWins;
  if ( this->m_iGunGameTRBombCTScore.m_Value != m_iNumCTWins )
  {
    CGameRulesProxy::NotifyNetworkStateChanged();
    this->m_iGunGameTRBombCTScore.m_Value = m_iNumCTWins;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10274130
// Name: public: bool CCSGameRules::CheckWinLimit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSGameRules::CheckWinLimit(CCSGameRules *this)
{
  CCSGameRules *v1; // esi
  int (__thiscall *GetCurrentGameType)(IGameTypes *); // edx
  int m_nValue; // eax
  int v4; // eax
  int v6; // eax
  bool v7; // zf
  int v8; // edi
  CTeam *GlobalTeam; // esi
  int v10; // ebx
  CBasePlayer *v11; // edi
  _BYTE *v12; // eax
  CTeam *v13; // ebx
  int (__thiscall *GetNumPlayers)(CTeam *); // eax
  int v15; // edi
  int v16; // eax
  void *v17; // esi
  CBaseEdict **v18; // eax
  CBaseEdict **v19; // esi
  CBaseEdict *v20; // ecx
  CBaseEdict *v21; // ecx
  int (__thiscall *v22)(CTeam *); // edx
  int v23; // edi
  int v24; // edi
  CTeam *v25; // esi
  int v26; // ebx
  CBasePlayer *v27; // edi
  _WORD *v28; // eax
  void (__thiscall *GoToIntermission)(struct CCSGameRules *); // edx
  int v30; // eax
  ConVarRef mp_ggtr_rounds_per_half; // [esp+4h] [ebp-18h] BYREF
  int iPlayer; // [esp+Ch] [ebp-10h]
  CCSGameRules *v33; // [esp+10h] [ebp-Ch]
  int iTeam; // [esp+14h] [ebp-8h]
  bool bSwitchTo2ndHalfOfGunGameTRBombMode; // [esp+1Ah] [ebp-2h]
  bool bShouldTerminateTRBombMatch; // [esp+1Bh] [ebp-1h]

  v1 = this;
  GetCurrentGameType = g_pGameTypes->GetCurrentGameType;
  v33 = this;
  if ( GetCurrentGameType(this: g_pGameTypes) == 1 && g_pGameTypes->GetCurrentGameMode(this: g_pGameTypes) == 1 )
  {
    if ( mp_ggselect_match_bestof_win.m_pParent != nullptr )
      m_nValue = mp_ggselect_match_bestof_win.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    v4 = (m_nValue >> 1) + 1;
    if ( mp_ggselect_match_bestof_win.m_pParent != nullptr
      && mp_ggselect_match_bestof_win.m_pParent->m_Value.m_nValue != 0 )
    {
      if ( v1->m_iNumCTWins >= v4 )
      {
        UTIL_LogPrintf(fmt: "Team \"CT\" triggered \"GG Select Intermission_Win_Limit\"\n");
        v1->GoToIntermission(this: v1);
        return 1;
      }
      if ( v1->m_iNumTerroristWins >= v4 )
      {
        UTIL_LogPrintf(fmt: "Team \"TERRORIST\" triggered \"GG Select Intermission_Win_Limit\"\n");
        v1->GoToIntermission(this: v1);
        return 1;
      }
    }
    return 0;
  }
  if ( g_pGameTypes->GetCurrentGameType(this: g_pGameTypes) == 1
    && g_pGameTypes->GetCurrentGameMode(this: g_pGameTypes) == 2 )
  {
    ConVarRef::ConVarRef(this: &mp_ggtr_rounds_per_half, pName: "mp_ggtr_rounds_per_half");
    if ( v1->m_bFirstHalfOfGunGameTRBombModePlayed )
      v6 = 2 * mp_ggtr_rounds_per_half.m_pConVarState->m_Value.m_nValue;
    else
      v6 = mp_ggtr_rounds_per_half.m_pConVarState->m_Value.m_nValue;
    if ( v1->m_iNumCTWins + v1->m_iNumTerroristWins >= v6 )
    {
      CCSGameRules::CalculateTeamScores(this: v1);
      v7 = !v1->m_bFirstHalfOfGunGameTRBombModePlayed;
      bSwitchTo2ndHalfOfGunGameTRBombMode = false;
      bShouldTerminateTRBombMatch = false;
      if ( v7 )
      {
        v8 = 0;
        bSwitchTo2ndHalfOfGunGameTRBombMode = true;
        iTeam = 0;
        if ( GetNumberOfTeams() > 0 )
        {
          do
          {
            GlobalTeam = GetGlobalTeam(iIndex: v8);
            v10 = 0;
            if ( GlobalTeam->GetNumPlayers(this: GlobalTeam) > 0 )
            {
              do
              {
                v11 = GlobalTeam->GetPlayer(this: GlobalTeam, a2: v10);
                if ( v11 != nullptr && v11->IsPlayer(this: v11) )
                {
                  v12 = __RTDynamicCast(
                          inptr: v11,
                          VfDelta: 0,
                          SrcType: &CBaseEntity `RTTI Type Descriptor',
                          TargetType: &CCSPlayer `RTTI Type Descriptor',
                          isReference: 0);
                  if ( v12 != nullptr )
                    v12[4861] = 1;
                }
                ++v10;
              }
              while ( v10 < GlobalTeam->GetNumPlayers(this: GlobalTeam) );
              v8 = iTeam;
            }
            iTeam = ++v8;
          }
          while ( v8 < GetNumberOfTeams() );
          v1 = v33;
        }
        CCSGameRules::GotoTRBombModeHalftime(this: v1);
      }
      else
      {
        bShouldTerminateTRBombMatch = true;
      }
      iTeam = 0;
      if ( GetNumberOfTeams() > 0 )
      {
        do
        {
          v13 = GetGlobalTeam(iIndex: iTeam);
          GetNumPlayers = v13->GetNumPlayers;
          v15 = 0;
          iPlayer = 0;
          if ( GetNumPlayers(this: v13) > 0 )
          {
            do
            {
              v16 = (int)v13->GetPlayer(this: v13, a2: v15);
              v17 = (void *)v16;
              if ( v16 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v16 + 336))(a1: v16) != 0 )
              {
                v18 = (CBaseEdict **)__RTDynamicCast(
                                       inptr: v17,
                                       VfDelta: 0,
                                       SrcType: &CBaseEntity `RTTI Type Descriptor',
                                       TargetType: &CCSPlayer `RTTI Type Descriptor',
                                       isReference: 0);
                v19 = v18;
                if ( v18 != nullptr )
                {
                  if ( v18[1221] != nullptr )
                  {
                    if ( *((_BYTE *)v18 + 84) != 0 )
                    {
                      *((_BYTE *)v18 + 88) |= 1u;
                    }
                    else
                    {
                      v20 = v18[6];
                      if ( v20 != nullptr )
                        CBaseEdict::StateChanged(this: v20, offset: 0x1314u);
                    }
                    v19[1221] = nullptr;
                  }
                  *((_BYTE *)v19 + 4860) = 0;
                  if ( v19[1222] != nullptr )
                  {
                    if ( *((_BYTE *)v19 + 84) != 0 )
                    {
                      *((_BYTE *)v19 + 88) |= 1u;
                    }
                    else
                    {
                      v21 = v19[6];
                      if ( v21 != nullptr )
                        CBaseEdict::StateChanged(this: v21, offset: 0x1318u);
                    }
                    v19[1222] = nullptr;
                  }
                }
              }
              v22 = v13->GetNumPlayers;
              v15 = ++iPlayer;
            }
            while ( v15 < v22(this: v13) );
            v1 = v33;
          }
          v23 = ++iTeam;
        }
        while ( v23 < GetNumberOfTeams() );
      }
      if ( bShouldTerminateTRBombMatch || bSwitchTo2ndHalfOfGunGameTRBombMode )
      {
        v24 = 0;
        iPlayer = 0;
        if ( GetNumberOfTeams() > 0 )
        {
          do
          {
            v25 = GetGlobalTeam(iIndex: v24);
            v26 = 0;
            if ( v25->GetNumPlayers(this: v25) > 0 )
            {
              do
              {
                v27 = v25->GetPlayer(this: v25, a2: v26);
                if ( v27 != nullptr && v27->IsPlayer(this: v27) )
                {
                  v28 = __RTDynamicCast(
                          inptr: v27,
                          VfDelta: 0,
                          SrcType: &CBaseEntity `RTTI Type Descriptor',
                          TargetType: &CCSPlayer `RTTI Type Descriptor',
                          isReference: 0);
                  if ( v28 != nullptr )
                  {
                    v28[3508] = 0;
                    *((_BYTE *)v28 + 7018) = 0;
                  }
                }
                ++v26;
              }
              while ( v26 < v25->GetNumPlayers(this: v25) );
              v24 = iPlayer;
            }
            iPlayer = ++v24;
          }
          while ( v24 < GetNumberOfTeams() );
          v1 = v33;
        }
        if ( bShouldTerminateTRBombMatch )
        {
          GoToIntermission = v1->GoToIntermission;
          v1->m_bGunGameTRBombMatchEnded = true;
          GoToIntermission(this: v1);
        }
      }
    }
    return 0;
  }
  if ( mp_winlimit.m_pParent == nullptr )
    return 0;
  v30 = mp_winlimit.m_pParent->m_Value.m_nValue;
  if ( v30 == 0 )
    return 0;
  if ( v1->m_iNumCTWins >= v30 )
  {
    UTIL_LogPrintf(fmt: "Team \"CT\" triggered \"Intermission_Win_Limit\"\n");
    v1->GoToIntermission(this: v1);
    return 1;
  }
  if ( v1->m_iNumTerroristWins < v30 )
    return 0;
  UTIL_LogPrintf(fmt: "Team \"TERRORIST\" triggered \"Intermission_Win_Limit\"\n");
  v1->GoToIntermission(this: v1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10274590
// Name: public: void CCSGameRules::CheckFreezePeriodExpired(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::CheckFreezePeriodExpired(CCSGameRules *this)
{
  float m_Value; // xmm0_4
  int v3; // eax
  int v4; // eax
  IGameEvent *v5; // eax
  int v6; // edi
  char v7; // bl
  CCSPlayer *v8; // eax
  CCSPlayer *v9; // esi
  edict_t *m_pPev; // eax
  const char *v11; // [esp-14h] [ebp-74h]
  char T_sentence[40]; // [esp+4h] [ebp-5Ch] BYREF
  char CT_sentence[40]; // [esp+2Ch] [ebp-34h] BYREF
  float startTime; // [esp+54h] [ebp-Ch]
  float v15; // [esp+58h] [ebp-8h]
  bool bCTPlayed; // [esp+5Fh] [ebp-1h]

  m_Value = this->m_fRoundStartTime.m_Value;
  v15 = m_Value;
  startTime = m_Value;
  if ( (LODWORD(m_Value) & 0x7F800000) == 0x7F800000 )
  {
    _Warning(a1: "Infinite round start time!\n");
    CGameRulesProxy::NotifyNetworkStateChanged();
    m_Value = startTime;
    this->m_fRoundStartTime.m_Value = gpGlobals->curtime;
  }
  startTime = m_Value;
  if ( (LODWORD(m_Value) & 0x7F800000) == 0x7F800000 || m_Value <= gpGlobals->curtime )
  {
    UTIL_LogPrintf(fmt: "World triggered \"Round_Start\"\n");
    v3 = random->RandomInt(this: random, a2: 0, a3: 3);
    if ( v3 != 0 )
    {
      v4 = v3 - 1;
      if ( v4 != 0 )
      {
        if ( v4 != 1 )
        {
          V_strncpy(pDest: CT_sentence, pSrc: "radio.go", maxLen: 40);
          v11 = "radio.go";
LABEL_12:
          V_strncpy(pDest: T_sentence, pSrc: v11, maxLen: 40);
          goto LABEL_13;
        }
        V_strncpy(pDest: CT_sentence, pSrc: "radio.locknload", maxLen: 40);
        V_strncpy(pDest: T_sentence, pSrc: "radio.locknload", maxLen: 40);
      }
      else
      {
        V_strncpy(pDest: CT_sentence, pSrc: "radio.letsgo", maxLen: 40);
        V_strncpy(pDest: T_sentence, pSrc: "radio.letsgo", maxLen: 40);
      }
LABEL_13:
      if ( this->m_bMapHasEscapeZone )
      {
        V_strncpy(pDest: CT_sentence, pSrc: "radio.elim", maxLen: 40);
        V_strncpy(pDest: T_sentence, pSrc: "radio.getout", maxLen: 40);
      }
      else if ( this->m_iMapHasVIPSafetyZone == 1 )
      {
        V_strncpy(pDest: CT_sentence, pSrc: "radio.vip", maxLen: 40);
        V_strncpy(pDest: T_sentence, pSrc: "radio.locknload", maxLen: 40);
      }
      if ( this->m_bFreezePeriod.m_Value )
      {
        CGameRulesProxy::NotifyNetworkStateChanged();
        this->m_bFreezePeriod.m_Value = false;
      }
      v5 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "round_freeze_end", a3: 0, a4: 0);
      if ( v5 != nullptr )
        gameeventmanager->FireEvent(this: gameeventmanager, a2: v5, a3: false);
      v6 = 1;
      v7 = 0;
      for ( bCTPlayed = false; v6 <= gpGlobals->maxClients; ++v6 )
      {
        v8 = CCSPlayer::Instance(iEnt: v6);
        v9 = v8;
        if ( v8 != nullptr )
        {
          m_pPev = v8->m_Network.m_pPev;
          if ( m_pPev != nullptr && m_pPev - gpGlobals->pEdicts != 0 && v9->m_iPlayerState.m_Value == STATE_ACTIVE )
          {
            if ( CBaseEntity::GetTeamNumber(this: v9) != 3 || bCTPlayed )
            {
              if ( CBaseEntity::GetTeamNumber(this: v9) == 2 && v7 == 0 )
              {
                CCSPlayer::Radio(this: v9, pszRadioSound: T_sentence, pszRadioText: nullptr);
                v7 = 1;
              }
            }
            else
            {
              CCSPlayer::Radio(this: v9, pszRadioSound: CT_sentence, pszRadioText: nullptr);
              bCTPlayed = true;
            }
          }
        }
      }
      return;
    }
    V_strncpy(pDest: CT_sentence, pSrc: "radio.moveout", maxLen: 40);
    v11 = "radio.moveout";
    goto LABEL_12;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102747D0
// Name: protected: virtual void CCSGameRules::GoToIntermission(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::GoToIntermission(CCSGameRules *this)
{
  CCSGameRules *v1; // ebx
  IGameEvent *v2; // esi
  int v3; // ebx
  CTeam *GlobalTeam; // edi
  IGameEvent_vtbl *v5; // ebx
  int v6; // eax
  float v7; // xmm0_4
  const StatsCollection_t *v8; // eax
  IGameEvent_vtbl *v9; // ebx
  int v10; // eax
  float v11; // xmm0_4
  const StatsCollection_t *TeamStats; // eax
  int i; // edi
  CBasePlayer *v14; // esi
  CCSPlayer *v15; // eax
  CCSPlayer *v16; // esi
  const char *v17; // [esp+18h] [ebp-20h]
  int v18; // [esp+1Ch] [ebp-1Ch]
  float deaths; // [esp+28h] [ebp-10h]
  int winnerIndex; // [esp+2Ch] [ebp-Ch]
  int teamIndex; // [esp+30h] [ebp-8h]
  float kills; // [esp+34h] [ebp-4h]

  v1 = this;
  _Msg(a1: "Going to intermission...\n");
  v2 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "cs_win_panel_match", a3: 0, a4: 0);
  winnerIndex = 1;
  if ( v2 == nullptr )
    goto LABEL_19;
  v3 = 2;
  teamIndex = 2;
  do
  {
    GlobalTeam = GetGlobalTeam(iIndex: v3);
    if ( GlobalTeam == nullptr )
      goto LABEL_17;
    if ( GlobalTeam->GetScore(this: GlobalTeam) <= 0 )
    {
      if ( GlobalTeam->GetScore(this: GlobalTeam) == 0 )
        winnerIndex = 1;
    }
    else
    {
      winnerIndex = v3;
    }
    kills = (float)CCSGameStats::GetTeamStats(this: &CCS_GameStats, iTeamIndex: v3)->m_iValue[2];
    deaths = (float)CCSGameStats::GetTeamStats(this: &CCS_GameStats, iTeamIndex: v3)->m_iValue[3];
    if ( v3 == 2 )
    {
      v9 = v2->__vftable;
      v10 = ((int (__thiscall *)(CTeam *, const char *))GlobalTeam->GetScore)(a1: GlobalTeam, a2: v17);
      v9->SetInt(this: v2, a2: "t_score", a3: v10);
      v11 = kills;
      if ( deaths != 0.0 )
        v11 = kills / deaths;
      ((void (__stdcall *)(const char *, float, int))v2->SetFloat)(a1: "t_kd", a2: COERCE_FLOAT(LODWORD(v11)), a3: v18);
      TeamStats = CCSGameStats::GetTeamStats(this: &CCS_GameStats, iTeamIndex: 2);
      v2->SetInt(this: v2, a2: "t_objectives_done", a3: TeamStats->m_iValue[18]);
      v18 = CCSGameStats::GetTeamStats(this: &CCS_GameStats, iTeamIndex: 2)->m_iValue[17];
      v17 = "t_money_earned";
    }
    else
    {
      if ( v3 != 3 )
        goto LABEL_17;
      v5 = v2->__vftable;
      v6 = ((int (__thiscall *)(CTeam *, const char *))GlobalTeam->GetScore)(a1: GlobalTeam, a2: v17);
      v5->SetInt(this: v2, a2: "ct_score", a3: v6);
      v7 = kills;
      if ( deaths != 0.0 )
        v7 = kills / deaths;
      ((void (__stdcall *)(const char *, float, int))v2->SetFloat)(a1: "ct_kd", a2: COERCE_FLOAT(LODWORD(v7)), a3: v18);
      v8 = CCSGameStats::GetTeamStats(this: &CCS_GameStats, iTeamIndex: 3);
      v2->SetInt(this: v2, a2: "ct_objectives_done", a3: v8->m_iValue[18]);
      v18 = CCSGameStats::GetTeamStats(this: &CCS_GameStats, iTeamIndex: 3)->m_iValue[17];
      v17 = "ct_money_earned";
    }
    ((void (__thiscall *)(IGameEvent *))v2->SetInt)(a1: v2);
    v3 = teamIndex;
LABEL_17:
    teamIndex = ++v3;
  }
  while ( v3 <= 3 );
  gameeventmanager->FireEvent(this: gameeventmanager, a2: v2, a3: false);
  v1 = this;
LABEL_19:
  CMultiplayRules::GoToIntermission(this: v1);
  for ( i = 1; i <= 64; ++i )
  {
    v14 = UTIL_PlayerByIndex(playerIndex: i);
    if ( v14 != nullptr && v14->IsPlayer(this: v14) )
    {
      v15 = (CCSPlayer *)__RTDynamicCast(
                           inptr: v14,
                           VfDelta: 0,
                           SrcType: &CBaseEntity `RTTI Type Descriptor',
                           TargetType: &CCSPlayer `RTTI Type Descriptor',
                           isReference: 0);
      v16 = v15;
      if ( v15 != nullptr )
      {
        v15->m_bVote = false;
        CCSPlayer::Unblind(this: v15);
        CBaseEntity::AddFlag(this: v16, flags: 64);
        CCSGameRules::UpdateMatchStats(this: v1, pPlayer: v16, winnerIndex);
      }
    }
  }
  if ( !v1->m_bFreezePeriod.m_Value )
  {
    CGameRulesProxy::NotifyNetworkStateChanged();
    v1->m_bFreezePeriod.m_Value = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10274A60
// Name: public: void CCSGameRules::GoToMatchRestartIntermission(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::GoToMatchRestartIntermission(CCSGameRules *this)
{
  IGameEvent *v2; // esi
  IGameEvent *v3; // esi
  int i; // edi
  CBasePlayer *v5; // esi
  CCSPlayer *v6; // eax
  CBaseEntity *v7; // esi

  this->m_bRestartVotingAllowed = false;
  v2 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "enable_restart_voting", a3: 0, a4: 0);
  if ( v2 != nullptr )
  {
    v2->SetBool(this: v2, a2: "enable", a3: this->m_bRestartVotingAllowed);
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v2, a3: false);
  }
  v3 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "cs_win_panel_round", a3: 0, a4: 0);
  if ( v3 != nullptr )
  {
    v3->SetBool(this: v3, a2: "show_timer_defend", a3: false);
    v3->SetBool(this: v3, a2: "show_timer_attack", a3: false);
    v3->SetInt(this: v3, a2: "final_event", a3: 9);
    v3->SetString(this: v3, a2: "funfact_token", a3: "#funfact_draw");
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v3, a3: false);
  }
  CMultiplayRules::GoToIntermission(this);
  for ( i = 1; i <= 64; ++i )
  {
    v5 = UTIL_PlayerByIndex(playerIndex: i);
    if ( v5 != nullptr && v5->IsPlayer(this: v5) )
    {
      v6 = (CCSPlayer *)__RTDynamicCast(
                          inptr: v5,
                          VfDelta: 0,
                          SrcType: &CBaseEntity `RTTI Type Descriptor',
                          TargetType: &CCSPlayer `RTTI Type Descriptor',
                          isReference: 0);
      v7 = v6;
      if ( v6 != nullptr )
      {
        v6->m_bVote = false;
        CCSPlayer::Unblind(this: v6);
        CBaseEntity::AddFlag(this: v7, flags: 64);
      }
    }
  }
  if ( !this->m_bFreezePeriod.m_Value )
  {
    CGameRulesProxy::NotifyNetworkStateChanged();
    this->m_bFreezePeriod.m_Value = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10274BB0
// Name: public: void CCSGameRules::CheckLevelInitialized(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::CheckLevelInitialized(CCSGameRules *this)
{
  const char *pszValue; // eax
  CBaseEntity *i; // esi
  CBaseEntity *j; // esi
  float v5; // [esp+44h] [ebp-14h]
  float v6; // [esp+44h] [ebp-14h]
  float z; // [esp+48h] [ebp-10h]
  float v8; // [esp+48h] [ebp-10h]
  int nNumSlots; // [esp+4Ch] [ebp-Ch] BYREF
  unsigned int dwRichPresenceContext; // [esp+50h] [ebp-8h] BYREF
  int nExtraSpectators; // [esp+54h] [ebp-4h] BYREF
  int savedregs; // [esp+58h] [ebp+0h] BYREF

  if ( !this->m_bLevelInitialized )
  {
    this->m_iSpawnPointCount_Terrorist = 0;
    this->m_iSpawnPointCount_CT = 0;
    pszValue = gpGlobals->mapname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    nNumSlots = 2;
    nExtraSpectators = 2;
    dwRichPresenceContext = 0xFFFF;
    if ( pszValue != nullptr )
      g_pGameTypes->GetMapInfo(
        this: g_pGameTypes,
        a2: pszValue,
        a3: &nNumSlots,
        a4: &nExtraSpectators,
        a5: &dwRichPresenceContext);
    if ( this->m_iSpectatorSlotCount.m_Value != nExtraSpectators )
    {
      CGameRulesProxy::NotifyNetworkStateChanged();
      this->m_iSpectatorSlotCount.m_Value = nExtraSpectators;
    }
    for ( i = CGlobalEntityList::FindEntityByClassname(
                this: &gEntList,
                pStartEntity: nullptr,
                szName: "info_player_terrorist");
          i != nullptr;
          i = CGlobalEntityList::FindEntityByClassname(
                this: &gEntList,
                pStartEntity: i,
                szName: "info_player_terrorist") )
    {
      if ( this->IsSpawnPointValid(this, a2: i, a3: nullptr) )
      {
        ++this->m_iSpawnPointCount_Terrorist;
      }
      else
      {
        if ( (i->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: i, a2: (int)&savedregs);
        z = i->m_vecAbsOrigin.z;
        if ( (i->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: i, a2: (int)&savedregs);
        v5 = i->m_vecAbsOrigin.z;
        if ( (i->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: i, a2: (int)&savedregs);
        _Warning(a1: "Invalid terrorist spawnpoint at (%.1f,%.1f,%.1f)\n", i->m_vecAbsOrigin.x, v5, z);
      }
    }
    for ( j = CGlobalEntityList::FindEntityByClassname(
                this: &gEntList,
                pStartEntity: i,
                szName: "info_player_counterterrorist");
          j != nullptr;
          j = CGlobalEntityList::FindEntityByClassname(
                this: &gEntList,
                pStartEntity: j,
                szName: "info_player_counterterrorist") )
    {
      if ( this->IsSpawnPointValid(this, a2: j, a3: nullptr) )
      {
        ++this->m_iSpawnPointCount_CT;
      }
      else
      {
        if ( (j->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: j, a2: (int)&savedregs);
        v6 = j->m_vecAbsOrigin.z;
        if ( (j->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: j, a2: (int)&savedregs);
        v8 = j->m_vecAbsOrigin.z;
        if ( (j->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: j, a2: (int)&savedregs);
        _Warning(a1: "Invalid counterterrorist spawnpoint at (%.1f,%.1f,%.1f)\n", j->m_vecAbsOrigin.x, v8, v6);
      }
    }
    if ( CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: nullptr, szName: "info_player_logo") != nullptr
      && !this->m_bLogoMap.m_Value )
    {
      CGameRulesProxy::NotifyNetworkStateChanged();
      this->m_bLogoMap.m_Value = true;
    }
    this->m_bLevelInitialized = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10274E40
// Name: public: bool CCSGameRules::TeamFull(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSGameRules::TeamFull(CCSGameRules *this, int team_id)
{
  CTeam *GlobalTeam; // eax

  CCSGameRules::CheckLevelInitialized(this);
  if ( team_id == 1 )
  {
    GlobalTeam = GetGlobalTeam(iIndex: 1);
    return GlobalTeam->GetNumPlayers(this: GlobalTeam) >= this->m_iSpectatorSlotCount.m_Value;
  }
  else if ( team_id == 2 )
  {
    return this->m_iNumTerrorist >= this->m_iSpawnPointCount_Terrorist;
  }
  else
  {
    return team_id == 3 && this->m_iNumCT >= this->m_iSpawnPointCount_CT;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10274EB0
// Name: public: int CCSGameRules::SelectDefaultTeam(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSGameRules::SelectDefaultTeam(CCSGameRules *this, bool ignoreBots)
{
  bool v2; // bl
  char *m_pszString; // eax
  char *v5; // eax
  int m_iNumTerrorist; // esi
  int m_iNumCT; // eax
  int v8; // esi
  __int16 m_iNumTerroristWins; // ax
  __int16 m_iNumCTWins; // cx

  v2 = ignoreBots;
  if ( ignoreBots )
  {
    if ( (cv_bot_join_team.m_nFlags & 0x1000) != 0 )
    {
      m_pszString = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = cv_bot_join_team.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)locale;
    }
    if ( m_pszString == "T" || _V_stricmp(s1: m_pszString, s2: "T") == 0 )
      goto LABEL_16;
    if ( (cv_bot_join_team.m_nFlags & 0x1000) != 0 )
    {
      v5 = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      v5 = cv_bot_join_team.m_pParent->m_Value.m_pszString;
      if ( v5 == nullptr )
        v5 = (char *)locale;
    }
    if ( v5 == "CT"
      || _V_stricmp(s1: v5, s2: "CT") == 0
      || mp_autoteambalance.m_pParent == nullptr
      || mp_autoteambalance.m_pParent->m_Value.m_nValue == 0 )
    {
LABEL_16:
      v2 = false;
    }
  }
  m_iNumTerrorist = this->m_iNumTerrorist;
  m_iNumCT = this->m_iNumCT;
  if ( v2 )
  {
    m_iNumTerrorist = UTIL_HumansOnTeam(teamID: 2, isAlive: false);
    m_iNumCT = UTIL_HumansOnTeam(teamID: 3, isAlive: false);
  }
  if ( m_iNumTerrorist >= m_iNumCT )
  {
    if ( m_iNumTerrorist <= m_iNumCT )
    {
      m_iNumTerroristWins = this->m_iNumTerroristWins;
      m_iNumCTWins = this->m_iNumCTWins;
      if ( m_iNumCTWins <= m_iNumTerroristWins )
      {
        if ( m_iNumCTWins >= m_iNumTerroristWins )
          v8 = 3 - (random->RandomInt(this: random, a2: 0, a3: 1) != 0);
        else
          v8 = 3;
      }
      else
      {
        v8 = 2;
      }
    }
    else
    {
      v8 = 3;
    }
  }
  else
  {
    v8 = 2;
  }
  if ( CCSGameRules::TeamFull(this, team_id: v8) && (v8 = (v8 == 2) + 2, CCSGameRules::TeamFull(this, team_id: v8)) )
    return 0;
  else
    return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10275000
// Name: public: void CCSGameRules::TerminateRound(float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::TerminateRound(CCSGameRules *this, float tmDelay, int iReason)
{
  int v3; // ebx
  int v4; // edi
  int v6; // esi
  int v7; // esi
  int i; // esi
  CCSPlayer *v9; // eax
  CCSFunFactMgr *m_pFunFactManager; // ecx
  IGameEvent *v11; // esi
  int m_Value; // ecx
  int j; // esi
  CCSPlayer *v14; // eax
  IGameEvent *v15; // eax
  IGameEvent *v16; // esi
  CCSGameRules *v17; // esi
  int v18; // edi
  CTeam *GlobalTeam; // ebx
  int v20; // esi
  CBasePlayer *v21; // esi
  CCSPlayer *v22; // eax
  CCSPlayer *v23; // edi
  CBaseEdict *v24; // ecx
  FunFact funfact; // [esp+Ch] [ebp-24h] BYREF
  CCSGameRules *v26; // [esp+28h] [ebp-8h]
  const char *text; // [esp+2Ch] [ebp-4h]
  int iTeam; // [esp+38h] [ebp+8h]
  int iPlayer; // [esp+3Ch] [ebp+Ch]

  v3 = iReason;
  v4 = 0;
  v26 = this;
  funfact.iPlayer = 0;
  text = "UNKNOWN";
  switch ( iReason )
  {
    case 0:
      text = "#SFUI_Notice_Target_Bombed";
      v4 = 2;
      break;
    case 1:
      text = "#SFUI_Notice_VIP_Escaped";
      v4 = 3;
      break;
    case 2:
      text = "#SFUI_Notice_VIP_Assassinated";
      v4 = 2;
      break;
    case 3:
      text = "#SFUI_Notice_Terrorists_Escaped";
      v4 = 2;
      break;
    case 4:
      text = "#SFUI_Notice_CTs_PreventEscape";
      v4 = 3;
      break;
    case 5:
      text = "#SFUI_Notice_Escaping_Terrorists_Neutralized";
      v4 = 3;
      break;
    case 6:
      text = "#SFUI_Notice_Bomb_Defused";
      v4 = 3;
      break;
    case 7:
      text = "#SFUI_Notice_CTs_Win";
      v4 = 3;
      break;
    case 8:
      text = "#SFUI_Notice_Terrorists_Win";
      v4 = 2;
      break;
    case 9:
      text = "#SFUI_Notice_Round_Draw";
      v4 = 1;
      break;
    case 10:
      text = "#SFUI_Notice_All_Hostages_Rescued";
      v4 = 3;
      break;
    case 11:
      text = "#SFUI_Notice_Target_Saved";
      v4 = 3;
      break;
    case 12:
      text = "#SFUI_Notice_Hostages_Not_Rescued";
      v4 = 2;
      break;
    case 13:
      text = "#SFUI_Notice_Terrorists_Not_Escaped";
      v4 = 3;
      break;
    case 14:
      text = "#SFUI_Notice_VIP_Not_Escaped";
      v4 = 2;
      break;
    case 15:
      text = "#SFUI_Notice_Game_Commencing";
      v4 = 1;
      break;
    default:
      DevMsg(a1: "TerminateRound: unknown round end ID %i\n", iReason);
      break;
  }
  this->m_iRoundWinStatus = v4;
  this->m_flRestartRoundTime = gpGlobals->curtime + tmDelay;
  if ( v4 == 3 )
  {
    v6 = 0;
    if ( g_Hostages.m_Size <= 0 )
      goto LABEL_27;
    do
    {
      ((void (__thiscall *)(CHostage *, const char *, _DWORD, _DWORD, _DWORD, int, int, int, _DWORD, _DWORD))g_Hostages.m_Memory.m_pMemory[v6]->AcceptInput)(
        a1: g_Hostages.m_Memory.m_pMemory[v6],
        a2: "CTsWin",
        a3: 0,
        a4: 0,
        a5: 0,
        a6: funfact.iData1,
        a7: funfact.iData2,
        a8: -1,
        a9: 0,
        a10: 0);
      ++v6;
    }
    while ( v6 < g_Hostages.m_Size );
    goto LABEL_26;
  }
  if ( v4 == 2 )
  {
    v7 = 0;
    if ( g_Hostages.m_Size > 0 )
    {
      do
      {
        ((void (__thiscall *)(CHostage *, const char *, _DWORD, _DWORD, _DWORD, int, int, int, _DWORD, _DWORD))g_Hostages.m_Memory.m_pMemory[v7]->AcceptInput)(
          a1: g_Hostages.m_Memory.m_pMemory[v7],
          a2: "TerroristsWin",
          a3: 0,
          a4: 0,
          a5: 0,
          a6: funfact.iData1,
          a7: funfact.iData2,
          a8: -1,
          a9: 0,
          a10: 0);
        ++v7;
      }
      while ( v7 < g_Hostages.m_Size );
LABEL_26:
      v3 = iReason;
    }
  }
LABEL_27:
  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v9 = (CCSPlayer *)UTIL_PlayerByIndex(playerIndex: i);
    if ( v9 != nullptr )
      CCSPlayer::HandleEndOfRound(this: v9);
  }
  CCSGameRules::ProcessEndOfRoundAchievements(this: v26, iWinnerTeam: v4, iReason: v3);
  if ( v3 != 15 )
  {
    m_pFunFactManager = v26->m_pFunFactManager;
    funfact.id = -1;
    funfact.szLocalizationToken = locale;
    memset(&funfact.iPlayer, 0, 20);
    CCSFunFactMgr::GetRoundEndFunFact(this: m_pFunFactManager, iWinningTeam: v4, iRoundResult: v3, &funfact);
    v11 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "cs_win_panel_round", a3: 0, a4: 0);
    if ( v11 != nullptr )
    {
      if ( (float)((float)((float)v26->m_iRoundTime.m_Value + v26->m_fRoundStartTime.m_Value) - gpGlobals->curtime) > 0.0 )
      {
        v11->SetBool(this: v11, a2: "show_timer_attack", a3: true);
        m_Value = (int)(float)((float)v26->m_iRoundTime.m_Value
                             - (float)((float)((float)v26->m_iRoundTime.m_Value + v26->m_fRoundStartTime.m_Value)
                                     - gpGlobals->curtime));
      }
      else
      {
        v11->SetBool(this: v11, a2: "show_timer_defend", a3: true);
        m_Value = v26->m_iRoundTime.m_Value;
      }
      v11->SetInt(this: v11, a2: "timer_time", a3: m_Value);
      v11->SetInt(this: v11, a2: "final_event", a3: v3);
      v11->SetString(this: v11, a2: "funfact_token", a3: funfact.szLocalizationToken);
      v11->SetInt(this: v11, a2: "funfact_player", a3: funfact.iPlayer);
      v11->SetInt(this: v11, a2: "funfact_data1", a3: funfact.iData1);
      v11->SetInt(this: v11, a2: "funfact_data2", a3: funfact.iData2);
      v11->SetInt(this: v11, a2: "funfact_data3", a3: funfact.iData3);
      gameeventmanager->FireEvent(this: gameeventmanager, a2: v11, a3: false);
    }
  }
  for ( j = 1; j <= gpGlobals->maxClients; ++j )
  {
    v14 = (CCSPlayer *)UTIL_PlayerByIndex(playerIndex: j);
    if ( v14 != nullptr )
      CCSPlayer::OnRoundEnd(this: v14, winningTeam: v4, reason: v3);
  }
  v15 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "round_end", a3: 0, a4: 0);
  v16 = v15;
  if ( v15 != nullptr )
  {
    v15->SetInt(this: v15, a2: "winner", a3: v4);
    v16->SetInt(this: v16, a2: "reason", a3: v3);
    v16->SetString(this: v16, a2: "message", a3: text);
    v16->SetInt(this: v16, a2: "priority", a3: 6);
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v16, a3: false);
  }
  v17 = v26;
  if ( CCSGameRules::GetMapRemainingTime(this: v26) == 0.0 )
  {
    if ( (UTIL_LogPrintf(fmt: "World triggered \"Intermission_Time_Limit\"\n"),
          v17->GoToIntermission(this: v17),
          g_pGameTypes->GetCurrentGameType(this: g_pGameTypes) == 1)
      && g_pGameTypes->GetCurrentGameMode(this: g_pGameTypes) == 2
      || g_pGameTypes->GetCurrentGameType(this: g_pGameTypes) == 1
      && g_pGameTypes->GetCurrentGameMode(this: g_pGameTypes) == 0 )
    {
      v18 = 0;
      iTeam = 0;
      if ( GetNumberOfTeams() > 0 )
      {
        do
        {
          GlobalTeam = GetGlobalTeam(iIndex: v18);
          v20 = 0;
          iPlayer = 0;
          if ( GlobalTeam->GetNumPlayers(this: GlobalTeam) > 0 )
          {
            do
            {
              v21 = GlobalTeam->GetPlayer(this: GlobalTeam, a2: v20);
              if ( v21 != nullptr && v21->IsPlayer(this: v21) )
              {
                v22 = (CCSPlayer *)__RTDynamicCast(
                                     inptr: v21,
                                     VfDelta: 0,
                                     SrcType: &CBaseEntity `RTTI Type Descriptor',
                                     TargetType: &CCSPlayer `RTTI Type Descriptor',
                                     isReference: 0);
                v23 = v22;
                if ( v22 != nullptr )
                {
                  if ( v22->m_iGunGameProgressiveWeaponIndex.m_Value != 0 )
                  {
                    if ( v22->m_Network.m_TimerEvent.m_bRegistered )
                    {
                      *((_BYTE *)&v22->m_Network + 76) |= 1u;
                    }
                    else
                    {
                      v24 = &v22->m_Network.m_pPev->CBaseEdict;
                      if ( v24 != nullptr )
                        CBaseEdict::StateChanged(this: v24, offset: 0x1314u);
                    }
                    v23->m_iGunGameProgressiveWeaponIndex.m_Value = 0;
                  }
                  v23->m_bShouldProgressGunGameTRBombModeWeapon = false;
                  CCSPlayer::ResetTRBombModeData(this: v23);
                }
              }
              v20 = ++iPlayer;
            }
            while ( iPlayer < GlobalTeam->GetNumPlayers(this: GlobalTeam) );
            v18 = iTeam;
          }
          iTeam = ++v18;
        }
        while ( v18 < GetNumberOfTeams() );
        v17 = v26;
      }
      v17->m_bGunGameTRBombMatchEnded = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10275640
// Name: public: void CCSGameRules::CheckMapConditions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::CheckMapConditions(CCSGameRules *this)
{
  if ( CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: nullptr, szName: "func_bomb_target") != nullptr )
  {
    if ( !this->m_bMapHasBombTarget.m_Value )
    {
      CGameRulesProxy::NotifyNetworkStateChanged();
      this->m_bMapHasBombTarget.m_Value = true;
    }
    this->m_bMapHasBombZone = true;
  }
  else
  {
    if ( CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: nullptr, szName: "info_bomb_target") != nullptr )
    {
      if ( !this->m_bMapHasBombTarget.m_Value )
      {
        CGameRulesProxy::NotifyNetworkStateChanged();
        this->m_bMapHasBombTarget.m_Value = true;
      }
    }
    else if ( this->m_bMapHasBombTarget.m_Value )
    {
      CGameRulesProxy::NotifyNetworkStateChanged();
      this->m_bMapHasBombTarget.m_Value = false;
    }
    this->m_bMapHasBombZone = false;
  }
  this->m_bMapHasBuyZone = CGlobalEntityList::FindEntityByClassname(
                             this: &gEntList,
                             pStartEntity: nullptr,
                             szName: "func_buyzone") != nullptr;
  if ( CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: nullptr, szName: "func_hostage_rescue") != nullptr )
  {
    if ( !this->m_bMapHasRescueZone.m_Value )
    {
      CGameRulesProxy::NotifyNetworkStateChanged();
      this->m_bMapHasRescueZone.m_Value = true;
    }
  }
  else if ( this->m_bMapHasRescueZone.m_Value )
  {
    CGameRulesProxy::NotifyNetworkStateChanged();
    this->m_bMapHasRescueZone.m_Value = false;
  }
  this->m_bMapHasEscapeZone = CGlobalEntityList::FindEntityByClassname(
                                this: &gEntList,
                                pStartEntity: nullptr,
                                szName: "func_escapezone") != nullptr;
  this->m_iMapHasVIPSafetyZone = 2
                               - (CGlobalEntityList::FindEntityByClassname(
                                    this: &gEntList,
                                    pStartEntity: nullptr,
                                    szName: "func_vip_safetyzone") != nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10275760
// Name: public: static void CCSGameRules::EndRound(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CCSGameRules::EndRound()
{
  CCSGameRules::TerminateRound(this: (CCSGameRules *)g_pGameRules, tmDelay: 0.0, iReason: 9);
}

//------------------------------------------------------------------------------
// Address: 0x10275780
// Name: public: virtual void CCSGameRules::LevelInitPostEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::LevelInitPostEntity(CCSGameRules *this)
{
  this->m_bLevelInitialized = false;
  CCSGameRules::CheckMapConditions(this);
}

//------------------------------------------------------------------------------
// Address: 0x10275790
// Name: public: bool CCSGameRules::NeededPlayersCheck(bool __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSGameRules::NeededPlayersCheck(CCSGameRules *this, bool *bNeededPlayers)
{
  if ( this->m_iNumSpawnableTerrorist == 0 || this->m_iNumSpawnableCT == 0 )
  {
    _Msg(a1: "Game will not start until both teams have players.\n");
    UTIL_ClientPrintAll(
      msg_dest: 2,
      msg_name: "#SFUI_Notice_Game_scoring",
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
    *bNeededPlayers = true;
    this->m_bFirstConnected = false;
  }
  if ( this->m_bFirstConnected || this->m_iNumSpawnableTerrorist == 0 || this->m_iNumSpawnableCT == 0 )
    return 0;
  if ( this->m_bFreezePeriod.m_Value )
  {
    CGameRulesProxy::NotifyNetworkStateChanged();
    this->m_bFreezePeriod.m_Value = false;
  }
  this->m_bCompleteReset = true;
  CCSGameRules::TerminateRound(this, tmDelay: 3.0, iReason: 15);
  this->m_bFirstConnected = true;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10275840
// Name: public: bool CCSGameRules::HostageRescueRoundEndCheck(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSGameRules::HostageRescueRoundEndCheck(CCSGameRules *this, bool bNeededPlayers)
{
  int m_Size; // edi
  CCSGameRules *v3; // eax
  int v4; // ebx
  int i; // esi
  CHostage *v6; // ecx
  bool v7; // zf
  IGameEvent *v8; // eax

  m_Size = g_Hostages.m_Size;
  v3 = this;
  v4 = 0;
  for ( i = 0; i < m_Size; ++i )
  {
    v6 = g_Hostages.m_Memory.m_pMemory[i];
    if ( v6->m_iHealth.m_Value > 0 )
    {
      v7 = !CHostage::IsRescued(this: v6);
      v3 = this;
      if ( v7 )
        ++v4;
    }
  }
  if ( v3->m_iHostagesRemaining.m_Value != v4 )
  {
    CGameRulesProxy::NotifyNetworkStateChanged();
    this->m_iHostagesRemaining.m_Value = v4;
    v3 = this;
  }
  if ( v4 != 0 || m_Size <= 0 || (double)v3->m_iHostagesRescued < (double)m_Size * 0.5 )
    return 0;
  v3->m_iAccountCT += 1500;
  if ( !bNeededPlayers )
  {
    ++v3->m_iNumCTWins;
    CCSGameRules::UpdateTeamScores(this: v3);
  }
  CCSGameStats::Event_AllHostagesRescued(this: &CCS_GameStats);
  v8 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "hostage_rescued_all", a3: 0, a4: 0);
  if ( v8 != nullptr )
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v8, a3: false);
  CCSGameRules::TerminateRound(this, tmDelay: mp_round_restart_delay.m_pParent->m_Value.m_fValue, iReason: 10);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10275950
// Name: public: bool CCSGameRules::GunGameProgressiveEndCheck(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSGameRules::GunGameProgressiveEndCheck(CCSGameRules *this)
{
  int v2; // edi
  CTeam *GlobalTeam; // esi
  int v4; // ebx
  CBasePlayer *v5; // edi
  int v6; // edi
  CTeam *v7; // esi
  int v8; // ebx
  CBasePlayer *v9; // edi
  _BYTE *v10; // eax
  float tmDelay; // xmm0_4
  int v12; // eax
  int v13; // esi
  CTeam *v14; // edi
  int v15; // ebx
  int v16; // eax
  void *v17; // esi
  CBasePlayer *v18; // eax
  CCSPlayer *v19; // esi
  int iTeam; // [esp+20h] [ebp-Ch]
  int iTeama; // [esp+20h] [ebp-Ch]
  int delayTime; // [esp+24h] [ebp-8h]
  bool bReturnValue; // [esp+2Bh] [ebp-1h]

  bReturnValue = false;
  if ( this->m_bGunGameTRBombMatchEnded )
    return false;
  if ( g_pGameTypes->GetCurrentGameType(this: g_pGameTypes) == 1
    && g_pGameTypes->GetCurrentGameMode(this: g_pGameTypes) == 0 )
  {
    v2 = 0;
    for ( delayTime = 0; v2 < GetNumberOfTeams(); delayTime = v2 )
    {
      GlobalTeam = GetGlobalTeam(iIndex: v2);
      v4 = 0;
      if ( GlobalTeam->GetNumPlayers(this: GlobalTeam) > 0 )
      {
        do
        {
          v5 = GlobalTeam->GetPlayer(this: GlobalTeam, a2: v4);
          if ( v5 != nullptr && v5->IsPlayer(this: v5) )
            __RTDynamicCast(
              inptr: v5,
              VfDelta: 0,
              SrcType: &CBaseEntity `RTTI Type Descriptor',
              TargetType: &CCSPlayer `RTTI Type Descriptor',
              isReference: 0);
          ++v4;
        }
        while ( v4 < GlobalTeam->GetNumPlayers(this: GlobalTeam) );
        v2 = delayTime;
      }
      ++v2;
    }
    v6 = 0;
    iTeam = 0;
    if ( GetNumberOfTeams() > 0 )
    {
      do
      {
        v7 = GetGlobalTeam(iIndex: v6);
        v8 = 0;
        if ( v7->GetNumPlayers(this: v7) > 0 )
        {
          do
          {
            v9 = v7->GetPlayer(this: v7, a2: v8);
            if ( v9 != nullptr && v9->IsPlayer(this: v9) )
            {
              v10 = __RTDynamicCast(
                      inptr: v9,
                      VfDelta: 0,
                      SrcType: &CBaseEntity `RTTI Type Descriptor',
                      TargetType: &CCSPlayer `RTTI Type Descriptor',
                      isReference: 0);
              if ( v10 != nullptr && v10[4846] != 0 )
              {
                if ( g_pGameTypes->GetCurrentGameType(this: g_pGameTypes) != 1
                  || g_pGameTypes->GetCurrentGameMode(this: g_pGameTypes) != 0 )
                {
                  tmDelay = mp_round_restart_delay.m_pParent->m_Value.m_fValue;
                }
                else
                {
                  tmDelay = mp_ggprogressive_round_restart_delay.m_pParent->m_Value.m_fValue;
                }
                this->m_bCompleteReset = true;
                v12 = v7->GetTeamNumber(this: v7);
                CCSGameRules::TerminateRound(this, tmDelay, iReason: (v12 != 3) + 7);
                bReturnValue = true;
              }
            }
            ++v8;
          }
          while ( v8 < v7->GetNumPlayers(this: v7) );
          v6 = iTeam;
        }
        iTeam = ++v6;
      }
      while ( v6 < GetNumberOfTeams() );
      if ( bReturnValue )
      {
        v13 = 0;
        for ( iTeama = 0; v13 < GetNumberOfTeams(); iTeama = v13 )
        {
          v14 = GetGlobalTeam(iIndex: v13);
          v15 = 0;
          if ( v14->GetNumPlayers(this: v14) > 0 )
          {
            do
            {
              v16 = (int)v14->GetPlayer(this: v14, a2: v15);
              v17 = (void *)v16;
              if ( v16 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v16 + 336))(a1: v16) != 0 )
              {
                v18 = (CBasePlayer *)__RTDynamicCast(
                                       inptr: v17,
                                       VfDelta: 0,
                                       SrcType: &CBaseEntity `RTTI Type Descriptor',
                                       TargetType: &CCSPlayer `RTTI Type Descriptor',
                                       isReference: 0);
                v19 = (CCSPlayer *)v18;
                if ( v18 != nullptr )
                {
                  CBasePlayer::LockPlayerInPlace(this: v18);
                  v19->m_bVote = false;
                  CCSPlayer::Unblind(this: v19);
                }
              }
              ++v15;
            }
            while ( v15 < v14->GetNumPlayers(this: v14) );
            v13 = iTeama;
          }
          ++v13;
        }
      }
    }
  }
  return bReturnValue;
}

//------------------------------------------------------------------------------
// Address: 0x10275C10
// Name: public: bool CCSGameRules::VIPRoundEndCheck(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSGameRules::VIPRoundEndCheck(CCSGameRules *this, bool bNeededPlayers)
{
  unsigned int m_Index; // ecx
  int v5; // eax
  CEntInfo *v6; // edx
  unsigned int v7; // ecx
  IHandleEntity *m_pEntity; // edx
  IGameEvent *v9; // esi
  CBaseEntity *v10; // eax
  int v11; // eax
  unsigned int v12; // eax
  CCSPlayer *v13; // ecx
  bool v14; // zf
  CEntInfo *v15; // eax
  IHandleEntity *v16; // eax
  IGameEvent *v17; // esi
  CBaseEntity *v18; // eax
  int v19; // eax

  if ( this->m_iMapHasVIPSafetyZone != 1 )
    return 0;
  m_Index = this->m_pVIP.m_Index;
  if ( m_Index != -1 )
  {
    v5 = (unsigned __int16)m_Index;
    v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v7 = HIWORD(m_Index);
    if ( v6->m_SerialNumber == v7 && v6->m_pEntity != nullptr )
    {
      if ( g_pEntityList->m_EntPtrArray[v5].m_SerialNumber == v7 )
        m_pEntity = g_pEntityList->m_EntPtrArray[v5].m_pEntity;
      else
        m_pEntity = nullptr;
      if ( BYTE1(m_pEntity[1225].__vftable) == 1 )
      {
        this->m_iAccountCT += 3500;
        if ( !bNeededPlayers )
        {
          ++this->m_iNumCTWins;
          CCSGameRules::UpdateTeamScores(this);
        }
        v9 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "vip_escaped", a3: 0, a4: 0);
        if ( v9 != nullptr )
        {
          v10 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_pVIP);
          v11 = engine->GetPlayerUserId(this: engine, a2: v10->m_Network.m_pPev);
          v9->SetInt(this: v9, a2: "userid", a3: v11);
          v9->SetInt(this: v9, a2: "priority", a3: 9);
          gameeventmanager->FireEvent(this: gameeventmanager, a2: v9, a3: false);
        }
        v12 = this->m_pVIP.m_Index;
        if ( v12 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber != HIWORD(v12) )
          v13 = nullptr;
        else
          v13 = (CCSPlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_pEntity;
        CCSPlayer::IncrementNumMVPs(this: v13, mvpReason: CSMVP_UNDEFINED);
        CCSGameRules::TerminateRound(this, tmDelay: mp_round_restart_delay.m_pParent->m_Value.m_fValue, iReason: 1);
        return 1;
      }
      v14 = g_pEntityList->m_EntPtrArray[v5].m_SerialNumber == v7;
      v15 = &g_pEntityList->m_EntPtrArray[v5];
      v16 = v14 ? v15->m_pEntity : nullptr;
      if ( BYTE1(v16[138].__vftable) == 2 )
      {
        this->m_iAccountTerrorist += 3250;
        if ( !bNeededPlayers )
        {
          ++this->m_iNumTerroristWins;
          CCSGameRules::UpdateTeamScores(this);
        }
        v17 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "vip_killed", a3: 0, a4: 0);
        if ( v17 != nullptr )
        {
          v18 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_pVIP);
          v19 = engine->GetPlayerUserId(this: engine, a2: v18->m_Network.m_pPev);
          v17->SetInt(this: v17, a2: "userid", a3: v19);
          v17->SetInt(this: v17, a2: "priority", a3: 9);
          gameeventmanager->FireEvent(this: gameeventmanager, a2: v17, a3: false);
        }
        CCSGameRules::TerminateRound(this, tmDelay: mp_round_restart_delay.m_pParent->m_Value.m_fValue, iReason: 2);
        return 1;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10275E30
// Name: public: bool CCSGameRules::BombRoundEndCheck(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSGameRules::BombRoundEndCheck(CCSGameRules *this, bool bNeededPlayers)
{
  if ( this->m_bTargetBombed && this->m_bMapHasBombTarget.m_Value )
  {
    this->m_iAccountTerrorist += 2500;
    if ( !bNeededPlayers )
    {
      ++this->m_iNumTerroristWins;
      CCSGameRules::UpdateTeamScores(this);
    }
    CCSGameRules::TerminateRound(this, tmDelay: mp_round_restart_delay.m_pParent->m_Value.m_fValue, iReason: 0);
    return 1;
  }
  else if ( this->m_bBombDefused && this->m_bMapHasBombTarget.m_Value )
  {
    this->m_iAccountCT += 2250;
    this->m_iAccountTerrorist += 800;
    if ( !bNeededPlayers )
    {
      ++this->m_iNumCTWins;
      CCSGameRules::UpdateTeamScores(this);
    }
    CCSGameRules::TerminateRound(this, tmDelay: mp_round_restart_delay.m_pParent->m_Value.m_fValue, iReason: 6);
    return 1;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10275EF0
// Name: public: bool CCSGameRules::TeamExterminationCheck(int,int,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSGameRules::TeamExterminationCheck(
        CCSGameRules *this,
        int NumAliveTerrorist,
        int NumAliveCT,
        int NumDeadTerrorist,
        int NumDeadCT,
        bool bNeededPlayers)
{
  char v7; // dl
  int v8; // eax

  if ( this->m_iNumCT <= 0
    || this->m_iNumSpawnableCT <= 0
    || this->m_iNumTerrorist <= 0
    || this->m_iNumSpawnableTerrorist <= 0 )
  {
    if ( NumAliveCT == 0 && NumAliveTerrorist == 0 )
    {
      CCSGameRules::TerminateRound(this, tmDelay: mp_round_restart_delay.m_pParent->m_Value.m_fValue, iReason: 9);
      return 1;
    }
    return 0;
  }
  if ( NumAliveTerrorist == 0 && NumDeadTerrorist != 0 )
  {
    v7 = 0;
    v8 = 0;
    if ( g_PlantedC4s.m_Size <= 0 )
      goto LABEL_12;
    do
    {
      if ( g_PlantedC4s.m_Memory.m_pMemory[v8]->m_bBombTicking.m_Value )
        v7 = 1;
      ++v8;
    }
    while ( v8 < g_PlantedC4s.m_Size );
    if ( v7 == 0 )
    {
LABEL_12:
      if ( this->m_bMapHasBombTarget.m_Value )
        this->m_iAccountCT += 2250;
      else
        this->m_iAccountCT += 2000;
      if ( !bNeededPlayers )
      {
        ++this->m_iNumCTWins;
        CCSGameRules::UpdateTeamScores(this);
      }
      CCSGameRules::TerminateRound(this, tmDelay: mp_round_restart_delay.m_pParent->m_Value.m_fValue, iReason: 7);
      return 1;
    }
  }
  if ( NumAliveCT != 0 || NumDeadCT == 0 )
    return 0;
  if ( this->m_bMapHasBombTarget.m_Value )
    this->m_iAccountTerrorist += 2250;
  else
    this->m_iAccountTerrorist += 2000;
  if ( !bNeededPlayers )
  {
    ++this->m_iNumTerroristWins;
    CCSGameRules::UpdateTeamScores(this);
  }
  CCSGameRules::TerminateRound(this, tmDelay: mp_round_restart_delay.m_pParent->m_Value.m_fValue, iReason: 8);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10276060
// Name: public: void CCSGameRules::UpdateVoteStatus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::UpdateVoteStatus(CCSGameRules *this)
{
  CCSGameRules *v1; // esi
  int v2; // ebx
  int v3; // edi
  CBasePlayer *v4; // eax
  CBasePlayer *v5; // esi
  _BYTE *v6; // eax
  _BYTE *v7; // esi
  float percentOfVotesNeeded; // [esp+0h] [ebp-10h]
  int minimumVoters; // [esp+8h] [ebp-8h]
  int numVotes; // [esp+Ch] [ebp-4h]

  v1 = this;
  if ( gpGlobals->curtime > this->m_voteEndTime && this->m_currentVote != VoteType_None )
    CCSGameRules::CloseVote(this);
  v2 = 0;
  numVotes = 0;
  percentOfVotesNeeded = mp_required_vote_majority.m_pParent->m_Value.m_fValue;
  if ( mp_required_voters.m_pParent != nullptr )
    minimumVoters = mp_required_voters.m_pParent->m_Value.m_nValue;
  else
    minimumVoters = 0;
  v3 = 1;
  if ( gpGlobals->maxClients >= 1 )
  {
    do
    {
      v4 = UTIL_PlayerByIndex(playerIndex: v3);
      v5 = v4;
      if ( v4 != nullptr && v4->IsPlayer(this: v4) )
      {
        v6 = __RTDynamicCast(
               inptr: v5,
               VfDelta: 0,
               SrcType: &CBaseEntity `RTTI Type Descriptor',
               TargetType: &CCSPlayer `RTTI Type Descriptor',
               isReference: 0);
        v7 = v6;
        if ( v6 != nullptr && (*(unsigned __int8 (__thiscall **)(_BYTE *))(*(_DWORD *)v6 + 1912))(a1: v6) == 0 )
        {
          ++v2;
          if ( v7[6876] != 0 )
            ++numVotes;
        }
      }
      ++v3;
    }
    while ( v3 <= gpGlobals->maxClients );
    v1 = this;
  }
  if ( v2 >= minimumVoters && (float)numVotes >= (float)((float)v2 * percentOfVotesNeeded) )
  {
    if ( v1->m_currentVote == VoteType_RestartMatch )
      CCSGameRules::GoToMatchRestartIntermission(this: v1);
    CCSGameRules::CloseVote(this: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10276170
// Name: public: void CCSGameRules::CheckRoundTimeExpired(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::CheckRoundTimeExpired(CCSGameRules *this)
{
  if ( (mp_ignore_round_win_conditions.m_pParent == nullptr
     || mp_ignore_round_win_conditions.m_pParent->m_Value.m_nValue == 0)
    && (float)((float)((float)this->m_iRoundTime.m_Value + this->m_fRoundStartTime.m_Value) - gpGlobals->curtime) <= 0.0
    && this->m_iRoundWinStatus == 0
    && this->m_bFirstConnected )
  {
    if ( this->m_bMapHasBombTarget.m_Value )
    {
      if ( !this->m_bBombPlanted )
      {
        this->m_iAccountCT += 2250;
        ++this->m_iNumCTWins;
        CCSGameRules::TerminateRound(this, tmDelay: mp_round_restart_delay.m_pParent->m_Value.m_fValue, iReason: 11);
        CCSGameRules::UpdateTeamScores(this);
        CCSGameRules::MarkLivingPlayersOnTeamAsNotReceivingMoneyNextRound(this, team: 2);
      }
    }
    else if ( this->m_bMapHasRescueZone.m_Value )
    {
      this->m_iAccountTerrorist += 2250;
      ++this->m_iNumTerroristWins;
      CCSGameRules::TerminateRound(this, tmDelay: mp_round_restart_delay.m_pParent->m_Value.m_fValue, iReason: 12);
      CCSGameRules::UpdateTeamScores(this);
      CCSGameRules::MarkLivingPlayersOnTeamAsNotReceivingMoneyNextRound(this, team: 3);
    }
    else if ( this->m_bMapHasEscapeZone )
    {
      ++this->m_iNumCTWins;
      CCSGameRules::TerminateRound(this, tmDelay: mp_round_restart_delay.m_pParent->m_Value.m_fValue, iReason: 13);
      CCSGameRules::UpdateTeamScores(this);
    }
    else if ( this->m_iMapHasVIPSafetyZone == 1 )
    {
      this->m_iAccountTerrorist += 2250;
      ++this->m_iNumTerroristWins;
      CCSGameRules::TerminateRound(this, tmDelay: mp_round_restart_delay.m_pParent->m_Value.m_fValue, iReason: 14);
      CCSGameRules::UpdateTeamScores(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102762D0
// Name: public: bool SetHumanTeamFunctor::operator()(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall SetHumanTeamFunctor::operator()(SetHumanTeamFunctor *this, CBasePlayer *basePlayer)
{
  CCSPlayer *v3; // esi
  int m_targetTeam; // ebx

  if ( basePlayer == nullptr )
    return 1;
  if ( !basePlayer->IsPlayer(this: basePlayer) )
    return 1;
  v3 = (CCSPlayer *)__RTDynamicCast(
                      inptr: basePlayer,
                      VfDelta: 0,
                      SrcType: &CBaseEntity `RTTI Type Descriptor',
                      TargetType: &CCSPlayer `RTTI Type Descriptor',
                      isReference: 0);
  if ( v3 == nullptr
    || v3->IsBot(this: v3)
    || CBaseEntity::GetTeamNumber(this: v3) != this->m_sourceTeam
    || v3->m_iPlayerState.m_Value == STATE_PICKINGCLASS )
  {
    return 1;
  }
  if ( CCSGameRules::TeamFull(this: (CCSGameRules *)g_pGameRules, team_id: this->m_targetTeam) )
    return 0;
  m_targetTeam = this->m_targetTeam;
  if ( CCSGameRules::TeamStacked(
         this: (CCSGameRules *)g_pGameRules,
         newTeam_id: this->m_targetTeam,
         curTeam_id: this->m_sourceTeam) )
  {
    return 0;
  }
  CCSPlayer::SwitchTeam(this: v3, iTeamNum: m_targetTeam);
  CRecipientFilter::AddRecipient(this: &this->m_traitors, player: v3);
  CRecipientFilter::RemoveRecipient(this: &this->m_loyalists, player: (signed int)v3);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102763A0
// Name: public: void CCSGameRules::BalanceTeams(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::BalanceTeams(CCSGameRules *this)
{
  bool v2; // zf
  int m_iNumCT; // edi
  int m_iNumTerrorist; // esi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // ecx
  int v9; // edx
  CCSGameRules *v10; // esi
  int v11; // edi
  CCSPlayer *v12; // ebx
  int v13; // eax
  bool v14; // sf
  bool v15; // of
  int v16; // ecx
  CTeam *GlobalTeam; // eax
  int v18; // eax
  CBasePlayer *v19; // eax
  CBasePlayer *v20; // esi
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  int TeamNumber; // eax
  CRecipientFilter traitors; // [esp+Ch] [ebp-58h] BYREF
  CRecipientFilter loyalists; // [esp+2Ch] [ebp-38h] BYREF
  int i; // [esp+4Ch] [ebp-18h]
  CCSGameRules *v27; // [esp+50h] [ebp-14h]
  int iTragetTeam; // [esp+54h] [ebp-10h]
  int j; // [esp+58h] [ebp-Ch]
  int iTeamToSwap; // [esp+5Ch] [ebp-8h]
  int iNumToSwap; // [esp+60h] [ebp-4h]

  v2 = this->m_iMapHasVIPSafetyZone == 1;
  v27 = this;
  if ( v2 )
  {
    m_iNumCT = this->m_iNumCT;
    m_iNumTerrorist = this->m_iNumTerrorist;
    v5 = m_iNumTerrorist + m_iNumCT;
    if ( (m_iNumTerrorist + m_iNumCT) % 2 != 0 )
      v6 = 1 - (int)((double)v5 * -0.55);
    else
      v6 = v5 / 2;
    if ( m_iNumCT >= v6 )
    {
      if ( m_iNumTerrorist >= m_iNumTerrorist + m_iNumCT - v6 )
        return;
      iTeamToSwap = 3;
      iNumToSwap = m_iNumCT - v6;
      goto LABEL_15;
    }
    v7 = v6 - m_iNumCT;
    goto LABEL_13;
  }
  v8 = this->m_iNumCT;
  v9 = this->m_iNumTerrorist;
  if ( v9 >= v8 )
  {
    if ( v9 <= v8 )
      return;
    v7 = (v9 - v8) / 2;
LABEL_13:
    iTeamToSwap = 2;
    goto LABEL_14;
  }
  iTeamToSwap = 3;
  v7 = (v8 - v9) / 2;
LABEL_14:
  iNumToSwap = v7;
LABEL_15:
  if ( iNumToSwap > 3 )
    iNumToSwap = 3;
  if ( iTeamToSwap == 3 )
    iTragetTeam = 2;
  else
    iTragetTeam = 3;
  CRecipientFilter::CRecipientFilter(this: &traitors);
  CRecipientFilter::CRecipientFilter(this: &loyalists);
  CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&traitors);
  CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&loyalists);
  CRecipientFilter::AddAllPlayers(this: &loyalists);
  i = 0;
  if ( iNumToSwap > 0 )
  {
    while ( 1 )
    {
      v10 = v27;
      v11 = -1;
      v12 = nullptr;
      CCSGameRules::CheckLevelInitialized(this: v27);
      if ( iTragetTeam == 1 )
        break;
      if ( iTragetTeam == 2 )
      {
        v16 = v10->m_iNumTerrorist;
        v15 = __OFSUB__(v16, v10->m_iSpawnPointCount_Terrorist);
        v14 = v16 - v10->m_iSpawnPointCount_Terrorist < 0;
        goto LABEL_27;
      }
      if ( iTragetTeam == 3 )
      {
        v13 = v10->m_iNumCT;
        v15 = __OFSUB__(v13, v10->m_iSpawnPointCount_CT);
        v14 = v13 - v10->m_iSpawnPointCount_CT < 0;
        goto LABEL_27;
      }
LABEL_28:
      j = 1;
      if ( gpGlobals->maxClients >= 1 )
      {
        do
        {
          v19 = UTIL_PlayerByIndex(playerIndex: j);
          v20 = v19;
          if ( v19 != nullptr
            && __RTDynamicCast(
                 inptr: v19,
                 VfDelta: 0,
                 SrcType: &CCSPlayer `RTTI Type Descriptor',
                 TargetType: &CCSBot `RTTI Type Descriptor',
                 isReference: 0) == nullptr )
          {
            m_Index = v27->m_pVIP.m_Index;
            if ( m_Index == -1
              || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
            {
              m_pEntity = nullptr;
            }
            else
            {
              m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
            }
            if ( m_pEntity != v20 )
            {
              TeamNumber = CBaseEntity::GetTeamNumber(this: v20);
              if ( TeamNumber == iTeamToSwap
                && engine->GetPlayerUserId(this: engine, a2: v20->m_Network.m_pPev) > v11
                && LODWORD(v20[1].m_flPrevAnimTime) != 3 )
              {
                v11 = engine->GetPlayerUserId(this: engine, a2: v20->m_Network.m_pPev);
                v12 = (CCSPlayer *)v20;
              }
            }
          }
          ++j;
        }
        while ( j <= gpGlobals->maxClients );
        if ( v12 != nullptr )
        {
          CRecipientFilter::AddRecipient(this: &traitors, player: v12);
          CRecipientFilter::RemoveRecipient(this: &loyalists, player: (signed int)v12);
          CCSPlayer::SwitchTeam(this: v12, iTeamNum: iTragetTeam);
        }
      }
      if ( ++i >= iNumToSwap )
        goto LABEL_44;
    }
    GlobalTeam = GetGlobalTeam(iIndex: 1);
    v18 = GlobalTeam->GetNumPlayers(this: GlobalTeam);
    v15 = __OFSUB__(v18, v10->m_iSpectatorSlotCount.m_Value);
    v14 = v18 - v10->m_iSpectatorSlotCount.m_Value < 0;
LABEL_27:
    if ( v14 == v15 )
      goto LABEL_44;
    goto LABEL_28;
  }
LABEL_44:
  if ( ConCommandBase::GetFlags(this: (ConCommandBase *)&traitors) > 0 )
  {
    UTIL_ClientPrintFilter(
      filter: &traitors,
      msg_dest: 4,
      msg_name: "#SFUI_Notice_Player_Balanced",
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
    UTIL_ClientPrintFilter(
      filter: &loyalists,
      msg_dest: 4,
      msg_name: "#SFUI_Notice_Teams_Balanced",
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  }
  CRecipientFilter::~CRecipientFilter(this: &loyalists);
  CRecipientFilter::~CRecipientFilter(this: &traitors);
}

//------------------------------------------------------------------------------
// Address: 0x10276680
// Name: public: void CCSGameRules::AddGunGameWeapon(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::AddGunGameWeapon(
        CCSGameRules *this,
        const char *pWeaponName,
        int nNumKillsToUpgrade,
        int nTeamID)
{
  int v5; // ebx
  CSWeaponID v6; // edi
  int m_Value; // edi
  int v8; // edi
  int v9; // edi
  int v10; // edi
  char weaponName[80]; // [esp+8h] [ebp-50h] BYREF
  int pWeaponNamea; // [esp+60h] [ebp+8h]
  int pWeaponNameb; // [esp+60h] [ebp+8h]

  if ( pWeaponName != nullptr )
  {
    v5 = nNumKillsToUpgrade;
    if ( nNumKillsToUpgrade <= 0 )
    {
      _Warning(
        a1: "CCSGameRules: Invalid number of kills-to-upgrade (%d) for weapon %s.\n",
        nNumKillsToUpgrade,
        pWeaponName);
      v5 = 1;
    }
    weaponName[0] = 0;
    V_snprintf(pDest: weaponName, maxLen: 80, pFormat: "weapon_%s", pWeaponName);
    v6 = WeaponIdFromString(szWeaponName: weaponName);
    if ( v6 != WEAPON_NONE )
    {
      if ( nTeamID == 3 )
      {
        pWeaponNamea = this->m_iNumGunGameProgressiveWeaponsCT.m_Value;
        if ( this->m_GGProgressiveWeaponOrderCT.m_Value[pWeaponNamea] != v6 )
        {
          CGameRulesProxy::NotifyNetworkStateChanged();
          this->m_GGProgressiveWeaponOrderCT.m_Value[pWeaponNamea] = v6;
        }
        m_Value = this->m_iNumGunGameProgressiveWeaponsCT.m_Value;
        if ( this->m_GGProgressiveWeaponKillUpgradeOrderCT.m_Value[m_Value] != v5 )
        {
          CGameRulesProxy::NotifyNetworkStateChanged();
          this->m_GGProgressiveWeaponKillUpgradeOrderCT.m_Value[m_Value] = v5;
        }
        v8 = this->m_iNumGunGameProgressiveWeaponsCT.m_Value + 1;
        CGameRulesProxy::NotifyNetworkStateChanged();
        this->m_iNumGunGameProgressiveWeaponsCT.m_Value = v8;
      }
      else if ( nTeamID == 2 )
      {
        pWeaponNameb = this->m_iNumGunGameProgressiveWeaponsT.m_Value;
        if ( this->m_GGProgressiveWeaponOrderT.m_Value[pWeaponNameb] != v6 )
        {
          CGameRulesProxy::NotifyNetworkStateChanged();
          this->m_GGProgressiveWeaponOrderT.m_Value[pWeaponNameb] = v6;
        }
        v9 = this->m_iNumGunGameProgressiveWeaponsT.m_Value;
        if ( this->m_GGProgressiveWeaponKillUpgradeOrderT.m_Value[v9] != v5 )
        {
          CGameRulesProxy::NotifyNetworkStateChanged();
          this->m_GGProgressiveWeaponKillUpgradeOrderT.m_Value[v9] = v5;
        }
        v10 = this->m_iNumGunGameProgressiveWeaponsT.m_Value + 1;
        CGameRulesProxy::NotifyNetworkStateChanged();
        this->m_iNumGunGameProgressiveWeaponsT.m_Value = v10;
      }
    }
    else
    {
      _Warning(a1: "CCSGameRules::AddGunGameWeapon: encountered an unknown weapon \"%s\".\n", pWeaponName);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102767D0
// Name: protected: void CCSGameRules::InitializeGameTypeAndMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::InitializeGameTypeAndMode(CCSGameRules *this)
{
  const CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int> > *v2; // eax
  const CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int> > *v3; // edi
  int v4; // ebx
  CUtlString *p_m_Name; // ecx
  const char *v6; // eax
  int v7; // eax
  const CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int> > *v8; // eax
  const CUtlVector<IGameTypes::WeaponProgression,CUtlMemory<IGameTypes::WeaponProgression,int> > *v9; // edi
  int v10; // ebx
  CUtlString *v11; // ecx
  const char *v12; // eax
  int v13; // eax
  int m_pMemory; // [esp-10h] [ebp-20h]
  int v15; // [esp-10h] [ebp-20h]
  ConVarRef host_map; // [esp+4h] [ebp-Ch] BYREF
  unsigned int isMultiplayer; // [esp+Ch] [ebp-4h]

  LOBYTE(isMultiplayer) = g_pMatchFramework->IsOnlineGame(this: g_pMatchFramework);
  if ( g_pGameTypes->ApplyConvarsForCurrentMode(this: g_pGameTypes, a2: isMultiplayer) )
  {
    if ( g_pGameTypes->GetCurrentGameType(this: g_pGameTypes) == 1
      && g_pGameTypes->GetCurrentGameMode(this: g_pGameTypes) == 0
      || g_pGameTypes->GetCurrentGameType(this: g_pGameTypes) == 1
      && g_pGameTypes->GetCurrentGameMode(this: g_pGameTypes) == 2 )
    {
      v2 = g_pGameTypes->GetWeaponProgressionForCurrentModeCT(this: g_pGameTypes);
      v3 = v2;
      v4 = 0;
      if ( v2 != nullptr && v2->m_Size > 0 )
      {
        isMultiplayer = 0;
        do
        {
          p_m_Name = &v3->m_Memory.m_pMemory[isMultiplayer / 0x14].m_Name;
          m_pMemory = (int)p_m_Name[1].m_Storage.m_Memory.m_pMemory;
          v6 = CUtlString::operator char const *(this: p_m_Name);
          CCSGameRules::AddGunGameWeapon(this, pWeaponName: v6, nNumKillsToUpgrade: m_pMemory, nTeamID: 3);
          v7 = g_pGameTypes->GetNoResetVoteThresholdForCurrentModeCT(this: g_pGameTypes);
          isMultiplayer += 20;
          ++v4;
          this->m_NoResetVoteThresholdCT = v7;
        }
        while ( v4 < v3->m_Size );
      }
      v8 = g_pGameTypes->GetWeaponProgressionForCurrentModeT(this: g_pGameTypes);
      v9 = v8;
      v10 = 0;
      if ( v8 != nullptr && v8->m_Size > 0 )
      {
        isMultiplayer = 0;
        do
        {
          v11 = &v9->m_Memory.m_pMemory[isMultiplayer / 0x14].m_Name;
          v15 = (int)v11[1].m_Storage.m_Memory.m_pMemory;
          v12 = CUtlString::operator char const *(this: v11);
          CCSGameRules::AddGunGameWeapon(this, pWeaponName: v12, nNumKillsToUpgrade: v15, nTeamID: 2);
          v13 = g_pGameTypes->GetNoResetVoteThresholdForCurrentModeT(this: g_pGameTypes);
          isMultiplayer += 20;
          ++v10;
          this->m_NoResetVoteThresholdT = v13;
        }
        while ( v10 < v9->m_Size );
      }
    }
    ConVarRef::ConVarRef(this: &host_map, pName: "host_map");
    g_pGameTypes->ApplyConvarsForMap(this: g_pGameTypes, a2: host_map.m_pConVarState->m_Value.m_pszString);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102769A0
// Name: public: bool CCSGameRules::CheckWinConditions(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSGameRules::CheckWinConditions(CCSGameRules *this)
{
  bool v3; // di
  int NumAliveTerrorist; // [esp+4h] [ebp-18h] BYREF
  int NumAliveCT; // [esp+8h] [ebp-14h] BYREF
  int NumDeadTerrorist; // [esp+Ch] [ebp-10h] BYREF
  int NumDeadCT; // [esp+10h] [ebp-Ch] BYREF
  BOOL bNeededPlayers; // [esp+17h] [ebp-5h] BYREF
  bool v9; // [esp+1Bh] [ebp-1h] BYREF

  if ( mp_ignore_round_win_conditions.m_pParent != nullptr
    && mp_ignore_round_win_conditions.m_pParent->m_Value.m_nValue != 0 )
  {
    return false;
  }
  if ( this->m_iRoundWinStatus != 0 )
  {
    CCSGameRules::InitializePlayerCounts(
      this,
      NumAliveTerrorist: &NumDeadCT,
      NumAliveCT: &NumDeadTerrorist,
      NumDeadTerrorist: &NumAliveCT,
      NumDeadCT: &NumAliveTerrorist);
    CCSGameRules::NeededPlayersCheck(this, bNeededPlayers: &v9);
    return true;
  }
  CCSGameRules::InitializePlayerCounts(this, &NumAliveTerrorist, &NumAliveCT, &NumDeadTerrorist, &NumDeadCT);
  if ( g_pGameTypes->GetCurrentGameType(this: g_pGameTypes) == 1
    && g_pGameTypes->GetCurrentGameMode(this: g_pGameTypes) == 0
    || CCSGameRules::IsPlayingGunGameTRBomb(this) )
  {
    if ( CCSGameRules::GunGameProgressiveEndCheck(this) )
      return true;
    if ( CCSGameRules::IsPlayingGunGameProgressive(this) )
      return false;
  }
  LOBYTE(bNeededPlayers) = 0;
  if ( CCSGameRules::NeededPlayersCheck(this, (bool *)&bNeededPlayers) != 0 )
    return false;
  v3 = bNeededPlayers;
  return CCSGameRules::VIPRoundEndCheck(this, bNeededPlayers) != 0
      || CCSGameRules::BombRoundEndCheck(this, bNeededPlayers: v3) != 0
      || CCSGameRules::TeamExterminationCheck(
           this,
           NumAliveTerrorist,
           NumAliveCT,
           NumDeadTerrorist,
           NumDeadCT,
           bNeededPlayers: v3) != 0
      || CCSGameRules::HostageRescueRoundEndCheck(this, bNeededPlayers: v3) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10276AC0
// Name: public: void CCSGameRules::MoveHumansToHumanTeam(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::MoveHumansToHumanTeam(CCSGameRules *this)
{
  int HumanTeam; // eax
  int v2; // esi
  SetHumanTeamFunctor setTeam; // [esp+4h] [ebp-48h] BYREF

  HumanTeam = CCSGameRules::GetHumanTeam(this);
  v2 = HumanTeam;
  if ( HumanTeam == 2 || HumanTeam == 3 )
  {
    CRecipientFilter::CRecipientFilter(this: &setTeam.m_traitors);
    CRecipientFilter::CRecipientFilter(this: &setTeam.m_loyalists);
    setTeam.m_targetTeam = v2;
    setTeam.m_sourceTeam = (v2 != 3) + 2;
    CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&setTeam.m_traitors);
    CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&setTeam.m_loyalists);
    CRecipientFilter::AddAllPlayers(this: &setTeam.m_loyalists);
    ForEachPlayer<SetHumanTeamFunctor>(func: &setTeam);
    if ( setTeam.m_traitors.GetRecipientCount(this: &setTeam.m_traitors) > 0 )
    {
      UTIL_ClientPrintFilter(
        filter: &setTeam.m_traitors,
        msg_dest: 4,
        msg_name: "#SFUI_Notice_Player_Balanced",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      UTIL_ClientPrintFilter(
        filter: &setTeam.m_loyalists,
        msg_dest: 4,
        msg_name: "#SFUI_Notice_Teams_Balanced",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
    }
    CRecipientFilter::~CRecipientFilter(this: &setTeam.m_loyalists);
    CRecipientFilter::~CRecipientFilter(this: &setTeam.m_traitors);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10276B80
// Name: public: virtual void CCSGameRules::ClientDisconnected(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::ClientDisconnected(CCSGameRules *this, edict_t *pClient)
{
  IServerUnknown *m_pUnk; // ecx
  CBaseEntity *v4; // esi
  CCSPlayer *v5; // eax

  CTeamplayRules::ClientDisconnected(this, pClient);
  if ( pClient != nullptr )
  {
    m_pUnk = pClient->m_pUnk;
    if ( m_pUnk != nullptr )
    {
      v4 = m_pUnk->GetBaseEntity(this: m_pUnk);
      if ( v4 != nullptr && v4->IsPlayer(this: v4) )
      {
        v5 = (CCSPlayer *)__RTDynamicCast(
                            inptr: v4,
                            VfDelta: 0,
                            SrcType: &CBaseEntity `RTTI Type Descriptor',
                            TargetType: &CCSPlayer `RTTI Type Descriptor',
                            isReference: 0);
        if ( v5 != nullptr )
          CCSPlayer::RemoveNemesisRelationships(this: v5);
      }
    }
  }
  CCSGameRules::CheckWinConditions(this);
}

//------------------------------------------------------------------------------
// Address: 0x10276C00
// Name: public: void CCSGameRules::RestartRound(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::RestartRound(CCSGameRules *this)
{
  IGameEvent *v2; // edi
  int i; // edi
  CCSPlayer *v4; // eax
  IGameEvent *v5; // eax
  int m_iNumSpawnableTerrorist; // eax
  CGlobalVars *v7; // edi
  CTeam *GlobalTeam; // edi
  CTeam *v9; // ebx
  int j; // edi
  CCSPlayer *v11; // eax
  edict_t *m_pPev; // edx
  int v13; // edi
  int m_nValue; // eax
  bool v15; // cc
  __int16 m_iNumCTWins; // ax
  CTeam *v17; // edi
  CTeam *v18; // ebx
  int v19; // ebx
  int k; // edi
  int m_iRoundWinStatus; // ecx
  int m_iLoserBonus; // eax
  int v23; // ecx
  __m128i v24; // xmm0
  float m_Value; // xmm1_4
  bool v26; // zf
  CGlobalVars *v27; // eax
  int m; // ebx
  CBasePlayer *v29; // eax
  CCSPlayer *v30; // edi
  int v31; // ebx
  CBasePlayer *v32; // eax
  CCSPlayer *v33; // edi
  int v34; // eax
  int v35; // eax
  int v36; // edi
  int v37; // edi
  CCSPlayer *v38; // eax
  int n; // ebx
  CBasePlayer *v40; // eax
  CCSPlayer *v41; // edi
  int v42; // eax
  int v43; // eax
  int m_Size; // edi
  IGameEvent *v45; // edi
  CTeam *v46; // edi
  int (__thiscall *GetNumPlayers)(CTeam *); // eax
  int v48; // ebx
  int v49; // eax
  void *v50; // edi
  CBasePlayer *v51; // eax
  __int16 v52; // ax
  CTeam *v53; // edi
  CTeam *v54; // ebx
  CTeam *v55; // ebx
  int (__thiscall *v56)(CTeam *); // eax
  CBasePlayer *v57; // edi
  CCSPlayer *v58; // eax
  CCSPlayer *v59; // ebx
  CBaseEdict *v60; // ecx
  int (__thiscall *v61)(CTeam *); // edx
  int v62; // edi
  int v63; // edi
  int (__thiscall *v64)(CTeam *); // edx
  int v65; // edi
  unsigned int v66; // [esp+4h] [ebp-58h]
  CGameTrace *v67; // [esp+8h] [ebp-54h]
  CTeam *pTeam; // [esp+40h] [ebp-1Ch] BYREF
  int iPlayer; // [esp+44h] [ebp-18h] BYREF
  int NumAliveCT; // [esp+48h] [ebp-14h] BYREF
  int iTeam; // [esp+4Ch] [ebp-10h] BYREF
  int terroristUniform; // [esp+50h] [ebp-Ch]
  int v73; // [esp+54h] [ebp-8h]
  RevertBotsFunctor revertBots; // [esp+5Bh] [ebp-1h] BYREF

  this->m_bRestartVotingAllowed = true;
  v2 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "enable_restart_voting", a3: 0, a4: 0);
  if ( v2 != nullptr )
  {
    v2->SetBool(this: v2, a2: "enable", a3: this->m_bRestartVotingAllowed);
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v2, a3: false);
  }
  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v4 = (CCSPlayer *)UTIL_PlayerByIndex(playerIndex: i);
    if ( v4 != nullptr )
      CCSPlayer::OnPreResetRound(this: v4);
  }
  v5 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "write_leaderboard_stats", a3: 0, a4: 0);
  if ( v5 != nullptr )
  {
    v67 = nullptr;
    v66 = (unsigned int)v5;
    ((void (__thiscall *)(IGameEventManager2 *))gameeventmanager->FireEvent)(a1: gameeventmanager);
  }
  iPlayer = SLODWORD(gpGlobals->curtime);
  if ( (iPlayer & 0x7F800000) == 0x7F800000 )
  {
    _Warning(a1: "NaN curtime in RestartRound\n");
    gpGlobals->curtime = 0.0;
  }
  ForEachPlayer<RevertBotsFunctor>(func: &revertBots);
  ++this->m_iTotalRoundsPlayed;
  ConVar::SetValue(this: (ConVar *)&sv_stopspeed.IConVar, value: 75.0);
  CCSGameRules::InitializePlayerCounts(
    this,
    NumAliveTerrorist: &iTeam,
    &NumAliveCT,
    NumDeadTerrorist: &iPlayer,
    NumDeadCT: (int *)&pTeam);
  *(_WORD *)&this->m_bBombDropped = 0;
  if ( CCSGameRules::GetHumanTeam(this) != 0 )
    CCSGameRules::MoveHumansToHumanTeam(this);
  if ( mp_autoteambalance.m_pParent != nullptr
    && mp_autoteambalance.m_pParent->m_Value.m_nValue != 0
    && this->m_iUnBalancedRounds >= 1
    && CCSGameRules::GetHumanTeam(this) == 0 )
  {
    CCSGameRules::BalanceTeams(this);
  }
  m_iNumSpawnableTerrorist = this->m_iNumSpawnableTerrorist;
  if ( this->m_iNumSpawnableCT - m_iNumSpawnableTerrorist >= 2
    || m_iNumSpawnableTerrorist - this->m_iNumSpawnableCT >= 2 )
  {
    ++this->m_iUnBalancedRounds;
  }
  else
  {
    this->m_iUnBalancedRounds = 0;
  }
  if ( mp_autoteambalance.m_pParent != nullptr
    && mp_autoteambalance.m_pParent->m_Value.m_nValue != 0
    && this->m_iUnBalancedRounds == 1
    && CCSGameRules::GetHumanTeam(this) == 0 )
  {
    UTIL_ClientPrintAll(
      msg_dest: 4,
      msg_name: "#SFUI_Notice_Auto_Team_Balance_Next_Round",
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  }
  if ( this->m_bCompleteReset )
  {
    if ( mp_timelimit.m_pParent != nullptr && mp_timelimit.m_pParent->m_Value.m_nValue < 0 )
      CCollisionProperty::TestCollision(this: (ConVar *)&mp_timelimit.IConVar, value: 0, fContentsMask: v66, tr: v67);
    v7 = gpGlobals;
    if ( this->m_flGameStartTime.m_Value != gpGlobals->curtime )
    {
      CGameRulesProxy::NotifyNetworkStateChanged();
      this->m_flGameStartTime.m_Value = v7->curtime;
    }
    iPlayer = SLODWORD(this->m_flGameStartTime.m_Value);
    if ( (iPlayer & 0x7F800000) == 0x7F800000 )
    {
      _Warning(a1: "Trying to set a NaN game start time\n");
      CGameRulesProxy::NotifyNetworkStateChanged();
      this->m_flGameStartTime.m_Value = 0.0;
    }
    this->m_iTotalRoundsPlayed = 0;
    *(_DWORD *)&this->m_iNumCTWins = 0;
    this->m_iNumConsecutiveTerroristLoses = 0;
    this->m_iNumConsecutiveCTLoses = 0;
    GlobalTeam = GetGlobalTeam(iIndex: 2);
    v9 = GetGlobalTeam(iIndex: 3);
    if ( GlobalTeam != nullptr )
      GlobalTeam->SetScore(this: GlobalTeam, a2: this->m_iNumTerroristWins);
    if ( v9 != nullptr )
      v9->SetScore(this: v9, a2: this->m_iNumCTWins);
    for ( j = 1; j <= gpGlobals->maxClients; ++j )
    {
      v11 = CCSPlayer::Instance(iEnt: j);
      if ( v11 != nullptr )
      {
        m_pPev = v11->m_Network.m_pPev;
        if ( m_pPev != nullptr && m_pPev - gpGlobals->pEdicts != 0 )
          CCSPlayer::Reset(this: v11, resetScore: true);
      }
    }
  }
  if ( !this->m_bFreezePeriod.m_Value )
  {
    CGameRulesProxy::NotifyNetworkStateChanged();
    this->m_bFreezePeriod.m_Value = true;
  }
  v13 = (int)(float)(mp_roundtime.m_pParent->m_Value.m_fValue * 60.0);
  if ( this->m_iRoundTime.m_Value != v13 )
  {
    CGameRulesProxy::NotifyNetworkStateChanged();
    this->m_iRoundTime.m_Value = v13;
  }
  if ( mp_freezetime.m_pParent != nullptr )
    m_nValue = mp_freezetime.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  this->m_iFreezeTime = m_nValue;
  if ( g_pMapInfo != nullptr )
  {
    switch ( g_pMapInfo->m_iBuyingStatus )
    {
      case 0:
        *(_WORD *)&this->m_bTCantBuy = 0;
        _Msg(a1: "EVERYONE CAN BUY!\n");
        break;
      case 1:
        *(_WORD *)&this->m_bTCantBuy = 1;
        _Msg(a1: "Only CT's can buy!!\n");
        break;
      case 2:
        *(_WORD *)&this->m_bTCantBuy = 256;
        _Msg(a1: "Only T's can buy!!\n");
        break;
      case 3:
        *(_WORD *)&this->m_bTCantBuy = 257;
        _Msg(a1: "No one can buy!!\n");
        break;
      default:
        goto LABEL_58;
    }
  }
  else
  {
LABEL_58:
    *(_WORD *)&this->m_bTCantBuy = 0;
  }
  if ( CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: nullptr, szName: "func_bomb_target") != nullptr )
  {
    if ( !this->m_bMapHasBombTarget.m_Value )
    {
      CGameRulesProxy::NotifyNetworkStateChanged();
      this->m_bMapHasBombTarget.m_Value = true;
    }
    this->m_bMapHasBombZone = true;
  }
  else
  {
    if ( CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: nullptr, szName: "info_bomb_target") != nullptr )
    {
      if ( !this->m_bMapHasBombTarget.m_Value )
      {
        CGameRulesProxy::NotifyNetworkStateChanged();
        this->m_bMapHasBombTarget.m_Value = true;
      }
    }
    else if ( this->m_bMapHasBombTarget.m_Value )
    {
      CGameRulesProxy::NotifyNetworkStateChanged();
      this->m_bMapHasBombTarget.m_Value = false;
    }
    this->m_bMapHasBombZone = false;
  }
  if ( CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: nullptr, szName: "func_hostage_rescue") != nullptr )
  {
    if ( !this->m_bMapHasRescueZone.m_Value )
    {
      CGameRulesProxy::NotifyNetworkStateChanged();
      this->m_bMapHasRescueZone.m_Value = true;
    }
  }
  else if ( this->m_bMapHasRescueZone.m_Value )
  {
    CGameRulesProxy::NotifyNetworkStateChanged();
    this->m_bMapHasRescueZone.m_Value = false;
  }
  this->m_bMapHasBuyZone = CGlobalEntityList::FindEntityByClassname(
                             this: &gEntList,
                             pStartEntity: nullptr,
                             szName: "func_buyzone") != nullptr;
  if ( CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: nullptr, szName: "func_escapezone") != nullptr )
  {
    v15 = this->m_iNumEscapeRounds < 3;
    this->m_bMapHasEscapeZone = true;
    this->m_iHaveEscaped = 0;
    this->m_iNumEscapers = 0;
    if ( !v15 )
    {
      m_iNumCTWins = this->m_iNumCTWins;
      this->m_iNumCTWins = this->m_iNumTerroristWins;
      this->m_iNumTerroristWins = m_iNumCTWins;
      v17 = GetGlobalTeam(iIndex: 2);
      v18 = GetGlobalTeam(iIndex: 3);
      if ( v17 != nullptr )
        v17->SetScore(this: v17, a2: this->m_iNumTerroristWins);
      if ( v18 != nullptr )
        v18->SetScore(this: v18, a2: this->m_iNumCTWins);
      this->m_iNumEscapeRounds = 0;
    }
    ++this->m_iNumEscapeRounds;
  }
  else
  {
    this->m_bMapHasEscapeZone = false;
  }
  if ( CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: nullptr, szName: "func_vip_safetyzone") != nullptr )
  {
    ++this->m_iConsecutiveVIP;
    this->m_iMapHasVIPSafetyZone = 1;
  }
  else
  {
    this->m_iMapHasVIPSafetyZone = 2;
  }
  v19 = 0;
  for ( k = 0; k < g_Hostages.m_Size; ++k )
  {
    if ( CHostage::IsValid(this: g_Hostages.m_Memory.m_pMemory[k]) )
      v19 += CCSGameRules::TeamCashAwardValue(this, reason: TEAM_CASH_AWARD_HOSTAGE_ALIVE);
    if ( v19 >= 2000 )
      break;
  }
  m_iRoundWinStatus = this->m_iRoundWinStatus;
  if ( m_iRoundWinStatus == 2 )
  {
    if ( this->m_iNumConsecutiveTerroristLoses > 1 )
      this->m_iLoserBonus = 500;
    ++this->m_iNumConsecutiveCTLoses;
    this->m_iNumConsecutiveTerroristLoses = 0;
  }
  else if ( m_iRoundWinStatus == 3 )
  {
    if ( this->m_iNumConsecutiveCTLoses > 1 )
      this->m_iLoserBonus = 500;
    ++this->m_iNumConsecutiveTerroristLoses;
    this->m_iNumConsecutiveCTLoses = 0;
  }
  if ( this->m_iNumConsecutiveTerroristLoses > 1 && (m_iLoserBonus = this->m_iLoserBonus) < 3000
    || this->m_iNumConsecutiveCTLoses > 1 && (m_iLoserBonus = this->m_iLoserBonus) < 3000 )
  {
    this->m_iLoserBonus = m_iLoserBonus + 500;
  }
  if ( m_iRoundWinStatus == 2 )
  {
    v23 = this->m_iLoserBonus;
    this->m_iAccountTerrorist += v19;
    this->m_iAccountCT += v23;
  }
  else if ( m_iRoundWinStatus == 3 )
  {
    this->m_iAccountCT += v19;
    if ( !this->m_bMapHasEscapeZone )
      this->m_iAccountTerrorist += this->m_iLoserBonus;
  }
  v24 = _mm_cvtsi32_si128(this->m_iFreezeTime);
  this->m_iAccountCT += 250 * this->m_iHostagesRescued;
  m_Value = this->m_fRoundStartTime.m_Value;
  *(float *)&iPlayer = _mm_cvtepi32_ps(v24).m128_f32[0] + gpGlobals->curtime;
  if ( m_Value != *(float *)&iPlayer )
  {
    CGameRulesProxy::NotifyNetworkStateChanged();
    this->m_fRoundStartTime.m_Value = *(float *)&iPlayer;
  }
  iPlayer = SLODWORD(this->m_fRoundStartTime.m_Value);
  if ( (iPlayer & 0x7F800000) == 0x7F800000 )
  {
    _Warning(a1: "Trying to set a NaN round start time\n");
    CGameRulesProxy::NotifyNetworkStateChanged();
    this->m_fRoundStartTime.m_Value = 0.0;
  }
  v26 = !this->m_bCompleteReset;
  this->m_bRoundTimeWarningTriggered = false;
  if ( !v26 )
  {
    this->m_iAccountCT = 0;
    this->m_iAccountTerrorist = 0;
    *(_DWORD *)&this->m_iNumCTWins = 0;
    this->m_iNumConsecutiveTerroristLoses = 0;
    this->m_iNumConsecutiveCTLoses = 0;
    this->m_iLoserBonus = 500;
  }
  v27 = gpGlobals;
  for ( m = 1; m <= gpGlobals->maxClients; ++m )
  {
    v29 = UTIL_PlayerByIndex(playerIndex: m);
    v30 = (CCSPlayer *)v29;
    if ( v29 != nullptr )
    {
      v29[1].m_target.pszValue = nullptr;
      v29[1].m_clrRender.m_Value.r = 0;
      if ( CBaseEntity::GetTeamNumber(this: v29) == 3 )
      {
        if ( CCSPlayer::DoesPlayerGetRoundStartMoney(this: v30) )
          CCSPlayer::AddAccount(this: v30, amount: this->m_iAccountCT, bTrackChange: true, bItemBought: false);
      }
      else if ( CBaseEntity::GetTeamNumber(this: v30) == 2 )
      {
        ++this->m_iNumEscapers;
        if ( CCSPlayer::DoesPlayerGetRoundStartMoney(this: v30) )
          CCSPlayer::AddAccount(this: v30, amount: this->m_iAccountTerrorist, bTrackChange: true, bItemBought: false);
      }
      if ( CBaseEntity::GetTeamNumber(this: v30) == 3 || CBaseEntity::GetTeamNumber(this: v30) == 2 )
        CCollisionProperty::SetSolidFlags(this: &v30->m_Collision, flags: v30->m_Collision.m_usSolidFlags.m_Value | 4);
    }
    v27 = gpGlobals;
  }
  v31 = 1;
  terroristUniform = -1;
  iTeam = -1;
  if ( v27->maxClients >= 1 )
  {
    do
    {
      v32 = UTIL_PlayerByIndex(playerIndex: v31);
      v33 = (CCSPlayer *)v32;
      if ( v32 != nullptr )
      {
        if ( CBaseEntity::GetTeamNumber(this: v32) == 3 )
        {
          v34 = CCSPlayer::PlayerClass(this: v33);
          if ( PlayerModelInfo::IsCTClass(this: &PlayerModelInfo::s_PlayerModelInfo, i: v34) )
          {
            if ( iTeam == -1 )
              iTeam = CCSPlayer::PlayerClass(this: v33);
            else
              CCSPlayer::PlayerClass(this: v33);
            CCSPlayer::RoundRespawn(this: v33);
          }
        }
        if ( CBaseEntity::GetTeamNumber(this: v33) == 2
          && (v35 = CCSPlayer::PlayerClass(this: v33),
              PlayerModelInfo::IsTClass(this: &PlayerModelInfo::s_PlayerModelInfo, i: v35)) )
        {
          if ( terroristUniform == -1 )
            terroristUniform = CCSPlayer::PlayerClass(this: v33);
          else
            CCSPlayer::PlayerClass(this: v33);
          CCSPlayer::RoundRespawn(this: v33);
        }
        else
        {
          CCSPlayer::ObserverRoundRespawn(this: v33);
        }
        if ( v33->m_iAccount.m_Value > v33->m_iShouldHaveCash )
          this->m_bDontUploadStats = true;
      }
      v27 = gpGlobals;
      ++v31;
    }
    while ( v31 <= gpGlobals->maxClients );
  }
  v36 = 1;
  if ( v27->maxClients >= 1 )
  {
    do
    {
      UTIL_PlayerByIndex(playerIndex: v36);
      v27 = gpGlobals;
      ++v36;
    }
    while ( v36 <= gpGlobals->maxClients );
  }
  v37 = 1;
  if ( v27->maxClients >= 1 )
  {
    do
    {
      v38 = (CCSPlayer *)UTIL_PlayerByIndex(playerIndex: v37);
      if ( v38 != nullptr )
        CCSPlayer::ResetRoundBasedAchievementVariables(this: v38);
      ++v37;
    }
    while ( v37 <= gpGlobals->maxClients );
  }
  if ( this->m_bCompleteReset )
  {
    CCSGameStats::ResetAllStats(this: &CCS_GameStats);
    CCSGameStats::ResetPlayerClassMatchStats(this: &CCS_GameStats);
  }
  else
  {
    CCSGameStats::ResetRoundStats(this: &CCS_GameStats);
  }
  CCSGameRules::CleanUpMap(this);
  for ( n = 1; n <= gpGlobals->maxClients; ++n )
  {
    v40 = UTIL_PlayerByIndex(playerIndex: n);
    v41 = (CCSPlayer *)v40;
    if ( v40 != nullptr )
    {
      if ( CBaseEntity::GetTeamNumber(this: v40) == 3
        && (v42 = CCSPlayer::PlayerClass(this: v41),
            PlayerModelInfo::IsCTClass(this: &PlayerModelInfo::s_PlayerModelInfo, i: v42))
        || CBaseEntity::GetTeamNumber(this: v41) == 2
        && (v43 = CCSPlayer::PlayerClass(this: v41),
            PlayerModelInfo::IsTClass(this: &PlayerModelInfo::s_PlayerModelInfo, i: v43)) )
      {
        CCSPlayer::CheckTKPunishment(this: v41);
      }
    }
  }
  if ( this->m_bMapHasBombTarget.m_Value )
  {
    CCSGameRules::GiveC4ToRandomPlayer(this);
    if ( mp_defuser_allocation.m_pParent != nullptr && mp_defuser_allocation.m_pParent->m_Value.m_nValue == 1 )
      CCSGameRules::GiveDefuserToRandomPlayer(this);
  }
  this->m_flIntermissionEndTime = 0.0;
  this->m_flRestartRoundTime = 0.0;
  this->m_iAccountCT = 0;
  this->m_iAccountTerrorist = 0;
  this->m_iHostagesRescued = 0;
  this->m_iHostagesTouched = 0;
  *(_DWORD *)&this->m_bNoTerroristsKilled = 16843009;
  this->m_pFirstKill.m_Index = -1;
  this->m_pFirstBlood.m_Index = -1;
  this->m_bCanDonateWeapons = true;
  if ( this->m_iHostagesRemaining.m_Value != 0 )
  {
    CGameRulesProxy::NotifyNetworkStateChanged();
    this->m_iHostagesRemaining.m_Value = 0;
  }
  this->m_pLastRescuer.m_Index = -1;
  this->m_iNumRescuers = 0;
  this->m_iRoundWinStatus = 0;
  *(_WORD *)&this->m_hostageWasInjured = 0;
  *(_WORD *)&this->m_bTargetBombed = 0;
  this->m_bCompleteReset = false;
  this->m_flNextHostageAnnouncement = gpGlobals->curtime;
  m_Size = g_Hostages.m_Size;
  if ( this->m_iHostagesRemaining.m_Value != g_Hostages.m_Size )
  {
    CGameRulesProxy::NotifyNetworkStateChanged();
    this->m_iHostagesRemaining.m_Value = m_Size;
  }
  v45 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "round_start", a3: 0, a4: 0);
  if ( v45 != nullptr )
  {
    v45->SetInt(this: v45, a2: "timelimit", a3: this->m_iRoundTime.m_Value);
    v45->SetInt(this: v45, a2: "fraglimit", a3: 0);
    v45->SetInt(this: v45, a2: "priority", a3: 6);
    if ( this->m_bMapHasRescueZone.m_Value )
    {
      v45->SetString(this: v45, a2: "objective", a3: "HOSTAGE RESCUE");
    }
    else if ( this->m_bMapHasEscapeZone )
    {
      v45->SetString(this: v45, a2: "objective", a3: "PRISON ESCAPE");
    }
    else if ( this->m_iMapHasVIPSafetyZone == 1 )
    {
      v45->SetString(this: v45, a2: "objective", a3: "VIP RESCUE");
    }
    else if ( this->m_bMapHasBombTarget.m_Value || this->m_bMapHasBombZone )
    {
      v45->SetString(this: v45, a2: "objective", a3: "BOMB TARGET");
    }
    else
    {
      v45->SetString(this: v45, a2: "objective", a3: "DEATHMATCH");
    }
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v45, a3: false);
  }
  CCSGameRules::UploadGameStats(this);
  if ( g_pGameTypes->GetCurrentGameType(this: g_pGameTypes) == 1
    && g_pGameTypes->GetCurrentGameMode(this: g_pGameTypes) == 0
    || g_pGameTypes->GetCurrentGameType(this: g_pGameTypes) == 1
    && g_pGameTypes->GetCurrentGameMode(this: g_pGameTypes) == 2 )
  {
    iTeam = 0;
    if ( GetNumberOfTeams() > 0 )
    {
      do
      {
        v46 = GetGlobalTeam(iIndex: iTeam);
        GetNumPlayers = v46->GetNumPlayers;
        v48 = 0;
        pTeam = v46;
        *(float *)&iPlayer = 0.0;
        if ( GetNumPlayers(this: v46) > 0 )
        {
          do
          {
            v49 = (int)v46->GetPlayer(this: v46, a2: v48);
            v50 = (void *)v49;
            if ( v49 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v49 + 336))(a1: v49) != 0 )
            {
              v51 = (CBasePlayer *)__RTDynamicCast(
                                     inptr: v50,
                                     VfDelta: 0,
                                     SrcType: &CBaseEntity `RTTI Type Descriptor',
                                     TargetType: &CCSPlayer `RTTI Type Descriptor',
                                     isReference: 0);
              if ( v51 != nullptr )
              {
                CBasePlayer::UnlockPlayer(this: v51);
                if ( g_pGameTypes->GetCurrentGameType(this: g_pGameTypes) == 1
                  && g_pGameTypes->GetCurrentGameMode(this: g_pGameTypes) == 2 )
                {
                  if ( this->m_bGunGameTRBombModeHalftime.m_Value )
                  {
                    v52 = this->m_iNumCTWins;
                    this->m_iNumCTWins = this->m_iNumTerroristWins;
                    this->m_iNumTerroristWins = v52;
                    v53 = GetGlobalTeam(iIndex: 2);
                    v54 = GetGlobalTeam(iIndex: 3);
                    if ( v53 != nullptr )
                      v53->SetScore(this: v53, a2: this->m_iNumTerroristWins);
                    if ( v54 != nullptr )
                      v54->SetScore(this: v54, a2: this->m_iNumCTWins);
                    if ( this->m_bGunGameTRBombModeHalftime.m_Value )
                    {
                      CGameRulesProxy::NotifyNetworkStateChanged();
                      this->m_bGunGameTRBombModeHalftime.m_Value = false;
                    }
                  }
                  if ( this->m_bGunGameTRBombMatchEnded )
                  {
                    this->m_bGunGameTRBombMatchEnded = false;
                    if ( this->m_iGunGameTRBombTScore.m_Value != 0 )
                    {
                      CGameRulesProxy::NotifyNetworkStateChanged();
                      this->m_iGunGameTRBombTScore.m_Value = 0;
                    }
                    if ( this->m_iGunGameTRBombCTScore.m_Value != 0 )
                    {
                      CGameRulesProxy::NotifyNetworkStateChanged();
                      this->m_iGunGameTRBombCTScore.m_Value = 0;
                    }
                    terroristUniform = 0;
                    if ( GetNumberOfTeams() > 0 )
                    {
                      do
                      {
                        v55 = GetGlobalTeam(iIndex: terroristUniform);
                        v56 = v55->GetNumPlayers;
                        NumAliveCT = (int)v55;
                        v73 = 0;
                        if ( v56(this: v55) > 0 )
                        {
                          do
                          {
                            v57 = v55->GetPlayer(this: v55, a2: v73);
                            if ( v57 != nullptr && v57->IsPlayer(this: v57) )
                            {
                              v58 = (CCSPlayer *)__RTDynamicCast(
                                                   inptr: v57,
                                                   VfDelta: 0,
                                                   SrcType: &CBaseEntity `RTTI Type Descriptor',
                                                   TargetType: &CCSPlayer `RTTI Type Descriptor',
                                                   isReference: 0);
                              v59 = v58;
                              if ( v58 != nullptr )
                              {
                                if ( v58->m_iGunGameProgressiveWeaponIndex.m_Value != 0 )
                                {
                                  if ( v58->m_Network.m_TimerEvent.m_bRegistered )
                                  {
                                    *((_BYTE *)&v58->m_Network + 76) |= 1u;
                                  }
                                  else
                                  {
                                    v60 = &v58->m_Network.m_pPev->CBaseEdict;
                                    if ( v60 != nullptr )
                                      CBaseEdict::StateChanged(this: v60, offset: 0x1314u);
                                  }
                                  v59->m_iGunGameProgressiveWeaponIndex.m_Value = 0;
                                }
                                v59->m_bShouldProgressGunGameTRBombModeWeapon = false;
                                CCSPlayer::ResetTRBombModeData(this: v59);
                              }
                              v55 = (CTeam *)NumAliveCT;
                            }
                            v61 = v55->GetNumPlayers;
                            v62 = ++v73;
                          }
                          while ( v62 < v61(this: v55) );
                        }
                        v63 = ++terroristUniform;
                      }
                      while ( v63 < GetNumberOfTeams() );
                    }
                    this->m_bFirstHalfOfGunGameTRBombModePlayed = false;
                  }
                }
              }
            }
            v46 = pTeam;
            v64 = pTeam->GetNumPlayers;
            v48 = ++iPlayer;
          }
          while ( v48 < v64(this: pTeam) );
        }
        v65 = ++iTeam;
      }
      while ( v65 < GetNumberOfTeams() );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10277AC0
// Name: public: bool CCSGameRules::CheckGameOver(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSGameRules::CheckGameOver(CCSGameRules *this)
{
  float m_flIntermissionEndTime; // xmm0_4
  int i; // esi
  CBasePlayer *v5; // eax
  IGameEvent *v6; // eax

  if ( !g_fGameOver )
    return 0;
  m_flIntermissionEndTime = this->m_flIntermissionEndTime;
  if ( m_flIntermissionEndTime != 0.0 && gpGlobals->curtime > m_flIntermissionEndTime )
  {
    if ( mp_match_end_restart.m_pParent == nullptr || mp_match_end_restart.m_pParent->m_Value.m_nValue == 0 )
    {
      this->ChangeLevel(this);
      this->m_flIntermissionEndTime = 0.0;
      return 1;
    }
    for ( i = 1; i <= gpGlobals->maxClients; ++i )
    {
      v5 = UTIL_PlayerByIndex(playerIndex: i);
      if ( v5 != nullptr )
        v5->ChangeTeam(this: v5, a2: 0);
    }
    this->m_bCompleteReset = true;
    CCSGameRules::RestartRound(this);
    g_fGameOver = false;
    v6 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "cs_match_end_restart", a3: 0, a4: 0);
    if ( v6 != nullptr )
      gameeventmanager->FireEvent(this: gameeventmanager, a2: v6, a3: false);
    this->m_flIntermissionEndTime = 0.0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10277BB0
// Name: public: virtual void CCSGameRules::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::Think(CCSGameRules *this)
{
  CBasePlayer *i; // esi
  CTeam *GlobalTeam; // eax
  int m_nValue; // eax
  IGameEvent *v5; // eax
  float m_flRestartRoundTime; // xmm0_4
  int j; // ebx
  CBasePlayer *v8; // eax
  float *v9; // eax
  float curtime; // xmm0_4
  const char *v11; // eax

  CGameRules::Think(this);
  for ( i = nullptr; (int)i < GetNumberOfTeams(); i = (CBasePlayer *)((char *)i + 1) )
  {
    GlobalTeam = GetGlobalTeam(iIndex: (int)i);
    GlobalTeam->Think(this: GlobalTeam);
  }
  if ( CCSGameRules::CheckGameOver(this) == 0 )
  {
    if ( mp_maxrounds.m_pParent != nullptr
      && (m_nValue = mp_maxrounds.m_pParent->m_Value.m_nValue) != 0
      && this->m_iTotalRoundsPlayed >= m_nValue )
    {
      UTIL_LogPrintf(fmt: "World triggered \"Intermission_Round_Limit\"\n");
      this->GoToIntermission(this);
    }
    else if ( CCSGameRules::CheckFragLimit(this) == 0 && CCSGameRules::CheckWinLimit(this) == 0 )
    {
      if ( this->m_bFreezePeriod.m_Value )
        CCSGameRules::CheckFreezePeriodExpired(this);
      else
        CCSGameRules::CheckRoundTimeExpired(this);
      CCSGameRules::CheckLevelInitialized(this);
      CCSGameRules::UpdateVoteStatus(this);
      if ( !this->m_bRoundTimeWarningTriggered
        && (float)((float)((float)this->m_iRoundTime.m_Value + this->m_fRoundStartTime.m_Value) - gpGlobals->curtime) < 10.0 )
      {
        this->m_bRoundTimeWarningTriggered = true;
        v5 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "round_time_warning", a3: 0, a4: 0);
        if ( v5 != nullptr )
          gameeventmanager->FireEvent(this: gameeventmanager, a2: v5, a3: false);
      }
      m_flRestartRoundTime = this->m_flRestartRoundTime;
      if ( m_flRestartRoundTime > 0.0 && gpGlobals->curtime >= m_flRestartRoundTime )
      {
        for ( j = 1; j <= gpGlobals->maxClients; ++j )
        {
          v8 = UTIL_PlayerByIndex(playerIndex: j);
          i = v8;
          if ( v8 != nullptr && v8->IsBot(this: v8) )
          {
            v9 = (float *)__RTDynamicCast(
                            inptr: i,
                            VfDelta: 0,
                            SrcType: &CBasePlayer `RTTI Type Descriptor',
                            TargetType: &CCSBot `RTTI Type Descriptor',
                            isReference: 0);
            if ( v9 != nullptr )
            {
              curtime = gpGlobals->curtime;
              if ( v9[4199] > curtime )
              {
                if ( curtime <= (float)(this->m_flRestartRoundTime + 10.0) )
                  goto LABEL_28;
                v11 = (const char *)(*(int (__thiscall **)(float *))(*(_DWORD *)v9 + 160))(a1: v9);
                _Msg(a1: "Ignoring speaking bot %s at round end\n", v11);
              }
            }
          }
        }
        CCSGameRules::RestartRound(this);
      }
LABEL_28:
      if ( gpGlobals->curtime > this->m_tmNextPeriodicThink )
      {
        CCSGameRules::CheckRestartRound(this, a2: (unsigned int)i);
        this->m_tmNextPeriodicThink = gpGlobals->curtime + 1.0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10277DE0
// Name: public: CCSGameRules::CCSGameRules(void)
// Source: json
//------------------------------------------------------------------------------
CCSGameRules *__thiscall CCSGameRules::CCSGameRules(CCSGameRules *this)
{
  CCSFunFactMgr *v2; // eax
  CCSFunFactMgr *v3; // eax
  int v4; // edi
  int m_nValue; // eax
  int v6; // edi
  int m_Size; // eax
  int v8; // edi
  CTeam **m_pMemory; // ecx
  int v10; // eax
  CTeam **v11; // edi
  const char *pszValue; // eax
  IBaseFileSystem_vtbl *v13; // edi
  char *v14; // eax
  const char *v15; // eax
  IVEngineServer_vtbl *v16; // edi
  char *v17; // eax
  CTeam *pTeam; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  CTeamplayRules::CTeamplayRules(this);
  this->__vftable = (CCSGameRules_vtbl *)&CCSGameRules::`vftable';
  this->m_pFirstKill.m_Index = -1;
  this->m_pFirstBlood.m_Index = -1;
  this->m_pLastRescuer.m_Index = -1;
  this->m_pVIP.m_Index = -1;
  this->m_pLastBombGuy.m_Index = -1;
  this->m_pLastDefuserGuy.m_Index = -1;
  if ( this->m_iRoundTime.m_Value != 0 )
  {
    CGameRulesProxy::NotifyNetworkStateChanged();
    this->m_iRoundTime.m_Value = 0;
  }
  this->m_iRoundWinStatus = 0;
  this->m_iFreezeTime = 0;
  if ( this->m_fRoundStartTime.m_Value != 0.0 )
  {
    CGameRulesProxy::NotifyNetworkStateChanged();
    this->m_fRoundStartTime.m_Value = 0.0;
  }
  this->m_bAllowWeaponSwitch = true;
  if ( !this->m_bFreezePeriod.m_Value )
  {
    CGameRulesProxy::NotifyNetworkStateChanged();
    this->m_bFreezePeriod.m_Value = true;
  }
  *(_DWORD *)&this->m_iNumCTWins = 0;
  this->m_iNumCT = 0;
  this->m_iNumTerrorist = 0;
  this->m_flRestartRoundTime = 0.1;
  this->m_iNumSpawnableCT = 0;
  this->m_iNumSpawnableTerrorist = 0;
  *(_WORD *)&this->m_bFirstConnected = 0;
  this->m_iAccountCT = 0;
  this->m_iAccountTerrorist = 0;
  this->m_iNumConsecutiveCTLoses = 0;
  this->m_iNumConsecutiveTerroristLoses = 0;
  *(_WORD *)&this->m_bTargetBombed = 0;
  this->m_iTotalRoundsPlayed = -1;
  this->m_iUnBalancedRounds = 0;
  if ( this->m_flGameStartTime.m_Value != 0.0 )
  {
    CGameRulesProxy::NotifyNetworkStateChanged();
    this->m_flGameStartTime.m_Value = 0.0;
  }
  if ( this->m_iHostagesRemaining.m_Value != 0 )
  {
    CGameRulesProxy::NotifyNetworkStateChanged();
    this->m_iHostagesRemaining.m_Value = 0;
  }
  this->m_bLevelInitialized = false;
  if ( this->m_bLogoMap.m_Value )
  {
    CGameRulesProxy::NotifyNetworkStateChanged();
    this->m_bLogoMap.m_Value = false;
  }
  this->m_tmNextPeriodicThink = 0.0;
  if ( this->m_bMapHasBombTarget.m_Value )
  {
    CGameRulesProxy::NotifyNetworkStateChanged();
    this->m_bMapHasBombTarget.m_Value = false;
  }
  if ( this->m_bMapHasRescueZone.m_Value )
  {
    CGameRulesProxy::NotifyNetworkStateChanged();
    this->m_bMapHasRescueZone.m_Value = false;
  }
  this->m_iSpawnPointCount_Terrorist = 0;
  this->m_iSpawnPointCount_CT = 0;
  *(_WORD *)&this->m_bTCantBuy = 0;
  this->m_bMapHasBuyZone = false;
  this->m_iLoserBonus = 0;
  this->m_iHostagesRescued = 0;
  this->m_iHostagesTouched = 0;
  this->m_flNextHostageAnnouncement = 0.0;
  *(_DWORD *)&this->m_bNoTerroristsKilled = 16843009;
  this->m_pFirstKill.m_Index = -1;
  this->m_firstKillTime = 0.0;
  this->m_pFirstBlood.m_Index = -1;
  this->m_firstBloodTime = 0.0;
  this->m_bCanDonateWeapons = true;
  this->m_pLastRescuer.m_Index = -1;
  this->m_iNumRescuers = 0;
  *(_WORD *)&this->m_hostageWasInjured = 0;
  v2 = (CCSFunFactMgr *)operator new(nSize: 0x138u);
  if ( v2 != nullptr )
    v3 = CCSFunFactMgr::CCSFunFactMgr(this: v2);
  else
    v3 = nullptr;
  this->m_pFunFactManager = v3;
  v3->Init(this: v3);
  this->m_iHaveEscaped = 0;
  this->m_bMapHasEscapeZone = false;
  this->m_iNumEscapers = 0;
  this->m_iNumEscapeRounds = 0;
  this->m_iMapHasVIPSafetyZone = 0;
  this->m_pVIP.m_Index = -1;
  this->m_iConsecutiveVIP = 0;
  *(_WORD *)&this->m_bMapHasBombZone = 0;
  this->m_bBombPlanted = false;
  this->m_pLastBombGuy.m_Index = -1;
  this->m_bGunGameRespawnWithBomb = false;
  this->m_fGunGameBombRespawnTimer = 0.0;
  *(_DWORD *)&this->m_bFirstHalfOfGunGameTRBombModePlayed = 0x10000;
  this->m_NoResetVoteThresholdCT = -1;
  this->m_NoResetVoteThresholdT = -1;
  this->m_currentVote = VoteType_None;
  this->m_voteEndTime = 0.0;
  if ( this->m_iNumGunGameProgressiveWeaponsCT.m_Value != 0 )
  {
    CGameRulesProxy::NotifyNetworkStateChanged();
    this->m_iNumGunGameProgressiveWeaponsCT.m_Value = 0;
  }
  if ( this->m_iNumGunGameProgressiveWeaponsT.m_Value != 0 )
  {
    CGameRulesProxy::NotifyNetworkStateChanged();
    this->m_iNumGunGameProgressiveWeaponsT.m_Value = 0;
  }
  if ( this->m_iGunGameTRBombTScore.m_Value != 0 )
  {
    CGameRulesProxy::NotifyNetworkStateChanged();
    this->m_iGunGameTRBombTScore.m_Value = 0;
  }
  if ( this->m_iGunGameTRBombCTScore.m_Value != 0 )
  {
    CGameRulesProxy::NotifyNetworkStateChanged();
    this->m_iGunGameTRBombCTScore.m_Value = 0;
  }
  if ( this->m_bGunGameTRBombModeHalftime.m_Value )
  {
    CGameRulesProxy::NotifyNetworkStateChanged();
    this->m_bGunGameTRBombModeHalftime.m_Value = false;
  }
  this->m_bAllowWeaponSwitch = true;
  if ( this->m_iSpectatorSlotCount.m_Value != 0 )
  {
    CGameRulesProxy::NotifyNetworkStateChanged();
    this->m_iSpectatorSlotCount.m_Value = 0;
  }
  this->m_flNextHostageAnnouncement = gpGlobals->curtime;
  v4 = (int)(float)(mp_roundtime.m_pParent->m_Value.m_fValue * 60.0);
  if ( this->m_iRoundTime.m_Value != v4 )
  {
    CGameRulesProxy::NotifyNetworkStateChanged();
    this->m_iRoundTime.m_Value = v4;
  }
  if ( mp_freezetime.m_pParent != nullptr )
    m_nValue = mp_freezetime.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  this->m_iFreezeTime = m_nValue;
  this->m_pPrices = nullptr;
  if ( this->m_bBlackMarket.m_Value )
  {
    CGameRulesProxy::NotifyNetworkStateChanged();
    this->m_bBlackMarket.m_Value = false;
  }
  v6 = 0;
  this->m_bDontUploadStats = false;
  for ( i = 0; ; v6 = i )
  {
    pTeam = (CTeam *)CreateEntityByName(className: "cs_team_manager", iForceEdictIndex: -1, bNotify: true);
    pTeam->Init(this: pTeam, a2: sTeamNames[v6], a3: v6);
    m_Size = g_Teams.m_Size;
    v8 = g_Teams.m_Size;
    if ( g_Teams.m_Size + 1 > g_Teams.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&g_Teams,
        num: g_Teams.m_Size - g_Teams.m_Memory.m_nAllocationCount + 1);
      m_Size = g_Teams.m_Size;
    }
    m_pMemory = g_Teams.m_Memory.m_pMemory;
    g_Teams.m_Size = m_Size + 1;
    v10 = m_Size - v8;
    g_Teams.m_pElements = g_Teams.m_Memory.m_pMemory;
    if ( v10 > 0 )
    {
      _V_memmove(dest: &g_Teams.m_Memory.m_pMemory[v8 + 1], src: &g_Teams.m_Memory.m_pMemory[v8], count: 4 * v10);
      m_pMemory = g_Teams.m_Memory.m_pMemory;
    }
    v11 = &m_pMemory[v8];
    if ( v11 != nullptr )
      *v11 = pTeam;
    if ( (unsigned int)++i >= 4 )
      break;
  }
  pszValue = gpGlobals->mapname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  v13 = filesystem->IBaseFileSystem::__vftable;
  v14 = UTIL_VarArgs(format: "maps/cfg/%s.cfg", pszValue);
  if ( v13->FileExists(this: &filesystem->IBaseFileSystem, a2: v14, a3: nullptr) )
  {
    v15 = gpGlobals->mapname.pszValue;
    if ( v15 == nullptr )
      v15 = locale;
    v16 = engine->__vftable;
    v17 = UTIL_VarArgs(format: "exec %s.cfg */maps\n", v15);
    v16->ServerCommand(this: engine, a2: v17);
    engine->ServerExecute(this: engine);
  }
  if ( g_flGameStatsUpdateTime == 0.0 )
  {
    memset(dst: (int)g_iWeaponPurchases, value: nullptr, count: sizeof(g_iWeaponPurchases));
    *(_QWORD *)g_iTerroristVictories = 0;
    *(_QWORD *)&g_iTerroristVictories[4] = 0;
    *(_QWORD *)&g_iTerroristVictories[8] = 0;
    *(_QWORD *)&g_iTerroristVictories[12] = 0;
    *(_QWORD *)g_iCounterTVictories = 0;
    *(_QWORD *)&g_iCounterTVictories[4] = 0;
    *(_QWORD *)&g_iCounterTVictories[8] = 0;
    *(_QWORD *)&g_iCounterTVictories[12] = 0;
    *(_DWORD *)&g_iTerroristVictories[16] = 0;
    *(_DWORD *)&g_iCounterTVictories[16] = 0;
    g_flGameStatsUpdateTime = 79200.0;
  }
  CCSGameRules::InitializeGameTypeAndMode(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10278330
// Name: public: virtual unsigned char const __near * CCSGameRules::GetEncryptionKey(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSGameRules::GetEncryptionKey(CCSGameRules *this)
{
  return "d7NSuLq2";
}

//------------------------------------------------------------------------------
// Address: 0x10278340
// Name: public: virtual char const __near * CCSGameRules::GetGameDescription(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSGameRules::GetGameDescription(CCSGameRules *this)
{
  return "Counter-Strike: Source";
}

//------------------------------------------------------------------------------
// Address: 0x10278360
// Name: public: virtual CCSGameRules::~CCSGameRules(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSGameRules::~CCSGameRules(CCSGameRules *this)
{
  CTeam **m_pMemory; // eax
  CCSFunFactMgr *m_pFunFactManager; // ecx

  this->__vftable = (CCSGameRules_vtbl *)&CCSGameRules::`vftable';
  m_pMemory = g_Teams.m_Memory.m_pMemory;
  g_Teams.m_Size = 0;
  if ( g_Teams.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_Teams.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_Teams.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_Teams.m_Memory.m_pMemory = nullptr;
    }
    g_Teams.m_Memory.m_nAllocationCount = 0;
  }
  g_Teams.m_pElements = m_pMemory;
  m_pFunFactManager = this->m_pFunFactManager;
  if ( m_pFunFactManager != nullptr )
    ((void (__thiscall *)(CCSFunFactMgr *, int))m_pFunFactManager->dtr_IGameSystem)(a1: m_pFunFactManager, a2: 1);
  this->__vftable = (CCSGameRules_vtbl *)&CMultiplayRules::`vftable';
  CUtlVector<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,int>>::~CUtlVector<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,CUtlMemory<CUtlVector<CEntityDataInstantiator<StepSimulationData>::HashEntry,CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>>,int>>(this: (CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int> >,int> > *)&this->m_VoiceCommandMenus);
  CGameRules::~CGameRules(this);
}

//------------------------------------------------------------------------------
// Address: 0x102783E0
// Name: void __CreateGameRules_CCSGameRules(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __CreateGameRules_CCSGameRules()
{
  CCSGameRules *v0; // esi

  v0 = (CCSGameRules *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 1784);
  _V_memset(dest: v0, fill: 0, count: 1784);
  if ( v0 != nullptr )
    CCSGameRules::CCSGameRules(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x1040D470
// Name: DT_CSGameRules::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_CSGameRules::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_CSGameRules::g_SendTable);
  return atexit(func: DT_CSGameRules::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040D490
// Name: DT_CSGameRules::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_CSGameRules::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_CSGameRules::ignored>();
  DT_CSGameRules::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040D4E0
// Name: DT_CSGameRulesProxy::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_CSGameRulesProxy::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_CSGameRulesProxy::g_SendTable);
  return atexit(func: DT_CSGameRulesProxy::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040D500
// Name: DT_CSGameRulesProxy::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_CSGameRulesProxy::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_CSGameRulesProxy::ignored>();
  DT_CSGameRulesProxy::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041F410
// Name: DT_CSGameRules::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_CSGameRules::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_CSGameRules::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041F420
// Name: DT_CSGameRulesProxy::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_CSGameRulesProxy::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_CSGameRulesProxy::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10276920
// Name: bool ForEachPlayer<class SetHumanTeamFunctor>(class SetHumanTeamFunctor __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl ForEachPlayer<SetHumanTeamFunctor>(SetHumanTeamFunctor *func)
{
  int v1; // edi
  CBasePlayer *v2; // eax
  CBasePlayer *v3; // esi
  edict_t *m_pPev; // eax

  v1 = 1;
  if ( gpGlobals->maxClients < 1 )
    return 1;
  while ( 1 )
  {
    v2 = UTIL_PlayerByIndex(playerIndex: v1);
    v3 = v2;
    if ( v2 != nullptr )
    {
      m_pPev = v2->m_Network.m_pPev;
      if ( m_pPev != nullptr
        && m_pPev - gpGlobals->pEdicts != 0
        && v3->IsPlayer(this: v3)
        && v3->m_iConnected != PlayerDisconnected
        && SetHumanTeamFunctor::operator()(this: func, basePlayer: v3) == 0 )
      {
        break;
      }
    }
    if ( ++v1 > gpGlobals->maxClients )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1040D4A0
// Name: _dynamic_initializer_for__g_CCSGameRulesProxy_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CCSGameRulesProxy_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CCSGameRulesProxy_ClassReg,
           pNetworkName: "CCSGameRulesProxy",
           pTable: &DT_CSGameRulesProxy::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1040D4C0
// Name: _dynamic_initializer_for__cs_gamerules__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cs_gamerules__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CCSGameRulesProxy> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &cs_gamerules,
           a3: "cs_gamerules");
}

//------------------------------------------------------------------------------
// Address: 0x1041F430
// Name: _ServerClassInit_DT_CSGameRulesProxy::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_CSGameRulesProxy::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_145;
  for ( i = 2; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

} // namespace server
