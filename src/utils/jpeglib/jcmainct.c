// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jcmainct.c
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10253380
// Name: process_data_simple_main
// Source: json
//------------------------------------------------------------------------------
void __cdecl process_data_simple_main(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned int *in_row_ctr,
        unsigned int in_rows_avail)
{
  jpeg_c_main_controller *main; // esi
  void (__cdecl **p_process_data)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int); // ebx
  bool v6; // zf

  main = cinfo->main;
  if ( (char *)main[1].start_pass < (char *)cinfo->total_iMCU_rows )
  {
    p_process_data = &main[1].process_data;
    do
    {
      v6 = *p_process_data == (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int))8;
      if ( (unsigned int)*p_process_data < 8 )
      {
        cinfo->prep->pre_process_data(
          a1: cinfo,
          a2: input_buf,
          a3: in_row_ctr,
          a4: in_rows_avail,
          a5: (unsigned __int8 ***)&main[3],
          a6: (unsigned int *)&main[1].process_data,
          a7: 8u);
        v6 = *p_process_data == (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int))8;
      }
      if ( !v6 )
        break;
      if ( cinfo->coef->compress_data(a1: cinfo, a2: (unsigned __int8 ***)&main[3]) == 0 )
      {
        if ( LOBYTE(main[2].start_pass) == 0 )
        {
          --*in_row_ctr;
          LOBYTE(main[2].start_pass) = 1;
        }
        return;
      }
      if ( LOBYTE(main[2].start_pass) != 0 )
      {
        ++*in_row_ctr;
        LOBYTE(main[2].start_pass) = 0;
      }
      ++main[1].start_pass;
      *p_process_data = nullptr;
    }
    while ( (char *)main[1].start_pass < (char *)cinfo->total_iMCU_rows );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10253420
// Name: start_pass_main
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_main(
        jpeg_common_struct *cinfo,
        void (__cdecl *pass_mode)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int))
{
  jpeg_c_main_controller *progress; // eax

  progress = (jpeg_c_main_controller *)cinfo[13].progress;
  if ( LOBYTE(cinfo[7].progress) == 0 )
  {
    progress[1].start_pass = nullptr;
    progress[1].process_data = nullptr;
    LOBYTE(progress[2].start_pass) = 0;
    progress[2].process_data = pass_mode;
    if ( pass_mode != nullptr )
    {
      cinfo->err->msg_code = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
    else
    {
      progress->process_data = process_data_simple_main;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10253470
// Name: _jinit_c_main_controller
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_c_main_controller(jpeg_common_struct *cinfo, unsigned __int8 need_full_buffer)
{
  jpeg_c_main_controller *v3; // eax
  jpeg_component_info *global_state; // ecx
  unsigned int *p_width_in_blocks; // edi
  jpeg_c_main_controller *v6; // ebx
  int ci; // [esp+Ch] [ebp+8h]

  v3 = (jpeg_c_main_controller *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 64);
  cinfo[13].progress = (jpeg_progress_mgr *)v3;
  v3->start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))start_pass_main;
  if ( LOBYTE(cinfo[7].progress) == 0 )
  {
    if ( need_full_buffer != 0 )
    {
      cinfo->err->msg_code = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
    else
    {
      global_state = (jpeg_component_info *)cinfo[2].global_state;
      ci = 0;
      if ( (int)cinfo[2].client_data > 0 )
      {
        p_width_in_blocks = &global_state->width_in_blocks;
        v6 = v3 + 3;
        do
        {
          v6->start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))cinfo->mem->alloc_sarray(
                                                                                   a1: cinfo,
                                                                                   a2: 1,
                                                                                   a3: 8 * *p_width_in_blocks,
                                                                                   a4: 8 * *(p_width_in_blocks - 4));
          v6 = (jpeg_c_main_controller *)((char *)v6 + 4);
          p_width_in_blocks += 21;
          ++ci;
        }
        while ( ci < (int)cinfo[2].client_data );
      }
    }
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102533B0
// Name: process_data_simple_main
// Source: json
//------------------------------------------------------------------------------
void __cdecl process_data_simple_main(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned int *in_row_ctr,
        unsigned int in_rows_avail)
{
  jpeg_c_main_controller *main; // esi
  void (__cdecl **p_process_data)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int); // ebx
  bool v6; // zf

  main = cinfo->main;
  if ( (char *)main[1].start_pass < (char *)cinfo->total_iMCU_rows )
  {
    p_process_data = &main[1].process_data;
    do
    {
      v6 = *p_process_data == (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int))8;
      if ( (unsigned int)*p_process_data < 8 )
      {
        cinfo->prep->pre_process_data(
          a1: cinfo,
          a2: input_buf,
          a3: in_row_ctr,
          a4: in_rows_avail,
          a5: (unsigned __int8 ***)&main[3],
          a6: (unsigned int *)&main[1].process_data,
          a7: 8u);
        v6 = *p_process_data == (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int))8;
      }
      if ( !v6 )
        break;
      if ( cinfo->coef->compress_data(a1: cinfo, a2: (unsigned __int8 ***)&main[3]) == 0 )
      {
        if ( LOBYTE(main[2].start_pass) == 0 )
        {
          --*in_row_ctr;
          LOBYTE(main[2].start_pass) = 1;
        }
        return;
      }
      if ( LOBYTE(main[2].start_pass) != 0 )
      {
        ++*in_row_ctr;
        LOBYTE(main[2].start_pass) = 0;
      }
      ++main[1].start_pass;
      *p_process_data = nullptr;
    }
    while ( (char *)main[1].start_pass < (char *)cinfo->total_iMCU_rows );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10253450
// Name: start_pass_main
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_main(
        jpeg_common_struct *cinfo,
        void (__cdecl *pass_mode)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int))
{
  jpeg_c_main_controller *progress; // eax

  progress = (jpeg_c_main_controller *)cinfo[13].progress;
  if ( LOBYTE(cinfo[7].progress) == 0 )
  {
    progress[1].start_pass = nullptr;
    progress[1].process_data = nullptr;
    LOBYTE(progress[2].start_pass) = 0;
    progress[2].process_data = pass_mode;
    if ( pass_mode != nullptr )
    {
      cinfo->err->msg_code = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
    else
    {
      progress->process_data = process_data_simple_main;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102534A0
// Name: _jinit_c_main_controller
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_c_main_controller(jpeg_common_struct *cinfo, unsigned __int8 need_full_buffer)
{
  jpeg_c_main_controller *v3; // eax
  jpeg_component_info *global_state; // ecx
  unsigned int *p_width_in_blocks; // edi
  jpeg_c_main_controller *v6; // ebx
  int ci; // [esp+Ch] [ebp+8h]

  v3 = (jpeg_c_main_controller *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 64);
  cinfo[13].progress = (jpeg_progress_mgr *)v3;
  v3->start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))start_pass_main;
  if ( LOBYTE(cinfo[7].progress) == 0 )
  {
    if ( need_full_buffer != 0 )
    {
      cinfo->err->msg_code = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
    else
    {
      global_state = (jpeg_component_info *)cinfo[2].global_state;
      ci = 0;
      if ( (int)cinfo[2].client_data > 0 )
      {
        p_width_in_blocks = &global_state->width_in_blocks;
        v6 = v3 + 3;
        do
        {
          v6->start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))cinfo->mem->alloc_sarray(
                                                                                   a1: cinfo,
                                                                                   a2: 1,
                                                                                   a3: 8 * *p_width_in_blocks,
                                                                                   a4: 8 * *(p_width_in_blocks - 4));
          v6 = (jpeg_c_main_controller *)((char *)v6 + 4);
          p_width_in_blocks += 21;
          ++ci;
        }
        while ( ci < (int)cinfo[2].client_data );
      }
    }
  }
}

} // namespace engine_xlsp

// ============================================================
// Overlay from statsmap (Missing functions)
// ============================================================
namespace statsmap {

//------------------------------------------------------------------------------
// Address: 0x004078D0
// Name: process_data_simple_main
// Source: json
//------------------------------------------------------------------------------
void __cdecl process_data_simple_main(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned int *in_row_ctr,
        unsigned int in_rows_avail)
{
  jpeg_c_main_controller *main; // esi
  void (__cdecl **p_process_data)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int); // ebx
  bool v6; // zf

  main = cinfo->main;
  if ( (char *)main[1].start_pass < (char *)cinfo->total_iMCU_rows )
  {
    p_process_data = &main[1].process_data;
    do
    {
      v6 = *p_process_data == (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int))8;
      if ( (unsigned int)*p_process_data < 8 )
      {
        cinfo->prep->pre_process_data(
          a1: cinfo,
          a2: input_buf,
          a3: in_row_ctr,
          a4: in_rows_avail,
          a5: (unsigned __int8 ***)&main[3],
          a6: (unsigned int *)&main[1].process_data,
          a7: 8u);
        v6 = *p_process_data == (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int))8;
      }
      if ( !v6 )
        break;
      if ( cinfo->coef->compress_data(a1: cinfo, a2: (unsigned __int8 ***)&main[3]) == 0 )
      {
        if ( LOBYTE(main[2].start_pass) == 0 )
        {
          --*in_row_ctr;
          LOBYTE(main[2].start_pass) = 1;
        }
        return;
      }
      if ( LOBYTE(main[2].start_pass) != 0 )
      {
        ++*in_row_ctr;
        LOBYTE(main[2].start_pass) = 0;
      }
      ++main[1].start_pass;
      *p_process_data = nullptr;
    }
    while ( (char *)main[1].start_pass < (char *)cinfo->total_iMCU_rows );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407970
// Name: start_pass_main
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_main(
        jpeg_common_struct *cinfo,
        void (__cdecl *pass_mode)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int))
{
  jpeg_c_main_controller *progress; // eax

  progress = (jpeg_c_main_controller *)cinfo[13].progress;
  if ( LOBYTE(cinfo[7].progress) == 0 )
  {
    progress[1].start_pass = nullptr;
    progress[1].process_data = nullptr;
    LOBYTE(progress[2].start_pass) = 0;
    progress[2].process_data = pass_mode;
    if ( pass_mode != nullptr )
    {
      cinfo->err->msg_code = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
    else
    {
      progress->process_data = process_data_simple_main;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004079C0
// Name: _jinit_c_main_controller
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_c_main_controller(jpeg_common_struct *cinfo, unsigned __int8 need_full_buffer)
{
  jpeg_c_main_controller *v3; // eax
  jpeg_component_info *global_state; // ecx
  unsigned int *p_width_in_blocks; // edi
  jpeg_c_main_controller *v6; // ebx
  int ci; // [esp+Ch] [ebp+8h]

  v3 = (jpeg_c_main_controller *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 64);
  cinfo[13].progress = (jpeg_progress_mgr *)v3;
  v3->start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))start_pass_main;
  if ( LOBYTE(cinfo[7].progress) == 0 )
  {
    if ( need_full_buffer != 0 )
    {
      cinfo->err->msg_code = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
    else
    {
      global_state = (jpeg_component_info *)cinfo[2].global_state;
      ci = 0;
      if ( (int)cinfo[2].client_data > 0 )
      {
        p_width_in_blocks = &global_state->width_in_blocks;
        v6 = v3 + 3;
        do
        {
          v6->start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))cinfo->mem->alloc_sarray(
                                                                                   a1: cinfo,
                                                                                   a2: 1,
                                                                                   a3: 8 * *p_width_in_blocks,
                                                                                   a4: 8 * *(p_width_in_blocks - 4));
          v6 = (jpeg_c_main_controller *)((char *)v6 + 4);
          p_width_in_blocks += 21;
          ++ci;
        }
        while ( ci < (int)cinfo[2].client_data );
      }
    }
  }
}

} // namespace statsmap

// ============================================================
// Overlay from VXConsole (Missing functions)
// ============================================================
namespace VXConsole {

//------------------------------------------------------------------------------
// Address: 0x00430BE0
// Name: process_data_simple_main
// Source: json
//------------------------------------------------------------------------------
void __cdecl process_data_simple_main(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned int *in_row_ctr,
        unsigned int in_rows_avail)
{
  jpeg_c_main_controller *main; // esi
  void (__cdecl **p_process_data)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int); // ebx
  bool v6; // zf

  main = cinfo->main;
  if ( (char *)main[1].start_pass < (char *)cinfo->total_iMCU_rows )
  {
    p_process_data = &main[1].process_data;
    do
    {
      v6 = *p_process_data == (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int))8;
      if ( (unsigned int)*p_process_data < 8 )
      {
        cinfo->prep->pre_process_data(
          a1: cinfo,
          a2: input_buf,
          a3: in_row_ctr,
          a4: in_rows_avail,
          a5: (unsigned __int8 ***)&main[3],
          a6: (unsigned int *)&main[1].process_data,
          a7: 8u);
        v6 = *p_process_data == (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int))8;
      }
      if ( !v6 )
        break;
      if ( cinfo->coef->compress_data(a1: cinfo, a2: (unsigned __int8 ***)&main[3]) == 0 )
      {
        if ( LOBYTE(main[2].start_pass) == 0 )
        {
          --*in_row_ctr;
          LOBYTE(main[2].start_pass) = 1;
        }
        return;
      }
      if ( LOBYTE(main[2].start_pass) != 0 )
      {
        ++*in_row_ctr;
        LOBYTE(main[2].start_pass) = 0;
      }
      ++main[1].start_pass;
      *p_process_data = nullptr;
    }
    while ( (char *)main[1].start_pass < (char *)cinfo->total_iMCU_rows );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00430C80
// Name: start_pass_main
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_main(
        jpeg_common_struct *cinfo,
        void (__cdecl *pass_mode)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int))
{
  jpeg_c_main_controller *progress; // eax

  progress = (jpeg_c_main_controller *)cinfo[13].progress;
  if ( LOBYTE(cinfo[7].progress) == 0 )
  {
    progress[1].start_pass = nullptr;
    progress[1].process_data = nullptr;
    LOBYTE(progress[2].start_pass) = 0;
    progress[2].process_data = pass_mode;
    if ( pass_mode != nullptr )
    {
      cinfo->err->msg_code = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
    else
    {
      progress->process_data = process_data_simple_main;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00430CD0
// Name: _jinit_c_main_controller
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_c_main_controller(jpeg_common_struct *cinfo, unsigned __int8 need_full_buffer)
{
  jpeg_c_main_controller *v3; // eax
  jpeg_component_info *global_state; // ecx
  unsigned int *p_width_in_blocks; // edi
  jpeg_c_main_controller *v6; // ebx
  int ci; // [esp+Ch] [ebp+8h]

  v3 = (jpeg_c_main_controller *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 64);
  cinfo[13].progress = (jpeg_progress_mgr *)v3;
  v3->start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))start_pass_main;
  if ( LOBYTE(cinfo[7].progress) == 0 )
  {
    if ( need_full_buffer != 0 )
    {
      cinfo->err->msg_code = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
    else
    {
      global_state = (jpeg_component_info *)cinfo[2].global_state;
      ci = 0;
      if ( (int)cinfo[2].client_data > 0 )
      {
        p_width_in_blocks = &global_state->width_in_blocks;
        v6 = v3 + 3;
        do
        {
          v6->start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))cinfo->mem->alloc_sarray(
                                                                                   a1: cinfo,
                                                                                   a2: 1,
                                                                                   a3: 8 * *p_width_in_blocks,
                                                                                   a4: 8 * *(p_width_in_blocks - 4));
          v6 = (jpeg_c_main_controller *)((char *)v6 + 4);
          p_width_in_blocks += 21;
          ++ci;
        }
        while ( ci < (int)cinfo[2].client_data );
      }
    }
  }
}

} // namespace VXConsole

// ============================================================
// Overlay from vxconsole_ps3 (Missing functions)
// ============================================================
namespace vxconsole_ps3 {

//------------------------------------------------------------------------------
// Address: 0x0041D9E0
// Name: process_data_simple_main
// Source: json
//------------------------------------------------------------------------------
void __cdecl process_data_simple_main(
        jpeg_compress_struct *cinfo,
        unsigned __int8 **input_buf,
        unsigned int *in_row_ctr,
        unsigned int in_rows_avail)
{
  jpeg_c_main_controller *main; // esi
  void (__cdecl **p_process_data)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int); // ebx
  bool v6; // zf

  main = cinfo->main;
  if ( (char *)main[1].start_pass < (char *)cinfo->total_iMCU_rows )
  {
    p_process_data = &main[1].process_data;
    do
    {
      v6 = *p_process_data == (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int))8;
      if ( (unsigned int)*p_process_data < 8 )
      {
        cinfo->prep->pre_process_data(
          a1: cinfo,
          a2: input_buf,
          a3: in_row_ctr,
          a4: in_rows_avail,
          a5: (unsigned __int8 ***)&main[3],
          a6: (unsigned int *)&main[1].process_data,
          a7: 8u);
        v6 = *p_process_data == (void (__cdecl *)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int))8;
      }
      if ( !v6 )
        break;
      if ( cinfo->coef->compress_data(a1: cinfo, a2: (unsigned __int8 ***)&main[3]) == 0 )
      {
        if ( LOBYTE(main[2].start_pass) == 0 )
        {
          --*in_row_ctr;
          LOBYTE(main[2].start_pass) = 1;
        }
        return;
      }
      if ( LOBYTE(main[2].start_pass) != 0 )
      {
        ++*in_row_ctr;
        LOBYTE(main[2].start_pass) = 0;
      }
      ++main[1].start_pass;
      *p_process_data = nullptr;
    }
    while ( (char *)main[1].start_pass < (char *)cinfo->total_iMCU_rows );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041DA80
// Name: start_pass_main
// Source: json
//------------------------------------------------------------------------------
void __cdecl start_pass_main(
        jpeg_common_struct *cinfo,
        void (__cdecl *pass_mode)(jpeg_compress_struct *, unsigned __int8 **, unsigned int *, unsigned int))
{
  jpeg_c_main_controller *progress; // eax

  progress = (jpeg_c_main_controller *)cinfo[13].progress;
  if ( LOBYTE(cinfo[7].progress) == 0 )
  {
    progress[1].start_pass = nullptr;
    progress[1].process_data = nullptr;
    LOBYTE(progress[2].start_pass) = 0;
    progress[2].process_data = pass_mode;
    if ( pass_mode != nullptr )
    {
      cinfo->err->msg_code = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
    else
    {
      progress->process_data = process_data_simple_main;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041DAD0
// Name: _jinit_c_main_controller
// Source: json
//------------------------------------------------------------------------------
void __cdecl jinit_c_main_controller(jpeg_common_struct *cinfo, unsigned __int8 need_full_buffer)
{
  jpeg_c_main_controller *v3; // eax
  jpeg_component_info *global_state; // ecx
  unsigned int *p_width_in_blocks; // edi
  jpeg_c_main_controller *v6; // ebx
  int ci; // [esp+Ch] [ebp+8h]

  v3 = (jpeg_c_main_controller *)cinfo->mem->alloc_small(a1: cinfo, a2: 1, a3: 64);
  cinfo[13].progress = (jpeg_progress_mgr *)v3;
  v3->start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))start_pass_main;
  if ( LOBYTE(cinfo[7].progress) == 0 )
  {
    if ( need_full_buffer != 0 )
    {
      cinfo->err->msg_code = 4;
      cinfo->err->error_exit(a1: cinfo);
    }
    else
    {
      global_state = (jpeg_component_info *)cinfo[2].global_state;
      ci = 0;
      if ( (int)cinfo[2].client_data > 0 )
      {
        p_width_in_blocks = &global_state->width_in_blocks;
        v6 = v3 + 3;
        do
        {
          v6->start_pass = (void (__cdecl *)(jpeg_compress_struct *, J_BUF_MODE))cinfo->mem->alloc_sarray(
                                                                                   a1: cinfo,
                                                                                   a2: 1,
                                                                                   a3: 8 * *p_width_in_blocks,
                                                                                   a4: 8 * *(p_width_in_blocks - 4));
          v6 = (jpeg_c_main_controller *)((char *)v6 + 4);
          p_width_in_blocks += 21;
          ++ci;
        }
        while ( ci < (int)cinfo[2].client_data );
      }
    }
  }
}

} // namespace vxconsole_ps3
