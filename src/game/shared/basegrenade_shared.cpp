// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/basegrenade_shared.cpp
// Functions: 23
// ============================================================

#include "game\shared\basegrenade_shared.h"

//------------------------------------------------------------------------------
// Address: 0x10017660
// Name: public: virtual class ClientClass __near * C_BaseGrenade::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_BaseGrenade::GetClientClass(C_BaseGrenade *this)
{
  return &__g_C_BaseGrenadeClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10017790
// Name: public: virtual struct datamap_t __near * C_BaseGrenade::GetPredDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall C_BaseGrenade::GetPredDescMap(C_BaseGrenade *this)
{
  return &C_BaseGrenade::m_PredMap;
}

//------------------------------------------------------------------------------
// Address: 0x100177A0
// Name: public: virtual void C_BaseGrenade::Event_Killed(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseGrenade::Event_Killed(C_BaseGrenade *this, const CTakeDamageInfo *info)
{
  this->Detonate(this);
}

//------------------------------------------------------------------------------
// Address: 0x100177B0
// Name: public: virtual void C_BaseGrenade::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseGrenade::Precache(C_BaseGrenade *this)
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  C_BaseEntity::PrecacheScriptSound(soundname: "BaseGrenade.Explode");
}

//------------------------------------------------------------------------------
// Address: 0x100177D0
// Name: public: virtual C_BaseGrenade::~C_BaseGrenade(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseGrenade::~C_BaseGrenade(C_BaseGrenade *this)
{
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BaseGrenade_vtbl *)&C_BaseGrenade::`vftable'{for `IClientUnknown'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_BaseGrenade::`vftable'{for `IClientRenderable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_BaseGrenade::`vftable'{for `IClientNetworkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_BaseGrenade::`vftable'{for `IClientThinkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_BaseGrenade::`vftable';
  C_BaseAnimating::~C_BaseAnimating(this);
}

//------------------------------------------------------------------------------
// Address: 0x10017800
// Name: public: virtual float C_BaseGrenade::GetShakeAmplitude(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BaseGrenade::GetShakeAmplitude(C_BaseGrenade *this)
{
  return 25.0;
}

//------------------------------------------------------------------------------
// Address: 0x10017810
// Name: public: virtual float C_BaseGrenade::GetShakeRadius(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BaseGrenade::GetShakeRadius(C_BaseGrenade *this)
{
  return 750.0;
}

//------------------------------------------------------------------------------
// Address: 0x10017880
// Name: public: virtual float C_BaseGrenade::GetDamage(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BaseGrenade::GetDamage(C_BaseGrenade *this)
{
  return this->m_flDamage.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x10017890
// Name: public: virtual float C_BaseGrenade::GetDamageRadius(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall C_BaseGrenade::GetDamageRadius(C_BaseGrenade *this)
{
  return this->m_DmgRadius.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x100178A0
// Name: public: class C_BaseEntity __near * C_BaseEntity::GetOwnerEntity(void)const
// Source: json
//------------------------------------------------------------------------------
C_BaseEntity *__thiscall C_BaseEntity::GetOwnerEntity(C_BaseEntity *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_hOwnerEntity.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (C_BaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x100178D0
// Name: public: virtual void C_BaseGrenade::Detonate(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall C_BaseGrenade::Detonate(C_BaseGrenade *this@<ecx>, int a2@<esi>)
{
  int v3; // eax
  float v4; // xmm1_4
  float v5; // xmm2_4
  const Vector *v6; // eax
  const Vector *(__thiscall *GetAbsOrigin)(IClientEntity *); // edx
  const Vector *v8; // eax
  vgui::PropertyPage *v9; // ecx
  __int128 v10; // [esp+8h] [ebp-8Ch]
  float v11; // [esp+Ch] [ebp-88h]
  float v12; // [esp+18h] [ebp-7Ch]
  CGameTrace tr; // [esp+24h] [ebp-70h] BYREF
  __int128 v15; // [esp+78h] [ebp-1Ch] OVERLAPPED BYREF
  Vector vecAbsEnd; // [esp+88h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+94h] [ebp+0h] BYREF

  *(_QWORD *)&v15 = 0;
  *(_QWORD *)&v10 = 0;
  *((_QWORD *)&v15 + 1) = 0xFFFFFFFF00000000uLL;
  *((_QWORD *)&v10 + 1) = 0xFFFFFFFF00000000uLL;
  C_BaseEntity::ThinkSet(this, a2: (int)&v15, func: v10, thinkTime: 0.0, szContext: nullptr);
  v3 = ((int (__thiscall *)(C_BaseGrenade *, int))this->GetAbsOrigin)(a1: this, a2);
  v4 = *(float *)v3;
  v5 = *(float *)(v3 + 4);
  *((float *)&v15 + 3) = *(float *)(v3 + 8) + 8.0;
  *(_QWORD *)((char *)&v15 + 4) = __PAIR64__(LODWORD(v5), LODWORD(v4));
  vecAbsEnd.x = v4;
  vecAbsEnd.y = v5;
  vecAbsEnd.z = *((float *)&v15 + 3) - 32.0;
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)this,
    vecAbsStart: (const Vector *)((char *)&v15 + 4),
    &vecAbsEnd,
    mask: 0x600400Bu,
    ignore: this,
    collisionGroup: 0,
    ptr: &tr);
  if ( tr.startsolid )
  {
    v6 = this->GetAbsOrigin(this);
    *(_QWORD *)((char *)&v15 + 4) = *(_QWORD *)&v6->x;
    GetAbsOrigin = this->GetAbsOrigin;
    *((float *)&v15 + 3) = v6->z - 32.0;
    v8 = GetAbsOrigin(this);
    UTIL_TraceLine(
      a1: &savedregs,
      a2: (int)this,
      vecAbsStart: v8,
      vecAbsEnd: (const Vector *)((char *)&v15 + 4),
      mask: 0x600400Bu,
      ignore: this,
      collisionGroup: 0,
      ptr: &tr);
  }
  this->Explode(this, a2: &tr, a3: 64);
  if ( ((double (__thiscall *)(C_BaseGrenade *))this->GetShakeAmplitude)(a1: this) != 0.0 )
  {
    v12 = ((double (__thiscall *)(C_BaseGrenade *, _DWORD, _DWORD))this->GetShakeRadius)(a1: this, a2: 0, a3: 0);
    v11 = ((double (__thiscall *)(C_BaseGrenade *, int, int, _DWORD))this->GetShakeAmplitude)(
            a1: this,
            a2: 1125515264,
            a3: 1065353216,
            a4: LODWORD(v12));
    ((void (__thiscall *)(C_BaseGrenade *, _DWORD))this->GetAbsOrigin)(a1: this, a2: LODWORD(v11));
    C_BaseAnimating::ShutdownBoneSetupThreadPool(this: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017A60
// Name: public: class C_BaseCombatCharacter __near * C_BaseGrenade::GetThrower(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseCombatCharacter *__thiscall C_BaseGrenade::GetThrower(C_BaseGrenade *this)
{
  unsigned int m_Index; // eax
  CBaseEntityList *v3; // edi
  IHandleEntity *m_pEntity; // ecx
  C_BaseCombatCharacter *result; // eax
  unsigned int v6; // edx
  int v7; // ecx
  CEntInfo *v8; // esi
  unsigned int v9; // edx
  int v10; // ecx
  IHandleEntity *v11; // eax

  m_Index = this->m_hThrower.m_Value.m_Index;
  v3 = g_pEntityList;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
  {
    result = (C_BaseCombatCharacter *)((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[49].SetRefEHandle)(a1: m_pEntity);
    if ( result != nullptr )
      return result;
    v3 = g_pEntityList;
  }
  else
  {
    result = nullptr;
  }
  v6 = this->m_hOwnerEntity.m_Index;
  if ( v6 != -1 )
  {
    v7 = (unsigned __int16)v6;
    v8 = &v3->m_EntPtrArray[(unsigned __int16)v6];
    v9 = HIWORD(v6);
    if ( v8->m_SerialNumber == v9 && v8->m_pEntity != nullptr )
    {
      v10 = v7;
      if ( v3->m_EntPtrArray[v10].m_SerialNumber == v9 && (v11 = v3->m_EntPtrArray[v10].m_pEntity) != nullptr )
        return ((C_BaseCombatCharacter *(__thiscall *)(IHandleEntity *))v11->__vftable[49].SetRefEHandle)(a1: v11);
      else
        return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017B00
// Name: public: virtual void C_BaseGrenade::SetDamage(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseGrenade::SetDamage(C_BaseGrenade *this, float flDamage)
{
  if ( this->m_flDamage.m_Value != flDamage )
    this->m_flDamage.m_Value = flDamage;
}

//------------------------------------------------------------------------------
// Address: 0x10017B30
// Name: public: virtual void C_BaseGrenade::SetDamageRadius(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BaseGrenade::SetDamageRadius(C_BaseGrenade *this, float flDamageRadius)
{
  if ( this->m_DmgRadius.m_Value != flDamageRadius )
    this->m_DmgRadius.m_Value = flDamageRadius;
}

//------------------------------------------------------------------------------
// Address: 0x10017B60
// Name: public: C_BaseGrenade::C_BaseGrenade(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseGrenade *__thiscall C_BaseGrenade::C_BaseGrenade(C_BaseGrenade *this)
{
  unsigned int m_Index; // ecx

  C_BaseAnimating::C_BaseAnimating(this);
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BaseGrenade_vtbl *)&C_BaseGrenade::`vftable'{for `IClientUnknown'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_BaseGrenade::`vftable'{for `IClientRenderable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_BaseGrenade::`vftable'{for `IClientNetworkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_BaseGrenade::`vftable'{for `IClientThinkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_BaseGrenade::`vftable';
  this->m_hThrower.m_Value.m_Index = -1;
  this->m_hOriginalThrower.m_Index = -1;
  m_Index = this->m_hThrower.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    this->m_hThrower.m_Value.m_Index = -1;
  }
  this->m_hOriginalThrower.m_Index = -1;
  if ( this->m_bIsLive.m_Value )
    this->m_bIsLive.m_Value = false;
  if ( this->m_DmgRadius.m_Value != 100.0 )
    this->m_DmgRadius.m_Value = 100.0;
  this->m_flDetonateTime = 0.0;
  this->m_bHasWarnedAI = false;
  if ( !this->m_bSimulatedEveryTick.m_Value )
  {
    this->m_bSimulatedEveryTick.m_Value = true;
    C_BaseEntity::Interp_UpdateInterpolationAmounts(this, map: &this->m_VarMap);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10017C90
// Name: CC_BaseGrenadeFactory
// Source: json
//------------------------------------------------------------------------------
C_BaseGrenade *__cdecl CC_BaseGrenadeFactory()
{
  C_BaseGrenade *v0; // eax

  v0 = (C_BaseGrenade *)C_BaseEntity::operator new(stAllocateBlock: 0xCE0u);
  if ( v0 != nullptr )
    return C_BaseGrenade::C_BaseGrenade(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1040FE50
// Name: DT_BaseGrenade::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseGrenade::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_BaseGrenade::g_RecvTable);
  return atexit(func: DT_BaseGrenade::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x1040FE70
// Name: DT_BaseGrenade::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseGrenade::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_BaseGrenade::ignored>();
  DT_BaseGrenade::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FEB0
// Name: C_BaseGrenade_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__
// Source: json
//------------------------------------------------------------------------------
void C_BaseGrenade_PredDataDescInit::_dynamic_initializer_for__g_PredMapHolder__()
{
  C_BaseGrenade::m_PredMap.dataNumFields = 6;
  C_BaseGrenade::m_PredMap.dataDesc = (typedescription_t *)&unk_10598064;
}

//------------------------------------------------------------------------------
// Address: 0x1042F8A0
// Name: DT_BaseGrenade::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseGrenade::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_BaseGrenade::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10017C40
// Name: _C_BaseGrenade_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_BaseGrenade_CreateObject(int entnum, int serialNum)
{
  C_BaseGrenade *v2; // eax
  C_BaseGrenade *v3; // eax
  C_BaseGrenade *v4; // esi

  v2 = (C_BaseGrenade *)C_BaseEntity::operator new(stAllocateBlock: 0xCE0u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_BaseGrenade::C_BaseGrenade(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x1040FE80
// Name: _dynamic_initializer_for__g_CgrenadeFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CgrenadeFoo__()
{
  CClassMap *ClassMap; // eax
  int result; // eax

  ClassMap = GetClassMap();
  result = ((int (__thiscall *)(CClassMap *, const char *, const char *, int, C_BaseGrenade *(__cdecl *)()))ClassMap->Add)(
             a1: ClassMap,
             a2: "grenade",
             a3: "C_BaseGrenade",
             a4: 3296,
             a5: CC_BaseGrenadeFactory);
  __g_C_BaseGrenadeClientClass.m_pMapClassname = "grenade";
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FED0
// Name: _dynamic_initializer_for____g_C_BaseParticleEntityClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_BaseParticleEntityClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_BaseParticleEntityClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_BaseParticleEntityClientClass;
  return result;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x100D5740
// Name: public: virtual struct datamap_t __near * CBaseGrenade::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CBaseGrenade::GetDataDescMap(CBaseGrenade *this)
{
  return &CBaseGrenade::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100D5750
// Name: public: virtual class ServerClass __near * CBaseGrenade::GetServerClass(void)
// Source: json
//------------------------------------------------------------------------------
ServerClass *__thiscall CBaseGrenade::GetServerClass(CBaseGrenade *this)
{
  return &g_CBaseGrenade_ClassReg;
}

//------------------------------------------------------------------------------
// Address: 0x100D5760
// Name: public: virtual void CBaseGrenade::Event_Killed(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGrenade::Event_Killed(CBaseGrenade *this, const CTakeDamageInfo *info)
{
  this->Detonate(this);
}

//------------------------------------------------------------------------------
// Address: 0x100D5770
// Name: public: virtual void CBaseGrenade::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGrenade::Precache(CBaseGrenade *this)
{
  CBaseAnimating::Precache(this);
  CBaseEntity::PrecacheScriptSound(soundname: "BaseGrenade.Explode");
}

//------------------------------------------------------------------------------
// Address: 0x100D5790
// Name: public: virtual CBaseGrenade::~CBaseGrenade(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGrenade::~CBaseGrenade(CBaseGrenade *this)
{
  this->CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CBaseGrenade_vtbl *)&CBaseGrenade::`vftable'{for `CBaseAnimating'};
  this->CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&CBaseGrenade::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  CBaseAnimating::~CBaseAnimating(this);
}

//------------------------------------------------------------------------------
// Address: 0x100D57B0
// Name: public: virtual class QAngle CDefaultPlayerPickupVPhysics::PreferredCarryAngles(void)
// Source: json
//------------------------------------------------------------------------------
QAngle *__thiscall CDefaultPlayerPickupVPhysics::PreferredCarryAngles(
        CDefaultPlayerPickupVPhysics *this,
        QAngle *result)
{
  *result = vec3_angle;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D57E0
// Name: public: virtual class Vector CDefaultPlayerPickupVPhysics::PhysGunLaunchVelocity(class Vector const __near &,float)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CDefaultPlayerPickupVPhysics::PhysGunLaunchVelocity(
        CDefaultPlayerPickupVPhysics *this,
        Vector *result,
        const Vector *vecForward,
        float flMass)
{
  Pickup_DefaultPhysGunLaunchVelocity(result, vecForward, flMass);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D5810
// Name: public: virtual float CBaseGrenade::GetShakeAmplitude(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseGrenade::GetShakeAmplitude(CBaseGrenade *this)
{
  return 25.0;
}

//------------------------------------------------------------------------------
// Address: 0x100D5820
// Name: public: virtual float CBaseGrenade::GetShakeRadius(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseGrenade::GetShakeRadius(CBaseGrenade *this)
{
  return 750.0;
}

//------------------------------------------------------------------------------
// Address: 0x100D5830
// Name: public: virtual int CBaseGrenade::ObjectCaps(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseGrenade::ObjectCaps(CBaseGrenade *this)
{
  return CBaseEntity::ObjectCaps(this) | 0x21;
}

//------------------------------------------------------------------------------
// Address: 0x100D5880
// Name: public: virtual class Vector CDefaultPlayerPickupVPhysics::PhysGunLaunchAngularImpulse(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
Vector *__thiscall CDefaultPlayerPickupVPhysics::PhysGunLaunchAngularImpulse(
        CDefaultPlayerPickupVPhysics *this,
        Vector *result)
{
  IUniformRandomStream *v2; // ecx
  IUniformRandomStream *v3; // ecx

  result->x = _RandomFloat((IUniformRandomStream *)this, a2: -600.0, a3: 600.0);
  result->y = _RandomFloat(this: v2, a2: -600.0, a3: 600.0);
  result->z = _RandomFloat(this: v3, a2: -600.0, a3: 600.0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D5900
// Name: public: virtual float CBaseGrenade::GetDamage(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseGrenade::GetDamage(CBaseGrenade *this)
{
  return this->m_flDamage.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x100D5910
// Name: public: virtual float CBaseGrenade::GetDamageRadius(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseGrenade::GetDamageRadius(CBaseGrenade *this)
{
  return this->m_DmgRadius.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x100D5920
// Name: public: void CBaseGrenade::Smoke(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGrenade::Smoke(CBaseGrenade *this)
{
  __int64 v2; // xmm0_8
  float v3; // xmm0_4
  CPVSFilter filter; // [esp+30h] [ebp-44h] BYREF
  Vector mins; // [esp+50h] [ebp-24h] BYREF
  Vector maxs; // [esp+5Ch] [ebp-18h] BYREF
  Vector vecAbsOrigin; // [esp+68h] [ebp-Ch] BYREF
  int savedregs; // [esp+74h] [ebp+0h] BYREF

  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  v2 = *(_QWORD *)&this->m_vecAbsOrigin.x;
  vecAbsOrigin.z = this->m_vecAbsOrigin.z;
  *(_QWORD *)&vecAbsOrigin.x = v2;
  if ( (enginetrace->GetPointContents(this: enginetrace, a2: &vecAbsOrigin, a3: 16432, a4: nullptr) & 0x4030) != 0 )
  {
    maxs.x = vecAbsOrigin.x + 64.0;
    maxs.y = vecAbsOrigin.y + 64.0;
    maxs.z = vecAbsOrigin.z + 64.0;
    mins.x = vecAbsOrigin.x - 64.0;
    mins.y = vecAbsOrigin.y - 64.0;
    mins.z = vecAbsOrigin.z - 64.0;
    UTIL_Bubbles(&mins, &maxs, count: 100);
  }
  else
  {
    CRecipientFilter::CRecipientFilter(this: &filter);
    filter.__vftable = (CPVSFilter_vtbl *)&CPVSFilter::`vftable';
    CRecipientFilter::AddRecipientsByPVS(this: &filter, origin: &vecAbsOrigin);
    v3 = this->m_DmgRadius.m_Value * 0.03;
    ((void (__stdcall *)(CPVSFilter *, _DWORD, Vector *, int, _DWORD, int))te->Smoke)(
      a1: &filter,
      a2: 0,
      a3: &vecAbsOrigin,
      a4: g_sModelIndexSmoke,
      a5: LODWORD(v3),
      a6: 24);
    CRecipientFilter::~CRecipientFilter(this: &filter);
  }
  CBaseEntity::ThinkSet(this, func: CBaseEntity::SUB_Remove, thinkTime: 0.0, szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100D5A80
// Name: public: virtual void CBaseGrenade::Use(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGrenade::Use(
        CBaseGrenade *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        USE_TYPE useType,
        float value)
{
  if ( useType == USE_TOGGLE && pActivator != nullptr && pActivator->IsPlayer(this: pActivator) )
    ((void (__thiscall *)(CBaseEntity *, CBaseGrenade *, int))pActivator->__vftable[2].NetworkStateChanged_m_nNextThinkTick)(
      a1: pActivator,
      a2: this,
      a3: 1);
  else
    CBaseEntity::Use(this, pActivator, pCaller, useType, value);
}

//------------------------------------------------------------------------------
// Address: 0x100D5AE0
// Name: public: void CBaseGrenade::DetonateUse(class CBaseEntity __near *,class CBaseEntity __near *,enum USE_TYPE,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGrenade::DetonateUse(
        CBaseGrenade *this,
        CBaseEntity *pActivator,
        CBaseEntity *pCaller,
        CBaseEntity *useType,
        float value)
{
  CBaseEntity::ThinkSet(this, func:  __thiscall CItem::`vcall'{920,{flat}}, thinkTime: 0.0, szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100D5B20
// Name: public: void CBaseGrenade::PreDetonate(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseGrenade::PreDetonate(CBaseGrenade *this@<ecx>, int a2@<ebp>)
{
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2);
  CSoundEnt::InsertSound(
    iType: 8,
    vecOrigin: &this->m_vecAbsOrigin,
    iVolume: 400,
    flDuration: 1.5,
    pOwner: this,
    soundChannelIndex: 0,
    pSoundTarget: nullptr);
  CBaseEntity::ThinkSet(this, func:  __thiscall CItem::`vcall'{920,{flat}}, thinkTime: 0.0, szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 1.5, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100D5D60
// Name: public: virtual void CBaseGrenade::Detonate(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseGrenade::Detonate(CBaseGrenade *this@<ecx>, int a2@<edi>, int a3@<esi>)
{
  float x; // xmm1_4
  float y; // xmm2_4
  int m_iEFlags; // edx
  float (__thiscall *GetShakeRadius)(CBaseGrenade *); // eax
  double v8; // st7
  float (__thiscall *GetShakeAmplitude)(CBaseGrenade *); // eax
  CGameTrace tr; // [esp+2Ch] [ebp-6Ch] BYREF
  Vector vecSpot; // [esp+80h] [ebp-18h] BYREF
  Vector vecAbsEnd; // [esp+8Ch] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+98h] [ebp+0h] BYREF

  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  x = this->m_vecAbsOrigin.x;
  y = this->m_vecAbsOrigin.y;
  vecSpot.z = this->m_vecAbsOrigin.z + 8.0;
  vecSpot.x = x;
  vecSpot.y = y;
  vecAbsEnd.x = x;
  vecAbsEnd.y = y;
  vecAbsEnd.z = vecSpot.z - 32.0;
  UTIL_TraceLine(
    a1: &savedregs,
    a2: (int)this,
    vecAbsStart: &vecSpot,
    &vecAbsEnd,
    mask: 0x600400Bu,
    ignore: this,
    collisionGroup: 0,
    ptr: &tr);
  if ( tr.startsolid )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    m_iEFlags = this->m_iEFlags;
    vecSpot.x = this->m_vecAbsOrigin.x;
    vecSpot.y = this->m_vecAbsOrigin.y;
    vecSpot.z = this->m_vecAbsOrigin.z - 32.0;
    if ( (m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    UTIL_TraceLine(
      a1: &savedregs,
      a2: (int)this,
      vecAbsStart: &this->m_vecAbsOrigin,
      vecAbsEnd: &vecSpot,
      mask: 0x600400Bu,
      ignore: this,
      collisionGroup: 0,
      ptr: &tr);
  }
  ((void (__thiscall *)(CBaseGrenade *, CGameTrace *, int, int, int))this->Explode)(
    a1: this,
    a2: &tr,
    a3: 64,
    a4: a2,
    a5: a3);
  if ( ((double (__thiscall *)(CBaseGrenade *))this->GetShakeAmplitude)(a1: this) != 0.0 )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
    GetShakeRadius = this->GetShakeRadius;
    vecAbsEnd.x = 0.0;
    vecSpot.z = 0.0;
    vecSpot.y = 0.0;
    v8 = ((double (__thiscall *)(CBaseGrenade *))GetShakeRadius)(a1: this);
    GetShakeAmplitude = this->GetShakeAmplitude;
    vecSpot.x = v8;
    tr.hitbox = 1065353216;
    tr.m_pEnt = (CBaseEntity *)1125515264;
    *(float *)&tr.physicsbone = GetShakeAmplitude(this);
    UTIL_ScreenShake(
      center: &this->m_vecAbsOrigin,
      amplitude: *(float *)&tr.physicsbone,
      frequency: *(float *)&tr.m_pEnt,
      duration: *(float *)&tr.hitbox,
      radius: vecSpot.x,
      eCommand: SLODWORD(vecSpot.y),
      bAirShake: SLOBYTE(vecSpot.z),
      ignore: (CUtlVector<CBasePlayer *,CUtlMemory<CBasePlayer *,int> > *)LODWORD(vecAbsEnd.x));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D5F00
// Name: public: void CBaseGrenade::ExplodeTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGrenade::ExplodeTouch(CBaseGrenade *this, CBaseEntity *pOther)
{
  float z; // ecx
  float x; // xmm3_4
  float y; // xmm4_4
  float v6; // xmm5_4
  unsigned int v7; // eax
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm6_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  CGameTrace tr; // [esp+4h] [ebp-78h] BYREF
  Vector vecSpot; // [esp+58h] [ebp-24h] BYREF
  Vector vecAbsEnd; // [esp+64h] [ebp-18h] BYREF
  Vector velDir; // [esp+70h] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+7Ch] [ebp+0h] BYREF

  if ( pOther->m_Collision.m_nSolidType.m_Value != 0 && (pOther->m_Collision.m_usSolidFlags.m_Value & 4) == 0 )
  {
    if ( (this->m_iEFlags & 0x1000) != 0 )
      CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
    z = this->m_vecAbsVelocity.z;
    *(_QWORD *)&velDir.x = *(_QWORD *)&this->m_vecAbsVelocity.x;
    velDir.z = z;
    VectorNormalize(vec: &velDir);
    x = velDir.x;
    y = velDir.y;
    v6 = velDir.z;
    v7 = (unsigned int)this->m_iEFlags >> 11;
    v8 = velDir.x * 32.0;
    v9 = velDir.y * 32.0;
    v10 = velDir.z * 32.0;
    vecAbsEnd.x = velDir.x * 32.0;
    vecAbsEnd.y = velDir.y * 32.0;
    vecAbsEnd.z = velDir.z * 32.0;
    if ( (v7 & 1) != 0 )
    {
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
      v6 = velDir.z;
      y = velDir.y;
      x = velDir.x;
      v10 = vecAbsEnd.z;
      v9 = vecAbsEnd.y;
      v8 = vecAbsEnd.x;
    }
    v11 = this->m_vecAbsOrigin.x - v8;
    v12 = this->m_vecAbsOrigin.y - v9;
    v13 = this->m_vecAbsOrigin.z - v10;
    vecSpot.x = v11;
    vecSpot.y = v12;
    vecSpot.z = v13;
    vecAbsEnd.x = (float)(x * 64.0) + v11;
    vecAbsEnd.y = (float)(y * 64.0) + v12;
    vecAbsEnd.z = (float)(v6 * 64.0) + v13;
    UTIL_TraceLine(
      a1: &savedregs,
      a2: (int)this,
      vecAbsStart: &vecSpot,
      &vecAbsEnd,
      mask: 0x400Bu,
      ignore: this,
      collisionGroup: 0,
      ptr: &tr);
    this->Explode(this, a2: &tr, a3: 64);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D6060
// Name: public: void CBaseGrenade::DangerSoundThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseGrenade::DangerSoundThink(CBaseGrenade *this@<ecx>, int a2@<ebp>)
{
  unsigned int v3; // edx
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
      pOwner: this,
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
    CNullEntity::Spawn(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D6250
// Name: public: class CBaseCombatCharacter __near * CBaseGrenade::GetThrower(void)
// Source: json
//------------------------------------------------------------------------------
CBaseCombatCharacter *__thiscall CBaseGrenade::GetThrower(CBaseGrenade *this)
{
  unsigned int m_Index; // eax
  CBaseEntityList *v3; // edi
  IHandleEntity *m_pEntity; // ecx
  CBaseCombatCharacter *result; // eax
  unsigned int v6; // edx
  int v7; // ecx
  CEntInfo *v8; // esi
  unsigned int v9; // edx
  int v10; // ecx
  IHandleEntity *v11; // eax

  m_Index = this->m_hThrower.m_Value.m_Index;
  v3 = g_pEntityList;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
  {
    result = (CBaseCombatCharacter *)((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[25].dtr_IHandleEntity)(a1: m_pEntity);
    if ( result != nullptr )
      return result;
    v3 = g_pEntityList;
  }
  else
  {
    result = nullptr;
  }
  v6 = this->m_hOwnerEntity.m_Value.m_Index;
  if ( v6 != -1 )
  {
    v7 = (unsigned __int16)v6;
    v8 = &v3->m_EntPtrArray[(unsigned __int16)v6];
    v9 = HIWORD(v6);
    if ( v8->m_SerialNumber == v9 && v8->m_pEntity != nullptr )
    {
      v10 = v7;
      if ( v3->m_EntPtrArray[v10].m_SerialNumber == v9 && (v11 = v3->m_EntPtrArray[v10].m_pEntity) != nullptr )
        return ((CBaseCombatCharacter *(__thiscall *)(IHandleEntity *))v11->__vftable[25].dtr_IHandleEntity)(a1: v11);
      else
        return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100D62F0
// Name: public: class CBaseEntity const __near * CNetworkHandleBase<class CBaseEntity,class CBaseGrenade::NetworkVar_m_hThrower>::Set(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
const CBaseEntity *__thiscall CNetworkHandleBase<CBaseEntity,CBaseGrenade::NetworkVar_m_hThrower>::Set(
        CNetworkHandleBase<CBaseEntity,CBaseGrenade::NetworkVar_m_hThrower> *this,
        const CBaseEntity *val)
{
  unsigned int m_Index; // eax
  const CBaseEntity *m_pEntity; // ecx
  CNetworkHandleBase<CBaseEntity,CBaseGrenade::NetworkVar_m_hThrower> *v5; // eax
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
    v5 = this - 299;
    if ( *((_BYTE *)this - 1112) != 0 )
    {
      LOBYTE(v5[22].m_Value.m_Index) |= 1u;
    }
    else
    {
      v6 = (CBaseEdict *)v5[6].m_Value.m_Index;
      if ( v6 != nullptr )
        CBaseEdict::StateChanged(this: v6, offset: 0x4ACu);
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
// Address: 0x100D6380
// Name: public: void CBaseGrenade::SlideTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGrenade::SlideTouch(CBaseGrenade *this, CBaseCombatCharacter *pOther)
{
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  if ( pOther != CBaseGrenade::GetThrower(this) )
  {
    if ( (this->m_fFlags.m_Value & 1) != 0 )
    {
      if ( (this->m_iEFlags & 0x1000) != 0 )
        CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
      if ( this->m_vecAbsVelocity.x == 0.0 && (this->m_iEFlags & 0x1000) != 0 )
        CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
    }
    else
    {
      this->BounceSound(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D63F0
// Name: public: void CBaseGrenade::TumbleThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGrenade::TumbleThink(CBaseGrenade *this)
{
  float v2; // xmm0_4
  unsigned int v3; // ecx
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  edict_t *m_pPev; // ecx
  Vector vecOrigin; // [esp+14h] [ebp-18h] BYREF
  float v9; // [esp+20h] [ebp-Ch]
  float v10; // [esp+24h] [ebp-8h]
  float v11; // [esp+28h] [ebp-4h]
  int savedregs; // [esp+2Ch] [ebp+0h] BYREF

  if ( CBaseEntity::IsInWorld(this, a2: (int)&savedregs) )
  {
    this->StudioFrameAdvance(this);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.1, szContext: nullptr);
    if ( gpGlobals->curtime > (float)(this->m_flDetonateTime - 1.0) )
    {
      if ( (this->m_iEFlags & 0x1000) != 0 )
        CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
      v2 = this->m_flDetonateTime - gpGlobals->curtime;
      v3 = (unsigned int)this->m_iEFlags >> 11;
      v4 = this->m_vecAbsVelocity.x * v2;
      v5 = this->m_vecAbsVelocity.y * v2;
      v6 = this->m_vecAbsVelocity.z * v2;
      v9 = v4;
      v10 = v5;
      v11 = v6;
      if ( (v3 & 1) != 0 )
      {
        CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
        v6 = v11;
        v5 = v10;
        v4 = v9;
      }
      vecOrigin.x = this->m_vecAbsOrigin.x + v4;
      vecOrigin.y = this->m_vecAbsOrigin.y + v5;
      vecOrigin.z = this->m_vecAbsOrigin.z + v6;
      CSoundEnt::InsertSound(
        iType: 8,
        &vecOrigin,
        iVolume: 400,
        flDuration: 0.1,
        pOwner: this,
        soundChannelIndex: 0,
        pSoundTarget: nullptr);
    }
    if ( gpGlobals->curtime >= this->m_flDetonateTime )
      CBaseEntity::ThinkSet(this, func:  __thiscall CItem::`vcall'{920,{flat}}, thinkTime: 0.0, szContext: nullptr);
    if ( this->m_nWaterLevel.m_Value != 0 )
    {
      if ( (this->m_iEFlags & 0x1000) != 0 )
        CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)&savedregs);
      vecOrigin.x = this->m_vecAbsVelocity.x * 0.5;
      vecOrigin.y = this->m_vecAbsVelocity.y * 0.5;
      vecOrigin.z = this->m_vecAbsVelocity.z * 0.5;
      CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vecOrigin);
      if ( this->m_flPlaybackRate.m_Value != 0.2 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x37Cu);
        }
        this->m_flPlaybackRate.m_Value = 0.2;
      }
    }
  }
  else
  {
    CNullEntity::Spawn(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D6620
// Name: public: virtual void CBaseGrenade::SetDamage(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGrenade::SetDamage(CBaseGrenade *this, float flDamage)
{
  CNetworkVarBase<float,CBaseGrenade::NetworkVar_m_flDamage> *p_m_flDamage; // esi
  edict_t *m_pPev; // ecx

  p_m_flDamage = &this->m_flDamage;
  if ( this->m_flDamage.m_Value != flDamage )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_flDamage->m_Value = flDamage;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x4A4u);
      p_m_flDamage->m_Value = flDamage;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D6680
// Name: public: virtual void CBaseGrenade::SetDamageRadius(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGrenade::SetDamageRadius(CBaseGrenade *this, float flDamageRadius)
{
  CNetworkVarBase<float,CBaseGrenade::NetworkVar_m_DmgRadius> *p_m_DmgRadius; // esi
  edict_t *m_pPev; // ecx

  p_m_DmgRadius = &this->m_DmgRadius;
  if ( this->m_DmgRadius.m_Value != flDamageRadius )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      p_m_DmgRadius->m_Value = flDamageRadius;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x494u);
      p_m_DmgRadius->m_Value = flDamageRadius;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D66E0
// Name: public: virtual void CBaseGrenade::Explode(class CGameTrace __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGrenade::Explode(CBaseGrenade *this, CGameTrace *pTrace, int bitsDamageType)
{
  float v4; // xmm2_4
  float v5; // xmm3_4
  float z; // xmm0_4
  __int64 v7; // xmm0_8
  int v8; // edi
  surfacedata_t *v9; // eax
  const char *v10; // ebx
  int surfaceProps; // edx
  surfacedata_t *v12; // ebx
  int v13; // eax
  float m_Value; // xmm0_4
  float v15; // xmm0_4
  unsigned int m_Index; // ecx
  int v17; // eax
  CEntInfo *v18; // edx
  unsigned int v19; // ecx
  int v20; // eax
  bool v21; // zf
  CBaseEntity **v22; // eax
  CBaseEntity *v23; // edi
  QAngle *p_m_vecAbsOrigin; // eax
  unsigned int v25; // eax
  CBaseEntity *m_pEntity; // edi
  const Vector *v27; // eax
  float flDamage; // [esp+48h] [ebp-120h]
  int flDuration; // [esp+4Ch] [ebp-11Ch]
  Vector *soundtime; // [esp+54h] [ebp-114h]
  int material_low; // [esp+58h] [ebp-110h]
  CTakeDamageInfo info; // [esp+68h] [ebp-100h] BYREF
  CGameTrace tr; // [esp+C4h] [ebp-A4h] BYREF
  CPASFilter filter; // [esp+118h] [ebp-50h] BYREF
  QAngle vecAngles; // [esp+138h] [ebp-30h] BYREF
  Vector vecNormal; // [esp+144h] [ebp-24h] BYREF
  Vector vecAbsOrigin; // [esp+150h] [ebp-18h] BYREF
  Vector vecParticleOrigin; // [esp+15Ch] [ebp-Ch] BYREF
  IHandleEntity savedregs; // [esp+168h] [ebp+0h] BYREF

  this->m_ModelName.pszValue = nullptr;
  CBaseEntity::DispatchUpdateTransmitState(this);
  CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 4);
  if ( this->m_takedamage.m_Value != 0 )
  {
    this->NetworkStateChanged_m_takedamage(this, a2: &this->m_takedamage);
    this->m_takedamage.m_Value = 0;
  }
  if ( pTrace->fraction != 1.0 )
  {
    v4 = pTrace->plane.normal.z * 0.60000002;
    v5 = pTrace->endpos.x + (float)(pTrace->plane.normal.x * 0.60000002);
    vecParticleOrigin.y = pTrace->endpos.y + (float)(pTrace->plane.normal.y * 0.60000002);
    z = pTrace->endpos.z;
    vecParticleOrigin.x = v5;
    vecParticleOrigin.z = z + v4;
    CBaseEntity::SetAbsOrigin(this, absOrigin: &vecParticleOrigin);
  }
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  v7 = *(_QWORD *)&this->m_vecAbsOrigin.x;
  vecAbsOrigin.z = this->m_vecAbsOrigin.z;
  *(_QWORD *)&vecAbsOrigin.x = v7;
  v8 = enginetrace->GetPointContents(this: enginetrace, a2: &vecAbsOrigin, a3: -1, a4: nullptr);
  v9 = (surfacedata_t *)((int (__stdcall *)(_DWORD))physprops->GetSurfaceData)(a1: pTrace->surface.surfaceProps);
  v10 = this->GetParticleSystemName(this, a2: v8, a3: v9);
  if ( v10 != nullptr )
  {
    vecParticleOrigin = vecAbsOrigin;
    if ( (v8 & 0x4030) != 0 )
    {
      vecNormal.x = vecAbsOrigin.x;
      vecNormal.y = vecAbsOrigin.y;
      vecNormal.z = vecAbsOrigin.z + 512.0;
      UTIL_TraceLine(
        a1: &savedregs,
        a2: (int)this,
        vecAbsStart: &vecParticleOrigin,
        vecAbsEnd: &vecNormal,
        mask: 0x4030u,
        ignore: nullptr,
        collisionGroup: 0,
        ptr: &tr);
      if ( tr.startsolid )
      {
        if ( tr.fractionleftsolid != 0.0 )
        {
          vecParticleOrigin.x = (float)(tr.fractionleftsolid * 0.0) + vecParticleOrigin.x;
          vecParticleOrigin.y = (float)(tr.fractionleftsolid * 0.0) + vecParticleOrigin.y;
          vecParticleOrigin.z = (float)(tr.fractionleftsolid * 512.0) + vecParticleOrigin.z;
        }
      }
      else
      {
        vecNormal.x = vecParticleOrigin.x;
        vecNormal.y = vecParticleOrigin.y;
        vecNormal.z = vecParticleOrigin.z - 512.0;
        UTIL_TraceLine(
          a1: &savedregs,
          a2: (int)this,
          vecAbsStart: &vecParticleOrigin,
          vecAbsEnd: &vecNormal,
          mask: 0x4030u,
          ignore: nullptr,
          collisionGroup: 0,
          ptr: &tr);
        if ( tr.fraction < 1.0 )
          vecParticleOrigin = tr.endpos;
      }
    }
    DispatchParticleEffect(
      pszParticleName: v10,
      vecOrigin: vecParticleOrigin,
      vecAngles,
      pEntity: nullptr,
      nSplitScreenPlayerSlot: -1,
      filter: nullptr);
  }
  else
  {
    if ( pTrace->fraction == 1.0 )
    {
      CRecipientFilter::CRecipientFilter(this: &filter);
      filter.__vftable = (CPASFilter_vtbl *)&CPASFilter::`vftable';
      CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: &vecAbsOrigin);
      v13 = g_sModelIndexFireball;
      if ( (v8 & 0x4030) != 0 )
        v13 = g_sModelIndexWExplosion;
      material_low = 67;
      soundtime = nullptr;
    }
    else
    {
      surfaceProps = pTrace->surface.surfaceProps;
      vecNormal = pTrace->plane.normal;
      v12 = physprops->GetSurfaceData(this: physprops, a2: surfaceProps);
      CRecipientFilter::CRecipientFilter(this: &filter);
      filter.__vftable = (CPASFilter_vtbl *)&CPASFilter::`vftable';
      CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: &vecAbsOrigin);
      v13 = g_sModelIndexFireball;
      if ( (v8 & 0x4030) != 0 )
        v13 = g_sModelIndexWExplosion;
      material_low = LOBYTE(v12->game.material);
      soundtime = &vecNormal;
    }
    m_Value = this->m_DmgRadius.m_Value;
    flDuration = (int)m_Value;
    v15 = m_Value * 0.03;
    ((void (__stdcall *)(CPASFilter *, int, Vector *, int, _DWORD, int, _DWORD, int, int, Vector *, int))te->Explosion)(
      a1: &filter,
      a2: -1082130432,
      a3: &vecAbsOrigin,
      a4: v13,
      a5: LODWORD(v15),
      a6: 25,
      a7: 0,
      a8: flDuration,
      a9: (int)this->m_flDamage.m_Value,
      a10: soundtime,
      a11: material_low);
    CRecipientFilter::~CRecipientFilter(this: &filter);
  }
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  CSoundEnt::InsertSound(
    iType: 1,
    vecOrigin: &this->m_vecAbsOrigin,
    iVolume: 1024,
    flDuration: 3.0,
    pOwner: nullptr,
    soundChannelIndex: 0,
    pSoundTarget: nullptr);
  m_Index = this->m_hThrower.m_Value.m_Index;
  if ( m_Index != -1
    && (v17 = (unsigned __int16)m_Index,
        v18 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index],
        v19 = HIWORD(m_Index),
        v18->m_SerialNumber == v19)
    && v18->m_pEntity != nullptr )
  {
    v20 = v17;
    v21 = g_pEntityList->m_EntPtrArray[v20].m_SerialNumber == v19;
    v22 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v20];
    if ( v21 )
      v23 = *v22;
    else
      v23 = nullptr;
    if ( (v23->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v23, a2: (int)&savedregs);
    p_m_vecAbsOrigin = (QAngle *)&v23->m_vecAbsOrigin;
  }
  else
  {
    p_m_vecAbsOrigin = (QAngle *)&vec3_origin;
  }
  vecAngles = *p_m_vecAbsOrigin;
  CBaseEntity::EmitSound(this, soundname: "BaseGrenade.Explode", soundtime: 0.0, duration: nullptr);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  v25 = this->m_hThrower.m_Value.m_Index;
  if ( v25 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v25].m_SerialNumber != HIWORD(v25) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v25].m_pEntity;
  flDamage = this->m_flDamage.m_Value;
  v27 = this->GetBlastForce(this, result: &vecNormal);
  CTakeDamageInfo::CTakeDamageInfo(
    this: &info,
    pInflictor: this,
    pAttacker: m_pEntity,
    damageForce: v27,
    damagePosition: &this->m_vecAbsOrigin,
    flDamage,
    bitsDamageType,
    iKillType: 0,
    reportedPosition: (Vector *)&vecAngles,
    iObjectsPenetrated: 0);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  RadiusDamage(
    &info,
    vecSrc: &this->m_vecAbsOrigin,
    flRadius: this->m_DmgRadius.m_Value,
    iClassIgnore: 0,
    pEntityIgnore: nullptr);
  UTIL_DecalTrace(pTrace, decalName: "Scorch");
  CBaseEntity::ThinkSet(this, func: CBaseEntity::SUB_Remove, thinkTime: 0.0, szContext: nullptr);
  this->m_pfnTouch = nullptr;
  CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  CBaseEntity::AddEffects(this, nEffects: 32);
  CBaseEntity::SetAbsVelocity(this, vecAbsVelocity: &vec3_origin);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100D6C60
// Name: public: void CBaseGrenade::BounceTouch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CBaseGrenade::BounceTouch(CBaseGrenade *this@<ecx>, int a2@<ebp>, CBaseCombatCharacter *pOther)
{
  __int128 v4; // xmm0
  const CGameTrace *TouchTrace; // eax
  CBaseEntity *v6; // eax
  const Vector *AbsVelocity; // eax
  float v8; // xmm0_4
  float m_Value; // xmm1_4
  edict_t *m_pPev; // ecx
  float v11; // xmm2_4
  __int128 v12; // xmm0
  __int128 v13; // xmm1
  float v14; // xmm0_4
  edict_t *v15; // ecx
  float v16; // xmm0_4
  edict_t *v17; // ecx
  edict_t *v18; // ecx
  const Vector *AbsOrigin; // [esp+8h] [ebp-F4h]
  _BYTE v20[12]; // [esp+18h] [ebp-E4h] BYREF
  CGameTrace tr; // [esp+24h] [ebp-D8h] BYREF
  __int128 info_84; // [esp+D0h] [ebp-2Ch] OVERLAPPED BYREF
  float v23; // [esp+ECh] [ebp-10h]
  _DWORD v24[3]; // [esp+F0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+FCh] [ebp+0h]

  v24[0] = a2;
  v24[1] = retaddr;
  if ( (pOther->m_Collision.m_usSolidFlags.m_Value & 0x28) == 0 && pOther != CBaseGrenade::GetThrower(this) )
  {
    if ( pOther->m_takedamage.m_Value != 0 && gpGlobals->curtime > this->m_flNextAttack.m_Value )
    {
      if ( (this->m_iEFlags & 0x1000) != 0 )
        CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)v24);
      v4 = 0;
      *(float *)&v4 = fsqrt(
                        (float)((float)(this->m_vecAbsVelocity.x * this->m_vecAbsVelocity.x)
                              + (float)(this->m_vecAbsVelocity.y * this->m_vecAbsVelocity.y))
                      + (float)(this->m_vecAbsVelocity.z * this->m_vecAbsVelocity.z));
      info_84 = v4;
      if ( *(float *)&v4 > 100.0 )
      {
        if ( CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hThrower) != nullptr )
        {
          TouchTrace = CBaseEntity::GetTouchTrace();
          CGameTrace::operator=(this: (CGameTrace *)v20, __that: TouchTrace);
          ClearMultiDamage();
          AngleVectors(
            angles: &this->m_angRotation.m_Value,
            forward: (Vector *)((char *)&info_84 + 4),
            right: nullptr,
            up: nullptr);
          v6 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_hThrower);
          CTakeDamageInfo::CTakeDamageInfo(
            this: (CTakeDamageInfo *)&tr.m_pEnt,
            pInflictor: this,
            pAttacker: v6,
            flDamage: 1.0,
            bitsDamageType: 128,
            iKillType: 0,
            iObjectsPenetrated: 0);
          AbsOrigin = CBaseEntity::GetAbsOrigin(this);
          AbsVelocity = CBaseEntity::GetAbsVelocity(this);
          CalculateMeleeDamageForce(
            info: (CTakeDamageInfo *)&tr.m_pEnt,
            vecMeleeDir: AbsVelocity,
            vecForceOrigin: AbsOrigin,
            flScale: 1.0);
          CBaseEntity::DispatchTraceAttack(
            this: pOther,
            info: (const CTakeDamageInfo *)&tr.m_pEnt,
            vecDir: (const Vector *)((char *)&info_84 + 4),
            ptr: (CGameTrace *)v20);
          ApplyMultiDamage();
        }
        m_Value = this->m_flNextAttack.m_Value;
        v23 = gpGlobals->curtime + 1.0;
        v8 = v23;
        if ( m_Value != v23 )
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
              CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x498u);
              v8 = v23;
            }
          }
          this->m_flNextAttack.m_Value = v8;
        }
      }
    }
    if ( (this->m_iEFlags & 0x1000) != 0 )
      CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)v24);
    if ( !this->m_bHasWarnedAI )
    {
      v11 = this->m_vecAbsVelocity.z * 0.45;
      v12 = 0;
      *(float *)&v12 = fsqrt(
                         (float)((float)(v11 * v11) + (float)(this->m_vecAbsVelocity.y * this->m_vecAbsVelocity.y))
                       + (float)(this->m_vecAbsVelocity.x * this->m_vecAbsVelocity.x));
      info_84 = v12;
      if ( *(float *)&v12 <= 60.0 )
      {
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)v24);
        CSoundEnt::InsertSound(
          iType: 8,
          vecOrigin: &this->m_vecAbsOrigin,
          iVolume: (int)(float)(this->m_flDamage.m_Value * 2.5),
          flDuration: 0.30000001,
          pOwner: this,
          soundChannelIndex: 0,
          pSoundTarget: nullptr);
        this->m_bHasWarnedAI = true;
      }
    }
    if ( (this->m_fFlags.m_Value & 1) == 0 )
      this->BounceSound(this);
    if ( (this->m_iEFlags & 0x1000) != 0 )
      CBaseEntity::CalcAbsoluteVelocity(this, a2: (int)v24);
    v13 = 0;
    *(float *)&v13 = fsqrt(
                       (float)((float)(this->m_vecAbsVelocity.z * this->m_vecAbsVelocity.z)
                             + (float)(this->m_vecAbsVelocity.x * this->m_vecAbsVelocity.x))
                     + (float)(this->m_vecAbsVelocity.y * this->m_vecAbsVelocity.y));
    info_84 = v13;
    *(float *)&v13 = this->m_flPlaybackRate.m_Value;
    v14 = *(float *)&info_84 * 0.005;
    v23 = v14;
    if ( *(float *)&v13 != v14 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
      }
      else
      {
        v15 = this->m_Network.m_pPev;
        if ( v15 != nullptr )
        {
          CBaseEdict::StateChanged(this: &v15->CBaseEdict, offset: 0x37Cu);
          v14 = v23;
        }
      }
      this->m_flPlaybackRate.m_Value = v14;
    }
    v16 = 1.0 - this->m_flFrozen.m_Value;
    if ( v16 >= 0.0 )
    {
      if ( v16 > 1.0 )
        v16 = 1.0;
    }
    else
    {
      v16 = 0.0;
    }
    if ( (float)(this->m_flPlaybackRate.m_Value * v16) <= 1.0 )
    {
      if ( CBaseAnimating::GetPlaybackRate(this) < 0.5 && this->m_flPlaybackRate.m_Value != 0.0 )
      {
        if ( this->m_Network.m_TimerEvent.m_bRegistered )
        {
          *((_BYTE *)&this->m_Network + 76) |= 1u;
        }
        else
        {
          v18 = this->m_Network.m_pPev;
          if ( v18 != nullptr )
            CBaseEdict::StateChanged(this: &v18->CBaseEdict, offset: 0x37Cu);
        }
        this->m_flPlaybackRate.m_Value = 0.0;
      }
    }
    else if ( this->m_flPlaybackRate.m_Value != 1.0 )
    {
      if ( this->m_Network.m_TimerEvent.m_bRegistered )
      {
        *((_BYTE *)&this->m_Network + 76) |= 1u;
        this->m_flPlaybackRate.m_Value = 1.0;
      }
      else
      {
        v17 = this->m_Network.m_pPev;
        if ( v17 != nullptr )
          CBaseEdict::StateChanged(this: &v17->CBaseEdict, offset: 0x37Cu);
        this->m_flPlaybackRate.m_Value = 1.0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D70C0
// Name: public: void CBaseGrenade::SetThrower(class CBaseCombatCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseGrenade::SetThrower(CBaseGrenade *this, CBaseCombatCharacter *pThrower)
{
  unsigned int m_Index; // eax

  CNetworkHandleBase<CBaseEntity,CBaseGrenade::NetworkVar_m_hThrower>::Set(this: &this->m_hThrower, val: pThrower);
  m_Index = this->m_hOriginalThrower.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    if ( pThrower != nullptr )
      this->m_hOriginalThrower.m_Index = pThrower->GetRefEHandle(this: pThrower)->m_Index;
    else
      this->m_hOriginalThrower.m_Index = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D7130
// Name: public: CBaseGrenade::CBaseGrenade(void)
// Source: json
//------------------------------------------------------------------------------
CBaseGrenade *__thiscall CBaseGrenade::CBaseGrenade(CBaseGrenade *this)
{
  unsigned int m_Index; // eax
  edict_t *m_pPev; // ecx
  edict_t *v4; // ecx
  edict_t *v5; // ecx
  bool m_Value; // zf
  CBaseGrenade *result; // eax
  edict_t *v8; // ecx

  CBaseAnimating::CBaseAnimating(this);
  this->CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&CDefaultPlayerPickupVPhysics::`vftable';
  this->CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CBaseGrenade_vtbl *)&CBaseGrenade::`vftable'{for `CBaseAnimating'};
  this->CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&CBaseGrenade::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  this->m_hThrower.m_Value.m_Index = -1;
  this->m_hOriginalThrower.m_Index = -1;
  m_Index = this->m_hThrower.m_Value.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      m_pPev = this->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        CBaseEdict::StateChanged(this: &m_pPev->CBaseEdict, offset: 0x4ACu);
    }
    this->m_hThrower.m_Value.m_Index = -1;
  }
  this->m_hOriginalThrower.m_Index = -1;
  if ( this->m_bIsLive.m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v4 = this->m_Network.m_pPev;
      if ( v4 != nullptr )
        CBaseEdict::StateChanged(this: &v4->CBaseEdict, offset: 0x491u);
    }
    this->m_bIsLive.m_Value = false;
  }
  if ( this->m_DmgRadius.m_Value != 100.0 )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
    }
    else
    {
      v5 = this->m_Network.m_pPev;
      if ( v5 != nullptr )
        CBaseEdict::StateChanged(this: &v5->CBaseEdict, offset: 0x494u);
    }
    this->m_DmgRadius.m_Value = 100.0;
  }
  m_Value = this->m_bSimulatedEveryTick.m_Value;
  this->m_flDetonateTime = 0.0;
  this->m_bHasWarnedAI = false;
  result = this;
  if ( !m_Value )
  {
    if ( this->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&this->m_Network + 76) |= 1u;
      this->m_bSimulatedEveryTick.m_Value = true;
    }
    else
    {
      v8 = this->m_Network.m_pPev;
      if ( v8 != nullptr )
        CBaseEdict::StateChanged(this: &v8->CBaseEdict, offset: 0x1F5u);
      this->m_bSimulatedEveryTick.m_Value = true;
      return this;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1035BE00
// Name: public: virtual class Vector CBaseGrenade::GetBlastForce(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CBaseGrenade::GetBlastForce(CDefaultParticleSystemQuery *this, Vector *result)
{
  *result = vec3_origin;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10400480
// Name: CBaseGrenade_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBaseGrenade_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBaseGrenade>(__formal: nullptr);
  CBaseGrenade_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104004B0
// Name: DT_BaseGrenade::_dynamic_initializer_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseGrenade::_dynamic_initializer_for__g_SendTable__()
{
  SendTable::SendTable(this: &DT_BaseGrenade::g_SendTable);
  return atexit(func: DT_BaseGrenade::_dynamic_atexit_destructor_for__g_SendTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104004D0
// Name: DT_BaseGrenade::_dynamic_initializer_for__g_SendTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BaseGrenade::_dynamic_initializer_for__g_SendTableInit__()
{
  int result; // eax

  result = ServerClassInit<DT_BaseGrenade::ignored>();
  DT_BaseGrenade::g_SendTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10419ED0
// Name: DT_BaseGrenade::_dynamic_atexit_destructor_for__g_SendTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BaseGrenade::_dynamic_atexit_destructor_for__g_SendTable__()
{
  CAI_BaseNPC::OnSetSchedule(this: (vgui::Panel *)&DT_BaseGrenade::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x100D72A0
// Name: struct datamap_t __near * DataMapInit<class CBaseGrenade>(class CBaseGrenade __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBaseGrenade>()
{
  char *Name; // eax
  char *v1; // eax

  if ( (_S2_51 & 1) == 0 )
  {
    _S2_51 |= 1u;
    nameHolder_97.m_pszBase = "CBaseGrenade";
    nameHolder_97.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_97.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_97.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_97.m_Names.m_Size = 0;
    nameHolder_97.m_Names.m_pElements = nullptr;
    nameHolder_97.m_nLenBase = 12;
    atexit(func: DataMapInit_CBaseGrenade__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBaseGrenade::m_DataMap.baseMap = &CBaseAnimating::m_DataMap;
  if ( (_S2_51 & 2) == 0 )
  {
    _S2_51 |= 2u;
    dataDesc_94[9].fieldName = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_97, pszIdentifier: "Smoke");
    dataDesc_94[9].flags = 32;
    dataDesc_94[9].fieldOffset = 0;
    dataDesc_94[9].fieldSize = 1;
    dataDesc_94[9].externalName = nullptr;
    dataDesc_94[9].pSaveRestoreOps = nullptr;
    dataDesc_94[9].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseGrenade::Smoke;
    *(_QWORD *)&dataDesc_94[9].td = 0;
    *(_QWORD *)&dataDesc_94[9].override_field = 0;
    *(_QWORD *)&dataDesc_94[9].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_94[9].flatOffset[1] = 0;
    dataDesc_94[10].fieldType = FIELD_VOID;
    dataDesc_94[10].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_97,
                                  pszIdentifier: "BounceTouch");
    dataDesc_94[10].fieldOffset = 0;
    dataDesc_94[10].fieldSize = 1;
    dataDesc_94[10].flags = 32;
    dataDesc_94[10].externalName = nullptr;
    dataDesc_94[10].pSaveRestoreOps = nullptr;
    dataDesc_94[10].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseGrenade::BounceTouch;
    *(_QWORD *)&dataDesc_94[10].td = 0;
    *(_QWORD *)&dataDesc_94[10].override_field = 0;
    *(_QWORD *)&dataDesc_94[10].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_94[10].flatOffset[1] = 0;
    dataDesc_94[11].fieldType = FIELD_VOID;
    Name = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_97, pszIdentifier: "SlideTouch");
    dataDesc_94[11].fieldSize = 1;
    dataDesc_94[11].fieldName = Name;
    dataDesc_94[11].fieldOffset = 0;
    dataDesc_94[11].flags = 32;
    dataDesc_94[11].externalName = nullptr;
    dataDesc_94[11].pSaveRestoreOps = nullptr;
    dataDesc_94[11].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseGrenade::SlideTouch;
    *(_QWORD *)&dataDesc_94[11].td = 0;
    *(_QWORD *)&dataDesc_94[11].override_field = 0;
    *(_QWORD *)&dataDesc_94[11].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_94[11].flatOffset[1] = 0;
    dataDesc_94[12].fieldType = FIELD_VOID;
    dataDesc_94[12].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_97,
                                  pszIdentifier: "ExplodeTouch");
    dataDesc_94[12].flags = 32;
    dataDesc_94[12].fieldOffset = 0;
    dataDesc_94[12].fieldSize = 1;
    dataDesc_94[12].externalName = nullptr;
    dataDesc_94[12].pSaveRestoreOps = nullptr;
    dataDesc_94[12].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseGrenade::ExplodeTouch;
    *(_QWORD *)&dataDesc_94[12].td = 0;
    *(_QWORD *)&dataDesc_94[12].override_field = 0;
    *(_QWORD *)&dataDesc_94[12].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_94[12].flatOffset[1] = 0;
    dataDesc_94[13].fieldType = FIELD_VOID;
    dataDesc_94[13].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_97,
                                  pszIdentifier: "DetonateUse");
    dataDesc_94[13].fieldOffset = 0;
    dataDesc_94[13].fieldSize = 1;
    dataDesc_94[13].flags = 32;
    dataDesc_94[13].externalName = nullptr;
    dataDesc_94[13].pSaveRestoreOps = nullptr;
    dataDesc_94[13].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseGrenade::DetonateUse;
    *(_QWORD *)&dataDesc_94[13].td = 0;
    *(_QWORD *)&dataDesc_94[13].override_field = 0;
    *(_QWORD *)&dataDesc_94[13].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_94[13].flatOffset[1] = 0;
    dataDesc_94[14].fieldType = FIELD_VOID;
    v1 = CDatadescGeneratedNameHolder::GenerateName(this: &nameHolder_97, pszIdentifier: "DangerSoundThink");
    dataDesc_94[14].fieldSize = 1;
    dataDesc_94[14].fieldName = v1;
    dataDesc_94[14].fieldOffset = 0;
    dataDesc_94[14].flags = 32;
    dataDesc_94[14].externalName = nullptr;
    dataDesc_94[14].pSaveRestoreOps = nullptr;
    dataDesc_94[14].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseGrenade::DangerSoundThink;
    *(_QWORD *)&dataDesc_94[14].td = 0;
    *(_QWORD *)&dataDesc_94[14].override_field = 0;
    *(_QWORD *)&dataDesc_94[14].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_94[14].flatOffset[1] = 0;
    dataDesc_94[15].fieldType = FIELD_VOID;
    dataDesc_94[15].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_97,
                                  pszIdentifier: "PreDetonate");
    dataDesc_94[15].flags = 32;
    dataDesc_94[15].fieldOffset = 0;
    dataDesc_94[15].fieldSize = 1;
    dataDesc_94[15].externalName = nullptr;
    dataDesc_94[15].pSaveRestoreOps = nullptr;
    dataDesc_94[15].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseGrenade::PreDetonate;
    *(_QWORD *)&dataDesc_94[15].td = 0;
    *(_QWORD *)&dataDesc_94[15].override_field = 0;
    *(_QWORD *)&dataDesc_94[15].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_94[15].flatOffset[1] = 0;
    dataDesc_94[16].fieldType = FIELD_VOID;
    dataDesc_94[16].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_97,
                                  pszIdentifier: "Detonate");
    dataDesc_94[16].fieldOffset = 0;
    dataDesc_94[16].fieldSize = 1;
    dataDesc_94[16].flags = 32;
    dataDesc_94[16].externalName = nullptr;
    dataDesc_94[16].pSaveRestoreOps = nullptr;
    dataDesc_94[16].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *)) __thiscall CItem::`vcall'{920,{flat}};
    *(_QWORD *)&dataDesc_94[16].td = 0;
    *(_QWORD *)&dataDesc_94[16].override_field = 0;
    *(_QWORD *)&dataDesc_94[16].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_94[16].flatOffset[1] = 0;
    dataDesc_94[17].fieldType = FIELD_VOID;
    dataDesc_94[17].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_97,
                                  pszIdentifier: "TumbleThink");
    dataDesc_94[17].fieldOffset = 0;
    *(_DWORD *)&dataDesc_94[17].fieldSize = 2097153;
    dataDesc_94[17].externalName = nullptr;
    dataDesc_94[17].pSaveRestoreOps = nullptr;
    dataDesc_94[17].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CBaseGrenade::TumbleThink;
    *(_QWORD *)&dataDesc_94[17].td = 0;
    *(_QWORD *)&dataDesc_94[17].override_field = 0;
    *(_QWORD *)&dataDesc_94[17].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_94[17].flatOffset[1] = 0;
  }
  CBaseGrenade::m_DataMap.dataNumFields = 17;
  CBaseGrenade::m_DataMap.dataDesc = &dataDesc_94[1];
  return &CBaseGrenade::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10400490
// Name: _dynamic_initializer_for__g_CBaseGrenade_ClassReg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ServerClass *dynamic_initializer_for__g_CBaseGrenade_ClassReg__()
{
  return ServerClass::ServerClass(
           this: &g_CBaseGrenade_ClassReg,
           pNetworkName: "CBaseGrenade",
           pTable: &DT_BaseGrenade::g_SendTable);
}

//------------------------------------------------------------------------------
// Address: 0x10419EE0
// Name: _ServerClassInit_DT_BaseGrenade::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ServerClassInit_DT_BaseGrenade::ignored__::_2_::_dynamic_atexit_destructor_for__g_SendProps__()
{
  SendProp *v0; // esi
  int i; // edi

  v0 = (SendProp *)&_S3_27;
  for ( i = 7; i >= 0; --i )
    SendProp::~SendProp(this: --v0);
}

//------------------------------------------------------------------------------
// Address: 0x10419F00
// Name: _DataMapInit_CBaseGrenade__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_CBaseGrenade__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_97);
}

//------------------------------------------------------------------------------
// Address: 0x10419F10
// Name: _dynamic_atexit_destructor_for__sv_allchat__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__sv_allchat__()
{
  ConVar::~ConVar(this: &sv_allchat);
}

//------------------------------------------------------------------------------
// Address: 0x10419F20
// Name: _dynamic_atexit_destructor_for__tf_escort_score_rate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__tf_escort_score_rate__()
{
  ConVar::~ConVar(this: &tf_escort_score_rate);
}

//------------------------------------------------------------------------------
// Address: 0x10419F30
// Name: _dynamic_atexit_destructor_for__g_CBaseMultiplayerPlayer_ScriptDesc__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CBaseMultiplayerPlayer_ScriptDesc__()
{
  CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>::~CUtlVector<ScriptFunctionBinding_t,CUtlMemory<ScriptFunctionBinding_t,int>>(this: &g_CBaseMultiplayerPlayer_ScriptDesc.m_FunctionBindings);
}

} // namespace server
