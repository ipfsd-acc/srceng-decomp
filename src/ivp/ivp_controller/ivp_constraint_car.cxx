// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_controller/ivp_constraint_car.cxx
// Functions: 11
// ============================================================

#include "ivp\ivp_controller\ivp_constraint_car.h"

//------------------------------------------------------------------------------
// Address: 0x1000F1B0
// Name: public: virtual char const __near * IVP_Constraint_Solver_Car::get_controller_name(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall IVP_Constraint_Solver_Car::get_controller_name(IVP_Constraint_Solver_Car *this)
{
  return "sys:vehicle";
}

//------------------------------------------------------------------------------
// Address: 0x10093AC0
// Name: public: IVP_Constraint_Car_Object::IVP_Constraint_Car_Object(class IVP_Constraint_Solver_Car __near *,class IVP_Real_Object __near *,class IVP_Real_Object __near *,class IVP_U_Float_Point __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
IVP_Constraint_Car_Object *__userpurge IVP_Constraint_Car_Object::IVP_Constraint_Car_Object@<eax>(
        IVP_Constraint_Car_Object *this@<ecx>,
        int a2@<ebp>,
        IVP_Constraint_Solver_Car *solver_car_,
        IVP_Real_Object *i_real_obj_app,
        IVP_Real_Object *i_real_obj_body,
        IVP_U_Float_Point *target_Bos_override)
{
  _BYTE v8[12]; // [esp-Ch] [ebp-5Ch] BYREF
  __int64 m_core_f_object_60; // [esp+3Ch] [ebp-14h] OVERLAPPED
  int v10; // [esp+44h] [ebp-Ch]
  void *v11; // [esp+48h] [ebp-8h]
  void *retaddr; // [esp+50h] [ebp+0h]

  v10 = a2;
  v11 = retaddr;
  this->solver_car = solver_car_;
  this->real_object = i_real_obj_app;
  this->fix_wheel_constraint = nullptr;
  i_real_obj_app->physical_core->car_wheel = this;
  this->last_skid_value = 0.0;
  this->last_contact_position_ws.k[2] = 0.0;
  this->last_contact_position_ws.k[1] = 0.0;
  this->last_contact_position_ws.k[0] = 0.0;
  m_core_f_object_60 = 0;
  this->last_skid_time.seconds = 0.0;
  if ( i_real_obj_body != nullptr )
  {
    if ( target_Bos_override != nullptr )
    {
      IVP_U_Matrix::init(this: &this->target_position_bs);
      IVP_Real_Object::calc_m_core_f_object(this: i_real_obj_body, m_core_f_object: (IVP_U_Matrix *)v8);
      IVP_U_Matrix::vmult4(this: (IVP_U_Matrix *)v8, p_in: target_Bos_override, p_out: &this->target_position_bs.vv);
    }
    else
    {
      IVP_U_Matrix::mimult4(
        this: &i_real_obj_body->physical_core->m_world_f_core_last_psi,
        mb: &i_real_obj_app->physical_core->m_world_f_core_last_psi,
        m_out: &this->target_position_bs);
    }
    return this;
  }
  else
  {
    IVP_U_Matrix::init(this: &this->target_position_bs);
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10093BA0
// Name: protected: virtual void IVP_Constraint_Solver_Car::core_is_going_to_be_deleted_event(class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Constraint_Solver_Car::core_is_going_to_be_deleted_event(
        IVP_Constraint_Solver_Car *this,
        IVP_Core *__formal)
{
  int v2; // eax
  IVP_Constraint **c_local_ballsocket; // edx

  v2 = 0;
  if ( this->wheel_objects.n_elems != 0 )
  {
    c_local_ballsocket = this->c_local_ballsocket;
    do
    {
      *c_local_ballsocket = nullptr;
      ++v2;
      ++c_local_ballsocket;
    }
    while ( v2 < this->wheel_objects.n_elems );
  }
  ((void (__thiscall *)(IVP_Constraint_Solver_Car *, int))this->dtr_IVP_Controller)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10093BD0
// Name: private: void IVP_Constraint_Solver_Car_Builder::calc_pushing_behavior(int,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge IVP_Constraint_Solver_Car_Builder::calc_pushing_behavior(
        IVP_Constraint_Solver_Car_Builder *this@<ecx>,
        IVP_Core *a2@<ebp>,
        int A_obj_idx,
        int push_vec_idx)
{
  IVP_Constraint_Solver_Car *car_solver; // eax
  char *v5; // edx
  IVP_Constraint_Car_Object *body_object; // eax
  IVP_U_Matrix3 *v7; // edi
  int v8; // esi
  IVP_Constraint_Solver_Car_Builder *v9; // eax
  int v10; // edx
  IVP_BOOL *constraint_is_disabled; // ecx
  IVP_Constraint_Solver_Car *v12; // ecx
  int v13; // edi
  int v14; // esi
  float val; // xmm0_4
  float v16; // xmm1_4
  const IVP_U_Matrix *v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm4_4
  IVP_Constraint_Solver_Car *v20; // ecx
  bool v21; // zf
  int n_elems; // edx
  _BYTE v23[12]; // [esp+1Ch] [ebp-1CCh] BYREF
  IVP_U_Matrix m_B_from_A; // [esp+28h] [ebp-1C0h] BYREF
  _BYTE inv_impulse_A_4[65]; // [esp+6Ch] [ebp-17Ch] OVERLAPPED BYREF
  IVP_U_Float_Point app_center_B; // [esp+B8h] [ebp-130h] BYREF
  IVP_U_Float_Point impulse_A; // [esp+C8h] [ebp-120h] BYREF
  IVP_U_Float_Point impulse_world; // [esp+D8h] [ebp-110h] BYREF
  IVP_U_Float_Point B_at_app_speed_world; // [esp+E8h] [ebp-100h] BYREF
  IVP_U_Float_Point inv_impulse_world; // [esp+F8h] [ebp-F0h] BYREF
  IVP_U_Float_Point sur_speed_B_world; // [esp+108h] [ebp-E0h] BYREF
  IVP_U_Float_Point B_push_pos_in_B; // [esp+118h] [ebp-D0h] BYREF
  IVP_U_Float_Point inv_impulse_B; // [esp+128h] [ebp-C0h] BYREF
  IVP_U_Float_Point sur_speed_B_in_B; // [esp+138h] [ebp-B0h] BYREF
  IVP_U_Float_Point A_push_pos_in_A; // [esp+148h] [ebp-A0h] BYREF
  IVP_U_Float_Point speed_change_B_world; // [esp+158h] [ebp-90h] BYREF
  IVP_U_Float_Point speed_change_A_in_B; // [esp+168h] [ebp-80h] BYREF
  IVP_U_Float_Point rot_change_A_in_B; // [esp+178h] [ebp-70h] BYREF
  IVP_U_Float_Point impulse_B; // [esp+188h] [ebp-60h] BYREF
  IVP_U_Float_Point rot_change_B_in_B; // [esp+198h] [ebp-50h]
  IVP_U_Matrix *v41; // [esp+1B8h] [ebp-30h]
  float v42; // [esp+1BCh] [ebp-2Ch] BYREF
  float v43; // [esp+1C0h] [ebp-28h]
  const IVP_U_Matrix *m_world_f_B; // [esp+1C4h] [ebp-24h]
  IVP_U_Float_Point delta_speed_change; // [esp+1C8h] [ebp-20h]
  IVP_Constraint_Solver_Car_Builder *v46; // [esp+1D8h] [ebp-10h]
  IVP_Core *core_B; // [esp+1DCh] [ebp-Ch]
  int fill_app_idx; // [esp+1E0h] [ebp-8h]
  int retaddr; // [esp+1E8h] [ebp+0h]

  core_B = a2;
  fill_app_idx = retaddr;
  car_solver = this->car_solver;
  v46 = this;
  v5 = (char *)car_solver->wheel_objects.elems[A_obj_idx];
  body_object = car_solver->body_object;
  delta_speed_change.hesse_val = *(float *)(*(_DWORD *)v5 + 148);
  LODWORD(delta_speed_change.k[2]) = body_object->real_object->physical_core;
  qmemcpy(inv_impulse_A_4, (const void *)(LODWORD(delta_speed_change.k[2]) + 96), 0x40u);
  v41 = (IVP_U_Matrix *)(LODWORD(delta_speed_change.k[2]) + 96);
  IVP_U_Matrix::mmult4(
    this: (IVP_U_Matrix *)(LODWORD(delta_speed_change.k[2]) + 96),
    mb: (const IVP_U_Matrix *)(v5 + 16),
    m_out: (IVP_U_Matrix *)inv_impulse_A_4);
  v7 = v41;
  IVP_U_Matrix::mimult4(this: v41, mb: (const IVP_U_Matrix *)inv_impulse_A_4, m_out: (IVP_U_Matrix *)v23);
  v8 = push_vec_idx;
  memset(&rot_change_A_in_B.k[1], 0, 12);
  rot_change_A_in_B.k[push_vec_idx % 3 + 1] = 1.0;
  IVP_U_Matrix3::vmult3(
    this: v7,
    p_in: (IVP_U_Float_Point *)&rot_change_A_in_B.k[1],
    p_out: (IVP_U_Float_Point *)&impulse_A.k[1]);
  IVP_U_Matrix3::vimult3(
    this: (IVP_U_Matrix3 *)inv_impulse_A_4,
    p_in: (IVP_U_Float_Point *)&impulse_A.k[1],
    p_out: (IVP_U_Float_Point *)&app_center_B.k[1]);
  B_push_pos_in_B.k[1] = -rot_change_A_in_B.k[1];
  B_push_pos_in_B.k[2] = -rot_change_A_in_B.k[2];
  B_push_pos_in_B.hesse_val = -rot_change_A_in_B.hesse_val;
  IVP_U_Matrix3::vmult3(
    this: v7,
    p_in: (IVP_U_Float_Point *)&B_push_pos_in_B.k[1],
    p_out: (IVP_U_Float_Point *)&B_at_app_speed_world.k[1]);
  IVP_U_Matrix3::vimult3(
    this: (IVP_U_Matrix3 *)inv_impulse_A_4,
    p_in: (IVP_U_Float_Point *)&B_at_app_speed_world.k[1],
    p_out: (IVP_U_Float_Point *)&m_B_from_A.vv.k[1]);
  memset(&sur_speed_B_in_B.k[1], 0, 12);
  IVP_U_Matrix::vmult4(
    this: (IVP_U_Matrix *)v23,
    p_in: (IVP_U_Float_Point *)&sur_speed_B_in_B.k[1],
    p_out: (IVP_U_Float_Point *)&sur_speed_B_world.k[1]);
  if ( push_vec_idx <= 2 )
  {
    IVP_Core::test_push_core(
      this: (IVP_Core *)LODWORD(delta_speed_change.hesse_val),
      point_cs: (IVP_U_Float_Point *)&sur_speed_B_in_B.k[1],
      impulse_in_core: (IVP_U_Float_Point *)&app_center_B.k[1],
      impulse_in_world: (IVP_U_Float_Point *)&impulse_A.k[1],
      speed_out: (IVP_U_Float_Point *)&v42,
      rot_out: (IVP_U_Float_Point *)&impulse_world.k[1]);
    IVP_U_Matrix3::vimult3(
      this: v7,
      p_in: (const IVP_U_Float_Point *)&v42,
      p_out: (IVP_U_Float_Point *)&speed_change_B_world.k[1]);
    memset(&speed_change_A_in_B.k[1], 0, 12);
    IVP_Core::test_push_core(
      this: (IVP_Core *)LODWORD(delta_speed_change.k[2]),
      point_cs: (IVP_U_Float_Point *)&sur_speed_B_world.k[1],
      impulse_in_core: (IVP_U_Float_Point *)&B_push_pos_in_B.k[1],
      impulse_in_world: (IVP_U_Float_Point *)&B_at_app_speed_world.k[1],
      speed_out: (IVP_U_Float_Point *)&A_push_pos_in_A.k[1],
      rot_out: (IVP_U_Float_Point *)&impulse_B.k[1]);
    IVP_Core::get_surface_speed_on_test(
      this: (IVP_Core *)LODWORD(delta_speed_change.k[2]),
      point_cs: (IVP_U_Float_Point *)&sur_speed_B_world.k[1],
      center_speed_ws: (IVP_U_Float_Point *)&A_push_pos_in_A.k[1],
      rot_speed_cs: (IVP_U_Float_Point *)&impulse_B.k[1],
      speed_out_ws: (IVP_U_Float_Point *)&inv_impulse_world.k[1]);
    IVP_U_Matrix3::vimult3(
      this: v7,
      p_in: (IVP_U_Float_Point *)&inv_impulse_world.k[1],
      p_out: (IVP_U_Float_Point *)&inv_impulse_B.k[1]);
  }
  if ( push_vec_idx >= 3 )
  {
    IVP_Core::test_rot_push_core_multiple_cs(
      this: (IVP_Core *)LODWORD(delta_speed_change.hesse_val),
      normized_core_axis: (IVP_U_Float_Point *)&app_center_B.k[1],
      rot_impulse: 1.0,
      delta_rot_speed_out: (IVP_U_Float_Point *)&v42);
    IVP_U_Matrix3::vmult3(
      this: (IVP_U_Matrix3 *)v23,
      p_in: (const IVP_U_Float_Point *)&v42,
      p_out: (IVP_U_Float_Point *)&speed_change_A_in_B.k[1]);
    memset(&speed_change_B_world.k[1], 0, 12);
    IVP_Core::test_rot_push_core_multiple_cs(
      this: (IVP_Core *)LODWORD(delta_speed_change.k[2]),
      normized_core_axis: (IVP_U_Float_Point *)&rot_change_A_in_B.k[1],
      rot_impulse: -1.0,
      delta_rot_speed_out: (IVP_U_Float_Point *)&impulse_B.k[1]);
    memset(&A_push_pos_in_A.k[1], 0, 12);
    IVP_Core::get_surface_speed_on_test(
      this: (IVP_Core *)LODWORD(delta_speed_change.k[2]),
      point_cs: (IVP_U_Float_Point *)&sur_speed_B_world.k[1],
      center_speed_ws: (IVP_U_Float_Point *)&A_push_pos_in_A.k[1],
      rot_speed_cs: (IVP_U_Float_Point *)&impulse_B.k[1],
      speed_out_ws: (IVP_U_Float_Point *)&inv_impulse_world.k[1]);
    IVP_U_Matrix3::vimult3(
      this: v7,
      p_in: (IVP_U_Float_Point *)&inv_impulse_world.k[1],
      p_out: (IVP_U_Float_Point *)&inv_impulse_B.k[1]);
  }
  v9 = v46;
  v10 = 0;
  if ( push_vec_idx > 0 )
  {
    constraint_is_disabled = v46->car_solver->constraint_is_disabled;
    do
    {
      if ( *constraint_is_disabled == IVP_FALSE )
        ++v10;
      ++constraint_is_disabled;
      --v8;
    }
    while ( v8 != 0 );
  }
  v12 = v46->car_solver;
  v13 = v10 + A_obj_idx * v46->n_constraints;
  v14 = 0;
  delta_speed_change.hesse_val = 0.0;
  if ( v12->wheel_objects.n_elems != 0 )
  {
    do
    {
      if ( LODWORD(delta_speed_change.hesse_val) == A_obj_idx )
      {
        val = speed_change_B_world.k[1] - inv_impulse_B.k[1];
        v16 = speed_change_B_world.k[2] - inv_impulse_B.k[2];
        *(float *)&v17 = speed_change_B_world.hesse_val - inv_impulse_B.hesse_val;
        v18 = speed_change_A_in_B.k[1] - impulse_B.k[1];
        v19 = speed_change_A_in_B.k[2] - impulse_B.k[2];
        rot_change_B_in_B.hesse_val = speed_change_A_in_B.hesse_val - impulse_B.hesse_val;
      }
      else
      {
        IVP_U_Matrix::vimult4(
          this: v41,
          p_in: (const IVP_U_Float_Point *)(*(_DWORD *)(*(_DWORD *)v12->wheel_objects.elems[LODWORD(delta_speed_change.hesse_val)]
                                                + 148)
                                    + 144),
          p_out: (IVP_U_Float_Point *)&inv_impulse_A_4[64]);
        IVP_Core::get_surface_speed_on_test(
          this: (IVP_Core *)LODWORD(delta_speed_change.k[2]),
          point_cs: (const IVP_U_Float_Point *)&inv_impulse_A_4[64],
          center_speed_ws: (IVP_U_Float_Point *)&A_push_pos_in_A.k[1],
          rot_speed_cs: (IVP_U_Float_Point *)&impulse_B.k[1],
          speed_out_ws: (IVP_U_Float_Point *)&impulse_world.k[1]);
        IVP_U_Matrix3::vimult3(
          this: v41,
          p_in: (IVP_U_Float_Point *)&impulse_world.k[1],
          p_out: (IVP_U_Float_Point *)&v42);
        v9 = v46;
        val = v42 * -1.0;
        v16 = v43 * -1.0;
        *(float *)&v17 = *(float *)&m_world_f_B * -1.0;
        v18 = -impulse_B.k[1];
        v19 = -impulse_B.k[2];
        rot_change_B_in_B.hesse_val = -impulse_B.hesse_val;
      }
      v20 = v9->car_solver;
      m_world_f_B = v17;
      v43 = v16;
      v42 = val;
      v21 = v20->constraint_is_disabled[0] == IVP_FALSE;
      rot_change_B_in_B.k[2] = v19;
      rot_change_B_in_B.k[1] = v18;
      if ( v21 )
      {
        IVP_Great_Matrix_Many_Zero::set_value(this: &v9->tmp_matrix, val, col: v13, row: v14);
        v17 = m_world_f_B;
        v16 = v43;
        v19 = rot_change_B_in_B.k[2];
        v18 = rot_change_B_in_B.k[1];
        v9 = v46;
        ++v14;
      }
      if ( v9->car_solver->constraint_is_disabled[1] == IVP_FALSE )
      {
        IVP_Great_Matrix_Many_Zero::set_value(this: &v9->tmp_matrix, val: v16, col: v13, row: v14);
        v17 = m_world_f_B;
        v19 = rot_change_B_in_B.k[2];
        v18 = rot_change_B_in_B.k[1];
        v9 = v46;
        ++v14;
      }
      if ( v9->car_solver->constraint_is_disabled[2] == IVP_FALSE )
      {
        IVP_Great_Matrix_Many_Zero::set_value(this: &v9->tmp_matrix, val: *(float *)&v17, col: v13, row: v14);
        v19 = rot_change_B_in_B.k[2];
        v18 = rot_change_B_in_B.k[1];
        v9 = v46;
        ++v14;
      }
      if ( v9->car_solver->constraint_is_disabled[3] == IVP_FALSE )
      {
        IVP_Great_Matrix_Many_Zero::set_value(this: &v9->tmp_matrix, val: v18, col: v13, row: v14);
        v19 = rot_change_B_in_B.k[2];
        v9 = v46;
        ++v14;
      }
      if ( v9->car_solver->constraint_is_disabled[4] == IVP_FALSE )
      {
        IVP_Great_Matrix_Many_Zero::set_value(this: &v9->tmp_matrix, val: v19, col: v13, row: v14);
        v9 = v46;
        ++v14;
      }
      if ( v9->car_solver->constraint_is_disabled[5] == IVP_FALSE )
      {
        IVP_Great_Matrix_Many_Zero::set_value(
          this: &v9->tmp_matrix,
          val: rot_change_B_in_B.hesse_val,
          col: v13,
          row: v14);
        v9 = v46;
        ++v14;
      }
      v12 = v9->car_solver;
      n_elems = v9->car_solver->wheel_objects.n_elems;
      ++LODWORD(delta_speed_change.hesse_val);
    }
    while ( SLODWORD(delta_speed_change.hesse_val) < n_elems );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10094110
// Name: public: enum IVP_RETURN_TYPE IVP_Constraint_Solver_Car_Builder::calc_constraint_matrix(void)
// Source: json
//------------------------------------------------------------------------------
IVP_RETURN_TYPE __thiscall IVP_Constraint_Solver_Car_Builder::calc_constraint_matrix(
        IVP_Constraint_Solver_Car_Builder *this)
{
  int v2; // ebx
  unsigned int v3; // edi
  int v4; // eax
  int i; // edi
  IVP_RETURN_TYPE v6; // edi
  int size; // [esp+Ch] [ebp-Ch]
  int app_idx; // [esp+10h] [ebp-8h]
  int vec_idx; // [esp+14h] [ebp-4h]
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  v2 = this->n_appends * this->n_constraints;
  v3 = 4 * v2 * v2;
  this->tmp_matrix.columns = v2;
  this->tmp_matrix.MATRIX_EPS = 1.0e-10;
  this->tmp_matrix.matrix_values = (float *)p_malloc(size: v3);
  size = 4 * v2;
  this->tmp_matrix.desired_vector = (float *)p_malloc(size: 4 * v2);
  this->tmp_matrix.result_vector = (float *)p_malloc(size: 4 * v2);
  v4 = 0;
  app_idx = 0;
  if ( this->n_appends > 0 )
  {
    do
    {
      vec_idx = 0;
      for ( i = 64; i < 88; i += 4 )
      {
        if ( *(IVP_Constraint_Solver_Car_vtbl **)((char *)&this->car_solver->__vftable + i) != (IVP_Constraint_Solver_Car_vtbl *)1 )
        {
          IVP_Constraint_Solver_Car_Builder::calc_pushing_behavior(
            this,
            a2: (IVP_Core *)&savedregs,
            A_obj_idx: v4,
            push_vec_idx: vec_idx);
          v4 = app_idx;
        }
        ++vec_idx;
      }
      app_idx = ++v4;
    }
    while ( v4 < this->n_appends );
    v3 = 4 * v2 * v2;
  }
  this->car_solver->co_matrix.matrix_values = (float *)p_malloc(size: v3);
  this->car_solver->co_matrix.columns = v2;
  v6 = IVP_Great_Matrix_Many_Zero::invert(this: &this->tmp_matrix, dest: &this->car_solver->co_matrix);
  if ( this->tmp_matrix.matrix_values != nullptr )
  {
    free(data: this->tmp_matrix.matrix_values);
    this->tmp_matrix.matrix_values = nullptr;
  }
  if ( this->tmp_matrix.result_vector != nullptr )
  {
    free(data: this->tmp_matrix.result_vector);
    this->tmp_matrix.result_vector = nullptr;
  }
  if ( this->tmp_matrix.desired_vector != nullptr )
  {
    free(data: this->tmp_matrix.desired_vector);
    this->tmp_matrix.desired_vector = nullptr;
  }
  this->car_solver->co_matrix.desired_vector = (float *)p_malloc(size);
  this->car_solver->co_matrix.result_vector = (float *)p_malloc(size);
  this->car_solver->co_matrix.MATRIX_EPS = 1.0e-10;
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10094250
// Name: public: IVP_Constraint_Solver_Car::IVP_Constraint_Solver_Car(enum IVP_COORDINATE_INDEX,enum IVP_COORDINATE_INDEX,enum IVP_COORDINATE_INDEX,enum IVP_BOOL)
// Source: json
//------------------------------------------------------------------------------
IVP_Constraint_Solver_Car *__thiscall IVP_Constraint_Solver_Car::IVP_Constraint_Solver_Car(
        IVP_Constraint_Solver_Car *this,
        IVP_COORDINATE_INDEX right,
        IVP_COORDINATE_INDEX up,
        IVP_COORDINATE_INDEX forward,
        IVP_BOOL is_left_hand)
{
  float v6; // xmm0_4

  this->__vftable = (IVP_Constraint_Solver_Car_vtbl *)&IVP_Constraint_Solver_Car::`vftable';
  *(_DWORD *)&this->wheel_objects.memsize = 0;
  this->wheel_objects.elems = nullptr;
  IVP_Great_Matrix_Many_Zero::IVP_Great_Matrix_Many_Zero(this: &this->co_matrix);
  *(_DWORD *)&this->cores_of_constraint_system.memsize = 0;
  this->cores_of_constraint_system.elems = nullptr;
  this->x_idx = right;
  this->y_idx = up;
  this->z_idx = forward;
  if ( is_left_hand != IVP_FALSE )
    v6 = -1.0;
  else
    v6 = 1.0;
  this->angle_sign = v6;
  this->max_delta_speed = 240.0;
  this->local_translation_in_use = IVP_FALSE;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100942E0
// Name: protected: virtual float IVP_Constraint_Solver_Car::get_minimum_simulation_frequency(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall IVP_Constraint_Solver_Car::get_minimum_simulation_frequency(IVP_Constraint_Solver_Car *this)
{
  return 30.0;
}

//------------------------------------------------------------------------------
// Address: 0x100942F0
// Name: public: virtual IVP_Constraint_Solver_Car::~IVP_Constraint_Solver_Car(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Constraint_Solver_Car::~IVP_Constraint_Solver_Car(IVP_Constraint_Solver_Car *this)
{
  int v2; // ebx
  IVP_Constraint **c_local_ballsocket; // edi
  IVP_Constraint_Solver_Car *elems; // eax
  IVP_Constraint_Solver_Car *v5; // eax
  IVP_Constraint_Solver_Car *v6; // eax

  this->__vftable = (IVP_Constraint_Solver_Car_vtbl *)&IVP_Constraint_Solver_Car::`vftable';
  IVP_Controller_Manager::remove_controller_from_environment(cntrl: this, silently: IVP_TRUE);
  v2 = 0;
  if ( this->wheel_objects.n_elems != 0 )
  {
    c_local_ballsocket = this->c_local_ballsocket;
    do
    {
      if ( *c_local_ballsocket != nullptr )
        ((void (__thiscall *)(IVP_Constraint *, int))(*c_local_ballsocket)->dtr_IVP_Controller)(
          a1: *c_local_ballsocket,
          a2: 1);
      *c_local_ballsocket = nullptr;
      ++v2;
      ++c_local_ballsocket;
    }
    while ( v2 < this->wheel_objects.n_elems );
  }
  elems = (IVP_Constraint_Solver_Car *)this->wheel_objects.elems;
  if ( elems != (IVP_Constraint_Solver_Car *)&this->co_matrix )
  {
    if ( elems != nullptr )
      free(data: this->wheel_objects.elems);
    this->wheel_objects.elems = nullptr;
    this->wheel_objects.memsize = 0;
  }
  this->wheel_objects.n_elems = 0;
  if ( this->co_matrix.matrix_values != nullptr )
  {
    free(data: this->co_matrix.matrix_values);
    this->co_matrix.matrix_values = nullptr;
  }
  if ( this->co_matrix.result_vector != nullptr )
  {
    free(data: this->co_matrix.result_vector);
    this->co_matrix.result_vector = nullptr;
  }
  if ( this->co_matrix.desired_vector != nullptr )
  {
    free(data: this->co_matrix.desired_vector);
    this->co_matrix.desired_vector = nullptr;
  }
  v5 = (IVP_Constraint_Solver_Car *)this->cores_of_constraint_system.elems;
  if ( v5 != (IVP_Constraint_Solver_Car *)this->constraint_is_disabled )
  {
    if ( v5 != nullptr )
      free(data: this->cores_of_constraint_system.elems);
    this->cores_of_constraint_system.elems = nullptr;
    this->cores_of_constraint_system.memsize = 0;
  }
  this->cores_of_constraint_system.n_elems = 0;
  v6 = (IVP_Constraint_Solver_Car *)this->wheel_objects.elems;
  if ( v6 != (IVP_Constraint_Solver_Car *)&this->co_matrix )
  {
    if ( v6 != nullptr )
      free(data: this->wheel_objects.elems);
    this->wheel_objects.elems = nullptr;
    this->wheel_objects.memsize = 0;
  }
  this->wheel_objects.n_elems = 0;
  this->__vftable = (IVP_Constraint_Solver_Car_vtbl *)&IVP_Controller_Dependent::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10094400
// Name: public: enum IVP_RETURN_TYPE IVP_Constraint_Solver_Car::init_constraint_system(class IVP_Environment __near *,class IVP_Real_Object __near *,class IVP_U_Vector<class IVP_Real_Object> __near &,class IVP_U_Vector<class IVP_U_Float_Point> __near &)
// Source: json
//------------------------------------------------------------------------------
IVP_RETURN_TYPE __thiscall IVP_Constraint_Solver_Car::init_constraint_system(
        IVP_Constraint_Solver_Car *this,
        IVP_Environment *env,
        IVP_Real_Object *body,
        IVP_U_Vector<IVP_Real_Object> *wheels,
        IVP_U_Vector<IVP_U_Float_Point> *p_Bos)
{
  IVP_Constraint_Car_Object *v6; // edi
  IVP_Core *physical_core; // edi
  int v8; // edi
  IVP_Constraint_Car_Object *v9; // eax
  IVP_Constraint_Solver_Car *v10; // edi
  IVP_Constraint_Solver_Car_Builder *v11; // eax
  IVP_Constraint_Solver_Car_Builder *v12; // esi
  IVP_BOOL *v13; // eax
  int x_idx; // eax
  bool v15; // zf
  IVP_BOOL *v16; // eax
  int y_idx; // eax
  IVP_BOOL *v18; // eax
  int z_idx; // edi
  IVP_RETURN_TYPE v20; // edi
  IVP_Constraint_Car_Object *v22; // [esp+Ch] [ebp-8h]
  void *v23; // [esp+Ch] [ebp-8h]
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  this->environment = env;
  v6 = (IVP_Constraint_Car_Object *)p_malloc(size: 0x80u);
  if ( v6 != nullptr )
  {
    v6->real_object = body;
    v6->solver_car = this;
    v6->fix_wheel_constraint = nullptr;
    body->physical_core->car_wheel = v6;
    v6->last_skid_value = 0.0;
    v6->last_contact_position_ws.k[2] = 0.0;
    v6->last_contact_position_ws.k[1] = 0.0;
    v6->last_contact_position_ws.k[0] = 0.0;
    LODWORD(v6->last_skid_time.seconds) = 0;
    HIDWORD(v6->last_skid_time.seconds) = 0;
    IVP_U_Matrix::init(this: &v6->target_position_bs);
  }
  else
  {
    v6 = nullptr;
  }
  this->body_object = v6;
  physical_core = body->physical_core;
  if ( this->cores_of_constraint_system.n_elems >= this->cores_of_constraint_system.memsize )
    IVP_U_Vector_Base::increment_mem(this: &this->cores_of_constraint_system);
  this->cores_of_constraint_system.elems[this->cores_of_constraint_system.n_elems++] = physical_core;
  v8 = 0;
  if ( wheels->n_elems != 0 )
  {
    do
    {
      v9 = (IVP_Constraint_Car_Object *)p_malloc(size: 0x80u);
      if ( v9 != nullptr )
        v22 = IVP_Constraint_Car_Object::IVP_Constraint_Car_Object(
                this: v9,
                a2: (int)&savedregs,
                solver_car_: this,
                i_real_obj_app: (IVP_Real_Object *)wheels->elems[v8],
                i_real_obj_body: body,
                target_Bos_override: (IVP_U_Float_Point *)p_Bos->elems[v8]);
      else
        v22 = nullptr;
      if ( this->wheel_objects.n_elems >= this->wheel_objects.memsize )
        IVP_U_Vector_Base::increment_mem(this: &this->wheel_objects);
      this->wheel_objects.elems[this->wheel_objects.n_elems++] = v22;
      v23 = *((void **)wheels->elems[v8] + 37);
      if ( this->cores_of_constraint_system.n_elems >= this->cores_of_constraint_system.memsize )
        IVP_U_Vector_Base::increment_mem(this: &this->cores_of_constraint_system);
      this->cores_of_constraint_system.elems[this->cores_of_constraint_system.n_elems++] = v23;
      this->c_local_ballsocket[v8++] = nullptr;
    }
    while ( v8 < wheels->n_elems );
  }
  v10 = this;
  IVP_Controller_Manager::announce_controller_to_environment(this: env->controller_manager, cntrl: this);
  v11 = (IVP_Constraint_Solver_Car_Builder *)p_malloc(size: 0x24u);
  v12 = v11;
  if ( v11 != nullptr )
  {
    IVP_Great_Matrix_Many_Zero::IVP_Great_Matrix_Many_Zero(this: &v11->tmp_matrix);
    *(_QWORD *)&v12->car_solver = 0;
    *(_QWORD *)&v12->n_constraints = 0;
    *(_QWORD *)&v12->tmp_matrix.columns = 0;
    *(_QWORD *)&v12->tmp_matrix.matrix_values = 0;
    v12->tmp_matrix.result_vector = nullptr;
    v12->car_solver = v10;
    v12->n_appends = v10->wheel_objects.n_elems;
    v12->n_constraints = 6;
    v10->constraint_is_disabled[0] = IVP_FALSE;
    v12->car_solver->constraint_is_disabled[1] = IVP_FALSE;
    v12->car_solver->constraint_is_disabled[2] = IVP_FALSE;
    v12->car_solver->constraint_is_disabled[3] = IVP_FALSE;
    v12->car_solver->constraint_is_disabled[4] = IVP_FALSE;
    v12->car_solver->constraint_is_disabled[5] = IVP_FALSE;
  }
  else
  {
    v12 = nullptr;
  }
  v13 = &v12->car_solver->constraint_is_disabled[v10->y_idx];
  if ( *v13 == IVP_FALSE )
  {
    *v13 = IVP_TRUE;
    --v12->n_constraints;
  }
  x_idx = v10->x_idx;
  v15 = v12->car_solver->constraint_is_disabled[x_idx + 3] == IVP_FALSE;
  v16 = &v12->car_solver->constraint_is_disabled[x_idx + 3];
  if ( v15 )
  {
    *v16 = IVP_TRUE;
    --v12->n_constraints;
  }
  y_idx = v10->y_idx;
  v15 = v12->car_solver->constraint_is_disabled[y_idx + 3] == IVP_FALSE;
  v18 = &v12->car_solver->constraint_is_disabled[y_idx + 3];
  if ( v15 )
  {
    *v18 = IVP_TRUE;
    --v12->n_constraints;
  }
  z_idx = v10->z_idx;
  if ( v12->car_solver->constraint_is_disabled[z_idx + 3] == IVP_FALSE )
  {
    v12->car_solver->constraint_is_disabled[z_idx + 3] = IVP_TRUE;
    --v12->n_constraints;
  }
  v20 = IVP_Constraint_Solver_Car_Builder::calc_constraint_matrix(this: v12);
  free(data: v12);
  return v20;
}

//------------------------------------------------------------------------------
// Address: 0x10094660
// Name: protected: void IVP_Constraint_Solver_Car::do_simulation_controller_rotation(class IVP_Event_Sim __near *,class IVP_Core __near *,class IVP_U_Matrix const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Constraint_Solver_Car::do_simulation_controller_rotation(
        IVP_Constraint_Solver_Car *this@<ecx>,
        int a2@<ebp>,
        double a3@<esi:edi>,
        IVP_Event_Sim *es,
        IVP_Core *core_B,
        const IVP_U_Matrix *m_world_f_B)
{
  float *v7; // eax
  IVP_Core *v8; // esi
  int x_idx; // ecx
  float v10; // xmm0_4
  int z_idx; // eax
  float v12; // xmm1_4
  float v13; // xmm0_4
  int y_idx; // eax
  double v15; // xmm0_8
  int v16; // eax
  int v17; // eax
  float v18; // xmm2_4
  float v19; // xmm5_4
  float i_delta_time; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  int n_elems; // edx
  long double v24; // [esp-1Ch] [ebp-1BCh]
  long double v25; // [esp-1Ch] [ebp-1BCh]
  long double v26; // [esp-14h] [ebp-1B4h]
  long double v27; // [esp-14h] [ebp-1B4h]
  _BYTE v28[12]; // [esp-Ch] [ebp-1ACh] BYREF
  IVP_Solver_Core_Reaction tcb; // [esp+0h] [ebp-1A0h] BYREF
  IVP_U_Point tv_ws; // [esp+120h] [ebp-80h] BYREF
  IVP_U_Float_Point rot_impulse_ds; // [esp+130h] [ebp-70h] BYREF
  IVP_U_Point target_vec_as; // [esp+140h] [ebp-60h] BYREF
  IVP_U_Float_Point z_rot_axis_world2; // [esp+150h] [ebp-50h] BYREF
  IVP_U_Float_Point y_rot_axis_world2; // [esp+160h] [ebp-40h] BYREF
  IVP_U_Point tv_bs; // [esp+170h] [ebp-30h]
  float v36; // [esp+180h] [ebp-20h]
  IVP_Core *v37; // [esp+184h] [ebp-1Ch]
  float cur_angles_B[2]; // [esp+188h] [ebp-18h]
  IVP_Core *core_A; // [esp+190h] [ebp-10h]
  int v40; // [esp+194h] [ebp-Ch]
  void *v41; // [esp+198h] [ebp-8h]
  void *retaddr; // [esp+1A0h] [ebp+0h]

  v40 = a2;
  v41 = retaddr;
  v24 = a3;
  core_A = nullptr;
  if ( this->wheel_objects.n_elems != 0 )
  {
    while ( 1 )
    {
      v7 = (float *)this->wheel_objects.elems[(_DWORD)core_A];
      v8 = *(IVP_Core **)(*(_DWORD *)v7 + 148);
      x_idx = this->x_idx;
      y_rot_axis_world2.k[1] = v7[x_idx + 4];
      y_rot_axis_world2.k[2] = v7[x_idx + 8];
      v10 = v7[x_idx + 12];
      v37 = v8;
      y_rot_axis_world2.hesse_val = v10;
      IVP_U_Matrix3::vmult3(
        this: &m_world_f_B->IVP_U_Matrix3,
        p_in: (IVP_U_Float_Point *)&y_rot_axis_world2.k[1],
        p_out: (IVP_U_Float_Point *)&tcb.delta_velocity_ds.k[1]);
      IVP_U_Matrix3::vimult3(
        this: &v8->m_world_f_core_last_psi,
        p_in: (const IVP_U_Float_Point *)&tcb.delta_velocity_ds.k[1],
        p_out: (IVP_U_Float_Point *)&rot_impulse_ds.k[1]);
      z_idx = this->z_idx;
      v12 = rot_impulse_ds.k[this->x_idx + 1];
      cur_angles_B[1] = this->angle_sign;
      v13 = rot_impulse_ds.k[z_idx + 1];
      cur_angles_B[0] = v12;
      __libm_sse2_atan2(y: v24, x: v26);
      y_idx = this->y_idx;
      LODWORD(tv_bs.hesse_val) = COERCE_UNSIGNED_INT(v13 * cur_angles_B[1]) ^ _mask__NegFloat_;
      v15 = rot_impulse_ds.k[y_idx + 1];
      __libm_sse2_atan2(y: v25, x: v27);
      v16 = this->y_idx;
      *(float *)&v15 = v15;
      v36 = *(float *)&v15 * cur_angles_B[1];
      z_rot_axis_world2.k[1] = v8->m_world_f_core_last_psi.rows[0].k[v16];
      z_rot_axis_world2.k[2] = v8->m_world_f_core_last_psi.rows[1].k[v16];
      *(float *)&v15 = v8->m_world_f_core_last_psi.rows[2].k[v16];
      v17 = this->z_idx;
      z_rot_axis_world2.hesse_val = *(float *)&v15;
      target_vec_as.k[1] = v8->m_world_f_core_last_psi.rows[0].k[v17];
      target_vec_as.k[2] = v8->m_world_f_core_last_psi.rows[1].k[v17];
      target_vec_as.hesse_val = v8->m_world_f_core_last_psi.rows[2].k[v17];
      IVP_Solver_Core_Reaction::init_reaction_solver_rotation_ws(
        this: (IVP_Solver_Core_Reaction *)v28,
        core_0: core_B,
        core_1: v8,
        direction_0_ws: (IVP_U_Float_Point *)&z_rot_axis_world2.k[1],
        direction_1_ws: (IVP_U_Point *)&target_vec_as.k[1],
        direction_2_ws: nullptr);
      v18 = (float)(tcb.m_velocity_ds_f_impulse_ds.rows[0].k[2] * tcb.cr_mult_inv1[2].k[1])
          - (float)(tcb.cr_mult_inv1[2].k[2] * tcb.cr_mult_inv1[2].k[2]);
      if ( (float)(v18 * v18) < 1.0e-20 )
        break;
      v19 = -(float)(tcb.cr_mult_inv1[2].k[2] * (float)(1.0 / v18));
      i_delta_time = es->i_delta_time;
      v21 = (float)-(float)(i_delta_time * v36) - tcb.m_velocity_ds_f_impulse_ds.rows[2].k[2];
      v22 = (float)-(float)(i_delta_time * tv_bs.hesse_val) - tcb.m_velocity_ds_f_impulse_ds.rows[2].k[1];
      tv_ws.k[1] = (float)(v21 * v19)
                 + (float)(v22 * (float)(tcb.m_velocity_ds_f_impulse_ds.rows[0].k[2] * (float)(1.0 / v18)));
      tv_ws.k[2] = (float)(v21 * (float)(tcb.cr_mult_inv1[2].k[1] * (float)(1.0 / v18))) + (float)(v22 * v19);
      IVP_Solver_Core_Reaction::exert_angular_impulse_dim2(
        this: (IVP_Solver_Core_Reaction *)v28,
        core_0: core_B,
        core_1: v8,
        impulse_ds: (IVP_U_Point *)&tv_ws.k[1]);
      n_elems = this->wheel_objects.n_elems;
      core_A = (IVP_Core *)((char *)core_A + 1);
      if ( (int)core_A >= n_elems )
        return;
    }
    ivp_message(templat: "do_constraint_system: Couldn't invert rot matrix!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x100948D0
// Name: public: virtual void IVP_Constraint_Solver_Car::do_simulation_controller(class IVP_Event_Sim __near *,class IVP_U_Vector<class IVP_Core> __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Constraint_Solver_Car::do_simulation_controller(
        IVP_Constraint_Solver_Car *this@<ecx>,
        float *a2@<ebp>,
        IVP_Event_Sim *es,
        IVP_U_Vector<IVP_Core> *__formal)
{
  IVP_Core *physical_core; // eax
  double v5; // rdi
  float v6; // ecx
  float hesse_val; // xmm1_4
  float v8; // xmm0_4
  float v9; // eax
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  _DWORD *v13; // eax
  float v14; // eax
  int v15; // ecx
  float v17; // eax
  float v18; // ecx
  int v19; // edx
  float v20; // eax
  double v21; // st7
  int v22; // edx
  float v23; // ecx
  int v24; // edx
  double v25; // st7
  int v26; // ecx
  int v27; // [esp-Ch] [ebp-DCh] BYREF
  IVP_U_Point wheelTargetWS; // [esp+0h] [ebp-D0h] BYREF
  IVP_U_Float_Point surspeed_B_in_world; // [esp+10h] [ebp-C0h] BYREF
  float v30[3]; // [esp+24h] [ebp-ACh] BYREF
  IVP_U_Float_Point surspeed_A_in_B; // [esp+30h] [ebp-A0h] BYREF
  IVP_U_Point target_position_ws; // [esp+40h] [ebp-90h] BYREF
  IVP_U_Float_Point cur_pos_A_in_B; // [esp+50h] [ebp-80h] BYREF
  IVP_U_Float_Point cur_pos_B_in_B; // [esp+60h] [ebp-70h] BYREF
  IVP_U_Float_Point t_impulse_bs; // [esp+70h] [ebp-60h] BYREF
  float i_delta_time; // [esp+90h] [ebp-40h]
  float v37; // [esp+94h] [ebp-3Ch]
  float v38; // [esp+98h] [ebp-38h]
  IVP_Core *inv_dtime; // [esp+9Ch] [ebp-34h]
  IVP_Real_Object **max_quad_speed; // [esp+A0h] [ebp-30h]
  float delta_time; // [esp+A4h] [ebp-2Ch] BYREF
  IVP_Core *core_B; // [esp+A8h] [ebp-28h]
  IVP_Constraint_Car_Object *app; // [esp+ACh] [ebp-24h]
  IVP_U_Float_Point t_impulse_ws; // [esp+B0h] [ebp-20h]
  int v45; // [esp+C0h] [ebp-10h]
  float *res_vec_ptr; // [esp+C4h] [ebp-Ch] BYREF
  IVP_Core *core_A; // [esp+C8h] [ebp-8h]
  IVP_Core *retaddr; // [esp+D0h] [ebp+0h]

  res_vec_ptr = a2;
  core_A = retaddr;
  HIDWORD(v5) = this;
  physical_core = this->body_object->real_object->physical_core;
  LODWORD(v5) = &physical_core->m_world_f_core_last_psi;
  i_delta_time = es->i_delta_time;
  inv_dtime = physical_core;
  IVP_Constraint_Solver_Car::do_simulation_controller_rotation(
    this,
    a2: (int)&res_vec_ptr,
    a3: v5,
    es,
    core_B: physical_core,
    m_world_f_B: &physical_core->m_world_f_core_last_psi);
  v6 = *(float *)(HIDWORD(v5) + 32);
  hesse_val = inv_dtime->rot_inertia.hesse_val;
  v38 = es->delta_time;
  v8 = *(float *)(HIDWORD(v5) + 148) * *(float *)(HIDWORD(v5) + 148);
  t_impulse_ws.hesse_val = v6;
  v37 = v8;
  if ( hesse_val >= 10000.0 )
    v37 = v8 * 2.75;
  t_impulse_ws.k[2] = 0.0;
  if ( *(_WORD *)(HIDWORD(v5) + 10) != 0 )
  {
    do
    {
      v9 = *(float *)(*(_DWORD *)(HIDWORD(v5) + 12) + 4 * LODWORD(t_impulse_ws.k[2]));
      v10 = *(float *)(LODWORD(v9) + 64);
      v45 = *(_DWORD *)(*(_DWORD *)LODWORD(v9) + 148);
      cur_pos_A_in_B.k[1] = v10;
      cur_pos_A_in_B.k[2] = *(float *)(LODWORD(v9) + 68);
      v11 = *(float *)(LODWORD(v9) + 72);
      *(float *)&max_quad_speed = v9;
      cur_pos_A_in_B.hesse_val = v11;
      IVP_U_Matrix::vimult4(
        this: (IVP_U_Matrix *)LODWORD(v5),
        p_in: (const IVP_U_Float_Point *)(v45 + 144),
        p_out: (IVP_U_Point *)&target_position_ws.k[1]);
      IVP_U_Matrix3::vimult3(
        this: (IVP_U_Matrix3 *)LODWORD(v5),
        p_in: (const IVP_U_Float_Point *)(v45 + 208),
        p_out: (IVP_U_Float_Point *)v30);
      IVP_Core::get_surface_speed(
        this: inv_dtime,
        point_core: (IVP_U_Float_Point *)&cur_pos_A_in_B.k[1],
        speed_world_out: (IVP_U_Point *)&wheelTargetWS.k[1]);
      IVP_U_Matrix3::vimult3(
        this: (IVP_U_Matrix3 *)LODWORD(v5),
        p_in: (IVP_U_Point *)&wheelTargetWS.k[1],
        p_out: (IVP_U_Float_Point *)&cur_pos_B_in_B.k[1]);
      delta_time = (float)((float)((float)(v30[0] * v38) + target_position_ws.k[1])
                         - (float)((float)(cur_pos_B_in_B.k[1] * v38) + cur_pos_A_in_B.k[1]))
                 * i_delta_time;
      *(float *)&core_B = (float)((float)((float)(v30[1] * v38) + target_position_ws.k[2])
                                - (float)((float)(cur_pos_B_in_B.k[2] * v38) + cur_pos_A_in_B.k[2]))
                        * i_delta_time;
      *(float *)&app = (float)((float)((float)(v30[2] * v38) + target_position_ws.hesse_val)
                             - (float)((float)(cur_pos_B_in_B.hesse_val * v38) + cur_pos_A_in_B.hesse_val))
                     * i_delta_time;
      t_impulse_bs.k[1] = (float)(cur_pos_B_in_B.k[1] * v38) + cur_pos_A_in_B.k[1];
      t_impulse_bs.k[2] = (float)(cur_pos_B_in_B.k[2] * v38) + cur_pos_A_in_B.k[2];
      t_impulse_bs.hesse_val = (float)(cur_pos_B_in_B.hesse_val * v38) + cur_pos_A_in_B.hesse_val;
      if ( (float)((float)((float)(delta_time * delta_time) + (float)(*(float *)&core_B * *(float *)&core_B))
                 + (float)(*(float *)&app * *(float *)&app)) > v37 )
      {
        IVP_U_Matrix::vmult4(
          this: (IVP_U_Matrix *)LODWORD(v5),
          p_in: (IVP_U_Float_Point *)&t_impulse_bs.k[1],
          p_out: (IVP_U_Float_Point *)&v27);
        delta_time = (float)(target_position_ws.k[1] - t_impulse_bs.k[1]) * i_delta_time;
        *(float *)&core_B = (float)(target_position_ws.k[2] - t_impulse_bs.k[2]) * i_delta_time;
        *(float *)&app = (float)(target_position_ws.hesse_val - t_impulse_bs.hesse_val) * i_delta_time;
        IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)&delta_time);
        v12 = *(float *)(HIDWORD(v5) + 148) * 0.25;
        v13 = (_DWORD *)v45;
        delta_time = v12 * delta_time;
        *(float *)&core_B = *(float *)&core_B * v12;
        *(float *)&app = *(float *)&app * v12;
        *(_DWORD *)(v45 + 216) = 0;
        v13[53] = 0;
        v13[52] = 0;
        v13[46] = 0;
        v13[45] = 0;
        v13[44] = 0;
        if ( (float)(inv_dtime->max_surface_rot_speed + inv_dtime->current_speed) < 0.000099999997 )
        {
          IVP_Real_Object::get_quat_world_f_object_AT(
            this: *max_quad_speed,
            quat_world_f_object: (IVP_U_Quat *)&surspeed_A_in_B.k[1],
            position: (IVP_U_Point *)&surspeed_B_in_world.k[1]);
          IVP_U_Matrix::vmult4(
            this: (IVP_U_Matrix *)LODWORD(v5),
            p_in: (IVP_U_Float_Point *)&t_impulse_bs.k[1],
            p_out: (IVP_U_Float_Point *)&surspeed_B_in_world.k[1]);
          IVP_Real_Object::beam_object_to_new_position(
            this: *max_quad_speed,
            rotation_world_f_object: (const IVP_U_Quat *)&surspeed_A_in_B.k[1],
            position_w_f_o: (const IVP_U_Point *)&surspeed_B_in_world.k[1],
            optimize_for_repeated_calls: IVP_TRUE);
        }
      }
      v14 = t_impulse_ws.hesse_val;
      *(float *)LODWORD(t_impulse_ws.hesse_val) = *(&delta_time + *(_DWORD *)(HIDWORD(v5) + 40));
      LODWORD(v14) += 8;
      *(float *)(LODWORD(v14) - 4) = *(&delta_time + *(_DWORD *)(HIDWORD(v5) + 48));
      v15 = *(unsigned __int16 *)(HIDWORD(v5) + 10);
      t_impulse_ws.hesse_val = v14;
      ++LODWORD(t_impulse_ws.k[2]);
    }
    while ( SLODWORD(t_impulse_ws.k[2]) < v15 );
  }
  if ( *(_DWORD *)(HIDWORD(v5) + 88) == 1 && --*(_DWORD *)(HIDWORD(v5) + 144) < 0 )
  {
    t_impulse_ws.hesse_val = 0.0;
    if ( *(_WORD *)(HIDWORD(v5) + 10) != 0 )
    {
      LODWORD(v17) = HIDWORD(v5) + 92;
      max_quad_speed = (IVP_Real_Object **)(HIDWORD(v5) + 92);
      do
      {
        if ( *(_DWORD *)LODWORD(v17) != 0 )
        {
          (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)LODWORD(v17) + 28))(a1: *(_DWORD *)LODWORD(v17), a2: 1);
          v17 = *(float *)&max_quad_speed;
        }
        v18 = t_impulse_ws.hesse_val;
        *(_DWORD *)LODWORD(v17) = 0;
        v19 = *(unsigned __int16 *)(HIDWORD(v5) + 10);
        LODWORD(v17) += 4;
        LODWORD(t_impulse_ws.hesse_val) = LODWORD(v18) + 1;
        *(float *)&max_quad_speed = v17;
      }
      while ( LODWORD(v18) + 1 < v19 );
    }
    *(_DWORD *)(HIDWORD(v5) + 88) = 0;
  }
  IVP_Great_Matrix_Many_Zero::mult(this: (IVP_Great_Matrix_Many_Zero *)(HIDWORD(v5) + 16));
  if ( *(_DWORD *)(HIDWORD(v5) + 88) == 0 )
  {
    v20 = *(float *)(HIDWORD(v5) + 36);
    t_impulse_ws.k[2] = v20;
    v45 = 0;
    if ( *(_WORD *)(HIDWORD(v5) + 10) != 0 )
    {
      while ( 1 )
      {
        v21 = *(float *)LODWORD(v20);
        v22 = **(_DWORD **)(*(_DWORD *)(HIDWORD(v5) + 12) + 4 * v45);
        v38 = *(float *)(*(_DWORD *)(HIDWORD(v5) + 12) + 4 * v45);
        v23 = *(float *)(v22 + 148);
        cur_pos_B_in_B.k[*(_DWORD *)(HIDWORD(v5) + 40) + 1] = v21;
        v24 = *(_DWORD *)(HIDWORD(v5) + 48);
        v25 = *(float *)(LODWORD(v20) + 4);
        t_impulse_ws.hesse_val = v23;
        cur_pos_B_in_B.k[*(_DWORD *)(HIDWORD(v5) + 44) + 1] = 0.0;
        cur_pos_B_in_B.k[v24 + 1] = v25;
        IVP_U_Matrix3::vmult3(
          this: (IVP_U_Matrix3 *)LODWORD(v5),
          p_in: (IVP_U_Float_Point *)&cur_pos_B_in_B.k[1],
          p_out: (IVP_U_Float_Point *)&delta_time);
        LODWORD(t_impulse_ws.k[2]) += 8;
        IVP_U_Matrix::vmult4(
          this: (IVP_U_Matrix *)LODWORD(v5),
          p_in: (const IVP_U_Float_Point *)(LODWORD(v38) + 64),
          p_out: (IVP_U_Float_Point *)&surspeed_A_in_B.k[1]);
        IVP_Core::push_core_ws(
          this: inv_dtime,
          world_point: (const IVP_U_Point *)&surspeed_A_in_B.k[1],
          impulse_in_world: (const IVP_U_Float_Point *)&delta_time);
        delta_time = delta_time * -1.0;
        *(float *)&core_B = *(float *)&core_B * -1.0;
        *(float *)&app = *(float *)&app * -1.0;
        IVP_Core::push_core_ws(
          this: (IVP_Core *)LODWORD(t_impulse_ws.hesse_val),
          world_point: (const IVP_U_Point *)(LODWORD(t_impulse_ws.hesse_val) + 144),
          impulse_in_world: (const IVP_U_Float_Point *)&delta_time);
        v26 = *(unsigned __int16 *)(HIDWORD(v5) + 10);
        if ( ++v45 >= v26 )
          break;
        v20 = t_impulse_ws.k[2];
      }
    }
  }
}
