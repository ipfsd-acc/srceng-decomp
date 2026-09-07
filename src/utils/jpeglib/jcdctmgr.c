// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jcdctmgr.c
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10255AE0
// Name: start_pass_fdctmgr
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_fdctmgr(jpeg_compress_struct *cinfo)
{
  jpeg_compress_struct *v1; // edi
  int v2; // esi
  J_DCT_METHOD dct_method; // eax
  JQUANT_TBL *v4; // ebx
  __int32 v5; // eax
  double *v6; // eax
  int v7; // edx
  unsigned __int16 *v8; // ecx
  double v9; // xmm2_8
  float v10; // xmm1_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  int *v17; // ecx
  __int16 *v18; // edx
  char *v19; // eax
  int *v20; // esi
  int i; // eax
  int ci; // [esp+4h] [ebp-Ch]
  int *p_quant_tbl_no; // [esp+8h] [ebp-8h]
  my_fdct_controller *fdct; // [esp+Ch] [ebp-4h]

  v1 = cinfo;
  fdct = (my_fdct_controller *)cinfo->fdct;
  ci = 0;
  if ( cinfo->num_components > 0 )
  {
    p_quant_tbl_no = &cinfo->comp_info->quant_tbl_no;
    do
    {
      v2 = *p_quant_tbl_no;
      if ( (unsigned int)*p_quant_tbl_no > 3 || v1->quant_tbl_ptrs[v2] == nullptr )
      {
        v1->err->msg_code = 52;
        v1->err->msg_parm.i[0] = v2;
        v1->err->error_exit(a1: (jpeg_common_struct *)v1);
      }
      dct_method = v1->dct_method;
      v4 = v1->quant_tbl_ptrs[v2];
      if ( dct_method != JDCT_ISLOW )
      {
        v5 = dct_method - 1;
        if ( v5 != 0 )
        {
          if ( v5 == 1 )
          {
            if ( fdct->float_divisors[v2] == nullptr )
              fdct->float_divisors[v2] = (float *)v1->mem->alloc_small(a1: (jpeg_common_struct *)v1, a2: 1, a3: 256u);
            v6 = (double *)aanscalefactor;
            v7 = (int)(fdct->float_divisors[v2] + 2);
            v8 = &v4->quantval[2];
            do
            {
              v9 = 1.0 / ((double)*(v8 - 2) * *v6 * 8.0);
              v8 += 8;
              v7 += 32;
              ++v6;
              v10 = v9;
              *(float *)(v7 - 40) = v10;
              v11 = 1.0 / ((double)*(v8 - 9) * *(v6 - 1) * 1.387039845 * 8.0);
              *(float *)(v7 - 36) = v11;
              v12 = 1.0 / ((double)*(v8 - 8) * *(v6 - 1) * 1.306562965 * 8.0);
              *(float *)(v7 - 32) = v12;
              v13 = 1.0 / ((double)*(v8 - 7) * *(v6 - 1) * 1.175875602 * 8.0);
              *(float *)(v7 - 28) = v13;
              v14 = 1.0 / ((double)*(v8 - 6) * *(v6 - 1) * 8.0);
              *(float *)(v7 - 24) = v14;
              v15 = 1.0 / ((double)*(v8 - 5) * *(v6 - 1) * 0.785694958 * 8.0);
              *(float *)(v7 - 20) = v15;
              v16 = 1.0 / ((double)*(v8 - 4) * *(v6 - 1) * 0.5411961 * 8.0);
              *(float *)(v7 - 16) = v16;
              *(float *)(v7 - 12) = 1.0 / ((double)*(v8 - 3) * *(v6 - 1) * 0.275899379 * 8.0);
            }
            while ( (int)v6 < (int)&FLOAT_16384_5 );
          }
          else
          {
            v1->err->msg_code = 48;
            v1->err->error_exit(a1: (jpeg_common_struct *)v1);
          }
        }
        else
        {
          if ( fdct->divisors[v2] == nullptr )
            fdct->divisors[v2] = (int *)v1->mem->alloc_small(a1: (jpeg_common_struct *)v1, a2: 1, a3: 256u);
          v17 = fdct->divisors[v2] + 2;
          v18 = &word_103CABBA;
          v19 = (char *)&v4->quantval[2];
          do
          {
            *(v17 - 2) = (*(v18 - 1) * *((unsigned __int16 *)v19 - 2) + 1024) >> 11;
            *(v17 - 1) = (*v18 * *((unsigned __int16 *)v19 - 1) + 1024) >> 11;
            *v17 = (*(unsigned __int16 *)v19 * *(const __int16 *)((char *)aanscales + v19 - (char *)v4) + 1024) >> 11;
            v17[1] = (*((unsigned __int16 *)v19 + 1) * *(__int16 *)((char *)&word_103CABBA + v19 - (char *)v4) + 1024) >> 11;
            v18 += 4;
            v17 += 4;
            v19 += 8;
          }
          while ( (int)v18 < (int)((__int16 *)aanscalefactor + 1) );
          v1 = cinfo;
        }
      }
      else
      {
        if ( fdct->divisors[v2] == nullptr )
          fdct->divisors[v2] = (int *)v1->mem->alloc_small(a1: (jpeg_common_struct *)v1, a2: 1, a3: 256u);
        v20 = fdct->divisors[v2];
        for ( i = 0; i < 64; ++i )
          v20[i] = 8 * v4->quantval[i];
      }
      p_quant_tbl_no += 21;
      ++ci;
    }
    while ( ci < v1->num_components );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10255E70
// Name: forward_DCT
// Source: json
//------------------------------------------------------------------------------
void __cdecl forward_DCT(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **sample_data,
        __int16 (*coef_blocks)[64],
        unsigned int start_row,
        unsigned int start_col,
        jpeg_compress_struct *num_blocks)
{
  jpeg_forward_dct *fdct; // eax
  int v8; // eax
  __int16 *v10; // edi
  jpeg_component_info *v11; // edx
  int *v12; // eax
  int i; // esi
  unsigned __int8 *v14; // ecx
  unsigned __int8 *v15; // ecx
  unsigned __int8 *v16; // ecx
  unsigned __int8 *v17; // ecx
  unsigned int v18; // esi
  int j; // ebx
  int v20; // ecx
  int v21; // eax
  int v22; // edx
  int v23; // edx
  int v24; // eax
  int v25; // eax
  int v26; // ecx
  int v27; // eax
  int v28; // edx
  int v29; // edx
  int v30; // eax
  int v31; // eax
  int v32; // ecx
  int v33; // eax
  int v34; // edx
  int v35; // edx
  int v36; // eax
  int v37; // eax
  int v38; // ecx
  int v39; // eax
  int v40; // edx
  int v41; // edx
  int v42; // eax
  int v43; // eax
  int workspace[64]; // [esp+0h] [ebp-104h] BYREF
  void (__cdecl *do_dct)(int *); // [esp+100h] [ebp-4h]
  jpeg_compress_struct *cinfoa; // [esp+10Ch] [ebp+8h]
  jpeg_component_info *compptra; // [esp+110h] [ebp+Ch]
  unsigned __int8 **sample_dataa; // [esp+114h] [ebp+10h]
  char *start_rowa; // [esp+11Ch] [ebp+18h]
  unsigned int num_blocksa; // [esp+124h] [ebp+20h]

  fdct = cinfo->fdct;
  do_dct = (void (__cdecl *)(int *))fdct[1].start_pass;
  v8 = *((_DWORD *)&fdct[1].forward_DCT + compptr->quant_tbl_no);
  if ( num_blocks != nullptr )
  {
    compptra = (jpeg_component_info *)&sample_data[start_row + 2];
    num_blocksa = v8 + 8;
    start_rowa = (char *)workspace - v8;
    sample_dataa = (unsigned __int8 **)((char *)&workspace[1] - v8);
    v10 = &(*coef_blocks)[2];
    cinfoa = num_blocks;
    do
    {
      v11 = compptra;
      v12 = workspace;
      for ( i = 2; i != 0; --i )
      {
        v14 = (unsigned __int8 *)v11[-1].quant_table + start_col;
        *v12 = *v14 - 128;
        v12[1] = v14[1] - 128;
        v12[2] = v14[2] - 128;
        v12[3] = v14[3] - 128;
        v12[4] = v14[4] - 128;
        v12[5] = v14[5] - 128;
        v12[6] = v14[6] - 128;
        v12[7] = v14[7] - 128;
        v15 = (unsigned __int8 *)v11[-1].dct_table + start_col;
        v12[8] = *v15 - 128;
        v12[9] = v15[1] - 128;
        v12[10] = v15[2] - 128;
        v12[11] = v15[3] - 128;
        v12[12] = v15[4] - 128;
        v12[13] = v15[5] - 128;
        v12[14] = v15[6] - 128;
        v12[15] = v15[7] - 128;
        v16 = (unsigned __int8 *)(start_col + v11->component_id);
        v12[16] = *v16 - 128;
        v12[17] = v16[1] - 128;
        v12[18] = v16[2] - 128;
        v12[19] = v16[3] - 128;
        v12[20] = v16[4] - 128;
        v12[21] = v16[5] - 128;
        v12[22] = v16[6] - 128;
        v12[23] = v16[7] - 128;
        v17 = (unsigned __int8 *)(start_col + v11->component_index);
        v12[24] = *v17 - 128;
        v12[25] = v17[1] - 128;
        v12[26] = v17[2] - 128;
        v12[27] = v17[3] - 128;
        v12[28] = v17[4] - 128;
        v12[29] = v17[5] - 128;
        v12[30] = v17[6] - 128;
        v12[31] = v17[7] - 128;
        v12 += 32;
        v11 = (jpeg_component_info *)((char *)v11 + 16);
      }
      do_dct(a1: workspace);
      v18 = num_blocksa;
      for ( j = 0; j < 64; j += 4 )
      {
        v20 = *(_DWORD *)(v18 - 8);
        v21 = workspace[j];
        v22 = v20 >> 1;
        if ( v21 >= 0 )
        {
          v25 = v22 + v21;
          if ( v25 < v20 )
            LOWORD(v24) = 0;
          else
            v24 = v25 / v20;
        }
        else
        {
          v23 = v22 - v21;
          if ( v23 < v20 )
            LOWORD(v24) = 0;
          else
            v24 = -(v23 / v20);
        }
        *(v10 - 2) = v24;
        v26 = *(_DWORD *)(v18 - 4);
        v27 = workspace[j + 1];
        v28 = v26 >> 1;
        if ( v27 >= 0 )
        {
          v31 = v28 + v27;
          if ( v31 < v26 )
            LOWORD(v30) = 0;
          else
            v30 = v31 / v26;
        }
        else
        {
          v29 = v28 - v27;
          if ( v29 < v26 )
            LOWORD(v30) = 0;
          else
            v30 = -(v29 / v26);
        }
        *(v10 - 1) = v30;
        v32 = *(_DWORD *)v18;
        v33 = *(_DWORD *)&start_rowa[v18];
        v34 = *(int *)v18 >> 1;
        if ( v33 >= 0 )
        {
          v37 = v34 + v33;
          if ( v37 < v32 )
            LOWORD(v36) = 0;
          else
            v36 = v37 / v32;
        }
        else
        {
          v35 = v34 - v33;
          if ( v35 < v32 )
            LOWORD(v36) = 0;
          else
            v36 = -(v35 / v32);
        }
        *v10 = v36;
        v38 = *(_DWORD *)(v18 + 4);
        v39 = *(int *)((char *)sample_dataa + v18);
        v40 = v38 >> 1;
        if ( v39 >= 0 )
        {
          v43 = v40 + v39;
          if ( v43 < v38 )
            LOWORD(v42) = 0;
          else
            v42 = v43 / v38;
        }
        else
        {
          v41 = v40 - v39;
          if ( v41 < v38 )
            LOWORD(v42) = 0;
          else
            v42 = -(v41 / v38);
        }
        v10[1] = v42;
        v10 += 4;
        v18 += 16;
      }
      start_col += 8;
      cinfoa = (jpeg_compress_struct *)((char *)cinfoa - 1);
    }
    while ( cinfoa != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10256160
// Name: forward_DCT_float
// Source: json
//------------------------------------------------------------------------------
void __cdecl forward_DCT_float(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **sample_data,
        __int16 (*coef_blocks)[64],
        unsigned int start_row,
        unsigned int start_col,
        jpeg_component_info *num_blocks)
{
  jpeg_forward_dct *fdct; // eax
  unsigned __int8 *v9; // eax
  int v10; // edx
  unsigned __int8 *v11; // eax
  float v12; // xmm0_4
  unsigned __int8 *v13; // eax
  int v14; // ecx
  unsigned __int8 *v15; // eax
  int v16; // edx
  unsigned __int8 *v17; // eax
  int v18; // ecx
  unsigned __int8 *v19; // eax
  int v20; // edx
  unsigned __int8 *v21; // eax
  int v22; // ecx
  unsigned __int8 *v23; // eax
  int v24; // edx
  unsigned __int8 *v25; // eax
  int v26; // ecx
  unsigned __int8 *v27; // eax
  int v28; // edx
  unsigned __int8 *v29; // eax
  int v30; // ecx
  unsigned __int8 *v31; // eax
  int v32; // edx
  unsigned __int8 *v33; // eax
  int v34; // ecx
  unsigned __int8 *v35; // eax
  int v36; // edx
  unsigned __int8 *v37; // eax
  int v38; // ecx
  unsigned __int8 *v39; // eax
  int i; // eax
  float workspace[64]; // [esp+8h] [ebp-108h] BYREF
  void (__cdecl *do_dct)(float *); // [esp+108h] [ebp-8h]
  float *divisors; // [esp+10Ch] [ebp-4h]
  jpeg_component_info *compptra; // [esp+11Ch] [ebp+Ch]

  fdct = cinfo->fdct;
  do_dct = (void (__cdecl *)(float *))fdct[3].forward_DCT;
  divisors = *((float **)&fdct[4].start_pass + compptr->quant_tbl_no);
  if ( num_blocks != nullptr )
  {
    for ( compptra = num_blocks; compptra != nullptr; compptra = (jpeg_component_info *)((char *)compptra - 1) )
    {
      v9 = sample_data[start_row];
      v10 = v9[start_col];
      v11 = &v9[start_col];
      workspace[0] = (float)(v10 - 128);
      workspace[1] = (float)(v11[1] - 128);
      workspace[2] = (float)(v11[2] - 128);
      workspace[3] = (float)(v11[3] - 128);
      workspace[4] = (float)(v11[4] - 128);
      workspace[5] = (float)(v11[5] - 128);
      workspace[6] = (float)(v11[6] - 128);
      v12 = (float)(v11[7] - 128);
      v13 = sample_data[start_row + 1];
      workspace[7] = v12;
      v14 = v13[start_col];
      v15 = &v13[start_col];
      workspace[8] = (float)(v14 - 128);
      workspace[9] = (float)(v15[1] - 128);
      workspace[10] = (float)(v15[2] - 128);
      workspace[11] = (float)(v15[3] - 128);
      workspace[12] = (float)(v15[4] - 128);
      workspace[13] = (float)(v15[5] - 128);
      workspace[14] = (float)(v15[6] - 128);
      v16 = v15[7] - 128;
      v17 = sample_data[start_row + 2];
      workspace[15] = (float)v16;
      v18 = v17[start_col];
      v19 = &v17[start_col];
      workspace[16] = (float)(v18 - 128);
      workspace[17] = (float)(v19[1] - 128);
      workspace[18] = (float)(v19[2] - 128);
      workspace[19] = (float)(v19[3] - 128);
      workspace[20] = (float)(v19[4] - 128);
      workspace[21] = (float)(v19[5] - 128);
      workspace[22] = (float)(v19[6] - 128);
      v20 = v19[7];
      v21 = sample_data[start_row + 3];
      workspace[23] = (float)(v20 - 128);
      v22 = v21[start_col];
      v23 = &v21[start_col];
      workspace[24] = (float)(v22 - 128);
      workspace[25] = (float)(v23[1] - 128);
      workspace[26] = (float)(v23[2] - 128);
      workspace[27] = (float)(v23[3] - 128);
      workspace[28] = (float)(v23[4] - 128);
      workspace[29] = (float)(v23[5] - 128);
      workspace[30] = (float)(v23[6] - 128);
      v24 = v23[7];
      v25 = sample_data[start_row + 4];
      workspace[31] = (float)(v24 - 128);
      v26 = v25[start_col];
      v27 = &v25[start_col];
      workspace[32] = (float)(v26 - 128);
      workspace[33] = (float)(v27[1] - 128);
      workspace[34] = (float)(v27[2] - 128);
      workspace[35] = (float)(v27[3] - 128);
      workspace[36] = (float)(v27[4] - 128);
      workspace[37] = (float)(v27[5] - 128);
      workspace[38] = (float)(v27[6] - 128);
      v28 = v27[7];
      v29 = sample_data[start_row + 5];
      workspace[39] = (float)(v28 - 128);
      v30 = v29[start_col];
      v31 = &v29[start_col];
      workspace[40] = (float)(v30 - 128);
      workspace[41] = (float)(v31[1] - 128);
      workspace[42] = (float)(v31[2] - 128);
      workspace[43] = (float)(v31[3] - 128);
      workspace[44] = (float)(v31[4] - 128);
      workspace[45] = (float)(v31[5] - 128);
      workspace[46] = (float)(v31[6] - 128);
      v32 = v31[7];
      v33 = sample_data[start_row + 6];
      workspace[47] = (float)(v32 - 128);
      v34 = v33[start_col];
      v35 = &v33[start_col];
      workspace[48] = (float)(v34 - 128);
      workspace[49] = (float)(v35[1] - 128);
      workspace[50] = (float)(v35[2] - 128);
      workspace[51] = (float)(v35[3] - 128);
      workspace[52] = (float)(v35[4] - 128);
      workspace[53] = (float)(v35[5] - 128);
      workspace[54] = (float)(v35[6] - 128);
      v36 = v35[7];
      v37 = sample_data[start_row + 7];
      workspace[55] = (float)(v36 - 128);
      v38 = v37[start_col];
      v39 = &v37[start_col];
      workspace[56] = (float)(v38 - 128);
      workspace[57] = (float)(v39[1] - 128);
      workspace[58] = (float)(v39[2] - 128);
      workspace[59] = (float)(v39[3] - 128);
      workspace[60] = (float)(v39[4] - 128);
      workspace[61] = (float)(v39[5] - 128);
      workspace[62] = (float)(v39[6] - 128);
      workspace[63] = (float)(v39[7] - 128);
      do_dct(a1: workspace);
      for ( i = 0; i < 64; ++i )
        (*coef_blocks)[i] = (int)(float)((float)(divisors[i] * workspace[i]) + 16384.5) - 0x4000;
      ++coef_blocks;
      start_col += 8;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10256760
// Name: _jinit_forward_dct
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_forward_dct(jpeg_common_struct *cinfo)
{
  jpeg_forward_dct *v1; // esi
  J_DCT_METHOD v2; // eax
  __int32 v3; // eax

  v1 = (jpeg_forward_dct *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 48);
  cinfo[14].progress = (jpeg_progress_mgr *)v1;
  v1->start_pass = start_pass_fdctmgr;
  v2 = *(_DWORD *)&cinfo[7].is_decompressor;
  if ( v2 == JDCT_ISLOW )
  {
    v1[1].start_pass = (void (__cdecl *)(jpeg_compress_struct *))jpeg_fdct_islow;
    goto LABEL_8;
  }
  v3 = v2 - 1;
  if ( v3 == 0 )
  {
    v1[1].start_pass = (void (__cdecl *)(jpeg_compress_struct *))jpeg_fdct_ifast;
LABEL_8:
    v1->forward_DCT = (void (__cdecl *)(jpeg_compress_struct *, jpeg_component_info *, unsigned __int8 **, __int16 (*)[64], unsigned int, unsigned int, unsigned int))forward_DCT;
    goto LABEL_9;
  }
  if ( v3 == 1 )
  {
    v1->forward_DCT = (void (__cdecl *)(jpeg_compress_struct *, jpeg_component_info *, unsigned __int8 **, __int16 (*)[64], unsigned int, unsigned int, unsigned int))forward_DCT_float;
    v1[3].forward_DCT = (void (__cdecl *)(jpeg_compress_struct *, jpeg_component_info *, unsigned __int8 **, __int16 (*)[64], unsigned int, unsigned int, unsigned int))jpeg_fdct_float;
  }
  else
  {
    cinfo->err->msg_code = 48;
    cinfo->err->error_exit(a1: cinfo);
  }
LABEL_9:
  v1[1].forward_DCT = nullptr;
  v1[4].start_pass = nullptr;
  v1[2].start_pass = nullptr;
  v1[4].forward_DCT = nullptr;
  v1[2].forward_DCT = nullptr;
  v1[5].start_pass = nullptr;
  v1[3].start_pass = nullptr;
  v1[5].forward_DCT = nullptr;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10255B10
// Name: start_pass_fdctmgr
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_fdctmgr(jpeg_compress_struct *cinfo)
{
  jpeg_compress_struct *v1; // edi
  int v2; // esi
  J_DCT_METHOD dct_method; // eax
  JQUANT_TBL *v4; // ebx
  __int32 v5; // eax
  double *v6; // eax
  int v7; // edx
  unsigned __int16 *v8; // ecx
  double v9; // xmm2_8
  float v10; // xmm1_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  int *v17; // ecx
  __int16 *v18; // edx
  char *v19; // eax
  int *v20; // esi
  int i; // eax
  int ci; // [esp+4h] [ebp-Ch]
  int *p_quant_tbl_no; // [esp+8h] [ebp-8h]
  my_fdct_controller *fdct; // [esp+Ch] [ebp-4h]

  v1 = cinfo;
  fdct = (my_fdct_controller *)cinfo->fdct;
  ci = 0;
  if ( cinfo->num_components > 0 )
  {
    p_quant_tbl_no = &cinfo->comp_info->quant_tbl_no;
    do
    {
      v2 = *p_quant_tbl_no;
      if ( (unsigned int)*p_quant_tbl_no > 3 || v1->quant_tbl_ptrs[v2] == nullptr )
      {
        v1->err->msg_code = 52;
        v1->err->msg_parm.i[0] = v2;
        v1->err->error_exit(a1: (jpeg_common_struct *)v1);
      }
      dct_method = v1->dct_method;
      v4 = v1->quant_tbl_ptrs[v2];
      if ( dct_method != JDCT_ISLOW )
      {
        v5 = dct_method - 1;
        if ( v5 != 0 )
        {
          if ( v5 == 1 )
          {
            if ( fdct->float_divisors[v2] == nullptr )
              fdct->float_divisors[v2] = (float *)v1->mem->alloc_small(a1: (jpeg_common_struct *)v1, a2: 1, a3: 256u);
            v6 = (double *)aanscalefactor;
            v7 = (int)(fdct->float_divisors[v2] + 2);
            v8 = &v4->quantval[2];
            do
            {
              v9 = 1.0 / ((double)*(v8 - 2) * *v6 * 8.0);
              v8 += 8;
              v7 += 32;
              ++v6;
              v10 = v9;
              *(float *)(v7 - 40) = v10;
              v11 = 1.0 / ((double)*(v8 - 9) * *(v6 - 1) * 1.387039845 * 8.0);
              *(float *)(v7 - 36) = v11;
              v12 = 1.0 / ((double)*(v8 - 8) * *(v6 - 1) * 1.306562965 * 8.0);
              *(float *)(v7 - 32) = v12;
              v13 = 1.0 / ((double)*(v8 - 7) * *(v6 - 1) * 1.175875602 * 8.0);
              *(float *)(v7 - 28) = v13;
              v14 = 1.0 / ((double)*(v8 - 6) * *(v6 - 1) * 8.0);
              *(float *)(v7 - 24) = v14;
              v15 = 1.0 / ((double)*(v8 - 5) * *(v6 - 1) * 0.785694958 * 8.0);
              *(float *)(v7 - 20) = v15;
              v16 = 1.0 / ((double)*(v8 - 4) * *(v6 - 1) * 0.5411961 * 8.0);
              *(float *)(v7 - 16) = v16;
              *(float *)(v7 - 12) = 1.0 / ((double)*(v8 - 3) * *(v6 - 1) * 0.275899379 * 8.0);
            }
            while ( (int)v6 < (int)&FLOAT_16384_5 );
          }
          else
          {
            v1->err->msg_code = 48;
            v1->err->error_exit(a1: (jpeg_common_struct *)v1);
          }
        }
        else
        {
          if ( fdct->divisors[v2] == nullptr )
            fdct->divisors[v2] = (int *)v1->mem->alloc_small(a1: (jpeg_common_struct *)v1, a2: 1, a3: 256u);
          v17 = fdct->divisors[v2] + 2;
          v18 = &word_103CAC8A;
          v19 = (char *)&v4->quantval[2];
          do
          {
            *(v17 - 2) = (*(v18 - 1) * *((unsigned __int16 *)v19 - 2) + 1024) >> 11;
            *(v17 - 1) = (*v18 * *((unsigned __int16 *)v19 - 1) + 1024) >> 11;
            *v17 = (*(unsigned __int16 *)v19 * *(const __int16 *)((char *)aanscales + v19 - (char *)v4) + 1024) >> 11;
            v17[1] = (*((unsigned __int16 *)v19 + 1) * *(__int16 *)((char *)&word_103CAC8A + v19 - (char *)v4) + 1024) >> 11;
            v18 += 4;
            v17 += 4;
            v19 += 8;
          }
          while ( (int)v18 < (int)((__int16 *)aanscalefactor + 1) );
          v1 = cinfo;
        }
      }
      else
      {
        if ( fdct->divisors[v2] == nullptr )
          fdct->divisors[v2] = (int *)v1->mem->alloc_small(a1: (jpeg_common_struct *)v1, a2: 1, a3: 256u);
        v20 = fdct->divisors[v2];
        for ( i = 0; i < 64; ++i )
          v20[i] = 8 * v4->quantval[i];
      }
      p_quant_tbl_no += 21;
      ++ci;
    }
    while ( ci < v1->num_components );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10255EA0
// Name: forward_DCT
// Source: json
//------------------------------------------------------------------------------
void __cdecl forward_DCT(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **sample_data,
        __int16 (*coef_blocks)[64],
        unsigned int start_row,
        unsigned int start_col,
        jpeg_compress_struct *num_blocks)
{
  jpeg_forward_dct *fdct; // eax
  int v8; // eax
  __int16 *v10; // edi
  jpeg_component_info *v11; // edx
  int *v12; // eax
  int i; // esi
  unsigned __int8 *v14; // ecx
  unsigned __int8 *v15; // ecx
  unsigned __int8 *v16; // ecx
  unsigned __int8 *v17; // ecx
  unsigned int v18; // esi
  int j; // ebx
  int v20; // ecx
  int v21; // eax
  int v22; // edx
  int v23; // edx
  int v24; // eax
  int v25; // eax
  int v26; // ecx
  int v27; // eax
  int v28; // edx
  int v29; // edx
  int v30; // eax
  int v31; // eax
  int v32; // ecx
  int v33; // eax
  int v34; // edx
  int v35; // edx
  int v36; // eax
  int v37; // eax
  int v38; // ecx
  int v39; // eax
  int v40; // edx
  int v41; // edx
  int v42; // eax
  int v43; // eax
  int workspace[64]; // [esp+0h] [ebp-104h] BYREF
  void (__cdecl *do_dct)(int *); // [esp+100h] [ebp-4h]
  jpeg_compress_struct *cinfoa; // [esp+10Ch] [ebp+8h]
  jpeg_component_info *compptra; // [esp+110h] [ebp+Ch]
  unsigned __int8 **sample_dataa; // [esp+114h] [ebp+10h]
  char *start_rowa; // [esp+11Ch] [ebp+18h]
  unsigned int num_blocksa; // [esp+124h] [ebp+20h]

  fdct = cinfo->fdct;
  do_dct = (void (__cdecl *)(int *))fdct[1].start_pass;
  v8 = *((_DWORD *)&fdct[1].forward_DCT + compptr->quant_tbl_no);
  if ( num_blocks != nullptr )
  {
    compptra = (jpeg_component_info *)&sample_data[start_row + 2];
    num_blocksa = v8 + 8;
    start_rowa = (char *)workspace - v8;
    sample_dataa = (unsigned __int8 **)((char *)&workspace[1] - v8);
    v10 = &(*coef_blocks)[2];
    cinfoa = num_blocks;
    do
    {
      v11 = compptra;
      v12 = workspace;
      for ( i = 2; i != 0; --i )
      {
        v14 = (unsigned __int8 *)v11[-1].quant_table + start_col;
        *v12 = *v14 - 128;
        v12[1] = v14[1] - 128;
        v12[2] = v14[2] - 128;
        v12[3] = v14[3] - 128;
        v12[4] = v14[4] - 128;
        v12[5] = v14[5] - 128;
        v12[6] = v14[6] - 128;
        v12[7] = v14[7] - 128;
        v15 = (unsigned __int8 *)v11[-1].dct_table + start_col;
        v12[8] = *v15 - 128;
        v12[9] = v15[1] - 128;
        v12[10] = v15[2] - 128;
        v12[11] = v15[3] - 128;
        v12[12] = v15[4] - 128;
        v12[13] = v15[5] - 128;
        v12[14] = v15[6] - 128;
        v12[15] = v15[7] - 128;
        v16 = (unsigned __int8 *)(start_col + v11->component_id);
        v12[16] = *v16 - 128;
        v12[17] = v16[1] - 128;
        v12[18] = v16[2] - 128;
        v12[19] = v16[3] - 128;
        v12[20] = v16[4] - 128;
        v12[21] = v16[5] - 128;
        v12[22] = v16[6] - 128;
        v12[23] = v16[7] - 128;
        v17 = (unsigned __int8 *)(start_col + v11->component_index);
        v12[24] = *v17 - 128;
        v12[25] = v17[1] - 128;
        v12[26] = v17[2] - 128;
        v12[27] = v17[3] - 128;
        v12[28] = v17[4] - 128;
        v12[29] = v17[5] - 128;
        v12[30] = v17[6] - 128;
        v12[31] = v17[7] - 128;
        v12 += 32;
        v11 = (jpeg_component_info *)((char *)v11 + 16);
      }
      do_dct(a1: workspace);
      v18 = num_blocksa;
      for ( j = 0; j < 64; j += 4 )
      {
        v20 = *(_DWORD *)(v18 - 8);
        v21 = workspace[j];
        v22 = v20 >> 1;
        if ( v21 >= 0 )
        {
          v25 = v22 + v21;
          if ( v25 < v20 )
            LOWORD(v24) = 0;
          else
            v24 = v25 / v20;
        }
        else
        {
          v23 = v22 - v21;
          if ( v23 < v20 )
            LOWORD(v24) = 0;
          else
            v24 = -(v23 / v20);
        }
        *(v10 - 2) = v24;
        v26 = *(_DWORD *)(v18 - 4);
        v27 = workspace[j + 1];
        v28 = v26 >> 1;
        if ( v27 >= 0 )
        {
          v31 = v28 + v27;
          if ( v31 < v26 )
            LOWORD(v30) = 0;
          else
            v30 = v31 / v26;
        }
        else
        {
          v29 = v28 - v27;
          if ( v29 < v26 )
            LOWORD(v30) = 0;
          else
            v30 = -(v29 / v26);
        }
        *(v10 - 1) = v30;
        v32 = *(_DWORD *)v18;
        v33 = *(_DWORD *)&start_rowa[v18];
        v34 = *(int *)v18 >> 1;
        if ( v33 >= 0 )
        {
          v37 = v34 + v33;
          if ( v37 < v32 )
            LOWORD(v36) = 0;
          else
            v36 = v37 / v32;
        }
        else
        {
          v35 = v34 - v33;
          if ( v35 < v32 )
            LOWORD(v36) = 0;
          else
            v36 = -(v35 / v32);
        }
        *v10 = v36;
        v38 = *(_DWORD *)(v18 + 4);
        v39 = *(int *)((char *)sample_dataa + v18);
        v40 = v38 >> 1;
        if ( v39 >= 0 )
        {
          v43 = v40 + v39;
          if ( v43 < v38 )
            LOWORD(v42) = 0;
          else
            v42 = v43 / v38;
        }
        else
        {
          v41 = v40 - v39;
          if ( v41 < v38 )
            LOWORD(v42) = 0;
          else
            v42 = -(v41 / v38);
        }
        v10[1] = v42;
        v10 += 4;
        v18 += 16;
      }
      start_col += 8;
      cinfoa = (jpeg_compress_struct *)((char *)cinfoa - 1);
    }
    while ( cinfoa != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10256190
// Name: forward_DCT_float
// Source: json
//------------------------------------------------------------------------------
void __cdecl forward_DCT_float(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **sample_data,
        __int16 (*coef_blocks)[64],
        unsigned int start_row,
        unsigned int start_col,
        jpeg_component_info *num_blocks)
{
  jpeg_forward_dct *fdct; // eax
  unsigned __int8 *v9; // eax
  int v10; // edx
  unsigned __int8 *v11; // eax
  float v12; // xmm0_4
  unsigned __int8 *v13; // eax
  int v14; // ecx
  unsigned __int8 *v15; // eax
  int v16; // edx
  unsigned __int8 *v17; // eax
  int v18; // ecx
  unsigned __int8 *v19; // eax
  int v20; // edx
  unsigned __int8 *v21; // eax
  int v22; // ecx
  unsigned __int8 *v23; // eax
  int v24; // edx
  unsigned __int8 *v25; // eax
  int v26; // ecx
  unsigned __int8 *v27; // eax
  int v28; // edx
  unsigned __int8 *v29; // eax
  int v30; // ecx
  unsigned __int8 *v31; // eax
  int v32; // edx
  unsigned __int8 *v33; // eax
  int v34; // ecx
  unsigned __int8 *v35; // eax
  int v36; // edx
  unsigned __int8 *v37; // eax
  int v38; // ecx
  unsigned __int8 *v39; // eax
  int i; // eax
  float workspace[64]; // [esp+8h] [ebp-108h] BYREF
  void (__cdecl *do_dct)(float *); // [esp+108h] [ebp-8h]
  float *divisors; // [esp+10Ch] [ebp-4h]
  jpeg_component_info *compptra; // [esp+11Ch] [ebp+Ch]

  fdct = cinfo->fdct;
  do_dct = (void (__cdecl *)(float *))fdct[3].forward_DCT;
  divisors = *((float **)&fdct[4].start_pass + compptr->quant_tbl_no);
  if ( num_blocks != nullptr )
  {
    for ( compptra = num_blocks; compptra != nullptr; compptra = (jpeg_component_info *)((char *)compptra - 1) )
    {
      v9 = sample_data[start_row];
      v10 = v9[start_col];
      v11 = &v9[start_col];
      workspace[0] = (float)(v10 - 128);
      workspace[1] = (float)(v11[1] - 128);
      workspace[2] = (float)(v11[2] - 128);
      workspace[3] = (float)(v11[3] - 128);
      workspace[4] = (float)(v11[4] - 128);
      workspace[5] = (float)(v11[5] - 128);
      workspace[6] = (float)(v11[6] - 128);
      v12 = (float)(v11[7] - 128);
      v13 = sample_data[start_row + 1];
      workspace[7] = v12;
      v14 = v13[start_col];
      v15 = &v13[start_col];
      workspace[8] = (float)(v14 - 128);
      workspace[9] = (float)(v15[1] - 128);
      workspace[10] = (float)(v15[2] - 128);
      workspace[11] = (float)(v15[3] - 128);
      workspace[12] = (float)(v15[4] - 128);
      workspace[13] = (float)(v15[5] - 128);
      workspace[14] = (float)(v15[6] - 128);
      v16 = v15[7] - 128;
      v17 = sample_data[start_row + 2];
      workspace[15] = (float)v16;
      v18 = v17[start_col];
      v19 = &v17[start_col];
      workspace[16] = (float)(v18 - 128);
      workspace[17] = (float)(v19[1] - 128);
      workspace[18] = (float)(v19[2] - 128);
      workspace[19] = (float)(v19[3] - 128);
      workspace[20] = (float)(v19[4] - 128);
      workspace[21] = (float)(v19[5] - 128);
      workspace[22] = (float)(v19[6] - 128);
      v20 = v19[7];
      v21 = sample_data[start_row + 3];
      workspace[23] = (float)(v20 - 128);
      v22 = v21[start_col];
      v23 = &v21[start_col];
      workspace[24] = (float)(v22 - 128);
      workspace[25] = (float)(v23[1] - 128);
      workspace[26] = (float)(v23[2] - 128);
      workspace[27] = (float)(v23[3] - 128);
      workspace[28] = (float)(v23[4] - 128);
      workspace[29] = (float)(v23[5] - 128);
      workspace[30] = (float)(v23[6] - 128);
      v24 = v23[7];
      v25 = sample_data[start_row + 4];
      workspace[31] = (float)(v24 - 128);
      v26 = v25[start_col];
      v27 = &v25[start_col];
      workspace[32] = (float)(v26 - 128);
      workspace[33] = (float)(v27[1] - 128);
      workspace[34] = (float)(v27[2] - 128);
      workspace[35] = (float)(v27[3] - 128);
      workspace[36] = (float)(v27[4] - 128);
      workspace[37] = (float)(v27[5] - 128);
      workspace[38] = (float)(v27[6] - 128);
      v28 = v27[7];
      v29 = sample_data[start_row + 5];
      workspace[39] = (float)(v28 - 128);
      v30 = v29[start_col];
      v31 = &v29[start_col];
      workspace[40] = (float)(v30 - 128);
      workspace[41] = (float)(v31[1] - 128);
      workspace[42] = (float)(v31[2] - 128);
      workspace[43] = (float)(v31[3] - 128);
      workspace[44] = (float)(v31[4] - 128);
      workspace[45] = (float)(v31[5] - 128);
      workspace[46] = (float)(v31[6] - 128);
      v32 = v31[7];
      v33 = sample_data[start_row + 6];
      workspace[47] = (float)(v32 - 128);
      v34 = v33[start_col];
      v35 = &v33[start_col];
      workspace[48] = (float)(v34 - 128);
      workspace[49] = (float)(v35[1] - 128);
      workspace[50] = (float)(v35[2] - 128);
      workspace[51] = (float)(v35[3] - 128);
      workspace[52] = (float)(v35[4] - 128);
      workspace[53] = (float)(v35[5] - 128);
      workspace[54] = (float)(v35[6] - 128);
      v36 = v35[7];
      v37 = sample_data[start_row + 7];
      workspace[55] = (float)(v36 - 128);
      v38 = v37[start_col];
      v39 = &v37[start_col];
      workspace[56] = (float)(v38 - 128);
      workspace[57] = (float)(v39[1] - 128);
      workspace[58] = (float)(v39[2] - 128);
      workspace[59] = (float)(v39[3] - 128);
      workspace[60] = (float)(v39[4] - 128);
      workspace[61] = (float)(v39[5] - 128);
      workspace[62] = (float)(v39[6] - 128);
      workspace[63] = (float)(v39[7] - 128);
      do_dct(a1: workspace);
      for ( i = 0; i < 64; ++i )
        (*coef_blocks)[i] = (int)(float)((float)(divisors[i] * workspace[i]) + 16384.5) - 0x4000;
      ++coef_blocks;
      start_col += 8;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10256790
// Name: _jinit_forward_dct
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_forward_dct(jpeg_common_struct *cinfo)
{
  jpeg_forward_dct *v1; // esi
  J_DCT_METHOD v2; // eax
  __int32 v3; // eax

  v1 = (jpeg_forward_dct *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 48);
  cinfo[14].progress = (jpeg_progress_mgr *)v1;
  v1->start_pass = start_pass_fdctmgr;
  v2 = *(_DWORD *)&cinfo[7].is_decompressor;
  if ( v2 == JDCT_ISLOW )
  {
    v1[1].start_pass = (void (__cdecl *)(jpeg_compress_struct *))jpeg_fdct_islow;
    goto LABEL_8;
  }
  v3 = v2 - 1;
  if ( v3 == 0 )
  {
    v1[1].start_pass = (void (__cdecl *)(jpeg_compress_struct *))jpeg_fdct_ifast;
LABEL_8:
    v1->forward_DCT = (void (__cdecl *)(jpeg_compress_struct *, jpeg_component_info *, unsigned __int8 **, __int16 (*)[64], unsigned int, unsigned int, unsigned int))forward_DCT;
    goto LABEL_9;
  }
  if ( v3 == 1 )
  {
    v1->forward_DCT = (void (__cdecl *)(jpeg_compress_struct *, jpeg_component_info *, unsigned __int8 **, __int16 (*)[64], unsigned int, unsigned int, unsigned int))forward_DCT_float;
    v1[3].forward_DCT = (void (__cdecl *)(jpeg_compress_struct *, jpeg_component_info *, unsigned __int8 **, __int16 (*)[64], unsigned int, unsigned int, unsigned int))jpeg_fdct_float;
  }
  else
  {
    cinfo->err->msg_code = 48;
    cinfo->err->error_exit(a1: cinfo);
  }
LABEL_9:
  v1[1].forward_DCT = nullptr;
  v1[4].start_pass = nullptr;
  v1[2].start_pass = nullptr;
  v1[4].forward_DCT = nullptr;
  v1[2].forward_DCT = nullptr;
  v1[5].start_pass = nullptr;
  v1[3].start_pass = nullptr;
  v1[5].forward_DCT = nullptr;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from statsmap (Missing functions)
// ============================================================
namespace statsmap {

//------------------------------------------------------------------------------
// Address: 0x0040A030
// Name: start_pass_fdctmgr
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_fdctmgr(jpeg_compress_struct *cinfo)
{
  jpeg_compress_struct *v1; // edi
  int v2; // esi
  J_DCT_METHOD dct_method; // eax
  JQUANT_TBL *v4; // ebx
  __int32 v5; // eax
  double *v6; // eax
  int v7; // edx
  unsigned __int16 *v8; // ecx
  double v9; // xmm2_8
  float v10; // xmm1_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  int *v17; // ecx
  __int16 *v18; // edx
  char *v19; // eax
  int *v20; // esi
  int i; // eax
  int ci; // [esp+4h] [ebp-Ch]
  int *p_quant_tbl_no; // [esp+8h] [ebp-8h]
  my_fdct_controller *fdct; // [esp+Ch] [ebp-4h]

  v1 = cinfo;
  fdct = (my_fdct_controller *)cinfo->fdct;
  ci = 0;
  if ( cinfo->num_components > 0 )
  {
    p_quant_tbl_no = &cinfo->comp_info->quant_tbl_no;
    do
    {
      v2 = *p_quant_tbl_no;
      if ( (unsigned int)*p_quant_tbl_no > 3 || v1->quant_tbl_ptrs[v2] == nullptr )
      {
        v1->err->msg_code = 52;
        v1->err->msg_parm.i[0] = v2;
        v1->err->error_exit(a1: (jpeg_common_struct *)v1);
      }
      dct_method = v1->dct_method;
      v4 = v1->quant_tbl_ptrs[v2];
      if ( dct_method != JDCT_ISLOW )
      {
        v5 = dct_method - 1;
        if ( v5 != 0 )
        {
          if ( v5 == 1 )
          {
            if ( fdct->float_divisors[v2] == nullptr )
              fdct->float_divisors[v2] = (float *)v1->mem->alloc_small(a1: (jpeg_common_struct *)v1, a2: 1, a3: 256u);
            v6 = (double *)aanscalefactor;
            v7 = (int)(fdct->float_divisors[v2] + 2);
            v8 = &v4->quantval[2];
            do
            {
              v9 = 1.0 / ((double)*(v8 - 2) * *v6 * 8.0);
              v8 += 8;
              v7 += 32;
              ++v6;
              v10 = v9;
              *(float *)(v7 - 40) = v10;
              v11 = 1.0 / ((double)*(v8 - 9) * *(v6 - 1) * 1.387039845 * 8.0);
              *(float *)(v7 - 36) = v11;
              v12 = 1.0 / ((double)*(v8 - 8) * *(v6 - 1) * 1.306562965 * 8.0);
              *(float *)(v7 - 32) = v12;
              v13 = 1.0 / ((double)*(v8 - 7) * *(v6 - 1) * 1.175875602 * 8.0);
              *(float *)(v7 - 28) = v13;
              v14 = 1.0 / ((double)*(v8 - 6) * *(v6 - 1) * 8.0);
              *(float *)(v7 - 24) = v14;
              v15 = 1.0 / ((double)*(v8 - 5) * *(v6 - 1) * 0.785694958 * 8.0);
              *(float *)(v7 - 20) = v15;
              v16 = 1.0 / ((double)*(v8 - 4) * *(v6 - 1) * 0.5411961 * 8.0);
              *(float *)(v7 - 16) = v16;
              *(float *)(v7 - 12) = 1.0 / ((double)*(v8 - 3) * *(v6 - 1) * 0.275899379 * 8.0);
            }
            while ( (int)v6 < (int)&DOUBLE_8_0 );
          }
          else
          {
            v1->err->msg_code = 48;
            v1->err->error_exit(a1: (jpeg_common_struct *)v1);
          }
        }
        else
        {
          if ( fdct->divisors[v2] == nullptr )
            fdct->divisors[v2] = (int *)v1->mem->alloc_small(a1: (jpeg_common_struct *)v1, a2: 1, a3: 256u);
          v17 = fdct->divisors[v2] + 2;
          v18 = &word_42198A;
          v19 = (char *)&v4->quantval[2];
          do
          {
            *(v17 - 2) = (*(v18 - 1) * *((unsigned __int16 *)v19 - 2) + 1024) >> 11;
            *(v17 - 1) = (*v18 * *((unsigned __int16 *)v19 - 1) + 1024) >> 11;
            *v17 = (*(unsigned __int16 *)v19 * *(const __int16 *)((char *)aanscales + v19 - (char *)v4) + 1024) >> 11;
            v17[1] = (*((unsigned __int16 *)v19 + 1) * *(__int16 *)((char *)&word_42198A + v19 - (char *)v4) + 1024) >> 11;
            v18 += 4;
            v17 += 4;
            v19 += 8;
          }
          while ( (int)v18 < (int)((__int16 *)aanscalefactor + 1) );
          v1 = cinfo;
        }
      }
      else
      {
        if ( fdct->divisors[v2] == nullptr )
          fdct->divisors[v2] = (int *)v1->mem->alloc_small(a1: (jpeg_common_struct *)v1, a2: 1, a3: 256u);
        v20 = fdct->divisors[v2];
        for ( i = 0; i < 64; ++i )
          v20[i] = 8 * v4->quantval[i];
      }
      p_quant_tbl_no += 21;
      ++ci;
    }
    while ( ci < v1->num_components );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A3C0
// Name: forward_DCT
// Source: json
//------------------------------------------------------------------------------
void __cdecl forward_DCT(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **sample_data,
        __int16 (*coef_blocks)[64],
        unsigned int start_row,
        unsigned int start_col,
        jpeg_compress_struct *num_blocks)
{
  jpeg_forward_dct *fdct; // eax
  int v8; // eax
  __int16 *v10; // edi
  jpeg_component_info *v11; // edx
  int *v12; // eax
  int i; // esi
  unsigned __int8 *v14; // ecx
  unsigned __int8 *v15; // ecx
  unsigned __int8 *v16; // ecx
  unsigned __int8 *v17; // ecx
  unsigned int v18; // esi
  int j; // ebx
  int v20; // ecx
  int v21; // eax
  int v22; // edx
  int v23; // edx
  int v24; // eax
  int v25; // eax
  int v26; // ecx
  int v27; // eax
  int v28; // edx
  int v29; // edx
  int v30; // eax
  int v31; // eax
  int v32; // ecx
  int v33; // eax
  int v34; // edx
  int v35; // edx
  int v36; // eax
  int v37; // eax
  int v38; // ecx
  int v39; // eax
  int v40; // edx
  int v41; // edx
  int v42; // eax
  int v43; // eax
  int workspace[64]; // [esp+0h] [ebp-104h] BYREF
  void (__cdecl *do_dct)(int *); // [esp+100h] [ebp-4h]
  jpeg_compress_struct *cinfoa; // [esp+10Ch] [ebp+8h]
  jpeg_component_info *compptra; // [esp+110h] [ebp+Ch]
  unsigned __int8 **sample_dataa; // [esp+114h] [ebp+10h]
  char *start_rowa; // [esp+11Ch] [ebp+18h]
  unsigned int num_blocksa; // [esp+124h] [ebp+20h]

  fdct = cinfo->fdct;
  do_dct = (void (__cdecl *)(int *))fdct[1].start_pass;
  v8 = *((_DWORD *)&fdct[1].forward_DCT + compptr->quant_tbl_no);
  if ( num_blocks != nullptr )
  {
    compptra = (jpeg_component_info *)&sample_data[start_row + 2];
    num_blocksa = v8 + 8;
    start_rowa = (char *)workspace - v8;
    sample_dataa = (unsigned __int8 **)((char *)&workspace[1] - v8);
    v10 = &(*coef_blocks)[2];
    cinfoa = num_blocks;
    do
    {
      v11 = compptra;
      v12 = workspace;
      for ( i = 2; i != 0; --i )
      {
        v14 = (unsigned __int8 *)v11[-1].quant_table + start_col;
        *v12 = *v14 - 128;
        v12[1] = v14[1] - 128;
        v12[2] = v14[2] - 128;
        v12[3] = v14[3] - 128;
        v12[4] = v14[4] - 128;
        v12[5] = v14[5] - 128;
        v12[6] = v14[6] - 128;
        v12[7] = v14[7] - 128;
        v15 = (unsigned __int8 *)v11[-1].dct_table + start_col;
        v12[8] = *v15 - 128;
        v12[9] = v15[1] - 128;
        v12[10] = v15[2] - 128;
        v12[11] = v15[3] - 128;
        v12[12] = v15[4] - 128;
        v12[13] = v15[5] - 128;
        v12[14] = v15[6] - 128;
        v12[15] = v15[7] - 128;
        v16 = (unsigned __int8 *)(start_col + v11->component_id);
        v12[16] = *v16 - 128;
        v12[17] = v16[1] - 128;
        v12[18] = v16[2] - 128;
        v12[19] = v16[3] - 128;
        v12[20] = v16[4] - 128;
        v12[21] = v16[5] - 128;
        v12[22] = v16[6] - 128;
        v12[23] = v16[7] - 128;
        v17 = (unsigned __int8 *)(start_col + v11->component_index);
        v12[24] = *v17 - 128;
        v12[25] = v17[1] - 128;
        v12[26] = v17[2] - 128;
        v12[27] = v17[3] - 128;
        v12[28] = v17[4] - 128;
        v12[29] = v17[5] - 128;
        v12[30] = v17[6] - 128;
        v12[31] = v17[7] - 128;
        v12 += 32;
        v11 = (jpeg_component_info *)((char *)v11 + 16);
      }
      do_dct(a1: workspace);
      v18 = num_blocksa;
      for ( j = 0; j < 64; j += 4 )
      {
        v20 = *(_DWORD *)(v18 - 8);
        v21 = workspace[j];
        v22 = v20 >> 1;
        if ( v21 >= 0 )
        {
          v25 = v22 + v21;
          if ( v25 < v20 )
            LOWORD(v24) = 0;
          else
            v24 = v25 / v20;
        }
        else
        {
          v23 = v22 - v21;
          if ( v23 < v20 )
            LOWORD(v24) = 0;
          else
            v24 = -(v23 / v20);
        }
        *(v10 - 2) = v24;
        v26 = *(_DWORD *)(v18 - 4);
        v27 = workspace[j + 1];
        v28 = v26 >> 1;
        if ( v27 >= 0 )
        {
          v31 = v28 + v27;
          if ( v31 < v26 )
            LOWORD(v30) = 0;
          else
            v30 = v31 / v26;
        }
        else
        {
          v29 = v28 - v27;
          if ( v29 < v26 )
            LOWORD(v30) = 0;
          else
            v30 = -(v29 / v26);
        }
        *(v10 - 1) = v30;
        v32 = *(_DWORD *)v18;
        v33 = *(_DWORD *)&start_rowa[v18];
        v34 = *(int *)v18 >> 1;
        if ( v33 >= 0 )
        {
          v37 = v34 + v33;
          if ( v37 < v32 )
            LOWORD(v36) = 0;
          else
            v36 = v37 / v32;
        }
        else
        {
          v35 = v34 - v33;
          if ( v35 < v32 )
            LOWORD(v36) = 0;
          else
            v36 = -(v35 / v32);
        }
        *v10 = v36;
        v38 = *(_DWORD *)(v18 + 4);
        v39 = *(int *)((char *)sample_dataa + v18);
        v40 = v38 >> 1;
        if ( v39 >= 0 )
        {
          v43 = v40 + v39;
          if ( v43 < v38 )
            LOWORD(v42) = 0;
          else
            v42 = v43 / v38;
        }
        else
        {
          v41 = v40 - v39;
          if ( v41 < v38 )
            LOWORD(v42) = 0;
          else
            v42 = -(v41 / v38);
        }
        v10[1] = v42;
        v10 += 4;
        v18 += 16;
      }
      start_col += 8;
      cinfoa = (jpeg_compress_struct *)((char *)cinfoa - 1);
    }
    while ( cinfoa != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040A6B0
// Name: forward_DCT_float
// Source: json
//------------------------------------------------------------------------------
void __cdecl forward_DCT_float(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **sample_data,
        __int16 (*coef_blocks)[64],
        unsigned int start_row,
        unsigned int start_col,
        jpeg_component_info *num_blocks)
{
  jpeg_forward_dct *fdct; // eax
  unsigned __int8 *v9; // eax
  int v10; // edx
  unsigned __int8 *v11; // eax
  float v12; // xmm0_4
  unsigned __int8 *v13; // eax
  int v14; // ecx
  unsigned __int8 *v15; // eax
  int v16; // edx
  unsigned __int8 *v17; // eax
  int v18; // ecx
  unsigned __int8 *v19; // eax
  int v20; // edx
  unsigned __int8 *v21; // eax
  int v22; // ecx
  unsigned __int8 *v23; // eax
  int v24; // edx
  unsigned __int8 *v25; // eax
  int v26; // ecx
  unsigned __int8 *v27; // eax
  int v28; // edx
  unsigned __int8 *v29; // eax
  int v30; // ecx
  unsigned __int8 *v31; // eax
  int v32; // edx
  unsigned __int8 *v33; // eax
  int v34; // ecx
  unsigned __int8 *v35; // eax
  int v36; // edx
  unsigned __int8 *v37; // eax
  int v38; // ecx
  unsigned __int8 *v39; // eax
  int i; // eax
  float workspace[64]; // [esp+8h] [ebp-108h] BYREF
  void (__cdecl *do_dct)(float *); // [esp+108h] [ebp-8h]
  float *divisors; // [esp+10Ch] [ebp-4h]
  jpeg_component_info *compptra; // [esp+11Ch] [ebp+Ch]

  fdct = cinfo->fdct;
  do_dct = (void (__cdecl *)(float *))fdct[3].forward_DCT;
  divisors = *((float **)&fdct[4].start_pass + compptr->quant_tbl_no);
  if ( num_blocks != nullptr )
  {
    for ( compptra = num_blocks; compptra != nullptr; compptra = (jpeg_component_info *)((char *)compptra - 1) )
    {
      v9 = sample_data[start_row];
      v10 = v9[start_col];
      v11 = &v9[start_col];
      workspace[0] = (float)(v10 - 128);
      workspace[1] = (float)(v11[1] - 128);
      workspace[2] = (float)(v11[2] - 128);
      workspace[3] = (float)(v11[3] - 128);
      workspace[4] = (float)(v11[4] - 128);
      workspace[5] = (float)(v11[5] - 128);
      workspace[6] = (float)(v11[6] - 128);
      v12 = (float)(v11[7] - 128);
      v13 = sample_data[start_row + 1];
      workspace[7] = v12;
      v14 = v13[start_col];
      v15 = &v13[start_col];
      workspace[8] = (float)(v14 - 128);
      workspace[9] = (float)(v15[1] - 128);
      workspace[10] = (float)(v15[2] - 128);
      workspace[11] = (float)(v15[3] - 128);
      workspace[12] = (float)(v15[4] - 128);
      workspace[13] = (float)(v15[5] - 128);
      workspace[14] = (float)(v15[6] - 128);
      v16 = v15[7] - 128;
      v17 = sample_data[start_row + 2];
      workspace[15] = (float)v16;
      v18 = v17[start_col];
      v19 = &v17[start_col];
      workspace[16] = (float)(v18 - 128);
      workspace[17] = (float)(v19[1] - 128);
      workspace[18] = (float)(v19[2] - 128);
      workspace[19] = (float)(v19[3] - 128);
      workspace[20] = (float)(v19[4] - 128);
      workspace[21] = (float)(v19[5] - 128);
      workspace[22] = (float)(v19[6] - 128);
      v20 = v19[7];
      v21 = sample_data[start_row + 3];
      workspace[23] = (float)(v20 - 128);
      v22 = v21[start_col];
      v23 = &v21[start_col];
      workspace[24] = (float)(v22 - 128);
      workspace[25] = (float)(v23[1] - 128);
      workspace[26] = (float)(v23[2] - 128);
      workspace[27] = (float)(v23[3] - 128);
      workspace[28] = (float)(v23[4] - 128);
      workspace[29] = (float)(v23[5] - 128);
      workspace[30] = (float)(v23[6] - 128);
      v24 = v23[7];
      v25 = sample_data[start_row + 4];
      workspace[31] = (float)(v24 - 128);
      v26 = v25[start_col];
      v27 = &v25[start_col];
      workspace[32] = (float)(v26 - 128);
      workspace[33] = (float)(v27[1] - 128);
      workspace[34] = (float)(v27[2] - 128);
      workspace[35] = (float)(v27[3] - 128);
      workspace[36] = (float)(v27[4] - 128);
      workspace[37] = (float)(v27[5] - 128);
      workspace[38] = (float)(v27[6] - 128);
      v28 = v27[7];
      v29 = sample_data[start_row + 5];
      workspace[39] = (float)(v28 - 128);
      v30 = v29[start_col];
      v31 = &v29[start_col];
      workspace[40] = (float)(v30 - 128);
      workspace[41] = (float)(v31[1] - 128);
      workspace[42] = (float)(v31[2] - 128);
      workspace[43] = (float)(v31[3] - 128);
      workspace[44] = (float)(v31[4] - 128);
      workspace[45] = (float)(v31[5] - 128);
      workspace[46] = (float)(v31[6] - 128);
      v32 = v31[7];
      v33 = sample_data[start_row + 6];
      workspace[47] = (float)(v32 - 128);
      v34 = v33[start_col];
      v35 = &v33[start_col];
      workspace[48] = (float)(v34 - 128);
      workspace[49] = (float)(v35[1] - 128);
      workspace[50] = (float)(v35[2] - 128);
      workspace[51] = (float)(v35[3] - 128);
      workspace[52] = (float)(v35[4] - 128);
      workspace[53] = (float)(v35[5] - 128);
      workspace[54] = (float)(v35[6] - 128);
      v36 = v35[7];
      v37 = sample_data[start_row + 7];
      workspace[55] = (float)(v36 - 128);
      v38 = v37[start_col];
      v39 = &v37[start_col];
      workspace[56] = (float)(v38 - 128);
      workspace[57] = (float)(v39[1] - 128);
      workspace[58] = (float)(v39[2] - 128);
      workspace[59] = (float)(v39[3] - 128);
      workspace[60] = (float)(v39[4] - 128);
      workspace[61] = (float)(v39[5] - 128);
      workspace[62] = (float)(v39[6] - 128);
      workspace[63] = (float)(v39[7] - 128);
      do_dct(a1: workspace);
      for ( i = 0; i < 64; ++i )
        (*coef_blocks)[i] = (int)(float)((float)(divisors[i] * workspace[i]) + 16384.5) - 0x4000;
      ++coef_blocks;
      start_col += 8;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040ACB0
// Name: _jinit_forward_dct
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_forward_dct(jpeg_common_struct *cinfo)
{
  jpeg_forward_dct *v1; // esi
  J_DCT_METHOD v2; // eax
  __int32 v3; // eax

  v1 = (jpeg_forward_dct *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 48);
  cinfo[14].progress = (jpeg_progress_mgr *)v1;
  v1->start_pass = start_pass_fdctmgr;
  v2 = *(_DWORD *)&cinfo[7].is_decompressor;
  if ( v2 == JDCT_ISLOW )
  {
    v1[1].start_pass = (void (__cdecl *)(jpeg_compress_struct *))jpeg_fdct_islow;
    goto LABEL_8;
  }
  v3 = v2 - 1;
  if ( v3 == 0 )
  {
    v1[1].start_pass = (void (__cdecl *)(jpeg_compress_struct *))jpeg_fdct_ifast;
LABEL_8:
    v1->forward_DCT = (void (__cdecl *)(jpeg_compress_struct *, jpeg_component_info *, unsigned __int8 **, __int16 (*)[64], unsigned int, unsigned int, unsigned int))forward_DCT;
    goto LABEL_9;
  }
  if ( v3 == 1 )
  {
    v1->forward_DCT = (void (__cdecl *)(jpeg_compress_struct *, jpeg_component_info *, unsigned __int8 **, __int16 (*)[64], unsigned int, unsigned int, unsigned int))forward_DCT_float;
    v1[3].forward_DCT = (void (__cdecl *)(jpeg_compress_struct *, jpeg_component_info *, unsigned __int8 **, __int16 (*)[64], unsigned int, unsigned int, unsigned int))jpeg_fdct_float;
  }
  else
  {
    cinfo->err->msg_code = 48;
    cinfo->err->error_exit(a1: cinfo);
  }
LABEL_9:
  v1[1].forward_DCT = nullptr;
  v1[4].start_pass = nullptr;
  v1[2].start_pass = nullptr;
  v1[4].forward_DCT = nullptr;
  v1[2].forward_DCT = nullptr;
  v1[5].start_pass = nullptr;
  v1[3].start_pass = nullptr;
  v1[5].forward_DCT = nullptr;
}

} // namespace statsmap

// ============================================================
// Overlay from VXConsole (Missing functions)
// ============================================================
namespace VXConsole {

//------------------------------------------------------------------------------
// Address: 0x00433340
// Name: start_pass_fdctmgr
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_fdctmgr(jpeg_compress_struct *cinfo)
{
  jpeg_compress_struct *v1; // edi
  int v2; // esi
  J_DCT_METHOD dct_method; // eax
  JQUANT_TBL *v4; // ebx
  __int32 v5; // eax
  double *v6; // eax
  int v7; // edx
  unsigned __int16 *v8; // ecx
  double v9; // xmm2_8
  float v10; // xmm1_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  int *v17; // ecx
  __int16 *v18; // edx
  char *v19; // eax
  int *v20; // esi
  int i; // eax
  int ci; // [esp+4h] [ebp-Ch]
  int *p_quant_tbl_no; // [esp+8h] [ebp-8h]
  my_fdct_controller *fdct; // [esp+Ch] [ebp-4h]

  v1 = cinfo;
  fdct = (my_fdct_controller *)cinfo->fdct;
  ci = 0;
  if ( cinfo->num_components > 0 )
  {
    p_quant_tbl_no = &cinfo->comp_info->quant_tbl_no;
    do
    {
      v2 = *p_quant_tbl_no;
      if ( (unsigned int)*p_quant_tbl_no > 3 || v1->quant_tbl_ptrs[v2] == nullptr )
      {
        v1->err->msg_code = 52;
        v1->err->msg_parm.i[0] = v2;
        v1->err->error_exit(a1: (jpeg_common_struct *)v1);
      }
      dct_method = v1->dct_method;
      v4 = v1->quant_tbl_ptrs[v2];
      if ( dct_method != JDCT_ISLOW )
      {
        v5 = dct_method - 1;
        if ( v5 != 0 )
        {
          if ( v5 == 1 )
          {
            if ( fdct->float_divisors[v2] == nullptr )
              fdct->float_divisors[v2] = (float *)v1->mem->alloc_small(a1: (jpeg_common_struct *)v1, a2: 1, a3: 256u);
            v6 = (double *)aanscalefactor;
            v7 = (int)(fdct->float_divisors[v2] + 2);
            v8 = &v4->quantval[2];
            do
            {
              v9 = 1.0 / ((double)*(v8 - 2) * *v6 * 8.0);
              v8 += 8;
              v7 += 32;
              ++v6;
              v10 = v9;
              *(float *)(v7 - 40) = v10;
              v11 = 1.0 / ((double)*(v8 - 9) * *(v6 - 1) * 1.387039845 * 8.0);
              *(float *)(v7 - 36) = v11;
              v12 = 1.0 / ((double)*(v8 - 8) * *(v6 - 1) * 1.306562965 * 8.0);
              *(float *)(v7 - 32) = v12;
              v13 = 1.0 / ((double)*(v8 - 7) * *(v6 - 1) * 1.175875602 * 8.0);
              *(float *)(v7 - 28) = v13;
              v14 = 1.0 / ((double)*(v8 - 6) * *(v6 - 1) * 8.0);
              *(float *)(v7 - 24) = v14;
              v15 = 1.0 / ((double)*(v8 - 5) * *(v6 - 1) * 0.785694958 * 8.0);
              *(float *)(v7 - 20) = v15;
              v16 = 1.0 / ((double)*(v8 - 4) * *(v6 - 1) * 0.5411961 * 8.0);
              *(float *)(v7 - 16) = v16;
              *(float *)(v7 - 12) = 1.0 / ((double)*(v8 - 3) * *(v6 - 1) * 0.275899379 * 8.0);
            }
            while ( (int)v6 < (int)&DOUBLE_8_0 );
          }
          else
          {
            v1->err->msg_code = 48;
            v1->err->error_exit(a1: (jpeg_common_struct *)v1);
          }
        }
        else
        {
          if ( fdct->divisors[v2] == nullptr )
            fdct->divisors[v2] = (int *)v1->mem->alloc_small(a1: (jpeg_common_struct *)v1, a2: 1, a3: 256u);
          v17 = fdct->divisors[v2] + 2;
          v18 = &word_458CA2;
          v19 = (char *)&v4->quantval[2];
          do
          {
            *(v17 - 2) = (*(v18 - 1) * *((unsigned __int16 *)v19 - 2) + 1024) >> 11;
            *(v17 - 1) = (*v18 * *((unsigned __int16 *)v19 - 1) + 1024) >> 11;
            *v17 = (*(unsigned __int16 *)v19 * *(const __int16 *)((char *)aanscales + v19 - (char *)v4) + 1024) >> 11;
            v17[1] = (*((unsigned __int16 *)v19 + 1) * *(__int16 *)((char *)&word_458CA2 + v19 - (char *)v4) + 1024) >> 11;
            v18 += 4;
            v17 += 4;
            v19 += 8;
          }
          while ( (int)v18 < (int)((__int16 *)aanscalefactor + 1) );
          v1 = cinfo;
        }
      }
      else
      {
        if ( fdct->divisors[v2] == nullptr )
          fdct->divisors[v2] = (int *)v1->mem->alloc_small(a1: (jpeg_common_struct *)v1, a2: 1, a3: 256u);
        v20 = fdct->divisors[v2];
        for ( i = 0; i < 64; ++i )
          v20[i] = 8 * v4->quantval[i];
      }
      p_quant_tbl_no += 21;
      ++ci;
    }
    while ( ci < v1->num_components );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004336D0
// Name: forward_DCT
// Source: json
//------------------------------------------------------------------------------
void __cdecl forward_DCT(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **sample_data,
        __int16 (*coef_blocks)[64],
        unsigned int start_row,
        unsigned int start_col,
        jpeg_compress_struct *num_blocks)
{
  jpeg_forward_dct *fdct; // eax
  int v8; // eax
  __int16 *v10; // edi
  jpeg_component_info *v11; // edx
  int *v12; // eax
  int i; // esi
  unsigned __int8 *v14; // ecx
  unsigned __int8 *v15; // ecx
  unsigned __int8 *v16; // ecx
  unsigned __int8 *v17; // ecx
  unsigned int v18; // esi
  int j; // ebx
  int v20; // ecx
  int v21; // eax
  int v22; // edx
  int v23; // edx
  int v24; // eax
  int v25; // eax
  int v26; // ecx
  int v27; // eax
  int v28; // edx
  int v29; // edx
  int v30; // eax
  int v31; // eax
  int v32; // ecx
  int v33; // eax
  int v34; // edx
  int v35; // edx
  int v36; // eax
  int v37; // eax
  int v38; // ecx
  int v39; // eax
  int v40; // edx
  int v41; // edx
  int v42; // eax
  int v43; // eax
  int workspace[64]; // [esp+0h] [ebp-104h] BYREF
  void (__cdecl *do_dct)(int *); // [esp+100h] [ebp-4h]
  jpeg_compress_struct *cinfoa; // [esp+10Ch] [ebp+8h]
  jpeg_component_info *compptra; // [esp+110h] [ebp+Ch]
  unsigned __int8 **sample_dataa; // [esp+114h] [ebp+10h]
  char *start_rowa; // [esp+11Ch] [ebp+18h]
  unsigned int num_blocksa; // [esp+124h] [ebp+20h]

  fdct = cinfo->fdct;
  do_dct = (void (__cdecl *)(int *))fdct[1].start_pass;
  v8 = *((_DWORD *)&fdct[1].forward_DCT + compptr->quant_tbl_no);
  if ( num_blocks != nullptr )
  {
    compptra = (jpeg_component_info *)&sample_data[start_row + 2];
    num_blocksa = v8 + 8;
    start_rowa = (char *)workspace - v8;
    sample_dataa = (unsigned __int8 **)((char *)&workspace[1] - v8);
    v10 = &(*coef_blocks)[2];
    cinfoa = num_blocks;
    do
    {
      v11 = compptra;
      v12 = workspace;
      for ( i = 2; i != 0; --i )
      {
        v14 = (unsigned __int8 *)v11[-1].quant_table + start_col;
        *v12 = *v14 - 128;
        v12[1] = v14[1] - 128;
        v12[2] = v14[2] - 128;
        v12[3] = v14[3] - 128;
        v12[4] = v14[4] - 128;
        v12[5] = v14[5] - 128;
        v12[6] = v14[6] - 128;
        v12[7] = v14[7] - 128;
        v15 = (unsigned __int8 *)v11[-1].dct_table + start_col;
        v12[8] = *v15 - 128;
        v12[9] = v15[1] - 128;
        v12[10] = v15[2] - 128;
        v12[11] = v15[3] - 128;
        v12[12] = v15[4] - 128;
        v12[13] = v15[5] - 128;
        v12[14] = v15[6] - 128;
        v12[15] = v15[7] - 128;
        v16 = (unsigned __int8 *)(start_col + v11->component_id);
        v12[16] = *v16 - 128;
        v12[17] = v16[1] - 128;
        v12[18] = v16[2] - 128;
        v12[19] = v16[3] - 128;
        v12[20] = v16[4] - 128;
        v12[21] = v16[5] - 128;
        v12[22] = v16[6] - 128;
        v12[23] = v16[7] - 128;
        v17 = (unsigned __int8 *)(start_col + v11->component_index);
        v12[24] = *v17 - 128;
        v12[25] = v17[1] - 128;
        v12[26] = v17[2] - 128;
        v12[27] = v17[3] - 128;
        v12[28] = v17[4] - 128;
        v12[29] = v17[5] - 128;
        v12[30] = v17[6] - 128;
        v12[31] = v17[7] - 128;
        v12 += 32;
        v11 = (jpeg_component_info *)((char *)v11 + 16);
      }
      do_dct(a1: workspace);
      v18 = num_blocksa;
      for ( j = 0; j < 64; j += 4 )
      {
        v20 = *(_DWORD *)(v18 - 8);
        v21 = workspace[j];
        v22 = v20 >> 1;
        if ( v21 >= 0 )
        {
          v25 = v22 + v21;
          if ( v25 < v20 )
            LOWORD(v24) = 0;
          else
            v24 = v25 / v20;
        }
        else
        {
          v23 = v22 - v21;
          if ( v23 < v20 )
            LOWORD(v24) = 0;
          else
            v24 = -(v23 / v20);
        }
        *(v10 - 2) = v24;
        v26 = *(_DWORD *)(v18 - 4);
        v27 = workspace[j + 1];
        v28 = v26 >> 1;
        if ( v27 >= 0 )
        {
          v31 = v28 + v27;
          if ( v31 < v26 )
            LOWORD(v30) = 0;
          else
            v30 = v31 / v26;
        }
        else
        {
          v29 = v28 - v27;
          if ( v29 < v26 )
            LOWORD(v30) = 0;
          else
            v30 = -(v29 / v26);
        }
        *(v10 - 1) = v30;
        v32 = *(_DWORD *)v18;
        v33 = *(_DWORD *)&start_rowa[v18];
        v34 = *(int *)v18 >> 1;
        if ( v33 >= 0 )
        {
          v37 = v34 + v33;
          if ( v37 < v32 )
            LOWORD(v36) = 0;
          else
            v36 = v37 / v32;
        }
        else
        {
          v35 = v34 - v33;
          if ( v35 < v32 )
            LOWORD(v36) = 0;
          else
            v36 = -(v35 / v32);
        }
        *v10 = v36;
        v38 = *(_DWORD *)(v18 + 4);
        v39 = *(int *)((char *)sample_dataa + v18);
        v40 = v38 >> 1;
        if ( v39 >= 0 )
        {
          v43 = v40 + v39;
          if ( v43 < v38 )
            LOWORD(v42) = 0;
          else
            v42 = v43 / v38;
        }
        else
        {
          v41 = v40 - v39;
          if ( v41 < v38 )
            LOWORD(v42) = 0;
          else
            v42 = -(v41 / v38);
        }
        v10[1] = v42;
        v10 += 4;
        v18 += 16;
      }
      start_col += 8;
      cinfoa = (jpeg_compress_struct *)((char *)cinfoa - 1);
    }
    while ( cinfoa != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004339C0
// Name: forward_DCT_float
// Source: json
//------------------------------------------------------------------------------
void __cdecl forward_DCT_float(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **sample_data,
        __int16 (*coef_blocks)[64],
        unsigned int start_row,
        unsigned int start_col,
        jpeg_component_info *num_blocks)
{
  jpeg_forward_dct *fdct; // eax
  unsigned __int8 *v9; // eax
  int v10; // edx
  unsigned __int8 *v11; // eax
  float v12; // xmm0_4
  unsigned __int8 *v13; // eax
  int v14; // ecx
  unsigned __int8 *v15; // eax
  int v16; // edx
  unsigned __int8 *v17; // eax
  int v18; // ecx
  unsigned __int8 *v19; // eax
  int v20; // edx
  unsigned __int8 *v21; // eax
  int v22; // ecx
  unsigned __int8 *v23; // eax
  int v24; // edx
  unsigned __int8 *v25; // eax
  int v26; // ecx
  unsigned __int8 *v27; // eax
  int v28; // edx
  unsigned __int8 *v29; // eax
  int v30; // ecx
  unsigned __int8 *v31; // eax
  int v32; // edx
  unsigned __int8 *v33; // eax
  int v34; // ecx
  unsigned __int8 *v35; // eax
  int v36; // edx
  unsigned __int8 *v37; // eax
  int v38; // ecx
  unsigned __int8 *v39; // eax
  int i; // eax
  float workspace[64]; // [esp+8h] [ebp-108h] BYREF
  void (__cdecl *do_dct)(float *); // [esp+108h] [ebp-8h]
  float *divisors; // [esp+10Ch] [ebp-4h]
  jpeg_component_info *compptra; // [esp+11Ch] [ebp+Ch]

  fdct = cinfo->fdct;
  do_dct = (void (__cdecl *)(float *))fdct[3].forward_DCT;
  divisors = *((float **)&fdct[4].start_pass + compptr->quant_tbl_no);
  if ( num_blocks != nullptr )
  {
    for ( compptra = num_blocks; compptra != nullptr; compptra = (jpeg_component_info *)((char *)compptra - 1) )
    {
      v9 = sample_data[start_row];
      v10 = v9[start_col];
      v11 = &v9[start_col];
      workspace[0] = (float)(v10 - 128);
      workspace[1] = (float)(v11[1] - 128);
      workspace[2] = (float)(v11[2] - 128);
      workspace[3] = (float)(v11[3] - 128);
      workspace[4] = (float)(v11[4] - 128);
      workspace[5] = (float)(v11[5] - 128);
      workspace[6] = (float)(v11[6] - 128);
      v12 = (float)(v11[7] - 128);
      v13 = sample_data[start_row + 1];
      workspace[7] = v12;
      v14 = v13[start_col];
      v15 = &v13[start_col];
      workspace[8] = (float)(v14 - 128);
      workspace[9] = (float)(v15[1] - 128);
      workspace[10] = (float)(v15[2] - 128);
      workspace[11] = (float)(v15[3] - 128);
      workspace[12] = (float)(v15[4] - 128);
      workspace[13] = (float)(v15[5] - 128);
      workspace[14] = (float)(v15[6] - 128);
      v16 = v15[7] - 128;
      v17 = sample_data[start_row + 2];
      workspace[15] = (float)v16;
      v18 = v17[start_col];
      v19 = &v17[start_col];
      workspace[16] = (float)(v18 - 128);
      workspace[17] = (float)(v19[1] - 128);
      workspace[18] = (float)(v19[2] - 128);
      workspace[19] = (float)(v19[3] - 128);
      workspace[20] = (float)(v19[4] - 128);
      workspace[21] = (float)(v19[5] - 128);
      workspace[22] = (float)(v19[6] - 128);
      v20 = v19[7];
      v21 = sample_data[start_row + 3];
      workspace[23] = (float)(v20 - 128);
      v22 = v21[start_col];
      v23 = &v21[start_col];
      workspace[24] = (float)(v22 - 128);
      workspace[25] = (float)(v23[1] - 128);
      workspace[26] = (float)(v23[2] - 128);
      workspace[27] = (float)(v23[3] - 128);
      workspace[28] = (float)(v23[4] - 128);
      workspace[29] = (float)(v23[5] - 128);
      workspace[30] = (float)(v23[6] - 128);
      v24 = v23[7];
      v25 = sample_data[start_row + 4];
      workspace[31] = (float)(v24 - 128);
      v26 = v25[start_col];
      v27 = &v25[start_col];
      workspace[32] = (float)(v26 - 128);
      workspace[33] = (float)(v27[1] - 128);
      workspace[34] = (float)(v27[2] - 128);
      workspace[35] = (float)(v27[3] - 128);
      workspace[36] = (float)(v27[4] - 128);
      workspace[37] = (float)(v27[5] - 128);
      workspace[38] = (float)(v27[6] - 128);
      v28 = v27[7];
      v29 = sample_data[start_row + 5];
      workspace[39] = (float)(v28 - 128);
      v30 = v29[start_col];
      v31 = &v29[start_col];
      workspace[40] = (float)(v30 - 128);
      workspace[41] = (float)(v31[1] - 128);
      workspace[42] = (float)(v31[2] - 128);
      workspace[43] = (float)(v31[3] - 128);
      workspace[44] = (float)(v31[4] - 128);
      workspace[45] = (float)(v31[5] - 128);
      workspace[46] = (float)(v31[6] - 128);
      v32 = v31[7];
      v33 = sample_data[start_row + 6];
      workspace[47] = (float)(v32 - 128);
      v34 = v33[start_col];
      v35 = &v33[start_col];
      workspace[48] = (float)(v34 - 128);
      workspace[49] = (float)(v35[1] - 128);
      workspace[50] = (float)(v35[2] - 128);
      workspace[51] = (float)(v35[3] - 128);
      workspace[52] = (float)(v35[4] - 128);
      workspace[53] = (float)(v35[5] - 128);
      workspace[54] = (float)(v35[6] - 128);
      v36 = v35[7];
      v37 = sample_data[start_row + 7];
      workspace[55] = (float)(v36 - 128);
      v38 = v37[start_col];
      v39 = &v37[start_col];
      workspace[56] = (float)(v38 - 128);
      workspace[57] = (float)(v39[1] - 128);
      workspace[58] = (float)(v39[2] - 128);
      workspace[59] = (float)(v39[3] - 128);
      workspace[60] = (float)(v39[4] - 128);
      workspace[61] = (float)(v39[5] - 128);
      workspace[62] = (float)(v39[6] - 128);
      workspace[63] = (float)(v39[7] - 128);
      do_dct(a1: workspace);
      for ( i = 0; i < 64; ++i )
        (*coef_blocks)[i] = (int)(float)((float)(divisors[i] * workspace[i]) + 16384.5) - 0x4000;
      ++coef_blocks;
      start_col += 8;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00433FC0
// Name: _jinit_forward_dct
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_forward_dct(jpeg_common_struct *cinfo)
{
  jpeg_forward_dct *v1; // esi
  J_DCT_METHOD v2; // eax
  __int32 v3; // eax

  v1 = (jpeg_forward_dct *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 48);
  cinfo[14].progress = (jpeg_progress_mgr *)v1;
  v1->start_pass = start_pass_fdctmgr;
  v2 = *(_DWORD *)&cinfo[7].is_decompressor;
  if ( v2 == JDCT_ISLOW )
  {
    v1[1].start_pass = (void (__cdecl *)(jpeg_compress_struct *))jpeg_fdct_islow;
    goto LABEL_8;
  }
  v3 = v2 - 1;
  if ( v3 == 0 )
  {
    v1[1].start_pass = (void (__cdecl *)(jpeg_compress_struct *))jpeg_fdct_ifast;
LABEL_8:
    v1->forward_DCT = (void (__cdecl *)(jpeg_compress_struct *, jpeg_component_info *, unsigned __int8 **, __int16 (*)[64], unsigned int, unsigned int, unsigned int))forward_DCT;
    goto LABEL_9;
  }
  if ( v3 == 1 )
  {
    v1->forward_DCT = (void (__cdecl *)(jpeg_compress_struct *, jpeg_component_info *, unsigned __int8 **, __int16 (*)[64], unsigned int, unsigned int, unsigned int))forward_DCT_float;
    v1[3].forward_DCT = (void (__cdecl *)(jpeg_compress_struct *, jpeg_component_info *, unsigned __int8 **, __int16 (*)[64], unsigned int, unsigned int, unsigned int))jpeg_fdct_float;
  }
  else
  {
    cinfo->err->msg_code = 48;
    cinfo->err->error_exit(a1: cinfo);
  }
LABEL_9:
  v1[1].forward_DCT = nullptr;
  v1[4].start_pass = nullptr;
  v1[2].start_pass = nullptr;
  v1[4].forward_DCT = nullptr;
  v1[2].forward_DCT = nullptr;
  v1[5].start_pass = nullptr;
  v1[3].start_pass = nullptr;
  v1[5].forward_DCT = nullptr;
}

} // namespace VXConsole

// ============================================================
// Overlay from vxconsole_ps3 (Missing functions)
// ============================================================
namespace vxconsole_ps3 {

//------------------------------------------------------------------------------
// Address: 0x00420140
// Name: start_pass_fdctmgr
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_fdctmgr(jpeg_compress_struct *cinfo)
{
  jpeg_compress_struct *v1; // edi
  int v2; // esi
  J_DCT_METHOD dct_method; // eax
  JQUANT_TBL *v4; // ebx
  __int32 v5; // eax
  double *v6; // eax
  int v7; // edx
  unsigned __int16 *v8; // ecx
  double v9; // xmm2_8
  float v10; // xmm1_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  float v13; // xmm1_4
  float v14; // xmm1_4
  float v15; // xmm1_4
  float v16; // xmm1_4
  int *v17; // ecx
  __int16 *v18; // edx
  char *v19; // eax
  int *v20; // esi
  int i; // eax
  int ci; // [esp+4h] [ebp-Ch]
  int *p_quant_tbl_no; // [esp+8h] [ebp-8h]
  my_fdct_controller *fdct; // [esp+Ch] [ebp-4h]

  v1 = cinfo;
  fdct = (my_fdct_controller *)cinfo->fdct;
  ci = 0;
  if ( cinfo->num_components > 0 )
  {
    p_quant_tbl_no = &cinfo->comp_info->quant_tbl_no;
    do
    {
      v2 = *p_quant_tbl_no;
      if ( (unsigned int)*p_quant_tbl_no > 3 || v1->quant_tbl_ptrs[v2] == nullptr )
      {
        v1->err->msg_code = 52;
        v1->err->msg_parm.i[0] = v2;
        v1->err->error_exit(a1: (jpeg_common_struct *)v1);
      }
      dct_method = v1->dct_method;
      v4 = v1->quant_tbl_ptrs[v2];
      if ( dct_method != JDCT_ISLOW )
      {
        v5 = dct_method - 1;
        if ( v5 != 0 )
        {
          if ( v5 == 1 )
          {
            if ( fdct->float_divisors[v2] == nullptr )
              fdct->float_divisors[v2] = (float *)v1->mem->alloc_small(a1: (jpeg_common_struct *)v1, a2: 1, a3: 256u);
            v6 = (double *)aanscalefactor;
            v7 = (int)(fdct->float_divisors[v2] + 2);
            v8 = &v4->quantval[2];
            do
            {
              v9 = 1.0 / ((double)*(v8 - 2) * *v6 * 8.0);
              v8 += 8;
              v7 += 32;
              ++v6;
              v10 = v9;
              *(float *)(v7 - 40) = v10;
              v11 = 1.0 / ((double)*(v8 - 9) * *(v6 - 1) * 1.387039845 * 8.0);
              *(float *)(v7 - 36) = v11;
              v12 = 1.0 / ((double)*(v8 - 8) * *(v6 - 1) * 1.306562965 * 8.0);
              *(float *)(v7 - 32) = v12;
              v13 = 1.0 / ((double)*(v8 - 7) * *(v6 - 1) * 1.175875602 * 8.0);
              *(float *)(v7 - 28) = v13;
              v14 = 1.0 / ((double)*(v8 - 6) * *(v6 - 1) * 8.0);
              *(float *)(v7 - 24) = v14;
              v15 = 1.0 / ((double)*(v8 - 5) * *(v6 - 1) * 0.785694958 * 8.0);
              *(float *)(v7 - 20) = v15;
              v16 = 1.0 / ((double)*(v8 - 4) * *(v6 - 1) * 0.5411961 * 8.0);
              *(float *)(v7 - 16) = v16;
              *(float *)(v7 - 12) = 1.0 / ((double)*(v8 - 3) * *(v6 - 1) * 0.275899379 * 8.0);
            }
            while ( (int)v6 < (int)&DOUBLE_8_0 );
          }
          else
          {
            v1->err->msg_code = 48;
            v1->err->error_exit(a1: (jpeg_common_struct *)v1);
          }
        }
        else
        {
          if ( fdct->divisors[v2] == nullptr )
            fdct->divisors[v2] = (int *)v1->mem->alloc_small(a1: (jpeg_common_struct *)v1, a2: 1, a3: 256u);
          v17 = fdct->divisors[v2] + 2;
          v18 = &word_43F5D2;
          v19 = (char *)&v4->quantval[2];
          do
          {
            *(v17 - 2) = (*(v18 - 1) * *((unsigned __int16 *)v19 - 2) + 1024) >> 11;
            *(v17 - 1) = (*v18 * *((unsigned __int16 *)v19 - 1) + 1024) >> 11;
            *v17 = (*(unsigned __int16 *)v19 * *(const __int16 *)((char *)aanscales + v19 - (char *)v4) + 1024) >> 11;
            v17[1] = (*((unsigned __int16 *)v19 + 1) * *(__int16 *)((char *)&word_43F5D2 + v19 - (char *)v4) + 1024) >> 11;
            v18 += 4;
            v17 += 4;
            v19 += 8;
          }
          while ( (int)v18 < (int)((__int16 *)aanscalefactor + 1) );
          v1 = cinfo;
        }
      }
      else
      {
        if ( fdct->divisors[v2] == nullptr )
          fdct->divisors[v2] = (int *)v1->mem->alloc_small(a1: (jpeg_common_struct *)v1, a2: 1, a3: 256u);
        v20 = fdct->divisors[v2];
        for ( i = 0; i < 64; ++i )
          v20[i] = 8 * v4->quantval[i];
      }
      p_quant_tbl_no += 21;
      ++ci;
    }
    while ( ci < v1->num_components );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004204D0
// Name: forward_DCT
// Source: json
//------------------------------------------------------------------------------
void __cdecl forward_DCT(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **sample_data,
        __int16 (*coef_blocks)[64],
        unsigned int start_row,
        unsigned int start_col,
        jpeg_compress_struct *num_blocks)
{
  jpeg_forward_dct *fdct; // eax
  int v8; // eax
  __int16 *v10; // edi
  jpeg_component_info *v11; // edx
  int *v12; // eax
  int i; // esi
  unsigned __int8 *v14; // ecx
  unsigned __int8 *v15; // ecx
  unsigned __int8 *v16; // ecx
  unsigned __int8 *v17; // ecx
  unsigned int v18; // esi
  int j; // ebx
  int v20; // ecx
  int v21; // eax
  int v22; // edx
  int v23; // edx
  int v24; // eax
  int v25; // eax
  int v26; // ecx
  int v27; // eax
  int v28; // edx
  int v29; // edx
  int v30; // eax
  int v31; // eax
  int v32; // ecx
  int v33; // eax
  int v34; // edx
  int v35; // edx
  int v36; // eax
  int v37; // eax
  int v38; // ecx
  int v39; // eax
  int v40; // edx
  int v41; // edx
  int v42; // eax
  int v43; // eax
  int workspace[64]; // [esp+0h] [ebp-104h] BYREF
  void (__cdecl *do_dct)(int *); // [esp+100h] [ebp-4h]
  jpeg_compress_struct *cinfoa; // [esp+10Ch] [ebp+8h]
  jpeg_component_info *compptra; // [esp+110h] [ebp+Ch]
  unsigned __int8 **sample_dataa; // [esp+114h] [ebp+10h]
  char *start_rowa; // [esp+11Ch] [ebp+18h]
  unsigned int num_blocksa; // [esp+124h] [ebp+20h]

  fdct = cinfo->fdct;
  do_dct = (void (__cdecl *)(int *))fdct[1].start_pass;
  v8 = *((_DWORD *)&fdct[1].forward_DCT + compptr->quant_tbl_no);
  if ( num_blocks != nullptr )
  {
    compptra = (jpeg_component_info *)&sample_data[start_row + 2];
    num_blocksa = v8 + 8;
    start_rowa = (char *)workspace - v8;
    sample_dataa = (unsigned __int8 **)((char *)&workspace[1] - v8);
    v10 = &(*coef_blocks)[2];
    cinfoa = num_blocks;
    do
    {
      v11 = compptra;
      v12 = workspace;
      for ( i = 2; i != 0; --i )
      {
        v14 = (unsigned __int8 *)v11[-1].quant_table + start_col;
        *v12 = *v14 - 128;
        v12[1] = v14[1] - 128;
        v12[2] = v14[2] - 128;
        v12[3] = v14[3] - 128;
        v12[4] = v14[4] - 128;
        v12[5] = v14[5] - 128;
        v12[6] = v14[6] - 128;
        v12[7] = v14[7] - 128;
        v15 = (unsigned __int8 *)v11[-1].dct_table + start_col;
        v12[8] = *v15 - 128;
        v12[9] = v15[1] - 128;
        v12[10] = v15[2] - 128;
        v12[11] = v15[3] - 128;
        v12[12] = v15[4] - 128;
        v12[13] = v15[5] - 128;
        v12[14] = v15[6] - 128;
        v12[15] = v15[7] - 128;
        v16 = (unsigned __int8 *)(start_col + v11->component_id);
        v12[16] = *v16 - 128;
        v12[17] = v16[1] - 128;
        v12[18] = v16[2] - 128;
        v12[19] = v16[3] - 128;
        v12[20] = v16[4] - 128;
        v12[21] = v16[5] - 128;
        v12[22] = v16[6] - 128;
        v12[23] = v16[7] - 128;
        v17 = (unsigned __int8 *)(start_col + v11->component_index);
        v12[24] = *v17 - 128;
        v12[25] = v17[1] - 128;
        v12[26] = v17[2] - 128;
        v12[27] = v17[3] - 128;
        v12[28] = v17[4] - 128;
        v12[29] = v17[5] - 128;
        v12[30] = v17[6] - 128;
        v12[31] = v17[7] - 128;
        v12 += 32;
        v11 = (jpeg_component_info *)((char *)v11 + 16);
      }
      do_dct(a1: workspace);
      v18 = num_blocksa;
      for ( j = 0; j < 64; j += 4 )
      {
        v20 = *(_DWORD *)(v18 - 8);
        v21 = workspace[j];
        v22 = v20 >> 1;
        if ( v21 >= 0 )
        {
          v25 = v22 + v21;
          if ( v25 < v20 )
            LOWORD(v24) = 0;
          else
            v24 = v25 / v20;
        }
        else
        {
          v23 = v22 - v21;
          if ( v23 < v20 )
            LOWORD(v24) = 0;
          else
            v24 = -(v23 / v20);
        }
        *(v10 - 2) = v24;
        v26 = *(_DWORD *)(v18 - 4);
        v27 = workspace[j + 1];
        v28 = v26 >> 1;
        if ( v27 >= 0 )
        {
          v31 = v28 + v27;
          if ( v31 < v26 )
            LOWORD(v30) = 0;
          else
            v30 = v31 / v26;
        }
        else
        {
          v29 = v28 - v27;
          if ( v29 < v26 )
            LOWORD(v30) = 0;
          else
            v30 = -(v29 / v26);
        }
        *(v10 - 1) = v30;
        v32 = *(_DWORD *)v18;
        v33 = *(_DWORD *)&start_rowa[v18];
        v34 = *(int *)v18 >> 1;
        if ( v33 >= 0 )
        {
          v37 = v34 + v33;
          if ( v37 < v32 )
            LOWORD(v36) = 0;
          else
            v36 = v37 / v32;
        }
        else
        {
          v35 = v34 - v33;
          if ( v35 < v32 )
            LOWORD(v36) = 0;
          else
            v36 = -(v35 / v32);
        }
        *v10 = v36;
        v38 = *(_DWORD *)(v18 + 4);
        v39 = *(int *)((char *)sample_dataa + v18);
        v40 = v38 >> 1;
        if ( v39 >= 0 )
        {
          v43 = v40 + v39;
          if ( v43 < v38 )
            LOWORD(v42) = 0;
          else
            v42 = v43 / v38;
        }
        else
        {
          v41 = v40 - v39;
          if ( v41 < v38 )
            LOWORD(v42) = 0;
          else
            v42 = -(v41 / v38);
        }
        v10[1] = v42;
        v10 += 4;
        v18 += 16;
      }
      start_col += 8;
      cinfoa = (jpeg_compress_struct *)((char *)cinfoa - 1);
    }
    while ( cinfoa != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004207C0
// Name: forward_DCT_float
// Source: json
//------------------------------------------------------------------------------
void __cdecl forward_DCT_float(
        jpeg_compress_struct *cinfo,
        jpeg_component_info *compptr,
        unsigned __int8 **sample_data,
        __int16 (*coef_blocks)[64],
        unsigned int start_row,
        unsigned int start_col,
        jpeg_component_info *num_blocks)
{
  jpeg_forward_dct *fdct; // eax
  unsigned __int8 *v9; // eax
  int v10; // edx
  unsigned __int8 *v11; // eax
  float v12; // xmm0_4
  unsigned __int8 *v13; // eax
  int v14; // ecx
  unsigned __int8 *v15; // eax
  int v16; // edx
  unsigned __int8 *v17; // eax
  int v18; // ecx
  unsigned __int8 *v19; // eax
  int v20; // edx
  unsigned __int8 *v21; // eax
  int v22; // ecx
  unsigned __int8 *v23; // eax
  int v24; // edx
  unsigned __int8 *v25; // eax
  int v26; // ecx
  unsigned __int8 *v27; // eax
  int v28; // edx
  unsigned __int8 *v29; // eax
  int v30; // ecx
  unsigned __int8 *v31; // eax
  int v32; // edx
  unsigned __int8 *v33; // eax
  int v34; // ecx
  unsigned __int8 *v35; // eax
  int v36; // edx
  unsigned __int8 *v37; // eax
  int v38; // ecx
  unsigned __int8 *v39; // eax
  int i; // eax
  float workspace[64]; // [esp+8h] [ebp-108h] BYREF
  void (__cdecl *do_dct)(float *); // [esp+108h] [ebp-8h]
  float *divisors; // [esp+10Ch] [ebp-4h]
  jpeg_component_info *compptra; // [esp+11Ch] [ebp+Ch]

  fdct = cinfo->fdct;
  do_dct = (void (__cdecl *)(float *))fdct[3].forward_DCT;
  divisors = *((float **)&fdct[4].start_pass + compptr->quant_tbl_no);
  if ( num_blocks != nullptr )
  {
    for ( compptra = num_blocks; compptra != nullptr; compptra = (jpeg_component_info *)((char *)compptra - 1) )
    {
      v9 = sample_data[start_row];
      v10 = v9[start_col];
      v11 = &v9[start_col];
      workspace[0] = (float)(v10 - 128);
      workspace[1] = (float)(v11[1] - 128);
      workspace[2] = (float)(v11[2] - 128);
      workspace[3] = (float)(v11[3] - 128);
      workspace[4] = (float)(v11[4] - 128);
      workspace[5] = (float)(v11[5] - 128);
      workspace[6] = (float)(v11[6] - 128);
      v12 = (float)(v11[7] - 128);
      v13 = sample_data[start_row + 1];
      workspace[7] = v12;
      v14 = v13[start_col];
      v15 = &v13[start_col];
      workspace[8] = (float)(v14 - 128);
      workspace[9] = (float)(v15[1] - 128);
      workspace[10] = (float)(v15[2] - 128);
      workspace[11] = (float)(v15[3] - 128);
      workspace[12] = (float)(v15[4] - 128);
      workspace[13] = (float)(v15[5] - 128);
      workspace[14] = (float)(v15[6] - 128);
      v16 = v15[7] - 128;
      v17 = sample_data[start_row + 2];
      workspace[15] = (float)v16;
      v18 = v17[start_col];
      v19 = &v17[start_col];
      workspace[16] = (float)(v18 - 128);
      workspace[17] = (float)(v19[1] - 128);
      workspace[18] = (float)(v19[2] - 128);
      workspace[19] = (float)(v19[3] - 128);
      workspace[20] = (float)(v19[4] - 128);
      workspace[21] = (float)(v19[5] - 128);
      workspace[22] = (float)(v19[6] - 128);
      v20 = v19[7];
      v21 = sample_data[start_row + 3];
      workspace[23] = (float)(v20 - 128);
      v22 = v21[start_col];
      v23 = &v21[start_col];
      workspace[24] = (float)(v22 - 128);
      workspace[25] = (float)(v23[1] - 128);
      workspace[26] = (float)(v23[2] - 128);
      workspace[27] = (float)(v23[3] - 128);
      workspace[28] = (float)(v23[4] - 128);
      workspace[29] = (float)(v23[5] - 128);
      workspace[30] = (float)(v23[6] - 128);
      v24 = v23[7];
      v25 = sample_data[start_row + 4];
      workspace[31] = (float)(v24 - 128);
      v26 = v25[start_col];
      v27 = &v25[start_col];
      workspace[32] = (float)(v26 - 128);
      workspace[33] = (float)(v27[1] - 128);
      workspace[34] = (float)(v27[2] - 128);
      workspace[35] = (float)(v27[3] - 128);
      workspace[36] = (float)(v27[4] - 128);
      workspace[37] = (float)(v27[5] - 128);
      workspace[38] = (float)(v27[6] - 128);
      v28 = v27[7];
      v29 = sample_data[start_row + 5];
      workspace[39] = (float)(v28 - 128);
      v30 = v29[start_col];
      v31 = &v29[start_col];
      workspace[40] = (float)(v30 - 128);
      workspace[41] = (float)(v31[1] - 128);
      workspace[42] = (float)(v31[2] - 128);
      workspace[43] = (float)(v31[3] - 128);
      workspace[44] = (float)(v31[4] - 128);
      workspace[45] = (float)(v31[5] - 128);
      workspace[46] = (float)(v31[6] - 128);
      v32 = v31[7];
      v33 = sample_data[start_row + 6];
      workspace[47] = (float)(v32 - 128);
      v34 = v33[start_col];
      v35 = &v33[start_col];
      workspace[48] = (float)(v34 - 128);
      workspace[49] = (float)(v35[1] - 128);
      workspace[50] = (float)(v35[2] - 128);
      workspace[51] = (float)(v35[3] - 128);
      workspace[52] = (float)(v35[4] - 128);
      workspace[53] = (float)(v35[5] - 128);
      workspace[54] = (float)(v35[6] - 128);
      v36 = v35[7];
      v37 = sample_data[start_row + 7];
      workspace[55] = (float)(v36 - 128);
      v38 = v37[start_col];
      v39 = &v37[start_col];
      workspace[56] = (float)(v38 - 128);
      workspace[57] = (float)(v39[1] - 128);
      workspace[58] = (float)(v39[2] - 128);
      workspace[59] = (float)(v39[3] - 128);
      workspace[60] = (float)(v39[4] - 128);
      workspace[61] = (float)(v39[5] - 128);
      workspace[62] = (float)(v39[6] - 128);
      workspace[63] = (float)(v39[7] - 128);
      do_dct(a1: workspace);
      for ( i = 0; i < 64; ++i )
        (*coef_blocks)[i] = (int)(float)((float)(divisors[i] * workspace[i]) + 16384.5) - 0x4000;
      ++coef_blocks;
      start_col += 8;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420DC0
// Name: _jinit_forward_dct
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_forward_dct(jpeg_common_struct *cinfo)
{
  jpeg_forward_dct *v1; // esi
  J_DCT_METHOD v2; // eax
  __int32 v3; // eax

  v1 = (jpeg_forward_dct *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 48);
  cinfo[14].progress = (jpeg_progress_mgr *)v1;
  v1->start_pass = start_pass_fdctmgr;
  v2 = *(_DWORD *)&cinfo[7].is_decompressor;
  if ( v2 == JDCT_ISLOW )
  {
    v1[1].start_pass = (void (__cdecl *)(jpeg_compress_struct *))jpeg_fdct_islow;
    goto LABEL_8;
  }
  v3 = v2 - 1;
  if ( v3 == 0 )
  {
    v1[1].start_pass = (void (__cdecl *)(jpeg_compress_struct *))jpeg_fdct_ifast;
LABEL_8:
    v1->forward_DCT = (void (__cdecl *)(jpeg_compress_struct *, jpeg_component_info *, unsigned __int8 **, __int16 (*)[64], unsigned int, unsigned int, unsigned int))forward_DCT;
    goto LABEL_9;
  }
  if ( v3 == 1 )
  {
    v1->forward_DCT = (void (__cdecl *)(jpeg_compress_struct *, jpeg_component_info *, unsigned __int8 **, __int16 (*)[64], unsigned int, unsigned int, unsigned int))forward_DCT_float;
    v1[3].forward_DCT = (void (__cdecl *)(jpeg_compress_struct *, jpeg_component_info *, unsigned __int8 **, __int16 (*)[64], unsigned int, unsigned int, unsigned int))jpeg_fdct_float;
  }
  else
  {
    cinfo->err->msg_code = 48;
    cinfo->err->error_exit(a1: cinfo);
  }
LABEL_9:
  v1[1].forward_DCT = nullptr;
  v1[4].start_pass = nullptr;
  v1[2].start_pass = nullptr;
  v1[4].forward_DCT = nullptr;
  v1[2].forward_DCT = nullptr;
  v1[5].start_pass = nullptr;
  v1[3].start_pass = nullptr;
  v1[5].forward_DCT = nullptr;
}

} // namespace vxconsole_ps3
