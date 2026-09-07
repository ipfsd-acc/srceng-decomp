// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/hegrenade_projectile.cpp
// Functions: 9
// ============================================================

#include "game\shared\cstrike15\hegrenade_projectile.h"

//------------------------------------------------------------------------------
// Address: 0x102A35D0
// Name: public: virtual void hegrenade_projectilePrecache::CResourcePrecacher::Cache(class IPrecacheHandler __near *,bool,struct ResourceList_t__ __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hegrenade_projectilePrecache::CResourcePrecacher::Cache(
        hegrenade_projectilePrecache::CResourcePrecacher *this,
        IPrecacheHandler *pPrecacheHandler,
        BOOL bPrecache,
        struct ResourceList_t__ *hResourceList,
        bool bIgnoreConditionals)
{
  pPrecacheHandler->CacheResource(
    this: pPrecacheHandler,
    a2: ENTITY,
    a3: "hegrenade_projectile",
    a4: bPrecache,
    a5: hResourceList,
    a6: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102A3600
// Name: public: virtual void CHEGrenadeProjectile::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHEGrenadeProjectile::Spawn(CHEGrenadeProjectile *this)
{
  this->SetModel(this, a2: "models/Weapons/w_eq_fraggrenade_thrown.mdl");
  CBaseCSGrenadeProjectile::Spawn(this);
}

//------------------------------------------------------------------------------
// Address: 0x102A3620
// Name: public: virtual void CHEGrenadeProjectile::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CHEGrenadeProjectile::Precache(
        CHEGrenadeProjectile *this@<ecx>,
        bool (__cdecl *a2)(const char *)@<edi>)
{
  CBaseEntity::PrecacheModel(a1: a2, name: "models/Weapons/w_eq_fraggrenade_thrown.mdl", bPreload: true);
  CBaseEntity::PrecacheScriptSound(soundname: "HEGrenade.Bounce");
  CBaseCSGrenadeProjectile::Precache(this);
}

//------------------------------------------------------------------------------
// Address: 0x102A3650
// Name: public: virtual void CHEGrenadeProjectile::BounceSound(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHEGrenadeProjectile::BounceSound(CHEGrenadeProjectile *this)
{
  CBaseEntity::EmitSound(this, soundname: "HEGrenade.Bounce", soundtime: 0.0, duration: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102A3670
// Name: public: virtual char const __near * CHEGrenadeProjectile::GetParticleSystemName(int,struct surfacedata_t __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CHEGrenadeProjectile::GetParticleSystemName(
        CHEGrenadeProjectile *this,
        __int16 pointContents,
        surfacedata_t *pdata)
{
  const char *result; // eax

  if ( (pointContents & 0x4030) != 0 )
    return "explosion_basic_water";
  if ( pdata == nullptr )
    return "explosion_basic";
  switch ( pdata->game.material )
  {
    case 0xBu:
    case 0x44u:
    case 0x4Au:
    case 0x4Eu:
    case 0x4Fu:
      result = "explosion_hegrenade_dirt";
      break;
    case 0x4Bu:
      result = "explosion_hegrenade_snow";
      break;
    default:
      return "explosion_basic";
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102A3720
// Name: public: virtual void CHEGrenadeProjectile::Detonate(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CHEGrenadeProjectile::Detonate(
        CHEGrenadeProjectile *this@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        int a4@<esi>)
{
  CBaseCombatCharacter *Thrower; // esi
  _DWORD *v6; // ebx
  IGameEvent *v7; // esi
  int v8; // eax

  CBaseGrenade::Detonate(this, a2: (int)this, a3: a4);
  Thrower = CBaseGrenade::GetThrower(this);
  if ( Thrower != nullptr && Thrower->IsPlayer(this: Thrower) )
  {
    v6 = __RTDynamicCast(
           inptr: Thrower,
           VfDelta: 0,
           SrcType: &CBaseEntity `RTTI Type Descriptor',
           TargetType: &CCSPlayer `RTTI Type Descriptor',
           isReference: 0);
    if ( v6 != nullptr )
    {
      v7 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "hegrenade_detonate", a3: 0, a4: 0);
      if ( v7 != nullptr )
      {
        v8 = ((int (__thiscall *)(IVEngineServer *, _DWORD, int))engine->GetPlayerUserId)(a1: engine, a2: v6[6], a3: a2);
        v7->SetInt(this: v7, a2: "userid", a3: v8);
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: a3);
        ((void (__thiscall *)(IGameEvent *, const char *, _DWORD))v7->SetFloat)(
          a1: v7,
          a2: "x",
          a3: LODWORD(this->m_vecAbsOrigin.x));
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: a3);
        ((void (__thiscall *)(IGameEvent *, const char *, _DWORD))v7->SetFloat)(
          a1: v7,
          a2: "y",
          a3: LODWORD(this->m_vecAbsOrigin.y));
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: a3);
        ((void (__thiscall *)(IGameEvent *, const char *))v7->SetFloat)(a1: v7, a2: "z");
        gameeventmanager->FireEvent(this: gameeventmanager, a2: v7, a3: false);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A3860
// Name: public: static class CHEGrenadeProjectile __near * CHEGrenadeProjectile::Create(class Vector const __near &,class QAngle const __near &,class Vector const __near &,class Vector const __near &,class CBaseCombatCharacter __near *,float)
// Source: json
//------------------------------------------------------------------------------
CHEGrenadeProjectile *__cdecl CHEGrenadeProjectile::Create(
        const Vector *position,
        const QAngle *angles,
        const Vector *velocity,
        const Vector *angVelocity,
        CBaseCombatCharacter *pOwner)
{
  CBaseEntity *v5; // esi
  CBaseEdict *v6; // ecx
  CBaseEntity_vtbl *v7; // edi
  int TeamNumber; // eax
  CCSWeaponInfo *WeaponInfo; // eax
  float m_iDamage; // xmm0_4
  CBaseEdict *v11; // ecx
  float x; // ebx
  CHEGrenadeProjectile *result; // eax
  CBaseEdict *v14; // ecx

  v5 = CBaseEntity::Create(szName: "hegrenade_projectile", vecOrigin: position, vecAngles: angles, pOwner);
  CBaseCSGrenadeProjectile::SetDetonateTimerLength(this: (CBaseCSGrenadeProjectile *)v5, timer: 1.5);
  CBaseEntity::SetAbsVelocity(this: v5, vecAbsVelocity: velocity);
  CBaseCSGrenadeProjectile::SetupInitialTransmittedGrenadeVelocity(this: (CBaseCSGrenadeProjectile *)v5, velocity);
  CBaseGrenade::SetThrower(this: (CBaseGrenade *)v5, pThrower: pOwner);
  v5->m_flGravity = 0.40000001;
  CBaseEntity::SetFriction(this: v5, flFriction: 0.2);
  if ( v5->m_flElasticity.m_Value != 0.44999999 )
  {
    if ( v5->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v5->m_Network + 76) |= 1u;
    }
    else
    {
      v6 = &v5->m_Network.m_pPev->CBaseEdict;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0x1B8u);
    }
    v5->m_flElasticity.m_Value = 0.44999999;
  }
  v7 = v5->__vftable;
  TeamNumber = CBaseEntity::GetTeamNumber(this: pOwner);
  v7->ChangeTeam(this: v5, a2: TeamNumber);
  CBaseEntity::ApplyLocalAngularVelocityImpulse(this: v5, angImpulse: angVelocity);
  CBaseEntity::ThinkSet(
    this: v5,
    func: (void (__thiscall *)(CBaseEntity *))CBaseCSGrenadeProjectile::DangerSoundThink,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this: v5, thinkTime: gpGlobals->curtime, szContext: nullptr);
  WeaponInfo = GetWeaponInfo(weaponID: WEAPON_HEGRENADE);
  LODWORD(v5[1].m_vecAbsVelocity.x) = WeaponInfo;
  if ( WeaponInfo == nullptr )
    return (CHEGrenadeProjectile *)v5;
  m_iDamage = (float)WeaponInfo->m_iDamage;
  if ( *(float *)&v5[1].m_nWaterTouch != m_iDamage )
  {
    if ( v5->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v5->m_Network + 76) |= 1u;
    }
    else
    {
      v11 = &v5->m_Network.m_pPev->CBaseEdict;
      if ( v11 != nullptr )
        CBaseEdict::StateChanged(this: v11, offset: 0x4A4u);
    }
    *(float *)&v5[1].m_nWaterTouch = m_iDamage;
  }
  x = v5[1].m_vecAbsVelocity.x;
  result = (CHEGrenadeProjectile *)v5;
  if ( *(float *)&v5[1].m_hOwnerEntity.m_Value.m_Index != *(float *)(LODWORD(x) + 2272) )
  {
    if ( v5->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&v5->m_Network + 76) |= 1u;
    }
    else
    {
      v14 = &v5->m_Network.m_pPev->CBaseEdict;
      if ( v14 != nullptr )
        CBaseEdict::StateChanged(this: v14, offset: 0x494u);
    }
    v5[1].m_hOwnerEntity.m_Value.m_Index = *(unsigned int *)(LODWORD(x) + 2272);
    return (CHEGrenadeProjectile *)v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104101C0
// Name: _dynamic_initializer_for__hegrenade_projectile__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__hegrenade_projectile__()
{
  CEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(CEntityFactoryDictionary *, CEntityFactory<CHEGrenadeProjectile> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &hegrenade_projectile,
           a3: "hegrenade_projectile");
}

//------------------------------------------------------------------------------
// Address: 0x104101E0
// Name: hegrenade_projectilePrecache::_dynamic_initializer_for__s_ResourcePrecacher__
// Source: json
//------------------------------------------------------------------------------
int hegrenade_projectilePrecache::_dynamic_initializer_for__s_ResourcePrecacher__()
{
  int result; // eax

  result = dword_106DA8A4;
  hegrenade_projectilePrecache::s_ResourcePrecacher.m_pNext = (IResourcePrecacher *)dword_106DA8A4;
  dword_106DA8A4 = (int)&hegrenade_projectilePrecache::s_ResourcePrecacher;
  return result;
}
