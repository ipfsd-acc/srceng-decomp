// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/item_world.cpp
// Functions: 30
// ============================================================

#include "game\server\item_world.h"

//------------------------------------------------------------------------------
// Address: 0x101630D0
// Name: private: virtual struct datamap_t __near * CWorldItem::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CWorldItem::GetDataDescMap(CWorldItem *this)
{
  return &CWorldItem::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101630E0
// Name: public: virtual struct datamap_t __near * CItem::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CItem::GetDataDescMap(CItem *this)
{
  return &CItem::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x101630F0
// Name: public: virtual CItem::~CItem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CItem::~CItem(CItem *this)
{
  IPhysicsConstraint *m_pConstraint; // eax

  m_pConstraint = this->m_pConstraint;
  this->CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CItem_vtbl *)&CItem::`vftable'{for `CBaseAnimating'};
  this->CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&CItem::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  if ( m_pConstraint != nullptr )
  {
    physenv->DestroyConstraint(this: physenv, a2: m_pConstraint);
    this->m_pConstraint = nullptr;
  }
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnCacheInteraction);
  CBaseEntityOutput::~CBaseEntityOutput(this: &this->m_OnPlayerTouch);
  CBaseAnimating::~CBaseAnimating(this);
}

//------------------------------------------------------------------------------
// Address: 0x10163150
// Name: public: virtual int CItem::ObjectCaps(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CItem::ObjectCaps(CItem *this)
{
  return CBaseEntity::ObjectCaps(this) | 0x40000001;
}

//------------------------------------------------------------------------------
// Address: 0x10163160
// Name: public: virtual void CItem::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CItem::Precache(CItem *this)
{
  CBaseAnimating::Precache(this);
  CBaseEntity::PrecacheScriptSound(soundname: "Item.Materialize");
}

//------------------------------------------------------------------------------
// Address: 0x10163180
// Name: public: virtual bool CWorldItem::KeyValue(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CWorldItem::KeyValue(CWorldItem *this, char *szKeyName, const char *szValue)
{
  if ( szKeyName != "type" && _V_stricmp(s1: szKeyName, s2: "type") != 0 )
    return CBaseEntity::KeyValue(this, szKeyName, szValue);
  this->m_iType = atoi(nptr: szValue);
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10163280
// Name: public: void CItem::ItemTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CItem::ItemTouch(CItem *this, CBasePlayer *pOther)
{
  CBasePlayer *v2; // edi
  IServerVehicle *v4; // eax

  v2 = pOther;
  if ( pOther->GetServerVehicle(this: pOther) == nullptr
    || (v4 = pOther->GetServerVehicle(this: pOther), (v2 = (CBasePlayer *)v4->GetPassenger(this: v4, a2: 0)) != nullptr) )
  {
    if ( v2->IsPlayer(this: v2) && this->ItemCanBeTouchedByPlayer(this, a2: v2) )
    {
      COutputEvent::FireOutput(this: &this->m_OnCacheInteraction, pActivator: v2, pCaller: this, fDelay: 0.0);
      if ( !v2->m_bPreventWeaponPickup && g_pGameRules->CanHaveItem(this: g_pGameRules, a2: v2, a3: this) )
      {
        if ( this->MyTouch(this, a2: v2) )
        {
          COutputEvent::FireOutput(this: &this->m_OnPlayerTouch, pActivator: v2, pCaller: this, fDelay: 0.0);
          this->m_pfnTouch = nullptr;
          CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
          g_pGameRules->PlayerGotItem(this: g_pGameRules, a2: v2, a3: this);
          if ( g_pGameRules->ItemShouldRespawn(this: g_pGameRules, a2: this) == 5 )
          {
            this->Respawn(this);
            return;
          }
        }
        else if ( gEvilImpulse101 == 0 )
        {
          return;
        }
        UTIL_Remove(oldObj: this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101633C0
// Name: public: virtual void CItem::OnPhysGunPickup(class CBasePlayer __near *,enum PhysGunPickup_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CItem::OnPhysGunPickup(CItem *this, CBasePlayer *pPhysGunUser, PhysGunPickup_t reason)
{
  COutputEvent::FireOutput(
    this: (COutputEvent *)&this->m_Network.m_PVSInfo.m_pClusters,
    pActivator: pPhysGunUser,
    pCaller: (CItem *)((char *)this - 1164),
    fDelay: 0.0);
  if ( reason == PICKED_UP_BY_CANNON )
  {
    CCollisionProperty::UseTriggerBounds(this: (CCollisionProperty *)((char *)this - 936), bEnable: true, flBloat: 48.0);
    if ( this->m_Network.m_TimerEvent.m_pCallback != nullptr )
    {
      physenv->DestroyConstraint(this: physenv, a2: (IPhysicsConstraint *)this->m_Network.m_TimerEvent.m_pCallback);
      this->m_Network.m_TimerEvent.m_pCallback = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10163430
// Name: public: virtual void CItem::OnPhysGunDrop(class CBasePlayer __near *,enum PhysGunDrop_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CItem::OnPhysGunDrop(CItem *this, CBasePlayer *pPhysGunUser, CBasePlayer *reason)
{
  CCollisionProperty::UseTriggerBounds(this: (CCollisionProperty *)((char *)this - 936), bEnable: true, flBloat: 24.0);
}

//------------------------------------------------------------------------------
// Address: 0x10163460
// Name: public: bool CItem::CreateItemVPhysicsObject(void)
// Source: json
//------------------------------------------------------------------------------
char __usercall CItem::CreateItemVPhysicsObject@<al>(CItem *this@<ecx>, int a2@<ebp>)
{
  int v3; // eax
  int v4; // ebx
  const char *pszValue; // eax

  v3 = this->m_Collision.GetSolidFlags(this: &this->m_Collision);
  v4 = v3 | 0x10;
  if ( !this->m_bActivateWhenAtRest )
    v4 = v3 | 0x18;
  if ( CBaseEntity::VPhysicsInitNormal(
         this,
         solidType: SOLID_VPHYSICS,
         nSolidFlags: v4,
         createAsleep: false,
         pSolid: nullptr) != nullptr )
    return 1;
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BBOX);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: v4 | this->m_Collision.m_usSolidFlags.m_Value);
  if ( UTIL_DropToFloor(pEntity: this, mask: 0x200400Bu, pIgnore: nullptr) != 0 )
    return 1;
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2);
  pszValue = this->m_iClassname.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  _Warning(
    a1: "Item %s fell out of level at %f,%f,%f\n",
    pszValue,
    this->m_vecAbsOrigin.x,
    this->m_vecAbsOrigin.y,
    this->m_vecAbsOrigin.z);
  UTIL_Remove(oldObj: this);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10163580
// Name: private: void CItem::ComeToRest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CItem::ComeToRest(CItem *this)
{
  if ( this->m_bActivateWhenAtRest )
  {
    this->m_bActivateWhenAtRest = false;
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 8);
    CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101635C0
// Name: public: virtual class CBaseEntity __near * CItem::Respawn(void)
// Source: json
//------------------------------------------------------------------------------
CItem *__thiscall CItem::Respawn(CItem *this)
{
  Vector *(__thiscall *VecItemRespawnSpot)(CGameRules *, Vector *, CItem *); // edx
  const Vector *v3; // eax
  const QAngle *v4; // eax
  float v6; // [esp+14h] [ebp-1Ch]
  bool bFireTriggers[12]; // [esp+24h] [ebp-Ch] BYREF

  this->m_pfnTouch = nullptr;
  CBaseEntity::AddEffects(this, nEffects: 32);
  this->VPhysicsDestroyObject(this);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BBOX);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 8);
  VecItemRespawnSpot = g_pGameRules->VecItemRespawnSpot;
  *(_DWORD *)bFireTriggers = 0;
  v3 = (const Vector *)((int (__thiscall *)(CGameRules *))VecItemRespawnSpot)(a1: g_pGameRules);
  UTIL_SetOrigin(entity: this, vecOrigin: v3, (bool)bFireTriggers);
  v4 = (const QAngle *)((int (__thiscall *)(CGameRules *))g_pGameRules->VecItemRespawnAngles)(a1: g_pGameRules);
  CBaseEntity::SetAbsAngles(this, absAngles: v4);
  UTIL_DropToFloor(pEntity: this, mask: 0x200400Bu, pIgnore: nullptr);
  CBaseEntity::RemoveAllDecals(this);
  CBaseEntity::ThinkSet(this, func:  __thiscall CItem::`vcall'{920,{flat}}, thinkTime: 0.0, szContext: nullptr);
  v6 = ((double (__thiscall *)(CGameRules *, CItem *, _DWORD))g_pGameRules->FlItemRespawnTime)(
         a1: g_pGameRules,
         a2: this,
         a3: 0)
     + gpGlobals->curtime;
  CBaseEntity::SetNextThink(this, thinkTime: v6, szContext: (const char *)bFireTriggers);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101636F0
// Name: public: CItem::CItem(void)
// Source: json
//------------------------------------------------------------------------------
CItem *__thiscall CItem::CItem(CItem *this)
{
  CBaseAnimating::CBaseAnimating(this);
  this->CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&CDefaultPlayerPickupVPhysics::`vftable';
  this->CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CItem_vtbl *)&CItem::`vftable'{for `CBaseAnimating'};
  this->CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&CItem::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  this->m_OnPlayerTouch.m_Value.iVal = 0;
  this->m_OnPlayerTouch.m_Value.eVal.m_Index = -1;
  this->m_OnPlayerTouch.m_Value.fieldType = FIELD_VOID;
  this->m_OnCacheInteraction.m_Value.iVal = 0;
  this->m_OnCacheInteraction.m_Value.eVal.m_Index = -1;
  this->m_OnCacheInteraction.m_Value.fieldType = FIELD_VOID;
  this->m_bActivateWhenAtRest = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10163750
// Name: public: virtual void CItem::OnEntityEvent(enum EntityEvent_t,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CItem::OnEntityEvent(CItem *this, EntityEvent_t event, void *pEventData)
{
  CBaseEntity::OnEntityEvent(this, event, pEventData);
  if ( event == ENTITY_EVENT_WATER_TOUCH )
  {
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CItem::ComeToRest,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101637B0
// Name: bool UTIL_ItemCanBeTouchedByPlayer(class CBaseEntity __near *,class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl UTIL_ItemCanBeTouchedByPlayer(CBaseEntity *pItem, CBasePlayer *pPlayer)
{
  IPhysicsObject *m_pPhysicsObject; // ecx
  CGameTrace tr; // [esp+8h] [ebp-8Ch] BYREF
  QAngle vecAngles; // [esp+5Ch] [ebp-38h] BYREF
  CTraceFilterSkipTwoEntities filter; // [esp+68h] [ebp-2Ch] BYREF
  Vector vecEndPos; // [esp+7Ch] [ebp-18h] BYREF
  Vector vecStartPos; // [esp+88h] [ebp-Ch] BYREF
  int savedregs; // [esp+94h] [ebp+0h] BYREF

  if ( pItem == nullptr || pPlayer == nullptr )
    return false;
  if ( pPlayer->IsInAVehicle(this: pPlayer) )
    return true;
  m_pPhysicsObject = pItem->m_pPhysicsObject;
  if ( m_pPhysicsObject != nullptr )
    m_pPhysicsObject->GetPosition(this: m_pPhysicsObject, a2: &vecStartPos, a3: &vecAngles);
  else
    vecStartPos = *CCollisionProperty::WorldSpaceCenter(this: &pItem->m_Collision);
  pPlayer->EyePosition(this: pPlayer, result: &vecEndPos);
  CTraceFilterSkipTwoEntities::CTraceFilterSkipTwoEntities(
    this: &filter,
    passentity: pPlayer,
    passentity2: pItem,
    collisionGroup: 8);
  UTIL_TraceLine(
    a1: (int)&savedregs,
    a2: (int)pPlayer,
    vecAbsStart: &vecStartPos,
    vecAbsEnd: &vecEndPos,
    mask: 0x200400Bu,
    pFilter: &filter,
    ptr: &tr);
  return tr.fraction >= 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10163890
// Name: public: virtual bool CItem::ItemCanBeTouchedByPlayer(class CBasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CItem::ItemCanBeTouchedByPlayer(CItem *this, CBasePlayer *pPlayer)
{
  return UTIL_ItemCanBeTouchedByPlayer(pItem: this, pPlayer);
}

//------------------------------------------------------------------------------
// Address: 0x101638B0
// Name: public: virtual void CItem::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CItem::Spawn(CItem *this)
{
  IPhysicsObject *v2; // edi
  IPhysicsObject *m_pPhysicsObject; // ebx
  IPhysicsConstraint *v4; // eax
  float z; // edx
  unsigned int v6; // eax
  __int64 v7; // xmm0_8
  constraint_fixedparams_t fixed; // [esp+10h] [ebp-60h] BYREF
  QAngle angles; // [esp+58h] [ebp-18h] BYREF
  Vector origin; // [esp+64h] [ebp-Ch] BYREF
  int savedregs; // [esp+70h] [ebp+0h] BYREF

  CBaseEntity::SetNetworkQuantizeOriginAngAngles(this, bQuantize: true);
  if ( g_pGameRules->IsAllowedToSpawn(this: g_pGameRules, a2: this) )
  {
    CBaseEntity::SetMoveType(this, val: MOVETYPE_FLYGRAVITY, moveCollide: MOVECOLLIDE_DEFAULT);
    CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BBOX);
    CBaseEntity::SetBlocksLOS(this, bBlocksLOS: false);
    this->m_iEFlags |= 0x200000u;
    CBaseEntity::SetCollisionGroup(this, collisionGroup: 11);
    if ( this->HasBloatedCollision(this) )
      CCollisionProperty::UseTriggerBounds(this: &this->m_Collision, bEnable: true, flBloat: 24.0);
    this->m_pfnTouch = (void (__thiscall *)(CBaseEntity *, CBaseEntity *))CItem::ItemTouch;
    if ( CItem::CreateItemVPhysicsObject(this, a2: (int)&savedregs) != 0 )
    {
      if ( this->m_takedamage.m_Value != 1 )
      {
        this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
        this->m_takedamage.m_Value = 1;
      }
      if ( (this->m_spawnflags.m_Value & 1) != 0 )
      {
        v2 = g_PhysWorldObject;
        m_pPhysicsObject = this->m_pPhysicsObject;
        if ( g_PhysWorldObject != nullptr && m_pPhysicsObject != nullptr )
        {
          constraint_fixedparams_t::Defaults(this: &fixed);
          constraint_fixedparams_t::InitWithCurrentObjectState(this: &fixed, pRef: v2, pAttached: m_pPhysicsObject);
          fixed.constraint.forceLimit = 4545.4546;
          fixed.constraint.torqueLimit = 4545.4546;
          v4 = physenv->CreateFixedConstraint(this: physenv, a2: v2, a3: m_pPhysicsObject, a4: 0, a5: &fixed);
          this->m_pConstraint = v4;
          v4->SetGameData(this: v4, a2: this);
        }
      }
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      z = this->m_vecAbsOrigin.z;
      v6 = (unsigned int)this->m_iEFlags >> 11;
      *(_QWORD *)&origin.x = *(_QWORD *)&this->m_vecAbsOrigin.x;
      origin.z = z;
      if ( (v6 & 1) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      v7 = *(_QWORD *)&this->m_angAbsRotation.x;
      angles.z = this->m_angAbsRotation.z;
      *(_QWORD *)&angles.x = v7;
      CBaseEntity::NetworkQuantize(this, org: &origin, &angles);
      CBaseEntity::SetAbsOrigin(this, absOrigin: &origin);
      CBaseEntity::SetAbsAngles(this, absAngles: &angles);
    }
  }
  else
  {
    UTIL_Remove(oldObj: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10163A70
// Name: public: virtual void CWorldItem::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorldItem::Spawn(CWorldItem *this)
{
  CBaseEntity *v2; // eax
  CBaseEntity *v3; // esi
  const char *pszValue; // edx
  CBaseEdict *v5; // ecx
  CBaseEdict *v6; // ecx
  int m_Value; // eax
  int v8; // edi
  CBaseEdict *v9; // ecx
  const char *v10; // [esp+8h] [ebp-4h]

  if ( this->m_iType == 44 )
  {
    v2 = CBaseEntity::Create(
           szName: "item_battery",
           vecOrigin: &this->m_vecOrigin.m_Value,
           vecAngles: &this->m_angRotation.m_Value,
           pOwner: nullptr);
  }
  else
  {
    if ( this->m_iType != 45 )
    {
LABEL_6:
      _Warning(a1: "unable to create world_item %d\n", this->m_iType);
      UTIL_RemoveImmediate(oldObj: this);
      return;
    }
    v2 = CBaseEntity::Create(
           szName: "item_suit",
           vecOrigin: &this->m_vecOrigin.m_Value,
           vecAngles: &this->m_angRotation.m_Value,
           pOwner: nullptr);
  }
  v3 = v2;
  if ( v2 == nullptr )
    goto LABEL_6;
  v2->m_target.pszValue = this->m_target.pszValue;
  pszValue = this->m_iName.m_Value.pszValue;
  v10 = pszValue;
  if ( v2->m_iName.m_Value.pszValue != pszValue )
  {
    if ( v2->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v2->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = &v2->m_Network.m_pPev->CBaseEdict;
      if ( v5 != nullptr )
      {
        CBaseEdict::StateChanged(this: v5, offset: 0xCCu);
        pszValue = v10;
      }
    }
    v3->m_iName.m_Value.pszValue = pszValue;
  }
  CGlobalEntityList::UpdateName(this: &gEntList, pEnt: v3);
  if ( v3->m_spawnflags.m_Value != 0 )
  {
    if ( v3->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v3->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = &v3->m_Network.m_pPev->CBaseEdict;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0x2F8u);
    }
    v3->m_spawnflags.m_Value = 0;
  }
  m_Value = v3->m_spawnflags.m_Value;
  v8 = m_Value | this->m_spawnflags.m_Value;
  if ( m_Value != v8 )
  {
    if ( v3->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v3->m_Network + 76) |= 1u;
    }
    else
    {
      v9 = &v3->m_Network.m_pPev->CBaseEdict;
      if ( v9 != nullptr )
        CBaseEdict::StateChanged(this: v9, offset: 0x2F8u);
    }
    v3->m_spawnflags.m_Value = v8;
  }
  UTIL_RemoveImmediate(oldObj: this);
}

//------------------------------------------------------------------------------
// Address: 0x10163BC0
// Name: public: virtual void CItem::Materialize(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CItem::Materialize(CItem *this@<ecx>, int a2@<ebp>)
{
  unsigned int v3; // esi
  edict_t *m_pPev; // ecx

  CItem::CreateItemVPhysicsObject(this, a2);
  if ( (this->m_fEffects.m_Value & 0x20) != 0 )
  {
    CBaseEntity::EmitSound(this, soundname: "Item.Materialize", soundtime: 0.0, duration: nullptr);
    v3 = this->m_fEffects.m_Value & 0xFFFFFFDF;
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
    if ( this->m_Network.m_pPev != nullptr )
      this->m_Network.m_pPev->m_fStateFlags |= 0x80u;
    CBaseEntity::DispatchUpdateTransmitState(this);
    CBaseAnimating::DoMuzzleFlash(this);
  }
  this->m_pfnTouch = (void (__thiscall *)(CBaseEntity *, CBaseEntity *))CItem::ItemTouch;
}

//------------------------------------------------------------------------------
// Address: 0x10401C20
// Name: _dynamic_initializer_for__item_sodacan__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__item_sodacan__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CItemSoda> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &item_sodacan,
           a3: "item_sodacan");
}

//------------------------------------------------------------------------------
// Address: 0x10405540
// Name: _dynamic_initializer_for__world_items__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__world_items__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CWorldItem> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &world_items,
           a3: "world_items");
}

//------------------------------------------------------------------------------
// Address: 0x10405560
// Name: CWorldItem_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CWorldItem_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CWorldItem>(__formal: nullptr);
  CWorldItem_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405570
// Name: CItem_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CItem_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CItem>(__formal: nullptr);
  CItem_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10410370
// Name: _dynamic_initializer_for__item_assaultsuit__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__item_assaultsuit__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CItemAssaultSuit> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &item_assaultsuit,
           a3: "item_assaultsuit");
}

//------------------------------------------------------------------------------
// Address: 0x10410390
// Name: _dynamic_initializer_for__item_defuser__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__item_defuser__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CItemDefuser> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &item_defuser,
           a3: "item_defuser");
}

//------------------------------------------------------------------------------
// Address: 0x10410400
// Name: _dynamic_initializer_for__item_kevlar__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__item_kevlar__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CItemKevlar> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &item_kevlar,
           a3: "item_kevlar");
}

//------------------------------------------------------------------------------
// Address: 0x10410420
// Name: _dynamic_initializer_for__item_nvgs__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__item_nvgs__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CItemNvgs> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &item_nvgs,
           a3: "item_nvgs");
}

//------------------------------------------------------------------------------
// Address: 0x10163C60
// Name: struct datamap_t __near * DataMapInit<class CWorldItem>(class CWorldItem __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CWorldItem>()
{
  if ( (_S2_139 & 1) == 0 )
  {
    _S2_139 |= 1u;
    nameHolder_241.m_pszBase = "CWorldItem";
    nameHolder_241.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_241.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_241.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_241.m_Names.m_Size = 0;
    nameHolder_241.m_Names.m_pElements = nullptr;
    nameHolder_241.m_nLenBase = 10;
    atexit(func: DataMapInit_CWorldItem__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CWorldItem::m_DataMap.baseMap = &CBaseAnimating::m_DataMap;
  CWorldItem::m_DataMap.dataNumFields = 1;
  CWorldItem::m_DataMap.dataDesc = &dataDesc_228[1];
  return &CWorldItem::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10163CD0
// Name: struct datamap_t __near * DataMapInit<class CItem>(class CItem __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CItem>()
{
  if ( (_S3_76 & 1) == 0 )
  {
    _S3_76 |= 1u;
    nameHolder_242.m_pszBase = "CItem";
    nameHolder_242.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_242.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_242.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_242.m_Names.m_Size = 0;
    nameHolder_242.m_Names.m_pElements = nullptr;
    nameHolder_242.m_nLenBase = 5;
    atexit(func: DataMapInit_CItem__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CItem::m_DataMap.baseMap = &CBaseAnimating::m_DataMap;
  if ( (_S3_76 & 2) == 0 )
  {
    _S3_76 |= 2u;
    dataDesc_229[4].pSaveRestoreOps = GetPhysObjSaveRestoreOps(type: PIID_IPHYSICSCONSTRAINT);
    dataDesc_229[4].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_229[4].td = 0;
    *(_QWORD *)&dataDesc_229[4].override_field = 0;
    *(_QWORD *)&dataDesc_229[4].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_229[4].flatOffset[1] = 0;
    dataDesc_229[5].fieldType = FIELD_VOID;
    dataDesc_229[5].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_242,
                                  pszIdentifier: "ItemTouch");
    dataDesc_229[5].flags = 32;
    dataDesc_229[5].fieldOffset = 0;
    dataDesc_229[5].fieldSize = 1;
    dataDesc_229[5].externalName = nullptr;
    dataDesc_229[5].pSaveRestoreOps = nullptr;
    dataDesc_229[5].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CItem::ItemTouch;
    *(_QWORD *)&dataDesc_229[5].td = 0;
    *(_QWORD *)&dataDesc_229[5].override_field = 0;
    *(_QWORD *)&dataDesc_229[5].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_229[5].flatOffset[1] = 0;
    dataDesc_229[6].fieldType = FIELD_VOID;
    dataDesc_229[6].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_242,
                                  pszIdentifier: "Materialize");
    dataDesc_229[6].fieldOffset = 0;
    dataDesc_229[6].fieldSize = 1;
    dataDesc_229[6].flags = 32;
    dataDesc_229[6].externalName = nullptr;
    dataDesc_229[6].pSaveRestoreOps = nullptr;
    dataDesc_229[6].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *)) __thiscall CItem::`vcall'{920,{flat}};
    *(_QWORD *)&dataDesc_229[6].td = 0;
    *(_QWORD *)&dataDesc_229[6].override_field = 0;
    *(_QWORD *)&dataDesc_229[6].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_229[6].flatOffset[1] = 0;
    dataDesc_229[7].fieldType = FIELD_VOID;
    dataDesc_229[7].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_242,
                                  pszIdentifier: "ComeToRest");
    dataDesc_229[7].fieldSize = 1;
    dataDesc_229[7].flags = 32;
    dataDesc_229[8].fieldSize = 1;
    *(_QWORD *)&dataDesc_229[7].td = 0;
    *(_QWORD *)&dataDesc_229[7].override_field = 0;
    *(_QWORD *)&dataDesc_229[7].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_229[7].flatOffset[1] = 0;
    dataDesc_229[7].fieldOffset = 0;
    dataDesc_229[7].externalName = nullptr;
    dataDesc_229[7].pSaveRestoreOps = nullptr;
    dataDesc_229[7].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CItem::ComeToRest;
    dataDesc_229[8].fieldType = FIELD_CUSTOM;
    dataDesc_229[8].fieldName = "m_OnPlayerTouch";
    dataDesc_229[8].fieldOffset = 1172;
    dataDesc_229[8].flags = 22;
    dataDesc_229[8].externalName = "OnPlayerTouch";
    dataDesc_229[8].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_229[8].inputFunc = 0;
    *(_QWORD *)&dataDesc_229[8].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_229[8].override_count = 0;
    *(_QWORD *)dataDesc_229[8].flatOffset = 0;
    *(_DWORD *)&dataDesc_229[8].flatGroup = 0;
    dataDesc_229[9].fieldType = FIELD_CUSTOM;
    dataDesc_229[9].fieldName = "m_OnCacheInteraction";
    dataDesc_229[9].fieldOffset = 1196;
    *(_DWORD *)&dataDesc_229[9].fieldSize = 1441793;
    dataDesc_229[9].externalName = "OnCacheInteraction";
    dataDesc_229[9].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_229[9].inputFunc = 0;
    *(_QWORD *)&dataDesc_229[9].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_229[9].override_count = 0;
    *(_QWORD *)dataDesc_229[9].flatOffset = 0;
    *(_DWORD *)&dataDesc_229[9].flatGroup = 0;
  }
  CItem::m_DataMap.dataNumFields = 9;
  CItem::m_DataMap.dataDesc = &dataDesc_229[1];
  return &CItem::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10405580
// Name: _dynamic_initializer_for__g_CLightGlow_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CLightGlow_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CLightGlow_ClassReg,
           pNetworkName: "CLightGlow",
           pTable: &DT_LightGlow::g_SendTable);
}
