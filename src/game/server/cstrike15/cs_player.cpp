// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/cs_player.cpp
// Functions: 291
// ============================================================

#include "game\server\cstrike15\cs_player.h"

//------------------------------------------------------------------------------
// Address: 0x10253F80
// Name: public: class CBasePlayer const __near * CNetworkHandleBase<class CBasePlayer,class CPropVehicleDriveable::NetworkVar_m_hPlayer>::Set(class CBasePlayer const __near *)
// Source: json
//------------------------------------------------------------------------------
const CBasePlayer *__thiscall CNetworkHandleBase<CBasePlayer,CPropVehicleDriveable::NetworkVar_m_hPlayer>::Set(
        CNetworkHandleBase<CBasePlayer,CPropVehicleDriveable::NetworkVar_m_hPlayer> *this,
        const CBasePlayer *val)
{
  unsigned int m_Index; // eax
  const CBasePlayer *m_pEntity; // ecx
  CNetworkHandleBase<CBasePlayer,CPropVehicleDriveable::NetworkVar_m_hPlayer> *v5; // eax
  CBaseEdict *v6; // ecx

  m_Index = this->m_Value.m_Index;
  if ( this->m_Value.m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (const CBasePlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  }
  if ( m_pEntity != val )
  {
    v5 = this - 416;
    if ( *((_BYTE *)this - 1580) != 0 )
    {
      LOBYTE(v5[22].m_Value.m_Index) |= 1u;
    }
    else
    {
      v6 = (CBaseEdict *)v5[6].m_Value.m_Index;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0x680u);
    }
    if ( val != nullptr )
    {
      this->m_Value.m_Index = val->GetRefEHandle(this: val)->m_Index;
      return val;
    }
    this->m_Value.m_Index = -1;
  }
  return val;
}

//------------------------------------------------------------------------------
// Address: 0x1027D560
// Name: public: virtual class ServerClass __near * CCSRagdoll::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CCSRagdoll::GetServerClass(CCSRagdoll *this)
{
  return &g_CCSRagdoll_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1027D570
// Name: public: virtual class ServerClass __near * CTEPlayerAnimEvent::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CTEPlayerAnimEvent::GetServerClass(CTEPlayerAnimEvent *this)
{
  return &g_CTEPlayerAnimEvent_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1027D580
// Name: public: virtual void playerPrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall playerPrecache::CResourcePrecacher::Cache(
        playerPrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "player",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1027D5B0
// Name: public: virtual class ServerClass __near * CCSPlayer::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CCSPlayer::GetServerClass(CCSPlayer *this)
{
  return &g_CCSPlayer_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x1027D5C0
// Name: public: virtual struct datamap_t __near * CCSPlayer::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CCSPlayer::GetDataDescMap(CCSPlayer *this)
{
  return &CCSPlayer::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1027D5D0
// Name: class CCSBot __near * ToCSBot(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CCSBot *__cdecl ToCSBot(CBaseEntity *pEntity)
{
  void *v1; // esi

  if ( pEntity != nullptr
    && pEntity->IsPlayer(this: pEntity)
    && (v1 = __RTDynamicCast(
               inptr: pEntity,
               VfDelta: 0,
               SrcType: &CBaseEntity `RTTI Type Descriptor',
               TargetType: &CCSPlayer `RTTI Type Descriptor',
               isReference: 0)) != nullptr
    && (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)v1 + 1912))(a1: v1) != 0 )
  {
    return (CCSBot *)__RTDynamicCast(
                       inptr: v1,
                       VfDelta: 0,
                       SrcType: &CCSPlayer `RTTI Type Descriptor',
                       TargetType: &CCSBot `RTTI Type Descriptor',
                       isReference: 0);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027D640
// Name: void cc_CreatePredictionError_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl cc_CreatePredictionError_f(const CCommand *args)
{
  int m_nArgc; // eax
  bool v2; // cc
  const char *v3; // eax
  edict_t *pEdicts; // esi
  edict_t *v5; // eax
  IServerUnknown *m_pUnk; // ecx
  CBaseEntity *v7; // esi
  Vector absOrigin; // [esp+0h] [ebp-10h] BYREF
  float distance; // [esp+Ch] [ebp-4h]
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  m_nArgc = args->m_nArgc;
  distance = 32.0;
  if ( m_nArgc >= 2 )
  {
    v2 = m_nArgc <= 1;
    v3 = locale;
    if ( !v2 )
      v3 = args->m_ppArgv[1];
    distance = atof(nptr: v3);
  }
  pEdicts = gpGlobals->pEdicts;
  if ( pEdicts != nullptr )
    v5 = (pEdicts[1].m_fStateFlags & 2) == 0 ? &pEdicts[1] : nullptr;
  else
    v5 = nullptr;
  if ( (v5 != nullptr || pEdicts != nullptr && (v5 = gpGlobals->pEdicts, (pEdicts->m_fStateFlags & 2) == 0))
    && (m_pUnk = v5->m_pUnk) != nullptr )
  {
    v7 = m_pUnk->GetBaseEntity(this: m_pUnk);
  }
  else
  {
    v7 = nullptr;
  }
  if ( (v7->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: v7, a2: (int)&savedregs);
  absOrigin.x = distance + v7->m_vecAbsOrigin.x;
  absOrigin.y = v7->m_vecAbsOrigin.y;
  absOrigin.z = v7->m_vecAbsOrigin.z;
  CBaseEntity::SetAbsOrigin(this: v7, &absOrigin);
}

//------------------------------------------------------------------------------
// Address: 0x1027D740
// Name: public: virtual void CCSPlayer::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CCSPlayer::Precache(CCSPlayer *this@<ecx>, bool (__cdecl *a2)(const char *)@<edi>)
{
  int v3; // esi
  IVEngineServer_vtbl *v4; // edi
  const char *ClassModelPath; // eax
  IVEngineServer_vtbl *v6; // edi
  const char *v7; // eax
  const char *TViewModelPath; // eax
  const char *CTViewModelPath; // eax
  bool (__cdecl *v10)(const char *); // [esp-Ch] [ebp-24h]
  Vector mins; // [esp+0h] [ebp-18h] BYREF
  Vector maxs; // [esp+Ch] [ebp-Ch] BYREF

  mins.x = -13.0;
  mins.y = -13.0;
  mins.z = -10.0;
  maxs.x = 13.0;
  maxs.y = 13.0;
  maxs.z = 75.0;
  PlayerModelInfo::InitializeForCurrentMap(this: &PlayerModelInfo::s_PlayerModelInfo);
  v3 = 1;
  if ( PlayerModelInfo::s_PlayerModelInfo.m_NumCTModels + PlayerModelInfo::s_PlayerModelInfo.m_NumTModels >= 1 )
  {
    v10 = a2;
    do
    {
      v4 = engine->__vftable;
      ClassModelPath = PlayerModelInfo::GetClassModelPath(this: &PlayerModelInfo::s_PlayerModelInfo, classID: v3);
      v4->PrecacheModel(this: engine, a2: ClassModelPath, a3: true);
      v6 = engine->__vftable;
      v7 = PlayerModelInfo::GetClassModelPath(this: &PlayerModelInfo::s_PlayerModelInfo, classID: v3);
      v6->ForceModelBounds(this: engine, a2: v7, a3: &mins, a4: &maxs);
      ++v3;
    }
    while ( v3 <= PlayerModelInfo::s_PlayerModelInfo.m_NumCTModels + PlayerModelInfo::s_PlayerModelInfo.m_NumTModels );
    a2 = v10;
  }
  TViewModelPath = PlayerModelInfo::GetTViewModelPath();
  CBaseEntity::PrecacheModel(a1: a2, name: TViewModelPath, bPreload: true);
  CTViewModelPath = PlayerModelInfo::GetCTViewModelPath();
  CBaseEntity::PrecacheModel(a1: a2, name: CTViewModelPath, bPreload: true);
  CBaseEntity::PrecacheScriptSound(soundname: "Player.DeathHeadShot");
  CBaseEntity::PrecacheScriptSound(soundname: "Player.Death");
  CBaseEntity::PrecacheScriptSound(soundname: "Player.DamageHelmet");
  CBaseEntity::PrecacheScriptSound(soundname: "Player.DamageHeadShot");
  CBaseEntity::PrecacheScriptSound(soundname: "Flesh.BulletImpact");
  CBaseEntity::PrecacheScriptSound(soundname: "Player.DamageKevlar");
  CBaseEntity::PrecacheScriptSound(soundname: "Player.PickupWeapon");
  CBaseEntity::PrecacheScriptSound(soundname: "Player.NightVisionOff");
  CBaseEntity::PrecacheScriptSound(soundname: "Player.NightVisionOn");
  CBaseEntity::PrecacheScriptSound(soundname: "Player.FlashlightOn");
  CBaseEntity::PrecacheScriptSound(soundname: "Player.FlashlightOff");
  CBaseEntity::PrecacheScriptSound(soundname: "Default.Land");
  CBaseEntity::PrecacheScriptSound(soundname: "Bot.StuckSound");
  CBaseEntity::PrecacheScriptSound(soundname: "Bot.StuckStart");
  CBaseEntity::PrecacheScriptSound(soundname: "Bot.FellOff");
  UTIL_PrecacheOther(szClassname: "item_kevlar", modelName: nullptr);
  UTIL_PrecacheOther(szClassname: "item_assaultsuit", modelName: nullptr);
  UTIL_PrecacheOther(szClassname: "item_defuser", modelName: nullptr);
  CBaseEntity::PrecacheModel(a1: a2, name: "sprites/glow01.vmt", bPreload: true);
  PrecacheEffect(pEffectName: "csblood");
  PrecacheEffect(pEffectName: "gunshotsplash");
  PrecacheParticleSystem(pParticleSystemName: "achieved");
  CBasePlayer::Precache(this);
}

//------------------------------------------------------------------------------
// Address: 0x1027D920
// Name: public: virtual void CCSPlayer::ShowViewPortPanel(char const __near *,bool,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::ShowViewPortPanel(CCSPlayer *this, const char *name, bool bShow, KeyValues *data)
{
  CResponseRulesToEngineInterface *v5; // ecx
  ICommandLine *v6; // eax

  if ( !CCSGameRules::IsLogoMap(this: (CCSGameRules *)g_pGameRules) )
  {
    v6 = _CommandLine(this: v5);
    if ( v6->FindParm(this: v6, a2: "-makedevshots") == 0 )
      CBasePlayer::ShowViewPortPanel(this, name, bShow, data);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027D970
// Name: public: int CCSPlayer::GetPercentageOfEnemyTeamKilled(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSPlayer::GetPercentageOfEnemyTeamKilled(CCSPlayer *this)
{
  int m_NumEnemiesAtRoundStart; // eax

  m_NumEnemiesAtRoundStart = this->m_NumEnemiesAtRoundStart;
  if ( m_NumEnemiesAtRoundStart <= 0 )
    return 0;
  else
    return (int)(float)((float)((float)this->m_NumEnemiesKilledThisRound / (float)m_NumEnemiesAtRoundStart) * 100.0);
}

//------------------------------------------------------------------------------
// Address: 0x1027D9A0
// Name: public: virtual void CCSPlayer::VPhysicsShadowUpdate(class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSPlayer::VPhysicsShadowUpdate(CCSPlayer *this@<ecx>, int a2@<edi>, IPhysicsObject *pPhysics)
{
  if ( CCSPlayer::CanMove(this) )
    CBasePlayer::VPhysicsShadowUpdate(this, a2, pPhysics: *(float *)&pPhysics);
}

//------------------------------------------------------------------------------
// Address: 0x1027D9C0
// Name: public: virtual void CCSPlayer::SetupVisibility(class CBaseEntity __near *,unsigned char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::SetupVisibility(
        CCSPlayer *this,
        CBaseEntity *pViewEntity,
        unsigned __int8 *pvs,
        int pvssize)
{
  CServerNetworkProperty *p_m_Network; // ecx
  int v6; // eax

  CBasePlayer::SetupVisibility(this, pViewEntity, pvs, pvssize);
  p_m_Network = &pViewEntity->m_Network;
  if ( pViewEntity == nullptr )
    p_m_Network = &this->m_Network;
  v6 = p_m_Network->AreaNum(this: p_m_Network);
  PointCameraSetupVisibility(pPlayer: this, area: v6, pvs, pvssize);
}

//------------------------------------------------------------------------------
// Address: 0x1027DA00
// Name: public: virtual bool CCSPlayer::IsValidObserverTarget(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSPlayer::IsValidObserverTarget(CCSPlayer *this, CBaseEntity *target)
{
  if ( target == nullptr )
    return false;
  if ( target->IsPlayer(this: target) )
    return CBasePlayer::IsValidObserverTarget(this, target);
  return __RTDynamicCast(
           inptr: target,
           VfDelta: 0,
           SrcType: &CBaseEntity `RTTI Type Descriptor',
           TargetType: &CPlantedC4 `RTTI Type Descriptor',
           isReference: 0) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1027DA60
// Name: protected: void CCSPlayer::PushawayThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CCSPlayer::PushawayThink(CCSPlayer *this@<ecx>, IPhysicsObject *a2@<ebp>, int a3@<edi>)
{
  PerformObstaclePushaway(a1: a2, a2: a3, a3: (int)this, pPushingEntity: this);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.050000001, szContext: "CSPushawayThink");
}

//------------------------------------------------------------------------------
// Address: 0x1027DAA0
// Name: public: virtual bool CCSPlayer::Weapon_CanSwitchTo(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSPlayer::Weapon_CanSwitchTo(CCSPlayer *this, CBaseCombatWeapon *pWeapon)
{
  bool result; // al
  CBaseCombatWeapon *ActiveWeapon; // eax

  result = false;
  if ( pWeapon->CanDeploy(this: pWeapon) )
  {
    if ( CBaseCombatCharacter::GetActiveWeapon(this) == nullptr )
      return true;
    ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
    if ( ActiveWeapon->CanHolster(this: ActiveWeapon) )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1027DAF0
// Name: public: void CCSPlayer::HintMessage(char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::HintMessage(
        CCSPlayer *this,
        const char *pMessage,
        bool bDisplayIfDead,
        bool bOverrideClientSettings)
{
  CHintMessageQueue *m_pHintMessageQueue; // ecx

  if ( (bDisplayIfDead || this->IsAlive(this)) && this->IsNetClient(this) )
  {
    m_pHintMessageQueue = this->m_pHintMessageQueue;
    if ( m_pHintMessageQueue != nullptr && (bOverrideClientSettings || this->m_bShowHints) )
      CHintMessageQueue::AddMessage(this: m_pHintMessageQueue, message: pMessage, duration: 6.0, args: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027DB60
// Name: public: void CCSPlayer::MarkAsNotReceivingMoneyNextRound(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::MarkAsNotReceivingMoneyNextRound(CCSPlayer *this)
{
  this->m_receivesMoneyNextRound = false;
}

//------------------------------------------------------------------------------
// Address: 0x1027DB70
// Name: public: bool CCSPlayer::DoesPlayerGetRoundStartMoney(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSPlayer::DoesPlayerGetRoundStartMoney(CCSPlayer *this)
{
  return this->m_receivesMoneyNextRound;
}

//------------------------------------------------------------------------------
// Address: 0x1027DB80
// Name: public: static class CCSPlayer __near * CCSPlayer::Instance(int)
// Source: json
//------------------------------------------------------------------------------
CCSPlayer *__cdecl CCSPlayer::Instance(int iEnt)
{
  edict_t *pEdicts; // esi
  edict_t *v2; // eax
  IServerUnknown *m_pUnk; // ecx
  CBaseEntity *v4; // eax

  pEdicts = gpGlobals->pEdicts;
  if ( pEdicts != nullptr )
    v2 = (pEdicts[iEnt].m_fStateFlags & 2) == 0 ? &pEdicts[iEnt] : nullptr;
  else
    v2 = nullptr;
  if ( (v2 != nullptr || pEdicts != nullptr && (v2 = gpGlobals->pEdicts, (pEdicts->m_fStateFlags & 2) == 0))
    && (m_pUnk = v2->m_pUnk) != nullptr )
  {
    v4 = m_pUnk->GetBaseEntity(this: m_pUnk);
  }
  else
  {
    v4 = nullptr;
  }
  return (CCSPlayer *)__RTDynamicCast(
                        inptr: v4,
                        VfDelta: 0,
                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                        TargetType: &CCSPlayer `RTTI Type Descriptor',
                        isReference: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1027DBF0
// Name: public: void CCSPlayer::CheckTKPunishment(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::CheckTKPunishment(CCSPlayer *this)
{
  CCSPlayer_vtbl *v1; // eax
  void (__thiscall *CommitSuicide)(CBasePlayer *, bool, bool); // edx

  if ( this->m_bJustKilledTeammate && mp_tkpunish.m_pParent != nullptr && mp_tkpunish.m_pParent->m_Value.m_nValue != 0 )
  {
    v1 = this->CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
    this->m_bPunishedForTK = true;
    CommitSuicide = v1->CommitSuicide;
    this->m_bJustKilledTeammate = false;
    ((void (__stdcall *)(_DWORD, _DWORD))CommitSuicide)(a1: 0, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027DC30
// Name: public: class CWeaponCSBase __near * CCSPlayer::GetActiveCSWeapon(void)const
// Source: json
//------------------------------------------------------------------------------
CWeaponCSBase *__thiscall CCSPlayer::GetActiveCSWeapon(CCSPlayer *this)
{
  CBaseCombatWeapon *ActiveWeapon; // eax

  ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
  return (CWeaponCSBase *)__RTDynamicCast(
                            inptr: ActiveWeapon,
                            VfDelta: 0,
                            SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
                            TargetType: &CWeaponCSBase `RTTI Type Descriptor',
                            isReference: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1027DC50
// Name: public: bool CCSPlayer::IsVIP(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSPlayer::IsVIP(CCSPlayer *this)
{
  return this->m_isVIP;
}

//------------------------------------------------------------------------------
// Address: 0x1027DC60
// Name: public: bool CCSPlayer::HasPrimaryWeapon(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSPlayer::HasPrimaryWeapon(CCSPlayer *this)
{
  return this->Weapon_GetSlot(this, a2: 0) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1027DC80
// Name: public: bool CCSPlayer::HasSecondaryWeapon(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSPlayer::HasSecondaryWeapon(CCSPlayer *this)
{
  return this->Weapon_GetSlot(this, a2: 1) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1027DCA0
// Name: protected: enum BuyResult_e CCSPlayer::AttemptToBuyShield(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSPlayer::AttemptToBuyShield(CCSPlayer *this)
{
  ClientPrint(
    player: this,
    msg_dest: 4u,
    msg_name: "Tactical shield disabled",
    param1: nullptr,
    param2: nullptr,
    param3: nullptr,
    param4: nullptr);
  return 4;
}

//------------------------------------------------------------------------------
// Address: 0x1027DCC0
// Name: protected: void CCSPlayer::InternalAutoBuyAmmo(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::InternalAutoBuyAmmo(CCSPlayer *this, int nSlot)
{
  CBaseCombatWeapon *v3; // eax
  int v4; // eax
  int v5; // ebx
  CCSAmmoDef *AmmoDef; // eax
  CCSPlayer_vtbl *v7; // edi
  CCSAmmoDef *CSAmmoDef; // eax
  int BuySize; // eax
  int v10; // [esp-10h] [ebp-18h]
  int maxAmmo; // [esp+4h] [ebp-4h]

  v3 = this->Weapon_GetSlot(this, a2: nSlot);
  if ( v3 != nullptr )
  {
    v4 = v3->GetPrimaryAmmoType(this: v3);
    v5 = v4;
    if ( v4 != -1 )
    {
      v10 = v4;
      AmmoDef = GetAmmoDef();
      maxAmmo = CAmmoDef::MaxCarry(this: AmmoDef, nAmmoIndex: v10, owner: this);
      if ( CBaseCombatCharacter::GetAmmoCount(this, iAmmoIndex: v5) < maxAmmo )
      {
        LOBYTE(nSlot) = 1;
        do
        {
          v7 = this->CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
          CSAmmoDef = GetCSAmmoDef();
          BuySize = CCSAmmoDef::GetBuySize(this: CSAmmoDef, index: v5);
          v7->GiveAmmo(this, a2: BuySize, a3: v5, a4: nSlot);
          LOBYTE(nSlot) = 0;
        }
        while ( CBaseCombatCharacter::GetAmmoCount(this, iAmmoIndex: v5) < maxAmmo );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027DD50
// Name: enum RadioType NameToRadioEvent(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl NameToRadioEvent(const char *name)
{
  int v1; // esi
  const char **v2; // eax

  v1 = 0;
  if ( RadioEventName[0] == nullptr )
    return 0;
  v2 = RadioEventName;
  while ( _V_stricmp(s1: *v2, s2: name) != 0 )
  {
    v2 = &RadioEventName[++v1];
    if ( *v2 == nullptr )
      return 0;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x1027DDA0
// Name: void UTIL_CSRadioMessage(class IRecipientFilter __near &,int,int,char const __near *,char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UTIL_CSRadioMessage(
        IRecipientFilter *filter,
        unsigned int iClient,
        unsigned int msg_dest,
        const char *msg_name,
        const char *param1,
        const char *param2,
        const char *param3,
        const char *param4)
{
  UserMessageBegin(filter, messagename: "RadioText");
  MessageWriteByte(iValue: msg_dest);
  MessageWriteByte(iValue: iClient);
  MessageWriteString(sz: msg_name);
  if ( param1 != nullptr )
    MessageWriteString(sz: param1);
  else
    MessageWriteString(sz: locale);
  if ( param2 != nullptr )
    MessageWriteString(sz: param2);
  else
    MessageWriteString(sz: locale);
  if ( param3 != nullptr )
    MessageWriteString(sz: param3);
  else
    MessageWriteString(sz: locale);
  if ( param4 != nullptr )
    MessageWriteString(sz: param4);
  else
    MessageWriteString(sz: locale);
  MessageEnd();
}

//------------------------------------------------------------------------------
// Address: 0x1027DE40
// Name: public: void CCSPlayer::NoteWeaponFired(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::NoteWeaponFired(CCSPlayer *this)
{
  CUserCmd *m_pCurrentCommand; // eax

  m_pCurrentCommand = this->m_pCurrentCommand;
  if ( m_pCurrentCommand != nullptr )
    this->m_iLastWeaponFireUsercmd = m_pCurrentCommand->command_number;
}

//------------------------------------------------------------------------------
// Address: 0x1027DE60
// Name: public: virtual bool CCSPlayer::WantsLagCompensationOnEntity(class CBaseEntity const __near *,class CUserCmd const __near *,class CBitVec<2048> const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSPlayer::WantsLagCompensationOnEntity(
        CCSPlayer *this,
        CBaseEntity *entity,
        const CUserCmd *pCmd,
        const CBitVec<2048> *pEntityTransmitBits)
{
  bool result; // al
  CBaseCombatWeapon *ActiveWeapon; // eax
  void *v7; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  result = ((pCmd->buttons & 1) != 0
         || pCmd->command_number - this->m_iLastWeaponFireUsercmd <= 5
         || (pCmd->buttons & 0x800 | 0x80000) != 0
         && (ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this),
             (v7 = __RTDynamicCast(
                     inptr: ActiveWeapon,
                     VfDelta: 0,
                     SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
                     TargetType: &CWeaponCSBase `RTTI Type Descriptor',
                     isReference: 0)) != nullptr)
         && (*(int (__thiscall **)(void *))(*(_DWORD *)v7 + 1520))(a1: v7) == 31)
        && CBasePlayer::WantsLagCompensationOnEntity(
             this,
             a2: COERCE_FLOAT(&savedregs),
             entity,
             pCmd,
             pEntityTransmitBits);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1027DEE0
// Name: protected: bool CCSPlayer::SelectSpawnSpot(char const __near *,class CBaseEntity __near * __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSPlayer::SelectSpawnSpot(CCSPlayer *this, CBaseEntity *pEntClassName, CBaseEntity **pSpot)
{
  CBaseEntity *EntityByClassname; // eax
  CBaseEntity *v5; // eax
  CBaseEntity *v6; // edi
  int savedregs; // [esp+10h] [ebp+0h] BYREF
  CBaseEntity *pFirstSpot; // [esp+18h] [ebp+8h]

  EntityByClassname = CGlobalEntityList::FindEntityByClassname(
                        this: &gEntList,
                        pStartEntity: *pSpot,
                        szName: (const char *)pEntClassName);
  *pSpot = EntityByClassname;
  if ( EntityByClassname == nullptr )
    *pSpot = CGlobalEntityList::FindEntityByClassname(
               this: &gEntList,
               pStartEntity: nullptr,
               szName: (const char *)pEntClassName);
  v5 = *pSpot;
  pFirstSpot = *pSpot;
  while ( 1 )
  {
    if ( v5 != nullptr && g_pGameRules->IsSpawnPointValid(this: g_pGameRules, a2: v5, a3: this) )
    {
      v6 = *pSpot;
      if ( ((*pSpot)->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: *pSpot, a2: (int)&savedregs);
      if ( v6->m_vecAbsOrigin.x != 0.0 || v6->m_vecAbsOrigin.y != 0.0 || v6->m_vecAbsOrigin.z != 0.0 )
        break;
    }
    v5 = CGlobalEntityList::FindEntityByClassname(
           this: &gEntList,
           pStartEntity: *pSpot,
           szName: (const char *)pEntClassName);
    *pSpot = v5;
    if ( v5 == pFirstSpot )
    {
      DevMsg(a1: "CCSPlayer::SelectSpawnSpot: couldn't find valid spawn point.\n");
      return 1;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1027DFB0
// Name: private: void CCSPlayer::State_Enter_PICKINGTEAM(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::State_Enter_PICKINGTEAM(CCSPlayer *this)
{
  this->ShowViewPortPanel(this, a2: "team", a3: true, a4: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1027DFD0
// Name: private: void CCSPlayer::State_Enter_GUNGAME_RESPAWN(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::State_Enter_GUNGAME_RESPAWN(CCSPlayer *this)
{
  if ( !this->m_bRespawning )
  {
    this->m_bRespawning = true;
    CCSPlayer::State_Transition(this, newState: STATE_ACTIVE);
    respawn(pEdict: this, fCopyCorpse: false);
    this->m_nButtons = 0;
    CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027E020
// Name: private: void CCSPlayer::State_PreThink_GUNGAME_RESPAWN(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::State_PreThink_GUNGAME_RESPAWN(CCSPlayer *this)
{
  CCSPlayer::State_Transition(this, newState: STATE_ACTIVE);
}

//------------------------------------------------------------------------------
// Address: 0x1027E030
// Name: public: virtual bool CCSPlayer::Weapon_CanUse(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSPlayer::Weapon_CanUse(CCSPlayer *this, CBaseCombatWeapon *pBaseWeapon)
{
  void *v3; // esi

  v3 = __RTDynamicCast(
         inptr: pBaseWeapon,
         VfDelta: 0,
         SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
         TargetType: &CWeaponCSBase `RTTI Type Descriptor',
         isReference: 0);
  return v3 == nullptr
      || (CCSGameRules::IsPlayingTraining(this: (CCSGameRules *)g_pGameRules)
       || (*(int (__thiscall **)(void *))(*(_DWORD *)v3 + 1520))(a1: v3) != 37
       || CBaseEntity::GetTeamNumber(this) == 2)
      && ((*(int (__thiscall **)(void *))(*(_DWORD *)v3 + 1520))(a1: v3) != 22
       || (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)v3 + 1024))(a1: v3) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x1027E0C0
// Name: timeleft
// Source: json
//------------------------------------------------------------------------------
void __cdecl timeleft()
{
  CBasePlayer *CommandClient; // esi
  CBasePlayer *v1; // eax
  CBasePlayer *v2; // ebx
  int MapRemainingTime; // eax
  int v4; // edi
  int v5; // esi
  char minutes[8]; // [esp+8h] [ebp-10h] BYREF
  char seconds[8]; // [esp+10h] [ebp-8h] BYREF

  CommandClient = UTIL_GetCommandClient();
  if ( CommandClient != nullptr && CommandClient->IsPlayer(this: CommandClient) )
  {
    v1 = (CBasePlayer *)__RTDynamicCast(
                          inptr: CommandClient,
                          VfDelta: 0,
                          SrcType: &CBaseEntity `RTTI Type Descriptor',
                          TargetType: &CCSPlayer `RTTI Type Descriptor',
                          isReference: 0);
    v2 = v1;
    if ( v1 != nullptr && (float)(int)v1[1].m_iName.m_Value.pszValue >= gpGlobals->curtime )
      return;
  }
  else
  {
    v2 = nullptr;
  }
  MapRemainingTime = (int)CCSGameRules::GetMapRemainingTime(this: (CCSGameRules *)g_pGameRules);
  v4 = MapRemainingTime;
  if ( MapRemainingTime >= 0 )
  {
    if ( MapRemainingTime != 0 )
    {
      v5 = MapRemainingTime / 60;
      V_snprintf(pDest: minutes, maxLen: 8, pFormat: "%d", MapRemainingTime / 60);
      V_snprintf(pDest: seconds, maxLen: 8, pFormat: "%2.2d", v4 - 60 * v5);
      if ( v2 == nullptr )
      {
        _Msg(a1: "Time Remaining:  %s:%s\n", minutes, seconds);
        return;
      }
      ClientPrint(
        player: v2,
        msg_dest: 3u,
        msg_name: "#Game_timelimit",
        param1: minutes,
        param2: seconds,
        param3: nullptr,
        param4: nullptr);
    }
    else
    {
      if ( v2 == nullptr )
      {
        _Msg(a1: "* Last Round *\n");
        return;
      }
      ClientPrint(
        player: v2,
        msg_dest: 3u,
        msg_name: "#Game_last_round",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
    }
  }
  else
  {
    if ( v2 == nullptr )
    {
      _Msg(a1: "* No Time Limit *\n");
      return;
    }
    ClientPrint(
      player: v2,
      msg_dest: 3u,
      msg_name: "#Game_no_timelimit",
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  }
  v2[1].m_iName.m_Value.pszValue = (const char *)(int)(float)(gpGlobals->curtime + 1.0);
}

//------------------------------------------------------------------------------
// Address: 0x1027E240
// Name: private: void CCSPlayer::PostAutoBuyCommandProcessing(struct AutoBuyInfoStruct const __near *,bool __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::PostAutoBuyCommandProcessing(
        CCSPlayer *this,
        const AutoBuyInfoStruct *commandInfo,
        bool *boughtPrimary,
        bool *boughtSecondary)
{
  CBaseCombatWeapon *v5; // edi
  CBaseCombatWeapon *v6; // esi
  const char *pszValue; // edi
  const char *v8; // eax

  if ( commandInfo != nullptr )
  {
    v5 = this->Weapon_GetSlot(this, a2: 0);
    v6 = this->Weapon_GetSlot(this, a2: 1);
    if ( v5 == nullptr )
      goto LABEL_7;
    pszValue = v5->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    if ( _V_stricmp(s1: pszValue, s2: commandInfo->m_classname) != 0 )
    {
LABEL_7:
      if ( v6 != nullptr )
      {
        v8 = v6->m_iClassname.pszValue;
        if ( v8 == nullptr )
          v8 = locale;
        if ( _V_stricmp(s1: v8, s2: commandInfo->m_classname) == 0 )
          *boughtSecondary = true;
      }
    }
    else
    {
      *boughtPrimary = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027E2D0
// Name: public: virtual bool CCSPlayer::IsUseableEntity(class CBaseEntity __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSPlayer::IsUseableEntity(CCSPlayer *this, CBaseEntity *pEntity, unsigned int requiredCaps)
{
  if ( __RTDynamicCast(
         inptr: pEntity,
         VfDelta: 0,
         SrcType: &CBaseEntity `RTTI Type Descriptor',
         TargetType: &CWeaponCSBase `RTTI Type Descriptor',
         isReference: 0) != nullptr )
    return true;
  __RTDynamicCast(
    inptr: pEntity,
    VfDelta: 0,
    SrcType: &CBaseEntity `RTTI Type Descriptor',
    TargetType: &CBaseCSGrenadeProjectile `RTTI Type Descriptor',
    isReference: 0);
  return CBasePlayer::IsUseableEntity(this, pEntity, requiredCaps);
}

//------------------------------------------------------------------------------
// Address: 0x1027E330
// Name: public: virtual class CBaseEntity __near * CCSPlayer::FindUseEntity(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__usercall CCSPlayer::FindUseEntity@<eax>(CCSPlayer *this@<ecx>, CBaseEntity *EntityByClassname@<esi>)
{
  __int64 v3; // xmm0_8
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  float *v5; // eax
  const QAngle *v6; // eax
  Vector v8; // [esp+8h] [ebp-24h] BYREF
  Vector forward; // [esp+14h] [ebp-18h] BYREF
  Vector vecLOS; // [esp+20h] [ebp-Ch] BYREF
  int savedregs; // [esp+2Ch] [ebp+0h] BYREF

  if ( !CCSGameRules::IsBombDefuseMap(this: (CCSGameRules *)g_pGameRules) )
    return CBasePlayer::FindUseEntity(this, a2: COERCE_FLOAT(&savedregs), a3: (int)this, a4: (int)EntityByClassname);
  if ( CBaseEntity::GetTeamNumber(this) != 3 )
    return CBasePlayer::FindUseEntity(this, a2: COERCE_FLOAT(&savedregs), a3: (int)this, a4: (int)EntityByClassname);
  EntityByClassname = CGlobalEntityList::FindEntityByClassname(
                        this: &gEntList,
                        pStartEntity: nullptr,
                        szName: "planted_c4");
  if ( EntityByClassname == nullptr )
    return CBasePlayer::FindUseEntity(this, a2: COERCE_FLOAT(&savedregs), a3: (int)this, a4: (int)EntityByClassname);
  if ( (EntityByClassname->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: EntityByClassname, a2: (int)&savedregs);
  v3 = *(_QWORD *)&EntityByClassname->m_vecAbsOrigin.x;
  EyePosition = this->EyePosition;
  forward.z = EntityByClassname->m_vecAbsOrigin.z;
  *(_QWORD *)&forward.x = v3;
  v5 = (float *)EyePosition(this, result: &v8);
  vecLOS.x = *v5 - forward.x;
  vecLOS.y = v5[1] - forward.y;
  vecLOS.z = v5[2] - forward.z;
  if ( (float)((float)((float)(vecLOS.x * vecLOS.x) + (float)(vecLOS.y * vecLOS.y)) + (float)(vecLOS.z * vecLOS.z)) >= 9216.0 )
    return CBasePlayer::FindUseEntity(this, a2: COERCE_FLOAT(&savedregs), a3: (int)this, a4: (int)EntityByClassname);
  v6 = this->EyeAngles(this);
  AngleVectors(angles: v6, &forward, right: nullptr, up: nullptr);
  VectorNormalize(vec: &vecLOS);
  if ( (float)((float)((float)(vecLOS.x * forward.x) + (float)(forward.y * vecLOS.y)) + (float)(forward.z * vecLOS.z)) < -0.7 )
    return EntityByClassname;
  else
    return CBasePlayer::FindUseEntity(this, a2: COERCE_FLOAT(&savedregs), a3: (int)this, a4: (int)EntityByClassname);
}

//------------------------------------------------------------------------------
// Address: 0x1027E480
// Name: private: virtual bool CCSPlayer::FlashlightTurnOn(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSPlayer::FlashlightTurnOn(CCSPlayer *this, bool playSound)
{
  if ( flashlight.m_pParent != nullptr && flashlight.m_pParent->m_Value.m_nValue > 0 && this->IsAlive(this) )
  {
    CBaseEntity::AddEffects(this, nEffects: 4);
    CBaseEntity::EmitSound(this, soundname: "Player.FlashlightOn", soundtime: 0.0, duration: nullptr);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1027E4D0
// Name: public: static void CCSPlayer::StartNewBulletGroup(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CCSPlayer::StartNewBulletGroup()
{
  ++s_BulletGroupCounter;
}

//------------------------------------------------------------------------------
// Address: 0x1027E4E0
// Name: public: static unsigned int CCSPlayer::GetBulletGroup(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl CCSPlayer::GetBulletGroup()
{
  return s_BulletGroupCounter;
}

//------------------------------------------------------------------------------
// Address: 0x1027E4F0
// Name: public: static void CCSPlayer::ResetBulletGroup(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CCSPlayer::ResetBulletGroup()
{
  s_BulletGroupCounter = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1027E500
// Name: public: bool CCSPlayer::HasC4(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCSPlayer::HasC4(CCSPlayer *this)
{
  return this->Weapon_OwnsThisType(this, a2: "weapon_c4", a3: 0) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1027E520
// Name: public: void CCSPlayer::SelectDeathPose(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::SelectDeathPose(CCSPlayer *this, const CTakeDamageInfo *info)
{
  IMDLCache *v2; // edi
  CStudioHdr *m_pStudioHdr; // eax
  int v5; // eax
  int v6; // ecx
  int m_LastHitGroup; // [esp-Ch] [ebp-1Ch]
  int iDeathFrame; // [esp+8h] [ebp-8h] BYREF
  Activity aActivity; // [esp+Ch] [ebp-4h] BYREF

  v2 = mdlcache;
  mdlcache->BeginLock(this: mdlcache);
  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  m_pStudioHdr = this->m_pStudioHdr;
  if ( m_pStudioHdr != nullptr && m_pStudioHdr->m_pStudioHdr != nullptr )
  {
    m_LastHitGroup = this->m_LastHitGroup;
    aActivity = ACT_INVALID;
    iDeathFrame = 0;
    SelectDeathPoseActivityAndFrame(
      entity: this,
      info,
      hitgroup: m_LastHitGroup,
      activity: &aActivity,
      frame: &iDeathFrame);
    if ( aActivity == ACT_INVALID )
    {
      this->m_iDeathPose = -1;
      this->m_iDeathFrame = 0;
    }
    else
    {
      v5 = CBaseAnimating::SelectWeightedSequence(this, activity: aActivity);
      v6 = iDeathFrame;
      this->m_iDeathPose = v5;
      this->m_iDeathFrame = v6;
    }
    v2->EndLock(this: v2);
  }
  else
  {
    v2->EndLock(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027E5F0
// Name: public: void CCSPlayer::HandleEndOfRound(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::HandleEndOfRound(CCSPlayer *this)
{
  float v1; // xmm0_4

  v1 = gpGlobals->curtime - this->m_spawnedTime;
  if ( v1 > this->m_longestLife )
    this->m_longestLife = v1;
}

//------------------------------------------------------------------------------
// Address: 0x1027E620
// Name: public: void CCSPlayer::OnCanceledDefuse(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::OnCanceledDefuse(CCSPlayer *this)
{
  if ( this->m_gooseChaseStep == GC_SHOT_DURING_DEFUSE )
    this->m_gooseChaseStep = GC_STOPPED_AFTER_GETTING_SHOT;
}

//------------------------------------------------------------------------------
// Address: 0x1027E640
// Name: public: void CCSPlayer::OnStartedDefuse(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::OnStartedDefuse(CCSPlayer *this)
{
  bool v1; // zf

  v1 = this->m_defuseDefenseStep == DD_NONE;
  this->m_bAttemptedDefusal = true;
  if ( v1 )
    this->m_defuseDefenseStep = DD_STARTED_DEFUSE;
}

//------------------------------------------------------------------------------
// Address: 0x1027E660
// Name: public: bool CCSPlayer::IsPlayerDominated(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSPlayer::IsPlayerDominated(CCSPlayer *this, int iPlayerIndex)
{
  return this->m_bPlayerDominated.m_Value[iPlayerIndex];
}

//------------------------------------------------------------------------------
// Address: 0x1027E680
// Name: public: void CCSPlayer::SetNumMVPs(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::SetNumMVPs(CCSPlayer *this, int iNumMVP)
{
  this->m_iMVPs = iNumMVP;
}

//------------------------------------------------------------------------------
// Address: 0x1027E690
// Name: public: int CCSPlayer::GetNumMVPs(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSPlayer::GetNumMVPs(CCSPlayer *this)
{
  return this->m_iMVPs;
}

//------------------------------------------------------------------------------
// Address: 0x1027E6A0
// Name: public: void CCSPlayer::CheckMaxGrenadeKills(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::CheckMaxGrenadeKills(CCSPlayer *this, int grenadeKills)
{
  if ( grenadeKills > this->m_maxGrenadeKills )
    this->m_maxGrenadeKills = grenadeKills;
}

//------------------------------------------------------------------------------
// Address: 0x1027E6C0
// Name: public: virtual void CCSPlayer::CommitSuicide(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::CommitSuicide(CCSPlayer *this, bool bExplode, bool bForce)
{
  this->m_wasNotKilledNaturally = true;
  CBasePlayer::CommitSuicide(this, bExplode, bForce);
}

//------------------------------------------------------------------------------
// Address: 0x1027E6D0
// Name: public: virtual void CCSPlayer::CommitSuicide(class Vector const __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::CommitSuicide(CCSPlayer *this, const Vector *vecForce, bool bExplode, bool bForce)
{
  this->m_wasNotKilledNaturally = true;
  CBasePlayer::CommitSuicide(this, vecForce, bExplode, bForce);
}

//------------------------------------------------------------------------------
// Address: 0x1027E6E0
// Name: public: virtual bool CCSPlayer::ShouldCollide(int,int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSPlayer::ShouldCollide(CCSPlayer *this, int collisionGroup, int contentsMask)
{
  unsigned int v4; // eax

  return (collisionGroup != 8
       || (v4 = this->PhysicsSolidMaskForEntity(this) & 0x1800) == 0
       || v4 != (contentsMask & 0x1800))
      && CBaseEntity::ShouldCollide(this, collisionGroup, contentsMask);
}

//------------------------------------------------------------------------------
// Address: 0x1027E730
// Name: public: void CCSPlayer::AddRoundProximityScore(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::AddRoundProximityScore(CCSPlayer *this, int iPoints)
{
  this->m_iRoundProximityScore += iPoints;
}

//------------------------------------------------------------------------------
// Address: 0x1027E740
// Name: public: int CCSPlayer::GetNumConcurrentDominations(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSPlayer::GetNumConcurrentDominations(CCSPlayer *this)
{
  int result; // eax
  int v3; // edi
  CBasePlayer *v4; // eax
  CBasePlayer *v5; // esi
  _DWORD *v6; // eax
  signed int v7; // eax
  int numConcurrentDominations; // [esp+8h] [ebp-4h]

  result = 0;
  v3 = 1;
  numConcurrentDominations = 0;
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
        if ( v6 != nullptr )
        {
          v7 = v6[6];
          if ( v7 != 0 )
            v7 = (signed int)(v7 - (unsigned int)gpGlobals->pEdicts) >> 4;
          if ( this->m_bPlayerDominated.m_Value[v7] )
            ++numConcurrentDominations;
        }
      }
      ++v3;
    }
    while ( v3 <= gpGlobals->maxClients );
    return numConcurrentDominations;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1027E7D0
// Name: public: bool CCSPlayer::HasControlledByPlayer(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCSPlayer::HasControlledByPlayer(CCSPlayer *this)
{
  unsigned int m_Index; // eax

  m_Index = this->m_hControlledByPlayer.m_Index;
  return m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1027E810
// Name: public: bool CCSPlayer::IsReloading(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSPlayer::IsReloading(CCSPlayer *this)
{
  CBaseCombatWeapon *ActiveWeapon; // eax

  ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
  return ActiveWeapon != nullptr && ActiveWeapon->m_bInReload.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x1027E830
// Name: public: class CCSPlayer __near * CWeaponCSBase::GetDonor(void)
// Source: json
//------------------------------------------------------------------------------
CCSPlayer *__thiscall CWeaponCSBase::GetDonor(CWeaponCSBase *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_donor.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CCSPlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x1027E860
// Name: SvNoMVPChangeCallback
// Source: json
//------------------------------------------------------------------------------
void __cdecl SvNoMVPChangeCallback(IConVar *pConVar)
{
  int i; // edi
  CBasePlayer *v2; // eax
  CBasePlayer *v3; // esi
  _DWORD *v4; // eax
  ConVarRef var; // [esp+0h] [ebp-8h] BYREF

  ConVarRef::ConVarRef(this: &var, pConVar);
  if ( ConVarRef::IsValid(this: &var) && var.m_pConVarState->m_Value.m_nValue != 0 )
  {
    for ( i = 1; i <= 64; ++i )
    {
      v2 = UTIL_PlayerByIndex(playerIndex: i);
      v3 = v2;
      if ( v2 != nullptr && v2->IsPlayer(this: v2) )
      {
        v4 = __RTDynamicCast(
               inptr: v3,
               VfDelta: 0,
               SrcType: &CBaseEntity `RTTI Type Descriptor',
               TargetType: &CCSPlayer `RTTI Type Descriptor',
               isReference: 0);
        if ( v4 != nullptr )
          v4[1718] = 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027E8E0
// Name: public: virtual int CPhysicsPlayerCallback::ShouldMoveTo(class IPhysicsObject __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CPhysicsPlayerCallback::ShouldMoveTo(
        CPhysicsPlayerCallback *this,
        IPhysicsObject *pObject,
        const Vector *position)
{
  _BYTE *v3; // eax

  v3 = pObject->GetGameData(this: pObject);
  return v3 == nullptr || v3[3292] == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1027F340
// Name: protected: bool CCSPlayer::RunMimicCommand(class CUserCmd __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSPlayer::RunMimicCommand(CCSPlayer *this, CUserCmd *cmd)
{
  int v4; // eax
  signed int v5; // eax
  CBasePlayer *v6; // eax
  const CUserCmd *p_m_LastCmd; // eax

  if ( !this->IsBot(this) )
    return 0;
  v4 = bot_mimic.m_pParent != nullptr ? bot_mimic.m_pParent->m_Value.m_nValue : 0;
  v5 = abs32(v4);
  if ( v5 > gpGlobals->maxClients )
    return 0;
  v6 = UTIL_PlayerByIndex(playerIndex: v5);
  if ( v6 == nullptr )
    return 0;
  p_m_LastCmd = &v6->m_LastCmd;
  if ( p_m_LastCmd == nullptr )
    return 0;
  CUserCmd::operator=(this: cmd, src: p_m_LastCmd);
  cmd->viewangles.y = bot_mimic_yaw_offset.m_pParent->m_Value.m_fValue + cmd->viewangles.y;
  this->pl.fixangle = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1027F3D0
// Name: protected: void CCSPlayer::GiveCurrentProgressiveGunGameWeapon(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::GiveCurrentProgressiveGunGameWeapon(CCSPlayer *this)
{
  CCSGameRules *v1; // edi
  int TeamNumber; // eax
  CSWeaponID CurrentGunGameWeapon; // edi
  CBaseCombatWeapon *v5; // eax
  CBaseCombatWeapon *v6; // eax
  const char *v7; // eax

  v1 = (CCSGameRules *)g_pGameRules;
  TeamNumber = CBaseEntity::GetTeamNumber(this);
  CurrentGunGameWeapon = CCSGameRules::GetCurrentGunGameWeapon(
                           this: v1,
                           nCurrentWeaponIndex: this->m_iGunGameProgressiveWeaponIndex.m_Value,
                           nTeamID: TeamNumber);
  if ( CurrentGunGameWeapon != -1 )
  {
    v5 = this->Weapon_GetSlot(this, a2: 1);
    if ( v5 != nullptr )
      CBaseCombatWeapon::DestroyItem(this: v5);
    v6 = this->Weapon_GetSlot(this, a2: 0);
    if ( v6 != nullptr )
      CBaseCombatWeapon::DestroyItem(this: v6);
    v7 = WeaponIdAsString(weaponID: CurrentGunGameWeapon);
    if ( v7 != nullptr )
      this->GiveNamedItem(this, a2: v7, a3: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027F450
// Name: public: virtual void CCSPlayer::InitVCollision(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::InitVCollision(CCSPlayer *this, const Vector *vecAbsOrigin, const Vector *vecAbsVelocity)
{
  CBasePlayer::InitVCollision(this, vecAbsOrigin, vecAbsVelocity);
  if ( sv_turbophysics.m_pParent == nullptr || sv_turbophysics.m_pParent->m_Value.m_nValue == 0 )
    this->m_pPhysicsController->SetEventHandler(this: this->m_pPhysicsController, a2: &playerCallback);
}

//------------------------------------------------------------------------------
// Address: 0x1027F490
// Name: public: bool CCSPlayer::HasWeaponOfType(int)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSPlayer::HasWeaponOfType(CCSPlayer *this, int nWeaponID)
{
  int v3; // esi
  CBaseCombatWeapon *Weapon; // eax
  void *v5; // eax

  v3 = 0;
  while ( 1 )
  {
    Weapon = CBaseCombatCharacter::GetWeapon(this, i: v3);
    v5 = __RTDynamicCast(
           inptr: Weapon,
           VfDelta: 0,
           SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
           TargetType: &CWeaponCSBase `RTTI Type Descriptor',
           isReference: 0);
    if ( v5 != nullptr && (*(int (__thiscall **)(void *))(*(_DWORD *)v5 + 1520))(a1: v5) == nWeaponID )
      break;
    if ( ++v3 >= 64 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1027F4F0
// Name: public: void CCSPlayer::Pain(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::Pain(CCSPlayer *this, bool bHasArmour)
{
  if ( this->m_LastHitGroup == 1 )
  {
    if ( this->m_bHasHelmet.m_Value )
      CBaseEntity::EmitSound(this, soundname: "Player.DamageHelmet", soundtime: 0.0, duration: nullptr);
    else
      CBaseEntity::EmitSound(this, soundname: "Player.DamageHeadShot", soundtime: 0.0, duration: nullptr);
  }
  else if ( bHasArmour )
  {
    CBaseEntity::EmitSound(this, soundname: "Player.DamageKevlar", soundtime: 0.0, duration: nullptr);
  }
  else
  {
    CBaseEntity::EmitSound(this, soundname: "Flesh.BulletImpact", soundtime: 0.0, duration: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027F550
// Name: public: bool CCSPlayer::HasDefuser(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSPlayer::HasDefuser(CCSPlayer *this)
{
  return this->m_bHasDefuser.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x1027F560
// Name: public: void CCSPlayer::Deafen(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::Deafen(CCSPlayer *this, float flDistance)
{
  int v3; // edi
  CSingleUserRecipientFilter user; // [esp+4h] [ebp-20h] BYREF

  if ( this->GetObserverMode(this) == 0 || this->GetObserverMode(this) == 4 )
  {
    if ( flDistance >= 100.0 )
    {
      if ( flDistance >= 500.0 )
      {
        if ( flDistance >= 1000.0 )
          return;
        v3 = 136;
      }
      else
      {
        v3 = 135;
      }
    }
    else
    {
      v3 = 134;
    }
    CRecipientFilter::CRecipientFilter(this: &user);
    user.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
    CRecipientFilter::AddRecipient(this: &user, player: this);
    enginesound->SetPlayerDSP(this: enginesound, a2: &user, a3: v3, a4: false);
    CRecipientFilter::~CRecipientFilter(this: &user);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027F610
// Name: public: bool CCSPlayer::IsInBuyZone(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCSPlayer::IsInBuyZone(CCSPlayer *this)
{
  return this->m_bInBuyZone.m_Value && !this->m_isVIP;
}

//------------------------------------------------------------------------------
// Address: 0x1027F630
// Name: public: bool CCSPlayer::CanPlayerBuy(bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSPlayer::CanPlayerBuy(CCSPlayer *this, bool display)
{
  CGameRules *v4; // ebx
  int m_nValue; // edi
  char strBuyTime[16]; // [esp+4h] [ebp-10h] BYREF

  if ( !this->m_bInBuyZone.m_Value || this->m_isVIP )
    return false;
  v4 = g_pGameRules;
  if ( this->m_lifeState.m_Value != 0 )
    return false;
  if ( mp_buytime.m_pParent != nullptr )
    m_nValue = mp_buytime.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  if ( !CCSGameRules::IsBuyTimeElapsed(this: (CCSGameRules *)g_pGameRules) )
  {
    if ( this->m_bIsVIP )
    {
      if ( display )
      {
        ClientPrint(
          player: this,
          msg_dest: 4u,
          msg_name: "#VIP_cant_buy",
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
        return false;
      }
    }
    else if ( BYTE1(v4[136].m_pNext) != 0 && CBaseEntity::GetTeamNumber(this) == 3 )
    {
      if ( display )
      {
        ClientPrint(
          player: this,
          msg_dest: 4u,
          msg_name: "#CT_cant_buy",
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
        return false;
      }
    }
    else
    {
      if ( LOBYTE(v4[136].m_pNext) == 0 || CBaseEntity::GetTeamNumber(this) != 2 )
        return !this->m_bIsControllingBot.m_Value;
      if ( display )
        ClientPrint(
          player: this,
          msg_dest: 4u,
          msg_name: "#Terrorist_cant_buy",
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
    }
    return false;
  }
  if ( display )
  {
    V_snprintf(pDest: strBuyTime, maxLen: 16, pFormat: "%d", m_nValue);
    ClientPrint(
      player: this,
      msg_dest: 4u,
      msg_name: "#Cant_buy",
      param1: strBuyTime,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1027F790
// Name: public: void CCSPlayer::AutoBuyAmmo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::AutoBuyAmmo(CCSPlayer *this)
{
  CGameRules *v2; // edi
  double curtime; // st7
  float v4; // [esp+4h] [ebp-4h]

  if ( sv_autobuyammo.m_pParent != nullptr
    && sv_autobuyammo.m_pParent->m_Value.m_nValue != 0
    && gpGlobals->curtime > this->m_flNextAutoBuyAmmoTime
    && this->m_bInBuyZone.m_Value
    && !this->m_isVIP )
  {
    v2 = g_pGameRules;
    if ( this->m_lifeState.m_Value == 0
      && !CCSGameRules::IsBuyTimeElapsed(this: (CCSGameRules *)g_pGameRules)
      && !this->m_bIsVIP
      && (BYTE1(v2[136].m_pNext) == 0 || CBaseEntity::GetTeamNumber(this) != 3)
      && (LOBYTE(v2[136].m_pNext) == 0 || CBaseEntity::GetTeamNumber(this) != 2)
      && !this->m_bIsControllingBot.m_Value )
    {
      curtime = gpGlobals->curtime;
      v4 = curtime + 0.5;
      this->m_flNextAutoBuyAmmoTime = v4 - fmod(curtime - this->m_flNextAutoBuyAmmoTime, 0.5);
      CCSPlayer::InternalAutoBuyAmmo(this, nSlot: 1);
      CCSPlayer::InternalAutoBuyAmmo(this, nSlot: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027F880
// Name: public: void CCSPlayer::ConstructRadioFilter(class CRecipientFilter __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::ConstructRadioFilter(CCSPlayer *this, CFmtStrN<1024> *filter)
{
  int i; // edi
  CBaseEntity *v5; // eax
  CBasePlayer *v6; // esi
  int m_Value; // eax
  bool v8; // zf
  int localTeam; // [esp+14h] [ebp+8h]

  CRecipientFilter::MakeReliable(this: filter);
  localTeam = CBaseEntity::GetTeamNumber(this);
  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v5 = UTIL_PlayerByIndex(playerIndex: i);
    v6 = (CBasePlayer *)v5;
    if ( v5 != nullptr && !v5[5].m_OnUser1.m_Value.bVal )
    {
      if ( CBaseEntity::GetTeamNumber(this: v5) == 1 )
      {
        m_Value = v6->m_iObserverMode.m_Value;
        if ( m_Value == 4 )
          goto LABEL_9;
        v8 = m_Value == 5;
      }
      else
      {
        v8 = CBaseEntity::GetTeamNumber(this: v6) == localTeam;
      }
      if ( v8 )
LABEL_9:
        CRecipientFilter::AddRecipient(this: (CRecipientFilter *)filter, player: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027F910
// Name: public: virtual void CCSPlayer::OnDamagedByExplosion(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::OnDamagedByExplosion(CCSPlayer *this, const CTakeDamageInfo *info)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx
  int savedregs; // [esp+0h] [ebp+0h] BYREF
  float lastDamage; // [esp+8h] [ebp+8h]

  lastDamage = info->m_flDamage;
  if ( LOBYTE(g_pGameRules[144].__vftable) != 1 )
  {
    m_Index = info->m_hInflictor.m_Index;
    if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    {
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      if ( m_pEntity != nullptr )
      {
        if ( (m_pEntity->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: m_pEntity, a2: (int)&savedregs);
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      }
    }
    if ( lastDamage >= 30.0 )
      *(_QWORD *)&this->m_applyDeafnessTime = COERCE_UNSIGNED_INT(gpGlobals->curtime + 0.3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027F9D0
// Name: public: void CCSPlayer::ApplyDeafnessEffect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::ApplyDeafnessEffect(CCSPlayer *this)
{
  float v2; // xmm0_4
  int v3; // ecx
  int v4; // eax
  CSingleUserRecipientFilter user; // [esp+0h] [ebp-20h] BYREF

  v2 = gpGlobals->curtime - this->m_applyDeafnessTime;
  if ( v2 < 4.5 )
  {
    if ( v2 >= 0.1 )
    {
      v3 = 1;
      if ( v2 >= 3.0 )
        v3 = 2;
    }
    else
    {
      v3 = 0;
    }
    if ( v3 != 0 )
    {
      if ( v3 == 1 )
        v4 = 139;
      else
        v4 = 138 - (int)(float)((float)(v2 - 3.0) * 1.3333334);
    }
    else
    {
      v4 = 137 - (int)(float)(v2 * -20.0);
    }
    if ( v4 != this->m_currentDeafnessFilter )
    {
      this->m_currentDeafnessFilter = v4;
      CRecipientFilter::CRecipientFilter(this: &user);
      user.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
      CRecipientFilter::AddRecipient(this: &user, player: this);
      enginesound->SetPlayerDSP(this: enginesound, a2: &user, a3: this->m_currentDeafnessFilter, a4: false);
      CRecipientFilter::~CRecipientFilter(this: &user);
    }
  }
  else
  {
    *(_QWORD *)&this->m_applyDeafnessTime = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027FAD0
// Name: public: int CCSPlayer::PlayerClass(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSPlayer::PlayerClass(CCSPlayer *this)
{
  return this->m_iClass.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x1027FAE0
// Name: public: virtual class CBaseEntity __near * CCSPlayer::EntSelectSpawnPoint(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CCSPlayer::EntSelectSpawnPoint(CCSPlayer *this)
{
  CBaseEntity *EntityByTarget; // esi
  CBaseEntity *m_pEntity; // eax
  CBaseEntity *v4; // eax
  const char *pszValue; // eax
  const char *v6; // eax
  edict_t *pEdicts; // esi
  edict_t *v9; // eax
  IServerUnknown *m_pUnk; // ecx
  CBaseEntity *pSpot; // [esp+4h] [ebp-4h] BYREF

  pSpot = nullptr;
  if ( CCSGameRules::IsLogoMap(this: (CCSGameRules *)g_pGameRules) )
  {
    CCSPlayer::SelectSpawnSpot(this, pEntClassName: (CBaseEntity *)"info_player_logo", &pSpot);
    CBasePlayer::LockPlayerInPlace(this);
    EntityByTarget = pSpot;
    goto ReturnSpot_0;
  }
  if ( CBaseEntity::GetTeamNumber(this) == 3 )
  {
    if ( g_pLastCTSpawn.m_Index == -1
      || g_pEntityList->m_EntPtrArray[LOWORD(g_pLastCTSpawn.m_Index)].m_SerialNumber != HIWORD(g_pLastCTSpawn.m_Index) )
    {
      m_pEntity = nullptr;
    }
    else
    {
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[LOWORD(g_pLastCTSpawn.m_Index)].m_pEntity;
    }
    pSpot = m_pEntity;
    if ( CCSPlayer::SelectSpawnSpot(this, pEntClassName: (CBaseEntity *)"info_player_counterterrorist", &pSpot) != 0 )
    {
      EntityByTarget = pSpot;
      if ( pSpot == nullptr )
      {
        g_pLastCTSpawn.m_Index = -1;
        goto LABEL_29;
      }
      g_pLastCTSpawn.m_Index = pSpot->GetRefEHandle(this: pSpot)->m_Index;
      goto ReturnSpot_0;
    }
  }
  else if ( CBaseEntity::GetTeamNumber(this) == 2 )
  {
    v4 = g_pLastTerroristSpawn.m_Index == -1
      || g_pEntityList->m_EntPtrArray[LOWORD(g_pLastTerroristSpawn.m_Index)].m_SerialNumber != HIWORD(g_pLastTerroristSpawn.m_Index)
       ? nullptr
       : (CBaseEntity *)g_pEntityList->m_EntPtrArray[LOWORD(g_pLastTerroristSpawn.m_Index)].m_pEntity;
    pSpot = v4;
    if ( CCSPlayer::SelectSpawnSpot(this, pEntClassName: (CBaseEntity *)"info_player_terrorist", &pSpot) != 0 )
    {
      EntityByTarget = pSpot;
      CHandle<CBaseEntity>::operator=(this: &g_pLastTerroristSpawn, val: pSpot);
      goto ReturnSpot_0;
    }
  }
  if ( gpGlobals->startspot.pszValue != nullptr )
  {
    pszValue = gpGlobals->startspot.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    if ( strlen(pszValue) != 0 )
    {
      v6 = gpGlobals->startspot.pszValue;
      if ( v6 == nullptr )
        v6 = locale;
      EntityByTarget = CGlobalEntityList::FindEntityByTarget(this: &gEntList, pStartEntity: nullptr, szName: v6);
      if ( EntityByTarget == nullptr )
        goto LABEL_29;
      return EntityByTarget;
    }
  }
  EntityByTarget = CGlobalEntityList::FindEntityByClassname(
                     this: &gEntList,
                     pStartEntity: nullptr,
                     szName: "info_player_terrorist");
ReturnSpot_0:
  if ( EntityByTarget != nullptr )
    return EntityByTarget;
LABEL_29:
  if ( CCSGameRules::IsLogoMap(this: (CCSGameRules *)g_pGameRules) )
    _Warning(a1: "PutClientInServer: no info_player_logo on level\n");
  else
    _Warning(a1: "PutClientInServer: no info_player_start on level\n");
  pEdicts = gpGlobals->pEdicts;
  if ( pEdicts != nullptr )
    v9 = (pEdicts->m_fStateFlags & 2) == 0 ? pEdicts : nullptr;
  else
    v9 = nullptr;
  if ( (v9 != nullptr || pEdicts != nullptr && (v9 = gpGlobals->pEdicts, (pEdicts->m_fStateFlags & 2) == 0))
    && (m_pUnk = v9->m_pUnk) != nullptr )
  {
    return m_pUnk->GetBaseEntity(this: m_pUnk);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027FCE0
// Name: private: void CCSPlayer::State_Enter_WELCOME(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::State_Enter_WELCOME(CCSPlayer *this)
{
  IPhysicsObject *m_pPhysicsObject; // ecx
  CResponseRulesToEngineInterface *v3; // ecx
  ICommandLine *v4; // eax
  int v5; // eax
  edict_t *m_pPev; // edx
  IVEngineServer_vtbl *v7; // ecx

  this->StartObserverMode(this, a2: 6);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
    m_pPhysicsObject->Sleep(this: m_pPhysicsObject);
  cvar->FindVar_2(this: cvar, a2: "hostname");
  if ( !CCSGameRules::IsLogoMap(this: (CCSGameRules *)g_pGameRules) )
  {
    v4 = _CommandLine(this: v3);
    v5 = v4->FindParm(this: v4, a2: "-makereslists");
    m_pPev = this->m_Network.m_pPev;
    v7 = engine->__vftable;
    if ( v5 != 0 )
      v7->ClientCommand(this: engine, a2: m_pPev, a3: "jointeam 3\n");
    else
      v7->ClientCommand(this: engine, a2: m_pPev, a3: "joingame\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027FD90
// Name: private: void CCSPlayer::State_PreThink_DEATH_ANIM(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CCSPlayer::State_PreThink_DEATH_ANIM(CCSPlayer *this@<ecx>, int a2@<ebp>)
{
  __int128 v3; // xmm0
  float z; // edx
  float v5; // xmm0_4
  __int128 v6; // [esp-10h] [ebp-2Ch] BYREF
  float v7; // [esp+Ch] [ebp-10h]
  _DWORD v8[2]; // [esp+10h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+1Ch] [ebp+0h]

  v8[0] = a2;
  v8[1] = retaddr;
  if ( (this->m_fFlags.m_Value & 1) != 0 )
  {
    if ( (this->m_iEFlags & 0x1000) != 0 )
      CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)v8);
    v3 = 0;
    *(float *)&v3 = fsqrt(
                      (float)((float)(this->m_vecAbsVelocity.x * this->m_vecAbsVelocity.x)
                            + (float)(this->m_vecAbsVelocity.y * this->m_vecAbsVelocity.y))
                    + (float)(this->m_vecAbsVelocity.z * this->m_vecAbsVelocity.z));
    v6 = v3;
    v7 = *(float *)&v3 - 20.0;
    if ( (float)(*(float *)&v3 - 20.0) > 0.0 )
    {
      if ( (this->m_iEFlags & 0x1000) != 0 )
        CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)v8);
      z = this->m_vecAbsVelocity.z;
      *(_QWORD *)((char *)&v6 + 4) = *(_QWORD *)&this->m_vecAbsVelocity.x;
      *((float *)&v6 + 3) = z;
      VectorNormalize(vec: (Vector *)((char *)&v6 + 4));
      *((float *)&v6 + 1) = *((float *)&v6 + 1) * v7;
      *((float *)&v6 + 2) = *((float *)&v6 + 2) * v7;
      *((float *)&v6 + 3) = *((float *)&v6 + 3) * v7;
      CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: (const Vector *)((char *)&v6 + 4));
    }
    else
    {
      CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
    }
  }
  v5 = this->m_flDeathTime.m_Value + 0.8;
  v7 = (float)(spec_freeze_traveltime.m_pParent->m_Value.m_fValue + v5) + spec_freeze_time.m_pParent->m_Value.m_fValue;
  if ( gpGlobals->curtime >= v5 )
  {
    if ( this->GetObserverTarget(this) == nullptr
      || this->GetObserverTarget(this) == this
      || this->m_bAbortFreezeCam
      || v7 <= gpGlobals->curtime
      || this->GetObserverMode(this) == 2 )
    {
      if ( this->GetObserverMode(this) == 2
        && this->m_bAbortFreezeCam
        && (mp_fadetoblack.m_pParent == nullptr || mp_fadetoblack.m_pParent->m_Value.m_nValue == 0) )
      {
        if ( CCSGameRules::IsPlayingGunGameProgressive(this: (CCSGameRules *)g_pGameRules) )
          CCSPlayer::State_Transition(this, newState: STATE_GUNGAME_RESPAWN);
        else
          CCSPlayer::State_Transition(this, newState: STATE_OBSERVER_MODE);
      }
    }
    else
    {
      this->StartObserverMode(this, a2: 2);
    }
  }
  if ( v7 <= gpGlobals->curtime )
  {
    if ( CCSGameRules::IsPlayingGunGameProgressive(this: (CCSGameRules *)g_pGameRules) )
      CCSPlayer::State_Transition(this, newState: STATE_GUNGAME_RESPAWN);
    else
      CCSPlayer::State_Transition(this, newState: STATE_OBSERVER_MODE);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027FFD0
// Name: private: void CCSPlayer::State_PreThink_DEATH_WAIT_FOR_KEY(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::State_PreThink_DEATH_WAIT_FOR_KEY(CCSPlayer *this)
{
  bool v2; // cl
  edict_t *m_pPev; // eax

  if ( this->m_MoveType.m_Value != 0 && (this->m_fFlags.m_Value & 1) != 0 )
    CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  v2 = (this->m_nButtons & 0xFFFEFFFF) != 0;
  if ( mp_fadetoblack.m_pParent != nullptr && mp_fadetoblack.m_pParent->m_Value.m_nValue != 0 )
    v2 = false;
  if ( gpGlobals->curtime >= (float)((float)(this->m_flDeathTime.m_Value + 3.0) + 3.0) || v2 )
  {
    if ( CCSGameRules::IsPlayingGunGameProgressive(this: (CCSGameRules *)g_pGameRules) )
    {
      CCSPlayer::State_Transition(this, newState: STATE_GUNGAME_RESPAWN);
    }
    else
    {
      if ( this->GetObserverTarget(this) != nullptr )
      {
        m_pPev = this->GetObserverTarget(this)->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          m_pPev -= (int)gpGlobals->pEdicts;
        ((void (__thiscall *)(CCSPlayer *, int, int, edict_t *))this->StartReplayMode)(
          a1: this,
          a2: 1090519040,
          a3: 1090519040,
          a4: m_pPev);
      }
      CCSPlayer::State_Transition(this, newState: STATE_OBSERVER_MODE);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102800B0
// Name: private: void CCSPlayer::State_Enter_OBSERVER_MODE(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::State_Enter_OBSERVER_MODE(CCSPlayer *this)
{
  int m_iObserverLastMode; // edi
  edict_t *m_pPev; // eax
  const char *v4; // eax
  int v5; // eax
  IPhysicsObject *m_pPhysicsObject; // ecx
  color32_s clr; // [esp+14h] [ebp-4h] BYREF

  if ( mp_fadetoblack.m_pParent != nullptr
    && mp_fadetoblack.m_pParent->m_Value.m_nValue != 0
    && (mp_forcecamera.m_pParent == nullptr || mp_forcecamera.m_pParent->m_Value.m_nValue != 2) )
  {
    clr = (color32_s)-16777216;
    UTIL_ScreenFade(pEntity: this, color: &clr, fadeTime: 0.0, fadeHold: 0.0, flags: 17);
  }
  m_iObserverLastMode = this->m_iObserverLastMode;
  if ( this->IsNetClient(this) )
  {
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      m_pPev -= (int)gpGlobals->pEdicts;
    v4 = engine->GetClientConVarValue(this: engine, a2: m_pPev, a3: "cl_spec_mode");
    if ( v4 != nullptr )
    {
      v5 = atoi(nptr: v4);
      if ( v5 >= 5 )
      {
        if ( v5 > 6 )
          v5 = 6;
      }
      else
      {
        v5 = 5;
      }
      m_iObserverLastMode = v5;
    }
  }
  this->StartObserverMode(this, a2: m_iObserverLastMode);
  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
    m_pPhysicsObject->Sleep(this: m_pPhysicsObject);
}

//------------------------------------------------------------------------------
// Address: 0x10280190
// Name: public: void CCSPlayer::EmitPrivateSound(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::EmitPrivateSound(CCSPlayer *this, const char *soundName)
{
  edict_t *m_pPev; // eax
  signed int v4; // eax
  CSoundParameters params; // [esp+14h] [ebp-D4h] BYREF
  CSingleUserRecipientFilter filter; // [esp+C8h] [ebp-20h] BYREF

  params.pitch = 100;
  params.pitchlow = 100;
  params.pitchhigh = 100;
  params.channel = 0;
  params.volume = 1.0;
  params.soundlevel = SNDLVL_NORM;
  params.soundname[0] = 0;
  params.play_to_owner_only = false;
  params.count = 0;
  params.delay_msec = 0;
  params.m_nSoundEntryVersion = 1;
  params.m_hSoundScriptHandle = -1;
  params.m_pOperatorsKV = nullptr;
  params.m_nRandomSeed = -1;
  if ( CBaseEntity::GetParametersForSound(soundname: soundName, &params, actormodel: nullptr) )
  {
    CRecipientFilter::CRecipientFilter(this: &filter);
    filter.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
    CRecipientFilter::AddRecipient(this: &filter, player: this);
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      v4 = m_pPev - gpGlobals->pEdicts;
    else
      v4 = 0;
    CBaseEntity::EmitSound(
      &filter,
      iEntIndex: v4,
      soundname: soundName,
      pOrigin: nullptr,
      soundtime: 0.0,
      duration: nullptr);
    CRecipientFilter::~CRecipientFilter(this: &filter);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10280280
// Name: public: bool CCSPlayer::CanUseGrenade(enum CSWeaponID)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSPlayer::CanUseGrenade(CCSPlayer *this, CSWeaponID nID)
{
  return nID != WEAPON_MOLOTOV || this->m_fMolotovUseTime.m_Value <= gpGlobals->curtime;
}

//------------------------------------------------------------------------------
// Address: 0x102802B0
// Name: private: virtual int CCSPlayer::FlashlightIsOn(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCSPlayer::FlashlightIsOn(CCSPlayer *this)
{
  return (this->m_fEffects.m_Value & 4) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x102802C0
// Name: public: virtual void CCSPlayer::HandleAnimEvent(struct animevent_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::HandleAnimEvent(CCSPlayer *this, animevent_t *pEvent)
{
  int event_lowword; // edx
  int v3; // edx

  if ( (pEvent->type & 0x400) != 0 )
    event_lowword = pEvent->_event_lowword;
  else
    event_lowword = *(_DWORD *)&pEvent->_event_highword;
  if ( event_lowword != 4001 )
  {
    if ( (pEvent->type & 0x400) != 0 )
      v3 = pEvent->_event_lowword;
    else
      v3 = *(_DWORD *)&pEvent->_event_highword;
    if ( v3 != 4002 )
      CBasePlayer::HandleAnimEvent(this, pEvent);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10280310
// Name: public: virtual bool CCSPlayer::StartReplayMode(float,float,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSPlayer::StartReplayMode(CCSPlayer *this, float fDelay, float fDuration, int iEntity)
{
  char result; // al
  unsigned int m_Index; // ecx
  int v7; // eax
  CEntInfo *v8; // edx
  unsigned int v9; // ecx
  int v10; // eax
  bool v11; // zf
  CEntInfo *v12; // eax
  IHandleEntity *m_pEntity; // eax
  unsigned int v14; // eax
  edict_t *m_pPev; // eax
  edict_t *v16; // eax
  CSingleUserRecipientFilter filter; // [esp+10h] [ebp-20h] BYREF

  result = CBasePlayer::StartReplayMode(this, fDelay, fDuration, iEntity);
  if ( result != 0 )
  {
    CRecipientFilter::CRecipientFilter(this: &filter);
    filter.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
    CRecipientFilter::AddRecipient(this: &filter, player: this);
    CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&filter);
    UserMessageBegin(&filter, messagename: "KillCam");
    MessageWriteByte(iValue: 4u);
    m_Index = this->m_hObserverTarget.m_Value.m_Index;
    if ( m_Index != -1
      && (v7 = (unsigned __int16)m_Index,
          v8 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
          v9 = HIWORD(m_Index),
          v8->m_SerialNumber == v9)
      && v8->m_pEntity != nullptr )
    {
      v10 = v7;
      v11 = g_pEntityList->m_EntPtrArray[v10].m_SerialNumber == v9;
      v12 = &g_pEntityList->m_EntPtrArray[v10];
      if ( v11 )
        m_pEntity = v12->m_pEntity;
      else
        m_pEntity = nullptr;
      v14 = (unsigned int)m_pEntity[6].__vftable;
      if ( v14 != 0 )
        v14 = (int)(v14 - (unsigned int)gpGlobals->pEdicts) >> 4;
      MessageWriteByte(iValue: v14);
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        MessageWriteByte(iValue: m_pPev - gpGlobals->pEdicts);
      else
        MessageWriteByte(iValue: 0);
    }
    else
    {
      v16 = this->m_Network.m_pPev;
      if ( v16 != nullptr )
        v16 -= (int)gpGlobals->pEdicts;
      MessageWriteByte(iValue: (unsigned int)v16);
      MessageWriteByte(iValue: 0);
    }
    MessageEnd();
    ClientPrint(
      player: this,
      msg_dest: 4u,
      msg_name: "Kill Cam Replay",
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
    CRecipientFilter::~CRecipientFilter(this: &filter);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10280460
// Name: public: virtual void CCSPlayer::StopReplayMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::StopReplayMode(CCSPlayer *this)
{
  CSingleUserRecipientFilter filter; // [esp+4h] [ebp-20h] BYREF

  CBasePlayer::StopReplayMode(this);
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
  CRecipientFilter::AddRecipient(this: &filter, player: this);
  CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&filter);
  UserMessageBegin(&filter, messagename: "KillCam");
  MessageWriteByte(iValue: 0);
  MessageWriteByte(iValue: 0);
  MessageWriteByte(iValue: 0);
  MessageEnd();
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x102804D0
// Name: public: static enum CSWeaponID CCSPlayer::GetWeaponIdCausingDamange(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
CSWeaponID __cdecl CCSPlayer::GetWeaponIdCausingDamange(const CTakeDamageInfo *info)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // edi
  unsigned int v3; // eax
  CEntInfo *v4; // ecx
  IHandleEntity *v5; // esi
  CBaseCombatCharacter *v6; // eax
  CBaseCombatWeapon *ActiveWeapon; // eax
  void *v8; // eax
  const char *v10; // eax

  m_Index = info->m_hInflictor.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v3 = info->m_hAttacker.m_Index;
  if ( v3 != -1
    && (v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v3],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_SerialNumber == HIWORD(v3))
    && (v5 = v4->m_pEntity, v4->m_pEntity != nullptr)
    && ((unsigned __int8 (__thiscall *)(IHandleEntity *))v5->__vftable[28].dtr_IHandleEntity)(a1: v4->m_pEntity) != 0 )
  {
    v6 = (CBaseCombatCharacter *)__RTDynamicCast(
                                   inptr: v5,
                                   VfDelta: 0,
                                   SrcType: &CBaseEntity `RTTI Type Descriptor',
                                   TargetType: &CCSPlayer `RTTI Type Descriptor',
                                   isReference: 0);
  }
  else
  {
    v6 = nullptr;
  }
  if ( v6 == m_pEntity )
  {
    ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: v6);
    v8 = __RTDynamicCast(
           inptr: ActiveWeapon,
           VfDelta: 0,
           SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
           TargetType: &CWeaponCSBase `RTTI Type Descriptor',
           isReference: 0);
    if ( v8 != nullptr )
      return (*(CSWeaponID (__thiscall **)(void *))(*(_DWORD *)v8 + 1520))(a1: v8);
  }
  else if ( m_pEntity != nullptr )
  {
    v10 = (const char *)m_pEntity[23].__vftable;
    if ( v10 == nullptr )
      v10 = locale;
    if ( _V_strcmp(s1: v10, s2: "hegrenade_projectile") == 0 )
      return WEAPON_HEGRENADE;
  }
  return WEAPON_NONE;
}

//------------------------------------------------------------------------------
// Address: 0x102805C0
// Name: public: int CCSPlayer::GetNumPlayersDamagedWithFire(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSPlayer::GetNumPlayersDamagedWithFire(CCSPlayer *this)
{
  return this->m_BurnDamageDeltVec.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x102805D0
// Name: public: class CBaseEntity __near * CCSPlayer::GetNearestSurfaceBelow(float)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
CBaseEntity *__userpurge CCSPlayer::GetNearestSurfaceBelow@<eax>(
        CCSPlayer *this@<ecx>,
        float a2@<ebp>,
        int a3@<esi>,
        float maxTrace)
{
  unsigned int v5; // eax
  bool v6; // zf
  __int64 v7; // xmm0_8
  CGameRules_vtbl *v8; // eax
  const CViewVectors *(__thiscall *GetViewVectors)(CGameRules *); // edx
  int v10; // eax
  __int64 v11; // xmm0_8
  CGameRules_vtbl *v12; // edx
  int (*v13)(void); // eax
  int v14; // eax
  float v15; // ecx
  float v16; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm0_4
  int v21; // [esp+18h] [ebp-F8h]
  Vector v22; // [esp+1Ch] [ebp-F4h] BYREF
  CGameTrace trace; // [esp+28h] [ebp-E8h] BYREF
  float v24; // [esp+7Ch] [ebp-94h]
  Ray_t ray; // [esp+80h] [ebp-90h]
  CTraceFilterSimple v26; // [esp+D0h] [ebp-40h] BYREF
  Vector minExtent; // [esp+E0h] [ebp-30h]
  Vector traceEnd; // [esp+ECh] [ebp-24h]
  Vector traceStart; // [esp+F8h] [ebp-18h]
  Vector maxExtent; // [esp+104h] [ebp-Ch] BYREF
  float retaddr; // [esp+110h] [ebp+0h]

  maxExtent.x = a2;
  maxExtent.y = retaddr;
  v5 = (unsigned int)this->m_iEFlags >> 11;
  ray.m_Extents.y = 0.0;
  if ( (v5 & 1) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&maxExtent);
  v6 = !this->m_Local.m_bDucked.m_Value;
  v7 = *(_QWORD *)&this->m_vecAbsOrigin.x;
  traceEnd.z = this->m_vecAbsOrigin.z;
  v8 = g_pGameRules->__vftable;
  minExtent.z = traceEnd.z;
  GetViewVectors = v8->GetViewVectors;
  *(_QWORD *)&traceEnd.x = v7;
  *(_QWORD *)&minExtent.x = v7;
  minExtent.z = traceEnd.z - maxTrace;
  if ( v6 )
    v10 = ((int (__stdcall *)(int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, const char *, _DWORD, int, _DWORD, CBaseEntity *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, const matrix3x4_t *, _DWORD, _DWORD, _DWORD, CTraceFilterSimple_vtbl *, const IHandleEntity *, int, bool (__cdecl *)(IHandleEntity *, int), _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))GetViewVectors)(
            a1: a3,
            a2: v21,
            a3: LODWORD(v22.x),
            a4: LODWORD(v22.y),
            a5: LODWORD(v22.z),
            a6: LODWORD(trace.startpos.x),
            a7: LODWORD(trace.startpos.y),
            a8: LODWORD(trace.startpos.z),
            a9: LODWORD(trace.endpos.x),
            a10: LODWORD(trace.endpos.y),
            a11: LODWORD(trace.endpos.z),
            a12: LODWORD(trace.plane.normal.x),
            a13: LODWORD(trace.plane.normal.y),
            a14: LODWORD(trace.plane.normal.z),
            a15: LODWORD(trace.plane.dist),
            a16: *(_DWORD *)&trace.plane.type,
            a17: LODWORD(trace.fraction),
            a18: trace.contents,
            a19: *(_DWORD *)&trace.dispFlags,
            a20: LODWORD(trace.fractionleftsolid),
            a21: trace.surface.name,
            a22: *(_DWORD *)&trace.surface.surfaceProps,
            a23: trace.hitgroup,
            a24: *(_DWORD *)&trace.physicsbone,
            a25: trace.m_pEnt,
            a26: trace.hitbox,
            a27: LODWORD(v24),
            a28: LODWORD(ray.m_Start.x),
            a29: LODWORD(ray.m_Start.y),
            a30: LODWORD(ray.m_Start.z),
            a31: LODWORD(ray.m_Start.w),
            a32: LODWORD(ray.m_Delta.x),
            a33: LODWORD(ray.m_Delta.y),
            a34: LODWORD(ray.m_Delta.z),
            a35: LODWORD(ray.m_Delta.w),
            a36: LODWORD(ray.m_StartOffset.x),
            a37: LODWORD(ray.m_StartOffset.y),
            a38: LODWORD(ray.m_StartOffset.z),
            a39: LODWORD(ray.m_StartOffset.w),
            a40: LODWORD(ray.m_Extents.x),
            a41: LODWORD(ray.m_Extents.y),
            a42: LODWORD(ray.m_Extents.z),
            a43: LODWORD(ray.m_Extents.w),
            a44: ray.m_pWorldAxisTransform,
            a45: *(_DWORD *)&ray.m_IsRay,
            a46: *(_DWORD *)(&ray.m_IsSwept + 3),
            a47: *(_DWORD *)(&ray.m_IsSwept + 7),
            a48: v26.__vftable,
            a49: v26.m_pPassEnt,
            a50: v26.m_collisionGroup,
            a51: v26.m_pExtraShouldHitCheckFunction,
            a52: LODWORD(minExtent.x),
            a53: LODWORD(minExtent.y),
            a54: LODWORD(minExtent.z),
            a55: LODWORD(traceEnd.x),
            a56: LODWORD(traceEnd.y),
            a57: LODWORD(traceEnd.z),
            a58: LODWORD(traceStart.x),
            a59: LODWORD(traceStart.y),
            a60: LODWORD(traceStart.z))
        + 12;
  else
    v10 = ((int (__stdcall *)(int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, const char *, _DWORD, int, _DWORD, CBaseEntity *, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, const matrix3x4_t *, _DWORD, _DWORD, _DWORD, CTraceFilterSimple_vtbl *, const IHandleEntity *, int, bool (__cdecl *)(IHandleEntity *, int), _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))GetViewVectors)(
            a1: a3,
            a2: v21,
            a3: LODWORD(v22.x),
            a4: LODWORD(v22.y),
            a5: LODWORD(v22.z),
            a6: LODWORD(trace.startpos.x),
            a7: LODWORD(trace.startpos.y),
            a8: LODWORD(trace.startpos.z),
            a9: LODWORD(trace.endpos.x),
            a10: LODWORD(trace.endpos.y),
            a11: LODWORD(trace.endpos.z),
            a12: LODWORD(trace.plane.normal.x),
            a13: LODWORD(trace.plane.normal.y),
            a14: LODWORD(trace.plane.normal.z),
            a15: LODWORD(trace.plane.dist),
            a16: *(_DWORD *)&trace.plane.type,
            a17: LODWORD(trace.fraction),
            a18: trace.contents,
            a19: *(_DWORD *)&trace.dispFlags,
            a20: LODWORD(trace.fractionleftsolid),
            a21: trace.surface.name,
            a22: *(_DWORD *)&trace.surface.surfaceProps,
            a23: trace.hitgroup,
            a24: *(_DWORD *)&trace.physicsbone,
            a25: trace.m_pEnt,
            a26: trace.hitbox,
            a27: LODWORD(v24),
            a28: LODWORD(ray.m_Start.x),
            a29: LODWORD(ray.m_Start.y),
            a30: LODWORD(ray.m_Start.z),
            a31: LODWORD(ray.m_Start.w),
            a32: LODWORD(ray.m_Delta.x),
            a33: LODWORD(ray.m_Delta.y),
            a34: LODWORD(ray.m_Delta.z),
            a35: LODWORD(ray.m_Delta.w),
            a36: LODWORD(ray.m_StartOffset.x),
            a37: LODWORD(ray.m_StartOffset.y),
            a38: LODWORD(ray.m_StartOffset.z),
            a39: LODWORD(ray.m_StartOffset.w),
            a40: LODWORD(ray.m_Extents.x),
            a41: LODWORD(ray.m_Extents.y),
            a42: LODWORD(ray.m_Extents.z),
            a43: LODWORD(ray.m_Extents.w),
            a44: ray.m_pWorldAxisTransform,
            a45: *(_DWORD *)&ray.m_IsRay,
            a46: *(_DWORD *)(&ray.m_IsSwept + 3),
            a47: *(_DWORD *)(&ray.m_IsSwept + 7),
            a48: v26.__vftable,
            a49: v26.m_pPassEnt,
            a50: v26.m_collisionGroup,
            a51: v26.m_pExtraShouldHitCheckFunction,
            a52: LODWORD(minExtent.x),
            a53: LODWORD(minExtent.y),
            a54: LODWORD(minExtent.z),
            a55: LODWORD(traceEnd.x),
            a56: LODWORD(traceEnd.y),
            a57: LODWORD(traceEnd.z),
            a58: LODWORD(traceStart.x),
            a59: LODWORD(traceStart.y),
            a60: LODWORD(traceStart.z))
        + 36;
  v6 = !this->m_Local.m_bDucked.m_Value;
  v11 = *(_QWORD *)v10;
  v12 = g_pGameRules->__vftable;
  v26.m_pExtraShouldHitCheckFunction = *(bool (__cdecl **)(IHandleEntity *, int))(v10 + 8);
  v13 = (int (*)(void))v12->GetViewVectors;
  *(_QWORD *)&v26.m_pPassEnt = v11;
  if ( v6 )
    v14 = v13() + 24;
  else
    v14 = v13() + 48;
  v15 = *(float *)(v14 + 8);
  *(_QWORD *)&traceStart.x = *(_QWORD *)v14;
  ray.m_Start.z = minExtent.y - traceEnd.y;
  ray.m_Start.y = minExtent.x - traceEnd.x;
  ray.m_Start.w = minExtent.z - traceEnd.z;
  ray.m_Extents.y = 0.0;
  BYTE1(ray.m_Extents.z) = (float)((float)((float)(ray.m_Start.z * ray.m_Start.z)
                                         + (float)(ray.m_Start.y * ray.m_Start.y))
                                 + (float)(ray.m_Start.w * ray.m_Start.w)) != 0.0;
  ray.m_StartOffset.y = (float)(traceStart.x - *(float *)&v26.m_pPassEnt) * 0.5;
  ray.m_StartOffset.z = (float)(traceStart.y - *(float *)&v26.m_collisionGroup) * 0.5;
  ray.m_StartOffset.w = (float)(v15 - *(float *)&v26.m_pExtraShouldHitCheckFunction) * 0.5;
  LOBYTE(ray.m_Extents.z) = (float)((float)((float)(ray.m_StartOffset.z * ray.m_StartOffset.z)
                                          + (float)(ray.m_StartOffset.y * ray.m_StartOffset.y))
                                  + (float)(ray.m_StartOffset.w * ray.m_StartOffset.w)) < 0.000001;
  v16 = (float)(*(float *)&v26.m_pPassEnt + traceStart.x) * 0.5;
  v17 = (float)(*(float *)&v26.m_collisionGroup + traceStart.y) * 0.5;
  v18 = 0.5 * (float)(*(float *)&v26.m_pExtraShouldHitCheckFunction + v15);
  *(float *)&trace.m_pEnt = v16 + traceEnd.x;
  *(float *)&trace.hitbox = v17 + traceEnd.y;
  v24 = v18 + traceEnd.z;
  ray.m_Delta.y = v16 * -1.0;
  ray.m_Delta.z = v17 * -1.0;
  ray.m_Delta.w = v18 * -1.0;
  CTraceFilterSimple::CTraceFilterSimple(this: &v26, passedict: this, collisionGroup: 8, pExtraShouldHitFunc: nullptr);
  enginetrace->TraceRay(
    this: enginetrace,
    a2: (const Ray_t *)&trace.m_pEnt,
    a3: 33636363u,
    a4: &v26,
    a5: (CGameTrace *)&v22);
  if ( r_visualizetraces.m_pParent != nullptr && r_visualizetraces.m_pParent->m_Value.m_nValue != 0 )
    DebugDrawLine(vecAbsStart: &v22, vecAbsEnd: &trace.startpos, r: 255, g: 0, b: 0, test: 1, duration: -1.0);
  return *(CBaseEntity **)&trace.surface.surfaceProps;
}

//------------------------------------------------------------------------------
// Address: 0x10280860
// Name: protected: virtual void CCSPlayer::AttemptToExitFreezeCam(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::AttemptToExitFreezeCam(CCSPlayer *this)
{
  if ( (float)(this->m_flDeathTime.m_Value + 0.8 + spec_freeze_traveltime.m_pParent->m_Value.m_fValue) <= gpGlobals->curtime )
    this->m_bAbortFreezeCam = true;
}

//------------------------------------------------------------------------------
// Address: 0x102808A0
// Name: public: bool CCSPlayer::CanControlBot(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSPlayer::CanControlBot(CCSPlayer *this, CCSBot *pBot)
{
  int TeamNumber; // ebx
  CBaseCombatWeapon *ActiveWeapon; // eax
  _BYTE *v6; // eax

  if ( cv_bot_controllable.m_pParent == nullptr || cv_bot_controllable.m_pParent->m_Value.m_nValue == 0 )
    return false;
  if ( pBot == nullptr )
    return false;
  if ( !pBot->IsAlive(this: pBot) )
    return false;
  TeamNumber = CBaseEntity::GetTeamNumber(this: pBot);
  if ( TeamNumber != CBaseEntity::GetTeamNumber(this) )
    return false;
  if ( !this->IsValidObserverTarget(this, a2: pBot) )
    return false;
  if ( CCSPlayer::HasControlledByPlayer(this: pBot) )
    return false;
  if ( CCSBot::IsDefusingBomb(this: pBot) )
    return false;
  ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: pBot);
  v6 = __RTDynamicCast(
         inptr: ActiveWeapon,
         VfDelta: 0,
         SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
         TargetType: &CC4 `RTTI Type Descriptor',
         isReference: 0);
  if ( v6 != nullptr && v6[1472] != 0 )
    return false;
  if ( CCSGameRules::IsRoundOver(this: (CCSGameRules *)g_pGameRules)
    || CCSGameRules::IsFreezePeriod(this: (CCSGameRules *)g_pGameRules) )
  {
    return false;
  }
  return !this->IsAlive(this);
}

//------------------------------------------------------------------------------
// Address: 0x10280990
// Name: public: class CCSBot __near * CCSPlayer::FindNearestControllableBot(bool)
// Source: json
//------------------------------------------------------------------------------
CCSBot *__thiscall CCSPlayer::FindNearestControllableBot(CCSPlayer *this, bool bMustBeValidObserverTarget)
{
  int v4; // ebx
  CBasePlayer *v5; // eax
  CBasePlayer *v6; // esi
  void *v7; // eax
  void *v8; // esi
  CCSBot *v9; // eax
  CBaseEntity *v10; // esi
  float flNearestDistSqr; // [esp+4h] [ebp-8h]
  CCSBot *pNearestBot; // [esp+8h] [ebp-4h]
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  if ( cv_bot_controllable.m_pParent == nullptr || cv_bot_controllable.m_pParent->m_Value.m_nValue == 0 )
    return nullptr;
  v4 = 1;
  flNearestDistSqr = 0.0;
  for ( pNearestBot = nullptr; v4 <= gpGlobals->maxClients; ++v4 )
  {
    v5 = UTIL_PlayerByIndex(playerIndex: v4);
    v6 = v5;
    if ( v5 != nullptr && v5->IsPlayer(this: v5) )
    {
      v7 = __RTDynamicCast(
             inptr: v6,
             VfDelta: 0,
             SrcType: &CBaseEntity `RTTI Type Descriptor',
             TargetType: &CCSPlayer `RTTI Type Descriptor',
             isReference: 0);
      v8 = v7;
      if ( v7 != nullptr && (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)v7 + 1912))(a1: v7) != 0 )
      {
        v9 = (CCSBot *)__RTDynamicCast(
                         inptr: v8,
                         VfDelta: 0,
                         SrcType: &CCSPlayer `RTTI Type Descriptor',
                         TargetType: &CCSBot `RTTI Type Descriptor',
                         isReference: 0);
        v10 = v9;
        if ( v9 != nullptr
          && CCSPlayer::CanControlBot(this, pBot: v9)
          && (!bMustBeValidObserverTarget || this->IsValidObserverTarget(this, a2: v10)) )
        {
          if ( (v10->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this: v10, a2: (int)&savedregs);
          if ( (this->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
          if ( pNearestBot == nullptr
            || flNearestDistSqr > (float)((float)((float)((float)(this->m_vecAbsOrigin.y - v10->m_vecAbsOrigin.y)
                                                        * (float)(this->m_vecAbsOrigin.y - v10->m_vecAbsOrigin.y))
                                                + (float)((float)(this->m_vecAbsOrigin.x - v10->m_vecAbsOrigin.x)
                                                        * (float)(this->m_vecAbsOrigin.x - v10->m_vecAbsOrigin.x)))
                                        + (float)((float)(this->m_vecAbsOrigin.z - v10->m_vecAbsOrigin.z)
                                                * (float)(this->m_vecAbsOrigin.z - v10->m_vecAbsOrigin.z))) )
          {
            flNearestDistSqr = (float)((float)((float)(this->m_vecAbsOrigin.y - v10->m_vecAbsOrigin.y)
                                             * (float)(this->m_vecAbsOrigin.y - v10->m_vecAbsOrigin.y))
                                     + (float)((float)(this->m_vecAbsOrigin.x - v10->m_vecAbsOrigin.x)
                                             * (float)(this->m_vecAbsOrigin.x - v10->m_vecAbsOrigin.x)))
                             + (float)((float)(this->m_vecAbsOrigin.z - v10->m_vecAbsOrigin.z)
                                     * (float)(this->m_vecAbsOrigin.z - v10->m_vecAbsOrigin.z));
            pNearestBot = (CCSBot *)v10;
          }
        }
      }
    }
  }
  return pNearestBot;
}

//------------------------------------------------------------------------------
// Address: 0x10280B20
// Name: public: virtual void CCSPlayer::IncrementFragCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::IncrementFragCount(CCSPlayer *this, int nCount)
{
  unsigned int m_Index; // edx
  IHandleEntity *m_pEntity; // eax

  if ( this->m_bIsControllingBot.m_Value
    && (m_Index = this->m_hControlledBot.m_Index) != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
  {
    m_pEntity->__vftable[156].SetRefEHandle(this: m_pEntity, a2: (const CBaseHandle *)nCount);
  }
  else
  {
    this->m_iFrags += nCount;
    this->pl.frags = this->m_iFrags;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10280B90
// Name: public: virtual void CCSPlayer::IncrementDeathCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::IncrementDeathCount(CCSPlayer *this, int nCount)
{
  unsigned int m_Index; // edx
  IHandleEntity *m_pEntity; // eax

  if ( this->m_bIsControllingBot.m_Value
    && (m_Index = this->m_hControlledBot.m_Index) != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
  {
    ((void (__thiscall *)(IHandleEntity *, int))m_pEntity->__vftable[156].GetRefEHandle)(a1: m_pEntity, a2: nCount);
  }
  else
  {
    this->m_iDeaths += nCount;
    this->pl.deaths = this->m_iDeaths;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10280C00
// Name: public: void CCSPlayer::AddScore(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::AddScore(CCSPlayer *this, int iPoints)
{
  unsigned int m_Index; // ecx
  CCSPlayer *m_pEntity; // eax

  if ( this->m_bIsControllingBot.m_Value )
  {
    m_Index = this->m_hControlledBot.m_Index;
    if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    {
      m_pEntity = (CCSPlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
      if ( m_pEntity != nullptr )
        CCSPlayer::AddScore(this: m_pEntity, iPoints);
    }
  }
  else
  {
    this->m_iScore += iPoints;
    this->m_iRoundScore += iPoints;
  }
  if ( this->m_iScore < 0 )
    this->m_iScore = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10280D00
// Name: public: void CWeaponCSBase::SetDonor(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWeaponCSBase::SetDonor(CWeaponCSBase *this, CCSPlayer *player)
{
  if ( player != nullptr )
    this->m_donor.m_Index = player->GetRefEHandle(this: player)->m_Index;
  else
    this->m_donor.m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10280FB0
// Name: public: virtual void CCSPlayer::PlayerRunCommand(class CUserCmd __near *,class IMoveHelper __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::PlayerRunCommand(CCSPlayer *this, CUserCmd *ucmd, IMoveHelper *moveHelper)
{
  CUserCmd *p_tempCmd; // edi
  int v4; // edx
  int tickcount; // ecx
  int tick_count; // eax
  int m_nValue; // ecx
  CBasePlayer *v8; // edx
  edict_t *m_pPev; // eax
  signed int v10; // eax
  CUserCmd tempCmd; // [esp+4h] [ebp-5Ch] BYREF
  CBasePlayer *v12; // [esp+5Ch] [ebp-4h]

  v12 = this;
  if ( sv_runcmds.m_pParent != nullptr && sv_runcmds.m_pParent->m_Value.m_nValue != 0 )
  {
    p_tempCmd = ucmd;
    if ( IsEngineThreaded()
      || (sv_max_usercmd_future_ticks.m_pParent == nullptr
        ? (v4 = 0)
        : (v4 = sv_max_usercmd_future_ticks.m_pParent->m_Value.m_nValue),
          tickcount = gpGlobals->tickcount,
          (tick_count = ucmd->tick_count) <= tickcount + v4) )
    {
      tempCmd.__vftable = (CUserCmd_vtbl *)&CUserCmd::`vftable';
      memset(&tempCmd.command_number, 0, 37);
      memset(&tempCmd.weaponselect, 0, 17);
      memset((void *)&tempCmd.headangles, 0, 24);
      if ( bot_mimic.m_pParent != nullptr )
        m_nValue = bot_mimic.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      v8 = v12;
      m_pPev = v12->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        v10 = m_pPev - gpGlobals->pEdicts;
      else
        v10 = 0;
      if ( -m_nValue == v10 )
      {
        CUserCmd::operator=(this: &tempCmd, src: ucmd);
        v8 = v12;
        p_tempCmd = &tempCmd;
        memset(&tempCmd.forwardmove, 0, 17);
      }
      if ( v8->IsBot(this: v8) && bot_crouch.m_pParent != nullptr && bot_crouch.m_pParent->m_Value.m_nValue != 0 )
        p_tempCmd->buttons |= 4u;
      CBasePlayer::PlayerRunCommand(this: v12, ucmd: p_tempCmd, moveHelper);
    }
    else
    {
      DevMsg(a1: "Client cmd out of sync (delta %i).\n", tick_count - tickcount);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10281110
// Name: public: virtual int CCSPlayer::OnTakeDamage_Alive(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CCSPlayer::OnTakeDamage_Alive@<eax>(
        CCSPlayer *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        const CTakeDamageInfo *info)
{
  int result; // eax
  IGameEvent *v6; // esi
  int v7; // eax
  void (__thiscall *SetInt)(IGameEvent *, const char *, int); // edx
  unsigned int m_Index; // ecx
  const char *v10; // ebx
  int v11; // eax
  CBaseCombatWeapon *Inflictor; // eax
  const char *pszValue; // eax
  CBaseEntity *Attacker; // eax
  int TeamNumber; // ebx
  CBasePlayer *player; // [esp+4h] [ebp-4h]
  CBasePlayer *playera; // [esp+4h] [ebp-4h]

  if ( this->m_bGunGameImmunity.m_Value )
    return 0;
  this->m_bitsDamageType |= info->m_bitsDamageType;
  result = CBaseCombatCharacter::OnTakeDamage_Alive(this, info);
  if ( result != 0 )
  {
    v6 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_hurt", a3: 0, a4: 0);
    if ( v6 == nullptr )
      return 1;
    v7 = ((int (__thiscall *)(IVEngineServer *, edict_t *, int, int))engine->GetPlayerUserId)(
           a1: engine,
           a2: this->m_Network.m_pPev,
           a3,
           a4: a2);
    v6->SetInt(this: v6, a2: "userid", a3: v7);
    v6->SetInt(this: v6, a2: "health", a3: this->m_iHealth.m_Value < 0 ? 0 : this->m_iHealth.m_Value);
    v6->SetInt(this: v6, a2: "armor", a3: this->m_ArmorValue.m_Value < 0 ? 0 : this->m_ArmorValue.m_Value);
    v6->SetInt(this: v6, a2: "dmg_health", a3: this->m_lastDamageHealth);
    v6->SetInt(this: v6, a2: "dmg_armor", a3: this->m_lastDamageArmor);
    SetInt = v6->SetInt;
    if ( (info->m_bitsDamageType & 0x40) != 0 )
      SetInt(this: v6, a2: "hitgroup", a3: 0);
    else
      SetInt(this: v6, a2: "hitgroup", a3: this->m_LastHitGroup);
    m_Index = info->m_hAttacker.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      player = nullptr;
    else
      player = (CBasePlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    v10 = locale;
    if ( player->IsPlayer(this: player) )
    {
      playera = ToBasePlayer(pEntity: player);
      v11 = engine->GetPlayerUserId(this: engine, a2: playera->m_Network.m_pPev);
      v6->SetInt(this: v6, a2: "attacker", a3: v11);
      Inflictor = (CBaseCombatWeapon *)CTakeDamageInfo::GetInflictor(this: info);
      if ( Inflictor != nullptr )
      {
        if ( Inflictor != (CBaseCombatWeapon *)playera )
          goto LABEL_17;
        if ( CBaseCombatCharacter::GetActiveWeapon(this: playera) != nullptr )
        {
          Inflictor = CBaseCombatCharacter::GetActiveWeapon(this: playera);
LABEL_17:
          pszValue = Inflictor->m_iClassname.pszValue;
          if ( pszValue != nullptr )
            v10 = pszValue;
          else
            v10 = locale;
        }
      }
    }
    else
    {
      v6->SetInt(this: v6, a2: "attacker", a3: 0);
    }
    if ( strncmp(first: v10, last: "weapon_", count: 7u) != 0 )
    {
      if ( strncmp(first: v10, last: "hegrenade", count: 9u) == 0 )
      {
        Attacker = CTakeDamageInfo::GetAttacker(this: info);
        TeamNumber = CBaseEntity::GetTeamNumber(this: Attacker);
        if ( TeamNumber != CBaseEntity::GetTeamNumber(this) )
          this->m_grenadeDamageTakenThisRound = (int)(float)((float)this->m_grenadeDamageTakenThisRound
                                                           + info->m_flDamage);
      }
      else if ( strncmp(first: v10, last: "flashbang", count: 9u) != 0 )
      {
        strncmp(first: v10, last: "smokegrenade", count: 0xCu);
      }
    }
    ((void (__thiscall *)(IGameEvent *, const char *))v6->SetString)(a1: v6, a2: "weapon");
    v6->SetInt(this: v6, a2: "priority", a3: 5);
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v6, a3: false);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102813B0
// Name: public: bool CCSPlayer::IsCloseToActiveBomb(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSPlayer::IsCloseToActiveBomb(CCSPlayer *this)
{
  int v1; // edi
  CPlantedC4 *v3; // esi
  __int64 bombPos; // [esp+Ch] [ebp-Ch]
  float bombPos_8; // [esp+14h] [ebp-4h]
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  v1 = 0;
  if ( g_PlantedC4s.m_Size <= 0 )
    return 0;
  while ( 1 )
  {
    v3 = g_PlantedC4s.m_Memory.m_pMemory[v1];
    if ( v3 != nullptr && v3->m_bBombTicking.m_Value )
    {
      if ( (v3->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: g_PlantedC4s.m_Memory.m_pMemory[v1], a2: (int)&savedregs);
      bombPos = *(_QWORD *)&v3->m_vecAbsOrigin.x;
      bombPos_8 = v3->m_vecAbsOrigin.z;
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      if ( (float)((float)((float)((float)(this->m_vecAbsOrigin.x - *(float *)&bombPos)
                                 * (float)(this->m_vecAbsOrigin.x - *(float *)&bombPos))
                         + (float)((float)(this->m_vecAbsOrigin.y - *((float *)&bombPos + 1))
                                 * (float)(this->m_vecAbsOrigin.y - *((float *)&bombPos + 1))))
                 + (float)((float)(this->m_vecAbsOrigin.z - bombPos_8) * (float)(this->m_vecAbsOrigin.z - bombPos_8))) < 230400.0 )
        break;
    }
    if ( ++v1 >= g_PlantedC4s.m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102814A0
// Name: public: bool CCSPlayer::IsObjectiveKill(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSPlayer::IsObjectiveKill(CCSPlayer *this, CCSPlayer *pCSVictim)
{
  return pCSVictim != nullptr && CCSPlayer::IsCloseToActiveBomb(this: pCSVictim) != 0
      || CCSPlayer::IsCloseToActiveBomb(this) != 0
      || pCSVictim != nullptr && pCSVictim->m_iNumFollowers > 0
      || this->m_iNumFollowers > 0;
}

//------------------------------------------------------------------------------
// Address: 0x102814F0
// Name: public: virtual class CBaseEntity __near * CCSPlayer::FindNextObserverTarget(bool)
// Source: json
//------------------------------------------------------------------------------
CBasePlayer *__thiscall CCSPlayer::FindNextObserverTarget(CCSPlayer *this, int bReverse)
{
  CBasePlayer *result; // eax

  result = CBasePlayer::FindNextObserverTarget(this, bReverse);
  if ( result == nullptr && g_PlantedC4s.m_Size > 0 )
  {
    this->SetObserverTarget(this, a2: *g_PlantedC4s.m_Memory.m_pMemory);
    this->SetObserverMode(this, a2: 5);
    return (CBasePlayer *)*g_PlantedC4s.m_Memory.m_pMemory;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10281540
// Name: public: void CCSPlayer::UpdateMouseoverHints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::UpdateMouseoverHints(CCSPlayer *this)
{
  CBaseEntity *m_pEnt; // edi
  int v3; // eax
  int v4; // eax
  unsigned int m_iDisplayHistoryBits; // eax
  CHintMessageQueue *v6; // ecx
  CHintMessageQueue *m_pHintMessageQueue; // ecx
  unsigned int v8; // eax
  CHintMessageQueue *v9; // ecx
  int v10; // eax
  const Vector *v11; // eax
  bool v12; // zf
  unsigned int v13; // eax
  CHintMessageQueue *v14; // ecx
  CHintMessageQueue *v15; // ecx
  CGameTrace tr; // [esp+24h] [ebp-90h] BYREF
  _BYTE v17[12]; // [esp+78h] [ebp-3Ch] BYREF
  Vector up; // [esp+84h] [ebp-30h] BYREF
  Vector forward; // [esp+90h] [ebp-24h] BYREF
  Vector searchStart; // [esp+9Ch] [ebp-18h] BYREF
  Vector searchEnd; // [esp+A8h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+B4h] [ebp+0h] BYREF

  if ( this->m_blindUntilTime <= gpGlobals->curtime && (this->m_afPhysicsFlags.m_Value & 8) == 0 )
  {
    CBasePlayer::EyeVectors(this, pForward: &forward, pRight: nullptr, pUp: &up);
    this->EyePosition(this, result: &searchStart);
    searchEnd.y = searchStart.y + (float)(forward.y * 2048.0);
    searchEnd.x = searchStart.x + (float)(forward.x * 2048.0);
    searchEnd.z = searchStart.z + (float)(forward.z * 2048.0);
    UTIL_TraceLine(
      a1: &savedregs,
      a2: (int)this,
      vecAbsStart: &searchStart,
      vecAbsEnd: &searchEnd,
      mask: 0x202608Bu,
      ignore: this,
      collisionGroup: 0,
      ptr: &tr);
    if ( tr.fraction != 1.0 && CGameTrace::DidHitNonWorldEntity(this: &tr) && tr.m_pEnt != nullptr )
    {
      m_pEnt = tr.m_pEnt;
      v3 = ((int (*)(void))tr.m_pEnt->Classify)() - 1;
      if ( v3 != 0 )
      {
        if ( v3 == 1 )
        {
          v4 = CBaseEntity::GetTeamNumber(this) - 2;
          if ( v4 != 0 )
          {
            if ( v4 == 1 )
            {
              m_iDisplayHistoryBits = this->m_iDisplayHistoryBits;
              if ( (m_iDisplayHistoryBits & 4) != 0 || tr.fraction <= 0.1 )
              {
                if ( (m_iDisplayHistoryBits & 8) == 0 && tr.fraction <= 0.1 )
                {
                  this->m_iDisplayHistoryBits = m_iDisplayHistoryBits | 0xC;
                  if ( this->IsAlive(this) && this->IsNetClient(this) )
                  {
                    m_pHintMessageQueue = this->m_pHintMessageQueue;
                    if ( m_pHintMessageQueue != nullptr && this->m_bShowHints )
                      CHintMessageQueue::AddMessage(
                        this: m_pHintMessageQueue,
                        message: "#Hint_press_use_so_hostage_will_follow",
                        duration: 6.0,
                        args: nullptr);
                  }
                }
              }
              else
              {
                this->m_iDisplayHistoryBits = m_iDisplayHistoryBits | 4;
                if ( this->IsNetClient(this) )
                {
                  v6 = this->m_pHintMessageQueue;
                  if ( v6 != nullptr && this->m_bShowHints )
                    CHintMessageQueue::AddMessage(
                      this: v6,
                      message: "#Hint_rescue_the_hostages",
                      duration: 6.0,
                      args: nullptr);
                }
              }
            }
          }
          else
          {
            v8 = this->m_iDisplayHistoryBits;
            if ( (v8 & 4) == 0 )
            {
              this->m_iDisplayHistoryBits = v8 | 4;
              if ( this->IsNetClient(this) )
              {
                v9 = this->m_pHintMessageQueue;
                if ( v9 != nullptr && this->m_bShowHints )
                  CHintMessageQueue::AddMessage(
                    this: v9,
                    message: "#Hint_prevent_hostage_rescue",
                    duration: 6.0,
                    args: nullptr);
              }
            }
          }
        }
      }
      else
      {
        v10 = ((int (__thiscall *)(CBaseEntity *))m_pEnt->EyePosition)(a1: m_pEnt);
        v11 = (const Vector *)((int (__thiscall *)(CCSPlayer *, _BYTE *, int))this->EyePosition)(
                                a1: this,
                                a2: v17,
                                a3: v10);
        if ( !CBotManager::IsLineBlockedBySmoke(this: TheBots, from: v11, to: &searchEnd, grenadeBloat: 1.2) )
        {
          v12 = g_pGameRules->PlayerRelationship(this: g_pGameRules, a2: this, a3: m_pEnt) == 1;
          v13 = this->m_iDisplayHistoryBits;
          if ( v12 )
          {
            if ( (v13 & 0x80u) == 0 )
            {
              this->m_iDisplayHistoryBits = v13 | 0x80;
              if ( this->IsNetClient(this) )
              {
                v14 = this->m_pHintMessageQueue;
                if ( v14 != nullptr && this->m_bShowHints )
                  CHintMessageQueue::AddMessage(
                    this: v14,
                    message: "#Hint_spotted_a_friend",
                    duration: 6.0,
                    args: nullptr);
              }
            }
          }
          else if ( (v13 & 0x100) == 0 )
          {
            this->m_iDisplayHistoryBits = v13 | 0x100;
            if ( this->IsNetClient(this) )
            {
              v15 = this->m_pHintMessageQueue;
              if ( v15 != nullptr && this->m_bShowHints )
                CHintMessageQueue::AddMessage(
                  this: v15,
                  message: "#Hint_spotted_an_enemy",
                  duration: 6.0,
                  args: nullptr);
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102818D0
// Name: public: bool CCSPlayer::IsArmored(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSPlayer::IsArmored(CCSPlayer *this, int nHitGroup)
{
  bool result; // al

  result = false;
  if ( this->m_ArmorValue.m_Value > 0 )
  {
    switch ( nHitGroup )
    {
      case 0:
      case 2:
      case 3:
      case 4:
      case 5:
        goto $LN4_48;
      case 1:
        if ( this->m_bHasHelmet.m_Value )
$LN4_48:
          result = true;
        break;
      default:
        return result;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10281920
// Name: public: void CCSPlayer::MoveToNextIntroCamera(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::MoveToNextIntroCamera(CCSPlayer *this)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx
  CBaseEntity *EntityByClassname; // eax
  unsigned int v5; // eax
  CBaseEntityList *v6; // edx
  CBaseEntity *v7; // ecx
  CBaseEntity *v8; // eax
  unsigned int v9; // ecx
  CBaseEntity *v10; // ebx
  int v11; // eax
  CEntInfo *v12; // esi
  unsigned int v13; // ecx
  int v14; // eax
  bool v15; // zf
  CEntInfo *v16; // eax
  IHandleEntity *v17; // eax
  const char *v18; // eax
  CBasePlayer *EntityByName; // eax
  unsigned int v20; // eax
  CBaseEntity *v21; // ecx
  CBaseEntity *v22; // eax
  unsigned int v23; // eax
  CBaseEntity *v24; // esi
  const CViewVectors *v25; // eax
  unsigned int v26; // eax
  CBaseEntity *v27; // esi
  unsigned int v28; // eax
  CBaseEntity *v29; // esi
  QAngle CamAngles; // [esp+Ch] [ebp-30h] BYREF
  Vector vIntroCamera; // [esp+18h] [ebp-24h] BYREF
  Vector absOrigin; // [esp+24h] [ebp-18h] BYREF
  Vector vCamera; // [esp+30h] [ebp-Ch] BYREF
  int savedregs; // [esp+3Ch] [ebp+0h] BYREF

  m_Index = this->m_pIntroCamera.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  EntityByClassname = CGlobalEntityList::FindEntityByClassname(
                        this: &gEntList,
                        pStartEntity: m_pEntity,
                        szName: "point_viewcontrol");
  if ( EntityByClassname != nullptr )
    this->m_pIntroCamera.m_Index = EntityByClassname->GetRefEHandle(this: EntityByClassname)->m_Index;
  else
    this->m_pIntroCamera.m_Index = -1;
  v5 = this->m_pIntroCamera.m_Index;
  v6 = g_pEntityList;
  if ( v5 == -1 )
    goto LABEL_13;
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity == nullptr )
  {
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5) )
LABEL_13:
      v7 = nullptr;
    else
      v7 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
    v8 = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: v7, szName: "point_viewcontrol");
    if ( v8 != nullptr )
      this->m_pIntroCamera.m_Index = v8->GetRefEHandle(this: v8)->m_Index;
    else
      this->m_pIntroCamera.m_Index = -1;
    v6 = g_pEntityList;
  }
  v9 = this->m_pIntroCamera.m_Index;
  v10 = nullptr;
  if ( v9 != -1 )
  {
    v11 = (unsigned __int16)v9;
    v12 = &v6->m_EntPtrArray[(unsigned __int16)v9];
    v13 = HIWORD(v9);
    if ( v12->m_SerialNumber == v13 && v12->m_pEntity != nullptr )
    {
      v14 = v11;
      v15 = v6->m_EntPtrArray[v14].m_SerialNumber == v13;
      v16 = &v6->m_EntPtrArray[v14];
      if ( v15 )
        v17 = v16->m_pEntity;
      else
        v17 = nullptr;
      v18 = (const char *)v17[44].__vftable;
      if ( v18 == nullptr )
        v18 = locale;
      EntityByName = CGlobalEntityList::FindEntityByName(
                       this: &gEntList,
                       pStartEntity: nullptr,
                       szName: v18,
                       pSearchingEntity: nullptr,
                       pActivator: nullptr,
                       pCaller: nullptr,
                       pFilter: nullptr);
      v6 = g_pEntityList;
      v10 = EntityByName;
    }
  }
  v20 = this->m_pIntroCamera.m_Index;
  if ( v20 == -1 )
    goto LABEL_32;
  if ( v6->m_EntPtrArray[(unsigned __int16)v20].m_SerialNumber != HIWORD(v20)
    || v6->m_EntPtrArray[(unsigned __int16)v20].m_pEntity == nullptr )
  {
    if ( v6->m_EntPtrArray[(unsigned __int16)v20].m_SerialNumber == HIWORD(v20) )
    {
      v21 = (CBaseEntity *)v6->m_EntPtrArray[(unsigned __int16)v20].m_pEntity;
      goto LABEL_33;
    }
LABEL_32:
    v21 = nullptr;
LABEL_33:
    v22 = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: v21, szName: "info_player_terrorist");
    if ( v22 != nullptr )
      this->m_pIntroCamera.m_Index = v22->GetRefEHandle(this: v22)->m_Index;
    else
      this->m_pIntroCamera.m_Index = -1;
  }
  this->SetViewOffset(this, a2: &vec3_origin);
  UTIL_SetSize(pEnt: this, vecMin: &vec3_origin, vecMax: &vec3_origin);
  if ( v10 != nullptr )
  {
    v26 = this->m_pIntroCamera.m_Index;
    if ( v26 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v26].m_SerialNumber != HIWORD(v26) )
      v27 = nullptr;
    else
      v27 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v26].m_pEntity;
    if ( (v27->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v27, a2: (int)&savedregs);
    if ( (v10->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v10, a2: (int)&savedregs);
    v28 = this->m_pIntroCamera.m_Index;
    vCamera.x = v10->m_vecAbsOrigin.x - v27->m_vecAbsOrigin.x;
    vCamera.y = v10->m_vecAbsOrigin.y - v27->m_vecAbsOrigin.y;
    vCamera.z = v10->m_vecAbsOrigin.z - v27->m_vecAbsOrigin.z;
    if ( v28 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v28].m_SerialNumber != HIWORD(v28) )
      v29 = nullptr;
    else
      v29 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v28].m_pEntity;
    if ( (v29->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v29, a2: (int)&savedregs);
    vIntroCamera = v29->m_vecAbsOrigin;
    VectorNormalize(vec: &vCamera);
    VectorAngles(forward: &vCamera, angles: &CamAngles);
    CBaseEntity::SetAbsOrigin(this, absOrigin: &vIntroCamera);
    CBaseEntity::SetAbsAngles(this, absAngles: &CamAngles);
    CBasePlayer::SnapEyeAngles(this, viewAngles: &CamAngles);
    this->m_fIntroCamTime = gpGlobals->curtime + 6.0;
  }
  else
  {
    if ( this->m_pIntroCamera.m_Index != -1 )
    {
      v23 = this->m_pIntroCamera.m_Index;
      if ( v23 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v23].m_SerialNumber != HIWORD(v23) )
        v24 = nullptr;
      else
        v24 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v23].m_pEntity;
      if ( (v24->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v24, a2: (int)&savedregs);
      v25 = g_pGameRules->GetViewVectors(this: g_pGameRules);
      absOrigin.x = v25->m_vView.x + v24->m_vecAbsOrigin.x;
      absOrigin.y = v25->m_vView.y + v24->m_vecAbsOrigin.y;
      absOrigin.z = v25->m_vView.z + v24->m_vecAbsOrigin.z;
      CBaseEntity::SetAbsOrigin(this, &absOrigin);
    }
    memset((void *)&absOrigin, 0, sizeof(absOrigin));
    CBaseEntity::SetAbsAngles(this, absAngles: (const QAngle *)&absOrigin);
    this->m_pIntroCamera.m_Index = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10281D30
// Name: cs_make_vip
// Source: json
//------------------------------------------------------------------------------
void __cdecl cs_make_vip(const CCommand *args)
{
  int v1; // eax
  CBasePlayer *v2; // esi

  if ( UTIL_IsCommandIssuedByServerAdmin() && args->m_nArgc == 2 )
  {
    v1 = atoi(nptr: args->m_ppArgv[1]);
    v2 = UTIL_PlayerByIndex(playerIndex: v1);
    ForEachPlayer<NotVIP>();
    if ( v2 != nullptr )
      LOBYTE(v2[1].m_Relationship.m_Memory.m_pMemory) = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10281D90
// Name: public: void CCSPlayer::Radio(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::Radio(CCSPlayer *this, const char *pszRadioSound, const char *pszRadioText)
{
  const char *v4; // eax
  edict_t *v5; // eax
  edict_t *m_pPev; // eax
  unsigned int v7; // ebx
  const char *v8; // edi
  const char *v9; // [esp+0h] [ebp-38h]
  const char *v10; // [esp+4h] [ebp-34h]
  CRecipientFilter filter; // [esp+18h] [ebp-20h] BYREF

  if ( this->IsAlive(this) && (this->m_afPhysicsFlags.m_Value & 8) == 0 )
  {
    CRecipientFilter::CRecipientFilter(this: &filter);
    CCSPlayer::ConstructRadioFilter(this, (CFmtStrN<1024> *)&filter);
    if ( pszRadioText != nullptr )
    {
      v4 = g_pGameRules->GetChatLocation(this: g_pGameRules, a2: 1, a3: this);
      if ( v4 != nullptr && *v4 != 0 )
      {
        v10 = v4;
        v9 = this->GetPlayerName(this);
        v5 = CBaseEntity::entindex(this);
        UTIL_CSRadioMessage(
          &filter,
          iClient: (unsigned int)v5,
          msg_dest: 3u,
          msg_name: "#Game_radio_location",
          param1: v9,
          param2: v10,
          param3: pszRadioText,
          param4: nullptr);
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          v7 = m_pPev - gpGlobals->pEdicts;
        else
          v7 = 0;
        v8 = this->GetPlayerName(this);
        UserMessageBegin(&filter, messagename: "RadioText");
        MessageWriteByte(iValue: 3u);
        MessageWriteByte(iValue: v7);
        MessageWriteString(sz: "#Game_radio");
        if ( v8 != nullptr )
          MessageWriteString(sz: v8);
        else
          MessageWriteString(sz: locale);
        MessageWriteString(sz: pszRadioText);
        MessageWriteString(sz: locale);
        MessageWriteString(sz: locale);
        MessageEnd();
      }
    }
    UserMessageBegin(&filter, messagename: "SendAudio");
    MessageWriteString(sz: pszRadioSound);
    MessageEnd();
    TE_RadioIcon(&filter, delay: 0.0, pPlayer: this);
    CRecipientFilter::~CRecipientFilter(this: &filter);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10281F00
// Name: public: void CCSPlayer::ListPlayers(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CCSPlayer::ListPlayers(CCSPlayer *this@<ecx>, int a2@<edi>)
{
  int v2; // ebx
  CBasePlayer *v3; // eax
  CBaseEntity *v4; // eax
  _DWORD *v5; // esi
  bool v6; // zf
  int (__thiscall *GetPlayerUserId)(IVEngineServer *, const edict_t *); // eax
  int v8; // edi
  int v9; // edi
  int v10; // [esp-Ch] [ebp-54h]
  int v11; // [esp-Ch] [ebp-54h]
  int v12; // [esp-8h] [ebp-50h]
  int v13; // [esp-8h] [ebp-50h]
  char buf[64]; // [esp+4h] [ebp-44h] BYREF
  CBasePlayer *player; // [esp+44h] [ebp-4h]

  v2 = 1;
  player = this;
  if ( gpGlobals->maxClients >= 1 )
  {
    v12 = a2;
    do
    {
      v3 = UTIL_PlayerByIndex(playerIndex: v2);
      v4 = (CBaseEntity *)__RTDynamicCast(
                            inptr: v3,
                            VfDelta: 0,
                            SrcType: &CBasePlayer `RTTI Type Descriptor',
                            TargetType: &CCSPlayer `RTTI Type Descriptor',
                            isReference: 0);
      v5 = &v4->__vftable;
      if ( v4 != nullptr && !CBaseEntity::IsDormant(this: v4) )
      {
        v6 = (*(unsigned __int8 (__thiscall **)(_DWORD *, int))(*v5 + 1912))(a1: v5, a2: v12) == 0;
        v13 = v5[6];
        GetPlayerUserId = engine->GetPlayerUserId;
        if ( v6 )
        {
          v9 = ((int (__cdecl *)(int))GetPlayerUserId)(a1: v13);
          v11 = (*(int (__thiscall **)(_DWORD *))(*v5 + 160))(a1: v5);
          V_snprintf(pDest: buf, maxLen: 64, pFormat: "  %d : %s", v9, v11);
        }
        else
        {
          v8 = ((int (__cdecl *)(int))GetPlayerUserId)(a1: v13);
          v10 = (*(int (__thiscall **)(_DWORD *))(*v5 + 160))(a1: v5);
          V_snprintf(pDest: buf, maxLen: 64, pFormat: "B %d : %s", v8, v10);
        }
        ClientPrint(
          player,
          msg_dest: 2u,
          msg_name: buf,
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
      }
      ++v2;
    }
    while ( v2 <= gpGlobals->maxClients );
  }
  ClientPrint(player, msg_dest: 2u, msg_name: "\n", param1: nullptr, param2: nullptr, param3: nullptr, param4: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10282000
// Name: private: void CCSPlayer::State_PreThink_WELCOME(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::State_PreThink_WELCOME(CCSPlayer *this)
{
  unsigned int m_Index; // edx

  m_Index = this->m_pIntroCamera.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr
    && gpGlobals->curtime >= this->m_fIntroCamTime )
  {
    CCSPlayer::MoveToNextIntroCamera(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10282050
// Name: public: virtual bool CCSPlayer::BumpWeapon(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSPlayer::BumpWeapon(CCSPlayer *this, CBaseCombatWeapon *pBaseWeapon)
{
  CBaseCombatWeapon *v3; // eax
  CWeaponCSBase *v4; // esi
  const CCSWeaponInfo *CSWpnData; // eax
  const char *pszValue; // eax
  CBaseCombatWeapon *v8; // eax
  int v9; // eax
  int v10; // ebx
  CCSAmmoDef *AmmoDef; // eax
  bool v12; // al
  CCSPlayer_vtbl *v13; // ebx
  int v14; // eax
  CCSPlayer *Donor; // ebx
  CCSWeaponInfo *v16; // eax
  int m_iExtraPrimaryAmmo; // ebx
  int v18; // eax
  IGameEvent *v19; // ebx
  int UserID; // eax
  IGameEvent *v21; // ebx
  IGameEvent_vtbl *v22; // esi
  int v23; // eax
  int numGrenades; // [esp+Ch] [ebp-8h]
  const char *numGrenadesa; // [esp+Ch] [ebp-8h]
  int numGrenadesb; // [esp+Ch] [ebp-8h]
  bool bPickupTaser; // [esp+13h] [ebp-1h]
  const char *weaponName; // [esp+1Ch] [ebp+8h]
  const char *weaponNamea; // [esp+1Ch] [ebp+8h]
  bool weaponName_3; // [esp+1Fh] [ebp+Bh]

  v3 = (CBaseCombatWeapon *)__RTDynamicCast(
                              inptr: pBaseWeapon,
                              VfDelta: 0,
                              SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
                              TargetType: &CWeaponCSBase `RTTI Type Descriptor',
                              isReference: 0);
  v4 = (CWeaponCSBase *)v3;
  if ( v3 == nullptr )
  {
    CCollisionProperty::SetSolidFlags(
      this: &pBaseWeapon->m_Collision,
      flags: pBaseWeapon->m_Collision.m_usSolidFlags.m_Value | 4);
    CBaseEntity::AddEffects(this: pBaseWeapon, nEffects: 32);
    this->Weapon_Equip(this, a2: pBaseWeapon);
    return 1;
  }
  if ( CBaseCombatWeapon::GetOwner(this: v3) != nullptr
    || !this->Weapon_CanUse(this, a2: v4)
    || !g_pGameRules->CanHavePlayerItem(this: g_pGameRules, a2: this, a3: v4) )
  {
    if ( gEvilImpulse101 != 0 )
      UTIL_Remove(oldObj: v4);
    return 0;
  }
  CSWpnData = CWeaponCSBase::GetCSWpnData(this: v4);
  weaponName_3 = CSWpnData->m_WeaponType == WEAPONTYPE_GRENADE;
  if ( CSWpnData->m_WeaponType == WEAPONTYPE_GRENADE )
  {
    pszValue = v4->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    v8 = this->Weapon_OwnsThisType(this, a2: pszValue, a3: 0);
    if ( v8 != nullptr )
    {
      numGrenades = 0;
      v9 = v8->GetPrimaryAmmoType(this: v8);
      v10 = v9;
      if ( v9 != -1 )
        numGrenades = CBaseCombatCharacter::GetAmmoCount(this, iAmmoIndex: v9);
      AmmoDef = GetAmmoDef();
      if ( numGrenades >= CAmmoDef::MaxCarry(this: AmmoDef, nAmmoIndex: v10, owner: this) )
        return 0;
    }
  }
  v12 = v4->GetCSWeaponID(this: v4) == WEAPON_TASER;
  bPickupTaser = v12;
  if ( v12 )
  {
    numGrenadesa = v4->m_iClassname.pszValue;
    if ( numGrenadesa == nullptr )
      numGrenadesa = locale;
    v13 = this->CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
    v14 = v4->GetSubType(this: v4);
    if ( v13->Weapon_OwnsThisType(this, a2: numGrenadesa, a3: v14) != nullptr )
      return 0;
    v12 = bPickupTaser;
  }
  if ( !weaponName_3 && !v12 && this->Weapon_SlotOccupied(this, a2: v4) )
    return 0;
  this->m_bPickedUpWeapon = true;
  v4->CheckRespawn(this: v4);
  CBaseEntity::AddSolidFlags(this: v4, flags: 4);
  CBaseEntity::AddEffects(this: v4, nEffects: 32);
  Donor = CWeaponCSBase::GetDonor(this: v4);
  if ( Donor != nullptr )
  {
    v16 = (CCSWeaponInfo *)CWeaponCSBase::GetCSWpnData(this: v4);
    if ( CCSWeaponInfo::GetWeaponPrice(this: v16) > this->m_iAccount.m_Value )
      CCSGameStats::Event_PlayerDonatedWeapon(this: &CCS_GameStats, pPlayer: Donor);
    v4->m_donor.m_Index = -1;
  }
  this->Weapon_Equip(this, a2: v4);
  m_iExtraPrimaryAmmo = v4->m_iExtraPrimaryAmmo;
  if ( m_iExtraPrimaryAmmo != 0 && !weaponName_3 )
  {
    v18 = v4->GetPrimaryAmmoType(this: v4);
    if ( v18 != -1 )
    {
      v4->m_iExtraPrimaryAmmo = 0;
      CBaseCombatCharacter::SetAmmoCount(this, iCount: m_iExtraPrimaryAmmo, iAmmoIndex: v18);
    }
  }
  if ( (unsigned __int8)CCSGameRules::IsPlayingGunGameSelect(this: (CCSGameRules *)g_pGameRules) != 0 )
  {
    v19 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "gg_select_item_pickup", a3: 0, a4: 0);
    if ( v19 != nullptr )
    {
      weaponName = v4->m_iClassname.pszValue;
      if ( weaponName == nullptr )
        weaponName = locale;
      numGrenadesb = (int)v19->__vftable;
      UserID = CBasePlayer::GetUserID(this);
      (*(void (__thiscall **)(IGameEvent *, const char *, int))(numGrenadesb + 44))(a1: v19, a2: "userid", a3: UserID);
      v19->SetString(this: v19, a2: "item", a3: weaponName);
      gameeventmanager->FireEvent(this: gameeventmanager, a2: v19, a3: false);
    }
  }
  v21 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "item_pickup", a3: 0, a4: 0);
  if ( v21 != nullptr )
  {
    weaponNamea = v4->m_iClassname.pszValue;
    if ( weaponNamea == nullptr )
      weaponNamea = locale;
    if ( strncmp(first: weaponNamea, last: "weapon_", count: 7u) == 0 )
      weaponNamea += 7;
    v22 = v21->__vftable;
    v23 = CBasePlayer::GetUserID(this);
    v22->SetInt(this: v21, a2: "userid", a3: v23);
    v21->SetString(this: v21, a2: "item", a3: weaponNamea);
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v21, a3: false);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102823A0
// Name: private: void CCSPlayer::BuildRebuyStruct(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CCSPlayer::BuildRebuyStruct(CCSPlayer *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  _DWORD *v4; // edi
  CBaseCombatWeapon *v5; // ebx
  const char *v6; // eax
  int v7; // eax
  const char *pszValue; // eax
  int v9; // eax
  CBaseCombatWeapon *v10; // eax
  CBaseCombatWeapon *v11; // edi
  int v12; // eax
  CBaseCombatWeapon *v13; // eax
  CBaseCombatWeapon *v14; // edi
  int v15; // eax
  CBaseCombatWeapon *v16; // eax
  CCSPlayer_vtbl *v17; // edx
  int v18; // eax
  CCSPlayer_vtbl *v19; // edx
  int v20; // eax
  bool m_Value; // cl
  bool v22; // dl

  if ( !this->m_bIsInRebuy )
  {
    v4 = (_DWORD *)((int (__thiscall *)(CCSPlayer *, _DWORD, int, int))this->Weapon_GetSlot)(
                     a1: this,
                     a2: 0,
                     a3,
                     a4: a2);
    v5 = this->Weapon_GetSlot(this, a2: 1);
    if ( v4 != nullptr )
    {
      v6 = (const char *)v4[23];
      if ( v6 == nullptr )
        v6 = locale;
      V_strncpy(pDest: this->m_rebuyStruct.m_szPrimaryWeapon, pSrc: v6 + 7, maxLen: 64);
      if ( (*(int (__thiscall **)(_DWORD *))(*v4 + 1352))(a1: v4) != -1 )
      {
        v7 = (*(int (__thiscall **)(_DWORD *))(*v4 + 1352))(a1: v4);
        this->m_rebuyStruct.m_primaryAmmo = CBaseCombatCharacter::GetAmmoCount(this, iAmmoIndex: v7);
      }
    }
    else
    {
      this->m_rebuyStruct.m_szPrimaryWeapon[0] = 0;
      this->m_rebuyStruct.m_primaryAmmo = 0;
    }
    if ( v5 != nullptr )
    {
      pszValue = v5->m_iClassname.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      V_strncpy(pDest: this->m_rebuyStruct.m_szSecondaryWeapon, pSrc: pszValue + 7, maxLen: 64);
      if ( v5->GetPrimaryAmmoType(this: v5) != -1 )
      {
        v9 = v5->GetPrimaryAmmoType(this: v5);
        this->m_rebuyStruct.m_secondaryAmmo = CBaseCombatCharacter::GetAmmoCount(this, iAmmoIndex: v9);
      }
    }
    else
    {
      this->m_rebuyStruct.m_szSecondaryWeapon[0] = 0;
      this->m_rebuyStruct.m_secondaryAmmo = 0;
    }
    v10 = this->Weapon_OwnsThisType(this, a2: "weapon_hegrenade", a3: 0);
    v11 = v10;
    if ( v10 == nullptr || v10->GetPrimaryAmmoType(this: v10) == -1 )
    {
      this->m_rebuyStruct.m_heGrenade = 0;
    }
    else
    {
      v12 = v11->GetPrimaryAmmoType(this: v11);
      this->m_rebuyStruct.m_heGrenade = CBaseCombatCharacter::GetAmmoCount(this, iAmmoIndex: v12);
    }
    v13 = this->Weapon_OwnsThisType(this, a2: "weapon_flashbang", a3: 0);
    v14 = v13;
    if ( v13 == nullptr || v13->GetPrimaryAmmoType(this: v13) == -1 )
    {
      this->m_rebuyStruct.m_flashbang = 0;
    }
    else
    {
      v15 = v14->GetPrimaryAmmoType(this: v14);
      this->m_rebuyStruct.m_flashbang = CBaseCombatCharacter::GetAmmoCount(this, iAmmoIndex: v15);
    }
    v16 = this->Weapon_OwnsThisType(this, a2: "weapon_smokegrenade", a3: 0);
    v17 = this->CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
    this->m_rebuyStruct.m_smokeGrenade = v16 != nullptr;
    v18 = (int)v17->Weapon_OwnsThisType(this, a2: "weapon_molotov", a3: 0);
    v19 = this->CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
    this->m_rebuyStruct.m_molotovGrenade = v18 != 0;
    v20 = (int)v19->Weapon_OwnsThisType(this, a2: "weapon_decoy", a3: 0);
    m_Value = this->m_bHasDefuser.m_Value;
    v22 = this->m_bHasNightVision.m_Value;
    this->m_rebuyStruct.m_decoyGrenade = v20 != 0;
    this->m_rebuyStruct.m_defuser = m_Value;
    this->m_rebuyStruct.m_nightVision = v22;
    if ( this->m_bHasHelmet.m_Value )
      this->m_rebuyStruct.m_armor = 2;
    else
      this->m_rebuyStruct.m_armor = this->m_ArmorValue.m_Value > 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102825D0
// Name: public: virtual void CCSPlayer::CreateViewModel(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::CreateViewModel(CCSPlayer *this, unsigned int index)
{
  int v2; // ebx
  CBaseViewModel *EntityByName; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  v2 = index;
  if ( CBasePlayer::GetViewModel(this, index) == nullptr )
  {
    EntityByName = (CBaseViewModel *)CreateEntityByName(
                                       className: "predicted_viewmodel",
                                       iForceEdictIndex: -1,
                                       bNotify: true);
    if ( EntityByName != nullptr )
    {
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      CBaseEntity::SetAbsOrigin(this: EntityByName, absOrigin: &this->m_vecAbsOrigin);
      CBaseViewModel::SetOwner(this: EntityByName, pEntity: this);
      CBaseViewModel::SetIndex(this: EntityByName, nIndex: v2);
      DispatchSpawn(pEntity: EntityByName, bRunVScripts: true);
      CBaseEntity::FollowEntity(this: EntityByName, pBaseEntity: this, bBoneMerge: false);
      index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
      CBasePlayer::NetworkVar_m_hViewModel::Set(
        this: &this->m_hViewModel,
        i: v2,
        val: (const CHandle<CBaseViewModel> *)&index);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10282670
// Name: public: virtual int CCSPlayer::GetNextObserverSearchStartPoint(bool)
// Source: json
//------------------------------------------------------------------------------
edict_t *__thiscall CCSPlayer::GetNextObserverSearchStartPoint(CCSPlayer *this, bool bReverse)
{
  unsigned int v3; // eax
  CBaseEntity *v4; // ecx
  CCSBot *NearestControllableBot; // eax
  edict_t *result; // eax
  unsigned int m_Index; // ecx
  int v8; // eax
  CEntInfo *v9; // edx
  unsigned int v10; // ecx
  int v11; // eax
  bool v12; // zf
  CEntInfo *v13; // eax
  IHandleEntity *v14; // eax
  unsigned int v15; // eax
  CEntInfo *v16; // ecx
  IHandleEntity *m_pEntity; // esi
  void *v18; // esi

  if ( cv_bot_controllable.m_pParent != nullptr
    && cv_bot_controllable.m_pParent->m_Value.m_nValue != 0
    && ((v3 = this->m_hObserverTarget.m_Value.m_Index) == -1
     || g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_SerialNumber != HIWORD(v3)
      ? (v4 = nullptr)
      : (v4 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_pEntity),
        !this->IsValidObserverTarget(this, a2: v4)
     && (NearestControllableBot = CCSPlayer::FindNearestControllableBot(this, bMustBeValidObserverTarget: true)) != nullptr) )
  {
    result = NearestControllableBot->m_Network.m_pPev;
    if ( result != nullptr )
      return (edict_t *)(result - gpGlobals->pEdicts);
  }
  else
  {
    m_Index = this->m_hObserverTarget.m_Value.m_Index;
    if ( m_Index == -1 )
      return (edict_t *)CBasePlayer::GetNextObserverSearchStartPoint(this, bReverse);
    v8 = (unsigned __int16)m_Index;
    v9 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v10 = HIWORD(m_Index);
    if ( v9->m_SerialNumber != v10 || v9->m_pEntity == nullptr )
      return (edict_t *)CBasePlayer::GetNextObserverSearchStartPoint(this, bReverse);
    v11 = v8;
    v12 = g_pEntityList->m_EntPtrArray[v11].m_SerialNumber == v10;
    v13 = &g_pEntityList->m_EntPtrArray[v11];
    v14 = v12 ? v13->m_pEntity : nullptr;
    if ( v14->__vftable[22].GetRefEHandle(this: v14) == nullptr
      && (v15 = this->m_hObserverTarget.m_Value.m_Index) != -1
      && (v16 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v15],
          g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_SerialNumber == HIWORD(v15))
      && (m_pEntity = v16->m_pEntity, v16->m_pEntity != nullptr)
      && ((unsigned __int8 (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[28].dtr_IHandleEntity)(a1: v16->m_pEntity) != 0
      && (v18 = __RTDynamicCast(
                  inptr: m_pEntity,
                  VfDelta: 0,
                  SrcType: &CBaseEntity `RTTI Type Descriptor',
                  TargetType: &CCSPlayer `RTTI Type Descriptor',
                  isReference: 0)) != nullptr
      && (*(int (__thiscall **)(void *))(*(_DWORD *)v18 + 1620))(a1: v18) != 0 )
    {
      result = *(edict_t **)((*(int (__thiscall **)(void *))(*(_DWORD *)v18 + 1620))(a1: v18) + 24);
      if ( result != nullptr )
        return (edict_t *)(result - gpGlobals->pEdicts);
    }
    else
    {
      return (edict_t *)CBasePlayer::GetNextObserverSearchStartPoint(this, bReverse);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10282800
// Name: public: virtual void CCSPlayer::PlayStepSound(class Vector __near &,struct surfacedata_t __near *,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::PlayStepSound(
        CCSPlayer *this,
        Vector *vecOrigin,
        surfacedata_t *psurface,
        float fvol,
        bool force)
{
  IGameEvent *v6; // esi
  int v7; // eax

  CBasePlayer::PlayStepSound(this, vecOrigin, psurface, fvol, force);
  if ( sv_footsteps.m_pParent->m_Value.m_fValue != 0.0 && psurface != nullptr )
  {
    ++this->m_iFootsteps;
    v6 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_footstep", a3: 0, a4: 0);
    if ( v6 != nullptr )
    {
      v7 = engine->GetPlayerUserId(this: engine, a2: this->m_Network.m_pPev);
      v6->SetInt(this: v6, a2: "userid", a3: v7);
      gameeventmanager->FireEvent(this: gameeventmanager, a2: v6, a3: false);
    }
    this->m_bMadeFootstepNoise = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102828A0
// Name: public: void CCSPlayer::ChangeName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::ChangeName(CCSPlayer *this, const char *pszNewName)
{
  const char *v3; // ebx
  IGameEvent *v4; // esi
  int v5; // eax
  char trimmedName[32]; // [esp+Ch] [ebp-40h] BYREF
  CReliableBroadcastRecipientFilter filter; // [esp+2Ch] [ebp-20h] BYREF

  V_strncpy(pDest: trimmedName, pSrc: pszNewName, maxLen: 32);
  v3 = this->GetPlayerName(this);
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CReliableBroadcastRecipientFilter_vtbl *)&CBroadcastRecipientFilter::`vftable';
  CRecipientFilter::AddAllPlayers(this: &filter);
  filter.__vftable = (CReliableBroadcastRecipientFilter_vtbl *)&CReliableBroadcastRecipientFilter::`vftable';
  CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&filter);
  UTIL_SayText2Filter(
    &filter,
    pEntity: this,
    bChat: false,
    msg_name: "#Cstrike_Name_Change",
    param1: v3,
    param2: trimmedName,
    param3: nullptr,
    param4: nullptr);
  v4 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_changename", a3: 0, a4: 0);
  if ( v4 != nullptr )
  {
    v5 = engine->GetPlayerUserId(this: engine, a2: this->m_Network.m_pPev);
    v4->SetInt(this: v4, a2: "userid", a3: v5);
    v4->SetString(this: v4, a2: "oldname", a3: v3);
    v4->SetString(this: v4, a2: "newname", a3: trimmedName);
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v4, a3: false);
  }
  CBasePlayer::SetPlayerName(this, name: trimmedName);
  engine->ClientCommand(this: engine, a2: this->m_Network.m_pPev, a3: "name \"%s\"", trimmedName);
  this->m_flNameChangeHistory[4] = this->m_flNameChangeHistory[3];
  this->m_flNameChangeHistory[3] = this->m_flNameChangeHistory[2];
  this->m_flNameChangeHistory[2] = this->m_flNameChangeHistory[1];
  this->m_flNameChangeHistory[1] = this->m_flNameChangeHistory[0];
  this->m_flNameChangeHistory[0] = gpGlobals->curtime;
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x10282A00
// Name: protected: void CCSPlayer::SendGunGameWeaponUpgradeAlert(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::SendGunGameWeaponUpgradeAlert(CCSPlayer *this)
{
  IGameEvent *v2; // esi
  int v3; // eax

  v2 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "gg_player_impending_upgrade", a3: 0, a4: 0);
  if ( v2 != nullptr )
  {
    v3 = engine->GetPlayerUserId(this: engine, a2: this->m_Network.m_pPev);
    v2->SetInt(this: v2, a2: "userid", a3: v3);
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v2, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10282A60
// Name: public: void CCSPlayer::SetPlayerDominatingMe(class CCSPlayer __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::SetPlayerDominatingMe(CCSPlayer *this, CCSPlayer *pPlayer, bool bDominated)
{
  edict_t *m_pPev; // eax
  signed int v4; // edi
  CCSPlayer::NetworkVar_m_bPlayerDominatingMe *p_m_bPlayerDominatingMe; // esi
  edict_t *v6; // ecx

  m_pPev = pPlayer->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    v4 = m_pPev - gpGlobals->pEdicts;
  else
    v4 = 0;
  p_m_bPlayerDominatingMe = &this->m_bPlayerDominatingMe;
  if ( bDominated != this->m_bPlayerDominatingMe.m_Value[v4] )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bPlayerDominatingMe->m_Value[v4] = bDominated;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: v4 + 6806);
      p_m_bPlayerDominatingMe->m_Value[v4] = bDominated;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10282AD0
// Name: public: void CCSPlayer::IncrementNumMVPs(enum CSMvpReason_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::IncrementNumMVPs(CCSPlayer *this, CSMvpReason_t mvpReason)
{
  IGameEvent *v3; // esi
  int v4; // eax

  if ( sv_nomvp.m_pParent != nullptr && sv_nomvp.m_pParent->m_Value.m_nValue != 0 )
  {
    _Msg(a1: "Round MVP disabled: sv_nomvp is set.\n");
  }
  else
  {
    ++this->m_iMVPs;
    CCSGameStats::Event_MVPEarned(this: &CCS_GameStats, pPlayer: this);
    v3 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "round_mvp", a3: 0, a4: 0);
    if ( v3 != nullptr )
    {
      v4 = engine->GetPlayerUserId(this: engine, a2: this->m_Network.m_pPev);
      v3->SetInt(this: v3, a2: "userid", a3: v4);
      v3->SetInt(this: v3, a2: "reason", a3: mvpReason);
      gameeventmanager->FireEvent(this: gameeventmanager, a2: v3, a3: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10282B70
// Name: public: void CCSPlayer::UpdateLeader(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::UpdateLeader(CCSPlayer *this)
{
  int v2; // edi
  CBasePlayer *v3; // esi
  CCSPlayer *v4; // eax
  IGameEvent *v5; // esi
  int v6; // eax
  int TeamNumber; // eax
  int (*GetNoResetVoteThresholdForCurrentModeCT)(void); // eax
  int v9; // eax

  v2 = 1;
  while ( 1 )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: v2);
    if ( v3 != nullptr && v3->IsPlayer(this: v3) )
    {
      v4 = (CCSPlayer *)__RTDynamicCast(
                          inptr: v3,
                          VfDelta: 0,
                          SrcType: &CBaseEntity `RTTI Type Descriptor',
                          TargetType: &CCSPlayer `RTTI Type Descriptor',
                          isReference: 0);
      if ( v4 != nullptr
        && v4 != this
        && this->m_iGunGameProgressiveWeaponIndex.m_Value <= v4->m_iGunGameProgressiveWeaponIndex.m_Value )
      {
        break;
      }
    }
    if ( ++v2 > 64 )
    {
      v5 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "gg_leader", a3: 0, a4: 0);
      if ( v5 != nullptr )
      {
        v6 = engine->GetPlayerUserId(this: engine, a2: this->m_Network.m_pPev);
        v5->SetInt(this: v5, a2: "playerid", a3: v6);
        gameeventmanager->FireEvent(this: gameeventmanager, a2: v5, a3: false);
      }
      TeamNumber = CBaseEntity::GetTeamNumber(this);
      if ( TeamNumber == 3 )
      {
        GetNoResetVoteThresholdForCurrentModeCT = (int (*)(void))g_pGameTypes->GetNoResetVoteThresholdForCurrentModeCT;
      }
      else
      {
        if ( TeamNumber != 2 )
          return;
        GetNoResetVoteThresholdForCurrentModeCT = (int (*)(void))g_pGameTypes->GetNoResetVoteThresholdForCurrentModeT;
      }
      v9 = GetNoResetVoteThresholdForCurrentModeCT();
      if ( v9 != -1 && this->m_iGunGameProgressiveWeaponIndex.m_Value >= v9 )
        CCSGameRules::SetRestartVotingEnabled(this: (CCSGameRules *)g_pGameRules, enabled: false);
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10282C70
// Name: public: class CBaseEntity const __near * CNetworkHandleBase<class CBaseEntity,class CCSPlayer::NetworkVar_m_hRagdoll>::Set(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
const CBaseEntity *__thiscall CNetworkHandleBase<CBaseEntity,CCSPlayer::NetworkVar_m_hRagdoll>::Set(
        CNetworkHandleBase<CBaseEntity,CCSPlayer::NetworkVar_m_hRagdoll> *this,
        const CBaseEntity *val)
{
  unsigned int m_Index; // eax
  const CBaseEntity *m_pEntity; // ecx
  CNetworkHandleBase<CBaseEntity,CCSPlayer::NetworkVar_m_hRagdoll> *v5; // eax
  CBaseEdict *v6; // ecx

  m_Index = this->m_Value.m_Index;
  if ( this->m_Value.m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (const CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  }
  if ( m_pEntity != val )
  {
    v5 = this - 1526;
    if ( *((_BYTE *)this - 6020) != 0 )
    {
      LOBYTE(v5[22].m_Value.m_Index) |= 1u;
    }
    else
    {
      v6 = (CBaseEdict *)v5[6].m_Value.m_Index;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0x17D8u);
    }
    if ( val != nullptr )
    {
      this->m_Value.m_Index = val->GetRefEHandle(this: val)->m_Index;
      return val;
    }
    this->m_Value.m_Index = -1;
  }
  return val;
}

//------------------------------------------------------------------------------
// Address: 0x10282D00
// Name: public: class CBaseEntity const __near * CNetworkHandleBase<class CBaseEntity,class CCSRagdoll::NetworkVar_m_hPlayer>::Set(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
const CBaseEntity *__thiscall CNetworkHandleBase<CBaseEntity,CCSRagdoll::NetworkVar_m_hPlayer>::Set(
        CNetworkHandleBase<CBaseEntity,CCSRagdoll::NetworkVar_m_hPlayer> *this,
        const CBaseEntity *val)
{
  unsigned int m_Index; // eax
  const CBaseEntity *m_pEntity; // ecx
  CNetworkHandleBase<CBaseEntity,CCSRagdoll::NetworkVar_m_hPlayer> *v5; // eax
  CBaseEdict *v6; // ecx

  m_Index = this->m_Value.m_Index;
  if ( this->m_Value.m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (const CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  }
  if ( m_pEntity != val )
  {
    v5 = this - 296;
    if ( *((_BYTE *)this - 1100) != 0 )
    {
      LOBYTE(v5[22].m_Value.m_Index) |= 1u;
    }
    else
    {
      v6 = (CBaseEdict *)v5[6].m_Value.m_Index;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0x4A0u);
    }
    if ( val != nullptr )
    {
      this->m_Value.m_Index = val->GetRefEHandle(this: val)->m_Index;
      return val;
    }
    this->m_Value.m_Index = -1;
  }
  return val;
}

//------------------------------------------------------------------------------
// Address: 0x10283590
// Name: public: void CCSRagdoll::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CCSRagdoll::Init(CCSRagdoll *this@<ecx>, int a2@<ebp>)
{
  const CViewVectors *v3; // eax
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // edi
  unsigned int v6; // eax
  CBaseEntity *v7; // edi
  unsigned int v8; // eax
  CBaseEntity *v9; // ecx
  CCSRagdoll_vtbl *v10; // edi
  int TeamNumber; // eax
  Vector *flFriction; // [esp+0h] [ebp-10h]

  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BBOX);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_STEP, moveCollide: MOVECOLLIDE_DEFAULT);
  CBaseEntity::SetFriction(this, flFriction: 1.0);
  flFriction = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vDuckHullMax;
  v3 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  CBaseEntity::SetCollisionBounds(this, mins: &v3->m_vDuckHullMin, maxs: flFriction);
  if ( this->m_takedamage.m_Value != 0 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    this->m_takedamage.m_Value = 0;
  }
  CBaseEntity::SetCollisionGroup(this, collisionGroup: 1);
  m_Index = this->m_hPlayer.m_Value.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( (m_pEntity->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: m_pEntity, a2);
  CBaseEntity::SetAbsOrigin(this, absOrigin: &m_pEntity->m_vecAbsOrigin);
  v6 = this->m_hPlayer.m_Value.m_Index;
  if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
    v7 = nullptr;
  else
    v7 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
  if ( (v7->m_iEFlags & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this: v7, a2);
  CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &v7->m_vecAbsVelocity);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  v8 = this->m_hPlayer.m_Value.m_Index;
  if ( v8 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber != HIWORD(v8) )
    v9 = nullptr;
  else
    v9 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_pEntity;
  v10 = this->__vftable;
  TeamNumber = CBaseEntity::GetTeamNumber(this: v9);
  v10->ChangeTeam(this, a2: TeamNumber);
  CBaseAnimating::UseClientSideAnimation(this);
}

//------------------------------------------------------------------------------
// Address: 0x10283720
// Name: public: void CCSPlayer::CheckAndAwardAssists(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::CheckAndAwardAssists(CCSPlayer *this, CCSPlayer *pCSVictim)
{
  int m_Head; // eax
  float m_iDamage; // xmm1_4
  UtlLinkedListElem_t<CDamageRecord *,int> *m_pMemory; // ebx
  int v6; // eax
  CDamageRecord *m_Element; // esi
  UtlLinkedListElem_t<CDamageRecord *,int> *v8; // edi
  unsigned int m_Index; // eax
  CCSPlayer *m_pEntity; // edx
  CCSPlayer *maxDamagePlayer; // [esp+Ch] [ebp+8h]

  m_Head = pCSVictim->m_DamageTakenList.m_Head;
  m_iDamage = 0.0;
  maxDamagePlayer = nullptr;
  if ( m_Head != -1 )
  {
    m_pMemory = pCSVictim->m_DamageTakenList.m_Memory.m_pMemory;
    do
    {
      v6 = m_Head;
      m_Element = m_pMemory[v6].m_Element;
      v8 = &m_pMemory[v6];
      m_Index = m_Element->m_PlayerHandle.m_Index;
      if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
      {
        m_pEntity = (CCSPlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
        if ( m_pEntity != nullptr && (float)m_Element->m_iDamage > m_iDamage && m_pEntity != this )
        {
          m_iDamage = (float)m_Element->m_iDamage;
          maxDamagePlayer = (CCSPlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
        }
      }
      m_Head = v8->m_Next;
    }
    while ( m_Head != -1 );
  }
  if ( m_iDamage > cs_AssistDamageThreshold.m_pParent->m_Value.m_fValue )
    CCSGameRules::ScorePlayerAssist(this: (CCSGameRules *)g_pGameRules, pPlayer: maxDamagePlayer);
}

//------------------------------------------------------------------------------
// Address: 0x102837D0
// Name: public: virtual void CCSPlayer::TraceAttack(class CTakeDamageInfo const __near &,class Vector const __near &,class CGameTrace __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::TraceAttack(
        CCSPlayer *this,
        const CTakeDamageInfo *info,
        const Vector *vecDir,
        CGameTrace *ptr)
{
  unsigned int m_Index; // eax
  CEntInfo *v6; // ecx
  CBaseEntity *m_pEntity; // esi
  int TeamNumber; // esi
  CGameTrace *v9; // ecx
  float v10; // edx
  edict_t *m_pPev; // ecx
  bool v12; // zf
  float m_flDamage; // xmm0_4
  int m_bitsDamageType; // eax
  bool m_Value; // al
  double v16; // st7
  float v17; // xmm0_4
  float v18; // xmm0_4
  bool v19; // cc
  CNetworkVectorBase<QAngle,CPlayerLocalData::NetworkVar_m_vecPunchAngle> *v20; // eax
  float z; // eax
  float v22; // xmm0_4
  IPredictionSystem *i; // eax
  float v24; // xmm2_4
  float v25; // xmm0_4
  float y; // xmm1_4
  CBaseEntity *m_pEnt; // edx
  float v28; // xmm0_4
  edict_t *v29; // edx
  float v30; // xmm0_4
  IPredictionSystem *j; // eax
  CTakeDamageInfo subInfo; // [esp+18h] [ebp-78h] BYREF
  char v33; // [esp+74h] [ebp-1Ch]
  QAngle punchAngle; // [esp+7Ch] [ebp-14h] BYREF
  float flDamage; // [esp+88h] [ebp-8h]
  bool bHeadShot; // [esp+8Dh] [ebp-3h]
  bool bShouldSpark; // [esp+8Eh] [ebp-2h]
  bool bShouldBleed; // [esp+8Fh] [ebp-1h]

  m_Index = info->m_hAttacker.m_Index;
  bShouldBleed = true;
  bShouldSpark = false;
  if ( m_Index != -1 )
  {
    v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    {
      m_pEntity = (CBaseEntity *)v6->m_pEntity;
      if ( v6->m_pEntity != nullptr && m_pEntity->IsPlayer(this: (CBaseEntity *)v6->m_pEntity) )
      {
        TeamNumber = CBaseEntity::GetTeamNumber(this: m_pEntity);
        if ( CBaseEntity::GetTeamNumber(this) == TeamNumber )
          bShouldBleed = CCSBotManager::AllowFriendlyFireDamage(this: (CCSGameRules *)g_pGameRules);
      }
    }
  }
  if ( this->m_takedamage.m_Value == 2 )
  {
    v9 = ptr;
    this->m_LastHitGroup = ptr->hitgroup;
    LODWORD(v10) = ptr->physicsbone;
    flDamage = v10;
    if ( this->m_nForceBone.m_Value != LODWORD(v10) )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
        {
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x35Cu);
          v10 = flDamage;
        }
      }
      v9 = ptr;
      *(float *)&this->m_nForceBone.m_Value = v10;
    }
    v12 = !this->m_bGunGameImmunity.m_Value;
    m_flDamage = info->m_flDamage;
    flDamage = m_flDamage;
    bHeadShot = false;
    if ( !v12 )
    {
      bShouldBleed = false;
      goto $LN244_0;
    }
    m_bitsDamageType = info->m_bitsDamageType;
    if ( (m_bitsDamageType & 0x100) != 0 )
    {
      bShouldBleed = false;
      goto $LN244_0;
    }
    if ( (m_bitsDamageType & 0x40) != 0 )
    {
      if ( this->m_ArmorValue.m_Value <= 0 )
      {
        if ( bShouldBleed )
        {
LABEL_40:
          v20 = CBasePlayer::GetPunchAngle(this);
          *(_QWORD *)&punchAngle.x = *(_QWORD *)&v20->m_Value.x;
          z = v20->m_Value.z;
          v22 = flDamage * -0.1;
          punchAngle.x = v22;
          punchAngle.z = z;
          if ( v22 < -4.0 )
            punchAngle.x = -4.0;
LABEL_38:
          CBasePlayer::SetPunchAngle(this, &punchAngle);
        }
      }
      else
      {
        bShouldBleed = false;
      }
      goto $LN244_0;
    }
    switch ( v9->hitgroup )
    {
      case 1:
        m_Value = this->m_bHasHelmet.m_Value;
        if ( m_Value )
          bShouldSpark = true;
        flDamage = m_flDamage * 4.0;
        if ( m_Value )
          goto LABEL_34;
        punchAngle = CBasePlayer::GetPunchAngle(this)->m_Value;
        punchAngle.x = flDamage * -0.5;
        if ( (float)(flDamage * -0.5) < -12.0 )
          punchAngle.x = -12.0;
        v16 = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                a1: random,
                a2: -1082130432,
                a3: 1065353216)
            * flDamage;
        punchAngle.z = v16;
        if ( v16 >= -9.0 )
        {
          v17 = 9.0;
          if ( punchAngle.z <= 9.0 )
            goto LABEL_33;
        }
        else
        {
          v17 = -9.0;
        }
        punchAngle.z = v17;
LABEL_33:
        CBasePlayer::SetPunchAngle(this, &punchAngle);
LABEL_34:
        bHeadShot = true;
$LN244_0:
        for ( i = IPredictionSystem::g_pPredictionSystems; i != nullptr; i = i->m_pNextSystem )
          ++i->m_nStatusPushed;
        if ( bShouldBleed )
        {
          CBaseEntity::TraceBleed(this, flDamage, vecDir, ptr, bitsDamageType: info->m_bitsDamageType);
          v24 = vecDir->z;
          memset((void *)&subInfo.m_vecDamagePosition, 0, sizeof(subInfo.m_vecDamagePosition));
          memset(&subInfo.m_hInflictor, 0, 20);
          memset(&subInfo.m_bitsDamageType, 0, 14);
          subInfo.m_vecDamageForce.x = ptr->endpos.x;
          subInfo.m_vecDamageForce.y = ptr->endpos.y;
          v25 = ptr->endpos.z;
          subInfo.m_flBaseDamage = 1.0;
          y = vecDir->y;
          m_pEnt = ptr->m_pEnt;
          subInfo.m_vecDamageForce.z = v25;
          v28 = vecDir->x * -1.0;
          memset(&subInfo.m_flRadius, 0, 16);
          v33 = 0;
          subInfo.m_vecReportedPosition.x = v28;
          subInfo.m_vecReportedPosition.y = y * -1.0;
          subInfo.m_vecReportedPosition.z = v24 * -1.0;
          if ( m_pEnt != nullptr )
          {
            v29 = m_pEnt->m_Network.m_pPev;
            if ( v29 != nullptr )
              LODWORD(subInfo.m_flMaxDamage) = v29 - gpGlobals->pEdicts;
            else
              subInfo.m_flMaxDamage = 0.0;
          }
          else
          {
            subInfo.m_flMaxDamage = 0.0;
          }
          v30 = flDamage;
          *(float *)&subInfo.m_bitsDamageType = flDamage;
          if ( this->m_ArmorValue.m_Value > 0 )
          {
            v30 = flDamage * 0.5;
            *(float *)&subInfo.m_bitsDamageType = flDamage * 0.5;
          }
          if ( ptr->hitgroup == 1 && bShouldSpark )
            *(float *)&subInfo.m_bitsDamageType = v30 * 0.5;
          DispatchEffect(pName: "csblood", data: (const CEffectData *)&subInfo);
        }
        if ( ptr->hitgroup == 1 && bShouldSpark )
          g_pEffects->Sparks(this: g_pEffects, a2: &ptr->endpos, a3: 1, a4: 1, a5: (const Vector *)&ptr->plane);
        CTakeDamageInfo::CTakeDamageInfo(this: (CTakeDamageInfo *)&subInfo.m_vecDamageForce.z, __that: info);
        subInfo.m_flBaseDamage = flDamage;
        if ( bHeadShot )
          subInfo.m_iDamageStats |= 0x40000000u;
        AddMultiDamage(info: (CTakeDamageInfo *)&subInfo.m_vecDamageForce.z, pEntity: this);
        for ( j = IPredictionSystem::g_pPredictionSystems; j != nullptr; j = j->m_pNextSystem )
          --j->m_nStatusPushed;
        return;
      case 2:
        if ( this->m_ArmorValue.m_Value <= 0 )
        {
          punchAngle = CBasePlayer::GetPunchAngle(this)->m_Value;
          v18 = flDamage * -0.1;
          punchAngle.x = v18;
          if ( v18 < -4.0 )
            punchAngle.x = -4.0;
          goto LABEL_38;
        }
        goto $LN244_0;
      case 3:
        v19 = this->m_ArmorValue.m_Value <= 0;
        flDamage = m_flDamage * 1.25;
        if ( v19 )
          goto LABEL_40;
        goto $LN244_0;
      case 6:
      case 7:
        flDamage = m_flDamage * 0.75;
        goto $LN244_0;
      default:
        goto $LN244_0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10283CA0
// Name: public: virtual void CCSPlayer::PreThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CCSPlayer::PreThink(CCSPlayer *this@<ecx>, int a2@<ebp>)
{
  int m_nButtons; // eax
  CCSPlayerStateInfo *m_pCurStateInfo; // eax
  void (__thiscall *pfnPreThink)(char *); // edx
  CHintMessageQueue *m_pHintMessageQueue; // ecx
  const char *v7; // eax
  IVEngineServer_vtbl *v8; // edi
  int UserID; // eax
  char *v10; // eax
  CNavArea *NavArea; // eax
  unsigned int m_place; // eax
  const char *v13; // eax
  CBasePlayer::NetworkVar_m_szLastPlaceName *v14; // eax
  const char *v15; // [esp+0h] [ebp-Ch]

  CBasePlayer::PreThink(this);
  if ( this->m_bAutoReload )
  {
    this->m_nButtons |= 0x2000u;
    this->m_bAutoReload = false;
  }
  m_nButtons = this->m_nButtons;
  if ( (m_nButtons & 1) != 0 )
  {
    if ( !this->m_triggerPulled )
    {
      ++this->m_triggerPulls;
      this->m_triggerPulled = true;
    }
  }
  else
  {
    this->m_triggerPulled = false;
  }
  if ( this->m_afButtonLast != m_nButtons )
    this->m_flLastMovement = gpGlobals->curtime;
  if ( !g_fGameOver )
  {
    m_pCurStateInfo = this->m_pCurStateInfo;
    if ( m_pCurStateInfo != nullptr )
    {
      pfnPreThink = (void (__thiscall *)(char *))m_pCurStateInfo->pfnPreThink;
      if ( pfnPreThink != nullptr )
        pfnPreThink(a1: (char *)this + DWORD1(m_pCurStateInfo->pfnPreThink));
    }
    m_pHintMessageQueue = this->m_pHintMessageQueue;
    if ( m_pHintMessageQueue != nullptr )
      CHintMessageQueue::Update(this: m_pHintMessageQueue);
    this->m_vecTotalBulletForce = vec3_origin;
    if ( mp_autokick.m_pParent != nullptr
      && mp_autokick.m_pParent->m_Value.m_nValue != 0
      && !this->IsBot(this)
      && !this->pl.hltv
      && !this->m_autoKickDisabled
      && gpGlobals->curtime > (float)((float)(2 * (int)g_pGameRules[46].m_pszName) + this->m_flLastMovement) )
    {
      v7 = this->GetPlayerName(this);
      UTIL_ClientPrintAll(
        msg_dest: 2u,
        msg_name: "#Game_idle_kick",
        param1: v7,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      v8 = engine->__vftable;
      UserID = CBasePlayer::GetUserID(this);
      v10 = UTIL_VarArgs(format: "kickid %d %s\n", UserID, "Player idle");
      v8->ServerCommand(this: engine, a2: v10);
      this->m_flLastMovement = gpGlobals->curtime;
    }
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2);
    NavArea = CNavMesh::GetNavArea(this: TheNavMesh, pos: &this->m_vecAbsOrigin, beneathLimit: 1000.0);
    if ( NavArea != nullptr && NavArea != this->m_lastNavArea )
    {
      this->m_lastNavArea = NavArea;
      m_place = NavArea->m_place;
      if ( m_place != 0 )
      {
        v13 = CNavMesh::PlaceToName(this: TheNavMesh, place: m_place);
        if ( v13 != nullptr && *v13 != 0 )
        {
          v15 = v13;
          v14 = CBasePlayer::NetworkVar_m_szLastPlaceName::GetForModify(this: &this->m_szLastPlaceName);
          V_strncpy(pDest: v14->m_Value, pSrc: v15, maxLen: 18);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10283EC0
// Name: public: void CCSPlayer::HandleMenu_Radio1(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::HandleMenu_Radio1(CCSPlayer *this, int slot)
{
  int m_iRadioMessages; // eax
  IGameEvent *v4; // esi
  int v5; // eax

  m_iRadioMessages = this->m_iRadioMessages;
  if ( m_iRadioMessages >= 0 && this->m_flRadioTime <= gpGlobals->curtime )
  {
    this->m_iRadioMessages = m_iRadioMessages - 1;
    this->m_flRadioTime = gpGlobals->curtime + 1.5;
    switch ( slot )
    {
      case 1:
        CCSPlayer::Radio(this, pszRadioSound: "Radio.CoverMe", pszRadioText: "#Cstrike_TitlesTXT_Cover_me");
        break;
      case 2:
        CCSPlayer::Radio(
          this,
          pszRadioSound: "Radio.YouTakeThePoint",
          pszRadioText: "#Cstrike_TitlesTXT_You_take_the_point");
        break;
      case 3:
        CCSPlayer::Radio(
          this,
          pszRadioSound: "Radio.HoldPosition",
          pszRadioText: "#Cstrike_TitlesTXT_Hold_this_position");
        break;
      case 4:
        CCSPlayer::Radio(this, pszRadioSound: "Radio.Regroup", pszRadioText: "#Cstrike_TitlesTXT_Regroup_team");
        break;
      case 5:
        CCSPlayer::Radio(this, pszRadioSound: "Radio.FollowMe", pszRadioText: "#Cstrike_TitlesTXT_Follow_me");
        break;
      case 6:
        CCSPlayer::Radio(this, pszRadioSound: "Radio.TakingFire", pszRadioText: "#Cstrike_TitlesTXT_Taking_fire");
        break;
      default:
        break;
    }
    v4 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_radio", a3: 0, a4: 0);
    if ( v4 != nullptr )
    {
      v5 = engine->GetPlayerUserId(this: engine, a2: this->m_Network.m_pPev);
      v4->SetInt(this: v4, a2: "userid", a3: v5);
      v4->SetInt(this: v4, a2: "slot", a3: slot + 1);
      gameeventmanager->FireEvent(this: gameeventmanager, a2: v4, a3: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10283FF0
// Name: public: void CCSPlayer::HandleMenu_Radio2(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::HandleMenu_Radio2(CCSPlayer *this, int slot)
{
  int m_iRadioMessages; // eax
  IGameEvent *v4; // esi
  int v5; // eax

  m_iRadioMessages = this->m_iRadioMessages;
  if ( m_iRadioMessages >= 0 && this->m_flRadioTime <= gpGlobals->curtime )
  {
    this->m_iRadioMessages = m_iRadioMessages - 1;
    this->m_flRadioTime = gpGlobals->curtime + 1.5;
    switch ( slot )
    {
      case 1:
        CCSPlayer::Radio(this, pszRadioSound: "Radio.GoGoGo", pszRadioText: "#Cstrike_TitlesTXT_Go_go_go");
        break;
      case 2:
        CCSPlayer::Radio(this, pszRadioSound: "Radio.TeamFallBack", pszRadioText: "#Cstrike_TitlesTXT_Team_fall_back");
        break;
      case 3:
        CCSPlayer::Radio(
          this,
          pszRadioSound: "Radio.StickTogether",
          pszRadioText: "#Cstrike_TitlesTXT_Stick_together_team");
        break;
      case 4:
        CCSPlayer::Radio(
          this,
          pszRadioSound: "Radio.GetInPosition",
          pszRadioText: "#Cstrike_TitlesTXT_Get_in_position_and_wait");
        break;
      case 5:
        CCSPlayer::Radio(this, pszRadioSound: "Radio.StormFront", pszRadioText: "#Cstrike_TitlesTXT_Storm_the_front");
        break;
      case 6:
        CCSPlayer::Radio(this, pszRadioSound: "Radio.ReportInTeam", pszRadioText: "#Cstrike_TitlesTXT_Report_in_team");
        break;
      default:
        break;
    }
    v4 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_radio", a3: 0, a4: 0);
    if ( v4 != nullptr )
    {
      v5 = engine->GetPlayerUserId(this: engine, a2: this->m_Network.m_pPev);
      v4->SetInt(this: v4, a2: "userid", a3: v5);
      v4->SetInt(this: v4, a2: "slot", a3: slot + 8);
      gameeventmanager->FireEvent(this: gameeventmanager, a2: v4, a3: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10284120
// Name: public: void CCSPlayer::HandleMenu_Radio3(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::HandleMenu_Radio3(CCSPlayer *this, int slot)
{
  int m_iRadioMessages; // eax
  IGameEvent *v4; // esi
  int v5; // eax
  const char *v6; // [esp-Ch] [ebp-10h]
  const char *v7; // [esp-8h] [ebp-Ch]

  m_iRadioMessages = this->m_iRadioMessages;
  if ( m_iRadioMessages >= 0 && this->m_flRadioTime <= gpGlobals->curtime )
  {
    this->m_iRadioMessages = m_iRadioMessages - 1;
    this->m_flRadioTime = gpGlobals->curtime + 1.5;
    switch ( slot )
    {
      case 1:
        if ( random->RandomInt(this: random, a2: 0, a3: 1) != 0 )
          CCSPlayer::Radio(this, pszRadioSound: "Radio.Affirmitive", pszRadioText: "#Cstrike_TitlesTXT_Affirmative");
        else
          CCSPlayer::Radio(this, pszRadioSound: "Radio.Roger", pszRadioText: "#Cstrike_TitlesTXT_Roger_that");
        break;
      case 2:
        v7 = "#Cstrike_TitlesTXT_Enemy_spotted";
        v6 = "Radio.EnemySpotted";
        goto LABEL_15;
      case 3:
        v7 = "#Cstrike_TitlesTXT_Need_backup";
        v6 = "Radio.NeedBackup";
        goto LABEL_15;
      case 4:
        v7 = "#Cstrike_TitlesTXT_Sector_clear";
        v6 = "Radio.SectorClear";
        goto LABEL_15;
      case 5:
        v7 = "#Cstrike_TitlesTXT_In_position";
        v6 = "Radio.InPosition";
        goto LABEL_15;
      case 6:
        v7 = "#Cstrike_TitlesTXT_Reporting_in";
        v6 = "Radio.ReportingIn";
        goto LABEL_15;
      case 7:
        v7 = "#Cstrike_TitlesTXT_Get_out_of_there";
        v6 = "Radio.GetOutOfThere";
        goto LABEL_15;
      case 8:
        v7 = "#Cstrike_TitlesTXT_Negative";
        v6 = "Radio.Negative";
        goto LABEL_15;
      case 9:
        v7 = "#Cstrike_TitlesTXT_Enemy_down";
        v6 = "Radio.EnemyDown";
LABEL_15:
        CCSPlayer::Radio(this, pszRadioSound: v6, pszRadioText: v7);
        break;
      default:
        break;
    }
    v4 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_radio", a3: 0, a4: 0);
    if ( v4 != nullptr )
    {
      v5 = engine->GetPlayerUserId(this: engine, a2: this->m_Network.m_pPev);
      v4->SetInt(this: v4, a2: "userid", a3: v5);
      v4->SetInt(this: v4, a2: "slot", a3: slot + 15);
      gameeventmanager->FireEvent(this: gameeventmanager, a2: v4, a3: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102842B0
// Name: bool HandleRadioAliasCommands(class CCSPlayer __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __usercall HandleRadioAliasCommands@<al>(int a1@<edi>, CCSPlayer *pPlayer, const char *pszCommand)
{
  char v3; // bl
  int v4; // eax
  IGameEvent *v5; // edi
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int m_iRadioMessages; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // eax
  int v35; // eax
  int v36; // eax
  int v37; // eax
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // eax

  v3 = 0;
  if ( pPlayer->IsAlive(this: pPlayer) && (pPlayer->m_afPhysicsFlags.m_Value & 8) == 0 )
  {
    if ( pszCommand != "coverme" && _V_stricmp(s1: pszCommand, s2: "coverme") != 0 )
    {
      if ( pszCommand != "takepoint" && _V_stricmp(s1: pszCommand, s2: "takepoint") != 0 )
      {
        if ( pszCommand != "holdpos" && _V_stricmp(s1: pszCommand, s2: "holdpos") != 0 )
        {
          if ( FStrEq(sz1: pszCommand, sz2: "regroup") )
          {
            m_iRadioMessages = pPlayer->m_iRadioMessages;
            v3 = 1;
            if ( m_iRadioMessages < 0 )
              return v3;
            if ( pPlayer->m_flRadioTime > gpGlobals->curtime )
              return v3;
            pPlayer->m_iRadioMessages = m_iRadioMessages - 1;
            pPlayer->m_flRadioTime = gpGlobals->curtime + 1.5;
            CCSPlayer::Radio(
              this: pPlayer,
              pszRadioSound: "Radio.Regroup",
              pszRadioText: "#Cstrike_TitlesTXT_Regroup_team");
            v5 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_radio", a3: 0, a4: 0);
            if ( v5 == nullptr )
              return v3;
            v12 = ((int (__thiscall *)(IVEngineServer *, edict_t *, int))engine->GetPlayerUserId)(
                    a1: engine,
                    a2: pPlayer->m_Network.m_pPev,
                    a3: a1);
            v5->SetInt(this: v5, a2: "userid", a3: v12);
            v5->SetInt(this: v5, a2: "slot", a3: 5);
          }
          else if ( FStrEq(sz1: pszCommand, sz2: "followme") )
          {
            v13 = pPlayer->m_iRadioMessages;
            v3 = 1;
            if ( v13 < 0 )
              return v3;
            if ( pPlayer->m_flRadioTime > gpGlobals->curtime )
              return v3;
            pPlayer->m_iRadioMessages = v13 - 1;
            pPlayer->m_flRadioTime = gpGlobals->curtime + 1.5;
            CCSPlayer::Radio(
              this: pPlayer,
              pszRadioSound: "Radio.FollowMe",
              pszRadioText: "#Cstrike_TitlesTXT_Follow_me");
            v5 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_radio", a3: 0, a4: 0);
            if ( v5 == nullptr )
              return v3;
            v14 = ((int (__thiscall *)(IVEngineServer *, edict_t *, int))engine->GetPlayerUserId)(
                    a1: engine,
                    a2: pPlayer->m_Network.m_pPev,
                    a3: a1);
            v5->SetInt(this: v5, a2: "userid", a3: v14);
            v5->SetInt(this: v5, a2: "slot", a3: 6);
          }
          else if ( FStrEq(sz1: pszCommand, sz2: "takingfire") )
          {
            v15 = pPlayer->m_iRadioMessages;
            v3 = 1;
            if ( v15 < 0 )
              return v3;
            if ( pPlayer->m_flRadioTime > gpGlobals->curtime )
              return v3;
            pPlayer->m_iRadioMessages = v15 - 1;
            pPlayer->m_flRadioTime = gpGlobals->curtime + 1.5;
            CCSPlayer::Radio(
              this: pPlayer,
              pszRadioSound: "Radio.TakingFire",
              pszRadioText: "#Cstrike_TitlesTXT_Taking_fire");
            v5 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_radio", a3: 0, a4: 0);
            if ( v5 == nullptr )
              return v3;
            v16 = ((int (__thiscall *)(IVEngineServer *, edict_t *, int))engine->GetPlayerUserId)(
                    a1: engine,
                    a2: pPlayer->m_Network.m_pPev,
                    a3: a1);
            v5->SetInt(this: v5, a2: "userid", a3: v16);
            v5->SetInt(this: v5, a2: "slot", a3: 7);
          }
          else
          {
            if ( FStrEq(sz1: pszCommand, sz2: "go") )
            {
              CCSPlayer::HandleMenu_Radio2(this: pPlayer, slot: 1);
              return 1;
            }
            if ( FStrEq(sz1: pszCommand, sz2: "fallback") )
            {
              v18 = pPlayer->m_iRadioMessages;
              v3 = 1;
              if ( v18 < 0 )
                return v3;
              if ( pPlayer->m_flRadioTime > gpGlobals->curtime )
                return v3;
              pPlayer->m_iRadioMessages = v18 - 1;
              pPlayer->m_flRadioTime = gpGlobals->curtime + 1.5;
              CCSPlayer::Radio(
                this: pPlayer,
                pszRadioSound: "Radio.TeamFallBack",
                pszRadioText: "#Cstrike_TitlesTXT_Team_fall_back");
              v5 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_radio", a3: 0, a4: 0);
              if ( v5 == nullptr )
                return v3;
              v19 = ((int (__thiscall *)(IVEngineServer *, edict_t *, int))engine->GetPlayerUserId)(
                      a1: engine,
                      a2: pPlayer->m_Network.m_pPev,
                      a3: a1);
              v5->SetInt(this: v5, a2: "userid", a3: v19);
              v5->SetInt(this: v5, a2: "slot", a3: 10);
            }
            else if ( FStrEq(sz1: pszCommand, sz2: "sticktog") )
            {
              v20 = pPlayer->m_iRadioMessages;
              v3 = 1;
              if ( v20 < 0 )
                return v3;
              if ( pPlayer->m_flRadioTime > gpGlobals->curtime )
                return v3;
              pPlayer->m_iRadioMessages = v20 - 1;
              pPlayer->m_flRadioTime = gpGlobals->curtime + 1.5;
              CCSPlayer::Radio(
                this: pPlayer,
                pszRadioSound: "Radio.StickTogether",
                pszRadioText: "#Cstrike_TitlesTXT_Stick_together_team");
              v5 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_radio", a3: 0, a4: 0);
              if ( v5 == nullptr )
                return v3;
              v21 = ((int (__thiscall *)(IVEngineServer *, edict_t *, int))engine->GetPlayerUserId)(
                      a1: engine,
                      a2: pPlayer->m_Network.m_pPev,
                      a3: a1);
              v5->SetInt(this: v5, a2: "userid", a3: v21);
              v5->SetInt(this: v5, a2: "slot", a3: 11);
            }
            else if ( FStrEq(sz1: pszCommand, sz2: "getinpos") )
            {
              v22 = pPlayer->m_iRadioMessages;
              v3 = 1;
              if ( v22 < 0 )
                return v3;
              if ( pPlayer->m_flRadioTime > gpGlobals->curtime )
                return v3;
              pPlayer->m_iRadioMessages = v22 - 1;
              pPlayer->m_flRadioTime = gpGlobals->curtime + 1.5;
              CCSPlayer::Radio(
                this: pPlayer,
                pszRadioSound: "Radio.GetInPosition",
                pszRadioText: "#Cstrike_TitlesTXT_Get_in_position_and_wait");
              v5 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_radio", a3: 0, a4: 0);
              if ( v5 == nullptr )
                return v3;
              v23 = ((int (__thiscall *)(IVEngineServer *, edict_t *, int))engine->GetPlayerUserId)(
                      a1: engine,
                      a2: pPlayer->m_Network.m_pPev,
                      a3: a1);
              v5->SetInt(this: v5, a2: "userid", a3: v23);
              v5->SetInt(this: v5, a2: "slot", a3: 12);
            }
            else if ( FStrEq(sz1: pszCommand, sz2: "stormfront") )
            {
              v24 = pPlayer->m_iRadioMessages;
              v3 = 1;
              if ( v24 < 0 )
                return v3;
              if ( pPlayer->m_flRadioTime > gpGlobals->curtime )
                return v3;
              pPlayer->m_iRadioMessages = v24 - 1;
              pPlayer->m_flRadioTime = gpGlobals->curtime + 1.5;
              CCSPlayer::Radio(
                this: pPlayer,
                pszRadioSound: "Radio.StormFront",
                pszRadioText: "#Cstrike_TitlesTXT_Storm_the_front");
              v5 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_radio", a3: 0, a4: 0);
              if ( v5 == nullptr )
                return v3;
              v25 = ((int (__thiscall *)(IVEngineServer *, edict_t *, int))engine->GetPlayerUserId)(
                      a1: engine,
                      a2: pPlayer->m_Network.m_pPev,
                      a3: a1);
              v5->SetInt(this: v5, a2: "userid", a3: v25);
              v5->SetInt(this: v5, a2: "slot", a3: 13);
            }
            else if ( FStrEq(sz1: pszCommand, sz2: "report") )
            {
              v26 = pPlayer->m_iRadioMessages;
              v3 = 1;
              if ( v26 < 0 )
                return v3;
              if ( pPlayer->m_flRadioTime > gpGlobals->curtime )
                return v3;
              pPlayer->m_iRadioMessages = v26 - 1;
              pPlayer->m_flRadioTime = gpGlobals->curtime + 1.5;
              CCSPlayer::Radio(
                this: pPlayer,
                pszRadioSound: "Radio.ReportInTeam",
                pszRadioText: "#Cstrike_TitlesTXT_Report_in_team");
              v5 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_radio", a3: 0, a4: 0);
              if ( v5 == nullptr )
                return v3;
              v27 = ((int (__thiscall *)(IVEngineServer *, edict_t *, int))engine->GetPlayerUserId)(
                      a1: engine,
                      a2: pPlayer->m_Network.m_pPev,
                      a3: a1);
              v5->SetInt(this: v5, a2: "userid", a3: v27);
              v5->SetInt(this: v5, a2: "slot", a3: 14);
            }
            else
            {
              if ( FStrEq(sz1: pszCommand, sz2: "roger") )
              {
                CCSPlayer::HandleMenu_Radio3(this: pPlayer, slot: 1);
                return 1;
              }
              if ( FStrEq(sz1: pszCommand, sz2: "enemyspot") )
              {
                v28 = pPlayer->m_iRadioMessages;
                v3 = 1;
                if ( v28 < 0 )
                  return v3;
                if ( pPlayer->m_flRadioTime > gpGlobals->curtime )
                  return v3;
                pPlayer->m_iRadioMessages = v28 - 1;
                pPlayer->m_flRadioTime = gpGlobals->curtime + 1.5;
                CCSPlayer::Radio(
                  this: pPlayer,
                  pszRadioSound: "Radio.EnemySpotted",
                  pszRadioText: "#Cstrike_TitlesTXT_Enemy_spotted");
                v5 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_radio", a3: 0, a4: 0);
                if ( v5 == nullptr )
                  return v3;
                v29 = ((int (__thiscall *)(IVEngineServer *, edict_t *, int))engine->GetPlayerUserId)(
                        a1: engine,
                        a2: pPlayer->m_Network.m_pPev,
                        a3: a1);
                v5->SetInt(this: v5, a2: "userid", a3: v29);
                v5->SetInt(this: v5, a2: "slot", a3: 17);
              }
              else if ( FStrEq(sz1: pszCommand, sz2: "needbackup") )
              {
                v30 = pPlayer->m_iRadioMessages;
                v3 = 1;
                if ( v30 < 0 )
                  return v3;
                if ( pPlayer->m_flRadioTime > gpGlobals->curtime )
                  return v3;
                pPlayer->m_iRadioMessages = v30 - 1;
                pPlayer->m_flRadioTime = gpGlobals->curtime + 1.5;
                CCSPlayer::Radio(
                  this: pPlayer,
                  pszRadioSound: "Radio.NeedBackup",
                  pszRadioText: "#Cstrike_TitlesTXT_Need_backup");
                v5 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_radio", a3: 0, a4: 0);
                if ( v5 == nullptr )
                  return v3;
                v31 = ((int (__thiscall *)(IVEngineServer *, edict_t *, int))engine->GetPlayerUserId)(
                        a1: engine,
                        a2: pPlayer->m_Network.m_pPev,
                        a3: a1);
                v5->SetInt(this: v5, a2: "userid", a3: v31);
                v5->SetInt(this: v5, a2: "slot", a3: 18);
              }
              else if ( FStrEq(sz1: pszCommand, sz2: "sectorclear") )
              {
                v32 = pPlayer->m_iRadioMessages;
                v3 = 1;
                if ( v32 < 0 )
                  return v3;
                if ( pPlayer->m_flRadioTime > gpGlobals->curtime )
                  return v3;
                pPlayer->m_iRadioMessages = v32 - 1;
                pPlayer->m_flRadioTime = gpGlobals->curtime + 1.5;
                CCSPlayer::Radio(
                  this: pPlayer,
                  pszRadioSound: "Radio.SectorClear",
                  pszRadioText: "#Cstrike_TitlesTXT_Sector_clear");
                v5 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_radio", a3: 0, a4: 0);
                if ( v5 == nullptr )
                  return v3;
                v33 = ((int (__thiscall *)(IVEngineServer *, edict_t *, int))engine->GetPlayerUserId)(
                        a1: engine,
                        a2: pPlayer->m_Network.m_pPev,
                        a3: a1);
                v5->SetInt(this: v5, a2: "userid", a3: v33);
                v5->SetInt(this: v5, a2: "slot", a3: 19);
              }
              else if ( FStrEq(sz1: pszCommand, sz2: "inposition") )
              {
                v34 = pPlayer->m_iRadioMessages;
                v3 = 1;
                if ( v34 < 0 )
                  return v3;
                if ( pPlayer->m_flRadioTime > gpGlobals->curtime )
                  return v3;
                pPlayer->m_iRadioMessages = v34 - 1;
                pPlayer->m_flRadioTime = gpGlobals->curtime + 1.5;
                CCSPlayer::Radio(
                  this: pPlayer,
                  pszRadioSound: "Radio.InPosition",
                  pszRadioText: "#Cstrike_TitlesTXT_In_position");
                v5 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_radio", a3: 0, a4: 0);
                if ( v5 == nullptr )
                  return v3;
                v35 = ((int (__thiscall *)(IVEngineServer *, edict_t *, int))engine->GetPlayerUserId)(
                        a1: engine,
                        a2: pPlayer->m_Network.m_pPev,
                        a3: a1);
                v5->SetInt(this: v5, a2: "userid", a3: v35);
                v5->SetInt(this: v5, a2: "slot", a3: 20);
              }
              else if ( FStrEq(sz1: pszCommand, sz2: "reportingin") )
              {
                v36 = pPlayer->m_iRadioMessages;
                v3 = 1;
                if ( v36 < 0 )
                  return v3;
                if ( pPlayer->m_flRadioTime > gpGlobals->curtime )
                  return v3;
                pPlayer->m_iRadioMessages = v36 - 1;
                pPlayer->m_flRadioTime = gpGlobals->curtime + 1.5;
                CCSPlayer::Radio(
                  this: pPlayer,
                  pszRadioSound: "Radio.ReportingIn",
                  pszRadioText: "#Cstrike_TitlesTXT_Reporting_in");
                v5 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_radio", a3: 0, a4: 0);
                if ( v5 == nullptr )
                  return v3;
                v37 = ((int (__thiscall *)(IVEngineServer *, edict_t *, int))engine->GetPlayerUserId)(
                        a1: engine,
                        a2: pPlayer->m_Network.m_pPev,
                        a3: a1);
                v5->SetInt(this: v5, a2: "userid", a3: v37);
                v5->SetInt(this: v5, a2: "slot", a3: 21);
              }
              else if ( FStrEq(sz1: pszCommand, sz2: "getout") )
              {
                v38 = pPlayer->m_iRadioMessages;
                v3 = 1;
                if ( v38 < 0 )
                  return v3;
                if ( pPlayer->m_flRadioTime > gpGlobals->curtime )
                  return v3;
                pPlayer->m_iRadioMessages = v38 - 1;
                pPlayer->m_flRadioTime = gpGlobals->curtime + 1.5;
                CCSPlayer::Radio(
                  this: pPlayer,
                  pszRadioSound: "Radio.GetOutOfThere",
                  pszRadioText: "#Cstrike_TitlesTXT_Get_out_of_there");
                v5 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_radio", a3: 0, a4: 0);
                if ( v5 == nullptr )
                  return v3;
                v39 = ((int (__thiscall *)(IVEngineServer *, edict_t *, int))engine->GetPlayerUserId)(
                        a1: engine,
                        a2: pPlayer->m_Network.m_pPev,
                        a3: a1);
                v5->SetInt(this: v5, a2: "userid", a3: v39);
                v5->SetInt(this: v5, a2: "slot", a3: 22);
              }
              else if ( FStrEq(sz1: pszCommand, sz2: "negative") )
              {
                v40 = pPlayer->m_iRadioMessages;
                v3 = 1;
                if ( v40 < 0 )
                  return v3;
                if ( pPlayer->m_flRadioTime > gpGlobals->curtime )
                  return v3;
                pPlayer->m_iRadioMessages = v40 - 1;
                pPlayer->m_flRadioTime = gpGlobals->curtime + 1.5;
                CCSPlayer::Radio(
                  this: pPlayer,
                  pszRadioSound: "Radio.Negative",
                  pszRadioText: "#Cstrike_TitlesTXT_Negative");
                v5 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_radio", a3: 0, a4: 0);
                if ( v5 == nullptr )
                  return v3;
                v41 = ((int (__thiscall *)(IVEngineServer *, edict_t *, int))engine->GetPlayerUserId)(
                        a1: engine,
                        a2: pPlayer->m_Network.m_pPev,
                        a3: a1);
                v5->SetInt(this: v5, a2: "userid", a3: v41);
                v5->SetInt(this: v5, a2: "slot", a3: 23);
              }
              else
              {
                if ( !FStrEq(sz1: pszCommand, sz2: "enemydown") )
                  return v3;
                v42 = pPlayer->m_iRadioMessages;
                v3 = 1;
                if ( v42 < 0 )
                  return v3;
                if ( pPlayer->m_flRadioTime > gpGlobals->curtime )
                  return v3;
                pPlayer->m_iRadioMessages = v42 - 1;
                pPlayer->m_flRadioTime = gpGlobals->curtime + 1.5;
                CCSPlayer::Radio(
                  this: pPlayer,
                  pszRadioSound: "Radio.EnemyDown",
                  pszRadioText: "#Cstrike_TitlesTXT_Enemy_down");
                v5 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_radio", a3: 0, a4: 0);
                if ( v5 == nullptr )
                  return v3;
                v43 = ((int (__thiscall *)(IVEngineServer *, edict_t *, int))engine->GetPlayerUserId)(
                        a1: engine,
                        a2: pPlayer->m_Network.m_pPev,
                        a3: a1);
                v5->SetInt(this: v5, a2: "userid", a3: v43);
                v5->SetInt(this: v5, a2: "slot", a3: 24);
              }
            }
          }
        }
        else
        {
          v9 = pPlayer->m_iRadioMessages;
          v3 = 1;
          if ( v9 < 0 )
            return v3;
          if ( pPlayer->m_flRadioTime > gpGlobals->curtime )
            return v3;
          pPlayer->m_iRadioMessages = v9 - 1;
          pPlayer->m_flRadioTime = gpGlobals->curtime + 1.5;
          CCSPlayer::Radio(
            this: pPlayer,
            pszRadioSound: "Radio.HoldPosition",
            pszRadioText: "#Cstrike_TitlesTXT_Hold_this_position");
          v5 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_radio", a3: 0, a4: 0);
          if ( v5 == nullptr )
            return v3;
          v10 = ((int (__thiscall *)(IVEngineServer *, edict_t *, int))engine->GetPlayerUserId)(
                  a1: engine,
                  a2: pPlayer->m_Network.m_pPev,
                  a3: a1);
          v5->SetInt(this: v5, a2: "userid", a3: v10);
          v5->SetInt(this: v5, a2: "slot", a3: 4);
        }
      }
      else
      {
        v7 = pPlayer->m_iRadioMessages;
        v3 = 1;
        if ( v7 < 0 )
          return v3;
        if ( pPlayer->m_flRadioTime > gpGlobals->curtime )
          return v3;
        pPlayer->m_iRadioMessages = v7 - 1;
        pPlayer->m_flRadioTime = gpGlobals->curtime + 1.5;
        CCSPlayer::Radio(
          this: pPlayer,
          pszRadioSound: "Radio.YouTakeThePoint",
          pszRadioText: "#Cstrike_TitlesTXT_You_take_the_point");
        v5 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_radio", a3: 0, a4: 0);
        if ( v5 == nullptr )
          return v3;
        v8 = ((int (__thiscall *)(IVEngineServer *, edict_t *, int))engine->GetPlayerUserId)(
               a1: engine,
               a2: pPlayer->m_Network.m_pPev,
               a3: a1);
        v5->SetInt(this: v5, a2: "userid", a3: v8);
        v5->SetInt(this: v5, a2: "slot", a3: 3);
      }
    }
    else
    {
      v4 = pPlayer->m_iRadioMessages;
      v3 = 1;
      if ( v4 < 0 )
        return v3;
      if ( pPlayer->m_flRadioTime > gpGlobals->curtime )
        return v3;
      pPlayer->m_iRadioMessages = v4 - 1;
      pPlayer->m_flRadioTime = gpGlobals->curtime + 1.5;
      CCSPlayer::Radio(this: pPlayer, pszRadioSound: "Radio.CoverMe", pszRadioText: "#Cstrike_TitlesTXT_Cover_me");
      v5 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_radio", a3: 0, a4: 0);
      if ( v5 == nullptr )
        return v3;
      v6 = ((int (__thiscall *)(IVEngineServer *, edict_t *, int))engine->GetPlayerUserId)(
             a1: engine,
             a2: pPlayer->m_Network.m_pPev,
             a3: a1);
      v5->SetInt(this: v5, a2: "userid", a3: v6);
      v5->SetInt(this: v5, a2: "slot", a3: 2);
    }
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v5, a3: false);
    return v3;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10285110
// Name: public: virtual void CCSPlayer::ResetForceTeamThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::ResetForceTeamThink(CCSPlayer *this)
{
  edict_t *m_pPev; // ecx

  if ( this->m_fForceTeam.m_Value != -1.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xC44u);
    }
    this->m_fForceTeam.m_Value = -1.0;
  }
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10285190
// Name: private: void CCSPlayer::State_Enter_DEATH_WAIT_FOR_KEY(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::State_Enter_DEATH_WAIT_FOR_KEY(CCSPlayer *this)
{
  CNetworkVarBase<char,CBaseEntity::NetworkVar_m_lifeState> *p_m_lifeState; // esi
  edict_t *m_pPev; // ecx

  p_m_lifeState = &this->m_lifeState;
  if ( this->m_lifeState.m_Value != 2 )
  {
    this->NetworkStateChanged_m_lifeState(this, a2: &this->m_lifeState);
    p_m_lifeState->m_Value = 2;
  }
  if ( this->m_flPlaybackRate.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_flPlaybackRate.m_Value = 0.0;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x37Cu);
      this->m_flPlaybackRate.m_Value = 0.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10285210
// Name: private: void CCSPlayer::State_Enter_ACTIVE(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::State_Enter_ACTIVE(CCSPlayer *this)
{
  IPhysicsObject *m_pPhysicsObject; // ecx

  CBaseEntity::SetMoveType(this, val: MOVETYPE_WALK, moveCollide: MOVECOLLIDE_DEFAULT);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value & 0xFFFB);
  if ( this->m_Local.m_iHideHUD.m_Value != 0 )
  {
    this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: &this->m_Local.m_iHideHUD);
    this->m_Local.m_iHideHUD.m_Value = 0;
  }
  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
    m_pPhysicsObject->Wake(this: m_pPhysicsObject);
  this->m_bRespawning = false;
}

//------------------------------------------------------------------------------
// Address: 0x10285270
// Name: public: void CCSPlayer::StockPlayerAmmo(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::StockPlayerAmmo(CCSPlayer *this, CBaseCombatWeapon *pNewWeapon)
{
  CBaseCombatWeapon *v3; // eax
  CBaseCombatWeapon *v4; // esi
  int v5; // eax
  CBaseCombatWeapon *v6; // eax
  void *v7; // esi
  int v8; // eax
  CCSAmmoDef *AmmoDef; // eax
  Ammo_t *AmmoOfIndex; // eax
  int v11; // ebx
  CBaseEdict *v12; // ecx
  CBaseCombatWeapon *v13; // eax
  CCSAmmoDef *v14; // eax
  Ammo_t *v15; // eax
  int v16; // edi
  CBaseEdict *v17; // ecx
  int v18; // [esp-8h] [ebp-10h]
  int v19; // [esp-4h] [ebp-Ch]

  v3 = (CBaseCombatWeapon *)__RTDynamicCast(
                              inptr: pNewWeapon,
                              VfDelta: 0,
                              SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
                              TargetType: &CWeaponCSBase `RTTI Type Descriptor',
                              isReference: 0);
  v4 = v3;
  if ( v3 != nullptr )
  {
    if ( (CBaseCombatWeapon::GetWpnData(this: v3)->iFlags & 0x10) != 0 )
      return;
    v5 = v4->GetPrimaryAmmoType(this: v4);
    if ( v5 == -1 )
      return;
    goto LABEL_15;
  }
  v6 = this->Weapon_GetSlot(this, a2: 0);
  v7 = __RTDynamicCast(
         inptr: v6,
         VfDelta: 0,
         SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
         TargetType: &CWeaponCSBase `RTTI Type Descriptor',
         isReference: 0);
  if ( v7 != nullptr )
  {
    v8 = (*(int (__thiscall **)(void *))(*(_DWORD *)v7 + 1352))(a1: v7);
    if ( v8 != -1 )
    {
      v18 = v8;
      AmmoDef = GetAmmoDef();
      AmmoOfIndex = CAmmoDef::GetAmmoOfIndex(this: AmmoDef, nAmmoIndex: v18);
      CBaseCombatCharacter::GiveAmmo(this, iCount: 9999, szName: AmmoOfIndex->pName, bSuppressSound: false);
      v11 = (*(int (__thiscall **)(void *))(*(_DWORD *)v7 + 1280))(a1: v7);
      if ( *((_DWORD *)v7 + 300) != v11 )
      {
        if ( *((_BYTE *)v7 + 84) != 0 )
        {
          *((_BYTE *)v7 + 88) |= 1u;
        }
        else
        {
          v12 = *((CBaseEdict **)v7 + 6);
          if ( v12 != nullptr )
            CBaseEdict::StateChanged(this: v12, offset: 0x4B0u);
        }
        *((_DWORD *)v7 + 300) = v11;
      }
    }
  }
  v13 = this->Weapon_GetSlot(this, a2: 1);
  v4 = (CBaseCombatWeapon *)__RTDynamicCast(
                              inptr: v13,
                              VfDelta: 0,
                              SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
                              TargetType: &CWeaponCSBase `RTTI Type Descriptor',
                              isReference: 0);
  if ( v4 != nullptr )
  {
    v5 = v4->GetPrimaryAmmoType(this: v4);
    if ( v5 != -1 )
    {
LABEL_15:
      v19 = v5;
      v14 = GetAmmoDef();
      v15 = CAmmoDef::GetAmmoOfIndex(this: v14, nAmmoIndex: v19);
      CBaseCombatCharacter::GiveAmmo(this, iCount: 9999, szName: v15->pName, bSuppressSound: false);
      v16 = v4->GetMaxClip1(this: v4);
      if ( v4->m_iClip1.m_Value != v16 )
      {
        if ( v4->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&v4->m_Network + 76) |= 1u;
          v4->m_iClip1.m_Value = v16;
        }
        else
        {
          v17 = &v4->m_Network.m_pPev->CBaseEdict;
          if ( v17 != nullptr )
            CBaseEdict::StateChanged(this: v17, offset: 0x4B0u);
          v4->m_iClip1.m_Value = v16;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10285420
// Name: public: void CCSPlayer::OutputDamageTaken(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::OutputDamageTaken(CCSPlayer *this)
{
  int m_Head; // edi
  const char *v3; // eax
  int v4; // ebx
  CDamageRecord *m_Element; // edi
  char buf[67]; // [esp+8h] [ebp-44h] BYREF
  bool bPrintHeader; // [esp+4Bh] [ebp-1h]

  m_Head = this->m_DamageTakenList.m_Head;
  for ( bPrintHeader = true; m_Head != -1; m_Head = this->m_DamageTakenList.m_Memory.m_pMemory[v4].m_Next )
  {
    if ( bPrintHeader )
    {
      v3 = this->GetPlayerName(this);
      ClientPrint(
        player: this,
        msg_dest: 2u,
        msg_name: "Player: %s1 - Damage Taken\n",
        param1: v3,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      ClientPrint(
        player: this,
        msg_dest: 2u,
        msg_name: "-------------------------\n",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      bPrintHeader = false;
    }
    v4 = m_Head;
    m_Element = this->m_DamageTakenList.m_Memory.m_pMemory[m_Head].m_Element;
    if ( m_Element != nullptr )
    {
      if ( m_Element->m_iNumHits == 1 )
        V_snprintf(pDest: buf, maxLen: 64, pFormat: "%d in %d hit", m_Element->m_iDamage, 1);
      else
        V_snprintf(pDest: buf, maxLen: 64, pFormat: "%d in %d hits", m_Element->m_iDamage, m_Element->m_iNumHits);
      ClientPrint(
        player: this,
        msg_dest: 2u,
        msg_name: "Damage Taken from \"%s1\" - %s2\n",
        param1: m_Element->m_szPlayerName,
        param2: buf,
        param3: nullptr,
        param4: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10285500
// Name: public: void CCSPlayer::OutputDamageGiven(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::OutputDamageGiven(CCSPlayer *this)
{
  int m_Head; // edi
  const char *v3; // eax
  int v4; // ebx
  CDamageRecord *m_Element; // edi
  char buf[67]; // [esp+8h] [ebp-44h] BYREF
  bool bPrintHeader; // [esp+4Bh] [ebp-1h]

  m_Head = this->m_DamageGivenList.m_Head;
  for ( bPrintHeader = true; m_Head != -1; m_Head = this->m_DamageGivenList.m_Memory.m_pMemory[v4].m_Next )
  {
    if ( bPrintHeader )
    {
      v3 = this->GetPlayerName(this);
      ClientPrint(
        player: this,
        msg_dest: 2u,
        msg_name: "Player: %s1 - Damage Given\n",
        param1: v3,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      ClientPrint(
        player: this,
        msg_dest: 2u,
        msg_name: "-------------------------\n",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      bPrintHeader = false;
    }
    v4 = m_Head;
    m_Element = this->m_DamageGivenList.m_Memory.m_pMemory[m_Head].m_Element;
    if ( m_Element != nullptr )
    {
      if ( m_Element->m_iNumHits == 1 )
        V_snprintf(pDest: buf, maxLen: 64, pFormat: "%d in %d hit", m_Element->m_iDamage, 1);
      else
        V_snprintf(pDest: buf, maxLen: 64, pFormat: "%d in %d hits", m_Element->m_iDamage, m_Element->m_iNumHits);
      ClientPrint(
        player: this,
        msg_dest: 2u,
        msg_name: "Damage Given to \"%s1\" - %s2\n",
        param1: m_Element->m_szPlayerName,
        param2: buf,
        param3: nullptr,
        param4: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102855E0
// Name: public: void CCSPlayer::ResetRoundBasedAchievementVariables(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::ResetRoundBasedAchievementVariables(CCSPlayer *this)
{
  int v2; // edi
  CBaseCombatWeapon *v3; // eax
  _DWORD *v4; // eax
  CBaseCombatWeapon *v5; // eax
  _DWORD *v6; // eax
  int numCTPlayers; // [esp+Ch] [ebp-8h]
  int numTPlayers; // [esp+10h] [ebp-4h]

  this->m_KillingSpreeStartTime = -1;
  v2 = 0;
  numCTPlayers = 0;
  for ( numTPlayers = 0; v2 < g_Teams.m_Size; ++v2 )
  {
    if ( g_Teams.m_Memory.m_pMemory[v2] != nullptr )
    {
      if ( g_Teams.m_Memory.m_pMemory[v2]->GetTeamNumber(this: g_Teams.m_Memory.m_pMemory[v2]) == 3 )
      {
        numCTPlayers = g_Teams.m_Memory.m_pMemory[v2]->GetNumPlayers(this: g_Teams.m_Memory.m_pMemory[v2]);
      }
      else if ( g_Teams.m_Memory.m_pMemory[v2]->GetTeamNumber(this: g_Teams.m_Memory.m_pMemory[v2]) == 2 )
      {
        numTPlayers = g_Teams.m_Memory.m_pMemory[v2]->GetNumPlayers(this: g_Teams.m_Memory.m_pMemory[v2]);
      }
    }
  }
  this->m_NumEnemiesKilledThisRound = 0;
  this->m_NumEnemiesKilledThisSpawn = 0;
  this->m_maxNumEnemiesKillStreak = 0;
  if ( CBaseEntity::GetTeamNumber(this) == 3 )
  {
    this->m_NumEnemiesAtRoundStart = numTPlayers;
  }
  else if ( CBaseEntity::GetTeamNumber(this) == 2 )
  {
    this->m_NumEnemiesAtRoundStart = numCTPlayers;
  }
  v3 = this->Weapon_GetSlot(this, a2: 0);
  v4 = __RTDynamicCast(
         inptr: v3,
         VfDelta: 0,
         SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
         TargetType: &CWeaponCSBase `RTTI Type Descriptor',
         isReference: 0);
  if ( v4 != nullptr )
    v4[355] = 0;
  v5 = this->Weapon_GetSlot(this, a2: 1);
  v6 = __RTDynamicCast(
         inptr: v5,
         VfDelta: 0,
         SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
         TargetType: &CWeaponCSBase `RTTI Type Descriptor',
         isReference: 0);
  if ( v6 != nullptr )
    v6[355] = 0;
  this->m_killWeapons.m_Size = 0;
  this->m_killTimes.m_Size = 0;
  this->m_enemyPlayersKilledThisRound.m_Size = 0;
  this->m_killsWhileBlind = 0;
  this->m_bombCarrierkills = 0;
  *(_WORD *)&this->m_bSurvivedHeadshotDueToHelmet = 0;
  this->m_gooseChaseStep = GC_NONE;
  this->m_defuseDefenseStep = DD_NONE;
  this->m_pGooseChaseDistractingPlayer.m_Index = -1;
  this->m_bMadeFootstepNoise = false;
  this->m_knifeKillsWhenOutOfAmmo = 0;
  this->m_attemptedBombPlace = false;
  this->m_triggerPulled = false;
  this->m_triggerPulls = 0;
  this->m_bMadePurchseThisRound = false;
  *(_WORD *)&this->m_bKilledDefuser = 0;
  this->m_maxGrenadeKills = 0;
  this->m_grenadeDamageTakenThisRound = 0;
  this->m_firstShotKills = 0;
  this->m_hasReloaded = false;
  this->m_bWieldingKnifeAndKilledByGun = false;
  this->m_wasKilledThisRound = false;
  this->m_bombPickupTime = -1.0;
  this->m_bombPlacedTime = -1.0;
  this->m_bombDroppedTime = -1.0;
  this->m_killedTime = -1.0;
  this->m_spawnedTime = -1.0;
  this->m_longestLife = -1.0;
  this->m_WeaponTypesUsed.m_Size = 0;
  this->m_WeaponTypesHeld.m_Size = 0;
  this->m_WeaponTypesRunningOutOfAmmo.m_Size = 0;
  this->m_BurnDamageDeltVec.m_Size = 0;
  *(_DWORD *)&this->m_bPickedUpWeapon = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10285800
// Name: public: bool CCSPlayer::DidPlayerEmptyAmmoForWeapon(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSPlayer::DidPlayerEmptyAmmoForWeapon(CCSPlayer *this, CBaseCombatWeapon *pBaseWeapon)
{
  CWeaponCSBase *v3; // eax
  CWeaponCSBase *v4; // esi
  CSWeaponType m_WeaponType; // edi
  bool result; // al

  result = false;
  if ( pBaseWeapon != nullptr )
  {
    v3 = (CWeaponCSBase *)__RTDynamicCast(
                            inptr: pBaseWeapon,
                            VfDelta: 0,
                            SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
                            TargetType: &CWeaponCSBase `RTTI Type Descriptor',
                            isReference: 0);
    v4 = v3;
    if ( v3 != nullptr )
    {
      m_WeaponType = CWeaponCSBase::GetCSWpnData(this: v3)->m_WeaponType;
      pBaseWeapon = (CBaseCombatWeapon *)v4->GetCSWeaponID(this: v4);
      if ( m_WeaponType != WEAPONTYPE_KNIFE
        && m_WeaponType != WEAPONTYPE_C4
        && m_WeaponType != WEAPONTYPE_GRENADE
        && CUtlVector<enum CSWeaponID,CUtlMemory<enum CSWeaponID,int>>::Find(
             this: (CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > *)&this->m_WeaponTypesRunningOutOfAmmo,
             src: &pBaseWeapon) != -1 )
      {
        return true;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10285880
// Name: public: void CCSPlayer::SetPlayerDominated(class CCSPlayer __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::SetPlayerDominated(CCSPlayer *this, CCSPlayer *pPlayer, bool bDominated)
{
  edict_t *m_pPev; // eax
  CCSPlayer *v4; // edx
  signed int v5; // edi
  CCSPlayer::NetworkVar_m_bPlayerDominated *p_m_bPlayerDominated; // esi
  edict_t *v7; // ecx

  m_pPev = pPlayer->m_Network.m_pPev;
  v4 = this;
  if ( m_pPev != nullptr )
    v5 = m_pPev - gpGlobals->pEdicts;
  else
    v5 = 0;
  p_m_bPlayerDominated = &this->m_bPlayerDominated;
  if ( bDominated != this->m_bPlayerDominated.m_Value[v5] )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v7 = this->m_Network.m_pPev;
      if ( v7 != nullptr )
      {
        CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: v5 + 6741);
        v4 = this;
      }
    }
    p_m_bPlayerDominated->m_Value[v5] = bDominated;
  }
  CCSPlayer::SetPlayerDominatingMe(this: pPlayer, pPlayer: v4, bDominated);
}

//------------------------------------------------------------------------------
// Address: 0x10285900
// Name: public: void CCSPlayer::RemoveNemesisRelationships(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::RemoveNemesisRelationships(CCSPlayer *this)
{
  int i; // ebx
  CBasePlayer *v3; // eax
  CBasePlayer *v4; // esi
  CCSPlayer *v5; // eax
  CCSPlayer *v6; // esi

  for ( i = 1; i <= gpGlobals->maxClients; ++i )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: i);
    v4 = v3;
    if ( v3 != nullptr && v3->IsPlayer(this: v3) )
    {
      v5 = (CCSPlayer *)__RTDynamicCast(
                          inptr: v4,
                          VfDelta: 0,
                          SrcType: &CBaseEntity `RTTI Type Descriptor',
                          TargetType: &CCSPlayer `RTTI Type Descriptor',
                          isReference: 0);
      v6 = v5;
      if ( v5 != nullptr && v5 != this )
      {
        CCSPlayer::SetPlayerDominated(this, pPlayer: v5, bDominated: false);
        CCSPlayer::SetPlayerDominated(this: v6, pPlayer: this, bDominated: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10285980
// Name: public: int CCSPlayer::GetNumEnemyDamagers(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSPlayer::GetNumEnemyDamagers(CCSPlayer *this)
{
  int m_Head; // edi
  int result; // eax
  CBasePlayer *v4; // esi
  const char *v5; // eax
  int TeamNumber; // esi
  CDamageRecord *m_Element; // [esp-Ch] [ebp-1Ch]
  int numberOfEnemyDamagers; // [esp+8h] [ebp-8h]
  int j; // [esp+Ch] [ebp-4h]

  m_Head = this->m_DamageTakenList.m_Head;
  result = 0;
  numberOfEnemyDamagers = 0;
  if ( m_Head != -1 )
  {
    do
    {
      for ( j = 1; j <= 64; ++j )
      {
        v4 = UTIL_PlayerByIndex(playerIndex: j);
        if ( v4 != nullptr )
        {
          m_Element = this->m_DamageTakenList.m_Memory.m_pMemory[m_Head].m_Element;
          v5 = v4->GetPlayerName(this: v4);
          if ( V_strncmp(s1: v5, s2: m_Element->m_szPlayerName, count: 32) == 0 )
          {
            TeamNumber = CBaseEntity::GetTeamNumber(this: v4);
            if ( TeamNumber != CBaseEntity::GetTeamNumber(this) )
              ++numberOfEnemyDamagers;
          }
        }
      }
      m_Head = this->m_DamageTakenList.m_Memory.m_pMemory[m_Head].m_Next;
    }
    while ( m_Head != -1 );
    return numberOfEnemyDamagers;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10285A20
// Name: public: int CCSPlayer::GetNumEnemiesDamaged(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSPlayer::GetNumEnemiesDamaged(CCSPlayer *this)
{
  int m_Head; // edi
  int result; // eax
  CBasePlayer *v4; // esi
  const char *v5; // eax
  int TeamNumber; // esi
  CDamageRecord *m_Element; // [esp-Ch] [ebp-1Ch]
  int numberOfEnemiesDamaged; // [esp+8h] [ebp-8h]
  int j; // [esp+Ch] [ebp-4h]

  m_Head = this->m_DamageGivenList.m_Head;
  result = 0;
  numberOfEnemiesDamaged = 0;
  if ( m_Head != -1 )
  {
    do
    {
      for ( j = 1; j <= 64; ++j )
      {
        v4 = UTIL_PlayerByIndex(playerIndex: j);
        if ( v4 != nullptr )
        {
          m_Element = this->m_DamageGivenList.m_Memory.m_pMemory[m_Head].m_Element;
          v5 = v4->GetPlayerName(this: v4);
          if ( V_strncmp(s1: v5, s2: m_Element->m_szPlayerName, count: 32) == 0 )
          {
            TeamNumber = CBaseEntity::GetTeamNumber(this: v4);
            if ( TeamNumber != CBaseEntity::GetTeamNumber(this) )
              ++numberOfEnemiesDamaged;
          }
        }
      }
      m_Head = this->m_DamageGivenList.m_Memory.m_pMemory[m_Head].m_Next;
    }
    while ( m_Head != -1 );
    return numberOfEnemiesDamaged;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102862C0
// Name: public: void CCSPlayer::SetFlinchVelocityModifier(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::SetFlinchVelocityModifier(CCSPlayer *this, float fVelocityModifier)
{
  CNetworkVarBase<float,CCSPlayer::NetworkVar_m_flVelocityModifier> *p_m_flVelocityModifier; // esi
  CNetworkVarBase<float,CCSPlayer::NetworkVar_m_flVelocityModifier> *p_fVelocityModifier; // edi
  edict_t *m_pPev; // ecx

  p_m_flVelocityModifier = &this->m_flVelocityModifier;
  p_fVelocityModifier = &this->m_flVelocityModifier;
  if ( fVelocityModifier <= this->m_flVelocityModifier.m_Value )
    p_fVelocityModifier = (CNetworkVarBase<float,CCSPlayer::NetworkVar_m_flVelocityModifier> *)&fVelocityModifier;
  if ( p_m_flVelocityModifier->m_Value != p_fVelocityModifier->m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_flVelocityModifier->m_Value = p_fVelocityModifier->m_Value;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x178Cu);
      p_m_flVelocityModifier->m_Value = p_fVelocityModifier->m_Value;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10286330
// Name: void TE_PlayerAnimEvent(class CBasePlayer __near *,enum PlayerAnimEvent_t,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TE_PlayerAnimEvent(CBasePlayer *pPlayer, PlayerAnimEvent_t event, int nData)
{
  const Vector *v3; // edi
  CBasePlayer *m_pEntity; // eax
  CPVSFilter filter; // [esp+8h] [ebp-2Ch] BYREF
  _BYTE v6[12]; // [esp+28h] [ebp-Ch] BYREF

  v3 = pPlayer->EyePosition(this: pPlayer, result: v6);
  CRecipientFilter::CRecipientFilter(this: &filter);
  filter.__vftable = (CPVSFilter_vtbl *)&CPVSFilter::`vftable';
  CRecipientFilter::AddRecipientsByPVS(this: &filter, origin: v3);
  if ( g_TEPlayerAnimEvent.m_hPlayer.m_Value.m_Index == -1
    || g_pEntityList->m_EntPtrArray[LOWORD(g_TEPlayerAnimEvent.m_hPlayer.m_Value.m_Index)].m_SerialNumber != HIWORD(g_TEPlayerAnimEvent.m_hPlayer.m_Value.m_Index) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = (CBasePlayer *)g_pEntityList->m_EntPtrArray[LOWORD(g_TEPlayerAnimEvent.m_hPlayer.m_Value.m_Index)].m_pEntity;
  }
  if ( m_pEntity != pPlayer )
    g_TEPlayerAnimEvent.m_hPlayer.m_Value.m_Index = pPlayer->GetRefEHandle(this: pPlayer)->m_Index;
  if ( g_TEPlayerAnimEvent.m_iEvent.m_Value != event )
    g_TEPlayerAnimEvent.m_iEvent.m_Value = event;
  if ( g_TEPlayerAnimEvent.m_nData.m_Value != nData )
    g_TEPlayerAnimEvent.m_nData.m_Value = nData;
  CBaseTempEntity::Create(this: &g_TEPlayerAnimEvent, &filter, delay: 0.0);
  CRecipientFilter::~CRecipientFilter(this: &filter);
}

//------------------------------------------------------------------------------
// Address: 0x102863F0
// Name: protected: void CCSPlayer::SetModelFromClass(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::SetModelFromClass(CCSPlayer *this)
{
  CNetworkVarBase<int,CCSPlayer::NetworkVar_m_iClass> *p_m_iClass; // esi
  bool IsTClass; // al
  int TeamNumber; // eax
  int NextClassForTeam; // ebx
  CNetworkVarBase<int,CCSPlayer::NetworkVar_m_iClass> *v6; // eax
  CBaseEdict *m_Value; // ecx
  CCSPlayer_vtbl *v8; // ebx
  const char *v9; // eax
  CCSPlayer_vtbl *v10; // esi
  const char *ClassModelPath; // eax

  if ( CBaseEntity::GetTeamNumber(this) == 2 )
  {
    p_m_iClass = &this->m_iClass;
    IsTClass = PlayerModelInfo::IsTClass(this: &PlayerModelInfo::s_PlayerModelInfo, i: this->m_iClass.m_Value);
  }
  else
  {
    if ( CBaseEntity::GetTeamNumber(this) != 3 )
    {
      v10 = this->CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
      ClassModelPath = PlayerModelInfo::GetClassModelPath(this: &PlayerModelInfo::s_PlayerModelInfo, classID: 1);
      v10->SetModel(this, a2: ClassModelPath);
      return;
    }
    p_m_iClass = &this->m_iClass;
    IsTClass = PlayerModelInfo::IsCTClass(this: &PlayerModelInfo::s_PlayerModelInfo, i: this->m_iClass.m_Value);
  }
  if ( !IsTClass )
  {
    TeamNumber = CBaseEntity::GetTeamNumber(this);
    NextClassForTeam = PlayerModelInfo::GetNextClassForTeam(this: &PlayerModelInfo::s_PlayerModelInfo, team: TeamNumber);
    if ( p_m_iClass->m_Value != NextClassForTeam )
    {
      v6 = p_m_iClass - 1541;
      if ( LOBYTE(p_m_iClass[-1520].m_Value) != 0 )
      {
        LOBYTE(v6[22].m_Value) |= 1u;
      }
      else
      {
        m_Value = (CBaseEdict *)v6[6].m_Value;
        if ( m_Value != nullptr )
          CBaseEdict::StateChanged(this: m_Value, offset: 0x1814u);
      }
      p_m_iClass->m_Value = NextClassForTeam;
    }
  }
  v8 = this->CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  v9 = PlayerModelInfo::GetClassModelPath(this: &PlayerModelInfo::s_PlayerModelInfo, classID: p_m_iClass->m_Value);
  v8->SetModel(this, a2: v9);
}

//------------------------------------------------------------------------------
// Address: 0x102864B0
// Name: public: void CCSPlayer::ClearFlashbangScreenFade(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::ClearFlashbangScreenFade(CCSPlayer *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx
  color32_s clr; // [esp+18h] [ebp-4h] BYREF

  if ( this->m_blindUntilTime > gpGlobals->curtime )
  {
    clr = 0;
    UTIL_ScreenFade(pEntity: this, color: &clr, fadeTime: 0.0099999998, fadeHold: 0.0, flags: 18);
    if ( this->m_flFlashDuration.m_Value != 0.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x17C4u);
      }
      this->m_flFlashDuration.m_Value = 0.0;
    }
    if ( this->m_flFlashMaxAlpha.m_Value != 255.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v3 = this->m_Network.m_pPev;
        if ( v3 != nullptr )
          CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x17C8u);
      }
      this->m_flFlashMaxAlpha.m_Value = 255.0;
    }
  }
  this->m_blindUntilTime = 0.0;
  this->m_blindStartTime = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x102865A0
// Name: protected: virtual void CCSPlayer::CreateRagdollEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::CreateRagdollEntity(CCSPlayer *this)
{
  unsigned int m_Index; // eax
  CNetworkHandleBase<CBaseEntity,CCSPlayer::NetworkVar_m_hRagdoll> *p_m_hRagdoll; // edi
  IHandleEntity *m_pEntity; // eax
  CCSRagdoll *v5; // ebx
  IServerNetworkable *EntityByName; // eax
  CBaseEdict *v7; // ecx
  CBaseEdict *v8; // ecx
  CBaseEdict *v9; // ecx
  CBaseEdict *v10; // ecx
  CBaseEdict *v11; // ecx
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  m_Index = this->m_hRagdoll.m_Value.m_Index;
  p_m_hRagdoll = &this->m_hRagdoll;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v5 = (CCSRagdoll *)__RTDynamicCast(
                       inptr: m_pEntity,
                       VfDelta: 0,
                       SrcType: &CBaseEntity `RTTI Type Descriptor',
                       TargetType: &CCSRagdoll `RTTI Type Descriptor',
                       isReference: 0);
  if ( v5 != nullptr
    || (EntityByName = CreateEntityByName(className: "cs_ragdoll", iForceEdictIndex: -1, bNotify: true),
        (v5 = (CCSRagdoll *)__RTDynamicCast(
                              inptr: EntityByName,
                              VfDelta: 0,
                              SrcType: &CBaseEntity `RTTI Type Descriptor',
                              TargetType: &CCSRagdoll `RTTI Type Descriptor',
                              isReference: 0)) != nullptr) )
  {
    if ( (this->m_iEFlags & 0x1000) != 0 )
      CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
    if ( this->m_vecAbsVelocity.x != v5->m_vecRagdollVelocity.m_Value.x
      || this->m_vecAbsVelocity.y != v5->m_vecRagdollVelocity.m_Value.y
      || this->m_vecAbsVelocity.z != v5->m_vecRagdollVelocity.m_Value.z )
    {
      if ( v5->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v5->m_Network + 76) |= 1u;
      }
      else
      {
        v7 = &v5->m_Network.m_pPev->CBaseEdict;
        if ( v7 != nullptr )
          CBaseEdict::StateChanged(this: v7, offset: 0x4A4u);
      }
      v5->m_vecRagdollVelocity.m_Value.x = this->m_vecAbsVelocity.x;
      v5->m_vecRagdollVelocity.m_Value.y = this->m_vecAbsVelocity.y;
      v5->m_vecRagdollVelocity.m_Value.z = this->m_vecAbsVelocity.z;
    }
    if ( this->m_vecTotalBulletForce.x != v5->m_vecForce.m_Value.x
      || this->m_vecTotalBulletForce.y != v5->m_vecForce.m_Value.y
      || this->m_vecTotalBulletForce.z != v5->m_vecForce.m_Value.z )
    {
      if ( v5->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v5->m_Network + 76) |= 1u;
      }
      else
      {
        v8 = &v5->m_Network.m_pPev->CBaseEdict;
        if ( v8 != nullptr )
          CBaseEdict::StateChanged(this: v8, offset: 0x360u);
      }
      v5->m_vecForce.m_Value.x = this->m_vecTotalBulletForce.x;
      v5->m_vecForce.m_Value.y = this->m_vecTotalBulletForce.y;
      v5->m_vecForce.m_Value.z = this->m_vecTotalBulletForce.z;
    }
    CNetworkHandleBase<CBaseEntity,CCSRagdoll::NetworkVar_m_hPlayer>::Set(this: &v5->m_hPlayer, val: this);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    if ( this->m_vecAbsOrigin.x != v5->m_vecRagdollOrigin.m_Value.x
      || this->m_vecAbsOrigin.y != v5->m_vecRagdollOrigin.m_Value.y
      || this->m_vecAbsOrigin.z != v5->m_vecRagdollOrigin.m_Value.z )
    {
      if ( v5->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v5->m_Network + 76) |= 1u;
      }
      else
      {
        v9 = &v5->m_Network.m_pPev->CBaseEdict;
        if ( v9 != nullptr )
          CBaseEdict::StateChanged(this: v9, offset: 0x4B0u);
      }
      v5->m_vecRagdollOrigin.m_Value.x = this->m_vecAbsOrigin.x;
      v5->m_vecRagdollOrigin.m_Value.y = this->m_vecAbsOrigin.y;
      v5->m_vecRagdollOrigin.m_Value.z = this->m_vecAbsOrigin.z;
    }
    v5->m_nModelIndex.m_Value = this->m_nModelIndex.m_Value;
    v5->m_nForceBone.m_Value = this->m_nForceBone.m_Value;
    if ( v5->m_iDeathPose.m_Value != this->m_iDeathPose )
    {
      if ( v5->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v5->m_Network + 76) |= 1u;
      }
      else
      {
        v10 = &v5->m_Network.m_pPev->CBaseEdict;
        if ( v10 != nullptr )
          CBaseEdict::StateChanged(this: v10, offset: 0x4BCu);
      }
      v5->m_iDeathPose.m_Value = this->m_iDeathPose;
    }
    if ( v5->m_iDeathFrame.m_Value != this->m_iDeathFrame )
    {
      if ( v5->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&v5->m_Network + 76) |= 1u;
      }
      else
      {
        v11 = &v5->m_Network.m_pPev->CBaseEdict;
        if ( v11 != nullptr )
          CBaseEdict::StateChanged(this: v11, offset: 0x4C0u);
      }
      v5->m_iDeathFrame.m_Value = this->m_iDeathFrame;
    }
    CCSRagdoll::Init(this: v5, a2: (int)&savedregs);
  }
  CNetworkHandleBase<CBaseEntity,CCSPlayer::NetworkVar_m_hRagdoll>::Set(this: p_m_hRagdoll, val: v5);
}

//------------------------------------------------------------------------------
// Address: 0x102868A0
// Name: public: void CCSPlayer::HandleOutOfAmmoKnifeKills(class CCSPlayer __near *,class CWeaponCSBase __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSPlayer::HandleOutOfAmmoKnifeKills(
        CCSPlayer *this@<ecx>,
        int a2@<esi>,
        CCSPlayer *pAttackerPlayer,
        CWeaponCSBase *pAttackerWeapon)
{
  char v4; // bl
  CBaseCombatWeapon *v5; // eax
  CBaseCombatWeapon *v6; // eax
  bool v7; // zf
  char allPrimaryAndSecondariesOutOfAmmo_3; // [esp+Fh] [ebp+Fh]

  if ( pAttackerWeapon != nullptr && pAttackerWeapon->GetCSWeaponID(this: pAttackerWeapon) == WEAPON_KNIFE )
  {
    v4 = 0;
    allPrimaryAndSecondariesOutOfAmmo_3 = 1;
    if ( ((int (__thiscall *)(CCSPlayer *, _DWORD, int))pAttackerPlayer->Weapon_GetSlot)(
           a1: pAttackerPlayer,
           a2: 0,
           a3: a2) != 0 )
    {
      v4 = 1;
      v5 = pAttackerPlayer->Weapon_GetSlot(this: pAttackerPlayer, a2: 0);
      if ( v5 == nullptr || !CCSPlayer::DidPlayerEmptyAmmoForWeapon(this: pAttackerPlayer, pBaseWeapon: v5) )
        allPrimaryAndSecondariesOutOfAmmo_3 = 0;
    }
    if ( pAttackerPlayer->Weapon_GetSlot(this: pAttackerPlayer, a2: 1) != nullptr )
    {
      v6 = pAttackerPlayer->Weapon_GetSlot(this: pAttackerPlayer, a2: 1);
      if ( v6 == nullptr )
        return;
      v7 = !CCSPlayer::DidPlayerEmptyAmmoForWeapon(this: pAttackerPlayer, pBaseWeapon: v6);
    }
    else
    {
      v7 = v4 == 0;
    }
    if ( !v7 && allPrimaryAndSecondariesOutOfAmmo_3 != 0 )
      ++pAttackerPlayer->m_knifeKillsWhenOutOfAmmo;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10286950
// Name: private: void CCSPlayer::UpdateAddonBits(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::UpdateAddonBits(CCSPlayer *this)
{
  int v2; // ebx
  CCSAmmoDef *AmmoDef; // eax
  int v4; // eax
  int AmmoCount; // edi
  CBaseCombatWeapon *ActiveWeapon; // eax
  CCSAmmoDef *v7; // eax
  int v8; // eax
  CBaseCombatWeapon *v9; // eax
  CCSAmmoDef *v10; // eax
  int v11; // eax
  CBaseCombatWeapon *v12; // eax
  CCSAmmoDef *v13; // eax
  int v14; // eax
  CBaseCombatWeapon *v15; // eax
  CBaseCombatWeapon *v16; // eax
  CBaseCombatWeapon *v17; // eax
  CBaseCombatWeapon *v18; // edi
  int v19; // edi
  edict_t *v20; // ecx
  CBaseCombatWeapon *v21; // eax
  CBaseCombatWeapon *v22; // edi
  bool v23; // zf
  string_t (__thiscall *GetModelName)(struct CBaseEntity *); // edx
  int v25; // edi
  edict_t *m_pPev; // ecx
  edict_t *v27; // ecx
  edict_t *v28; // ecx
  edict_t *v29; // ecx
  int iNewBits; // [esp+Ch] [ebp-4h]

  v2 = 0;
  AmmoDef = GetAmmoDef();
  v4 = CAmmoDef::Index(this: AmmoDef, psz: "AMMO_TYPE_FLASHBANG");
  AmmoCount = CBaseCombatCharacter::GetAmmoCount(this, iAmmoIndex: v4);
  ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
  if ( __RTDynamicCast(
         inptr: ActiveWeapon,
         VfDelta: 0,
         SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
         TargetType: &CFlashbang `RTTI Type Descriptor',
         isReference: 0) != nullptr )
    --AmmoCount;
  if ( AmmoCount >= 1 )
    v2 = 1;
  if ( AmmoCount >= 2 )
    v2 |= 2u;
  v7 = GetAmmoDef();
  v8 = CAmmoDef::Index(this: v7, psz: "AMMO_TYPE_HEGRENADE");
  if ( CBaseCombatCharacter::GetAmmoCount(this, iAmmoIndex: v8) != 0 )
  {
    v9 = CBaseCombatCharacter::GetActiveWeapon(this);
    if ( __RTDynamicCast(
           inptr: v9,
           VfDelta: 0,
           SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
           TargetType: &CHEGrenade `RTTI Type Descriptor',
           isReference: 0) == nullptr )
      v2 |= 4u;
  }
  v10 = GetAmmoDef();
  v11 = CAmmoDef::Index(this: v10, psz: "AMMO_TYPE_SMOKEGRENADE");
  if ( CBaseCombatCharacter::GetAmmoCount(this, iAmmoIndex: v11) != 0 )
  {
    v12 = CBaseCombatCharacter::GetActiveWeapon(this);
    if ( __RTDynamicCast(
           inptr: v12,
           VfDelta: 0,
           SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
           TargetType: &CSmokeGrenade `RTTI Type Descriptor',
           isReference: 0) == nullptr )
      v2 |= 8u;
  }
  v13 = GetAmmoDef();
  v14 = CAmmoDef::Index(this: v13, psz: "AMMO_TYPE_DECOY");
  if ( CBaseCombatCharacter::GetAmmoCount(this, iAmmoIndex: v14) != 0 )
  {
    v15 = CBaseCombatCharacter::GetActiveWeapon(this);
    if ( __RTDynamicCast(
           inptr: v15,
           VfDelta: 0,
           SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
           TargetType: &CDecoyGrenade `RTTI Type Descriptor',
           isReference: 0) == nullptr )
      v2 |= 0x200u;
  }
  if ( this->Weapon_OwnsThisType(this, a2: "weapon_c4", a3: 0) != nullptr )
  {
    v16 = CBaseCombatCharacter::GetActiveWeapon(this);
    if ( __RTDynamicCast(
           inptr: v16,
           VfDelta: 0,
           SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
           TargetType: &CC4 `RTTI Type Descriptor',
           isReference: 0) == nullptr )
      v2 |= 0x10u;
  }
  if ( this->m_bHasDefuser.m_Value )
    v2 |= 0x20u;
  v17 = this->Weapon_GetSlot(this, a2: 0);
  v18 = (CBaseCombatWeapon *)__RTDynamicCast(
                               inptr: v17,
                               VfDelta: 0,
                               SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
                               TargetType: &CWeaponCSBase `RTTI Type Descriptor',
                               isReference: 0);
  if ( v18 == nullptr || v18 == CBaseCombatCharacter::GetActiveWeapon(this) )
  {
    if ( this->m_iPrimaryAddon.m_Value != 0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_iPrimaryAddon.m_Value = 0;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x18F8u);
        this->m_iPrimaryAddon.m_Value = 0;
      }
    }
  }
  else
  {
    v19 = ((int (__thiscall *)(CBaseCombatWeapon *))v18->__vftable[1].GetModelName)(a1: v18);
    if ( this->m_iPrimaryAddon.m_Value != v19 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v20 = this->m_Network.m_pPev;
        if ( v20 != nullptr )
          CBaseEdict::StateChanged(this: &v20->CBaseEdict, offset: 0x18F8u);
      }
      this->m_iPrimaryAddon.m_Value = v19;
    }
    v2 |= 0x40u;
  }
  v21 = this->Weapon_GetSlot(this, a2: 1);
  v22 = (CBaseCombatWeapon *)__RTDynamicCast(
                               inptr: v21,
                               VfDelta: 0,
                               SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
                               TargetType: &CWeaponCSBase `RTTI Type Descriptor',
                               isReference: 0);
  if ( v22 != nullptr )
  {
    v23 = v22 == CBaseCombatCharacter::GetActiveWeapon(this);
    GetModelName = v22->__vftable[1].GetModelName;
    if ( !v23 )
    {
      v2 |= 0x80u;
      iNewBits = v2;
      if ( ((int (__thiscall *)(CBaseCombatWeapon *))GetModelName)(a1: v22) != 2 )
      {
LABEL_34:
        v25 = ((int (__thiscall *)(CBaseCombatWeapon *))v22->__vftable[1].GetModelName)(a1: v22);
        if ( this->m_iSecondaryAddon.m_Value != v25 )
        {
          if ( this->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&this->m_Network + 76) |= 1u;
          }
          else
          {
            v27 = this->m_Network.m_pPev;
            if ( v27 != nullptr )
              CBaseEdict::StateChanged(this: &v27->CBaseEdict, offset: 0x18FCu);
          }
          this->m_iSecondaryAddon.m_Value = v25;
        }
        v2 = iNewBits;
        goto LABEL_47;
      }
LABEL_33:
      iNewBits = v2 | 0x100;
      goto LABEL_34;
    }
    if ( ((int (__thiscall *)(CBaseCombatWeapon *))GetModelName)(a1: v22) == 2 )
      goto LABEL_33;
  }
  if ( this->m_iSecondaryAddon.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_iSecondaryAddon.m_Value = 0;
    }
    else
    {
      v28 = this->m_Network.m_pPev;
      if ( v28 != nullptr )
        CBaseEdict::StateChanged(this: &v28->CBaseEdict, offset: 0x18FCu);
      this->m_iSecondaryAddon.m_Value = 0;
    }
  }
LABEL_47:
  if ( this->m_iAddonBits.m_Value != v2 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_iAddonBits.m_Value = v2;
    }
    else
    {
      v29 = this->m_Network.m_pPev;
      if ( v29 != nullptr )
        CBaseEdict::StateChanged(this: &v29->CBaseEdict, offset: 0x18F4u);
      this->m_iAddonBits.m_Value = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10286CD0
// Name: private: void CCSPlayer::UpdateRadar(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::UpdateRadar(CCSPlayer *this)
{
  float curtime; // xmm0_4
  CCSPlayer *v2; // ebx
  float v3; // xmm1_4
  CCSPlayer_vtbl *v4; // eax
  IVEngineServer_vtbl *v5; // esi
  int v6; // eax
  unsigned int v7; // edi
  CBasePlayer *v8; // eax
  CBasePlayer *v9; // esi
  CBaseEntity *v10; // eax
  CBaseEntity *v11; // esi
  int v12; // eax
  bool v13; // al
  double v14; // st7
  CSingleUserRecipientFilter user; // [esp+24h] [ebp-44h] BYREF
  _BYTE v16[12]; // [esp+44h] [ebp-24h] BYREF
  CBitVec<64> playerbits; // [esp+50h] [ebp-18h] BYREF
  int TeamNumber; // [esp+58h] [ebp-10h]
  int iValue; // [esp+5Ch] [ebp-Ch]
  CCSPlayer *v20; // [esp+60h] [ebp-8h]
  int v21; // [esp+64h] [ebp-4h]
  int savedregs; // [esp+68h] [ebp+0h] BYREF

  curtime = gpGlobals->curtime;
  v2 = this;
  v3 = this->m_flLastRadarUpdateTime + 1.0;
  v20 = this;
  if ( v3 <= curtime )
  {
    v4 = this->CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
    this->m_flLastRadarUpdateTime = curtime;
    playerbits = 0;
    v5 = engine->__vftable;
    v6 = ((int (__thiscall *)(CCSPlayer *, _BYTE *, CBitVec<64> *))v4->EyePosition)(a1: this, a2: v16, a3: &playerbits);
    ((void (__thiscall *)(IVEngineServer *, _DWORD, int))v5->Message_DetermineMulticastRecipients)(
      a1: engine,
      a2: 0,
      a3: v6);
    CRecipientFilter::CRecipientFilter(this: &user);
    user.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
    CRecipientFilter::AddRecipient(this: &user, player: v2);
    UserMessageBegin(filter: &user, messagename: "UpdateRadar");
    v7 = 0;
    v21 = 1;
    do
    {
      iValue = v7 + 1;
      v8 = UTIL_PlayerByIndex(playerIndex: v7 + 1);
      v9 = v8;
      if ( v8 != nullptr && v8->IsPlayer(this: v8) )
      {
        v10 = (CBaseEntity *)__RTDynamicCast(
                               inptr: v9,
                               VfDelta: 0,
                               SrcType: &CBaseEntity `RTTI Type Descriptor',
                               TargetType: &CCSPlayer `RTTI Type Descriptor',
                               isReference: 0);
        v11 = v10;
        if ( v10 != nullptr )
        {
          TeamNumber = CBaseEntity::GetTeamNumber(this: v10);
          v12 = CBaseEntity::GetTeamNumber(this: v2);
          v13 = TeamNumber == v12;
          if ( (v21 & playerbits.m_Ints[v7 >> 5]) != 0 && v13 )
          {
            v2 = v20;
          }
          else
          {
            v2 = v20;
            if ( v11 != v20
              && v11->IsAlive(this: v11)
              && ((int)v11[3].m_iParent.pszValue & 8) == 0
              && LODWORD(v11[4].m_Collision.m_vecMaxs.m_Value.x) != 2 )
            {
              MessageWriteByte(iValue);
              if ( (v11->m_iEFlags & 0x800) != 0 )
                CBaseEntity::CalcAbsolutePosition(this: v11, a2: (int)&savedregs);
              MessageWriteSBitLong(data: (int)(float)(v11->m_vecAbsOrigin.x * 0.25), numbits: 13);
              if ( (v11->m_iEFlags & 0x800) != 0 )
                CBaseEntity::CalcAbsolutePosition(this: v11, a2: (int)&savedregs);
              MessageWriteSBitLong(data: (int)(float)(v11->m_vecAbsOrigin.y * 0.25), numbits: 13);
              if ( (v11->m_iEFlags & 0x800) != 0 )
                CBaseEntity::CalcAbsolutePosition(this: v11, a2: (int)&savedregs);
              MessageWriteSBitLong(data: (int)(float)(v11->m_vecAbsOrigin.z * 0.25), numbits: 13);
              if ( (v11->m_iEFlags & 0x800) != 0 )
                CBaseEntity::CalcAbsolutePosition(this: v11, a2: (int)&savedregs);
              v14 = AngleNormalize(angle: v11->m_angAbsRotation.y);
              MessageWriteSBitLong(data: (int)v14, numbits: 9);
            }
          }
        }
      }
      v7 = iValue;
      v21 = __ROL4__(v21, 1);
    }
    while ( iValue < 64 );
    MessageWriteByte(iValue: 0);
    MessageEnd();
    CRecipientFilter::~CRecipientFilter(this: &user);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10286F40
// Name: public: virtual void CCSPlayer::PostThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::PostThink(CCSPlayer *this)
{
  CGameRules *v2; // edi
  CHintMessageQueue *m_pHintMessageQueue; // ecx
  float curtime; // xmm0_4
  bool v5; // zf
  CBaseCombatWeapon *ActiveWeapon; // edi
  bool (__thiscall *IsAlive)(CBaseEntity *); // eax
  CHintMessageQueue *v8; // ecx
  IGameEvent *v9; // eax
  IGameEvent *v10; // edi
  int v11; // eax
  CGameRules *v12; // ebx
  IGameEvent *v13; // eax
  IGameEvent *v14; // edi
  int v15; // eax
  CBaseCombatWeapon *v16; // eax
  void (__thiscall *SetBool)(IGameEvent *, const char *, bool); // edx
  IGameEvent *v18; // eax
  IGameEvent *v19; // edi
  int v20; // eax
  float z; // ecx
  const QAngle *v22; // ebx
  edict_t *m_pPev; // ecx
  _BYTE *v24; // ecx
  float m_applyDeafnessTime; // xmm0_4
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *p_m_timestamp; // edi
  double v27; // st7
  float m_Value; // xmm0_4
  edict_t *v29; // ecx
  QAngle angles; // [esp+94h] [ebp-10h] BYREF
  float v31; // [esp+A0h] [ebp-4h]

  CBasePlayer::PostThink(this);
  CCSPlayer::UpdateAddonBits(this);
  CCSPlayer::UpdateRadar(this);
  if ( (this->m_iDisplayHistoryBits & 2) == 0 && this->m_bInBuyZone.m_Value && !this->m_isVIP )
  {
    v2 = g_pGameRules;
    if ( this->m_lifeState.m_Value == 0
      && !CCSGameRules::IsBuyTimeElapsed(this: (CCSGameRules *)g_pGameRules)
      && !this->m_bIsVIP
      && (BYTE1(v2[136].m_pNext) == 0 || CBaseEntity::GetTeamNumber(this) != 3)
      && (LOBYTE(v2[136].m_pNext) == 0 || CBaseEntity::GetTeamNumber(this) != 2)
      && !this->m_bIsControllingBot.m_Value )
    {
      if ( this->IsAlive(this) && this->IsNetClient(this) )
      {
        m_pHintMessageQueue = this->m_pHintMessageQueue;
        if ( m_pHintMessageQueue != nullptr && this->m_bShowHints )
          CHintMessageQueue::AddMessage(
            this: m_pHintMessageQueue,
            message: "#Hint_press_buy_to_purchase",
            duration: 6.0,
            args: nullptr);
      }
      this->m_iDisplayHistoryBits |= 2u;
    }
  }
  curtime = gpGlobals->curtime;
  if ( curtime > this->m_flNextMouseoverUpdate )
  {
    v5 = !this->m_bShowHints;
    this->m_flNextMouseoverUpdate = curtime + 0.2;
    if ( !v5 )
      CCSPlayer::UpdateMouseoverHints(this);
  }
  if ( CBaseCombatCharacter::GetActiveWeapon(this) != nullptr && (this->m_iDisplayHistoryBits & 0x8000) == 0 )
  {
    ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
    if ( !ActiveWeapon->HasAnyAmmo(this: ActiveWeapon)
      && (CBaseCombatWeapon::GetWpnData(this: ActiveWeapon)->iFlags & 0x10) == 0 )
    {
      IsAlive = this->IsAlive;
      this->m_iDisplayHistoryBits |= 0x8000u;
      if ( IsAlive(this) && this->IsNetClient(this) )
      {
        v8 = this->m_pHintMessageQueue;
        if ( v8 != nullptr && this->m_bShowHints )
          CHintMessageQueue::AddMessage(this: v8, message: "#Hint_out_of_ammo", duration: 6.0, args: nullptr);
      }
    }
  }
  if ( this->m_bWasInBuyZone )
  {
    if ( this->m_bInBuyZone.m_Value && !this->m_isVIP )
      goto LABEL_56;
    this->m_bWasInBuyZone = false;
    v9 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "exit_buyzone", a3: 0, a4: 0);
  }
  else
  {
    if ( !this->m_bInBuyZone.m_Value || this->m_isVIP )
      goto LABEL_56;
    this->m_bWasInBuyZone = true;
    v9 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "enter_buyzone", a3: 0, a4: 0);
  }
  v10 = v9;
  if ( v9 != nullptr )
  {
    v11 = engine->GetPlayerUserId(this: engine, a2: this->m_Network.m_pPev);
    v10->SetInt(this: v10, a2: "userid", a3: v11);
    if ( this->m_bInBuyZone.m_Value && !this->m_isVIP )
    {
      v12 = g_pGameRules;
      if ( this->m_lifeState.m_Value != 0 )
      {
        LOBYTE(v31) = 0;
      }
      else if ( CCSGameRules::IsBuyTimeElapsed(this: (CCSGameRules *)g_pGameRules) )
      {
        LOBYTE(v31) = 0;
      }
      else if ( this->m_bIsVIP )
      {
        LOBYTE(v31) = 0;
      }
      else
      {
        LOBYTE(v31) = (BYTE1(v12[136].m_pNext) == 0 || CBaseEntity::GetTeamNumber(this) != 3)
                   && (LOBYTE(v12[136].m_pNext) == 0 || CBaseEntity::GetTeamNumber(this) != 2)
                   && !this->m_bIsControllingBot.m_Value;
      }
    }
    else
    {
      LOBYTE(v31) = 0;
    }
    ((void (__thiscall *)(IGameEvent *, const char *, float))v10->SetBool)(
      a1: v10,
      a2: "canbuy",
      a3: COERCE_FLOAT(LODWORD(v31)));
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v10, a3: false);
  }
LABEL_56:
  if ( this->m_bWasInBombZoneTrigger )
  {
    if ( this->m_bInBombZoneTrigger )
      goto LABEL_64;
    this->m_bWasInBombZoneTrigger = false;
    v13 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "exit_bombzone", a3: 0, a4: 0);
  }
  else
  {
    if ( !this->m_bInBombZoneTrigger )
      goto LABEL_64;
    this->m_bWasInBombZoneTrigger = true;
    v13 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "enter_bombzone", a3: 0, a4: 0);
  }
  v14 = v13;
  if ( v13 != nullptr )
  {
    v15 = engine->GetPlayerUserId(this: engine, a2: this->m_Network.m_pPev);
    v14->SetInt(this: v14, a2: "userid", a3: v15);
    v16 = this->Weapon_OwnsThisType(this, a2: "weapon_c4", a3: 0);
    SetBool = v14->SetBool;
    LOBYTE(v31) = v16 != nullptr;
    SetBool(this: v14, a2: "hasbomb", a3: LODWORD(v31));
    v14->SetBool(this: v14, a2: "isplanted", a3: (bool)g_pGameRules[144].m_pNext);
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v14, a3: false);
  }
LABEL_64:
  if ( this->m_bWasInHostageRescueZone )
  {
    if ( this->m_bInHostageRescueZone.m_Value )
      goto LABEL_72;
    this->m_bWasInHostageRescueZone = false;
    v18 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "exit_rescue_zone", a3: 0, a4: 0);
  }
  else
  {
    if ( !this->m_bInHostageRescueZone.m_Value )
      goto LABEL_72;
    this->m_bWasInHostageRescueZone = true;
    v18 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "enter_rescue_zone", a3: 0, a4: 0);
  }
  v19 = v18;
  if ( v18 != nullptr )
  {
    v20 = engine->GetPlayerUserId(this: engine, a2: this->m_Network.m_pPev);
    v19->SetInt(this: v19, a2: "userid", a3: v20);
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v19, a3: false);
  }
LABEL_72:
  z = this->m_angRotation.m_Value.z;
  angles.y = this->m_angRotation.m_Value.y;
  angles.z = z;
  angles.x = 0.0;
  CBaseEntity::SetLocalAngles(this, &angles);
  v22 = this->EyeAngles(this);
  if ( v22->x != this->m_angEyeAngles.m_Value.x
    || v22->y != this->m_angEyeAngles.m_Value.y
    || v22->z != this->m_angEyeAngles.m_Value.z )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x183Cu);
    }
    this->m_angEyeAngles.m_Value.x = v22->x;
    this->m_angEyeAngles.m_Value.y = v22->y;
    this->m_angEyeAngles.m_Value.z = v22->z;
  }
  v24 = &this->m_PlayerAnimState->gap4[*(_DWORD *)(*(_DWORD *)this->m_PlayerAnimState->gap4 + 4)];
  (*(void (__thiscall **)(_BYTE *, _DWORD, _DWORD))(*(_DWORD *)v24 + 4))(
    a1: v24,
    a2: LODWORD(this->m_angEyeAngles.m_Value.y),
    a3: LODWORD(this->m_angEyeAngles.m_Value.x));
  m_applyDeafnessTime = this->m_applyDeafnessTime;
  if ( m_applyDeafnessTime != 0.0 && gpGlobals->curtime >= m_applyDeafnessTime )
    CCSPlayer::ApplyDeafnessEffect(this);
  if ( this->m_bPlayerUnderwater && this->m_nWaterLevel.m_Value < 3u )
  {
    CBaseEntity::StopSound(this, soundname: "Player.AmbientUnderWater");
    this->SetPlayerUnderwater(this, a2: false);
  }
  if ( this->IsAlive(this) )
  {
    p_m_timestamp = &this->m_cycleLatchTimer.m_timestamp;
    if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_cycleLatchTimer) > this->m_cycleLatchTimer.m_timestamp.m_Value )
    {
      v27 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_cycleLatchTimer) + 0.2;
      v31 = v27;
      if ( p_m_timestamp->m_Value != v27 )
      {
        this->m_cycleLatchTimer.NetworkStateChanged(
          this: &this->m_cycleLatchTimer,
          a2: &this->m_cycleLatchTimer.m_timestamp);
        p_m_timestamp->m_Value = v31;
      }
      if ( this->m_cycleLatchTimer.m_duration.m_Value != 0.2 )
      {
        this->m_cycleLatchTimer.NetworkStateChanged(
          this: &this->m_cycleLatchTimer,
          a2: &this->m_cycleLatchTimer.m_duration);
        this->m_cycleLatchTimer.m_duration.m_Value = 0.2;
      }
      m_Value = this->m_flCycle.m_Value;
      v5 = !this->m_Network.m_TimerEvent.m_bRegistered;
      v31 = m_Value;
      if ( v5 )
      {
        v29 = this->m_Network.m_pPev;
        if ( v29 != nullptr )
        {
          CBaseEdict::StateChanged(this: &v29->CBaseEdict, offset: 0x1984u);
          m_Value = v31;
        }
      }
      else
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      this->m_cycleLatch.m_Value = (int)(float)(m_Value * 16.0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102875E0
// Name: public: void CCSPlayer::ClearGunGameImmunity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::ClearGunGameImmunity(CCSPlayer *this)
{
  edict_t *m_pPev; // ecx

  if ( this->m_bGunGameImmunity.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x1311u);
    }
    this->m_bGunGameImmunity.m_Value = false;
  }
  this->m_fImmuneToGunGameDamageTime = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10287630
// Name: public: void CCSPlayer::AddAccount(int,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::AddAccount(CCSPlayer *this, int amount, bool bTrackChange, bool bItemBought)
{
  CCSPlayer *v4; // edx
  int m_Value; // eax
  CNetworkVarBase<int,CCSPlayer::NetworkVar_m_iAccount> *p_m_iAccount; // esi
  int v7; // ebx
  edict_t *m_pPev; // ecx
  CNetworkVarBase<int,CCSPlayer::NetworkVar_m_iAccount> *v9; // eax
  CBaseEdict *v10; // ecx
  CNetworkVarBase<int,CCSPlayer::NetworkVar_m_iAccount> *v11; // eax
  CBaseEdict *v12; // ecx

  v4 = this;
  m_Value = this->m_iAccount.m_Value;
  p_m_iAccount = &this->m_iAccount;
  v7 = m_Value + amount;
  if ( m_Value != m_Value + amount )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
      {
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x1900u);
        v4 = this;
      }
    }
    p_m_iAccount->m_Value = v7;
  }
  if ( amount <= 0 )
  {
    if ( amount < 0 && bItemBought )
      CCSGameStats::Event_MoneySpent(this: &CCS_GameStats, pPlayer: v4, moneySpent: -amount);
  }
  else
  {
    CCSGameStats::Event_MoneyEarned(this: &CCS_GameStats, pPlayer: v4, moneyEarned: amount);
  }
  if ( p_m_iAccount->m_Value >= 0 )
  {
    if ( p_m_iAccount->m_Value > 16000 )
    {
      v11 = p_m_iAccount - 1600;
      if ( LOBYTE(p_m_iAccount[-1579].m_Value) != 0 )
      {
        LOBYTE(v11[22].m_Value) |= 1u;
        p_m_iAccount->m_Value = 16000;
      }
      else
      {
        v12 = (CBaseEdict *)v11[6].m_Value;
        if ( v12 != nullptr )
          CBaseEdict::StateChanged(this: v12, offset: 0x1900u);
        p_m_iAccount->m_Value = 16000;
      }
    }
  }
  else
  {
    v9 = p_m_iAccount - 1600;
    if ( LOBYTE(p_m_iAccount[-1579].m_Value) != 0 )
    {
      LOBYTE(v9[22].m_Value) |= 1u;
      p_m_iAccount->m_Value = 0;
    }
    else
    {
      v10 = (CBaseEdict *)v9[6].m_Value;
      if ( v10 != nullptr )
        CBaseEdict::StateChanged(this: v10, offset: 0x1900u);
      p_m_iAccount->m_Value = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10287740
// Name: public: void CCSPlayer::RemoveDefuser(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::RemoveDefuser(CCSPlayer *this)
{
  CNetworkVarBase<bool,CCSPlayer::NetworkVar_m_bHasDefuser> *p_m_bHasDefuser; // esi
  edict_t *m_pPev; // ecx

  p_m_bHasDefuser = &this->m_bHasDefuser;
  if ( this->m_bHasDefuser.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_bHasDefuser->m_Value = false;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x135Cu);
      p_m_bHasDefuser->m_Value = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10287780
// Name: public: void CCSPlayer::GiveDefuser(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::GiveDefuser(CCSPlayer *this, bool bPickedUp)
{
  IGameEvent *v3; // esi
  int v4; // eax
  edict_t *m_pPev; // ecx

  if ( !this->m_bHasDefuser.m_Value )
  {
    v3 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "item_pickup", a3: 0, a4: 0);
    if ( v3 != nullptr )
    {
      v4 = engine->GetPlayerUserId(this: engine, a2: this->m_Network.m_pPev);
      v3->SetInt(this: v3, a2: "userid", a3: v4);
      v3->SetString(this: v3, a2: "item", a3: "defuser");
      gameeventmanager->FireEvent(this: gameeventmanager, a2: v3, a3: false);
    }
  }
  if ( this->m_bHasDefuser.m_Value )
  {
    this->m_bPickedUpDefuser = bPickedUp;
  }
  else
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x135Cu);
    }
    this->m_bHasDefuser.m_Value = true;
    this->m_bPickedUpDefuser = bPickedUp;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10287850
// Name: public: virtual void CCSPlayer::Blind(float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSPlayer::Blind(
        CCSPlayer *this@<ecx>,
        int a2@<ebx>,
        float holdTime,
        float fadeTime,
        float startingAlpha)
{
  float m_blindStartTime; // xmm0_4
  float m_blindUntilTime; // xmm1_4
  float v8; // xmm0_4
  CCSPlayer_vtbl *v9; // eax
  int (__thiscall *GetObserverMode)(CBasePlayer *); // edx
  float v11; // xmm1_4
  float fadeHold; // xmm2_4
  float curtime; // xmm1_4
  float v14; // xmm2_4
  float m_Value; // xmm0_4
  edict_t *v16; // ecx
  edict_t *v17; // ecx
  float *p_holdTime; // eax
  float v19; // xmm0_4
  float v20; // xmm1_4
  edict_t *m_pPev; // ecx
  float v22; // xmm0_4
  CNetworkVarBase<float,CCSPlayer::NetworkVar_m_flFlashMaxAlpha> *p_m_flFlashMaxAlpha; // edi
  edict_t *v24; // ecx
  IGameEvent *v25; // esi
  int v26; // eax
  float oldBlindStartTime; // [esp+10h] [ebp-Ch]
  float oldBlindUntilTime; // [esp+14h] [ebp-8h]
  color32_s clr; // [esp+18h] [ebp-4h] BYREF

  m_blindStartTime = this->m_blindStartTime;
  m_blindUntilTime = this->m_blindUntilTime;
  clr.b = -1;
  oldBlindStartTime = m_blindStartTime;
  *(_WORD *)&clr.r = -1;
  clr.a = (int)startingAlpha;
  v8 = (float)(gpGlobals->curtime + holdTime) + (float)(fadeTime * 0.5);
  oldBlindUntilTime = m_blindUntilTime;
  if ( m_blindUntilTime > v8 )
    v8 = m_blindUntilTime;
  v9 = this->CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  this->m_blindUntilTime = v8;
  GetObserverMode = v9->GetObserverMode;
  this->m_blindStartTime = gpGlobals->curtime;
  if ( ((int (__thiscall *)(CCSPlayer *, int))GetObserverMode)(a1: this, a2) == 0 || this->GetObserverMode(this) == 4 )
  {
    curtime = gpGlobals->curtime;
    v14 = fadeTime * 0.7142857142857143;
    m_Value = this->m_flFlashDuration.m_Value;
    fadeTime = v14;
    if ( curtime <= oldBlindUntilTime )
    {
      holdTime = (float)(m_Value + oldBlindStartTime) - curtime;
      p_holdTime = &holdTime;
      if ( holdTime <= v14 )
        p_holdTime = &fadeTime;
      v20 = this->m_flFlashDuration.m_Value;
      fadeTime = *p_holdTime;
      v19 = fadeTime;
      if ( v20 != fadeTime )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
          {
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x17C4u);
            v19 = fadeTime;
          }
        }
        this->m_flFlashDuration.m_Value = v19;
      }
      if ( !CCSGameRules::IsIntermission(this: (CCSGameRules *)g_pGameRules) )
      {
        v22 = this->m_flFlashMaxAlpha.m_Value;
        p_m_flFlashMaxAlpha = &this->m_flFlashMaxAlpha;
        if ( v22 <= startingAlpha )
          p_m_flFlashMaxAlpha = (CNetworkVarBase<float,CCSPlayer::NetworkVar_m_flFlashMaxAlpha> *)&startingAlpha;
        if ( v22 != p_m_flFlashMaxAlpha->m_Value )
        {
          if ( this->m_Network.m_TimerEvent.m_bRegistered )
          {
            *((_BYTE *)&this->m_Network + 76) |= 1u;
          }
          else
          {
            v24 = this->m_Network.m_pPev;
            if ( v24 != nullptr )
              CBaseEdict::StateChanged(this: &v24->CBaseEdict, offset: 0x17C8u);
          }
          this->m_flFlashMaxAlpha.m_Value = p_m_flFlashMaxAlpha->m_Value;
        }
      }
    }
    else
    {
      if ( m_Value != v14 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v16 = this->m_Network.m_pPev;
          if ( v16 != nullptr )
          {
            CBaseEdict::StateChanged(this: &v16->CBaseEdict, offset: 0x17C4u);
            v14 = fadeTime;
          }
        }
        this->m_flFlashDuration.m_Value = v14;
      }
      if ( !CCSGameRules::IsIntermission(this: (CCSGameRules *)g_pGameRules)
        && this->m_flFlashMaxAlpha.m_Value != startingAlpha )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
          this->m_flFlashMaxAlpha.m_Value = startingAlpha;
        }
        else
        {
          v17 = this->m_Network.m_pPev;
          if ( v17 != nullptr )
            CBaseEdict::StateChanged(this: &v17->CBaseEdict, offset: 0x17C8u);
          this->m_flFlashMaxAlpha.m_Value = startingAlpha;
        }
      }
    }
    v25 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_blind", a3: 0, a4: 0);
    if ( v25 != nullptr )
    {
      v26 = engine->GetPlayerUserId(this: engine, a2: this->m_Network.m_pPev);
      v25->SetInt(this: v25, a2: "userid", a3: v26);
      gameeventmanager->FireEvent(this: gameeventmanager, a2: v25, a3: false);
    }
  }
  else if ( mp_fadetoblack.m_pParent == nullptr || mp_fadetoblack.m_pParent->m_Value.m_nValue == 0 )
  {
    v11 = fadeTime;
    clr.a = -106;
    if ( fadeTime >= 0.5 )
      v11 = 0.5;
    fadeHold = holdTime;
    if ( (float)(v11 * 0.5) <= holdTime )
      fadeHold = v11 * 0.5;
    UTIL_ScreenFade(pEntity: this, color: &clr, fadeTime: v11, fadeHold, flags: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10287B40
// Name: public: virtual void CCSPlayer::RemoveAllItems(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::RemoveAllItems(CCSPlayer *this, bool removeSuit)
{
  edict_t *m_pPev; // ecx
  edict_t *v4; // ecx
  edict_t *v5; // ecx
  edict_t *v6; // ecx

  if ( this->m_bHasDefuser.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x135Cu);
    }
    this->m_bHasDefuser.m_Value = false;
  }
  if ( this->m_bHasNightVision.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x135Du);
    }
    this->m_bHasNightVision.m_Value = false;
  }
  if ( this->m_bNightVisionOn.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x135Eu);
    }
    this->m_bNightVisionOn.m_Value = false;
  }
  *(_WORD *)&this->m_bPickedUpDefuser = 0;
  this->m_bPickedUpWeapon = false;
  this->m_bAttemptedDefusal = false;
  if ( removeSuit )
  {
    if ( this->m_bHasHelmet.m_Value )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v6 = this->m_Network.m_pPev;
        if ( v6 != nullptr )
          CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x1324u);
      }
      this->m_bHasHelmet.m_Value = false;
    }
    CBasePlayer::SetArmorValue(this, value: 0);
  }
  CBasePlayer::RemoveAllItems(this, removeSuit);
}

//------------------------------------------------------------------------------
// Address: 0x10287C50
// Name: public: void CCSPlayer::ObserverRoundRespawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::ObserverRoundRespawn(CCSPlayer *this)
{
  CCSPlayer::ClearFlashbangScreenFade(this);
  if ( this->m_szNewName[0] != 0 )
  {
    CCSPlayer::ChangeName(this, pszNewName: this->m_szNewName);
    this->m_szNewName[0] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10287C80
// Name: public: bool CCSPlayer::CSWeaponDrop(class CBaseCombatWeapon __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CCSPlayer::CSWeaponDrop@<al>(
        CCSPlayer *this@<ecx>,
        int a2@<ebx>,
        CBaseCombatWeapon *pWeapon,
        bool bDropShield,
        bool bThrowForward)
{
  char result; // al
  const QAngle *v8; // eax
  edict_t *m_pPev; // ecx
  CWeaponCSBase *v10; // ebx
  const CCSWeaponInfo *CSWpnData; // eax
  CBaseCombatWeapon *Weapon; // eax
  int v13; // ebx
  int v14; // eax
  void (__thiscall *Teleport)(CBaseEntity *, const Vector *, const QAngle *, const Vector *, bool); // edx
  IPhysicsObject *m_pPhysicsObject; // esi
  unsigned int v17; // eax
  __int64 v18; // xmm0_8
  void (__thiscall *AddVelocity)(IPhysicsObject *, const Vector *, const Vector *); // edx
  matrix3x4_t transform; // [esp+8h] [ebp-120h] BYREF
  matrix3x4_t rootInvLocal; // [esp+38h] [ebp-F0h] BYREF
  matrix3x4_t rootLocal; // [esp+68h] [ebp-C0h] BYREF
  QAngle vAngles; // [esp+98h] [ebp-90h] BYREF
  matrix3x4_t weaponMatrix; // [esp+A4h] [ebp-84h] BYREF
  Vector vPos; // [esp+D4h] [ebp-54h] BYREF
  QAngle angles; // [esp+E0h] [ebp-48h] BYREF
  Vector vecAdd; // [esp+ECh] [ebp-3Ch] BYREF
  Vector origin; // [esp+F8h] [ebp-30h] BYREF
  Vector vForward; // [esp+104h] [ebp-24h] BYREF
  Vector vTossPos; // [esp+110h] [ebp-18h] BYREF
  Vector angImp; // [esp+11Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+128h] [ebp+0h] BYREF
  int iAmmoIndex; // [esp+130h] [ebp+8h]
  IMDLCache *iAmmoIndexa; // [esp+130h] [ebp+8h]
  void (__thiscall **ib)(CWeaponCSBase *, char *); // [esp+138h] [ebp+10h]
  int i; // [esp+138h] [ebp+10h]
  int ia; // [esp+138h] [ebp+10h]

  result = 0;
  if ( pWeapon != nullptr )
  {
    v8 = this->EyeAngles(this);
    AngleVectors(angles: v8, forward: &vForward, right: nullptr, up: nullptr);
    vTossPos = *this->WorldSpaceCenter(this);
    if ( bThrowForward )
    {
      vTossPos.x = vTossPos.x + (float)(vForward.x * 64.0);
      vTossPos.y = vTossPos.y + (float)(vForward.y * 64.0);
      vTossPos.z = vTossPos.z + (float)(vForward.z * 64.0);
    }
    this->Weapon_Drop(this, a2: pWeapon, a3: &vTossPos, a4: nullptr);
    CCollisionProperty::SetSolidFlags(this: &pWeapon->m_Collision, flags: 0x98u);
    if ( pWeapon->m_MoveCollide.m_Value != 1 )
    {
      if ( pWeapon->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&pWeapon->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = pWeapon->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xD7u);
      }
      pWeapon->m_MoveCollide.m_Value = 1;
    }
    v10 = (CWeaponCSBase *)__RTDynamicCast(
                             inptr: pWeapon,
                             VfDelta: 0,
                             SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
                             TargetType: &CWeaponCSBase `RTTI Type Descriptor',
                             isReference: 0);
    if ( v10 != nullptr )
    {
      ib = (void (__thiscall **)(CWeaponCSBase *, char *))&v10->SetWeaponModelIndex;
      CSWpnData = CWeaponCSBase::GetCSWpnData(this: v10);
      (*ib)(a1: v10, a2: CSWpnData->szWorldModel);
      iAmmoIndex = v10->GetPrimaryAmmoType(this: v10);
      if ( iAmmoIndex != -1 )
      {
        if ( this->IsAlive(this) && this->m_iHealth.m_Value > 0 )
        {
          i = 0;
          while ( 1 )
          {
            Weapon = CBaseCombatCharacter::GetWeapon(this, i);
            if ( Weapon != nullptr && Weapon != pWeapon && Weapon->GetPrimaryAmmoType(this: Weapon) == iAmmoIndex )
              break;
            if ( ++i >= 64 )
              goto LABEL_19;
          }
        }
        else
        {
LABEL_19:
          if ( (unsigned __int8)CCSGameRules::IsPlayingGunGameSelect(this: (CCSGameRules *)g_pGameRules) == 0 )
          {
            v10->m_iExtraPrimaryAmmo = CBaseCombatCharacter::GetAmmoCount(this, iAmmoIndex);
            CBaseCombatCharacter::SetAmmoCount(this, iCount: 0, iAmmoIndex);
          }
        }
      }
    }
    iAmmoIndexa = mdlcache;
    ((void (*)(void))mdlcache->BeginLock)();
    v13 = CBaseAnimating::LookupBone(this, szName: "ValveBiped.weapon_bone");
    v14 = CBaseAnimating::LookupBone(this: pWeapon, szName: "ValveBiped.weapon_bone");
    ia = v14;
    if ( v13 == -1 || v14 == -1 )
    {
      v13 = CBaseAnimating::LookupBone(this, szName: "ValveBiped.Bip01_R_Hand");
      ia = 0;
    }
    if ( v13 != -1 )
    {
      this->GetBoneTransform(this, a2: v13, a3: &transform);
      CBaseEntity::StopFollowingEntity(this: pWeapon);
      memset((void *)&angImp, 0, sizeof(angImp));
      CBaseEntity::SetAbsOrigin(this: pWeapon, absOrigin: &angImp);
      memset((void *)&angImp, 0, sizeof(angImp));
      CBaseEntity::SetAbsAngles(this: pWeapon, absAngles: (const QAngle *)&angImp);
      pWeapon->InvalidateBoneCache(this: pWeapon);
      pWeapon->GetBoneTransform(this: pWeapon, a2: ia, a3: &rootLocal);
      MatrixInvert(in: &rootLocal, out: &rootInvLocal);
      ConcatTransforms(in1: &transform, in2: &rootInvLocal, out: &weaponMatrix);
      MatrixAngles(a1: (int)pWeapon, src: (const VMatrix *)&weaponMatrix, vAngles: &angles);
      Teleport = pWeapon->Teleport;
      origin.x = weaponMatrix.m_flMatVal[0][3];
      origin.y = weaponMatrix.m_flMatVal[1][3];
      origin.z = weaponMatrix.m_flMatVal[2][3];
      Teleport(this: pWeapon, a2: &origin, a3: &angles, a4: nullptr, a5: true);
      m_pPhysicsObject = pWeapon->m_pPhysicsObject;
      if ( m_pPhysicsObject != nullptr )
      {
        ((void (__thiscall *)(IPhysicsObject *, Vector *, QAngle *, int))m_pPhysicsObject->GetPosition)(
          a1: m_pPhysicsObject,
          a2: &vPos,
          a3: &vAngles,
          a4: a2);
        m_pPhysicsObject->SetPosition(this: m_pPhysicsObject, a2: &vPos, a3: &angles, a4: true);
        v17 = (unsigned int)this->m_iEFlags >> 12;
        memset((void *)&angImp, 0, sizeof(angImp));
        if ( (v17 & 1) != 0 )
          CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
        v18 = *(_QWORD *)&this->m_vecAbsVelocity.x;
        AddVelocity = m_pPhysicsObject->AddVelocity;
        vecAdd.z = this->m_vecAbsVelocity.z;
        *(_QWORD *)&vecAdd.x = v18;
        ((void (__thiscall *)(IPhysicsObject *, Vector *))AddVelocity)(a1: m_pPhysicsObject, a2: &vecAdd);
      }
    }
    iAmmoIndexa->EndLock(this: iAmmoIndexa);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10288030
// Name: protected: void CCSPlayer::TransferInventory(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::TransferInventory(CCSPlayer *this, CCSPlayer *pTargetPlayer)
{
  CCSPlayer *v2; // esi
  int i; // ebx
  CBaseCombatWeapon *Weapon; // eax
  CCSPlayer_vtbl *v5; // esi
  int v6; // eax
  CNetworkVarBase<bool,CCSPlayer::NetworkVar_m_bHasNightVision> *p_m_bHasNightVision; // ebx
  CBaseEdict *v8; // ecx
  edict_t *m_pPev; // ecx
  edict_t *v10; // ecx

  v2 = this;
  pTargetPlayer->RemoveAllItems(this: pTargetPlayer, a2: true);
  for ( i = 0; i < 64; ++i )
  {
    Weapon = CBaseCombatCharacter::GetWeapon(this: v2, i);
    if ( Weapon != nullptr )
    {
      v5 = pTargetPlayer->CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
      v6 = ((int (__thiscall *)(CBaseCombatWeapon *, _DWORD))Weapon->GetName)(a1: Weapon, a2: 0);
      ((void (__thiscall *)(CCSPlayer *, int))v5->GiveNamedItem)(a1: pTargetPlayer, a2: v6);
      v2 = this;
    }
  }
  if ( v2->m_bHasDefuser.m_Value )
    CCSPlayer::GiveDefuser(this: pTargetPlayer, bPickedUp: false);
  CBasePlayer::SetArmorValue(this: pTargetPlayer, value: v2->m_ArmorValue.m_Value);
  pTargetPlayer->m_bHasHelmet.m_Value = v2->m_bHasHelmet.m_Value;
  p_m_bHasNightVision = &this->m_bHasNightVision;
  pTargetPlayer->m_bHasNightVision.m_Value = this->m_bHasNightVision.m_Value;
  CBasePlayer::SetArmorValue(this, value: 0);
  if ( v2->m_bHasHelmet.m_Value )
  {
    if ( v2->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v2->m_Network + 76) |= 1u;
    }
    else
    {
      v8 = &v2->m_Network.m_pPev->CBaseEdict;
      if ( v8 != nullptr )
        CBaseEdict::StateChanged(this: v8, offset: 0x1324u);
    }
    v2->m_bHasHelmet.m_Value = false;
  }
  if ( p_m_bHasNightVision->m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x135Du);
    }
    p_m_bHasNightVision->m_Value = false;
  }
  if ( this->m_bNightVisionOn.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v10 = this->m_Network.m_pPev;
      if ( v10 != nullptr )
        CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0x135Eu);
    }
    this->m_bNightVisionOn.m_Value = false;
  }
  this->RemoveAllItems(this, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x10288180
// Name: protected: bool CCSPlayer::DropRifle(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSPlayer::DropRifle(CCSPlayer *this, bool fromDeath)
{
  CBaseCombatWeapon *v3; // eax

  v3 = this->Weapon_GetSlot(this, a2: 0);
  if ( v3 != nullptr )
    return CCSPlayer::CSWeaponDrop(this, a2: 0, pWeapon: v3, bDropShield: false, bThrowForward: false);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102881B0
// Name: protected: bool CCSPlayer::DropPistol(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSPlayer::DropPistol(CCSPlayer *this, bool fromDeath)
{
  CBaseCombatWeapon *v3; // eax
  char result; // al

  v3 = this->Weapon_GetSlot(this, a2: 1);
  if ( v3 == nullptr )
    return 0;
  result = CCSPlayer::CSWeaponDrop(this, a2: 0, pWeapon: v3, bDropShield: false, bThrowForward: false);
  this->m_bUsingDefaultPistol = false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102881F0
// Name: protected: enum BuyResult_e CCSPlayer::AttemptToBuyVest(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CCSPlayer::AttemptToBuyVest@<eax>(CCSPlayer *this@<ecx>, int a2@<edi>)
{
  int BlackMarketPriceForWeapon; // ebx
  IGameEvent *v5; // edi
  int v6; // eax

  BlackMarketPriceForWeapon = 650;
  if ( HIBYTE(g_pGameRules[48].__vftable) != 0 )
    BlackMarketPriceForWeapon = CCSGameRules::GetBlackMarketPriceForWeapon(
                                  this: (CCSGameRules *)g_pGameRules,
                                  iWeaponID: 39);
  if ( this->m_ArmorValue.m_Value < 100 )
  {
    if ( this->m_iAccount.m_Value >= BlackMarketPriceForWeapon )
    {
      if ( this->m_bHasHelmet.m_Value && !this->m_bIsInAutoBuy && !this->m_bIsInRebuy )
        ClientPrint(
          player: this,
          msg_dest: 4u,
          msg_name: "#Already_Have_Helmet_Bought_Kevlar",
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
      v5 = (IGameEvent *)((int (__thiscall *)(IGameEventManager2 *, const char *, _DWORD, _DWORD, int))gameeventmanager->CreateEventA)(
                           a1: gameeventmanager,
                           a2: "item_pickup",
                           a3: 0,
                           a4: 0,
                           a5: a2);
      if ( v5 != nullptr )
      {
        v6 = engine->GetPlayerUserId(this: engine, a2: this->m_Network.m_pPev);
        v5->SetInt(this: v5, a2: "userid", a3: v6);
        v5->SetString(this: v5, a2: "item", a3: "vest");
        gameeventmanager->FireEvent(this: gameeventmanager, a2: v5, a3: false);
      }
      ((void (__thiscall *)(CCSPlayer *, const char *))this->GiveNamedItem)(a1: this, a2: "item_kevlar");
      CCSPlayer::AddAccount(this, amount: -BlackMarketPriceForWeapon, bTrackChange: true, bItemBought: true);
      BlackMarketAddWeapon(pWeaponName: "item_kevlar", pBuyer: this);
      return 0;
    }
    else
    {
      if ( !this->m_bIsInAutoBuy && !this->m_bIsInRebuy )
        ClientPrint(
          player: this,
          msg_dest: 4u,
          msg_name: "#Not_Enough_Money",
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
      return 2;
    }
  }
  else
  {
    if ( !this->m_bIsInAutoBuy && !this->m_bIsInRebuy )
      ClientPrint(
        player: this,
        msg_dest: 4u,
        msg_name: "#Already_Have_Kevlar",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10288350
// Name: protected: enum BuyResult_e CCSPlayer::AttemptToBuyAssaultSuit(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CCSPlayer::AttemptToBuyAssaultSuit@<eax>(CCSPlayer *this@<ecx>, int a2@<edi>)
{
  IGameEvent *v4; // edi
  int v5; // eax

  if ( this->m_ArmorValue.m_Value < 100 )
  {
    if ( this->m_bHasHelmet.m_Value )
    {
      if ( this->m_iAccount.m_Value >= 0 )
      {
        if ( !this->m_bIsInAutoBuy && !this->m_bIsInRebuy )
          ClientPrint(
            player: this,
            msg_dest: 4u,
            msg_name: "#Already_Have_Helmet_Bought_Kevlar",
            param1: nullptr,
            param2: nullptr,
            param3: nullptr,
            param4: nullptr);
        goto LABEL_11;
      }
    }
    else if ( this->m_iAccount.m_Value >= 0 )
    {
LABEL_11:
      v4 = (IGameEvent *)((int (__thiscall *)(IGameEventManager2 *, const char *, _DWORD, _DWORD, int))gameeventmanager->CreateEventA)(
                           a1: gameeventmanager,
                           a2: "item_pickup",
                           a3: 0,
                           a4: 0,
                           a5: a2);
      if ( v4 != nullptr )
      {
        v5 = engine->GetPlayerUserId(this: engine, a2: this->m_Network.m_pPev);
        v4->SetInt(this: v4, a2: "userid", a3: v5);
        v4->SetString(this: v4, a2: "item", a3: "vesthelm");
        gameeventmanager->FireEvent(this: gameeventmanager, a2: v4, a3: false);
      }
      ((void (__thiscall *)(CCSPlayer *, const char *))this->GiveNamedItem)(a1: this, a2: "item_assaultsuit");
      CCSPlayer::AddAccount(this, amount: 0, bTrackChange: true, bItemBought: true);
      BlackMarketAddWeapon(pWeaponName: "item_assaultsuit", pBuyer: this);
      return 0;
    }
  }
  else
  {
    if ( this->m_bHasHelmet.m_Value )
    {
      if ( !this->m_bIsInAutoBuy && !this->m_bIsInRebuy )
        ClientPrint(
          player: this,
          msg_dest: 4u,
          msg_name: "#Already_Have_Kevlar_Helmet",
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
      return 1;
    }
    if ( this->m_iAccount.m_Value >= 0 )
    {
      if ( !this->m_bIsInAutoBuy && !this->m_bIsInRebuy )
        ClientPrint(
          player: this,
          msg_dest: 4u,
          msg_name: "#Already_Have_Kevlar_Bought_Helmet",
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
      goto LABEL_11;
    }
  }
  if ( !this->m_bIsInAutoBuy && !this->m_bIsInRebuy )
    ClientPrint(
      player: this,
      msg_dest: 4u,
      msg_name: "#Not_Enough_Money",
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x102884F0
// Name: protected: enum BuyResult_e CCSPlayer::AttemptToBuyNightVision(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSPlayer::AttemptToBuyNightVision(CCSPlayer *this)
{
  int BlackMarketPriceForWeapon; // ebx
  edict_t *m_pPev; // eax
  edict_t *v5; // ecx
  IGameEvent *v6; // edi
  int v7; // eax
  CHintMessageQueue *m_pHintMessageQueue; // ecx
  CPASAttenuationFilter filter; // [esp+3Ch] [ebp-20h] BYREF

  BlackMarketPriceForWeapon = 1250;
  if ( HIBYTE(g_pGameRules[48].__vftable) != 0 )
    BlackMarketPriceForWeapon = CCSGameRules::GetBlackMarketPriceForWeapon(
                                  this: (CCSGameRules *)g_pGameRules,
                                  iWeaponID: 41);
  if ( this->m_bHasNightVision.m_Value )
  {
    if ( !this->m_bIsInAutoBuy && !this->m_bIsInRebuy )
      ClientPrint(
        player: this,
        msg_dest: 4u,
        msg_name: "#Already_Have_One",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
    return 1;
  }
  else if ( this->m_iAccount.m_Value >= BlackMarketPriceForWeapon )
  {
    CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: this, lookupSound: "Player.PickupWeapon");
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      m_pPev -= (int)gpGlobals->pEdicts;
    CBaseEntity::EmitSound(
      &filter,
      iEntIndex: (int)m_pPev,
      soundname: "Player.PickupWeapon",
      pOrigin: nullptr,
      soundtime: 0.0,
      duration: nullptr);
    if ( !this->m_bHasNightVision.m_Value )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v5 = this->m_Network.m_pPev;
        if ( v5 != nullptr )
          CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x135Du);
      }
      this->m_bHasNightVision.m_Value = true;
    }
    CCSPlayer::AddAccount(this, amount: -BlackMarketPriceForWeapon, bTrackChange: true, bItemBought: true);
    BlackMarketAddWeapon(pWeaponName: "nightvision", pBuyer: this);
    v6 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "item_pickup", a3: 0, a4: 0);
    if ( v6 != nullptr )
    {
      v7 = engine->GetPlayerUserId(this: engine, a2: this->m_Network.m_pPev);
      v6->SetInt(this: v6, a2: "userid", a3: v7);
      v6->SetString(this: v6, a2: "item", a3: "nvgs");
      gameeventmanager->FireEvent(this: gameeventmanager, a2: v6, a3: false);
    }
    if ( (this->m_iDisplayHistoryBits & 0x100000) == 0 )
    {
      if ( this->IsAlive(this) && this->IsNetClient(this) )
      {
        m_pHintMessageQueue = this->m_pHintMessageQueue;
        if ( m_pHintMessageQueue != nullptr && this->m_bShowHints )
          CHintMessageQueue::AddMessage(
            this: m_pHintMessageQueue,
            message: "#Hint_use_nightvision",
            duration: 6.0,
            args: nullptr);
      }
      this->m_iDisplayHistoryBits |= 0x100000u;
    }
    CRecipientFilter::~CRecipientFilter(this: &filter);
    return 0;
  }
  else
  {
    if ( !this->m_bIsInAutoBuy && !this->m_bIsInRebuy )
      ClientPrint(
        player: this,
        msg_dest: 4u,
        msg_name: "#Not_Enough_Money",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
    return 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10288700
// Name: protected: enum BuyResult_e CCSPlayer::BuyGunAmmo(class CBaseCombatWeapon __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSPlayer::BuyGunAmmo(CCSPlayer *this, CBaseCombatWeapon *pWeapon, bool bBlinkMoney)
{
  CGameRules *v4; // edi
  int v6; // eax
  int v7; // edi
  CCSAmmoDef *AmmoDef; // eax
  int v9; // ebx
  CCSAmmoDef *CSAmmoDef; // eax
  CCSPlayer_vtbl *v11; // ebx
  CCSAmmoDef *v12; // eax
  int BuySize; // eax
  CCSAmmoDef *v14; // eax
  int Cost; // eax
  int v16; // [esp-Ch] [ebp-14h]

  if ( !this->m_bInBuyZone.m_Value )
    return 3;
  if ( this->m_isVIP )
    return 3;
  v4 = g_pGameRules;
  if ( this->m_lifeState.m_Value != 0
    || CCSGameRules::IsBuyTimeElapsed(this: (CCSGameRules *)g_pGameRules)
    || this->m_bIsVIP
    || BYTE1(v4[136].m_pNext) != 0 && CBaseEntity::GetTeamNumber(this) == 3 )
  {
    return 3;
  }
  if ( LOBYTE(v4[136].m_pNext) != 0 && CBaseEntity::GetTeamNumber(this) == 2 || this->m_bIsControllingBot.m_Value )
    return 3;
  v6 = pWeapon->GetPrimaryAmmoType(this: pWeapon);
  v7 = v6;
  if ( v6 == -1 )
    return 1;
  v16 = v6;
  AmmoDef = GetAmmoDef();
  v9 = CAmmoDef::MaxCarry(this: AmmoDef, nAmmoIndex: v16, owner: this);
  if ( CBaseCombatCharacter::GetAmmoCount(this, iAmmoIndex: v7) >= v9 )
    return 1;
  CSAmmoDef = GetCSAmmoDef();
  if ( this->m_iAccount.m_Value < CCSAmmoDef::GetCost(this: CSAmmoDef, index: v7) )
  {
    if ( bBlinkMoney && !this->m_bIsInAutoBuy && !this->m_bIsInRebuy )
      ClientPrint(
        player: this,
        msg_dest: 4u,
        msg_name: "#Not_Enough_Money",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
    return 2;
  }
  else
  {
    v11 = this->CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
    v12 = GetCSAmmoDef();
    BuySize = CCSAmmoDef::GetBuySize(this: v12, index: v7);
    v11->GiveAmmo(this, a2: BuySize, a3: v7, a4: true);
    v14 = GetCSAmmoDef();
    Cost = CCSAmmoDef::GetCost(this: v14, index: v7);
    CCSPlayer::AddAccount(this, amount: -Cost, bTrackChange: true, bItemBought: true);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10288850
// Name: protected: enum BuyResult_e CCSPlayer::BuyAmmo(int,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSPlayer::BuyAmmo(CCSPlayer *this, unsigned int nSlot, bool bBlinkMoney)
{
  CGameRules *v4; // edi
  CBaseCombatWeapon *v6; // eax

  if ( !this->m_bInBuyZone.m_Value )
    return 3;
  if ( this->m_isVIP )
    return 3;
  v4 = g_pGameRules;
  if ( this->m_lifeState.m_Value != 0
    || CCSGameRules::IsBuyTimeElapsed(this: (CCSGameRules *)g_pGameRules)
    || this->m_bIsVIP
    || BYTE1(v4[136].m_pNext) != 0 && CBaseEntity::GetTeamNumber(this) == 3 )
  {
    return 3;
  }
  if ( LOBYTE(v4[136].m_pNext) != 0 && CBaseEntity::GetTeamNumber(this) == 2 || this->m_bIsControllingBot.m_Value )
    return 3;
  if ( nSlot <= 1 )
  {
    v6 = this->Weapon_GetSlot(this, a2: nSlot);
    if ( v6 != nullptr )
      return CCSPlayer::BuyGunAmmo(this, pWeapon: v6, bBlinkMoney);
  }
  return 5;
}

//------------------------------------------------------------------------------
// Address: 0x10288900
// Name: protected: enum BuyResult_e CCSPlayer::AttemptToBuyAmmo(int)
// Source: json
//------------------------------------------------------------------------------
BuyResult_e __thiscall CCSPlayer::AttemptToBuyAmmo(CCSPlayer *this, unsigned int iAmmoType)
{
  BuyResult_e result; // eax
  CGameRules *v4; // edi
  CBaseCombatWeapon *v5; // eax

  result = CCSPlayer::BuyAmmo(this, nSlot: iAmmoType, bBlinkMoney: true);
  if ( result == BUY_BOUGHT )
  {
    do
    {
      if ( !this->m_bInBuyZone.m_Value )
        break;
      if ( this->m_isVIP )
        break;
      v4 = g_pGameRules;
      if ( this->m_lifeState.m_Value != 0
        || CCSGameRules::IsBuyTimeElapsed(this: (CCSGameRules *)g_pGameRules)
        || this->m_bIsVIP
        || BYTE1(v4[136].m_pNext) != 0 && CBaseEntity::GetTeamNumber(this) == 3 )
      {
        break;
      }
      if ( LOBYTE(v4[136].m_pNext) != 0 && CBaseEntity::GetTeamNumber(this) == 2 )
        break;
      if ( this->m_bIsControllingBot.m_Value )
        break;
      if ( iAmmoType > 1 )
        break;
      v5 = this->Weapon_GetSlot(this, a2: iAmmoType);
      if ( v5 == nullptr )
        break;
    }
    while ( CCSPlayer::BuyGunAmmo(this, pWeapon: v5, bBlinkMoney: false) == 0 );
    return BUY_BOUGHT;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102889C0
// Name: protected: enum BuyResult_e CCSPlayer::AttemptToBuyAmmoSingle(int)
// Source: json
//------------------------------------------------------------------------------
BuyResult_e __userpurge CCSPlayer::AttemptToBuyAmmoSingle@<eax>(
        CCSPlayer *this@<ecx>,
        int a2@<ebx>,
        unsigned int iAmmoType)
{
  BuyResult_e result; // eax

  result = CCSPlayer::BuyAmmo(this, nSlot: iAmmoType, bBlinkMoney: true);
  if ( result == BUY_BOUGHT )
  {
    CCSPlayer::BuildRebuyStruct(this, a2, a3: (int)this);
    return BUY_BOUGHT;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102889F0
// Name: public: bool CCSPlayer::HandleCommand_JoinTeam(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSPlayer::HandleCommand_JoinTeam(CCSPlayer *this, int team)
{
  CCSGameRules *v2; // ebx
  int HumanTeam; // esi
  bool v6; // al
  int v7; // eax
  void (__thiscall *CommitSuicide)(CBasePlayer *, bool, bool); // eax
  edict_t *m_pPev; // ecx
  unsigned int TeamNumber; // eax
  const char *v11; // eax

  v2 = (CCSGameRules *)g_pGameRules;
  HumanTeam = team;
  if ( GetGlobalTeam(iIndex: team) == nullptr )
  {
    DevWarning(a1: "HandleCommand_JoinTeam( %d ) - invalid team index.\n", HumanTeam);
    return 0;
  }
  if ( this->m_bTeamChanged && HumanTeam != this->m_iOldTeam && HumanTeam != 1 )
  {
    ClientPrint(
      player: this,
      msg_dest: 4u,
      msg_name: "#Only_1_Team_Change",
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
    return 1;
  }
  if ( HumanTeam == 0 && (this->IsBot(this) || (HumanTeam = CCSGameRules::GetHumanTeam(this: v2)) == 0) )
  {
    v6 = this->IsBot(this);
    HumanTeam = CCSGameRules::SelectDefaultTeam(this: v2, ignoreBots: !v6);
    if ( HumanTeam == 0 )
    {
      if ( cv_bot_auto_vacate.m_pParent == nullptr
        || cv_bot_auto_vacate.m_pParent->m_Value.m_nValue == 0
        || this->IsBot(this)
        || (HumanTeam = (random->RandomInt(this: random, a2: 0, a3: 1) != 0) + 2,
            !UTIL_KickBotFromTeam(kickTeam: HumanTeam))
        && (HumanTeam = (HumanTeam != 3) + 2, !UTIL_KickBotFromTeam(kickTeam: HumanTeam))
        || HumanTeam == 0 )
      {
        ClientPrint(
          player: this,
          msg_dest: 4u,
          msg_name: "#All_Teams_Full",
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
LABEL_18:
        this->ShowViewPortPanel(this, a2: "team", a3: true, a4: nullptr);
        return 0;
      }
    }
  }
  if ( HumanTeam == CBaseEntity::GetTeamNumber(this) )
  {
    if ( CBaseEntity::GetTeamNumber(this) == 2 || CBaseEntity::GetTeamNumber(this) == 3 )
    {
      engine->ClientCommand(this: engine, a2: this->m_Network.m_pPev, a3: "joinclass\n");
      return 1;
    }
    return 1;
  }
  if ( CCSGameRules::TeamFull(this: v2, team_id: HumanTeam)
    && (cv_bot_auto_vacate.m_pParent == nullptr
     || cv_bot_auto_vacate.m_pParent->m_Value.m_nValue == 0
     || this->IsBot(this)
     || HumanTeam == 1
     || !UTIL_KickBotFromTeam(kickTeam: HumanTeam)) )
  {
    switch ( HumanTeam )
    {
      case 2:
        ClientPrint(
          player: this,
          msg_dest: 4u,
          msg_name: "#Terrorists_Full",
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
        break;
      case 3:
        ClientPrint(
          player: this,
          msg_dest: 4u,
          msg_name: "#CTs_Full",
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
        break;
      case 1:
        ClientPrint(
          player: this,
          msg_dest: 4u,
          msg_name: "#Cannot_Be_Spectator",
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
        break;
      default:
        break;
    }
    goto LABEL_18;
  }
  if ( !this->IsBot(this) )
  {
    if ( HumanTeam == 1 )
      goto LABEL_44;
    v7 = CCSGameRules::GetHumanTeam(this: v2);
    if ( v7 != 0 && v7 != HumanTeam )
    {
      if ( v7 == 2 )
      {
        ClientPrint(
          player: this,
          msg_dest: 4u,
          msg_name: "#Humans_Join_Team_T",
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
      }
      else if ( v7 == 3 )
      {
        ClientPrint(
          player: this,
          msg_dest: 4u,
          msg_name: "#Humans_Join_Team_CT",
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
      }
      goto LABEL_18;
    }
  }
  if ( HumanTeam != 1 )
  {
    TeamNumber = CBaseEntity::GetTeamNumber(this);
    if ( CCSGameRules::TeamStacked(this: v2, newTeam_id: HumanTeam, curTeam_id: TeamNumber)
      && (cv_bot_auto_vacate.m_pParent == nullptr
       || cv_bot_auto_vacate.m_pParent->m_Value.m_nValue == 0
       || this->IsBot(this)
       || !UTIL_KickBotFromTeam(kickTeam: HumanTeam)) )
    {
      v11 = "#Too_Many_Terrorists";
      if ( HumanTeam != 2 )
        v11 = "#Too_Many_CTs";
      ClientPrint(
        player: this,
        msg_dest: 4u,
        msg_name: v11,
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      goto LABEL_18;
    }
    this->ChangeTeam(this, a2: HumanTeam);
    return 1;
  }
LABEL_44:
  if ( (mp_allowspectators.m_pParent == nullptr || mp_allowspectators.m_pParent->m_Value.m_nValue == 0)
    && !this->pl.hltv )
  {
    ClientPrint(
      player: this,
      msg_dest: 4u,
      msg_name: "#Cannot_Be_Spectator",
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
    return 0;
  }
  if ( CBaseEntity::GetTeamNumber(this) != 0 && this->m_iPlayerState.m_Value == STATE_ACTIVE )
  {
    CommitSuicide = this->CommitSuicide;
    this->m_fNextSuicideTime = gpGlobals->curtime;
    CommitSuicide(this, a2: false, a3: false);
    this->IncrementFragCount(this, a2: 1);
  }
  this->ChangeTeam(this, a2: 1);
  if ( this->m_iClass.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x1814u);
    }
    this->m_iClass.m_Value = 0;
  }
  if ( mp_fadetoblack.m_pParent != nullptr && mp_fadetoblack.m_pParent->m_Value.m_nValue != 0 )
  {
    team = -16777216;
    UTIL_ScreenFade(pEntity: this, color: (const color32_s *)&team, fadeTime: 0.0, fadeHold: 0.0, flags: 17);
    return 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10288DF0
// Name: public: void CCSPlayer::SetProgressBarTime(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::SetProgressBarTime(CCSPlayer *this, int barTime)
{
  edict_t *m_pPev; // ecx
  edict_t *v4; // ecx

  if ( this->m_iProgressBarDuration.m_Value != barTime )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x17D0u);
    }
    this->m_iProgressBarDuration.m_Value = barTime;
  }
  if ( this->m_flProgressBarStartTime.m_Value != this->m_flSimulationTime.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_flProgressBarStartTime.m_Value = this->m_flSimulationTime.m_Value;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x17CCu);
      this->m_flProgressBarStartTime.m_Value = this->m_flSimulationTime.m_Value;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10288E80
// Name: public: virtual void CCSPlayer::PlayerForceTeamThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::PlayerForceTeamThink(CCSPlayer *this)
{
  float m_Value; // xmm1_4
  float v3; // xmm0_4
  edict_t *m_pPev; // ecx
  CCSGameRules *v5; // ebx
  int HumanTeam; // edi
  bool v7; // al
  int v8; // eax
  void (__thiscall *CommitSuicide)(CBasePlayer *, bool, bool); // eax
  edict_t *v10; // ecx
  unsigned int TeamNumber; // eax
  const char *v12; // eax
  ConVarRef cvTime; // [esp+28h] [ebp-Ch] BYREF
  color32_s color; // [esp+30h] [ebp-4h] BYREF

  if ( CBaseEntity::GetTeamNumber(this) != 0 )
    this->ResetForceTeamThink(this);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.5, szContext: nullptr);
  if ( this->m_fForceTeam.m_Value == -1.0 )
  {
    ConVarRef::ConVarRef(this: &cvTime, pName: "mp_force_pick_time");
    m_Value = this->m_fForceTeam.m_Value;
    *(float *)&color = (float)cvTime.m_pConVarState->m_Value.m_nValue + gpGlobals->curtime;
    v3 = *(float *)&color;
    if ( m_Value != *(float *)&color )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
        {
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xC44u);
          v3 = *(float *)&color;
        }
      }
      this->m_fForceTeam.m_Value = v3;
    }
  }
  if ( gpGlobals->curtime <= this->m_fForceTeam.m_Value )
    return;
  this->ResetForceTeamThink(this);
  v5 = (CCSGameRules *)g_pGameRules;
  if ( GetGlobalTeam(iIndex: 0) == nullptr )
  {
    DevWarning(a1: "HandleCommand_JoinTeam( %d ) - invalid team index.\n", 0);
LABEL_13:
    engine->ClientCommand(this: engine, a2: this->m_Network.m_pPev, a3: "disconnect\n");
    return;
  }
  if ( this->m_bTeamChanged && this->m_iOldTeam != 0 )
  {
    ClientPrint(
      player: this,
      msg_dest: 4u,
      msg_name: "#Only_1_Team_Change",
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
    return;
  }
  if ( this->IsBot(this) || (HumanTeam = CCSGameRules::GetHumanTeam(this: v5)) == 0 )
  {
    v7 = this->IsBot(this);
    HumanTeam = CCSGameRules::SelectDefaultTeam(this: v5, ignoreBots: !v7);
    if ( HumanTeam == 0 )
    {
      if ( cv_bot_auto_vacate.m_pParent == nullptr
        || cv_bot_auto_vacate.m_pParent->m_Value.m_nValue == 0
        || this->IsBot(this)
        || (HumanTeam = (random->RandomInt(this: random, a2: 0, a3: 1) != 0) + 2,
            !UTIL_KickBotFromTeam(kickTeam: HumanTeam))
        && (HumanTeam = (HumanTeam != 3) + 2, !UTIL_KickBotFromTeam(kickTeam: HumanTeam))
        || HumanTeam == 0 )
      {
        ClientPrint(
          player: this,
          msg_dest: 4u,
          msg_name: "#All_Teams_Full",
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
LABEL_28:
        this->ShowViewPortPanel(this, a2: "team", a3: true, a4: nullptr);
        goto LABEL_13;
      }
    }
  }
  if ( HumanTeam == CBaseEntity::GetTeamNumber(this) )
  {
    if ( CBaseEntity::GetTeamNumber(this) == 2 || CBaseEntity::GetTeamNumber(this) == 3 )
      engine->ClientCommand(this: engine, a2: this->m_Network.m_pPev, a3: "joinclass\n");
    return;
  }
  if ( CCSGameRules::TeamFull(this: v5, team_id: HumanTeam)
    && (cv_bot_auto_vacate.m_pParent == nullptr
     || cv_bot_auto_vacate.m_pParent->m_Value.m_nValue == 0
     || this->IsBot(this)
     || HumanTeam == 1
     || !UTIL_KickBotFromTeam(kickTeam: HumanTeam)) )
  {
    switch ( HumanTeam )
    {
      case 2:
        ClientPrint(
          player: this,
          msg_dest: 4u,
          msg_name: "#Terrorists_Full",
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
        break;
      case 3:
        ClientPrint(
          player: this,
          msg_dest: 4u,
          msg_name: "#CTs_Full",
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
        break;
      case 1:
        ClientPrint(
          player: this,
          msg_dest: 4u,
          msg_name: "#Cannot_Be_Spectator",
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
        break;
      default:
        break;
    }
    goto LABEL_28;
  }
  if ( this->IsBot(this) )
    goto LABEL_53;
  if ( HumanTeam != 1 )
  {
    v8 = CCSGameRules::GetHumanTeam(this: v5);
    if ( v8 != 0 && v8 != HumanTeam )
    {
      if ( v8 == 2 )
      {
        ClientPrint(
          player: this,
          msg_dest: 4u,
          msg_name: "#Humans_Join_Team_T",
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
      }
      else if ( v8 == 3 )
      {
        ClientPrint(
          player: this,
          msg_dest: 4u,
          msg_name: "#Humans_Join_Team_CT",
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
      }
      goto LABEL_28;
    }
LABEL_53:
    if ( HumanTeam != 1 )
    {
      TeamNumber = CBaseEntity::GetTeamNumber(this);
      if ( !CCSGameRules::TeamStacked(this: v5, newTeam_id: HumanTeam, curTeam_id: TeamNumber)
        || cv_bot_auto_vacate.m_pParent != nullptr
        && cv_bot_auto_vacate.m_pParent->m_Value.m_nValue != 0
        && !this->IsBot(this)
        && UTIL_KickBotFromTeam(kickTeam: HumanTeam) )
      {
        this->ChangeTeam(this, a2: HumanTeam);
        return;
      }
      v12 = "#Too_Many_Terrorists";
      if ( HumanTeam != 2 )
        v12 = "#Too_Many_CTs";
      ClientPrint(
        player: this,
        msg_dest: 4u,
        msg_name: v12,
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      goto LABEL_28;
    }
  }
  if ( (mp_allowspectators.m_pParent == nullptr || mp_allowspectators.m_pParent->m_Value.m_nValue == 0)
    && !this->pl.hltv )
  {
    ClientPrint(
      player: this,
      msg_dest: 4u,
      msg_name: "#Cannot_Be_Spectator",
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
    goto LABEL_13;
  }
  if ( CBaseEntity::GetTeamNumber(this) != 0 && this->m_iPlayerState.m_Value == STATE_ACTIVE )
  {
    CommitSuicide = this->CommitSuicide;
    this->m_fNextSuicideTime = gpGlobals->curtime;
    CommitSuicide(this, a2: false, a3: false);
    this->IncrementFragCount(this, a2: 1);
  }
  this->ChangeTeam(this, a2: 1);
  if ( this->m_iClass.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v10 = this->m_Network.m_pPev;
      if ( v10 != nullptr )
        CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0x1814u);
    }
    this->m_iClass.m_Value = 0;
  }
  if ( mp_fadetoblack.m_pParent != nullptr && mp_fadetoblack.m_pParent->m_Value.m_nValue != 0 )
  {
    *(float *)&color = -1.7014118e38;
    UTIL_ScreenFade(pEntity: this, &color, fadeTime: 0.0, fadeHold: 0.0, flags: 17);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10289340
// Name: private: void CCSPlayer::State_Enter_DEATH_ANIM(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::State_Enter_DEATH_ANIM(CCSPlayer *this)
{
  CGlobalVars *v2; // ebx
  edict_t *m_pPev; // ecx
  bool (__thiscall *StartObserverMode)(CBasePlayer *, int); // edx
  unsigned int v5; // edi
  edict_t *v6; // ecx
  color32_s clr; // [esp+14h] [ebp-4h] BYREF

  if ( CBasePlayer::HasWeapons(this) != 0 )
    this->PackDeadPlayerItems(this);
  v2 = gpGlobals;
  if ( this->m_flDeathTime.m_Value != gpGlobals->curtime )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xC3Cu);
    }
    this->m_flDeathTime.m_Value = v2->curtime;
  }
  StartObserverMode = this->StartObserverMode;
  this->m_bAbortFreezeCam = false;
  StartObserverMode(this, a2: 1);
  v5 = this->m_fEffects.m_Value & 0xFFFFFFDF;
  if ( this->m_fEffects.m_Value != v5 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0xA4u);
    }
    this->m_fEffects.m_Value = v5;
  }
  if ( this->m_Network.m_pPev != nullptr )
    this->m_Network.m_pPev->m_fStateFlags |= 0x80u;
  CBaseEntity::DispatchUpdateTransmitState(this);
  if ( mp_fadetoblack.m_pParent != nullptr && mp_fadetoblack.m_pParent->m_Value.m_nValue != 0 )
  {
    clr = (color32_s)-16777216;
    UTIL_ScreenFade(pEntity: this, color: &clr, fadeTime: 3.0, fadeHold: 3.0, flags: 10);
    CCSPlayer::State_Transition(this, newState: STATE_DEATH_WAIT_FOR_KEY);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10289450
// Name: private: void CCSPlayer::State_PreThink_OBSERVER_MODE(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::State_PreThink_OBSERVER_MODE(CCSPlayer *this)
{
  edict_t *m_pPev; // ecx
  CBaseEntity *v3; // eax
  CCSBot *v4; // eax
  edict_t *v5; // ecx

  if ( this->m_bCanControlObservedBot.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x1B6Cu);
    }
    this->m_bCanControlObservedBot.m_Value = false;
  }
  if ( this->GetObserverMode(this) >= 4 )
  {
    v3 = this->GetObserverTarget(this);
    v4 = ToCSBot(pEntity: v3);
    if ( CCSPlayer::CanControlBot(this, pBot: v4) && !this->m_bCanControlObservedBot.m_Value )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_bCanControlObservedBot.m_Value = true;
      }
      else
      {
        v5 = this->m_Network.m_pPev;
        if ( v5 != nullptr )
          CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x1B6Cu);
        this->m_bCanControlObservedBot.m_Value = true;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10289500
// Name: private: void CCSPlayer::State_Enter_PICKINGCLASS(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::State_Enter_PICKINGCLASS(CCSPlayer *this)
{
  ICommandLine *v2; // eax
  edict_t *m_pPev; // ecx
  IPhysicsObject *m_pPhysicsObject; // ecx

  v2 = _CommandLine((CResponseRulesToEngineInterface *)this);
  if ( v2->FindParm(this: v2, a2: "-makereslists") != 0 )
    goto LABEL_15;
  if ( this->GetObserverMode(this) == 1 )
    this->StartObserverMode(this, a2: 1);
  if ( this->m_iClass.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x1814u);
    }
    this->m_iClass.m_Value = 0;
  }
  m_pPhysicsObject = this->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
    m_pPhysicsObject->Sleep(this: m_pPhysicsObject);
  if ( CBaseEntity::GetTeamNumber(this) == 2 || CBaseEntity::GetTeamNumber(this) == 3 )
LABEL_15:
    engine->ClientCommand(this: engine, a2: this->m_Network.m_pPev, a3: "joinclass\n");
  else
    CCSPlayer::HandleCommand_JoinClass(this);
}

//------------------------------------------------------------------------------
// Address: 0x102895D0
// Name: private: void CCSPlayer::State_PreThink_ACTIVE(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::State_PreThink_ACTIVE(CCSPlayer *this)
{
  float m_fJustLeftImmunityTime; // xmm0_4
  float m_lowHealthGoalTime; // xmm0_4

  if ( CCSGameRules::IsPlayingGunGameProgressive(this: (CCSGameRules *)g_pGameRules)
    || CCSGameRules::IsPlayingGunGameTRBomb(this: (CCSGameRules *)g_pGameRules) )
  {
    if ( gpGlobals->curtime > this->m_fImmuneToGunGameDamageTime && this->m_bGunGameImmunity.m_Value )
    {
      CCSPlayer::ClearGunGameImmunity(this);
      this->m_fJustLeftImmunityTime = gpGlobals->curtime + 2.0;
    }
    m_fJustLeftImmunityTime = this->m_fJustLeftImmunityTime;
    if ( m_fJustLeftImmunityTime != 0.0 && gpGlobals->curtime > m_fJustLeftImmunityTime )
      this->m_fJustLeftImmunityTime = 0.0;
  }
  m_lowHealthGoalTime = this->m_lowHealthGoalTime;
  if ( m_lowHealthGoalTime != 0.0 && gpGlobals->curtime > m_lowHealthGoalTime )
  {
    this->m_lowHealthGoalTime = 0.0;
    CBaseMultiplayerPlayer::AwardAchievement(this, iAchievement: 6039, iCount: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102896A0
// Name: public: virtual void CCSPlayer::Weapon_Equip(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::Weapon_Equip(CCSPlayer *this, CBaseCombatWeapon *pWeapon)
{
  CBaseCombatWeapon *v2; // ebx
  CWeaponCSBase *v4; // esi
  const char *pszValue; // eax
  CCSPlayer_vtbl *v6; // ebx
  int v7; // eax
  CBaseCombatWeapon *v8; // eax

  v2 = pWeapon;
  v4 = (CWeaponCSBase *)__RTDynamicCast(
                          inptr: pWeapon,
                          VfDelta: 0,
                          SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
                          TargetType: &CWeaponCSBase `RTTI Type Descriptor',
                          isReference: 0);
  if ( v4 != nullptr )
  {
    if ( v4->GetSlot(this: v4) == 0 || v4->GetSlot(this: v4) == 1 )
    {
      v6 = this->CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
      v7 = v4->GetSlot(this: v4);
      v8 = v6->Weapon_GetSlot(this, a2: v7);
      if ( v8 != nullptr )
        CCSPlayer::CSWeaponDrop(this, a2: (int)v6, pWeapon: v8, bDropShield: false, bThrowForward: true);
    }
    else if ( CWeaponCSBase::GetCSWpnData(this: v4)->m_WeaponType == WEAPONTYPE_GRENADE )
    {
      pszValue = v4->m_iClassname.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      if ( this->Weapon_OwnsThisType(this, a2: pszValue, a3: 0) != nullptr )
      {
        this->Weapon_EquipAmmoOnly(this, a2: pWeapon);
        UTIL_Remove(oldObj: v4);
        return;
      }
    }
    CCollisionProperty::SetSolidFlags(this: &v4->m_Collision, flags: 4u);
    v4->SetOwnerEntity(this: v4, a2: this);
    v2 = pWeapon;
  }
  CBasePlayer::Weapon_Equip(this, pWeapon: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10289790
// Name: public: void CCSPlayer::RescueZoneTouch(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::RescueZoneTouch(CCSPlayer *this, inputdata_t *inputdata)
{
  edict_t *m_pPev; // ecx
  CHintMessageQueue *m_pHintMessageQueue; // ecx

  if ( !this->m_bInHostageRescueZone.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x177Cu);
    }
    this->m_bInHostageRescueZone.m_Value = true;
  }
  if ( CBaseEntity::GetTeamNumber(this) == 3 && (this->m_iDisplayHistoryBits & 0x20000) == 0 )
  {
    if ( this->IsAlive(this) && this->IsNetClient(this) )
    {
      m_pHintMessageQueue = this->m_pHintMessageQueue;
      if ( m_pHintMessageQueue != nullptr && this->m_bShowHints )
        CHintMessageQueue::AddMessage(
          this: m_pHintMessageQueue,
          message: "#Hint_hostage_rescue_zone",
          duration: 6.0,
          args: nullptr);
    }
    this->m_iDisplayHistoryBits |= 0x20000u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10289840
// Name: public: virtual class CBaseEntity __near * CCSPlayer::GiveNamedItem(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CCSPlayer::GiveNamedItem(CCSPlayer *this, CHandle<CBaseEntity> pszName, float iSubType)
{
  const char *m_Index; // ebx
  IServerNetworkable *EntityByName; // eax
  CBaseEntity *v7; // eax
  CBaseEntity *v8; // eax
  CBaseEntity *v9; // eax
  CBaseCombatWeapon *v10; // edi
  CBaseEntity *v11; // eax
  CBaseEntity *v12; // eax
  float v13; // xmm0_4
  float m_Value; // xmm1_4
  edict_t *m_pPev; // ecx
  ConVarRef mp_molotovusedelay; // [esp+8h] [ebp-8h] BYREF

  m_Index = (const char *)pszName.m_Index;
  if ( pszName.m_Index == 0
    || *(_BYTE *)pszName.m_Index == 0
    || _V_stricmp(s1: (const char *)pszName.m_Index, s2: "weapon_shield") == 0 )
  {
    return nullptr;
  }
  EntityByName = CreateEntityByName(className: m_Index, iForceEdictIndex: -1, bNotify: true);
  if ( EntityByName != nullptr )
    pszName.m_Index = EntityByName->GetEdict(this: EntityByName)->m_fStateFlags;
  else
    pszName.m_Index = -1;
  if ( CHandle<CBaseEntity>::operator==(this: &pszName, val: nullptr) )
  {
    _Msg(a1: "NULL Ent in GiveNamedItem!\n");
    return nullptr;
  }
  v7 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &pszName);
  CBaseEntity::SetLocalOrigin(this: v7, origin: &this->m_vecOrigin.m_Value);
  v8 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &pszName);
  CBaseEntity::AddSpawnFlags(this: v8, nFlags: 0x40000000);
  v9 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &pszName);
  v10 = (CBaseCombatWeapon *)__RTDynamicCast(
                               inptr: v9,
                               VfDelta: 0,
                               SrcType: &CBaseEntity `RTTI Type Descriptor',
                               TargetType: &CBaseCombatWeapon `RTTI Type Descriptor',
                               isReference: 0);
  if ( v10 != nullptr && iSubType != 0.0 )
    v10->SetSubType(this: v10, a2: LODWORD(iSubType));
  v11 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &pszName);
  DispatchSpawn(pEntity: v11, bRunVScripts: true);
  this->m_bIsBeingGivenItem = true;
  if ( CHandle<CBaseEntity>::operator!=(this: &pszName, val: nullptr) )
  {
    v12 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &pszName);
    if ( (v12->m_iEFlags & 1) == 0 )
      v12->Touch(this: v12, a2: this);
  }
  this->m_bIsBeingGivenItem = false;
  CCSPlayer::StockPlayerAmmo(this, pNewWeapon: v10);
  if ( V_strncmp(s1: m_Index, s2: "weapon_molotov", count: 14) == 0 )
  {
    ConVarRef::ConVarRef(this: &mp_molotovusedelay, pName: "mp_molotovusedelay");
    m_Value = this->m_fMolotovUseTime.m_Value;
    iSubType = gpGlobals->curtime + mp_molotovusedelay.m_pConVarState->m_Value.m_fValue;
    v13 = iSubType;
    if ( m_Value != iSubType )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
        {
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x131Cu);
          v13 = iSubType;
        }
      }
      this->m_fMolotovUseTime.m_Value = v13;
    }
  }
  return CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &pszName);
}

//------------------------------------------------------------------------------
// Address: 0x10289A00
// Name: public: void CCSPlayer::DoAnimationEvent(enum PlayerAnimEvent_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::DoAnimationEvent(CCSPlayer *this, PlayerAnimEvent_t event, int nData)
{
  int v4; // edi
  edict_t *m_pPev; // ecx

  if ( event == PLAYERANIMEVENT_THROW_GRENADE )
  {
    v4 = (this->m_iThrowGrenadeCounter.m_Value + 1) % 8;
    if ( this->m_iThrowGrenadeCounter.m_Value != v4 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_iThrowGrenadeCounter.m_Value = v4;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x17D4u);
        this->m_iThrowGrenadeCounter.m_Value = v4;
      }
    }
  }
  else
  {
    this->m_PlayerAnimState->DoAnimationEvent(this: this->m_PlayerAnimState, a2: event, a3: nData);
    TE_PlayerAnimEvent(pPlayer: this, event, nData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10289A90
// Name: private: virtual void CCSPlayer::FlashlightTurnOff(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::FlashlightTurnOff(CCSPlayer *this, bool playSound)
{
  unsigned int v3; // esi
  edict_t *m_pPev; // ecx

  v3 = this->m_fEffects.m_Value & 0xFFFFFFFB;
  if ( this->m_fEffects.m_Value != v3 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xA4u);
    }
    this->m_fEffects.m_Value = v3;
  }
  if ( this->IsAlive(this) )
    CBaseEntity::EmitSound(this, soundname: "Player.FlashlightOff", soundtime: 0.0, duration: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10289B00
// Name: protected: void CCSPlayer::DropWeapons(bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSPlayer::DropWeapons(
        CCSPlayer *this@<ecx>,
        CBaseEntity *a2@<ebx>,
        bool fromDeath,
        bool friendlyFire)
{
  CBaseCombatWeapon *v5; // edi
  const Vector *v6; // eax
  edict_t *m_pPev; // ecx
  int m_nValue; // eax
  CBaseCombatWeapon *ActiveWeapon; // eax
  void *v10; // edi
  CBaseCombatWeapon *v11; // eax
  CBaseCombatWeapon *v12; // eax
  char v13; // bl
  CBaseCombatWeapon *v14; // eax
  void *v15; // eax
  CBaseCSGrenade *v16; // eax
  CBaseCSGrenade *v17; // edi
  ConVar *m_pParent; // eax
  unsigned int i; // ebx
  CBaseCombatWeapon *v20; // eax
  CBaseCombatWeapon *v21; // edi
  const QAngle *v22; // [esp+10h] [ebp-38h]
  CBaseEntity *v23; // [esp+14h] [ebp-34h]
  const char *GrenadePriorities[5]; // [esp+1Ch] [ebp-2Ch] BYREF
  Vector vForward; // [esp+30h] [ebp-18h] BYREF
  Vector vRight; // [esp+3Ch] [ebp-Ch] BYREF
  int savedregs; // [esp+48h] [ebp+0h] BYREF
  float fromDeatha; // [esp+50h] [ebp+8h]

  v5 = this->Weapon_OwnsThisType(this, a2: "weapon_c4", a3: 0);
  if ( v5 != nullptr )
  {
    this->m_bombDroppedTime = gpGlobals->curtime;
    CCSPlayer::CSWeaponDrop(this, (unsigned __int8)a2, pWeapon: v5, bDropShield: false, bThrowForward: true);
    if ( fromDeath && friendlyFire )
      *(&v5[1].m_Network.m_TimerEvent.m_bRegistered + 1) = true;
  }
  if ( this->m_bHasDefuser.m_Value
    && mp_death_drop_defuser.m_pParent != nullptr
    && mp_death_drop_defuser.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    AngleVectors(angles: &this->m_angAbsRotation, forward: &vForward, right: &vRight, up: nullptr);
    v6 = (const Vector *)((int (__thiscall *)(CCSPlayer *, CNetworkVectorXYZBase<QAngle,CBaseEntity::NetworkVar_m_angRotation> *, _DWORD))this->WorldSpaceCenter)(
                           a1: this,
                           a2: &this->m_angRotation,
                           a3: 0);
    a2 = CBaseEntity::Create(szName: "item_defuser", vecOrigin: v6, vecAngles: v22, pOwner: v23);
    fromDeatha = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                   a1: random,
                   a2: -1035468800,
                   a3: 1112014848);
    *(float *)&GrenadePriorities[2] = (float)(vForward.x * 200.0) + (float)(vRight.x * fromDeatha);
    *(float *)&GrenadePriorities[3] = (float)(vForward.y * 200.0) + (float)(vRight.y * fromDeatha);
    *(float *)&GrenadePriorities[4] = (float)(vForward.z * 200.0) + (float)(vRight.z * fromDeatha);
    CBaseEntity::ApplyAbsVelocityImpulse(this: a2, vecImpulse: (const Vector *)&GrenadePriorities[2]);
    if ( this->m_bHasDefuser.m_Value )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x135Cu);
      }
      this->m_bHasDefuser.m_Value = false;
    }
  }
  if ( mp_death_drop_gun.m_pParent != nullptr )
  {
    m_nValue = mp_death_drop_gun.m_pParent->m_Value.m_nValue;
    if ( m_nValue != 0 )
    {
      if ( m_nValue != 2
        || (ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this),
            v10 = __RTDynamicCast(
                    inptr: ActiveWeapon,
                    VfDelta: 0,
                    SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
                    TargetType: &CWeaponCSBase `RTTI Type Descriptor',
                    isReference: 0),
            (*(int (__thiscall **)(void *))(*(_DWORD *)v10 + 1312))(a1: v10) != 1)
        && (*(int (__thiscall **)(void *))(*(_DWORD *)v10 + 1312))(a1: v10) != 0 )
      {
        v11 = this->Weapon_GetSlot(this, a2: 0);
        if ( v11 == nullptr
          || CCSPlayer::CSWeaponDrop(this, (unsigned __int8)a2, pWeapon: v11, bDropShield: false, bThrowForward: false) == 0 )
        {
          v12 = this->Weapon_GetSlot(this, a2: 1);
          if ( v12 != nullptr )
          {
            CCSPlayer::CSWeaponDrop(this, (unsigned __int8)a2, pWeapon: v12, bDropShield: false, bThrowForward: false);
            this->m_bUsingDefaultPistol = false;
          }
        }
      }
    }
  }
  v13 = 0;
  v14 = CBaseCombatCharacter::GetActiveWeapon(this);
  v15 = __RTDynamicCast(
          inptr: v14,
          VfDelta: 0,
          SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
          TargetType: &CWeaponCSBase `RTTI Type Descriptor',
          isReference: 0);
  v16 = (CBaseCSGrenade *)__RTDynamicCast(
                            inptr: v15,
                            VfDelta: 0,
                            SrcType: &CWeaponCSBase `RTTI Type Descriptor',
                            TargetType: &CBaseCSGrenade `RTTI Type Descriptor',
                            isReference: 0);
  v17 = v16;
  if ( v16 == nullptr )
    goto LABEL_41;
  if ( (v16->m_bPinPulled.m_Value || v16->m_fThrowTime.m_Value > 0.0)
    && (v16->m_iClassname.pszValue == "weapon_hegrenade"
     || CBaseEntity::ClassMatchesComplex(this: v16, pszClassOrWildcard: "weapon_hegrenade") != 0
     || v17->m_iClassname.pszValue == "weapon_flashbang"
     || CBaseEntity::ClassMatchesComplex(this: v17, pszClassOrWildcard: "weapon_flashbang") != 0
     || v17->m_iClassname.pszValue == "weapon_smokegrenade"
     || CBaseEntity::ClassMatchesComplex(this: v17, pszClassOrWildcard: "weapon_smokegrenade") != 0
     || v17->m_iClassname.pszValue == "weapon_decoy"
     || CBaseEntity::ClassMatchesComplex(this: v17, pszClassOrWildcard: "weapon_decoy") != 0) )
  {
    v17->DropGrenade(this: v17);
    CBaseCSGrenade::DecrementAmmo(this: v17, pOwner: this);
    v13 = 1;
  }
  m_pParent = mp_death_drop_grenade.m_pParent;
  if ( mp_death_drop_grenade.m_pParent != nullptr )
  {
    if ( mp_death_drop_grenade.m_pParent->m_Value.m_nValue != 2 || v13 != 0 )
    {
LABEL_42:
      if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 && v13 == 0 )
      {
        GrenadePriorities[0] = "weapon_hegrenade";
        GrenadePriorities[1] = "weapon_flashbang";
        GrenadePriorities[2] = "weapon_smokegrenade";
        GrenadePriorities[3] = "weapon_molotov";
        GrenadePriorities[4] = "weapon_decoy";
        for ( i = 0; i < 5; ++i )
        {
          v20 = this->Weapon_OwnsThisType(this, a2: GrenadePriorities[i], a3: 0);
          v21 = (CBaseCombatWeapon *)__RTDynamicCast(
                                       inptr: v20,
                                       VfDelta: 0,
                                       SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
                                       TargetType: &CBaseCSGrenade `RTTI Type Descriptor',
                                       isReference: 0);
          if ( v21 != nullptr
            && v21->HasAmmo(this: v21)
            && CCSPlayer::CSWeaponDrop(
                 this,
                 a2: (unsigned __int8)i,
                 pWeapon: v21,
                 bDropShield: false,
                 bThrowForward: false) != 0 )
          {
            break;
          }
        }
      }
      return;
    }
    v13 = CCSPlayer::CSWeaponDrop(this, a2: 0, pWeapon: v17, bDropShield: false, bThrowForward: false);
LABEL_41:
    m_pParent = mp_death_drop_grenade.m_pParent;
    goto LABEL_42;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10289ED0
// Name: public: void CCSPlayer::SwitchTeam(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::SwitchTeam(CCSPlayer *this, int iTeamNum)
{
  int v2; // edi
  double RoundElapsedTime; // st7
  void (__thiscall *ChangeTeam)(CBasePlayer *, int, bool, bool); // edx
  int NextClassForTeam; // edi
  edict_t *m_pPev; // ecx
  int NumAliveTerrorist; // [esp+8h] [ebp-Ch] BYREF
  int NumAliveCT; // [esp+Ch] [ebp-8h] BYREF
  int NumDeadTerrorist; // [esp+10h] [ebp-4h] BYREF

  v2 = iTeamNum;
  if ( GetGlobalTeam(iIndex: iTeamNum) != nullptr && (v2 == 3 || v2 == 2) )
  {
    if ( v2 != CBaseEntity::GetTeamNumber(this) )
    {
      RoundElapsedTime = CCSGameRules::GetRoundElapsedTime(this: (CCSGameRules *)g_pGameRules);
      CCSGameStats::IncrementStat(
        this: &CCS_GameStats,
        pPlayer: this,
        statId: CSSTAT_PLAYTIME,
        iDelta: (int)RoundElapsedTime,
        bPlayerOnly: true);
      ChangeTeam = this->ChangeTeam;
      this->m_bTeamChanged = true;
      ChangeTeam(this, a2: v2, a3: false, a4: false);
      if ( this->m_bHasDefuser.m_Value )
        CCSPlayer::RemoveDefuser(this);
      NextClassForTeam = PlayerModelInfo::GetNextClassForTeam(this: &PlayerModelInfo::s_PlayerModelInfo, team: v2);
      if ( this->m_iClass.m_Value != NextClassForTeam )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x1814u);
        }
        this->m_iClass.m_Value = NextClassForTeam;
      }
      CCSGameRules::InitializePlayerCounts(
        this: (CCSGameRules *)g_pGameRules,
        &NumAliveTerrorist,
        &NumAliveCT,
        &NumDeadTerrorist,
        NumDeadCT: &iTeamNum);
    }
  }
  else
  {
    _Warning(a1: "CCSPlayer::SwitchTeam( %d ) - invalid team index.\n", v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10289FD0
// Name: public: void CCSPlayer::PlayerUsedKnife(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::PlayerUsedKnife(CCSPlayer *this)
{
  edict_t *m_pPev; // ecx

  if ( CCSGameRules::IsPlayingGunGameProgressive(this: (CCSGameRules *)g_pGameRules)
    || CCSGameRules::IsPlayingGunGameTRBomb(this: (CCSGameRules *)g_pGameRules) )
  {
    if ( this->m_bGunGameImmunity.m_Value )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x1311u);
      }
      this->m_bGunGameImmunity.m_Value = false;
    }
    this->m_fImmuneToGunGameDamageTime = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028A040
// Name: public: void CCSPlayer::PlayerUsedGrenade(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::PlayerUsedGrenade(CCSPlayer *this, int nWeaponID)
{
  edict_t *m_pPev; // ecx

  if ( CCSGameRules::IsPlayingGunGameProgressive(this: (CCSGameRules *)g_pGameRules)
    || CCSGameRules::IsPlayingGunGameTRBomb(this: (CCSGameRules *)g_pGameRules) )
  {
    if ( this->m_bGunGameImmunity.m_Value )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x1311u);
      }
      this->m_bGunGameImmunity.m_Value = false;
    }
    this->m_fImmuneToGunGameDamageTime = 0.0;
  }
  if ( CCSGameRules::IsPlayingGunGameTRBomb(this: (CCSGameRules *)g_pGameRules) )
  {
    if ( nWeaponID == 32 )
    {
      if ( this->m_bGunGameTRModeHasFlashbang )
        this->m_bGunGameTRModeHasFlashbang = false;
    }
    else if ( nWeaponID == 33 )
    {
      if ( this->m_bGunGameTRModeHasHEGrenade )
        this->m_bGunGameTRModeHasHEGrenade = false;
    }
    else if ( nWeaponID == 35 && this->m_bGunGameTRModeHasMolotov )
    {
      this->m_bGunGameTRModeHasMolotov = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028A110
// Name: public: void CCSPlayer::OnPreResetRound(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::OnPreResetRound(CCSPlayer *this)
{
  int TeamNumber; // eax
  int v3; // ebx
  double RoundElapsedTime; // st7
  void (__thiscall *ChangeTeam)(CBasePlayer *, int, bool, bool); // edx
  int NextClassForTeam; // ebx
  edict_t *m_pPev; // ecx
  IGameEvent *v8; // edi
  int v9; // eax
  IGameEvent *v10; // edi
  int v11; // eax
  IGameEvent *v12; // eax
  IGameEvent *v13; // edi
  IGameEvent_vtbl *v14; // ebx
  int UserID; // eax
  int NumAliveTerrorist; // [esp+4h] [ebp-14h] BYREF
  int NumAliveCT; // [esp+8h] [ebp-10h] BYREF
  int NumDeadTerrorist; // [esp+Ch] [ebp-Ch] BYREF
  int NumDeadCT; // [esp+10h] [ebp-8h] BYREF
  int teamNum; // [esp+14h] [ebp-4h]

  if ( this->IsAlive(this) && this->m_bSurvivedHeadshotDueToHelmet )
    CBaseMultiplayerPlayer::AwardAchievement(this, iAchievement: 3004, iCount: 1);
  if ( this->IsAlive(this) && this->m_grenadeDamageTakenThisRound > 80 )
    CBaseMultiplayerPlayer::AwardAchievement(this, iAchievement: 3010, iCount: 1);
  if ( this->IsAlive(this) && CCSPlayer::GetNumEnemyDamagers(this) >= 5 )
    CBaseMultiplayerPlayer::AwardAchievement(this, iAchievement: 5025, iCount: 1);
  if ( CCSGameRules::IsPlayingGunGameTRBomb(this: (CCSGameRules *)g_pGameRules)
    && this->m_bShouldSwitchGunGameTRBombTeam )
  {
    TeamNumber = CBaseEntity::GetTeamNumber(this);
    v3 = TeamNumber;
    teamNum = TeamNumber;
    if ( TeamNumber == 2 )
    {
      this->m_bShouldSwitchGunGameTRBombTeam = false;
      if ( GetGlobalTeam(iIndex: 3) != nullptr )
      {
        if ( CBaseEntity::GetTeamNumber(this) != 3 )
        {
          RoundElapsedTime = CCSGameRules::GetRoundElapsedTime(this: (CCSGameRules *)g_pGameRules);
          CCSGameStats::IncrementStat(
            this: &CCS_GameStats,
            pPlayer: this,
            statId: CSSTAT_PLAYTIME,
            iDelta: (int)RoundElapsedTime,
            bPlayerOnly: true);
          ChangeTeam = this->ChangeTeam;
          this->m_bTeamChanged = true;
          ChangeTeam(this, a2: 3, a3: false, a4: false);
          if ( this->m_bHasDefuser.m_Value )
            CCSPlayer::RemoveDefuser(this);
          NextClassForTeam = PlayerModelInfo::GetNextClassForTeam(this: &PlayerModelInfo::s_PlayerModelInfo, team: 3);
          if ( this->m_iClass.m_Value != NextClassForTeam )
          {
            if ( this->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&this->m_Network + 76) |= 1u;
            }
            else
            {
              m_pPev = this->m_Network.m_pPev;
              if ( m_pPev != nullptr )
                CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x1814u);
            }
            this->m_iClass.m_Value = NextClassForTeam;
          }
          CCSGameRules::InitializePlayerCounts(
            this: (CCSGameRules *)g_pGameRules,
            &NumAliveTerrorist,
            &NumAliveCT,
            &NumDeadTerrorist,
            &NumDeadCT);
          v3 = teamNum;
        }
      }
      else
      {
        _Warning(a1: "CCSPlayer::SwitchTeam( %d ) - invalid team index.\n", 3);
      }
    }
    else
    {
      if ( TeamNumber != 3 )
        return;
      this->m_bShouldSwitchGunGameTRBombTeam = false;
      CCSPlayer::SwitchTeam(this, iTeamNum: 2);
    }
    v8 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "gg_halftime", a3: 0, a4: 0);
    if ( v8 != nullptr )
    {
      v9 = engine->GetPlayerUserId(this: engine, a2: this->m_Network.m_pPev);
      v8->SetInt(this: v8, a2: "userid", a3: v9);
      gameeventmanager->FireEvent(this: gameeventmanager, a2: v8, a3: false);
    }
    if ( v3 == 2 )
    {
      v10 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "switch_team_to_ct", a3: 0, a4: 0);
      if ( v10 != nullptr )
      {
        v11 = engine->GetPlayerUserId(this: engine, a2: this->m_Network.m_pPev);
        v10->SetInt(this: v10, a2: "userid", a3: v11);
        gameeventmanager->FireEvent(this: gameeventmanager, a2: v10, a3: false);
      }
    }
    else if ( v3 == 3 )
    {
      v12 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "switch_team_to_t", a3: 0, a4: 0);
      v13 = v12;
      if ( v12 != nullptr )
      {
        v14 = v12->__vftable;
        UserID = CBasePlayer::GetUserID(this);
        v14->SetInt(this: v13, a2: "userid", a3: UserID);
        gameeventmanager->FireEvent(this: gameeventmanager, a2: v13, a3: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028A3C0
// Name: public: void CCSPlayer::ResetTRBombModeData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::ResetTRBombModeData(CCSPlayer *this)
{
  edict_t *m_pPev; // ecx
  edict_t *v3; // ecx

  if ( this->m_iGunGameProgressiveWeaponIndex.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x1314u);
    }
    this->m_iGunGameProgressiveWeaponIndex.m_Value = 0;
  }
  this->m_iNumGunGameKillsWithCurrentWeapon = 0;
  if ( this->m_iNumGunGameTRKillPoints.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v3 = this->m_Network.m_pPev;
      if ( v3 != nullptr )
        CBaseEdict::StateChanged(this: &v3->CBaseEdict, offset: 0x1318u);
    }
    this->m_iNumGunGameTRKillPoints.m_Value = 0;
  }
  this->m_iNumGunGameTRBombTotalPoints = 0;
  *(_WORD *)&this->m_bShouldProgressGunGameTRBombModeWeapon = 0;
  this->m_bMadeFinalGunGameProgressiveKill = false;
}

//------------------------------------------------------------------------------
// Address: 0x1028A450
// Name: public: void CCSPlayer::ReleaseControlOfBot(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::ReleaseControlOfBot(CCSPlayer *this)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // eax
  CCSBot *v4; // edx
  edict_t *m_pPev; // ecx
  edict_t *v6; // ecx
  edict_t *v7; // ecx
  edict_t *v8; // ecx
  int iAccountDelta; // [esp+4h] [ebp-8h]
  CCSBot *pBot; // [esp+8h] [ebp-4h]

  if ( this->m_bIsControllingBot.m_Value )
  {
    m_Index = this->m_hControlledBot.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    v4 = ToCSBot(pEntity: m_pEntity);
    iAccountDelta = this->m_iAccount.m_Value - this->m_PreControlData.m_iAccount;
    pBot = v4;
    if ( this->m_iClass.m_Value != this->m_PreControlData.m_iClass )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
        {
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x1814u);
          v4 = pBot;
        }
      }
      this->m_iClass.m_Value = this->m_PreControlData.m_iClass;
    }
    if ( this->m_iAccount.m_Value != this->m_PreControlData.m_iAccount )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v6 = this->m_Network.m_pPev;
        if ( v6 != nullptr )
        {
          CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x1900u);
          v4 = pBot;
        }
      }
      this->m_iAccount.m_Value = this->m_PreControlData.m_iAccount;
    }
    if ( v4 != nullptr )
    {
      v4->m_hControlledByPlayer.m_Index = -1;
      CCSPlayer::TransferInventory(this, pTargetPlayer: v4);
      CCSPlayer::AddAccount(this: pBot, amount: iAccountDelta, bTrackChange: true, bItemBought: false);
    }
    this->m_hControlledBot.m_Index = -1;
    if ( this->m_bIsControllingBot.m_Value )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v7 = this->m_Network.m_pPev;
        if ( v7 != nullptr )
          CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x1B6Bu);
      }
      this->m_bIsControllingBot.m_Value = false;
    }
    if ( this->m_iControlledBotEntIndex.m_Value != -1 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v8 = this->m_Network.m_pPev;
        if ( v8 != nullptr )
          CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0x1B70u);
      }
      this->m_iControlledBotEntIndex.m_Value = -1;
    }
    CBaseEntity::DispatchUpdateTransmitState(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028A5E0
// Name: bot_stop_control
// Source: json
//------------------------------------------------------------------------------
void __cdecl bot_stop_control()
{
  CBasePlayer *CommandClient; // esi
  CCSPlayer *v1; // eax
  CCSPlayer *v2; // esi
  unsigned int m_Index; // ecx
  int v4; // eax
  CEntInfo *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  bool v8; // zf
  CBaseEntity **v9; // eax
  CBaseEntity *v10; // eax
  CCSBot *v11; // edi

  CommandClient = UTIL_GetCommandClient();
  if ( CommandClient != nullptr && CommandClient->IsPlayer(this: CommandClient) )
  {
    v1 = (CCSPlayer *)__RTDynamicCast(
                        inptr: CommandClient,
                        VfDelta: 0,
                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                        TargetType: &CCSPlayer `RTTI Type Descriptor',
                        isReference: 0);
    v2 = v1;
    if ( v1 != nullptr )
    {
      m_Index = v1->m_hControlledBot.m_Index;
      if ( m_Index != -1 )
      {
        v4 = (unsigned __int16)m_Index;
        v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
        v6 = HIWORD(m_Index);
        if ( v5->m_SerialNumber == v6 && v5->m_pEntity != nullptr )
        {
          v7 = v4;
          v8 = g_pEntityList->m_EntPtrArray[v7].m_SerialNumber == v6;
          v9 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v7];
          if ( v8 )
            v10 = *v9;
          else
            v10 = nullptr;
          v11 = ToCSBot(pEntity: v10);
          CCSPlayer::ReleaseControlOfBot(this: v2);
          if ( v11 != nullptr && v11->IsAlive(this: v11) )
          {
            v2->SetObserverTarget(this: v2, a2: v11);
            v2->StartObserverMode(this: v2, a2: 5);
          }
          else
          {
            v2->StartObserverMode(this: v2, a2: 6);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028A6C0
// Name: public: void CCSPlayer::Unblind(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::Unblind(CCSPlayer *this)
{
  CNetworkVarBase<float,CCSPlayer::NetworkVar_m_flFlashMaxAlpha> *p_m_flFlashMaxAlpha; // esi
  edict_t *m_pPev; // ecx

  p_m_flFlashMaxAlpha = &this->m_flFlashMaxAlpha;
  if ( this->m_flFlashMaxAlpha.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_flFlashMaxAlpha->m_Value = 0.0;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x17C8u);
      p_m_flFlashMaxAlpha->m_Value = 0.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028A960
// Name: public: void CCSPlayer::GiveDefaultItems(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::GiveDefaultItems(CCSPlayer *this)
{
  CBaseCombatWeapon *v2; // edi
  CBaseCombatWeapon *v3; // eax
  const char *v4; // eax
  int m_Value; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  IGameEvent *v9; // edi
  int v10; // eax
  CSingleUserRecipientFilter filter; // [esp+Ch] [ebp-3Ch] BYREF
  ConVarRef mp_ggtr_bomb_pts_for_he; // [esp+2Ch] [ebp-1Ch] BYREF
  ConVarRef mp_ggtr_bomb_pts_for_flash; // [esp+34h] [ebp-14h] BYREF
  ConVarRef mp_ggtr_bomb_pts_for_molotov; // [esp+3Ch] [ebp-Ch] BYREF
  bool bGiveHEGrenade; // [esp+45h] [ebp-3h]
  bool bGiveFlashbang; // [esp+46h] [ebp-2h]
  bool bGiveMolotov; // [esp+47h] [ebp-1h]

  if ( mp_defuser_allocation.m_pParent != nullptr
    && mp_defuser_allocation.m_pParent->m_Value.m_nValue == 2
    && CBaseEntity::GetTeamNumber(this) == 3 )
  {
    CCSPlayer::GiveDefuser(this, bPickedUp: false);
  }
  this->GiveNamedItem(this, a2: "item_assaultsuit", a3: 0);
  if ( (unsigned __int8)CCSGameRules::IsPlayingGunGameSelect(this: (CCSGameRules *)g_pGameRules) != 0 )
  {
    CBaseCombatCharacter::GiveAmmo(this, iCount: 250, szName: "BULLET_PLAYER_50AE", bSuppressSound: false);
    CBaseCombatCharacter::GiveAmmo(this, iCount: 250, szName: "BULLET_PLAYER_762MM", bSuppressSound: false);
    CBaseCombatCharacter::GiveAmmo(this, iCount: 250, szName: "BULLET_PLAYER_338MAG", bSuppressSound: false);
    CBaseCombatCharacter::GiveAmmo(this, iCount: 250, szName: "BULLET_PLAYER_556MM", bSuppressSound: false);
    CBaseCombatCharacter::GiveAmmo(this, iCount: 250, szName: "BULLET_PLAYER_556MM_BOX", bSuppressSound: false);
    CBaseCombatCharacter::GiveAmmo(this, iCount: 250, szName: "BULLET_PLAYER_9MM", bSuppressSound: false);
    CBaseCombatCharacter::GiveAmmo(this, iCount: 250, szName: "BULLET_PLAYER_BUCKSHOT", bSuppressSound: false);
    CBaseCombatCharacter::GiveAmmo(this, iCount: 250, szName: "BULLET_PLAYER_45ACP", bSuppressSound: false);
    CBaseCombatCharacter::GiveAmmo(this, iCount: 250, szName: "BULLET_PLAYER_357SIG", bSuppressSound: false);
    CBaseCombatCharacter::GiveAmmo(this, iCount: 250, szName: "BULLET_PLAYER_57MM", bSuppressSound: false);
  }
  if ( CCSGameRules::IsPlayingGunGameProgressive(this: (CCSGameRules *)g_pGameRules)
    || CCSGameRules::IsPlayingGunGameTRBomb(this: (CCSGameRules *)g_pGameRules) )
  {
    CCSPlayer::GiveCurrentProgressiveGunGameWeapon(this);
    v4 = WeaponIdAsString(weaponID: WEAPON_KNIFE);
    if ( v4 != nullptr )
      this->GiveNamedItem(this, a2: v4, a3: 0);
    if ( CCSGameRules::IsPlayingGunGameTRBomb(this: (CCSGameRules *)g_pGameRules) )
    {
      ConVarRef::ConVarRef(this: &mp_ggtr_bomb_pts_for_he, pName: "mp_ggtr_bomb_pts_for_he");
      ConVarRef::ConVarRef(this: &mp_ggtr_bomb_pts_for_flash, pName: "mp_ggtr_bomb_pts_for_flash");
      ConVarRef::ConVarRef(this: &mp_ggtr_bomb_pts_for_molotov, pName: "mp_ggtr_bomb_pts_for_molotov");
      m_Value = this->m_iNumGunGameTRKillPoints.m_Value;
      bGiveMolotov = false;
      bGiveFlashbang = false;
      bGiveHEGrenade = false;
      if ( m_Value < mp_ggtr_bomb_pts_for_molotov.m_pConVarState->m_Value.m_nValue || this->m_bGunGameTRModeHasMolotov )
      {
        if ( m_Value < mp_ggtr_bomb_pts_for_flash.m_pConVarState->m_Value.m_nValue || this->m_bGunGameTRModeHasFlashbang )
        {
          if ( m_Value >= mp_ggtr_bomb_pts_for_he.m_pConVarState->m_Value.m_nValue
            && !this->m_bGunGameTRModeHasHEGrenade )
          {
            bGiveHEGrenade = true;
            this->m_bGunGameTRModeHasHEGrenade = true;
          }
        }
        else
        {
          bGiveFlashbang = true;
          this->m_bGunGameTRModeHasFlashbang = true;
        }
      }
      else
      {
        bGiveMolotov = true;
        this->m_bGunGameTRModeHasMolotov = true;
      }
      if ( this->m_bGunGameTRModeHasMolotov && CCSPlayer::HasWeaponOfType(this, nWeaponID: 35) == 0 )
      {
        v6 = WeaponIdAsString(weaponID: WEAPON_MOLOTOV);
        if ( v6 != nullptr )
          this->GiveNamedItem(this, a2: v6, a3: 0);
        this->m_bGunGameTRModeHasMolotov = true;
      }
      if ( this->m_bGunGameTRModeHasFlashbang && CCSPlayer::HasWeaponOfType(this, nWeaponID: 32) == 0 )
      {
        v7 = WeaponIdAsString(weaponID: WEAPON_FLASHBANG);
        if ( v7 != nullptr )
          this->GiveNamedItem(this, a2: v7, a3: 0);
        this->m_bGunGameTRModeHasFlashbang = true;
      }
      if ( this->m_bGunGameTRModeHasHEGrenade && CCSPlayer::HasWeaponOfType(this, nWeaponID: 33) == 0 )
      {
        v8 = WeaponIdAsString(weaponID: WEAPON_HEGRENADE);
        if ( v8 != nullptr )
          this->GiveNamedItem(this, a2: v8, a3: 0);
        this->m_bGunGameTRModeHasHEGrenade = true;
      }
      if ( bGiveMolotov || bGiveFlashbang || bGiveHEGrenade )
      {
        v9 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "gg_bonus_grenade_achieved", a3: 0, a4: 0);
        if ( v9 != nullptr )
        {
          v10 = engine->GetPlayerUserId(this: engine, a2: this->m_Network.m_pPev);
          v9->SetInt(this: v9, a2: "userid", a3: v10);
          gameeventmanager->FireEvent(this: gameeventmanager, a2: v9, a3: false);
        }
      }
    }
  }
  else
  {
    v2 = this->Weapon_GetSlot(this, a2: 2);
    v3 = this->Weapon_GetSlot(this, a2: 1);
    if ( v2 != nullptr )
    {
      if ( v3 != nullptr )
      {
        CRecipientFilter::CRecipientFilter(this: &filter);
        filter.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
        CRecipientFilter::AddRecipient(this: &filter, player: this);
        CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&filter);
        UserMessageBegin(&filter, messagename: "DisplayInventory");
        MessageWriteBool(bValue: true);
        MessageEnd();
        CRecipientFilter::~CRecipientFilter(this: &filter);
        return;
      }
      CRecipientFilter::CRecipientFilter(this: &filter);
      filter.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
      CRecipientFilter::AddRecipient(this: &filter, player: this);
      CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&filter);
      UserMessageBegin(&filter, messagename: "DisplayInventory");
      MessageWriteBool(bValue: false);
      MessageEnd();
      CRecipientFilter::~CRecipientFilter(this: &filter);
    }
    this->m_bUsingDefaultPistol = true;
    if ( CBaseEntity::GetTeamNumber(this) == 3 )
    {
      this->GiveNamedItem(this, a2: "weapon_knife", a3: 0);
      this->GiveNamedItem(this, a2: "weapon_hkp2000", a3: 0);
      CBaseCombatCharacter::GiveAmmo(this, iCount: 24, szName: "BULLET_PLAYER_45ACP", bSuppressSound: false);
      this->m_bPickedUpWeapon = false;
    }
    else
    {
      if ( CBaseEntity::GetTeamNumber(this) == 2 )
      {
        this->GiveNamedItem(this, a2: "weapon_knife", a3: 0);
        this->GiveNamedItem(this, a2: "weapon_glock", a3: 0);
        CBaseCombatCharacter::GiveAmmo(this, iCount: 40, szName: "BULLET_PLAYER_9MM", bSuppressSound: false);
      }
      this->m_bPickedUpWeapon = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028ADD0
// Name: protected: void CCSPlayer::GiveNextProgressiveGunGameWeapon(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::GiveNextProgressiveGunGameWeapon(CCSPlayer *this)
{
  CCSGameRules *v1; // esi
  int TeamNumber; // eax
  int v4; // esi
  edict_t *m_pPev; // ecx
  CBaseCombatWeapon *v6; // eax
  CBaseCombatWeapon *v7; // eax
  CBaseCombatWeapon *v8; // eax
  const char *v9; // eax
  IGameEvent *v10; // esi
  int v11; // eax
  const char *szName; // [esp+Ch] [ebp-4h]
  const char *szNamea; // [esp+Ch] [ebp-4h]

  v1 = (CCSGameRules *)g_pGameRules;
  TeamNumber = CBaseEntity::GetTeamNumber(this);
  szName = (const char *)CCSGameRules::GetNextGunGameWeapon(
                           this: v1,
                           nCurrentWeaponIndex: this->m_iGunGameProgressiveWeaponIndex.m_Value,
                           nTeamID: TeamNumber);
  if ( szName != (const char *)-1 )
  {
    v4 = this->m_iGunGameProgressiveWeaponIndex.m_Value + 1;
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x1314u);
    }
    this->m_iGunGameProgressiveWeaponIndex.m_Value = v4;
    v6 = this->Weapon_GetSlot(this, a2: 1);
    if ( v6 != nullptr )
      CBaseCombatWeapon::DestroyItem(this: v6);
    v7 = this->Weapon_GetSlot(this, a2: 0);
    if ( v7 != nullptr )
      CBaseCombatWeapon::DestroyItem(this: v7);
    if ( szName == (const char *)31 )
    {
      v8 = this->Weapon_GetSlot(this, a2: 2);
      if ( v8 != nullptr )
        CBaseCombatWeapon::DestroyItem(this: v8);
    }
    v9 = WeaponIdAsString(weaponID: (CSWeaponID)szName);
    if ( v9 != nullptr )
      this->GiveNamedItem(this, a2: v9, a3: 0);
    if ( CCSGameRules::IsPlayingGunGameTRBomb(this: (CCSGameRules *)g_pGameRules) )
    {
      v10 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "ggtr_player_levelup", a3: 0, a4: 0);
      if ( v10 == nullptr )
      {
LABEL_21:
        CCSPlayer::UpdateLeader(this);
        return;
      }
    }
    else
    {
      if ( !CCSGameRules::IsPlayingGunGameProgressive(this: (CCSGameRules *)g_pGameRules) )
        goto LABEL_21;
      v10 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "ggprogressive_player_levelup", a3: 0, a4: 0);
      if ( v10 == nullptr )
        goto LABEL_21;
    }
    szNamea = WeaponIdAsString(weaponID: (CSWeaponID)szName);
    v11 = engine->GetPlayerUserId(this: engine, a2: this->m_Network.m_pPev);
    v10->SetInt(this: v10, a2: "userid", a3: v11);
    v10->SetInt(this: v10, a2: "weaponrank", a3: this->m_iGunGameProgressiveWeaponIndex.m_Value);
    v10->SetString(this: v10, a2: "weaponname", a3: szNamea);
    gameeventmanager->FireEvent(this: gameeventmanager, a2: v10, a3: false);
    goto LABEL_21;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028AF80
// Name: protected: void CCSPlayer::GivePreviousProgressiveGunGameWeapon(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::GivePreviousProgressiveGunGameWeapon(CCSPlayer *this)
{
  CCSGameRules *v1; // edi
  CNetworkVarBase<int,CCSPlayer::NetworkVar_m_iGunGameProgressiveWeaponIndex> *p_m_iGunGameProgressiveWeaponIndex; // esi
  int TeamNumber; // eax
  int v4; // edi
  CNetworkVarBase<int,CCSPlayer::NetworkVar_m_iGunGameProgressiveWeaponIndex> *v5; // eax
  CBaseEdict *m_Value; // ecx

  v1 = (CCSGameRules *)g_pGameRules;
  p_m_iGunGameProgressiveWeaponIndex = &this->m_iGunGameProgressiveWeaponIndex;
  TeamNumber = CBaseEntity::GetTeamNumber(this);
  if ( CCSGameRules::GetPreviousGunGameWeapon(
         this: v1,
         nCurrentWeaponIndex: p_m_iGunGameProgressiveWeaponIndex->m_Value,
         nTeamID: TeamNumber) != -1 )
  {
    v4 = p_m_iGunGameProgressiveWeaponIndex->m_Value - 1;
    if ( p_m_iGunGameProgressiveWeaponIndex->m_Value != v4 )
    {
      v5 = p_m_iGunGameProgressiveWeaponIndex - 1221;
      if ( LOBYTE(p_m_iGunGameProgressiveWeaponIndex[-1200].m_Value) != 0 )
      {
        LOBYTE(v5[22].m_Value) |= 1u;
        p_m_iGunGameProgressiveWeaponIndex->m_Value = v4;
      }
      else
      {
        m_Value = (CBaseEdict *)v5[6].m_Value;
        if ( m_Value != nullptr )
          CBaseEdict::StateChanged(this: m_Value, offset: 0x1314u);
        p_m_iGunGameProgressiveWeaponIndex->m_Value = v4;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028AFE0
// Name: public: virtual void CCSPlayer::DeathSound(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::DeathSound(CCSPlayer *this, const CTakeDamageInfo *info)
{
  if ( CCSGameRules::IsPlayingGunGameProgressive(this: (CCSGameRules *)g_pGameRules)
    && ((this->m_LastDamageType & 0x20) != 0 || this->m_wasNotKilledNaturally) )
  {
    this->m_iNumGunGameKillsWithCurrentWeapon = 0;
    CCSPlayer::GivePreviousProgressiveGunGameWeapon(this);
  }
  if ( this->m_LastHitGroup == 1 )
    CBaseEntity::EmitSound(this, soundname: "Player.DeathHeadShot", soundtime: 0.0, duration: nullptr);
  else
    CBaseEntity::EmitSound(this, soundname: "Player.Death", soundtime: 0.0, duration: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1028B050
// Name: public: virtual void CCSPlayer::CheatImpulseCommands(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::CheatImpulseCommands(CCSPlayer *this, int iImpulse)
{
  if ( iImpulse == 101 )
  {
    if ( sv_cheats->m_pParent != nullptr && sv_cheats->m_pParent->m_Value.m_nValue != 0 )
    {
      gEvilImpulse101 = 1;
      CCSPlayer::AddAccount(this, amount: 16000, bTrackChange: true, bItemBought: false);
      CBaseCombatCharacter::GiveAmmo(this, iCount: 250, szName: "BULLET_PLAYER_50AE", bSuppressSound: false);
      CBaseCombatCharacter::GiveAmmo(this, iCount: 250, szName: "BULLET_PLAYER_762MM", bSuppressSound: false);
      CBaseCombatCharacter::GiveAmmo(this, iCount: 250, szName: "BULLET_PLAYER_338MAG", bSuppressSound: false);
      CBaseCombatCharacter::GiveAmmo(this, iCount: 250, szName: "BULLET_PLAYER_556MM", bSuppressSound: false);
      CBaseCombatCharacter::GiveAmmo(this, iCount: 250, szName: "BULLET_PLAYER_556MM_BOX", bSuppressSound: false);
      CBaseCombatCharacter::GiveAmmo(this, iCount: 250, szName: "BULLET_PLAYER_9MM", bSuppressSound: false);
      CBaseCombatCharacter::GiveAmmo(this, iCount: 250, szName: "BULLET_PLAYER_BUCKSHOT", bSuppressSound: false);
      CBaseCombatCharacter::GiveAmmo(this, iCount: 250, szName: "BULLET_PLAYER_45ACP", bSuppressSound: false);
      CBaseCombatCharacter::GiveAmmo(this, iCount: 250, szName: "BULLET_PLAYER_357SIG", bSuppressSound: false);
      CBaseCombatCharacter::GiveAmmo(this, iCount: 250, szName: "BULLET_PLAYER_57MM", bSuppressSound: false);
      gEvilImpulse101 = 0;
    }
  }
  else
  {
    CBasePlayer::CheatImpulseCommands(this, a2: (int)this, iImpulse);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028B170
// Name: public: virtual void CCSPlayer::OnSwitchWeapons(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSPlayer::OnSwitchWeapons(
        CCSPlayer *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        CBaseCombatWeapon *pBaseWeapon)
{
  CWeaponCSBase *v5; // edi
  IGameEvent *v6; // esi
  const char *pszValue; // ebx
  int v8; // eax
  int v9; // eax
  IGameEvent_vtbl *v10; // ebx
  bool v11; // al
  IGameEvent_vtbl *v12; // ebx
  bool v13; // al
  const CCSWeaponInfo *CSWpnData; // eax
  CSWeaponType m_WeaponType; // esi
  CBaseCombatWeapon *v16; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CSWeaponID *m_pMemory; // ecx
  int v20; // eax
  CSWeaponID *v21; // edi

  if ( pBaseWeapon != nullptr )
  {
    v5 = (CWeaponCSBase *)__RTDynamicCast(
                            inptr: pBaseWeapon,
                            VfDelta: 0,
                            SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
                            TargetType: &CWeaponCSBase `RTTI Type Descriptor',
                            isReference: 0);
    if ( v5 != nullptr )
    {
      v6 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "item_equip", a3: 0, a4: 0);
      if ( v6 != nullptr )
      {
        pszValue = v5->m_iClassname.pszValue;
        if ( pszValue == nullptr )
          pszValue = locale;
        if ( strncmp(first: pszValue, last: "weapon_", count: 7u) == 0 )
          pszValue += 7;
        v8 = ((int (__thiscall *)(IVEngineServer *, edict_t *, int, int, int))engine->GetPlayerUserId)(
               a1: engine,
               a2: this->m_Network.m_pPev,
               a3: a4,
               a4: a2,
               a5: a3);
        v6->SetInt(this: v6, a2: "userid", a3: v8);
        v6->SetString(this: v6, a2: "item", a3: pszValue);
        if ( !v5->IsZoomOrKnife(this: v5) || (v9 = v5->GetCSWeaponID(this: v5), LOBYTE(pBaseWeapon) = 1, v9 == 31) )
          LOBYTE(pBaseWeapon) = 0;
        v6->SetBool(this: v6, a2: "canzoom", a3: (bool)pBaseWeapon);
        v10 = v6->__vftable;
        v11 = v5->HasSilencer(this: v5);
        v10->SetBool(this: v6, a2: "hassilencer", a3: v11);
        v12 = v6->__vftable;
        v13 = v5->IsSilenced(this: v5);
        v12->SetBool(this: v6, a2: "issilenced", a3: v13);
        CSWpnData = CWeaponCSBase::GetCSWpnData(this: v5);
        v6->SetBool(this: v6, a2: "hastracers", a3: CSWpnData->m_iTracerFequency > 0);
        CWeaponCSBase::GetCSWpnData(this: v5);
        ((void (__thiscall *)(IGameEvent *, const char *))v6->SetInt)(a1: v6, a2: "weptype");
        ((void (__thiscall *)(IGameEventManager2 *))gameeventmanager->FireEvent)(a1: gameeventmanager);
      }
      m_WeaponType = CWeaponCSBase::GetCSWpnData(this: v5)->m_WeaponType;
      v16 = (CBaseCombatWeapon *)v5->GetCSWeaponID(this: v5);
      pBaseWeapon = v16;
      if ( m_WeaponType != WEAPONTYPE_KNIFE
        && m_WeaponType != WEAPONTYPE_C4
        && m_WeaponType != WEAPONTYPE_GRENADE
        && CUtlVector<enum CSWeaponID,CUtlMemory<enum CSWeaponID,int>>::Find(
             this: (CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > *)&this->m_WeaponTypesHeld,
             src: &pBaseWeapon) == -1 )
      {
        m_Size = this->m_WeaponTypesHeld.m_Size;
        m_nAllocationCount = this->m_WeaponTypesHeld.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CNavLadder *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_WeaponTypesHeld,
            num: m_Size - m_nAllocationCount + 1);
        ++this->m_WeaponTypesHeld.m_Size;
        m_pMemory = this->m_WeaponTypesHeld.m_Memory.m_pMemory;
        v20 = this->m_WeaponTypesHeld.m_Size - m_Size - 1;
        this->m_WeaponTypesHeld.m_pElements = m_pMemory;
        if ( v20 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v20);
        v21 = &this->m_WeaponTypesHeld.m_Memory.m_pMemory[m_Size];
        if ( v21 != nullptr )
          *v21 = (CSWeaponID)v16;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028B3B0
// Name: public: void CCSPlayer::Reset(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::Reset(CCSPlayer *this, bool resetScore)
{
  edict_t *m_pPev; // ecx
  int StartMoney; // eax
  ConVarRef v5; // [esp+8h] [ebp-8h] BYREF

  CCSPlayer::RemoveNemesisRelationships(this);
  if ( resetScore )
  {
    CBasePlayer::ResetFragCount(this);
    CBasePlayer::ResetDeathCount(this);
    ConVarRef::ConVarRef(this: &v5, pName: "score_default");
    this->m_iScore = v5.m_pConVarState->m_Value.m_nValue;
    this->m_iRoundScore = 0;
    this->m_iRoundProximityScore = 0;
    this->m_iContributionScore = 0;
  }
  if ( this->m_iAccount.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x1900u);
    }
    this->m_iAccount.m_Value = 0;
  }
  CCSPlayer::AddAccount(this, amount: -16000, bTrackChange: false, bItemBought: false);
  this->RemoveAllItems(this, a2: true);
  StartMoney = CCSGameRules::GetStartMoney(this: (CCSGameRules *)g_pGameRules);
  CCSPlayer::AddAccount(this, amount: StartMoney, bTrackChange: true, bItemBought: false);
}

//------------------------------------------------------------------------------
// Address: 0x1028B480
// Name: public: void CCSPlayer::AddAccount(enum CashAwardReason,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::AddAccount(CCSPlayer *this, CashAwardReason reason, bool bTrackChange, bool bItemBought)
{
  int v4; // eax

  v4 = 0;
  switch ( reason )
  {
    case CASH_AWARD_KILL_TEAMMATE:
      CCSPlayer::AddAccount(this, amount: -2200, bTrackChange, bItemBought);
      break;
    case CASH_AWARD_KILLED_VIP:
      CCSPlayer::AddAccount(this, amount: 2500, bTrackChange, bItemBought);
      break;
    case CASH_AWARD_KILLED_ENEMY:
      CCSPlayer::AddAccount(this, amount: 300, bTrackChange, bItemBought);
      break;
    case CASH_AWARD_RESCUED_HOSTAGE:
      CCSPlayer::AddAccount(this, amount: 1000, bTrackChange, bItemBought);
      break;
    case CASH_AWARD_INTERACT_WITH_HOSTAGE:
      v4 = 150;
      goto LABEL_7;
    default:
LABEL_7:
      CCSPlayer::AddAccount(this, amount: v4, bTrackChange, bItemBought);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028B520
// Name: public: enum BuyResult_e CCSPlayer::HandleCommand_Buy_Internal(char const __near *)
// Source: json
//------------------------------------------------------------------------------
BuyResult_e __thiscall CCSPlayer::HandleCommand_Buy_Internal(CCSPlayer *this, const char *wpnName)
{
  bool v3; // al
  CGameRules *v4; // edi
  CSWeaponID m_nValue; // edi
  CCSWeaponInfo *WeaponInfo; // ebx
  BuyResult_e v7; // eax
  int v9; // eax
  int v10; // edi
  const char *m_WrongTeamMsg; // ebx
  CBaseCombatWeapon *v12; // eax
  int v13; // eax
  int iSlot; // eax
  bool v15; // zf
  int WeaponPrice; // eax
  char itemNameUsed[256]; // [esp+Ch] [ebp-108h] BYREF
  CSWeaponID weaponId; // [esp+10Ch] [ebp-8h]
  BuyResult_e v19; // [esp+110h] [ebp-4h]
  const char *wpnNamea; // [esp+11Ch] [ebp+8h]

  if ( this->m_bInBuyZone.m_Value && !this->m_isVIP )
  {
    v4 = g_pGameRules;
    if ( this->m_lifeState.m_Value != 0 )
    {
      v3 = false;
    }
    else if ( CCSGameRules::IsBuyTimeElapsed(this: (CCSGameRules *)g_pGameRules) )
    {
      v3 = false;
    }
    else if ( this->m_bIsVIP )
    {
      v3 = false;
    }
    else
    {
      v3 = (BYTE1(v4[136].m_pNext) == 0 || CBaseEntity::GetTeamNumber(this) != 3)
        && (LOBYTE(v4[136].m_pNext) == 0 || CBaseEntity::GetTeamNumber(this) != 2)
        && !this->m_bIsControllingBot.m_Value;
    }
  }
  else
  {
    v3 = false;
  }
  v19 = 2 * !v3 + 3;
  wpnNamea = GetTranslatedWeaponAlias(szAlias: wpnName);
  m_nValue = AliasToWeaponID(szAlias: wpnNamea);
  weaponId = m_nValue;
  WeaponInfo = GetWeaponInfo(weaponID: m_nValue);
  if ( WeaponInfo == nullptr )
  {
    if ( _V_stricmp(s1: itemNameUsed, s2: "primammo") != 0 )
    {
      if ( _V_stricmp(s1: itemNameUsed, s2: "secammo") != 0 )
        goto LABEL_21;
      v7 = CCSPlayer::AttemptToBuyAmmo(this, iAmmoType: 1u);
    }
    else
    {
      v7 = CCSPlayer::AttemptToBuyAmmo(this, iAmmoType: 0);
    }
    v19 = v7;
LABEL_21:
    if ( v19 == BUY_BOUGHT )
      CCSPlayer::BuildRebuyStruct(this, a2: (int)WeaponInfo, a3: m_nValue);
    return v19;
  }
  if ( !CCSPlayer::CanPlayerBuy(this, display: true) )
    return BUY_PLAYER_CANT_BUY;
  switch ( m_nValue )
  {
    case WEAPON_EQUIPMENT_FIRST:
      v9 = CCSPlayer::AttemptToBuyVest(this, a2: 39);
      break;
    case WEAPON_ASSAULTSUIT:
      v9 = CCSPlayer::AttemptToBuyAssaultSuit(this, a2: 40);
      break;
    case WEAPON_SHIELDGUN:
      v9 = CCSPlayer::AttemptToBuyShield(this);
      break;
    case WEAPON_NVG:
      v9 = CCSPlayer::AttemptToBuyNightVision(this);
      break;
    default:
      goto LABEL_41;
  }
  v10 = v9;
  if ( v9 != 5 )
  {
    if ( v9 == 0 )
      CCSPlayer::BuildRebuyStruct(this, a2: (int)WeaponInfo, a3: 0);
    return v10;
  }
  m_nValue = weaponId;
LABEL_41:
  if ( WeaponInfo->m_iTeam != 0 && CBaseEntity::GetTeamNumber(this) != WeaponInfo->m_iTeam )
  {
    m_WrongTeamMsg = WeaponInfo->m_WrongTeamMsg;
    if ( *m_WrongTeamMsg != 0 )
      ClientPrint(
        player: this,
        msg_dest: 4u,
        msg_name: "#Alias_Not_Avail",
        param1: m_WrongTeamMsg,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
    return BUY_NOT_ALLOWED;
  }
  if ( CCSWeaponInfo::GetWeaponPrice(this: WeaponInfo) <= 0 )
    goto LABEL_21;
  if ( WeaponInfo->m_WeaponType == WEAPONTYPE_GRENADE )
  {
    if ( this->m_iAccount.m_Value < CCSWeaponInfo::GetWeaponPrice(this: WeaponInfo) )
      goto LABEL_21;
    switch ( m_nValue )
    {
      case WEAPON_FLASHBANG:
        if ( ammo_flashbang_max.m_pParent == nullptr )
          goto LABEL_52;
        m_nValue = ammo_flashbang_max.m_pParent->m_Value.m_nValue;
        break;
      case WEAPON_HEGRENADE:
        if ( ammo_hegrenade_max.m_pParent == nullptr )
          goto LABEL_52;
        m_nValue = ammo_hegrenade_max.m_pParent->m_Value.m_nValue;
        break;
      case WEAPON_SMOKEGRENADE:
        if ( ammo_smokegrenade_max.m_pParent == nullptr )
          goto LABEL_52;
        m_nValue = ammo_smokegrenade_max.m_pParent->m_Value.m_nValue;
        break;
      case WEAPON_MOLOTOV:
        if ( ammo_molotov_max.m_pParent == nullptr )
          goto LABEL_52;
        m_nValue = ammo_molotov_max.m_pParent->m_Value.m_nValue;
        break;
      case WEAPON_DECOY:
        if ( ammo_decoy_max.m_pParent != nullptr )
          m_nValue = ammo_decoy_max.m_pParent->m_Value.m_nValue;
        else
LABEL_52:
          m_nValue = WEAPON_NONE;
        break;
      default:
        m_nValue = WEAPON_DEAGLE;
        break;
    }
    v12 = this->Weapon_OwnsThisType(this, a2: WeaponInfo->szClassName, a3: 0);
    if ( v12 != nullptr )
    {
      v13 = v12->GetPrimaryAmmoType(this: v12);
      if ( v13 != -1 && CBaseCombatCharacter::GetAmmoCount(this, iAmmoIndex: v13) >= m_nValue )
      {
        if ( !this->m_bIsInAutoBuy && !this->m_bIsInRebuy )
          ClientPrint(
            player: this,
            msg_dest: 4u,
            msg_name: "#Cannot_Carry_Anymore",
            param1: nullptr,
            param2: nullptr,
            param3: nullptr,
            param4: nullptr);
        return BUY_ALREADY_HAVE;
      }
    }
    goto LABEL_76;
  }
  if ( this->Weapon_OwnsThisType(this, a2: WeaponInfo->szClassName, a3: 0) != nullptr )
    return BUY_ALREADY_HAVE;
  if ( this->m_iAccount.m_Value >= CCSWeaponInfo::GetWeaponPrice(this: WeaponInfo) )
  {
    if ( this->m_lifeState.m_Value != 2 )
    {
      iSlot = WeaponInfo->iSlot;
      if ( iSlot == 1 )
      {
        CCSPlayer::DropPistol(this, fromDeath: false);
      }
      else if ( iSlot == 0 )
      {
        CCSPlayer::DropRifle(this, fromDeath: false);
      }
    }
LABEL_76:
    v15 = WeaponInfo->iSlot == 1;
    v19 = BUY_BOUGHT;
    if ( v15 )
      this->m_bUsingDefaultPistol = false;
    this->GiveNamedItem(this, a2: WeaponInfo->szClassName, a3: 0);
    WeaponPrice = CCSWeaponInfo::GetWeaponPrice(this: WeaponInfo);
    CCSPlayer::AddAccount(this, amount: -WeaponPrice, bTrackChange: true, bItemBought: true);
    BlackMarketAddWeapon(pWeaponName: wpnNamea, pBuyer: this);
    CCSPlayer::BuildRebuyStruct(this, a2: (int)WeaponInfo, a3: m_nValue);
    return v19;
  }
  if ( !this->m_bIsInAutoBuy && !this->m_bIsInRebuy )
    ClientPrint(
      player: this,
      msg_dest: 4u,
      msg_name: "#Not_Enough_Money",
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  return BUY_CANT_AFFORD;
}

//------------------------------------------------------------------------------
// Address: 0x1028B900
// Name: private: static class CCSPlayerStateInfo __near * CCSPlayer::State_LookupInfo(enum CSPlayerState)
// Source: json
//------------------------------------------------------------------------------
CCSPlayerStateInfo *__cdecl CCSPlayer::State_LookupInfo(CSPlayerState state)
{
  unsigned int v1; // eax
  int v2; // ecx
  unsigned __int64 v4; // [esp+8h] [ebp-8h]

  v1 = 0;
  if ( (_S8_14 & 1) == 0 )
  {
    _S8_14 |= 1u;
    qword_105C9210 = (unsigned int)CCSPlayer::State_Enter_ACTIVE;
    qword_105C9218 = 0;
    qword_105C9220 = 0;
    qword_105C9228 = 0xFFFFFFFF00000000uLL;
    qword_105C9230 = (unsigned int)CCSPlayer::State_PreThink_ACTIVE;
    qword_105C9238 = 0;
    qword_105C9248 = (unsigned int)CCSPlayer::State_Enter_WELCOME;
    qword_105C9250 = 0;
    qword_105C9258 = 0;
    qword_105C9260 = 0xFFFFFFFF00000000uLL;
    qword_105C9268 = (unsigned int)CCSPlayer::State_PreThink_WELCOME;
    qword_105C9270 = 0;
    qword_105C9280 = (unsigned int)CCSPlayer::State_Enter_PICKINGTEAM;
    qword_105C9288 = 0;
    qword_105C9290 = 0;
    qword_105C9298 = 0xFFFFFFFF00000000uLL;
    qword_105C92A0 = (unsigned int)CCSPlayer::State_PreThink_OBSERVER_MODE;
    dword_105C9240 = 1;
    dword_105C9244 = (int)"STATE_WELCOME";
    dword_105C9278 = 2;
    dword_105C927C = (int)"STATE_PICKINGTEAM";
    qword_105C92A8 = 0;
    dword_105C92B0 = 3;
    dword_105C92B4 = (int)"STATE_PICKINGCLASS";
    qword_105C92B8 = (unsigned int)CCSPlayer::State_Enter_PICKINGCLASS;
    qword_105C92C0 = 0;
    qword_105C92C8 = 0;
    qword_105C92D0 = 0xFFFFFFFF00000000uLL;
    qword_105C92D8 = (unsigned int)CCSPlayer::State_PreThink_OBSERVER_MODE;
    qword_105C92E0 = 0;
    qword_105C92F0 = (unsigned int)CCSPlayer::State_Enter_DEATH_ANIM;
    qword_105C92F8 = 0;
    qword_105C9300 = 0;
    qword_105C9308 = 0xFFFFFFFF00000000uLL;
    qword_105C9310 = (unsigned int)CCSPlayer::State_PreThink_DEATH_ANIM;
    qword_105C9318 = 0;
    qword_105C9328 = (unsigned int)CCSPlayer::State_Enter_DEATH_WAIT_FOR_KEY;
    qword_105C9330 = 0;
    qword_105C9338 = 0;
    qword_105C9340 = 0xFFFFFFFF00000000uLL;
    qword_105C9348 = (unsigned int)CCSPlayer::State_PreThink_DEATH_WAIT_FOR_KEY;
    dword_105C92E8 = 4;
    dword_105C92EC = (int)"STATE_DEATH_ANIM";
    dword_105C9320 = 5;
    dword_105C9324 = (int)"STATE_DEATH_WAIT_FOR_KEY";
    qword_105C9350 = 0;
    dword_105C9358 = 6;
    dword_105C935C = (int)"STATE_OBSERVER_MODE";
    qword_105C9360 = (unsigned int)CCSPlayer::State_Enter_OBSERVER_MODE;
    qword_105C9368 = 0;
    qword_105C9370 = 0;
    qword_105C9378 = 0xFFFFFFFF00000000uLL;
    qword_105C9380 = (unsigned int)CCSPlayer::State_PreThink_OBSERVER_MODE;
    qword_105C9388 = 0;
    qword_105C9398 = (unsigned int)CCSPlayer::State_Enter_GUNGAME_RESPAWN;
    qword_105C93A0 = 0;
    qword_105C93A8 = 0;
    qword_105C93B0 = 0xFFFFFFFF00000000uLL;
    qword_105C93B8 = (unsigned int)CCSPlayer::State_PreThink_GUNGAME_RESPAWN;
    qword_105C93C0 = 0;
    qword_105C93D0 = 0;
    qword_105C93D8 = 0xFFFFFFFF00000000uLL;
    qword_105C93E0 = 0;
    qword_105C93E8 = 0xFFFFFFFF00000000uLL;
    v4 = 0xFFFFFFFF00000000uLL;
    qword_105C93F0 = 0;
    dword_105C9390 = 7;
    dword_105C9394 = (int)"STATE_GUNGAME_RESPAWN";
    dword_105C93C8 = 8;
    dword_105C93CC = (int)"STATE_DORMANT";
    qword_105C93F8 = 0xFFFFFFFF00000000uLL;
  }
  v2 = 0;
  while ( playerStateInfos[v1].m_iPlayerState != state )
  {
    ++v1;
    ++v2;
    if ( v1 >= 9 )
      return nullptr;
  }
  return &playerStateInfos[v2];
}

//------------------------------------------------------------------------------
// Address: 0x1028BE30
// Name: public: void CCSPlayer::PlayerUsedFirearm(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::PlayerUsedFirearm(CCSPlayer *this, CBaseCombatWeapon *pBaseWeapon)
{
  edict_t *m_pPev; // ecx
  CWeaponCSBase *v4; // eax
  CWeaponCSBase *v5; // esi
  CSWeaponType m_WeaponType; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CSWeaponID *m_pMemory; // ecx
  int v10; // eax
  CSWeaponID *v11; // eax

  if ( CCSGameRules::IsPlayingGunGameProgressive(this: (CCSGameRules *)g_pGameRules)
    || CCSGameRules::IsPlayingGunGameTRBomb(this: (CCSGameRules *)g_pGameRules) )
  {
    if ( this->m_bGunGameImmunity.m_Value )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x1311u);
      }
      this->m_bGunGameImmunity.m_Value = false;
    }
    this->m_fImmuneToGunGameDamageTime = 0.0;
  }
  if ( pBaseWeapon != nullptr )
  {
    v4 = (CWeaponCSBase *)__RTDynamicCast(
                            inptr: pBaseWeapon,
                            VfDelta: 0,
                            SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
                            TargetType: &CWeaponCSBase `RTTI Type Descriptor',
                            isReference: 0);
    v5 = v4;
    if ( v4 != nullptr )
    {
      m_WeaponType = CWeaponCSBase::GetCSWpnData(this: v4)->m_WeaponType;
      pBaseWeapon = (CBaseCombatWeapon *)v5->GetCSWeaponID(this: v5);
      if ( m_WeaponType != WEAPONTYPE_KNIFE
        && m_WeaponType != WEAPONTYPE_C4
        && m_WeaponType != WEAPONTYPE_GRENADE
        && CUtlVector<enum CSWeaponID,CUtlMemory<enum CSWeaponID,int>>::Find(
             this: (CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > *)&this->m_WeaponTypesUsed,
             src: &pBaseWeapon) == -1 )
      {
        m_Size = this->m_WeaponTypesUsed.m_Size;
        m_nAllocationCount = this->m_WeaponTypesUsed.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CNavLadder *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_WeaponTypesUsed,
            num: m_Size - m_nAllocationCount + 1);
        ++this->m_WeaponTypesUsed.m_Size;
        m_pMemory = this->m_WeaponTypesUsed.m_Memory.m_pMemory;
        v10 = this->m_WeaponTypesUsed.m_Size - m_Size - 1;
        this->m_WeaponTypesUsed.m_pElements = m_pMemory;
        if ( v10 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v10);
        v11 = &this->m_WeaponTypesUsed.m_Memory.m_pMemory[m_Size];
        if ( v11 != nullptr )
          *v11 = (CSWeaponID)pBaseWeapon;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028BF80
// Name: public: void CCSPlayer::AddBurnDamageDelt(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::AddBurnDamageDelt(CCSPlayer *this, vgui::TreeNode *entityIndex)
{
  CUtlMemory<vgui::TreeNode *,int> *p_m_BurnDamageDeltVec; // esi
  int m_Size; // ecx
  int v4; // eax
  vgui::TreeNode **m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v7; // edi
  vgui::TreeNode **v8; // ecx
  int v9; // eax
  vgui::TreeNode **v10; // eax

  p_m_BurnDamageDeltVec = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_BurnDamageDeltVec;
  m_Size = this->m_BurnDamageDeltVec.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = p_m_BurnDamageDeltVec->m_pMemory;
  while ( *m_pMemory != entityIndex )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
  {
LABEL_7:
    m_nAllocationCount = p_m_BurnDamageDeltVec->m_nAllocationCount;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(this: p_m_BurnDamageDeltVec, num: m_Size - m_nAllocationCount + 1);
    ++p_m_BurnDamageDeltVec[1].m_pMemory;
    v8 = p_m_BurnDamageDeltVec->m_pMemory;
    v9 = (int)p_m_BurnDamageDeltVec[1].m_pMemory - v7 - 1;
    p_m_BurnDamageDeltVec[1].m_nAllocationCount = (int)p_m_BurnDamageDeltVec->m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &v8[v7 + 1], src: &v8[v7], count: 4 * v9);
    v10 = &p_m_BurnDamageDeltVec->m_pMemory[v7];
    if ( v10 != nullptr )
      *v10 = entityIndex;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028C010
// Name: public: void CCSPlayer::PlayerEmptiedAmmoForFirearm(class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::PlayerEmptiedAmmoForFirearm(CCSPlayer *this, CBaseCombatWeapon *pBaseWeapon)
{
  CWeaponCSBase *v3; // eax
  CWeaponCSBase *v4; // esi
  CSWeaponType m_WeaponType; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CSWeaponID *m_pMemory; // ecx
  int v9; // eax
  CSWeaponID *v10; // eax

  if ( pBaseWeapon != nullptr )
  {
    v3 = (CWeaponCSBase *)__RTDynamicCast(
                            inptr: pBaseWeapon,
                            VfDelta: 0,
                            SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
                            TargetType: &CWeaponCSBase `RTTI Type Descriptor',
                            isReference: 0);
    v4 = v3;
    if ( v3 != nullptr )
    {
      m_WeaponType = CWeaponCSBase::GetCSWpnData(this: v3)->m_WeaponType;
      pBaseWeapon = (CBaseCombatWeapon *)v4->GetCSWeaponID(this: v4);
      if ( m_WeaponType != WEAPONTYPE_KNIFE
        && m_WeaponType != WEAPONTYPE_C4
        && m_WeaponType != WEAPONTYPE_GRENADE
        && CUtlVector<enum CSWeaponID,CUtlMemory<enum CSWeaponID,int>>::Find(
             this: (CUtlVector<CBaseEntity *,CUtlMemory<CBaseEntity *,int> > *)&this->m_WeaponTypesRunningOutOfAmmo,
             src: &pBaseWeapon) == -1 )
      {
        m_Size = this->m_WeaponTypesRunningOutOfAmmo.m_Size;
        m_nAllocationCount = this->m_WeaponTypesRunningOutOfAmmo.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CNavLadder *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_WeaponTypesRunningOutOfAmmo,
            num: m_Size - m_nAllocationCount + 1);
        ++this->m_WeaponTypesRunningOutOfAmmo.m_Size;
        m_pMemory = this->m_WeaponTypesRunningOutOfAmmo.m_Memory.m_pMemory;
        v9 = this->m_WeaponTypesRunningOutOfAmmo.m_Size - m_Size - 1;
        this->m_WeaponTypesRunningOutOfAmmo.m_pElements = m_pMemory;
        if ( v9 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
        v10 = &this->m_WeaponTypesRunningOutOfAmmo.m_Memory.m_pMemory[m_Size];
        if ( v10 != nullptr )
          *v10 = (CSWeaponID)pBaseWeapon;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028C100
// Name: public: static void CCSPlayer::ProcessPlayerDeathAchievements(class CCSPlayer __near *,class CCSPlayer __near *,class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CCSPlayer::ProcessPlayerDeathAchievements(
        CCSPlayer *pAttacker,
        CCSPlayer *pVictim,
        const CTakeDamageInfo *info)
{
  unsigned int m_Index; // eax
  int TeamNumber; // ebx
  CBaseCombatWeapon *ActiveWeapon; // eax
  CWeaponCSBase *v7; // ebx
  CBaseCombatWeapon *v8; // eax
  CSWeaponID WeaponIdCausingDamange; // eax
  bool v10; // zf
  CSWeaponID v11; // edi
  CBaseCombatWeapon *v12; // eax
  int m_Value; // edi
  int j; // ebx
  int v15; // ebx
  int m_iDamage; // edi
  int (__thiscall *GetMaxHealth)(CBaseEntity *); // eax
  const char *v18; // eax
  CBasePlayer *v19; // edi
  const char *v20; // eax
  int v21; // ebx
  CCSPlayer *v22; // eax
  int v23; // eax
  unsigned int v24; // ecx
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CHandle<CCSPlayer> *m_pMemory; // ecx
  int v28; // eax
  CHandle<CCSPlayer> *v29; // ebx
  int v30; // eax
  int v31; // edi
  unsigned int v32; // eax
  CBaseEntity *m_pEntity; // ecx
  int v34; // ebx
  unsigned int v35; // eax
  CCSPlayer *v36; // ecx
  int m_KillingSpreeStartTime; // eax
  int m_NumEnemiesKilledThisRound; // eax
  CBaseMultiplayerPlayer *v39; // eax
  int v40; // ecx
  int v41; // eax
  int *v42; // edx
  int v43; // eax
  int v44; // ebx
  int *v45; // ecx
  int v46; // eax
  int *v47; // ebx
  float m_blindStartTime; // xmm0_4
  int FOV; // ebx
  int v50; // ebx
  bool v51; // bl
  CBaseCombatWeapon *v52; // eax
  void *v53; // eax
  int v54; // eax
  bool v55; // bl
  int v56; // edi
  unsigned int v57; // eax
  CBaseEntity **v58; // ecx
  CBaseMultiplayerPlayer *v59; // edi
  int v60; // ebx
  CBaseMultiplayerPlayer *v61; // ebx
  CBasePlayer *v62; // eax
  CCSPlayer *v63; // esi
  int v64; // edi
  int v65; // eax
  const char *v66; // [esp-4h] [ebp-5Ch]
  const char *v67; // [esp-4h] [ebp-5Ch]
  int teamAliveCount[4]; // [esp+10h] [ebp-48h]
  int teamIgnoreCount[4]; // [esp+20h] [ebp-38h] BYREF
  int teamCount[4]; // [esp+30h] [ebp-28h] BYREF
  CWeaponCSBase *pVictimWeapon; // [esp+40h] [ebp-18h]
  CWeaponCSBase *pAttackerWeapon; // [esp+44h] [ebp-14h]
  int v73; // [esp+48h] [ebp-10h]
  int livePlayerCount; // [esp+4Ch] [ebp-Ch]
  CSWeaponID attackerWeaponId; // [esp+50h] [ebp-8h]
  bool attackerZoomed; // [esp+57h] [ebp-1h]
  int savedregs; // [esp+58h] [ebp+0h] BYREF
  int i; // [esp+60h] [ebp+8h]
  unsigned int ia; // [esp+60h] [ebp+8h]
  int ib; // [esp+60h] [ebp+8h]
  int ic; // [esp+60h] [ebp+8h]
  bool i_3; // [esp+63h] [ebp+Bh]
  char i_3a; // [esp+63h] [ebp+Bh]

  m_Index = info->m_hInflictor.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    livePlayerCount = 0;
  else
    livePlayerCount = (int)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( pVictim != nullptr )
  {
    pVictim->m_wasKilledThisRound = true;
    pVictim->m_numRoundsSurvived = 0;
    pVictim->m_lowHealthGoalTime = 0.0;
  }
  if ( pAttacker != nullptr && pVictim != nullptr )
  {
    TeamNumber = CBaseEntity::GetTeamNumber(this: pAttacker);
    if ( CBaseEntity::GetTeamNumber(this: pVictim) != TeamNumber )
    {
      ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: pAttacker);
      v7 = (CWeaponCSBase *)__RTDynamicCast(
                              inptr: ActiveWeapon,
                              VfDelta: 0,
                              SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
                              TargetType: &CWeaponCSBase `RTTI Type Descriptor',
                              isReference: 0);
      pAttackerWeapon = v7;
      v8 = CBaseCombatCharacter::GetActiveWeapon(this: pVictim);
      pVictimWeapon = (CWeaponCSBase *)__RTDynamicCast(
                                         inptr: v8,
                                         VfDelta: 0,
                                         SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
                                         TargetType: &CWeaponCSBase `RTTI Type Descriptor',
                                         isReference: 0);
      WeaponIdCausingDamange = CCSPlayer::GetWeaponIdCausingDamange(info);
      v10 = !pVictim->m_bIsDefusing.m_Value;
      v11 = WeaponIdCausingDamange;
      attackerWeaponId = WeaponIdCausingDamange;
      if ( !v10 )
      {
        CBaseMultiplayerPlayer::AwardAchievement(this: pAttacker, iAchievement: 1005, iCount: 1);
        pAttacker->m_bKilledDefuser = true;
        if ( v11 == WEAPON_HEGRENADE )
          CBaseMultiplayerPlayer::AwardAchievement(this: pAttacker, iAchievement: 3027, iCount: 1);
      }
      v12 = CBaseCombatCharacter::GetActiveWeapon(this: pVictim);
      if ( v12 != nullptr && v12->m_bInReload.m_Value )
        CBaseMultiplayerPlayer::AwardAchievement(this: pAttacker, iAchievement: 3005, iCount: 1);
      if ( v7 != nullptr )
      {
        if ( v7->UsesClipsForAmmo1(this: v7) && (m_Value = v7->m_iClip1.m_Value) + 1 == v7->GetMaxClip1(this: v7) )
        {
          if ( ++pAttacker->m_firstShotKills >= 3 )
            CBaseMultiplayerPlayer::AwardAchievement(this: pAttacker, iAchievement: 3049, iCount: 1);
        }
        else
        {
          pAttacker->m_firstShotKills = 0;
        }
      }
      if ( pAttacker->m_bulletsFiredSinceLastSpawn == 1
        && CCSGameRules::IsPlayingGunGameProgressive(this: (CCSGameRules *)g_pGameRules) )
      {
        CBaseMultiplayerPlayer::AwardAchievement(this: pAttacker, iAchievement: 3051, iCount: 1);
      }
      if ( pVictim->m_bIsRescuing && !pAttacker->m_bInjuredAHostage && pVictim->m_iNumFollowers == g_Hostages.m_Size )
      {
        CBaseMultiplayerPlayer::AwardAchievement(this: pAttacker, iAchievement: 2002, iCount: 1);
        pAttacker->m_bKilledRescuer = true;
      }
      for ( j = pVictim->m_DamageTakenList.m_Head;
            j != -1;
            j = *(int *)((char *)&pVictim->m_DamageTakenList.m_Memory.m_pMemory->m_Next + v15) )
      {
        v15 = 12 * j;
        m_iDamage = (*(CDamageRecord **)((char *)&pVictim->m_DamageTakenList.m_Memory.m_pMemory->m_Element + v15))->m_iDamage;
        GetMaxHealth = pVictim->GetMaxHealth;
        v73 = v15;
        if ( m_iDamage >= GetMaxHealth(this: pVictim) - 5 )
        {
          v66 = *(const char **)((char *)&pVictim->m_DamageTakenList.m_Memory.m_pMemory->m_Element + v15);
          v18 = pAttacker->GetPlayerName(this: pAttacker);
          if ( V_strncmp(s1: v18, s2: v66, count: 32) != 0 )
          {
            for ( i = 1; i <= 64; ++i )
            {
              v19 = UTIL_PlayerByIndex(playerIndex: i);
              if ( v19 != nullptr )
              {
                v67 = *(const char **)((char *)&pVictim->m_DamageTakenList.m_Memory.m_pMemory->m_Element + v15);
                v20 = v19->GetPlayerName(this: v19);
                if ( V_strncmp(s1: v20, s2: v67, count: 32) == 0 )
                {
                  v21 = CBaseEntity::GetTeamNumber(this: v19);
                  if ( v21 != CBaseEntity::GetTeamNumber(this: pVictim) )
                  {
                    v22 = ToCSPlayer(pEntity: v19);
                    CBaseMultiplayerPlayer::AwardAchievement(this: v22, iAchievement: 5023, iCount: 1);
                    v15 = v73;
                    break;
                  }
                  v15 = v73;
                }
              }
            }
          }
        }
      }
      ++pAttacker->m_NumEnemiesKilledThisRound;
      v23 = ++pAttacker->m_NumEnemiesKilledThisSpawn;
      if ( v23 > pAttacker->m_maxNumEnemiesKillStreak )
        pAttacker->m_maxNumEnemiesKillStreak = v23;
      CUtlVector<float,CUtlMemory<float,int>>::InsertBefore(
        this: &pAttacker->m_killTimes,
        elem: pAttacker->m_killTimes.m_Size,
        src: &gpGlobals->curtime);
      v24 = pVictim->GetRefEHandle(this: pVictim)->m_Index;
      m_Size = pAttacker->m_enemyPlayersKilledThisRound.m_Size;
      m_nAllocationCount = pAttacker->m_enemyPlayersKilledThisRound.m_Memory.m_nAllocationCount;
      ia = v24;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&pAttacker->m_enemyPlayersKilledThisRound,
          num: m_Size - m_nAllocationCount + 1);
      ++pAttacker->m_enemyPlayersKilledThisRound.m_Size;
      m_pMemory = pAttacker->m_enemyPlayersKilledThisRound.m_Memory.m_pMemory;
      v28 = pAttacker->m_enemyPlayersKilledThisRound.m_Size - m_Size - 1;
      pAttacker->m_enemyPlayersKilledThisRound.m_pElements = m_pMemory;
      if ( v28 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v28);
      v29 = &pAttacker->m_enemyPlayersKilledThisRound.m_Memory.m_pMemory[m_Size];
      if ( v29 != nullptr )
        v29->m_Index = ia;
      v30 = 0;
      for ( ib = 0; v30 < pVictim->m_enemyPlayersKilledThisRound.m_Size; ib = v30 )
      {
        v31 = v30;
        v32 = pVictim->m_enemyPlayersKilledThisRound.m_Memory.m_pMemory[v30].m_Index;
        if ( v32 != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)v32].m_SerialNumber == HIWORD(v32) )
        {
          m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v32].m_pEntity;
          if ( m_pEntity != nullptr )
          {
            v34 = CBaseEntity::GetTeamNumber(this: m_pEntity);
            if ( CBaseEntity::GetTeamNumber(this: pAttacker) == v34 )
            {
              v35 = pVictim->m_enemyPlayersKilledThisRound.m_Memory.m_pMemory[v31].m_Index;
              if ( v35 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v35].m_SerialNumber != HIWORD(v35) )
                v36 = nullptr;
              else
                v36 = (CCSPlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v35].m_pEntity;
              CCSGameStats::Event_PlayerAvengedTeammate(this: &CCS_GameStats, pAttacker, pAvengedPlayer: v36);
            }
          }
        }
        v30 = ib + 1;
      }
      for ( ; pAttacker->m_killTimes.m_Size > 0; --pAttacker->m_killTimes.m_Size )
      {
        if ( gpGlobals->curtime <= (float)(*pAttacker->m_killTimes.m_Memory.m_pMemory + 15.0) )
          break;
        if ( pAttacker->m_killTimes.m_Size - 1 > 0 )
          _V_memmove(
            dest: pAttacker->m_killTimes.m_Memory.m_pMemory,
            src: pAttacker->m_killTimes.m_Memory.m_pMemory + 1,
            count: 4 * (pAttacker->m_killTimes.m_Size - 1));
      }
      if ( pAttacker->m_killTimes.m_Size >= 5 )
      {
        pAttacker->m_KillingSpreeStartTime = (int)gpGlobals->curtime;
        CBaseMultiplayerPlayer::AwardAchievement(this: pAttacker, iAchievement: 3006, iCount: 1);
      }
      m_KillingSpreeStartTime = pVictim->m_KillingSpreeStartTime;
      if ( m_KillingSpreeStartTime >= 0 && (float)((float)m_KillingSpreeStartTime - gpGlobals->curtime) <= 5.0 )
        CBaseMultiplayerPlayer::AwardAchievement(this: pAttacker, iAchievement: 5022, iCount: 1);
      if ( pAttackerWeapon != nullptr && pAttackerWeapon->m_prevOwner == pVictim )
        CBaseMultiplayerPlayer::AwardAchievement(this: pAttacker, iAchievement: 3039, iCount: 1);
      m_NumEnemiesKilledThisRound = pAttacker->m_NumEnemiesKilledThisRound;
      if ( m_NumEnemiesKilledThisRound == pAttacker->m_NumEnemiesAtRoundStart && m_NumEnemiesKilledThisRound >= 5 )
      {
        CBaseMultiplayerPlayer::AwardAchievement(this: pAttacker, iAchievement: 5019, iCount: 1);
        if ( CCSGameRules::IsPlayingGunGameTRBomb(this: (CCSGameRules *)g_pGameRules)
          && LOBYTE(g_pGameRules[144].m_pNext) == 0 )
        {
          if ( CBaseEntity::GetTeamNumber(this: pAttacker) == 3 )
            CBaseMultiplayerPlayer::AwardAchievement(this: pAttacker, iAchievement: 6035, iCount: 1);
          else
            CBaseMultiplayerPlayer::AwardAchievement(this: pAttacker, iAchievement: 6036, iCount: 1);
        }
      }
      if ( pVictim->m_fJustLeftImmunityTime > 0.0 )
        CBaseMultiplayerPlayer::AwardAchievement(this: pAttacker, iAchievement: 3050, iCount: 1);
      if ( !pAttacker->IsAlive(this: pAttacker) && attackerWeaponId == WEAPON_HEGRENADE )
      {
        CCSGameStats::IncrementStat(
          this: &CCS_GameStats,
          pPlayer: pAttacker,
          statId: CSSTAT_GRENADE_POSTHUMOUSKILLS,
          iDelta: 1,
          bPlayerOnly: false);
        if ( pAttacker->IsPlayer(this: pAttacker) )
          v39 = (CBaseMultiplayerPlayer *)__RTDynamicCast(
                                            inptr: pAttacker,
                                            VfDelta: 0,
                                            SrcType: &CBaseEntity `RTTI Type Descriptor',
                                            TargetType: &CCSPlayer `RTTI Type Descriptor',
                                            isReference: 0);
        else
          v39 = nullptr;
        CBaseMultiplayerPlayer::AwardAchievement(this: v39, iAchievement: 5018, iCount: 1);
      }
      if ( CBaseCombatCharacter::GetActiveWeapon(this: pAttacker) != nullptr
        && CBaseCombatCharacter::GetActiveWeapon(this: pAttacker)->m_iClip1.m_Value == 0
        && pAttackerWeapon != nullptr
        && CWeaponCSBase::GetCSWpnData(this: pAttackerWeapon)->m_WeaponType != WEAPONTYPE_SNIPER_RIFLE
        && CWeaponCSBase::GetCSWpnData(this: pAttackerWeapon)->m_WeaponType != WEAPONTYPE_KNIFE
        && attackerWeaponId != WEAPON_TASER
        && (CCSPlayer *)livePlayerCount == pAttacker )
      {
        CBaseMultiplayerPlayer::AwardAchievement(this: pAttacker, iAchievement: 5021, iCount: 1);
        CCSGameStats::IncrementStat(
          this: &CCS_GameStats,
          pPlayer: pAttacker,
          statId: CSSTAT_KILLS_WITH_LAST_ROUND,
          iDelta: 1,
          bPlayerOnly: false);
      }
      if ( pVictimWeapon != nullptr
        && CWeaponCSBase::GetCSWpnData(this: pVictimWeapon)->m_WeaponType == WEAPONTYPE_KNIFE
        && pVictimWeapon->GetCSWeaponID(this: pVictimWeapon) != WEAPON_TASER
        && (CCSPlayer *)livePlayerCount == pAttacker
        && pAttackerWeapon != nullptr
        && pAttackerWeapon->GetCSWeaponID(this: pAttackerWeapon) != WEAPON_KNIFE
        && CWeaponCSBase::GetCSWpnData(this: pAttackerWeapon)->m_WeaponType != WEAPONTYPE_C4
        && CWeaponCSBase::GetCSWpnData(this: pAttackerWeapon)->m_WeaponType != WEAPONTYPE_GRENADE )
      {
        pVictim->m_bWieldingKnifeAndKilledByGun = true;
      }
      if ( attackerWeaponId != WEAPON_NONE )
      {
        v40 = pAttacker->m_killWeapons.m_Size;
        v41 = 0;
        if ( v40 <= 0 )
          goto LABEL_112;
        v42 = pAttacker->m_killWeapons.m_Memory.m_pMemory;
        while ( *v42 != attackerWeaponId )
        {
          ++v41;
          ++v42;
          if ( v41 >= v40 )
            goto LABEL_112;
        }
        if ( v41 == -1 )
        {
LABEL_112:
          v43 = pAttacker->m_killWeapons.m_Memory.m_nAllocationCount;
          v44 = pAttacker->m_killWeapons.m_Size;
          if ( v40 + 1 > v43 )
            CUtlMemory<CNavLadder *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&pAttacker->m_killWeapons,
              num: v40 - v43 + 1);
          ++pAttacker->m_killWeapons.m_Size;
          v45 = pAttacker->m_killWeapons.m_Memory.m_pMemory;
          v46 = pAttacker->m_killWeapons.m_Size - v44 - 1;
          pAttacker->m_killWeapons.m_pElements = v45;
          if ( v46 > 0 )
            _V_memmove(dest: &v45[v44 + 1], src: &v45[v44], count: 4 * v46);
          v47 = &pAttacker->m_killWeapons.m_Memory.m_pMemory[v44];
          if ( v47 != nullptr )
            *v47 = attackerWeaponId;
          if ( pAttacker->m_killWeapons.m_Size >= 5 )
            CBaseMultiplayerPlayer::AwardAchievement(this: pAttacker, iAchievement: 3007, iCount: 1);
        }
      }
      m_blindStartTime = pAttacker->m_blindStartTime;
      if ( (float)(pAttacker->m_flFlashDuration.m_Value + m_blindStartTime) > gpGlobals->curtime )
      {
        if ( m_blindStartTime != pAttacker->m_firstKillBlindStartTime )
        {
          pAttacker->m_killsWhileBlind = 0;
          pAttacker->m_firstKillBlindStartTime = m_blindStartTime;
        }
        if ( ++pAttacker->m_killsWhileBlind >= 1 )
          CBaseMultiplayerPlayer::AwardAchievement(this: pAttacker, iAchievement: 3021, iCount: 1);
        if ( pAttacker->m_killsWhileBlind >= 2 )
          CBaseMultiplayerPlayer::AwardAchievement(this: pAttacker, iAchievement: 3022, iCount: 1);
      }
      FOV = CBasePlayer::GetFOV(this: pVictim);
      i_3 = FOV != CBasePlayer::GetDefaultFOV(this: pVictim);
      v50 = CBasePlayer::GetFOV(this: pAttacker);
      attackerZoomed = v50 != CBasePlayer::GetDefaultFOV(this: pAttacker);
      v51 = pAttackerWeapon != nullptr
         && CWeaponCSBase::GetCSWpnData(this: pAttackerWeapon)->m_WeaponType == WEAPONTYPE_SNIPER_RIFLE
         && (CCSPlayer *)livePlayerCount == pAttacker;
      if ( i_3 && v51 )
        CBaseMultiplayerPlayer::AwardAchievement(this: pAttacker, iAchievement: 3028, iCount: 1);
      if ( attackerWeaponId == WEAPON_KNIFE && i_3 )
        CBaseMultiplayerPlayer::AwardAchievement(this: pAttacker, iAchievement: 3029, iCount: 1);
      if ( v51 && !attackerZoomed )
        CBaseMultiplayerPlayer::AwardAchievement(this: pAttacker, iAchievement: 3030, iCount: 1);
      if ( pAttacker->IsAlive(this: pAttacker) && pAttacker->m_iHealth.m_Value <= 1 )
        CBaseMultiplayerPlayer::AwardAchievement(this: pAttacker, iAchievement: 3032, iCount: 1);
      if ( pAttacker->IsAlive(this: pAttacker) && pAttacker->m_iHealth.m_Value <= 25 )
        ++pAttacker->m_iMediumHealthKills;
      if ( (unsigned __int8)CCSGameRules::IsPistolRound(this: (CCSGameRules *)g_pGameRules) != 0
        && CCSGameRules::IsPlayingClassic(this: (CCSGameRules *)g_pGameRules)
        && attackerWeaponId == WEAPON_KNIFE )
      {
        CBaseMultiplayerPlayer::AwardAchievement(this: pAttacker, iAchievement: 3033, iCount: 1);
      }
      v52 = CBaseCombatCharacter::GetActiveWeapon(this: pVictim);
      v53 = __RTDynamicCast(
              inptr: v52,
              VfDelta: 0,
              SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
              TargetType: &CWeaponCSBase `RTTI Type Descriptor',
              isReference: 0);
      if ( v53 != nullptr )
      {
        v54 = (*(int (__thiscall **)(void *))(*(_DWORD *)v53 + 1520))(a1: v53);
        if ( attackerWeaponId == WEAPON_ELITE && v54 == 2 )
          CBaseMultiplayerPlayer::AwardAchievement(this: pAttacker, iAchievement: 3034, iCount: 1);
      }
      if ( pAttacker->m_MoveType.m_Value == 9
        || (i_3a = 1,
            CCSPlayer::GetNearestSurfaceBelow(
              this: pAttacker,
              a2: COERCE_FLOAT(&savedregs),
              a3: (int)pAttacker,
              maxTrace: 100.0) != nullptr) )
      {
        i_3a = 0;
      }
      v55 = pVictim->m_MoveType.m_Value != 9
         && CCSPlayer::GetNearestSurfaceBelow(
              this: pVictim,
              a2: COERCE_FLOAT(&savedregs),
              a3: (int)pAttacker,
              maxTrace: 100.0) == nullptr;
      if ( i_3a != 0 )
        CBaseMultiplayerPlayer::AwardAchievement(this: pAttacker, iAchievement: 3036, iCount: 1);
      if ( v55 )
        CBaseMultiplayerPlayer::AwardAchievement(this: pAttacker, iAchievement: 3037, iCount: 1);
      if ( i_3a != 0 && v55 )
        CBaseMultiplayerPlayer::AwardAchievement(this: pAttacker, iAchievement: 3038, iCount: 1);
      if ( pAttacker->m_defuseDefenseStep == DD_STARTED_DEFUSE )
        pAttacker->m_defuseDefenseStep = DD_KILLED_TERRORIST;
      if ( pVictim->Weapon_OwnsThisType(this: pVictim, a2: "weapon_c4", a3: 0) != nullptr
        && (float)(pVictim->m_bombPickupTime + 3.0) > gpGlobals->curtime )
      {
        CBaseMultiplayerPlayer::AwardAchievement(this: pAttacker, iAchievement: 1007, iCount: 1);
      }
      if ( CCSGameRules::IsPlayingGunGameProgressive(this: (CCSGameRules *)g_pGameRules)
        && LOBYTE(g_pGameRules[138].m_pNext) != 0
        && BYTE1(g_pGameRules[138].m_pNext) != 0 )
      {
        CBaseMultiplayerPlayer::AwardAchievement(this: pAttacker, iAchievement: 6034, iCount: 1);
      }
      if ( pVictim->Weapon_OwnsThisType(this: pVictim, a2: "weapon_c4", a3: 0) != nullptr
        || pVictim->m_bombDroppedTime > 0.0 )
      {
        ++pAttacker->m_bombCarrierkills;
      }
    }
    v56 = CBaseEntity::GetTeamNumber(this: pAttacker);
    if ( CBaseEntity::GetTeamNumber(this: pVictim) == v56 && pAttacker->m_blindUntilTime > gpGlobals->curtime )
    {
      v57 = pAttacker->m_lastFlashBangAttacker.m_Index;
      if ( v57 != -1 )
      {
        v58 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)v57];
        if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v57].m_SerialNumber == HIWORD(v57) )
        {
          v59 = (CBaseMultiplayerPlayer *)*v58;
          if ( *v58 != nullptr )
          {
            v60 = CBaseEntity::GetTeamNumber(this: *v58);
            if ( CBaseEntity::GetTeamNumber(this: pAttacker) != v60 )
              CBaseMultiplayerPlayer::AwardAchievement(this: v59, iAchievement: 5044, iCount: 1);
          }
        }
      }
    }
  }
  v61 = nullptr;
  memset(teamCount, 0, sizeof(teamCount));
  livePlayerCount = 0;
  memset(teamIgnoreCount, 0, sizeof(teamIgnoreCount));
  ic = 1;
  if ( gpGlobals->maxClients >= 1 )
  {
    do
    {
      v62 = UTIL_PlayerByIndex(playerIndex: ic);
      v63 = (CCSPlayer *)v62;
      if ( v62 != nullptr )
      {
        v64 = CBaseEntity::GetTeamNumber(this: v62);
        if ( v64 >= 0 )
        {
          ++teamCount[v64];
          if ( v63->m_wasNotKilledNaturally )
            ++teamIgnoreCount[v64];
        }
        if ( v63->IsAlive(this: v63) && v63 != pVictim )
        {
          ++teamAliveCount[v64];
          ++livePlayerCount;
          v61 = v63;
        }
      }
      ++ic;
    }
    while ( ic <= gpGlobals->maxClients );
    if ( v61 != nullptr )
    {
      v65 = CBaseEntity::GetTeamNumber(this: v61);
      if ( livePlayerCount == 1
        && g_pGameRules[130].m_pszName == nullptr
        && teamCount[v65] - teamIgnoreCount[v65] >= 5
        && teamCount[(v65 != 3) + 2] - teamIgnoreCount[(v65 != 3) + 2] >= 5
        && ((int)v61[1].m_pfnThink & 0x400) == 0 )
      {
        CBaseMultiplayerPlayer::AwardAchievement(this: v61, iAchievement: 5020, iCount: 1);
        if ( (unsigned __int8)CCSGameRules::IsPlayingGunGameSelect(this: (CCSGameRules *)g_pGameRules) != 0 )
          CBaseMultiplayerPlayer::AwardAchievement(this: v61, iAchievement: 6037, iCount: 1);
      }
    }
  }
  CCSGameStats::Event_PlayerKilled_PreWeaponDrop(this: &CCS_GameStats, pPlayer: pVictim, info);
}

//------------------------------------------------------------------------------
// Address: 0x1028CD80
// Name: public: void CCSPlayer::OnRoundEnd(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::OnRoundEnd(CCSPlayer *this, int winningTeam, int reason)
{
  int v4; // eax
  IGameEvent *v5; // edi
  int v6; // eax
  int v7; // edi
  edict_t *m_pPev; // ecx
  CTeam *GlobalTeam; // eax
  ConVar *m_pConVarState; // edi
  int v11; // ebx
  CBasePlayer *v12; // eax
  CBasePlayer *v13; // edi
  CGlobalVars *v14; // ebx
  unsigned int m_Index; // ecx
  int v16; // eax
  CEntInfo *v17; // edx
  unsigned int v18; // ecx
  int v19; // eax
  bool v20; // zf
  CBaseMultiplayerPlayer **v21; // eax
  CBaseMultiplayerPlayer *v22; // eax
  int losingTeamId; // [esp+8h] [ebp-10h]
  ConVarRef v24; // [esp+Ch] [ebp-Ch] BYREF
  int ignoreCount; // [esp+14h] [ebp-4h]

  if ( this->IsAlive(this) )
  {
    v4 = ++this->m_numRoundsSurvived;
    if ( v4 > this->m_maxNumRoundsSurvived )
      this->m_maxNumRoundsSurvived = v4;
  }
  if ( CCSGameRules::IsPlayingGunGameProgressive(this: (CCSGameRules *)g_pGameRules)
    || (unsigned __int8)CCSGameRules::IsPlayingGunGameSelect(this: (CCSGameRules *)g_pGameRules) != 0 )
  {
    v5 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "gg_reset_round_start_sounds", a3: 0, a4: 0);
    if ( v5 != nullptr )
    {
      v6 = engine->GetPlayerUserId(this: engine, a2: this->m_Network.m_pPev);
      v5->SetInt(this: v5, a2: "userid", a3: v6);
      gameeventmanager->FireEvent(this: gameeventmanager, a2: v5, a3: false);
    }
  }
  if ( winningTeam == 3 || winningTeam == 2 )
  {
    losingTeamId = (winningTeam != 3) + 2;
    if ( CCSGameRules::IsPlayingGunGameTRBomb(this: (CCSGameRules *)g_pGameRules) )
    {
      if ( winningTeam == CBaseEntity::GetTeamNumber(this) )
      {
        v7 = this->m_iNumGunGameTRKillPoints.m_Value + 1;
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x1318u);
        }
        this->m_iNumGunGameTRKillPoints.m_Value = v7;
        ++this->m_iNumGunGameTRBombTotalPoints;
      }
      ConVarRef::ConVarRef(this: &v24, pName: "mp_ggtr_bomb_pts_for_upgrade");
      if ( this->m_iNumGunGameTRKillPoints.m_Value == v24.m_pConVarState->m_Value.m_nValue )
        CCSPlayer::SendGunGameWeaponUpgradeAlert(this);
      if ( this->m_iNumGunGameTRKillPoints.m_Value > v24.m_pConVarState->m_Value.m_nValue - 1 )
        this->m_bShouldProgressGunGameTRBombModeWeapon = true;
    }
    GlobalTeam = GetGlobalTeam(iIndex: losingTeamId);
    m_pConVarState = nullptr;
    if ( GlobalTeam != nullptr )
    {
      v11 = 1;
      v24.m_pConVarState = (ConVar *)GlobalTeam->GetNumPlayers(this: GlobalTeam);
      for ( ignoreCount = 0; v11 <= gpGlobals->maxClients; ++v11 )
      {
        v12 = UTIL_PlayerByIndex(playerIndex: v11);
        v13 = v12;
        if ( v12 != nullptr
          && CBaseEntity::GetTeamNumber(this: v12) == losingTeamId
          && LOBYTE(v13[1].m_hMyWeapons.m_Value[18].m_Index) != 0 )
        {
          ++ignoreCount;
        }
      }
      v24.m_pConVarState = (ConVar *)((char *)v24.m_pConVarState - ignoreCount);
      m_pConVarState = v24.m_pConVarState;
    }
    if ( this->IsAlive(this) )
    {
      v14 = gpGlobals;
      if ( v14->curtime - CCSGameRules::GetRoundStartTime(this: (CCSGameRules *)g_pGameRules) < 30.0
        && CBaseEntity::GetTeamNumber(this) == winningTeam
        && (int)m_pConVarState >= 5 )
      {
        CBaseMultiplayerPlayer::AwardAchievement(this, iAchievement: 5037, iCount: 1);
      }
    }
    if ( this->IsAlive(this) && reason == 0 && this->m_gooseChaseStep == GC_STOPPED_AFTER_GETTING_SHOT )
    {
      m_Index = this->m_pGooseChaseDistractingPlayer.m_Index;
      if ( m_Index != -1 )
      {
        v16 = (unsigned __int16)m_Index;
        v17 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
        v18 = HIWORD(m_Index);
        if ( v17->m_SerialNumber == v18 && v17->m_pEntity != nullptr )
        {
          v19 = v16;
          v20 = g_pEntityList->m_EntPtrArray[v19].m_SerialNumber == v18;
          v21 = (CBaseMultiplayerPlayer **)&g_pEntityList->m_EntPtrArray[v19];
          if ( v20 )
            v22 = *v21;
          else
            v22 = nullptr;
          CBaseMultiplayerPlayer::AwardAchievement(this: v22, iAchievement: 1009, iCount: 1);
        }
      }
    }
    if ( this->IsAlive(this) && reason == 6 && this->m_defuseDefenseStep == DD_KILLED_TERRORIST )
      CBaseMultiplayerPlayer::AwardAchievement(this, iAchievement: 1011, iCount: 1);
    if ( this->m_NumEnemiesKilledThisRound > 0
      && CBaseEntity::GetTeamNumber(this) == winningTeam
      && !this->m_bMadeFootstepNoise )
    {
      CBaseMultiplayerPlayer::AwardAchievement(this, iAchievement: 5039, iCount: 1);
    }
    if ( CBaseEntity::GetTeamNumber(this) != winningTeam || this->m_bMadePurchseThisRound )
    {
      this->m_lastRoundResult = reason;
      this->m_roundsWonWithoutPurchase = 0;
    }
    else
    {
      if ( ++this->m_roundsWonWithoutPurchase > 10 )
        CBaseMultiplayerPlayer::AwardAchievement(this, iAchievement: 5042, iCount: 1);
      this->m_lastRoundResult = reason;
    }
  }
  else
  {
    this->m_lastRoundResult = reason;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028D0F0
// Name: public: void CUtlDict<float,int>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<float,int>::RemoveAll(CUtlDict<float,int> *this)
{
  int i; // esi

  for ( i = CUtlRBTree<CUtlMap<char const *,float,int>::Node_t,int,CUtlMap<char const *,float,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,float,int>::Node_t,int>,int>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != -1;
        i = CUtlRBTree<CUtlMap<char const *,float,int>::Node_t,int,CUtlMap<char const *,float,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,float,int>::Node_t,int>,int>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,float,int>::Node_t,int,CUtlMap<char const *,float,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,float,int>::Node_t,int>,int>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x1028D140
// Name: public: virtual void CCSPlayer::Event_KilledOther(class CBaseEntity __near *,class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::Event_KilledOther(CCSPlayer *this, CBasePlayer *pVictim, const CTakeDamageInfo *info)
{
  unsigned int m_Index; // ecx
  CEntInfo *v5; // eax
  IHandleEntity *m_pEntity; // ebx
  CCSPlayer *v7; // ebx
  int TeamNumber; // edi
  IGameEvent *v9; // edi
  const char **p_m_pszDefaultValue; // ecx
  int v11; // eax
  IPlayerInfo *v12; // ecx
  IGameEvent_vtbl *v13; // ebx
  int v14; // eax
  float m_fMinVal; // eax
  int v16; // ebx
  edict_t *m_pPev; // ecx
  CCSGameRules *v18; // edi
  int v19; // eax
  CCSGameRules *v20; // edi
  int v21; // eax
  CCSGameRules *v22; // edi
  int v23; // eax
  bool IsFinalGunGameProgressiveWeapon; // al
  CCSGameRules *v25; // edi
  int v26; // eax
  int v27; // eax
  CCSGameRules *v28; // edi
  int v29; // eax
  IGameEvent *v30; // esi
  CBasePlayer *Attacker; // eax
  IPlayerInfo *PlayerInfo; // eax
  IGameEvent v33; // edi
  int v34; // eax
  ConVarRef v35; // [esp+Ch] [ebp-8h] BYREF
  CBaseEntity *pVictima; // [esp+1Ch] [ebp+8h]

  CBasePlayer::Event_KilledOther(this, pVictim, info);
  if ( pVictim != nullptr && pVictim->IsPlayer(this: pVictim) )
    v35.m_pConVarState = (ConVar *)__RTDynamicCast(
                                     inptr: pVictim,
                                     VfDelta: 0,
                                     SrcType: &CBaseEntity `RTTI Type Descriptor',
                                     TargetType: &CCSPlayer `RTTI Type Descriptor',
                                     isReference: 0);
  else
    v35.m_pConVarState = nullptr;
  m_Index = info->m_hAttacker.m_Index;
  if ( m_Index != -1
    && (v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
    && (m_pEntity = v5->m_pEntity, v5->m_pEntity != nullptr)
    && ((unsigned __int8 (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[28].dtr_IHandleEntity)(a1: m_pEntity) != 0 )
  {
    v7 = (CCSPlayer *)__RTDynamicCast(
                        inptr: m_pEntity,
                        VfDelta: 0,
                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                        TargetType: &CCSPlayer `RTTI Type Descriptor',
                        isReference: 0);
  }
  else
  {
    v7 = nullptr;
  }
  TeamNumber = CBaseEntity::GetTeamNumber(this: pVictim);
  if ( CBaseEntity::GetTeamNumber(this) != TeamNumber || pVictim == v7 )
  {
    if ( v7 != nullptr
      && v35.m_pConVarState != nullptr
      && (CBaseEntity::GetTeamNumber(this: pVictim) == 3 || CBaseEntity::GetTeamNumber(this: pVictim) == 2) )
    {
      if ( CCSPlayer::IsObjectiveKill(this: v7, pCSVictim: (CCSPlayer *)v35.m_pConVarState) )
        CCSGameRules::ScorePlayerObjectiveKill(this: (CCSGameRules *)g_pGameRules, pPlayer: v7);
      else
        CCSGameRules::ScorePlayerKill(this: (CCSGameRules *)g_pGameRules, pPlayer: v7);
      CCSPlayer::CheckAndAwardAssists(this, pCSVictim: (CCSPlayer *)v35.m_pConVarState);
    }
    if ( CCSGameRules::IsPlayingGunGame(this: (CCSGameRules *)g_pGameRules)
      && v35.m_pConVarState != nullptr
      && v7 != nullptr )
    {
      ++this->m_iNumGunGameKillsWithCurrentWeapon;
      v9 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "gg_killed_enemy", a3: 0, a4: 0);
      if ( v9 != nullptr )
      {
        if ( v35.m_pConVarState == (ConVar *)-4164 )
          p_m_pszDefaultValue = nullptr;
        else
          p_m_pszDefaultValue = &v35.m_pConVarState[47].m_pszDefaultValue;
        pVictima = (CBaseEntity *)v9->__vftable;
        v11 = (*((int (__thiscall **)(const char **))*p_m_pszDefaultValue + 1))(a1: p_m_pszDefaultValue);
        ((void (__thiscall *)(IGameEvent *, const char *, int))LODWORD(pVictima->m_Network.m_PVSInfo.m_vCenter[1]))(
          a1: v9,
          a2: "victimid",
          a3: v11);
        if ( v7 == (CCSPlayer *)-4164 )
          v12 = nullptr;
        else
          v12 = &v7->m_PlayerInfo.IPlayerInfo;
        v13 = v9->__vftable;
        v14 = v12->GetUserID(this: v12);
        v13->SetInt(this: v9, a2: "attackerid", a3: v14);
        m_fMinVal = v35.m_pConVarState[79].m_fMinVal;
        if ( (LOBYTE(m_fMinVal) & 1) != 0 )
        {
          v9->SetInt(this: v9, a2: "dominated", a3: 1);
        }
        else if ( (LOBYTE(m_fMinVal) & 2) != 0 )
        {
          v9->SetInt(this: v9, a2: "revenge", a3: 1);
        }
        gameeventmanager->FireEvent(this: gameeventmanager, a2: v9, a3: false);
      }
      if ( CCSGameRules::IsPlayingGunGameTRBomb(this: (CCSGameRules *)g_pGameRules) )
      {
        v16 = this->m_iNumGunGameTRKillPoints.m_Value + 1;
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x1318u);
        }
        this->m_iNumGunGameTRKillPoints.m_Value = v16;
        ++this->m_iNumGunGameTRBombTotalPoints;
        ConVarRef::ConVarRef(this: &v35, pName: "mp_ggtr_bomb_pts_for_upgrade");
        if ( this->m_iNumGunGameTRKillPoints.m_Value == v35.m_pConVarState->m_Value.m_nValue )
          CCSPlayer::SendGunGameWeaponUpgradeAlert(this);
      }
      if ( CCSGameRules::IsPlayingGunGameTRBomb(this: (CCSGameRules *)g_pGameRules) )
      {
        v18 = (CCSGameRules *)g_pGameRules;
        v19 = CBaseEntity::GetTeamNumber(this);
        if ( CCSGameRules::IsFinalGunGameProgressiveWeapon(
               this: v18,
               nCurrentWeaponIndex: this->m_iGunGameProgressiveWeaponIndex.m_Value,
               nTeamID: v19) )
        {
          v20 = (CCSGameRules *)g_pGameRules;
          v21 = CBaseEntity::GetTeamNumber(this);
          if ( this->m_iNumGunGameKillsWithCurrentWeapon == CCSGameRules::GetGunGameNumKillsRequiredForWeapon(
                                                              this: v20,
                                                              nCurrentWeaponIndex: this->m_iGunGameProgressiveWeaponIndex.m_Value,
                                                              nTeamID: v21) )
            this->m_bMadeFinalGunGameProgressiveKill = true;
        }
      }
      if ( CCSGameRules::IsPlayingGunGameProgressive(this: (CCSGameRules *)g_pGameRules) )
      {
        v22 = (CCSGameRules *)g_pGameRules;
        v23 = CBaseEntity::GetTeamNumber(this);
        IsFinalGunGameProgressiveWeapon = CCSGameRules::IsFinalGunGameProgressiveWeapon(
                                            this: v22,
                                            nCurrentWeaponIndex: this->m_iGunGameProgressiveWeaponIndex.m_Value,
                                            nTeamID: v23);
        v25 = (CCSGameRules *)g_pGameRules;
        if ( IsFinalGunGameProgressiveWeapon )
        {
          v26 = CBaseEntity::GetTeamNumber(this);
          if ( this->m_iNumGunGameKillsWithCurrentWeapon == CCSGameRules::GetGunGameNumKillsRequiredForWeapon(
                                                              this: v25,
                                                              nCurrentWeaponIndex: this->m_iGunGameProgressiveWeaponIndex.m_Value,
                                                              nTeamID: v26) )
            this->m_bMadeFinalGunGameProgressiveKill = true;
        }
        else
        {
          v27 = CBaseEntity::GetTeamNumber(this);
          if ( this->m_iNumGunGameKillsWithCurrentWeapon == CCSGameRules::GetGunGameNumKillsRequiredForWeapon(
                                                              this: v25,
                                                              nCurrentWeaponIndex: this->m_iGunGameProgressiveWeaponIndex.m_Value,
                                                              nTeamID: v27) )
          {
            this->m_iNumGunGameKillsWithCurrentWeapon = 0;
            CCSPlayer::GiveNextProgressiveGunGameWeapon(this);
            v28 = (CCSGameRules *)g_pGameRules;
            v29 = CBaseEntity::GetTeamNumber(this);
            if ( CCSGameRules::IsFinalGunGameProgressiveWeapon(
                   this: v28,
                   nCurrentWeaponIndex: this->m_iGunGameProgressiveWeaponIndex.m_Value,
                   nTeamID: v29) )
            {
              v30 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "gg_final_weapon_achieved", a3: 0, a4: 0);
              ConVarRef::ConVarRef(this: &v35, pName: "sf_ui_tint");
              v35.m_pConVar->SetValue_2(this: v35.m_pConVar, a2: 4);
              if ( v30 != nullptr )
              {
                Attacker = (CBasePlayer *)CTakeDamageInfo::GetAttacker(this: info);
                PlayerInfo = CBasePlayer::GetPlayerInfo(this: Attacker);
                v33.__vftable = v30->__vftable;
                v34 = PlayerInfo->GetUserID(this: PlayerInfo);
                v33.SetInt(this: v30, a2: "playerid", a3: v34);
                gameeventmanager->FireEvent(this: gameeventmanager, a2: v30, a3: false);
              }
            }
          }
        }
      }
    }
  }
  else
  {
    CCSGameRules::ScorePlayerTeamKill(this: (CCSGameRules *)g_pGameRules, pPlayer: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028D540
// Name: public: void CCSPlayer::IncrementGunGameProgressiveWeapon(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::IncrementGunGameProgressiveWeapon(CCSPlayer *this, int nNumLevelsToIncrease)
{
  int v3; // esi
  int TeamNumber; // eax
  CCSGameRules *v5; // esi
  int v6; // eax
  edict_t *m_pPev; // ecx
  CCSGameRules *nNumLevelsToIncreasea; // [esp+14h] [ebp+8h]

  v3 = nNumLevelsToIncrease + this->m_iGunGameProgressiveWeaponIndex.m_Value - 1;
  nNumLevelsToIncreasea = (CCSGameRules *)g_pGameRules;
  TeamNumber = CBaseEntity::GetTeamNumber(this);
  if ( v3 >= CCSGameRules::GetNumProgressiveGunGameWeapons(this: nNumLevelsToIncreasea, nTeamID: TeamNumber) - 1 )
  {
    v5 = (CCSGameRules *)g_pGameRules;
    v6 = CBaseEntity::GetTeamNumber(this);
    v3 = CCSGameRules::GetNumProgressiveGunGameWeapons(this: v5, nTeamID: v6) - 2;
  }
  if ( this->m_iGunGameProgressiveWeaponIndex.m_Value <= v3 )
  {
    if ( this->m_iGunGameProgressiveWeaponIndex.m_Value != v3 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_iGunGameProgressiveWeaponIndex.m_Value = v3;
        CCSPlayer::GiveNextProgressiveGunGameWeapon(this);
        return;
      }
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x1314u);
      this->m_iGunGameProgressiveWeaponIndex.m_Value = v3;
    }
    CCSPlayer::GiveNextProgressiveGunGameWeapon(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028D5E0
// Name: public: enum BuyResult_e CCSPlayer::HandleCommand_Buy(char const __near *)
// Source: json
//------------------------------------------------------------------------------
BuyResult_e __thiscall CCSPlayer::HandleCommand_Buy(CCSPlayer *this, const char *item)
{
  BuyResult_e result; // eax

  result = CCSPlayer::HandleCommand_Buy_Internal(this, wpnName: item);
  if ( result == BUY_BOUGHT )
  {
    this->m_bMadePurchseThisRound = true;
    CCSGameStats::IncrementStat(
      this: &CCS_GameStats,
      pPlayer: this,
      statId: CSSTAT_ITEMS_PURCHASED,
      iDelta: 1,
      bPlayerOnly: false);
    return BUY_BOUGHT;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1028D620
// Name: private: void CCSPlayer::State_Enter(enum CSPlayerState)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::State_Enter(CCSPlayer *this, CSPlayerState newState)
{
  edict_t *m_pPev; // ecx
  CCSPlayerStateInfo *v4; // eax
  int m_nValue; // edx
  edict_t *v6; // ecx
  CCSPlayerStateInfo *m_pCurStateInfo; // eax
  void (__thiscall *pfnEnterState)(char *); // edx

  if ( this->m_iPlayerState.m_Value != newState )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x12D8u);
    }
    this->m_iPlayerState.m_Value = newState;
  }
  v4 = CCSPlayer::State_LookupInfo(state: newState);
  this->m_pCurStateInfo = v4;
  if ( cs_ShowStateTransitions.m_pParent != nullptr )
  {
    if ( cs_ShowStateTransitions.m_pParent->m_Value.m_nValue == -1 )
    {
LABEL_14:
      if ( v4 != nullptr )
        _Msg(a1: "ShowStateTransitions: entering '%s'\n", v4->m_pStateName);
      else
        _Msg(a1: "ShowStateTransitions: entering #%d\n", newState);
      goto LABEL_17;
    }
    m_nValue = cs_ShowStateTransitions.m_pParent->m_Value.m_nValue;
  }
  else
  {
    m_nValue = 0;
  }
  v6 = this->m_Network.m_pPev;
  if ( v6 != nullptr )
    v6 -= (int)gpGlobals->pEdicts;
  if ( (edict_t *)m_nValue == v6 )
    goto LABEL_14;
LABEL_17:
  m_pCurStateInfo = this->m_pCurStateInfo;
  if ( m_pCurStateInfo != nullptr )
  {
    pfnEnterState = (void (__thiscall *)(char *))m_pCurStateInfo->pfnEnterState;
    if ( pfnEnterState != nullptr )
      pfnEnterState(a1: (char *)this + DWORD1(m_pCurStateInfo->pfnEnterState));
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028D6E0
// Name: private: void CCSPlayer::ParseAutoBuyString(char const __near *,bool __near &,bool __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::ParseAutoBuyString(
        CCSPlayer *this,
        const char *string,
        bool *boughtPrimary,
        bool *boughtSecondary)
{
  const char *v4; // edx
  bool v5; // zf
  char v6; // al
  int v7; // ecx
  int v8; // eax
  AutoBuyInfoStruct *v9; // esi
  const AutoBuyInfoStruct *v10; // ebx
  AutoBuyInfoStruct *v11; // edi
  int v12; // eax
  CCSPlayer *v13; // edi
  BuyResult_e v14; // esi
  BuyResult_e v15; // eax
  const char *m_command; // [esp-14h] [ebp-40h]
  char command[36]; // [esp+0h] [ebp-2Ch] BYREF
  BuyResult_e overallResult; // [esp+24h] [ebp-8h]
  CCSPlayer *pPlayer; // [esp+28h] [ebp-4h]

  v4 = string;
  pPlayer = this;
  if ( string == nullptr || (v5 = *string == 0, overallResult = BUY_ALREADY_HAVE, v5) )
  {
LABEL_46:
    CCSPlayer::EmitPrivateSound(this, soundName: "BuyPreset.AlreadyBought");
    return;
  }
  do
  {
    v6 = *v4;
    v7 = 0;
    if ( *v4 != 0 )
    {
      while ( v6 != 32 )
      {
        if ( v7 < 31 )
        {
          ++v4;
          command[v7] = v6;
          v6 = *v4;
          ++v7;
          if ( *v4 != 0 )
            continue;
        }
        string = v4;
        goto LABEL_8;
      }
    }
    else
    {
LABEL_8:
      if ( *v4 != 32 )
        goto LABEL_10;
    }
    string = ++v4;
LABEL_10:
    v8 = 0;
    command[v7] = 0;
    if ( command[0] != 0 )
    {
      while ( command[v8] != 32 )
      {
        if ( command[++v8] == 0 )
          goto LABEL_15;
      }
      command[v8] = 0;
    }
LABEL_15:
    if ( strlen(command) != 0 )
    {
      v9 = g_autoBuyInfo;
      v10 = nullptr;
      v11 = g_autoBuyInfo;
      while ( v9->m_class != 0 )
      {
        v9 = v11;
        m_command = v11->m_command;
        ++v11;
        v12 = _V_stricmp(s1: m_command, s2: command);
        v4 = string;
        if ( v12 == 0 )
          v10 = v9;
        if ( v10 != nullptr )
        {
          if ( (!*boughtPrimary || (v10->m_class & 1) == 0 || (v10->m_class & 4) != 0)
            && (!*boughtSecondary || (v10->m_class & 2) == 0 || (v10->m_class & 4) != 0)
            && ((v10->m_class & 8) == 0 || pPlayer->m_ArmorValue.m_Value < 100) )
          {
            v13 = pPlayer;
            v14 = CCSPlayer::HandleCommand_Buy_Internal(this: pPlayer, wpnName: command);
            if ( v14 == BUY_BOUGHT )
            {
              v13->m_bMadePurchseThisRound = true;
              CCSGameStats::IncrementStat(
                this: &CCS_GameStats,
                pPlayer: v13,
                statId: CSSTAT_ITEMS_PURCHASED,
                iDelta: 1,
                bPlayerOnly: false);
            }
            v15 = overallResult;
            if ( v14 != BUY_BOUGHT )
            {
              if ( overallResult != BUY_BOUGHT
                && (v14 == BUY_CANT_AFFORD || v14 == BUY_INVALID_ITEM || v14 == BUY_PLAYER_CANT_BUY) )
              {
                v15 = BUY_CANT_AFFORD;
              }
            }
            else
            {
              v15 = BUY_BOUGHT;
            }
            overallResult = v15;
            CCSPlayer::PostAutoBuyCommandProcessing(this: v13, commandInfo: v10, boughtPrimary, boughtSecondary);
            v4 = string;
          }
          break;
        }
      }
    }
  }
  while ( *v4 != 0 );
  switch ( overallResult )
  {
    case BUY_CANT_AFFORD:
      CCSPlayer::EmitPrivateSound(this: pPlayer, soundName: "BuyPreset.CantBuy");
      return;
    case BUY_ALREADY_HAVE:
      this = pPlayer;
      goto LABEL_46;
    case BUY_BOUGHT:
      ++g_iAutoBuyPurchases;
      break;
    default:
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028D8A0
// Name: private: enum BuyResult_e CCSPlayer::RebuyPrimaryWeapon(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSPlayer::RebuyPrimaryWeapon(CCSPlayer *this)
{
  BuyResult_e v3; // edi

  if ( this->Weapon_GetSlot(this, a2: 0) != nullptr )
    return 1;
  if ( strlen(this->m_rebuyStruct.m_szPrimaryWeapon) == 0 )
    return 1;
  v3 = CCSPlayer::HandleCommand_Buy_Internal(this, wpnName: this->m_rebuyStruct.m_szPrimaryWeapon);
  if ( v3 == BUY_BOUGHT )
  {
    this->m_bMadePurchseThisRound = true;
    CCSGameStats::IncrementStat(
      this: &CCS_GameStats,
      pPlayer: this,
      statId: CSSTAT_ITEMS_PURCHASED,
      iDelta: 1,
      bPlayerOnly: false);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1028D920
// Name: private: enum BuyResult_e CCSPlayer::RebuySecondaryWeapon(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSPlayer::RebuySecondaryWeapon(CCSPlayer *this)
{
  BuyResult_e v3; // edi

  if ( this->Weapon_GetSlot(this, a2: 1) != nullptr && !this->m_bUsingDefaultPistol )
    return 1;
  if ( strlen(this->m_rebuyStruct.m_szSecondaryWeapon) == 0 )
    return 1;
  v3 = CCSPlayer::HandleCommand_Buy_Internal(this, wpnName: this->m_rebuyStruct.m_szSecondaryWeapon);
  if ( v3 == BUY_BOUGHT )
  {
    this->m_bMadePurchseThisRound = true;
    CCSGameStats::IncrementStat(
      this: &CCS_GameStats,
      pPlayer: this,
      statId: CSSTAT_ITEMS_PURCHASED,
      iDelta: 1,
      bPlayerOnly: false);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1028D9A0
// Name: private: enum BuyResult_e CCSPlayer::RebuyPrimaryAmmo(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSPlayer::RebuyPrimaryAmmo(CCSPlayer *this)
{
  CBaseCombatWeapon *v2; // eax
  int v3; // eax
  BuyResult_e v4; // edi

  v2 = this->Weapon_GetSlot(this, a2: 0);
  if ( v2 == nullptr )
    return 1;
  v3 = v2->GetPrimaryAmmoType(this: v2);
  if ( v3 == -1 || this->m_rebuyStruct.m_primaryAmmo <= CBaseCombatCharacter::GetAmmoCount(this, iAmmoIndex: v3) )
    return 1;
  v4 = CCSPlayer::HandleCommand_Buy_Internal(this, wpnName: "primammo");
  if ( v4 == BUY_BOUGHT )
  {
    this->m_bMadePurchseThisRound = true;
    CCSGameStats::IncrementStat(
      this: &CCS_GameStats,
      pPlayer: this,
      statId: CSSTAT_ITEMS_PURCHASED,
      iDelta: 1,
      bPlayerOnly: false);
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1028DA10
// Name: private: enum BuyResult_e CCSPlayer::RebuySecondaryAmmo(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSPlayer::RebuySecondaryAmmo(CCSPlayer *this)
{
  CBaseCombatWeapon *v2; // eax
  int v3; // eax
  BuyResult_e v4; // edi

  v2 = this->Weapon_GetSlot(this, a2: 1);
  if ( v2 == nullptr )
    return 1;
  v3 = v2->GetPrimaryAmmoType(this: v2);
  if ( v3 == -1 || this->m_rebuyStruct.m_secondaryAmmo <= CBaseCombatCharacter::GetAmmoCount(this, iAmmoIndex: v3) )
    return 1;
  v4 = CCSPlayer::HandleCommand_Buy_Internal(this, wpnName: "secammo");
  if ( v4 == BUY_BOUGHT )
  {
    this->m_bMadePurchseThisRound = true;
    CCSGameStats::IncrementStat(
      this: &CCS_GameStats,
      pPlayer: this,
      statId: CSSTAT_ITEMS_PURCHASED,
      iDelta: 1,
      bPlayerOnly: false);
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1028DA80
// Name: private: enum BuyResult_e CCSPlayer::RebuyHEGrenade(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSPlayer::RebuyHEGrenade(CCSPlayer *this)
{
  CBaseCombatWeapon *v2; // ecx
  int AmmoCount; // eax
  int v4; // eax
  int v6; // ebx
  int v7; // eax
  BuyResult_e v8; // esi
  int v9; // eax
  bool v10; // zf
  int v11; // [esp+4h] [ebp-4h]

  v2 = this->Weapon_OwnsThisType(this, a2: "weapon_hegrenade", a3: 0);
  AmmoCount = 0;
  if ( v2 != nullptr )
  {
    v4 = v2->GetPrimaryAmmoType(this: v2);
    if ( v4 == -1 )
      return 1;
    AmmoCount = CBaseCombatCharacter::GetAmmoCount(this, iAmmoIndex: v4);
  }
  v6 = 1;
  v7 = (this->m_rebuyStruct.m_heGrenade - AmmoCount) & ((this->m_rebuyStruct.m_heGrenade - AmmoCount < 0) - 1);
  if ( v7 > 0 )
  {
    v11 = v7;
    do
    {
      v8 = CCSPlayer::HandleCommand_Buy_Internal(this, wpnName: "hegrenade");
      if ( v8 == BUY_BOUGHT )
      {
        this->m_bMadePurchseThisRound = true;
        CCSGameStats::IncrementStat(
          this: &CCS_GameStats,
          pPlayer: this,
          statId: CSSTAT_ITEMS_PURCHASED,
          iDelta: 1,
          bPlayerOnly: false);
      }
      v9 = v6;
      if ( v8 != BUY_BOUGHT )
      {
        if ( v6 != 0 && (v8 == BUY_CANT_AFFORD || v8 == BUY_INVALID_ITEM || v8 == BUY_PLAYER_CANT_BUY) )
          v9 = 2;
      }
      else
      {
        v9 = 0;
      }
      v10 = v11-- == 1;
      v6 = v9;
    }
    while ( !v10 );
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1028DB40
// Name: private: enum BuyResult_e CCSPlayer::RebuyFlashbang(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSPlayer::RebuyFlashbang(CCSPlayer *this)
{
  CBaseCombatWeapon *v2; // ecx
  int AmmoCount; // eax
  int v4; // eax
  int v6; // ebx
  int v7; // eax
  BuyResult_e v8; // esi
  int v9; // eax
  bool v10; // zf
  int v11; // [esp+4h] [ebp-4h]

  v2 = this->Weapon_OwnsThisType(this, a2: "weapon_flashbang", a3: 0);
  AmmoCount = 0;
  if ( v2 != nullptr )
  {
    v4 = v2->GetPrimaryAmmoType(this: v2);
    if ( v4 == -1 )
      return 1;
    AmmoCount = CBaseCombatCharacter::GetAmmoCount(this, iAmmoIndex: v4);
  }
  v6 = 1;
  v7 = (this->m_rebuyStruct.m_flashbang - AmmoCount) & ((this->m_rebuyStruct.m_flashbang - AmmoCount < 0) - 1);
  if ( v7 > 0 )
  {
    v11 = v7;
    do
    {
      v8 = CCSPlayer::HandleCommand_Buy_Internal(this, wpnName: "flashbang");
      if ( v8 == BUY_BOUGHT )
      {
        this->m_bMadePurchseThisRound = true;
        CCSGameStats::IncrementStat(
          this: &CCS_GameStats,
          pPlayer: this,
          statId: CSSTAT_ITEMS_PURCHASED,
          iDelta: 1,
          bPlayerOnly: false);
      }
      v9 = v6;
      if ( v8 != BUY_BOUGHT )
      {
        if ( v6 != 0 && (v8 == BUY_CANT_AFFORD || v8 == BUY_INVALID_ITEM || v8 == BUY_PLAYER_CANT_BUY) )
          v9 = 2;
      }
      else
      {
        v9 = 0;
      }
      v10 = v11-- == 1;
      v6 = v9;
    }
    while ( !v10 );
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1028DC00
// Name: private: enum BuyResult_e CCSPlayer::RebuySmokeGrenade(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSPlayer::RebuySmokeGrenade(CCSPlayer *this)
{
  CBaseCombatWeapon *v2; // ecx
  int AmmoCount; // eax
  int v4; // eax
  int v6; // ebx
  int v7; // eax
  BuyResult_e v8; // esi
  int v9; // eax
  bool v10; // zf
  int v11; // [esp+4h] [ebp-4h]

  v2 = this->Weapon_OwnsThisType(this, a2: "weapon_smokegrenade", a3: 0);
  AmmoCount = 0;
  if ( v2 != nullptr )
  {
    v4 = v2->GetPrimaryAmmoType(this: v2);
    if ( v4 == -1 )
      return 1;
    AmmoCount = CBaseCombatCharacter::GetAmmoCount(this, iAmmoIndex: v4);
  }
  v6 = 1;
  v7 = (this->m_rebuyStruct.m_smokeGrenade - AmmoCount) & ((this->m_rebuyStruct.m_smokeGrenade - AmmoCount < 0) - 1);
  if ( v7 > 0 )
  {
    v11 = v7;
    do
    {
      v8 = CCSPlayer::HandleCommand_Buy_Internal(this, wpnName: "smokegrenade");
      if ( v8 == BUY_BOUGHT )
      {
        this->m_bMadePurchseThisRound = true;
        CCSGameStats::IncrementStat(
          this: &CCS_GameStats,
          pPlayer: this,
          statId: CSSTAT_ITEMS_PURCHASED,
          iDelta: 1,
          bPlayerOnly: false);
      }
      v9 = v6;
      if ( v8 != BUY_BOUGHT )
      {
        if ( v6 != 0 && (v8 == BUY_CANT_AFFORD || v8 == BUY_INVALID_ITEM || v8 == BUY_PLAYER_CANT_BUY) )
          v9 = 2;
      }
      else
      {
        v9 = 0;
      }
      v10 = v11-- == 1;
      v6 = v9;
    }
    while ( !v10 );
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1028DCC0
// Name: private: enum BuyResult_e CCSPlayer::RebuyDefuser(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSPlayer::RebuyDefuser(CCSPlayer *this)
{
  BuyResult_e v2; // edi

  if ( this->m_bHasDefuser.m_Value || !this->m_rebuyStruct.m_defuser )
    return 1;
  v2 = CCSPlayer::HandleCommand_Buy_Internal(this, wpnName: "defuser");
  if ( v2 == BUY_BOUGHT )
  {
    this->m_bMadePurchseThisRound = true;
    CCSGameStats::IncrementStat(
      this: &CCS_GameStats,
      pPlayer: this,
      statId: CSSTAT_ITEMS_PURCHASED,
      iDelta: 1,
      bPlayerOnly: false);
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1028DD10
// Name: private: enum BuyResult_e CCSPlayer::RebuyNightVision(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSPlayer::RebuyNightVision(CCSPlayer *this)
{
  BuyResult_e v2; // edi

  if ( this->m_bHasNightVision.m_Value || !this->m_rebuyStruct.m_nightVision )
    return 1;
  v2 = CCSPlayer::HandleCommand_Buy_Internal(this, wpnName: "nvgs");
  if ( v2 == BUY_BOUGHT )
  {
    this->m_bMadePurchseThisRound = true;
    CCSGameStats::IncrementStat(
      this: &CCS_GameStats,
      pPlayer: this,
      statId: CSSTAT_ITEMS_PURCHASED,
      iDelta: 1,
      bPlayerOnly: false);
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1028DD60
// Name: private: enum BuyResult_e CCSPlayer::RebuyArmor(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSPlayer::RebuyArmor(CCSPlayer *this)
{
  int m_armor; // eax
  int v3; // ecx
  BuyResult_e v4; // eax
  BuyResult_e v5; // edi

  m_armor = this->m_rebuyStruct.m_armor;
  if ( m_armor <= 0 )
    return 1;
  v3 = this->m_bHasHelmet.m_Value ? 2 : this->m_ArmorValue.m_Value > 0;
  if ( v3 >= m_armor )
    return 1;
  if ( m_armor == 1 )
    v4 = CCSPlayer::HandleCommand_Buy_Internal(this, wpnName: "vest");
  else
    v4 = CCSPlayer::HandleCommand_Buy_Internal(this, wpnName: "vesthelm");
  v5 = v4;
  if ( v4 == BUY_BOUGHT )
  {
    this->m_bMadePurchseThisRound = true;
    CCSGameStats::IncrementStat(
      this: &CCS_GameStats,
      pPlayer: this,
      statId: CSSTAT_ITEMS_PURCHASED,
      iDelta: 1,
      bPlayerOnly: false);
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1028DE60
// Name: public: virtual void CCSPlayer::InitialSpawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::InitialSpawn(CCSPlayer *this)
{
  int StartMoney; // ebx
  edict_t *m_pPev; // ecx

  CBasePlayer::InitialSpawn(this);
  if ( this->IsBot(this) )
  {
    StartMoney = CCSGameRules::GetStartMoney(this: (CCSGameRules *)g_pGameRules);
    if ( this->m_iAccount.m_Value != StartMoney )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x1900u);
      }
      this->m_iAccount.m_Value = StartMoney;
    }
  }
  if ( !engine->IsDedicatedServer(this: engine) && TheNavMesh->m_isOutOfDate && this == UTIL_GetListenServerHost() )
    ClientPrint(
      player: this,
      msg_dest: 4u,
      msg_name: "The Navigation Mesh was built using a different version of this map.",
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  CCSPlayer::State_Enter(this, newState: STATE_WELCOME);
  CCSGameStats::ResetPlayerStats(this: &CCS_GameStats, pPlayer: this);
  CCSPlayer::RemoveNemesisRelationships(this);
}

//------------------------------------------------------------------------------
// Address: 0x1028DF20
// Name: public: void CCSPlayer::State_Transition(enum CSPlayerState)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::State_Transition(CCSPlayer *this, CSPlayerState newState)
{
  CCSPlayerStateInfo *m_pCurStateInfo; // eax

  m_pCurStateInfo = this->m_pCurStateInfo;
  if ( m_pCurStateInfo != nullptr && LODWORD(m_pCurStateInfo->pfnLeaveState) != 0 )
    ((void (__thiscall *)(char *))LODWORD(m_pCurStateInfo->pfnLeaveState))(a1: (char *)this + DWORD1(m_pCurStateInfo->pfnLeaveState));
  CCSPlayer::State_Enter(this, newState);
}

//------------------------------------------------------------------------------
// Address: 0x1028DF50
// Name: public: void CCSPlayer::AutoBuy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::AutoBuy(CCSPlayer *this)
{
  edict_t *m_pPev; // eax
  const char *v3; // eax
  bool boughtPrimary; // [esp+6h] [ebp-2h] BYREF
  bool boughtSecondary; // [esp+7h] [ebp-1h] BYREF

  if ( this->m_bInBuyZone.m_Value && !this->m_isVIP )
  {
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      m_pPev -= (int)gpGlobals->pEdicts;
    v3 = engine->GetClientConVarValue(this: engine, a2: m_pPev, a3: "cl_autobuy");
    if ( v3 != nullptr && *v3 != 0 )
    {
      boughtPrimary = false;
      boughtSecondary = false;
      this->m_bIsInAutoBuy = true;
      CCSPlayer::ParseAutoBuyString(this, string: v3, &boughtPrimary, &boughtSecondary);
      *(_WORD *)&this->m_bIsInAutoBuy = 256;
    }
    else
    {
      CCSPlayer::EmitPrivateSound(this, soundName: "BuyPreset.AlreadyBought");
    }
  }
  else
  {
    CCSPlayer::EmitPrivateSound(this, soundName: "BuyPreset.CantBuy");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028DFF0
// Name: public: void CCSPlayer::Rebuy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::Rebuy(CCSPlayer *this)
{
  edict_t *m_pPev; // eax
  const char *v3; // eax
  int v4; // ebx
  int v5; // esi
  int v6; // eax
  int v7; // eax
  char token[256]; // [esp+4h] [ebp-104h] BYREF
  const char *rebuyString; // [esp+104h] [ebp-4h]

  if ( !this->m_bInBuyZone.m_Value || this->m_isVIP )
  {
    CCSPlayer::EmitPrivateSound(this, soundName: "BuyPreset.CantBuy");
    return;
  }
  m_pPev = this->m_Network.m_pPev;
  if ( m_pPev != nullptr )
    m_pPev -= (int)gpGlobals->pEdicts;
  v3 = engine->GetClientConVarValue(this: engine, a2: m_pPev, a3: "cl_rebuy");
  if ( v3 != nullptr && *v3 != 0 )
  {
    this->m_bIsInRebuy = true;
    v4 = 1;
    rebuyString = engine->ParseFile(this: engine, a2: v3, a3: token, a4: 256);
    if ( rebuyString != nullptr )
    {
      while ( 1 )
      {
        v5 = 1;
        if ( V_strncmp(s1: token, s2: "PrimaryWeapon", count: 14) == 0 )
          break;
        if ( V_strncmp(s1: token, s2: "PrimaryAmmo", count: 12) == 0 )
        {
          v6 = CCSPlayer::RebuyPrimaryAmmo(this);
          goto LABEL_29;
        }
        if ( V_strncmp(s1: token, s2: "SecondaryWeapon", count: 16) == 0 )
        {
          v6 = CCSPlayer::RebuySecondaryWeapon(this);
          goto LABEL_29;
        }
        if ( V_strncmp(s1: token, s2: "SecondaryAmmo", count: 14) == 0 )
        {
          v6 = CCSPlayer::RebuySecondaryAmmo(this);
          goto LABEL_29;
        }
        if ( V_strncmp(s1: token, s2: "HEGrenade", count: 10) == 0 )
        {
          v6 = CCSPlayer::RebuyHEGrenade(this);
          goto LABEL_29;
        }
        if ( V_strncmp(s1: token, s2: "Flashbang", count: 10) == 0 )
        {
          v6 = CCSPlayer::RebuyFlashbang(this);
          goto LABEL_29;
        }
        if ( V_strncmp(s1: token, s2: "SmokeGrenade", count: 13) == 0 )
        {
          v6 = CCSPlayer::RebuySmokeGrenade(this);
          goto LABEL_29;
        }
        if ( V_strncmp(s1: token, s2: "Defuser", count: 8) == 0 )
        {
          v6 = CCSPlayer::RebuyDefuser(this);
          goto LABEL_29;
        }
        if ( V_strncmp(s1: token, s2: "NightVision", count: 12) == 0 )
        {
          v6 = CCSPlayer::RebuyNightVision(this);
          goto LABEL_29;
        }
        if ( V_strncmp(s1: token, s2: "Armor", count: 6) == 0 )
        {
          v6 = CCSPlayer::RebuyArmor(this);
          goto LABEL_29;
        }
LABEL_30:
        v7 = v4;
        if ( v5 != 0 )
        {
          if ( v4 != 0 && (v5 == 2 || v5 == 5 || v5 == 3) )
            v7 = 2;
        }
        else
        {
          v7 = 0;
        }
        v4 = v7;
        rebuyString = engine->ParseFile(this: engine, a2: rebuyString, a3: token, a4: 256);
        if ( rebuyString == nullptr )
          goto LABEL_38;
      }
      v6 = CCSPlayer::RebuyPrimaryWeapon(this);
LABEL_29:
      v5 = v6;
      goto LABEL_30;
    }
LABEL_38:
    *(_WORD *)&this->m_bAutoReload = 1;
    if ( v4 == 2 )
    {
      CCSPlayer::EmitPrivateSound(this, soundName: "BuyPreset.CantBuy");
    }
    else if ( v4 == 1 )
    {
      CCSPlayer::EmitPrivateSound(this, soundName: "BuyPreset.AlreadyBought");
    }
    else
    {
      ++g_iReBuyPurchases;
    }
  }
  else
  {
    CCSPlayer::EmitPrivateSound(this, soundName: "BuyPreset.AlreadyBought");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028E2B0
// Name: public: virtual void CCSPlayer::ChangeTeam(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSPlayer::ChangeTeam(CCSPlayer *this@<ecx>, int a2@<edi>, CBaseEntity *iTeamNum)
{
  CBaseEntity *v3; // ebx
  int TeamNumber; // edi
  double RoundElapsedTime; // st7
  edict_t *m_pPev; // ecx
  CCSPlayerStateInfo *m_pCurStateInfo; // eax
  void (__thiscall *pfnLeaveState)(char *); // edx
  int StartMoney; // ebx
  edict_t *v11; // ecx
  IGameEvent *v12; // eax
  IGameEvent *v13; // edi
  int v14; // eax
  IGameEvent *v15; // ebx
  CTeam *GlobalTeam; // eax
  CTeam *v17; // eax
  CTeam *v18; // esi
  int i; // edi
  int v20; // eax
  CTeam *v21; // esi
  int j; // edi
  int v23; // eax
  int NumAliveTerrorist; // [esp+20h] [ebp-14h] BYREF
  int NumAliveCT; // [esp+24h] [ebp-10h] BYREF
  int NumDeadTerrorist; // [esp+28h] [ebp-Ch] BYREF
  int NumDeadCT; // [esp+2Ch] [ebp-8h] BYREF
  int numSpectators; // [esp+30h] [ebp-4h]
  int numPlayers; // [esp+3Ch] [ebp+8h]

  v3 = iTeamNum;
  if ( GetGlobalTeam(iIndex: (int)iTeamNum) == nullptr )
  {
    _Warning(a1: "CCSPlayer::ChangeTeam( %d ) - invalid team index.\n", iTeamNum);
    return;
  }
  TeamNumber = CBaseEntity::GetTeamNumber(this);
  if ( iTeamNum != (CBaseEntity *)TeamNumber )
  {
    CCSPlayer::DropWeapons(this, a2: iTeamNum, fromDeath: false, friendlyFire: false);
    CCSPlayer::RemoveNemesisRelationships(this);
    if ( iTeamNum == (CBaseEntity *)1 )
    {
      this->m_iOldTeam = TeamNumber;
    }
    else
    {
      RoundElapsedTime = CCSGameRules::GetRoundElapsedTime(this: (CCSGameRules *)g_pGameRules);
      CCSGameStats::IncrementStat(
        this: &CCS_GameStats,
        pPlayer: this,
        statId: CSSTAT_PLAYTIME,
        iDelta: (int)RoundElapsedTime,
        bPlayerOnly: true);
      this->m_bTeamChanged = true;
    }
    this->ChangeTeam(this, a2: (int)iTeamNum, a3: false, a4: false);
    if ( this->m_iClass.m_Value != 0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x1814u);
      }
      this->m_iClass.m_Value = 0;
    }
    if ( iTeamNum != nullptr )
    {
      if ( iTeamNum == (CBaseEntity *)1 )
      {
        this->RemoveAllItems(this, a2: true);
        CCSPlayer::State_Transition(this, newState: STATE_OBSERVER_MODE);
      }
      else
      {
        if ( TeamNumber == 1 )
        {
          StartMoney = CCSGameRules::GetStartMoney(this: (CCSGameRules *)g_pGameRules);
          if ( this->m_iAccount.m_Value < StartMoney )
          {
            if ( this->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&this->m_Network + 76) |= 1u;
            }
            else
            {
              v11 = this->m_Network.m_pPev;
              if ( v11 != nullptr )
                CBaseEdict::StateChanged(this: &v11->CBaseEdict, offset: 0x1900u);
            }
            this->m_iAccount.m_Value = StartMoney;
          }
          v3 = iTeamNum;
        }
        else if ( TeamNumber != 0 && !CBasePlayer::IsDead(this) )
        {
          this->CommitSuicide(this, a2: false, a3: false);
        }
        CCSPlayer::State_Transition(this, newState: STATE_PICKINGCLASS);
      }
    }
    else
    {
      m_pCurStateInfo = this->m_pCurStateInfo;
      if ( m_pCurStateInfo != nullptr )
      {
        pfnLeaveState = (void (__thiscall *)(char *))m_pCurStateInfo->pfnLeaveState;
        if ( pfnLeaveState != nullptr )
          pfnLeaveState(a1: (char *)this + DWORD1(m_pCurStateInfo->pfnLeaveState));
      }
      CCSPlayer::State_Enter(this, newState: STATE_OBSERVER_MODE);
      this->ResetForceTeamThink(this);
      CBaseEntity::ThinkSet(
        this,
        func:  __thiscall CBasePlayer::`vcall'{1396,{flat}},
        thinkTime: 0.0,
        szContext: nullptr);
      CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.5, szContext: nullptr);
    }
    CCSGameRules::InitializePlayerCounts(
      this: (CCSGameRules *)g_pGameRules,
      &NumAliveTerrorist,
      &NumAliveCT,
      &NumDeadTerrorist,
      &NumDeadCT);
    if ( v3 == (CBaseEntity *)3 )
    {
      v12 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "switch_team_to_ct", a3: 0, a4: 0);
    }
    else
    {
      if ( v3 != (CBaseEntity *)2 )
      {
LABEL_38:
        if ( !this->IsBot(this) )
        {
          v15 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "switch_team", a3: 0, a4: 0);
          if ( v15 != nullptr )
          {
            GlobalTeam = GetGlobalTeam(iIndex: 0);
            numPlayers = ((int (__thiscall *)(CTeam *, int))GlobalTeam->GetNumPlayers)(a1: GlobalTeam, a2);
            v17 = GetGlobalTeam(iIndex: 1);
            numSpectators = v17->GetNumPlayers(this: v17);
            v18 = GetGlobalTeam(iIndex: 2);
            for ( i = 0; i < v18->GetNumPlayers(this: v18); ++i )
            {
              v20 = (int)v18->GetPlayer(this: v18, a2: i);
              if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v20 + 1912))(a1: v20) == 0 )
                ++numPlayers;
            }
            v21 = GetGlobalTeam(iIndex: 3);
            for ( j = 0; j < v21->GetNumPlayers(this: v21); ++j )
            {
              v23 = (int)v21->GetPlayer(this: v21, a2: j);
              if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v23 + 1912))(a1: v23) == 0 )
                ++numPlayers;
            }
            ((void (__thiscall *)(IGameEvent *, const char *))v15->SetInt)(a1: v15, a2: "numPlayers");
            v15->SetInt(this: v15, a2: "numSpectators", a3: numSpectators);
            gameeventmanager->FireEvent(this: gameeventmanager, a2: v15, a3: false);
          }
        }
        return;
      }
      v12 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "switch_team_to_t", a3: 0, a4: 0);
    }
    v13 = v12;
    if ( v12 != nullptr )
    {
      v14 = engine->GetPlayerUserId(this: engine, a2: this->m_Network.m_pPev);
      v13->SetInt(this: v13, a2: "userid", a3: v14);
      gameeventmanager->FireEvent(this: gameeventmanager, a2: v13, a3: false);
    }
    goto LABEL_38;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028E630
// Name: public: void CCSPlayer::RecordDamageGiven(class CCSPlayer __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::RecordDamageGiven(
        CCSPlayer *this,
        CCSPlayer *damageDealer,
        CDamageRecord *szDamageTaker,
        int iDamageGiven)
{
  int m_Head; // esi
  CDamageRecord *v6; // esi
  unsigned int v7; // edi
  CDamageRecord *m_Element; // eax
  unsigned int v9; // ecx
  int v10; // eax
  int v11; // esi
  UtlLinkedListElem_t<CDamageRecord *,int> *v12; // ecx
  int m_Tail; // eax
  CDamageRecord *record; // [esp+18h] [ebp+Ch]

  m_Head = this->m_DamageGivenList.m_Head;
  if ( m_Head == -1 )
  {
LABEL_4:
    v6 = (CDamageRecord *)operator new(nSize: 0x30u);
    if ( v6 != nullptr )
    {
      v7 = s_BulletGroupCounter;
      v6->m_PlayerHandle.m_Index = -1;
      V_strncpy(pDest: v6->m_szPlayerName, pSrc: szDamageTaker->m_szPlayerName, maxLen: 32);
      v6->m_iDamage = iDamageGiven;
      v6->m_iNumHits = 1;
      v6->m_iLastBulletUpdate = v7;
      if ( damageDealer != nullptr )
        v6->m_PlayerHandle.m_Index = damageDealer->GetRefEHandle(this: damageDealer)->m_Index;
      else
        v6->m_PlayerHandle.m_Index = -1;
      record = v6;
    }
    else
    {
      record = nullptr;
    }
    v10 = CUtlLinkedList<CDamageRecord *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CDamageRecord *,int>,int>>::AllocInternal(
            this: &this->m_DamageGivenList,
            multilist: false);
    v11 = v10;
    if ( v10 == -1 )
    {
      v11 = -1;
    }
    else
    {
      CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
        this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&this->m_DamageGivenList,
        elem: v10);
      v12 = &this->m_DamageGivenList.m_Memory.m_pMemory[v11];
      v12->m_Next = -1;
      m_Tail = this->m_DamageGivenList.m_Tail;
      v12->m_Previous = m_Tail;
      this->m_DamageGivenList.m_Tail = v11;
      if ( m_Tail == -1 )
        this->m_DamageGivenList.m_Head = v11;
      else
        this->m_DamageGivenList.m_Memory.m_pMemory[m_Tail].m_Next = v11;
      ++this->m_DamageGivenList.m_ElementCount;
    }
    this->m_DamageGivenList.m_Memory.m_pMemory[v11].m_Element = record;
  }
  else
  {
    while ( V_strncmp(
              s1: szDamageTaker->m_szPlayerName,
              s2: this->m_DamageGivenList.m_Memory.m_pMemory[m_Head].m_Element->m_szPlayerName,
              count: 32) != 0 )
    {
      m_Head = this->m_DamageGivenList.m_Memory.m_pMemory[m_Head].m_Next;
      if ( m_Head == -1 )
        goto LABEL_4;
    }
    m_Element = this->m_DamageGivenList.m_Memory.m_pMemory[m_Head].m_Element;
    v9 = s_BulletGroupCounter;
    m_Element->m_iDamage += iDamageGiven;
    if ( m_Element->m_iLastBulletUpdate != v9 )
      ++m_Element->m_iNumHits;
    m_Element->m_iLastBulletUpdate = v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028E790
// Name: public: void CCSPlayer::RecordDamageTaken(class CCSPlayer __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::RecordDamageTaken(
        CCSPlayer *this,
        CCSPlayer *damageDealer,
        CDamageRecord *szDamageDealer,
        int iDamageTaken)
{
  int m_Head; // esi
  CDamageRecord *v6; // esi
  unsigned int v7; // edi
  CDamageRecord *m_Element; // eax
  unsigned int v9; // ecx
  int v10; // eax
  int v11; // esi
  UtlLinkedListElem_t<CDamageRecord *,int> *v12; // ecx
  int m_Tail; // eax
  CDamageRecord *record; // [esp+18h] [ebp+Ch]

  m_Head = this->m_DamageTakenList.m_Head;
  if ( m_Head == -1 )
  {
LABEL_4:
    v6 = (CDamageRecord *)operator new(nSize: 0x30u);
    if ( v6 != nullptr )
    {
      v7 = s_BulletGroupCounter;
      v6->m_PlayerHandle.m_Index = -1;
      V_strncpy(pDest: v6->m_szPlayerName, pSrc: szDamageDealer->m_szPlayerName, maxLen: 32);
      v6->m_iDamage = iDamageTaken;
      v6->m_iNumHits = 1;
      v6->m_iLastBulletUpdate = v7;
      if ( damageDealer != nullptr )
        v6->m_PlayerHandle.m_Index = damageDealer->GetRefEHandle(this: damageDealer)->m_Index;
      else
        v6->m_PlayerHandle.m_Index = -1;
      record = v6;
    }
    else
    {
      record = nullptr;
    }
    v10 = CUtlLinkedList<CDamageRecord *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CDamageRecord *,int>,int>>::AllocInternal(
            this: &this->m_DamageTakenList,
            multilist: false);
    v11 = v10;
    if ( v10 == -1 )
    {
      v11 = -1;
    }
    else
    {
      CUtlLinkedList<vgui::MenuItem *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::MenuItem *,int>,int>>::Unlink(
        this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&this->m_DamageTakenList,
        elem: v10);
      v12 = &this->m_DamageTakenList.m_Memory.m_pMemory[v11];
      v12->m_Next = -1;
      m_Tail = this->m_DamageTakenList.m_Tail;
      v12->m_Previous = m_Tail;
      this->m_DamageTakenList.m_Tail = v11;
      if ( m_Tail == -1 )
        this->m_DamageTakenList.m_Head = v11;
      else
        this->m_DamageTakenList.m_Memory.m_pMemory[m_Tail].m_Next = v11;
      ++this->m_DamageTakenList.m_ElementCount;
    }
    this->m_DamageTakenList.m_Memory.m_pMemory[v11].m_Element = record;
  }
  else
  {
    while ( V_strncmp(
              s1: szDamageDealer->m_szPlayerName,
              s2: this->m_DamageTakenList.m_Memory.m_pMemory[m_Head].m_Element->m_szPlayerName,
              count: 32) != 0 )
    {
      m_Head = this->m_DamageTakenList.m_Memory.m_pMemory[m_Head].m_Next;
      if ( m_Head == -1 )
        goto LABEL_4;
    }
    m_Element = this->m_DamageTakenList.m_Memory.m_pMemory[m_Head].m_Element;
    v9 = s_BulletGroupCounter;
    m_Element->m_iDamage += iDamageTaken;
    if ( m_Element->m_iLastBulletUpdate != v9 )
      ++m_Element->m_iNumHits;
    m_Element->m_iLastBulletUpdate = v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028E8F0
// Name: public: bool CCSPlayer::TakeControlOfBot(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
bool __userpurge CCSPlayer::TakeControlOfBot@<al>(CCSPlayer *this@<ecx>, int a2@<ebx>, CCSBot *pBot)
{
  bool result; // al
  int m_Value; // ecx
  int m_iFrags; // edx
  int m_iDeaths; // eax
  int v9; // ecx
  int v10; // eax
  int m_iEFlags; // edx
  int v12; // ecx
  float z; // eax
  unsigned int v14; // ecx
  float v15; // edx
  __int64 v16; // xmm0_8
  int v17; // eax
  int v18; // ecx
  MoveType_t v19; // edx
  CBaseCombatWeapon *ActiveWeapon; // ebx
  CBaseViewModel *ViewModel; // eax
  float curtime; // xmm0_4
  bool v23; // dl
  float v24; // xmm0_4
  float v25; // xmm0_4
  const char *pszValue; // ebx
  const char *v27; // eax
  edict_t *m_pPev; // ecx
  edict_t *v29; // eax
  edict_t *v30; // ecx
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  _DWORD *v33; // eax
  _DWORD *v34; // ebx
  unsigned int v35; // eax
  _DWORD *v36; // eax
  CBaseEdict *v37; // ecx
  unsigned int v38; // eax
  edict_t *v39; // ecx
  edict_t *v40; // ecx
  CCSPlayerStateInfo *m_pCurStateInfo; // eax
  void (__thiscall *pfnLeaveState)(char *); // edx
  edict_t *v43; // ecx
  CCSPlayerStateInfo *v44; // eax
  void (__thiscall *v45)(char *); // edx
  bool m_bTeamChanged; // bl
  void (__thiscall *Teleport)(CBaseEntity *, const Vector *, const QAngle *, const Vector *, bool); // eax
  edict_t *v48; // ecx
  CCSPlayerStateInfo *v49; // eax
  CSPlayerState v50; // ebx
  void (__thiscall *v51)(char *); // edx
  int v52; // ebx
  CBaseEdict *v53; // ecx
  CBaseEdict *v54; // ecx
  CBaseEdict *v55; // ecx
  CBaseEdict *v56; // ecx
  bool *v57; // esi
  bool v58; // bl
  bool *v59; // eax
  CBaseEdict *v60; // ecx
  CBaseViewModel *v61; // eax
  edict_t *v62; // ecx
  char szBotWeaponClassname[64]; // [esp+48h] [ebp-8Ch] BYREF
  Vector vecBotPosition; // [esp+88h] [ebp-4Ch] BYREF
  QAngle vecBotAngles; // [esp+94h] [ebp-40h] BYREF
  float flBotVMCycle; // [esp+A0h] [ebp-34h]
  MoveType_t eBotMoveType; // [esp+A4h] [ebp-30h]
  int nBotClass; // [esp+A8h] [ebp-2Ch]
  float flBotStamina; // [esp+ACh] [ebp-28h]
  float flBotWeaponCycle; // [esp+B0h] [ebp-24h]
  int nBotHealth; // [esp+B4h] [ebp-20h]
  float flBotNextAttack; // [esp+B8h] [ebp-1Ch]
  float flBotVelocityModifier; // [esp+BCh] [ebp-18h]
  float flBotWeaponNextSecondaryAttack; // [esp+C0h] [ebp-14h]
  float flBotWeaponTimeWeaponIdle; // [esp+C4h] [ebp-10h]
  float flBotWeaponNextPrimaryAttack; // [esp+C8h] [ebp-Ch]
  signed int v78; // [esp+CCh] [ebp-8h]
  bool bBotWeaponInReload; // [esp+D1h] [ebp-3h]
  bool bBotFL_DUCKING; // [esp+D2h] [ebp-2h]
  bool bBotDucking; // [esp+D3h] [ebp-1h]
  int savedregs; // [esp+D4h] [ebp+0h] BYREF
  bool bBotDucked_3; // [esp+DFh] [ebp+Bh]

  result = CCSPlayer::CanControlBot(this, pBot);
  if ( result )
  {
    m_Value = this->m_iAccount.m_Value;
    m_iFrags = this->m_iFrags;
    this->m_PreControlData.m_iClass = this->m_iClass.m_Value;
    m_iDeaths = this->m_iDeaths;
    this->m_PreControlData.m_iFrags = m_iFrags;
    this->m_PreControlData.m_iAccount = m_Value;
    this->m_PreControlData.m_iDeaths = m_iDeaths;
    v9 = pBot->m_iClass.m_Value;
    v10 = pBot->m_iFrags;
    pBot->m_PreControlData.m_iAccount = pBot->m_iAccount.m_Value;
    m_iEFlags = pBot->m_iEFlags;
    pBot->m_PreControlData.CBot<CCSPlayer>::CCSPlayer::m_iClass = v9;
    v12 = pBot->m_iDeaths;
    pBot->m_PreControlData.m_iFrags = v10;
    pBot->m_PreControlData.m_iDeaths = v12;
    if ( (m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pBot, a2: (int)&savedregs);
    z = pBot->m_vecAbsOrigin.z;
    v14 = (unsigned int)pBot->m_iEFlags >> 11;
    *(_QWORD *)&vecBotPosition.x = *(_QWORD *)&pBot->m_vecAbsOrigin.x;
    vecBotPosition.z = z;
    if ( (v14 & 1) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: pBot, a2: (int)&savedregs);
    v15 = pBot->m_angAbsRotation.z;
    v16 = *(_QWORD *)&pBot->m_angAbsRotation.x;
    v17 = pBot->m_iClass.m_Value;
    nBotHealth = pBot->m_iHealth.m_Value;
    v18 = pBot->m_fFlags.m_Value;
    vecBotAngles.z = v15;
    LOBYTE(v15) = pBot->m_Local.m_bDucked.m_Value;
    *(_QWORD *)&vecBotAngles.x = v16;
    *(float *)&v16 = pBot->m_flStamina.m_Value;
    bBotDucked_3 = LOBYTE(v15);
    v19 = pBot->m_MoveType.m_Value;
    nBotClass = v17;
    LOBYTE(v17) = pBot->m_Local.m_bDucking.m_Value;
    flBotStamina = *(float *)&v16;
    *(float *)&v16 = pBot->m_flVelocityModifier.m_Value;
    bBotFL_DUCKING = (v18 & 2) != 0;
    flBotVelocityModifier = *(float *)&v16;
    bBotDucking = v17;
    eBotMoveType = v19;
    ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: pBot);
    ViewModel = CBasePlayer::GetViewModel(this: pBot, index: 0);
    flBotNextAttack = pBot->m_flNextAttack.m_Value;
    if ( ActiveWeapon != nullptr )
    {
      flBotWeaponNextPrimaryAttack = ActiveWeapon->m_flNextPrimaryAttack.m_Value;
      flBotWeaponNextSecondaryAttack = ActiveWeapon->m_flNextSecondaryAttack.m_Value;
      curtime = ActiveWeapon->m_flTimeWeaponIdle.m_Value;
    }
    else
    {
      curtime = gpGlobals->curtime;
      flBotWeaponNextPrimaryAttack = curtime;
      flBotWeaponNextSecondaryAttack = curtime;
    }
    v23 = ActiveWeapon->m_bInReload.m_Value;
    flBotWeaponTimeWeaponIdle = curtime;
    v24 = ActiveWeapon->m_flCycle.m_Value;
    bBotWeaponInReload = v23;
    flBotWeaponCycle = v24;
    if ( ViewModel != nullptr )
      v25 = ViewModel->m_flCycle.m_Value;
    else
      v25 = 0.0;
    pszValue = ActiveWeapon->m_iClassname.pszValue;
    flBotVMCycle = v25;
    v27 = pszValue;
    if ( pszValue == nullptr )
      v27 = locale;
    V_strncpy(pDest: szBotWeaponClassname, pSrc: v27, maxLen: 64);
    this->m_hControlledBot.m_Index = *(_DWORD *)((int (__thiscall *)(CCSBot *, int))pBot->GetRefEHandle)(a1: pBot, a2);
    pBot->m_hControlledByPlayer.m_Index = this->GetRefEHandle(this)->m_Index;
    if ( !this->m_bIsControllingBot.m_Value )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x1B6Bu);
      }
      this->m_bIsControllingBot.m_Value = true;
    }
    v29 = pBot->m_Network.m_pPev;
    if ( v29 != nullptr )
      v78 = v29 - gpGlobals->pEdicts;
    else
      v78 = 0;
    if ( this->m_iControlledBotEntIndex.m_Value != v78 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v30 = this->m_Network.m_pPev;
        if ( v30 != nullptr )
          CBaseEdict::StateChanged(this: &v30->CBaseEdict, offset: 0x1B70u);
      }
      this->m_iControlledBotEntIndex.m_Value = v78;
    }
    m_Index = this->m_hRagdoll.m_Value.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    v33 = __RTDynamicCast(
            inptr: m_pEntity,
            VfDelta: 0,
            SrcType: &CBaseEntity `RTTI Type Descriptor',
            TargetType: &CCSRagdoll `RTTI Type Descriptor',
            isReference: 0);
    if ( v33 != nullptr )
    {
      v34 = v33 + 296;
      v35 = v33[296];
      if ( v35 != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)v35].m_SerialNumber == HIWORD(v35)
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)v35].m_pEntity != nullptr )
      {
        v36 = v34 - 296;
        if ( *((_BYTE *)v34 - 1100) != 0 )
        {
          *((_BYTE *)v36 + 88) |= 1u;
        }
        else
        {
          v37 = (CBaseEdict *)v36[6];
          if ( v37 != nullptr )
            CBaseEdict::StateChanged(this: v37, offset: 0x4A0u);
        }
        *v34 = -1;
      }
      v38 = this->m_hRagdoll.m_Value.m_Index;
      if ( v38 != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)v38].m_SerialNumber == HIWORD(v38)
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)v38].m_pEntity != nullptr )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v39 = this->m_Network.m_pPev;
          if ( v39 != nullptr )
            CBaseEdict::StateChanged(this: &v39->CBaseEdict, offset: 0x17D8u);
        }
        this->m_hRagdoll.m_Value.m_Index = -1;
      }
    }
    if ( this->m_iClass.m_Value != nBotClass )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v40 = this->m_Network.m_pPev;
        if ( v40 != nullptr )
          CBaseEdict::StateChanged(this: &v40->CBaseEdict, offset: 0x1814u);
      }
      this->m_iClass.m_Value = nBotClass;
    }
    CBaseEntity::MakeDormant(this: pBot);
    m_pCurStateInfo = pBot->m_pCurStateInfo;
    if ( m_pCurStateInfo != nullptr )
    {
      pfnLeaveState = (void (__thiscall *)(char *))m_pCurStateInfo->pfnLeaveState;
      if ( pfnLeaveState != nullptr )
        pfnLeaveState(a1: (char *)pBot + DWORD1(m_pCurStateInfo->pfnLeaveState));
    }
    CCSPlayer::State_Enter(this: pBot, newState: STATE_DORMANT);
    if ( pBot->m_iHealth.m_Value != 0 )
    {
      pBot->NetworkStateChanged_m_iHealth(this: pBot, a2: &pBot->m_iHealth);
      pBot->m_iHealth.m_Value = 0;
    }
    if ( pBot->m_lifeState.m_Value != 2 )
    {
      pBot->NetworkStateChanged_m_lifeState(this: pBot, a2: &pBot->m_lifeState);
      pBot->m_lifeState.m_Value = 2;
    }
    if ( this->m_flVelocityModifier.m_Value != flBotVelocityModifier )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v43 = this->m_Network.m_pPev;
        if ( v43 != nullptr )
          CBaseEdict::StateChanged(this: &v43->CBaseEdict, offset: 0x178Cu);
      }
      this->m_flVelocityModifier.m_Value = flBotVelocityModifier;
    }
    this->StopObserverMode(this);
    v44 = this->m_pCurStateInfo;
    if ( v44 != nullptr )
    {
      v45 = (void (__thiscall *)(char *))v44->pfnLeaveState;
      if ( v45 != nullptr )
        v45(a1: (char *)this + DWORD1(v44->pfnLeaveState));
    }
    CCSPlayer::State_Enter(this, newState: STATE_ACTIVE);
    m_bTeamChanged = this->m_bTeamChanged;
    this->Spawn(this);
    Teleport = this->Teleport;
    this->m_bTeamChanged = m_bTeamChanged;
    Teleport(this, a2: &vecBotPosition, a3: &vecBotAngles, a4: &vec3_origin, a5: true);
    if ( this->m_flStamina.m_Value != flBotStamina )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v48 = this->m_Network.m_pPev;
        if ( v48 != nullptr )
          CBaseEdict::StateChanged(this: &v48->CBaseEdict, offset: 0x1780u);
      }
      this->m_flStamina.m_Value = flBotStamina;
    }
    v49 = this->m_pCurStateInfo;
    v50 = this->m_iPlayerState.m_Value;
    if ( v49 != nullptr )
    {
      v51 = (void (__thiscall *)(char *))v49->pfnLeaveState;
      if ( v51 != nullptr )
        v51(a1: (char *)this + DWORD1(v49->pfnLeaveState));
    }
    CCSPlayer::State_Enter(this, newState: v50);
    CCSPlayer::TransferInventory(this: pBot, pTargetPlayer: this);
    if ( this->m_iHealth.m_Value != nBotHealth )
    {
      this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
      this->m_iHealth.m_Value = nBotHealth;
    }
    if ( this->m_lifeState.m_Value != 0 )
    {
      this->NetworkStateChanged_m_lifeState(this, a2: &this->m_lifeState);
      this->m_lifeState.m_Value = 0;
    }
    CBaseEntity::SetMoveType(this, val: eBotMoveType, moveCollide: MOVECOLLIDE_DEFAULT);
    if ( this->m_Local.m_bDucked.m_Value != bBotDucked_3 )
    {
      this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: &this->m_Local.m_bDucked);
      this->m_Local.m_bDucked.m_Value = bBotDucked_3;
    }
    if ( this->m_Local.m_bDucking.m_Value != bBotDucking )
    {
      this->m_Local.NetworkStateChanged(this: &this->m_Local, a2: &this->m_Local.m_bDucking);
      this->m_Local.m_bDucking.m_Value = bBotDucking;
    }
    if ( bBotFL_DUCKING )
      CBaseEntity::AddFlag(this, flags: 2);
    CBaseEntity::DispatchUpdateTransmitState(this: pBot);
    CBaseEntity::DispatchUpdateTransmitState(this);
    v52 = ((int (__thiscall *)(CCSPlayer *, char *))this->Weapon_OwnsThisType)(a1: this, a2: szBotWeaponClassname);
    if ( v52 != 0 )
    {
      this->Weapon_Switch(this, a2: (CBaseCombatWeapon *)v52, a3: 0);
      if ( *(float *)(v52 + 940) != flBotWeaponCycle )
      {
        if ( *(_BYTE *)(v52 + 84) != 0 )
        {
          *(_BYTE *)(v52 + 88) |= 1u;
        }
        else
        {
          v53 = *(CBaseEdict **)(v52 + 24);
          if ( v53 != nullptr )
            CBaseEdict::StateChanged(this: v53, offset: 0x3ACu);
        }
        *(float *)(v52 + 940) = flBotWeaponCycle;
      }
      if ( *(float *)(v52 + 1208) != flBotWeaponTimeWeaponIdle )
      {
        if ( *(_BYTE *)(v52 + 84) != 0 )
        {
          *(_BYTE *)(v52 + 88) |= 1u;
        }
        else
        {
          v54 = *(CBaseEdict **)(v52 + 24);
          if ( v54 != nullptr )
            CBaseEdict::StateChanged(this: v54, offset: 0x4B8u);
        }
        *(float *)(v52 + 1208) = flBotWeaponTimeWeaponIdle;
      }
      if ( *(float *)(v52 + 1172) != flBotWeaponNextPrimaryAttack )
      {
        if ( *(_BYTE *)(v52 + 84) != 0 )
        {
          *(_BYTE *)(v52 + 88) |= 1u;
        }
        else
        {
          v55 = *(CBaseEdict **)(v52 + 24);
          if ( v55 != nullptr )
            CBaseEdict::StateChanged(this: v55, offset: 0x494u);
        }
        *(float *)(v52 + 1172) = flBotWeaponNextPrimaryAttack;
      }
      if ( *(float *)(v52 + 1176) != flBotWeaponNextSecondaryAttack )
      {
        if ( *(_BYTE *)(v52 + 84) != 0 )
        {
          *(_BYTE *)(v52 + 88) |= 1u;
        }
        else
        {
          v56 = *(CBaseEdict **)(v52 + 24);
          if ( v56 != nullptr )
            CBaseEdict::StateChanged(this: v56, offset: 0x498u);
        }
        *(float *)(v52 + 1176) = flBotWeaponNextSecondaryAttack;
      }
      v57 = (bool *)(v52 + 1253);
      v58 = bBotWeaponInReload;
      if ( *v57 != bBotWeaponInReload )
      {
        v59 = v57 - 1253;
        if ( *(v57 - 1169) )
        {
          v59[88] |= 1u;
        }
        else
        {
          v60 = *((CBaseEdict **)v59 + 6);
          if ( v60 != nullptr )
            CBaseEdict::StateChanged(this: v60, offset: 0x4E5u);
        }
        *v57 = v58;
      }
      v61 = CBasePlayer::GetViewModel(this, index: 0);
      if ( v61 != nullptr )
        CBaseAnimating::SetCycle(this: v61, flCycle: flBotVMCycle);
      if ( this->m_flNextAttack.m_Value != flBotNextAttack )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v62 = this->m_Network.m_pPev;
          if ( v62 != nullptr )
            CBaseEdict::StateChanged(this: &v62->CBaseEdict, offset: 0x684u);
        }
        this->m_flNextAttack.m_Value = flBotNextAttack;
      }
    }
    ++this->m_botsControlled;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1028F0D0
// Name: bot_take_control
// Source: json
//------------------------------------------------------------------------------
void __usercall bot_take_control(int a1@<ebx>)
{
  CBasePlayer *CommandClient; // esi
  CCSPlayer *v2; // esi
  CBaseEntity *v3; // eax
  CCSBot *v4; // edi
  int v5; // eax
  const char *v6; // eax
  edict_t *v7; // eax
  int v8; // eax
  const char *v9; // eax
  int v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  const char *v13; // [esp-Ch] [ebp-10h]
  const char *v14; // [esp-8h] [ebp-Ch]
  int v15; // [esp-8h] [ebp-Ch]
  const char *v16; // [esp-8h] [ebp-Ch]

  CommandClient = UTIL_GetCommandClient();
  if ( CommandClient != nullptr && CommandClient->IsPlayer(this: CommandClient) )
  {
    v2 = (CCSPlayer *)__RTDynamicCast(
                        inptr: CommandClient,
                        VfDelta: 0,
                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                        TargetType: &CCSPlayer `RTTI Type Descriptor',
                        isReference: 0);
    if ( v2 != nullptr )
    {
      v3 = v2->GetObserverTarget(this: v2);
      v4 = ToCSBot(pEntity: v3);
      if ( v4 != nullptr )
      {
        if ( CBasePlayer::IsDead(this: v2)
          && cv_bot_controllable.m_pParent != nullptr
          && cv_bot_controllable.m_pParent->m_Value.m_nValue != 0 )
        {
          if ( CCSPlayer::TakeControlOfBot(this: v2, a2: a1, pBot: v4) )
          {
            v7 = CBaseEntity::entindex(this: v4);
            v8 = ((int (__thiscall *)(CCSBot *, edict_t *))v4->GetPlayerName)(a1: v4, a2: v7);
            v9 = (const char *)((int (__thiscall *)(CCSPlayer *, int))v2->GetPlayerName)(a1: v2, a2: v8);
            _Msg(a1: "Player %s took control bot %s (%d)\n", v9, v13, v15);
          }
          else
          {
            v10 = (int)v4->GetPlayerName(this: v4);
            v11 = (const char *)((int (__thiscall *)(CCSPlayer *, int))v2->GetPlayerName)(a1: v2, a2: v10);
            _Msg(a1: "Player %s tried to take control of bot %s but failed\n", v11, v16);
          }
        }
        else
        {
          v5 = (int)v4->GetPlayerName(this: v4);
          v6 = (const char *)((int (__thiscall *)(CCSPlayer *, int))v2->GetPlayerName)(a1: v2, a2: v5);
          _Msg(a1: "Player %s tried to take control of bot %s but was disallowed by the server\n", v6, v14);
        }
      }
      else
      {
        v12 = v2->GetPlayerName(this: v2);
        _Msg(a1: "Player %s tried to take control of bot but none could be found\n", v12);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028F220
// Name: public: CCSPlayer::CCSPlayer(void)
// Source: json
//------------------------------------------------------------------------------
CCSPlayer *__thiscall CCSPlayer::CCSPlayer(CCSPlayer *this)
{
  CountdownTimer_vtbl *v2; // edx
  CountdownTimer_vtbl *v3; // edx
  UtlLinkedListElem_t<CDamageRecord *,int> *m_pMemory; // ecx
  UtlLinkedListElem_t<CDamageRecord *,int> *v5; // edx
  CountdownTimer_vtbl *v6; // edx
  CountdownTimer_vtbl *v7; // edx
  edict_t *m_pPev; // ecx
  edict_t *v9; // ecx
  edict_t *v10; // ecx
  edict_t *v11; // ecx
  const CViewVectors *v12; // eax
  edict_t *v13; // ecx
  edict_t *v14; // ecx
  edict_t *v15; // ecx
  edict_t *v16; // ecx
  edict_t *v17; // ecx
  edict_t *v18; // ecx
  edict_t *v19; // ecx
  edict_t *v20; // ecx
  double curtime; // st7
  CHintMessageQueue *v22; // eax
  CHintMessageQueue *v23; // eax
  double v24; // st7
  edict_t *v25; // ecx
  edict_t *v26; // ecx
  edict_t *v27; // ecx
  edict_t *v28; // ecx
  edict_t *v29; // ecx
  edict_t *v30; // ecx
  edict_t *v31; // ecx
  edict_t *v32; // ecx
  int m_nValue; // ecx
  ConVarRef v35; // [esp+Ch] [ebp-8h] BYREF

  CBaseMultiplayerPlayer::CBaseMultiplayerPlayer(this);
  this->ICSPlayerAnimStateHelpers::__vftable = (ICSPlayerAnimStateHelpers_vtbl *)&ICSPlayerAnimStateHelpers::`vftable';
  this->CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CCSPlayer_vtbl *)&CCSPlayer::`vftable'{for `CBasePlayer'};
  this->CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CAI_ExpresserSink::__vftable = (CAI_ExpresserSink_vtbl *)&CCSPlayer::`vftable'{for `CAI_ExpresserSink'};
  this->ICSPlayerAnimStateHelpers::__vftable = (ICSPlayerAnimStateHelpers_vtbl *)&CCSPlayer::`vftable';
  this->m_pIntroCamera.m_Index = -1;
  this->m_hRagdoll.m_Value.m_Index = -1;
  this->m_ladderSurpressionTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v2 = this->m_ladderSurpressionTimer.__vftable;
  this->m_ladderSurpressionTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v2->NetworkStateChanged)(a1: &this->m_ladderSurpressionTimer.m_duration);
  v3 = this->m_ladderSurpressionTimer.__vftable;
  this->m_ladderSurpressionTimer.m_timestamp.m_Value = -1.0;
  v3->NetworkStateChanged(this: &this->m_ladderSurpressionTimer, a2: &this->m_ladderSurpressionTimer.m_timestamp);
  this->m_DamageGivenList.m_Memory.m_pMemory = nullptr;
  this->m_DamageGivenList.m_Memory.m_nAllocationCount = 0;
  this->m_DamageGivenList.m_Memory.m_nGrowSize = 0;
  this->m_DamageGivenList.m_LastAlloc.index = -1;
  m_pMemory = this->m_DamageGivenList.m_Memory.m_pMemory;
  this->m_DamageGivenList.m_Head = -1;
  this->m_DamageGivenList.m_Tail = -1;
  this->m_DamageGivenList.m_FirstFree = -1;
  this->m_DamageGivenList.m_ElementCount = 0;
  this->m_DamageGivenList.m_NumAlloced = 0;
  this->m_DamageGivenList.m_pElements = m_pMemory;
  this->m_DamageTakenList.m_Memory.m_pMemory = nullptr;
  this->m_DamageTakenList.m_Memory.m_nAllocationCount = 0;
  this->m_DamageTakenList.m_Memory.m_nGrowSize = 0;
  this->m_DamageTakenList.m_LastAlloc.index = -1;
  v5 = this->m_DamageTakenList.m_Memory.m_pMemory;
  this->m_DamageTakenList.m_Head = -1;
  this->m_DamageTakenList.m_Tail = -1;
  this->m_DamageTakenList.m_FirstFree = -1;
  this->m_DamageTakenList.m_ElementCount = 0;
  this->m_DamageTakenList.m_NumAlloced = 0;
  this->m_DamageTakenList.m_pElements = v5;
  this->m_RateLimitLastCommandTimes.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_RateLimitLastCommandTimes.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_RateLimitLastCommandTimes.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_RateLimitLastCommandTimes.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_RateLimitLastCommandTimes.m_Elements.m_Tree.m_Root = -1;
  this->m_RateLimitLastCommandTimes.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_RateLimitLastCommandTimes.m_Elements.m_Tree.m_NumElements = 0;
  this->m_RateLimitLastCommandTimes.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_RateLimitLastCommandTimes.m_Elements.m_Tree.m_pElements = this->m_RateLimitLastCommandTimes.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_RateLimitLastCommandTimes.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_RateLimitLastCommandTimes.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->m_cycleLatchTimer.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v6 = this->m_cycleLatchTimer.__vftable;
  this->m_cycleLatchTimer.m_duration.m_Value = 0.0;
  ((void (__stdcall *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v6->NetworkStateChanged)(a1: &this->m_cycleLatchTimer.m_duration);
  v7 = this->m_cycleLatchTimer.__vftable;
  this->m_cycleLatchTimer.m_timestamp.m_Value = -1.0;
  v7->NetworkStateChanged(this: &this->m_cycleLatchTimer, a2: &this->m_cycleLatchTimer.m_timestamp);
  this->m_killTimes.m_Memory.m_pMemory = nullptr;
  this->m_killTimes.m_Memory.m_nAllocationCount = 0;
  this->m_killTimes.m_Memory.m_nGrowSize = 0;
  this->m_killTimes.m_Size = 0;
  this->m_killTimes.m_pElements = nullptr;
  this->m_enemyPlayersKilledThisRound.m_Memory.m_pMemory = nullptr;
  this->m_enemyPlayersKilledThisRound.m_Memory.m_nAllocationCount = 0;
  this->m_enemyPlayersKilledThisRound.m_Memory.m_nGrowSize = 0;
  this->m_enemyPlayersKilledThisRound.m_Size = 0;
  this->m_enemyPlayersKilledThisRound.m_pElements = nullptr;
  this->m_killWeapons.m_Memory.m_pMemory = nullptr;
  this->m_killWeapons.m_Memory.m_nAllocationCount = 0;
  this->m_killWeapons.m_Memory.m_nGrowSize = 0;
  this->m_killWeapons.m_Size = 0;
  this->m_killWeapons.m_pElements = nullptr;
  this->m_pGooseChaseDistractingPlayer.m_Index = -1;
  this->m_lastFlashBangAttacker.m_Index = -1;
  this->m_WeaponTypesUsed.m_Memory.m_pMemory = nullptr;
  this->m_WeaponTypesUsed.m_Memory.m_nAllocationCount = 0;
  this->m_WeaponTypesUsed.m_Memory.m_nGrowSize = 0;
  this->m_WeaponTypesUsed.m_Size = 0;
  this->m_WeaponTypesUsed.m_pElements = nullptr;
  this->m_WeaponTypesHeld.m_Memory.m_pMemory = nullptr;
  this->m_WeaponTypesHeld.m_Memory.m_nAllocationCount = 0;
  this->m_WeaponTypesHeld.m_Memory.m_nGrowSize = 0;
  this->m_WeaponTypesHeld.m_Size = 0;
  this->m_WeaponTypesHeld.m_pElements = nullptr;
  this->m_WeaponTypesRunningOutOfAmmo.m_Memory.m_pMemory = nullptr;
  this->m_WeaponTypesRunningOutOfAmmo.m_Memory.m_nAllocationCount = 0;
  this->m_WeaponTypesRunningOutOfAmmo.m_Memory.m_nGrowSize = 0;
  this->m_WeaponTypesRunningOutOfAmmo.m_Size = 0;
  this->m_WeaponTypesRunningOutOfAmmo.m_pElements = nullptr;
  this->m_BurnDamageDeltVec.m_Memory.m_pMemory = nullptr;
  this->m_BurnDamageDeltVec.m_Memory.m_nAllocationCount = 0;
  this->m_BurnDamageDeltVec.m_Memory.m_nGrowSize = 0;
  this->m_BurnDamageDeltVec.m_Size = 0;
  this->m_BurnDamageDeltVec.m_pElements = nullptr;
  this->m_hControlledBot.m_Index = -1;
  this->m_hControlledByPlayer.m_Index = -1;
  this->m_PlayerAnimState = CreatePlayerAnimState(
                              pEntity: this,
                              pHelpers: &this->ICSPlayerAnimStateHelpers,
                              legAnimType: LEGANIM_9WAY,
                              bUseAimSequences: true);
  CBaseAnimating::UseClientSideAnimation(this);
  this->m_maxNumRoundsSurvived = 0;
  this->m_numRoundsSurvived = 0;
  this->m_iLastWeaponFireUsercmd = 0;
  if ( this->m_iAddonBits.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x18F4u);
    }
    this->m_iAddonBits.m_Value = 0;
  }
  this->m_bEscaped = false;
  if ( this->m_iAccount.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v9 = this->m_Network.m_pPev;
      if ( v9 != nullptr )
        CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0x1900u);
    }
    this->m_iAccount.m_Value = 0;
  }
  this->m_bIsVIP = false;
  if ( this->m_iClass.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v10 = this->m_Network.m_pPev;
      if ( v10 != nullptr )
        CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0x1814u);
    }
    this->m_iClass.m_Value = 0;
  }
  if ( this->m_angEyeAngles.m_Value.x != 0.0
    || this->m_angEyeAngles.m_Value.y != 0.0
    || this->m_angEyeAngles.m_Value.z != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v11 = this->m_Network.m_pPev;
      if ( v11 != nullptr )
        CBaseEdict::StateChanged(this: &v11->CBaseEdict, offset: 0x183Cu);
    }
    this->m_angEyeAngles.m_Value.x = 0.0;
    this->m_angEyeAngles.m_Value.y = 0.0;
    this->m_angEyeAngles.m_Value.z = 0.0;
  }
  v12 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  CBaseEntity::SetViewOffset(this, v: &v12->m_vView);
  this->m_pCurStateInfo = nullptr;
  if ( this->m_iThrowGrenadeCounter.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v13 = this->m_Network.m_pPev;
      if ( v13 != nullptr )
        CBaseEdict::StateChanged(this: &v13->CBaseEdict, offset: 0x17D4u);
    }
    this->m_iThrowGrenadeCounter.m_Value = 0;
  }
  if ( this->m_lifeState.m_Value != 2 )
  {
    this->NetworkStateChanged_m_lifeState(this, a2: &this->m_lifeState);
    this->m_lifeState.m_Value = 2;
  }
  *(_WORD *)&this->m_bInBombZoneTrigger = 0;
  if ( this->m_bInBombZone.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v14 = this->m_Network.m_pPev;
      if ( v14 != nullptr )
        CBaseEdict::StateChanged(this: &v14->CBaseEdict, offset: 0x1770u);
    }
    this->m_bInBombZone.m_Value = false;
  }
  this->m_bWasInBuyZone = false;
  if ( this->m_bInBuyZone.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v15 = this->m_Network.m_pPev;
      if ( v15 != nullptr )
        CBaseEdict::StateChanged(this: &v15->CBaseEdict, offset: 0x1771u);
    }
    this->m_bInBuyZone.m_Value = false;
  }
  this->m_bWasInHostageRescueZone = false;
  if ( this->m_bInHostageRescueZone.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v16 = this->m_Network.m_pPev;
      if ( v16 != nullptr )
        CBaseEdict::StateChanged(this: &v16->CBaseEdict, offset: 0x177Cu);
    }
    this->m_bInHostageRescueZone.m_Value = false;
  }
  if ( this->m_flDeathTime.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v17 = this->m_Network.m_pPev;
      if ( v17 != nullptr )
        CBaseEdict::StateChanged(this: &v17->CBaseEdict, offset: 0xC3Cu);
    }
    this->m_flDeathTime.m_Value = 0.0;
  }
  if ( this->m_fForceTeam.m_Value != -1.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v18 = this->m_Network.m_pPev;
      if ( v18 != nullptr )
        CBaseEdict::StateChanged(this: &v18->CBaseEdict, offset: 0xC44u);
    }
    this->m_fForceTeam.m_Value = -1.0;
  }
  this->m_iHostagesKilled = 0;
  this->iRadioMenu = -1;
  this->m_bTeamChanged = false;
  if ( this->m_iShotsFired.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v19 = this->m_Network.m_pPev;
      if ( v19 != nullptr )
        CBaseEdict::StateChanged(this: &v19->CBaseEdict, offset: 0x1788u);
    }
    this->m_iShotsFired.m_Value = 0;
  }
  this->m_bulletsFiredSinceLastSpawn = 0;
  if ( this->m_iDirection.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v20 = this->m_Network.m_pPev;
      if ( v20 != nullptr )
        CBaseEdict::StateChanged(this: &v20->CBaseEdict, offset: 0x1784u);
    }
    this->m_iDirection.m_Value = 0;
  }
  this->m_receivesMoneyNextRound = true;
  this->m_bIsBeingGivenItem = false;
  this->m_isVIP = false;
  *(_WORD *)&this->m_bJustKilledTeammate = 0;
  this->m_iTeamKills = 0;
  curtime = gpGlobals->curtime;
  this->m_iNextTimeCheck = 0;
  this->m_flLastMovement = curtime;
  this->m_szNewName[0] = 0;
  this->m_flNameChangeHistory[0] = -600.0;
  this->m_flNameChangeHistory[1] = -600.0;
  this->m_flNameChangeHistory[2] = -600.0;
  this->m_flNameChangeHistory[3] = -600.0;
  this->m_flNameChangeHistory[4] = -600.0;
  this->m_iIgnoreGlobalChat = 0;
  this->m_bIgnoreRadio = false;
  v22 = (CHintMessageQueue *)operator new(nSize: 0x1Cu);
  if ( v22 != nullptr )
    v23 = CHintMessageQueue::CHintMessageQueue(this: v22, pPlayer: this);
  else
    v23 = nullptr;
  this->m_pHintMessageQueue = v23;
  this->m_iDisplayHistoryBits = 0;
  this->m_bShowHints = true;
  v24 = gpGlobals->curtime;
  this->m_lastDamageHealth = 0;
  this->m_flNextMouseoverUpdate = v24;
  this->m_lastDamageArmor = 0;
  this->m_applyDeafnessTime = 0.0;
  if ( this->m_cycleLatch.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v25 = this->m_Network.m_pPev;
      if ( v25 != nullptr )
        CBaseEdict::StateChanged(this: &v25->CBaseEdict, offset: 0x1984u);
    }
    this->m_cycleLatch.m_Value = 0;
  }
  if ( this->m_cycleLatchTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_cycleLatchTimer.NetworkStateChanged(
      this: &this->m_cycleLatchTimer,
      a2: &this->m_cycleLatchTimer.m_timestamp);
    this->m_cycleLatchTimer.m_timestamp.m_Value = -1.0;
  }
  this->m_firstKillBlindStartTime = -1.0;
  this->m_iShouldHaveCash = 0;
  this->m_lastNavArea = nullptr;
  this->m_NumEnemiesKilledThisRound = 0;
  this->m_NumEnemiesKilledThisSpawn = 0;
  this->m_maxNumEnemiesKillStreak = 0;
  this->m_NumEnemiesAtRoundStart = 0;
  this->m_KillingSpreeStartTime = -1;
  this->m_killsWhileBlind = 0;
  this->m_bombCarrierkills = 0;
  *(_WORD *)&this->m_bSurvivedHeadshotDueToHelmet = 0;
  this->m_pGooseChaseDistractingPlayer.m_Index = -1;
  this->m_bombPickupTime = -1.0;
  this->m_bombPlacedTime = -1.0;
  this->m_bombDroppedTime = -1.0;
  this->m_killedTime = -1.0;
  this->m_spawnedTime = -1.0;
  this->m_longestLife = -1.0;
  this->m_gooseChaseStep = GC_NONE;
  this->m_defuseDefenseStep = DD_NONE;
  this->m_lastRoundResult = -1;
  this->m_bMadeFootstepNoise = false;
  this->m_knifeKillsWhenOutOfAmmo = 0;
  this->m_attemptedBombPlace = false;
  this->m_triggerPulled = false;
  this->m_triggerPulls = 0;
  this->m_bMadePurchseThisRound = false;
  this->m_roundsWonWithoutPurchase = 0;
  this->m_iDeathFlags = 0;
  this->m_lastWeaponBeforeC4AutoSwitch = nullptr;
  this->m_lastFlashBangAttacker.m_Index = -1;
  this->m_iMVPs = 0;
  *(_WORD *)&this->m_bKilledDefuser = 0;
  this->m_maxGrenadeKills = 0;
  this->m_grenadeDamageTakenThisRound = 0;
  this->m_firstShotKills = 0;
  this->m_hasReloaded = false;
  this->m_flNextAutoBuyAmmoTime = 0.0;
  this->m_wasNotKilledNaturally = false;
  if ( this->m_iGunGameProgressiveWeaponIndex.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v26 = this->m_Network.m_pPev;
      if ( v26 != nullptr )
        CBaseEdict::StateChanged(this: &v26->CBaseEdict, offset: 0x1314u);
    }
    this->m_iGunGameProgressiveWeaponIndex.m_Value = 0;
  }
  *(_WORD *)&this->m_bRespawning = 0;
  this->m_LastDamageType = 0;
  this->m_fImmuneToGunGameDamageTime = 0.0;
  this->m_fJustLeftImmunityTime = 0.0;
  this->m_lowHealthGoalTime = 0.0;
  if ( this->m_bGunGameImmunity.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v27 = this->m_Network.m_pPev;
      if ( v27 != nullptr )
        CBaseEdict::StateChanged(this: &v27->CBaseEdict, offset: 0x1311u);
    }
    this->m_bGunGameImmunity.m_Value = false;
  }
  this->m_iNumGunGameKillsWithCurrentWeapon = 0;
  if ( this->m_iNumGunGameTRKillPoints.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v28 = this->m_Network.m_pPev;
      if ( v28 != nullptr )
        CBaseEdict::StateChanged(this: &v28->CBaseEdict, offset: 0x1318u);
    }
    this->m_iNumGunGameTRKillPoints.m_Value = 0;
  }
  this->m_iNumGunGameTRBombTotalPoints = 0;
  *(_WORD *)&this->m_bShouldProgressGunGameTRBombModeWeapon = 0;
  *(_WORD *)&this->m_bGunGameTRModeHasHEGrenade = 0;
  this->m_bGunGameTRModeHasMolotov = false;
  if ( this->m_fMolotovUseTime.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v29 = this->m_Network.m_pPev;
      if ( v29 != nullptr )
        CBaseEdict::StateChanged(this: &v29->CBaseEdict, offset: 0x131Cu);
    }
    this->m_fMolotovUseTime.m_Value = 0.0;
  }
  if ( this->m_bIsControllingBot.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v30 = this->m_Network.m_pPev;
      if ( v30 != nullptr )
        CBaseEdict::StateChanged(this: &v30->CBaseEdict, offset: 0x1B6Bu);
    }
    this->m_bIsControllingBot.m_Value = false;
  }
  if ( this->m_bCanControlObservedBot.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v31 = this->m_Network.m_pPev;
      if ( v31 != nullptr )
        CBaseEdict::StateChanged(this: &v31->CBaseEdict, offset: 0x1B6Cu);
    }
    this->m_bCanControlObservedBot.m_Value = false;
  }
  if ( this->m_iControlledBotEntIndex.m_Value != -1 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v32 = this->m_Network.m_pPev;
      if ( v32 != nullptr )
        CBaseEdict::StateChanged(this: &v32->CBaseEdict, offset: 0x1B70u);
    }
    this->m_iControlledBotEntIndex.m_Value = -1;
  }
  this->m_bVote = false;
  this->m_botsControlled = 0;
  this->m_iFootsteps = 0;
  this->m_iMediumHealthKills = 0;
  ConVarRef::ConVarRef(this: &v35, pName: "score_default");
  m_nValue = v35.m_pConVarState->m_Value.m_nValue;
  this->m_iRoundScore = 0;
  this->m_iRoundProximityScore = 0;
  this->m_iContributionScore = 0;
  this->m_iScore = m_nValue;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1028FC20
// Name: public: virtual bool CCSPlayer::IsBeingGivenItem(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSPlayer::IsBeingGivenItem(CCSPlayer *this)
{
  return this->m_bIsBeingGivenItem;
}

//------------------------------------------------------------------------------
// Address: 0x1028FC30
// Name: protected: virtual int CCSPlayer::SpawnArmorValue(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSPlayer::SpawnArmorValue(CCSPlayer *this)
{
  return this->m_ArmorValue.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x1028FC40
// Name: public: virtual CCSPlayer::~CCSPlayer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::~CCSPlayer(CCSPlayer *this)
{
  CHintMessageQueue *m_pHintMessageQueue; // edi
  void (__thiscall ***v3)(_DWORD); // ecx

  m_pHintMessageQueue = this->m_pHintMessageQueue;
  this->CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CCSPlayer_vtbl *)&CCSPlayer::`vftable'{for `CBasePlayer'};
  this->CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CAI_ExpresserSink::__vftable = (CAI_ExpresserSink_vtbl *)&CCSPlayer::`vftable'{for `CAI_ExpresserSink'};
  this->ICSPlayerAnimStateHelpers::__vftable = (ICSPlayerAnimStateHelpers_vtbl *)&CCSPlayer::`vftable';
  if ( m_pHintMessageQueue != nullptr )
  {
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&m_pHintMessageQueue->m_messages);
    free(pMem: m_pHintMessageQueue);
  }
  this->m_pHintMessageQueue = nullptr;
  CUtlLinkedList<CDamageRecord *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CDamageRecord *,int>,int>>::PurgeAndDeleteElements(this: &this->m_DamageGivenList);
  CUtlLinkedList<CDamageRecord *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CDamageRecord *,int>,int>>::PurgeAndDeleteElements(this: &this->m_DamageTakenList);
  v3 = (void (__thiscall ***)(_DWORD))&this->m_PlayerAnimState->gap4[*(_DWORD *)(*(_DWORD *)this->m_PlayerAnimState->gap4
                                                                               + 4)];
  (**v3)(a1: v3);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_BurnDamageDeltVec);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_WeaponTypesRunningOutOfAmmo);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_WeaponTypesHeld);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_WeaponTypesUsed);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_killWeapons);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_enemyPlayersKilledThisRound);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_killTimes);
  CUtlDict<float,int>::RemoveAll(this: &this->m_RateLimitLastCommandTimes);
  CUtlRBTree<CUtlMap<char const *,float,int>::Node_t,int,CUtlMap<char const *,float,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,float,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,float,int>::Node_t,int,CUtlMap<char const *,float,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,float,int>::Node_t,int>,int>>(this: &this->m_RateLimitLastCommandTimes.m_Elements.m_Tree);
  CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&this->m_DamageTakenList);
  if ( this->m_DamageTakenList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_DamageTakenList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_DamageTakenList.m_Memory.m_pMemory);
      this->m_DamageTakenList.m_Memory.m_pMemory = nullptr;
    }
    this->m_DamageTakenList.m_Memory.m_nAllocationCount = 0;
  }
  CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>>::RemoveAll(this: (CUtlLinkedList<vgui::TreeNode *,int,0,int,CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> > *)&this->m_DamageGivenList);
  if ( this->m_DamageGivenList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_DamageGivenList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_DamageGivenList.m_Memory.m_pMemory);
      this->m_DamageGivenList.m_Memory.m_pMemory = nullptr;
    }
    this->m_DamageGivenList.m_Memory.m_nAllocationCount = 0;
  }
  CBaseMultiplayerPlayer::~CBaseMultiplayerPlayer(this);
}

//------------------------------------------------------------------------------
// Address: 0x1028FDB0
// Name: public: virtual void CCSPlayer::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::Spawn(CCSPlayer *this)
{
  CCSPlayer_vtbl *v2; // edi
  const CViewVectors *v3; // eax
  float m_Value; // xmm1_4
  edict_t *m_pPev; // ecx
  edict_t *v6; // ecx
  double v7; // st7
  bool v8; // zf
  edict_t *v9; // ecx
  edict_t *v10; // ecx
  CHintMessageQueue *m_pHintMessageQueue; // ecx
  CCSPlayerStateInfo *m_pCurStateInfo; // eax
  CSPlayerState v13; // edi
  void (__thiscall *pfnLeaveState)(char *); // edx
  edict_t *v15; // ecx
  edict_t *v16; // ecx
  unsigned int m_Index; // ecx
  int v18; // eax
  CEntInfo *v19; // edx
  unsigned int v20; // ecx
  int v21; // eax
  CBaseEntity **v22; // eax
  CBaseEntity *v23; // eax
  unsigned int v24; // eax
  edict_t *v25; // ecx
  CHintMessageQueue *v26; // ecx
  CBaseEdict *v27; // ecx
  CBaseCombatWeapon *ActiveWeapon; // eax
  CGlobalVars *v29; // ebx
  double v30; // st7
  edict_t *v31; // ecx
  edict_t *v32; // ecx
  edict_t *v33; // ecx
  ConVarRef mp_gungameimmunitytime; // [esp+1Ch] [ebp-10h] BYREF
  float v35; // [esp+24h] [ebp-8h]
  float v36; // [esp+28h] [ebp-4h]

  CUtlDict<float,int>::RemoveAll(this: &this->m_RateLimitLastCommandTimes);
  CCSPlayer::SetProgressBarTime(this, barTime: 0);
  this->CreateViewModel(this, a2: 1);
  CCSPlayer::SetModelFromClass(this);
  CBaseMultiplayerPlayer::Spawn(this);
  this->m_lastNavArea = nullptr;
  CBaseEntity::AddFlag(this, flags: 1);
  v2 = this->CBaseMultiplayerPlayer::CAI_ExpresserHost<CBasePlayer>::CBasePlayer::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  v3 = g_pGameRules->GetViewVectors(this: g_pGameRules);
  v2->SetViewOffset(this, a2: &v3->m_vView);
  m_Value = this->m_flMaxspeed.m_Value;
  v36 = 260.0;
  if ( m_Value != 260.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xED4u);
    }
    this->m_flMaxspeed.m_Value = v36;
  }
  CBasePlayer::SetFOV(this, pRequester: this, FOV: 0, zoomRate: 0.0, iZoomStart: 0);
  if ( this->m_bIsDefusing.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = this->m_Network.m_pPev;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: &v6->CBaseEdict, offset: 0x1310u);
    }
    this->m_bIsDefusing.m_Value = false;
  }
  v7 = _RandomFloat(this: (IUniformRandomStream *)v6, a2: 0.0, a3: 0.5) + gpGlobals->curtime;
  v8 = this->m_iPlayerState.m_Value == STATE_OBSERVER_MODE;
  *(_WORD *)&this->m_bIsRescuing = 0;
  this->m_flNextAutoBuyAmmoTime = v7;
  this->m_iNumFollowers = 0;
  if ( !v8 )
    this->m_wasNotKilledNaturally = false;
  this->m_bulletsFiredSinceLastSpawn = 0;
  if ( this->m_iShotsFired.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v9 = this->m_Network.m_pPev;
      if ( v9 != nullptr )
        CBaseEdict::StateChanged(this: &v9->CBaseEdict, offset: 0x1788u);
    }
    this->m_iShotsFired.m_Value = 0;
  }
  if ( this->m_iDirection.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v10 = this->m_Network.m_pPev;
      if ( v10 != nullptr )
        CBaseEdict::StateChanged(this: &v10->CBaseEdict, offset: 0x1784u);
    }
    this->m_iDirection.m_Value = 0;
  }
  m_pHintMessageQueue = this->m_pHintMessageQueue;
  if ( m_pHintMessageQueue != nullptr )
    CHintMessageQueue::Reset(this: m_pHintMessageQueue);
  m_pCurStateInfo = this->m_pCurStateInfo;
  this->m_iDisplayHistoryBits &= 0xFFFFEBBD;
  v13 = this->m_iPlayerState.m_Value;
  if ( m_pCurStateInfo != nullptr )
  {
    pfnLeaveState = (void (__thiscall *)(char *))m_pCurStateInfo->pfnLeaveState;
    if ( pfnLeaveState != nullptr )
      pfnLeaveState(a1: (char *)this + DWORD1(m_pCurStateInfo->pfnLeaveState));
  }
  CCSPlayer::State_Enter(this, newState: v13);
  CCSPlayer::ClearFlashbangScreenFade(this);
  if ( this->m_flVelocityModifier.m_Value != 1.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v15 = this->m_Network.m_pPev;
      if ( v15 != nullptr )
        CBaseEdict::StateChanged(this: &v15->CBaseEdict, offset: 0x178Cu);
    }
    this->m_flVelocityModifier.m_Value = 1.0;
  }
  if ( this->m_flStamina.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v16 = this->m_Network.m_pPev;
      if ( v16 != nullptr )
        CBaseEdict::StateChanged(this: &v16->CBaseEdict, offset: 0x1780u);
    }
    this->m_flStamina.m_Value = 0.0;
  }
  ++this->m_iNumSpawns;
  this->m_flLastRadarUpdateTime = 0.0;
  if ( !engine->IsDedicatedServer(this: engine)
    && (int)g_pGameRules[131].__vftable < 2
    && TheNavMesh->m_isOutOfDate
    && this == UTIL_GetListenServerHost() )
  {
    ClientPrint(
      player: this,
      msg_dest: 4u,
      msg_name: "The Navigation Mesh was built using a different version of this map.",
      param1: nullptr,
      param2: nullptr,
      param3: nullptr,
      param4: nullptr);
  }
  this->m_bTeamChanged = false;
  this->m_iOldTeam = 0;
  this->m_iRadioMessages = 60;
  this->m_flRadioTime = gpGlobals->curtime;
  m_Index = this->m_hRagdoll.m_Value.m_Index;
  if ( m_Index != -1 )
  {
    v18 = (unsigned __int16)m_Index;
    v19 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v20 = HIWORD(m_Index);
    if ( v19->m_SerialNumber == v20 && v19->m_pEntity != nullptr )
    {
      v21 = v18;
      v8 = g_pEntityList->m_EntPtrArray[v21].m_SerialNumber == v20;
      v22 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v21];
      if ( v8 )
        v23 = *v22;
      else
        v23 = nullptr;
      UTIL_Remove(oldObj: v23);
    }
  }
  v24 = this->m_hRagdoll.m_Value.m_Index;
  if ( v24 != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)v24].m_SerialNumber == HIWORD(v24)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)v24].m_pEntity != nullptr )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v25 = this->m_Network.m_pPev;
      if ( v25 != nullptr )
        CBaseEdict::StateChanged(this: &v25->CBaseEdict, offset: 0x17D8u);
    }
    this->m_hRagdoll.m_Value.m_Index = -1;
  }
  if ( this->m_szNewName[0] != 0 )
  {
    CCSPlayer::ChangeName(this, pszNewName: this->m_szNewName);
    this->m_szNewName[0] = 0;
  }
  if ( this->m_bIsVIP && this->IsNetClient(this) )
  {
    v26 = this->m_pHintMessageQueue;
    if ( v26 != nullptr )
      CHintMessageQueue::AddMessage(this: v26, message: "#Hint_you_are_the_vip", duration: 6.0, args: nullptr);
  }
  this->m_bIsInAutoBuy = false;
  *(_WORD *)&this->m_bAutoReload = 0;
  this->m_NumEnemiesKilledThisSpawn = 0;
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CCSPlayer::PushawayThink,
    thinkTime: gpGlobals->curtime + 0.050000001,
    szContext: "CSPushawayThink");
  if ( CBaseCombatCharacter::GetActiveWeapon(this) != nullptr )
  {
    v27 = (CBaseEdict *)(this->m_afPhysicsFlags.m_Value >> 3);
    if ( (this->m_afPhysicsFlags.m_Value & 8) == 0 )
    {
      ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this);
      ActiveWeapon->Deploy(this: ActiveWeapon);
      v29 = gpGlobals;
      if ( this->m_flNextAttack.m_Value != gpGlobals->curtime )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v27 = &this->m_Network.m_pPev->CBaseEdict;
          if ( v27 != nullptr )
            CBaseEdict::StateChanged(this: v27, offset: 0x684u);
        }
        this->m_flNextAttack.m_Value = v29->curtime;
      }
    }
  }
  this->m_applyDeafnessTime = 0.0;
  this->m_lowHealthGoalTime = 0.0;
  if ( this->m_cycleLatch.m_Value != 0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v27 = &this->m_Network.m_pPev->CBaseEdict;
      if ( v27 != nullptr )
        CBaseEdict::StateChanged(this: v27, offset: 0x1984u);
    }
    this->m_cycleLatch.m_Value = 0;
  }
  v36 = _RandomFloat(this: (IUniformRandomStream *)v27, a2: 0.0, a3: 0.2);
  v30 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_cycleLatchTimer) + v36;
  v35 = v30;
  if ( this->m_cycleLatchTimer.m_timestamp.m_Value != v30 )
  {
    this->m_cycleLatchTimer.NetworkStateChanged(
      this: &this->m_cycleLatchTimer,
      a2: &this->m_cycleLatchTimer.m_timestamp);
    this->m_cycleLatchTimer.m_timestamp.m_Value = v35;
  }
  if ( this->m_cycleLatchTimer.m_duration.m_Value != v36 )
  {
    this->m_cycleLatchTimer.NetworkStateChanged(this: &this->m_cycleLatchTimer, a2: &this->m_cycleLatchTimer.m_duration);
    this->m_cycleLatchTimer.m_duration.m_Value = v36;
  }
  CCSPlayer::StockPlayerAmmo(this, pNewWeapon: nullptr);
  ConVarRef::ConVarRef(this: &mp_gungameimmunitytime, pName: "mp_gungameimmunitytime");
  if ( CCSGameRules::IsPlayingGunGameProgressive(this: (CCSGameRules *)g_pGameRules)
    || CCSGameRules::IsPlayingGunGameTRBomb(this: (CCSGameRules *)g_pGameRules) )
  {
    this->m_fImmuneToGunGameDamageTime = mp_gungameimmunitytime.m_pConVarState->m_Value.m_fValue + gpGlobals->curtime;
    if ( !this->m_bGunGameImmunity.m_Value )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v32 = this->m_Network.m_pPev;
        if ( v32 != nullptr )
          CBaseEdict::StateChanged(this: &v32->CBaseEdict, offset: 0x1311u);
      }
      this->m_bGunGameImmunity.m_Value = true;
    }
  }
  else
  {
    this->m_fImmuneToGunGameDamageTime = 0.0;
    if ( this->m_bGunGameImmunity.m_Value )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_bGunGameImmunity.m_Value = false;
      }
      else
      {
        v31 = this->m_Network.m_pPev;
        if ( v31 != nullptr )
          CBaseEdict::StateChanged(this: &v31->CBaseEdict, offset: 0x1311u);
        this->m_bGunGameImmunity.m_Value = false;
      }
    }
  }
  this->m_knifeKillsWhenOutOfAmmo = 0;
  this->m_botsControlled = 0;
  this->m_iFootsteps = 0;
  this->m_iMediumHealthKills = 0;
  this->m_killedTime = -1.0;
  this->m_spawnedTime = gpGlobals->curtime;
  if ( this->m_bKilledByTaser.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_bKilledByTaser.m_Value = false;
    }
    else
    {
      v33 = this->m_Network.m_pPev;
      if ( v33 != nullptr )
        CBaseEdict::StateChanged(this: &v33->CBaseEdict, offset: 0x1772u);
      this->m_bKilledByTaser.m_Value = false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10290460
// Name: public: virtual void CCSPlayer::Event_Killed(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CCSPlayer::Event_Killed(
        CCSPlayer *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        const CTakeDamageInfo *info)
{
  float curtime; // xmm0_4
  float v7; // xmm0_4
  const CTakeDamageInfo *v8; // edi
  unsigned int m_Index; // eax
  CEntInfo *v10; // ecx
  IHandleEntity *m_pEntity; // esi
  CCSPlayer *v12; // eax
  unsigned int v13; // eax
  CBaseEntity *v14; // ecx
  int TeamNumber; // esi
  unsigned int v16; // eax
  CEntInfo *v17; // ecx
  IHandleEntity *v18; // esi
  CBaseCombatCharacter *v19; // eax
  CCSPlayer *v20; // edi
  CBaseCombatWeapon *ActiveWeapon; // eax
  CCSPlayer *v22; // eax
  edict_t *m_pPev; // ecx
  edict_t *v24; // ecx
  edict_t *v25; // ecx
  edict_t *v26; // ecx
  edict_t *v27; // ecx
  edict_t *v28; // ecx
  unsigned int v29; // eax
  CBaseEntity *v30; // ecx
  unsigned int v31; // eax
  float v32; // xmm1_4
  float v33; // xmm2_4
  CRagdollMagnet *BestMagnet; // eax
  Vector *ForceVector; // eax
  CCSPlayerStateInfo *m_pCurStateInfo; // eax
  void (__thiscall *pfnLeaveState)(char *); // edx
  edict_t *v38; // ecx
  int v39; // edi
  CBasePlayer *v40; // eax
  CBasePlayer *v41; // esi
  CCSPlayer *v42; // eax
  CSMvpReason_t v43; // ecx
  int v44; // eax
  CBasePlayer *v45; // esi
  CBaseEntity *v46; // eax
  CCSPlayer *v47; // esi
  CGameRules *v48; // edi
  int v49; // edi
  int v50; // eax
  bool (__thiscall *IsNetClient)(CBaseEntity *); // eax
  CHintMessageQueue *m_pHintMessageQueue; // ecx
  int v53; // [esp+8h] [ebp-88h]
  int v54; // [esp+Ch] [ebp-84h]
  int v55; // [esp+10h] [ebp-80h]
  CTakeDamageInfo subinfo; // [esp+14h] [ebp-7Ch] BYREF
  Vector result; // [esp+70h] [ebp-20h] BYREF
  CSMvpReason_t mvpReason; // [esp+7Ch] [ebp-14h]
  CCSPlayer *pMVP; // [esp+80h] [ebp-10h]
  int i; // [esp+84h] [ebp-Ch]
  int maxDamage; // [esp+88h] [ebp-8h]
  bool friendlyFire; // [esp+8Fh] [ebp-1h]
  int maxKills; // [esp+98h] [ebp+8h]
  bool maxKills_3; // [esp+9Bh] [ebp+Bh]

  curtime = gpGlobals->curtime;
  v55 = a2;
  this->m_killedTime = curtime;
  v7 = curtime - this->m_spawnedTime;
  if ( v7 > this->m_longestLife )
    this->m_longestLife = v7;
  v54 = a4;
  v53 = a3;
  v8 = info;
  m_Index = info->m_hAttacker.m_Index;
  if ( m_Index != -1
    && (v10 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index))
    && (m_pEntity = v10->m_pEntity, v10->m_pEntity != nullptr)
    && ((unsigned __int8 (__thiscall *)(IHandleEntity *, int, int, int))m_pEntity->__vftable[28].dtr_IHandleEntity)(
         a1: v10->m_pEntity,
         a2: v53,
         a3: v54,
         a4: v55) != 0 )
  {
    v12 = (CCSPlayer *)__RTDynamicCast(
                         inptr: m_pEntity,
                         VfDelta: 0,
                         SrcType: &CBaseEntity `RTTI Type Descriptor',
                         TargetType: &CCSPlayer `RTTI Type Descriptor',
                         isReference: 0);
  }
  else
  {
    v12 = nullptr;
  }
  CCSPlayer::ProcessPlayerDeathAchievements(pAttacker: v12, pVictim: this, info);
  CBasePlayer::SetArmorValue(this, value: 0);
  v13 = info->m_hAttacker.m_Index;
  if ( v13 == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_SerialNumber != HIWORD(v13)
    || (v14 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_pEntity) == nullptr
    || (TeamNumber = CBaseEntity::GetTeamNumber(this: v14),
        friendlyFire = true,
        TeamNumber != CBaseEntity::GetTeamNumber(this)) )
  {
    friendlyFire = false;
  }
  v16 = info->m_hAttacker.m_Index;
  if ( v16 != -1 )
  {
    v17 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v16];
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v16].m_SerialNumber == HIWORD(v16) )
    {
      v18 = v17->m_pEntity;
      if ( v17->m_pEntity != nullptr
        && ((unsigned __int8 (__thiscall *)(IHandleEntity *))v18->__vftable[28].dtr_IHandleEntity)(a1: v17->m_pEntity) != 0 )
      {
        v19 = (CBaseCombatCharacter *)__RTDynamicCast(
                                        inptr: v18,
                                        VfDelta: 0,
                                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                                        TargetType: &CCSPlayer `RTTI Type Descriptor',
                                        isReference: 0);
        v20 = (CCSPlayer *)v19;
        if ( v19 != nullptr )
        {
          ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: v19);
          v22 = (CCSPlayer *)__RTDynamicCast(
                               inptr: ActiveWeapon,
                               VfDelta: 0,
                               SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
                               TargetType: &CWeaponCSBase `RTTI Type Descriptor',
                               isReference: 0);
          pMVP = v22;
          if ( v22 != nullptr && v22->FlashlightIsOn(this: v22) == 22 && !this->m_bKilledByTaser.m_Value )
          {
            if ( this->m_Network.m_TimerEvent.m_bRegistered )
            {
              *((_BYTE *)&this->m_Network + 76) |= 1u;
            }
            else
            {
              m_pPev = this->m_Network.m_pPev;
              if ( m_pPev != nullptr )
                CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x1772u);
            }
            this->m_bKilledByTaser.m_Value = true;
          }
          CCSPlayer::HandleOutOfAmmoKnifeKills(
            this,
            a2: (int)v18,
            pAttackerPlayer: v20,
            pAttackerWeapon: (CWeaponCSBase *)pMVP);
        }
        v8 = info;
      }
    }
  }
  CCSPlayer::DropWeapons(this, a2: this, fromDeath: true, friendlyFire: !friendlyFire);
  CCSPlayer::SetProgressBarTime(this, barTime: 0);
  if ( this->m_bIsDefusing.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v24 = this->m_Network.m_pPev;
      if ( v24 != nullptr )
        CBaseEdict::StateChanged(this: &v24->CBaseEdict, offset: 0x1310u);
    }
    this->m_bIsDefusing.m_Value = false;
  }
  if ( this->m_bHasNightVision.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v25 = this->m_Network.m_pPev;
      if ( v25 != nullptr )
        CBaseEdict::StateChanged(this: &v25->CBaseEdict, offset: 0x135Du);
    }
    this->m_bHasNightVision.m_Value = false;
  }
  if ( this->m_bNightVisionOn.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v26 = this->m_Network.m_pPev;
      if ( v26 != nullptr )
        CBaseEdict::StateChanged(this: &v26->CBaseEdict, offset: 0x135Eu);
    }
    this->m_bNightVisionOn.m_Value = false;
  }
  *(_WORD *)&this->m_bPickedUpDefuser = 0;
  this->m_bPickedUpWeapon = false;
  this->m_bAttemptedDefusal = false;
  if ( this->m_bHasHelmet.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v27 = this->m_Network.m_pPev;
      if ( v27 != nullptr )
        CBaseEdict::StateChanged(this: &v27->CBaseEdict, offset: 0x1324u);
    }
    this->m_bHasHelmet.m_Value = false;
  }
  if ( this->m_flFlashDuration.m_Value != 0.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v28 = this->m_Network.m_pPev;
      if ( v28 != nullptr )
        CBaseEdict::StateChanged(this: &v28->CBaseEdict, offset: 0x17C4u);
    }
    this->m_flFlashDuration.m_Value = 0.0;
  }
  ((void (__thiscall *)(CCSPlayer *, _DWORD, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, unsigned int, unsigned int, unsigned int, _DWORD, _DWORD, _DWORD, int, int, int, int, _DWORD, int, int, unsigned int, _DWORD, _DWORD, _DWORD, CSMvpReason_t, CCSPlayer *, int))this->FlashlightTurnOff)(
    a1: this,
    a2: 0,
    a3: v53,
    a4: v54,
    a5: v55,
    a6: LODWORD(subinfo.m_vecDamageForce.x),
    a7: LODWORD(subinfo.m_vecDamageForce.y),
    a8: LODWORD(subinfo.m_vecDamageForce.z),
    a9: LODWORD(subinfo.m_vecDamagePosition.x),
    a10: LODWORD(subinfo.m_vecDamagePosition.y),
    a11: LODWORD(subinfo.m_vecDamagePosition.z),
    a12: LODWORD(subinfo.m_vecReportedPosition.x),
    a13: LODWORD(subinfo.m_vecReportedPosition.y),
    a14: LODWORD(subinfo.m_vecReportedPosition.z),
    a15: subinfo.m_hInflictor.m_Index,
    a16: subinfo.m_hAttacker.m_Index,
    a17: subinfo.m_hWeapon.m_Index,
    a18: LODWORD(subinfo.m_flDamage),
    a19: LODWORD(subinfo.m_flMaxDamage),
    a20: LODWORD(subinfo.m_flBaseDamage),
    a21: subinfo.m_bitsDamageType,
    a22: subinfo.m_iDamageCustom,
    a23: subinfo.m_iDamageStats,
    a24: subinfo.m_iAmmoType,
    a25: LODWORD(subinfo.m_flRadius),
    a26: subinfo.m_iDamagedOtherPlayers,
    a27: subinfo.m_iObjectsPenetrated,
    a28: subinfo.m_uiBulletID,
    a29: LODWORD(result.x),
    a30: LODWORD(result.y),
    a31: LODWORD(result.z),
    a32: mvpReason,
    a33: pMVP,
    a34: i);
  v29 = v8->m_hAttacker.m_Index;
  if ( v29 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v29].m_SerialNumber != HIWORD(v29) )
    v30 = nullptr;
  else
    v30 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v29].m_pEntity;
  if ( this->IsValidObserverTarget(this, a2: v30) )
  {
    v31 = v8->m_hAttacker.m_Index;
    if ( v31 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v31].m_SerialNumber != HIWORD(v31) )
      this->SetObserverTarget(this, a2: nullptr);
    else
      this->SetObserverTarget(this, a2: (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v31].m_pEntity);
  }
  else
  {
    this->ResetObserverMode(this);
  }
  CTakeDamageInfo::CTakeDamageInfo(this: &subinfo, __that: v8);
  v32 = this->m_vecTotalBulletForce.y * 2.0;
  v33 = this->m_vecTotalBulletForce.z * 2.0;
  subinfo.m_vecDamageForce.x = this->m_vecTotalBulletForce.x * 2.0;
  subinfo.m_vecDamageForce.y = v32;
  subinfo.m_vecDamageForce.z = v33;
  CCSPlayer::SelectDeathPose(this, info: v8);
  BestMagnet = CRagdollMagnet::FindBestMagnet(pNPC: this);
  if ( BestMagnet != nullptr )
  {
    ForceVector = CRagdollMagnet::GetForceVector(this: BestMagnet, &result, pNPC: this);
    this->m_vecTotalBulletForce.x = this->m_vecTotalBulletForce.x + ForceVector->x;
    this->m_vecTotalBulletForce.y = ForceVector->y + this->m_vecTotalBulletForce.y;
    this->m_vecTotalBulletForce.z = ForceVector->z + this->m_vecTotalBulletForce.z;
  }
  this->CreateRagdollEntity(this);
  m_pCurStateInfo = this->m_pCurStateInfo;
  if ( m_pCurStateInfo != nullptr )
  {
    pfnLeaveState = (void (__thiscall *)(char *))m_pCurStateInfo->pfnLeaveState;
    if ( pfnLeaveState != nullptr )
      pfnLeaveState(a1: (char *)this + DWORD1(m_pCurStateInfo->pfnLeaveState));
  }
  CCSPlayer::State_Enter(this, newState: STATE_DEATH_ANIM);
  CBasePlayer::Event_Killed(this, info: &subinfo);
  if ( CCSGameRules::IsPlayingGunGameTRBomb(this: (CCSGameRules *)g_pGameRules) )
  {
    *(_WORD *)&this->m_bGunGameTRModeHasHEGrenade = 0;
    this->m_bGunGameTRModeHasMolotov = false;
  }
  if ( CCSGameRules::IsPlayingGunGameProgressive(this: (CCSGameRules *)g_pGameRules) )
  {
    maxKills_3 = g_pGameRules[130].m_pszName != nullptr;
    friendlyFire = CCSGameRules::CheckWinConditions(this: (CCSGameRules *)g_pGameRules);
    if ( friendlyFire )
    {
      this->m_bMadeFinalGunGameProgressiveKill = false;
      if ( this->m_iGunGameProgressiveWeaponIndex.m_Value != 0 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
          this->m_iGunGameProgressiveWeaponIndex.m_Value = 0;
        }
        else
        {
          v38 = this->m_Network.m_pPev;
          if ( v38 != nullptr )
            CBaseEdict::StateChanged(this: &v38->CBaseEdict, offset: 0x1314u);
          this->m_iGunGameProgressiveWeaponIndex.m_Value = 0;
        }
      }
    }
  }
  else
  {
    maxKills_3 = g_pGameRules[130].m_pszName != nullptr;
    friendlyFire = CCSGameRules::CheckWinConditions(this: (CCSGameRules *)g_pGameRules);
  }
  if ( !maxKills_3 && friendlyFire )
  {
    pMVP = nullptr;
    maxKills = 0;
    maxDamage = 0;
    mvpReason = CSMVP_ELIMINATION;
    if ( CCSGameRules::IsPlayingGunGameProgressive(this: (CCSGameRules *)g_pGameRules) )
    {
      v39 = 1;
      if ( gpGlobals->maxClients < 1 )
        goto LABEL_109;
      while ( 1 )
      {
        v40 = UTIL_PlayerByIndex(playerIndex: v39);
        v41 = v40;
        if ( v40 != nullptr && v40->IsPlayer(this: v40) )
        {
          v42 = (CCSPlayer *)__RTDynamicCast(
                               inptr: v41,
                               VfDelta: 0,
                               SrcType: &CBaseEntity `RTTI Type Descriptor',
                               TargetType: &CCSPlayer `RTTI Type Descriptor',
                               isReference: 0);
          if ( v42 != nullptr && v42->m_bMadeFinalGunGameProgressiveKill )
            break;
        }
        if ( ++v39 > gpGlobals->maxClients )
          goto LABEL_109;
      }
      v43 = CSMVP_GUNGAMEWINNER;
    }
    else
    {
      v44 = 1;
      i = 1;
      if ( gpGlobals->maxClients < 1 )
        goto LABEL_109;
      do
      {
        v45 = UTIL_PlayerByIndex(playerIndex: v44);
        if ( v45 != nullptr && v45->IsPlayer(this: v45) )
        {
          v46 = (CBaseEntity *)__RTDynamicCast(
                                 inptr: v45,
                                 VfDelta: 0,
                                 SrcType: &CBaseEntity `RTTI Type Descriptor',
                                 TargetType: &CCSPlayer `RTTI Type Descriptor',
                                 isReference: 0);
          v47 = (CCSPlayer *)v46;
          if ( v46 != nullptr )
          {
            v48 = g_pGameRules;
            if ( (const char *)CBaseEntity::GetTeamNumber(this: v46) == v48[130].m_pszName )
            {
              v49 = CCSGameStats::FindPlayerStats(this: &CCS_GameStats, pPlayer: v47)->statsCurrentRound.m_iValue[2];
              v50 = CCSGameStats::FindPlayerStats(this: &CCS_GameStats, pPlayer: v47)->statsCurrentRound.m_iValue[4];
              if ( v49 > maxKills || v49 == maxKills && v50 > maxDamage )
              {
                pMVP = v47;
                maxKills = v49;
                maxDamage = v50;
              }
            }
          }
        }
        v44 = i + 1;
        i = v44;
      }
      while ( v44 <= gpGlobals->maxClients );
      v43 = mvpReason;
      v42 = pMVP;
    }
    if ( v42 != nullptr )
      CCSPlayer::IncrementNumMVPs(this: v42, mvpReason: v43);
  }
LABEL_109:
  CCSPlayer::OutputDamageGiven(this);
  CCSPlayer::OutputDamageTaken(this);
  CUtlLinkedList<CDamageRecord *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CDamageRecord *,int>,int>>::PurgeAndDeleteElements(this: &this->m_DamageGivenList);
  CUtlLinkedList<CDamageRecord *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CDamageRecord *,int>,int>>::PurgeAndDeleteElements(this: &this->m_DamageTakenList);
  if ( this->m_bPunishedForTK )
  {
    IsNetClient = this->IsNetClient;
    this->m_bPunishedForTK = false;
    if ( IsNetClient(this) )
    {
      m_pHintMessageQueue = this->m_pHintMessageQueue;
      if ( m_pHintMessageQueue != nullptr )
        CHintMessageQueue::AddMessage(
          this: m_pHintMessageQueue,
          message: "#Hint_cannot_play_because_tk",
          duration: 6.0,
          args: nullptr);
    }
  }
  if ( this->m_bIsControllingBot.m_Value )
    CCSPlayer::ReleaseControlOfBot(this);
}

//------------------------------------------------------------------------------
// Address: 0x10290B80
// Name: public: virtual int CCSPlayer::OnTakeDamage(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CCSPlayer::OnTakeDamage@<eax>(
        CCSPlayer *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        const CTakeDamageInfo *inputInfo)
{
  unsigned __int8 m_Value; // al
  CBaseEntity *Attacker; // eax
  CCSPlayer *v8; // eax
  CCSPlayer *v9; // ebx
  int TeamNumber; // edi
  bool v11; // zf
  int v12; // edi
  int v13; // eax
  int v14; // eax
  CTeam *GlobalTeam; // edi
  int (__thiscall *GetNumPlayers)(CTeam *); // eax
  CBaseEntity *v17; // eax
  CCSPlayer *v18; // eax
  int (__thiscall *v19)(CTeam *); // edx
  int v20; // eax
  CHintMessageQueue *m_pHintMessageQueue; // ecx
  float curtime; // xmm0_4
  const char *(__thiscall *GetPlayerName)(CBaseEntity *); // eax
  const char *v24; // eax
  int v25; // eax
  CBasePlayer *v26; // eax
  int v27; // edi
  const char *v28; // eax
  float v29; // xmm0_4
  CBaseEntity *m_pEntity; // eax
  CCSPlayer *v31; // eax
  CWeaponCSBase *ActiveCSWeapon; // eax
  CCSWeaponInfo *CSWpnData; // eax
  CBaseEntity *v34; // edi
  void *v35; // eax
  int m_LastHitGroup; // ecx
  float m_fFlinchVelocityModifierSmall; // xmm0_4
  edict_t *v38; // eax
  void *v39; // eax
  CCSWeaponInfo *WeaponInfo; // eax
  float v41; // xmm0_4
  CWeaponCSBase *v42; // eax
  CWeaponCSBase *v43; // edi
  bool v44; // al
  int v45; // edi
  float v46; // xmm2_4
  float v47; // xmm0_4
  float v48; // xmm1_4
  int v49; // eax
  float v50; // xmm0_4
  double v51; // xmm0_8
  edict_t *m_pPev; // ecx
  CBaseEntity *Inflictor; // eax
  const Vector *v54; // eax
  float m_flDamage; // xmm0_4
  int v56; // eax
  CBaseEntity *v57; // eax
  CCSPlayer *v58; // eax
  CBaseMultiplayerPlayer *v59; // ebx
  int v60; // edi
  int m_Head; // edi
  int v62; // edi
  const char *v63; // eax
  CCSPlayer *v64; // edi
  CDamageRecord *v65; // eax
  CDamageRecord *v66; // eax
  int v67; // esi
  CDamageRecord *m_Element; // [esp+Ch] [ebp-A8h]
  int v71; // [esp+10h] [ebp-A4h]
  CSingleUserRecipientFilter user; // [esp+18h] [ebp-9Ch] BYREF
  CTakeDamageInfo info; // [esp+38h] [ebp-7Ch] BYREF
  CCSPlayer *pAttacker; // [esp+94h] [ebp-20h]
  void *inptr; // [esp+98h] [ebp-1Ch]
  float flArmorRatio; // [esp+9Ch] [ebp-18h]
  int i; // [esp+A0h] [ebp-14h]
  CBasePlayer *pPlayer; // [esp+A4h] [ebp-10h]
  bool bDamageIsFromGunfire; // [esp+AAh] [ebp-Ah]
  bool bDamageIsFromSelf; // [esp+ABh] [ebp-9h]
  float flDamage; // [esp+ACh] [ebp-8h]
  bool bFriendlyFireEnabled; // [esp+B2h] [ebp-2h]
  bool bDamageIsFromOpponent; // [esp+B3h] [ebp-1h]
  int savedregs; // [esp+B4h] [ebp+0h] BYREF
  float fDamageToHealth; // [esp+BCh] [ebp+8h]
  char fDamageToHealth_3; // [esp+BFh] [ebp+Bh]

  if ( this->m_bGunGameImmunity.m_Value )
    return 0;
  CTakeDamageInfo::CTakeDamageInfo(this: &info, __that: inputInfo);
  if ( info.m_hInflictor.m_Index == -1 )
    return 0;
  if ( g_pEntityList->m_EntPtrArray[LOWORD(info.m_hInflictor.m_Index)].m_SerialNumber != HIWORD(info.m_hInflictor.m_Index) )
    return 0;
  inptr = g_pEntityList->m_EntPtrArray[LOWORD(info.m_hInflictor.m_Index)].m_pEntity;
  if ( inptr == nullptr )
    return 0;
  m_Value = this->m_MoveType.m_Value;
  if ( m_Value == 8 || m_Value == 10 )
    return 0;
  flArmorRatio = 0.5;
  flDamage = info.m_flDamage;
  bFriendlyFireEnabled = CCSBotManager::AllowFriendlyFireDamage(this: (CCSGameRules *)g_pGameRules);
  this->m_LastDamageType = info.m_bitsDamageType;
  CCSGameRules::PlayerTookDamage(this: (CCSGameRules *)g_pGameRules, player: this, damageInfo: inputInfo);
  Attacker = CTakeDamageInfo::GetAttacker(this: &info);
  v8 = ToCSPlayer(pEntity: Attacker);
  v9 = v8;
  pAttacker = v8;
  if ( v8 == nullptr
    || (TeamNumber = CBaseEntity::GetTeamNumber(this: v8)) != CBaseEntity::GetTeamNumber(this)
    || (fDamageToHealth_3 = 1, v11 = v9 == this) )
  {
    fDamageToHealth_3 = 0;
    v11 = v9 == this;
  }
  bDamageIsFromSelf = v11;
  bDamageIsFromGunfire = v9 == inptr;
  if ( v9 == nullptr
    || (v12 = CBaseEntity::GetTeamNumber(this: v9),
        v13 = CBaseEntity::GetTeamNumber(this),
        bDamageIsFromOpponent = true,
        v12 == v13) )
  {
    bDamageIsFromOpponent = false;
  }
  if ( this->m_bIsDefusing.m_Value && this->m_gooseChaseStep == GC_NONE )
  {
    if ( fDamageToHealth_3 == 0 )
      goto LABEL_26;
    i = 0;
    v14 = CBaseEntity::GetTeamNumber(this: v9);
    GlobalTeam = GetGlobalTeam(iIndex: v14);
    GetNumPlayers = GlobalTeam->GetNumPlayers;
    pPlayer = nullptr;
    if ( GetNumPlayers(this: GlobalTeam) > 0 )
    {
      do
      {
        v17 = GlobalTeam->GetPlayer(this: GlobalTeam, a2: (int)pPlayer);
        v18 = ToCSPlayer(pEntity: v17);
        if ( v18 != nullptr && v18->m_lifeState.m_Value == 0 )
          ++i;
        v19 = GlobalTeam->GetNumPlayers;
        pPlayer = (CBasePlayer *)((char *)pPlayer + 1);
        v20 = v19(this: GlobalTeam);
      }
      while ( (int)pPlayer < v20 );
      if ( i == 1 )
      {
        this->m_gooseChaseStep = GC_SHOT_DURING_DEFUSE;
        CHandle<CBaseEntity>::operator=(this: (CHandle<CBaseEntity> *)&this->m_pGooseChaseDistractingPlayer, val: v9);
      }
    }
  }
  if ( fDamageToHealth_3 == 0 )
  {
LABEL_26:
    if ( !bDamageIsFromSelf )
      goto LABEL_28;
  }
  CCSGameRules::ScoreFriendlyFire(this: (CCSGameRules *)g_pGameRules, pPlayer: v9, fDamage: flDamage);
LABEL_28:
  if ( bFriendlyFireEnabled )
  {
    if ( fDamageToHealth_3 == 0 )
      goto LABEL_48;
    if ( v9 != nullptr )
    {
      if ( (v9->m_iDisplayHistoryBits & 0x200) == 0 )
      {
        if ( v9->IsAlive(this: v9) && v9->IsNetClient(this: v9) )
        {
          m_pHintMessageQueue = v9->m_pHintMessageQueue;
          if ( m_pHintMessageQueue != nullptr && v9->m_bShowHints )
            CHintMessageQueue::AddMessage(
              this: m_pHintMessageQueue,
              message: "#Hint_try_not_to_injure_teammates",
              duration: 6.0,
              args: nullptr);
        }
        v9->m_iDisplayHistoryBits |= 0x200u;
      }
      curtime = gpGlobals->curtime;
      if ( curtime > (float)(v9->m_flLastAttackedTeammate + 0.60000002) )
      {
        GetPlayerName = v9->GetPlayerName;
        v9->m_flLastAttackedTeammate = curtime;
        v24 = GetPlayerName(this: v9);
        _Msg(a1: "%s attacked a teammate\n", v24);
        v25 = 1;
        for ( i = 1; v25 <= gpGlobals->maxClients; i = v25 )
        {
          v26 = UTIL_PlayerByIndex(playerIndex: v25);
          pPlayer = v26;
          if ( v26 != nullptr )
          {
            v27 = CBaseEntity::GetTeamNumber(this: v26);
            if ( v27 == CBaseEntity::GetTeamNumber(this) )
            {
              v28 = v9->GetPlayerName(this: v9);
              ClientPrint(
                player: pPlayer,
                msg_dest: 3u,
                msg_name: "#Game_teammate_attack",
                param1: v28,
                param2: nullptr,
                param3: nullptr,
                param4: nullptr);
            }
          }
          v25 = i + 1;
        }
      }
    }
  }
  if ( fDamageToHealth_3 == 0 )
  {
LABEL_48:
    if ( !bFriendlyFireEnabled )
      goto LABEL_52;
  }
  else if ( !bFriendlyFireEnabled )
  {
    if ( bDamageIsFromGunfire )
      return 0;
LABEL_52:
    if ( info.m_hInflictor.m_Index == -1
      || g_pEntityList->m_EntPtrArray[LOWORD(info.m_hInflictor.m_Index)].m_SerialNumber != HIWORD(info.m_hInflictor.m_Index) )
    {
      m_pEntity = nullptr;
    }
    else
    {
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[LOWORD(info.m_hInflictor.m_Index)].m_pEntity;
    }
    v31 = ToCSPlayer(pEntity: m_pEntity);
    if ( v31 != nullptr )
    {
      ActiveCSWeapon = CCSPlayer::GetActiveCSWeapon(this: v31);
      if ( ActiveCSWeapon != nullptr )
      {
        CSWpnData = (CCSWeaponInfo *)CWeaponCSBase::GetCSWpnData(this: ActiveCSWeapon);
        if ( CSWpnData != nullptr )
        {
          v34 = (CBaseEntity *)inptr;
          goto LABEL_66;
        }
      }
    }
    v34 = (CBaseEntity *)inptr;
    v35 = __RTDynamicCast(
            inptr,
            VfDelta: 0,
            SrcType: &CBaseEntity `RTTI Type Descriptor',
            TargetType: &CBaseCSGrenadeProjectile `RTTI Type Descriptor',
            isReference: 0);
    if ( v35 != nullptr && (CSWpnData = *((CCSWeaponInfo **)v35 + 304)) != nullptr
      || (v34->m_iClassname.pszValue == "inferno"
       || CBaseEntity::ClassMatchesComplex(this: v34, pszClassOrWildcard: "inferno") != 0)
      && (CSWpnData = GetWeaponInfo(weaponID: WEAPON_MOLOTOV)) != nullptr )
    {
LABEL_66:
      m_LastHitGroup = this->m_LastHitGroup;
      if ( (this->m_fFlags.m_Value & 2) != 0 || m_LastHitGroup == 6 || m_LastHitGroup == 7 )
        m_fFlinchVelocityModifierSmall = CSWpnData->m_fFlinchVelocityModifierSmall;
      else
        m_fFlinchVelocityModifierSmall = CSWpnData->m_fFlinchVelocityModifierLarge;
      CCSPlayer::SetFlinchVelocityModifier(this, fVelocityModifier: m_fFlinchVelocityModifierSmall);
    }
    if ( v9 == nullptr )
      goto LABEL_85;
    if ( (info.m_bitsDamageType & 8) != 0 )
    {
      v38 = CBaseEntity::entindex(this);
      CCSPlayer::AddBurnDamageDelt(this: v9, entityIndex: (vgui::TreeNode *)v38);
    }
    if ( (info.m_bitsDamageType & 0x40) == 0 )
    {
      v42 = CCSPlayer::GetActiveCSWeapon(this: v9);
      v43 = v42;
      if ( v42 != nullptr )
      {
        flArmorRatio = CWeaponCSBase::GetCSWpnData(this: v42)->m_flArmorRatio * 0.5;
        v44 = CWeaponCSBase::GetCSWpnData(this: v43)->m_WeaponType == WEAPONTYPE_KNIFE;
        if ( (info.m_bitsDamageType & 2) != 0 && !v44 && bDamageIsFromOpponent )
          CCSGameStats::Event_ShotHit(this: &CCS_GameStats, pPlayer: v9, &info);
      }
      goto LABEL_85;
    }
    v39 = __RTDynamicCast(
            inptr: v34,
            VfDelta: 0,
            SrcType: &CBaseEntity `RTTI Type Descriptor',
            TargetType: &CBaseCSGrenadeProjectile `RTTI Type Descriptor',
            isReference: 0);
    if ( v39 == nullptr || (WeaponInfo = *((CCSWeaponInfo **)v39 + 304)) == nullptr )
    {
      WeaponInfo = GetWeaponInfo(weaponID: WEAPON_HEGRENADE);
      if ( WeaponInfo == nullptr )
      {
LABEL_85:
        v41 = flArmorRatio;
        goto LABEL_86;
      }
    }
    v41 = WeaponInfo->m_flArmorRatio * 0.5;
LABEL_86:
    v45 = this->m_ArmorValue.m_Value;
    v46 = flDamage;
    this->m_lastDamageAmount = (int)flDamage;
    if ( v45 != 0
      && (info.m_bitsDamageType & 0x4020) == 0
      && CCSPlayer::IsArmored(this, nHitGroup: this->m_LastHitGroup) )
    {
      fDamageToHealth = v46 * v41;
      v47 = (float)(v46 - (float)(v46 * v41)) * 0.5;
      v48 = (float)v45;
      if ( v47 <= (float)v45 )
      {
        if ( v47 < 0.0 )
          v47 = 1.0;
        v49 = (int)(float)(v48 - v47);
      }
      else
      {
        fDamageToHealth = v46 - (float)(v48 * 2.0);
        v47 = (float)v45;
        v49 = 0;
      }
      this->m_lastDamageArmor = (int)v47;
      CBasePlayer::SetArmorValue(this, value: v49);
      if ( this->m_LastHitGroup == 1 && (v50 = (float)this->m_iHealth.m_Value, flDamage > v50) )
      {
        v46 = fDamageToHealth;
        if ( v50 > fDamageToHealth )
          this->m_bSurvivedHeadshotDueToHelmet = true;
      }
      else
      {
        v46 = fDamageToHealth;
      }
      v51 = (double)this->m_ArmorValue.m_Value;
      flDamage = v46;
      info.m_flDamage = v46;
      if ( v51 <= 0.0 && this->m_bHasHelmet.m_Value )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
          {
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x1324u);
            v46 = flDamage;
          }
        }
        this->m_bHasHelmet.m_Value = false;
      }
      if ( (info.m_bitsDamageType & 0x20) != 0 )
        goto LABEL_111;
      CCSPlayer::Pain(this, bHasArmour: true);
      goto LABEL_110;
    }
    v11 = (info.m_bitsDamageType & 0x20) == 0;
    this->m_lastDamageArmor = 0;
    if ( v11 )
    {
      CCSPlayer::Pain(this, bHasArmour: false);
LABEL_110:
      v46 = flDamage;
    }
LABEL_111:
    this->m_lastDamageHealth = (int)v46;
    info.m_flDamage = (float)(int)v46;
    if ( info.m_flDamage <= 0.0 )
      return 0;
    CRecipientFilter::CRecipientFilter(this: &user);
    user.__vftable = (CSingleUserRecipientFilter_vtbl *)&CSingleUserRecipientFilter::`vftable';
    CRecipientFilter::AddRecipient(this: &user, player: this);
    CRecipientFilter::MakeReliable(this: (CFmtStrN<1024> *)&user);
    UserMessageBegin(filter: &user, messagename: "Damage");
    MessageWriteByte(iValue: (int)info.m_flDamage);
    Inflictor = CTakeDamageInfo::GetInflictor(this: &info);
    v54 = (const Vector *)((int (__thiscall *)(CBaseEntity *, int, int))Inflictor->WorldSpaceCenter)(
                            a1: Inflictor,
                            a2,
                            a3);
    MessageWriteVec3Coord(rgflValue: v54);
    MessageEnd();
    if ( (info.m_bitsDamageType & 0x40) != 0 )
      this->OnDamagedByExplosion(this, a2: &info);
    m_flDamage = info.m_flDamage;
    if ( this->m_lowHealthGoalTime == 0.0 && (float)((float)this->m_iHealth.m_Value - info.m_flDamage) <= 10.0 )
      this->m_lowHealthGoalTime = gpGlobals->curtime + 30.0;
    v56 = this->m_iHealth.m_Value;
    if ( (float)((float)v56 - m_flDamage) <= 0.0 && v56 <= 5 )
    {
      v57 = CTakeDamageInfo::GetAttacker(this: &info);
      v58 = ToCSPlayer(pEntity: v57);
      v59 = v58;
      if ( v58 != nullptr )
      {
        v60 = CBaseEntity::GetTeamNumber(this: v58);
        if ( v60 != CBaseEntity::GetTeamNumber(this) )
        {
          m_Head = this->m_DamageTakenList.m_Head;
          if ( m_Head == -1 )
          {
LABEL_124:
            CBaseMultiplayerPlayer::AwardAchievement(this: v59, iAchievement: 5024, iCount: 1);
          }
          else
          {
            while ( 1 )
            {
              v62 = m_Head;
              m_Element = this->m_DamageTakenList.m_Memory.m_pMemory[v62].m_Element;
              v63 = v59->GetPlayerName(this: v59);
              if ( V_strncmp(s1: v63, s2: m_Element->m_szPlayerName, count: 32) == 0 )
                break;
              m_Head = this->m_DamageTakenList.m_Memory.m_pMemory[v62].m_Next;
              if ( m_Head == -1 )
                goto LABEL_124;
            }
          }
        }
      }
      m_flDamage = info.m_flDamage;
    }
    v64 = pAttacker;
    if ( pAttacker != nullptr )
    {
      v65 = (CDamageRecord *)this->GetPlayerName(this);
      CCSPlayer::RecordDamageGiven(this: v64, damageDealer: this, szDamageTaker: v65, iDamageGiven: (int)m_flDamage);
      v71 = (int)info.m_flDamage;
      v66 = (CDamageRecord *)v64->GetPlayerName(this: v64);
      CCSPlayer::RecordDamageTaken(this, damageDealer: v64, szDamageDealer: v66, iDamageTaken: v71);
      if ( bDamageIsFromOpponent )
        CCSGameRules::ScorePlayerDamage(
          this: (CCSGameRules *)g_pGameRules,
          a2: COERCE_FLOAT(&savedregs),
          pPlayer: v64,
          fDamage: info.m_flDamage);
    }
    else
    {
      CCSPlayer::RecordDamageTaken(
        this,
        damageDealer: nullptr,
        szDamageDealer: (CDamageRecord *)"world",
        iDamageTaken: (int)m_flDamage);
    }
    this->m_vecTotalBulletForce.x = this->m_vecTotalBulletForce.x + info.m_vecDamageForce.x;
    this->m_vecTotalBulletForce.y = info.m_vecDamageForce.y + this->m_vecTotalBulletForce.y;
    this->m_vecTotalBulletForce.z = info.m_vecDamageForce.z + this->m_vecTotalBulletForce.z;
    gamestats->Event_PlayerDamage(this: gamestats, a2: this, a3: &info);
    v67 = CBaseCombatCharacter::OnTakeDamage(this, a2: (int)v64, &info);
    CRecipientFilter::~CRecipientFilter(this: &user);
    return v67;
  }
  if ( (info.m_bitsDamageType & 0x40) == 0 && fDamageToHealth_3 != 0 )
  {
    v29 = flDamage * 0.35;
    flDamage = v29;
  }
  goto LABEL_52;
}

//------------------------------------------------------------------------------
// Address: 0x10291470
// Name: public: void CCSPlayer::RoundRespawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSPlayer::RoundRespawn(CCSPlayer *this)
{
  edict_t *m_pPev; // ecx
  CCSGameRules *v3; // ebx
  int TeamNumber; // eax
  bool v5; // zf
  void (__thiscall *SetValue_2)(IConVar *, int); // eax
  edict_t *v7; // ecx
  CCSGameRules *v8; // edi
  int v9; // eax
  CCSPlayerStateInfo *m_pCurStateInfo; // eax
  void (__thiscall *pfnLeaveState)(char *); // edx
  int m_nValue; // eax
  ConVarRef v13; // [esp+14h] [ebp-8h] BYREF

  if ( CCSGameRules::IsPlayingGunGameProgressive(this: (CCSGameRules *)g_pGameRules)
    || CCSGameRules::IsPlayingGunGameTRBomb(this: (CCSGameRules *)g_pGameRules) )
  {
    LOBYTE(v13.m_pConVarState) = CCSGameRules::IsPlayingGunGameProgressive(this: (CCSGameRules *)g_pGameRules);
    CCSPlayer::Reset(this, resetScore: (bool)v13.m_pConVarState);
    this->m_bMadeFinalGunGameProgressiveKill = false;
    this->m_iNumGunGameKillsWithCurrentWeapon = 0;
    if ( CCSGameRules::IsPlayingGunGameProgressive(this: (CCSGameRules *)g_pGameRules) )
    {
      if ( this->m_iGunGameProgressiveWeaponIndex.m_Value != 0 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x1314u);
        }
        this->m_iGunGameProgressiveWeaponIndex.m_Value = 0;
      }
      v3 = (CCSGameRules *)g_pGameRules;
      TeamNumber = CBaseEntity::GetTeamNumber(this);
      if ( !CCSGameRules::IsFinalGunGameProgressiveWeapon(
              this: v3,
              nCurrentWeaponIndex: this->m_iGunGameProgressiveWeaponIndex.m_Value,
              nTeamID: TeamNumber) )
      {
        ConVarRef::ConVarRef(this: &v13, pName: "sf_ui_tint");
        if ( v13.m_pConVarState->m_Value.m_nValue == 4 )
        {
          v5 = CBaseEntity::GetTeamNumber(this) == 2;
          SetValue_2 = v13.m_pConVar->SetValue_2;
          if ( v5 )
            ((void (__stdcall *)(int))SetValue_2)(a1: 2);
          else
            ((void (__stdcall *)(int))SetValue_2)(a1: 1);
        }
      }
    }
    CCSPlayer::GiveDefaultItems(this);
    if ( CCSGameRules::IsPlayingGunGameTRBomb(this: (CCSGameRules *)g_pGameRules)
      && this->m_bShouldProgressGunGameTRBombModeWeapon )
    {
      this->m_bShouldProgressGunGameTRBombModeWeapon = false;
      CCSPlayer::IncrementGunGameProgressiveWeapon(this, nNumLevelsToIncrease: 1);
      if ( this->m_iNumGunGameTRKillPoints.m_Value != 0 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v7 = this->m_Network.m_pPev;
          if ( v7 != nullptr )
            CBaseEdict::StateChanged(this: &v7->CBaseEdict, offset: 0x1318u);
        }
        this->m_iNumGunGameTRKillPoints.m_Value = 0;
      }
      ConVarRef::ConVarRef(this: &v13, pName: "sf_ui_tint");
      v8 = (CCSGameRules *)g_pGameRules;
      v9 = CBaseEntity::GetTeamNumber(this);
      if ( CCSGameRules::IsFinalGunGameProgressiveWeapon(
             this: v8,
             nCurrentWeaponIndex: this->m_iGunGameProgressiveWeaponIndex.m_Value,
             nTeamID: v9) )
      {
        v13.m_pConVar->SetValue_2(this: v13.m_pConVar, a2: 4);
      }
      else if ( v13.m_pConVarState->m_Value.m_nValue == 4 )
      {
        if ( CBaseEntity::GetTeamNumber(this) == 2 )
          v13.m_pConVar->SetValue_2(this: v13.m_pConVar, a2: 2);
        else
          v13.m_pConVar->SetValue_2(this: v13.m_pConVar, a2: 1);
      }
    }
  }
  this->StopObserverMode(this);
  m_pCurStateInfo = this->m_pCurStateInfo;
  if ( m_pCurStateInfo != nullptr )
  {
    pfnLeaveState = (void (__thiscall *)(char *))m_pCurStateInfo->pfnLeaveState;
    if ( pfnLeaveState != nullptr )
      pfnLeaveState(a1: (char *)this + DWORD1(m_pCurStateInfo->pfnLeaveState));
  }
  CCSPlayer::State_Enter(this, newState: STATE_ACTIVE);
  if ( mp_maxrounds.m_pParent == nullptr
    || (m_nValue = mp_maxrounds.m_pParent->m_Value.m_nValue) <= 0
    || (int)g_pGameRules[131].__vftable < m_nValue )
  {
    respawn(pEdict: this, fCopyCorpse: false);
  }
  this->m_nButtons = 0;
  CBaseEntity::SetNextThink(this, thinkTime: -1.0, szContext: nullptr);
  this->m_receivesMoneyNextRound = true;
  CCSPlayer::OutputDamageGiven(this);
  CCSPlayer::OutputDamageTaken(this);
  CUtlLinkedList<CDamageRecord *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CDamageRecord *,int>,int>>::PurgeAndDeleteElements(this: &this->m_DamageGivenList);
  CUtlLinkedList<CDamageRecord *,int,0,int,CUtlMemory<UtlLinkedListElem_t<CDamageRecord *,int>,int>>::PurgeAndDeleteElements(this: &this->m_DamageTakenList);
}

//------------------------------------------------------------------------------
// Address: 0x102916D0
// Name: public: void CCSPlayer::GetIntoGame(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall CCSPlayer::GetIntoGame(CCSPlayer *this@<ecx>, __int64 a2@<esi:edi>)
{
  CCSGameRules *v3; // edi
  bool v4; // zf
  CCSPlayerStateInfo *m_pCurStateInfo; // eax
  void (__thiscall *pfnLeaveState)(char *); // edx
  void (__thiscall *v7)(char *); // edx
  IGameEvent *v8; // edi
  double v9; // st7
  int v10; // ebx
  int v11; // eax
  int v12; // eax
  IGameEvent_vtbl *v13; // edx
  ConVarRef bot_quota; // [esp+28h] [ebp-Ch] BYREF
  int v16; // [esp+30h] [ebp-4h] OVERLAPPED BYREF

  CBasePlayer::SetFOV(this, pRequester: this, FOV: 0, zoomRate: 0.0, iZoomStart: 0);
  this->m_flLastMovement = gpGlobals->curtime;
  v3 = (CCSGameRules *)g_pGameRules;
  v4 = ((unsigned __int8 (__thiscall *)(CGameRules *, CCSPlayer *, _DWORD, _DWORD, IConVar *))g_pGameRules->FPlayerCanRespawn)(
         a1: g_pGameRules,
         a2: this,
         a3: a2,
         a4: HIDWORD(a2),
         a5: bot_quota.m_pConVar) == 0;
  m_pCurStateInfo = this->m_pCurStateInfo;
  if ( v4 )
  {
    if ( m_pCurStateInfo != nullptr )
    {
      pfnLeaveState = (void (__thiscall *)(char *))m_pCurStateInfo->pfnLeaveState;
      if ( pfnLeaveState != nullptr )
        pfnLeaveState(a1: (char *)this + DWORD1(m_pCurStateInfo->pfnLeaveState));
    }
    CCSPlayer::State_Enter(this, newState: STATE_OBSERVER_MODE);
    this->m_wasNotKilledNaturally = true;
    CCSGameRules::CheckWinConditions(this: v3);
  }
  else
  {
    if ( m_pCurStateInfo != nullptr )
    {
      v7 = (void (__thiscall *)(char *))m_pCurStateInfo->pfnLeaveState;
      if ( v7 != nullptr )
        v7(a1: (char *)this + DWORD1(m_pCurStateInfo->pfnLeaveState));
    }
    CCSPlayer::State_Enter(this, newState: STATE_ACTIVE);
    this->Spawn(this);
    CCSGameRules::CheckWinConditions(this: v3);
    v3->SpawningLatePlayer(this: v3, a2: this);
    if ( v3->m_flRestartRoundTime == 0.0
      && CCSGameRules::IsBombDefuseMap(this: v3)
      && CCSGameRules::IsThereABomber(this: v3) == 0
      && !CCSGameRules::IsThereABomb(this: v3) )
    {
      CCSGameRules::GiveC4ToRandomPlayer(this: v3);
    }
    if ( CBaseEntity::GetTeamNumber(this) == 2 )
      ++v3->m_iNumEscapers;
    CCSPlayer::ResetRoundBasedAchievementVariables(this);
    if ( (this->m_afPhysicsFlags.m_Value & 8) == 0 )
    {
      v8 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "player_spawned", a3: 0, a4: 0);
      v9 = ((double (__thiscall *)(CGameRules *))g_pGameRules->__vftable[1].Damage_GetShowOnHud)(a1: g_pGameRules);
      v10 = (int)ceil(X: v9);
      HIBYTE(v16) = 0;
      CCSGameRules::NeededPlayersCheck(this: (CCSGameRules *)g_pGameRules, bNeededPlayers: (bool *)&v16 + 3);
      ConVarRef::ConVarRef(this: &bot_quota, pName: "bot_quota");
      if ( v8 != nullptr )
      {
        v11 = ((int (__thiscall *)(IVEngineServer *, edict_t *, IConVar *, ConVar *, int))engine->GetPlayerUserId)(
                a1: engine,
                a2: this->m_Network.m_pPev,
                a3: bot_quota.m_pConVar,
                a4: bot_quota.m_pConVarState,
                a5: v16);
        v8->SetInt(this: v8, a2: "userid", a3: v11);
        LOBYTE(v12) = !CCSGameRules::IsPlayingTraining(this: (CCSGameRules *)g_pGameRules)
                   && bot_quota.m_pConVarState->m_Value.m_nValue > 0
                   && (v10 > 0 || HIBYTE(v16) != 0);
        v13 = v8->__vftable;
        v16 = v12;
        ((void (__thiscall *)(IGameEvent *, const char *))v13->SetBool)(a1: v8, a2: "inrestart");
        gameeventmanager->FireEvent(this: gameeventmanager, a2: v8, a3: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102918C0
// Name: AutoBuy
// Source: json
//------------------------------------------------------------------------------
void __cdecl AutoBuy()
{
  CBasePlayer *CommandClient; // esi
  CCSPlayer *v1; // eax

  CommandClient = UTIL_GetCommandClient();
  if ( CommandClient != nullptr && CommandClient->IsPlayer(this: CommandClient) )
  {
    v1 = (CCSPlayer *)__RTDynamicCast(
                        inptr: CommandClient,
                        VfDelta: 0,
                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                        TargetType: &CCSPlayer `RTTI Type Descriptor',
                        isReference: 0);
    if ( v1 != nullptr )
      CCSPlayer::AutoBuy(this: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10291910
// Name: Rebuy
// Source: json
//------------------------------------------------------------------------------
void __cdecl Rebuy()
{
  CBasePlayer *CommandClient; // esi
  CCSPlayer *v1; // eax

  CommandClient = UTIL_GetCommandClient();
  if ( CommandClient != nullptr && CommandClient->IsPlayer(this: CommandClient) )
  {
    v1 = (CCSPlayer *)__RTDynamicCast(
                        inptr: CommandClient,
                        VfDelta: 0,
                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                        TargetType: &CCSPlayer `RTTI Type Descriptor',
                        isReference: 0);
    if ( v1 != nullptr )
      CCSPlayer::Rebuy(this: v1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10291960
// Name: public: int CUtlDict<float,int>::Insert(char const __near *,float const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlDict<float,int>::Insert(CUtlDict<float,int> *this, const char *pName, int element)
{
  const char *v3; // ebx
  char *v5; // eax
  float v6; // xmm0_4
  int v7; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,float,int>::Node_t,int> *m_pMemory; // edx
  CUtlMap<char const *,float,int>::Node_t insert; // [esp+Ch] [ebp-8h] BYREF

  v3 = pName;
  if ( pName != nullptr && (v5 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pName) + 1)) != nullptr )
    strcpy(v5, v3);
  else
    v5 = nullptr;
  v6 = *(float *)element;
  insert.key = v5;
  insert.elem = v6;
  element = -1;
  LOBYTE(pName) = 0;
  CUtlRBTree<CUtlMap<char const *,float,int>::Node_t,int,CUtlMap<char const *,float,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,float,int>::Node_t,int>,int>>::FindInsertionPosition(
    this: &this->m_Elements.m_Tree,
    &insert,
    parent: &element,
    leftchild: (bool *)&pName);
  v7 = CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::NewNode(
         (CUtlRBTree<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> > *)this,
         a2: (const char *)this);
  CUtlRBTree<CUtlMap<char const *,float,int>::Node_t,int,CUtlMap<char const *,float,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,float,int>::Node_t,int>,int>>::LinkToParent(
    this: &this->m_Elements.m_Tree,
    i: v7,
    parent: element,
    isLeft: (bool)pName);
  m_pMemory = this->m_Elements.m_Tree.m_Elements.m_pMemory;
  ++this->m_Elements.m_Tree.m_NumElements;
  if ( &m_pMemory[v7] != (UtlRBTreeNode_t<CUtlMap<char const *,float,int>::Node_t,int> *)-16 )
    m_pMemory[v7].m_Data = insert;
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x10291A50
// Name: private: bool CCSPlayer::ShouldRunRateLimitedCommand(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSPlayer::ShouldRunRateLimitedCommand(CCSPlayer *this, const CCommand *args)
{
  const char *v3; // esi
  int v4; // eax
  float *p_elem; // eax
  CUtlMap<char const *,float,int>::Node_t search; // [esp+8h] [ebp-8h] BYREF

  if ( args->m_nArgc > 0 )
  {
    v3 = args->m_ppArgv[0];
    if ( v3 == nullptr )
    {
LABEL_5:
      CUtlDict<float,int>::Insert(
        this: &this->m_RateLimitLastCommandTimes,
        pName: v3,
        element: (int)&gpGlobals->curtime);
      return 1;
    }
  }
  else
  {
    v3 = locale;
  }
  search.key = v3;
  v4 = CUtlRBTree<CUtlMap<char const *,float,int>::Node_t,int,CUtlMap<char const *,float,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,float,int>::Node_t,int>,int>>::Find(
         this: &this->m_RateLimitLastCommandTimes.m_Elements.m_Tree,
         &search);
  if ( v4 == -1 )
    goto LABEL_5;
  p_elem = &this->m_RateLimitLastCommandTimes.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem;
  if ( (float)(gpGlobals->curtime - *p_elem) < 0.3 )
    return 0;
  *p_elem = gpGlobals->curtime;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10291B00
// Name: public: bool CCSPlayer::HandleCommand_JoinClass(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CCSPlayer::HandleCommand_JoinClass@<al>(CCSPlayer *this@<ecx>, __int64 a2@<esi:edi>)
{
  int NextClassForTeam; // ebx
  int TeamNumber; // eax
  CBaseEdict *v4; // ecx

  HIDWORD(a2) = this;
  NextClassForTeam = 0;
  if ( (unsigned int)(CBaseEntity::GetTeamNumber(this) - 2) <= 1 )
  {
    TeamNumber = CBaseEntity::GetTeamNumber(this: (CBaseEntity *)HIDWORD(a2));
    NextClassForTeam = PlayerModelInfo::GetNextClassForTeam(this: &PlayerModelInfo::s_PlayerModelInfo, team: TeamNumber);
  }
  if ( *(_DWORD *)(HIDWORD(a2) + 4824) == 0 )
    CCSGameRules::CheckWinConditions(this: (CCSGameRules *)g_pGameRules);
  if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(*(_DWORD *)HIDWORD(a2) + 1912))(a1: HIDWORD(a2)) == 0
    && *(_DWORD *)(HIDWORD(a2) + 4824) == 0 )
  {
    (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)HIDWORD(a2) + 1908))(a1: HIDWORD(a2), a2: 0, a3: 0);
  }
  if ( *(_DWORD *)(HIDWORD(a2) + 6164) != NextClassForTeam )
  {
    if ( *(_BYTE *)(HIDWORD(a2) + 84) != 0 )
    {
      *(_BYTE *)(HIDWORD(a2) + 88) |= 1u;
    }
    else
    {
      v4 = *(CBaseEdict **)(HIDWORD(a2) + 24);
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: v4, offset: 0x1814u);
    }
    *(_DWORD *)(HIDWORD(a2) + 6164) = NextClassForTeam;
  }
  if ( *(_DWORD *)(HIDWORD(a2) + 4824) == 3 )
    CCSPlayer::GetIntoGame(this: (CCSPlayer *)HIDWORD(a2), a2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10291BF0
// Name: public: virtual bool CCSPlayer::ClientCommand(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSPlayer::ClientCommand(CCSPlayer *this, const CCommand *args)
{
  __int64 v2; // rdi
  const char *v3; // ebx
  int v4; // eax
  CBaseEdict *v6; // ecx
  const char *v7; // eax
  CBaseCombatWeapon *ActiveWeapon; // eax
  CWeaponCSBase *v9; // eax
  CCSWeaponInfo *CSWpnData; // eax
  int WeaponPrice; // eax
  CSWeaponType m_WeaponType; // eax
  char v13; // bl
  CBaseEdict *v14; // ecx
  bool v15; // al
  edict_t *v16; // [esp-Ch] [ebp-40h]
  edict_t *v17; // [esp-Ch] [ebp-40h]
  VoteType v18; // [esp-4h] [ebp-38h]
  CCSPlayer *soundtime; // [esp+0h] [ebp-34h]
  CCSPlayer *attenuation; // [esp+4h] [ebp-30h]
  CPASAttenuationFilter filter; // [esp+14h] [ebp-20h] BYREF

  HIDWORD(v2) = this;
  LODWORD(v2) = locale;
  if ( args->m_nArgc > 0 )
    LODWORD(v2) = args->m_ppArgv[0];
  if ( (const char *)v2 == "jointeam" || _V_stricmp(s1: (const char *)v2, s2: "jointeam") == 0 )
  {
    if ( args->m_nArgc < 2 )
      _Warning(a1: "Player sent bad jointeam syntax\n");
    if ( CCSPlayer::ShouldRunRateLimitedCommand(this: (CCSPlayer *)HIDWORD(v2), args) != 0 )
    {
      if ( args->m_nArgc > 1 )
        v3 = args->m_ppArgv[1];
      else
        v3 = locale;
      v4 = atoi(nptr: v3);
      CCSPlayer::HandleCommand_JoinTeam(this: (CCSPlayer *)HIDWORD(v2), team: v4);
    }
    return true;
  }
  if ( (const char *)v2 == "resetteam" || _V_stricmp(s1: (const char *)v2, s2: "resetteam") == 0 )
  {
    *(_BYTE *)(HIDWORD(v2) + 4912) = 0;
    *(_DWORD *)(HIDWORD(v2) + 4908) = 0;
    if ( *(_DWORD *)(HIDWORD(v2) + 6164) != 0 )
    {
      if ( *(_BYTE *)(HIDWORD(v2) + 84) != 0 )
      {
        *(_BYTE *)(HIDWORD(v2) + 88) |= 1u;
        *(_DWORD *)(HIDWORD(v2) + 6164) = 0;
        return true;
      }
      v6 = *(CBaseEdict **)(HIDWORD(v2) + 24);
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0x1814u);
      *(_DWORD *)(HIDWORD(v2) + 6164) = 0;
    }
    return true;
  }
  if ( (const char *)v2 == "spectate" || _V_stricmp(s1: (const char *)v2, s2: "spectate") == 0 )
  {
    if ( CCSPlayer::ShouldRunRateLimitedCommand(this: (CCSPlayer *)HIDWORD(v2), args) != 0 )
      CCSPlayer::HandleCommand_JoinTeam(this: (CCSPlayer *)HIDWORD(v2), team: 1);
    return true;
  }
  if ( (const char *)v2 == "joingame" || _V_stricmp(s1: (const char *)v2, s2: "joingame") == 0 )
  {
    if ( *(_DWORD *)(HIDWORD(v2) + 4824) == 1 )
      CCSPlayer::State_Transition(this: (CCSPlayer *)HIDWORD(v2), newState: STATE_PICKINGTEAM);
    return true;
  }
  if ( (const char *)v2 == "player_vote" || _V_stricmp(s1: (const char *)v2, s2: "player_vote") == 0 )
  {
    if ( args->m_nArgc > 1 && g_pGameRules[147].m_pNext != nullptr && args->m_nArgc > 1 )
    {
      v7 = args->m_ppArgv[1];
      if ( v7 != nullptr && *v7 == 49 )
      {
        *(_BYTE *)(HIDWORD(v2) + 6876) = 1;
        return CBaseMultiplayerPlayer::ClientCommand(this: (CBaseMultiplayerPlayer *)HIDWORD(v2), args);
      }
    }
    return CBaseMultiplayerPlayer::ClientCommand(this: (CBaseMultiplayerPlayer *)HIDWORD(v2), args);
  }
  if ( FStrEq(sz1: (const char *)v2, sz2: "call_vote") )
  {
    if ( args->m_nArgc > 1 )
    {
      LODWORD(v2) = args->m_ppArgv[1];
      if ( FStrEq(sz1: (const char *)v2, sz2: "kick_player") )
      {
        attenuation = (CCSPlayer *)HIDWORD(v2);
        soundtime = (CCSPlayer *)HIDWORD(v2);
        v18 = VoteType_KickPlayer;
LABEL_44:
        CCSGameRules::InitiateVote(
          this: (CCSGameRules *)g_pGameRules,
          a2: v2,
          a3: SHIDWORD(v2),
          voteType: v18,
          initiatingPlayer: soundtime,
          playerToKick: attenuation);
        return CBaseMultiplayerPlayer::ClientCommand(this: (CBaseMultiplayerPlayer *)HIDWORD(v2), args);
      }
      if ( FStrEq(sz1: (const char *)v2, sz2: "team_switch") )
      {
        attenuation = nullptr;
        soundtime = (CCSPlayer *)HIDWORD(v2);
        v18 = VoteType_TeamSwitch;
        goto LABEL_44;
      }
      if ( FStrEq(sz1: (const char *)v2, sz2: "scramble_teams") )
      {
        attenuation = nullptr;
        soundtime = (CCSPlayer *)HIDWORD(v2);
        v18 = VoteType_ScrambleTeams;
        goto LABEL_44;
      }
      if ( FStrEq(sz1: (const char *)v2, sz2: "surrender") )
      {
        attenuation = nullptr;
        soundtime = (CCSPlayer *)HIDWORD(v2);
        v18 = VoteType_Surrender;
        goto LABEL_44;
      }
      if ( FStrEq(sz1: (const char *)v2, sz2: "restart_match") )
      {
        if ( HIBYTE(g_pGameRules[146].__vftable) != 0 )
          CCSGameRules::InitiateVote(
            this: (CCSGameRules *)g_pGameRules,
            a2: v2,
            a3: SHIDWORD(v2),
            voteType: VoteType_RestartMatch,
            initiatingPlayer: (CCSPlayer *)HIDWORD(v2),
            playerToKick: nullptr);
        return CBaseMultiplayerPlayer::ClientCommand(this: (CBaseMultiplayerPlayer *)HIDWORD(v2), args);
      }
      if ( FStrEq(sz1: (const char *)v2, sz2: "change_map") )
      {
        attenuation = nullptr;
        soundtime = (CCSPlayer *)HIDWORD(v2);
        v18 = VoteType_ChangeMap;
        goto LABEL_44;
      }
    }
    return CBaseMultiplayerPlayer::ClientCommand(this: (CBaseMultiplayerPlayer *)HIDWORD(v2), args);
  }
  if ( FStrEq(sz1: (const char *)v2, sz2: "joinclass") )
  {
    if ( CCSPlayer::ShouldRunRateLimitedCommand(this: (CCSPlayer *)HIDWORD(v2), args) != 0 )
      CCSPlayer::HandleCommand_JoinClass(this: (CCSPlayer *)HIDWORD(v2), a2: v2);
    return true;
  }
  if ( FStrEq(sz1: (const char *)v2, sz2: "drop") )
  {
    if ( !CCSGameRules::IsPlayingGunGameProgressive(this: (CCSGameRules *)g_pGameRules)
      && !CCSGameRules::IsPlayingGunGameTRBomb(this: (CCSGameRules *)g_pGameRules) )
    {
      ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: (CBaseCombatCharacter *)HIDWORD(v2));
      v9 = (CWeaponCSBase *)__RTDynamicCast(
                              inptr: ActiveWeapon,
                              VfDelta: 0,
                              SrcType: &CBaseCombatWeapon `RTTI Type Descriptor',
                              TargetType: &CWeaponCSBase `RTTI Type Descriptor',
                              isReference: 0);
      LODWORD(v2) = v9;
      if ( v9 != nullptr )
      {
        if ( !CWeaponCSBase::IsAPriorOwner(this: v9, pPlayer: (CCSPlayer *)HIDWORD(v2)) )
        {
          CWeaponCSBase::AddToPriorOwnerList(this: (CWeaponCSBase *)v2, pPlayer: (CCSPlayer *)HIDWORD(v2));
          CSWpnData = (CCSWeaponInfo *)CWeaponCSBase::GetCSWpnData(this: (CWeaponCSBase *)v2);
          WeaponPrice = CCSWeaponInfo::GetWeaponPrice(this: CSWpnData);
          CCSGameStats::IncrementStat(
            this: &CCS_GameStats,
            pPlayer: (CCSPlayer *)HIDWORD(v2),
            statId: CSTAT_ITEMS_DROPPED_VALUE,
            iDelta: WeaponPrice,
            bPlayerOnly: false);
        }
        m_WeaponType = CWeaponCSBase::GetCSWpnData(this: (CWeaponCSBase *)v2)->m_WeaponType;
        if ( m_WeaponType != WEAPONTYPE_KNIFE && m_WeaponType != WEAPONTYPE_GRENADE )
        {
          if ( LOBYTE(g_pGameRules[138].m_pszName) != 0 && *(_BYTE *)(v2 + 1452) == 0 )
          {
            *(_BYTE *)(v2 + 1452) = 1;
            CWeaponCSBase::SetDonor(this: (CWeaponCSBase *)v2, player: (CCSPlayer *)HIDWORD(v2));
          }
          CCSPlayer::CSWeaponDrop(
            this: (CCSPlayer *)HIDWORD(v2),
            a2: (int)args,
            pWeapon: (CBaseCombatWeapon *)v2,
            bDropShield: true,
            bThrowForward: true);
        }
      }
    }
    return true;
  }
  if ( FStrEq(sz1: (const char *)v2, sz2: "buy") )
  {
    if ( args->m_nArgc != 2
      || CCSPlayer::HandleCommand_Buy(this: (CCSPlayer *)HIDWORD(v2), item: args->m_ppArgv[1]) == BUY_INVALID_ITEM )
    {
      ClientPrint(
        player: (CBasePlayer *)HIDWORD(v2),
        msg_dest: 2u,
        msg_name: "usage: buy <item>\n",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      ClientPrint(
        player: (CBasePlayer *)HIDWORD(v2),
        msg_dest: 2u,
        msg_name: "  primammo\n",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      ClientPrint(
        player: (CBasePlayer *)HIDWORD(v2),
        msg_dest: 2u,
        msg_name: "  secammo\n",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      ClientPrint(
        player: (CBasePlayer *)HIDWORD(v2),
        msg_dest: 2u,
        msg_name: "  vest\n",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      ClientPrint(
        player: (CBasePlayer *)HIDWORD(v2),
        msg_dest: 2u,
        msg_name: "  vesthelm\n",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      ClientPrint(
        player: (CBasePlayer *)HIDWORD(v2),
        msg_dest: 2u,
        msg_name: "  defuser\n",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      ClientPrint(
        player: (CBasePlayer *)HIDWORD(v2),
        msg_dest: 2u,
        msg_name: "  nvgs\n",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      ClientPrint(
        player: (CBasePlayer *)HIDWORD(v2),
        msg_dest: 2u,
        msg_name: "  flashbang\n",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      ClientPrint(
        player: (CBasePlayer *)HIDWORD(v2),
        msg_dest: 2u,
        msg_name: "  hegrenade\n",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      ClientPrint(
        player: (CBasePlayer *)HIDWORD(v2),
        msg_dest: 2u,
        msg_name: "  smokegrenade\n",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      ClientPrint(
        player: (CBasePlayer *)HIDWORD(v2),
        msg_dest: 2u,
        msg_name: "  galil\n",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      ClientPrint(
        player: (CBasePlayer *)HIDWORD(v2),
        msg_dest: 2u,
        msg_name: "  ak47\n",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      ClientPrint(
        player: (CBasePlayer *)HIDWORD(v2),
        msg_dest: 2u,
        msg_name: "  awp\n",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      ClientPrint(
        player: (CBasePlayer *)HIDWORD(v2),
        msg_dest: 2u,
        msg_name: "  g3sg1\n",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      ClientPrint(
        player: (CBasePlayer *)HIDWORD(v2),
        msg_dest: 2u,
        msg_name: "  famas\n",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      ClientPrint(
        player: (CBasePlayer *)HIDWORD(v2),
        msg_dest: 2u,
        msg_name: "  aug\n",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      ClientPrint(
        player: (CBasePlayer *)HIDWORD(v2),
        msg_dest: 2u,
        msg_name: "  glock\n",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      ClientPrint(
        player: (CBasePlayer *)HIDWORD(v2),
        msg_dest: 2u,
        msg_name: "  deagle\n",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      ClientPrint(
        player: (CBasePlayer *)HIDWORD(v2),
        msg_dest: 2u,
        msg_name: "  elite\n",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      ClientPrint(
        player: (CBasePlayer *)HIDWORD(v2),
        msg_dest: 2u,
        msg_name: "  fiveseven\n",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      ClientPrint(
        player: (CBasePlayer *)HIDWORD(v2),
        msg_dest: 2u,
        msg_name: "  xm1014\n",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      ClientPrint(
        player: (CBasePlayer *)HIDWORD(v2),
        msg_dest: 2u,
        msg_name: "  mac10\n",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      ClientPrint(
        player: (CBasePlayer *)HIDWORD(v2),
        msg_dest: 2u,
        msg_name: "  ump45\n",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      ClientPrint(
        player: (CBasePlayer *)HIDWORD(v2),
        msg_dest: 2u,
        msg_name: "  p90\n",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
      ClientPrint(
        player: (CBasePlayer *)HIDWORD(v2),
        msg_dest: 2u,
        msg_name: "  m249\n",
        param1: nullptr,
        param2: nullptr,
        param3: nullptr,
        param4: nullptr);
    }
    return true;
  }
  if ( FStrEq(sz1: (const char *)v2, sz2: "buyammo1") )
  {
    CCSPlayer::AttemptToBuyAmmoSingle(this: (CCSPlayer *)HIDWORD(v2), a2: (int)args, iAmmoType: 0);
    return true;
  }
  if ( FStrEq(sz1: (const char *)v2, sz2: "buyammo2") )
  {
    CCSPlayer::AttemptToBuyAmmoSingle(this: (CCSPlayer *)HIDWORD(v2), a2: (int)args, iAmmoType: 1u);
    return true;
  }
  if ( !FStrEq(sz1: (const char *)v2, sz2: "nightvision") )
  {
    if ( FStrEq(sz1: (const char *)v2, sz2: "menuselect")
      || HandleRadioAliasCommands(a1: v2, pPlayer: (CCSPlayer *)HIDWORD(v2), pszCommand: (const char *)v2) != 0 )
    {
      return true;
    }
    if ( FStrEq(sz1: (const char *)v2, sz2: "listplayers") )
    {
      CCSPlayer::ListPlayers(this: (CCSPlayer *)HIDWORD(v2), a2: v2);
      return true;
    }
    if ( FStrEq(sz1: (const char *)v2, sz2: "ignorerad") )
    {
      v15 = *(_BYTE *)(HIDWORD(v2) + 4820) == 0;
      *(_BYTE *)(HIDWORD(v2) + 4820) = v15;
      if ( v15 )
        ClientPrint(
          player: (CBasePlayer *)HIDWORD(v2),
          msg_dest: 3u,
          msg_name: "#Ignore_Radio",
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
      else
        ClientPrint(
          player: (CBasePlayer *)HIDWORD(v2),
          msg_dest: 3u,
          msg_name: "#Accept_Radio",
          param1: nullptr,
          param2: nullptr,
          param3: nullptr,
          param4: nullptr);
      return true;
    }
    if ( FStrEq(sz1: (const char *)v2, sz2: "become_vip") )
      return true;
    return CBaseMultiplayerPlayer::ClientCommand(this: (CBaseMultiplayerPlayer *)HIDWORD(v2), args);
  }
  if ( CCSPlayer::ShouldRunRateLimitedCommand(this: (CCSPlayer *)HIDWORD(v2), args) != 0
    && *(_BYTE *)(HIDWORD(v2) + 4957) != 0 )
  {
    if ( *(_BYTE *)(HIDWORD(v2) + 4958) != 0 )
    {
      CPASAttenuationFilter::CPASAttenuationFilter(
        this: &filter,
        entity: (CBaseEntity *)HIDWORD(v2),
        attenuation: 0.80000001);
      v16 = CBaseEntity::entindex(this: (CBaseEntity *)HIDWORD(v2));
      CBaseEntity::EmitSound(
        &filter,
        iEntIndex: (int)v16,
        soundname: "Player.NightVisionOff",
        pOrigin: nullptr,
        soundtime: 0.0,
        duration: nullptr);
    }
    else
    {
      CPASAttenuationFilter::CPASAttenuationFilter(
        this: &filter,
        entity: (CBaseEntity *)HIDWORD(v2),
        attenuation: 0.80000001);
      v17 = CBaseEntity::entindex(this: (CBaseEntity *)HIDWORD(v2));
      CBaseEntity::EmitSound(
        &filter,
        iEntIndex: (int)v17,
        soundname: "Player.NightVisionOn",
        pOrigin: nullptr,
        soundtime: 0.0,
        duration: nullptr);
    }
    CRecipientFilter::~CRecipientFilter(this: &filter);
    v13 = *(_BYTE *)(HIDWORD(v2) + 4958) == 0;
    if ( *(_BYTE *)(HIDWORD(v2) + 4958) != v13 )
    {
      if ( *(_BYTE *)(HIDWORD(v2) + 84) != 0 )
      {
        *(_BYTE *)(HIDWORD(v2) + 88) |= 1u;
        *(_BYTE *)(HIDWORD(v2) + 4958) = v13;
        return true;
      }
      v14 = *(CBaseEdict **)(HIDWORD(v2) + 24);
      if ( v14 != nullptr )
        CBaseEdict::StateChanged(this: v14, offset: 0x135Eu);
      *(_BYTE *)(HIDWORD(v2) + 4958) = v13;
    }
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x1040EF00
// Name: DT_CSRagdoll::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_CSRagdoll::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_CSRagdoll::g_SendTable);
  return atexit(func: DT_CSRagdoll::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040EF20
// Name: DT_CSRagdoll::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_CSRagdoll::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_CSRagdoll::ignored>();
  DT_CSRagdoll::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040EF50
// Name: DT_TEPlayerAnimEvent::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_TEPlayerAnimEvent::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_TEPlayerAnimEvent::g_SendTable);
  return atexit(func: DT_TEPlayerAnimEvent::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040EF70
// Name: DT_TEPlayerAnimEvent::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_TEPlayerAnimEvent::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_TEPlayerAnimEvent::ignored>();
  DT_TEPlayerAnimEvent::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040EFD0
// Name: playerPrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int playerPrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  playerPrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&playerPrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040EFF0
// Name: DT_CSLocalPlayerExclusive::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_CSLocalPlayerExclusive::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_CSLocalPlayerExclusive::g_SendTable);
  return atexit(func: DT_CSLocalPlayerExclusive::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040F010
// Name: DT_CSLocalPlayerExclusive::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_CSLocalPlayerExclusive::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_CSLocalPlayerExclusive::ignored>();
  DT_CSLocalPlayerExclusive::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040F020
// Name: DT_CSNonLocalPlayerExclusive::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_CSNonLocalPlayerExclusive::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_CSNonLocalPlayerExclusive::g_SendTable);
  return atexit(func: DT_CSNonLocalPlayerExclusive::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040F040
// Name: DT_CSNonLocalPlayerExclusive::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_CSNonLocalPlayerExclusive::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_CSNonLocalPlayerExclusive::ignored>();
  DT_CSNonLocalPlayerExclusive::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040F070
// Name: DT_CSPlayer::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_CSPlayer::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_CSPlayer::g_SendTable);
  return atexit(func: DT_CSPlayer::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040F090
// Name: DT_CSPlayer::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_CSPlayer::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_CSPlayer::ignored>();
  DT_CSPlayer::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040F0A0
// Name: CCSPlayer_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CCSPlayer_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CCSPlayer>();
  CCSPlayer_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041FBC0
// Name: DT_CSRagdoll::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_CSRagdoll::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_CSRagdoll::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041FBD0
// Name: DT_TEPlayerAnimEvent::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_TEPlayerAnimEvent::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_TEPlayerAnimEvent::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041FC10
// Name: DT_CSLocalPlayerExclusive::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_CSLocalPlayerExclusive::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_CSLocalPlayerExclusive::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041FC40
// Name: DT_CSNonLocalPlayerExclusive::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_CSNonLocalPlayerExclusive::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_CSNonLocalPlayerExclusive::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041FC70
// Name: DT_CSPlayer::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_CSPlayer::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_CSPlayer::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10254010
// Name: class CPropVehicle __near * _CreateEntityTemplate<class CPropVehicle>(class CPropVehicle __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPropVehicle *__cdecl _CreateEntityTemplate<CPropVehicle>(CPropVehicle *newEnt, const char *className)
{
  CBaseAnimating *v2; // eax
  CBaseAnimating *v3; // esi

  v2 = (CBaseAnimating *)CBaseEntity::operator new(stAllocateBlock: 0x5E4u);
  v3 = v2;
  if ( v2 != nullptr )
  {
    CBaseAnimating::CBaseAnimating(this: v2);
    v3[1].__vftable = (CBaseAnimating_vtbl *)&CDefaultPlayerPickupVPhysics::`vftable';
    v3->__vftable = (CBaseAnimating_vtbl *)&CPropVehicle::`vftable'{for `CBaseProp'};
    v3[1].__vftable = (CBaseAnimating_vtbl *)&CPropVehicle::`vftable'{for `CDefaultPlayerPickupVPhysics'};
    CFourWheelVehiclePhysics::CFourWheelVehiclePhysics(
      this: (CFourWheelVehiclePhysics *)&v3[1].m_pfnMoveDone,
      pOuter: v3);
    *(_DWORD *)&v3[1].m_nWaterTouch = -1;
    LODWORD(v3[1].m_Collision.m_vecSurroundingMaxs.z) = 1;
    v3->PostConstructor(this: v3, a2: className);
    return (CPropVehicle *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028DDE0
// Name: class CCSRagdoll __near * _CreateEntityTemplate<class CCSRagdoll>(class CCSRagdoll __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CCSRagdoll *__cdecl _CreateEntityTemplate<CCSRagdoll>(CCSRagdoll *newEnt, const char *className)
{
  CBaseAnimating *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseAnimating *)CBaseEntity::operator new(stAllocateBlock: 0x4C4u);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseAnimating::CBaseAnimating(this: v2);
    v3[291] = 0;
    v3[292] = 0;
    v3[293] = 0;
    v3[294] = 0;
    v3[295] = 0;
    *v3 = &CCSRagdoll::`vftable';
    v3[296] = -1;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CCSRagdoll *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040EF30
// Name: _dynamic_initializer_for__g_CTEPlayerAnimEvent_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTEPlayerAnimEvent_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTEPlayerAnimEvent_ClassReg,
           pNetworkName: "CTEPlayerAnimEvent",
           pTable: &DT_TEPlayerAnimEvent::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1040EF80
// Name: _dynamic_initializer_for__g_TEPlayerAnimEvent__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_TEPlayerAnimEvent__()
{
  CBaseTempEntity::CBaseTempEntity(this: &g_TEPlayerAnimEvent, name: "PlayerAnimEvent");
  g_TEPlayerAnimEvent.__vftable = (CTEPlayerAnimEvent_vtbl *)&CTEPlayerAnimEvent::`vftable';
  g_TEPlayerAnimEvent.m_hPlayer.m_Value.m_Index = -1;
  return atexit(func: dynamic_atexit_destructor_for__g_TEPlayerAnimEvent__);
}

//------------------------------------------------------------------------------
// Address: 0x1040F050
// Name: _dynamic_initializer_for__g_CCSPlayer_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CCSPlayer_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CCSPlayer_ClassReg,
           pNetworkName: "CCSPlayer",
           pTable: &DT_CSPlayer::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1040F0B0
// Name: _dynamic_initializer_for__cc_CreatePredictionError__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cc_CreatePredictionError__()
{
  ConCommand::ConCommand(
    this: &cc_CreatePredictionError,
    pName: "CreatePredictionError",
    callback: (void (__cdecl *)())cc_CreatePredictionError_f,
    pHelpString: "Create a prediction error",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cc_CreatePredictionError__);
}

//------------------------------------------------------------------------------
// Address: 0x1040F0E0
// Name: _dynamic_initializer_for__sv_runcmds__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__sv_runcmds__()
{
  ConVar::ConVar(this: &sv_runcmds, pName: "sv_runcmds", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__sv_runcmds__);
}

//------------------------------------------------------------------------------
// Address: 0x1040F110
// Name: _dynamic_initializer_for__cs_make_vip_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cs_make_vip_command__()
{
  ConCommand::ConCommand(
    this: &cs_make_vip_command,
    pName: "cs_make_vip",
    callback: (void (__cdecl *)())cs_make_vip,
    pHelpString: "Marks a player as the VIP",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cs_make_vip_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1040F140
// Name: _dynamic_initializer_for__timeleft_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__timeleft_command__()
{
  ConCommand::ConCommand(
    this: &timeleft_command,
    pName: "timeleft",
    callback: timeleft,
    pHelpString: "prints the time remaining in the match",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__timeleft_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1040F170
// Name: _dynamic_initializer_for__autobuy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__autobuy__()
{
  ConCommand::ConCommand(
    this: &autobuy,
    pName: "autobuy",
    callback: AutoBuy,
    pHelpString: "Attempt to purchase items with the order listed in cl_autobuy",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__autobuy__);
}

//------------------------------------------------------------------------------
// Address: 0x1040F1A0
// Name: _dynamic_initializer_for__rebuy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__rebuy__()
{
  ConCommand::ConCommand(
    this: &rebuy,
    pName: "rebuy",
    callback: Rebuy,
    pHelpString: "Attempt to repurchase items with the order listed in cl_rebuy",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__rebuy__);
}

//------------------------------------------------------------------------------
// Address: 0x1040F1D0
// Name: _dynamic_initializer_for__bot_take_control_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__bot_take_control_command__()
{
  ConCommand::ConCommand(
    this: &bot_take_control_command,
    pName: "bot_take_control",
    callback: (void (__cdecl *)())bot_take_control,
    pHelpString: "Take control of a bot.",
    flags: 4,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__bot_take_control_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1040F200
// Name: _dynamic_initializer_for__bot_stop_control_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__bot_stop_control_command__()
{
  ConCommand::ConCommand(
    this: &bot_stop_control_command,
    pName: "bot_stop_control",
    callback: bot_stop_control,
    pHelpString: "Release control of a bot.",
    flags: 4,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__bot_stop_control_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1040F230
// Name: _dynamic_initializer_for__g_CCSPlayerResource_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CCSPlayerResource_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CCSPlayerResource_ClassReg,
           pNetworkName: "CCSPlayerResource",
           pTable: &DT_CSPlayerResource::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1041FBE0
// Name: _ServerClassInit_DT_TEPlayerAnimEvent::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_TEPlayerAnimEvent::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_146;
  for ( i = 3; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041FC00
// Name: _dynamic_atexit_destructor_for__g_TEPlayerAnimEvent__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_TEPlayerAnimEvent__()
{
  CBaseTempEntity::~CBaseTempEntity(this: &g_TEPlayerAnimEvent);
}

//------------------------------------------------------------------------------
// Address: 0x1041FC20
// Name: _ServerClassInit_DT_CSLocalPlayerExclusive::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_CSLocalPlayerExclusive::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S4_68;
  for ( i = 8; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041FC50
// Name: _ServerClassInit_DT_CSNonLocalPlayerExclusive::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_CSNonLocalPlayerExclusive::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S5_38;
  for ( i = 2; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041FC80
// Name: _ServerClassInit_DT_CSPlayer::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_CSPlayer::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S6_29;
  for ( i = 48; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041FCA0
// Name: _dynamic_atexit_destructor_for__cc_CreatePredictionError__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cc_CreatePredictionError__()
{
  ConCommand::~ConCommand(this: &cc_CreatePredictionError);
}

//------------------------------------------------------------------------------
// Address: 0x1041FCB0
// Name: _dynamic_atexit_destructor_for__sv_runcmds__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_runcmds__()
{
  ConVar::~ConVar(this: &sv_runcmds);
}

//------------------------------------------------------------------------------
// Address: 0x1041FCC0
// Name: _dynamic_atexit_destructor_for__cs_make_vip_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cs_make_vip_command__()
{
  ConCommand::~ConCommand(this: &cs_make_vip_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041FCD0
// Name: _dynamic_atexit_destructor_for__timeleft_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__timeleft_command__()
{
  ConCommand::~ConCommand(this: &timeleft_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041FCE0
// Name: _dynamic_atexit_destructor_for__autobuy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__autobuy__()
{
  ConCommand::~ConCommand(this: &autobuy);
}

//------------------------------------------------------------------------------
// Address: 0x1041FCF0
// Name: _dynamic_atexit_destructor_for__rebuy__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rebuy__()
{
  ConCommand::~ConCommand(this: &rebuy);
}

//------------------------------------------------------------------------------
// Address: 0x1041FD00
// Name: _dynamic_atexit_destructor_for__bot_take_control_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bot_take_control_command__()
{
  ConCommand::~ConCommand(this: &bot_take_control_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041FD10
// Name: _dynamic_atexit_destructor_for__bot_stop_control_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__bot_stop_control_command__()
{
  ConCommand::~ConCommand(this: &bot_stop_control_command);
}

//------------------------------------------------------------------------------
// Address: 0x1041FD20
// Name: _ServerClassInit_DT_CSRagdoll::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_CSRagdoll::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S2_242;
  for ( i = 11; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041FD40
// Name: _DataMapInit_CCSPlayer__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CCSPlayer__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_472);
}
