// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/havana/havok/hk_physics/constraint/hinge/hinge_bp_builder.cpp
// Functions: 6
// ============================================================

#include "ivp\havana\havok\hk_physics\constraint\hinge\hinge_bp_builder.h"

//------------------------------------------------------------------------------
// Address: 0x10040B30
// Name: public: void hk_Hinge_BP_Builder::set_position_os(int,class hk_Vector3 const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Hinge_BP_Builder::set_position_os(
        hk_Hinge_BP_Builder *this,
        int body_index,
        const hk_Vector3 *position)
{
  hk_Ray *v3; // eax

  v3 = &this->m_hinge_bp.m_axis_os[body_index];
  v3->m_origin.x = position->x;
  v3->m_origin.y = position->y;
  v3->m_origin.z = position->z;
}

//------------------------------------------------------------------------------
// Address: 0x10040B60
// Name: public: void hk_Hinge_BP_Builder::set_angular_motor(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Hinge_BP_Builder::set_angular_motor(
        hk_Hinge_BP_Builder *this,
        float angular_velocity,
        float max_torque)
{
  this->m_hinge_bp.m_limit.m_friction_is_enabled = max_torque != 0.0;
  LODWORD(this->m_hinge_bp.m_limit.m_joint_friction) = LODWORD(max_torque) & _mask__AbsFloat_;
  this->m_hinge_bp.m_limit.m_desired_velocity = angular_velocity;
}

//------------------------------------------------------------------------------
// Address: 0x10040BA0
// Name: public: void hk_Hinge_BP_Builder::set_angular_limits(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Hinge_BP_Builder::set_angular_limits(hk_Hinge_BP_Builder *this, float lower, float upper)
{
  if ( fabs(lower + 3.1415927) > 0.000099999997 || fabs(upper - 3.1415927) > 0.000099999997 )
  {
    this->m_hinge_bp.m_limit.m_limit_is_enabled = true;
    this->m_hinge_bp.m_limit.m_limit_min = lower;
    this->m_hinge_bp.m_limit.m_limit_max = upper;
  }
  else
  {
    this->m_hinge_bp.m_limit.m_limit_is_enabled = false;
    this->m_hinge_bp.m_limit.m_limit_min = lower;
    this->m_hinge_bp.m_limit.m_limit_max = upper;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10040C10
// Name: public: void hk_Hinge_BP_Builder::set_tau(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Hinge_BP_Builder::set_tau(hk_Hinge_BP_Builder *this, float tau)
{
  this->m_hinge_bp.m_tau = tau;
}

//------------------------------------------------------------------------------
// Address: 0x10040C20
// Name: public: void hk_Hinge_BP_Builder::set_axis_perp_os(int,class hk_Vector3 const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Hinge_BP_Builder::set_axis_perp_os(hk_Hinge_BP_Builder *this, int body, const hk_Vector3 *axis_os)
{
  float x; // xmm2_4
  float y; // xmm3_4
  float z; // xmm4_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  int v8; // eax

  x = axis_os->x;
  y = axis_os->y;
  z = axis_os->z;
  v6 = (float)((float)(x * x) + (float)(y * y)) + (float)(z * z);
  v7 = 0.0;
  if ( v6 != 0.0 )
    v7 = 1.0 / fsqrt(v6);
  v8 = 2 * (body + 6);
  *(&this->m_hinge_bp.m_tau + 2 * v8) = v7 * x;
  *(&this->m_hinge_bp.m_strength + 2 * v8) = v7 * y;
  *((float *)&this->m_hinge_bp.m_limit.m_limit_is_enabled + 2 * v8) = v7 * z;
}

//------------------------------------------------------------------------------
// Address: 0x10040CA0
// Name: public: void hk_Hinge_BP_Builder::set_axis_ws(class hk_Rigid_Body __near *,class hk_Rigid_Body __near *,class hk_Vector3 const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge hk_Hinge_BP_Builder::set_axis_ws(
        hk_Hinge_BP_Builder *this@<ecx>,
        int a2@<ebp>,
        hk_Rigid_Body *a,
        hk_Rigid_Body *b,
        const hk_Vector3 *axis_ws)
{
  float x; // xmm2_4
  float y; // xmm3_4
  float z; // xmm4_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  bool v10; // zf
  IVP_Core *physical_core; // eax
  IVP_Core *v12; // eax
  float v13; // xmm0_4
  float v14[3]; // [esp-Ch] [ebp-ACh] BYREF
  _BYTE n_axis_4[64]; // [esp+4h] [ebp-9Ch] OVERLAPPED BYREF
  hk_Vector3 *v16; // [esp+50h] [ebp-50h]
  hk_Rotation v17; // [esp+54h] [ebp-4Ch] BYREF
  float v18; // [esp+84h] [ebp-1Ch]
  float v19; // [esp+88h] [ebp-18h]
  float v20; // [esp+8Ch] [ebp-14h]
  int v21; // [esp+90h] [ebp-10h]
  int v22; // [esp+94h] [ebp-Ch]
  void *v23; // [esp+98h] [ebp-8h]
  void *retaddr; // [esp+A0h] [ebp+0h]

  v22 = a2;
  v23 = retaddr;
  v16 = (hk_Vector3 *)this;
  x = axis_ws->x;
  y = axis_ws->y;
  z = axis_ws->z;
  v8 = (float)((float)(x * x) + (float)(y * y)) + (float)(z * z);
  if ( v8 == 0.0 )
    v9 = 0.0;
  else
    v9 = 1.0 / fsqrt(v8);
  v10 = (*(_DWORD *)&a->flags & 0x800) == 0;
  v14[0] = v9 * x;
  v14[1] = v9 * y;
  v14[2] = v9 * z;
  if ( v10 )
  {
    qmemcpy(n_axis_4, &a->physical_core->m_world_f_core_last_psi, sizeof(n_axis_4));
    IVP_U_Matrix::vmult4(
      this: (IVP_U_Matrix *)n_axis_4,
      p_in: &a->shift_core_f_object,
      p_out: (IVP_U_Float_Point *)&n_axis_4[48]);
    v17.m_elems[0] = *(float *)n_axis_4;
    v17.m_elems[1] = *(float *)&n_axis_4[16];
    v17.m_elems[2] = *(float *)&n_axis_4[32];
    v17.m_elems[4] = *(float *)&n_axis_4[4];
    v17.m_elems[3] = 0.0;
    v17.m_elems[5] = *(float *)&n_axis_4[20];
    v17.m_elems[7] = 0.0;
    v17.m_elems[11] = 0.0;
    v17.m_elems[6] = *(float *)&n_axis_4[36];
    v18 = *(float *)&n_axis_4[48];
    v17.m_elems[8] = *(float *)&n_axis_4[8];
    v19 = *(float *)&n_axis_4[52];
    v17.m_elems[9] = *(float *)&n_axis_4[24];
    v20 = *(float *)&n_axis_4[56];
    v17.m_elems[10] = *(float *)&n_axis_4[40];
  }
  else
  {
    physical_core = a->physical_core;
    v17.m_elems[0] = physical_core->m_world_f_core_last_psi.rows[0].k[0];
    v17.m_elems[1] = physical_core->m_world_f_core_last_psi.rows[1].k[0];
    v17.m_elems[2] = physical_core->m_world_f_core_last_psi.rows[2].k[0];
    v17.m_elems[3] = 0.0;
    v17.m_elems[4] = physical_core->m_world_f_core_last_psi.rows[0].k[1];
    v17.m_elems[5] = physical_core->m_world_f_core_last_psi.rows[1].k[1];
    v17.m_elems[6] = physical_core->m_world_f_core_last_psi.rows[2].k[1];
    v17.m_elems[7] = 0.0;
    v17.m_elems[8] = physical_core->m_world_f_core_last_psi.rows[0].k[2];
    v17.m_elems[9] = physical_core->m_world_f_core_last_psi.rows[1].k[2];
    v17.m_elems[10] = physical_core->m_world_f_core_last_psi.rows[2].k[2];
    v17.m_elems[11] = 0.0;
    v18 = physical_core->m_world_f_core_last_psi.vv.k[0];
    v19 = physical_core->m_world_f_core_last_psi.vv.k[1];
    v20 = physical_core->m_world_f_core_last_psi.vv.k[2];
  }
  v21 = 1065353216;
  hk_Vector3::set_rotated_inv_dir(this: v16 + 3, t: &v17, v: (const hk_Vector3 *)v14);
  if ( (*(_DWORD *)&b->flags & 0x800) != 0 )
  {
    v12 = b->physical_core;
    v17.m_elems[0] = v12->m_world_f_core_last_psi.rows[0].k[0];
    v17.m_elems[1] = v12->m_world_f_core_last_psi.rows[1].k[0];
    v17.m_elems[2] = v12->m_world_f_core_last_psi.rows[2].k[0];
    v17.m_elems[3] = 0.0;
    v17.m_elems[4] = v12->m_world_f_core_last_psi.rows[0].k[1];
    v17.m_elems[5] = v12->m_world_f_core_last_psi.rows[1].k[1];
    v17.m_elems[6] = v12->m_world_f_core_last_psi.rows[2].k[1];
    v17.m_elems[7] = 0.0;
    v17.m_elems[8] = v12->m_world_f_core_last_psi.rows[0].k[2];
    v17.m_elems[9] = v12->m_world_f_core_last_psi.rows[1].k[2];
    *(_QWORD *)&v17.m_elems[10] = LODWORD(v12->m_world_f_core_last_psi.rows[2].k[2]);
    v18 = v12->m_world_f_core_last_psi.vv.k[0];
    v19 = v12->m_world_f_core_last_psi.vv.k[1];
    v13 = v12->m_world_f_core_last_psi.vv.k[2];
  }
  else
  {
    qmemcpy(n_axis_4, &b->physical_core->m_world_f_core_last_psi, sizeof(n_axis_4));
    IVP_U_Matrix::vmult4(
      this: (IVP_U_Matrix *)n_axis_4,
      p_in: &b->shift_core_f_object,
      p_out: (IVP_U_Float_Point *)&n_axis_4[48]);
    v17.m_elems[0] = *(float *)n_axis_4;
    v17.m_elems[4] = *(float *)&n_axis_4[4];
    v17.m_elems[1] = *(float *)&n_axis_4[16];
    v17.m_elems[5] = *(float *)&n_axis_4[20];
    v17.m_elems[2] = *(float *)&n_axis_4[32];
    v17.m_elems[6] = *(float *)&n_axis_4[36];
    v17.m_elems[3] = 0.0;
    v17.m_elems[7] = 0.0;
    v17.m_elems[11] = 0.0;
    v17.m_elems[8] = *(float *)&n_axis_4[8];
    v18 = *(float *)&n_axis_4[48];
    v17.m_elems[9] = *(float *)&n_axis_4[24];
    v19 = *(float *)&n_axis_4[52];
    v13 = *(float *)&n_axis_4[56];
    v17.m_elems[10] = *(float *)&n_axis_4[40];
  }
  v20 = v13;
  v21 = 1065353216;
  hk_Vector3::set_rotated_inv_dir(this: v16 + 5, t: &v17, v: (const hk_Vector3 *)v14);
}
