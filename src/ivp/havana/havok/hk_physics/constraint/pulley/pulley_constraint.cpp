// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/havana/havok/hk_physics/constraint/pulley/pulley_constraint.cpp
// Functions: 9
// ============================================================

#include "ivp\havana\havok\hk_physics\constraint\pulley\pulley_constraint.h"

//------------------------------------------------------------------------------
// Address: 0x10036FF0
// Name: protected: void hk_Pulley_Constraint::init_pulley_constraint(class hk_Pulley_BP const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Pulley_Constraint::init_pulley_constraint(hk_Pulley_Constraint *this, const hk_Pulley_BP *bp)
{
  this->m_tau = bp->m_tau;
  this->m_strength = bp->m_strength;
  this->m_length = bp->m_length;
  this->m_gearing = bp->m_gearing;
  this->m_translation_os_ks[0].x = bp->m_translation_os_ks[0].x;
  this->m_translation_os_ks[0].y = bp->m_translation_os_ks[0].y;
  this->m_translation_os_ks[0].z = bp->m_translation_os_ks[0].z;
  this->m_translation_os_ks[1].x = bp->m_translation_os_ks[1].x;
  this->m_translation_os_ks[1].y = bp->m_translation_os_ks[1].y;
  this->m_translation_os_ks[1].z = bp->m_translation_os_ks[1].z;
  this->m_worldspace_point[0].x = bp->m_worldspace_point[0].x;
  this->m_worldspace_point[0].y = bp->m_worldspace_point[0].y;
  this->m_worldspace_point[0].z = bp->m_worldspace_point[0].z;
  this->m_worldspace_point[1].x = bp->m_worldspace_point[1].x;
  this->m_worldspace_point[1].y = bp->m_worldspace_point[1].y;
  this->m_worldspace_point[1].z = bp->m_worldspace_point[1].z;
  this->m_is_rigid = bp->m_is_rigid;
}

//------------------------------------------------------------------------------
// Address: 0x10037060
// Name: public: void hk_Pulley_Constraint::write_to_blueprint(class hk_Pulley_BP __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Pulley_Constraint::write_to_blueprint(hk_Pulley_Constraint *this, hk_Pulley_BP *bp)
{
  bp->m_tau = this->m_tau;
  bp->m_strength = this->m_strength;
  bp->m_length = this->m_length;
  bp->m_gearing = this->m_gearing;
  bp->m_translation_os_ks[0].x = this->m_translation_os_ks[0].x;
  bp->m_translation_os_ks[0].y = this->m_translation_os_ks[0].y;
  bp->m_translation_os_ks[0].z = this->m_translation_os_ks[0].z;
  bp->m_translation_os_ks[1].x = this->m_translation_os_ks[1].x;
  bp->m_translation_os_ks[1].y = this->m_translation_os_ks[1].y;
  bp->m_translation_os_ks[1].z = this->m_translation_os_ks[1].z;
  bp->m_worldspace_point[0].x = this->m_worldspace_point[0].x;
  bp->m_worldspace_point[0].y = this->m_worldspace_point[0].y;
  bp->m_worldspace_point[0].z = this->m_worldspace_point[0].z;
  bp->m_worldspace_point[1].x = this->m_worldspace_point[1].x;
  bp->m_worldspace_point[1].y = this->m_worldspace_point[1].y;
  bp->m_worldspace_point[1].z = this->m_worldspace_point[1].z;
  bp->m_is_rigid = this->m_is_rigid;
}

//------------------------------------------------------------------------------
// Address: 0x100370D0
// Name: public: hk_Pulley_Constraint::hk_Pulley_Constraint(class hk_Environment __near *,class hk_Pulley_BP const __near *,class hk_Rigid_Body __near *,class hk_Rigid_Body __near *)
// Source: json
//------------------------------------------------------------------------------
hk_Pulley_Constraint *__thiscall hk_Pulley_Constraint::hk_Pulley_Constraint(
        hk_Pulley_Constraint *this,
        hk_Environment *env,
        const hk_Pulley_BP *bp,
        hk_Rigid_Body *a,
        hk_Rigid_Body *b)
{
  hk_Rigid_Body_Binary_EF::hk_Rigid_Body_Binary_EF(this, env, a, b, __formal: IVP_CP_CONSTRAINTS);
  this->m_constraint_system = nullptr;
  this->m_client_data = nullptr;
  this->__vftable = (hk_Pulley_Constraint_vtbl *)&hk_Pulley_Constraint::`vftable';
  hk_Pulley_Constraint::init_pulley_constraint(this, bp);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10037110
// Name: protected: virtual char const __near * hk_Pulley_Constraint::get_constraint_type(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall hk_Pulley_Constraint::get_constraint_type(hk_Pulley_Constraint *this)
{
  return "pulley";
}

//------------------------------------------------------------------------------
// Address: 0x10037120
// Name: public: hk_Pulley_Constraint::hk_Pulley_Constraint(class hk_Local_Constraint_System __near *,class hk_Pulley_BP const __near *,class hk_Rigid_Body __near *,class hk_Rigid_Body __near *)
// Source: json
//------------------------------------------------------------------------------
hk_Pulley_Constraint *__thiscall hk_Pulley_Constraint::hk_Pulley_Constraint(
        hk_Pulley_Constraint *this,
        hk_Local_Constraint_System *constraint_system,
        const hk_Pulley_BP *bp,
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
  this->__vftable = (hk_Pulley_Constraint_vtbl *)&hk_Pulley_Constraint::`vftable';
  hk_Pulley_Constraint::init_pulley_constraint(this, bp);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100371A0
// Name: public: virtual void hk_Pulley_Constraint::init_constraint(void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Pulley_Constraint::init_constraint(hk_Pulley_Constraint *this, const hk_Pulley_BP *vbp)
{
  hk_Pulley_Constraint::init_pulley_constraint(this, bp: vbp);
}

//------------------------------------------------------------------------------
// Address: 0x100371B0
// Name: protected: virtual void hk_Pulley_Constraint::step_constraint(class hk_PSI_Info __near &,void __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Pulley_Constraint::step_constraint(
        hk_Pulley_Constraint *this,
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
  hk_Pulley_Constraint *v24; // [esp+18h] [ebp-8h]
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
// Address: 0x10037450
// Name: private: virtual int hk_Pulley_Constraint::setup_and_step_constraint(class hk_PSI_Info __near &,void __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
int __userpurge hk_Pulley_Constraint::setup_and_step_constraint@<eax>(
        hk_Pulley_Constraint *this@<ecx>,
        hk_Rigid_Body *a2@<ebp>,
        hk_PSI_Info *pi,
        hk_Rigid_Body *mem,
        float tau_factor,
        float damp_factor)
{
  hk_Rigid_Body *v6; // esi
  float v7; // edi
  hk_Rigid_Body *v8; // eax
  bool v9; // zf
  hk_Rigid_Body *v10; // edx
  float *physical_core; // ecx
  float v12; // xmm7_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm3_4
  float v16; // xmm4_4
  float v17; // xmm5_4
  float v18; // xmm6_4
  float v19; // xmm2_4
  float v20; // xmm2_4
  float v21; // xmm7_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  float v24; // xmm2_4
  float *v25; // ecx
  float v26; // xmm6_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm3_4
  float v31; // xmm4_4
  float v32; // xmm5_4
  float v33; // xmm3_4
  float v34; // xmm2_4
  float v35; // xmm0_4
  float v36; // xmm6_4
  float v37; // xmm7_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm4_4
  float v41; // xmm3_4
  float v42; // xmm5_4
  float v43; // xmm1_4
  float v44; // xmm3_4
  float v45; // xmm1_4
  float v46; // xmm2_4
  float v47; // xmm6_4
  float v48; // xmm7_4
  float v49; // xmm0_4
  float v50; // xmm1_4
  float v51; // xmm3_4
  float v52; // xmm1_4
  IVP_Core *v53; // eax
  float w; // xmm6_4
  float y; // xmm3_4
  float z; // xmm7_4
  float *v57; // eax
  float v58; // xmm1_4
  float v59; // xmm2_4
  float v60; // xmm2_4
  float v61; // xmm0_4
  float v62; // xmm3_4
  float *v63; // eax
  float v64; // xmm6_4
  float v65; // xmm1_4
  float v66; // xmm7_4
  float *v67; // eax
  float v68; // xmm1_4
  float v69; // xmm2_4
  float v70; // xmm0_4
  float v71; // xmm1_4
  float v72; // xmm3_4
  float v73; // xmm2_4
  IVP_Environment *environment; // eax
  hk_Rigid_Body *v75; // edx
  float *v76; // ecx
  float v77; // xmm5_4
  float v78; // xmm0_4
  float v79; // xmm2_4
  float v80; // xmm1_4
  float v81; // xmm7_4
  int v82; // eax
  float v83; // xmm4_4
  float v84; // xmm0_4
  float v85; // xmm1_4
  float v86; // xmm3_4
  float v87; // xmm2_4
  float v88; // xmm3_4
  float v89; // xmm0_4
  float v90; // xmm4_4
  float v91; // xmm3_4
  float *v92; // ecx
  float v93; // xmm2_4
  float v94; // xmm1_4
  float v95; // xmm3_4
  float v96; // xmm0_4
  float v97; // xmm1_4
  float v98; // xmm5_4
  float v99; // xmm2_4
  float v100; // xmm1_4
  float v101; // xmm0_4
  float v102; // xmm5_4
  hk_Core_VMQ_Input *v103; // xmm2_4
  float v104; // xmm5_4
  int v105; // eax
  hk_Rigid_Body *v106; // edx
  float *v107; // ecx
  float v108; // xmm5_4
  float v109; // xmm0_4
  float v110; // xmm2_4
  float v111; // xmm7_4
  float v112; // xmm4_4
  float v113; // xmm0_4
  float v114; // xmm1_4
  float v115; // xmm3_4
  float v116; // xmm2_4
  float v117; // xmm3_4
  float v118; // xmm0_4
  float v119; // xmm4_4
  float v120; // xmm3_4
  float *v121; // ecx
  float v122; // xmm2_4
  float v123; // xmm1_4
  float v124; // xmm3_4
  float v125; // xmm0_4
  float v126; // xmm1_4
  float v127; // xmm5_4
  float v128; // xmm2_4
  IVP_Object *controller_phantom; // ecx
  hk_Rigid_Body_Core *v130; // ecx
  int v131; // eax
  hk_Rigid_Body *v132; // edx
  hk_Core_VMQ_Input *v133; // ecx
  hk_Rigid_Body_Core *v134; // ecx
  const IVP_U_Float_Point *p_rot_speed; // [esp-4h] [ebp-124h]
  const IVP_U_Float_Point *v137; // [esp-4h] [ebp-124h]
  float factor; // [esp+0h] [ebp-120h]
  IVP_U_Matrix v139; // [esp+14h] [ebp-10Ch] BYREF
  float v140; // [esp+54h] [ebp-CCh]
  float v141; // [esp+58h] [ebp-C8h]
  float v142; // [esp+5Ch] [ebp-C4h]
  float v143; // [esp+60h] [ebp-C0h]
  float v144; // [esp+64h] [ebp-BCh]
  float v145; // [esp+68h] [ebp-B8h]
  float v146; // [esp+6Ch] [ebp-B4h]
  float v147; // [esp+70h] [ebp-B0h]
  float v148; // [esp+74h] [ebp-ACh]
  float v149; // [esp+78h] [ebp-A8h]
  float v150; // [esp+7Ch] [ebp-A4h]
  float v151; // [esp+80h] [ebp-A0h]
  float v152[3]; // [esp+84h] [ebp-9Ch] BYREF
  hk_Vector3 impulses; // [esp+90h] [ebp-90h]
  float v154; // [esp+A0h] [ebp-80h]
  IVP_U_Quat v155; // [esp+A4h] [ebp-7Ch] BYREF
  IVP_U_Matrix m_world_f_core_last_psi; // [esp+B4h] [ebp-6Ch] BYREF
  float v157; // [esp+FCh] [ebp-24h]
  float v158; // [esp+100h] [ebp-20h]
  hk_Rigid_Body *v159; // [esp+104h] [ebp-1Ch]
  hk_Rigid_Body *v160; // [esp+108h] [ebp-18h]
  float v161; // [esp+10Ch] [ebp-14h]
  hk_Rigid_Body *b0; // [esp+110h] [ebp-10h]
  hk_Rigid_Body *b1; // [esp+114h] [ebp-Ch]
  void *v164; // [esp+118h] [ebp-8h]
  void *retaddr; // [esp+120h] [ebp+0h]

  b1 = a2;
  v164 = retaddr;
  v6 = mem;
  v7 = *(float *)&this;
  v161 = *(float *)&this;
  if ( *(float *)&mem == 0.0 )
  {
    *(float *)&b0 = 0.0;
    v6 = nullptr;
  }
  else
  {
    LODWORD(mem->extra_radius) = &mem->client_data;
    mem->physical_core = (IVP_Core *)1;
    mem->friction_core = (IVP_Core *)1;
    mem->original_core = (IVP_Core *)4;
    b0 = mem;
  }
  v8 = this->m_entities[0];
  v9 = (*(_DWORD *)&v8->flags & 0x800) == 0;
  v10 = this->m_entities[1];
  v159 = v8;
  v160 = v10;
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
    v6 = b0;
    v7 = v161;
    v10 = v160;
    v8 = v159;
    v139.rows[2].k[1] = m_world_f_core_last_psi.rows[1].k[2];
    v139.rows[2].k[2] = m_world_f_core_last_psi.rows[2].k[2];
    v139.vv.k[0] = m_world_f_core_last_psi.vv.k[0];
    v139.vv.k[1] = m_world_f_core_last_psi.vv.k[1];
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
    v139.rows[2].k[1] = physical_core[30];
    v139.rows[2].k[2] = physical_core[34];
    v139.vv.k[0] = physical_core[36];
    v139.vv.k[1] = physical_core[37];
    v19 = physical_core[38];
  }
  v9 = (*(_DWORD *)&v10->flags & 0x800) == 0;
  v139.vv.k[2] = v19;
  v20 = *(float *)(LODWORD(v7) + 24) * v12;
  v21 = *(float *)(LODWORD(v7) + 28);
  v22 = v20 + (float)(v15 * v21);
  v23 = *(float *)(LODWORD(v7) + 32);
  v151 = (float)(v22 + (float)(v18 * v23)) + v139.vv.k[0];
  v24 = *(float *)(LODWORD(v7) + 24);
  v150 = (float)((float)((float)(v13 * v24) + (float)(v16 * v21)) + (float)(v139.rows[2].k[1] * v23)) + v139.vv.k[1];
  v158 = (float)((float)((float)(v14 * v24) + (float)(v17 * v21)) + (float)(v139.rows[2].k[2] * v23)) + v139.vv.k[2];
  if ( v9 )
  {
    v139 = v10->physical_core->m_world_f_core_last_psi;
    IVP_U_Matrix::vmult4(this: &v139, p_in: &v10->shift_core_f_object, p_out: &v139.vv);
    v26 = v139.rows[0].k[0];
    v27 = v139.rows[1].k[0];
    v28 = v139.rows[2].k[0];
    v29 = v139.rows[0].k[1];
    v6 = b0;
    v7 = v161;
    v8 = v159;
    m_world_f_core_last_psi.rows[1].k[1] = v139.rows[1].k[1];
    m_world_f_core_last_psi.rows[1].k[2] = v139.rows[2].k[1];
    m_world_f_core_last_psi.rows[2].k[0] = v139.rows[0].k[2];
    m_world_f_core_last_psi.rows[2].k[1] = v139.rows[1].k[2];
    m_world_f_core_last_psi.rows[2].k[2] = v139.rows[2].k[2];
    m_world_f_core_last_psi.vv.k[0] = v139.vv.k[0];
    m_world_f_core_last_psi.vv.k[1] = v139.vv.k[1];
    v30 = v139.vv.k[2];
  }
  else
  {
    v25 = (float *)v10->physical_core;
    v26 = v25[24];
    v27 = v25[28];
    v28 = v25[32];
    v29 = v25[25];
    m_world_f_core_last_psi.rows[1].k[1] = v25[29];
    m_world_f_core_last_psi.rows[1].k[2] = v25[33];
    m_world_f_core_last_psi.rows[2].k[0] = v25[26];
    m_world_f_core_last_psi.rows[2].k[1] = v25[30];
    m_world_f_core_last_psi.rows[2].k[2] = v25[34];
    m_world_f_core_last_psi.vv.k[0] = v25[36];
    m_world_f_core_last_psi.vv.k[1] = v25[37];
    v30 = v25[38];
  }
  v31 = *(float *)(LODWORD(v7) + 40);
  v32 = *(float *)(LODWORD(v7) + 48);
  m_world_f_core_last_psi.vv.k[2] = v30;
  v33 = *(float *)(LODWORD(v7) + 44);
  v34 = (float)((float)((float)(v29 * v33) + (float)(v31 * v26)) + (float)(m_world_f_core_last_psi.rows[2].k[0] * v32))
      + m_world_f_core_last_psi.vv.k[0];
  v35 = (float)((float)((float)(v27 * v31) + (float)(m_world_f_core_last_psi.rows[1].k[1] * v33))
              + (float)(m_world_f_core_last_psi.rows[2].k[1] * v32))
      + m_world_f_core_last_psi.vv.k[1];
  v36 = *(float *)(LODWORD(v7) + 72);
  v37 = *(float *)(LODWORD(v7) + 76) - v35;
  v142 = v35;
  v38 = *(float *)(LODWORD(v7) + 100);
  v39 = (float)(v28 * v31) + (float)(m_world_f_core_last_psi.rows[1].k[2] * v33);
  v40 = *(float *)(LODWORD(v7) + 60) - v150;
  v41 = m_world_f_core_last_psi.rows[2].k[2] * v32;
  v42 = *(float *)(LODWORD(v7) + 64) - v158;
  v43 = (float)(v39 + v41) + m_world_f_core_last_psi.vv.k[2];
  v44 = *(float *)(LODWORD(v7) + 56) - v151;
  v157 = v43;
  v45 = *(float *)(LODWORD(v7) + 80) - v43;
  v146 = v34;
  v46 = v38 * (float)(v36 - v34);
  v47 = v38 * v37;
  v48 = v38 * v45;
  v161 = fsqrt((float)((float)(v40 * v40) + (float)(v44 * v44)) + (float)(v42 * v42));
  v49 = 1.0 / (float)(v161 + 1.0e-18);
  v143 = v49 * v44;
  v141 = v49 * v40;
  v140 = v49 * v42;
  v50 = fsqrt((float)((float)(v47 * v47) + (float)(v46 * v46)) + (float)(v48 * v48));
  v51 = v50 + 1.0e-18;
  v52 = (float)(v50 + v161) - *(float *)(LODWORD(v7) + 96);
  *(float *)&v6[1].exact_synapses = v52;
  v9 = *(_BYTE *)(LODWORD(v7) + 104) == 0;
  v144 = (float)(1.0 / v51) * v46;
  v148 = (float)(1.0 / v51) * v47;
  v147 = (float)(1.0 / v51) * v48;
  if ( v9 && v52 < 0.0 )
  {
    p_rot_speed = &v8->physical_core->rot_speed;
    impulses.w = pi->delta_time;
    IVP_U_Quat::set_fast_multiple_with_clip(this: &v155, angles: p_rot_speed, factor: impulses.w);
    v53 = v159->physical_core;
    w = v53->q_world_f_core_next_psi.w;
    y = v53->q_world_f_core_next_psi.y;
    z = v53->q_world_f_core_next_psi.z;
    b0 = (hk_Rigid_Body *)LODWORD(v53->q_world_f_core_next_psi.x);
    impulses.z = y;
    v161 = z;
    v154 = w;
    v152[0] = (float)((float)((float)(v155.w * *(float *)&b0) + (float)(v155.x * w)) + (float)(v155.z * y))
            - (float)(v155.y * z);
    v152[1] = (float)((float)((float)(v155.w * y) + (float)(v155.y * w)) + (float)(v155.x * z))
            - (float)(v155.z * *(float *)&b0);
    v152[2] = (float)((float)((float)(v155.w * z) + (float)(v155.z * w)) + (float)(v155.y * *(float *)&b0))
            - (float)(v155.x * y);
    impulses.x = (float)((float)((float)(v155.w * w) - (float)(v155.x * *(float *)&b0)) - (float)(v155.y * y))
               - (float)(v155.z * z);
    IVP_U_Quat::fast_normize_quat(this: (IVP_U_Quat *)v152);
    IVP_U_Quat::set_matrix(this: (IVP_U_Quat *)v152, mat: &m_world_f_core_last_psi);
    v57 = (float *)v159->physical_core;
    v9 = (*(_DWORD *)&v159->flags & 0x800) == 0;
    v58 = (float)(v57[53] * impulses.w) + v57[37];
    v59 = (float)(v57[54] * impulses.w) + v57[38];
    m_world_f_core_last_psi.vv.k[0] = (float)(impulses.w * v57[52]) + v57[36];
    m_world_f_core_last_psi.vv.k[1] = v58;
    m_world_f_core_last_psi.vv.k[2] = v59;
    if ( v9 )
      IVP_U_Matrix::vmult4(
        this: &m_world_f_core_last_psi,
        p_in: &v159->shift_core_f_object,
        p_out: &m_world_f_core_last_psi.vv);
    v60 = *(float *)(LODWORD(v7) + 28);
    v61 = *(float *)(LODWORD(v7) + 24);
    v62 = *(float *)(LODWORD(v7) + 32);
    impulses.z = (float)((float)((float)(v61 * m_world_f_core_last_psi.rows[0].k[0])
                               + (float)(v60 * m_world_f_core_last_psi.rows[0].k[1]))
                       + (float)(v62 * m_world_f_core_last_psi.rows[0].k[2]))
               + m_world_f_core_last_psi.vv.k[0];
    v149 = (float)((float)((float)(v61 * m_world_f_core_last_psi.rows[2].k[0])
                         + (float)(v60 * m_world_f_core_last_psi.rows[2].k[1]))
                 + (float)(v62 * m_world_f_core_last_psi.rows[2].k[2]))
         + m_world_f_core_last_psi.vv.k[2];
    factor = pi->delta_time;
    v137 = &v160->physical_core->rot_speed;
    v145 = (float)((float)((float)(v61 * m_world_f_core_last_psi.rows[1].k[0])
                         + (float)(v60 * m_world_f_core_last_psi.rows[1].k[1]))
                 + (float)(v62 * m_world_f_core_last_psi.rows[1].k[2]))
         + m_world_f_core_last_psi.vv.k[1];
    v154 = factor;
    IVP_U_Quat::set_fast_multiple_with_clip(this: &v155, angles: v137, factor);
    v63 = (float *)v160->physical_core;
    v64 = v63[71];
    v65 = v63[68];
    v66 = v63[70];
    v161 = v63[69];
    *(float *)&b0 = v66;
    impulses.w = v64;
    v152[0] = (float)((float)((float)(v64 * v155.x) + (float)(v155.w * v65)) + (float)(v155.z * v161))
            - (float)(v155.y * v66);
    v152[1] = (float)((float)((float)(v155.w * v161) + (float)(v155.y * v64)) + (float)(v66 * v155.x))
            - (float)(v155.z * v65);
    v152[2] = (float)((float)((float)(v155.w * v66) + (float)(v155.z * v64)) + (float)(v155.y * v65))
            - (float)(v161 * v155.x);
    impulses.x = (float)((float)((float)(v155.w * v64) - (float)(v65 * v155.x)) - (float)(v155.y * v161))
               - (float)(v155.z * v66);
    IVP_U_Quat::fast_normize_quat(this: (IVP_U_Quat *)v152);
    IVP_U_Quat::set_matrix(this: (IVP_U_Quat *)v152, mat: &m_world_f_core_last_psi);
    v9 = (*(_DWORD *)&v160->flags & 0x800) == 0;
    v67 = (float *)v160->physical_core;
    v68 = (float)(v67[53] * v154) + v67[37];
    v69 = (float)(v67[54] * v154) + v67[38];
    m_world_f_core_last_psi.vv.k[0] = (float)(v154 * v67[52]) + v67[36];
    m_world_f_core_last_psi.vv.k[1] = v68;
    m_world_f_core_last_psi.vv.k[2] = v69;
    if ( v9 )
      IVP_U_Matrix::vmult4(
        this: &m_world_f_core_last_psi,
        p_in: &v160->shift_core_f_object,
        p_out: &m_world_f_core_last_psi.vv);
    v70 = *(float *)(LODWORD(v7) + 100);
    v71 = (float)(*(float *)(LODWORD(v7) + 76)
                - (float)((float)((float)((float)(*(float *)(LODWORD(v7) + 40) * m_world_f_core_last_psi.rows[1].k[0])
                                        + (float)(*(float *)(LODWORD(v7) + 44) * m_world_f_core_last_psi.rows[1].k[1]))
                                + (float)(*(float *)(LODWORD(v7) + 48) * m_world_f_core_last_psi.rows[1].k[2]))
                        + m_world_f_core_last_psi.vv.k[1]))
        * v70;
    v72 = (float)(*(float *)(LODWORD(v7) + 72)
                - (float)((float)((float)((float)(*(float *)(LODWORD(v7) + 40) * m_world_f_core_last_psi.rows[0].k[0])
                                        + (float)(*(float *)(LODWORD(v7) + 44) * m_world_f_core_last_psi.rows[0].k[1]))
                                + (float)(*(float *)(LODWORD(v7) + 48) * m_world_f_core_last_psi.rows[0].k[2]))
                        + m_world_f_core_last_psi.vv.k[0]))
        * v70;
    v73 = (float)(*(float *)(LODWORD(v7) + 80)
                - (float)((float)((float)((float)(*(float *)(LODWORD(v7) + 40) * m_world_f_core_last_psi.rows[2].k[0])
                                        + (float)(*(float *)(LODWORD(v7) + 44) * m_world_f_core_last_psi.rows[2].k[1]))
                                + (float)(*(float *)(LODWORD(v7) + 48) * m_world_f_core_last_psi.rows[2].k[2]))
                        + m_world_f_core_last_psi.vv.k[2]))
        * v70;
    LOBYTE(v6[1].invalid_synapses) = (float)((float)(fsqrt(
                                                       (float)((float)(v71 * v71) + (float)(v72 * v72))
                                                     + (float)(v73 * v73))
                                                   + fsqrt(
                                                       (float)((float)((float)(*(float *)(LODWORD(v7) + 60) - v145)
                                                                     * (float)(*(float *)(LODWORD(v7) + 60) - v145))
                                                             + (float)((float)(*(float *)(LODWORD(v7) + 56) - impulses.z)
                                                                     * (float)(*(float *)(LODWORD(v7) + 56) - impulses.z)))
                                                     + (float)((float)(*(float *)(LODWORD(v7) + 64) - v149)
                                                             * (float)(*(float *)(LODWORD(v7) + 64) - v149))))
                                           - *(float *)(LODWORD(v7) + 96)) < (float)(*(float *)(LODWORD(v7) + 96)
                                                                                   * 0.0099999998);
  }
  else
  {
    LOBYTE(v6[1].invalid_synapses) = 0;
  }
  if ( LOBYTE(v6[1].invalid_synapses) == 0 )
  {
    hk_VM_Query_Builder<hk_VMQ_Storage<1>>::begin(this: (hk_VM_Query_Builder<hk_VMQ_Storage<1> > *)v6, size: 1);
    environment = v6[1].environment;
    v75 = v159;
    v76 = (float *)v159->physical_core;
    v77 = v151 - v76[36];
    v78 = v150 - v76[37];
    v79 = v158 - v76[38];
    *(float *)((char *)v6->shift_core_f_object.k + (_DWORD)environment) = v143;
    *(float *)((char *)&v6->shift_core_f_object.k[1] + (_DWORD)environment) = v141;
    *(float *)((char *)&v6->shift_core_f_object.k[2] + (_DWORD)environment) = v140;
    v80 = *(float *)((char *)&v6->shift_core_f_object.k[1] + (_DWORD)environment);
    v81 = *(float *)((char *)&v6->shift_core_f_object.k[2] + (_DWORD)environment);
    v82 = (int)&v6->shift_core_f_object + (_DWORD)environment;
    v83 = v78;
    v84 = v78 * *(float *)(v82 + 8);
    v85 = (float)(v80 * v77) - (float)(v83 * *(float *)v82);
    v86 = v79;
    v87 = v79 * *(float *)(v82 + 4);
    v88 = v86 * *(float *)v82;
    *(float *)(v82 + 24) = v85;
    v89 = v84 - v87;
    *(float *)(v82 + 16) = v89;
    v90 = v85;
    v91 = v88 - (float)(v81 * v77);
    *(float *)(v82 + 20) = v91;
    v92 = (float *)v75->physical_core;
    v93 = v91;
    v94 = v92[29] * v91;
    v95 = v89;
    v96 = (float)((float)(v92[25] * v89) + v94) + (float)(v92[33] * v90);
    v97 = (float)((float)(v92[26] * v95) + (float)(v92[30] * v93)) + (float)(v92[34] * v90);
    v98 = (float)(v92[28] * v93) + (float)(v92[24] * v95);
    v99 = v92[32];
    *(float *)(v82 + 24) = v97;
    v100 = v144;
    *(float *)(v82 + 20) = v96;
    v101 = v142;
    v102 = v98 + (float)(v99 * v90);
    *(float *)&v103 = v157;
    *(float *)(v82 + 16) = v102;
    v104 = v146;
    *(_DWORD *)(v82 + 32) = v6[1].controller_phantom;
    v105 = (int)&v6[1].environment->statistic_manager.impact_rescue_after_counter + (unsigned int)v6;
    v106 = v160;
    v107 = (float *)v160->physical_core;
    v108 = v104 - v107[36];
    v109 = v101 - v107[37];
    v110 = *(float *)&v103 - v107[38];
    *(float *)v105 = v100;
    *(float *)(v105 + 4) = v148;
    *(float *)(v105 + 8) = v147;
    v111 = *(float *)(v105 + 8) * v108;
    v112 = v109;
    v113 = v109 * *(float *)(v105 + 8);
    v114 = (float)(*(float *)(v105 + 4) * v108) - (float)(v112 * *(float *)v105);
    v115 = v110;
    v116 = v110 * *(float *)(v105 + 4);
    v117 = v115 * *(float *)v105;
    *(float *)(v105 + 24) = v114;
    v118 = v113 - v116;
    *(float *)(v105 + 16) = v118;
    v119 = v114;
    v120 = v117 - v111;
    *(float *)(v105 + 20) = v120;
    v121 = (float *)v106->physical_core;
    v122 = v120;
    v123 = v121[29] * v120;
    v124 = v118;
    v125 = (float)((float)(v121[25] * v118) + v123) + (float)(v121[33] * v119);
    v126 = (float)((float)(v121[26] * v124) + (float)(v121[30] * v122)) + (float)(v121[34] * v119);
    v127 = (float)(v121[28] * v122) + (float)(v121[24] * v124);
    v128 = v121[32];
    *(float *)(v105 + 20) = v125;
    *(float *)(v105 + 24) = v126;
    *(float *)(v105 + 16) = v127 + (float)(v128 * v119);
    *(_DWORD *)(v105 + 32) = v6[1].controller_phantom++;
    controller_phantom = (IVP_Object *)v6[1].controller_phantom;
    v6[1].environment = (IVP_Environment *)((char *)v6[1].environment + 48);
    v6[1].prev_in_cluster = controller_phantom;
    v6[1].__vftable = (hk_Rigid_Body_vtbl *)controller_phantom;
    LODWORD(v158) = &v6[1].prev_in_cluster;
    v130 = (hk_Rigid_Body_Core *)v159->physical_core;
    LODWORD(v157) = &v6[1];
    hk_Rigid_Body_Core::add_to_mass_matrix_inv(
      this: v130,
      input: (hk_Core_VMQ_Input *)&v6[1],
      matrix_out: (hk_Dense_Matrix *)&v6->extra_radius,
      velocities_out: (float *)v6);
    v131 = (int)v6[1].controller_phantom;
    v132 = v160;
    *(_DWORD *)LODWORD(v157) = v131;
    v133 = (hk_Core_VMQ_Input *)LODWORD(v158);
    *(_DWORD *)LODWORD(v158) = v131;
    hk_Rigid_Body_Core::add_to_mass_matrix_inv(
      this: (hk_Rigid_Body_Core *)v132->physical_core,
      input: v133,
      matrix_out: (hk_Dense_Matrix *)&v6->extra_radius,
      velocities_out: (float *)v6);
    *(float *)LODWORD(v6->extra_radius) = 1.0 / *(float *)LODWORD(v6->extra_radius);
    v134 = (hk_Rigid_Body_Core *)v159->physical_core;
    v152[0] = (float)((float)((float)((float)(*(float *)(LODWORD(v7) + 88) * tau_factor) * pi->i_delta_time)
                            * *(float *)&v6[1].exact_synapses)
                    - (float)((float)(*(float *)(LODWORD(v7) + 92) * damp_factor) * *(float *)&v6->__vftable))
            * *(float *)LODWORD(v6->extra_radius);
    hk_Rigid_Body_Core::apply_impulses(this: v134, input: (hk_Core_VMQ_Input *)LODWORD(v157), impulse_strength: v152);
    hk_Rigid_Body_Core::apply_impulses(
      this: (hk_Rigid_Body_Core *)v160->physical_core,
      input: (hk_Core_VMQ_Input *)LODWORD(v158),
      impulse_strength: v152);
  }
  return 224;
}

//------------------------------------------------------------------------------
// Address: 0x10038390
// Name: protected: virtual int hk_Pulley_Constraint::get_vmq_storage_size(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall hk_Pulley_Constraint::get_vmq_storage_size(hk_Stiff_Spring_Constraint *this)
{
  return 224;
}
