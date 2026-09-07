// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/havana/havok/hk_physics/constraint/ragdoll/ragdoll_constraint.cpp
// Functions: 14
// ============================================================

#include "ivp\havana\havok\hk_physics\constraint\ragdoll\ragdoll_constraint.h"

//------------------------------------------------------------------------------
// Address: 0x1003DFF0
// Name: public: void hk_Rotation_sse_t::AddDiagonal(union __m128 const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Rotation_sse_t::AddDiagonal(hk_Rotation_sse_t *this, const __m128 *diag)
{
  __m128 y; // xmm1
  __m128 v3; // xmm2
  __m128 v4; // xmm0
  __m128 z; // xmm1

  y = this->y;
  this->x = _mm_or_ps(
              _mm_and_ps(_mm_add_ps(*diag, this->x), *(__m128 *)&g_SIMD_ComponentMask[0][0]),
              _mm_andnot_ps(*(__m128 *)&g_SIMD_ComponentMask[0][0], this->x));
  v3 = _mm_and_ps(_mm_add_ps(*diag, y), (__m128)xmmword_100DAD20);
  v4 = _mm_andnot_ps((__m128)xmmword_100DAD20, y);
  z = this->z;
  this->y = _mm_or_ps(v3, v4);
  this->z = _mm_or_ps(
              _mm_and_ps(_mm_add_ps(*diag, z), (__m128)xmmword_100DAD30),
              _mm_andnot_ps((__m128)xmmword_100DAD30, z));
}

//------------------------------------------------------------------------------
// Address: 0x1003E060
// Name: public: void hk_Ragdoll_Constraint::write_to_blueprint(class hk_Ragdoll_Constraint_BP __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Ragdoll_Constraint::write_to_blueprint(hk_Ragdoll_Constraint *this, hk_Ragdoll_Constraint_BP *bp)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  __int64 m1_44; // [esp+2Ch] [ebp-34h]
  __int64 m0_4; // [esp+34h] [ebp-2Ch]
  __int64 m0_12; // [esp+3Ch] [ebp-24h]
  __int64 m0_20; // [esp+44h] [ebp-1Ch]
  __int64 m0_28; // [esp+4Ch] [ebp-14h]
  hk_Rotation v13; // 0:^10.48

  bp->m_transform_os_ks[0].hk_Rotation = this->m_transform_os_ks[0].hk_Rotation;
  bp->m_transform_os_ks[0].m_translation.x = this->m_transform_os_ks[0].m_translation.x;
  bp->m_transform_os_ks[0].m_translation.y = this->m_transform_os_ks[0].m_translation.y;
  bp->m_transform_os_ks[0].m_translation.z = this->m_transform_os_ks[0].m_translation.z;
  bp->m_transform_os_ks[1].hk_Rotation = this->m_transform_os_ks[1].hk_Rotation;
  bp->m_transform_os_ks[1].m_translation.x = this->m_transform_os_ks[1].m_translation.x;
  bp->m_transform_os_ks[1].m_translation.y = this->m_transform_os_ks[1].m_translation.y;
  bp->m_transform_os_ks[1].m_translation.z = this->m_transform_os_ks[1].m_translation.z;
  m1_44 = *(_QWORD *)&this->m_transform_os_ks[0].m_elems[2];
  m0_4 = *(_QWORD *)&this->m_transform_os_ks[0].m_elems[4];
  m0_12 = *(_QWORD *)&this->m_transform_os_ks[0].m_elems[6];
  m0_20 = *(_QWORD *)&this->m_transform_os_ks[0].m_elems[8];
  m0_28 = *(_QWORD *)&this->m_transform_os_ks[0].m_elems[10];
  v13 = this->m_transform_os_ks[1].hk_Rotation;
  v2 = 2 * this->m_axisMap[0];
  *(_QWORD *)&bp->m_transform_os_ks[0].m_elems[2 * v2] = *(_QWORD *)this->m_transform_os_ks[0].m_elems;
  LODWORD(bp->m_transform_os_ks[0].m_elems[2 * v2 + 2]) = m1_44;
  v3 = 2 * (this->m_axisMap[0] + 4);
  *(_QWORD *)&bp->m_transform_os_ks[0].m_elems[2 * v3] = *(_QWORD *)v13.m_elems;
  bp->m_transform_os_ks[0].m_elems[2 * v3 + 2] = v13.m_elems[2];
  v4 = 2 * this->m_axisMap[2];
  *(_QWORD *)&bp->m_transform_os_ks[0].m_elems[2 * v4] = m0_4;
  LODWORD(bp->m_transform_os_ks[0].m_elems[2 * v4 + 2]) = m0_12;
  v5 = 2 * (this->m_axisMap[2] + 4);
  *(_QWORD *)&bp->m_transform_os_ks[0].m_elems[2 * v5] = *(_QWORD *)&v13.m_elems[4];
  bp->m_transform_os_ks[0].m_elems[2 * v5 + 2] = v13.m_elems[6];
  v6 = 2 * this->m_axisMap[1];
  *(_QWORD *)&bp->m_transform_os_ks[0].m_elems[2 * v6] = m0_20;
  LODWORD(bp->m_transform_os_ks[0].m_elems[2 * v6 + 2]) = m0_28;
  v7 = 2 * (this->m_axisMap[1] + 4);
  *(_QWORD *)&bp->m_transform_os_ks[0].m_elems[2 * v7] = *(_QWORD *)&v13.m_elems[8];
  bp->m_transform_os_ks[0].m_elems[2 * v7 + 2] = v13.m_elems[10];
  *(_QWORD *)&bp->m_limits[0].m_limit_is_enabled = *(_QWORD *)&this->m_inputLimits[0].m_limit_is_enabled;
  *(_QWORD *)&bp->m_limits[0].m_limit_max = *(_QWORD *)&this->m_inputLimits[0].m_limit_max;
  *(_QWORD *)&bp->m_limits[0].m_joint_friction = *(_QWORD *)&this->m_inputLimits[0].m_joint_friction;
  bp->m_limits[0].m_limit_min = -this->m_inputLimits[0].m_limit_max;
  bp->m_limits[0].m_limit_max = -this->m_inputLimits[0].m_limit_min;
  bp->m_limits[1] = this->m_inputLimits[1];
  bp->m_limits[2] = this->m_inputLimits[2];
  bp->m_strength = this->m_strength;
  bp->m_tau = this->m_tau;
  bp->m_constrainTranslation = this->m_constrainTranslation;
  bp->m_axisMap[0] = this->m_axisMap[0];
  bp->m_axisMap[1] = this->m_axisMap[1];
  bp->m_axisMap[2] = this->m_axisMap[2];
}

//------------------------------------------------------------------------------
// Address: 0x1003E3C0
// Name: public: void hk_Ragdoll_Constraint::update_transforms(class hk_Transform const __near &,class hk_Transform const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Ragdoll_Constraint::update_transforms(
        hk_Ragdoll_Constraint *this,
        const hk_Transform *os_ks_0,
        const hk_Transform *os_ks_1)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax

  v3 = 2 * this->m_axisMap[0];
  this->m_transform_os_ks[0].m_elems[0] = os_ks_0->m_elems[4 * this->m_axisMap[0]];
  this->m_transform_os_ks[0].m_elems[1] = os_ks_0->m_elems[2 * v3 + 1];
  this->m_transform_os_ks[0].m_elems[2] = os_ks_0->m_elems[2 * v3 + 2];
  v4 = 2 * this->m_axisMap[0];
  this->m_transform_os_ks[1].m_elems[0] = os_ks_1->m_elems[4 * this->m_axisMap[0]];
  this->m_transform_os_ks[1].m_elems[1] = os_ks_1->m_elems[2 * v4 + 1];
  this->m_transform_os_ks[1].m_elems[2] = os_ks_1->m_elems[2 * v4 + 2];
  v5 = 2 * this->m_axisMap[2];
  this->m_transform_os_ks[0].m_elems[4] = os_ks_0->m_elems[4 * this->m_axisMap[2]];
  this->m_transform_os_ks[0].m_elems[5] = os_ks_0->m_elems[2 * v5 + 1];
  this->m_transform_os_ks[0].m_elems[6] = os_ks_0->m_elems[2 * v5 + 2];
  v6 = 2 * this->m_axisMap[2];
  this->m_transform_os_ks[1].m_elems[4] = os_ks_1->m_elems[4 * this->m_axisMap[2]];
  this->m_transform_os_ks[1].m_elems[5] = os_ks_1->m_elems[2 * v6 + 1];
  this->m_transform_os_ks[1].m_elems[6] = os_ks_1->m_elems[2 * v6 + 2];
  v7 = 2 * this->m_axisMap[1];
  this->m_transform_os_ks[0].m_elems[8] = os_ks_0->m_elems[4 * this->m_axisMap[1]];
  this->m_transform_os_ks[0].m_elems[9] = os_ks_0->m_elems[2 * v7 + 1];
  this->m_transform_os_ks[0].m_elems[10] = os_ks_0->m_elems[2 * v7 + 2];
  v8 = 2 * this->m_axisMap[1];
  this->m_transform_os_ks[1].m_elems[8] = os_ks_1->m_elems[4 * this->m_axisMap[1]];
  this->m_transform_os_ks[1].m_elems[9] = os_ks_1->m_elems[2 * v8 + 1];
  this->m_transform_os_ks[1].m_elems[10] = os_ks_1->m_elems[2 * v8 + 2];
}

//------------------------------------------------------------------------------
// Address: 0x1003E490
// Name: public: void hk_Ragdoll_Constraint::update_friction(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Ragdoll_Constraint::update_friction(hk_Ragdoll_Constraint *this, float friction)
{
  int v2; // xmm1_4
  float *p_m_joint_friction; // edx
  float *v4; // ecx
  int i; // esi

  v2 = LODWORD(friction) & _mask__AbsFloat_;
  p_m_joint_friction = &this->m_inputLimits[0].m_joint_friction;
  v4 = &this->m_limits[0].m_joint_friction;
  for ( i = 3; i != 0; --i )
  {
    *((_BYTE *)v4 - 15) = friction != 0.0;
    *(_DWORD *)v4 = v2;
    v4[1] = 0.0;
    *((_BYTE *)p_m_joint_friction - 15) = friction != 0.0;
    *(_DWORD *)p_m_joint_friction = v2;
    p_m_joint_friction[1] = 0.0;
    v4 += 7;
    p_m_joint_friction += 6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003E500
// Name: public: virtual int hk_Ragdoll_Constraint::get_vmq_storage_size(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall hk_Ragdoll_Constraint::get_vmq_storage_size(hk_Ragdoll_Constraint *this)
{
  return 736;
}

//------------------------------------------------------------------------------
// Address: 0x1003E510
// Name: protected: void hk_Ragdoll_Constraint::apply_angular_part(class hk_PSI_Info __near &,class hk_Ragdoll_Constraint_Work __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Ragdoll_Constraint::apply_angular_part(
        hk_Ragdoll_Constraint *this,
        hk_PSI_Info *pi,
        hk_Ragdoll_Constraint_Work *work)
{
  __m128 tau_strength_X_twist_factors; // xmm7
  hk_Rigid_Body *v5; // ecx
  __m128 *physical_core; // edi
  __m128 *v7; // ecx
  hk_APL_Query::StateEnum m_state; // edx
  __m128 v9; // xmm5
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm2
  __m128 twist_axis_ws; // xmm1
  __m128 v14; // xmm0
  __m128 v15; // xmm2
  __m128 v16; // xmm1
  __m128 v17; // xmm2
  __m128 v18; // xmm4
  __m128 v19; // xmm4
  __m128 v20; // xmm2
  __m128 v21; // xmm2
  __m128 v22; // xmm3
  __m128 v23; // xmm0
  __m128 v24; // xmm1
  __m128 v25; // xmm0
  __m128 v26; // xmm4
  __m128 delta_time_low; // xmm6
  __m128 v28; // xmm0
  __m128 v29; // xmm1
  __m128 v30; // xmm0
  __m128 v31; // xmm2
  __m128 v32; // xmm3
  __m128 v33; // xmm3
  __m128 v34; // xmm4
  __m128 v35; // xmm0
  __m128 v36; // xmm1
  __m128 v37; // xmm1
  __m128 v38; // xmm2
  __m128 v39; // xmm2
  __m128 v40; // xmm1
  __m128 v41; // xmm0
  __m128 v42; // xmm2
  __m128 v43; // xmm1
  __m128 v44; // xmm1
  __m128 *v45; // edi
  __m128 *v46; // ecx
  hk_APL_Query::StateEnum v47; // edx
  __m128 v48; // xmm1
  __m128 v49; // xmm2
  __m128 v50; // xmm2
  __m128 v51; // xmm1
  __m128 v52; // xmm2
  __m128 v53; // xmm0
  __m128 v54; // xmm2
  __m128 v55; // xmm0
  __m128 v56; // xmm2
  __m128 v57; // xmm1
  __m128 v58; // xmm0
  __m128 v59; // xmm1
  __m128 v60; // xmm3
  __m128 v61; // xmm3
  __m128 v62; // xmm1
  __m128 v63; // xmm2
  __m128 v64; // xmm4
  __m128 v65; // xmm2
  __m128 v66; // xmm2
  __m128 v67; // xmm0
  __m128 v68; // xmm6
  __m128 v69; // xmm3
  __m128 v70; // xmm4
  __m128 v71; // xmm1
  __m128 v72; // xmm0
  __m128 v73; // xmm2
  __m128 v74; // xmm3
  __m128 v75; // xmm5
  __m128 v76; // xmm2
  __m128 v77; // xmm2
  __m128 v78; // xmm1
  __m128 v79; // xmm2
  __m128 v80; // xmm0
  __m128 v81; // xmm0
  __m128 *v82; // edi
  __m128 *v83; // ecx
  hk_APL_Query::StateEnum v84; // edx
  __m128 v85; // xmm1
  __m128 v86; // xmm2
  __m128 v87; // xmm2
  __m128 v88; // xmm1
  __m128 v89; // xmm2
  __m128 v90; // xmm0
  __m128 v91; // xmm2
  __m128 v92; // xmm0
  __m128 v93; // xmm2
  __m128 v94; // xmm1
  __m128 v95; // xmm0
  __m128 v96; // xmm1
  __m128 v97; // xmm3
  __m128 v98; // xmm3
  __m128 v99; // xmm1
  __m128 v100; // xmm2
  __m128 v101; // xmm4
  __m128 v102; // xmm2
  __m128 v103; // xmm2
  __m128 v104; // xmm0
  __m128 v105; // xmm6
  __m128 v106; // xmm3
  __m128 v107; // xmm4
  __m128 v108; // xmm1
  __m128 v109; // xmm0
  __m128 v110; // xmm2
  __m128 v111; // xmm3
  __m128 v112; // xmm5
  __m128 v113; // xmm2
  __m128 v114; // xmm2
  __m128 v115; // xmm1
  __m128 v116; // xmm2
  __m128 v117; // xmm0
  __m128 v118; // xmm0
  __m128 v119; // [esp-68h] [ebp-ACh]
  __m128 v120; // [esp-68h] [ebp-ACh]
  __m128 v121; // [esp-68h] [ebp-ACh]
  __m128 v122; // [esp-58h] [ebp-9Ch]
  __m128 v123; // [esp-58h] [ebp-9Ch]
  __m128 v124; // [esp-48h] [ebp-8Ch]
  __m128 i_delta_time_low; // [esp-28h] [ebp-6Ch]
  __m128 v126; // [esp-28h] [ebp-6Ch]
  __m128 v127; // [esp-28h] [ebp-6Ch]
  hk_Rigid_Body *v128; // [esp-Ch] [ebp-50h]
  hk_Rigid_Body *v129; // [esp+14h] [ebp-30h]
  __m128 v130; // [esp+18h] [ebp-2Ch]
  __m128 v131; // [esp+18h] [ebp-2Ch]
  __m128 v132; // [esp+18h] [ebp-2Ch]
  __m128 v133; // [esp+28h] [ebp-1Ch]
  __m128 v134; // [esp+28h] [ebp-1Ch]
  __m128 v135; // [esp+28h] [ebp-1Ch]
  __m128 v136; // [esp+28h] [ebp-1Ch]
  __m128 v137; // [esp+28h] [ebp-1Ch]
  __m128 v138; // [esp+28h] [ebp-1Ch]
  __m128 v139; // [esp+28h] [ebp-1Ch]
  __m128 v140; // [esp+28h] [ebp-1Ch]
  __m128 v141; // [esp+28h] [ebp-1Ch]
  __m128 v142; // [esp+28h] [ebp-1Ch]
  __m128 v143; // [esp+28h] [ebp-1Ch]
  __m128 v144; // [esp+28h] [ebp-1Ch]
  __m128 v145; // [esp+28h] [ebp-1Ch]
  __m128 v146; // [esp+28h] [ebp-1Ch]
  __m128 v147; // [esp+28h] [ebp-1Ch]
  __m128 v148; // [esp+28h] [ebp-1Ch]
  __m128 v149; // [esp+28h] [ebp-1Ch]
  __m128 v150; // [esp+28h] [ebp-1Ch]
  __m128 v151; // [esp+28h] [ebp-1Ch]

  tau_strength_X_twist_factors = work->tau_strength_X_twist_factors;
  v5 = this->m_entities[0];
  physical_core = (__m128 *)v5->physical_core;
  v128 = v5;
  v7 = (__m128 *)this->m_entities[1]->physical_core;
  v129 = this->m_entities[1];
  m_state = work->query_engine_angle_twist.m_state;
  v9 = _mm_mul_ps(
         _mm_shuffle_ps(tau_strength_X_twist_factors, tau_strength_X_twist_factors, 255),
         tau_strength_X_twist_factors);
  v130 = _mm_shuffle_ps(work->joint_angles, work->joint_angles, 0);
  if ( m_state == kStateReady )
  {
    v133 = _mm_mul_ps(v7[12], work->query_engine_angle_twist.m_angular[1]);
    v10 = 0;
    v10.m128_f32[0] = (float)(v133.m128_f32[1] + v133.m128_f32[0]) + v133.m128_f32[2];
    v134 = _mm_mul_ps(physical_core[12], work->query_engine_angle_twist.m_angular[0]);
    v11 = 0;
    v11.m128_f32[0] = (float)(v134.m128_f32[1] + v134.m128_f32[0]) + v134.m128_f32[2];
    v12 = _mm_add_ps(_mm_shuffle_ps(v11, v11, 0), _mm_shuffle_ps(v10, v10, 0));
  }
  else
  {
    if ( m_state == kStateIgnore )
      goto LABEL_14;
    twist_axis_ws = work->twist_axis_ws;
    work->query_engine_angle_twist.m_state = kStateReady;
    v14 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(twist_axis_ws, twist_axis_ws, 170), physical_core[8]),
              _mm_mul_ps(_mm_shuffle_ps(twist_axis_ws, twist_axis_ws, 85), physical_core[7])),
            _mm_mul_ps(_mm_shuffle_ps(twist_axis_ws, twist_axis_ws, 0), physical_core[6]));
    v15 = _mm_sub_ps(Four_Zeros, twist_axis_ws);
    v16 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v15, v15, 170), v7[8]),
              _mm_mul_ps(_mm_shuffle_ps(v15, v15, 85), v7[7])),
            _mm_mul_ps(_mm_shuffle_ps(v15, v15, 0), v7[6]));
    work->query_engine_angle_twist.m_angular[0] = v14;
    work->query_engine_angle_twist.m_angular[1] = v16;
    v17 = Four_Zeros;
    v18 = Four_Zeros;
    if ( (physical_core->m128_i16[0] & 0x12) != 0 )
    {
      work->query_engine_angle_twist.m_delta_spin[0] = Four_Zeros;
    }
    else
    {
      v135 = _mm_mul_ps(physical_core[12], v14);
      v19 = 0;
      v19.m128_f32[0] = (float)(v135.m128_f32[1] + v135.m128_f32[0]) + v135.m128_f32[2];
      v20 = _mm_mul_ps(physical_core[3], v14);
      work->query_engine_angle_twist.m_delta_spin[0] = v20;
      v136 = _mm_mul_ps(v20, v14);
      v21 = 0;
      v21.m128_f32[0] = (float)(v136.m128_f32[1] + v136.m128_f32[0]) + v136.m128_f32[2];
      v18 = _mm_shuffle_ps(v19, v19, 0);
      v17 = _mm_shuffle_ps(v21, v21, 0);
    }
    if ( (v7->m128_i16[0] & 0x12) != 0 )
    {
      work->query_engine_angle_twist.m_delta_spin[1] = Four_Zeros;
    }
    else
    {
      v137 = _mm_mul_ps(v7[12], v16);
      v22 = 0;
      v22.m128_f32[0] = (float)(v137.m128_f32[1] + v137.m128_f32[0]) + v137.m128_f32[2];
      v23 = _mm_mul_ps(v7[3], v16);
      work->query_engine_angle_twist.m_delta_spin[1] = v23;
      v138 = _mm_mul_ps(v23, v16);
      v24 = 0;
      v24.m128_f32[0] = (float)(v138.m128_f32[1] + v138.m128_f32[0]) + v138.m128_f32[2];
      v18 = _mm_add_ps(v18, _mm_shuffle_ps(v22, v22, 0));
      v17 = _mm_add_ps(v17, _mm_shuffle_ps(v24, v24, 0));
    }
    v25 = _mm_rcp_ps(v17);
    work->query_engine_angle_twist.m_invVirtualMass = v17;
    work->query_engine_angle_twist.m_virtualMass = _mm_and_ps(
                                                     _mm_sub_ps(
                                                       _mm_add_ps(v25, v25),
                                                       _mm_mul_ps(_mm_mul_ps(v25, v25), v17)),
                                                     _mm_cmplt_ps(Four_Epsilons, v17));
    v12 = v18;
    work->query_engine_angle_twist.m_maskLimit = *(__m128 *)&s_limit_mask_1[this->m_limits[0].m_limit_is_enabled][0];
  }
  v26 = Four_Zeros;
  delta_time_low = (__m128)LODWORD(pi->delta_time);
  v28 = _mm_shuffle_ps(
          (__m128)LODWORD(this->m_limits[0].m_ref_position),
          (__m128)LODWORD(this->m_limits[0].m_ref_position),
          0);
  v139 = v12;
  v29 = Four_Zeros;
  v124 = v28;
  v119 = delta_time_low;
  i_delta_time_low = (__m128)LODWORD(pi->i_delta_time);
  if ( this->m_limits[0].m_friction_is_enabled )
  {
    v30 = _mm_sub_ps(v28, v130);
    delta_time_low = (__m128)LODWORD(pi->delta_time);
    v31 = _mm_cmplt_ps(v30, _mm_sub_ps(Four_Zeros, s_pi_1));
    v32 = _mm_cmplt_ps(s_pi_1, v30);
    v33 = _mm_or_ps(
            _mm_andnot_ps(
              v32,
              _mm_or_ps(_mm_and_ps(_mm_sub_ps(Four_Zeros, s_2_pi_1), v31), _mm_andnot_ps(v31, Four_Zeros))),
            _mm_and_ps(v32, s_2_pi_1));
    v34 = _mm_sub_ps(v30, v33);
    v130 = _mm_add_ps(v33, v130);
    v35 = _mm_mul_ps(
            _mm_sub_ps(
              _mm_mul_ps(_mm_mul_ps(_mm_mul_ps(s_friction_tau_factor_1, v9), v34), i_delta_time_low),
              _mm_mul_ps(_mm_shuffle_ps(v9, v9, 85), v139)),
            work->query_engine_angle_twist.m_virtualMass);
    v36 = _mm_rcp_ps(v35);
    v37 = _mm_mul_ps(
            _mm_and_ps(
              _mm_sub_ps(_mm_add_ps(v36, v36), _mm_mul_ps(_mm_mul_ps(v36, v36), v35)),
              *(__m128 *)g_SIMD_clear_signmask),
            _mm_mul_ps(
              _mm_shuffle_ps(
                (__m128)LODWORD(this->m_limits[0].m_joint_friction),
                (__m128)LODWORD(this->m_limits[0].m_joint_friction),
                0),
              v119));
    v38 = _mm_cmplt_ps(v37, Four_Ones);
    v39 = _mm_or_ps(_mm_and_ps(v38, v37), _mm_andnot_ps(v38, Four_Ones));
    v40 = v39;
    v34.m128_f32[0] = v34.m128_f32[0] - (float)(v39.m128_f32[0] * v34.m128_f32[0]);
    v12 = v139;
    v29 = _mm_mul_ps(v40, v35);
    LODWORD(this->m_limits[0].m_ref_position) = COERCE_UNSIGNED_INT(
                                                  (float)((float)(_mm_shuffle_ps(
                                                                    (__m128)LODWORD(this->m_limits[0].m_desired_velocity),
                                                                    (__m128)LODWORD(this->m_limits[0].m_desired_velocity),
                                                                    0).m128_f32[0]
                                                                * v119.m128_f32[0])
                                                        + v124.m128_f32[0])
                                                - v34.m128_f32[0])
                                              & g_SIMD_ComponentMask[0][0]
                                              | _mm_andnot_ps(*(__m128 *)&g_SIMD_ComponentMask[0][0], v124).m128_u32[0];
    v26 = Four_Zeros;
  }
  v41 = _mm_add_ps(
          _mm_mul_ps(_mm_add_ps(_mm_mul_ps(work->query_engine_angle_twist.m_invVirtualMass, v29), v12), delta_time_low),
          v130);
  v42 = _mm_mul_ps(
          _mm_mul_ps(
            _mm_shuffle_ps(
              (__m128)LODWORD(this->m_limits[0].m_limit_tau),
              (__m128)LODWORD(this->m_limits[0].m_limit_tau),
              0),
            v9),
          _mm_mul_ps(work->query_engine_angle_twist.m_virtualMass, i_delta_time_low));
  v43 = _mm_sub_ps(
          v29,
          _mm_and_ps(
            _mm_add_ps(
              _mm_min_ps(
                _mm_mul_ps(
                  _mm_sub_ps(
                    v41,
                    _mm_shuffle_ps(
                      (__m128)LODWORD(this->m_limits[0].m_limit_min),
                      (__m128)LODWORD(this->m_limits[0].m_limit_min),
                      0)),
                  v42),
                v26),
              _mm_max_ps(
                _mm_mul_ps(
                  _mm_sub_ps(
                    v41,
                    _mm_shuffle_ps(
                      (__m128)LODWORD(this->m_limits[0].m_limit_max),
                      (__m128)LODWORD(this->m_limits[0].m_limit_max),
                      0)),
                  v42),
                v26)),
            work->query_engine_angle_twist.m_maskLimit));
  v44 = _mm_shuffle_ps(v43, v43, 0);
  physical_core[12] = _mm_and_ps(
                        _mm_add_ps(_mm_mul_ps(work->query_engine_angle_twist.m_delta_spin[0], v44), physical_core[12]),
                        *(__m128 *)g_SIMD_clear_wmask);
  v7[12] = _mm_and_ps(
             _mm_add_ps(_mm_mul_ps(work->query_engine_angle_twist.m_delta_spin[1], v44), v7[12]),
             *(__m128 *)g_SIMD_clear_wmask);
LABEL_14:
  v45 = (__m128 *)v128->physical_core;
  v46 = (__m128 *)v129->physical_core;
  v47 = work->query_engine_angle_planes.m_state;
  v122 = _mm_shuffle_ps(work->joint_angles, work->joint_angles, 170);
  if ( v47 == kStateReady )
  {
    v140 = _mm_mul_ps(v46[12], work->query_engine_angle_planes.m_angular[1]);
    v48 = 0;
    v48.m128_f32[0] = (float)(v140.m128_f32[1] + v140.m128_f32[0]) + v140.m128_f32[2];
    v141 = _mm_mul_ps(v45[12], work->query_engine_angle_planes.m_angular[0]);
    v49 = 0;
    v49.m128_f32[0] = (float)(v141.m128_f32[1] + v141.m128_f32[0]) + v141.m128_f32[2];
    v50 = _mm_add_ps(_mm_shuffle_ps(v49, v49, 0), _mm_shuffle_ps(v48, v48, 0));
  }
  else
  {
    if ( v47 == kStateIgnore )
      goto LABEL_29;
    v51 = _mm_sub_ps(
            _mm_mul_ps(
              _mm_shuffle_ps(work->twist_axis_Att_ws, work->twist_axis_Att_ws, 9),
              _mm_shuffle_ps(work->plane_Axis_Ref_ws, work->plane_Axis_Ref_ws, 18)),
            _mm_mul_ps(
              _mm_shuffle_ps(work->twist_axis_Att_ws, work->twist_axis_Att_ws, 18),
              _mm_shuffle_ps(work->plane_Axis_Ref_ws, work->plane_Axis_Ref_ws, 9)));
    v131 = _mm_mul_ps(v51, v51);
    v52 = 0;
    v52.m128_f32[0] = (float)((float)(v131.m128_f32[1] + v131.m128_f32[0]) + v131.m128_f32[2]) + v131.m128_f32[3];
    v53 = _mm_shuffle_ps(v52, v52, 0);
    if ( _mm_movemask_ps(_mm_cmple_ps(v53, g_scalar4_hk_epsilon)) != 0 )
    {
      work->query_engine_angle_planes.m_state = kStateIgnore;
      goto LABEL_29;
    }
    v54 = _mm_rsqrt_ps(v53);
    v55 = _mm_mul_ps(
            _mm_max_ps(
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_mul_ps(_mm_sub_ps(Four_Threes, _mm_mul_ps(_mm_mul_ps(v54, v54), v53)), v54),
                  Four_PointFives),
                s_scalar_min_cross_length_1),
              Four_Ones),
            v51);
    work->query_engine_angle_planes.m_state = kStateReady;
    v56 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v55, v55, 170), v45[8]),
              _mm_mul_ps(_mm_shuffle_ps(v55, v55, 85), v45[7])),
            _mm_mul_ps(_mm_shuffle_ps(v55, v55, 0), v45[6]));
    v57 = _mm_sub_ps(Four_Zeros, v55);
    v58 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v57, v57, 170), v46[8]),
              _mm_mul_ps(_mm_shuffle_ps(v57, v57, 85), v46[7])),
            _mm_mul_ps(_mm_shuffle_ps(v57, v57, 0), v46[6]));
    work->query_engine_angle_planes.m_angular[0] = v56;
    work->query_engine_angle_planes.m_angular[1] = v58;
    v59 = Four_Zeros;
    v60 = Four_Zeros;
    if ( (v45->m128_i16[0] & 0x12) != 0 )
    {
      work->query_engine_angle_planes.m_delta_spin[0] = Four_Zeros;
    }
    else
    {
      v142 = _mm_mul_ps(v45[12], v56);
      v61 = 0;
      v61.m128_f32[0] = (float)(v142.m128_f32[1] + v142.m128_f32[0]) + v142.m128_f32[2];
      v62 = _mm_mul_ps(v45[3], v56);
      work->query_engine_angle_planes.m_delta_spin[0] = v62;
      v143 = _mm_mul_ps(v62, v56);
      v63 = 0;
      v63.m128_f32[0] = (float)(v143.m128_f32[1] + v143.m128_f32[0]) + v143.m128_f32[2];
      v60 = _mm_shuffle_ps(v61, v61, 0);
      v59 = _mm_shuffle_ps(v63, v63, 0);
    }
    if ( (v46->m128_i16[0] & 0x12) != 0 )
    {
      work->query_engine_angle_planes.m_delta_spin[1] = Four_Zeros;
    }
    else
    {
      v144 = _mm_mul_ps(v46[12], v58);
      v64 = 0;
      v64.m128_f32[0] = (float)(v144.m128_f32[1] + v144.m128_f32[0]) + v144.m128_f32[2];
      v65 = _mm_mul_ps(v46[3], v58);
      work->query_engine_angle_planes.m_delta_spin[1] = v65;
      v145 = _mm_mul_ps(v65, v58);
      v66 = 0;
      v66.m128_f32[0] = (float)(v145.m128_f32[1] + v145.m128_f32[0]) + v145.m128_f32[2];
      v60 = _mm_add_ps(v60, _mm_shuffle_ps(v64, v64, 0));
      v59 = _mm_add_ps(v59, _mm_shuffle_ps(v66, v66, 0));
    }
    v67 = _mm_rcp_ps(v59);
    work->query_engine_angle_planes.m_invVirtualMass = v59;
    work->query_engine_angle_planes.m_virtualMass = _mm_and_ps(
                                                      _mm_sub_ps(
                                                        _mm_add_ps(v67, v67),
                                                        _mm_mul_ps(_mm_mul_ps(v67, v67), v59)),
                                                      _mm_cmplt_ps(Four_Epsilons, v59));
    v50 = v60;
    work->query_engine_angle_planes.m_maskLimit = *(__m128 *)&s_limit_mask_1[this->m_limits[2].m_limit_is_enabled][0];
  }
  v68 = (__m128)LODWORD(pi->delta_time);
  v69 = Four_Zeros;
  v126 = v50;
  v70 = _mm_shuffle_ps(
          (__m128)LODWORD(this->m_limits[2].m_ref_position),
          (__m128)LODWORD(this->m_limits[2].m_ref_position),
          0);
  v120 = (__m128)LODWORD(pi->i_delta_time);
  if ( this->m_limits[2].m_friction_is_enabled )
  {
    v71 = _mm_sub_ps(v122, v70);
    v72 = _mm_max_ps(
            _mm_mul_ps(
              _mm_sub_ps(
                _mm_mul_ps(
                  _mm_mul_ps(_mm_mul_ps(s_friction_tau_factor_1, tau_strength_X_twist_factors), v71),
                  (__m128)LODWORD(pi->i_delta_time)),
                _mm_mul_ps(_mm_shuffle_ps(tau_strength_X_twist_factors, tau_strength_X_twist_factors, 85), v50)),
              work->query_engine_angle_planes.m_virtualMass),
            Four_Epsilons);
    v73 = _mm_and_ps(*(__m128 *)g_SIMD_clear_signmask, v72);
    v74 = _mm_rcp_ps(v73);
    v75 = _mm_mul_ps(_mm_mul_ps(v74, v74), v73);
    v76 = _mm_mul_ps(
            _mm_shuffle_ps(
              (__m128)LODWORD(this->m_limits[2].m_joint_friction),
              (__m128)LODWORD(this->m_limits[2].m_joint_friction),
              0),
            v68);
    v68 = (__m128)LODWORD(pi->delta_time);
    v77 = _mm_min_ps(Four_Ones, _mm_mul_ps(_mm_sub_ps(_mm_add_ps(v74, v74), v75), v76));
    v69 = _mm_mul_ps(v77, v72);
    v71.m128_f32[0] = v71.m128_f32[0] - (float)(v77.m128_f32[0] * v71.m128_f32[0]);
    v50 = v126;
    LODWORD(this->m_limits[2].m_ref_position) = COERCE_UNSIGNED_INT(
                                                  (float)((float)(_mm_shuffle_ps(
                                                                    (__m128)LODWORD(this->m_limits[2].m_desired_velocity),
                                                                    (__m128)LODWORD(this->m_limits[2].m_desired_velocity),
                                                                    0).m128_f32[0]
                                                                * pi->delta_time)
                                                        + v70.m128_f32[0])
                                                + v71.m128_f32[0])
                                              & g_SIMD_ComponentMask[0][0]
                                              | _mm_andnot_ps(*(__m128 *)&g_SIMD_ComponentMask[0][0], v70).m128_u32[0];
  }
  v78 = _mm_sub_ps(
          v122,
          _mm_mul_ps(_mm_add_ps(_mm_mul_ps(work->query_engine_angle_planes.m_invVirtualMass, v69), v50), v68));
  v79 = _mm_mul_ps(
          _mm_mul_ps(
            _mm_shuffle_ps(
              (__m128)LODWORD(this->m_limits[2].m_limit_tau),
              (__m128)LODWORD(this->m_limits[2].m_limit_tau),
              0),
            tau_strength_X_twist_factors),
          _mm_mul_ps(work->query_engine_angle_planes.m_virtualMass, v120));
  v80 = _mm_add_ps(
          _mm_and_ps(
            _mm_add_ps(
              _mm_min_ps(
                _mm_mul_ps(
                  _mm_sub_ps(
                    v78,
                    _mm_shuffle_ps(
                      (__m128)LODWORD(this->m_limits[2].m_limit_min),
                      (__m128)LODWORD(this->m_limits[2].m_limit_min),
                      0)),
                  v79),
                Four_Zeros),
              _mm_max_ps(
                _mm_mul_ps(
                  _mm_sub_ps(
                    v78,
                    _mm_shuffle_ps(
                      (__m128)LODWORD(this->m_limits[2].m_limit_max),
                      (__m128)LODWORD(this->m_limits[2].m_limit_max),
                      0)),
                  v79),
                Four_Zeros)),
            work->query_engine_angle_planes.m_maskLimit),
          v69);
  v81 = _mm_shuffle_ps(v80, v80, 0);
  v45[12] = _mm_and_ps(
              _mm_add_ps(_mm_mul_ps(work->query_engine_angle_planes.m_delta_spin[0], v81), v45[12]),
              *(__m128 *)g_SIMD_clear_wmask);
  v46[12] = _mm_and_ps(
              _mm_add_ps(_mm_mul_ps(work->query_engine_angle_planes.m_delta_spin[1], v81), v46[12]),
              *(__m128 *)g_SIMD_clear_wmask);
LABEL_29:
  v82 = (__m128 *)v128->physical_core;
  v83 = (__m128 *)v129->physical_core;
  v84 = work->query_engine_angle_cone.m_state;
  v127 = _mm_shuffle_ps(work->joint_angles, work->joint_angles, 85);
  if ( v84 == kStateReady )
  {
    v146 = _mm_mul_ps(v83[12], work->query_engine_angle_cone.m_angular[1]);
    v85 = 0;
    v85.m128_f32[0] = (float)(v146.m128_f32[1] + v146.m128_f32[0]) + v146.m128_f32[2];
    v147 = _mm_mul_ps(v82[12], work->query_engine_angle_cone.m_angular[0]);
    v86 = 0;
    v86.m128_f32[0] = (float)(v147.m128_f32[1] + v147.m128_f32[0]) + v147.m128_f32[2];
    v87 = _mm_add_ps(_mm_shuffle_ps(v86, v86, 0), _mm_shuffle_ps(v85, v85, 0));
  }
  else
  {
    if ( v84 == kStateIgnore )
      return;
    v88 = _mm_sub_ps(
            _mm_mul_ps(
              _mm_shuffle_ps(work->twist_axis_Att_ws, work->twist_axis_Att_ws, 9),
              _mm_shuffle_ps(work->twist_axis_Ref_ws, work->twist_axis_Ref_ws, 18)),
            _mm_mul_ps(
              _mm_shuffle_ps(work->twist_axis_Att_ws, work->twist_axis_Att_ws, 18),
              _mm_shuffle_ps(work->twist_axis_Ref_ws, work->twist_axis_Ref_ws, 9)));
    v132 = _mm_mul_ps(v88, v88);
    v89 = 0;
    v89.m128_f32[0] = (float)((float)(v132.m128_f32[1] + v132.m128_f32[0]) + v132.m128_f32[2]) + v132.m128_f32[3];
    v90 = _mm_shuffle_ps(v89, v89, 0);
    if ( _mm_movemask_ps(_mm_cmple_ps(v90, g_scalar4_hk_epsilon)) != 0 )
    {
      work->query_engine_angle_cone.m_state = kStateIgnore;
      return;
    }
    v91 = _mm_rsqrt_ps(v90);
    v92 = _mm_mul_ps(
            _mm_max_ps(
              _mm_mul_ps(
                _mm_mul_ps(
                  _mm_mul_ps(_mm_sub_ps(Four_Threes, _mm_mul_ps(_mm_mul_ps(v91, v91), v90)), v91),
                  Four_PointFives),
                s_scalar_min_cross_length_1),
              Four_Ones),
            v88);
    work->query_engine_angle_cone.m_state = kStateReady;
    v93 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v92, v92, 170), v82[8]),
              _mm_mul_ps(_mm_shuffle_ps(v92, v92, 85), v82[7])),
            _mm_mul_ps(_mm_shuffle_ps(v92, v92, 0), v82[6]));
    v94 = _mm_sub_ps(Four_Zeros, v92);
    v95 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v94, v94, 170), v83[8]),
              _mm_mul_ps(_mm_shuffle_ps(v94, v94, 85), v83[7])),
            _mm_mul_ps(_mm_shuffle_ps(v94, v94, 0), v83[6]));
    work->query_engine_angle_cone.m_angular[0] = v93;
    work->query_engine_angle_cone.m_angular[1] = v95;
    v96 = Four_Zeros;
    v97 = Four_Zeros;
    if ( (v82->m128_i16[0] & 0x12) != 0 )
    {
      work->query_engine_angle_cone.m_delta_spin[0] = Four_Zeros;
    }
    else
    {
      v148 = _mm_mul_ps(v82[12], v93);
      v98 = 0;
      v98.m128_f32[0] = (float)(v148.m128_f32[1] + v148.m128_f32[0]) + v148.m128_f32[2];
      v99 = _mm_mul_ps(v82[3], v93);
      work->query_engine_angle_cone.m_delta_spin[0] = v99;
      v149 = _mm_mul_ps(v99, v93);
      v100 = 0;
      v100.m128_f32[0] = (float)(v149.m128_f32[1] + v149.m128_f32[0]) + v149.m128_f32[2];
      v97 = _mm_shuffle_ps(v98, v98, 0);
      v96 = _mm_shuffle_ps(v100, v100, 0);
    }
    if ( (v83->m128_i16[0] & 0x12) != 0 )
    {
      work->query_engine_angle_cone.m_delta_spin[1] = Four_Zeros;
    }
    else
    {
      v150 = _mm_mul_ps(v83[12], v95);
      v101 = 0;
      v101.m128_f32[0] = (float)(v150.m128_f32[1] + v150.m128_f32[0]) + v150.m128_f32[2];
      v102 = _mm_mul_ps(v83[3], v95);
      work->query_engine_angle_cone.m_delta_spin[1] = v102;
      v151 = _mm_mul_ps(v102, v95);
      v103 = 0;
      v103.m128_f32[0] = (float)(v151.m128_f32[1] + v151.m128_f32[0]) + v151.m128_f32[2];
      v97 = _mm_add_ps(v97, _mm_shuffle_ps(v101, v101, 0));
      v96 = _mm_add_ps(v96, _mm_shuffle_ps(v103, v103, 0));
    }
    v104 = _mm_rcp_ps(v96);
    work->query_engine_angle_cone.m_invVirtualMass = v96;
    work->query_engine_angle_cone.m_virtualMass = _mm_and_ps(
                                                    _mm_sub_ps(
                                                      _mm_add_ps(v104, v104),
                                                      _mm_mul_ps(_mm_mul_ps(v104, v104), v96)),
                                                    _mm_cmplt_ps(Four_Epsilons, v96));
    v87 = v97;
    work->query_engine_angle_cone.m_maskLimit = *(__m128 *)&s_limit_mask_1[this->m_limits[1].m_limit_is_enabled][0];
  }
  v105 = (__m128)LODWORD(pi->delta_time);
  v106 = Four_Zeros;
  v123 = v87;
  v107 = _mm_shuffle_ps(
           (__m128)LODWORD(this->m_limits[1].m_ref_position),
           (__m128)LODWORD(this->m_limits[1].m_ref_position),
           0);
  v121 = (__m128)LODWORD(pi->i_delta_time);
  if ( this->m_limits[1].m_friction_is_enabled )
  {
    v108 = _mm_sub_ps(v127, v107);
    v109 = _mm_max_ps(
             _mm_mul_ps(
               _mm_sub_ps(
                 _mm_mul_ps(
                   _mm_mul_ps(_mm_mul_ps(s_friction_tau_factor_1, tau_strength_X_twist_factors), v108),
                   (__m128)LODWORD(pi->i_delta_time)),
                 _mm_mul_ps(_mm_shuffle_ps(tau_strength_X_twist_factors, tau_strength_X_twist_factors, 85), v87)),
               work->query_engine_angle_cone.m_virtualMass),
             Four_Epsilons);
    v110 = _mm_and_ps(*(__m128 *)g_SIMD_clear_signmask, v109);
    v111 = _mm_rcp_ps(v110);
    v112 = _mm_mul_ps(_mm_mul_ps(v111, v111), v110);
    v113 = _mm_mul_ps(
             _mm_shuffle_ps(
               (__m128)LODWORD(this->m_limits[1].m_joint_friction),
               (__m128)LODWORD(this->m_limits[1].m_joint_friction),
               0),
             v105);
    v105 = (__m128)LODWORD(pi->delta_time);
    v114 = _mm_min_ps(Four_Ones, _mm_mul_ps(_mm_sub_ps(_mm_add_ps(v111, v111), v112), v113));
    v106 = _mm_mul_ps(v114, v109);
    v108.m128_f32[0] = v108.m128_f32[0] - (float)(v114.m128_f32[0] * v108.m128_f32[0]);
    v87 = v123;
    LODWORD(this->m_limits[1].m_ref_position) = COERCE_UNSIGNED_INT(
                                                  (float)((float)(_mm_shuffle_ps(
                                                                    (__m128)LODWORD(this->m_limits[1].m_desired_velocity),
                                                                    (__m128)LODWORD(this->m_limits[1].m_desired_velocity),
                                                                    0).m128_f32[0]
                                                                * pi->delta_time)
                                                        + v107.m128_f32[0])
                                                + v108.m128_f32[0])
                                              & g_SIMD_ComponentMask[0][0]
                                              | _mm_andnot_ps(*(__m128 *)&g_SIMD_ComponentMask[0][0], v107).m128_u32[0];
  }
  v115 = _mm_sub_ps(
           v127,
           _mm_mul_ps(_mm_add_ps(_mm_mul_ps(work->query_engine_angle_cone.m_invVirtualMass, v106), v87), v105));
  v116 = _mm_mul_ps(
           _mm_mul_ps(
             _mm_shuffle_ps(
               (__m128)LODWORD(this->m_limits[1].m_limit_tau),
               (__m128)LODWORD(this->m_limits[1].m_limit_tau),
               0),
             tau_strength_X_twist_factors),
           _mm_mul_ps(work->query_engine_angle_cone.m_virtualMass, v121));
  v117 = _mm_add_ps(
           _mm_and_ps(
             _mm_add_ps(
               _mm_min_ps(
                 _mm_mul_ps(
                   _mm_sub_ps(
                     v115,
                     _mm_shuffle_ps(
                       (__m128)LODWORD(this->m_limits[1].m_limit_min),
                       (__m128)LODWORD(this->m_limits[1].m_limit_min),
                       0)),
                   v116),
                 Four_Zeros),
               _mm_max_ps(
                 _mm_mul_ps(
                   _mm_sub_ps(
                     v115,
                     _mm_shuffle_ps(
                       (__m128)LODWORD(this->m_limits[1].m_limit_max),
                       (__m128)LODWORD(this->m_limits[1].m_limit_max),
                       0)),
                   v116),
                 Four_Zeros)),
             work->query_engine_angle_cone.m_maskLimit),
           v106);
  v118 = _mm_shuffle_ps(v117, v117, 0);
  v82[12] = _mm_and_ps(
              _mm_add_ps(_mm_mul_ps(work->query_engine_angle_cone.m_delta_spin[0], v118), v82[12]),
              *(__m128 *)g_SIMD_clear_wmask);
  v83[12] = _mm_and_ps(
              _mm_add_ps(_mm_mul_ps(work->query_engine_angle_cone.m_delta_spin[1], v118), v83[12]),
              *(__m128 *)g_SIMD_clear_wmask);
}

//------------------------------------------------------------------------------
// Address: 0x1003F350
// Name: union __m128 ArcTan2Alt(union __m128,union __m128)
// Source: json
//------------------------------------------------------------------------------
void ArcTan2Alt()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1003F490
// Name: public: virtual void hk_Ragdoll_Constraint::step_constraint(class hk_PSI_Info __near &,void __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Ragdoll_Constraint::step_constraint(
        hk_Ragdoll_Constraint *this,
        hk_PSI_Info *pi,
        void *mem,
        unsigned __int64 tau_factor)
{
  __m128 *v5; // eax
  __m128 rot_speed; // xmm2
  __m128 v7; // xmm0
  __m128 v8; // xmm1
  __m128 v9; // xmm1
  __m128 v10; // xmm0
  __m128 v11; // xmm1
  __m128 inv_rot_inertia; // xmm1
  __m128 v13; // [esp-Ch] [ebp-4Ch]
  __m128 v14; // [esp-Ch] [ebp-4Ch]
  IVP_Core *physical_core; // [esp+14h] [ebp-2Ch]
  __m128 *p_rot_speed; // [esp+14h] [ebp-2Ch]
  IVP_Core *v17; // [esp+30h] [ebp-10h]

  v13.m128_u64[0] = tau_factor;
  v13.m128_u64[1] = 1621981420;
  physical_core = this->m_entities[0]->physical_core;
  v17 = this->m_entities[1]->physical_core;
  v14 = _mm_or_ps(
          _mm_and_ps(*((__m128 *)mem + 17), (__m128)xmmword_100DAD40),
          _mm_andnot_ps((__m128)xmmword_100DAD40, v13));
  *((__m128 *)mem + 45) = v14;
  hk_Ragdoll_Constraint::apply_angular_part(this, pi, work: (hk_Ragdoll_Constraint_Work *)mem);
  if ( this->m_constrainTranslation != 0 )
  {
    v5 = (__m128 *)physical_core;
    rot_speed = (__m128)physical_core->rot_speed;
    p_rot_speed = (__m128 *)&physical_core->rot_speed;
    v7 = (__m128)v17->rot_speed;
    v8 = _mm_mul_ps(_mm_mul_ps((__m128)LODWORD(this->m_tau), v14), (__m128)LODWORD(pi->i_delta_time));
    v9 = _mm_sub_ps(
           _mm_mul_ps(_mm_shuffle_ps(v8, v8, 0), _mm_and_ps(*(__m128 *)mem, *(__m128 *)g_SIMD_clear_wmask)),
           _mm_mul_ps(
             _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_sub_ps(Four_Zeros, (__m128)v17->speed),
                     _mm_mul_ps(_mm_shuffle_ps(v7, v7, 170), *((__m128 *)mem + 6))),
                   _mm_mul_ps(_mm_shuffle_ps(v7, v7, 85), *((__m128 *)mem + 5))),
                 _mm_mul_ps(_mm_shuffle_ps(v7, v7, 0), *((__m128 *)mem + 4))),
               _mm_add_ps(
                 _mm_add_ps(
                   _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(rot_speed, rot_speed, 170), *((__m128 *)mem + 3)), v5[13]),
                   _mm_mul_ps(_mm_shuffle_ps(rot_speed, rot_speed, 85), *((__m128 *)mem + 2))),
                 _mm_mul_ps(_mm_shuffle_ps(rot_speed, rot_speed, 0), *((__m128 *)mem + 1)))),
             _mm_mul_ps(
               _mm_shuffle_ps((__m128)LODWORD(this->m_strength), (__m128)LODWORD(this->m_strength), 0),
               _mm_shuffle_ps(v14, v14, 85))));
    v10 = _mm_add_ps(
            _mm_add_ps(
              _mm_mul_ps(_mm_shuffle_ps(v9, v9, 170), *((__m128 *)mem + 15)),
              _mm_mul_ps(_mm_shuffle_ps(v9, v9, 85), *((__m128 *)mem + 14))),
            _mm_mul_ps(_mm_shuffle_ps(v9, v9, 0), *((__m128 *)mem + 13)));
    if ( (v5->m128_i16[0] & 0x12) == 0 )
    {
      v11 = v5[3];
      *p_rot_speed = _mm_and_ps(
                       _mm_add_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_mul_ps(_mm_shuffle_ps(v10, v10, 170), *((__m128 *)mem + 9)),
                             _mm_mul_ps(_mm_shuffle_ps(v10, v10, 85), *((__m128 *)mem + 8))),
                           _mm_mul_ps(_mm_shuffle_ps(v10, v10, 0), *((__m128 *)mem + 7))),
                         rot_speed),
                       *(__m128 *)g_SIMD_clear_wmask);
      v5[13] = _mm_and_ps(
                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v11, v11, 255), v10), v5[13]),
                 *(__m128 *)g_SIMD_clear_wmask);
    }
    if ( (*(_WORD *)&v17->IVP_Core_Fast_Static & 0x12) == 0 )
    {
      inv_rot_inertia = (__m128)v17->inv_rot_inertia;
      v17->rot_speed = (IVP_U_Float_Point)_mm_and_ps(
                                            _mm_add_ps(
                                              _mm_add_ps(
                                                _mm_add_ps(
                                                  _mm_mul_ps(_mm_shuffle_ps(v10, v10, 170), *((__m128 *)mem + 12)),
                                                  _mm_mul_ps(_mm_shuffle_ps(v10, v10, 85), *((__m128 *)mem + 11))),
                                                _mm_mul_ps(_mm_shuffle_ps(v10, v10, 0), *((__m128 *)mem + 10))),
                                              (__m128)v17->rot_speed),
                                            *(__m128 *)g_SIMD_clear_wmask);
      v17->speed = (IVP_U_Float_Point)_mm_and_ps(
                                        _mm_add_ps(
                                          _mm_mul_ps(
                                            _mm_shuffle_ps(inv_rot_inertia, inv_rot_inertia, 255),
                                            _mm_sub_ps(Four_Zeros, v10)),
                                          (__m128)v17->speed),
                                        *(__m128 *)g_SIMD_clear_wmask);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F710
// Name: public: void hk_Ragdoll_Constraint::init_ragdoll_constraint(class hk_Ragdoll_Constraint_BP const __near *,class hk_Local_Constraint_System __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge hk_Ragdoll_Constraint::init_ragdoll_constraint(
        hk_Ragdoll_Constraint *this@<ecx>,
        int a2@<edi>,
        const hk_Ragdoll_Constraint_BP *bp,
        hk_Local_Constraint_System *sys)
{
  hk_Transform *m_transform_os_ks; // ecx
  float v6; // xmm1_4
  float m_limit_max; // xmm1_4
  float angle; // xmm0_4
  float v9; // xmm1_4
  double v10; // xmm0_8
  double m_limit_min; // xmm0_8
  long double v12; // [esp+4h] [ebp-8h]
  long double v13; // [esp+4h] [ebp-8h]
  long double v14; // [esp+4h] [ebp-8h]

  LODWORD(v12) = a2;
  this->m_transform_os_ks[0].hk_Rotation = bp->m_transform_os_ks[0].hk_Rotation;
  this->m_transform_os_ks[0].m_translation.x = bp->m_transform_os_ks[0].m_translation.x;
  m_transform_os_ks = this->m_transform_os_ks;
  m_transform_os_ks->m_translation.y = bp->m_transform_os_ks[0].m_translation.y;
  m_transform_os_ks->m_translation.z = bp->m_transform_os_ks[0].m_translation.z;
  this->m_transform_os_ks[1].hk_Rotation = bp->m_transform_os_ks[1].hk_Rotation;
  this->m_transform_os_ks[1].m_translation.x = bp->m_transform_os_ks[1].m_translation.x;
  this->m_transform_os_ks[1].m_translation.y = bp->m_transform_os_ks[1].m_translation.y;
  this->m_transform_os_ks[1].m_translation.z = bp->m_transform_os_ks[1].m_translation.z;
  this->m_tau = bp->m_tau;
  this->m_strength = bp->m_strength;
  this->m_constrainTranslation = bp->m_constrainTranslation;
  this->m_axisMap[0] = bp->m_axisMap[0];
  this->m_axisMap[1] = bp->m_axisMap[1];
  this->m_axisMap[2] = bp->m_axisMap[2];
  this->m_limits[0].m_limit_is_enabled = bp->m_limits[0].m_limit_is_enabled;
  this->m_limits[0].m_friction_is_enabled = bp->m_limits[0].m_friction_is_enabled;
  this->m_limits[0].m_limit_min = bp->m_limits[0].m_limit_min;
  this->m_limits[0].m_limit_max = bp->m_limits[0].m_limit_max;
  v6 = this->m_limits[0].m_limit_max - this->m_limits[0].m_limit_min;
  this->m_limits[0].m_limit_tau = bp->m_limits[0].m_limit_tau;
  this->m_limits[0].m_joint_friction = fabs(bp->m_limits[0].m_joint_friction);
  this->m_limits[0].m_desired_velocity = bp->m_limits[0].m_desired_velocity;
  if ( v6 >= 6.2831855 )
    this->m_limits[0].m_limit_is_enabled = false;
  this->m_limits[1].m_limit_is_enabled = bp->m_limits[1].m_limit_is_enabled;
  this->m_limits[1].m_friction_is_enabled = bp->m_limits[1].m_friction_is_enabled;
  this->m_limits[1].m_limit_min = bp->m_limits[1].m_limit_min;
  this->m_limits[1].m_limit_max = bp->m_limits[1].m_limit_max;
  this->m_limits[1].m_limit_tau = bp->m_limits[1].m_limit_tau;
  this->m_limits[1].m_joint_friction = fabs(bp->m_limits[1].m_joint_friction);
  this->m_limits[1].m_desired_velocity = bp->m_limits[1].m_desired_velocity;
  if ( (float)(this->m_limits[1].m_limit_max - this->m_limits[1].m_limit_min) >= 6.2831855 )
    this->m_limits[1].m_limit_is_enabled = false;
  this->m_limits[2].m_limit_is_enabled = bp->m_limits[2].m_limit_is_enabled;
  this->m_limits[2].m_friction_is_enabled = bp->m_limits[2].m_friction_is_enabled;
  this->m_limits[2].m_limit_min = bp->m_limits[2].m_limit_min;
  this->m_limits[2].m_limit_max = bp->m_limits[2].m_limit_max;
  this->m_limits[2].m_limit_tau = bp->m_limits[2].m_limit_tau;
  this->m_limits[2].m_joint_friction = fabs(bp->m_limits[2].m_joint_friction);
  this->m_limits[2].m_desired_velocity = bp->m_limits[2].m_desired_velocity;
  if ( (float)(this->m_limits[2].m_limit_max - this->m_limits[2].m_limit_min) >= 6.2831855 )
    this->m_limits[2].m_limit_is_enabled = false;
  m_limit_max = bp->m_limits[1].m_limit_max;
  angle = (float)(bp->m_limits[1].m_limit_min + m_limit_max) * 0.5;
  v9 = m_limit_max - bp->m_limits[1].m_limit_min;
  if ( fabs(angle) > 0.001 )
    hk_Matrix3::rotate(this: m_transform_os_ks, axis: 2, angle);
  __libm_sse2_cos(x: v12);
  this->m_limits[1].m_limit_min = v9 * 0.5;
  this->m_limits[1].m_limit_max = 100.0;
  v10 = bp->m_limits[2].m_limit_max;
  __libm_sse2_sin(x: v13);
  *(float *)&v10 = v10;
  LODWORD(this->m_limits[2].m_limit_min) = LODWORD(v10) ^ _mask__NegFloat_;
  m_limit_min = bp->m_limits[2].m_limit_min;
  __libm_sse2_sin(x: v14);
  *(float *)&m_limit_min = m_limit_min;
  LODWORD(this->m_limits[2].m_limit_max) = LODWORD(m_limit_min) ^ _mask__NegFloat_;
  qmemcpy(this->m_inputLimits, bp->m_limits, sizeof(this->m_inputLimits));
}

//------------------------------------------------------------------------------
// Address: 0x1003FAE0
// Name: public: hk_Ragdoll_Constraint::hk_Ragdoll_Constraint(class hk_Environment __near *,class hk_Ragdoll_Constraint_BP const __near *,class hk_Rigid_Body __near *,class hk_Rigid_Body __near *)
// Source: json
//------------------------------------------------------------------------------
hk_Ragdoll_Constraint *__userpurge hk_Ragdoll_Constraint::hk_Ragdoll_Constraint@<eax>(
        hk_Ragdoll_Constraint *this@<ecx>,
        int a2@<edi>,
        hk_Environment *env,
        const hk_Ragdoll_Constraint_BP *bp,
        hk_Rigid_Body *a,
        hk_Rigid_Body *b)
{
  hk_Rigid_Body_Binary_EF::hk_Rigid_Body_Binary_EF(this, env, a, b, __formal: IVP_CP_CONSTRAINTS);
  this->__vftable = (hk_Ragdoll_Constraint_vtbl *)&hk_Ragdoll_Constraint::`vftable';
  this->m_constraint_system = nullptr;
  this->m_client_data = nullptr;
  *(_WORD *)&this->m_limits[0].m_limit_is_enabled = 0;
  *(_WORD *)&this->m_limits[1].m_limit_is_enabled = 0;
  *(_WORD *)&this->m_limits[2].m_limit_is_enabled = 0;
  this->m_limits[0].m_limit_min = 0.0;
  this->m_limits[0].m_limit_max = 0.0;
  this->m_limits[0].m_limit_tau = 1.0;
  this->m_limits[0].m_joint_friction = 0.0;
  this->m_limits[0].m_desired_velocity = 0.0;
  this->m_limits[0].m_ref_position = 0.0;
  this->m_limits[1].m_limit_min = 0.0;
  this->m_limits[1].m_limit_max = 0.0;
  this->m_limits[1].m_limit_tau = 1.0;
  this->m_limits[1].m_joint_friction = 0.0;
  this->m_limits[1].m_desired_velocity = 0.0;
  this->m_limits[1].m_ref_position = 0.0;
  this->m_limits[2].m_limit_min = 0.0;
  this->m_limits[2].m_limit_max = 0.0;
  this->m_limits[2].m_limit_tau = 1.0;
  this->m_limits[2].m_joint_friction = 0.0;
  this->m_limits[2].m_desired_velocity = 0.0;
  this->m_limits[2].m_ref_position = 0.0;
  *(_WORD *)&this->m_inputLimits[0].m_limit_is_enabled = 0;
  *(_WORD *)&this->m_inputLimits[1].m_limit_is_enabled = 0;
  *(_WORD *)&this->m_inputLimits[2].m_limit_is_enabled = 0;
  this->m_inputLimits[0].m_limit_min = 0.0;
  this->m_inputLimits[0].m_limit_max = 0.0;
  this->m_inputLimits[0].m_limit_tau = 1.0;
  this->m_inputLimits[0].m_joint_friction = 0.0;
  this->m_inputLimits[0].m_desired_velocity = 0.0;
  this->m_inputLimits[1].m_limit_min = 0.0;
  this->m_inputLimits[1].m_limit_max = 0.0;
  this->m_inputLimits[1].m_limit_tau = 1.0;
  this->m_inputLimits[1].m_joint_friction = 0.0;
  this->m_inputLimits[1].m_desired_velocity = 0.0;
  this->m_inputLimits[2].m_limit_min = 0.0;
  this->m_inputLimits[2].m_limit_max = 0.0;
  this->m_inputLimits[2].m_limit_tau = 1.0;
  this->m_inputLimits[2].m_joint_friction = 0.0;
  this->m_inputLimits[2].m_desired_velocity = 0.0;
  hk_Ragdoll_Constraint::init_ragdoll_constraint(this, a2, bp, sys: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003FC60
// Name: public: virtual char const __near * hk_Ragdoll_Constraint::get_constraint_type(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall hk_Ragdoll_Constraint::get_constraint_type(hk_Ragdoll_Constraint *this)
{
  return "ragdoll";
}

//------------------------------------------------------------------------------
// Address: 0x1003FCC0
// Name: public: hk_Ragdoll_Constraint::hk_Ragdoll_Constraint(class hk_Local_Constraint_System __near *,class hk_Ragdoll_Constraint_BP const __near *,class hk_Rigid_Body __near *,class hk_Rigid_Body __near *)
// Source: json
//------------------------------------------------------------------------------
hk_Ragdoll_Constraint *__thiscall hk_Ragdoll_Constraint::hk_Ragdoll_Constraint(
        hk_Ragdoll_Constraint *this,
        hk_Local_Constraint_System *constraint_system,
        const hk_Ragdoll_Constraint_BP *bp,
        hk_Rigid_Body *a,
        hk_Rigid_Body *b)
{
  hk_Constraint::hk_Constraint(
    this,
    sys: constraint_system,
    a,
    b,
    redundend_prio: IVP_CP_CONSTRAINTS,
    storage_size: 736);
  this->__vftable = (hk_Ragdoll_Constraint_vtbl *)&hk_Ragdoll_Constraint::`vftable';
  *(_WORD *)&this->m_limits[0].m_limit_is_enabled = 0;
  this->m_limits[0].m_limit_min = 0.0;
  this->m_limits[0].m_limit_max = 0.0;
  this->m_limits[0].m_limit_tau = 1.0;
  this->m_limits[0].m_joint_friction = 0.0;
  this->m_limits[0].m_desired_velocity = 0.0;
  this->m_limits[0].m_ref_position = 0.0;
  *(_WORD *)&this->m_limits[1].m_limit_is_enabled = 0;
  this->m_limits[1].m_limit_min = 0.0;
  this->m_limits[1].m_limit_max = 0.0;
  this->m_limits[1].m_limit_tau = 1.0;
  this->m_limits[1].m_joint_friction = 0.0;
  this->m_limits[1].m_desired_velocity = 0.0;
  this->m_limits[1].m_ref_position = 0.0;
  *(_WORD *)&this->m_limits[2].m_limit_is_enabled = 0;
  this->m_limits[2].m_limit_min = 0.0;
  this->m_limits[2].m_limit_max = 0.0;
  this->m_limits[2].m_limit_tau = 1.0;
  this->m_limits[2].m_joint_friction = 0.0;
  this->m_limits[2].m_desired_velocity = 0.0;
  this->m_limits[2].m_ref_position = 0.0;
  *(_WORD *)&this->m_inputLimits[0].m_limit_is_enabled = 0;
  this->m_inputLimits[0].m_limit_min = 0.0;
  this->m_inputLimits[0].m_limit_max = 0.0;
  this->m_inputLimits[0].m_limit_tau = 1.0;
  this->m_inputLimits[0].m_joint_friction = 0.0;
  this->m_inputLimits[0].m_desired_velocity = 0.0;
  *(_WORD *)&this->m_inputLimits[1].m_limit_is_enabled = 0;
  this->m_inputLimits[1].m_limit_min = 0.0;
  this->m_inputLimits[1].m_limit_max = 0.0;
  this->m_inputLimits[1].m_limit_tau = 1.0;
  this->m_inputLimits[1].m_joint_friction = 0.0;
  this->m_inputLimits[1].m_desired_velocity = 0.0;
  *(_WORD *)&this->m_inputLimits[2].m_limit_is_enabled = 0;
  this->m_inputLimits[2].m_limit_min = 0.0;
  this->m_inputLimits[2].m_limit_max = 0.0;
  this->m_inputLimits[2].m_limit_tau = 1.0;
  this->m_inputLimits[2].m_joint_friction = 0.0;
  this->m_inputLimits[2].m_desired_velocity = 0.0;
  hk_Ragdoll_Constraint::init_ragdoll_constraint(this, a2: (int)constraint_system, bp, sys: constraint_system);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003FE50
// Name: public: virtual void hk_Ragdoll_Constraint::init_constraint(void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge hk_Ragdoll_Constraint::init_constraint(
        hk_Ragdoll_Constraint *this@<ecx>,
        int a2@<edi>,
        const hk_Ragdoll_Constraint_BP *vbp)
{
  hk_Ragdoll_Constraint::init_ragdoll_constraint(this, a2, bp: vbp, sys: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1003FE70
// Name: public: virtual int hk_Ragdoll_Constraint::setup_and_step_constraint(class hk_PSI_Info __near &,void __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __userpurge hk_Ragdoll_Constraint::setup_and_step_constraint@<eax>(
        hk_Ragdoll_Constraint *this@<ecx>,
        int a2@<ebp>,
        hk_PSI_Info *pi,
        void *mem,
        float tau_factor,
        float strength_factor)
{
  hk_Rigid_Body *v6; // edx
  __m128 *v7; // eax
  bool v8; // zf
  __m128 *v9; // edi
  __m128 v10; // xmm6
  __m128 v11; // xmm2
  __m128 v12; // xmm0
  __m128 v13; // xmm4
  __m128 v14; // xmm1
  __m128 *physical_core; // edx
  __m128 v16; // xmm3
  __m128 v17; // xmm4
  __m128 v18; // xmm1
  __m128 v19; // xmm6
  __m128 v20; // xmm0
  __m128 v21; // xmm5
  __m128 v22; // xmm2
  __m128 v23; // xmm5
  __m128 v24; // xmm7
  __m128 v25; // xmm0
  __m128 v26; // xmm5
  __m128 v27; // xmm1
  __m128 v28; // xmm0
  __m128 v29; // xmm5
  __m128 v30; // xmm0
  __m128 v31; // xmm2
  __m128 v32; // xmm0
  __m128 v33; // xmm3
  __m128 v34; // xmm4
  __m128 v35; // xmm1
  __m128 v36; // xmm6
  __m128 v37; // xmm0
  __m128 v38; // xmm0
  __m128 v39; // xmm4
  __m128 v40; // xmm7
  __m128 v41; // xmm6
  __m128 v42; // xmm6
  __m128 v43; // xmm1
  __m128 v44; // xmm4
  __m128 v45; // xmm1
  __m128 v46; // xmm4
  __m128 v47; // xmm2
  hk_Ragdoll_Constraint *v48; // ecx
  __m128 v49; // xmm3
  __m128 v50; // xmm0
  hk_Local_Constraint_System *v51; // eax
  __m128 v52; // xmm1
  __m128 v53; // xmm0
  __m128 v54; // xmm1
  __m128 *v55; // eax
  __m128 v56; // xmm1
  __m128 v57; // xmm2
  __m128 v58; // xmm3
  __m128 v59; // xmm0
  char v60; // dl
  __m128 v61; // xmm4
  __m128 v62; // xmm5
  __int128 v63; // xmm3
  __int128 v64; // xmm3
  __m128 v65; // xmm4
  __m128 v66; // xmm1
  __m128 v67; // xmm5
  __m128 v68; // xmm3
  __m128 v69; // xmm5
  __m128 v70; // xmm6
  __m128 v71; // xmm4
  __m128 v72; // xmm1
  __m128 v73; // xmm3
  __m128 v74; // xmm7
  __m128 v75; // xmm4
  __m128 *v76; // eax
  __int128 v77; // xmm1
  __int128 v78; // xmm1
  __m128 v79; // xmm6
  __m128 v80; // xmm3
  __m128 v81; // xmm1
  __m128 v82; // xmm4
  __m128 v83; // xmm7
  __m128 v84; // xmm1
  __m128 v85; // xmm4
  __m128 v86; // xmm3
  __m128 v87; // xmm6
  __m128 v88; // xmm4
  __m128 v89; // xmm7
  __m128 v90; // xmm6
  __m128 v91; // xmm5
  __m128 v92; // xmm3
  __m128 v93; // xmm1
  __m128 v94; // xmm6
  __m128 v95; // xmm4
  __m128 v96; // xmm4
  __m128 v97; // xmm0
  __m128 v98; // xmm0
  __m128 v99; // xmm7
  __m128 v100; // xmm1
  __m128 v101; // xmm4
  __m128 v102; // xmm0
  __m128 v103; // xmm3
  __m128 i_delta_time_low; // xmm5
  __m128 v105; // xmm3
  __m128 v106; // xmm2
  __m128 v107; // xmm0
  __m128 v108; // xmm2
  __m128 v109; // xmm1
  __m128 v111; // [esp-Ch] [ebp-18Ch]
  _BYTE dir_4[80]; // [esp+4h] [ebp-17Ch] OVERLAPPED BYREF
  __m128 v113; // [esp+54h] [ebp-12Ch]
  __m128 v114; // [esp+64h] [ebp-11Ch]
  _BYTE v115[96]; // [esp+74h] [ebp-10Ch] OVERLAPPED
  __m128 v116; // [esp+D4h] [ebp-ACh]
  __m128 v117; // [esp+E4h] [ebp-9Ch]
  __m128 v118; // [esp+F4h] [ebp-8Ch]
  __m128 v119; // [esp+104h] [ebp-7Ch]
  _BYTE v120[44]; // [esp+114h] [ebp-6Ch] OVERLAPPED BYREF
  __m128 *v121; // [esp+140h] [ebp-40h]
  __m128 *v122; // [esp+144h] [ebp-3Ch]
  __m128 *v123; // [esp+154h] [ebp-2Ch]
  __m128 v124; // [esp+164h] [ebp-1Ch]
  int v125; // [esp+174h] [ebp-Ch]
  void *v126; // [esp+178h] [ebp-8h]
  void *retaddr; // [esp+180h] [ebp+0h]

  v125 = a2;
  v126 = retaddr;
  *(_DWORD *)&v120[40] = this;
  v6 = this->m_entities[1];
  *((_DWORD *)mem + 112) = 0;
  *((_DWORD *)mem + 144) = 0;
  *((_DWORD *)mem + 176) = 0;
  v7 = (__m128 *)this->m_entities[0];
  v8 = (v7[4].m128_i32[1] & 0x800) == 0;
  *(float *)v115 = tau_factor;
  v9 = (__m128 *)v7[9].m128_i32[1];
  v10 = v9[6];
  v11 = v9[7];
  *(float *)&v115[4] = strength_factor;
  v12 = v9[8];
  v13 = _mm_shuffle_ps(v10, v11, 68);
  v14 = _mm_shuffle_ps(v12, Four_Zeros, 68);
  v122 = (__m128 *)v6;
  physical_core = (__m128 *)v6->physical_core;
  v16 = _mm_shuffle_ps(v13, v14, 136);
  v17 = _mm_shuffle_ps(v13, v14, 221);
  v18 = v9[9];
  v19 = _mm_shuffle_ps(_mm_shuffle_ps(v10, v11, 238), _mm_shuffle_ps(v12, Four_Zeros, 238), 136);
  v121 = v7;
  v123 = physical_core;
  *(__m128 *)dir_4 = v16;
  *(__m128 *)&dir_4[16] = v17;
  *(__m128 *)&dir_4[32] = v19;
  *(__m128 *)&dir_4[48] = v18;
  if ( v8 )
    *(__m128 *)&dir_4[48] = _mm_add_ps(
                              _mm_add_ps(
                                _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v7[3], v7[3], 170), v19), v18),
                                _mm_mul_ps(_mm_shuffle_ps(v7[3], v7[3], 85), v17)),
                              _mm_mul_ps(_mm_shuffle_ps(v7[3], v7[3], 0), v16));
  v8 = (v122[4].m128_i32[1] & 0x800) == 0;
  v20 = _mm_shuffle_ps(physical_core[6], physical_core[7], 68);
  v21 = physical_core[8];
  v22 = _mm_shuffle_ps(v21, Four_Zeros, 238);
  v23 = _mm_shuffle_ps(v21, Four_Zeros, 68);
  v24 = _mm_shuffle_ps(v20, v23, 136);
  v25 = _mm_shuffle_ps(v20, v23, 221);
  v26 = physical_core[9];
  v27 = _mm_shuffle_ps(_mm_shuffle_ps(physical_core[6], physical_core[7], 238), v22, 136);
  *(__m128 *)&v115[16] = v24;
  *(__m128 *)&v115[32] = v25;
  *(__m128 *)&v115[48] = v27;
  *(__m128 *)&v115[64] = v26;
  if ( v8 )
    *(__m128 *)&v115[64] = _mm_add_ps(
                             _mm_add_ps(
                               _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v122[3], v122[3], 170), v27), v26),
                               _mm_mul_ps(_mm_shuffle_ps(v122[3], v122[3], 85), *(__m128 *)&v115[32])),
                             _mm_mul_ps(_mm_shuffle_ps(v122[3], v122[3], 0), v24));
  v28 = _mm_and_ps(*(__m128 *)this->m_transform_os_ks[0].m_elems, *(__m128 *)g_SIMD_clear_wmask);
  v29 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v28, v28, 170), v19), _mm_mul_ps(_mm_shuffle_ps(v28, v28, 85), v17)),
          _mm_mul_ps(_mm_shuffle_ps(v28, v28, 0), v16));
  v30 = _mm_and_ps(*(__m128 *)&this->m_transform_os_ks[0].m_elems[8], *(__m128 *)g_SIMD_clear_wmask);
  v31 = _mm_add_ps(
          _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v30, v30, 170), v19), _mm_mul_ps(_mm_shuffle_ps(v30, v30, 85), v17)),
          _mm_mul_ps(_mm_shuffle_ps(v30, v30, 0), v16));
  v32 = _mm_and_ps(*(__m128 *)this->m_transform_os_ks[1].m_elems, *(__m128 *)g_SIMD_clear_wmask);
  v33 = _mm_add_ps(
          _mm_add_ps(
            _mm_mul_ps(_mm_shuffle_ps(v32, v32, 85), *(__m128 *)&v115[32]),
            _mm_mul_ps(_mm_shuffle_ps(v32, v32, 170), *(__m128 *)&v115[48])),
          _mm_mul_ps(_mm_shuffle_ps(v32, v32, 0), v24));
  v34 = _mm_add_ps(v33, v29);
  v124 = _mm_mul_ps(v34, v34);
  v35 = 0;
  v35.m128_f32[0] = (float)(v124.m128_f32[1] + v124.m128_f32[0]) + v124.m128_f32[2];
  v36 = _mm_shuffle_ps(v35, v35, 0);
  v37 = _mm_rsqrt_ps(v36);
  v38 = _mm_mul_ps(
          _mm_mul_ps(
            _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(Four_Threes, _mm_mul_ps(_mm_mul_ps(v37, v37), v36)), v37), Four_PointFives),
            g_f4_111half),
          _mm_or_ps(_mm_and_ps((__m128)xmmword_100DAD40, v36), _mm_andnot_ps((__m128)xmmword_100DAD40, v34)));
  *(__m128 *)v115 = _mm_or_ps(
                      _mm_andnot_ps((__m128)xmmword_100DAD40, *(__m128 *)v115),
                      _mm_and_ps((__m128)xmmword_100DAD40, v38));
  *((__m128 *)mem + 18) = v29;
  *((__m128 *)mem + 20) = v31;
  *((__m128 *)mem + 19) = v33;
  v118 = _mm_shuffle_ps(v38, v38, 18);
  *(__m128 *)&v120[16] = _mm_shuffle_ps(v38, v38, 9);
  v39 = _mm_sub_ps(
          _mm_mul_ps(_mm_shuffle_ps(v31, v31, 18), *(__m128 *)&v120[16]),
          _mm_mul_ps(_mm_shuffle_ps(v31, v31, 9), v118));
  v124 = _mm_mul_ps(v39, v39);
  v40 = 0;
  v40.m128_f32[0] = (float)(v124.m128_f32[1] + v124.m128_f32[0]) + v124.m128_f32[2];
  v119 = _mm_shuffle_ps(v40, v40, 0);
  v41 = _mm_rsqrt_ps(v119);
  v124 = _mm_mul_ps(v41, v41);
  v42 = *(__m128 *)&this->m_transform_os_ks[1].m_elems[8];
  v43 = _mm_and_ps(
          _mm_mul_ps(
            _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(Four_Threes, _mm_mul_ps(v124, v119)), _mm_rsqrt_ps(v119)), Four_PointFives),
            v39),
          _mm_cmplt_ps(Four_Epsilons, v119));
  *((__m128 *)mem + 17) = v38;
  v44 = _mm_mul_ps(_mm_shuffle_ps(v42, v42, 170), *(__m128 *)&v115[48]);
  *((_OWORD *)mem + 45) = *(_OWORD *)v115;
  v124 = _mm_mul_ps(
           _mm_add_ps(
             _mm_add_ps(v44, _mm_mul_ps(_mm_shuffle_ps(v42, v42, 85), *(__m128 *)&v115[32])),
             _mm_mul_ps(_mm_shuffle_ps(v42, v42, 0), *(__m128 *)&v115[16])),
           v43);
  v45 = 0;
  v45.m128_f32[0] = (float)(v124.m128_f32[1] + v124.m128_f32[0]) + v124.m128_f32[2];
  v124 = _mm_mul_ps(v33, v29);
  v46 = 0;
  v46.m128_f32[0] = (float)(v124.m128_f32[1] + v124.m128_f32[0]) + v124.m128_f32[2];
  v119 = v46;
  v124 = _mm_mul_ps(v33, v31);
  v47 = 0;
  v47.m128_f32[0] = (float)(v124.m128_f32[1] + v124.m128_f32[0]) + v124.m128_f32[2];
  v118 = (__m128)xmmword_100DAD30;
  *(_OWORD *)&v120[16] = *(_OWORD *)&g_SIMD_ComponentMask[0][0];
  v124 = v47;
  ArcTan2Alt();
  *((__m128 *)mem + 16) = _mm_or_ps(
                            _mm_and_ps(
                              _mm_sub_ps(Four_Zeros, _mm_shuffle_ps(v45, v45, 0)),
                              *(__m128 *)&g_SIMD_ComponentMask[0][0]),
                            _mm_andnot_ps(
                              *(__m128 *)&g_SIMD_ComponentMask[0][0],
                              _mm_or_ps(
                                _mm_andnot_ps((__m128)xmmword_100DAD30, _mm_shuffle_ps(v46, v46, 0)),
                                _mm_and_ps(_mm_shuffle_ps(v47, v47, 0), (__m128)xmmword_100DAD30))));
  hk_Ragdoll_Constraint::apply_angular_part(this: v48, pi, work: (hk_Ragdoll_Constraint_Work *)mem);
  if ( *(_BYTE *)(*(_DWORD *)&v120[40] + 327) != 0 )
  {
    v49 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps(*(__m128 *)(*(_DWORD *)&v120[40] + 80), *(__m128 *)(*(_DWORD *)&v120[40] + 80), 170),
                  *(__m128 *)&dir_4[32]),
                *(__m128 *)&dir_4[48]),
              _mm_mul_ps(
                _mm_shuffle_ps(*(__m128 *)(*(_DWORD *)&v120[40] + 80), *(__m128 *)(*(_DWORD *)&v120[40] + 80), 85),
                *(__m128 *)&dir_4[16])),
            _mm_mul_ps(
              _mm_shuffle_ps(*(__m128 *)(*(_DWORD *)&v120[40] + 80), *(__m128 *)(*(_DWORD *)&v120[40] + 80), 0),
              *(__m128 *)dir_4));
    v50 = *(__m128 *)(*(_DWORD *)&v120[40] + 144);
    v51 = *(hk_Local_Constraint_System **)(*(_DWORD *)&v120[40] + 16);
    v52 = _mm_add_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v50, v50, 170), *(__m128 *)&v115[48]), *(__m128 *)&v115[64]),
              _mm_mul_ps(_mm_shuffle_ps(v50, v50, 85), *(__m128 *)&v115[32])),
            _mm_mul_ps(_mm_shuffle_ps(v50, v50, 0), *(__m128 *)&v115[16]));
    v53 = _mm_sub_ps(v52, v49);
    *(__m128 *)v120 = v49;
    *(__m128 *)&v120[16] = v52;
    v111 = v53;
    *(__m128 *)mem = v53;
    if ( v51 != nullptr )
    {
      v124 = _mm_mul_ps(v53, v53);
      v54 = 0;
      v54.m128_f32[0] = (float)(v124.m128_f32[1] + v124.m128_f32[0]) + v124.m128_f32[2];
      hk_Local_Constraint_System::report_square_error(this: v51, errorSq: _mm_shuffle_ps(v54, v54, 0));
      v52 = *(__m128 *)&v120[16];
      v49 = *(__m128 *)v120;
    }
    v55 = (__m128 *)v9->m128_u16[0];
    v56 = _mm_sub_ps(v52, *(__m128 *)(v122[9].m128_i32[1] + 144));
    v57 = Four_Zeros;
    v58 = _mm_sub_ps(v49, *(__m128 *)(v121[9].m128_i32[1] + 144));
    v59 = Four_Zeros;
    v60 = (unsigned __int8)v55 | ((unsigned __int8)v9->m128_i16[0] >> 3);
    v61 = Four_Zeros;
    v118 = v56;
    v113 = Four_Zeros;
    v62 = Four_Zeros;
    v121 = v55;
    if ( (v60 & 2) != 0 )
    {
      *((__m128 *)mem + 9) = Four_Zeros;
      v63 = *((_OWORD *)mem + 9);
      *((_OWORD *)mem + 8) = v63;
      *((_OWORD *)mem + 7) = v63;
      *((__m128 *)mem + 3) = Four_Zeros;
      v64 = *((_OWORD *)mem + 3);
      *((_OWORD *)mem + 2) = v64;
      *((_OWORD *)mem + 1) = v64;
    }
    else
    {
      v65 = _mm_shuffle_ps(v58, v58, 0);
      v66 = _mm_shuffle_ps(v58, v58, 85);
      v67 = _mm_shuffle_ps(v58, v58, 170);
      v68 = _mm_mul_ps(v67, v9[6]);
      v69 = _mm_sub_ps(_mm_mul_ps(v67, v9[7]), _mm_mul_ps(v66, v9[8]));
      v70 = _mm_sub_ps(_mm_mul_ps(v65, v9[8]), v68);
      v71 = _mm_sub_ps(_mm_mul_ps(v66, v9[6]), _mm_mul_ps(v65, v9[7]));
      v72 = _mm_shuffle_ps(v69, v70, 68);
      v73 = _mm_shuffle_ps(v71, Four_Zeros, 68);
      *(__m128 *)&v115[80] = _mm_shuffle_ps(v72, v73, 136);
      *(__m128 *)&v115[64] = v71;
      v116 = _mm_shuffle_ps(v72, v73, 221);
      v74 = _mm_shuffle_ps(_mm_shuffle_ps(v69, v70, 238), _mm_shuffle_ps(v71, Four_Zeros, 238), 136);
      v75 = v9[3];
      v117 = v74;
      *(__m128 *)&dir_4[16] = _mm_mul_ps(v75, v69);
      *(__m128 *)&v120[16] = _mm_shuffle_ps(*(__m128 *)&dir_4[16], *(__m128 *)&dir_4[16], 0);
      *(__m128 *)&dir_4[64] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&dir_4[16], *(__m128 *)&dir_4[16], 170), v74),
                                    Four_Zeros),
                                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&dir_4[16], *(__m128 *)&dir_4[16], 85), v116)),
                                _mm_mul_ps(*(__m128 *)&v120[16], *(__m128 *)&v115[80]));
      *(__m128 *)&dir_4[32] = _mm_mul_ps(v75, v70);
      *(__m128 *)&dir_4[48] = _mm_mul_ps(v75, *(__m128 *)&v115[64]);
      v113 = _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&dir_4[32], *(__m128 *)&dir_4[32], 170), v74),
                   Four_Zeros),
                 _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&dir_4[32], *(__m128 *)&dir_4[32], 85), v116)),
               _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&dir_4[32], *(__m128 *)&dir_4[32], 0), *(__m128 *)&v115[80]));
      v114 = _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&dir_4[48], *(__m128 *)&dir_4[48], 170), v74),
                   Four_Zeros),
                 _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&dir_4[48], *(__m128 *)&dir_4[48], 85), v116)),
               _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&dir_4[48], *(__m128 *)&dir_4[48], 0), *(__m128 *)&v115[80]));
      *(__m128 *)&v120[16] = _mm_shuffle_ps(v75, v75, 255);
      hk_Rotation_sse_t::AddDiagonal(this: (hk_Rotation_sse_t *)&dir_4[64], diag: (const __m128 *)&v120[16]);
      v61 = v113;
      v62 = *(__m128 *)&dir_4[64];
      v56 = v118;
      v57 = Four_Zeros;
      *((_OWORD *)mem + 1) = *(_OWORD *)&v115[80];
      *((__m128 *)mem + 2) = v116;
      *((__m128 *)mem + 3) = v117;
      *((_OWORD *)mem + 7) = *(_OWORD *)&dir_4[16];
      *((_OWORD *)mem + 8) = *(_OWORD *)&dir_4[32];
      *((_OWORD *)mem + 9) = *(_OWORD *)&dir_4[48];
      v59 = v114;
    }
    v76 = v123;
    if ( (((unsigned __int8)v123->m128_i16[0] | ((unsigned __int8)v123->m128_i16[0] >> 3)) & 2) != 0 )
    {
      *((__m128 *)mem + 12) = v57;
      v77 = *((_OWORD *)mem + 12);
      *((_OWORD *)mem + 11) = v77;
      *((_OWORD *)mem + 10) = v77;
      *((__m128 *)mem + 6) = v57;
      v78 = *((_OWORD *)mem + 6);
      *((_OWORD *)mem + 5) = v78;
      *((_OWORD *)mem + 4) = v78;
    }
    else
    {
      v79 = v123[8];
      v80 = _mm_shuffle_ps(v56, v56, 0);
      *(__m128 *)&v115[64] = _mm_shuffle_ps(v56, v56, 170);
      *(__m128 *)&v120[16] = _mm_mul_ps(*(__m128 *)&v115[64], v123[7]);
      v81 = _mm_shuffle_ps(v56, v56, 85);
      v82 = _mm_mul_ps(v81, v123[6]);
      *(__m128 *)&dir_4[16] = _mm_sub_ps(_mm_mul_ps(v81, v79), *(__m128 *)&v120[16]);
      v83 = _mm_sub_ps(_mm_mul_ps(*(__m128 *)&v115[64], v123[6]), _mm_mul_ps(v80, v79));
      v84 = _mm_shuffle_ps(*(__m128 *)&dir_4[16], v83, 68);
      v85 = _mm_sub_ps(_mm_mul_ps(v80, v123[7]), v82);
      v86 = _mm_shuffle_ps(v85, v57, 68);
      *(__m128 *)&v115[80] = _mm_shuffle_ps(v84, v86, 136);
      *(__m128 *)&dir_4[48] = v85;
      v87 = _mm_shuffle_ps(_mm_shuffle_ps(*(__m128 *)&dir_4[16], v83, 238), _mm_shuffle_ps(v85, v57, 238), 136);
      v88 = v123[3];
      v117 = v87;
      v116 = _mm_shuffle_ps(v84, v86, 221);
      *(__m128 *)&v115[32] = _mm_mul_ps(v88, *(__m128 *)&dir_4[16]);
      *(__m128 *)&v120[16] = _mm_shuffle_ps(*(__m128 *)&v115[32], *(__m128 *)&v115[32], 0);
      *(__m128 *)&v115[48] = _mm_mul_ps(v88, v83);
      *(__m128 *)&dir_4[64] = _mm_add_ps(
                                _mm_add_ps(
                                  _mm_add_ps(
                                    _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v115[32], *(__m128 *)&v115[32], 170), v87),
                                    v62),
                                  _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v115[32], *(__m128 *)&v115[32], 85), v116)),
                                _mm_mul_ps(*(__m128 *)&v120[16], *(__m128 *)&v115[80]));
      *(__m128 *)&v115[64] = _mm_mul_ps(v88, *(__m128 *)&dir_4[48]);
      v113 = _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v115[48], *(__m128 *)&v115[48], 170), v87), v113),
                 _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v115[48], *(__m128 *)&v115[48], 85), v116)),
               _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v115[48], *(__m128 *)&v115[48], 0), *(__m128 *)&v115[80]));
      v114 = _mm_add_ps(
               _mm_add_ps(
                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v115[64], *(__m128 *)&v115[64], 170), v87), v59),
                 _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v115[64], *(__m128 *)&v115[64], 85), v116)),
               _mm_mul_ps(_mm_shuffle_ps(*(__m128 *)&v115[64], *(__m128 *)&v115[64], 0), *(__m128 *)&v115[80]));
      *(__m128 *)&v120[16] = _mm_shuffle_ps(v88, v88, 255);
      hk_Rotation_sse_t::AddDiagonal(this: (hk_Rotation_sse_t *)&dir_4[64], diag: (const __m128 *)&v120[16]);
      v61 = v113;
      v62 = *(__m128 *)&dir_4[64];
      v57 = Four_Zeros;
      v76 = v123;
      *((_OWORD *)mem + 4) = *(_OWORD *)&v115[80];
      *((__m128 *)mem + 5) = v116;
      *((__m128 *)mem + 6) = v117;
      *((_OWORD *)mem + 10) = *(_OWORD *)&v115[32];
      *((_OWORD *)mem + 11) = *(_OWORD *)&v115[48];
      *((_OWORD *)mem + 12) = *(_OWORD *)&v115[64];
      v59 = v114;
    }
    v89 = _mm_shuffle_ps(v62, v62, 9);
    v90 = _mm_shuffle_ps(v62, v62, 82);
    v91 = _mm_shuffle_ps(v61, v61, 9);
    v119 = _mm_shuffle_ps(v61, v61, 82);
    *(__m128 *)&v120[16] = v90;
    v92 = _mm_shuffle_ps(v59, v59, 82);
    v93 = _mm_shuffle_ps(v59, v59, 9);
    v94 = _mm_sub_ps(_mm_mul_ps(v119, v89), _mm_mul_ps(v91, v90));
    v124 = _mm_mul_ps(v59, v94);
    v95 = 0;
    v95.m128_f32[0] = (float)(v124.m128_f32[1] + v124.m128_f32[0]) + v124.m128_f32[2];
    v96 = _mm_shuffle_ps(v95, v95, 0);
    v97 = _mm_rcp_ps(v96);
    v118 = v89;
    v98 = _mm_sub_ps(_mm_add_ps(v97, v97), _mm_mul_ps(_mm_mul_ps(v97, v97), v96));
    v99 = _mm_mul_ps(v93, v119);
    *((__m128 *)mem + 14) = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v93, *(__m128 *)&v120[16]), _mm_mul_ps(v92, v118)), v98);
    v100 = v9[12];
    v123 = v9 + 12;
    v101 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v92, v91), v99), v98);
    *((__m128 *)mem + 15) = _mm_mul_ps(v98, v94);
    v102 = v76[12];
    v122 = v76 + 12;
    *(_OWORD *)&v120[16] = *(unsigned int *)(*(_DWORD *)&v120[40] + 316);
    v103 = (__m128)*(unsigned int *)(*(_DWORD *)&v120[40] + 320);
    i_delta_time_low = (__m128)LODWORD(pi->i_delta_time);
    *((__m128 *)mem + 13) = v101;
    v105 = _mm_mul_ps(_mm_mul_ps(v103, *(__m128 *)v115), i_delta_time_low);
    v106 = _mm_add_ps(
             _mm_sub_ps(
               v57,
               _mm_mul_ps(
                 _mm_add_ps(
                   _mm_add_ps(
                     _mm_add_ps(
                       _mm_sub_ps(
                         _mm_add_ps(
                           _mm_add_ps(
                             _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v100, v100, 170), *((__m128 *)mem + 3)), v9[13]),
                             _mm_mul_ps(_mm_shuffle_ps(v100, v100, 85), *((__m128 *)mem + 2))),
                           _mm_mul_ps(_mm_shuffle_ps(v100, v100, 0), *((__m128 *)mem + 1))),
                         v76[13]),
                       _mm_mul_ps(_mm_shuffle_ps(v102, v102, 170), *((__m128 *)mem + 6))),
                     _mm_mul_ps(_mm_shuffle_ps(v102, v102, 85), *((__m128 *)mem + 5))),
                   _mm_mul_ps(_mm_shuffle_ps(v102, v102, 0), *((__m128 *)mem + 4))),
                 _mm_mul_ps(
                   _mm_shuffle_ps(*(__m128 *)&v120[16], *(__m128 *)&v120[16], 0),
                   _mm_shuffle_ps(*(__m128 *)v115, *(__m128 *)v115, 85)))),
             _mm_mul_ps(_mm_shuffle_ps(v105, v105, 0), v111));
    v107 = _mm_add_ps(
             _mm_add_ps(
               _mm_mul_ps(_mm_shuffle_ps(v106, v106, 170), *((__m128 *)mem + 15)),
               _mm_mul_ps(_mm_shuffle_ps(v106, v106, 85), *((__m128 *)mem + 14))),
             _mm_mul_ps(_mm_shuffle_ps(v106, v106, 0), *((__m128 *)mem + 13)));
    if ( ((unsigned __int8)v121 & 0x12) == 0 )
    {
      v108 = v9[3];
      *v123 = _mm_and_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v107, v107, 170), *((__m128 *)mem + 9)),
                      _mm_mul_ps(_mm_shuffle_ps(v107, v107, 85), *((__m128 *)mem + 8))),
                    _mm_mul_ps(_mm_shuffle_ps(v107, v107, 0), *((__m128 *)mem + 7))),
                  v100),
                *(__m128 *)g_SIMD_clear_wmask);
      v9[13] = _mm_and_ps(
                 _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v108, v108, 255), v107), v9[13]),
                 *(__m128 *)g_SIMD_clear_wmask);
    }
    if ( (v76->m128_i16[0] & 0x12) == 0 )
    {
      v109 = v76[3];
      *v122 = _mm_and_ps(
                _mm_add_ps(
                  _mm_add_ps(
                    _mm_add_ps(
                      _mm_mul_ps(_mm_shuffle_ps(v107, v107, 170), *((__m128 *)mem + 12)),
                      _mm_mul_ps(_mm_shuffle_ps(v107, v107, 85), *((__m128 *)mem + 11))),
                    _mm_mul_ps(_mm_shuffle_ps(v107, v107, 0), *((__m128 *)mem + 10))),
                  *v122),
                *(__m128 *)g_SIMD_clear_wmask);
      v76[13] = _mm_and_ps(
                  _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v109, v109, 255), _mm_sub_ps(Four_Zeros, v107)), v76[13]),
                  *(__m128 *)g_SIMD_clear_wmask);
    }
  }
  return 736;
}
