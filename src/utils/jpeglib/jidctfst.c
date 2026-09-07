// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jidctfst.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10013A10
// Name: _jpeg_idct_ifast
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_idct_ifast(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        __int16 *coef_block,
        unsigned __int8 **output_buf,
        unsigned int output_col)
{
  _DWORD *dct_table; // edx
  unsigned __int8 *v7; // edi
  int *v8; // ecx
  int v9; // eax
  int v10; // edi
  int v11; // eax
  int v12; // ebx
  int v13; // edi
  int v14; // ebx
  int v15; // edi
  int v16; // eax
  int v17; // ebx
  int v18; // eax
  int v19; // eax
  int v20; // ebx
  int v21; // edi
  int v22; // eax
  int v23; // eax
  int v24; // edi
  int v25; // ebx
  int v26; // esi
  int *v27; // edx
  unsigned __int8 *v28; // eax
  unsigned __int8 v29; // cl
  int v30; // edi
  int v31; // esi
  int v32; // edi
  int v33; // ecx
  int v34; // ebx
  int v35; // ecx
  int v36; // esi
  int v37; // ebx
  int v38; // ecx
  int v39; // esi
  int v40; // edi
  int v41; // esi
  int v42; // edi
  int v43; // ecx
  int v44; // edi
  int v45; // ebx
  int v46; // esi
  int v47; // esi
  int v48; // esi
  int v49; // esi
  int workspace[64]; // [esp+Ch] [ebp-120h] BYREF
  unsigned __int8 *range_limit; // [esp+10Ch] [ebp-20h]
  int z12; // [esp+110h] [ebp-1Ch]
  int tmp0; // [esp+114h] [ebp-18h]
  int z13; // [esp+118h] [ebp-14h]
  int ctr; // [esp+11Ch] [ebp-10h]
  int tmp10; // [esp+120h] [ebp-Ch]
  int tmp3; // [esp+124h] [ebp-8h]
  int z5; // [esp+128h] [ebp-4h]
  int tmp7; // [esp+134h] [ebp+8h]
  int tmp2; // [esp+138h] [ebp+Ch]
  int tmp2a; // [esp+138h] [ebp+Ch]
  int tmp2b; // [esp+138h] [ebp+Ch]
  int z10; // [esp+13Ch] [ebp+10h]
  int z10a; // [esp+13Ch] [ebp+10h]
  int z10b; // [esp+13Ch] [ebp+10h]
  int z10c; // [esp+13Ch] [ebp+10h]
  int z10d; // [esp+13Ch] [ebp+10h]
  int z10e; // [esp+13Ch] [ebp+10h]

  dct_table = compptr->dct_table;
  v7 = cinfo->sample_range_limit + 128;
  range_limit = v7;
  v8 = workspace;
  for ( ctr = 8; ctr > 0; --ctr )
  {
    if ( coef_block[8] != 0
      || coef_block[16] != 0
      || coef_block[24] != 0
      || coef_block[32] != 0
      || coef_block[40] != 0
      || coef_block[48] != 0
      || coef_block[56] != 0 )
    {
      v10 = *dct_table * *coef_block;
      v11 = dct_table[16] * coef_block[16];
      tmp2 = dct_table[32] * coef_block[32];
      tmp3 = dct_table[48] * coef_block[48];
      v12 = v10 + tmp2;
      v13 = v10 - tmp2;
      tmp10 = v12;
      z10 = ((362 * (v11 - tmp3)) >> 8) - (v11 + tmp3);
      tmp0 = v12 + v11 + tmp3;
      tmp3 = v12 - (v11 + tmp3);
      v14 = z10 + v13;
      tmp2a = v13 - z10;
      v15 = dct_table[8] * coef_block[8];
      v16 = dct_table[24] * coef_block[24];
      tmp10 = v14;
      v17 = dct_table[56] * coef_block[56];
      z10a = v16;
      v18 = dct_table[40] * coef_block[40];
      z13 = v18 + z10a;
      z10b = v18 - z10a;
      v19 = v17 + v15;
      tmp7 = v17 + v15 + z13;
      z12 = v15 - v17;
      z5 = (473 * (z10b + v15 - v17)) >> 8;
      v20 = z5 + ((-669 * z10b) >> 8) - tmp7;
      z10c = ((362 * (v19 - z13)) >> 8) - v20;
      z5 = z10c + ((277 * z12) >> 8) - z5;
      v21 = tmp0;
      *v8 = tmp0 + tmp7;
      v8[56] = v21 - tmp7;
      v22 = v20 + tmp10;
      v8[48] = tmp10 - v20;
      v8[8] = v22;
      v23 = tmp3;
      v8[40] = tmp2a - z10c;
      v24 = z5;
      v8[16] = z10c + tmp2a;
      v25 = v24 + v23;
      v9 = v23 - v24;
      v7 = range_limit;
      v8[32] = v25;
    }
    else
    {
      v9 = *dct_table * *coef_block;
      *v8 = v9;
      v8[8] = v9;
      v8[16] = v9;
      v8[32] = v9;
      v8[40] = v9;
      v8[48] = v9;
      v8[56] = v9;
    }
    v8[24] = v9;
    ++coef_block;
    ++dct_table;
    ++v8;
  }
  v26 = 0;
  v27 = workspace;
  ctr = 0;
  do
  {
    v28 = &output_buf[v26][output_col];
    if ( v27[1] != 0 || v27[2] != 0 || v27[3] != 0 || v27[4] != 0 || v27[5] != 0 || v27[6] != 0 || v27[7] != 0 )
    {
      v30 = v27[4];
      v31 = *v27 + v30;
      v32 = *v27 - v30;
      v33 = v27[2];
      v34 = v33 + v27[6];
      z10d = ((362 * (v33 - v27[6])) >> 8) - v34;
      v35 = v34 + v31;
      v36 = v31 - v34;
      v37 = v27[7];
      tmp0 = v35;
      tmp3 = v36;
      v38 = v27[3];
      tmp10 = z10d + v32;
      v39 = v27[5];
      tmp2b = v32 - z10d;
      v40 = v39 + v38;
      v41 = v39 - v38;
      z13 = v40;
      v42 = v27[1];
      v43 = v37 + v42;
      v44 = v42 - v37;
      z5 = (473 * (v44 + v41)) >> 8;
      v45 = z5 + ((-669 * v41) >> 8) - (v43 + z13);
      z10e = ((362 * (v43 - z13)) >> 8) - v45;
      v46 = (tmp0 - (v43 + z13)) >> 5;
      z5 = z10e + ((277 * v44) >> 8) - z5;
      v7 = range_limit;
      *v28 = range_limit[((tmp0 + v43 + z13) >> 5) & 0x3FF];
      LOBYTE(v43) = v7[v46 & 0x3FF];
      v47 = tmp10;
      v28[7] = v43;
      v28[1] = v7[((v45 + v47) >> 5) & 0x3FF];
      v28[6] = v7[((v47 - v45) >> 5) & 0x3FF];
      v28[2] = v7[((z10e + tmp2b) >> 5) & 0x3FF];
      v48 = tmp3;
      v28[5] = v7[((tmp2b - z10e) >> 5) & 0x3FF];
      LOBYTE(v45) = v7[((z5 + v48) >> 5) & 0x3FF];
      v49 = ((v48 - z5) >> 5) & 0x3FF;
      v28[4] = v45;
      v29 = v7[v49];
      v26 = ctr;
    }
    else
    {
      v29 = v7[(*v27 >> 5) & 0x3FF];
      *v28 = v29;
      v28[1] = v29;
      v28[2] = v29;
      v28[4] = v29;
      v28[5] = v29;
      v28[6] = v29;
      v28[7] = v29;
    }
    ++v26;
    v27 += 8;
    v28[3] = v29;
    ctr = v26;
  }
  while ( v26 < 8 );
}

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1027C770
// Name: _jpeg_idct_ifast
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_idct_ifast(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        __int16 *coef_block,
        unsigned __int8 **output_buf,
        unsigned int output_col)
{
  _DWORD *dct_table; // edx
  unsigned __int8 *v7; // edi
  int *v8; // ecx
  int v9; // eax
  int v10; // edi
  int v11; // eax
  int v12; // ebx
  int v13; // edi
  int v14; // ebx
  int v15; // edi
  int v16; // eax
  int v17; // ebx
  int v18; // eax
  int v19; // eax
  int v20; // ebx
  int v21; // edi
  int v22; // eax
  int v23; // eax
  int v24; // edi
  int v25; // ebx
  int v26; // esi
  int *v27; // edx
  unsigned __int8 *v28; // eax
  unsigned __int8 v29; // cl
  int v30; // edi
  int v31; // esi
  int v32; // edi
  int v33; // ecx
  int v34; // ebx
  int v35; // ecx
  int v36; // esi
  int v37; // ebx
  int v38; // ecx
  int v39; // esi
  int v40; // edi
  int v41; // esi
  int v42; // edi
  int v43; // ecx
  int v44; // edi
  int v45; // ebx
  int v46; // esi
  int v47; // esi
  int v48; // esi
  int v49; // esi
  int workspace[64]; // [esp+Ch] [ebp-120h] BYREF
  unsigned __int8 *range_limit; // [esp+10Ch] [ebp-20h]
  int z12; // [esp+110h] [ebp-1Ch]
  int tmp0; // [esp+114h] [ebp-18h]
  int z13; // [esp+118h] [ebp-14h]
  int ctr; // [esp+11Ch] [ebp-10h]
  int tmp10; // [esp+120h] [ebp-Ch]
  int tmp3; // [esp+124h] [ebp-8h]
  int z5; // [esp+128h] [ebp-4h]
  int tmp7; // [esp+134h] [ebp+8h]
  int tmp2; // [esp+138h] [ebp+Ch]
  int tmp2a; // [esp+138h] [ebp+Ch]
  int tmp2b; // [esp+138h] [ebp+Ch]
  int z10; // [esp+13Ch] [ebp+10h]
  int z10a; // [esp+13Ch] [ebp+10h]
  int z10b; // [esp+13Ch] [ebp+10h]
  int z10c; // [esp+13Ch] [ebp+10h]
  int z10d; // [esp+13Ch] [ebp+10h]
  int z10e; // [esp+13Ch] [ebp+10h]

  dct_table = compptr->dct_table;
  v7 = cinfo->sample_range_limit + 128;
  range_limit = v7;
  v8 = workspace;
  for ( ctr = 8; ctr > 0; --ctr )
  {
    if ( coef_block[8] != 0
      || coef_block[16] != 0
      || coef_block[24] != 0
      || coef_block[32] != 0
      || coef_block[40] != 0
      || coef_block[48] != 0
      || coef_block[56] != 0 )
    {
      v10 = *dct_table * *coef_block;
      v11 = dct_table[16] * coef_block[16];
      tmp2 = dct_table[32] * coef_block[32];
      tmp3 = dct_table[48] * coef_block[48];
      v12 = v10 + tmp2;
      v13 = v10 - tmp2;
      tmp10 = v12;
      z10 = ((362 * (v11 - tmp3)) >> 8) - (v11 + tmp3);
      tmp0 = v12 + v11 + tmp3;
      tmp3 = v12 - (v11 + tmp3);
      v14 = z10 + v13;
      tmp2a = v13 - z10;
      v15 = dct_table[8] * coef_block[8];
      v16 = dct_table[24] * coef_block[24];
      tmp10 = v14;
      v17 = dct_table[56] * coef_block[56];
      z10a = v16;
      v18 = dct_table[40] * coef_block[40];
      z13 = v18 + z10a;
      z10b = v18 - z10a;
      v19 = v17 + v15;
      tmp7 = v17 + v15 + z13;
      z12 = v15 - v17;
      z5 = (473 * (z10b + v15 - v17)) >> 8;
      v20 = z5 + ((-669 * z10b) >> 8) - tmp7;
      z10c = ((362 * (v19 - z13)) >> 8) - v20;
      z5 = z10c + ((277 * z12) >> 8) - z5;
      v21 = tmp0;
      *v8 = tmp0 + tmp7;
      v8[56] = v21 - tmp7;
      v22 = v20 + tmp10;
      v8[48] = tmp10 - v20;
      v8[8] = v22;
      v23 = tmp3;
      v8[40] = tmp2a - z10c;
      v24 = z5;
      v8[16] = z10c + tmp2a;
      v25 = v24 + v23;
      v9 = v23 - v24;
      v7 = range_limit;
      v8[32] = v25;
    }
    else
    {
      v9 = *dct_table * *coef_block;
      *v8 = v9;
      v8[8] = v9;
      v8[16] = v9;
      v8[32] = v9;
      v8[40] = v9;
      v8[48] = v9;
      v8[56] = v9;
    }
    v8[24] = v9;
    ++coef_block;
    ++dct_table;
    ++v8;
  }
  v26 = 0;
  v27 = workspace;
  ctr = 0;
  do
  {
    v28 = &output_buf[v26][output_col];
    if ( v27[1] != 0 || v27[2] != 0 || v27[3] != 0 || v27[4] != 0 || v27[5] != 0 || v27[6] != 0 || v27[7] != 0 )
    {
      v30 = v27[4];
      v31 = *v27 + v30;
      v32 = *v27 - v30;
      v33 = v27[2];
      v34 = v33 + v27[6];
      z10d = ((362 * (v33 - v27[6])) >> 8) - v34;
      v35 = v34 + v31;
      v36 = v31 - v34;
      v37 = v27[7];
      tmp0 = v35;
      tmp3 = v36;
      v38 = v27[3];
      tmp10 = z10d + v32;
      v39 = v27[5];
      tmp2b = v32 - z10d;
      v40 = v39 + v38;
      v41 = v39 - v38;
      z13 = v40;
      v42 = v27[1];
      v43 = v37 + v42;
      v44 = v42 - v37;
      z5 = (473 * (v44 + v41)) >> 8;
      v45 = z5 + ((-669 * v41) >> 8) - (v43 + z13);
      z10e = ((362 * (v43 - z13)) >> 8) - v45;
      v46 = (tmp0 - (v43 + z13)) >> 5;
      z5 = z10e + ((277 * v44) >> 8) - z5;
      v7 = range_limit;
      *v28 = range_limit[((tmp0 + v43 + z13) >> 5) & 0x3FF];
      LOBYTE(v43) = v7[v46 & 0x3FF];
      v47 = tmp10;
      v28[7] = v43;
      v28[1] = v7[((v45 + v47) >> 5) & 0x3FF];
      v28[6] = v7[((v47 - v45) >> 5) & 0x3FF];
      v28[2] = v7[((z10e + tmp2b) >> 5) & 0x3FF];
      v48 = tmp3;
      v28[5] = v7[((tmp2b - z10e) >> 5) & 0x3FF];
      LOBYTE(v45) = v7[((z5 + v48) >> 5) & 0x3FF];
      v49 = ((v48 - z5) >> 5) & 0x3FF;
      v28[4] = v45;
      v29 = v7[v49];
      v26 = ctr;
    }
    else
    {
      v29 = v7[(*v27 >> 5) & 0x3FF];
      *v28 = v29;
      v28[1] = v29;
      v28[2] = v29;
      v28[4] = v29;
      v28[5] = v29;
      v28[6] = v29;
      v28[7] = v29;
    }
    ++v26;
    v27 += 8;
    v28[3] = v29;
    ctr = v26;
  }
  while ( v26 < 8 );
}

} // namespace client
