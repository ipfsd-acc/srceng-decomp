// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jcapimin.c
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10250440
// Name: _jpeg_CreateCompress
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_CreateCompress(jpeg_common_struct *cinfo, int version, unsigned int structsize)
{
  jpeg_error_mgr *err; // edi
  void *client_data; // [esp+14h] [ebp+8h]

  cinfo->mem = nullptr;
  if ( version != 62 )
  {
    cinfo->err->msg_code = 12;
    cinfo->err->msg_parm.i[0] = 62;
    cinfo->err->msg_parm.i[1] = version;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( structsize != 360 )
  {
    cinfo->err->msg_code = 21;
    cinfo->err->msg_parm.i[0] = 360;
    cinfo->err->msg_parm.i[1] = structsize;
    cinfo->err->error_exit(a1: cinfo);
  }
  err = cinfo->err;
  client_data = cinfo->client_data;
  memset(dst: (unsigned __int8 *)cinfo, value: 0, count: 0x168u);
  cinfo->err = err;
  cinfo->client_data = client_data;
  cinfo->is_decompressor = 0;
  jinit_memory_mgr(cinfo);
  cinfo->progress = nullptr;
  cinfo[1].err = nullptr;
  cinfo[2].global_state = 0;
  cinfo[3].err = nullptr;
  cinfo[3].mem = nullptr;
  cinfo[3].progress = nullptr;
  cinfo[3].client_data = nullptr;
  *(_DWORD *)&cinfo[3].is_decompressor = 0;
  cinfo[4].progress = nullptr;
  cinfo[3].global_state = 0;
  cinfo[4].client_data = nullptr;
  cinfo[4].err = nullptr;
  *(_DWORD *)&cinfo[4].is_decompressor = 0;
  cinfo[4].mem = nullptr;
  cinfo[4].global_state = 0;
  *(_DWORD *)&cinfo[14].is_decompressor = 0;
  *(_QWORD *)&cinfo[2].err = 0x3FF0000000000000LL;
  cinfo->global_state = 100;
}

//------------------------------------------------------------------------------
// Address: 0x10250520
// Name: _jpeg_destroy_compress
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_destroy_compress(jpeg_common_struct *cinfo)
{
  jpeg_destroy(cinfo);
}

//------------------------------------------------------------------------------
// Address: 0x10250530
// Name: _jpeg_suppress_tables
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_suppress_tables(jpeg_compress_struct *cinfo, unsigned __int8 suppress)
{
  JQUANT_TBL *v2; // ecx
  JQUANT_TBL *v3; // ecx
  JQUANT_TBL *v4; // ecx
  JQUANT_TBL *v5; // ecx
  JHUFF_TBL **ac_huff_tbl_ptrs; // eax
  int i; // esi
  int v8; // ecx

  v2 = cinfo->quant_tbl_ptrs[0];
  if ( v2 != nullptr )
    v2->sent_table = suppress;
  v3 = cinfo->quant_tbl_ptrs[1];
  if ( v3 != nullptr )
    v3->sent_table = suppress;
  v4 = cinfo->quant_tbl_ptrs[2];
  if ( v4 != nullptr )
    v4->sent_table = suppress;
  v5 = cinfo->quant_tbl_ptrs[3];
  if ( v5 != nullptr )
    v5->sent_table = suppress;
  ac_huff_tbl_ptrs = cinfo->ac_huff_tbl_ptrs;
  for ( i = 4; i != 0; --i )
  {
    v8 = (int)*(ac_huff_tbl_ptrs - 4);
    if ( v8 != 0 )
      *(_BYTE *)(v8 + 273) = suppress;
    if ( *ac_huff_tbl_ptrs != nullptr )
      (*ac_huff_tbl_ptrs)->sent_table = suppress;
    ++ac_huff_tbl_ptrs;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102505A0
// Name: _jpeg_finish_compress
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_finish_compress(jpeg_common_struct *cinfo)
{
  int global_state; // eax
  jpeg_comp_master *i; // eax
  unsigned int j; // edi

  global_state = cinfo->global_state;
  if ( global_state == 101 || global_state == 102 )
  {
    if ( (jpeg_progress_mgr *)*(_DWORD *)&cinfo[8].is_decompressor < cinfo[1].progress )
    {
      cinfo->err->msg_code = 67;
      cinfo->err->error_exit(a1: cinfo);
    }
    ((void (__cdecl *)(jpeg_common_struct *))cinfo[13].mem->alloc_sarray)(a1: cinfo);
  }
  else if ( global_state != 103 )
  {
    cinfo->err->msg_code = 20;
    cinfo->err->msg_parm.i[0] = cinfo->global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  for ( i = (jpeg_comp_master *)cinfo[13].mem; i->is_last_pass == 0; i = (jpeg_comp_master *)cinfo[13].mem )
  {
    i->prepare_for_pass(a1: (jpeg_compress_struct *)cinfo);
    for ( j = 0; (jpeg_progress_mgr *)j < cinfo[9].progress; ++j )
    {
      if ( cinfo->progress != nullptr )
      {
        cinfo->progress->pass_counter = j;
        cinfo->progress->pass_limit = (int)cinfo[9].progress;
        cinfo->progress->progress_monitor(a1: cinfo);
      }
      if ( (*(unsigned __int8 (__cdecl **)(jpeg_common_struct *, _DWORD))(*(_DWORD *)&cinfo[13].is_decompressor + 4))(
             a1: cinfo,
             a2: 0) == 0 )
      {
        cinfo->err->msg_code = 24;
        cinfo->err->error_exit(a1: cinfo);
      }
    }
    ((void (__cdecl *)(jpeg_common_struct *))cinfo[13].mem->alloc_sarray)(a1: cinfo);
  }
  (*(void (__cdecl **)(jpeg_common_struct *))(cinfo[13].global_state + 12))(a1: cinfo);
  cinfo[1].err->reset_error_mgr(a1: cinfo);
  jpeg_abort(cinfo);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10250460
// Name: _jpeg_CreateCompress
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_CreateCompress(jpeg_common_struct *cinfo, int version, unsigned int structsize)
{
  jpeg_error_mgr *err; // edi
  void *client_data; // [esp+14h] [ebp+8h]

  cinfo->mem = nullptr;
  if ( version != 62 )
  {
    cinfo->err->msg_code = 12;
    cinfo->err->msg_parm.i[0] = 62;
    cinfo->err->msg_parm.i[1] = version;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( structsize != 360 )
  {
    cinfo->err->msg_code = 21;
    cinfo->err->msg_parm.i[0] = 360;
    cinfo->err->msg_parm.i[1] = structsize;
    cinfo->err->error_exit(a1: cinfo);
  }
  err = cinfo->err;
  client_data = cinfo->client_data;
  memset(dst: (unsigned __int8 *)cinfo, value: 0, count: 0x168u);
  cinfo->err = err;
  cinfo->client_data = client_data;
  cinfo->is_decompressor = 0;
  jinit_memory_mgr(cinfo);
  cinfo->progress = nullptr;
  cinfo[1].err = nullptr;
  cinfo[2].global_state = 0;
  cinfo[3].err = nullptr;
  cinfo[3].mem = nullptr;
  cinfo[3].progress = nullptr;
  cinfo[3].client_data = nullptr;
  *(_DWORD *)&cinfo[3].is_decompressor = 0;
  cinfo[4].progress = nullptr;
  cinfo[3].global_state = 0;
  cinfo[4].client_data = nullptr;
  cinfo[4].err = nullptr;
  *(_DWORD *)&cinfo[4].is_decompressor = 0;
  cinfo[4].mem = nullptr;
  cinfo[4].global_state = 0;
  *(_DWORD *)&cinfo[14].is_decompressor = 0;
  *(_QWORD *)&cinfo[2].err = 0x3FF0000000000000LL;
  cinfo->global_state = 100;
}

//------------------------------------------------------------------------------
// Address: 0x10250540
// Name: _jpeg_destroy_compress
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_destroy_compress(jpeg_common_struct *cinfo)
{
  jpeg_destroy(cinfo);
}

//------------------------------------------------------------------------------
// Address: 0x10250550
// Name: _jpeg_suppress_tables
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_suppress_tables(jpeg_compress_struct *cinfo, unsigned __int8 suppress)
{
  JQUANT_TBL *v2; // ecx
  JQUANT_TBL *v3; // ecx
  JQUANT_TBL *v4; // ecx
  JQUANT_TBL *v5; // ecx
  JHUFF_TBL **ac_huff_tbl_ptrs; // eax
  int i; // esi
  int v8; // ecx

  v2 = cinfo->quant_tbl_ptrs[0];
  if ( v2 != nullptr )
    v2->sent_table = suppress;
  v3 = cinfo->quant_tbl_ptrs[1];
  if ( v3 != nullptr )
    v3->sent_table = suppress;
  v4 = cinfo->quant_tbl_ptrs[2];
  if ( v4 != nullptr )
    v4->sent_table = suppress;
  v5 = cinfo->quant_tbl_ptrs[3];
  if ( v5 != nullptr )
    v5->sent_table = suppress;
  ac_huff_tbl_ptrs = cinfo->ac_huff_tbl_ptrs;
  for ( i = 4; i != 0; --i )
  {
    v8 = (int)*(ac_huff_tbl_ptrs - 4);
    if ( v8 != 0 )
      *(_BYTE *)(v8 + 273) = suppress;
    if ( *ac_huff_tbl_ptrs != nullptr )
      (*ac_huff_tbl_ptrs)->sent_table = suppress;
    ++ac_huff_tbl_ptrs;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102505C0
// Name: _jpeg_finish_compress
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_finish_compress(jpeg_common_struct *cinfo)
{
  int global_state; // eax
  jpeg_comp_master *i; // eax
  unsigned int j; // edi

  global_state = cinfo->global_state;
  if ( global_state == 101 || global_state == 102 )
  {
    if ( (jpeg_progress_mgr *)*(_DWORD *)&cinfo[8].is_decompressor < cinfo[1].progress )
    {
      cinfo->err->msg_code = 67;
      cinfo->err->error_exit(a1: cinfo);
    }
    ((void (__cdecl *)(jpeg_common_struct *))cinfo[13].mem->alloc_sarray)(a1: cinfo);
  }
  else if ( global_state != 103 )
  {
    cinfo->err->msg_code = 20;
    cinfo->err->msg_parm.i[0] = cinfo->global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  for ( i = (jpeg_comp_master *)cinfo[13].mem; i->is_last_pass == 0; i = (jpeg_comp_master *)cinfo[13].mem )
  {
    i->prepare_for_pass(a1: (jpeg_compress_struct *)cinfo);
    for ( j = 0; (jpeg_progress_mgr *)j < cinfo[9].progress; ++j )
    {
      if ( cinfo->progress != nullptr )
      {
        cinfo->progress->pass_counter = j;
        cinfo->progress->pass_limit = (int)cinfo[9].progress;
        cinfo->progress->progress_monitor(a1: cinfo);
      }
      if ( (*(unsigned __int8 (__cdecl **)(jpeg_common_struct *, _DWORD))(*(_DWORD *)&cinfo[13].is_decompressor + 4))(
             a1: cinfo,
             a2: 0) == 0 )
      {
        cinfo->err->msg_code = 24;
        cinfo->err->error_exit(a1: cinfo);
      }
    }
    ((void (__cdecl *)(jpeg_common_struct *))cinfo[13].mem->alloc_sarray)(a1: cinfo);
  }
  (*(void (__cdecl **)(jpeg_common_struct *))(cinfo[13].global_state + 12))(a1: cinfo);
  cinfo[1].err->reset_error_mgr(a1: cinfo);
  jpeg_abort(cinfo);
}

} // namespace engine_xlsp

// ============================================================
// Overlay from statsmap (Missing functions)
// ============================================================
namespace statsmap {

//------------------------------------------------------------------------------
// Address: 0x00404970
// Name: _jpeg_CreateCompress
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_CreateCompress(jpeg_common_struct *cinfo, int version, unsigned int structsize)
{
  jpeg_error_mgr *err; // edi
  void *client_data; // [esp+14h] [ebp+8h]

  cinfo->mem = nullptr;
  if ( version != 62 )
  {
    cinfo->err->msg_code = 12;
    cinfo->err->msg_parm.i[0] = 62;
    cinfo->err->msg_parm.i[1] = version;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( structsize != 360 )
  {
    cinfo->err->msg_code = 21;
    cinfo->err->msg_parm.i[0] = 360;
    cinfo->err->msg_parm.i[1] = structsize;
    cinfo->err->error_exit(a1: cinfo);
  }
  err = cinfo->err;
  client_data = cinfo->client_data;
  memset(dst: (unsigned __int8 *)cinfo, value: 0, count: 0x168u);
  cinfo->err = err;
  cinfo->client_data = client_data;
  cinfo->is_decompressor = 0;
  jinit_memory_mgr(cinfo);
  cinfo->progress = nullptr;
  cinfo[1].err = nullptr;
  cinfo[2].global_state = 0;
  cinfo[3].err = nullptr;
  cinfo[3].mem = nullptr;
  cinfo[3].progress = nullptr;
  cinfo[3].client_data = nullptr;
  *(_DWORD *)&cinfo[3].is_decompressor = 0;
  cinfo[4].progress = nullptr;
  cinfo[3].global_state = 0;
  cinfo[4].client_data = nullptr;
  cinfo[4].err = nullptr;
  *(_DWORD *)&cinfo[4].is_decompressor = 0;
  cinfo[4].mem = nullptr;
  cinfo[4].global_state = 0;
  *(_DWORD *)&cinfo[14].is_decompressor = 0;
  *(_QWORD *)&cinfo[2].err = 0x3FF0000000000000LL;
  cinfo->global_state = 100;
}

//------------------------------------------------------------------------------
// Address: 0x00404A50
// Name: _jpeg_destroy_compress
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_destroy_compress(jpeg_common_struct *cinfo)
{
  jpeg_destroy(cinfo);
}

//------------------------------------------------------------------------------
// Address: 0x00404A60
// Name: _jpeg_suppress_tables
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_suppress_tables(jpeg_compress_struct *cinfo, unsigned __int8 suppress)
{
  JQUANT_TBL *v2; // ecx
  JQUANT_TBL *v3; // ecx
  JQUANT_TBL *v4; // ecx
  JQUANT_TBL *v5; // ecx
  JHUFF_TBL **ac_huff_tbl_ptrs; // eax
  int i; // esi
  int v8; // ecx

  v2 = cinfo->quant_tbl_ptrs[0];
  if ( v2 != nullptr )
    v2->sent_table = suppress;
  v3 = cinfo->quant_tbl_ptrs[1];
  if ( v3 != nullptr )
    v3->sent_table = suppress;
  v4 = cinfo->quant_tbl_ptrs[2];
  if ( v4 != nullptr )
    v4->sent_table = suppress;
  v5 = cinfo->quant_tbl_ptrs[3];
  if ( v5 != nullptr )
    v5->sent_table = suppress;
  ac_huff_tbl_ptrs = cinfo->ac_huff_tbl_ptrs;
  for ( i = 4; i != 0; --i )
  {
    v8 = (int)*(ac_huff_tbl_ptrs - 4);
    if ( v8 != 0 )
      *(_BYTE *)(v8 + 273) = suppress;
    if ( *ac_huff_tbl_ptrs != nullptr )
      (*ac_huff_tbl_ptrs)->sent_table = suppress;
    ++ac_huff_tbl_ptrs;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404AD0
// Name: _jpeg_finish_compress
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_finish_compress(jpeg_common_struct *cinfo)
{
  int global_state; // eax
  jpeg_comp_master *i; // eax
  unsigned int j; // edi

  global_state = cinfo->global_state;
  if ( global_state == 101 || global_state == 102 )
  {
    if ( (jpeg_progress_mgr *)*(_DWORD *)&cinfo[8].is_decompressor < cinfo[1].progress )
    {
      cinfo->err->msg_code = 67;
      cinfo->err->error_exit(a1: cinfo);
    }
    ((void (__cdecl *)(jpeg_common_struct *))cinfo[13].mem->alloc_sarray)(a1: cinfo);
  }
  else if ( global_state != 103 )
  {
    cinfo->err->msg_code = 20;
    cinfo->err->msg_parm.i[0] = cinfo->global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  for ( i = (jpeg_comp_master *)cinfo[13].mem; i->is_last_pass == 0; i = (jpeg_comp_master *)cinfo[13].mem )
  {
    i->prepare_for_pass(a1: (jpeg_compress_struct *)cinfo);
    for ( j = 0; (jpeg_progress_mgr *)j < cinfo[9].progress; ++j )
    {
      if ( cinfo->progress != nullptr )
      {
        cinfo->progress->pass_counter = j;
        cinfo->progress->pass_limit = (int)cinfo[9].progress;
        cinfo->progress->progress_monitor(a1: cinfo);
      }
      if ( (*(unsigned __int8 (__cdecl **)(jpeg_common_struct *, _DWORD))(*(_DWORD *)&cinfo[13].is_decompressor + 4))(
             a1: cinfo,
             a2: 0) == 0 )
      {
        cinfo->err->msg_code = 24;
        cinfo->err->error_exit(a1: cinfo);
      }
    }
    ((void (__cdecl *)(jpeg_common_struct *))cinfo[13].mem->alloc_sarray)(a1: cinfo);
  }
  (*(void (__cdecl **)(jpeg_common_struct *))(cinfo[13].global_state + 12))(a1: cinfo);
  cinfo[1].err->reset_error_mgr(a1: cinfo);
  jpeg_abort(cinfo);
}

} // namespace statsmap

// ============================================================
// Overlay from VXConsole (Missing functions)
// ============================================================
namespace VXConsole {

//------------------------------------------------------------------------------
// Address: 0x0042DC90
// Name: _jpeg_CreateCompress
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_CreateCompress(jpeg_common_struct *cinfo, int version, unsigned int structsize)
{
  jpeg_error_mgr *err; // edi
  void *client_data; // [esp+14h] [ebp+8h]

  cinfo->mem = nullptr;
  if ( version != 62 )
  {
    cinfo->err->msg_code = 12;
    cinfo->err->msg_parm.i[0] = 62;
    cinfo->err->msg_parm.i[1] = version;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( structsize != 360 )
  {
    cinfo->err->msg_code = 21;
    cinfo->err->msg_parm.i[0] = 360;
    cinfo->err->msg_parm.i[1] = structsize;
    cinfo->err->error_exit(a1: cinfo);
  }
  err = cinfo->err;
  client_data = cinfo->client_data;
  memset(dst: (unsigned __int8 *)cinfo, value: 0, count: 0x168u);
  cinfo->err = err;
  cinfo->client_data = client_data;
  cinfo->is_decompressor = 0;
  jinit_memory_mgr(cinfo);
  cinfo->progress = nullptr;
  cinfo[1].err = nullptr;
  cinfo[2].global_state = 0;
  cinfo[3].err = nullptr;
  cinfo[3].mem = nullptr;
  cinfo[3].progress = nullptr;
  cinfo[3].client_data = nullptr;
  *(_DWORD *)&cinfo[3].is_decompressor = 0;
  cinfo[4].progress = nullptr;
  cinfo[3].global_state = 0;
  cinfo[4].client_data = nullptr;
  cinfo[4].err = nullptr;
  *(_DWORD *)&cinfo[4].is_decompressor = 0;
  cinfo[4].mem = nullptr;
  cinfo[4].global_state = 0;
  *(_DWORD *)&cinfo[14].is_decompressor = 0;
  *(_QWORD *)&cinfo[2].err = 0x3FF0000000000000LL;
  cinfo->global_state = 100;
}

//------------------------------------------------------------------------------
// Address: 0x0042DD70
// Name: _jpeg_suppress_tables
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_suppress_tables(jpeg_compress_struct *cinfo, unsigned __int8 suppress)
{
  JQUANT_TBL *v2; // ecx
  JQUANT_TBL *v3; // ecx
  JQUANT_TBL *v4; // ecx
  JQUANT_TBL *v5; // ecx
  JHUFF_TBL **ac_huff_tbl_ptrs; // eax
  int i; // esi
  int v8; // ecx

  v2 = cinfo->quant_tbl_ptrs[0];
  if ( v2 != nullptr )
    v2->sent_table = suppress;
  v3 = cinfo->quant_tbl_ptrs[1];
  if ( v3 != nullptr )
    v3->sent_table = suppress;
  v4 = cinfo->quant_tbl_ptrs[2];
  if ( v4 != nullptr )
    v4->sent_table = suppress;
  v5 = cinfo->quant_tbl_ptrs[3];
  if ( v5 != nullptr )
    v5->sent_table = suppress;
  ac_huff_tbl_ptrs = cinfo->ac_huff_tbl_ptrs;
  for ( i = 4; i != 0; --i )
  {
    v8 = (int)*(ac_huff_tbl_ptrs - 4);
    if ( v8 != 0 )
      *(_BYTE *)(v8 + 273) = suppress;
    if ( *ac_huff_tbl_ptrs != nullptr )
      (*ac_huff_tbl_ptrs)->sent_table = suppress;
    ++ac_huff_tbl_ptrs;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042DDE0
// Name: _jpeg_finish_compress
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_finish_compress(jpeg_common_struct *cinfo)
{
  int global_state; // eax
  jpeg_comp_master *i; // eax
  unsigned int j; // edi

  global_state = cinfo->global_state;
  if ( global_state == 101 || global_state == 102 )
  {
    if ( (jpeg_progress_mgr *)*(_DWORD *)&cinfo[8].is_decompressor < cinfo[1].progress )
    {
      cinfo->err->msg_code = 67;
      cinfo->err->error_exit(a1: cinfo);
    }
    ((void (__cdecl *)(jpeg_common_struct *))cinfo[13].mem->alloc_sarray)(a1: cinfo);
  }
  else if ( global_state != 103 )
  {
    cinfo->err->msg_code = 20;
    cinfo->err->msg_parm.i[0] = cinfo->global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  for ( i = (jpeg_comp_master *)cinfo[13].mem; i->is_last_pass == 0; i = (jpeg_comp_master *)cinfo[13].mem )
  {
    i->prepare_for_pass(a1: (jpeg_compress_struct *)cinfo);
    for ( j = 0; (jpeg_progress_mgr *)j < cinfo[9].progress; ++j )
    {
      if ( cinfo->progress != nullptr )
      {
        cinfo->progress->pass_counter = j;
        cinfo->progress->pass_limit = (int)cinfo[9].progress;
        cinfo->progress->progress_monitor(a1: cinfo);
      }
      if ( (*(unsigned __int8 (__cdecl **)(jpeg_common_struct *, _DWORD))(*(_DWORD *)&cinfo[13].is_decompressor + 4))(
             a1: cinfo,
             a2: 0) == 0 )
      {
        cinfo->err->msg_code = 24;
        cinfo->err->error_exit(a1: cinfo);
      }
    }
    ((void (__cdecl *)(jpeg_common_struct *))cinfo[13].mem->alloc_sarray)(a1: cinfo);
  }
  (*(void (__cdecl **)(jpeg_common_struct *))(cinfo[13].global_state + 12))(a1: cinfo);
  cinfo[1].err->reset_error_mgr(a1: cinfo);
  jpeg_abort(cinfo);
}

} // namespace VXConsole

// ============================================================
// Overlay from vxconsole_ps3 (Missing functions)
// ============================================================
namespace vxconsole_ps3 {

//------------------------------------------------------------------------------
// Address: 0x0041AA90
// Name: _jpeg_CreateCompress
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_CreateCompress(jpeg_common_struct *cinfo, int version, unsigned int structsize)
{
  jpeg_error_mgr *err; // edi
  void *client_data; // [esp+14h] [ebp+8h]

  cinfo->mem = nullptr;
  if ( version != 62 )
  {
    cinfo->err->msg_code = 12;
    cinfo->err->msg_parm.i[0] = 62;
    cinfo->err->msg_parm.i[1] = version;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( structsize != 360 )
  {
    cinfo->err->msg_code = 21;
    cinfo->err->msg_parm.i[0] = 360;
    cinfo->err->msg_parm.i[1] = structsize;
    cinfo->err->error_exit(a1: cinfo);
  }
  err = cinfo->err;
  client_data = cinfo->client_data;
  memset(dst: (unsigned __int8 *)cinfo, value: 0, count: 0x168u);
  cinfo->err = err;
  cinfo->client_data = client_data;
  cinfo->is_decompressor = 0;
  jinit_memory_mgr(cinfo);
  cinfo->progress = nullptr;
  cinfo[1].err = nullptr;
  cinfo[2].global_state = 0;
  cinfo[3].err = nullptr;
  cinfo[3].mem = nullptr;
  cinfo[3].progress = nullptr;
  cinfo[3].client_data = nullptr;
  *(_DWORD *)&cinfo[3].is_decompressor = 0;
  cinfo[4].progress = nullptr;
  cinfo[3].global_state = 0;
  cinfo[4].client_data = nullptr;
  cinfo[4].err = nullptr;
  *(_DWORD *)&cinfo[4].is_decompressor = 0;
  cinfo[4].mem = nullptr;
  cinfo[4].global_state = 0;
  *(_DWORD *)&cinfo[14].is_decompressor = 0;
  *(_QWORD *)&cinfo[2].err = 0x3FF0000000000000LL;
  cinfo->global_state = 100;
}

//------------------------------------------------------------------------------
// Address: 0x0041AB70
// Name: _jpeg_suppress_tables
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_suppress_tables(jpeg_compress_struct *cinfo, unsigned __int8 suppress)
{
  JQUANT_TBL *v2; // ecx
  JQUANT_TBL *v3; // ecx
  JQUANT_TBL *v4; // ecx
  JQUANT_TBL *v5; // ecx
  JHUFF_TBL **ac_huff_tbl_ptrs; // eax
  int i; // esi
  int v8; // ecx

  v2 = cinfo->quant_tbl_ptrs[0];
  if ( v2 != nullptr )
    v2->sent_table = suppress;
  v3 = cinfo->quant_tbl_ptrs[1];
  if ( v3 != nullptr )
    v3->sent_table = suppress;
  v4 = cinfo->quant_tbl_ptrs[2];
  if ( v4 != nullptr )
    v4->sent_table = suppress;
  v5 = cinfo->quant_tbl_ptrs[3];
  if ( v5 != nullptr )
    v5->sent_table = suppress;
  ac_huff_tbl_ptrs = cinfo->ac_huff_tbl_ptrs;
  for ( i = 4; i != 0; --i )
  {
    v8 = (int)*(ac_huff_tbl_ptrs - 4);
    if ( v8 != 0 )
      *(_BYTE *)(v8 + 273) = suppress;
    if ( *ac_huff_tbl_ptrs != nullptr )
      (*ac_huff_tbl_ptrs)->sent_table = suppress;
    ++ac_huff_tbl_ptrs;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041ABE0
// Name: _jpeg_finish_compress
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_finish_compress(jpeg_common_struct *cinfo)
{
  int global_state; // eax
  jpeg_comp_master *i; // eax
  unsigned int j; // edi

  global_state = cinfo->global_state;
  if ( global_state == 101 || global_state == 102 )
  {
    if ( (jpeg_progress_mgr *)*(_DWORD *)&cinfo[8].is_decompressor < cinfo[1].progress )
    {
      cinfo->err->msg_code = 67;
      cinfo->err->error_exit(a1: cinfo);
    }
    ((void (__cdecl *)(jpeg_common_struct *))cinfo[13].mem->alloc_sarray)(a1: cinfo);
  }
  else if ( global_state != 103 )
  {
    cinfo->err->msg_code = 20;
    cinfo->err->msg_parm.i[0] = cinfo->global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  for ( i = (jpeg_comp_master *)cinfo[13].mem; i->is_last_pass == 0; i = (jpeg_comp_master *)cinfo[13].mem )
  {
    i->prepare_for_pass(a1: (jpeg_compress_struct *)cinfo);
    for ( j = 0; (jpeg_progress_mgr *)j < cinfo[9].progress; ++j )
    {
      if ( cinfo->progress != nullptr )
      {
        cinfo->progress->pass_counter = j;
        cinfo->progress->pass_limit = (int)cinfo[9].progress;
        cinfo->progress->progress_monitor(a1: cinfo);
      }
      if ( (*(unsigned __int8 (__cdecl **)(jpeg_common_struct *, _DWORD))(*(_DWORD *)&cinfo[13].is_decompressor + 4))(
             a1: cinfo,
             a2: 0) == 0 )
      {
        cinfo->err->msg_code = 24;
        cinfo->err->error_exit(a1: cinfo);
      }
    }
    ((void (__cdecl *)(jpeg_common_struct *))cinfo[13].mem->alloc_sarray)(a1: cinfo);
  }
  (*(void (__cdecl **)(jpeg_common_struct *))(cinfo[13].global_state + 12))(a1: cinfo);
  cinfo[1].err->reset_error_mgr(a1: cinfo);
  jpeg_abort(cinfo);
}

} // namespace vxconsole_ps3
