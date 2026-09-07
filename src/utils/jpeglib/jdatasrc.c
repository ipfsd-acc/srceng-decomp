// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jdatasrc.c
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10272230
// Name: init_source
// Source: json
//------------------------------------------------------------------------------
void __cdecl init_source(jpeg_decompress_struct *cinfo)
{
  LOBYTE(cinfo->src[1].init_source) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10272240
// Name: fill_input_buffer
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl fill_input_buffer(jpeg_common_struct *cinfo)
{
  jpeg_source_mgr *err; // esi
  unsigned int v2; // eax
  const unsigned __int8 *bytes_in_buffer; // ecx

  err = (jpeg_source_mgr *)cinfo[1].err;
  v2 = fread(
         buffer: (void *)err[1].bytes_in_buffer,
         elementSize: 1u,
         count: 0x1000u,
         stream: (_iobuf *)err[1].next_input_byte);
  if ( v2 == 0 )
  {
    if ( LOBYTE(err[1].init_source) != 0 )
    {
      cinfo->err->msg_code = 42;
      cinfo->err->error_exit(a1: cinfo);
    }
    cinfo->err->msg_code = 120;
    cinfo->err->emit_message(a1: cinfo, a2: -1);
    *(_BYTE *)err[1].bytes_in_buffer = -1;
    *(_BYTE *)(err[1].bytes_in_buffer + 1) = -39;
    v2 = 2;
  }
  bytes_in_buffer = (const unsigned __int8 *)err[1].bytes_in_buffer;
  err->bytes_in_buffer = v2;
  err->next_input_byte = bytes_in_buffer;
  LOBYTE(err[1].init_source) = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102722C0
// Name: skip_input_data
// Source: json
//------------------------------------------------------------------------------
void __cdecl skip_input_data(jpeg_common_struct *cinfo, int num_bytes)
{
  int v2; // ebx
  jpeg_source_mgr *err; // eax
  jpeg_source_mgr *v5; // esi
  unsigned int v6; // eax
  const unsigned __int8 *bytes_in_buffer; // ecx
  my_source_mgr *src; // [esp+10h] [ebp+8h]

  v2 = num_bytes;
  err = (jpeg_source_mgr *)cinfo[1].err;
  src = (my_source_mgr *)err;
  if ( num_bytes > 0 )
  {
    if ( num_bytes > (signed int)err->bytes_in_buffer )
    {
      do
      {
        v5 = (jpeg_source_mgr *)cinfo[1].err;
        v2 -= err->bytes_in_buffer;
        v6 = fread(
               buffer: (void *)v5[1].bytes_in_buffer,
               elementSize: 1u,
               count: 0x1000u,
               stream: (_iobuf *)v5[1].next_input_byte);
        if ( v6 == 0 )
        {
          if ( LOBYTE(v5[1].init_source) != 0 )
          {
            cinfo->err->msg_code = 42;
            cinfo->err->error_exit(a1: cinfo);
          }
          cinfo->err->msg_code = 120;
          cinfo->err->emit_message(a1: cinfo, a2: -1);
          *(_BYTE *)v5[1].bytes_in_buffer = -1;
          *(_BYTE *)(v5[1].bytes_in_buffer + 1) = -39;
          v6 = 2;
        }
        bytes_in_buffer = (const unsigned __int8 *)v5[1].bytes_in_buffer;
        v5->bytes_in_buffer = v6;
        v5->next_input_byte = bytes_in_buffer;
        LOBYTE(v5[1].init_source) = 0;
        err = &src->pub;
      }
      while ( v2 > (signed int)src->pub.bytes_in_buffer );
    }
    err->next_input_byte += v2;
    err->bytes_in_buffer -= v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10272370
// Name: _jpeg_stdio_src
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_stdio_src(jpeg_common_struct *cinfo, _iobuf *infile)
{
  jpeg_source_mgr *v2; // eax
  jpeg_memory_mgr *mem; // edx
  jpeg_source_mgr *err; // eax

  if ( cinfo[1].err == nullptr )
  {
    v2 = (jpeg_source_mgr *)cinfo->mem->alloc_small(a1: cinfo, a2: 0, a3: 40);
    mem = cinfo->mem;
    cinfo[1].err = (jpeg_error_mgr *)v2;
    v2[1].bytes_in_buffer = (int)mem->alloc_small(a1: cinfo, a2: 0, a3: 4096u);
  }
  err = (jpeg_source_mgr *)cinfo[1].err;
  err->init_source = init_source;
  err->fill_input_buffer = (unsigned __int8 (__cdecl *)(jpeg_decompress_struct *))fill_input_buffer;
  err->skip_input_data = (void (__cdecl *)(jpeg_decompress_struct *, int))skip_input_data;
  err->resync_to_restart = jpeg_resync_to_restart;
  err->term_source = (void (__cdecl *)(jpeg_decompress_struct *))C_BaseAnimating::ShutdownBoneSetupThreadPool;
  err[1].next_input_byte = (const unsigned __int8 *)infile;
  err->bytes_in_buffer = 0;
  err->next_input_byte = nullptr;
}
