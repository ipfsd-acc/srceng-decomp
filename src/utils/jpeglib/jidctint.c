// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jidctint.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10013530
// Name: _jpeg_idct_islow
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_idct_islow(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        __int16 *coef_block,
        unsigned __int8 **output_buf,
        unsigned int output_col)
{
  __int16 *v5; // esi
  _DWORD *dct_table; // edi
  unsigned __int8 *v7; // edx
  int *v8; // eax
  int v9; // ecx
  int v10; // ecx
  int v11; // edx
  int v12; // ebx
  int v13; // edx
  int v14; // ecx
  int v15; // edx
  int v16; // ecx
  int v17; // ebx
  int v18; // ecx
  int v19; // edx
  int v20; // esi
  int v21; // ecx
  int v22; // ebx
  int v23; // edx
  int v24; // esi
  int v25; // ebx
  int v26; // edi
  int v27; // ebx
  int v28; // edi
  int v29; // esi
  int v30; // edi
  int v31; // esi
  int v32; // edx
  int v33; // edi
  int *v34; // ecx
  unsigned __int8 *v35; // eax
  unsigned __int8 v36; // bl
  int v37; // edx
  int v38; // esi
  int v39; // edi
  int v40; // edx
  int v41; // ebx
  int v42; // edi
  int v43; // esi
  int v44; // edi
  int v45; // edx
  int v46; // ebx
  int v47; // ebx
  int v48; // ebx
  int v49; // esi
  int v50; // esi
  int v51; // ebx
  int v52; // esi
  int v53; // esi
  __int16 *v54; // esi
  int workspace[64]; // [esp+Ch] [ebp-134h] BYREF
  int tmp13; // [esp+10Ch] [ebp-34h]
  int tmp10; // [esp+110h] [ebp-30h]
  unsigned __int8 *range_limit; // [esp+114h] [ebp-2Ch]
  int tmp12; // [esp+118h] [ebp-28h]
  int tmp11; // [esp+11Ch] [ebp-24h]
  int v61; // [esp+120h] [ebp-20h]
  int z5; // [esp+124h] [ebp-1Ch]
  int ctr; // [esp+128h] [ebp-18h]
  int z4; // [esp+12Ch] [ebp-14h]
  int z2; // [esp+130h] [ebp-10h]
  __int16 *inptr; // [esp+134h] [ebp-Ch]
  int tmp2; // [esp+138h] [ebp-8h]
  int z3; // [esp+13Ch] [ebp-4h]
  int z1; // [esp+148h] [ebp+8h]
  int z1a; // [esp+148h] [ebp+8h]
  int z1b; // [esp+148h] [ebp+8h]
  int tmp3; // [esp+14Ch] [ebp+Ch]
  int tmp3a; // [esp+14Ch] [ebp+Ch]
  int tmp3b; // [esp+14Ch] [ebp+Ch]
  int tmp3c; // [esp+14Ch] [ebp+Ch]
  int tmp1; // [esp+150h] [ebp+10h]
  int tmp1a; // [esp+150h] [ebp+10h]
  int tmp1b; // [esp+150h] [ebp+10h]
  int tmp1c; // [esp+150h] [ebp+10h]

  v5 = coef_block;
  dct_table = compptr->dct_table;
  v7 = cinfo->sample_range_limit + 128;
  range_limit = v7;
  inptr = coef_block;
  tmp2 = (int)dct_table;
  v8 = workspace;
  for ( ctr = 8; ctr > 0; --ctr )
  {
    v61 = (unsigned __int16)v5[8];
    if ( (_WORD)v61 != 0 || v5[16] != 0 || v5[24] != 0 || v5[32] != 0 || v5[40] != 0 || v5[48] != 0 || v5[56] != 0 )
    {
      v10 = dct_table[16] * v5[16];
      v11 = dct_table[48] * v5[48];
      z1 = 4433 * (v11 + v10);
      v12 = z1 - 15137 * v11;
      v13 = *dct_table * *v5;
      tmp3 = z1 + 6270 * v10;
      z3 = dct_table[32] * v5[32];
      v14 = (v13 + z3) << 13;
      tmp1 = (v13 - z3) << 13;
      tmp10 = v14 + tmp3;
      tmp13 = v14 - tmp3;
      v15 = tmp1 + v12;
      v16 = tmp1 - v12;
      v17 = dct_table[8] * (__int16)v61;
      tmp12 = v16;
      v18 = dct_table[56] * v5[56];
      tmp11 = v15;
      v19 = dct_table[40] * v5[40];
      v20 = dct_table[24] * v5[24];
      tmp3a = v17;
      z4 = v19 + v17;
      z5 = 9633 * (v18 + v20 + v19 + v17);
      z1a = -7373 * (v18 + v17);
      z2 = -20995 * (v19 + v20);
      z3 = z5 - 16069 * (v18 + v20);
      v21 = z3 + z1a + 2446 * v18;
      v22 = z5 - 3196 * (v19 + v17);
      v23 = z2 + v22 + 16819 * v19;
      v24 = z2 + z3 + 25172 * v20;
      tmp3b = z1a + 12299 * tmp3a + v22;
      v25 = (tmp10 + tmp3b + 1024) >> 11;
      v8[56] = (tmp10 - tmp3b + 1024) >> 11;
      v26 = tmp11;
      *v8 = v25;
      v27 = v26 + v24 + 1024;
      v28 = v26 - v24;
      v29 = tmp12;
      v8[48] = (v28 + 1024) >> 11;
      v30 = v29 + v23 + 1024;
      v31 = v29 - v23;
      v32 = tmp13;
      v8[40] = (v31 + 1024) >> 11;
      v8[16] = v30 >> 11;
      dct_table = (_DWORD *)tmp2;
      v8[24] = (v32 + v21 + 1024) >> 11;
      v5 = inptr;
      v8[32] = (v32 - v21 + 1024) >> 11;
      v7 = range_limit;
      v8[8] = v27 >> 11;
    }
    else
    {
      v9 = 4 * *dct_table * *v5;
      *v8 = v9;
      v8[8] = v9;
      v8[16] = v9;
      v8[24] = v9;
      v8[32] = v9;
      v8[40] = v9;
      v8[48] = v9;
      v8[56] = v9;
    }
    ++v5;
    ++dct_table;
    ++v8;
    tmp2 = (int)dct_table;
    inptr = v5;
  }
  v33 = 0;
  v34 = workspace;
  ctr = 0;
  do
  {
    v35 = &output_buf[v33][output_col];
    v61 = v34[1];
    if ( v61 != 0 || v34[2] != 0 || v34[3] != 0 || v34[4] != 0 || v34[5] != 0 || v34[6] != 0 || v34[7] != 0 )
    {
      v37 = v34[2];
      v38 = v34[6];
      v39 = 4433 * (v38 + v37);
      tmp3c = v39 + 6270 * v37;
      v40 = v34[4];
      v41 = v39 - 15137 * v38;
      v42 = (*v34 + v40) << 13;
      tmp1a = (*v34 - v40) << 13;
      v43 = v42 + tmp3c;
      v44 = v42 - tmp3c;
      tmp11 = v41 + tmp1a;
      v45 = tmp1a - v41;
      v46 = v34[5];
      tmp12 = v45;
      inptr = (__int16 *)v34[7];
      tmp1b = v46;
      v47 = v34[3];
      z5 = 9633 * ((_DWORD)inptr + v47 + tmp1b + v61);
      z1b = -7373 * ((_DWORD)inptr + v61);
      z2 = -20995 * (v47 + tmp1b);
      z3 = z5 - 16069 * ((_DWORD)inptr + v47);
      z4 = z5 - 3196 * (tmp1b + v61);
      inptr = (__int16 *)(z3 + z1b + 2446 * (_DWORD)inptr);
      tmp1c = z2 + z4 + 16819 * tmp1b;
      tmp2 = z2 + z3 + 25172 * v47;
      v48 = ((v43 + z1b + z4 + 12299 * v61 + 0x20000) >> 18) & 0x3FF;
      v7 = range_limit;
      v49 = v43 - (z1b + z4 + 12299 * v61) + 0x20000;
      *v35 = range_limit[v48];
      LOBYTE(v48) = v7[(v49 >> 18) & 0x3FF];
      v50 = tmp11;
      v35[7] = v48;
      v51 = v50 + tmp2 + 0x20000;
      v52 = v50 - tmp2 + 0x20000;
      v35[1] = v7[(v51 >> 18) & 0x3FF];
      LOBYTE(v51) = v7[(v52 >> 18) & 0x3FF];
      v53 = tmp12;
      v35[6] = v51;
      v35[2] = v7[((v53 + tmp1c + 0x20000) >> 18) & 0x3FF];
      LOBYTE(v51) = v7[((v53 - tmp1c + 0x20000) >> 18) & 0x3FF];
      v54 = inptr;
      v35[5] = v51;
      v35[3] = v7[(((int)v54 + v44 + 0x20000) >> 18) & 0x3FF];
      v36 = v7[((v44 - (int)v54 + 0x20000) >> 18) & 0x3FF];
      v33 = ctr;
    }
    else
    {
      v36 = v7[((*v34 + 16) >> 5) & 0x3FF];
      *v35 = v36;
      v35[1] = v36;
      v35[2] = v36;
      v35[3] = v36;
      v35[5] = v36;
      v35[6] = v36;
      v35[7] = v36;
    }
    ++v33;
    v34 += 8;
    v35[4] = v36;
    ctr = v33;
  }
  while ( v33 < 8 );
}

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1027C290
// Name: _jpeg_idct_islow
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_idct_islow(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        __int16 *coef_block,
        unsigned __int8 **output_buf,
        unsigned int output_col)
{
  __int16 *v5; // esi
  _DWORD *dct_table; // edi
  unsigned __int8 *v7; // edx
  int *v8; // eax
  int v9; // ecx
  int v10; // ecx
  int v11; // edx
  int v12; // ebx
  int v13; // edx
  int v14; // ecx
  int v15; // edx
  int v16; // ecx
  int v17; // ebx
  int v18; // ecx
  int v19; // edx
  int v20; // esi
  int v21; // ecx
  int v22; // ebx
  int v23; // edx
  int v24; // esi
  int v25; // ebx
  int v26; // edi
  int v27; // ebx
  int v28; // edi
  int v29; // esi
  int v30; // edi
  int v31; // esi
  int v32; // edx
  int v33; // edi
  int *v34; // ecx
  unsigned __int8 *v35; // eax
  unsigned __int8 v36; // bl
  int v37; // edx
  int v38; // esi
  int v39; // edi
  int v40; // edx
  int v41; // ebx
  int v42; // edi
  int v43; // esi
  int v44; // edi
  int v45; // edx
  int v46; // ebx
  int v47; // ebx
  int v48; // ebx
  int v49; // esi
  int v50; // esi
  int v51; // ebx
  int v52; // esi
  int v53; // esi
  __int16 *v54; // esi
  int workspace[64]; // [esp+Ch] [ebp-134h] BYREF
  int tmp13; // [esp+10Ch] [ebp-34h]
  int tmp10; // [esp+110h] [ebp-30h]
  unsigned __int8 *range_limit; // [esp+114h] [ebp-2Ch]
  int tmp12; // [esp+118h] [ebp-28h]
  int tmp11; // [esp+11Ch] [ebp-24h]
  int v61; // [esp+120h] [ebp-20h]
  int z5; // [esp+124h] [ebp-1Ch]
  int ctr; // [esp+128h] [ebp-18h]
  int z4; // [esp+12Ch] [ebp-14h]
  int z2; // [esp+130h] [ebp-10h]
  __int16 *inptr; // [esp+134h] [ebp-Ch]
  int tmp2; // [esp+138h] [ebp-8h]
  int z3; // [esp+13Ch] [ebp-4h]
  int z1; // [esp+148h] [ebp+8h]
  int z1a; // [esp+148h] [ebp+8h]
  int z1b; // [esp+148h] [ebp+8h]
  int tmp3; // [esp+14Ch] [ebp+Ch]
  int tmp3a; // [esp+14Ch] [ebp+Ch]
  int tmp3b; // [esp+14Ch] [ebp+Ch]
  int tmp3c; // [esp+14Ch] [ebp+Ch]
  int tmp1; // [esp+150h] [ebp+10h]
  int tmp1a; // [esp+150h] [ebp+10h]
  int tmp1b; // [esp+150h] [ebp+10h]
  int tmp1c; // [esp+150h] [ebp+10h]

  v5 = coef_block;
  dct_table = compptr->dct_table;
  v7 = cinfo->sample_range_limit + 128;
  range_limit = v7;
  inptr = coef_block;
  tmp2 = (int)dct_table;
  v8 = workspace;
  for ( ctr = 8; ctr > 0; --ctr )
  {
    v61 = (unsigned __int16)v5[8];
    if ( (_WORD)v61 != 0 || v5[16] != 0 || v5[24] != 0 || v5[32] != 0 || v5[40] != 0 || v5[48] != 0 || v5[56] != 0 )
    {
      v10 = dct_table[16] * v5[16];
      v11 = dct_table[48] * v5[48];
      z1 = 4433 * (v11 + v10);
      v12 = z1 - 15137 * v11;
      v13 = *dct_table * *v5;
      tmp3 = z1 + 6270 * v10;
      z3 = dct_table[32] * v5[32];
      v14 = (v13 + z3) << 13;
      tmp1 = (v13 - z3) << 13;
      tmp10 = v14 + tmp3;
      tmp13 = v14 - tmp3;
      v15 = tmp1 + v12;
      v16 = tmp1 - v12;
      v17 = dct_table[8] * (__int16)v61;
      tmp12 = v16;
      v18 = dct_table[56] * v5[56];
      tmp11 = v15;
      v19 = dct_table[40] * v5[40];
      v20 = dct_table[24] * v5[24];
      tmp3a = v17;
      z4 = v19 + v17;
      z5 = 9633 * (v18 + v20 + v19 + v17);
      z1a = -7373 * (v18 + v17);
      z2 = -20995 * (v19 + v20);
      z3 = z5 - 16069 * (v18 + v20);
      v21 = z3 + z1a + 2446 * v18;
      v22 = z5 - 3196 * (v19 + v17);
      v23 = z2 + v22 + 16819 * v19;
      v24 = z2 + z3 + 25172 * v20;
      tmp3b = z1a + 12299 * tmp3a + v22;
      v25 = (tmp10 + tmp3b + 1024) >> 11;
      v8[56] = (tmp10 - tmp3b + 1024) >> 11;
      v26 = tmp11;
      *v8 = v25;
      v27 = v26 + v24 + 1024;
      v28 = v26 - v24;
      v29 = tmp12;
      v8[48] = (v28 + 1024) >> 11;
      v30 = v29 + v23 + 1024;
      v31 = v29 - v23;
      v32 = tmp13;
      v8[40] = (v31 + 1024) >> 11;
      v8[16] = v30 >> 11;
      dct_table = (_DWORD *)tmp2;
      v8[24] = (v32 + v21 + 1024) >> 11;
      v5 = inptr;
      v8[32] = (v32 - v21 + 1024) >> 11;
      v7 = range_limit;
      v8[8] = v27 >> 11;
    }
    else
    {
      v9 = 4 * *dct_table * *v5;
      *v8 = v9;
      v8[8] = v9;
      v8[16] = v9;
      v8[24] = v9;
      v8[32] = v9;
      v8[40] = v9;
      v8[48] = v9;
      v8[56] = v9;
    }
    ++v5;
    ++dct_table;
    ++v8;
    tmp2 = (int)dct_table;
    inptr = v5;
  }
  v33 = 0;
  v34 = workspace;
  ctr = 0;
  do
  {
    v35 = &output_buf[v33][output_col];
    v61 = v34[1];
    if ( v61 != 0 || v34[2] != 0 || v34[3] != 0 || v34[4] != 0 || v34[5] != 0 || v34[6] != 0 || v34[7] != 0 )
    {
      v37 = v34[2];
      v38 = v34[6];
      v39 = 4433 * (v38 + v37);
      tmp3c = v39 + 6270 * v37;
      v40 = v34[4];
      v41 = v39 - 15137 * v38;
      v42 = (*v34 + v40) << 13;
      tmp1a = (*v34 - v40) << 13;
      v43 = v42 + tmp3c;
      v44 = v42 - tmp3c;
      tmp11 = v41 + tmp1a;
      v45 = tmp1a - v41;
      v46 = v34[5];
      tmp12 = v45;
      inptr = (__int16 *)v34[7];
      tmp1b = v46;
      v47 = v34[3];
      z5 = 9633 * ((_DWORD)inptr + v47 + tmp1b + v61);
      z1b = -7373 * ((_DWORD)inptr + v61);
      z2 = -20995 * (v47 + tmp1b);
      z3 = z5 - 16069 * ((_DWORD)inptr + v47);
      z4 = z5 - 3196 * (tmp1b + v61);
      inptr = (__int16 *)(z3 + z1b + 2446 * (_DWORD)inptr);
      tmp1c = z2 + z4 + 16819 * tmp1b;
      tmp2 = z2 + z3 + 25172 * v47;
      v48 = ((v43 + z1b + z4 + 12299 * v61 + 0x20000) >> 18) & 0x3FF;
      v7 = range_limit;
      v49 = v43 - (z1b + z4 + 12299 * v61) + 0x20000;
      *v35 = range_limit[v48];
      LOBYTE(v48) = v7[(v49 >> 18) & 0x3FF];
      v50 = tmp11;
      v35[7] = v48;
      v51 = v50 + tmp2 + 0x20000;
      v52 = v50 - tmp2 + 0x20000;
      v35[1] = v7[(v51 >> 18) & 0x3FF];
      LOBYTE(v51) = v7[(v52 >> 18) & 0x3FF];
      v53 = tmp12;
      v35[6] = v51;
      v35[2] = v7[((v53 + tmp1c + 0x20000) >> 18) & 0x3FF];
      LOBYTE(v51) = v7[((v53 - tmp1c + 0x20000) >> 18) & 0x3FF];
      v54 = inptr;
      v35[5] = v51;
      v35[3] = v7[(((int)v54 + v44 + 0x20000) >> 18) & 0x3FF];
      v36 = v7[((v44 - (int)v54 + 0x20000) >> 18) & 0x3FF];
      v33 = ctr;
    }
    else
    {
      v36 = v7[((*v34 + 16) >> 5) & 0x3FF];
      *v35 = v36;
      v35[1] = v36;
      v35[2] = v36;
      v35[3] = v36;
      v35[5] = v36;
      v35[6] = v36;
      v35[7] = v36;
    }
    ++v33;
    v34 += 8;
    v35[4] = v36;
    ctr = v33;
  }
  while ( v33 < 8 );
}

} // namespace client
