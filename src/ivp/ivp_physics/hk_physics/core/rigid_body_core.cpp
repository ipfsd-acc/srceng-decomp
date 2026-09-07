// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_physics/hk_physics/core/rigid_body_core.cpp
// Functions: 2
// ============================================================

#include "ivp\ivp_physics\hk_physics\core\rigid_body_core.h"

//------------------------------------------------------------------------------
// Address: 0x100438C0
// Name: public: void hk_Rigid_Body_Core::add_to_mass_matrix_inv(struct hk_Core_VMQ_Input __near &,class hk_Dense_Matrix __near &,float __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Rigid_Body_Core::add_to_mass_matrix_inv(
        hk_Rigid_Body_Core *this,
        hk_Core_VMQ_Input *input,
        int matrix_out,
        float *velocities_out)
{
  hk_Virtual_Mass_Query *m_vmq; // eax
  float *p_z; // edi
  float *v7; // esi
  float v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm0_4
  float v11; // xmm2_4
  float v12; // xmm4_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm5_4
  int v16; // eax
  hk_Virtual_Mass_Query *v17; // ebx
  float *v18; // eax
  float v19; // xmm2_4
  int v20; // ebx
  float v21; // xmm0_4
  int v22; // ebx
  float v23; // xmm0_4
  int v24; // ebx
  float v25; // xmm0_4
  float *v26; // ecx
  float v27; // xmm0_4
  bool v28; // zf
  float *v29; // eax
  float v30; // xmm0_4
  float *v31; // ecx
  float v32; // xmm0_4
  bool v33; // sf
  float *v34; // eax
  float x; // xmm1_4
  unsigned int v36; // [esp+0h] [ebp-20h]
  hk_Virtual_Mass_Query *mq_b; // [esp+4h] [ebp-1Ch]
  int j; // [esp+8h] [ebp-18h]
  int v39; // [esp+Ch] [ebp-14h]
  hk_Rigid_Body_Core *v40; // [esp+10h] [ebp-10h]
  hk_Cached_Force_Axis_Description *ds_a; // [esp+14h] [ebp-Ch]
  hk_Virtual_Mass_Query *mq_a; // [esp+18h] [ebp-8h]
  int j_dest_index; // [esp+1Ch] [ebp-4h]
  int j_dest_indexa; // [esp+1Ch] [ebp-4h]
  int j_dest_indexb; // [esp+1Ch] [ebp-4h]
  int j_dest_indexc; // [esp+1Ch] [ebp-4h]
  int j_dest_indexd; // [esp+1Ch] [ebp-4h]
  int i_dest_index; // [esp+2Ch] [ebp+Ch]

  v40 = this;
  if ( (((unsigned __int8)*(_WORD *)&this->IVP_Core_Fast_Static
       | ((unsigned __int8)*(_WORD *)&this->IVP_Core_Fast_Static >> 3))
      & 2) == 0 )
  {
    m_vmq = input->m_vmq;
    ds_a = input->m_buffer;
    mq_a = m_vmq;
    p_z = &ds_a->dummy.z;
    v39 = -1;
    v7 = &m_vmq->m_angular.z;
    while ( 1 )
    {
      v8 = *(v7 - 1);
      v9 = *(v7 - 2);
      v10 = this->rot_speed.k[1] * v8;
      v11 = v8 * this->inv_rot_inertia.k[1];
      v12 = *v7 * this->inv_rot_inertia.k[2];
      v13 = (float)((float)(this->rot_speed.k[0] * v9) + v10) + (float)(this->rot_speed.k[2] * *v7);
      v14 = (float)(*(v7 - 5) * this->speed.k[1]) + (float)(m_vmq->m_linear.x * this->speed.k[0]);
      v15 = this->speed.k[2] * *(v7 - 4);
      ds_a->dummy.x = v9 * this->inv_rot_inertia.k[0];
      *(p_z - 1) = v11;
      *p_z = v12;
      v16 = *((_DWORD *)v7 + 2);
      velocities_out[v16] = (float)((float)(v14 + v15) + v13) + velocities_out[v16];
      i_dest_index = v16;
      v17 = input->m_vmq;
      mq_b = v17;
      j = v39;
      if ( v39 >= 0 )
      {
        if ( v39 + 1 >= 4 )
        {
          v36 = (unsigned int)(v39 + 1) >> 2;
          v18 = &v17->m_angular.z;
          v17 = input->m_vmq;
          j = v39 - 4 * v36;
          do
          {
            v19 = mq_a->m_linear.x * v17->m_linear.x;
            v20 = i_dest_index + *((_DWORD *)v18 + 2) * *(_DWORD *)(matrix_out + 12);
            v21 = (float)((float)((float)((float)(*(v18 - 5) * *(v7 - 5)) + v19) + (float)(*(v18 - 4) * *(v7 - 4)))
                        * v40->inv_rot_inertia.hesse_val)
                + (float)((float)((float)(*(v18 - 2) * ds_a->dummy.x) + (float)(*(v18 - 1) * *(p_z - 1)))
                        + (float)(*p_z * *v18));
            j_dest_index = *((_DWORD *)v18 + 2);
            *(float *)(*(_DWORD *)matrix_out + 4 * v20) = v21 + *(float *)(*(_DWORD *)matrix_out + 4 * v20);
            *(float *)(*(_DWORD *)matrix_out + 4 * (j_dest_index + i_dest_index * *(_DWORD *)(matrix_out + 12))) = v21 + *(float *)(*(_DWORD *)matrix_out + 4 * (j_dest_index + i_dest_index * *(_DWORD *)(matrix_out + 12)));
            v22 = i_dest_index + *((_DWORD *)v18 + 14) * *(_DWORD *)(matrix_out + 12);
            j_dest_indexa = *((_DWORD *)v18 + 14);
            v23 = (float)((float)((float)((float)(v18[6] * mq_a->m_linear.x) + (float)(v18[7] * *(v7 - 5)))
                                + (float)(v18[8] * *(v7 - 4)))
                        * v40->inv_rot_inertia.hesse_val)
                + (float)((float)((float)(v18[10] * ds_a->dummy.x) + (float)(v18[11] * *(p_z - 1)))
                        + (float)(v18[12] * *p_z));
            *(float *)(*(_DWORD *)matrix_out + 4 * v22) = v23 + *(float *)(*(_DWORD *)matrix_out + 4 * v22);
            *(float *)(*(_DWORD *)matrix_out + 4 * (j_dest_indexa + i_dest_index * *(_DWORD *)(matrix_out + 12))) = v23 + *(float *)(*(_DWORD *)matrix_out + 4 * (j_dest_indexa + i_dest_index * *(_DWORD *)(matrix_out + 12)));
            v24 = i_dest_index + *((_DWORD *)v18 + 26) * *(_DWORD *)(matrix_out + 12);
            j_dest_indexb = *((_DWORD *)v18 + 26);
            v25 = (float)((float)((float)((float)(v18[18] * mq_a->m_linear.x) + (float)(v18[19] * *(v7 - 5)))
                                + (float)(v18[20] * *(v7 - 4)))
                        * v40->inv_rot_inertia.hesse_val)
                + (float)((float)((float)(v18[22] * ds_a->dummy.x) + (float)(v18[23] * *(p_z - 1)))
                        + (float)(v18[24] * *p_z));
            *(float *)(*(_DWORD *)matrix_out + 4 * v24) = v25 + *(float *)(*(_DWORD *)matrix_out + 4 * v24);
            *(float *)(*(_DWORD *)matrix_out + 4 * (j_dest_indexb + i_dest_index * *(_DWORD *)(matrix_out + 12))) = v25 + *(float *)(*(_DWORD *)matrix_out + 4 * (j_dest_indexb + i_dest_index * *(_DWORD *)(matrix_out + 12)));
            j_dest_indexc = *((_DWORD *)v18 + 38);
            v26 = (float *)(*(_DWORD *)matrix_out + 4 * (i_dest_index + j_dest_indexc * *(_DWORD *)(matrix_out + 12)));
            v27 = (float)((float)((float)((float)(v18[30] * mq_a->m_linear.x) + (float)(v18[31] * *(v7 - 5)))
                                + (float)(v18[32] * *(v7 - 4)))
                        * v40->inv_rot_inertia.hesse_val)
                + (float)((float)((float)(v18[34] * ds_a->dummy.x) + (float)(v18[35] * *(p_z - 1)))
                        + (float)(v18[36] * *p_z));
            *v26 = v27 + *v26;
            v17 = mq_b + 4;
            v18 += 48;
            v28 = v36-- == 1;
            *(float *)(*(_DWORD *)matrix_out + 4 * (j_dest_indexc + i_dest_index * *(_DWORD *)(matrix_out + 12))) = v27 + *(float *)(*(_DWORD *)matrix_out + 4 * (j_dest_indexc + i_dest_index * *(_DWORD *)(matrix_out + 12)));
            mq_b += 4;
          }
          while ( !v28 );
          this = v40;
        }
        if ( j >= 0 )
        {
          v29 = &v17->m_angular.z;
          do
          {
            v30 = (float)((float)((float)(*(v29 - 6) * mq_a->m_linear.x) + (float)(*(v29 - 5) * *(v7 - 5)))
                        + (float)(*(v29 - 4) * *(v7 - 4)))
                * this->inv_rot_inertia.hesse_val;
            j_dest_indexd = *((_DWORD *)v29 + 2);
            v31 = (float *)(*(_DWORD *)matrix_out + 4 * (i_dest_index + j_dest_indexd * *(_DWORD *)(matrix_out + 12)));
            v32 = v30
                + (float)((float)((float)(*(v29 - 1) * *(p_z - 1)) + (float)(*(v29 - 2) * ds_a->dummy.x))
                        + (float)(*v29 * *p_z));
            *v31 = v32 + *v31;
            v29 += 12;
            v33 = --j < 0;
            *(float *)(*(_DWORD *)matrix_out + 4 * (j_dest_indexd + i_dest_index * *(_DWORD *)(matrix_out + 12))) = v32 + *(float *)(*(_DWORD *)matrix_out + 4 * (j_dest_indexd + i_dest_index * *(_DWORD *)(matrix_out + 12)));
            this = v40;
          }
          while ( !v33 );
        }
      }
      v34 = (float *)(*(_DWORD *)matrix_out + 4 * i_dest_index * (*(_DWORD *)(matrix_out + 12) + 1));
      x = mq_a->m_linear.x;
      ++mq_a;
      *v34 = (float)((float)((float)((float)((float)(*(v7 - 5) * *(v7 - 5)) + (float)(x * x))
                                   + (float)(*(v7 - 4) * *(v7 - 4)))
                           * this->inv_rot_inertia.hesse_val)
                   + (float)((float)((float)(*(v7 - 1) * *(p_z - 1)) + (float)(*(v7 - 2) * ds_a->dummy.x))
                           + (float)(*p_z * *v7)))
           + *v34;
      ++ds_a;
      ++v39;
      v7 += 12;
      p_z += 4;
      if ( v39 + 1 >= input->m_n_queries )
        break;
      m_vmq = mq_a;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10043DB0
// Name: public: void hk_Rigid_Body_Core::apply_impulses(struct hk_Core_VMQ_Input __near &,float const __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall hk_Rigid_Body_Core::apply_impulses(
        hk_Rigid_Body_Core *this,
        hk_Core_VMQ_Input *input,
        const float *impulse_strength)
{
  hk_Virtual_Mass_Query *m_vmq; // eax
  float hesse_val; // xmm1_4
  hk_Cached_Force_Axis_Description *m_buffer; // edx
  int v6; // esi
  float v7; // xmm0_4
  float v8; // xmm0_4
  float v9; // xmm2_4

  if ( (*(_WORD *)&this->IVP_Core_Fast_Static & 0x12) == 0 )
  {
    m_vmq = input->m_vmq;
    hesse_val = this->inv_rot_inertia.hesse_val;
    m_buffer = input->m_buffer;
    v6 = input->m_n_queries - 1;
    do
    {
      v7 = impulse_strength[m_vmq->m_matrix_index];
      this->rot_speed.k[0] = (float)(m_buffer->dummy.x * v7) + this->rot_speed.k[0];
      this->rot_speed.k[1] = (float)(m_buffer->dummy.y * v7) + this->rot_speed.k[1];
      this->rot_speed.k[2] = (float)(m_buffer->dummy.z * v7) + this->rot_speed.k[2];
      v8 = v7 * hesse_val;
      this->speed.k[0] = (float)(m_vmq->m_linear.x * v8) + this->speed.k[0];
      this->speed.k[1] = (float)(m_vmq->m_linear.y * v8) + this->speed.k[1];
      v9 = (float)(m_vmq->m_linear.z * v8) + this->speed.k[2];
      ++m_vmq;
      ++m_buffer;
      --v6;
      this->speed.k[2] = v9;
    }
    while ( v6 >= 0 );
  }
}
