// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/havana/havok/hk_physics/constraint/constraint.cpp
// Functions: 2
// ============================================================

#include "ivp\havana\havok\hk_physics\constraint\constraint.h"

//------------------------------------------------------------------------------
// Address: 0x10043860
// Name: public: hk_Constraint::hk_Constraint(class hk_Local_Constraint_System __near *,class hk_Rigid_Body __near *,class hk_Rigid_Body __near *,enum IVP_CONTROLLER_PRIORITY,int)
// Source: json
//------------------------------------------------------------------------------
hk_Constraint *__thiscall hk_Constraint::hk_Constraint(
        hk_Constraint *this,
        hk_Local_Constraint_System *sys,
        hk_Rigid_Body *a,
        hk_Rigid_Body *b,
        IVP_CONTROLLER_PRIORITY redundend_prio,
        int storage_size)
{
  hk_Rigid_Body_Binary_EF::hk_Rigid_Body_Binary_EF(this, env: nullptr, a, b, __formal: IVP_CP_NONE);
  this->__vftable = (hk_Constraint_vtbl *)&hk_Constraint::`vftable';
  this->m_constraint_system = sys;
  hk_Local_Constraint_System::add_constraint(this: sys, constraint: this, storage_size);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100438A0
// Name: public: virtual hk_Constraint::~hk_Constraint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Constraint::~hk_Constraint(hk_Constraint *this)
{
  hk_Local_Constraint_System *m_constraint_system; // ecx

  m_constraint_system = this->m_constraint_system;
  this->__vftable = (hk_Constraint_vtbl *)&hk_Constraint::`vftable';
  if ( m_constraint_system != nullptr )
    hk_Local_Constraint_System::constraint_deletion_event(this: m_constraint_system, constraint: this);
  this->__vftable = (hk_Constraint_vtbl *)&hk_Rigid_Body_Binary_EF::`vftable';
}
