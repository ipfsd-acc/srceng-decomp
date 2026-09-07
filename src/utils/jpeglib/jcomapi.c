// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jcomapi.c
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10252040
// Name: _jpeg_abort
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_abort(jpeg_common_struct *cinfo)
{
  jpeg_memory_mgr *mem; // eax

  mem = cinfo->mem;
  if ( mem != nullptr )
  {
    mem->free_pool(a1: cinfo, a2: 1);
    if ( cinfo->is_decompressor != 0 )
    {
      cinfo->global_state = 200;
      cinfo[11].mem = nullptr;
    }
    else
    {
      cinfo->global_state = 100;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10252080
// Name: _jpeg_destroy
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_destroy(jpeg_common_struct *cinfo)
{
  jpeg_memory_mgr *mem; // eax

  mem = cinfo->mem;
  if ( mem != nullptr )
    mem->self_destruct(a1: cinfo);
  cinfo->global_state = 0;
  cinfo->mem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102520B0
// Name: _jpeg_alloc_quant_table
// Source: json
//------------------------------------------------------------------------------
JQUANT_TBL *__cdecl jpeg_alloc_quant_table(jpeg_common_struct *cinfo)
{
  JQUANT_TBL *result; // eax

  result = (JQUANT_TBL *)cinfo->mem->alloc_small(a1: cinfo, a2: 0, a3: 130);
  result->sent_table = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102520E0
// Name: _jpeg_alloc_huff_table
// Source: json
//------------------------------------------------------------------------------
JHUFF_TBL *__cdecl jpeg_alloc_huff_table(jpeg_common_struct *cinfo)
{
  JHUFF_TBL *result; // eax

  result = (JHUFF_TBL *)cinfo->mem->alloc_small(a1: cinfo, a2: 0, a3: 274);
  result->sent_table = 0;
  return result;
}

// ============================================================
// Overlay from FileSystemOpenDialog (Missing functions)
// ============================================================
namespace FileSystemOpenDialog {

//------------------------------------------------------------------------------
// Address: 0x1000C660
// Name: _jpeg_abort
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_abort(jpeg_common_struct *cinfo)
{
  jpeg_memory_mgr *mem; // eax

  mem = cinfo->mem;
  if ( mem != nullptr )
  {
    mem->free_pool(a1: cinfo, a2: 1);
    if ( cinfo->is_decompressor != 0 )
    {
      cinfo->global_state = 200;
      cinfo[11].mem = nullptr;
    }
    else
    {
      cinfo->global_state = 100;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C6A0
// Name: _jpeg_destroy
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_destroy(jpeg_common_struct *cinfo)
{
  jpeg_memory_mgr *mem; // eax

  mem = cinfo->mem;
  if ( mem != nullptr )
    mem->self_destruct(a1: cinfo);
  cinfo->global_state = 0;
  cinfo->mem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000C6D0
// Name: _jpeg_alloc_quant_table
// Source: json
//------------------------------------------------------------------------------
JQUANT_TBL *__cdecl jpeg_alloc_quant_table(jpeg_common_struct *cinfo)
{
  JQUANT_TBL *result; // eax

  result = (JQUANT_TBL *)cinfo->mem->alloc_small(a1: cinfo, a2: 0, a3: 130);
  result->sent_table = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000C700
// Name: _jpeg_alloc_huff_table
// Source: json
//------------------------------------------------------------------------------
JHUFF_TBL *__cdecl jpeg_alloc_huff_table(jpeg_common_struct *cinfo)
{
  JHUFF_TBL *result; // eax

  result = (JHUFF_TBL *)cinfo->mem->alloc_small(a1: cinfo, a2: 0, a3: 274);
  result->sent_table = 0;
  return result;
}

} // namespace FileSystemOpenDialog

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10252060
// Name: _jpeg_abort
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_abort(jpeg_common_struct *cinfo)
{
  jpeg_memory_mgr *mem; // eax

  mem = cinfo->mem;
  if ( mem != nullptr )
  {
    mem->free_pool(a1: cinfo, a2: 1);
    if ( cinfo->is_decompressor != 0 )
    {
      cinfo->global_state = 200;
      cinfo[11].mem = nullptr;
    }
    else
    {
      cinfo->global_state = 100;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102520A0
// Name: _jpeg_destroy
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_destroy(jpeg_common_struct *cinfo)
{
  jpeg_memory_mgr *mem; // eax

  mem = cinfo->mem;
  if ( mem != nullptr )
    mem->self_destruct(a1: cinfo);
  cinfo->global_state = 0;
  cinfo->mem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102520D0
// Name: _jpeg_alloc_quant_table
// Source: json
//------------------------------------------------------------------------------
JQUANT_TBL *__cdecl jpeg_alloc_quant_table(jpeg_common_struct *cinfo)
{
  JQUANT_TBL *result; // eax

  result = (JQUANT_TBL *)cinfo->mem->alloc_small(a1: cinfo, a2: 0, a3: 130);
  result->sent_table = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10252100
// Name: _jpeg_alloc_huff_table
// Source: json
//------------------------------------------------------------------------------
JHUFF_TBL *__cdecl jpeg_alloc_huff_table(jpeg_common_struct *cinfo)
{
  JHUFF_TBL *result; // eax

  result = (JHUFF_TBL *)cinfo->mem->alloc_small(a1: cinfo, a2: 0, a3: 274);
  result->sent_table = 0;
  return result;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from statsmap (Missing functions)
// ============================================================
namespace statsmap {

//------------------------------------------------------------------------------
// Address: 0x00406570
// Name: _jpeg_abort
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_abort(jpeg_common_struct *cinfo)
{
  jpeg_memory_mgr *mem; // eax

  mem = cinfo->mem;
  if ( mem != nullptr )
  {
    mem->free_pool(a1: cinfo, a2: 1);
    if ( cinfo->is_decompressor != 0 )
    {
      cinfo->global_state = 200;
      cinfo[11].mem = nullptr;
    }
    else
    {
      cinfo->global_state = 100;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004065B0
// Name: _jpeg_destroy
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_destroy(jpeg_common_struct *cinfo)
{
  jpeg_memory_mgr *mem; // eax

  mem = cinfo->mem;
  if ( mem != nullptr )
    mem->self_destruct(a1: cinfo);
  cinfo->global_state = 0;
  cinfo->mem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004065E0
// Name: _jpeg_alloc_quant_table
// Source: json
//------------------------------------------------------------------------------
JQUANT_TBL *__cdecl jpeg_alloc_quant_table(jpeg_common_struct *cinfo)
{
  JQUANT_TBL *result; // eax

  result = (JQUANT_TBL *)cinfo->mem->alloc_small(a1: cinfo, a2: 0, a3: 130);
  result->sent_table = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406610
// Name: _jpeg_alloc_huff_table
// Source: json
//------------------------------------------------------------------------------
JHUFF_TBL *__cdecl jpeg_alloc_huff_table(jpeg_common_struct *cinfo)
{
  JHUFF_TBL *result; // eax

  result = (JHUFF_TBL *)cinfo->mem->alloc_small(a1: cinfo, a2: 0, a3: 274);
  result->sent_table = 0;
  return result;
}

} // namespace statsmap

// ============================================================
// Overlay from VXConsole (Missing functions)
// ============================================================
namespace VXConsole {

//------------------------------------------------------------------------------
// Address: 0x0042F880
// Name: _jpeg_abort
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_abort(jpeg_common_struct *cinfo)
{
  jpeg_memory_mgr *mem; // eax

  mem = cinfo->mem;
  if ( mem != nullptr )
  {
    mem->free_pool(a1: cinfo, a2: 1);
    if ( cinfo->is_decompressor != 0 )
    {
      cinfo->global_state = 200;
      cinfo[11].mem = nullptr;
    }
    else
    {
      cinfo->global_state = 100;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042F8C0
// Name: _jpeg_destroy
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_destroy(jpeg_common_struct *cinfo)
{
  jpeg_memory_mgr *mem; // eax

  mem = cinfo->mem;
  if ( mem != nullptr )
    mem->self_destruct(a1: cinfo);
  cinfo->global_state = 0;
  cinfo->mem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0042F8F0
// Name: _jpeg_alloc_quant_table
// Source: json
//------------------------------------------------------------------------------
JQUANT_TBL *__cdecl jpeg_alloc_quant_table(jpeg_common_struct *cinfo)
{
  JQUANT_TBL *result; // eax

  result = (JQUANT_TBL *)cinfo->mem->alloc_small(a1: cinfo, a2: 0, a3: 130);
  result->sent_table = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042F920
// Name: _jpeg_alloc_huff_table
// Source: json
//------------------------------------------------------------------------------
JHUFF_TBL *__cdecl jpeg_alloc_huff_table(jpeg_common_struct *cinfo)
{
  JHUFF_TBL *result; // eax

  result = (JHUFF_TBL *)cinfo->mem->alloc_small(a1: cinfo, a2: 0, a3: 274);
  result->sent_table = 0;
  return result;
}

} // namespace VXConsole

// ============================================================
// Overlay from vxconsole_ps3 (Missing functions)
// ============================================================
namespace vxconsole_ps3 {

//------------------------------------------------------------------------------
// Address: 0x0041C680
// Name: _jpeg_abort
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_abort(jpeg_common_struct *cinfo)
{
  jpeg_memory_mgr *mem; // eax

  mem = cinfo->mem;
  if ( mem != nullptr )
  {
    mem->free_pool(a1: cinfo, a2: 1);
    if ( cinfo->is_decompressor != 0 )
    {
      cinfo->global_state = 200;
      cinfo[11].mem = nullptr;
    }
    else
    {
      cinfo->global_state = 100;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041C6C0
// Name: _jpeg_destroy
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_destroy(jpeg_common_struct *cinfo)
{
  jpeg_memory_mgr *mem; // eax

  mem = cinfo->mem;
  if ( mem != nullptr )
    mem->self_destruct(a1: cinfo);
  cinfo->global_state = 0;
  cinfo->mem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0041C6F0
// Name: _jpeg_alloc_quant_table
// Source: json
//------------------------------------------------------------------------------
JQUANT_TBL *__cdecl jpeg_alloc_quant_table(jpeg_common_struct *cinfo)
{
  JQUANT_TBL *result; // eax

  result = (JQUANT_TBL *)cinfo->mem->alloc_small(a1: cinfo, a2: 0, a3: 130);
  result->sent_table = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041C720
// Name: _jpeg_alloc_huff_table
// Source: json
//------------------------------------------------------------------------------
JHUFF_TBL *__cdecl jpeg_alloc_huff_table(jpeg_common_struct *cinfo)
{
  JHUFF_TBL *result; // eax

  result = (JHUFF_TBL *)cinfo->mem->alloc_small(a1: cinfo, a2: 0, a3: 274);
  result->sent_table = 0;
  return result;
}

} // namespace vxconsole_ps3

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x102753E0
// Name: _jpeg_abort
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_abort(jpeg_common_struct *cinfo)
{
  jpeg_memory_mgr *mem; // eax

  mem = cinfo->mem;
  if ( mem != nullptr )
  {
    mem->free_pool(a1: cinfo, a2: 1);
    if ( cinfo->is_decompressor != 0 )
    {
      cinfo->global_state = 200;
      cinfo[11].mem = nullptr;
    }
    else
    {
      cinfo->global_state = 100;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10275420
// Name: _jpeg_destroy
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_destroy(jpeg_common_struct *cinfo)
{
  jpeg_memory_mgr *mem; // eax

  mem = cinfo->mem;
  if ( mem != nullptr )
    mem->self_destruct(a1: cinfo);
  cinfo->global_state = 0;
  cinfo->mem = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10275450
// Name: _jpeg_alloc_quant_table
// Source: json
//------------------------------------------------------------------------------
JQUANT_TBL *__cdecl jpeg_alloc_quant_table(jpeg_common_struct *cinfo)
{
  JQUANT_TBL *result; // eax

  result = (JQUANT_TBL *)cinfo->mem->alloc_small(a1: cinfo, a2: 0, a3: 130);
  result->sent_table = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10275480
// Name: _jpeg_alloc_huff_table
// Source: json
//------------------------------------------------------------------------------
JHUFF_TBL *__cdecl jpeg_alloc_huff_table(jpeg_common_struct *cinfo)
{
  JHUFF_TBL *result; // eax

  result = (JHUFF_TBL *)cinfo->mem->alloc_small(a1: cinfo, a2: 0, a3: 274);
  result->sent_table = 0;
  return result;
}

} // namespace client
