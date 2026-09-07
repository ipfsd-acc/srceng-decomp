// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jidctred.c
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10014230
// Name: _jpeg_idct_4x4
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_idct_4x4(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        __int16 *coef_block,
        unsigned __int8 **output_buf,
        unsigned int output_col)
{
  _DWORD *dct_table; // edx
  __int16 *v6; // esi
  int v7; // ecx
  int *v8; // ebx
  int v9; // eax
  int v10; // ebx
  int v11; // eax
  int v12; // ecx
  int v13; // edi
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // ecx
  int v18; // eax
  int v19; // edi
  int v20; // eax
  int v21; // esi
  int *v22; // ecx
  unsigned __int8 *v23; // eax
  int v24; // edx
  unsigned __int8 v25; // dl
  int v26; // eax
  int v27; // edi
  int v28; // esi
  int v29; // edi
  int v30; // eax
  _BYTE *v31; // edx
  unsigned __int8 v32; // bl
  int v33; // esi
  int v34; // edi
  unsigned __int8 *v35; // eax
  unsigned __int8 v36; // bl
  int workspace[32]; // [esp+Ch] [ebp-90h] BYREF
  int *v38; // [esp+8Ch] [ebp-10h]
  int tmp12; // [esp+90h] [ebp-Ch]
  int z2; // [esp+94h] [ebp-8h]
  unsigned __int8 *range_limit; // [esp+98h] [ebp-4h]
  int tmp2; // [esp+A4h] [ebp+8h]
  int tmp2a; // [esp+A4h] [ebp+8h]
  int tmp2b; // [esp+A4h] [ebp+8h]
  int tmp2c; // [esp+A4h] [ebp+8h]
  int ctr; // [esp+A8h] [ebp+Ch]
  int ctra; // [esp+A8h] [ebp+Ch]
  int z3; // [esp+ACh] [ebp+10h]
  int z3a; // [esp+ACh] [ebp+10h]

  dct_table = compptr->dct_table;
  range_limit = cinfo->sample_range_limit + 128;
  v6 = coef_block + 48;
  v7 = 8;
  v8 = &workspace[8];
  ctr = 8;
  v38 = &workspace[8];
  do
  {
    if ( v7 != 4 )
    {
      if ( *(v6 - 40) != 0 || *(v6 - 32) != 0 || *(v6 - 24) != 0 || *(v6 - 8) != 0 || *v6 != 0 || v6[8] != 0 )
      {
        v10 = dct_table[24] * *(v6 - 24);
        v11 = (*dct_table * *(v6 - 48)) << 14;
        v12 = 15137 * dct_table[16] * *(v6 - 32) - 6270 * dct_table[48] * *v6;
        v13 = v12 + v11;
        v14 = v11 - v12;
        v15 = dct_table[40] * *(v6 - 8);
        tmp12 = v14;
        tmp2 = dct_table[56] * v6[8];
        v16 = dct_table[8] * *(v6 - 40);
        z3 = v10;
        z2 = v15;
        v17 = 8697 * v16 + 11893 * v15 - 17799 * v10 - 1730 * tmp2;
        v8 = v38;
        tmp2a = 7373 * z3 + 20995 * v16 - 4926 * z2 - 4176 * tmp2;
        *(v38 - 8) = (v13 + tmp2a + 2048) >> 12;
        v18 = tmp12;
        v8[16] = (v13 - tmp2a + 2048) >> 12;
        v19 = v18 + v17 + 2048;
        v20 = v18 - v17;
        v7 = ctr;
        *v8 = v19 >> 12;
        v9 = (v20 + 2048) >> 12;
      }
      else
      {
        v9 = 4 * *dct_table * *(v6 - 48);
        *(v8 - 8) = v9;
        *v8 = v9;
        v8[16] = v9;
      }
      v8[8] = v9;
    }
    --v7;
    ++v8;
    ++v6;
    ++dct_table;
    v38 = v8;
    ctr = v7;
  }
  while ( v7 > 0 );
  v21 = 0;
  v22 = workspace;
  ctra = 0;
  do
  {
    v23 = &output_buf[v21][output_col];
    v24 = v22[1];
    tmp12 = (int)v23;
    if ( v24 != 0 || v22[2] != 0 || v22[3] != 0 || v22[5] != 0 || v22[6] != 0 || v22[7] != 0 )
    {
      v26 = 15137 * v22[2] - 6270 * v22[6];
      z3a = v22[3];
      v27 = *v22 << 14;
      v28 = v26 + v27;
      v29 = v27 - v26;
      tmp2b = v22[7];
      z2 = v22[5];
      v30 = 8697 * v24 + 11893 * z2 - 17799 * z3a - 1730 * tmp2b;
      tmp2c = 7373 * z3a + 20995 * v24 - 4926 * z2 - 4176 * tmp2b;
      v31 = (_BYTE *)tmp12;
      *(_BYTE *)tmp12 = range_limit[((v28 + tmp2c + 0x40000) >> 19) & 0x3FF];
      v32 = range_limit[((v28 - tmp2c + 0x40000) >> 19) & 0x3FF];
      v33 = v29 + v30 + 0x40000;
      v34 = v29 - v30;
      v35 = range_limit;
      v31[3] = v32;
      v36 = range_limit[(v33 >> 19) & 0x3FF];
      v21 = ctra;
      v31[1] = v36;
      v31[2] = v35[((v34 + 0x40000) >> 19) & 0x3FF];
    }
    else
    {
      v25 = range_limit[((*v22 + 16) >> 5) & 0x3FF];
      *v23 = v25;
      v23[1] = v25;
      v23[2] = v25;
      v23[3] = v25;
    }
    ++v21;
    v22 += 8;
    ctra = v21;
  }
  while ( v21 < 4 );
}

//------------------------------------------------------------------------------
// Address: 0x10014520
// Name: _jpeg_idct_2x2
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_idct_2x2(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        __int16 *coef_block,
        unsigned __int8 **output_buf,
        unsigned int output_col)
{
  _DWORD *dct_table; // ecx
  __int16 *v6; // eax
  int v7; // esi
  int *v8; // edi
  int v9; // edx
  int v10; // esi
  int v11; // edx
  int v12; // ebx
  int v13; // edx
  int v14; // edx
  int v15; // esi
  int v16; // edx
  int v17; // ebx
  int v18; // edx
  int v19; // edx
  int v20; // esi
  int v21; // edx
  int v22; // ebx
  int v23; // edx
  int v24; // edx
  int v25; // esi
  int v26; // edx
  int v27; // ebx
  int v28; // edx
  unsigned __int8 *v29; // edx
  unsigned __int8 v30; // al
  unsigned __int8 *v31; // edi
  int v32; // esi
  int v33; // eax
  int v34; // esi
  int v35; // edi
  int v36; // ebx
  unsigned __int8 *v37; // edx
  unsigned __int8 v38; // al
  int v39; // ecx
  unsigned __int8 *v40; // edi
  int v41; // esi
  int v42; // eax
  int workspace[16]; // [esp+Ch] [ebp-44h] BYREF
  unsigned __int8 *range_limit; // [esp+4Ch] [ebp-4h]
  int cinfoa; // [esp+58h] [ebp+8h]

  dct_table = compptr->dct_table;
  range_limit = cinfo->sample_range_limit + 128;
  v6 = coef_block + 24;
  v7 = 6;
  cinfoa = 6;
  v8 = &workspace[1];
  do
  {
    if ( v7 != 4 && v7 != 2 && v7 != 0 )
    {
      if ( *(v6 - 16) != 0 || *v6 != 0 || v6[16] != 0 || v6[32] != 0 )
      {
        v10 = 29692 * dct_table[8] * *(v6 - 16)
            + 6967 * dct_table[40] * v6[16]
            - 5906 * dct_table[56] * v6[32]
            - 10426 * dct_table[24] * *v6;
        v11 = (*dct_table * *(v6 - 24)) << 15;
        v12 = v10 + v11 + 4096;
        v13 = v11 - v10;
        v7 = cinfoa;
        *(v8 - 1) = v12 >> 13;
        v9 = (v13 + 4096) >> 13;
      }
      else
      {
        v9 = 4 * *dct_table * *(v6 - 24);
        *(v8 - 1) = v9;
      }
      v8[7] = v9;
    }
    if ( v7 != 5 && v7 != 3 && v7 != 1 )
    {
      if ( *(v6 - 15) != 0 || v6[1] != 0 || v6[17] != 0 || v6[33] != 0 )
      {
        v15 = 29692 * dct_table[9] * *(v6 - 15)
            + 6967 * dct_table[41] * v6[17]
            - 5906 * dct_table[57] * v6[33]
            - 10426 * dct_table[25] * v6[1];
        v16 = (dct_table[1] * *(v6 - 23)) << 15;
        v17 = v15 + v16 + 4096;
        v18 = v16 - v15;
        v7 = cinfoa;
        *v8 = v17 >> 13;
        v14 = (v18 + 4096) >> 13;
      }
      else
      {
        v14 = 4 * dct_table[1] * *(v6 - 23);
        *v8 = v14;
      }
      v8[8] = v14;
    }
    if ( v7 != 6 && v7 != 4 && v7 != 2 )
    {
      if ( *(v6 - 14) != 0 || v6[2] != 0 || v6[18] != 0 || v6[34] != 0 )
      {
        v20 = 29692 * dct_table[10] * *(v6 - 14)
            + 6967 * dct_table[42] * v6[18]
            - 5906 * dct_table[58] * v6[34]
            - 10426 * dct_table[26] * v6[2];
        v21 = (dct_table[2] * *(v6 - 22)) << 15;
        v22 = v20 + v21 + 4096;
        v23 = v21 - v20;
        v7 = cinfoa;
        v8[1] = v22 >> 13;
        v19 = (v23 + 4096) >> 13;
      }
      else
      {
        v19 = 4 * dct_table[2] * *(v6 - 22);
        v8[1] = v19;
      }
      v8[9] = v19;
    }
    if ( v7 != 7 && v7 != 5 && v7 != 3 )
    {
      if ( *(v6 - 13) != 0 || v6[3] != 0 || v6[19] != 0 || v6[35] != 0 )
      {
        v25 = 29692 * dct_table[11] * *(v6 - 13)
            + 6967 * dct_table[43] * v6[19]
            - 5906 * dct_table[59] * v6[35]
            - 10426 * dct_table[27] * v6[3];
        v26 = (dct_table[3] * *(v6 - 21)) << 15;
        v27 = v25 + v26 + 4096;
        v28 = v26 - v25;
        v7 = cinfoa;
        v8[2] = v27 >> 13;
        v24 = (v28 + 4096) >> 13;
      }
      else
      {
        v24 = 4 * dct_table[3] * *(v6 - 21);
        v8[2] = v24;
      }
      v8[10] = v24;
    }
    v7 -= 4;
    v6 += 4;
    dct_table += 4;
    v8 += 4;
    cinfoa = v7;
  }
  while ( v7 + 2 > 0 );
  v29 = &(*output_buf)[output_col];
  if ( workspace[1] != 0 || workspace[3] != 0 || workspace[5] != 0 || workspace[7] != 0 )
  {
    v31 = range_limit;
    v32 = 6967 * workspace[5] + 29692 * workspace[1] - 10426 * workspace[3] - 5906 * workspace[7];
    v33 = (((workspace[0] << 15) - v32 + 0x80000) >> 20) & 0x3FF;
    *v29 = range_limit[((v32 + (workspace[0] << 15) + 0x80000) >> 20) & 0x3FF];
    v30 = v31[v33];
  }
  else
  {
    v30 = range_limit[((workspace[0] + 16) >> 5) & 0x3FF];
    *v29 = v30;
  }
  v34 = workspace[15];
  v35 = workspace[13];
  v36 = workspace[11];
  v29[1] = v30;
  v37 = &output_buf[1][output_col];
  if ( workspace[9] != 0 || v36 != 0 || v35 != 0 || v34 != 0 )
  {
    v39 = 6967 * v35 + 29692 * workspace[9];
    v40 = range_limit;
    v41 = v39 - 5906 * v34 - 10426 * v36;
    v42 = ((workspace[8] << 15) - v41 + 0x80000) >> 20;
    *v37 = range_limit[((v41 + (workspace[8] << 15) + 0x80000) >> 20) & 0x3FF];
    v37[1] = v40[v42 & 0x3FF];
  }
  else
  {
    v38 = range_limit[((workspace[8] + 16) >> 5) & 0x3FF];
    *v37 = v38;
    v37[1] = v38;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014980
// Name: _jpeg_idct_1x1
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_idct_1x1(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        __int16 *coef_block,
        unsigned __int8 **output_buf,
        unsigned int output_col)
{
  (*output_buf)[output_col] = cinfo->sample_range_limit[(((*(_DWORD *)compptr->dct_table * *coef_block + 4) >> 3) & 0x3FF)
                                                      + 128];
}

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1027CF90
// Name: _jpeg_idct_4x4
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_idct_4x4(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        __int16 *coef_block,
        unsigned __int8 **output_buf,
        unsigned int output_col)
{
  _DWORD *dct_table; // edx
  __int16 *v6; // esi
  int v7; // ecx
  int *v8; // ebx
  int v9; // eax
  int v10; // ebx
  int v11; // eax
  int v12; // ecx
  int v13; // edi
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // ecx
  int v18; // eax
  int v19; // edi
  int v20; // eax
  int v21; // esi
  int *v22; // ecx
  unsigned __int8 *v23; // eax
  int v24; // edx
  unsigned __int8 v25; // dl
  int v26; // eax
  int v27; // edi
  int v28; // esi
  int v29; // edi
  int v30; // eax
  _BYTE *v31; // edx
  unsigned __int8 v32; // bl
  int v33; // esi
  int v34; // edi
  unsigned __int8 *v35; // eax
  unsigned __int8 v36; // bl
  int workspace[32]; // [esp+Ch] [ebp-90h] BYREF
  int *v38; // [esp+8Ch] [ebp-10h]
  int tmp12; // [esp+90h] [ebp-Ch]
  int z2; // [esp+94h] [ebp-8h]
  unsigned __int8 *range_limit; // [esp+98h] [ebp-4h]
  int tmp2; // [esp+A4h] [ebp+8h]
  int tmp2a; // [esp+A4h] [ebp+8h]
  int tmp2b; // [esp+A4h] [ebp+8h]
  int tmp2c; // [esp+A4h] [ebp+8h]
  int ctr; // [esp+A8h] [ebp+Ch]
  int ctra; // [esp+A8h] [ebp+Ch]
  int z3; // [esp+ACh] [ebp+10h]
  int z3a; // [esp+ACh] [ebp+10h]

  dct_table = compptr->dct_table;
  range_limit = cinfo->sample_range_limit + 128;
  v6 = coef_block + 48;
  v7 = 8;
  v8 = &workspace[8];
  ctr = 8;
  v38 = &workspace[8];
  do
  {
    if ( v7 != 4 )
    {
      if ( *(v6 - 40) != 0 || *(v6 - 32) != 0 || *(v6 - 24) != 0 || *(v6 - 8) != 0 || *v6 != 0 || v6[8] != 0 )
      {
        v10 = dct_table[24] * *(v6 - 24);
        v11 = (*dct_table * *(v6 - 48)) << 14;
        v12 = 15137 * dct_table[16] * *(v6 - 32) - 6270 * dct_table[48] * *v6;
        v13 = v12 + v11;
        v14 = v11 - v12;
        v15 = dct_table[40] * *(v6 - 8);
        tmp12 = v14;
        tmp2 = dct_table[56] * v6[8];
        v16 = dct_table[8] * *(v6 - 40);
        z3 = v10;
        z2 = v15;
        v17 = 8697 * v16 + 11893 * v15 - 17799 * v10 - 1730 * tmp2;
        v8 = v38;
        tmp2a = 7373 * z3 + 20995 * v16 - 4926 * z2 - 4176 * tmp2;
        *(v38 - 8) = (v13 + tmp2a + 2048) >> 12;
        v18 = tmp12;
        v8[16] = (v13 - tmp2a + 2048) >> 12;
        v19 = v18 + v17 + 2048;
        v20 = v18 - v17;
        v7 = ctr;
        *v8 = v19 >> 12;
        v9 = (v20 + 2048) >> 12;
      }
      else
      {
        v9 = 4 * *dct_table * *(v6 - 48);
        *(v8 - 8) = v9;
        *v8 = v9;
        v8[16] = v9;
      }
      v8[8] = v9;
    }
    --v7;
    ++v8;
    ++v6;
    ++dct_table;
    v38 = v8;
    ctr = v7;
  }
  while ( v7 > 0 );
  v21 = 0;
  v22 = workspace;
  ctra = 0;
  do
  {
    v23 = &output_buf[v21][output_col];
    v24 = v22[1];
    tmp12 = (int)v23;
    if ( v24 != 0 || v22[2] != 0 || v22[3] != 0 || v22[5] != 0 || v22[6] != 0 || v22[7] != 0 )
    {
      v26 = 15137 * v22[2] - 6270 * v22[6];
      z3a = v22[3];
      v27 = *v22 << 14;
      v28 = v26 + v27;
      v29 = v27 - v26;
      tmp2b = v22[7];
      z2 = v22[5];
      v30 = 8697 * v24 + 11893 * z2 - 17799 * z3a - 1730 * tmp2b;
      tmp2c = 7373 * z3a + 20995 * v24 - 4926 * z2 - 4176 * tmp2b;
      v31 = (_BYTE *)tmp12;
      *(_BYTE *)tmp12 = range_limit[((v28 + tmp2c + 0x40000) >> 19) & 0x3FF];
      v32 = range_limit[((v28 - tmp2c + 0x40000) >> 19) & 0x3FF];
      v33 = v29 + v30 + 0x40000;
      v34 = v29 - v30;
      v35 = range_limit;
      v31[3] = v32;
      v36 = range_limit[(v33 >> 19) & 0x3FF];
      v21 = ctra;
      v31[1] = v36;
      v31[2] = v35[((v34 + 0x40000) >> 19) & 0x3FF];
    }
    else
    {
      v25 = range_limit[((*v22 + 16) >> 5) & 0x3FF];
      *v23 = v25;
      v23[1] = v25;
      v23[2] = v25;
      v23[3] = v25;
    }
    ++v21;
    v22 += 8;
    ctra = v21;
  }
  while ( v21 < 4 );
}

//------------------------------------------------------------------------------
// Address: 0x1027D280
// Name: _jpeg_idct_2x2
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_idct_2x2(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        __int16 *coef_block,
        unsigned __int8 **output_buf,
        unsigned int output_col)
{
  _DWORD *dct_table; // ecx
  __int16 *v6; // eax
  int v7; // esi
  int *v8; // edi
  int v9; // edx
  int v10; // esi
  int v11; // edx
  int v12; // ebx
  int v13; // edx
  int v14; // edx
  int v15; // esi
  int v16; // edx
  int v17; // ebx
  int v18; // edx
  int v19; // edx
  int v20; // esi
  int v21; // edx
  int v22; // ebx
  int v23; // edx
  int v24; // edx
  int v25; // esi
  int v26; // edx
  int v27; // ebx
  int v28; // edx
  unsigned __int8 *v29; // edx
  unsigned __int8 v30; // al
  unsigned __int8 *v31; // edi
  int v32; // esi
  int v33; // eax
  int v34; // esi
  int v35; // edi
  int v36; // ebx
  unsigned __int8 *v37; // edx
  unsigned __int8 v38; // al
  int v39; // ecx
  unsigned __int8 *v40; // edi
  int v41; // esi
  int v42; // eax
  int workspace[16]; // [esp+Ch] [ebp-44h] BYREF
  unsigned __int8 *range_limit; // [esp+4Ch] [ebp-4h]
  int cinfoa; // [esp+58h] [ebp+8h]

  dct_table = compptr->dct_table;
  range_limit = cinfo->sample_range_limit + 128;
  v6 = coef_block + 24;
  v7 = 6;
  cinfoa = 6;
  v8 = &workspace[1];
  do
  {
    if ( v7 != 4 && v7 != 2 && v7 != 0 )
    {
      if ( *(v6 - 16) != 0 || *v6 != 0 || v6[16] != 0 || v6[32] != 0 )
      {
        v10 = 29692 * dct_table[8] * *(v6 - 16)
            + 6967 * dct_table[40] * v6[16]
            - 5906 * dct_table[56] * v6[32]
            - 10426 * dct_table[24] * *v6;
        v11 = (*dct_table * *(v6 - 24)) << 15;
        v12 = v10 + v11 + 4096;
        v13 = v11 - v10;
        v7 = cinfoa;
        *(v8 - 1) = v12 >> 13;
        v9 = (v13 + 4096) >> 13;
      }
      else
      {
        v9 = 4 * *dct_table * *(v6 - 24);
        *(v8 - 1) = v9;
      }
      v8[7] = v9;
    }
    if ( v7 != 5 && v7 != 3 && v7 != 1 )
    {
      if ( *(v6 - 15) != 0 || v6[1] != 0 || v6[17] != 0 || v6[33] != 0 )
      {
        v15 = 29692 * dct_table[9] * *(v6 - 15)
            + 6967 * dct_table[41] * v6[17]
            - 5906 * dct_table[57] * v6[33]
            - 10426 * dct_table[25] * v6[1];
        v16 = (dct_table[1] * *(v6 - 23)) << 15;
        v17 = v15 + v16 + 4096;
        v18 = v16 - v15;
        v7 = cinfoa;
        *v8 = v17 >> 13;
        v14 = (v18 + 4096) >> 13;
      }
      else
      {
        v14 = 4 * dct_table[1] * *(v6 - 23);
        *v8 = v14;
      }
      v8[8] = v14;
    }
    if ( v7 != 6 && v7 != 4 && v7 != 2 )
    {
      if ( *(v6 - 14) != 0 || v6[2] != 0 || v6[18] != 0 || v6[34] != 0 )
      {
        v20 = 29692 * dct_table[10] * *(v6 - 14)
            + 6967 * dct_table[42] * v6[18]
            - 5906 * dct_table[58] * v6[34]
            - 10426 * dct_table[26] * v6[2];
        v21 = (dct_table[2] * *(v6 - 22)) << 15;
        v22 = v20 + v21 + 4096;
        v23 = v21 - v20;
        v7 = cinfoa;
        v8[1] = v22 >> 13;
        v19 = (v23 + 4096) >> 13;
      }
      else
      {
        v19 = 4 * dct_table[2] * *(v6 - 22);
        v8[1] = v19;
      }
      v8[9] = v19;
    }
    if ( v7 != 7 && v7 != 5 && v7 != 3 )
    {
      if ( *(v6 - 13) != 0 || v6[3] != 0 || v6[19] != 0 || v6[35] != 0 )
      {
        v25 = 29692 * dct_table[11] * *(v6 - 13)
            + 6967 * dct_table[43] * v6[19]
            - 5906 * dct_table[59] * v6[35]
            - 10426 * dct_table[27] * v6[3];
        v26 = (dct_table[3] * *(v6 - 21)) << 15;
        v27 = v25 + v26 + 4096;
        v28 = v26 - v25;
        v7 = cinfoa;
        v8[2] = v27 >> 13;
        v24 = (v28 + 4096) >> 13;
      }
      else
      {
        v24 = 4 * dct_table[3] * *(v6 - 21);
        v8[2] = v24;
      }
      v8[10] = v24;
    }
    v7 -= 4;
    v6 += 4;
    dct_table += 4;
    v8 += 4;
    cinfoa = v7;
  }
  while ( v7 + 2 > 0 );
  v29 = &(*output_buf)[output_col];
  if ( workspace[1] != 0 || workspace[3] != 0 || workspace[5] != 0 || workspace[7] != 0 )
  {
    v31 = range_limit;
    v32 = 6967 * workspace[5] + 29692 * workspace[1] - 10426 * workspace[3] - 5906 * workspace[7];
    v33 = (((workspace[0] << 15) - v32 + 0x80000) >> 20) & 0x3FF;
    *v29 = range_limit[((v32 + (workspace[0] << 15) + 0x80000) >> 20) & 0x3FF];
    v30 = v31[v33];
  }
  else
  {
    v30 = range_limit[((workspace[0] + 16) >> 5) & 0x3FF];
    *v29 = v30;
  }
  v34 = workspace[15];
  v35 = workspace[13];
  v36 = workspace[11];
  v29[1] = v30;
  v37 = &output_buf[1][output_col];
  if ( workspace[9] != 0 || v36 != 0 || v35 != 0 || v34 != 0 )
  {
    v39 = 6967 * v35 + 29692 * workspace[9];
    v40 = range_limit;
    v41 = v39 - 5906 * v34 - 10426 * v36;
    v42 = ((workspace[8] << 15) - v41 + 0x80000) >> 20;
    *v37 = range_limit[((v41 + (workspace[8] << 15) + 0x80000) >> 20) & 0x3FF];
    v37[1] = v40[v42 & 0x3FF];
  }
  else
  {
    v38 = range_limit[((workspace[8] + 16) >> 5) & 0x3FF];
    *v37 = v38;
    v37[1] = v38;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027D6E0
// Name: _jpeg_idct_1x1
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_idct_1x1(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        __int16 *coef_block,
        unsigned __int8 **output_buf,
        unsigned int output_col)
{
  (*output_buf)[output_col] = cinfo->sample_range_limit[(((*(_DWORD *)compptr->dct_table * *coef_block + 4) >> 3) & 0x3FF)
                                                      + 128];
}

} // namespace client
