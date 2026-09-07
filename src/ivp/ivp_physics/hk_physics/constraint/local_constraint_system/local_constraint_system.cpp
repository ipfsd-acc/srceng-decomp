// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_physics/hk_physics/constraint/local_constraint_system/local_constraint_system.cpp
// Functions: 30
// ============================================================

#include "ivp\ivp_physics\hk_physics\constraint\local_constraint_system\local_constraint_system.h"

//------------------------------------------------------------------------------
// Address: 0x10003C40
// Name: protected: virtual class IVP_U_Vector<class IVP_Core> __near * CPhysics_Airboat::get_associated_controlled_cores(void)
// Source: json
//------------------------------------------------------------------------------
IVP_U_Vector<IVP_Core> *__thiscall CPhysics_Airboat::get_associated_controlled_cores(CPhysics_Airboat *this)
{
  return (IVP_U_Vector<IVP_Core> *)&this->m_CarSystemDebugData.frontActuatorRight.hesse_val;
}

//------------------------------------------------------------------------------
// Address: 0x10004FB0
// Name: private: virtual class IVP_U_Vector<class IVP_Core> __near * IVP_Controller_Independent::get_associated_controlled_cores(void)
// Source: json
//------------------------------------------------------------------------------
IVP_U_Vector<IVP_Core> *__thiscall IVP_Controller_Independent::get_associated_controlled_cores(
        IVP_Controller_Independent *this)
{
  return &IVP_Controller_Independent::empty_list;
}

//------------------------------------------------------------------------------
// Address: 0x100348C0
// Name: public: void hk_Local_Constraint_System::write_to_blueprint(class hk_Local_Constraint_System_BP __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Local_Constraint_System::write_to_blueprint(
        hk_Local_Constraint_System *this,
        hk_Local_Constraint_System_BP *bp)
{
  bp->m_damp = 1.0;
  bp->m_tau = 1.0;
  bp->m_n_iterations = this->m_n_iterations - 2;
  bp->m_active = this->m_is_active;
  bp->m_minErrorTicks = this->m_minErrorTicks;
  bp->m_errorTolerance = this->m_errorTolerance;
}

//------------------------------------------------------------------------------
// Address: 0x10034900
// Name: GetMoveableMass
// Source: json
//------------------------------------------------------------------------------
__int64 __userpurge GetMoveableMass@<xmm0>(IVP_Core *pCore@<ecx>)
{
  if ( (*(_WORD *)&pCore->IVP_Core_Fast_Static & 0x12) != 0 )
    return 0;
  else
    return LODWORD(pCore->rot_inertia.hesse_val);
}

//------------------------------------------------------------------------------
// Address: 0x10034920
// Name: public: void hk_Local_Constraint_System::report_square_error(union __m128)
// Source: json
//------------------------------------------------------------------------------
void __usercall hk_Local_Constraint_System::report_square_error(
        hk_Local_Constraint_System *this@<ecx>,
        __m128 errorSq@<xmm0>)
{
  this->m_scErrorThisTick = _mm_max_ps(this->m_scErrorThisTick, errorSq);
}

//------------------------------------------------------------------------------
// Address: 0x10034930
// Name: public: void hk_Local_Constraint_System::activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Local_Constraint_System::activate(hk_Local_Constraint_System *this)
{
  if ( !this->m_is_active && this->m_bodies.m_n_elems != 0 )
  {
    IVP_Controller_Manager::announce_controller_to_environment(
      this: this->m_environment->controller_manager,
      cntrl: this);
    this->m_is_active = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034960
// Name: public: void hk_Local_Constraint_System::deactivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Local_Constraint_System::deactivate(hk_Local_Constraint_System *this)
{
  if ( this->m_is_active && this->actuator_controlled_cores.n_elems != 0 )
  {
    IVP_Controller_Manager::remove_controller_from_environment(cntrl: this, silently: IVP_FALSE);
    this->m_is_active = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034990
// Name: public: virtual class IVP_U_Vector<class IVP_Core> __near * IVP_Constraint::get_associated_controlled_cores(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Vector_of_Cores_2 *__thiscall IVP_Constraint::get_associated_controlled_cores(IVP_Constraint *this)
{
  return &this->cores_of_constraint_system;
}

//------------------------------------------------------------------------------
// Address: 0x100349A0
// Name: public: virtual char const __near * hk_Link_EF::get_controller_name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall hk_Link_EF::get_controller_name(hk_Link_EF *this)
{
  return "sys:constraint";
}

//------------------------------------------------------------------------------
// Address: 0x100349B0
// Name: public: virtual void hk_Link_EF::do_simulation_controller(class IVP_Event_Sim __near *,class IVP_U_Vector<class IVP_Core> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Link_EF::do_simulation_controller(
        hk_Link_EF *this,
        hk_PSI_Info *es,
        IVP_U_Vector<IVP_Core> *__formal)
{
  this->apply_effector_PSI(this, a2: es);
}

//------------------------------------------------------------------------------
// Address: 0x100349D0
// Name: public: virtual void hk_Link_EF::core_is_going_to_be_deleted_event(class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Link_EF::core_is_going_to_be_deleted_event(IVP_Controller_Buoyancy *this, IVP_Core *__formal)
{
  if ( this != nullptr )
    ((void (__thiscall *)(IVP_Controller_Buoyancy *, int))this->dtr_IVP_Controller)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10034A40
// Name: public: hk_Local_Constraint_System::hk_Local_Constraint_System(class hk_Environment __near *,class hk_Local_Constraint_System_BP __near *)
// Source: json
//------------------------------------------------------------------------------
hk_Local_Constraint_System *__thiscall hk_Local_Constraint_System::hk_Local_Constraint_System(
        hk_Local_Constraint_System *this,
        hk_Environment *env,
        hk_Local_Constraint_System_BP *bp)
{
  *(_DWORD *)&this->actuator_controlled_cores.memsize = 0;
  this->actuator_controlled_cores.elems = nullptr;
  this->m_environment = env;
  this->__vftable = (hk_Local_Constraint_System_vtbl *)&hk_Local_Constraint_System::`vftable';
  this->m_constraints.m_elems = nullptr;
  this->m_constraints.m_n_elems = 0;
  this->m_constraints.m_memsize = 0;
  this->m_bodies.m_n_elems = 0;
  this->m_bodies.m_memsize = 0;
  this->m_bodies.m_elems = nullptr;
  this->m_size_of_all_vmq_storages = 0;
  this->m_is_active = false;
  this->m_scErrorThisTick = Four_Zeros;
  this->m_errorCount = 0;
  this->m_client_data = nullptr;
  this->m_n_iterations = bp->m_n_iterations + 2;
  this->m_errorTolerance = bp->m_errorTolerance;
  this->m_minErrorTicks = bp->m_minErrorTicks;
  this->m_needsSort = false;
  this->m_penetrationCount = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10034AB0
// Name: public: virtual hk_Local_Constraint_System::~hk_Local_Constraint_System(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Local_Constraint_System::~hk_Local_Constraint_System(hk_Local_Constraint_System *this)
{
  bool v2; // sf
  int v3; // eax
  int v4; // ecx
  hk_Memory *instance; // eax
  hk_Memory *v6; // eax
  hk_Local_Constraint_System *elems; // eax
  char *m_elems; // [esp-Ch] [ebp-10h]
  char *v9; // [esp-Ch] [ebp-10h]
  int v10; // [esp-8h] [ebp-Ch]
  int v11; // [esp-8h] [ebp-Ch]

  v3 = this->m_constraints.m_n_elems - 1;
  v2 = this->m_constraints.m_n_elems == 0;
  this->__vftable = (hk_Local_Constraint_System_vtbl *)&hk_Local_Constraint_System::`vftable';
  if ( !v2 )
  {
    do
    {
      v4 = *(_DWORD *)&this->m_constraints.m_elems[4 * v3];
      if ( *(hk_Local_Constraint_System **)(v4 + 16) == this )
        *(_DWORD *)(v4 + 16) = 0;
      --v3;
    }
    while ( v3 >= 0 );
  }
  if ( this->m_is_active )
    IVP_Controller_Manager::remove_controller_from_environment(cntrl: this, silently: IVP_TRUE);
  if ( this->m_bodies.m_elems != nullptr )
  {
    v10 = 4 * this->m_bodies.m_memsize;
    m_elems = this->m_bodies.m_elems;
    instance = hk_Memory::get_instance();
    hk_Memory::deallocate(this: instance, p: m_elems, size: v10, cl: HK_MEMORY_CLASS_ARRAY);
  }
  if ( this->m_constraints.m_elems != nullptr )
  {
    v11 = 4 * this->m_constraints.m_memsize;
    v9 = this->m_constraints.m_elems;
    v6 = hk_Memory::get_instance();
    hk_Memory::deallocate(this: v6, p: v9, size: v11, cl: HK_MEMORY_CLASS_ARRAY);
  }
  this->__vftable = (hk_Local_Constraint_System_vtbl *)&hk_Link_EF::`vftable';
  elems = (hk_Local_Constraint_System *)this->actuator_controlled_cores.elems;
  if ( elems != (hk_Local_Constraint_System *)&this->m_n_iterations )
  {
    if ( elems != nullptr )
      free(data: elems);
    this->actuator_controlled_cores.elems = nullptr;
    this->actuator_controlled_cores.memsize = 0;
  }
  this->actuator_controlled_cores.n_elems = 0;
  this->__vftable = (hk_Local_Constraint_System_vtbl *)&IVP_Controller_Dependent::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10034B60
// Name: public: virtual void hk_Local_Constraint_System::core_is_going_to_be_deleted_event(class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Local_Constraint_System::core_is_going_to_be_deleted_event(
        hk_Local_Constraint_System *this,
        IVP_Core *my_core)
{
  int m_n_elems; // eax
  int v4; // esi

  m_n_elems = this->m_bodies.m_n_elems;
  if ( (_WORD)m_n_elems != 0 )
  {
    v4 = m_n_elems - 1;
    do
    {
      if ( *(IVP_Core **)(*(_DWORD *)&this->m_bodies.m_elems[4 * v4] + 148) == my_core )
        this->entity_deletion_event(this, a2: *(hk_Rigid_Body **)&this->m_bodies.m_elems[4 * v4]);
      --v4;
    }
    while ( v4 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034BB0
// Name: protected: void hk_Local_Constraint_System::recalc_storage_size(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Local_Constraint_System::recalc_storage_size(hk_Local_Constraint_System *this)
{
  bool v2; // sf
  int v3; // edi
  int v4; // ecx

  v3 = this->m_constraints.m_n_elems - 1;
  v2 = this->m_constraints.m_n_elems == 0;
  this->m_size_of_all_vmq_storages = 0;
  if ( !v2 )
  {
    do
    {
      v4 = *(_DWORD *)&this->m_constraints.m_elems[4 * v3];
      this->m_size_of_all_vmq_storages += (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
      --v3;
    }
    while ( v3 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034BE0
// Name: protected: void hk_Local_Constraint_System::add_constraint(class hk_Constraint __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Local_Constraint_System::add_constraint(
        hk_Local_Constraint_System *this,
        hk_Constraint *constraint,
        int storage_size)
{
  hk_Local_Constraint_System *v3; // edi
  hk_Rigid_Body **v4; // eax
  hk_Array_Base *p_m_bodies; // esi
  hk_Rigid_Body *v6; // ebx
  int v7; // eax
  char *v8; // ecx
  IVP_Core *physical_core; // ebx
  hk_Rigid_Body **v11; // [esp+8h] [ebp-8h]
  bool isActive; // [esp+Fh] [ebp-1h]
  int i; // [esp+18h] [ebp+8h]

  v3 = this;
  isActive = this->m_is_active;
  if ( isActive )
    hk_Local_Constraint_System::deactivate(this);
  if ( v3->m_constraints.m_n_elems >= v3->m_constraints.m_memsize )
    hk_Array_Base::grow_mem(this: &v3->m_constraints, size: 4);
  *(_DWORD *)&v3->m_constraints.m_elems[4 * v3->m_constraints.m_n_elems++] = constraint;
  v4 = &constraint->m_entities[1];
  i = 1;
  p_m_bodies = &v3->m_bodies;
  v11 = v4;
  do
  {
    v6 = *v4;
    v7 = p_m_bodies->m_n_elems - 1;
    if ( p_m_bodies->m_n_elems == 0 )
      goto LABEL_12;
    v8 = &p_m_bodies->m_elems[4 * v7];
    while ( *(hk_Rigid_Body **)v8 != v6 )
    {
      v8 -= 4;
      if ( --v7 < 0 )
        goto LABEL_12;
    }
    if ( v7 < 0 )
    {
LABEL_12:
      if ( p_m_bodies->m_n_elems >= p_m_bodies->m_memsize )
        hk_Array_Base::grow_mem(this: p_m_bodies, size: 4);
      *(_DWORD *)&p_m_bodies->m_elems[4 * p_m_bodies->m_n_elems++] = v6;
      physical_core = v6->physical_core;
      if ( (*(_BYTE *)&physical_core->IVP_Core_Fast_Static & 2) == 0 )
      {
        if ( v3->actuator_controlled_cores.n_elems >= v3->actuator_controlled_cores.memsize )
          IVP_U_Vector_Base::increment_mem(this: &v3->actuator_controlled_cores);
        v3->actuator_controlled_cores.elems[v3->actuator_controlled_cores.n_elems++] = physical_core;
        v3 = this;
      }
    }
    v4 = v11 - 1;
    --i;
    --v11;
  }
  while ( i >= 0 );
  v3->m_needsSort = true;
  if ( isActive )
    hk_Local_Constraint_System::activate(this: v3);
  v3->m_size_of_all_vmq_storages += storage_size;
}

//------------------------------------------------------------------------------
// Address: 0x10034CF0
// Name: public: void hk_Local_Constraint_System::get_constraints_in_system(class hk_Array<class hk_Constraint __near *> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Local_Constraint_System::get_constraints_in_system(
        hk_Local_Constraint_System *this,
        hk_Array<hk_Constraint *> *constraint_out)
{
  int v2; // edi
  int v3; // ebx
  hk_Local_Constraint_System *v4; // [esp+4h] [ebp-4h]

  v2 = this->m_constraints.m_n_elems - 1;
  v4 = this;
  if ( this->m_constraints.m_n_elems != 0 )
  {
    do
    {
      v3 = *(_DWORD *)&this->m_constraints.m_elems[4 * v2];
      if ( constraint_out->m_n_elems >= constraint_out->m_memsize )
      {
        hk_Array_Base::grow_mem(this: constraint_out, size: 4);
        this = v4;
      }
      *(_DWORD *)&constraint_out->m_elems[4 * constraint_out->m_n_elems++] = v3;
      --v2;
    }
    while ( v2 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034D40
// Name: protected: void hk_Local_Constraint_System::sort_constraints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Local_Constraint_System::sort_constraints(hk_Local_Constraint_System *this)
{
  bool v2; // sf
  int v3; // edi
  int v4; // ecx
  int v5; // ebx
  int v6; // ebx
  unsigned __int16 m_n_elems; // di
  int v8; // eax
  char *v9; // ecx
  int v10; // edx
  int v11; // edi
  int v12; // ebx
  hk_Memory *instance; // eax
  char *m_elems; // [esp+0h] [ebp-14h]
  int v15; // [esp+4h] [ebp-10h]
  hk_Array<hk_Constraint *> list; // [esp+Ch] [ebp-8h] BYREF

  v3 = this->m_constraints.m_n_elems - 1;
  v2 = this->m_constraints.m_n_elems == 0;
  *(_DWORD *)&list.m_memsize = 0;
  list.m_elems = nullptr;
  if ( !v2 )
  {
    do
    {
      v4 = *(_DWORD *)&this->m_constraints.m_elems[4 * v3];
      if ( (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 24))(a1: v4) == 0 )
      {
        v5 = *(_DWORD *)&this->m_constraints.m_elems[4 * v3];
        if ( list.m_n_elems >= list.m_memsize )
          hk_Array_Base::grow_mem(this: &list, size: 4);
        *(_DWORD *)&list.m_elems[4 * list.m_n_elems++] = v5;
      }
      --v3;
    }
    while ( v3 >= 0 );
  }
  v6 = list.m_n_elems - 1;
  if ( list.m_n_elems != 0 )
  {
    do
    {
      m_n_elems = this->m_constraints.m_n_elems;
      v8 = m_n_elems - 1;
      if ( m_n_elems != 0 )
      {
        v9 = &this->m_constraints.m_elems[4 * v8];
        while ( *(_DWORD *)v9 != *(_DWORD *)&list.m_elems[4 * v6] )
        {
          v9 -= 4;
          if ( --v8 < 0 )
            goto LABEL_12;
        }
      }
      else
      {
LABEL_12:
        v8 = -1;
      }
      v10 = (unsigned __int16)(m_n_elems - 1);
      this->m_constraints.m_n_elems = m_n_elems - 1;
      if ( v8 < v10 )
        *(_DWORD *)&this->m_constraints.m_elems[4 * v8] = *(_DWORD *)&this->m_constraints.m_elems[4 * v10];
      --v6;
    }
    while ( v6 >= 0 );
  }
  v11 = list.m_n_elems - 1;
  if ( list.m_n_elems != 0 )
  {
    do
    {
      v12 = *(_DWORD *)&list.m_elems[4 * v11];
      if ( this->m_constraints.m_n_elems >= this->m_constraints.m_memsize )
        hk_Array_Base::grow_mem(this: &this->m_constraints, size: 4);
      *(_DWORD *)&this->m_constraints.m_elems[4 * this->m_constraints.m_n_elems++] = v12;
      --v11;
    }
    while ( v11 >= 0 );
  }
  if ( list.m_elems != nullptr )
  {
    v15 = 4 * list.m_memsize;
    m_elems = list.m_elems;
    instance = hk_Memory::get_instance();
    hk_Memory::deallocate(this: instance, p: m_elems, size: v15, cl: HK_MEMORY_CLASS_ARRAY);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034E40
// Name: public: void hk_Local_Constraint_System::solve_penetration(class IVP_Real_Object __near *,class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Local_Constraint_System::solve_penetration(
        hk_Local_Constraint_System *this,
        IVP_Real_Object *pivp0,
        IVP_Real_Object *pivp1)
{
  int m_penetrationCount; // edi
  int v4; // eax
  IVP_Real_Object **v5; // edx
  int v6; // eax
  IVP_Real_Object **v7; // edx
  int v8; // eax

  m_penetrationCount = this->m_penetrationCount;
  if ( m_penetrationCount < 4 )
  {
    v4 = this->m_bodies.m_n_elems - 1;
    if ( this->m_bodies.m_n_elems != 0 )
    {
      v5 = (IVP_Real_Object **)&this->m_bodies.m_elems[4 * v4];
      while ( *v5 != pivp0 )
      {
        --v5;
        if ( --v4 < 0 )
          goto LABEL_6;
      }
    }
    else
    {
LABEL_6:
      LOWORD(v4) = -1;
    }
    this->m_penetrationPairs[m_penetrationCount].obj0 = v4;
    v6 = this->m_bodies.m_n_elems - 1;
    if ( this->m_bodies.m_n_elems != 0 )
    {
      v7 = (IVP_Real_Object **)&this->m_bodies.m_elems[4 * v6];
      while ( *v7 != pivp1 )
      {
        --v7;
        if ( --v6 < 0 )
          goto LABEL_11;
      }
    }
    else
    {
LABEL_11:
      LOWORD(v6) = -1;
    }
    this->m_penetrationPairs[this->m_penetrationCount].obj1 = v6;
    v8 = this->m_penetrationCount;
    if ( this->m_penetrationPairs[v8].obj0 >= 0 && this->m_penetrationPairs[v8].obj1 >= 0 )
      this->m_penetrationCount = v8 + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034EC0
// Name: public: virtual void hk_Local_Constraint_System::apply_effector_PSI(class hk_PSI_Info __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge hk_Local_Constraint_System::apply_effector_PSI(
        hk_Local_Constraint_System *this@<ecx>,
        int a2@<ebp>,
        hk_PSI_Info *pi)
{
  void *v3; // esp
  __int16 *v5; // eax
  _BYTE *v6; // edi
  int v7; // ecx
  int v8; // eax
  int m_n_elems; // ecx
  float v10; // ecx
  int v11; // xmm0_4
  int v12; // edi
  int v13; // ecx
  int v14; // edi
  int v15; // ecx
  hk_Environment *m_environment; // eax
  double v17; // st7
  bool v18; // sf
  int v19; // edx
  float v20; // xmm1_4
  char *v21; // edi
  bool v22; // cc
  __int16 *p_obj1; // ecx
  char *m_elems; // eax
  IVP_Real_Object *v25; // edx
  IVP_Real_Object *v26; // eax
  IVP_Core *physical_core; // edi
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  const IVP_U_Point *v31; // edx
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm1_4
  float v36; // xmm2_4
  float v37; // xmm0_4
  float v38; // xmm2_4
  float v39; // xmm1_4
  IVP_Real_Object *v40; // edi
  IVP_Real_Object *v41; // edi
  int m_errorCount; // eax
  _BYTE v43[153992]; // [esp+40h] [ebp-25A44h] BYREF
  IVP_U_Float_Point v44; // [esp+259C8h] [ebp-BCh] BYREF
  IVP_U_Float_Point v45; // [esp+259D8h] [ebp-ACh] BYREF
  _DWORD v46[10]; // [esp+259E8h] [ebp-9Ch]
  _DWORD v47[10]; // [esp+25A10h] [ebp-74h]
  float v48; // [esp+25A38h] [ebp-4Ch]
  IVP_Real_Object *v49; // [esp+25A3Ch] [ebp-48h]
  const IVP_U_Point *v50; // [esp+25A40h] [ebp-44h]
  IVP_Real_Object *v51; // [esp+25A44h] [ebp-40h]
  IVP_U_Float_Point v52; // [esp+25A48h] [ebp-3Ch] BYREF
  IVP_U_Float_Point v53; // [esp+25A58h] [ebp-2Ch] BYREF
  int v54; // [esp+25A68h] [ebp-1Ch]
  float v55; // [esp+25A6Ch] [ebp-18h]
  float delta_PSI_time; // [esp+25A70h] [ebp-14h]
  __int16 *i; // [esp+25A74h] [ebp-10h]
  int v58; // [esp+25A78h] [ebp-Ch]
  void *v59; // [esp+25A7Ch] [ebp-8h]
  void *retaddr; // [esp+25A84h] [ebp+0h]

  v58 = a2;
  v59 = retaddr;
  v3 = alloca(154184);
  if ( this->m_needsSort )
  {
    hk_Local_Constraint_System::sort_constraints(this);
    this->m_needsSort = false;
  }
  v46[3] = 1058642330;
  v5 = nullptr;
  this->m_scErrorThisTick = Four_Zeros;
  v46[4] = 1053609165;
  v46[5] = 1053609165;
  v46[6] = 1053609165;
  v46[7] = 1053609165;
  v46[8] = 1053609165;
  v6 = v43;
  v46[0] = 1065353216;
  v46[1] = 1065353216;
  v46[2] = 1061997773;
  v46[9] = 0;
  v47[0] = 1065353216;
  v47[1] = 1065353216;
  v47[2] = 1061997773;
  v47[3] = 1061997773;
  v47[4] = 1061997773;
  v47[5] = 1061997773;
  v47[6] = 1061997773;
  v47[7] = 1061997773;
  v47[8] = 1061997773;
  v47[9] = 0;
  i = nullptr;
  if ( this->m_constraints.m_n_elems != 0 )
  {
    while ( 1 )
    {
      v7 = *(_DWORD *)&this->m_constraints.m_elems[4 * (_DWORD)v5];
      *(_DWORD *)&v43[4 * (_DWORD)v5 + 149992] = v6;
      v8 = (*(int (__thiscall **)(int, hk_PSI_Info *, _BYTE *, int, int))(*(_DWORD *)v7 + 12))(
             a1: v7,
             a2: pi,
             a3: v6,
             a4: 1065353216,
             a5: 1065353216);
      m_n_elems = this->m_constraints.m_n_elems;
      v6 += v8;
      i = (__int16 *)((char *)i + 1);
      if ( (int)i >= m_n_elems )
        break;
      v5 = i;
    }
  }
  v10 = 0.0;
  delta_PSI_time = 0.0;
  if ( this->m_n_iterations > 0 )
  {
    do
    {
      v54 = v46[LODWORD(v10)];
      v11 = v54;
      v55 = *(float *)&v54;
      if ( *(float *)&v54 == 0.0 )
        break;
      v12 = this->m_constraints.m_n_elems - 1;
      if ( this->m_constraints.m_n_elems != 0 )
      {
        i = (__int16 *)v47[LODWORD(v10)];
        while ( 1 )
        {
          v13 = *(_DWORD *)&this->m_constraints.m_elems[4 * v12];
          (*(void (__thiscall **)(int, hk_PSI_Info *, _DWORD, int, __int16 *))(*(_DWORD *)v13 + 16))(
            a1: v13,
            a2: pi,
            a3: *(_DWORD *)&v43[4 * v12-- + 149992],
            a4: v11,
            a5: i);
          if ( v12 < 0 )
            break;
          v11 = v54;
        }
        v10 = delta_PSI_time;
      }
      v14 = 0;
      if ( this->m_constraints.m_n_elems != 0 )
      {
        i = (__int16 *)v47[LODWORD(v10)];
        do
        {
          v15 = *(_DWORD *)&this->m_constraints.m_elems[4 * v14];
          (*(void (__thiscall **)(int, hk_PSI_Info *, _DWORD, float, __int16 *))(*(_DWORD *)v15 + 16))(
            a1: v15,
            a2: pi,
            a3: *(_DWORD *)&v43[4 * v14++ + 149992],
            a4: COERCE_FLOAT(LODWORD(v55)),
            a5: i);
        }
        while ( v14 < this->m_constraints.m_n_elems );
        v10 = delta_PSI_time;
      }
      ++LODWORD(v10);
      delta_PSI_time = v10;
    }
    while ( SLODWORD(v10) < this->m_n_iterations );
  }
  if ( this->m_penetrationCount != 0 )
  {
    m_environment = this->m_environment;
    delta_PSI_time = m_environment->delta_PSI_time;
    v17 = IVP_U_Float_Point::fast_real_length(this: &m_environment->gravity);
    v19 = this->m_bodies.m_n_elems - 1;
    v18 = this->m_bodies.m_n_elems == 0;
    v20 = 0.0;
    v55 = (v17 + v17) * delta_PSI_time;
    if ( !v18 )
    {
      v21 = &this->m_bodies.m_elems[4 * v19];
      do
      {
        if ( *(_DWORD *)v21 != 0 )
          v20 = COERCE_FLOAT(GetMoveableMass(pCore: (IVP_Core *)*(_DWORD *)(*(_DWORD *)v21 + 148))) + v20;
        v21 -= 4;
        --v19;
      }
      while ( v19 >= 0 );
    }
    v22 = this->m_penetrationCount <= 0;
    *(float *)&v54 = 0.0;
    if ( !v22 )
    {
      p_obj1 = &this->m_penetrationPairs[0].obj1;
      v48 = v20 * v55;
      for ( i = &this->m_penetrationPairs[0].obj1; ; p_obj1 = i )
      {
        m_elems = this->m_bodies.m_elems;
        v25 = *(IVP_Real_Object **)&m_elems[4 * *(p_obj1 - 1)];
        v26 = *(IVP_Real_Object **)&m_elems[4 * *p_obj1];
        physical_core = v26->physical_core;
        v28 = physical_core->m_world_f_core_last_psi.vv.k[1];
        v29 = physical_core->m_world_f_core_last_psi.vv.k[2];
        v30 = physical_core->m_world_f_core_last_psi.vv.k[0];
        v51 = v25;
        v31 = (const IVP_U_Point *)v25->physical_core;
        v32 = v28 - v31[9].k[1];
        v33 = v29 - v31[9].k[2];
        v34 = v30 - v31[9].k[0];
        v49 = v26;
        v50 = v31;
        LODWORD(v55) = &v31[9];
        v52.k[0] = v34;
        v52.k[1] = v32;
        v52.k[2] = v33;
        if ( IVP_U_Float_Point::real_length_plus_normize(this: &v52) > 0.01 )
        {
          v35 = v52.k[2];
          v36 = v52.k[1];
        }
        else
        {
          v35 = 0.0;
          v36 = 0.0;
          v52.k[0] = 1.0;
          v52.k[1] = 0.0;
          v52.k[2] = 0.0;
        }
        v37 = v48 * v52.k[0];
        v38 = v36 * v48;
        v39 = v35 * v48;
        v53.k[0] = v48 * v52.k[0];
        v53.k[1] = v38;
        v53.k[2] = v39;
        if ( *((_BYTE *)&physical_core->IVP_Core_Fast_Static + 1) < 8u
          && (*(_BYTE *)&physical_core->IVP_Core_Fast_Static & 0x10) == 0 )
        {
          v40 = v49;
          IVP_Real_Object::async_push_object_ws(
            this: v49,
            position_ws_: (const IVP_U_Point *)LODWORD(v55),
            impulse_ws_: &v53);
          v44.k[0] = delta_PSI_time;
          v44.k[1] = 0.0;
          v44.k[2] = 0.0;
          IVP_Real_Object::async_add_rot_speed_object_cs(this: v40, rotation_vec: &v44);
          v39 = v53.k[2];
          v38 = v53.k[1];
          v37 = v53.k[0];
        }
        if ( BYTE1(v50->k[0]) < 8u && (LOBYTE(v50->k[0]) & 0x10) == 0 )
        {
          v41 = v51;
          v53.k[0] = v37 * -1.0;
          v53.k[1] = v38 * -1.0;
          v53.k[2] = v39 * -1.0;
          IVP_Real_Object::async_push_object_ws(
            this: v51,
            position_ws_: (const IVP_U_Point *)LODWORD(v55),
            impulse_ws_: &v53);
          v45.k[0] = -delta_PSI_time;
          v45.k[1] = 0.0;
          v45.k[2] = 0.0;
          IVP_Real_Object::async_add_rot_speed_object_cs(this: v41, rotation_vec: &v45);
        }
        i += 2;
        if ( ++v54 >= this->m_penetrationCount )
          break;
      }
    }
    this->m_penetrationCount = 0;
  }
  if ( this->m_scErrorThisTick.m128_f32[0] <= (float)(this->m_errorTolerance * this->m_errorTolerance) )
  {
    this->m_errorCount = 0;
  }
  else
  {
    m_errorCount = this->m_errorCount;
    if ( m_errorCount <= this->m_minErrorTicks )
      this->m_errorCount = m_errorCount + 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035390
// Name: public: virtual void hk_Local_Constraint_System::entity_deletion_event(class hk_Rigid_Body __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Local_Constraint_System::entity_deletion_event(
        hk_Local_Constraint_System *this,
        hk_Rigid_Body *entity)
{
  unsigned __int16 m_n_elems; // si
  int v3; // eax
  hk_Rigid_Body **v4; // edx
  int v5; // edx

  m_n_elems = this->m_bodies.m_n_elems;
  v3 = m_n_elems - 1;
  if ( m_n_elems != 0 )
  {
    v4 = (hk_Rigid_Body **)&this->m_bodies.m_elems[4 * v3];
    while ( *v4 != entity )
    {
      --v4;
      if ( --v3 < 0 )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v3 = -1;
  }
  this->m_bodies.m_n_elems = m_n_elems - 1;
  v5 = (unsigned __int16)(m_n_elems - 1);
  if ( v3 < v5 )
    *(_DWORD *)&this->m_bodies.m_elems[4 * v3] = *(_DWORD *)&this->m_bodies.m_elems[4 * v5];
  if ( (*(_BYTE *)&entity->physical_core->IVP_Core_Fast_Static & 2) == 0 )
    IVP_U_Vector<IVP_OV_Element>::remove(
      this: (IVP_U_Vector<IVP_Listener_Object> *)&this->actuator_controlled_cores,
      elem: (IVP_Listener_Object *)entity->physical_core);
}

//------------------------------------------------------------------------------
// Address: 0x100353F0
// Name: public: void hk_Local_Constraint_System::constraint_deletion_event(class hk_Constraint __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Local_Constraint_System::constraint_deletion_event(
        hk_Local_Constraint_System *this,
        hk_Constraint *constraint)
{
  unsigned __int16 m_n_elems; // si
  int v3; // eax
  hk_Constraint **v4; // edx

  m_n_elems = this->m_constraints.m_n_elems;
  v3 = m_n_elems - 1;
  if ( m_n_elems != 0 )
  {
    v4 = (hk_Constraint **)&this->m_constraints.m_elems[4 * v3];
    while ( *v4 != constraint )
    {
      --v4;
      if ( --v3 < 0 )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v3 = -1;
  }
  for ( this->m_constraints.m_n_elems = m_n_elems - 1; v3 < this->m_constraints.m_n_elems; ++v3 )
    *(_DWORD *)&this->m_constraints.m_elems[4 * v3] = *(_DWORD *)&this->m_constraints.m_elems[4 * v3 + 4];
  if ( this->m_constraints.m_n_elems != 0 )
    hk_Local_Constraint_System::recalc_storage_size(this);
}

//------------------------------------------------------------------------------
// Address: 0x10047340
// Name: public: IVP_U_Vector<class IVV_Sphere>::IVP_U_Vector<class IVV_Sphere>(int)
// Source: json
//------------------------------------------------------------------------------
IVP_U_Vector<IVV_Sphere> *__thiscall IVP_U_Vector<IVV_Sphere>::IVP_U_Vector<IVV_Sphere>(
        IVP_U_Vector<IVV_Sphere> *this,
        int size)
{
  this->memsize = size;
  this->n_elems = 0;
  if ( size != 0 )
    this->elems = (void **)p_malloc(size: 4 * size);
  else
    this->elems = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10075870
// Name: public: int IVP_U_Vector<class IVP_Real_Object>::add(class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_U_Vector<IVP_Real_Object>::add(IVP_U_Vector<IVP_Real_Object> *this, IVP_Real_Object *elem)
{
  int result; // eax

  if ( this->n_elems >= this->memsize )
    IVP_U_Vector_Base::increment_mem(this);
  this->elems[this->n_elems] = elem;
  result = this->n_elems;
  this->n_elems = result + 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10076080
// Name: public: void IVP_U_Vector<class IVP_Core>::remove_at(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Vector<IVP_Core>::remove_at(IVP_U_Vector<IVP_Sim_Unit_Controller_Core_List> *this, int index)
{
  int v2; // eax

  v2 = index;
  if ( index >= this->n_elems - 1 )
  {
    --this->n_elems;
  }
  else
  {
    do
    {
      this->elems[v2] = this->elems[v2 + 1];
      ++v2;
    }
    while ( v2 < this->n_elems - 1 );
    --this->n_elems;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10082560
// Name: public: virtual class IVP_U_Vector<class IVP_Core> __near * IVP_Friction_System::get_associated_controlled_cores(void)
// Source: json
//------------------------------------------------------------------------------
IVP_U_Vector<IVP_Core> *__thiscall IVP_Friction_System::get_associated_controlled_cores(IVP_Friction_System *this)
{
  return &this->moveable_cores_of_friction_system;
}

//------------------------------------------------------------------------------
// Address: 0x100840C0
// Name: public: void IVP_U_Vector<class IVP_OV_Element>::remove(class IVP_OV_Element __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_U_Vector<IVP_OV_Element>::remove(
        IVP_U_Vector<IVP_Listener_Object> *this,
        IVP_Listener_Object *elem)
{
  unsigned __int16 n_elems; // si
  int v3; // eax
  IVP_Listener_Object **v4; // edx

  n_elems = this->n_elems;
  v3 = n_elems - 1;
  if ( n_elems != 0 )
  {
    v4 = (IVP_Listener_Object **)&this->elems[v3];
    do
    {
      if ( *v4 == elem )
        break;
      --v4;
      --v3;
    }
    while ( v3 >= 0 );
  }
  for ( this->n_elems = n_elems - 1; v3 < this->n_elems; ++v3 )
    this->elems[v3] = this->elems[v3 + 1];
}

//------------------------------------------------------------------------------
// Address: 0x1008BE90
// Name: protected: virtual class IVP_U_Vector<class IVP_Core> __near * IVP_Controller_Raycast_Car::get_associated_controlled_cores(void)
// Source: json
//------------------------------------------------------------------------------
IVP_U_Vector<IVP_Core> *__thiscall IVP_Controller_Raycast_Car::get_associated_controlled_cores(IVP_Actuator *this)
{
  return &this->actuator_controlled_cores;
}

//------------------------------------------------------------------------------
// Address: 0x100942D0
// Name: public: virtual class IVP_U_Vector<class IVP_Core> __near * IVP_Constraint_Solver_Car::get_associated_controlled_cores(void)
// Source: json
//------------------------------------------------------------------------------
IVP_U_Vector<IVP_Core> *__thiscall IVP_Constraint_Solver_Car::get_associated_controlled_cores(
        IVP_Constraint_Solver_Car *this)
{
  return &this->cores_of_constraint_system;
}

//------------------------------------------------------------------------------
// Address: 0x100A6E40
// Name: public: virtual enum IVP_CONTROLLER_PRIORITY hk_Link_EF::get_controller_priority(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall hk_Link_EF::get_controller_priority(IVP_Constraint *this)
{
  return 405;
}
