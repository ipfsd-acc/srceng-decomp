// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/basecsgrenade_projectile.cpp
// Functions: 21
// ============================================================

#include "game\shared\cstrike15\basecsgrenade_projectile.h"

//------------------------------------------------------------------------------
// Address: 0x101B3AC0
// Name: public: virtual class ClientClass __near * C_BaseCSGrenadeProjectile::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_BaseCSGrenadeProjectile::GetClientClass(C_BaseCSGrenadeProjectile *this)
{
  return &__g_C_BaseCSGrenadeProjectileClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x101B3B60
// Name: public: virtual int C_BaseCSGrenadeProjectile::DrawModel(int,struct RenderableInstance_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall C_BaseCSGrenadeProjectile::DrawModel(
        C_BaseCSGrenadeProjectile *this,
        int flags,
        const RenderableInstance_t *instance)
{
  C_BasePlayer *Thrower; // ebx
  C_BaseCombatCharacter *v5; // eax
  _DWORD **v6; // eax

  Thrower = (C_BasePlayer *)C_BaseGrenade::GetThrower(this: (C_BaseCSGrenadeProjectile *)((char *)this - 4));
  if ( Thrower != C_BasePlayer::GetLocalPlayer(nSlot: -1)
    && (float)(*(float *)(gpGlobals.m_Index + 12) - this->m_vInitialVelocity.m_Value.z) < 0.5
    && (v5 = C_BaseGrenade::GetThrower(this: (C_BaseCSGrenadeProjectile *)((char *)this - 4)),
        (v6 = (_DWORD **)__RTDynamicCast(
                           inptr: v5,
                           VfDelta: 0,
                           SrcType: &C_BaseCombatCharacter `RTTI Type Descriptor',
                           TargetType: &C_CSPlayer `RTTI Type Descriptor',
                           isReference: 0)) != nullptr)
    && (*(unsigned __int8 (__thiscall **)(_DWORD *))(*v6[1689] + 4))(a1: v6[1689]) != 0 )
  {
    return 0;
  }
  else
  {
    return C_BaseAnimating::DrawModel(this, flags, instance);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B3C00
// Name: public: virtual void C_BaseCSGrenadeProjectile::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCSGrenadeProjectile::Spawn(C_BaseCSGrenadeProjectile *this)
{
  this->m_flSpawnTime = *(float *)(gpGlobals.m_Index + 12);
  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x101B3CC0
// Name: public: virtual void C_BaseCSGrenadeProjectile::PostDataUpdate(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseCSGrenadeProjectile::PostDataUpdate(C_BaseCSGrenadeProjectile *this, DataUpdateType_t type)
{
  CDiscontinuousInterpolatedVar<Vector> *OriginInterpolator; // edi
  const Vector *LocalOrigin; // eax
  float v5; // [esp+0h] [ebp-24h]
  Vector vCurOrigin; // [esp+18h] [ebp-Ch] BYREF
  float changeTime; // [esp+2Ch] [ebp+8h]

  C_BaseAnimating::PostDataUpdate(this, updateType: type);
  if ( type == DATA_UPDATE_CREATED )
  {
    OriginInterpolator = C_BaseEntity::GetOriginInterpolator(this: (C_BaseCSGrenadeProjectile *)((char *)this - 8));
    *(_DWORD *)&OriginInterpolator->m_VarHistory.m_firstElement = 0;
    changeTime = C_BaseEntity::GetLastChangeTime(this: (C_BaseCSGrenadeProjectile *)((char *)this - 8), flags: 2);
    LocalOrigin = C_BaseEntity::GetLocalOrigin(this: (C_BaseCSGrenadeProjectile *)((char *)this - 8));
    vCurOrigin.x = LocalOrigin->x - *(float *)&this->m_hOriginalThrower.m_Index;
    vCurOrigin.y = LocalOrigin->y - *((float *)&this->m_hOriginalThrower + 1);
    v5 = changeTime - 1.0;
    vCurOrigin.z = LocalOrigin->z - this->m_vInitialVelocity.m_Value.x;
    CInterpolatedVarArrayBase<Vector,0>::AddToHead(
      this: (CInterpolatedVarArrayBase<QAngle,0> *)OriginInterpolator,
      changeTime: v5,
      values: (const QAngle *)&vCurOrigin,
      bFlushNewer: false);
    vCurOrigin = *C_BaseEntity::GetLocalOrigin(this: (C_BaseCSGrenadeProjectile *)((char *)this - 8));
    CInterpolatedVarArrayBase<Vector,0>::AddToHead(
      this: (CInterpolatedVarArrayBase<QAngle,0> *)OriginInterpolator,
      changeTime,
      values: (const QAngle *)&vCurOrigin,
      bFlushNewer: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10421C80
// Name: DT_BaseCSGrenadeProjectile::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseCSGrenadeProjectile::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_BaseCSGrenadeProjectile::g_RecvTable);
  return atexit(func: DT_BaseCSGrenadeProjectile::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10421CA0
// Name: DT_BaseCSGrenadeProjectile::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseCSGrenadeProjectile::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_BaseCSGrenadeProjectile::ignored>();
  DT_BaseCSGrenadeProjectile::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10435110
// Name: DT_BaseCSGrenadeProjectile::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseCSGrenadeProjectile::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_BaseCSGrenadeProjectile::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x101B3C50
// Name: _C_BaseCSGrenadeProjectile_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_BaseCSGrenadeProjectile_CreateObject(int entnum, int serialNum)
{
  C_BaseGrenade *v2; // eax
  _DWORD *v3; // esi

  v2 = (C_BaseGrenade *)C_BaseEntity::operator new(stAllocateBlock: 0xCF0u);
  v3 = &v2->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseGrenade::C_BaseGrenade(this: v2);
  *v3 = &C_BaseCSGrenadeProjectile::`vftable'{for `IClientUnknown'};
  v3[1] = &C_BaseCSGrenadeProjectile::`vftable'{for `IClientRenderable'};
  v3[2] = &C_BaseCSGrenadeProjectile::`vftable'{for `IClientNetworkable'};
  v3[3] = &C_BaseCSGrenadeProjectile::`vftable'{for `IClientThinkable'};
  v3[4] = &C_BaseCSGrenadeProjectile::`vftable';
  (*(void (__thiscall **)(_DWORD *, int, int))(*v3 + 172))(a1: v3, a2: entnum, a3: serialNum);
  return (IClientNetworkable *)(v3 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x10421CB0
// Name: _dynamic_initializer_for__cl_buy_favorite_quiet__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_buy_favorite_quiet__()
{
  ConVar::ConVar(
    this: &cl_buy_favorite_quiet,
    pName: "cl_buy_favorite_quiet",
    pDefaultValue: "0",
    flags: 1073741952,
    pHelpString: "Skips the prompt when saving a buy favorite in the buy menu");
  return atexit(func: dynamic_atexit_destructor_for__cl_buy_favorite_quiet__);
}

//------------------------------------------------------------------------------
// Address: 0x10421CE0
// Name: _dynamic_initializer_for__cl_buy_favorite_nowarn__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_buy_favorite_nowarn__()
{
  ConVar::ConVar(
    this: &cl_buy_favorite_nowarn,
    pName: "cl_buy_favorite_nowarn",
    pDefaultValue: "0",
    flags: 1073741952,
    pHelpString: "Skips the error prompt when saving an invalid buy favorite");
  return atexit(func: dynamic_atexit_destructor_for__cl_buy_favorite_nowarn__);
}

//------------------------------------------------------------------------------
// Address: 0x10421D10
// Name: _dynamic_initializer_for__cl_buy_favorite_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_buy_favorite_command__()
{
  ConCommand::ConCommand(
    this: &cl_buy_favorite_command,
    pName: "cl_buy_favorite",
    callback: (void (__cdecl *)())cl_buy_favorite,
    pHelpString: "Purchase a favorite weapon/equipment loadout",
    flags: 0x40000000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cl_buy_favorite_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10421D40
// Name: _dynamic_initializer_for__cl_buy_favorite_set_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_buy_favorite_set_command__()
{
  ConCommand::ConCommand(
    this: &cl_buy_favorite_set_command,
    pName: "cl_buy_favorite_set",
    callback: (void (__cdecl *)())cl_buy_favorite_set,
    pHelpString: "Saves the current loadout as a favorite",
    flags: 0x40000000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cl_buy_favorite_set_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10421D70
// Name: _dynamic_initializer_for__cl_buy_favorite_reset__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_buy_favorite_reset__()
{
  ConCommand::ConCommand(
    this: &cl_buy_favorite_reset,
    pName: "cl_buy_favorite_reset",
    callback: __CmdFunc_BuyPresetsReset,
    pHelpString: "Reset favorite loadouts to the default",
    flags: 0x40000000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__cl_buy_favorite_reset__);
}

//------------------------------------------------------------------------------
// Address: 0x10421DA0
// Name: _dynamic_initializer_for__g_Hostages__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Hostages__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_Hostages__);
}

//------------------------------------------------------------------------------
// Address: 0x10421DB0
// Name: _dynamic_initializer_for__g_HostageRagdolls__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_HostageRagdolls__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_HostageRagdolls__);
}

//------------------------------------------------------------------------------
// Address: 0x10421DC0
// Name: _dynamic_initializer_for____g_C_CHostageClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_CHostageClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_CHostageClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_CHostageClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10435120
// Name: _dynamic_atexit_destructor_for__cl_buy_favorite_quiet__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_buy_favorite_quiet__()
{
  ConVar::~ConVar(this: &cl_buy_favorite_quiet);
}

//------------------------------------------------------------------------------
// Address: 0x10435130
// Name: _dynamic_atexit_destructor_for__cl_buy_favorite_nowarn__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_buy_favorite_nowarn__()
{
  ConVar::~ConVar(this: &cl_buy_favorite_nowarn);
}

//------------------------------------------------------------------------------
// Address: 0x10435140
// Name: _dynamic_atexit_destructor_for__cl_buy_favorite_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_buy_favorite_command__()
{
  ConCommand::~ConCommand(this: &cl_buy_favorite_command);
}

//------------------------------------------------------------------------------
// Address: 0x10435150
// Name: _dynamic_atexit_destructor_for__cl_buy_favorite_set_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_buy_favorite_set_command__()
{
  ConCommand::~ConCommand(this: &cl_buy_favorite_set_command);
}

//------------------------------------------------------------------------------
// Address: 0x10435160
// Name: _dynamic_atexit_destructor_for__cl_buy_favorite_reset__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_buy_favorite_reset__()
{
  ConCommand::~ConCommand(this: &cl_buy_favorite_reset);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10268CB0
// Name: public: virtual struct datamap_t __near * CBaseCSGrenadeProjectile::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CBaseCSGrenadeProjectile::GetDataDescMap(CBaseCSGrenadeProjectile *this)
{
  return &CBaseCSGrenadeProjectile::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10268CC0
// Name: public: virtual class ServerClass __near * CBaseCSGrenadeProjectile::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CBaseCSGrenadeProjectile::GetServerClass(CBaseCSGrenadeProjectile *this)
{
  return &g_CBaseCSGrenadeProjectile_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x10268CD0
// Name: public: virtual void CBaseCSGrenadeProjectile::PostConstructor(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCSGrenadeProjectile::PostConstructor(CBaseCSGrenadeProjectile *this, const char *className)
{
  CBaseEntity::PostConstructor(this, szClassname: className);
  CBotManager::AddGrenade(this: TheBots, grenade: this);
}

//------------------------------------------------------------------------------
// Address: 0x10268CF0
// Name: public: virtual CBaseCSGrenadeProjectile::~CBaseCSGrenadeProjectile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCSGrenadeProjectile::~CBaseCSGrenadeProjectile(CBaseCSGrenadeProjectile *this)
{
  this->CBaseGrenade::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CBaseCSGrenadeProjectile_vtbl *)&CBaseCSGrenadeProjectile::`vftable'{for `CBaseAnimating'};
  this->CBaseGrenade::CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&CBaseCSGrenadeProjectile::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  CBotManager::RemoveGrenade(this: TheBots, grenade: this);
  CBaseGrenade::~CBaseGrenade(this);
}

//------------------------------------------------------------------------------
// Address: 0x10268D60
// Name: public: virtual void CBaseCSGrenadeProjectile::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCSGrenadeProjectile::Precache(CBaseCSGrenadeProjectile *this)
{
  CBaseGrenade::Precache(this);
  PrecacheEffect(pEffectName: "gunshotsplash");
}

//------------------------------------------------------------------------------
// Address: 0x10268D80
// Name: protected: void CBaseCSGrenadeProjectile::SetDetonateTimerLength(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCSGrenadeProjectile::SetDetonateTimerLength(CBaseCSGrenadeProjectile *this, float timer)
{
  this->m_flDetonateTime = gpGlobals->curtime + timer;
}

//------------------------------------------------------------------------------
// Address: 0x10268DA0
// Name: public: virtual void CBaseCSGrenadeProjectile::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCSGrenadeProjectile::Spawn(CBaseCSGrenadeProjectile *this)
{
  Vector mins; // [esp+8h] [ebp-18h] BYREF
  Vector maxs; // [esp+14h] [ebp-Ch] BYREF

  this->Precache(this);
  vgui::ListViewPanel::Paint((vgui::ListViewPanel *)this);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: 0x10u);
  CBaseEntity::SetMoveType(this, val: MOVETYPE_FLYGRAVITY, moveCollide: MOVECOLLIDE_FLY_CUSTOM);
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BBOX);
  maxs.x = 2.0;
  maxs.y = 2.0;
  maxs.z = 2.0;
  mins.x = -2.0;
  mins.y = -2.0;
  mins.z = -2.0;
  CBaseEntity::SetSize(this, &mins, &maxs);
}

//------------------------------------------------------------------------------
// Address: 0x10268EF0
// Name: public: void CBaseCSGrenadeProjectile::DangerSoundThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseCSGrenadeProjectile::DangerSoundThink(CBaseCSGrenadeProjectile *this@<ecx>, int a2@<ebp>)
{
  unsigned int v3; // eax
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // [esp+20h] [ebp-3Ch]
  Vector v9; // [esp+38h] [ebp-24h] BYREF
  float v10; // [esp+44h] [ebp-18h]
  float v11; // [esp+48h] [ebp-14h]
  float v12; // [esp+4Ch] [ebp-10h]
  _DWORD v13[3]; // [esp+50h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+5Ch] [ebp+0h]

  v13[0] = a2;
  v13[1] = retaddr;
  if ( CBaseEntity::IsInWorld(this, a2: (int)v13) )
  {
    if ( gpGlobals->curtime <= this->m_flDetonateTime )
    {
      if ( (this->m_iEFlags & 0x1000) != 0 )
        CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)v13);
      v8 = fsqrt(
             (float)((float)(this->m_vecAbsVelocity.x * this->m_vecAbsVelocity.x)
                   + (float)(this->m_vecAbsVelocity.y * this->m_vecAbsVelocity.y))
           + (float)(this->m_vecAbsVelocity.z * this->m_vecAbsVelocity.z));
      if ( (this->m_iEFlags & 0x1000) != 0 )
        CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)v13);
      v3 = (unsigned int)this->m_iEFlags >> 11;
      v4 = this->m_vecAbsVelocity.x * 0.5;
      v5 = this->m_vecAbsVelocity.y * 0.5;
      v6 = this->m_vecAbsVelocity.z * 0.5;
      v10 = v4;
      v11 = v5;
      v12 = v6;
      if ( (v3 & 1) != 0 )
      {
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)v13);
        v6 = v12;
        v5 = v11;
        v4 = v10;
      }
      v7 = this->m_vecAbsOrigin.x + v4;
      v9.y = this->m_vecAbsOrigin.y + v5;
      v9.z = this->m_vecAbsOrigin.z + v6;
      v9.x = v7;
      CSoundEnt::InsertSound(
        iType: 8,
        vecOrigin: &v9,
        iVolume: (int)v8,
        flDuration: 0.2,
        pOwner: nullptr,
        soundChannelIndex: 0,
        pSoundTarget: nullptr);
      CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.2, szContext: nullptr);
      if ( this->m_nWaterLevel.m_Value != 0 )
      {
        if ( (this->m_iEFlags & 0x1000) != 0 )
          CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)v13);
        v9.x = this->m_vecAbsVelocity.x * 0.5;
        v9.y = this->m_vecAbsVelocity.y * 0.5;
        v9.z = this->m_vecAbsVelocity.z * 0.5;
        CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &v9);
      }
    }
    else
    {
      this->Detonate(this);
    }
  }
  else
  {
    CNullEntity::Spawn(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10269100
// Name: private: virtual void CBaseCSGrenadeProjectile::ResolveFlyCollisionCustom(class CGameTrace __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCSGrenadeProjectile::ResolveFlyCollisionCustom(
        CBaseCSGrenadeProjectile *this,
        CGameTrace *trace,
        Vector *vecVelocity)
{
  CBaseEntity *m_pEnt; // eax
  CBaseEntity *v6; // ecx
  CBaseEntity *v7; // ecx
  CBaseEntity *v8; // ecx
  float z; // ecx
  float v10; // xmm0_4
  float y; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  float x; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // edx
  CGlobalVars *v21; // eax
  float v22; // xmm5_4
  float v23; // xmm6_4
  float v24; // xmm0_4
  float v25; // xmm1_4
  float v26; // xmm5_4
  float v27; // xmm6_4
  float v28; // xmm4_4
  float v29; // xmm1_4
  float v30; // xmm3_4
  CBaseCombatCharacter *Thrower; // eax
  CBaseCombatCharacter *v32; // edi
  const edict_t **v33; // ebx
  IGameEvent *v34; // edi
  int v35; // eax
  CTakeDamageInfo info; // [esp+38h] [ebp-84h] BYREF
  Vector vecDelta; // [esp+94h] [ebp-28h] BYREF
  Vector vecAbsVelocity; // [esp+A0h] [ebp-1Ch] BYREF
  float flSurfaceElasticity; // [esp+ACh] [ebp-10h]
  Vector vecBaseDir; // [esp+B0h] [ebp-Ch] BYREF
  int savedregs; // [esp+BCh] [ebp+0h] BYREF
  float flSpeedSqr; // [esp+C4h] [ebp+8h]
  char flSpeedSqr_3; // [esp+C7h] [ebp+Bh]
  CBaseEntity *vecVelocitya; // [esp+C8h] [ebp+Ch]

  m_pEnt = trace->m_pEnt;
  flSurfaceElasticity = 1.0;
  if ( m_pEnt != nullptr && m_pEnt->IsPlayer(this: m_pEnt) )
    flSurfaceElasticity = 0.30000001;
  v6 = trace->m_pEnt;
  flSpeedSqr_3 = 0;
  if ( v6 != nullptr
    && (v6->m_iClassname.pszValue == "func_breakable"
     || CBaseEntity::ClassMatchesComplex(this: v6, pszClassOrWildcard: "func_breakable") != 0) )
  {
    flSpeedSqr_3 = 1;
  }
  v7 = trace->m_pEnt;
  if ( v7 != nullptr
    && (v7->m_iClassname.pszValue == "func_breakable_surf"
     || CBaseEntity::ClassMatchesComplex(this: v7, pszClassOrWildcard: "func_breakable_surf") != 0) )
  {
    flSpeedSqr_3 = 1;
  }
  v8 = trace->m_pEnt;
  if ( (v8 == nullptr
     || v8->m_iClassname.pszValue != "prop_physics_multiplayer"
     && CBaseEntity::ClassMatchesComplex(this: v8, pszClassOrWildcard: "prop_physics_multiplayer") == 0)
    && flSpeedSqr_3 == 0 )
  {
    goto LABEL_22;
  }
  CTakeDamageInfo::CTakeDamageInfo(
    this: &info,
    pInflictor: this,
    pAttacker: this,
    flDamage: 10.0,
    bitsDamageType: 128,
    iKillType: 0,
    iObjectsPenetrated: 0);
  if ( (this->m_iEFlags & 0x1000) != 0 )
    CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
  CBaseEntity::DispatchTraceAttack(this: trace->m_pEnt, &info, vecDir: &this->m_vecAbsVelocity, ptr: trace);
  ApplyMultiDamage();
  if ( trace->m_pEnt->m_iHealth.m_Value <= 0 )
  {
    if ( (this->m_iEFlags & 0x1000) != 0 )
      CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
    z = this->m_vecAbsVelocity.z;
    *(_QWORD *)&vecBaseDir.x = *(_QWORD *)&this->m_vecAbsVelocity.x;
    vecBaseDir.x = vecBaseDir.x * 0.40000001;
    vecBaseDir.y = vecBaseDir.y * 0.40000001;
    vecBaseDir.z = z * 0.40000001;
    CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vecBaseDir);
  }
  else
  {
LABEL_22:
    v10 = this->m_flElasticity.m_Value * flSurfaceElasticity;
    if ( v10 >= 0.0 )
    {
      if ( v10 <= 0.89999998 )
        flSpeedSqr = this->m_flElasticity.m_Value * flSurfaceElasticity;
      else
        flSpeedSqr = 0.89999998;
    }
    else
    {
      flSpeedSqr = 0.0;
    }
    if ( (this->m_iEFlags & 0x1000) != 0 )
      CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
    LODWORD(flSurfaceElasticity) = &trace->plane;
    CBaseEntity::PhysicsClipVelocity(
      this,
      in: &this->m_vecAbsVelocity,
      normal: &trace->plane.normal,
      out: &vecAbsVelocity,
      overbounce: 2.0);
    y = vecAbsVelocity.y;
    v13 = vecAbsVelocity.z;
    vecAbsVelocity.x = vecAbsVelocity.x * flSpeedSqr;
    vecVelocity->x = vecAbsVelocity.x + this->m_vecBaseVelocity.m_Value.x;
    v14 = y * flSpeedSqr;
    vecVelocity->y = this->m_vecBaseVelocity.m_Value.y + v14;
    v15 = v13 * flSpeedSqr;
    v16 = this->m_vecBaseVelocity.m_Value.z + v15;
    vecAbsVelocity.y = v14;
    x = vecVelocity->x;
    vecAbsVelocity.z = v15;
    v18 = vecVelocity->y;
    vecVelocity->z = v16;
    v19 = (float)((float)(x * x) + (float)(v18 * v18)) + (float)(v16 * v16);
    if ( trace->plane.normal.z <= 0.69999999 )
    {
      if ( v19 >= 900.0 )
      {
        CBaseEntity::SetAbsVelocity(this, &vecAbsVelocity);
      }
      else
      {
        CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
        CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
      }
    }
    else
    {
      vecVelocitya = trace->m_pEnt;
      CBaseEntity::SetAbsVelocity(this, &vecAbsVelocity);
      if ( v19 >= 900.0 )
      {
        v20 = this->m_vecBaseVelocity.m_Value.z;
        vecDelta.x = this->m_vecBaseVelocity.m_Value.x - vecAbsVelocity.x;
        vecDelta.y = this->m_vecBaseVelocity.m_Value.y - vecAbsVelocity.y;
        vecDelta.z = this->m_vecBaseVelocity.m_Value.z - vecAbsVelocity.z;
        *(_QWORD *)&vecBaseDir.x = *(_QWORD *)&this->m_vecBaseVelocity.m_Value.x;
        vecBaseDir.z = v20;
        VectorNormalize(vec: &vecBaseDir);
        v21 = gpGlobals;
        v22 = vecAbsVelocity.x;
        v23 = vecAbsVelocity.y;
        v24 = (float)((float)(vecBaseDir.y * vecDelta.y) + (float)(vecDelta.x * vecBaseDir.x))
            + (float)(vecBaseDir.z * vecDelta.z);
        v25 = (float)(1.0 - trace->fraction) * gpGlobals->frametime;
        vecVelocity->z = vecAbsVelocity.z * v25;
        v26 = v22 * v25;
        v27 = v23 * v25;
        vecVelocity->x = v26;
        vecVelocity->y = v27;
        v28 = (float)(1.0 - trace->fraction) * v21->frametime;
        v29 = (float)((float)(this->m_vecBaseVelocity.m_Value.z * v24) * v28) + vecVelocity->z;
        v30 = (float)((float)(this->m_vecBaseVelocity.m_Value.y * v24) * v28) + v27;
        vecVelocity->x = (float)((float)(v24 * this->m_vecBaseVelocity.m_Value.x) * v28) + v26;
        vecVelocity->y = v30;
        vecVelocity->z = v29;
        CBaseEntity::PhysicsPushEntity(this, push: vecVelocity, pTrace: trace);
      }
      else
      {
        if ( CBaseEntity::IsStandable(this: vecVelocitya) )
          CBaseEntity::SetGroundEntity(this, ground: vecVelocitya);
        CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
        CBaseEntity::SetLocalAngularVelocity(this, vecAngVelocity: &vec3_angle);
        VectorAngles(forward: (const Vector *)LODWORD(flSurfaceElasticity), angles: (QAngle *)&vecDelta);
        vecDelta.y = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, int))random->RandomFloat)(
                       a1: random,
                       a2: 0,
                       a3: 1135869952);
        CBaseEntity::SetAbsAngles(this, absAngles: (const QAngle *)&vecDelta);
      }
    }
    this->BounceSound(this);
    Thrower = CBaseGrenade::GetThrower(this);
    v32 = Thrower;
    if ( Thrower != nullptr && Thrower->IsPlayer(this: Thrower) )
    {
      v33 = (const edict_t **)__RTDynamicCast(
                                inptr: v32,
                                VfDelta: 0,
                                SrcType: &CBaseEntity `RTTI Type Descriptor',
                                TargetType: &CCSPlayer `RTTI Type Descriptor',
                                isReference: 0);
      if ( v33 != nullptr )
      {
        v34 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "grenade_bounce", a3: 0, a4: 0);
        if ( v34 != nullptr )
        {
          v35 = engine->GetPlayerUserId(this: engine, a2: v33[6]);
          v34->SetInt(this: v34, a2: "userid", a3: v35);
          if ( (this->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
          ((void (__thiscall *)(IGameEvent *, const char *, _DWORD))v34->SetFloat)(
            a1: v34,
            a2: "x",
            a3: LODWORD(this->m_vecAbsOrigin.x));
          if ( (this->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
          ((void (__thiscall *)(IGameEvent *, const char *, _DWORD))v34->SetFloat)(
            a1: v34,
            a2: "y",
            a3: LODWORD(this->m_vecAbsOrigin.y));
          if ( (this->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
          ((void (__thiscall *)(IGameEvent *, const char *, _DWORD))v34->SetFloat)(
            a1: v34,
            a2: "z",
            a3: LODWORD(this->m_vecAbsOrigin.z));
          gameeventmanager->FireEvent(this: gameeventmanager, a2: v34, a3: false);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102696B0
// Name: public: virtual void CBaseCSGrenadeProjectile::Splash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCSGrenadeProjectile::Splash(CBaseCSGrenadeProjectile *this)
{
  float z; // ecx
  float x; // xmm3_4
  float y; // xmm0_4
  float v5; // xmm2_4
  CGameTrace tr; // [esp+10h] [ebp-D8h] BYREF
  CEffectData data; // [esp+64h] [ebp-84h] BYREF
  __int64 v8; // [esp+C8h] [ebp-20h]
  Vector vecAbsEnd; // [esp+D0h] [ebp-18h] BYREF
  Vector centerPoint; // [esp+DCh] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+E8h] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  z = this->m_vecAbsOrigin.z;
  *(_QWORD *)&centerPoint.x = *(_QWORD *)&this->m_vecAbsOrigin.x;
  v8 = *(_QWORD *)&centerPoint.x;
  *(_QWORD *)&vecAbsEnd.x = *(_QWORD *)&centerPoint.x;
  centerPoint.z = z;
  vecAbsEnd.z = z + 512.0;
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)this,
    vecAbsStart: &centerPoint,
    &vecAbsEnd,
    mask: 0x4030u,
    ignore: nullptr,
    collisionGroup: 0,
    ptr: &tr);
  if ( tr.startsolid )
  {
    if ( tr.fractionleftsolid != 0.0 )
    {
      v5 = (float)(tr.fractionleftsolid * 512.0) + centerPoint.z;
      x = (float)(tr.fractionleftsolid * 0.0) + centerPoint.x;
      y = (float)(tr.fractionleftsolid * 0.0) + centerPoint.y;
      goto LABEL_9;
    }
  }
  else
  {
    *(_QWORD *)&vecAbsEnd.x = v8;
    vecAbsEnd.z = centerPoint.z - 512.0;
    UTIL_TraceLine(
      a1: &savedregs,
      a2: (int)this,
      vecAbsStart: &centerPoint,
      &vecAbsEnd,
      mask: 0x4030u,
      ignore: nullptr,
      collisionGroup: 0,
      ptr: &tr);
    if ( tr.fraction < 1.0 )
    {
      x = tr.endpos.x;
      y = tr.endpos.y;
      v5 = tr.endpos.z;
      goto LABEL_9;
    }
  }
  v5 = centerPoint.z;
  y = centerPoint.y;
  x = centerPoint.x;
LABEL_9:
  data.m_vOrigin.y = y;
  memset((void *)&data.m_vStart, 0, 20);
  memset((void *)&data.m_vAngles, 0, 20);
  data.m_flScale = 1.0;
  memset(&data.m_flMagnitude, 0, 14);
  memset(&data.m_nMaterial, 0, 17);
  data.m_vOrigin.x = x;
  data.m_vOrigin.z = v5;
  data.m_vNormal.z = 1.0;
  data.m_flScale = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                     a1: random,
                     a2: 1065353216,
                     a3: 0x40000000);
  if ( (CBaseEntity::GetWaterType(this) & 0x10) != 0 )
    data.m_fFlags |= 1u;
  DispatchEffect(pName: "gunshotsplash", &data);
}

//------------------------------------------------------------------------------
// Address: 0x102698C0
// Name: public: void CBaseCSGrenadeProjectile::SetupInitialTransmittedGrenadeVelocity(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseCSGrenadeProjectile::SetupInitialTransmittedGrenadeVelocity(
        CBaseCSGrenadeProjectile *this,
        const Vector *velocity)
{
  CNetworkVectorBase<Vector,CBaseCSGrenadeProjectile::NetworkVar_m_vInitialVelocity> *p_m_vInitialVelocity; // esi
  edict_t *m_pPev; // ecx

  p_m_vInitialVelocity = &this->m_vInitialVelocity;
  if ( velocity->x != this->m_vInitialVelocity.m_Value.x
    || velocity->y != this->m_vInitialVelocity.m_Value.y
    || velocity->z != this->m_vInitialVelocity.m_Value.z )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x4B4u);
    }
    p_m_vInitialVelocity->m_Value = *velocity;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040D1B0
// Name: CBaseCSGrenadeProjectile_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBaseCSGrenadeProjectile_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBaseCSGrenadeProjectile>(__formal: nullptr);
  CBaseCSGrenadeProjectile_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040D1E0
// Name: DT_BaseCSGrenadeProjectile::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseCSGrenadeProjectile::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_BaseCSGrenadeProjectile::g_SendTable);
  return atexit(func: DT_BaseCSGrenadeProjectile::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040D200
// Name: DT_BaseCSGrenadeProjectile::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseCSGrenadeProjectile::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_BaseCSGrenadeProjectile::ignored>();
  DT_BaseCSGrenadeProjectile::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041F370
// Name: DT_BaseCSGrenadeProjectile::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseCSGrenadeProjectile::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_BaseCSGrenadeProjectile::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10269940
// Name: struct datamap_t __near * DataMapInit<class CBaseCSGrenadeProjectile>(class CBaseCSGrenadeProjectile __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBaseCSGrenadeProjectile>()
{
  if ( (_S2_240 & 1) == 0 )
  {
    _S2_240 |= 1u;
    nameHolder_471.m_pszBase = "CBaseCSGrenadeProjectile";
    nameHolder_471.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_471.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_471.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_471.m_Names.m_Size = 0;
    nameHolder_471.m_Names.m_pElements = nullptr;
    nameHolder_471.m_nLenBase = 24;
    atexit(func: DataMapInit_CBaseCSGrenadeProjectile__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBaseCSGrenadeProjectile::m_DataMap.baseMap = &CBaseGrenade::m_DataMap;
  if ( (_S2_240 & 2) == 0 )
  {
    _S2_240 |= 2u;
    dataDesc_497[1].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_471,
                                  pszIdentifier: "DangerSoundThink");
    dataDesc_497[1].fieldOffset = 0;
    *(_DWORD *)&dataDesc_497[1].fieldSize = 2097153;
    dataDesc_497[1].externalName = nullptr;
    dataDesc_497[1].pSaveRestoreOps = nullptr;
    dataDesc_497[1].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseCSGrenadeProjectile::DangerSoundThink;
    *(_QWORD *)&dataDesc_497[1].td = 0;
    *(_QWORD *)&dataDesc_497[1].override_field = 0;
    *(_QWORD *)&dataDesc_497[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_497[1].flatOffset[1] = 0;
  }
  CBaseCSGrenadeProjectile::m_DataMap.dataNumFields = 1;
  CBaseCSGrenadeProjectile::m_DataMap.dataDesc = &dataDesc_497[1];
  return &CBaseCSGrenadeProjectile::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1040D1C0
// Name: _dynamic_initializer_for__g_CBaseCSGrenadeProjectile_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CBaseCSGrenadeProjectile_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CBaseCSGrenadeProjectile_ClassReg,
           pNetworkName: "CBaseCSGrenadeProjectile",
           pTable: &DT_BaseCSGrenadeProjectile::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x1040D210
// Name: _dynamic_initializer_for__g_BlackMarket_WeaponsBought__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_BlackMarket_WeaponsBought__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_BlackMarket_WeaponsBought__);
}

//------------------------------------------------------------------------------
// Address: 0x1040D220
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___8
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___8()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_8,
           fn: _CreateCServerGameTagsIServerGameTags_interface_8,
           pName: "ServerGameTags001");
}

//------------------------------------------------------------------------------
// Address: 0x1041F380
// Name: _ServerClassInit_DT_BaseCSGrenadeProjectile::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_BaseCSGrenadeProjectile::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_144;
  for ( i = 2; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x1041F3A0
// Name: _DataMapInit_CBaseCSGrenadeProjectile__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBaseCSGrenadeProjectile__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_471);
}

//------------------------------------------------------------------------------
// Address: 0x1041F3B0
// Name: _dynamic_atexit_destructor_for__g_BlackMarket_WeaponsBought__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_BlackMarket_WeaponsBought__()
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_BlackMarket_WeaponsBought);
}

//------------------------------------------------------------------------------
// Address: 0x1041F3C0
// Name: _dynamic_atexit_destructor_for__mp_logdetail__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mp_logdetail__()
{
  ConVar::~ConVar(this: &mp_logdetail);
}

//------------------------------------------------------------------------------
// Address: 0x1041F3D0
// Name: _dynamic_atexit_destructor_for__g_CSEventLog__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CSEventLog__()
{
  CEventLog::~CEventLog(this: &g_CSEventLog);
}

//------------------------------------------------------------------------------
// Address: 0x1041F3E0
// Name: _dynamic_atexit_destructor_for__sv_timebetweenducks__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_timebetweenducks__()
{
  ConVar::~ConVar(this: &sv_timebetweenducks);
}

//------------------------------------------------------------------------------
// Address: 0x1041F3F0
// Name: _dynamic_atexit_destructor_for__sv_enablebunnyhopping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_enablebunnyhopping__()
{
  ConVar::~ConVar(this: &sv_enablebunnyhopping);
}

//------------------------------------------------------------------------------
// Address: 0x1041F400
// Name: _dynamic_atexit_destructor_for__g_GameMovement__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_GameMovement__()
{
  CGameMovement::~CGameMovement(this: &g_GameMovement);
}

} // namespace server
