// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/havana/havok/hk_physics/constraint/ragdoll/ragdoll_constraint_bp_builder.cpp
// Functions: 1
// ============================================================

#include "ivp\havana\havok\hk_physics\constraint\ragdoll\ragdoll_constraint_bp_builder.h"

//------------------------------------------------------------------------------
// Address: 0x10042820
// Name: public: enum hk_result hk_Ragdoll_Constraint_BP_Builder::initialize_from_limited_ball_socket_bp(class hk_Limited_Ball_Socket_BP const __near *,class hk_Rigid_Body __near *,class hk_Rigid_Body __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __userpurge hk_Ragdoll_Constraint_BP_Builder::initialize_from_limited_ball_socket_bp@<eax>(
        hk_Ragdoll_Constraint_BP_Builder *this@<ecx>,
        float a2@<ebp>,
        const hk_Limited_Ball_Socket_BP *bp,
        hk_Rigid_Body *a,
        hk_Rigid_Body *b)
{
  hk_Ragdoll_Constraint_BP_Builder *v5; // esi
  const hk_Limited_Ball_Socket_BP *v6; // edi
  const hk_Vector3 *p_m_translation; // edx
  int v8; // ecx
  double y; // st7
  float m_min; // xmm0_4
  float v11; // xmm6_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm5_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm4_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  hk_Constraint_Limit_BP *m_limits; // eax
  float v21; // xmm7_4
  float v22; // xmm7_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  int v26; // ecx
  int v27; // edx
  int v28; // eax
  float v29; // xmm0_4
  double v30; // st7
  float *v31; // eax
  float *v32; // eax
  float *v33; // eax
  float v34; // xmm1_4
  float v35; // xmm0_4
  unsigned __int8 v36; // al
  bool v37; // zf
  IVP_Core *physical_core; // eax
  float v39; // xmm1_4
  IVP_Core *v40; // eax
  IVP_Core *v41; // eax
  float v42; // xmm1_4
  float v43; // xmm2_4
  float v44; // xmm3_4
  IVP_Core *v45; // eax
  float v46; // xmm2_4
  float v47; // xmm3_4
  int m_n_queries; // eax
  float v49; // xmm4_4
  float v50; // xmm5_4
  IVP_Core *v51; // ecx
  float v52; // xmm0_4
  char *v53; // eax
  float v54; // xmm0_4
  float v55; // xmm2_4
  float v56; // xmm7_4
  float v57; // xmm6_4
  float v58; // xmm7_4
  float v59; // xmm0_4
  float *v60; // edx
  char *v61; // eax
  float v62; // xmm4_4
  float v63; // xmm5_4
  float v64; // xmm0_4
  float v65; // xmm3_4
  float v66; // xmm4_4
  float v67; // xmm0_4
  float v68; // xmm1_4
  float v69; // xmm5_4
  float v70; // xmm2_4
  hk_Rigid_Body_Core *v71; // ecx
  float v72; // xmm1_4
  float v73; // xmm3_4
  int v74; // eax
  const hk_Vector3 *v75; // ecx
  float v76; // ecx
  int v77; // edx
  int v78; // eax
  double v79; // st7
  float *v80; // eax
  float *v81; // eax
  double v82; // st7
  int v83; // eax
  double v84; // st7
  float *v85; // eax
  float v86; // xmm0_4
  float v87; // xmm1_4
  float v88; // eax
  float v89; // xmm1_4
  float v90; // xmm0_4
  float v91; // xmm0_4
  float m_max; // xmm1_4
  unsigned __int8 v93; // cl
  hk_Vector3 cross_a; // [esp+20h] [ebp-250h] BYREF
  hk_VM_Query_Builder<hk_VMQ_Storage<1> > query; // [esp+30h] [ebp-240h] BYREF
  float v96; // [esp+100h] [ebp-170h]
  hk_Vector3 axis_Att_ws; // [esp+104h] [ebp-16Ch]
  float limit_mid[3]; // [esp+114h] [ebp-15Ch] BYREF
  hk_Vector3 axis_Ref_ws; // [esp+120h] [ebp-150h] BYREF
  int v100; // [esp+130h] [ebp-140h]
  float v101; // [esp+134h] [ebp-13Ch]
  float v102; // [esp+138h] [ebp-138h]
  float v103; // [esp+13Ch] [ebp-134h]
  int v104; // [esp+140h] [ebp-130h]
  float v105; // [esp+144h] [ebp-12Ch]
  float v106; // [esp+148h] [ebp-128h]
  float v107; // [esp+14Ch] [ebp-124h]
  int v108; // [esp+150h] [ebp-120h]
  float v109; // [esp+154h] [ebp-11Ch]
  float v110; // [esp+158h] [ebp-118h]
  float v111; // [esp+15Ch] [ebp-114h]
  int v112; // [esp+160h] [ebp-110h]
  hk_Transform v113; // [esp+164h] [ebp-10Ch] BYREF
  float v114; // [esp+1A4h] [ebp-CCh] BYREF
  float v115; // [esp+1A8h] [ebp-C8h]
  float v116; // [esp+1ACh] [ebp-C4h]
  _BYTE pos_Ref_ws_4[60]; // [esp+1B4h] [ebp-BCh] OVERLAPPED BYREF
  _BYTE pos_Att_ws_4[64]; // [esp+1F4h] [ebp-7Ch] OVERLAPPED BYREF
  hk_Ragdoll_Constraint_BP_Builder *v119; // [esp+240h] [ebp-30h]
  _DWORD v120[3]; // [esp+244h] [ebp-2Ch]
  float limit_diff[3]; // [esp+250h] [ebp-20h]
  int axis_of_min_inertia; // [esp+25Ch] [ebp-14h]
  int v123; // [esp+260h] [ebp-10h]
  float min_inertia_inv; // [esp+264h] [ebp-Ch]
  int i; // [esp+268h] [ebp-8h]
  int retaddr; // [esp+270h] [ebp+0h]

  min_inertia_inv = a2;
  i = retaddr;
  v5 = this;
  v119 = this;
  v6 = bp;
  this->m_ragdoll_constraint_bp.m_transform_os_ks[0].hk_Rotation = bp->m_transform_os_ks[0].hk_Rotation;
  this->m_ragdoll_constraint_bp.m_transform_os_ks[0].m_translation.x = bp->m_transform_os_ks[0].m_translation.x;
  p_m_translation = &this->m_ragdoll_constraint_bp.m_transform_os_ks[0].m_translation;
  this->m_ragdoll_constraint_bp.m_transform_os_ks[0].m_translation.y = bp->m_transform_os_ks[0].m_translation.y;
  v8 = 0;
  p_m_translation->z = bp->m_transform_os_ks[0].m_translation.z;
  v5->m_ragdoll_constraint_bp.m_transform_os_ks[1].hk_Rotation = bp->m_transform_os_ks[1].hk_Rotation;
  v5->m_ragdoll_constraint_bp.m_transform_os_ks[1].m_translation.x = bp->m_transform_os_ks[1].m_translation.x;
  y = bp->m_transform_os_ks[1].m_translation.y;
  axis_of_min_inertia = (int)p_m_translation;
  v5->m_ragdoll_constraint_bp.m_transform_os_ks[1].m_translation.y = y;
  v123 = 0;
  v5->m_ragdoll_constraint_bp.m_transform_os_ks[1].m_translation.z = bp->m_transform_os_ks[1].m_translation.z;
  v5->m_ragdoll_constraint_bp.m_constrainTranslation = bp->m_constrainTranslation;
  m_min = bp->m_angular_limits[0].m_min;
  v11 = bp->m_angular_limits[0].m_max - m_min;
  v12 = (float)(m_min + bp->m_angular_limits[0].m_max) * 0.5;
  *(float *)v120 = v11;
  axis_Att_ws.y = v12;
  if ( v11 > 1.0e-16 )
    v123 = 1;
  v13 = bp->m_angular_limits[1].m_min;
  v14 = bp->m_angular_limits[1].m_max - v13;
  v15 = (float)(v13 + bp->m_angular_limits[1].m_max) * 0.5;
  *(float *)&v120[1] = v14;
  axis_Att_ws.z = v15;
  if ( v14 > 1.0e-16 )
    ++v123;
  v16 = bp->m_angular_limits[2].m_min;
  v17 = bp->m_angular_limits[2].m_max - v16;
  v18 = (float)(v16 + bp->m_angular_limits[2].m_max) * 0.5;
  *(float *)&v120[2] = v17;
  axis_Att_ws.w = v18;
  if ( v17 > 1.0e-16 )
    ++v123;
  v19 = COERCE_DOUBLE(_mask__AbsDouble_ & 0x400921FB60000000LL);
  m_limits = v5->m_ragdoll_constraint_bp.m_limits;
  limit_diff[2] = v19;
  LODWORD(limit_diff[1]) = v5->m_ragdoll_constraint_bp.m_limits;
  do
  {
    v21 = limit_diff[2];
    v5->m_ragdoll_constraint_bp.m_axisMap[v8] = v8;
    m_limits->m_limit_is_enabled = v21 > 0.000099999997
                                || (v22 = COERCE_DOUBLE(_mask__AbsDouble_ & 0xC00921FB60000000uLL)) > 0.000099999997;
    m_limits->m_limit_min = 0.0;
    m_limits->m_limit_max = 0.0;
    ++v8;
    ++m_limits;
  }
  while ( v8 < 3 );
  switch ( v123 )
  {
    case 0:
      v23 = COERCE_DOUBLE(_mask__AbsDouble_ & 0x4008552E93000000LL);
      v5->m_ragdoll_constraint_bp.m_limits[1].m_limit_is_enabled = v23 > 0.000099999997
                                                                || (v24 = COERCE_DOUBLE(_mask__AbsDouble_ & 0xC008552E93000000uLL)) > 0.000099999997;
      v5->m_ragdoll_constraint_bp.m_limits[1].m_limit_min = -0.1;
      v5->m_ragdoll_constraint_bp.m_limits[1].m_limit_max = 0.1;
      return 1;
    case 1:
      v123 = -1;
      if ( v11 > 1.0e-16 )
        v123 = 0;
      if ( v14 > 1.0e-16 )
        v123 = 1;
      if ( v17 > 1.0e-16 )
        v123 = 2;
      qmemcpy(pos_Ref_ws_4, v5, 48);
      *(_QWORD *)&pos_Att_ws_4[16] = *(_QWORD *)v5->m_ragdoll_constraint_bp.m_transform_os_ks[1].m_elems;
      *(_QWORD *)&pos_Att_ws_4[24] = *(_QWORD *)&v5->m_ragdoll_constraint_bp.m_transform_os_ks[1].m_elems[2];
      *(_QWORD *)&pos_Att_ws_4[32] = *(_QWORD *)&v5->m_ragdoll_constraint_bp.m_transform_os_ks[1].m_elems[4];
      *(_QWORD *)&pos_Att_ws_4[40] = *(_QWORD *)&v5->m_ragdoll_constraint_bp.m_transform_os_ks[1].m_elems[6];
      *(_QWORD *)&pos_Att_ws_4[48] = *(_QWORD *)&v5->m_ragdoll_constraint_bp.m_transform_os_ks[1].m_elems[8];
      *(_QWORD *)&pos_Att_ws_4[56] = *(_QWORD *)&v5->m_ragdoll_constraint_bp.m_transform_os_ks[1].m_elems[10];
      hk_Matrix3::rotate(this: (hk_Matrix3 *)pos_Ref_ws_4, axis: v123, angle: *(&axis_Att_ws.y + v123));
      v26 = v123;
      if ( v123 == 2 )
      {
        axis_of_min_inertia = 0;
      }
      else
      {
        axis_of_min_inertia = v123 + 1;
        v27 = 2;
        if ( v123 == 0 )
          goto LABEL_30;
      }
      v27 = v123 - 1;
LABEL_30:
      v28 = 2 * axis_of_min_inertia;
      v29 = *(float *)&v120[v123];
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[0].m_elems[0] = *(float *)&pos_Ref_ws_4[16 * axis_of_min_inertia];
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[0].m_elems[1] = *(float *)&pos_Ref_ws_4[8 * v28 + 4];
      v30 = *(float *)&pos_Ref_ws_4[8 * v28 + 8];
      v31 = (float *)&pos_Att_ws_4[8 * v28 + 16];
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[0].m_elems[2] = v30;
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[1].m_elems[0] = *v31;
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[1].m_elems[1] = v31[1];
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[1].m_elems[2] = v31[2];
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[0].m_elems[4] = *(float *)&pos_Ref_ws_4[16 * v27];
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[0].m_elems[5] = *(float *)&pos_Ref_ws_4[16 * v27 + 4];
      v32 = (float *)&pos_Att_ws_4[16 * v27 + 16];
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[0].m_elems[6] = *(float *)&pos_Ref_ws_4[16 * v27 + 8];
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[1].m_elems[4] = *v32;
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[1].m_elems[5] = v32[1];
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[1].m_elems[6] = v32[2];
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[0].m_elems[8] = *(float *)&pos_Ref_ws_4[16 * v26];
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[0].m_elems[9] = *(float *)&pos_Ref_ws_4[16 * v26 + 4];
      v33 = (float *)&pos_Att_ws_4[16 * v26 + 16];
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[0].m_elems[10] = *(float *)&pos_Ref_ws_4[16 * v26 + 8];
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[1].m_elems[8] = *v33;
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[1].m_elems[9] = v33[1];
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[1].m_elems[10] = v33[2];
      if ( v29 > 3.1415927 && v29 < 6.2831855 )
        v120[v26] = 1078530011;
      v34 = *(float *)&v120[v26] * -0.5;
      v35 = *(float *)&v120[v26] * 0.5;
      v5->m_ragdoll_constraint_bp.m_limits[1].m_limit_is_enabled = fabs(v34 + 3.1415927) > 0.000099999997
                                                                || fabs(v35 - 3.1415927) > 0.000099999997;
      v36 = axis_of_min_inertia;
      v5->m_ragdoll_constraint_bp.m_limits[1].m_limit_min = v34;
      v5->m_ragdoll_constraint_bp.m_limits[1].m_limit_max = v35;
      v5->m_ragdoll_constraint_bp.m_axisMap[0] = v36;
      v5->m_ragdoll_constraint_bp.m_axisMap[2] = v27;
      v5->m_ragdoll_constraint_bp.m_axisMap[1] = v26;
      return 0;
    case 2:
    case 3:
      v37 = (*(_DWORD *)&a->flags & 0x800) == 0;
      limit_diff[2] = -1.0;
      limit_diff[0] = 0.0;
      if ( v37 )
      {
        qmemcpy(pos_Att_ws_4, &a->physical_core->m_world_f_core_last_psi, sizeof(pos_Att_ws_4));
        IVP_U_Matrix::vmult4(
          this: (IVP_U_Matrix *)pos_Att_ws_4,
          p_in: &a->shift_core_f_object,
          p_out: (IVP_U_Float_Point *)&pos_Att_ws_4[48]);
        p_m_translation = (const hk_Vector3 *)axis_of_min_inertia;
        v6 = bp;
        v5 = v119;
        v113.m_elems[4] = *(float *)&pos_Att_ws_4[4];
        v113.m_elems[5] = *(float *)&pos_Att_ws_4[20];
        v113.m_elems[6] = *(float *)&pos_Att_ws_4[36];
        v113.m_elems[8] = *(float *)&pos_Att_ws_4[8];
        v113.m_elems[9] = *(float *)&pos_Att_ws_4[24];
        v113.m_elems[0] = *(float *)pos_Att_ws_4;
        v113.m_elems[10] = *(float *)&pos_Att_ws_4[40];
        v113.m_elems[1] = *(float *)&pos_Att_ws_4[16];
        v113.m_translation.x = *(float *)&pos_Att_ws_4[48];
        v113.m_elems[2] = *(float *)&pos_Att_ws_4[32];
        v113.m_translation.y = *(float *)&pos_Att_ws_4[52];
        v39 = *(float *)&pos_Att_ws_4[56];
        v113.m_elems[3] = 0.0;
        v113.m_elems[7] = 0.0;
        v113.m_elems[11] = 0.0;
      }
      else
      {
        physical_core = a->physical_core;
        v113.m_elems[0] = physical_core->m_world_f_core_last_psi.rows[0].k[0];
        v113.m_elems[1] = physical_core->m_world_f_core_last_psi.rows[1].k[0];
        v113.m_elems[2] = physical_core->m_world_f_core_last_psi.rows[2].k[0];
        v113.m_elems[3] = 0.0;
        v113.m_elems[4] = physical_core->m_world_f_core_last_psi.rows[0].k[1];
        v113.m_elems[5] = physical_core->m_world_f_core_last_psi.rows[1].k[1];
        v113.m_elems[6] = physical_core->m_world_f_core_last_psi.rows[2].k[1];
        v113.m_elems[7] = 0.0;
        v113.m_elems[8] = physical_core->m_world_f_core_last_psi.rows[0].k[2];
        v113.m_elems[9] = physical_core->m_world_f_core_last_psi.rows[1].k[2];
        v113.m_elems[10] = physical_core->m_world_f_core_last_psi.rows[2].k[2];
        v113.m_elems[11] = 0.0;
        v113.m_translation.x = physical_core->m_world_f_core_last_psi.vv.k[0];
        v113.m_translation.y = physical_core->m_world_f_core_last_psi.vv.k[1];
        v39 = physical_core->m_world_f_core_last_psi.vv.k[2];
      }
      v37 = (*(_DWORD *)&b->flags & 0x800) == 0;
      v113.m_translation.z = v39;
      v113.m_translation.w = 1.0;
      if ( v37 )
      {
        qmemcpy(pos_Att_ws_4, &b->physical_core->m_world_f_core_last_psi, sizeof(pos_Att_ws_4));
        IVP_U_Matrix::vmult4(
          this: (IVP_U_Matrix *)pos_Att_ws_4,
          p_in: &b->shift_core_f_object,
          p_out: (IVP_U_Float_Point *)&pos_Att_ws_4[48]);
        p_m_translation = (const hk_Vector3 *)axis_of_min_inertia;
        v6 = bp;
        v5 = v119;
        axis_Ref_ws.y = *(float *)pos_Att_ws_4;
        axis_Ref_ws.z = *(float *)&pos_Att_ws_4[16];
        axis_Ref_ws.w = *(float *)&pos_Att_ws_4[32];
        v101 = *(float *)&pos_Att_ws_4[4];
        v100 = 0;
        v102 = *(float *)&pos_Att_ws_4[20];
        v104 = 0;
        v108 = 0;
        v103 = *(float *)&pos_Att_ws_4[36];
        v109 = *(float *)&pos_Att_ws_4[48];
        v105 = *(float *)&pos_Att_ws_4[8];
        v110 = *(float *)&pos_Att_ws_4[52];
        v106 = *(float *)&pos_Att_ws_4[24];
        v111 = *(float *)&pos_Att_ws_4[56];
        v107 = *(float *)&pos_Att_ws_4[40];
      }
      else
      {
        v40 = b->physical_core;
        axis_Ref_ws.y = v40->m_world_f_core_last_psi.rows[0].k[0];
        axis_Ref_ws.z = v40->m_world_f_core_last_psi.rows[1].k[0];
        axis_Ref_ws.w = v40->m_world_f_core_last_psi.rows[2].k[0];
        v100 = 0;
        v101 = v40->m_world_f_core_last_psi.rows[0].k[1];
        v102 = v40->m_world_f_core_last_psi.rows[1].k[1];
        v103 = v40->m_world_f_core_last_psi.rows[2].k[1];
        v104 = 0;
        v105 = v40->m_world_f_core_last_psi.rows[0].k[2];
        v106 = v40->m_world_f_core_last_psi.rows[1].k[2];
        v107 = v40->m_world_f_core_last_psi.rows[2].k[2];
        v108 = 0;
        v109 = v40->m_world_f_core_last_psi.vv.k[0];
        v110 = v40->m_world_f_core_last_psi.vv.k[1];
        v111 = v40->m_world_f_core_last_psi.vv.k[2];
      }
      v112 = 1065353216;
      hk_Vector3::set_transformed_pos(this: (hk_Vector3 *)&v114, t: &v113, v: p_m_translation);
      hk_Vector3::set_transformed_pos(
        this: (hk_Vector3 *)&pos_Ref_ws_4[48],
        t: (const hk_Transform *)&axis_Ref_ws.y,
        v: &v5->m_ragdoll_constraint_bp.m_transform_os_ks[1].m_translation);
      v41 = a->physical_core;
      v42 = v41->m_world_f_core_last_psi.vv.k[1];
      v43 = v41->m_world_f_core_last_psi.vv.k[2];
      v44 = v114 - v41->m_world_f_core_last_psi.vv.k[0];
      v45 = b->physical_core;
      v115 = v115 - v42;
      v116 = v116 - v43;
      v114 = v44;
      v46 = v45->m_world_f_core_last_psi.vv.k[2];
      v47 = *(float *)&pos_Ref_ws_4[48] - v45->m_world_f_core_last_psi.vv.k[0];
      *(float *)&pos_Ref_ws_4[52] = *(float *)&pos_Ref_ws_4[52] - v45->m_world_f_core_last_psi.vv.k[1];
      *(float *)&pos_Ref_ws_4[48] = v47;
      *(float *)&pos_Ref_ws_4[56] = *(float *)&pos_Ref_ws_4[56] - v46;
      axis_of_min_inertia = 0;
      v123 = (int)v5;
      do
      {
        hk_Vector3::set_rotated_dir(this: (hk_Vector3 *)limit_mid, t: &v113, v: (const hk_Vector3 *)v123);
        hk_Vector3::set_rotated_dir(
          this: (hk_Vector3 *)&query.m_vmq_offset,
          t: (const hk_Rotation *)&axis_Ref_ws.y,
          v: (const hk_Vector3 *)(v123 + 64));
        LODWORD(query.m_vmq_storage.m_impulse_info[1][9]) = &query.m_vmq_storage.m_dense_matrix.m_rows;
        *(_QWORD *)&query.m_vmq_storage.m_impulse_info[1][10] = 0x100000001LL;
        query.m_vmq_storage.m_dense_matrix.m_elt = (float *)4;
        hk_VM_Query_Builder<hk_VMQ_Storage<1>>::begin(
          this: (hk_VM_Query_Builder<hk_VMQ_Storage<1> > *)&cross_a.y,
          size: 1);
        m_n_queries = query.m_input[1].m_n_queries;
        v49 = limit_mid[0];
        v50 = limit_mid[1];
        v51 = a->physical_core;
        v52 = limit_mid[2];
        *(int *)((char *)&query.m_input[-11].m_n_queries + query.m_input[1].m_n_queries) = 0;
        *(_DWORD *)&query.m_vmq_storage.m_buffer_1[m_n_queries + 8] = 0;
        *(_DWORD *)&query.m_vmq_storage.m_buffer_1[m_n_queries + 4] = 0;
        *(float *)((char *)&query.m_vmq_storage.m_impulse_info[0][3] + m_n_queries) = v52;
        *(float *)((char *)&query.m_vmq_storage.m_impulse_info[0][1] + m_n_queries) = v49;
        *(float *)((char *)&query.m_input[-10].m_n_queries + m_n_queries) = v50;
        v53 = &query.m_vmq_storage.m_buffer_1[m_n_queries + 4];
        v54 = v49 * v51->m_world_f_core_last_psi.rows[0].k[0];
        v55 = (float)((float)(v51->m_world_f_core_last_psi.rows[0].k[2] * v49)
                    + (float)(v51->m_world_f_core_last_psi.rows[1].k[2] * v50))
            + (float)(v51->m_world_f_core_last_psi.rows[2].k[2] * *((float *)v53 + 6));
        v56 = v51->m_world_f_core_last_psi.rows[1].k[0];
        v57 = v51->m_world_f_core_last_psi.rows[2].k[0] * *((float *)v53 + 6);
        *((float *)v53 + 5) = (float)((float)(v51->m_world_f_core_last_psi.rows[0].k[1] * v49)
                                    + (float)(v51->m_world_f_core_last_psi.rows[1].k[1] * v50))
                            + (float)(v51->m_world_f_core_last_psi.rows[2].k[1] * *((float *)v53 + 6));
        *((float *)v53 + 6) = v55;
        v58 = (float)(v56 * v50) + v54;
        v59 = limit_mid[2];
        *((float *)v53 + 4) = v58 + v57;
        *((_DWORD *)v53 + 8) = query.m_input[1].m_vmq;
        v60 = (float *)b->physical_core;
        v61 = (char *)&query.m_vmq_storage.m_impulse_info[0][9] + query.m_input[1].m_n_queries;
        *((_DWORD *)v61 + 2) = 0;
        *((_DWORD *)v61 + 1) = 0;
        *(_DWORD *)v61 = 0;
        v62 = v49 * -1.0;
        v63 = v50 * -1.0;
        v64 = v59 * -1.0;
        *((float *)v61 + 4) = v62;
        *((float *)v61 + 5) = v63;
        *((float *)v61 + 6) = v64;
        v65 = v62;
        v66 = v64;
        v67 = (float)((float)(v60[25] * v65) + (float)(v60[29] * v63)) + (float)(v60[33] * v64);
        v68 = (float)((float)(v60[26] * v65) + (float)(v60[30] * v63)) + (float)(v60[34] * v66);
        v69 = (float)(v60[28] * v63) + (float)(v60[24] * v65);
        v70 = v60[32];
        *((float *)v61 + 5) = v67;
        *((float *)v61 + 6) = v68;
        *((float *)v61 + 4) = v69 + (float)(v70 * v66);
        *((_DWORD *)v61 + 8) = query.m_input[1].m_vmq;
        query.m_input[1].m_n_queries += 48;
        LODWORD(query.m_vmq_storage.m_dense_matrix.m_elt_buffer[1]) = ++query.m_input[1].m_vmq;
        query.m_input[0].m_n_queries = (int)query.m_input[1].m_vmq;
        hk_Rigid_Body_Core::add_to_mass_matrix_inv(
          this: (hk_Rigid_Body_Core *)v51,
          input: (hk_Core_VMQ_Input *)&query.m_vmq_storage.m_dense_matrix.m_elt_buffer[1],
          matrix_out: (hk_Dense_Matrix *)&query.m_vmq_storage.m_impulse_info[1][9],
          velocities_out: &cross_a.y);
        v71 = (hk_Rigid_Body_Core *)a->physical_core;
        LODWORD(query.m_vmq_storage.m_dense_matrix.m_elt_buffer[1]) = query.m_input[1].m_vmq;
        query.m_input[0].m_n_queries = (int)query.m_input[1].m_vmq;
        hk_Rigid_Body_Core::add_to_mass_matrix_inv(
          this: v71,
          input: query.m_input,
          matrix_out: (hk_Dense_Matrix *)&query.m_vmq_storage.m_impulse_info[1][9],
          velocities_out: &cross_a.y);
        v72 = (float)((float)(v114 * limit_mid[1]) - (float)(limit_mid[0] * v115))
            * (float)((float)(v114 * limit_mid[1]) - (float)(limit_mid[0] * v115));
        v73 = (float)((float)((float)((float)((float)(*(float *)&query.m_vmq_offset * *(float *)&pos_Ref_ws_4[56])
                                            - (float)(*(float *)&pos_Ref_ws_4[48] * v96))
                                    * (float)((float)(*(float *)&query.m_vmq_offset * *(float *)&pos_Ref_ws_4[56])
                                            - (float)(*(float *)&pos_Ref_ws_4[48] * v96)))
                            + (float)((float)((float)(v96 * *(float *)&pos_Ref_ws_4[52])
                                            - (float)(*(float *)&query.m_dense_matrix_offset
                                                    * *(float *)&pos_Ref_ws_4[56]))
                                    * (float)((float)(v96 * *(float *)&pos_Ref_ws_4[52])
                                            - (float)(*(float *)&query.m_dense_matrix_offset
                                                    * *(float *)&pos_Ref_ws_4[56]))))
                    + (float)((float)((float)(*(float *)&pos_Ref_ws_4[48] * *(float *)&query.m_dense_matrix_offset)
                                    - (float)(*(float *)&query.m_vmq_offset * *(float *)&pos_Ref_ws_4[52]))
                            * (float)((float)(*(float *)&pos_Ref_ws_4[48] * *(float *)&query.m_dense_matrix_offset)
                                    - (float)(*(float *)&query.m_vmq_offset * *(float *)&pos_Ref_ws_4[52]))))
            * b->physical_core->inv_rot_inertia.hesse_val;
        if ( (float)((float)((float)((float)((float)((float)((float)((float)(limit_mid[0] * v116)
                                                                   - (float)(v114 * limit_mid[2]))
                                                           * (float)((float)(limit_mid[0] * v116)
                                                                   - (float)(v114 * limit_mid[2])))
                                                   + (float)((float)((float)(limit_mid[2] * v115)
                                                                   - (float)(limit_mid[1] * v116))
                                                           * (float)((float)(limit_mid[2] * v115)
                                                                   - (float)(limit_mid[1] * v116))))
                                           + v72)
                                   * a->physical_core->inv_rot_inertia.hesse_val)
                           + *(float *)LODWORD(query.m_vmq_storage.m_impulse_info[1][9]))
                   + v73) > limit_diff[2] )
        {
          limit_diff[2] = (float)((float)((float)((float)((float)((float)((float)(limit_mid[0] * v116)
                                                                        - (float)(v114 * limit_mid[2]))
                                                                * (float)((float)(limit_mid[0] * v116)
                                                                        - (float)(v114 * limit_mid[2])))
                                                        + (float)((float)((float)(limit_mid[2] * v115)
                                                                        - (float)(limit_mid[1] * v116))
                                                                * (float)((float)(limit_mid[2] * v115)
                                                                        - (float)(limit_mid[1] * v116))))
                                                + v72)
                                        * a->physical_core->inv_rot_inertia.hesse_val)
                                + *(float *)LODWORD(query.m_vmq_storage.m_impulse_info[1][9]))
                        + v73;
          LODWORD(limit_diff[0]) = axis_of_min_inertia;
        }
        v123 += 16;
        ++axis_of_min_inertia;
      }
      while ( axis_of_min_inertia < 3 );
      if ( LODWORD(limit_diff[0]) == 2 )
      {
        axis_of_min_inertia = 0;
LABEL_50:
        v74 = LODWORD(limit_diff[0]) - 1;
        v123 = LODWORD(limit_diff[0]) - 1;
        goto LABEL_51;
      }
      axis_of_min_inertia = LODWORD(limit_diff[0]) + 1;
      if ( LODWORD(limit_diff[0]) != 0 )
        goto LABEL_50;
      v74 = 2;
      v123 = 2;
LABEL_51:
      v75 = (const hk_Vector3 *)axis_of_min_inertia;
      if ( *(float *)&v120[axis_of_min_inertia] > *(float *)&v120[v74] )
      {
        axis_of_min_inertia = v74;
        v123 = (int)v75;
        v74 = (int)v75;
      }
      qmemcpy(pos_Ref_ws_4, v5, 48);
      *(_QWORD *)&pos_Att_ws_4[16] = *(_QWORD *)v5->m_ragdoll_constraint_bp.m_transform_os_ks[1].m_elems;
      *(_QWORD *)&pos_Att_ws_4[24] = *(_QWORD *)&v5->m_ragdoll_constraint_bp.m_transform_os_ks[1].m_elems[2];
      *(_QWORD *)&pos_Att_ws_4[32] = *(_QWORD *)&v5->m_ragdoll_constraint_bp.m_transform_os_ks[1].m_elems[4];
      *(_QWORD *)&pos_Att_ws_4[40] = *(_QWORD *)&v5->m_ragdoll_constraint_bp.m_transform_os_ks[1].m_elems[6];
      *(_QWORD *)&pos_Att_ws_4[48] = *(_QWORD *)&v5->m_ragdoll_constraint_bp.m_transform_os_ks[1].m_elems[8];
      *(_QWORD *)&pos_Att_ws_4[56] = *(_QWORD *)&v5->m_ragdoll_constraint_bp.m_transform_os_ks[1].m_elems[10];
      hk_Matrix3::rotate(this: (hk_Matrix3 *)pos_Ref_ws_4, axis: v74, angle: *(&axis_Att_ws.y + v74));
      v76 = limit_diff[0];
      v77 = axis_of_min_inertia;
      v78 = 2 * LODWORD(limit_diff[0]);
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[0].m_elems[0] = *(float *)&pos_Ref_ws_4[16 * LODWORD(limit_diff[0])];
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[0].m_elems[1] = *(float *)&pos_Ref_ws_4[8 * v78 + 4];
      v79 = *(float *)&pos_Ref_ws_4[8 * v78 + 8];
      v80 = (float *)&pos_Att_ws_4[8 * v78 + 16];
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[0].m_elems[2] = v79;
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[1].m_elems[0] = *v80;
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[1].m_elems[1] = v80[1];
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[1].m_elems[2] = v80[2];
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[0].m_elems[4] = *(float *)&pos_Ref_ws_4[16 * v77];
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[0].m_elems[5] = *(float *)&pos_Ref_ws_4[16 * v77 + 4];
      v81 = (float *)&pos_Att_ws_4[16 * v77 + 16];
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[0].m_elems[6] = *(float *)&pos_Ref_ws_4[16 * v77 + 8];
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[1].m_elems[4] = *v81;
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[1].m_elems[5] = v81[1];
      v82 = v81[2];
      v83 = v123;
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[1].m_elems[6] = v82;
      v83 *= 2;
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[0].m_elems[8] = *(float *)&pos_Ref_ws_4[8 * v83];
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[0].m_elems[9] = *(float *)&pos_Ref_ws_4[8 * v83 + 4];
      v84 = *(float *)&pos_Ref_ws_4[8 * v83 + 8];
      v85 = (float *)&pos_Att_ws_4[8 * v83 + 16];
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[0].m_elems[10] = v84;
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[1].m_elems[8] = *v85;
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[1].m_elems[9] = v85[1];
      v5->m_ragdoll_constraint_bp.m_transform_os_ks[1].m_elems[10] = v85[2];
      LODWORD(v86) = LODWORD(v6->m_angular_limits[LODWORD(v76)].m_max) ^ _mask__NegFloat_;
      LODWORD(v87) = LODWORD(v6->m_angular_limits[LODWORD(v76)].m_min) ^ _mask__NegFloat_;
      if ( fabs(v86 + 3.1415927) > 0.000099999997 || fabs(v87 - 3.1415927) > 0.000099999997 )
      {
        v88 = limit_diff[1];
        *(_BYTE *)LODWORD(limit_diff[1]) = 1;
      }
      else
      {
        v88 = limit_diff[1];
        *(_BYTE *)LODWORD(limit_diff[1]) = 0;
      }
      *(float *)(LODWORD(v88) + 4) = v86;
      *(float *)(LODWORD(v88) + 8) = v87;
      v89 = *(float *)&v120[v123] * -0.5;
      v90 = *(float *)&v120[v123] * 0.5;
      v5->m_ragdoll_constraint_bp.m_limits[1].m_limit_is_enabled = fabs(v89 + 3.1415927) > 0.000099999997
                                                                || fabs(v90 - 3.1415927) > 0.000099999997;
      v5->m_ragdoll_constraint_bp.m_limits[1].m_limit_min = v89;
      v5->m_ragdoll_constraint_bp.m_limits[1].m_limit_max = v90;
      v91 = v6->m_angular_limits[v77].m_min;
      m_max = v6->m_angular_limits[v77].m_max;
      v5->m_ragdoll_constraint_bp.m_limits[2].m_limit_is_enabled = fabs(v91 + 3.1415927) > 0.000099999997
                                                                || fabs(m_max - 3.1415927) > 0.000099999997;
      v5->m_ragdoll_constraint_bp.m_limits[2].m_limit_min = v91;
      v5->m_ragdoll_constraint_bp.m_limits[2].m_limit_max = m_max;
      v5->m_ragdoll_constraint_bp.m_axisMap[0] = LOBYTE(v76);
      v93 = v123;
      v5->m_ragdoll_constraint_bp.m_axisMap[2] = v77;
      v5->m_ragdoll_constraint_bp.m_axisMap[1] = v93;
      return 0;
    default:
      return 1;
  }
}
