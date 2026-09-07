// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_intern/ivp_friction_gaps.cxx
// Functions: 15
// ============================================================

#include "ivp\ivp_intern\ivp_friction_gaps.h"

//------------------------------------------------------------------------------
// Address: 0x1009EED0
// Name: public: static void IVP_Friction_Solver::async_apply_impulse(class IVP_Impact_Solver_Long_Term const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Friction_Solver::async_apply_impulse(const IVP_Impact_Solver_Long_Term *info, float impulse)
{
  float v2; // xmm3_4
  IVP_Core *v3; // ecx
  float v4; // xmm1_4
  float v5; // xmm4_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm2_4
  IVP_Core *v9; // ecx
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4

  v2 = impulse;
  v3 = info->contact_core[0];
  if ( v3 != nullptr )
  {
    v4 = info->contact_cross_nomal_cs[0].k[2] * v3->inv_rot_inertia.k[2];
    v5 = info->contact_cross_nomal_cs[0].k[0] * v3->inv_rot_inertia.k[0];
    v3->rot_speed_change.k[1] = (float)((float)(info->contact_cross_nomal_cs[0].k[1] * v3->inv_rot_inertia.k[1])
                                      * (float)-impulse)
                              + v3->rot_speed_change.k[1];
    v3->rot_speed_change.k[2] = (float)(v4 * (float)-impulse) + v3->rot_speed_change.k[2];
    v3->rot_speed_change.k[0] = (float)((float)-impulse * v5) + v3->rot_speed_change.k[0];
    v6 = -(float)(v3->inv_rot_inertia.hesse_val * impulse);
    v7 = (float)(info->surf_normal.k[1] * v6) + v3->speed_change.k[1];
    v8 = (float)(info->surf_normal.k[2] * v6) + v3->speed_change.k[2];
    v3->speed_change.k[0] = (float)(info->surf_normal.k[0] * v6) + v3->speed_change.k[0];
    v3->speed_change.k[1] = v7;
    v3->speed_change.k[2] = v8;
    IVP_Core::apply_velocity_limit(this: v3);
    v2 = impulse;
  }
  v9 = info->contact_core[1];
  if ( v9 != nullptr )
  {
    v10 = info->contact_cross_nomal_cs[1].k[0] * v9->inv_rot_inertia.k[0];
    v11 = info->contact_cross_nomal_cs[1].k[2] * v9->inv_rot_inertia.k[2];
    v9->rot_speed_change.k[1] = (float)((float)(info->contact_cross_nomal_cs[1].k[1] * v9->inv_rot_inertia.k[1]) * v2)
                              + v9->rot_speed_change.k[1];
    v9->rot_speed_change.k[2] = (float)(v11 * v2) + v9->rot_speed_change.k[2];
    v9->rot_speed_change.k[0] = (float)(v10 * v2) + v9->rot_speed_change.k[0];
    v12 = v9->inv_rot_inertia.hesse_val * v2;
    v13 = (float)(info->surf_normal.k[1] * v12) + v9->speed_change.k[1];
    v14 = (float)(info->surf_normal.k[2] * v12) + v9->speed_change.k[2];
    v9->speed_change.k[0] = (float)(info->surf_normal.k[0] * v12) + v9->speed_change.k[0];
    v9->speed_change.k[1] = v13;
    v9->speed_change.k[2] = v14;
    IVP_Core::apply_velocity_limit(this: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009F090
// Name: public: void IVP_Friction_Solver::factor_result_vec(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Friction_Solver::factor_result_vec(IVP_Friction_Solver *this)
{
  int v1; // eax
  float *result_vector; // edx
  float v3; // xmm0_4
  float *v4; // edx
  float *v5; // edx
  float v6; // xmm0_4
  float *v7; // edx

  v1 = this->dist_change_mat.columns - 1;
  if ( v1 >= 0 )
  {
    if ( this->dist_change_mat.columns >= 4 )
    {
      do
      {
        this->dist_change_mat.result_vector[v1] = this->dist_change_mat.result_vector[v1] * this->correct_x_factor;
        this->dist_change_mat.result_vector[v1 - 1] = this->dist_change_mat.result_vector[v1 - 1]
                                                    * this->correct_x_factor;
        this->dist_change_mat.result_vector[v1 - 2] = this->correct_x_factor
                                                    * this->dist_change_mat.result_vector[v1 - 2];
        result_vector = this->dist_change_mat.result_vector;
        v3 = this->correct_x_factor * result_vector[v1 - 3];
        v4 = &result_vector[v1 - 3];
        v1 -= 4;
        *v4 = v3;
      }
      while ( v1 >= 3 );
    }
    for ( ; v1 >= 0; *v7 = v6 )
    {
      v5 = this->dist_change_mat.result_vector;
      v6 = v5[v1] * this->correct_x_factor;
      v7 = &v5[v1--];
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009F130
// Name: public: void IVP_Friction_Solver::normize_constraint_equ(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Friction_Solver::normize_constraint_equ(IVP_Friction_Solver *this)
{
  float v1; // xmm0_4
  int columns; // edi
  int v3; // ebx
  float v4; // xmm1_4
  int aligned_row_len; // edi
  float *matrix_values; // edx
  int v7; // esi
  int v8; // eax
  float *v9; // edi
  unsigned int v10; // edx
  float *v11; // edi
  int v12; // eax
  int v13; // eax
  int v14; // edx
  float *v15; // eax
  float v16; // xmm3_4
  float v17; // xmm4_4
  int v18; // eax
  unsigned int v19; // edx
  float *v20; // esi
  float v21; // xmm1_4
  float v22; // xmm1_4
  float v23; // xmm1_4
  float v24; // xmm1_4
  float *v25; // edx
  float v26; // xmm1_4
  int v27; // ebx
  float *v28; // edx
  int j; // eax
  int v30; // eax
  float *v31; // edx
  float *v32; // edx
  float *desired_vector; // edx
  float v34; // xmm0_4
  float *v35; // edx
  int i; // [esp+4h] [ebp-14h]
  unsigned int v37; // [esp+8h] [ebp-10h]
  float *v38; // [esp+Ch] [ebp-Ch]
  int v39; // [esp+10h] [ebp-8h]
  float *v40; // [esp+10h] [ebp-8h]
  float *v41; // [esp+14h] [ebp-4h]

  v1 = 0.0;
  columns = this->dist_change_mat.columns;
  v3 = columns - 1;
  v4 = 0.0;
  i = columns - 1;
  if ( columns - 1 < 0 )
    goto LABEL_21;
  v37 = this->dist_change_mat.columns;
  if ( columns >= 4 )
  {
    aligned_row_len = this->dist_change_mat.aligned_row_len;
    matrix_values = this->dist_change_mat.matrix_values;
    v39 = 4 * aligned_row_len;
    v7 = v3 * (4 * aligned_row_len + 4);
    v8 = -1 - aligned_row_len;
    v41 = (float *)((char *)matrix_values + v7);
    v38 = (float *)((char *)matrix_values + v7 + -12 * aligned_row_len - 12);
    v9 = &matrix_values[-2 * aligned_row_len - 2];
    v40 = (float *)((char *)&matrix_values[v39 / 0xFFFFFFFC - 1] + v7);
    v10 = v37 >> 2;
    v11 = (float *)((char *)v9 + v7);
    v12 = 16 * v8;
    v3 = i - 4 * (v37 >> 2);
    do
    {
      if ( *v41 > v4 )
        v4 = *v41;
      if ( *v40 > v4 )
        v4 = *v40;
      if ( *v11 > v4 )
        v4 = *v11;
      if ( *v38 > v4 )
        v4 = *v38;
      v41 = (float *)((char *)v41 + v12);
      v40 = (float *)((char *)v40 + v12);
      v38 = (float *)((char *)v38 + v12);
      v11 = (float *)((char *)v11 + v12);
      --v10;
    }
    while ( v10 != 0 );
    columns = this->dist_change_mat.columns;
  }
  if ( v3 >= 0 )
  {
    v13 = 4 * this->dist_change_mat.aligned_row_len;
    v14 = -4 - v13;
    v15 = (float *)((char *)this->dist_change_mat.matrix_values + v3 * (v13 + 4));
    do
    {
      if ( *v15 > v4 )
        v4 = *v15;
      v15 = (float *)((char *)v15 + v14);
      --v3;
    }
    while ( v3 >= 0 );
  }
  if ( v4 <= 1.0e-10 )
  {
LABEL_21:
    v16 = 1.0;
    v17 = 1.0;
  }
  else
  {
    v16 = 1.0;
    v17 = 1.0 / v4;
  }
  v18 = columns - 1;
  this->correct_x_factor = v17;
  if ( columns - 1 < 0 )
    goto LABEL_41;
  if ( columns >= 4 )
  {
    v19 = (unsigned int)columns >> 2;
    v20 = &this->dist_change_mat.desired_vector[v18 - 2];
    v18 -= 4 * ((unsigned int)columns >> 2);
    do
    {
      v21 = fabs(v20[2]);
      if ( v21 > v1 )
        v1 = v21;
      v22 = fabs(v20[1]);
      if ( v22 > v1 )
        v1 = v22;
      v23 = fabs(*v20);
      if ( v23 > v1 )
        v1 = v23;
      v24 = fabs(*(v20 - 1));
      if ( v24 > v1 )
        v1 = v24;
      v20 -= 4;
      --v19;
    }
    while ( v19 != 0 );
  }
  if ( v18 >= 0 )
  {
    v25 = &this->dist_change_mat.desired_vector[v18];
    do
    {
      v26 = fabs(*v25);
      if ( v26 > v1 )
        v1 = v26;
      --v25;
      --v18;
    }
    while ( v18 >= 0 );
  }
  if ( v1 <= 1.0e-10 )
LABEL_41:
    v1 = 1.0;
  else
    v16 = 1.0 / v1;
  v27 = 0;
  this->correct_x_factor = v17 * v1;
  if ( columns > 0 )
  {
    do
    {
      v28 = &this->dist_change_mat.matrix_values[v27 * this->dist_change_mat.aligned_row_len];
      for ( j = 0; j < this->dist_change_mat.aligned_row_len; ++j )
        v28[j] = v28[j] * v17;
      ++v27;
    }
    while ( v27 < this->dist_change_mat.columns );
  }
  v30 = this->dist_change_mat.columns - 1;
  if ( v30 >= 0 )
  {
    if ( this->dist_change_mat.columns >= 4 )
    {
      do
      {
        this->dist_change_mat.desired_vector[v30] = this->dist_change_mat.desired_vector[v30] * v16;
        this->dist_change_mat.desired_vector[v30 - 1] = this->dist_change_mat.desired_vector[v30 - 1] * v16;
        v31 = &this->dist_change_mat.desired_vector[v30 - 2];
        *v31 = v16 * *v31;
        v32 = &this->dist_change_mat.desired_vector[v30 - 3];
        v30 -= 4;
        *v32 = v16 * *v32;
      }
      while ( v30 >= 3 );
    }
    for ( ; v30 >= 0; *v35 = v34 * v16 )
    {
      desired_vector = this->dist_change_mat.desired_vector;
      v34 = desired_vector[v30];
      v35 = &desired_vector[v30--];
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009F3F0
// Name: public: int IVP_Friction_Solver::do_resulting_pushes(class IVP_Friction_System __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_Friction_Solver::do_resulting_pushes(IVP_Friction_Solver *this, IVP_Friction_System *fs)
{
  IVP_Contact_Point *first_friction_dist; // esi
  int v3; // edi
  float impulse; // xmm0_4
  int v6; // eax
  __int16 v7; // cx
  float now_friction_pressure; // xmm0_4

  first_friction_dist = fs->first_friction_dist;
  v3 = 0;
  while ( first_friction_dist != nullptr )
  {
    if ( v3 < fs->complex_not_necessary_number )
    {
LABEL_16:
      impulse = 0.0;
      goto no_complex_done;
    }
    impulse = this->dist_change_mat.result_vector[v3];
    if ( impulse <= 0.0 )
    {
      if ( impulse == 0.0 )
      {
        now_friction_pressure = first_friction_dist->now_friction_pressure;
        *((_WORD *)&first_friction_dist->IVP_Contact_Point_Fast + 47) = 0;
        impulse = (float)(now_friction_pressure * 0.0) * this->es->delta_time;
        goto cont_for_next;
      }
      if ( *((int *)&first_friction_dist->IVP_Contact_Point_Fast + 23) < 0 )
        *((_WORD *)&first_friction_dist->IVP_Contact_Point_Fast + 47) = 0;
      ++*((_WORD *)&first_friction_dist->IVP_Contact_Point_Fast + 47);
      if ( (int)(*((_DWORD *)&first_friction_dist->IVP_Contact_Point_Fast + 23) & 0xFFFF0000) > 589824 )
      {
        v7 = 0;
        goto LABEL_13;
      }
    }
    else
    {
      v6 = *((__int16 *)&first_friction_dist->IVP_Contact_Point_Fast + 47);
      if ( v6 >= 0 )
      {
        v7 = -1;
LABEL_13:
        *((_WORD *)&first_friction_dist->IVP_Contact_Point_Fast + 47) = v7;
        goto LABEL_14;
      }
      *((_WORD *)&first_friction_dist->IVP_Contact_Point_Fast + 47) = v6 - 1;
    }
LABEL_14:
    IVP_Friction_Solver::async_apply_impulse(info: first_friction_dist->tmp_contact_info, impulse);
cont_for_next:
    if ( impulse < 0.0 )
      goto LABEL_16;
no_complex_done:
    first_friction_dist->now_friction_pressure = this->es->i_delta_time * impulse;
    first_friction_dist = first_friction_dist->next_dist_in_friction;
    ++v3;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1009F4E0
// Name: public: void IVP_Friction_System::reorder_mindists_for_complex(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Friction_System::reorder_mindists_for_complex(IVP_Friction_System *this)
{
  IVP_Contact_Point *first_friction_dist; // esi
  float last_gap_len; // xmm0_4
  IVP_Contact_Point *next_dist_in_friction; // edi

  first_friction_dist = this->first_friction_dist;
  if ( first_friction_dist != nullptr )
  {
    do
    {
      last_gap_len = first_friction_dist->last_gap_len;
      next_dist_in_friction = first_friction_dist->next_dist_in_friction;
      if ( last_gap_len >= ivp_mindist_settings.max_distance_for_friction
        || first_friction_dist->tmp_contact_info->friction_is_broken == 1 )
      {
        IVP_Friction_System::delete_friction_distance(this, old_dist: first_friction_dist);
      }
      else if ( last_gap_len > (float)(ivp_mindist_settings.distance_keepers_safety + ivp_mindist_settings.friction_dist)
             && (*(_BYTE *)&first_friction_dist->synapse[0].l_obj->friction_core->IVP_Core_Fast_Static
               & *(_BYTE *)&first_friction_dist->synapse[1].l_obj->friction_core->IVP_Core_Fast_Static
               & 1) != 0 )
      {
        IVP_Friction_System::remove_dist_from_system(this, old_dist: first_friction_dist);
        IVP_Friction_System::add_dist_to_system(this, new_dist: first_friction_dist);
      }
      first_friction_dist = next_dist_in_friction;
    }
    while ( next_dist_in_friction != nullptr );
    this->complex_not_necessary_number = 0;
  }
  else
  {
    this->complex_not_necessary_number = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009F570
// Name: public: void IVP_Friction_System::bubble_sort_dists_importance(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Friction_System::bubble_sort_dists_importance(IVP_Friction_System *this)
{
  IVP_Contact_Point *first_friction_dist; // edi
  IVP_Contact_Point *i; // eax
  IVP_Contact_Point *prev_dist_in_friction; // edx
  IVP_Contact_Point *v4; // edx
  IVP_Contact_Point **p_next_dist_in_friction; // esi

  first_friction_dist = this->first_friction_dist;
  if ( first_friction_dist != nullptr )
  {
    for ( i = first_friction_dist->next_dist_in_friction; i != nullptr; i = i->next_dist_in_friction )
    {
      if ( (int)(*((_DWORD *)&first_friction_dist->IVP_Contact_Point_Fast + 23) & 0xFFFF0000) > (int)(*((_DWORD *)&i->IVP_Contact_Point_Fast + 23) & 0xFFFF0000) )
      {
        if ( this->first_friction_dist == first_friction_dist )
          this->first_friction_dist = i;
        prev_dist_in_friction = first_friction_dist->prev_dist_in_friction;
        if ( prev_dist_in_friction != nullptr )
          prev_dist_in_friction->next_dist_in_friction = i;
        if ( i->next_dist_in_friction != nullptr )
          i->next_dist_in_friction->prev_dist_in_friction = first_friction_dist;
        first_friction_dist->next_dist_in_friction = i->next_dist_in_friction;
        i->prev_dist_in_friction = first_friction_dist->prev_dist_in_friction;
        first_friction_dist->prev_dist_in_friction = i;
        v4 = i->prev_dist_in_friction;
        for ( i->next_dist_in_friction = first_friction_dist; v4 != nullptr; v4 = i->prev_dist_in_friction )
        {
          if ( (int)(*((_DWORD *)&v4->IVP_Contact_Point_Fast + 23) & 0xFFFF0000) <= (int)(*((_DWORD *)&i->IVP_Contact_Point_Fast
                                                                                          + 23)
                                                                                        & 0xFFFF0000) )
            break;
          if ( this->first_friction_dist == v4 )
            this->first_friction_dist = i;
          p_next_dist_in_friction = &v4->prev_dist_in_friction->IVP_Contact_Point_Fast::IVP_Contact_Point_Fast_Static::next_dist_in_friction;
          if ( p_next_dist_in_friction != nullptr )
            *p_next_dist_in_friction = i;
          if ( i->next_dist_in_friction != nullptr )
            i->next_dist_in_friction->prev_dist_in_friction = v4;
          v4->next_dist_in_friction = i->next_dist_in_friction;
          i->prev_dist_in_friction = v4->prev_dist_in_friction;
          v4->prev_dist_in_friction = i;
          i->next_dist_in_friction = v4;
        }
        i = first_friction_dist;
      }
      first_friction_dist = i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009F640
// Name: public: enum IVP_RETURN_TYPE IVP_Friction_Solver::test_gauss_solution_suggestion(float __near *,int __near *,int,class IVP_U_Memory __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall IVP_Friction_Solver::test_gauss_solution_suggestion(
        IVP_Friction_Solver *this,
        float *push_results,
        int *active_is_at_pos,
        int total_actives,
        IVP_U_Memory *mem_friction)
{
  unsigned int v6; // edx
  char *speicherbeginn; // edi
  char *v8; // eax
  int v9; // eax
  int *v10; // ebx
  float *v11; // ecx
  int v12; // edx
  float *v13; // eax
  int *v14; // edx
  int v15; // ecx
  float v16; // xmm1_4
  int v17; // ecx
  float v18; // xmm1_4
  int v19; // ecx
  float v20; // xmm1_4
  int v21; // ecx
  float v22; // xmm1_4
  bool v23; // zf
  int v24; // ebx
  float *v25; // ecx
  int v26; // edx
  int v27; // eax
  float v28; // xmm1_4
  int v29; // ebx
  int i; // [esp+Ch] [ebp-Ch]
  unsigned int v32; // [esp+10h] [ebp-8h]
  int v33; // [esp+14h] [ebp-4h]
  int gauss_failed; // [esp+2Ch] [ebp+14h]

  v6 = 4 * this->dist_change_mat.columns;
  speicherbeginn = mem_friction->speicherbeginn;
  v8 = (char *)((unsigned int)&speicherbeginn[v6 + 31] & 0xFFFFFFE0);
  if ( v8 < mem_friction->speicherende )
    mem_friction->speicherbeginn = v8;
  else
    speicherbeginn = IVP_U_Memory::neuer_sp_block(this: mem_friction, groesse: v6);
  memset(dst: (unsigned __int8 *)speicherbeginn, value: 0, count: 4 * this->dist_change_mat.columns);
  v9 = total_actives;
  v10 = active_is_at_pos;
  v11 = push_results;
  v12 = 0;
  gauss_failed = 0;
  if ( total_actives >= 4 )
  {
    v13 = push_results + 1;
    v14 = active_is_at_pos + 3;
    v32 = ((unsigned int)(total_actives - 4) >> 2) + 1;
    i = 4 * v32;
    do
    {
      v15 = *(v14 - 3);
      v16 = *(v13 - 1);
      if ( (float)(this->l_environment->gravity_scalar * 0.0099999998) > (float)((float)(this->correct_x_factor * v16)
                                                                               * *((float *)this->contact_info_vector.elems[v15]
                                                                                 + 27)) )
        gauss_failed = 1;
      *(_DWORD *)&speicherbeginn[4 * v15] = 1;
      this->dist_change_mat.result_vector[v15] = v16;
      v17 = *(_DWORD *)((char *)v13 + (char *)active_is_at_pos - (char *)push_results);
      v18 = *v13;
      if ( (float)(this->l_environment->gravity_scalar * 0.0099999998) > (float)((float)(this->correct_x_factor * *v13)
                                                                               * *((float *)this->contact_info_vector.elems[v17]
                                                                                 + 27)) )
        gauss_failed = 1;
      *(_DWORD *)&speicherbeginn[4 * v17] = 1;
      this->dist_change_mat.result_vector[v17] = v18;
      v19 = *(v14 - 1);
      v20 = v13[1];
      if ( (float)(this->l_environment->gravity_scalar * 0.0099999998) > (float)((float)(this->correct_x_factor * v20)
                                                                               * *((float *)this->contact_info_vector.elems[v19]
                                                                                 + 27)) )
        gauss_failed = 1;
      *(_DWORD *)&speicherbeginn[4 * v19] = 1;
      this->dist_change_mat.result_vector[v19] = v20;
      v21 = *v14;
      v22 = v13[2];
      if ( (float)(this->l_environment->gravity_scalar * 0.0099999998) > (float)((float)(this->correct_x_factor * v22)
                                                                               * *((float *)this->contact_info_vector.elems[*v14]
                                                                                 + 27)) )
        gauss_failed = 1;
      *(_DWORD *)&speicherbeginn[4 * v21] = 1;
      v13 += 4;
      v14 += 4;
      v23 = v32-- == 1;
      this->dist_change_mat.result_vector[v21] = v22;
    }
    while ( !v23 );
    v12 = i;
    v11 = push_results;
    v10 = active_is_at_pos;
    v9 = total_actives;
  }
  if ( v12 < v9 )
  {
    v24 = (char *)v10 - (char *)push_results;
    v25 = &v11[v12];
    v33 = v24;
    v26 = v9 - v12;
    while ( 1 )
    {
      v27 = *(_DWORD *)((char *)v25 + v24);
      v28 = *v25;
      if ( (float)(this->l_environment->gravity_scalar * 0.0099999998) > (float)((float)(this->correct_x_factor * *v25)
                                                                               * *((float *)this->contact_info_vector.elems[v27]
                                                                                 + 27)) )
        gauss_failed = 1;
      *(_DWORD *)&speicherbeginn[4 * v27] = 1;
      ++v25;
      --v26;
      this->dist_change_mat.result_vector[v27] = v28;
      if ( v26 == 0 )
        break;
      v24 = v33;
    }
  }
  v29 = 0;
  if ( this->dist_change_mat.columns <= 0 )
    return gauss_failed == 0;
  while ( *(_DWORD *)&speicherbeginn[4 * v29] != 0
       || IVP_Great_Matrix_Many_Zero::matrix_check_unequation_line(this: &this->dist_change_mat, linenum: v29) )
  {
    if ( ++v29 >= this->dist_change_mat.columns )
      return gauss_failed == 0;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1009F8B0
// Name: public: void IVP_Friction_Solver::calc_distance_matrix_column(int,class IVP_Core __near *,class IVP_Friction_Info_For_Core __near *,class IVP_U_Float_Point __near *,class IVP_U_Float_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Friction_Solver::calc_distance_matrix_column(
        IVP_Friction_Solver *this,
        int current_contact_point_index,
        IVP_Core *core,
        IVP_Friction_Info_For_Core *fr_info,
        IVP_U_Float_Point *rotation_vec,
        IVP_U_Float_Point *translation_vec)
{
  IVP_Friction_Info_For_Core *v6; // edx
  int v7; // eax
  int v8; // esi
  IVP_Core **v9; // edx
  int v10; // eax
  float v11; // xmm0_4
  int v12; // eax
  float *v13; // esi
  int col; // [esp+4h] [ebp-8h]
  IVP_Friction_Solver *v15; // [esp+8h] [ebp-4h]

  v6 = fr_info;
  v7 = 0;
  v15 = this;
  col = 0;
  if ( fr_info->friction_springs.n_elems != 0 )
  {
    do
    {
      v8 = *(__int16 *)(*((_DWORD *)v6->friction_springs.elems[v7] + 16) + 80);
      if ( v8 >= 0 )
      {
        v9 = (IVP_Core **)this->contact_info_vector.elems[v8];
        if ( v9[28] == core )
        {
          v10 = 0;
          v11 = -1.0;
        }
        else
        {
          v11 = 1.0;
          v10 = 1;
        }
        if ( v9[v10 + 28] != nullptr )
        {
          v12 = 2 * (v10 + 12);
          v13 = &v15->dist_change_mat.matrix_values[current_contact_point_index
                                                  + v8 * this->dist_change_mat.aligned_row_len];
          this = v15;
          *v13 = (float)((float)((float)((float)((float)(*(float *)&v9[2 * v12 + 1] * rotation_vec->k[1])
                                               + (float)(*(float *)&v9[2 * v12] * rotation_vec->k[0]))
                                       + (float)(*(float *)&v9[2 * v12 + 2] * rotation_vec->k[2]))
                               + (float)((float)((float)(*((float *)v9 + 5) * translation_vec->k[1])
                                               + (float)(*((float *)v9 + 4) * translation_vec->k[0]))
                                       + (float)(*((float *)v9 + 6) * translation_vec->k[2])))
                       * v11)
               + *v13;
        }
      }
      v6 = fr_info;
      v7 = col + 1;
      col = v7;
    }
    while ( v7 < fr_info->friction_springs.n_elems );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009F9C0
// Name: public: int IVP_Friction_Solver::calc_solver_PSI(class IVP_Friction_System __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __userpurge IVP_Friction_Solver::calc_solver_PSI@<eax>(
        IVP_Friction_Solver *this@<ecx>,
        int a2@<ebp>,
        IVP_Friction_System *fs,
        int *active_is_at_pos)
{
  int v5; // eax
  int hesse_val_low; // eax
  void *v7; // esi
  float *v8; // ecx
  float v9; // xmm2_4
  float *v10; // ecx
  float v11; // xmm1_4
  float v12; // xmm0_4
  IVP_Core *v13; // ecx
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm0_4
  IVP_Friction_Info_For_Core *v18; // edx
  float v19; // xmm1_4
  IVP_Core *v20; // ecx
  float v21; // xmm1_4
  IVP_Friction_Info_For_Core *v22; // edx
  float hesse_val; // xmm0_4
  int n_elems; // ecx
  IVP_Contact_Point *first_friction_dist; // esi
  int j; // edi
  __int16 index_in_fs; // ax
  IVP_U_Float_Point v29; // [esp-Ch] [ebp-5Ch] BYREF
  IVP_U_Float_Point v30; // [esp+4h] [ebp-4Ch] BYREF
  float v31[3]; // [esp+14h] [ebp-3Ch] BYREF
  IVP_U_Float_Point rotation_vec; // [esp+20h] [ebp-30h] BYREF
  IVP_U_Float_Point translation_vec; // [esp+30h] [ebp-20h]
  int v34; // [esp+40h] [ebp-10h]
  int v35; // [esp+44h] [ebp-Ch]
  int i; // [esp+48h] [ebp-8h]
  int retaddr; // [esp+50h] [ebp+0h]

  v35 = a2;
  i = retaddr;
  v5 = this->dist_change_mat.columns * this->dist_change_mat.aligned_row_len - 1;
  if ( v5 >= 0 )
  {
    if ( this->dist_change_mat.columns * this->dist_change_mat.aligned_row_len >= 4 )
    {
      do
      {
        this->dist_change_mat.matrix_values[v5] = 0.0;
        this->dist_change_mat.matrix_values[v5 - 1] = 0.0;
        this->dist_change_mat.matrix_values[v5 - 2] = 0.0;
        this->dist_change_mat.matrix_values[v5 - 3] = 0.0;
        v5 -= 4;
      }
      while ( v5 >= 3 );
    }
    for ( ; v5 >= 0; this->dist_change_mat.matrix_values[v5 + 1] = 0.0 )
      --v5;
  }
  hesse_val_low = 0;
  v34 = 0;
  translation_vec.hesse_val = 0.0;
  if ( this->contact_info_vector.n_elems != 0 )
  {
    do
    {
      v7 = this->contact_info_vector.elems[hesse_val_low];
      v8 = *((float **)v7 + 28);
      v9 = 0.0;
      if ( v8 != nullptr )
        v9 = (float)((float)((float)(*((float *)v7 + 5) * v8[53]) + (float)(*((float *)v7 + 4) * v8[52]))
                   + (float)(*((float *)v7 + 6) * v8[54]))
           + (float)((float)((float)(*((float *)v7 + 49) * v8[49]) + (float)(*((float *)v7 + 48) * v8[48]))
                   + (float)(*((float *)v7 + 50) * v8[50]));
      v10 = *((float **)v7 + 29);
      if ( v10 != nullptr )
        v9 = v9
           - (float)((float)((float)((float)(*((float *)v7 + 53) * v10[49]) + (float)(v10[48] * *((float *)v7 + 52)))
                           + (float)(*((float *)v7 + 54) * v10[50]))
                   + (float)((float)((float)(*((float *)v7 + 5) * v10[53]) + (float)(*((float *)v7 + 4) * v10[52]))
                           + (float)(*((float *)v7 + 6) * v10[54])));
      v11 = ivp_mindist_settings.friction_dist - *((float *)v7 + 25);
      v12 = 1.0;
      if ( v11 < 0.0 )
        v12 = 20.0;
      this->dist_change_mat.desired_vector[hesse_val_low] = (float)(v12 * v11) + v9;
      if ( *((_DWORD *)v7 + 24) != 0 )
      {
        *active_is_at_pos = hesse_val_low;
        ++v34;
        ++active_is_at_pos;
      }
      v13 = *((IVP_Core **)v7 + 28);
      if ( v13 != nullptr )
      {
        v14 = *((float *)v7 + 48) * v13->inv_rot_inertia.k[0];
        v15 = *((float *)v7 + 50) * v13->inv_rot_inertia.k[2];
        v31[1] = -(float)(*((float *)v7 + 49) * v13->inv_rot_inertia.k[1]);
        v16 = *((float *)v7 + 4);
        v31[0] = -v14;
        v17 = v13->inv_rot_inertia.hesse_val * -1.0;
        v18 = *((IVP_Friction_Info_For_Core **)v7 + 22);
        rotation_vec.k[1] = v16 * v17;
        rotation_vec.k[2] = *((float *)v7 + 5) * v17;
        v19 = *((float *)v7 + 6) * v17;
        v31[2] = -v15;
        rotation_vec.hesse_val = v19;
        IVP_Friction_Solver::calc_distance_matrix_column(
          this,
          current_contact_point_index: hesse_val_low,
          core: v13,
          fr_info: v18,
          rotation_vec: (IVP_U_Float_Point *)v31,
          translation_vec: (IVP_U_Float_Point *)&rotation_vec.k[1]);
        hesse_val_low = LODWORD(translation_vec.hesse_val);
      }
      v20 = *((IVP_Core **)v7 + 29);
      if ( v20 != nullptr )
      {
        v21 = *((float *)v7 + 4);
        v29.k[0] = v20->inv_rot_inertia.k[0] * *((float *)v7 + 52);
        v29.k[1] = *((float *)v7 + 53) * v20->inv_rot_inertia.k[1];
        v22 = *((IVP_Friction_Info_For_Core **)v7 + 23);
        v29.k[2] = *((float *)v7 + 54) * v20->inv_rot_inertia.k[2];
        hesse_val = v20->inv_rot_inertia.hesse_val;
        v30.k[0] = v21 * hesse_val;
        v30.k[1] = *((float *)v7 + 5) * hesse_val;
        v30.k[2] = *((float *)v7 + 6) * hesse_val;
        IVP_Friction_Solver::calc_distance_matrix_column(
          this,
          current_contact_point_index: hesse_val_low,
          core: v20,
          fr_info: v22,
          rotation_vec: &v29,
          translation_vec: &v30);
        hesse_val_low = LODWORD(translation_vec.hesse_val);
      }
      n_elems = this->contact_info_vector.n_elems;
      LODWORD(translation_vec.hesse_val) = ++hesse_val_low;
    }
    while ( hesse_val_low < n_elems );
  }
  first_friction_dist = fs->first_friction_dist;
  for ( j = 0; first_friction_dist != nullptr; ++j )
  {
    index_in_fs = first_friction_dist->tmp_contact_info->index_in_fs;
    if ( index_in_fs >= 0 && index_in_fs != j )
      _Error(a1: "IVP Failed at %s %d\n", "..\\ivp_intern\\ivp_friction_gaps.cxx", 934);
    first_friction_dist = first_friction_dist->next_dist_in_friction;
  }
  return v34;
}

//------------------------------------------------------------------------------
// Address: 0x1009FD20
// Name: public: void IVP_Friction_System::static_fr_oversized_matrix_panic(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Friction_System::static_fr_oversized_matrix_panic(IVP_Friction_System *this)
{
  int v1; // eax
  _DWORD *v2; // edx
  int v3; // eax
  void **v4; // ebx
  _DWORD **v5; // esi
  _BYTE *v6; // edi
  int i; // [esp+0h] [ebp-Ch]
  IVP_Friction_System *v8; // [esp+4h] [ebp-8h]
  int v9; // [esp+8h] [ebp-4h]

  v1 = this->moveable_cores_of_friction_system.n_elems - 1;
  v8 = this;
  i = v1;
  if ( this->moveable_cores_of_friction_system.n_elems != 0 )
  {
    do
    {
      v2 = this->moveable_cores_of_friction_system.elems[v1];
      *(_WORD *)v2 |= 1u;
      v3 = this->fr_pairs_of_objs.n_elems - 1;
      v9 = 0;
      if ( this->fr_pairs_of_objs.n_elems != 0 )
      {
        v4 = &this->fr_pairs_of_objs.elems[v3];
        do
        {
          v5 = (_DWORD **)*v4;
          v6 = *((_BYTE **)*v4 + 13);
          if ( (v6 == (_BYTE *)v2 || v5[14] == v2) && ((*v6 | *(_BYTE *)v5[14]) & 2) == 0 )
            ++v9;
          --v4;
          --v3;
        }
        while ( v3 >= 0 );
        this = v8;
        if ( v9 > 1 )
        {
          v2[54] = 0;
          v2[53] = 0;
          v2[52] = 0;
          v2[50] = 0;
          v2[49] = 0;
          v2[48] = 0;
        }
      }
      v1 = --i;
    }
    while ( i >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009FDD0
// Name: public: float IVP_Friction_System::kinetic_energy_of_hole_frs(void)
// Source: json
//------------------------------------------------------------------------------
double __usercall IVP_Friction_System::kinetic_energy_of_hole_frs@<st0>(IVP_Friction_System *this@<ecx>, int a2@<ebp>)
{
  bool v3; // sf
  int v4; // esi
  double result; // st7
  IVP_Core *v6; // ecx
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm1_4
  double energy_on_test; // st7
  float v12[3]; // [esp-Ch] [ebp-3Ch] BYREF
  IVP_U_Float_Point speed_vec; // [esp+0h] [ebp-30h] BYREF
  float v14; // [esp+20h] [ebp-10h]
  int v15; // [esp+24h] [ebp-Ch]
  void *v16; // [esp+28h] [ebp-8h]
  void *retaddr; // [esp+30h] [ebp+0h]

  v15 = a2;
  v16 = retaddr;
  v4 = this->cores_of_friction_system.n_elems - 1;
  v3 = this->cores_of_friction_system.n_elems == 0;
  v14 = 0.0;
  if ( v3 )
    return v14;
  do
  {
    v6 = (IVP_Core *)this->cores_of_friction_system.elems[v4];
    v7 = v6->speed.k[1] + v6->speed_change.k[1];
    v8 = v6->speed.k[2] + v6->speed_change.k[2];
    v12[0] = v6->speed_change.k[0] + v6->speed.k[0];
    v12[1] = v7;
    v12[2] = v8;
    v9 = v6->rot_speed.k[1] + v6->rot_speed_change.k[1];
    v10 = v6->rot_speed.k[2] + v6->rot_speed_change.k[2];
    speed_vec.k[1] = v6->rot_speed.k[0] + v6->rot_speed_change.k[0];
    speed_vec.k[2] = v9;
    speed_vec.hesse_val = v10;
    energy_on_test = IVP_Core::get_energy_on_test(
                       this: v6,
                       speed_vec: (const IVP_U_Float_Point *)v12,
                       rot_speed_vec: (IVP_U_Float_Point *)&speed_vec.k[1]);
    result = energy_on_test + v14;
    --v4;
    v14 = result;
  }
  while ( v4 >= 0 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009FEC0
// Name: public: float IVP_Friction_System::get_max_energy_gain(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall IVP_Friction_System::get_max_energy_gain(IVP_Friction_System *this)
{
  IVP_Environment *l_environment; // eax
  int v2; // edx
  float gravity_scalar; // xmm2_4
  float v4; // xmm1_4
  float min_friction_mass; // xmm3_4
  int v6; // esi
  void **v7; // eax
  float *v8; // edi
  float v9; // xmm0_4
  float *v10; // edi
  float v11; // xmm0_4
  float v12; // xmm0_4
  int v13; // edi
  float v14; // xmm0_4
  void **v15; // eax
  float v16; // xmm0_4
  float sum_gain; // [esp+0h] [ebp-4h]

  l_environment = this->l_environment;
  v2 = this->cores_of_friction_system.n_elems - 1;
  gravity_scalar = l_environment->gravity_scalar;
  v4 = 0.0;
  sum_gain = 0.0;
  min_friction_mass = l_environment->anomaly_limits->min_friction_mass;
  if ( this->cores_of_friction_system.n_elems != 0 )
  {
    if ( this->cores_of_friction_system.n_elems >= 4u )
    {
      v6 = this->cores_of_friction_system.n_elems >> 2;
      v7 = &this->cores_of_friction_system.elems[v2 - 2];
      v2 -= 4 * v6;
      do
      {
        v8 = (float *)v7[2];
        if ( (*(_BYTE *)v8 & 2) == 0 )
        {
          v9 = v8[7];
          if ( min_friction_mass <= v9 )
          {
            if ( v9 > min_friction_mass )
              v9 = min_friction_mass;
          }
          else
          {
            v9 = min_friction_mass;
          }
          v4 = (float)((float)(v9 * gravity_scalar) * 0.1) + v4;
        }
        v10 = (float *)v7[1];
        if ( (*(_BYTE *)v10 & 2) == 0 )
        {
          v11 = v10[7];
          if ( min_friction_mass <= v11 )
          {
            if ( v11 > min_friction_mass )
              v11 = min_friction_mass;
          }
          else
          {
            v11 = min_friction_mass;
          }
          v4 = (float)((float)(v11 * gravity_scalar) * 0.1) + v4;
        }
        if ( (*(_BYTE *)*v7 & 2) == 0 )
        {
          v12 = *((float *)*v7 + 7);
          if ( min_friction_mass <= v12 )
          {
            if ( v12 > min_friction_mass )
              v12 = min_friction_mass;
          }
          else
          {
            v12 = min_friction_mass;
          }
          v4 = (float)((float)(v12 * gravity_scalar) * 0.1) + v4;
        }
        v13 = (int)*(v7 - 1);
        if ( (*(_BYTE *)v13 & 2) == 0 )
        {
          v14 = *(float *)(v13 + 28);
          if ( min_friction_mass <= v14 )
          {
            if ( v14 > min_friction_mass )
              v14 = min_friction_mass;
          }
          else
          {
            v14 = min_friction_mass;
          }
          v4 = (float)((float)(v14 * gravity_scalar) * 0.1) + v4;
        }
        v7 -= 4;
        --v6;
      }
      while ( v6 != 0 );
      sum_gain = v4;
    }
    if ( v2 >= 0 )
    {
      v15 = &this->cores_of_friction_system.elems[v2];
      do
      {
        if ( (*(_BYTE *)*v15 & 2) == 0 )
        {
          v16 = *((float *)*v15 + 7);
          if ( min_friction_mass <= v16 )
          {
            if ( v16 > min_friction_mass )
              v16 = min_friction_mass;
          }
          else
          {
            v16 = min_friction_mass;
          }
          v4 = (float)((float)(v16 * gravity_scalar) * 0.1) + v4;
          sum_gain = v4;
        }
        --v15;
        --v2;
      }
      while ( v2 >= 0 );
    }
  }
  return sum_gain;
}

//------------------------------------------------------------------------------
// Address: 0x100A0030
// Name: public: void IVP_Friction_Solver::solve_linear_equation_and_push(class IVP_Friction_System __near *,int __near *,int,class IVP_U_Memory __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Friction_Solver::solve_linear_equation_and_push(
        IVP_Friction_Solver *this@<ecx>,
        double a2@<st0>,
        IVP_Friction_System *my_fs,
        int *active_is_at_pos,
        int total_actives,
        IVP_U_Memory *mem_friction)
{
  int aligned_row_len; // ecx
  char *v9; // eax
  float *v10; // eax
  char *v11; // eax
  float *v12; // eax
  unsigned int v13; // ecx
  char *speicherbeginn; // edx
  char *v15; // eax
  float *v16; // eax
  IVP_Friction_System *v17; // ebx
  IVP_Contact_Point *first_friction_dist; // eax
  int k; // ecx
  double v20; // st6
  double max_energy_gain; // st7
  int n_elems; // esi
  int j; // esi
  int i; // esi
  IVP_Linear_Constraint_Solver constraint_unilateral; // [esp+Ch] [ebp-110h] BYREF
  IVP_Great_Matrix_Many_Zero actives_matrix; // [esp+104h] [ebp-18h] BYREF
  int savedregs; // [esp+11Ch] [ebp+0h] BYREF
  float e_before; // [esp+128h] [ebp+Ch]
  char *total_activesa; // [esp+12Ch] [ebp+10h]
  char *total_activesb; // [esp+12Ch] [ebp+10h]

  IVP_Great_Matrix_Many_Zero::IVP_Great_Matrix_Many_Zero(this: &actives_matrix);
  actives_matrix.columns = total_actives;
  actives_matrix.aligned_row_len = (total_actives + 3) & 0xFFFFFFFC;
  IVP_Friction_Solver::normize_constraint_equ(this);
  aligned_row_len = actives_matrix.aligned_row_len;
  total_activesa = mem_friction->speicherbeginn;
  v9 = (char *)((unsigned int)&total_activesa[4 * actives_matrix.aligned_row_len + 31] & 0xFFFFFFE0);
  if ( v9 < mem_friction->speicherende )
  {
    mem_friction->speicherbeginn = v9;
    v10 = (float *)total_activesa;
  }
  else
  {
    v10 = (float *)IVP_U_Memory::neuer_sp_block(this: mem_friction, groesse: 4 * actives_matrix.aligned_row_len);
    aligned_row_len = actives_matrix.aligned_row_len;
  }
  actives_matrix.desired_vector = v10;
  total_activesb = mem_friction->speicherbeginn;
  v11 = (char *)((unsigned int)&total_activesb[4 * aligned_row_len + 31] & 0xFFFFFFE0);
  if ( v11 < mem_friction->speicherende )
  {
    mem_friction->speicherbeginn = v11;
    v12 = (float *)total_activesb;
  }
  else
  {
    v12 = (float *)IVP_U_Memory::neuer_sp_block(this: mem_friction, groesse: 4 * aligned_row_len);
    aligned_row_len = actives_matrix.aligned_row_len;
  }
  actives_matrix.result_vector = v12;
  v13 = 4 * total_actives * aligned_row_len + 12;
  speicherbeginn = mem_friction->speicherbeginn;
  v15 = (char *)((unsigned int)&speicherbeginn[v13 + 31] & 0xFFFFFFE0);
  if ( v15 < mem_friction->speicherende )
  {
    mem_friction->speicherbeginn = v15;
    v16 = (float *)speicherbeginn;
  }
  else
  {
    v16 = (float *)IVP_U_Memory::neuer_sp_block(this: mem_friction, groesse: v13);
  }
  actives_matrix.matrix_values = v16;
  IVP_Great_Matrix_Many_Zero::align_matrix_values(this: &actives_matrix);
  memset(
    dst: (unsigned __int8 *)this->dist_change_mat.result_vector,
    value: 0,
    count: 4 * this->dist_change_mat.aligned_row_len);
  IVP_Great_Matrix_Many_Zero::fill_from_bigger_matrix(
    this: &actives_matrix,
    big_matrix: &this->dist_change_mat,
    original_pos: active_is_at_pos,
    n_column: total_actives);
  IVP_Great_Matrix_Many_Zero::IVP_Great_Matrix_Many_Zero(this: &constraint_unilateral.sub_solver_mat);
  IVP_Great_Matrix_Many_Zero::IVP_Great_Matrix_Many_Zero(this: &constraint_unilateral.full_solver_mat);
  IVP_Great_Matrix_Many_Zero::IVP_Great_Matrix_Many_Zero(this: &constraint_unilateral.debug_mat);
  IVP_Great_Matrix_Many_Zero::IVP_Great_Matrix_Many_Zero(this: &constraint_unilateral.inv_mat);
  if ( IVP_Great_Matrix_Many_Zero::solve_great_matrix_many_zero(this: &actives_matrix) == 1
    && IVP_Friction_Solver::test_gauss_solution_suggestion(
         this,
         push_results: actives_matrix.result_vector,
         active_is_at_pos,
         total_actives,
         mem_friction) )
  {
    v17 = my_fs;
first_try:
    IVP_Friction_Solver::factor_result_vec(this);
    v20 = IVP_Friction_System::kinetic_energy_of_hole_frs(this: v17, a2: (int)&savedregs);
    e_before = a2;
    IVP_Friction_Solver::do_resulting_pushes(this, fs: v17);
    IVP_Friction_System::kinetic_energy_of_hole_frs(this: v17, a2: (int)&savedregs);
    max_energy_gain = IVP_Friction_System::get_max_energy_gain(this: v17);
    n_elems = v17->moveable_cores_of_friction_system.n_elems;
    if ( v20 + e_before < max_energy_gain )
    {
      for ( i = n_elems - 1; i >= 0; --i )
        IVP_Core::abort_all_async_pushes(this: (IVP_Core *)v17->moveable_cores_of_friction_system.elems[i]);
    }
    else
    {
      for ( j = n_elems - 1; j >= 0; --j )
        IVP_Core::commit_all_async_pushes(this: (IVP_Core *)v17->moveable_cores_of_friction_system.elems[j]);
    }
    return;
  }
  v17 = my_fs;
  first_friction_dist = my_fs->first_friction_dist;
  for ( k = 0; first_friction_dist != nullptr; ++k )
  {
    if ( *((int *)&first_friction_dist->IVP_Contact_Point_Fast + 23) >= 0 )
      break;
    first_friction_dist = first_friction_dist->next_dist_in_friction;
  }
  if ( IVP_Linear_Constraint_Solver::init_and_solve_lc(
         this: &constraint_unilateral,
         A_in: this->dist_change_mat.matrix_values,
         b_in: this->dist_change_mat.desired_vector,
         result_vec_out: this->dist_change_mat.result_vector,
         var_num: this->dist_change_mat.columns,
         actives_at_begin: k,
         my_mem: mem_friction) == IVP_OK )
    goto first_try;
}

//------------------------------------------------------------------------------
// Address: 0x100A0220
// Name: public: void IVP_Friction_Solver::setup_coords_mindists(class IVP_Friction_System __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Friction_Solver::setup_coords_mindists(IVP_Friction_Solver *this, IVP_Friction_System *fs)
{
  IVP_Friction_System *v2; // ebx
  IVP_Contact_Point *first_friction_dist; // edi
  int v4; // eax
  IVP_Impact_Solver_Long_Term *tmp_contact_info; // esi
  int total_dist_counter; // [esp+8h] [ebp-Ch]
  int index_of_contact_point; // [esp+10h] [ebp-4h]

  v2 = fs;
  first_friction_dist = fs->first_friction_dist;
  v4 = 0;
  for ( index_of_contact_point = 0;
        first_friction_dist != nullptr;
        first_friction_dist = first_friction_dist->next_dist_in_friction )
  {
    tmp_contact_info = first_friction_dist->tmp_contact_info;
    if ( v4 >= v2->complex_not_necessary_number )
    {
      total_dist_counter = v4 + 1;
      tmp_contact_info->friction.friction_infos[0] = IVP_Core::get_friction_info(
                                                       this: first_friction_dist->synapse[0].l_obj->physical_core,
                                                       my_fr_system: v2);
      tmp_contact_info->friction.friction_infos[1] = IVP_Core::get_friction_info(
                                                       this: first_friction_dist->synapse[1].l_obj->physical_core,
                                                       my_fr_system: v2);
      tmp_contact_info->friction.dist_len = first_friction_dist->last_gap_len;
      tmp_contact_info->friction.has_negative_pull_since = *((__int16 *)&first_friction_dist->IVP_Contact_Point_Fast + 47);
      if ( this->contact_info_vector.n_elems >= this->contact_info_vector.memsize )
        IVP_U_Vector_Base::increment_mem(this: &this->contact_info_vector);
      this->contact_info_vector.elems[this->contact_info_vector.n_elems++] = tmp_contact_info;
      v2 = fs;
      tmp_contact_info->index_in_fs = index_of_contact_point++;
      v4 = total_dist_counter;
    }
    else
    {
      tmp_contact_info->index_in_fs = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A02D0
// Name: public: void IVP_Friction_System::do_friction_system(class IVP_Event_Sim const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Friction_System::do_friction_system(
        IVP_Friction_System *this@<ecx>,
        double a2@<st0>,
        const IVP_Event_Sim *es_in)
{
  IVP_U_Memory *short_term_mem; // edi
  IVP_Friction_System *v5; // ecx
  bool v6; // zf
  unsigned int friction_dist_number; // ecx
  int *speicherbeginn; // ebx
  unsigned int v9; // eax
  int v10; // eax
  IVP_Friction_Solver fr_solver; // [esp+8h] [ebp-830h] BYREF
  int savedregs; // [esp+838h] [ebp+0h] BYREF

  short_term_mem = this->l_environment->short_term_mem;
  ++short_term_mem->transaction_in_use;
  IVP_Friction_System::bubble_sort_dists_importance(this);
  IVP_Friction_System::reorder_mindists_for_complex(this: v5);
  if ( this->friction_dist_number - this->complex_not_necessary_number > 150
    && this->l_environment->anomaly_manager->max_contacts_exceeded_check_freezing(
         this: this->l_environment->anomaly_manager,
         a2: (IVP_Core **)this->cores_of_friction_system.elems,
         a3: this->cores_of_friction_system.n_elems) != IVP_FALSE )
  {
    IVP_Friction_System::static_fr_oversized_matrix_panic(this);
    v6 = short_term_mem->transaction_in_use-- == 1;
    if ( v6 )
      IVP_U_Memory::free_mem_transaction(this: short_term_mem);
  }
  else
  {
    IVP_Friction_Solver::IVP_Friction_Solver(this: &fr_solver, fri_sys: this, es_in);
    IVP_Friction_Solver::setup_coords_mindists(this: &fr_solver, fs: this);
    friction_dist_number = this->friction_dist_number;
    speicherbeginn = (int *)short_term_mem->speicherbeginn;
    v9 = ((unsigned int)&speicherbeginn[friction_dist_number + 7] + 3) & 0xFFFFFFE0;
    if ( (char *)v9 < short_term_mem->speicherende )
      short_term_mem->speicherbeginn = (char *)v9;
    else
      speicherbeginn = (int *)IVP_U_Memory::neuer_sp_block(this: short_term_mem, groesse: friction_dist_number * 4);
    v10 = IVP_Friction_Solver::calc_solver_PSI(
            this: &fr_solver,
            a2: (int)&savedregs,
            fs: this,
            active_is_at_pos: speicherbeginn);
    IVP_Friction_Solver::solve_linear_equation_and_push(
      this: &fr_solver,
      a2,
      my_fs: this,
      active_is_at_pos: speicherbeginn,
      total_actives: v10,
      mem_friction: short_term_mem);
    v6 = short_term_mem->transaction_in_use-- == 1;
    if ( v6 )
      IVP_U_Memory::free_mem_transaction(this: short_term_mem);
    if ( (IVP_Impact_Solver_Long_Term **)fr_solver.contact_info_vector.elems != fr_solver.contact_info_vector.elem_buffer
      && fr_solver.contact_info_vector.elems != nullptr )
    {
      free(data: fr_solver.contact_info_vector.elems);
    }
  }
}
