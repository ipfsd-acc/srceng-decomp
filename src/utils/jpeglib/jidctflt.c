// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jidctflt.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10013DD0
// Name: _jpeg_idct_float
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_idct_float(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        __int16 *coef_block,
        unsigned __int8 **output_buf,
        unsigned int output_col)
{
  float *dct_table; // edx
  unsigned __int8 *sample_range_limit; // esi
  float *v8; // eax
  __int16 v9; // di
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  int v13; // ebx
  float v14; // xmm4_4
  float v15; // xmm0_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  float v19; // xmm2_4
  float v20; // xmm4_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm6_4
  float v24; // xmm0_4
  float v25; // xmm6_4
  float v26; // xmm7_4
  float v27; // xmm5_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm6_4
  float v32; // xmm5_4
  float v33; // xmm0_4
  float v34; // xmm1_4
  int v35; // edi
  int v36; // edi
  float *v37; // ecx
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm0_4
  float v41; // xmm4_4
  float v42; // xmm3_4
  unsigned __int8 *v43; // eax
  float v44; // xmm1_4
  float v45; // xmm2_4
  float v46; // xmm0_4
  float v47; // xmm3_4
  float v48; // xmm4_4
  float v49; // xmm1_4
  float v50; // xmm0_4
  float v51; // xmm4_4
  float v52; // xmm7_4
  float v53; // xmm0_4
  float v54; // xmm1_4
  float v55; // xmm5_4
  float v56; // xmm4_4
  float v57; // xmm1_4
  unsigned __int8 *v58; // eax
  float v59; // xmm4_4
  float v60; // xmm0_4
  float v61; // xmm1_4
  float workspace[64]; // [esp+0h] [ebp-104h] BYREF
  int ctr; // [esp+100h] [ebp-4h]
  float z13; // [esp+10Ch] [ebp+8h]
  float z13a; // [esp+10Ch] [ebp+8h]
  float tmp3; // [esp+110h] [ebp+Ch]
  float tmp3a; // [esp+110h] [ebp+Ch]
  float tmp2; // [esp+114h] [ebp+10h]
  float tmp2a; // [esp+114h] [ebp+10h]

  dct_table = (float *)compptr->dct_table;
  sample_range_limit = cinfo->sample_range_limit;
  v8 = workspace;
  ctr = 8;
  do
  {
    v9 = coef_block[8];
    if ( v9 != 0
      || coef_block[16] != 0
      || coef_block[24] != 0
      || coef_block[32] != 0
      || coef_block[40] != 0
      || coef_block[48] != 0
      || coef_block[56] != 0 )
    {
      v11 = (float)*coef_block * *dct_table;
      v12 = (float)coef_block[16] * dct_table[16];
      v13 = coef_block[48];
      v14 = (float)((float)v13 * dct_table[48]) + v12;
      v15 = (float)((float)(v12 - (float)((float)v13 * dct_table[48])) * 1.4142135) - v14;
      v16 = (float)((float)coef_block[32] * dct_table[32]) + v11;
      v17 = v11 - (float)((float)coef_block[32] * dct_table[32]);
      v18 = v14 + v16;
      v19 = v16 - v14;
      v20 = v15 + v17;
      tmp2 = v17 - v15;
      tmp3 = v19;
      v21 = (float)v9 * dct_table[8];
      v22 = (float)coef_block[24] * dct_table[24];
      v23 = (float)coef_block[40] * dct_table[40];
      v24 = v23 - v22;
      v25 = v23 + v22;
      v26 = v24;
      v27 = (float)coef_block[56] * dct_table[56];
      v28 = v27 + v21;
      v29 = v21 - v27;
      v30 = (float)(v29 + v26) * 1.847759;
      z13 = v25;
      v31 = v28 + v25;
      v32 = (float)(v30 - (float)(v26 * 2.613126)) - v31;
      *v8 = v31 + v18;
      v33 = (float)((float)(v28 - z13) * 1.4142135) - v32;
      v34 = (float)((float)(v29 * 1.0823922) - v30) + v33;
      v8[56] = v18 - v31;
      v8[8] = v32 + v20;
      v8[40] = tmp2 - v33;
      v8[48] = v20 - v32;
      v8[16] = v33 + tmp2;
      v8[32] = v34 + tmp3;
      v10 = tmp3 - v34;
    }
    else
    {
      v10 = (float)*coef_block * *dct_table;
      *v8 = v10;
      v8[8] = v10;
      v8[16] = v10;
      v8[32] = v10;
      v8[40] = v10;
      v8[48] = v10;
      v8[56] = v10;
    }
    v35 = ctr - 1;
    v8[24] = v10;
    ++coef_block;
    ++dct_table;
    ++v8;
    ctr = v35;
  }
  while ( v35 > 0 );
  v36 = 0;
  v37 = &workspace[2];
  do
  {
    v38 = *(v37 - 2);
    v39 = v38 - v37[2];
    v40 = v38 + v37[2];
    v41 = v39;
    v42 = v37[4] + *v37;
    v43 = output_buf[v36];
    v44 = (float)((float)(*v37 - v37[4]) * 1.4142135) - v42;
    v45 = v42 + v40;
    v46 = v40 - v42;
    v47 = v44 + v41;
    v48 = v41 - v44;
    v49 = *(v37 - 1);
    tmp3a = v46;
    v50 = v37[3];
    tmp2a = v48;
    v51 = v37[1] + v50;
    v52 = v50 - v37[1];
    v53 = v37[5] + v49;
    v54 = v49 - v37[5];
    v55 = v53 + v51;
    z13a = v51;
    v56 = (float)(v54 + v52) * 1.847759;
    v57 = (float)(v54 * 1.0823922) - v56;
    v43[output_col] = sample_range_limit[((((int)(float)(v55 + v45) + 4) >> 3) & 0x3FF) + 128];
    v58 = &v43[output_col];
    v58[7] = sample_range_limit[((((int)(float)(v45 - v55) + 4) >> 3) & 0x3FF) + 128];
    v59 = (float)(v56 - (float)(v52 * 2.613126)) - v55;
    v58[1] = sample_range_limit[((((int)(float)(v59 + v47) + 4) >> 3) & 0x3FF) + 128];
    v60 = (float)((float)(v53 - z13a) * 1.4142135) - v59;
    v61 = v57 + v60;
    v58[6] = sample_range_limit[((((int)(float)(v47 - v59) + 4) >> 3) & 0x3FF) + 128];
    v58[2] = sample_range_limit[((((int)(float)(v60 + tmp2a) + 4) >> 3) & 0x3FF) + 128];
    v58[5] = sample_range_limit[((((int)(float)(tmp2a - v60) + 4) >> 3) & 0x3FF) + 128];
    v58[4] = sample_range_limit[((((int)(float)(v61 + tmp3a) + 4) >> 3) & 0x3FF) + 128];
    ++v36;
    v37 += 8;
    v58[3] = sample_range_limit[((((int)(float)(tmp3a - v61) + 4) >> 3) & 0x3FF) + 128];
  }
  while ( v36 < 8 );
}

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1027CB30
// Name: _jpeg_idct_float
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_idct_float(
        jpeg_decompress_struct *cinfo,
        jpeg_component_info *compptr,
        __int16 *coef_block,
        unsigned __int8 **output_buf,
        unsigned int output_col)
{
  float *dct_table; // edx
  unsigned __int8 *sample_range_limit; // esi
  float *v8; // eax
  __int16 v9; // di
  float v10; // xmm0_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  int v13; // ebx
  float v14; // xmm4_4
  float v15; // xmm0_4
  float v16; // xmm2_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  float v19; // xmm2_4
  float v20; // xmm4_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm6_4
  float v24; // xmm0_4
  float v25; // xmm6_4
  float v26; // xmm7_4
  float v27; // xmm5_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm6_4
  float v32; // xmm5_4
  float v33; // xmm0_4
  float v34; // xmm1_4
  int v35; // edi
  int v36; // edi
  float *v37; // ecx
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm0_4
  float v41; // xmm4_4
  float v42; // xmm3_4
  unsigned __int8 *v43; // eax
  float v44; // xmm1_4
  float v45; // xmm2_4
  float v46; // xmm0_4
  float v47; // xmm3_4
  float v48; // xmm4_4
  float v49; // xmm1_4
  float v50; // xmm0_4
  float v51; // xmm4_4
  float v52; // xmm7_4
  float v53; // xmm0_4
  float v54; // xmm1_4
  float v55; // xmm5_4
  float v56; // xmm4_4
  float v57; // xmm1_4
  unsigned __int8 *v58; // eax
  float v59; // xmm4_4
  float v60; // xmm0_4
  float v61; // xmm1_4
  float workspace[64]; // [esp+0h] [ebp-104h] BYREF
  int ctr; // [esp+100h] [ebp-4h]
  float z13; // [esp+10Ch] [ebp+8h]
  float z13a; // [esp+10Ch] [ebp+8h]
  float tmp3; // [esp+110h] [ebp+Ch]
  float tmp3a; // [esp+110h] [ebp+Ch]
  float tmp2; // [esp+114h] [ebp+10h]
  float tmp2a; // [esp+114h] [ebp+10h]

  dct_table = (float *)compptr->dct_table;
  sample_range_limit = cinfo->sample_range_limit;
  v8 = workspace;
  ctr = 8;
  do
  {
    v9 = coef_block[8];
    if ( v9 != 0
      || coef_block[16] != 0
      || coef_block[24] != 0
      || coef_block[32] != 0
      || coef_block[40] != 0
      || coef_block[48] != 0
      || coef_block[56] != 0 )
    {
      v11 = (float)*coef_block * *dct_table;
      v12 = (float)coef_block[16] * dct_table[16];
      v13 = coef_block[48];
      v14 = (float)((float)v13 * dct_table[48]) + v12;
      v15 = (float)((float)(v12 - (float)((float)v13 * dct_table[48])) * 1.4142135) - v14;
      v16 = (float)((float)coef_block[32] * dct_table[32]) + v11;
      v17 = v11 - (float)((float)coef_block[32] * dct_table[32]);
      v18 = v14 + v16;
      v19 = v16 - v14;
      v20 = v15 + v17;
      tmp2 = v17 - v15;
      tmp3 = v19;
      v21 = (float)v9 * dct_table[8];
      v22 = (float)coef_block[24] * dct_table[24];
      v23 = (float)coef_block[40] * dct_table[40];
      v24 = v23 - v22;
      v25 = v23 + v22;
      v26 = v24;
      v27 = (float)coef_block[56] * dct_table[56];
      v28 = v27 + v21;
      v29 = v21 - v27;
      v30 = (float)(v29 + v26) * 1.847759;
      z13 = v25;
      v31 = v28 + v25;
      v32 = (float)(v30 - (float)(v26 * 2.613126)) - v31;
      *v8 = v31 + v18;
      v33 = (float)((float)(v28 - z13) * 1.4142135) - v32;
      v34 = (float)((float)(v29 * 1.0823922) - v30) + v33;
      v8[56] = v18 - v31;
      v8[8] = v32 + v20;
      v8[40] = tmp2 - v33;
      v8[48] = v20 - v32;
      v8[16] = v33 + tmp2;
      v8[32] = v34 + tmp3;
      v10 = tmp3 - v34;
    }
    else
    {
      v10 = (float)*coef_block * *dct_table;
      *v8 = v10;
      v8[8] = v10;
      v8[16] = v10;
      v8[32] = v10;
      v8[40] = v10;
      v8[48] = v10;
      v8[56] = v10;
    }
    v35 = ctr - 1;
    v8[24] = v10;
    ++coef_block;
    ++dct_table;
    ++v8;
    ctr = v35;
  }
  while ( v35 > 0 );
  v36 = 0;
  v37 = &workspace[2];
  do
  {
    v38 = *(v37 - 2);
    v39 = v38 - v37[2];
    v40 = v38 + v37[2];
    v41 = v39;
    v42 = v37[4] + *v37;
    v43 = output_buf[v36];
    v44 = (float)((float)(*v37 - v37[4]) * 1.4142135) - v42;
    v45 = v42 + v40;
    v46 = v40 - v42;
    v47 = v44 + v41;
    v48 = v41 - v44;
    v49 = *(v37 - 1);
    tmp3a = v46;
    v50 = v37[3];
    tmp2a = v48;
    v51 = v37[1] + v50;
    v52 = v50 - v37[1];
    v53 = v37[5] + v49;
    v54 = v49 - v37[5];
    v55 = v53 + v51;
    z13a = v51;
    v56 = (float)(v54 + v52) * 1.847759;
    v57 = (float)(v54 * 1.0823922) - v56;
    v43[output_col] = sample_range_limit[((((int)(float)(v55 + v45) + 4) >> 3) & 0x3FF) + 128];
    v58 = &v43[output_col];
    v58[7] = sample_range_limit[((((int)(float)(v45 - v55) + 4) >> 3) & 0x3FF) + 128];
    v59 = (float)(v56 - (float)(v52 * 2.613126)) - v55;
    v58[1] = sample_range_limit[((((int)(float)(v59 + v47) + 4) >> 3) & 0x3FF) + 128];
    v60 = (float)((float)(v53 - z13a) * 1.4142135) - v59;
    v61 = v57 + v60;
    v58[6] = sample_range_limit[((((int)(float)(v47 - v59) + 4) >> 3) & 0x3FF) + 128];
    v58[2] = sample_range_limit[((((int)(float)(v60 + tmp2a) + 4) >> 3) & 0x3FF) + 128];
    v58[5] = sample_range_limit[((((int)(float)(tmp2a - v60) + 4) >> 3) & 0x3FF) + 128];
    v58[4] = sample_range_limit[((((int)(float)(v61 + tmp3a) + 4) >> 3) & 0x3FF) + 128];
    ++v36;
    v37 += 8;
    v58[3] = sample_range_limit[((((int)(float)(tmp3a - v61) + 4) >> 3) & 0x3FF) + 128];
  }
  while ( v36 < 8 );
}

} // namespace client
