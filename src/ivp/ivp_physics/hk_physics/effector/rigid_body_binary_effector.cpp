// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_physics/hk_physics/effector/rigid_body_binary_effector.cpp
// Functions: 1
// ============================================================

#include "ivp\ivp_physics\hk_physics\effector\rigid_body_binary_effector.h"

//------------------------------------------------------------------------------
// Address: 0x10043830
// Name: protected: hk_Rigid_Body_Binary_EF::hk_Rigid_Body_Binary_EF(class hk_Environment __near *,class hk_Rigid_Body __near *,class hk_Rigid_Body __near *,enum IVP_CONTROLLER_PRIORITY)
// Source: json
//------------------------------------------------------------------------------
hk_Rigid_Body_Binary_EF *__thiscall hk_Rigid_Body_Binary_EF::hk_Rigid_Body_Binary_EF(
        hk_Rigid_Body_Binary_EF *this,
        hk_Environment *env,
        hk_Rigid_Body *a,
        hk_Rigid_Body *b,
        IVP_CONTROLLER_PRIORITY __formal)
{
  this->m_entities[0] = a;
  this->__vftable = (hk_Rigid_Body_Binary_EF_vtbl *)&hk_Rigid_Body_Binary_EF::`vftable';
  this->m_entities[1] = b;
  this->m_environment = env;
  return this;
}
