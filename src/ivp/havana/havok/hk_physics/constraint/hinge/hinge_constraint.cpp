// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/havana/havok/hk_physics/constraint/hinge/hinge_constraint.cpp
// Functions: 10
// ============================================================

#include "ivp\havana\havok\hk_physics\constraint\hinge\hinge_constraint.h"

//------------------------------------------------------------------------------
// Address: 0x1003BD50
// Name: public: void hk_Hinge_Constraint::write_to_blueprint(class hk_Hinge_BP __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Hinge_Constraint::write_to_blueprint(hk_Hinge_Constraint *this, hk_Hinge_BP *pOutBP)
{
  pOutBP->m_tau = this->m_tau;
  pOutBP->m_strength = this->m_strength;
  pOutBP->m_axis_os[0].m_origin.x = this->m_axis_os[0].m_origin.x;
  pOutBP->m_axis_os[0].m_origin.y = this->m_axis_os[0].m_origin.y;
  pOutBP->m_axis_os[0].m_origin.z = this->m_axis_os[0].m_origin.z;
  pOutBP->m_axis_os[0].m_direction.x = this->m_axis_os[0].m_direction.x;
  pOutBP->m_axis_os[0].m_direction.y = this->m_axis_os[0].m_direction.y;
  pOutBP->m_axis_os[0].m_direction.z = this->m_axis_os[0].m_direction.z;
  pOutBP->m_axis_perp_os[0].x = this->m_axis_perp_os[0].x;
  pOutBP->m_axis_perp_os[0].y = this->m_axis_perp_os[0].y;
  pOutBP->m_axis_perp_os[0].z = this->m_axis_perp_os[0].z;
  pOutBP->m_axis_os[1].m_origin.x = this->m_axis_os[1].m_origin.x;
  pOutBP->m_axis_os[1].m_origin.y = this->m_axis_os[1].m_origin.y;
  pOutBP->m_axis_os[1].m_origin.z = this->m_axis_os[1].m_origin.z;
  pOutBP->m_axis_os[1].m_direction.x = this->m_axis_os[1].m_direction.x;
  pOutBP->m_axis_os[1].m_direction.y = this->m_axis_os[1].m_direction.y;
  pOutBP->m_axis_os[1].m_direction.z = this->m_axis_os[1].m_direction.z;
  pOutBP->m_axis_perp_os[1].x = this->m_axis_perp_os[1].x;
  pOutBP->m_axis_perp_os[1].y = this->m_axis_perp_os[1].y;
  pOutBP->m_axis_perp_os[1].z = this->m_axis_perp_os[1].z;
  pOutBP->m_limit = this->m_limit.hk_Constraint_Limit_BP;
}

//------------------------------------------------------------------------------
// Address: 0x1003BE00
// Name: public: virtual int hk_Hinge_Constraint::get_vmq_storage_size(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall hk_Hinge_Constraint::get_vmq_storage_size(hk_Hinge_Constraint *this)
{
  return 976;
}

//------------------------------------------------------------------------------
// Address: 0x1003BE10
// Name: public: void hk_Hinge_Constraint::set_motor(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Hinge_Constraint::set_motor(hk_Hinge_Constraint *this, float desired_vel, float max_force)
{
  this->m_limit.m_friction_is_enabled = max_force != 0.0;
  LODWORD(this->m_limit.m_joint_friction) = LODWORD(max_force) & _mask__AbsFloat_;
  this->m_limit.m_desired_velocity = desired_vel;
}

//------------------------------------------------------------------------------
// Address: 0x1003BE60
// Name: protected: void hk_Hinge_Constraint::init_hinge_constraint(class hk_Hinge_BP const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge hk_Hinge_Constraint::init_hinge_constraint(
        hk_Hinge_Constraint *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const hk_Hinge_BP *bp)
{
  hk_Hinge_Constraint *v5; // esi
  const hk_Hinge_BP *v6; // edi
  double m_tau; // st7
  hk_Rigid_Body *v8; // eax
  bool v9; // zf
  hk_Rigid_Body *v10; // edx
  IVP_Core *physical_core; // eax
  float v12; // xmm0_4
  IVP_Core *v13; // eax
  float v14; // xmm0_4
  hk_Hinge_Constraint *v15; // ecx
  int v16; // edx
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  float *v20; // edx
  float *p_x; // ecx
  float v22; // xmm2_4
  float v23; // xmm1_4
  float v24; // xmm3_4
  float v25; // xmm0_4
  float v26; // xmm0_4
  hk_Vector3 *v27; // eax
  float v28; // xmm0_4
  float m_ref_position; // xmm2_4
  float v30; // xmm2_4
  long double v31; // [esp-2Ch] [ebp-15Ch]
  long double v32; // [esp-24h] [ebp-154h]
  hk_Vector3 v33; // [esp-1Ch] [ebp-14Ch] BYREF
  float v34[3]; // [esp-Ch] [ebp-13Ch] BYREF
  hk_Vector3 line_ws[2]; // [esp+0h] [ebp-130h] BYREF
  hk_Vector3 perp_x2_ws; // [esp+20h] [ebp-110h] BYREF
  _BYTE perp_x_ws_4[64]; // [esp+34h] [ebp-FCh] OVERLAPPED BYREF
  hk_Rigid_Body *v38; // [esp+80h] [ebp-B0h]
  float v39; // [esp+84h] [ebp-ACh] BYREF
  float v40; // [esp+88h] [ebp-A8h]
  hk_Rigid_Body *b1; // [esp+8Ch] [ebp-A4h]
  hk_Vector3 axis_perp_ws; // [esp+90h] [ebp-A0h] BYREF
  int v43; // [esp+A0h] [ebp-90h]
  float v44; // [esp+A4h] [ebp-8Ch]
  float v45; // [esp+A8h] [ebp-88h]
  float v46; // [esp+ACh] [ebp-84h]
  int v47; // [esp+B0h] [ebp-80h]
  float v48; // [esp+B4h] [ebp-7Ch]
  float v49; // [esp+B8h] [ebp-78h]
  float v50; // [esp+BCh] [ebp-74h]
  int v51; // [esp+C0h] [ebp-70h]
  float v52; // [esp+C4h] [ebp-6Ch]
  float v53; // [esp+C8h] [ebp-68h]
  float v54; // [esp+CCh] [ebp-64h]
  int v55; // [esp+D0h] [ebp-60h]
  hk_Rotation v56; // [esp+D4h] [ebp-5Ch] BYREF
  float v57; // [esp+104h] [ebp-2Ch]
  float v58; // [esp+108h] [ebp-28h]
  float v59; // [esp+10Ch] [ebp-24h]
  int v60; // [esp+110h] [ebp-20h]
  hk_Hinge_Constraint *i; // [esp+120h] [ebp-10h]
  int v62; // [esp+124h] [ebp-Ch]
  void *v63; // [esp+128h] [ebp-8h]
  void *retaddr; // [esp+130h] [ebp+0h]

  v62 = a2;
  v63 = retaddr;
  HIDWORD(v31) = a4;
  v5 = this;
  LODWORD(v31) = a3;
  v6 = bp;
  m_tau = bp->m_tau;
  i = this;
  this->m_tau = m_tau;
  this->m_strength = bp->m_strength;
  this->m_axis_os[0].m_origin.x = bp->m_axis_os[0].m_origin.x;
  this->m_axis_os[0].m_origin.y = bp->m_axis_os[0].m_origin.y;
  this->m_axis_os[0].m_origin.z = bp->m_axis_os[0].m_origin.z;
  this->m_axis_os[0].m_direction.x = bp->m_axis_os[0].m_direction.x;
  this->m_axis_os[0].m_direction.y = bp->m_axis_os[0].m_direction.y;
  this->m_axis_os[0].m_direction.z = bp->m_axis_os[0].m_direction.z;
  this->m_axis_os[1].m_origin.x = bp->m_axis_os[1].m_origin.x;
  this->m_axis_os[1].m_origin.y = bp->m_axis_os[1].m_origin.y;
  this->m_axis_os[1].m_origin.z = bp->m_axis_os[1].m_origin.z;
  this->m_axis_os[1].m_direction.x = bp->m_axis_os[1].m_direction.x;
  this->m_axis_os[1].m_direction.y = bp->m_axis_os[1].m_direction.y;
  this->m_axis_os[1].m_direction.z = bp->m_axis_os[1].m_direction.z;
  this->m_limit.hk_Constraint_Limit_BP = bp->m_limit;
  v8 = this->m_entities[0];
  v9 = (*(_DWORD *)&v8->flags & 0x800) == 0;
  v10 = this->m_entities[1];
  v38 = v10;
  if ( v9 )
  {
    qmemcpy(perp_x_ws_4, &v8->physical_core->m_world_f_core_last_psi, sizeof(perp_x_ws_4));
    IVP_U_Matrix::vmult4(
      this: (IVP_U_Matrix *)perp_x_ws_4,
      p_in: &v8->shift_core_f_object,
      p_out: (IVP_U_Float_Point *)&perp_x_ws_4[48]);
    v5 = i;
    v10 = v38;
    v6 = bp;
    axis_perp_ws.y = *(float *)perp_x_ws_4;
    axis_perp_ws.z = *(float *)&perp_x_ws_4[16];
    axis_perp_ws.w = *(float *)&perp_x_ws_4[32];
    v44 = *(float *)&perp_x_ws_4[4];
    v45 = *(float *)&perp_x_ws_4[20];
    v46 = *(float *)&perp_x_ws_4[36];
    v48 = *(float *)&perp_x_ws_4[8];
    v49 = *(float *)&perp_x_ws_4[24];
    v50 = *(float *)&perp_x_ws_4[40];
    v52 = *(float *)&perp_x_ws_4[48];
    v53 = *(float *)&perp_x_ws_4[52];
    v12 = *(float *)&perp_x_ws_4[56];
    v43 = 0;
    v47 = 0;
    v51 = 0;
  }
  else
  {
    physical_core = v8->physical_core;
    axis_perp_ws.y = physical_core->m_world_f_core_last_psi.rows[0].k[0];
    axis_perp_ws.z = physical_core->m_world_f_core_last_psi.rows[1].k[0];
    axis_perp_ws.w = physical_core->m_world_f_core_last_psi.rows[2].k[0];
    v43 = 0;
    v44 = physical_core->m_world_f_core_last_psi.rows[0].k[1];
    v45 = physical_core->m_world_f_core_last_psi.rows[1].k[1];
    v46 = physical_core->m_world_f_core_last_psi.rows[2].k[1];
    v47 = 0;
    v48 = physical_core->m_world_f_core_last_psi.rows[0].k[2];
    v49 = physical_core->m_world_f_core_last_psi.rows[1].k[2];
    v50 = physical_core->m_world_f_core_last_psi.rows[2].k[2];
    v51 = 0;
    v52 = physical_core->m_world_f_core_last_psi.vv.k[0];
    v53 = physical_core->m_world_f_core_last_psi.vv.k[1];
    v12 = physical_core->m_world_f_core_last_psi.vv.k[2];
  }
  v55 = 1065353216;
  v54 = v12;
  if ( (*(_DWORD *)&v10->flags & 0x800) != 0 )
  {
    v13 = v10->physical_core;
    v56.m_elems[0] = v13->m_world_f_core_last_psi.rows[0].k[0];
    v56.m_elems[1] = v13->m_world_f_core_last_psi.rows[1].k[0];
    v56.m_elems[2] = v13->m_world_f_core_last_psi.rows[2].k[0];
    v56.m_elems[3] = 0.0;
    v56.m_elems[4] = v13->m_world_f_core_last_psi.rows[0].k[1];
    v56.m_elems[5] = v13->m_world_f_core_last_psi.rows[1].k[1];
    v56.m_elems[6] = v13->m_world_f_core_last_psi.rows[2].k[1];
    v56.m_elems[7] = 0.0;
    v56.m_elems[8] = v13->m_world_f_core_last_psi.rows[0].k[2];
    v56.m_elems[9] = v13->m_world_f_core_last_psi.rows[1].k[2];
    v56.m_elems[10] = v13->m_world_f_core_last_psi.rows[2].k[2];
    v56.m_elems[11] = 0.0;
    v57 = v13->m_world_f_core_last_psi.vv.k[0];
    v58 = v13->m_world_f_core_last_psi.vv.k[1];
    v14 = v13->m_world_f_core_last_psi.vv.k[2];
    v15 = nullptr;
    v60 = 1065353216;
    v59 = v14;
  }
  else
  {
    qmemcpy(perp_x_ws_4, &v10->physical_core->m_world_f_core_last_psi, sizeof(perp_x_ws_4));
    IVP_U_Matrix::vmult4(
      this: (IVP_U_Matrix *)perp_x_ws_4,
      p_in: &v10->shift_core_f_object,
      p_out: (IVP_U_Float_Point *)&perp_x_ws_4[48]);
    v5 = i;
    v56.m_elems[0] = *(float *)perp_x_ws_4;
    v6 = bp;
    v56.m_elems[1] = *(float *)&perp_x_ws_4[16];
    v56.m_elems[2] = *(float *)&perp_x_ws_4[32];
    v56.m_elems[4] = *(float *)&perp_x_ws_4[4];
    v56.m_elems[5] = *(float *)&perp_x_ws_4[20];
    v56.m_elems[6] = *(float *)&perp_x_ws_4[36];
    v56.m_elems[8] = *(float *)&perp_x_ws_4[8];
    v56.m_elems[9] = *(float *)&perp_x_ws_4[24];
    v56.m_elems[10] = *(float *)&perp_x_ws_4[40];
    v57 = *(float *)&perp_x_ws_4[48];
    v58 = *(float *)&perp_x_ws_4[52];
    v15 = nullptr;
    v56.m_elems[3] = 0.0;
    v56.m_elems[7] = 0.0;
    v56.m_elems[11] = 0.0;
    v60 = 1065353216;
    v59 = *(float *)&perp_x_ws_4[56];
  }
  for ( i = nullptr; ; v15 = i )
  {
    v16 = 16 * ((_DWORD)v15->m_entities + 2);
    v17 = *(float *)((char *)&v6->m_tau + v16);
    v18 = *(float *)((char *)&v6->m_strength + v16);
    v19 = *(float *)(&v6->m_limit.m_limit_is_enabled + v16);
    v20 = (float *)((char *)&v6->m_tau + v16);
    if ( fsqrt((float)((float)(v17 * v17) + (float)(v18 * v18)) + (float)(v19 * v19)) == 0.0 )
    {
      if ( v15 != nullptr )
      {
        hk_Vector3::set_rotated_dir(
          this: (hk_Vector3 *)&v39,
          t: (const hk_Rotation *)&axis_perp_ws.y,
          v: v5->m_axis_perp_os);
        hk_Vector3::set_rotated_inv_dir(this: &v5->m_axis_perp_os[(_DWORD)i], t: &v56, v: (const hk_Vector3 *)&v39);
      }
      else
      {
        v27 = hk_Vector3_Util::perp_vec(result: &v33, dir: &v5->m_axis_os[0].m_direction);
        v5->m_axis_perp_os[0].x = v27->x;
        v5->m_axis_perp_os[0].y = v27->y;
        v5->m_axis_perp_os[0].z = v27->z;
      }
    }
    else
    {
      p_x = &v5->m_axis_perp_os[(_DWORD)v15].x;
      *p_x = v17;
      p_x[1] = v20[1];
      v22 = v17;
      p_x[2] = v20[2];
      v23 = p_x[1];
      v24 = p_x[2];
      v25 = (float)((float)(v17 * v17) + (float)(v23 * v23)) + (float)(v24 * v24);
      v26 = v25 == 0.0 ? 0.0 : 1.0 / fsqrt(v25);
      *p_x = v22 * v26;
      p_x[1] = v23 * v26;
      p_x[2] = v24 * v26;
    }
    i = (hk_Hinge_Constraint *)((char *)i + 1);
    if ( (int)i >= 2 )
      break;
  }
  hk_Vector3::set_rotated_dir(
    this: (hk_Vector3 *)v34,
    t: (const hk_Rotation *)&axis_perp_ws.y,
    v: &v5->m_axis_os[0].m_direction);
  hk_Vector3::set_rotated_dir(this: (hk_Vector3 *)&line_ws[0].y, t: &v56, v: &v5->m_axis_os[1].m_direction);
  hk_Vector3::set_rotated_dir(
    this: (hk_Vector3 *)&perp_x2_ws.y,
    t: (const hk_Rotation *)&axis_perp_ws.y,
    v: v5->m_axis_perp_os);
  v39 = (float)(v34[2] * perp_x2_ws.z) - (float)(v34[1] * perp_x2_ws.w);
  v40 = (float)(v34[0] * perp_x2_ws.w) - (float)(v34[2] * perp_x2_ws.y);
  *(float *)&b1 = (float)(v34[1] * perp_x2_ws.y) - (float)(v34[0] * perp_x2_ws.z);
  hk_Vector3::set_rotated_dir(this: (hk_Vector3 *)&line_ws[1].y, t: &v56, v: &v5->m_axis_perp_os[1]);
  v28 = (float)((float)(line_ws[1].z * v40) + (float)(line_ws[1].y * v39)) + (float)(line_ws[1].w * *(float *)&b1);
  __libm_sse2_atan2(y: v31, x: v32);
  if ( v28 < 0.0 )
  {
    m_ref_position = v5->m_limit.m_ref_position;
    if ( m_ref_position > 0.0 && (float)(m_ref_position - v28) > 3.1415927 )
      v5->m_limit.m_ref_position = v28 + 6.2831855;
  }
  if ( v28 > 0.0 )
  {
    v30 = v5->m_limit.m_ref_position;
    if ( v30 < 0.0 && (float)(v28 - v30) > 3.1415927 )
      v5->m_limit.m_ref_position = v28 - 6.2831855;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003C560
// Name: public: virtual void hk_Hinge_Constraint::step_constraint(class hk_PSI_Info __near &,void __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Hinge_Constraint::step_constraint(
        hk_Hinge_Constraint *this,
        hk_PSI_Info *pi,
        __m128 **mem,
        float tau_factor,
        float strength_factor)
{
  hk_Rigid_Body *v5; // eax
  hk_Rigid_Body *v6; // edx
  __m128 v7; // xmm1
  float v8; // xmm0_4
  float *physical_core; // ecx
  __m128 v10; // xmm2
  float *v11; // edx
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  float *v14; // eax
  int v15; // edi
  float v16; // xmm0_4
  bool v17; // sf
  float *v18; // ecx
  float *v19; // edi
  float *v20; // eax
  int v21; // edx
  float v22; // xmm0_4
  __m128 v23; // xmm0
  __m128 *v24; // eax
  __m128 v25; // xmm3
  __m128 v26; // xmm4
  __m128 v27; // xmm1
  __m128 v28; // xmm2
  int v29; // ecx
  __m128 v30; // xmm5
  __m128 v31; // xmm6
  char *v32; // eax
  __m128 v33; // xmm7
  __m128 v34; // xmm4
  __m128 *v35; // eax
  __m128 v36; // xmm6
  __m128 v37; // xmm5
  __m128 v38; // xmm4
  __m128 v39; // xmm7
  __m128 *v40; // eax
  __m128 v41; // xmm2
  __m128 v42; // xmm6
  __m128 v43; // xmm7
  __m128 v44; // xmm4
  __m128 *v45; // eax
  __m128 v46; // xmm3
  __m128 v47; // [esp-1Ch] [ebp-3Ch]
  __m128 v48; // [esp-Ch] [ebp-2Ch]
  hk_Rigid_Body *scaleW_8; // [esp+8h] [ebp-18h]
  hk_Rigid_Body *scaleW_12; // [esp+Ch] [ebp-14h]
  int v51; // [esp+10h] [ebp-10h]
  int v52; // [esp+10h] [ebp-10h]

  v5 = this->m_entities[0];
  v6 = this->m_entities[1];
  v7 = 0;
  v7.m128_f32[0] = this->m_tau * tau_factor;
  v8 = (float)(this->m_strength * -1.0) * strength_factor;
  physical_core = (float *)v5->physical_core;
  v10 = 0;
  v10.m128_f32[0] = v8;
  scaleW_8 = v5;
  *((_QWORD *)mem + 13) = 0;
  *((_QWORD *)mem + 12) = 0;
  *((_QWORD *)mem + 15) = 0;
  *((_QWORD *)mem + 14) = 0;
  scaleW_12 = v6;
  v11 = (float *)mem[237];
  v51 = (int)&mem[236][-1].m128_i32[3] + 3;
  v12 = _mm_shuffle_ps(v7, v7, 0);
  v13 = _mm_shuffle_ps(v10, v10, 0);
  v14 = v11 + 6;
  do
  {
    v15 = *((_DWORD *)v14 + 2);
    v16 = (float)((float)((float)((float)(*(v14 - 1) * physical_core[49]) + (float)(*(v14 - 2) * physical_core[48]))
                        + (float)(physical_core[50] * *v14))
                + (float)((float)((float)(*(v14 - 5) * physical_core[53]) + (float)(*v11 * physical_core[52]))
                        + (float)(*(v14 - 4) * physical_core[54])))
        + *(float *)&mem[v15 + 24];
    v11 += 12;
    v14 += 12;
    v17 = --v51 < 0;
    *(float *)&mem[v15 + 24] = v16;
  }
  while ( !v17 );
  v18 = (float *)scaleW_12->physical_core;
  v19 = (float *)mem[240];
  v52 = (int)&mem[239][-1].m128_i32[3] + 3;
  v20 = v19 + 6;
  do
  {
    v21 = *((_DWORD *)v20 + 2);
    v22 = (float)((float)((float)((float)(*(v20 - 5) * v18[53]) + (float)(*v19 * v18[52]))
                        + (float)(*(v20 - 4) * v18[54]))
                + (float)((float)((float)(*(v20 - 2) * v18[48]) + (float)(*(v20 - 1) * v18[49]))
                        + (float)(v18[50] * *v20)))
        + *(float *)&mem[v21 + 24];
    v19 += 12;
    v20 += 12;
    v17 = --v52 < 0;
    *(float *)&mem[v21 + 24] = v22;
  }
  while ( !v17 );
  v23 = _mm_add_ps(_mm_mul_ps(*((__m128 *)mem + 6), v13), _mm_mul_ps(**mem, v12));
  v24 = mem[192];
  v25 = _mm_add_ps(_mm_mul_ps((*mem)[1], v12), _mm_mul_ps(*((__m128 *)mem + 7), v13));
  v26 = _mm_shuffle_ps(v23, v23, 0);
  v27 = _mm_add_ps(_mm_mul_ps(*v24, v26), Four_Zeros);
  v28 = _mm_add_ps(_mm_mul_ps(v24[1], v26), Four_Zeros);
  v29 = 4 * (_DWORD)mem[195];
  v30 = *(__m128 *)((char *)v24 + v29);
  v31 = *(__m128 *)((char *)v24 + v29 + 16);
  v32 = (char *)v24 + v29;
  v33 = *(__m128 *)&v32[v29];
  v34 = _mm_shuffle_ps(v23, v23, 85);
  v35 = (__m128 *)&v32[v29];
  v36 = _mm_mul_ps(v31, v34);
  v37 = _mm_mul_ps(v30, v34);
  v38 = _mm_shuffle_ps(v23, v23, 170);
  v47 = _mm_mul_ps(v33, v38);
  v39 = v35[1];
  v40 = (__m128 *)((char *)v35 + v29);
  v41 = _mm_add_ps(v28, v36);
  v42 = v40[1];
  v43 = _mm_mul_ps(v39, v38);
  v44 = *v40;
  v45 = (__m128 *)((char *)v40 + v29);
  v48 = _mm_shuffle_ps(v23, v23, 255);
  v46 = _mm_shuffle_ps(v25, v25, 0);
  *mem[12] = _mm_add_ps(_mm_add_ps(_mm_add_ps(_mm_add_ps(v27, v37), v47), _mm_mul_ps(v44, v48)), _mm_mul_ps(*v45, v46));
  mem[12][1] = _mm_add_ps(_mm_mul_ps(v45[1], v46), _mm_add_ps(_mm_add_ps(v41, v43), _mm_mul_ps(v42, v48)));
  hk_Rigid_Body_Core::apply_impulses(
    this: (hk_Rigid_Body_Core *)scaleW_8->physical_core,
    input: (hk_Core_VMQ_Input *)(mem + 236),
    impulse_strength: mem[12]->m128_f32);
  hk_Rigid_Body_Core::apply_impulses(
    this: (hk_Rigid_Body_Core *)scaleW_12->physical_core,
    input: (hk_Core_VMQ_Input *)(mem + 239),
    impulse_strength: mem[12]->m128_f32);
}

//------------------------------------------------------------------------------
// Address: 0x1003C830
// Name: public: virtual void hk_Hinge_Constraint::init_constraint(void const __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge hk_Hinge_Constraint::init_constraint(
        hk_Hinge_Constraint *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        const hk_Hinge_BP *vbp)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  hk_Hinge_Constraint::init_hinge_constraint(this, a2: (int)&savedregs, a3: a2, a4: a3, bp: vbp);
}

//------------------------------------------------------------------------------
// Address: 0x1003C840
// Name: public: hk_Hinge_Constraint::hk_Hinge_Constraint(class hk_Environment __near *,class hk_Hinge_BP const __near *,class hk_Rigid_Body __near *,class hk_Rigid_Body __near *)
// Source: json
//------------------------------------------------------------------------------
hk_Hinge_Constraint *__userpurge hk_Hinge_Constraint::hk_Hinge_Constraint@<eax>(
        hk_Hinge_Constraint *this@<ecx>,
        int a2@<edi>,
        hk_Environment *env,
        const hk_Hinge_BP *bp,
        hk_Rigid_Body *a,
        hk_Rigid_Body *b)
{
  hk_Rigid_Body_Binary_EF::hk_Rigid_Body_Binary_EF(this, env, a, b, __formal: IVP_CP_CONSTRAINTS);
  this->__vftable = (hk_Hinge_Constraint_vtbl *)&hk_Hinge_Constraint::`vftable';
  this->m_constraint_system = nullptr;
  this->m_client_data = nullptr;
  *(_WORD *)&this->m_limit.m_limit_is_enabled = 0;
  this->m_limit.m_limit_min = 0.0;
  this->m_limit.m_limit_max = 0.0;
  this->m_limit.m_limit_tau = 1.0;
  this->m_limit.m_joint_friction = 0.0;
  this->m_limit.m_desired_velocity = 0.0;
  this->m_limit.m_ref_position = 0.0;
  hk_Hinge_Constraint::init_constraint(this, a2, a3: (int)this, vbp: bp);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003C8C0
// Name: public: virtual char const __near * hk_Hinge_Constraint::get_constraint_type(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall hk_Hinge_Constraint::get_constraint_type(hk_Hinge_Constraint *this)
{
  return "hinge";
}

//------------------------------------------------------------------------------
// Address: 0x1003C8D0
// Name: public: hk_Hinge_Constraint::hk_Hinge_Constraint(class hk_Local_Constraint_System __near *,class hk_Hinge_BP const __near *,class hk_Rigid_Body __near *,class hk_Rigid_Body __near *)
// Source: json
//------------------------------------------------------------------------------
hk_Hinge_Constraint *__userpurge hk_Hinge_Constraint::hk_Hinge_Constraint@<eax>(
        hk_Hinge_Constraint *this@<ecx>,
        int a2@<edi>,
        hk_Local_Constraint_System *constraint_system,
        const hk_Hinge_BP *bp,
        hk_Rigid_Body *a,
        hk_Rigid_Body *b)
{
  hk_Constraint::hk_Constraint(
    this,
    sys: constraint_system,
    a,
    b,
    redundend_prio: IVP_CP_CONSTRAINTS,
    storage_size: 976);
  this->__vftable = (hk_Hinge_Constraint_vtbl *)&hk_Hinge_Constraint::`vftable';
  *(_WORD *)&this->m_limit.m_limit_is_enabled = 0;
  this->m_limit.m_limit_min = 0.0;
  this->m_limit.m_limit_max = 0.0;
  this->m_limit.m_limit_tau = 1.0;
  this->m_limit.m_joint_friction = 0.0;
  this->m_limit.m_desired_velocity = 0.0;
  this->m_limit.m_ref_position = 0.0;
  hk_Hinge_Constraint::init_constraint(this, a2, a3: (int)this, vbp: bp);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003C950
// Name: public: virtual int hk_Hinge_Constraint::setup_and_step_constraint(class hk_PSI_Info __near &,void __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __userpurge hk_Hinge_Constraint::setup_and_step_constraint@<eax>(
        hk_Hinge_Constraint *this@<ecx>,
        hk_Rigid_Body *a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        hk_PSI_Info *pi,
        _DWORD *mem,
        unsigned __int64 tau_factor)
{
  hk_Hinge_Constraint *v7; // esi
  hk_Rigid_Body *v8; // eax
  bool v9; // zf
  float w; // edx
  IVP_Core *physical_core; // eax
  float v12; // xmm1_4
  int v13; // eax
  double v14; // xmm0_8
  hk_Hinge_Constraint_Work *v15; // edi
  __m128 *v16; // eax
  __m128 *v17; // ecx
  __int16 v18; // dx
  __m128 v19; // xmm1
  __m128 v20; // xmm0
  __m128 v21; // xmm1
  __m128 v22; // xmm5
  __m128 v23; // xmm3
  __m128 v24; // xmm0
  __m128 v25; // xmm7
  __m128 v26; // xmm2
  __m128 v27; // xmm4
  __m128 v28; // xmm7
  __m128 v29; // xmm4
  __m128 v30; // xmm3
  __m128 v31; // xmm2
  __m128 v32; // xmm6
  __m128 v33; // xmm0
  __int128 m_desired_velocity_low; // xmm2
  const unsigned int *v35; // edx
  __int128 v36; // xmm0
  __int128 delta_time_low; // xmm2
  __m128 m_ref_position_low; // xmm0
  __m128 i_delta_time_low; // xmm2
  __m128 v40; // xmm0
  __m128 v41; // xmm3
  __m128 v42; // xmm0
  __m128 v43; // xmm3
  __m128 v44; // xmm5
  __m128 v45; // xmm5
  __m128 v46; // xmm5
  __m128 v47; // xmm0
  __m128 v48; // xmm1
  __m128 v49; // xmm1
  __m128 v50; // xmm2
  __m128 v51; // xmm2
  __m128 v52; // xmm0
  __m128 v53; // xmm4
  __m128 v54; // xmm3
  __m128 v55; // xmm3
  __m128 v56; // xmm0
  int v57; // esi
  float *v58; // eax
  float v59; // xmm2_4
  float v60; // xmm1_4
  float v61; // xmm3_4
  float v62; // edx
  float *v63; // eax
  float v64; // xmm4_4
  float v65; // xmm0_4
  int v66; // eax
  float v67; // xmm1_4
  float *v68; // ecx
  float v69; // xmm5_4
  float v70; // xmm6_4
  float v71; // xmm7_4
  int v72; // eax
  float v73; // xmm5_4
  float *v74; // ecx
  float v75; // xmm7_4
  float v76; // xmm6_4
  float v77; // xmm7_4
  float v78; // xmm5_4
  float v79; // xmm6_4
  float v80; // xmm7_4
  float v81; // xmm6_4
  float v82; // xmm7_4
  float v83; // xmm6_4
  int v84; // eax
  float v85; // xmm3_4
  int v86; // eax
  float *v87; // ecx
  float v88; // xmm5_4
  float v89; // xmm7_4
  float v90; // xmm6_4
  float v91; // xmm3_4
  float v92; // xmm6_4
  float v93; // xmm7_4
  float v94; // xmm6_4
  float v95; // xmm7_4
  int v96; // xmm3_4
  int v97; // eax
  int v98; // eax
  float *v99; // ecx
  float v100; // xmm3_4
  float v101; // xmm5_4
  float v102; // xmm6_4
  float v103; // xmm3_4
  float v104; // xmm7_4
  float v105; // xmm6_4
  float v106; // xmm7_4
  float v107; // xmm6_4
  float v108; // xmm7_4
  float v109; // xmm6_4
  int v110; // eax
  float v111; // xmm3_4
  float *v112; // eax
  float *v113; // ecx
  float v114; // xmm2_4
  float v115; // xmm6_4
  float v116; // xmm5_4
  float v117; // xmm7_4
  float v118; // xmm7_4
  float v119; // xmm2_4
  int v120; // eax
  int v121; // eax
  float *v122; // ecx
  float v123; // xmm5_4
  float v124; // xmm3_4
  float v125; // xmm7_4
  float v126; // xmm4_4
  int v127; // eax
  int v128; // eax
  float v129; // xmm2_4
  float *v130; // ecx
  float v131; // xmm4_4
  float v132; // xmm5_4
  float v133; // xmm6_4
  float v134; // xmm2_4
  float v135; // xmm3_4
  float v136; // xmm7_4
  float v137; // xmm4_4
  int v138; // eax
  int v139; // eax
  float v140; // xmm2_4
  float *v141; // ecx
  float v142; // xmm4_4
  float v143; // xmm5_4
  float v144; // xmm6_4
  float v145; // xmm2_4
  float v146; // xmm3_4
  float v147; // xmm7_4
  float v148; // xmm4_4
  float v149; // xmm2_4
  int v150; // eax
  float *v151; // ecx
  float v152; // xmm5_4
  float v153; // xmm2_4
  float v154; // xmm6_4
  float v155; // xmm3_4
  float v156; // xmm4_4
  float v157; // xmm7_4
  float v158; // xmm2_4
  int v159; // eax
  int v160; // eax
  float v161; // xmm0_4
  float *v162; // ecx
  float v163; // xmm2_4
  float v164; // xmm3_4
  float v165; // xmm4_4
  float v166; // xmm0_4
  float v167; // xmm1_4
  int v168; // ecx
  hk_Rigid_Body_Core *v169; // ecx
  int v170; // eax
  hk_Core_VMQ_Input *v171; // ecx
  float y; // edx
  float v173; // xmm2_4
  __m128 v174; // xmm1
  int v175; // eax
  __m128 v176; // xmm1
  __m128 v177; // xmm0
  float v178; // xmm3_4
  float z; // ecx
  float *m_elt; // eax
  __m128 *v181; // edx
  __m128 v182; // xmm0
  __m128 v183; // xmm3
  __m128 v184; // xmm4
  __m128 v185; // xmm1
  __m128 v186; // xmm2
  __m128 v187; // xmm4
  __m128 v188; // xmm6
  __m128 v189; // xmm5
  __m128 v190; // xmm4
  __m128 v191; // xmm7
  __m128 v192; // xmm2
  __m128 v193; // xmm6
  __m128 v194; // xmm3
  long double v196; // [esp+4h] [ebp-23Ch]
  long double v197; // [esp+Ch] [ebp-234h]
  __m128 m_joint_friction_low; // [esp+14h] [ebp-22Ch]
  __m128 v199; // [esp+24h] [ebp-21Ch]
  __m128 v200; // [esp+34h] [ebp-20Ch]
  float v201[3]; // [esp+44h] [ebp-1FCh] BYREF
  _BYTE query_20[140]; // [esp+74h] [ebp-1CCh] OVERLAPPED BYREF
  _BYTE orig_ws_4[60]; // [esp+104h] [ebp-13Ch] OVERLAPPED BYREF
  int v204; // [esp+140h] [ebp-100h]
  float v205; // [esp+144h] [ebp-FCh]
  float v206; // [esp+148h] [ebp-F8h]
  float v207; // [esp+14Ch] [ebp-F4h]
  int v208; // [esp+150h] [ebp-F0h]
  float v209; // [esp+154h] [ebp-ECh]
  float v210; // [esp+158h] [ebp-E8h]
  float v211; // [esp+15Ch] [ebp-E4h]
  int v212; // [esp+160h] [ebp-E0h]
  __int64 v213; // [esp+164h] [ebp-DCh]
  float v214; // [esp+16Ch] [ebp-D4h]
  int v215; // [esp+170h] [ebp-D0h]
  hk_Transform v216; // [esp+174h] [ebp-CCh] BYREF
  __m128 v217; // [esp+1B4h] [ebp-8Ch]
  __m128 v218; // [esp+1C4h] [ebp-7Ch] OVERLAPPED
  float v219; // [esp+1E0h] [ebp-60h]
  float v220; // [esp+1E4h] [ebp-5Ch]
  float v221; // [esp+1E8h] [ebp-58h]
  _BYTE perp_y_ws_4[20]; // [esp+1F0h] [ebp-50h] OVERLAPPED
  float v223[3]; // [esp+210h] [ebp-30h] BYREF
  hk_Vector3 perp_x_ws; // [esp+21Ch] [ebp-24h]
  float v225; // [esp+22Ch] [ebp-14h]
  hk_Hinge_Constraint_Work *work; // [esp+230h] [ebp-10h]
  hk_Rigid_Body *b1; // [esp+234h] [ebp-Ch]
  void *v228; // [esp+238h] [ebp-8h]
  void *retaddr; // [esp+240h] [ebp+0h]

  b1 = a2;
  v228 = retaddr;
  HIDWORD(v196) = a4;
  v7 = this;
  v8 = this->m_entities[0];
  v9 = (*(_DWORD *)&v8->flags & 0x800) == 0;
  w = *(float *)&this->m_entities[1];
  LODWORD(v196) = a3;
  *(_DWORD *)perp_y_ws_4 = this;
  work = (hk_Hinge_Constraint_Work *)v8;
  perp_x_ws.w = w;
  if ( v9 )
  {
    qmemcpy(&query_20[32], &v8->physical_core->m_world_f_core_last_psi, 0x40u);
    IVP_U_Matrix::vmult4(
      this: (IVP_U_Matrix *)&query_20[32],
      p_in: &v8->shift_core_f_object,
      p_out: (IVP_U_Float_Point *)&query_20[80]);
    w = perp_x_ws.w;
    v7 = *(hk_Hinge_Constraint **)perp_y_ws_4;
    v205 = *(float *)&query_20[36];
    v206 = *(float *)&query_20[52];
    v207 = *(float *)&query_20[68];
    v209 = *(float *)&query_20[40];
    v210 = *(float *)&query_20[56];
    *(_DWORD *)&orig_ws_4[48] = *(_DWORD *)&query_20[32];
    v211 = *(float *)&query_20[72];
    *(_DWORD *)&orig_ws_4[52] = *(_DWORD *)&query_20[48];
    v213 = *(_QWORD *)&query_20[80];
    *(_DWORD *)&orig_ws_4[56] = *(_DWORD *)&query_20[64];
    v12 = *(float *)&query_20[88];
    v204 = 0;
    v208 = 0;
    v212 = 0;
  }
  else
  {
    physical_core = v8->physical_core;
    *(float *)&orig_ws_4[48] = physical_core->m_world_f_core_last_psi.rows[0].k[0];
    *(float *)&orig_ws_4[52] = physical_core->m_world_f_core_last_psi.rows[1].k[0];
    *(float *)&orig_ws_4[56] = physical_core->m_world_f_core_last_psi.rows[2].k[0];
    v204 = 0;
    v205 = physical_core->m_world_f_core_last_psi.rows[0].k[1];
    v206 = physical_core->m_world_f_core_last_psi.rows[1].k[1];
    v207 = physical_core->m_world_f_core_last_psi.rows[2].k[1];
    v208 = 0;
    v209 = physical_core->m_world_f_core_last_psi.rows[0].k[2];
    v210 = physical_core->m_world_f_core_last_psi.rows[1].k[2];
    v211 = physical_core->m_world_f_core_last_psi.rows[2].k[2];
    v212 = 0;
    v213 = *(_QWORD *)physical_core->m_world_f_core_last_psi.vv.k;
    v12 = physical_core->m_world_f_core_last_psi.vv.k[2];
  }
  v214 = v12;
  v215 = 1065353216;
  if ( (*(_DWORD *)(LODWORD(w) + 68) & 0x800) != 0 )
  {
    v13 = *(_DWORD *)(LODWORD(w) + 148);
    v216.m_elems[0] = *(float *)(v13 + 96);
    v216.m_elems[1] = *(float *)(v13 + 112);
    v216.m_elems[2] = *(float *)(v13 + 128);
    v216.m_elems[3] = 0.0;
    v216.m_elems[4] = *(float *)(v13 + 100);
    v216.m_elems[5] = *(float *)(v13 + 116);
    v216.m_elems[6] = *(float *)(v13 + 132);
    v216.m_elems[7] = 0.0;
    v216.m_elems[8] = *(float *)(v13 + 104);
    v216.m_elems[9] = *(float *)(v13 + 120);
    v216.m_elems[10] = *(float *)(v13 + 136);
    v216.m_elems[11] = 0.0;
    *(_QWORD *)&v216.m_translation.x = *(_QWORD *)(v13 + 144);
    v216.m_translation.z = *(float *)(v13 + 152);
  }
  else
  {
    qmemcpy(&query_20[32], (const void *)(*(_DWORD *)(LODWORD(w) + 148) + 96), 0x40u);
    IVP_U_Matrix::vmult4(
      this: (IVP_U_Matrix *)&query_20[32],
      p_in: (const IVP_U_Float_Point *)(LODWORD(w) + 48),
      p_out: (IVP_U_Float_Point *)&query_20[80]);
    v7 = *(hk_Hinge_Constraint **)perp_y_ws_4;
    v216.m_elems[0] = *(float *)&query_20[32];
    v216.m_elems[1] = *(float *)&query_20[48];
    v216.m_elems[2] = *(float *)&query_20[64];
    v216.m_elems[4] = *(float *)&query_20[36];
    v216.m_elems[3] = 0.0;
    v216.m_elems[5] = *(float *)&query_20[52];
    v216.m_elems[7] = 0.0;
    v216.m_elems[11] = 0.0;
    v216.m_elems[6] = *(float *)&query_20[68];
    *(_QWORD *)&v216.m_translation.x = *(_QWORD *)&query_20[80];
    v216.m_elems[8] = *(float *)&query_20[40];
    v216.m_elems[9] = *(float *)&query_20[56];
    v216.m_translation.z = *(float *)&query_20[88];
    v216.m_elems[10] = *(float *)&query_20[72];
  }
  v216.m_translation.w = 1.0;
  hk_Vector3::set_transformed_pos(
    this: (hk_Vector3 *)&query_20[128],
    t: (const hk_Transform *)&orig_ws_4[48],
    v: &v7->m_axis_os[0].m_origin);
  hk_Vector3::set_transformed_pos(this: (hk_Vector3 *)orig_ws_4, t: &v216, v: &v7->m_axis_os[1].m_origin);
  hk_Vector3::set_rotated_dir(
    this: (hk_Vector3 *)&query_20[96],
    t: (const hk_Rotation *)&orig_ws_4[48],
    v: &v7->m_axis_os[0].m_direction);
  hk_Vector3::set_rotated_dir(this: (hk_Vector3 *)&query_20[112], t: &v216, v: &v7->m_axis_os[1].m_direction);
  hk_Vector3::set_rotated_dir(this: (hk_Vector3 *)v223, t: (const hk_Rotation *)&orig_ws_4[48], v: v7->m_axis_perp_os);
  v9 = *(_WORD *)&v7->m_limit.m_limit_is_enabled == 0;
  v219 = (float)(*(float *)&query_20[104] * v223[1]) - (float)(*(float *)&query_20[100] * v223[2]);
  v220 = (float)(*(float *)&query_20[96] * v223[2]) - (float)(v223[0] * *(float *)&query_20[104]);
  v221 = (float)(v223[0] * *(float *)&query_20[100]) - (float)(*(float *)&query_20[96] * v223[1]);
  if ( v9 )
  {
    v15 = work;
  }
  else
  {
    v218.m128_u64[0] = tau_factor;
    v218.m128_u64[1] = 0;
    hk_Vector3::set_rotated_dir(this: (hk_Vector3 *)v201, t: &v216, v: &v7->m_axis_perp_os[1]);
    v14 = (float)((float)((float)(v201[1] * v220) + (float)(v219 * v201[0])) + (float)(v201[2] * v221));
    __libm_sse2_atan2(y: v196, x: v197);
    v15 = work;
    v16 = *(__m128 **)&work->query_engine.m_vmq_storage.m_buffer_0[20];
    v17 = *(__m128 **)(LODWORD(perp_x_ws.w) + 148);
    v18 = v16->m128_i16[0];
    *(float *)&v14 = v14;
    v19 = 0;
    v19.m128_f32[0] = *(float *)&v14;
    v20 = v19;
    v21 = Four_Zeros;
    v22 = _mm_shuffle_ps(v20, v20, 0);
    v23 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&query_20[96], *(__m128 *)&query_20[96], 170), v16[8]),
              _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&query_20[96], *(__m128 *)&query_20[96], 85), v16[7])),
            _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&query_20[96], *(__m128 *)&query_20[96], 0), v16[6]));
    v24 = _mm_sub_ps(Four_Zeros, *(__m128 *)&query_20[96]);
    v25 = Four_Zeros;
    v200 = v22;
    v26 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v24, v24, 170), v17[8]),
              _mm_mul_ps(_mm_shuffle_ps(v24, v24, 85), v17[7])),
            _mm_mul_ps(_mm_shuffle_ps(v24, v24, 0), v17[6]));
    v217 = Four_Zeros;
    v27 = Four_Zeros;
    if ( (v18 & 0x12) != 0 )
    {
      *(__m128 *)query_20 = Four_Zeros;
    }
    else
    {
      v217 = _mm_mul_ps(v16[12], v23);
      v28 = 0;
      v28.m128_f32[0] = (float)(v217.m128_f32[1] + v217.m128_f32[0]) + v217.m128_f32[2];
      *(__m128 *)query_20 = _mm_mul_ps(v16[3], v23);
      *(__m128 *)&perp_y_ws_4[4] = _mm_mul_ps(*(__m128 *)query_20, v23);
      v29 = 0;
      v25 = _mm_shuffle_ps(v28, v28, 0);
      v29.m128_f32[0] = (float)(*(float *)&perp_y_ws_4[8] + *(float *)&perp_y_ws_4[4]) + *(float *)&perp_y_ws_4[12];
      v217 = v25;
      v27 = _mm_shuffle_ps(v29, v29, 0);
    }
    if ( (v17->m128_i16[0] & 0x12) != 0 )
    {
      *(__m128 *)&query_20[16] = Four_Zeros;
    }
    else
    {
      *(__m128 *)&perp_y_ws_4[4] = _mm_mul_ps(v17[12], v26);
      v30 = 0;
      v30.m128_f32[0] = (float)(*(float *)&perp_y_ws_4[8] + *(float *)&perp_y_ws_4[4]) + *(float *)&perp_y_ws_4[12];
      *(__m128 *)&query_20[16] = _mm_mul_ps(v17[3], v26);
      *(__m128 *)&perp_y_ws_4[4] = _mm_mul_ps(*(__m128 *)&query_20[16], v26);
      v31 = 0;
      v31.m128_f32[0] = (float)(*(float *)&perp_y_ws_4[8] + *(float *)&perp_y_ws_4[4]) + *(float *)&perp_y_ws_4[12];
      v25 = _mm_add_ps(v25, _mm_shuffle_ps(v30, v30, 0));
      v217 = v25;
      v27 = _mm_add_ps(v27, _mm_shuffle_ps(v31, v31, 0));
    }
    v32 = v218;
    v33 = _mm_rcp_ps(v27);
    m_desired_velocity_low = LODWORD(v7->m_limit.m_desired_velocity);
    v35 = s_limit_mask_0[v7->m_limit.m_limit_is_enabled];
    v9 = !v7->m_limit.m_friction_is_enabled;
    *(__m128 *)&query_20[48] = _mm_and_ps(
                                 _mm_sub_ps(_mm_add_ps(v33, v33), _mm_mul_ps(_mm_mul_ps(v33, v33), v27)),
                                 _mm_cmplt_ps(Four_Epsilons, v27));
    v36 = *(_OWORD *)v35;
    *(_OWORD *)&orig_ws_4[16] = m_desired_velocity_low;
    m_joint_friction_low = (__m128)LODWORD(v7->m_limit.m_joint_friction);
    delta_time_low = LODWORD(pi->delta_time);
    *(_OWORD *)&query_20[64] = v36;
    m_ref_position_low = (__m128)LODWORD(v7->m_limit.m_ref_position);
    *(_OWORD *)&perp_y_ws_4[4] = delta_time_low;
    i_delta_time_low = (__m128)LODWORD(pi->i_delta_time);
    v40 = _mm_shuffle_ps(m_ref_position_low, m_ref_position_low, 0);
    v41 = Four_Zeros;
    *(__m128 *)&orig_ws_4[32] = v40;
    v199 = i_delta_time_low;
    if ( !v9 )
    {
      v32 = v218;
      v42 = _mm_sub_ps(v40, v22);
      v43 = _mm_cmplt_ps(v42, _mm_sub_ps(Four_Zeros, s_pi_0));
      v44 = _mm_cmplt_ps(s_pi_0, v42);
      v45 = _mm_or_ps(
              _mm_andnot_ps(
                v44,
                _mm_or_ps(_mm_and_ps(_mm_sub_ps(Four_Zeros, s_2_pi_0), v43), _mm_andnot_ps(v43, Four_Zeros))),
              _mm_and_ps(v44, s_2_pi_0));
      v200 = _mm_add_ps(v45, v200);
      v46 = _mm_sub_ps(v42, v45);
      v47 = _mm_mul_ps(
              _mm_sub_ps(
                _mm_mul_ps(_mm_mul_ps(_mm_mul_ps(v218, s_friction_tau_factor_0), v46), i_delta_time_low),
                _mm_mul_ps(_mm_shuffle_ps(v32, v32, 85), v217)),
              *(__m128 *)&query_20[48]);
      v48 = _mm_rcp_ps(v47);
      v49 = _mm_mul_ps(
              _mm_and_ps(
                _mm_sub_ps(_mm_add_ps(v48, v48), _mm_mul_ps(_mm_mul_ps(v48, v48), v47)),
                *(__m128 *)g_SIMD_clear_signmask),
              _mm_mul_ps(_mm_shuffle_ps(m_joint_friction_low, m_joint_friction_low, 0), *(__m128 *)&perp_y_ws_4[4]));
      v50 = _mm_cmplt_ps(v49, Four_Ones);
      v51 = _mm_or_ps(_mm_andnot_ps(v50, Four_Ones), _mm_and_ps(v50, v49));
      *(__m128 *)&orig_ws_4[16] = _mm_mul_ps(
                                    _mm_shuffle_ps(*(__m128 *)&orig_ws_4[16], *(__m128 *)&orig_ws_4[16], 0),
                                    *(__m128 *)&perp_y_ws_4[4]);
      v41 = _mm_mul_ps(v51, v47);
      LODWORD(v7->m_limit.m_ref_position) = COERCE_UNSIGNED_INT(
                                              (float)(*(float *)&orig_ws_4[16] + *(float *)&orig_ws_4[32])
                                            - (float)(v46.m128_f32[0] - (float)(v51.m128_f32[0] * v46.m128_f32[0])))
                                          & g_SIMD_ComponentMask[0][0]
                                          | _mm_andnot_ps(
                                              *(__m128 *)&g_SIMD_ComponentMask[0][0],
                                              *(__m128 *)&orig_ws_4[32]).m128_u32[0];
      v21 = Four_Zeros;
      v25 = v217;
    }
    v52 = _mm_mul_ps(
            _mm_mul_ps(
              _mm_shuffle_ps((__m128)LODWORD(v7->m_limit.m_limit_tau), (__m128)LODWORD(v7->m_limit.m_limit_tau), 0),
              v32),
            _mm_mul_ps(v199, *(__m128 *)&query_20[48]));
    v53 = _mm_add_ps(_mm_mul_ps(_mm_add_ps(_mm_mul_ps(v27, v41), v25), *(__m128 *)&perp_y_ws_4[4]), v200);
    v54 = _mm_sub_ps(
            v41,
            _mm_and_ps(
              _mm_add_ps(
                _mm_min_ps(
                  _mm_mul_ps(
                    _mm_sub_ps(
                      v53,
                      _mm_shuffle_ps(
                        (__m128)LODWORD(v7->m_limit.m_limit_min),
                        (__m128)LODWORD(v7->m_limit.m_limit_min),
                        0)),
                    v52),
                  v21),
                _mm_max_ps(
                  _mm_mul_ps(
                    _mm_sub_ps(
                      v53,
                      _mm_shuffle_ps(
                        (__m128)LODWORD(v7->m_limit.m_limit_max),
                        (__m128)LODWORD(v7->m_limit.m_limit_max),
                        0)),
                    v52),
                  v21)),
              *(__m128 *)&query_20[64]));
    v55 = _mm_shuffle_ps(v54, v54, 0);
    v56 = _mm_mul_ps(v55, *(__m128 *)&query_20[16]);
    v16[12] = _mm_and_ps(_mm_add_ps(_mm_mul_ps(v55, *(__m128 *)query_20), v16[12]), *(__m128 *)g_SIMD_clear_wmask);
    v17[12] = _mm_and_ps(_mm_add_ps(v56, v17[12]), *(__m128 *)g_SIMD_clear_wmask);
  }
  if ( mem != nullptr )
  {
    *mem = mem + 4;
    mem[1] = 5;
    mem[2] = 8;
    mem[12] = mem + 16;
    mem[13] = 5;
    mem[14] = 8;
    mem[192] = mem + 196;
    mem[193] = 5;
    mem[194] = 5;
    mem[195] = 8;
    LODWORD(perp_x_ws.z) = mem;
  }
  else
  {
    perp_x_ws.z = 0.0;
  }
  v57 = LODWORD(perp_x_ws.z) + 96;
  hk_VM_Query_Builder<hk_VMQ_Storage<5>>::begin(
    this: (hk_VM_Query_Builder<hk_VMQ_Storage<5> > *)(LODWORD(perp_x_ws.z) + 96),
    size: 5);
  v58 = *(float **)&v15->query_engine.m_vmq_storage.m_buffer_0[20];
  v59 = *(float *)&query_20[128] - v58[36];
  v60 = *(float *)&query_20[132] - v58[37];
  v61 = *(float *)&query_20[136] - v58[38];
  v62 = perp_x_ws.w;
  v63 = *(float **)(LODWORD(perp_x_ws.w) + 148);
  v64 = *(float *)&orig_ws_4[4] - v63[37];
  v218.m128_f32[0] = *(float *)orig_ws_4 - v63[36];
  v65 = *(float *)&orig_ws_4[8] - v63[38];
  v66 = v57 + *(_DWORD *)(v57 + 872) + 192;
  *(float *)&orig_ws_4[36] = v60;
  v218.m128_f32[2] = v65;
  *(_DWORD *)(v66 + 8) = 0;
  *(_DWORD *)(v66 + 4) = 0;
  *(_DWORD *)v66 = 1065353216;
  *(_DWORD *)(v66 + 16) = 0;
  *(float *)(v66 + 20) = v61;
  LODWORD(v67) = LODWORD(v60) ^ _mask__NegFloat_;
  *(float *)(v66 + 24) = v67;
  v68 = *(float **)&v15->query_engine.m_vmq_storage.m_buffer_0[20];
  v69 = (float)((float)(v68[26] * 0.0) + (float)(v68[30] * v61)) + (float)(v68[34] * *(float *)(v66 + 24));
  v70 = (float)(v68[28] * v61) + (float)(v68[24] * 0.0);
  v71 = v68[32] * *(float *)(v66 + 24);
  *(float *)(v66 + 20) = (float)((float)(v68[25] * 0.0) + (float)(v68[29] * v61)) + (float)(v68[33] * v67);
  *(float *)(v66 + 24) = v69;
  *(float *)(v66 + 16) = v70 + v71;
  *(_DWORD *)(v66 + 32) = *(_DWORD *)(v57 + 876);
  v72 = v57 + *(_DWORD *)(v57 + 872) + 432;
  *(_DWORD *)(v72 + 8) = 0;
  *(_DWORD *)(v72 + 4) = 0;
  v225 = v69;
  v73 = v218.m128_f32[2];
  *(_DWORD *)v72 = -1082130432;
  *(float *)(v72 + 20) = v73 * -1.0;
  *(_DWORD *)(v72 + 16) = 0;
  *(float *)(v72 + 24) = v64;
  v74 = *(float **)(LODWORD(v62) + 148);
  *(float *)&work = v74[25] * 0.0;
  v75 = v74[33];
  *(float *)&work = *(float *)&work + (float)(v74[29] * *(float *)(v72 + 20));
  v76 = *(float *)&work + (float)(v75 * v64);
  v77 = v74[30] * *(float *)(v72 + 20);
  v225 = v76;
  v78 = 0.0 * v74[24];
  v79 = (float)(v74[26] * 0.0) + v77;
  v80 = v74[34];
  *(float *)&work = v79;
  v81 = v79 + (float)(v80 * v64);
  v82 = (float)(v74[28] * *(float *)(v72 + 20)) + v78;
  perp_x_ws.y = v81;
  v83 = v74[32] * v64;
  *(float *)(v72 + 20) = v225;
  *(float *)(v72 + 24) = perp_x_ws.y;
  *(float *)(v72 + 16) = v82 + v83;
  *(_DWORD *)(v72 + 32) = *(_DWORD *)(v57 + 876);
  v84 = *(_DWORD *)(v57 + 872);
  *(_DWORD *)(v57 + v84 + 248) = 0;
  *(_DWORD *)(v57 + v84 + 240) = 0;
  *(_DWORD *)(v57 + v84 + 244) = 1065353216;
  LODWORD(v85) = LODWORD(v61) ^ _mask__NegFloat_;
  v86 = v57 + v84 + 240;
  *(float *)(v86 + 16) = v85;
  *(_DWORD *)(v86 + 20) = 0;
  *(float *)(v86 + 24) = v59;
  v87 = *(float **)&v15->query_engine.m_vmq_storage.m_buffer_0[20];
  v88 = (float)((float)(v87[25] * v85) + (float)(v87[29] * 0.0)) + (float)(v87[33] * v59);
  v89 = v87[30];
  v90 = v87[26] * v85;
  v91 = v85 * v87[24];
  *(float *)&work = v90;
  v92 = v90 + (float)(v89 * 0.0);
  v93 = v87[34];
  *(float *)&work = v92;
  v94 = v92 + (float)(v93 * v59);
  v95 = v87[28] * 0.0;
  v225 = v94;
  *(float *)(v86 + 16) = (float)(v95 + v91) + (float)(v87[32] * v59);
  *(float *)(v86 + 20) = v88;
  *(float *)(v86 + 24) = v225;
  v96 = v218.m128_i32[2];
  *(_DWORD *)(v86 + 32) = *(_DWORD *)(v57 + 876) + 1;
  v97 = *(_DWORD *)(v57 + 872);
  *(_DWORD *)(v57 + v97 + 488) = 0;
  *(_DWORD *)(v57 + v97 + 480) = 0;
  *(_DWORD *)(v57 + v97 + 484) = -1082130432;
  *(_DWORD *)(v57 + v97 + 496) = v96;
  *(_DWORD *)(v57 + v97 + 500) = 0;
  v98 = v57 + v97 + 480;
  *(float *)(v98 + 24) = v218.m128_f32[0] * -1.0;
  v99 = *(float **)(LODWORD(v62) + 148);
  v100 = *(float *)(v98 + 16);
  v101 = (float)((float)(v99[25] * v100) + (float)(v99[29] * 0.0)) + (float)(v99[33] * *(float *)(v98 + 24));
  v102 = v99[26] * v100;
  v103 = v100 * v99[24];
  v104 = v99[30] * 0.0;
  *(float *)&work = v102;
  v105 = v102 + v104;
  v106 = v99[34] * *(float *)(v98 + 24);
  *(float *)&work = v105;
  v107 = v105 + v106;
  v108 = (float)(v99[28] * 0.0) + v103;
  v225 = v107;
  v109 = v99[32] * *(float *)(v98 + 24);
  *(float *)(v98 + 24) = v225;
  *(float *)(v98 + 20) = v101;
  *(float *)(v98 + 16) = v108 + v109;
  *(_DWORD *)(v98 + 32) = *(_DWORD *)(v57 + 876) + 1;
  v110 = *(_DWORD *)(v57 + 872);
  *(_DWORD *)(v57 + v110 + 292) = 0;
  *(_DWORD *)(v57 + v110 + 288) = 0;
  *(_DWORD *)(v57 + v110 + 296) = 1065353216;
  v111 = *(float *)&orig_ws_4[36];
  v112 = (float *)(v57 + v110 + 288);
  v112[4] = *(float *)&orig_ws_4[36];
  *((_DWORD *)v112 + 5) = LODWORD(v59) ^ _mask__NegFloat_;
  v112[6] = 0.0;
  v113 = *(float **)&v15->query_engine.m_vmq_storage.m_buffer_0[20];
  v114 = v111 * v113[24];
  v115 = v113[32];
  v116 = (float)((float)(v113[26] * v111) + (float)(v113[30] * v112[5])) + (float)(v113[34] * 0.0);
  v117 = v113[28] * v112[5];
  v112[5] = (float)((float)(v113[25] * v111) + (float)(v113[29] * v112[5])) + (float)(v113[33] * 0.0);
  v112[6] = v116;
  v118 = v117 + v114;
  v119 = v218.m128_f32[0];
  v112[4] = v118 + (float)(v115 * 0.0);
  *((_DWORD *)v112 + 8) = *(_DWORD *)(v57 + 876) + 2;
  v120 = *(_DWORD *)(v57 + 872);
  *(_DWORD *)(v57 + v120 + 532) = 0;
  *(_DWORD *)(v57 + v120 + 528) = 0;
  *(_DWORD *)(v57 + v120 + 536) = -1082130432;
  *(float *)(v57 + v120 + 548) = v119;
  *(_DWORD *)(v57 + v120 + 552) = 0;
  v121 = v57 + v120 + 528;
  *(float *)(v121 + 16) = v64 * -1.0;
  v122 = *(float **)(LODWORD(v62) + 148);
  v123 = *(float *)(v121 + 16);
  v124 = (float)((float)(v122[26] * v123) + (float)(v122[30] * v119)) + (float)(v122[34] * 0.0);
  v125 = (float)(v122[28] * v119) + (float)(v122[24] * v123);
  v126 = v122[32];
  *(float *)(v121 + 20) = (float)((float)(v122[25] * v123) + (float)(v122[29] * v119)) + (float)(v122[33] * 0.0);
  *(float *)(v121 + 24) = v124;
  *(float *)(v121 + 16) = v125 + (float)(v126 * 0.0);
  *(_DWORD *)(v121 + 32) = *(_DWORD *)(v57 + 876) + 2;
  v127 = *(_DWORD *)(v57 + 872);
  *(_DWORD *)(v57 + v127 + 344) = 0;
  *(_DWORD *)(v57 + v127 + 340) = 0;
  *(_DWORD *)(v57 + v127 + 336) = 0;
  v128 = v57 + v127 + 336;
  *(float *)(v128 + 16) = v223[0];
  *(float *)(v128 + 20) = v223[1];
  v129 = v223[2];
  *(float *)(v128 + 24) = v223[2];
  v130 = *(float **)&v15->query_engine.m_vmq_storage.m_buffer_0[20];
  v131 = *(float *)(v128 + 20);
  v132 = *(float *)(v128 + 16);
  v133 = v129;
  v134 = (float)((float)(v130[25] * v132) + (float)(v130[29] * v131)) + (float)(v130[33] * v129);
  v135 = (float)((float)(v130[26] * v132) + (float)(v130[30] * v131)) + (float)(v130[34] * v133);
  v136 = (float)(v130[28] * v131) + (float)(v130[24] * v132);
  v137 = v130[32];
  *(float *)(v128 + 20) = v134;
  *(float *)(v128 + 24) = v135;
  *(float *)(v128 + 16) = v136 + (float)(v137 * v133);
  *(_DWORD *)(v128 + 32) = *(_DWORD *)(v57 + 876) + 3;
  v138 = *(_DWORD *)(v57 + 872);
  *(_DWORD *)(v57 + v138 + 584) = 0;
  *(_DWORD *)(v57 + v138 + 580) = 0;
  *(_DWORD *)(v57 + v138 + 576) = 0;
  v139 = v57 + v138 + 576;
  *(float *)(v139 + 16) = v223[0] * -1.0;
  *(float *)(v139 + 20) = v223[1] * -1.0;
  v140 = v223[2] * -1.0;
  *(float *)(v139 + 24) = v223[2] * -1.0;
  v141 = *(float **)(LODWORD(v62) + 148);
  v142 = *(float *)(v139 + 20);
  v143 = *(float *)(v139 + 16);
  v144 = v140;
  v145 = (float)((float)(v141[25] * v143) + (float)(v141[29] * v142)) + (float)(v141[33] * v140);
  v146 = (float)((float)(v141[26] * v143) + (float)(v141[30] * v142)) + (float)(v141[34] * v144);
  v147 = (float)(v141[28] * v142) + (float)(v141[24] * v143);
  v148 = v141[32];
  *(float *)(v139 + 20) = v145;
  v149 = v219;
  *(float *)(v139 + 24) = v146;
  *(float *)(v139 + 16) = v147 + (float)(v148 * v144);
  *(_DWORD *)(v139 + 32) = *(_DWORD *)(v57 + 876) + 3;
  v150 = v57 + *(_DWORD *)(v57 + 872) + 384;
  *(_DWORD *)(v150 + 8) = 0;
  *(_DWORD *)(v150 + 4) = 0;
  *(_DWORD *)v150 = 0;
  *(float *)(v150 + 16) = v149;
  *(float *)(v150 + 20) = v220;
  *(float *)(v150 + 24) = v221;
  v151 = *(float **)&v15->query_engine.m_vmq_storage.m_buffer_0[20];
  v152 = *(float *)(v150 + 20);
  v153 = *(float *)(v150 + 16);
  v154 = *(float *)(v150 + 24);
  v155 = (float)((float)(v151[25] * v153) + (float)(v151[29] * v152)) + (float)(v151[33] * v154);
  v156 = v151[26] * v153;
  v157 = (float)(v151[28] * v152) + (float)(v153 * v151[24]);
  v158 = v151[32];
  *(float *)(v150 + 24) = (float)(v156 + (float)(v151[30] * v152)) + (float)(v151[34] * v154);
  *(float *)(v150 + 20) = v155;
  *(float *)(v150 + 16) = v157 + (float)(v158 * v154);
  *(_DWORD *)(v150 + 32) = *(_DWORD *)(v57 + 876) + 4;
  v159 = *(_DWORD *)(v57 + 872);
  *(_DWORD *)(v57 + v159 + 632) = 0;
  *(_DWORD *)(v57 + v159 + 628) = 0;
  *(_DWORD *)(v57 + v159 + 624) = 0;
  *(float *)(v57 + v159 + 640) = v219 * -1.0;
  v160 = v57 + v159 + 624;
  *(float *)(v160 + 20) = v220 * -1.0;
  v161 = v221 * -1.0;
  *(float *)(v160 + 24) = v221 * -1.0;
  v162 = *(float **)(LODWORD(v62) + 148);
  v163 = *(float *)(v160 + 20);
  v164 = *(float *)(v160 + 16);
  v165 = v161;
  v166 = (float)((float)(v162[25] * v164) + (float)(v162[29] * v163)) + (float)(v162[33] * v161);
  v167 = (float)((float)(v162[26] * v164) + (float)(v162[30] * v163)) + (float)(v162[34] * v165);
  *(float *)(v160 + 16) = (float)((float)(v162[28] * v163) + (float)(v162[24] * v164)) + (float)(v162[32] * v165);
  *(float *)(v160 + 20) = v166;
  *(float *)(v160 + 24) = v167;
  *(_DWORD *)(v160 + 32) = *(_DWORD *)(v57 + 876) + 4;
  *(_DWORD *)(v57 + 876) += 5;
  v168 = *(_DWORD *)(v57 + 876);
  *(_DWORD *)(v57 + 872) += 240;
  *(_DWORD *)(v57 + 848) = v168;
  *(_DWORD *)(v57 + 860) = v168;
  work = (hk_Hinge_Constraint_Work *)(v57 + 672);
  v169 = *(hk_Rigid_Body_Core **)&v15->query_engine.m_vmq_storage.m_buffer_0[20];
  LODWORD(perp_x_ws.y) = v57 + 848;
  LODWORD(v225) = v57 + 860;
  hk_Rigid_Body_Core::add_to_mass_matrix_inv(
    this: v169,
    input: (hk_Core_VMQ_Input *)(v57 + 848),
    matrix_out: (hk_Dense_Matrix *)(v57 + 672),
    velocities_out: (float *)v57);
  v170 = *(_DWORD *)(v57 + 876);
  v171 = (hk_Core_VMQ_Input *)LODWORD(v225);
  y = perp_x_ws.y;
  *(_DWORD *)LODWORD(v225) = v170;
  *(_DWORD *)LODWORD(y) = v170;
  hk_Rigid_Body_Core::add_to_mass_matrix_inv(
    this: *(hk_Rigid_Body_Core **)(LODWORD(perp_x_ws.w) + 148),
    input: v171,
    matrix_out: (hk_Dense_Matrix *)work,
    velocities_out: (float *)v57);
  v173 = *(float *)&orig_ws_4[8] - *(float *)&query_20[136];
  v174 = 0;
  v174.m128_f32[0] = *(float *)(*(_DWORD *)perp_y_ws_4 + 120) * *(float *)&tau_factor;
  *(__m128 *)&orig_ws_4[32] = _mm_shuffle_ps(v174, v174, 0);
  v175 = *(_DWORD *)LODWORD(perp_x_ws.z);
  v176 = 0;
  v176.m128_f32[0] = (float)(*(float *)(*(_DWORD *)perp_y_ws_4 + 124) * -1.0) * *((float *)&tau_factor + 1);
  v177 = v176;
  v176.m128_f32[0] = *(float *)&orig_ws_4[4] - *(float *)&query_20[132];
  *(__m128 *)&orig_ws_4[16] = _mm_shuffle_ps(v177, v177, 0);
  *(float *)v175 = *(float *)orig_ws_4 - *(float *)&query_20[128];
  v178 = *(float *)v175;
  *(_DWORD *)(v175 + 4) = v176.m128_i32[0];
  *(float *)(v175 + 8) = v173;
  v177.m128_i32[0] = LODWORD(pi->i_delta_time);
  *(float *)v175 = v178 * v177.m128_f32[0];
  *(float *)(v175 + 4) = v177.m128_f32[0] * v176.m128_f32[0];
  *(float *)(v175 + 8) = v177.m128_f32[0] * v173;
  *(float *)(v175 + 12) = (float)((float)((float)(*(float *)&query_20[116] * v220)
                                        + (float)(v219 * *(float *)&query_20[112]))
                                + (float)(*(float *)&query_20[120] * v221))
                        * pi->i_delta_time;
  *(_DWORD *)(v175 + 16) = COERCE_UNSIGNED_INT(
                             (float)((float)((float)(*(float *)&query_20[116] * v223[1])
                                           + (float)(v223[0] * *(float *)&query_20[112]))
                                   + (float)(*(float *)&query_20[120] * v223[2]))
                           * pi->i_delta_time)
                         ^ _mask__NegFloat_;
  hk_Dense_Matrix_Util::invert_5x5(m: (hk_Fixed_Dense_Matrix<5> *)work, tolerance: 0.0);
  z = perp_x_ws.z;
  m_elt = work->m_correction.m_elt;
  v181 = *(__m128 **)(LODWORD(perp_x_ws.z) + 48);
  v182 = _mm_add_ps(
           _mm_mul_ps(*(__m128 *)*(_DWORD *)LODWORD(perp_x_ws.z), *(__m128 *)&orig_ws_4[32]),
           _mm_mul_ps(*(__m128 *)v57, *(__m128 *)&orig_ws_4[16]));
  v183 = _mm_add_ps(
           _mm_mul_ps(*(__m128 *)(v57 + 16), *(__m128 *)&orig_ws_4[16]),
           _mm_mul_ps(*(__m128 *)(*(_DWORD *)LODWORD(perp_x_ws.z) + 16), *(__m128 *)&orig_ws_4[32]));
  v184 = _mm_shuffle_ps(v182, v182, 0);
  v185 = _mm_add_ps(_mm_mul_ps(*(__m128 *)work->m_correction.m_elt, v184), Four_Zeros);
  v186 = _mm_add_ps(_mm_mul_ps(*(__m128 *)(work->m_correction.m_elt + 4), v184), Four_Zeros);
  v187 = _mm_shuffle_ps(v182, v182, 85);
  v188 = _mm_mul_ps(*(__m128 *)(work->m_correction.m_elt + 12), v187);
  v189 = _mm_mul_ps(*(__m128 *)(work->m_correction.m_elt + 8), v187);
  v190 = _mm_shuffle_ps(v182, v182, 170);
  *(__m128 *)&orig_ws_4[16] = _mm_mul_ps(*(__m128 *)(work->m_correction.m_elt + 16), v190);
  v191 = *(__m128 *)(m_elt + 20);
  *(__m128 *)&orig_ws_4[32] = _mm_shuffle_ps(v182, v182, 255);
  v192 = _mm_add_ps(v186, v188);
  v193 = _mm_mul_ps(*(__m128 *)(m_elt + 28), *(__m128 *)&orig_ws_4[32]);
  v194 = _mm_shuffle_ps(v183, v183, 0);
  *v181 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_add_ps(v185, v189), *(__m128 *)&orig_ws_4[16]),
              _mm_mul_ps(*(__m128 *)(m_elt + 24), *(__m128 *)&orig_ws_4[32])),
            _mm_mul_ps(*(__m128 *)(m_elt + 32), v194));
  *(__m128 *)(*(_DWORD *)(LODWORD(z) + 48) + 16) = _mm_add_ps(
                                                     _mm_mul_ps(*(__m128 *)(m_elt + 36), v194),
                                                     _mm_add_ps(_mm_add_ps(v192, _mm_mul_ps(v191, v190)), v193));
  hk_Rigid_Body_Core::apply_impulses(
    this: *(hk_Rigid_Body_Core **)&v15->query_engine.m_vmq_storage.m_buffer_0[20],
    input: (hk_Core_VMQ_Input *)LODWORD(perp_x_ws.y),
    impulse_strength: *(const float **)(LODWORD(z) + 48));
  hk_Rigid_Body_Core::apply_impulses(
    this: *(hk_Rigid_Body_Core **)(LODWORD(perp_x_ws.w) + 148),
    input: (hk_Core_VMQ_Input *)LODWORD(v225),
    impulse_strength: *(const float **)(LODWORD(perp_x_ws.z) + 48));
  return 976;
}
