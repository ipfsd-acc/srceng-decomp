// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/havana/havok/hk_physics/constraint/breakable_constraint/breakable_constraint.cpp
// Functions: 14
// ============================================================

#include "ivp\havana\havok\hk_physics\constraint\breakable_constraint\breakable_constraint.h"

//------------------------------------------------------------------------------
// Address: 0x10035450
// Name: public: virtual char const __near * hk_Constraint::get_constraint_type(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall hk_Constraint::get_constraint_type(hk_Constraint *this)
{
  return "unknown";
}

//------------------------------------------------------------------------------
// Address: 0x10035460
// Name: public: virtual hk_Breakable_Constraint::~hk_Breakable_Constraint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Breakable_Constraint::~hk_Breakable_Constraint(hk_Breakable_Constraint *this)
{
  hk_Constraint *m_real_constraint; // ecx

  m_real_constraint = this->m_real_constraint;
  this->__vftable = (hk_Breakable_Constraint_vtbl *)&hk_Breakable_Constraint::`vftable';
  if ( m_real_constraint != nullptr )
    ((void (__thiscall *)(hk_Constraint *, int))m_real_constraint->dtr_hk_Constraint)(a1: m_real_constraint, a2: 1);
  hk_Constraint::~hk_Constraint(this);
}

//------------------------------------------------------------------------------
// Address: 0x10035490
// Name: public: virtual char const __near * hk_Breakable_Constraint::get_constraint_type(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall hk_Breakable_Constraint::get_constraint_type(hk_Breakable_Constraint *this)
{
  return this->m_real_constraint->get_constraint_type(this: this->m_real_constraint);
}

//------------------------------------------------------------------------------
// Address: 0x100354A0
// Name: public: virtual int hk_Breakable_Constraint::get_constraint_dof(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall hk_Breakable_Constraint::get_constraint_dof(hk_Breakable_Constraint *this)
{
  return this->m_real_constraint->get_constraint_dof(this: this->m_real_constraint);
}

//------------------------------------------------------------------------------
// Address: 0x100354B0
// Name: protected: void hk_Breakable_Constraint::init_breakable_constraint(class hk_Breakable_Constraint_BP const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Breakable_Constraint::init_breakable_constraint(
        hk_Breakable_Constraint *this,
        const hk_Breakable_Constraint_BP *bp)
{
  double m_angular_strength; // st7

  this->m_real_constraint = bp->m_real_constraint;
  this->m_linear_strength = bp->m_linear_strength;
  m_angular_strength = bp->m_angular_strength;
  this->m_is_broken = false;
  this->m_angular_strength = m_angular_strength;
  *(_QWORD *)this->m_bodyMassScale = *(_QWORD *)bp->m_bodyMassScale;
}

//------------------------------------------------------------------------------
// Address: 0x100354E0
// Name: public: void hk_Breakable_Constraint::write_to_blueprint(class hk_Breakable_Constraint_BP __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Breakable_Constraint::write_to_blueprint(
        hk_Breakable_Constraint *this,
        hk_Breakable_Constraint_BP *pOutBP)
{
  pOutBP->m_real_constraint = this->m_real_constraint;
  pOutBP->m_linear_strength = this->m_linear_strength;
  pOutBP->m_angular_strength = this->m_angular_strength;
  *(_QWORD *)pOutBP->m_bodyMassScale = *(_QWORD *)this->m_bodyMassScale;
}

//------------------------------------------------------------------------------
// Address: 0x10035510
// Name: public: virtual int hk_Breakable_Constraint::get_vmq_storage_size(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall hk_Breakable_Constraint::get_vmq_storage_size(hk_Breakable_Constraint *this)
{
  return this->m_real_constraint->get_vmq_storage_size(this: this->m_real_constraint);
}

//------------------------------------------------------------------------------
// Address: 0x10035520
// Name: public: void hk_Breakable_Constraint::FireEventIfBroken(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Breakable_Constraint::FireEventIfBroken(hk_Breakable_Constraint *this)
{
  hk_Local_Constraint_System *m_constraint_system; // eax
  IVP_Environment *m_environment; // ecx

  if ( this->m_is_broken )
  {
    m_constraint_system = this->m_constraint_system;
    if ( m_constraint_system->m_is_active )
    {
      m_environment = m_constraint_system->m_environment;
      if ( m_environment != nullptr )
        IVP_Environment::fire_event_constraint_broken(this: m_environment, constraint: this);
    }
  }
  this->m_is_broken = false;
}

//------------------------------------------------------------------------------
// Address: 0x10035590
// Name: public: hk_Breakable_Constraint::hk_Breakable_Constraint(class hk_Local_Constraint_System __near *,class hk_Breakable_Constraint_BP const __near *)
// Source: json
//------------------------------------------------------------------------------
hk_Breakable_Constraint *__thiscall hk_Breakable_Constraint::hk_Breakable_Constraint(
        hk_Breakable_Constraint *this,
        hk_Local_Constraint_System *constraint_system,
        const hk_Breakable_Constraint_BP *bp)
{
  hk_Constraint_vtbl *v5; // edx
  hk_Rigid_Body *v6; // ebx
  int v7; // eax
  hk_Rigid_Body *v9; // [esp+18h] [ebp+Ch]

  v5 = bp->m_real_constraint->__vftable;
  v6 = bp->m_real_constraint->m_entities[1];
  v9 = bp->m_real_constraint->m_entities[0];
  v7 = ((int (*)(void))v5->get_vmq_storage_size)();
  hk_Constraint::hk_Constraint(
    this,
    sys: constraint_system,
    a: v9,
    b: v6,
    redundend_prio: IVP_CP_CONSTRAINTS,
    storage_size: v7);
  this->__vftable = (hk_Breakable_Constraint_vtbl *)&hk_Breakable_Constraint::`vftable';
  hk_Breakable_Constraint::init_breakable_constraint(this, bp);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100355E0
// Name: public: virtual void hk_Breakable_Constraint::init_constraint(void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Breakable_Constraint::init_constraint(
        hk_Breakable_Constraint *this,
        const hk_Breakable_Constraint_BP *vbp)
{
  hk_Breakable_Constraint::init_breakable_constraint(this, bp: vbp);
}

//------------------------------------------------------------------------------
// Address: 0x100355F0
// Name: public: BreakableConstraintHelper::BreakableConstraintHelper(class hk_Rigid_Body __near *,float)
// Source: json
//------------------------------------------------------------------------------
BreakableConstraintHelper *__thiscall BreakableConstraintHelper::BreakableConstraintHelper(
        BreakableConstraintHelper *this,
        hk_Rigid_Body *b,
        float massScale)
{
  hk_Rigid_Body_Core *physical_core; // eax
  float v4; // xmm0_4
  hk_Rigid_Body_Core *m_core; // eax
  IVP_Core *v6; // eax
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4

  physical_core = (hk_Rigid_Body_Core *)b->physical_core;
  v4 = massScale;
  this->m_core = physical_core;
  this->m_old_lin_vel.x = physical_core->speed.k[0];
  this->m_old_lin_vel.y = physical_core->speed.k[1];
  this->m_old_lin_vel.z = physical_core->speed.k[2];
  m_core = this->m_core;
  this->m_old_ang_vel.x = this->m_core->rot_speed.k[0];
  this->m_old_ang_vel.y = m_core->rot_speed.k[1];
  this->m_old_ang_vel.z = m_core->rot_speed.k[2];
  this->m_pBody = b;
  this->m_massScale = massScale;
  if ( massScale == 1.0 || massScale <= 0.0 || (*(_WORD *)&this->m_core->IVP_Core_Fast_Static & 0x12) != 0 )
  {
    this->m_massScale = 1.0;
    return this;
  }
  else
  {
    v6 = b->physical_core;
    v7 = v6->rot_inertia.k[1];
    v8 = v6->rot_inertia.k[2];
    this->m_oldRotInertia.k[0] = v6->rot_inertia.k[0];
    this->m_oldRotInertia.k[2] = v8;
    this->m_oldRotInertia.k[1] = v7;
    this->m_oldRotInertia.hesse_val = v6->rot_inertia.hesse_val;
    v9 = v6->inv_rot_inertia.k[1];
    v10 = v6->inv_rot_inertia.k[2];
    this->m_oldInvRotInertia.k[0] = v6->inv_rot_inertia.k[0];
    this->m_oldInvRotInertia.k[2] = v10;
    this->m_oldInvRotInertia.k[1] = v9;
    this->m_oldInvRotInertia.hesse_val = v6->inv_rot_inertia.hesse_val;
    if ( (float)(this->m_core->rot_inertia.hesse_val * massScale) > 10000.0 )
      v4 = 10000.0 / this->m_core->rot_inertia.hesse_val;
    v6->rot_inertia.k[0] = v6->rot_inertia.k[0] * v4;
    v6->rot_inertia.k[1] = v6->rot_inertia.k[1] * v4;
    v6->rot_inertia.k[2] = v6->rot_inertia.k[2] * v4;
    v6->rot_inertia.hesse_val = v6->rot_inertia.hesse_val * v4;
    v6->inv_rot_inertia.k[0] = v6->inv_rot_inertia.k[0] * (float)(1.0 / v4);
    v6->inv_rot_inertia.k[1] = v6->inv_rot_inertia.k[1] * (float)(1.0 / v4);
    v6->inv_rot_inertia.k[2] = (float)(1.0 / v4) * v6->inv_rot_inertia.k[2];
    v6->inv_rot_inertia.hesse_val = v6->inv_rot_inertia.hesse_val * (float)(1.0 / v4);
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035770
// Name: public: virtual int hk_Breakable_Constraint::setup_and_step_constraint(class hk_PSI_Info __near &,void __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
int __userpurge hk_Breakable_Constraint::setup_and_step_constraint@<eax>(
        hk_Breakable_Constraint *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        hk_PSI_Info *pi,
        void *mem,
        float tau_factor,
        float damp_factor)
{
  float massScale; // xmm0_4
  float v10; // edi
  float m_linear_strength; // xmm3_4
  float m_angular_strength; // xmm4_4
  float v13; // xmm0_4
  bool v14; // al
  float v15; // eax
  int v16; // ecx
  int v17; // eax
  int v18; // eax
  float v21[3]; // [esp+18h] [ebp-ACh] BYREF
  BreakableConstraintHelper ss0; // [esp+24h] [ebp-A0h] BYREF
  BreakableConstraintHelper ss1; // [esp+74h] [ebp-50h]
  float retaddr; // [esp+C4h] [ebp+0h]

  ss1.m_oldInvRotInertia.k[1] = a2;
  ss1.m_oldInvRotInertia.k[2] = retaddr;
  massScale = this->m_bodyMassScale[0];
  this->m_is_broken = false;
  BreakableConstraintHelper::BreakableConstraintHelper(
    this: (BreakableConstraintHelper *)v21,
    b: this->m_entities[0],
    massScale);
  BreakableConstraintHelper::BreakableConstraintHelper(
    this: (BreakableConstraintHelper *)&ss0.m_oldInvRotInertia.k[1],
    b: this->m_entities[1],
    massScale: this->m_bodyMassScale[1]);
  ((void (__thiscall *)(hk_Constraint *, hk_PSI_Info *, void *, _DWORD, _DWORD, int, int))this->m_real_constraint->setup_and_step_constraint)(
    a1: this->m_real_constraint,
    a2: pi,
    a3: mem,
    a4: LODWORD(tau_factor),
    a5: LODWORD(damp_factor),
    a6: a3,
    a7: a4);
  v10 = v21[0];
  m_linear_strength = this->m_linear_strength;
  m_angular_strength = this->m_angular_strength;
  v14 = true;
  if ( (float)(m_linear_strength * m_linear_strength) > (float)((float)((float)((float)((float)(*(float *)(LODWORD(v21[0]) + 212)
                                                                                              - v21[2])
                                                                                      * (float)(*(float *)(LODWORD(v21[0]) + 212)
                                                                                              - v21[2]))
                                                                              + (float)((float)(*(float *)(LODWORD(v21[0]) + 208)
                                                                                              - v21[1])
                                                                                      * (float)(*(float *)(LODWORD(v21[0]) + 208)
                                                                                              - v21[1])))
                                                                      + (float)((float)(*(float *)(LODWORD(v21[0]) + 216)
                                                                                      - *(float *)&ss0.m_core)
                                                                              * (float)(*(float *)(LODWORD(v21[0]) + 216)
                                                                                      - *(float *)&ss0.m_core)))
                                                              * *(float *)(LODWORD(v21[0]) + 28)) )
  {
    v13 = *(float *)(LODWORD(v21[0]) + 16) * (float)(*(float *)(LODWORD(v21[0]) + 192) - ss0.m_old_lin_vel.y);
    if ( (float)(m_angular_strength * m_angular_strength) > (float)((float)((float)((float)(*(float *)(LODWORD(v21[0]) + 20)
                                                                                          * (float)(*(float *)(LODWORD(v21[0]) + 196)
                                                                                                  - ss0.m_old_lin_vel.z))
                                                                                  * (float)(*(float *)(LODWORD(v21[0]) + 20)
                                                                                          * (float)(*(float *)(LODWORD(v21[0]) + 196)
                                                                                                  - ss0.m_old_lin_vel.z)))
                                                                          + (float)(v13 * v13))
                                                                  + (float)((float)(*(float *)(LODWORD(v21[0]) + 24)
                                                                                  * (float)(*(float *)(LODWORD(v21[0]) + 200)
                                                                                          - ss0.m_old_lin_vel.w))
                                                                          * (float)(*(float *)(LODWORD(v21[0]) + 24)
                                                                                  * (float)(*(float *)(LODWORD(v21[0]) + 200)
                                                                                          - ss0.m_old_lin_vel.w))))
      && (float)(m_linear_strength * m_linear_strength) > (float)((float)((float)((float)((float)(*(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1]) + 208)
                                                                                                - ss0.m_oldInvRotInertia.k[2])
                                                                                        * (float)(*(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1]) + 208)
                                                                                                - ss0.m_oldInvRotInertia.k[2]))
                                                                                + (float)((float)(*(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1]) + 212)
                                                                                                - ss0.m_oldInvRotInertia.hesse_val)
                                                                                        * (float)(*(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1]) + 212)
                                                                                                - ss0.m_oldInvRotInertia.hesse_val)))
                                                                        + (float)((float)(*(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1]) + 216)
                                                                                        - *(float *)&ss1.m_core)
                                                                                * (float)(*(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1]) + 216)
                                                                                        - *(float *)&ss1.m_core)))
                                                                * *(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1]) + 28))
      && (float)(m_angular_strength * m_angular_strength) > (float)((float)((float)((float)(*(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1]) + 16)
                                                                                          * (float)(*(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1]) + 192)
                                                                                                  - ss1.m_old_lin_vel.y))
                                                                                  * (float)(*(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1]) + 16)
                                                                                          * (float)(*(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1]) + 192)
                                                                                                  - ss1.m_old_lin_vel.y)))
                                                                          + (float)((float)(*(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1]) + 20)
                                                                                          * (float)(*(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1]) + 196)
                                                                                                  - ss1.m_old_lin_vel.z))
                                                                                  * (float)(*(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1]) + 20)
                                                                                          * (float)(*(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1]) + 196)
                                                                                                  - ss1.m_old_lin_vel.z))))
                                                                  + (float)((float)(*(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1])
                                                                                             + 24)
                                                                                  * (float)(*(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1]) + 200)
                                                                                          - ss1.m_old_lin_vel.w))
                                                                          * (float)(*(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1])
                                                                                             + 24)
                                                                                  * (float)(*(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1]) + 200)
                                                                                          - ss1.m_old_lin_vel.w)))) )
    {
      v14 = false;
    }
  }
  this->m_is_broken = v14;
  hk_Breakable_Constraint::FireEventIfBroken(this);
  if ( !this->m_constraint_system->m_is_active )
  {
    if ( (*(_WORD *)LODWORD(v10) & 0x12) == 0 )
    {
      *(float *)(LODWORD(v10) + 208) = v21[1];
      *(float *)(LODWORD(v10) + 212) = v21[2];
      *(_DWORD *)(LODWORD(v10) + 216) = ss0.m_core;
      *(float *)(LODWORD(v10) + 192) = ss0.m_old_lin_vel.y;
      *(float *)(LODWORD(v10) + 196) = ss0.m_old_lin_vel.z;
      *(float *)(LODWORD(v10) + 200) = ss0.m_old_lin_vel.w;
    }
    v15 = ss0.m_oldInvRotInertia.k[1];
    if ( (*(_WORD *)LODWORD(ss0.m_oldInvRotInertia.k[1]) & 0x12) == 0 )
    {
      *(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1]) + 208) = ss0.m_oldInvRotInertia.k[2];
      *(float *)(LODWORD(v15) + 212) = ss0.m_oldInvRotInertia.hesse_val;
      *(_DWORD *)(LODWORD(v15) + 216) = ss1.m_core;
      *(float *)(LODWORD(v15) + 192) = ss1.m_old_lin_vel.y;
      *(float *)(LODWORD(v15) + 196) = ss1.m_old_lin_vel.z;
      *(float *)(LODWORD(v15) + 200) = ss1.m_old_lin_vel.w;
    }
  }
  v16 = this->m_real_constraint->get_vmq_storage_size(this: this->m_real_constraint);
  if ( ss1.m_old_ang_vel.y != 1.0 && ss1.m_old_ang_vel.y > 0.0 )
  {
    v17 = *(_DWORD *)(LODWORD(ss1.m_old_ang_vel.z) + 148);
    *(float *)(v17 + 16) = ss1.m_massScale;
    *(_DWORD *)(v17 + 20) = ss1.m_pBody;
    *(_DWORD *)(v17 + 24) = *((_DWORD *)&ss1.m_pBody + 1);
    *(float *)(v17 + 28) = ss1.m_oldRotInertia.k[0];
    *(float *)(v17 + 48) = ss1.m_oldRotInertia.k[1];
    *(float *)(v17 + 52) = ss1.m_oldRotInertia.k[2];
    *(float *)(v17 + 56) = ss1.m_oldRotInertia.hesse_val;
    *(float *)(v17 + 60) = ss1.m_oldInvRotInertia.k[0];
  }
  if ( ss0.m_old_ang_vel.y != 1.0 && ss0.m_old_ang_vel.y > 0.0 )
  {
    v18 = *(_DWORD *)(LODWORD(ss0.m_old_ang_vel.z) + 148);
    *(float *)(v18 + 16) = ss0.m_massScale;
    *(_DWORD *)(v18 + 20) = ss0.m_pBody;
    *(_DWORD *)(v18 + 24) = *((_DWORD *)&ss0.m_pBody + 1);
    *(float *)(v18 + 28) = ss0.m_oldRotInertia.k[0];
    *(float *)(v18 + 48) = ss0.m_oldRotInertia.k[1];
    *(float *)(v18 + 52) = ss0.m_oldRotInertia.k[2];
    *(float *)(v18 + 56) = ss0.m_oldRotInertia.hesse_val;
    *(float *)(v18 + 60) = ss0.m_oldInvRotInertia.k[0];
  }
  return v16;
}

//------------------------------------------------------------------------------
// Address: 0x10035B50
// Name: public: virtual void hk_Breakable_Constraint::step_constraint(class hk_PSI_Info __near &,void __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge hk_Breakable_Constraint::step_constraint(
        hk_Breakable_Constraint *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        hk_PSI_Info *pi,
        void *mem,
        float tau_factor,
        float damp_factor)
{
  float v9; // edi
  float m_linear_strength; // xmm3_4
  float m_angular_strength; // xmm4_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  bool v16; // al
  float v17; // eax
  int v18; // eax
  int v19; // eax
  float v21[3]; // [esp+18h] [ebp-ACh] BYREF
  BreakableConstraintHelper ss0; // [esp+24h] [ebp-A0h] BYREF
  BreakableConstraintHelper ss1; // [esp+74h] [ebp-50h]
  float retaddr; // [esp+C4h] [ebp+0h]

  ss1.m_oldInvRotInertia.k[1] = a2;
  ss1.m_oldInvRotInertia.k[2] = retaddr;
  BreakableConstraintHelper::BreakableConstraintHelper(
    this: (BreakableConstraintHelper *)v21,
    b: this->m_entities[0],
    massScale: this->m_bodyMassScale[0]);
  BreakableConstraintHelper::BreakableConstraintHelper(
    this: (BreakableConstraintHelper *)&ss0.m_oldInvRotInertia.k[1],
    b: this->m_entities[1],
    massScale: this->m_bodyMassScale[1]);
  ((void (__thiscall *)(hk_Constraint *, hk_PSI_Info *, void *, _DWORD, _DWORD, int, int))this->m_real_constraint->step_constraint)(
    a1: this->m_real_constraint,
    a2: pi,
    a3: mem,
    a4: LODWORD(tau_factor),
    a5: LODWORD(damp_factor),
    a6: a3,
    a7: a4);
  v9 = v21[0];
  m_linear_strength = this->m_linear_strength;
  m_angular_strength = this->m_angular_strength;
  v16 = true;
  if ( (float)(m_linear_strength * m_linear_strength) > (float)((float)((float)((float)((float)(*(float *)(LODWORD(v21[0]) + 212)
                                                                                              - v21[2])
                                                                                      * (float)(*(float *)(LODWORD(v21[0]) + 212)
                                                                                              - v21[2]))
                                                                              + (float)((float)(*(float *)(LODWORD(v21[0]) + 208)
                                                                                              - v21[1])
                                                                                      * (float)(*(float *)(LODWORD(v21[0]) + 208)
                                                                                              - v21[1])))
                                                                      + (float)((float)(*(float *)(LODWORD(v21[0]) + 216)
                                                                                      - *(float *)&ss0.m_core)
                                                                              * (float)(*(float *)(LODWORD(v21[0]) + 216)
                                                                                      - *(float *)&ss0.m_core)))
                                                              * *(float *)(LODWORD(v21[0]) + 28)) )
  {
    v12 = *(float *)(LODWORD(v21[0]) + 16) * (float)(*(float *)(LODWORD(v21[0]) + 192) - ss0.m_old_lin_vel.y);
    v13 = *(float *)(LODWORD(v21[0]) + 20) * (float)(*(float *)(LODWORD(v21[0]) + 196) - ss0.m_old_lin_vel.z);
    if ( (float)(m_angular_strength * m_angular_strength) > (float)((float)((float)(v13 * v13) + (float)(v12 * v12))
                                                                  + (float)((float)(*(float *)(LODWORD(v21[0]) + 24)
                                                                                  * (float)(*(float *)(LODWORD(v21[0]) + 200)
                                                                                          - ss0.m_old_lin_vel.w))
                                                                          * (float)(*(float *)(LODWORD(v21[0]) + 24)
                                                                                  * (float)(*(float *)(LODWORD(v21[0]) + 200)
                                                                                          - ss0.m_old_lin_vel.w))))
      && (float)(m_linear_strength * m_linear_strength) > (float)((float)((float)((float)((float)(*(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1]) + 212)
                                                                                                - ss0.m_oldInvRotInertia.hesse_val)
                                                                                        * (float)(*(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1]) + 212)
                                                                                                - ss0.m_oldInvRotInertia.hesse_val))
                                                                                + (float)((float)(*(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1]) + 208)
                                                                                                - ss0.m_oldInvRotInertia.k[2])
                                                                                        * (float)(*(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1]) + 208)
                                                                                                - ss0.m_oldInvRotInertia.k[2])))
                                                                        + (float)((float)(*(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1]) + 216)
                                                                                        - *(float *)&ss1.m_core)
                                                                                * (float)(*(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1]) + 216)
                                                                                        - *(float *)&ss1.m_core)))
                                                                * *(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1]) + 28)) )
    {
      v14 = (float)(*(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1]) + 192) - ss1.m_old_lin_vel.y)
          * *(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1]) + 16);
      v15 = *(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1]) + 20)
          * (float)(*(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1]) + 196) - ss1.m_old_lin_vel.z);
      if ( (float)(m_angular_strength * m_angular_strength) > (float)((float)((float)(v14 * v14) + (float)(v15 * v15))
                                                                    + (float)((float)(*(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1])
                                                                                               + 24)
                                                                                    * (float)(*(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1]) + 200)
                                                                                            - ss1.m_old_lin_vel.w))
                                                                            * (float)(*(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1])
                                                                                               + 24)
                                                                                    * (float)(*(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1]) + 200)
                                                                                            - ss1.m_old_lin_vel.w)))) )
        v16 = false;
    }
  }
  this->m_is_broken = v16;
  hk_Breakable_Constraint::FireEventIfBroken(this);
  if ( !this->m_constraint_system->m_is_active )
  {
    if ( (*(_WORD *)LODWORD(v9) & 0x12) == 0 )
    {
      *(float *)(LODWORD(v9) + 208) = v21[1];
      *(float *)(LODWORD(v9) + 212) = v21[2];
      *(_DWORD *)(LODWORD(v9) + 216) = ss0.m_core;
      *(float *)(LODWORD(v9) + 192) = ss0.m_old_lin_vel.y;
      *(float *)(LODWORD(v9) + 196) = ss0.m_old_lin_vel.z;
      *(float *)(LODWORD(v9) + 200) = ss0.m_old_lin_vel.w;
    }
    v17 = ss0.m_oldInvRotInertia.k[1];
    if ( (*(_WORD *)LODWORD(ss0.m_oldInvRotInertia.k[1]) & 0x12) == 0 )
    {
      *(float *)(LODWORD(ss0.m_oldInvRotInertia.k[1]) + 208) = ss0.m_oldInvRotInertia.k[2];
      *(float *)(LODWORD(v17) + 212) = ss0.m_oldInvRotInertia.hesse_val;
      *(_DWORD *)(LODWORD(v17) + 216) = ss1.m_core;
      *(float *)(LODWORD(v17) + 192) = ss1.m_old_lin_vel.y;
      *(float *)(LODWORD(v17) + 196) = ss1.m_old_lin_vel.z;
      *(float *)(LODWORD(v17) + 200) = ss1.m_old_lin_vel.w;
    }
  }
  if ( ss1.m_old_ang_vel.y != 1.0 && ss1.m_old_ang_vel.y > 0.0 )
  {
    v18 = *(_DWORD *)(LODWORD(ss1.m_old_ang_vel.z) + 148);
    *(float *)(v18 + 16) = ss1.m_massScale;
    *(_DWORD *)(v18 + 20) = ss1.m_pBody;
    *(_DWORD *)(v18 + 24) = *((_DWORD *)&ss1.m_pBody + 1);
    *(float *)(v18 + 28) = ss1.m_oldRotInertia.k[0];
    *(float *)(v18 + 48) = ss1.m_oldRotInertia.k[1];
    *(float *)(v18 + 52) = ss1.m_oldRotInertia.k[2];
    *(float *)(v18 + 56) = ss1.m_oldRotInertia.hesse_val;
    *(float *)(v18 + 60) = ss1.m_oldInvRotInertia.k[0];
  }
  if ( ss0.m_old_ang_vel.y != 1.0 && ss0.m_old_ang_vel.y > 0.0 )
  {
    v19 = *(_DWORD *)(LODWORD(ss0.m_old_ang_vel.z) + 148);
    *(float *)(v19 + 16) = ss0.m_massScale;
    *(_DWORD *)(v19 + 20) = ss0.m_pBody;
    *(_DWORD *)(v19 + 24) = *((_DWORD *)&ss0.m_pBody + 1);
    *(float *)(v19 + 28) = ss0.m_oldRotInertia.k[0];
    *(float *)(v19 + 48) = ss0.m_oldRotInertia.k[1];
    *(float *)(v19 + 52) = ss0.m_oldRotInertia.k[2];
    *(float *)(v19 + 56) = ss0.m_oldRotInertia.hesse_val;
    *(float *)(v19 + 60) = ss0.m_oldInvRotInertia.k[0];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035F20
// Name: public: virtual void hk_Rigid_Body_Binary_EF::get_effected_entities(class hk_Array<class hk_Rigid_Body __near *> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Rigid_Body_Binary_EF::get_effected_entities(
        hk_Rigid_Body_Binary_EF *this,
        hk_Array<hk_Rigid_Body *> *ent_out)
{
  hk_Rigid_Body *v3; // ebx
  hk_Rigid_Body *v4; // edi

  v3 = this->m_entities[0];
  if ( ent_out->m_n_elems >= ent_out->m_memsize )
    hk_Array_Base::grow_mem(this: ent_out, size: 4);
  *(_DWORD *)&ent_out->m_elems[4 * ent_out->m_n_elems++] = v3;
  v4 = this->m_entities[1];
  if ( ent_out->m_n_elems >= ent_out->m_memsize )
    hk_Array_Base::grow_mem(this: ent_out, size: 4);
  *(_DWORD *)&ent_out->m_elems[4 * ent_out->m_n_elems++] = v4;
}
