// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/bot/states/cs_bot_buy.cpp
// Functions: 7
// ============================================================

#include "game\server\cstrike15\bot\states\cs_bot_buy.h"

//------------------------------------------------------------------------------
// Address: 0x102D1BF0
// Name: public: void CCSBot::GiveWeapon(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::GiveWeapon(CCSBot *this, const char *weaponAlias)
{
  const char *TranslatedWeaponAlias; // eax
  unsigned __int16 v4; // di
  CStringRegistry *v5; // ecx
  FileWeaponInfo_t *FileWeaponInfoFromHandle; // eax
  _DWORD *v7; // edi
  int v8; // edi
  char wpnName[128]; // [esp+8h] [ebp-80h] BYREF

  TranslatedWeaponAlias = GetTranslatedWeaponAlias(szAlias: weaponAlias);
  V_snprintf(pDest: wpnName, maxLen: 128, pFormat: "weapon_%s", TranslatedWeaponAlias);
  v4 = LookupWeaponInfoSlot(name: wpnName);
  if ( v4 != (unsigned __int16)GetInvalidWeaponInfoHandle(this: v5) )
  {
    FileWeaponInfoFromHandle = GetFileWeaponInfoFromHandle(handle: v4);
    v7 = __RTDynamicCast(
           inptr: FileWeaponInfoFromHandle,
           VfDelta: 0,
           SrcType: &FileWeaponInfo_t `RTTI Type Descriptor',
           TargetType: &CCSWeaponInfo `RTTI Type Descriptor',
           isReference: 0);
    if ( v7 != nullptr )
    {
      if ( this->Weapon_OwnsThisType(this, a2: wpnName, a3: 0) == nullptr
        && this->Weapon_GetSlot(this, a2: v7[86]) != nullptr )
      {
        v8 = v7[86];
        if ( v8 == 1 )
        {
          CCSPlayer::DropPistol(this, fromDeath: false);
        }
        else if ( v8 == 0 )
        {
          CCSPlayer::DropRifle(this, fromDeath: false);
        }
      }
      this->GiveNamedItem(this, a2: wpnName, a3: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D1CD0
// Name: HasDefaultPistol
// Source: json
//------------------------------------------------------------------------------
bool __usercall HasDefaultPistol@<al>(CCSBot *me@<edi>)
{
  CBaseCombatWeapon *v1; // esi

  v1 = me->Weapon_GetSlot(this: me, a2: 1);
  return v1 != nullptr
      && (CBaseEntity::GetTeamNumber(this: me) == 2
       && ((int (__thiscall *)(CBaseCombatWeapon *))v1->__vftable[1].GetModelName)(a1: v1) == 4
       || CBaseEntity::GetTeamNumber(this: me) == 3
       && ((int (__thiscall *)(CBaseCombatWeapon *))v1->__vftable[1].GetModelName)(a1: v1) == 23);
}

//------------------------------------------------------------------------------
// Address: 0x102D1D30
// Name: enum WeaponType GetWeaponType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
WeaponType __cdecl GetWeaponType(const char *alias)
{
  int v1; // edi
  int i; // esi
  int v3; // edi
  int v4; // esi

  v1 = 0;
  for ( i = 0; i < 16; ++i )
  {
    if ( _V_stricmp(s1: alias, s2: primaryWeaponBuyInfoCT[i].buyAlias) == 0 )
      return primaryWeaponBuyInfoCT[v1].type;
    if ( _V_stricmp(s1: alias, s2: primaryWeaponBuyInfoT[i].buyAlias) == 0 )
      return primaryWeaponBuyInfoT[v1].type;
    ++v1;
  }
  v3 = 0;
  v4 = 0;
  while ( 1 )
  {
    if ( _V_stricmp(s1: alias, s2: secondaryWeaponBuyInfoCT[v4].buyAlias) == 0 )
      return secondaryWeaponBuyInfoCT[v3].type;
    if ( _V_stricmp(s1: alias, s2: secondaryWeaponBuyInfoT[v4].buyAlias) == 0 )
      break;
    ++v4;
    ++v3;
    if ( v4 >= 3 )
      return NUM_WEAPON_TYPES;
  }
  return secondaryWeaponBuyInfoT[v3].type;
}

//------------------------------------------------------------------------------
// Address: 0x102D1DF0
// Name: public: virtual void BuyState::OnExit(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BuyState::OnExit(BuyState *this, CCSBot *me)
{
  CCSBot::ResetStuckMonitor(this: me);
  CCSBot::EquipBestWeapon(this: me, mustEquip: false);
}

//------------------------------------------------------------------------------
// Address: 0x102D1E10
// Name: public: virtual void BuyState::OnEnter(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall BuyState::OnEnter(BuyState *this, CCSBot *me)
{
  char *m_pszString; // eax
  CCSBot *v4; // edi
  IUniformRandomStream *v5; // ecx
  CCSBotManager *v6; // edi
  IUniformRandomStream *v7; // ecx

  this->m_retries = 0;
  this->m_prefRetries = 0;
  this->m_prefIndex = 0;
  if ( (bot_loadout.m_nFlags & 0x1000) != 0
    || (m_pszString = bot_loadout.m_pParent->m_Value.m_pszString) != nullptr && *m_pszString != 0
    || (unsigned __int8)CCSGameRules::IsPlayingGunGameSelect(this: (CCSGameRules *)g_pGameRules) != 0 )
  {
    v4 = me;
LABEL_6:
    this->m_doneBuying = false;
    goto LABEL_7;
  }
  v4 = me;
  if ( cv_bot_eco_limit.m_pParent->m_Value.m_fValue <= (float)me->m_iAccount.m_Value )
    goto LABEL_6;
  CBot<CCSPlayer>::PrintIfWatched(this: me, format: "Saving money for next round.\n");
  this->m_doneBuying = true;
LABEL_7:
  this->m_isInitialDelay = true;
  CCSBot::EquipBestWeapon(this: v4, mustEquip: true);
  this->m_buyShield = false;
  if ( CBaseEntity::GetTeamNumber(this: v4) == 3 )
    CCSPlayer::HasPrimaryWeapon(this: v4);
  this->m_buyGrenade = cv_bot_allow_grenades.m_pParent != nullptr
                    && cv_bot_allow_grenades.m_pParent->m_Value.m_nValue != 0
                    && _RandomFloat(this: v5, a2: 0.0, a3: 100.0) < 33.299999;
  this->m_buyPistol = false;
  if ( cv_bot_allow_pistols.m_pParent != nullptr && cv_bot_allow_pistols.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( v4->Weapon_GetSlot(this: v4, a2: 1) != nullptr )
    {
      if ( !HasDefaultPistol(me: v4) )
        return;
      if ( (cv_bot_allow_shotguns.m_pParent != nullptr && cv_bot_allow_shotguns.m_pParent->m_Value.m_nValue != 0
         || (v6 = (CCSBotManager *)TheBots, CCSBotManager::AllowSubMachineGuns(this: (CCSBotManager *)TheBots))
         || CCSBotManager::AllowRifles(this: v6)
         || CCSBotManager::AllowMachineGuns(this: v6)
         || CCSBotManager::AllowSnipers(this: v6))
        && (v7 = (IUniformRandomStream *)me, me->m_iAccount.m_Value >= 1000) )
      {
        if ( _RandomFloat(this: (IUniformRandomStream *)me, a2: 0.0, a3: 100.0) < 33.299999 )
        {
          this->m_buyPistol = true;
          return;
        }
      }
      else if ( _RandomFloat(this: v7, a2: 0.0, a3: 100.0) < 75.0 )
      {
        this->m_buyPistol = true;
        return;
      }
      this->m_buyPistol = false;
    }
    else
    {
      this->m_buyPistol = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D2020
// Name: public: virtual void BuyState::OnUpdate(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall BuyState::OnUpdate(BuyState *this, CCSBot *me)
{
  bool v2; // zf
  char *m_pszString; // eax
  int i; // ebx
  const char *v7; // edi
  edict_t *m_pPev; // ecx
  ConVar *v9; // eax
  const char *v10; // eax
  IUniformRandomStream *v11; // ecx
  int v12; // eax
  const char *v13; // edi
  BuyState *v14; // edx
  const BotProfile *m_profile; // ecx
  int m_prefIndex; // eax
  char v17; // bl
  int v18; // edi
  const char *WeaponPreferenceAsString; // eax
  const char *v20; // edi
  bool v21; // al
  IUniformRandomStream *v22; // ecx
  BuyInfo *v23; // ebx
  IUniformRandomStream *v24; // ecx
  WeaponType type; // edi
  int v26; // eax
  int v27; // edi
  int v28; // eax
  int v29; // ecx
  int v30; // eax
  int v31; // edx
  int v32; // edi
  bool HasPrimaryWeapon; // al
  BuyState *v34; // ebx
  int m_retries; // eax
  IUniformRandomStream *v36; // ecx
  int v37; // edi
  char *buyAlias; // eax
  IUniformRandomStream *v39; // ecx
  double v40; // st7
  int TeamNumber; // eax
  CCommand args; // [esp+30h] [ebp-654h] BYREF
  char cmdBuffer[256]; // [esp+538h] [ebp-14Ch] BYREF
  _DWORD v44[8]; // [esp+638h] [ebp-4Ch]
  char pDest[8]; // [esp+658h] [ebp-2Ch] BYREF
  CSplitString weapons; // [esp+660h] [ebp-24h] BYREF
  int j; // [esp+678h] [ebp-Ch]
  int stockPrimaryCount; // [esp+67Ch] [ebp-8h]
  BuyState *v49; // [esp+680h] [ebp-4h]
  int savedregs; // [esp+684h] [ebp+0h] BYREF
  float rnd; // [esp+68Ch] [ebp+8h]
  bool rnd_3; // [esp+68Fh] [ebp+Bh]

  v2 = !TheNavMesh->m_isLoaded;
  v49 = this;
  if ( v2 )
    return;
  if ( this->m_isInitialDelay )
  {
    if ( (float)(gpGlobals->curtime - me->m_stateTimestamp) < 0.25 )
      return;
    this->m_isInitialDelay = false;
  }
  if ( this->m_doneBuying )
  {
    if ( g_pGameRules->IsMultiplayer(this: g_pGameRules)
      && CCSGameRules::IsFreezePeriod(this: (CCSGameRules *)g_pGameRules) )
    {
      CCSBot::EquipBestWeapon(this: me, mustEquip: true);
      me->Reload(this: me);
      CCSBot::ResetStuckMonitor(this: me);
    }
    else
    {
      CCSBot::Idle(this: me);
    }
    return;
  }
  if ( (bot_loadout.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
LABEL_14:
    CSplitString::CSplitString(this: &weapons, pString: m_pszString, pSeparator: " ");
    for ( i = 0; i < weapons.m_Size; ++i )
    {
      v7 = weapons.m_Memory.m_pMemory[i];
      if ( v7 != "vest" && _V_stricmp(s1: v7, s2: "vest") != 0 )
      {
        if ( v7 != "vesthelm" && _V_stricmp(s1: v7, s2: "vesthelm") != 0 )
        {
          if ( FStrEq(sz1: v7, sz2: "defuser") )
          {
            if ( CBaseEntity::GetTeamNumber(this: me) == 3 )
              CCSPlayer::GiveDefuser(this: me, bPickedUp: false);
          }
          else if ( FStrEq(sz1: v7, sz2: "nvgs") )
          {
            if ( !me->m_bHasNightVision.m_Value )
            {
              if ( me->m_Network.m_TimerEvent.m_bRegistered )
              {
                *((_BYTE *)&me->m_Network + 76) |= 1u;
                me->m_bHasNightVision.m_Value = true;
              }
              else
              {
                m_pPev = me->m_Network.m_pPev;
                if ( m_pPev != nullptr )
                  CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x135Du);
                me->m_bHasNightVision.m_Value = true;
              }
            }
          }
          else if ( FStrEq(sz1: v7, sz2: "primammo") )
          {
            CCSPlayer::AttemptToBuyAmmo(this: me, iAmmoType: 0);
          }
          else if ( FStrEq(sz1: v7, sz2: "secammo") )
          {
            CCSPlayer::AttemptToBuyAmmo(this: me, iAmmoType: 1u);
          }
          else
          {
            CCSBot::GiveWeapon(this: me, weaponAlias: v7);
          }
        }
        else
        {
          me->GiveNamedItem(this: me, a2: "item_assaultsuit", a3: 0);
        }
      }
      else
      {
        me->GiveNamedItem(this: me, a2: "item_kevlar", a3: 0);
      }
    }
    v49->m_doneBuying = true;
    CSplitString::~CSplitString(this: &weapons);
    return;
  }
  m_pszString = bot_loadout.m_pParent->m_Value.m_pszString;
  if ( m_pszString != nullptr && *m_pszString != 0 )
    goto LABEL_14;
  if ( (unsigned __int8)CCSGameRules::IsPlayingGunGameSelect(this: (CCSGameRules *)g_pGameRules) != 0 )
  {
    v2 = CBaseEntity::GetTeamNumber(this: me) == 3;
    v9 = &bot_gungameselect_weapons_ct;
    if ( !v2 )
      v9 = &bot_gungameselect_weapons_t;
    if ( (v9->m_nFlags & 0x1000) != 0 )
    {
      v10 = "FCVAR_NEVER_AS_STRING";
LABEL_45:
      CSplitString::CSplitString(this: &weapons, pString: v10, pSeparator: " ");
      v12 = _RandomInt(this: v11, a2: 0, a3: weapons.m_Size - 1);
      CCSBot::GiveWeapon(this: me, weaponAlias: weapons.m_Memory.m_pMemory[v12]);
      this->m_doneBuying = true;
      CSplitString::~CSplitString(this: &weapons);
      return;
    }
    v10 = v9->m_pParent->m_Value.m_pszString;
    if ( v10 != nullptr && *v10 != 0 )
      goto LABEL_45;
  }
  if ( !CCSPlayer::IsInBuyZone(this: me) )
  {
    this->m_doneBuying = true;
    v13 = "CT";
    if ( CBaseEntity::GetTeamNumber(this: me) != 3 )
      v13 = "Terrorist";
    if ( (me->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: me, a2: (int)&savedregs);
    if ( (me->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: me, a2: (int)&savedregs);
    if ( (me->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: me, a2: (int)&savedregs);
    CONSOLE_ECHO(
      pszMsg: "%s bot spawned outside of a buy zone (%d, %d, %d)\n",
      v13,
      (int)me->m_vecAbsOrigin.x,
      (int)me->m_vecAbsOrigin.y,
      (int)me->m_vecAbsOrigin.z);
    return;
  }
  if ( (float)(gpGlobals->curtime - me->m_stateTimestamp) <= 0.02 )
    return;
  v14 = v49;
  m_profile = me->m_profile;
  me->m_stateTimestamp = gpGlobals->curtime;
  m_prefIndex = v14->m_prefIndex;
  v17 = 1;
  if ( m_prefIndex < m_profile->m_weaponPreferenceCount
    && (bot_randombuy.m_pParent == nullptr || bot_randombuy.m_pParent->m_Value.m_nValue == 0) )
  {
    if ( v14->m_prefRetries >= 2 )
    {
      v14->m_prefIndex = m_prefIndex + 1;
      v14->m_prefRetries = 0;
      return;
    }
    v18 = m_profile->m_weaponPreference[m_prefIndex];
    WeaponPreferenceAsString = BotProfile::GetWeaponPreferenceAsString(this: m_profile, i: v14->m_prefIndex);
    V_snprintf(pDest, maxLen: 32, pFormat: "weapon_%s", WeaponPreferenceAsString);
    if ( me->Weapon_OwnsThisType(this: me, a2: pDest, a3: 0) != nullptr )
    {
      v49->m_prefIndex = 9999;
      return;
    }
    if ( IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove(this: (vgui::ToggleButton *)me) )
    {
      if ( v18 == 38 )
      {
        v49->m_prefIndex = 9999;
        return;
      }
    }
    else if ( v18 == 38 )
    {
      goto LABEL_78;
    }
    v20 = WeaponIDToAlias(id: v18);
    switch ( GetWeaponType(alias: v20) )
    {
      case PISTOL:
        v21 = CCSBotManager::AllowPistols(this: (CCSBotManager *)TheBots);
        goto LABEL_75;
      case SHOTGUN:
        v21 = CCSBotManager::AllowShotguns(this: (CCSBotManager *)TheBots);
        goto LABEL_75;
      case SUB_MACHINE_GUN:
        v21 = CCSBotManager::AllowSubMachineGuns(this: (CCSBotManager *)TheBots);
        goto LABEL_75;
      case RIFLE:
        v21 = CCSBotManager::AllowRifles(this: (CCSBotManager *)TheBots);
        goto LABEL_75;
      case MACHINE_GUN:
        v21 = CCSBotManager::AllowMachineGuns(this: (CCSBotManager *)TheBots);
        goto LABEL_75;
      case SNIPER_RIFLE:
        v21 = CCSBotManager::AllowSnipers(this: (CCSBotManager *)TheBots);
LABEL_75:
        if ( v21 )
          goto LABEL_76;
        break;
      default:
LABEL_76:
        if ( v20 != nullptr )
        {
          V_snprintf(pDest: cmdBuffer, maxLen: 256, pFormat: "buy %s\n", v20);
          CCommand::CCommand(this: &args);
          CCommand::Tokenize(this: &args, pCommand: cmdBuffer, pBreakSet: nullptr);
          me->ClientCommand(this: me, a2: &args);
          CBot<CCSPlayer>::PrintIfWatched(this: me, format: "Tried to buy preferred weapon %s.\n", v20);
          v17 = 0;
        }
        break;
    }
LABEL_78:
    ++v49->m_prefRetries;
    if ( v17 == 0 )
      return;
  }
  if ( !CCSPlayer::HasPrimaryWeapon(this: me) )
  {
    if ( v49->m_buyShield )
    {
      CCommand::CCommand(this: &args);
      CCommand::Tokenize(this: &args, pCommand: "buy shield", pBreakSet: nullptr);
      me->ClientCommand(this: me, a2: &args);
      CBot<CCSPlayer>::PrintIfWatched(this: me, format: "Tried to buy a shield.\n");
    }
    else
    {
      v23 = primaryWeaponBuyInfoT;
      if ( CBaseEntity::GetTeamNumber(this: me) != 2 )
        v23 = primaryWeaponBuyInfoCT;
      stockPrimaryCount = 0;
      rnd_3 = _RandomFloat(this: v22, a2: 0.0, a3: 100.0) < 50.0;
      if ( bot_randombuy.m_pParent != nullptr && bot_randombuy.m_pParent->m_Value.m_nValue != 0 )
        rnd_3 = true;
      for ( j = 16; j != 0; --j )
      {
        type = v23->type;
        if ( v23->type == SHOTGUN && CCSBotManager::AllowShotguns(this: (CCSBotManager *)TheBots)
          || type == SUB_MACHINE_GUN && CCSBotManager::AllowSubMachineGuns(this: (CCSBotManager *)TheBots)
          || type == RIFLE && CCSBotManager::AllowRifles(this: (CCSBotManager *)TheBots)
          || type == SNIPER_RIFLE && CCSBotManager::AllowSnipers(this: (CCSBotManager *)TheBots) && rnd_3
          || type == MACHINE_GUN && CCSBotManager::AllowMachineGuns(this: (CCSBotManager *)TheBots) )
        {
          v26 = stockPrimaryCount;
          v44[stockPrimaryCount] = v23;
          stockPrimaryCount = v26 + 1;
        }
        ++v23;
      }
      if ( stockPrimaryCount != 0 )
      {
        if ( v49->m_retries != 0
          || CCSBotManager::GetDifficultyLevel() < BOT_HARD
          || bot_randombuy.m_pParent != nullptr && bot_randombuy.m_pParent->m_Value.m_nValue != 0 )
        {
          goto LABEL_116;
        }
        v27 = stockPrimaryCount;
        v24 = nullptr;
        v28 = 0;
        if ( stockPrimaryCount <= 0 )
          goto LABEL_116;
        do
        {
          if ( *(_BYTE *)(v44[v28] + 4) != 0 )
            v24 = (IUniformRandomStream *)((char *)v24 + 1);
          ++v28;
        }
        while ( v28 < stockPrimaryCount );
        if ( v24 == nullptr )
        {
LABEL_116:
          v30 = _RandomInt(this: v24, a2: 0, a3: stockPrimaryCount - 1);
        }
        else
        {
          v29 = _RandomInt(this: (IUniformRandomStream *)((char *)v24 - 1), a2: 0, a3: (int)&v24[-1].__vftable + 3);
          v30 = 0;
          do
          {
            if ( *(_BYTE *)(v44[v30] + 4) != 0 )
            {
              v31 = v29--;
              if ( v31 == 0 )
                break;
            }
            ++v30;
          }
          while ( v30 < v27 );
        }
        v32 = v44[v30];
        V_snprintf(pDest: cmdBuffer, maxLen: 256, pFormat: "buy %s\n", *(const char **)(v32 + 8));
        CCommand::CCommand(this: &args);
        CCommand::Tokenize(this: &args, pCommand: cmdBuffer, pBreakSet: nullptr);
        me->ClientCommand(this: me, a2: &args);
        CBot<CCSPlayer>::PrintIfWatched(this: me, format: "Tried to buy %s.\n", *(const char **)(v32 + 8));
      }
    }
  }
  HasPrimaryWeapon = CCSPlayer::HasPrimaryWeapon(this: me);
  v34 = v49;
  if ( HasPrimaryWeapon || (m_retries = v49->m_retries, v49->m_retries = m_retries + 1, m_retries > 5) )
  {
    CCommand::CCommand(this: &args);
    if ( CCSPlayer::HasPrimaryWeapon(this: me) )
    {
      CCommand::Tokenize(this: &args, pCommand: "buy primammo", pBreakSet: nullptr);
      me->ClientCommand(this: me, a2: &args);
    }
    CCommand::Tokenize(this: &args, pCommand: "buy vesthelm", pBreakSet: nullptr);
    me->ClientCommand(this: me, a2: &args);
    CCommand::Tokenize(this: &args, pCommand: "buy vest", pBreakSet: nullptr);
    me->ClientCommand(this: me, a2: &args);
    if ( CCSBotManager::AllowPistols(this: (CCSBotManager *)TheBots)
      && BotProfile::HasPistolPreference(this: me->m_profile) == 0 )
    {
      if ( v34->m_buyPistol )
      {
        v37 = _RandomInt(this: v36, a2: 0, a3: 2);
        if ( CBaseEntity::GetTeamNumber(this: me) == 2 )
          buyAlias = secondaryWeaponBuyInfoT[v37].buyAlias;
        else
          buyAlias = secondaryWeaponBuyInfoCT[v37].buyAlias;
        V_snprintf(pDest: cmdBuffer, maxLen: 256, pFormat: "buy %s\n", buyAlias);
        CCommand::Tokenize(this: &args, pCommand: cmdBuffer, pBreakSet: nullptr);
        me->ClientCommand(this: me, a2: &args);
        v34->m_buyPistol = false;
      }
      CCommand::Tokenize(this: &args, pCommand: "buy secammo", pBreakSet: nullptr);
      me->ClientCommand(this: me, a2: &args);
    }
    if ( !v34->m_buyGrenade || CCSBot::HasGrenade(this: me) )
      goto LABEL_144;
    v40 = _RandomFloat(this: v39, a2: 0.0, a3: 100.0);
    rnd = v40;
    if ( v40 < 10.0 )
    {
      CCommand::Tokenize(this: &args, pCommand: "buy smokegrenade", pBreakSet: nullptr);
LABEL_143:
      me->ClientCommand(this: me, a2: &args);
LABEL_144:
      v34->m_doneBuying = true;
      return;
    }
    if ( rnd >= 20.0 )
    {
      if ( rnd < 30.0 )
      {
        CCommand::Tokenize(this: &args, pCommand: "buy decoy", pBreakSet: nullptr);
        goto LABEL_143;
      }
      if ( rnd < 40.0 )
      {
        CCommand::Tokenize(this: &args, pCommand: "buy molotov", pBreakSet: nullptr);
        goto LABEL_143;
      }
    }
    else
    {
      TeamNumber = CBaseEntity::GetTeamNumber(this: me);
      if ( UTIL_IsTeamAllBots(team: TeamNumber) )
      {
        CCommand::Tokenize(this: &args, pCommand: "buy flashbang", pBreakSet: nullptr);
        goto LABEL_143;
      }
    }
    CCommand::Tokenize(this: &args, pCommand: "buy hegrenade", pBreakSet: nullptr);
    goto LABEL_143;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D2A00
// Name: __CreateCServerGameTagsIServerGameTags_interface_38
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_38()
{
  return &_g_CServerGameTags_singleton_38;
}
