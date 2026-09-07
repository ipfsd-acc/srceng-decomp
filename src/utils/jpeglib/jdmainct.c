// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jdmainct.c
// Functions: 9
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1000CFC0
// Name: alloc_funny_pointers
// Source: json
//------------------------------------------------------------------------------
void __usercall alloc_funny_pointers(jpeg_common_struct *cinfo@<esi>)
{
  jpeg_d_main_controller *mem; // ebx
  int v2; // edi
  int v3; // eax
  jpeg_component_info *v4; // eax
  int v5; // ebx
  int *p_v_samp_factor; // ecx
  int v7; // edi
  int v8; // eax
  my_main_controller *main; // [esp+8h] [ebp-10h]
  int rgroup; // [esp+Ch] [ebp-Ch]
  int v11; // [esp+10h] [ebp-8h]
  int *i; // [esp+14h] [ebp-4h]

  mem = (jpeg_d_main_controller *)cinfo[16].mem;
  v2 = *(_DWORD *)&cinfo[11].is_decompressor;
  main = (my_main_controller *)mem;
  v3 = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 8 * (int)cinfo[1].client_data);
  mem[7].start_pass = (void (__cdecl *)(jpeg_decompress_struct *, J_BUF_MODE))v3;
  mem[7].process_data = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 **, unsigned int *, unsigned int))(v3 + 4 * (int)cinfo[1].client_data);
  v4 = (jpeg_component_info *)cinfo[8].mem;
  v5 = 0;
  if ( (int)cinfo[1].client_data > 0 )
  {
    p_v_samp_factor = &v4->v_samp_factor;
    v11 = v2 + 4;
    for ( i = &v4->v_samp_factor; ; p_v_samp_factor = i )
    {
      v7 = *p_v_samp_factor * p_v_samp_factor[6] / *(_DWORD *)&cinfo[11].is_decompressor * v11;
      rgroup = *p_v_samp_factor * p_v_samp_factor[6] / *(_DWORD *)&cinfo[11].is_decompressor;
      i += 21;
      v8 = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 8 * v7) + 4 * rgroup;
      main->xbuffer[0][v5] = (unsigned __int8 **)v8;
      main->xbuffer[1][v5++] = (unsigned __int8 **)(v8 + 4 * v7);
      if ( v5 >= (int)cinfo[1].client_data )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D070
// Name: make_funny_pointers
// Source: json
//------------------------------------------------------------------------------
void __cdecl make_funny_pointers(jpeg_decompress_struct *cinfo)
{
  jpeg_decompress_struct *v1; // esi
  int v2; // ecx
  jpeg_d_main_controller *p_pub; // edi
  jpeg_component_info *comp_info; // eax
  int *p_v_samp_factor; // edx
  int v6; // ebx
  int v7; // edx
  int v8; // eax
  _DWORD *v9; // ecx
  int v10; // edi
  _DWORD *v11; // esi
  int v12; // edi
  _DWORD *v13; // ecx
  int v14; // edx
  unsigned __int8 **v15; // eax
  unsigned __int8 **xbuf0; // [esp+10h] [ebp-18h]
  my_main_controller *main; // [esp+14h] [ebp-14h]
  int M; // [esp+18h] [ebp-10h]
  int v19; // [esp+1Ch] [ebp-Ch]
  int v20; // [esp+1Ch] [ebp-Ch]
  int *v21; // [esp+20h] [ebp-8h]
  int ci; // [esp+24h] [ebp-4h]

  v1 = cinfo;
  v2 = 0;
  p_pub = cinfo->main;
  M = cinfo->min_DCT_scaled_size;
  comp_info = cinfo->comp_info;
  main = (my_main_controller *)p_pub;
  ci = 0;
  if ( cinfo->num_components > 0 )
  {
    p_v_samp_factor = &comp_info->v_samp_factor;
    v21 = &comp_info->v_samp_factor;
    while ( 1 )
    {
      v6 = *p_v_samp_factor * p_v_samp_factor[6] / v1->min_DCT_scaled_size;
      v7 = *((_DWORD *)p_pub[7].process_data + v2);
      xbuf0 = *((unsigned __int8 ***)p_pub[7].start_pass + v2);
      v8 = *((_DWORD *)&p_pub[1].start_pass + v2);
      if ( v6 * (M + 2) > 0 )
      {
        v9 = *((_DWORD **)p_pub[7].process_data + v2);
        v19 = v6 * (M + 2);
        do
        {
          v10 = *(_DWORD *)((char *)v9 + v8 - v7);
          *v9 = v10;
          *(_DWORD *)((char *)v9++ + (_DWORD)xbuf0 - v7) = v10;
          --v19;
        }
        while ( v19 != 0 );
        v2 = ci;
        p_pub = &main->pub;
      }
      if ( 2 * v6 > 0 )
      {
        v11 = (_DWORD *)(v7 + 4 * M * v6);
        v12 = v8 - v7;
        v13 = (_DWORD *)(v8 + 4 * v6 * (M - 2));
        v14 = v7 - v8;
        v20 = 2 * v6;
        do
        {
          *(_DWORD *)((char *)v13 + v14) = *(_DWORD *)((char *)v11 + v12);
          *v11++ = *v13++;
          --v20;
        }
        while ( v20 != 0 );
        v2 = ci;
        p_pub = &main->pub;
      }
      if ( v6 > 0 )
      {
        v15 = &xbuf0[-v6];
        do
        {
          *v15++ = *xbuf0;
          --v6;
        }
        while ( v6 != 0 );
      }
      v21 += 21;
      ci = ++v2;
      if ( v2 >= cinfo->num_components )
        break;
      p_v_samp_factor = v21;
      v1 = cinfo;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D1A0
// Name: set_wraparound_pointers
// Source: json
//------------------------------------------------------------------------------
void __cdecl set_wraparound_pointers(jpeg_decompress_struct *cinfo)
{
  jpeg_decompress_struct *v1; // ebx
  int v2; // esi
  jpeg_d_main_controller *p_pub; // edi
  int *p_v_samp_factor; // ecx
  int v5; // eax
  char *v6; // edi
  char *v7; // ebx
  char *v8; // edx
  char *v9; // esi
  int v10; // ecx
  unsigned __int8 **xbuf0; // [esp+Ch] [ebp-18h]
  int M; // [esp+10h] [ebp-14h]
  my_main_controller *main; // [esp+14h] [ebp-10h]
  int *v14; // [esp+18h] [ebp-Ch]
  int ci; // [esp+1Ch] [ebp-8h]
  int rgroup; // [esp+20h] [ebp-4h]

  v1 = cinfo;
  v2 = 0;
  p_pub = cinfo->main;
  main = (my_main_controller *)p_pub;
  M = cinfo->min_DCT_scaled_size;
  ci = 0;
  if ( cinfo->num_components > 0 )
  {
    p_v_samp_factor = &cinfo->comp_info->v_samp_factor;
    v14 = p_v_samp_factor;
    while ( 1 )
    {
      v5 = *p_v_samp_factor * p_v_samp_factor[6] / v1->min_DCT_scaled_size;
      xbuf0 = *((unsigned __int8 ***)p_pub[7].start_pass + v2);
      v6 = *((char **)p_pub[7].process_data + v2);
      rgroup = v5;
      if ( v5 > 0 )
      {
        v7 = &v6[4 * v5 * (M + 2)];
        v8 = &v6[-4 * v5];
        v9 = &v6[4 * v5 * (M + 1)];
        v10 = (char *)xbuf0 - v6;
        do
        {
          *(_DWORD *)&v8[v10] = *(_DWORD *)&v9[v10];
          *(_DWORD *)v8 = *(_DWORD *)v9;
          *(_DWORD *)&v7[v10] = *(_DWORD *)&v6[v10];
          *(_DWORD *)v7 = *(_DWORD *)v6;
          v9 += 4;
          v8 += 4;
          v6 += 4;
          v7 += 4;
          --rgroup;
        }
        while ( rgroup != 0 );
        v2 = ci;
        v1 = cinfo;
        p_v_samp_factor = v14;
      }
      ++v2;
      p_v_samp_factor += 21;
      ci = v2;
      v14 = p_v_samp_factor;
      if ( v2 >= v1->num_components )
        break;
      p_pub = &main->pub;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D280
// Name: set_bottom_pointers
// Source: json
//------------------------------------------------------------------------------
void __cdecl set_bottom_pointers(jpeg_decompress_struct *cinfo)
{
  jpeg_decompress_struct *v1; // esi
  int *p_v_samp_factor; // ebx
  int v3; // edi
  unsigned int v4; // esi
  int v5; // ecx
  int v6; // edx
  int v7; // ecx
  _DWORD *v8; // eax
  my_main_controller *main; // [esp+8h] [ebp-8h]
  int ci; // [esp+Ch] [ebp-4h]

  v1 = cinfo;
  main = (my_main_controller *)cinfo->main;
  ci = 0;
  if ( cinfo->num_components > 0 )
  {
    p_v_samp_factor = &cinfo->comp_info->v_samp_factor;
    while ( 1 )
    {
      v3 = *p_v_samp_factor * p_v_samp_factor[6] / v1->min_DCT_scaled_size;
      v4 = p_v_samp_factor[8] % (unsigned int)(*p_v_samp_factor * p_v_samp_factor[6]);
      if ( v4 == 0 )
        v4 = *p_v_samp_factor * p_v_samp_factor[6];
      v5 = ci;
      if ( ci == 0 )
        main->rowgroups_avail = (int)(v4 - 1) / v3 + 1;
      v6 = 2 * v3;
      if ( 2 * v3 > 0 )
      {
        v7 = (int)&main->xbuffer[main->whichptr][ci][v4];
        v8 = (_DWORD *)v7;
        do
        {
          *v8++ = *(_DWORD *)(v7 - 4);
          --v6;
        }
        while ( v6 != 0 );
        v5 = ci;
      }
      p_v_samp_factor += 21;
      ci = v5 + 1;
      if ( v5 + 1 >= cinfo->num_components )
        break;
      v1 = cinfo;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D330
// Name: process_data_simple_main
// Source: json
//------------------------------------------------------------------------------
void __cdecl process_data_simple_main(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 **output_buf,
        unsigned int *out_row_ctr,
        unsigned int out_rows_avail)
{
  jpeg_d_main_controller *main; // esi
  unsigned int rowgroups_avail; // [esp+10h] [ebp+8h]

  main = cinfo->main;
  if ( LOBYTE(main[6].start_pass) == 0 )
  {
    if ( cinfo->coef->decompress_data(a1: cinfo, a2: (unsigned __int8 ***)&main[1]) == 0 )
      return;
    LOBYTE(main[6].start_pass) = 1;
  }
  rowgroups_avail = cinfo->min_DCT_scaled_size;
  cinfo->post->post_process_data(
    a1: cinfo,
    a2: (unsigned __int8 ***)&main[1],
    a3: (unsigned int *)&main[6].process_data,
    a4: cinfo->min_DCT_scaled_size,
    a5: output_buf,
    a6: out_row_ctr,
    a7: out_rows_avail);
  if ( (char *)main[6].process_data >= (char *)rowgroups_avail )
  {
    LOBYTE(main[6].start_pass) = 0;
    main[6].process_data = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D3B0
// Name: process_data_context_main
// Source: json
//------------------------------------------------------------------------------
void __cdecl process_data_context_main(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 **output_buf,
        unsigned int *out_row_ctr,
        unsigned int out_rows_avail)
{
  jpeg_d_main_controller *main; // esi
  void (__cdecl *process_data)(jpeg_decompress_struct *, unsigned __int8 **, unsigned int *, unsigned int); // eax
  char *v6; // eax
  void (__cdecl *v7)(jpeg_decompress_struct *, unsigned __int8 **, unsigned int *, unsigned int); // eax

  main = cinfo->main;
  if ( LOBYTE(main[6].start_pass) == 0 )
  {
    if ( cinfo->coef->decompress_data(
           a1: cinfo,
           a2: *((unsigned __int8 ****)&main[7].start_pass + (int)main[8].start_pass)) == 0 )
      return;
    ++main[9].process_data;
    LOBYTE(main[6].start_pass) = 1;
  }
  process_data = main[8].process_data;
  if ( process_data == nullptr )
  {
LABEL_9:
    v7 = main[9].process_data;
    main[6].process_data = nullptr;
    main[9].start_pass = (void (__cdecl *)(jpeg_decompress_struct *, J_BUF_MODE))(cinfo->min_DCT_scaled_size - 1);
    if ( v7 == (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 **, unsigned int *, unsigned int))cinfo->total_iMCU_rows )
      set_bottom_pointers(cinfo);
    main[8].process_data = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 **, unsigned int *, unsigned int))1;
    goto LABEL_12;
  }
  v6 = (char *)process_data - 1;
  if ( v6 != nullptr )
  {
    if ( v6 != (char *)1 )
      return;
    cinfo->post->post_process_data(
      a1: cinfo,
      a2: *((unsigned __int8 ****)&main[7].start_pass + (int)main[8].start_pass),
      a3: (unsigned int *)&main[6].process_data,
      a4: (unsigned int)main[9].start_pass,
      a5: output_buf,
      a6: out_row_ctr,
      a7: out_rows_avail);
    if ( (char *)main[6].process_data < (char *)main[9].start_pass )
      return;
    main[8].process_data = nullptr;
    if ( *out_row_ctr >= out_rows_avail )
      return;
    goto LABEL_9;
  }
LABEL_12:
  cinfo->post->post_process_data(
    a1: cinfo,
    a2: *((unsigned __int8 ****)&main[7].start_pass + (int)main[8].start_pass),
    a3: (unsigned int *)&main[6].process_data,
    a4: (unsigned int)main[9].start_pass,
    a5: output_buf,
    a6: out_row_ctr,
    a7: out_rows_avail);
  if ( (char *)main[6].process_data >= (char *)main[9].start_pass )
  {
    if ( main[9].process_data == (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 **, unsigned int *, unsigned int))1 )
      set_wraparound_pointers(cinfo);
    main[8].start_pass = (void (__cdecl *)(jpeg_decompress_struct *, J_BUF_MODE))((int)main[8].start_pass ^ 1);
    LOBYTE(main[6].start_pass) = 0;
    main[6].process_data = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 **, unsigned int *, unsigned int))(cinfo->min_DCT_scaled_size + 1);
    main[9].start_pass = (void (__cdecl *)(jpeg_decompress_struct *, J_BUF_MODE))(cinfo->min_DCT_scaled_size + 2);
    main[8].process_data = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 **, unsigned int *, unsigned int))2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D4E0
// Name: process_data_crank_post
// Source: json
//------------------------------------------------------------------------------
void __cdecl process_data_crank_post(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 **output_buf,
        unsigned int *out_row_ctr,
        unsigned int out_rows_avail)
{
  cinfo->post->post_process_data(
    a1: cinfo,
    a2: nullptr,
    a3: nullptr,
    a4: 0,
    a5: output_buf,
    a6: out_row_ctr,
    a7: out_rows_avail);
}

//------------------------------------------------------------------------------
// Address: 0x1000D510
// Name: start_pass_main
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_main(jpeg_common_struct *cinfo, J_BUF_MODE pass_mode)
{
  jpeg_d_main_controller *mem; // esi

  mem = (jpeg_d_main_controller *)cinfo[16].mem;
  if ( pass_mode != JBUF_PASS_THRU )
  {
    if ( pass_mode == JBUF_CRANK_DEST )
    {
      mem->process_data = process_data_crank_post;
    }
    else
    {
      cinfo->err->msg_code = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
  }
  else if ( LOBYTE(cinfo[17].progress->pass_limit) != 0 )
  {
    mem->process_data = process_data_context_main;
    make_funny_pointers((jpeg_decompress_struct *)cinfo);
    mem[8].start_pass = nullptr;
    mem[8].process_data = nullptr;
    mem[9].process_data = nullptr;
    LOBYTE(mem[6].start_pass) = 0;
    mem[6].process_data = nullptr;
  }
  else
  {
    LOBYTE(mem[6].start_pass) = 0;
    mem[6].process_data = nullptr;
    mem->process_data = process_data_simple_main;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D590
// Name: _jinit_d_main_controller
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_d_main_controller(jpeg_common_struct *cinfo, unsigned __int8 need_full_buffer)
{
  jpeg_d_main_controller *v3; // ebx
  int v4; // eax
  int *p_free_pool; // edi
  jpeg_d_main_controller *v6; // ebx
  int ci; // [esp+10h] [ebp+8h]
  int ngroups; // [esp+14h] [ebp+Ch]

  v3 = (jpeg_d_main_controller *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 80);
  cinfo[16].mem = (jpeg_memory_mgr *)v3;
  v3->start_pass = (void (__cdecl *)(jpeg_decompress_struct *, J_BUF_MODE))start_pass_main;
  if ( need_full_buffer != 0 )
  {
    cinfo->err->msg_code = 4;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( LOBYTE(cinfo[17].progress->pass_limit) != 0 )
  {
    if ( *(int *)&cinfo[11].is_decompressor < 2 )
    {
      cinfo->err->msg_code = 47;
      cinfo->err->error_exit(a1: cinfo);
    }
    alloc_funny_pointers(cinfo);
    v4 = *(_DWORD *)&cinfo[11].is_decompressor + 2;
  }
  else
  {
    v4 = *(_DWORD *)&cinfo[11].is_decompressor;
  }
  ngroups = v4;
  ci = 0;
  if ( (int)cinfo[1].client_data > 0 )
  {
    p_free_pool = (int *)&cinfo[8].mem->free_pool;
    v6 = v3 + 1;
    do
    {
      v6->start_pass = (void (__cdecl *)(jpeg_decompress_struct *, J_BUF_MODE))cinfo->mem->alloc_sarray(
                                                                                 a1: cinfo,
                                                                                 a2: 1,
                                                                                 a3: *p_free_pool * *(p_free_pool - 2),
                                                                                 a4: ngroups
                                                                               * (*p_free_pool
                                                                                * *(p_free_pool - 6)
                                                                                / *(_DWORD *)&cinfo[11].is_decompressor));
      v6 = (jpeg_d_main_controller *)((char *)v6 + 4);
      p_free_pool += 21;
      ++ci;
    }
    while ( ci < (int)cinfo[1].client_data );
  }
}

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x10275D40
// Name: alloc_funny_pointers
// Source: json
//------------------------------------------------------------------------------
void __usercall alloc_funny_pointers(jpeg_common_struct *cinfo@<esi>)
{
  jpeg_d_main_controller *mem; // ebx
  int v2; // edi
  int v3; // eax
  jpeg_component_info *v4; // eax
  int v5; // ebx
  int *p_v_samp_factor; // ecx
  int v7; // edi
  int v8; // eax
  my_main_controller *main; // [esp+8h] [ebp-10h]
  int rgroup; // [esp+Ch] [ebp-Ch]
  int v11; // [esp+10h] [ebp-8h]
  int *i; // [esp+14h] [ebp-4h]

  mem = (jpeg_d_main_controller *)cinfo[16].mem;
  v2 = *(_DWORD *)&cinfo[11].is_decompressor;
  main = (my_main_controller *)mem;
  v3 = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 8 * (int)cinfo[1].client_data);
  mem[7].start_pass = (void (__cdecl *)(jpeg_decompress_struct *, J_BUF_MODE))v3;
  mem[7].process_data = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 **, unsigned int *, unsigned int))(v3 + 4 * (int)cinfo[1].client_data);
  v4 = (jpeg_component_info *)cinfo[8].mem;
  v5 = 0;
  if ( (int)cinfo[1].client_data > 0 )
  {
    p_v_samp_factor = &v4->v_samp_factor;
    v11 = v2 + 4;
    for ( i = &v4->v_samp_factor; ; p_v_samp_factor = i )
    {
      v7 = *p_v_samp_factor * p_v_samp_factor[6] / *(_DWORD *)&cinfo[11].is_decompressor * v11;
      rgroup = *p_v_samp_factor * p_v_samp_factor[6] / *(_DWORD *)&cinfo[11].is_decompressor;
      i += 21;
      v8 = cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 8 * v7) + 4 * rgroup;
      main->xbuffer[0][v5] = (unsigned __int8 **)v8;
      main->xbuffer[1][v5++] = (unsigned __int8 **)(v8 + 4 * v7);
      if ( v5 >= (int)cinfo[1].client_data )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10275DF0
// Name: make_funny_pointers
// Source: json
//------------------------------------------------------------------------------
void __cdecl make_funny_pointers(jpeg_decompress_struct *cinfo)
{
  jpeg_decompress_struct *v1; // esi
  int v2; // ecx
  jpeg_d_main_controller *p_pub; // edi
  jpeg_component_info *comp_info; // eax
  int *p_v_samp_factor; // edx
  int v6; // ebx
  int v7; // edx
  int v8; // eax
  _DWORD *v9; // ecx
  int v10; // edi
  _DWORD *v11; // esi
  int v12; // edi
  _DWORD *v13; // ecx
  int v14; // edx
  unsigned __int8 **v15; // eax
  unsigned __int8 **xbuf0; // [esp+10h] [ebp-18h]
  my_main_controller *main; // [esp+14h] [ebp-14h]
  int M; // [esp+18h] [ebp-10h]
  int v19; // [esp+1Ch] [ebp-Ch]
  int v20; // [esp+1Ch] [ebp-Ch]
  int *v21; // [esp+20h] [ebp-8h]
  int ci; // [esp+24h] [ebp-4h]

  v1 = cinfo;
  v2 = 0;
  p_pub = cinfo->main;
  M = cinfo->min_DCT_scaled_size;
  comp_info = cinfo->comp_info;
  main = (my_main_controller *)p_pub;
  ci = 0;
  if ( cinfo->num_components > 0 )
  {
    p_v_samp_factor = &comp_info->v_samp_factor;
    v21 = &comp_info->v_samp_factor;
    while ( 1 )
    {
      v6 = *p_v_samp_factor * p_v_samp_factor[6] / v1->min_DCT_scaled_size;
      v7 = *((_DWORD *)p_pub[7].process_data + v2);
      xbuf0 = *((unsigned __int8 ***)p_pub[7].start_pass + v2);
      v8 = *((_DWORD *)&p_pub[1].start_pass + v2);
      if ( v6 * (M + 2) > 0 )
      {
        v9 = *((_DWORD **)p_pub[7].process_data + v2);
        v19 = v6 * (M + 2);
        do
        {
          v10 = *(_DWORD *)((char *)v9 + v8 - v7);
          *v9 = v10;
          *(_DWORD *)((char *)v9++ + (_DWORD)xbuf0 - v7) = v10;
          --v19;
        }
        while ( v19 != 0 );
        v2 = ci;
        p_pub = &main->pub;
      }
      if ( 2 * v6 > 0 )
      {
        v11 = (_DWORD *)(v7 + 4 * M * v6);
        v12 = v8 - v7;
        v13 = (_DWORD *)(v8 + 4 * v6 * (M - 2));
        v14 = v7 - v8;
        v20 = 2 * v6;
        do
        {
          *(_DWORD *)((char *)v13 + v14) = *(_DWORD *)((char *)v11 + v12);
          *v11++ = *v13++;
          --v20;
        }
        while ( v20 != 0 );
        v2 = ci;
        p_pub = &main->pub;
      }
      if ( v6 > 0 )
      {
        v15 = &xbuf0[-v6];
        do
        {
          *v15++ = *xbuf0;
          --v6;
        }
        while ( v6 != 0 );
      }
      v21 += 21;
      ci = ++v2;
      if ( v2 >= cinfo->num_components )
        break;
      p_v_samp_factor = v21;
      v1 = cinfo;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10275F20
// Name: set_wraparound_pointers
// Source: json
//------------------------------------------------------------------------------
void __cdecl set_wraparound_pointers(jpeg_decompress_struct *cinfo)
{
  jpeg_decompress_struct *v1; // ebx
  int v2; // esi
  jpeg_d_main_controller *p_pub; // edi
  int *p_v_samp_factor; // ecx
  int v5; // eax
  char *v6; // edi
  char *v7; // ebx
  char *v8; // edx
  char *v9; // esi
  int v10; // ecx
  unsigned __int8 **xbuf0; // [esp+Ch] [ebp-18h]
  int M; // [esp+10h] [ebp-14h]
  my_main_controller *main; // [esp+14h] [ebp-10h]
  int *v14; // [esp+18h] [ebp-Ch]
  int ci; // [esp+1Ch] [ebp-8h]
  int rgroup; // [esp+20h] [ebp-4h]

  v1 = cinfo;
  v2 = 0;
  p_pub = cinfo->main;
  main = (my_main_controller *)p_pub;
  M = cinfo->min_DCT_scaled_size;
  ci = 0;
  if ( cinfo->num_components > 0 )
  {
    p_v_samp_factor = &cinfo->comp_info->v_samp_factor;
    v14 = p_v_samp_factor;
    while ( 1 )
    {
      v5 = *p_v_samp_factor * p_v_samp_factor[6] / v1->min_DCT_scaled_size;
      xbuf0 = *((unsigned __int8 ***)p_pub[7].start_pass + v2);
      v6 = *((char **)p_pub[7].process_data + v2);
      rgroup = v5;
      if ( v5 > 0 )
      {
        v7 = &v6[4 * v5 * (M + 2)];
        v8 = &v6[-4 * v5];
        v9 = &v6[4 * v5 * (M + 1)];
        v10 = (char *)xbuf0 - v6;
        do
        {
          *(_DWORD *)&v8[v10] = *(_DWORD *)&v9[v10];
          *(_DWORD *)v8 = *(_DWORD *)v9;
          *(_DWORD *)&v7[v10] = *(_DWORD *)&v6[v10];
          *(_DWORD *)v7 = *(_DWORD *)v6;
          v9 += 4;
          v8 += 4;
          v6 += 4;
          v7 += 4;
          --rgroup;
        }
        while ( rgroup != 0 );
        v2 = ci;
        v1 = cinfo;
        p_v_samp_factor = v14;
      }
      ++v2;
      p_v_samp_factor += 21;
      ci = v2;
      v14 = p_v_samp_factor;
      if ( v2 >= v1->num_components )
        break;
      p_pub = &main->pub;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10276000
// Name: set_bottom_pointers
// Source: json
//------------------------------------------------------------------------------
void __cdecl set_bottom_pointers(jpeg_decompress_struct *cinfo)
{
  jpeg_decompress_struct *v1; // esi
  int *p_v_samp_factor; // ebx
  int v3; // edi
  unsigned int v4; // esi
  int v5; // ecx
  int v6; // edx
  int v7; // ecx
  _DWORD *v8; // eax
  my_main_controller *main; // [esp+8h] [ebp-8h]
  int ci; // [esp+Ch] [ebp-4h]

  v1 = cinfo;
  main = (my_main_controller *)cinfo->main;
  ci = 0;
  if ( cinfo->num_components > 0 )
  {
    p_v_samp_factor = &cinfo->comp_info->v_samp_factor;
    while ( 1 )
    {
      v3 = *p_v_samp_factor * p_v_samp_factor[6] / v1->min_DCT_scaled_size;
      v4 = p_v_samp_factor[8] % (unsigned int)(*p_v_samp_factor * p_v_samp_factor[6]);
      if ( v4 == 0 )
        v4 = *p_v_samp_factor * p_v_samp_factor[6];
      v5 = ci;
      if ( ci == 0 )
        main->rowgroups_avail = (int)(v4 - 1) / v3 + 1;
      v6 = 2 * v3;
      if ( 2 * v3 > 0 )
      {
        v7 = (int)&main->xbuffer[main->whichptr][ci][v4];
        v8 = (_DWORD *)v7;
        do
        {
          *v8++ = *(_DWORD *)(v7 - 4);
          --v6;
        }
        while ( v6 != 0 );
        v5 = ci;
      }
      p_v_samp_factor += 21;
      ci = v5 + 1;
      if ( v5 + 1 >= cinfo->num_components )
        break;
      v1 = cinfo;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102760B0
// Name: process_data_simple_main
// Source: json
//------------------------------------------------------------------------------
void __cdecl process_data_simple_main(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 **output_buf,
        unsigned int *out_row_ctr,
        unsigned int out_rows_avail)
{
  jpeg_d_main_controller *main; // esi
  unsigned int rowgroups_avail; // [esp+10h] [ebp+8h]

  main = cinfo->main;
  if ( LOBYTE(main[6].start_pass) == 0 )
  {
    if ( cinfo->coef->decompress_data(a1: cinfo, a2: (unsigned __int8 ***)&main[1]) == 0 )
      return;
    LOBYTE(main[6].start_pass) = 1;
  }
  rowgroups_avail = cinfo->min_DCT_scaled_size;
  cinfo->post->post_process_data(
    a1: cinfo,
    a2: (unsigned __int8 ***)&main[1],
    a3: (unsigned int *)&main[6].process_data,
    a4: cinfo->min_DCT_scaled_size,
    a5: output_buf,
    a6: out_row_ctr,
    a7: out_rows_avail);
  if ( (char *)main[6].process_data >= (char *)rowgroups_avail )
  {
    LOBYTE(main[6].start_pass) = 0;
    main[6].process_data = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10276130
// Name: process_data_context_main
// Source: json
//------------------------------------------------------------------------------
void __cdecl process_data_context_main(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 **output_buf,
        unsigned int *out_row_ctr,
        unsigned int out_rows_avail)
{
  jpeg_d_main_controller *main; // esi
  void (__cdecl *process_data)(jpeg_decompress_struct *, unsigned __int8 **, unsigned int *, unsigned int); // eax
  char *v6; // eax
  void (__cdecl *v7)(jpeg_decompress_struct *, unsigned __int8 **, unsigned int *, unsigned int); // eax

  main = cinfo->main;
  if ( LOBYTE(main[6].start_pass) == 0 )
  {
    if ( cinfo->coef->decompress_data(
           a1: cinfo,
           a2: *((unsigned __int8 ****)&main[7].start_pass + (int)main[8].start_pass)) == 0 )
      return;
    ++main[9].process_data;
    LOBYTE(main[6].start_pass) = 1;
  }
  process_data = main[8].process_data;
  if ( process_data == nullptr )
  {
LABEL_9:
    v7 = main[9].process_data;
    main[6].process_data = nullptr;
    main[9].start_pass = (void (__cdecl *)(jpeg_decompress_struct *, J_BUF_MODE))(cinfo->min_DCT_scaled_size - 1);
    if ( v7 == (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 **, unsigned int *, unsigned int))cinfo->total_iMCU_rows )
      set_bottom_pointers(cinfo);
    main[8].process_data = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 **, unsigned int *, unsigned int))1;
    goto LABEL_12;
  }
  v6 = (char *)process_data - 1;
  if ( v6 != nullptr )
  {
    if ( v6 != (char *)1 )
      return;
    cinfo->post->post_process_data(
      a1: cinfo,
      a2: *((unsigned __int8 ****)&main[7].start_pass + (int)main[8].start_pass),
      a3: (unsigned int *)&main[6].process_data,
      a4: (unsigned int)main[9].start_pass,
      a5: output_buf,
      a6: out_row_ctr,
      a7: out_rows_avail);
    if ( (char *)main[6].process_data < (char *)main[9].start_pass )
      return;
    main[8].process_data = nullptr;
    if ( *out_row_ctr >= out_rows_avail )
      return;
    goto LABEL_9;
  }
LABEL_12:
  cinfo->post->post_process_data(
    a1: cinfo,
    a2: *((unsigned __int8 ****)&main[7].start_pass + (int)main[8].start_pass),
    a3: (unsigned int *)&main[6].process_data,
    a4: (unsigned int)main[9].start_pass,
    a5: output_buf,
    a6: out_row_ctr,
    a7: out_rows_avail);
  if ( (char *)main[6].process_data >= (char *)main[9].start_pass )
  {
    if ( main[9].process_data == (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 **, unsigned int *, unsigned int))1 )
      set_wraparound_pointers(cinfo);
    main[8].start_pass = (void (__cdecl *)(jpeg_decompress_struct *, J_BUF_MODE))((int)main[8].start_pass ^ 1);
    LOBYTE(main[6].start_pass) = 0;
    main[6].process_data = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 **, unsigned int *, unsigned int))(cinfo->min_DCT_scaled_size + 1);
    main[9].start_pass = (void (__cdecl *)(jpeg_decompress_struct *, J_BUF_MODE))(cinfo->min_DCT_scaled_size + 2);
    main[8].process_data = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 **, unsigned int *, unsigned int))2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10276260
// Name: process_data_crank_post
// Source: json
//------------------------------------------------------------------------------
void __cdecl process_data_crank_post(
        jpeg_decompress_struct *cinfo,
        unsigned __int8 **output_buf,
        unsigned int *out_row_ctr,
        unsigned int out_rows_avail)
{
  cinfo->post->post_process_data(
    a1: cinfo,
    a2: nullptr,
    a3: nullptr,
    a4: 0,
    a5: output_buf,
    a6: out_row_ctr,
    a7: out_rows_avail);
}

//------------------------------------------------------------------------------
// Address: 0x10276290
// Name: start_pass_main
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_main(jpeg_common_struct *cinfo, J_BUF_MODE pass_mode)
{
  jpeg_d_main_controller *mem; // esi

  mem = (jpeg_d_main_controller *)cinfo[16].mem;
  if ( pass_mode != JBUF_PASS_THRU )
  {
    if ( pass_mode == JBUF_CRANK_DEST )
    {
      mem->process_data = process_data_crank_post;
    }
    else
    {
      cinfo->err->msg_code = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
  }
  else if ( LOBYTE(cinfo[17].progress->pass_limit) != 0 )
  {
    mem->process_data = process_data_context_main;
    make_funny_pointers((jpeg_decompress_struct *)cinfo);
    mem[8].start_pass = nullptr;
    mem[8].process_data = nullptr;
    mem[9].process_data = nullptr;
    LOBYTE(mem[6].start_pass) = 0;
    mem[6].process_data = nullptr;
  }
  else
  {
    LOBYTE(mem[6].start_pass) = 0;
    mem[6].process_data = nullptr;
    mem->process_data = process_data_simple_main;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10276310
// Name: _jinit_d_main_controller
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_d_main_controller(jpeg_common_struct *cinfo, unsigned __int8 need_full_buffer)
{
  jpeg_d_main_controller *v3; // ebx
  int v4; // eax
  int *p_free_pool; // edi
  jpeg_d_main_controller *v6; // ebx
  int ci; // [esp+10h] [ebp+8h]
  int ngroups; // [esp+14h] [ebp+Ch]

  v3 = (jpeg_d_main_controller *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 80);
  cinfo[16].mem = (jpeg_memory_mgr *)v3;
  v3->start_pass = (void (__cdecl *)(jpeg_decompress_struct *, J_BUF_MODE))start_pass_main;
  if ( need_full_buffer != 0 )
  {
    cinfo->err->msg_code = 4;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( LOBYTE(cinfo[17].progress->pass_limit) != 0 )
  {
    if ( *(int *)&cinfo[11].is_decompressor < 2 )
    {
      cinfo->err->msg_code = 47;
      cinfo->err->error_exit(a1: cinfo);
    }
    alloc_funny_pointers(cinfo);
    v4 = *(_DWORD *)&cinfo[11].is_decompressor + 2;
  }
  else
  {
    v4 = *(_DWORD *)&cinfo[11].is_decompressor;
  }
  ngroups = v4;
  ci = 0;
  if ( (int)cinfo[1].client_data > 0 )
  {
    p_free_pool = (int *)&cinfo[8].mem->free_pool;
    v6 = v3 + 1;
    do
    {
      v6->start_pass = (void (__cdecl *)(jpeg_decompress_struct *, J_BUF_MODE))cinfo->mem->alloc_sarray(
                                                                                 a1: cinfo,
                                                                                 a2: 1,
                                                                                 a3: *p_free_pool * *(p_free_pool - 2),
                                                                                 a4: ngroups
                                                                               * (*p_free_pool
                                                                                * *(p_free_pool - 6)
                                                                                / *(_DWORD *)&cinfo[11].is_decompressor));
      v6 = (jpeg_d_main_controller *)((char *)v6 + 4);
      p_free_pool += 21;
      ++ci;
    }
    while ( ci < (int)cinfo[1].client_data );
  }
}

} // namespace client
