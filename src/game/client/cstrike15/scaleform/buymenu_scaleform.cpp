// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/scaleform/buymenu_scaleform.cpp
// Functions: 43
// ============================================================

#include "game\client\cstrike15\scaleform\buymenu_scaleform.h"

//------------------------------------------------------------------------------
// Address: 0x102058A0
// Name: public: class CCSLoadout __near & CCSLoadout::operator=(class CCSLoadout const __near &)
// Source: json
//------------------------------------------------------------------------------
CCSLoadout *__thiscall CCSLoadout::operator=(CCSLoadout *this, const CCSLoadout *in_rhs)
{
  *this = *in_rhs;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10205910
// Name: public: bool CCSLoadout::operator==(class CCSLoadout const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSLoadout::operator==(CCSLoadout *this, const CCSLoadout *in_rhs)
{
  int v3; // edi
  CCSEquipmentLoadout *m_EquipmentArray; // esi
  CSWeaponID m_EquipmentID; // edx
  bool v6; // bl
  int v7; // esi
  CCSEquipmentLoadout *i; // edx
  CSWeaponID v9; // eax
  bool v10; // bl
  CCSLoadout *v11; // [esp+0h] [ebp-4h]

  v11 = this;
  if ( this->m_primaryWeaponID != in_rhs->m_primaryWeaponID
    || this->m_secondaryWeaponID != in_rhs->m_secondaryWeaponID
    || this->m_flags != in_rhs->m_flags )
  {
    return 0;
  }
  v3 = 0;
  m_EquipmentArray = this->m_EquipmentArray;
  while ( 1 )
  {
    m_EquipmentID = m_EquipmentArray->m_EquipmentID;
    if ( m_EquipmentArray->m_EquipmentID != WEAPON_NONE )
    {
      v6 = false;
      if ( in_rhs->m_EquipmentArray[0].m_EquipmentID == m_EquipmentID )
      {
        this = v11;
        v6 = in_rhs->m_EquipmentArray[0].m_Quantity == m_EquipmentArray->m_Quantity;
      }
      if ( in_rhs->m_EquipmentArray[1].m_EquipmentID == m_EquipmentID )
      {
        this = v11;
        if ( in_rhs->m_EquipmentArray[1].m_Quantity == m_EquipmentArray->m_Quantity )
          v6 = true;
      }
      if ( in_rhs->m_EquipmentArray[2].m_EquipmentID == m_EquipmentID )
      {
        this = v11;
        if ( in_rhs->m_EquipmentArray[2].m_Quantity == m_EquipmentArray->m_Quantity )
          v6 = true;
      }
      if ( in_rhs->m_EquipmentArray[3].m_EquipmentID == m_EquipmentID )
      {
        this = v11;
        if ( in_rhs->m_EquipmentArray[3].m_Quantity == m_EquipmentArray->m_Quantity )
          v6 = true;
      }
      if ( in_rhs->m_EquipmentArray[4].m_EquipmentID == m_EquipmentID )
      {
        this = v11;
        if ( in_rhs->m_EquipmentArray[4].m_Quantity == m_EquipmentArray->m_Quantity )
          v6 = true;
      }
      if ( (in_rhs->m_EquipmentArray[5].m_EquipmentID != m_EquipmentID
         || in_rhs->m_EquipmentArray[5].m_Quantity != m_EquipmentArray->m_Quantity)
        && !v6 )
      {
        break;
      }
    }
    ++v3;
    ++m_EquipmentArray;
    if ( v3 >= 6 )
    {
      v7 = 0;
      for ( i = in_rhs->m_EquipmentArray; ; ++i )
      {
        v9 = i->m_EquipmentID;
        if ( i->m_EquipmentID != WEAPON_NONE )
        {
          v10 = false;
          if ( this->m_EquipmentArray[0].m_EquipmentID == v9 )
            v10 = this->m_EquipmentArray[0].m_Quantity == i->m_Quantity;
          if ( this->m_EquipmentArray[1].m_EquipmentID == v9 && this->m_EquipmentArray[1].m_Quantity == i->m_Quantity )
            v10 = true;
          if ( this->m_EquipmentArray[2].m_EquipmentID == v9 && this->m_EquipmentArray[2].m_Quantity == i->m_Quantity )
            v10 = true;
          if ( this->m_EquipmentArray[3].m_EquipmentID == v9 && this->m_EquipmentArray[3].m_Quantity == i->m_Quantity )
            v10 = true;
          if ( this->m_EquipmentArray[4].m_EquipmentID == v9 && this->m_EquipmentArray[4].m_Quantity == i->m_Quantity )
            v10 = true;
          if ( (this->m_EquipmentArray[5].m_EquipmentID != v9 || this->m_EquipmentArray[5].m_Quantity != i->m_Quantity)
            && !v10 )
          {
            break;
          }
        }
        if ( ++v7 >= 6 )
          return 1;
      }
      return 0;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10205A50
// Name: void InitBuyMenuLoadoutData(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitBuyMenuLoadoutData()
{
  CSWeaponID v0; // edi
  CSWeaponID *v1; // esi
  CSWeaponID *v2; // eax
  int v3; // ebx
  CSWeaponID v4; // ebx
  CSWeaponID v5; // ebx
  CSWeaponID v6; // ebx
  CSWeaponID v7; // ebx
  CSWeaponID v8; // ebx
  int i; // [esp+Ch] [ebp-4h]

  v0 = s_defaultEquipment[0];
  v1 = s_defaultLoadoutWeapons;
  v2 = (CSWeaponID *)&unk_10668F14;
  do
  {
    for ( i = 6; i != 0; --i )
    {
      *(v2 - 5) = *v1;
      v3 = *((_DWORD *)v1 + 1);
      v1 += 2;
      *((_DWORD *)v2 - 4) = v3;
      *((_BYTE *)v2 + 36) = 0;
      *((_DWORD *)v2 - 3) = v0;
      if ( v0 == WEAPON_NONE )
        *((_DWORD *)v2 - 2) = 0;
      v4 = s_defaultEquipment[1];
      *((_DWORD *)v2 - 2) = 1;
      *((_DWORD *)v2 - 1) = v4;
      if ( v4 == WEAPON_NONE )
        *v2 = WEAPON_NONE;
      v5 = s_defaultEquipment[2];
      *v2 = WEAPON_DEAGLE;
      *((_DWORD *)v2 + 1) = v5;
      if ( v5 == WEAPON_NONE )
        *((_DWORD *)v2 + 2) = 0;
      v6 = s_defaultEquipment[3];
      *((_DWORD *)v2 + 2) = 1;
      *((_DWORD *)v2 + 3) = v6;
      if ( v6 == WEAPON_NONE )
        *((_DWORD *)v2 + 4) = 0;
      v7 = s_defaultEquipment[4];
      *((_DWORD *)v2 + 4) = 1;
      *((_DWORD *)v2 + 5) = v7;
      if ( v7 == WEAPON_NONE )
        *((_DWORD *)v2 + 6) = 0;
      v8 = s_defaultEquipment[5];
      *((_DWORD *)v2 + 6) = 1;
      *((_DWORD *)v2 + 7) = v8;
      if ( v8 == WEAPON_NONE )
        *((_DWORD *)v2 + 8) = 0;
      *((_DWORD *)v2 + 8) = 1;
      v2 += 15;
    }
  }
  while ( (int)v2 < (int)&player_teamplayedlast.m_pNext );
}

//------------------------------------------------------------------------------
// Address: 0x10205B10
// Name: public: virtual void CCSBuyMenuScaleform::FlashLoaded(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBuyMenuScaleform::FlashLoaded(CCSBuyMenuScaleform *this)
{
  void *v2; // eax

  v2 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: this->m_FlashAPI, a3: "Panel");
  if ( v2 != nullptr )
    this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10205B40
// Name: public: void CCSBuyMenuScaleform::CalculateBestStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBuyMenuScaleform::CalculateBestStats(CCSBuyMenuScaleform *this)
{
  CSWeaponID i; // edi
  CCSWeaponInfo *WeaponInfo; // eax
  CCSBuyMenuScaleform::WeaponStatPack *p_m_SecondaryStats; // ecx
  float v5; // xmm0_4
  float m_flCycleTime; // xmm1_4
  float v7; // xmm0_4
  float m_flMaxSpeed; // xmm0_4
  float v9; // xmm0_4
  BOOL v10; // esi
  float v11; // xmm0_4

  for ( i = WEAPON_DEAGLE; i < WEAPON_KNIFE; ++i )
  {
    if ( i != WEAPON_TASER )
    {
      WeaponInfo = GetWeaponInfo(weaponID: i);
      p_m_SecondaryStats = &this->m_SecondaryStats;
      if ( WeaponInfo->m_WeaponType != WEAPONTYPE_PISTOL )
        p_m_SecondaryStats = &this->m_PrimaryStats;
      v5 = (float)WeaponInfo->m_iDamage * WeaponInfo->m_flArmorRatio;
      if ( v5 > p_m_SecondaryStats->m_FirepowerStat.m_fBest )
        p_m_SecondaryStats->m_FirepowerStat.m_fBest = v5;
      if ( p_m_SecondaryStats->m_FirepowerStat.m_fWorst > v5 )
        p_m_SecondaryStats->m_FirepowerStat.m_fWorst = v5;
      m_flCycleTime = WeaponInfo->m_flCycleTime;
      if ( m_flCycleTime > 0.0 )
      {
        v7 = 1.0 / m_flCycleTime;
        if ( (float)(1.0 / m_flCycleTime) > p_m_SecondaryStats->m_FireRateStat.m_fBest )
          p_m_SecondaryStats->m_FireRateStat.m_fBest = v7;
        if ( p_m_SecondaryStats->m_FireRateStat.m_fWorst > v7 )
          p_m_SecondaryStats->m_FireRateStat.m_fWorst = v7;
      }
      m_flMaxSpeed = WeaponInfo->m_flMaxSpeed;
      if ( m_flMaxSpeed > p_m_SecondaryStats->m_MovementStat.m_fBest )
        p_m_SecondaryStats->m_MovementStat.m_fBest = m_flMaxSpeed;
      if ( p_m_SecondaryStats->m_MovementStat.m_fWorst > m_flMaxSpeed )
        p_m_SecondaryStats->m_MovementStat.m_fWorst = m_flMaxSpeed;
      v9 = WeaponInfo->m_fInaccuracyCrouch[1];
      v10 = false;
      if ( v9 != 0.0 )
        v10 = WeaponInfo->m_fInaccuracyCrouch[0] > v9;
      v11 = 100.0 / (float)(WeaponInfo->m_fInaccuracyCrouch[v10] + WeaponInfo->m_fSpread[v10]);
      if ( v11 > p_m_SecondaryStats->m_AccuracyStat.m_fBest )
        p_m_SecondaryStats->m_AccuracyStat.m_fBest = v11;
      if ( p_m_SecondaryStats->m_AccuracyStat.m_fWorst > v11 )
        p_m_SecondaryStats->m_AccuracyStat.m_fWorst = v11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10205C70
// Name: public: virtual void CCSBuyMenuScaleform::PostUnloadFlash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBuyMenuScaleform::PostUnloadFlash(CCSBuyMenuScaleform *this)
{
  this->m_bLoading = false;
}

//------------------------------------------------------------------------------
// Address: 0x10205C80
// Name: public: void CCSBuyMenuScaleform::AutobuyFromFlash(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBuyMenuScaleform::AutobuyFromFlash(CCSBuyMenuScaleform *this, IScaleformUI *pui, void *obj)
{
  C_CSPlayer *LocalPlayer; // eax
  int UserID; // eax
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+4h] [ebp-8h] BYREF
  CGameUiSetActiveSplitScreenPlayerGuard v7; // [esp+8h] [ebp-4h] BYREF

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iFlashSlot - 2);
  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &v7,
    slot: this->m_iFlashSlot - 2);
  engine->ClientCmd(this: engine, a2: "autobuy");
  this->m_bBoughtSomething = true;
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &v7);
  LocalPlayer = CClientTools::GetLocalPlayer();
  if ( LocalPlayer != nullptr )
    UserID = C_BasePlayer::GetUserID(this: LocalPlayer);
  else
    UserID = -1;
  C_CSGameRules::CloseBuyMenu(this: (C_CSGameRules *)g_pGameRules, nPlayerID: UserID);
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x10205D00
// Name: public: void CCSBuyMenuScaleform::GetWeaponIDFromShortNameFromFlash(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBuyMenuScaleform::GetWeaponIDFromShortNameFromFlash(
        CCSBuyMenuScaleform *this,
        IScaleformUI *pui,
        void *obj)
{
  const char *v4; // eax
  CSWeaponID v5; // eax
  char pDest[100]; // [esp+8h] [ebp-64h] BYREF

  v4 = this->m_pScaleformUI->Params_GetArgAsString(this: this->m_pScaleformUI, a2: obj, a3: 0);
  pDest[0] = 0;
  V_snprintf(pDest, maxLen: 0x64u, pFormat: "weapon_%s", v4);
  v5 = WeaponIdFromString(szWeaponName: pDest);
  this->m_pScaleformUI->Params_SetResult_5(this: this->m_pScaleformUI, a2: obj, a3: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10205D60
// Name: public: void CCSBuyMenuScaleform::BuyWeapon(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBuyMenuScaleform::BuyWeapon(CCSBuyMenuScaleform *this, const char *weapShortName)
{
  char buyCommand[100]; // [esp+4h] [ebp-68h] BYREF
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+68h] [ebp-4h] BYREF

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iFlashSlot - 2);
  V_snprintf(pDest: buyCommand, maxLen: 0x64u, pFormat: "buy %s", weapShortName);
  engine->ClientCmd(this: engine, a2: buyCommand);
  this->m_bBoughtSomething = true;
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x10205DC0
// Name: public: void CCSBuyMenuScaleform::BuyWeaponFromFlash(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBuyMenuScaleform::BuyWeaponFromFlash(CCSBuyMenuScaleform *this, IScaleformUI *pui, void *params)
{
  const char *v4; // edi
  char pDest[100]; // [esp+8h] [ebp-64h] BYREF

  v4 = this->m_pScaleformUI->Params_GetArgAsString(this: this->m_pScaleformUI, a2: params, a3: 0);
  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: (CGameUiSetActiveSplitScreenPlayerGuard *)&params,
    slot: this->m_iFlashSlot - 2);
  V_snprintf(pDest, maxLen: 0x64u, pFormat: "buy %s", v4);
  engine->ClientCmd(this: engine, a2: pDest);
  this->m_bBoughtSomething = true;
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: (CGameUiSetActiveSplitScreenPlayerGuard *)&params);
}

//------------------------------------------------------------------------------
// Address: 0x10206010
// Name: public: void CCSBuyMenuScaleform::Hide(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBuyMenuScaleform::Hide(CCSBuyMenuScaleform *this)
{
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx
  int v4; // eax
  _DWORD v5[4]; // [esp+0h] [ebp-24h]
  SplitScreenConVarRef pHideHud; // [esp+10h] [ebp-14h] BYREF
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+20h] [ebp-4h] BYREF

  if ( !this->m_bLoading && this->m_bFlashAPIIsValid && this->m_bVisible )
  {
    CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
      this: &g_UISSGuard,
      slot: this->m_iFlashSlot - 2);
    for ( i = 1; ; i = 0 )
    {
      m_pScaleformUI = this->m_pScaleformUI;
      if ( i == 0 )
        break;
      if ( m_pScaleformUI != nullptr )
        m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
      g_pScaleformUI->Value_InvokeWithoutReturn(
        this: g_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "hidePanel",
        a4: nullptr,
        a5: 0);
    }
    if ( m_pScaleformUI != nullptr )
      m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
    SplitScreenConVarRef::SplitScreenConVarRef(this: &pHideHud, pName: "hidehud");
    v4 = v5[2 * this->m_iFlashSlot];
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 4))(a1: v4, a2: this->m_PrevHideHudValue);
    g_pMatSystemSurface->EnableWindowsMessages(this: g_pMatSystemSurface, a2: true);
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
  }
  this->m_bVisible = false;
}

//------------------------------------------------------------------------------
// Address: 0x102060E0
// Name: public: virtual bool CCSBuyMenuScaleform::PreUnloadFlash(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSBuyMenuScaleform::PreUnloadFlash(CCSBuyMenuScaleform *this)
{
  CGameEventListener *v2; // esi

  v2 = &this->CGameEventListener;
  if ( this->m_bRegisteredForEvents )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: v2);
    v2->m_bRegisteredForEvents = false;
  }
  this->m_bLoading = true;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10206110
// Name: public: void CCSBuyMenuScaleform::UpdateLoadouts(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBuyMenuScaleform::UpdateLoadouts(CCSBuyMenuScaleform *this)
{
  CCSLoadout *p_m_previousPlayerLoadout; // edi
  int v2; // edx
  CCSEquipmentLoadout *m_EquipmentArray; // eax
  C_CSPlayer *LocalPlayer; // eax
  int v5; // eax
  CCSLoadout *v6; // esi
  int v7; // ebx
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+4h] [ebp-8h] BYREF
  CCSLoadout *v9; // [esp+8h] [ebp-4h]

  p_m_previousPlayerLoadout = &this->m_previousPlayerLoadout;
  if ( this->m_previousPlayerLoadout.m_primaryWeaponID == WEAPON_NONE
    && this->m_previousPlayerLoadout.m_secondaryWeaponID == WEAPON_NONE )
  {
    v2 = 0;
    m_EquipmentArray = this->m_previousPlayerLoadout.m_EquipmentArray;
    while ( m_EquipmentArray->m_EquipmentID == WEAPON_NONE || m_EquipmentArray->m_Quantity == 0 )
    {
      ++v2;
      ++m_EquipmentArray;
      if ( v2 >= 6 )
      {
        if ( this->m_previousPlayerLoadout.m_flags == 0 )
          return;
        break;
      }
    }
  }
  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iFlashSlot - 2);
  LocalPlayer = CClientTools::GetLocalPlayer();
  if ( LocalPlayer != nullptr )
  {
    v5 = LocalPlayer->GetTeamNumber(this: LocalPlayer);
    if ( v5 == 2 )
      v6 = s_loadoutArray[0];
    else
      v6 = v5 != 3 ? nullptr : (CCSLoadout *)&unk_10669068;
    v7 = 0;
    v9 = v6;
    while ( CCSLoadout::operator==(this: v9, in_rhs: p_m_previousPlayerLoadout) == 0 )
    {
      ++v9;
      if ( ++v7 >= 6 )
      {
        _V_memmove(dest: (unsigned __int8 *)&v6[1], src: (unsigned __int8 *)v6, count: 0x12Cu);
        v6->m_primaryWeaponID = p_m_previousPlayerLoadout->m_primaryWeaponID;
        v6->m_secondaryWeaponID = p_m_previousPlayerLoadout->m_secondaryWeaponID;
        v6->m_flags = p_m_previousPlayerLoadout->m_flags;
        v6->m_EquipmentArray[0].m_EquipmentID = p_m_previousPlayerLoadout->m_EquipmentArray[0].m_EquipmentID;
        v6->m_EquipmentArray[0].m_Quantity = p_m_previousPlayerLoadout->m_EquipmentArray[0].m_Quantity;
        v6->m_EquipmentArray[1].m_EquipmentID = p_m_previousPlayerLoadout->m_EquipmentArray[1].m_EquipmentID;
        v6->m_EquipmentArray[1].m_Quantity = p_m_previousPlayerLoadout->m_EquipmentArray[1].m_Quantity;
        v6->m_EquipmentArray[2].m_EquipmentID = p_m_previousPlayerLoadout->m_EquipmentArray[2].m_EquipmentID;
        v6->m_EquipmentArray[2].m_Quantity = p_m_previousPlayerLoadout->m_EquipmentArray[2].m_Quantity;
        v6->m_EquipmentArray[3].m_EquipmentID = p_m_previousPlayerLoadout->m_EquipmentArray[3].m_EquipmentID;
        v6->m_EquipmentArray[3].m_Quantity = p_m_previousPlayerLoadout->m_EquipmentArray[3].m_Quantity;
        v6->m_EquipmentArray[4].m_EquipmentID = p_m_previousPlayerLoadout->m_EquipmentArray[4].m_EquipmentID;
        v6->m_EquipmentArray[4].m_Quantity = p_m_previousPlayerLoadout->m_EquipmentArray[4].m_Quantity;
        v6->m_EquipmentArray[5].m_EquipmentID = p_m_previousPlayerLoadout->m_EquipmentArray[5].m_EquipmentID;
        v6->m_EquipmentArray[5].m_Quantity = p_m_previousPlayerLoadout->m_EquipmentArray[5].m_Quantity;
        break;
      }
    }
  }
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x10206240
// Name: public: int CCSBuyMenuScaleform::PriceLoadout(class CCSLoadout const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSBuyMenuScaleform::PriceLoadout(CCSBuyMenuScaleform *this, const CCSLoadout *loadout)
{
  int v2; // ebx
  CCSWeaponInfo *WeaponInfo; // eax
  int WeaponPrice; // eax
  CCSWeaponInfo *v5; // eax
  int v6; // eax
  CCSWeaponInfo *v7; // eax
  int v8; // eax
  int v9; // edi
  CCSEquipmentLoadout *m_EquipmentArray; // esi
  CCSWeaponInfo *v11; // eax
  int v12; // eax

  v2 = 0;
  if ( loadout->m_primaryWeaponID != WEAPON_NONE )
  {
    WeaponInfo = GetWeaponInfo(weaponID: loadout->m_primaryWeaponID);
    if ( WeaponInfo != nullptr )
      WeaponPrice = CCSWeaponInfo::GetWeaponPrice(this: WeaponInfo);
    else
      WeaponPrice = 0;
    v2 = WeaponPrice;
  }
  if ( loadout->m_secondaryWeaponID != WEAPON_NONE )
  {
    v5 = GetWeaponInfo(weaponID: loadout->m_secondaryWeaponID);
    if ( v5 != nullptr )
      v6 = CCSWeaponInfo::GetWeaponPrice(this: v5);
    else
      v6 = 0;
    v2 += v6;
  }
  if ( (loadout->m_flags & 1) != 0 )
  {
    v7 = GetWeaponInfo(weaponID: WEAPON_TASER);
    if ( v7 != nullptr )
      v8 = CCSWeaponInfo::GetWeaponPrice(this: v7);
    else
      v8 = 0;
    v2 += v8;
  }
  v9 = 0;
  m_EquipmentArray = loadout->m_EquipmentArray;
  do
  {
    if ( m_EquipmentArray->m_EquipmentID == WEAPON_NONE || m_EquipmentArray->m_Quantity == 0 )
      break;
    v11 = GetWeaponInfo(weaponID: m_EquipmentArray->m_EquipmentID);
    v12 = v11 != nullptr ? CCSWeaponInfo::GetWeaponPrice(this: v11) : 0;
    ++v9;
    v2 += v12 * m_EquipmentArray->m_Quantity;
    ++m_EquipmentArray;
  }
  while ( v9 < 6 );
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x102062F0
// Name: public: bool CCSBuyMenuScaleform::FillInPlayerLoadout(class CCSLoadout __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSBuyMenuScaleform::FillInPlayerLoadout(CCSBuyMenuScaleform *this, CCSLoadout *newLoadout)
{
  C_CSPlayer *LocalPlayer; // eax
  C_CSPlayer *v3; // esi
  CSWeaponID v4; // ebx
  C_WeaponCSBase *CSWeapon; // eax
  C_WeaponCSBase *v7; // esi
  CCSEquipmentLoadout *v8; // ebx
  int (__thiscall *GetPrimaryAmmoType)(C_BaseCombatWeapon *); // eax
  int v10; // eax
  int AmmoCount; // eax
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+8h] [ebp-Ch] BYREF
  C_CSPlayer *pPlayer; // [esp+Ch] [ebp-8h]
  int numEquipment; // [esp+10h] [ebp-4h]
  int i; // [esp+1Ch] [ebp+8h]

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iFlashSlot - 2);
  LocalPlayer = CClientTools::GetLocalPlayer();
  v3 = LocalPlayer;
  v4 = WEAPON_NONE;
  pPlayer = LocalPlayer;
  if ( LocalPlayer != nullptr && LocalPlayer->IsAlive(this: LocalPlayer) )
  {
    newLoadout->m_primaryWeaponID = WEAPON_NONE;
    newLoadout->m_secondaryWeaponID = WEAPON_NONE;
    newLoadout->m_flags = 0;
    newLoadout->m_EquipmentArray[0].m_EquipmentID = WEAPON_NONE;
    newLoadout->m_EquipmentArray[1].m_EquipmentID = WEAPON_NONE;
    newLoadout->m_EquipmentArray[0].m_Quantity = 0;
    newLoadout->m_EquipmentArray[1].m_Quantity = 0;
    newLoadout->m_EquipmentArray[2].m_EquipmentID = WEAPON_NONE;
    newLoadout->m_EquipmentArray[2].m_Quantity = 0;
    newLoadout->m_EquipmentArray[3].m_EquipmentID = WEAPON_NONE;
    newLoadout->m_EquipmentArray[3].m_Quantity = 0;
    newLoadout->m_EquipmentArray[4].m_EquipmentID = WEAPON_NONE;
    newLoadout->m_EquipmentArray[4].m_Quantity = 0;
    newLoadout->m_EquipmentArray[5].m_EquipmentID = WEAPON_NONE;
    newLoadout->m_EquipmentArray[5].m_Quantity = 0;
    numEquipment = 0;
    i = 0;
    while ( 1 )
    {
      CSWeapon = C_CSPlayer::GetCSWeapon(this: v3, id: (const CBaseHandle *)v4);
      v7 = CSWeapon;
      if ( CSWeapon != nullptr )
      {
        if ( v4 == WEAPON_TASER )
        {
          newLoadout->m_flags |= 1u;
        }
        else if ( C_WeaponCSBase::GetCSWpnData(this: CSWeapon)->m_WeaponType == WEAPONTYPE_PISTOL )
        {
          newLoadout->m_secondaryWeaponID = v4;
        }
        else if ( C_WeaponCSBase::GetCSWpnData(this: v7)->m_WeaponType == WEAPONTYPE_GRENADE )
        {
          if ( numEquipment < 6 )
          {
            v8 = &newLoadout->m_EquipmentArray[numEquipment];
            v8->m_EquipmentID = i;
            if ( i == 0 )
              v8->m_Quantity = 0;
            GetPrimaryAmmoType = v7->GetPrimaryAmmoType;
            ++numEquipment;
            v10 = GetPrimaryAmmoType(this: v7);
            AmmoCount = C_BaseCombatCharacter::GetAmmoCount(this: pPlayer, iAmmoIndex: v10);
            v8->m_Quantity = AmmoCount;
            if ( AmmoCount == 0 )
              v8->m_EquipmentID = WEAPON_NONE;
            v4 = i;
          }
        }
        else if ( C_WeaponCSBase::GetCSWpnData(this: v7)->m_WeaponType != WEAPONTYPE_UNKNOWN
               && C_WeaponCSBase::GetCSWpnData(this: v7)->m_WeaponType != WEAPONTYPE_C4
               && C_WeaponCSBase::GetCSWpnData(this: v7)->m_WeaponType != WEAPONTYPE_KNIFE )
        {
          newLoadout->m_primaryWeaponID = v4;
        }
      }
      i = ++v4;
      if ( v4 >= WEAPON_C4 )
        break;
      v3 = pPlayer;
    }
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
    return 1;
  }
  else
  {
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10206450
// Name: public: void CCSBuyMenuScaleform::BuyLoadout(class CCSLoadout __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBuyMenuScaleform::BuyLoadout(CCSBuyMenuScaleform *this, CCSLoadout *loadout)
{
  CCSLoadout *v3; // ebx
  CSWeaponID m_primaryWeaponID; // esi
  char *v5; // eax
  CSWeaponID m_secondaryWeaponID; // esi
  char *v7; // eax
  int *p_m_Quantity; // ebx
  bool v9; // cc
  CSWeaponID v10; // esi
  char *v11; // eax
  char *v12; // esi
  char pDest[100]; // [esp+Ch] [ebp-74h] BYREF
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+70h] [ebp-10h] BYREF
  CGameUiSetActiveSplitScreenPlayerGuard v15; // [esp+74h] [ebp-Ch] BYREF
  CGameUiSetActiveSplitScreenPlayerGuard v16; // [esp+78h] [ebp-8h] BYREF
  int i; // [esp+7Ch] [ebp-4h]

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iFlashSlot - 2);
  v3 = loadout;
  m_primaryWeaponID = loadout->m_primaryWeaponID;
  if ( loadout->m_primaryWeaponID != WEAPON_NONE )
  {
    CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
      this: (CGameUiSetActiveSplitScreenPlayerGuard *)&loadout,
      slot: this->m_iFlashSlot - 2);
    v5 = WeaponIdAsString(weaponID: m_primaryWeaponID);
    if ( v5 != nullptr && *v5 != 0 )
      CCSBuyMenuScaleform::BuyWeapon(this, weapShortName: v5 + 7);
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: (CGameUiSetActiveSplitScreenPlayerGuard *)&loadout);
  }
  m_secondaryWeaponID = v3->m_secondaryWeaponID;
  if ( m_secondaryWeaponID != WEAPON_NONE )
  {
    CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
      this: (CGameUiSetActiveSplitScreenPlayerGuard *)&loadout,
      slot: this->m_iFlashSlot - 2);
    v7 = WeaponIdAsString(weaponID: m_secondaryWeaponID);
    if ( v7 != nullptr && *v7 != 0 )
      CCSBuyMenuScaleform::BuyWeapon(this, weapShortName: v7 + 7);
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: (CGameUiSetActiveSplitScreenPlayerGuard *)&loadout);
  }
  p_m_Quantity = &v3->m_EquipmentArray[0].m_Quantity;
  for ( i = 6; i != 0; --i )
  {
    v9 = *p_m_Quantity <= 0;
    loadout = nullptr;
    if ( !v9 )
    {
      do
      {
        v10 = *(p_m_Quantity - 1);
        if ( v10 != WEAPON_NONE )
        {
          CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
            this: &v15,
            slot: this->m_iFlashSlot - 2);
          v11 = WeaponIdAsString(weaponID: v10);
          v12 = v11;
          if ( v11 != nullptr && *v11 != 0 )
          {
            CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
              this: &v16,
              slot: this->m_iFlashSlot - 2);
            V_snprintf(pDest, maxLen: 0x64u, pFormat: "buy %s", v12 + 7);
            engine->ClientCmd(this: engine, a2: pDest);
            this->m_bBoughtSomething = true;
            CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &v16);
          }
          CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &v15);
        }
        loadout = (CCSLoadout *)((char *)loadout + 1);
      }
      while ( (int)loadout < *p_m_Quantity );
    }
    p_m_Quantity += 2;
  }
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x102065B0
// Name: public: void CCSBuyMenuScaleform::BuyLoadoutFromFlash(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSBuyMenuScaleform::BuyLoadoutFromFlash(
        CCSBuyMenuScaleform *this@<ecx>,
        int a2@<edi>,
        IScaleformUI *pui,
        void *params)
{
  C_CSPlayer *LocalPlayer; // eax
  int v6; // eax
  CCSLoadout *v7; // edi
  int v8; // eax
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+4h] [ebp-4h] BYREF

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iFlashSlot - 2);
  LocalPlayer = CClientTools::GetLocalPlayer();
  if ( LocalPlayer != nullptr )
  {
    v6 = ((int (__thiscall *)(C_CSPlayer *, int))LocalPlayer->GetTeamNumber)(a1: LocalPlayer, a2);
    if ( v6 == 2 )
      v7 = s_loadoutArray[0];
    else
      v7 = v6 != 3 ? nullptr : (CCSLoadout *)&unk_10669068;
    v8 = (int)((double (__thiscall *)(IScaleformUI *, void *))this->m_pScaleformUI->Params_GetArgAsNumber)(
                a1: this->m_pScaleformUI,
                a2: params);
    CCSBuyMenuScaleform::BuyLoadout(this, loadout: &v7[v8]);
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
  }
  else
  {
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10206650
// Name: public: void CCSBuyMenuScaleform::BuyPrevious(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBuyMenuScaleform::BuyPrevious(CCSBuyMenuScaleform *this, IScaleformUI *pui, void *obj)
{
  int v4; // ecx
  CCSEquipmentLoadout *m_EquipmentArray; // eax
  C_CSPlayer *LocalPlayer; // eax
  int UserID; // eax
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+4h] [ebp-8h] BYREF
  CGameUiSetActiveSplitScreenPlayerGuard v9; // [esp+8h] [ebp-4h] BYREF

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iFlashSlot - 2);
  if ( this->m_previousPlayerLoadout.m_primaryWeaponID == WEAPON_NONE
    && this->m_previousPlayerLoadout.m_secondaryWeaponID == WEAPON_NONE )
  {
    v4 = 0;
    m_EquipmentArray = this->m_previousPlayerLoadout.m_EquipmentArray;
    while ( m_EquipmentArray->m_EquipmentID == WEAPON_NONE || m_EquipmentArray->m_Quantity == 0 )
    {
      ++v4;
      ++m_EquipmentArray;
      if ( v4 >= 6 )
      {
        if ( this->m_previousPlayerLoadout.m_flags != 0 )
          break;
        CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
          this: &v9,
          slot: this->m_iFlashSlot - 2);
        engine->ClientCmd(this: engine, a2: "autobuy");
        this->m_bBoughtSomething = true;
        CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &v9);
        goto LABEL_10;
      }
    }
  }
  CCSBuyMenuScaleform::BuyLoadout(this, loadout: &this->m_previousPlayerLoadout);
LABEL_10:
  LocalPlayer = CClientTools::GetLocalPlayer();
  if ( LocalPlayer != nullptr )
    UserID = C_BasePlayer::GetUserID(this: LocalPlayer);
  else
    UserID = -1;
  C_CSGameRules::CloseBuyMenu(this: (C_CSGameRules *)g_pGameRules, nPlayerID: UserID);
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x10206710
// Name: public: void CCSBuyMenuScaleform::InitWeapon(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSBuyMenuScaleform::InitWeapon(
        CCSBuyMenuScaleform *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        IScaleformUI *pui,
        void *params)
{
  const char *v6; // eax
  CCSWeaponInfo *WeaponInfo; // ebx
  void *v8; // edi
  void *v9; // eax
  IScaleformUI *m_pScaleformUI; // ecx
  IScaleformUI_vtbl *v11; // edx
  CSWeaponType m_WeaponType; // eax
  __int32 v13; // eax
  bool v14; // zf
  bool (__thiscall *Value_SetMember_2)(IScaleformUI *, void *, const char *, const char *); // eax
  CCSAmmoDef *AmmoDef; // eax
  int v17; // eax
  int WeaponPrice; // eax
  CCSAmmoDef *v19; // eax
  int v20; // eax
  __m128 v21; // xmm2
  __m128 v22; // xmm1
  __m128 v23; // xmm3
  __m128 v24; // xmm0
  __m128 v25; // xmm1
  float m_flCycleTime; // xmm2_4
  __m128 v27; // xmm0
  __m128 v28; // xmm1
  float v29; // xmm2_4
  __m128 v30; // xmm3
  __m128 v31; // xmm1
  __m128 m_flMaxSpeed_low; // xmm0
  __m128 v33; // xmm2
  __m128 v34; // xmm3
  __m128 v35; // xmm1
  __m128 v36; // xmm2
  int iAmmoType; // [esp-8h] [ebp-84h]
  int v38; // [esp-8h] [ebp-84h]
  C_CSPlayer *v40; // [esp-4h] [ebp-80h]
  C_CSPlayer *v41; // [esp-4h] [ebp-80h]
  char pDest[100]; // [esp+4h] [ebp-78h] BYREF
  IScaleformUI_vtbl *v43; // [esp+68h] [ebp-14h]
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+6Ch] [ebp-10h] BYREF
  void *name; // [esp+70h] [ebp-Ch]
  C_CSPlayer *pLocalPlayer; // [esp+74h] [ebp-8h]
  CCSBuyMenuScaleform::WeaponStatPack *pack; // [esp+78h] [ebp-4h]

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iFlashSlot - 2);
  pLocalPlayer = CClientTools::GetLocalPlayer();
  if ( pLocalPlayer != nullptr )
  {
    v6 = this->m_pScaleformUI->Params_GetArgAsString(this: this->m_pScaleformUI, a2: params, a3: 0);
    pDest[0] = 0;
    V_snprintf(pDest, maxLen: 0x64u, pFormat: "weapon_%s", v6);
    pack = (CCSBuyMenuScaleform::WeaponStatPack *)WeaponIdFromString(szWeaponName: pDest);
    WeaponInfo = GetWeaponInfo(weaponID: (CSWeaponID)pack);
    if ( WeaponInfo != nullptr )
    {
      v8 = (void *)((int (__thiscall *)(IScaleformUI *, void *, int, int))this->m_pScaleformUI->Params_CreateNewObject)(
                     a1: this->m_pScaleformUI,
                     a2: params,
                     a3,
                     a4: a2);
      v9 = this->m_pScaleformUI->Params_CreateNewString_2(
             this: this->m_pScaleformUI,
             a2: params,
             a3: WeaponInfo->szPrintName);
      m_pScaleformUI = this->m_pScaleformUI;
      v11 = m_pScaleformUI->__vftable;
      name = v9;
      v11->Value_SetMember_5(this: m_pScaleformUI, a2: v8, a3: "maxCarry", a4: 1);
      if ( pack == (CCSBuyMenuScaleform::WeaponStatPack *)22 )
      {
        ((void (__stdcall *)(void *, const char *, const char *))this->m_pScaleformUI->Value_SetMember_2)(
          a1: v8,
          a2: "weaponType",
          a3: "taser");
      }
      else
      {
        m_WeaponType = WeaponInfo->m_WeaponType;
        if ( m_WeaponType != WEAPONTYPE_KNIFE )
        {
          v13 = m_WeaponType - 1;
          if ( v13 != 0 )
          {
            v14 = v13 == 7;
            Value_SetMember_2 = this->m_pScaleformUI->Value_SetMember_2;
            if ( v14 )
            {
              ((void (__stdcall *)(void *, const char *, const char *))Value_SetMember_2)(
                a1: v8,
                a2: "weaponType",
                a3: "equipment");
              v40 = pLocalPlayer;
              iAmmoType = WeaponInfo->iAmmoType;
              AmmoDef = GetAmmoDef();
              v17 = CAmmoDef::MaxCarry(this: AmmoDef, nAmmoIndex: iAmmoType, owner: v40);
              ((void (__stdcall *)(void *, const char *, int))this->m_pScaleformUI->Value_SetMember_5)(
                a1: v8,
                a2: "maxCarry",
                a3: v17);
            }
            else
            {
              ((void (__stdcall *)(void *, const char *, const char *))Value_SetMember_2)(
                a1: v8,
                a2: "weaponType",
                a3: "primary");
            }
          }
          else
          {
            ((void (__stdcall *)(void *, const char *, const char *))this->m_pScaleformUI->Value_SetMember_2)(
              a1: v8,
              a2: "weaponType",
              a3: "secondary");
          }
        }
      }
      if ( WeaponInfo->m_WeaponType == WEAPONTYPE_PISTOL )
        pack = &this->m_SecondaryStats;
      else
        pack = &this->m_PrimaryStats;
      v43 = this->m_pScaleformUI->ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::__vftable;
      WeaponPrice = CCSWeaponInfo::GetWeaponPrice(this: WeaponInfo);
      v43->Value_SetMember_5(this: this->m_pScaleformUI, a2: v8, a3: "price", a4: WeaponPrice);
      this->m_pScaleformUI->Value_SetMember_6(this: this->m_pScaleformUI, a2: v8, a3: "name", a4: name);
      this->m_pScaleformUI->Value_SetMember_5(
        this: this->m_pScaleformUI,
        a2: v8,
        a3: "clipSize",
        a4: WeaponInfo->iMaxClip1);
      v41 = pLocalPlayer;
      v38 = WeaponInfo->iAmmoType;
      v43 = this->m_pScaleformUI->ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::__vftable;
      v19 = GetAmmoDef();
      v20 = CAmmoDef::MaxCarry(this: v19, nAmmoIndex: v38, owner: v41);
      v43->Value_SetMember_5(this: this->m_pScaleformUI, a2: v8, a3: "maxRounds", a4: v20);
      v21 = (__m128)COERCE_UNSIGNED_INT((float)WeaponInfo->m_iDamage);
      v21.m128_f32[0] = (float)((float)((float)((float)(v21.m128_f32[0] * WeaponInfo->m_flArmorRatio)
                                              - pack->m_FirepowerStat.m_fWorst)
                                      * 100.0)
                              / (float)(pack->m_FirepowerStat.m_fBest - pack->m_FirepowerStat.m_fWorst))
                      + 0.5;
      if ( v21.m128_f32[0] >= 0.0 )
      {
        if ( v21.m128_f32[0] > 100.0 )
          v21 = (__m128)0x42C80000u;
      }
      else
      {
        v21 = 0;
      }
      v22.m128_i32[0] = 1258291200;
      v23 = _mm_and_ps((__m128)0x80000000, v21);
      v22.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v21, v23), v22).m128_f32[0]) & 0x4B000000
                      | v23.m128_i32[0];
      v24 = v21;
      v24.m128_f32[0] = (float)(v21.m128_f32[0] + v22.m128_f32[0]) - v22.m128_f32[0];
      v25 = v24;
      v25.m128_f32[0] = v24.m128_f32[0] - v21.m128_f32[0];
      this->m_pScaleformUI->Value_SetMember_5(
        this: this->m_pScaleformUI,
        a2: v8,
        a3: "firepower",
        a4: (int)(float)(v24.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v25, v23).m128_u32[0] & 0x3F800000)));
      m_flCycleTime = WeaponInfo->m_flCycleTime;
      v27 = 0;
      if ( m_flCycleTime > 0.0 )
      {
        v27 = (__m128)0x3F800000u;
        v27.m128_f32[0] = 1.0 / m_flCycleTime;
      }
      v27.m128_f32[0] = (float)((float)((float)(v27.m128_f32[0] - pack->m_FireRateStat.m_fWorst) * 100.0)
                              / (float)(pack->m_FireRateStat.m_fBest - pack->m_FireRateStat.m_fWorst))
                      + 0.5;
      if ( v27.m128_f32[0] >= 0.0 )
      {
        if ( v27.m128_f32[0] > 100.0 )
          v27 = (__m128)0x42C80000u;
      }
      else
      {
        v27 = 0;
      }
      v28.m128_i32[0] = 1258291200;
      v29 = v27.m128_f32[0];
      v30 = _mm_and_ps((__m128)0x80000000, v27);
      v28.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v27, v30), v28).m128_f32[0]) & 0x4B000000
                      | v30.m128_i32[0];
      v27.m128_f32[0] = (float)(v27.m128_f32[0] + v28.m128_f32[0]) - v28.m128_f32[0];
      v31 = v27;
      v31.m128_f32[0] = v27.m128_f32[0] - v29;
      this->m_pScaleformUI->Value_SetMember_5(
        this: this->m_pScaleformUI,
        a2: v8,
        a3: "fireRate",
        a4: (int)(float)(v27.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v31, v30).m128_u32[0] & 0x3F800000)));
      m_flMaxSpeed_low = (__m128)LODWORD(WeaponInfo->m_flMaxSpeed);
      m_flMaxSpeed_low.m128_f32[0] = (float)((float)((float)(m_flMaxSpeed_low.m128_f32[0] - pack->m_MovementStat.m_fWorst)
                                                   * 100.0)
                                           / (float)(pack->m_MovementStat.m_fBest - pack->m_MovementStat.m_fWorst))
                                   + 0.5;
      if ( m_flMaxSpeed_low.m128_f32[0] >= 0.0 )
      {
        if ( m_flMaxSpeed_low.m128_f32[0] > 100.0 )
          m_flMaxSpeed_low = (__m128)0x42C80000u;
      }
      else
      {
        m_flMaxSpeed_low = 0;
      }
      v33.m128_i32[0] = 1258291200;
      v34 = _mm_and_ps((__m128)0x80000000, m_flMaxSpeed_low);
      v33.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(m_flMaxSpeed_low, v34), v33).m128_f32[0])
                      & 0x4B000000
                      | v34.m128_i32[0];
      v35 = m_flMaxSpeed_low;
      v35.m128_f32[0] = (float)(m_flMaxSpeed_low.m128_f32[0] + v33.m128_f32[0]) - v33.m128_f32[0];
      v36 = v35;
      v36.m128_f32[0] = v35.m128_f32[0] - m_flMaxSpeed_low.m128_f32[0];
      this->m_pScaleformUI->Value_SetMember_5(
        this: this->m_pScaleformUI,
        a2: v8,
        a3: "moveRate",
        a4: (int)(float)(v35.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v36, v34).m128_u32[0] & 0x3F800000)));
      ((void (__thiscall *)(IScaleformUI *, void *))this->m_pScaleformUI->Value_SetMember_5)(
        a1: this->m_pScaleformUI,
        a2: v8);
      this->m_pScaleformUI->Params_SetResult_6(this: this->m_pScaleformUI, a2: params, a3: v8);
      if ( this->m_pScaleformUI != nullptr )
      {
        if ( name != nullptr )
          this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: name);
        if ( this->m_pScaleformUI != nullptr && v8 != nullptr )
          this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v8);
      }
    }
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
  }
  else
  {
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10206C50
// Name: public: void CCSBuyMenuScaleform::OnCancel(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBuyMenuScaleform::OnCancel(CCSBuyMenuScaleform *this, IScaleformUI *pui, void *obj)
{
  C_CSPlayer *LocalPlayer; // eax
  int UserID; // eax
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+4h] [ebp-4h] BYREF

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iFlashSlot - 2);
  if ( this->m_bBoughtSomething
    && CCSBuyMenuScaleform::FillInPlayerLoadout(this, newLoadout: &this->m_previousPlayerLoadout) != 0 )
  {
    CCSBuyMenuScaleform::UpdateLoadouts(this);
  }
  LocalPlayer = CClientTools::GetLocalPlayer();
  if ( LocalPlayer != nullptr )
    UserID = C_BasePlayer::GetUserID(this: LocalPlayer);
  else
    UserID = -1;
  C_CSGameRules::CloseBuyMenu(this: (C_CSGameRules *)g_pGameRules, nPlayerID: UserID);
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x10206CC0
// Name: public: void CCSBuyMenuScaleform::SetPlayerIsCT(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSBuyMenuScaleform::SetPlayerIsCT(CCSBuyMenuScaleform *this@<ecx>, int a2@<edi>, BOOL value)
{
  void *v4; // edi
  char i; // al
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+4h] [ebp-4h] BYREF

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iFlashSlot - 2);
  if ( this->m_bFlashAPIIsValid )
  {
    v4 = (void *)((int (__thiscall *)(IScaleformUI *, int, int))this->m_pScaleformUI->CreateValueArray)(
                   a1: this->m_pScaleformUI,
                   a2: 1,
                   a3: a2);
    this->m_pScaleformUI->ValueArray_SetElement_3(this: this->m_pScaleformUI, a2: v4, a3: 0, a4: value);
    for ( i = 1; i != 0; i = 0 )
    {
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      this->m_pScaleformUI->Value_InvokeWithoutReturn(
        this: this->m_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "setPlayerIsCT",
        a4: v4,
        a5: 1u);
    }
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
    ((void (__thiscall *)(IScaleformUI *, void *))this->m_pScaleformUI->ReleaseValueArray)(
      a1: this->m_pScaleformUI,
      a2: v4);
  }
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x10206D80
// Name: public: void CCSBuyMenuScaleform::UpdatePlayerCash(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSBuyMenuScaleform::UpdatePlayerCash(
        CCSBuyMenuScaleform *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        bool force)
{
  C_CSPlayer *LocalPlayer; // eax
  int Account; // ebx
  void *v7; // edi
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_bFlashAPIIsValid )
  {
    CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
      this: &g_UISSGuard,
      slot: this->m_iFlashSlot - 2);
    LocalPlayer = CClientTools::GetLocalPlayer();
    Account = 0;
    if ( LocalPlayer != nullptr )
      Account = C_CSPlayer::GetAccount(this: LocalPlayer);
    if ( Account != this->m_iCurrentCashDisplayed || force )
    {
      v7 = (void *)((int (__thiscall *)(IScaleformUI *, int, int, int))this->m_pScaleformUI->CreateValueArray)(
                     a1: this->m_pScaleformUI,
                     a2: 1,
                     a3,
                     a4: a2);
      this->m_pScaleformUI->ValueArray_SetElement_5(this: this->m_pScaleformUI, a2: v7, a3: 0, a4: Account);
      for ( i = 1; ; i = 0 )
      {
        m_pScaleformUI = this->m_pScaleformUI;
        if ( i == 0 )
          break;
        if ( m_pScaleformUI != nullptr )
          m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
        this->m_pScaleformUI->Value_InvokeWithoutReturn(
          this: this->m_pScaleformUI,
          a2: this->m_FlashAPI,
          a3: "setPlayerCash",
          a4: v7,
          a5: 1u);
      }
      if ( m_pScaleformUI != nullptr )
        m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
      ((void (__thiscall *)(IScaleformUI *))this->m_pScaleformUI->ReleaseValueArray)(a1: this->m_pScaleformUI);
      this->m_iCurrentCashDisplayed = Account;
    }
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10206E60
// Name: public: bool CCSBuyMenuScaleform::UpdateTimeLeft(bool)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CCSBuyMenuScaleform::UpdateTimeLeft@<al>(CCSBuyMenuScaleform *this@<ecx>, int a2@<edi>, bool force)
{
  double v4; // st7
  float v5; // xmm0_4
  double v6; // st7
  __m128 v7; // xmm0
  __m128 v8; // xmm2
  __m128 v9; // xmm3
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  int v12; // edi
  IScaleformUI *m_pScaleformUI; // ecx
  __m128 v14; // xmm1
  __m128 v15; // xmm3
  __m128 v16; // xmm0
  __m128 v17; // xmm1
  void *v18; // ebx
  char i; // al
  IScaleformUI *v20; // ecx
  float roundElapsedTimea; // [esp+14h] [ebp-4h]
  float roundElapsedTime; // [esp+14h] [ebp-4h]

  if ( !this->m_bFlashAPIIsValid )
    return 0;
  v4 = C_CSGameRules::GetRoundElapsedTime(this: (C_CSGameRules *)g_pGameRules);
  if ( v4 <= 0.0 )
  {
    v5 = 0.0;
  }
  else
  {
    roundElapsedTimea = v4;
    v5 = roundElapsedTimea;
  }
  v6 = C_CSGameRules::GetBuyTimeLength(this: (C_CSGameRules *)g_pGameRules) - v5;
  roundElapsedTime = v6;
  if ( v6 <= 0.0 )
    return 1;
  v7 = (__m128)LODWORD(roundElapsedTime);
  v7.m128_f32[0] = roundElapsedTime * 5.0;
  v8.m128_i32[0] = 1258291200;
  v9 = _mm_and_ps((__m128)0x80000000, v7);
  v8.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v7, v9), v8).m128_f32[0]) & 0x4B000000 | v9.m128_i32[0];
  v10 = v7;
  v10.m128_f32[0] = (float)((float)(roundElapsedTime * 5.0) + v8.m128_f32[0]) - v8.m128_f32[0];
  v11 = v10;
  v11.m128_f32[0] = v10.m128_f32[0] - (float)(roundElapsedTime * 5.0);
  v12 = (int)(float)(v10.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v11, v9).m128_u32[0] & 0x3F800000));
  if ( !force && v12 == this->m_iCurrentTimeLeft )
    return 0;
  m_pScaleformUI = this->m_pScaleformUI;
  this->m_iCurrentTimeLeft = v12;
  v14.m128_i32[0] = 1258291200;
  v15 = _mm_and_ps((__m128)0x80000000, (__m128)LODWORD(roundElapsedTime));
  v14.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps((__m128)LODWORD(roundElapsedTime), v15), v14).m128_f32[0])
                  & 0x4B000000
                  | v15.m128_i32[0];
  v16 = (__m128)LODWORD(roundElapsedTime);
  v16.m128_f32[0] = (float)(roundElapsedTime + v14.m128_f32[0]) - v14.m128_f32[0];
  v17 = v16;
  v17.m128_f32[0] = v16.m128_f32[0] - roundElapsedTime;
  v18 = (void *)((int (__thiscall *)(IScaleformUI *, int, int))m_pScaleformUI->CreateValueArray)(
                  a1: m_pScaleformUI,
                  a2: 2,
                  a3: a2);
  ((void (__thiscall *)(IScaleformUI *, void *, _DWORD, _DWORD))this->m_pScaleformUI->ValueArray_SetElement_4)(
    a1: this->m_pScaleformUI,
    a2: v18,
    a3: 0,
    a4: v16.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v17, v15).m128_u32[0] & 0x3F800000));
  this->m_pScaleformUI->ValueArray_SetElement_3(this: this->m_pScaleformUI, a2: v18, a3: 1, a4: v12 % 5 <= 2);
  for ( i = 1; ; i = 0 )
  {
    v20 = this->m_pScaleformUI;
    if ( i == 0 )
      break;
    if ( v20 != nullptr )
      v20->LockSlot(this: v20, a2: this->m_iFlashSlot);
    this->m_pScaleformUI->Value_InvokeWithoutReturn(
      this: this->m_pScaleformUI,
      a2: this->m_FlashAPI,
      a3: "setBuyTimeLeft",
      a4: v18,
      a5: 2u);
  }
  if ( v20 != nullptr )
    v20->UnlockSlot(this: v20, a2: this->m_iFlashSlot);
  ((void (__thiscall *)(IScaleformUI *, void *))this->m_pScaleformUI->ReleaseValueArray)(
    a1: this->m_pScaleformUI,
    a2: v18);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10207070
// Name: public: void CCSBuyMenuScaleform::SetRadialSelection(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSBuyMenuScaleform::SetRadialSelection(
        CCSBuyMenuScaleform *this@<ecx>,
        int a2@<edi>,
        int iNewSelection)
{
  IScaleformUI *m_pScaleformUI; // ecx
  void *v5; // edi
  char i; // al
  IScaleformUI *v7; // ecx

  if ( this->m_bFlashAPIIsValid && iNewSelection != this->m_iCurrentRadialSelection )
  {
    m_pScaleformUI = this->m_pScaleformUI;
    this->m_iCurrentRadialSelection = iNewSelection;
    v5 = (void *)((int (__thiscall *)(IScaleformUI *, int, int))m_pScaleformUI->CreateValueArray)(
                   a1: m_pScaleformUI,
                   a2: 1,
                   a3: a2);
    this->m_pScaleformUI->ValueArray_SetElement_5(
      this: this->m_pScaleformUI,
      a2: v5,
      a3: 0,
      a4: this->m_iCurrentRadialSelection);
    for ( i = 1; ; i = 0 )
    {
      v7 = this->m_pScaleformUI;
      if ( i == 0 )
        break;
      if ( v7 != nullptr )
        v7->LockSlot(this: v7, a2: this->m_iFlashSlot);
      this->m_pScaleformUI->Value_InvokeWithoutReturn(
        this: this->m_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "setWedgeHighlight",
        a4: v5,
        a5: 1u);
    }
    if ( v7 != nullptr )
      v7->UnlockSlot(this: v7, a2: this->m_iFlashSlot);
    ((void (__thiscall *)(IScaleformUI *, void *))this->m_pScaleformUI->ReleaseValueArray)(
      a1: this->m_pScaleformUI,
      a2: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10207120
// Name: public: void CCSBuyMenuScaleform::UpdateRadialSelection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBuyMenuScaleform::UpdateRadialSelection(CCSBuyMenuScaleform *this)
{
  int v2; // edi
  float v3; // xmm0_4
  float v4; // xmm1_4
  __m128 v5; // xmm2
  __m128 v6; // xmm1
  __m128 v7; // xmm3
  __m128 v8; // xmm0
  __m128 v9; // xmm1
  float v10; // [esp+8h] [ebp-8h]
  float normalized_xpos; // [esp+Ch] [ebp-4h]

  v2 = -1;
  if ( this->m_bFlashAPIIsValid )
  {
    normalized_xpos = this->m_pScaleformUI->GetJoyValue(
                        this: this->m_pScaleformUI,
                        a2: this->m_iFlashSlot - 2,
                        a3: 0,
                        a4: 0);
    v3 = normalized_xpos;
  }
  else
  {
    v3 = 0.0;
    normalized_xpos = 0.0;
  }
  if ( this->m_bFlashAPIIsValid )
  {
    v10 = this->m_pScaleformUI->GetJoyValue(this: this->m_pScaleformUI, a2: this->m_iFlashSlot - 2, a3: 0, a4: 1);
    v4 = v10;
    v3 = normalized_xpos;
  }
  else
  {
    v4 = 0.0;
  }
  if ( fsqrt(
         (float)(COERCE_FLOAT(LODWORD(v4) ^ _mask__NegFloat_) * COERCE_FLOAT(LODWORD(v4) ^ _mask__NegFloat_))
       + (float)(v3 * v3)) > 0.25 )
  {
    __libm_sse2_atan2();
    v5 = 0;
    v5.m128_f32[0] = v3 * 57.29578;
    if ( (float)(v3 * 57.29578) < 0.0 )
      v5.m128_f32[0] = v5.m128_f32[0] + 360.0;
    v5.m128_f32[0] = v5.m128_f32[0] * 0.016666668;
    v6.m128_i32[0] = 1258291200;
    v7 = _mm_and_ps((__m128)0x80000000, v5);
    v6.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v5, v7), v6).m128_f32[0]) & 0x4B000000 | v7.m128_i32[0];
    v8 = v5;
    v8.m128_f32[0] = (float)(v5.m128_f32[0] + v6.m128_f32[0]) - v6.m128_f32[0];
    v9 = v8;
    v9.m128_f32[0] = v8.m128_f32[0] - v5.m128_f32[0];
    v2 = ((int)(float)(v8.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v9, v7).m128_u32[0] & 0x3F800000)) + 1) % 6;
  }
  CCSBuyMenuScaleform::SetRadialSelection(this, a2: v2, iNewSelection: v2);
}

//------------------------------------------------------------------------------
// Address: 0x102073B0
// Name: public: CCSEquipmentLoadout::CCSEquipmentLoadout(void)
// Source: json
//------------------------------------------------------------------------------
CCSEquipmentLoadout *__thiscall CCSEquipmentLoadout::CCSEquipmentLoadout(CCSEquipmentLoadout *this)
{
  this->m_EquipmentID = WEAPON_NONE;
  this->m_Quantity = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102073C0
// Name: public: void CCSBuyMenuScaleform::ReportLoadouts(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSBuyMenuScaleform::ReportLoadouts(
        CCSBuyMenuScaleform *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        IScaleformUI *pui,
        void *obj)
{
  C_CSPlayer *LocalPlayer; // eax
  int v7; // eax
  CCSLoadout *v8; // edi
  void *FlashArray; // eax
  CSWeaponID *p_m_secondaryWeaponID; // ecx
  int v11; // ebx
  int v12; // eax
  IScaleformUI_vtbl *v13; // edi
  int v14; // eax
  void *v15; // ebx
  bool v16; // zf
  void *result; // [esp+4h] [ebp-14h]
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+8h] [ebp-10h] BYREF
  void *weapons; // [esp+Ch] [ebp-Ch]
  void *prices; // [esp+10h] [ebp-8h]
  CSWeaponID *i; // [esp+14h] [ebp-4h]

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iFlashSlot - 2);
  LocalPlayer = CClientTools::GetLocalPlayer();
  if ( LocalPlayer != nullptr )
  {
    v7 = ((int (__thiscall *)(C_CSPlayer *, int, int))LocalPlayer->GetTeamNumber)(a1: LocalPlayer, a2: a3, a3: a2);
    if ( v7 == 2 )
      v8 = s_loadoutArray[0];
    else
      v8 = v7 != 3 ? nullptr : (CCSLoadout *)&unk_10669068;
    result = ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::CreateFlashObject(this);
    weapons = ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::CreateFlashArray(this, length: 6);
    FlashArray = ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::CreateFlashArray(this, length: 6);
    p_m_secondaryWeaponID = &v8->m_secondaryWeaponID;
    prices = FlashArray;
    v11 = 0;
    for ( i = &v8->m_secondaryWeaponID; ; p_m_secondaryWeaponID = i )
    {
      v12 = *((_DWORD *)p_m_secondaryWeaponID - 1);
      if ( v12 == 0 )
      {
        v12 = *p_m_secondaryWeaponID;
        if ( *p_m_secondaryWeaponID == WEAPON_NONE )
        {
          v12 = 22;
          if ( (p_m_secondaryWeaponID[13] & 1) == 0 )
            v12 = *((_DWORD *)p_m_secondaryWeaponID + 1);
        }
      }
      this->m_pScaleformUI->Value_SetArrayElement_5(this: this->m_pScaleformUI, a2: weapons, a3: v11, a4: v12);
      v13 = this->m_pScaleformUI->ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::__vftable;
      v14 = CCSBuyMenuScaleform::PriceLoadout(this, loadout: (const CCSLoadout *)(i - 1));
      v13->Value_SetArrayElement_5(this: this->m_pScaleformUI, a2: prices, a3: v11, a4: v14);
      i += 15;
      if ( ++v11 >= 6 )
        break;
    }
    v15 = weapons;
    ((void (__thiscall *)(IScaleformUI *, void *))this->m_pScaleformUI->Value_SetMember_6)(
      a1: this->m_pScaleformUI,
      a2: result);
    this->m_pScaleformUI->Value_SetMember_6(this: this->m_pScaleformUI, a2: result, a3: "prices", a4: prices);
    this->m_pScaleformUI->Params_SetResult_6(this: this->m_pScaleformUI, a2: obj, a3: result);
    v16 = this->m_pScaleformUI == nullptr;
    if ( this->m_pScaleformUI != nullptr )
    {
      if ( result != nullptr )
        this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: result);
      v16 = this->m_pScaleformUI == nullptr;
      if ( this->m_pScaleformUI != nullptr )
      {
        if ( v15 != nullptr )
          this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v15);
        v16 = this->m_pScaleformUI == nullptr;
      }
    }
    if ( !v16 && prices != nullptr )
      this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: prices);
  }
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x10207540
// Name: public: void __near * CCSBuyMenuScaleform::CreateFlashLoadout(class CCSLoadout const __near &)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CCSBuyMenuScaleform::CreateFlashLoadout(CCSBuyMenuScaleform *this, const CCSLoadout *loadout)
{
  void *FlashObject; // eax
  int v4; // edi
  CCSEquipmentLoadout *m_EquipmentArray; // ecx
  int v6; // eax
  void *FlashArray; // ebx
  CCSWeaponInfo *WeaponInfo; // eax
  int WeaponPrice; // eax
  CCSWeaponInfo *v10; // eax
  int v11; // eax
  CCSWeaponInfo *v12; // eax
  int v13; // eax
  int *v14; // ebx
  CCSWeaponInfo *v15; // eax
  int v16; // eax
  bool v17; // zf
  void *weaponArray; // [esp+Ch] [ebp-10h]
  void *v20; // [esp+10h] [ebp-Ch]
  int price; // [esp+14h] [ebp-8h]
  char *weaponCountArray; // [esp+18h] [ebp-4h]
  void *weaponCountArraya; // [esp+18h] [ebp-4h]
  int j; // [esp+24h] [ebp+8h]

  FlashObject = ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::CreateFlashObject(this);
  v4 = 0;
  m_EquipmentArray = loadout->m_EquipmentArray;
  v20 = FlashObject;
  price = 0;
  v6 = 0;
  while ( m_EquipmentArray->m_EquipmentID != WEAPON_NONE && m_EquipmentArray->m_Quantity != 0 )
  {
    ++v6;
    ++m_EquipmentArray;
    if ( v6 >= 6 )
    {
      weaponCountArray = nullptr;
      goto LABEL_6;
    }
  }
  weaponCountArray = (char *)v6;
LABEL_6:
  if ( (loadout->m_flags & 1) != 0 )
    ++weaponCountArray;
  if ( loadout->m_primaryWeaponID != WEAPON_NONE )
    ++weaponCountArray;
  if ( loadout->m_secondaryWeaponID != WEAPON_NONE )
    ++weaponCountArray;
  FlashArray = ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::CreateFlashArray(this, length: (int)weaponCountArray);
  weaponArray = FlashArray;
  weaponCountArraya = ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::CreateFlashArray(
                        this,
                        length: (int)weaponCountArray);
  if ( loadout->m_primaryWeaponID != WEAPON_NONE )
  {
    this->m_pScaleformUI->Value_SetArrayElement_5(
      this: this->m_pScaleformUI,
      a2: FlashArray,
      a3: 0,
      a4: loadout->m_primaryWeaponID);
    this->m_pScaleformUI->Value_SetArrayElement_5(this: this->m_pScaleformUI, a2: weaponCountArraya, a3: 0, a4: 1);
    this->m_pScaleformUI->Value_SetMember_5(this: this->m_pScaleformUI, a2: v20, a3: "primary", a4: 0);
    WeaponInfo = GetWeaponInfo(weaponID: loadout->m_primaryWeaponID);
    if ( WeaponInfo != nullptr )
      WeaponPrice = CCSWeaponInfo::GetWeaponPrice(this: WeaponInfo);
    else
      WeaponPrice = 0;
    price = WeaponPrice;
    v4 = 1;
  }
  if ( loadout->m_secondaryWeaponID != WEAPON_NONE )
  {
    this->m_pScaleformUI->Value_SetArrayElement_5(
      this: this->m_pScaleformUI,
      a2: FlashArray,
      a3: v4,
      a4: loadout->m_secondaryWeaponID);
    this->m_pScaleformUI->Value_SetArrayElement_5(this: this->m_pScaleformUI, a2: weaponCountArraya, a3: v4, a4: 1);
    this->m_pScaleformUI->Value_SetMember_5(this: this->m_pScaleformUI, a2: v20, a3: "secondary", a4: v4);
    v10 = GetWeaponInfo(weaponID: loadout->m_secondaryWeaponID);
    if ( v10 != nullptr )
      v11 = CCSWeaponInfo::GetWeaponPrice(this: v10);
    else
      v11 = 0;
    price += v11;
    ++v4;
  }
  if ( (loadout->m_flags & 1) != 0 )
  {
    this->m_pScaleformUI->Value_SetArrayElement_5(this: this->m_pScaleformUI, a2: FlashArray, a3: v4, a4: 22);
    this->m_pScaleformUI->Value_SetArrayElement_5(this: this->m_pScaleformUI, a2: weaponCountArraya, a3: v4, a4: 1);
    this->m_pScaleformUI->Value_SetMember_5(this: this->m_pScaleformUI, a2: v20, a3: "taser", a4: v4);
    v12 = GetWeaponInfo(weaponID: WEAPON_TASER);
    if ( v12 != nullptr )
      v13 = CCSWeaponInfo::GetWeaponPrice(this: v12);
    else
      v13 = 0;
    price += v13;
    ++v4;
  }
  v14 = (int *)loadout->m_EquipmentArray;
  for ( j = 0; j < 6; ++j )
  {
    if ( *v14 == 0 || v14[1] == 0 )
      break;
    this->m_pScaleformUI->Value_SetArrayElement_5(this: this->m_pScaleformUI, a2: weaponArray, a3: v4, a4: *v14);
    this->m_pScaleformUI->Value_SetArrayElement_5(this: this->m_pScaleformUI, a2: weaponCountArraya, a3: v4, a4: v14[1]);
    v15 = GetWeaponInfo(weaponID: (CSWeaponID)*v14);
    v16 = v15 != nullptr ? CCSWeaponInfo::GetWeaponPrice(this: v15) : 0;
    price += v16 * v14[1];
    ++v4;
    v14 += 2;
  }
  this->m_pScaleformUI->Value_SetMember_6(this: this->m_pScaleformUI, a2: v20, a3: "weapons", a4: weaponArray);
  this->m_pScaleformUI->Value_SetMember_6(this: this->m_pScaleformUI, a2: v20, a3: "counts", a4: weaponCountArraya);
  this->m_pScaleformUI->Value_SetMember_5(this: this->m_pScaleformUI, a2: v20, a3: "price", a4: price);
  v17 = this->m_pScaleformUI == nullptr;
  if ( this->m_pScaleformUI != nullptr )
  {
    if ( weaponArray != nullptr )
      this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: weaponArray);
    v17 = this->m_pScaleformUI == nullptr;
  }
  if ( !v17 && weaponCountArraya != nullptr )
    this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: weaponCountArraya);
  return v20;
}

//------------------------------------------------------------------------------
// Address: 0x10207800
// Name: public: void CCSBuyMenuScaleform::GetPredefinedLoadout(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSBuyMenuScaleform::GetPredefinedLoadout(
        CCSBuyMenuScaleform *this@<ecx>,
        int a2@<edi>,
        IScaleformUI *pui,
        void *obj)
{
  C_CSPlayer *LocalPlayer; // eax
  int v6; // eax
  CCSLoadout *v7; // edi
  int v8; // eax
  void *FlashLoadout; // edi
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+4h] [ebp-4h] BYREF

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iFlashSlot - 2);
  LocalPlayer = CClientTools::GetLocalPlayer();
  if ( LocalPlayer != nullptr )
  {
    v6 = ((int (__thiscall *)(C_CSPlayer *, int))LocalPlayer->GetTeamNumber)(a1: LocalPlayer, a2);
    if ( v6 == 2 )
      v7 = s_loadoutArray[0];
    else
      v7 = v6 != 3 ? nullptr : (CCSLoadout *)&unk_10669068;
    v8 = (int)((double (__thiscall *)(IScaleformUI *, void *))this->m_pScaleformUI->Params_GetArgAsNumber)(
                a1: this->m_pScaleformUI,
                a2: obj);
    FlashLoadout = CCSBuyMenuScaleform::CreateFlashLoadout(this, loadout: &v7[v8]);
    this->m_pScaleformUI->Params_SetResult_6(this: this->m_pScaleformUI, a2: obj, a3: FlashLoadout);
    if ( this->m_pScaleformUI != nullptr && FlashLoadout != nullptr )
      this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: FlashLoadout);
  }
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x102078C0
// Name: public: void CCSBuyMenuScaleform::UpdatePlayerLoadout(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSBuyMenuScaleform::UpdatePlayerLoadout(
        CCSBuyMenuScaleform *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        bool force,
        bool pushToScaleform)
{
  void *v6; // edi
  void *FlashLoadout; // ebx
  char i; // al
  CCSLoadout newLoadout; // [esp+4h] [ebp-3Ch] BYREF

  memset(&newLoadout, 0, 57);
  if ( CCSBuyMenuScaleform::FillInPlayerLoadout(this, &newLoadout) != 0
    && (force || CCSLoadout::operator==(this: &newLoadout, in_rhs: &this->m_currentPlayerLoadout) == 0) )
  {
    CCSLoadout::operator=(this: &this->m_currentPlayerLoadout, in_rhs: &newLoadout);
    if ( pushToScaleform )
    {
      v6 = (void *)((int (__thiscall *)(IScaleformUI *, int, int, int))this->m_pScaleformUI->CreateValueArray)(
                     a1: this->m_pScaleformUI,
                     a2: 1,
                     a3,
                     a4: a2);
      FlashLoadout = CCSBuyMenuScaleform::CreateFlashLoadout(this, loadout: &this->m_currentPlayerLoadout);
      this->m_pScaleformUI->ValueArray_SetElement_6(this: this->m_pScaleformUI, a2: v6, a3: 0, a4: FlashLoadout);
      for ( i = 1; i != 0; i = 0 )
      {
        if ( this->m_pScaleformUI != nullptr )
          this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
        this->m_pScaleformUI->Value_InvokeWithoutReturn(
          this: this->m_pScaleformUI,
          a2: this->m_FlashAPI,
          a3: "setPlayerLoadout",
          a4: v6,
          a5: 1u);
      }
      if ( this->m_pScaleformUI != nullptr )
      {
        this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
        if ( this->m_pScaleformUI != nullptr && FlashLoadout != nullptr )
          this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: FlashLoadout);
      }
      ((void (__thiscall *)(IScaleformUI *))this->m_pScaleformUI->ReleaseValueArray)(a1: this->m_pScaleformUI);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102079F0
// Name: public: void CCSBuyMenuScaleform::GetWeaponShortNameFromID(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBuyMenuScaleform::GetWeaponShortNameFromID(CCSBuyMenuScaleform *this, IScaleformUI *pui, void *obj)
{
  long double v4; // st7
  char *v5; // eax
  void *FlashString; // edi

  v4 = this->m_pScaleformUI->Params_GetArgAsNumber(this: this->m_pScaleformUI, a2: obj, a3: 0);
  v5 = WeaponIdAsString(weaponID: (CSWeaponID)v4);
  if ( v5 != nullptr && *v5 != 0 )
  {
    FlashString = ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::CreateFlashString(this, value: v5 + 7);
    this->m_pScaleformUI->Params_SetResult_6(this: this->m_pScaleformUI, a2: obj, a3: FlashString);
    if ( this->m_pScaleformUI != nullptr && FlashString != nullptr )
      this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: FlashString);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10207A60
// Name: public: virtual void CCSBuyMenuScaleform::ViewportThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CCSBuyMenuScaleform::ViewportThink(CCSBuyMenuScaleform *this@<ecx>, int a1@<esi>, int a3@<ebx>)
{
  float v4; // xmm0_4

  CCSBuyMenuScaleform::UpdateRadialSelection(this: (CCSBuyMenuScaleform *)((char *)this - 20));
  if ( CCSBuyMenuScaleform::UpdateTimeLeft(
         this: (CCSBuyMenuScaleform *)((char *)this - 20),
         a2: (int)this,
         force: false) != 0 )
  {
    CCSBuyMenuScaleform::OnCancel(this: (CCSBuyMenuScaleform *)((char *)this - 20), pui: nullptr, obj: nullptr);
    PrintBuyTimeOverMessage(a1);
  }
  else
  {
    v4 = *(float *)(gpGlobals.m_Index + 12);
    if ( v4 >= this->m_PrimaryStats.m_FireRateStat.m_fWorst )
    {
      this->m_PrimaryStats.m_FireRateStat.m_fWorst = v4 + 0.25;
      CCSBuyMenuScaleform::UpdatePlayerCash(
        this: (CCSBuyMenuScaleform *)((char *)this - 20),
        a2: a3,
        a3: (int)this,
        force: false);
      CCSBuyMenuScaleform::UpdatePlayerLoadout(
        this: (CCSBuyMenuScaleform *)((char *)this - 20),
        a2: a3,
        a3: (int)this,
        force: false,
        pushToScaleform: true);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10207AD0
// Name: public: virtual void CCSBuyMenuScaleform::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBuyMenuScaleform::FireGameEvent(CCSBuyMenuScaleform *this, IGameEvent *event)
{
  C_CSPlayer *LocalPlayer; // ebx
  char i; // al
  int v6; // edi
  int v7; // edi
  C_CSGameRules *v8; // esi
  int UserID; // eax
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+Ch] [ebp-4h] BYREF
  const char *newTeam; // [esp+18h] [ebp+8h]
  int newTeama; // [esp+18h] [ebp+8h]

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: *((_DWORD *)this - 3) - 2);
  newTeam = event->GetName(this: event);
  LocalPlayer = CClientTools::GetLocalPlayer();
  if ( _V_strcmp(s1: newTeam, s2: "cs_game_disconnected") != 0 )
  {
    if ( _V_strcmp(s1: newTeam, s2: "player_team") != 0 )
    {
      if ( _V_strcmp(s1: newTeam, s2: "player_death") == 0 && LocalPlayer != nullptr )
      {
        v7 = event->GetInt(this: event, a2: "userid", a3: 0);
        if ( C_BasePlayer::GetUserID(this: LocalPlayer) == v7
          && BYTE1(this->m_PrimaryStats.m_MovementStat.m_fWorst) != 0 )
        {
          v8 = (C_CSGameRules *)g_pGameRules;
          UserID = C_BasePlayer::GetUserID(this: LocalPlayer);
          C_CSGameRules::CloseBuyMenu(this: v8, nPlayerID: UserID);
        }
      }
    }
    else if ( LocalPlayer != nullptr )
    {
      newTeama = event->GetInt(this: event, a2: "team", a3: 0);
      v6 = event->GetInt(this: event, a2: "userid", a3: 0);
      if ( C_BasePlayer::GetUserID(this: LocalPlayer) == v6 )
      {
        CCSBuyMenuScaleform::SetPlayerIsCT(
          this: (CCSBuyMenuScaleform *)((char *)this - 24),
          a2: v6,
          value: newTeama == 3);
        CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
        return;
      }
    }
  }
  else if ( *((_BYTE *)this - 8) != 0 )
  {
    if ( BYTE1(this->m_PrimaryStats.m_MovementStat.m_fWorst) != 0 )
    {
      for ( i = 1; i != 0; i = 0 )
      {
        if ( *((_DWORD *)this - 5) != 0 )
          (*(void (__thiscall **)(_DWORD, _DWORD))(**((_DWORD **)this - 5) + 64))(
            a1: *((_DWORD *)this - 5),
            a2: *((_DWORD *)this - 3));
        g_pScaleformUI->Value_InvokeWithoutReturn(
          this: g_pScaleformUI,
          a2: *((void **)this - 4),
          a3: "hidePanelAndRemove",
          a4: nullptr,
          a5: 0);
      }
      if ( *((_DWORD *)this - 5) != 0 )
      {
        (*(void (__thiscall **)(_DWORD, _DWORD))(**((_DWORD **)this - 5) + 68))(
          a1: *((_DWORD *)this - 5),
          a2: *((_DWORD *)this - 3));
        CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
        return;
      }
    }
    else if ( *((_BYTE *)this - 8) != 0 )
    {
      (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD))(**((_DWORD **)this - 5) + 76))(
        a1: *((_DWORD *)this - 5),
        a2: *((_DWORD *)this - 3),
        a3: *((_DWORD *)this - 4));
      CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
      return;
    }
  }
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x10207CA0
// Name: public: CCSBuyMenuScaleform::CCSBuyMenuScaleform(class CounterStrikeViewport __near *)
// Source: json
//------------------------------------------------------------------------------
CCSBuyMenuScaleform *__thiscall CCSBuyMenuScaleform::CCSBuyMenuScaleform(
        CCSBuyMenuScaleform *this,
        CounterStrikeViewport *pViewPort)
{
  _DWORD *v3; // ecx

  this->m_bFlashAPIIsValid = false;
  this->m_pScaleformUI = nullptr;
  this->m_FlashAPI = nullptr;
  this->m_iFlashSlot = -1;
  this->IViewPortPanel::__vftable = (IViewPortPanel_vtbl *)&IViewPortPanel::`vftable';
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  this->m_bRegisteredForEvents = false;
  this->m_nDebugID = 42;
  this->ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::__vftable = (CCSBuyMenuScaleform_vtbl *)&CCSBuyMenuScaleform::`vftable'{for `ScaleformFlashInterfaceMixin<ScaleformEmptyClass>'};
  this->IViewPortPanel::__vftable = (IViewPortPanel_vtbl *)&CCSBuyMenuScaleform::`vftable'{for `IViewPortPanel'};
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CCSBuyMenuScaleform::`vftable'{for `CGameEventListener'};
  this->m_pViewPort = pViewPort;
  this->m_SecondaryStats.m_FirepowerStat.m_fBest = 1.1754944e-38;
  this->m_SecondaryStats.m_FirepowerStat.m_fWorst = 3.4028235e38;
  this->m_SecondaryStats.m_FireRateStat.m_fBest = 1.1754944e-38;
  this->m_SecondaryStats.m_FireRateStat.m_fWorst = 3.4028235e38;
  this->m_SecondaryStats.m_AccuracyStat.m_fBest = 1.1754944e-38;
  this->m_SecondaryStats.m_AccuracyStat.m_fWorst = 3.4028235e38;
  this->m_SecondaryStats.m_MovementStat.m_fBest = 1.1754944e-38;
  this->m_SecondaryStats.m_MovementStat.m_fWorst = 3.4028235e38;
  this->m_PrimaryStats.m_FirepowerStat.m_fBest = 1.1754944e-38;
  this->m_PrimaryStats.m_FirepowerStat.m_fWorst = 3.4028235e38;
  this->m_PrimaryStats.m_FireRateStat.m_fBest = 1.1754944e-38;
  this->m_PrimaryStats.m_FireRateStat.m_fWorst = 3.4028235e38;
  this->m_PrimaryStats.m_AccuracyStat.m_fBest = 1.1754944e-38;
  this->m_PrimaryStats.m_AccuracyStat.m_fWorst = 3.4028235e38;
  this->m_PrimaryStats.m_MovementStat.m_fBest = 1.1754944e-38;
  this->m_PrimaryStats.m_MovementStat.m_fWorst = 3.4028235e38;
  this->m_fNextUpdateTime = 0.0;
  this->m_iCurrentRadialSelection = -1;
  this->m_iCurrentCashDisplayed = 0;
  this->m_iCurrentTimeLeft = 0;
  *(_WORD *)&this->m_bBoughtSomething = 0;
  this->m_bLoading = false;
  this->m_currentPlayerLoadout.m_primaryWeaponID = WEAPON_NONE;
  this->m_currentPlayerLoadout.m_secondaryWeaponID = WEAPON_NONE;
  this->m_currentPlayerLoadout.m_flags = 0;
  this->m_currentPlayerLoadout.m_EquipmentArray[0].m_EquipmentID = WEAPON_NONE;
  this->m_currentPlayerLoadout.m_EquipmentArray[1].m_EquipmentID = WEAPON_NONE;
  this->m_currentPlayerLoadout.m_EquipmentArray[0].m_Quantity = 0;
  this->m_currentPlayerLoadout.m_EquipmentArray[1].m_Quantity = 0;
  this->m_currentPlayerLoadout.m_EquipmentArray[2].m_EquipmentID = WEAPON_NONE;
  this->m_currentPlayerLoadout.m_EquipmentArray[2].m_Quantity = 0;
  this->m_currentPlayerLoadout.m_EquipmentArray[3].m_EquipmentID = WEAPON_NONE;
  this->m_currentPlayerLoadout.m_EquipmentArray[3].m_Quantity = 0;
  this->m_currentPlayerLoadout.m_EquipmentArray[4].m_EquipmentID = WEAPON_NONE;
  this->m_currentPlayerLoadout.m_EquipmentArray[4].m_Quantity = 0;
  this->m_currentPlayerLoadout.m_EquipmentArray[5].m_EquipmentID = WEAPON_NONE;
  this->m_currentPlayerLoadout.m_EquipmentArray[5].m_Quantity = 0;
  this->m_previousPlayerLoadout.m_primaryWeaponID = WEAPON_NONE;
  this->m_previousPlayerLoadout.m_secondaryWeaponID = WEAPON_NONE;
  this->m_previousPlayerLoadout.m_flags = 0;
  this->m_previousPlayerLoadout.m_EquipmentArray[0].m_EquipmentID = WEAPON_NONE;
  this->m_previousPlayerLoadout.m_EquipmentArray[1].m_EquipmentID = WEAPON_NONE;
  this->m_previousPlayerLoadout.m_EquipmentArray[0].m_Quantity = 0;
  this->m_previousPlayerLoadout.m_EquipmentArray[1].m_Quantity = 0;
  this->m_previousPlayerLoadout.m_EquipmentArray[2].m_EquipmentID = WEAPON_NONE;
  this->m_previousPlayerLoadout.m_EquipmentArray[2].m_Quantity = 0;
  this->m_previousPlayerLoadout.m_EquipmentArray[3].m_EquipmentID = WEAPON_NONE;
  this->m_previousPlayerLoadout.m_EquipmentArray[3].m_Quantity = 0;
  this->m_previousPlayerLoadout.m_EquipmentArray[4].m_EquipmentID = WEAPON_NONE;
  this->m_previousPlayerLoadout.m_EquipmentArray[4].m_Quantity = 0;
  this->m_previousPlayerLoadout.m_EquipmentArray[5].m_EquipmentID = WEAPON_NONE;
  this->m_previousPlayerLoadout.m_EquipmentArray[5].m_Quantity = 0;
  this->m_iSplitScreenSlot = 0;
  if ( s_loadoutArray[0][0].m_primaryWeaponID == WEAPON_NONE && dword_10668F04 == 0 )
  {
    v3 = &unk_10668F08;
    while ( *v3 == 0 || v3[1] == 0 )
    {
      v3 += 2;
      if ( (int)v3 >= (int)&byte_10668F38 )
      {
        if ( byte_10668F38 == 0 )
          InitBuyMenuLoadoutData();
        return this;
      }
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10207E60
// Name: public: virtual char const __near * CCSBuyMenuScaleform::GetName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCSBuyMenuScaleform::GetName(CCSBuyMenuScaleform *this)
{
  return "buy";
}

//------------------------------------------------------------------------------
// Address: 0x10207E70
// Name: public: virtual bool CCSBuyMenuScaleform::IsVisible(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBuyMenuScaleform::IsVisible(CCSBuyMenuScaleform *this)
{
  return BYTE1(this->m_fNextUpdateTime);
}

//------------------------------------------------------------------------------
// Address: 0x10207EA0
// Name: public: virtual CCSBuyMenuScaleform::~CCSBuyMenuScaleform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBuyMenuScaleform::~CCSBuyMenuScaleform(CCSBuyMenuScaleform *this)
{
  CGameEventListener *v2; // esi
  bool v3; // zf

  v2 = &this->CGameEventListener;
  this->ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::__vftable = (CCSBuyMenuScaleform_vtbl *)&CCSBuyMenuScaleform::`vftable'{for `ScaleformFlashInterfaceMixin<ScaleformEmptyClass>'};
  this->IViewPortPanel::__vftable = (IViewPortPanel_vtbl *)&CCSBuyMenuScaleform::`vftable'{for `IViewPortPanel'};
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CCSBuyMenuScaleform::`vftable'{for `CGameEventListener'};
  if ( this->m_bRegisteredForEvents )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: v2);
    v2->m_bRegisteredForEvents = false;
  }
  v3 = !v2->m_bRegisteredForEvents;
  v2->__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  v2->m_nDebugID = 13;
  if ( !v3 )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: v2);
    v2->m_bRegisteredForEvents = false;
  }
  v2->__vftable = (CGameEventListener_vtbl *)&IGameEventListener2::`vftable';
  v3 = !this->m_bFlashAPIIsValid;
  this->IViewPortPanel::__vftable = (IViewPortPanel_vtbl *)&IViewPortPanel::`vftable';
  this->ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::__vftable = (CCSBuyMenuScaleform_vtbl *)&ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::`vftable';
  if ( !v3 )
    this->m_pScaleformUI->RemoveElement(this: this->m_pScaleformUI, a2: this->m_iFlashSlot, a3: this->m_FlashAPI);
}

//------------------------------------------------------------------------------
// Address: 0x10207F30
// Name: public: void CCSBuyMenuScaleform::Show(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CCSBuyMenuScaleform::Show(CCSBuyMenuScaleform *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx
  int m_iFlashSlot; // eax
  int v7; // edx
  int v8; // eax
  int v9; // [esp+0h] [ebp-24h]
  BOOL v10; // [esp+4h] [ebp-20h]
  const char *v11; // [esp+8h] [ebp-1Ch]
  SplitScreenConVarRef pHideHud; // [esp+10h] [ebp-14h] BYREF
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+20h] [ebp-4h] BYREF

  if ( this->m_bLoading )
    goto LABEL_12;
  if ( !this->m_bFlashAPIIsValid )
  {
    this->m_bLoading = true;
    g_pScaleformUI->RequestElement(
      this: g_pScaleformUI,
      a2: this->m_iSplitScreenSlot + 2,
      a3: "BuyMenu",
      a4: (ScaleformUIFunctionHandlerObject *)this,
      a5: pScaleformFunctionHandler_CCSBuyMenuScaleform_BuyMenu);
LABEL_12:
    this->m_bVisible = true;
    return;
  }
  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iFlashSlot - 2);
  LOBYTE(v11) = 1;
  LOBYTE(v10) = 1;
  this->m_bBoughtSomething = false;
  this->m_fNextUpdateTime = 0.0;
  this->m_iCurrentTimeLeft = 0;
  CCSBuyMenuScaleform::UpdatePlayerLoadout(this, a2, a3, force: v10, pushToScaleform: (bool)v11);
  CCSBuyMenuScaleform::UpdatePlayerCash(this, a2, a3, force: true);
  CCSBuyMenuScaleform::UpdateTimeLeft(this, a2: a3, force: true);
  for ( i = 1; ; i = 0 )
  {
    m_pScaleformUI = this->m_pScaleformUI;
    if ( i == 0 )
      break;
    if ( m_pScaleformUI != nullptr )
      m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
    g_pScaleformUI->Value_InvokeWithoutReturn(
      this: g_pScaleformUI,
      a2: this->m_FlashAPI,
      a3: "showPanel",
      a4: nullptr,
      a5: 0);
  }
  if ( m_pScaleformUI != nullptr )
    m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
  v11 = "hidehud";
  this->m_iCurrentRadialSelection = -1;
  SplitScreenConVarRef::SplitScreenConVarRef(this: &pHideHud, pName: v11);
  m_iFlashSlot = this->m_iFlashSlot;
  v7 = *(_DWORD *)(*(&v10 + 2 * m_iFlashSlot) + 48);
  v8 = *(&v9 + 2 * m_iFlashSlot);
  this->m_PrevHideHudValue = v7;
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v8 + 4))(a1: v8, a2: 4);
  g_pMatSystemSurface->EnableWindowsMessages(this: g_pMatSystemSurface, a2: false);
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
  this->m_bVisible = true;
}

//------------------------------------------------------------------------------
// Address: 0x10208080
// Name: public: virtual void CCSBuyMenuScaleform::ShowPanel(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSBuyMenuScaleform::ShowPanel(
        CCSBuyMenuScaleform *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        bool bShow)
{
  CCSBuyMenuScaleform *v4; // ecx

  if ( bShow != BYTE1(this->m_fNextUpdateTime) )
  {
    v4 = (CCSBuyMenuScaleform *)((char *)this - 20);
    if ( bShow )
      CCSBuyMenuScaleform::Show(this: v4, a2, a3);
    else
      CCSBuyMenuScaleform::Hide(this: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102080B0
// Name: public: void CCSBuyMenuScaleform::GetPlayerLoadout(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBuyMenuScaleform::GetPlayerLoadout(CCSBuyMenuScaleform *this, IScaleformUI *pui, void *params)
{
  void *FlashLoadout; // edi
  CCSLoadout newLoadout; // [esp+Ch] [ebp-3Ch] BYREF

  memset(&newLoadout, 0, 57);
  if ( CCSBuyMenuScaleform::FillInPlayerLoadout(this, &newLoadout) != 0 )
    CCSLoadout::operator=(this: &this->m_currentPlayerLoadout, in_rhs: &newLoadout);
  FlashLoadout = CCSBuyMenuScaleform::CreateFlashLoadout(this, loadout: &this->m_currentPlayerLoadout);
  this->m_pScaleformUI->Params_SetResult_6(this: this->m_pScaleformUI, a2: params, a3: FlashLoadout);
  if ( this->m_pScaleformUI != nullptr && FlashLoadout != nullptr )
    this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: FlashLoadout);
}

//------------------------------------------------------------------------------
// Address: 0x10208180
// Name: public: virtual void CCSBuyMenuScaleform::FlashReady(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CCSBuyMenuScaleform::FlashReady(CCSBuyMenuScaleform *this@<ecx>, int a2@<ebx>)
{
  C_CSPlayer *LocalPlayer; // eax
  int v4; // eax
  bool v5; // zf
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+4h] [ebp-4h] BYREF

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iFlashSlot - 2);
  LocalPlayer = CClientTools::GetLocalPlayer();
  if ( LocalPlayer != nullptr )
  {
    v4 = LocalPlayer->GetTeamNumber(this: LocalPlayer);
    CCSBuyMenuScaleform::SetPlayerIsCT(this, a2: (int)this, value: v4 == 3);
  }
  CCSBuyMenuScaleform::CalculateBestStats(this);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->CGameEventListener,
    a3: "cs_game_disconnected",
    a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "player_team", a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "player_death", a4: false);
  v5 = !this->m_bVisible;
  this->m_bLoading = false;
  if ( v5 )
    CCSBuyMenuScaleform::Hide(this);
  else
    CCSBuyMenuScaleform::Show(this, a2, a3: (int)this);
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x10427940
// Name: _dynamic_initializer_for__buymenu_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__buymenu_command__()
{
  ConCommand::ConCommand(
    this: &buymenu_command,
    pName: "buymenu",
    callback: buymenu,
    pHelpString: "Show main buy menu",
    flags: 0x10000000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__buymenu_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10435DA0
// Name: _dynamic_atexit_destructor_for__buymenu_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__buymenu_command__()
{
  ConCommand::~ConCommand(this: &buymenu_command);
}
