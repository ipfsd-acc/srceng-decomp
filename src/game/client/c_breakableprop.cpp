// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_breakableprop.cpp
// Functions: 18
// ============================================================

#include "game\client\c_breakableprop.h"

//------------------------------------------------------------------------------
// Address: 0x100618F0
// Name: public: virtual class ClientClass __near * C_BreakableProp::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_BreakableProp::GetClientClass(C_BreakableProp *this)
{
  return &__g_C_BreakablePropClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x100619A0
// Name: public: void C_BreakableProp::CopyFadeFrom(class C_BreakableProp __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BreakableProp::CopyFadeFrom(C_BreakableProp *this, C_BreakableProp *pSource)
{
  float flMinDist; // [esp+0h] [ebp-10h]
  float flFadeScale; // [esp+4h] [ebp-Ch]
  float flFadeScalea; // [esp+4h] [ebp-Ch]

  flFadeScale = C_BaseEntity::GetGlobalFadeScale(this: pSource);
  C_BaseEntity::SetGlobalFadeScale(this, a2: (int)pSource, a3: (int)this, flFadeScale);
  flFadeScalea = C_BaseEntity::GetMaxFadeDist(this: pSource);
  flMinDist = C_BaseEntity::GetMinFadeDist(this: pSource);
  C_BaseEntity::SetDistanceFade(this, flMinDist, flMaxDist: flFadeScalea);
}

//------------------------------------------------------------------------------
// Address: 0x100619E0
// Name: public: virtual void C_BreakableProp::OnDataChanged(enum DataUpdateType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_BreakableProp::OnDataChanged(C_BreakableProp *this, DataUpdateType_t type)
{
  C_BaseAnimating::OnDataChanged(this, updateType: type);
  if ( LOBYTE(this->m_qPreferredPlayerCarryAngles.y) != 0 )
    VPhysicsShadowDataChanged(bCreate: type == DATA_UPDATE_CREATED, pEntity: (C_BreakableProp *)((char *)this - 8));
}

//------------------------------------------------------------------------------
// Address: 0x10061A20
// Name: public: virtual bool C_BreakableProp::HasPreferredCarryAnglesForPlayer(class C_BasePlayer __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall C_BreakableProp::HasPreferredCarryAnglesForPlayer(C_BreakableProp *this, C_BasePlayer *pPlayer)
{
  return *(float *)&this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable < 3.4028235e38;
}

//------------------------------------------------------------------------------
// Address: 0x10061A40
// Name: public: virtual class QAngle C_BreakableProp::PreferredCarryAngles(void)
// Source: json
//------------------------------------------------------------------------------
QAngle *__thiscall C_BreakableProp::PreferredCarryAngles(C_BreakableProp *this, QAngle *result)
{
  IClientRenderable *v2; // ecx
  __int64 v3; // xmm0_8
  float v5; // ecx

  v2 = &this->IClientRenderable;
  if ( *(float *)&v2->__vftable >= 3.4028235e38 )
    v2 = (IClientRenderable *)&vec3_angle;
  v3 = *(_QWORD *)&v2->__vftable;
  v5 = *(float *)&v2[2].__vftable;
  *(_QWORD *)&result->x = v3;
  result->z = v5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10061A90
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
// Address: 0x10061AB0
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
// Address: 0x10061AE0
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
// Address: 0x10061B60
// Name: public: C_BreakableProp::C_BreakableProp(void)
// Source: json
//------------------------------------------------------------------------------
C_BreakableProp *__thiscall C_BreakableProp::C_BreakableProp(C_BreakableProp *this)
{
  C_BaseAnimating::C_BaseAnimating(this);
  this->CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&CDefaultPlayerPickupVPhysics::`vftable';
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BreakableProp_vtbl *)&C_BreakableProp::`vftable'{for `IClientUnknown'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_BreakableProp::`vftable'{for `IClientRenderable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_BreakableProp::`vftable'{for `IClientNetworkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_BreakableProp::`vftable'{for `IClientThinkable'};
  this->C_BaseAnimating::C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_BreakableProp::`vftable'{for `C_BaseAnimating'};
  this->CDefaultPlayerPickupVPhysics::IPlayerPickupVPhysics::__vftable = (CDefaultPlayerPickupVPhysics_vtbl *)&C_BreakableProp::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  this->m_takedamage = 2;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x104117A0
// Name: DT_BreakableProp::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_BreakableProp::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_BreakableProp::g_RecvTable);
  return atexit(func: DT_BreakableProp::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x104117C0
// Name: DT_BreakableProp::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_BreakableProp::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_BreakableProp::ignored>();
  DT_BreakableProp::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104300E0
// Name: DT_BreakableProp::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_BreakableProp::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_BreakableProp::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10061BB0
// Name: _C_BreakableProp_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_BreakableProp_CreateObject(int entnum, int serialNum)
{
  C_BaseAnimating *v2; // eax
  C_BaseAnimating *v3; // esi

  v2 = (C_BaseAnimating *)C_BaseEntity::operator new(stAllocateBlock: 0xCD0u);
  v3 = v2;
  if ( v2 == nullptr )
    return nullptr;
  C_BaseAnimating::C_BaseAnimating(this: v2);
  v3[1].C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BaseAnimating_vtbl *)&CDefaultPlayerPickupVPhysics::`vftable';
  v3->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BaseAnimating_vtbl *)&C_BreakableProp::`vftable'{for `IClientUnknown'};
  v3->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_BreakableProp::`vftable'{for `IClientRenderable'};
  v3->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_BreakableProp::`vftable'{for `IClientNetworkable'};
  v3->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_BreakableProp::`vftable'{for `IClientThinkable'};
  v3->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_BreakableProp::`vftable'{for `C_BaseAnimating'};
  v3[1].C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_BaseAnimating_vtbl *)&C_BreakableProp::`vftable'{for `CDefaultPlayerPickupVPhysics'};
  v3->m_takedamage = 2;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v3->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x104117D0
// Name: _dynamic_initializer_for__mat_colcorrection_disableentities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_colcorrection_disableentities__()
{
  ConVar::ConVar(
    this: &mat_colcorrection_disableentities,
    pName: "mat_colcorrection_disableentities",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Disable map color-correction entities");
  return atexit(func: dynamic_atexit_destructor_for__mat_colcorrection_disableentities__);
}

//------------------------------------------------------------------------------
// Address: 0x10411800
// Name: _dynamic_initializer_for__mat_colcorrection_forceentitiesclientside__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_colcorrection_forceentitiesclientside__()
{
  ConVar::ConVar(
    this: &mat_colcorrection_forceentitiesclientside,
    pName: "mat_colcorrection_forceentitiesclientside",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Forces color correction entities to be updated on the client");
  return atexit(func: dynamic_atexit_destructor_for__mat_colcorrection_forceentitiesclientside__);
}

//------------------------------------------------------------------------------
// Address: 0x10411830
// Name: _dynamic_initializer_for____g_C_ColorCorrectionClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_ColorCorrectionClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_ColorCorrectionClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_ColorCorrectionClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104300F0
// Name: _dynamic_atexit_destructor_for__mat_colcorrection_disableentities__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_colcorrection_disableentities__()
{
  ConVar::~ConVar(this: &mat_colcorrection_disableentities);
}

//------------------------------------------------------------------------------
// Address: 0x10430100
// Name: _dynamic_atexit_destructor_for__mat_colcorrection_forceentitiesclientside__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_colcorrection_forceentitiesclientside__()
{
  ConVar::~ConVar(this: &mat_colcorrection_forceentitiesclientside);
}
