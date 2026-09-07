// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/multiplay_gamerules.cpp
// Functions: 14
// ============================================================

#include "game\shared\multiplay_gamerules.h"

//------------------------------------------------------------------------------
// Address: 0x10126F20
// Name: public: virtual int C_MultiplayRules::Damage_GetTimeBased(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_MultiplayRules::Damage_GetTimeBased(C_MultiplayRules *this)
{
  return 4161536;
}

//------------------------------------------------------------------------------
// Address: 0x10126F30
// Name: public: virtual int C_MultiplayRules::Damage_GetShouldGibCorpse(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_MultiplayRules::Damage_GetShouldGibCorpse(C_MultiplayRules *this)
{
  return 737;
}

//------------------------------------------------------------------------------
// Address: 0x10126F40
// Name: public: virtual int C_MultiplayRules::Damage_GetShowOnHud(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_MultiplayRules::Damage_GetShowOnHud(C_MultiplayRules *this)
{
  return 3621128;
}

//------------------------------------------------------------------------------
// Address: 0x10126F50
// Name: public: virtual int C_MultiplayRules::Damage_GetNoPhysicsForce(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_MultiplayRules::Damage_GetNoPhysicsForce(C_MultiplayRules *this)
{
  return this->Damage_GetTimeBased(this) | 0x1804829;
}

//------------------------------------------------------------------------------
// Address: 0x10126F60
// Name: public: virtual int C_MultiplayRules::Damage_GetShouldNotBleed(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_MultiplayRules::Damage_GetShouldNotBleed(C_MultiplayRules *this)
{
  return 1179648;
}

//------------------------------------------------------------------------------
// Address: 0x10126F70
// Name: public: virtual bool C_MultiplayRules::Damage_IsTimeBased(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_MultiplayRules::Damage_IsTimeBased(C_MultiplayRules *this, int iDmgType)
{
  return (iDmgType & 0x3F8000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10126F90
// Name: public: virtual bool C_MultiplayRules::Damage_ShouldGibCorpse(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_MultiplayRules::Damage_ShouldGibCorpse(C_MultiplayRules *this, __int16 iDmgType)
{
  return (iDmgType & 0x2E1) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10126FB0
// Name: public: virtual bool C_MultiplayRules::Damage_ShowOnHUD(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_MultiplayRules::Damage_ShowOnHUD(C_MultiplayRules *this, int iDmgType)
{
  return (iDmgType & 0x374108) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10126FD0
// Name: public: virtual bool C_MultiplayRules::Damage_NoPhysicsForce(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_MultiplayRules::Damage_NoPhysicsForce(C_MultiplayRules *this, int iDmgType)
{
  return (iDmgType & (this->Damage_GetTimeBased(this) | 0x1804829)) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10126FF0
// Name: public: virtual bool C_MultiplayRules::Damage_ShouldNotBleed(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_MultiplayRules::Damage_ShouldNotBleed(C_MultiplayRules *this, int iDmgType)
{
  return (iDmgType & 0x120000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101270A0
// Name: public: char const __near * C_MultiplayRules::GetVoiceCommandSubtitle(int,int)
// Source: json
//------------------------------------------------------------------------------
VoiceCommandMenuItem_t *__thiscall C_MultiplayRules::GetVoiceCommandSubtitle(
        C_MultiplayRules *this,
        int iMenu,
        int iItem)
{
  CUtlVector<VoiceCommandMenuItem_t,CUtlMemory<VoiceCommandMenuItem_t,int> > *m_pMemory; // ecx
  bool v4; // cc
  CUtlVector<VoiceCommandMenuItem_t,CUtlMemory<VoiceCommandMenuItem_t,int> > *v5; // ecx

  if ( iMenu >= 0
    && iMenu < this->m_VoiceCommandMenus.m_Size
    && iItem >= 0
    && (m_pMemory = this->m_VoiceCommandMenus.m_Memory.m_pMemory,
        v4 = iItem < m_pMemory[iMenu].m_Size,
        v5 = &m_pMemory[iMenu],
        v4) )
  {
    return &v5->m_Memory.m_pMemory[iItem];
  }
  else
  {
    return (VoiceCommandMenuItem_t *)prType;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10127160
// Name: public: void C_MultiplayRules::LoadVoiceCommandScript(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_MultiplayRules::LoadVoiceCommandScript(C_MultiplayRules *this)
{
  KeyValues *v2; // eax
  IBaseFileSystem *v3; // eax
  KeyValues *v4; // edi
  CUtlVector<CUtlVector<VoiceCommandMenuItem_t,CUtlMemory<VoiceCommandMenuItem_t,int> >,CUtlMemory<CUtlVector<VoiceCommandMenuItem_t,CUtlMemory<VoiceCommandMenuItem_t,int> >,int> > *p_m_VoiceCommandMenus; // esi
  int v6; // edi
  KeyValues *FirstSubKey; // ebx
  char *String; // eax
  char *v9; // eax
  int v10; // eax
  int m_Size; // edi
  CUtlMemory<VoiceCommandMenuItem_t,int> *p_m_Memory; // esi
  int m_nAllocationCount; // eax
  VoiceCommandMenuItem_t *m_pMemory; // ecx
  int v15; // eax
  VoiceCommandMenuItem_t *v16; // edi
  KeyValues *NextKey; // eax
  VoiceCommandMenuItem_t item; // [esp+8h] [ebp-214h] BYREF
  int iMenuIndex; // [esp+208h] [ebp-14h]
  CUtlVector<CUtlVector<VoiceCommandMenuItem_t,CUtlMemory<VoiceCommandMenuItem_t,int> >,CUtlMemory<CUtlVector<VoiceCommandMenuItem_t,CUtlMemory<VoiceCommandMenuItem_t,int> >,int> > *v20; // [esp+20Ch] [ebp-10h]
  int iNumItems; // [esp+210h] [ebp-Ch]
  KeyValues *pKV; // [esp+214h] [ebp-8h]
  KeyValues *menu; // [esp+218h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    pKV = KeyValues::KeyValues(this: v2, setName: "VoiceCommands");
  else
    pKV = nullptr;
  if ( filesystem != nullptr )
    v3 = &filesystem->IBaseFileSystem;
  else
    v3 = nullptr;
  v4 = pKV;
  if ( KeyValues::LoadFromFile(
         this: pKV,
         filesystem: v3,
         resourceName: "scripts/voicecommands.txt",
         pathID: "GAME",
         pfnEvaluateSymbolProc: nullptr) )
  {
    menu = KeyValues::GetFirstSubKey(this: pKV);
    if ( menu != nullptr )
    {
      p_m_VoiceCommandMenus = &this->m_VoiceCommandMenus;
      v20 = p_m_VoiceCommandMenus;
      do
      {
        v6 = CUtlVector<CUtlVector<VoiceCommandMenuItem_t,CUtlMemory<VoiceCommandMenuItem_t,int>>,CUtlMemory<CUtlVector<VoiceCommandMenuItem_t,CUtlMemory<VoiceCommandMenuItem_t,int>>,int>>::InsertBefore(
               this: p_m_VoiceCommandMenus,
               elem: p_m_VoiceCommandMenus->m_Size);
        iMenuIndex = v6;
        iNumItems = 0;
        FirstSubKey = KeyValues::GetFirstSubKey(this: menu);
        if ( FirstSubKey != nullptr )
        {
          while ( 1 )
          {
            if ( ++iNumItems <= 9 )
            {
              String = (char *)KeyValues::GetString(this: FirstSubKey, keyName: "subtitle", defaultValue: prType);
              V_strncpy(pDest: item.m_szSubtitle, pSrc: String, maxLen: 256);
              v9 = (char *)KeyValues::GetString(this: FirstSubKey, keyName: "menu_label", defaultValue: prType);
              V_strncpy(pDest: item.m_szMenuLabel, pSrc: v9, maxLen: 256);
              v10 = v6;
              m_Size = p_m_VoiceCommandMenus->m_Memory.m_pMemory[v6].m_Size;
              p_m_Memory = &p_m_VoiceCommandMenus->m_Memory.m_pMemory[v10].m_Memory;
              m_nAllocationCount = p_m_Memory->m_nAllocationCount;
              if ( m_Size + 1 > m_nAllocationCount )
                CUtlMemory<VoiceCommandMenuItem_t,int>::Grow(this: p_m_Memory, num: m_Size - m_nAllocationCount + 1);
              ++p_m_Memory[1].m_pMemory;
              m_pMemory = p_m_Memory->m_pMemory;
              v15 = (int)&p_m_Memory[1].m_pMemory->m_szSubtitle[-m_Size - 1];
              p_m_Memory[1].m_nAllocationCount = (int)p_m_Memory->m_pMemory->m_szSubtitle;
              if ( v15 > 0 )
                _V_memmove(
                  dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
                  src: (unsigned __int8 *)&m_pMemory[m_Size],
                  count: v15 << 9);
              v16 = &p_m_Memory->m_pMemory[m_Size];
              if ( v16 != nullptr )
                *v16 = item;
            }
            else
            {
              _Warning(a1: "Trying to load more than 9 menu items in voicecommands.txt, extras ignored");
            }
            NextKey = KeyValues::GetNextKey(this: FirstSubKey);
            p_m_VoiceCommandMenus = v20;
            FirstSubKey = NextKey;
            if ( NextKey == nullptr )
              break;
            v6 = iMenuIndex;
          }
        }
        menu = KeyValues::GetNextKey(this: menu);
      }
      while ( menu != nullptr );
      v4 = pKV;
    }
  }
  KeyValues::deleteThis(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10127320
// Name: public: C_MultiplayRules::C_MultiplayRules(void)
// Source: json
//------------------------------------------------------------------------------
C_MultiplayRules *__thiscall C_MultiplayRules::C_MultiplayRules(C_MultiplayRules *this)
{
  C_GameRules::C_GameRules(this);
  this->__vftable = (C_MultiplayRules_vtbl *)&C_MultiplayRules::`vftable';
  this->m_VoiceCommandMenus.m_Memory.m_pMemory = nullptr;
  this->m_VoiceCommandMenus.m_Memory.m_nAllocationCount = 0;
  this->m_VoiceCommandMenus.m_Memory.m_nGrowSize = 0;
  this->m_VoiceCommandMenus.m_Size = 0;
  this->m_VoiceCommandMenus.m_pElements = nullptr;
  C_MultiplayRules::LoadVoiceCommandScript(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10127390
// Name: void __CreateGameRules_CMultiplayRules(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __CreateGameRules_CMultiplayRules()
{
  C_MultiplayRules *v0; // esi

  v0 = (C_MultiplayRules *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 32);
  _V_memset(dest: v0, fill: 0, count: 32);
  if ( v0 != nullptr )
  {
    C_GameRules::C_GameRules(this: v0);
    v0->__vftable = (C_MultiplayRules_vtbl *)&C_MultiplayRules::`vftable';
    v0->m_VoiceCommandMenus.m_Memory.m_pMemory = nullptr;
    v0->m_VoiceCommandMenus.m_Memory.m_nAllocationCount = 0;
    v0->m_VoiceCommandMenus.m_Memory.m_nGrowSize = 0;
    v0->m_VoiceCommandMenus.m_Size = 0;
    v0->m_VoiceCommandMenus.m_pElements = nullptr;
    C_MultiplayRules::LoadVoiceCommandScript(this: v0);
  }
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10175AC0
// Name: public: virtual int CMultiplayRules::Damage_GetTimeBased(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMultiplayRules::Damage_GetTimeBased(CMultiplayRules *this)
{
  return 4161536;
}

//------------------------------------------------------------------------------
// Address: 0x10175AD0
// Name: public: virtual int CMultiplayRules::Damage_GetShouldGibCorpse(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMultiplayRules::Damage_GetShouldGibCorpse(CMultiplayRules *this)
{
  return 737;
}

//------------------------------------------------------------------------------
// Address: 0x10175AE0
// Name: public: virtual int CMultiplayRules::Damage_GetShowOnHud(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMultiplayRules::Damage_GetShowOnHud(CMultiplayRules *this)
{
  return 3621128;
}

//------------------------------------------------------------------------------
// Address: 0x10175AF0
// Name: public: virtual int CMultiplayRules::Damage_GetNoPhysicsForce(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMultiplayRules::Damage_GetNoPhysicsForce(CMultiplayRules *this)
{
  return this->Damage_GetTimeBased(this) | 0x1804829;
}

//------------------------------------------------------------------------------
// Address: 0x10175B00
// Name: public: virtual int CMultiplayRules::Damage_GetShouldNotBleed(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMultiplayRules::Damage_GetShouldNotBleed(CMultiplayRules *this)
{
  return 1179648;
}

//------------------------------------------------------------------------------
// Address: 0x10175B10
// Name: public: virtual bool CMultiplayRules::Damage_IsTimeBased(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMultiplayRules::Damage_IsTimeBased(CMultiplayRules *this, int iDmgType)
{
  return (iDmgType & 0x3F8000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10175B30
// Name: public: virtual bool CMultiplayRules::Damage_ShouldGibCorpse(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMultiplayRules::Damage_ShouldGibCorpse(CMultiplayRules *this, __int16 iDmgType)
{
  return (iDmgType & 0x2E1) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10175B50
// Name: public: virtual bool CMultiplayRules::Damage_ShowOnHUD(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMultiplayRules::Damage_ShowOnHUD(CMultiplayRules *this, int iDmgType)
{
  return (iDmgType & 0x374108) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10175B70
// Name: public: virtual bool CMultiplayRules::Damage_NoPhysicsForce(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMultiplayRules::Damage_NoPhysicsForce(CMultiplayRules *this, int iDmgType)
{
  return (iDmgType & (this->Damage_GetTimeBased(this) | 0x1804829)) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10175B90
// Name: public: virtual bool CMultiplayRules::Damage_ShouldNotBleed(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMultiplayRules::Damage_ShouldNotBleed(CMultiplayRules *this, int iDmgType)
{
  return (iDmgType & 0x120000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10175BB0
// Name: public: virtual void CMultiplayRules::RefreshSkillData(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMultiplayRules::RefreshSkillData(CMultiplayRules *this, bool forceUpdate)
{
  CGameRules::RefreshSkillData(this, forceUpdate);
}

//------------------------------------------------------------------------------
// Address: 0x10175BC0
// Name: public: virtual bool CMultiplayRules::FShouldSwitchWeapon(class CBasePlayer __near *,class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMultiplayRules::FShouldSwitchWeapon(
        CMultiplayRules *this,
        CBasePlayer *pPlayer,
        CBaseCombatWeapon *pWeapon)
{
  CBaseCombatWeapon *ActiveWeapon; // eax
  CBaseCombatWeapon *v5; // eax
  int v6; // esi

  if ( !pPlayer->Weapon_CanSwitchTo(this: pPlayer, a2: pWeapon) )
    return false;
  if ( CBaseCombatCharacter::GetActiveWeapon(this: pPlayer) == nullptr )
    return true;
  if ( !pWeapon->AllowsAutoSwitchTo(this: pWeapon) )
    return false;
  ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: pPlayer);
  if ( !ActiveWeapon->AllowsAutoSwitchFrom(this: ActiveWeapon) )
    return false;
  v5 = CBaseCombatCharacter::GetActiveWeapon(this: pPlayer);
  v6 = v5->GetWeight(this: v5);
  return pWeapon->GetWeight(this: pWeapon) > v6;
}

//------------------------------------------------------------------------------
// Address: 0x10175C50
// Name: public: virtual bool CMultiplayRules::SwitchToNextBestWeapon(class CBaseCombatCharacter __near *,class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMultiplayRules::SwitchToNextBestWeapon(
        CMultiplayRules *this,
        CBaseCombatCharacter *pPlayer,
        CBaseCombatWeapon *pCurrentWeapon)
{
  CBaseCombatWeapon *v3; // eax

  v3 = this->GetNextBestWeapon(this, a2: pPlayer, a3: pCurrentWeapon);
  return v3 != nullptr && pPlayer->Weapon_Switch(this: pPlayer, a2: v3, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10175C90
// Name: public: virtual bool CMultiplayRules::ClientConnected(struct edict_t __near *,char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMultiplayRules::ClientConnected(
        CMultiplayRules *this,
        edict_t *pEntity,
        const char *pszName,
        const char *pszAddress,
        char *reject,
        int maxrejectlen)
{
  CVoiceGameMgr *VoiceGameMgr; // eax

  VoiceGameMgr = GetVoiceGameMgr();
  CVoiceGameMgr::ClientConnected(this: VoiceGameMgr, pEdict: pEntity);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10175CB0
// Name: public: virtual void CMultiplayRules::PlayerThink(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMultiplayRules::PlayerThink(CMultiplayRules *this, CBasePlayer *pPlayer)
{
  if ( g_fGameOver )
  {
    pPlayer->m_afButtonPressed = 0;
    pPlayer->m_nButtons = 0;
    pPlayer->m_afButtonReleased = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10175CE0
// Name: public: virtual void CMultiplayRules::PlayerSpawn(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMultiplayRules::PlayerSpawn(CMultiplayRules *this, CBasePlayer *pPlayer)
{
  CBaseEntity *i; // esi

  pPlayer->EquipSuit(this: pPlayer, a2: true);
  for ( i = CGlobalEntityList::FindEntityByClassname(
              this: &gEntList,
              pStartEntity: nullptr,
              szName: "game_player_equip");
        i != nullptr;
        i = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: i, szName: "game_player_equip") )
  {
    i->Touch(this: i, a2: pPlayer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10175D40
// Name: public: virtual float CMultiplayRules::FlPlayerSpawnTime(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CMultiplayRules::FlPlayerSpawnTime(CMultiplayRules *this, CBasePlayer *pPlayer)
{
  return gpGlobals->curtime;
}

//------------------------------------------------------------------------------
// Address: 0x10175D50
// Name: public: virtual int CMultiplayRules::IPointsForKill(class CBasePlayer __near *,class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMultiplayRules::IPointsForKill(CMultiplayRules *this, CBasePlayer *pAttacker, CBasePlayer *pKilled)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10175D60
// Name: public: class CBasePlayer __near * CMultiplayRules::GetDeathScorer(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__thiscall CMultiplayRules::GetDeathScorer(
        CMultiplayRules *this,
        CBaseEntity *pKiller,
        CBaseEntity *pInflictor)
{
  CBasePlayer *result; // eax
  int (__thiscall ***v4)(_DWORD); // eax
  int (__thiscall ***v5)(_DWORD); // eax

  if ( pKiller == nullptr )
    return nullptr;
  if ( pKiller->Classify(this: pKiller) == CLASS_PLAYER )
    return (CBasePlayer *)pKiller;
  v4 = (int (__thiscall ***)(_DWORD))__RTDynamicCast(
                                       inptr: pKiller,
                                       VfDelta: 0,
                                       SrcType: &CBaseEntity `RTTI Type Descriptor',
                                       TargetType: &IScorer `RTTI Type Descriptor',
                                       isReference: 0);
  if ( v4 == nullptr || (result = (CBasePlayer *)(**v4)(a1: v4)) == nullptr )
  {
    v5 = (int (__thiscall ***)(_DWORD))__RTDynamicCast(
                                         inptr: pInflictor,
                                         VfDelta: 0,
                                         SrcType: &CBaseEntity `RTTI Type Descriptor',
                                         TargetType: &IScorer `RTTI Type Descriptor',
                                         isReference: 0);
    if ( v5 == nullptr )
      return nullptr;
    result = (CBasePlayer *)(**v5)(a1: v5);
    if ( result == nullptr )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10175DE0
// Name: public: virtual class CBasePlayer __near * CMultiplayRules::GetDeathScorer(class CBaseEntity __near *,class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__thiscall CMultiplayRules::GetDeathScorer(
        CMultiplayRules *this,
        CBaseEntity *pKiller,
        CBaseEntity *pInflictor,
        CBaseEntity *pVictim)
{
  return CMultiplayRules::GetDeathScorer(this, pKiller, pInflictor);
}

//------------------------------------------------------------------------------
// Address: 0x10175E00
// Name: public: virtual float CMultiplayRules::FlWeaponTryRespawn(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CMultiplayRules::FlWeaponTryRespawn(CMultiplayRules *this, CBaseCombatWeapon *pWeapon)
{
  if ( pWeapon != nullptr
    && (pWeapon->GetWeaponFlags(this: pWeapon) & 8) != 0
    && CGlobalEntityList::NumberOfEntities(this: &gEntList) >= gpGlobals->maxEntities - 100 )
  {
    return this->FlWeaponRespawnTime(this, a2: pWeapon);
  }
  else
  {
    return 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10175E60
// Name: public: virtual float CMultiplayRules::FlItemRespawnTime(class CItem __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CMultiplayRules::FlItemRespawnTime(CMultiplayRules *this, CItem *pItem)
{
  return gpGlobals->curtime + 30.0;
}

//------------------------------------------------------------------------------
// Address: 0x10175E80
// Name: public: virtual float CMultiplayRules::FlHealthChargerRechargeTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CMultiplayRules::FlHealthChargerRechargeTime(CMultiplayRules *this)
{
  return 60.0;
}

//------------------------------------------------------------------------------
// Address: 0x10175E90
// Name: public: virtual float CMultiplayRules::FlHEVChargerRechargeTime(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CMultiplayRules::FlHEVChargerRechargeTime(CMultiplayRules *this)
{
  return 30.0;
}

//------------------------------------------------------------------------------
// Address: 0x10175EB0
// Name: public: virtual int CMultiplayRules::DeadPlayerAmmo(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMultiplayRules::DeadPlayerAmmo(CMultiplayRules *this, CBasePlayer *pPlayer)
{
  return 11;
}

//------------------------------------------------------------------------------
// Address: 0x10175EC0
// Name: public: virtual class CBaseEntity __near * CMultiplayRules::GetPlayerSpawnSpot(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CMultiplayRules::GetPlayerSpawnSpot(CMultiplayRules *this, CBasePlayer *pPlayer)
{
  return CGameRules::GetPlayerSpawnSpot(this, pPlayer);
}

//------------------------------------------------------------------------------
// Address: 0x10175ED0
// Name: public: virtual bool CMultiplayRules::PlayerCanHearChat(class CBasePlayer __near *,class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CMultiplayRules::PlayerCanHearChat(
        CMultiplayRules *this,
        CBasePlayer *pListener,
        CBasePlayer *pSpeaker)
{
  return this->PlayerRelationship(this, a2: pListener, a3: pSpeaker) == 1;
}

//------------------------------------------------------------------------------
// Address: 0x10175F00
// Name: void MPTimeLimitCallback(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl MPTimeLimitCallback()
{
  unsigned int v0; // [esp-8h] [ebp-8h]
  CGameTrace *v1; // [esp-4h] [ebp-4h]

  if ( mp_timelimit.m_pParent != nullptr && mp_timelimit.m_pParent->m_Value.m_nValue < 0 )
    CCollisionProperty::TestCollision(this: (ConVar *)&mp_timelimit.IConVar, value: 0, fContentsMask: v0, tr: v1);
  if ( g_pGameRules != nullptr )
    g_pGameRules->__vftable[1].PostInit(this: g_pGameRules);
}

//------------------------------------------------------------------------------
// Address: 0x10175F30
// Name: public: virtual void CMultiplayRules::Think(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMultiplayRules::Think(CMultiplayRules *this)
{
  float v2; // xmm0_4
  int v3; // esi
  CBasePlayer *v4; // eax
  float flFragLimit; // [esp+4h] [ebp-4h]

  CGameRules::Think(this);
  if ( g_fGameOver )
  {
    this->ChangeLevel(this);
    return;
  }
  v2 = mp_timelimit.m_pParent->m_Value.m_fValue * 60.0;
  flFragLimit = fraglimit.m_pParent->m_Value.m_fValue;
  if ( v2 != 0.0 && gpGlobals->curtime >= v2 )
    goto LABEL_11;
  if ( fraglimit.m_pParent->m_Value.m_fValue != 0.0 )
  {
    v3 = 1;
    if ( gpGlobals->maxClients >= 1 )
    {
      while ( 1 )
      {
        v4 = UTIL_PlayerByIndex(playerIndex: v3);
        if ( v4 != nullptr && (float)v4->m_iFrags >= flFragLimit )
          break;
        if ( ++v3 > gpGlobals->maxClients )
          return;
      }
LABEL_11:
      this->GoToIntermission(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10176010
// Name: public: virtual class CBaseCombatWeapon __near * CMultiplayRules::GetNextBestWeapon(class CBaseCombatCharacter __near *,class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseCombatWeapon *__thiscall CMultiplayRules::GetNextBestWeapon(
        CMultiplayRules *this,
        CBaseCombatCharacter *pPlayer,
        CBaseCombatWeapon *pCurrentWeapon)
{
  int v3; // ebx
  CBaseCombatWeapon *Weapon; // esi
  CBaseCombatWeapon *pBest; // [esp+8h] [ebp-Ch]
  int iBestWeight; // [esp+Ch] [ebp-8h]
  int iCurrentWeight; // [esp+10h] [ebp-4h]

  v3 = 0;
  iCurrentWeight = -1;
  iBestWeight = -1;
  pBest = nullptr;
  if ( pCurrentWeapon != nullptr )
  {
    if ( pCurrentWeapon->AllowsAutoSwitchFrom(this: pCurrentWeapon) && pCurrentWeapon->CanHolster(this: pCurrentWeapon) )
    {
      iCurrentWeight = pCurrentWeapon->GetWeight(this: pCurrentWeapon);
      goto LABEL_5;
    }
    return nullptr;
  }
  else
  {
    do
    {
LABEL_5:
      Weapon = CBaseCombatCharacter::GetWeapon(this: pPlayer, i: v3);
      if ( Weapon != nullptr && (pCurrentWeapon == nullptr || Weapon->AllowsAutoSwitchTo(this: Weapon)) )
      {
        if ( Weapon->GetWeight(this: Weapon) <= -1
          || Weapon->GetWeight(this: Weapon) != iCurrentWeight
          || Weapon == pCurrentWeapon )
        {
          if ( Weapon->GetWeight(this: Weapon) > iBestWeight
            && Weapon != pCurrentWeapon
            && Weapon->HasAnyAmmo(this: Weapon) )
          {
            iBestWeight = Weapon->GetWeight(this: Weapon);
            pBest = Weapon;
          }
        }
        else if ( Weapon->HasAnyAmmo(this: Weapon) && pPlayer->Weapon_CanSwitchTo(this: pPlayer, a2: Weapon) )
        {
          return Weapon;
        }
      }
      ++v3;
    }
    while ( v3 < 64 );
    return pBest;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10176140
// Name: public: virtual void CMultiplayRules::ClientDisconnected(struct edict_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMultiplayRules::ClientDisconnected(CMultiplayRules *this, edict_t *pClient)
{
  IServerUnknown *m_pUnk; // ecx
  CBaseEntity *v3; // eax
  CBaseEntity *v4; // esi

  if ( pClient != nullptr )
  {
    m_pUnk = pClient->m_pUnk;
    if ( m_pUnk != nullptr )
    {
      v3 = m_pUnk->GetBaseEntity(this: m_pUnk);
      v4 = v3;
      if ( v3 != nullptr )
      {
        FireTargets(targetName: "game_playerleave", pActivator: v3, pCaller: v3, useType: USE_TOGGLE, value: 0.0);
        v4->__vftable[1].NetworkStateChanged_m_hGroundEntity(this: v4, a2: (void *)1);
        CBasePlayer::DestroyViewModels(this: (CBasePlayer *)v4);
        LODWORD(v4[4].m_Collision.m_vecMaxs.m_Value.x) = 2;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101761A0
// Name: public: virtual bool CMultiplayRules::AllowAutoTargetCrosshair(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMultiplayRules::AllowAutoTargetCrosshair(CMultiplayRules *this)
{
  return aimcrosshair.m_pParent != nullptr && aimcrosshair.m_pParent->m_Value.m_nValue != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101761C0
// Name: public: virtual float CMultiplayRules::FlWeaponRespawnTime(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CMultiplayRules::FlWeaponRespawnTime(CMultiplayRules *this, CBaseCombatWeapon *pWeapon)
{
  if ( weaponstay.m_pParent == nullptr
    || weaponstay.m_pParent->m_Value.m_nValue <= 0
    || (pWeapon->GetWeaponFlags(this: pWeapon) & 8) != 0 )
  {
    return gpGlobals->curtime + 20.0;
  }
  else
  {
    return gpGlobals->curtime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10176210
// Name: public: virtual bool CMultiplayRules::CanHavePlayerItem(class CBasePlayer __near *,class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMultiplayRules::CanHavePlayerItem(
        CMultiplayRules *this,
        CBasePlayer *pPlayer,
        CBaseCombatWeapon *pItem)
{
  CAI_BaseNPC *v3; // esi
  int v5; // esi

  v3 = (CAI_BaseNPC *)this;
  if ( weaponstay.m_pParent == nullptr
    || weaponstay.m_pParent->m_Value.m_nValue <= 0
    || (pItem->GetWeaponFlags(this: pItem) & 8) != 0 )
  {
    return CGameRules::FPlayerCanTakeDamage(this: v3, vecSightDir: (const Vector *)pPlayer, sightDist: *(float *)&pItem);
  }
  v5 = 0;
  while ( CBaseCombatCharacter::GetWeapon(this: pPlayer, i: v5) != pItem )
  {
    if ( ++v5 >= 64 )
    {
      v3 = (CAI_BaseNPC *)this;
      return CGameRules::FPlayerCanTakeDamage(
               this: v3,
               vecSightDir: (const Vector *)pPlayer,
               sightDist: *(float *)&pItem);
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10176290
// Name: public: virtual class Vector CMultiplayRules::VecItemRespawnSpot(class CItem __near *)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CMultiplayRules::VecItemRespawnSpot(CMultiplayRules *this, Vector *result, CItem *pItem)
{
  float z; // ecx
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  if ( (pItem->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pItem, a2: (int)&savedregs);
  z = pItem->m_vecAbsOrigin.z;
  *(_QWORD *)&result->x = *(_QWORD *)&pItem->m_vecAbsOrigin.x;
  result->z = z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101762D0
// Name: public: virtual class QAngle CMultiplayRules::VecItemRespawnAngles(class CItem __near *)
// Source: json
//------------------------------------------------------------------------------
QAngle *__thiscall CMultiplayRules::VecItemRespawnAngles(CMultiplayRules *this, QAngle *result, CItem *pItem)
{
  float z; // ecx
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  if ( (pItem->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pItem, a2: (int)&savedregs);
  z = pItem->m_angAbsRotation.z;
  *(_QWORD *)&result->x = *(_QWORD *)&pItem->m_angAbsRotation.x;
  result->z = z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10176310
// Name: public: virtual bool CMultiplayRules::PlayFootstepSounds(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CMultiplayRules::PlayFootstepSounds@<al>(CMultiplayRules *this@<ecx>, int a2@<ebp>, CBasePlayer *pl)
{
  _DWORD v4[3]; // [esp+0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v4[0] = a2;
  v4[1] = retaddr;
  if ( footsteps.m_pParent == nullptr || footsteps.m_pParent->m_Value.m_nValue == 0 )
    return false;
  if ( CBasePlayer::IsOnLadder(this: pl) )
    return true;
  if ( (pl->m_iEFlags & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this: pl, a2: (int)v4);
  return fsqrt(
           (float)(pl->m_vecAbsVelocity.x * pl->m_vecAbsVelocity.x)
         + (float)(pl->m_vecAbsVelocity.y * pl->m_vecAbsVelocity.y)) > 220.0;
}

//------------------------------------------------------------------------------
// Address: 0x101763B0
// Name: public: virtual bool CMultiplayRules::FAllowFlashlight(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMultiplayRules::FAllowFlashlight(CMultiplayRules *this)
{
  return flashlight.m_pParent != nullptr && flashlight.m_pParent->m_Value.m_nValue != 0;
}

//------------------------------------------------------------------------------
// Address: 0x101763D0
// Name: public: virtual void CMultiplayRules::GetTaggedConVarList(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMultiplayRules::GetTaggedConVarList(CMultiplayRules *this, KeyValues *pCvarTagList)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "sv_gravity");
  else
    v3 = nullptr;
  KeyValues::SetString(this: v3, keyName: "convar", value: "sv_gravity");
  KeyValues::SetString(this: v3, keyName: "tag", value: "gravity");
  KeyValues::AddSubKey(this: pCvarTagList, pSubkey: v3);
}

//------------------------------------------------------------------------------
// Address: 0x101764D0
// Name: public: virtual void CMultiplayRules::PlayerKilled(class CBasePlayer __near *,class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMultiplayRules::PlayerKilled(CMultiplayRules *this, CBasePlayer *pVictim, const CTakeDamageInfo *info)
{
  unsigned int m_Index; // eax
  unsigned int v6; // eax
  CBaseEntity *m_pEntity; // eax
  CBasePlayer *v8; // esi
  CMultiplayRules_vtbl *v9; // edx
  int v10; // eax
  CBaseEntity *infoa; // [esp+40h] [ebp+Ch]
  const CTakeDamageInfo *infob; // [esp+40h] [ebp+Ch]

  this->DeathNotice(this, a2: pVictim, a3: info);
  m_Index = info->m_hInflictor.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    infoa = nullptr;
  else
    infoa = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v6 = info->m_hAttacker.m_Index;
  if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
  v8 = this->GetDeathScorer(this, a2: m_pEntity, a3: infoa, a4: pVictim);
  pVictim->IncrementDeathCount(this: pVictim, a2: 1);
  FireTargets(targetName: "game_playerdie", pActivator: pVictim, pCaller: pVictim, useType: USE_TOGGLE, value: 0.0);
  if ( pVictim == v8 )
  {
    if ( !this->UseSuicidePenalty(this) )
      return;
LABEL_15:
    pVictim->IncrementFragCount(this: pVictim, a2: -1);
    return;
  }
  v9 = this->__vftable;
  if ( v8 != nullptr )
  {
    infob = (const CTakeDamageInfo *)v8->__vftable;
    v10 = ((int (__stdcall *)(CBasePlayer *, CBasePlayer *))v9->IPointsForKill)(a1: v8, a2: pVictim);
    ((void (__thiscall *)(CBasePlayer *, int))infob[20].m_hInflictor.m_Index)(a1: v8, a2: v10);
    CBasePlayer::AllowImmediateDecalPainting(this: v8);
    FireTargets(targetName: "game_playerkill", pActivator: v8, pCaller: v8, useType: USE_TOGGLE, value: 0.0);
    return;
  }
  if ( ((unsigned __int8 (__fastcall *)(CMultiplayRules *))v9->UseSuicidePenalty)(a1: this) != 0 )
    goto LABEL_15;
}

//------------------------------------------------------------------------------
// Address: 0x10176620
// Name: public: virtual void CMultiplayRules::DeathNotice(class CBasePlayer __near *,class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMultiplayRules::DeathNotice(CMultiplayRules *this, CBasePlayer *pVictim, const CTakeDamageInfo *info)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ebx
  unsigned int v6; // eax
  CBaseEntity *v7; // eax
  CBasePlayer *v8; // esi
  CBaseCombatWeapon *ActiveWeapon; // eax
  IGameEvent *v10; // esi
  int v11; // eax
  int killer_ID; // [esp+Ch] [ebp-8h]
  const char *killer_weapon_name; // [esp+10h] [ebp-4h]

  m_Index = info->m_hInflictor.m_Index;
  m_pEntity = nullptr;
  killer_weapon_name = "world";
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
  v8 = this->GetDeathScorer(this, a2: v7, a3: m_pEntity, a4: pVictim);
  if ( info->m_iDamageCustom != 0 )
  {
    this->GetDamageCustomString(this, a2: info);
    if ( v8 != nullptr )
      killer_ID = engine->GetPlayerUserId(this: engine, a2: v8->m_Network.m_pPev);
    goto LABEL_22;
  }
  if ( v8 == nullptr )
    goto LABEL_17;
  killer_ID = engine->GetPlayerUserId(this: engine, a2: v8->m_Network.m_pPev);
  if ( m_pEntity != nullptr )
  {
    if ( m_pEntity == v8 )
    {
      if ( CBaseCombatCharacter::GetActiveWeapon(this: v8) != nullptr )
      {
        ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: v8);
        killer_weapon_name = ActiveWeapon->GetDeathNoticeName(this: ActiveWeapon);
      }
      goto LABEL_19;
    }
LABEL_17:
    killer_weapon_name = m_pEntity->m_iClassname.pszValue;
    if ( killer_weapon_name == nullptr )
      killer_weapon_name = locale;
  }
LABEL_19:
  if ( strncmp(first: killer_weapon_name, last: "weapon_", count: 7u) != 0
    && strncmp(first: killer_weapon_name, last: "NPC_", count: 8u) != 0 )
  {
    strncmp(first: killer_weapon_name, last: "func_", count: 5u);
  }
LABEL_22:
  v10 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_death", a3: 0, a4: 0);
  if ( v10 != nullptr )
  {
    v11 = engine->GetPlayerUserId(this: engine, a2: pVictim->m_Network.m_pPev);
    v10->SetInt(this: v10, a2: "userid", a3: v11);
    v10->SetInt(this: v10, a2: "attacker", a3: killer_ID);
    v10->SetInt(this: v10, a2: "customkill", a3: info->m_iDamageCustom);
    v10->SetInt(this: v10, a2: "priority", a3: 7);
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v10, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10176800
// Name: public: virtual int CMultiplayRules::WeaponShouldRespawn(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMultiplayRules::WeaponShouldRespawn(CMultiplayRules *this, CBaseCombatWeapon *pWeapon)
{
  return ((pWeapon->m_spawnflags.m_Value & 0x40000000) != 0) + 1;
}

//------------------------------------------------------------------------------
// Address: 0x10176820
// Name: public: virtual int CMultiplayRules::ItemShouldRespawn(class CItem __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMultiplayRules::ItemShouldRespawn(CMultiplayRules *this, CItem *pItem)
{
  return ((pItem->m_spawnflags.m_Value & 0x40000000) != 0) + 5;
}

//------------------------------------------------------------------------------
// Address: 0x10176850
// Name: protected: virtual void CMultiplayRules::GoToIntermission(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMultiplayRules::GoToIntermission(CMultiplayRules *this)
{
  int m_nValue; // eax
  CHLTVDirector *v3; // eax
  CHLTVDirector *v4; // eax
  CHLTVDirector *v5; // eax
  IGameEvent *v6; // eax
  int i; // esi
  CBasePlayer *v8; // eax
  float flWaitTime; // [esp+4h] [ebp-4h]

  if ( !g_fGameOver )
  {
    g_fGameOver = true;
    if ( mp_chattime.m_pParent != nullptr )
      m_nValue = mp_chattime.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    flWaitTime = (float)m_nValue;
    if ( tv_delaymapchange.m_pParent != nullptr && tv_delaymapchange.m_pParent->m_Value.m_nValue != 0 )
    {
      v3 = HLTVDirector();
      if ( v3->IsActive(this: &v3->IHLTVDirector) )
      {
        v4 = HLTVDirector();
        if ( flWaitTime <= ((double (__thiscall *)(IHLTVDirector *))v4->GetDelay)(a1: &v4->IHLTVDirector) )
        {
          v5 = HLTVDirector();
          flWaitTime = v5->GetDelay(this: &v5->IHLTVDirector);
        }
      }
    }
    this->m_flIntermissionEndTime = gpGlobals->curtime + flWaitTime;
    v6 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "cs_intermission", a3: 0, a4: 0);
    if ( v6 != nullptr )
      gameeventmanager->FireEvent(this: gameeventmanager, a2: v6, a3: false);
    for ( i = 1; i <= 64; ++i )
    {
      v8 = UTIL_PlayerByIndex(playerIndex: i);
      if ( v8 != nullptr )
        v8->ShowViewPortPanel(this: v8, a2: "scores", a3: true, a4: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10176950
// Name: protected: virtual void CMultiplayRules::ChangeLevel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMultiplayRules::ChangeLevel(CMultiplayRules *this)
{
  char *m_pszString; // ecx
  char *v3; // eax
  char *v4; // eax
  char szNextMap[36]; // [esp+4h] [ebp-24h] BYREF

  if ( (nextlevel.m_nFlags & 0x1000) != 0 )
    goto LABEL_5;
  m_pszString = nextlevel.m_pParent->m_Value.m_pszString;
  if ( m_pszString == nullptr || *m_pszString == 0 )
    goto LABEL_14;
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
  {
    if ( (nextlevel.m_nFlags & 0x1000) != 0 )
    {
      V_strncpy(pDest: szNextMap, pSrc: "FCVAR_NEVER_AS_STRING", maxLen: 32);
    }
    else
    {
      v4 = nextlevel.m_pParent->m_Value.m_pszString;
      if ( v4 == nullptr )
        v4 = (char *)locale;
      V_strncpy(pDest: szNextMap, pSrc: v4, maxLen: 32);
    }
    goto LABEL_16;
  }
LABEL_14:
  this->GetNextLevelName(this, a2: szNextMap, a3: 32, a4: false);
  if ( ++CMultiplayRules::m_nMapCycleindex >= CMultiplayRules::m_MapList.m_Size )
    CMultiplayRules::m_nMapCycleindex = 0;
LABEL_16:
  g_fGameOver = true;
  _Msg(a1: "CHANGE LEVEL: %s\n", szNextMap);
  engine->ChangeLevel(this: engine, a2: szNextMap, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10176A50
// Name: public: void CMultiplayRules::SkipNextMapInCycle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMultiplayRules::SkipNextMapInCycle(CMultiplayRules *this)
{
  char *m_pszString; // ecx
  char *v3; // eax
  char *v4; // eax
  char szSkippedMap[32]; // [esp+4h] [ebp-44h] BYREF
  char szNextMap[36]; // [esp+24h] [ebp-24h] BYREF

  this->GetNextLevelName(this, a2: szSkippedMap, a3: 32, a4: false);
  if ( ++CMultiplayRules::m_nMapCycleindex >= CMultiplayRules::m_MapList.m_Size )
    CMultiplayRules::m_nMapCycleindex = 0;
  this->GetNextLevelName(this, a2: szNextMap, a3: 32, a4: false);
  _Msg(a1: "Skipping: %s\tNext map: %s\n", szSkippedMap, szNextMap);
  if ( (nextlevel.m_nFlags & 0x1000) != 0 )
    goto LABEL_7;
  m_pszString = nextlevel.m_pParent->m_Value.m_pszString;
  if ( m_pszString == nullptr || *m_pszString == 0 )
    return;
  if ( (nextlevel.m_nFlags & 0x1000) != 0 )
  {
LABEL_7:
    v3 = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    v3 = nextlevel.m_pParent->m_Value.m_pszString;
    if ( v3 == nullptr )
      v3 = (char *)locale;
  }
  if ( engine->IsMapValid(this: engine, a2: v3) != 0 )
  {
    if ( (nextlevel.m_nFlags & 0x1000) != 0 )
    {
      _Msg(
        a1: "Warning! \"nextlevel\" is set to \"%s\" and will override the next map to be played.\n",
        "FCVAR_NEVER_AS_STRING");
    }
    else
    {
      v4 = nextlevel.m_pParent->m_Value.m_pszString;
      if ( v4 == nullptr )
        v4 = (char *)locale;
      _Msg(a1: "Warning! \"nextlevel\" is set to \"%s\" and will override the next map to be played.\n", v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10176B50
// Name: public: virtual bool CMultiplayRules::ClientCommand(class CBaseEntity __near *,class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMultiplayRules::ClientCommand(CMultiplayRules *this, CBasePlayer *pEdict, const CCommand *args)
{
  const char *v4; // esi
  CBaseMultiplayerPlayer *v5; // esi
  const char *v6; // eax
  int v7; // edi
  const char *v8; // ebx
  int v9; // eax
  int AchievementEventMask; // esi
  const char *v12; // eax
  int v13; // eax
  const FireBulletsInfo_t *v14; // edi
  const char *v15; // ebx
  IGameEvent *v16; // eax
  IGameEvent *v17; // esi
  IGameEvent_vtbl *v18; // ebx
  edict_t *v19; // eax
  CBasePlayer *pPlayer; // [esp+10h] [ebp-4h]
  int iPlayerID; // [esp+20h] [ebp+Ch]

  if ( pEdict == nullptr || (pPlayer = pEdict, !pEdict->IsPlayer(this: pEdict)) )
    pPlayer = nullptr;
  v4 = locale;
  if ( args->m_nArgc > 0 )
    v4 = args->m_ppArgv[0];
  if ( v4 != "voicemenu" && _V_stricmp(s1: v4, s2: "voicemenu") != 0 )
  {
    if ( v4 != "achievement_earned" && _V_stricmp(s1: v4, s2: "achievement_earned") != 0 )
    {
      return CGameRules::ClientCommand(this, pEdict, args);
    }
    else
    {
      if ( pEdict != nullptr && pEdict->ShouldAnnounceAchievement(this: pEdict) )
      {
        AchievementEventMask = UTIL_GetAchievementEventMask();
        iPlayerID = engine->GetPlayerUserId(this: engine, a2: pEdict->m_Network.m_pPev);
        v12 = locale;
        if ( args->m_nArgc > 1 )
          v12 = args->m_ppArgv[1];
        v13 = atoi(nptr: v12);
        v14 = (const FireBulletsInfo_t *)(AchievementEventMask ^ v13);
        if ( args->m_nArgc > 2 )
          v15 = args->m_ppArgv[2];
        else
          v15 = locale;
        if ( (iPlayerID ^ v13) == atoi(nptr: v15) )
        {
          v16 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "achievement_earned", a3: 0, a4: 0);
          v17 = v16;
          if ( v16 != nullptr )
          {
            v18 = v16->__vftable;
            v19 = CBaseEntity::entindex(this: pEdict);
            v18->SetInt(this: v17, a2: "player", a3: (int)v19);
            v17->SetInt(this: v17, a2: "achievement", a3: (int)v14);
            gameeventmanager->FireEvent(this: gameeventmanager, a2: v17, a3: false);
          }
          ((void (__thiscall *)(CBasePlayer *, const FireBulletsInfo_t *))pEdict->__vftable[1].GetServerClass)(
            a1: pEdict,
            a2: v14);
        }
      }
      return true;
    }
  }
  else
  {
    if ( args->m_nArgc >= 3 )
    {
      v5 = (CBaseMultiplayerPlayer *)__RTDynamicCast(
                                       inptr: pPlayer,
                                       VfDelta: 0,
                                       SrcType: &CBasePlayer `RTTI Type Descriptor',
                                       TargetType: &CBaseMultiplayerPlayer `RTTI Type Descriptor',
                                       isReference: 0);
      if ( v5 != nullptr )
      {
        v6 = locale;
        if ( args->m_nArgc > 1 )
          v6 = args->m_ppArgv[1];
        v7 = atoi(nptr: v6);
        if ( args->m_nArgc > 2 )
          v8 = args->m_ppArgv[2];
        else
          v8 = locale;
        v9 = atoi(nptr: v8);
        this->VoiceCommand(this, a2: v5, a3: v7, a4: v9);
      }
    }
    return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10176D40
// Name: public: virtual struct VoiceCommandMenuItem_t __near * CMultiplayRules::VoiceCommand(class CBaseMultiplayerPlayer __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
// bad sp value at call has been detected, the output may be wrong!
CMultiplayer_Expresser *__userpurge CMultiplayRules::VoiceCommand@<eax>(
        CMultiplayRules *this@<ecx>,
        int a2@<ebp>,
        CBaseMultiplayerPlayer *pPlayer,
        int iMenu,
        int iItem)
{
  unsigned int v5; // edi
  CUtlVector<VoiceCommandMenuItem_t,CUtlMemory<VoiceCommandMenuItem_t,int> > *v6; // eax
  CMultiplayer_Expresser *v7; // ecx
  bool (__thiscall *CanSpeakVoiceCommand)(CBaseMultiplayerPlayer *); // eax
  const Vector *v9; // eax
  int v10; // eax
  CBaseMultiplayerPlayer *v11; // eax
  int *v12; // edi
  const Vector *v13; // eax
  int v14; // edx
  float *v15; // eax
  __int128 v16; // xmm0
  CTeam *Team; // eax
  edict_t *v18; // eax
  _BYTE v20[12]; // [esp-Ch] [ebp-9Ch] BYREF
  __int128 szResponse_52; // [esp+34h] [ebp-5Ch] OVERLAPPED
  IRecipientFilter v22[3]; // [esp+50h] [ebp-40h] BYREF
  CRecipientFilter filter; // [esp+5Ch] [ebp-34h]
  int v24; // [esp+7Ch] [ebp-14h]
  CMultiplayer_Expresser *pExpresser; // [esp+80h] [ebp-10h]
  int index; // [esp+84h] [ebp-Ch]
  int i; // [esp+88h] [ebp-8h]
  int retaddr; // [esp+90h] [ebp+0h]

  index = a2;
  i = retaddr;
  if ( pPlayer == nullptr )
    return nullptr;
  if ( iMenu < 0 )
    return nullptr;
  if ( iMenu >= this->m_VoiceCommandMenus.m_Size )
    return nullptr;
  v5 = iItem;
  if ( iItem < 0 )
    return nullptr;
  v6 = &this->m_VoiceCommandMenus.m_Memory.m_pMemory[iMenu];
  if ( iItem >= v6->m_Size )
    return nullptr;
  v7 = (CMultiplayer_Expresser *)&v6->m_Memory.m_pMemory[iItem];
  CanSpeakVoiceCommand = pPlayer->CanSpeakVoiceCommand;
  pExpresser = v7;
  if ( !CanSpeakVoiceCommand(this: pPlayer) )
    return nullptr;
  filter.m_Recipients.m_pElements = (int *)pPlayer->GetMultiplayerExpresser(this: pPlayer);
  CMultiplayer_Expresser::AllowMultipleScenes(this: (CMultiplayer_Expresser *)filter.m_Recipients.m_pElements);
  if ( pPlayer->SpeakConceptIfAllowed(
         this: pPlayer,
         a2: (int)pExpresser->__vftable,
         a3: nullptr,
         a4: v20,
         a5: 64u,
         a6: nullptr) )
  {
    if ( LOBYTE(pExpresser->m_pSink) != 0 )
    {
      CRecipientFilter::CRecipientFilter(this: (CRecipientFilter *)v22);
      if ( BYTE1(pExpresser->m_pSink) != 0 )
      {
        v9 = pPlayer->WorldSpaceCenter(this: pPlayer);
        CRecipientFilter::AddRecipientsByPAS(this: (CRecipientFilter *)v22, origin: v9);
        v10 = ConCommandBase::GetFlags(this: (ConCommandBase *)v22) - 1;
        v24 = v10;
        if ( v10 >= 0 )
        {
          while ( 1 )
          {
            *(_DWORD *)&filter.m_bUsingPredictionRules = CRecipientFilter::GetRecipientIndex(
                                                           this: (CRecipientFilter *)v22,
                                                           slot: v10);
            v11 = (CBaseMultiplayerPlayer *)UTIL_PlayerByIndex(playerIndex: *(int *)&filter.m_bUsingPredictionRules);
            v12 = (int *)v11;
            if ( v11 != nullptr && v11 != pPlayer )
            {
              v13 = pPlayer->WorldSpaceCenter(this: pPlayer);
              v14 = *v12;
              filter.m_Recipients.m_Size = (int)v13;
              v15 = (float *)(*(int (__thiscall **)(int *))(v14 + 588))(a1: v12);
              v16 = 0;
              *(float *)&v16 = fsqrt(
                                 (float)((float)(v15[1] - *(float *)(filter.m_Recipients.m_Size + 4))
                                       * (float)(v15[1] - *(float *)(filter.m_Recipients.m_Size + 4)))
                               + (float)((float)(*v15 - *(float *)filter.m_Recipients.m_Size)
                                       * (float)(*v15 - *(float *)filter.m_Recipients.m_Size)));
              szResponse_52 = v16;
              if ( *(float *)&v16 > 1900.0 )
                CRecipientFilter::RemoveRecipientByPlayerIndex(
                  this: (CRecipientFilter *)v22,
                  playerindex: *(int *)&filter.m_bUsingPredictionRules);
            }
            if ( --v24 < 0 )
              break;
            v10 = v24;
          }
          v5 = iItem;
        }
      }
      else
      {
        CRecipientFilter::AddAllPlayers(this: (CRecipientFilter *)v22);
      }
      if ( !pPlayer->ShouldShowVoiceSubtitleToEnemy(this: pPlayer) )
      {
        Team = CBaseEntity::GetTeam(this: pPlayer);
        CRecipientFilter::RemoveRecipientsNotOnTeam(this: (CRecipientFilter *)v22, team: Team);
      }
      UserMessageBegin(filter: v22, messagename: "VoiceSubtitle");
      v18 = CBaseEntity::entindex(this: pPlayer);
      MessageWriteByte(iValue: (unsigned int)v18);
      MessageWriteByte(iValue: iMenu);
      MessageWriteByte(iValue: v5);
      MessageEnd();
      CRecipientFilter::~CRecipientFilter(this: (CRecipientFilter *)v22);
    }
    pPlayer->NoteSpokeVoiceCommand(this: pPlayer, a2: v20);
    CMultiplayer_Expresser::DisallowMultipleScenes(this: (CMultiplayer_Expresser *)filter.m_Recipients.m_pElements);
    return pExpresser;
  }
  else
  {
    pExpresser = nullptr;
    CMultiplayer_Expresser::DisallowMultipleScenes(this: (CMultiplayer_Expresser *)filter.m_Recipients.m_pElements);
    return pExpresser;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10176F90
// Name: void cc_SkipNextMapInCycle(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl cc_SkipNextMapInCycle()
{
  if ( UTIL_IsCommandIssuedByServerAdmin() && g_pGameRules != nullptr )
    CMultiplayRules::SkipNextMapInCycle(this: (CMultiplayRules *)g_pGameRules);
}

//------------------------------------------------------------------------------
// Address: 0x10176FB0
// Name: public: virtual float CMultiplayRules::FlPlayerFallDamage(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CMultiplayRules::FlPlayerFallDamage(CMultiplayRules *this, CBasePlayer *pPlayer)
{
  float m_Value; // xmm1_4
  CNetworkVarBase<float,CPlayerLocalData::NetworkVar_m_flFallVelocity> *p_m_flFallVelocity; // esi

  if ( (int)falldamage.m_pParent->m_Value.m_fValue != 1 )
    return 10.0;
  m_Value = pPlayer->m_Local.m_flFallVelocity.m_Value;
  p_m_flFallVelocity = &pPlayer->m_Local.m_flFallVelocity;
  if ( m_Value != (float)(m_Value - 580.0) )
  {
    pPlayer->m_Local.NetworkStateChanged(this: &pPlayer->m_Local, a2: &pPlayer->m_Local.m_flFallVelocity);
    p_m_flFallVelocity->m_Value = m_Value - 580.0;
  }
  return p_m_flFallVelocity->m_Value * 100.0 * 0.0022522523;
}

//------------------------------------------------------------------------------
// Address: 0x101770A0
// Name: protected: virtual void CMultiplayRules::GetNextLevelName(char __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMultiplayRules::GetNextLevelName(CMultiplayRules *this, char *pszNextMap, int bufsize, bool bRandom)
{
  const char *pszValue; // eax
  char *m_pszString; // edi
  int v6; // eax
  char **v7; // ecx
  char *v8; // edi
  const char *v9; // eax
  int m_Size; // eax
  int v11; // esi
  int v12; // eax
  int v13; // ecx
  bool v14; // zf
  char *v15; // edi
  const char *v16; // eax
  int v17; // eax
  int v18; // esi
  int v19; // ecx
  int v20; // esi
  char *v21; // eax
  unsigned __int8 *v22; // esi
  int v23; // edi
  char *v24; // esi
  int v25; // eax
  char *v26; // esi
  int v27; // eax
  int v28; // esi
  const char *v29; // eax
  int v30; // eax
  char szWarningMessage[260]; // [esp+4h] [ebp-10Ch] BYREF
  int nFileLength; // [esp+108h] [ebp-8h] BYREF
  char *aFileList; // [esp+10Ch] [ebp-4h]

  if ( mapcycledisabled.m_pParent != nullptr && mapcycledisabled.m_pParent->m_Value.m_nValue != 0 )
  {
    pszValue = gpGlobals->mapname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    V_strncpy(pDest: pszNextMap, pSrc: pszValue, maxLen: bufsize);
    return;
  }
  if ( (mapcyclefile.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = mapcyclefile.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)locale;
  }
  v6 = filesystem->GetPathTime(this: filesystem, a2: m_pszString, a3: "GAME");
  if ( v6 == 0 )
  {
    v8 = (char *)operator new(nSize: 0x20u);
    v9 = gpGlobals->mapname.pszValue;
    if ( v9 == nullptr )
      v9 = locale;
    V_strncpy(pDest: v8, pSrc: v9, maxLen: 32);
    m_Size = CMultiplayRules::m_MapList.m_Size;
    v11 = CMultiplayRules::m_MapList.m_Size;
    if ( CMultiplayRules::m_MapList.m_Size + 1 > CMultiplayRules::m_MapList.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&CMultiplayRules::m_MapList,
        num: CMultiplayRules::m_MapList.m_Size - CMultiplayRules::m_MapList.m_Memory.m_nAllocationCount + 1);
      m_Size = CMultiplayRules::m_MapList.m_Size;
    }
    v12 = m_Size + 1;
    v13 = v12 - v11 - 1;
    CMultiplayRules::m_MapList.m_Size = v12;
    CMultiplayRules::m_MapList.m_pElements = CMultiplayRules::m_MapList.m_Memory.m_pMemory;
    if ( v13 > 0 )
    {
      _V_memmove(
        dest: &CMultiplayRules::m_MapList.m_Memory.m_pMemory[v11 + 1],
        src: &CMultiplayRules::m_MapList.m_Memory.m_pMemory[v11],
        count: 4 * v13);
      v12 = CMultiplayRules::m_MapList.m_Size;
    }
    v7 = &CMultiplayRules::m_MapList.m_Memory.m_pMemory[v11];
    if ( v7 == nullptr )
      goto LABEL_20;
    *v7 = v8;
LABEL_19:
    v12 = CMultiplayRules::m_MapList.m_Size;
    goto LABEL_20;
  }
  if ( CMultiplayRules::m_nMapCycleTimeStamp == v6 )
    goto LABEL_19;
  v20 = 0;
  CMultiplayRules::m_nMapCycleTimeStamp = v6;
  for ( CMultiplayRules::m_nMapCycleindex = 0; v20 < CMultiplayRules::m_MapList.m_Size; ++v20 )
    free(pMem: CMultiplayRules::m_MapList.m_Memory.m_pMemory[v20]);
  CMultiplayRules::m_MapList.m_Size = 0;
  v21 = (char *)UTIL_LoadFileForMe(filename: m_pszString, pLength: &nFileLength);
  v22 = (unsigned __int8 *)v21;
  aFileList = v21;
  if ( v21 == nullptr || nFileLength == 0 )
    goto LABEL_52;
  V_SplitString(pString: v21, pSeparator: "\n", outStrings: &CMultiplayRules::m_MapList);
  v23 = 0;
  if ( CMultiplayRules::m_MapList.m_Size <= 0 )
    goto LABEL_51;
  do
  {
    v24 = CMultiplayRules::m_MapList.m_Memory.m_pMemory[v23];
    strchr(string: v24, chr: 0xDu);
    while ( v25 != 0 )
    {
      _V_strcpy(dest: (char *)v25, src: (const char *)(v25 + 1));
      strchr(string: v24, chr: 0xDu);
    }
    v26 = CMultiplayRules::m_MapList.m_Memory.m_pMemory[v23];
    strchr(string: v26, chr: 0x20u);
    while ( v27 != 0 )
    {
      _V_strcpy(dest: (char *)v27, src: (const char *)(v27 + 1));
      strchr(string: v26, chr: 0x20u);
    }
    if ( engine->IsMapValid(this: engine, a2: CMultiplayRules::m_MapList.m_Memory.m_pMemory[v23]) != 0 )
    {
      if ( V_strncmp(s1: CMultiplayRules::m_MapList.m_Memory.m_pMemory[v23], s2: "//", count: 2) != 0 )
        goto LABEL_49;
    }
    else
    {
      V_snprintf(
        pDest: szWarningMessage,
        maxLen: 260,
        pFormat: "Invalid map '%s' included in map cycle file. Ignored.\n",
        CMultiplayRules::m_MapList.m_Memory.m_pMemory[v23]);
      _Warning(a1: szWarningMessage);
    }
    free(pMem: CMultiplayRules::m_MapList.m_Memory.m_pMemory[v23]);
    if ( CMultiplayRules::m_MapList.m_Size - v23 - 1 > 0 )
      _V_memmove(
        dest: &CMultiplayRules::m_MapList.m_Memory.m_pMemory[v23],
        src: &CMultiplayRules::m_MapList.m_Memory.m_pMemory[v23 + 1],
        count: 4 * (CMultiplayRules::m_MapList.m_Size - v23 - 1));
    --CMultiplayRules::m_MapList.m_Size;
    --v23;
LABEL_49:
    ++v23;
  }
  while ( v23 < CMultiplayRules::m_MapList.m_Size );
  v22 = (unsigned __int8 *)aFileList;
LABEL_51:
  UTIL_FreeFile(buffer: v22);
LABEL_52:
  v12 = CMultiplayRules::m_MapList.m_Size;
  v28 = 0;
  v14 = CMultiplayRules::m_MapList.m_Size == 0;
  if ( CMultiplayRules::m_MapList.m_Size > 0 )
  {
    while ( 1 )
    {
      v29 = gpGlobals->mapname.pszValue;
      if ( v29 == nullptr )
        v29 = locale;
      v30 = _V_strcmp(s1: v29, s2: CMultiplayRules::m_MapList.m_Memory.m_pMemory[v28++]);
      v14 = v30 == 0;
      v12 = CMultiplayRules::m_MapList.m_Size;
      if ( v14 )
        break;
      if ( v28 >= CMultiplayRules::m_MapList.m_Size )
        goto LABEL_20;
    }
    CMultiplayRules::m_nMapCycleindex = v28;
    if ( v28 >= CMultiplayRules::m_MapList.m_Size )
      CMultiplayRules::m_nMapCycleindex = 0;
LABEL_20:
    v14 = v12 == 0;
  }
  if ( v14 )
  {
    v15 = (char *)operator new(nSize: 0x20u);
    v16 = gpGlobals->mapname.pszValue;
    if ( v16 == nullptr )
      v16 = locale;
    V_strncpy(pDest: v15, pSrc: v16, maxLen: 32);
    v17 = CMultiplayRules::m_MapList.m_Size;
    v18 = CMultiplayRules::m_MapList.m_Size;
    if ( CMultiplayRules::m_MapList.m_Size + 1 > CMultiplayRules::m_MapList.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&CMultiplayRules::m_MapList,
        num: CMultiplayRules::m_MapList.m_Size - CMultiplayRules::m_MapList.m_Memory.m_nAllocationCount + 1);
      v17 = CMultiplayRules::m_MapList.m_Size;
    }
    v12 = v17 + 1;
    v19 = v12 - v18 - 1;
    CMultiplayRules::m_MapList.m_Size = v12;
    CMultiplayRules::m_MapList.m_pElements = CMultiplayRules::m_MapList.m_Memory.m_pMemory;
    if ( v19 > 0 )
    {
      _V_memmove(
        dest: &CMultiplayRules::m_MapList.m_Memory.m_pMemory[v18 + 1],
        src: &CMultiplayRules::m_MapList.m_Memory.m_pMemory[v18],
        count: 4 * v19);
      v12 = CMultiplayRules::m_MapList.m_Size;
    }
    v7 = &CMultiplayRules::m_MapList.m_Memory.m_pMemory[v18];
    if ( v7 != nullptr )
    {
      *v7 = v15;
      v12 = CMultiplayRules::m_MapList.m_Size;
    }
  }
  if ( bRandom )
    CMultiplayRules::m_nMapCycleindex = _RandomInt(this: (IUniformRandomStream *)v7, a2: 0, a3: v12 - 1);
  V_strncpy(
    pDest: pszNextMap,
    pSrc: CMultiplayRules::m_MapList.m_Memory.m_pMemory[CMultiplayRules::m_nMapCycleindex],
    maxLen: bufsize);
}

//------------------------------------------------------------------------------
// Address: 0x101774B0
// Name: public: void CMultiplayRules::LoadVoiceCommandScript(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMultiplayRules::LoadVoiceCommandScript(CMultiplayRules *this)
{
  KeyValues *v2; // eax
  IBaseFileSystem *v3; // eax
  KeyValues *v4; // edi
  CUtlVector<CUtlVector<VoiceCommandMenuItem_t,CUtlMemory<VoiceCommandMenuItem_t,int> >,CUtlMemory<CUtlVector<VoiceCommandMenuItem_t,CUtlMemory<VoiceCommandMenuItem_t,int> >,int> > *p_m_VoiceCommandMenus; // esi
  int v6; // edi
  KeyValues *FirstSubKey; // ebx
  const char *String; // eax
  int MPConceptIndexFromString; // esi
  const char *v10; // eax
  const char *v11; // eax
  int v12; // ecx
  int m_Size; // edi
  CUtlMemory<VoiceCommandMenuItem_t,int> *p_m_Memory; // esi
  int m_nAllocationCount; // eax
  VoiceCommandMenuItem_t *m_pMemory; // ecx
  int v17; // eax
  VoiceCommandMenuItem_t *v18; // edi
  VoiceCommandMenuItem_t item; // [esp+8h] [ebp-5Ch] BYREF
  int iMenuIndex; // [esp+50h] [ebp-14h]
  CUtlVector<CUtlVector<VoiceCommandMenuItem_t,CUtlMemory<VoiceCommandMenuItem_t,int> >,CUtlMemory<CUtlVector<VoiceCommandMenuItem_t,CUtlMemory<VoiceCommandMenuItem_t,int> >,int> > *v21; // [esp+54h] [ebp-10h]
  int iNumItems; // [esp+58h] [ebp-Ch]
  KeyValues *pKV; // [esp+5Ch] [ebp-8h]
  KeyValues *menu; // [esp+60h] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    pKV = KeyValues::KeyValues(this: v2, setName: "VoiceCommands");
  else
    pKV = nullptr;
  if ( filesystem != nullptr )
    v3 = &filesystem->IBaseFileSystem;
  else
    v3 = nullptr;
  v4 = pKV;
  if ( KeyValues::LoadFromFile(
         this: pKV,
         filesystem: v3,
         resourceName: "scripts/voicecommands.txt",
         pathID: "GAME",
         pfnEvaluateSymbolProc: nullptr) )
  {
    menu = KeyValues::GetFirstSubKey(this: pKV);
    if ( menu != nullptr )
    {
      p_m_VoiceCommandMenus = &this->m_VoiceCommandMenus;
      v21 = p_m_VoiceCommandMenus;
      do
      {
        v6 = CUtlVector<CUtlVector<VoiceCommandMenuItem_t,CUtlMemory<VoiceCommandMenuItem_t,int>>,CUtlMemory<CUtlVector<VoiceCommandMenuItem_t,CUtlMemory<VoiceCommandMenuItem_t,int>>,int>>::InsertBefore(
               this: p_m_VoiceCommandMenus,
               elem: p_m_VoiceCommandMenus->m_Size);
        iMenuIndex = v6;
        iNumItems = 0;
        FirstSubKey = KeyValues::GetFirstSubKey(this: menu);
        if ( FirstSubKey != nullptr )
        {
          while ( 1 )
          {
            if ( ++iNumItems <= 9 )
            {
              String = KeyValues::GetString(this: FirstSubKey, keyName: "concept", defaultValue: locale);
              MPConceptIndexFromString = GetMPConceptIndexFromString(pszConcept: String);
              if ( MPConceptIndexFromString == -1 )
              {
                v10 = KeyValues::GetString(this: FirstSubKey, keyName: "concept", defaultValue: locale);
                _Warning(
                  a1: "Voicecommand script attempting to use unknown concept. Need to define new concepts in code. ( %s )\n",
                  v10);
              }
              item.m_iConcept = MPConceptIndexFromString;
              item.m_bShowSubtitle = KeyValues::GetInt(this: FirstSubKey, keyName: "show_subtitle", defaultValue: 0) > 0;
              item.m_bDistanceBasedSubtitle = KeyValues::GetInt(
                                                this: FirstSubKey,
                                                keyName: "distance_check_subtitle",
                                                defaultValue: 0) > 0;
              v11 = KeyValues::GetString(this: FirstSubKey, keyName: "activity", defaultValue: locale);
              V_strncpy(pDest: item.m_szGestureActivity, pSrc: v11, maxLen: 64);
              v12 = v6;
              m_Size = v21->m_Memory.m_pMemory[v6].m_Size;
              p_m_Memory = &v21->m_Memory.m_pMemory[v12].m_Memory;
              m_nAllocationCount = p_m_Memory->m_nAllocationCount;
              if ( m_Size + 1 > m_nAllocationCount )
                CUtlMemory<VoiceCommandMenuItem_t,int>::Grow(this: p_m_Memory, num: m_Size - m_nAllocationCount + 1);
              ++p_m_Memory[1].m_pMemory;
              m_pMemory = p_m_Memory->m_pMemory;
              v17 = (int)p_m_Memory[1].m_pMemory - m_Size - 1;
              p_m_Memory[1].m_nAllocationCount = (int)p_m_Memory->m_pMemory;
              if ( v17 > 0 )
                _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 72 * v17);
              v18 = &p_m_Memory->m_pMemory[m_Size];
              if ( v18 != nullptr )
                *v18 = item;
            }
            else
            {
              _Warning(a1: "Trying to load more than 9 menu items in voicecommands.txt, extras ignored");
            }
            FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
            if ( FirstSubKey == nullptr )
              break;
            v6 = iMenuIndex;
          }
          p_m_VoiceCommandMenus = v21;
        }
        menu = KeyValues::GetNextKey(this: menu);
      }
      while ( menu != nullptr );
      v4 = pKV;
    }
  }
  KeyValues::deleteThis(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101776B0
// Name: public: CMultiplayRules::CMultiplayRules(void)
// Source: json
//------------------------------------------------------------------------------
CMultiplayRules *__thiscall CMultiplayRules::CMultiplayRules(CMultiplayRules *this)
{
  char *v2; // edi
  char *v3; // eax
  char *m_pszString; // eax
  char szCommand[256]; // [esp+Ch] [ebp-100h] BYREF

  CGameRules::CGameRules(this);
  this->__vftable = (CMultiplayRules_vtbl *)&CMultiplayRules::`vftable';
  this->m_VoiceCommandMenus.m_Memory.m_pMemory = nullptr;
  this->m_VoiceCommandMenus.m_Memory.m_nAllocationCount = 0;
  this->m_VoiceCommandMenus.m_Memory.m_nGrowSize = 0;
  this->m_VoiceCommandMenus.m_Size = 0;
  this->m_VoiceCommandMenus.m_pElements = nullptr;
  CGameRules::RefreshSkillData(this, forceUpdate: true);
  if ( !engine->IsDedicatedServer(this: engine) )
  {
    if ( (lservercfgfile.m_nFlags & 0x1000) != 0 )
    {
      v2 = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = lservercfgfile.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        goto LABEL_13;
      v2 = lservercfgfile.m_pParent->m_Value.m_pszString;
      if ( *m_pszString == 0 )
        goto LABEL_13;
    }
    _Msg(a1: "Executing listen server config file\n");
    goto LABEL_12;
  }
  if ( (servercfgfile.m_nFlags & 0x1000) != 0 )
  {
    v2 = "FCVAR_NEVER_AS_STRING";
    _Msg(a1: "Executing dedicated server config file\n");
LABEL_12:
    V_snprintf(pDest: szCommand, maxLen: 256, pFormat: "exec %s\n", v2);
    engine->ServerCommand(this: engine, a2: szCommand);
    goto LABEL_13;
  }
  v3 = servercfgfile.m_pParent->m_Value.m_pszString;
  if ( v3 != nullptr )
  {
    v2 = servercfgfile.m_pParent->m_Value.m_pszString;
    if ( *v3 != 0 )
    {
      _Msg(a1: "Executing dedicated server config file\n");
      goto LABEL_12;
    }
  }
LABEL_13:
  ConVar::SetValue(this: (ConVar *)&nextlevel.IConVar, value: locale);
  CMultiplayRules::LoadVoiceCommandScript(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101777B0
// Name: public: virtual void CMultiplayRules::EndMultiplayerGame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMultiplayRules::EndMultiplayerGame(CMultiplayRules *this)
{
  this->GoToIntermission(this);
}

//------------------------------------------------------------------------------
// Address: 0x101777C0
// Name: public: virtual void CMultiplayRules::ResetMapCycleTimeStamp(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMultiplayRules::ResetMapCycleTimeStamp(CMultiplayRules *this)
{
  CMultiplayRules::m_nMapCycleTimeStamp = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101777D0
// Name: void __CreateGameRules_CMultiplayRules(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __CreateGameRules_CMultiplayRules()
{
  CMultiplayRules *v0; // esi

  v0 = (CMultiplayRules *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 36);
  _V_memset(dest: v0, fill: 0, count: 36);
  if ( v0 != nullptr )
    CMultiplayRules::CMultiplayRules(this: v0);
}

//------------------------------------------------------------------------------
// Address: 0x10406800
// Name: _dynamic_initializer_for__CMultiplayRules::m_MapList__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CMultiplayRules::m_MapList__()
{
  return atexit(func: dynamic_atexit_destructor_for__CMultiplayRules::m_MapList__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C7B0
// Name: _dynamic_atexit_destructor_for__CMultiplayRules::m_MapList__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMultiplayRules::m_MapList__()
{
  CUtlVector<SWeaponHitData *,CUtlMemory<SWeaponHitData *,int>>::PurgeAndDeleteElements(this: &CMultiplayRules::m_MapList);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&CMultiplayRules::m_MapList);
}

//------------------------------------------------------------------------------
// Address: 0x10406810
// Name: _dynamic_initializer_for__clear_debug_overlays_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__clear_debug_overlays_command__()
{
  ConCommand::ConCommand(
    this: &clear_debug_overlays_command,
    pName: "clear_debug_overlays",
    callback: (void (__cdecl *)())clear_debug_overlays,
    pHelpString: "clears debug overlays",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__clear_debug_overlays_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10406840
// Name: _dynamic_initializer_for__g_debug_vehicledriver__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_debug_vehicledriver__()
{
  ConVar::ConVar(this: &g_debug_vehicledriver, pName: "g_debug_vehicledriver", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__g_debug_vehicledriver__);
}

//------------------------------------------------------------------------------
// Address: 0x1041C7D0
// Name: _dynamic_atexit_destructor_for__clear_debug_overlays_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__clear_debug_overlays_command__()
{
  ConCommand::~ConCommand(this: &clear_debug_overlays_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041C7E0
// Name: _dynamic_atexit_destructor_for__g_debug_vehicledriver__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_debug_vehicledriver__()
{
  ConVar::~ConVar(this: &g_debug_vehicledriver);
}

//------------------------------------------------------------------------------
// Address: 0x1041C7F0
// Name: _DataMapInit_CNPC_VehicleDriver__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CNPC_VehicleDriver__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_284);
}

//------------------------------------------------------------------------------
// Address: 0x1041C800
// Name: _dynamic_atexit_destructor_for__sv_pushaway_force__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_pushaway_force__()
{
  ConVar::~ConVar(this: &sv_pushaway_force);
}

//------------------------------------------------------------------------------
// Address: 0x1041C810
// Name: _dynamic_atexit_destructor_for__sv_pushaway_min_player_speed__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_pushaway_min_player_speed__()
{
  ConVar::~ConVar(this: &sv_pushaway_min_player_speed);
}

//------------------------------------------------------------------------------
// Address: 0x1041C820
// Name: _dynamic_atexit_destructor_for__sv_pushaway_max_force__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_pushaway_max_force__()
{
  ConVar::~ConVar(this: &sv_pushaway_max_force);
}

//------------------------------------------------------------------------------
// Address: 0x1041C830
// Name: _dynamic_atexit_destructor_for__sv_pushaway_clientside__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_pushaway_clientside__()
{
  ConVar::~ConVar(this: &sv_pushaway_clientside);
}

//------------------------------------------------------------------------------
// Address: 0x1041C840
// Name: _dynamic_atexit_destructor_for__sv_pushaway_player_force__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_pushaway_player_force__()
{
  ConVar::~ConVar(this: &sv_pushaway_player_force);
}

//------------------------------------------------------------------------------
// Address: 0x1041C850
// Name: _dynamic_atexit_destructor_for__sv_pushaway_max_player_force__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_pushaway_max_player_force__()
{
  ConVar::~ConVar(this: &sv_pushaway_max_player_force);
}

//------------------------------------------------------------------------------
// Address: 0x1041C860
// Name: _DataMapInit_CParticleLight__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CParticleLight__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_285);
}

} // namespace server
