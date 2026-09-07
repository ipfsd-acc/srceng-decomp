// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/havana/havok/hk_physics/constraint/fixed/fixed_constraint.cpp
// Functions: 9
// ============================================================

#include "ivp\havana\havok\hk_physics\constraint\fixed\fixed_constraint.h"

//------------------------------------------------------------------------------
// Address: 0x10041080
// Name: public: void hk_Fixed_Constraint::write_to_blueprint(class hk_Fixed_BP __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Fixed_Constraint::write_to_blueprint(hk_Fixed_Constraint *this, hk_Fixed_BP *pOutBP)
{
  pOutBP->m_tau = this->m_tau;
  pOutBP->m_strength = this->m_strength;
  pOutBP->m_transform_os_ks.hk_Rotation = this->m_transform_os_ks.hk_Rotation;
  pOutBP->m_transform_os_ks.m_translation.x = this->m_transform_os_ks.m_translation.x;
  pOutBP->m_transform_os_ks.m_translation.y = this->m_transform_os_ks.m_translation.y;
  pOutBP->m_transform_os_ks.m_translation.z = this->m_transform_os_ks.m_translation.z;
}

//------------------------------------------------------------------------------
// Address: 0x100410F0
// Name: public: virtual int hk_Fixed_Constraint::get_vmq_storage_size(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall hk_Fixed_Constraint::get_vmq_storage_size(hk_Fixed_Constraint *this)
{
  return 1088;
}

//------------------------------------------------------------------------------
// Address: 0x10041100
// Name: protected: void hk_Fixed_Constraint::init_fixed_constraint(class hk_Fixed_BP const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Fixed_Constraint::init_fixed_constraint(hk_Fixed_Constraint *this, const hk_Fixed_BP *bp)
{
  this->m_tau = bp->m_tau;
  this->m_strength = bp->m_strength;
  this->m_transform_os_ks.hk_Rotation = bp->m_transform_os_ks.hk_Rotation;
  this->m_transform_os_ks.m_translation.x = bp->m_transform_os_ks.m_translation.x;
  this->m_transform_os_ks.m_translation.y = bp->m_transform_os_ks.m_translation.y;
  this->m_transform_os_ks.m_translation.z = bp->m_transform_os_ks.m_translation.z;
}

//------------------------------------------------------------------------------
// Address: 0x10041170
// Name: public: hk_Fixed_Constraint::hk_Fixed_Constraint(class hk_Environment __near *,class hk_Fixed_BP const __near *,class hk_Rigid_Body __near *,class hk_Rigid_Body __near *)
// Source: json
//------------------------------------------------------------------------------
hk_Fixed_Constraint *__thiscall hk_Fixed_Constraint::hk_Fixed_Constraint(
        hk_Fixed_Constraint *this,
        hk_Environment *env,
        const hk_Fixed_BP *bp,
        hk_Rigid_Body *a,
        hk_Rigid_Body *b)
{
  hk_Rigid_Body_Binary_EF::hk_Rigid_Body_Binary_EF(this, env, a, b, __formal: IVP_CP_CONSTRAINTS);
  this->m_constraint_system = nullptr;
  this->m_client_data = nullptr;
  this->__vftable = (hk_Fixed_Constraint_vtbl *)&hk_Fixed_Constraint::`vftable';
  hk_Fixed_Constraint::init_fixed_constraint(this, bp);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100411B0
// Name: public: virtual char const __near * hk_Fixed_Constraint::get_constraint_type(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall hk_Fixed_Constraint::get_constraint_type(hk_Fixed_Constraint *this)
{
  return "fixed";
}

//------------------------------------------------------------------------------
// Address: 0x100411C0
// Name: public: hk_Fixed_Constraint::hk_Fixed_Constraint(class hk_Local_Constraint_System __near *,class hk_Fixed_BP const __near *,class hk_Rigid_Body __near *,class hk_Rigid_Body __near *)
// Source: json
//------------------------------------------------------------------------------
hk_Fixed_Constraint *__thiscall hk_Fixed_Constraint::hk_Fixed_Constraint(
        hk_Fixed_Constraint *this,
        hk_Local_Constraint_System *constraint_system,
        const hk_Fixed_BP *bp,
        hk_Rigid_Body *a,
        hk_Rigid_Body *b)
{
  hk_Constraint::hk_Constraint(
    this,
    sys: constraint_system,
    a,
    b,
    redundend_prio: IVP_CP_CONSTRAINTS,
    storage_size: 1088);
  this->__vftable = (hk_Fixed_Constraint_vtbl *)&hk_Fixed_Constraint::`vftable';
  hk_Fixed_Constraint::init_fixed_constraint(this, bp);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10041200
// Name: public: virtual void hk_Fixed_Constraint::init_constraint(void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Fixed_Constraint::init_constraint(hk_Fixed_Constraint *this, const hk_Fixed_BP *vbp)
{
  hk_Fixed_Constraint::init_fixed_constraint(this, bp: vbp);
}

//------------------------------------------------------------------------------
// Address: 0x10041210
// Name: public: virtual void hk_Fixed_Constraint::step_constraint(class hk_PSI_Info __near &,void __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge hk_Fixed_Constraint::step_constraint(
        hk_Fixed_Constraint *this@<ecx>,
        int a2@<ebp>,
        hk_PSI_Info *pi,
        char *mem,
        float tau_factor,
        float strength_factor)
{
  hk_Rigid_Body *v6; // edx
  float *physical_core; // esi
  float *v8; // ecx
  float *v9; // edx
  int v10; // edi
  float v11; // xmm0_4
  bool v12; // sf
  IVP_Core *v13; // esi
  float *v14; // edi
  int v15; // ecx
  float *v16; // edx
  int v17; // ecx
  float v18; // xmm0_4
  float v19; // xmm0_4
  int v20; // edx
  float *v21; // ecx
  float v22; // xmm3_4
  const float *v23[3]; // [esp-Ch] [ebp-8Ch] BYREF
  hk_Fixed_Dense_Vector<6> impulses; // [esp+0h] [ebp-80h] BYREF
  hk_Fixed_Dense_Vector<6> delta; // [esp+30h] [ebp-50h] BYREF
  hk_Rigid_Body *v26; // [esp+60h] [ebp-20h]
  hk_Core_VMQ_Input *v27; // [esp+64h] [ebp-1Ch]
  hk_Fixed_Constraint *v28; // [esp+68h] [ebp-18h]
  hk_Rigid_Body *b0; // [esp+6Ch] [ebp-14h]
  int v30; // [esp+70h] [ebp-10h]
  int v31; // [esp+74h] [ebp-Ch]
  hk_Rigid_Body *b1; // [esp+78h] [ebp-8h]
  hk_Rigid_Body *retaddr; // [esp+80h] [ebp+0h]

  v31 = a2;
  b1 = retaddr;
  v6 = this->m_entities[0];
  physical_core = (float *)v6->physical_core;
  b0 = this->m_entities[1];
  v26 = v6;
  v28 = this;
  *((_QWORD *)mem + 7) = 0;
  *((_QWORD *)mem + 6) = 0;
  *((_QWORD *)mem + 9) = 0;
  *((_QWORD *)mem + 8) = 0;
  v30 = *((_DWORD *)mem + 264) - 1;
  v8 = *((float **)mem + 265);
  v27 = (hk_Core_VMQ_Input *)(mem + 1056);
  v9 = v8 + 6;
  do
  {
    v10 = *((_DWORD *)v9 + 2);
    v11 = (float)((float)((float)((float)(*(v9 - 5) * physical_core[53]) + (float)(*v8 * physical_core[52]))
                        + (float)(*(v9 - 4) * physical_core[54]))
                + (float)((float)((float)(*(v9 - 1) * physical_core[49]) + (float)(*(v9 - 2) * physical_core[48]))
                        + (float)(physical_core[50] * *v9)))
        + *(float *)&mem[4 * v10 + 48];
    v8 += 12;
    v9 += 12;
    v12 = --v30 < 0;
    *(float *)&mem[4 * v10 + 48] = v11;
  }
  while ( !v12 );
  v13 = b0->physical_core;
  v14 = *((float **)mem + 268);
  v15 = *((_DWORD *)mem + 267) - 1;
  LODWORD(delta.m_elt_buffer[7]) = mem + 1068;
  v30 = v15;
  v16 = v14 + 6;
  do
  {
    v17 = *((_DWORD *)v16 + 2);
    v18 = (float)((float)((float)((float)(*(v16 - 5) * v13->speed.k[1]) + (float)(*v14 * v13->speed.k[0]))
                        + (float)(*(v16 - 4) * v13->speed.k[2]))
                + (float)((float)((float)(*(v16 - 2) * v13->rot_speed.k[0]) + (float)(*(v16 - 1) * v13->rot_speed.k[1]))
                        + (float)(v13->rot_speed.k[2] * *v16)))
        + *(float *)&mem[4 * v17 + 48];
    v14 += 12;
    v16 += 12;
    v12 = --v30 < 0;
    *(float *)&mem[4 * v17 + 48] = v18;
  }
  while ( !v12 );
  v19 = (float)(v28->m_strength * -1.0) * strength_factor;
  LODWORD(impulses.m_elt_buffer[5]) = &delta.m_size;
  LODWORD(impulses.m_elt_buffer[6]) = 6;
  LODWORD(impulses.m_elt_buffer[7]) = 8;
  v20 = 5;
  v21 = (float *)(mem + 32);
  do
  {
    v22 = *v21;
    *(float *)((char *)v21 + (char *)&impulses.m_elt_buffer[6] - mem) = (float)(*(float *)&mem[4 * v20 + 48] * v19)
                                                                      + (float)(v21[1] * tau_factor);
    *(float *)((char *)v21 + (char *)&impulses.m_elt_buffer[5] - mem) = (float)(*(float *)&mem[4 * v20 + 44] * v19)
                                                                      + (float)(v22 * tau_factor);
    v20 -= 2;
    v21 -= 2;
  }
  while ( v20 > 0 );
  v23[0] = (const float *)&impulses.m_size;
  v23[1] = (const float *)6;
  v23[2] = (const float *)8;
  hk_Dense_Matrix_Util::mult(
    m: (const hk_Dense_Matrix *)mem + 53,
    in: (hk_Fixed_Dense_Vector<6> *)&impulses.m_elt_buffer[5],
    out: (hk_Dense_Vector *)v23);
  hk_Rigid_Body_Core::apply_impulses(
    this: (hk_Rigid_Body_Core *)v26->physical_core,
    input: v27,
    impulse_strength: v23[0]);
  hk_Rigid_Body_Core::apply_impulses(
    this: (hk_Rigid_Body_Core *)b0->physical_core,
    input: (hk_Core_VMQ_Input *)LODWORD(delta.m_elt_buffer[7]),
    impulse_strength: v23[0]);
}

//------------------------------------------------------------------------------
// Address: 0x10041580
// Name: public: virtual int hk_Fixed_Constraint::setup_and_step_constraint(class hk_PSI_Info __near &,void __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __userpurge hk_Fixed_Constraint::setup_and_step_constraint@<eax>(
        hk_Fixed_Constraint *this@<ecx>,
        int a2@<ebp>,
        hk_PSI_Info *pi,
        char *mem,
        float tau_factor,
        float strength_factor)
{
  char *v6; // esi
  hk_Rigid_Body *v7; // eax
  bool v8; // zf
  hk_Rigid_Body *v9; // edx
  IVP_Core *physical_core; // eax
  float v11; // xmm0_4
  IVP_Core *v12; // eax
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  char *v17; // esi
  float v18; // edi
  hk_Virtual_Mass_Query *v19; // eax
  hk_Rigid_Body *v20; // edx
  float v21; // xmm3_4
  float v22; // xmm2_4
  float v23; // xmm1_4
  float *v24; // eax
  float v25; // xmm5_4
  float v26; // xmm0_4
  float v27; // xmm4_4
  int v28; // eax
  float *v29; // ecx
  float v30; // xmm5_4
  float v31; // xmm1_4
  float v32; // xmm7_4
  float v33; // xmm6_4
  float v34; // xmm5_4
  int v35; // eax
  float *v36; // ecx
  float v37; // xmm7_4
  float v38; // xmm6_4
  float v39; // xmm7_4
  float v40; // xmm5_4
  float v41; // xmm6_4
  float v42; // xmm7_4
  float v43; // xmm6_4
  float v44; // xmm7_4
  float v45; // xmm6_4
  int v46; // eax
  int v47; // eax
  float *v48; // ecx
  float v49; // xmm3_4
  float v50; // xmm6_4
  float v51; // xmm7_4
  float v52; // xmm3_4
  int v53; // eax
  int v54; // eax
  float *v55; // ecx
  float v56; // xmm3_4
  float v57; // xmm5_4
  float v58; // xmm6_4
  float v59; // xmm3_4
  float v60; // xmm7_4
  float v61; // xmm6_4
  float v62; // xmm7_4
  float v63; // xmm6_4
  float v64; // xmm7_4
  float v65; // xmm6_4
  int v66; // eax
  int v67; // eax
  float *v68; // ecx
  float v69; // xmm2_4
  float v70; // xmm6_4
  float v71; // xmm5_4
  float v72; // xmm7_4
  float v73; // xmm7_4
  float v74; // xmm2_4
  int v75; // eax
  int v76; // eax
  float v77; // xmm5_4
  float v78; // xmm4_4
  float *v79; // ecx
  float v80; // xmm2_4
  float v81; // xmm3_4
  float v82; // xmm4_4
  float v83; // xmm7_4
  float v84; // xmm2_4
  int v85; // eax
  int v86; // eax
  float w; // xmm2_4
  float *v88; // ecx
  float v89; // xmm4_4
  float v90; // xmm5_4
  float v91; // xmm6_4
  float v92; // xmm2_4
  float v93; // xmm3_4
  float v94; // xmm7_4
  float v95; // xmm4_4
  int v96; // eax
  int v97; // eax
  float v98; // xmm2_4
  float *v99; // ecx
  float v100; // xmm4_4
  float v101; // xmm5_4
  float v102; // xmm6_4
  float v103; // xmm2_4
  float v104; // xmm3_4
  float v105; // xmm7_4
  float v106; // xmm4_4
  int v107; // eax
  float v108; // xmm2_4
  float *v109; // ecx
  float v110; // xmm4_4
  float v111; // xmm5_4
  float v112; // xmm6_4
  float v113; // xmm2_4
  float v114; // xmm3_4
  float v115; // xmm7_4
  float v116; // xmm4_4
  int v117; // eax
  int v118; // eax
  float v119; // xmm2_4
  float *v120; // ecx
  float v121; // xmm4_4
  float v122; // xmm5_4
  float v123; // xmm6_4
  float v124; // xmm2_4
  float v125; // xmm3_4
  int v126; // eax
  float v127; // xmm2_4
  float *v128; // ecx
  float v129; // xmm4_4
  float v130; // xmm5_4
  int v131; // eax
  float v132; // xmm6_4
  float v133; // xmm2_4
  float v134; // xmm3_4
  float v135; // xmm7_4
  float v136; // xmm4_4
  int v137; // eax
  int v138; // eax
  float v139; // xmm0_4
  float *v140; // ecx
  float v141; // xmm2_4
  float v142; // xmm3_4
  float v143; // xmm4_4
  float v144; // xmm0_4
  float v145; // xmm1_4
  float v146; // xmm5_4
  float v147; // xmm2_4
  int v148; // ecx
  hk_Rigid_Body_Core *v149; // ecx
  int v150; // eax
  hk_Core_VMQ_Input *v151; // ecx
  hk_Core_VMQ_Input *v152; // edx
  char *v153; // ecx
  int v154; // eax
  float v155; // xmm1_4
  float v156; // xmm2_4
  float v157; // xmm3_4
  float v158; // xmm4_4
  float i_delta_time; // xmm1_4
  float v160; // xmm0_4
  float v161; // xmm1_4
  float v162; // xmm0_4
  float v163; // xmm1_4
  float v164; // xmm0_4
  float v165; // xmm2_4
  float v166; // xmm1_4
  float v167; // xmm0_4
  float *v168; // eax
  char *v169; // edx
  int i; // ecx
  float v171; // xmm3_4
  hk_Fixed_Work *v172; // esi
  float v174; // [esp+18h] [ebp-1A8h]
  hk_Mass_Relative_Vector3 mcr_0; // [esp+20h] [ebp-1A0h] BYREF
  hk_Fixed_Dense_Vector<6> delta; // [esp+30h] [ebp-190h] BYREF
  _BYTE impulses_4[96]; // [esp+64h] [ebp-15Ch] OVERLAPPED BYREF
  float v178; // [esp+C4h] [ebp-FCh]
  float v179; // [esp+CCh] [ebp-F4h]
  hk_Mass_Relative_Vector3 mcr_1; // [esp+D0h] [ebp-F0h] BYREF
  hk_Matrix3 joint_axes_ws; // [esp+E0h] [ebp-E0h]
  _BYTE position_ws_4[64]; // [esp+114h] [ebp-ACh] OVERLAPPED BYREF
  hk_Matrix3 v183; // [esp+154h] [ebp-6Ch] BYREF
  float v184; // [esp+184h] [ebp-3Ch]
  float v185; // [esp+188h] [ebp-38h]
  float v186; // [esp+18Ch] [ebp-34h]
  int v187; // [esp+190h] [ebp-30h]
  hk_Rigid_Body *v188; // [esp+19Ch] [ebp-24h]
  float v189; // [esp+1A0h] [ebp-20h]
  char *v190; // [esp+1A4h] [ebp-1Ch]
  hk_Rigid_Body *b1; // [esp+1A8h] [ebp-18h]
  float v192; // [esp+1ACh] [ebp-14h]
  hk_Fixed_Work *work; // [esp+1B0h] [ebp-10h]
  int v194; // [esp+1B4h] [ebp-Ch]
  hk_Rigid_Body *b0; // [esp+1B8h] [ebp-8h]
  hk_Rigid_Body *retaddr; // [esp+1C0h] [ebp+0h]

  v194 = a2;
  b0 = retaddr;
  v6 = (char *)this;
  v7 = this->m_entities[0];
  v8 = (*(_DWORD *)&v7->flags & 0x800) == 0;
  v9 = this->m_entities[1];
  b1 = (hk_Rigid_Body *)this;
  v192 = *(float *)&v7;
  v188 = v9;
  if ( v8 )
  {
    qmemcpy(position_ws_4, &v7->physical_core->m_world_f_core_last_psi, sizeof(position_ws_4));
    IVP_U_Matrix::vmult4(
      this: (IVP_U_Matrix *)position_ws_4,
      p_in: &v7->shift_core_f_object,
      p_out: (IVP_U_Float_Point *)&position_ws_4[48]);
    v9 = v188;
    v6 = (char *)b1;
    v183.m_elems[0] = *(float *)position_ws_4;
    v183.m_elems[4] = *(float *)&position_ws_4[4];
    v183.m_elems[1] = *(float *)&position_ws_4[16];
    v183.m_elems[5] = *(float *)&position_ws_4[20];
    v183.m_elems[2] = *(float *)&position_ws_4[32];
    v183.m_elems[6] = *(float *)&position_ws_4[36];
    v183.m_elems[3] = 0.0;
    v183.m_elems[7] = 0.0;
    v183.m_elems[11] = 0.0;
    v183.m_elems[8] = *(float *)&position_ws_4[8];
    v184 = *(float *)&position_ws_4[48];
    v183.m_elems[9] = *(float *)&position_ws_4[24];
    v185 = *(float *)&position_ws_4[52];
    v11 = *(float *)&position_ws_4[56];
    v183.m_elems[10] = *(float *)&position_ws_4[40];
  }
  else
  {
    physical_core = v7->physical_core;
    v183.m_elems[0] = physical_core->m_world_f_core_last_psi.rows[0].k[0];
    v183.m_elems[1] = physical_core->m_world_f_core_last_psi.rows[1].k[0];
    v183.m_elems[2] = physical_core->m_world_f_core_last_psi.rows[2].k[0];
    v183.m_elems[3] = 0.0;
    v183.m_elems[4] = physical_core->m_world_f_core_last_psi.rows[0].k[1];
    v183.m_elems[5] = physical_core->m_world_f_core_last_psi.rows[1].k[1];
    v183.m_elems[6] = physical_core->m_world_f_core_last_psi.rows[2].k[1];
    v183.m_elems[7] = 0.0;
    v183.m_elems[8] = physical_core->m_world_f_core_last_psi.rows[0].k[2];
    v183.m_elems[9] = physical_core->m_world_f_core_last_psi.rows[1].k[2];
    *(_QWORD *)&v183.m_elems[10] = LODWORD(physical_core->m_world_f_core_last_psi.rows[2].k[2]);
    v184 = physical_core->m_world_f_core_last_psi.vv.k[0];
    v185 = physical_core->m_world_f_core_last_psi.vv.k[1];
    v11 = physical_core->m_world_f_core_last_psi.vv.k[2];
  }
  v186 = v11;
  v187 = 1065353216;
  if ( (*(_DWORD *)&v9->flags & 0x800) != 0 )
  {
    v12 = v9->physical_core;
    *(float *)position_ws_4 = v12->m_world_f_core_last_psi.rows[0].k[0];
    *(float *)&position_ws_4[4] = v12->m_world_f_core_last_psi.rows[1].k[0];
    *(float *)&position_ws_4[8] = v12->m_world_f_core_last_psi.rows[2].k[0];
    *(float *)&position_ws_4[16] = v12->m_world_f_core_last_psi.rows[0].k[1];
    *(float *)&position_ws_4[20] = v12->m_world_f_core_last_psi.rows[1].k[1];
    *(float *)&position_ws_4[24] = v12->m_world_f_core_last_psi.rows[2].k[1];
    *(float *)&position_ws_4[48] = v12->m_world_f_core_last_psi.vv.k[0];
    *(float *)&position_ws_4[52] = v12->m_world_f_core_last_psi.vv.k[1];
    v13 = v12->m_world_f_core_last_psi.vv.k[2];
  }
  else
  {
    qmemcpy(&impulses_4[32], &v9->physical_core->m_world_f_core_last_psi, 0x40u);
    IVP_U_Matrix::vmult4(
      this: (IVP_U_Matrix *)&impulses_4[32],
      p_in: &v9->shift_core_f_object,
      p_out: (IVP_U_Float_Point *)&impulses_4[80]);
    v6 = (char *)b1;
    *(_DWORD *)position_ws_4 = *(_DWORD *)&impulses_4[32];
    *(_DWORD *)&position_ws_4[4] = *(_DWORD *)&impulses_4[48];
    *(_DWORD *)&position_ws_4[8] = *(_DWORD *)&impulses_4[64];
    *(_DWORD *)&position_ws_4[16] = *(_DWORD *)&impulses_4[36];
    *(_DWORD *)&position_ws_4[20] = *(_DWORD *)&impulses_4[52];
    *(_DWORD *)&position_ws_4[24] = *(_DWORD *)&impulses_4[68];
    *(_DWORD *)&position_ws_4[48] = *(_DWORD *)&impulses_4[80];
    *(_DWORD *)&position_ws_4[52] = *(_DWORD *)&impulses_4[84];
    v13 = *(float *)&impulses_4[88];
  }
  *(float *)&position_ws_4[56] = v13;
  hk_Matrix3::set_mul3(this: (hk_Matrix3 *)&mcr_1.m_vector.y, Ma: &v183, Mb: (const hk_Matrix3 *)(v6 + 32));
  v14 = *((float *)v6 + 21);
  v15 = *((float *)v6 + 20);
  v16 = *((float *)v6 + 22);
  joint_axes_ws.m_elems[9] = (float)((float)((float)(v15 * v183.m_elems[0]) + (float)(v14 * v183.m_elems[4]))
                                   + (float)(v16 * v183.m_elems[8]))
                           + v184;
  joint_axes_ws.m_elems[10] = (float)((float)((float)(v14 * v183.m_elems[5]) + (float)(v15 * v183.m_elems[1]))
                                    + (float)(v16 * v183.m_elems[9]))
                            + v185;
  joint_axes_ws.m_elems[11] = (float)((float)((float)(v14 * v183.m_elems[6]) + (float)(v15 * v183.m_elems[2]))
                                    + (float)(v16 * v183.m_elems[10]))
                            + v186;
  if ( mem != nullptr )
  {
    *(_DWORD *)mem = mem + 16;
    *((_DWORD *)mem + 1) = 6;
    *((_DWORD *)mem + 2) = 8;
    *((_DWORD *)mem + 212) = mem + 864;
    *((_DWORD *)mem + 213) = 6;
    *((_DWORD *)mem + 214) = 6;
    *((_DWORD *)mem + 215) = 8;
    v190 = mem;
  }
  else
  {
    v190 = nullptr;
  }
  v17 = v190 + 48;
  hk_VM_Query_Builder<hk_VMQ_Storage<6>>::begin(this: (hk_VM_Query_Builder<hk_VMQ_Storage<6> > *)(v190 + 48), size: 6);
  v18 = v192;
  v19 = *(hk_Virtual_Mass_Query **)(LODWORD(v192) + 148);
  v20 = v188;
  v21 = joint_axes_ws.m_elems[11] - v19[3].m_linear.z;
  v22 = joint_axes_ws.m_elems[9] - v19[3].m_linear.x;
  v23 = joint_axes_ws.m_elems[10] - v19[3].m_linear.y;
  v24 = (float *)v188->physical_core;
  v25 = joint_axes_ws.m_elems[9] - v24[36];
  v26 = joint_axes_ws.m_elems[11] - v24[38];
  v27 = joint_axes_ws.m_elems[10] - v24[37];
  v28 = (int)&v17[*((_DWORD *)v17 + 258) + 224];
  v178 = v25;
  v179 = v26;
  *(_DWORD *)(v28 + 8) = 0;
  *(_DWORD *)(v28 + 4) = 0;
  *(_DWORD *)v28 = 1065353216;
  *(_DWORD *)(v28 + 16) = 0;
  *(float *)(v28 + 20) = v21;
  v174 = v23;
  *(_DWORD *)(v28 + 24) = LODWORD(v23) ^ _mask__NegFloat_;
  v29 = *(float **)(LODWORD(v18) + 148);
  v30 = (float)((float)(v29[25] * 0.0) + (float)(v29[29] * v21)) + (float)(v29[33] * *(float *)(v28 + 24));
  v31 = 0.0 * v29[24];
  v32 = v29[28];
  v192 = (float)((float)(v29[26] * 0.0) + (float)(v29[30] * v21)) + (float)(v29[34] * *(float *)(v28 + 24));
  v33 = v29[32] * *(float *)(v28 + 24);
  *(float *)(v28 + 20) = v30;
  v34 = v179;
  *(float *)(v28 + 24) = v192;
  *(float *)(v28 + 16) = (float)((float)(v32 * v21) + v31) + v33;
  *(_DWORD *)(v28 + 32) = *((_DWORD *)v17 + 259);
  v35 = (int)&v17[*((_DWORD *)v17 + 258) + 512];
  *(_DWORD *)(v35 + 8) = 0;
  *(_DWORD *)(v35 + 4) = 0;
  *(_DWORD *)v35 = -1082130432;
  *(float *)(v35 + 20) = v34 * -1.0;
  *(_DWORD *)(v35 + 16) = 0;
  *(float *)(v35 + 24) = v27;
  v36 = (float *)v20->physical_core;
  *(float *)&work = v36[25] * 0.0;
  v37 = v36[33];
  *(float *)&work = *(float *)&work + (float)(v36[29] * *(float *)(v35 + 20));
  v38 = *(float *)&work + (float)(v37 * v27);
  v39 = v36[30] * *(float *)(v35 + 20);
  v192 = v38;
  v40 = 0.0 * v36[24];
  v41 = (float)(v36[26] * 0.0) + v39;
  v42 = v36[34];
  *(float *)&work = v41;
  v43 = v41 + (float)(v42 * v27);
  v44 = (float)(v36[28] * *(float *)(v35 + 20)) + v40;
  v189 = v43;
  v45 = v36[32] * v27;
  *(float *)(v35 + 20) = v192;
  *(float *)(v35 + 24) = v189;
  *(float *)(v35 + 16) = v44 + v45;
  *(_DWORD *)(v35 + 32) = *((_DWORD *)v17 + 259);
  v46 = *((_DWORD *)v17 + 258);
  *(_DWORD *)&v17[v46 + 280] = 0;
  *(_DWORD *)&v17[v46 + 272] = 0;
  *(_DWORD *)&v17[v46 + 276] = 1065353216;
  *(_DWORD *)&v17[v46 + 288] = LODWORD(v21) ^ _mask__NegFloat_;
  v47 = (int)&v17[v46 + 272];
  *(_DWORD *)(v47 + 20) = 0;
  *(float *)(v47 + 24) = v22;
  v48 = *(float **)(LODWORD(v18) + 148);
  v49 = (float)((float)(v48[25] * *(float *)(v47 + 16)) + (float)(v48[29] * 0.0)) + (float)(v48[33] * v22);
  v50 = (float)(v48[28] * 0.0) + (float)(v48[24] * *(float *)(v47 + 16));
  v51 = v48[32];
  v192 = (float)((float)(v48[26] * *(float *)(v47 + 16)) + (float)(v48[30] * 0.0)) + (float)(v48[34] * v22);
  *(float *)(v47 + 16) = v50 + (float)(v51 * v22);
  *(float *)(v47 + 20) = v49;
  *(float *)(v47 + 24) = v192;
  v52 = v179;
  *(_DWORD *)(v47 + 32) = *((_DWORD *)v17 + 259) + 1;
  v53 = *((_DWORD *)v17 + 258);
  *(_DWORD *)&v17[v53 + 568] = 0;
  *(_DWORD *)&v17[v53 + 560] = 0;
  *(_DWORD *)&v17[v53 + 564] = -1082130432;
  *(float *)&v17[v53 + 576] = v52;
  *(_DWORD *)&v17[v53 + 580] = 0;
  v54 = (int)&v17[v53 + 560];
  *(float *)(v54 + 24) = v178 * -1.0;
  v55 = (float *)v20->physical_core;
  v56 = *(float *)(v54 + 16);
  v57 = (float)((float)(v55[25] * v56) + (float)(v55[29] * 0.0)) + (float)(v55[33] * *(float *)(v54 + 24));
  v58 = v55[26] * v56;
  v59 = v56 * v55[24];
  v60 = v55[30] * 0.0;
  *(float *)&work = v58;
  v61 = v58 + v60;
  v62 = v55[34] * *(float *)(v54 + 24);
  *(float *)&work = v61;
  v63 = v61 + v62;
  v64 = (float)(v55[28] * 0.0) + v59;
  v192 = v63;
  v65 = v55[32] * *(float *)(v54 + 24);
  *(float *)(v54 + 24) = v192;
  *(float *)(v54 + 20) = v57;
  *(float *)(v54 + 16) = v64 + v65;
  *(_DWORD *)(v54 + 32) = *((_DWORD *)v17 + 259) + 1;
  v66 = *((_DWORD *)v17 + 258);
  *(_DWORD *)&v17[v66 + 324] = 0;
  *(_DWORD *)&v17[v66 + 320] = 0;
  *(_DWORD *)&v17[v66 + 328] = 1065353216;
  v67 = (int)&v17[v66 + 320];
  *(float *)(v67 + 16) = v174;
  *(_DWORD *)(v67 + 20) = LODWORD(v22) ^ _mask__NegFloat_;
  *(_DWORD *)(v67 + 24) = 0;
  v68 = *(float **)(LODWORD(v18) + 148);
  v69 = v174 * v68[24];
  v70 = v68[32];
  v71 = (float)((float)(v68[26] * v174) + (float)(v68[30] * *(float *)(v67 + 20))) + (float)(v68[34] * 0.0);
  v72 = v68[28] * *(float *)(v67 + 20);
  *(float *)(v67 + 20) = (float)((float)(v68[25] * v174) + (float)(v68[29] * *(float *)(v67 + 20)))
                       + (float)(v68[33] * 0.0);
  *(float *)(v67 + 24) = v71;
  v73 = v72 + v69;
  v74 = v178;
  *(float *)(v67 + 16) = v73 + (float)(v70 * 0.0);
  *(_DWORD *)(v67 + 32) = *((_DWORD *)v17 + 259) + 2;
  v75 = *((_DWORD *)v17 + 258);
  *(_DWORD *)&v17[v75 + 612] = 0;
  *(_DWORD *)&v17[v75 + 608] = 0;
  *(_DWORD *)&v17[v75 + 616] = -1082130432;
  *(float *)&v17[v75 + 628] = v74;
  *(_DWORD *)&v17[v75 + 632] = 0;
  v76 = (int)&v17[v75 + 608];
  v77 = v74;
  v78 = v27 * -1.0;
  *(float *)(v76 + 16) = v78;
  v79 = (float *)v20->physical_core;
  v80 = v78;
  v81 = (float)((float)(v79[25] * v78) + (float)(v79[29] * v77)) + (float)(v79[33] * 0.0);
  v82 = (float)((float)(v79[26] * v78) + (float)(v79[30] * v77)) + (float)(v79[34] * 0.0);
  v83 = (float)(v79[28] * v77) + (float)(v80 * v79[24]);
  v84 = v79[32];
  *(float *)(v76 + 20) = v81;
  *(float *)(v76 + 24) = v82;
  *(float *)(v76 + 16) = v83 + (float)(v84 * 0.0);
  *(_DWORD *)(v76 + 32) = *((_DWORD *)v17 + 259) + 2;
  v85 = *((_DWORD *)v17 + 258);
  *(_DWORD *)&v17[v85 + 376] = 0;
  *(_DWORD *)&v17[v85 + 372] = 0;
  *(_DWORD *)&v17[v85 + 368] = 0;
  v86 = (int)&v17[v85 + 368];
  *(float *)(v86 + 16) = mcr_1.m_vector.y;
  *(float *)(v86 + 20) = mcr_1.m_vector.z;
  w = mcr_1.m_vector.w;
  *(float *)(v86 + 24) = mcr_1.m_vector.w;
  v88 = *(float **)(LODWORD(v18) + 148);
  v89 = *(float *)(v86 + 20);
  v90 = *(float *)(v86 + 16);
  v91 = w;
  v92 = (float)((float)(v88[25] * v90) + (float)(v88[29] * v89)) + (float)(v88[33] * w);
  v93 = (float)((float)(v88[26] * v90) + (float)(v88[30] * v89)) + (float)(v88[34] * v91);
  v94 = (float)(v88[28] * v89) + (float)(v88[24] * v90);
  v95 = v88[32];
  *(float *)(v86 + 20) = v92;
  *(float *)(v86 + 24) = v93;
  *(float *)(v86 + 16) = v94 + (float)(v95 * v91);
  *(_DWORD *)(v86 + 32) = *((_DWORD *)v17 + 259) + 3;
  v96 = *((_DWORD *)v17 + 258);
  *(_DWORD *)&v17[v96 + 664] = 0;
  *(_DWORD *)&v17[v96 + 660] = 0;
  *(_DWORD *)&v17[v96 + 656] = 0;
  v97 = (int)&v17[v96 + 656];
  *(float *)(v97 + 16) = mcr_1.m_vector.y * -1.0;
  *(float *)(v97 + 20) = mcr_1.m_vector.z * -1.0;
  v98 = mcr_1.m_vector.w * -1.0;
  *(float *)(v97 + 24) = mcr_1.m_vector.w * -1.0;
  v99 = (float *)v20->physical_core;
  v100 = *(float *)(v97 + 20);
  v101 = *(float *)(v97 + 16);
  v102 = v98;
  v103 = (float)((float)(v99[25] * v101) + (float)(v99[29] * v100)) + (float)(v99[33] * v98);
  v104 = (float)((float)(v99[26] * v101) + (float)(v99[30] * v100)) + (float)(v99[34] * v102);
  v105 = (float)(v99[28] * v100) + (float)(v99[24] * v101);
  v106 = v99[32];
  *(float *)(v97 + 20) = v103;
  *(float *)(v97 + 24) = v104;
  *(float *)(v97 + 16) = v105 + (float)(v106 * v102);
  *(_DWORD *)(v97 + 32) = *((_DWORD *)v17 + 259) + 3;
  v107 = (int)&v17[*((_DWORD *)v17 + 258) + 416];
  *(_DWORD *)(v107 + 8) = 0;
  *(_DWORD *)(v107 + 4) = 0;
  *(_DWORD *)v107 = 0;
  *(float *)(v107 + 16) = joint_axes_ws.m_elems[1];
  *(float *)(v107 + 20) = joint_axes_ws.m_elems[2];
  v108 = joint_axes_ws.m_elems[3];
  *(float *)(v107 + 24) = joint_axes_ws.m_elems[3];
  v109 = *(float **)(LODWORD(v18) + 148);
  v110 = *(float *)(v107 + 20);
  v111 = *(float *)(v107 + 16);
  v112 = v108;
  v113 = (float)((float)(v109[25] * v111) + (float)(v109[29] * v110)) + (float)(v109[33] * v108);
  v114 = (float)((float)(v109[26] * v111) + (float)(v109[30] * v110)) + (float)(v109[34] * v112);
  v115 = (float)(v109[28] * v110) + (float)(v109[24] * v111);
  v116 = v109[32];
  *(float *)(v107 + 20) = v113;
  *(float *)(v107 + 24) = v114;
  *(float *)(v107 + 16) = v115 + (float)(v116 * v112);
  *(_DWORD *)(v107 + 32) = *((_DWORD *)v17 + 259) + 4;
  v117 = *((_DWORD *)v17 + 258);
  *(_DWORD *)&v17[v117 + 712] = 0;
  *(_DWORD *)&v17[v117 + 708] = 0;
  *(_DWORD *)&v17[v117 + 704] = 0;
  v118 = (int)&v17[v117 + 704];
  *(float *)(v118 + 16) = joint_axes_ws.m_elems[1] * -1.0;
  *(float *)(v118 + 20) = joint_axes_ws.m_elems[2] * -1.0;
  v119 = joint_axes_ws.m_elems[3] * -1.0;
  *(float *)(v118 + 24) = joint_axes_ws.m_elems[3] * -1.0;
  v120 = (float *)v20->physical_core;
  v121 = *(float *)(v118 + 20);
  v122 = *(float *)(v118 + 16);
  v123 = v119;
  v124 = (float)((float)(v120[25] * v122) + (float)(v120[29] * v121)) + (float)(v120[33] * v119);
  v125 = (float)((float)(v120[26] * v122) + (float)(v120[30] * v121)) + (float)(v120[34] * v123);
  *(float *)(v118 + 16) = (float)((float)(v120[28] * v121) + (float)(v120[24] * v122)) + (float)(v120[32] * v123);
  *(float *)(v118 + 20) = v124;
  *(float *)(v118 + 24) = v125;
  *(_DWORD *)(v118 + 32) = *((_DWORD *)v17 + 259) + 4;
  v126 = *((_DWORD *)v17 + 258);
  *(_DWORD *)&v17[v126 + 472] = 0;
  *(_DWORD *)&v17[v126 + 468] = 0;
  *(_DWORD *)&v17[v126 + 464] = 0;
  *(float *)&v17[v126 + 480] = joint_axes_ws.m_elems[5];
  *(float *)&v17[v126 + 484] = joint_axes_ws.m_elems[6];
  v127 = joint_axes_ws.m_elems[7];
  *(float *)&v17[v126 + 488] = joint_axes_ws.m_elems[7];
  v128 = *(float **)(LODWORD(v18) + 148);
  v129 = *(float *)&v17[v126 + 484];
  v130 = *(float *)&v17[v126 + 480];
  v131 = (int)&v17[v126 + 464];
  v132 = v127;
  v133 = (float)((float)(v128[25] * v130) + (float)(v128[29] * v129)) + (float)(v128[33] * v127);
  v134 = (float)((float)(v128[26] * v130) + (float)(v128[30] * v129)) + (float)(v128[34] * v132);
  v135 = (float)(v128[28] * v129) + (float)(v128[24] * v130);
  v136 = v128[32];
  *(float *)(v131 + 20) = v133;
  *(float *)(v131 + 24) = v134;
  *(float *)(v131 + 16) = v135 + (float)(v136 * v132);
  *(_DWORD *)(v131 + 32) = *((_DWORD *)v17 + 259) + 5;
  v137 = *((_DWORD *)v17 + 258);
  *(_DWORD *)&v17[v137 + 760] = 0;
  *(_DWORD *)&v17[v137 + 756] = 0;
  *(_DWORD *)&v17[v137 + 752] = 0;
  *(float *)&v17[v137 + 768] = joint_axes_ws.m_elems[5] * -1.0;
  v138 = (int)&v17[v137 + 752];
  *(float *)(v138 + 20) = joint_axes_ws.m_elems[6] * -1.0;
  v139 = joint_axes_ws.m_elems[7] * -1.0;
  *(float *)(v138 + 24) = joint_axes_ws.m_elems[7] * -1.0;
  v140 = (float *)v20->physical_core;
  v141 = *(float *)(v138 + 20);
  v142 = *(float *)(v138 + 16);
  v143 = v139;
  v144 = (float)((float)(v140[25] * v142) + (float)(v140[29] * v141)) + (float)(v140[33] * v139);
  v145 = (float)((float)(v140[26] * v142) + (float)(v140[30] * v141)) + (float)(v140[34] * v143);
  v146 = (float)(v140[28] * v141) + (float)(v140[24] * v142);
  v147 = v140[32];
  *(float *)(v138 + 20) = v144;
  *(float *)(v138 + 24) = v145;
  *(float *)(v138 + 16) = v146 + (float)(v147 * v143);
  *(_DWORD *)(v138 + 32) = *((_DWORD *)v17 + 259) + 5;
  *((_DWORD *)v17 + 259) += 6;
  v148 = *((_DWORD *)v17 + 259);
  *((_DWORD *)v17 + 258) += 288;
  *((_DWORD *)v17 + 252) = v148;
  *((_DWORD *)v17 + 255) = v148;
  work = (hk_Fixed_Work *)(v17 + 800);
  v149 = *(hk_Rigid_Body_Core **)(LODWORD(v18) + 148);
  LODWORD(v189) = v17 + 1008;
  LODWORD(v192) = v17 + 1020;
  hk_Rigid_Body_Core::add_to_mass_matrix_inv(
    this: v149,
    input: (hk_Core_VMQ_Input *)v17 + 84,
    matrix_out: (hk_Dense_Matrix *)v17 + 50,
    velocities_out: (float *)v17);
  v150 = *((_DWORD *)v17 + 259);
  v151 = (hk_Core_VMQ_Input *)LODWORD(v192);
  v152 = (hk_Core_VMQ_Input *)LODWORD(v189);
  *(_DWORD *)LODWORD(v192) = v150;
  v152->m_n_queries = v150;
  hk_Rigid_Body_Core::add_to_mass_matrix_inv(
    this: (hk_Rigid_Body_Core *)v188->physical_core,
    input: v151,
    matrix_out: (hk_Dense_Matrix *)work,
    velocities_out: (float *)v17);
  v153 = v190;
  v154 = *(_DWORD *)v190;
  v155 = *(float *)&position_ws_4[48] - joint_axes_ws.m_elems[9];
  v156 = *(float *)&position_ws_4[52] - joint_axes_ws.m_elems[10];
  v157 = *(float *)&position_ws_4[56] - joint_axes_ws.m_elems[11];
  LODWORD(mcr_0.m_vector.z) = 6;
  LODWORD(mcr_0.m_vector.w) = 8;
  LODWORD(mcr_0.m_vector.y) = &delta.m_size;
  *(float *)v154 = *(float *)&position_ws_4[48] - joint_axes_ws.m_elems[9];
  *(float *)(v154 + 4) = v156;
  *(float *)(v154 + 8) = v157;
  v158 = pi->i_delta_time * v155;
  i_delta_time = pi->i_delta_time;
  *(float *)(v154 + 8) = i_delta_time * v157;
  v160 = *(float *)&position_ws_4[20];
  *(float *)(v154 + 4) = i_delta_time * v156;
  v161 = *(float *)&position_ws_4[16];
  *(float *)v154 = v158;
  v162 = (float)((float)((float)(v160 * joint_axes_ws.m_elems[6]) + (float)(v161 * joint_axes_ws.m_elems[5]))
               + (float)(*(float *)&position_ws_4[24] * joint_axes_ws.m_elems[7]))
       * pi->i_delta_time;
  v163 = *(float *)position_ws_4;
  *(float *)(v154 + 12) = v162;
  v164 = *(float *)&position_ws_4[4];
  v165 = *(float *)&position_ws_4[8];
  *(_DWORD *)(v154 + 16) = COERCE_UNSIGNED_INT(
                             (float)((float)((float)(*(float *)&position_ws_4[4] * joint_axes_ws.m_elems[6])
                                           + (float)(v163 * joint_axes_ws.m_elems[5]))
                                   + (float)(*(float *)&position_ws_4[8] * joint_axes_ws.m_elems[7]))
                           * pi->i_delta_time)
                         ^ _mask__NegFloat_;
  *(float *)(v154 + 20) = (float)((float)((float)(v164 * joint_axes_ws.m_elems[2])
                                        + (float)(v163 * joint_axes_ws.m_elems[1]))
                                + (float)(v165 * joint_axes_ws.m_elems[3]))
                        * pi->i_delta_time;
  v166 = *(float *)&b1->hull_manager.time_of_next_reset * tau_factor;
  v167 = (float)(b1->hull_manager.hull_value_next_psi * -1.0) * strength_factor;
  v190 = (char *)((char *)&mcr_0.m_vector.z - v153);
  b1 = (hk_Rigid_Body *)5;
  v168 = (float *)(v153 + 32);
  v169 = (char *)((char *)&mcr_0.m_vector.y - v153);
  for ( i = 5; i > 0; b1 = (hk_Rigid_Body *)i )
  {
    v171 = *v168;
    *(float *)((char *)v168 + (_DWORD)v190) = (float)(*(float *)&v17[4 * i] * v167) + (float)(v168[1] * v166);
    i = (int)&b1[-1].client_data + 14;
    *(float *)((char *)v168 + (_DWORD)v169) = (float)(*(float *)&v17[4 * (_DWORD)b1 - 4] * v167) + (float)(v171 * v166);
    v168 -= 2;
  }
  v172 = work;
  hk_Dense_Matrix_Util::invert_6x6(m: (hk_Fixed_Dense_Matrix<6> *)work, tolerance: 0.0);
  LODWORD(delta.m_elt_buffer[5]) = impulses_4;
  LODWORD(delta.m_elt_buffer[6]) = 6;
  LODWORD(delta.m_elt_buffer[7]) = 8;
  hk_Dense_Matrix_Util::mult(
    m: (const hk_Dense_Matrix *)v172,
    in: (const hk_Dense_Vector *)&mcr_0.m_vector.y,
    out: (hk_Fixed_Dense_Vector<6> *)&delta.m_elt_buffer[5]);
  hk_Rigid_Body_Core::apply_impulses(
    this: *(hk_Rigid_Body_Core **)(LODWORD(v18) + 148),
    input: (hk_Core_VMQ_Input *)LODWORD(v189),
    impulse_strength: (const float *)LODWORD(delta.m_elt_buffer[5]));
  hk_Rigid_Body_Core::apply_impulses(
    this: (hk_Rigid_Body_Core *)v188->physical_core,
    input: (hk_Core_VMQ_Input *)LODWORD(v192),
    impulse_strength: (const float *)LODWORD(delta.m_elt_buffer[5]));
  return 1088;
}
