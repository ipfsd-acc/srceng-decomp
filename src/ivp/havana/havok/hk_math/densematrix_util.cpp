// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/havana/havok/hk_math/densematrix_util.cpp
// Functions: 4
// ============================================================

#include "ivp\havana\havok\hk_math\densematrix_util.h"

//------------------------------------------------------------------------------
// Address: 0x100442A0
// Name: public: static void hk_Dense_Matrix_Util::mult(class hk_Dense_Matrix const __near &,class hk_Dense_Vector const __near &,class hk_Dense_Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl hk_Dense_Matrix_Util::mult(const hk_Dense_Matrix *m, const hk_Dense_Vector *in, hk_Dense_Vector *out)
{
  int m_rows; // ebx
  int m_cols; // edi
  int v6; // eax
  int v7; // edx
  int v8; // eax
  float *v9; // edi
  float v10; // xmm0_4
  int cols; // [esp+Ch] [ebp-8h]
  int rows; // [esp+10h] [ebp-4h]
  float *ma; // [esp+1Ch] [ebp+8h]
  float *mb; // [esp+1Ch] [ebp+8h]

  m_rows = m->m_rows;
  m_cols = m->m_cols;
  v6 = 0;
  rows = m_rows;
  for ( cols = m_cols; v6 < out->m_size; ++v6 )
    out->m_elt[v6] = 0.0;
  v7 = 0;
  if ( m_cols > 0 )
  {
    do
    {
      v8 = 0;
      if ( m_rows >= 4 )
      {
        ma = &in->m_elt[v7];
        do
        {
          out->m_elt[v8] = (float)(m->m_elt[v8 + v7 * m->m_lda] * *ma) + out->m_elt[v8];
          out->m_elt[v8 + 1] = (float)(m->m_elt[v8 + 1 + v7 * m->m_lda] * *ma) + out->m_elt[v8 + 1];
          out->m_elt[v8 + 2] = (float)(m->m_elt[v8 + 2 + v7 * m->m_lda] * *ma) + out->m_elt[v8 + 2];
          m_rows = rows;
          out->m_elt[v8 + 3] = (float)(m->m_elt[v8 + 3 + v7 * m->m_lda] * *ma) + out->m_elt[v8 + 3];
          v8 += 4;
        }
        while ( v8 < rows - 3 );
      }
      if ( v8 < m_rows )
      {
        mb = &in->m_elt[v7];
        do
        {
          v9 = &out->m_elt[v8];
          m_rows = rows;
          v10 = (float)(m->m_elt[v8 + v7 * m->m_lda] * *mb) + *v9;
          ++v8;
          *v9 = v10;
        }
        while ( v8 < rows );
      }
      ++v7;
    }
    while ( v7 < cols );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10044410
// Name: public: static enum hk_result hk_Dense_Matrix_Util::invert_6x6(class hk_Fixed_Dense_Matrix<6> __near &,float)
// Source: json
//------------------------------------------------------------------------------
hk_result __cdecl hk_Dense_Matrix_Util::invert_6x6(hk_Fixed_Dense_Matrix<6> *m)
{
  float *m_elt_buffer; // edx
  float *v2; // ebx
  float *v3; // eax
  int i; // ecx
  int v5; // esi
  float *v6; // edi
  float v7; // xmm0_4
  int v8; // eax
  int v9; // eax
  int v10; // edx
  int v11; // ecx
  float v12; // xmm0_4
  int v13; // edx
  float *v14; // eax
  int v15; // edx
  float *v16; // eax
  int v17; // edi
  int v18; // eax
  float *v19; // ecx
  int v20; // edx
  float *v21; // esi
  float v22; // xmm0_4
  int v23; // ecx
  float *v24; // eax
  int v25; // ecx
  float *v26; // eax
  float *v27; // eax
  float inverted[48]; // [esp+0h] [ebp-D4h] BYREF
  int v30; // [esp+C0h] [ebp-14h]
  float *v31; // [esp+C4h] [ebp-10h]
  char *v32; // [esp+C8h] [ebp-Ch]
  float *v33; // [esp+CCh] [ebp-8h]
  int j; // [esp+D0h] [ebp-4h]
  float *ma; // [esp+DCh] [ebp+8h]

  m_elt_buffer = m->m_elt_buffer;
  v2 = inverted;
  v31 = m->m_elt_buffer;
  ma = m->m_elt_buffer;
  v33 = inverted;
  v3 = inverted;
  for ( i = 23; i >= 0; --i )
  {
    *v3 = 0.0;
    v3[1] = 0.0;
    v3 += 2;
  }
  inverted[0] = 1.0;
  inverted[9] = 1.0;
  inverted[18] = 1.0;
  inverted[27] = 1.0;
  inverted[36] = 1.0;
  inverted[45] = 1.0;
  v5 = 0;
  while ( 1 )
  {
    v6 = &m_elt_buffer[v5];
    v7 = 1.0 / *v6;
    v8 = v5;
    do
    {
      m_elt_buffer[v8] = v7 * m_elt_buffer[v8];
      ++v8;
    }
    while ( v8 < 6 );
    v9 = 0;
    do
    {
      v2[v9] = v2[v9] * v7;
      ++v9;
    }
    while ( v9 <= v5 );
    v10 = v5 + 1;
    v32 = (char *)(v5 + 1);
    if ( v5 + 1 < 6 )
    {
      v11 = 0;
      j = 6 - v10;
      do
      {
        v12 = v6[8];
        v6 += 8;
        v2 += 8;
        v11 -= 8;
        if ( v12 != 0.0 )
        {
          v13 = 0;
          v14 = v2;
          do
          {
            *v14 = *v14 - (float)(v14[v11] * v12);
            ++v13;
            ++v14;
          }
          while ( v13 <= v5 );
          v15 = v5;
          v16 = v6;
          do
          {
            *v16 = *v16 - (float)(v16[v11] * v12);
            ++v15;
            ++v16;
          }
          while ( v15 < 6 );
          v10 = (int)v32;
        }
        --j;
      }
      while ( j != 0 );
      v2 = v33;
    }
    ma += 8;
    v2 += 8;
    v5 = v10;
    v33 = v2;
    if ( v10 >= 6 )
      break;
    m_elt_buffer = ma;
  }
  v17 = 5;
  for ( j = 0; j >= -20; j -= 4 )
  {
    v18 = v17 - 1;
    v19 = ma - 8;
    v2 -= 8;
    ma -= 8;
    v30 = v17 - 1;
    v33 = (float *)(v17 - 1);
    if ( v17 - 1 >= 0 )
    {
      v20 = 0;
      v21 = v19 + 5;
      v32 = (char *)((char *)v2 - (char *)v19);
      do
      {
        v22 = *(float *)((char *)v21 + j - 32);
        v21 -= 8;
        v20 += 8;
        if ( v22 != 0.0 )
        {
          v23 = 5;
          v24 = (float *)&v32[(_DWORD)v21];
          do
          {
            *v24 = *v24 - (float)(v24[v20] * v22);
            --v24;
            --v23;
          }
          while ( v23 >= 0 );
          v25 = 5;
          v26 = v21;
          do
          {
            *v26 = *v26 - (float)(v26[v20] * v22);
            --v25;
            --v26;
          }
          while ( v25 >= v17 );
        }
        v33 = (float *)((char *)v33 - 1);
      }
      while ( (int)v33 >= 0 );
      v18 = v30;
    }
    v17 = v18;
  }
  v27 = v31;
  qmemcpy(v31, inverted, 24);
  v27[8] = inverted[8];
  v27[9] = inverted[9];
  v27[10] = inverted[10];
  v27[11] = inverted[11];
  v27[12] = inverted[12];
  v27[13] = inverted[13];
  v27[16] = inverted[16];
  v27[17] = inverted[17];
  v27[18] = inverted[18];
  v27[19] = inverted[19];
  v27[20] = inverted[20];
  v27[21] = inverted[21];
  v27[24] = inverted[24];
  v27[25] = inverted[25];
  v27[26] = inverted[26];
  v27[27] = inverted[27];
  v27[28] = inverted[28];
  v27[29] = inverted[29];
  v27[32] = inverted[32];
  v27[33] = inverted[33];
  v27[34] = inverted[34];
  v27[35] = inverted[35];
  v27[36] = inverted[36];
  v27[37] = inverted[37];
  v27[40] = inverted[40];
  v27[41] = inverted[41];
  v27[42] = inverted[42];
  v27[43] = inverted[43];
  v27[44] = inverted[44];
  v27[45] = inverted[45];
  return HK_OK;
}

//------------------------------------------------------------------------------
// Address: 0x10044800
// Name: public: static enum hk_result hk_Dense_Matrix_Util::invert_5x5(class hk_Fixed_Dense_Matrix<5> __near &,float)
// Source: json
//------------------------------------------------------------------------------
hk_result __cdecl hk_Dense_Matrix_Util::invert_5x5(hk_Fixed_Dense_Matrix<5> *m)
{
  float *m_elt_buffer; // edx
  float *v2; // ebx
  float *v3; // eax
  int i; // ecx
  int v5; // esi
  float *v6; // edi
  float v7; // xmm0_4
  int v8; // eax
  int v9; // eax
  int v10; // edx
  int v11; // ecx
  float v12; // xmm0_4
  int v13; // edx
  float *v14; // eax
  int v15; // edx
  float *v16; // eax
  int v17; // edi
  int v18; // eax
  float *v19; // ecx
  int v20; // edx
  float *v21; // esi
  float v22; // xmm0_4
  int v23; // ecx
  float *v24; // eax
  int v25; // ecx
  float *v26; // eax
  float *v27; // eax
  float inverted[40]; // [esp+0h] [ebp-B4h] BYREF
  int v30; // [esp+A0h] [ebp-14h]
  float *v31; // [esp+A4h] [ebp-10h]
  char *v32; // [esp+A8h] [ebp-Ch]
  float *v33; // [esp+ACh] [ebp-8h]
  int j; // [esp+B0h] [ebp-4h]
  float *ma; // [esp+BCh] [ebp+8h]

  m_elt_buffer = m->m_elt_buffer;
  v2 = inverted;
  v31 = m->m_elt_buffer;
  ma = m->m_elt_buffer;
  v33 = inverted;
  v3 = inverted;
  for ( i = 19; i >= 0; --i )
  {
    *v3 = 0.0;
    v3[1] = 0.0;
    v3 += 2;
  }
  inverted[0] = 1.0;
  inverted[9] = 1.0;
  inverted[18] = 1.0;
  inverted[27] = 1.0;
  inverted[36] = 1.0;
  v5 = 0;
  while ( 1 )
  {
    v6 = &m_elt_buffer[v5];
    v7 = 1.0 / *v6;
    v8 = v5;
    do
    {
      m_elt_buffer[v8] = m_elt_buffer[v8] * v7;
      ++v8;
    }
    while ( v8 < 5 );
    v9 = 0;
    do
    {
      v2[v9] = v2[v9] * v7;
      ++v9;
    }
    while ( v9 <= v5 );
    v10 = v5 + 1;
    v32 = (char *)(v5 + 1);
    if ( v5 + 1 < 5 )
    {
      v11 = 0;
      j = 5 - v10;
      do
      {
        v12 = v6[8];
        v6 += 8;
        v2 += 8;
        v11 -= 8;
        if ( v12 != 0.0 )
        {
          v13 = 0;
          v14 = v2;
          do
          {
            *v14 = *v14 - (float)(v14[v11] * v12);
            ++v13;
            ++v14;
          }
          while ( v13 <= v5 );
          v15 = v5;
          v16 = v6;
          do
          {
            *v16 = *v16 - (float)(v16[v11] * v12);
            ++v15;
            ++v16;
          }
          while ( v15 < 5 );
          v10 = (int)v32;
        }
        --j;
      }
      while ( j != 0 );
      v2 = v33;
    }
    ma += 8;
    v2 += 8;
    v5 = v10;
    v33 = v2;
    if ( v10 >= 5 )
      break;
    m_elt_buffer = ma;
  }
  v17 = 4;
  for ( j = 0; j >= -16; j -= 4 )
  {
    v18 = v17 - 1;
    v19 = ma - 8;
    v2 -= 8;
    ma -= 8;
    v30 = v17 - 1;
    v33 = (float *)(v17 - 1);
    if ( v17 - 1 >= 0 )
    {
      v20 = 0;
      v21 = v19 + 4;
      v32 = (char *)((char *)v2 - (char *)v19);
      do
      {
        v22 = *(float *)((char *)v21 + j - 32);
        v21 -= 8;
        v20 += 8;
        if ( v22 != 0.0 )
        {
          v23 = 4;
          v24 = (float *)&v32[(_DWORD)v21];
          do
          {
            *v24 = *v24 - (float)(v24[v20] * v22);
            --v24;
            --v23;
          }
          while ( v23 >= 0 );
          v25 = 4;
          v26 = v21;
          do
          {
            *v26 = *v26 - (float)(v26[v20] * v22);
            --v25;
            --v26;
          }
          while ( v25 >= v17 );
        }
        v33 = (float *)((char *)v33 - 1);
      }
      while ( (int)v33 >= 0 );
      v18 = v30;
    }
    v17 = v18;
  }
  v27 = v31;
  qmemcpy(v31, inverted, 20);
  v27[8] = inverted[8];
  v27[9] = inverted[9];
  v27[10] = inverted[10];
  v27[11] = inverted[11];
  v27[12] = inverted[12];
  v27[16] = inverted[16];
  v27[17] = inverted[17];
  v27[18] = inverted[18];
  v27[19] = inverted[19];
  v27[20] = inverted[20];
  v27[24] = inverted[24];
  v27[25] = inverted[25];
  v27[26] = inverted[26];
  v27[27] = inverted[27];
  v27[28] = inverted[28];
  v27[32] = inverted[32];
  v27[33] = inverted[33];
  v27[34] = inverted[34];
  v27[35] = inverted[35];
  v27[36] = inverted[36];
  return HK_OK;
}

//------------------------------------------------------------------------------
// Address: 0x10044B50
// Name: public: static enum hk_result hk_Dense_Matrix_Util::invert_3x3_symmetric(class hk_Dense_Matrix __near &,float)
// Source: json
//------------------------------------------------------------------------------
int __cdecl hk_Dense_Matrix_Util::invert_3x3_symmetric(hk_Dense_Matrix *m, float tolerance)
{
  float *m_elt; // ecx
  float v3; // xmm0_4
  unsigned int m_lda; // edx
  float v5; // xmm3_4
  float v6; // xmm4_4
  float v7; // xmm5_4
  float *v8; // eax
  float v9; // xmm7_4
  float v10; // xmm1_4
  float *v11; // esi
  float v12; // xmm3_4
  float v13; // xmm2_4
  float v14; // xmm5_4
  float v15; // xmm4_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // xmm6_4
  float r2; // [esp+0h] [ebp-24h]
  float r2_8; // [esp+8h] [ebp-1Ch]
  float r1; // [esp+10h] [ebp-14h]
  float r1_4; // [esp+14h] [ebp-10h]
  float r1_8; // [esp+18h] [ebp-Ch]
  float ma; // [esp+2Ch] [ebp+8h]

  m_elt = m->m_elt;
  v3 = m->m_elt[2];
  m_lda = m->m_lda;
  v5 = m->m_elt[m_lda + 1];
  v6 = m->m_elt[m_lda + 2];
  v7 = m->m_elt[m_lda];
  v8 = &m->m_elt[m_lda];
  v9 = v8[m_lda + 2];
  v10 = v8[m_lda + 1];
  ma = v8[m_lda];
  v11 = &v8[m_lda + 1];
  v12 = (float)(v5 * v9) - (float)(v6 * v10);
  v13 = v7 * v9;
  v14 = (float)(v7 * v10) - (float)(ma * v8[1]);
  v15 = (float)(ma * v8[2]) - v13;
  v16 = m_elt[1];
  r1 = (float)(v3 * v10) - (float)(v16 * v9);
  r1_4 = (float)(*m_elt * v9) - (float)(v3 * ma);
  r1_8 = (float)(v16 * ma) - (float)(*m_elt * *v11);
  r2_8 = (float)(*m_elt * v8[1]) - (float)(v16 * *v8);
  r2 = (float)(v16 * v8[2]) - (float)(v3 * v8[1]);
  v17 = (float)(v3 * *v8) - (float)(*m_elt * v8[2]);
  v18 = (float)((float)(*m_elt * v12) + (float)(v15 * v16)) + (float)(m_elt[2] * v14);
  if ( (float)((float)(tolerance * tolerance) * tolerance) > COERCE_FLOAT(LODWORD(v18) & _mask__AbsFloat_) )
    return 1;
  *m_elt = v12 * (float)(1.0 / v18);
  m_elt[1] = v15 * (float)(1.0 / v18);
  m_elt[2] = v14 * (float)(1.0 / v18);
  *v8 = r1 * (float)(1.0 / v18);
  v8[1] = r1_4 * (float)(1.0 / v18);
  v8[2] = r1_8 * (float)(1.0 / v18);
  *v11 = v17 * (float)(1.0 / v18);
  v8[m_lda + 2] = r2_8 * (float)(1.0 / v18);
  v8[m_lda] = r2 * (float)(1.0 / v18);
  return 0;
}
