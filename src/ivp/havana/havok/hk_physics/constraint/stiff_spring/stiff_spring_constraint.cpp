// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/havana/havok/hk_physics/constraint/stiff_spring/stiff_spring_constraint.cpp
// Functions: 9
// ============================================================

#include "ivp\havana\havok\hk_physics\constraint\stiff_spring\stiff_spring_constraint.h"

//------------------------------------------------------------------------------
// Address: 0x10038250
// Name: protected: void hk_Stiff_Spring_Constraint::init_stiff_spring_constraint(class hk_Stiff_Spring_BP const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Stiff_Spring_Constraint::init_stiff_spring_constraint(
        hk_Stiff_Spring_Constraint *this,
        const hk_Stiff_Spring_BP *bp)
{
  this->m_tau = bp->m_tau;
  this->m_strength = bp->m_strength;
  this->m_stiff_spring_length = bp->m_length;
  this->m_translation_os_ks[0].x = bp->m_translation_os_ks[0].x;
  this->m_translation_os_ks[0].y = bp->m_translation_os_ks[0].y;
  this->m_translation_os_ks[0].z = bp->m_translation_os_ks[0].z;
  this->m_translation_os_ks[1].x = bp->m_translation_os_ks[1].x;
  this->m_translation_os_ks[1].y = bp->m_translation_os_ks[1].y;
  this->m_translation_os_ks[1].z = bp->m_translation_os_ks[1].z;
  this->m_min_length = bp->m_min_length;
}

//------------------------------------------------------------------------------
// Address: 0x100382A0
// Name: public: void hk_Stiff_Spring_Constraint::write_to_blueprint(class hk_Stiff_Spring_BP __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Stiff_Spring_Constraint::write_to_blueprint(
        hk_Stiff_Spring_Constraint *this,
        hk_Stiff_Spring_BP *bp)
{
  bp->m_tau = this->m_tau;
  bp->m_strength = this->m_strength;
  bp->m_length = this->m_stiff_spring_length;
  bp->m_translation_os_ks[0].x = this->m_translation_os_ks[0].x;
  bp->m_translation_os_ks[0].y = this->m_translation_os_ks[0].y;
  bp->m_translation_os_ks[0].z = this->m_translation_os_ks[0].z;
  bp->m_translation_os_ks[1].x = this->m_translation_os_ks[1].x;
  bp->m_translation_os_ks[1].y = this->m_translation_os_ks[1].y;
  bp->m_translation_os_ks[1].z = this->m_translation_os_ks[1].z;
  bp->m_min_length = this->m_min_length;
}

//------------------------------------------------------------------------------
// Address: 0x100382F0
// Name: public: hk_Stiff_Spring_Constraint::hk_Stiff_Spring_Constraint(class hk_Environment __near *,class hk_Stiff_Spring_BP const __near *,class hk_Rigid_Body __near *,class hk_Rigid_Body __near *)
// Source: json
//------------------------------------------------------------------------------
hk_Stiff_Spring_Constraint *__thiscall hk_Stiff_Spring_Constraint::hk_Stiff_Spring_Constraint(
        hk_Stiff_Spring_Constraint *this,
        hk_Environment *env,
        const hk_Stiff_Spring_BP *bp,
        hk_Rigid_Body *a,
        hk_Rigid_Body *b)
{
  hk_Rigid_Body_Binary_EF::hk_Rigid_Body_Binary_EF(this, env, a, b, __formal: IVP_CP_CONSTRAINTS);
  this->m_constraint_system = nullptr;
  this->m_client_data = nullptr;
  this->__vftable = (hk_Stiff_Spring_Constraint_vtbl *)&hk_Stiff_Spring_Constraint::`vftable';
  hk_Stiff_Spring_Constraint::init_stiff_spring_constraint(this, bp);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10038330
// Name: protected: virtual char const __near * hk_Stiff_Spring_Constraint::get_constraint_type(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall hk_Stiff_Spring_Constraint::get_constraint_type(hk_Stiff_Spring_Constraint *this)
{
  return "stiff_spring";
}

//------------------------------------------------------------------------------
// Address: 0x10038340
// Name: protected: virtual int hk_Stiff_Spring_Constraint::get_constraint_dof(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall hk_Stiff_Spring_Constraint::get_constraint_dof(hk_Stiff_Spring_Constraint *this)
{
  return 5;
}

//------------------------------------------------------------------------------
// Address: 0x10038350
// Name: public: hk_Stiff_Spring_Constraint::hk_Stiff_Spring_Constraint(class hk_Local_Constraint_System __near *,class hk_Stiff_Spring_BP const __near *,class hk_Rigid_Body __near *,class hk_Rigid_Body __near *)
// Source: json
//------------------------------------------------------------------------------
hk_Stiff_Spring_Constraint *__thiscall hk_Stiff_Spring_Constraint::hk_Stiff_Spring_Constraint(
        hk_Stiff_Spring_Constraint *this,
        hk_Local_Constraint_System *constraint_system,
        const hk_Stiff_Spring_BP *bp,
        hk_Rigid_Body *a,
        hk_Rigid_Body *b)
{
  hk_Constraint::hk_Constraint(
    this,
    sys: constraint_system,
    a,
    b,
    redundend_prio: IVP_CP_CONSTRAINTS,
    storage_size: 224);
  this->__vftable = (hk_Stiff_Spring_Constraint_vtbl *)&hk_Stiff_Spring_Constraint::`vftable';
  hk_Stiff_Spring_Constraint::init_stiff_spring_constraint(this, bp);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100383E0
// Name: public: virtual void hk_Stiff_Spring_Constraint::init_constraint(void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Stiff_Spring_Constraint::init_constraint(
        hk_Stiff_Spring_Constraint *this,
        const hk_Stiff_Spring_BP *vbp)
{
  hk_Stiff_Spring_Constraint::init_stiff_spring_constraint(this, bp: vbp);
}

//------------------------------------------------------------------------------
// Address: 0x100383F0
// Name: protected: virtual void hk_Stiff_Spring_Constraint::step_constraint(class hk_PSI_Info __near &,void __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Stiff_Spring_Constraint::step_constraint(
        hk_Stiff_Spring_Constraint *this,
        hk_PSI_Info *pi,
        char *mem,
        float tau_factor,
        float damp_factor)
{
  bool v6; // zf
  hk_Rigid_Body *v7; // eax
  int v8; // ebx
  hk_Rigid_Body_Core *physical_core; // ecx
  float *v10; // esi
  int v11; // ebx
  float *v12; // eax
  int v13; // edi
  float v14; // xmm0_4
  IVP_Core *v15; // esi
  float *v16; // ebx
  float *v17; // eax
  int v18; // edi
  float v19; // xmm0_4
  bool v20; // sf
  hk_Vector3 impulses; // [esp+0h] [ebp-20h] BYREF
  hk_Core_VMQ_Input *v22; // [esp+10h] [ebp-10h]
  hk_Core_VMQ_Input *input; // [esp+14h] [ebp-Ch]
  hk_Stiff_Spring_Constraint *v24; // [esp+18h] [ebp-8h]
  hk_Rigid_Body *b1; // [esp+1Ch] [ebp-4h]
  char *mema; // [esp+2Ch] [ebp+Ch]

  v6 = mem[212] == 0;
  v24 = this;
  if ( v6 )
  {
    *(_DWORD *)mem = 0;
    v7 = this->m_entities[0];
    v8 = *((_DWORD *)mem + 44);
    b1 = this->m_entities[1];
    physical_core = (hk_Rigid_Body_Core *)v7->physical_core;
    v10 = *((float **)mem + 45);
    input = (hk_Core_VMQ_Input *)(mem + 176);
    v11 = v8 - 1;
    v12 = v10 + 6;
    do
    {
      v13 = *((_DWORD *)v12 + 2);
      v14 = (float)((float)((float)((float)(*(v12 - 5) * physical_core->speed.k[1])
                                  + (float)(*v10 * physical_core->speed.k[0]))
                          + (float)(*(v12 - 4) * physical_core->speed.k[2]))
                  + (float)((float)((float)(*(v12 - 2) * physical_core->rot_speed.k[0])
                                  + (float)(*(v12 - 1) * physical_core->rot_speed.k[1]))
                          + (float)(*v12 * physical_core->rot_speed.k[2])))
          + *(float *)&mem[4 * v13];
      v10 += 12;
      v12 += 12;
      --v11;
      *(float *)&mem[4 * v13] = v14;
    }
    while ( v11 >= 0 );
    v15 = b1->physical_core;
    v16 = *((float **)mem + 48);
    mema = (char *)(*((_DWORD *)mem + 47) - 1);
    v22 = (hk_Core_VMQ_Input *)(mem + 188);
    v17 = v16 + 6;
    do
    {
      v18 = *((_DWORD *)v17 + 2);
      v19 = (float)((float)((float)((float)(*(v17 - 5) * v15->speed.k[1]) + (float)(*v16 * v15->speed.k[0]))
                          + (float)(*(v17 - 4) * v15->speed.k[2]))
                  + (float)((float)((float)(*(v17 - 1) * v15->rot_speed.k[1]) + (float)(*(v17 - 2) * v15->rot_speed.k[0]))
                          + (float)(*v17 * v15->rot_speed.k[2])))
          + *(float *)&mem[4 * v18];
      v16 += 12;
      v17 += 12;
      v20 = (int)--mema < 0;
      *(float *)&mem[4 * v18] = v19;
    }
    while ( !v20 );
    impulses.x = (float)((float)((float)((float)(v24->m_tau * tau_factor) * pi->i_delta_time) * *((float *)mem + 52))
                       - (float)((float)(v24->m_strength * damp_factor) * *(float *)mem))
               * **((float **)mem + 36);
    hk_Rigid_Body_Core::apply_impulses(this: physical_core, input, impulse_strength: &impulses.x);
    hk_Rigid_Body_Core::apply_impulses(
      this: (hk_Rigid_Body_Core *)b1->physical_core,
      input: v22,
      impulse_strength: &impulses.x);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100385D0
// Name: private: virtual int hk_Stiff_Spring_Constraint::setup_and_step_constraint(class hk_PSI_Info __near &,void __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
int __userpurge hk_Stiff_Spring_Constraint::setup_and_step_constraint@<eax>(
        hk_Stiff_Spring_Constraint *this@<ecx>,
        hk_Rigid_Body *a2@<ebp>,
        hk_PSI_Info *pi,
        _DWORD *mem,
        float tau_factor,
        float damp_factor)
{
  float v6; // esi
  float z; // edi
  hk_Rigid_Body *v8; // edx
  bool v9; // zf
  hk_Rigid_Body *v10; // eax
  float *physical_core; // ecx
  float v12; // xmm3_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm4_4
  float v17; // xmm5_4
  float v18; // xmm6_4
  float v19; // xmm7_4
  float v20; // xmm2_4
  float v21; // xmm7_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm2_4
  float *v25; // eax
  float v26; // xmm2_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm6_4
  float v30; // xmm7_4
  float v31; // xmm3_4
  float v32; // xmm2_4
  float v33; // xmm3_4
  float v34; // xmm4_4
  float v35; // xmm5_4
  float v36; // xmm3_4
  float v37; // xmm1_4
  float v38; // xmm2_4
  float v39; // xmm3_4
  float v40; // xmm1_4
  float v41; // xmm4_4
  float v42; // xmm0_4
  float v43; // xmm5_4
  float v44; // xmm0_4
  float v45; // xmm3_4
  float v46; // xmm1_4
  float v47; // xmm4_4
  float *v48; // eax
  float v49; // xmm6_4
  float v50; // xmm3_4
  float v51; // xmm7_4
  float *v52; // eax
  float v53; // xmm1_4
  float v54; // xmm2_4
  float v55; // xmm1_4
  float v56; // xmm2_4
  float v57; // xmm3_4
  const IVP_U_Float_Point *v58; // eax
  float *v59; // eax
  float v60; // xmm6_4
  float v61; // xmm1_4
  float v62; // xmm4_4
  float v63; // xmm7_4
  float *v64; // eax
  float v65; // xmm1_4
  float v66; // xmm2_4
  float v67; // xmm3_4
  float v68; // xmm4_4
  float v69; // xmm5_4
  float v70; // xmm0_4
  float v71; // xmm1_4
  float v72; // xmm2_4
  float v73; // xmm0_4
  float v74; // xmm1_4
  float v75; // xmm0_4
  float v76; // xmm2_4
  float v77; // xmm0_4
  float v78; // xmm0_4
  int v79; // eax
  hk_Rigid_Body *v80; // edx
  float *v81; // ecx
  float v82; // xmm3_4
  float v83; // xmm0_4
  float v84; // xmm1_4
  float v85; // xmm6_4
  float v86; // xmm2_4
  float v87; // xmm7_4
  int v88; // eax
  float v89; // xmm5_4
  float v90; // xmm0_4
  float v91; // xmm2_4
  float v92; // xmm4_4
  float v93; // xmm1_4
  float v94; // xmm0_4
  hk_Rigid_Body *v95; // edi
  float v96; // xmm4_4
  float *v97; // ecx
  float v98; // xmm3_4
  float v99; // xmm4_4
  float v100; // xmm1_4
  float v101; // xmm2_4
  float v102; // xmm5_4
  float w; // xmm3_4
  float v104; // xmm5_4
  float v105; // xmm0_4
  float v106; // xmm1_4
  float v107; // xmm2_4
  float v108; // xmm5_4
  float v109; // xmm0_4
  float *v110; // ecx
  float v111; // xmm2_4
  float v112; // xmm0_4
  float v113; // xmm3_4
  int v114; // eax
  float v115; // xmm6_4
  float v116; // xmm1_4
  float v117; // xmm2_4
  float v118; // xmm5_4
  float v119; // xmm0_4
  float v120; // xmm1_4
  float v121; // xmm4_4
  float v122; // xmm3_4
  float v123; // xmm0_4
  float v124; // xmm4_4
  float *v125; // ecx
  float v126; // xmm2_4
  float v127; // xmm4_4
  float v128; // xmm3_4
  float v129; // xmm0_4
  float v130; // xmm1_4
  float v131; // xmm5_4
  float v132; // xmm2_4
  int v133; // eax
  int v134; // eax
  hk_Core_VMQ_Input *v135; // ecx
  hk_Rigid_Body *v136; // edx
  hk_Rigid_Body_Core *v137; // ecx
  const IVP_U_Float_Point *p_rot_speed; // [esp-4h] [ebp-114h]
  IVP_U_Matrix v140; // [esp+14h] [ebp-FCh] BYREF
  float v141; // [esp+54h] [ebp-BCh]
  float v142; // [esp+58h] [ebp-B8h]
  float v143; // [esp+5Ch] [ebp-B4h]
  float v144; // [esp+60h] [ebp-B0h]
  float v145[3]; // [esp+64h] [ebp-ACh] BYREF
  hk_Vector3 impulses; // [esp+70h] [ebp-A0h]
  float v147; // [esp+80h] [ebp-90h]
  float v148; // [esp+84h] [ebp-8Ch]
  float factor; // [esp+88h] [ebp-88h]
  float v150; // [esp+8Ch] [ebp-84h]
  float delta_time; // [esp+90h] [ebp-80h]
  IVP_U_Quat v152; // [esp+94h] [ebp-7Ch] BYREF
  IVP_U_Matrix m_world_f_core_last_psi; // [esp+A4h] [ebp-6Ch] BYREF
  float v154; // [esp+F0h] [ebp-20h]
  float v155; // [esp+F4h] [ebp-1Ch]
  hk_Rigid_Body *v156; // [esp+F8h] [ebp-18h]
  hk_Rigid_Body *v157; // [esp+FCh] [ebp-14h]
  float v158; // [esp+100h] [ebp-10h]
  hk_Rigid_Body *b0; // [esp+104h] [ebp-Ch]
  hk_Rigid_Body *b1; // [esp+108h] [ebp-8h]
  hk_Rigid_Body *retaddr; // [esp+110h] [ebp+0h]

  b0 = a2;
  b1 = retaddr;
  v6 = *(float *)&mem;
  z = *(float *)&this;
  LODWORD(impulses.z) = this;
  if ( *(float *)&mem == 0.0 )
  {
    v158 = 0.0;
    v6 = 0.0;
  }
  else
  {
    mem[36] = mem + 40;
    mem[37] = 1;
    mem[38] = 1;
    mem[39] = 4;
    v158 = *(float *)&mem;
  }
  v8 = this->m_entities[0];
  v9 = (*(_DWORD *)&v8->flags & 0x800) == 0;
  v10 = this->m_entities[1];
  v156 = v8;
  v157 = v10;
  if ( v9 )
  {
    m_world_f_core_last_psi = v8->physical_core->m_world_f_core_last_psi;
    IVP_U_Matrix::vmult4(
      this: &m_world_f_core_last_psi,
      p_in: &v8->shift_core_f_object,
      p_out: &m_world_f_core_last_psi.vv);
    v12 = m_world_f_core_last_psi.rows[0].k[0];
    v13 = m_world_f_core_last_psi.rows[1].k[0];
    v14 = m_world_f_core_last_psi.rows[2].k[0];
    v15 = m_world_f_core_last_psi.rows[0].k[1];
    v16 = m_world_f_core_last_psi.rows[1].k[1];
    v17 = m_world_f_core_last_psi.rows[2].k[1];
    v18 = m_world_f_core_last_psi.rows[0].k[2];
    v6 = v158;
    v10 = v157;
    v8 = v156;
    z = impulses.z;
    v140.rows[2].k[1] = m_world_f_core_last_psi.rows[1].k[2];
    v140.rows[2].k[2] = m_world_f_core_last_psi.rows[2].k[2];
    v140.vv.k[0] = m_world_f_core_last_psi.vv.k[0];
    v140.vv.k[1] = m_world_f_core_last_psi.vv.k[1];
    v19 = m_world_f_core_last_psi.vv.k[2];
  }
  else
  {
    physical_core = (float *)v8->physical_core;
    v12 = physical_core[24];
    v13 = physical_core[28];
    v14 = physical_core[32];
    v15 = physical_core[25];
    v16 = physical_core[29];
    v17 = physical_core[33];
    v18 = physical_core[26];
    v140.rows[2].k[1] = physical_core[30];
    v140.rows[2].k[2] = physical_core[34];
    v140.vv.k[0] = physical_core[36];
    v140.vv.k[1] = physical_core[37];
    v19 = physical_core[38];
  }
  v9 = (*(_DWORD *)&v10->flags & 0x800) == 0;
  v20 = v15 * *(float *)(LODWORD(z) + 28);
  v140.vv.k[2] = v19;
  v21 = *(float *)(LODWORD(z) + 24);
  v22 = v20 + (float)(v12 * v21);
  v23 = *(float *)(LODWORD(z) + 32);
  v148 = (float)(v22 + (float)(v18 * v23)) + v140.vv.k[0];
  v24 = *(float *)(LODWORD(z) + 28);
  v150 = (float)((float)((float)(v13 * v21) + (float)(v16 * v24)) + (float)(v140.rows[2].k[1] * v23)) + v140.vv.k[1];
  impulses.w = (float)((float)((float)(v14 * v21) + (float)(v17 * v24)) + (float)(v140.rows[2].k[2] * v23))
             + v140.vv.k[2];
  if ( v9 )
  {
    v140 = v10->physical_core->m_world_f_core_last_psi;
    IVP_U_Matrix::vmult4(this: &v140, p_in: &v10->shift_core_f_object, p_out: &v140.vv);
    v27 = v140.rows[0].k[0];
    v28 = v140.rows[1].k[0];
    v29 = v140.rows[2].k[0];
    v30 = v140.rows[0].k[1];
    v6 = v158;
    v8 = v156;
    z = impulses.z;
    m_world_f_core_last_psi.rows[2].k[0] = v140.rows[0].k[2];
    m_world_f_core_last_psi.rows[2].k[1] = v140.rows[1].k[2];
    m_world_f_core_last_psi.rows[2].k[2] = v140.rows[2].k[2];
    m_world_f_core_last_psi.vv.k[0] = v140.vv.k[0];
    m_world_f_core_last_psi.rows[1].k[1] = v140.rows[1].k[1];
    v32 = v140.rows[2].k[1];
    m_world_f_core_last_psi.vv.k[1] = v140.vv.k[1];
    v33 = v140.vv.k[2];
  }
  else
  {
    v25 = (float *)v10->physical_core;
    v26 = v25[29];
    v27 = v25[24];
    v28 = v25[28];
    v29 = v25[32];
    v30 = v25[25];
    m_world_f_core_last_psi.rows[2].k[0] = v25[26];
    m_world_f_core_last_psi.rows[2].k[1] = v25[30];
    m_world_f_core_last_psi.rows[2].k[2] = v25[34];
    m_world_f_core_last_psi.vv.k[0] = v25[36];
    v31 = v25[37];
    m_world_f_core_last_psi.rows[1].k[1] = v26;
    v32 = v25[33];
    m_world_f_core_last_psi.vv.k[1] = v31;
    v33 = v25[38];
  }
  v34 = *(float *)(LODWORD(z) + 40);
  v35 = *(float *)(LODWORD(z) + 48);
  m_world_f_core_last_psi.vv.k[2] = v33;
  v36 = *(float *)(LODWORD(z) + 44);
  v37 = (float)(v28 * v34) + (float)(m_world_f_core_last_psi.rows[1].k[1] * v36);
  v38 = (float)((float)((float)((float)(v32 * v36) + (float)(v29 * v34))
                      + (float)(m_world_f_core_last_psi.rows[2].k[2] * v35))
              + m_world_f_core_last_psi.vv.k[2])
      - impulses.w;
  v39 = (float)((float)((float)((float)(v27 * v34) + (float)(v30 * v36))
                      + (float)(m_world_f_core_last_psi.rows[2].k[0] * v35))
              + m_world_f_core_last_psi.vv.k[0])
      - v148;
  v40 = (float)((float)(v37 + (float)(m_world_f_core_last_psi.rows[2].k[1] * v35)) + m_world_f_core_last_psi.vv.k[1])
      - v150;
  v41 = fsqrt((float)((float)(v40 * v40) + (float)(v39 * v39)) + (float)(v38 * v38));
  v42 = 1.0 / (float)(v41 + 1.0e-18);
  v43 = v42 * v39;
  v155 = v42 * v38;
  v44 = *(float *)(LODWORD(z) + 68);
  v45 = (float)(1.0 / (float)(v41 + 1.0e-18)) * v40;
  v46 = *(float *)(LODWORD(z) + 64);
  v141 = v43;
  v144 = v45;
  if ( v44 <= v41 )
  {
    if ( v41 <= v46 )
      v47 = 0.0;
    else
      v47 = v41 - v46;
  }
  else
  {
    v47 = v41 - v44;
  }
  *(float *)(LODWORD(v6) + 208) = v47;
  if ( *(float *)(LODWORD(z) + 68) != *(float *)(LODWORD(z) + 64) && v47 == 0.0 )
  {
    p_rot_speed = &v8->physical_core->rot_speed;
    factor = pi->delta_time;
    IVP_U_Quat::set_fast_multiple_with_clip(this: &v152, angles: p_rot_speed, factor);
    v48 = (float *)v156->physical_core;
    v49 = v48[71];
    v50 = v48[69];
    v51 = v48[70];
    v158 = v48[68];
    v147 = v50;
    v154 = v51;
    delta_time = v49;
    v145[0] = (float)((float)((float)(v152.w * v158) + (float)(v152.x * v49)) + (float)(v152.z * v50))
            - (float)(v152.y * v51);
    v145[1] = (float)((float)((float)(v152.w * v50) + (float)(v152.y * v49)) + (float)(v152.x * v51))
            - (float)(v152.z * v158);
    v145[2] = (float)((float)((float)(v152.w * v51) + (float)(v152.z * v49)) + (float)(v152.y * v158))
            - (float)(v152.x * v50);
    impulses.x = (float)((float)((float)(v152.w * v49) - (float)(v152.x * v158)) - (float)(v152.y * v50))
               - (float)(v152.z * v51);
    IVP_U_Quat::fast_normize_quat(this: (IVP_U_Quat *)v145);
    IVP_U_Quat::set_matrix(this: (IVP_U_Quat *)v145, mat: &m_world_f_core_last_psi);
    v52 = (float *)v156->physical_core;
    v9 = (*(_DWORD *)&v156->flags & 0x800) == 0;
    v53 = (float)(v52[53] * factor) + v52[37];
    v54 = (float)(v52[54] * factor) + v52[38];
    m_world_f_core_last_psi.vv.k[0] = (float)(factor * v52[52]) + v52[36];
    m_world_f_core_last_psi.vv.k[1] = v53;
    m_world_f_core_last_psi.vv.k[2] = v54;
    if ( v9 )
      IVP_U_Matrix::vmult4(
        this: &m_world_f_core_last_psi,
        p_in: &v156->shift_core_f_object,
        p_out: &m_world_f_core_last_psi.vv);
    v55 = *(float *)(LODWORD(z) + 28);
    v56 = *(float *)(LODWORD(z) + 24);
    v57 = *(float *)(LODWORD(z) + 32);
    v58 = (const IVP_U_Float_Point *)v157->physical_core;
    v147 = (float)((float)((float)(m_world_f_core_last_psi.rows[0].k[0] * v56)
                         + (float)(m_world_f_core_last_psi.rows[0].k[1] * v55))
                 + (float)(m_world_f_core_last_psi.rows[0].k[2] * v57))
         + m_world_f_core_last_psi.vv.k[0];
    v143 = (float)((float)((float)(m_world_f_core_last_psi.rows[1].k[0] * v56)
                         + (float)(m_world_f_core_last_psi.rows[1].k[1] * v55))
                 + (float)(m_world_f_core_last_psi.rows[1].k[2] * v57))
         + m_world_f_core_last_psi.vv.k[1];
    v142 = (float)((float)((float)(m_world_f_core_last_psi.rows[2].k[0] * v56)
                         + (float)(m_world_f_core_last_psi.rows[2].k[1] * v55))
                 + (float)(m_world_f_core_last_psi.rows[2].k[2] * v57))
         + m_world_f_core_last_psi.vv.k[2];
    delta_time = pi->delta_time;
    IVP_U_Quat::set_fast_multiple_with_clip(this: &v152, angles: v58 + 12, factor: delta_time);
    v59 = (float *)v157->physical_core;
    v60 = v59[71];
    v61 = v59[68];
    v62 = v59[69];
    v63 = v59[70];
    v154 = v62;
    v158 = v63;
    factor = v60;
    v145[0] = (float)((float)((float)(v60 * v152.x) + (float)(v152.w * v61)) + (float)(v152.z * v62))
            - (float)(v152.y * v63);
    v145[1] = (float)((float)((float)(v152.w * v62) + (float)(v152.y * v60)) + (float)(v63 * v152.x))
            - (float)(v152.z * v61);
    v145[2] = (float)((float)((float)(v152.w * v63) + (float)(v152.z * v60)) + (float)(v152.y * v61))
            - (float)(v62 * v152.x);
    impulses.x = (float)((float)((float)(v152.w * v60) - (float)(v61 * v152.x)) - (float)(v152.y * v62))
               - (float)(v152.z * v63);
    IVP_U_Quat::fast_normize_quat(this: (IVP_U_Quat *)v145);
    IVP_U_Quat::set_matrix(this: (IVP_U_Quat *)v145, mat: &m_world_f_core_last_psi);
    v9 = (*(_DWORD *)&v157->flags & 0x800) == 0;
    v64 = (float *)v157->physical_core;
    v65 = (float)(v64[53] * delta_time) + v64[37];
    v66 = (float)(v64[54] * delta_time) + v64[38];
    m_world_f_core_last_psi.vv.k[0] = (float)(delta_time * v64[52]) + v64[36];
    m_world_f_core_last_psi.vv.k[1] = v65;
    m_world_f_core_last_psi.vv.k[2] = v66;
    if ( v9 )
      IVP_U_Matrix::vmult4(
        this: &m_world_f_core_last_psi,
        p_in: &v157->shift_core_f_object,
        p_out: &m_world_f_core_last_psi.vv);
    v67 = *(float *)(LODWORD(z) + 44);
    v68 = *(float *)(LODWORD(z) + 40);
    v69 = *(float *)(LODWORD(z) + 48);
    v70 = (float)((float)((float)((float)(m_world_f_core_last_psi.rows[0].k[0] * v68)
                                + (float)(m_world_f_core_last_psi.rows[0].k[1] * v67))
                        + (float)(m_world_f_core_last_psi.rows[0].k[2] * v69))
                + m_world_f_core_last_psi.vv.k[0])
        - v147;
    v71 = (float)((float)((float)((float)(m_world_f_core_last_psi.rows[1].k[0] * v68)
                                + (float)(m_world_f_core_last_psi.rows[1].k[1] * v67))
                        + (float)(m_world_f_core_last_psi.rows[1].k[2] * v69))
                + m_world_f_core_last_psi.vv.k[1])
        - v143;
    v72 = (float)((float)((float)((float)(m_world_f_core_last_psi.rows[2].k[0] * v68)
                                + (float)(m_world_f_core_last_psi.rows[2].k[1] * v67))
                        + (float)(m_world_f_core_last_psi.rows[2].k[2] * v69))
                + m_world_f_core_last_psi.vv.k[2])
        - v142;
    v73 = (float)(v70 * v70) + (float)(v71 * v71);
    v74 = *(float *)(LODWORD(z) + 68);
    v75 = v73 + (float)(v72 * v72);
    v76 = *(float *)(LODWORD(z) + 64);
    v77 = fsqrt(v75);
    if ( v74 <= v77 )
    {
      if ( v77 <= v76 )
      {
LABEL_27:
        *(_BYTE *)(LODWORD(v6) + 212) = 1;
        goto LABEL_29;
      }
      v78 = v77 - v76;
    }
    else
    {
      v78 = v77 - v74;
    }
    if ( v78 != 0.0 )
    {
      *(_BYTE *)(LODWORD(v6) + 212) = 0;
      goto LABEL_29;
    }
    goto LABEL_27;
  }
  *(_BYTE *)(LODWORD(v6) + 212) = 0;
LABEL_29:
  if ( *(_BYTE *)(LODWORD(v6) + 212) == 0 )
  {
    hk_VM_Query_Builder<hk_VMQ_Storage<1>>::begin(this: (hk_VM_Query_Builder<hk_VMQ_Storage<1> > *)LODWORD(v6), size: 1);
    v79 = *(_DWORD *)(LODWORD(v6) + 200);
    v80 = v156;
    v81 = (float *)v156->physical_core;
    v82 = v148 - v81[36];
    v83 = v150 - v81[37];
    v84 = impulses.w - v81[38];
    v85 = v141;
    *(float *)(v79 + LODWORD(v6) + 52) = v144;
    *(float *)(v79 + LODWORD(v6) + 56) = v155;
    *(float *)(v79 + LODWORD(v6) + 48) = v85;
    v86 = *(float *)(v79 + LODWORD(v6) + 52);
    v87 = *(float *)(v79 + LODWORD(v6) + 56);
    v88 = v79 + LODWORD(v6) + 48;
    v89 = v83;
    v90 = v83 * *(float *)(v88 + 8);
    v91 = (float)(v86 * v82) - (float)(v89 * v85);
    v92 = v84;
    v93 = v84 * *(float *)(v88 + 4);
    *(float *)(v88 + 24) = v91;
    v94 = v90 - v93;
    *(float *)(v88 + 16) = v94;
    v95 = v157;
    v96 = (float)(v92 * v85) - (float)(v87 * v82);
    *(float *)(v88 + 20) = v96;
    v97 = (float *)v80->physical_core;
    v98 = v96;
    v99 = v91;
    v100 = (float)((float)(v97[25] * v94) + (float)(v97[29] * v98)) + (float)(v97[33] * v91);
    v101 = (float)((float)(v97[26] * v94) + (float)(v97[30] * v98)) + (float)(v97[34] * v91);
    v102 = v97[28] * v98;
    w = impulses.w;
    v104 = v102 + (float)(v94 * v97[24]);
    v105 = v97[32];
    *(float *)(v88 + 20) = v100;
    v106 = v144;
    *(float *)(v88 + 24) = v101;
    v107 = v148;
    v108 = v104 + (float)(v105 * v99);
    v109 = v150;
    *(float *)(v88 + 16) = v108;
    *(_DWORD *)(v88 + 32) = *(_DWORD *)(LODWORD(v6) + 204);
    v110 = (float *)v95->physical_core;
    v111 = v107 - v110[36];
    v112 = v109 - v110[37];
    v113 = w - v110[38];
    v114 = *(_DWORD *)(LODWORD(v6) + 200) + LODWORD(v6) + 96;
    v115 = v85 * -1.0;
    *(float *)v114 = v115;
    *(float *)(v114 + 4) = v106 * -1.0;
    *(float *)(v114 + 8) = v155 * -1.0;
    v116 = v111 * *(float *)(v114 + 4);
    v117 = v111 * *(float *)(v114 + 8);
    v118 = v112;
    v119 = v112 * *(float *)(v114 + 8);
    v120 = v116 - (float)(v118 * v115);
    v121 = v113;
    v122 = v113 * *(float *)(v114 + 4);
    *(float *)(v114 + 24) = v120;
    v123 = v119 - v122;
    *(float *)(v114 + 16) = v123;
    v124 = (float)(v121 * v115) - v117;
    *(float *)(v114 + 20) = v124;
    v125 = (float *)v95->physical_core;
    v126 = v124;
    v127 = v120;
    v128 = v123;
    v129 = (float)((float)(v125[25] * v123) + (float)(v125[29] * v126)) + (float)(v125[33] * v120);
    v130 = (float)((float)(v125[26] * v128) + (float)(v125[30] * v126)) + (float)(v125[34] * v120);
    v131 = (float)(v125[28] * v126) + (float)(v125[24] * v128);
    v132 = v125[32];
    *(float *)(v114 + 20) = v129;
    *(float *)(v114 + 24) = v130;
    *(float *)(v114 + 16) = v131 + (float)(v132 * v127);
    *(_DWORD *)(v114 + 32) = (*(_DWORD *)(LODWORD(v6) + 204))++;
    v133 = *(_DWORD *)(LODWORD(v6) + 204);
    *(_DWORD *)(LODWORD(v6) + 200) += 48;
    *(_DWORD *)(LODWORD(v6) + 176) = v133;
    *(_DWORD *)(LODWORD(v6) + 188) = v133;
    LODWORD(v155) = LODWORD(v6) + 188;
    hk_Rigid_Body_Core::add_to_mass_matrix_inv(
      this: (hk_Rigid_Body_Core *)v80->physical_core,
      input: (hk_Core_VMQ_Input *)(LODWORD(v6) + 176),
      matrix_out: (hk_Dense_Matrix *)(LODWORD(v6) + 144),
      velocities_out: (float *)LODWORD(v6));
    v134 = *(_DWORD *)(LODWORD(v6) + 204);
    v135 = (hk_Core_VMQ_Input *)LODWORD(v155);
    v136 = v157;
    *(_DWORD *)(LODWORD(v6) + 176) = v134;
    v135->m_n_queries = v134;
    hk_Rigid_Body_Core::add_to_mass_matrix_inv(
      this: (hk_Rigid_Body_Core *)v136->physical_core,
      input: v135,
      matrix_out: (hk_Dense_Matrix *)(LODWORD(v6) + 144),
      velocities_out: (float *)LODWORD(v6));
    **(float **)(LODWORD(v6) + 144) = 1.0 / **(float **)(LODWORD(v6) + 144);
    v137 = (hk_Rigid_Body_Core *)v156->physical_core;
    v145[0] = (float)((float)((float)((float)(*(float *)(LODWORD(impulses.z) + 56) * tau_factor) * pi->i_delta_time)
                            * *(float *)(LODWORD(v6) + 208))
                    - (float)((float)(*(float *)(LODWORD(impulses.z) + 60) * damp_factor) * *(float *)LODWORD(v6)))
            * **(float **)(LODWORD(v6) + 144);
    hk_Rigid_Body_Core::apply_impulses(
      this: v137,
      input: (hk_Core_VMQ_Input *)(LODWORD(v6) + 176),
      impulse_strength: v145);
    hk_Rigid_Body_Core::apply_impulses(
      this: (hk_Rigid_Body_Core *)v157->physical_core,
      input: (hk_Core_VMQ_Input *)LODWORD(v155),
      impulse_strength: v145);
  }
  return 224;
}
