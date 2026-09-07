// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_physics/ivp_cache_object.cxx
// Functions: 9
// ============================================================

#include "ivp\ivp_physics\ivp_cache_object.h"

//------------------------------------------------------------------------------
// Address: 0x1006D0A0
// Name: public: static void IVP_Cache_Object_Manager::invalid_cache_object(class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl IVP_Cache_Object_Manager::invalid_cache_object(IVP_Real_Object *object)
{
  IVP_Cache_Object *cache_object; // eax

  cache_object = object->cache_object;
  if ( cache_object != nullptr )
  {
    cache_object->object = nullptr;
    object->cache_object = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006D0C0
// Name: public: IVP_Cache_Object_Manager::IVP_Cache_Object_Manager(int)
// Source: json
//------------------------------------------------------------------------------
IVP_Cache_Object_Manager *__thiscall IVP_Cache_Object_Manager::IVP_Cache_Object_Manager(
        IVP_Cache_Object_Manager *this,
        int number_of_cache_elements)
{
  this->n_cache_objects = number_of_cache_elements;
  this->cache_objects_buffer = _calloc_crt(nelem: 112, size: number_of_cache_elements);
  this->reuse_loop_index = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006D0F0
// Name: public: IVP_Cache_Object_Manager::~IVP_Cache_Object_Manager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Cache_Object_Manager::~IVP_Cache_Object_Manager(IVP_Cache_Object_Manager *this)
{
  int v2; // edi
  int v3; // edx
  int v4; // eax
  int v5; // ecx

  v2 = 0;
  if ( this->n_cache_objects > 0 )
  {
    v3 = 0;
    do
    {
      v4 = *(_DWORD *)&this->cache_objects_buffer[v3 + 104];
      if ( v4 != 0 )
      {
        v5 = *(_DWORD *)(v4 + 64);
        if ( v5 != 0 )
        {
          *(_DWORD *)(v5 + 104) = 0;
          *(_DWORD *)(v4 + 64) = 0;
        }
      }
      ++v2;
      v3 += 112;
    }
    while ( v2 < this->n_cache_objects );
  }
  if ( this->cache_objects_buffer != nullptr )
  {
    free(data: this->cache_objects_buffer);
    this->cache_objects_buffer = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006D140
// Name: public: void IVP_Cache_Object::update_cache_object(void)restrict
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Cache_Object::update_cache_object(IVP_Cache_Object *this)
{
  IVP_Real_Object *object; // eax
  IVP_Environment *environment; // edx
  IVP_Core *physical_core; // ecx
  float v5; // xmm0_4
  IVP_U_Quat *p_q_world_f_object; // edi
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  IVP_Core *v10; // eax
  float v11; // xmm3_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  IVP_Real_Object *v15; // eax
  IVP_U_Quat *q_core_f_object; // eax
  float y; // xmm1_4
  float z; // xmm2_4
  float w; // xmm6_4
  float v20; // xmm4_4
  float v21; // xmm5_4
  float v22; // xmm7_4
  float v23; // xmm0_4
  float v24; // xmm6_4
  float v25; // xmm7_4
  IVP_Time current_time; // [esp+Ch] [ebp-10h]
  IVP_U_Matrix *current_time_4; // [esp+10h] [ebp-Ch]

  object = this->object;
  environment = object->environment;
  *(IVP_Time *)&current_time.seconds = environment->current_time;
  this->valid_until_time_code = environment->current_time_code;
  physical_core = object->physical_core;
  v5 = current_time.seconds - physical_core->time_of_last_psi.seconds;
  p_q_world_f_object = &this->q_world_f_object;
  if ( v5 == 0.0 )
  {
    v7 = physical_core->pos_world_f_core_last_psi.k[1];
    v8 = physical_core->pos_world_f_core_last_psi.k[2];
    *(_QWORD *)&p_q_world_f_object->x = *(_QWORD *)&physical_core->q_world_f_core_last_psi.x;
    *(_QWORD *)&this->q_world_f_object.z = *(_QWORD *)&physical_core->q_world_f_core_last_psi.z;
    v9 = physical_core->pos_world_f_core_last_psi.k[0];
    this->m_world_f_object.vv.k[0] = v9;
    this->m_world_f_object.vv.k[1] = v7;
    this->m_world_f_object.vv.k[2] = v8;
    this->core_pos.k[0] = v9;
    this->core_pos.k[1] = v7;
    this->core_pos.k[2] = v8;
  }
  else
  {
    IVP_U_Quat::set_interpolate_smoothly(
      this: &this->q_world_f_object,
      from: &physical_core->q_world_f_core_last_psi,
      to: &physical_core->q_world_f_core_next_psi,
      t: (float)(environment->current_time.seconds - physical_core->time_of_last_psi.seconds) * physical_core->i_delta_time);
    v10 = this->object->physical_core;
    v11 = current_time.seconds - v10->time_of_last_psi.seconds;
    v12 = (float)(v10->delta_world_f_core_psis.k[0] * v11) + v10->pos_world_f_core_last_psi.k[0];
    v13 = (float)(v10->delta_world_f_core_psis.k[1] * v11) + v10->pos_world_f_core_last_psi.k[1];
    v14 = (float)(v10->delta_world_f_core_psis.k[2] * v11) + v10->pos_world_f_core_last_psi.k[2];
    this->core_pos.k[0] = v12;
    this->core_pos.k[1] = v13;
    this->core_pos.k[2] = v14;
    this->m_world_f_object.vv.k[0] = v12;
    this->m_world_f_object.vv.k[1] = v13;
    this->m_world_f_object.vv.k[2] = v14;
  }
  current_time_4 = &this->m_world_f_object;
  IVP_U_Quat::set_matrix(this: &this->q_world_f_object, mat: &this->m_world_f_object);
  v15 = this->object;
  if ( (*(_DWORD *)&v15->flags & 0x800) == 0 )
    IVP_U_Matrix::vmult4(this: current_time_4, p_in: &v15->shift_core_f_object, p_out: &this->m_world_f_object.vv);
  q_core_f_object = this->object->q_core_f_object;
  if ( q_core_f_object != nullptr )
  {
    y = this->q_world_f_object.y;
    z = this->q_world_f_object.z;
    w = q_core_f_object->w;
    v20 = (float)((float)((float)(this->q_world_f_object.w * q_core_f_object->y) + (float)(y * w))
                + (float)(z * q_core_f_object->x))
        - (float)(this->q_world_f_object.x * q_core_f_object->z);
    v21 = (float)((float)((float)(this->q_world_f_object.w * q_core_f_object->z) + (float)(z * w))
                + (float)(this->q_world_f_object.x * q_core_f_object->y))
        - (float)(y * q_core_f_object->x);
    v22 = this->q_world_f_object.w;
    v23 = v22 * q_core_f_object->x;
    v24 = (float)((float)(v22 * w) - (float)(p_q_world_f_object->x * q_core_f_object->x))
        - (float)(y * q_core_f_object->y);
    v25 = z * q_core_f_object->z;
    p_q_world_f_object->x = (float)((float)(v23 + (float)(p_q_world_f_object->x * q_core_f_object->w))
                                  + (float)(y * q_core_f_object->z))
                          - (float)(z * q_core_f_object->y);
    this->q_world_f_object.y = v20;
    this->q_world_f_object.z = v21;
    this->q_world_f_object.w = v24 - v25;
    IVP_U_Quat::set_matrix(this: &this->q_world_f_object, mat: current_time_4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006D3D0
// Name: public: void IVP_Cache_Object::transform_position_to_object_coords(class IVP_U_Point const __near *,class IVP_U_Point __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Cache_Object::transform_position_to_object_coords(
        IVP_Cache_Object *this,
        const IVP_U_Point *P_world,
        IVP_U_Point *P_object_out)
{
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm2_4

  v3 = P_world->k[0] - this->m_world_f_object.vv.k[0];
  v4 = P_world->k[1] - this->m_world_f_object.vv.k[1];
  v5 = P_world->k[2] - this->m_world_f_object.vv.k[2];
  P_object_out->k[0] = (float)((float)(this->m_world_f_object.rows[1].k[0] * v4)
                             + (float)(this->m_world_f_object.rows[0].k[0] * v3))
                     + (float)(this->m_world_f_object.rows[2].k[0] * v5);
  P_object_out->k[1] = (float)((float)(this->m_world_f_object.rows[1].k[1] * v4)
                             + (float)(this->m_world_f_object.rows[0].k[1] * v3))
                     + (float)(this->m_world_f_object.rows[2].k[1] * v5);
  P_object_out->k[2] = (float)((float)(this->m_world_f_object.rows[1].k[2] * v4)
                             + (float)(this->m_world_f_object.rows[0].k[2] * v3))
                     + (float)(this->m_world_f_object.rows[2].k[2] * v5);
}

//------------------------------------------------------------------------------
// Address: 0x1006D480
// Name: public: void IVP_Cache_Object::transform_position_to_world_coords(class IVP_U_Float_Point const __near *,class IVP_U_Point __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Cache_Object::transform_position_to_world_coords(
        IVP_Cache_Object *this,
        const IVP_U_Float_Point *P_object,
        IVP_U_Point *P_world_out)
{
  float v3; // xmm4_4
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm4_4
  float v8; // xmm3_4
  float v9; // xmm0_4
  float v10; // xmm1_4

  v3 = P_object->k[1];
  v4 = (float)(this->m_world_f_object.rows[0].k[1] * v3) + (float)(this->m_world_f_object.rows[0].k[0] * P_object->k[0]);
  v5 = (float)(this->m_world_f_object.rows[1].k[1] * v3) + (float)(this->m_world_f_object.rows[1].k[0] * P_object->k[0]);
  v6 = this->m_world_f_object.rows[2].k[1] * v3;
  v7 = P_object->k[2];
  v8 = (float)(this->m_world_f_object.rows[0].k[2] * v7) + v4;
  v9 = (float)((float)(this->m_world_f_object.rows[1].k[2] * v7) + v5) + this->m_world_f_object.vv.k[1];
  v10 = (float)((float)(this->m_world_f_object.rows[2].k[2] * v7)
              + (float)(v6 + (float)(this->m_world_f_object.rows[2].k[0] * P_object->k[0])))
      + this->m_world_f_object.vv.k[2];
  P_world_out->k[0] = this->m_world_f_object.vv.k[0] + v8;
  P_world_out->k[1] = v9;
  P_world_out->k[2] = v10;
}

//------------------------------------------------------------------------------
// Address: 0x1006D530
// Name: public: void IVP_Cache_Object::transform_vector_to_object_coords(class IVP_U_Point const __near *,class IVP_U_Point __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Cache_Object::transform_vector_to_object_coords(
        IVP_Cache_Object *this,
        const IVP_U_Float_Point *P_world,
        IVP_U_Float_Point *P_object_out)
{
  float v3; // xmm2_4
  float v4; // xmm4_4
  float v5; // xmm0_4
  float v6; // xmm1_4

  v3 = P_world->k[1];
  v4 = P_world->k[2];
  v5 = (float)((float)(this->m_world_f_object.rows[0].k[1] * P_world->k[0])
             + (float)(this->m_world_f_object.rows[1].k[1] * v3))
     + (float)(this->m_world_f_object.rows[2].k[1] * v4);
  v6 = (float)((float)(this->m_world_f_object.rows[0].k[2] * P_world->k[0])
             + (float)(this->m_world_f_object.rows[1].k[2] * v3))
     + (float)(this->m_world_f_object.rows[2].k[2] * v4);
  P_object_out->k[0] = (float)((float)(this->m_world_f_object.rows[1].k[0] * v3)
                             + (float)(this->m_world_f_object.rows[0].k[0] * P_world->k[0]))
                     + (float)(this->m_world_f_object.rows[2].k[0] * v4);
  P_object_out->k[1] = v5;
  P_object_out->k[2] = v6;
}

//------------------------------------------------------------------------------
// Address: 0x1006D5D0
// Name: public: void IVP_Cache_Object::transform_vector_to_world_coords(class IVP_U_Point const __near *,class IVP_U_Point __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Cache_Object::transform_vector_to_world_coords(
        IVP_Cache_Object *this,
        const IVP_U_Float_Point *P_object,
        IVP_U_Float_Point *P_world_out)
{
  float v3; // xmm2_4
  float v4; // xmm4_4
  float v5; // xmm0_4
  float v6; // xmm1_4

  v3 = P_object->k[1];
  v4 = P_object->k[2];
  v5 = (float)((float)(this->m_world_f_object.rows[1].k[0] * P_object->k[0])
             + (float)(this->m_world_f_object.rows[1].k[1] * v3))
     + (float)(this->m_world_f_object.rows[1].k[2] * v4);
  v6 = (float)((float)(this->m_world_f_object.rows[2].k[0] * P_object->k[0])
             + (float)(this->m_world_f_object.rows[2].k[1] * v3))
     + (float)(this->m_world_f_object.rows[2].k[2] * v4);
  P_world_out->k[0] = (float)((float)(this->m_world_f_object.rows[0].k[1] * v3)
                            + (float)(this->m_world_f_object.rows[0].k[0] * P_object->k[0]))
                    + (float)(this->m_world_f_object.rows[0].k[2] * v4);
  P_world_out->k[1] = v5;
  P_world_out->k[2] = v6;
}

//------------------------------------------------------------------------------
// Address: 0x1006D670
// Name: public: class IVP_Cache_Object __near * IVP_Cache_Object_Manager::get_cache_object(class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Cache_Object *__thiscall IVP_Cache_Object_Manager::get_cache_object(
        IVP_Cache_Object_Manager *this,
        IVP_Real_Object *object)
{
  int reuse_loop_index; // eax
  IVP_Cache_Object *v3; // esi
  int v4; // edx
  IVP_Real_Object *v5; // eax
  IVP_Cache_Object *cache_object; // ecx

  reuse_loop_index = this->reuse_loop_index;
  v3 = (IVP_Cache_Object *)&this->cache_objects_buffer[112 * reuse_loop_index];
  if ( v3->reference_count != 0 )
  {
    v4 = this->n_cache_objects - 1;
    do
    {
      reuse_loop_index = v4 & (reuse_loop_index + 1);
      this->reuse_loop_index = reuse_loop_index;
      v3 = (IVP_Cache_Object *)&this->cache_objects_buffer[112 * reuse_loop_index];
    }
    while ( v3->reference_count != 0 );
  }
  this->reuse_loop_index = (this->reuse_loop_index + 1) & (this->n_cache_objects - 1);
  v5 = v3->object;
  if ( v5 != nullptr )
  {
    cache_object = v5->cache_object;
    if ( cache_object != nullptr )
    {
      cache_object->object = nullptr;
      v5->cache_object = nullptr;
    }
  }
  v3->object = object;
  object->cache_object = v3;
  v3->valid_until_time_code = 0;
  if ( *(_BYTE *)&object->flags >= 8 )
    IVP_Cache_Object::update_cache_object(this: v3);
  return v3;
}
