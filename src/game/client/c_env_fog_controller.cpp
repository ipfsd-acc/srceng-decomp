// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/c_env_fog_controller.cpp
// Functions: 8
// ============================================================

#include "game\client\c_env_fog_controller.h"

//------------------------------------------------------------------------------
// Address: 0x10067820
// Name: public: virtual class ClientClass __near * C_FogController::GetClientClass(void)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall C_FogController::GetClientClass(C_FogController *this)
{
  return &__g_C_FogControllerClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x10067A70
// Name: public: C_FogController::C_FogController(void)
// Source: json
//------------------------------------------------------------------------------
C_FogController *__thiscall C_FogController::C_FogController(C_FogController *this)
{
  C_BaseEntity::C_BaseEntity(this);
  this->C_BaseEntity::IClientEntity::IClientUnknown::IHandleEntity::__vftable = (C_FogController_vtbl *)&C_FogController::`vftable'{for `IClientUnknown'};
  this->C_BaseEntity::IClientEntity::IClientRenderable::__vftable = (IClientRenderable_vtbl *)&C_FogController::`vftable'{for `IClientRenderable'};
  this->C_BaseEntity::IClientEntity::IClientNetworkable::__vftable = (IClientNetworkable_vtbl *)&C_FogController::`vftable'{for `IClientNetworkable'};
  this->C_BaseEntity::IClientEntity::IClientThinkable::__vftable = (IClientThinkable_vtbl *)&C_FogController::`vftable'{for `IClientThinkable'};
  this->C_BaseEntity::IClientModelRenderable::__vftable = (IClientModelRenderable_vtbl *)&C_FogController::`vftable';
  this->m_fog.__vftable = (fogparams_t_vtbl *)&fogparams_t::`vftable';
  if ( this->m_fog.enable.m_Value )
  {
    this->m_fog.NetworkStateChanged(this: &this->m_fog, a2: &this->m_fog.enable);
    this->m_fog.enable.m_Value = false;
  }
  if ( this->m_fog.maxdensity.m_Value != 1.0 )
  {
    this->m_fog.NetworkStateChanged(this: &this->m_fog, a2: &this->m_fog.maxdensity);
    this->m_fog.maxdensity.m_Value = 1.0;
  }
  if ( this->m_fog.HDRColorScale.m_Value != 1.0 )
  {
    this->m_fog.NetworkStateChanged(this: &this->m_fog, a2: &this->m_fog.HDRColorScale);
    this->m_fog.HDRColorScale.m_Value = 1.0;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10411C60
// Name: DT_FogController::_dynamic_initializer_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
int DT_FogController::_dynamic_initializer_for__g_RecvTable__()
{
  RecvTable::RecvTable(this: &DT_FogController::g_RecvTable);
  return atexit(func: DT_FogController::_dynamic_atexit_destructor_for__g_RecvTable__);
}

//------------------------------------------------------------------------------
// Address: 0x10411C80
// Name: DT_FogController::_dynamic_initializer_for__g_RecvTableInit__
// Source: json
//------------------------------------------------------------------------------
int DT_FogController::_dynamic_initializer_for__g_RecvTableInit__()
{
  int result; // eax

  result = ClientClassInit<DT_FogController::ignored>();
  DT_FogController::g_RecvTableInit = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10430200
// Name: DT_FogController::_dynamic_atexit_destructor_for__g_RecvTable__
// Source: json
//------------------------------------------------------------------------------
void __cdecl DT_FogController::_dynamic_atexit_destructor_for__g_RecvTable__()
{
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: (vgui::PropertyPage *)&DT_FogController::g_RecvTable);
}

//------------------------------------------------------------------------------
// Address: 0x10067B30
// Name: _C_FogController_CreateObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IClientNetworkable *__cdecl C_FogController_CreateObject(int entnum, int serialNum)
{
  C_FogController *v2; // eax
  C_FogController *v3; // eax
  C_FogController *v4; // esi

  v2 = (C_FogController *)C_BaseEntity::operator new(stAllocateBlock: 0x9D0u);
  if ( v2 == nullptr )
    return nullptr;
  v3 = C_FogController::C_FogController(this: v2);
  v4 = v3;
  if ( v3 == nullptr )
    return nullptr;
  v3->Init(this: v3, a2: entnum, a3: serialNum);
  return &v4->IClientNetworkable;
}

//------------------------------------------------------------------------------
// Address: 0x10411C90
// Name: _dynamic_initializer_for__g_C_EnvParticleScript_RegistrationHelper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall dynamic_initializer_for__g_C_EnvParticleScript_RegistrationHelper__(const char *a1@<edi>)
{
  CParticleMgr *v1; // eax
  const char *v2; // [esp-8h] [ebp-8h]

  v2 = type_info::name(this: &C_EnvParticleScript `RTTI Type Descriptor', __ptype_info_node: &__type_info_root_node);
  v1 = ParticleMgr();
  CParticleMgr::RegisterEffect(this: v1, a2: a1, pEffectType: v2, func: C_EnvParticleScript_Factory);
}

//------------------------------------------------------------------------------
// Address: 0x10411CC0
// Name: _dynamic_initializer_for____g_C_EnvParticleScriptClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_EnvParticleScriptClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_EnvParticleScriptClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_EnvParticleScriptClientClass;
  return result;
}
