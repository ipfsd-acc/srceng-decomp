// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/buy_presets/buy_preset_weapon_info.cpp
// Functions: 10
// ============================================================

#include "game\client\cstrike15\buy_presets\buy_preset_weapon_info.h"

//------------------------------------------------------------------------------
// Address: 0x101B5A80
// Name: wchar_t const __near * WeaponIDToDisplayName(enum CSWeaponID)
// Source: json
//------------------------------------------------------------------------------
wchar_t *__cdecl WeaponIDToDisplayName(CSWeaponID weaponID)
{
  int v1; // edx
  int v2; // eax

  v1 = 0;
  if ( weaponDisplayNameInfo[0].displayName == nullptr )
    return nullptr;
  v2 = 0;
  while ( weaponDisplayNameInfo[v2].id != weaponID )
  {
    v2 = ++v1;
    if ( weaponDisplayNameInfo[v1].displayName == nullptr )
      return nullptr;
  }
  return g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: weaponDisplayNameInfo[v1].displayName);
}

//------------------------------------------------------------------------------
// Address: 0x101B5AD0
// Name: public: BuyPresetWeapon::BuyPresetWeapon(void)
// Source: json
//------------------------------------------------------------------------------
BuyPresetWeapon *__thiscall BuyPresetWeapon::BuyPresetWeapon(BuyPresetWeapon *this)
{
  this->m_name = nullptr;
  this->m_weaponID = WEAPON_NONE;
  this->m_ammoType = AMMO_CLIPS;
  this->m_ammoAmount = 0;
  this->m_fillAmmo = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101B5AF0
// Name: public: BuyPresetWeapon::BuyPresetWeapon(enum CSWeaponID)
// Source: json
//------------------------------------------------------------------------------
BuyPresetWeapon *__thiscall BuyPresetWeapon::BuyPresetWeapon(BuyPresetWeapon *this, CSWeaponID weaponID)
{
  this->m_name = WeaponIDToDisplayName(weaponID);
  this->m_weaponID = weaponID;
  this->m_ammoType = AMMO_CLIPS;
  this->m_fillAmmo = true;
  this->m_ammoAmount = weaponID != WEAPON_NONE;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101B5B30
// Name: public: class BuyPresetWeapon __near & BuyPresetWeapon::operator=(class BuyPresetWeapon const __near &)
// Source: json
//------------------------------------------------------------------------------
BuyPresetWeapon *__thiscall BuyPresetWeapon::operator=(BuyPresetWeapon *this, const BuyPresetWeapon *other)
{
  *this = *other;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101B5B60
// Name: public: void BuyPresetWeapon::SetWeaponID(enum CSWeaponID)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BuyPresetWeapon::SetWeaponID(BuyPresetWeapon *this, CSWeaponID weaponID)
{
  const wchar_t *v3; // eax

  v3 = WeaponIDToDisplayName(weaponID);
  this->m_weaponID = weaponID;
  this->m_name = v3;
}

//------------------------------------------------------------------------------
// Address: 0x101B5B80
// Name: int CalcClipsNeeded(class BuyPresetWeapon const __near *,class CCSWeaponInfo const __near *,int const __near * const)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CalcClipsNeeded(const BuyPresetWeapon *pWeapon, const CCSWeaponInfo *pInfo, const int *ammo)
{
  CCSAmmoDef *CSAmmoDef; // eax
  int v5; // eax
  CCSAmmoDef *v6; // eax
  int BuySize; // edi
  int v8; // ecx
  int iAmmoType; // edx
  AmmoSizeType m_ammoType; // eax
  __int32 v11; // eax
  int v12; // eax
  int v13; // esi
  int v14; // ebx
  int X; // [esp+0h] [ebp-1Ch]
  C_CSPlayer *X_4; // [esp+4h] [ebp-18h]
  int X_4a; // [esp+4h] [ebp-18h]
  int numClips; // [esp+18h] [ebp-4h]
  int maxRounds; // [esp+24h] [ebp+8h]
  float maxRoundsa; // [esp+24h] [ebp+8h]

  if ( pWeapon != nullptr && pInfo != nullptr )
  {
    X_4 = CClientTools::GetLocalPlayer();
    X = pInfo->iAmmoType;
    CSAmmoDef = GetCSAmmoDef();
    v5 = CAmmoDef::MaxCarry(this: CSAmmoDef, nAmmoIndex: X, owner: X_4);
    X_4a = pInfo->iAmmoType;
    maxRounds = v5;
    v6 = GetCSAmmoDef();
    BuySize = CCSAmmoDef::GetBuySize(this: v6, index: X_4a);
    v8 = 0;
    if ( BuySize == 0 )
      return v8;
    iAmmoType = pInfo->iAmmoType;
    if ( iAmmoType < 0 )
      return v8;
    m_ammoType = pWeapon->m_ammoType;
    if ( m_ammoType != AMMO_PERCENT )
    {
      v11 = m_ammoType - 1;
      if ( v11 == 0 )
      {
        numClips = pWeapon->m_ammoAmount;
        if ( pWeapon->m_weaponID != WEAPON_NONE || pWeapon->m_ammoAmount < 4 )
        {
          v13 = maxRounds;
        }
        else
        {
          v13 = maxRounds;
          numClips = (int)ceil(X: (float)((float)maxRounds / (float)BuySize));
        }
        maxRoundsa = (float)numClips;
        if ( maxRoundsa > ceil(X: (float)((float)v13 / (float)BuySize)) )
          maxRoundsa = ceil(X: (float)((float)v13 / (float)BuySize));
        v14 = ammo[pInfo->iAmmoType];
        v8 = (int)maxRoundsa - v14 / BuySize;
        if ( v8 >= 0 && v14 != v13 )
          return v8;
        return 0;
      }
      if ( v11 != 1 )
        return v8;
      v12 = pWeapon->m_ammoAmount - ammo[iAmmoType];
    }
    else
    {
      v12 = (int)(float)((float)(maxRounds * pWeapon->m_ammoAmount - ammo[iAmmoType]) * 0.0099999998);
    }
    if ( v12 > 0 )
      return (int)ceil(X: (float)((float)v12 / (float)BuySize));
    return 0;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101B5D40
// Name: bool CanBuyWeapon(enum CSWeaponID,enum CSWeaponID,enum CSWeaponID)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CanBuyWeapon(CSWeaponID currentPrimaryID, CSWeaponID currentSecondaryID, CSWeaponID weaponID)
{
  bool result; // al
  C_CSPlayer *LocalPlayer; // edi
  CCSWeaponInfo *WeaponInfo; // eax

  if ( currentPrimaryID == WEAPON_SHIELDGUN && weaponID == WEAPON_ELITE
    || currentSecondaryID == WEAPON_ELITE && weaponID == WEAPON_SHIELDGUN )
  {
    return false;
  }
  LocalPlayer = CClientTools::GetLocalPlayer();
  result = false;
  if ( LocalPlayer != nullptr )
  {
    WeaponInfo = GetWeaponInfo(weaponID);
    if ( WeaponInfo != nullptr
      && (WeaponInfo->m_iTeam == 0 || LocalPlayer->GetTeamNumber(this: LocalPlayer) == WeaponInfo->m_iTeam) )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B5DB0
// Name: void FillClientAmmo(int __near * const)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FillClientAmmo(int *ammo)
{
  CSWeaponID i; // ebx
  CCSWeaponInfo *WeaponInfo; // eax
  int iAmmoType; // edi
  int AmmoCount; // eax
  C_CSPlayer *localPlayer; // [esp+4h] [ebp-4h]

  *ammo = 0;
  ammo[1] = 0;
  ammo[2] = 0;
  ammo[3] = 0;
  ammo[4] = 0;
  ammo[5] = 0;
  ammo[6] = 0;
  ammo[7] = 0;
  ammo[8] = 0;
  ammo[9] = 0;
  ammo[10] = 0;
  ammo[11] = 0;
  ammo[12] = 0;
  ammo[13] = 0;
  ammo[14] = 0;
  ammo[15] = 0;
  ammo[16] = 0;
  ammo[17] = 0;
  ammo[18] = 0;
  ammo[19] = 0;
  ammo[20] = 0;
  ammo[21] = 0;
  ammo[22] = 0;
  ammo[23] = 0;
  ammo[24] = 0;
  ammo[25] = 0;
  ammo[26] = 0;
  ammo[27] = 0;
  ammo[28] = 0;
  ammo[29] = 0;
  ammo[30] = 0;
  ammo[31] = 0;
  localPlayer = CClientTools::GetLocalPlayer();
  if ( localPlayer != nullptr )
  {
    for ( i = WEAPON_NONE; i < WEAPON_MAX; ++i )
    {
      if ( i != WEAPON_NONE && i < WEAPON_SHIELDGUN )
      {
        WeaponInfo = GetWeaponInfo(weaponID: i);
        if ( WeaponInfo != nullptr )
        {
          iAmmoType = WeaponInfo->iAmmoType;
          AmmoCount = C_BaseCombatCharacter::GetAmmoCount(this: localPlayer, iAmmoIndex: iAmmoType);
          if ( AmmoCount > 0 )
          {
            if ( ammo[iAmmoType] > AmmoCount )
              AmmoCount = ammo[iAmmoType];
            ammo[iAmmoType] = AmmoCount;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B5E80
// Name: class C_WeaponCSBase __near * GetWeaponInSlot(int,int)
// Source: json
//------------------------------------------------------------------------------
C_CSPlayer *__cdecl GetWeaponInSlot(int iSlot, int iSlotPos)
{
  C_CSPlayer *result; // eax
  C_WeaponCSBase *v3; // ebx
  int v4; // edi
  int v5; // esi

  result = CClientTools::GetLocalPlayer();
  v3 = (C_WeaponCSBase *)result;
  if ( result != nullptr )
  {
    v4 = 0;
    while ( 1 )
    {
      v5 = ((int (__thiscall *)(C_WeaponCSBase *, int))v3->RescindAltFireHudHint)(a1: v3, a2: v4);
      if ( v5 != 0
        && (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 1288))(a1: v5) == iSlot
        && (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 1292))(a1: v5) == iSlotPos )
      {
        break;
      }
      if ( ++v4 >= 64 )
        return nullptr;
    }
    return (C_CSPlayer *)v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B5EE0
// Name: enum CSWeaponID GetClientWeaponID(bool)
// Source: json
//------------------------------------------------------------------------------
CSWeaponID __cdecl GetClientWeaponID(bool primary)
{
  C_CSPlayer *WeaponInSlot; // eax

  if ( CClientTools::GetLocalPlayer() != nullptr
    && (WeaponInSlot = GetWeaponInSlot(iSlot: !primary, iSlotPos: !primary)) != nullptr )
  {
    return ((CSWeaponID (__thiscall *)(C_CSPlayer *))WeaponInSlot->C_BasePlayer::C_BaseCombatCharacter::C_BaseFlex::C_BaseAnimatingOverlay::C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].InitSharedVars)(a1: WeaponInSlot);
  }
  else
  {
    return WEAPON_NONE;
  }
}
