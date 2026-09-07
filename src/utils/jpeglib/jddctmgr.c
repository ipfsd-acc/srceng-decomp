// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jddctmgr.c
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1000FBC0
// Name: start_pass
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass(jpeg_decompress_struct *cinfo)
{
  jpeg_decompress_struct *v1; // ebx
  jpeg_inverse_dct *idct; // eax
  jpeg_component_info *comp_info; // ecx
  int *p_DCT_scaled_size; // edi
  jpeg_inverse_dct *v5; // esi
  J_DCT_METHOD dct_method; // eax
  __int32 v7; // eax
  int v8; // esi
  double *v9; // eax
  float *v10; // edx
  unsigned __int16 *v11; // ecx
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  int *v19; // ecx
  unsigned __int16 *v20; // eax
  __int16 *v21; // edx
  int v22; // esi
  int v23; // ecx
  int i; // eax
  int *v25; // [esp+4h] [ebp-14h]
  int ci; // [esp+8h] [ebp-10h]
  _DWORD *p_start_pass; // [esp+Ch] [ebp-Ch]
  void (__cdecl *method_ptr)(jpeg_decompress_struct *, jpeg_component_info *, __int16 *, unsigned __int8 **, unsigned int); // [esp+10h] [ebp-8h]
  int method; // [esp+14h] [ebp-4h]

  v1 = cinfo;
  idct = cinfo->idct;
  comp_info = cinfo->comp_info;
  method = 0;
  method_ptr = nullptr;
  ci = 0;
  if ( cinfo->num_components > 0 )
  {
    p_DCT_scaled_size = &comp_info->DCT_scaled_size;
    v5 = idct + 1;
    v25 = &comp_info->DCT_scaled_size;
    p_start_pass = &idct[1].start_pass;
    do
    {
      switch ( *p_DCT_scaled_size )
      {
        case 1:
          method_ptr = jpeg_idct_1x1;
          method = 0;
          break;
        case 2:
          method_ptr = jpeg_idct_2x2;
          method = 0;
          break;
        case 4:
          method_ptr = jpeg_idct_4x4;
          method = 0;
          break;
        case 8:
          dct_method = v1->dct_method;
          if ( dct_method != JDCT_ISLOW )
          {
            v7 = dct_method - 1;
            if ( v7 != 0 )
            {
              if ( v7 == 1 )
              {
                method_ptr = jpeg_idct_float;
                method = 2;
              }
              else
              {
                v1->err->msg_code = 48;
                v1->err->error_exit(a1: (jpeg_common_struct *)v1);
              }
            }
            else
            {
              method_ptr = jpeg_idct_ifast;
              method = 1;
            }
          }
          else
          {
            method_ptr = jpeg_idct_islow;
            method = 0;
          }
          break;
        default:
          v1->err->msg_code = 7;
          v1->err->msg_parm.i[0] = *p_DCT_scaled_size;
          v1->err->error_exit(a1: (jpeg_common_struct *)v1);
          break;
      }
      v5[-1].inverse_DCT[0] = method_ptr;
      if ( *((_BYTE *)p_DCT_scaled_size + 12) != 0
        && v5->start_pass != (void (__cdecl *)(jpeg_decompress_struct *))method )
      {
        v8 = p_DCT_scaled_size[10];
        if ( v8 != 0 )
        {
          *p_start_pass = method;
          if ( method != 0 )
          {
            if ( method == 1 )
            {
              v19 = (int *)(p_DCT_scaled_size[11] + 8);
              v20 = (unsigned __int16 *)(v8 + 4);
              v21 = &word_1012FC4A;
              v22 = -v8;
              do
              {
                *(v19 - 2) = (*(v20 - 2) * *(v21 - 1) + 2048) >> 12;
                *(v19 - 1) = (*v21 * *(v20 - 1) + 2048) >> 12;
                *v19 = (*v20 * *(__int16 *)((char *)aanscales + (_DWORD)v20 + v22) + 2048) >> 12;
                v19[1] = (v20[1] * *(__int16 *)((char *)&word_1012FC4A + (_DWORD)v20 + v22) + 2048) >> 12;
                v21 += 4;
                v19 += 4;
                v20 += 4;
              }
              while ( (int)v21 < (int)word_1012FCCA );
              p_DCT_scaled_size = v25;
              v1 = cinfo;
            }
            else
            {
              v9 = (double *)aanscalefactor;
              v10 = (float *)(p_DCT_scaled_size[11] + 8);
              v11 = (unsigned __int16 *)(v8 + 4);
              do
              {
                v12 = (double)*(v11 - 2) * *v9;
                *(v10 - 2) = v12;
                v13 = (double)*(v11 - 1) * *v9 * 1.387039845;
                *(v10 - 1) = v13;
                v14 = (double)*v11 * *v9 * 1.306562965;
                *v10 = v14;
                v15 = (double)v11[1] * *v9 * 1.175875602;
                v10[1] = v15;
                v16 = (double)v11[2] * *v9;
                v10[2] = v16;
                v17 = (double)v11[3] * *v9 * 0.785694958;
                v10[3] = v17;
                v18 = (double)v11[4] * *v9 * 0.5411961;
                v10[4] = v18;
                v10[5] = (double)v11[5] * *v9++ * 0.275899379;
                v11 += 8;
                v10 += 8;
              }
              while ( (int)v9 < (int)base_dither_matrix[0] );
            }
          }
          else
          {
            v23 = p_DCT_scaled_size[11];
            for ( i = 0; i < 64; ++i )
              *(_DWORD *)(v23 + 4 * i) = *(unsigned __int16 *)(v8 + 2 * i);
          }
        }
      }
      v5 = (jpeg_inverse_dct *)(p_start_pass + 1);
      p_DCT_scaled_size += 21;
      ++ci;
      ++p_start_pass;
      v25 = p_DCT_scaled_size;
    }
    while ( ci < v1->num_components );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000FF00
// Name: _jinit_inverse_dct
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_inverse_dct(jpeg_common_struct *cinfo)
{
  jpeg_inverse_dct *v2; // eax
  int v3; // edi
  jpeg_inverse_dct *v4; // ebx
  int v5; // eax
  jpeg_decompress_struct *cinfoa; // [esp+10h] [ebp+8h]

  v2 = (jpeg_inverse_dct *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 84);
  cinfo[17].mem = (jpeg_memory_mgr *)v2;
  v2->start_pass = start_pass;
  v3 = 0;
  if ( (int)cinfo[1].client_data > 0 )
  {
    cinfoa = (jpeg_decompress_struct *)&cinfo[8].mem[1].access_virt_sarray;
    v4 = v2 + 1;
    do
    {
      v5 = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 256);
      cinfoa->err = (jpeg_error_mgr *)v5;
      memset(dst: v5, value: nullptr, count: 0x100u);
      cinfoa = (jpeg_decompress_struct *)((char *)cinfoa + 84);
      v4->start_pass = (void (__cdecl *)(jpeg_decompress_struct *))-1;
      ++v3;
      v4 = (jpeg_inverse_dct *)((char *)v4 + 4);
    }
    while ( v3 < (int)cinfo[1].client_data );
  }
}

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x10278930
// Name: start_pass
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass(jpeg_decompress_struct *cinfo)
{
  jpeg_decompress_struct *v1; // ebx
  jpeg_inverse_dct *idct; // eax
  jpeg_component_info *comp_info; // ecx
  int *p_DCT_scaled_size; // edi
  jpeg_inverse_dct *v5; // esi
  J_DCT_METHOD dct_method; // eax
  __int32 v7; // eax
  int v8; // esi
  double *v9; // eax
  float *v10; // edx
  unsigned __int16 *v11; // ecx
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm0_4
  int *v19; // ecx
  unsigned __int16 *v20; // eax
  __int16 *v21; // edx
  int v22; // esi
  int v23; // ecx
  int i; // eax
  int *v25; // [esp+4h] [ebp-14h]
  int ci; // [esp+8h] [ebp-10h]
  _DWORD *p_start_pass; // [esp+Ch] [ebp-Ch]
  void (__cdecl *method_ptr)(jpeg_decompress_struct *, jpeg_component_info *, __int16 *, unsigned __int8 **, unsigned int); // [esp+10h] [ebp-8h]
  int method; // [esp+14h] [ebp-4h]

  v1 = cinfo;
  idct = cinfo->idct;
  comp_info = cinfo->comp_info;
  method = 0;
  method_ptr = nullptr;
  ci = 0;
  if ( cinfo->num_components > 0 )
  {
    p_DCT_scaled_size = &comp_info->DCT_scaled_size;
    v5 = idct + 1;
    v25 = &comp_info->DCT_scaled_size;
    p_start_pass = &idct[1].start_pass;
    do
    {
      switch ( *p_DCT_scaled_size )
      {
        case 1:
          method_ptr = jpeg_idct_1x1;
          method = 0;
          break;
        case 2:
          method_ptr = jpeg_idct_2x2;
          method = 0;
          break;
        case 4:
          method_ptr = jpeg_idct_4x4;
          method = 0;
          break;
        case 8:
          dct_method = v1->dct_method;
          if ( dct_method != JDCT_ISLOW )
          {
            v7 = dct_method - 1;
            if ( v7 != 0 )
            {
              if ( v7 == 1 )
              {
                method_ptr = jpeg_idct_float;
                method = 2;
              }
              else
              {
                v1->err->msg_code = 48;
                v1->err->error_exit(a1: (jpeg_common_struct *)v1);
              }
            }
            else
            {
              method_ptr = jpeg_idct_ifast;
              method = 1;
            }
          }
          else
          {
            method_ptr = jpeg_idct_islow;
            method = 0;
          }
          break;
        default:
          v1->err->msg_code = 7;
          v1->err->msg_parm.i[0] = *p_DCT_scaled_size;
          v1->err->error_exit(a1: (jpeg_common_struct *)v1);
          break;
      }
      v5[-1].inverse_DCT[0] = method_ptr;
      if ( *((_BYTE *)p_DCT_scaled_size + 12) != 0
        && v5->start_pass != (void (__cdecl *)(jpeg_decompress_struct *))method )
      {
        v8 = p_DCT_scaled_size[10];
        if ( v8 != 0 )
        {
          *p_start_pass = method;
          if ( method != 0 )
          {
            if ( method == 1 )
            {
              v19 = (int *)(p_DCT_scaled_size[11] + 8);
              v20 = (unsigned __int16 *)(v8 + 4);
              v21 = &word_104EABFA;
              v22 = -v8;
              do
              {
                *(v19 - 2) = (*(v20 - 2) * *(v21 - 1) + 2048) >> 12;
                *(v19 - 1) = (*v21 * *(v20 - 1) + 2048) >> 12;
                *v19 = (*v20 * *(__int16 *)((char *)aanscales + (_DWORD)v20 + v22) + 2048) >> 12;
                v19[1] = (v20[1] * *(__int16 *)((char *)&word_104EABFA + (_DWORD)v20 + v22) + 2048) >> 12;
                v21 += 4;
                v19 += 4;
                v20 += 4;
              }
              while ( (int)v21 < (int)word_104EAC7A );
              p_DCT_scaled_size = v25;
              v1 = cinfo;
            }
            else
            {
              v9 = (double *)aanscalefactor;
              v10 = (float *)(p_DCT_scaled_size[11] + 8);
              v11 = (unsigned __int16 *)(v8 + 4);
              do
              {
                v12 = (double)*(v11 - 2) * *v9;
                *(v10 - 2) = v12;
                v13 = (double)*(v11 - 1) * *v9 * 1.387039845;
                *(v10 - 1) = v13;
                v14 = (double)*v11 * *v9 * 1.306562965;
                *v10 = v14;
                v15 = (double)v11[1] * *v9 * 1.175875602;
                v10[1] = v15;
                v16 = (double)v11[2] * *v9;
                v10[2] = v16;
                v17 = (double)v11[3] * *v9 * 0.785694958;
                v10[3] = v17;
                v18 = (double)v11[4] * *v9 * 0.5411961;
                v10[4] = v18;
                v10[5] = (double)v11[5] * *v9++ * 0.275899379;
                v11 += 8;
                v10 += 8;
              }
              while ( (int)v9 < (int)base_dither_matrix[0] );
            }
          }
          else
          {
            v23 = p_DCT_scaled_size[11];
            for ( i = 0; i < 64; ++i )
              *(_DWORD *)(v23 + 4 * i) = *(unsigned __int16 *)(v8 + 2 * i);
          }
        }
      }
      v5 = (jpeg_inverse_dct *)(p_start_pass + 1);
      p_DCT_scaled_size += 21;
      ++ci;
      ++p_start_pass;
      v25 = p_DCT_scaled_size;
    }
    while ( ci < v1->num_components );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10278C70
// Name: _jinit_inverse_dct
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_inverse_dct(jpeg_common_struct *cinfo)
{
  jpeg_inverse_dct *v2; // eax
  int v3; // edi
  jpeg_inverse_dct *v4; // ebx
  int v5; // eax
  jpeg_decompress_struct *cinfoa; // [esp+10h] [ebp+8h]

  v2 = (jpeg_inverse_dct *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 84);
  cinfo[17].mem = (jpeg_memory_mgr *)v2;
  v2->start_pass = start_pass;
  v3 = 0;
  if ( (int)cinfo[1].client_data > 0 )
  {
    cinfoa = (jpeg_decompress_struct *)&cinfo[8].mem[1].access_virt_sarray;
    v4 = v2 + 1;
    do
    {
      v5 = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 256);
      cinfoa->err = (jpeg_error_mgr *)v5;
      memset(dst: v5, value: nullptr, count: 0x100u);
      cinfoa = (jpeg_decompress_struct *)((char *)cinfoa + 84);
      v4->start_pass = (void (__cdecl *)(jpeg_decompress_struct *))-1;
      ++v3;
      v4 = (jpeg_inverse_dct *)((char *)v4 + 4);
    }
    while ( v3 < (int)cinfo[1].client_data );
  }
}

} // namespace client
