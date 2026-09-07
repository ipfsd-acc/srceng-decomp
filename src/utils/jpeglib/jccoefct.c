// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jccoefct.c
// Functions: 5
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10253510
// Name: compress_data
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl compress_data(jpeg_compress_struct *cinfo, unsigned __int8 ***input_buf)
{
  jpeg_compress_struct *v2; // esi
  jpeg_c_coef_controller *p_pub; // eax
  void (__cdecl *start_pass)(jpeg_compress_struct *, J_BUF_MODE); // ecx
  unsigned int v5; // edx
  jpeg_c_coef_controller *v6; // eax
  unsigned __int8 (__cdecl *v8)(jpeg_compress_struct *, unsigned __int8 ***); // ebx
  int v9; // edi
  jpeg_component_info **cur_comp_info; // esi
  jpeg_component_info *v11; // esi
  signed int last_col_width; // ebx
  int MCU_width; // eax
  int v14; // eax
  __int16 (**v15)[64]; // ecx
  signed int v16; // eax
  __int16 (**v17)[64]; // eax
  bool v18; // zf
  jpeg_component_info *v19; // ecx
  unsigned __int8 (__cdecl *last_row_height)(jpeg_compress_struct *, unsigned __int8 ***); // edx
  int xpos; // [esp+Ch] [ebp-30h]
  unsigned int last_iMCU_row; // [esp+10h] [ebp-2Ch]
  jpeg_component_info **v23; // [esp+14h] [ebp-28h]
  int ci; // [esp+18h] [ebp-24h]
  int bi; // [esp+1Ch] [ebp-20h]
  int blockcnt; // [esp+20h] [ebp-1Ch]
  unsigned int last_MCU_col; // [esp+24h] [ebp-18h]
  int yindex; // [esp+28h] [ebp-14h]
  int ypos; // [esp+2Ch] [ebp-10h]
  unsigned int MCU_col_num; // [esp+30h] [ebp-Ch]
  int yoffset; // [esp+34h] [ebp-8h]
  my_coef_controller *coef; // [esp+38h] [ebp-4h]

  v2 = cinfo;
  p_pub = cinfo->coef;
  last_iMCU_row = cinfo->total_iMCU_rows - 1;
  start_pass = p_pub[2].start_pass;
  v5 = cinfo->MCUs_per_row - 1;
  coef = (my_coef_controller *)p_pub;
  last_MCU_col = v5;
  yoffset = (int)start_pass;
  if ( (int)start_pass < (int)p_pub[2].compress_data )
  {
    while ( 1 )
    {
      v8 = p_pub[1].compress_data;
      MCU_col_num = (unsigned int)v8;
      if ( (unsigned int)v8 <= v5 )
        break;
LABEL_29:
      start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))((char *)start_pass + 1);
      p_pub[1].compress_data = nullptr;
      yoffset = (int)start_pass;
      if ( (int)start_pass >= (int)p_pub[2].compress_data )
        goto LABEL_2;
      v5 = last_MCU_col;
    }
    while ( 1 )
    {
      v9 = 0;
      ci = 0;
      if ( v2->comps_in_scan > 0 )
      {
        cur_comp_info = v2->cur_comp_info;
        v23 = cur_comp_info;
        do
        {
          v11 = *cur_comp_info;
          if ( (unsigned int)v8 >= last_MCU_col )
            last_col_width = v11->last_col_width;
          else
            last_col_width = v11->MCU_width;
          xpos = MCU_col_num * v11->MCU_sample_width;
          blockcnt = last_col_width;
          ypos = 8 * yoffset;
          yindex = 0;
          if ( v11->MCU_height > 0 )
          {
            MCU_width = v11->MCU_width;
            do
            {
              if ( coef->iMCU_row_num < last_iMCU_row || yoffset + yindex < v11->last_row_height )
              {
                cinfo->fdct->forward_DCT(
                  a1: cinfo,
                  a2: v11,
                  a3: input_buf[v11->component_index],
                  a4: coef->MCU_buffer[v9],
                  a5: ypos,
                  a6: xpos,
                  a7: last_col_width);
                v16 = v11->MCU_width;
                if ( last_col_width < v16 )
                {
                  jzero_far(
                    target: (unsigned __int8 *)coef->MCU_buffer[last_col_width + 2 * v9],
                    bytestozero: (v16 - last_col_width) << 7);
                  bi = last_col_width;
                  if ( last_col_width < v11->MCU_width )
                  {
                    v17 = &coef->MCU_buffer[last_col_width + 2 * v9];
                    do
                    {
                      *(_WORD *)*v17 = *(_WORD *)*(v17 - 1);
                      ++v17;
                      ++bi;
                    }
                    while ( bi < v11->MCU_width );
                  }
                }
              }
              else
              {
                jzero_far(target: (unsigned __int8 *)coef->MCU_buffer[v9], bytestozero: MCU_width << 7);
                v14 = 0;
                if ( v11->MCU_width > 0 )
                {
                  v15 = &coef->MCU_buffer[v9];
                  do
                  {
                    ++v14;
                    *(_WORD *)*v15++ = **((_WORD **)&coef->MCU_rows_per_iMCU_row + v9);
                  }
                  while ( v14 < v11->MCU_width );
                  last_col_width = blockcnt;
                }
              }
              MCU_width = v11->MCU_width;
              ypos += 8;
              v9 += MCU_width;
              ++yindex;
            }
            while ( yindex < v11->MCU_height );
          }
          v8 = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))MCU_col_num;
          cur_comp_info = v23 + 1;
          ++ci;
          ++v23;
        }
        while ( ci < cinfo->comps_in_scan );
        p_pub = &coef->pub;
        v2 = cinfo;
      }
      v18 = v2->entropy->encode_mcu(a1: v2, a2: (__int16 (**)[64])&p_pub[3]) == 0;
      p_pub = &coef->pub;
      if ( v18 )
        break;
      v8 = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))((char *)v8 + 1);
      MCU_col_num = (unsigned int)v8;
      if ( (unsigned int)v8 > last_MCU_col )
      {
        start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))yoffset;
        goto LABEL_29;
      }
    }
    coef->mcu_ctr = (unsigned int)v8;
    coef->MCU_vert_offset = yoffset;
    return 0;
  }
  else
  {
LABEL_2:
    ++p_pub[1].start_pass;
    v6 = v2->coef;
    if ( v2->comps_in_scan <= 1 )
    {
      v19 = v2->cur_comp_info[0];
      if ( (char *)v6[1].start_pass >= (char *)(v2->total_iMCU_rows - 1) )
        last_row_height = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))v19->last_row_height;
      else
        last_row_height = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))v19->v_samp_factor;
      v6[2].compress_data = last_row_height;
      v6[1].compress_data = nullptr;
      v6[2].start_pass = nullptr;
      return 1;
    }
    else
    {
      v6[2].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))1;
      v6[1].compress_data = nullptr;
      v6[2].start_pass = nullptr;
      return 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102537A0
// Name: compress_output
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl compress_output(jpeg_compress_struct *cinfo)
{
  jpeg_compress_struct *v1; // esi
  my_coef_controller *v2; // edx
  int v3; // edi
  jpeg_component_info **cur_comp_info; // ebx
  jpeg_memory_mgr *mem; // eax
  __int16 (**v6)[64]; // eax
  int MCU_vert_offset; // eax
  unsigned int mcu_ctr; // edi
  int v9; // ebx
  jpeg_component_info *v10; // edi
  int MCU_width; // ecx
  bool v12; // cc
  __int16 *v13; // eax
  int v14; // edx
  __int16 (**v15)[64]; // esi
  my_coef_controller *v16; // eax
  int v17; // ecx
  jpeg_c_coef_controller *v19; // eax
  jpeg_component_info *v20; // ecx
  unsigned __int8 (__cdecl *last_row_height)(jpeg_compress_struct *, unsigned __int8 ***); // edx
  __int16 (**buffer[4])[64]; // [esp+Ch] [ebp-30h]
  unsigned int v23; // [esp+1Ch] [ebp-20h]
  int yindex; // [esp+20h] [ebp-1Ch]
  unsigned int MCU_col_num; // [esp+24h] [ebp-18h]
  jpeg_component_info **v26; // [esp+28h] [ebp-14h]
  int ci; // [esp+2Ch] [ebp-10h]
  __int16 (**v28)[64]; // [esp+30h] [ebp-Ch]
  int yoffset; // [esp+34h] [ebp-8h]
  my_coef_controller *coef; // [esp+38h] [ebp-4h]

  v1 = cinfo;
  v2 = (my_coef_controller *)cinfo->coef;
  v3 = 0;
  coef = v2;
  if ( cinfo->comps_in_scan > 0 )
  {
    cur_comp_info = cinfo->cur_comp_info;
    do
    {
      mem = v1->mem;
      v1 = cinfo;
      v6 = mem->access_virt_barray(
             a1: (jpeg_common_struct *)cinfo,
             a2: coef->whole_image[(*cur_comp_info)->component_index],
             a3: (*cur_comp_info)->v_samp_factor * v2->iMCU_row_num,
             a4: (*cur_comp_info)->v_samp_factor,
             a5: 0);
      v2 = coef;
      buffer[v3++] = v6;
      ++cur_comp_info;
    }
    while ( v3 < cinfo->comps_in_scan );
  }
  MCU_vert_offset = v2->MCU_vert_offset;
  yoffset = MCU_vert_offset;
  if ( MCU_vert_offset >= v2->MCU_rows_per_iMCU_row )
  {
LABEL_23:
    ++v2->iMCU_row_num;
    v19 = v1->coef;
    if ( v1->comps_in_scan <= 1 )
    {
      v20 = v1->cur_comp_info[0];
      if ( (char *)v19[1].start_pass >= (char *)(v1->total_iMCU_rows - 1) )
        last_row_height = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))v20->last_row_height;
      else
        last_row_height = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))v20->v_samp_factor;
      v19[1].compress_data = nullptr;
      v19[2].start_pass = nullptr;
      v19[2].compress_data = last_row_height;
      return 1;
    }
    else
    {
      v19[1].compress_data = nullptr;
      v19[2].start_pass = nullptr;
      v19[2].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))1;
      return 1;
    }
  }
  else
  {
    while ( 1 )
    {
      mcu_ctr = v2->mcu_ctr;
      MCU_col_num = mcu_ctr;
      if ( mcu_ctr < v1->MCUs_per_row )
        break;
LABEL_20:
      ++MCU_vert_offset;
      v2->mcu_ctr = 0;
      yoffset = MCU_vert_offset;
      if ( MCU_vert_offset >= v2->MCU_rows_per_iMCU_row )
        goto LABEL_23;
    }
    while ( 1 )
    {
      v9 = 0;
      ci = 0;
      if ( v1->comps_in_scan > 0 )
      {
        v26 = v1->cur_comp_info;
        do
        {
          v10 = *v26;
          MCU_width = (*v26)->MCU_width;
          v12 = (*v26)->MCU_height <= 0;
          yindex = 0;
          if ( !v12 )
          {
            v23 = (MCU_col_num * MCU_width) << 7;
            v28 = &buffer[ci][yoffset];
            do
            {
              v13 = (__int16 *)((char *)*v28 + v23);
              v14 = 0;
              if ( MCU_width > 0 )
              {
                v15 = &coef->MCU_buffer[v9];
                do
                {
                  *v15 = (__int16 (*)[64])v13;
                  MCU_width = v10->MCU_width;
                  ++v14;
                  ++v9;
                  ++v15;
                  v13 += 64;
                }
                while ( v14 < MCU_width );
                v1 = cinfo;
              }
              ++v28;
              ++yindex;
            }
            while ( yindex < v10->MCU_height );
          }
          ++v26;
          ++ci;
        }
        while ( ci < v1->comps_in_scan );
        mcu_ctr = MCU_col_num;
        v2 = coef;
      }
      if ( v1->entropy->encode_mcu(a1: v1, a2: v2->MCU_buffer) == 0 )
        break;
      v2 = coef;
      MCU_col_num = ++mcu_ctr;
      if ( mcu_ctr >= v1->MCUs_per_row )
      {
        MCU_vert_offset = yoffset;
        goto LABEL_20;
      }
    }
    v16 = coef;
    v17 = yoffset;
    coef->mcu_ctr = mcu_ctr;
    v16->MCU_vert_offset = v17;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10253980
// Name: compress_first_pass
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl compress_first_pass(jpeg_compress_struct *cinfo, unsigned __int8 ***input_buf)
{
  jpeg_compress_struct *v2; // eax
  jpeg_component_info *comp_info; // esi
  jpeg_c_coef_controller *p_pub; // edi
  int v5; // ecx
  unsigned int width_in_blocks; // ebx
  int v7; // edx
  int v8; // edi
  int v9; // eax
  __int16 *v10; // esi
  unsigned __int8 *v11; // esi
  __int16 v12; // cx
  int i; // eax
  unsigned int v14; // ebx
  int v15; // edi
  unsigned __int8 *v16; // esi
  int v17; // edi
  int v18; // eax
  __int16 v19; // dx
  unsigned __int8 *v20; // eax
  int j; // ecx
  bool v22; // cc
  int v24; // [esp+8h] [ebp-34h]
  int ci; // [esp+10h] [ebp-2Ch]
  my_coef_controller *coef; // [esp+18h] [ebp-24h]
  unsigned int last_iMCU_row; // [esp+1Ch] [ebp-20h]
  jpeg_c_coef_controller *v29; // [esp+24h] [ebp-18h]
  int h_samp_factor; // [esp+28h] [ebp-14h]
  __int16 (**buffer)[64]; // [esp+2Ch] [ebp-10h]
  jpeg_component_info *compptr; // [esp+30h] [ebp-Ch]
  int lastblockrow; // [esp+34h] [ebp-8h]
  __int16 *lastblockrowa; // [esp+34h] [ebp-8h]
  int lastblockrowb; // [esp+34h] [ebp-8h]
  int block_row; // [esp+38h] [ebp-4h]
  int block_rowa; // [esp+38h] [ebp-4h]

  v2 = cinfo;
  comp_info = cinfo->comp_info;
  p_pub = cinfo->coef;
  coef = (my_coef_controller *)p_pub;
  last_iMCU_row = cinfo->total_iMCU_rows - 1;
  ci = 0;
  compptr = comp_info;
  if ( cinfo->num_components > 0 )
  {
    v29 = p_pub + 8;
    while ( 1 )
    {
      v5 = (int)v2->mem->access_virt_barray(
                  a1: (jpeg_common_struct *)v2,
                  a2: (jvirt_barray_control *)v29->start_pass,
                  a3: comp_info->v_samp_factor * (int)p_pub[1].start_pass,
                  a4: comp_info->v_samp_factor,
                  a5: 1u);
      buffer = (__int16 (**)[64])v5;
      if ( (char *)p_pub[1].start_pass >= (char *)last_iMCU_row )
      {
        lastblockrow = comp_info->height_in_blocks % comp_info->v_samp_factor;
        if ( lastblockrow == 0 )
          lastblockrow = comp_info->v_samp_factor;
      }
      else
      {
        lastblockrow = comp_info->v_samp_factor;
      }
      width_in_blocks = comp_info->width_in_blocks;
      v7 = width_in_blocks % comp_info->h_samp_factor;
      h_samp_factor = comp_info->h_samp_factor;
      v8 = v7;
      if ( v7 > 0 )
        v8 = h_samp_factor - v7;
      v9 = 0;
      block_row = 0;
      if ( lastblockrow > 0 )
      {
        while ( 1 )
        {
          v10 = *(__int16 **)(v5 + 4 * v9);
          cinfo->fdct->forward_DCT(
            a1: cinfo,
            a2: compptr,
            a3: *input_buf,
            a4: (__int16 (*)[64])v10,
            a5: 8 * v9,
            a6: 0,
            a7: width_in_blocks);
          if ( v8 > 0 )
          {
            v11 = (unsigned __int8 *)&v10[64 * width_in_blocks];
            jzero_far(target: v11, bytestozero: v8 << 7);
            v12 = *((_WORD *)v11 - 64);
            for ( i = v8; i != 0; --i )
            {
              *(_WORD *)v11 = v12;
              v11 += 128;
            }
          }
          v5 = (int)buffer;
          if ( ++block_row >= lastblockrow )
            break;
          v9 = block_row;
        }
        comp_info = compptr;
      }
      if ( coef->iMCU_row_num == last_iMCU_row )
      {
        v14 = v8 + width_in_blocks;
        v15 = lastblockrow;
        block_rowa = lastblockrow;
        if ( lastblockrow < comp_info->v_samp_factor )
        {
          while ( 1 )
          {
            v16 = *(unsigned __int8 **)(v5 + 4 * v15);
            lastblockrowa = *(__int16 **)(v5 + 4 * v15 - 4);
            jzero_far(target: v16, bytestozero: v14 << 7);
            if ( v14 / h_samp_factor != 0 )
            {
              v17 = h_samp_factor << 7;
              v18 = (char *)lastblockrowa - (char *)v16;
              v24 = (char *)lastblockrowa - (char *)v16;
              lastblockrowb = v14 / h_samp_factor;
              do
              {
                v19 = *(_WORD *)&v16[v18 - 128 + v17];
                if ( h_samp_factor > 0 )
                {
                  v20 = v16;
                  for ( j = h_samp_factor; j != 0; --j )
                  {
                    *(_WORD *)v20 = v19;
                    v20 += 128;
                  }
                  v18 = v24;
                }
                v16 += v17;
                --lastblockrowb;
              }
              while ( lastblockrowb != 0 );
              v15 = block_rowa;
            }
            block_rowa = ++v15;
            if ( v15 >= compptr->v_samp_factor )
              break;
            v5 = (int)buffer;
          }
          comp_info = compptr;
        }
      }
      v29 = (jpeg_c_coef_controller *)((char *)v29 + 4);
      ++input_buf;
      ++comp_info;
      v22 = ++ci < cinfo->num_components;
      compptr = comp_info;
      v2 = cinfo;
      if ( !v22 )
        break;
      p_pub = &coef->pub;
    }
  }
  return compress_output(cinfo: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10253B80
// Name: start_pass_coef
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_coef(jpeg_common_struct *cinfo, J_BUF_MODE pass_mode)
{
  jpeg_c_coef_controller *v2; // esi
  jpeg_c_coef_controller *v3; // ecx
  jpeg_component_info *v4; // ebx
  unsigned __int8 (__cdecl *last_row_height)(jpeg_compress_struct *, unsigned __int8 ***); // ebx

  v2 = *(jpeg_c_coef_controller **)&cinfo[13].is_decompressor;
  v2[1].start_pass = nullptr;
  v3 = *(jpeg_c_coef_controller **)&cinfo[13].is_decompressor;
  if ( (int)cinfo[9].client_data <= 1 )
  {
    v4 = *(jpeg_component_info **)&cinfo[9].is_decompressor;
    if ( (char *)v3[1].start_pass >= (char *)((char *)&cinfo[9].progress[-1].total_passes + 3) )
      last_row_height = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))v4->last_row_height;
    else
      last_row_height = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))v4->v_samp_factor;
    v3[2].compress_data = last_row_height;
  }
  else
  {
    v3[2].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))1;
  }
  v3[1].compress_data = nullptr;
  v3[2].start_pass = nullptr;
  if ( pass_mode != JBUF_PASS_THRU )
  {
    if ( pass_mode == JBUF_CRANK_DEST )
    {
      if ( v2[8].start_pass == nullptr )
      {
        cinfo->err->msg_code = 4;
        cinfo->err->error_exit(a1: cinfo);
      }
      v2->compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))compress_output;
    }
    else if ( pass_mode == JBUF_SAVE_AND_PASS )
    {
      if ( v2[8].start_pass == nullptr )
      {
        cinfo->err->msg_code = 4;
        cinfo->err->error_exit(a1: cinfo);
      }
      v2->compress_data = compress_first_pass;
    }
    else
    {
      cinfo->err->msg_code = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
  }
  else
  {
    if ( v2[8].start_pass != nullptr )
    {
      cinfo->err->msg_code = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
    v2->compress_data = compress_data;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10253C70
// Name: _jinit_c_coef_controller
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_c_coef_controller(jpeg_common_struct *cinfo, unsigned __int8 need_full_buffer)
{
  jpeg_c_coef_controller *v3; // ebx
  int *v4; // esi
  jpeg_memory_mgr *mem; // ebx
  int v6; // eax
  char *v7; // eax
  int v8; // [esp-Ch] [ebp-14h]
  jpeg_compress_struct *cinfoa; // [esp+10h] [ebp+8h]
  int ci; // [esp+14h] [ebp+Ch]

  v3 = (jpeg_c_coef_controller *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 104);
  *(_DWORD *)&cinfo[13].is_decompressor = v3;
  v3->start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))start_pass_coef;
  if ( need_full_buffer != 0 )
  {
    ci = 0;
    if ( (int)cinfo[2].client_data > 0 )
    {
      v4 = (int *)(cinfo[2].global_state + 12);
      cinfoa = (jpeg_compress_struct *)&v3[8];
      do
      {
        mem = cinfo->mem;
        v8 = jround_up(a: v4[5], b: *v4);
        v6 = jround_up(a: v4[4], b: *(v4 - 1));
        cinfoa->err = (jpeg_error_mgr *)((int (__cdecl *)(jpeg_common_struct *, int, _DWORD, int, int))mem->request_virt_barray)(
                                          a1: cinfo,
                                          a2: 1,
                                          a3: 0,
                                          a4: v6,
                                          a5: v8);
        v4 += 21;
        ++ci;
        cinfoa = (jpeg_compress_struct *)((char *)cinfoa + 4);
      }
      while ( ci < (int)cinfo[2].client_data );
    }
  }
  else
  {
    v7 = (char *)cinfo->mem->alloc_large(a1: cinfo, a2: 1, a3: 1280);
    v3[3].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))(v7 + 128);
    v3[4].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))(v7 + 256);
    v3[4].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))(v7 + 384);
    v3[5].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))(v7 + 512);
    v3[5].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))(v7 + 640);
    v3[6].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))(v7 + 768);
    v3[3].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))v7;
    v3[6].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))(v7 + 896);
    v3[7].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))(v7 + 1024);
    v3[7].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))(v7 + 1152);
    v3[8].start_pass = nullptr;
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10253540
// Name: compress_data
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl compress_data(jpeg_compress_struct *cinfo, unsigned __int8 ***input_buf)
{
  jpeg_compress_struct *v2; // esi
  jpeg_c_coef_controller *p_pub; // eax
  void (__cdecl *start_pass)(jpeg_compress_struct *, J_BUF_MODE); // ecx
  unsigned int v5; // edx
  jpeg_c_coef_controller *v6; // eax
  unsigned __int8 (__cdecl *v8)(jpeg_compress_struct *, unsigned __int8 ***); // ebx
  int v9; // edi
  jpeg_component_info **cur_comp_info; // esi
  jpeg_component_info *v11; // esi
  signed int last_col_width; // ebx
  int MCU_width; // eax
  int v14; // eax
  __int16 (**v15)[64]; // ecx
  signed int v16; // eax
  __int16 (**v17)[64]; // eax
  bool v18; // zf
  jpeg_component_info *v19; // ecx
  unsigned __int8 (__cdecl *last_row_height)(jpeg_compress_struct *, unsigned __int8 ***); // edx
  int xpos; // [esp+Ch] [ebp-30h]
  unsigned int last_iMCU_row; // [esp+10h] [ebp-2Ch]
  jpeg_component_info **v23; // [esp+14h] [ebp-28h]
  int ci; // [esp+18h] [ebp-24h]
  int bi; // [esp+1Ch] [ebp-20h]
  int blockcnt; // [esp+20h] [ebp-1Ch]
  unsigned int last_MCU_col; // [esp+24h] [ebp-18h]
  int yindex; // [esp+28h] [ebp-14h]
  int ypos; // [esp+2Ch] [ebp-10h]
  unsigned int MCU_col_num; // [esp+30h] [ebp-Ch]
  int yoffset; // [esp+34h] [ebp-8h]
  my_coef_controller *coef; // [esp+38h] [ebp-4h]

  v2 = cinfo;
  p_pub = cinfo->coef;
  last_iMCU_row = cinfo->total_iMCU_rows - 1;
  start_pass = p_pub[2].start_pass;
  v5 = cinfo->MCUs_per_row - 1;
  coef = (my_coef_controller *)p_pub;
  last_MCU_col = v5;
  yoffset = (int)start_pass;
  if ( (int)start_pass < (int)p_pub[2].compress_data )
  {
    while ( 1 )
    {
      v8 = p_pub[1].compress_data;
      MCU_col_num = (unsigned int)v8;
      if ( (unsigned int)v8 <= v5 )
        break;
LABEL_29:
      start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))((char *)start_pass + 1);
      p_pub[1].compress_data = nullptr;
      yoffset = (int)start_pass;
      if ( (int)start_pass >= (int)p_pub[2].compress_data )
        goto LABEL_2;
      v5 = last_MCU_col;
    }
    while ( 1 )
    {
      v9 = 0;
      ci = 0;
      if ( v2->comps_in_scan > 0 )
      {
        cur_comp_info = v2->cur_comp_info;
        v23 = cur_comp_info;
        do
        {
          v11 = *cur_comp_info;
          if ( (unsigned int)v8 >= last_MCU_col )
            last_col_width = v11->last_col_width;
          else
            last_col_width = v11->MCU_width;
          xpos = MCU_col_num * v11->MCU_sample_width;
          blockcnt = last_col_width;
          ypos = 8 * yoffset;
          yindex = 0;
          if ( v11->MCU_height > 0 )
          {
            MCU_width = v11->MCU_width;
            do
            {
              if ( coef->iMCU_row_num < last_iMCU_row || yoffset + yindex < v11->last_row_height )
              {
                cinfo->fdct->forward_DCT(
                  a1: cinfo,
                  a2: v11,
                  a3: input_buf[v11->component_index],
                  a4: coef->MCU_buffer[v9],
                  a5: ypos,
                  a6: xpos,
                  a7: last_col_width);
                v16 = v11->MCU_width;
                if ( last_col_width < v16 )
                {
                  jzero_far(
                    target: (unsigned __int8 *)coef->MCU_buffer[last_col_width + 2 * v9],
                    bytestozero: (v16 - last_col_width) << 7);
                  bi = last_col_width;
                  if ( last_col_width < v11->MCU_width )
                  {
                    v17 = &coef->MCU_buffer[last_col_width + 2 * v9];
                    do
                    {
                      *(_WORD *)*v17 = *(_WORD *)*(v17 - 1);
                      ++v17;
                      ++bi;
                    }
                    while ( bi < v11->MCU_width );
                  }
                }
              }
              else
              {
                jzero_far(target: (unsigned __int8 *)coef->MCU_buffer[v9], bytestozero: MCU_width << 7);
                v14 = 0;
                if ( v11->MCU_width > 0 )
                {
                  v15 = &coef->MCU_buffer[v9];
                  do
                  {
                    ++v14;
                    *(_WORD *)*v15++ = **((_WORD **)&coef->MCU_rows_per_iMCU_row + v9);
                  }
                  while ( v14 < v11->MCU_width );
                  last_col_width = blockcnt;
                }
              }
              MCU_width = v11->MCU_width;
              ypos += 8;
              v9 += MCU_width;
              ++yindex;
            }
            while ( yindex < v11->MCU_height );
          }
          v8 = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))MCU_col_num;
          cur_comp_info = v23 + 1;
          ++ci;
          ++v23;
        }
        while ( ci < cinfo->comps_in_scan );
        p_pub = &coef->pub;
        v2 = cinfo;
      }
      v18 = v2->entropy->encode_mcu(a1: v2, a2: (__int16 (**)[64])&p_pub[3]) == 0;
      p_pub = &coef->pub;
      if ( v18 )
        break;
      v8 = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))((char *)v8 + 1);
      MCU_col_num = (unsigned int)v8;
      if ( (unsigned int)v8 > last_MCU_col )
      {
        start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))yoffset;
        goto LABEL_29;
      }
    }
    coef->mcu_ctr = (unsigned int)v8;
    coef->MCU_vert_offset = yoffset;
    return 0;
  }
  else
  {
LABEL_2:
    ++p_pub[1].start_pass;
    v6 = v2->coef;
    if ( v2->comps_in_scan <= 1 )
    {
      v19 = v2->cur_comp_info[0];
      if ( (char *)v6[1].start_pass >= (char *)(v2->total_iMCU_rows - 1) )
        last_row_height = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))v19->last_row_height;
      else
        last_row_height = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))v19->v_samp_factor;
      v6[2].compress_data = last_row_height;
      v6[1].compress_data = nullptr;
      v6[2].start_pass = nullptr;
      return 1;
    }
    else
    {
      v6[2].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))1;
      v6[1].compress_data = nullptr;
      v6[2].start_pass = nullptr;
      return 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102537D0
// Name: compress_output
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl compress_output(jpeg_compress_struct *cinfo)
{
  jpeg_compress_struct *v1; // esi
  my_coef_controller *v2; // edx
  int v3; // edi
  jpeg_component_info **cur_comp_info; // ebx
  jpeg_memory_mgr *mem; // eax
  __int16 (**v6)[64]; // eax
  int MCU_vert_offset; // eax
  unsigned int mcu_ctr; // edi
  int v9; // ebx
  jpeg_component_info *v10; // edi
  int MCU_width; // ecx
  bool v12; // cc
  __int16 *v13; // eax
  int v14; // edx
  __int16 (**v15)[64]; // esi
  my_coef_controller *v16; // eax
  int v17; // ecx
  jpeg_c_coef_controller *v19; // eax
  jpeg_component_info *v20; // ecx
  unsigned __int8 (__cdecl *last_row_height)(jpeg_compress_struct *, unsigned __int8 ***); // edx
  __int16 (**buffer[4])[64]; // [esp+Ch] [ebp-30h]
  unsigned int v23; // [esp+1Ch] [ebp-20h]
  int yindex; // [esp+20h] [ebp-1Ch]
  unsigned int MCU_col_num; // [esp+24h] [ebp-18h]
  jpeg_component_info **v26; // [esp+28h] [ebp-14h]
  int ci; // [esp+2Ch] [ebp-10h]
  __int16 (**v28)[64]; // [esp+30h] [ebp-Ch]
  int yoffset; // [esp+34h] [ebp-8h]
  my_coef_controller *coef; // [esp+38h] [ebp-4h]

  v1 = cinfo;
  v2 = (my_coef_controller *)cinfo->coef;
  v3 = 0;
  coef = v2;
  if ( cinfo->comps_in_scan > 0 )
  {
    cur_comp_info = cinfo->cur_comp_info;
    do
    {
      mem = v1->mem;
      v1 = cinfo;
      v6 = mem->access_virt_barray(
             a1: (jpeg_common_struct *)cinfo,
             a2: coef->whole_image[(*cur_comp_info)->component_index],
             a3: (*cur_comp_info)->v_samp_factor * v2->iMCU_row_num,
             a4: (*cur_comp_info)->v_samp_factor,
             a5: 0);
      v2 = coef;
      buffer[v3++] = v6;
      ++cur_comp_info;
    }
    while ( v3 < cinfo->comps_in_scan );
  }
  MCU_vert_offset = v2->MCU_vert_offset;
  yoffset = MCU_vert_offset;
  if ( MCU_vert_offset >= v2->MCU_rows_per_iMCU_row )
  {
LABEL_23:
    ++v2->iMCU_row_num;
    v19 = v1->coef;
    if ( v1->comps_in_scan <= 1 )
    {
      v20 = v1->cur_comp_info[0];
      if ( (char *)v19[1].start_pass >= (char *)(v1->total_iMCU_rows - 1) )
        last_row_height = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))v20->last_row_height;
      else
        last_row_height = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))v20->v_samp_factor;
      v19[1].compress_data = nullptr;
      v19[2].start_pass = nullptr;
      v19[2].compress_data = last_row_height;
      return 1;
    }
    else
    {
      v19[1].compress_data = nullptr;
      v19[2].start_pass = nullptr;
      v19[2].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))1;
      return 1;
    }
  }
  else
  {
    while ( 1 )
    {
      mcu_ctr = v2->mcu_ctr;
      MCU_col_num = mcu_ctr;
      if ( mcu_ctr < v1->MCUs_per_row )
        break;
LABEL_20:
      ++MCU_vert_offset;
      v2->mcu_ctr = 0;
      yoffset = MCU_vert_offset;
      if ( MCU_vert_offset >= v2->MCU_rows_per_iMCU_row )
        goto LABEL_23;
    }
    while ( 1 )
    {
      v9 = 0;
      ci = 0;
      if ( v1->comps_in_scan > 0 )
      {
        v26 = v1->cur_comp_info;
        do
        {
          v10 = *v26;
          MCU_width = (*v26)->MCU_width;
          v12 = (*v26)->MCU_height <= 0;
          yindex = 0;
          if ( !v12 )
          {
            v23 = (MCU_col_num * MCU_width) << 7;
            v28 = &buffer[ci][yoffset];
            do
            {
              v13 = (__int16 *)((char *)*v28 + v23);
              v14 = 0;
              if ( MCU_width > 0 )
              {
                v15 = &coef->MCU_buffer[v9];
                do
                {
                  *v15 = (__int16 (*)[64])v13;
                  MCU_width = v10->MCU_width;
                  ++v14;
                  ++v9;
                  ++v15;
                  v13 += 64;
                }
                while ( v14 < MCU_width );
                v1 = cinfo;
              }
              ++v28;
              ++yindex;
            }
            while ( yindex < v10->MCU_height );
          }
          ++v26;
          ++ci;
        }
        while ( ci < v1->comps_in_scan );
        mcu_ctr = MCU_col_num;
        v2 = coef;
      }
      if ( v1->entropy->encode_mcu(a1: v1, a2: v2->MCU_buffer) == 0 )
        break;
      v2 = coef;
      MCU_col_num = ++mcu_ctr;
      if ( mcu_ctr >= v1->MCUs_per_row )
      {
        MCU_vert_offset = yoffset;
        goto LABEL_20;
      }
    }
    v16 = coef;
    v17 = yoffset;
    coef->mcu_ctr = mcu_ctr;
    v16->MCU_vert_offset = v17;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102539B0
// Name: compress_first_pass
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl compress_first_pass(jpeg_compress_struct *cinfo, unsigned __int8 ***input_buf)
{
  jpeg_compress_struct *v2; // eax
  jpeg_component_info *comp_info; // esi
  jpeg_c_coef_controller *p_pub; // edi
  int v5; // ecx
  unsigned int width_in_blocks; // ebx
  int v7; // edx
  int v8; // edi
  int v9; // eax
  __int16 *v10; // esi
  unsigned __int8 *v11; // esi
  __int16 v12; // cx
  int i; // eax
  unsigned int v14; // ebx
  int v15; // edi
  unsigned __int8 *v16; // esi
  int v17; // edi
  int v18; // eax
  __int16 v19; // dx
  unsigned __int8 *v20; // eax
  int j; // ecx
  bool v22; // cc
  int v24; // [esp+8h] [ebp-34h]
  int ci; // [esp+10h] [ebp-2Ch]
  my_coef_controller *coef; // [esp+18h] [ebp-24h]
  unsigned int last_iMCU_row; // [esp+1Ch] [ebp-20h]
  jpeg_c_coef_controller *v29; // [esp+24h] [ebp-18h]
  int h_samp_factor; // [esp+28h] [ebp-14h]
  __int16 (**buffer)[64]; // [esp+2Ch] [ebp-10h]
  jpeg_component_info *compptr; // [esp+30h] [ebp-Ch]
  int lastblockrow; // [esp+34h] [ebp-8h]
  __int16 *lastblockrowa; // [esp+34h] [ebp-8h]
  int lastblockrowb; // [esp+34h] [ebp-8h]
  int block_row; // [esp+38h] [ebp-4h]
  int block_rowa; // [esp+38h] [ebp-4h]

  v2 = cinfo;
  comp_info = cinfo->comp_info;
  p_pub = cinfo->coef;
  coef = (my_coef_controller *)p_pub;
  last_iMCU_row = cinfo->total_iMCU_rows - 1;
  ci = 0;
  compptr = comp_info;
  if ( cinfo->num_components > 0 )
  {
    v29 = p_pub + 8;
    while ( 1 )
    {
      v5 = (int)v2->mem->access_virt_barray(
                  a1: (jpeg_common_struct *)v2,
                  a2: (jvirt_barray_control *)v29->start_pass,
                  a3: comp_info->v_samp_factor * (int)p_pub[1].start_pass,
                  a4: comp_info->v_samp_factor,
                  a5: 1u);
      buffer = (__int16 (**)[64])v5;
      if ( (char *)p_pub[1].start_pass >= (char *)last_iMCU_row )
      {
        lastblockrow = comp_info->height_in_blocks % comp_info->v_samp_factor;
        if ( lastblockrow == 0 )
          lastblockrow = comp_info->v_samp_factor;
      }
      else
      {
        lastblockrow = comp_info->v_samp_factor;
      }
      width_in_blocks = comp_info->width_in_blocks;
      v7 = width_in_blocks % comp_info->h_samp_factor;
      h_samp_factor = comp_info->h_samp_factor;
      v8 = v7;
      if ( v7 > 0 )
        v8 = h_samp_factor - v7;
      v9 = 0;
      block_row = 0;
      if ( lastblockrow > 0 )
      {
        while ( 1 )
        {
          v10 = *(__int16 **)(v5 + 4 * v9);
          cinfo->fdct->forward_DCT(
            a1: cinfo,
            a2: compptr,
            a3: *input_buf,
            a4: (__int16 (*)[64])v10,
            a5: 8 * v9,
            a6: 0,
            a7: width_in_blocks);
          if ( v8 > 0 )
          {
            v11 = (unsigned __int8 *)&v10[64 * width_in_blocks];
            jzero_far(target: v11, bytestozero: v8 << 7);
            v12 = *((_WORD *)v11 - 64);
            for ( i = v8; i != 0; --i )
            {
              *(_WORD *)v11 = v12;
              v11 += 128;
            }
          }
          v5 = (int)buffer;
          if ( ++block_row >= lastblockrow )
            break;
          v9 = block_row;
        }
        comp_info = compptr;
      }
      if ( coef->iMCU_row_num == last_iMCU_row )
      {
        v14 = v8 + width_in_blocks;
        v15 = lastblockrow;
        block_rowa = lastblockrow;
        if ( lastblockrow < comp_info->v_samp_factor )
        {
          while ( 1 )
          {
            v16 = *(unsigned __int8 **)(v5 + 4 * v15);
            lastblockrowa = *(__int16 **)(v5 + 4 * v15 - 4);
            jzero_far(target: v16, bytestozero: v14 << 7);
            if ( v14 / h_samp_factor != 0 )
            {
              v17 = h_samp_factor << 7;
              v18 = (char *)lastblockrowa - (char *)v16;
              v24 = (char *)lastblockrowa - (char *)v16;
              lastblockrowb = v14 / h_samp_factor;
              do
              {
                v19 = *(_WORD *)&v16[v18 - 128 + v17];
                if ( h_samp_factor > 0 )
                {
                  v20 = v16;
                  for ( j = h_samp_factor; j != 0; --j )
                  {
                    *(_WORD *)v20 = v19;
                    v20 += 128;
                  }
                  v18 = v24;
                }
                v16 += v17;
                --lastblockrowb;
              }
              while ( lastblockrowb != 0 );
              v15 = block_rowa;
            }
            block_rowa = ++v15;
            if ( v15 >= compptr->v_samp_factor )
              break;
            v5 = (int)buffer;
          }
          comp_info = compptr;
        }
      }
      v29 = (jpeg_c_coef_controller *)((char *)v29 + 4);
      ++input_buf;
      ++comp_info;
      v22 = ++ci < cinfo->num_components;
      compptr = comp_info;
      v2 = cinfo;
      if ( !v22 )
        break;
      p_pub = &coef->pub;
    }
  }
  return compress_output(cinfo: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10253BB0
// Name: start_pass_coef
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_coef(jpeg_common_struct *cinfo, J_BUF_MODE pass_mode)
{
  jpeg_c_coef_controller *v2; // esi
  jpeg_c_coef_controller *v3; // ecx
  jpeg_component_info *v4; // ebx
  unsigned __int8 (__cdecl *last_row_height)(jpeg_compress_struct *, unsigned __int8 ***); // ebx

  v2 = *(jpeg_c_coef_controller **)&cinfo[13].is_decompressor;
  v2[1].start_pass = nullptr;
  v3 = *(jpeg_c_coef_controller **)&cinfo[13].is_decompressor;
  if ( (int)cinfo[9].client_data <= 1 )
  {
    v4 = *(jpeg_component_info **)&cinfo[9].is_decompressor;
    if ( (char *)v3[1].start_pass >= (char *)((char *)&cinfo[9].progress[-1].total_passes + 3) )
      last_row_height = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))v4->last_row_height;
    else
      last_row_height = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))v4->v_samp_factor;
    v3[2].compress_data = last_row_height;
  }
  else
  {
    v3[2].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))1;
  }
  v3[1].compress_data = nullptr;
  v3[2].start_pass = nullptr;
  if ( pass_mode != JBUF_PASS_THRU )
  {
    if ( pass_mode == JBUF_CRANK_DEST )
    {
      if ( v2[8].start_pass == nullptr )
      {
        cinfo->err->msg_code = 4;
        cinfo->err->error_exit(a1: cinfo);
      }
      v2->compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))compress_output;
    }
    else if ( pass_mode == JBUF_SAVE_AND_PASS )
    {
      if ( v2[8].start_pass == nullptr )
      {
        cinfo->err->msg_code = 4;
        cinfo->err->error_exit(a1: cinfo);
      }
      v2->compress_data = compress_first_pass;
    }
    else
    {
      cinfo->err->msg_code = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
  }
  else
  {
    if ( v2[8].start_pass != nullptr )
    {
      cinfo->err->msg_code = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
    v2->compress_data = compress_data;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10253CA0
// Name: _jinit_c_coef_controller
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_c_coef_controller(jpeg_common_struct *cinfo, unsigned __int8 need_full_buffer)
{
  jpeg_c_coef_controller *v3; // ebx
  int *v4; // esi
  jpeg_memory_mgr *mem; // ebx
  int v6; // eax
  char *v7; // eax
  int v8; // [esp-Ch] [ebp-14h]
  jpeg_compress_struct *cinfoa; // [esp+10h] [ebp+8h]
  int ci; // [esp+14h] [ebp+Ch]

  v3 = (jpeg_c_coef_controller *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 104);
  *(_DWORD *)&cinfo[13].is_decompressor = v3;
  v3->start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))start_pass_coef;
  if ( need_full_buffer != 0 )
  {
    ci = 0;
    if ( (int)cinfo[2].client_data > 0 )
    {
      v4 = (int *)(cinfo[2].global_state + 12);
      cinfoa = (jpeg_compress_struct *)&v3[8];
      do
      {
        mem = cinfo->mem;
        v8 = jround_up(a: v4[5], b: *v4);
        v6 = jround_up(a: v4[4], b: *(v4 - 1));
        cinfoa->err = (jpeg_error_mgr *)((int (__cdecl *)(jpeg_common_struct *, int, _DWORD, int, int))mem->request_virt_barray)(
                                          a1: cinfo,
                                          a2: 1,
                                          a3: 0,
                                          a4: v6,
                                          a5: v8);
        v4 += 21;
        ++ci;
        cinfoa = (jpeg_compress_struct *)((char *)cinfoa + 4);
      }
      while ( ci < (int)cinfo[2].client_data );
    }
  }
  else
  {
    v7 = (char *)cinfo->mem->alloc_large(a1: cinfo, a2: 1, a3: 1280);
    v3[3].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))(v7 + 128);
    v3[4].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))(v7 + 256);
    v3[4].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))(v7 + 384);
    v3[5].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))(v7 + 512);
    v3[5].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))(v7 + 640);
    v3[6].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))(v7 + 768);
    v3[3].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))v7;
    v3[6].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))(v7 + 896);
    v3[7].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))(v7 + 1024);
    v3[7].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))(v7 + 1152);
    v3[8].start_pass = nullptr;
  }
}

} // namespace engine_xlsp

// ============================================================
// Overlay from statsmap (Missing functions)
// ============================================================
namespace statsmap {

//------------------------------------------------------------------------------
// Address: 0x00407A60
// Name: compress_data
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl compress_data(jpeg_compress_struct *cinfo, unsigned __int8 ***input_buf)
{
  jpeg_compress_struct *v2; // esi
  jpeg_c_coef_controller *p_pub; // eax
  void (__cdecl *start_pass)(jpeg_compress_struct *, J_BUF_MODE); // ecx
  unsigned int v5; // edx
  jpeg_c_coef_controller *v6; // eax
  unsigned __int8 (__cdecl *v8)(jpeg_compress_struct *, unsigned __int8 ***); // ebx
  int v9; // edi
  jpeg_component_info **cur_comp_info; // esi
  jpeg_component_info *v11; // esi
  signed int last_col_width; // ebx
  int MCU_width; // eax
  int v14; // eax
  __int16 (**v15)[64]; // ecx
  signed int v16; // eax
  __int16 (**v17)[64]; // eax
  bool v18; // zf
  jpeg_component_info *v19; // ecx
  unsigned __int8 (__cdecl *last_row_height)(jpeg_compress_struct *, unsigned __int8 ***); // edx
  int xpos; // [esp+Ch] [ebp-30h]
  unsigned int last_iMCU_row; // [esp+10h] [ebp-2Ch]
  jpeg_component_info **v23; // [esp+14h] [ebp-28h]
  int ci; // [esp+18h] [ebp-24h]
  int bi; // [esp+1Ch] [ebp-20h]
  int blockcnt; // [esp+20h] [ebp-1Ch]
  unsigned int last_MCU_col; // [esp+24h] [ebp-18h]
  int yindex; // [esp+28h] [ebp-14h]
  int ypos; // [esp+2Ch] [ebp-10h]
  unsigned int MCU_col_num; // [esp+30h] [ebp-Ch]
  int yoffset; // [esp+34h] [ebp-8h]
  my_coef_controller *coef; // [esp+38h] [ebp-4h]

  v2 = cinfo;
  p_pub = cinfo->coef;
  last_iMCU_row = cinfo->total_iMCU_rows - 1;
  start_pass = p_pub[2].start_pass;
  v5 = cinfo->MCUs_per_row - 1;
  coef = (my_coef_controller *)p_pub;
  last_MCU_col = v5;
  yoffset = (int)start_pass;
  if ( (int)start_pass < (int)p_pub[2].compress_data )
  {
    while ( 1 )
    {
      v8 = p_pub[1].compress_data;
      MCU_col_num = (unsigned int)v8;
      if ( (unsigned int)v8 <= v5 )
        break;
LABEL_29:
      start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))((char *)start_pass + 1);
      p_pub[1].compress_data = nullptr;
      yoffset = (int)start_pass;
      if ( (int)start_pass >= (int)p_pub[2].compress_data )
        goto LABEL_2;
      v5 = last_MCU_col;
    }
    while ( 1 )
    {
      v9 = 0;
      ci = 0;
      if ( v2->comps_in_scan > 0 )
      {
        cur_comp_info = v2->cur_comp_info;
        v23 = cur_comp_info;
        do
        {
          v11 = *cur_comp_info;
          if ( (unsigned int)v8 >= last_MCU_col )
            last_col_width = v11->last_col_width;
          else
            last_col_width = v11->MCU_width;
          xpos = MCU_col_num * v11->MCU_sample_width;
          blockcnt = last_col_width;
          ypos = 8 * yoffset;
          yindex = 0;
          if ( v11->MCU_height > 0 )
          {
            MCU_width = v11->MCU_width;
            do
            {
              if ( coef->iMCU_row_num < last_iMCU_row || yoffset + yindex < v11->last_row_height )
              {
                cinfo->fdct->forward_DCT(
                  a1: cinfo,
                  a2: v11,
                  a3: input_buf[v11->component_index],
                  a4: coef->MCU_buffer[v9],
                  a5: ypos,
                  a6: xpos,
                  a7: last_col_width);
                v16 = v11->MCU_width;
                if ( last_col_width < v16 )
                {
                  jzero_far(
                    target: (unsigned __int8 *)coef->MCU_buffer[last_col_width + 2 * v9],
                    bytestozero: (v16 - last_col_width) << 7);
                  bi = last_col_width;
                  if ( last_col_width < v11->MCU_width )
                  {
                    v17 = &coef->MCU_buffer[last_col_width + 2 * v9];
                    do
                    {
                      *(_WORD *)*v17 = *(_WORD *)*(v17 - 1);
                      ++v17;
                      ++bi;
                    }
                    while ( bi < v11->MCU_width );
                  }
                }
              }
              else
              {
                jzero_far(target: (unsigned __int8 *)coef->MCU_buffer[v9], bytestozero: MCU_width << 7);
                v14 = 0;
                if ( v11->MCU_width > 0 )
                {
                  v15 = &coef->MCU_buffer[v9];
                  do
                  {
                    ++v14;
                    *(_WORD *)*v15++ = **((_WORD **)&coef->MCU_rows_per_iMCU_row + v9);
                  }
                  while ( v14 < v11->MCU_width );
                  last_col_width = blockcnt;
                }
              }
              MCU_width = v11->MCU_width;
              ypos += 8;
              v9 += MCU_width;
              ++yindex;
            }
            while ( yindex < v11->MCU_height );
          }
          v8 = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))MCU_col_num;
          cur_comp_info = v23 + 1;
          ++ci;
          ++v23;
        }
        while ( ci < cinfo->comps_in_scan );
        p_pub = &coef->pub;
        v2 = cinfo;
      }
      v18 = v2->entropy->encode_mcu(a1: v2, a2: (__int16 (**)[64])&p_pub[3]) == 0;
      p_pub = &coef->pub;
      if ( v18 )
        break;
      v8 = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))((char *)v8 + 1);
      MCU_col_num = (unsigned int)v8;
      if ( (unsigned int)v8 > last_MCU_col )
      {
        start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))yoffset;
        goto LABEL_29;
      }
    }
    coef->mcu_ctr = (unsigned int)v8;
    coef->MCU_vert_offset = yoffset;
    return 0;
  }
  else
  {
LABEL_2:
    ++p_pub[1].start_pass;
    v6 = v2->coef;
    if ( v2->comps_in_scan <= 1 )
    {
      v19 = v2->cur_comp_info[0];
      if ( (char *)v6[1].start_pass >= (char *)(v2->total_iMCU_rows - 1) )
        last_row_height = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))v19->last_row_height;
      else
        last_row_height = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))v19->v_samp_factor;
      v6[2].compress_data = last_row_height;
      v6[1].compress_data = nullptr;
      v6[2].start_pass = nullptr;
      return 1;
    }
    else
    {
      v6[2].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))1;
      v6[1].compress_data = nullptr;
      v6[2].start_pass = nullptr;
      return 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407CF0
// Name: compress_output
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl compress_output(jpeg_compress_struct *cinfo)
{
  jpeg_compress_struct *v1; // esi
  my_coef_controller *v2; // edx
  int v3; // edi
  jpeg_component_info **cur_comp_info; // ebx
  jpeg_memory_mgr *mem; // eax
  __int16 (**v6)[64]; // eax
  int MCU_vert_offset; // eax
  unsigned int mcu_ctr; // edi
  int v9; // ebx
  jpeg_component_info *v10; // edi
  int MCU_width; // ecx
  bool v12; // cc
  __int16 *v13; // eax
  int v14; // edx
  __int16 (**v15)[64]; // esi
  my_coef_controller *v16; // eax
  int v17; // ecx
  jpeg_c_coef_controller *v19; // eax
  jpeg_component_info *v20; // ecx
  unsigned __int8 (__cdecl *last_row_height)(jpeg_compress_struct *, unsigned __int8 ***); // edx
  __int16 (**buffer[4])[64]; // [esp+Ch] [ebp-30h]
  unsigned int v23; // [esp+1Ch] [ebp-20h]
  int yindex; // [esp+20h] [ebp-1Ch]
  unsigned int MCU_col_num; // [esp+24h] [ebp-18h]
  jpeg_component_info **v26; // [esp+28h] [ebp-14h]
  int ci; // [esp+2Ch] [ebp-10h]
  __int16 (**v28)[64]; // [esp+30h] [ebp-Ch]
  int yoffset; // [esp+34h] [ebp-8h]
  my_coef_controller *coef; // [esp+38h] [ebp-4h]

  v1 = cinfo;
  v2 = (my_coef_controller *)cinfo->coef;
  v3 = 0;
  coef = v2;
  if ( cinfo->comps_in_scan > 0 )
  {
    cur_comp_info = cinfo->cur_comp_info;
    do
    {
      mem = v1->mem;
      v1 = cinfo;
      v6 = mem->access_virt_barray(
             a1: (jpeg_common_struct *)cinfo,
             a2: coef->whole_image[(*cur_comp_info)->component_index],
             a3: (*cur_comp_info)->v_samp_factor * v2->iMCU_row_num,
             a4: (*cur_comp_info)->v_samp_factor,
             a5: 0);
      v2 = coef;
      buffer[v3++] = v6;
      ++cur_comp_info;
    }
    while ( v3 < cinfo->comps_in_scan );
  }
  MCU_vert_offset = v2->MCU_vert_offset;
  yoffset = MCU_vert_offset;
  if ( MCU_vert_offset >= v2->MCU_rows_per_iMCU_row )
  {
LABEL_23:
    ++v2->iMCU_row_num;
    v19 = v1->coef;
    if ( v1->comps_in_scan <= 1 )
    {
      v20 = v1->cur_comp_info[0];
      if ( (char *)v19[1].start_pass >= (char *)(v1->total_iMCU_rows - 1) )
        last_row_height = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))v20->last_row_height;
      else
        last_row_height = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))v20->v_samp_factor;
      v19[1].compress_data = nullptr;
      v19[2].start_pass = nullptr;
      v19[2].compress_data = last_row_height;
      return 1;
    }
    else
    {
      v19[1].compress_data = nullptr;
      v19[2].start_pass = nullptr;
      v19[2].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))1;
      return 1;
    }
  }
  else
  {
    while ( 1 )
    {
      mcu_ctr = v2->mcu_ctr;
      MCU_col_num = mcu_ctr;
      if ( mcu_ctr < v1->MCUs_per_row )
        break;
LABEL_20:
      ++MCU_vert_offset;
      v2->mcu_ctr = 0;
      yoffset = MCU_vert_offset;
      if ( MCU_vert_offset >= v2->MCU_rows_per_iMCU_row )
        goto LABEL_23;
    }
    while ( 1 )
    {
      v9 = 0;
      ci = 0;
      if ( v1->comps_in_scan > 0 )
      {
        v26 = v1->cur_comp_info;
        do
        {
          v10 = *v26;
          MCU_width = (*v26)->MCU_width;
          v12 = (*v26)->MCU_height <= 0;
          yindex = 0;
          if ( !v12 )
          {
            v23 = (MCU_col_num * MCU_width) << 7;
            v28 = &buffer[ci][yoffset];
            do
            {
              v13 = (__int16 *)((char *)*v28 + v23);
              v14 = 0;
              if ( MCU_width > 0 )
              {
                v15 = &coef->MCU_buffer[v9];
                do
                {
                  *v15 = (__int16 (*)[64])v13;
                  MCU_width = v10->MCU_width;
                  ++v14;
                  ++v9;
                  ++v15;
                  v13 += 64;
                }
                while ( v14 < MCU_width );
                v1 = cinfo;
              }
              ++v28;
              ++yindex;
            }
            while ( yindex < v10->MCU_height );
          }
          ++v26;
          ++ci;
        }
        while ( ci < v1->comps_in_scan );
        mcu_ctr = MCU_col_num;
        v2 = coef;
      }
      if ( v1->entropy->encode_mcu(a1: v1, a2: v2->MCU_buffer) == 0 )
        break;
      v2 = coef;
      MCU_col_num = ++mcu_ctr;
      if ( mcu_ctr >= v1->MCUs_per_row )
      {
        MCU_vert_offset = yoffset;
        goto LABEL_20;
      }
    }
    v16 = coef;
    v17 = yoffset;
    coef->mcu_ctr = mcu_ctr;
    v16->MCU_vert_offset = v17;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407ED0
// Name: compress_first_pass
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl compress_first_pass(jpeg_compress_struct *cinfo, unsigned __int8 ***input_buf)
{
  jpeg_compress_struct *v2; // eax
  jpeg_component_info *comp_info; // esi
  jpeg_c_coef_controller *p_pub; // edi
  int v5; // ecx
  unsigned int width_in_blocks; // ebx
  int v7; // edx
  int v8; // edi
  int v9; // eax
  __int16 *v10; // esi
  unsigned __int8 *v11; // esi
  __int16 v12; // cx
  int i; // eax
  unsigned int v14; // ebx
  int v15; // edi
  unsigned __int8 *v16; // esi
  int v17; // edi
  int v18; // eax
  __int16 v19; // dx
  unsigned __int8 *v20; // eax
  int j; // ecx
  bool v22; // cc
  int v24; // [esp+8h] [ebp-34h]
  int ci; // [esp+10h] [ebp-2Ch]
  my_coef_controller *coef; // [esp+18h] [ebp-24h]
  unsigned int last_iMCU_row; // [esp+1Ch] [ebp-20h]
  jpeg_c_coef_controller *v29; // [esp+24h] [ebp-18h]
  int h_samp_factor; // [esp+28h] [ebp-14h]
  __int16 (**buffer)[64]; // [esp+2Ch] [ebp-10h]
  jpeg_component_info *compptr; // [esp+30h] [ebp-Ch]
  int lastblockrow; // [esp+34h] [ebp-8h]
  __int16 *lastblockrowa; // [esp+34h] [ebp-8h]
  int lastblockrowb; // [esp+34h] [ebp-8h]
  int block_row; // [esp+38h] [ebp-4h]
  int block_rowa; // [esp+38h] [ebp-4h]

  v2 = cinfo;
  comp_info = cinfo->comp_info;
  p_pub = cinfo->coef;
  coef = (my_coef_controller *)p_pub;
  last_iMCU_row = cinfo->total_iMCU_rows - 1;
  ci = 0;
  compptr = comp_info;
  if ( cinfo->num_components > 0 )
  {
    v29 = p_pub + 8;
    while ( 1 )
    {
      v5 = (int)v2->mem->access_virt_barray(
                  a1: (jpeg_common_struct *)v2,
                  a2: (jvirt_barray_control *)v29->start_pass,
                  a3: comp_info->v_samp_factor * (int)p_pub[1].start_pass,
                  a4: comp_info->v_samp_factor,
                  a5: 1u);
      buffer = (__int16 (**)[64])v5;
      if ( (char *)p_pub[1].start_pass >= (char *)last_iMCU_row )
      {
        lastblockrow = comp_info->height_in_blocks % comp_info->v_samp_factor;
        if ( lastblockrow == 0 )
          lastblockrow = comp_info->v_samp_factor;
      }
      else
      {
        lastblockrow = comp_info->v_samp_factor;
      }
      width_in_blocks = comp_info->width_in_blocks;
      v7 = width_in_blocks % comp_info->h_samp_factor;
      h_samp_factor = comp_info->h_samp_factor;
      v8 = v7;
      if ( v7 > 0 )
        v8 = h_samp_factor - v7;
      v9 = 0;
      block_row = 0;
      if ( lastblockrow > 0 )
      {
        while ( 1 )
        {
          v10 = *(__int16 **)(v5 + 4 * v9);
          cinfo->fdct->forward_DCT(
            a1: cinfo,
            a2: compptr,
            a3: *input_buf,
            a4: (__int16 (*)[64])v10,
            a5: 8 * v9,
            a6: 0,
            a7: width_in_blocks);
          if ( v8 > 0 )
          {
            v11 = (unsigned __int8 *)&v10[64 * width_in_blocks];
            jzero_far(target: v11, bytestozero: v8 << 7);
            v12 = *((_WORD *)v11 - 64);
            for ( i = v8; i != 0; --i )
            {
              *(_WORD *)v11 = v12;
              v11 += 128;
            }
          }
          v5 = (int)buffer;
          if ( ++block_row >= lastblockrow )
            break;
          v9 = block_row;
        }
        comp_info = compptr;
      }
      if ( coef->iMCU_row_num == last_iMCU_row )
      {
        v14 = v8 + width_in_blocks;
        v15 = lastblockrow;
        block_rowa = lastblockrow;
        if ( lastblockrow < comp_info->v_samp_factor )
        {
          while ( 1 )
          {
            v16 = *(unsigned __int8 **)(v5 + 4 * v15);
            lastblockrowa = *(__int16 **)(v5 + 4 * v15 - 4);
            jzero_far(target: v16, bytestozero: v14 << 7);
            if ( v14 / h_samp_factor != 0 )
            {
              v17 = h_samp_factor << 7;
              v18 = (char *)lastblockrowa - (char *)v16;
              v24 = (char *)lastblockrowa - (char *)v16;
              lastblockrowb = v14 / h_samp_factor;
              do
              {
                v19 = *(_WORD *)&v16[v18 - 128 + v17];
                if ( h_samp_factor > 0 )
                {
                  v20 = v16;
                  for ( j = h_samp_factor; j != 0; --j )
                  {
                    *(_WORD *)v20 = v19;
                    v20 += 128;
                  }
                  v18 = v24;
                }
                v16 += v17;
                --lastblockrowb;
              }
              while ( lastblockrowb != 0 );
              v15 = block_rowa;
            }
            block_rowa = ++v15;
            if ( v15 >= compptr->v_samp_factor )
              break;
            v5 = (int)buffer;
          }
          comp_info = compptr;
        }
      }
      v29 = (jpeg_c_coef_controller *)((char *)v29 + 4);
      ++input_buf;
      ++comp_info;
      v22 = ++ci < cinfo->num_components;
      compptr = comp_info;
      v2 = cinfo;
      if ( !v22 )
        break;
      p_pub = &coef->pub;
    }
  }
  return compress_output(cinfo: v2);
}

//------------------------------------------------------------------------------
// Address: 0x004080D0
// Name: start_pass_coef
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_coef(jpeg_common_struct *cinfo, J_BUF_MODE pass_mode)
{
  jpeg_c_coef_controller *v2; // esi
  jpeg_c_coef_controller *v3; // ecx
  jpeg_component_info *v4; // ebx
  unsigned __int8 (__cdecl *last_row_height)(jpeg_compress_struct *, unsigned __int8 ***); // ebx

  v2 = *(jpeg_c_coef_controller **)&cinfo[13].is_decompressor;
  v2[1].start_pass = nullptr;
  v3 = *(jpeg_c_coef_controller **)&cinfo[13].is_decompressor;
  if ( (int)cinfo[9].client_data <= 1 )
  {
    v4 = *(jpeg_component_info **)&cinfo[9].is_decompressor;
    if ( (char *)v3[1].start_pass >= (char *)((char *)&cinfo[9].progress[-1].total_passes + 3) )
      last_row_height = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))v4->last_row_height;
    else
      last_row_height = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))v4->v_samp_factor;
    v3[2].compress_data = last_row_height;
  }
  else
  {
    v3[2].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))1;
  }
  v3[1].compress_data = nullptr;
  v3[2].start_pass = nullptr;
  if ( pass_mode != JBUF_PASS_THRU )
  {
    if ( pass_mode == JBUF_CRANK_DEST )
    {
      if ( v2[8].start_pass == nullptr )
      {
        cinfo->err->msg_code = 4;
        cinfo->err->error_exit(a1: cinfo);
      }
      v2->compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))compress_output;
    }
    else if ( pass_mode == JBUF_SAVE_AND_PASS )
    {
      if ( v2[8].start_pass == nullptr )
      {
        cinfo->err->msg_code = 4;
        cinfo->err->error_exit(a1: cinfo);
      }
      v2->compress_data = compress_first_pass;
    }
    else
    {
      cinfo->err->msg_code = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
  }
  else
  {
    if ( v2[8].start_pass != nullptr )
    {
      cinfo->err->msg_code = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
    v2->compress_data = compress_data;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004081C0
// Name: _jinit_c_coef_controller
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_c_coef_controller(jpeg_common_struct *cinfo, unsigned __int8 need_full_buffer)
{
  jpeg_c_coef_controller *v3; // ebx
  int *v4; // esi
  jpeg_memory_mgr *mem; // ebx
  int v6; // eax
  char *v7; // eax
  int v8; // [esp-Ch] [ebp-14h]
  jpeg_compress_struct *cinfoa; // [esp+10h] [ebp+8h]
  int ci; // [esp+14h] [ebp+Ch]

  v3 = (jpeg_c_coef_controller *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 104);
  *(_DWORD *)&cinfo[13].is_decompressor = v3;
  v3->start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))start_pass_coef;
  if ( need_full_buffer != 0 )
  {
    ci = 0;
    if ( (int)cinfo[2].client_data > 0 )
    {
      v4 = (int *)(cinfo[2].global_state + 12);
      cinfoa = (jpeg_compress_struct *)&v3[8];
      do
      {
        mem = cinfo->mem;
        v8 = jround_up(a: v4[5], b: *v4);
        v6 = jround_up(a: v4[4], b: *(v4 - 1));
        cinfoa->err = (jpeg_error_mgr *)((int (__cdecl *)(jpeg_common_struct *, int, _DWORD, int, int))mem->request_virt_barray)(
                                          a1: cinfo,
                                          a2: 1,
                                          a3: 0,
                                          a4: v6,
                                          a5: v8);
        v4 += 21;
        ++ci;
        cinfoa = (jpeg_compress_struct *)((char *)cinfoa + 4);
      }
      while ( ci < (int)cinfo[2].client_data );
    }
  }
  else
  {
    v7 = (char *)cinfo->mem->alloc_large(a1: cinfo, a2: 1, a3: 1280);
    v3[3].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))(v7 + 128);
    v3[4].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))(v7 + 256);
    v3[4].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))(v7 + 384);
    v3[5].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))(v7 + 512);
    v3[5].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))(v7 + 640);
    v3[6].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))(v7 + 768);
    v3[3].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))v7;
    v3[6].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))(v7 + 896);
    v3[7].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))(v7 + 1024);
    v3[7].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))(v7 + 1152);
    v3[8].start_pass = nullptr;
  }
}

} // namespace statsmap

// ============================================================
// Overlay from VXConsole (Missing functions)
// ============================================================
namespace VXConsole {

//------------------------------------------------------------------------------
// Address: 0x00430D70
// Name: compress_data
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl compress_data(jpeg_compress_struct *cinfo, unsigned __int8 ***input_buf)
{
  jpeg_compress_struct *v2; // esi
  jpeg_c_coef_controller *p_pub; // eax
  void (__cdecl *start_pass)(jpeg_compress_struct *, J_BUF_MODE); // ecx
  unsigned int v5; // edx
  jpeg_c_coef_controller *v6; // eax
  unsigned __int8 (__cdecl *v8)(jpeg_compress_struct *, unsigned __int8 ***); // ebx
  int v9; // edi
  jpeg_component_info **cur_comp_info; // esi
  jpeg_component_info *v11; // esi
  signed int last_col_width; // ebx
  int MCU_width; // eax
  int v14; // eax
  __int16 (**v15)[64]; // ecx
  signed int v16; // eax
  __int16 (**v17)[64]; // eax
  bool v18; // zf
  jpeg_component_info *v19; // ecx
  unsigned __int8 (__cdecl *last_row_height)(jpeg_compress_struct *, unsigned __int8 ***); // edx
  int xpos; // [esp+Ch] [ebp-30h]
  unsigned int last_iMCU_row; // [esp+10h] [ebp-2Ch]
  jpeg_component_info **v23; // [esp+14h] [ebp-28h]
  int ci; // [esp+18h] [ebp-24h]
  int bi; // [esp+1Ch] [ebp-20h]
  int blockcnt; // [esp+20h] [ebp-1Ch]
  unsigned int last_MCU_col; // [esp+24h] [ebp-18h]
  int yindex; // [esp+28h] [ebp-14h]
  int ypos; // [esp+2Ch] [ebp-10h]
  unsigned int MCU_col_num; // [esp+30h] [ebp-Ch]
  int yoffset; // [esp+34h] [ebp-8h]
  my_coef_controller *coef; // [esp+38h] [ebp-4h]

  v2 = cinfo;
  p_pub = cinfo->coef;
  last_iMCU_row = cinfo->total_iMCU_rows - 1;
  start_pass = p_pub[2].start_pass;
  v5 = cinfo->MCUs_per_row - 1;
  coef = (my_coef_controller *)p_pub;
  last_MCU_col = v5;
  yoffset = (int)start_pass;
  if ( (int)start_pass < (int)p_pub[2].compress_data )
  {
    while ( 1 )
    {
      v8 = p_pub[1].compress_data;
      MCU_col_num = (unsigned int)v8;
      if ( (unsigned int)v8 <= v5 )
        break;
LABEL_29:
      start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))((char *)start_pass + 1);
      p_pub[1].compress_data = nullptr;
      yoffset = (int)start_pass;
      if ( (int)start_pass >= (int)p_pub[2].compress_data )
        goto LABEL_2;
      v5 = last_MCU_col;
    }
    while ( 1 )
    {
      v9 = 0;
      ci = 0;
      if ( v2->comps_in_scan > 0 )
      {
        cur_comp_info = v2->cur_comp_info;
        v23 = cur_comp_info;
        do
        {
          v11 = *cur_comp_info;
          if ( (unsigned int)v8 >= last_MCU_col )
            last_col_width = v11->last_col_width;
          else
            last_col_width = v11->MCU_width;
          xpos = MCU_col_num * v11->MCU_sample_width;
          blockcnt = last_col_width;
          ypos = 8 * yoffset;
          yindex = 0;
          if ( v11->MCU_height > 0 )
          {
            MCU_width = v11->MCU_width;
            do
            {
              if ( coef->iMCU_row_num < last_iMCU_row || yoffset + yindex < v11->last_row_height )
              {
                cinfo->fdct->forward_DCT(
                  a1: cinfo,
                  a2: v11,
                  a3: input_buf[v11->component_index],
                  a4: coef->MCU_buffer[v9],
                  a5: ypos,
                  a6: xpos,
                  a7: last_col_width);
                v16 = v11->MCU_width;
                if ( last_col_width < v16 )
                {
                  jzero_far(
                    target: (unsigned __int8 *)coef->MCU_buffer[last_col_width + 2 * v9],
                    bytestozero: (v16 - last_col_width) << 7);
                  bi = last_col_width;
                  if ( last_col_width < v11->MCU_width )
                  {
                    v17 = &coef->MCU_buffer[last_col_width + 2 * v9];
                    do
                    {
                      *(_WORD *)*v17 = *(_WORD *)*(v17 - 1);
                      ++v17;
                      ++bi;
                    }
                    while ( bi < v11->MCU_width );
                  }
                }
              }
              else
              {
                jzero_far(target: (unsigned __int8 *)coef->MCU_buffer[v9], bytestozero: MCU_width << 7);
                v14 = 0;
                if ( v11->MCU_width > 0 )
                {
                  v15 = &coef->MCU_buffer[v9];
                  do
                  {
                    ++v14;
                    *(_WORD *)*v15++ = **((_WORD **)&coef->MCU_rows_per_iMCU_row + v9);
                  }
                  while ( v14 < v11->MCU_width );
                  last_col_width = blockcnt;
                }
              }
              MCU_width = v11->MCU_width;
              ypos += 8;
              v9 += MCU_width;
              ++yindex;
            }
            while ( yindex < v11->MCU_height );
          }
          v8 = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))MCU_col_num;
          cur_comp_info = v23 + 1;
          ++ci;
          ++v23;
        }
        while ( ci < cinfo->comps_in_scan );
        p_pub = &coef->pub;
        v2 = cinfo;
      }
      v18 = v2->entropy->encode_mcu(a1: v2, a2: (__int16 (**)[64])&p_pub[3]) == 0;
      p_pub = &coef->pub;
      if ( v18 )
        break;
      v8 = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))((char *)v8 + 1);
      MCU_col_num = (unsigned int)v8;
      if ( (unsigned int)v8 > last_MCU_col )
      {
        start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))yoffset;
        goto LABEL_29;
      }
    }
    coef->mcu_ctr = (unsigned int)v8;
    coef->MCU_vert_offset = yoffset;
    return 0;
  }
  else
  {
LABEL_2:
    ++p_pub[1].start_pass;
    v6 = v2->coef;
    if ( v2->comps_in_scan <= 1 )
    {
      v19 = v2->cur_comp_info[0];
      if ( (char *)v6[1].start_pass >= (char *)(v2->total_iMCU_rows - 1) )
        last_row_height = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))v19->last_row_height;
      else
        last_row_height = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))v19->v_samp_factor;
      v6[2].compress_data = last_row_height;
      v6[1].compress_data = nullptr;
      v6[2].start_pass = nullptr;
      return 1;
    }
    else
    {
      v6[2].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))1;
      v6[1].compress_data = nullptr;
      v6[2].start_pass = nullptr;
      return 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00431000
// Name: compress_output
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl compress_output(jpeg_compress_struct *cinfo)
{
  jpeg_compress_struct *v1; // esi
  my_coef_controller *v2; // edx
  int v3; // edi
  jpeg_component_info **cur_comp_info; // ebx
  jpeg_memory_mgr *mem; // eax
  __int16 (**v6)[64]; // eax
  int MCU_vert_offset; // eax
  unsigned int mcu_ctr; // edi
  int v9; // ebx
  jpeg_component_info *v10; // edi
  int MCU_width; // ecx
  bool v12; // cc
  __int16 *v13; // eax
  int v14; // edx
  __int16 (**v15)[64]; // esi
  my_coef_controller *v16; // eax
  int v17; // ecx
  jpeg_c_coef_controller *v19; // eax
  jpeg_component_info *v20; // ecx
  unsigned __int8 (__cdecl *last_row_height)(jpeg_compress_struct *, unsigned __int8 ***); // edx
  __int16 (**buffer[4])[64]; // [esp+Ch] [ebp-30h]
  unsigned int v23; // [esp+1Ch] [ebp-20h]
  int yindex; // [esp+20h] [ebp-1Ch]
  unsigned int MCU_col_num; // [esp+24h] [ebp-18h]
  jpeg_component_info **v26; // [esp+28h] [ebp-14h]
  int ci; // [esp+2Ch] [ebp-10h]
  __int16 (**v28)[64]; // [esp+30h] [ebp-Ch]
  int yoffset; // [esp+34h] [ebp-8h]
  my_coef_controller *coef; // [esp+38h] [ebp-4h]

  v1 = cinfo;
  v2 = (my_coef_controller *)cinfo->coef;
  v3 = 0;
  coef = v2;
  if ( cinfo->comps_in_scan > 0 )
  {
    cur_comp_info = cinfo->cur_comp_info;
    do
    {
      mem = v1->mem;
      v1 = cinfo;
      v6 = mem->access_virt_barray(
             a1: (jpeg_common_struct *)cinfo,
             a2: coef->whole_image[(*cur_comp_info)->component_index],
             a3: (*cur_comp_info)->v_samp_factor * v2->iMCU_row_num,
             a4: (*cur_comp_info)->v_samp_factor,
             a5: 0);
      v2 = coef;
      buffer[v3++] = v6;
      ++cur_comp_info;
    }
    while ( v3 < cinfo->comps_in_scan );
  }
  MCU_vert_offset = v2->MCU_vert_offset;
  yoffset = MCU_vert_offset;
  if ( MCU_vert_offset >= v2->MCU_rows_per_iMCU_row )
  {
LABEL_23:
    ++v2->iMCU_row_num;
    v19 = v1->coef;
    if ( v1->comps_in_scan <= 1 )
    {
      v20 = v1->cur_comp_info[0];
      if ( (char *)v19[1].start_pass >= (char *)(v1->total_iMCU_rows - 1) )
        last_row_height = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))v20->last_row_height;
      else
        last_row_height = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))v20->v_samp_factor;
      v19[1].compress_data = nullptr;
      v19[2].start_pass = nullptr;
      v19[2].compress_data = last_row_height;
      return 1;
    }
    else
    {
      v19[1].compress_data = nullptr;
      v19[2].start_pass = nullptr;
      v19[2].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))1;
      return 1;
    }
  }
  else
  {
    while ( 1 )
    {
      mcu_ctr = v2->mcu_ctr;
      MCU_col_num = mcu_ctr;
      if ( mcu_ctr < v1->MCUs_per_row )
        break;
LABEL_20:
      ++MCU_vert_offset;
      v2->mcu_ctr = 0;
      yoffset = MCU_vert_offset;
      if ( MCU_vert_offset >= v2->MCU_rows_per_iMCU_row )
        goto LABEL_23;
    }
    while ( 1 )
    {
      v9 = 0;
      ci = 0;
      if ( v1->comps_in_scan > 0 )
      {
        v26 = v1->cur_comp_info;
        do
        {
          v10 = *v26;
          MCU_width = (*v26)->MCU_width;
          v12 = (*v26)->MCU_height <= 0;
          yindex = 0;
          if ( !v12 )
          {
            v23 = (MCU_col_num * MCU_width) << 7;
            v28 = &buffer[ci][yoffset];
            do
            {
              v13 = (__int16 *)((char *)*v28 + v23);
              v14 = 0;
              if ( MCU_width > 0 )
              {
                v15 = &coef->MCU_buffer[v9];
                do
                {
                  *v15 = (__int16 (*)[64])v13;
                  MCU_width = v10->MCU_width;
                  ++v14;
                  ++v9;
                  ++v15;
                  v13 += 64;
                }
                while ( v14 < MCU_width );
                v1 = cinfo;
              }
              ++v28;
              ++yindex;
            }
            while ( yindex < v10->MCU_height );
          }
          ++v26;
          ++ci;
        }
        while ( ci < v1->comps_in_scan );
        mcu_ctr = MCU_col_num;
        v2 = coef;
      }
      if ( v1->entropy->encode_mcu(a1: v1, a2: v2->MCU_buffer) == 0 )
        break;
      v2 = coef;
      MCU_col_num = ++mcu_ctr;
      if ( mcu_ctr >= v1->MCUs_per_row )
      {
        MCU_vert_offset = yoffset;
        goto LABEL_20;
      }
    }
    v16 = coef;
    v17 = yoffset;
    coef->mcu_ctr = mcu_ctr;
    v16->MCU_vert_offset = v17;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004311E0
// Name: compress_first_pass
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl compress_first_pass(jpeg_compress_struct *cinfo, unsigned __int8 ***input_buf)
{
  jpeg_compress_struct *v2; // eax
  jpeg_component_info *comp_info; // esi
  jpeg_c_coef_controller *p_pub; // edi
  int v5; // ecx
  unsigned int width_in_blocks; // ebx
  int v7; // edx
  int v8; // edi
  int v9; // eax
  __int16 *v10; // esi
  unsigned __int8 *v11; // esi
  __int16 v12; // cx
  int i; // eax
  unsigned int v14; // ebx
  int v15; // edi
  unsigned __int8 *v16; // esi
  int v17; // edi
  int v18; // eax
  __int16 v19; // dx
  unsigned __int8 *v20; // eax
  int j; // ecx
  bool v22; // cc
  int v24; // [esp+8h] [ebp-34h]
  int ci; // [esp+10h] [ebp-2Ch]
  my_coef_controller *coef; // [esp+18h] [ebp-24h]
  unsigned int last_iMCU_row; // [esp+1Ch] [ebp-20h]
  jpeg_c_coef_controller *v29; // [esp+24h] [ebp-18h]
  int h_samp_factor; // [esp+28h] [ebp-14h]
  __int16 (**buffer)[64]; // [esp+2Ch] [ebp-10h]
  jpeg_component_info *compptr; // [esp+30h] [ebp-Ch]
  int lastblockrow; // [esp+34h] [ebp-8h]
  __int16 *lastblockrowa; // [esp+34h] [ebp-8h]
  int lastblockrowb; // [esp+34h] [ebp-8h]
  int block_row; // [esp+38h] [ebp-4h]
  int block_rowa; // [esp+38h] [ebp-4h]

  v2 = cinfo;
  comp_info = cinfo->comp_info;
  p_pub = cinfo->coef;
  coef = (my_coef_controller *)p_pub;
  last_iMCU_row = cinfo->total_iMCU_rows - 1;
  ci = 0;
  compptr = comp_info;
  if ( cinfo->num_components > 0 )
  {
    v29 = p_pub + 8;
    while ( 1 )
    {
      v5 = (int)v2->mem->access_virt_barray(
                  a1: (jpeg_common_struct *)v2,
                  a2: (jvirt_barray_control *)v29->start_pass,
                  a3: comp_info->v_samp_factor * (int)p_pub[1].start_pass,
                  a4: comp_info->v_samp_factor,
                  a5: 1u);
      buffer = (__int16 (**)[64])v5;
      if ( (char *)p_pub[1].start_pass >= (char *)last_iMCU_row )
      {
        lastblockrow = comp_info->height_in_blocks % comp_info->v_samp_factor;
        if ( lastblockrow == 0 )
          lastblockrow = comp_info->v_samp_factor;
      }
      else
      {
        lastblockrow = comp_info->v_samp_factor;
      }
      width_in_blocks = comp_info->width_in_blocks;
      v7 = width_in_blocks % comp_info->h_samp_factor;
      h_samp_factor = comp_info->h_samp_factor;
      v8 = v7;
      if ( v7 > 0 )
        v8 = h_samp_factor - v7;
      v9 = 0;
      block_row = 0;
      if ( lastblockrow > 0 )
      {
        while ( 1 )
        {
          v10 = *(__int16 **)(v5 + 4 * v9);
          cinfo->fdct->forward_DCT(
            a1: cinfo,
            a2: compptr,
            a3: *input_buf,
            a4: (__int16 (*)[64])v10,
            a5: 8 * v9,
            a6: 0,
            a7: width_in_blocks);
          if ( v8 > 0 )
          {
            v11 = (unsigned __int8 *)&v10[64 * width_in_blocks];
            jzero_far(target: v11, bytestozero: v8 << 7);
            v12 = *((_WORD *)v11 - 64);
            for ( i = v8; i != 0; --i )
            {
              *(_WORD *)v11 = v12;
              v11 += 128;
            }
          }
          v5 = (int)buffer;
          if ( ++block_row >= lastblockrow )
            break;
          v9 = block_row;
        }
        comp_info = compptr;
      }
      if ( coef->iMCU_row_num == last_iMCU_row )
      {
        v14 = v8 + width_in_blocks;
        v15 = lastblockrow;
        block_rowa = lastblockrow;
        if ( lastblockrow < comp_info->v_samp_factor )
        {
          while ( 1 )
          {
            v16 = *(unsigned __int8 **)(v5 + 4 * v15);
            lastblockrowa = *(__int16 **)(v5 + 4 * v15 - 4);
            jzero_far(target: v16, bytestozero: v14 << 7);
            if ( v14 / h_samp_factor != 0 )
            {
              v17 = h_samp_factor << 7;
              v18 = (char *)lastblockrowa - (char *)v16;
              v24 = (char *)lastblockrowa - (char *)v16;
              lastblockrowb = v14 / h_samp_factor;
              do
              {
                v19 = *(_WORD *)&v16[v18 - 128 + v17];
                if ( h_samp_factor > 0 )
                {
                  v20 = v16;
                  for ( j = h_samp_factor; j != 0; --j )
                  {
                    *(_WORD *)v20 = v19;
                    v20 += 128;
                  }
                  v18 = v24;
                }
                v16 += v17;
                --lastblockrowb;
              }
              while ( lastblockrowb != 0 );
              v15 = block_rowa;
            }
            block_rowa = ++v15;
            if ( v15 >= compptr->v_samp_factor )
              break;
            v5 = (int)buffer;
          }
          comp_info = compptr;
        }
      }
      v29 = (jpeg_c_coef_controller *)((char *)v29 + 4);
      ++input_buf;
      ++comp_info;
      v22 = ++ci < cinfo->num_components;
      compptr = comp_info;
      v2 = cinfo;
      if ( !v22 )
        break;
      p_pub = &coef->pub;
    }
  }
  return compress_output(cinfo: v2);
}

//------------------------------------------------------------------------------
// Address: 0x004313E0
// Name: start_pass_coef
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_coef(jpeg_common_struct *cinfo, J_BUF_MODE pass_mode)
{
  jpeg_c_coef_controller *v2; // esi
  jpeg_c_coef_controller *v3; // ecx
  jpeg_component_info *v4; // ebx
  unsigned __int8 (__cdecl *last_row_height)(jpeg_compress_struct *, unsigned __int8 ***); // ebx

  v2 = *(jpeg_c_coef_controller **)&cinfo[13].is_decompressor;
  v2[1].start_pass = nullptr;
  v3 = *(jpeg_c_coef_controller **)&cinfo[13].is_decompressor;
  if ( (int)cinfo[9].client_data <= 1 )
  {
    v4 = *(jpeg_component_info **)&cinfo[9].is_decompressor;
    if ( (char *)v3[1].start_pass >= (char *)((char *)&cinfo[9].progress[-1].total_passes + 3) )
      last_row_height = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))v4->last_row_height;
    else
      last_row_height = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))v4->v_samp_factor;
    v3[2].compress_data = last_row_height;
  }
  else
  {
    v3[2].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))1;
  }
  v3[1].compress_data = nullptr;
  v3[2].start_pass = nullptr;
  if ( pass_mode != JBUF_PASS_THRU )
  {
    if ( pass_mode == JBUF_CRANK_DEST )
    {
      if ( v2[8].start_pass == nullptr )
      {
        cinfo->err->msg_code = 4;
        cinfo->err->error_exit(a1: cinfo);
      }
      v2->compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))compress_output;
    }
    else if ( pass_mode == JBUF_SAVE_AND_PASS )
    {
      if ( v2[8].start_pass == nullptr )
      {
        cinfo->err->msg_code = 4;
        cinfo->err->error_exit(a1: cinfo);
      }
      v2->compress_data = compress_first_pass;
    }
    else
    {
      cinfo->err->msg_code = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
  }
  else
  {
    if ( v2[8].start_pass != nullptr )
    {
      cinfo->err->msg_code = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
    v2->compress_data = compress_data;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004314D0
// Name: _jinit_c_coef_controller
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_c_coef_controller(jpeg_common_struct *cinfo, unsigned __int8 need_full_buffer)
{
  jpeg_c_coef_controller *v3; // ebx
  int *v4; // esi
  jpeg_memory_mgr *mem; // ebx
  int v6; // eax
  char *v7; // eax
  int v8; // [esp-Ch] [ebp-14h]
  jpeg_compress_struct *cinfoa; // [esp+10h] [ebp+8h]
  int ci; // [esp+14h] [ebp+Ch]

  v3 = (jpeg_c_coef_controller *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 104);
  *(_DWORD *)&cinfo[13].is_decompressor = v3;
  v3->start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))start_pass_coef;
  if ( need_full_buffer != 0 )
  {
    ci = 0;
    if ( (int)cinfo[2].client_data > 0 )
    {
      v4 = (int *)(cinfo[2].global_state + 12);
      cinfoa = (jpeg_compress_struct *)&v3[8];
      do
      {
        mem = cinfo->mem;
        v8 = jround_up(a: v4[5], b: *v4);
        v6 = jround_up(a: v4[4], b: *(v4 - 1));
        cinfoa->err = (jpeg_error_mgr *)((int (__cdecl *)(jpeg_common_struct *, int, _DWORD, int, int))mem->request_virt_barray)(
                                          a1: cinfo,
                                          a2: 1,
                                          a3: 0,
                                          a4: v6,
                                          a5: v8);
        v4 += 21;
        ++ci;
        cinfoa = (jpeg_compress_struct *)((char *)cinfoa + 4);
      }
      while ( ci < (int)cinfo[2].client_data );
    }
  }
  else
  {
    v7 = (char *)cinfo->mem->alloc_large(a1: cinfo, a2: 1, a3: 1280);
    v3[3].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))(v7 + 128);
    v3[4].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))(v7 + 256);
    v3[4].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))(v7 + 384);
    v3[5].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))(v7 + 512);
    v3[5].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))(v7 + 640);
    v3[6].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))(v7 + 768);
    v3[3].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))v7;
    v3[6].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))(v7 + 896);
    v3[7].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))(v7 + 1024);
    v3[7].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))(v7 + 1152);
    v3[8].start_pass = nullptr;
  }
}

} // namespace VXConsole

// ============================================================
// Overlay from vxconsole_ps3 (Missing functions)
// ============================================================
namespace vxconsole_ps3 {

//------------------------------------------------------------------------------
// Address: 0x0041DB70
// Name: compress_data
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl compress_data(jpeg_compress_struct *cinfo, unsigned __int8 ***input_buf)
{
  jpeg_compress_struct *v2; // esi
  jpeg_c_coef_controller *p_pub; // eax
  void (__cdecl *start_pass)(jpeg_compress_struct *, J_BUF_MODE); // ecx
  unsigned int v5; // edx
  jpeg_c_coef_controller *v6; // eax
  unsigned __int8 (__cdecl *v8)(jpeg_compress_struct *, unsigned __int8 ***); // ebx
  int v9; // edi
  jpeg_component_info **cur_comp_info; // esi
  jpeg_component_info *v11; // esi
  signed int last_col_width; // ebx
  int MCU_width; // eax
  int v14; // eax
  __int16 (**v15)[64]; // ecx
  signed int v16; // eax
  __int16 (**v17)[64]; // eax
  bool v18; // zf
  jpeg_component_info *v19; // ecx
  unsigned __int8 (__cdecl *last_row_height)(jpeg_compress_struct *, unsigned __int8 ***); // edx
  int xpos; // [esp+Ch] [ebp-30h]
  unsigned int last_iMCU_row; // [esp+10h] [ebp-2Ch]
  jpeg_component_info **v23; // [esp+14h] [ebp-28h]
  int ci; // [esp+18h] [ebp-24h]
  int bi; // [esp+1Ch] [ebp-20h]
  int blockcnt; // [esp+20h] [ebp-1Ch]
  unsigned int last_MCU_col; // [esp+24h] [ebp-18h]
  int yindex; // [esp+28h] [ebp-14h]
  int ypos; // [esp+2Ch] [ebp-10h]
  unsigned int MCU_col_num; // [esp+30h] [ebp-Ch]
  int yoffset; // [esp+34h] [ebp-8h]
  my_coef_controller *coef; // [esp+38h] [ebp-4h]

  v2 = cinfo;
  p_pub = cinfo->coef;
  last_iMCU_row = cinfo->total_iMCU_rows - 1;
  start_pass = p_pub[2].start_pass;
  v5 = cinfo->MCUs_per_row - 1;
  coef = (my_coef_controller *)p_pub;
  last_MCU_col = v5;
  yoffset = (int)start_pass;
  if ( (int)start_pass < (int)p_pub[2].compress_data )
  {
    while ( 1 )
    {
      v8 = p_pub[1].compress_data;
      MCU_col_num = (unsigned int)v8;
      if ( (unsigned int)v8 <= v5 )
        break;
LABEL_29:
      start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))((char *)start_pass + 1);
      p_pub[1].compress_data = nullptr;
      yoffset = (int)start_pass;
      if ( (int)start_pass >= (int)p_pub[2].compress_data )
        goto LABEL_2;
      v5 = last_MCU_col;
    }
    while ( 1 )
    {
      v9 = 0;
      ci = 0;
      if ( v2->comps_in_scan > 0 )
      {
        cur_comp_info = v2->cur_comp_info;
        v23 = cur_comp_info;
        do
        {
          v11 = *cur_comp_info;
          if ( (unsigned int)v8 >= last_MCU_col )
            last_col_width = v11->last_col_width;
          else
            last_col_width = v11->MCU_width;
          xpos = MCU_col_num * v11->MCU_sample_width;
          blockcnt = last_col_width;
          ypos = 8 * yoffset;
          yindex = 0;
          if ( v11->MCU_height > 0 )
          {
            MCU_width = v11->MCU_width;
            do
            {
              if ( coef->iMCU_row_num < last_iMCU_row || yoffset + yindex < v11->last_row_height )
              {
                cinfo->fdct->forward_DCT(
                  a1: cinfo,
                  a2: v11,
                  a3: input_buf[v11->component_index],
                  a4: coef->MCU_buffer[v9],
                  a5: ypos,
                  a6: xpos,
                  a7: last_col_width);
                v16 = v11->MCU_width;
                if ( last_col_width < v16 )
                {
                  jzero_far(
                    target: (unsigned __int8 *)coef->MCU_buffer[last_col_width + 2 * v9],
                    bytestozero: (v16 - last_col_width) << 7);
                  bi = last_col_width;
                  if ( last_col_width < v11->MCU_width )
                  {
                    v17 = &coef->MCU_buffer[last_col_width + 2 * v9];
                    do
                    {
                      *(_WORD *)*v17 = *(_WORD *)*(v17 - 1);
                      ++v17;
                      ++bi;
                    }
                    while ( bi < v11->MCU_width );
                  }
                }
              }
              else
              {
                jzero_far(target: (unsigned __int8 *)coef->MCU_buffer[v9], bytestozero: MCU_width << 7);
                v14 = 0;
                if ( v11->MCU_width > 0 )
                {
                  v15 = &coef->MCU_buffer[v9];
                  do
                  {
                    ++v14;
                    *(_WORD *)*v15++ = **((_WORD **)&coef->MCU_rows_per_iMCU_row + v9);
                  }
                  while ( v14 < v11->MCU_width );
                  last_col_width = blockcnt;
                }
              }
              MCU_width = v11->MCU_width;
              ypos += 8;
              v9 += MCU_width;
              ++yindex;
            }
            while ( yindex < v11->MCU_height );
          }
          v8 = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))MCU_col_num;
          cur_comp_info = v23 + 1;
          ++ci;
          ++v23;
        }
        while ( ci < cinfo->comps_in_scan );
        p_pub = &coef->pub;
        v2 = cinfo;
      }
      v18 = v2->entropy->encode_mcu(a1: v2, a2: (__int16 (**)[64])&p_pub[3]) == 0;
      p_pub = &coef->pub;
      if ( v18 )
        break;
      v8 = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))((char *)v8 + 1);
      MCU_col_num = (unsigned int)v8;
      if ( (unsigned int)v8 > last_MCU_col )
      {
        start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))yoffset;
        goto LABEL_29;
      }
    }
    coef->mcu_ctr = (unsigned int)v8;
    coef->MCU_vert_offset = yoffset;
    return 0;
  }
  else
  {
LABEL_2:
    ++p_pub[1].start_pass;
    v6 = v2->coef;
    if ( v2->comps_in_scan <= 1 )
    {
      v19 = v2->cur_comp_info[0];
      if ( (char *)v6[1].start_pass >= (char *)(v2->total_iMCU_rows - 1) )
        last_row_height = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))v19->last_row_height;
      else
        last_row_height = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))v19->v_samp_factor;
      v6[2].compress_data = last_row_height;
      v6[1].compress_data = nullptr;
      v6[2].start_pass = nullptr;
      return 1;
    }
    else
    {
      v6[2].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))1;
      v6[1].compress_data = nullptr;
      v6[2].start_pass = nullptr;
      return 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041DE00
// Name: compress_output
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl compress_output(jpeg_compress_struct *cinfo)
{
  jpeg_compress_struct *v1; // esi
  my_coef_controller *v2; // edx
  int v3; // edi
  jpeg_component_info **cur_comp_info; // ebx
  jpeg_memory_mgr *mem; // eax
  __int16 (**v6)[64]; // eax
  int MCU_vert_offset; // eax
  unsigned int mcu_ctr; // edi
  int v9; // ebx
  jpeg_component_info *v10; // edi
  int MCU_width; // ecx
  bool v12; // cc
  __int16 *v13; // eax
  int v14; // edx
  __int16 (**v15)[64]; // esi
  my_coef_controller *v16; // eax
  int v17; // ecx
  jpeg_c_coef_controller *v19; // eax
  jpeg_component_info *v20; // ecx
  unsigned __int8 (__cdecl *last_row_height)(jpeg_compress_struct *, unsigned __int8 ***); // edx
  __int16 (**buffer[4])[64]; // [esp+Ch] [ebp-30h]
  unsigned int v23; // [esp+1Ch] [ebp-20h]
  int yindex; // [esp+20h] [ebp-1Ch]
  unsigned int MCU_col_num; // [esp+24h] [ebp-18h]
  jpeg_component_info **v26; // [esp+28h] [ebp-14h]
  int ci; // [esp+2Ch] [ebp-10h]
  __int16 (**v28)[64]; // [esp+30h] [ebp-Ch]
  int yoffset; // [esp+34h] [ebp-8h]
  my_coef_controller *coef; // [esp+38h] [ebp-4h]

  v1 = cinfo;
  v2 = (my_coef_controller *)cinfo->coef;
  v3 = 0;
  coef = v2;
  if ( cinfo->comps_in_scan > 0 )
  {
    cur_comp_info = cinfo->cur_comp_info;
    do
    {
      mem = v1->mem;
      v1 = cinfo;
      v6 = mem->access_virt_barray(
             a1: (jpeg_common_struct *)cinfo,
             a2: coef->whole_image[(*cur_comp_info)->component_index],
             a3: (*cur_comp_info)->v_samp_factor * v2->iMCU_row_num,
             a4: (*cur_comp_info)->v_samp_factor,
             a5: 0);
      v2 = coef;
      buffer[v3++] = v6;
      ++cur_comp_info;
    }
    while ( v3 < cinfo->comps_in_scan );
  }
  MCU_vert_offset = v2->MCU_vert_offset;
  yoffset = MCU_vert_offset;
  if ( MCU_vert_offset >= v2->MCU_rows_per_iMCU_row )
  {
LABEL_23:
    ++v2->iMCU_row_num;
    v19 = v1->coef;
    if ( v1->comps_in_scan <= 1 )
    {
      v20 = v1->cur_comp_info[0];
      if ( (char *)v19[1].start_pass >= (char *)(v1->total_iMCU_rows - 1) )
        last_row_height = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))v20->last_row_height;
      else
        last_row_height = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))v20->v_samp_factor;
      v19[1].compress_data = nullptr;
      v19[2].start_pass = nullptr;
      v19[2].compress_data = last_row_height;
      return 1;
    }
    else
    {
      v19[1].compress_data = nullptr;
      v19[2].start_pass = nullptr;
      v19[2].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))1;
      return 1;
    }
  }
  else
  {
    while ( 1 )
    {
      mcu_ctr = v2->mcu_ctr;
      MCU_col_num = mcu_ctr;
      if ( mcu_ctr < v1->MCUs_per_row )
        break;
LABEL_20:
      ++MCU_vert_offset;
      v2->mcu_ctr = 0;
      yoffset = MCU_vert_offset;
      if ( MCU_vert_offset >= v2->MCU_rows_per_iMCU_row )
        goto LABEL_23;
    }
    while ( 1 )
    {
      v9 = 0;
      ci = 0;
      if ( v1->comps_in_scan > 0 )
      {
        v26 = v1->cur_comp_info;
        do
        {
          v10 = *v26;
          MCU_width = (*v26)->MCU_width;
          v12 = (*v26)->MCU_height <= 0;
          yindex = 0;
          if ( !v12 )
          {
            v23 = (MCU_col_num * MCU_width) << 7;
            v28 = &buffer[ci][yoffset];
            do
            {
              v13 = (__int16 *)((char *)*v28 + v23);
              v14 = 0;
              if ( MCU_width > 0 )
              {
                v15 = &coef->MCU_buffer[v9];
                do
                {
                  *v15 = (__int16 (*)[64])v13;
                  MCU_width = v10->MCU_width;
                  ++v14;
                  ++v9;
                  ++v15;
                  v13 += 64;
                }
                while ( v14 < MCU_width );
                v1 = cinfo;
              }
              ++v28;
              ++yindex;
            }
            while ( yindex < v10->MCU_height );
          }
          ++v26;
          ++ci;
        }
        while ( ci < v1->comps_in_scan );
        mcu_ctr = MCU_col_num;
        v2 = coef;
      }
      if ( v1->entropy->encode_mcu(a1: v1, a2: v2->MCU_buffer) == 0 )
        break;
      v2 = coef;
      MCU_col_num = ++mcu_ctr;
      if ( mcu_ctr >= v1->MCUs_per_row )
      {
        MCU_vert_offset = yoffset;
        goto LABEL_20;
      }
    }
    v16 = coef;
    v17 = yoffset;
    coef->mcu_ctr = mcu_ctr;
    v16->MCU_vert_offset = v17;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041DFE0
// Name: compress_first_pass
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl compress_first_pass(jpeg_compress_struct *cinfo, unsigned __int8 ***input_buf)
{
  jpeg_compress_struct *v2; // eax
  jpeg_component_info *comp_info; // esi
  jpeg_c_coef_controller *p_pub; // edi
  int v5; // ecx
  unsigned int width_in_blocks; // ebx
  int v7; // edx
  int v8; // edi
  int v9; // eax
  __int16 *v10; // esi
  unsigned __int8 *v11; // esi
  __int16 v12; // cx
  int i; // eax
  unsigned int v14; // ebx
  int v15; // edi
  unsigned __int8 *v16; // esi
  int v17; // edi
  int v18; // eax
  __int16 v19; // dx
  unsigned __int8 *v20; // eax
  int j; // ecx
  bool v22; // cc
  int v24; // [esp+8h] [ebp-34h]
  int ci; // [esp+10h] [ebp-2Ch]
  my_coef_controller *coef; // [esp+18h] [ebp-24h]
  unsigned int last_iMCU_row; // [esp+1Ch] [ebp-20h]
  jpeg_c_coef_controller *v29; // [esp+24h] [ebp-18h]
  int h_samp_factor; // [esp+28h] [ebp-14h]
  __int16 (**buffer)[64]; // [esp+2Ch] [ebp-10h]
  jpeg_component_info *compptr; // [esp+30h] [ebp-Ch]
  int lastblockrow; // [esp+34h] [ebp-8h]
  __int16 *lastblockrowa; // [esp+34h] [ebp-8h]
  int lastblockrowb; // [esp+34h] [ebp-8h]
  int block_row; // [esp+38h] [ebp-4h]
  int block_rowa; // [esp+38h] [ebp-4h]

  v2 = cinfo;
  comp_info = cinfo->comp_info;
  p_pub = cinfo->coef;
  coef = (my_coef_controller *)p_pub;
  last_iMCU_row = cinfo->total_iMCU_rows - 1;
  ci = 0;
  compptr = comp_info;
  if ( cinfo->num_components > 0 )
  {
    v29 = p_pub + 8;
    while ( 1 )
    {
      v5 = (int)v2->mem->access_virt_barray(
                  a1: (jpeg_common_struct *)v2,
                  a2: (jvirt_barray_control *)v29->start_pass,
                  a3: comp_info->v_samp_factor * (int)p_pub[1].start_pass,
                  a4: comp_info->v_samp_factor,
                  a5: 1u);
      buffer = (__int16 (**)[64])v5;
      if ( (char *)p_pub[1].start_pass >= (char *)last_iMCU_row )
      {
        lastblockrow = comp_info->height_in_blocks % comp_info->v_samp_factor;
        if ( lastblockrow == 0 )
          lastblockrow = comp_info->v_samp_factor;
      }
      else
      {
        lastblockrow = comp_info->v_samp_factor;
      }
      width_in_blocks = comp_info->width_in_blocks;
      v7 = width_in_blocks % comp_info->h_samp_factor;
      h_samp_factor = comp_info->h_samp_factor;
      v8 = v7;
      if ( v7 > 0 )
        v8 = h_samp_factor - v7;
      v9 = 0;
      block_row = 0;
      if ( lastblockrow > 0 )
      {
        while ( 1 )
        {
          v10 = *(__int16 **)(v5 + 4 * v9);
          cinfo->fdct->forward_DCT(
            a1: cinfo,
            a2: compptr,
            a3: *input_buf,
            a4: (__int16 (*)[64])v10,
            a5: 8 * v9,
            a6: 0,
            a7: width_in_blocks);
          if ( v8 > 0 )
          {
            v11 = (unsigned __int8 *)&v10[64 * width_in_blocks];
            jzero_far(target: v11, bytestozero: v8 << 7);
            v12 = *((_WORD *)v11 - 64);
            for ( i = v8; i != 0; --i )
            {
              *(_WORD *)v11 = v12;
              v11 += 128;
            }
          }
          v5 = (int)buffer;
          if ( ++block_row >= lastblockrow )
            break;
          v9 = block_row;
        }
        comp_info = compptr;
      }
      if ( coef->iMCU_row_num == last_iMCU_row )
      {
        v14 = v8 + width_in_blocks;
        v15 = lastblockrow;
        block_rowa = lastblockrow;
        if ( lastblockrow < comp_info->v_samp_factor )
        {
          while ( 1 )
          {
            v16 = *(unsigned __int8 **)(v5 + 4 * v15);
            lastblockrowa = *(__int16 **)(v5 + 4 * v15 - 4);
            jzero_far(target: v16, bytestozero: v14 << 7);
            if ( v14 / h_samp_factor != 0 )
            {
              v17 = h_samp_factor << 7;
              v18 = (char *)lastblockrowa - (char *)v16;
              v24 = (char *)lastblockrowa - (char *)v16;
              lastblockrowb = v14 / h_samp_factor;
              do
              {
                v19 = *(_WORD *)&v16[v18 - 128 + v17];
                if ( h_samp_factor > 0 )
                {
                  v20 = v16;
                  for ( j = h_samp_factor; j != 0; --j )
                  {
                    *(_WORD *)v20 = v19;
                    v20 += 128;
                  }
                  v18 = v24;
                }
                v16 += v17;
                --lastblockrowb;
              }
              while ( lastblockrowb != 0 );
              v15 = block_rowa;
            }
            block_rowa = ++v15;
            if ( v15 >= compptr->v_samp_factor )
              break;
            v5 = (int)buffer;
          }
          comp_info = compptr;
        }
      }
      v29 = (jpeg_c_coef_controller *)((char *)v29 + 4);
      ++input_buf;
      ++comp_info;
      v22 = ++ci < cinfo->num_components;
      compptr = comp_info;
      v2 = cinfo;
      if ( !v22 )
        break;
      p_pub = &coef->pub;
    }
  }
  return compress_output(cinfo: v2);
}

//------------------------------------------------------------------------------
// Address: 0x0041E1E0
// Name: start_pass_coef
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_coef(jpeg_common_struct *cinfo, J_BUF_MODE pass_mode)
{
  jpeg_c_coef_controller *v2; // esi
  jpeg_c_coef_controller *v3; // ecx
  jpeg_component_info *v4; // ebx
  unsigned __int8 (__cdecl *last_row_height)(jpeg_compress_struct *, unsigned __int8 ***); // ebx

  v2 = *(jpeg_c_coef_controller **)&cinfo[13].is_decompressor;
  v2[1].start_pass = nullptr;
  v3 = *(jpeg_c_coef_controller **)&cinfo[13].is_decompressor;
  if ( (int)cinfo[9].client_data <= 1 )
  {
    v4 = *(jpeg_component_info **)&cinfo[9].is_decompressor;
    if ( (char *)v3[1].start_pass >= (char *)((char *)&cinfo[9].progress[-1].total_passes + 3) )
      last_row_height = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))v4->last_row_height;
    else
      last_row_height = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))v4->v_samp_factor;
    v3[2].compress_data = last_row_height;
  }
  else
  {
    v3[2].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))1;
  }
  v3[1].compress_data = nullptr;
  v3[2].start_pass = nullptr;
  if ( pass_mode != JBUF_PASS_THRU )
  {
    if ( pass_mode == JBUF_CRANK_DEST )
    {
      if ( v2[8].start_pass == nullptr )
      {
        cinfo->err->msg_code = 4;
        cinfo->err->error_exit(a1: cinfo);
      }
      v2->compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))compress_output;
    }
    else if ( pass_mode == JBUF_SAVE_AND_PASS )
    {
      if ( v2[8].start_pass == nullptr )
      {
        cinfo->err->msg_code = 4;
        cinfo->err->error_exit(a1: cinfo);
      }
      v2->compress_data = compress_first_pass;
    }
    else
    {
      cinfo->err->msg_code = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
  }
  else
  {
    if ( v2[8].start_pass != nullptr )
    {
      cinfo->err->msg_code = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
    v2->compress_data = compress_data;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041E2D0
// Name: _jinit_c_coef_controller
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_c_coef_controller(jpeg_common_struct *cinfo, unsigned __int8 need_full_buffer)
{
  jpeg_c_coef_controller *v3; // ebx
  int *v4; // esi
  jpeg_memory_mgr *mem; // ebx
  int v6; // eax
  char *v7; // eax
  int v8; // [esp-Ch] [ebp-14h]
  jpeg_compress_struct *cinfoa; // [esp+10h] [ebp+8h]
  int ci; // [esp+14h] [ebp+Ch]

  v3 = (jpeg_c_coef_controller *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 104);
  *(_DWORD *)&cinfo[13].is_decompressor = v3;
  v3->start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))start_pass_coef;
  if ( need_full_buffer != 0 )
  {
    ci = 0;
    if ( (int)cinfo[2].client_data > 0 )
    {
      v4 = (int *)(cinfo[2].global_state + 12);
      cinfoa = (jpeg_compress_struct *)&v3[8];
      do
      {
        mem = cinfo->mem;
        v8 = jround_up(a: v4[5], b: *v4);
        v6 = jround_up(a: v4[4], b: *(v4 - 1));
        cinfoa->err = (jpeg_error_mgr *)((int (__cdecl *)(jpeg_common_struct *, int, _DWORD, int, int))mem->request_virt_barray)(
                                          a1: cinfo,
                                          a2: 1,
                                          a3: 0,
                                          a4: v6,
                                          a5: v8);
        v4 += 21;
        ++ci;
        cinfoa = (jpeg_compress_struct *)((char *)cinfoa + 4);
      }
      while ( ci < (int)cinfo[2].client_data );
    }
  }
  else
  {
    v7 = (char *)cinfo->mem->alloc_large(a1: cinfo, a2: 1, a3: 1280);
    v3[3].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))(v7 + 128);
    v3[4].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))(v7 + 256);
    v3[4].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))(v7 + 384);
    v3[5].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))(v7 + 512);
    v3[5].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))(v7 + 640);
    v3[6].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))(v7 + 768);
    v3[3].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))v7;
    v3[6].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))(v7 + 896);
    v3[7].start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))(v7 + 1024);
    v3[7].compress_data = (unsigned __int8 (__cdecl *)(jpeg_compress_struct *, unsigned __int8 ***))(v7 + 1152);
    v3[8].start_pass = nullptr;
  }
}

} // namespace vxconsole_ps3
