// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_intern/ivp_great_matrix.cxx
// Functions: 42
// ============================================================

#include "ivp\ivp_intern\ivp_great_matrix.h"

//------------------------------------------------------------------------------
// Address: 0x1009B410
// Name: public: enum IVP_RETURN_TYPE IVP_Great_Matrix_Many_Zero::matrix_check_unequation_line(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall IVP_Great_Matrix_Many_Zero::matrix_check_unequation_line(IVP_Great_Matrix_Many_Zero *this, int linenum)
{
  float v2; // xmm0_4
  int columns; // edi
  int v4; // ebx
  float *v5; // eax
  float *v6; // edx
  unsigned int v7; // esi
  float v8; // xmm1_4
  float v9; // xmm0_4
  float *v10; // edx
  int v11; // edi
  float v12; // xmm1_4

  v2 = 0.0;
  columns = this->columns;
  v4 = 0;
  v5 = &this->matrix_values[linenum * this->aligned_row_len];
  if ( columns >= 4 )
  {
    v6 = this->result_vector + 2;
    v7 = ((unsigned int)(columns - 4) >> 2) + 1;
    v4 = 4 * v7;
    do
    {
      v8 = (float)((float)(*(v6 - 1) * v5[1]) + (float)((float)(*(v6 - 2) * *v5) + v2)) + (float)(v5[2] * *v6);
      v9 = v6[1] * v5[3];
      v5 += 4;
      v6 += 4;
      --v7;
      v2 = v9 + v8;
    }
    while ( v7 != 0 );
  }
  if ( v4 < columns )
  {
    v10 = &this->result_vector[v4];
    v11 = columns - v4;
    do
    {
      v12 = *v5++ * *v10++;
      --v11;
      v2 = v2 + v12;
    }
    while ( v11 != 0 );
  }
  return (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(this->desired_vector[linenum] * 0.0000099999997) & _mask__AbsFloat_)
               + v2) >= this->desired_vector[linenum];
}

//------------------------------------------------------------------------------
// Address: 0x1009B4F0
// Name: public: void IVP_Great_Matrix_Many_Zero::align_matrix_values(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Great_Matrix_Many_Zero::align_matrix_values(IVP_Great_Matrix_Many_Zero *this)
{
  this->matrix_values = (float *)((int)(this->matrix_values + 3) & 0xFFFFFFF0);
}

//------------------------------------------------------------------------------
// Address: 0x1009B500
// Name: public: void IVP_Great_Matrix_Many_Zero::exchange_rows(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Great_Matrix_Many_Zero::exchange_rows(IVP_Great_Matrix_Many_Zero *this, int a, int b)
{
  float *matrix_values; // esi
  int aligned_row_len; // edx
  int v5; // eax
  float *v6; // edx
  float *v7; // eax
  int columns; // esi
  unsigned int v9; // esi
  float v10; // xmm0_4
  int v11; // xmm0_4
  int v12; // xmm0_4
  int v13; // xmm0_4
  float *desired_vector; // eax
  float v15; // xmm0_4

  matrix_values = this->matrix_values;
  aligned_row_len = this->aligned_row_len;
  v5 = b * aligned_row_len;
  v6 = &matrix_values[a * aligned_row_len];
  v7 = &matrix_values[v5];
  columns = this->columns;
  if ( columns > 0 )
  {
    v9 = ((unsigned int)(columns - 1) >> 2) + 1;
    do
    {
      v10 = *v7;
      *v7 = *v6;
      *v6 = v10;
      v11 = *((_DWORD *)v7 + 1);
      v7[1] = v6[1];
      *((_DWORD *)v6 + 1) = v11;
      v12 = *((_DWORD *)v7 + 2);
      v7[2] = v6[2];
      *((_DWORD *)v6 + 2) = v12;
      v13 = *((_DWORD *)v7 + 3);
      v7[3] = v6[3];
      *((_DWORD *)v6 + 3) = v13;
      v7 += 4;
      v6 += 4;
      --v9;
    }
    while ( v9 != 0 );
  }
  desired_vector = this->desired_vector;
  v15 = desired_vector[a];
  desired_vector[a] = desired_vector[b];
  this->desired_vector[b] = v15;
}

//------------------------------------------------------------------------------
// Address: 0x1009B5A0
// Name: public: enum IVP_RETURN_TYPE IVP_Great_Matrix_Many_Zero::solve_lower_null_matrix(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_Great_Matrix_Many_Zero::solve_lower_null_matrix(IVP_Great_Matrix_Many_Zero *this)
{
  int v1; // edi
  int columns; // esi
  float *v3; // eax
  float *desired_vector; // edx
  float v5; // xmm0_4
  int v6; // esi
  float *v7; // edx
  unsigned int v8; // edi
  float v9; // xmm0_4
  float v10; // xmm1_4
  float *v11; // edx
  int v12; // esi
  float v13; // xmm1_4
  int j; // eax
  int v16; // eax
  int i; // [esp+Ch] [ebp-8h]
  int v18; // [esp+10h] [ebp-4h]

  v1 = this->columns - 1;
  i = v1;
  if ( v1 < 0 )
  {
LABEL_16:
    for ( j = 0; j < this->columns; ++j )
      this->result_vector[j] = this->desired_vector[j];
    return 1;
  }
  v18 = v1 + 3;
  while ( 1 )
  {
    columns = this->columns;
    v3 = &this->matrix_values[columns - 1 + v1 * this->aligned_row_len];
    desired_vector = this->desired_vector;
    v5 = desired_vector[v1];
    v6 = columns - 1;
    if ( v6 > v1 )
    {
      if ( v6 - v1 >= 4 )
      {
        v7 = &desired_vector[v6 - 2];
        v8 = ((unsigned int)(v6 - v18 - 1) >> 2) + 1;
        v6 -= 4 * v8;
        do
        {
          v9 = (float)((float)(v5 - (float)(v7[2] * *v3)) - (float)(v7[1] * *(v3 - 1))) - (float)(*(v3 - 2) * *v7);
          v10 = *(v7 - 1) * *(v3 - 3);
          v3 -= 4;
          v7 -= 4;
          --v8;
          v5 = v9 - v10;
        }
        while ( v8 != 0 );
        v1 = i;
      }
      if ( v6 > v1 )
      {
        v11 = &this->desired_vector[v6];
        v12 = v6 - v1;
        do
        {
          v13 = *v11-- * *v3--;
          --v12;
          v5 = v5 - v13;
        }
        while ( v12 != 0 );
      }
    }
    if ( this->MATRIX_EPS <= fabs(*v3) )
    {
      this->desired_vector[v1] = v5 / *v3;
      goto LABEL_15;
    }
    if ( (float)(this->MATRIX_EPS * 1000.0) <= fabs(v5) )
      break;
    this->desired_vector[v1] = 0.0;
LABEL_15:
    --v18;
    i = --v1;
    if ( v1 < 0 )
      goto LABEL_16;
  }
  v16 = this->columns - 1;
  if ( v16 >= 0 )
  {
    if ( this->columns >= 4 )
    {
      do
      {
        this->result_vector[v16] = 0.0;
        this->result_vector[v16 - 1] = 0.0;
        this->result_vector[v16 - 2] = 0.0;
        this->result_vector[v16 - 3] = 0.0;
        v16 -= 4;
      }
      while ( v16 >= 3 );
    }
    for ( ; v16 >= 0; this->result_vector[v16 + 1] = 0.0 )
      --v16;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1009B740
// Name: public: IVP_Great_Matrix_Many_Zero::IVP_Great_Matrix_Many_Zero(void)
// Source: json
//------------------------------------------------------------------------------
IVP_Great_Matrix_Many_Zero *__thiscall IVP_Great_Matrix_Many_Zero::IVP_Great_Matrix_Many_Zero(
        IVP_Great_Matrix_Many_Zero *this)
{
  this->MATRIX_EPS = 9.9999997e-10;
  this->matrix_values = nullptr;
  this->desired_vector = nullptr;
  this->result_vector = nullptr;
  this->columns = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1009B760
// Name: public: void IVP_Great_Matrix_Many_Zero::fill_from_bigger_matrix(class IVP_Great_Matrix_Many_Zero __near *,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Great_Matrix_Many_Zero::fill_from_bigger_matrix(
        IVP_Great_Matrix_Many_Zero *this,
        IVP_Great_Matrix_Many_Zero *big_matrix,
        int *original_pos,
        int n_column)
{
  int v4; // edi
  IVP_Great_Matrix_Many_Zero *v5; // ebx
  int *v6; // ecx
  int v7; // esi
  float *v8; // edx
  int v9; // eax
  int v10; // edi
  unsigned int v11; // edi
  int v12; // ebx
  float *v13; // edx
  int v14; // eax
  int *v15; // esi
  unsigned int v16; // edi
  int v17; // eax
  double v18; // st7
  double v19; // st7
  int v20; // edi
  int v21; // eax
  int v22; // ebx
  int i; // [esp+Ch] [ebp-Ch]
  char *v25; // [esp+10h] [ebp-8h]
  int j; // [esp+14h] [ebp-4h]

  v4 = n_column;
  v5 = this;
  if ( n_column != 0 )
  {
    v6 = original_pos;
    v7 = 0;
    if ( original_pos[n_column - 1] == n_column - 1 )
    {
      if ( n_column > 0 )
      {
        do
        {
          v8 = &big_matrix->matrix_values[big_matrix->aligned_row_len * original_pos[v7]];
          v9 = (int)&v5->matrix_values[v7 * v5->aligned_row_len];
          v10 = v5->aligned_row_len - 1;
          if ( v10 >= 0 )
          {
            v11 = (unsigned int)(v10 + 4) >> 2;
            do
            {
              v9 += 16;
              *(float *)(v9 - 16) = *v8;
              v8 += 4;
              --v11;
              *(float *)(v9 - 12) = *(v8 - 3);
              *(float *)(v9 - 8) = *(v8 - 2);
              *(float *)(v9 - 4) = *(v8 - 1);
            }
            while ( v11 != 0 );
          }
          v5->desired_vector[v7] = big_matrix->desired_vector[original_pos[v7]];
          ++v7;
        }
        while ( v7 < n_column );
      }
    }
    else
    {
      i = 0;
      if ( n_column > 0 )
      {
        do
        {
          v12 = (int)&v5->matrix_values[v7 * v5->aligned_row_len];
          v13 = &big_matrix->matrix_values[v6[v7] * big_matrix->aligned_row_len];
          v14 = 0;
          j = 0;
          if ( v4 >= 4 )
          {
            v15 = v6 + 3;
            v16 = ((unsigned int)(v4 - 4) >> 2) + 1;
            v17 = v12 + 4;
            j = 4 * v16;
            do
            {
              *(float *)(v17 - 4) = v13[*(v15 - 3)];
              v18 = v13[*(int *)((char *)v6 + v17 - v12)];
              v17 += 16;
              *(float *)(v17 - 16) = v18;
              v19 = v13[*(v15 - 1)];
              v15 += 4;
              --v16;
              *(float *)(v17 - 12) = v19;
              *(float *)(v17 - 8) = v13[*(v15 - 4)];
            }
            while ( v16 != 0 );
            v14 = j;
            v7 = i;
            v6 = original_pos;
            v4 = n_column;
          }
          if ( v14 < v4 )
          {
            v25 = (char *)v6 - v12;
            v20 = n_column - j;
            v21 = v12 + 4 * v14;
            do
            {
              v22 = *(_DWORD *)&v25[v21];
              v21 += 4;
              --v20;
              *(float *)(v21 - 4) = v13[v22];
            }
            while ( v20 != 0 );
          }
          v5 = this;
          this->desired_vector[v7] = big_matrix->desired_vector[v6[v7]];
          v4 = n_column;
          i = ++v7;
        }
        while ( v7 < n_column );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009B8E0
// Name: public: void IVP_Great_Matrix_Many_Zero::set_value(float,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Great_Matrix_Many_Zero::set_value(IVP_Great_Matrix_Many_Zero *this, float val, int col, int row)
{
  this->matrix_values[col + row * this->columns] = val;
}

//------------------------------------------------------------------------------
// Address: 0x1009B900
// Name: public: void IVP_Great_Matrix_Many_Zero::mult_aligned(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Great_Matrix_Many_Zero::mult_aligned(IVP_Great_Matrix_Many_Zero *this)
{
  int columns; // edi
  int v2; // eax
  float *v3; // ebx
  int v4; // esi
  float v5; // xmm0_4
  float *desired_vector; // ecx
  float *v7; // esi
  unsigned int v8; // edx
  int v9; // ecx
  float *v10; // eax
  float v11; // xmm2_4
  float v12; // xmm0_4
  float *v13; // eax
  int v14; // edi
  float v15; // xmm2_4
  int i; // [esp+4h] [ebp-10h]
  IVP_Great_Matrix_Many_Zero *v17; // [esp+8h] [ebp-Ch]
  int j; // [esp+10h] [ebp-4h]

  columns = this->columns;
  v2 = 0;
  v17 = this;
  for ( j = 0; v2 < columns; j = v2 )
  {
    v3 = &this->matrix_values[v2 * this->aligned_row_len];
    v4 = 0;
    v5 = 0.0;
    if ( columns >= 4 )
    {
      desired_vector = this->desired_vector;
      v7 = desired_vector + 3;
      v8 = ((unsigned int)(columns - 4) >> 2) + 1;
      i = 4 * v8;
      v9 = (char *)desired_vector - (char *)v3;
      v10 = v3 + 1;
      do
      {
        v11 = (float)((float)((float)(*(v10 - 1) * *(v7 - 3)) + v5) + (float)(*(float *)((char *)v10 + v9) * *v10))
            + (float)(v10[1] * *(v7 - 1));
        v12 = v10[2] * *v7;
        v10 += 4;
        v7 += 4;
        --v8;
        v5 = v12 + v11;
      }
      while ( v8 != 0 );
      this = v17;
      v4 = i;
      v2 = j;
    }
    if ( v4 < columns )
    {
      v13 = &v3[v4];
      v14 = columns - v4;
      do
      {
        v15 = *(float *)((char *)v13 + (char *)this->desired_vector - (char *)v3) * *v13;
        ++v13;
        --v14;
        v5 = v5 + v15;
      }
      while ( v14 != 0 );
      v2 = j;
    }
    this->result_vector[v2] = v5;
    columns = this->columns;
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009BA00
// Name: public: void IVP_Great_Matrix_Many_Zero::mult(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Great_Matrix_Many_Zero::mult(IVP_Great_Matrix_Many_Zero *this)
{
  int columns; // esi
  int v2; // edi
  int v3; // ebx
  float v4; // xmm0_4
  float *v5; // edx
  float *v6; // eax
  unsigned int v7; // edi
  float v8; // xmm2_4
  float v9; // xmm0_4
  float *v10; // edx
  float *v11; // eax
  int v12; // esi
  float v13; // xmm2_4
  int j; // [esp+8h] [ebp-4h]

  columns = this->columns;
  v2 = 0;
  for ( j = 0; v2 < columns; j = v2 )
  {
    v3 = 0;
    v4 = 0.0;
    if ( columns >= 4 )
    {
      v5 = &this->matrix_values[v2 * columns + 2];
      v6 = this->desired_vector + 2;
      v7 = ((unsigned int)(columns - 4) >> 2) + 1;
      v3 = 4 * v7;
      do
      {
        v8 = (float)((float)((float)(*(v5 - 2) * *(v6 - 2)) + v4) + (float)(*(v5 - 1) * *(v6 - 1))) + (float)(*v6 * *v5);
        v9 = v5[1] * v6[1];
        v6 += 4;
        v5 += 4;
        --v7;
        v4 = v9 + v8;
      }
      while ( v7 != 0 );
      v2 = j;
    }
    if ( v3 < columns )
    {
      v10 = &this->desired_vector[v3];
      v11 = &this->matrix_values[v3 + v2 * columns];
      v12 = columns - v3;
      do
      {
        v13 = *v11++ * *v10++;
        --v12;
        v4 = v4 + v13;
      }
      while ( v12 != 0 );
      v2 = j;
    }
    this->result_vector[v2] = v4;
    columns = this->columns;
    ++v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009BAF0
// Name: private: void IVP_Linear_Constraint_Solver::mult_active_x_for_accel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Linear_Constraint_Solver::mult_active_x_for_accel(IVP_Linear_Constraint_Solver *this)
{
  int r_actives; // esi
  int *actives_inactives_ignored; // edi
  int v3; // ebx
  float *v4; // edx
  int v5; // eax
  float v6; // xmm1_4
  float *delta_f; // esi
  unsigned int v8; // ebx
  _DWORD *v9; // eax
  int v10; // edi
  float v11; // xmm0_4
  int *v12; // esi
  int v13; // ebx
  float v14; // xmm0_4
  int row_of_A; // [esp+4h] [ebp-10h]
  int j; // [esp+8h] [ebp-Ch]
  int v17; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  r_actives = this->r_actives;
  for ( i = r_actives; r_actives < this->n_variables; i = r_actives )
  {
    actives_inactives_ignored = this->actives_inactives_ignored;
    v3 = this->r_actives;
    row_of_A = actives_inactives_ignored[r_actives];
    v4 = &this->full_solver_mat.matrix_values[row_of_A * this->aligned_size];
    v5 = 0;
    v6 = 0.0;
    v17 = v3;
    if ( v3 >= 4 )
    {
      delta_f = this->delta_f;
      v8 = ((unsigned int)(v3 - 4) >> 2) + 1;
      v9 = actives_inactives_ignored + 2;
      j = 4 * v8;
      do
      {
        v10 = v9[1];
        v11 = (float)(delta_f[*v9] * v4[*v9])
            + (float)((float)(delta_f[*(v9 - 1)] * v4[*(v9 - 1)])
                    + (float)((float)(delta_f[*(v9 - 2)] * v4[*(v9 - 2)]) + v6));
        v9 += 4;
        --v8;
        v6 = (float)(delta_f[v10] * v4[v10]) + v11;
      }
      while ( v8 != 0 );
      v3 = v17;
      v5 = j;
      r_actives = i;
    }
    if ( v5 < v3 )
    {
      v12 = &this->actives_inactives_ignored[v5];
      v13 = v3 - v5;
      do
      {
        v14 = this->delta_f[*v12] * v4[*v12];
        ++v12;
        --v13;
        v6 = v6 + v14;
      }
      while ( v13 != 0 );
      r_actives = i;
    }
    ++r_actives;
    this->delta_accel[row_of_A] = v4[this->actives_inactives_ignored[this->ignored_pos]] + v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009BC00
// Name: private: void IVP_Linear_Constraint_Solver::mult_x_with_full_A_minus_b(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Linear_Constraint_Solver::mult_x_with_full_A_minus_b(IVP_Linear_Constraint_Solver *this)
{
  IVP_Linear_Constraint_Solver *v1; // esi
  int n_variables; // edx
  int v3; // eax
  int v4; // edx
  float *full_x; // ecx
  int v6; // ebx
  float v7; // xmm0_4
  float *v8; // esi
  float *v9; // eax
  unsigned int v10; // edi
  int v11; // ebx
  float v12; // xmm2_4
  float v13; // xmm0_4
  float *v14; // eax
  int v15; // ebx
  float v16; // xmm2_4
  int v18; // [esp+8h] [ebp-Ch]
  int i; // [esp+10h] [ebp-4h]

  v1 = this;
  n_variables = this->n_variables;
  v3 = 0;
  for ( i = 0; v3 < n_variables; i = v3 )
  {
    v4 = n_variables - 1;
    full_x = v1->full_x;
    v6 = (int)&v1->full_A[v3 * v1->aligned_size];
    v18 = v6;
    v7 = 0.0;
    if ( v4 >= 0 )
    {
      if ( v4 + 1 >= 4 )
      {
        v8 = (float *)(v6 + 4 * v4 - 12);
        v9 = &full_x[v4 - 1];
        v10 = (unsigned int)(v4 + 1) >> 2;
        v11 = v6 - (_DWORD)full_x;
        v4 -= 4 * v10;
        do
        {
          v12 = (float)((float)((float)(v9[1] * v8[3]) + v7) + (float)(*(float *)((char *)v9 + v11) * *v9))
              + (float)(*(v9 - 1) * v8[1]);
          v13 = *(v9 - 2) * *v8;
          v9 -= 4;
          v8 -= 4;
          --v10;
          v7 = v13 + v12;
        }
        while ( v10 != 0 );
        v6 = v18;
        v1 = this;
        v3 = i;
      }
      if ( v4 >= 0 )
      {
        v14 = &full_x[v4];
        v15 = v6 - (_DWORD)full_x;
        do
        {
          v16 = *(float *)((char *)v14 + v15) * *v14;
          --v14;
          --v4;
          v7 = v7 + v16;
        }
        while ( v4 >= 0 );
        v3 = i;
      }
    }
    v1->temp[v3] = v7 - v1->full_b[v3];
    n_variables = v1->n_variables;
    ++v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009BCF0
// Name: private: enum IVP_BOOL IVP_Linear_Constraint_Solver::numerical_stability_ok(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_Linear_Constraint_Solver::numerical_stability_ok(IVP_Linear_Constraint_Solver *this)
{
  int r_actives; // ecx
  int v3; // eax
  int *actives_inactives_ignored; // edx
  int n_variables; // edi
  int *i; // edx

  IVP_Linear_Constraint_Solver::mult_x_with_full_A_minus_b(this);
  r_actives = this->r_actives;
  v3 = 0;
  if ( r_actives <= 0 )
  {
LABEL_5:
    n_variables = this->n_variables;
    if ( r_actives >= n_variables )
      return 1;
    for ( i = &this->actives_inactives_ignored[r_actives]; fabs(this->temp[*i] - this->accel[*i]) <= this->TEST_EPS; ++i )
    {
      if ( ++r_actives >= n_variables )
        return 1;
    }
  }
  else
  {
    actives_inactives_ignored = this->actives_inactives_ignored;
    while ( fabs(this->temp[*actives_inactives_ignored]) <= this->TEST_EPS )
    {
      ++v3;
      ++actives_inactives_ignored;
      if ( v3 >= r_actives )
        goto LABEL_5;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1009BD90
// Name: private: void IVP_Linear_Constraint_Solver::alloc_memory(class IVP_U_Memory __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Linear_Constraint_Solver::alloc_memory(IVP_Linear_Constraint_Solver *this, IVP_U_Memory *my_mem)
{
  unsigned int v3; // ecx
  char *speicherbeginn; // edx
  char *v5; // eax
  int *v6; // eax
  int aligned_size; // ecx
  unsigned int v8; // ecx
  char *v9; // edx
  char *v10; // eax
  int *v11; // eax
  int v12; // ecx
  char *v13; // eax
  unsigned int v14; // ecx
  char *v15; // edx
  int v16; // edi
  int n_variables; // edx
  float *v18; // eax
  float *v19; // eax
  float *v20; // eax
  float *v21; // eax
  float *v22; // eax
  int v23; // edx
  float *v24; // eax
  float *v25; // eax
  float *v26; // eax
  float *v27; // eax
  float *v28; // eax
  float *v29; // eax
  float *v30; // eax
  float *v31; // eax
  float *v32; // eax
  float *v33; // eax

  v3 = 4 * this->aligned_size;
  speicherbeginn = my_mem->speicherbeginn;
  v5 = (char *)((unsigned int)&speicherbeginn[v3 + 31] & 0xFFFFFFE0);
  if ( v5 < my_mem->speicherende )
  {
    my_mem->speicherbeginn = v5;
    v6 = (int *)speicherbeginn;
  }
  else
  {
    v6 = (int *)IVP_U_Memory::neuer_sp_block(this: my_mem, groesse: v3);
  }
  aligned_size = this->aligned_size;
  this->actives_inactives_ignored = v6;
  v8 = 4 * aligned_size;
  v9 = my_mem->speicherbeginn;
  v10 = (char *)((unsigned int)&v9[v8 + 31] & 0xFFFFFFE0);
  if ( v10 < my_mem->speicherende )
  {
    my_mem->speicherbeginn = v10;
    v11 = (int *)v9;
  }
  else
  {
    v11 = (int *)IVP_U_Memory::neuer_sp_block(this: my_mem, groesse: v8);
  }
  v12 = 2 * this->aligned_size * (4 * this->n_variables + 13);
  this->variable_is_found_at = v11;
  v13 = my_mem->speicherbeginn;
  v14 = 2 * v12;
  v15 = (char *)((unsigned int)&v13[v14 + 31] & 0xFFFFFFE0);
  if ( v15 < my_mem->speicherende )
    my_mem->speicherbeginn = v15;
  else
    v13 = IVP_U_Memory::neuer_sp_block(this: my_mem, groesse: v14);
  v16 = this->aligned_size;
  n_variables = this->n_variables;
  this->accel = (float *)v13;
  v18 = (float *)&v13[4 * v16];
  this->delta_accel = v18;
  v19 = &v18[v16];
  this->delta_f = v19;
  v20 = &v19[v16];
  this->reset_x = v20;
  v21 = &v20[v16];
  this->reset_accel = v21;
  v22 = &v21[v16];
  this->lu_sub_solver.L_matrix = v22;
  v23 = v16 * n_variables;
  v24 = &v22[v23];
  this->lu_sub_solver.U_matrix = v24;
  v25 = &v24[v23];
  this->lu_sub_solver.input_vec = v25;
  v26 = &v25[v16];
  this->lu_sub_solver.out_vec = v26;
  v27 = &v26[v16];
  this->lu_sub_solver.temp_vec = v27;
  v28 = &v27[v16];
  this->lu_sub_solver.mult_vec = v28;
  v29 = &v28[v16];
  this->sub_solver_mat.matrix_values = v29;
  v30 = &v29[v23];
  this->sub_solver_mat.desired_vector = v30;
  v31 = &v30[v16];
  this->sub_solver_mat.result_vector = v31;
  v32 = &v31[v16];
  this->inv_mat.matrix_values = v32;
  v33 = &v32[v23];
  this->inv_mat.desired_vector = v33;
  this->inv_mat.result_vector = &v33[v16];
}

//------------------------------------------------------------------------------
// Address: 0x1009BEB0
// Name: private: void IVP_Linear_Constraint_Solver::update_step_vars(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Linear_Constraint_Solver::update_step_vars(IVP_Linear_Constraint_Solver *this, float step_size)
{
  int i; // eax
  float *v3; // edx
  float v4; // xmm1_4
  int j; // eax
  int v6; // edx
  float *accel; // esi
  bool v8; // cc
  float *v9; // edx
  int k; // eax
  int v11; // edx
  float *full_x; // esi
  float *v13; // edx

  for ( i = 0; i < this->n_variables; *v3 = v4 )
  {
    this->accel[i] = (float)(this->delta_accel[i] * step_size) + this->accel[i];
    v3 = &this->full_x[i];
    v4 = (float)(this->delta_f[i++] * step_size) + *v3;
  }
  for ( j = this->r_actives; j < this->ignored_pos; ++j )
  {
    v6 = this->actives_inactives_ignored[j];
    accel = this->accel;
    v8 = accel[v6] >= 0.0;
    v9 = &accel[v6];
    if ( !v8 )
      *v9 = 0.0;
  }
  for ( k = 0; k < this->r_actives; ++k )
  {
    v11 = this->actives_inactives_ignored[k];
    full_x = this->full_x;
    v8 = full_x[v11] >= 0.0;
    v13 = &full_x[v11];
    if ( !v8 )
      *v13 = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009BF60
// Name: private: void IVP_Linear_Constraint_Solver::lcs_bubble_sort_x_vals(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Linear_Constraint_Solver::lcs_bubble_sort_x_vals(IVP_Linear_Constraint_Solver *this)
{
  int v1; // ebx
  int v2; // edx
  int *actives_inactives_ignored; // eax
  int v4; // esi
  int v5; // edi
  int v6; // eax
  int *v7; // esi
  int v8; // edi
  int v9; // ebx
  int *v10; // esi
  int v11; // edi
  int v12; // ebx
  int *v13; // esi
  int v14; // edi
  int v15; // ebx
  int *v16; // esi
  int v17; // edi
  int v18; // ebx
  int v19; // esi
  int *v20; // eax
  int v21; // esi
  int v22; // edi
  int r2; // [esp+4h] [ebp-Ch]
  int v24; // [esp+Ch] [ebp-4h]

  v1 = 1;
  v2 = 0;
  for ( r2 = 1; v1 < this->r_actives; r2 = v1 )
  {
    if ( this->full_x[this->actives_inactives_ignored[v1]] > this->full_x[this->actives_inactives_ignored[v2]] )
    {
      actives_inactives_ignored = this->actives_inactives_ignored;
      v4 = actives_inactives_ignored[v1];
      v5 = actives_inactives_ignored[v2];
      actives_inactives_ignored[v2] = v4;
      this->actives_inactives_ignored[v1] = v5;
      this->variable_is_found_at[v4] = v2;
      this->variable_is_found_at[v5] = v1;
      if ( v2 < 4 )
      {
LABEL_11:
        while ( v2 > 0 )
        {
          if ( this->full_x[this->actives_inactives_ignored[v2]] <= this->full_x[this->actives_inactives_ignored[v2 - 1]] )
            break;
          v20 = this->actives_inactives_ignored;
          v21 = v20[v2 - 1];
          v22 = v20[v2];
          v20[v2] = v21;
          this->actives_inactives_ignored[v2 - 1] = v22;
          this->variable_is_found_at[v21] = v2--;
          this->variable_is_found_at[v22] = v2;
        }
      }
      else
      {
        v24 = v2 - 2;
        v6 = 4 * v2 - 8;
        while ( this->full_x[*(int *)((char *)this->actives_inactives_ignored + v6 + 8)] > this->full_x[*(int *)((char *)this->actives_inactives_ignored + v6 + 4)] )
        {
          v7 = this->actives_inactives_ignored;
          v8 = *(int *)((char *)v7 + v6 + 4);
          v9 = *(int *)((char *)v7 + v6 + 8);
          *(int *)((char *)v7 + v6 + 8) = v8;
          *(int *)((char *)this->actives_inactives_ignored + v6 + 4) = v9;
          this->variable_is_found_at[v8] = v2;
          this->variable_is_found_at[v9] = v24 + 1;
          if ( this->full_x[*(int *)((char *)this->actives_inactives_ignored + v6 + 4)] <= this->full_x[*(int *)((char *)this->actives_inactives_ignored + v6)] )
            break;
          v10 = this->actives_inactives_ignored;
          v11 = *(int *)((char *)v10 + v6);
          v12 = *(int *)((char *)v10 + v6 + 4);
          *(int *)((char *)v10 + v6 + 4) = v11;
          *(int *)((char *)this->actives_inactives_ignored + v6) = v12;
          this->variable_is_found_at[v11] = v24 + 1;
          this->variable_is_found_at[v12] = v24;
          if ( this->full_x[*(int *)((char *)this->actives_inactives_ignored + v6)] <= this->full_x[*(int *)((char *)this->actives_inactives_ignored + v6 - 4)] )
            break;
          v13 = this->actives_inactives_ignored;
          v14 = *(int *)((char *)v13 + v6 - 4);
          v15 = *(int *)((char *)v13 + v6);
          *(int *)((char *)v13 + v6) = v14;
          *(int *)((char *)this->actives_inactives_ignored + v6 - 4) = v15;
          this->variable_is_found_at[v14] = v24;
          this->variable_is_found_at[v15] = v24 - 1;
          if ( this->full_x[*(int *)((char *)this->actives_inactives_ignored + v6 - 4)] <= this->full_x[*(int *)((char *)this->actives_inactives_ignored + v6 - 8)] )
            break;
          v16 = this->actives_inactives_ignored;
          v17 = *(int *)((char *)v16 + v6 - 8);
          v18 = *(int *)((char *)v16 + v6 - 4);
          *(int *)((char *)v16 + v6 - 4) = v17;
          *(int *)((char *)this->actives_inactives_ignored + v6 - 8) = v18;
          this->variable_is_found_at[v17] = v24 - 1;
          v19 = v24;
          v24 -= 4;
          v2 -= 4;
          v6 -= 16;
          this->variable_is_found_at[v18] = v19 - 2;
          if ( v2 <= 3 )
          {
            v1 = r2;
            goto LABEL_11;
          }
        }
        v1 = r2;
      }
    }
    v2 = v1++;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009C170
// Name: private: void IVP_Linear_Constraint_Solver::get_values_when_setup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Linear_Constraint_Solver::get_values_when_setup(IVP_Linear_Constraint_Solver *this)
{
  float *reset_accel; // eax
  float *delta_accel; // edx
  int v4; // eax
  float *v5; // ecx
  float v6; // xmm0_4
  float *v7; // ecx
  int i; // eax
  int v9; // edx
  int v10; // eax

  reset_accel = this->reset_accel;
  this->full_solver_mat.desired_vector = this->reset_x;
  this->full_solver_mat.result_vector = reset_accel;
  IVP_Great_Matrix_Many_Zero::mult_aligned(this: &this->full_solver_mat);
  delta_accel = this->delta_accel;
  this->full_solver_mat.desired_vector = this->delta_f;
  v4 = 0;
  for ( this->full_solver_mat.result_vector = delta_accel; v4 < this->n_variables; *v7 = v6 )
  {
    v5 = this->reset_accel;
    v6 = v5[v4] - this->full_b[v4];
    v7 = &v5[v4++];
  }
  for ( i = 0; i < this->r_actives; this->reset_accel[v9] = 0.0 )
    v9 = this->actives_inactives_ignored[i++];
  v10 = this->n_variables - 1;
  if ( v10 >= 0 )
  {
    if ( this->n_variables >= 4 )
    {
      do
      {
        this->accel[v10] = this->reset_accel[v10];
        this->full_x[v10] = this->reset_x[v10];
        this->accel[v10 - 1] = this->reset_accel[v10 - 1];
        this->full_x[v10 - 1] = this->reset_x[v10 - 1];
        this->accel[v10 - 2] = this->reset_accel[v10 - 2];
        this->full_x[v10 - 2] = this->reset_x[v10 - 2];
        this->accel[v10 - 3] = this->reset_accel[v10 - 3];
        this->full_x[v10 - 3] = this->reset_x[v10 - 3];
        v10 -= 4;
      }
      while ( v10 >= 3 );
    }
    for ( ; v10 >= 0; this->full_x[v10 + 1] = this->reset_x[v10 + 1] )
    {
      --v10;
      this->accel[v10 + 1] = this->reset_accel[v10 + 1];
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009C2A0
// Name: private: void IVP_Linear_Constraint_Solver::move_variable_to_end(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Linear_Constraint_Solver::move_variable_to_end(IVP_Linear_Constraint_Solver *this, int var_nr)
{
  int i; // eax
  int *actives_inactives_ignored; // edx
  int v4; // esi
  int v5; // edi

  for ( i = var_nr + 1; i < this->n_variables; ++i )
  {
    actives_inactives_ignored = this->actives_inactives_ignored;
    v4 = actives_inactives_ignored[i];
    v5 = actives_inactives_ignored[i - 1];
    actives_inactives_ignored[i - 1] = v4;
    this->actives_inactives_ignored[i] = v5;
    this->variable_is_found_at[v4] = i - 1;
    this->variable_is_found_at[v5] = i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009C2E0
// Name: private: int IVP_Linear_Constraint_Solver::full_setup_test_ranges(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_Linear_Constraint_Solver::full_setup_test_ranges(IVP_Linear_Constraint_Solver *this)
{
  int v1; // esi
  int v2; // edx
  float *full_x; // eax
  float v4; // xmm1_4
  float *v5; // eax
  int *actives_inactives_ignored; // edx
  int v7; // eax
  int v8; // edi
  int v9; // ebx
  int r_actives; // edx
  int v11; // eax
  int *v12; // edx
  int v13; // esi
  int v14; // edi
  int v16; // [esp+0h] [ebp-Ch]
  int i; // [esp+4h] [ebp-8h]
  int illegal_vars; // [esp+8h] [ebp-4h]

  v1 = 0;
  for ( illegal_vars = 0; v1 < this->r_actives; ++v1 )
  {
    v2 = this->actives_inactives_ignored[v1];
    full_x = this->full_x;
    v4 = full_x[v2];
    v5 = &full_x[v2];
    if ( this->SOLVER_EPS > v4 )
    {
      if ( v4 <= (float)-this->SOLVER_EPS )
      {
        IVP_Linear_Constraint_Solver::move_variable_to_end(this, var_nr: v1);
        ++illegal_vars;
        --this->ignored_pos;
      }
      else
      {
        *v5 = 0.0;
        actives_inactives_ignored = this->actives_inactives_ignored;
        v7 = this->r_actives - 1;
        v8 = actives_inactives_ignored[v7];
        v9 = actives_inactives_ignored[v1];
        actives_inactives_ignored[v1] = v8;
        this->actives_inactives_ignored[v7] = v9;
        this->variable_is_found_at[v8] = v1;
        this->variable_is_found_at[v9] = v7;
      }
      --this->r_actives;
      --v1;
      --this->lu_sub_solver.n_sub;
      this->sub_solver_status = 1;
    }
  }
  r_actives = this->r_actives;
  i = r_actives;
  if ( r_actives < this->ignored_pos )
  {
    v11 = r_actives + 1;
    v16 = r_actives + 1;
    do
    {
      if ( this->accel[this->actives_inactives_ignored[r_actives]] < 0.0 )
      {
        if ( v11 < this->n_variables )
        {
          do
          {
            v12 = this->actives_inactives_ignored;
            v13 = v12[v11];
            v14 = v12[v11 - 1];
            v12[v11 - 1] = v13;
            this->actives_inactives_ignored[v11] = v14;
            this->variable_is_found_at[v13] = v11 - 1;
            this->variable_is_found_at[v14] = v11++;
          }
          while ( v11 < this->n_variables );
          v11 = v16;
          r_actives = i;
        }
        --r_actives;
        --v11;
        --this->ignored_pos;
      }
      ++r_actives;
      ++v11;
      i = r_actives;
      v16 = v11;
    }
    while ( r_actives < this->ignored_pos );
  }
  return illegal_vars;
}

//------------------------------------------------------------------------------
// Address: 0x1009C400
// Name: public: enum IVP_RETURN_TYPE IVP_Great_Matrix_Many_Zero::lu_crout(int __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall IVP_Great_Matrix_Many_Zero::lu_crout(IVP_Great_Matrix_Many_Zero *this, int *index_vec, float *sign)
{
  int columns; // edx
  int v4; // edi
  int v5; // ebx
  float v6; // xmm0_4
  float *matrix_values; // eax
  float *v8; // esi
  float *v9; // edi
  unsigned int v10; // eax
  float v11; // xmm1_4
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float *v15; // esi
  int v16; // eax
  float v17; // xmm1_4
  float v18; // xmm1_4
  int v19; // eax
  int v20; // esi
  float v21; // xmm0_4
  int v22; // edi
  float *v23; // edi
  float *v24; // ebx
  int v25; // esi
  unsigned int v26; // edi
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  float *v32; // ebx
  float v33; // xmm0_4
  float v34; // xmm1_4
  float *v35; // ebx
  float *v36; // esi
  float *v37; // ebx
  int v38; // esi
  float v39; // xmm1_4
  int v40; // edi
  float v41; // xmm1_4
  int v42; // ebx
  float v43; // xmm0_4
  float *v44; // edi
  float *v45; // ebx
  int v46; // esi
  unsigned int v47; // edi
  float v48; // xmm6_4
  float v49; // xmm0_4
  float v50; // xmm6_4
  float v51; // xmm0_4
  float v52; // xmm6_4
  float *v53; // ebx
  float v54; // xmm0_4
  float v55; // xmm6_4
  float *v56; // ebx
  float *v57; // esi
  float *v58; // edi
  float *v59; // ebx
  int v60; // esi
  float v61; // xmm6_4
  float v62; // xmm0_4
  int v63; // ebx
  int v64; // edi
  int v65; // edi
  int v66; // esi
  float *v67; // ebx
  float v68; // xmm0_4
  float *v69; // ebx
  float v70; // xmm0_4
  float *v71; // ebx
  float v72; // xmm0_4
  float *v73; // ebx
  float v74; // xmm0_4
  int v75; // esi
  int v76; // ebx
  float *v77; // edi
  float v78; // xmm0_4
  int v79; // edi
  float v80; // xmm0_4
  int v81; // esi
  float *v82; // edi
  int v83; // ebx
  float v84; // xmm1_4
  float *v85; // edi
  int v86; // ebx
  float v87; // xmm1_4
  float *v88; // edi
  int v89; // ebx
  float v90; // xmm1_4
  bool v91; // zf
  int v92; // esi
  int v93; // ebx
  int zeros; // [esp+Ch] [ebp-48h]
  int v96; // [esp+10h] [ebp-44h]
  int v97; // [esp+10h] [ebp-44h]
  float *v98; // [esp+14h] [ebp-40h]
  int v99; // [esp+14h] [ebp-40h]
  unsigned int v100; // [esp+14h] [ebp-40h]
  int v101; // [esp+14h] [ebp-40h]
  int v102; // [esp+14h] [ebp-40h]
  int v103; // [esp+18h] [ebp-3Ch]
  float *v104; // [esp+18h] [ebp-3Ch]
  int v105; // [esp+18h] [ebp-3Ch]
  float *v106; // [esp+1Ch] [ebp-38h]
  float *v107; // [esp+1Ch] [ebp-38h]
  int v108; // [esp+1Ch] [ebp-38h]
  float *v109; // [esp+20h] [ebp-34h]
  float *v110; // [esp+20h] [ebp-34h]
  int v111; // [esp+20h] [ebp-34h]
  float *v112; // [esp+24h] [ebp-30h]
  float *v113; // [esp+24h] [ebp-30h]
  unsigned int v114; // [esp+24h] [ebp-30h]
  float *v115; // [esp+28h] [ebp-2Ch]
  int v116; // [esp+28h] [ebp-2Ch]
  int v117; // [esp+2Ch] [ebp-28h]
  int v118; // [esp+30h] [ebp-24h]
  int v119; // [esp+34h] [ebp-20h]
  int v120; // [esp+38h] [ebp-1Ch]
  int imax; // [esp+3Ch] [ebp-18h]
  int v122; // [esp+40h] [ebp-14h]
  int v123; // [esp+40h] [ebp-14h]
  int v124; // [esp+44h] [ebp-10h]
  float *v125; // [esp+48h] [ebp-Ch]
  float *v126; // [esp+48h] [ebp-Ch]
  int k; // [esp+4Ch] [ebp-8h]
  int ka; // [esp+4Ch] [ebp-8h]
  int kb; // [esp+4Ch] [ebp-8h]
  int i; // [esp+50h] [ebp-4h]
  int ia; // [esp+50h] [ebp-4h]
  int ib; // [esp+50h] [ebp-4h]
  int ic; // [esp+50h] [ebp-4h]
  int id; // [esp+50h] [ebp-4h]

  columns = this->columns;
  v4 = 0;
  *sign = 1.0;
  imax = 0;
  zeros = 0;
  i = 0;
  if ( columns > 0 )
  {
    v96 = 0;
    do
    {
      v5 = 0;
      v6 = 0.0;
      if ( columns >= 4 )
      {
        matrix_values = this->matrix_values;
        v8 = &matrix_values[v4 + 2];
        v9 = &matrix_values[v4 + 1];
        v10 = ((unsigned int)(columns - 4) >> 2) + 1;
        v5 = 4 * v10;
        do
        {
          v11 = fabs(*(v8 - 2));
          if ( v11 > v6 )
            v6 = v11;
          v12 = fabs(*v9);
          if ( v12 > v6 )
            v6 = v12;
          v13 = fabs(*v8);
          if ( v13 > v6 )
            v6 = v13;
          v14 = fabs(v8[1]);
          if ( v14 > v6 )
            v6 = v14;
          v9 += 4;
          v8 += 4;
          --v10;
        }
        while ( v10 != 0 );
        v4 = v96;
      }
      if ( v5 < columns )
      {
        v15 = &this->matrix_values[v4 + v5];
        v16 = columns - v5;
        do
        {
          v17 = fabs(*v15);
          if ( v17 > v6 )
            v6 = v17;
          ++v15;
          --v16;
        }
        while ( v16 != 0 );
      }
      if ( v6 == 0.0 )
        v18 = 0.0;
      else
        v18 = 1.0 / v6;
      this->desired_vector[i] = v18;
      v4 += columns;
      ++i;
      v96 = v4;
    }
    while ( i < columns );
  }
  v19 = 0;
  if ( columns <= 0 )
    return true;
  v120 = columns;
  v117 = 3 * columns;
  v118 = 0;
  v124 = 0;
  v119 = 0;
  v97 = columns - 1;
  do
  {
    v20 = 0;
    ia = 0;
    if ( v19 > 0 )
    {
      v122 = 0;
      v103 = v19;
      do
      {
        v21 = this->matrix_values[v103];
        v22 = 0;
        if ( v20 >= 4 )
        {
          v23 = this->matrix_values;
          v125 = &v23[v122];
          v115 = &v23[v19];
          v106 = &v23[3 * columns + v19];
          v109 = &v23[2 * columns + v19];
          v24 = &v23[v120];
          v25 = 16 * columns;
          v26 = ((unsigned int)(ia - 4) >> 2) + 1;
          v112 = v24;
          k = 4 * v26;
          do
          {
            v27 = *v125 * *v115;
            v115 = (float *)((char *)v115 + v25);
            v28 = v21 - v27;
            v29 = v125[1] * *v112;
            v112 = (float *)((char *)v112 + v25);
            v30 = v28 - v29;
            v31 = v125[2] * *v109;
            v32 = v125;
            v125 += 4;
            v109 = (float *)((char *)v109 + v25);
            v33 = v30 - v31;
            v34 = v32[3];
            v35 = v106;
            v106 = (float *)((char *)v106 + v25);
            --v26;
            v21 = v33 - (float)(v34 * *v35);
          }
          while ( v26 != 0 );
          v22 = k;
          v20 = ia;
        }
        if ( v22 < v20 )
        {
          v36 = this->matrix_values;
          v98 = &v36[v22 + v122];
          v37 = &v36[v19 + columns * v22];
          v38 = ia - v22;
          do
          {
            v39 = *v98++ * *v37;
            v37 += columns;
            --v38;
            v21 = v21 - v39;
          }
          while ( v38 != 0 );
          v20 = ia;
        }
        v122 += columns;
        this->matrix_values[v103] = v21;
        ++v20;
        v103 += columns;
        ia = v20;
      }
      while ( v20 < v19 );
    }
    v40 = v19;
    v41 = 0.0;
    ib = v19;
    if ( v19 < columns )
    {
      v116 = v124;
      v99 = v118;
      v123 = v119 + 8;
      do
      {
        v42 = 0;
        v43 = *(float *)((char *)this->matrix_values + v99);
        ka = 0;
        if ( v19 >= 4 )
        {
          v44 = this->matrix_values;
          v126 = (float *)((char *)v44 + v123);
          v104 = &v44[v19];
          v113 = &v44[3 * columns + v19];
          v110 = &v44[2 * columns + v19];
          v45 = &v44[v120];
          v46 = 16 * columns;
          v47 = ((unsigned int)(v19 - 4) >> 2) + 1;
          v107 = v45;
          ka = 4 * v47;
          do
          {
            v48 = *(v126 - 2) * *v104;
            v104 = (float *)((char *)v104 + v46);
            v49 = v43 - v48;
            v50 = *(v126 - 1) * *v107;
            v107 = (float *)((char *)v107 + v46);
            v51 = v49 - v50;
            v52 = *v126 * *v110;
            v53 = v126;
            v126 += 4;
            v110 = (float *)((char *)v110 + v46);
            v54 = v51 - v52;
            v55 = v53[1];
            v56 = v113;
            v113 = (float *)((char *)v113 + v46);
            --v47;
            v43 = v54 - (float)(v55 * *v56);
          }
          while ( v47 != 0 );
          v40 = ib;
          v42 = ka;
        }
        if ( v42 < v19 )
        {
          v57 = this->matrix_values;
          v58 = &v57[v42 + v116];
          v59 = &v57[v19 + columns * v42];
          v60 = v19 - ka;
          while ( 1 )
          {
            v61 = *v58 * *v59;
            v59 += columns;
            --v60;
            v43 = v43 - v61;
            if ( v60 == 0 )
              break;
            ++v58;
          }
          v40 = ib;
        }
        *(float *)((char *)this->matrix_values + v99) = v43;
        v62 = fabs(v43) * this->desired_vector[v40];
        if ( v62 >= v41 )
        {
          v41 = v62;
          imax = v40;
        }
        v116 += columns;
        v123 += 4 * columns;
        v99 += 4 * columns;
        ib = ++v40;
      }
      while ( v40 < columns );
    }
    v63 = imax;
    if ( v19 != imax )
    {
      v64 = 0;
      if ( columns >= 4 )
      {
        v65 = v119;
        v100 = ((unsigned int)(columns - 4) >> 2) + 1;
        v66 = imax * columns;
        kb = 4 * v100;
        do
        {
          v67 = this->matrix_values;
          v68 = v67[v66];
          v67[v66] = *(float *)((char *)v67 + v65);
          *(float *)((char *)this->matrix_values + v65) = v68;
          v69 = this->matrix_values;
          v70 = v69[v66 + 1];
          v69[v66 + 1] = *(float *)((char *)v69 + v65 + 4);
          *(float *)((char *)this->matrix_values + v65 + 4) = v70;
          v71 = this->matrix_values;
          v72 = v71[v66 + 2];
          v71[v66 + 2] = *(float *)((char *)v71 + v65 + 8);
          *(float *)((char *)this->matrix_values + v65 + 8) = v72;
          v73 = this->matrix_values;
          v74 = v73[v66 + 3];
          v73[v66 + 3] = *(float *)((char *)v73 + v65 + 12);
          *(float *)((char *)this->matrix_values + v65 + 12) = v74;
          v65 += 16;
          v66 += 4;
          --v100;
        }
        while ( v100 != 0 );
        v64 = kb;
        v63 = imax;
      }
      if ( v64 < columns )
      {
        v75 = v64 + v63 * columns;
        v101 = columns - v64;
        v76 = v64 + v124;
        do
        {
          v77 = this->matrix_values;
          v78 = v77[v75];
          v77[v75] = v77[v76];
          this->matrix_values[v76] = v78;
          ++v75;
          ++v76;
          --v101;
        }
        while ( v101 != 0 );
        v63 = imax;
      }
      *sign = -*sign;
      this->desired_vector[v63] = this->desired_vector[v19];
    }
    index_vec[v19] = v63;
    if ( this->MATRIX_EPS <= fabs(*(float *)((char *)this->matrix_values + v118)) )
    {
      if ( v19 != columns - 1 )
      {
        v79 = v19 + 1;
        v80 = 1.0 / *(float *)((char *)this->matrix_values + v118);
        ic = v19 + 1;
        if ( v19 + 1 < columns )
        {
          if ( v97 >= 4 )
          {
            v102 = 4 * (columns + v124 + v19);
            v111 = 4 * (columns + v19 + v117);
            v108 = 4 * (v19 + v117);
            v105 = 4 * (columns + columns + v124 + v19);
            v81 = 16 * columns;
            v114 = ((unsigned int)(columns - ic - 4) >> 2) + 1;
            id = ic + 4 * v114;
            do
            {
              v82 = this->matrix_values;
              v83 = v102;
              v84 = *(float *)((char *)v82 + v102);
              v102 += v81;
              *(float *)((char *)v82 + v83) = v84 * v80;
              v85 = this->matrix_values;
              v86 = v105;
              v87 = *(float *)((char *)v85 + v105);
              v105 += v81;
              *(float *)((char *)v85 + v86) = v87 * v80;
              v88 = this->matrix_values;
              v89 = v108;
              v90 = *(float *)((char *)v88 + v108);
              v108 += v81;
              *(float *)((char *)v88 + v89) = v90 * v80;
              *(float *)((char *)this->matrix_values + v111) = v80 * *(float *)((char *)this->matrix_values + v111);
              v91 = v114-- == 1;
              v111 += v81;
            }
            while ( !v91 );
            v79 = id;
          }
          if ( v79 < columns )
          {
            v92 = v19 + columns * v79;
            v93 = columns - v79;
            do
            {
              this->matrix_values[v92] = v80 * this->matrix_values[v92];
              v92 += columns;
              --v93;
            }
            while ( v93 != 0 );
          }
        }
      }
    }
    else
    {
      ++zeros;
    }
    --v97;
    ++v120;
    v124 += columns;
    v117 += columns;
    v119 += 4 * columns;
    v118 += 4 * columns + 4;
    ++v19;
  }
  while ( v19 < columns );
  return zeros == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1009CAA0
// Name: public: enum IVP_RETURN_TYPE IVP_Incr_L_U_Matrix::normize_row(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_Incr_L_U_Matrix::normize_row(IVP_Incr_L_U_Matrix *this, int row_nr)
{
  int v2; // eax
  int v3; // edi
  float v4; // xmm1_4
  signed int v6; // eax
  int v7; // esi
  float v8; // xmm0_4
  float *v9; // eax
  unsigned int v10; // edx
  unsigned int v11; // edx
  float *v12; // eax
  unsigned int v13; // edx

  v2 = row_nr * this->aligned_row_len;
  v3 = v2 + row_nr;
  v4 = this->U_matrix[v3];
  if ( this->MATRIX_EPS > COERCE_FLOAT(LODWORD(v4) & _mask__AbsFloat_) )
    return 0;
  v6 = (signed int)&this->L_matrix[v2];
  v7 = this->n_sub + ((int)(v6 - (v6 & 0xFFFFFFF0)) >> 2);
  v8 = 1.0 / v4;
  if ( v7 > 0 )
  {
    v9 = (float *)((v6 & 0xFFFFFFF0) + 8);
    v10 = ((unsigned int)(v7 - 1) >> 2) + 1;
    do
    {
      *(v9 - 2) = v8 * *(v9 - 2);
      *(v9 - 1) = *(v9 - 1) * v8;
      *v9 = v8 * *v9;
      v9[1] = v9[1] * v8;
      v9 += 4;
      --v10;
    }
    while ( v10 != 0 );
  }
  v11 = (int)&this->U_matrix[v3 + 1] & 0xFFFFFFF0;
  if ( ((int)((int)&this->U_matrix[v3 + 1] - v11) >> 2) - row_nr + this->n_sub - 1 > 0 )
  {
    v12 = (float *)(v11 + 8);
    v13 = ((unsigned int)(((int)((int)&this->U_matrix[v3 + 1] - v11) >> 2) - row_nr + this->n_sub - 2) >> 2) + 1;
    do
    {
      *(v12 - 2) = v8 * *(v12 - 2);
      *(v12 - 1) = *(v12 - 1) * v8;
      *v12 = v8 * *v12;
      v12[1] = v12[1] * v8;
      v12 += 4;
      --v13;
    }
    while ( v13 != 0 );
  }
  this->U_matrix[v3] = 1.0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1009CBC0
// Name: public: void IVP_Incr_L_U_Matrix::pivot_search_l_u(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Incr_L_U_Matrix::pivot_search_l_u(IVP_Incr_L_U_Matrix *this, int col_nr)
{
  int v2; // edx
  float *U_matrix; // ebx
  int aligned_row_len; // edi
  int v5; // eax
  float v6; // xmm0_4
  int v7; // esi
  float v8; // xmm1_4
  float v9; // xmm1_4
  float v10; // xmm1_4
  float v11; // xmm1_4
  int v12; // esi
  float *v13; // edi
  float v14; // xmm1_4
  int v15; // edi
  int v16; // esi
  int v17; // ebx
  float *v18; // eax
  signed int v19; // esi
  unsigned int v20; // edi
  int v21; // esi
  float *v22; // eax
  float *v23; // edx
  unsigned int v24; // esi
  int v25; // xmm0_4
  int v26; // xmm0_4
  float v27; // xmm0_4
  int v28; // xmm0_4
  float *L_matrix; // eax
  unsigned int v30; // esi
  int v31; // edx
  float *v32; // eax
  float *v33; // ecx
  unsigned int v34; // edx
  int v35; // xmm0_4
  int v36; // xmm0_4
  float v37; // xmm0_4
  int v38; // xmm0_4
  float *v39; // [esp+4h] [ebp-10h]
  float *v40; // [esp+8h] [ebp-Ch]
  float *v41; // [esp+Ch] [ebp-8h]
  float *v42; // [esp+10h] [ebp-4h]
  int pivot_row; // [esp+1Ch] [ebp+8h]

  v2 = col_nr;
  U_matrix = this->U_matrix;
  aligned_row_len = this->aligned_row_len;
  v5 = this->n_sub - 1;
  v6 = fabs(U_matrix[col_nr * (aligned_row_len + 1)]);
  if ( v5 > col_nr )
  {
    if ( v5 - col_nr >= 4 )
    {
      v42 = &U_matrix[col_nr + v5 * aligned_row_len];
      v39 = &U_matrix[col_nr + aligned_row_len * (this->n_sub - 4)];
      v40 = &U_matrix[col_nr + aligned_row_len * (this->n_sub - 3)];
      v7 = -16 * aligned_row_len;
      v41 = (float *)((char *)&U_matrix[col_nr] + aligned_row_len * (4 * v5 - 4));
      do
      {
        v8 = fabs(*v42);
        if ( v8 > v6 )
        {
          col_nr = v5;
          v6 = v8;
        }
        v9 = fabs(*v41);
        if ( v9 > v6 )
        {
          col_nr = v5 - 1;
          v6 = v9;
        }
        v10 = fabs(*v40);
        if ( v10 > v6 )
        {
          col_nr = v5 - 2;
          v6 = v10;
        }
        v11 = fabs(*v39);
        if ( v11 > v6 )
        {
          col_nr = v5 - 3;
          v6 = v11;
        }
        v42 = (float *)((char *)v42 + v7);
        v41 = (float *)((char *)v41 + v7);
        v40 = (float *)((char *)v40 + v7);
        v39 = (float *)((char *)v39 + v7);
        v5 -= 4;
      }
      while ( v5 > v2 + 3 );
    }
    if ( v5 > v2 )
    {
      v12 = -4 * aligned_row_len;
      v13 = &U_matrix[v2 + v5 * aligned_row_len];
      do
      {
        v14 = fabs(*v13);
        if ( v14 > v6 )
        {
          col_nr = v5;
          v6 = v14;
        }
        --v5;
        v13 = (float *)((char *)v13 + v12);
      }
      while ( v5 > v2 );
    }
    v15 = col_nr;
    if ( col_nr != v2 )
    {
      v16 = this->aligned_row_len;
      pivot_row = v2 * v16;
      v17 = v15 * v16;
      v18 = this->U_matrix;
      v19 = (signed int)&v18[v2 + v2 * v16];
      v20 = v19 & 0xFFFFFFF0;
      v21 = this->n_sub + ((int)(v19 - (v19 & 0xFFFFFFF0)) >> 2) - v2;
      v22 = (float *)((unsigned int)&v18[v2 + v17] & 0xFFFFFFF0);
      if ( v21 > 0 )
      {
        v23 = (float *)(v20 + 8);
        v24 = ((unsigned int)(v21 - 1) >> 2) + 1;
        do
        {
          v25 = *((_DWORD *)v23 - 2);
          *(v23 - 2) = *v22;
          *(_DWORD *)v22 = v25;
          v26 = *((_DWORD *)v23 - 1);
          *(v23 - 1) = v22[1];
          *((_DWORD *)v22 + 1) = v26;
          v27 = *v23;
          *v23 = v22[2];
          v22[2] = v27;
          v28 = *((_DWORD *)v23 + 1);
          v23[1] = v22[3];
          *((_DWORD *)v22 + 3) = v28;
          v23 += 4;
          v22 += 4;
          --v24;
        }
        while ( v24 != 0 );
      }
      L_matrix = this->L_matrix;
      v30 = (unsigned int)&L_matrix[pivot_row] & 0xFFFFFFF0;
      v31 = this->n_sub + ((int)((int)&L_matrix[pivot_row] - v30) >> 2);
      v32 = (float *)((unsigned int)&L_matrix[v17] & 0xFFFFFFF0);
      if ( v31 > 0 )
      {
        v33 = (float *)(v30 + 8);
        v34 = ((unsigned int)(v31 - 1) >> 2) + 1;
        do
        {
          v35 = *((_DWORD *)v33 - 2);
          *(v33 - 2) = *v32;
          *(_DWORD *)v32 = v35;
          v36 = *((_DWORD *)v33 - 1);
          *(v33 - 1) = v32[1];
          *((_DWORD *)v32 + 1) = v36;
          v37 = *v33;
          *v33 = v32[2];
          v32[2] = v37;
          v38 = *((_DWORD *)v33 + 1);
          v33[1] = v32[3];
          *((_DWORD *)v32 + 3) = v38;
          v33 += 4;
          v32 += 4;
          --v34;
        }
        while ( v34 != 0 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009CE00
// Name: public: void IVP_Incr_L_U_Matrix::exchange_columns_L(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Incr_L_U_Matrix::exchange_columns_L(IVP_Incr_L_U_Matrix *this, int col0, int col1)
{
  int i; // edx
  float *L_matrix; // esi
  int v5; // eax
  float v6; // xmm0_4
  int v7; // eax

  for ( i = 0; i < this->n_sub; this->L_matrix[v7] = v6 )
  {
    L_matrix = this->L_matrix;
    v5 = i * this->aligned_row_len;
    v6 = L_matrix[v5 + col0];
    L_matrix[v5 + col0] = L_matrix[col1 + v5];
    v7 = col1 + i * this->aligned_row_len;
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009CE50
// Name: public: void IVP_Incr_L_U_Matrix::exchange_columns_U(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Incr_L_U_Matrix::exchange_columns_U(IVP_Incr_L_U_Matrix *this, int col0, int col1)
{
  int i; // edx
  float *U_matrix; // esi
  int v5; // eax
  float v6; // xmm0_4
  int v7; // eax

  for ( i = 0; i < this->n_sub; this->U_matrix[v7] = v6 )
  {
    U_matrix = this->U_matrix;
    v5 = i * this->aligned_row_len;
    v6 = U_matrix[v5 + col0];
    U_matrix[v5 + col0] = U_matrix[col1 + v5];
    v7 = col1 + i * this->aligned_row_len;
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009CEA0
// Name: public: void IVP_Incr_L_U_Matrix::mult_vec_with_L(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Incr_L_U_Matrix::mult_vec_with_L(IVP_Incr_L_U_Matrix *this)
{
  IVP_Incr_L_U_Matrix *v1; // esi
  int v2; // eax
  float *mult_vec; // ecx
  int v4; // ebx
  int v5; // edx
  float v6; // xmm0_4
  float *v7; // esi
  float *v8; // eax
  unsigned int v9; // edi
  int v10; // ebx
  float v11; // xmm2_4
  float v12; // xmm0_4
  float *v13; // eax
  int v14; // ebx
  float v15; // xmm2_4
  int v17; // [esp+8h] [ebp-Ch]
  int i; // [esp+10h] [ebp-4h]

  v1 = this;
  v2 = this->n_sub - 1;
  for ( i = v2; v2 >= 0; i = v2 )
  {
    mult_vec = v1->mult_vec;
    v4 = (int)&v1->L_matrix[v2 * v1->aligned_row_len];
    v5 = v1->n_sub - 1;
    v17 = v4;
    v6 = 0.0;
    if ( v5 >= 0 )
    {
      if ( v1->n_sub >= 4 )
      {
        v7 = (float *)(v4 + 4 * v5 - 12);
        v8 = &mult_vec[v5 - 1];
        v9 = (unsigned int)(v5 + 1) >> 2;
        v10 = v4 - (_DWORD)mult_vec;
        v5 -= 4 * v9;
        do
        {
          v11 = (float)((float)((float)(v8[1] * v7[3]) + v6) + (float)(*(float *)((char *)v8 + v10) * *v8))
              + (float)(*(v8 - 1) * v7[1]);
          v12 = *(v8 - 2) * *v7;
          v8 -= 4;
          v7 -= 4;
          --v9;
          v6 = v12 + v11;
        }
        while ( v9 != 0 );
        v4 = v17;
        v1 = this;
        v2 = i;
      }
      if ( v5 >= 0 )
      {
        v13 = &mult_vec[v5];
        v14 = v4 - (_DWORD)mult_vec;
        do
        {
          v15 = *(float *)((char *)v13 + v14) * *v13;
          --v13;
          --v5;
          v6 = v6 + v15;
        }
        while ( v5 >= 0 );
        v2 = i;
      }
    }
    v1->temp_vec[v2--] = v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009CF90
// Name: public: void IVP_Incr_L_U_Matrix::solve_vec_with_U(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Incr_L_U_Matrix::solve_vec_with_U(IVP_Incr_L_U_Matrix *this)
{
  int v1; // ebx
  int v2; // eax
  float v3; // xmm0_4
  float *v4; // esi
  float *v5; // edi
  unsigned int v6; // edx
  float v7; // xmm1_4
  float v8; // xmm0_4
  float *v9; // esi
  float *v10; // edx
  int v11; // eax
  float v12; // xmm1_4
  float *temp_vec; // eax
  float v14; // xmm1_4
  float *v15; // eax
  float v16; // xmm1_4
  IVP_Incr_L_U_Matrix *v17; // [esp+4h] [ebp-8h]
  int v18; // [esp+8h] [ebp-4h]

  v1 = this->n_sub - 1;
  v17 = this;
  if ( v1 >= 0 )
  {
    v18 = v1 + 3;
    do
    {
      v2 = this->n_sub - 1;
      v3 = 0.0;
      if ( v2 > v1 )
      {
        if ( v2 - v1 >= 4 )
        {
          v4 = &this->temp_vec[v2 - 2];
          v5 = &this->U_matrix[v2 - 2 + v1 * this->aligned_row_len];
          v6 = ((unsigned int)(v2 - v18 - 1) >> 2) + 1;
          v2 -= 4 * v6;
          do
          {
            v7 = (float)((float)((float)(v5[2] * v4[2]) + v3) + (float)(v5[1] * v4[1])) + (float)(*v5 * *v4);
            v8 = *(v5 - 1) * *(v4 - 1);
            v4 -= 4;
            v5 -= 4;
            --v6;
            v3 = v8 + v7;
          }
          while ( v6 != 0 );
          this = v17;
        }
        if ( v2 > v1 )
        {
          v9 = &this->temp_vec[v2];
          v10 = &this->U_matrix[v2 + v1 * this->aligned_row_len];
          v11 = v2 - v1;
          do
          {
            v12 = *v10-- * *v9--;
            --v11;
            v3 = v3 + v12;
          }
          while ( v11 != 0 );
        }
      }
      temp_vec = this->temp_vec;
      v14 = temp_vec[v1];
      --v18;
      v15 = &temp_vec[v1--];
      v16 = v14 - v3;
      *v15 = v16;
      this->out_vec[v1 + 1] = v16;
    }
    while ( v1 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D0A0
// Name: public: void IVP_Incr_L_U_Matrix::solve_lin_equ(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Incr_L_U_Matrix::solve_lin_equ(IVP_Incr_L_U_Matrix *this)
{
  int v2; // eax

  v2 = this->n_sub - 1;
  if ( v2 >= 0 )
  {
    if ( this->n_sub >= 4 )
    {
      do
      {
        this->mult_vec[v2] = this->input_vec[v2];
        this->mult_vec[v2 - 1] = this->input_vec[v2 - 1];
        this->mult_vec[v2 - 2] = this->input_vec[v2 - 2];
        this->mult_vec[v2 - 3] = this->input_vec[v2 - 3];
        v2 -= 4;
      }
      while ( v2 >= 3 );
    }
    for ( ; v2 >= 0; this->mult_vec[v2 + 1] = this->input_vec[v2 + 1] )
      --v2;
  }
  IVP_Incr_L_U_Matrix::mult_vec_with_L(this);
  IVP_Incr_L_U_Matrix::solve_vec_with_U(this);
}

//------------------------------------------------------------------------------
// Address: 0x1009D120
// Name: public: void IVP_Great_Matrix_Many_Zero::find_pivot_in_column(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Great_Matrix_Many_Zero::find_pivot_in_column(IVP_Great_Matrix_Many_Zero *this, int col)
{
  float *matrix_values; // ebx
  int aligned_row_len; // esi
  int v5; // eax
  float v6; // xmm0_4
  int v7; // edx
  float v8; // xmm1_4
  float v9; // xmm1_4
  float v10; // xmm1_4
  float v11; // xmm1_4
  int v12; // edx
  float *v13; // esi
  float v14; // xmm1_4
  float *v15; // [esp+4h] [ebp-10h]
  float *v16; // [esp+8h] [ebp-Ch]
  float *v17; // [esp+Ch] [ebp-8h]
  float *v18; // [esp+10h] [ebp-4h]
  int pos; // [esp+1Ch] [ebp+8h]

  matrix_values = this->matrix_values;
  aligned_row_len = this->aligned_row_len;
  v5 = this->columns - 1;
  v6 = fabs(matrix_values[col * (aligned_row_len + 1)]);
  pos = -1;
  if ( v5 > col )
  {
    if ( v5 - col >= 4 )
    {
      v18 = &matrix_values[col + v5 * aligned_row_len];
      v15 = &matrix_values[col + aligned_row_len * (this->columns - 4)];
      v16 = &matrix_values[col + aligned_row_len * (this->columns - 3)];
      v7 = -16 * aligned_row_len;
      v17 = (float *)((char *)&matrix_values[col] + aligned_row_len * (4 * v5 - 4));
      do
      {
        v8 = fabs(*v18);
        if ( v8 > v6 )
        {
          v6 = v8;
          pos = v5;
        }
        v9 = fabs(*v17);
        if ( v9 > v6 )
        {
          v6 = v9;
          pos = v5 - 1;
        }
        v10 = fabs(*v16);
        if ( v10 > v6 )
        {
          v6 = v10;
          pos = v5 - 2;
        }
        v11 = fabs(*v15);
        if ( v11 > v6 )
        {
          v6 = v11;
          pos = v5 - 3;
        }
        v18 = (float *)((char *)v18 + v7);
        v17 = (float *)((char *)v17 + v7);
        v16 = (float *)((char *)v16 + v7);
        v15 = (float *)((char *)v15 + v7);
        v5 -= 4;
      }
      while ( v5 > col + 3 );
    }
    if ( v5 > col )
    {
      v12 = -4 * aligned_row_len;
      v13 = &matrix_values[col + v5 * aligned_row_len];
      do
      {
        v14 = fabs(*v13);
        if ( v14 > v6 )
        {
          v6 = v14;
          pos = v5;
        }
        --v5;
        v13 = (float *)((char *)v13 + v12);
      }
      while ( v5 > col );
    }
    if ( pos >= 0 )
      IVP_Great_Matrix_Many_Zero::exchange_rows(this, a: col, b: pos);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D270
// Name: public: void IVP_Great_Matrix_Many_Zero::transform_to_lower_null_triangle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Great_Matrix_Many_Zero::transform_to_lower_null_triangle(IVP_Great_Matrix_Many_Zero *this)
{
  int j; // edi
  float v3; // xmm0_4
  int v4; // ebx
  float v5; // xmm4_4
  float v6; // xmm3_4
  int aligned_row_len; // eax
  signed int v8; // ecx
  unsigned int v9; // edx
  int v10; // ecx
  float *v11; // eax
  float v12; // xmm3_4
  float *v13; // edx
  unsigned int v14; // ecx
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  int i; // [esp+8h] [ebp-4h]

  for ( j = 0; j < this->columns; ++j )
  {
    IVP_Great_Matrix_Many_Zero::find_pivot_in_column(this, col: j);
    v3 = this->matrix_values[j * (this->aligned_row_len + 1)];
    if ( this->MATRIX_EPS <= fabs(v3) )
    {
      v4 = j + 1;
      v5 = -1.0 / v3;
      for ( i = j + 1; v4 < this->columns; i = v4 )
      {
        v6 = this->matrix_values[j + v4 * this->aligned_row_len];
        if ( fabs(v6) > this->MATRIX_EPS )
        {
          aligned_row_len = this->aligned_row_len;
          v8 = (signed int)&this->matrix_values[j * (aligned_row_len + 1)];
          v9 = v8 & 0xFFFFFFF0;
          v10 = this->columns + ((int)(v8 - (v8 & 0xFFFFFFF0)) >> 2) - j;
          v11 = (float *)((int)&this->matrix_values[j + v4 * aligned_row_len] & 0xFFFFFFF0);
          v12 = v6 * v5;
          if ( v10 > 0 )
          {
            v13 = (float *)(v9 + 8);
            v14 = ((unsigned int)(v10 - 1) >> 2) + 1;
            do
            {
              v15 = (float)(*(v13 - 1) * v12) + v11[1];
              v16 = (float)(*v13 * v12) + v11[2];
              v17 = (float)(v13[1] * v12) + v11[3];
              *v11 = (float)(*(v13 - 2) * v12) + *v11;
              v11[1] = v15;
              v11[2] = v16;
              v11[3] = v17;
              v11 += 4;
              v13 += 4;
              --v14;
            }
            while ( v14 != 0 );
          }
          v4 = i;
          this->desired_vector[i] = (float)(this->desired_vector[j] * v12) + this->desired_vector[i];
        }
        ++v4;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D3C0
// Name: private: void IVP_Linear_Constraint_Solver::do_a_little_random_permutation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Linear_Constraint_Solver::do_a_little_random_permutation(IVP_Linear_Constraint_Solver *this)
{
  int r_actives; // eax
  int second_permute_index; // edx
  int i; // esi
  int *actives_inactives_ignored; // esi
  int v5; // eax
  int v6; // edi
  int first_permute_index; // edx
  int v8; // ebx
  int ignored_pos; // edx
  int n_variables; // eax
  int first_permute_ignored; // esi
  int second_permute_ignored; // edi
  int v13; // eax
  int v14; // esi
  int v15; // eax
  int v16; // edx
  int *v17; // esi
  int v18; // edi
  int v19; // ebx

  r_actives = this->r_actives;
  if ( r_actives >= 2 )
  {
    ++this->first_permute_index;
    this->second_permute_index += 2;
    second_permute_index = this->second_permute_index;
    for ( i = this->first_permute_index; i >= r_actives; this->first_permute_index = i )
      i -= r_actives;
    for ( ; second_permute_index >= r_actives; this->second_permute_index = second_permute_index )
      second_permute_index -= r_actives;
    actives_inactives_ignored = this->actives_inactives_ignored;
    v5 = this->second_permute_index;
    v6 = actives_inactives_ignored[v5];
    first_permute_index = this->first_permute_index;
    v8 = actives_inactives_ignored[first_permute_index];
    actives_inactives_ignored[first_permute_index] = v6;
    this->actives_inactives_ignored[v5] = v8;
    this->variable_is_found_at[v6] = first_permute_index;
    this->variable_is_found_at[v8] = v5;
    ignored_pos = this->ignored_pos;
    n_variables = this->n_variables;
    ++this->first_permute_ignored;
    this->second_permute_ignored += 2;
    first_permute_ignored = this->first_permute_ignored;
    second_permute_ignored = this->second_permute_ignored;
    v13 = n_variables - ignored_pos - 1;
    if ( v13 >= 2 )
    {
      if ( first_permute_ignored >= v13 )
      {
        do
          first_permute_ignored -= v13;
        while ( first_permute_ignored >= v13 );
        this->first_permute_ignored = first_permute_ignored;
      }
      if ( second_permute_ignored >= v13 )
      {
        v14 = second_permute_ignored;
        do
          v14 -= v13;
        while ( v14 >= v13 );
        this->second_permute_ignored = v14;
      }
      v15 = ignored_pos + this->second_permute_ignored + 1;
      v16 = ignored_pos + this->first_permute_ignored + 1;
      v17 = this->actives_inactives_ignored;
      v18 = v17[v15];
      v19 = v17[v16];
      v17[v16] = v18;
      this->actives_inactives_ignored[v15] = v19;
      this->variable_is_found_at[v18] = v16;
      this->variable_is_found_at[v19] = v15;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009D490
// Name: private: enum IVP_RETURN_TYPE IVP_Linear_Constraint_Solver::setup_l_u_solver(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_Linear_Constraint_Solver::setup_l_u_solver(IVP_Linear_Constraint_Solver *this)
{
  int i; // edx
  int v2; // eax
  float *v3; // esi
  float *v4; // edi
  int j; // eax
  int v6; // ebx
  int n_sub; // ebx
  IVP_Incr_L_U_Matrix *p_lu_sub_solver; // esi
  int k; // ebx
  signed int v11; // edx
  int v12; // eax
  int v13; // edi
  int v14; // ecx
  int v15; // ebx
  float v16; // xmm0_4
  int aligned_row_len; // edi
  int v18; // eax
  int v19; // edi
  int v20; // ecx
  unsigned int v21; // edx
  int v22; // ecx
  float *v23; // eax
  float v24; // xmm0_4
  float *v25; // edx
  unsigned int v26; // ecx
  float v27; // xmm1_4
  float v28; // xmm2_4
  float v29; // xmm3_4
  float *L_matrix; // eax
  float *v31; // ecx
  unsigned int v32; // edx
  int v33; // ecx
  float *v34; // eax
  float *v35; // edx
  unsigned int v36; // ecx
  float v37; // xmm1_4
  float v38; // xmm2_4
  float v39; // xmm3_4
  int v40; // [esp+Ch] [ebp-10h]
  int v41; // [esp+10h] [ebp-Ch]
  int m; // [esp+14h] [ebp-8h]
  int v43; // [esp+18h] [ebp-4h]

  for ( i = 0; i < this->r_actives; ++i )
  {
    v2 = this->actives_inactives_ignored[i];
    this->lu_sub_solver.input_vec[i] = this->full_b[v2];
    v3 = &this->full_A[v2 * this->aligned_size];
    v4 = &this->lu_sub_solver.U_matrix[i * this->lu_sub_solver.aligned_row_len];
    for ( j = 0; j < this->r_actives; v4[j - 1] = v3[v6] )
      v6 = this->actives_inactives_ignored[j++];
  }
  n_sub = this->lu_sub_solver.n_sub;
  p_lu_sub_solver = &this->lu_sub_solver;
  if ( n_sub == 0 )
    return 1;
  for ( k = n_sub - 1; k >= 0; *(_DWORD *)(v11 + 4 * k + 4) = 1065353216 )
  {
    v11 = (signed int)&this->lu_sub_solver.L_matrix[k * this->lu_sub_solver.aligned_row_len];
    v12 = ((int)(v11 - (v11 & 0xFFFFFFF0)) >> 2) + this->lu_sub_solver.n_sub - 1;
    if ( v12 >= 0 )
      memset((void *)(v11 & 0xFFFFFFF0), 0, 4 * ((v12 + 4) & 0x3FFFFFFC));
    --k;
  }
  v13 = 1;
  v43 = 1;
  if ( this->lu_sub_solver.n_sub <= 1 )
    return IVP_Incr_L_U_Matrix::normize_row(this: p_lu_sub_solver, row_nr: p_lu_sub_solver->n_sub - 1) != 0;
  while ( 1 )
  {
    IVP_Incr_L_U_Matrix::pivot_search_l_u(this: p_lu_sub_solver, col_nr: v13 - 1);
    if ( IVP_Incr_L_U_Matrix::normize_row(this: p_lu_sub_solver, row_nr: v13 - 1) == 0 )
      break;
    v14 = p_lu_sub_solver->n_sub - 1;
    for ( m = v14; v14 >= v13; m = v14 )
    {
      v15 = v13 - 1;
      v16 = p_lu_sub_solver->U_matrix[v13 - 1 + v14 * p_lu_sub_solver->aligned_row_len];
      if ( v16 != 0.0 )
      {
        aligned_row_len = p_lu_sub_solver->aligned_row_len;
        v18 = v14 * aligned_row_len;
        v19 = v15 * aligned_row_len;
        v41 = v18;
        v20 = (int)&p_lu_sub_solver->U_matrix[v19 + 1 + v15];
        v21 = v20 & 0xFFFFFFF0;
        v40 = v15 + v18;
        v22 = ((int)(v20 - (v20 & 0xFFFFFFF0)) >> 2) - v43 + p_lu_sub_solver->n_sub;
        v23 = (float *)((int)&p_lu_sub_solver->U_matrix[v40 + 1] & 0xFFFFFFF0);
        v24 = -v16;
        if ( v22 > 0 )
        {
          v25 = (float *)(v21 + 8);
          v26 = ((unsigned int)(v22 - 1) >> 2) + 1;
          do
          {
            v27 = (float)(v24 * *v25) + v23[2];
            v28 = (float)(*(v25 - 1) * v24) + v23[1];
            v29 = (float)(v25[1] * v24) + v23[3];
            *v23 = (float)(*(v25 - 2) * v24) + *v23;
            v23[1] = v28;
            v23[2] = v27;
            v23[3] = v29;
            v23 += 4;
            v25 += 4;
            --v26;
          }
          while ( v26 != 0 );
        }
        L_matrix = p_lu_sub_solver->L_matrix;
        v31 = &L_matrix[v19];
        v32 = (unsigned int)v31 & 0xFFFFFFF0;
        v33 = p_lu_sub_solver->n_sub + ((int)((int)v31 - ((unsigned int)v31 & 0xFFFFFFF0)) >> 2);
        v34 = (float *)((unsigned int)&L_matrix[v41] & 0xFFFFFFF0);
        if ( v33 > 0 )
        {
          v35 = (float *)(v32 + 8);
          v36 = ((unsigned int)(v33 - 1) >> 2) + 1;
          do
          {
            v37 = (float)(v24 * *v35) + v34[2];
            v38 = (float)(*(v35 - 1) * v24) + v34[1];
            v39 = (float)(v35[1] * v24) + v34[3];
            *v34 = (float)(*(v35 - 2) * v24) + *v34;
            v34[1] = v38;
            v34[2] = v37;
            v34[3] = v39;
            v34 += 4;
            v35 += 4;
            --v36;
          }
          while ( v36 != 0 );
        }
        v13 = v43;
        p_lu_sub_solver->U_matrix[v40] = 0.0;
        v14 = m;
      }
      --v14;
    }
    v43 = ++v13;
    if ( v13 >= p_lu_sub_solver->n_sub )
      return IVP_Incr_L_U_Matrix::normize_row(this: p_lu_sub_solver, row_nr: p_lu_sub_solver->n_sub - 1) != 0;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1009D730
// Name: public: enum IVP_RETURN_TYPE IVP_Great_Matrix_Many_Zero::lu_inverse(class IVP_Great_Matrix_Many_Zero __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_Great_Matrix_Many_Zero::lu_inverse(
        IVP_Great_Matrix_Many_Zero *this,
        IVP_Great_Matrix_Many_Zero *matrix_out,
        int *index_vec)
{
  int columns; // edx
  int v4; // edi
  int v5; // eax
  int v6; // esi
  int v7; // ebx
  int v8; // eax
  float *matrix_values; // edx
  int v10; // edx
  int v11; // edi
  float *desired_vector; // eax
  float v13; // xmm0_4
  int v14; // eax
  float *v15; // esi
  float *v16; // edi
  unsigned int v17; // edx
  float v18; // xmm0_4
  float v19; // xmm4_4
  float *v20; // edi
  float *v21; // esi
  int v22; // edx
  float v23; // xmm4_4
  bool v24; // zf
  int v25; // edx
  int v26; // edi
  int v27; // ebx
  float *v28; // esi
  float v29; // xmm0_4
  float *v30; // edi
  unsigned int v31; // eax
  float *v32; // esi
  float v33; // xmm0_4
  float v34; // xmm4_4
  int v35; // eax
  float v36; // xmm4_4
  int v37; // edx
  int v38; // eax
  float *v39; // esi
  double v40; // st7
  int v41; // edx
  int v43; // [esp+Ch] [ebp-24h]
  int v44; // [esp+14h] [ebp-1Ch]
  float *v45; // [esp+14h] [ebp-1Ch]
  int i; // [esp+18h] [ebp-18h]
  int v47; // [esp+1Ch] [ebp-14h]
  int v48; // [esp+1Ch] [ebp-14h]
  int v49; // [esp+20h] [ebp-10h]
  int v50; // [esp+20h] [ebp-10h]
  int v51; // [esp+24h] [ebp-Ch]
  int v52; // [esp+24h] [ebp-Ch]
  float *v53; // [esp+24h] [ebp-Ch]
  int v54; // [esp+28h] [ebp-8h]
  int v55; // [esp+28h] [ebp-8h]
  int v56; // [esp+2Ch] [ebp-4h]

  columns = this->columns;
  v4 = 0;
  for ( i = 0; v4 < columns; i = v4 )
  {
    v5 = 0;
    if ( columns > 0 )
    {
      do
        this->desired_vector[v5++] = 0.0;
      while ( v5 < this->columns );
    }
    this->desired_vector[v4] = 1.0;
    v6 = this->columns;
    v7 = -1;
    v8 = 0;
    v47 = -1;
    v56 = v6;
    if ( v6 > 0 )
    {
      matrix_values = this->matrix_values;
      do
      {
        if ( this->MATRIX_EPS > fabs(*matrix_values) )
          return 0;
        ++v8;
        matrix_values += v6 + 1;
      }
      while ( v8 < v6 );
      v10 = 0;
      v51 = 0;
      v54 = 0;
      v49 = this->columns;
      do
      {
        v11 = *(int *)((char *)index_vec + v10);
        desired_vector = this->desired_vector;
        v13 = desired_vector[v11];
        desired_vector[v11] = *(float *)((char *)desired_vector + v10);
        if ( v47 < 0 )
        {
          if ( v13 != 0.0 )
            v47 = v7 + 2;
        }
        else
        {
          v14 = v47 - 1;
          if ( v47 - 1 <= v7 )
          {
            if ( v7 - v14 + 1 >= 4 )
            {
              v15 = &this->desired_vector[v14 + 2];
              v16 = &this->matrix_values[v14 + 2 + v54];
              v17 = ((unsigned int)(v7 - v14 - 3) >> 2) + 1;
              v14 += 4 * v17;
              do
              {
                v18 = (float)((float)(v13 - (float)(*(v16 - 2) * *(v15 - 2))) - (float)(*(v16 - 1) * *(v15 - 1)))
                    - (float)(*v16 * *v15);
                v19 = v16[1] * v15[1];
                v15 += 4;
                v16 += 4;
                --v17;
                v13 = v18 - v19;
              }
              while ( v17 != 0 );
              v6 = v56;
              v10 = v51;
            }
            if ( v14 <= v7 )
            {
              v20 = &this->desired_vector[v14];
              v21 = &this->matrix_values[v14 + v54];
              v22 = v7 - v14 + 1;
              do
              {
                v23 = *v21++ * *v20++;
                --v22;
                v13 = v13 - v23;
              }
              while ( v22 != 0 );
              v6 = v56;
              v10 = v51;
            }
          }
        }
        v54 += v6;
        *(float *)((char *)this->desired_vector + v10) = v13;
        v10 += 4;
        ++v7;
        v24 = v49-- == 1;
        v51 = v10;
      }
      while ( !v24 );
    }
    v25 = v6 - 1;
    if ( v6 - 1 >= 0 )
    {
      v48 = v25 * (4 * v6 + 4);
      v26 = v6 * v25;
      v43 = -4 - 4 * v6;
      v27 = v6;
      v52 = v6 * v25;
      v44 = v6;
      v50 = v56 - v6;
      do
      {
        v28 = this->desired_vector;
        v29 = v28[v25];
        v55 = v27;
        if ( v27 < v56 )
        {
          if ( v50 >= 4 )
          {
            v30 = &this->matrix_values[v27 + 2 + v26];
            v31 = ((unsigned int)(v56 - v27 - 4) >> 2) + 1;
            v32 = &v28[v25 + 3];
            v55 = v27 + 4 * v31;
            do
            {
              v33 = (float)((float)(v29 - (float)(*(v30 - 2) * *(v32 - 2))) - (float)(*(v30 - 1) * *(v32 - 1)))
                  - (float)(*v30 * *v32);
              v34 = v30[1] * v32[1];
              v32 += 4;
              v30 += 4;
              --v31;
              v29 = v33 - v34;
            }
            while ( v31 != 0 );
            v26 = v52;
            v27 = v44;
          }
          if ( v55 < v56 )
          {
            v53 = &this->desired_vector[v55];
            v45 = &this->matrix_values[v26 + v55];
            v35 = v56 - v55;
            do
            {
              v36 = *v53++ * *v45;
              --v35;
              v29 = v29 - v36;
              ++v45;
            }
            while ( v35 != 0 );
          }
        }
        v26 -= v56;
        ++v50;
        this->desired_vector[v25] = v29 / *(float *)((char *)this->matrix_values + v48);
        this->result_vector[v25] = this->desired_vector[v25];
        v48 += v43;
        --v27;
        --v25;
        v44 = v27;
        v52 = v26;
      }
      while ( v25 >= 0 );
    }
    v37 = this->columns;
    v38 = 0;
    if ( v37 > 0 )
    {
      v39 = matrix_out->matrix_values;
      do
      {
        v40 = this->result_vector[v38];
        v41 = i + v38 * v37;
        ++v38;
        v39[v41] = v40;
        v37 = this->columns;
      }
      while ( v38 < v37 );
    }
    columns = this->columns;
    v4 = i + 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1009DA70
// Name: public: enum IVP_RETURN_TYPE IVP_Great_Matrix_Many_Zero::invert(class IVP_Great_Matrix_Many_Zero __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_RETURN_TYPE __thiscall IVP_Great_Matrix_Many_Zero::invert(
        IVP_Great_Matrix_Many_Zero *this,
        IVP_Great_Matrix_Many_Zero *dest)
{
  void *v3; // esp
  IVP_RETURN_TYPE result; // eax
  int v5[2]; // [esp+0h] [ebp-Ch] BYREF
  float sign; // [esp+8h] [ebp-4h] BYREF

  v3 = alloca(4 * this->columns);
  sign = 0.0;
  result = IVP_Great_Matrix_Many_Zero::lu_crout(this, index_vec: v5, &sign);
  if ( result != IVP_FAULT )
    return IVP_Great_Matrix_Many_Zero::lu_inverse(this, matrix_out: dest, index_vec: v5);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009DAC0
// Name: public: enum IVP_RETURN_TYPE IVP_Incr_L_U_Matrix::decrement_l_u(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_Incr_L_U_Matrix::decrement_l_u(IVP_Incr_L_U_Matrix *this, int del_nr)
{
  int v3; // edi
  int v4; // ecx
  int v5; // ebx
  float v6; // xmm3_4
  int n_sub; // edi
  float *L_matrix; // eax
  unsigned int v9; // edx
  int v10; // ecx
  float *v11; // eax
  float v12; // xmm3_4
  float *v13; // edx
  unsigned int v14; // ecx
  float v15; // xmm0_4
  float v16; // xmm1_4
  float v17; // xmm2_4
  int v18; // edx
  int aligned_row_len; // edx
  float *v20; // eax
  signed int v21; // ecx
  unsigned int v22; // ebx
  int v23; // ecx
  float *v24; // eax
  float *v25; // edx
  unsigned int v26; // ecx
  float v27; // xmm0_4
  float v28; // xmm1_4
  float v29; // xmm2_4
  int v30; // ecx
  float *U_matrix; // edx
  int v32; // ebx
  float v33; // xmm0_4
  int v34; // ecx
  int v35; // ebx
  float *v36; // eax
  float v37; // xmm0_4
  float *v38; // ecx
  unsigned int v39; // edx
  float v40; // xmm1_4
  float v41; // xmm2_4
  float v42; // xmm3_4
  float *v43; // eax
  unsigned int v44; // edx
  int v45; // ecx
  float *v46; // eax
  float *v47; // edx
  unsigned int v48; // ecx
  float v49; // xmm1_4
  float v50; // xmm2_4
  float v51; // xmm3_4
  int v52; // edi
  int v53; // ebx
  signed int v54; // edx
  int v55; // ecx
  float v56; // xmm0_4
  float *v57; // eax
  unsigned int v58; // ecx
  int v59; // ebx
  int v60; // eax
  float *v62; // edi
  int v63; // edx
  float v64; // xmm3_4
  signed int v65; // ecx
  int v66; // eax
  unsigned int v67; // edx
  int v68; // ecx
  float *v69; // eax
  float v70; // xmm3_4
  float *v71; // edx
  unsigned int v72; // ecx
  float v73; // xmm0_4
  float v74; // xmm1_4
  float v75; // xmm2_4
  int v76; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]
  int ia; // [esp+10h] [ebp-4h]
  int ib; // [esp+10h] [ebp-4h]
  int del_nra; // [esp+1Ch] [ebp+8h]
  int del_nrb; // [esp+1Ch] [ebp+8h]

  v3 = del_nr;
  IVP_Incr_L_U_Matrix::exchange_columns_L(this, col0: del_nr, col1: this->n_sub - 1);
  IVP_Incr_L_U_Matrix::exchange_columns_U(this, col0: del_nr, col1: this->n_sub - 1);
  v4 = this->n_sub - 2;
  i = v4;
  if ( v4 > del_nr )
  {
    do
    {
      v5 = v4 * this->aligned_row_len;
      v6 = this->U_matrix[v5 + v3];
      if ( v6 != 0.0 )
      {
        n_sub = this->n_sub;
        L_matrix = this->L_matrix;
        v9 = (unsigned int)&L_matrix[this->aligned_row_len * (n_sub - 1)] & 0xFFFFFFF0;
        v10 = n_sub + ((int)((int)&L_matrix[this->aligned_row_len * (n_sub - 1)] - v9) >> 2);
        v11 = (float *)((unsigned int)&L_matrix[v5] & 0xFFFFFFF0);
        v12 = -v6;
        if ( v10 > 0 )
        {
          v13 = (float *)(v9 + 8);
          v14 = ((unsigned int)(v10 - 1) >> 2) + 1;
          do
          {
            v15 = (float)(*(v13 - 1) * v12) + v11[1];
            v16 = (float)(*v13 * v12) + v11[2];
            v17 = (float)(v13[1] * v12) + v11[3];
            *v11 = (float)(*(v13 - 2) * v12) + *v11;
            v11[1] = v15;
            v11[2] = v16;
            v11[3] = v17;
            v11 += 4;
            v13 += 4;
            --v14;
          }
          while ( v14 != 0 );
        }
        v4 = i;
        v3 = del_nr;
      }
      v18 = v4 * this->aligned_row_len;
      --v4;
      this->U_matrix[v3 + v18] = 0.0;
      i = v4;
    }
    while ( v4 > v3 );
  }
  if ( IVP_Incr_L_U_Matrix::normize_row(this, row_nr: v3) != 1 )
  {
    aligned_row_len = this->aligned_row_len;
    v20 = this->L_matrix;
    v21 = (signed int)&v20[aligned_row_len * (this->n_sub - 1)];
    v22 = v21 & 0xFFFFFFF0;
    v23 = this->n_sub + ((int)(v21 - (v21 & 0xFFFFFFF0)) >> 2);
    v24 = (float *)((unsigned int)&v20[v3 * aligned_row_len] & 0xFFFFFFF0);
    if ( v23 > 0 )
    {
      v25 = (float *)(v22 + 8);
      v26 = ((unsigned int)(v23 - 1) >> 2) + 1;
      do
      {
        v27 = *(v25 - 1) + v24[1];
        v28 = *v25 + v24[2];
        v29 = v25[1] + v24[3];
        *v24 = *(v25 - 2) + *v24;
        v24[1] = v27;
        v24[2] = v28;
        v24[3] = v29;
        v24 += 4;
        v25 += 4;
        --v26;
      }
      while ( v26 != 0 );
    }
    this->U_matrix[v3 * (this->aligned_row_len + 1)] = 1.0;
  }
  if ( del_nr < this->n_sub - 1 )
  {
    do
    {
      v30 = this->aligned_row_len;
      U_matrix = this->U_matrix;
      v32 = v30 * (this->n_sub - 1);
      v33 = U_matrix[v32 + v3];
      ia = v32;
      if ( v33 != 0.0 )
      {
        del_nra = v3 * v30;
        v34 = (int)&U_matrix[v3 + 1 + v3 * v30];
        v76 = v32 + v3;
        v35 = ((int)(v34 - (v34 & 0xFFFFFFF0)) >> 2) - v3 + this->n_sub - 1;
        v36 = (float *)((int)&this->U_matrix[v76 + 1] & 0xFFFFFFF0);
        v37 = -v33;
        if ( v35 > 0 )
        {
          v38 = (float *)((v34 & 0xFFFFFFF0) + 8);
          v39 = ((unsigned int)(v35 - 1) >> 2) + 1;
          do
          {
            v40 = (float)(v37 * *v38) + v36[2];
            v41 = (float)(*(v38 - 1) * v37) + v36[1];
            v42 = (float)(v38[1] * v37) + v36[3];
            *v36 = (float)(*(v38 - 2) * v37) + *v36;
            v36[1] = v41;
            v36[2] = v40;
            v36[3] = v42;
            v36 += 4;
            v38 += 4;
            --v39;
          }
          while ( v39 != 0 );
        }
        v43 = this->L_matrix;
        v44 = (unsigned int)&v43[del_nra] & 0xFFFFFFF0;
        v45 = this->n_sub + ((int)((int)&v43[del_nra] - v44) >> 2);
        v46 = (float *)((unsigned int)&v43[ia] & 0xFFFFFFF0);
        if ( v45 > 0 )
        {
          v47 = (float *)(v44 + 8);
          v48 = ((unsigned int)(v45 - 1) >> 2) + 1;
          do
          {
            v49 = (float)(v37 * *v47) + v46[2];
            v50 = (float)(*(v47 - 1) * v37) + v46[1];
            v51 = (float)(v47[1] * v37) + v46[3];
            *v46 = (float)(*(v47 - 2) * v37) + *v46;
            v46[1] = v50;
            v46[2] = v49;
            v46[3] = v51;
            v46 += 4;
            v47 += 4;
            --v48;
          }
          while ( v48 != 0 );
        }
        this->U_matrix[v76] = 0.0;
      }
      ++v3;
    }
    while ( v3 < this->n_sub - 1 );
  }
  v52 = this->n_sub;
  v53 = v52 - 1;
  v54 = (signed int)&this->L_matrix[(v52 - 1) * this->aligned_row_len];
  if ( this->MATRIX_EPS > COERCE_FLOAT(*(_DWORD *)(v54 + 4 * (v52 - 1)) & _mask__AbsFloat_) )
  {
    this->n_sub = v53;
    return 0;
  }
  else
  {
    v55 = v52 + ((int)(v54 - (v54 & 0xFFFFFFF0)) >> 2);
    v56 = 1.0 / *(float *)(v54 + 4 * (v52 - 1));
    if ( v55 > 0 )
    {
      v57 = (float *)((v54 & 0xFFFFFFF0) + 8);
      v58 = ((unsigned int)(v55 - 1) >> 2) + 1;
      do
      {
        *(v57 - 2) = *(v57 - 2) * v56;
        *(v57 - 1) = v56 * *(v57 - 1);
        *v57 = *v57 * v56;
        v57[1] = v57[1] * v56;
        v57 += 4;
        --v58;
      }
      while ( v58 != 0 );
    }
    *(_DWORD *)(v54 + 4 * v53) = 1065353216;
    v59 = this->n_sub - 1;
    v60 = this->n_sub - 2;
    ib = v60;
    if ( v60 >= 0 )
    {
      while ( 1 )
      {
        v62 = this->L_matrix;
        v63 = v60 * this->aligned_row_len;
        v64 = v62[v63 + v59];
        if ( v64 != 0.0 )
        {
          v65 = (signed int)&v62[v59 * this->aligned_row_len];
          v66 = (int)&v62[v63];
          v67 = v65 & 0xFFFFFFF0;
          v68 = this->n_sub + ((int)(v65 - (v65 & 0xFFFFFFF0)) >> 2);
          del_nrb = v66;
          v69 = (float *)(v66 & 0xFFFFFFF0);
          v70 = -v64;
          if ( v68 > 0 )
          {
            v71 = (float *)(v67 + 8);
            v72 = ((unsigned int)(v68 - 1) >> 2) + 1;
            do
            {
              v73 = (float)(v70 * *v71) + v69[2];
              v74 = (float)(*(v71 - 1) * v70) + v69[1];
              v75 = (float)(v71[1] * v70) + v69[3];
              *v69 = (float)(*(v71 - 2) * v70) + *v69;
              v69[1] = v74;
              v69[2] = v73;
              v69[3] = v75;
              v69 += 4;
              v71 += 4;
              --v72;
            }
            while ( v72 != 0 );
          }
          *(_DWORD *)(del_nrb + 4 * v59) = 0;
        }
        if ( --ib < 0 )
          break;
        v60 = ib;
      }
    }
    --this->n_sub;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009DF60
// Name: public: enum IVP_RETURN_TYPE IVP_Great_Matrix_Many_Zero::solve_great_matrix_many_zero(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_Great_Matrix_Many_Zero::solve_great_matrix_many_zero(IVP_Great_Matrix_Many_Zero *this)
{
  IVP_Great_Matrix_Many_Zero::transform_to_lower_null_triangle(this);
  return IVP_Great_Matrix_Many_Zero::solve_lower_null_matrix(this);
}

//------------------------------------------------------------------------------
// Address: 0x1009DF70
// Name: private: void IVP_Linear_Constraint_Solver::decrement_sub_solver(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Linear_Constraint_Solver::decrement_sub_solver(IVP_Linear_Constraint_Solver *this, int sub_pos)
{
  if ( this->sub_solver_status != 0 )
  {
    --this->lu_sub_solver.n_sub;
  }
  else if ( IVP_Incr_L_U_Matrix::decrement_l_u(this: &this->lu_sub_solver, del_nr: sub_pos) != 1 )
  {
    this->sub_solver_status = 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009DFB0
// Name: private: void IVP_Linear_Constraint_Solver::increment_sub_solver(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Linear_Constraint_Solver::increment_sub_solver(IVP_Linear_Constraint_Solver *this)
{
  int r_actives; // esi
  int v2; // edx
  int v3; // eax
  int v4; // edi
  int v5; // esi
  int i; // eax
  int v7; // esi
  int v8; // eax
  IVP_Incr_L_U_Matrix *p_lu_sub_solver; // esi
  int v10; // eax
  int v11; // ecx
  double v12; // st7
  int v13; // edi
  int v14; // ecx
  double v15; // st7
  int v16; // eax
  int v17; // ecx
  int v18; // edx
  int v19; // edx
  int v20; // ecx
  int n_sub; // ecx
  float *L_matrix; // edx
  _BYTE *v23; // edi
  int v24; // eax
  int v25; // ecx
  int v26; // eax
  int v27; // ebx
  float *U_matrix; // ecx
  float v29; // xmm0_4
  int v30; // edi
  int v31; // ecx
  unsigned int v32; // edx
  int v33; // ecx
  float *v34; // eax
  float v35; // xmm0_4
  float *v36; // edx
  unsigned int v37; // ecx
  float v38; // xmm1_4
  float v39; // xmm2_4
  float v40; // xmm3_4
  float *v41; // eax
  float *v42; // ecx
  unsigned int v43; // edx
  int v44; // ecx
  float *v45; // eax
  float *v46; // edx
  unsigned int v47; // ecx
  float v48; // xmm1_4
  float v49; // xmm2_4
  float v50; // xmm3_4
  int v52; // [esp+Ch] [ebp-Ch]
  int new_var_orig; // [esp+10h] [ebp-8h]
  int new_var_origa; // [esp+10h] [ebp-8h]
  int v55; // [esp+14h] [ebp-4h]
  int v56; // [esp+14h] [ebp-4h]

  r_actives = this->r_actives;
  v2 = this->actives_inactives_ignored[r_actives - 1];
  new_var_orig = v2;
  if ( this->sub_solver_status != 0 )
  {
    ++this->lu_sub_solver.n_sub;
  }
  else
  {
    v3 = 0;
    if ( r_actives > 0 )
    {
      do
      {
        v4 = this->actives_inactives_ignored[v3] + v2 * this->aligned_size;
        v5 = v3 + this->lu_sub_solver.n_sub * this->lu_sub_solver.aligned_row_len;
        v2 = new_var_orig;
        ++v3;
        this->lu_sub_solver.U_matrix[v5] = this->full_A[v4];
      }
      while ( v3 < this->r_actives );
    }
    for ( i = 0; i < this->r_actives - 1; this->lu_sub_solver.input_vec[i - 1] = this->full_A[v7] )
      v7 = v2 + this->aligned_size * this->actives_inactives_ignored[i++];
    v8 = this->lu_sub_solver.n_sub - 1;
    p_lu_sub_solver = &this->lu_sub_solver;
    if ( v8 >= 0 )
    {
      if ( this->lu_sub_solver.n_sub >= 4 )
      {
        do
        {
          this->lu_sub_solver.mult_vec[v8] = this->lu_sub_solver.input_vec[v8];
          this->lu_sub_solver.mult_vec[v8 - 1] = this->lu_sub_solver.input_vec[v8 - 1];
          this->lu_sub_solver.mult_vec[v8 - 2] = this->lu_sub_solver.input_vec[v8 - 2];
          this->lu_sub_solver.mult_vec[v8 - 3] = this->lu_sub_solver.input_vec[v8 - 3];
          v8 -= 4;
        }
        while ( v8 >= 3 );
      }
      for ( ; v8 >= 0; this->lu_sub_solver.mult_vec[v8 + 1] = this->lu_sub_solver.input_vec[v8 + 1] )
        --v8;
    }
    IVP_Incr_L_U_Matrix::mult_vec_with_L(this: p_lu_sub_solver);
    v10 = p_lu_sub_solver->n_sub - 1;
    if ( v10 >= 0 )
    {
      if ( p_lu_sub_solver->n_sub >= 4 )
      {
        v11 = p_lu_sub_solver->n_sub - 3;
        v55 = v11;
        do
        {
          v12 = p_lu_sub_solver->temp_vec[v10];
          v13 = p_lu_sub_solver->n_sub + v10 * p_lu_sub_solver->aligned_row_len;
          v10 -= 4;
          p_lu_sub_solver->U_matrix[v13] = v12;
          p_lu_sub_solver->U_matrix[p_lu_sub_solver->n_sub + p_lu_sub_solver->aligned_row_len * (v11 + 1)] = p_lu_sub_solver->temp_vec[v10 + 3];
          p_lu_sub_solver->U_matrix[p_lu_sub_solver->n_sub + v11 * p_lu_sub_solver->aligned_row_len] = p_lu_sub_solver->temp_vec[v10 + 2];
          p_lu_sub_solver->U_matrix[p_lu_sub_solver->n_sub + p_lu_sub_solver->aligned_row_len * (v55 - 1)] = p_lu_sub_solver->temp_vec[v10 + 1];
          v11 = v55 - 4;
          v55 -= 4;
        }
        while ( v10 >= 3 );
      }
      for ( ; v10 >= 0; p_lu_sub_solver->U_matrix[p_lu_sub_solver->n_sub + v14] = v15 )
      {
        v14 = v10 * p_lu_sub_solver->aligned_row_len;
        v15 = p_lu_sub_solver->temp_vec[v10--];
      }
    }
    v16 = p_lu_sub_solver->n_sub - 1;
    if ( v16 >= 0 )
    {
      if ( p_lu_sub_solver->n_sub >= 4 )
      {
        v17 = p_lu_sub_solver->n_sub - 3;
        do
        {
          v18 = p_lu_sub_solver->n_sub + v16 * p_lu_sub_solver->aligned_row_len;
          v16 -= 4;
          p_lu_sub_solver->L_matrix[v18] = 0.0;
          p_lu_sub_solver->L_matrix[p_lu_sub_solver->n_sub + p_lu_sub_solver->aligned_row_len * (v17 + 1)] = 0.0;
          p_lu_sub_solver->L_matrix[p_lu_sub_solver->n_sub + v17 * p_lu_sub_solver->aligned_row_len] = 0.0;
          v19 = p_lu_sub_solver->n_sub + p_lu_sub_solver->aligned_row_len * (v17 - 1);
          v17 -= 4;
          p_lu_sub_solver->L_matrix[v19] = 0.0;
        }
        while ( v16 >= 3 );
      }
      for ( ; v16 >= 0; p_lu_sub_solver->L_matrix[p_lu_sub_solver->n_sub + v20] = 0.0 )
      {
        v20 = v16 * p_lu_sub_solver->aligned_row_len;
        --v16;
      }
    }
    n_sub = p_lu_sub_solver->n_sub;
    L_matrix = p_lu_sub_solver->L_matrix;
    v23 = (_BYTE *)((unsigned int)&L_matrix[n_sub * p_lu_sub_solver->aligned_row_len] & 0xFFFFFFF0);
    v24 = (((char *)&L_matrix[n_sub * p_lu_sub_solver->aligned_row_len] - v23) >> 2) + n_sub - 1;
    if ( v24 >= 0 )
      memset(v23, 0, 4 * ((v24 + 4) & 0x3FFFFFFC));
    p_lu_sub_solver->L_matrix[p_lu_sub_solver->n_sub * (p_lu_sub_solver->aligned_row_len + 1)] = 1.0;
    v25 = p_lu_sub_solver->n_sub;
    v26 = v25 * p_lu_sub_solver->aligned_row_len;
    p_lu_sub_solver->n_sub = ++v25;
    v27 = 0;
    v56 = 0;
    if ( v25 - 1 > 0 )
    {
      new_var_origa = v26;
      do
      {
        U_matrix = p_lu_sub_solver->U_matrix;
        v29 = U_matrix[new_var_origa];
        v30 = v27 * p_lu_sub_solver->aligned_row_len;
        v31 = (int)&U_matrix[v30 + 1 + v27];
        v52 = p_lu_sub_solver->aligned_row_len * (p_lu_sub_solver->n_sub - 1);
        v32 = v31 & 0xFFFFFFF0;
        v33 = ((int)(v31 - (v31 & 0xFFFFFFF0)) >> 2) - v56 + p_lu_sub_solver->n_sub - 1;
        v34 = (float *)((int)&p_lu_sub_solver->U_matrix[v27 + 1 + v52] & 0xFFFFFFF0);
        v35 = -v29;
        if ( v33 > 0 )
        {
          v36 = (float *)(v32 + 8);
          v37 = ((unsigned int)(v33 - 1) >> 2) + 1;
          do
          {
            v38 = (float)(*(v36 - 1) * v35) + v34[1];
            v39 = (float)(*v36 * v35) + v34[2];
            v40 = (float)(v36[1] * v35) + v34[3];
            *v34 = (float)(*(v36 - 2) * v35) + *v34;
            v34[1] = v38;
            v34[2] = v39;
            v34[3] = v40;
            v34 += 4;
            v36 += 4;
            --v37;
          }
          while ( v37 != 0 );
        }
        v41 = p_lu_sub_solver->L_matrix;
        v42 = &v41[v30];
        v43 = (unsigned int)v42 & 0xFFFFFFF0;
        v44 = p_lu_sub_solver->n_sub + ((int)((int)v42 - ((unsigned int)v42 & 0xFFFFFFF0)) >> 2);
        v45 = (float *)((unsigned int)&v41[v52] & 0xFFFFFFF0);
        if ( v44 > 0 )
        {
          v46 = (float *)(v43 + 8);
          v47 = ((unsigned int)(v44 - 1) >> 2) + 1;
          do
          {
            v48 = (float)(*(v46 - 1) * v35) + v45[1];
            v49 = (float)(*v46 * v35) + v45[2];
            v50 = (float)(v46[1] * v35) + v45[3];
            *v45 = (float)(*(v46 - 2) * v35) + *v45;
            v45[1] = v48;
            v45[2] = v49;
            v45[3] = v50;
            v45 += 4;
            v46 += 4;
            --v47;
          }
          while ( v47 != 0 );
        }
        ++new_var_origa;
        p_lu_sub_solver->U_matrix[v27 + v52] = 0.0;
        v27 = v56 + 1;
        v56 = v27;
      }
      while ( v27 < p_lu_sub_solver->n_sub - 1 );
    }
    if ( IVP_Incr_L_U_Matrix::normize_row(this: p_lu_sub_solver, row_nr: p_lu_sub_solver->n_sub - 1) != 1 )
      this->sub_solver_status = 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009E3E0
// Name: private: void IVP_Linear_Constraint_Solver::move_not_necessary_actives_to_inactives(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Linear_Constraint_Solver::move_not_necessary_actives_to_inactives(
        IVP_Linear_Constraint_Solver *this)
{
  int i; // edi
  float *v3; // eax
  int r_actives; // eax
  int *actives_inactives_ignored; // ecx
  int v6; // edx
  int v7; // ebx

  for ( i = 0; i < this->r_actives; ++i )
  {
    v3 = &this->full_x[this->actives_inactives_ignored[i]];
    if ( this->SOLVER_EPS > *v3 )
    {
      *v3 = 0.0;
      r_actives = this->r_actives;
      actives_inactives_ignored = this->actives_inactives_ignored;
      v6 = actives_inactives_ignored[r_actives - 1];
      v7 = actives_inactives_ignored[i];
      --r_actives;
      actives_inactives_ignored[i] = v6;
      this->actives_inactives_ignored[r_actives] = v7;
      this->variable_is_found_at[v6] = i;
      this->variable_is_found_at[v7] = r_actives;
      --this->r_actives;
      if ( this->sub_solver_status != 0 )
      {
        --this->lu_sub_solver.n_sub;
      }
      else if ( IVP_Incr_L_U_Matrix::decrement_l_u(this: &this->lu_sub_solver, del_nr: i) != 1 )
      {
        this->sub_solver_status = 2;
      }
      --i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009E470
// Name: private: enum IVP_RETURN_TYPE IVP_Linear_Constraint_Solver::get_fdirection(void)
// Source: json
//------------------------------------------------------------------------------
IVP_RETURN_TYPE __thiscall IVP_Linear_Constraint_Solver::get_fdirection(IVP_Linear_Constraint_Solver *this)
{
  int j; // eax
  int r_actives; // ecx
  IVP_RETURN_TYPE result; // eax
  int v5; // edx
  int v6; // eax
  int v7; // ecx
  int v8; // edx
  int v9; // eax
  int v10; // ebx
  int v11; // edi
  int k; // ecx
  int m; // ecx
  double v14; // st7
  int v15; // edi
  int index; // [esp+4h] [ebp-Ch]
  int ignored_index; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  for ( j = 0; j < this->aligned_size; ++j )
    this->delta_f[j] = 0.0;
  r_actives = this->r_actives;
  if ( r_actives == 0 )
    return IVP_OK;
  if ( this->sub_solver_status != 0 )
  {
    ++this->debug_no_lu_count;
    this->sub_solver_mat.columns = r_actives;
    this->sub_solver_mat.aligned_row_len = (r_actives + 3) & 0xFFFFFFFC;
    v7 = 0;
    ignored_index = this->actives_inactives_ignored[this->ignored_pos];
    for ( i = 0; v7 < this->r_actives; i = v7 )
    {
      v8 = this->actives_inactives_ignored[v7];
      index = v8;
      this->sub_solver_mat.desired_vector[v7] = -this->full_A[ignored_index + v8 * this->aligned_size];
      v9 = 0;
      if ( this->r_actives > 0 )
      {
        while ( 1 )
        {
          v10 = this->actives_inactives_ignored[v9] + v8 * this->aligned_size;
          v11 = v9 + v7 * this->sub_solver_mat.aligned_row_len;
          ++v9;
          this->sub_solver_mat.matrix_values[v11] = this->full_A[v10];
          v7 = i;
          if ( v9 >= this->r_actives )
            break;
          v8 = index;
        }
      }
      ++v7;
    }
    IVP_Great_Matrix_Many_Zero::transform_to_lower_null_triangle(this: &this->sub_solver_mat);
    result = IVP_Great_Matrix_Many_Zero::solve_lower_null_matrix(this: &this->sub_solver_mat);
    for ( k = 0; k < this->r_actives; ++k )
      this->lu_sub_solver.out_vec[k] = this->sub_solver_mat.result_vector[k];
  }
  else
  {
    v5 = this->actives_inactives_ignored[this->ignored_pos];
    v6 = 0;
    if ( r_actives > 0 )
    {
      do
      {
        this->lu_sub_solver.input_vec[v6] = -this->full_A[v5 + this->aligned_size * this->actives_inactives_ignored[v6]];
        ++v6;
      }
      while ( v6 < this->r_actives );
    }
    IVP_Incr_L_U_Matrix::solve_lin_equ(this: &this->lu_sub_solver);
    result = IVP_OK;
  }
  for ( m = 0; m < this->r_actives; this->delta_f[v15] = v14 )
  {
    v14 = this->lu_sub_solver.out_vec[m];
    v15 = this->actives_inactives_ignored[m++];
  }
  this->delta_f[this->actives_inactives_ignored[this->ignored_pos]] = 1.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1009E620
// Name: private: void IVP_Linear_Constraint_Solver::startup_setup(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall IVP_Linear_Constraint_Solver::startup_setup(IVP_Linear_Constraint_Solver *this, int try_actives)
{
  int v3; // eax
  int i; // eax
  double v5; // st7
  int v6; // edx
  int r_actives; // eax
  int v8; // ecx
  float *full_x; // edx
  int *actives_inactives_ignored; // edx
  int v11; // ecx
  int v12; // ebx
  int v13; // edi
  int v14; // eax

  this->r_actives = try_actives;
  this->ignored_pos = try_actives;
  this->lu_sub_solver.n_sub = try_actives;
  v3 = 0;
  for ( this->aligned_sub_size = (try_actives + 3) & 0xFFFFFFFC; v3 < this->aligned_size; ++v3 )
    this->reset_x[v3] = 0.0;
  if ( IVP_Linear_Constraint_Solver::setup_l_u_solver(this) == 1 )
  {
    this->sub_solver_status = 0;
begin_of_while:
    IVP_Incr_L_U_Matrix::solve_lin_equ(this: &this->lu_sub_solver);
    for ( i = 0; i < this->r_actives; this->reset_x[v6] = v5 )
    {
      v5 = this->lu_sub_solver.out_vec[i];
      v6 = this->actives_inactives_ignored[i++];
    }
    IVP_Linear_Constraint_Solver::get_values_when_setup(this);
    r_actives = this->r_actives;
    while ( --r_actives >= 0 )
    {
      v8 = this->actives_inactives_ignored[r_actives];
      full_x = this->full_x;
      if ( full_x[v8] < 0.0 )
      {
        full_x[v8] = 0.0;
        this->reset_x[v8] = 0.0;
        --this->r_actives;
        --this->ignored_pos;
        actives_inactives_ignored = this->actives_inactives_ignored;
        v11 = this->r_actives;
        v12 = actives_inactives_ignored[v11];
        v13 = actives_inactives_ignored[r_actives];
        actives_inactives_ignored[v11] = v13;
        this->actives_inactives_ignored[r_actives] = v12;
        this->variable_is_found_at[v13] = v11;
        this->variable_is_found_at[v12] = r_actives;
        IVP_Linear_Constraint_Solver::decrement_sub_solver(this, sub_pos: r_actives);
        v14 = 0;
        if ( this->sub_solver_status <= 0 )
        {
          if ( this->r_actives > 0 )
          {
            do
            {
              this->lu_sub_solver.input_vec[v14] = this->full_b[this->actives_inactives_ignored[v14]];
              ++v14;
            }
            while ( v14 < this->r_actives );
          }
          goto begin_of_while;
        }
        if ( this->n_variables > 0 )
        {
          do
          {
            this->accel[v14] = 0.0;
            this->full_x[v14++] = 0.0;
          }
          while ( v14 < this->n_variables );
        }
        goto fast_setup_failed;
      }
    }
  }
  else
  {
fast_setup_failed:
    this->r_actives = 0;
    this->ignored_pos = 0;
    this->lu_sub_solver.n_sub = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009E780
// Name: private: enum IVP_RETURN_TYPE IVP_Linear_Constraint_Solver::full_setup(void)
// Source: json
//------------------------------------------------------------------------------
IVP_RETURN_TYPE __thiscall IVP_Linear_Constraint_Solver::full_setup(IVP_Linear_Constraint_Solver *this)
{
  int j; // eax
  int k; // eax
  double v4; // st7
  int v5; // ecx
  IVP_Linear_Constraint_Solver *v6; // ecx
  int r_actives; // edx
  int v8; // ecx
  int v9; // edx
  int v10; // eax
  int v11; // ebx
  int v12; // edi
  IVP_RETURN_TYPE result; // eax
  int m; // eax
  double v15; // st7
  int v16; // ecx
  int index; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  do
  {
    this->lu_sub_solver.n_sub = this->r_actives;
    for ( j = 0; j < this->aligned_size; ++j )
      this->reset_x[j] = 0.0;
    IVP_Linear_Constraint_Solver::do_a_little_random_permutation(this);
    if ( IVP_Linear_Constraint_Solver::setup_l_u_solver(this) == 1 )
    {
      this->sub_solver_status = 0;
      IVP_Incr_L_U_Matrix::solve_lin_equ(this: &this->lu_sub_solver);
      for ( k = 0; k < this->r_actives; this->reset_x[v5] = v4 )
      {
        v4 = this->lu_sub_solver.out_vec[k];
        v5 = this->actives_inactives_ignored[k++];
      }
    }
    else
    {
      this->sub_solver_status = 2;
      IVP_Linear_Constraint_Solver::lcs_bubble_sort_x_vals(this);
      IVP_Linear_Constraint_Solver::do_a_little_random_permutation(this: v6);
      r_actives = this->r_actives;
      v8 = 0;
      this->sub_solver_mat.columns = r_actives;
      this->sub_solver_mat.aligned_row_len = (r_actives + 3) & 0xFFFFFFFC;
      for ( i = 0; v8 < this->r_actives; i = v8 )
      {
        v9 = this->actives_inactives_ignored[v8];
        v10 = 0;
        this->sub_solver_mat.desired_vector[v8] = this->full_b[v9];
        index = v9;
        if ( this->r_actives > 0 )
        {
          while ( 1 )
          {
            v11 = this->actives_inactives_ignored[v10] + v9 * this->aligned_size;
            v12 = v10 + v8 * this->sub_solver_mat.aligned_row_len;
            ++v10;
            this->sub_solver_mat.matrix_values[v12] = this->full_A[v11];
            v8 = i;
            if ( v10 >= this->r_actives )
              break;
            v9 = index;
          }
        }
        ++v8;
      }
      IVP_Great_Matrix_Many_Zero::transform_to_lower_null_triangle(this: &this->sub_solver_mat);
      result = IVP_Great_Matrix_Many_Zero::solve_lower_null_matrix(this: &this->sub_solver_mat);
      if ( result != IVP_OK )
        return result;
      for ( m = 0; m < this->r_actives; this->reset_x[v16] = v15 )
      {
        v15 = this->sub_solver_mat.result_vector[m];
        v16 = this->actives_inactives_ignored[m++];
      }
    }
    IVP_Linear_Constraint_Solver::get_values_when_setup(this);
  }
  while ( IVP_Linear_Constraint_Solver::full_setup_test_ranges(this) > 0 );
  return IVP_OK;
}

//------------------------------------------------------------------------------
// Address: 0x1009E8F0
// Name: private: enum IVP_RETURN_TYPE IVP_Linear_Constraint_Solver::solve_lc(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall IVP_Linear_Constraint_Solver::solve_lc(IVP_Linear_Constraint_Solver *this)
{
  float v2; // xmm7_4
  int ignored_pos; // eax
  int v4; // ebx
  int sub_solver_status; // eax
  float v6; // xmm0_4
  int i; // eax
  int v8; // edx
  float v9; // xmm0_4
  float v10; // xmm1_4
  int v11; // edi
  float step_size; // xmm2_4
  int v13; // ecx
  int *actives_inactives_ignored; // eax
  int v15; // edx
  float v16; // xmm3_4
  float v17; // xmm0_4
  int r_actives; // eax
  int *v19; // ecx
  float v20; // xmm1_4
  int v21; // eax
  float *full_x; // edx
  bool v23; // cc
  float *v24; // eax
  int *v25; // ecx
  int v26; // edx
  int v27; // eax
  int v28; // ebx
  int v29; // eax
  IVP_Linear_Constraint_Solver *v30; // ecx
  int *v31; // ecx
  int v32; // edx
  int v33; // eax
  int v34; // ebx
  int *v35; // ecx
  int v36; // edx
  int v37; // eax
  int v38; // ebx
  int v39; // eax
  float *accel; // edx
  float *v41; // eax
  float MAX_STEP_LEN; // [esp+10h] [ebp-20h]
  int did_real_step; // [esp+1Ch] [ebp-14h]
  int nr_zero_steps; // [esp+20h] [ebp-10h]
  int step_count; // [esp+24h] [ebp-Ch]
  int next_numeric_stability_test; // [esp+28h] [ebp-8h]
  float solver_eps; // [esp+2Ch] [ebp-4h]

  v2 = this->SOLVER_EPS;
  step_count = 0;
  nr_zero_steps = 0;
  did_real_step = 0;
  next_numeric_stability_test = 7;
  solver_eps = this->SOLVER_EPS;
  while ( 1 )
  {
    if ( did_real_step != 0 )
      ++step_count;
    if ( step_count > 250 )
      return 0;
    if ( next_numeric_stability_test != 0 )
    {
      --next_numeric_stability_test;
      goto LABEL_9;
    }
    if ( IVP_Linear_Constraint_Solver::numerical_stability_ok(this) == 0 )
    {
perform_full_setup:
      if ( ++step_count > 250 )
        return 0;
      nr_zero_steps = 0;
      if ( IVP_Linear_Constraint_Solver::full_setup(this) == IVP_FAULT )
        return 0;
      v2 = solver_eps;
    }
    next_numeric_stability_test = 7;
LABEL_9:
    ignored_pos = this->ignored_pos;
    if ( ignored_pos >= this->n_variables )
      return 1;
    v4 = this->actives_inactives_ignored[ignored_pos];
    sub_solver_status = this->sub_solver_status;
    if ( sub_solver_status > 0 )
    {
      if ( sub_solver_status == 1 && did_real_step != 0 )
      {
        IVP_Linear_Constraint_Solver::do_a_little_random_permutation(this);
        if ( IVP_Linear_Constraint_Solver::setup_l_u_solver(this) == 1 )
          this->sub_solver_status = 0;
      }
      else
      {
        this->sub_solver_status = 1;
      }
    }
    v6 = this->accel[v4];
    if ( v2 > fabs(v6) )
    {
      v11 = this->ignored_pos;
      if ( v2 <= fabs(this->full_x[v4]) )
        goto move_ignored_to_active;
move_ignored_to_inactive:
      v39 = this->actives_inactives_ignored[this->ignored_pos];
      this->full_x[v39] = 0.0;
      accel = this->accel;
      v23 = accel[v39] >= 0.0;
      v41 = &accel[v39];
      did_real_step = 0;
      if ( !v23 )
        *v41 = 0.0;
      if ( ++this->ignored_pos >= this->n_variables )
        next_numeric_stability_test = 0;
    }
    else
    {
      if ( v6 >= 0.0 )
        goto move_ignored_to_inactive;
      if ( IVP_Linear_Constraint_Solver::get_fdirection(this) == IVP_FAULT )
        goto perform_full_setup;
      this->delta_f[v4] = 1.0;
      IVP_Linear_Constraint_Solver::mult_active_x_for_accel(this);
      for ( i = 0; i < this->r_actives; this->delta_accel[v8] = 0.0 )
        v8 = this->actives_inactives_ignored[i++];
      v9 = this->accel[v4];
      v10 = this->delta_accel[v4];
      MAX_STEP_LEN = this->MAX_STEP_LEN;
      if ( (float)(MAX_STEP_LEN * v10) <= (float)-v9 )
      {
        step_size = 1.0e20;
        v11 = -1;
      }
      else
      {
        v11 = this->ignored_pos;
        step_size = -(float)(v9 / v10);
      }
      v2 = solver_eps;
      v13 = 0;
      if ( this->r_actives > 0 )
      {
        actives_inactives_ignored = this->actives_inactives_ignored;
        do
        {
          v15 = *actives_inactives_ignored;
          v16 = this->delta_f[*actives_inactives_ignored];
          if ( (float)-solver_eps > v16 )
          {
            v17 = -(float)(this->full_x[v15] / v16);
            if ( solver_eps > COERCE_FLOAT(LODWORD(v17) & _mask__AbsFloat_) && solver_eps > this->full_x[v15] )
            {
              v11 = v13;
              step_size = -(float)(this->full_x[v15] / v16);
              goto limiting_var_found;
            }
            if ( (float)(step_size + solver_eps) > v17 )
            {
              step_size = -(float)(this->full_x[v15] / v16);
              v11 = v13;
            }
          }
          ++v13;
          ++actives_inactives_ignored;
        }
        while ( v13 < this->r_actives );
      }
      r_actives = this->r_actives;
      if ( r_actives < this->ignored_pos )
      {
        v19 = &this->actives_inactives_ignored[r_actives];
        do
        {
          v20 = this->delta_accel[*v19];
          if ( (float)-this->SOLVER_EPS > v20
            && (float)(step_size - solver_eps) > (float)-(float)(this->accel[*v19] / v20) )
          {
            step_size = -(float)(this->accel[*v19] / v20);
            v11 = r_actives;
          }
          ++r_actives;
          ++v19;
        }
        while ( r_actives < this->ignored_pos );
      }
      if ( step_size < 0.0 )
        step_size = 0.0;
      if ( v11 < 0 )
        return 0;
limiting_var_found:
      if ( step_size > MAX_STEP_LEN )
        goto perform_full_setup;
      if ( this->SOLVER_EPS <= step_size )
      {
        nr_zero_steps = 0;
        goto LABEL_55;
      }
      if ( ++nr_zero_steps > (this->n_variables >> 1) + 2 )
        goto perform_full_setup;
LABEL_55:
      did_real_step = 1;
      IVP_Linear_Constraint_Solver::update_step_vars(this, step_size);
      if ( v11 >= this->r_actives )
      {
        if ( v11 >= this->ignored_pos )
        {
move_ignored_to_active:
          IVP_Linear_Constraint_Solver::move_not_necessary_actives_to_inactives(this);
          v21 = this->actives_inactives_ignored[v11];
          this->accel[v21] = 0.0;
          full_x = this->full_x;
          v23 = full_x[v21] >= 0.0;
          v24 = &full_x[v21];
          if ( !v23 )
            *v24 = 0.0;
          v25 = this->actives_inactives_ignored;
          v26 = v25[v11];
          v27 = this->r_actives;
          v28 = v25[v27];
          v25[v27] = v26;
          this->actives_inactives_ignored[v11] = v28;
          this->variable_is_found_at[v26] = v27;
          this->variable_is_found_at[v28] = v11;
          v29 = ++this->ignored_pos;
          ++this->r_actives;
          if ( v29 >= this->n_variables )
          {
            v2 = solver_eps;
            next_numeric_stability_test = 0;
          }
          else
          {
            IVP_Linear_Constraint_Solver::increment_sub_solver(this);
            v2 = solver_eps;
          }
        }
        else
        {
          if ( step_size > this->SOLVER_EPS )
          {
            IVP_Linear_Constraint_Solver::move_not_necessary_actives_to_inactives(this: v30);
            v2 = solver_eps;
          }
          this->accel[this->actives_inactives_ignored[v11]] = 0.0;
          v35 = this->actives_inactives_ignored;
          v36 = v35[v11];
          v37 = this->r_actives;
          v38 = v35[v37];
          v35[v37] = v36;
          this->actives_inactives_ignored[v11] = v38;
          this->variable_is_found_at[v36] = v37;
          this->variable_is_found_at[v38] = v11;
          ++this->r_actives;
          IVP_Linear_Constraint_Solver::increment_sub_solver(this);
        }
      }
      else
      {
        this->full_x[this->actives_inactives_ignored[v11]] = 0.0;
        --this->r_actives;
        v31 = this->actives_inactives_ignored;
        v32 = v31[v11];
        v33 = this->r_actives;
        v34 = v31[v33];
        v31[v33] = v32;
        this->actives_inactives_ignored[v11] = v34;
        this->variable_is_found_at[v32] = v33;
        this->variable_is_found_at[v34] = v11;
        if ( this->sub_solver_status != 0 )
        {
          --this->lu_sub_solver.n_sub;
        }
        else
        {
          v2 = solver_eps;
          if ( IVP_Incr_L_U_Matrix::decrement_l_u(this: &this->lu_sub_solver, del_nr: v11) != 1 )
            this->sub_solver_status = 2;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009ED60
// Name: public: enum IVP_RETURN_TYPE IVP_Linear_Constraint_Solver::init_and_solve_lc(float __near *,float __near *,float __near *,int,int,class IVP_U_Memory __near *)
// Source: json
//------------------------------------------------------------------------------
IVP_RETURN_TYPE __thiscall IVP_Linear_Constraint_Solver::init_and_solve_lc(
        IVP_Linear_Constraint_Solver *this,
        float *A_in,
        float *b_in,
        float *result_vec_out,
        int var_num,
        int actives_at_begin,
        IVP_U_Memory *my_mem)
{
  float *temp_vec; // edx
  int aligned_size; // ecx
  float *delta_accel; // eax
  float *delta_f; // edx
  int v12; // eax
  float *v13; // ecx
  IVP_RETURN_TYPE result; // eax

  this->n_variables = var_num;
  this->aligned_size = (var_num + 3) & 0xFFFFFFFC;
  IVP_Linear_Constraint_Solver::alloc_memory(this, my_mem);
  temp_vec = this->lu_sub_solver.temp_vec;
  aligned_size = this->aligned_size;
  this->full_solver_mat.matrix_values = A_in;
  delta_accel = this->delta_accel;
  this->TEST_EPS = 0.0001;
  this->temp = temp_vec;
  delta_f = this->delta_f;
  this->full_solver_mat.result_vector = delta_accel;
  this->MAX_STEP_LEN = 10000.0;
  v12 = 0;
  this->full_solver_mat.desired_vector = delta_f;
  this->r_actives = 0;
  this->ignored_pos = 0;
  this->SOLVER_EPS = 0.0000001;
  this->GAUSS_EPS = 0.0000001;
  this->sub_solver_status = 0;
  this->lu_sub_solver.aligned_row_len = aligned_size;
  this->lu_sub_solver.n_sub = 0;
  this->lu_sub_solver.MATRIX_EPS = 0.000001;
  this->sub_solver_mat.MATRIX_EPS = 0.0000001;
  this->inv_mat.MATRIX_EPS = 0.0000001;
  this->full_solver_mat.columns = var_num;
  this->full_solver_mat.aligned_row_len = aligned_size;
  this->full_solver_mat.MATRIX_EPS = 0.0000001;
  if ( aligned_size > 0 )
  {
    do
    {
      this->actives_inactives_ignored[v12] = v12;
      this->variable_is_found_at[v12] = v12;
      v13 = &b_in[v12];
      *(float *)((char *)v13 + (char *)result_vec_out - (char *)b_in) = 0.0;
      this->accel[v12++] = -*v13;
    }
    while ( v12 < this->aligned_size );
  }
  this->full_b = b_in;
  this->full_x = result_vec_out;
  this->full_A = A_in;
  this->first_permute_index = 0;
  this->second_permute_index = 0;
  this->first_permute_ignored = 0;
  this->second_permute_ignored = 0;
  this->debug_no_lu_count = 0;
  this->debug_lcs = 0;
  IVP_Linear_Constraint_Solver::startup_setup(this, try_actives: actives_at_begin);
  result = IVP_Linear_Constraint_Solver::solve_lc(this);
  this->full_solver_mat.result_vector = nullptr;
  this->full_solver_mat.desired_vector = nullptr;
  this->full_solver_mat.matrix_values = nullptr;
  this->sub_solver_mat.result_vector = nullptr;
  this->sub_solver_mat.desired_vector = nullptr;
  this->sub_solver_mat.matrix_values = nullptr;
  this->inv_mat.result_vector = nullptr;
  this->inv_mat.desired_vector = nullptr;
  this->inv_mat.matrix_values = nullptr;
  return result;
}
