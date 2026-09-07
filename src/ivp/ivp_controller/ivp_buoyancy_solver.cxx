// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_controller/ivp_buoyancy_solver.cxx
// Functions: 13
// ============================================================

#include "ivp\ivp_controller\ivp_buoyancy_solver.h"

//------------------------------------------------------------------------------
// Address: 0x100A0810
// Name: public: static float IVP_Inline_Math::save_acosf(float)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x100A0850
// Name: public: static float IVP_Inline_Math::fast_asin(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl IVP_Inline_Math::fast_asin(float angle)
{
  return (float)(angle * angle) * (float)((float)(angle * angle) * angle) * 0.28999999
       + (float)((float)(angle * angle) * angle) * 0.12
       + angle;
}

//------------------------------------------------------------------------------
// Address: 0x100A0890
// Name: void ivp_core_get_surface_speed_os(class IVP_Core __near *,class IVP_Real_Object __near *,class IVP_U_Float_Point const __near *,class IVP_U_Float_Point __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall ivp_core_get_surface_speed_os(
        int a1@<ebp>,
        IVP_Core *pc,
        IVP_Real_Object *object,
        const IVP_U_Float_Point *point_os,
        IVP_U_Float_Point *speed_out_os)
{
  IVP_Cache_Object *cache_object; // ecx
  float v6; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  _BYTE v11[12]; // [esp-Ch] [ebp-6Ch] BYREF
  IVP_U_Point point_ws; // [esp+0h] [ebp-60h] BYREF
  IVP_U_Float_Point float_speed_out_ws; // [esp+10h] [ebp-50h] BYREF
  IVP_U_Float_Point speed_core; // [esp+20h] [ebp-40h] BYREF
  IVP_U_Float_Point point_core; // [esp+30h] [ebp-30h] BYREF
  IVP_Cache_Object *v16; // [esp+50h] [ebp-10h]
  int v17; // [esp+54h] [ebp-Ch]
  void *v18; // [esp+58h] [ebp-8h]
  void *retaddr; // [esp+60h] [ebp+0h]

  v17 = a1;
  v18 = retaddr;
  if ( object->cache_object == nullptr )
    object->cache_object = IVP_Cache_Object_Manager::get_cache_object(
                             this: object->environment->cache_object_manager,
                             object);
  if ( *(_BYTE *)&object->flags < 8 )
  {
    cache_object = object->cache_object;
    if ( object->environment->current_time_code > cache_object->valid_until_time_code )
      IVP_Cache_Object::update_cache_object(this: cache_object);
  }
  v16 = object->cache_object;
  IVP_Cache_Object::transform_position_to_world_coords(this: v16, P_object: point_os, P_world_out: (IVP_U_Point *)v11);
  IVP_U_Matrix::vimult4(
    this: &object->physical_core->m_world_f_core_last_psi,
    p_in: (const IVP_U_Float_Point *)v11,
    p_out: (IVP_U_Float_Point *)&speed_core.k[1]);
  v6 = pc->rot_speed.k[2] * speed_core.k[1];
  v7 = pc->rot_speed.k[1] * speed_core.k[1];
  float_speed_out_ws.k[1] = (float)(pc->rot_speed.k[1] * speed_core.hesse_val)
                          - (float)(pc->rot_speed.k[2] * speed_core.k[2]);
  v8 = (float)(pc->rot_speed.k[0] * speed_core.k[2]) - v7;
  float_speed_out_ws.k[2] = v6 - (float)(pc->rot_speed.k[0] * speed_core.hesse_val);
  float_speed_out_ws.hesse_val = v8;
  IVP_U_Matrix3::vmult3(
    this: &pc->m_world_f_core_last_psi,
    p_in: (IVP_U_Float_Point *)&float_speed_out_ws.k[1],
    p_out: (IVP_U_Float_Point *)&point_core.k[1]);
  v9 = pc->speed.k[1] + point_core.k[2];
  v10 = pc->speed.k[2] + point_core.hesse_val;
  point_core.k[1] = pc->speed.k[0] + point_core.k[1];
  point_core.k[2] = v9;
  point_core.hesse_val = v10;
  point_ws.k[1] = point_core.k[1];
  point_ws.k[2] = v9;
  point_ws.hesse_val = v10;
  IVP_Cache_Object::transform_vector_to_object_coords(
    this: v16,
    P_world: (IVP_U_Point *)&point_ws.k[1],
    P_object_out: speed_out_os);
}

//------------------------------------------------------------------------------
// Address: 0x100A09E0
// Name: public: IVP_Buoyancy_Solver::IVP_Buoyancy_Solver(class IVP_Core __near *,class IVP_Controller_Buoyancy __near *,class IVP_Template_Buoyancy const __near *,class IVP_U_Float_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Buoyancy_Solver *__thiscall IVP_Buoyancy_Solver::IVP_Buoyancy_Solver(
        IVP_Buoyancy_Solver *this,
        IVP_Core *core_,
        IVP_Controller_Buoyancy *cntrl,
        const IVP_Template_Buoyancy *input,
        const IVP_U_Float_Point *resulting_speed_of_current_ws_)
{
  float medium_density; // xmm0_4
  double viscosity_input_factor; // st7
  float v8; // xmm1_4
  float v9; // xmm2_4

  this->core = core_;
  this->environment = core_->environment;
  this->simulate_wing_behavior = input->simulate_wing_behavior;
  this->buoyancy_eps = input->buoyancy_eps;
  medium_density = input->medium_density;
  this->medium_density = medium_density;
  this->pressure_damp_factor = (float)(input->pressure_damp_factor * 0.5) * medium_density;
  this->friction_damp_factor = (float)(input->friction_damp_factor * 0.5) * this->medium_density;
  this->torque_factor = input->torque_factor;
  this->controller_buoyancy = cntrl;
  this->ball_rot_dampening_factor = input->ball_rot_dampening_factor;
  viscosity_input_factor = input->viscosity_input_factor;
  this->object_visible_surface_content_under = 0.0;
  this->viscosity_input_factor = viscosity_input_factor;
  this->sum_impulse_x_point.k[0] = 0.0;
  this->sum_impulse_x_point.k[1] = 0.0;
  this->sum_impulse_x_point.k[2] = 0.0;
  this->sum_impulse_x_movevector.k[0] = 0.0;
  this->sum_impulse_x_movevector.k[1] = 0.0;
  this->sum_impulse_x_movevector.k[2] = 0.0;
  this->sum_impulse.k[0] = 0.0;
  this->sum_impulse.k[1] = 0.0;
  this->sum_impulse.k[2] = 0.0;
  this->viscosity_factor = input->viscosity_factor;
  v8 = resulting_speed_of_current_ws_->k[1];
  v9 = resulting_speed_of_current_ws_->k[2];
  this->resulting_speed_of_current_ws.k[0] = resulting_speed_of_current_ws_->k[0];
  this->resulting_speed_of_current_ws.k[1] = v8;
  this->resulting_speed_of_current_ws.k[2] = v9;
  this->volume_under = 0.0;
  *(_QWORD *)&this->volume_center_under.k[1] = 0;
  this->volume_center_under.k[0] = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A0AE0
// Name: private: void IVP_Buoyancy_Solver::compute_buoyancy_values_for_one_ball(int const __near &,float const __near &,float const __near &,class IVP_U_Float_Hesse const __near *,class IVP_U_Float_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Buoyancy_Solver::compute_buoyancy_values_for_one_ball(
        IVP_Buoyancy_Solver *this,
        const int *decision,
        const float *distance,
        const float *radius,
        const IVP_U_Float_Hesse *surface_os,
        const IVP_U_Float_Point *geom_center_os)
{
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm1_4
  float v11; // xmm0_4
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm1_4

  this->volume_under = 0.0;
  *(_QWORD *)&this->volume_center_under.k[1] = 0;
  this->volume_center_under.k[0] = 0.0;
  if ( *decision != 0 )
  {
    if ( (unsigned int)(*decision - 1) <= 3 )
    {
      v6 = *distance + *radius;
      this->volume_under = (float)((float)((float)(*radius * 3.0) - v6) * (float)((float)(v6 * 3.1415927) * v6))
                         * 0.33333334;
      v7 = (float)((float)(*radius * 4.0) * *radius) - (float)((float)(*radius * 4.0) * v6);
      v8 = (float)(*radius * 3.0) - v6;
      v9 = v6 * v6;
      v10 = geom_center_os->k[1];
      v11 = (float)((float)(v7 + v9) * 0.75) / v8;
      v12 = geom_center_os->k[2];
      this->volume_center_under.k[0] = geom_center_os->k[0];
      this->volume_center_under.k[1] = v10;
      this->volume_center_under.k[2] = v12;
      v13 = (float)(surface_os->k[1] * v11) + this->volume_center_under.k[1];
      v14 = (float)(surface_os->k[2] * v11) + this->volume_center_under.k[2];
      this->volume_center_under.k[0] = (float)(surface_os->k[0] * v11) + this->volume_center_under.k[0];
      this->volume_center_under.k[1] = v13;
      this->volume_center_under.k[2] = v14;
    }
  }
  else
  {
    this->volume_under = (float)((float)(*radius * *radius) * *radius) * 4.1887903;
    v15 = geom_center_os->k[1];
    v16 = geom_center_os->k[2];
    this->volume_center_under.k[0] = geom_center_os->k[0];
    this->volume_center_under.k[1] = v15;
    this->volume_center_under.k[2] = v16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A0C60
// Name: private: void IVP_Buoyancy_Solver::compute_volumes_and_centers_for_one_pyramid(class IVP_Real_Object __near *,class IVP_U_Float_Point const __near * __near * const,float const __near * const,int const __near &,int const __near &,int const __near &,class IVP_U_Float_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Buoyancy_Solver::compute_volumes_and_centers_for_one_pyramid(
        IVP_Buoyancy_Solver *this,
        IVP_Real_Object *object,
        const IVP_U_Float_Point **triangle_points,
        const float *distance,
        const int *decision,
        const int *index_positiv,
        const int *index_neg,
        const IVP_U_Float_Point *s_point)
{
  int v8; // eax
  float v10; // xmm1_4
  float v11; // xmm2_4
  const IVP_U_Float_Point *v12; // esi
  float v13; // xmm3_4
  const IVP_U_Float_Point *v14; // edx
  float v15; // xmm7_4
  float v16; // xmm5_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  const IVP_U_Float_Point *v19; // edi
  float v20; // xmm4_4
  float v21; // xmm6_4
  float v22; // xmm2_4
  float v23; // xmm3_4
  const IVP_U_Float_Point *v24; // edi
  float v25; // xmm4_4
  float v26; // xmm6_4
  const IVP_U_Float_Point *v27; // eax
  float v28; // xmm2_4
  float v29; // xmm3_4
  float v30; // xmm4_4
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm3_4
  float v34; // xmm1_4
  const IVP_U_Float_Point *v35; // eax
  const IVP_U_Float_Point *v36; // edx
  float *v37; // esi
  float v38; // xmm7_4
  float v39; // xmm0_4
  float v40; // xmm3_4
  float v41; // xmm1_4
  float v42; // xmm4_4
  float v43; // xmm4_4
  float v44; // xmm5_4
  float v45; // xmm6_4
  const IVP_U_Float_Point *v46; // edx
  float v47; // xmm7_4
  float v48; // xmm3_4
  float v49; // xmm2_4
  float v50; // xmm4_4
  const IVP_U_Float_Point *v51; // edx
  const IVP_U_Float_Point *v52; // eax
  float v53; // xmm3_4
  float v54; // xmm4_4
  float v55; // xmm2_4
  float v56; // xmm3_4
  float v57; // xmm4_4
  float v58; // xmm1_4
  float v59; // xmm5_4
  float v60; // xmm6_4
  float v61; // xmm3_4
  float v62; // xmm6_4
  float v63; // xmm2_4
  const IVP_U_Float_Point *v64; // eax
  const IVP_U_Float_Point *v65; // edx
  float *v66; // esi
  float v67; // xmm2_4
  float v68; // xmm5_4
  float v69; // xmm2_4
  float v70; // xmm0_4
  float v71; // xmm1_4
  float v72; // xmm2_4
  float v73; // xmm0_4
  float v74; // [esp-4h] [ebp-44h]
  float area_center_total_12; // [esp+Ch] [ebp-34h]
  float area_center_part_above_12; // [esp+1Ch] [ebp-24h]
  float v77; // [esp+30h] [ebp-10h]
  float v78; // [esp+30h] [ebp-10h]

  if ( *decision != 0 )
  {
    if ( *decision == 1 )
    {
      v34 = distance[*index_neg];
      v35 = triangle_points[2];
      v36 = triangle_points[1];
      v37 = (float *)*triangle_points;
      v38 = (*triangle_points)->k[2];
      LODWORD(v39) = COERCE_UNSIGNED_INT(v34 / (float)(distance[*index_neg + 1] - v34)) ^ _mask__NegFloat_;
      v77 = v36->k[0] - (*triangle_points)->k[0];
      v40 = (*triangle_points)->k[1];
      LODWORD(v41) = COERCE_UNSIGNED_INT(v34 / (float)(distance[*index_neg + 2] - v34)) ^ _mask__NegFloat_;
      v42 = (float)((float)((float)((float)((*triangle_points)->k[0] - s_point->k[0])
                                  * (float)((float)((float)(v35->k[1] - v40) * (float)(v36->k[2] - v38))
                                          - (float)((float)(v35->k[2] - v38) * (float)(v36->k[1] - v40))))
                          + (float)((float)(v40 - s_point->k[1])
                                  * (float)((float)((float)(v35->k[2] - v38) * v77)
                                          - (float)((float)(v35->k[0] - (*triangle_points)->k[0])
                                                  * (float)(v36->k[2] - v38)))))
                  + (float)((float)(v38 - s_point->k[2])
                          * (float)((float)((float)(v35->k[0] - (*triangle_points)->k[0]) * (float)(v36->k[1] - v40))
                                  - (float)((float)(v35->k[1] - v40) * v77))))
          * -0.16666667;
      area_center_part_above_12 = v42 - (float)((float)(v42 * v39) * v41);
      this->volume_under = area_center_part_above_12 + this->volume_under;
      v43 = v37[2] + v36->k[2];
      v44 = v35->k[0] + (float)(v36->k[0] + *v37);
      v45 = v35->k[1] + (float)(v37[1] + v36->k[1]);
      v46 = triangle_points[*index_neg];
      v47 = v46->k[1];
      v48 = v46->k[2];
      v74 = v35->k[2] + v43;
      v49 = (float)(3.0 - v39) - v41;
      v50 = v49 * v46->k[0];
      v51 = triangle_points[*index_neg + 1];
      v52 = triangle_points[*index_neg + 2];
      area_center_total_12 = v48 * v49;
      v53 = (float)(v39 * v51->k[0]) + v50;
      v54 = (float)(v51->k[1] * v39) + (float)(v47 * v49);
      v55 = (float)(v52->k[0] * v41) + v53;
      v56 = (float)(v52->k[1] * v41) + v54;
      v57 = v52->k[2] * v41;
      v58 = v41 * v39;
      v59 = v44 - (float)(v55 * v58);
      v60 = v45 - (float)(v56 * v58);
      if ( this->buoyancy_eps <= (float)(1.0 - v58) )
      {
        v61 = 1.0 / (float)(1.0 - v58);
        v62 = (float)(v60 * v61) + s_point->k[1];
        v63 = (float)((float)(v74
                            - (float)((float)(v57 + (float)((float)(v51->k[2] * v39) + area_center_total_12)) * v58))
                    * v61)
            + s_point->k[2];
        this->volume_center_under.k[0] = this->volume_center_under.k[0]
                                       + (float)(area_center_part_above_12 * (float)((float)(v61 * v59) + s_point->k[0]));
        this->volume_center_under.k[1] = this->volume_center_under.k[1] + (float)(v62 * area_center_part_above_12);
        this->volume_center_under.k[2] = this->volume_center_under.k[2] + (float)(v63 * area_center_part_above_12);
      }
      else
      {
        this->volume_under = 0.0;
        this->volume_center_under.k[0] = 0.0;
        this->volume_center_under.k[1] = 0.0;
        this->volume_center_under.k[2] = 0.0;
      }
    }
    else if ( *decision == 2 )
    {
      v8 = *index_positiv;
      v10 = distance[v8] / (float)(distance[v8] - distance[v8 + 1]);
      v11 = distance[v8] - distance[v8 + 2];
      v12 = triangle_points[1];
      v13 = (*triangle_points)->k[1];
      v14 = triangle_points[2];
      v15 = (*triangle_points)->k[2];
      v16 = distance[*index_positiv] / v11;
      v17 = (*triangle_points)->k[0];
      v18 = (float)((float)((float)((float)((float)(v17 - s_point->k[0])
                                          * (float)((float)((float)(v14->k[1] - v13) * (float)(v12->k[2] - v15))
                                                  - (float)((float)(v14->k[2] - v15) * (float)(v12->k[1] - v13))))
                                  + (float)((float)(v13 - s_point->k[1])
                                          * (float)((float)((float)(v14->k[2] - v15) * (float)(v12->k[0] - v17))
                                                  - (float)((float)(v14->k[0] - v17) * (float)(v12->k[2] - v15)))))
                          + (float)((float)(v15 - s_point->k[2])
                                  * (float)((float)((float)(v14->k[0] - v17) * (float)(v12->k[1] - v13))
                                          - (float)((float)(v14->k[1] - v13) * (float)(v12->k[0] - v17)))))
                  * -0.16666667)
          * (float)(v16 * v10);
      this->volume_under = this->volume_under + v18;
      v19 = triangle_points[*index_positiv];
      v20 = v19->k[1];
      v21 = v19->k[2];
      v22 = (float)(3.0 - v10) - v16;
      v23 = v22 * v19->k[0];
      v24 = triangle_points[*index_positiv + 1];
      v25 = v20 * v22;
      v26 = v21 * v22;
      v27 = triangle_points[*index_positiv + 2];
      v28 = (float)(v24->k[0] * v10) + v23;
      v29 = (float)(v24->k[1] * v10) + v25;
      v30 = v24->k[2] * v10;
      v31 = (float)(v27->k[0] * v16) + v28;
      v32 = (float)((float)((float)(v27->k[1] * v16) + v29) + s_point->k[1]) * v18;
      v33 = (float)((float)((float)(v27->k[2] * v16) + (float)(v30 + v26)) + s_point->k[2]) * v18;
      this->volume_center_under.k[0] = this->volume_center_under.k[0] + (float)((float)(v31 + s_point->k[0]) * v18);
      this->volume_center_under.k[1] = this->volume_center_under.k[1] + v32;
      this->volume_center_under.k[2] = this->volume_center_under.k[2] + v33;
    }
  }
  else
  {
    v64 = triangle_points[2];
    v65 = triangle_points[1];
    v66 = (float *)*triangle_points;
    v67 = (*triangle_points)->k[1];
    v68 = (*triangle_points)->k[2];
    v78 = v65->k[0] - (*triangle_points)->k[0];
    v69 = (float)((float)((float)((float)(v67 - s_point->k[1])
                                * (float)((float)((float)(v64->k[2] - v68) * v78)
                                        - (float)((float)(v64->k[0] - (*triangle_points)->k[0])
                                                * (float)(v65->k[2] - v68))))
                        + (float)((float)((*triangle_points)->k[0] - s_point->k[0])
                                * (float)((float)((float)(v64->k[1] - v67) * (float)(v65->k[2] - v68))
                                        - (float)((float)(v64->k[2] - v68) * (float)(v65->k[1] - v67)))))
                + (float)((float)((float)((float)(v64->k[0] - (*triangle_points)->k[0]) * (float)(v65->k[1] - v67))
                                - (float)((float)(v64->k[1] - v67) * v78))
                        * (float)(v68 - s_point->k[2])))
        * -0.16666667;
    this->volume_under = this->volume_under + v69;
    v70 = (float)((float)(v64->k[1] + (float)(v66[1] + v65->k[1])) + s_point->k[1]) * v69;
    v71 = (float)((float)(v64->k[2] + (float)(v66[2] + v65->k[2])) + s_point->k[2]) * v69;
    this->volume_center_under.k[0] = this->volume_center_under.k[0]
                                   + (float)((float)(s_point->k[0] + (float)(v64->k[0] + (float)(*v66 + v65->k[0])))
                                           * v69);
    v72 = this->volume_center_under.k[1] + v70;
    v73 = this->volume_center_under.k[2];
    this->volume_center_under.k[1] = v72;
    this->volume_center_under.k[2] = v73 + v71;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A12F0
// Name: private: void IVP_Buoyancy_Solver::compute_rotation_and_translation_values_for_one_triangle(class IVP_Real_Object __near *,class IVP_Compact_Triangle const __near *,class IVP_U_Float_Point const __near * __near * const,class IVP_Compact_Ledge const __near *,float const __near * const,int const __near &,int const __near &,int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Buoyancy_Solver::compute_rotation_and_translation_values_for_one_triangle(
        IVP_Buoyancy_Solver *this@<ecx>,
        float a2@<ebp>,
        IVP_Real_Object *object,
        const IVP_Compact_Triangle *current_triangle,
        const IVP_U_Float_Point **triangle_points,
        const IVP_Compact_Ledge *current_ledge,
        const float *distance,
        const int *decision,
        const int *index_positiv,
        const int *index_neg)
{
  int v11; // eax
  float v13; // xmm1_4
  float v14; // xmm2_4
  const IVP_U_Float_Point *v15; // ecx
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm4_4
  float v19; // xmm5_4
  const IVP_U_Float_Point *v20; // ecx
  float v21; // xmm3_4
  float v22; // xmm4_4
  float v23; // xmm5_4
  const IVP_U_Float_Point *v24; // eax
  float v25; // xmm6_4
  float v26; // xmm3_4
  int v27; // eax
  float v28; // xmm0_4
  const IVP_U_Float_Point *v29; // edx
  float v30; // xmm4_4
  float v31; // xmm5_4
  float v32; // xmm3_4
  const IVP_U_Float_Point *v33; // edx
  float v34; // xmm2_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm3_4
  float v38; // xmm4_4
  const IVP_U_Float_Point *v39; // edx
  float v40; // xmm7_4
  float v41; // xmm6_4
  float v42; // xmm4_4
  const IVP_U_Float_Point *v43; // edx
  const IVP_U_Float_Point *v44; // eax
  float v45; // xmm1_4
  float v46; // xmm3_4
  float v47; // xmm4_4
  float v48; // xmm7_4
  float v49; // xmm6_4
  float v50; // xmm0_4
  float v51; // xmm5_4
  float v52; // xmm2_4
  float v53; // xmm1_4
  float v54; // xmm3_4
  float v55; // xmm4_4
  float buoyancy_eps; // xmm0_4
  const IVP_U_Float_Point *v57; // eax
  float v58; // xmm2_4
  float v59; // xmm3_4
  float v60; // xmm0_4
  const IVP_U_Float_Point *v61; // eax
  float v62; // xmm1_4
  float v63; // xmm2_4
  float v64; // xmm0_4
  float v65; // xmm1_4
  float v66; // xmm2_4
  float v67; // xmm4_4
  float v68; // xmm0_4
  float v69; // xmm1_4
  float v70; // xmm1_4
  float v71; // xmm5_4
  float v72; // xmm2_4
  float v73; // xmm3_4
  float v74; // xmm4_4
  float hesse_val; // xmm1_4
  float v76; // xmm0_4
  float v77; // xmm2_4
  float v78; // xmm0_4
  float v79; // xmm1_4
  float v80; // xmm2_4
  float v81; // xmm6_4
  float v82; // xmm3_4
  float v83; // xmm5_4
  float v84; // xmm4_4
  float v85; // xmm2_4
  float v86; // xmm1_4
  float v87[3]; // [esp-Ch] [ebp-8Ch] BYREF
  IVP_U_Float_Point move_direction_os; // [esp+0h] [ebp-80h] BYREF
  IVP_U_Float_Point speed_of_object_os; // [esp+10h] [ebp-70h] BYREF
  IVP_U_Float_Point normized_normal_os; // [esp+20h] [ebp-60h]
  IVP_U_Float_Point impulse_vector; // [esp+30h] [ebp-50h] BYREF
  IVP_U_Float_Point normal_os; // [esp+40h] [ebp-40h] BYREF
  IVP_U_Float_Point rel_speed_of_current_os; // [esp+50h] [ebp-30h] BYREF
  IVP_U_Float_Point area_center_part_under_os; // [esp+60h] [ebp-20h]
  float v95; // [esp+70h] [ebp-10h]
  float len_of_unscaled_normal; // [esp+74h] [ebp-Ch] BYREF
  float quad_length_of_speed; // [esp+78h] [ebp-8h]
  float retaddr; // [esp+80h] [ebp+0h]

  len_of_unscaled_normal = a2;
  quad_length_of_speed = retaddr;
  if ( *decision != 0 )
  {
    if ( *decision == 1 )
    {
      v27 = *index_neg;
      v28 = distance[*index_neg];
      v29 = triangle_points[1];
      v30 = (*triangle_points)->k[1] + v29->k[1];
      v31 = (*triangle_points)->k[2] + v29->k[2];
      v32 = (*triangle_points)->k[0] + v29->k[0];
      v33 = triangle_points[2];
      v34 = -(float)(distance[v27] / (float)(distance[v27 + 1] - v28));
      v35 = -(float)(v28 / (float)(distance[*index_neg + 2] - v28));
      v36 = v33->k[0] + v32;
      v37 = v33->k[1] + v30;
      v38 = v33->k[2];
      v39 = triangle_points[*index_neg];
      v40 = v39->k[1];
      v41 = v39->k[2];
      speed_of_object_os.k[1] = v36 * 0.33333334;
      speed_of_object_os.hesse_val = (float)(v38 + v31) * 0.33333334;
      v42 = v39->k[0];
      v43 = triangle_points[v27 + 1];
      v44 = triangle_points[v27 + 2];
      v45 = (float)((float)(3.0 - v34) - v35) * 0.33333334;
      speed_of_object_os.k[2] = v37 * 0.33333334;
      v46 = (float)(v43->k[0] * (float)(v34 * 0.33333334)) + (float)(v42 * v45);
      v47 = (float)(v43->k[1] * (float)(v34 * 0.33333334)) + (float)(v40 * v45);
      v48 = (float)(v43->k[2] * (float)(v34 * 0.33333334)) + (float)(v41 * v45);
      v49 = v35 * 0.33333334;
      v50 = v35 * v34;
      v51 = speed_of_object_os.k[1] - (float)((float)((float)(v49 * v44->k[0]) + v46) * v50);
      v52 = speed_of_object_os.k[2] - (float)((float)((float)(v44->k[1] * v49) + v47) * v50);
      v53 = 1.0 - v50;
      v54 = speed_of_object_os.hesse_val - (float)((float)((float)(v44->k[2] * v49) + v48) * v50);
      v55 = 1.0 / (float)(1.0 - v50);
      buoyancy_eps = this->buoyancy_eps;
      rel_speed_of_current_os.k[1] = v55 * v51;
      rel_speed_of_current_os.k[2] = v52 * (float)(1.0 / v53);
      rel_speed_of_current_os.hesse_val = v54 * (float)(1.0 / v53);
      if ( buoyancy_eps > v53 )
        return;
      v95 = v53;
    }
    else
    {
      if ( *decision != 2 )
        return;
      v11 = *index_positiv;
      v13 = distance[*index_positiv] / (float)(distance[v11] - distance[v11 + 1]);
      v14 = distance[v11] - distance[v11 + 2];
      v15 = triangle_points[*index_positiv];
      v16 = distance[*index_positiv] / v14;
      v17 = (float)((float)(3.0 - v13) - v16) * 0.33333334;
      v18 = v15->k[1] * v17;
      v19 = v15->k[2] * v17;
      rel_speed_of_current_os.k[1] = v15->k[0] * v17;
      rel_speed_of_current_os.k[2] = v18;
      rel_speed_of_current_os.hesse_val = v19;
      v20 = triangle_points[v11 + 1];
      v21 = (float)(v20->k[1] * (float)(v13 * 0.33333334)) + v18;
      v22 = (float)(v20->k[2] * (float)(v13 * 0.33333334)) + v19;
      v23 = v20->k[0];
      rel_speed_of_current_os.k[2] = v21;
      rel_speed_of_current_os.k[1] = (float)(v23 * (float)(v13 * 0.33333334)) + rel_speed_of_current_os.k[1];
      rel_speed_of_current_os.hesse_val = v22;
      v24 = triangle_points[v11 + 2];
      v25 = (float)(v24->k[1] * (float)(v16 * 0.33333334)) + v21;
      v26 = (float)(v24->k[2] * (float)(v16 * 0.33333334)) + v22;
      rel_speed_of_current_os.k[1] = (float)((float)(v16 * 0.33333334) * v24->k[0]) + rel_speed_of_current_os.k[1];
      rel_speed_of_current_os.k[2] = v25;
      rel_speed_of_current_os.hesse_val = v26;
      v95 = v16 * v13;
    }
  }
  else
  {
    v57 = triangle_points[1];
    v58 = (*triangle_points)->k[1] + v57->k[1];
    v59 = (*triangle_points)->k[2] + v57->k[2];
    v60 = v57->k[0] + (*triangle_points)->k[0];
    v61 = triangle_points[2];
    rel_speed_of_current_os.k[1] = v60;
    rel_speed_of_current_os.k[2] = v58;
    rel_speed_of_current_os.hesse_val = v59;
    v62 = v61->k[1] + v58;
    v63 = v61->k[2] + v59;
    rel_speed_of_current_os.k[1] = (float)(v60 + v61->k[0]) * 0.33333334;
    rel_speed_of_current_os.k[2] = v62 * 0.33333334;
    rel_speed_of_current_os.hesse_val = v63 * 0.33333334;
    v95 = 1.0;
  }
  IVP_Compact_Ledge_Solver::calc_hesse_vec_object_not_normized(
    edge: current_triangle->c_three_edges,
    ledge: current_ledge,
    out_vec: (IVP_U_Float_Point *)&impulse_vector.k[1]);
  area_center_part_under_os.hesse_val = impulse_vector.k[1] * impulse_vector.k[1];
  if ( this->buoyancy_eps <= (float)((float)((float)(impulse_vector.k[1] * impulse_vector.k[1])
                                           + (float)(impulse_vector.k[2] * impulse_vector.k[2]))
                                   + (float)(impulse_vector.hesse_val * impulse_vector.hesse_val)) )
  {
    ivp_core_get_surface_speed_os(
      a1: (int)&len_of_unscaled_normal,
      pc: this->core,
      object,
      point_os: (IVP_U_Float_Point *)&rel_speed_of_current_os.k[1],
      speed_out_os: (IVP_U_Float_Point *)&move_direction_os.k[1]);
    v64 = this->resulting_speed_of_current_os.k[0] - move_direction_os.k[1];
    v65 = this->resulting_speed_of_current_os.k[1] - move_direction_os.k[2];
    v66 = this->resulting_speed_of_current_os.k[2] - move_direction_os.hesse_val;
    v67 = this->buoyancy_eps;
    normal_os.k[1] = v64;
    normal_os.k[2] = v65;
    normal_os.hesse_val = v66;
    area_center_part_under_os.hesse_val = (float)((float)(v65 * v65) + (float)(v64 * v64)) + (float)(v66 * v66);
    if ( v67 > area_center_part_under_os.hesse_val )
    {
      v64 = 0.0;
      v65 = 1.0;
      v66 = 0.0;
      area_center_part_under_os.hesse_val = 0.0;
      normal_os.k[1] = 0.0;
      normal_os.k[2] = 1.0;
      normal_os.hesse_val = 0.0;
    }
    if ( (float)((float)((float)(v64 * impulse_vector.k[1]) + (float)(v65 * impulse_vector.k[2]))
               + (float)(v66 * impulse_vector.hesse_val)) <= v67 )
    {
      IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)&normal_os.k[1]);
      speed_of_object_os.k[1] = impulse_vector.k[1];
      speed_of_object_os.k[2] = impulse_vector.k[2];
      speed_of_object_os.hesse_val = impulse_vector.hesse_val;
      area_center_part_under_os.k[2] = IVP_U_Float_Point::real_length_plus_normize(this: (IVP_U_Float_Point *)&speed_of_object_os.k[1]);
      LODWORD(v68) = COERCE_UNSIGNED_INT(
                       (float)((float)((float)((float)(speed_of_object_os.k[2] * normal_os.k[2])
                                             + (float)(speed_of_object_os.k[1] * normal_os.k[1]))
                                     + (float)(speed_of_object_os.hesse_val * normal_os.hesse_val))
                             * v95)
                     * (float)(area_center_part_under_os.k[2] * 0.5))
                   ^ _mask__NegFloat_;
      v69 = (float)((float)(v68 * area_center_part_under_os.hesse_val) * this->pressure_damp_factor)
          + (float)((float)((float)(area_center_part_under_os.k[2] * 0.5) * area_center_part_under_os.hesse_val)
                  * this->friction_damp_factor);
      if ( this->simulate_wing_behavior != IVP_FALSE )
      {
        LODWORD(v70) = LODWORD(v69) ^ _mask__NegFloat_;
        v71 = speed_of_object_os.k[1] * v70;
        v72 = speed_of_object_os.k[2] * v70;
        v73 = speed_of_object_os.hesse_val * v70;
      }
      else
      {
        v71 = normal_os.k[1] * v69;
        v72 = normal_os.k[2] * v69;
        v73 = normal_os.hesse_val * v69;
      }
      v74 = rel_speed_of_current_os.k[2];
      hesse_val = rel_speed_of_current_os.hesse_val;
      this->object_visible_surface_content_under = COERCE_FLOAT(LODWORD(v68) & _mask__AbsFloat_)
                                                 + this->object_visible_surface_content_under;
      this->sum_impulse_x_point.k[0] = (float)((float)(v73 * v74) - (float)(v72 * hesse_val))
                                     + this->sum_impulse_x_point.k[0];
      v76 = this->sum_impulse_x_point.k[1];
      normized_normal_os.hesse_val = v73;
      normized_normal_os.k[2] = v72;
      v77 = v72 * rel_speed_of_current_os.k[1];
      this->sum_impulse_x_point.k[1] = v76
                                     + (float)((float)(hesse_val * v71) - (float)(v73 * rel_speed_of_current_os.k[1]));
      v78 = this->sum_impulse_x_point.k[2] + (float)(v77 - (float)(v74 * v71));
      normized_normal_os.k[1] = v71;
      this->sum_impulse_x_point.k[2] = v78;
      IVP_U_Float_Point::set_orthogonal_part(
        this: (IVP_U_Float_Point *)v87,
        vector: (IVP_U_Float_Point *)&normal_os.k[1],
        normal_v: (IVP_U_Float_Point *)&speed_of_object_os.k[1]);
      v79 = normized_normal_os.hesse_val;
      v80 = normized_normal_os.k[2];
      v81 = normized_normal_os.k[1];
      v82 = (float)(v87[1] * normized_normal_os.hesse_val) - (float)(v87[2] * normized_normal_os.k[2]);
      v83 = (float)((float)(v87[2] * normized_normal_os.k[1]) - (float)(normized_normal_os.hesse_val * v87[0]))
          + this->sum_impulse_x_movevector.k[1];
      v84 = this->sum_impulse_x_movevector.k[0];
      this->sum_impulse_x_movevector.k[2] = (float)((float)(normized_normal_os.k[2] * v87[0])
                                                  - (float)(v87[1] * normized_normal_os.k[1]))
                                          + this->sum_impulse_x_movevector.k[2];
      this->sum_impulse_x_movevector.k[1] = v83;
      this->sum_impulse_x_movevector.k[0] = v84 + v82;
      v85 = v80 + this->sum_impulse.k[1];
      v86 = v79 + this->sum_impulse.k[2];
      this->sum_impulse.k[0] = this->sum_impulse.k[0] + v81;
      this->sum_impulse.k[1] = v85;
      this->sum_impulse.k[2] = v86;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A1970
// Name: private: int IVP_Buoyancy_Solver::compute_disection_points_with_ball(class IVP_U_Float_Hesse const __near *,class IVP_U_Float_Hesse const __near *,class IVP_U_Float_Point const __near *,float const __near &,class IVP_U_Float_Point __near *,class IVP_U_Float_Point __near *)
// Source: json
//------------------------------------------------------------------------------
int __userpurge IVP_Buoyancy_Solver::compute_disection_points_with_ball@<eax>(
        IVP_Buoyancy_Solver *this@<ecx>,
        float a2@<ebp>,
        const IVP_U_Float_Hesse *plane1_os,
        const IVP_U_Float_Hesse *plane2_os,
        const IVP_U_Float_Point *geom_center_os,
        const float *radius,
        IVP_U_Float_Point *p1_os,
        IVP_U_Float_Point *p2_os)
{
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm7_4
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float hesse_val; // xmm0_4
  float v16; // xmm7_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  _BYTE v20[12]; // [esp-Ch] [ebp-CCh] BYREF
  IVP_U_Plain point_direction_form_of_plane2_os; // [esp+0h] [ebp-C0h] BYREF
  IVP_U_Straight straight_os; // [esp+40h] [ebp-80h] BYREF
  IVP_U_Point parameters; // [esp+60h] [ebp-60h] BYREF
  IVP_U_Point v24; // [esp+70h] [ebp-50h] BYREF
  IVP_U_Hesse tmp_plane2_os; // [esp+80h] [ebp-40h] BYREF
  IVP_U_Hesse non_float_plane1_os; // [esp+90h] [ebp-30h]
  IVP_U_Float_Point straight_start_point; // [esp+A0h] [ebp-20h]
  IVP_U_Float_Point straight_vec; // [esp+B0h] [ebp-10h] BYREF
  float retaddr; // [esp+C0h] [ebp+0h]

  straight_vec.k[1] = a2;
  straight_vec.k[2] = retaddr;
  v24.k[1] = plane2_os->k[0];
  v24.k[2] = plane2_os->k[1];
  v24.hesse_val = plane2_os->k[2];
  tmp_plane2_os.k[0] = plane2_os->hesse_val;
  IVP_U_Plain::IVP_U_Plain(
    this: (IVP_U_Plain *)v20,
    a2: COERCE_FLOAT((IVP_U_Float_Point *)&straight_vec.k[1]),
    i_hesse: (const IVP_U_Hesse *)&v24.k[1]);
  tmp_plane2_os.k[1] = plane1_os->k[0];
  tmp_plane2_os.k[2] = plane1_os->k[1];
  tmp_plane2_os.hesse_val = plane1_os->k[2];
  non_float_plane1_os.k[0] = plane1_os->hesse_val;
  if ( IVP_U_Plain::calc_intersect_with(
         this: (IVP_U_Plain *)v20,
         a2: COERCE_FLOAT((IVP_U_Float_Point *)&straight_vec.k[1]),
         plane2: (IVP_U_Hesse *)&tmp_plane2_os.k[1],
         straight_out: (IVP_U_Straight *)&point_direction_form_of_plane2_os.vec2.k[1]) )
  {
    *(_QWORD *)&non_float_plane1_os.k[2] = *(_QWORD *)&straight_os.vec.k[2];
    v8 = straight_os.vec.k[2] - geom_center_os->k[1];
    straight_os.start_point.k[1] = (float)((float)(point_direction_form_of_plane2_os.vec2.k[2]
                                                 * point_direction_form_of_plane2_os.vec2.k[2])
                                         + (float)(point_direction_form_of_plane2_os.vec2.k[1]
                                                 * point_direction_form_of_plane2_os.vec2.k[1]))
                                 + (float)(point_direction_form_of_plane2_os.vec2.hesse_val
                                         * point_direction_form_of_plane2_os.vec2.hesse_val);
    non_float_plane1_os.k[1] = straight_os.vec.k[1];
    v9 = straight_os.vec.k[1] - geom_center_os->k[0];
    straight_start_point.k[2] = point_direction_form_of_plane2_os.vec2.k[2];
    straight_start_point.k[1] = point_direction_form_of_plane2_os.vec2.k[1];
    v10 = straight_os.vec.hesse_val - geom_center_os->k[2];
    v11 = (float)((float)((float)(v8 * 2.0) * point_direction_form_of_plane2_os.vec2.k[2])
                + (float)((float)(v9 * 2.0) * point_direction_form_of_plane2_os.vec2.k[1]))
        + (float)((float)(v10 * 2.0) * point_direction_form_of_plane2_os.vec2.hesse_val);
    v12 = (float)((float)((float)(v8 * v8) + (float)(v9 * v9)) + (float)(v10 * v10)) - (float)(*radius * *radius);
    straight_start_point.hesse_val = point_direction_form_of_plane2_os.vec2.hesse_val;
    straight_os.start_point.k[2] = v11;
    straight_os.start_point.hesse_val = v12;
    IVP_U_Point::solve_quadratic_equation_accurate(
      this: (IVP_U_Point *)&parameters.k[1],
      p: (const IVP_U_Point *)&straight_os.start_point.k[1]);
    if ( parameters.k[1] >= 0.0 )
    {
      v13 = (float)(parameters.k[2] * straight_start_point.k[1]) + non_float_plane1_os.k[1];
      v14 = (float)(parameters.k[2] * straight_start_point.k[2]) + non_float_plane1_os.k[2];
      p1_os->k[2] = (float)(parameters.k[2] * straight_start_point.hesse_val) + non_float_plane1_os.hesse_val;
      hesse_val = parameters.hesse_val;
      p1_os->k[0] = v13;
      p1_os->k[1] = v14;
      v16 = (float)(hesse_val * straight_start_point.k[1]) + non_float_plane1_os.k[1];
      v17 = (float)(hesse_val * straight_start_point.k[2]) + non_float_plane1_os.k[2];
      v18 = (float)(hesse_val * straight_start_point.hesse_val) + non_float_plane1_os.hesse_val;
      p2_os->k[0] = v16;
      p2_os->k[1] = v17;
      p2_os->k[2] = v18;
      return 1;
    }
    p1_os->k[0] = 0.0;
    p1_os->k[1] = 0.0;
    p1_os->k[2] = 0.0;
    p2_os->k[0] = 0.0;
    p2_os->k[1] = 0.0;
    p2_os->k[2] = 0.0;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100A1BA0
// Name: private: void IVP_Buoyancy_Solver::compute_values_for_one_ledge(class IVP_Real_Object __near *,class IVP_Compact_Ledge const __near *,class IVP_U_Float_Hesse const __near *,class IVP_U_Float_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Buoyancy_Solver::compute_values_for_one_ledge(
        IVP_Buoyancy_Solver *this@<ecx>,
        int a2@<ebp>,
        IVP_Real_Object *object,
        const IVP_Compact_Ledge *current_ledge,
        const IVP_U_Float_Hesse *surface_os,
        const IVP_U_Float_Point *s_point)
{
  int v6; // eax
  const IVP_Compact_Ledge *v7; // edi
  int c_point_offset; // edx
  int v9; // eax
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  int v13; // eax
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm1_4
  int v17; // eax
  float v18; // xmm4_4
  float v19; // xmm5_4
  float v20; // xmm7_4
  float v21; // xmm2_4
  float v22; // xmm3_4
  float hesse_val; // xmm6_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float buoyancy_eps; // xmm4_4
  float v27; // xmm0_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30[4]; // [esp-78h] [ebp-8Ch] BYREF
  float v31[4]; // [esp-68h] [ebp-7Ch] BYREF
  _DWORD v32[4]; // [esp-58h] [ebp-6Ch] BYREF
  float v33[6]; // [esp-48h] [ebp-5Ch] BYREF
  const IVP_U_Float_Point *v34[5]; // [esp-30h] [ebp-44h] BYREF
  float v35; // [esp-1Ch] [ebp-30h]
  float v36; // [esp-18h] [ebp-2Ch]
  float v37; // [esp-14h] [ebp-28h]
  float v38; // [esp-10h] [ebp-24h]
  int v39; // [esp-Ch] [ebp-20h]
  IVP_Buoyancy_Solver *v40; // [esp-8h] [ebp-1Ch]
  int v41; // [esp-4h] [ebp-18h] BYREF
  int i; // [esp+0h] [ebp-14h] BYREF
  int v43; // [esp+4h] [ebp-10h] BYREF
  _DWORD v44[3]; // [esp+8h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+14h] [ebp+0h]

  v44[0] = a2;
  v44[1] = retaddr;
  v6 = current_ledge->n_triangles - 1;
  v40 = this;
  v7 = current_ledge + 1;
  v39 = v6;
  if ( v6 >= 0 )
  {
    while ( 1 )
    {
      c_point_offset = current_ledge->c_point_offset;
      v9 = current_ledge->c_point_offset + 16 * (unsigned __int16)v7->ledgetree_node_offset;
      v10 = *(float *)((char *)&current_ledge->ledgetree_node_offset + v9);
      v11 = *(float *)((char *)current_ledge + v9 + 8);
      v12 = *(float *)((char *)&current_ledge->c_point_offset + v9);
      v13 = current_ledge->c_point_offset + 16 * (unsigned __int16)*((_DWORD *)v7 + 2);
      v30[1] = v10;
      v30[0] = v12;
      v30[2] = v11;
      v14 = *(float *)((char *)&current_ledge->c_point_offset + v13);
      v36 = v10;
      v15 = *(float *)((char *)&current_ledge->ledgetree_node_offset + v13);
      v35 = v11;
      v16 = *(float *)((char *)current_ledge + v13 + 8);
      v17 = c_point_offset + 16 * (unsigned __int16)*(_DWORD *)&v7->n_triangles;
      v31[1] = v15;
      v31[0] = v14;
      v31[2] = v16;
      v18 = *(float *)((char *)&current_ledge->ledgetree_node_offset + v17);
      v19 = *(float *)((char *)current_ledge + v17 + 8);
      v20 = *(float *)((char *)&current_ledge->c_point_offset + v17);
      v34[0] = (const IVP_U_Float_Point *)v30;
      v34[2] = (const IVP_U_Float_Point *)v32;
      v38 = v15;
      v34[4] = (const IVP_U_Float_Point *)v31;
      v21 = surface_os->k[1];
      v22 = surface_os->k[2];
      hesse_val = surface_os->hesse_val;
      v37 = v16;
      v24 = surface_os->k[0];
      *(float *)v32 = v20;
      *(float *)&v32[1] = v18;
      v34[1] = (const IVP_U_Float_Point *)v31;
      v25 = (float)((float)(v24 * v20) + (float)(v21 * v18)) + (float)(v22 * v19);
      buoyancy_eps = this->buoyancy_eps;
      *(float *)&v32[2] = v19;
      v34[3] = (const IVP_U_Float_Point *)v30;
      v27 = v25 + hesse_val;
      v43 = 0;
      if ( v27 >= 0.0 )
      {
        v41 = 2;
        v33[2] = buoyancy_eps + v27;
        v33[5] = buoyancy_eps + v27;
      }
      else
      {
        i = 2;
        v43 = 1;
        v33[2] = v27 - buoyancy_eps;
        v33[5] = v27 - buoyancy_eps;
      }
      v28 = (float)((float)((float)(v24 * v31[0]) + (float)(v21 * v38)) + (float)(v22 * v37)) + hesse_val;
      if ( v28 >= 0.0 )
      {
        v41 = 1;
        v33[1] = buoyancy_eps + v28;
        v33[4] = buoyancy_eps + v28;
      }
      else
      {
        ++v43;
        i = 1;
        v33[1] = v28 - buoyancy_eps;
        v33[4] = v28 - buoyancy_eps;
      }
      v29 = (float)((float)((float)(v24 * v30[0]) + (float)(v21 * v36)) + (float)(v22 * v35)) + hesse_val;
      if ( v29 >= 0.0 )
      {
        v41 = 0;
        v33[0] = buoyancy_eps + v29;
        v33[3] = buoyancy_eps + v29;
      }
      else
      {
        ++v43;
        i = 0;
        v33[0] = v29 - buoyancy_eps;
        v33[3] = v29 - buoyancy_eps;
      }
      IVP_Buoyancy_Solver::compute_volumes_and_centers_for_one_pyramid(
        this,
        object,
        triangle_points: v34,
        distance: v33,
        decision: &v43,
        index_positiv: &v41,
        index_neg: &i,
        s_point);
      IVP_Buoyancy_Solver::compute_rotation_and_translation_values_for_one_triangle(
        this: v40,
        a2: COERCE_FLOAT(v44),
        object,
        current_triangle: (const IVP_Compact_Triangle *)v7++,
        triangle_points: v34,
        current_ledge,
        distance: v33,
        decision: &v43,
        index_positiv: &v41,
        index_neg: &i);
      if ( --v39 < 0 )
        break;
      this = v40;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A1E10
// Name: private: void IVP_Buoyancy_Solver::compute_dampening_values_for_one_ball(int const __near &,float const __near &,float const __near &,class IVP_U_Float_Point const __near *,class IVP_U_Float_Point const __near *,class IVP_U_Float_Hesse const __near *,class IVP_U_Float_Hesse const __near *,class IVP_U_Float_Point const __near *,class IVP_U_Float_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge IVP_Buoyancy_Solver::compute_dampening_values_for_one_ball(
        IVP_Buoyancy_Solver *this@<ecx>,
        float a2@<ebp>,
        const int *decision,
        float *distance,
        const float *radius,
        const IVP_U_Float_Point *geom_center_os,
        const IVP_U_Float_Point *rel_speed_of_current_os_,
        const IVP_U_Float_Hesse *speed_plane_os_,
        IVP_U_Float_Hesse *surface_os,
        const IVP_U_Float_Point *p1_os,
        const IVP_U_Float_Point *p2_os)
{
  float v12; // xmm1_4
  int v13; // eax
  float v14; // xmm0_4
  float v15; // xmm1_4
  IVP_U_Float_Hesse *v16; // edi
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm5_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  long double v22; // st7
  float buoyancy_eps; // xmm1_4
  long double v24; // st7
  double v25; // st7
  float v26; // xmm1_4
  float v27; // xmm0_4
  bool v28; // cc
  float v29; // xmm1_4
  float v30; // xmm1_4
  float v31; // xmm2_4
  float v32; // xmm4_4
  float v33; // xmm5_4
  float v34; // xmm1_4
  float v35; // xmm1_4
  float v36; // xmm5_4
  float v37; // xmm1_4
  float v38; // xmm2_4
  float v39; // xmm3_4
  double v40; // st7
  long double v41; // st7
  double v42; // st7
  long double v43; // st7
  float hesse_val; // xmm3_4
  float v45; // xmm2_4
  float v46; // xmm1_4
  float v47; // xmm6_4
  float v48; // xmm0_4
  float v49; // xmm6_4
  float v50; // xmm0_4
  float v51; // xmm7_4
  float v52; // xmm1_4
  long double v53; // st7
  long double v54; // st7
  double v55; // st7
  float v56; // xmm0_4
  float v57; // xmm6_4
  float v58; // xmm5_4
  long double v59; // st7
  double v60; // st7
  long double v61; // st7
  float v62; // xmm1_4
  float v63; // xmm4_4
  float v64; // xmm3_4
  float v65; // xmm0_4
  double v66; // st7
  float v67; // xmm0_4
  float v68; // xmm2_4
  float v69; // xmm3_4
  float v70; // xmm5_4
  float v71; // xmm3_4
  float v72; // xmm4_4
  float v73; // xmm5_4
  float v74; // xmm1_4
  float v75; // xmm2_4
  long double v76; // st7
  float v77; // xmm1_4
  long double v78; // st7
  double v79; // st7
  float v80; // xmm3_4
  float v81; // xmm4_4
  float v82; // xmm5_4
  float v83; // xmm2_4
  float v84; // xmm1_4
  float v85; // xmm6_4
  float v86; // xmm5_4
  __m128i si128; // xmm1
  float v88; // xmm1_4
  long double v89; // st7
  float v90; // xmm5_4
  long double v91; // st7
  double v92; // st7
  long double v93; // st7
  double v94; // st7
  float v95; // xmm6_4
  float v96; // xmm1_4
  float v97; // xmm2_4
  float v98; // xmm0_4
  float v99; // xmm1_4
  long double v100; // st7
  long double v101; // st7
  double v102; // st7
  float v103; // xmm0_4
  float v104; // xmm2_4
  long double v105; // st7
  double v106; // st7
  long double v107; // st7
  float v108; // xmm1_4
  float v109; // xmm7_4
  float v110; // xmm5_4
  float v111; // xmm6_4
  float v112; // xmm0_4
  float v113; // xmm1_4
  float v114; // xmm2_4
  float v115; // xmm0_4
  float v116; // xmm7_4
  float v117; // xmm6_4
  float v118; // xmm5_4
  float v119; // xmm0_4
  double v120; // st7
  float v121; // xmm0_4
  float v122; // xmm3_4
  float v123; // xmm5_4
  float v124; // xmm6_4
  float v125; // xmm0_4
  float v126; // xmm7_4
  float v127; // xmm3_4
  float v128; // xmm2_4
  float v129; // xmm1_4
  float v130; // xmm0_4
  float v131; // xmm2_4
  float v132; // xmm3_4
  float v133; // xmm1_4
  float v134; // xmm6_4
  float v135; // xmm2_4
  float v136; // xmm3_4
  float v137; // xmm0_4
  float v138; // xmm1_4
  float v139; // xmm6_4
  float v140; // xmm3_4
  float v141; // xmm0_4
  float v142; // xmm2_4
  float v143; // xmm1_4
  float v144; // xmm0_4
  float v145; // xmm1_4
  float v146; // xmm3_4
  float v147; // xmm4_4
  float v148; // xmm2_4
  float v149; // xmm1_4
  float v150; // xmm0_4
  float v151; // xmm2_4
  float v152; // xmm0_4
  float v153; // xmm1_4
  float v154; // xmm6_4
  float v155; // xmm4_4
  float v156; // xmm1_4
  float v157; // xmm2_4
  float angle; // [esp+0h] [ebp-150h]
  float anglea; // [esp+0h] [ebp-150h]
  float angleb; // [esp+0h] [ebp-150h]
  _BYTE v161[12]; // [esp+14h] [ebp-13Ch] BYREF
  IVP_U_Float_Point projected_center_on_surface_os; // [esp+20h] [ebp-130h] BYREF
  IVP_U_Float_Point tmp_O2_os; // [esp+30h] [ebp-120h] BYREF
  IVP_U_Float_Point tmp_O1_os; // [esp+40h] [ebp-110h] BYREF
  IVP_U_Float_Point rel_speed_of_current_os; // [esp+50h] [ebp-100h] BYREF
  IVP_U_Float_Point MQ_os; // [esp+60h] [ebp-F0h] BYREF
  IVP_U_Float_Point O_os; // [esp+70h] [ebp-E0h] BYREF
  IVP_U_Float_Point center_of_segment_os; // [esp+80h] [ebp-D0h] BYREF
  IVP_U_Float_Point p1p2_os; // [esp+90h] [ebp-C0h] BYREF
  IVP_U_Float_Point edge_Q_center_os; // [esp+A0h] [ebp-B0h] BYREF
  IVP_U_Float_Hesse p1p2_hesse_os; // [esp+B0h] [ebp-A0h] BYREF
  IVP_U_Float_Point projected_center_on_ellipse_os; // [esp+C0h] [ebp-90h] BYREF
  IVP_U_Float_Hesse speed_plane_os; // [esp+D0h] [ebp-80h] BYREF
  IVP_U_Float_Point center_of_ellipse_os; // [esp+E0h] [ebp-70h] BYREF
  IVP_U_Float_Point center_of_circle_segment_under_surface; // [esp+F0h] [ebp-60h] BYREF
  IVP_U_Float_Point direction_up_4; // [esp+104h] [ebp-4Ch] OVERLAPPED BYREF
  float v177; // [esp+120h] [ebp-30h]
  float v178; // [esp+124h] [ebp-2Ch]
  float v179; // [esp+128h] [ebp-28h]
  float surface_content_up; // [esp+12Ch] [ebp-24h]
  float s; // [esp+130h] [ebp-20h]
  float surface_content_of_whole_ellipse; // [esp+134h] [ebp-1Ch]
  float surface_content_of_ellipse_segment; // [esp+138h] [ebp-18h]
  float surface_content_of_circle_segment_under_surface; // [esp+13Ch] [ebp-14h]
  float ball_projected_surface_content_under; // [esp+140h] [ebp-10h]
  float surface_content_circle; // [esp+144h] [ebp-Ch] BYREF
  float b; // [esp+148h] [ebp-8h]
  float retaddr; // [esp+150h] [ebp+0h]

  surface_content_circle = a2;
  b = retaddr;
  tmp_O1_os.k[1] = rel_speed_of_current_os_->k[0];
  tmp_O1_os.k[2] = rel_speed_of_current_os_->k[1];
  v12 = speed_plane_os_->k[0];
  tmp_O1_os.hesse_val = rel_speed_of_current_os_->k[2];
  projected_center_on_ellipse_os.k[2] = speed_plane_os_->k[1];
  projected_center_on_ellipse_os.hesse_val = speed_plane_os_->k[2];
  v13 = *decision;
  speed_plane_os.k[0] = speed_plane_os_->hesse_val;
  v14 = 0.0;
  *(_QWORD *)&direction_up_4.k[1] = 0;
  direction_up_4.k[0] = 0.0;
  projected_center_on_ellipse_os.k[1] = v12;
  surface_content_of_whole_ellipse = 0.0;
  switch ( v13 )
  {
    case 0:
      v14 = (float)(*radius * 3.1415927) * *radius;
      *(_QWORD *)direction_up_4.k = *(_QWORD *)geom_center_os->k;
      v15 = geom_center_os->k[2];
      surface_content_of_whole_ellipse = v14;
      goto LABEL_83;
    case 1:
      v16 = surface_os;
      IVP_U_Hesse::proj_on_plane(
        this: (IVP_U_Float_Hesse *)&projected_center_on_ellipse_os.k[1],
        p: surface_os,
        result: (IVP_U_Float_Point *)&center_of_ellipse_os.k[1]);
      ball_projected_surface_content_under = center_of_ellipse_os.k[2] * center_of_ellipse_os.k[2];
      if ( this->buoyancy_eps > (float)((float)((float)(center_of_ellipse_os.k[2] * center_of_ellipse_os.k[2])
                                              + (float)(center_of_ellipse_os.k[1] * center_of_ellipse_os.k[1]))
                                      + (float)(center_of_ellipse_os.hesse_val * center_of_ellipse_os.hesse_val)) )
      {
        v12 = projected_center_on_ellipse_os.k[1];
case_2:
        ball_projected_surface_content_under = (float)((float)(v16->k[1] * projected_center_on_ellipse_os.k[2])
                                                     + (float)(v12 * v16->k[0]))
                                             + (float)(v16->k[2] * projected_center_on_ellipse_os.hesse_val);
        if ( ball_projected_surface_content_under >= 0.0 )
        {
LABEL_80:
          v14 = 0.0;
          surface_content_of_whole_ellipse = 0.0;
        }
        else
        {
          IVP_U_Hesse::proj_on_plane(this: v16, p: geom_center_os, result: (IVP_U_Float_Point *)v161);
          IVP_U_Hesse::proj_on_plane(
            this: (IVP_U_Float_Hesse *)&projected_center_on_ellipse_os.k[1],
            p: (const IVP_U_Float_Point *)v161,
            result: &direction_up_4);
          LODWORD(v14) = COERCE_UNSIGNED_INT(
                           (float)((float)(*radius * *radius) - (float)(*distance * *distance))
                         * (float)(ball_projected_surface_content_under * 3.1415927))
                       & _mask__AbsFloat_;
          surface_content_of_whole_ellipse = v14;
        }
      }
      else
      {
        IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)&center_of_ellipse_os.k[1]);
        v17 = p1_os->k[0];
        v18 = p1_os->k[1];
        v19 = p1_os->k[2];
        v20 = p2_os->k[1] - v18;
        v21 = p2_os->k[2] - v19;
        center_of_segment_os.k[1] = p2_os->k[0] - p1_os->k[0];
        center_of_segment_os.k[2] = v20;
        center_of_segment_os.hesse_val = v21;
        speed_plane_os.k[1] = (float)(center_of_segment_os.k[1] * 0.5) + v17;
        speed_plane_os.k[2] = (float)(v20 * 0.5) + v18;
        speed_plane_os.hesse_val = (float)(v21 * 0.5) + v19;
        v22 = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Point *)&center_of_segment_os.k[1]);
        surface_content_of_circle_segment_under_surface = v22;
        if ( this->buoyancy_eps > v22 )
          goto LABEL_25;
        edge_Q_center_os.k[1] = center_of_segment_os.k[1];
        edge_Q_center_os.k[2] = center_of_segment_os.k[2];
        edge_Q_center_os.hesse_val = center_of_segment_os.hesse_val;
        IVP_U_Float_Hesse::calc_hesse_val(
          this: (IVP_U_Float_Hesse *)&edge_Q_center_os.k[1],
          p0: (IVP_U_Float_Hesse *)&speed_plane_os.k[1]);
        IVP_U_Hesse::normize(this: (IVP_U_Float_Hesse *)&edge_Q_center_os.k[1]);
        IVP_Buoyancy_Solver::compute_disection_points_with_ball(
          this,
          a2: COERCE_FLOAT(&surface_content_circle),
          plane1_os: surface_os,
          plane2_os: (const IVP_U_Float_Hesse *)&edge_Q_center_os.k[1],
          geom_center_os,
          radius,
          p1_os: (IVP_U_Float_Point *)&tmp_O2_os.k[1],
          p2_os: (IVP_U_Float_Point *)&projected_center_on_surface_os.k[1]);
        if ( (float)((float)((float)((float)(projected_center_on_surface_os.k[2] - tmp_O2_os.k[2])
                                   * projected_center_on_ellipse_os.k[2])
                           + (float)((float)(projected_center_on_surface_os.k[1] - tmp_O2_os.k[1])
                                   * projected_center_on_ellipse_os.k[1]))
                   + (float)((float)(projected_center_on_surface_os.hesse_val - tmp_O2_os.hesse_val)
                           * projected_center_on_ellipse_os.hesse_val)) < 0.0 )
          IVP_U_Hesse::proj_on_plane(
            this: (IVP_U_Float_Hesse *)&projected_center_on_ellipse_os.k[1],
            p: (IVP_U_Float_Point *)&projected_center_on_surface_os.k[1],
            result: (IVP_U_Float_Point *)&MQ_os.k[1]);
        else
          IVP_U_Hesse::proj_on_plane(
            this: (IVP_U_Float_Hesse *)&projected_center_on_ellipse_os.k[1],
            p: (IVP_U_Float_Point *)&tmp_O2_os.k[1],
            result: (IVP_U_Float_Point *)&MQ_os.k[1]);
        buoyancy_eps = this->buoyancy_eps;
        surface_content_of_ellipse_segment = (float)((float)(projected_center_on_ellipse_os.k[2] * surface_os->k[1])
                                                   + (float)(projected_center_on_ellipse_os.k[1] * surface_os->k[0]))
                                           + (float)(projected_center_on_ellipse_os.hesse_val * surface_os->k[2]);
        if ( buoyancy_eps >= surface_content_of_ellipse_segment )
        {
          rel_speed_of_current_os.k[1] = speed_plane_os.k[1] - geom_center_os->k[0];
          rel_speed_of_current_os.k[2] = speed_plane_os.k[2] - geom_center_os->k[1];
          rel_speed_of_current_os.hesse_val = speed_plane_os.hesse_val - geom_center_os->k[2];
          v179 = *radius;
          v24 = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Point *)&rel_speed_of_current_os.k[1]);
          ball_projected_surface_content_under = v179 - v24;
          v25 = IVP_Inline_Math::fast_asin(angle: surface_content_of_circle_segment_under_surface / (float)(v179 * 2.0));
          v26 = this->buoyancy_eps;
          s = fabs(
                ((v25 + v25) * v179 * v179
               - (v179 - ball_projected_surface_content_under) * surface_content_of_circle_segment_under_surface)
              * 0.5);
          v14 = s;
          if ( v26 <= s )
          {
            v28 = surface_content_of_ellipse_segment <= COERCE_FLOAT(LODWORD(v26) ^ _mask__NegFloat_);
            v29 = (float)(surface_content_of_circle_segment_under_surface
                        * surface_content_of_circle_segment_under_surface)
                * surface_content_of_circle_segment_under_surface;
            if ( !v28 )
            {
              v30 = v29 / (float)(s * 12.0);
              direction_up_4.k[0] = (float)(v30 * surface_os->k[0]) + geom_center_os->k[0];
              v31 = (float)(v30 * surface_os->k[1]) + geom_center_os->k[1];
              v15 = (float)(v30 * surface_os->k[2]) + geom_center_os->k[2];
              surface_content_of_whole_ellipse = s;
              goto LABEL_82;
            }
            v32 = geom_center_os->k[1];
            v33 = geom_center_os->k[2];
            v34 = v29 / (float)(s * 12.0);
            O_os.k[1] = (float)(v34 * center_of_ellipse_os.k[1]) + geom_center_os->k[0];
            O_os.k[2] = (float)(center_of_ellipse_os.k[2] * v34) + v32;
            v27 = (float)(center_of_ellipse_os.hesse_val * v34) + v33;
          }
          else
          {
            v27 = 0.0;
            O_os.k[1] = 0.0;
            O_os.k[2] = 0.0;
          }
          O_os.hesse_val = v27;
          IVP_U_Hesse::proj_on_plane(this: surface_os, p: geom_center_os, result: (IVP_U_Float_Point *)v161);
          IVP_U_Hesse::proj_on_plane(
            this: (IVP_U_Float_Hesse *)&projected_center_on_ellipse_os.k[1],
            p: (const IVP_U_Float_Point *)v161,
            result: (IVP_U_Float_Point *)&center_of_circle_segment_under_surface.k[1]);
          p1p2_os.k[1] = center_of_circle_segment_under_surface.k[1] - MQ_os.k[1];
          p1p2_os.k[2] = center_of_circle_segment_under_surface.k[2] - MQ_os.k[2];
          p1p2_os.hesse_val = center_of_circle_segment_under_surface.hesse_val - MQ_os.hesse_val;
          v177 = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Point *)&p1p2_os.k[1]);
          p1p2_hesse_os.k[1] = center_of_circle_segment_under_surface.k[1] - speed_plane_os.k[1];
          p1p2_hesse_os.k[2] = center_of_circle_segment_under_surface.k[2] - speed_plane_os.k[2];
          p1p2_hesse_os.hesse_val = center_of_circle_segment_under_surface.hesse_val - speed_plane_os.hesse_val;
          surface_content_up = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Hesse *)&p1p2_hesse_os.k[1]);
          v35 = this->buoyancy_eps;
          surface_content_of_ellipse_segment = fsqrt(
                                                 COERCE_FLOAT(
                                                   COERCE_UNSIGNED_INT((float)(*radius * *radius) - (float)(*distance * *distance))
                                                 & _mask__AbsFloat_));
          if ( v35 <= v177 )
          {
            v40 = IVP_Inline_Math::save_acosf(angle: surface_content_up / v177);
            ball_projected_surface_content_under = v40 * (surface_content_of_ellipse_segment * v177);
            v41 = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Point *)&center_of_segment_os.k[1]);
            v179 = (float)(surface_content_of_ellipse_segment * 3.1415927) * v177;
            v178 = fabs(ball_projected_surface_content_under - v41 * 0.5 * surface_content_up);
            surface_content_of_circle_segment_under_surface = fabs(v179 - v178);
            ball_projected_surface_content_under = v177 - surface_content_up;
            surface_content_of_ellipse_segment = fsqrt(
                                                   fabs(
                                                     (float)((float)((float)(v177 - surface_content_up) * 2.0) * v177)
                                                   - (float)((float)(v177 - surface_content_up)
                                                           * (float)(v177 - surface_content_up))))
                                               * 2.0;
            v42 = IVP_Inline_Math::fast_asin(angle: surface_content_of_ellipse_segment / (float)(v177 * 2.0));
            v43 = fabs(
                    (fabs((v42 + v42) * v177) * v177
                   - (v177 - ball_projected_surface_content_under) * surface_content_of_ellipse_segment)
                  * 0.5);
            ball_projected_surface_content_under = v43;
            if ( this->buoyancy_eps <= v43 )
            {
              IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)&p1p2_os.k[1]);
              v45 = center_of_circle_segment_under_surface.k[2];
              v46 = center_of_circle_segment_under_surface.k[1];
              v49 = (float)((float)(surface_content_of_ellipse_segment * surface_content_of_ellipse_segment)
                          * surface_content_of_ellipse_segment)
                  / (float)(ball_projected_surface_content_under * 12.0);
              edge_Q_center_os.k[2] = (float)(v49 * p1p2_os.k[2]) + center_of_circle_segment_under_surface.k[2];
              hesse_val = center_of_circle_segment_under_surface.hesse_val;
              edge_Q_center_os.hesse_val = (float)(v49 * p1p2_os.hesse_val)
                                         + center_of_circle_segment_under_surface.hesse_val;
              v48 = v178;
              v47 = (float)(v49 * p1p2_os.k[1]) + center_of_circle_segment_under_surface.k[1];
            }
            else
            {
              hesse_val = center_of_circle_segment_under_surface.hesse_val;
              v45 = center_of_circle_segment_under_surface.k[2];
              v46 = center_of_circle_segment_under_surface.k[1];
              v47 = 0.0;
              edge_Q_center_os.k[2] = 0.0;
              edge_Q_center_os.hesse_val = 0.0;
              v48 = 0.0;
            }
            v36 = surface_content_of_circle_segment_under_surface;
            if ( this->buoyancy_eps <= surface_content_of_circle_segment_under_surface )
            {
              LODWORD(v50) = LODWORD(v48) ^ _mask__NegFloat_;
              p1p2_hesse_os.k[1] = (float)(v46 * v179) + (float)(v50 * v47);
              v37 = (float)(1.0 / surface_content_of_circle_segment_under_surface) * p1p2_hesse_os.k[1];
              v38 = (float)(1.0 / surface_content_of_circle_segment_under_surface)
                  * (float)((float)(v50 * edge_Q_center_os.k[2]) + (float)(v45 * v179));
              v39 = (float)(1.0 / surface_content_of_circle_segment_under_surface)
                  * (float)((float)(hesse_val * v179) + (float)(v50 * edge_Q_center_os.hesse_val));
            }
            else
            {
              v37 = 0.0;
              v38 = 0.0;
              v39 = 0.0;
              v36 = 0.0;
            }
          }
          else
          {
            v36 = 0.0;
            v37 = 0.0;
            v38 = 0.0;
            v39 = 0.0;
          }
          v51 = this->buoyancy_eps;
          v14 = v36 + s;
          surface_content_of_whole_ellipse = v36 + s;
          if ( v51 <= (float)(v36 + s) )
          {
            direction_up_4.k[0] = (float)(1.0 / v14) * (float)((float)(v37 * v36) + (float)(O_os.k[1] * s));
            direction_up_4.k[1] = (float)(1.0 / v14) * (float)((float)(v38 * v36) + (float)(O_os.k[2] * s));
            v15 = (float)(1.0 / v14) * (float)((float)(v39 * v36) + (float)(O_os.hesse_val * s));
            goto LABEL_83;
          }
          goto LABEL_25;
        }
        IVP_U_Hesse::proj_on_plane(this: surface_os, p: geom_center_os, result: (IVP_U_Float_Point *)v161);
        IVP_U_Hesse::proj_on_plane(
          this: (IVP_U_Float_Hesse *)&projected_center_on_ellipse_os.k[1],
          p: (const IVP_U_Float_Point *)v161,
          result: (IVP_U_Float_Point *)&center_of_circle_segment_under_surface.k[1]);
        p1p2_hesse_os.k[1] = center_of_circle_segment_under_surface.k[1] - MQ_os.k[1];
        p1p2_hesse_os.k[2] = center_of_circle_segment_under_surface.k[2] - MQ_os.k[2];
        p1p2_hesse_os.hesse_val = center_of_circle_segment_under_surface.hesse_val - MQ_os.hesse_val;
        s = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Hesse *)&p1p2_hesse_os.k[1]);
        v52 = *distance;
        p1p2_os.k[1] = center_of_circle_segment_under_surface.k[1] - speed_plane_os.k[1];
        p1p2_os.k[2] = center_of_circle_segment_under_surface.k[2] - speed_plane_os.k[2];
        p1p2_os.hesse_val = center_of_circle_segment_under_surface.hesse_val - speed_plane_os.hesse_val;
        surface_content_up = (float)(*radius * *radius) - (float)(v52 * v52);
        v53 = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Point *)&p1p2_os.k[1]);
        rel_speed_of_current_os.k[1] = speed_plane_os.k[1] - geom_center_os->k[0];
        surface_content_of_ellipse_segment = fabs(s - v53);
        rel_speed_of_current_os.k[2] = speed_plane_os.k[2] - geom_center_os->k[1];
        rel_speed_of_current_os.hesse_val = speed_plane_os.hesse_val - geom_center_os->k[2];
        v179 = *radius;
        v54 = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Point *)&rel_speed_of_current_os.k[1]);
        ball_projected_surface_content_under = v179 - v54;
        v55 = IVP_Inline_Math::fast_asin(angle: surface_content_of_circle_segment_under_surface / (float)(v179 * 2.0));
        v56 = this->buoyancy_eps;
        v178 = fabs(
                 ((v55 + v55) * v179 * v179
                - (v179 - ball_projected_surface_content_under) * surface_content_of_circle_segment_under_surface)
               * 0.5);
        v57 = v178;
        if ( v56 > v178 )
        {
LABEL_25:
          v14 = 0.0;
          surface_content_of_whole_ellipse = 0.0;
          goto calculate_impulse;
        }
        v58 = s;
        if ( v56 <= s )
        {
          v59 = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Point *)&p1p2_os.k[1]);
          angle = v59 / s;
          v60 = IVP_Inline_Math::save_acosf(angle);
          ball_projected_surface_content_under = v60 * (sqrt(fabs(surface_content_up)) * s);
          v61 = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Point *)&p1p2_os.k[1]);
          v58 = s;
          v57 = v178;
          surface_content_up = ball_projected_surface_content_under
                             - v61 * (surface_content_of_circle_segment_under_surface * 0.5);
        }
        else
        {
          surface_content_up = 0.0;
        }
        v62 = this->buoyancy_eps;
        surface_content_of_whole_ellipse = v57 - surface_content_up;
        v177 = v62;
        if ( v62 <= (float)(v57 - surface_content_up) )
        {
          v63 = geom_center_os->k[2];
          v64 = geom_center_os->k[1];
          v65 = (float)((float)(surface_content_of_circle_segment_under_surface
                              * surface_content_of_circle_segment_under_surface)
                      * surface_content_of_circle_segment_under_surface)
              / (float)(v57 * 12.0);
          edge_Q_center_os.k[1] = (float)(v65 * center_of_ellipse_os.k[1]) + geom_center_os->k[0];
          edge_Q_center_os.hesse_val = (float)(v65 * center_of_ellipse_os.hesse_val) + v63;
          edge_Q_center_os.k[2] = (float)(v65 * center_of_ellipse_os.k[2]) + v64;
          surface_content_of_circle_segment_under_surface = fsqrt(
                                                              COERCE_FLOAT(
                                                                COERCE_UNSIGNED_INT(
                                                                  (float)((float)(surface_content_of_ellipse_segment
                                                                                * 2.0)
                                                                        * v58)
                                                                - (float)(surface_content_of_ellipse_segment
                                                                        * surface_content_of_ellipse_segment))
                                                              & _mask__AbsFloat_))
                                                          * 2.0;
          v66 = IVP_Inline_Math::fast_asin(angle: surface_content_of_circle_segment_under_surface / (float)(v58 * 2.0));
          ball_projected_surface_content_under = ((v66 + v66) * s * s
                                                - (s - surface_content_of_ellipse_segment)
                                                * surface_content_of_circle_segment_under_surface)
                                               * 0.5;
          if ( v177 > s || v177 > ball_projected_surface_content_under )
          {
            v68 = 0.0;
            v69 = 0.0;
            v70 = 0.0;
          }
          else
          {
            v67 = (float)((float)(surface_content_of_circle_segment_under_surface
                                * surface_content_of_circle_segment_under_surface)
                        * surface_content_of_circle_segment_under_surface)
                / (float)(ball_projected_surface_content_under * 12.0);
            v68 = (float)(v67 * center_of_ellipse_os.k[1]) + center_of_circle_segment_under_surface.k[1];
            v69 = (float)(v67 * center_of_ellipse_os.k[2]) + center_of_circle_segment_under_surface.k[2];
            v70 = (float)(v67 * center_of_ellipse_os.hesse_val) + center_of_circle_segment_under_surface.hesse_val;
          }
          v14 = surface_content_of_whole_ellipse;
          direction_up_4.k[0] = (float)(1.0 / surface_content_of_whole_ellipse)
                              * (float)((float)(edge_Q_center_os.k[1] * v178)
                                      + (float)(COERCE_FLOAT(LODWORD(surface_content_up) ^ _mask__NegFloat_) * v68));
          direction_up_4.k[1] = (float)(1.0 / surface_content_of_whole_ellipse)
                              * (float)((float)(COERCE_FLOAT(LODWORD(surface_content_up) ^ _mask__NegFloat_) * v69)
                                      + (float)(edge_Q_center_os.k[2] * v178));
          v15 = (float)(1.0 / surface_content_of_whole_ellipse)
              * (float)((float)(v178 * edge_Q_center_os.hesse_val)
                      + (float)(COERCE_FLOAT(LODWORD(surface_content_up) ^ _mask__NegFloat_) * v70));
LABEL_83:
          direction_up_4.k[2] = v15;
        }
        else
        {
          v14 = 0.0;
          surface_content_of_whole_ellipse = 0.0;
        }
      }
calculate_impulse:
      v148 = (float)((float)(tmp_O1_os.k[2] * tmp_O1_os.k[2]) + (float)(tmp_O1_os.k[1] * tmp_O1_os.k[1]))
           + (float)(tmp_O1_os.hesse_val * tmp_O1_os.hesse_val);
      if ( this->buoyancy_eps > v148 )
      {
        v148 = 0.0;
        tmp_O1_os.k[1] = 0.0;
        tmp_O1_os.k[2] = 1.0;
        tmp_O1_os.hesse_val = 0.0;
      }
      v149 = (float)(v148 * v14) * this->pressure_damp_factor;
      v150 = (float)((float)(v14 * 3.0) * v148) * this->friction_damp_factor;
      surface_content_of_ellipse_segment = v149;
      ball_projected_surface_content_under = v150;
      IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)&tmp_O1_os.k[1]);
      v151 = tmp_O1_os.hesse_val * (float)(ball_projected_surface_content_under + surface_content_of_ellipse_segment);
      v152 = tmp_O1_os.k[1] * (float)(ball_projected_surface_content_under + surface_content_of_ellipse_segment);
      v153 = tmp_O1_os.k[2] * (float)(ball_projected_surface_content_under + surface_content_of_ellipse_segment);
      this->object_visible_surface_content_under = this->object_visible_surface_content_under
                                                 + surface_content_of_whole_ellipse;
      v154 = this->sum_impulse_x_point.k[0];
      v155 = (float)(v151 * direction_up_4.k[1]) - (float)(v153 * direction_up_4.k[2]);
      this->sum_impulse_x_point.k[1] = (float)((float)(direction_up_4.k[2] * v152) - (float)(v151 * direction_up_4.k[0]))
                                     + this->sum_impulse_x_point.k[1];
      this->sum_impulse_x_point.k[0] = v154 + v155;
      this->sum_impulse_x_point.k[2] = (float)((float)(v153 * direction_up_4.k[0]) - (float)(v152 * direction_up_4.k[1]))
                                     + this->sum_impulse_x_point.k[2];
      this->sum_impulse_x_movevector.k[0] = (float)((float)(v151 * 0.0) - (float)(v153 * 0.0))
                                          + this->sum_impulse_x_movevector.k[0];
      this->sum_impulse_x_movevector.k[1] = (float)((float)(v152 * 0.0) - (float)(v151 * 0.0))
                                          + this->sum_impulse_x_movevector.k[1];
      this->sum_impulse_x_movevector.k[2] = (float)((float)(v153 * 0.0) - (float)(v152 * 0.0))
                                          + this->sum_impulse_x_movevector.k[2];
      v156 = v153 + this->sum_impulse.k[1];
      v157 = v151 + this->sum_impulse.k[2];
      this->sum_impulse.k[0] = v152 + this->sum_impulse.k[0];
      this->sum_impulse.k[1] = v156;
      this->sum_impulse.k[2] = v157;
      return;
    case 2:
      v16 = surface_os;
      goto case_2;
    case 3:
      IVP_U_Hesse::proj_on_plane(
        this: (IVP_U_Float_Hesse *)&projected_center_on_ellipse_os.k[1],
        p: surface_os,
        result: (IVP_U_Float_Point *)&center_of_circle_segment_under_surface.k[1]);
      center_of_circle_segment_under_surface.k[1] = center_of_circle_segment_under_surface.k[1] * -1.0;
      center_of_circle_segment_under_surface.k[2] = center_of_circle_segment_under_surface.k[2] * -1.0;
      center_of_circle_segment_under_surface.hesse_val = center_of_circle_segment_under_surface.hesse_val * -1.0;
      if ( this->buoyancy_eps > (float)((float)((float)(center_of_circle_segment_under_surface.k[1]
                                                      * center_of_circle_segment_under_surface.k[1])
                                              + (float)(center_of_circle_segment_under_surface.k[2]
                                                      * center_of_circle_segment_under_surface.k[2]))
                                      + (float)(center_of_circle_segment_under_surface.hesse_val
                                              * center_of_circle_segment_under_surface.hesse_val)) )
        goto LABEL_76;
      IVP_U_Float_Point::fast_normize(this: (IVP_U_Float_Point *)&center_of_circle_segment_under_surface.k[1]);
      v71 = p1_os->k[0];
      v72 = p1_os->k[1];
      v73 = p1_os->k[2];
      v74 = p2_os->k[1] - v72;
      v75 = p2_os->k[2] - v73;
      p1p2_os.k[1] = p2_os->k[0] - p1_os->k[0];
      p1p2_os.k[2] = v74;
      p1p2_os.hesse_val = v75;
      center_of_ellipse_os.k[1] = (float)(p1p2_os.k[1] * 0.5) + v71;
      center_of_ellipse_os.k[2] = (float)(v74 * 0.5) + v72;
      center_of_ellipse_os.hesse_val = (float)(v75 * 0.5) + v73;
      v76 = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Point *)&p1p2_os.k[1]);
      s = v76;
      if ( this->buoyancy_eps > v76 )
      {
        v14 = (float)(*radius * 3.1415927) * *radius;
        *(_QWORD *)direction_up_4.k = *(_QWORD *)geom_center_os->k;
        v15 = geom_center_os->k[2];
        surface_content_of_whole_ellipse = v14;
        goto LABEL_83;
      }
      edge_Q_center_os.k[1] = p1p2_os.k[1];
      edge_Q_center_os.k[2] = p1p2_os.k[2];
      edge_Q_center_os.hesse_val = p1p2_os.hesse_val;
      IVP_U_Float_Hesse::calc_hesse_val(
        this: (IVP_U_Float_Hesse *)&edge_Q_center_os.k[1],
        p0: (IVP_U_Float_Point *)&center_of_ellipse_os.k[1]);
      IVP_U_Hesse::normize(this: (IVP_U_Float_Hesse *)&edge_Q_center_os.k[1]);
      IVP_Buoyancy_Solver::compute_disection_points_with_ball(
        this,
        a2: COERCE_FLOAT(&surface_content_circle),
        plane1_os: surface_os,
        plane2_os: (const IVP_U_Float_Hesse *)&edge_Q_center_os.k[1],
        geom_center_os,
        radius,
        p1_os: (IVP_U_Float_Point *)&projected_center_on_surface_os.k[1],
        p2_os: (IVP_U_Float_Point *)&tmp_O2_os.k[1]);
      if ( (float)((float)((float)(projected_center_on_ellipse_os.k[1]
                                 * (float)(tmp_O2_os.k[1] - projected_center_on_surface_os.k[1]))
                         + (float)((float)(tmp_O2_os.k[2] - projected_center_on_surface_os.k[2])
                                 * projected_center_on_ellipse_os.k[2]))
                 + (float)((float)(tmp_O2_os.hesse_val - projected_center_on_surface_os.hesse_val)
                         * projected_center_on_ellipse_os.hesse_val)) < 0.0 )
        IVP_U_Hesse::proj_on_plane(
          this: (IVP_U_Float_Hesse *)&projected_center_on_ellipse_os.k[1],
          p: (IVP_U_Float_Point *)&tmp_O2_os.k[1],
          result: (IVP_U_Float_Point *)&MQ_os.k[1]);
      else
        IVP_U_Hesse::proj_on_plane(
          this: (IVP_U_Float_Hesse *)&projected_center_on_ellipse_os.k[1],
          p: (IVP_U_Float_Point *)&projected_center_on_surface_os.k[1],
          result: (IVP_U_Float_Point *)&MQ_os.k[1]);
      IVP_U_Hesse::proj_on_plane(this: surface_os, p: geom_center_os, result: (IVP_U_Float_Point *)v161);
      IVP_U_Hesse::proj_on_plane(
        this: (IVP_U_Float_Hesse *)&projected_center_on_ellipse_os.k[1],
        p: (const IVP_U_Float_Point *)v161,
        result: (IVP_U_Float_Hesse *)&speed_plane_os.k[1]);
      v77 = this->buoyancy_eps;
      v178 = (float)((float)(projected_center_on_ellipse_os.k[2] * surface_os->k[1])
                   + (float)(projected_center_on_ellipse_os.k[1] * surface_os->k[0]))
           + (float)(projected_center_on_ellipse_os.hesse_val * surface_os->k[2]);
      if ( v77 >= v178 )
      {
        p1p2_hesse_os.k[1] = center_of_ellipse_os.k[1] - geom_center_os->k[0];
        p1p2_hesse_os.k[2] = center_of_ellipse_os.k[2] - geom_center_os->k[1];
        p1p2_hesse_os.hesse_val = center_of_ellipse_os.hesse_val - geom_center_os->k[2];
        v179 = *radius;
        v78 = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Hesse *)&p1p2_hesse_os.k[1]);
        ball_projected_surface_content_under = v179 - v78;
        v79 = IVP_Inline_Math::fast_asin(angle: s / (float)(v179 * 2.0));
        surface_content_of_ellipse_segment = (float)(v179 * 3.1415927) * v179;
        ball_projected_surface_content_under = fabs(
                                                 ((v79 + v79) * v179 * v179
                                                - (v179 - ball_projected_surface_content_under) * s)
                                               * 0.5);
        surface_content_up = fabs(surface_content_of_ellipse_segment - ball_projected_surface_content_under);
        if ( this->buoyancy_eps <= ball_projected_surface_content_under )
        {
          v80 = geom_center_os->k[0];
          v81 = geom_center_os->k[1];
          v82 = geom_center_os->k[2];
          v83 = -ball_projected_surface_content_under;
          v84 = (float)((float)(s * s) * s) / (float)(ball_projected_surface_content_under * 12.0);
          if ( v178 > (float)-this->buoyancy_eps )
          {
            v85 = (float)((float)-v84 * surface_os->k[1]) + v81;
            v86 = (float)(v82 * surface_content_of_ellipse_segment)
                + (float)(v83 * (float)((float)((float)-v84 * surface_os->k[2]) + v82));
            v14 = surface_content_up;
            O_os.k[1] = (float)(1.0 / surface_content_up)
                      * (float)((float)(v80 * surface_content_of_ellipse_segment)
                              + (float)(v83 * (float)((float)(surface_os->k[0] * (float)-v84) + v80)));
            O_os.k[2] = (float)(1.0 / surface_content_up)
                      * (float)((float)(v81 * surface_content_of_ellipse_segment) + (float)(v83 * v85));
            O_os.hesse_val = (float)(1.0 / surface_content_up) * v86;
            si128 = _mm_load_si128((const __m128i *)&O_os.k[1]);
            surface_content_of_whole_ellipse = surface_content_up;
            direction_up_4 = (IVP_U_Float_Point)si128;
            goto calculate_impulse;
          }
          O_os.k[1] = (float)(1.0 / surface_content_up)
                    * (float)((float)(v80 * surface_content_of_ellipse_segment)
                            + (float)(v83 * (float)((float)(center_of_circle_segment_under_surface.k[1] * v84) + v80)));
          O_os.k[2] = (float)(1.0 / surface_content_up)
                    * (float)((float)(v81 * surface_content_of_ellipse_segment)
                            + (float)(v83 * (float)((float)(center_of_circle_segment_under_surface.k[2] * v84) + v81)));
          O_os.hesse_val = (float)(1.0 / surface_content_up)
                         * (float)((float)(v82 * surface_content_of_ellipse_segment)
                                 + (float)(v83
                                         * (float)((float)(center_of_circle_segment_under_surface.hesse_val * v84) + v82)));
        }
        else
        {
          *(_QWORD *)direction_up_4.k = *(_QWORD *)geom_center_os->k;
          direction_up_4.k[2] = geom_center_os->k[2];
        }
        rel_speed_of_current_os.k[1] = speed_plane_os.k[1] - MQ_os.k[1];
        rel_speed_of_current_os.k[2] = speed_plane_os.k[2] - MQ_os.k[2];
        rel_speed_of_current_os.hesse_val = speed_plane_os.hesse_val - MQ_os.hesse_val;
        surface_content_of_circle_segment_under_surface = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Point *)&rel_speed_of_current_os.k[1]);
        v88 = *distance;
        center_of_segment_os.k[1] = speed_plane_os.k[1] - center_of_ellipse_os.k[1];
        center_of_segment_os.k[2] = speed_plane_os.k[2] - center_of_ellipse_os.k[2];
        center_of_segment_os.hesse_val = speed_plane_os.hesse_val - center_of_ellipse_os.hesse_val;
        ball_projected_surface_content_under = (float)(*radius * *radius) - (float)(v88 * v88);
        v89 = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Point *)&center_of_segment_os.k[1]);
        v90 = this->buoyancy_eps;
        surface_content_of_ellipse_segment = fabs(surface_content_of_circle_segment_under_surface - v89);
        if ( v90 > surface_content_of_circle_segment_under_surface )
          goto LABEL_54;
        v91 = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Point *)&center_of_segment_os.k[1]);
        anglea = v91 / surface_content_of_circle_segment_under_surface;
        v92 = IVP_Inline_Math::save_acosf(angle: anglea);
        ball_projected_surface_content_under = v92
                                             * (sqrt(fabs(ball_projected_surface_content_under))
                                              * surface_content_of_circle_segment_under_surface);
        v93 = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Point *)&center_of_segment_os.k[1]);
        v177 = ball_projected_surface_content_under - v93 * (s * 0.5);
        v178 = fsqrt(
                 COERCE_FLOAT(
                   COERCE_UNSIGNED_INT(
                     (float)((float)(surface_content_of_ellipse_segment * 2.0)
                           * surface_content_of_circle_segment_under_surface)
                   - (float)(surface_content_of_ellipse_segment * surface_content_of_ellipse_segment))
                 & _mask__AbsFloat_))
             * 2.0;
        v94 = IVP_Inline_Math::fast_asin(angle: v178 / (float)(surface_content_of_circle_segment_under_surface * 2.0));
        v90 = this->buoyancy_eps;
        ball_projected_surface_content_under = fabs(
                                                 ((v94 + v94)
                                                * surface_content_of_circle_segment_under_surface
                                                * surface_content_of_circle_segment_under_surface
                                                - (surface_content_of_circle_segment_under_surface
                                                 - surface_content_of_ellipse_segment)
                                                * v178)
                                               * 0.5);
        if ( v90 <= ball_projected_surface_content_under )
        {
          v95 = v177;
          v98 = (float)((float)(v178 * v178) * v178) / (float)(ball_projected_surface_content_under * 12.0);
          p1p2_hesse_os.k[1] = (float)(center_of_circle_segment_under_surface.k[1] * v98) + speed_plane_os.k[1];
          v96 = (float)(center_of_circle_segment_under_surface.k[2] * v98) + speed_plane_os.k[2];
          v97 = (float)(center_of_circle_segment_under_surface.hesse_val * v98) + speed_plane_os.hesse_val;
        }
        else
        {
LABEL_54:
          v95 = 0.0;
          p1p2_hesse_os.k[1] = 0.0;
          v96 = 0.0;
          v97 = 0.0;
        }
        v14 = v95 + surface_content_up;
        surface_content_of_whole_ellipse = v95 + surface_content_up;
        if ( v90 > (float)(v95 + surface_content_up) )
        {
          v14 = 0.0;
          surface_content_of_whole_ellipse = 0.0;
          *(_QWORD *)direction_up_4.k = 0;
          direction_up_4.k[2] = 0.0;
          goto calculate_impulse;
        }
        direction_up_4.k[2] = O_os.hesse_val * surface_content_up;
        direction_up_4.k[0] = (float)(1.0 / v14)
                            * (float)((float)(v95 * p1p2_hesse_os.k[1]) + (float)(surface_content_up * O_os.k[1]));
        direction_up_4.k[1] = (float)(1.0 / v14) * (float)((float)(v96 * v95) + (float)(O_os.k[2] * surface_content_up));
        v15 = (float)(1.0 / v14) * (float)((float)(v97 * v95) + (float)(O_os.hesse_val * surface_content_up));
        goto LABEL_83;
      }
      p1p2_hesse_os.k[1] = speed_plane_os.k[1] - MQ_os.k[1];
      p1p2_hesse_os.k[2] = speed_plane_os.k[2] - MQ_os.k[2];
      p1p2_hesse_os.hesse_val = speed_plane_os.hesse_val - MQ_os.hesse_val;
      surface_content_of_circle_segment_under_surface = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Hesse *)&p1p2_hesse_os.k[1]);
      v99 = *distance;
      center_of_segment_os.k[1] = speed_plane_os.k[1] - center_of_ellipse_os.k[1];
      center_of_segment_os.k[2] = speed_plane_os.k[2] - center_of_ellipse_os.k[2];
      center_of_segment_os.hesse_val = speed_plane_os.hesse_val - center_of_ellipse_os.hesse_val;
      surface_content_of_ellipse_segment = fsqrt(
                                             COERCE_FLOAT(
                                               COERCE_UNSIGNED_INT((float)(*radius * *radius) - (float)(v99 * v99))
                                             & _mask__AbsFloat_));
      v100 = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Point *)&center_of_segment_os.k[1]);
      rel_speed_of_current_os.k[1] = center_of_ellipse_os.k[1] - geom_center_os->k[0];
      ball_projected_surface_content_under = fabs(surface_content_of_circle_segment_under_surface - v100);
      rel_speed_of_current_os.k[2] = center_of_ellipse_os.k[2] - geom_center_os->k[1];
      rel_speed_of_current_os.hesse_val = center_of_ellipse_os.hesse_val - geom_center_os->k[2];
      v179 = *radius;
      v101 = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Point *)&rel_speed_of_current_os.k[1]);
      surface_content_up = v179 - v101;
      v102 = IVP_Inline_Math::fast_asin(angle: s / (float)(v179 * 2.0));
      v103 = this->buoyancy_eps;
      v178 = fabs(((v102 + v102) * v179 * v179 - (v179 - surface_content_up) * s) * 0.5);
      v104 = v178;
      if ( v103 <= v178 )
      {
        if ( v103 <= surface_content_of_circle_segment_under_surface )
        {
          v105 = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Point *)&center_of_segment_os.k[1]);
          angleb = v105 / surface_content_of_circle_segment_under_surface;
          v106 = IVP_Inline_Math::save_acosf(angle: angleb);
          surface_content_up = v106
                             * (surface_content_of_ellipse_segment
                              * surface_content_of_circle_segment_under_surface);
          v107 = IVP_U_Float_Point::fast_real_length(this: (IVP_U_Float_Point *)&center_of_segment_os.k[1]);
          v104 = v178;
          surface_content_up = surface_content_up - v107 * (s * 0.5);
        }
        else
        {
          surface_content_up = 0.0;
        }
        v179 = *radius;
        v108 = this->buoyancy_eps;
        LODWORD(surface_content_of_whole_ellipse) = COERCE_UNSIGNED_INT(
                                                      (float)((float)((float)(v179 * v179)
                                                                    - (float)(surface_content_of_ellipse_segment
                                                                            * surface_content_of_circle_segment_under_surface))
                                                            * 3.1415927)
                                                    - COERCE_FLOAT(
                                                        COERCE_UNSIGNED_INT(v104 - surface_content_up)
                                                      & _mask__AbsFloat_))
                                                  & _mask__AbsFloat_;
        v177 = v108;
        if ( v108 > surface_content_of_whole_ellipse )
        {
          v14 = 0.0;
          surface_content_of_whole_ellipse = 0.0;
          goto calculate_impulse;
        }
        v109 = geom_center_os->k[2];
        v110 = geom_center_os->k[0];
        v111 = geom_center_os->k[1];
        v112 = (float)((float)(s * s) * s) / (float)(v104 * 12.0);
        v113 = (float)((float)(center_of_circle_segment_under_surface.k[1] * v112) + geom_center_os->k[0])
             * COERCE_FLOAT(LODWORD(v178) ^ _mask__NegFloat_);
        v114 = (float)((float)(center_of_circle_segment_under_surface.k[2] * v112) + v111)
             * COERCE_FLOAT(LODWORD(v178) ^ _mask__NegFloat_);
        center_of_ellipse_os.hesse_val = (float)((float)(center_of_circle_segment_under_surface.hesse_val * v112) + v109)
                                       * COERCE_FLOAT(LODWORD(v178) ^ _mask__NegFloat_);
        v115 = (float)(v179 * 3.1415927) * v179;
        v116 = (float)(v109 * v115) + center_of_ellipse_os.hesse_val;
        v117 = (float)(v111 * v115) + v114;
        v118 = (float)(v110 * v115) + v113;
        v119 = fabs(v115 - v178);
        s = v119;
        if ( v177 <= v119 )
        {
          center_of_ellipse_os.k[1] = (float)(1.0 / v119) * v118;
          center_of_ellipse_os.k[2] = v117 * (float)(1.0 / v119);
          center_of_ellipse_os.hesse_val = v116 * (float)(1.0 / v119);
        }
        else
        {
          s = 0.0;
          memset(&center_of_ellipse_os.k[1], 0, 12);
        }
        v178 = fsqrt(
                 fabs(
                   (float)((float)(ball_projected_surface_content_under * 2.0)
                         * surface_content_of_circle_segment_under_surface)
                 - (float)(ball_projected_surface_content_under * ball_projected_surface_content_under)))
             * 2.0;
        v120 = IVP_Inline_Math::fast_asin(angle: v178 / (float)(surface_content_of_circle_segment_under_surface * 2.0));
        ball_projected_surface_content_under = ((v120 + v120)
                                              * surface_content_of_circle_segment_under_surface
                                              * surface_content_of_circle_segment_under_surface
                                              - (surface_content_of_circle_segment_under_surface
                                               - ball_projected_surface_content_under)
                                              * v178)
                                             * 0.5;
        if ( v177 > surface_content_of_circle_segment_under_surface || v177 > ball_projected_surface_content_under )
        {
          v122 = 0.0;
          v123 = 0.0;
          v124 = 0.0;
        }
        else
        {
          v121 = (float)((float)(v178 * v178) * v178) / (float)(ball_projected_surface_content_under * 12.0);
          v122 = (float)(center_of_circle_segment_under_surface.k[1] * v121) + speed_plane_os.k[1];
          v123 = (float)(center_of_circle_segment_under_surface.k[2] * v121) + speed_plane_os.k[2];
          v124 = (float)(center_of_circle_segment_under_surface.hesse_val * v121) + speed_plane_os.hesse_val;
        }
        v125 = (float)(surface_content_of_ellipse_segment * 3.1415927) * surface_content_of_circle_segment_under_surface;
        v126 = v122 * COERCE_FLOAT(LODWORD(surface_content_up) ^ _mask__NegFloat_);
        v127 = v125 * speed_plane_os.k[1];
        v128 = speed_plane_os.k[2] * v125;
        v129 = speed_plane_os.hesse_val * v125;
        LODWORD(v130) = COERCE_UNSIGNED_INT(v125 - surface_content_up) & _mask__AbsFloat_;
        v131 = v128 + (float)(v123 * COERCE_FLOAT(LODWORD(surface_content_up) ^ _mask__NegFloat_));
        v132 = v127 + v126;
        v133 = v129 + (float)(v124 * COERCE_FLOAT(LODWORD(surface_content_up) ^ _mask__NegFloat_));
        if ( v177 <= v130 )
        {
          v134 = (float)(1.0 / v130) * v132;
          v135 = v131 * (float)(1.0 / v130);
          v136 = v133 * (float)(1.0 / v130);
        }
        else
        {
          v134 = 0.0;
          v135 = 0.0;
          v136 = 0.0;
          v130 = 0.0;
        }
        LODWORD(v137) = LODWORD(v130) ^ _mask__NegFloat_;
        v138 = v137 * v134;
        v139 = (float)(v135 * v137) + (float)(center_of_ellipse_os.k[2] * s);
        v140 = (float)(v136 * v137) + (float)(center_of_ellipse_os.hesse_val * s);
        v14 = surface_content_of_whole_ellipse;
        direction_up_4.k[0] = (float)(1.0 / surface_content_of_whole_ellipse)
                            * (float)((float)(s * center_of_ellipse_os.k[1]) + v138);
        direction_up_4.k[1] = (float)(1.0 / surface_content_of_whole_ellipse) * v139;
        v15 = (float)(1.0 / surface_content_of_whole_ellipse) * v140;
        goto LABEL_83;
      }
LABEL_76:
      v12 = projected_center_on_ellipse_os.k[1];
case_4:
      v141 = (float)((float)(surface_os->k[1] * projected_center_on_ellipse_os.k[2]) + (float)(v12 * surface_os->k[0]))
           + (float)(surface_os->k[2] * projected_center_on_ellipse_os.hesse_val);
      if ( v141 <= 0.0 )
      {
        v14 = (float)(*radius * 3.1415927) * *radius;
        *(_QWORD *)direction_up_4.k = *(_QWORD *)geom_center_os->k;
        v15 = geom_center_os->k[2];
        surface_content_of_whole_ellipse = v14;
        goto LABEL_83;
      }
      v142 = (float)(*radius * 3.1415927) * *radius;
      v143 = (float)((float)(*radius * *radius) - (float)(*distance * *distance)) * (float)(v141 * 3.1415927);
      LODWORD(v144) = COERCE_UNSIGNED_INT(v142 - v143) & _mask__AbsFloat_;
      ball_projected_surface_content_under = v143;
      v145 = this->buoyancy_eps;
      surface_content_of_ellipse_segment = v142;
      surface_content_of_whole_ellipse = v144;
      if ( v145 <= v144 )
      {
        IVP_U_Hesse::proj_on_plane(this: surface_os, p: geom_center_os, result: (IVP_U_Float_Point *)v161);
        IVP_U_Hesse::proj_on_plane(
          this: (IVP_U_Float_Hesse *)&projected_center_on_ellipse_os.k[1],
          p: (const IVP_U_Float_Point *)v161,
          result: (IVP_U_Float_Hesse *)&p1p2_hesse_os.k[1]);
        v146 = (float)(geom_center_os->k[1] * surface_content_of_ellipse_segment)
             + (float)(p1p2_hesse_os.k[2]
                     * COERCE_FLOAT(LODWORD(ball_projected_surface_content_under) ^ _mask__NegFloat_));
        v14 = surface_content_of_whole_ellipse;
        v147 = (float)(geom_center_os->k[2] * surface_content_of_ellipse_segment)
             + (float)(p1p2_hesse_os.hesse_val
                     * COERCE_FLOAT(LODWORD(ball_projected_surface_content_under) ^ _mask__NegFloat_));
        direction_up_4.k[0] = (float)(1.0 / surface_content_of_whole_ellipse)
                            * (float)((float)(geom_center_os->k[0] * surface_content_of_ellipse_segment)
                                    + (float)(p1p2_hesse_os.k[1]
                                            * COERCE_FLOAT(LODWORD(ball_projected_surface_content_under) ^ _mask__NegFloat_)));
        v31 = (float)(1.0 / surface_content_of_whole_ellipse) * v146;
        v15 = (float)(1.0 / surface_content_of_whole_ellipse) * v147;
LABEL_82:
        direction_up_4.k[1] = v31;
        goto LABEL_83;
      }
      goto LABEL_80;
    case 4:
      goto case_4;
    default:
      goto calculate_impulse;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A3A30
// Name: private: void IVP_Buoyancy_Solver::compute_values_for_one_ball(class IVP_Real_Object const __near *,class IVP_U_Float_Hesse const __near *,class IVP_U_Float_Point const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge IVP_Buoyancy_Solver::compute_values_for_one_ball(
        IVP_Buoyancy_Solver *this@<ecx>,
        float a2@<ebp>,
        const IVP_Real_Object *object,
        IVP_U_Float_Hesse *surface_os,
        const IVP_U_Float_Point *rel_speed_of_current_os)
{
  float v6; // xmm2_4
  float v7; // xmm3_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  int v11; // eax
  _BYTE v12[12]; // [esp-Ch] [ebp-5Ch] BYREF
  IVP_U_Float_Point p1_os; // [esp+0h] [ebp-50h] BYREF
  IVP_U_Float_Point p2_os; // [esp+10h] [ebp-40h] BYREF
  IVP_U_Float_Point geom_center_os; // [esp+20h] [ebp-30h] BYREF
  IVP_U_Float_Hesse speed_plane_os; // [esp+30h] [ebp-20h] BYREF
  float extra_radius; // [esp+40h] [ebp-10h] BYREF
  float distance; // [esp+44h] [ebp-Ch] BYREF
  int decision; // [esp+48h] [ebp-8h]
  int retaddr; // [esp+50h] [ebp+0h]

  distance = a2;
  decision = retaddr;
  v6 = rel_speed_of_current_os->k[1];
  v7 = rel_speed_of_current_os->k[2];
  v8 = 0.0;
  extra_radius = object->extra_radius;
  v9 = rel_speed_of_current_os->k[0];
  memset(&p2_os.k[1], 0, 12);
  if ( (float)((float)((float)(v9 * v9) + (float)(v6 * v6)) + (float)(v7 * v7)) >= 1.0e-10 )
  {
    geom_center_os.k[2] = rel_speed_of_current_os->k[1];
    v8 = rel_speed_of_current_os->k[2];
    geom_center_os.k[1] = v9;
  }
  else
  {
    geom_center_os.k[1] = 0.0;
    geom_center_os.k[2] = 1.0;
  }
  geom_center_os.hesse_val = v8;
  IVP_U_Float_Hesse::calc_hesse_val(
    this: (IVP_U_Float_Hesse *)&geom_center_os.k[1],
    p0: (IVP_U_Float_Point *)&p2_os.k[1]);
  IVP_U_Hesse::normize(this: (IVP_U_Float_Hesse *)&geom_center_os.k[1]);
  v10 = (float)((float)((float)(surface_os->k[1] * p2_os.k[2]) + (float)(surface_os->k[0] * p2_os.k[1]))
              + (float)(surface_os->k[2] * p2_os.hesse_val))
      + surface_os->hesse_val;
  speed_plane_os.k[2] = v10;
  if ( v10 <= 0.0 )
  {
    if ( COERCE_FLOAT(LODWORD(v10) & _mask__AbsFloat_) >= extra_radius )
      return;
    v11 = 2
        - (IVP_Buoyancy_Solver::compute_disection_points_with_ball(
             this,
             a2: COERCE_FLOAT(&distance),
             plane1_os: surface_os,
             plane2_os: (const IVP_U_Float_Hesse *)&geom_center_os.k[1],
             geom_center_os: (IVP_U_Float_Point *)&p2_os.k[1],
             radius: &extra_radius,
             p1_os: (IVP_U_Float_Point *)v12,
             p2_os: (IVP_U_Float_Point *)&p1_os.k[1]) != 0);
    goto LABEL_10;
  }
  if ( v10 < extra_radius )
  {
    v11 = 4
        - (IVP_Buoyancy_Solver::compute_disection_points_with_ball(
             this,
             a2: COERCE_FLOAT(&distance),
             plane1_os: surface_os,
             plane2_os: (const IVP_U_Float_Hesse *)&geom_center_os.k[1],
             geom_center_os: (IVP_U_Float_Point *)&p2_os.k[1],
             radius: &extra_radius,
             p1_os: (IVP_U_Float_Point *)v12,
             p2_os: (IVP_U_Float_Point *)&p1_os.k[1]) != 0);
LABEL_10:
    LODWORD(speed_plane_os.hesse_val) = v11;
    goto LABEL_11;
  }
  speed_plane_os.hesse_val = 0.0;
LABEL_11:
  IVP_Buoyancy_Solver::compute_buoyancy_values_for_one_ball(
    this,
    decision: (const int *)&speed_plane_os.hesse_val,
    distance: &speed_plane_os.k[2],
    radius: &extra_radius,
    surface_os,
    geom_center_os: (IVP_U_Float_Point *)&p2_os.k[1]);
  IVP_Buoyancy_Solver::compute_dampening_values_for_one_ball(
    this,
    a2: COERCE_FLOAT(&distance),
    decision: (const int *)&speed_plane_os.hesse_val,
    distance: &speed_plane_os.k[2],
    radius: &extra_radius,
    geom_center_os: (IVP_U_Float_Point *)&p2_os.k[1],
    rel_speed_of_current_os_: rel_speed_of_current_os,
    speed_plane_os_: (const IVP_U_Float_Hesse *)&geom_center_os.k[1],
    surface_os,
    p1_os: (const IVP_U_Float_Point *)v12,
    p2_os: (IVP_U_Float_Point *)&p1_os.k[1]);
}

//------------------------------------------------------------------------------
// Address: 0x100A3BE0
// Name: private: void IVP_Buoyancy_Solver::compute_values_for_one_polygon(class IVP_Real_Object __near *,class IVP_U_Float_Hesse const __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __userpurge IVP_Buoyancy_Solver::compute_values_for_one_polygon(
        IVP_Buoyancy_Solver *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        IVP_Real_Object *object,
        const IVP_U_Float_Hesse *surface_os)
{
  float v7; // xmm0_4
  void *v8; // eax
  int v9; // eax
  int memsize; // eax
  float volume_under; // xmm1_4
  float v12; // xmm0_4
  float v14[3]; // [esp-Ch] [ebp-2Ch] BYREF
  IVP_U_Float_Point s_point; // [esp+0h] [ebp-20h] BYREF
  IVP_U_BigVector<IVP_Compact_Ledge> object_ledges; // [esp+10h] [ebp-10h] BYREF
  void **retaddr; // [esp+20h] [ebp+0h]

  object_ledges.n_elems = a2;
  object_ledges.elems = retaddr;
  this->volume_under = 0.0;
  this->volume_center_under.k[2] = 0.0;
  this->volume_center_under.k[1] = 0.0;
  this->volume_center_under.k[0] = 0.0;
  LODWORD(v7) = LODWORD(surface_os->hesse_val) ^ _mask__NegFloat_;
  v14[0] = surface_os->k[0] * v7;
  v14[1] = surface_os->k[1] * v7;
  v14[2] = surface_os->k[2] * v7;
  v8 = p_malloc(size: 0x400u);
  v9 = ((int (__thiscall *)(IVP_Attacher_To_Cores_Buoyancy *, IVP_Real_Object *, int, int))this->controller_buoyancy->attacher_buoyancy->get_buoyancy_surface)(
         a1: this->controller_buoyancy->attacher_buoyancy,
         a2: object,
         a3,
         a4);
  (*(void (__thiscall **)(int, float *))(*(_DWORD *)v9 + 20))(a1: v9, a2: &s_point.k[1]);
  memsize = LODWORD(s_point.k[2]) - 1;
  object_ledges.memsize = LODWORD(s_point.k[2]) - 1;
  if ( LODWORD(s_point.k[2]) - 1 >= 0 )
  {
    while ( 1 )
    {
      IVP_Buoyancy_Solver::compute_values_for_one_ledge(
        this,
        a2: (int)&object_ledges.n_elems,
        object,
        current_ledge: *(const IVP_Compact_Ledge **)(LODWORD(s_point.hesse_val) + 4 * memsize),
        surface_os,
        s_point: (const IVP_U_Float_Point *)v14);
      if ( --object_ledges.memsize < 0 )
        break;
      memsize = object_ledges.memsize;
    }
  }
  volume_under = this->volume_under;
  if ( volume_under > this->buoyancy_eps )
  {
    this->volume_center_under.k[0] = this->volume_center_under.k[0] * (float)(0.25 / volume_under);
    v12 = (float)(0.25 / volume_under) * this->volume_center_under.k[2];
    this->volume_center_under.k[1] = this->volume_center_under.k[1] * (float)(0.25 / volume_under);
    this->volume_center_under.k[2] = v12;
  }
  if ( (IVP_U_BigVector<IVP_Compact_Ledge> *)LODWORD(s_point.hesse_val) != &object_ledges
    && LODWORD(s_point.hesse_val) != 0 )
  {
    free(data: (void *)LODWORD(s_point.hesse_val));
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A3D40
// Name: public: enum IVP_BOOL IVP_Buoyancy_Solver::compute_forces(class IVP_U_Float_Point const __near *,class IVP_U_Float_Hesse const __near *,class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall IVP_Buoyancy_Solver::compute_forces(
        IVP_Buoyancy_Solver *this,
        const IVP_U_Float_Point *rel_speed_of_current_os,
        IVP_U_Float_Hesse *surface_os,
        IVP_Real_Object *object)
{
  IVP_Cache_Object *cache_object; // ecx
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  if ( this->medium_density <= 0.0 )
    return false;
  this->object_visible_surface_content_under = 0.0;
  this->sum_impulse_x_point.k[0] = 0.0;
  this->sum_impulse_x_point.k[1] = 0.0;
  this->sum_impulse_x_point.k[2] = 0.0;
  this->sum_impulse_x_movevector.k[0] = 0.0;
  this->sum_impulse_x_movevector.k[1] = 0.0;
  this->sum_impulse_x_movevector.k[2] = 0.0;
  this->sum_impulse.k[0] = 0.0;
  this->sum_impulse.k[1] = 0.0;
  this->sum_impulse.k[2] = 0.0;
  if ( object->cache_object == nullptr )
    object->cache_object = IVP_Cache_Object_Manager::get_cache_object(
                             this: object->environment->cache_object_manager,
                             object);
  if ( *(_BYTE *)&object->flags < 8 )
  {
    cache_object = object->cache_object;
    if ( object->environment->current_time_code > cache_object->valid_until_time_code )
      IVP_Cache_Object::update_cache_object(this: cache_object);
  }
  IVP_Cache_Object::transform_vector_to_object_coords(
    this: object->cache_object,
    P_world: &this->resulting_speed_of_current_ws,
    P_object_out: &this->resulting_speed_of_current_os);
  if ( object->object_type == IVP_POLYGON )
  {
    IVP_Buoyancy_Solver::compute_values_for_one_polygon(
      this,
      a2: (int)&savedregs,
      a3: (int)object,
      a4: (int)this,
      object,
      surface_os);
  }
  else if ( object->object_type == IVP_BALL )
  {
    IVP_Buoyancy_Solver::compute_values_for_one_ball(
      this,
      a2: COERCE_FLOAT(&savedregs),
      object,
      surface_os,
      rel_speed_of_current_os);
  }
  return this->volume_under > this->buoyancy_eps
      || (float)((float)((float)(this->sum_impulse.k[1] * this->sum_impulse.k[1])
                       + (float)(this->sum_impulse.k[0] * this->sum_impulse.k[0]))
               + (float)(this->sum_impulse.k[2] * this->sum_impulse.k[2])) > this->buoyancy_eps;
}
