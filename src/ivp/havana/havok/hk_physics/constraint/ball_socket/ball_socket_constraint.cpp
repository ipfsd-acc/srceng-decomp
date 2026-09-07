// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/havana/havok/hk_physics/constraint/ball_socket/ball_socket_constraint.cpp
// Functions: 14
// ============================================================

#include "ivp\havana\havok\hk_physics\constraint\ball_socket\ball_socket_constraint.h"

//------------------------------------------------------------------------------
// Address: 0x10035F80
// Name: protected: void hk_Ball_Socket_Constraint::init_ball_socket_constraint(class hk_Ball_Socket_BP const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Ball_Socket_Constraint::init_ball_socket_constraint(
        hk_Ball_Socket_Constraint *this,
        const hk_Ball_Socket_BP *bp)
{
  this->m_tau = bp->m_tau;
  this->m_strength = bp->m_strength;
  this->m_translation_os_ks[0].x = bp->m_translation_os_ks[0].x;
  this->m_translation_os_ks[0].y = bp->m_translation_os_ks[0].y;
  this->m_translation_os_ks[0].z = bp->m_translation_os_ks[0].z;
  this->m_translation_os_ks[1].x = bp->m_translation_os_ks[1].x;
  this->m_translation_os_ks[1].y = bp->m_translation_os_ks[1].y;
  this->m_translation_os_ks[1].z = bp->m_translation_os_ks[1].z;
}

//------------------------------------------------------------------------------
// Address: 0x10035FC0
// Name: public: void hk_Ball_Socket_Constraint::write_to_blueprint(class hk_Ball_Socket_BP __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Ball_Socket_Constraint::write_to_blueprint(hk_Ball_Socket_Constraint *this, hk_Ball_Socket_BP *bp)
{
  bp->m_tau = this->m_tau;
  bp->m_strength = this->m_strength;
  bp->m_translation_os_ks[0].x = this->m_translation_os_ks[0].x;
  bp->m_translation_os_ks[0].y = this->m_translation_os_ks[0].y;
  bp->m_translation_os_ks[0].z = this->m_translation_os_ks[0].z;
  bp->m_translation_os_ks[1].x = this->m_translation_os_ks[1].x;
  bp->m_translation_os_ks[1].y = this->m_translation_os_ks[1].y;
  bp->m_translation_os_ks[1].z = this->m_translation_os_ks[1].z;
}

//------------------------------------------------------------------------------
// Address: 0x10036000
// Name: public: virtual int hk_Ball_Socket_Constraint::get_vmq_storage_size(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall hk_Ball_Socket_Constraint::get_vmq_storage_size(hk_Ball_Socket_Constraint *this)
{
  return 512;
}

//------------------------------------------------------------------------------
// Address: 0x10036010
// Name: public: hk_Ball_Socket_Constraint::hk_Ball_Socket_Constraint(class hk_Environment __near *,class hk_Ball_Socket_BP const __near *,class hk_Rigid_Body __near *,class hk_Rigid_Body __near *)
// Source: json
//------------------------------------------------------------------------------
hk_Ball_Socket_Constraint *__thiscall hk_Ball_Socket_Constraint::hk_Ball_Socket_Constraint(
        hk_Ball_Socket_Constraint *this,
        hk_Environment *env,
        const hk_Ball_Socket_BP *bp,
        hk_Rigid_Body *a,
        hk_Rigid_Body *b)
{
  hk_Rigid_Body_Binary_EF::hk_Rigid_Body_Binary_EF(this, env, a, b, __formal: IVP_CP_CONSTRAINTS);
  this->m_constraint_system = nullptr;
  this->m_client_data = nullptr;
  this->__vftable = (hk_Ball_Socket_Constraint_vtbl *)&hk_Ball_Socket_Constraint::`vftable';
  hk_Ball_Socket_Constraint::init_ball_socket_constraint(this, bp);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10036050
// Name: public: virtual char const __near * hk_Ball_Socket_Constraint::get_constraint_type(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall hk_Ball_Socket_Constraint::get_constraint_type(hk_Ball_Socket_Constraint *this)
{
  return "ball_socket";
}

//------------------------------------------------------------------------------
// Address: 0x10036060
// Name: public: hk_Ball_Socket_Constraint::hk_Ball_Socket_Constraint(class hk_Local_Constraint_System __near *,class hk_Ball_Socket_BP const __near *,class hk_Rigid_Body __near *,class hk_Rigid_Body __near *)
// Source: json
//------------------------------------------------------------------------------
hk_Ball_Socket_Constraint *__thiscall hk_Ball_Socket_Constraint::hk_Ball_Socket_Constraint(
        hk_Ball_Socket_Constraint *this,
        hk_Local_Constraint_System *constraint_system,
        const hk_Ball_Socket_BP *bp,
        hk_Rigid_Body *a,
        hk_Rigid_Body *b)
{
  hk_Constraint::hk_Constraint(
    this,
    sys: constraint_system,
    a,
    b,
    redundend_prio: IVP_CP_CONSTRAINTS,
    storage_size: 512);
  this->__vftable = (hk_Ball_Socket_Constraint_vtbl *)&hk_Ball_Socket_Constraint::`vftable';
  hk_Ball_Socket_Constraint::init_ball_socket_constraint(this, bp);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100360A0
// Name: public: virtual void hk_Ball_Socket_Constraint::init_constraint(void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Ball_Socket_Constraint::init_constraint(
        hk_Ball_Socket_Constraint *this,
        const hk_Ball_Socket_BP *vbp)
{
  hk_Ball_Socket_Constraint::init_ball_socket_constraint(this, bp: vbp);
}

//------------------------------------------------------------------------------
// Address: 0x100360B0
// Name: public: virtual void hk_Ball_Socket_Constraint::step_constraint(class hk_PSI_Info __near &,void __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Ball_Socket_Constraint::step_constraint(
        hk_Ball_Socket_Constraint *this,
        hk_PSI_Info *pi,
        char *mem,
        float tau_factor,
        float damp_factor)
{
  hk_Rigid_Body *v6; // edx
  hk_Rigid_Body *v7; // ecx
  float *physical_core; // esi
  float *v9; // ecx
  float *v10; // edx
  int v11; // edi
  float v12; // xmm0_4
  bool v13; // sf
  IVP_Core *v14; // esi
  float *v15; // edi
  int v16; // ecx
  float *v17; // edx
  int v18; // ecx
  float v19; // xmm0_4
  float v20; // xmm0_4
  float *v21; // edx
  float v22; // xmm2_4
  float v23; // xmm4_4
  float v24; // xmm3_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm2_4
  float v28; // xmm3_4
  int v29; // eax
  float v30; // xmm3_4
  hk_Vector3 impulses; // [esp+0h] [ebp-24h] BYREF
  hk_Core_VMQ_Input *v32; // [esp+10h] [ebp-14h]
  hk_Rigid_Body *b0; // [esp+14h] [ebp-10h]
  hk_Core_VMQ_Input *input; // [esp+18h] [ebp-Ch]
  hk_Ball_Socket_Constraint *v35; // [esp+1Ch] [ebp-8h]
  hk_Rigid_Body *b1; // [esp+20h] [ebp-4h]
  char *mema; // [esp+30h] [ebp+Ch]
  char *memb; // [esp+30h] [ebp+Ch]

  *(_QWORD *)(mem + 20) = 0;
  *((_DWORD *)mem + 4) = 0;
  v6 = this->m_entities[0];
  v35 = this;
  v7 = this->m_entities[1];
  physical_core = (float *)v6->physical_core;
  b0 = v6;
  b1 = v7;
  mema = (char *)(*((_DWORD *)mem + 120) - 1);
  v9 = *((float **)mem + 121);
  input = (hk_Core_VMQ_Input *)(mem + 480);
  v10 = v9 + 6;
  do
  {
    v11 = *((_DWORD *)v10 + 2);
    v12 = (float)((float)((float)((float)(*(v10 - 5) * physical_core[53]) + (float)(*v9 * physical_core[52]))
                        + (float)(*(v10 - 4) * physical_core[54]))
                + (float)((float)((float)(*(v10 - 2) * physical_core[48]) + (float)(*(v10 - 1) * physical_core[49]))
                        + (float)(*v10 * physical_core[50])))
        + *(float *)&mem[4 * v11 + 16];
    v9 += 12;
    v10 += 12;
    v13 = (int)--mema < 0;
    *(float *)&mem[4 * v11 + 16] = v12;
  }
  while ( !v13 );
  v14 = b1->physical_core;
  v15 = *((float **)mem + 124);
  v16 = *((_DWORD *)mem + 123) - 1;
  v32 = (hk_Core_VMQ_Input *)(mem + 492);
  memb = (char *)v16;
  v17 = v15 + 6;
  do
  {
    v18 = *((_DWORD *)v17 + 2);
    v19 = (float)((float)((float)((float)(*(v17 - 5) * v14->speed.k[1]) + (float)(*v15 * v14->speed.k[0]))
                        + (float)(*(v17 - 4) * v14->speed.k[2]))
                + (float)((float)((float)(*(v17 - 1) * v14->rot_speed.k[1]) + (float)(*(v17 - 2) * v14->rot_speed.k[0]))
                        + (float)(v14->rot_speed.k[2] * *v17)))
        + *(float *)&mem[4 * v18 + 16];
    v15 += 12;
    v17 += 12;
    v13 = (int)--memb < 0;
    *(float *)&mem[4 * v18 + 16] = v19;
  }
  while ( !v13 );
  v20 = (float)(v35->m_tau * tau_factor) * pi->i_delta_time;
  v21 = *((float **)mem + 104);
  v22 = *(float *)mem * v20;
  v23 = *((float *)mem + 2) * v20;
  v24 = *((float *)mem + 1) * v20;
  v25 = (float)(damp_factor * -1.0) * v35->m_strength;
  v26 = (float)(v25 * *((float *)mem + 4)) + v22;
  v27 = (float)(*((float *)mem + 5) * v25) + v24;
  v28 = *((float *)mem + 6);
  v29 = *((_DWORD *)mem + 107);
  v30 = (float)(v28 * v25) + v23;
  impulses.x = *v21 * v26;
  impulses.y = v21[1] * v26;
  v29 *= 4;
  impulses.z = v21[2] * v26;
  impulses.x = (float)(*(float *)((char *)v21 + v29) * v27) + impulses.x;
  impulses.y = (float)(*(float *)((char *)v21 + v29 + 4) * v27) + impulses.y;
  impulses.z = (float)(*(float *)((char *)v21 + v29 + 8) * v27) + impulses.z;
  impulses.x = (float)(v30 * *(float *)((char *)v21 + v29 + v29)) + impulses.x;
  impulses.y = (float)(*(float *)((char *)v21 + v29 + v29 + 4) * v30) + impulses.y;
  impulses.z = (float)(*(float *)((char *)v21 + v29 + v29 + 8) * v30) + impulses.z;
  hk_Rigid_Body_Core::apply_impulses(
    this: (hk_Rigid_Body_Core *)b0->physical_core,
    input,
    impulse_strength: &impulses.x);
  hk_Rigid_Body_Core::apply_impulses(
    this: (hk_Rigid_Body_Core *)b1->physical_core,
    input: v32,
    impulse_strength: &impulses.x);
}

//------------------------------------------------------------------------------
// Address: 0x10036360
// Name: public: void hk_VM_Query_Builder<class hk_VMQ_Storage<3>>::begin(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_VM_Query_Builder<hk_VMQ_Storage<3>>::begin(hk_VM_Query_Builder<hk_VMQ_Storage<3> > *this, int size)
{
  int v2; // eax

  this->m_input[1].m_buffer = (hk_Cached_Force_Axis_Description *)this->m_vmq_storage.m_buffer_1;
  this->m_input[0].m_buffer = (hk_Cached_Force_Axis_Description *)this->m_vmq_storage.m_buffer_0;
  this->m_input[1].m_vmq = (hk_Virtual_Mass_Query *)this->m_vmq_storage.m_impulse_info[1];
  this->m_input[0].m_vmq = (hk_Virtual_Mass_Query *)this->m_vmq_storage.m_impulse_info;
  this->m_vmq_offset = 0;
  this->m_dense_matrix_offset = 0;
  v2 = this->m_vmq_storage.m_dense_matrix.m_rows * this->m_vmq_storage.m_dense_matrix.m_lda - 1;
  if ( v2 >= 0 )
  {
    if ( this->m_vmq_storage.m_dense_matrix.m_rows * this->m_vmq_storage.m_dense_matrix.m_lda >= 4 )
    {
      do
      {
        this->m_vmq_storage.m_dense_matrix.m_elt[v2] = 0.0;
        this->m_vmq_storage.m_dense_matrix.m_elt[v2 - 1] = 0.0;
        this->m_vmq_storage.m_dense_matrix.m_elt[v2 - 2] = 0.0;
        this->m_vmq_storage.m_dense_matrix.m_elt[v2 - 3] = 0.0;
        v2 -= 4;
      }
      while ( v2 >= 3 );
    }
    for ( ; v2 >= 0; this->m_vmq_storage.m_dense_matrix.m_elt[v2 + 1] = 0.0 )
      --v2;
  }
  this->m_vmq_storage.m_velocities[3] = 0.0;
  this->m_vmq_storage.m_velocities[2] = 0.0;
  this->m_vmq_storage.m_velocities[1] = 0.0;
  this->m_vmq_storage.m_velocities[0] = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10036420
// Name: public: virtual int hk_Ball_Socket_Constraint::setup_and_step_constraint(class hk_PSI_Info __near &,void __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __userpurge hk_Ball_Socket_Constraint::setup_and_step_constraint@<eax>(
        hk_Ball_Socket_Constraint *this@<ecx>,
        int a2@<ebp>,
        hk_PSI_Info *pi,
        hk_Core_VMQ_Input *mem,
        float tau_factor,
        float damp_factor)
{
  float *p_m_n_queries; // edi
  hk_Rigid_Body *v7; // eax
  bool v8; // zf
  hk_Rigid_Body *v9; // edx
  hk_VM_Query_Builder<hk_VMQ_Storage<3> > *v10; // esi
  IVP_Core *physical_core; // eax
  float v12; // xmm4_4
  float v13; // xmm5_4
  float v14; // xmm6_4
  float v15; // xmm7_4
  float v16; // xmm0_4
  float x; // xmm1_4
  float z; // xmm2_4
  float y; // xmm0_4
  IVP_Core *v20; // eax
  float v21; // xmm6_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm7_4
  float v26; // xmm3_4
  float v27; // xmm4_4
  float v28; // xmm5_4
  float v29; // xmm3_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  int v32; // edx
  float *v33; // eax
  float v34; // xmm5_4
  float v35; // xmm1_4
  float v36; // xmm0_4
  float *v37; // eax
  float v38; // xmm2_4
  float v39; // xmm0_4
  int v40; // eax
  float v41; // xmm1_4
  float *v42; // ecx
  float v43; // xmm6_4
  float v44; // xmm1_4
  float v45; // xmm7_4
  float v46; // xmm3_4
  hk_Rigid_Body *v47; // xmm2_4
  unsigned int m_vmq_offset; // eax
  hk_Rigid_Body *v49; // ecx
  int v50; // eax
  float v51; // xmm2_4
  float *v52; // ecx
  float v53; // xmm4_4
  float v54; // xmm3_4
  float v55; // xmm6_4
  float v56; // xmm7_4
  int v57; // eax
  float *v58; // ecx
  float v59; // xmm3_4
  float v60; // xmm6_4
  float v61; // xmm7_4
  hk_Rigid_Body *v62; // xmm2_4
  unsigned int v63; // eax
  hk_Rigid_Body *v64; // ecx
  hk_VM_Query_Builder<hk_VMQ_Storage<3> > *v65; // xmm2_4
  int v66; // eax
  float *v67; // ecx
  float v68; // xmm2_4
  float v69; // xmm3_4
  float v70; // xmm4_4
  float v71; // xmm2_4
  float v72; // xmm4_4
  float v73; // xmm7_4
  float v74; // xmm6_4
  int v75; // eax
  float v76; // xmm5_4
  float *v77; // ecx
  float v78; // xmm4_4
  float v79; // xmm7_4
  float v80; // xmm2_4
  float v81; // xmm2_4
  unsigned int v82; // eax
  hk_Rigid_Body *v83; // ecx
  hk_VM_Query_Builder<hk_VMQ_Storage<3> > *v84; // xmm1_4
  float *v85; // ecx
  int v86; // eax
  float v87; // xmm0_4
  float v88; // xmm3_4
  float v89; // xmm1_4
  float v90; // xmm2_4
  int m_dense_matrix_offset; // eax
  int v92; // eax
  float w; // edx
  float v94; // ecx
  float v95; // xmm0_4
  float v96; // xmm1_4
  float v97; // xmm4_4
  float v98; // xmm0_4
  float v99; // xmm2_4
  float v100; // esi
  float *v101; // edx
  int v102; // eax
  float v104; // [esp+18h] [ebp-D8h]
  float v105; // [esp+1Ch] [ebp-D4h]
  _BYTE mcr_0_4[64]; // [esp+24h] [ebp-CCh] OVERLAPPED BYREF
  float v107; // [esp+64h] [ebp-8Ch] BYREF
  float v108; // [esp+68h] [ebp-88h]
  float v109; // [esp+6Ch] [ebp-84h]
  _BYTE impulses_4[76]; // [esp+74h] [ebp-7Ch] OVERLAPPED BYREF
  hk_VM_Query_Builder<hk_VMQ_Storage<3> > *query_engine; // [esp+C0h] [ebp-30h]
  float v112; // [esp+C4h] [ebp-2Ch]
  hk_Rigid_Body *b0; // [esp+C8h] [ebp-28h]
  hk_Mass_Relative_Vector3 mcr_1; // [esp+CCh] [ebp-24h]
  hk_Rigid_Body *v115; // [esp+DCh] [ebp-14h]
  hk_Core_VMQ_Input *m_input; // [esp+E0h] [ebp-10h]
  int v117; // [esp+E4h] [ebp-Ch]
  hk_Rigid_Body *b1; // [esp+E8h] [ebp-8h]
  hk_Rigid_Body *retaddr; // [esp+F0h] [ebp+0h]

  v117 = a2;
  b1 = retaddr;
  p_m_n_queries = (float *)&mem->m_n_queries;
  LODWORD(mcr_1.m_vector.y) = this;
  if ( mem != nullptr )
  {
    mem[34].m_buffer = (hk_Cached_Force_Axis_Description *)&mem[36];
    mem[35].m_n_queries = 3;
    mem[35].m_vmq = (hk_Virtual_Mass_Query *)3;
    mem[35].m_buffer = (hk_Cached_Force_Axis_Description *)4;
    m_input = mem;
  }
  else
  {
    m_input = nullptr;
    p_m_n_queries = nullptr;
  }
  v7 = this->m_entities[0];
  v8 = (*(_DWORD *)&v7->flags & 0x800) == 0;
  v9 = this->m_entities[1];
  v10 = (hk_VM_Query_Builder<hk_VMQ_Storage<3> > *)(p_m_n_queries + 4);
  *(_DWORD *)&impulses_4[64] = p_m_n_queries + 4;
  *(_DWORD *)&impulses_4[72] = v7;
  v115 = v9;
  if ( v8 )
  {
    qmemcpy(mcr_0_4, &v7->physical_core->m_world_f_core_last_psi, sizeof(mcr_0_4));
    IVP_U_Matrix::vmult4(
      this: (IVP_U_Matrix *)mcr_0_4,
      p_in: &v7->shift_core_f_object,
      p_out: (IVP_U_Float_Point *)&mcr_0_4[48]);
    v12 = *(float *)mcr_0_4;
    v13 = *(float *)&mcr_0_4[16];
    v14 = *(float *)&mcr_0_4[32];
    v15 = *(float *)&mcr_0_4[4];
    v9 = v115;
    v10 = *(hk_VM_Query_Builder<hk_VMQ_Storage<3> > **)&impulses_4[64];
    p_m_n_queries = (float *)&m_input->m_n_queries;
    this = (hk_Ball_Socket_Constraint *)LODWORD(mcr_1.m_vector.y);
    *(_DWORD *)&impulses_4[20] = *(_DWORD *)&mcr_0_4[20];
    *(_DWORD *)&impulses_4[24] = *(_DWORD *)&mcr_0_4[36];
    *(_DWORD *)&impulses_4[32] = *(_DWORD *)&mcr_0_4[8];
    *(_DWORD *)&impulses_4[36] = *(_DWORD *)&mcr_0_4[24];
    *(_DWORD *)&impulses_4[40] = *(_DWORD *)&mcr_0_4[40];
    *(_DWORD *)&impulses_4[48] = *(_DWORD *)&mcr_0_4[48];
    *(_DWORD *)&impulses_4[52] = *(_DWORD *)&mcr_0_4[52];
    v16 = *(float *)&mcr_0_4[56];
  }
  else
  {
    physical_core = v7->physical_core;
    v12 = physical_core->m_world_f_core_last_psi.rows[0].k[0];
    v13 = physical_core->m_world_f_core_last_psi.rows[1].k[0];
    v14 = physical_core->m_world_f_core_last_psi.rows[2].k[0];
    v15 = physical_core->m_world_f_core_last_psi.rows[0].k[1];
    *(float *)&impulses_4[20] = physical_core->m_world_f_core_last_psi.rows[1].k[1];
    *(float *)&impulses_4[24] = physical_core->m_world_f_core_last_psi.rows[2].k[1];
    *(float *)&impulses_4[32] = physical_core->m_world_f_core_last_psi.rows[0].k[2];
    *(float *)&impulses_4[36] = physical_core->m_world_f_core_last_psi.rows[1].k[2];
    *(float *)&impulses_4[40] = physical_core->m_world_f_core_last_psi.rows[2].k[2];
    *(float *)&impulses_4[48] = physical_core->m_world_f_core_last_psi.vv.k[0];
    *(float *)&impulses_4[52] = physical_core->m_world_f_core_last_psi.vv.k[1];
    v16 = physical_core->m_world_f_core_last_psi.vv.k[2];
  }
  v8 = (*(_DWORD *)&v9->flags & 0x800) == 0;
  x = this->m_translation_os_ks[0].x;
  z = this->m_translation_os_ks[0].z;
  *(float *)&impulses_4[56] = v16;
  y = this->m_translation_os_ks[0].y;
  *(float *)&impulses_4[68] = (float)((float)((float)(y * v15) + (float)(x * v12))
                                    + (float)(z * *(float *)&impulses_4[32]))
                            + *(float *)&impulses_4[48];
  mcr_1.m_vector.z = (float)((float)((float)(x * v13) + (float)(y * *(float *)&impulses_4[20]))
                           + (float)(z * *(float *)&impulses_4[36]))
                   + *(float *)&impulses_4[52];
  mcr_1.m_vector.w = (float)((float)((float)(y * *(float *)&impulses_4[24]) + (float)(x * v14))
                           + (float)(z * *(float *)&impulses_4[40]))
                   + *(float *)&impulses_4[56];
  if ( v8 )
  {
    qmemcpy(impulses_4, &v9->physical_core->m_world_f_core_last_psi, 0x40u);
    IVP_U_Matrix::vmult4(
      this: (IVP_U_Matrix *)impulses_4,
      p_in: &v9->shift_core_f_object,
      p_out: (IVP_U_Float_Point *)&impulses_4[48]);
    v21 = *(float *)impulses_4;
    v22 = *(float *)&impulses_4[16];
    v23 = *(float *)&impulses_4[32];
    v24 = *(float *)&impulses_4[4];
    v25 = *(float *)&impulses_4[20];
    v10 = *(hk_VM_Query_Builder<hk_VMQ_Storage<3> > **)&impulses_4[64];
    p_m_n_queries = (float *)&m_input->m_n_queries;
    this = (hk_Ball_Socket_Constraint *)LODWORD(mcr_1.m_vector.y);
    *(_DWORD *)&mcr_0_4[24] = *(_DWORD *)&impulses_4[36];
    *(_DWORD *)&mcr_0_4[32] = *(_DWORD *)&impulses_4[8];
    *(_DWORD *)&mcr_0_4[36] = *(_DWORD *)&impulses_4[24];
    *(_DWORD *)&mcr_0_4[40] = *(_DWORD *)&impulses_4[40];
    *(_DWORD *)&mcr_0_4[48] = *(_DWORD *)&impulses_4[48];
    *(_DWORD *)&mcr_0_4[52] = *(_DWORD *)&impulses_4[52];
    v26 = *(float *)&impulses_4[56];
  }
  else
  {
    v20 = v9->physical_core;
    v21 = v20->m_world_f_core_last_psi.rows[0].k[0];
    v22 = v20->m_world_f_core_last_psi.rows[1].k[0];
    v23 = v20->m_world_f_core_last_psi.rows[2].k[0];
    v24 = v20->m_world_f_core_last_psi.rows[0].k[1];
    v25 = v20->m_world_f_core_last_psi.rows[1].k[1];
    *(float *)&mcr_0_4[24] = v20->m_world_f_core_last_psi.rows[2].k[1];
    *(float *)&mcr_0_4[32] = v20->m_world_f_core_last_psi.rows[0].k[2];
    *(float *)&mcr_0_4[36] = v20->m_world_f_core_last_psi.rows[1].k[2];
    *(float *)&mcr_0_4[40] = v20->m_world_f_core_last_psi.rows[2].k[2];
    *(float *)&mcr_0_4[48] = v20->m_world_f_core_last_psi.vv.k[0];
    *(float *)&mcr_0_4[52] = v20->m_world_f_core_last_psi.vv.k[1];
    v26 = v20->m_world_f_core_last_psi.vv.k[2];
  }
  v27 = this->m_translation_os_ks[1].x;
  v28 = this->m_translation_os_ks[1].z;
  *(float *)&mcr_0_4[56] = v26;
  v29 = this->m_translation_os_ks[1].y;
  *(float *)&impulses_4[48] = (float)((float)((float)(v24 * v29) + (float)(v21 * v27))
                                    + (float)(*(float *)&mcr_0_4[32] * v28))
                            + *(float *)&mcr_0_4[48];
  *(float *)&impulses_4[52] = (float)((float)((float)(v22 * v27) + (float)(v25 * v29))
                                    + (float)(*(float *)&mcr_0_4[36] * v28))
                            + *(float *)&mcr_0_4[52];
  v30 = *(float *)&impulses_4[52] - mcr_1.m_vector.z;
  *(float *)&impulses_4[56] = (float)((float)((float)(v23 * v27) + (float)(*(float *)&mcr_0_4[24] * v29))
                                    + (float)(*(float *)&mcr_0_4[40] * v28))
                            + *(float *)&mcr_0_4[56];
  v31 = *(float *)&impulses_4[56] - mcr_1.m_vector.w;
  *p_m_n_queries = *(float *)&impulses_4[48] - *(float *)&impulses_4[68];
  p_m_n_queries[1] = v30;
  p_m_n_queries[2] = v31;
  hk_VM_Query_Builder<hk_VMQ_Storage<3>>::begin(this: v10, size: 3);
  v32 = *(_DWORD *)&impulses_4[72];
  v33 = *(float **)(*(_DWORD *)&impulses_4[72] + 148);
  v34 = *(float *)&impulses_4[68] - v33[36];
  v35 = mcr_1.m_vector.z - v33[37];
  v36 = mcr_1.m_vector.w - v33[38];
  v37 = (float *)v115->physical_core;
  v38 = v36;
  *(float *)&query_engine = *(float *)&impulses_4[48] - v37[36];
  v112 = *(float *)&impulses_4[52] - v37[37];
  v39 = *(float *)&impulses_4[56] - v37[38];
  v40 = (int)v10->m_vmq_storage.m_impulse_info + v10->m_vmq_offset;
  *(float *)&b0 = v39;
  *(_QWORD *)(v40 + 4) = 0;
  *(_DWORD *)v40 = 1065353216;
  *(float *)(v40 + 20) = v38;
  v104 = v35;
  *(_DWORD *)(v40 + 16) = 0;
  LODWORD(v41) = LODWORD(v35) ^ _mask__NegFloat_;
  *(float *)(v40 + 24) = v41;
  v42 = *(float **)(v32 + 148);
  v43 = v41;
  v105 = v38;
  v44 = (float)((float)(v42[25] * 0.0) + (float)(v42[29] * v38)) + (float)(v42[33] * v41);
  v45 = (float)(v42[28] * v38) + (float)(v42[24] * 0.0);
  v46 = v42[32];
  *(float *)(v40 + 24) = (float)((float)(v42[26] * 0.0) + (float)(v42[30] * v38)) + (float)(v42[34] * v43);
  *(float *)(v40 + 20) = v44;
  v47 = b0;
  *(float *)(v40 + 16) = v45 + (float)(v46 * v43);
  *(_DWORD *)(v40 + 32) = v10->m_dense_matrix_offset;
  m_vmq_offset = v10->m_vmq_offset;
  *(_QWORD *)((char *)&v10->m_vmq_storage.m_impulse_info[1][1] + m_vmq_offset) = 0;
  v49 = v115;
  *(float *)((char *)v10->m_vmq_storage.m_impulse_info[1] + m_vmq_offset) = -1.0;
  *(float *)((char *)&v10->m_vmq_storage.m_impulse_info[1][4] + m_vmq_offset) = 0.0;
  v50 = (int)v10->m_vmq_storage.m_impulse_info[1] + m_vmq_offset;
  *(float *)(v50 + 20) = *(float *)&v47 * -1.0;
  v51 = v112;
  *(float *)(v50 + 24) = v112;
  v52 = (float *)v49->physical_core;
  v53 = *(float *)(v50 + 20);
  v54 = (float)((float)(v52[26] * 0.0) + (float)(v52[30] * v53)) + (float)(v52[34] * v51);
  v55 = (float)(v52[28] * v53) + (float)(v52[24] * 0.0);
  v56 = v52[32] * *(float *)(v50 + 24);
  *(float *)(v50 + 20) = (float)((float)(v52[25] * 0.0) + (float)(v52[29] * v53)) + (float)(v52[33] * v51);
  *(float *)(v50 + 24) = v54;
  *(float *)(v50 + 16) = v55 + v56;
  *(_DWORD *)(v50 + 32) = v10->m_dense_matrix_offset;
  v57 = (int)&v10->m_vmq_storage.m_impulse_info[0][12] + v10->m_vmq_offset;
  *(_DWORD *)(v57 + 8) = 0;
  *(_DWORD *)v57 = 0;
  *(_DWORD *)(v57 + 4) = 1065353216;
  *(_DWORD *)(v57 + 16) = LODWORD(v105) ^ _mask__NegFloat_;
  *(_DWORD *)(v57 + 20) = 0;
  *(float *)(v57 + 24) = v34;
  v58 = *(float **)(v32 + 148);
  v59 = (float)((float)(v58[26] * *(float *)(v57 + 16)) + (float)(v58[30] * 0.0)) + (float)(v58[34] * v34);
  v60 = (float)(v58[28] * 0.0) + (float)(v58[24] * *(float *)(v57 + 16));
  v61 = v58[32];
  *(float *)(v57 + 20) = (float)((float)(v58[25] * *(float *)(v57 + 16)) + (float)(v58[29] * 0.0))
                       + (float)(v58[33] * v34);
  *(float *)(v57 + 24) = v59;
  v62 = b0;
  *(float *)(v57 + 16) = v60 + (float)(v61 * v34);
  *(_DWORD *)(v57 + 32) = v10->m_dense_matrix_offset + 1;
  v63 = v10->m_vmq_offset;
  v64 = v115;
  *(float *)((char *)&v10->m_vmq_storage.m_impulse_info[1][14] + v63) = 0.0;
  *(float *)((char *)&v10->m_vmq_storage.m_impulse_info[1][12] + v63) = 0.0;
  *(float *)((char *)&v10->m_vmq_storage.m_impulse_info[1][13] + v63) = -1.0;
  *(_DWORD *)((char *)&v10->m_vmq_storage.m_impulse_info[1][16] + v63) = v62;
  v65 = query_engine;
  v66 = (int)&v10->m_vmq_storage.m_impulse_info[1][12] + v63;
  *(_DWORD *)(v66 + 20) = 0;
  *(float *)(v66 + 24) = *(float *)&v65 * -1.0;
  v67 = (float *)v64->physical_core;
  v68 = *(float *)(v66 + 16);
  v69 = (float)((float)(v67[25] * v68) + (float)(v67[29] * 0.0)) + (float)(v67[33] * *(float *)(v66 + 24));
  v70 = v67[26] * v68;
  v71 = v68 * v67[24];
  v72 = (float)(v70 + (float)(v67[30] * 0.0)) + (float)(v67[34] * *(float *)(v66 + 24));
  v73 = v67[28] * 0.0;
  v74 = v67[32] * *(float *)(v66 + 24);
  *(float *)(v66 + 20) = v69;
  *(float *)(v66 + 24) = v72;
  *(float *)(v66 + 16) = (float)(v73 + v71) + v74;
  *(_DWORD *)(v66 + 32) = v10->m_dense_matrix_offset + 1;
  v75 = (int)&v10->m_vmq_storage.m_impulse_info[0][24] + v10->m_vmq_offset;
  *(_QWORD *)v75 = 0;
  *(_DWORD *)(v75 + 8) = 1065353216;
  *(float *)(v75 + 16) = v104;
  LODWORD(v76) = LODWORD(v34) ^ _mask__NegFloat_;
  *(float *)(v75 + 20) = v76;
  *(_DWORD *)(v75 + 24) = 0;
  v77 = *(float **)(v32 + 148);
  v78 = (float)((float)(v77[26] * v104) + (float)(v77[30] * v76)) + (float)(v77[34] * 0.0);
  v79 = (float)(v77[28] * v76) + (float)(v104 * v77[24]);
  v80 = v77[32];
  *(float *)(v75 + 20) = (float)((float)(v77[25] * v104) + (float)(v77[29] * v76)) + (float)(v77[33] * 0.0);
  *(float *)(v75 + 24) = v78;
  *(float *)(v75 + 16) = v79 + (float)(v80 * 0.0);
  v81 = v112 * -1.0;
  *(_DWORD *)(v75 + 32) = v10->m_dense_matrix_offset + 2;
  v82 = v10->m_vmq_offset;
  v83 = v115;
  *(_QWORD *)((char *)&v10->m_vmq_storage.m_impulse_info[1][24] + v82) = 0;
  *(float *)((char *)&v10->m_vmq_storage.m_impulse_info[1][26] + v82) = -1.0;
  v84 = query_engine;
  *(float *)((char *)&v10->m_vmq_storage.m_impulse_info[1][28] + v82) = v81;
  *(float *)((char *)&v10->m_vmq_storage.m_impulse_info[1][29] + v82) = *(float *)&v84;
  *(float *)((char *)&v10->m_vmq_storage.m_impulse_info[1][30] + v82) = 0.0;
  v85 = (float *)v83->physical_core;
  v86 = (int)&v10->m_vmq_storage.m_impulse_info[1][24] + v82;
  v87 = v81;
  v88 = *(float *)&v84;
  v89 = (float)((float)(v85[25] * v81) + (float)(v85[29] * *(float *)&v84)) + (float)(v85[33] * 0.0);
  v90 = (float)((float)(v85[26] * v81) + (float)(v85[30] * v88)) + (float)(v85[34] * 0.0);
  *(float *)(v86 + 16) = (float)((float)(v85[28] * v88) + (float)(v87 * v85[24])) + (float)(v85[32] * 0.0);
  *(float *)(v86 + 20) = v89;
  *(float *)(v86 + 24) = v90;
  *(_DWORD *)(v86 + 32) = v10->m_dense_matrix_offset + 2;
  v10->m_dense_matrix_offset += 3;
  m_dense_matrix_offset = v10->m_dense_matrix_offset;
  v10->m_vmq_offset += 144;
  v10->m_input[0].m_n_queries = m_dense_matrix_offset;
  m_input = v10->m_input;
  v10->m_input[1].m_n_queries = m_dense_matrix_offset;
  LODWORD(mcr_1.m_vector.w) = &v10->m_vmq_storage.m_dense_matrix;
  LODWORD(mcr_1.m_vector.z) = &v10->m_input[1];
  hk_Rigid_Body_Core::add_to_mass_matrix_inv(
    this: *(hk_Rigid_Body_Core **)(v32 + 148),
    input: m_input,
    matrix_out: &v10->m_vmq_storage.m_dense_matrix,
    velocities_out: v10->m_vmq_storage.m_velocities);
  v92 = v10->m_dense_matrix_offset;
  w = mcr_1.m_vector.w;
  m_input->m_n_queries = v92;
  v94 = mcr_1.m_vector.z;
  *(_DWORD *)LODWORD(mcr_1.m_vector.z) = v92;
  hk_Rigid_Body_Core::add_to_mass_matrix_inv(
    this: (hk_Rigid_Body_Core *)v115->physical_core,
    input: (hk_Core_VMQ_Input *)LODWORD(v94),
    matrix_out: (hk_Dense_Matrix *)LODWORD(w),
    velocities_out: v10->m_vmq_storage.m_velocities);
  v95 = (float)(*(float *)(LODWORD(mcr_1.m_vector.y) + 56) * tau_factor) * pi->i_delta_time;
  v96 = (float)(*(float *)(LODWORD(mcr_1.m_vector.y) + 60) * -1.0) * damp_factor;
  *(float *)&query_engine = (float)(v96 * v10->m_vmq_storage.m_velocities[0]) + (float)(*p_m_n_queries * v95);
  v97 = v95 * p_m_n_queries[1];
  v98 = v95 * p_m_n_queries[2];
  v112 = (float)(v10->m_vmq_storage.m_velocities[1] * v96) + v97;
  v99 = v10->m_vmq_storage.m_velocities[2];
  v100 = mcr_1.m_vector.w;
  *(float *)&b0 = (float)(v99 * v96) + v98;
  hk_Dense_Matrix_Util::invert_3x3_symmetric(m: (hk_Dense_Matrix *)LODWORD(mcr_1.m_vector.w), tolerance: 0.0);
  v101 = *(float **)LODWORD(v100);
  v102 = *(_DWORD *)(LODWORD(v100) + 12);
  v107 = *(float *)&query_engine * **(float **)LODWORD(v100);
  v108 = v101[1] * *(float *)&query_engine;
  v102 *= 4;
  v109 = v101[2] * *(float *)&query_engine;
  v107 = (float)(v112 * *(float *)((char *)v101 + v102)) + v107;
  v108 = (float)(*(float *)((char *)v101 + v102 + 4) * v112) + v108;
  v109 = (float)(*(float *)((char *)v101 + v102 + 8) * v112) + v109;
  v107 = (float)(*(float *)&b0 * *(float *)((char *)v101 + v102 + v102)) + v107;
  v108 = (float)(*(float *)((char *)v101 + v102 + v102 + 4) * *(float *)&b0) + v108;
  v109 = (float)(*(float *)((char *)v101 + v102 + v102 + 8) * *(float *)&b0) + v109;
  hk_Rigid_Body_Core::apply_impulses(
    this: *(hk_Rigid_Body_Core **)(*(_DWORD *)&impulses_4[72] + 148),
    input: m_input,
    impulse_strength: &v107);
  hk_Rigid_Body_Core::apply_impulses(
    this: (hk_Rigid_Body_Core *)v115->physical_core,
    input: (hk_Core_VMQ_Input *)LODWORD(mcr_1.m_vector.z),
    impulse_strength: &v107);
  return 512;
}

//------------------------------------------------------------------------------
// Address: 0x10037390
// Name: public: void hk_VM_Query_Builder<class hk_VMQ_Storage<1>>::begin(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_VM_Query_Builder<hk_VMQ_Storage<1>>::begin(hk_VM_Query_Builder<hk_VMQ_Storage<1> > *this, int size)
{
  int v2; // eax

  this->m_input[1].m_buffer = (hk_Cached_Force_Axis_Description *)this->m_vmq_storage.m_buffer_1;
  this->m_input[0].m_buffer = (hk_Cached_Force_Axis_Description *)this->m_vmq_storage.m_buffer_0;
  this->m_input[1].m_vmq = (hk_Virtual_Mass_Query *)this->m_vmq_storage.m_impulse_info[1];
  this->m_input[0].m_vmq = (hk_Virtual_Mass_Query *)this->m_vmq_storage.m_impulse_info;
  this->m_vmq_offset = 0;
  this->m_dense_matrix_offset = 0;
  v2 = this->m_vmq_storage.m_dense_matrix.m_rows * this->m_vmq_storage.m_dense_matrix.m_lda - 1;
  if ( v2 >= 0 )
  {
    if ( this->m_vmq_storage.m_dense_matrix.m_rows * this->m_vmq_storage.m_dense_matrix.m_lda >= 4 )
    {
      do
      {
        this->m_vmq_storage.m_dense_matrix.m_elt[v2] = 0.0;
        this->m_vmq_storage.m_dense_matrix.m_elt[v2 - 1] = 0.0;
        this->m_vmq_storage.m_dense_matrix.m_elt[v2 - 2] = 0.0;
        this->m_vmq_storage.m_dense_matrix.m_elt[v2 - 3] = 0.0;
        v2 -= 4;
      }
      while ( v2 >= 3 );
    }
    for ( ; v2 >= 0; this->m_vmq_storage.m_dense_matrix.m_elt[v2 + 1] = 0.0 )
      --v2;
  }
  this->m_vmq_storage.m_velocities[3] = 0.0;
  this->m_vmq_storage.m_velocities[2] = 0.0;
  this->m_vmq_storage.m_velocities[1] = 0.0;
  this->m_vmq_storage.m_velocities[0] = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10039680
// Name: public: void hk_VM_Query_Builder<class hk_VMQ_Storage<5>>::begin(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_VM_Query_Builder<hk_VMQ_Storage<5>>::begin(hk_VM_Query_Builder<hk_VMQ_Storage<5> > *this, int size)
{
  int v2; // eax

  this->m_input[1].m_buffer = (hk_Cached_Force_Axis_Description *)this->m_vmq_storage.m_buffer_1;
  this->m_input[0].m_buffer = (hk_Cached_Force_Axis_Description *)this->m_vmq_storage.m_buffer_0;
  this->m_input[1].m_vmq = (hk_Virtual_Mass_Query *)this->m_vmq_storage.m_impulse_info[1];
  this->m_input[0].m_vmq = (hk_Virtual_Mass_Query *)this->m_vmq_storage.m_impulse_info;
  this->m_vmq_offset = 0;
  this->m_dense_matrix_offset = 0;
  v2 = this->m_vmq_storage.m_dense_matrix.m_rows * this->m_vmq_storage.m_dense_matrix.m_lda - 1;
  if ( v2 >= 0 )
  {
    if ( this->m_vmq_storage.m_dense_matrix.m_rows * this->m_vmq_storage.m_dense_matrix.m_lda >= 4 )
    {
      do
      {
        this->m_vmq_storage.m_dense_matrix.m_elt[v2] = 0.0;
        this->m_vmq_storage.m_dense_matrix.m_elt[v2 - 1] = 0.0;
        this->m_vmq_storage.m_dense_matrix.m_elt[v2 - 2] = 0.0;
        this->m_vmq_storage.m_dense_matrix.m_elt[v2 - 3] = 0.0;
        v2 -= 4;
      }
      while ( v2 >= 3 );
    }
    for ( ; v2 >= 0; this->m_vmq_storage.m_dense_matrix.m_elt[v2 + 1] = 0.0 )
      --v2;
  }
  this->m_vmq_storage.m_velocities[3] = 0.0;
  this->m_vmq_storage.m_velocities[2] = 0.0;
  this->m_vmq_storage.m_velocities[1] = 0.0;
  this->m_vmq_storage.m_velocities[0] = 0.0;
  this->m_vmq_storage.m_velocities[7] = 0.0;
  this->m_vmq_storage.m_velocities[6] = 0.0;
  this->m_vmq_storage.m_velocities[5] = 0.0;
  this->m_vmq_storage.m_velocities[4] = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1003FC70
// Name: public: virtual int hk_Ball_Socket_Constraint::get_constraint_dof(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall hk_Ball_Socket_Constraint::get_constraint_dof(IVP_OV_Element *this)
{
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x100414A0
// Name: public: void hk_VM_Query_Builder<class hk_VMQ_Storage<6>>::begin(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_VM_Query_Builder<hk_VMQ_Storage<6>>::begin(hk_VM_Query_Builder<hk_VMQ_Storage<6> > *this, int size)
{
  int v2; // eax

  this->m_input[1].m_buffer = (hk_Cached_Force_Axis_Description *)this->m_vmq_storage.m_buffer_1;
  this->m_input[0].m_buffer = (hk_Cached_Force_Axis_Description *)this->m_vmq_storage.m_buffer_0;
  this->m_input[1].m_vmq = (hk_Virtual_Mass_Query *)this->m_vmq_storage.m_impulse_info[1];
  this->m_input[0].m_vmq = (hk_Virtual_Mass_Query *)this->m_vmq_storage.m_impulse_info;
  this->m_vmq_offset = 0;
  this->m_dense_matrix_offset = 0;
  v2 = this->m_vmq_storage.m_dense_matrix.m_rows * this->m_vmq_storage.m_dense_matrix.m_lda - 1;
  if ( v2 >= 0 )
  {
    if ( this->m_vmq_storage.m_dense_matrix.m_rows * this->m_vmq_storage.m_dense_matrix.m_lda >= 4 )
    {
      do
      {
        this->m_vmq_storage.m_dense_matrix.m_elt[v2] = 0.0;
        this->m_vmq_storage.m_dense_matrix.m_elt[v2 - 1] = 0.0;
        this->m_vmq_storage.m_dense_matrix.m_elt[v2 - 2] = 0.0;
        this->m_vmq_storage.m_dense_matrix.m_elt[v2 - 3] = 0.0;
        v2 -= 4;
      }
      while ( v2 >= 3 );
    }
    for ( ; v2 >= 0; this->m_vmq_storage.m_dense_matrix.m_elt[v2 + 1] = 0.0 )
      --v2;
  }
  this->m_vmq_storage.m_velocities[3] = 0.0;
  this->m_vmq_storage.m_velocities[2] = 0.0;
  this->m_vmq_storage.m_velocities[1] = 0.0;
  this->m_vmq_storage.m_velocities[0] = 0.0;
  this->m_vmq_storage.m_velocities[7] = 0.0;
  this->m_vmq_storage.m_velocities[6] = 0.0;
  this->m_vmq_storage.m_velocities[5] = 0.0;
  this->m_vmq_storage.m_velocities[4] = 0.0;
}
