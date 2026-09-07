// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jdpostct.c
// Functions: 5
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1000FF80
// Name: post_process_1pass
// Source: json
//------------------------------------------------------------------------------
void __cdecl post_process_1pass(
        unsigned int cinfo,
        unsigned __int8 ***input_buf,
        unsigned int *in_row_group_ctr,
        unsigned int in_row_groups_avail,
        unsigned __int8 **output_buf,
        unsigned int *out_row_ctr,
        unsigned int out_rows_avail)
{
  unsigned int *v7; // ebx
  void (__cdecl *start_pass)(jpeg_decompress_struct *, J_BUF_MODE); // eax
  jpeg_decompress_struct *v9; // esi
  jpeg_d_post_controller *v10; // edi
  jpeg_upsampler *v11; // ecx

  v7 = out_row_ctr;
  start_pass = (void (__cdecl *)(jpeg_decompress_struct *, J_BUF_MODE))(out_rows_avail - *out_row_ctr);
  v9 = (jpeg_decompress_struct *)cinfo;
  v10 = *(jpeg_d_post_controller **)(cinfo + 396);
  if ( (char *)start_pass > (char *)v10[2].start_pass )
    start_pass = v10[2].start_pass;
  v11 = *(jpeg_upsampler **)(cinfo + 416);
  cinfo = 0;
  v11->upsample(
    a1: v9,
    a2: input_buf,
    a3: in_row_group_ctr,
    a4: in_row_groups_avail,
    a5: (unsigned __int8 **)v10[1].post_process_data,
    a6: &cinfo,
    a7: (unsigned int)start_pass);
  v9->cquantize->color_quantize(
    a1: v9,
    a2: (unsigned __int8 **)v10[1].post_process_data,
    a3: &output_buf[*v7],
    a4: cinfo);
  *v7 += cinfo;
}

//------------------------------------------------------------------------------
// Address: 0x10010000
// Name: post_process_prepass
// Source: json
//------------------------------------------------------------------------------
void __cdecl post_process_prepass(
        jpeg_common_struct *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int *in_row_group_ctr,
        unsigned int in_row_groups_avail,
        unsigned __int8 **output_buf,
        unsigned int *out_row_ctr)
{
  jpeg_d_post_controller *client_data; // esi
  jpeg_d_post_controller *v8; // ebx
  unsigned int v9; // ecx
  void (__cdecl *start_pass)(jpeg_decompress_struct *, J_BUF_MODE); // eax
  unsigned int old_next_row; // [esp+14h] [ebp+8h]
  unsigned int old_next_rowa; // [esp+14h] [ebp+8h]

  client_data = (jpeg_d_post_controller *)cinfo[16].client_data;
  v8 = client_data + 3;
  if ( client_data[3].start_pass == nullptr )
    client_data[1].post_process_data = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))cinfo->mem->access_virt_sarray(a1: cinfo, a2: client_data[1].start_pass, a3: client_data[2].post_process_data, a4: client_data[2].start_pass, a5: 1);
  old_next_row = (unsigned int)v8->start_pass;
  ((void (__cdecl *)(jpeg_common_struct *, unsigned __int8 ***, unsigned int *, unsigned int, _DWORD, jpeg_d_post_controller *, void (__cdecl *)(jpeg_decompress_struct *, J_BUF_MODE)))cinfo[17].progress->pass_counter)(
    a1: cinfo,
    a2: input_buf,
    a3: in_row_group_ctr,
    a4: in_row_groups_avail,
    a5: client_data[1].post_process_data,
    a6: &client_data[3],
    a7: client_data[2].start_pass);
  v9 = old_next_row;
  if ( (char *)v8->start_pass > (char *)old_next_row )
  {
    old_next_rowa = (unsigned int)v8->start_pass - old_next_row;
    (*(void (__cdecl **)(jpeg_common_struct *, char *, _DWORD, unsigned int))(*(_DWORD *)&cinfo[17].is_decompressor + 4))(
      a1: cinfo,
      a2: (char *)client_data[1].post_process_data + 4 * v9,
      a3: 0,
      a4: old_next_rowa);
    *out_row_ctr += old_next_rowa;
  }
  start_pass = client_data[2].start_pass;
  if ( (char *)v8->start_pass >= (char *)start_pass )
  {
    client_data[2].post_process_data = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))((char *)client_data[2].post_process_data + (unsigned int)start_pass);
    v8->start_pass = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100100B0
// Name: post_process_2pass
// Source: json
//------------------------------------------------------------------------------
void __cdecl post_process_2pass(
        jpeg_common_struct *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int *in_row_group_ctr,
        unsigned int in_row_groups_avail,
        unsigned __int8 **output_buf,
        unsigned int *out_row_ctr,
        unsigned int out_rows_avail)
{
  jpeg_d_post_controller *client_data; // esi
  unsigned int v8; // edi
  void (__cdecl *start_pass)(jpeg_decompress_struct *, J_BUF_MODE); // eax

  client_data = (jpeg_d_post_controller *)cinfo[16].client_data;
  if ( client_data[3].start_pass == nullptr )
    client_data[1].post_process_data = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))cinfo->mem->access_virt_sarray(a1: cinfo, a2: client_data[1].start_pass, a3: client_data[2].post_process_data, a4: client_data[2].start_pass, a5: 0);
  v8 = (char *)client_data[2].start_pass - (char *)client_data[3].start_pass;
  if ( v8 > out_rows_avail - *out_row_ctr )
    v8 = out_rows_avail - *out_row_ctr;
  if ( v8 > (char *)cinfo[4].err - (char *)client_data[2].post_process_data )
    v8 = (char *)cinfo[4].err - (char *)client_data[2].post_process_data;
  (*(void (__cdecl **)(jpeg_common_struct *, char *, unsigned __int8 **, unsigned int))(*(_DWORD *)&cinfo[17].is_decompressor
                                                                                      + 4))(
    a1: cinfo,
    a2: (char *)client_data[1].post_process_data + 4 * (int)client_data[3].start_pass,
    a3: &output_buf[*out_row_ctr],
    a4: v8);
  *out_row_ctr += v8;
  start_pass = client_data[2].start_pass;
  client_data[3].start_pass = (void (__cdecl *)(jpeg_decompress_struct *, J_BUF_MODE))((char *)client_data[3].start_pass
                                                                                     + v8);
  if ( (char *)client_data[3].start_pass >= (char *)start_pass )
  {
    client_data[2].post_process_data = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))((char *)client_data[2].post_process_data + (unsigned int)start_pass);
    client_data[3].start_pass = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010150
// Name: start_pass_dpost
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_dpost(jpeg_common_struct *cinfo, J_BUF_MODE pass_mode)
{
  jpeg_d_post_controller *client_data; // esi
  bool v3; // zf

  client_data = (jpeg_d_post_controller *)cinfo[16].client_data;
  if ( pass_mode != JBUF_PASS_THRU )
  {
    if ( pass_mode == JBUF_CRANK_DEST )
    {
      if ( client_data[1].start_pass == nullptr )
      {
        cinfo->err->msg_code = 4;
        cinfo->err->error_exit(a1: cinfo);
      }
      client_data->post_process_data = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))post_process_2pass;
      client_data[3].start_pass = nullptr;
      client_data[2].post_process_data = nullptr;
    }
    else if ( pass_mode == JBUF_SAVE_AND_PASS )
    {
      if ( client_data[1].start_pass == nullptr )
      {
        cinfo->err->msg_code = 4;
        cinfo->err->error_exit(a1: cinfo);
      }
      client_data->post_process_data = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))post_process_prepass;
      client_data[3].start_pass = nullptr;
      client_data[2].post_process_data = nullptr;
    }
    else
    {
      cinfo->err->msg_code = 4;
      cinfo->err->error_exit(a1: cinfo);
      client_data[3].start_pass = nullptr;
      client_data[2].post_process_data = nullptr;
    }
  }
  else
  {
    if ( BYTE2(cinfo[3].err) != 0 )
    {
      v3 = client_data[1].post_process_data == nullptr;
      client_data->post_process_data = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))post_process_1pass;
      if ( v3 )
      {
        client_data[1].post_process_data = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))cinfo->mem->access_virt_sarray(a1: cinfo, a2: client_data[1].start_pass, a3: 0, a4: client_data[2].start_pass, a5: 1);
        client_data[3].start_pass = nullptr;
        client_data[2].post_process_data = nullptr;
        return;
      }
    }
    else
    {
      client_data->post_process_data = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))cinfo[17].progress->pass_counter;
    }
    client_data[3].start_pass = nullptr;
    client_data[2].post_process_data = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010260
// Name: _jinit_d_post_controller
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_d_post_controller(jpeg_common_struct *cinfo, unsigned __int8 need_full_buffer)
{
  jpeg_d_post_controller *v2; // edi
  int client_data; // eax
  jpeg_memory_mgr *mem; // ebx
  int v5; // eax
  unsigned int v6; // [esp-8h] [ebp-10h]

  v2 = (jpeg_d_post_controller *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 28);
  cinfo[16].client_data = v2;
  v2->start_pass = (void (__cdecl *)(jpeg_decompress_struct *, J_BUF_MODE))start_pass_dpost;
  v2[1].start_pass = nullptr;
  v2[1].post_process_data = nullptr;
  if ( BYTE2(cinfo[3].err) != 0 )
  {
    client_data = (int)cinfo[11].client_data;
    v2[2].start_pass = (void (__cdecl *)(jpeg_decompress_struct *, J_BUF_MODE))client_data;
    if ( need_full_buffer != 0 )
    {
      mem = cinfo->mem;
      v6 = client_data;
      v5 = jround_up(a: (int)cinfo[4].err, b: client_data);
      v2[1].start_pass = (void (__cdecl *)(jpeg_decompress_struct *, J_BUF_MODE))mem->request_virt_sarray(
                                                                                   a1: cinfo,
                                                                                   a2: 1,
                                                                                   a3: 0,
                                                                                   a4: cinfo[3].global_state
                                                                                 * (int)cinfo[4].mem,
                                                                                   a5: v5,
                                                                                   a6: v6);
    }
    else
    {
      v2[1].post_process_data = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))cinfo->mem->alloc_sarray(a1: cinfo, a2: 1, a3: cinfo[3].global_state * (int)cinfo[4].mem, a4: client_data);
    }
  }
}

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x10278CF0
// Name: post_process_1pass
// Source: json
//------------------------------------------------------------------------------
void __cdecl post_process_1pass(
        unsigned int cinfo,
        unsigned __int8 ***input_buf,
        unsigned int *in_row_group_ctr,
        unsigned int in_row_groups_avail,
        unsigned __int8 **output_buf,
        unsigned int *out_row_ctr,
        unsigned int out_rows_avail)
{
  unsigned int *v7; // ebx
  void (__cdecl *start_pass)(jpeg_decompress_struct *, J_BUF_MODE); // eax
  jpeg_decompress_struct *v9; // esi
  jpeg_d_post_controller *v10; // edi
  jpeg_upsampler *v11; // ecx

  v7 = out_row_ctr;
  start_pass = (void (__cdecl *)(jpeg_decompress_struct *, J_BUF_MODE))(out_rows_avail - *out_row_ctr);
  v9 = (jpeg_decompress_struct *)cinfo;
  v10 = *(jpeg_d_post_controller **)(cinfo + 396);
  if ( (char *)start_pass > (char *)v10[2].start_pass )
    start_pass = v10[2].start_pass;
  v11 = *(jpeg_upsampler **)(cinfo + 416);
  cinfo = 0;
  v11->upsample(
    a1: v9,
    a2: input_buf,
    a3: in_row_group_ctr,
    a4: in_row_groups_avail,
    a5: (unsigned __int8 **)v10[1].post_process_data,
    a6: &cinfo,
    a7: (unsigned int)start_pass);
  v9->cquantize->color_quantize(
    a1: v9,
    a2: (unsigned __int8 **)v10[1].post_process_data,
    a3: &output_buf[*v7],
    a4: cinfo);
  *v7 += cinfo;
}

//------------------------------------------------------------------------------
// Address: 0x10278D70
// Name: post_process_prepass
// Source: json
//------------------------------------------------------------------------------
void __cdecl post_process_prepass(
        jpeg_common_struct *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int *in_row_group_ctr,
        unsigned int in_row_groups_avail,
        unsigned __int8 **output_buf,
        unsigned int *out_row_ctr)
{
  jpeg_d_post_controller *client_data; // esi
  jpeg_d_post_controller *v8; // ebx
  unsigned int v9; // ecx
  void (__cdecl *start_pass)(jpeg_decompress_struct *, J_BUF_MODE); // eax
  unsigned int old_next_row; // [esp+14h] [ebp+8h]
  unsigned int old_next_rowa; // [esp+14h] [ebp+8h]

  client_data = (jpeg_d_post_controller *)cinfo[16].client_data;
  v8 = client_data + 3;
  if ( client_data[3].start_pass == nullptr )
    client_data[1].post_process_data = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))cinfo->mem->access_virt_sarray(a1: cinfo, a2: client_data[1].start_pass, a3: client_data[2].post_process_data, a4: client_data[2].start_pass, a5: 1);
  old_next_row = (unsigned int)v8->start_pass;
  ((void (__cdecl *)(jpeg_common_struct *, unsigned __int8 ***, unsigned int *, unsigned int, _DWORD, jpeg_d_post_controller *, void (__cdecl *)(jpeg_decompress_struct *, J_BUF_MODE)))cinfo[17].progress->pass_counter)(
    a1: cinfo,
    a2: input_buf,
    a3: in_row_group_ctr,
    a4: in_row_groups_avail,
    a5: client_data[1].post_process_data,
    a6: &client_data[3],
    a7: client_data[2].start_pass);
  v9 = old_next_row;
  if ( (char *)v8->start_pass > (char *)old_next_row )
  {
    old_next_rowa = (unsigned int)v8->start_pass - old_next_row;
    (*(void (__cdecl **)(jpeg_common_struct *, char *, _DWORD, unsigned int))(*(_DWORD *)&cinfo[17].is_decompressor + 4))(
      a1: cinfo,
      a2: (char *)client_data[1].post_process_data + 4 * v9,
      a3: 0,
      a4: old_next_rowa);
    *out_row_ctr += old_next_rowa;
  }
  start_pass = client_data[2].start_pass;
  if ( (char *)v8->start_pass >= (char *)start_pass )
  {
    client_data[2].post_process_data = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))((char *)client_data[2].post_process_data + (unsigned int)start_pass);
    v8->start_pass = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10278E20
// Name: post_process_2pass
// Source: json
//------------------------------------------------------------------------------
void __cdecl post_process_2pass(
        jpeg_common_struct *cinfo,
        unsigned __int8 ***input_buf,
        unsigned int *in_row_group_ctr,
        unsigned int in_row_groups_avail,
        unsigned __int8 **output_buf,
        unsigned int *out_row_ctr,
        unsigned int out_rows_avail)
{
  jpeg_d_post_controller *client_data; // esi
  unsigned int v8; // edi
  void (__cdecl *start_pass)(jpeg_decompress_struct *, J_BUF_MODE); // eax

  client_data = (jpeg_d_post_controller *)cinfo[16].client_data;
  if ( client_data[3].start_pass == nullptr )
    client_data[1].post_process_data = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))cinfo->mem->access_virt_sarray(a1: cinfo, a2: client_data[1].start_pass, a3: client_data[2].post_process_data, a4: client_data[2].start_pass, a5: 0);
  v8 = (char *)client_data[2].start_pass - (char *)client_data[3].start_pass;
  if ( v8 > out_rows_avail - *out_row_ctr )
    v8 = out_rows_avail - *out_row_ctr;
  if ( v8 > (char *)cinfo[4].err - (char *)client_data[2].post_process_data )
    v8 = (char *)cinfo[4].err - (char *)client_data[2].post_process_data;
  (*(void (__cdecl **)(jpeg_common_struct *, char *, unsigned __int8 **, unsigned int))(*(_DWORD *)&cinfo[17].is_decompressor
                                                                                      + 4))(
    a1: cinfo,
    a2: (char *)client_data[1].post_process_data + 4 * (int)client_data[3].start_pass,
    a3: &output_buf[*out_row_ctr],
    a4: v8);
  *out_row_ctr += v8;
  start_pass = client_data[2].start_pass;
  client_data[3].start_pass = (void (__cdecl *)(jpeg_decompress_struct *, J_BUF_MODE))((char *)client_data[3].start_pass
                                                                                     + v8);
  if ( (char *)client_data[3].start_pass >= (char *)start_pass )
  {
    client_data[2].post_process_data = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))((char *)client_data[2].post_process_data + (unsigned int)start_pass);
    client_data[3].start_pass = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10278EC0
// Name: start_pass_dpost
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_dpost(jpeg_common_struct *cinfo, J_BUF_MODE pass_mode)
{
  jpeg_d_post_controller *client_data; // esi
  bool v3; // zf

  client_data = (jpeg_d_post_controller *)cinfo[16].client_data;
  if ( pass_mode != JBUF_PASS_THRU )
  {
    if ( pass_mode == JBUF_CRANK_DEST )
    {
      if ( client_data[1].start_pass == nullptr )
      {
        cinfo->err->msg_code = 4;
        cinfo->err->error_exit(a1: cinfo);
      }
      client_data->post_process_data = post_process_2pass;
      client_data[3].start_pass = nullptr;
      client_data[2].post_process_data = nullptr;
    }
    else if ( pass_mode == JBUF_SAVE_AND_PASS )
    {
      if ( client_data[1].start_pass == nullptr )
      {
        cinfo->err->msg_code = 4;
        cinfo->err->error_exit(a1: cinfo);
      }
      client_data->post_process_data = post_process_prepass;
      client_data[3].start_pass = nullptr;
      client_data[2].post_process_data = nullptr;
    }
    else
    {
      cinfo->err->msg_code = 4;
      cinfo->err->error_exit(a1: cinfo);
      client_data[3].start_pass = nullptr;
      client_data[2].post_process_data = nullptr;
    }
  }
  else
  {
    if ( BYTE2(cinfo[3].err) != 0 )
    {
      v3 = client_data[1].post_process_data == nullptr;
      client_data->post_process_data = post_process_1pass;
      if ( v3 )
      {
        client_data[1].post_process_data = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))cinfo->mem->access_virt_sarray(a1: cinfo, a2: client_data[1].start_pass, a3: 0, a4: client_data[2].start_pass, a5: 1);
        client_data[3].start_pass = nullptr;
        client_data[2].post_process_data = nullptr;
        return;
      }
    }
    else
    {
      client_data->post_process_data = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))cinfo[17].progress->pass_counter;
    }
    client_data[3].start_pass = nullptr;
    client_data[2].post_process_data = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10278FD0
// Name: _jinit_d_post_controller
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_d_post_controller(jpeg_common_struct *cinfo, unsigned __int8 need_full_buffer)
{
  jpeg_d_post_controller *v2; // edi
  int client_data; // eax
  jpeg_memory_mgr *mem; // ebx
  int v5; // eax
  unsigned int v6; // [esp-8h] [ebp-10h]

  v2 = (jpeg_d_post_controller *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 28);
  cinfo[16].client_data = v2;
  v2->start_pass = (void (__cdecl *)(jpeg_decompress_struct *, J_BUF_MODE))start_pass_dpost;
  v2[1].start_pass = nullptr;
  v2[1].post_process_data = nullptr;
  if ( BYTE2(cinfo[3].err) != 0 )
  {
    client_data = (int)cinfo[11].client_data;
    v2[2].start_pass = (void (__cdecl *)(jpeg_decompress_struct *, J_BUF_MODE))client_data;
    if ( need_full_buffer != 0 )
    {
      mem = cinfo->mem;
      v6 = client_data;
      v5 = jround_up(a: (int)cinfo[4].err, b: client_data);
      v2[1].start_pass = (void (__cdecl *)(jpeg_decompress_struct *, J_BUF_MODE))mem->request_virt_sarray(
                                                                                   a1: cinfo,
                                                                                   a2: 1,
                                                                                   a3: 0,
                                                                                   a4: cinfo[3].global_state
                                                                                 * (int)cinfo[4].mem,
                                                                                   a5: v5,
                                                                                   a6: v6);
    }
    else
    {
      v2[1].post_process_data = (void (__cdecl *)(jpeg_decompress_struct *, unsigned __int8 ***, unsigned int *, unsigned int, unsigned __int8 **, unsigned int *, unsigned int))cinfo->mem->alloc_sarray(a1: cinfo, a2: 1, a3: cinfo[3].global_state * (int)cinfo[4].mem, a4: client_data);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10423500
// Name: _dynamic_initializer_for__post_jump_crouch__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__post_jump_crouch__()
{
  ConVar::ConVar(
    this: &post_jump_crouch,
    pName: "post_jump_crouch",
    pDefaultValue: "0.2f",
    flags: 0x4000,
    pHelpString: "This determines how long the player character will crouch for after landing a jump.  This only affects the third per"
    "son animation visuals and does not affect gameplay timing.");
  return atexit(func: dynamic_atexit_destructor_for__post_jump_crouch__);
}

//------------------------------------------------------------------------------
// Address: 0x10435800
// Name: _dynamic_atexit_destructor_for__post_jump_crouch__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__post_jump_crouch__()
{
  ConVar::~ConVar(this: &post_jump_crouch);
}

//------------------------------------------------------------------------------
// Address: 0x10423530
// Name: _dynamic_initializer_for__g_Prediction__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Prediction__()
{
  CPrediction::CPrediction(this: &g_Prediction);
  g_Prediction.__vftable = (CCSPrediction_vtbl *)&CCSPrediction::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__g_Prediction__);
}

//------------------------------------------------------------------------------
// Address: 0x10423550
// Name: _dynamic_initializer_for____g_CreateCCSPredictionIPrediction_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCCSPredictionIPrediction_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCCSPredictionIPrediction_reg,
           fn: (void *(__cdecl *)())_CreateCCSPredictionIPrediction_interface,
           pName: "VClientPrediction001");
}

} // namespace client
