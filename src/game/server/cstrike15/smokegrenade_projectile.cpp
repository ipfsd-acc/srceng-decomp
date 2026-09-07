// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/smokegrenade_projectile.cpp
// Functions: 13
// ============================================================

#include "game\server\cstrike15\smokegrenade_projectile.h"

//------------------------------------------------------------------------------
// Address: 0x102A58F0
// Name: public: virtual void smokegrenade_projectilePrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall smokegrenade_projectilePrecache::CResourcePrecacher::Cache(
        smokegrenade_projectilePrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "smokegrenade_projectile",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102A5920
// Name: public: virtual struct datamap_t __near * CSmokeGrenadeProjectile::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CSmokeGrenadeProjectile::GetDataDescMap(CSmokeGrenadeProjectile *this)
{
  return &CSmokeGrenadeProjectile::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102A5930
// Name: public: virtual void CSmokeGrenadeProjectile::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSmokeGrenadeProjectile::Spawn(CSmokeGrenadeProjectile *this)
{
  this->SetModel(this, a2: "models/Weapons/w_eq_smokegrenade_thrown.mdl");
  CBaseCSGrenadeProjectile::Spawn(this);
}

//------------------------------------------------------------------------------
// Address: 0x102A5950
// Name: public: virtual void CSmokeGrenadeProjectile::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSmokeGrenadeProjectile::Precache(
        CSmokeGrenadeProjectile *this@<ecx>,
        bool (__cdecl *a2)(const char *)@<edi>)
{
  CBaseEntity::PrecacheModel(a1: a2, name: "models/Weapons/w_eq_smokegrenade_thrown.mdl", bPreload: true);
  CBaseEntity::PrecacheScriptSound(soundname: "BaseSmokeEffect.Sound");
  CBaseEntity::PrecacheScriptSound(soundname: "SmokeGrenade.Bounce");
  CBaseCSGrenadeProjectile::Precache(this);
}

//------------------------------------------------------------------------------
// Address: 0x102A5980
// Name: public: virtual void CSmokeGrenadeProjectile::BounceSound(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSmokeGrenadeProjectile::BounceSound(CSmokeGrenadeProjectile *this)
{
  if ( !this->m_bDidSmokeEffect )
    CBaseEntity::EmitSound(this, soundname: "SmokeGrenade.Bounce", soundtime: 0.0, duration: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102A59A0
// Name: public: void CSmokeGrenadeProjectile::Think_Remove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSmokeGrenadeProjectile::Think_Remove(CSmokeGrenadeProjectile *this)
{
  CBotManager::RemoveGrenade(this: TheBots, grenade: this);
  this->m_ModelName.pszValue = nullptr;
  CBaseEntity::DispatchUpdateTransmitState(this);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_NONE, moveCollide: MOVECOLLIDE_DEFAULT);
}

//------------------------------------------------------------------------------
// Address: 0x102A59F0
// Name: public: void CSmokeGrenadeProjectile::Think_Fade(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSmokeGrenadeProjectile::Think_Fade(CSmokeGrenadeProjectile *this)
{
  unsigned __int8 v2; // bl
  edict_t *m_pPev; // ecx

  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
  v2 = this->m_clrRender.m_Value.a - 1;
  if ( this->m_Network.m_TimerEvent.m_bRegistered )
  {
    *((_BYTE *)&this->m_Network + 76) |= 1u;
  }
  else
  {
    m_pPev = this->m_Network.m_pPev;
    if ( m_pPev != nullptr )
      CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xB8u);
  }
  this->m_clrRender.m_Value.a = v2;
  if ( v2 == 0 )
  {
    CBotManager::RemoveGrenade(this: TheBots, grenade: this);
    this->m_ModelName.pszValue = nullptr;
    CBaseEntity::DispatchUpdateTransmitState(this);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 20.0, szContext: nullptr);
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CSmokeGrenadeProjectile::Think_Remove,
      thinkTime: 0.0,
      szContext: nullptr);
    CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A5AB0
// Name: public: void CSmokeGrenadeProjectile::Think_Detonate(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSmokeGrenadeProjectile::Think_Detonate(
        CSmokeGrenadeProjectile *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>)
{
  CBaseEntity *i; // edi
  float v6; // xmm0_4
  float v7; // xmm1_4
  CBaseCombatCharacter *Thrower; // edi
  IGameEvent *v9; // edi
  int v10; // eax
  edict_t *m_pPev; // ecx
  QAngle v12; // [esp+4Ch] [ebp-64h] BYREF
  int v13; // [esp+64h] [ebp-4Ch]
  int v14; // [esp+68h] [ebp-48h]
  float x; // [esp+70h] [ebp-40h]
  float y; // [esp+74h] [ebp-3Ch]
  float z; // [esp+78h] [ebp-38h]
  _DWORD *v18; // [esp+A0h] [ebp-10h]
  _DWORD v19[2]; // [esp+A4h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+B0h] [ebp+0h]

  v19[0] = a2;
  v19[1] = retaddr;
  v14 = a4;
  v13 = a3;
  if ( (this->m_iEFlags & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)v19);
  if ( fsqrt(
         (float)((float)(this->m_vecAbsVelocity.z * this->m_vecAbsVelocity.z)
               + (float)(this->m_vecAbsVelocity.x * this->m_vecAbsVelocity.x))
       + (float)(this->m_vecAbsVelocity.y * this->m_vecAbsVelocity.y)) <= 0.1 )
  {
    CBotManager::SetGrenadeRadius(this: TheBots, grenade: this, radius: 155.0);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)v19);
    memset((void *)&v12, 0, sizeof(v12));
    DispatchParticleEffect(
      pszParticleName: "explosion_smokegrenade",
      vecOrigin: this->m_vecAbsOrigin,
      vecAngles: v12,
      pEntity: nullptr,
      nSplitScreenPlayerSlot: -1,
      filter: nullptr);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)v19);
    x = this->m_vecAbsOrigin.x;
    y = this->m_vecAbsOrigin.y;
    z = this->m_vecAbsOrigin.z;
    for ( i = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: nullptr, szName: "hostage_entity");
          i != nullptr;
          i = CGlobalEntityList::FindEntityByClassname(this: &gEntList, pStartEntity: i, szName: "hostage_entity") )
    {
      if ( (i->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: i, a2: (int)v19);
      if ( (this->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)v19);
      v6 = this->m_vecAbsOrigin.z - i->m_vecAbsOrigin.z;
      v7 = this->m_vecAbsOrigin.x - i->m_vecAbsOrigin.x;
      if ( fsqrt(
             (float)((float)(v6 * v6)
                   + (float)((float)(this->m_vecAbsOrigin.y - i->m_vecAbsOrigin.y)
                           * (float)(this->m_vecAbsOrigin.y - i->m_vecAbsOrigin.y)))
           + (float)(v7 * v7)) < 1000.0 )
        ((void (__thiscall *)(CBaseEntity *, const char *, CSmokeGrenadeProjectile *, CSmokeGrenadeProjectile *, float, float, float, int, int, _DWORD))i->AcceptInput)(
          a1: i,
          a2: "smokegrenade",
          a3: this,
          a4: this,
          a5: COERCE_FLOAT(LODWORD(x)),
          a6: COERCE_FLOAT(LODWORD(y)),
          a7: COERCE_FLOAT(LODWORD(z)),
          a8: -1,
          a9: 3,
          a10: 0);
    }
    Thrower = CBaseGrenade::GetThrower(this);
    if ( Thrower != nullptr && Thrower->IsPlayer(this: Thrower) )
    {
      v18 = __RTDynamicCast(
              inptr: Thrower,
              VfDelta: 0,
              SrcType: &CBaseEntity `RTTI Type Descriptor',
              TargetType: &CCSPlayer `RTTI Type Descriptor',
              isReference: 0);
      if ( v18 != nullptr )
      {
        v9 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "smokegrenade_detonate", a3: 0, a4: 0);
        if ( v9 != nullptr )
        {
          v10 = ((int (__thiscall *)(IVEngineServer *, _DWORD, int, int))engine->GetPlayerUserId)(
                  a1: engine,
                  a2: v18[6],
                  a3: v13,
                  a4: v14);
          v9->SetInt(this: v9, a2: "userid", a3: v10);
          if ( (this->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this, a2: (int)v19);
          ((void (__thiscall *)(IGameEvent *, const char *, _DWORD))v9->SetFloat)(
            a1: v9,
            a2: "x",
            a3: LODWORD(this->m_vecAbsOrigin.x));
          if ( (this->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this, a2: (int)v19);
          ((void (__thiscall *)(IGameEvent *, const char *, _DWORD))v9->SetFloat)(
            a1: v9,
            a2: "y",
            a3: LODWORD(this->m_vecAbsOrigin.y));
          if ( (this->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this, a2: (int)v19);
          ((void (__thiscall *)(IGameEvent *, const char *, _DWORD))v9->SetFloat)(
            a1: v9,
            a2: "z",
            a3: LODWORD(this->m_vecAbsOrigin.z));
          ((void (__thiscall *)(IGameEventManager2 *))gameeventmanager->FireEvent)(a1: gameeventmanager);
        }
      }
    }
    this->m_bDidSmokeEffect = true;
    CBaseEntity::EmitSound(this, soundname: "BaseSmokeEffect.Sound", soundtime: 0.0, duration: nullptr);
    if ( this->m_nRenderMode.m_Value != 1 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        m_pPev = this->m_Network.m_pPev;
        if ( m_pPev != nullptr )
          CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0xB5u);
      }
      this->m_nRenderMode.m_Value = 1;
    }
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 5.0, szContext: nullptr);
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CSmokeGrenadeProjectile::Think_Fade,
      thinkTime: 0.0,
      szContext: nullptr);
  }
  else
  {
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.2, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A6110
// Name: public: static class CSmokeGrenadeProjectile __near * CSmokeGrenadeProjectile::Create(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class CBaseCombatCharacter __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
CSmokeGrenadeProjectile *__cdecl CSmokeGrenadeProjectile::Create(
        const Vector *position,
        const QAngle *angles,
        const Vector *velocity,
        const Vector *angVelocity,
        CBaseCombatCharacter *pOwner,
        QAngle *color)
{
  CBaseEntity *v6; // esi
  CBaseEdict *v7; // ecx
  CBaseEntity_vtbl *v8; // edi
  int TeamNumber; // eax
  CBaseEdict *v10; // ecx

  v6 = CBaseEntity::Create(szName: "smokegrenade_projectile", vecOrigin: position, vecAngles: angles, pOwner);
  CBaseEntity::ThinkSet(
    this: v6,
    func: (void (__thiscall *)(CBaseEntity *))CSmokeGrenadeProjectile::Think_Detonate,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this: v6, thinkTime: gpGlobals->curtime + 1.5, szContext: nullptr);
  CBotManager::SetGrenadeRadius(this: TheBots, grenade: (CBaseGrenade *)v6, radius: 0.0);
  CBaseEntity::SetAbsVelocity(this: v6, vecAbsVelocity: velocity);
  CBaseCSGrenadeProjectile::SetupInitialTransmittedGrenadeVelocity(this: (CBaseCSGrenadeProjectile *)v6, velocity);
  CBaseGrenade::SetThrower(this: (CBaseGrenade *)v6, pThrower: pOwner);
  v6->m_flGravity = 0.55000001;
  CBaseEntity::SetFriction(this: v6, flFriction: 0.69999999);
  if ( *(float *)&v6[1].m_nWaterTouch != 100.0 )
  {
    if ( v6->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v6->m_Network + 76) |= 1u;
    }
    else
    {
      v7 = &v6->m_Network.m_pPev->CBaseEdict;
      if ( v7 != nullptr )
        CBaseEdict::StateChanged(this: v7, offset: 0x4A4u);
    }
    *(_DWORD *)&v6[1].m_nWaterTouch = 1120403456;
  }
  v8 = v6->__vftable;
  TeamNumber = CBaseEntity::GetTeamNumber(this: pOwner);
  v8->ChangeTeam(this: v6, a2: TeamNumber);
  CBaseEntity::ApplyLocalAngularVelocityImpulse(this: v6, angImpulse: angVelocity);
  v6->m_flGravity = 0.40000001;
  v6->m_pfnTouch = (void (__thiscall *)(CBaseEntity *, CBaseEntity *))CBaseGrenade::BounceTouch;
  CBaseEntity::SetFriction(this: v6, flFriction: 0.2);
  if ( v6->m_flElasticity.m_Value != 0.44999999 )
  {
    if ( v6->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v6->m_Network + 76) |= 1u;
    }
    else
    {
      v10 = &v6->m_Network.m_pPev->CBaseEdict;
      if ( v10 != nullptr )
        CBaseEdict::StateChanged(this: v10, offset: 0x1B8u);
    }
    v6->m_flElasticity.m_Value = 0.44999999;
  }
  LOBYTE(v6[1].m_vecAbsVelocity.z) = 0;
  v6[1].m_vecAngVelocity = *color;
  LODWORD(v6[1].m_vecAbsVelocity.x) = GetWeaponInfo(weaponID: WEAPON_SMOKEGRENADE);
  return (CSmokeGrenadeProjectile *)v6;
}

//------------------------------------------------------------------------------
// Address: 0x10410530
// Name: _dynamic_initializer_for__smokegrenade_projectile__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__smokegrenade_projectile__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CSmokeGrenadeProjectile> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &smokegrenade_projectile,
           a3: "smokegrenade_projectile");
}

//------------------------------------------------------------------------------
// Address: 0x10410550
// Name: smokegrenade_projectilePrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int smokegrenade_projectilePrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  smokegrenade_projectilePrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&smokegrenade_projectilePrecache::s_ResourcePrecacher;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10410570
// Name: CSmokeGrenadeProjectile_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CSmokeGrenadeProjectile_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CSmokeGrenadeProjectile>();
  CSmokeGrenadeProjectile_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10410580
// Name: _dynamic_initializer_for__g_CTERadioIcon_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CTERadioIcon_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CTERadioIcon_ClassReg,
           pNetworkName: "CTERadioIcon",
           pTable: &DT_TERadioIcon::g_SendTable);
}
