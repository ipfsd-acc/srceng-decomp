// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_intern/ivp_friction.cxx
// Functions: 49
// ============================================================

#include "ivp\ivp_intern\ivp_friction.h"

//------------------------------------------------------------------------------
// Address: 0x10081010
// Name: public: float IVP_Impact_Solver_Long_Term::get_closing_speed(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall IVP_Impact_Solver_Long_Term::get_closing_speed(IVP_Impact_Solver_Long_Term *this)
{
  IVP_Core *v1; // eax
  float v2; // xmm0_4
  IVP_Core *v3; // eax
  float v5; // [esp+0h] [ebp-4h]

  v1 = this->contact_core[0];
  v2 = 0.0;
  v5 = 0.0;
  if ( v1 != nullptr )
  {
    v2 = (float)((float)((float)(this->contact_cross_nomal_cs[0].k[1] * v1->rot_speed.k[1])
                       + (float)(this->contact_cross_nomal_cs[0].k[0] * v1->rot_speed.k[0]))
               + (float)(this->contact_cross_nomal_cs[0].k[2] * v1->rot_speed.k[2]))
       + (float)((float)((float)(this->surf_normal.k[1] * v1->speed.k[1])
                       + (float)(v1->speed.k[0] * this->surf_normal.k[0]))
               + (float)(this->surf_normal.k[2] * v1->speed.k[2]));
    v5 = v2;
  }
  v3 = this->contact_core[1];
  if ( v3 != nullptr )
    return (float)(v2
                 - (float)((float)((float)((float)(this->contact_cross_nomal_cs[1].k[1] * v3->rot_speed.k[1])
                                         + (float)(this->contact_cross_nomal_cs[1].k[0] * v3->rot_speed.k[0]))
                                 + (float)(this->contact_cross_nomal_cs[1].k[2] * v3->rot_speed.k[2]))
                         + (float)((float)((float)(this->surf_normal.k[1] * v3->speed.k[1])
                                         + (float)(v3->speed.k[0] * this->surf_normal.k[0]))
                                 + (float)(this->surf_normal.k[2] * v3->speed.k[2]))));
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10081120
// Name: public: static void IVP_Friction_Solver::apply_impulse(class IVP_Impact_Solver_Long_Term const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Friction_Solver::apply_impulse(const IVP_Impact_Solver_Long_Term *info, float impulse)
{
  IVP_Core *v2; // eax
  float v3; // xmm4_4
  float v4; // xmm1_4
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  IVP_Core *v8; // eax
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm2_4

  v2 = info->contact_core[0];
  if ( v2 != nullptr )
  {
    v3 = info->contact_cross_nomal_cs[0].k[0] * v2->inv_rot_inertia.k[0];
    v4 = info->contact_cross_nomal_cs[0].k[2] * v2->inv_rot_inertia.k[2];
    v2->rot_speed.k[1] = (float)((float)(info->contact_cross_nomal_cs[0].k[1] * v2->inv_rot_inertia.k[1])
                               * (float)-impulse)
                       + v2->rot_speed.k[1];
    v2->rot_speed.k[2] = (float)(v4 * (float)-impulse) + v2->rot_speed.k[2];
    v2->rot_speed.k[0] = (float)((float)-impulse * v3) + v2->rot_speed.k[0];
    v5 = -(float)(v2->inv_rot_inertia.hesse_val * impulse);
    v6 = (float)(info->surf_normal.k[1] * v5) + v2->speed.k[1];
    v7 = (float)(info->surf_normal.k[2] * v5) + v2->speed.k[2];
    v2->speed.k[0] = (float)(info->surf_normal.k[0] * v5) + v2->speed.k[0];
    v2->speed.k[1] = v6;
    v2->speed.k[2] = v7;
  }
  v8 = info->contact_core[1];
  if ( v8 != nullptr )
  {
    v9 = info->contact_cross_nomal_cs[1].k[0] * v8->inv_rot_inertia.k[0];
    v10 = info->contact_cross_nomal_cs[1].k[2] * v8->inv_rot_inertia.k[2];
    v8->rot_speed.k[1] = (float)((float)(info->contact_cross_nomal_cs[1].k[1] * v8->inv_rot_inertia.k[1]) * impulse)
                       + v8->rot_speed.k[1];
    v8->rot_speed.k[2] = (float)(v10 * impulse) + v8->rot_speed.k[2];
    v8->rot_speed.k[0] = (float)(v9 * impulse) + v8->rot_speed.k[0];
    v11 = v8->inv_rot_inertia.hesse_val * impulse;
    v12 = (float)(info->surf_normal.k[1] * v11) + v8->speed.k[1];
    v13 = (float)(info->surf_normal.k[2] * v11) + v8->speed.k[2];
    v8->speed.k[0] = (float)(info->surf_normal.k[0] * v11) + v8->speed.k[0];
    v8->speed.k[1] = v12;
    v8->speed.k[2] = v13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100812D0
// Name: private: float IVP_Contact_Point::two_values_friction(class IVP_U_Float_Point __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
double __userpurge IVP_Contact_Point::two_values_friction@<st0>(
        IVP_Contact_Point *this@<ecx>,
        int a2@<ebp>,
        IVP_U_Float_Point *real_world_friction_vec)
{
  const IVP_U_Float_Point *p_contact_point_ws; // esi
  int v5; // eax
  IVP_Core *friction_core; // eax
  double v7; // st7
  float real_friction_factor; // xmm1_4
  float *k; // eax
  float v10; // xmm3_4
  float v11; // xmm4_4
  float v12; // xmm2_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  float v18; // xmm3_4
  float v19; // xmm4_4
  unsigned int v20; // xmm2_4
  unsigned int v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm0_4
  float v24; // xmm4_4
  float v25; // xmm1_4
  float v26; // xmm2_4
  _DWORD v28[3]; // [esp-Ch] [ebp-6Ch] BYREF
  _BYTE x_direction_4[28]; // [esp+4h] [ebp-5Ch] OVERLAPPED BYREF
  IVP_U_Float_Point x_in_surface; // [esp+20h] [ebp-40h]
  IVP_U_Float_Point friction_vec; // [esp+30h] [ebp-30h] BYREF
  IVP_Material *mtl[2]; // [esp+40h] [ebp-20h]
  float *relevance_factor; // [esp+48h] [ebp-18h]
  IVP_Real_Object **second_friction_val; // [esp+4Ch] [ebp-14h]
  int max_len_in_x_direction; // [esp+50h] [ebp-10h]
  int v36; // [esp+54h] [ebp-Ch]
  void *v37; // [esp+58h] [ebp-8h]
  void *retaddr; // [esp+60h] [ebp+0h]

  v36 = a2;
  v37 = retaddr;
  IVP_Contact_Point::get_material_info(this, mtl: (IVP_Material **)&friction_vec.k[1]);
  p_contact_point_ws = &this->tmp_contact_info->contact_point_ws;
  v5 = 0;
  max_len_in_x_direction = 0;
  relevance_factor = &friction_vec.k[2];
  second_friction_val = &this->synapse[0].l_obj;
  while ( *(_DWORD *)(LODWORD(friction_vec.k[v5 + 1]) + 8) == 0 )
  {
LABEL_8:
    second_friction_val += 5;
    --relevance_factor;
    v5 = max_len_in_x_direction + 1;
    max_len_in_x_direction = v5;
    if ( v5 >= 2 )
    {
      v23 = this->span_friction_s[0];
      v24 = this->span_friction_s[1];
      v25 = (float)(p_contact_point_ws[9].k[1] * v24) + (float)(p_contact_point_ws[8].k[1] * v23);
      v26 = (float)(p_contact_point_ws[9].k[2] * v24) + (float)(p_contact_point_ws[8].k[2] * v23);
      real_world_friction_vec->k[0] = (float)(v24 * p_contact_point_ws[9].k[0])
                                    + (float)(p_contact_point_ws[8].k[0] * v23);
      real_world_friction_vec->k[1] = v25;
      real_world_friction_vec->k[2] = v26;
      return IVP_U_Float_Point::real_length_plus_normize(this: real_world_friction_vec);
    }
  }
  friction_core = (*second_friction_val)->friction_core;
  v28[0] = LODWORD(friction_core->m_world_f_core_last_psi.rows[0].k[0]);
  v28[1] = LODWORD(friction_core->m_world_f_core_last_psi.rows[1].k[0]);
  v28[2] = LODWORD(friction_core->m_world_f_core_last_psi.rows[2].k[0]);
  IVP_U_Float_Point::set_orthogonal_part(
    this: (IVP_U_Float_Point *)&x_direction_4[16],
    vector: (const IVP_U_Float_Point *)v28,
    normal_v: p_contact_point_ws + 1);
  friction_vec.hesse_val = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Point *)&x_direction_4[16]);
  *(float *)mtl = ((double (__thiscall *)(_DWORD))*(_DWORD *)(*(_DWORD *)LODWORD(friction_vec.k[max_len_in_x_direction
                                                                                              + 1])
                                                            + 8))(a1: LODWORD(friction_vec.k[max_len_in_x_direction + 1]));
  v7 = ((double (__thiscall *)(_DWORD))*(_DWORD *)(**(_DWORD **)relevance_factor + 4))(a1: *(_DWORD *)relevance_factor);
  real_friction_factor = this->real_friction_factor;
  *(float *)mtl = v7 * *(float *)mtl;
  if ( real_friction_factor >= 1.0e-10 )
  {
    k = this->tmp_contact_info->contact_point_ws.k;
    v10 = k[34];
    v11 = this->span_friction_s[1];
    v12 = k[33];
    v13 = (float)((float)(real_friction_factor
                        - (float)((float)(real_friction_factor - *(float *)mtl) * friction_vec.hesse_val))
                * 0.0049999999)
        / real_friction_factor;
    v14 = k[32];
    mtl[1] = (IVP_Material *)LODWORD(v13);
    v15 = this->span_friction_s[0];
    x_in_surface.k[1] = (float)(k[36] * v11) + (float)(v14 * v15);
    x_in_surface.k[2] = (float)(k[37] * v11) + (float)(v12 * v15);
    x_in_surface.hesse_val = (float)(k[38] * v11) + (float)(v10 * v15);
    IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)&x_direction_4[16]);
    v16 = (float)((float)(*(float *)&x_direction_4[16] * x_in_surface.k[1])
                + (float)(*(float *)&x_direction_4[20] * x_in_surface.k[2]))
        + (float)(*(float *)&x_direction_4[24] * x_in_surface.hesse_val);
    if ( fabs(v16) > *(float *)&mtl[1] )
    {
      v17 = *(float *)&x_direction_4[16] * *(float *)&mtl[1];
      v18 = *(float *)&x_direction_4[20] * *(float *)&mtl[1];
      v19 = *(float *)&x_direction_4[24] * *(float *)&mtl[1];
      if ( v16 < 0.0 )
      {
        v17 = v17 * -1.0;
        v18 = v18 * -1.0;
        v19 = v19 * -1.0;
      }
      *(float *)&v20 = v17
                     + (float)((float)(*(float *)&x_direction_4[16] * COERCE_FLOAT(LODWORD(v16) ^ _mask__NegFloat_))
                             + x_in_surface.k[1]);
      *(float *)&v21 = v18
                     + (float)((float)(*(float *)&x_direction_4[20] * COERCE_FLOAT(LODWORD(v16) ^ _mask__NegFloat_))
                             + x_in_surface.k[2]);
      *(_QWORD *)x_direction_4 = __PAIR64__(v21, v20);
      v22 = v19
          + (float)((float)(*(float *)&x_direction_4[24] * COERCE_FLOAT(LODWORD(v16) ^ _mask__NegFloat_))
                  + x_in_surface.hesse_val);
      *(_QWORD *)real_world_friction_vec->k = __PAIR64__(v21, v20);
      *(float *)&x_direction_4[8] = v22;
      *(_QWORD *)&real_world_friction_vec->k[2] = *(_QWORD *)&x_direction_4[8];
      this->span_friction_s[0] = (float)((float)(p_contact_point_ws[8].k[1] * *(float *)&v21)
                                       + (float)(p_contact_point_ws[8].k[0] * *(float *)&v20))
                               + (float)(p_contact_point_ws[8].k[2] * v22);
      this->span_friction_s[1] = (float)((float)(p_contact_point_ws[9].k[1] * *(float *)&v21)
                                       + (float)(*(float *)&v20 * p_contact_point_ws[9].k[0]))
                               + (float)(p_contact_point_ws[9].k[2] * v22);
    }
    goto LABEL_8;
  }
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10081610
// Name: private: void IVP_Contact_Point::friction_force_local_constraint_1d(class IVP_Event_Sim const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Contact_Point::friction_force_local_constraint_1d(
        IVP_Contact_Point *this@<ecx>,
        float a2@<ebp>,
        const IVP_Event_Sim *es)
{
  float *k; // eax
  float v5; // xmm4_4
  float v6; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm4_4
  float v9; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm1_4
  IVP_Core *friction_core; // ecx
  float v13; // xmm4_4
  float v14; // xmm4_4
  float *v15; // edi
  int v16; // eax
  IVP_Core *v17; // ecx
  float hesse_val; // xmm0_4
  float v19; // xmm1_4
  unsigned int i; // esi
  IVP_Core *v21; // edi
  __int16 v22; // ax
  IVP_Contact_Point *v23; // ecx
  IVP_Impact_Solver_Long_Term *tmp_contact_info; // edx
  float v25; // xmm0_4
  float *v26; // eax
  float *v27; // eax
  IVP_U_Float_Point push_core_vec[2]; // [esp+0h] [ebp-110h] BYREF
  IVP_U_Float_Point world_speed[2]; // [esp+20h] [ebp-F0h] BYREF
  IVP_U_Float_Point test_world; // [esp+40h] [ebp-D0h] BYREF
  IVP_U_Float_Point test_trans; // [esp+50h] [ebp-C0h] BYREF
  IVP_U_Float_Point test_rot; // [esp+60h] [ebp-B0h]
  IVP_U_Float_Point translation_vec[2]; // [esp+70h] [ebp-A0h]
  IVP_U_Float_Point rotation_vec[2]; // [esp+90h] [ebp-80h]
  float v35; // [esp+B0h] [ebp-60h]
  float v36; // [esp+B4h] [ebp-5Ch] BYREF
  float v37; // [esp+B8h] [ebp-58h]
  float now_speed_direction; // [esp+BCh] [ebp-54h]
  IVP_Contact_Point *v39; // [esp+D0h] [ebp-40h]
  float v40; // [esp+D4h] [ebp-3Ch]
  float v41; // [esp+D8h] [ebp-38h]
  IVP_Core *v42; // [esp+DCh] [ebp-34h] BYREF
  float *speed_change_on_push; // [esp+E0h] [ebp-30h]
  float maximum_impulse_force; // [esp+E4h] [ebp-2Ch] BYREF
  IVP_Core *core[2]; // [esp+E8h] [ebp-28h]
  IVP_U_Float_Point world_offset_contact; // [esp+F0h] [ebp-20h]
  IVP_Core **v47; // [esp+100h] [ebp-10h]
  float spring_len; // [esp+104h] [ebp-Ch] BYREF
  float sign; // [esp+108h] [ebp-8h]
  float retaddr; // [esp+110h] [ebp+0h]

  spring_len = a2;
  sign = retaddr;
  v39 = this;
  k = this->tmp_contact_info->contact_point_ws.k;
  v5 = k[32];
  v6 = this->span_friction_s[0];
  v7 = k[34] * v6;
  *(float *)core = k[33] * v6;
  v8 = v5 * v6;
  v9 = this->span_friction_s[1];
  maximum_impulse_force = v8;
  core[1] = (IVP_Core *)LODWORD(v7);
  v10 = (float)(k[37] * v9) + *(float *)core;
  v11 = (float)(k[38] * v9) + v7;
  maximum_impulse_force = (float)(v9 * k[36]) + v8;
  core[0] = (IVP_Core *)LODWORD(v10);
  core[1] = (IVP_Core *)LODWORD(v11);
  world_offset_contact.k[2] = IVP_U_Float_Point::real_length_plus_normize(this: (IVP_U_Float_Point *)&maximum_impulse_force);
  if ( *((_BYTE *)&this->IVP_Contact_Point_Fast_Static + 52) == 1 )
    world_offset_contact.k[2] = IVP_Contact_Point::two_values_friction(
                                  this,
                                  a2: (int)&spring_len,
                                  real_world_friction_vec: (IVP_U_Float_Point *)&maximum_impulse_force);
  friction_core = this->synapse[1].l_obj->friction_core;
  v13 = this->now_friction_pressure * this->real_friction_factor;
  v42 = this->synapse[0].l_obj->friction_core;
  v14 = v13 * es->delta_time;
  speed_change_on_push = (float *)friction_core;
  v15 = &push_core_vec[1].k[2];
  v16 = 0;
  v41 = v14;
  v47 = nullptr;
  LODWORD(world_offset_contact.hesse_val) = 160 - (_DWORD)&push_core_vec[1].k[2];
  do
  {
    v17 = *(&v42 + v16);
    if ( (*(_WORD *)&v17->IVP_Core_Fast_Static & 0x12) != 0 )
    {
      v15[1] = 0.0;
      *v15 = 0.0;
      *(v15 - 1) = 0.0;
    }
    else
    {
      IVP_Core::get_surface_speed(
        this: v17,
        point_core: (const IVP_U_Float_Point *)((char *)&this->tmp_contact_info->contact_point_ws
                                  + (unsigned int)v15
                                  + LODWORD(world_offset_contact.hesse_val)),
        speed_world_out: (IVP_U_Float_Point *)(v15 - 1));
      v14 = v41;
      v16 = (int)v47;
    }
    ++v16;
    v15 += 4;
    v47 = (IVP_Core **)v16;
  }
  while ( v16 < 2 );
  v35 = (float)((float)((float)(push_core_vec[1].k[1] - world_speed[0].k[1]) * maximum_impulse_force)
              + (float)((float)(push_core_vec[1].k[2] - world_speed[0].k[2]) * *(float *)core))
      + (float)((float)(push_core_vec[1].hesse_val - world_speed[0].hesse_val) * *(float *)&core[1]);
  hesse_val = 1.0;
  v19 = 0.0;
  v40 = 0.0;
  world_offset_contact.hesse_val = 1.0;
  v47 = &v42;
  for ( i = 0; (int)i < 32; i += 16 )
  {
    v21 = *v47;
    v22 = (__int16)(*v47)->IVP_Core_Fast_Static;
    test_rot.k[i / 4 + 3] = 0.0;
    test_rot.k[i / 4 + 2] = 0.0;
    test_rot.k[i / 4 + 1] = 0.0;
    translation_vec[i / 0x10 + 1].hesse_val = 0.0;
    translation_vec[i / 0x10 + 1].k[2] = 0.0;
    translation_vec[i / 0x10 + 1].k[1] = 0.0;
    if ( (v22 & 0x12) == 0 )
    {
      v36 = maximum_impulse_force * hesse_val;
      v37 = *(float *)core * hesse_val;
      now_speed_direction = *(float *)&core[1] * hesse_val;
      IVP_U_Matrix3::vimult3(
        this: &v21->m_world_f_core_last_psi,
        p_in: (const IVP_U_Float_Point *)&v36,
        p_out: (IVP_U_Float_Point *)((char *)&spring_len + i - 272));
      IVP_Core::test_push_core(
        this: v21,
        point_cs: &v39->tmp_contact_info->contact_point_cs[i / 0x10],
        impulse_in_core: (const IVP_U_Float_Point *)((char *)&spring_len + i - 272),
        impulse_in_world: (const IVP_U_Float_Point *)&v36,
        speed_out: (IVP_U_Float_Point *)&test_world.k[1],
        rot_out: (IVP_U_Float_Point *)&test_trans.k[1]);
      test_rot.k[i / 4 + 1] = test_world.k[1];
      v23 = v39;
      test_rot.k[i / 4 + 2] = test_world.k[2];
      tmp_contact_info = v23->tmp_contact_info;
      test_rot.k[i / 4 + 3] = test_world.hesse_val;
      translation_vec[i / 0x10 + 1].k[1] = test_trans.k[1];
      translation_vec[i / 0x10 + 1].k[2] = test_trans.k[2];
      translation_vec[i / 0x10 + 1].hesse_val = test_trans.hesse_val;
      IVP_Core::get_surface_speed_on_test(
        this: v21,
        point_cs: &tmp_contact_info->contact_point_cs[i / 0x10],
        center_speed_ws: (IVP_U_Float_Point *)&test_world.k[1],
        rot_speed_cs: (IVP_U_Float_Point *)&test_trans.k[1],
        speed_out_ws: (IVP_U_Float_Point *)&world_speed[1].k[1]);
      v14 = v41;
      v19 = (float)((float)((float)(world_speed[1].k[1] * v36) + (float)(world_speed[1].k[2] * v37))
                  + (float)(world_speed[1].hesse_val * now_speed_direction))
          + v40;
      hesse_val = world_offset_contact.hesse_val;
      v40 = v19;
    }
    ++v47;
    hesse_val = hesse_val * -1.0;
    world_offset_contact.hesse_val = hesse_val;
  }
  if ( v19 > 1.0e-10 )
  {
    v25 = (float)((float)(es->delta_time * world_offset_contact.k[2]) - v35) / v19;
    if ( COERCE_FLOAT(LODWORD(v25) & _mask__AbsFloat_) > v14 )
      v25 = v14;
    v26 = (float *)v42;
    if ( (*(_WORD *)&v42->IVP_Core_Fast_Static & 0x12) == 0 )
    {
      v42->speed.k[0] = (float)(test_rot.k[1] * v25) + v42->speed.k[0];
      v26[53] = (float)(test_rot.k[2] * v25) + v26[53];
      v26[54] = (float)(test_rot.hesse_val * v25) + v26[54];
      v26[48] = (float)(translation_vec[1].k[1] * v25) + v26[48];
      v26[49] = (float)(translation_vec[1].k[2] * v25) + v26[49];
      v26[50] = (float)(translation_vec[1].hesse_val * v25) + v26[50];
    }
    v27 = speed_change_on_push;
    if ( (*(_WORD *)speed_change_on_push & 0x12) == 0 )
    {
      speed_change_on_push[52] = (float)(translation_vec[0].k[1] * v25) + speed_change_on_push[52];
      v27[53] = (float)(translation_vec[0].k[2] * v25) + v27[53];
      v27[54] = (float)(translation_vec[0].hesse_val * v25) + v27[54];
      v27[48] = (float)(rotation_vec[0].k[1] * v25) + v27[48];
      v27[49] = (float)(rotation_vec[0].k[2] * v25) + v27[49];
      v27[50] = (float)(rotation_vec[0].hesse_val * v25) + v27[50];
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10081B00
// Name: public: void IVP_Contact_Point::set_friction_to_neutral(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Contact_Point::set_friction_to_neutral(IVP_Contact_Point *this)
{
  this->span_friction_s[0] = 0.0;
  this->span_friction_s[1] = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10081B10
// Name: public: static void IVP_Friction_Solver::ease_two_mindists(class IVP_Contact_Point __near *,class IVP_Contact_Point __near *,class IVP_U_Float_Point __near *,class IVP_U_Float_Point __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __usercall IVP_Friction_Solver::ease_two_mindists(
        int a1@<ebp>,
        IVP_Contact_Point *dist0,
        IVP_Contact_Point *dist1,
        IVP_U_Float_Point *ease_diff_vec0,
        IVP_U_Float_Point *ease_diff_vec1,
        float ease_factor)
{
  float v6; // xmm0_4
  float *k; // eax
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm4_4
  float *v12; // ecx
  float v13; // xmm0_4
  float v14; // xmm3_4
  float v15; // xmm0_4
  float v16; // xmm4_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm7_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm4_4
  float v25; // xmm3_4
  float v26; // xmm5_4
  float v27; // xmm6_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm5_4
  float v32; // xmm0_4
  float v33; // [esp-Ch] [ebp-4Ch]
  float v34; // [esp-8h] [ebp-48h]
  float v35; // [esp-4h] [ebp-44h]
  float v36; // [esp-4h] [ebp-44h]
  float world_vec1_4; // [esp+4h] [ebp-3Ch]
  float world_vec1_8; // [esp+8h] [ebp-38h]
  float world_vec1_8a; // [esp+8h] [ebp-38h]
  float world_vec1_12; // [esp+Ch] [ebp-34h]
  float world_vec1_12a; // [esp+Ch] [ebp-34h]
  IVP_U_Float_Point ease_part0; // [esp+10h] [ebp-30h] BYREF
  float v43; // [esp+30h] [ebp-10h]
  int v44; // [esp+34h] [ebp-Ch]
  void *v45; // [esp+38h] [ebp-8h]
  void *retaddr; // [esp+40h] [ebp+0h]

  v44 = a1;
  v45 = retaddr;
  if ( dist0->synapse[0].l_obj->physical_core == dist1->synapse[0].l_obj->physical_core )
    v6 = 1.0;
  else
    v6 = -1.0;
  k = dist0->tmp_contact_info->contact_point_ws.k;
  v8 = k[32];
  v9 = k[33];
  v10 = k[34];
  v11 = dist0->span_friction_s[1];
  v12 = dist1->tmp_contact_info->contact_point_ws.k;
  v43 = v6;
  v13 = dist0->span_friction_s[0];
  v14 = v10 * v13;
  world_vec1_4 = (float)(k[36] * v11) + (float)(v8 * v13);
  world_vec1_8 = (float)(k[37] * v11) + (float)(v9 * v13);
  v15 = k[38] * v11;
  v16 = dist1->span_friction_s[1];
  world_vec1_12 = v15 + v14;
  v17 = dist1->span_friction_s[0];
  v18 = k[2] - v12[2];
  v33 = (float)(v12[36] * v16) + (float)(v12[32] * v17);
  v34 = (float)(v12[37] * v16) + (float)(v12[33] * v17);
  v35 = (float)(v12[38] * v16) + (float)(v12[34] * v17);
  v19 = k[1] - v12[1];
  ease_part0.k[1] = *k - *v12;
  ease_part0.k[2] = v19;
  ease_part0.hesse_val = v18;
  IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)&ease_part0.k[1]);
  v20 = (float)((float)(ease_part0.k[2] * world_vec1_8) + (float)(ease_part0.k[1] * world_vec1_4))
      + (float)(ease_part0.hesse_val * world_vec1_12);
  v21 = ease_part0.k[1] * v20;
  world_vec1_8a = ease_part0.k[2] * v20;
  world_vec1_12a = ease_part0.hesse_val * v20;
  v22 = (float)((float)((float)(v34 * ease_part0.k[2]) + (float)(ease_part0.k[1] * v33))
              + (float)(ease_part0.hesse_val * v35))
      * v43;
  v23 = (float)((float)(ease_part0.k[2] * v22) + world_vec1_8a) * 0.5;
  v24 = (float)((float)(ease_part0.hesse_val * v22) + world_vec1_12a) * 0.5;
  v36 = ease_part0.hesse_val * v22;
  v25 = (float)((float)(ease_part0.k[1] * v22) + v21) * 0.5;
  v26 = v25 - (float)(ease_part0.k[1] * v22);
  v27 = v23 - (float)(ease_part0.k[2] * v22);
  v28 = (float)((float)(v23 - world_vec1_8a) * ease_factor) + ease_diff_vec0->k[1];
  v29 = (float)((float)(v24 - world_vec1_12a) * ease_factor) + ease_diff_vec0->k[2];
  ease_diff_vec0->k[1] = v28;
  v30 = ease_factor * v43;
  ease_diff_vec0->k[2] = v29;
  ease_diff_vec0->k[0] = ease_diff_vec0->k[0] + (float)((float)(v25 - v21) * ease_factor);
  v31 = (float)(v26 * v30) + ease_diff_vec1->k[0];
  ease_diff_vec1->k[1] = ease_diff_vec1->k[1] + (float)(v27 * v30);
  v32 = ease_diff_vec1->k[2] + (float)((float)(v24 - v36) * v30);
  ease_diff_vec1->k[0] = v31;
  ease_diff_vec1->k[2] = v32;
}

//------------------------------------------------------------------------------
// Address: 0x10081DD0
// Name: private: IVP_Contact_Point::~IVP_Contact_Point(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall IVP_Contact_Point::~IVP_Contact_Point(
        IVP_Contact_Point *this@<ecx>,
        IVP_Contact_Point *a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>)
{
  IVP_Real_Object *l_obj; // eax
  IVP_U_Float_Point *v6; // eax
  IVP_Real_Object *v7; // edi
  const IVP_Compact_Edge *edge; // eax
  IVP_Real_Object *v9; // ecx
  float v10; // xmm0_4
  float v11; // xmm0_4
  IVP_Synapse_Friction *next; // eax
  IVP_Synapse_Friction *prev; // eax
  IVP_Synapse_Friction *v14; // eax
  IVP_Synapse_Friction *v15; // eax
  _DWORD v17[3]; // [esp-Ch] [ebp-7Ch] BYREF
  IVP_Contact_Situation contact_situation; // [esp+0h] [ebp-70h] BYREF
  IVP_Event_Friction v19; // [esp+50h] [ebp-20h] BYREF
  IVP_Event_Friction event_friction; // [esp+5Ch] [ebp-14h]
  IVP_Real_Object *obj1; // [esp+68h] [ebp-8h]
  IVP_Real_Object *retaddr; // [esp+70h] [ebp+0h]

  event_friction.friction_handle = a2;
  obj1 = retaddr;
  l_obj = this->synapse[0].l_obj;
  event_friction.contact_situation = (IVP_Contact_Situation *)l_obj->environment;
  ((void (__thiscall *)(IVP_SurfaceManager *, unsigned int, int, int))l_obj->surface_manager->remove_reference_to_ledge)(
    a1: l_obj->surface_manager,
    a2: ((int)this->synapse[0].edge & 0xFFFFFFF0)
  - 16 * ((*(_DWORD *)((int)this->synapse[0].edge & 0xFFFFFFF0) & 0xFFF) + 1),
    a3,
    a4);
  this->synapse[1].l_obj->surface_manager->remove_reference_to_ledge(
    this: this->synapse[1].l_obj->surface_manager,
    a2: (const IVP_Compact_Ledge *)(((int)this->synapse[1].edge & 0xFFFFFFF0)
                              - 16 * ((*(_DWORD *)((int)this->synapse[1].edge & 0xFFFFFFF0) & 0xFFF) + 1)));
  v6 = (IVP_U_Float_Point *)this->synapse[1].l_obj;
  v7 = this->synapse[0].l_obj;
  v19.environment = (IVP_Environment *)event_friction.contact_situation;
  LODWORD(contact_situation.speed.k[1]) = v7;
  LODWORD(contact_situation.speed.k[2]) = v6;
  memset(&contact_situation.surf_normal.k[1], 0, 12);
  IVP_Contact_Point::get_contact_normal(this, pOut: v6);
  edge = this->synapse[0].edge;
  v9 = (IVP_Real_Object *)this->synapse[1].edge;
  v17[0] = LODWORD(this->last_contact_point_ws.k[0]);
  v10 = this->last_contact_point_ws.k[1];
  LODWORD(contact_situation.speed.hesse_val) = edge;
  *(float *)&v17[1] = v10;
  v11 = this->last_contact_point_ws.k[2];
  contact_situation.objects[0] = v9;
  *(float *)&v17[2] = v11;
  v19.contact_situation = (IVP_Contact_Situation *)v17;
  v19.friction_handle = this;
  IVP_Environment::fire_event_friction_deleted(this: (IVP_Environment *)event_friction.contact_situation, coll: &v19);
  if ( (*(_DWORD *)&v7->flags & 0x2000) != 0 )
    IVP_Cluster_Manager::fire_event_friction_deleted(
      this: (IVP_Cluster_Manager *)LODWORD(event_friction.contact_situation->contact_point_ws.hesse_val),
      real_object: v7,
      event_friction: &v19);
  if ( ((int)event_friction.environment->statistic_manager.l_environment & 0x2000) != 0 )
    IVP_Cluster_Manager::fire_event_friction_deleted(
      this: (IVP_Cluster_Manager *)LODWORD(event_friction.contact_situation->contact_point_ws.hesse_val),
      real_object: (IVP_Real_Object *)event_friction.environment,
      event_friction: &v19);
  next = this->synapse[0].next;
  if ( next != nullptr )
    next->prev = this->synapse[0].prev;
  prev = this->synapse[0].prev;
  if ( prev != nullptr )
    prev->next = this->synapse[0].next;
  else
    this->synapse[0].l_obj->friction_synapses = this->synapse[0].next;
  v14 = this->synapse[1].next;
  if ( v14 != nullptr )
    v14->prev = this->synapse[1].prev;
  v15 = this->synapse[1].prev;
  if ( v15 != nullptr )
    v15->next = this->synapse[1].next;
  else
    this->synapse[1].l_obj->friction_synapses = this->synapse[1].next;
}

//------------------------------------------------------------------------------
// Address: 0x10081F40
// Name: public: static float IVP_Contact_Point_API::get_eliminated_energy(class IVP_Contact_Point __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl IVP_Contact_Point_API::get_eliminated_energy(IVP_Contact_Point *friction_handle)
{
  return friction_handle->integrated_destroyed_energy;
}

//------------------------------------------------------------------------------
// Address: 0x10081F50
// Name: public: static void IVP_Contact_Point_API::reset_eliminated_energy(class IVP_Contact_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Contact_Point_API::reset_eliminated_energy(IVP_Contact_Point *friction_handle)
{
  friction_handle->integrated_destroyed_energy = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10081F60
// Name: public: static float IVP_Contact_Point_API::get_vert_force(class IVP_Contact_Point __near *)
// Source: json
//------------------------------------------------------------------------------
double __cdecl IVP_Contact_Point_API::get_vert_force(IVP_Contact_Point *friction_handle)
{
  return friction_handle->now_friction_pressure;
}

//------------------------------------------------------------------------------
// Address: 0x10081F70
// Name: public: static void IVP_Contact_Point_API::get_surface_normal_ws(class IVP_Contact_Point __near *,class IVP_U_Float_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Contact_Point_API::get_surface_normal_ws(IVP_Contact_Point *friction_handle, IVP_U_Float_Point *pOut)
{
  IVP_Contact_Point::get_contact_normal(this: friction_handle, pOut);
}

//------------------------------------------------------------------------------
// Address: 0x10081F90
// Name: public: class IVP_Core __near * IVP_Core::union_find_get_father(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Core *__thiscall IVP_Core::union_find_get_father(IVP_Core *this)
{
  IVP_Core *result; // eax

  if ( this == nullptr )
    return nullptr;
  do
  {
    result = this;
    this = this->tmp.union_find_father;
  }
  while ( this != nullptr );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10081FB0
// Name: public: void IVP_Mutual_Energizer::init_mutual_energizer(class IVP_Core __near *,class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Mutual_Energizer::init_mutual_energizer(
        IVP_Mutual_Energizer *this@<ecx>,
        int a2@<ebp>,
        IVP_Core *core0,
        IVP_Core *core1)
{
  IVP_Core *v4; // eax
  IVP_Core *v6; // ecx
  float v7; // xmm0_4
  float v8; // xmm1_4
  IVP_Core *v9; // ecx
  IVP_Core *v10; // eax
  long double v11; // st7
  float v12; // xmm0_4
  IVP_Core *v13; // eax
  long double v14; // st7
  float v15; // xmm0_4
  IVP_Core *v16; // eax
  double hesse_val; // st7
  IVP_Core *v18; // eax
  float v19; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  IVP_U_Float_Point v22; // [esp-1Ch] [ebp-5Ch] BYREF
  float v23[3]; // [esp-Ch] [ebp-4Ch] BYREF
  IVP_U_Float_Point rot0_world; // [esp+0h] [ebp-40h] BYREF
  IVP_U_Float_Point rot1_world; // [esp+10h] [ebp-30h] BYREF
  float v26; // [esp+30h] [ebp-10h]
  int v27; // [esp+34h] [ebp-Ch]
  void *v28; // [esp+38h] [ebp-8h]
  void *retaddr; // [esp+40h] [ebp+0h]

  v27 = a2;
  v28 = retaddr;
  v4 = core1;
  if ( (*(_WORD *)&core1->IVP_Core_Fast_Static & 0x12) != 0 )
  {
    this->core[1] = core0;
  }
  else
  {
    this->core[1] = core1;
    v4 = core0;
  }
  v6 = this->core[1];
  this->core[0] = v4;
  v7 = v6->speed.k[1] - v4->speed.k[1];
  v8 = v6->speed.k[2] - v4->speed.k[2];
  this->trans_vec_world.k[0] = v6->speed.k[0] - v4->speed.k[0];
  this->trans_vec_world.k[1] = v7;
  this->trans_vec_world.k[2] = v8;
  this->trans_speed_potential = IVP_U_Float_Point::real_length_plus_normize(this: &this->trans_vec_world);
  IVP_U_Matrix3::vmult3(
    this: &this->core[0]->m_world_f_core_last_psi,
    p_in: &this->core[0]->rot_speed,
    p_out: (IVP_U_Float_Point *)v23);
  IVP_U_Matrix3::vmult3(
    this: &this->core[1]->m_world_f_core_last_psi,
    p_in: &this->core[1]->rot_speed,
    p_out: (IVP_U_Float_Point *)&rot0_world.k[1]);
  rot1_world.k[1] = rot0_world.k[1] - v23[0];
  rot1_world.k[2] = rot0_world.k[2] - v23[1];
  rot1_world.hesse_val = rot0_world.hesse_val - v23[2];
  this->rot_speed_potential = IVP_U_Float_Point::real_length_plus_normize(this: (IVP_U_Float_Point *)&rot1_world.k[1]);
  IVP_U_Matrix3::vimult3(
    this: &this->core[0]->m_world_f_core_last_psi,
    p_in: (IVP_U_Float_Point *)&rot1_world.k[1],
    p_out: this->rot_vec_obj);
  v9 = this->core[1];
  rot1_world.k[1] = rot1_world.k[1] * -1.0;
  rot1_world.k[2] = rot1_world.k[2] * -1.0;
  rot1_world.hesse_val = rot1_world.hesse_val * -1.0;
  IVP_U_Matrix3::vimult3(
    this: &v9->m_world_f_core_last_psi,
    p_in: (IVP_U_Float_Point *)&rot1_world.k[1],
    p_out: &this->rot_vec_obj[1]);
  v10 = this->core[0];
  v22.k[0] = this->rot_vec_obj[0].k[0] * v10->rot_inertia.k[0];
  v22.k[1] = this->rot_vec_obj[0].k[1] * v10->rot_inertia.k[1];
  v22.k[2] = this->rot_vec_obj[0].k[2] * v10->rot_inertia.k[2];
  v11 = IVP_U_Float_Point::fast_real_length(this: &v22);
  v26 = v11;
  this->rot_inertia[0] = v11;
  v12 = 1.0;
  if ( v11 >= 1.0e-10 )
    v12 = 1.0 / v26;
  else
    this->rot_inertia[0] = 1.0;
  this->inv_rot_inertia[0] = v12;
  v13 = this->core[1];
  v22.k[0] = this->rot_vec_obj[1].k[0] * v13->rot_inertia.k[0];
  v22.k[1] = this->rot_vec_obj[1].k[1] * v13->rot_inertia.k[1];
  v22.k[2] = this->rot_vec_obj[1].k[2] * v13->rot_inertia.k[2];
  v14 = IVP_U_Float_Point::fast_real_length(this: &v22);
  v26 = v14;
  v15 = 1.0;
  this->rot_inertia[1] = v14;
  if ( v14 >= 1.0e-10 )
    v15 = 1.0 / v26;
  else
    this->rot_inertia[1] = 1.0;
  this->inv_rot_inertia[1] = v15;
  v16 = this->core[1];
  this->trans_inertia[1] = v16->rot_inertia.hesse_val;
  hesse_val = v16->inv_rot_inertia.hesse_val;
  v18 = this->core[0];
  this->inv_trans_inertia[1] = hesse_val;
  if ( (*(_WORD *)&v18->IVP_Core_Fast_Static & 0x12) != 0 )
  {
    v19 = this->trans_inertia[1] * 10000.0;
    v20 = this->inv_rot_inertia[1] * 0.000099999997;
    this->inv_trans_inertia[0] = this->inv_trans_inertia[1] * 0.000099999997;
    v21 = this->rot_inertia[1] * 10000.0;
    this->trans_inertia[0] = v19;
    this->rot_inertia[0] = v21;
    this->inv_rot_inertia[0] = v20;
  }
  else
  {
    this->trans_inertia[0] = v18->rot_inertia.hesse_val;
    this->inv_trans_inertia[0] = v18->inv_rot_inertia.hesse_val;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10082240
// Name: public: void IVP_Mutual_Energizer::destroy_percent_energy(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Mutual_Energizer::destroy_percent_energy(
        IVP_Mutual_Energizer *this,
        float percent_energy_to_destroy)
{
  float v2; // xmm1_4
  IVP_Core *v3; // eax
  float v4; // xmm5_4
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm3_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm4_4
  IVP_Core *v11; // eax
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  IVP_Core *v18; // eax
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm0_4
  IVP_Core *v22; // eax
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm2_4

  v2 = this->inv_rot_inertia[0] + this->inv_rot_inertia[1];
  v3 = this->core[0];
  v4 = (float)(this->rot_speed_potential
             - fsqrt(
                 COERCE_FLOAT(
                   COERCE_UNSIGNED_INT(
                     (float)(this->rot_speed_potential * this->rot_speed_potential)
                   - (float)((float)((float)(this->rot_energy_potential * percent_energy_to_destroy) * 2.0) * v2))
                 & _mask__AbsFloat_)))
     * (float)(1.0 / v2);
  v5 = this->inv_trans_inertia[0] + this->inv_trans_inertia[1];
  v6 = (float)(this->trans_speed_potential
             - fsqrt(
                 COERCE_FLOAT(
                   COERCE_UNSIGNED_INT(
                     (float)(this->trans_speed_potential * this->trans_speed_potential)
                   - (float)((float)((float)(this->trans_energy_potential * percent_energy_to_destroy) * 2.0) * v5))
                 & _mask__AbsFloat_)))
     * (float)(1.0 / v5);
  v7 = v6;
  if ( (*(_WORD *)&v3->IVP_Core_Fast_Static & 0x12) == 0 )
  {
    v8 = this->trans_vec_world.k[2];
    v9 = this->trans_vec_world.k[0];
    v10 = this->inv_trans_inertia[0] * v6;
    v3->speed_change.k[1] = (float)(this->trans_vec_world.k[1] * v10) + v3->speed_change.k[1];
    v3->speed_change.k[2] = (float)(v8 * v10) + v3->speed_change.k[2];
    v3->speed_change.k[0] = (float)(v9 * v10) + v3->speed_change.k[0];
    v11 = this->core[0];
    v12 = this->inv_rot_inertia[0] * v4;
    v13 = (float)(this->rot_vec_obj[0].k[1] * v12) + v11->rot_speed_change.k[1];
    v14 = (float)(this->rot_vec_obj[0].k[2] * v12) + v11->rot_speed_change.k[2];
    v11->rot_speed_change.k[0] = (float)(v12 * this->rot_vec_obj[0].k[0]) + v11->rot_speed_change.k[0];
    v11->rot_speed_change.k[1] = v13;
    v11->rot_speed_change.k[2] = v14;
  }
  v15 = v7 * this->inv_trans_inertia[1];
  v16 = this->trans_vec_world.k[0];
  v17 = this->trans_vec_world.k[2];
  v18 = this->core[1];
  v19 = this->trans_vec_world.k[1] * -1.0;
  this->trans_vec_world.k[1] = v19;
  v20 = v17 * -1.0;
  this->trans_vec_world.k[2] = v20;
  v21 = v16 * -1.0;
  this->trans_vec_world.k[0] = v21;
  v18->speed_change.k[1] = (float)(v19 * v15) + v18->speed_change.k[1];
  v18->speed_change.k[2] = (float)(v20 * v15) + v18->speed_change.k[2];
  v18->speed_change.k[0] = (float)(v21 * v15) + v18->speed_change.k[0];
  v22 = this->core[1];
  v23 = this->inv_rot_inertia[1] * v4;
  v24 = (float)(this->rot_vec_obj[1].k[1] * v23) + v22->rot_speed_change.k[1];
  v25 = (float)(this->rot_vec_obj[1].k[2] * v23) + v22->rot_speed_change.k[2];
  v22->rot_speed_change.k[0] = (float)(this->rot_vec_obj[1].k[0] * v23) + v22->rot_speed_change.k[0];
  v22->rot_speed_change.k[1] = v24;
  v22->rot_speed_change.k[2] = v25;
}

//------------------------------------------------------------------------------
// Address: 0x10082470
// Name: private: void IVP_Contact_Point::calc_virtual_mass_of_mindist(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Contact_Point::calc_virtual_mass_of_mindist(IVP_Contact_Point *this)
{
  IVP_Core *physical_core; // eax
  IVP_Core *v3; // esi
  __int16 v4; // cx
  int v5; // esi
  int v6; // edi
  float v7; // xmm0_4
  double v8; // st7
  float vmass_no_dir[2]; // [esp+8h] [ebp-18h]
  IVP_Core *core[2]; // [esp+10h] [ebp-10h]
  IVP_Material *virt_mass_mindist_no_dir; // [esp+18h] [ebp-8h] BYREF
  float v12; // [esp+1Ch] [ebp-4h]

  IVP_Contact_Point::get_material_info(this, mtl: &virt_mass_mindist_no_dir);
  if ( virt_mass_mindist_no_dir->second_friction_x_enabled != IVP_FALSE || *(_DWORD *)(LODWORD(v12) + 8) != 0 )
    *((_BYTE *)&this->IVP_Contact_Point_Fast_Static + 52) = 1;
  physical_core = this->synapse[0].l_obj->physical_core;
  v3 = this->synapse[1].l_obj->physical_core;
  v4 = (__int16)physical_core->IVP_Core_Fast_Static;
  core[0] = physical_core;
  core[1] = v3;
  if ( (v4 & 0x12) != 0 )
  {
    v8 = IVP_Core::calc_virt_mass_worst_case(this: v3, core_point: &this->tmp_contact_info->contact_point_cs[1]);
    goto LABEL_11;
  }
  if ( (*(_WORD *)&v3->IVP_Core_Fast_Static & 0x12) != 0 )
  {
    v8 = IVP_Core::calc_virt_mass_worst_case(this: physical_core, core_point: this->tmp_contact_info->contact_point_cs);
LABEL_11:
    v12 = v8;
    v7 = v12;
    goto LABEL_12;
  }
  v5 = 160;
  v6 = 0;
  do
  {
    vmass_no_dir[v6] = IVP_Core::calc_virt_mass_worst_case(
                         this: core[v6],
                         core_point: (const IVP_U_Float_Point *)((char *)&this->tmp_contact_info->contact_point_ws + v5));
    v5 += 16;
    ++v6;
  }
  while ( v5 < 192 );
  v7 = (float)(vmass_no_dir[1] * vmass_no_dir[0]) / (float)(vmass_no_dir[1] + vmass_no_dir[0]);
LABEL_12:
  this->inv_virt_mass_mindist_no_dir = 1.0 / v7;
}

//------------------------------------------------------------------------------
// Address: 0x10082550
// Name: public: virtual float IVP_Friction_System::get_minimum_simulation_frequency(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall IVP_Friction_System::get_minimum_simulation_frequency(IVP_Friction_Sys_Static *this)
{
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10082570
// Name: public: int IVP_Synapse_Friction::get_material_index(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_Synapse_Friction::get_material_index(IVP_Synapse_Friction *this)
{
  return *(_BYTE *)(((int)this->edge & 0xFFFFFFF0) + 3) & 0x7F;
}

//------------------------------------------------------------------------------
// Address: 0x10082580
// Name: public: enum IVP_BOOL IVP_Synapse_Friction::is_same_as(class IVP_Synapse_Real const __near *)const
// Source: json
//------------------------------------------------------------------------------
IVP_BOOL __thiscall IVP_Synapse_Friction::is_same_as(IVP_Synapse_Friction *this, const IVP_Synapse_Real *syn1)
{
  const IVP_Compact_Edge *edge; // edx
  const IVP_Compact_Edge *v3; // esi
  IVP_BOOL result; // eax
  const IVP_Compact_Edge *v5; // ecx
  const IVP_Compact_Edge *v6; // esi

  if ( this->status != syn1->status )
    return IVP_FALSE;
  switch ( this->status )
  {
    case 0:
      edge = this->edge;
      v3 = syn1->edge;
      if ( ((unsigned int)edge & 0xFFFFFFF0) - 16 * (*(_DWORD *)((unsigned int)edge & 0xFFFFFFF0) & 0xFFF) - 16 != ((unsigned int)v3 & 0xFFFFFFF0) - 16 * (*(_DWORD *)((unsigned int)v3 & 0xFFFFFFF0) & 0xFFF) - 16 )
        return IVP_FALSE;
      return (unsigned __int16)(*(_WORD *)v3 ^ *(_WORD *)edge) == 0;
    case 1:
      v5 = this->edge;
      v6 = syn1->edge;
      if ( v5 != v6 && &v5[(2 * *(_DWORD *)v5) >> 17] != v6 )
        return IVP_FALSE;
      goto $LN3_8;
    case 2:
      return (((int)this->edge ^ (int)syn1->edge) & 0xFFFFFFF0) == 0;
    case 3:
$LN3_8:
      result = IVP_TRUE;
      break;
    default:
      _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_intern\\ivp_friction.cxx", 2314);
      return IVP_FALSE;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10082660
// Name: private: enum IVP_BOOL IVP_Contact_Point::is_same_as(class IVP_Mindist const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall IVP_Contact_Point::is_same_as(IVP_Contact_Point *this, const IVP_Synapse_Real *md2)
{
  IVP_Synapse_Friction *synapse; // edi
  IVP_Synapse_Friction *v3; // ebx
  const IVP_Synapse_Real *p_mindist_offset; // esi
  IVP_Synapse *v5; // eax
  const IVP_Synapse_Real *sy11; // [esp+14h] [ebp+8h]

  synapse = this->synapse;
  v3 = &this->synapse[1];
  p_mindist_offset = (const IVP_Synapse_Real *)&md2->mindist_offset;
  v5 = (IVP_Synapse *)&md2[1].mindist_offset;
  sy11 = (const IVP_Synapse_Real *)((char *)md2 + 52);
  if ( this->synapse[0].l_obj == p_mindist_offset->l_obj && this->synapse[1].l_obj == v5->l_obj )
  {
    if ( IVP_Synapse_Friction::is_same_as(this: synapse, syn1: p_mindist_offset) != IVP_FALSE
      && IVP_Synapse_Friction::is_same_as(this: v3, syn1: sy11) != IVP_FALSE )
    {
      return true;
    }
    v5 = &sy11->IVP_Synapse;
  }
  return v3->l_obj == p_mindist_offset->l_obj
      && synapse->l_obj == v5->l_obj
      && IVP_Synapse_Friction::is_same_as(this: v3, syn1: p_mindist_offset) != IVP_FALSE
      && IVP_Synapse_Friction::is_same_as(this: synapse, syn1: sy11) != IVP_FALSE;
}

//------------------------------------------------------------------------------
// Address: 0x100826F0
// Name: public: IVP_Contact_Point::IVP_Contact_Point(class IVP_Mindist __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
IVP_Contact_Point *__userpurge IVP_Contact_Point::IVP_Contact_Point@<eax>(
        IVP_Contact_Point *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        IVP_Mindist *md)
{
  IVP_Real_Object *l_obj; // edx
  IVP_Synapse *v8; // ecx
  float v9; // eax
  IVP_Synapse_Friction *synapse; // eax
  IVP_Synapse_Friction *friction_synapses; // edx
  IVP_Synapse *v12; // edi
  IVP_Real_Object *v13; // edx
  float v14; // eax
  IVP_Synapse_Friction *v15; // eax
  IVP_Synapse_Friction *v16; // edx
  const IVP_Compact_Edge *edge; // eax
  void (__thiscall *add_reference_to_ledge)(IVP_SurfaceManager *, const IVP_Compact_Ledge *); // edx
  float friction_dist; // xmm1_4
  _BYTE v23[12]; // [esp-Ch] [ebp-2Ch] BYREF
  IVP_U_Point wHesse_vecF_Fos; // [esp+0h] [ebp-20h]
  IVP_Real_Object *v25; // [esp+10h] [ebp-10h]
  int v26; // [esp+14h] [ebp-Ch]
  void *v27; // [esp+18h] [ebp-8h]
  void *retaddr; // [esp+20h] [ebp+0h]

  v26 = a2;
  v27 = retaddr;
  l_obj = md->synapse[(*((_DWORD *)&md->IVP_Mindist_Base + 5) >> 8) & 3].l_obj;
  v8 = &md->synapse[(*((_DWORD *)&md->IVP_Mindist_Base + 5) >> 8) & 3];
  LODWORD(wHesse_vecF_Fos.hesse_val) = md->synapse[(*((_DWORD *)&md->IVP_Mindist_Base + 5) >> 8) & 3].status;
  v9 = *(float *)&v8->edge;
  v25 = l_obj;
  wHesse_vecF_Fos.k[2] = v9;
  synapse = this->synapse;
  this->synapse[0].l_obj = l_obj;
  this->synapse[0].contact_point_offset = -8;
  friction_synapses = v25->friction_synapses;
  this->synapse[0].next = friction_synapses;
  this->synapse[0].prev = nullptr;
  if ( friction_synapses != nullptr )
    friction_synapses->prev = synapse;
  v25->friction_synapses = synapse;
  this->synapse[0].status = LOWORD(wHesse_vecF_Fos.hesse_val);
  this->synapse[0].edge = (const IVP_Compact_Edge *)LODWORD(wHesse_vecF_Fos.k[2]);
  v12 = &md->synapse[((*((_DWORD *)&md->IVP_Mindist_Base + 5) ^ 0x100u) >> 8) & 3];
  v13 = md->synapse[((*((_DWORD *)&md->IVP_Mindist_Base + 5) ^ 0x100u) >> 8) & 3].l_obj;
  LODWORD(wHesse_vecF_Fos.k[2]) = md->synapse[((*((_DWORD *)&md->IVP_Mindist_Base + 5) ^ 0x100u) >> 8) & 3].status;
  v14 = *(float *)&v12->edge;
  v25 = v13;
  wHesse_vecF_Fos.hesse_val = v14;
  v15 = &this->synapse[1];
  this->synapse[1].l_obj = v13;
  this->synapse[1].contact_point_offset = -28;
  v16 = v25->friction_synapses;
  this->synapse[1].next = v16;
  this->synapse[1].prev = nullptr;
  if ( v16 != nullptr )
    v16->prev = v15;
  v25->friction_synapses = v15;
  this->synapse[1].status = LOWORD(wHesse_vecF_Fos.k[2]);
  this->synapse[1].edge = (const IVP_Compact_Edge *)LODWORD(wHesse_vecF_Fos.hesse_val);
  ((void (__thiscall *)(IVP_SurfaceManager *, unsigned int, int, int))v8->l_obj->surface_manager->add_reference_to_ledge)(
    a1: v8->l_obj->surface_manager,
    a2: ((int)v8->edge & 0xFFFFFFF0) - 16 * ((*(_DWORD *)((int)v8->edge & 0xFFFFFFF0) & 0xFFF) + 1),
    a3,
    a4);
  edge = v12->edge;
  add_reference_to_ledge = v12->l_obj->surface_manager->add_reference_to_ledge;
  LODWORD(wHesse_vecF_Fos.k[2]) = v12->l_obj->surface_manager;
  add_reference_to_ledge(
    this: (IVP_SurfaceManager *)LODWORD(wHesse_vecF_Fos.k[2]),
    a2: (const IVP_Compact_Ledge *)(((unsigned int)edge & 0xFFFFFFF0)
                              - 16 * ((*(_DWORD *)((unsigned int)edge & 0xFFFFFFF0) & 0xFFF) + 1)));
  this->last_time_of_recalc_friction_s_vals = md->synapse[0].l_obj->environment->current_time;
  if ( v12->status == 2 )
  {
    IVP_Compact_Ledge_Solver::calc_hesse_vec_object_not_normized(
      edge: v12->edge,
      ledge: (const IVP_Compact_Ledge *)(((int)v12->edge & 0xFFFFFFF0)
                                - 16 * ((*(_DWORD *)((int)v12->edge & 0xFFFFFFF0) & 0xFFF) + 1)),
      out_vec: (IVP_U_Float_Point *)v23);
    this->inv_triangle_det = 1.0 / (IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Point *)v23) + 1.0e-18);
  }
  this->old_energy_dynamic_fr = 0.0;
  this->now_friction_pressure = 0.0;
  this->integrated_destroyed_energy = 0.0;
  *((_BYTE *)&this->IVP_Contact_Point_Fast + 93) = 1;
  this->span_friction_s[0] = 0.0;
  this->span_friction_s[1] = 0.0;
  friction_dist = ivp_mindist_settings.friction_dist;
  *((_WORD *)&this->IVP_Contact_Point_Fast + 47) = 0;
  this->l_friction_system = nullptr;
  *((_BYTE *)&this->IVP_Contact_Point_Fast_Static + 52) = 0;
  this->last_gap_len = friction_dist;
  *((_BYTE *)&this->IVP_Contact_Point_Fast + 92) = 20;
  *(_QWORD *)&this->last_contact_point_ws.k[1] = 0;
  this->last_contact_point_ws.k[0] = 0.0;
  this->last_contact_point_ws.hesse_val = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100828F0
// Name: public: float IVP_Friction_Core_Pair::get_sum_slide_way(class IVP_Event_Sim const __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall IVP_Friction_Core_Pair::get_sum_slide_way(IVP_Friction_Core_Pair *this, const IVP_Event_Sim *es)
{
  float v2; // xmm1_4
  int v3; // esi
  int v4; // edi
  void **v5; // eax
  float *v6; // edx
  float v7; // xmm0_4
  void **v8; // ecx
  float v9; // xmm0_4
  float sum; // [esp+0h] [ebp-4h]

  v2 = 0.0;
  v3 = this->fr_dists.n_elems - 1;
  sum = 0.0;
  if ( this->fr_dists.n_elems != 0 )
  {
    if ( this->fr_dists.n_elems >= 4u )
    {
      v4 = this->fr_dists.n_elems >> 2;
      v5 = &this->fr_dists.elems[v3 - 2];
      v3 -= 4 * v4;
      do
      {
        v6 = (float *)*(v5 - 1);
        v7 = (float)((float)(*((float *)*v5 + 21) * *((float *)*v5 + 17)) * *((float *)*v5 + 12))
           + (float)((float)((float)(*((float *)v5[1] + 21) * *((float *)v5[1] + 17)) * *((float *)v5[1] + 12))
                   + (float)((float)((float)(*((float *)v5[2] + 21) * *((float *)v5[2] + 17)) * *((float *)v5[2] + 12))
                           + v2));
        v5 -= 4;
        --v4;
        v2 = (float)((float)(v6[21] * v6[17]) * v6[12]) + v7;
      }
      while ( v4 != 0 );
      sum = (float)((float)(v6[21] * v6[17]) * v6[12]) + v7;
    }
    if ( v3 >= 0 )
    {
      v8 = &this->fr_dists.elems[v3];
      do
      {
        v9 = (float)(*((float *)*v8 + 21) * *((float *)*v8 + 17)) * *((float *)*v8 + 12);
        --v8;
        --v3;
        v2 = v2 + v9;
      }
      while ( v3 >= 0 );
      sum = v2;
    }
  }
  return es->delta_time * (sum * es->delta_time);
}

//------------------------------------------------------------------------------
// Address: 0x100829D0
// Name: public: int IVP_Friction_Core_Pair::number_of_pair_dists(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_Friction_Core_Pair::number_of_pair_dists(IVP_Friction_Core_Pair *this)
{
  return this->fr_dists.n_elems;
}

//------------------------------------------------------------------------------
// Address: 0x100829E0
// Name: public: class IVP_Friction_Core_Pair __near * IVP_Friction_System::get_pair_info_for_objs(class IVP_Core __near *,class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Friction_Core_Pair *__thiscall IVP_Friction_System::get_pair_info_for_objs(
        IVP_Friction_System *this,
        IVP_Core *core0,
        IVP_Core *core1)
{
  int v3; // edx
  void **i; // esi
  IVP_Friction_Core_Pair *result; // eax
  IVP_Core *v6; // ecx

  v3 = this->fr_pairs_of_objs.n_elems - 1;
  if ( this->fr_pairs_of_objs.n_elems == 0 )
    return nullptr;
  for ( i = &this->fr_pairs_of_objs.elems[v3]; ; --i )
  {
    result = (IVP_Friction_Core_Pair *)*i;
    v6 = *((IVP_Core **)*i + 13);
    if ( (v6 == core0 || result->objs[1] == core0) && (v6 == core1 || result->objs[1] == core1) )
      break;
    if ( --v3 < 0 )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10082A30
// Name: public: class IVP_Core __near * IVP_Friction_System::union_find_fr_sys(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Core *__thiscall IVP_Friction_System::union_find_fr_sys(IVP_Friction_System *this)
{
  int v2; // eax
  int v3; // ecx
  _DWORD *v4; // eax
  int v5; // edx
  int v6; // eax
  int v7; // esi
  int v8; // edx
  int n_elems; // eax
  int v10; // esi
  void **v11; // ecx
  IVP_Core *union_find_father; // edx
  IVP_Core *v13; // edi
  int v14; // esi
  void **v15; // edi
  IVP_Core *v16; // ecx
  IVP_Core *v17; // edx
  IVP_Core *first_father; // [esp+Ch] [ebp-8h]
  IVP_Core *second_father; // [esp+10h] [ebp-4h]

  v2 = this->cores_of_friction_system.n_elems - 1;
  if ( this->cores_of_friction_system.n_elems != 0 )
  {
    do
      *((_DWORD *)this->cores_of_friction_system.elems[v2--] + 106) = 0;
    while ( v2 >= 0 );
  }
  v3 = this->fr_pairs_of_objs.n_elems - 1;
  if ( this->fr_pairs_of_objs.n_elems != 0 )
  {
    do
    {
      v4 = this->fr_pairs_of_objs.elems[v3];
      v5 = v4[13];
      v6 = v4[14];
      if ( (*(_BYTE *)v5 & 2) == 0 && (*(_BYTE *)v6 & 2) == 0 )
      {
        do
        {
          v7 = v5;
          v5 = *(_DWORD *)(v5 + 424);
        }
        while ( v5 != 0 );
        do
        {
          v8 = v6;
          v6 = *(_DWORD *)(v6 + 424);
        }
        while ( v6 != 0 );
        if ( v7 != v8 )
          *(_DWORD *)(v8 + 424) = v7;
      }
      --v3;
    }
    while ( v3 >= 0 );
  }
  n_elems = this->cores_of_friction_system.n_elems;
  v10 = n_elems - 1;
  first_father = nullptr;
  second_father = nullptr;
  if ( this->cores_of_friction_system.n_elems != 0 )
  {
    v11 = &this->cores_of_friction_system.elems[v10];
    do
    {
      union_find_father = (IVP_Core *)*v11;
      if ( (*(_BYTE *)*v11 & 2) == 0 )
      {
        do
        {
          v13 = union_find_father;
          union_find_father = union_find_father->tmp.union_find_father;
        }
        while ( union_find_father != nullptr );
        first_father = v13;
      }
      --v11;
      --v10;
    }
    while ( v10 >= 0 );
  }
  v14 = n_elems - 1;
  if ( n_elems - 1 >= 0 )
  {
    v15 = &this->cores_of_friction_system.elems[v14];
    do
    {
      v16 = (IVP_Core *)*v15;
      if ( (*(_BYTE *)*v15 & 2) == 0 )
      {
        do
        {
          v17 = v16;
          v16 = v16->tmp.union_find_father;
        }
        while ( v16 != nullptr );
        if ( v17 != first_father )
          second_father = v17;
      }
      --v15;
      --v14;
    }
    while ( v14 >= 0 );
  }
  return second_father;
}

//------------------------------------------------------------------------------
// Address: 0x10082B30
// Name: public: virtual void IVP_Friction_System::reset_time(class IVP_Time)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Friction_System::reset_time(IVP_Friction_System *this, IVP_Time offset)
{
  int v2; // ebx
  _DWORD *v3; // edi
  int v4; // esi
  IVP_Friction_System *v5; // [esp+4h] [ebp-4h]

  v2 = this->fr_pairs_of_objs.n_elems - 1;
  v5 = this;
  if ( this->fr_pairs_of_objs.n_elems != 0 )
  {
    do
    {
      v3 = this->fr_pairs_of_objs.elems[v2];
      v4 = *((unsigned __int16 *)v3 + 1) - 1;
      if ( *((_WORD *)v3 + 1) != 0 )
      {
        do
          IVP_Contact_Point::reset_time(this: *(IVP_Contact_Point **)(v3[1] + 4 * v4--), offset);
        while ( v4 >= 0 );
        this = v5;
      }
      --v2;
    }
    while ( v2 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10082B80
// Name: public: void IVP_Friction_System::clear_integrated_anti_energy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Friction_System::clear_integrated_anti_energy(IVP_Friction_System *this)
{
  int v1; // eax
  _DWORD *v2; // edx

  v1 = this->fr_pairs_of_objs.n_elems - 1;
  if ( this->fr_pairs_of_objs.n_elems != 0 )
  {
    if ( this->fr_pairs_of_objs.n_elems >= 4u )
    {
      do
      {
        *((_DWORD *)this->fr_pairs_of_objs.elems[v1] + 12) = 0;
        *((_DWORD *)this->fr_pairs_of_objs.elems[v1 - 1] + 12) = 0;
        *((_DWORD *)this->fr_pairs_of_objs.elems[v1 - 2] + 12) = 0;
        v2 = this->fr_pairs_of_objs.elems[v1 - 3];
        v1 -= 4;
        v2[12] = 0;
      }
      while ( v1 >= 3 );
    }
    for ( ; v1 >= 0; *((_DWORD *)this->fr_pairs_of_objs.elems[v1 + 1] + 12) = 0 )
      --v1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10082BE0
// Name: private: float IVP_Friction_Core_Pair::destroy_mutual_energy(float)
// Source: json
//------------------------------------------------------------------------------
double __userpurge IVP_Friction_Core_Pair::destroy_mutual_energy@<st0>(
        IVP_Friction_Core_Pair *this@<ecx>,
        IVP_Core *a2@<ebp>,
        float d_e)
{
  float v3; // xmm0_4
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm1_4
  _BYTE v8[12]; // [esp+4h] [ebp-7Ch] BYREF
  IVP_Mutual_Energizer mutual_energizer_stack; // [esp+10h] [ebp-70h] BYREF
  float retaddr; // [esp+80h] [ebp+0h]

  mutual_energizer_stack.core[1] = a2;
  mutual_energizer_stack.whole_mutual_energy = retaddr;
  IVP_Mutual_Energizer::init_mutual_energizer(
    this: (IVP_Mutual_Energizer *)v8,
    a2: (int)&mutual_energizer_stack.core[1],
    core0: this->objs[0],
    core1: this->objs[1]);
  v3 = (float)((float)((float)(mutual_energizer_stack.inv_trans_inertia[1] * mutual_energizer_stack.trans_inertia[1])
                     * mutual_energizer_stack.trans_inertia[1])
             + 1.0e-10)
     - (float)((float)((float)(mutual_energizer_stack.inv_trans_inertia[0]
                             * (float)(mutual_energizer_stack.rot_speed_potential
                                     * (float)(mutual_energizer_stack.trans_inertia[1]
                                             / (float)(mutual_energizer_stack.rot_inertia[0]
                                                     + mutual_energizer_stack.rot_speed_potential))))
                     * (float)(mutual_energizer_stack.rot_speed_potential
                             * (float)(mutual_energizer_stack.trans_inertia[1]
                                     / (float)(mutual_energizer_stack.rot_inertia[0]
                                             + mutual_energizer_stack.rot_speed_potential))))
             + (float)((float)(mutual_energizer_stack.inv_trans_inertia[1]
                             * (float)(mutual_energizer_stack.trans_inertia[1]
                                     - (float)(mutual_energizer_stack.rot_inertia[0]
                                             * (float)(mutual_energizer_stack.trans_inertia[1]
                                                     / (float)(mutual_energizer_stack.rot_inertia[0]
                                                             + mutual_energizer_stack.rot_speed_potential)))))
                     * (float)(mutual_energizer_stack.trans_inertia[1]
                             - (float)(mutual_energizer_stack.rot_inertia[0]
                                     * (float)(mutual_energizer_stack.trans_inertia[1]
                                             / (float)(mutual_energizer_stack.rot_inertia[0]
                                                     + mutual_energizer_stack.rot_speed_potential))))));
  if ( v3 < 0.0 )
    v3 = 0.0;
  mutual_energizer_stack.rot_inertia[1] = v3 * 0.5;
  v4 = (float)((float)((float)(mutual_energizer_stack.rot_vec_obj[1].hesse_val
                             * mutual_energizer_stack.rot_vec_obj[1].k[1])
                     * mutual_energizer_stack.rot_vec_obj[1].k[1])
             + 1.0e-10)
     - (float)((float)((float)(mutual_energizer_stack.rot_vec_obj[1].k[2]
                             * (float)(mutual_energizer_stack.trans_speed_potential
                                     * (float)(mutual_energizer_stack.rot_vec_obj[1].k[1]
                                             / (float)(mutual_energizer_stack.trans_inertia[0]
                                                     + mutual_energizer_stack.trans_speed_potential))))
                     * (float)(mutual_energizer_stack.trans_speed_potential
                             * (float)(mutual_energizer_stack.rot_vec_obj[1].k[1]
                                     / (float)(mutual_energizer_stack.trans_inertia[0]
                                             + mutual_energizer_stack.trans_speed_potential))))
             + (float)((float)(mutual_energizer_stack.rot_vec_obj[1].hesse_val
                             * (float)(mutual_energizer_stack.rot_vec_obj[1].k[1]
                                     - (float)(mutual_energizer_stack.trans_inertia[0]
                                             * (float)(mutual_energizer_stack.rot_vec_obj[1].k[1]
                                                     / (float)(mutual_energizer_stack.trans_inertia[0]
                                                             + mutual_energizer_stack.trans_speed_potential)))))
                     * (float)(mutual_energizer_stack.rot_vec_obj[1].k[1]
                             - (float)(mutual_energizer_stack.trans_inertia[0]
                                     * (float)(mutual_energizer_stack.rot_vec_obj[1].k[1]
                                             / (float)(mutual_energizer_stack.trans_inertia[0]
                                                     + mutual_energizer_stack.trans_speed_potential))))));
  if ( v4 < 0.0 )
    v4 = 0.0;
  v5 = d_e;
  mutual_energizer_stack.inv_rot_inertia[0] = v4 * 0.5;
  v6 = (float)(v4 * 0.5) + mutual_energizer_stack.rot_inertia[1];
  mutual_energizer_stack.trans_energy_potential = v6;
  if ( d_e > (float)(v6 * 0.1) )
  {
    v5 = v6 * 0.1;
    d_e = v6 * 0.1;
  }
  if ( v6 < 1.0e-10 )
    return 0.0;
  IVP_Mutual_Energizer::destroy_percent_energy(this: (IVP_Mutual_Energizer *)v8, percent_energy_to_destroy: v5 / v6);
  return d_e;
}

//------------------------------------------------------------------------------
// Address: 0x10082D50
// Name: public: class IVP_Friction_Core_Pair __near * IVP_Friction_System::find_pair_of_cores(class IVP_Core __near *,class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Friction_Core_Pair *__thiscall IVP_Friction_System::find_pair_of_cores(
        IVP_Friction_System *this,
        IVP_Core *core0,
        IVP_Core *core1)
{
  int v3; // edx
  void **i; // esi
  IVP_Friction_Core_Pair *result; // eax
  IVP_Core *v6; // ecx

  v3 = this->fr_pairs_of_objs.n_elems - 1;
  if ( this->fr_pairs_of_objs.n_elems == 0 )
    return nullptr;
  for ( i = &this->fr_pairs_of_objs.elems[v3]; ; --i )
  {
    result = (IVP_Friction_Core_Pair *)*i;
    v6 = *((IVP_Core **)*i + 13);
    if ( v6 == core0 && result->objs[1] == core1 )
      break;
    if ( v6 == core1 && result->objs[1] == core0 )
      break;
    if ( --v3 < 0 )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10082DA0
// Name: public: enum IVP_BOOL IVP_Core::grow_friction_system(void)
// Source: json
//------------------------------------------------------------------------------
IVP_BOOL __thiscall IVP_Core::grow_friction_system(IVP_Core *this)
{
  IVP_BOOL result; // eax
  int v3; // ecx
  IVP_Synapse_Real *v4; // eax
  IVP_Mindist *v5; // esi
  bool v6; // zf
  IVP_Core *physical_core; // ebx
  IVP_U_Memory *sim_unit_mem; // ecx
  IVP_Friction_System *affected_friction_system; // [esp+4h] [ebp-14h] BYREF
  IVP_Synapse_Real *next_synapse; // [esp+8h] [ebp-10h]
  IVP_BOOL having_new_dist; // [esp+Ch] [ebp-Ch] BYREF
  IVP_BOOL grew_new_contact_point; // [esp+10h] [ebp-8h]
  int c; // [esp+14h] [ebp-4h]

  result = IVP_FALSE;
  v3 = this->objects.n_elems - 1;
  grew_new_contact_point = IVP_FALSE;
  c = v3;
  if ( v3 >= 0 )
  {
    do
    {
      v4 = *((IVP_Synapse_Real **)this->objects.elems[v3] + 8);
      if ( v4 != nullptr )
      {
        do
        {
          v5 = (IVP_Mindist *)((char *)v4 + v4->mindist_offset);
          v6 = (*((_DWORD *)&v5->IVP_Mindist_Base + 5) & 0x3000) == 0;
          next_synapse = (IVP_Synapse_Real *)v4->next;
          if ( v6 )
          {
            physical_core = v5->synapse[0].l_obj->physical_core;
            if ( physical_core == this )
              physical_core = v5->synapse[1].l_obj->physical_core;
            if ( (*(_BYTE *)&physical_core->IVP_Core_Fast_Static & 2) != 0 )
            {
              if ( (*(_BYTE *)&this->IVP_Core_Fast_Static & 2) != 0 )
                ((void (__thiscall *)(IVP_Mindist *, int))v5->dtr_IVP_Collision)(a1: v5, a2: 1);
            }
            else if ( IVP_Core::moveable_core_has_friction_info(this: physical_core) == nullptr )
            {
              IVP_Mindist::recalc_mindist(this: v5);
              if ( (*((_DWORD *)&v5->IVP_Mindist_Base + 5) & 0xC000) == 0
                && ivp_mindist_settings.max_distance_for_friction > v5->len_numerator )
              {
                ++this->environment->sim_unit_mem->transaction_in_use;
                IVP_Mindist::try_to_generate_managed_friction(
                  this: v5,
                  associated_fs: &affected_friction_system,
                  having_new: &having_new_dist,
                  sim_unit_not_destroy: this->sim_unit_of_core,
                  call_recalc_svals: IVP_TRUE);
                sim_unit_mem = this->environment->sim_unit_mem;
                v6 = sim_unit_mem->transaction_in_use-- == 1;
                if ( v6 )
                  IVP_U_Memory::free_mem_transaction(this: sim_unit_mem);
                if ( having_new_dist == IVP_TRUE )
                {
                  grew_new_contact_point = IVP_TRUE;
                  IVP_Core::reset_freeze_check_values(this: physical_core);
                }
              }
            }
          }
          v4 = next_synapse;
        }
        while ( next_synapse != nullptr );
        v3 = c;
      }
      c = --v3;
    }
    while ( v3 >= 0 );
    return grew_new_contact_point;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10082EC0
// Name: private: bool IVP_Contact_Point::friction_force_local_constraint_2d_wheel(class IVP_Core __near *,class IVP_Impact_Solver_Long_Term __near *,class IVP_Event_Sim const __near *,float __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
char __userpurge IVP_Contact_Point::friction_force_local_constraint_2d_wheel@<al>(
        IVP_Contact_Point *this@<ecx>,
        IVP_Constraint_Solver_Car *a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        IVP_Core *core_a,
        IVP_Impact_Solver_Long_Term *info,
        const IVP_Event_Sim *es,
        float *flEnergy)
{
  double v9; // st7
  IVP_Constraint_Car_Object *car_wheel; // eax
  float v11; // edx
  int v12; // ecx
  float v14; // xmm2_4
  float v15; // xmm6_4
  float v16; // xmm7_4
  float v17; // xmm0_4
  float v18; // xmm3_4
  float v19; // xmm4_4
  float v20; // xmm6_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  float v23; // xmm6_4
  float v24; // xmm2_4
  float v25; // xmm5_4
  float v26; // xmm1_4
  float v27; // xmm7_4
  float v28; // xmm0_4
  double v29; // st7
  IVP_Core *v30; // edx
  IVP_Constraint_Car_Object *v31; // eax
  float v32; // xmm6_4
  float v33; // xmm4_4
  float v34; // xmm3_4
  float v35; // xmm0_4
  float v36; // xmm2_4
  float v37; // xmm4_4
  float v38; // xmm1_4
  float v39; // xmm2_4
  float v40; // xmm2_4
  IVP_Constraint_Car_Object *v41; // eax
  bool v42; // zf
  float v43; // xmm0_4
  float v44; // xmm3_4
  float v45; // xmm2_4
  float v46; // xmm1_4
  long double v47; // st7
  float v48; // ecx
  long double v49; // st7
  float v50; // xmm0_4
  float v51; // xmm1_4
  long double v52; // st7
  float v53; // xmm0_4
  float v54; // xmm1_4
  long double v55; // st7
  long double v56; // st7
  float v57; // ecx
  float v58; // xmm1_4
  float v59; // xmm2_4
  float v60; // xmm1_4
  float v61; // xmm0_4
  int v63; // [esp+1Ch] [ebp-2ECh] BYREF
  IVP_Solver_Core_Reaction sc_body; // [esp+28h] [ebp-2E0h] BYREF
  IVP_Solver_Core_Reaction tcb; // [esp+148h] [ebp-1C0h] BYREF
  IVP_U_Float_Point rot_damp; // [esp+268h] [ebp-A0h] BYREF
  int v67; // [esp+278h] [ebp-90h]
  float v68; // [esp+27Ch] [ebp-8Ch] BYREF
  IVP_Material *materials[2]; // [esp+280h] [ebp-88h]
  IVP_U_Float_Point axis_bs; // [esp+288h] [ebp-80h] BYREF
  IVP_U_Float_Point axis_ws; // [esp+298h] [ebp-70h]
  float dot_old1_new1; // [esp+2A8h] [ebp-60h]
  float dot_old0_new1; // [esp+2ACh] [ebp-5Ch] BYREF
  float dot_old0_new0; // [esp+2B0h] [ebp-58h]
  float dot_old1_new0; // [esp+2B4h] [ebp-54h]
  IVP_U_Float_Point span_v_0; // [esp+2B8h] [ebp-50h] BYREF
  IVP_U_Float_Point span_v_1; // [esp+2C8h] [ebp-40h]
  float v78; // [esp+2D8h] [ebp-30h]
  float v79; // [esp+2DCh] [ebp-2Ch] BYREF
  float span_s_1; // [esp+2E0h] [ebp-28h]
  IVP_U_Float_Point impulses; // [esp+2E8h] [ebp-20h]
  float maximum_impulse_force; // [esp+2F8h] [ebp-10h]
  IVP_Constraint_Solver_Car *solver; // [esp+2FCh] [ebp-Ch]
  float wheel_vel; // [esp+300h] [ebp-8h]
  float retaddr; // [esp+308h] [ebp+0h]

  solver = a2;
  wheel_vel = retaddr;
  IVP_Contact_Point::get_material_info(this, mtl: (IVP_Material **)&rot_damp.hesse_val);
  v9 = ((double (__thiscall *)(int, int, int))*(_DWORD *)(*(_DWORD *)v67 + 16))(a1: v67, a2: a3, a3: a4);
  maximum_impulse_force = v9;
  if ( v9 != 0.0 )
  {
    memset(&tcb.delta_velocity_ds.k[1], 0, 12);
    IVP_Core::damp_object(
      this: core_a,
      a2: a4,
      delta_time_: es->delta_time,
      rotation_factor: (const IVP_U_Float_Point *)&tcb.delta_velocity_ds.k[1],
      speed_factor: maximum_impulse_force);
  }
  car_wheel = core_a->car_wheel;
  v11 = *(float *)&car_wheel->solver_car;
  v12 = *(_DWORD *)(LODWORD(v11) + 40);
  impulses.k[1] = (float)(this->real_friction_factor * this->now_friction_pressure) * es->delta_time;
  v68 = car_wheel->target_position_bs.rows[0].k[v12];
  materials[0] = (IVP_Material *)LODWORD(car_wheel->target_position_bs.rows[1].k[v12]);
  materials[1] = (IVP_Material *)LODWORD(car_wheel->target_position_bs.rows[2].k[v12]);
  impulses.k[2] = v11;
  IVP_U_Matrix3::vmult3(
    this: (IVP_U_Matrix3 *)(*(_DWORD *)(**(_DWORD **)(LODWORD(v11) + 4) + 148) + 96),
    p_in: (const IVP_U_Float_Point *)&v68,
    p_out: (IVP_U_Float_Point *)&axis_bs.k[1]);
  IVP_U_Float_Point::calc_cross_product(
    this: (IVP_U_Float_Point *)&dot_old0_new1,
    v1: (IVP_U_Float_Point *)&axis_bs.k[1],
    v2: &info->surf_normal);
  maximum_impulse_force = dot_old0_new1 * dot_old0_new1;
  if ( (float)((float)((float)(dot_old0_new1 * dot_old0_new1) + (float)(dot_old0_new0 * dot_old0_new0))
             + (float)(dot_old1_new0 * dot_old1_new0)) < 0.001 )
    return 0;
  IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)&dot_old0_new1);
  IVP_U_Float_Point::calc_cross_product(
    this: (IVP_U_Float_Point *)&span_v_0.k[1],
    v1: (const IVP_U_Float_Point *)&dot_old0_new1,
    v2: &info->surf_normal);
  v14 = info->span_friction_v[0].k[1];
  v15 = info->span_friction_v[0].k[0];
  v16 = info->span_friction_v[0].k[2];
  v17 = dot_old0_new0 * info->span_friction_v[1].k[1];
  v18 = (float)((float)(dot_old0_new0 * v14) + (float)(dot_old0_new1 * v15)) + (float)(dot_old1_new0 * v16);
  v19 = (float)((float)(span_v_0.k[2] * v14) + (float)(span_v_0.k[1] * v15)) + (float)(span_v_0.hesse_val * v16);
  v20 = info->span_friction_v[1].k[0];
  v21 = (float)(span_v_0.k[2] * info->span_friction_v[1].k[1]) + (float)(v20 * span_v_0.k[1]);
  impulses.hesse_val = 0.0;
  v22 = v17 + (float)(v20 * dot_old0_new1);
  v23 = info->span_friction_v[1].k[2];
  v24 = this->span_friction_s[0];
  LODWORD(impulses.k[2]) = &span_v_0.k[1];
  LODWORD(impulses.k[1]) = &dot_old0_new1;
  v25 = this->span_friction_s[1];
  axis_ws.hesse_val = v18;
  axis_ws.k[2] = v19;
  dot_old1_new1 = v22 + (float)(dot_old1_new0 * v23);
  axis_ws.k[1] = v21 + (float)(span_v_0.hesse_val * v23);
  maximum_impulse_force = (float)(v24 * v18) + (float)(v25 * dot_old1_new1);
  span_v_1.hesse_val = (float)(v24 * v19) + (float)(v25 * axis_ws.k[1]);
  IVP_Solver_Core_Reaction::init_reaction_solver_translation_ws(
    this: (IVP_Solver_Core_Reaction *)&sc_body.delta_velocity_ds.k[1],
    core_0: core_a,
    core_1: nullptr,
    pos_ws: &info->contact_point_ws,
    direction_0_ws: (IVP_U_Float_Point *)&dot_old0_new1,
    direction_1_ws: (IVP_U_Float_Point *)&span_v_0.k[1],
    direction_2_ws: nullptr);
  impulses.k[2] = 0.0;
  LODWORD(impulses.k[1]) = &span_v_0.k[1];
  v78 = tcb.m_velocity_ds_f_impulse_ds.rows[0].k[2];
  IVP_Solver_Core_Reaction::init_reaction_solver_translation_ws(
    this: (IVP_Solver_Core_Reaction *)&v63,
    core_0: *(IVP_Core **)(*MEMORY[4] + 148),
    core_1: nullptr,
    pos_ws: &info->contact_point_ws,
    direction_0_ws: (IVP_U_Float_Point *)&span_v_0.k[1],
    direction_1_ws: nullptr,
    direction_2_ws: (IVP_U_Float_Point *)LODWORD(tcb.m_velocity_ds_f_impulse_ds.rows[2].k[2]));
  v26 = (float)(es->i_delta_time * maximum_impulse_force) - tcb.m_velocity_ds_f_impulse_ds.rows[2].k[1];
  v27 = (float)(es->i_delta_time * span_v_1.hesse_val)
      - (float)((float)(sc_body.m_velocity_ds_f_impulse_ds.rows[2].k[1] * 0.0) + impulses.hesse_val);
  v28 = (float)(tcb.cr_mult_inv1[2].k[1] * tcb.m_velocity_ds_f_impulse_ds.rows[0].k[2])
      - (float)(tcb.cr_mult_inv1[2].k[2] * tcb.cr_mult_inv1[2].k[2]);
  if ( (float)(v28 * v28) < 1.0e-20 )
  {
    *flEnergy = 0.0;
    return 1;
  }
  else
  {
    v29 = info->contact_point_ws.k[0];
    v30 = core_a;
    v31 = core_a->car_wheel;
    v32 = -(float)(tcb.cr_mult_inv1[2].k[2] * (float)(1.0 / v28));
    v33 = tcb.cr_mult_inv1[2].k[1] * (float)(1.0 / v28);
    v34 = (float)(v32 * v27) + (float)((float)(tcb.m_velocity_ds_f_impulse_ds.rows[0].k[2] * (float)(1.0 / v28)) * v26);
    v35 = (float)(COERCE_FLOAT(
                    COERCE_UNSIGNED_INT(
                      (float)((float)(axis_bs.k[1] * span_v_0.k[1]) + (float)(axis_bs.k[2] * span_v_0.k[2]))
                    + (float)(axis_bs.hesse_val * span_v_0.hesse_val))
                  & _mask__AbsFloat_)
                * v78)
        / sc_body.cr_mult_inv1[2].k[1];
    v79 = v34;
    v36 = v33;
    v37 = info->contact_point_ws.k[2];
    span_s_1 = (float)(v36 * v27) + (float)(v32 * v26);
    v38 = span_s_1 * span_s_1;
    v39 = info->contact_point_ws.k[1];
    v31->last_contact_position_ws.k[0] = v29;
    v31->last_contact_position_ws.k[1] = v39;
    v40 = impulses.k[1];
    v31->last_contact_position_ws.k[2] = v37;
    core_a->car_wheel->last_skid_time = es->environment->current_time;
    v41 = core_a->car_wheel;
    v42 = v41->fix_wheel_constraint == nullptr;
    v43 = (float)(v35 + 1.0) * 0.30000001;
    impulses.hesse_val = v43;
    v44 = v34 * v34;
    v45 = v40 * v40;
    if ( v42 )
    {
      if ( (float)((float)((float)(v38 * v43) * v43) + v44) > v45 )
      {
        v54 = v38 + v44;
        if ( v54 <= v45 )
        {
          v58 = fsqrt(v45 - v44);
          v59 = span_s_1;
          if ( span_s_1 <= 0.0 )
            LODWORD(v58) ^= _mask__NegFloat_;
          span_s_1 = v58;
          v60 = (float)(v58 * 0.89999998) / (float)(v59 * v43);
          v41->last_skid_value = (float)((float)((float)(1.0 - v60) * 0.30000001) * this->now_friction_pressure)
                               * *(float *)(*(_DWORD *)(**(_DWORD **)(LODWORD(impulses.k[2]) + 4) + 148) + 60);
          if ( v60 < 1.0 )
          {
            v61 = (float)((float)(v60 * span_v_1.hesse_val) * axis_ws.k[1])
                + (float)(maximum_impulse_force * dot_old1_new1);
            this->span_friction_s[0] = (float)((float)(v60 * span_v_1.hesse_val) * axis_ws.k[2])
                                     + (float)(maximum_impulse_force * axis_ws.hesse_val);
            this->span_friction_s[1] = v61;
          }
        }
        else
        {
          v55 = IVP_Inline_Math::isqrt_float(quad: v54);
          v56 = v55 * impulses.k[1];
          v57 = impulses.k[2];
          v79 = v79 * v56;
          span_s_1 = span_s_1 * v56;
          this->span_friction_s[0] = v56 * this->span_friction_s[0];
          this->span_friction_s[1] = v56 * this->span_friction_s[1];
          v30 = core_a;
          core_a->car_wheel->last_skid_value = (1.0 - v56)
                                             * this->now_friction_pressure
                                             * *(float *)(*(_DWORD *)(**(_DWORD **)(LODWORD(v57) + 4) + 148) + 60);
        }
      }
    }
    else
    {
      v46 = (float)((float)(v38 + v44) * v43) * v43;
      if ( v46 <= v45 )
      {
        v53 = v43 * 0.5;
        span_s_1 = v53 * span_s_1;
        v79 = v53 * v79;
        v41->last_skid_value = 0.0;
      }
      else
      {
        v47 = IVP_Inline_Math::isqrt_float(quad: v46);
        v48 = impulses.k[2];
        v49 = v47 * impulses.k[1] * impulses.hesse_val;
        v78 = v49;
        v50 = v78 / impulses.hesse_val;
        v51 = (float)(v78 / impulses.hesse_val) * this->span_friction_s[0];
        v79 = v79 * v49;
        this->span_friction_s[0] = v51;
        v52 = v49 * span_s_1;
        this->span_friction_s[1] = v50 * this->span_friction_s[1];
        span_s_1 = v52;
        v30 = core_a;
        core_a->car_wheel->last_skid_value = (float)((float)(1.0 - v50) * this->now_friction_pressure)
                                           * *(float *)(*(_DWORD *)(**(_DWORD **)(LODWORD(v48) + 4) + 148) + 60);
      }
    }
    IVP_Solver_Core_Reaction::exert_impulse_dim2(
      this: (IVP_Solver_Core_Reaction *)&sc_body.delta_velocity_ds.k[1],
      core_0: v30,
      core_1: nullptr,
      impulse_ds: (IVP_U_Float_Point *)&v79);
    *flEnergy = 0.0;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083500
// Name: private: float IVP_Contact_Point::friction_force_local_constraint_2d(class IVP_Event_Sim const __near *)
// Source: json
//------------------------------------------------------------------------------
double __userpurge IVP_Contact_Point::friction_force_local_constraint_2d@<st0>(
        IVP_Contact_Point *this@<ecx>,
        IVP_Core *a2@<ebp>,
        const IVP_Event_Sim *es)
{
  IVP_Impact_Solver_Long_Term *tmp_contact_info; // edi
  double result; // st7
  IVP_Core *v6; // ecx
  float v7; // edx
  float i_delta_time; // xmm4_4
  float v9; // xmm0_4
  float v10; // xmm4_4
  float v11; // xmm1_4
  float v12; // xmm3_4
  long double v13; // st7
  long double v14; // st7
  float v15; // xmm0_4
  _BYTE v16[12]; // [esp+14h] [ebp-14Ch] BYREF
  IVP_Solver_Core_Reaction tcb; // [esp+20h] [ebp-140h] BYREF
  IVP_U_Float_Point impulses; // [esp+140h] [ebp-20h] BYREF
  float maximum_impulse_force; // [esp+150h] [ebp-10h]
  IVP_Core *core_b; // [esp+154h] [ebp-Ch] BYREF
  float flEnergy; // [esp+158h] [ebp-8h]
  float retaddr; // [esp+160h] [ebp+0h]

  core_b = a2;
  flEnergy = retaddr;
  tmp_contact_info = this->tmp_contact_info;
  impulses.k[1] = (float)(this->now_friction_pressure * this->real_friction_factor) * es->delta_time;
  if ( impulses.k[1] < 0.000001 )
    return 0.0;
  v6 = tmp_contact_info->contact_core[0];
  v7 = *(float *)&tmp_contact_info->contact_core[1];
  maximum_impulse_force = *(float *)&v6;
  impulses.k[2] = v7;
  if ( *(float *)&v6 != 0.0
    && v6->car_wheel != nullptr
    && v7 == 0.0
    && (this->next_dist_in_friction == nullptr || this->next_dist_in_friction->now_friction_pressure == 0.0) )
  {
    impulses.hesse_val = 0.0;
    if ( IVP_Contact_Point::friction_force_local_constraint_2d_wheel(
           this,
           a2: (IVP_Constraint_Solver_Car *)&core_b,
           a3: (int)tmp_contact_info,
           a4: (int)this,
           core_a: v6,
           info: tmp_contact_info,
           es,
           flEnergy: &impulses.hesse_val) != 0 )
      return impulses.hesse_val;
    *(float *)&v6 = maximum_impulse_force;
    v7 = impulses.k[2];
  }
  IVP_Solver_Core_Reaction::init_reaction_solver_translation_ws(
    this: (IVP_Solver_Core_Reaction *)v16,
    core_0: v6,
    core_1: (IVP_Core *)LODWORD(v7),
    pos_ws: &tmp_contact_info->contact_point_ws,
    direction_0_ws: tmp_contact_info->span_friction_v,
    direction_1_ws: &tmp_contact_info->span_friction_v[1],
    direction_2_ws: nullptr);
  i_delta_time = es->i_delta_time;
  v9 = (float)(i_delta_time * this->span_friction_s[1]) - tcb.m_velocity_ds_f_impulse_ds.rows[2].k[2];
  v10 = (float)(i_delta_time * this->span_friction_s[0]) - tcb.m_velocity_ds_f_impulse_ds.rows[2].k[1];
  v11 = (float)(tcb.cr_mult_inv1[2].k[1] * tcb.m_velocity_ds_f_impulse_ds.rows[0].k[2])
      - (float)(tcb.cr_mult_inv1[2].k[2] * tcb.cr_mult_inv1[2].k[2]);
  if ( (float)(v11 * v11) < 1.0e-20 )
    return 0.0;
  LODWORD(v12) = COERCE_UNSIGNED_INT((float)(1.0 / v11) * tcb.cr_mult_inv1[2].k[2]) ^ _mask__NegFloat_;
  tcb.delta_velocity_ds.k[2] = (float)((float)((float)(1.0 / v11) * tcb.cr_mult_inv1[2].k[1]) * v9) + (float)(v12 * v10);
  tcb.delta_velocity_ds.k[1] = (float)(v12 * v9)
                             + (float)((float)((float)(1.0 / v11) * tcb.m_velocity_ds_f_impulse_ds.rows[0].k[2]) * v10);
  impulses.hesse_val = (float)(tcb.delta_velocity_ds.k[2] * tcb.delta_velocity_ds.k[2])
                     + (float)(tcb.delta_velocity_ds.k[1] * tcb.delta_velocity_ds.k[1]);
  if ( impulses.hesse_val > (float)(impulses.k[1] * impulses.k[1]) )
  {
    v13 = IVP_Inline_Math::isqrt_float(
            quad: (float)(tcb.delta_velocity_ds.k[2] * tcb.delta_velocity_ds.k[2])
          + (float)(tcb.delta_velocity_ds.k[1] * tcb.delta_velocity_ds.k[1]));
    v14 = v13 * impulses.k[1];
    tcb.delta_velocity_ds.k[1] = tcb.delta_velocity_ds.k[1] * v14;
    tcb.delta_velocity_ds.k[2] = v14 * tcb.delta_velocity_ds.k[2];
  }
  IVP_Solver_Core_Reaction::exert_impulse_dim2(
    this: (IVP_Solver_Core_Reaction *)v16,
    core_0: (IVP_Core *)LODWORD(maximum_impulse_force),
    core_1: (IVP_Core *)LODWORD(impulses.k[2]),
    impulse_ds: (IVP_U_Float_Point *)&tcb.delta_velocity_ds.k[1]);
  v15 = fsqrt(
          (float)((float)(this->span_friction_s[1] * this->span_friction_s[1])
                + (float)(this->span_friction_s[0] * this->span_friction_s[0]))
        * (float)((float)(es->delta_time * impulses.hesse_val) * es->delta_time))
      * 0.5;
  maximum_impulse_force = v15 - this->old_energy_dynamic_fr;
  result = maximum_impulse_force;
  this->old_energy_dynamic_fr = v15;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10083720
// Name: public: void IVP_Friction_System::calc_friction_forces(class IVP_Event_Sim const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Friction_System::calc_friction_forces(IVP_Friction_System *this, const IVP_Event_Sim *es)
{
  int v2; // eax
  IVP_Friction_Core_Pair *v3; // ebx
  int v4; // edi
  float j; // xmm2_4
  float *v6; // esi
  float quad; // xmm0_4
  long double v8; // st7
  long double v9; // st7
  long double v10; // st7
  float v11; // [esp+10h] [ebp-1Ch]
  IVP_Friction_System *v12; // [esp+1Ch] [ebp-10h]
  int i; // [esp+20h] [ebp-Ch]
  float v14; // [esp+24h] [ebp-8h]
  float sum_slide_way; // [esp+28h] [ebp-4h]
  int savedregs; // [esp+2Ch] [ebp+0h] BYREF

  v2 = this->fr_pairs_of_objs.n_elems - 1;
  v12 = this;
  i = v2;
  if ( this->fr_pairs_of_objs.n_elems != 0 )
  {
    while ( 1 )
    {
      v3 = (IVP_Friction_Core_Pair *)this->fr_pairs_of_objs.elems[v2];
      sum_slide_way = IVP_Friction_Core_Pair::get_sum_slide_way(this: v3, es);
      v4 = v3->fr_dists.n_elems - 1;
      v14 = 0.0;
      if ( v3->fr_dists.n_elems != 0 )
      {
        for ( j = (float)(sum_slide_way * sum_slide_way) + 0.000001; ; j = (float)(sum_slide_way * sum_slide_way)
                                                                         + 0.000001 )
        {
          v6 = (float *)v3->fr_dists.elems[v4];
          quad = (float)(v6[14] * v6[14]) + (float)(v6[15] * v6[15]);
          if ( quad > j )
          {
            v8 = IVP_Inline_Math::isqrt_float(quad);
            v11 = v8;
            v6[14] = v6[14] * (float)(v11 * sum_slide_way);
            v9 = (v8 * quad - sum_slide_way) * v6[17];
            v6[15] = v6[15] * (float)(v11 * sum_slide_way);
            v10 = v9 * v6[21];
            *((_BYTE *)v6 + 93) = 1;
            v6[18] = v10 + v6[18];
          }
          if ( *((_BYTE *)v6 + 52) == 1 )
            IVP_Contact_Point::friction_force_local_constraint_1d(
              this: (IVP_Contact_Point *)v6,
              a2: COERCE_FLOAT(&savedregs),
              es);
          else
            v14 = IVP_Contact_Point::friction_force_local_constraint_2d(
                    this: (IVP_Contact_Point *)v6,
                    a2: (IVP_Core *)&savedregs,
                    es)
                + v14;
          if ( --v4 < 0 )
            break;
        }
        if ( v14 > 0.0 )
          v3->integrated_anti_energy = v3->integrated_anti_energy + v14;
      }
      v2 = --i;
      if ( i < 0 )
        break;
      this = v12;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083860
// Name: public: static void IVP_Friction_Solver::ease_friction_pair(class IVP_Friction_Core_Pair __near *,class IVP_U_Memory __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Friction_Solver::ease_friction_pair(IVP_Friction_Core_Pair *my_pair, IVP_Contact_Point **my_mem)
{
  IVP_Friction_Core_Pair *v3; // esi
  int n_elems; // edx
  char *v5; // eax
  char *v6; // eax
  char *v7; // edi
  void *v8; // esp
  bool v9; // sf
  int v10; // edx
  IVP_U_Float_Point *v11; // eax
  int v12; // esi
  _DWORD *v13; // ecx
  _DWORD *v14; // eax
  void **elems; // edi
  char *v16; // esi
  int v17; // edi
  int v18; // esi
  IVP_U_Float_Point *v19; // edi
  int v20; // esi
  IVP_Contact_Point *v21; // esi
  int v22; // esi
  _DWORD *v23; // eax
  void *v24; // ecx
  int v25; // eax
  int v26; // esi
  IVP_Contact_Point *v27; // edx
  bool v28; // zf
  int v29; // esi
  _DWORD *v30; // esi
  float *v31; // eax
  unsigned int v32; // edi
  int v33; // edx
  float *v34; // ecx
  int v35; // edx
  float *v36; // ecx
  int v37; // edx
  float *v38; // ecx
  int v39; // edx
  float *v40; // ecx
  float v41; // xmm0_4
  float *v42; // eax
  int v43; // edx
  float *v44; // ecx
  float v45; // xmm0_4
  _BYTE v46[8]; // [esp+4h] [ebp-28h] BYREF
  float easing_factor; // [esp+Ch] [ebp-20h]
  unsigned int v48; // [esp+10h] [ebp-1Ch]
  int v49; // [esp+14h] [ebp-18h]
  IVP_Contact_Point *fr_dist; // [esp+18h] [ebp-14h]
  IVP_Contact_Point **v51; // [esp+1Ch] [ebp-10h]
  IVP_U_Float_Point *ease_diff_vec0; // [esp+20h] [ebp-Ch]
  IVP_U_Float_Point *ease_diff_force_vec_stack; // [esp+24h] [ebp-8h]
  int total_n; // [esp+28h] [ebp-4h]
  int savedregs; // [esp+2Ch] [ebp+0h] BYREF
  IVP_U_Float_Point *i; // [esp+34h] [ebp+8h]
  int ia; // [esp+34h] [ebp+8h]
  char *all_my_dists; // [esp+38h] [ebp+Ch]

  v3 = my_pair;
  n_elems = my_pair->fr_dists.n_elems;
  all_my_dists = (char *)my_mem[2];
  v5 = (char *)((unsigned int)&all_my_dists[4 * n_elems + 31] & 0xFFFFFFE0);
  total_n = n_elems;
  if ( v5 < (char *)my_mem[3] )
  {
    my_mem[2] = (IVP_Contact_Point *)v5;
    v7 = all_my_dists;
  }
  else
  {
    v6 = IVP_U_Memory::neuer_sp_block(this: (IVP_U_Memory *)my_mem, groesse: 4 * n_elems);
    n_elems = total_n;
    v7 = v6;
    all_my_dists = v6;
  }
  easing_factor = 1.0 / (float)((float)n_elems + 1.0e-10);
  v8 = alloca(16 * n_elems);
  v10 = my_pair->fr_dists.n_elems - 1;
  v9 = my_pair->fr_dists.n_elems == 0;
  v11 = (IVP_U_Float_Point *)v46;
  ease_diff_force_vec_stack = (IVP_U_Float_Point *)v46;
  if ( !v9 )
  {
    v48 = v10 + 1;
    if ( v10 + 1 >= 4 )
    {
      fr_dist = (IVP_Contact_Point *)(-4 - (_DWORD)v7);
      v12 = 8 - (_DWORD)v7;
      ease_diff_vec0 = (IVP_U_Float_Point *)(4 * v10 - 8);
      v13 = (_DWORD *)((int)ease_diff_vec0->k + (_DWORD)v7);
      v14 = &v46[16 * v10 - 12];
      v51 = (IVP_Contact_Point **)(v48 >> 2);
      v49 = 8 - (_DWORD)v7;
      v10 -= 4 * (v48 >> 2);
      while ( 1 )
      {
        elems = my_pair->fr_dists.elems;
        v14[5] = 0;
        v16 = (char *)v13 + v12;
        v17 = *(int *)((char *)elems + (_DWORD)v16);
        v14[4] = 0;
        v14[3] = 0;
        v13[2] = v17;
        v18 = *(_DWORD *)&v16[(unsigned int)my_pair->fr_dists.elems - 4];
        v19 = ease_diff_vec0--;
        v14[1] = 0;
        *v14 = 0;
        v13[1] = v18;
        *(v14 - 1) = 0;
        v20 = *(_DWORD *)((char *)v19->k + (unsigned int)my_pair->fr_dists.elems);
        *(v14 - 3) = 0;
        *v13 = v20;
        v21 = fr_dist;
        *(v14 - 4) = 0;
        *(v14 - 5) = 0;
        v22 = *(int *)((char *)&v21->next_dist_in_friction + (_DWORD)v13 + (unsigned int)my_pair->fr_dists.elems);
        *(v14 - 7) = 0;
        *(v14 - 8) = 0;
        *(v13 - 1) = v22;
        *(v14 - 9) = 0;
        v13 -= 4;
        v14 -= 16;
        v51 = (IVP_Contact_Point **)((char *)v51 - 1);
        if ( v51 == nullptr )
          break;
        v12 = v49;
      }
      v3 = my_pair;
      v7 = all_my_dists;
      v11 = ease_diff_force_vec_stack;
    }
    if ( v10 >= 0 )
    {
      v23 = (_DWORD *)&v11[v10].k[1];
      do
      {
        v24 = v3->fr_dists.elems[v10];
        v23[1] = 0;
        *v23 = 0;
        *(v23 - 1) = 0;
        *(_DWORD *)&v7[4 * v10] = v24;
        v23 -= 4;
        --v10;
      }
      while ( v10 >= 0 );
    }
  }
  if ( total_n - 1 > 0 )
  {
    v25 = 1;
    v49 = 1;
    i = ease_diff_force_vec_stack;
    v51 = (IVP_Contact_Point **)v7;
    v48 = total_n - 1;
    do
    {
      fr_dist = *v51;
      v26 = v25;
      if ( v25 < total_n )
      {
        ease_diff_vec0 = i + 1;
        do
        {
          v27 = *(IVP_Contact_Point **)&v7[4 * v26];
          if ( fabs(
                 fabs(
                   (float)((float)(v27->tmp_contact_info->surf_normal.k[1] * fr_dist->tmp_contact_info->surf_normal.k[1])
                         + (float)(v27->tmp_contact_info->surf_normal.k[0] * fr_dist->tmp_contact_info->surf_normal.k[0]))
                 + (float)(v27->tmp_contact_info->surf_normal.k[2] * fr_dist->tmp_contact_info->surf_normal.k[2]))
               - 1.0) < 0.001 )
            IVP_Friction_Solver::ease_two_mindists(
              a1: (int)&savedregs,
              dist0: v27,
              dist1: fr_dist,
              ease_diff_vec0,
              ease_diff_vec1: i,
              ease_factor: easing_factor);
          ++ease_diff_vec0;
          ++v26;
        }
        while ( v26 < total_n );
        v25 = v49;
      }
      ++v51;
      ++i;
      ++v25;
      v28 = v48-- == 1;
      v49 = v25;
    }
    while ( !v28 );
  }
  v29 = 0;
  if ( total_n >= 4 )
  {
    v30 = v7 + 8;
    v31 = &ease_diff_force_vec_stack[1].k[2];
    v32 = ((unsigned int)(total_n - 4) >> 2) + 1;
    ia = 4 * v32;
    do
    {
      v33 = *(v30 - 2);
      v34 = *(float **)(v33 + 64);
      *(float *)(v33 + 56) = (float)((float)((float)(v34[33] * *(v31 - 5)) + (float)(*(v31 - 6) * v34[32]))
                                   + (float)(v34[34] * *(v31 - 4)))
                           + *(float *)(v33 + 56);
      *(float *)(v33 + 60) = (float)((float)((float)(v34[37] * *(v31 - 5)) + (float)(*(v31 - 6) * v34[36]))
                                   + (float)(v34[38] * *(v31 - 4)))
                           + *(float *)(v33 + 60);
      v35 = *(v30 - 1);
      v36 = *(float **)(v35 + 64);
      *(float *)(v35 + 56) = (float)((float)((float)(v36[33] * *(v31 - 1)) + (float)(*(v31 - 2) * v36[32]))
                                   + (float)(v36[34] * *v31))
                           + *(float *)(v35 + 56);
      *(float *)(v35 + 60) = (float)((float)((float)(v36[37] * *(v31 - 1)) + (float)(*(v31 - 2) * v36[36]))
                                   + (float)(v36[38] * *v31))
                           + *(float *)(v35 + 60);
      v37 = *v30;
      v38 = *(float **)(*v30 + 64);
      *(float *)(v37 + 56) = (float)((float)((float)(v38[33] * v31[3]) + (float)(v31[2] * v38[32]))
                                   + (float)(v38[34] * v31[4]))
                           + *(float *)(*v30 + 56);
      *(float *)(v37 + 60) = (float)((float)((float)(v38[37] * v31[3]) + (float)(v31[2] * v38[36]))
                                   + (float)(v38[38] * v31[4]))
                           + *(float *)(v37 + 60);
      v39 = v30[1];
      v40 = *(float **)(v39 + 64);
      *(float *)(v39 + 56) = (float)((float)((float)(v40[33] * v31[7]) + (float)(v31[6] * v40[32]))
                                   + (float)(v40[34] * v31[8]))
                           + *(float *)(v39 + 56);
      v41 = (float)((float)((float)(v40[37] * v31[7]) + (float)(v31[6] * v40[36])) + (float)(v40[38] * v31[8]))
          + *(float *)(v39 + 60);
      v30 += 4;
      v31 += 16;
      --v32;
      *(float *)(v39 + 60) = v41;
    }
    while ( v32 != 0 );
    v7 = all_my_dists;
    v29 = ia;
  }
  if ( v29 < total_n )
  {
    v42 = &ease_diff_force_vec_stack[v29].k[2];
    do
    {
      v43 = *(_DWORD *)&v7[4 * v29];
      v44 = *(float **)(v43 + 64);
      *(float *)(v43 + 56) = (float)((float)((float)(v44[33] * *(v42 - 1)) + (float)(*(v42 - 2) * v44[32]))
                                   + (float)(v44[34] * *v42))
                           + *(float *)(v43 + 56);
      ++v29;
      v45 = (float)((float)((float)(v44[37] * *(v42 - 1)) + (float)(*(v42 - 2) * v44[36])) + (float)(v44[38] * *v42))
          + *(float *)(v43 + 60);
      v42 += 4;
      *(float *)(v43 + 60) = v45;
    }
    while ( v29 < total_n );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083DA0
// Name: public: void IVP_Friction_System::ease_friction_forces(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Friction_System::ease_friction_forces(IVP_Friction_System *this)
{
  int v2; // edi
  IVP_Friction_Core_Pair *v3; // esi

  v2 = this->fr_pairs_of_objs.n_elems - 1;
  if ( this->fr_pairs_of_objs.n_elems != 0 )
  {
    do
    {
      v3 = (IVP_Friction_Core_Pair *)this->fr_pairs_of_objs.elems[v2];
      if ( v3->next_ease_nr_psi-- == 1 )
      {
        IVP_Friction_Solver::ease_friction_pair(
          my_pair: v3,
          my_mem: (IVP_Contact_Point **)this->l_environment->short_term_mem);
        v3->next_ease_nr_psi = 5;
      }
      --v2;
    }
    while ( v2 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083DE0
// Name: public: void IVP_Friction_System::delete_friction_distance(class IVP_Contact_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Friction_System::delete_friction_distance(IVP_Friction_System *this, IVP_Contact_Point *old_dist)
{
  IVP_Core *physical_core; // edi
  IVP_Friction_Info_For_Core *friction_info; // esi
  IVP_Friction_Info_For_Core *v5; // ebx
  int v6; // eax
  IVP_Contact_Point **v7; // ecx
  unsigned __int16 v8; // cx
  unsigned __int16 n_elems; // dx
  int v10; // eax
  IVP_Friction_Info_For_Core **v11; // ecx
  IVP_Core *core1; // [esp+10h] [ebp-4h]
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  physical_core = old_dist->synapse[0].l_obj->physical_core;
  core1 = old_dist->synapse[1].l_obj->physical_core;
  IVP_Core::reset_freeze_check_values(this: physical_core);
  IVP_Core::reset_freeze_check_values(this: core1);
  IVP_Friction_System::remove_dist_from_system(this, old_dist);
  if ( IVP_Friction_System::dist_removed_update_pair_info(this, old_dist) == IVP_TRUE )
    *((_BYTE *)this + 68) = 1;
  friction_info = IVP_Core::get_friction_info(this: physical_core, my_fr_system: this);
  v5 = IVP_Core::get_friction_info(this: core1, my_fr_system: this);
  v6 = friction_info->friction_springs.n_elems - 1;
  if ( friction_info->friction_springs.n_elems != 0 )
  {
    v7 = (IVP_Contact_Point **)&friction_info->friction_springs.elems[v6];
    do
    {
      if ( *v7 == old_dist )
        break;
      --v7;
      --v6;
    }
    while ( v6 >= 0 );
  }
  v8 = friction_info->friction_springs.n_elems - 1;
  for ( friction_info->friction_springs.n_elems = v8; v6 < friction_info->friction_springs.n_elems; ++v6 )
    friction_info->friction_springs.elems[v6] = friction_info->friction_springs.elems[v6 + 1];
  if ( friction_info->friction_springs.n_elems == 0 )
  {
    IVP_Core::delete_friction_info(this: physical_core, my_fr_info: friction_info);
    IVP_Friction_System::remove_core_from_system(this, old_obj: physical_core);
    physical_core = (IVP_Core *)physical_core->sim_unit_of_core;
    *(_DWORD *)&physical_core->IVP_Core_Fast_Static = *(_DWORD *)&physical_core->IVP_Core_Fast_Static & 0xFFFFFCFF
                                                    | 0x100;
  }
  n_elems = v5->friction_springs.n_elems;
  v10 = n_elems - 1;
  if ( n_elems != 0 )
  {
    v11 = (IVP_Friction_Info_For_Core **)&v5->friction_springs.elems[v10];
    do
    {
      friction_info = *v11;
      if ( *v11 == (IVP_Friction_Info_For_Core *)old_dist )
        break;
      --v11;
      --v10;
    }
    while ( v10 >= 0 );
  }
  for ( v5->friction_springs.n_elems = n_elems - 1; v10 < v5->friction_springs.n_elems; ++v10 )
    v5->friction_springs.elems[v10] = v5->friction_springs.elems[v10 + 1];
  if ( v5->friction_springs.n_elems == 0 )
  {
    IVP_Core::delete_friction_info(this: core1, my_fr_info: v5);
    IVP_Friction_System::remove_core_from_system(this, old_obj: core1);
    friction_info = (IVP_Friction_Info_For_Core *)core1->sim_unit_of_core;
    *(_DWORD *)&friction_info->friction_springs.memsize = *(_DWORD *)&friction_info->friction_springs.memsize
                                                        & 0xFFFFFCFF
                                                        | 0x100;
  }
  IVP_Contact_Point::~IVP_Contact_Point(
    this: old_dist,
    a2: (IVP_Contact_Point *)&savedregs,
    a3: (int)physical_core,
    a4: (int)friction_info);
  free(data: old_dist);
}

//------------------------------------------------------------------------------
// Address: 0x10083F50
// Name: public: void IVP_Friction_System::fusion_friction_systems(class IVP_Friction_System __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Friction_System::fusion_friction_systems(
        IVP_Friction_System *this,
        IVP_Friction_System *second_sys)
{
  IVP_Friction_System *v2; // edi
  IVP_Contact_Point *first_friction_dist; // esi
  IVP_Contact_Point *next_dist_in_friction; // ebx
  int v5; // eax
  IVP_Core *v6; // ebx
  IVP_Friction_Info_For_Core *friction_info; // esi
  IVP_Friction_Info_For_Core *v8; // edi
  IVP_Friction_Info_For_Core *v9; // esi
  int v10; // eax
  unsigned __int16 n_elems; // dx
  int v12; // eax
  IVP_Contact_Point **v13; // ecx
  bool v14; // sf
  IVP_Core *obj1; // [esp+Ch] [ebp-14h]
  IVP_Contact_Point *my_dist; // [esp+10h] [ebp-10h]
  int n; // [esp+14h] [ebp-Ch]
  int m; // [esp+18h] [ebp-8h]

  v2 = second_sys;
  first_friction_dist = second_sys->first_friction_dist;
  if ( first_friction_dist != nullptr )
  {
    do
    {
      next_dist_in_friction = first_friction_dist->next_dist_in_friction;
      IVP_Friction_System::remove_dist_from_system(this: second_sys, old_dist: first_friction_dist);
      IVP_Friction_System::dist_removed_update_pair_info(this: second_sys, old_dist: first_friction_dist);
      IVP_Friction_System::add_dist_to_system(this, new_dist: first_friction_dist);
      IVP_Friction_System::dist_added_update_pair_info(this, new_dist: first_friction_dist);
      first_friction_dist = next_dist_in_friction;
    }
    while ( next_dist_in_friction != nullptr );
  }
  v5 = second_sys->cores_of_friction_system.n_elems - 1;
  n = v5;
  if ( second_sys->cores_of_friction_system.n_elems != 0 )
  {
    while ( 1 )
    {
      v6 = (IVP_Core *)v2->cores_of_friction_system.elems[v5];
      obj1 = v6;
      friction_info = IVP_Core::get_friction_info(this: v6, my_fr_system: v2);
      v8 = IVP_Core::get_friction_info(this: v6, my_fr_system: this);
      if ( v8 != nullptr )
      {
        v9 = IVP_Core::get_friction_info(this: v6, my_fr_system: second_sys);
        v10 = v9->friction_springs.n_elems - 1;
        m = v10;
        if ( v10 >= 0 )
        {
          while ( 1 )
          {
            my_dist = (IVP_Contact_Point *)v9->friction_springs.elems[v10];
            if ( v8->friction_springs.n_elems >= v8->friction_springs.memsize )
              IVP_U_Vector_Base::increment_mem(this: &v8->friction_springs);
            v8->friction_springs.elems[v8->friction_springs.n_elems++] = my_dist;
            n_elems = v9->friction_springs.n_elems;
            v12 = n_elems - 1;
            if ( n_elems != 0 )
            {
              v13 = (IVP_Contact_Point **)&v9->friction_springs.elems[v12];
              do
              {
                if ( *v13 == my_dist )
                  break;
                --v13;
                --v12;
              }
              while ( v12 >= 0 );
              v6 = obj1;
            }
            for ( v9->friction_springs.n_elems = n_elems - 1; v12 < v9->friction_springs.n_elems; ++v12 )
              v9->friction_springs.elems[v12] = v9->friction_springs.elems[v12 + 1];
            if ( --m < 0 )
              break;
            v10 = m;
          }
        }
        IVP_Core::delete_friction_info(this: v6, my_fr_info: v9);
      }
      else
      {
        IVP_Core::unlink_friction_info(this: v6, my_fr_info: friction_info);
        friction_info->l_friction_system = this;
        IVP_Core::add_friction_info(this: v6, my_fr_info: (IVP_Friction_Hash *)friction_info);
        IVP_Friction_System::remove_core_from_system(this: second_sys, old_obj: v6);
        IVP_Friction_System::add_core_to_system(this, new_obj: v6);
      }
      v14 = --n < 0;
      v2 = second_sys;
      if ( v14 )
        break;
      v5 = n;
    }
  }
  ((void (__thiscall *)(IVP_Friction_System *, int))v2->dtr_IVP_Controller)(a1: v2, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10084110
// Name: public: void IVP_Friction_System::add_fr_pair(class IVP_Friction_Core_Pair __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Friction_System::add_fr_pair(IVP_Friction_System *this, IVP_Friction_Core_Pair *pair)
{
  IVP_U_Vector<IVP_Friction_Core_Pair> *p_fr_pairs_of_objs; // esi

  p_fr_pairs_of_objs = &this->fr_pairs_of_objs;
  if ( this->fr_pairs_of_objs.n_elems >= this->fr_pairs_of_objs.memsize )
    IVP_U_Vector_Base::increment_mem(this: &this->fr_pairs_of_objs);
  p_fr_pairs_of_objs->elems[p_fr_pairs_of_objs->n_elems++] = pair;
  IVP_Environment::fire_event_friction_pair_created(this: pair->objs[0]->environment, pair);
}

//------------------------------------------------------------------------------
// Address: 0x10084150
// Name: public: void IVP_Friction_System::del_fr_pair(class IVP_Friction_Core_Pair __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Friction_System::del_fr_pair(IVP_Friction_System *this, IVP_Friction_Core_Pair *pair)
{
  unsigned __int16 n_elems; // dx
  int v4; // eax
  IVP_Friction_Core_Pair **v5; // ecx

  IVP_Environment::fire_event_friction_pair_deleted(this: pair->objs[0]->environment, pair);
  n_elems = this->fr_pairs_of_objs.n_elems;
  v4 = n_elems - 1;
  if ( n_elems != 0 )
  {
    v5 = (IVP_Friction_Core_Pair **)&this->fr_pairs_of_objs.elems[v4];
    do
    {
      if ( *v5 == pair )
        break;
      --v5;
      --v4;
    }
    while ( v4 >= 0 );
  }
  for ( this->fr_pairs_of_objs.n_elems = n_elems - 1; v4 < this->fr_pairs_of_objs.n_elems; ++v4 )
    this->fr_pairs_of_objs.elems[v4] = this->fr_pairs_of_objs.elems[v4 + 1];
}

//------------------------------------------------------------------------------
// Address: 0x100841B0
// Name: public: int IVP_Friction_Core_Pair::check_all_fr_mindists_to_be_valid(class IVP_Friction_System __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_Friction_Core_Pair::check_all_fr_mindists_to_be_valid(
        IVP_Friction_Core_Pair *this,
        IVP_Friction_System *my_fs)
{
  int result; // eax
  int v3; // ebx
  IVP_Contact_Point *v4; // esi
  IVP_Impact_Solver_Long_Term *tmp_contact_info; // edi
  IVP_Core *physical_core; // edi
  IVP_Core *v7; // ebx
  IVP_Friction_Info_For_Core *friction_info; // esi
  IVP_Friction_Info_For_Core *v9; // ebx
  int v10; // eax
  IVP_Contact_Point **v11; // ecx
  unsigned __int16 v12; // cx
  unsigned __int16 n_elems; // dx
  int v14; // eax
  IVP_Friction_Info_For_Core **v15; // ecx
  IVP_Environment *pEnv; // [esp+4h] [ebp-18h]
  IVP_Friction_Core_Pair *v17; // [esp+8h] [ebp-14h]
  int k; // [esp+Ch] [ebp-10h]
  IVP_Core *old_obj; // [esp+10h] [ebp-Ch]
  int total_number_remaining; // [esp+14h] [ebp-8h]
  IVP_Contact_Point *my_dist; // [esp+18h] [ebp-4h]
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  result = this->fr_dists.n_elems;
  v3 = result - 1;
  v17 = this;
  total_number_remaining = result;
  pEnv = this->objs[0]->environment;
  k = result - 1;
  if ( this->fr_dists.n_elems != 0 )
  {
    while ( 1 )
    {
      v4 = (IVP_Contact_Point *)this->fr_dists.elems[v3];
      my_dist = v4;
      IVP_Contact_Point::recalc_friction_s_vals(this: v4, env: pEnv);
      tmp_contact_info = v4->tmp_contact_info;
      IVP_Contact_Point::read_materials_for_contact_situation(this: v4, info: tmp_contact_info);
      if ( tmp_contact_info->friction_is_broken == 1 )
      {
        --total_number_remaining;
        physical_core = v4->synapse[0].l_obj->physical_core;
        v7 = v4->synapse[1].l_obj->physical_core;
        old_obj = v7;
        IVP_Core::reset_freeze_check_values(this: physical_core);
        IVP_Core::reset_freeze_check_values(this: v7);
        IVP_Friction_System::remove_dist_from_system(this: my_fs, old_dist: v4);
        if ( IVP_Friction_System::dist_removed_update_pair_info(this: my_fs, old_dist: v4) == IVP_TRUE )
          *((_BYTE *)my_fs + 68) = 1;
        friction_info = IVP_Core::get_friction_info(this: physical_core, my_fr_system: my_fs);
        v9 = IVP_Core::get_friction_info(this: v7, my_fr_system: my_fs);
        v10 = friction_info->friction_springs.n_elems - 1;
        if ( friction_info->friction_springs.n_elems != 0 )
        {
          v11 = (IVP_Contact_Point **)&friction_info->friction_springs.elems[v10];
          do
          {
            if ( *v11 == my_dist )
              break;
            --v11;
            --v10;
          }
          while ( v10 >= 0 );
        }
        v12 = friction_info->friction_springs.n_elems - 1;
        for ( friction_info->friction_springs.n_elems = v12; v10 < friction_info->friction_springs.n_elems; ++v10 )
          friction_info->friction_springs.elems[v10] = friction_info->friction_springs.elems[v10 + 1];
        if ( friction_info->friction_springs.n_elems == 0 )
        {
          IVP_Core::delete_friction_info(this: physical_core, my_fr_info: friction_info);
          IVP_Friction_System::remove_core_from_system(this: my_fs, old_obj: physical_core);
          physical_core = (IVP_Core *)physical_core->sim_unit_of_core;
          *(_DWORD *)&physical_core->IVP_Core_Fast_Static = *(_DWORD *)&physical_core->IVP_Core_Fast_Static & 0xFFFFFCFF
                                                          | 0x100;
        }
        n_elems = v9->friction_springs.n_elems;
        v14 = n_elems - 1;
        if ( n_elems != 0 )
        {
          v15 = (IVP_Friction_Info_For_Core **)&v9->friction_springs.elems[v14];
          do
          {
            friction_info = *v15;
            if ( *v15 == (IVP_Friction_Info_For_Core *)my_dist )
              break;
            --v15;
            --v14;
          }
          while ( v14 >= 0 );
        }
        for ( v9->friction_springs.n_elems = n_elems - 1; v14 < v9->friction_springs.n_elems; ++v14 )
          v9->friction_springs.elems[v14] = v9->friction_springs.elems[v14 + 1];
        if ( v9->friction_springs.n_elems == 0 )
        {
          friction_info = (IVP_Friction_Info_For_Core *)old_obj;
          IVP_Core::delete_friction_info(this: old_obj, my_fr_info: v9);
          IVP_Friction_System::remove_core_from_system(this: my_fs, old_obj);
          *(_DWORD *)old_obj->sim_unit_of_core = *(_DWORD *)old_obj->sim_unit_of_core & 0xFFFFFCFF | 0x100;
        }
        IVP_Contact_Point::~IVP_Contact_Point(
          this: my_dist,
          a2: (IVP_Contact_Point *)&savedregs,
          a3: (int)physical_core,
          a4: (int)friction_info);
        free(data: my_dist);
        v3 = k;
      }
      k = --v3;
      if ( v3 < 0 )
        break;
      this = v17;
    }
    return total_number_remaining;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10084380
// Name: public: IVP_Friction_Core_Pair::~IVP_Friction_Core_Pair(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Friction_Core_Pair::~IVP_Friction_Core_Pair(IVP_Friction_Core_Pair *this)
{
  IVP_Friction_Core_Pair *elems; // eax

  elems = (IVP_Friction_Core_Pair *)this->fr_dists.elems;
  if ( elems == (IVP_Friction_Core_Pair *)(&this->fr_dists + 1) )
  {
    this->fr_dists.n_elems = 0;
  }
  else
  {
    if ( elems != nullptr )
      free(data: elems);
    this->fr_dists.elems = nullptr;
    *(_DWORD *)&this->fr_dists.memsize = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100843B0
// Name: public: IVP_Friction_Core_Pair::IVP_Friction_Core_Pair(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Friction_Core_Pair *__thiscall IVP_Friction_Core_Pair::IVP_Friction_Core_Pair(IVP_Friction_Core_Pair *this)
{
  *(_DWORD *)&this->fr_dists.memsize = 0;
  this->fr_dists.elems = nullptr;
  this->last_impact_time_pair.seconds = -1000.0;
  this->integrated_anti_energy = 0.0;
  this->next_ease_nr_psi = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100843F0
// Name: private: void IVP_Friction_Sys_Static::do_simulation_single_friction(class IVP_Event_Sim __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Friction_Sys_Static::do_simulation_single_friction(
        IVP_Friction_Sys_Static *this,
        IVP_Event_Sim *es)
{
  IVP_Contact_Point *first_friction_dist; // esi
  IVP_Impact_Solver_Long_Term *tmp_contact_info; // edi
  float v5; // xmm1_4
  float v6; // xmm0_4
  float impulse; // xmm0_4
  float closing_speed; // [esp+10h] [ebp-4h]

  first_friction_dist = this->l_friction_system->first_friction_dist;
  tmp_contact_info = first_friction_dist->tmp_contact_info;
  closing_speed = IVP_Impact_Solver_Long_Term::get_closing_speed(this: tmp_contact_info);
  v5 = ivp_mindist_settings.friction_dist - first_friction_dist->last_gap_len;
  v6 = 1.0;
  if ( v5 < 0.0 )
    v6 = 20.0;
  impulse = (float)((float)(v6 * v5) + closing_speed) * tmp_contact_info->virtual_mass;
  if ( impulse <= 0.0 )
  {
    first_friction_dist->now_friction_pressure = 0.0;
  }
  else
  {
    first_friction_dist->now_friction_pressure = es->i_delta_time * impulse;
    IVP_Friction_Solver::apply_impulse(info: tmp_contact_info, impulse);
  }
  if ( first_friction_dist->last_gap_len >= ivp_mindist_settings.max_distance_for_friction
    || first_friction_dist->tmp_contact_info->friction_is_broken == 1 )
  {
    IVP_Friction_System::delete_friction_distance(this: this->l_friction_system, old_dist: first_friction_dist);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100844A0
// Name: public: virtual void IVP_Friction_System::do_simulation_controller(class IVP_Event_Sim __near *,class IVP_U_Vector<class IVP_Core> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Friction_System::do_simulation_controller(
        IVP_Friction_System *this,
        IVP_Event_Sim *es,
        IVP_U_Vector<IVP_Core> *__formal)
{
  IVP_Contact_Point *first_friction_dist; // esi
  float quad; // xmm1_4
  long double v7; // st7
  long double v8; // st7
  long double v9; // st7
  float v10; // [esp+Ch] [ebp-8h]
  int savedregs; // [esp+14h] [ebp+0h] BYREF
  float max_local_spring_len; // [esp+1Ch] [ebp+8h]

  if ( this->friction_dist_number > 1 )
  {
    IVP_Friction_System::calc_friction_forces(this, es);
    IVP_Friction_System::ease_friction_forces(this);
  }
  else
  {
    first_friction_dist = this->first_friction_dist;
    max_local_spring_len = (float)((float)((float)(first_friction_dist->now_friction_pressure
                                                 * first_friction_dist->real_friction_factor)
                                         * first_friction_dist->inv_virt_mass_mindist_no_dir)
                                 * es->delta_time)
                         * es->delta_time;
    quad = (float)(first_friction_dist->span_friction_s[0] * first_friction_dist->span_friction_s[0])
         + (float)(first_friction_dist->span_friction_s[1] * first_friction_dist->span_friction_s[1]);
    if ( quad > (float)((float)(max_local_spring_len * max_local_spring_len) + 0.000001) )
    {
      v7 = IVP_Inline_Math::isqrt_float(quad);
      v10 = v7;
      first_friction_dist->span_friction_s[0] = first_friction_dist->span_friction_s[0]
                                              * (float)(v10 * max_local_spring_len);
      v8 = (v7 * quad - max_local_spring_len) * first_friction_dist->real_friction_factor;
      first_friction_dist->span_friction_s[1] = first_friction_dist->span_friction_s[1]
                                              * (float)(v10 * max_local_spring_len);
      v9 = v8 * first_friction_dist->now_friction_pressure;
      *((_BYTE *)&first_friction_dist->IVP_Contact_Point_Fast + 93) = 1;
      first_friction_dist->integrated_destroyed_energy = v9 + first_friction_dist->integrated_destroyed_energy;
    }
    if ( *((_BYTE *)&first_friction_dist->IVP_Contact_Point_Fast_Static + 52) == 1 )
      IVP_Contact_Point::friction_force_local_constraint_1d(this: first_friction_dist, a2: COERCE_FLOAT(&savedregs), es);
    else
      IVP_Contact_Point::friction_force_local_constraint_2d(this: first_friction_dist, a2: (IVP_Core *)&savedregs, es);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10084590
// Name: public: virtual void IVP_Friction_Sys_Static::core_is_going_to_be_deleted_event(class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Friction_Sys_Static::core_is_going_to_be_deleted_event(
        IVP_Friction_Sys_Static *this,
        IVP_Core *del_core)
{
  int v3; // eax
  _DWORD *v4; // edi
  int v5; // esi
  IVP_Friction_System *l_friction_system; // ebx
  int j; // [esp+4h] [ebp-4h]

  v3 = this->l_friction_system->fr_pairs_of_objs.n_elems - 1;
  j = v3;
  if ( this->l_friction_system->fr_pairs_of_objs.n_elems != 0 )
  {
    do
    {
      v4 = this->l_friction_system->fr_pairs_of_objs.elems[v3];
      if ( (IVP_Core *)v4[13] == del_core || (IVP_Core *)v4[14] == del_core )
      {
        v5 = *((unsigned __int16 *)v4 + 1) - 1;
        if ( *((_WORD *)v4 + 1) != 0 )
        {
          do
            IVP_Friction_System::delete_friction_distance(
              this: this->l_friction_system,
              old_dist: *(IVP_Contact_Point **)(v4[1] + 4 * v5--));
          while ( v5 >= 0 );
          v3 = j;
        }
      }
      j = --v3;
    }
    while ( v3 >= 0 );
  }
  l_friction_system = this->l_friction_system;
  if ( l_friction_system->friction_dist_number == 0 )
    ((void (__thiscall *)(IVP_Friction_System *, int))l_friction_system->dtr_IVP_Controller)(
      a1: l_friction_system,
      a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10084600
// Name: public: IVP_Friction_Solver::IVP_Friction_Solver(class IVP_Friction_System __near *,class IVP_Event_Sim const __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Friction_Solver *__thiscall IVP_Friction_Solver::IVP_Friction_Solver(
        IVP_Friction_Solver *this,
        IVP_Friction_System *fri_sys,
        const IVP_Event_Sim *es_in)
{
  IVP_U_Memory *short_term_mem; // edi
  int v5; // eax
  unsigned int v6; // eax
  int v7; // ecx
  unsigned int v8; // ecx
  float *speicherbeginn; // edx
  unsigned int v10; // eax
  float *v11; // eax
  int aligned_row_len; // ecx
  unsigned int v13; // ecx
  float *v14; // edx
  unsigned int v15; // eax
  float *v16; // eax
  int v17; // ecx
  unsigned int v18; // ecx
  float *v19; // edx
  unsigned int v20; // eax

  IVP_Great_Matrix_Many_Zero::IVP_Great_Matrix_Many_Zero(this: &this->dist_change_mat);
  *(_DWORD *)&this->contact_info_vector.memsize = 512;
  this->contact_info_vector.elems = (void **)this->contact_info_vector.elem_buffer;
  this->l_environment = fri_sys->l_environment;
  this->es = es_in;
  short_term_mem = fri_sys->l_environment->short_term_mem;
  v5 = fri_sys->friction_dist_number - fri_sys->complex_not_necessary_number;
  this->dist_change_mat.columns = v5;
  v6 = (v5 + 3) & 0xFFFFFFFC;
  v7 = v6 * this->dist_change_mat.columns;
  this->dist_change_mat.aligned_row_len = v6;
  v8 = 4 * v7 + 12;
  speicherbeginn = (float *)short_term_mem->speicherbeginn;
  v10 = ((unsigned int)speicherbeginn + v8 + 31) & 0xFFFFFFE0;
  if ( (char *)v10 < short_term_mem->speicherende )
  {
    short_term_mem->speicherbeginn = (char *)v10;
    v11 = speicherbeginn;
  }
  else
  {
    v11 = (float *)IVP_U_Memory::neuer_sp_block(this: short_term_mem, groesse: v8);
  }
  aligned_row_len = this->dist_change_mat.aligned_row_len;
  this->dist_change_mat.matrix_values = v11;
  v13 = aligned_row_len;
  v14 = (float *)short_term_mem->speicherbeginn;
  v15 = ((unsigned int)&v14[v13 + 7] + 3) & 0xFFFFFFE0;
  if ( (char *)v15 < short_term_mem->speicherende )
  {
    short_term_mem->speicherbeginn = (char *)v15;
    v16 = v14;
  }
  else
  {
    v16 = (float *)IVP_U_Memory::neuer_sp_block(this: short_term_mem, groesse: v13 * 4);
  }
  v17 = this->dist_change_mat.aligned_row_len;
  this->dist_change_mat.desired_vector = v16;
  v18 = v17;
  v19 = (float *)short_term_mem->speicherbeginn;
  v20 = ((unsigned int)&v19[v18 + 7] + 3) & 0xFFFFFFE0;
  if ( (char *)v20 < short_term_mem->speicherende )
  {
    short_term_mem->speicherbeginn = (char *)v20;
    this->dist_change_mat.result_vector = v19;
  }
  else
  {
    this->dist_change_mat.result_vector = (float *)IVP_U_Memory::neuer_sp_block(this: short_term_mem, groesse: v18 * 4);
  }
  IVP_Great_Matrix_Many_Zero::align_matrix_values(this: &this->dist_change_mat);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100846F0
// Name: public: void IVP_Friction_System::remove_energy_gained_by_real_friction(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall IVP_Friction_System::remove_energy_gained_by_real_friction(
        IVP_Friction_System *this@<ecx>,
        IVP_Core *a2@<ebp>)
{
  int v3; // edi
  IVP_Friction_Core_Pair *v4; // esi
  IVP_Core *v5; // eax
  float d_e; // xmm0_4
  double v7; // st7

  v3 = this->fr_pairs_of_objs.n_elems - 1;
  if ( this->fr_pairs_of_objs.n_elems != 0 )
  {
    do
    {
      v4 = (IVP_Friction_Core_Pair *)this->fr_pairs_of_objs.elems[v3];
      v5 = v4->objs[0];
      d_e = v5->environment->integrated_energy_damp * v4->integrated_anti_energy;
      v4->integrated_anti_energy = d_e;
      if ( d_e >= 0.0 && v5->car_wheel == nullptr && v4->objs[1]->car_wheel == nullptr )
      {
        v7 = IVP_Friction_Core_Pair::destroy_mutual_energy(this: v4, a2, d_e);
        v4->objs[0]->environment->statistic_manager.sum_energy_destr = v4->objs[0]->environment->statistic_manager.sum_energy_destr
                                                                     + v7;
        v4->integrated_anti_energy = v4->integrated_anti_energy - v7;
      }
      --v3;
    }
    while ( v3 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10084760
// Name: public: virtual void IVP_Friction_Sys_Energy::do_simulation_controller(class IVP_Event_Sim __near *,class IVP_U_Vector<class IVP_Core> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Friction_Sys_Energy::do_simulation_controller(
        IVP_Friction_Sys_Energy *this,
        IVP_Event_Sim *es,
        IVP_U_Vector<IVP_Core> *__formal)
{
  IVP_Friction_System *l_friction_system; // ecx
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  l_friction_system = this->l_friction_system;
  if ( l_friction_system->friction_dist_number > 1 )
  {
    IVP_Friction_System::fs_recalc_all_contact_points(this: l_friction_system);
    if ( (*(_DWORD *)es->sim_unit & 0x3000) != 0 )
      IVP_Friction_System::clear_integrated_anti_energy(this: this->l_friction_system);
    if ( (*(_DWORD *)es->sim_unit & 0xC00) == 0 )
      IVP_Friction_System::remove_energy_gained_by_real_friction(
        this: this->l_friction_system,
        a2: (IVP_Core *)&savedregs);
  }
  else
  {
    IVP_Contact_Point::recalc_friction_s_vals(this: l_friction_system->first_friction_dist, env: es->environment);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100847C0
// Name: public: void IVP_Friction_System::split_friction_system(class IVP_Core __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Friction_System::split_friction_system(IVP_Friction_System *this, IVP_Core *split_father)
{
  IVP_Friction_System *v2; // edi
  IVP_Friction_System *v3; // eax
  IVP_Friction_System *v4; // ebx
  void **elems; // edx
  IVP_Core *v6; // esi
  IVP_Friction_Hash *v7; // eax
  IVP_Friction_Hash *v8; // edi
  IVP_Core *union_find_father; // eax
  IVP_Core *v10; // ecx
  IVP_Friction_Core_Pair *v11; // eax
  IVP_Core *v12; // esi
  IVP_Core *v13; // edi
  IVP_Friction_Info_For_Core *friction_info; // ebx
  IVP_Core *v15; // eax
  IVP_Core *i; // ecx
  unsigned __int16 n_elems; // dx
  int v18; // eax
  void **v19; // ecx
  IVP_Contact_Point *v20; // esi
  IVP_Contact_Point *first_friction_dist; // eax
  int v22; // ecx
  unsigned __int16 v23; // dx
  int v24; // eax
  IVP_Contact_Point **v25; // ecx
  IVP_Friction_Info_For_Core *v26; // eax
  IVP_Core *v27; // esi
  IVP_Friction_Info_For_Core *v28; // edi
  IVP_Friction_Info_For_Core *v29; // ebx
  IVP_Core *fr_sys; // eax
  IVP_Core *v31; // edi
  IVP_Friction_Info_For_Core *v32; // esi
  void **v33; // eax
  IVP_Core *v34; // ebx
  IVP_Friction_Info_For_Core *v35; // esi
  void **v36; // eax
  int n; // [esp+Ch] [ebp-18h]
  int k; // [esp+10h] [ebp-14h]
  int fr_i_new; // [esp+14h] [ebp-10h]
  IVP_Friction_Info_For_Core *fr_i_newa; // [esp+14h] [ebp-10h]
  IVP_Friction_Core_Pair *fr_pair; // [esp+18h] [ebp-Ch]
  IVP_Friction_System *new_fr_sys; // [esp+1Ch] [ebp-8h]
  int l; // [esp+2Ch] [ebp+8h]

  v2 = this;
  while ( 1 )
  {
    v3 = (IVP_Friction_System *)p_malloc(size: 0x4Cu);
    if ( v3 != nullptr )
    {
      v4 = IVP_Friction_System::IVP_Friction_System(this: v3, env: v2->l_environment);
      new_fr_sys = v4;
    }
    else
    {
      v4 = nullptr;
      new_fr_sys = nullptr;
    }
    fr_i_new = v2->cores_of_friction_system.n_elems - 1;
    if ( v2->cores_of_friction_system.n_elems != 0 )
    {
      do
      {
        elems = v2->cores_of_friction_system.elems;
        v6 = (IVP_Core *)elems[fr_i_new];
        if ( (*(_BYTE *)&v6->IVP_Core_Fast_Static & 2) != 0 )
        {
          v7 = (IVP_Friction_Hash *)p_malloc(size: 0xCu);
          if ( v7 != nullptr )
          {
            v7->size = 0;
            v7->size_mm = 0;
            v8 = v7;
          }
          else
          {
            v8 = nullptr;
          }
          v8->nelems = (int)v4;
          IVP_Friction_System::add_core_to_system(this: v4, new_obj: v6);
          IVP_Core::add_friction_info(this: v6, my_fr_info: v8);
          v2 = this;
        }
        else
        {
          union_find_father = (IVP_Core *)elems[fr_i_new];
          do
          {
            v10 = union_find_father;
            union_find_father = union_find_father->tmp.union_find_father;
          }
          while ( union_find_father != nullptr );
          if ( v10 == split_father )
          {
            IVP_Friction_System::remove_core_from_system(this: v2, old_obj: (IVP_Core *)elems[fr_i_new]);
            IVP_Friction_System::add_core_to_system(this: v4, new_obj: v6);
            IVP_Core::get_friction_info(this: v6, my_fr_system: v2)->l_friction_system = v4;
          }
        }
        --fr_i_new;
      }
      while ( fr_i_new >= 0 );
    }
    n = v2->fr_pairs_of_objs.n_elems - 1;
    if ( v2->fr_pairs_of_objs.n_elems != 0 )
    {
      while ( 1 )
      {
        v11 = (IVP_Friction_Core_Pair *)this->fr_pairs_of_objs.elems[n];
        v12 = v11->objs[0];
        v13 = v11->objs[1];
        friction_info = nullptr;
        fr_pair = v11;
        fr_i_newa = nullptr;
        if ( (*(_BYTE *)&v12->IVP_Core_Fast_Static & 2) != 0 )
          break;
        if ( (*(_BYTE *)&v13->IVP_Core_Fast_Static & 2) != 0 )
          goto found_fixed;
LABEL_21:
        v15 = v12;
        for ( i = v12; v15 != nullptr; v15 = v15->tmp.union_find_father )
          i = v15;
        if ( i == split_father )
        {
          IVP_Environment::fire_event_friction_pair_deleted(this: fr_pair->objs[0]->environment, pair: fr_pair);
          n_elems = this->fr_pairs_of_objs.n_elems;
          v18 = n_elems - 1;
          if ( n_elems != 0 )
          {
            v19 = &this->fr_pairs_of_objs.elems[v18];
            do
            {
              if ( *v19 == fr_pair )
                break;
              --v19;
              --v18;
            }
            while ( v18 >= 0 );
          }
          for ( this->fr_pairs_of_objs.n_elems = n_elems - 1; v18 < this->fr_pairs_of_objs.n_elems; ++v18 )
            this->fr_pairs_of_objs.elems[v18] = this->fr_pairs_of_objs.elems[v18 + 1];
          if ( new_fr_sys->fr_pairs_of_objs.n_elems >= new_fr_sys->fr_pairs_of_objs.memsize )
            IVP_U_Vector_Base::increment_mem(this: &new_fr_sys->fr_pairs_of_objs);
          new_fr_sys->fr_pairs_of_objs.elems[new_fr_sys->fr_pairs_of_objs.n_elems++] = fr_pair;
          IVP_Environment::fire_event_friction_pair_created(this: fr_pair->objs[0]->environment, pair: fr_pair);
          k = fr_pair->fr_dists.n_elems - 1;
          if ( fr_pair->fr_dists.n_elems != 0 )
          {
            do
            {
              v20 = (IVP_Contact_Point *)fr_pair->fr_dists.elems[k];
              first_friction_dist = this->first_friction_dist;
              v22 = 0;
              if ( first_friction_dist == nullptr )
                goto LABEL_38;
              do
              {
                if ( first_friction_dist == v20 )
                  v22 = 1;
                first_friction_dist = first_friction_dist->next_dist_in_friction;
              }
              while ( first_friction_dist != nullptr );
              if ( v22 == 0 )
LABEL_38:
                _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_intern\\ivp_friction.cxx", 1519);
              IVP_Friction_System::remove_dist_from_system(this, old_dist: v20);
              IVP_Friction_System::add_dist_to_system(this: new_fr_sys, new_dist: v20);
              if ( friction_info != nullptr )
              {
                v23 = friction_info->friction_springs.n_elems;
                v24 = v23 - 1;
                if ( v23 != 0 )
                {
                  v25 = (IVP_Contact_Point **)&friction_info->friction_springs.elems[v24];
                  do
                  {
                    if ( *v25 == v20 )
                      break;
                    --v25;
                    --v24;
                  }
                  while ( v24 >= 0 );
                }
                for ( friction_info->friction_springs.n_elems = v23 - 1;
                      v24 < friction_info->friction_springs.n_elems;
                      ++v24 )
                {
                  friction_info->friction_springs.elems[v24] = friction_info->friction_springs.elems[v24 + 1];
                }
                v26 = fr_i_newa;
                if ( fr_i_newa->friction_springs.n_elems >= fr_i_newa->friction_springs.memsize )
                {
                  IVP_U_Vector_Base::increment_mem(this: &fr_i_newa->friction_springs);
                  v26 = fr_i_newa;
                }
                v26->friction_springs.elems[v26->friction_springs.n_elems++] = v20;
              }
              --k;
            }
            while ( k >= 0 );
          }
        }
        if ( --n < 0 )
          goto LABEL_51;
      }
      v13 = v11->objs[0];
      v12 = v11->objs[1];
found_fixed:
      friction_info = IVP_Core::get_friction_info(this: v13, my_fr_system: this);
      fr_i_newa = IVP_Core::get_friction_info(this: v13, my_fr_system: new_fr_sys);
      goto LABEL_21;
    }
LABEL_51:
    l = this->cores_of_friction_system.n_elems - 1;
    if ( this->cores_of_friction_system.n_elems != 0 )
    {
      do
      {
        v27 = (IVP_Core *)this->cores_of_friction_system.elems[l];
        if ( (*(_BYTE *)&v27->IVP_Core_Fast_Static & 2) != 0 )
        {
          v28 = IVP_Core::get_friction_info(this: v27, my_fr_system: new_fr_sys);
          v29 = IVP_Core::get_friction_info(this: v27, my_fr_system: this);
          if ( v28->friction_springs.n_elems == 0 )
          {
            IVP_Core::delete_friction_info(this: v27, my_fr_info: v28);
            IVP_Friction_System::remove_core_from_system(this: new_fr_sys, old_obj: v27);
          }
          if ( v29->friction_springs.n_elems == 0 )
          {
            IVP_Core::delete_friction_info(this: v27, my_fr_info: v29);
            IVP_Friction_System::remove_core_from_system(this, old_obj: v27);
          }
        }
        --l;
      }
      while ( l >= 0 );
    }
    if ( new_fr_sys->friction_obj_number < 2 )
      break;
    v2 = this;
    if ( this->friction_obj_number < 2 )
    {
      v34 = (IVP_Core *)*this->cores_of_friction_system.elems;
      v35 = IVP_Core::get_friction_info(this: v34, my_fr_system: this);
      IVP_Core::delete_friction_info(this: v34, my_fr_info: v35);
      if ( v35 != nullptr )
      {
        v36 = v35->friction_springs.elems;
        if ( v36 != (void **)&v35->l_friction_system )
        {
          if ( v36 != nullptr )
            free(data: v36);
          v35->friction_springs.elems = nullptr;
          v35->friction_springs.memsize = 0;
        }
        v35->friction_springs.n_elems = 0;
        free(data: v35);
      }
      ((void (__thiscall *)(IVP_Friction_System *, int))this->dtr_IVP_Controller)(a1: this, a2: 1);
      return;
    }
    fr_sys = IVP_Friction_System::union_find_fr_sys(this);
    if ( fr_sys == nullptr )
      return;
    split_father = fr_sys;
  }
  v31 = (IVP_Core *)*new_fr_sys->cores_of_friction_system.elems;
  v32 = IVP_Core::get_friction_info(this: v31, my_fr_system: new_fr_sys);
  IVP_Core::delete_friction_info(this: v31, my_fr_info: v32);
  if ( v32 != nullptr )
  {
    v33 = v32->friction_springs.elems;
    if ( v33 != (void **)&v32->l_friction_system )
    {
      if ( v33 != nullptr )
        free(data: v32->friction_springs.elems);
      v32->friction_springs.elems = nullptr;
      v32->friction_springs.memsize = 0;
    }
    v32->friction_springs.n_elems = 0;
    free(data: v32);
  }
  ((void (__thiscall *)(IVP_Friction_System *, int))new_fr_sys->dtr_IVP_Controller)(a1: new_fr_sys, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10084BB0
// Name: public: virtual void IVP_Friction_Sys_Static::do_simulation_controller(class IVP_Event_Sim __near *,class IVP_U_Vector<class IVP_Core> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Friction_Sys_Static::do_simulation_controller(
        IVP_Friction_Sys_Static *this,
        IVP_Event_Sim *es,
        IVP_U_Vector<IVP_Core> *__formal)
{
  IVP_Friction_System *l_friction_system; // ecx
  IVP_Friction_System *v5; // ecx
  IVP_Core *fr_sys; // eax
  IVP_Core *v7; // edi

  l_friction_system = this->l_friction_system;
  if ( l_friction_system->friction_dist_number > 1 )
    IVP_Friction_System::do_friction_system(this: l_friction_system, es_in: es);
  else
    IVP_Friction_Sys_Static::do_simulation_single_friction(this, es);
  v5 = this->l_friction_system;
  if ( v5->friction_dist_number != 0 )
  {
    if ( *((_BYTE *)v5 + 68) != 0 )
    {
      *((_BYTE *)v5 + 68) = 0;
      fr_sys = IVP_Friction_System::union_find_fr_sys(this: this->l_friction_system);
      v7 = fr_sys;
      if ( fr_sys != nullptr )
      {
        IVP_Friction_System::split_friction_system(this: this->l_friction_system, split_father: fr_sys);
        *(_DWORD *)v7->sim_unit_of_core = *(_DWORD *)v7->sim_unit_of_core & 0xFFFFFCFF | 0x100;
      }
    }
  }
  else
  {
    this->l_friction_system = nullptr;
    if ( v5 != nullptr )
      ((void (__thiscall *)(IVP_Friction_System *, int))v5->dtr_IVP_Controller)(a1: v5, a2: 1);
    *(_DWORD *)es->sim_unit = *(_DWORD *)es->sim_unit & 0xFFFFFCFF | 0x100;
  }
}
