// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_collision/ivp_3d_solver.cxx
// Functions: 3
// ============================================================

#include "ivp\ivp_collision\ivp_3d_solver.h"

//------------------------------------------------------------------------------
// Address: 0x100A98D0
// Name: protected: class IVP_Time IVP_3D_Solver::calc_nullstelle(class IVP_Time,class IVP_Time,float,float,float,class IVP_Real_Object __near *,class IVP_Real_Object __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_Time *__userpurge IVP_3D_Solver::calc_nullstelle@<eax>(
        IVP_3D_Solver *this@<ecx>,
        int a2@<ebp>,
        IVP_Time *result,
        IVP_Time t0,
        IVP_Time t1,
        float value,
        float v0,
        float v1,
        IVP_Real_Object *solver_a,
        IVP_Real_Object *solver_b)
{
  float v10; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm4_4
  double v13; // xmm0_8
  IVP_Time v14; // rdi
  double v15; // st7
  _BYTE v17[12]; // [esp-Ch] [ebp-ACh] BYREF
  IVP_U_Matrix A; // [esp+0h] [ebp-A0h] BYREF
  IVP_3D_Solver *v19; // [esp+80h] [ebp-20h]
  IVP_Time v20; // [esp+84h] [ebp-1Ch]
  float v21; // [esp+8Ch] [ebp-14h]
  IVP_Time tt; // [esp+90h] [ebp-10h] BYREF
  float vv; // [esp+98h] [ebp-8h]
  float retaddr; // [esp+A0h] [ebp+0h]

  HIDWORD(tt.seconds) = a2;
  vv = retaddr;
  v10 = value;
  v19 = this;
  LODWORD(tt.seconds) = 0;
LABEL_2:
  v11 = v0;
  while ( 1 )
  {
    v12 = t1.seconds - t0.seconds;
    v13 = (float)((float)(v12 * (float)(v10 - v11)) / (float)(v1 - v11)) + t0.seconds;
    v20.seconds = v13;
    if ( (LOBYTE(tt.seconds) & 3) == 3 )
    {
      if ( SLODWORD(tt.seconds) > 64 )
      {
        result->seconds = t0.seconds;
        return result;
      }
      v20.seconds = (float)((float)((float)(t0.seconds - v13) + (float)(t1.seconds - v13)) * 0.375) + v13;
    }
    v14.seconds = v20.seconds;
    IVP_Real_Object::calc_at_matrix(
      this: solver_a,
      a2: (int)&tt.seconds + 4,
      current_time: v20,
      m_world_f_object_out: (IVP_U_Matrix *)v17);
    IVP_Real_Object::calc_at_matrix(
      this: solver_b,
      a2: (int)&tt.seconds + 4,
      current_time: v14,
      m_world_f_object_out: (IVP_U_Matrix *)&A.vv.k[1]);
    v15 = ((double (__thiscall *)(IVP_3D_Solver *, _BYTE *, float *))v19->get_value)(a1: v19, a2: v17, a3: &A.vv.k[1]);
    v21 = v15;
    if ( fabs(v15 - value) < 0.003 )
      break;
    ++LODWORD(tt.seconds);
    v11 = v21;
    v10 = value;
    if ( v21 < value )
    {
      v1 = v21;
      t1.seconds = v14.seconds;
      goto LABEL_2;
    }
    v0 = v21;
    t0.seconds = v14.seconds;
  }
  result->seconds = v14.seconds;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100A9A30
// Name: public: enum IVP_BOOL IVP_3D_Solver::find_first_t_for_value_max_dev(float,class IVP_Time,class IVP_Time,int,class IVP_U_Matrix_Cache __near *,class IVP_U_Matrix_Cache __near *,float __near *,class IVP_Time __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_3D_Solver::find_first_t_for_value_max_dev(
        IVP_3D_Solver *this,
        float value,
        IVP_Time t_now,
        IVP_Time t_max,
        int t_now_cache_index,
        IVP_U_Matrix_Cache *mc_A,
        IVP_U_Matrix_Cache *mc_B,
        float *opt_val_at_t_now,
        IVP_Time *t_out)
{
  float v10; // xmm0_4
  double seconds; // xmm1_8
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm4_4
  int v17; // eax
  bool v18; // zf
  int seconds_low; // edx
  unsigned int seconds_high; // edx
  double v21; // st7
  IVP_Time v22; // [esp+18h] [ebp-2Ch]
  IVP_U_Matrix *v23; // [esp+20h] [ebp-24h]
  IVP_U_Matrix *v24; // [esp+20h] [ebp-24h]
  IVP_Time t; // [esp+30h] [ebp-14h] BYREF
  IVP_Time t1; // [esp+38h] [ebp-Ch]
  IVP_3D_Solver *v27; // [esp+40h] [ebp-4h]
  int savedregs; // [esp+44h] [ebp+0h] BYREF
  IVP_U_Matrix *v1; // [esp+68h] [ebp+24h]
  float v1a; // [esp+68h] [ebp+24h]
  float v0; // [esp+6Ch] [ebp+28h]

  v27 = this;
  if ( opt_val_at_t_now != nullptr )
  {
    v10 = *opt_val_at_t_now;
    v0 = *opt_val_at_t_now;
  }
  else
  {
    v0 = this->get_value(this, a2: mc_A->m_world_f_object[0], a3: mc_B->m_world_f_object[0]);
    v10 = v0;
  }
  if ( value < v10 )
  {
    seconds = t_max.seconds;
    v14 = (float)(v10 - value) * v27->inv_max_deviation;
    t.seconds = t_now.seconds;
    if ( (float)((float)(t_now.seconds - t_max.seconds) + v14) > 0.0 )
      return 0;
    while ( 1 )
    {
      v15 = v14 * 2.0;
      v16 = t.seconds - seconds;
      if ( (float)(v16 + v15) > 0.0 )
        v15 = (float)(seconds - t.seconds) + 0.002999999992425728;
      v17 = (int)(float)(v15 * 200.0);
      if ( v17 < 1 )
        v17 = 1;
      t_now_cache_index += v17;
      v18 = mc_A->m_world_f_object[t_now_cache_index] == nullptr;
      t1.seconds = (float)((float)v17 * 0.0049999999) + t.seconds;
      if ( v18 )
      {
        seconds_low = LODWORD(t1.seconds);
        v23 = &mc_A->matrizes[t_now_cache_index];
        HIDWORD(v22.seconds) = HIDWORD(t1.seconds);
        mc_A->m_world_f_object[t_now_cache_index] = v23;
        LODWORD(v22.seconds) = seconds_low;
        IVP_Real_Object::calc_at_matrix(
          this: mc_A->object,
          a2: (int)&savedregs,
          current_time: v22,
          m_world_f_object_out: v23);
      }
      v1 = mc_A->m_world_f_object[t_now_cache_index];
      if ( mc_B->m_world_f_object[t_now_cache_index] == nullptr )
      {
        seconds_high = HIDWORD(t1.seconds);
        v24 = &mc_B->matrizes[t_now_cache_index];
        mc_B->m_world_f_object[t_now_cache_index] = v24;
        IVP_Real_Object::calc_at_matrix(
          this: mc_B->object,
          a2: (int)&savedregs,
          current_time: (IVP_Time)__PAIR64__(seconds_high, LODWORD(t1.seconds)),
          m_world_f_object_out: v24);
      }
      v21 = ((double (__thiscall *)(IVP_3D_Solver *, IVP_U_Matrix *, IVP_U_Matrix *))v27->get_value)(
              a1: v27,
              a2: v1,
              a3: mc_B->m_world_f_object[t_now_cache_index]);
      v1a = v21;
      if ( value >= v21 )
        break;
      if ( t_now_cache_index != 20 )
      {
        seconds = t_max.seconds;
        v0 = v21;
        v14 = (float)(v1a - value) * v27->inv_max_deviation;
        t.seconds = t1.seconds;
        if ( (float)((float)(t1.seconds - t_max.seconds) + v14) <= 0.0 )
          continue;
      }
      return 0;
    }
    IVP_3D_Solver::calc_nullstelle(
      this: v27,
      a2: (int)&savedregs,
      result: &t,
      t0: t,
      t1,
      value,
      v0,
      v1: v1a,
      solver_a: mc_A->object,
      solver_b: mc_B->object);
    if ( (float)(t.seconds - t_max.seconds) > 0.0 )
    {
      return 0;
    }
    else
    {
      t_out->seconds = t.seconds;
      return 1;
    }
  }
  else
  {
    t_out->seconds = t_now.seconds;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A9C80
// Name: public: enum IVP_BOOL IVP_3D_Solver::find_first_t_for_value_coll(float,float,class IVP_Time,class IVP_Time,class IVP_U_Matrix_Cache __near *,class IVP_U_Matrix_Cache __near *,float __near *,class IVP_Time __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_3D_Solver::find_first_t_for_value_coll(
        IVP_3D_Solver *this,
        float value,
        float value2,
        IVP_Time t_now,
        IVP_Time t_max,
        float mc_A,
        float mc_B,
        IVP_U_Matrix_Cache **opt_val_at_t_now,
        IVP_Time *t_out)
{
  IVP_U_Matrix_Cache *v9; // ebx
  IVP_U_Matrix_Cache *v10; // edi
  float v12; // xmm0_4
  double seconds; // xmm1_8
  float v15; // xmm3_4
  float v16; // xmm4_4
  int v17; // esi
  float v18; // xmm0_4
  float v19; // xmm4_4
  int v20; // eax
  bool v21; // zf
  double v22; // st7
  float v23; // xmm3_4
  IVP_U_Matrix *v24; // [esp+24h] [ebp-24h]
  IVP_U_Matrix *v25; // [esp+24h] [ebp-24h]
  IVP_Time t0; // [esp+34h] [ebp-14h]
  IVP_Time t1; // [esp+3Ch] [ebp-Ch]
  int savedregs; // [esp+48h] [ebp+0h] BYREF

  v9 = (IVP_U_Matrix_Cache *)LODWORD(mc_B);
  v10 = (IVP_U_Matrix_Cache *)LODWORD(mc_A);
  if ( *(float *)&opt_val_at_t_now == 0.0 )
  {
    mc_A = this->get_value(this, a2: *(IVP_U_Matrix **)(LODWORD(mc_A) + 20), a3: *(IVP_U_Matrix **)(LODWORD(mc_B) + 20));
    v12 = mc_A;
  }
  else
  {
    v12 = *(float *)opt_val_at_t_now;
    mc_A = *(float *)opt_val_at_t_now;
  }
  if ( v12 > value )
    return IVP_3D_Solver::find_first_t_for_value_max_dev(
             this,
             value,
             t_now,
             t_max,
             t_now_cache_index: 0,
             mc_A: v10,
             mc_B: v9,
             opt_val_at_t_now: &mc_A,
             t_out);
  seconds = t_max.seconds;
  v15 = 1.0 / this->max_deviation;
  v16 = t_now.seconds - t_max.seconds;
  v17 = 0;
  *(float *)&opt_val_at_t_now = v15;
  t0.seconds = t_now.seconds;
  if ( v16 >= 0.0 )
    return 0;
  while ( 1 )
  {
    v18 = (float)(v12 - value2) * v15;
    v19 = t0.seconds - seconds;
    if ( (float)(v19 + v18) <= 0.0 )
    {
      if ( v18 < 0.0 )
        v18 = 0.0;
    }
    else
    {
      v18 = (float)(seconds - t0.seconds) + 0.002999999992425728;
    }
    v20 = (int)(float)(v18 * 200.0);
    if ( v20 < 1 )
      v20 = 1;
    v17 += v20;
    t1.seconds = (float)((float)v20 * 0.0049999999) + t0.seconds;
    if ( v10->m_world_f_object[v17] == nullptr )
    {
      v24 = &v10->matrizes[v17];
      v10->m_world_f_object[v17] = v24;
      IVP_Real_Object::calc_at_matrix(
        this: v10->object,
        a2: (int)&savedregs,
        current_time: t1,
        m_world_f_object_out: v24);
    }
    v21 = v9->m_world_f_object[v17] == nullptr;
    mc_B = *(float *)&v10->m_world_f_object[v17];
    if ( v21 )
    {
      v25 = &v9->matrizes[v17];
      v9->m_world_f_object[v17] = v25;
      IVP_Real_Object::calc_at_matrix(
        this: v9->object,
        a2: (int)&savedregs,
        current_time: t1,
        m_world_f_object_out: v25);
    }
    v22 = ((double (__thiscall *)(IVP_3D_Solver *, _DWORD, IVP_U_Matrix *))this->get_value)(
            a1: this,
            a2: LODWORD(mc_B),
            a3: v9->m_world_f_object[v17]);
    mc_B = v22;
    if ( v22 > value )
      break;
    v12 = mc_B;
    if ( mc_A >= mc_B )
    {
      t_out->seconds = t0.seconds;
      return 1;
    }
    seconds = t_max.seconds;
    v23 = t1.seconds - t_max.seconds;
    t0.seconds = t1.seconds;
    if ( v23 >= 0.0 )
      return 0;
    v15 = *(float *)&opt_val_at_t_now;
  }
  if ( (float)(t1.seconds - t_max.seconds) > 0.0 )
    return 0;
  mc_A = mc_B;
  return IVP_3D_Solver::find_first_t_for_value_max_dev(
           this,
           value,
           t_now: t1,
           t_max,
           t_now_cache_index: v17,
           mc_A: v10,
           mc_B: v9,
           opt_val_at_t_now: &mc_A,
           t_out);
}
