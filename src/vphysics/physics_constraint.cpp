// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vphysics/physics_constraint.cpp
// Functions: 78
// ============================================================

#include "vphysics\physics_constraint.h"

//------------------------------------------------------------------------------
// Address: 0x1000A4D0
// Name: public: virtual void CPhysicsConstraintGroup::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsConstraintGroup::Activate(CPhysicsConstraintGroup *this)
{
  hk_Local_Constraint_System *m_pLCS; // ecx

  m_pLCS = this->m_pLCS;
  if ( m_pLCS != nullptr )
    hk_Local_Constraint_System::activate(this: m_pLCS);
}

//------------------------------------------------------------------------------
// Address: 0x1000A4E0
// Name: public: virtual bool CPhysicsConstraintGroup::IsInErrorState(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPhysicsConstraintGroup::IsInErrorState(CPhysicsConstraintGroup *this)
{
  hk_Local_Constraint_System *m_pLCS; // eax

  m_pLCS = this->m_pLCS;
  return m_pLCS != nullptr && m_pLCS->m_errorCount >= m_pLCS->m_minErrorTicks;
}

//------------------------------------------------------------------------------
// Address: 0x1000A500
// Name: public: virtual void CPhysicsConstraintGroup::ClearErrorState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsConstraintGroup::ClearErrorState(CPhysicsConstraintGroup *this)
{
  hk_Local_Constraint_System *m_pLCS; // eax

  m_pLCS = this->m_pLCS;
  if ( m_pLCS != nullptr )
    m_pLCS->m_errorCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000A550
// Name: public: class hk_Constraint __near * CPhysicsConstraint::GetRealConstraint(void)const
// Source: json
//------------------------------------------------------------------------------
hk_Constraint *__thiscall CPhysicsConstraint::GetRealConstraint(CPhysicsConstraint *this)
{
  hk_Breakable_Constraint *m_HkConstraint; // ecx
  hk_Breakable_Constraint_BP pOutBP; // [esp+0h] [ebp-1Ch] BYREF

  if ( this->m_isBreakable == 0 )
    return this->m_HkConstraint;
  m_HkConstraint = (hk_Breakable_Constraint *)this->m_HkConstraint;
  memset(&pOutBP, 0, 12);
  pOutBP.m_bodyMassScale[0] = 1.0;
  pOutBP.m_bodyMassScale[1] = 1.0;
  hk_Breakable_Constraint::write_to_blueprint(this: m_HkConstraint, &pOutBP);
  return pOutBP.m_real_constraint;
}

//------------------------------------------------------------------------------
// Address: 0x1000A5A0
// Name: public: virtual void CPhysicsConstraint::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsConstraint::Activate(CPhysicsConstraint *this)
{
  hk_Local_Constraint_System *m_HkLCS; // ecx

  m_HkLCS = this->m_HkLCS;
  if ( m_HkLCS != nullptr )
    hk_Local_Constraint_System::activate(this: m_HkLCS);
}

//------------------------------------------------------------------------------
// Address: 0x1000A5B0
// Name: public: virtual void CPhysicsConstraint::Deactivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsConstraint::Deactivate(CPhysicsConstraint *this)
{
  hk_Local_Constraint_System *m_HkLCS; // ecx

  m_HkLCS = this->m_HkLCS;
  if ( m_HkLCS != nullptr )
    hk_Local_Constraint_System::deactivate(this: m_HkLCS);
}

//------------------------------------------------------------------------------
// Address: 0x1000A5C0
// Name: void SeedRandomGenerators(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandomGenerators()
{
  ivp_srand(seed: 1);
  hk_Math::srand01(seedVal: 0x219u);
  qh_srand(seed: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1000A5E0
// Name: class IPhysicsConstraint __near * GetClientDataForHkConstraint(class hk_Breakable_Constraint __near *)
// Source: json
//------------------------------------------------------------------------------
IPhysicsConstraint *__cdecl GetClientDataForHkConstraint(hk_Breakable_Constraint *pHkConstraint)
{
  return (IPhysicsConstraint *)pHkConstraint->m_client_data;
}

//------------------------------------------------------------------------------
// Address: 0x1000A5F0
// Name: public: virtual void CPhysicsConstraintGroup::GetErrorParams(struct constraint_groupparams_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsConstraintGroup::GetErrorParams(
        CPhysicsConstraintGroup *this,
        constraint_groupparams_t *pParams)
{
  hk_Local_Constraint_System *m_pLCS; // ecx
  float v3; // ecx
  hk_Local_Constraint_System_BP v4; // [esp+0h] [ebp-28h] BYREF

  m_pLCS = this->m_pLCS;
  if ( m_pLCS != nullptr )
  {
    v4.m_active = true;
    v4.m_damp = 1.0;
    v4.m_tau = 1.0;
    *(_QWORD *)&v4.m_n_iterations = 0x100000000LL;
    v4.m_errorTolerance = 0.029999999;
    hk_Local_Constraint_System::write_to_blueprint(this: m_pLCS, bp: &v4);
    v3 = g_PhysicsUnits.unitScaleMetersInv * v4.m_errorTolerance;
    *(_QWORD *)&pParams->additionalIterations = *(_QWORD *)&v4.m_n_iterations;
    pParams->errorTolerance = v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A670
// Name: public: virtual void CPhysicsConstraintGroup::SetErrorParams(struct constraint_groupparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsConstraintGroup::SetErrorParams(
        CPhysicsConstraintGroup *this,
        const constraint_groupparams_t *params)
{
  if ( this->m_pLCS != nullptr )
  {
    this->m_pLCS->m_minErrorTicks = params->minErrorTicks;
    this->m_pLCS->m_errorTolerance = params->errorTolerance * g_PhysicsUnits.unitScaleMeters;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A6A0
// Name: public: virtual void CPhysicsConstraintGroup::SolvePenetration(class IPhysicsObject __near *,class IPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsConstraintGroup::SolvePenetration(
        CPhysicsConstraintGroup *this,
        IPhysicsObject *pObj0,
        IPhysicsObject *pObj1)
{
  hk_Local_Constraint_System *m_pLCS; // ecx

  m_pLCS = this->m_pLCS;
  if ( m_pLCS != nullptr && pObj0 != nullptr && pObj1 != nullptr )
    hk_Local_Constraint_System::solve_penetration(
      this: m_pLCS,
      pivp0: (IVP_Real_Object *)pObj0[2].__vftable,
      pivp1: (IVP_Real_Object *)pObj1[2].__vftable);
}

//------------------------------------------------------------------------------
// Address: 0x1000A6D0
// Name: public: CPhysicsConstraintGroup::CPhysicsConstraintGroup(class IVP_Environment __near *,struct constraint_groupparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CPhysicsConstraintGroup *__userpurge CPhysicsConstraintGroup::CPhysicsConstraintGroup@<eax>(
        CPhysicsConstraintGroup *this@<ecx>,
        int a2@<esi>,
        hk_Environment *pEnvironment,
        const constraint_groupparams_t *group)
{
  int additionalIterations; // ecx
  int minErrorTicks; // edx
  float v7; // xmm0_4
  int v8; // eax
  hk_Local_Constraint_System *v9; // ecx
  hk_Local_Constraint_System *v10; // eax
  hk_Local_Constraint_System_BP cs_bp; // [esp+0h] [ebp-18h] BYREF

  this->__vftable = (CPhysicsConstraintGroup_vtbl *)&CPhysicsConstraintGroup::`vftable';
  additionalIterations = group->additionalIterations;
  minErrorTicks = group->minErrorTicks;
  cs_bp.m_damp = 1.0;
  cs_bp.m_tau = 1.0;
  v7 = group->errorTolerance * g_PhysicsUnits.unitScaleMeters;
  cs_bp.m_active = true;
  cs_bp.m_n_iterations = additionalIterations;
  cs_bp.m_minErrorTicks = minErrorTicks;
  cs_bp.m_errorTolerance = v7;
  v8 = ((int (__thiscall *)(IMemAlloc *, int, int))_g_pMemAlloc->Alloc_2)(a1: _g_pMemAlloc, a2: 131, a3: a2);
  if ( v8 != 0 )
  {
    v9 = (hk_Local_Constraint_System *)((v8 + 19) & 0xFFFFFFF0);
    *((_DWORD *)&v9[-1].m_client_data + 3) = v8;
    v10 = hk_Local_Constraint_System::hk_Local_Constraint_System(this: v9, env: pEnvironment, bp: &cs_bp);
    this->m_pLCS = v10;
    v10->m_client_data = this;
  }
  else
  {
    this->m_pLCS = nullptr;
    MEMORY[0x60] = this;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000A770
// Name: public: class hk_Constraint __near * CPhysicsConstraint::CreateBreakableConstraint(class hk_Constraint __near *,class hk_Local_Constraint_System __near *,struct constraint_breakableparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
hk_Breakable_Constraint *__thiscall CPhysicsConstraint::CreateBreakableConstraint(
        CPhysicsConstraint *this,
        hk_Constraint *pRealConstraint,
        hk_Local_Constraint_System *pLcs,
        const constraint_breakableparams_t *constraint)
{
  float v4; // xmm0_4
  float torqueLimit; // xmm0_4
  void *v6; // eax
  hk_Breakable_Constraint *v7; // ecx
  hk_Breakable_Constraint_BP v9; // [esp+0h] [ebp-1Ch] BYREF

  this->m_isBreakable = 1;
  v4 = constraint->forceLimit * g_PhysicsUnits.unitScaleMeters;
  v9.m_real_constraint = pRealConstraint;
  if ( v4 <= 0.0 )
    v9.m_linear_strength = 1.0e12;
  else
    v9.m_linear_strength = v4;
  torqueLimit = constraint->torqueLimit;
  if ( torqueLimit <= 0.0 )
    v9.m_angular_strength = 1.0e12;
  else
    v9.m_angular_strength = torqueLimit * 0.017453292;
  if ( constraint->bodyMassScale[0] <= 0.0 )
    v9.m_bodyMassScale[0] = 1.0;
  else
    v9.m_bodyMassScale[0] = constraint->bodyMassScale[0];
  if ( constraint->bodyMassScale[1] <= 0.0 )
    v9.m_bodyMassScale[1] = 1.0;
  else
    v9.m_bodyMassScale[1] = constraint->bodyMassScale[1];
  v6 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 67);
  if ( v6 == nullptr )
    return nullptr;
  v7 = (hk_Breakable_Constraint *)(((unsigned int)v6 + 19) & 0xFFFFFFF0);
  *(_DWORD *)&v7[-1].m_is_broken = v6;
  return hk_Breakable_Constraint::hk_Breakable_Constraint(this: v7, constraint_system: pLcs, bp: &v9);
}

//------------------------------------------------------------------------------
// Address: 0x1000A840
// Name: public: CPhysicsConstraint::CPhysicsConstraint(class CPhysicsObject __near *,class CPhysicsObject __near *)
// Source: json
//------------------------------------------------------------------------------
CPhysicsConstraint *__thiscall CPhysicsConstraint::CPhysicsConstraint(
        CPhysicsConstraint *this,
        CPhysicsObject *pReferenceObject,
        CPhysicsObject *pAttachedObject)
{
  IVP_Listener_Object *v4; // edi
  CPhysicsObject *m_pObjAttached; // eax

  this->IVP_Listener_Object::__vftable = (IVP_Listener_Object_vtbl *)&IVP_Listener_Object::`vftable';
  v4 = &this->IVP_Listener_Object;
  *(_DWORD *)&this->m_constraintType = 0;
  this->IPhysicsConstraint::__vftable = (CPhysicsConstraint_vtbl *)&CPhysicsConstraint::`vftable'{for `IPhysicsConstraint'};
  this->IVP_Listener_Object::__vftable = (IVP_Listener_Object_vtbl *)&CPhysicsConstraint::`vftable'{for `IVP_Listener_Object'};
  this->m_pGameData = nullptr;
  this->m_HkConstraint = nullptr;
  this->m_HkLCS = nullptr;
  if ( pReferenceObject != nullptr && pAttachedObject != nullptr )
  {
    this->m_pObjReference = pReferenceObject;
    this->m_pObjAttached = pAttachedObject;
    if ( (pReferenceObject->m_callbacks & 0x200) == 0 )
      IVP_Real_Object::add_listener_object(this: pReferenceObject->m_pObject, listener: v4);
    m_pObjAttached = this->m_pObjAttached;
    if ( (m_pObjAttached->m_callbacks & 0x200) == 0 )
    {
      IVP_Real_Object::add_listener_object(this: m_pObjAttached->m_pObject, listener: v4);
      return this;
    }
  }
  else
  {
    this->m_pObjReference = nullptr;
    this->m_pObjAttached = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000A8D0
// Name: public: virtual void CPhysicsConstraint::SetGameData(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsConstraint::SetGameData(CPhysicsConstraint *this, void *gameData)
{
  this->m_pGameData = gameData;
}

//------------------------------------------------------------------------------
// Address: 0x1000A8F0
// Name: ConvertRagdollToHinge
// Source: json
//------------------------------------------------------------------------------
char __usercall ConvertRagdollToHinge@<al>(
        constraint_limitedhingeparams_t *pHingeOut@<esi>,
        const constraint_ragdollparams_t *ragdoll@<edi>,
        IPhysicsObject *pReferenceObject)
{
  int v3; // ecx
  bool v4; // zf
  int v6; // edx
  int v7; // eax
  float v8; // xmm0_4
  matrix3x4_t refToWorld; // [esp+0h] [ebp-70h] BYREF
  matrix3x4_t constraintToWorld; // [esp+30h] [ebp-40h] BYREF
  Vector perpCS; // [esp+60h] [ebp-10h] BYREF
  int dofIndex; // [esp+6Ch] [ebp-4h]

  v3 = 0;
  v4 = ragdoll->axes[0].minRotation == ragdoll->axes[0].maxRotation;
  dofIndex = 0;
  if ( !v4 )
  {
    dofIndex = 0;
    v3 = 1;
  }
  if ( ragdoll->axes[1].minRotation != ragdoll->axes[1].maxRotation )
  {
    dofIndex = 1;
    ++v3;
  }
  if ( ragdoll->axes[2].minRotation != ragdoll->axes[2].maxRotation )
  {
    dofIndex = 2;
    ++v3;
  }
  if ( v3 != 1 )
    return 0;
  pHingeOut->worldPosition.x = 0.0;
  pHingeOut->worldPosition.y = 0.0;
  pHingeOut->worldPosition.z = 0.0;
  pHingeOut->worldAxisDirection.x = 0.0;
  pHingeOut->worldAxisDirection.y = 0.0;
  pHingeOut->worldAxisDirection.z = 0.0;
  pHingeOut->hingeAxis.minRotation = 0.0;
  pHingeOut->hingeAxis.maxRotation = 0.0;
  pHingeOut->hingeAxis.angularVelocity = 0.0;
  pHingeOut->hingeAxis.torque = 0.0;
  pHingeOut->constraint.forceLimit = 0.0;
  pHingeOut->constraint.torqueLimit = 0.0;
  pHingeOut->constraint.strength = 1.0;
  pHingeOut->constraint.bodyMassScale[0] = 1.0;
  pHingeOut->constraint.bodyMassScale[1] = 1.0;
  pHingeOut->constraint.isActive = true;
  pHingeOut->referencePerpAxisDirection.x = 0.0;
  pHingeOut->referencePerpAxisDirection.y = 0.0;
  pHingeOut->referencePerpAxisDirection.z = 0.0;
  pHingeOut->attachedPerpAxisDirection.x = 0.0;
  pHingeOut->attachedPerpAxisDirection.y = 0.0;
  pHingeOut->attachedPerpAxisDirection.z = 0.0;
  pHingeOut->constraint = ragdoll->constraint;
  pReferenceObject->GetPositionMatrix(this: pReferenceObject, a2: &refToWorld);
  ConcatTransforms(in1: &refToWorld, in2: &ragdoll->constraintToReference, out: &constraintToWorld);
  pHingeOut->constraint.strength = 1.0;
  MatrixGetColumn(in: &constraintToWorld, column: 3, out: &pHingeOut->worldPosition);
  MatrixGetColumn(in: &constraintToWorld, column: dofIndex, out: &pHingeOut->worldAxisDirection);
  v6 = (dofIndex + 1) % 3;
  pHingeOut->referencePerpAxisDirection.x = 0.0;
  pHingeOut->referencePerpAxisDirection.y = 0.0;
  pHingeOut->referencePerpAxisDirection.z = 0.0;
  *((_DWORD *)&pHingeOut->referencePerpAxisDirection.x + v6) = 1065353216;
  VectorIRotate(in1: &pHingeOut->referencePerpAxisDirection.x, in2: &ragdoll->constraintToReference, out: &perpCS.x);
  VectorRotate(in1: &perpCS.x, in2: &ragdoll->constraintToAttached, out: &pHingeOut->attachedPerpAxisDirection.x);
  v7 = 2 * (dofIndex + 8);
  *(_QWORD *)&pHingeOut->hingeAxis.minRotation = *(_QWORD *)&ragdoll->axes[dofIndex].minRotation;
  *(_QWORD *)&pHingeOut->hingeAxis.angularVelocity = *((_QWORD *)&ragdoll->constraint.torqueLimit + v7);
  pHingeOut->hingeAxis.torque = ((double (__thiscall *)(IPhysicsObject *))pReferenceObject->GetMass)(a1: pReferenceObject)
                              * pHingeOut->hingeAxis.torque
                              * 57.29578;
  if ( !ragdoll->useClockwiseRotations )
  {
    v8 = -pHingeOut->hingeAxis.minRotation;
    pHingeOut->hingeAxis.minRotation = -pHingeOut->hingeAxis.maxRotation;
    pHingeOut->hingeAxis.maxRotation = v8;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000AB00
// Name: public: void CPhysicsConstraint::InitBallsocket(class IVP_Environment __near *,class CPhysicsConstraintGroup __near *,struct constraint_ballsocketparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CPhysicsConstraint::InitBallsocket(
        CPhysicsConstraint *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        hk_Environment *pEnvironment,
        CPhysicsConstraintGroup *constraint_group,
        const constraint_ballsocketparams_t *ballsocket)
{
  float forceLimit; // xmm0_4
  float torqueLimit; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float z; // xmm1_4
  float x; // xmm2_4
  float v15; // xmm3_4
  float strength; // xmm0_4
  hk_Local_Constraint_System *m_pLCS; // edi
  void *v18; // eax
  hk_Local_Constraint_System *v19; // ecx
  int v20; // eax
  hk_Ball_Socket_Constraint *v21; // ecx
  hk_Ball_Socket_Constraint *v22; // eax
  hk_Breakable_Constraint *BreakableConstraint; // eax
  int v24; // eax
  hk_Ball_Socket_Constraint *v25; // ecx
  hk_Local_Constraint_System *m_HkLCS; // ecx
  hk_Ball_Socket_BP builder; // [esp+0h] [ebp-4Ch] BYREF
  hk_Local_Constraint_System_BP v30; // [esp+30h] [ebp-1Ch] BYREF
  bool breakable; // [esp+4Bh] [ebp-1h]

  this->m_constraintType = 4;
  forceLimit = ballsocket->constraint.forceLimit;
  breakable = forceLimit != 0.0 && forceLimit < 1.0e12
           || (torqueLimit = ballsocket->constraint.torqueLimit) != 0.0 && torqueLimit < 1.0e12
           || (v9 = ballsocket->constraint.bodyMassScale[0]) != 1.0 && v9 != 0.0
           || (v10 = ballsocket->constraint.bodyMassScale[1]) != 1.0 && v10 != 0.0;
  v11 = ballsocket->constraintPosition[0].x * g_PhysicsUnits.unitScaleMeters;
  v12 = ballsocket->constraintPosition[0].y * g_PhysicsUnits.unitScaleMeters;
  LODWORD(builder.m_translation_os_ks[0].y) = COERCE_UNSIGNED_INT(ballsocket->constraintPosition[0].z * g_PhysicsUnits.unitScaleMeters)
                                            ^ _mask__NegFloat_;
  z = ballsocket->constraintPosition[1].z;
  builder.m_translation_os_ks[0].x = v11;
  x = ballsocket->constraintPosition[1].x;
  builder.m_translation_os_ks[0].z = v12;
  v15 = ballsocket->constraintPosition[1].y * g_PhysicsUnits.unitScaleMeters;
  strength = ballsocket->constraint.strength;
  builder.m_tau = 1.0;
  builder.m_translation_os_ks[1].x = x * g_PhysicsUnits.unitScaleMeters;
  LODWORD(builder.m_translation_os_ks[1].y) = COERCE_UNSIGNED_INT(z * g_PhysicsUnits.unitScaleMeters) ^ _mask__NegFloat_;
  builder.m_translation_os_ks[1].z = v15;
  builder.m_strength = strength;
  if ( constraint_group != nullptr )
    m_pLCS = constraint_group->m_pLCS;
  else
    m_pLCS = nullptr;
  if ( m_pLCS == nullptr )
  {
    v30.m_damp = 1.0;
    v30.m_tau = 1.0;
    v30.m_active = true;
    v30.m_n_iterations = 0;
    v30.m_errorTolerance = 0.029999999;
    v30.m_minErrorTicks = 1;
    v18 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 131);
    if ( v18 != nullptr )
    {
      v19 = (hk_Local_Constraint_System *)(((unsigned int)v18 + 19) & 0xFFFFFFF0);
      *((_DWORD *)&v19[-1].m_client_data + 3) = v18;
      m_pLCS = hk_Local_Constraint_System::hk_Local_Constraint_System(this: v19, env: pEnvironment, bp: &v30);
    }
    else
    {
      m_pLCS = nullptr;
    }
    this->m_HkLCS = m_pLCS;
  }
  if ( breakable )
  {
    v20 = ((int (__thiscall *)(IMemAlloc *, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, unsigned int, unsigned int, _DWORD, _DWORD, int, int, _DWORD))_g_pMemAlloc->Alloc_2)(
            a1: _g_pMemAlloc,
            a2: 83,
            a3: a2,
            a4: a3,
            a5: LODWORD(builder.m_tau),
            a6: LODWORD(builder.m_strength),
            a7: LODWORD(builder.m_translation_os_ks[0].x),
            a8: LODWORD(builder.m_translation_os_ks[0].y),
            a9: LODWORD(builder.m_translation_os_ks[0].z),
            a10: LODWORD(builder.m_translation_os_ks[0].w),
            a11: LODWORD(builder.m_translation_os_ks[1].x),
            a12: LODWORD(builder.m_translation_os_ks[1].y),
            a13: LODWORD(builder.m_translation_os_ks[1].z),
            a14: LODWORD(builder.m_translation_os_ks[1].w),
            a15: builder.m_bodies[0],
            a16: builder.m_bodies[1],
            a17: LODWORD(v30.m_damp),
            a18: LODWORD(v30.m_tau),
            a19: v30.m_n_iterations,
            a20: v30.m_minErrorTicks,
            a21: LODWORD(v30.m_errorTolerance));
    if ( v20 != 0 )
    {
      v21 = (hk_Ball_Socket_Constraint *)((v20 + 19) & 0xFFFFFFF0);
      LODWORD(v21[-1].m_strength) = v20;
      v22 = hk_Ball_Socket_Constraint::hk_Ball_Socket_Constraint(
              this: v21,
              env: pEnvironment,
              bp: &builder,
              a: (hk_Rigid_Body *)this->m_pObjReference->m_pObject,
              b: (hk_Rigid_Body *)this->m_pObjAttached->m_pObject);
    }
    else
    {
      v22 = nullptr;
    }
    BreakableConstraint = CPhysicsConstraint::CreateBreakableConstraint(
                            this,
                            pRealConstraint: v22,
                            pLcs: m_pLCS,
                            constraint: &ballsocket->constraint);
  }
  else
  {
    v24 = ((int (__thiscall *)(IMemAlloc *, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, unsigned int, unsigned int, _DWORD, _DWORD, int, int, _DWORD))_g_pMemAlloc->Alloc_2)(
            a1: _g_pMemAlloc,
            a2: 83,
            a3: a2,
            a4: a3,
            a5: LODWORD(builder.m_tau),
            a6: LODWORD(builder.m_strength),
            a7: LODWORD(builder.m_translation_os_ks[0].x),
            a8: LODWORD(builder.m_translation_os_ks[0].y),
            a9: LODWORD(builder.m_translation_os_ks[0].z),
            a10: LODWORD(builder.m_translation_os_ks[0].w),
            a11: LODWORD(builder.m_translation_os_ks[1].x),
            a12: LODWORD(builder.m_translation_os_ks[1].y),
            a13: LODWORD(builder.m_translation_os_ks[1].z),
            a14: LODWORD(builder.m_translation_os_ks[1].w),
            a15: builder.m_bodies[0],
            a16: builder.m_bodies[1],
            a17: LODWORD(v30.m_damp),
            a18: LODWORD(v30.m_tau),
            a19: v30.m_n_iterations,
            a20: v30.m_minErrorTicks,
            a21: LODWORD(v30.m_errorTolerance));
    if ( v24 != 0 )
    {
      v25 = (hk_Ball_Socket_Constraint *)((v24 + 19) & 0xFFFFFFF0);
      LODWORD(v25[-1].m_strength) = v24;
      BreakableConstraint = (hk_Breakable_Constraint *)hk_Ball_Socket_Constraint::hk_Ball_Socket_Constraint(
                                                         this: v25,
                                                         constraint_system: m_pLCS,
                                                         bp: &builder,
                                                         a: (hk_Rigid_Body *)this->m_pObjReference->m_pObject,
                                                         b: (hk_Rigid_Body *)this->m_pObjAttached->m_pObject);
    }
    else
    {
      BreakableConstraint = nullptr;
    }
  }
  m_HkLCS = this->m_HkLCS;
  this->m_HkConstraint = BreakableConstraint;
  if ( m_HkLCS != nullptr )
  {
    if ( ballsocket->constraint.isActive )
      hk_Local_Constraint_System::activate(this: m_HkLCS);
    this->m_HkConstraint->m_client_data = this;
  }
  else
  {
    this->m_HkConstraint->m_client_data = this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AD40
// Name: public: void CPhysicsConstraint::InitPulley(class IVP_Environment __near *,class CPhysicsConstraintGroup __near *,struct constraint_pulleyparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CPhysicsConstraint::InitPulley(
        CPhysicsConstraint *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        hk_Environment *pEnvironment,
        hk_Local_Constraint_System *constraint_group,
        const constraint_pulleyparams_t *pulley)
{
  float forceLimit; // xmm0_4
  float torqueLimit; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  float totalLength; // xmm1_4
  float x; // xmm2_4
  float y; // xmm4_4
  bool isRigid; // dl
  float z; // xmm1_4
  float v17; // xmm2_4
  float v18; // xmm4_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm4_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  hk_Local_Constraint_System *m_environment; // eax
  void *v25; // eax
  hk_Local_Constraint_System *v26; // ecx
  int v27; // eax
  hk_Pulley_Constraint *v28; // ecx
  hk_Pulley_Constraint *v29; // eax
  hk_Breakable_Constraint *BreakableConstraint; // eax
  hk_Pulley_Constraint *v31; // ecx
  hk_Local_Constraint_System *m_HkLCS; // ecx
  hk_Pulley_BP pulley_bp; // [esp+0h] [ebp-74h] BYREF
  hk_Local_Constraint_System_BP v36; // [esp+5Ch] [ebp-18h] BYREF
  hk_Local_Constraint_System *lcs; // [esp+80h] [ebp+Ch]
  bool breakable_3; // [esp+87h] [ebp+13h]

  this->m_constraintType = 6;
  forceLimit = pulley->constraint.forceLimit;
  breakable_3 = true;
  if ( forceLimit == 0.0 || forceLimit >= 1.0e12 )
  {
    torqueLimit = pulley->constraint.torqueLimit;
    if ( torqueLimit == 0.0 || torqueLimit >= 1.0e12 )
    {
      v10 = pulley->constraint.bodyMassScale[0];
      if ( v10 == 1.0 || v10 == 0.0 )
      {
        v11 = pulley->constraint.bodyMassScale[1];
        if ( v11 == 1.0 || v11 == 0.0 )
          breakable_3 = false;
      }
    }
  }
  totalLength = pulley->totalLength;
  x = pulley->objectPosition[0].x;
  y = pulley->objectPosition[0].y;
  isRigid = pulley->isRigid;
  pulley_bp.m_tau = pulley->constraint.strength;
  pulley_bp.m_gearing = pulley->gearRatio;
  pulley_bp.m_length = totalLength * g_PhysicsUnits.unitScaleMeters;
  pulley_bp.m_translation_os_ks[0].y = -(float)(pulley->objectPosition[0].z * g_PhysicsUnits.unitScaleMeters);
  pulley_bp.m_translation_os_ks[1].y = -(float)(pulley->objectPosition[1].z * g_PhysicsUnits.unitScaleMeters);
  z = pulley->pulleyPosition[0].z;
  pulley_bp.m_translation_os_ks[0].x = x * g_PhysicsUnits.unitScaleMeters;
  v17 = pulley->objectPosition[1].x * g_PhysicsUnits.unitScaleMeters;
  pulley_bp.m_translation_os_ks[0].z = y * g_PhysicsUnits.unitScaleMeters;
  v18 = pulley->objectPosition[1].y;
  pulley_bp.m_translation_os_ks[1].x = v17;
  v19 = pulley->pulleyPosition[0].x;
  pulley_bp.m_worldspace_point[0].y = -(float)(z * g_PhysicsUnits.unitScaleMeters);
  v20 = pulley->pulleyPosition[1].z;
  pulley_bp.m_translation_os_ks[1].z = v18 * g_PhysicsUnits.unitScaleMeters;
  v21 = pulley->pulleyPosition[0].y;
  pulley_bp.m_worldspace_point[0].x = v19 * g_PhysicsUnits.unitScaleMeters;
  v22 = pulley->pulleyPosition[1].x * g_PhysicsUnits.unitScaleMeters;
  v23 = pulley->pulleyPosition[1].y * g_PhysicsUnits.unitScaleMeters;
  pulley_bp.m_strength = 1.0;
  pulley_bp.m_is_rigid = isRigid;
  pulley_bp.m_worldspace_point[0].z = v21 * g_PhysicsUnits.unitScaleMeters;
  pulley_bp.m_worldspace_point[1].x = v22;
  pulley_bp.m_worldspace_point[1].y = -(float)(v20 * g_PhysicsUnits.unitScaleMeters);
  pulley_bp.m_worldspace_point[1].z = v23;
  if ( constraint_group != nullptr )
    m_environment = (hk_Local_Constraint_System *)constraint_group->m_environment;
  else
    m_environment = nullptr;
  lcs = m_environment;
  if ( m_environment == nullptr )
  {
    v36.m_n_iterations = 0;
    v36.m_damp = 1.0;
    v36.m_tau = 1.0;
    v36.m_active = true;
    v36.m_errorTolerance = 0.029999999;
    v36.m_minErrorTicks = 1;
    v25 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 131);
    if ( v25 != nullptr )
    {
      v26 = (hk_Local_Constraint_System *)(((unsigned int)v25 + 19) & 0xFFFFFFF0);
      *((_DWORD *)&v26[-1].m_client_data + 3) = v25;
      lcs = hk_Local_Constraint_System::hk_Local_Constraint_System(this: v26, env: pEnvironment, bp: &v36);
    }
    else
    {
      lcs = nullptr;
    }
    this->m_HkLCS = lcs;
  }
  v27 = ((int (__thiscall *)(IMemAlloc *, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, unsigned int, unsigned int, _DWORD, _DWORD, int, int))_g_pMemAlloc->Alloc_2)(
          a1: _g_pMemAlloc,
          a2: 127,
          a3: a2,
          a4: a3,
          a5: LODWORD(pulley_bp.m_length),
          a6: LODWORD(pulley_bp.m_tau),
          a7: LODWORD(pulley_bp.m_strength),
          a8: LODWORD(pulley_bp.m_gearing),
          a9: LODWORD(pulley_bp.m_translation_os_ks[0].x),
          a10: LODWORD(pulley_bp.m_translation_os_ks[0].y),
          a11: LODWORD(pulley_bp.m_translation_os_ks[0].z),
          a12: LODWORD(pulley_bp.m_translation_os_ks[0].w),
          a13: LODWORD(pulley_bp.m_translation_os_ks[1].x),
          a14: LODWORD(pulley_bp.m_translation_os_ks[1].y),
          a15: LODWORD(pulley_bp.m_translation_os_ks[1].z),
          a16: LODWORD(pulley_bp.m_translation_os_ks[1].w),
          a17: LODWORD(pulley_bp.m_worldspace_point[0].x),
          a18: LODWORD(pulley_bp.m_worldspace_point[0].y),
          a19: LODWORD(pulley_bp.m_worldspace_point[0].z),
          a20: LODWORD(pulley_bp.m_worldspace_point[0].w),
          a21: LODWORD(pulley_bp.m_worldspace_point[1].x),
          a22: LODWORD(pulley_bp.m_worldspace_point[1].y),
          a23: LODWORD(pulley_bp.m_worldspace_point[1].z),
          a24: LODWORD(pulley_bp.m_worldspace_point[1].w),
          a25: *(_DWORD *)&pulley_bp.m_is_rigid,
          a26: pulley_bp.m_bodies[0],
          a27: pulley_bp.m_bodies[1],
          a28: LODWORD(v36.m_damp),
          a29: LODWORD(v36.m_tau),
          a30: v36.m_n_iterations,
          a31: v36.m_minErrorTicks);
  if ( breakable_3 )
  {
    if ( v27 != 0 )
    {
      v28 = (hk_Pulley_Constraint *)((v27 + 19) & 0xFFFFFFF0);
      *(_DWORD *)&v28[-1].m_is_rigid = v27;
      v29 = hk_Pulley_Constraint::hk_Pulley_Constraint(
              this: v28,
              env: pEnvironment,
              bp: &pulley_bp,
              a: (hk_Rigid_Body *)this->m_pObjReference->m_pObject,
              b: (hk_Rigid_Body *)this->m_pObjAttached->m_pObject);
      BreakableConstraint = CPhysicsConstraint::CreateBreakableConstraint(
                              this,
                              pRealConstraint: v29,
                              pLcs: lcs,
                              constraint: &pulley->constraint);
    }
    else
    {
      BreakableConstraint = CPhysicsConstraint::CreateBreakableConstraint(
                              this,
                              pRealConstraint: nullptr,
                              pLcs: lcs,
                              constraint: &pulley->constraint);
    }
  }
  else if ( v27 != 0 )
  {
    v31 = (hk_Pulley_Constraint *)((v27 + 19) & 0xFFFFFFF0);
    *(_DWORD *)&v31[-1].m_is_rigid = v27;
    BreakableConstraint = (hk_Breakable_Constraint *)hk_Pulley_Constraint::hk_Pulley_Constraint(
                                                       this: v31,
                                                       constraint_system: lcs,
                                                       bp: &pulley_bp,
                                                       a: (hk_Rigid_Body *)this->m_pObjReference->m_pObject,
                                                       b: (hk_Rigid_Body *)this->m_pObjAttached->m_pObject);
  }
  else
  {
    BreakableConstraint = nullptr;
  }
  m_HkLCS = this->m_HkLCS;
  this->m_HkConstraint = BreakableConstraint;
  if ( m_HkLCS != nullptr )
  {
    if ( pulley->constraint.isActive )
      hk_Local_Constraint_System::activate(this: m_HkLCS);
    this->m_HkConstraint->m_client_data = this;
  }
  else
  {
    this->m_HkConstraint->m_client_data = this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B000
// Name: public: void CPhysicsConstraint::InitLength(class IVP_Environment __near *,class CPhysicsConstraintGroup __near *,struct constraint_lengthparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CPhysicsConstraint::InitLength(
        CPhysicsConstraint *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        hk_Environment *pEnvironment,
        CPhysicsConstraintGroup *constraint_group,
        const constraint_lengthparams_t *length)
{
  float forceLimit; // xmm0_4
  float torqueLimit; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  float totalLength; // xmm1_4
  float x; // xmm2_4
  float y; // xmm3_4
  float z; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  hk_Local_Constraint_System *m_pLCS; // edi
  void *v18; // eax
  hk_Local_Constraint_System *v19; // ecx
  int v20; // eax
  hk_Stiff_Spring_Constraint *v21; // ecx
  hk_Stiff_Spring_Constraint *v22; // eax
  hk_Breakable_Constraint *BreakableConstraint; // eax
  int v24; // eax
  hk_Stiff_Spring_Constraint *v25; // ecx
  hk_Local_Constraint_System *m_HkLCS; // ecx
  hk_Stiff_Spring_BP stiff_bp; // [esp+0h] [ebp-54h] BYREF
  hk_Local_Constraint_System_BP v30; // [esp+38h] [ebp-1Ch] BYREF
  bool breakable; // [esp+53h] [ebp-1h]

  this->m_constraintType = 7;
  forceLimit = length->constraint.forceLimit;
  breakable = forceLimit != 0.0 && forceLimit < 1.0e12
           || (torqueLimit = length->constraint.torqueLimit) != 0.0 && torqueLimit < 1.0e12
           || (v9 = length->constraint.bodyMassScale[0]) != 1.0 && v9 != 0.0
           || (v10 = length->constraint.bodyMassScale[1]) != 1.0 && v10 != 0.0;
  totalLength = length->totalLength;
  x = length->objectPosition[0].x;
  y = length->objectPosition[0].y;
  stiff_bp.m_strength = 0.5;
  stiff_bp.m_tau = length->constraint.strength;
  stiff_bp.m_length = totalLength * g_PhysicsUnits.unitScaleMeters;
  stiff_bp.m_min_length = length->minLength * g_PhysicsUnits.unitScaleMeters;
  LODWORD(stiff_bp.m_translation_os_ks[0].y) = COERCE_UNSIGNED_INT(length->objectPosition[0].z * g_PhysicsUnits.unitScaleMeters)
                                             ^ _mask__NegFloat_;
  z = length->objectPosition[1].z;
  stiff_bp.m_translation_os_ks[0].x = x * g_PhysicsUnits.unitScaleMeters;
  v15 = length->objectPosition[1].x;
  stiff_bp.m_translation_os_ks[0].z = y * g_PhysicsUnits.unitScaleMeters;
  v16 = length->objectPosition[1].y * g_PhysicsUnits.unitScaleMeters;
  stiff_bp.m_translation_os_ks[1].x = v15 * g_PhysicsUnits.unitScaleMeters;
  LODWORD(stiff_bp.m_translation_os_ks[1].y) = COERCE_UNSIGNED_INT(z * g_PhysicsUnits.unitScaleMeters)
                                             ^ _mask__NegFloat_;
  stiff_bp.m_translation_os_ks[1].z = v16;
  if ( constraint_group != nullptr )
    m_pLCS = constraint_group->m_pLCS;
  else
    m_pLCS = nullptr;
  if ( m_pLCS == nullptr )
  {
    v30.m_damp = 1.0;
    v30.m_tau = 1.0;
    v30.m_active = true;
    v30.m_n_iterations = 0;
    v30.m_errorTolerance = 0.029999999;
    v30.m_minErrorTicks = 1;
    v18 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 131);
    if ( v18 != nullptr )
    {
      v19 = (hk_Local_Constraint_System *)(((unsigned int)v18 + 19) & 0xFFFFFFF0);
      *((_DWORD *)&v19[-1].m_client_data + 3) = v18;
      m_pLCS = hk_Local_Constraint_System::hk_Local_Constraint_System(this: v19, env: pEnvironment, bp: &v30);
    }
    else
    {
      m_pLCS = nullptr;
    }
    this->m_HkLCS = m_pLCS;
  }
  if ( breakable )
  {
    v20 = ((int (__thiscall *)(IMemAlloc *, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, unsigned int, unsigned int, _DWORD, _DWORD, int, int, _DWORD))_g_pMemAlloc->Alloc_2)(
            a1: _g_pMemAlloc,
            a2: 91,
            a3: a2,
            a4: a3,
            a5: LODWORD(stiff_bp.m_length),
            a6: LODWORD(stiff_bp.m_tau),
            a7: LODWORD(stiff_bp.m_strength),
            a8: LODWORD(stiff_bp.m_translation_os_ks[0].x),
            a9: LODWORD(stiff_bp.m_translation_os_ks[0].y),
            a10: LODWORD(stiff_bp.m_translation_os_ks[0].z),
            a11: LODWORD(stiff_bp.m_translation_os_ks[0].w),
            a12: LODWORD(stiff_bp.m_translation_os_ks[1].x),
            a13: LODWORD(stiff_bp.m_translation_os_ks[1].y),
            a14: LODWORD(stiff_bp.m_translation_os_ks[1].z),
            a15: LODWORD(stiff_bp.m_translation_os_ks[1].w),
            a16: LODWORD(stiff_bp.m_min_length),
            a17: stiff_bp.m_bodies[0],
            a18: stiff_bp.m_bodies[1],
            a19: LODWORD(v30.m_damp),
            a20: LODWORD(v30.m_tau),
            a21: v30.m_n_iterations,
            a22: v30.m_minErrorTicks,
            a23: LODWORD(v30.m_errorTolerance));
    if ( v20 != 0 )
    {
      v21 = (hk_Stiff_Spring_Constraint *)((v20 + 19) & 0xFFFFFFF0);
      LODWORD(v21[-1].m_min_length) = v20;
      v22 = hk_Stiff_Spring_Constraint::hk_Stiff_Spring_Constraint(
              this: v21,
              env: pEnvironment,
              bp: &stiff_bp,
              a: (hk_Rigid_Body *)this->m_pObjReference->m_pObject,
              b: (hk_Rigid_Body *)this->m_pObjAttached->m_pObject);
      BreakableConstraint = CPhysicsConstraint::CreateBreakableConstraint(
                              this,
                              pRealConstraint: v22,
                              pLcs: m_pLCS,
                              constraint: &length->constraint);
    }
    else
    {
      BreakableConstraint = CPhysicsConstraint::CreateBreakableConstraint(
                              this,
                              pRealConstraint: nullptr,
                              pLcs: m_pLCS,
                              constraint: &length->constraint);
    }
  }
  else
  {
    v24 = ((int (__thiscall *)(IMemAlloc *, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, unsigned int, unsigned int, _DWORD, _DWORD, int, int, _DWORD))_g_pMemAlloc->Alloc_2)(
            a1: _g_pMemAlloc,
            a2: 91,
            a3: a2,
            a4: a3,
            a5: LODWORD(stiff_bp.m_length),
            a6: LODWORD(stiff_bp.m_tau),
            a7: LODWORD(stiff_bp.m_strength),
            a8: LODWORD(stiff_bp.m_translation_os_ks[0].x),
            a9: LODWORD(stiff_bp.m_translation_os_ks[0].y),
            a10: LODWORD(stiff_bp.m_translation_os_ks[0].z),
            a11: LODWORD(stiff_bp.m_translation_os_ks[0].w),
            a12: LODWORD(stiff_bp.m_translation_os_ks[1].x),
            a13: LODWORD(stiff_bp.m_translation_os_ks[1].y),
            a14: LODWORD(stiff_bp.m_translation_os_ks[1].z),
            a15: LODWORD(stiff_bp.m_translation_os_ks[1].w),
            a16: LODWORD(stiff_bp.m_min_length),
            a17: stiff_bp.m_bodies[0],
            a18: stiff_bp.m_bodies[1],
            a19: LODWORD(v30.m_damp),
            a20: LODWORD(v30.m_tau),
            a21: v30.m_n_iterations,
            a22: v30.m_minErrorTicks,
            a23: LODWORD(v30.m_errorTolerance));
    if ( v24 != 0 )
    {
      v25 = (hk_Stiff_Spring_Constraint *)((v24 + 19) & 0xFFFFFFF0);
      LODWORD(v25[-1].m_min_length) = v24;
      BreakableConstraint = (hk_Breakable_Constraint *)hk_Stiff_Spring_Constraint::hk_Stiff_Spring_Constraint(
                                                         this: v25,
                                                         constraint_system: m_pLCS,
                                                         bp: &stiff_bp,
                                                         a: (hk_Rigid_Body *)this->m_pObjReference->m_pObject,
                                                         b: (hk_Rigid_Body *)this->m_pObjAttached->m_pObject);
    }
    else
    {
      BreakableConstraint = nullptr;
    }
  }
  m_HkLCS = this->m_HkLCS;
  this->m_HkConstraint = BreakableConstraint;
  if ( m_HkLCS != nullptr )
  {
    if ( length->constraint.isActive )
      hk_Local_Constraint_System::activate(this: m_HkLCS);
    this->m_HkConstraint->m_client_data = this;
  }
  else
  {
    this->m_HkConstraint->m_client_data = this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B270
// Name: public: virtual void CPhysicsConstraint::SetLinearMotor(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsConstraint::SetLinearMotor(CPhysicsConstraint *this, float speed, float maxLinearImpulse)
{
  bool v3; // zf
  hk_Breakable_Constraint *m_HkConstraint; // ecx
  hk_Breakable_Constraint_BP pOutBP; // [esp+8h] [ebp-1Ch] BYREF

  if ( this->m_constraintType == 5 )
  {
    v3 = this->m_isBreakable == 0;
    m_HkConstraint = (hk_Breakable_Constraint *)this->m_HkConstraint;
    if ( !v3 )
    {
      memset(&pOutBP, 0, 12);
      pOutBP.m_bodyMassScale[0] = 1.0;
      pOutBP.m_bodyMassScale[1] = 1.0;
      hk_Breakable_Constraint::write_to_blueprint(this: m_HkConstraint, &pOutBP);
      m_HkConstraint = (hk_Breakable_Constraint *)pOutBP.m_real_constraint;
    }
    hk_Prismatic_Constraint::set_motor(
      this: (hk_Prismatic_Constraint *)m_HkConstraint,
      desired_vel: g_PhysicsUnits.unitScaleMeters * speed,
      max_force: g_PhysicsUnits.unitScaleMeters * maxLinearImpulse);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B2F0
// Name: public: virtual void CPhysicsConstraint::SetAngularMotor(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsConstraint::SetAngularMotor(CPhysicsConstraint *this, float rotSpeed, float maxAngularImpulse)
{
  __int16 m_constraintType; // dx
  float v4; // xmm1_4
  bool v5; // zf
  hk_Breakable_Constraint *m_HkConstraint; // ecx
  hk_Breakable_Constraint *m_real_constraint; // ecx
  hk_Breakable_Constraint_BP pOutBP; // [esp+8h] [ebp-1Ch] BYREF

  m_constraintType = this->m_constraintType;
  v4 = rotSpeed;
  if ( m_constraintType == 1 && rotSpeed == 0.0 )
  {
    v5 = this->m_isBreakable == 0;
    m_HkConstraint = (hk_Breakable_Constraint *)this->m_HkConstraint;
    if ( !v5 )
    {
      memset(&pOutBP, 0, 12);
      pOutBP.m_bodyMassScale[0] = 1.0;
      pOutBP.m_bodyMassScale[1] = 1.0;
      hk_Breakable_Constraint::write_to_blueprint(this: m_HkConstraint, &pOutBP);
      m_HkConstraint = (hk_Breakable_Constraint *)pOutBP.m_real_constraint;
    }
    hk_Ragdoll_Constraint::update_friction(
      this: (hk_Ragdoll_Constraint *)m_HkConstraint,
      friction: maxAngularImpulse * 0.017453292);
  }
  else if ( m_constraintType == 2 )
  {
    v5 = this->m_isBreakable == 0;
    m_real_constraint = (hk_Breakable_Constraint *)this->m_HkConstraint;
    if ( !v5 )
    {
      memset(&pOutBP, 0, 12);
      pOutBP.m_bodyMassScale[0] = 1.0;
      pOutBP.m_bodyMassScale[1] = 1.0;
      hk_Breakable_Constraint::write_to_blueprint(this: m_real_constraint, &pOutBP);
      m_real_constraint = (hk_Breakable_Constraint *)pOutBP.m_real_constraint;
      v4 = rotSpeed;
    }
    hk_Hinge_Constraint::set_motor(
      this: (hk_Hinge_Constraint *)m_real_constraint,
      desired_vel: v4 * 0.017453292,
      max_force: COERCE_FLOAT(LODWORD(maxAngularImpulse) & _mask__AbsFloat_) * 0.017453292);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B3F0
// Name: public: void CPhysicsConstraint::ReadBreakableConstraint(struct constraint_breakableparams_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsConstraint::ReadBreakableConstraint(
        CPhysicsConstraint *this,
        constraint_breakableparams_t *params)
{
  hk_Breakable_Constraint *m_HkConstraint; // ecx
  constraint_breakableparams_t *v4; // eax
  float v5; // xmm0_4
  hk_Local_Constraint_System *m_HkLCS; // esi
  hk_Breakable_Constraint_BP pOutBP; // [esp+0h] [ebp-1Ch] BYREF

  if ( this->m_isBreakable != 0 )
  {
    m_HkConstraint = (hk_Breakable_Constraint *)this->m_HkConstraint;
    memset(&pOutBP, 0, 12);
    pOutBP.m_bodyMassScale[0] = 1.0;
    pOutBP.m_bodyMassScale[1] = 1.0;
    hk_Breakable_Constraint::write_to_blueprint(this: m_HkConstraint, &pOutBP);
    v4 = params;
    params->forceLimit = g_PhysicsUnits.unitScaleMetersInv * pOutBP.m_linear_strength;
    params->torqueLimit = pOutBP.m_angular_strength * 57.29578;
    params->strength = 1.0;
    params->bodyMassScale[0] = pOutBP.m_bodyMassScale[0];
    v5 = pOutBP.m_bodyMassScale[1];
  }
  else
  {
    v4 = params;
    params->forceLimit = 0.0;
    params->torqueLimit = 0.0;
    v5 = 1.0;
    params->strength = 1.0;
    params->bodyMassScale[0] = 1.0;
    params->isActive = true;
  }
  v4->bodyMassScale[1] = v5;
  m_HkLCS = this->m_HkLCS;
  if ( m_HkLCS != nullptr )
    v4->isActive = m_HkLCS->m_is_active;
}

//------------------------------------------------------------------------------
// Address: 0x1000B4C0
// Name: public: void CPhysicsConstraint::WriteHinge(struct constraint_hingeparams_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysicsConstraint::WriteHinge(
        CPhysicsConstraint *this@<ecx>,
        int a2@<ebp>,
        constraint_hingeparams_t *hinge)
{
  hk_Breakable_Constraint *m_HkConstraint; // ecx
  float unitScaleMetersInv; // xmm2_4
  float m_angular_strength; // xmm1_4
  hk_Constraint *v7; // xmm3_4
  float y; // xmm0_4
  float v9; // xmm0_4
  bool v10; // zf
  float v11; // xmm1_4
  IVP_Real_Object *v12; // [esp-2Ch] [ebp-F4h]
  IVP_Real_Object *m_pObject; // [esp-1Ch] [ebp-E4h]
  _DWORD v14[2]; // [esp-Ch] [ebp-D4h] BYREF
  __int16 v15; // [esp-4h] [ebp-CCh]
  hk_Hinge_BP hinge_bp; // [esp+0h] [ebp-C8h] BYREF
  hk_Breakable_Constraint_BP v17; // [esp+8Ch] [ebp-3Ch] BYREF
  hk_Hinge_Constraint *m_real_constraint; // [esp+B8h] [ebp-10h]
  _DWORD v19[2]; // [esp+BCh] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+C8h] [ebp+0h]

  v19[0] = a2;
  v19[1] = retaddr;
  if ( this->m_isBreakable != 0 )
  {
    m_HkConstraint = (hk_Breakable_Constraint *)this->m_HkConstraint;
    memset(&v17, 0, 12);
    v17.m_bodyMassScale[0] = 1.0;
    v17.m_bodyMassScale[1] = 1.0;
    hk_Breakable_Constraint::write_to_blueprint(this: m_HkConstraint, pOutBP: &v17);
    m_real_constraint = (hk_Hinge_Constraint *)v17.m_real_constraint;
  }
  else
  {
    m_real_constraint = (hk_Hinge_Constraint *)this->m_HkConstraint;
  }
  CPhysicsConstraint::ReadBreakableConstraint(this, params: &hinge->constraint);
  v15 = 0;
  hinge_bp.m_tau = 0.0;
  hinge_bp.m_strength = 0.0;
  *(_DWORD *)&hinge_bp.m_limit.m_limit_is_enabled = 1065353216;
  memset(&hinge_bp.m_limit.m_limit_min, 0, 20);
  v14[1] = 1065353216;
  v14[0] = 1065353216;
  memset(&hinge_bp.m_axis_os[0].m_origin.y, 0, 12);
  memset(&hinge_bp.m_axis_os[0].m_direction.y, 0, 12);
  memset(&hinge_bp.m_axis_os[1].m_origin.y, 0, 12);
  memset(&hinge_bp.m_axis_os[1].m_direction.y, 0, 12);
  memset(&hinge_bp.m_axis_perp_os[0].y, 0, 12);
  hk_Hinge_Constraint::write_to_blueprint(this: m_real_constraint, pOutBP: (hk_Hinge_BP *)v14);
  m_pObject = this->m_pObjReference->m_pObject;
  hinge_bp.m_axis_perp_os[1].w = hinge_bp.m_limit.m_limit_tau;
  *(_QWORD *)hinge_bp.m_bodies = *(_QWORD *)&hinge_bp.m_limit.m_joint_friction;
  TransformLocalToIVP(
    a1: COERCE_FLOAT(v19),
    pointIn: (const IVP_U_Float_Point *)&hinge_bp.m_axis_perp_os[1].w,
    pointOut: (IVP_U_Float_Point *)&v17,
    pObject: m_pObject,
    translate: true);
  unitScaleMetersInv = g_PhysicsUnits.unitScaleMetersInv;
  m_angular_strength = v17.m_angular_strength;
  v7 = v17.m_real_constraint;
  LODWORD(hinge->worldPosition.z) = COERCE_UNSIGNED_INT(v17.m_linear_strength * g_PhysicsUnits.unitScaleMetersInv)
                                  ^ _mask__NegFloat_;
  y = hinge_bp.m_axis_os[0].m_origin.y;
  hinge->worldPosition.x = *(float *)&v7 * unitScaleMetersInv;
  hinge->worldPosition.y = m_angular_strength * unitScaleMetersInv;
  v12 = this->m_pObjReference->m_pObject;
  *(float *)&v17.m_real_constraint = y;
  *(_QWORD *)&v17.m_linear_strength = *(_QWORD *)&hinge_bp.m_axis_os[0].m_origin.z;
  TransformLocalToIVP(
    a1: COERCE_FLOAT(v19),
    pointIn: (const IVP_U_Float_Point *)&v17,
    pointOut: (IVP_U_Float_Point *)&hinge_bp.m_axis_perp_os[1].w,
    pObject: v12,
    translate: false);
  LODWORD(v9) = hinge_bp.m_bodies[0] ^ _mask__NegFloat_;
  v10 = (_BYTE)v15 == 0;
  hinge->worldAxisDirection.x = hinge_bp.m_axis_perp_os[1].w;
  v11 = *(float *)&hinge_bp.m_bodies[1];
  hinge->worldAxisDirection.z = v9;
  hinge->worldAxisDirection.y = v11;
  hinge->hingeAxis.minRotation = 0.0;
  hinge->hingeAxis.maxRotation = 0.0;
  hinge->hingeAxis.angularVelocity = 0.0;
  hinge->hingeAxis.torque = 0.0;
  if ( !v10 )
  {
    hinge->hingeAxis.minRotation = hinge_bp.m_tau * 57.29578;
    hinge->hingeAxis.maxRotation = hinge_bp.m_strength * 57.29578;
  }
  if ( HIBYTE(v15) != 0 )
  {
    hinge->hingeAxis.angularVelocity = hinge_bp.m_limit.m_limit_max * 57.29578;
    hinge->hingeAxis.torque = hinge_bp.m_limit.m_limit_min * 57.29578;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B760
// Name: public: void CPhysicsConstraint::WritePulley(struct constraint_pulleyparams_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsConstraint::WritePulley(CPhysicsConstraint *this, hk_Pulley_Constraint *pulley)
{
  bool v3; // zf
  hk_Breakable_Constraint *m_HkConstraint; // ecx
  hk_Pulley_Constraint *m_real_constraint; // ebx
  float v6; // xmm2_4
  float x; // xmm0_4
  float y; // xmm3_4
  bool m_is_rigid; // al
  float v10; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm3_4
  float v15; // xmm0_4
  hk_Pulley_BP pulley_bp; // [esp+Ch] [ebp-78h] BYREF
  hk_Breakable_Constraint_BP pOutBP; // [esp+68h] [ebp-1Ch] BYREF

  pulley->m_entities[0] = nullptr;
  pulley->m_entities[1] = nullptr;
  pulley->__vftable = (hk_Pulley_Constraint_vtbl *)1065353216;
  pulley->m_environment = (hk_Environment *)1065353216;
  pulley->m_constraint_system = (hk_Local_Constraint_System *)1065353216;
  LOBYTE(pulley->m_client_data) = 1;
  pulley->m_worldspace_point[1].x = 1.0;
  pulley->m_worldspace_point[1].y = 1.0;
  pulley->m_translation_os_ks[0].x = 0.0;
  pulley->m_translation_os_ks[0].y = 0.0;
  pulley->m_translation_os_ks[0].z = 0.0;
  pulley->m_translation_os_ks[0].w = 0.0;
  pulley->m_translation_os_ks[1].x = 0.0;
  pulley->m_translation_os_ks[1].y = 0.0;
  pulley->m_translation_os_ks[1].z = 0.0;
  pulley->m_translation_os_ks[1].w = 0.0;
  pulley->m_worldspace_point[0].x = 0.0;
  pulley->m_worldspace_point[0].y = 0.0;
  pulley->m_worldspace_point[0].z = 0.0;
  pulley->m_worldspace_point[0].w = 0.0;
  LOBYTE(pulley->m_worldspace_point[1].z) = 0;
  v3 = this->m_isBreakable == 0;
  m_HkConstraint = (hk_Breakable_Constraint *)this->m_HkConstraint;
  if ( v3 )
  {
    m_real_constraint = (hk_Pulley_Constraint *)m_HkConstraint;
  }
  else
  {
    memset(&pOutBP, 0, 12);
    pOutBP.m_bodyMassScale[0] = 1.0;
    pOutBP.m_bodyMassScale[1] = 1.0;
    hk_Breakable_Constraint::write_to_blueprint(this: m_HkConstraint, &pOutBP);
    m_real_constraint = (hk_Pulley_Constraint *)pOutBP.m_real_constraint;
  }
  CPhysicsConstraint::ReadBreakableConstraint(this, params: (constraint_breakableparams_t *)pulley);
  pulley_bp.m_tau = 1.0;
  pulley_bp.m_strength = 1.0;
  pulley_bp.m_length = 1.0;
  pulley_bp.m_gearing = 1.0;
  pulley_bp.m_is_rigid = false;
  memset(pulley_bp.m_translation_os_ks, 0, 12);
  memset(&pulley_bp.m_translation_os_ks[1], 0, 12);
  memset(pulley_bp.m_worldspace_point, 0, 12);
  memset(&pulley_bp.m_worldspace_point[1], 0, 12);
  hk_Pulley_Constraint::write_to_blueprint(this: m_real_constraint, bp: &pulley_bp);
  v6 = pulley_bp.m_worldspace_point[0].y * g_PhysicsUnits.unitScaleMetersInv;
  pulley->m_translation_os_ks[0].y = pulley_bp.m_worldspace_point[0].z * g_PhysicsUnits.unitScaleMetersInv;
  x = pulley_bp.m_worldspace_point[0].x;
  y = pulley_bp.m_translation_os_ks[0].y;
  m_is_rigid = pulley_bp.m_is_rigid;
  pulley->m_translation_os_ks[0].z = -v6;
  pulley->m_translation_os_ks[0].x = x * g_PhysicsUnits.unitScaleMetersInv;
  v10 = y * g_PhysicsUnits.unitScaleMetersInv;
  pulley->m_translation_os_ks[1].w = pulley_bp.m_translation_os_ks[0].z * g_PhysicsUnits.unitScaleMetersInv;
  v11 = pulley_bp.m_translation_os_ks[0].x;
  pulley->m_worldspace_point[0].x = -v10;
  v12 = pulley_bp.m_worldspace_point[1].y;
  pulley->m_translation_os_ks[1].z = v11 * g_PhysicsUnits.unitScaleMetersInv;
  v13 = pulley_bp.m_worldspace_point[1].z * g_PhysicsUnits.unitScaleMetersInv;
  pulley->m_translation_os_ks[1].y = -(float)(v12 * g_PhysicsUnits.unitScaleMetersInv);
  v14 = pulley_bp.m_translation_os_ks[1].y;
  pulley->m_translation_os_ks[1].x = v13;
  pulley->m_translation_os_ks[0].w = pulley_bp.m_worldspace_point[1].x * g_PhysicsUnits.unitScaleMetersInv;
  v15 = pulley_bp.m_translation_os_ks[1].z * g_PhysicsUnits.unitScaleMetersInv;
  pulley->m_worldspace_point[0].w = -(float)(v14 * g_PhysicsUnits.unitScaleMetersInv);
  pulley->m_worldspace_point[0].z = v15;
  pulley->m_worldspace_point[0].y = pulley_bp.m_translation_os_ks[1].x * g_PhysicsUnits.unitScaleMetersInv;
  pulley->m_worldspace_point[1].y = pulley_bp.m_gearing;
  pulley->m_worldspace_point[1].x = g_PhysicsUnits.unitScaleMetersInv * pulley_bp.m_length;
  LOBYTE(pulley->m_worldspace_point[1].z) = m_is_rigid;
}

//------------------------------------------------------------------------------
// Address: 0x1000B9A0
// Name: public: void CPhysicsConstraint::WriteLength(struct constraint_lengthparams_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsConstraint::WriteLength(CPhysicsConstraint *this, constraint_lengthparams_t *length)
{
  hk_Breakable_Constraint *m_HkConstraint; // ecx
  hk_Stiff_Spring_Constraint *m_real_constraint; // ebx
  float y; // xmm3_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  hk_Stiff_Spring_BP stiff_bp; // [esp+0h] [ebp-54h] BYREF
  hk_Breakable_Constraint_BP pOutBP; // [esp+38h] [ebp-1Ch] BYREF

  length->constraint.forceLimit = 0.0;
  length->constraint.torqueLimit = 0.0;
  length->constraint.strength = 1.0;
  length->constraint.bodyMassScale[0] = 1.0;
  length->constraint.bodyMassScale[1] = 1.0;
  length->constraint.isActive = true;
  length->objectPosition[0].x = 0.0;
  length->objectPosition[0].y = 0.0;
  length->objectPosition[0].z = 0.0;
  length->objectPosition[1].x = 0.0;
  length->objectPosition[1].y = 0.0;
  length->objectPosition[1].z = 0.0;
  length->totalLength = 1.0;
  length->minLength = 0.0;
  if ( this->m_isBreakable != 0 )
  {
    m_HkConstraint = (hk_Breakable_Constraint *)this->m_HkConstraint;
    memset(&pOutBP, 0, 12);
    pOutBP.m_bodyMassScale[0] = 1.0;
    pOutBP.m_bodyMassScale[1] = 1.0;
    hk_Breakable_Constraint::write_to_blueprint(this: m_HkConstraint, &pOutBP);
    m_real_constraint = (hk_Stiff_Spring_Constraint *)pOutBP.m_real_constraint;
  }
  else
  {
    m_real_constraint = (hk_Stiff_Spring_Constraint *)this->m_HkConstraint;
  }
  CPhysicsConstraint::ReadBreakableConstraint(this, params: &length->constraint);
  stiff_bp.m_tau = 0.30000001;
  stiff_bp.m_strength = 0.5;
  stiff_bp.m_length = 1.0;
  stiff_bp.m_min_length = 1.0;
  memset(stiff_bp.m_translation_os_ks, 0, 12);
  memset(&stiff_bp.m_translation_os_ks[1], 0, 12);
  hk_Stiff_Spring_Constraint::write_to_blueprint(this: m_real_constraint, bp: &stiff_bp);
  y = stiff_bp.m_translation_os_ks[1].y;
  v6 = stiff_bp.m_translation_os_ks[0].z * g_PhysicsUnits.unitScaleMetersInv;
  length->objectPosition[0].z = -(float)(g_PhysicsUnits.unitScaleMetersInv * stiff_bp.m_translation_os_ks[0].y);
  length->objectPosition[0].y = v6;
  length->objectPosition[0].x = g_PhysicsUnits.unitScaleMetersInv * stiff_bp.m_translation_os_ks[0].x;
  v7 = stiff_bp.m_translation_os_ks[1].z * g_PhysicsUnits.unitScaleMetersInv;
  length->objectPosition[1].z = -(float)(y * g_PhysicsUnits.unitScaleMetersInv);
  length->objectPosition[1].y = v7;
  length->objectPosition[1].x = stiff_bp.m_translation_os_ks[1].x * g_PhysicsUnits.unitScaleMetersInv;
  length->totalLength = g_PhysicsUnits.unitScaleMetersInv * stiff_bp.m_length;
  length->minLength = g_PhysicsUnits.unitScaleMetersInv * stiff_bp.m_min_length;
}

//------------------------------------------------------------------------------
// Address: 0x1000BB40
// Name: public: void CPhysicsConstraint::WriteBallsocket(struct constraint_ballsocketparams_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsConstraint::WriteBallsocket(CPhysicsConstraint *this, hk_Ball_Socket_Constraint *ballsocket)
{
  hk_Breakable_Constraint *m_HkConstraint; // ecx
  float y; // xmm3_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  hk_Ball_Socket_BP ballsocket_bp; // [esp+0h] [ebp-4Ch] BYREF
  hk_Breakable_Constraint_BP pOutBP; // [esp+30h] [ebp-1Ch] BYREF
  hk_Ball_Socket_Constraint *pConstraint; // [esp+54h] [ebp+8h]

  ballsocket->m_translation_os_ks[0].y = 0.0;
  ballsocket->m_translation_os_ks[0].z = 0.0;
  ballsocket->m_translation_os_ks[0].x = 1.0;
  ballsocket->m_translation_os_ks[0].w = 1.0;
  ballsocket->m_translation_os_ks[1].x = 1.0;
  LOBYTE(ballsocket->m_translation_os_ks[1].y) = 1;
  ballsocket->__vftable = nullptr;
  ballsocket->m_entities[0] = nullptr;
  ballsocket->m_entities[1] = nullptr;
  ballsocket->m_environment = nullptr;
  ballsocket->m_constraint_system = nullptr;
  ballsocket->m_client_data = nullptr;
  if ( this->m_isBreakable != 0 )
  {
    m_HkConstraint = (hk_Breakable_Constraint *)this->m_HkConstraint;
    memset(&pOutBP, 0, 12);
    pOutBP.m_bodyMassScale[0] = 1.0;
    pOutBP.m_bodyMassScale[1] = 1.0;
    hk_Breakable_Constraint::write_to_blueprint(this: m_HkConstraint, &pOutBP);
    pConstraint = (hk_Ball_Socket_Constraint *)pOutBP.m_real_constraint;
  }
  else
  {
    pConstraint = (hk_Ball_Socket_Constraint *)this->m_HkConstraint;
  }
  CPhysicsConstraint::ReadBreakableConstraint(
    this,
    params: (constraint_breakableparams_t *)ballsocket->m_translation_os_ks);
  ballsocket_bp.m_strength = 1.0;
  ballsocket_bp.m_tau = 1.0;
  memset(ballsocket_bp.m_translation_os_ks, 0, 12);
  memset(&ballsocket_bp.m_translation_os_ks[1], 0, 12);
  hk_Ball_Socket_Constraint::write_to_blueprint(this: pConstraint, bp: &ballsocket_bp);
  y = ballsocket_bp.m_translation_os_ks[1].y;
  v6 = g_PhysicsUnits.unitScaleMetersInv * ballsocket_bp.m_translation_os_ks[0].z;
  *(float *)&ballsocket->m_entities[1] = -(float)(g_PhysicsUnits.unitScaleMetersInv
                                                * ballsocket_bp.m_translation_os_ks[0].y);
  *(float *)ballsocket->m_entities = v6;
  *(float *)&ballsocket->__vftable = g_PhysicsUnits.unitScaleMetersInv * ballsocket_bp.m_translation_os_ks[0].x;
  v7 = ballsocket_bp.m_translation_os_ks[1].z * g_PhysicsUnits.unitScaleMetersInv;
  *(float *)&ballsocket->m_client_data = -(float)(y * g_PhysicsUnits.unitScaleMetersInv);
  *(float *)&ballsocket->m_constraint_system = v7;
  *(float *)&ballsocket->m_environment = g_PhysicsUnits.unitScaleMetersInv * ballsocket_bp.m_translation_os_ks[1].x;
}

//------------------------------------------------------------------------------
// Address: 0x1000BCA0
// Name: public: virtual void CPhysicsConstraint::event_object_deleted(class IVP_Event_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsConstraint::event_object_deleted(CPhysicsConstraint *this, IVP_Event_Object *pEvent)
{
  hk_Constraint *m_HkConstraint; // ecx
  IVP_Core *physical_core; // eax
  IVP_Listener_Object_vtbl *v5; // eax
  char *v6; // esi
  int v7; // eax
  CPhysicsObject *m_pObjAttached; // ecx
  hk_Constraint *v9; // ecx

  m_HkConstraint = this->m_HkConstraint;
  if ( m_HkConstraint != nullptr )
  {
    physical_core = pEvent->real_object->physical_core;
    if ( (*(_BYTE *)&physical_core->IVP_Core_Fast_Static & 2) != 0 )
      m_HkConstraint->get_effected_entities(this: m_HkConstraint, a2: (hk_Array<hk_Rigid_Body *> *)physical_core);
  }
  v5 = this->IVP_Listener_Object::__vftable;
  v6 = (char *)this - 4;
  if ( ((int)v5[1].event_object_revived & 0x200) == 0 )
    IVP_Real_Object::remove_listener_object(
      this: (IVP_Real_Object *)v5->event_object_revived,
      listener: (IVP_Listener_Object *)this);
  v7 = *((_DWORD *)v6 + 3);
  if ( (*(_WORD *)(v7 + 28) & 0x200) == 0 )
    IVP_Real_Object::remove_listener_object(this: *(IVP_Real_Object **)(v7 + 8), listener: (IVP_Listener_Object *)this);
  *((_DWORD *)v6 + 2) = 0;
  *((_DWORD *)v6 + 3) = 0;
  m_pObjAttached = this->m_pObjAttached;
  if ( m_pObjAttached != nullptr )
    ((void (__thiscall *)(CPhysicsObject *, int))m_pObjAttached->IsStatic)(a1: m_pObjAttached, a2: 1);
  v9 = this->m_HkConstraint;
  this->m_pObjAttached = nullptr;
  if ( v9 != nullptr )
    v9->init_constraint(this: v9, a2: (const void *)1);
  this->m_HkConstraint = nullptr;
  if ( pEvent->environment != nullptr )
    CPhysicsEnvironment::NotifyConstraintDisabled(
      this: (CPhysicsEnvironment *)pEvent->environment->client_data,
      pConstraint: (IPhysicsConstraint *)this - 1);
}

//------------------------------------------------------------------------------
// Address: 0x1000BD50
// Name: public: virtual CPhysicsConstraint::~CPhysicsConstraint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsConstraint::~CPhysicsConstraint(CPhysicsConstraint *this)
{
  bool v2; // zf
  IVP_Listener_Object *v3; // edi
  CPhysicsObject *m_pObjReference; // eax
  CPhysicsObject *m_pObjAttached; // eax
  hk_Local_Constraint_System *m_HkLCS; // ecx
  hk_Constraint *m_HkConstraint; // ecx

  v2 = this->m_HkConstraint == nullptr;
  v3 = &this->IVP_Listener_Object;
  this->IPhysicsConstraint::__vftable = (CPhysicsConstraint_vtbl *)&CPhysicsConstraint::`vftable'{for `IPhysicsConstraint'};
  this->IVP_Listener_Object::__vftable = (IVP_Listener_Object_vtbl *)&CPhysicsConstraint::`vftable'{for `IVP_Listener_Object'};
  if ( !v2 || this->m_HkLCS != nullptr )
  {
    m_pObjReference = this->m_pObjReference;
    if ( (m_pObjReference->m_callbacks & 0x200) == 0 )
      IVP_Real_Object::remove_listener_object(this: m_pObjReference->m_pObject, listener: v3);
    m_pObjAttached = this->m_pObjAttached;
    if ( (m_pObjAttached->m_callbacks & 0x200) == 0 )
      IVP_Real_Object::remove_listener_object(this: m_pObjAttached->m_pObject, listener: v3);
    m_HkLCS = this->m_HkLCS;
    this->m_pObjReference = nullptr;
    this->m_pObjAttached = nullptr;
    if ( m_HkLCS != nullptr )
      ((void (__thiscall *)(hk_Local_Constraint_System *, int))m_HkLCS->dtr_IVP_Controller)(a1: m_HkLCS, a2: 1);
    m_HkConstraint = this->m_HkConstraint;
    if ( m_HkConstraint != nullptr )
      ((void (__thiscall *)(hk_Constraint *, int))m_HkConstraint->dtr_hk_Constraint)(a1: m_HkConstraint, a2: 1);
  }
  v3->__vftable = (IVP_Listener_Object_vtbl *)&IVP_Listener_Object::`vftable';
  this->IPhysicsConstraint::__vftable = (CPhysicsConstraint_vtbl *)&IPhysicsConstraint::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1000BDE0
// Name: class IPhysicsConstraintGroup __near * CreatePhysicsConstraintGroup(class IVP_Environment __near *,struct constraint_groupparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CPhysicsConstraintGroup *__usercall CreatePhysicsConstraintGroup@<eax>(
        int a1@<esi>,
        hk_Environment *pEnvironment,
        const constraint_groupparams_t *group)
{
  CPhysicsConstraintGroup *v3; // eax

  v3 = (CPhysicsConstraintGroup *)p_malloc(size: 8u);
  if ( v3 != nullptr )
    return CPhysicsConstraintGroup::CPhysicsConstraintGroup(this: v3, a2: a1, pEnvironment, group);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000BE10
// Name: class IPhysicsConstraint __near * CreateBallsocketConstraint(class IVP_Environment __near *,class CPhysicsObject __near *,class CPhysicsObject __near *,class IPhysicsConstraintGroup __near *,struct constraint_ballsocketparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CPhysicsConstraint *__usercall CreateBallsocketConstraint@<eax>(
        int a1@<edi>,
        hk_Environment *pEnvironment,
        CPhysicsObject *pReferenceObject,
        CPhysicsObject *pAttachedObject,
        CPhysicsConstraintGroup *pGroup,
        const constraint_ballsocketparams_t *ballsocket)
{
  CPhysicsConstraint *v6; // eax
  CPhysicsConstraint *v7; // esi

  v6 = (CPhysicsConstraint *)p_malloc(size: 0x20u);
  if ( v6 != nullptr )
    v7 = CPhysicsConstraint::CPhysicsConstraint(this: v6, pReferenceObject, pAttachedObject);
  else
    v7 = nullptr;
  CPhysicsConstraint::InitBallsocket(this: v7, a2: a1, a3: (int)v7, pEnvironment, constraint_group: pGroup, ballsocket);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x1000BE50
// Name: class IPhysicsConstraint __near * CreatePulleyConstraint(class IVP_Environment __near *,class CPhysicsObject __near *,class CPhysicsObject __near *,class IPhysicsConstraintGroup __near *,struct constraint_pulleyparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CPhysicsConstraint *__usercall CreatePulleyConstraint@<eax>(
        int a1@<edi>,
        hk_Environment *pEnvironment,
        CPhysicsObject *pReferenceObject,
        CPhysicsObject *pAttachedObject,
        hk_Local_Constraint_System *pGroup,
        const constraint_pulleyparams_t *pulley)
{
  CPhysicsConstraint *v6; // eax
  CPhysicsConstraint *v7; // esi

  v6 = (CPhysicsConstraint *)p_malloc(size: 0x20u);
  if ( v6 != nullptr )
    v7 = CPhysicsConstraint::CPhysicsConstraint(this: v6, pReferenceObject, pAttachedObject);
  else
    v7 = nullptr;
  CPhysicsConstraint::InitPulley(this: v7, a2: a1, a3: (int)v7, pEnvironment, constraint_group: pGroup, pulley);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x1000BE90
// Name: class IPhysicsConstraint __near * CreateLengthConstraint(class IVP_Environment __near *,class CPhysicsObject __near *,class CPhysicsObject __near *,class IPhysicsConstraintGroup __near *,struct constraint_lengthparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CPhysicsConstraint *__usercall CreateLengthConstraint@<eax>(
        int a1@<edi>,
        hk_Environment *pEnvironment,
        CPhysicsObject *pReferenceObject,
        CPhysicsObject *pAttachedObject,
        CPhysicsConstraintGroup *pGroup,
        const constraint_lengthparams_t *length)
{
  CPhysicsConstraint *v6; // eax
  CPhysicsConstraint *v7; // esi

  v6 = (CPhysicsConstraint *)p_malloc(size: 0x20u);
  if ( v6 != nullptr )
    v7 = CPhysicsConstraint::CPhysicsConstraint(this: v6, pReferenceObject, pAttachedObject);
  else
    v7 = nullptr;
  CPhysicsConstraint::InitLength(this: v7, a2: a1, a3: (int)v7, pEnvironment, constraint_group: pGroup, length);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x1000BED0
// Name: bool IsExternalConstraint(class IVP_Controller __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsExternalConstraint(IVP_Controller *pLCS, void *pGameData)
{
  IVP_U_Vector<IVP_Core> *v2; // edi
  int v3; // esi
  _DWORD *v4; // eax
  int v5; // edx
  int v6; // ecx

  v2 = pLCS->get_associated_controlled_cores(this: pLCS);
  if ( v2 == nullptr )
    return 0;
  v3 = 0;
  if ( v2->n_elems == 0 )
    return 0;
  while ( 1 )
  {
    v4 = v2->elems[v3];
    if ( v4 != nullptr )
    {
      v5 = v4[21];
      if ( *(_DWORD *)v5 != 0 )
      {
        v6 = *(_DWORD *)(*(_DWORD *)v5 + 160);
        if ( v6 != 0 && (void *)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 68))(a1: v6) != pGameData )
          break;
      }
    }
    if ( ++v3 >= v2->n_elems )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000BF40
// Name: bool RestorePhysicsConstraint(struct physrestoreparams_t const __near &,class CPhysicsConstraint __near * __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __usercall RestorePhysicsConstraint@<al>(
        int a1@<edi>,
        const physrestoreparams_t *params,
        CPhysicsConstraint **ppConstraint)
{
  IRestore *pRestore; // ecx
  int (__stdcall *CreateRagdollConstraint)(CPhysicsObject *, CPhysicsObject *, CPhysicsConstraintGroup *); // eax
  CPhysicsConstraint *v6; // eax
  unsigned __int8 v7[180]; // [esp+8h] [ebp-C4h] OVERLAPPED BYREF
  vphysics_save_cphysicsconstraint_t header; // [esp+BCh] [ebp-10h] BYREF

  pRestore = params->pRestore;
  memset(&header, 0, sizeof(header));
  pRestore->ReadAll(this: pRestore, a2: &header, a3: &vphysics_save_cphysicsconstraint_t::m_DataMap);
  if ( header.constraintType != 0 && header.pObjAttached != nullptr && header.pObjReference != nullptr )
  {
    switch ( header.constraintType )
    {
      case 1:
        memset(dst: v7, value: 0, count: sizeof(v7));
        ((void (__thiscall *)(IRestore *, unsigned __int8 *, datamap_t *, int))params->pRestore->ReadAll)(
          a1: params->pRestore,
          a2: v7,
          a3: &vphysics_save_constraintragdoll_t::m_DataMap,
          a4: a1);
        CreateRagdollConstraint = (int (__stdcall *)(CPhysicsObject *, CPhysicsObject *, CPhysicsConstraintGroup *))params->pEnvironment->CreateRagdollConstraint;
        goto LABEL_12;
      case 2:
        memset(dst: &v7[116], value: 0, count: 0x40u);
        ((void (__thiscall *)(IRestore *, unsigned __int8 *, datamap_t *, int))params->pRestore->ReadAll)(
          a1: params->pRestore,
          a2: &v7[116],
          a3: &vphysics_save_constrainthinge_t::m_DataMap,
          a4: a1);
        CreateRagdollConstraint = (int (__stdcall *)(CPhysicsObject *, CPhysicsObject *, CPhysicsConstraintGroup *))params->pEnvironment->CreateHingeConstraint;
        goto LABEL_12;
      case 3:
        memset(dst: &v7[108], value: 0, count: 0x48u);
        ((void (__thiscall *)(IRestore *, unsigned __int8 *, datamap_t *, int))params->pRestore->ReadAll)(
          a1: params->pRestore,
          a2: &v7[108],
          a3: &vphysics_save_constraintfixed_t::m_DataMap,
          a4: a1);
        CreateRagdollConstraint = (int (__stdcall *)(CPhysicsObject *, CPhysicsObject *, CPhysicsConstraintGroup *))params->pEnvironment->CreateFixedConstraint;
        goto LABEL_12;
      case 4:
        memset(dst: &v7[132], value: 0, count: 0x30u);
        ((void (__thiscall *)(IRestore *, unsigned __int8 *, datamap_t *, int))params->pRestore->ReadAll)(
          a1: params->pRestore,
          a2: &v7[132],
          a3: &vphysics_save_constraintballsocket_t::m_DataMap,
          a4: a1);
        CreateRagdollConstraint = (int (__stdcall *)(CPhysicsObject *, CPhysicsObject *, CPhysicsConstraintGroup *))params->pEnvironment->CreateBallsocketConstraint;
        goto LABEL_12;
      case 5:
        memset(dst: &v7[80], value: 0, count: 0x64u);
        ((void (__thiscall *)(IRestore *, unsigned __int8 *, datamap_t *, int))params->pRestore->ReadAll)(
          a1: params->pRestore,
          a2: &v7[80],
          a3: &vphysics_save_constraintsliding_t::m_DataMap,
          a4: a1);
        CreateRagdollConstraint = (int (__stdcall *)(CPhysicsObject *, CPhysicsObject *, CPhysicsConstraintGroup *))params->pEnvironment->CreateSlidingConstraint;
        goto LABEL_12;
      case 6:
        memset(dst: &v7[96], value: 0, count: 0x54u);
        ((void (__thiscall *)(IRestore *, unsigned __int8 *, datamap_t *, int))params->pRestore->ReadAll)(
          a1: params->pRestore,
          a2: &v7[96],
          a3: &vphysics_save_constraintpulley_t::m_DataMap,
          a4: a1);
        CreateRagdollConstraint = (int (__stdcall *)(CPhysicsObject *, CPhysicsObject *, CPhysicsConstraintGroup *))params->pEnvironment->CreatePulleyConstraint;
        goto LABEL_12;
      case 7:
        memset(dst: &v7[124], value: 0, count: 0x38u);
        ((void (__thiscall *)(IRestore *, unsigned __int8 *, datamap_t *, int))params->pRestore->ReadAll)(
          a1: params->pRestore,
          a2: &v7[124],
          a3: &vphysics_save_constraintlength_t::m_DataMap,
          a4: a1);
        CreateRagdollConstraint = (int (__stdcall *)(CPhysicsObject *, CPhysicsObject *, CPhysicsConstraintGroup *))params->pEnvironment->CreateLengthConstraint;
LABEL_12:
        *ppConstraint = (CPhysicsConstraint *)CreateRagdollConstraint(
                                                a1: header.pObjReference,
                                                a2: header.pObjAttached,
                                                a3: header.pGroup);
        break;
      default:
        break;
    }
    if ( *ppConstraint != nullptr )
    {
      (*ppConstraint)->SetGameData(this: *ppConstraint, a2: params->pGameData);
      return 1;
    }
  }
  else
  {
    v6 = (CPhysicsConstraint *)p_malloc(size: 0x20u);
    if ( v6 != nullptr )
    {
      v6->IVP_Listener_Object::__vftable = (IVP_Listener_Object_vtbl *)&IVP_Listener_Object::`vftable';
      *(_DWORD *)&v6->m_constraintType = 0;
      v6->m_pGameData = nullptr;
      v6->m_HkConstraint = nullptr;
      v6->m_HkLCS = nullptr;
      v6->m_pObjReference = nullptr;
      v6->m_pObjAttached = nullptr;
      v6->IPhysicsConstraint::__vftable = (CPhysicsConstraint_vtbl *)&CPhysicsConstraint::`vftable'{for `IPhysicsConstraint'};
      v6->IVP_Listener_Object::__vftable = (IVP_Listener_Object_vtbl *)&CPhysicsConstraint::`vftable'{for `IVP_Listener_Object'};
      *ppConstraint = v6;
      return 1;
    }
    *ppConstraint = nullptr;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000C1A0
// Name: bool SavePhysicsConstraintGroup(struct physsaveparams_t const __near &,class CPhysicsConstraintGroup __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SavePhysicsConstraintGroup(const physsaveparams_t *params, CPhysicsConstraintGroup *pConstraintGroup)
{
  hk_Local_Constraint_System *m_pLCS; // ecx
  ISave *pSave; // ecx
  hk_Local_Constraint_System_BP v5; // [esp+0h] [ebp-28h] BYREF
  vphysics_save_cphysicsconstraintgroup_t groupTemplate; // [esp+18h] [ebp-10h] BYREF

  m_pLCS = pConstraintGroup->m_pLCS;
  memset(&groupTemplate, 0, sizeof(groupTemplate));
  v5.m_damp = 1.0;
  v5.m_tau = 1.0;
  v5.m_active = true;
  v5.m_n_iterations = 0;
  v5.m_errorTolerance = 0.029999999;
  v5.m_minErrorTicks = 1;
  hk_Local_Constraint_System::write_to_blueprint(this: m_pLCS, bp: &v5);
  groupTemplate.additionalIterations = v5.m_n_iterations;
  groupTemplate.minErrorTicks = v5.m_minErrorTicks;
  pSave = params->pSave;
  groupTemplate.isActive = v5.m_active;
  groupTemplate.errorTolerance = g_PhysicsUnits.unitScaleMetersInv * v5.m_errorTolerance;
  pSave->WriteAll(this: pSave, a2: &groupTemplate, a3: &vphysics_save_cphysicsconstraintgroup_t::m_DataMap);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000C240
// Name: void ConvertHavanaLocalMatrixToHL(class hk_Transform const __near &,struct matrix3x4_t __near &,class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall ConvertHavanaLocalMatrixToHL(float a1@<ebp>, const hk_Transform *in, matrix3x4_t *hlMatrix)
{
  _DWORD v3[3]; // [esp-Ch] [ebp-4Ch] BYREF
  IVP_U_Matrix ivpMatrix; // [esp+0h] [ebp-40h]
  float retaddr; // [esp+40h] [ebp+0h]

  ivpMatrix.vv.k[1] = a1;
  ivpMatrix.vv.k[2] = retaddr;
  v3[0] = LODWORD(in->m_elems[0]);
  ivpMatrix.rows[0].k[1] = in->m_elems[1];
  ivpMatrix.rows[1].k[1] = in->m_elems[2];
  v3[1] = LODWORD(in->m_elems[4]);
  ivpMatrix.rows[0].k[2] = in->m_elems[5];
  ivpMatrix.rows[1].k[2] = in->m_elems[6];
  v3[2] = LODWORD(in->m_elems[8]);
  ivpMatrix.rows[0].hesse_val = in->m_elems[9];
  ivpMatrix.rows[1].hesse_val = in->m_elems[10];
  ivpMatrix.rows[2].k[1] = in->m_translation.x;
  ivpMatrix.rows[2].k[2] = in->m_translation.y;
  ivpMatrix.rows[2].hesse_val = in->m_translation.z;
  ConvertMatrixToHL(in: (const IVP_U_Matrix *)v3, output: hlMatrix);
}

//------------------------------------------------------------------------------
// Address: 0x1000C2F0
// Name: public: virtual void CPhysicsConstraint::OutputDebugInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsConstraint::OutputDebugInfo(CPhysicsConstraint *this)
{
  hk_Local_Constraint_System *m_HkLCS; // eax
  hk_Constraint *m_HkConstraint; // ecx
  int v3; // edi
  int v4; // esi
  const char *v5; // eax
  hk_Memory *instance; // eax
  char *m_elems; // [esp-Ch] [ebp-18h]
  int v8; // [esp-8h] [ebp-14h]
  hk_Array<hk_Constraint *> list; // [esp+4h] [ebp-8h] BYREF

  m_HkLCS = this->m_HkLCS;
  m_HkConstraint = this->m_HkConstraint;
  v3 = 0;
  if ( m_HkConstraint != nullptr )
    m_HkLCS = m_HkConstraint->m_constraint_system;
  if ( m_HkLCS != nullptr )
  {
    *(_DWORD *)&list.m_memsize = 0;
    list.m_elems = nullptr;
    hk_Local_Constraint_System::get_constraints_in_system(this: m_HkLCS, constraint_out: &list);
    _Msg(a1: "System of %d constraints\n", list.m_n_elems);
    v4 = list.m_n_elems - 1;
    if ( list.m_n_elems != 0 )
    {
      do
      {
        v5 = (const char *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)&list.m_elems[4 * v4] + 20))(a1: *(_DWORD *)&list.m_elems[4 * v4]);
        _Msg(a1: "\tConstraint %d) %s\n", v3++, v5);
        --v4;
      }
      while ( v4 >= 0 );
    }
    if ( list.m_elems != nullptr )
    {
      v8 = 4 * list.m_memsize;
      m_elems = list.m_elems;
      instance = hk_Memory::get_instance();
      hk_Memory::deallocate(this: instance, p: m_elems, size: v8, cl: HK_MEMORY_CLASS_ARRAY);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C3C0
// Name: public: void CPhysicsConstraint::InitHinge(class IVP_Environment __near *,class CPhysicsConstraintGroup __near *,struct constraint_limitedhingeparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CPhysicsConstraint::InitHinge(
        CPhysicsConstraint *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        hk_Environment *pEnvironment,
        CPhysicsConstraintGroup *constraint_group,
        const constraint_limitedhingeparams_t *hinge)
{
  float forceLimit; // xmm2_4
  float torqueLimit; // xmm2_4
  float v10; // xmm2_4
  float v11; // xmm2_4
  CPhysicsObject *m_pObjAttached; // edx
  float y; // xmm2_4
  float v14; // xmm0_4
  float x; // xmm1_4
  CPhysicsObject *m_pObjReference; // ecx
  float z; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm0_4
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  float v24; // xmm2_4
  float torque; // xmm0_4
  float minRotation; // xmm0_4
  float maxRotation; // xmm1_4
  hk_Local_Constraint_System *m_pLCS; // eax
  void *v29; // eax
  hk_Local_Constraint_System *v30; // ecx
  int v31; // eax
  hk_Hinge_Constraint *v32; // ecx
  hk_Hinge_Constraint *v33; // eax
  hk_Breakable_Constraint *BreakableConstraint; // eax
  hk_Hinge_Constraint *v35; // ecx
  hk_Local_Constraint_System *m_HkLCS; // ecx
  IVP_Real_Object *angular_velocity; // [esp+0h] [ebp-F4h]
  IVP_Real_Object *angular_velocitya; // [esp+0h] [ebp-F4h]
  int v40; // [esp+10h] [ebp-E4h] BYREF
  int v41; // [esp+14h] [ebp-E0h]
  int v42; // [esp+18h] [ebp-DCh]
  hk_Hinge_BP_Builder builder; // [esp+1Ch] [ebp-D8h] BYREF
  int v44; // [esp+A4h] [ebp-50h]
  IVP_U_Point v45; // [esp+A8h] [ebp-4Ch] BYREF
  float v46; // [esp+B8h] [ebp-3Ch] BYREF
  int v47; // [esp+BCh] [ebp-38h]
  float w; // [esp+C0h] [ebp-34h] BYREF
  hk_Local_Constraint_System_BP v49; // [esp+C4h] [ebp-30h]
  int v50; // [esp+DCh] [ebp-18h]
  hk_Local_Constraint_System *v51; // [esp+E0h] [ebp-14h]
  bool v52; // [esp+E7h] [ebp-Dh]
  int v53; // [esp+E8h] [ebp-Ch]
  hk_Local_Constraint_System *lcs; // [esp+ECh] [ebp-8h]
  hk_Local_Constraint_System *retaddr; // [esp+F4h] [ebp+0h]

  v53 = a2;
  lcs = retaddr;
  this->m_constraintType = 2;
  forceLimit = hinge->constraint.forceLimit;
  v52 = forceLimit != 0.0 && forceLimit < 1.0e12
     || (torqueLimit = hinge->constraint.torqueLimit) != 0.0 && torqueLimit < 1.0e12
     || (v10 = hinge->constraint.bodyMassScale[0]) != 1.0 && v10 != 0.0
     || (v11 = hinge->constraint.bodyMassScale[1]) != 1.0 && v11 != 0.0;
  m_pObjAttached = this->m_pObjAttached;
  y = hinge->worldAxisDirection.y;
  builder.m_hinge_bp.m_tau = 0.0;
  builder.m_hinge_bp.m_strength = 0.0;
  memset(&builder.m_hinge_bp.m_limit.m_limit_min, 0, 20);
  memset(&builder.m_hinge_bp.m_axis_os[0].m_origin.y, 0, 12);
  memset(&builder.m_hinge_bp.m_axis_os[0].m_direction.y, 0, 12);
  memset(&builder.m_hinge_bp.m_axis_os[1].m_origin.y, 0, 12);
  memset(&builder.m_hinge_bp.m_axis_os[1].m_direction.y, 0, 12);
  memset(&builder.m_hinge_bp.m_axis_perp_os[0].y, 0, 12);
  LODWORD(v14) = LODWORD(hinge->worldAxisDirection.z) ^ _mask__NegFloat_;
  *(_DWORD *)&builder.m_hinge_bp.m_limit.m_limit_is_enabled = 1065353216;
  v41 = 1065353216;
  v40 = 1065353216;
  x = hinge->worldAxisDirection.x;
  m_pObjReference = this->m_pObjReference;
  LOWORD(v42) = 0;
  v45.k[0] = x;
  v45.k[1] = v14;
  v45.k[2] = y;
  hk_Hinge_BP_Builder::set_axis_ws(
    this: (hk_Hinge_BP_Builder *)&v40,
    a: (hk_Rigid_Body *)m_pObjReference->m_pObject,
    b: (hk_Rigid_Body *)m_pObjAttached->m_pObject,
    axis_ws: (const hk_Vector3 *)&v45);
  z = hinge->worldPosition.z;
  angular_velocity = this->m_pObjReference->m_pObject;
  v18 = hinge->worldPosition.y * g_PhysicsUnits.unitScaleMeters;
  v45.k[0] = hinge->worldPosition.x * g_PhysicsUnits.unitScaleMeters;
  LODWORD(v45.k[1]) = COERCE_UNSIGNED_INT(z * g_PhysicsUnits.unitScaleMeters) ^ _mask__NegFloat_;
  v45.k[2] = v18;
  TransformIVPToLocal(
    pointIn: &v45,
    pointOut: (IVP_U_Point *)&builder.m_hinge_bp.m_axis_perp_os[1].w,
    pObject: angular_velocity,
    translate: true);
  w = builder.m_hinge_bp.m_axis_perp_os[1].w;
  *(_QWORD *)&v49.m_damp = *(_QWORD *)builder.m_hinge_bp.m_bodies;
  hk_Hinge_BP_Builder::set_position_os(
    this: (hk_Hinge_BP_Builder *)&v40,
    body_index: 0,
    position: (const hk_Vector3 *)&w);
  v19 = hinge->worldPosition.z;
  angular_velocitya = this->m_pObjAttached->m_pObject;
  v20 = hinge->worldPosition.y * g_PhysicsUnits.unitScaleMeters;
  v46 = hinge->worldPosition.x * g_PhysicsUnits.unitScaleMeters;
  v47 = COERCE_UNSIGNED_INT(v19 * g_PhysicsUnits.unitScaleMeters) ^ _mask__NegFloat_;
  w = v20;
  TransformIVPToLocal(
    pointIn: (const IVP_U_Point *)&v46,
    pointOut: (IVP_U_Point *)&builder.m_hinge_bp.m_axis_perp_os[1].w,
    pObject: angular_velocitya,
    translate: true);
  *(_QWORD *)v45.k = *(_QWORD *)&builder.m_hinge_bp.m_axis_perp_os[1].w;
  LODWORD(v45.k[2]) = builder.m_hinge_bp.m_bodies[1];
  hk_Hinge_BP_Builder::set_position_os(
    this: (hk_Hinge_BP_Builder *)&v40,
    body_index: 1,
    position: (const hk_Vector3 *)&v45);
  LODWORD(v21) = LODWORD(hinge->referencePerpAxisDirection.z) ^ _mask__NegFloat_;
  v22 = hinge->referencePerpAxisDirection.y;
  w = hinge->referencePerpAxisDirection.x;
  v49.m_damp = v21;
  v49.m_tau = v22;
  hk_Hinge_BP_Builder::set_axis_perp_os(this: (hk_Hinge_BP_Builder *)&v40, body: 0, axis_os: (const hk_Vector3 *)&w);
  LODWORD(v23) = LODWORD(hinge->attachedPerpAxisDirection.z) ^ _mask__NegFloat_;
  v24 = hinge->attachedPerpAxisDirection.y;
  w = hinge->attachedPerpAxisDirection.x;
  v49.m_damp = v23;
  v49.m_tau = v24;
  hk_Hinge_BP_Builder::set_axis_perp_os(this: (hk_Hinge_BP_Builder *)&v40, body: 1, axis_os: (const hk_Vector3 *)&w);
  hk_Hinge_BP_Builder::set_tau(this: (hk_Hinge_BP_Builder *)&v40, tau: hinge->constraint.strength);
  torque = hinge->hingeAxis.torque;
  if ( torque != 0.0 )
    hk_Hinge_BP_Builder::set_angular_motor(
      this: (hk_Hinge_BP_Builder *)&v40,
      angular_velocity: hinge->hingeAxis.angularVelocity * 0.017453292,
      max_torque: torque * 0.017453292);
  minRotation = hinge->hingeAxis.minRotation;
  maxRotation = hinge->hingeAxis.maxRotation;
  if ( minRotation != maxRotation )
    hk_Hinge_BP_Builder::set_angular_limits(
      this: (hk_Hinge_BP_Builder *)&v40,
      lower: minRotation * 0.017453292,
      upper: maxRotation * 0.017453292);
  if ( constraint_group != nullptr )
    m_pLCS = constraint_group->m_pLCS;
  else
    m_pLCS = nullptr;
  v51 = m_pLCS;
  if ( m_pLCS == nullptr )
  {
    LOBYTE(v49.m_n_iterations) = 1;
    LODWORD(v49.m_damp) = 1;
    v46 = 1.0;
    v47 = 1065353216;
    w = 0.0;
    v49.m_tau = 0.029999999;
    v29 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 131);
    if ( v29 != nullptr )
    {
      v30 = (hk_Local_Constraint_System *)(((unsigned int)v29 + 19) & 0xFFFFFFF0);
      *((_DWORD *)&v30[-1].m_client_data + 3) = v29;
      v51 = hk_Local_Constraint_System::hk_Local_Constraint_System(
              this: v30,
              env: pEnvironment,
              bp: (hk_Local_Constraint_System_BP *)&v46);
    }
    else
    {
      v51 = nullptr;
    }
    this->m_HkLCS = v51;
  }
  v31 = ((int (__thiscall *)(IMemAlloc *, int, int, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, unsigned int, unsigned int, int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD, int, int, _DWORD, _DWORD, int, hk_Local_Constraint_System *))_g_pMemAlloc->Alloc_2)(
          a1: _g_pMemAlloc,
          a2: 175,
          a3,
          a4,
          a5: v40,
          a6: v41,
          a7: v42,
          a8: LODWORD(builder.m_hinge_bp.m_tau),
          a9: LODWORD(builder.m_hinge_bp.m_strength),
          a10: *(_DWORD *)&builder.m_hinge_bp.m_limit.m_limit_is_enabled,
          a11: LODWORD(builder.m_hinge_bp.m_limit.m_limit_min),
          a12: LODWORD(builder.m_hinge_bp.m_limit.m_limit_max),
          a13: LODWORD(builder.m_hinge_bp.m_limit.m_limit_tau),
          a14: LODWORD(builder.m_hinge_bp.m_limit.m_joint_friction),
          a15: LODWORD(builder.m_hinge_bp.m_limit.m_desired_velocity),
          a16: LODWORD(builder.m_hinge_bp.m_axis_os[0].m_origin.x),
          a17: LODWORD(builder.m_hinge_bp.m_axis_os[0].m_origin.y),
          a18: LODWORD(builder.m_hinge_bp.m_axis_os[0].m_origin.z),
          a19: LODWORD(builder.m_hinge_bp.m_axis_os[0].m_origin.w),
          a20: LODWORD(builder.m_hinge_bp.m_axis_os[0].m_direction.x),
          a21: LODWORD(builder.m_hinge_bp.m_axis_os[0].m_direction.y),
          a22: LODWORD(builder.m_hinge_bp.m_axis_os[0].m_direction.z),
          a23: LODWORD(builder.m_hinge_bp.m_axis_os[0].m_direction.w),
          a24: LODWORD(builder.m_hinge_bp.m_axis_os[1].m_origin.x),
          a25: LODWORD(builder.m_hinge_bp.m_axis_os[1].m_origin.y),
          a26: LODWORD(builder.m_hinge_bp.m_axis_os[1].m_origin.z),
          a27: LODWORD(builder.m_hinge_bp.m_axis_os[1].m_origin.w),
          a28: LODWORD(builder.m_hinge_bp.m_axis_os[1].m_direction.x),
          a29: LODWORD(builder.m_hinge_bp.m_axis_os[1].m_direction.y),
          a30: LODWORD(builder.m_hinge_bp.m_axis_os[1].m_direction.z),
          a31: LODWORD(builder.m_hinge_bp.m_axis_os[1].m_direction.w),
          a32: LODWORD(builder.m_hinge_bp.m_axis_perp_os[0].x),
          a33: LODWORD(builder.m_hinge_bp.m_axis_perp_os[0].y),
          a34: LODWORD(builder.m_hinge_bp.m_axis_perp_os[0].z),
          a35: LODWORD(builder.m_hinge_bp.m_axis_perp_os[0].w),
          a36: LODWORD(builder.m_hinge_bp.m_axis_perp_os[1].x),
          a37: LODWORD(builder.m_hinge_bp.m_axis_perp_os[1].y),
          a38: LODWORD(builder.m_hinge_bp.m_axis_perp_os[1].z),
          a39: LODWORD(builder.m_hinge_bp.m_axis_perp_os[1].w),
          a40: builder.m_hinge_bp.m_bodies[0],
          a41: builder.m_hinge_bp.m_bodies[1],
          a42: v44,
          a43: LODWORD(v45.k[0]),
          a44: LODWORD(v45.k[1]),
          a45: LODWORD(v45.k[2]),
          a46: LODWORD(v45.hesse_val),
          a47: LODWORD(v46),
          a48: v47,
          a49: LODWORD(w),
          a50: LODWORD(v49.m_damp),
          a51: LODWORD(v49.m_tau),
          a52: v49.m_n_iterations,
          a53: v49.m_minErrorTicks,
          a54: LODWORD(v49.m_errorTolerance),
          a55: *(_DWORD *)&v49.m_active,
          a56: v50,
          a57: v51);
  if ( v52 )
  {
    if ( v31 != 0 )
    {
      v32 = (hk_Hinge_Constraint *)((v31 + 19) & 0xFFFFFFF0);
      LODWORD(v32[-1].m_limit.m_ref_position) = v31;
      v33 = hk_Hinge_Constraint::hk_Hinge_Constraint(
              this: v32,
              env: pEnvironment,
              bp: (const hk_Hinge_BP *)&v40,
              a: (hk_Rigid_Body *)this->m_pObjReference->m_pObject,
              b: (hk_Rigid_Body *)this->m_pObjAttached->m_pObject);
    }
    else
    {
      v33 = nullptr;
    }
    BreakableConstraint = CPhysicsConstraint::CreateBreakableConstraint(
                            this,
                            pRealConstraint: v33,
                            pLcs: (hk_Local_Constraint_System *)&hinge->constraint,
                            constraint: &hinge->constraint);
  }
  else if ( v31 != 0 )
  {
    v35 = (hk_Hinge_Constraint *)((v31 + 19) & 0xFFFFFFF0);
    LODWORD(v35[-1].m_limit.m_ref_position) = v31;
    BreakableConstraint = (hk_Breakable_Constraint *)hk_Hinge_Constraint::hk_Hinge_Constraint(
                                                       this: v35,
                                                       constraint_system: (hk_Local_Constraint_System *)this->m_pObjAttached->m_pObject,
                                                       bp: (const hk_Hinge_BP *)&v40,
                                                       a: (hk_Rigid_Body *)this->m_pObjReference->m_pObject,
                                                       b: (hk_Rigid_Body *)this->m_pObjAttached->m_pObject);
  }
  else
  {
    BreakableConstraint = nullptr;
  }
  m_HkLCS = this->m_HkLCS;
  this->m_HkConstraint = BreakableConstraint;
  if ( m_HkLCS != nullptr )
  {
    if ( hinge->constraint.isActive )
      hk_Local_Constraint_System::activate(this: m_HkLCS);
    this->m_HkConstraint->m_client_data = this;
  }
  else
  {
    this->m_HkConstraint->m_client_data = this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C8C0
// Name: public: void CPhysicsConstraint::InitFixed(class IVP_Environment __near *,class CPhysicsConstraintGroup __near *,struct constraint_fixedparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CPhysicsConstraint::InitFixed(
        CPhysicsConstraint *this@<ecx>,
        float a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        hk_Environment *pEnvironment,
        CPhysicsConstraintGroup *constraint_group,
        const constraint_fixedparams_t *fixed)
{
  float forceLimit; // xmm0_4
  float torqueLimit; // xmm0_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  float strength; // xmm1_4
  hk_Local_Constraint_System *m_pLCS; // edi
  void *v14; // eax
  hk_Local_Constraint_System *v15; // ecx
  int v16; // eax
  hk_Fixed_Constraint *v17; // ecx
  hk_Fixed_Constraint *v18; // eax
  hk_Breakable_Constraint *BreakableConstraint; // eax
  int v20; // eax
  hk_Fixed_Constraint *v21; // ecx
  hk_Local_Constraint_System *m_HkLCS; // ecx
  IVP_U_Matrix v25; // [esp-4Ch] [ebp-BCh] BYREF
  _DWORD v26[3]; // [esp-Ch] [ebp-7Ch] BYREF
  hk_Fixed_BP fixed_bp; // [esp+0h] [ebp-70h] BYREF
  int v28; // [esp+50h] [ebp-20h]
  hk_Local_Constraint_System_BP v29; // [esp+54h] [ebp-1Ch]
  _UNKNOWN *retaddr; // [esp+70h] [ebp+0h]

  v29.m_errorTolerance = a2;
  *(_DWORD *)&v29.m_active = retaddr;
  this->m_constraintType = 3;
  forceLimit = fixed->constraint.forceLimit;
  HIBYTE(v29.m_minErrorTicks) = forceLimit != 0.0 && forceLimit < 1.0e12
                             || (torqueLimit = fixed->constraint.torqueLimit) != 0.0 && torqueLimit < 1.0e12
                             || (v10 = fixed->constraint.bodyMassScale[0]) != 1.0 && v10 != 0.0
                             || (v11 = fixed->constraint.bodyMassScale[1]) != 1.0 && v11 != 0.0;
  fixed_bp.m_transform_os_ks.m_translation.y = 1.0;
  fixed_bp.m_transform_os_ks.m_translation.z = 1.0;
  hk_Transform::set_identity_transform(this: (hk_Transform *)v26);
  ConvertMatrixToIVP(matrix: &fixed->attachedRefXform, out: &v25);
  v26[0] = LODWORD(v25.rows[0].k[0]);
  v26[1] = LODWORD(v25.rows[1].k[0]);
  fixed_bp.m_transform_os_ks.m_elems[1] = v25.rows[0].k[1];
  v26[2] = LODWORD(v25.rows[2].k[0]);
  fixed_bp.m_transform_os_ks.m_elems[2] = v25.rows[1].k[1];
  fixed_bp.m_transform_os_ks.m_elems[0] = 0.0;
  fixed_bp.m_transform_os_ks.m_elems[3] = v25.rows[2].k[1];
  fixed_bp.m_transform_os_ks.m_elems[4] = 0.0;
  fixed_bp.m_transform_os_ks.m_elems[8] = 0.0;
  fixed_bp.m_transform_os_ks.m_elems[5] = v25.rows[0].k[2];
  fixed_bp.m_transform_os_ks.m_elems[9] = v25.vv.k[0];
  fixed_bp.m_transform_os_ks.m_elems[6] = v25.rows[1].k[2];
  fixed_bp.m_transform_os_ks.m_elems[10] = v25.vv.k[1];
  fixed_bp.m_transform_os_ks.m_elems[7] = v25.rows[2].k[2];
  strength = fixed->constraint.strength;
  fixed_bp.m_transform_os_ks.m_elems[11] = v25.vv.k[2];
  fixed_bp.m_transform_os_ks.m_translation.x = 1.0;
  fixed_bp.m_transform_os_ks.m_translation.z = strength;
  if ( constraint_group != nullptr )
    m_pLCS = constraint_group->m_pLCS;
  else
    m_pLCS = nullptr;
  if ( m_pLCS == nullptr )
  {
    LOBYTE(v29.m_n_iterations) = 1;
    LODWORD(v29.m_damp) = 1;
    fixed_bp.m_bodies[0] = 1065353216;
    fixed_bp.m_bodies[1] = 1065353216;
    v28 = 0;
    v29.m_tau = 0.029999999;
    v14 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 131);
    if ( v14 != nullptr )
    {
      v15 = (hk_Local_Constraint_System *)(((unsigned int)v14 + 19) & 0xFFFFFFF0);
      *((_DWORD *)&v15[-1].m_client_data + 3) = v14;
      m_pLCS = hk_Local_Constraint_System::hk_Local_Constraint_System(
                 this: v15,
                 env: pEnvironment,
                 bp: (hk_Local_Constraint_System_BP *)fixed_bp.m_bodies);
    }
    else
    {
      m_pLCS = nullptr;
    }
    this->m_HkLCS = m_pLCS;
  }
  if ( HIBYTE(v29.m_minErrorTicks) != 0 )
  {
    v16 = ((int (__thiscall *)(IMemAlloc *, int, int, int))_g_pMemAlloc->Alloc_2)(a1: _g_pMemAlloc, a2: 131, a3, a4);
    if ( v16 != 0 )
    {
      v17 = (hk_Fixed_Constraint *)((v16 + 19) & 0xFFFFFFF0);
      *((_DWORD *)&v17[-1].m_tau + 2) = v16;
      v18 = hk_Fixed_Constraint::hk_Fixed_Constraint(
              this: v17,
              env: pEnvironment,
              bp: (const hk_Fixed_BP *)v26,
              a: (hk_Rigid_Body *)this->m_pObjReference->m_pObject,
              b: (hk_Rigid_Body *)this->m_pObjAttached->m_pObject);
      BreakableConstraint = CPhysicsConstraint::CreateBreakableConstraint(
                              this,
                              pRealConstraint: v18,
                              pLcs: m_pLCS,
                              constraint: &fixed->constraint);
    }
    else
    {
      BreakableConstraint = CPhysicsConstraint::CreateBreakableConstraint(
                              this,
                              pRealConstraint: nullptr,
                              pLcs: m_pLCS,
                              constraint: &fixed->constraint);
    }
  }
  else
  {
    v20 = ((int (__thiscall *)(IMemAlloc *, int, int, int))_g_pMemAlloc->Alloc_2)(a1: _g_pMemAlloc, a2: 131, a3, a4);
    if ( v20 != 0 )
    {
      v21 = (hk_Fixed_Constraint *)((v20 + 19) & 0xFFFFFFF0);
      *((_DWORD *)&v21[-1].m_tau + 2) = v20;
      BreakableConstraint = (hk_Breakable_Constraint *)hk_Fixed_Constraint::hk_Fixed_Constraint(
                                                         this: v21,
                                                         constraint_system: m_pLCS,
                                                         bp: (const hk_Fixed_BP *)v26,
                                                         a: (hk_Rigid_Body *)this->m_pObjReference->m_pObject,
                                                         b: (hk_Rigid_Body *)this->m_pObjAttached->m_pObject);
    }
    else
    {
      BreakableConstraint = nullptr;
    }
  }
  m_HkLCS = this->m_HkLCS;
  this->m_HkConstraint = BreakableConstraint;
  if ( m_HkLCS != nullptr )
  {
    if ( fixed->constraint.isActive )
      hk_Local_Constraint_System::activate(this: m_HkLCS);
    this->m_HkConstraint->m_client_data = this;
  }
  else
  {
    this->m_HkConstraint->m_client_data = this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CBA0
// Name: public: void CPhysicsConstraint::InitSliding(class IVP_Environment __near *,class CPhysicsConstraintGroup __near *,struct constraint_slidingparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CPhysicsConstraint::InitSliding(
        CPhysicsConstraint *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        hk_Environment *pEnvironment,
        CPhysicsConstraintGroup *constraint_group,
        const constraint_slidingparams_t *sliding)
{
  float forceLimit; // xmm2_4
  float torqueLimit; // xmm2_4
  float v10; // xmm2_4
  float v11; // xmm2_4
  float x; // xmm1_4
  float y; // xmm2_4
  float strength; // xmm0_4
  float limitMin; // xmm1_4
  float limitMax; // xmm2_4
  float v17; // xmm0_4
  char v18; // dl
  bool v19; // cl
  float v20; // xmm6_4
  float v21; // xmm7_4
  float v22; // xmm3_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float friction; // xmm1_4
  float velocity; // xmm2_4
  float v27; // xmm1_4
  hk_Local_Constraint_System *m_pLCS; // edi
  void *v29; // eax
  hk_Local_Constraint_System *v30; // ecx
  int v31; // eax
  hk_Prismatic_Constraint *v32; // ecx
  hk_Prismatic_Constraint *v33; // eax
  hk_Breakable_Constraint *BreakableConstraint; // eax
  int v35; // eax
  hk_Prismatic_Constraint *v36; // ecx
  hk_Local_Constraint_System *m_HkLCS; // ecx
  IVP_U_Matrix v40; // [esp-4Ch] [ebp-10Ch] BYREF
  _DWORD v41[3]; // [esp-Ch] [ebp-CCh] BYREF
  hk_Transform t; // [esp+0h] [ebp-C0h] BYREF
  hk_Local_Constraint_System_BP v43; // [esp+40h] [ebp-80h] BYREF
  hk_Prismatic_BP prismatic_bp; // [esp+58h] [ebp-68h] BYREF
  int v45; // [esp+B4h] [ebp-Ch]
  void *v46; // [esp+B8h] [ebp-8h]
  void *retaddr; // [esp+C0h] [ebp+0h]

  v45 = a2;
  v46 = retaddr;
  this->m_constraintType = 5;
  forceLimit = sliding->constraint.forceLimit;
  HIBYTE(prismatic_bp.m_limit.m_ref_position) = forceLimit != 0.0 && forceLimit < 1.0e12
                                             || (torqueLimit = sliding->constraint.torqueLimit) != 0.0
                                             && torqueLimit < 1.0e12
                                             || (v10 = sliding->constraint.bodyMassScale[0]) != 1.0 && v10 != 0.0
                                             || (v11 = sliding->constraint.bodyMassScale[1]) != 1.0 && v11 != 0.0;
  LOWORD(prismatic_bp.m_axis_Ros.y) = 0;
  prismatic_bp.m_axis_Ros.z = 0.0;
  prismatic_bp.m_axis_Ros.w = 0.0;
  *(_DWORD *)&prismatic_bp.m_limit.m_limit_is_enabled = 1065353216;
  memset(&prismatic_bp.m_limit.m_limit_min, 0, 12);
  prismatic_bp.m_transform_Ros_Aos.m_translation.y = 1.0;
  prismatic_bp.m_transform_Ros_Aos.m_translation.z = 1.0;
  *(_DWORD *)&v43.m_active = 0;
  prismatic_bp.m_bodies[0] = 0;
  prismatic_bp.m_bodies[1] = 0;
  prismatic_bp.m_transform_Ros_Aos.m_rotation.x = 1.0;
  memset(&prismatic_bp.m_transform_Ros_Aos.m_rotation.y, 0, 12);
  prismatic_bp.m_transform_Ros_Aos.m_translation.w = 1.0;
  prismatic_bp.m_strength = 0.0;
  prismatic_bp.m_tau = 0.0;
  ConvertMatrixToIVP(matrix: &sliding->attachedRefXform, out: &v40);
  t.m_elems[1] = v40.rows[0].k[1];
  t.m_elems[2] = v40.rows[1].k[1];
  v41[0] = LODWORD(v40.rows[0].k[0]);
  t.m_elems[3] = v40.rows[2].k[1];
  v41[1] = LODWORD(v40.rows[1].k[0]);
  t.m_elems[5] = v40.rows[0].k[2];
  v41[2] = LODWORD(v40.rows[2].k[0]);
  t.m_elems[6] = v40.rows[1].k[2];
  t.m_elems[0] = 0.0;
  t.m_elems[4] = 0.0;
  t.m_elems[7] = v40.rows[2].k[2];
  t.m_elems[8] = 0.0;
  t.m_elems[9] = v40.vv.k[0];
  t.m_elems[10] = v40.vv.k[1];
  t.m_elems[11] = v40.vv.k[2];
  t.m_translation.x = 1.0;
  prismatic_bp.m_transform_Ros_Aos.m_rotation.y = v40.vv.k[0];
  prismatic_bp.m_transform_Ros_Aos.m_rotation.z = v40.vv.k[1];
  prismatic_bp.m_transform_Ros_Aos.m_rotation.w = v40.vv.k[2];
  hk_Quaternion::set(this: (hk_Quaternion *)&v43.m_active, r: (const hk_Rotation *)v41);
  x = sliding->slideAxisRef.x;
  y = sliding->slideAxisRef.y;
  LODWORD(prismatic_bp.m_strength) = LODWORD(sliding->slideAxisRef.z) ^ _mask__NegFloat_;
  strength = sliding->constraint.strength;
  prismatic_bp.m_transform_Ros_Aos.m_translation.w = x;
  limitMin = sliding->limitMin;
  prismatic_bp.m_tau = y;
  limitMax = sliding->limitMax;
  prismatic_bp.m_transform_Ros_Aos.m_translation.z = strength;
  v17 = 0.0;
  v18 = 0;
  v19 = false;
  v20 = 0.0;
  v21 = 0.0;
  v22 = 0.0;
  if ( limitMin != limitMax )
  {
    v23 = limitMin * g_PhysicsUnits.unitScaleMeters;
    v24 = limitMax * g_PhysicsUnits.unitScaleMeters;
    if ( fabs(v23 + 3.1415927) > 0.000099999997 || fabs(v24 - 3.1415927) > 0.000099999997 )
      v18 = 1;
    v20 = v23;
    v21 = v24;
  }
  friction = sliding->friction;
  if ( friction != 0.0 )
  {
    velocity = sliding->velocity;
    v27 = friction * g_PhysicsUnits.unitScaleMeters;
    v19 = v27 != 0.0;
    if ( velocity != 0.0 )
      v17 = velocity * g_PhysicsUnits.unitScaleMeters;
    v22 = fabs(v27);
  }
  LOBYTE(prismatic_bp.m_axis_Ros.y) = v18;
  BYTE1(prismatic_bp.m_axis_Ros.y) = v19;
  prismatic_bp.m_axis_Ros.z = v20;
  prismatic_bp.m_axis_Ros.w = v21;
  *(_DWORD *)&prismatic_bp.m_limit.m_limit_is_enabled = 1065353216;
  prismatic_bp.m_limit.m_limit_min = fabs(v22);
  prismatic_bp.m_limit.m_limit_max = v17;
  if ( constraint_group != nullptr )
    m_pLCS = constraint_group->m_pLCS;
  else
    m_pLCS = nullptr;
  if ( m_pLCS == nullptr )
  {
    t.m_translation.y = 1.0;
    t.m_translation.z = 1.0;
    LOBYTE(v43.m_n_iterations) = 1;
    t.m_translation.w = 0.0;
    v43.m_tau = 0.029999999;
    LODWORD(v43.m_damp) = 1;
    v29 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 131);
    if ( v29 != nullptr )
    {
      v30 = (hk_Local_Constraint_System *)(((unsigned int)v29 + 19) & 0xFFFFFFF0);
      *((_DWORD *)&v30[-1].m_client_data + 3) = v29;
      m_pLCS = hk_Local_Constraint_System::hk_Local_Constraint_System(
                 this: v30,
                 env: pEnvironment,
                 bp: (hk_Local_Constraint_System_BP *)&t.m_translation.y);
    }
    else
    {
      m_pLCS = nullptr;
    }
    this->m_HkLCS = m_pLCS;
  }
  if ( HIBYTE(prismatic_bp.m_limit.m_ref_position) != 0 )
  {
    v31 = ((int (__thiscall *)(IMemAlloc *, int, int, int))_g_pMemAlloc->Alloc_2)(a1: _g_pMemAlloc, a2: 147, a3, a4);
    if ( v31 != 0 )
    {
      v32 = (hk_Prismatic_Constraint *)((v31 + 19) & 0xFFFFFFF0);
      LODWORD(v32[-1].m_transform_Ros_Aos.m_translation.w) = v31;
      v33 = hk_Prismatic_Constraint::hk_Prismatic_Constraint(
              this: v32,
              env: pEnvironment,
              bp: (const hk_Prismatic_BP *)&v43.m_minErrorTicks,
              a: (hk_Rigid_Body *)this->m_pObjReference->m_pObject,
              b: (hk_Rigid_Body *)this->m_pObjAttached->m_pObject);
      BreakableConstraint = CPhysicsConstraint::CreateBreakableConstraint(
                              this,
                              pRealConstraint: v33,
                              pLcs: m_pLCS,
                              constraint: &sliding->constraint);
    }
    else
    {
      BreakableConstraint = CPhysicsConstraint::CreateBreakableConstraint(
                              this,
                              pRealConstraint: nullptr,
                              pLcs: m_pLCS,
                              constraint: &sliding->constraint);
    }
  }
  else
  {
    v35 = ((int (__thiscall *)(IMemAlloc *, int, int, int))_g_pMemAlloc->Alloc_2)(a1: _g_pMemAlloc, a2: 147, a3, a4);
    if ( v35 != 0 )
    {
      v36 = (hk_Prismatic_Constraint *)((v35 + 19) & 0xFFFFFFF0);
      LODWORD(v36[-1].m_transform_Ros_Aos.m_translation.w) = v35;
      BreakableConstraint = (hk_Breakable_Constraint *)hk_Prismatic_Constraint::hk_Prismatic_Constraint(
                                                         this: v36,
                                                         constraint_system: m_pLCS,
                                                         bp: (const hk_Prismatic_BP *)&v43.m_minErrorTicks,
                                                         a: (hk_Rigid_Body *)this->m_pObjReference->m_pObject,
                                                         b: (hk_Rigid_Body *)this->m_pObjAttached->m_pObject);
    }
    else
    {
      BreakableConstraint = nullptr;
    }
  }
  m_HkLCS = this->m_HkLCS;
  this->m_HkConstraint = BreakableConstraint;
  if ( m_HkLCS != nullptr )
  {
    if ( sliding->constraint.isActive )
      hk_Local_Constraint_System::activate(this: m_HkLCS);
    this->m_HkConstraint->m_client_data = this;
  }
  else
  {
    this->m_HkConstraint->m_client_data = this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D030
// Name: public: virtual void CPhysicsConstraint::UpdateRagdollTransforms(struct matrix3x4_t const __near &,struct matrix3x4_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysicsConstraint::UpdateRagdollTransforms(
        CPhysicsConstraint *this@<ecx>,
        int a2@<ebp>,
        const matrix3x4_t *constraintToReference,
        const matrix3x4_t *constraintToAttached)
{
  bool v5; // zf
  hk_Breakable_Constraint *m_HkConstraint; // ecx
  hk_Breakable_Constraint_BP v7; // [esp-28h] [ebp-E8h] BYREF
  _DWORD v8[3]; // [esp-Ch] [ebp-CCh] BYREF
  hk_Transform os_ks_0; // [esp+0h] [ebp-C0h] BYREF
  hk_Transform os_ks_1; // [esp+40h] [ebp-80h] BYREF
  float v11; // [esp+84h] [ebp-3Ch]
  float v12; // [esp+88h] [ebp-38h]
  float v13; // [esp+8Ch] [ebp-34h]
  float v14; // [esp+94h] [ebp-2Ch]
  float v15; // [esp+98h] [ebp-28h]
  float v16; // [esp+9Ch] [ebp-24h]
  float v17; // [esp+A4h] [ebp-1Ch]
  float v18; // [esp+A8h] [ebp-18h]
  float v19; // [esp+ACh] [ebp-14h]
  int v20; // [esp+B4h] [ebp-Ch]
  void *v21; // [esp+B8h] [ebp-8h]
  void *retaddr; // [esp+C0h] [ebp+0h]

  v20 = a2;
  v21 = retaddr;
  if ( this->m_constraintType == 1 )
  {
    ConvertMatrixToIVP(matrix: constraintToReference, out: (IVP_U_Matrix *)&os_ks_1.m_translation.y);
    v8[0] = LODWORD(os_ks_1.m_translation.y);
    *(float *)&v8[1] = v11;
    *(float *)&v8[2] = v14;
    os_ks_0.m_elems[1] = os_ks_1.m_translation.z;
    os_ks_0.m_elems[0] = 0.0;
    os_ks_0.m_elems[2] = v12;
    os_ks_0.m_elems[4] = 0.0;
    os_ks_0.m_elems[8] = 0.0;
    os_ks_0.m_elems[3] = v15;
    os_ks_0.m_elems[9] = v17;
    os_ks_0.m_elems[5] = os_ks_1.m_translation.w;
    os_ks_0.m_elems[10] = v18;
    os_ks_0.m_elems[6] = v13;
    os_ks_0.m_elems[11] = v19;
    os_ks_0.m_elems[7] = v16;
    os_ks_0.m_translation.x = 1.0;
    ConvertMatrixToIVP(matrix: constraintToAttached, out: (IVP_U_Matrix *)&os_ks_1.m_translation.y);
    os_ks_1.m_elems[1] = os_ks_1.m_translation.z;
    os_ks_1.m_elems[2] = v12;
    os_ks_1.m_elems[3] = v15;
    os_ks_1.m_elems[5] = os_ks_1.m_translation.w;
    os_ks_1.m_elems[6] = v13;
    os_ks_1.m_elems[7] = v16;
    os_ks_0.m_translation.y = os_ks_1.m_translation.y;
    os_ks_1.m_elems[9] = v17;
    os_ks_0.m_translation.z = v11;
    os_ks_1.m_elems[10] = v18;
    v5 = this->m_isBreakable == 0;
    os_ks_0.m_translation.w = v14;
    os_ks_1.m_elems[11] = v19;
    os_ks_1.m_elems[0] = 0.0;
    os_ks_1.m_elems[4] = 0.0;
    os_ks_1.m_elems[8] = 0.0;
    os_ks_1.m_translation.x = 1.0;
    m_HkConstraint = (hk_Breakable_Constraint *)this->m_HkConstraint;
    if ( !v5 )
    {
      memset(&v7, 0, 12);
      v7.m_bodyMassScale[0] = 1.0;
      v7.m_bodyMassScale[1] = 1.0;
      hk_Breakable_Constraint::write_to_blueprint(this: m_HkConstraint, pOutBP: &v7);
      m_HkConstraint = (hk_Breakable_Constraint *)v7.m_real_constraint;
    }
    hk_Ragdoll_Constraint::update_transforms(
      this: (hk_Ragdoll_Constraint *)m_HkConstraint,
      os_ks_0: (const hk_Transform *)v8,
      os_ks_1: (hk_Transform *)&os_ks_0.m_translation.y);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D240
// Name: public: virtual bool CPhysicsConstraint::GetConstraintTransform(struct matrix3x4_t __near *,struct matrix3x4_t __near *)const
// Source: json
//------------------------------------------------------------------------------
char __userpurge CPhysicsConstraint::GetConstraintTransform@<al>(
        CPhysicsConstraint *this@<ecx>,
        float a2@<ebp>,
        matrix3x4_t *pConstraintToReference,
        matrix3x4_t *pConstraintToAttached)
{
  __int16 m_constraintType; // ax
  hk_Breakable_Constraint *v5; // ecx
  float *v6; // esi
  hk_Breakable_Constraint *m_HkConstraint; // ecx
  float *m_real_constraint; // esi
  float v10; // xmm1_4
  float v11; // xmm2_4
  hk_Constraint *RealConstraint; // esi
  IVP_U_Matrix v13; // [esp-70h] [ebp-7Ch] BYREF
  hk_Breakable_Constraint_BP v14; // [esp-28h] [ebp-34h] BYREF
  Vector v15; // [esp-Ch] [ebp-18h] BYREF
  Vector pos; // [esp+0h] [ebp-Ch] BYREF
  float retaddr; // [esp+Ch] [ebp+0h]

  pos.x = a2;
  pos.y = retaddr;
  m_constraintType = this->m_constraintType;
  if ( m_constraintType != 1 )
  {
    if ( m_constraintType == 4 )
    {
      if ( this->m_isBreakable != 0 )
      {
        m_HkConstraint = (hk_Breakable_Constraint *)this->m_HkConstraint;
        memset(&v14, 0, 12);
        v14.m_bodyMassScale[0] = 1.0;
        v14.m_bodyMassScale[1] = 1.0;
        hk_Breakable_Constraint::write_to_blueprint(this: m_HkConstraint, pOutBP: &v14);
        m_real_constraint = (float *)v14.m_real_constraint;
      }
      else
      {
        m_real_constraint = (float *)this->m_HkConstraint;
      }
      if ( pConstraintToReference != nullptr )
      {
        v10 = m_real_constraint[8] * g_PhysicsUnits.unitScaleMetersInv;
        LODWORD(v15.z) = COERCE_UNSIGNED_INT(m_real_constraint[7] * g_PhysicsUnits.unitScaleMetersInv)
                       ^ _mask__NegFloat_;
        v15.y = v10;
        v15.x = g_PhysicsUnits.unitScaleMetersInv * m_real_constraint[6];
        AngleMatrix(angles: &vec3_angle, position: &v15, matrix: pConstraintToReference);
      }
      if ( pConstraintToAttached != nullptr )
      {
        v11 = m_real_constraint[11];
        v15.y = m_real_constraint[12] * g_PhysicsUnits.unitScaleMetersInv;
        LODWORD(v15.z) = COERCE_UNSIGNED_INT(v11 * g_PhysicsUnits.unitScaleMetersInv) ^ _mask__NegFloat_;
        v15.x = m_real_constraint[10] * g_PhysicsUnits.unitScaleMetersInv;
        AngleMatrix(angles: &vec3_angle, position: &v15, matrix: pConstraintToAttached);
      }
    }
    else
    {
      if ( m_constraintType != 3 )
        return 0;
      RealConstraint = CPhysicsConstraint::GetRealConstraint(this);
      if ( pConstraintToReference != nullptr )
        ConvertHavanaLocalMatrixToHL(
          a1: COERCE_FLOAT(&pos),
          in: (const hk_Transform *)&RealConstraint[1].m_entities[1],
          hlMatrix: pConstraintToReference);
      if ( pConstraintToAttached != nullptr )
      {
        ConvertHavanaLocalMatrixToHL(
          a1: COERCE_FLOAT(&pos),
          in: (const hk_Transform *)&RealConstraint[1].m_entities[1],
          hlMatrix: pConstraintToAttached);
        return 1;
      }
    }
    return 1;
  }
  if ( this->m_isBreakable != 0 )
  {
    v5 = (hk_Breakable_Constraint *)this->m_HkConstraint;
    memset(&v14, 0, 12);
    v14.m_bodyMassScale[0] = 1.0;
    v14.m_bodyMassScale[1] = 1.0;
    hk_Breakable_Constraint::write_to_blueprint(this: v5, pOutBP: &v14);
    v6 = (float *)v14.m_real_constraint;
  }
  else
  {
    v6 = (float *)this->m_HkConstraint;
  }
  if ( pConstraintToReference != nullptr )
  {
    v13.rows[0].k[0] = v6[8];
    v13.rows[1].k[0] = v6[9];
    v13.rows[2].k[0] = v6[10];
    v13.rows[0].k[1] = v6[12];
    v13.rows[1].k[1] = v6[13];
    v13.rows[2].k[1] = v6[14];
    v13.rows[0].k[2] = v6[16];
    v13.rows[1].k[2] = v6[17];
    v13.rows[2].k[2] = v6[18];
    v13.vv.k[0] = v6[20];
    v13.vv.k[1] = v6[21];
    v13.vv.k[2] = v6[22];
    ConvertMatrixToHL(in: &v13, output: pConstraintToReference);
  }
  if ( pConstraintToAttached != nullptr )
  {
    v13.rows[0].k[0] = v6[24];
    v13.rows[1].k[0] = v6[25];
    v13.rows[2].k[0] = v6[26];
    v13.rows[0].k[1] = v6[28];
    v13.rows[1].k[1] = v6[29];
    v13.rows[2].k[1] = v6[30];
    v13.rows[0].k[2] = v6[32];
    v13.rows[1].k[2] = v6[33];
    v13.rows[2].k[2] = v6[34];
    v13.vv.k[0] = v6[36];
    v13.vv.k[1] = v6[37];
    v13.vv.k[2] = v6[38];
    ConvertMatrixToHL(in: &v13, output: pConstraintToAttached);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000D530
// Name: public: void CPhysicsConstraint::WriteFixed(struct constraint_fixedparams_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysicsConstraint::WriteFixed(
        CPhysicsConstraint *this@<ecx>,
        int a2@<ebp>,
        constraint_fixedparams_t *fixed)
{
  hk_Breakable_Constraint *m_HkConstraint; // ecx
  hk_Fixed_Constraint *m_real_constraint; // edi
  _DWORD v6[3]; // [esp-Ch] [ebp-BCh] BYREF
  hk_Fixed_BP fixed_bp; // [esp+0h] [ebp-B0h] BYREF
  int v8; // [esp+54h] [ebp-5Ch]
  float v9; // [esp+58h] [ebp-58h]
  float v10; // [esp+5Ch] [ebp-54h]
  int v11; // [esp+64h] [ebp-4Ch]
  float v12; // [esp+68h] [ebp-48h]
  float v13; // [esp+6Ch] [ebp-44h]
  float v14; // [esp+74h] [ebp-3Ch]
  float v15; // [esp+78h] [ebp-38h]
  float v16; // [esp+7Ch] [ebp-34h]
  hk_Breakable_Constraint_BP v17; // [esp+88h] [ebp-28h] BYREF
  int v18; // [esp+A4h] [ebp-Ch]
  void *v19; // [esp+A8h] [ebp-8h]
  void *retaddr; // [esp+B0h] [ebp+0h]

  v18 = a2;
  v19 = retaddr;
  if ( this->m_isBreakable != 0 )
  {
    m_HkConstraint = (hk_Breakable_Constraint *)this->m_HkConstraint;
    memset(&v17, 0, 12);
    v17.m_bodyMassScale[0] = 1.0;
    v17.m_bodyMassScale[1] = 1.0;
    hk_Breakable_Constraint::write_to_blueprint(this: m_HkConstraint, pOutBP: &v17);
    m_real_constraint = (hk_Fixed_Constraint *)v17.m_real_constraint;
  }
  else
  {
    m_real_constraint = (hk_Fixed_Constraint *)this->m_HkConstraint;
  }
  CPhysicsConstraint::ReadBreakableConstraint(this, params: &fixed->constraint);
  fixed_bp.m_transform_os_ks.m_translation.y = 1.0;
  fixed_bp.m_transform_os_ks.m_translation.z = 1.0;
  hk_Transform::set_identity_transform(this: (hk_Transform *)v6);
  hk_Fixed_Constraint::write_to_blueprint(this: m_real_constraint, pOutBP: (hk_Fixed_BP *)v6);
  LODWORD(fixed_bp.m_tau) = v6[0];
  v8 = v6[1];
  v11 = v6[2];
  fixed_bp.m_bodies[0] = LODWORD(fixed_bp.m_transform_os_ks.m_elems[1]);
  v9 = fixed_bp.m_transform_os_ks.m_elems[2];
  v12 = fixed_bp.m_transform_os_ks.m_elems[3];
  fixed_bp.m_bodies[1] = LODWORD(fixed_bp.m_transform_os_ks.m_elems[5]);
  v10 = fixed_bp.m_transform_os_ks.m_elems[6];
  v13 = fixed_bp.m_transform_os_ks.m_elems[7];
  v14 = fixed_bp.m_transform_os_ks.m_elems[9];
  v15 = fixed_bp.m_transform_os_ks.m_elems[10];
  v16 = fixed_bp.m_transform_os_ks.m_elems[11];
  ConvertMatrixToHL(in: (const IVP_U_Matrix *)&fixed_bp.m_tau, output: &fixed->attachedRefXform);
}

//------------------------------------------------------------------------------
// Address: 0x1000D680
// Name: public: void CPhysicsConstraint::WriteRagdoll(struct constraint_ragdollparams_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysicsConstraint::WriteRagdoll(
        CPhysicsConstraint *this@<ecx>,
        int a2@<ebp>,
        constraint_ragdollparams_t *ragdoll)
{
  bool v4; // zf
  hk_Breakable_Constraint *v5; // ecx
  constraint_ragdollparams_t *v6; // edi
  int v7; // ecx
  hk_Ragdoll_Constraint *v8; // eax
  int v9; // edx
  float *v10; // esi
  int v11; // eax
  int v12; // edi
  float v13; // xmm0_4
  CPhysicsConstraint *v14; // eax
  float *v15; // edi
  double v16; // st7
  hk_Ragdoll_Constraint *v17; // eax
  _DWORD v18[3]; // [esp-Ch] [ebp-16Ch] BYREF
  hk_Ragdoll_Constraint_BP ragdoll_bp; // [esp+0h] [ebp-160h] BYREF
  int v20; // [esp+E0h] [ebp-80h]
  int v21; // [esp+E4h] [ebp-7Ch]
  int v22; // [esp+E8h] [ebp-78h]
  int v23; // [esp+ECh] [ebp-74h]
  _DWORD v24[3]; // [esp+F8h] [ebp-68h]
  int revAxisMapHK[3]; // [esp+104h] [ebp-5Ch] BYREF
  float z; // [esp+114h] [ebp-4Ch]
  float v27; // [esp+118h] [ebp-48h]
  float v28; // [esp+11Ch] [ebp-44h]
  float w; // [esp+124h] [ebp-3Ch]
  float v30; // [esp+128h] [ebp-38h]
  float v31; // [esp+12Ch] [ebp-34h]
  float v32; // [esp+134h] [ebp-2Ch]
  float v33; // [esp+138h] [ebp-28h]
  float v34; // [esp+13Ch] [ebp-24h]
  CPhysicsConstraint *v35; // [esp+14Ch] [ebp-14h]
  hk_Ragdoll_Constraint *m_HkConstraint; // [esp+150h] [ebp-10h]
  int v37; // [esp+154h] [ebp-Ch]
  void *v38; // [esp+158h] [ebp-8h]
  void *retaddr; // [esp+160h] [ebp+0h]

  v37 = a2;
  v38 = retaddr;
  v4 = this->m_isBreakable == 0;
  v35 = this;
  if ( v4 )
  {
    m_HkConstraint = (hk_Ragdoll_Constraint *)this->m_HkConstraint;
  }
  else
  {
    v5 = (hk_Breakable_Constraint *)this->m_HkConstraint;
    *(_DWORD *)(&ragdoll_bp.m_constrainTranslation + 9) = 0;
    v20 = 0;
    v21 = 0;
    v22 = 1065353216;
    v23 = 1065353216;
    hk_Breakable_Constraint::write_to_blueprint(
      this: v5,
      pOutBP: (hk_Breakable_Constraint_BP *)(&ragdoll_bp.m_constrainTranslation + 9));
    m_HkConstraint = *(hk_Ragdoll_Constraint **)(&ragdoll_bp.m_constrainTranslation + 9);
  }
  v6 = ragdoll;
  CPhysicsConstraint::ReadBreakableConstraint(this, params: &ragdoll->constraint);
  LOWORD(ragdoll_bp.m_transform_os_ks[1].m_translation.y) = 0;
  ragdoll_bp.m_transform_os_ks[1].m_translation.z = 0.0;
  ragdoll_bp.m_transform_os_ks[1].m_translation.w = 0.0;
  *(_DWORD *)&ragdoll_bp.m_limits[0].m_limit_is_enabled = 1065353216;
  memset(&ragdoll_bp.m_limits[0].m_limit_min, 0, 10);
  ragdoll_bp.m_limits[0].m_joint_friction = 0.0;
  ragdoll_bp.m_limits[0].m_desired_velocity = 0.0;
  *(_DWORD *)&ragdoll_bp.m_limits[1].m_limit_is_enabled = 1065353216;
  memset(&ragdoll_bp.m_limits[1].m_limit_min, 0, 10);
  ragdoll_bp.m_limits[1].m_joint_friction = 0.0;
  ragdoll_bp.m_limits[1].m_desired_velocity = 0.0;
  *(_DWORD *)&ragdoll_bp.m_limits[2].m_limit_is_enabled = 1065353216;
  ragdoll_bp.m_limits[2].m_limit_min = 0.0;
  ragdoll_bp.m_limits[2].m_limit_max = 0.0;
  hk_Transform::set_identity_transform(this: (hk_Transform *)v18);
  hk_Transform::set_identity_transform(this: (hk_Transform *)&ragdoll_bp.m_transform_os_ks[0].m_translation.y);
  ragdoll_bp.m_limits[2].m_limit_tau = 1.0;
  ragdoll_bp.m_limits[2].m_joint_friction = 1.0;
  HIBYTE(ragdoll_bp.m_limits[2].m_desired_velocity) = 1;
  hk_Ragdoll_Constraint::write_to_blueprint(this: m_HkConstraint, bp: (hk_Ragdoll_Constraint_BP *)v18);
  revAxisMapHK[0] = v18[0];
  z = *(float *)&v18[1];
  w = *(float *)&v18[2];
  revAxisMapHK[1] = LODWORD(ragdoll_bp.m_transform_os_ks[0].m_elems[1]);
  v27 = ragdoll_bp.m_transform_os_ks[0].m_elems[2];
  v30 = ragdoll_bp.m_transform_os_ks[0].m_elems[3];
  revAxisMapHK[2] = LODWORD(ragdoll_bp.m_transform_os_ks[0].m_elems[5]);
  v28 = ragdoll_bp.m_transform_os_ks[0].m_elems[6];
  v31 = ragdoll_bp.m_transform_os_ks[0].m_elems[7];
  v32 = ragdoll_bp.m_transform_os_ks[0].m_elems[9];
  v33 = ragdoll_bp.m_transform_os_ks[0].m_elems[10];
  v34 = ragdoll_bp.m_transform_os_ks[0].m_elems[11];
  ConvertMatrixToHL(in: (const IVP_U_Matrix *)revAxisMapHK, output: &ragdoll->constraintToReference);
  revAxisMapHK[0] = LODWORD(ragdoll_bp.m_transform_os_ks[0].m_translation.y);
  z = ragdoll_bp.m_transform_os_ks[0].m_translation.z;
  w = ragdoll_bp.m_transform_os_ks[0].m_translation.w;
  revAxisMapHK[1] = LODWORD(ragdoll_bp.m_transform_os_ks[1].m_elems[1]);
  v27 = ragdoll_bp.m_transform_os_ks[1].m_elems[2];
  v30 = ragdoll_bp.m_transform_os_ks[1].m_elems[3];
  revAxisMapHK[2] = LODWORD(ragdoll_bp.m_transform_os_ks[1].m_elems[5]);
  v28 = ragdoll_bp.m_transform_os_ks[1].m_elems[6];
  v31 = ragdoll_bp.m_transform_os_ks[1].m_elems[7];
  v32 = ragdoll_bp.m_transform_os_ks[1].m_elems[9];
  v33 = ragdoll_bp.m_transform_os_ks[1].m_elems[10];
  v34 = ragdoll_bp.m_transform_os_ks[1].m_elems[11];
  ConvertMatrixToHL(in: (const IVP_U_Matrix *)revAxisMapHK, output: &ragdoll->constraintToAttached);
  v7 = BYTE1(ragdoll_bp.m_limits[2].m_desired_velocity);
  v8 = nullptr;
  v24[LOBYTE(ragdoll_bp.m_limits[2].m_desired_velocity)] = 0;
  v9 = BYTE2(ragdoll_bp.m_limits[2].m_desired_velocity);
  v24[v7] = 1;
  v24[v9] = 2;
  for ( m_HkConstraint = nullptr; ; v8 = m_HkConstraint )
  {
    v10 = &v6->constraint.strength + 4 * (_DWORD)&v8->m_entities[1];
    v11 = ConvertCoordinateAxisToIVP(axisIndex: (int)v8);
    v12 = 3 * v24[v11];
    v13 = ragdoll_bp.m_limits[v24[v11]].m_limit_max * 57.29578;
    v14 = v35;
    v15 = &ragdoll_bp.m_transform_os_ks[1].m_translation.y + 2 * v12;
    v10[2] = v13;
    v16 = ((double (__thiscall *)(CPhysicsObject *))v14->m_pObjReference->GetInvMass)(a1: v14->m_pObjReference);
    v17 = m_HkConstraint;
    v10[3] = v16 * v15[4];
    if ( v17 == (hk_Ragdoll_Constraint *)2 )
    {
      *v10 = -(float)(v15[2] * 57.29578);
      v10[1] = -(float)(v15[1] * 57.29578);
    }
    else
    {
      *v10 = v15[1] * 57.29578;
      v10[1] = v15[2] * 57.29578;
    }
    m_HkConstraint = (hk_Ragdoll_Constraint *)((char *)&v17->__vftable + 1);
    if ( (int)&v17->__vftable + 1 >= 3 )
      break;
    v6 = ragdoll;
  }
  v4 = HIBYTE(ragdoll_bp.m_limits[2].m_desired_velocity) == 0;
  ragdoll->childIndex = -1;
  ragdoll->parentIndex = -1;
  ragdoll->onlyAngularLimits = v4;
  *(_WORD *)&ragdoll->isActive = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000DA50
// Name: public: void CPhysicsConstraint::WriteSliding(struct constraint_slidingparams_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge CPhysicsConstraint::WriteSliding(
        CPhysicsConstraint *this@<ecx>,
        int a2@<ebp>,
        constraint_slidingparams_t *sliding)
{
  float m_desired_velocity; // ecx
  hk_Breakable_Constraint *v4; // ecx
  IVP_U_Matrix v5; // [esp-4Ch] [ebp-11Ch] BYREF
  _DWORD v6[3]; // [esp-Ch] [ebp-DCh] BYREF
  hk_Transform t; // [esp+0h] [ebp-D0h]
  hk_Breakable_Constraint_BP v8; // [esp+40h] [ebp-90h] BYREF
  int v9; // [esp+5Ch] [ebp-74h] BYREF
  int v10; // [esp+64h] [ebp-6Ch] BYREF
  hk_Prismatic_BP prismatic_bp; // [esp+68h] [ebp-68h] BYREF
  int v12; // [esp+C4h] [ebp-Ch]
  void *v13; // [esp+C8h] [ebp-8h]
  void *retaddr; // [esp+D0h] [ebp+0h]

  v12 = a2;
  v13 = retaddr;
  LODWORD(prismatic_bp.m_limit.m_desired_velocity) = this;
  SetIdentityMatrix(matrix: &sliding->attachedRefXform);
  m_desired_velocity = prismatic_bp.m_limit.m_desired_velocity;
  sliding->slideAxisRef.x = 0.0;
  sliding->slideAxisRef.y = 0.0;
  sliding->slideAxisRef.z = 0.0;
  *(_QWORD *)&sliding->limitMin = 0;
  sliding->friction = 0.0;
  sliding->velocity = 0.0;
  sliding->constraint.forceLimit = 0.0;
  sliding->constraint.torqueLimit = 0.0;
  sliding->constraint.strength = 1.0;
  sliding->constraint.bodyMassScale[0] = 1.0;
  sliding->constraint.bodyMassScale[1] = 1.0;
  sliding->constraint.isActive = true;
  if ( *(_WORD *)(LODWORD(m_desired_velocity) + 30) != 0 )
  {
    v4 = *(hk_Breakable_Constraint **)(LODWORD(m_desired_velocity) + 16);
    memset(&v8, 0, 12);
    v8.m_bodyMassScale[0] = 1.0;
    v8.m_bodyMassScale[1] = 1.0;
    hk_Breakable_Constraint::write_to_blueprint(this: v4, pOutBP: &v8);
    LODWORD(prismatic_bp.m_limit.m_ref_position) = v8.m_real_constraint;
    m_desired_velocity = prismatic_bp.m_limit.m_desired_velocity;
  }
  else
  {
    prismatic_bp.m_limit.m_ref_position = *(float *)(LODWORD(m_desired_velocity) + 16);
  }
  CPhysicsConstraint::ReadBreakableConstraint(
    this: (CPhysicsConstraint *)LODWORD(m_desired_velocity),
    params: &sliding->constraint);
  LOWORD(prismatic_bp.m_axis_Ros.y) = 0;
  prismatic_bp.m_axis_Ros.z = 0.0;
  prismatic_bp.m_axis_Ros.w = 0.0;
  *(_DWORD *)&prismatic_bp.m_limit.m_limit_is_enabled = 1065353216;
  memset(&prismatic_bp.m_limit.m_limit_min, 0, 12);
  prismatic_bp.m_transform_Ros_Aos.m_translation.y = 1.0;
  prismatic_bp.m_transform_Ros_Aos.m_translation.z = 1.0;
  v10 = 0;
  prismatic_bp.m_bodies[0] = 0;
  prismatic_bp.m_bodies[1] = 0;
  prismatic_bp.m_transform_Ros_Aos.m_rotation.x = 1.0;
  memset(&prismatic_bp.m_transform_Ros_Aos.m_rotation.y, 0, 12);
  prismatic_bp.m_transform_Ros_Aos.m_translation.w = 1.0;
  prismatic_bp.m_strength = 0.0;
  prismatic_bp.m_tau = 0.0;
  hk_Prismatic_Constraint::write_to_blueprint(
    this: (hk_Prismatic_Constraint *)LODWORD(prismatic_bp.m_limit.m_ref_position),
    bp: (hk_Prismatic_BP *)&v9);
  t.m_elems[9] = prismatic_bp.m_transform_Ros_Aos.m_rotation.y;
  *(_QWORD *)&t.m_elems[10] = *(_QWORD *)&prismatic_bp.m_transform_Ros_Aos.m_rotation.z;
  hk_Rotation::set(this: (hk_Rotation *)v6, q: (const hk_Quaternion *)&v10);
  LODWORD(v5.rows[0].k[0]) = v6[0];
  LODWORD(v5.rows[1].k[0]) = v6[1];
  LODWORD(v5.rows[2].k[0]) = v6[2];
  v5.rows[0].k[1] = t.m_elems[1];
  v5.rows[1].k[1] = t.m_elems[2];
  v5.rows[2].k[1] = t.m_elems[3];
  v5.rows[0].k[2] = t.m_elems[5];
  v5.rows[1].k[2] = t.m_elems[6];
  v5.rows[2].k[2] = t.m_elems[7];
  v5.vv.k[0] = t.m_elems[9];
  *(_QWORD *)&v5.vv.k[1] = *(_QWORD *)&t.m_elems[10];
  ConvertMatrixToHL(in: &v5, output: &sliding->attachedRefXform);
  if ( BYTE1(prismatic_bp.m_axis_Ros.y) != 0 )
  {
    sliding->friction = g_PhysicsUnits.unitScaleMetersInv * prismatic_bp.m_limit.m_limit_min;
    sliding->velocity = g_PhysicsUnits.unitScaleMetersInv * prismatic_bp.m_limit.m_limit_max;
  }
  if ( LOBYTE(prismatic_bp.m_axis_Ros.y) != 0 )
  {
    sliding->limitMin = g_PhysicsUnits.unitScaleMetersInv * prismatic_bp.m_axis_Ros.z;
    sliding->limitMax = g_PhysicsUnits.unitScaleMetersInv * prismatic_bp.m_axis_Ros.w;
  }
  LODWORD(sliding->slideAxisRef.z) = LODWORD(prismatic_bp.m_strength) ^ _mask__NegFloat_;
  sliding->slideAxisRef.y = prismatic_bp.m_tau;
  sliding->slideAxisRef.x = prismatic_bp.m_transform_Ros_Aos.m_translation.w;
}

//------------------------------------------------------------------------------
// Address: 0x1000DD20
// Name: class IPhysicsConstraint __near * CreateHingeConstraint(class IVP_Environment __near *,class CPhysicsObject __near *,class CPhysicsObject __near *,class IPhysicsConstraintGroup __near *,struct constraint_limitedhingeparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CPhysicsConstraint *__usercall CreateHingeConstraint@<eax>(
        int a1@<edi>,
        hk_Environment *pEnvironment,
        CPhysicsObject *pReferenceObject,
        CPhysicsObject *pAttachedObject,
        CPhysicsConstraintGroup *pGroup,
        const constraint_limitedhingeparams_t *hinge)
{
  CPhysicsConstraint *v6; // eax
  CPhysicsConstraint *v7; // esi
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  v6 = (CPhysicsConstraint *)p_malloc(size: 0x20u);
  if ( v6 != nullptr )
    v7 = CPhysicsConstraint::CPhysicsConstraint(this: v6, pReferenceObject, pAttachedObject);
  else
    v7 = nullptr;
  CPhysicsConstraint::InitHinge(
    this: v7,
    a2: (int)&savedregs,
    a3: a1,
    a4: (int)v7,
    pEnvironment,
    constraint_group: pGroup,
    hinge);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x1000DD60
// Name: class IPhysicsConstraint __near * CreateFixedConstraint(class IVP_Environment __near *,class CPhysicsObject __near *,class CPhysicsObject __near *,class IPhysicsConstraintGroup __near *,struct constraint_fixedparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CPhysicsConstraint *__usercall CreateFixedConstraint@<eax>(
        int a1@<edi>,
        hk_Environment *pEnvironment,
        CPhysicsObject *pReferenceObject,
        CPhysicsObject *pAttachedObject,
        CPhysicsConstraintGroup *pGroup,
        const constraint_fixedparams_t *fixed)
{
  CPhysicsConstraint *v6; // eax
  CPhysicsConstraint *v7; // esi
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  v6 = (CPhysicsConstraint *)p_malloc(size: 0x20u);
  if ( v6 != nullptr )
    v7 = CPhysicsConstraint::CPhysicsConstraint(this: v6, pReferenceObject, pAttachedObject);
  else
    v7 = nullptr;
  CPhysicsConstraint::InitFixed(
    this: v7,
    a2: COERCE_FLOAT(&savedregs),
    a3: a1,
    a4: (int)v7,
    pEnvironment,
    constraint_group: pGroup,
    fixed);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x1000DDA0
// Name: class IPhysicsConstraint __near * CreateSlidingConstraint(class IVP_Environment __near *,class CPhysicsObject __near *,class CPhysicsObject __near *,class IPhysicsConstraintGroup __near *,struct constraint_slidingparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CPhysicsConstraint *__usercall CreateSlidingConstraint@<eax>(
        int a1@<edi>,
        hk_Environment *pEnvironment,
        CPhysicsObject *pReferenceObject,
        CPhysicsObject *pAttachedObject,
        CPhysicsConstraintGroup *pGroup,
        const constraint_slidingparams_t *sliding)
{
  CPhysicsConstraint *v6; // eax
  CPhysicsConstraint *v7; // esi
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  v6 = (CPhysicsConstraint *)p_malloc(size: 0x20u);
  if ( v6 != nullptr )
    v7 = CPhysicsConstraint::CPhysicsConstraint(this: v6, pReferenceObject, pAttachedObject);
  else
    v7 = nullptr;
  CPhysicsConstraint::InitSliding(
    this: v7,
    a2: (int)&savedregs,
    a3: a1,
    a4: (int)v7,
    pEnvironment,
    constraint_group: pGroup,
    sliding);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x1000DDE0
// Name: public: void CPhysicsConstraint::InitRagdoll(class IVP_Environment __near *,class CPhysicsConstraintGroup __near *,struct constraint_ragdollparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge CPhysicsConstraint::InitRagdoll(
        CPhysicsConstraint *this@<ecx>,
        int a2@<ebp>,
        hk_Environment *pEnvironment,
        CPhysicsConstraintGroup *constraint_group,
        const constraint_ragdollparams_t *ragdoll)
{
  CPhysicsObject *m_pObjReference; // eax
  hk_Rigid_Body *v6; // eax
  IVP_Object *next_in_cluster; // edx
  int v8; // eax
  float forceLimit; // xmm1_4
  float torqueLimit; // xmm1_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  int i; // edi
  constraint_axislimit_t *v14; // eax
  float *v15; // eax
  int v16; // xmm0_4
  float v17; // xmm1_4
  float v18; // xmm1_4
  float v19; // xmm1_4
  int v20; // eax
  int v21; // ecx
  int v22; // edi
  int v23; // esi
  IVP_Object *v24; // ecx
  void (__thiscall *dtr_IVP_Object)(IVP_Object *); // eax
  float *v26; // esi
  double v27; // st7
  double v28; // st7
  float v29; // xmm0_4
  hk_Local_Constraint_System *m_pLCS; // esi
  void *v31; // eax
  hk_Local_Constraint_System *v32; // ecx
  void *v33; // eax
  hk_Rigid_Body *v34; // edx
  hk_Ragdoll_Constraint *v35; // ecx
  hk_Ragdoll_Constraint *v36; // eax
  hk_Rigid_Body *v37; // edi
  float v38; // xmm0_4
  float v39; // xmm0_4
  float v40; // xmm0_4
  void *v41; // eax
  hk_Breakable_Constraint *v42; // ecx
  void *v43; // eax
  hk_Ragdoll_Constraint *v44; // ecx
  IVP_Cluster *v45; // eax
  hk_Rigid_Body *v46; // ecx
  hk_Local_Constraint_System *name; // ecx
  _BYTE v48[12]; // [esp-Ch] [ebp-294h] BYREF
  constraint_limitedhingeparams_t hinge; // [esp+0h] [ebp-288h] BYREF
  hk_Ragdoll_Constraint_BP_Builder r_builder; // [esp+58h] [ebp-230h] BYREF
  hk_Limited_Ball_Socket_BP ballsocketBP; // [esp+138h] [ebp-150h] BYREF
  float v52; // [esp+1E8h] [ebp-A0h]
  float v53; // [esp+1ECh] [ebp-9Ch]
  float v54; // [esp+1F0h] [ebp-98h]
  IVP_U_Matrix v55; // [esp+1FCh] [ebp-8Ch] BYREF
  hk_Local_Constraint_System_BP v56; // [esp+244h] [ebp-44h] BYREF
  int revAxisMapHK[3]; // [esp+25Ch] [ebp-2Ch]
  hk_Rigid_Body *v58; // [esp+268h] [ebp-20h]
  hk_Rigid_Body *att; // [esp+26Ch] [ebp-1Ch]
  float v60; // [esp+270h] [ebp-18h]
  hk_Rigid_Body *ref; // [esp+274h] [ebp-14h]
  bool v62; // [esp+27Bh] [ebp-Dh]
  _DWORD v63[2]; // [esp+27Ch] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+288h] [ebp+0h]

  v63[0] = a2;
  v63[1] = retaddr;
  m_pObjReference = this->m_pObjReference;
  ref = (hk_Rigid_Body *)this;
  if ( ConvertRagdollToHinge(
         pHingeOut: (constraint_limitedhingeparams_t *)v48,
         ragdoll,
         pReferenceObject: m_pObjReference) != 0 )
  {
    CPhysicsConstraint::InitHinge(
      this: (CPhysicsConstraint *)ref,
      a2: (int)v63,
      a3: (int)ragdoll,
      a4: (int)v48,
      pEnvironment,
      constraint_group,
      hinge: (const constraint_limitedhingeparams_t *)v48);
  }
  else
  {
    v6 = ref;
    next_in_cluster = ref->next_in_cluster;
    LOWORD(ref->controller_phantom) = 1;
    v8 = (int)v6->prev_in_cluster->IVP_Real_Object::IVP_Real_Object_Fast::IVP_Real_Object_Fast_Static::IVP_Object::next_in_cluster;
    v58 = (hk_Rigid_Body *)next_in_cluster->next_in_cluster;
    revAxisMapHK[1] = v8;
    ballsocketBP.m_transform_os_ks[1].m_translation.y = 1.0;
    ballsocketBP.m_transform_os_ks[1].m_translation.z = 1.0;
    hk_Transform::set_identity_transform(this: (hk_Transform *)(&r_builder.m_ragdoll_constraint_bp.m_constrainTranslation
                                                              + 1));
    hk_Transform::set_identity_transform(this: (hk_Transform *)&ballsocketBP.m_transform_os_ks[0].m_translation.y);
    memset(&ballsocketBP.m_transform_os_ks[1].m_translation.w, 0, 24);
    LOBYTE(ballsocketBP.m_angular_limits[2].m_max) = 1;
    ConvertMatrixToIVP(matrix: &ragdoll->constraintToReference, out: &v55);
    *(float *)(&r_builder.m_ragdoll_constraint_bp.m_constrainTranslation + 1) = v55.rows[0].k[0];
    *(float *)(&r_builder.m_ragdoll_constraint_bp.m_constrainTranslation + 5) = v55.rows[1].k[0];
    *(float *)(&r_builder.m_ragdoll_constraint_bp.m_constrainTranslation + 9) = v55.rows[2].k[0];
    ballsocketBP.m_transform_os_ks[0].m_elems[1] = v55.rows[0].k[1];
    ballsocketBP.m_transform_os_ks[0].m_elems[0] = 0.0;
    ballsocketBP.m_transform_os_ks[0].m_elems[2] = v55.rows[1].k[1];
    ballsocketBP.m_transform_os_ks[0].m_elems[4] = 0.0;
    ballsocketBP.m_transform_os_ks[0].m_elems[8] = 0.0;
    ballsocketBP.m_transform_os_ks[0].m_elems[3] = v55.rows[2].k[1];
    ballsocketBP.m_transform_os_ks[0].m_elems[9] = v55.vv.k[0];
    ballsocketBP.m_transform_os_ks[0].m_elems[5] = v55.rows[0].k[2];
    ballsocketBP.m_transform_os_ks[0].m_elems[10] = v55.vv.k[1];
    ballsocketBP.m_transform_os_ks[0].m_elems[6] = v55.rows[1].k[2];
    ballsocketBP.m_transform_os_ks[0].m_elems[11] = v55.vv.k[2];
    ballsocketBP.m_transform_os_ks[0].m_elems[7] = v55.rows[2].k[2];
    ballsocketBP.m_transform_os_ks[0].m_translation.x = 1.0;
    ConvertMatrixToIVP(matrix: &ragdoll->constraintToAttached, out: &v55);
    ballsocketBP.m_transform_os_ks[0].m_translation.y = v55.rows[0].k[0];
    ballsocketBP.m_transform_os_ks[0].m_translation.z = v55.rows[1].k[0];
    ballsocketBP.m_transform_os_ks[1].m_elems[1] = v55.rows[0].k[1];
    ballsocketBP.m_transform_os_ks[0].m_translation.w = v55.rows[2].k[0];
    ballsocketBP.m_transform_os_ks[1].m_elems[2] = v55.rows[1].k[1];
    ballsocketBP.m_transform_os_ks[1].m_elems[0] = 0.0;
    ballsocketBP.m_transform_os_ks[1].m_elems[3] = v55.rows[2].k[1];
    ballsocketBP.m_transform_os_ks[1].m_elems[4] = 0.0;
    ballsocketBP.m_transform_os_ks[1].m_elems[5] = v55.rows[0].k[2];
    ballsocketBP.m_transform_os_ks[1].m_elems[6] = v55.rows[1].k[2];
    ballsocketBP.m_transform_os_ks[1].m_elems[7] = v55.rows[2].k[2];
    ballsocketBP.m_transform_os_ks[1].m_elems[9] = v55.vv.k[0];
    ballsocketBP.m_transform_os_ks[1].m_elems[10] = v55.vv.k[1];
    ballsocketBP.m_transform_os_ks[1].m_elems[11] = v55.vv.k[2];
    forceLimit = ragdoll->constraint.forceLimit;
    ballsocketBP.m_transform_os_ks[1].m_elems[8] = 0.0;
    ballsocketBP.m_transform_os_ks[1].m_translation.x = 1.0;
    v62 = forceLimit != 0.0 && forceLimit < 1.0e12
       || (torqueLimit = ragdoll->constraint.torqueLimit) != 0.0 && torqueLimit < 1.0e12
       || (v11 = ragdoll->constraint.bodyMassScale[0]) != 1.0 && v11 != 0.0
       || (v12 = ragdoll->constraint.bodyMassScale[1]) != 1.0 && v12 != 0.0;
    for ( i = 0; i < 3; ++i )
    {
      v14 = &ragdoll->axes[i];
      if ( i == 2 )
      {
        *(float *)&revAxisMapHK[2] = (float)-v14->minRotation * 0.017453292;
        *(float *)&att = (float)-v14->maxRotation * 0.017453292;
        v15 = &ballsocketBP.m_transform_os_ks[1].m_translation.w + 2 * ConvertCoordinateAxisToIVP(axisIndex: 2);
        *v15 = *(float *)&att;
        v16 = revAxisMapHK[2];
      }
      else
      {
        *(float *)revAxisMapHK = v14->maxRotation * 0.017453292;
        v60 = v14->minRotation * 0.017453292;
        v15 = &ballsocketBP.m_transform_os_ks[1].m_translation.w + 2 * ConvertCoordinateAxisToIVP(axisIndex: i);
        *v15 = v60;
        v16 = revAxisMapHK[0];
      }
      *((_DWORD *)v15 + 1) = v16;
    }
    LOBYTE(ballsocketBP.m_angular_limits[2].m_max) = !ragdoll->onlyAngularLimits;
    if ( ragdoll->useClockwiseRotations )
    {
      v17 = -ballsocketBP.m_transform_os_ks[1].m_translation.w;
      ballsocketBP.m_transform_os_ks[1].m_translation.w = -ballsocketBP.m_strength;
      ballsocketBP.m_strength = v17;
      v18 = -ballsocketBP.m_tau;
      ballsocketBP.m_tau = -ballsocketBP.m_angular_limits[0].m_min;
      ballsocketBP.m_angular_limits[0].m_min = v18;
      v19 = -ballsocketBP.m_angular_limits[0].m_max;
      ballsocketBP.m_angular_limits[0].m_max = -ballsocketBP.m_angular_limits[1].m_min;
      ballsocketBP.m_angular_limits[1].m_min = v19;
    }
    LOWORD(r_builder.m_ragdoll_constraint_bp.m_transform_os_ks[1].m_translation.y) = 0;
    r_builder.m_ragdoll_constraint_bp.m_transform_os_ks[1].m_translation.z = 0.0;
    r_builder.m_ragdoll_constraint_bp.m_transform_os_ks[1].m_translation.w = 0.0;
    *(_DWORD *)&r_builder.m_ragdoll_constraint_bp.m_limits[0].m_limit_is_enabled = 1065353216;
    memset(&r_builder.m_ragdoll_constraint_bp.m_limits[0].m_limit_min, 0, 10);
    r_builder.m_ragdoll_constraint_bp.m_limits[0].m_joint_friction = 0.0;
    r_builder.m_ragdoll_constraint_bp.m_limits[0].m_desired_velocity = 0.0;
    *(_DWORD *)&r_builder.m_ragdoll_constraint_bp.m_limits[1].m_limit_is_enabled = 1065353216;
    memset(&r_builder.m_ragdoll_constraint_bp.m_limits[1].m_limit_min, 0, 10);
    r_builder.m_ragdoll_constraint_bp.m_limits[1].m_joint_friction = 0.0;
    r_builder.m_ragdoll_constraint_bp.m_limits[1].m_desired_velocity = 0.0;
    *(_DWORD *)&r_builder.m_ragdoll_constraint_bp.m_limits[2].m_limit_is_enabled = 1065353216;
    r_builder.m_ragdoll_constraint_bp.m_limits[2].m_limit_min = 0.0;
    r_builder.m_ragdoll_constraint_bp.m_limits[2].m_limit_max = 0.0;
    hk_Transform::set_identity_transform(this: (hk_Transform *)&hinge.attachedPerpAxisDirection);
    hk_Transform::set_identity_transform(this: (hk_Transform *)&r_builder.m_ragdoll_constraint_bp.m_transform_os_ks[0].m_translation.y);
    r_builder.m_ragdoll_constraint_bp.m_limits[2].m_limit_tau = 1.0;
    r_builder.m_ragdoll_constraint_bp.m_limits[2].m_joint_friction = 1.0;
    HIBYTE(r_builder.m_ragdoll_constraint_bp.m_limits[2].m_desired_velocity) = 1;
    hk_Ragdoll_Constraint_BP_Builder::initialize_from_limited_ball_socket_bp(
      this: (hk_Ragdoll_Constraint_BP_Builder *)&hinge.attachedPerpAxisDirection,
      bp: (const hk_Limited_Ball_Socket_BP *)(&r_builder.m_ragdoll_constraint_bp.m_constrainTranslation + 1),
      a: v58,
      b: (hk_Rigid_Body *)revAxisMapHK[1]);
    v20 = BYTE1(r_builder.m_ragdoll_constraint_bp.m_limits[2].m_desired_velocity);
    v21 = BYTE2(r_builder.m_ragdoll_constraint_bp.m_limits[2].m_desired_velocity);
    v22 = 0;
    *(&v56.m_minErrorTicks + LOBYTE(r_builder.m_ragdoll_constraint_bp.m_limits[2].m_desired_velocity)) = 0;
    *(&v56.m_minErrorTicks + v20) = 1;
    *(&v56.m_minErrorTicks + v21) = 2;
    LODWORD(v60) = &ragdoll->axes[0].torque;
    do
    {
      v23 = 3 * *(&v56.m_minErrorTicks + ConvertCoordinateAxisToIVP(axisIndex: v22));
      v24 = ref->next_in_cluster;
      dtr_IVP_Object = v24->__vftable[29].dtr_IVP_Object;
      v26 = &r_builder.m_ragdoll_constraint_bp.m_transform_os_ks[1].m_translation.y + 2 * v23;
      *(float *)&att = *(float *)(LODWORD(v60) - 4) * 0.017453292;
      v27 = ((double (__thiscall *)(IVP_Object *))dtr_IVP_Object)(a1: v24);
      v28 = v27 * *(float *)LODWORD(v60);
      *(float *)&revAxisMapHK[2] = v28;
      v29 = *(float *)&revAxisMapHK[2];
      LODWORD(v60) += 16;
      *((_BYTE *)v26 + 1) = v28 != 0.0;
      v26[4] = fabs(v29);
      v26[5] = *(float *)&att;
      ++v22;
      r_builder.m_ragdoll_constraint_bp.m_limits[2].m_joint_friction = 1.0;
    }
    while ( v22 < 3 );
    if ( constraint_group != nullptr )
      m_pLCS = constraint_group->m_pLCS;
    else
      m_pLCS = nullptr;
    if ( m_pLCS == nullptr )
    {
      v56.m_damp = 1.0;
      v56.m_tau = 1.0;
      v56.m_active = true;
      v56.m_n_iterations = 0;
      v56.m_errorTolerance = 0.029999999;
      v56.m_minErrorTicks = 1;
      v31 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 131);
      if ( v31 != nullptr )
      {
        v32 = (hk_Local_Constraint_System *)(((unsigned int)v31 + 19) & 0xFFFFFFF0);
        *((_DWORD *)&v32[-1].m_client_data + 3) = v31;
        m_pLCS = hk_Local_Constraint_System::hk_Local_Constraint_System(this: v32, env: pEnvironment, bp: &v56);
      }
      else
      {
        m_pLCS = nullptr;
      }
      ref->name = (const char *)m_pLCS;
    }
    if ( v62 )
    {
      v33 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 355);
      if ( v33 != nullptr )
      {
        v34 = v58;
        v35 = (hk_Ragdoll_Constraint *)(((unsigned int)v33 + 19) & 0xFFFFFFF0);
        *(_DWORD *)(&v35[-1].m_constrainTranslation + 5) = v33;
        v36 = hk_Ragdoll_Constraint::hk_Ragdoll_Constraint(
                this: v35,
                env: pEnvironment,
                bp: (const hk_Ragdoll_Constraint_BP *)&hinge.attachedPerpAxisDirection,
                a: v34,
                b: (hk_Rigid_Body *)revAxisMapHK[1]);
      }
      else
      {
        v36 = nullptr;
      }
      v37 = ref;
      HIWORD(ref->controller_phantom) = 1;
      *(_DWORD *)&ballsocketBP.m_constrainTranslation = v36;
      if ( (float)(g_PhysicsUnits.unitScaleMeters * ragdoll->constraint.forceLimit) <= 0.0 )
        *((_DWORD *)&ballsocketBP.m_constrainTranslation + 1) = 1399379109;
      else
        *((float *)&ballsocketBP.m_constrainTranslation + 1) = g_PhysicsUnits.unitScaleMeters
                                                             * ragdoll->constraint.forceLimit;
      v38 = ragdoll->constraint.torqueLimit;
      if ( v38 <= 0.0 )
        v52 = 1.0e12;
      else
        v52 = v38 * 0.017453292;
      v39 = ragdoll->constraint.bodyMassScale[0];
      if ( v39 <= 0.0 )
        v39 = 1.0;
      v53 = v39;
      v40 = ragdoll->constraint.bodyMassScale[1];
      if ( v40 <= 0.0 )
        v40 = 1.0;
      v54 = v40;
      v41 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 67);
      if ( v41 != nullptr )
      {
        v42 = (hk_Breakable_Constraint *)(((unsigned int)v41 + 19) & 0xFFFFFFF0);
        *(_DWORD *)&v42[-1].m_is_broken = v41;
        v37->father_cluster = (IVP_Cluster *)hk_Breakable_Constraint::hk_Breakable_Constraint(
                                               this: v42,
                                               constraint_system: m_pLCS,
                                               bp: (const hk_Breakable_Constraint_BP *)&ballsocketBP.m_constrainTranslation);
      }
      else
      {
        v37->father_cluster = nullptr;
      }
    }
    else
    {
      v43 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 355);
      if ( v43 != nullptr )
      {
        v44 = (hk_Ragdoll_Constraint *)(((unsigned int)v43 + 19) & 0xFFFFFFF0);
        ref = (hk_Rigid_Body *)revAxisMapHK[1];
        *(_DWORD *)(&v44[-1].m_constrainTranslation + 5) = v43;
        v45 = (IVP_Cluster *)hk_Ragdoll_Constraint::hk_Ragdoll_Constraint(
                               this: v44,
                               constraint_system: m_pLCS,
                               bp: (const hk_Ragdoll_Constraint_BP *)&hinge.attachedPerpAxisDirection,
                               a: v58,
                               b: ref);
      }
      else
      {
        v45 = nullptr;
      }
      v46 = ref;
      ref->father_cluster = v45;
      v37 = v46;
    }
    name = (hk_Local_Constraint_System *)v37->name;
    if ( name != nullptr && ragdoll->isActive )
      hk_Local_Constraint_System::activate(this: name);
    v37->father_cluster->IVP_Real_Object::IVP_Real_Object_Fast::IVP_Real_Object_Fast_Static::name = (const char *)v37;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E5D0
// Name: public: void CPhysicsConstraint::WriteToTemplate(struct vphysics_save_cphysicsconstraint_t __near &,struct vphysics_save_constraint_t __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPhysicsConstraint::WriteToTemplate(
        CPhysicsConstraint *this,
        vphysics_save_cphysicsconstraint_t *header,
        vphysics_save_constraint_t *constraintTemplate)
{
  hk_Constraint *m_HkConstraint; // edx
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  header->constraintType = this->m_constraintType;
  m_HkConstraint = this->m_HkConstraint;
  if ( m_HkConstraint != nullptr )
  {
    header->pGroup = (CPhysicsConstraintGroup *)m_HkConstraint->m_constraint_system->m_client_data;
    header->pObjReference = this->m_pObjReference;
    header->pObjAttached = this->m_pObjAttached;
    switch ( header->constraintType )
    {
      case 1:
        CPhysicsConstraint::WriteRagdoll(this, a2: (int)&savedregs, ragdoll: &constraintTemplate->ragdoll);
        break;
      case 2:
        CPhysicsConstraint::WriteHinge(this, a2: (int)&savedregs, hinge: &constraintTemplate->hinge);
        break;
      case 3:
        CPhysicsConstraint::WriteFixed(this, a2: (int)&savedregs, fixed: &constraintTemplate->fixed);
        break;
      case 4:
        CPhysicsConstraint::WriteBallsocket(
          this,
          ballsocket: (hk_Ball_Socket_Constraint *)&constraintTemplate->ballsocket);
        break;
      case 5:
        CPhysicsConstraint::WriteSliding(this, a2: (int)&savedregs, sliding: &constraintTemplate->sliding);
        break;
      case 6:
        CPhysicsConstraint::WritePulley(this, pulley: (hk_Pulley_Constraint *)&constraintTemplate->pulley);
        break;
      case 7:
        CPhysicsConstraint::WriteLength(this, length: &constraintTemplate->length);
        break;
      default:
        return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E6A0
// Name: public: virtual bool CPhysicsConstraint::GetConstraintParams(struct constraint_breakableparams_t __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CPhysicsConstraint::GetConstraintParams(
        CPhysicsConstraint *this,
        constraint_breakableparams_t *pParams)
{
  bool result; // al
  vphysics_save_constraint_t constraintTemplate; // [esp+8h] [ebp-26Ch] BYREF
  vphysics_save_cphysicsconstraint_t header; // [esp+264h] [ebp-10h] BYREF

  if ( pParams == nullptr )
    return false;
  memset(&header, 0, sizeof(header));
  memset(dst: (unsigned __int8 *)&constraintTemplate, value: 0, count: sizeof(constraintTemplate));
  CPhysicsConstraint::WriteToTemplate(this, &header, &constraintTemplate);
  if ( header.constraintType == 0 || header.pObjAttached == nullptr || header.pObjReference == nullptr )
    return false;
  switch ( header.constraintType )
  {
    case 1:
      *pParams = constraintTemplate.ragdoll.constraint;
      result = true;
      break;
    case 2:
      *pParams = constraintTemplate.hinge.constraint;
      result = true;
      break;
    case 3:
      *pParams = constraintTemplate.fixed.constraint;
      result = true;
      break;
    case 4:
      *pParams = constraintTemplate.ballsocket.constraint;
      result = true;
      break;
    case 5:
      *pParams = constraintTemplate.sliding.constraint;
      result = true;
      break;
    case 6:
      *pParams = constraintTemplate.pulley.constraint;
      result = true;
      break;
    case 7:
      *pParams = constraintTemplate.length.constraint;
      result = true;
      break;
    default:
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000E8A0
// Name: class IPhysicsConstraint __near * CreateRagdollConstraint(class IVP_Environment __near *,class CPhysicsObject __near *,class CPhysicsObject __near *,class IPhysicsConstraintGroup __near *,struct constraint_ragdollparams_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CPhysicsConstraint *__cdecl CreateRagdollConstraint(
        hk_Environment *pEnvironment,
        CPhysicsObject *pReferenceObject,
        CPhysicsObject *pAttachedObject,
        CPhysicsConstraintGroup *pGroup,
        const constraint_ragdollparams_t *ragdoll)
{
  CPhysicsConstraint *v5; // eax
  CPhysicsConstraint *v6; // esi
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  v5 = (CPhysicsConstraint *)p_malloc(size: 0x20u);
  if ( v5 != nullptr )
    v6 = CPhysicsConstraint::CPhysicsConstraint(this: v5, pReferenceObject, pAttachedObject);
  else
    v6 = nullptr;
  CPhysicsConstraint::InitRagdoll(this: v6, a2: (int)&savedregs, pEnvironment, constraint_group: pGroup, ragdoll);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x1000E8E0
// Name: bool SavePhysicsConstraint(struct physsaveparams_t const __near &,class CPhysicsConstraint __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl SavePhysicsConstraint(const physsaveparams_t *params, CPhysicsConstraint *pConstraint)
{
  bool result; // al
  vphysics_save_constraint_t constraintTemplate; // [esp+4h] [ebp-26Ch] BYREF
  vphysics_save_cphysicsconstraint_t header; // [esp+260h] [ebp-10h] BYREF

  memset(&header, 0, sizeof(header));
  memset(dst: (unsigned __int8 *)&constraintTemplate, value: 0, count: sizeof(constraintTemplate));
  CPhysicsConstraint::WriteToTemplate(this: pConstraint, &header, &constraintTemplate);
  params->pSave->WriteAll(this: params->pSave, a2: &header, a3: &vphysics_save_cphysicsconstraint_t::m_DataMap);
  if ( header.constraintType == 0 || header.pObjAttached == nullptr || header.pObjReference == nullptr )
    return true;
  switch ( header.constraintType )
  {
    case 1:
      params->pSave->WriteAll(
        this: params->pSave,
        a2: &constraintTemplate.ragdoll,
        a3: &vphysics_save_constraintragdoll_t::m_DataMap);
      return true;
    case 2:
      params->pSave->WriteAll(
        this: params->pSave,
        a2: &constraintTemplate.hinge,
        a3: &vphysics_save_constrainthinge_t::m_DataMap);
      result = true;
      break;
    case 3:
      params->pSave->WriteAll(
        this: params->pSave,
        a2: &constraintTemplate,
        a3: &vphysics_save_constraintfixed_t::m_DataMap);
      result = true;
      break;
    case 4:
      params->pSave->WriteAll(
        this: params->pSave,
        a2: &constraintTemplate.ballsocket,
        a3: &vphysics_save_constraintballsocket_t::m_DataMap);
      result = true;
      break;
    case 5:
      params->pSave->WriteAll(
        this: params->pSave,
        a2: &constraintTemplate.sliding,
        a3: &vphysics_save_constraintsliding_t::m_DataMap);
      result = true;
      break;
    case 6:
      params->pSave->WriteAll(
        this: params->pSave,
        a2: &constraintTemplate.pulley,
        a3: &vphysics_save_constraintpulley_t::m_DataMap);
      result = true;
      break;
    case 7:
      params->pSave->WriteAll(
        this: params->pSave,
        a2: &constraintTemplate.length,
        a3: &vphysics_save_constraintlength_t::m_DataMap);
      result = true;
      break;
    default:
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000EA50
// Name: void PostRestorePhysicsConstraintGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PostRestorePhysicsConstraintGroup()
{
  int i; // esi
  CPhysicsConstraintGroup **m_pMemory; // eax

  for ( i = 0; i < g_ConstraintGroupActivateList.m_Size; ++i )
    g_ConstraintGroupActivateList.m_Memory.m_pMemory[i]->Activate(this: g_ConstraintGroupActivateList.m_Memory.m_pMemory[i]);
  g_ConstraintGroupActivateList.m_Size = 0;
  if ( g_ConstraintGroupActivateList.m_Memory.m_nGrowSize < 0 )
  {
    g_ConstraintGroupActivateList.m_pElements = g_ConstraintGroupActivateList.m_Memory.m_pMemory;
  }
  else
  {
    m_pMemory = g_ConstraintGroupActivateList.m_Memory.m_pMemory;
    if ( g_ConstraintGroupActivateList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_ConstraintGroupActivateList.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_ConstraintGroupActivateList.m_Memory.m_pMemory = nullptr;
    }
    g_ConstraintGroupActivateList.m_Memory.m_nAllocationCount = 0;
    g_ConstraintGroupActivateList.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EAD0
// Name: bool RestorePhysicsConstraintGroup(struct physrestoreparams_t const __near &,class CPhysicsConstraintGroup __near * __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl RestorePhysicsConstraintGroup(
        const physrestoreparams_t *params,
        CPhysicsConstraintGroup **ppConstraintGroup)
{
  IRestore *pRestore; // ecx
  CPhysicsConstraintGroup *v3; // eax
  int m_Size; // eax
  int v5; // esi
  CPhysicsConstraintGroup **m_pMemory; // ecx
  int v7; // eax
  CPhysicsConstraintGroup **v8; // eax
  vphysics_save_cphysicsconstraintgroup_t groupTemplate; // [esp+8h] [ebp-10h] BYREF

  pRestore = params->pRestore;
  memset(&groupTemplate, 0, sizeof(groupTemplate));
  pRestore->ReadAll(this: pRestore, a2: &groupTemplate, a3: &vphysics_save_cphysicsconstraintgroup_t::m_DataMap);
  if ( groupTemplate.errorTolerance == 0.0 && groupTemplate.minErrorTicks == 0 )
  {
    groupTemplate.minErrorTicks = 15;
    groupTemplate.errorTolerance = 3.0;
  }
  v3 = (CPhysicsConstraintGroup *)params->pEnvironment->CreateConstraintGroup(
                                    this: params->pEnvironment,
                                    a2: &groupTemplate);
  *ppConstraintGroup = v3;
  if ( v3 != nullptr && groupTemplate.isActive )
  {
    m_Size = g_ConstraintGroupActivateList.m_Size;
    v5 = g_ConstraintGroupActivateList.m_Size;
    if ( g_ConstraintGroupActivateList.m_Size + 1 > g_ConstraintGroupActivateList.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CPredictedPhysicsObject *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&g_ConstraintGroupActivateList,
        num: g_ConstraintGroupActivateList.m_Size - g_ConstraintGroupActivateList.m_Memory.m_nAllocationCount + 1);
      m_Size = g_ConstraintGroupActivateList.m_Size;
    }
    m_pMemory = g_ConstraintGroupActivateList.m_Memory.m_pMemory;
    g_ConstraintGroupActivateList.m_Size = m_Size + 1;
    v7 = m_Size - v5;
    g_ConstraintGroupActivateList.m_pElements = g_ConstraintGroupActivateList.m_Memory.m_pMemory;
    if ( v7 > 0 )
    {
      _V_memmove(
        dest: &g_ConstraintGroupActivateList.m_Memory.m_pMemory[v5 + 1],
        src: &g_ConstraintGroupActivateList.m_Memory.m_pMemory[v5],
        count: 4 * v7);
      m_pMemory = g_ConstraintGroupActivateList.m_Memory.m_pMemory;
    }
    v8 = &m_pMemory[v5];
    if ( v8 != nullptr )
      *v8 = *ppConstraintGroup;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C6860
// Name: vphysics_save_cphysicsconstraintgroup_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *vphysics_save_cphysicsconstraintgroup_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<vphysics_save_cphysicsconstraintgroup_t>(__formal: nullptr);
  vphysics_save_cphysicsconstraintgroup_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C6880
// Name: vphysics_save_cphysicsconstraint_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *vphysics_save_cphysicsconstraint_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<vphysics_save_cphysicsconstraint_t>(__formal: nullptr);
  vphysics_save_cphysicsconstraint_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C6890
// Name: vphysics_save_constraintbreakable_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *vphysics_save_constraintbreakable_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<vphysics_save_constraintbreakable_t>(__formal: nullptr);
  vphysics_save_constraintbreakable_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C68A0
// Name: vphysics_save_constraintaxislimit_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *vphysics_save_constraintaxislimit_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<vphysics_save_constraintaxislimit_t>(__formal: nullptr);
  vphysics_save_constraintaxislimit_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C68B0
// Name: vphysics_save_constraintfixed_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *vphysics_save_constraintfixed_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<vphysics_save_constraintfixed_t>(__formal: nullptr);
  vphysics_save_constraintfixed_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C68C0
// Name: vphysics_save_constrainthinge_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *vphysics_save_constrainthinge_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<vphysics_save_constrainthinge_t>(__formal: nullptr);
  vphysics_save_constrainthinge_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C68D0
// Name: vphysics_save_constraintsliding_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *vphysics_save_constraintsliding_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<vphysics_save_constraintsliding_t>(__formal: nullptr);
  vphysics_save_constraintsliding_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C68E0
// Name: vphysics_save_constraintpulley_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *vphysics_save_constraintpulley_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<vphysics_save_constraintpulley_t>(__formal: nullptr);
  vphysics_save_constraintpulley_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C68F0
// Name: vphysics_save_constraintlength_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *vphysics_save_constraintlength_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<vphysics_save_constraintlength_t>(__formal: nullptr);
  vphysics_save_constraintlength_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C6900
// Name: vphysics_save_constraintballsocket_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *vphysics_save_constraintballsocket_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<vphysics_save_constraintballsocket_t>(__formal: nullptr);
  vphysics_save_constraintballsocket_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100C6910
// Name: vphysics_save_constraintragdoll_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *vphysics_save_constraintragdoll_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<vphysics_save_constraintragdoll_t>(__formal: nullptr);
  vphysics_save_constraintragdoll_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000EBC0
// Name: struct datamap_t __near * DataMapInit<struct vphysics_save_cphysicsconstraintgroup_t>(struct vphysics_save_cphysicsconstraintgroup_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<vphysics_save_cphysicsconstraintgroup_t>()
{
  if ( (_S1_0 & 1) == 0 )
  {
    _S1_0 |= 1u;
    nameHolder_1.m_pszBase = "vphysics_save_cphysicsconstraintgroup_t";
    nameHolder_1.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_1.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_1.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_1.m_Names.m_Size = 0;
    nameHolder_1.m_Names.m_pElements = nullptr;
    nameHolder_1.m_nLenBase = 39;
    atexit(func: DataMapInit_vphysics_save_cphysicsconstraintgroup_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  vphysics_save_cphysicsconstraintgroup_t::m_DataMap.baseMap = nullptr;
  vphysics_save_cphysicsconstraintgroup_t::m_DataMap.dataNumFields = 4;
  vphysics_save_cphysicsconstraintgroup_t::m_DataMap.dataDesc = &dataDesc_1[1];
  return &vphysics_save_cphysicsconstraintgroup_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1000EC40
// Name: struct datamap_t __near * DataMapInit<struct vphysics_save_cphysicsconstraint_t>(struct vphysics_save_cphysicsconstraint_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<vphysics_save_cphysicsconstraint_t>()
{
  if ( (_S2_0 & 1) == 0 )
  {
    _S2_0 |= 1u;
    nameHolder_2.m_pszBase = "vphysics_save_cphysicsconstraint_t";
    nameHolder_2.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_2.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_2.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_2.m_Names.m_Size = 0;
    nameHolder_2.m_Names.m_pElements = nullptr;
    nameHolder_2.m_nLenBase = 34;
    atexit(func: DataMapInit_vphysics_save_cphysicsconstraint_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  vphysics_save_cphysicsconstraint_t::m_DataMap.baseMap = nullptr;
  vphysics_save_cphysicsconstraint_t::m_DataMap.dataNumFields = 4;
  vphysics_save_cphysicsconstraint_t::m_DataMap.dataDesc = &dataDesc_2[1];
  return &vphysics_save_cphysicsconstraint_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1000ECC0
// Name: struct datamap_t __near * DataMapInit<struct vphysics_save_constraintbreakable_t>(struct vphysics_save_constraintbreakable_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<vphysics_save_constraintbreakable_t>()
{
  if ( (_S3_0 & 1) == 0 )
  {
    _S3_0 |= 1u;
    nameHolder_3.m_pszBase = "vphysics_save_constraintbreakable_t";
    nameHolder_3.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_3.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_3.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_3.m_Names.m_Size = 0;
    nameHolder_3.m_Names.m_pElements = nullptr;
    nameHolder_3.m_nLenBase = 35;
    atexit(func: DataMapInit_vphysics_save_constraintbreakable_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  vphysics_save_constraintbreakable_t::m_DataMap.baseMap = nullptr;
  vphysics_save_constraintbreakable_t::m_DataMap.dataNumFields = 5;
  vphysics_save_constraintbreakable_t::m_DataMap.dataDesc = &dataDesc_3[1];
  return &vphysics_save_constraintbreakable_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1000ED40
// Name: struct datamap_t __near * DataMapInit<struct vphysics_save_constraintaxislimit_t>(struct vphysics_save_constraintaxislimit_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<vphysics_save_constraintaxislimit_t>()
{
  if ( (_S4 & 1) == 0 )
  {
    _S4 |= 1u;
    nameHolder_4.m_pszBase = "vphysics_save_constraintaxislimit_t";
    nameHolder_4.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_4.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_4.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_4.m_Names.m_Size = 0;
    nameHolder_4.m_Names.m_pElements = nullptr;
    nameHolder_4.m_nLenBase = 35;
    atexit(func: DataMapInit_vphysics_save_constraintaxislimit_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  vphysics_save_constraintaxislimit_t::m_DataMap.baseMap = nullptr;
  vphysics_save_constraintaxislimit_t::m_DataMap.dataNumFields = 4;
  vphysics_save_constraintaxislimit_t::m_DataMap.dataDesc = &dataDesc_4[1];
  return &vphysics_save_constraintaxislimit_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1000EDC0
// Name: struct datamap_t __near * DataMapInit<struct vphysics_save_constraintfixed_t>(struct vphysics_save_constraintfixed_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<vphysics_save_constraintfixed_t>()
{
  if ( (_S5 & 1) == 0 )
  {
    _S5 |= 1u;
    nameHolder_5.m_pszBase = "vphysics_save_constraintfixed_t";
    nameHolder_5.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_5.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_5.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_5.m_Names.m_Size = 0;
    nameHolder_5.m_Names.m_pElements = nullptr;
    nameHolder_5.m_nLenBase = 31;
    atexit(func: DataMapInit_vphysics_save_constraintfixed_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  vphysics_save_constraintfixed_t::m_DataMap.baseMap = nullptr;
  vphysics_save_constraintfixed_t::m_DataMap.dataNumFields = 2;
  vphysics_save_constraintfixed_t::m_DataMap.dataDesc = &dataDesc_5[1];
  return &vphysics_save_constraintfixed_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1000EE40
// Name: struct datamap_t __near * DataMapInit<struct vphysics_save_constrainthinge_t>(struct vphysics_save_constrainthinge_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<vphysics_save_constrainthinge_t>()
{
  if ( (_S6 & 1) == 0 )
  {
    _S6 |= 1u;
    nameHolder_6.m_pszBase = "vphysics_save_constrainthinge_t";
    nameHolder_6.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_6.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_6.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_6.m_Names.m_Size = 0;
    nameHolder_6.m_Names.m_pElements = nullptr;
    nameHolder_6.m_nLenBase = 31;
    atexit(func: DataMapInit_vphysics_save_constrainthinge_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  vphysics_save_constrainthinge_t::m_DataMap.baseMap = nullptr;
  vphysics_save_constrainthinge_t::m_DataMap.dataNumFields = 4;
  vphysics_save_constrainthinge_t::m_DataMap.dataDesc = &dataDesc_6[1];
  return &vphysics_save_constrainthinge_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1000EEC0
// Name: struct datamap_t __near * DataMapInit<struct vphysics_save_constraintsliding_t>(struct vphysics_save_constraintsliding_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<vphysics_save_constraintsliding_t>()
{
  if ( (_S7 & 1) == 0 )
  {
    _S7 |= 1u;
    nameHolder_7.m_pszBase = "vphysics_save_constraintsliding_t";
    nameHolder_7.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_7.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_7.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_7.m_Names.m_Size = 0;
    nameHolder_7.m_Names.m_pElements = nullptr;
    nameHolder_7.m_nLenBase = 33;
    atexit(func: DataMapInit_vphysics_save_constraintsliding_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  vphysics_save_constraintsliding_t::m_DataMap.baseMap = nullptr;
  vphysics_save_constraintsliding_t::m_DataMap.dataNumFields = 7;
  vphysics_save_constraintsliding_t::m_DataMap.dataDesc = &dataDesc_7[1];
  return &vphysics_save_constraintsliding_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1000EF40
// Name: struct datamap_t __near * DataMapInit<struct vphysics_save_constraintpulley_t>(struct vphysics_save_constraintpulley_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<vphysics_save_constraintpulley_t>()
{
  if ( (_S8 & 1) == 0 )
  {
    _S8 |= 1u;
    nameHolder_8.m_pszBase = "vphysics_save_constraintpulley_t";
    nameHolder_8.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_8.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_8.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_8.m_Names.m_Size = 0;
    nameHolder_8.m_Names.m_pElements = nullptr;
    nameHolder_8.m_nLenBase = 32;
    atexit(func: DataMapInit_vphysics_save_constraintpulley_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  vphysics_save_constraintpulley_t::m_DataMap.baseMap = nullptr;
  vphysics_save_constraintpulley_t::m_DataMap.dataNumFields = 6;
  vphysics_save_constraintpulley_t::m_DataMap.dataDesc = &dataDesc_8[1];
  return &vphysics_save_constraintpulley_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1000EFF0
// Name: struct datamap_t __near * DataMapInit<struct vphysics_save_constraintlength_t>(struct vphysics_save_constraintlength_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<vphysics_save_constraintlength_t>()
{
  if ( (_S9 & 1) == 0 )
  {
    _S9 |= 1u;
    nameHolder_9.m_pszBase = "vphysics_save_constraintlength_t";
    nameHolder_9.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_9.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_9.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_9.m_Names.m_Size = 0;
    nameHolder_9.m_Names.m_pElements = nullptr;
    nameHolder_9.m_nLenBase = 32;
    atexit(func: DataMapInit_vphysics_save_constraintlength_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  vphysics_save_constraintlength_t::m_DataMap.baseMap = nullptr;
  vphysics_save_constraintlength_t::m_DataMap.dataNumFields = 4;
  vphysics_save_constraintlength_t::m_DataMap.dataDesc = &dataDesc_9[1];
  return &vphysics_save_constraintlength_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1000F070
// Name: struct datamap_t __near * DataMapInit<struct vphysics_save_constraintballsocket_t>(struct vphysics_save_constraintballsocket_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<vphysics_save_constraintballsocket_t>()
{
  if ( (_S10 & 1) == 0 )
  {
    _S10 |= 1u;
    nameHolder_10.m_pszBase = "vphysics_save_constraintballsocket_t";
    nameHolder_10.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_10.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_10.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_10.m_Names.m_Size = 0;
    nameHolder_10.m_Names.m_pElements = nullptr;
    nameHolder_10.m_nLenBase = 36;
    atexit(func: DataMapInit_vphysics_save_constraintballsocket_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  vphysics_save_constraintballsocket_t::m_DataMap.baseMap = nullptr;
  vphysics_save_constraintballsocket_t::m_DataMap.dataNumFields = 2;
  vphysics_save_constraintballsocket_t::m_DataMap.dataDesc = &dataDesc_10[1];
  return &vphysics_save_constraintballsocket_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1000F0F0
// Name: struct datamap_t __near * DataMapInit<struct vphysics_save_constraintragdoll_t>(struct vphysics_save_constraintragdoll_t __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<vphysics_save_constraintragdoll_t>()
{
  if ( (_S11 & 1) == 0 )
  {
    _S11 |= 1u;
    nameHolder_11.m_pszBase = "vphysics_save_constraintragdoll_t";
    nameHolder_11.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_11.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_11.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_11.m_Names.m_Size = 0;
    nameHolder_11.m_Names.m_pElements = nullptr;
    nameHolder_11.m_nLenBase = 33;
    atexit(func: DataMapInit_vphysics_save_constraintragdoll_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  vphysics_save_constraintragdoll_t::m_DataMap.baseMap = nullptr;
  vphysics_save_constraintragdoll_t::m_DataMap.dataNumFields = 9;
  vphysics_save_constraintragdoll_t::m_DataMap.dataDesc = &dataDesc_11[1];
  return &vphysics_save_constraintragdoll_t::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100C6870
// Name: _dynamic_initializer_for__g_ConstraintGroupActivateList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ConstraintGroupActivateList__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ConstraintGroupActivateList__);
}
