// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/havana/havok/hk_physics/constraint/prismatic/prismatic_constraint.cpp
// Functions: 11
// ============================================================

#include "ivp\havana\havok\hk_physics\constraint\prismatic\prismatic_constraint.h"

//------------------------------------------------------------------------------
// Address: 0x10039300
// Name: public: virtual int hk_Prismatic_Constraint::get_vmq_storage_size(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall hk_Prismatic_Constraint::get_vmq_storage_size(hk_Prismatic_Constraint *this)
{
  return 928;
}

//------------------------------------------------------------------------------
// Address: 0x10039310
// Name: public: void hk_Prismatic_Constraint::set_motor(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Prismatic_Constraint::set_motor(hk_Prismatic_Constraint *this, float desired_vel, float max_force)
{
  this->m_limits[0].m_friction_is_enabled = max_force != 0.0;
  LODWORD(this->m_limits[0].m_joint_friction) = LODWORD(max_force) & _mask__AbsFloat_;
  this->m_limits[0].m_desired_velocity = desired_vel;
}

//------------------------------------------------------------------------------
// Address: 0x10039350
// Name: public: void hk_Prismatic_Constraint::write_to_blueprint(class hk_Prismatic_BP __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Prismatic_Constraint::write_to_blueprint(hk_Prismatic_Constraint *this, hk_Prismatic_BP *bp)
{
  bp->m_tau = this->m_tau;
  bp->m_strength = this->m_strength;
  bp->m_transform_Ros_Aos.m_rotation = this->m_transform_Ros_Aos.m_rotation;
  bp->m_transform_Ros_Aos.m_translation.x = this->m_transform_Ros_Aos.m_translation.x;
  bp->m_transform_Ros_Aos.m_translation.y = this->m_transform_Ros_Aos.m_translation.y;
  bp->m_transform_Ros_Aos.m_translation.z = this->m_transform_Ros_Aos.m_translation.z;
  bp->m_axis_Ros.x = this->m_axis_Ros.x;
  bp->m_axis_Ros.y = this->m_axis_Ros.y;
  bp->m_axis_Ros.z = this->m_axis_Ros.z;
  bp->m_limit = this->m_limits[0];
}

//------------------------------------------------------------------------------
// Address: 0x100393D0
// Name: protected: void hk_Prismatic_Constraint::reset_linear_limit(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall hk_Prismatic_Constraint::reset_linear_limit(hk_Prismatic_Constraint *this@<ecx>, int a2@<ebp>)
{
  hk_Prismatic_Constraint *v2; // esi
  hk_Rigid_Body *v3; // eax
  bool v4; // zf
  IVP_Core *physical_core; // eax
  float v6; // xmm0_4
  hk_Rigid_Body *v7; // eax
  float *v8; // eax
  float v9; // xmm0_4
  IVP_U_Matrix m_world_f_core_last_psi; // [esp-4Ch] [ebp-ECh] BYREF
  float v11[3]; // [esp-Ch] [ebp-ACh] BYREF
  _BYTE axis_ws_4[64]; // [esp+4h] [ebp-9Ch] OVERLAPPED BYREF
  hk_Rotation v13; // [esp+44h] [ebp-5Ch] BYREF
  float v14; // [esp+74h] [ebp-2Ch]
  float v15; // [esp+78h] [ebp-28h]
  float v16; // [esp+7Ch] [ebp-24h]
  int v17; // [esp+80h] [ebp-20h]
  hk_Prismatic_Constraint *v18; // [esp+90h] [ebp-10h]
  int v19; // [esp+94h] [ebp-Ch]
  void *v20; // [esp+98h] [ebp-8h]
  void *retaddr; // [esp+A0h] [ebp+0h]

  v19 = a2;
  v20 = retaddr;
  v2 = this;
  v3 = this->m_entities[0];
  v4 = (*(_DWORD *)&v3->flags & 0x800) == 0;
  v18 = this;
  if ( v4 )
  {
    qmemcpy(axis_ws_4, &v3->physical_core->m_world_f_core_last_psi, sizeof(axis_ws_4));
    IVP_U_Matrix::vmult4(
      this: (IVP_U_Matrix *)axis_ws_4,
      p_in: &v3->shift_core_f_object,
      p_out: (IVP_U_Float_Point *)&axis_ws_4[48]);
    v2 = v18;
    v13.m_elems[0] = *(float *)axis_ws_4;
    v13.m_elems[4] = *(float *)&axis_ws_4[4];
    v13.m_elems[1] = *(float *)&axis_ws_4[16];
    v13.m_elems[5] = *(float *)&axis_ws_4[20];
    v13.m_elems[2] = *(float *)&axis_ws_4[32];
    v13.m_elems[6] = *(float *)&axis_ws_4[36];
    v13.m_elems[3] = 0.0;
    v13.m_elems[7] = 0.0;
    v13.m_elems[11] = 0.0;
    v13.m_elems[8] = *(float *)&axis_ws_4[8];
    v14 = *(float *)&axis_ws_4[48];
    v13.m_elems[9] = *(float *)&axis_ws_4[24];
    v15 = *(float *)&axis_ws_4[52];
    v6 = *(float *)&axis_ws_4[56];
    v13.m_elems[10] = *(float *)&axis_ws_4[40];
  }
  else
  {
    physical_core = v3->physical_core;
    v13.m_elems[0] = physical_core->m_world_f_core_last_psi.rows[0].k[0];
    v13.m_elems[1] = physical_core->m_world_f_core_last_psi.rows[1].k[0];
    v13.m_elems[2] = physical_core->m_world_f_core_last_psi.rows[2].k[0];
    v13.m_elems[3] = 0.0;
    v13.m_elems[4] = physical_core->m_world_f_core_last_psi.rows[0].k[1];
    v13.m_elems[5] = physical_core->m_world_f_core_last_psi.rows[1].k[1];
    v13.m_elems[6] = physical_core->m_world_f_core_last_psi.rows[2].k[1];
    v13.m_elems[7] = 0.0;
    v13.m_elems[8] = physical_core->m_world_f_core_last_psi.rows[0].k[2];
    v13.m_elems[9] = physical_core->m_world_f_core_last_psi.rows[1].k[2];
    *(_QWORD *)&v13.m_elems[10] = LODWORD(physical_core->m_world_f_core_last_psi.rows[2].k[2]);
    v14 = physical_core->m_world_f_core_last_psi.vv.k[0];
    v15 = physical_core->m_world_f_core_last_psi.vv.k[1];
    v6 = physical_core->m_world_f_core_last_psi.vv.k[2];
  }
  v7 = v2->m_entities[1];
  v16 = v6;
  v17 = 1065353216;
  if ( (*(_DWORD *)&v7->flags & 0x800) != 0 )
  {
    v8 = (float *)v7->physical_core;
    *(float *)&axis_ws_4[48] = v8[36];
    *(float *)&axis_ws_4[52] = v8[37];
    v9 = v8[38];
  }
  else
  {
    m_world_f_core_last_psi = v7->physical_core->m_world_f_core_last_psi;
    IVP_U_Matrix::vmult4(
      this: &m_world_f_core_last_psi,
      p_in: &v7->shift_core_f_object,
      p_out: &m_world_f_core_last_psi.vv);
    v2 = v18;
    *(float *)&axis_ws_4[48] = m_world_f_core_last_psi.vv.k[0];
    *(float *)&axis_ws_4[52] = m_world_f_core_last_psi.vv.k[1];
    v9 = m_world_f_core_last_psi.vv.k[2];
  }
  *(float *)&axis_ws_4[56] = v9;
  hk_Vector3::set_rotated_dir(this: (hk_Vector3 *)v11, t: &v13, v: &v2->m_axis_Ros);
  v2->m_limits[0].m_ref_position = (float)((float)(v11[1]
                                                 * (float)((float)(*(float *)&axis_ws_4[52] - v15)
                                                         - v2->m_transform_Ros_Aos.m_translation.y))
                                         + (float)(v11[0]
                                                 * (float)((float)(*(float *)&axis_ws_4[48] - v14)
                                                         - v2->m_transform_Ros_Aos.m_translation.x)))
                                 + (float)(v11[2]
                                         * (float)((float)(*(float *)&axis_ws_4[56] - v16)
                                                 - v2->m_transform_Ros_Aos.m_translation.z));
}

//------------------------------------------------------------------------------
// Address: 0x10039760
// Name: protected: void hk_Prismatic_Constraint::init_prismatic_constraint(class hk_Prismatic_BP const __near *,class hk_Local_Constraint_System __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Prismatic_Constraint::init_prismatic_constraint(
        hk_Prismatic_Constraint *this,
        const hk_Prismatic_BP *bp,
        hk_Local_Constraint_System *sys)
{
  hk_Vector3 *p_m_axis_Ros; // ecx
  float y; // xmm1_4
  float x; // xmm2_4
  float z; // xmm3_4
  float v8; // xmm0_4
  float v9; // xmm0_4
  hk_Vector3 *v10; // eax
  float hesse_val; // xmm1_4
  float v12; // xmm0_4
  hk_Vector3 result; // [esp+8h] [ebp-10h] BYREF
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  p_m_axis_Ros = &this->m_axis_Ros;
  this->m_tau = bp->m_tau;
  this->m_strength = bp->m_strength;
  this->m_transform_Ros_Aos.m_rotation = bp->m_transform_Ros_Aos.m_rotation;
  this->m_transform_Ros_Aos.m_translation.x = bp->m_transform_Ros_Aos.m_translation.x;
  this->m_transform_Ros_Aos.m_translation.y = bp->m_transform_Ros_Aos.m_translation.y;
  this->m_transform_Ros_Aos.m_translation.z = bp->m_transform_Ros_Aos.m_translation.z;
  p_m_axis_Ros->x = bp->m_axis_Ros.x;
  p_m_axis_Ros->y = bp->m_axis_Ros.y;
  p_m_axis_Ros->z = bp->m_axis_Ros.z;
  y = p_m_axis_Ros->y;
  x = p_m_axis_Ros->x;
  z = p_m_axis_Ros->z;
  v8 = (float)((float)(x * x) + (float)(y * y)) + (float)(z * z);
  if ( v8 == 0.0 )
    v9 = 0.0;
  else
    v9 = 1.0 / fsqrt(v8);
  p_m_axis_Ros->x = x * v9;
  p_m_axis_Ros->y = y * v9;
  p_m_axis_Ros->z = z * v9;
  v10 = hk_Vector3_Util::perp_vec(&result, dir: p_m_axis_Ros);
  this->m_perp_axis_Ros.x = v10->x;
  this->m_perp_axis_Ros.y = v10->y;
  this->m_perp_axis_Ros.z = v10->z;
  this->m_limits[0].m_limit_is_enabled = bp->m_limit.m_limit_is_enabled;
  this->m_limits[0].m_friction_is_enabled = bp->m_limit.m_friction_is_enabled;
  this->m_limits[0].m_limit_min = bp->m_limit.m_limit_min;
  this->m_limits[0].m_limit_max = bp->m_limit.m_limit_max;
  this->m_limits[0].m_limit_tau = bp->m_limit.m_limit_tau;
  LODWORD(this->m_limits[0].m_joint_friction) = LODWORD(bp->m_limit.m_joint_friction) & _mask__AbsFloat_;
  this->m_limits[0].m_desired_velocity = bp->m_limit.m_desired_velocity;
  hesse_val = this->m_entities[0]->physical_core->rot_inertia.hesse_val;
  v12 = this->m_entities[1]->physical_core->rot_inertia.hesse_val;
  if ( hesse_val == 0.0 )
  {
    this->m_pos_interpolation_value = 1.0;
    hk_Prismatic_Constraint::reset_linear_limit(this, a2: (int)&savedregs);
  }
  else
  {
    if ( v12 == 0.0 )
      this->m_pos_interpolation_value = 0.0;
    else
      this->m_pos_interpolation_value = v12 / (float)(v12 + hesse_val);
    hk_Prismatic_Constraint::reset_linear_limit(this, a2: (int)&savedregs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100398F0
// Name: public: hk_Prismatic_Constraint::hk_Prismatic_Constraint(class hk_Environment __near *,class hk_Prismatic_BP const __near *,class hk_Rigid_Body __near *,class hk_Rigid_Body __near *)
// Source: json
//------------------------------------------------------------------------------
hk_Prismatic_Constraint *__thiscall hk_Prismatic_Constraint::hk_Prismatic_Constraint(
        hk_Prismatic_Constraint *this,
        hk_Environment *env,
        const hk_Prismatic_BP *bp,
        hk_Rigid_Body *a,
        hk_Rigid_Body *b)
{
  hk_Rigid_Body_Binary_EF::hk_Rigid_Body_Binary_EF(this, env, a, b, __formal: IVP_CP_CONSTRAINTS);
  this->m_constraint_system = nullptr;
  this->m_client_data = nullptr;
  this->__vftable = (hk_Prismatic_Constraint_vtbl *)&hk_Prismatic_Constraint::`vftable';
  *(_WORD *)&this->m_limits[0].m_limit_is_enabled = 0;
  this->m_limits[0].m_limit_min = 0.0;
  this->m_limits[0].m_limit_max = 0.0;
  this->m_limits[0].m_limit_tau = 1.0;
  this->m_limits[0].m_joint_friction = 0.0;
  this->m_limits[0].m_desired_velocity = 0.0;
  this->m_limits[0].m_ref_position = 0.0;
  hk_Prismatic_Constraint::init_prismatic_constraint(this, bp, sys: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10039960
// Name: public: virtual char const __near * hk_Prismatic_Constraint::get_constraint_type(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall hk_Prismatic_Constraint::get_constraint_type(hk_Prismatic_Constraint *this)
{
  return "prismatic";
}

//------------------------------------------------------------------------------
// Address: 0x10039980
// Name: public: hk_Prismatic_Constraint::hk_Prismatic_Constraint(class hk_Local_Constraint_System __near *,class hk_Prismatic_BP const __near *,class hk_Rigid_Body __near *,class hk_Rigid_Body __near *)
// Source: json
//------------------------------------------------------------------------------
hk_Prismatic_Constraint *__thiscall hk_Prismatic_Constraint::hk_Prismatic_Constraint(
        hk_Prismatic_Constraint *this,
        hk_Local_Constraint_System *constraint_system,
        const hk_Prismatic_BP *bp,
        hk_Rigid_Body *a,
        hk_Rigid_Body *b)
{
  hk_Constraint::hk_Constraint(
    this,
    sys: constraint_system,
    a,
    b,
    redundend_prio: IVP_CP_CONSTRAINTS,
    storage_size: 928);
  this->__vftable = (hk_Prismatic_Constraint_vtbl *)&hk_Prismatic_Constraint::`vftable';
  *(_WORD *)&this->m_limits[0].m_limit_is_enabled = 0;
  this->m_limits[0].m_limit_min = 0.0;
  this->m_limits[0].m_limit_max = 0.0;
  this->m_limits[0].m_limit_tau = 1.0;
  this->m_limits[0].m_joint_friction = 0.0;
  this->m_limits[0].m_desired_velocity = 0.0;
  this->m_limits[0].m_ref_position = 0.0;
  hk_Prismatic_Constraint::init_prismatic_constraint(this, bp, sys: constraint_system);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100399F0
// Name: public: virtual void hk_Prismatic_Constraint::step_constraint(class hk_PSI_Info __near &,void __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge hk_Prismatic_Constraint::step_constraint(
        hk_Prismatic_Constraint *this@<ecx>,
        hk_Rigid_Body *a2@<ebp>,
        hk_PSI_Info *pi,
        char *mem,
        float tau_factor,
        float strength_factor)
{
  float v6; // xmm3_4
  float v7; // edi
  bool v8; // zf
  hk_Rigid_Body *v9; // edx
  float w; // esi
  float *physical_core; // eax
  float v12; // xmm0_4
  float *v13; // eax
  float v14; // xmm0_4
  float v15; // xmm2_4
  float y; // esi
  float *v17; // ecx
  float v18; // xmm3_4
  float v19; // xmm4_4
  float v20; // xmm5_4
  float *v21; // eax
  float v22; // xmm6_4
  float v23; // xmm1_4
  float v24; // xmm0_4
  float v25; // xmm2_4
  float v26; // xmm7_4
  float v27; // xmm2_4
  float v28; // xmm4_4
  float v29; // edx
  float v30; // xmm1_4
  float v31; // xmm3_4
  float v32; // xmm2_4
  float v33; // xmm0_4
  float v34; // xmm1_4
  float v35; // xmm5_4
  float v36; // xmm2_4
  float v37; // xmm0_4
  float *v38; // ecx
  int v39; // eax
  float v40; // xmm5_4
  float v41; // xmm0_4
  float v42; // xmm7_4
  float *v43; // eax
  float v44; // xmm3_4
  float v45; // xmm2_4
  float v46; // xmm4_4
  float v47; // xmm1_4
  float v48; // xmm7_4
  float v49; // xmm2_4
  float v50; // xmm0_4
  float v51; // xmm1_4
  float v52; // xmm4_4
  float v53; // xmm3_4
  float v54; // xmm1_4
  float v55; // xmm2_4
  float v56; // xmm5_4
  float v57; // xmm0_4
  float *m_elt; // eax
  float v59; // xmm1_4
  float v60; // xmm0_4
  float v61; // xmm4_4
  float v62; // xmm5_4
  float v63; // xmm0_4
  float v64; // xmm2_4
  float v65; // xmm5_4
  float v66; // xmm2_4
  float v67; // xmm4_4
  hk_Rigid_Body_Core *v68; // ecx
  float *v69; // esi
  float *v70; // ecx
  float v71; // xmm0_4
  float v72; // xmm2_4
  float v73; // xmm1_4
  float v74; // xmm0_4
  bool v75; // sf
  float *v76; // edx
  float *v77; // ecx
  float v78; // xmm0_4
  float v79; // xmm2_4
  float v80; // xmm1_4
  float v81; // xmm0_4
  float v82; // xmm0_4
  float v83; // xmm1_4
  float v84; // xmm2_4
  int v85; // edx
  float *v86; // ecx
  float v87; // xmm2_4
  IVP_U_Matrix v88; // [esp-4Ch] [ebp-25Ch] BYREF
  const float *v89[3]; // [esp-Ch] [ebp-21Ch] BYREF
  hk_Fixed_Dense_Vector<5> impulses; // [esp+0h] [ebp-210h] BYREF
  _BYTE v91[96]; // [esp+54h] [ebp-1BCh] BYREF
  hk_Dense_Matrix v92; // [esp+B4h] [ebp-15Ch] BYREF
  int v93; // [esp+C4h] [ebp-14Ch] BYREF
  hk_Core_VMQ_Input v94; // [esp+D4h] [ebp-13Ch] BYREF
  hk_Core_VMQ_Input v95; // [esp+E0h] [ebp-130h] BYREF
  int v96; // [esp+ECh] [ebp-124h]
  int v97; // [esp+F0h] [ebp-120h]
  _DWORD v98[3]; // [esp+F4h] [ebp-11Ch] BYREF
  hk_Fixed_Dense_Vector<5> delta; // [esp+100h] [ebp-110h] BYREF
  _BYTE shift_ws_Ros_4[64]; // [esp+134h] [ebp-DCh] OVERLAPPED BYREF
  hk_Core_VMQ_Input *v101; // [esp+17Ch] [ebp-94h]
  hk_Core_VMQ_Input *v102; // [esp+180h] [ebp-90h]
  hk_Rotation v103; // [esp+184h] [ebp-8Ch] BYREF
  float v104; // [esp+1B4h] [ebp-5Ch]
  float v105; // [esp+1B8h] [ebp-58h]
  float v106; // [esp+1BCh] [ebp-54h]
  int v107; // [esp+1C0h] [ebp-50h]
  float v108[3]; // [esp+1D0h] [ebp-40h] BYREF
  hk_Vector3 axis_ws; // [esp+1DCh] [ebp-34h]
  hk_Vector3 pos_ws; // [esp+1ECh] [ebp-24h]
  hk_Rigid_Body *b0; // [esp+1FCh] [ebp-14h]
  float v112; // [esp+200h] [ebp-10h] BYREF
  hk_Rigid_Body *b1; // [esp+204h] [ebp-Ch]
  void *v114; // [esp+208h] [ebp-8h]
  void *retaddr; // [esp+210h] [ebp+0h]

  b1 = a2;
  v114 = retaddr;
  v6 = tau_factor;
  v7 = *(float *)&this;
  v8 = *(_WORD *)&this->m_limits[0].m_limit_is_enabled == 0;
  v9 = this->m_entities[0];
  w = *(float *)&this->m_entities[1];
  v112 = *(float *)&this;
  LODWORD(pos_ws.y) = v9;
  pos_ws.w = w;
  if ( !v8 )
  {
    if ( (*(_DWORD *)&v9->flags & 0x800) != 0 )
    {
      physical_core = (float *)v9->physical_core;
      v103.m_elems[0] = physical_core[24];
      v103.m_elems[1] = physical_core[28];
      v103.m_elems[2] = physical_core[32];
      v103.m_elems[3] = 0.0;
      v103.m_elems[4] = physical_core[25];
      v103.m_elems[5] = physical_core[29];
      v103.m_elems[6] = physical_core[33];
      v103.m_elems[7] = 0.0;
      v103.m_elems[8] = physical_core[26];
      v103.m_elems[9] = physical_core[30];
      v103.m_elems[10] = physical_core[34];
      v103.m_elems[11] = 0.0;
      v104 = physical_core[36];
      v105 = physical_core[37];
      v12 = physical_core[38];
    }
    else
    {
      qmemcpy(shift_ws_Ros_4, &v9->physical_core->m_world_f_core_last_psi, sizeof(shift_ws_Ros_4));
      IVP_U_Matrix::vmult4(
        this: (IVP_U_Matrix *)shift_ws_Ros_4,
        p_in: &v9->shift_core_f_object,
        p_out: (IVP_U_Float_Point *)&shift_ws_Ros_4[48]);
      v7 = v112;
      w = pos_ws.w;
      v103.m_elems[0] = *(float *)shift_ws_Ros_4;
      v103.m_elems[4] = *(float *)&shift_ws_Ros_4[4];
      v103.m_elems[1] = *(float *)&shift_ws_Ros_4[16];
      v103.m_elems[5] = *(float *)&shift_ws_Ros_4[20];
      v103.m_elems[2] = *(float *)&shift_ws_Ros_4[32];
      v103.m_elems[6] = *(float *)&shift_ws_Ros_4[36];
      v103.m_elems[3] = 0.0;
      v103.m_elems[7] = 0.0;
      v103.m_elems[11] = 0.0;
      v103.m_elems[8] = *(float *)&shift_ws_Ros_4[8];
      v104 = *(float *)&shift_ws_Ros_4[48];
      v103.m_elems[9] = *(float *)&shift_ws_Ros_4[24];
      v105 = *(float *)&shift_ws_Ros_4[52];
      v12 = *(float *)&shift_ws_Ros_4[56];
      v103.m_elems[10] = *(float *)&shift_ws_Ros_4[40];
    }
    v8 = (*(_DWORD *)(LODWORD(w) + 68) & 0x800) == 0;
    v106 = v12;
    v107 = 1065353216;
    if ( v8 )
    {
      v88 = *(IVP_U_Matrix *)(*(_DWORD *)(LODWORD(w) + 148) + 96);
      IVP_U_Matrix::vmult4(this: &v88, p_in: (const IVP_U_Float_Point *)(LODWORD(pos_ws.w) + 48), p_out: &v88.vv);
      v7 = v112;
      *(float *)&shift_ws_Ros_4[48] = v88.vv.k[0];
      *(float *)&shift_ws_Ros_4[52] = v88.vv.k[1];
      v14 = v88.vv.k[2];
    }
    else
    {
      v13 = *(float **)(LODWORD(w) + 148);
      *(float *)&shift_ws_Ros_4[48] = v13[36];
      *(float *)&shift_ws_Ros_4[52] = v13[37];
      v14 = v13[38];
    }
    *(float *)&shift_ws_Ros_4[56] = v14;
    hk_Vector3::set_rotated_dir(this: (hk_Vector3 *)v108, t: &v103, v: (const hk_Vector3 *)(LODWORD(v7) + 64));
    v15 = *(float *)(LODWORD(v7) + 32);
    axis_ws.y = (float)((float)(1.0 - v15) * v104) + (float)(*(float *)&shift_ws_Ros_4[48] * v15);
    axis_ws.z = (float)((float)(1.0 - v15) * v105) + (float)(*(float *)&shift_ws_Ros_4[52] * v15);
    axis_ws.w = (float)((float)(1.0 - v15) * v106) + (float)(*(float *)&shift_ws_Ros_4[56] * v15);
    hk_Vector3::set_rotated_dir(
      this: (hk_Vector3 *)&delta.m_elt_buffer[5],
      t: &v103,
      v: (const hk_Vector3 *)(LODWORD(v7) + 112));
    v112 = (float)((float)(v108[1] * (float)((float)(*(float *)&shift_ws_Ros_4[52] - v105) - delta.m_elt_buffer[6]))
                 + (float)(v108[0] * (float)((float)(*(float *)&shift_ws_Ros_4[48] - v104) - delta.m_elt_buffer[5])))
         + (float)(v108[2] * (float)((float)(*(float *)&shift_ws_Ros_4[56] - v106) - delta.m_elt_buffer[7]));
    v92.m_elt = (float *)&v93;
    v92.m_rows = 1;
    v92.m_cols = 1;
    v92.m_lda = 4;
    hk_VM_Query_Builder<hk_VMQ_Storage<1>>::begin(
      this: (hk_VM_Query_Builder<hk_VMQ_Storage<1> > *)&impulses.m_elt_buffer[5],
      size: 1);
    y = pos_ws.y;
    v17 = *(float **)(LODWORD(pos_ws.y) + 148);
    v18 = axis_ws.y - v17[36];
    v19 = axis_ws.z - v17[37];
    v20 = axis_ws.w - v17[38];
    v21 = (float *)&v91[v96];
    *v21 = v108[0];
    v21[1] = v108[1];
    v21[2] = v108[2];
    v22 = v21[1];
    v23 = *v21 * v20;
    *(float *)&b0 = *v21 * v19;
    v24 = (float)(v22 * v18) - *(float *)&b0;
    v25 = v21[2];
    v21[6] = v24;
    v26 = v25;
    v27 = v25 * v19;
    v28 = v24;
    v21[4] = v27 - (float)(v22 * v20);
    v29 = pos_ws.w;
    v30 = v23 - (float)(v26 * v18);
    v21[5] = v30;
    v31 = v21[4];
    v32 = v30;
    v33 = (float)((float)(v17[25] * v31) + (float)(v17[29] * v30)) + (float)(v17[33] * v24);
    v34 = (float)((float)(v17[26] * v31) + (float)(v17[30] * v30)) + (float)(v17[34] * v28);
    v35 = (float)(v17[28] * v32) + (float)(v17[24] * v31);
    v36 = v17[32];
    v21[5] = v33;
    v37 = axis_ws.y;
    v21[6] = v34;
    v21[4] = v35 + (float)(v36 * v28);
    *((_DWORD *)v21 + 8) = v97;
    v38 = *(float **)(LODWORD(v29) + 148);
    v39 = v96;
    v40 = v37 - v38[36];
    v41 = axis_ws.z - v38[37];
    v42 = axis_ws.w - v38[38];
    *(float *)&v91[v96 + 48] = v108[0] * -1.0;
    v43 = (float *)&v91[v39 + 48];
    v43[1] = v108[1] * -1.0;
    v43[2] = v108[2] * -1.0;
    v44 = v43[1];
    v45 = v43[2];
    v46 = *v43;
    axis_ws.w = v42;
    v47 = v46 * v42;
    v48 = v45 * v40;
    v49 = (float)(v45 * v41) - (float)(v44 * axis_ws.w);
    v43[4] = v49;
    v43[6] = (float)(v44 * v40) - (float)(v46 * v41);
    v50 = v49;
    v51 = v47 - v48;
    v43[5] = v51;
    v52 = v43[6];
    v53 = v51;
    v54 = (float)((float)(v38[25] * v49) + (float)(v38[29] * v51)) + (float)(v38[33] * v52);
    v55 = (float)((float)(v38[26] * v49) + (float)(v38[30] * v53)) + (float)(v38[34] * v52);
    v56 = (float)(v38[28] * v53) + (float)(v50 * v38[24]);
    v57 = v38[32];
    v43[5] = v54;
    v43[6] = v55;
    v43[4] = v56 + (float)(v57 * v52);
    *((_DWORD *)v43 + 8) = v97;
    v96 += 48;
    v94.m_n_queries = ++v97;
    v95.m_n_queries = v97;
    hk_Rigid_Body_Core::add_to_mass_matrix_inv(
      this: *(hk_Rigid_Body_Core **)(LODWORD(y) + 148),
      input: &v94,
      matrix_out: &v92,
      velocities_out: &impulses.m_elt_buffer[5]);
    v94.m_n_queries = v97;
    v95.m_n_queries = v97;
    hk_Rigid_Body_Core::add_to_mass_matrix_inv(
      this: *(hk_Rigid_Body_Core **)(LODWORD(pos_ws.w) + 148),
      input: &v95,
      matrix_out: &v92,
      velocities_out: &impulses.m_elt_buffer[5]);
    m_elt = v92.m_elt;
    v59 = 1.0 / *v92.m_elt;
    v60 = 0.0;
    if ( *(_BYTE *)(LODWORD(v7) + 37) != 0 )
    {
      v61 = (float)(*(float *)(LODWORD(v7) + 56) * pi->delta_time) + *(float *)(LODWORD(v7) + 60);
      v62 = *(float *)(LODWORD(v7) + 52);
      v63 = (float)(tau_factor * 0.80000001) * (float)(v112 - *(float *)(LODWORD(v7) + 60));
      pos_ws.z = v112 - *(float *)(LODWORD(v7) + 60);
      v64 = impulses.m_elt_buffer[5] * strength_factor;
      *(float *)(LODWORD(v7) + 60) = v61;
      v60 = (float)((float)(v63 * pi->i_delta_time) - v64) * v59;
      b0 = (hk_Rigid_Body *)(LODWORD(v60) & _mask__AbsFloat_);
      if ( (float)(COERCE_FLOAT(LODWORD(v60) & _mask__AbsFloat_) * pi->i_delta_time) > v62 )
      {
        v65 = (float)(v62 / *(float *)&b0) * pi->delta_time;
        v60 = v65 * v60;
        *(float *)(LODWORD(v7) + 60) = (float)((float)(1.0 - v65) * pos_ws.z) + v61;
      }
    }
    v6 = tau_factor;
    if ( *(_BYTE *)(LODWORD(v7) + 36) != 0 )
    {
      v66 = v112 - (float)((float)((float)(v60 * *m_elt) + impulses.m_elt_buffer[5]) * pi->delta_time);
      v67 = *(float *)(LODWORD(v7) + 44);
      if ( v66 > v67 || (v67 = *(float *)(LODWORD(v7) + 40)) > v66 )
        v60 = v60
            + (float)((float)((float)((float)((float)(v66 - v67) * tau_factor) * *(float *)(LODWORD(v7) + 48))
                            * pi->i_delta_time)
                    * v59);
    }
    if ( v60 != 0.0 )
    {
      v68 = *(hk_Rigid_Body_Core **)(LODWORD(y) + 148);
      v112 = v60;
      hk_Rigid_Body_Core::apply_impulses(this: v68, input: &v94, impulse_strength: &v112);
      hk_Rigid_Body_Core::apply_impulses(
        this: *(hk_Rigid_Body_Core **)(LODWORD(pos_ws.w) + 148),
        input: &v95,
        impulse_strength: &v112);
      v6 = tau_factor;
    }
    v9 = (hk_Rigid_Body *)LODWORD(y);
  }
  *((_DWORD *)mem + 15) = 0;
  *((_DWORD *)mem + 14) = 0;
  *((_DWORD *)mem + 13) = 0;
  *((_DWORD *)mem + 12) = 0;
  *((_DWORD *)mem + 19) = 0;
  *((_DWORD *)mem + 18) = 0;
  *((_DWORD *)mem + 17) = 0;
  *((_DWORD *)mem + 16) = 0;
  v69 = (float *)v9->physical_core;
  b0 = (hk_Rigid_Body *)(*((_DWORD *)mem + 224) - 1);
  v112 = *((float *)mem + 225);
  v101 = (hk_Core_VMQ_Input *)(mem + 896);
  v70 = (float *)(LODWORD(v112) + 24);
  do
  {
    v71 = *(v70 - 5) * v69[53];
    v72 = *(v70 - 1) * v69[49];
    pos_ws.z = v70[2];
    v73 = *(float *)LODWORD(v112) * v69[52];
    LODWORD(v112) += 48;
    v74 = (float)((float)((float)(v71 + v73) + (float)(*(v70 - 4) * v69[54]))
                + (float)((float)((float)(*(v70 - 2) * v69[48]) + v72) + (float)(v69[50] * *v70)))
        + *(float *)&mem[4 * LODWORD(pos_ws.z) + 48];
    v70 += 12;
    v75 = (int)&b0[-1].client_data + 15 < 0;
    b0 = (hk_Rigid_Body *)((char *)b0 - 1);
    *(float *)&mem[4 * LODWORD(pos_ws.z) + 48] = v74;
  }
  while ( !v75 );
  v76 = *(float **)(LODWORD(pos_ws.w) + 148);
  b0 = (hk_Rigid_Body *)(*((_DWORD *)mem + 227) - 1);
  v112 = *((float *)mem + 228);
  v102 = (hk_Core_VMQ_Input *)(mem + 908);
  v77 = (float *)(LODWORD(v112) + 24);
  do
  {
    v78 = *(v77 - 5) * v76[53];
    v79 = *(v77 - 1) * v76[49];
    pos_ws.z = v77[2];
    v80 = *(float *)LODWORD(v112) * v76[52];
    LODWORD(v112) += 48;
    v81 = (float)((float)((float)(v78 + v80) + (float)(*(v77 - 4) * v76[54]))
                + (float)((float)((float)(*(v77 - 2) * v76[48]) + v79) + (float)(*v77 * v76[50])))
        + *(float *)&mem[4 * LODWORD(pos_ws.z) + 48];
    v77 += 12;
    v75 = (int)&b0[-1].client_data + 15 < 0;
    b0 = (hk_Rigid_Body *)((char *)b0 - 1);
    *(float *)&mem[4 * LODWORD(pos_ws.z) + 48] = v81;
  }
  while ( !v75 );
  v82 = (float)(*(float *)(LODWORD(v7) + 24) * -1.0) * strength_factor;
  v83 = *((float *)mem + 8);
  v84 = *((float *)mem + 16) * v82;
  v98[0] = &delta.m_size;
  v98[1] = 5;
  v98[2] = 8;
  delta.m_elt_buffer[1] = (float)(v83 * v6) + v84;
  v85 = 3;
  v86 = (float *)(mem + 24);
  do
  {
    v87 = *v86;
    *(float *)((char *)v86 + (char *)&v98[1] - mem) = (float)(*(float *)&mem[4 * v85 + 48] * v82) + (float)(v86[1] * v6);
    *(float *)((char *)v86 + (char *)v98 - mem) = (float)(*(float *)&mem[4 * v85 + 44] * v82) + (float)(v87 * v6);
    v85 -= 2;
    v86 -= 2;
  }
  while ( v85 > 0 );
  v89[0] = (const float *)&impulses.m_size;
  v89[1] = (const float *)5;
  v89[2] = (const float *)8;
  hk_Dense_Matrix_Util::mult(
    m: (const hk_Dense_Matrix *)mem + 45,
    in: (const hk_Dense_Vector *)v98,
    out: (hk_Dense_Vector *)v89);
  hk_Rigid_Body_Core::apply_impulses(
    this: *(hk_Rigid_Body_Core **)(LODWORD(pos_ws.y) + 148),
    input: v101,
    impulse_strength: v89[0]);
  hk_Rigid_Body_Core::apply_impulses(
    this: *(hk_Rigid_Body_Core **)(LODWORD(pos_ws.w) + 148),
    input: v102,
    impulse_strength: v89[0]);
}

//------------------------------------------------------------------------------
// Address: 0x1003A4B0
// Name: public: virtual void hk_Prismatic_Constraint::init_constraint(void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Prismatic_Constraint::init_constraint(hk_Prismatic_Constraint *this, const hk_Prismatic_BP *vbp)
{
  hk_Prismatic_Constraint::init_prismatic_constraint(this, bp: vbp, sys: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1003A4D0
// Name: public: virtual int hk_Prismatic_Constraint::setup_and_step_constraint(class hk_PSI_Info __near &,void __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __userpurge hk_Prismatic_Constraint::setup_and_step_constraint@<eax>(
        hk_Prismatic_Constraint *this@<ecx>,
        hk_Rigid_Body *a2@<ebp>,
        hk_PSI_Info *pi,
        _DWORD *mem,
        float tau_factor,
        float strength_factor)
{
  float z; // esi
  float w; // edi
  hk_Rigid_Body *v8; // eax
  bool v9; // zf
  float y; // edx
  float *physical_core; // eax
  float v12; // xmm1_4
  int v13; // eax
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  float v18; // xmm2_4
  float v19; // xmm2_4
  float v20; // xmm4_4
  float v21; // xmm3_4
  float v22; // xmm0_4
  int v23; // eax
  hk_Rigid_Body *v24; // edi
  float *v25; // ecx
  float v26; // xmm7_4
  float v27; // xmm0_4
  float v28; // xmm4_4
  float v29; // xmm5_4
  float v30; // xmm6_4
  float *v31; // eax
  float v32; // xmm3_4
  float v33; // xmm1_4
  float v34; // xmm2_4
  float v35; // xmm3_4
  float v36; // xmm4_4
  float v37; // xmm3_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float *v40; // ecx
  float v41; // xmm3_4
  float v42; // xmm4_4
  float v43; // xmm5_4
  float *v44; // eax
  float v45; // xmm7_4
  float v46; // xmm6_4
  float v47; // xmm1_4
  float v48; // xmm7_4
  float v49; // xmm0_4
  float v50; // xmm6_4
  float v51; // xmm0_4
  float v52; // xmm1_4
  float v53; // xmm4_4
  float v54; // xmm3_4
  float v55; // xmm1_4
  float v56; // xmm2_4
  float v57; // xmm5_4
  float v58; // xmm0_4
  float *m_elt; // eax
  float v60; // xmm0_4
  float v61; // xmm1_4
  float v62; // xmm6_4
  float v63; // xmm4_4
  float v64; // xmm2_4
  float v65; // xmm5_4
  float v66; // xmm5_4
  float v67; // xmm2_4
  float v68; // xmm3_4
  hk_Rigid_Body_Core *v69; // ecx
  int v70; // esi
  int v71; // edx
  float *v72; // ecx
  float v73; // xmm4_4
  float v74; // xmm1_4
  float v75; // xmm5_4
  int v76; // eax
  float v77; // xmm2_4
  float v78; // xmm3_4
  float v79; // xmm6_4
  float v80; // xmm1_4
  int v81; // edx
  int v82; // eax
  float v83; // edx
  float *v84; // ecx
  float v85; // xmm5_4
  float v86; // xmm2_4
  float v87; // xmm6_4
  float v88; // xmm3_4
  float v89; // xmm4_4
  float v90; // xmm7_4
  float v91; // xmm2_4
  int v92; // eax
  float v93; // xmm2_4
  float *v94; // ecx
  float v95; // xmm4_4
  float v96; // xmm5_4
  int v97; // eax
  float v98; // xmm6_4
  float v99; // xmm2_4
  float v100; // xmm3_4
  float v101; // xmm7_4
  float v102; // xmm4_4
  int v103; // eax
  float v104; // xmm2_4
  float *v105; // ecx
  float v106; // xmm5_4
  float v107; // xmm4_4
  float v108; // xmm6_4
  float v109; // xmm2_4
  float v110; // xmm3_4
  float v111; // xmm7_4
  float v112; // xmm4_4
  int v113; // eax
  float v114; // xmm2_4
  float *v115; // ecx
  float v116; // xmm4_4
  float v117; // xmm5_4
  int v118; // eax
  float v119; // xmm6_4
  float v120; // xmm2_4
  float v121; // xmm3_4
  float v122; // xmm7_4
  float v123; // xmm4_4
  int v124; // eax
  float *v125; // ecx
  float v126; // xmm4_4
  float v127; // xmm0_4
  float v128; // xmm5_4
  float v129; // xmm2_4
  float v130; // xmm3_4
  float v131; // xmm6_4
  float v132; // xmm4_4
  float v133; // xmm6_4
  float v134; // xmm0_4
  float v135; // xmm0_4
  float v136; // xmm5_4
  float v137; // xmm6_4
  float *v138; // eax
  float v139; // xmm0_4
  float v140; // xmm3_4
  float v141; // xmm2_4
  float *v142; // eax
  float v143; // xmm7_4
  float v144; // xmm5_4
  int v145; // eax
  float v146; // xmm4_4
  float v147; // xmm5_4
  float v148; // xmm6_4
  float v149; // xmm6_4
  float *v150; // ecx
  float v151; // xmm4_4
  float v152; // xmm5_4
  float v153; // xmm7_4
  float v154; // xmm6_4
  float v155; // xmm7_4
  float v156; // xmm6_4
  float v157; // xmm7_4
  float v158; // xmm6_4
  int v159; // eax
  float v160; // xmm4_4
  float v161; // xmm5_4
  float v162; // xmm6_4
  float v163; // xmm4_4
  float v164; // xmm5_4
  float v165; // xmm6_4
  float *v166; // ecx
  float v167; // xmm4_4
  float v168; // xmm5_4
  float v169; // xmm6_4
  float v170; // xmm7_4
  float v171; // xmm4_4
  int v172; // eax
  float v173; // xmm4_4
  int v174; // eax
  float v175; // xmm5_4
  float v176; // xmm7_4
  float v177; // xmm6_4
  float v178; // xmm5_4
  float *v179; // ecx
  float v180; // xmm4_4
  float v181; // xmm5_4
  float v182; // xmm2_4
  float v183; // xmm3_4
  float v184; // xmm6_4
  float v185; // xmm0_4
  float v186; // xmm0_4
  int v187; // eax
  int v188; // eax
  float v189; // xmm3_4
  float v190; // xmm7_4
  float v191; // xmm2_4
  float v192; // xmm4_4
  float v193; // xmm1_4
  float v194; // xmm0_4
  float v195; // xmm2_4
  float *v196; // ecx
  float v197; // xmm4_4
  float v198; // xmm0_4
  float v199; // xmm3_4
  float v200; // xmm1_4
  float v201; // xmm2_4
  float v202; // xmm5_4
  float v203; // xmm0_4
  int v204; // eax
  hk_Rigid_Body_Core *v205; // ecx
  float *v206; // eax
  hk_Core_VMQ_Input *v207; // ecx
  float v208; // edx
  float v209; // eax
  float v210; // xmm0_4
  float v211; // xmm1_4
  float v212; // xmm1_4
  float *v213; // ecx
  char *v214; // edx
  int v215; // eax
  hk_Rigid_Body *v216; // esi
  const float *v218[3]; // [esp+14h] [ebp-26Ch] BYREF
  hk_Fixed_Dense_Vector<5> impulses; // [esp+20h] [ebp-260h] BYREF
  _BYTE v220[96]; // [esp+74h] [ebp-20Ch] BYREF
  hk_Dense_Matrix v221; // [esp+D4h] [ebp-1ACh] BYREF
  int v222; // [esp+E4h] [ebp-19Ch] BYREF
  hk_Core_VMQ_Input v223; // [esp+F4h] [ebp-18Ch] BYREF
  hk_Core_VMQ_Input v224; // [esp+100h] [ebp-180h] BYREF
  int v225; // [esp+10Ch] [ebp-174h]
  int v226; // [esp+110h] [ebp-170h]
  _DWORD v227[3]; // [esp+114h] [ebp-16Ch] BYREF
  _BYTE delta_4[108]; // [esp+124h] [ebp-15Ch] OVERLAPPED BYREF
  int v229; // [esp+190h] [ebp-F0h]
  int v230; // [esp+194h] [ebp-ECh]
  int v231; // [esp+198h] [ebp-E8h]
  int v232; // [esp+19Ch] [ebp-E4h]
  int v233; // [esp+1A0h] [ebp-E0h]
  int v234; // [esp+1A4h] [ebp-DCh]
  int v235; // [esp+1A8h] [ebp-D8h]
  int v236; // [esp+1ACh] [ebp-D4h]
  int v237; // [esp+1B0h] [ebp-D0h]
  float v238; // [esp+1B4h] [ebp-CCh]
  float v239; // [esp+1B8h] [ebp-C8h]
  float v240; // [esp+1BCh] [ebp-C4h]
  int v241; // [esp+1C0h] [ebp-C0h]
  float v242; // [esp+1C4h] [ebp-BCh]
  float v243; // [esp+1C8h] [ebp-B8h]
  float v244; // [esp+1CCh] [ebp-B4h]
  hk_Vector3 perp_axis2_ws; // [esp+1D0h] [ebp-B0h] BYREF
  hk_Vector3 axis_ws; // [esp+1E0h] [ebp-A0h] BYREF
  hk_Vector3 perp_axis_ws; // [esp+1F0h] [ebp-90h] BYREF
  hk_Vector3 shift_ws_Ros; // [esp+200h] [ebp-80h] BYREF
  int v249; // [esp+210h] [ebp-70h]
  float v250; // [esp+214h] [ebp-6Ch]
  float v251; // [esp+218h] [ebp-68h]
  float v252; // [esp+21Ch] [ebp-64h]
  int v253; // [esp+220h] [ebp-60h]
  float v254; // [esp+224h] [ebp-5Ch]
  float v255; // [esp+228h] [ebp-58h]
  float v256; // [esp+22Ch] [ebp-54h]
  int v257; // [esp+230h] [ebp-50h]
  float v258; // [esp+234h] [ebp-4Ch]
  float v259; // [esp+238h] [ebp-48h]
  float v260; // [esp+23Ch] [ebp-44h]
  int v261; // [esp+240h] [ebp-40h]
  float v262; // [esp+24Ch] [ebp-34h]
  float v263; // [esp+250h] [ebp-30h]
  float v264; // [esp+254h] [ebp-2Ch]
  hk_Mass_Relative_Vector3 mcr_1; // [esp+258h] [ebp-28h]
  hk_Rigid_Body *b1; // [esp+268h] [ebp-18h]
  float v267; // [esp+26Ch] [ebp-14h] BYREF
  hk_Prismatic_Work *work; // [esp+270h] [ebp-10h]
  hk_Rigid_Body *b0; // [esp+274h] [ebp-Ch]
  void *v270; // [esp+278h] [ebp-8h]
  void *retaddr; // [esp+280h] [ebp+0h]

  b0 = a2;
  v270 = retaddr;
  z = *(float *)&this;
  LODWORD(mcr_1.m_vector.z) = this;
  if ( *(float *)&mem == 0.0 )
  {
    mcr_1.m_vector.w = 0.0;
    w = 0.0;
  }
  else
  {
    *mem = mem + 4;
    mem[1] = 5;
    mem[2] = 8;
    mem[180] = mem + 184;
    w = *(float *)&mem;
    mem[181] = 5;
    mem[182] = 5;
    mem[183] = 8;
    LODWORD(mcr_1.m_vector.w) = mem;
  }
  v8 = this->m_entities[0];
  v9 = (*(_DWORD *)&v8->flags & 0x800) == 0;
  y = *(float *)&this->m_entities[1];
  b1 = v8;
  mcr_1.m_vector.y = y;
  if ( v9 )
  {
    qmemcpy(&delta_4[32], &v8->physical_core->m_world_f_core_last_psi, 0x40u);
    IVP_U_Matrix::vmult4(
      this: (IVP_U_Matrix *)&delta_4[32],
      p_in: &v8->shift_core_f_object,
      p_out: (IVP_U_Float_Point *)&delta_4[80]);
    y = mcr_1.m_vector.y;
    z = mcr_1.m_vector.z;
    w = mcr_1.m_vector.w;
    v250 = *(float *)&delta_4[36];
    v251 = *(float *)&delta_4[52];
    v252 = *(float *)&delta_4[68];
    v254 = *(float *)&delta_4[40];
    v255 = *(float *)&delta_4[56];
    shift_ws_Ros.y = *(float *)&delta_4[32];
    v256 = *(float *)&delta_4[72];
    shift_ws_Ros.z = *(float *)&delta_4[48];
    v258 = *(float *)&delta_4[80];
    shift_ws_Ros.w = *(float *)&delta_4[64];
    v259 = *(float *)&delta_4[84];
    v12 = *(float *)&delta_4[88];
    v249 = 0;
    v253 = 0;
    v257 = 0;
  }
  else
  {
    physical_core = (float *)v8->physical_core;
    shift_ws_Ros.y = physical_core[24];
    shift_ws_Ros.z = physical_core[28];
    shift_ws_Ros.w = physical_core[32];
    v249 = 0;
    v250 = physical_core[25];
    v251 = physical_core[29];
    v252 = physical_core[33];
    v253 = 0;
    v254 = physical_core[26];
    v255 = physical_core[30];
    v256 = physical_core[34];
    v257 = 0;
    v258 = physical_core[36];
    v259 = physical_core[37];
    v12 = physical_core[38];
  }
  v260 = v12;
  v261 = 1065353216;
  if ( (*(_DWORD *)(LODWORD(y) + 68) & 0x800) != 0 )
  {
    v13 = *(_DWORD *)(LODWORD(y) + 148);
    *(_DWORD *)&delta_4[96] = *(_DWORD *)(v13 + 96);
    *(_DWORD *)&delta_4[100] = *(_DWORD *)(v13 + 112);
    *(_DWORD *)&delta_4[104] = *(_DWORD *)(v13 + 128);
    v229 = 0;
    v230 = *(_DWORD *)(v13 + 100);
    v231 = *(_DWORD *)(v13 + 116);
    v232 = *(_DWORD *)(v13 + 132);
    v233 = 0;
    v234 = *(_DWORD *)(v13 + 104);
    v235 = *(_DWORD *)(v13 + 120);
    v236 = *(_DWORD *)(v13 + 136);
    v237 = 0;
    v238 = *(float *)(v13 + 144);
    v239 = *(float *)(v13 + 148);
    v240 = *(float *)(v13 + 152);
  }
  else
  {
    qmemcpy(&delta_4[32], (const void *)(*(_DWORD *)(LODWORD(y) + 148) + 96), 0x40u);
    IVP_U_Matrix::vmult4(
      this: (IVP_U_Matrix *)&delta_4[32],
      p_in: (const IVP_U_Float_Point *)(LODWORD(y) + 48),
      p_out: (IVP_U_Float_Point *)&delta_4[80]);
    z = mcr_1.m_vector.z;
    w = mcr_1.m_vector.w;
    *(_DWORD *)&delta_4[96] = *(_DWORD *)&delta_4[32];
    *(_DWORD *)&delta_4[100] = *(_DWORD *)&delta_4[48];
    *(_DWORD *)&delta_4[104] = *(_DWORD *)&delta_4[64];
    v230 = *(_DWORD *)&delta_4[36];
    v229 = 0;
    v231 = *(_DWORD *)&delta_4[52];
    v233 = 0;
    v237 = 0;
    v232 = *(_DWORD *)&delta_4[68];
    v238 = *(float *)&delta_4[80];
    v234 = *(_DWORD *)&delta_4[40];
    v239 = *(float *)&delta_4[84];
    v235 = *(_DWORD *)&delta_4[56];
    v240 = *(float *)&delta_4[88];
    v236 = *(_DWORD *)&delta_4[72];
  }
  v241 = 1065353216;
  hk_Matrix3::set_mul3_inv(
    this: (hk_Matrix3 *)&delta_4[48],
    Ma: (const hk_Rotation *)&delta_4[96],
    Mb: (const hk_Matrix3 *)&shift_ws_Ros.y);
  hk_Quaternion::set(this: (hk_Quaternion *)&perp_axis_ws.y, r: (const hk_Rotation *)&delta_4[48]);
  v14 = *(float *)(LODWORD(z) + 108);
  v15 = (float)(shift_ws_Ros.x * *(float *)(LODWORD(z) + 96))
      + (float)((float)((float)(*(float *)(LODWORD(z) + 100) * perp_axis_ws.w)
                      - (float)(*(float *)(LODWORD(z) + 104) * perp_axis_ws.z))
              + (float)(perp_axis_ws.y * v14));
  v16 = (float)(*(float *)(LODWORD(z) + 104) * shift_ws_Ros.x)
      + (float)((float)(v14 * perp_axis_ws.w)
              + (float)((float)(*(float *)(LODWORD(z) + 96) * perp_axis_ws.z)
                      - (float)(perp_axis_ws.y * *(float *)(LODWORD(z) + 100))));
  v17 = (float)((float)(tau_factor * 2.0) * *(float *)(LODWORD(z) + 28)) * pi->i_delta_time;
  v18 = (float)(shift_ws_Ros.x * *(float *)(LODWORD(z) + 100))
      + (float)((float)(*(float *)(LODWORD(z) + 108) * perp_axis_ws.z)
              + (float)((float)(perp_axis_ws.y * *(float *)(LODWORD(z) + 104))
                      - (float)(*(float *)(LODWORD(z) + 96) * perp_axis_ws.w)));
  if ( shift_ws_Ros.x > 0.0 )
    LODWORD(v17) ^= _mask__NegFloat_;
  **(float **)LODWORD(w) = v15 * v17;
  *(float *)(*(_DWORD *)LODWORD(w) + 4) = v18 * v17;
  *(float *)(*(_DWORD *)LODWORD(w) + 8) = v16 * v17;
  hk_Vector3::set_rotated_dir(
    this: (hk_Vector3 *)&perp_axis2_ws.y,
    t: (const hk_Rotation *)&shift_ws_Ros.y,
    v: (const hk_Vector3 *)(LODWORD(z) + 64));
  hk_Vector3::set_rotated_dir(
    this: (hk_Vector3 *)&axis_ws.y,
    t: (const hk_Rotation *)&shift_ws_Ros.y,
    v: (const hk_Vector3 *)(LODWORD(z) + 80));
  v242 = (float)(perp_axis2_ws.z * axis_ws.w) - (float)(perp_axis2_ws.w * axis_ws.z);
  v243 = (float)(axis_ws.y * perp_axis2_ws.w) - (float)(perp_axis2_ws.y * axis_ws.w);
  v244 = (float)(perp_axis2_ws.y * axis_ws.z) - (float)(axis_ws.y * perp_axis2_ws.z);
  hk_Vector3::set_rotated_dir(
    this: (hk_Vector3 *)&perp_axis_ws.y,
    t: (const hk_Rotation *)&shift_ws_Ros.y,
    v: (const hk_Vector3 *)(LODWORD(z) + 112));
  v19 = (float)(v240 - v260) - perp_axis_ws.w;
  v20 = (float)(v239 - v259) - perp_axis_ws.z;
  v21 = (float)(v238 - v258) - perp_axis_ws.y;
  *(float *)(*(_DWORD *)LODWORD(w) + 12) = (float)((float)((float)(axis_ws.z * v20) + (float)(axis_ws.y * v21))
                                                 + (float)(axis_ws.w * v19))
                                         * (float)((float)(tau_factor * *(float *)(LODWORD(z) + 28)) * pi->i_delta_time);
  *(float *)(*(_DWORD *)LODWORD(w) + 16) = (float)((float)((float)(v20 * v243) + (float)(v21 * v242))
                                                 + (float)(v19 * v244))
                                         * (float)((float)(tau_factor * *(float *)(LODWORD(z) + 28)) * pi->i_delta_time);
  v22 = *(float *)(LODWORD(z) + 32);
  v9 = *(_WORD *)(LODWORD(z) + 36) == 0;
  v262 = (float)(v22 * v238) + (float)((float)(1.0 - v22) * v258);
  v263 = (float)(v22 * v239) + (float)((float)(1.0 - v22) * v259);
  v264 = (float)(v22 * v240) + (float)((float)(1.0 - v22) * v260);
  if ( v9 )
  {
    v24 = b1;
  }
  else
  {
    v267 = (float)((float)(perp_axis2_ws.z * v20) + (float)(perp_axis2_ws.y * v21)) + (float)(perp_axis2_ws.w * v19);
    v221.m_elt = (float *)&v222;
    v221.m_rows = 1;
    v221.m_cols = 1;
    v221.m_lda = 4;
    hk_VM_Query_Builder<hk_VMQ_Storage<1>>::begin(
      this: (hk_VM_Query_Builder<hk_VMQ_Storage<1> > *)&impulses.m_elt_buffer[5],
      size: 1);
    v23 = v225;
    v24 = b1;
    v25 = (float *)b1->physical_core;
    v26 = perp_axis2_ws.y;
    v27 = v262 - v25[36];
    v28 = v263 - v25[37];
    v29 = v264 - v25[38];
    *(float *)&v220[v225 + 4] = perp_axis2_ws.z;
    *(float *)&v220[v23 + 8] = perp_axis2_ws.w;
    *(float *)&v220[v23] = v26;
    v30 = *(float *)&v220[v23 + 4];
    v31 = (float *)&v220[v23];
    *(float *)&work = v26 * v28;
    v32 = v31[2];
    v33 = (float)(v27 * v30) - (float)(v26 * v28);
    v31[6] = v33;
    v34 = (float)(v26 * v29) - (float)(v27 * v32);
    v31[5] = v34;
    v35 = v32 * v28;
    v36 = v33;
    v37 = v35 - (float)(v30 * v29);
    v31[4] = v37;
    v38 = (float)((float)(v25[25] * v37) + (float)(v25[29] * v34)) + (float)(v25[33] * v33);
    v39 = (float)((float)(v25[26] * v37) + (float)(v25[30] * v34)) + (float)(v25[34] * v33);
    v31[4] = (float)((float)(v25[28] * v34) + (float)(v25[24] * v37)) + (float)(v25[32] * v36);
    v31[5] = v38;
    v31[6] = v39;
    *((_DWORD *)v31 + 8) = v226;
    v40 = *(float **)(LODWORD(mcr_1.m_vector.y) + 148);
    v41 = v262 - v40[36];
    v42 = v263 - v40[37];
    v43 = v264 - v40[38];
    v44 = (float *)&v220[v225 + 48];
    v44[1] = perp_axis2_ws.z * -1.0;
    v44[2] = perp_axis2_ws.w * -1.0;
    v45 = v26 * -1.0;
    *v44 = v45;
    v46 = v44[1];
    *(float *)&work = v45 * v42;
    v47 = v45 * v43;
    v48 = v44[2];
    v49 = v46;
    v50 = v46 * v43;
    v44[4] = (float)(v48 * v42) - v50;
    v44[6] = (float)(v49 * v41) - *(float *)&work;
    v51 = (float)(v48 * v42) - v50;
    v52 = v47 - (float)(v48 * v41);
    v44[5] = v52;
    v53 = v44[6];
    v54 = v52;
    v55 = (float)((float)(v40[25] * v51) + (float)(v40[29] * v52)) + (float)(v40[33] * v53);
    v56 = (float)((float)(v40[26] * v51) + (float)(v40[30] * v54)) + (float)(v40[34] * v53);
    v57 = (float)(v40[28] * v54) + (float)(v51 * v40[24]);
    v58 = v40[32];
    v44[5] = v55;
    v44[6] = v56;
    v44[4] = v57 + (float)(v58 * v53);
    *((_DWORD *)v44 + 8) = v226;
    v225 += 48;
    v223.m_n_queries = ++v226;
    v224.m_n_queries = v226;
    hk_Rigid_Body_Core::add_to_mass_matrix_inv(
      this: (hk_Rigid_Body_Core *)v24->physical_core,
      input: &v223,
      matrix_out: &v221,
      velocities_out: &impulses.m_elt_buffer[5]);
    v223.m_n_queries = v226;
    v224.m_n_queries = v226;
    hk_Rigid_Body_Core::add_to_mass_matrix_inv(
      this: *(hk_Rigid_Body_Core **)(LODWORD(mcr_1.m_vector.y) + 148),
      input: &v224,
      matrix_out: &v221,
      velocities_out: &impulses.m_elt_buffer[5]);
    m_elt = v221.m_elt;
    v60 = 0.0;
    v61 = 1.0 / *v221.m_elt;
    if ( *(_BYTE *)(LODWORD(z) + 37) != 0 )
    {
      v62 = v267 - *(float *)(LODWORD(z) + 60);
      v63 = (float)(*(float *)(LODWORD(z) + 56) * pi->delta_time) + *(float *)(LODWORD(z) + 60);
      v64 = impulses.m_elt_buffer[5] * strength_factor;
      v65 = *(float *)(LODWORD(z) + 52);
      *(float *)(LODWORD(z) + 60) = v63;
      v60 = (float)((float)((float)((float)(tau_factor * 0.80000001) * v62) * pi->i_delta_time) - v64) * v61;
      work = (hk_Prismatic_Work *)(LODWORD(v60) & _mask__AbsFloat_);
      if ( (float)(COERCE_FLOAT(LODWORD(v60) & _mask__AbsFloat_) * pi->i_delta_time) > v65 )
      {
        v66 = (float)(v65 / *(float *)&work) * pi->delta_time;
        v60 = v66 * v60;
        *(float *)(LODWORD(z) + 60) = (float)((float)(1.0 - v66) * v62) + v63;
      }
    }
    if ( *(_BYTE *)(LODWORD(z) + 36) != 0 )
    {
      v67 = v267 - (float)((float)((float)(v60 * *m_elt) + impulses.m_elt_buffer[5]) * pi->delta_time);
      v68 = *(float *)(LODWORD(z) + 44);
      if ( v67 > v68 || (v68 = *(float *)(LODWORD(z) + 40)) > v67 )
        v60 = v60
            + (float)((float)((float)((float)((float)(v67 - v68) * tau_factor) * *(float *)(LODWORD(z) + 48))
                            * pi->i_delta_time)
                    * v61);
    }
    if ( v60 != 0.0 )
    {
      v69 = (hk_Rigid_Body_Core *)v24->physical_core;
      v267 = v60;
      hk_Rigid_Body_Core::apply_impulses(this: v69, input: &v223, impulse_strength: &v267);
      hk_Rigid_Body_Core::apply_impulses(
        this: *(hk_Rigid_Body_Core **)(LODWORD(mcr_1.m_vector.y) + 148),
        input: &v224,
        impulse_strength: &v267);
    }
  }
  v70 = LODWORD(mcr_1.m_vector.w) + 48;
  hk_VM_Query_Builder<hk_VMQ_Storage<5>>::begin(
    this: (hk_VM_Query_Builder<hk_VMQ_Storage<5> > *)(LODWORD(mcr_1.m_vector.w) + 48),
    size: 5);
  v71 = *(_DWORD *)(v70 + 872);
  *(_DWORD *)(v71 + v70 + 200) = 0;
  *(_DWORD *)(v71 + v70 + 196) = 0;
  *(_DWORD *)(v71 + v70 + 192) = 0;
  *(float *)(v71 + v70 + 208) = shift_ws_Ros.y;
  *(float *)(v71 + v70 + 212) = shift_ws_Ros.z;
  *(float *)(v71 + v70 + 216) = shift_ws_Ros.w;
  v72 = (float *)v24->physical_core;
  v73 = *(float *)(v71 + v70 + 212);
  v74 = *(float *)(v71 + v70 + 208);
  v75 = *(float *)(v71 + v70 + 216);
  v76 = v71 + v70 + 192;
  v77 = (float)((float)(v72[25] * v74) + (float)(v72[29] * v73)) + (float)(v72[33] * v75);
  v78 = (float)((float)(v72[26] * v74) + (float)(v72[30] * v73)) + (float)(v72[34] * v75);
  v79 = (float)(v72[28] * v73) + (float)(v74 * v72[24]);
  v80 = v72[32];
  *(float *)(v76 + 20) = v77;
  *(float *)(v76 + 24) = v78;
  *(float *)(v76 + 16) = v79 + (float)(v80 * v75);
  *(_DWORD *)(v76 + 32) = *(_DWORD *)(v70 + 876);
  v81 = *(_DWORD *)(v70 + 872);
  *(_DWORD *)(v81 + v70 + 440) = 0;
  *(_DWORD *)(v81 + v70 + 436) = 0;
  *(_DWORD *)(v81 + v70 + 432) = 0;
  v82 = v81 + v70 + 432;
  v83 = mcr_1.m_vector.y;
  *(float *)(v82 + 16) = shift_ws_Ros.y * -1.0;
  *(float *)(v82 + 20) = shift_ws_Ros.z * -1.0;
  *(float *)(v82 + 24) = shift_ws_Ros.w * -1.0;
  v84 = *(float **)(LODWORD(v83) + 148);
  v85 = *(float *)(v82 + 20);
  v86 = *(float *)(v82 + 16);
  v87 = *(float *)(v82 + 24);
  v88 = (float)((float)(v84[25] * v86) + (float)(v84[29] * v85)) + (float)(v84[33] * v87);
  v89 = (float)((float)(v84[26] * v86) + (float)(v84[30] * v85)) + (float)(v84[34] * v87);
  v90 = (float)(v84[28] * v85) + (float)(v86 * v84[24]);
  v91 = v84[32];
  *(float *)(v82 + 20) = v88;
  *(float *)(v82 + 24) = v89;
  *(float *)(v82 + 16) = v90 + (float)(v91 * v87);
  *(_DWORD *)(v82 + 32) = *(_DWORD *)(v70 + 876);
  v92 = *(_DWORD *)(v70 + 872);
  *(_DWORD *)(v92 + v70 + 248) = 0;
  *(_DWORD *)(v92 + v70 + 244) = 0;
  *(_DWORD *)(v92 + v70 + 240) = 0;
  *(float *)(v92 + v70 + 256) = v250;
  *(float *)(v92 + v70 + 260) = v251;
  v93 = v252;
  *(float *)(v92 + v70 + 264) = v252;
  v94 = (float *)v24->physical_core;
  v95 = *(float *)(v92 + v70 + 260);
  v96 = *(float *)(v92 + v70 + 256);
  v97 = v92 + v70 + 240;
  v98 = v93;
  v99 = (float)((float)(v94[25] * v96) + (float)(v94[29] * v95)) + (float)(v94[33] * v93);
  v100 = (float)((float)(v94[26] * v96) + (float)(v94[30] * v95)) + (float)(v94[34] * v98);
  v101 = (float)(v94[28] * v95) + (float)(v94[24] * v96);
  v102 = v94[32];
  *(float *)(v97 + 20) = v99;
  *(float *)(v97 + 24) = v100;
  *(float *)(v97 + 16) = v101 + (float)(v102 * v98);
  *(_DWORD *)(v97 + 32) = *(_DWORD *)(v70 + 876) + 1;
  v103 = *(_DWORD *)(v70 + 872) + v70 + 480;
  *(_DWORD *)(v103 + 8) = 0;
  *(_DWORD *)(v103 + 4) = 0;
  *(_DWORD *)v103 = 0;
  *(float *)(v103 + 16) = v250 * -1.0;
  *(float *)(v103 + 20) = v251 * -1.0;
  v104 = v252 * -1.0;
  *(float *)(v103 + 24) = v252 * -1.0;
  v105 = *(float **)(LODWORD(v83) + 148);
  v106 = *(float *)(v103 + 16);
  v107 = *(float *)(v103 + 20);
  v108 = v104;
  v109 = (float)((float)(v105[25] * v106) + (float)(v105[29] * v107)) + (float)(v105[33] * v104);
  v110 = (float)((float)(v105[26] * v106) + (float)(v105[30] * v107)) + (float)(v105[34] * v108);
  v111 = (float)(v105[28] * v107) + (float)(v105[24] * v106);
  v112 = v105[32];
  *(float *)(v103 + 24) = v110;
  *(float *)(v103 + 20) = v109;
  *(float *)(v103 + 16) = v111 + (float)(v112 * v108);
  *(_DWORD *)(v103 + 32) = *(_DWORD *)(v70 + 876) + 1;
  v113 = *(_DWORD *)(v70 + 872);
  *(_DWORD *)(v113 + v70 + 296) = 0;
  *(_DWORD *)(v113 + v70 + 292) = 0;
  *(_DWORD *)(v113 + v70 + 288) = 0;
  *(float *)(v113 + v70 + 304) = v254;
  *(float *)(v113 + v70 + 308) = v255;
  v114 = v256;
  *(float *)(v113 + v70 + 312) = v256;
  v115 = (float *)v24->physical_core;
  v116 = *(float *)(v113 + v70 + 308);
  v117 = *(float *)(v113 + v70 + 304);
  v118 = v113 + v70 + 288;
  v119 = v114;
  v120 = (float)((float)(v115[25] * v117) + (float)(v115[29] * v116)) + (float)(v115[33] * v114);
  v121 = (float)((float)(v115[26] * v117) + (float)(v115[30] * v116)) + (float)(v115[34] * v119);
  v122 = (float)(v115[28] * v116) + (float)(v115[24] * v117);
  v123 = v115[32];
  *(float *)(v118 + 20) = v120;
  *(float *)(v118 + 24) = v121;
  *(float *)(v118 + 16) = v122 + (float)(v123 * v119);
  *(_DWORD *)(v118 + 32) = *(_DWORD *)(v70 + 876) + 2;
  v124 = *(_DWORD *)(v70 + 872) + v70 + 528;
  *(_DWORD *)(v124 + 8) = 0;
  *(_DWORD *)(v124 + 4) = 0;
  *(_DWORD *)v124 = 0;
  *(float *)(v124 + 16) = v254 * -1.0;
  *(float *)(v124 + 20) = v255 * -1.0;
  *(float *)(v124 + 24) = v256 * -1.0;
  v125 = *(float **)(LODWORD(v83) + 148);
  v126 = *(float *)(v124 + 20);
  v127 = *(float *)(v124 + 16);
  v128 = *(float *)(v124 + 24);
  v129 = (float)((float)(v125[25] * v127) + (float)(v125[29] * v126)) + (float)(v125[33] * v128);
  v130 = (float)((float)(v125[26] * v127) + (float)(v125[30] * v126)) + (float)(v125[34] * v128);
  v131 = v125[28] * v126;
  v132 = v262;
  v133 = v131 + (float)(v127 * v125[24]);
  v134 = v125[32];
  *(float *)(v124 + 20) = v129;
  *(float *)(v124 + 24) = v130;
  v135 = v134 * v128;
  v136 = v263;
  *(float *)(v124 + 16) = v133 + v135;
  v137 = v264;
  *(_DWORD *)(v124 + 32) = *(_DWORD *)(v70 + 876) + 2;
  v138 = (float *)v24->physical_core;
  v139 = v132 - v138[36];
  v140 = v137 - v138[38];
  v141 = v136 - v138[37];
  v142 = *(float **)(LODWORD(v83) + 148);
  perp_axis_ws.y = v142[36];
  perp_axis_ws.z = v142[37];
  v143 = v142[38];
  v144 = v136 - perp_axis_ws.z;
  v145 = *(_DWORD *)(v70 + 872) + v70 + 336;
  v262 = v132 - perp_axis_ws.y;
  *(float *)v145 = axis_ws.y;
  *(float *)(v145 + 4) = axis_ws.z;
  *(float *)(v145 + 8) = axis_ws.w;
  v146 = *(float *)(v145 + 4);
  v263 = v144;
  v147 = *(float *)v145;
  v264 = v137 - v143;
  perp_axis_ws.w = v143;
  *(float *)&b1 = v147 * v141;
  v148 = *(float *)(v145 + 8);
  *(float *)&work = v146;
  *(float *)(v145 + 24) = (float)(v146 * v139) - (float)(v147 * v141);
  *(float *)(v145 + 20) = (float)(v147 * v140) - (float)(v148 * v139);
  v149 = (float)(v148 * v141) - (float)(*(float *)&work * v140);
  *(float *)(v145 + 16) = v149;
  v150 = (float *)v24->physical_core;
  v151 = v149 * v150[24];
  v152 = (float)((float)(v150[25] * v149) + (float)(v150[29] * *(float *)(v145 + 20)))
       + (float)(v150[33] * *(float *)(v145 + 24));
  v153 = v150[30] * *(float *)(v145 + 20);
  v267 = v150[26] * v149;
  v154 = v267 + v153;
  v155 = v150[34] * *(float *)(v145 + 24);
  v267 = v154;
  v156 = v154 + v155;
  v157 = (float)(v150[28] * *(float *)(v145 + 20)) + v151;
  *(float *)&work = v156;
  v158 = v150[32] * *(float *)(v145 + 24);
  *(float *)(v145 + 24) = *(float *)&work;
  *(float *)(v145 + 20) = v152;
  *(float *)(v145 + 16) = v157 + v158;
  *(_DWORD *)(v145 + 32) = *(_DWORD *)(v70 + 876) + 3;
  v159 = *(_DWORD *)(v70 + 872) + v70 + 576;
  *(float *)v159 = axis_ws.y * -1.0;
  *(float *)(v159 + 4) = axis_ws.z * -1.0;
  *(float *)(v159 + 8) = axis_ws.w * -1.0;
  v160 = *(float *)(v159 + 4);
  v161 = *(float *)v159 * v264;
  v267 = *(float *)v159 * v263;
  v162 = *(float *)(v159 + 8);
  *(float *)&b1 = v160;
  v163 = (float)(v160 * v262) - v267;
  *(float *)&work = v162;
  v164 = v161 - (float)(v162 * v262);
  v165 = (float)(v162 * v263) - (float)(*(float *)&b1 * v264);
  *(float *)(v159 + 20) = v164;
  *(float *)(v159 + 24) = v163;
  *(float *)(v159 + 16) = v165;
  v166 = *(float **)(LODWORD(v83) + 148);
  v167 = (float)((float)(v166[25] * v165) + (float)(v166[29] * *(float *)(v159 + 20))) + (float)(v166[33] * v163);
  v168 = (float)((float)(v166[26] * v165) + (float)(v166[30] * *(float *)(v159 + 20)))
       + (float)(v166[34] * *(float *)(v159 + 24));
  v169 = (float)(v166[28] * *(float *)(v159 + 20)) + (float)(v166[24] * *(float *)(v159 + 16));
  v170 = v166[32] * *(float *)(v159 + 24);
  *(float *)(v159 + 20) = v167;
  *(float *)(v159 + 16) = v169 + v170;
  *(float *)(v159 + 24) = v168;
  v171 = v242;
  *(_DWORD *)(v159 + 32) = *(_DWORD *)(v70 + 876) + 3;
  v172 = *(_DWORD *)(v70 + 872);
  *(float *)(v172 + v70 + 384) = v171;
  *(float *)(v172 + v70 + 388) = v243;
  *(float *)(v172 + v70 + 392) = v244;
  v173 = *(float *)(v172 + v70 + 388);
  v174 = v172 + v70 + 384;
  *(float *)&work = v168;
  v175 = *(float *)v174;
  *(float *)&b1 = *(float *)v174 * v141;
  v176 = *(float *)(v174 + 8);
  *(float *)&work = v173;
  *(float *)(v174 + 24) = (float)(v173 * v139) - *(float *)&b1;
  v177 = (float)(v176 * v141) - (float)(*(float *)&work * v140);
  *(float *)(v174 + 16) = v177;
  v178 = (float)(v175 * v140) - (float)(v176 * v139);
  *(float *)(v174 + 20) = v178;
  v179 = (float *)v24->physical_core;
  v180 = v178;
  v181 = *(float *)(v174 + 24);
  v182 = (float)((float)(v179[25] * v177) + (float)(v179[29] * v180)) + (float)(v179[33] * v181);
  v183 = (float)((float)(v179[26] * v177) + (float)(v179[30] * v180)) + (float)(v179[34] * v181);
  v184 = (float)(v179[28] * v180) + (float)(v177 * v179[24]);
  v185 = v179[32];
  *(float *)(v174 + 20) = v182;
  *(float *)(v174 + 24) = v183;
  *(float *)(v174 + 16) = v184 + (float)(v185 * v181);
  v186 = v242 * -1.0;
  *(_DWORD *)(v174 + 32) = *(_DWORD *)(v70 + 876) + 4;
  v187 = *(_DWORD *)(v70 + 872);
  *(float *)(v187 + v70 + 624) = v186;
  v188 = v187 + v70 + 624;
  *(float *)(v188 + 4) = v243 * -1.0;
  *(float *)(v188 + 8) = v244 * -1.0;
  v189 = *(float *)(v188 + 4);
  v190 = *(float *)(v188 + 8);
  v191 = v190 * v263;
  v192 = *(float *)v188 * v263;
  v193 = (float)(*(float *)v188 * v264) - (float)(v190 * v262);
  *(float *)(v188 + 20) = v193;
  v194 = v189 * v262;
  v195 = v191 - (float)(v189 * v264);
  *(float *)(v188 + 16) = v195;
  *(float *)(v188 + 24) = v194 - v192;
  v196 = *(float **)(LODWORD(v83) + 148);
  v197 = *(float *)(v188 + 24);
  v198 = v195;
  v199 = v193;
  v200 = (float)((float)(v196[25] * v195) + (float)(v196[29] * v193)) + (float)(v196[33] * v197);
  v201 = (float)((float)(v196[26] * v195) + (float)(v196[30] * v199)) + (float)(v196[34] * v197);
  v202 = (float)(v196[28] * v199) + (float)(v198 * v196[24]);
  v203 = v196[32];
  *(float *)(v188 + 20) = v200;
  *(float *)(v188 + 24) = v201;
  *(float *)(v188 + 16) = v202 + (float)(v203 * v197);
  *(_DWORD *)(v188 + 32) = *(_DWORD *)(v70 + 876) + 4;
  *(_DWORD *)(v70 + 876) += 5;
  v204 = *(_DWORD *)(v70 + 876);
  *(_DWORD *)(v70 + 872) += 240;
  *(_DWORD *)(v70 + 848) = v204;
  *(_DWORD *)(v70 + 860) = v204;
  LODWORD(v267) = v70 + 848;
  work = (hk_Prismatic_Work *)(v70 + 860);
  v205 = (hk_Rigid_Body_Core *)v24->physical_core;
  b1 = (hk_Rigid_Body *)(v70 + 672);
  hk_Rigid_Body_Core::add_to_mass_matrix_inv(
    this: v205,
    input: (hk_Core_VMQ_Input *)(v70 + 848),
    matrix_out: (hk_Dense_Matrix *)(v70 + 672),
    velocities_out: (float *)v70);
  v206 = *(float **)(v70 + 876);
  v207 = (hk_Core_VMQ_Input *)work;
  v208 = v267;
  work->m_correction.m_elt = v206;
  *(_DWORD *)LODWORD(v208) = v206;
  hk_Rigid_Body_Core::add_to_mass_matrix_inv(
    this: *(hk_Rigid_Body_Core **)(LODWORD(mcr_1.m_vector.y) + 148),
    input: v207,
    matrix_out: (hk_Dense_Matrix *)b1,
    velocities_out: (float *)v70);
  v209 = mcr_1.m_vector.w;
  v210 = (float)(*(float *)(LODWORD(mcr_1.m_vector.z) + 24) * -1.0) * strength_factor;
  v211 = *(float *)(v70 + 16);
  v227[0] = delta_4;
  LODWORD(mcr_1.m_vector.w) = (char *)&v227[1] - LODWORD(mcr_1.m_vector.w);
  v212 = (float)(v211 * v210) + *(float *)(LODWORD(v209) + 32);
  LODWORD(mcr_1.m_vector.z) = 3;
  v213 = (float *)(LODWORD(v209) + 24);
  v214 = (char *)v227 - LODWORD(v209);
  v215 = 3;
  v227[1] = 5;
  v227[2] = 8;
  *(float *)&delta_4[16] = v212;
  do
  {
    *(float *)((char *)v213 + LODWORD(mcr_1.m_vector.w)) = (float)(*(float *)(v70 + 4 * v215) * v210) + v213[1];
    v215 = LODWORD(mcr_1.m_vector.z) - 2;
    *(float *)((char *)v213 + (_DWORD)v214) = (float)(*(float *)(v70 + 4 * LODWORD(mcr_1.m_vector.z) - 4) * v210)
                                            + *v213;
    v213 -= 2;
    LODWORD(mcr_1.m_vector.z) = v215;
  }
  while ( v215 > 0 );
  v216 = b1;
  hk_Dense_Matrix_Util::invert_5x5(m: (hk_Fixed_Dense_Matrix<5> *)b1, tolerance: 0.0);
  v218[0] = (const float *)&impulses.m_size;
  v218[1] = (const float *)5;
  v218[2] = (const float *)8;
  hk_Dense_Matrix_Util::mult(
    m: (const hk_Dense_Matrix *)v216,
    in: (const hk_Dense_Vector *)v227,
    out: (hk_Dense_Vector *)v218);
  hk_Rigid_Body_Core::apply_impulses(
    this: (hk_Rigid_Body_Core *)v24->physical_core,
    input: (hk_Core_VMQ_Input *)LODWORD(v267),
    impulse_strength: v218[0]);
  hk_Rigid_Body_Core::apply_impulses(
    this: *(hk_Rigid_Body_Core **)(LODWORD(mcr_1.m_vector.y) + 148),
    input: (hk_Core_VMQ_Input *)work,
    impulse_strength: v218[0]);
  return 928;
}
