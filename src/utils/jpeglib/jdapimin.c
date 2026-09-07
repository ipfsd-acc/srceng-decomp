// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jdapimin.c
// Functions: 6
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10009140
// Name: _jpeg_CreateDecompress
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_CreateDecompress(jpeg_common_struct *cinfo, int version, unsigned int structsize)
{
  jpeg_error_mgr *err; // ebx
  void *client_data; // [esp+14h] [ebp+8h]

  cinfo->mem = nullptr;
  if ( version != 62 )
  {
    cinfo->err->msg_code = 12;
    cinfo->err->msg_parm.i[0] = 62;
    cinfo->err->msg_parm.i[1] = version;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( structsize != 432 )
  {
    cinfo->err->msg_code = 21;
    cinfo->err->msg_parm.i[0] = 432;
    cinfo->err->msg_parm.i[1] = structsize;
    cinfo->err->error_exit(a1: cinfo);
  }
  err = cinfo->err;
  client_data = cinfo->client_data;
  memset(dst: (int)cinfo, value: nullptr, count: 0x1B0u);
  cinfo->err = err;
  cinfo->client_data = client_data;
  cinfo->is_decompressor = 1;
  jinit_memory_mgr(cinfo);
  cinfo->progress = nullptr;
  cinfo[1].err = nullptr;
  cinfo[6].err = nullptr;
  cinfo[6].mem = nullptr;
  cinfo[6].progress = nullptr;
  cinfo[6].client_data = nullptr;
  *(_DWORD *)&cinfo[6].is_decompressor = 0;
  cinfo[7].progress = nullptr;
  cinfo[6].global_state = 0;
  cinfo[7].client_data = nullptr;
  cinfo[7].err = nullptr;
  *(_DWORD *)&cinfo[7].is_decompressor = 0;
  cinfo[7].mem = nullptr;
  cinfo[7].global_state = 0;
  cinfo[11].mem = nullptr;
  jinit_marker_reader((jpeg_decompress_struct *)cinfo);
  jinit_input_controller((jpeg_decompress_struct *)cinfo);
  cinfo->global_state = 200;
}

//------------------------------------------------------------------------------
// Address: 0x10009240
// Name: _jpeg_destroy_decompress
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_destroy_decompress(jpeg_common_struct *cinfo)
{
  jpeg_destroy(cinfo);
}

//------------------------------------------------------------------------------
// Address: 0x10009250
// Name: default_decompress_parms
// Source: json
//------------------------------------------------------------------------------
void __usercall default_decompress_parms(jpeg_common_struct *cinfo@<esi>)
{
  jpeg_component_info *mem; // eax
  int component_id; // ecx
  int v3; // edx
  int v4; // edi
  jpeg_error_mgr *err; // eax

  switch ( (unsigned int)cinfo[1].client_data )
  {
    case 1u:
      *(_DWORD *)&cinfo[1].is_decompressor = 1;
      cinfo[1].global_state = 1;
      break;
    case 3u:
      if ( cinfo[10].is_decompressor != 0 )
      {
LABEL_12:
        *(_DWORD *)&cinfo[1].is_decompressor = 3;
        cinfo[1].global_state = 2;
        break;
      }
      if ( LOBYTE(cinfo[11].err) != 0 )
      {
        if ( BYTE1(cinfo[11].err) != 0 )
        {
          if ( BYTE1(cinfo[11].err) != 1 )
          {
            cinfo->err->msg_code = 114;
            cinfo->err->msg_parm.i[0] = BYTE1(cinfo[11].err);
            cinfo->err->emit_message(a1: cinfo, a2: -1);
            *(_DWORD *)&cinfo[1].is_decompressor = 3;
            cinfo[1].global_state = 2;
            break;
          }
          goto LABEL_12;
        }
LABEL_24:
        *(_DWORD *)&cinfo[1].is_decompressor = 2;
        cinfo[1].global_state = 2;
        break;
      }
      mem = (jpeg_component_info *)cinfo[8].mem;
      component_id = mem->component_id;
      v3 = mem[1].component_id;
      v4 = mem[2].component_id;
      if ( mem->component_id == 1 )
      {
        if ( v3 == 2 && v4 == 3 )
        {
          *(_DWORD *)&cinfo[1].is_decompressor = 3;
          cinfo[1].global_state = 2;
          break;
        }
      }
      else if ( component_id == 82 && v3 == 71 && v4 == 66 )
      {
        goto LABEL_24;
      }
      err = cinfo->err;
      err->msg_parm.i[0] = component_id;
      err->msg_parm.i[1] = v3;
      err->msg_parm.i[2] = v4;
      cinfo->err->msg_code = 111;
      cinfo->err->emit_message(a1: cinfo, a2: 1);
      *(_DWORD *)&cinfo[1].is_decompressor = 3;
      cinfo[1].global_state = 2;
      break;
    case 4u:
      if ( LOBYTE(cinfo[11].err) != 0 && BYTE1(cinfo[11].err) != 0 )
      {
        if ( BYTE1(cinfo[11].err) != 2 )
        {
          cinfo->err->msg_code = 114;
          cinfo->err->msg_parm.i[0] = BYTE1(cinfo[11].err);
          cinfo->err->emit_message(a1: cinfo, a2: -1);
        }
        *(_DWORD *)&cinfo[1].is_decompressor = 5;
        cinfo[1].global_state = 4;
      }
      else
      {
        *(_DWORD *)&cinfo[1].is_decompressor = 4;
        cinfo[1].global_state = 4;
      }
      break;
    default:
      *(_DWORD *)&cinfo[1].is_decompressor = 0;
      cinfo[1].global_state = 0;
      break;
  }
  cinfo[2].err = (jpeg_error_mgr *)1;
  cinfo[2].mem = (jpeg_memory_mgr *)1;
  *(_QWORD *)&cinfo[2].progress = 0x3FF0000000000000LL;
  *(_WORD *)&cinfo[2].is_decompressor = 0;
  cinfo[2].global_state = 0;
  LOWORD(cinfo[3].err) = 257;
  BYTE2(cinfo[3].err) = 0;
  cinfo[3].mem = (jpeg_memory_mgr *)2;
  LOBYTE(cinfo[3].progress) = 1;
  cinfo[3].client_data = (void *)256;
  cinfo[4].global_state = 0;
  *(_WORD *)&cinfo[3].is_decompressor = 0;
  *(&cinfo[3].is_decompressor + 2) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10009420
// Name: _jpeg_consume_input
// Source: json
//------------------------------------------------------------------------------
int __cdecl jpeg_consume_input(jpeg_decompress_struct *cinfo)
{
  int v1; // edi
  int result; // eax

  v1 = 0;
  switch ( cinfo->global_state )
  {
    case 0xC8:
      cinfo->inputctl->reset_input_controller(a1: cinfo);
      cinfo->src->init_source(a1: cinfo);
      cinfo->global_state = 201;
      goto $LN5_0;
    case 0xC9:
$LN5_0:
      v1 = cinfo->inputctl->consume_input(a1: cinfo);
      if ( v1 != 1 )
        goto LABEL_8;
      default_decompress_parms((jpeg_common_struct *)cinfo);
      cinfo->global_state = 202;
      result = 1;
      break;
    case 0xCA:
      return 1;
    case 0xCB:
    case 0xCC:
    case 0xCD:
    case 0xCE:
    case 0xCF:
    case 0xD0:
    case 0xD2:
      return cinfo->inputctl->consume_input(a1: cinfo);
    default:
      cinfo->err->msg_code = 20;
      cinfo->err->msg_parm.i[0] = cinfo->global_state;
      cinfo->err->error_exit(a1: (jpeg_common_struct *)cinfo);
LABEL_8:
      result = v1;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100094F0
// Name: _jpeg_finish_decompress
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl jpeg_finish_decompress(jpeg_common_struct *cinfo)
{
  int global_state; // eax

  global_state = cinfo->global_state;
  if ( (global_state == 205 || global_state == 206) && cinfo[2].is_decompressor == 0 )
  {
    if ( cinfo[5].err < cinfo[4].err )
    {
      cinfo->err->msg_code = 67;
      cinfo->err->error_exit(a1: cinfo);
    }
    ((void (__cdecl *)(jpeg_common_struct *))cinfo[16].err->emit_message)(a1: cinfo);
    cinfo->global_state = 210;
  }
  else if ( global_state == 207 )
  {
    cinfo->global_state = 210;
  }
  else if ( global_state != 210 )
  {
    cinfo->err->msg_code = 20;
    cinfo->err->msg_parm.i[0] = cinfo->global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( *(_BYTE *)(*(_DWORD *)&cinfo[16].is_decompressor + 17) != 0 )
  {
LABEL_14:
    ((void (__cdecl *)(jpeg_common_struct *))cinfo[1].err->msg_parm.i[0])(a1: cinfo);
    jpeg_abort(cinfo);
    return 1;
  }
  else
  {
    while ( (**(int (__cdecl ***)(jpeg_common_struct *))&cinfo[16].is_decompressor)(a1: cinfo) != 0 )
    {
      if ( *(_BYTE *)(*(_DWORD *)&cinfo[16].is_decompressor + 17) != 0 )
        goto LABEL_14;
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100095C0
// Name: _jpeg_read_header
// Source: json
//------------------------------------------------------------------------------
int __cdecl jpeg_read_header(jpeg_common_struct *cinfo, unsigned __int8 require_image)
{
  int global_state; // eax
  int result; // eax

  global_state = cinfo->global_state;
  if ( global_state != 200 && global_state != 201 )
  {
    cinfo->err->msg_code = 20;
    cinfo->err->msg_parm.i[0] = cinfo->global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  result = jpeg_consume_input((jpeg_decompress_struct *)cinfo);
  if ( result == 1 )
    return 1;
  if ( result == 2 )
  {
    if ( require_image != 0 )
    {
      cinfo->err->msg_code = 51;
      cinfo->err->error_exit(a1: cinfo);
    }
    jpeg_abort(cinfo);
    return 2;
  }
  return result;
}

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x10271AE0
// Name: _jpeg_CreateDecompress
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_CreateDecompress(jpeg_common_struct *cinfo, int version, unsigned int structsize)
{
  jpeg_error_mgr *err; // ebx
  void *client_data; // [esp+14h] [ebp+8h]

  cinfo->mem = nullptr;
  if ( version != 62 )
  {
    cinfo->err->msg_code = 12;
    cinfo->err->msg_parm.i[0] = 62;
    cinfo->err->msg_parm.i[1] = version;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( structsize != 432 )
  {
    cinfo->err->msg_code = 21;
    cinfo->err->msg_parm.i[0] = 432;
    cinfo->err->msg_parm.i[1] = structsize;
    cinfo->err->error_exit(a1: cinfo);
  }
  err = cinfo->err;
  client_data = cinfo->client_data;
  memset(dst: (int)cinfo, value: nullptr, count: 0x1B0u);
  cinfo->err = err;
  cinfo->client_data = client_data;
  cinfo->is_decompressor = 1;
  jinit_memory_mgr(cinfo);
  cinfo->progress = nullptr;
  cinfo[1].err = nullptr;
  cinfo[6].err = nullptr;
  cinfo[6].mem = nullptr;
  cinfo[6].progress = nullptr;
  cinfo[6].client_data = nullptr;
  *(_DWORD *)&cinfo[6].is_decompressor = 0;
  cinfo[7].progress = nullptr;
  cinfo[6].global_state = 0;
  cinfo[7].client_data = nullptr;
  cinfo[7].err = nullptr;
  *(_DWORD *)&cinfo[7].is_decompressor = 0;
  cinfo[7].mem = nullptr;
  cinfo[7].global_state = 0;
  cinfo[11].mem = nullptr;
  jinit_marker_reader((jpeg_decompress_struct *)cinfo);
  jinit_input_controller((jpeg_decompress_struct *)cinfo);
  cinfo->global_state = 200;
}

//------------------------------------------------------------------------------
// Address: 0x10271BE0
// Name: _jpeg_destroy_decompress
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_destroy_decompress(jpeg_common_struct *cinfo)
{
  jpeg_destroy(cinfo);
}

//------------------------------------------------------------------------------
// Address: 0x10271BF0
// Name: default_decompress_parms
// Source: json
//------------------------------------------------------------------------------
void __usercall default_decompress_parms(jpeg_common_struct *cinfo@<esi>)
{
  jpeg_component_info *mem; // eax
  int component_id; // ecx
  int v3; // edx
  int v4; // edi
  jpeg_error_mgr *err; // eax

  switch ( (unsigned int)cinfo[1].client_data )
  {
    case 1u:
      *(_DWORD *)&cinfo[1].is_decompressor = 1;
      cinfo[1].global_state = 1;
      break;
    case 3u:
      if ( cinfo[10].is_decompressor != 0 )
      {
LABEL_12:
        *(_DWORD *)&cinfo[1].is_decompressor = 3;
        cinfo[1].global_state = 2;
        break;
      }
      if ( LOBYTE(cinfo[11].err) != 0 )
      {
        if ( BYTE1(cinfo[11].err) != 0 )
        {
          if ( BYTE1(cinfo[11].err) != 1 )
          {
            cinfo->err->msg_code = 114;
            cinfo->err->msg_parm.i[0] = BYTE1(cinfo[11].err);
            cinfo->err->emit_message(a1: cinfo, a2: -1);
            *(_DWORD *)&cinfo[1].is_decompressor = 3;
            cinfo[1].global_state = 2;
            break;
          }
          goto LABEL_12;
        }
LABEL_24:
        *(_DWORD *)&cinfo[1].is_decompressor = 2;
        cinfo[1].global_state = 2;
        break;
      }
      mem = (jpeg_component_info *)cinfo[8].mem;
      component_id = mem->component_id;
      v3 = mem[1].component_id;
      v4 = mem[2].component_id;
      if ( mem->component_id == 1 )
      {
        if ( v3 == 2 && v4 == 3 )
        {
          *(_DWORD *)&cinfo[1].is_decompressor = 3;
          cinfo[1].global_state = 2;
          break;
        }
      }
      else if ( component_id == 82 && v3 == 71 && v4 == 66 )
      {
        goto LABEL_24;
      }
      err = cinfo->err;
      err->msg_parm.i[0] = component_id;
      err->msg_parm.i[1] = v3;
      err->msg_parm.i[2] = v4;
      cinfo->err->msg_code = 111;
      cinfo->err->emit_message(a1: cinfo, a2: 1);
      *(_DWORD *)&cinfo[1].is_decompressor = 3;
      cinfo[1].global_state = 2;
      break;
    case 4u:
      if ( LOBYTE(cinfo[11].err) != 0 && BYTE1(cinfo[11].err) != 0 )
      {
        if ( BYTE1(cinfo[11].err) != 2 )
        {
          cinfo->err->msg_code = 114;
          cinfo->err->msg_parm.i[0] = BYTE1(cinfo[11].err);
          cinfo->err->emit_message(a1: cinfo, a2: -1);
        }
        *(_DWORD *)&cinfo[1].is_decompressor = 5;
        cinfo[1].global_state = 4;
      }
      else
      {
        *(_DWORD *)&cinfo[1].is_decompressor = 4;
        cinfo[1].global_state = 4;
      }
      break;
    default:
      *(_DWORD *)&cinfo[1].is_decompressor = 0;
      cinfo[1].global_state = 0;
      break;
  }
  cinfo[2].err = (jpeg_error_mgr *)1;
  cinfo[2].mem = (jpeg_memory_mgr *)1;
  *(_QWORD *)&cinfo[2].progress = 0x3FF0000000000000LL;
  *(_WORD *)&cinfo[2].is_decompressor = 0;
  cinfo[2].global_state = 0;
  LOWORD(cinfo[3].err) = 257;
  BYTE2(cinfo[3].err) = 0;
  cinfo[3].mem = (jpeg_memory_mgr *)2;
  LOBYTE(cinfo[3].progress) = 1;
  cinfo[3].client_data = (void *)256;
  cinfo[4].global_state = 0;
  *(_WORD *)&cinfo[3].is_decompressor = 0;
  *(&cinfo[3].is_decompressor + 2) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10271DC0
// Name: _jpeg_consume_input
// Source: json
//------------------------------------------------------------------------------
int __cdecl jpeg_consume_input(jpeg_decompress_struct *cinfo)
{
  int v1; // edi
  int result; // eax

  v1 = 0;
  switch ( cinfo->global_state )
  {
    case 0xC8:
      cinfo->inputctl->reset_input_controller(a1: cinfo);
      cinfo->src->init_source(a1: cinfo);
      cinfo->global_state = 201;
      goto $LN5_42;
    case 0xC9:
$LN5_42:
      v1 = cinfo->inputctl->consume_input(a1: cinfo);
      if ( v1 != 1 )
        goto LABEL_8;
      default_decompress_parms((jpeg_common_struct *)cinfo);
      cinfo->global_state = 202;
      result = 1;
      break;
    case 0xCA:
      return 1;
    case 0xCB:
    case 0xCC:
    case 0xCD:
    case 0xCE:
    case 0xCF:
    case 0xD0:
    case 0xD2:
      return cinfo->inputctl->consume_input(a1: cinfo);
    default:
      cinfo->err->msg_code = 20;
      cinfo->err->msg_parm.i[0] = cinfo->global_state;
      cinfo->err->error_exit(a1: (jpeg_common_struct *)cinfo);
LABEL_8:
      result = v1;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10271E90
// Name: _jpeg_finish_decompress
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __cdecl jpeg_finish_decompress(jpeg_common_struct *cinfo)
{
  int global_state; // eax

  global_state = cinfo->global_state;
  if ( (global_state == 205 || global_state == 206) && cinfo[2].is_decompressor == 0 )
  {
    if ( cinfo[5].err < cinfo[4].err )
    {
      cinfo->err->msg_code = 67;
      cinfo->err->error_exit(a1: cinfo);
    }
    ((void (__cdecl *)(jpeg_common_struct *))cinfo[16].err->emit_message)(a1: cinfo);
    cinfo->global_state = 210;
  }
  else if ( global_state == 207 )
  {
    cinfo->global_state = 210;
  }
  else if ( global_state != 210 )
  {
    cinfo->err->msg_code = 20;
    cinfo->err->msg_parm.i[0] = cinfo->global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  if ( *(_BYTE *)(*(_DWORD *)&cinfo[16].is_decompressor + 17) != 0 )
  {
LABEL_14:
    ((void (__cdecl *)(jpeg_common_struct *))cinfo[1].err->msg_parm.i[0])(a1: cinfo);
    jpeg_abort(cinfo);
    return 1;
  }
  else
  {
    while ( (**(int (__cdecl ***)(jpeg_common_struct *))&cinfo[16].is_decompressor)(a1: cinfo) != 0 )
    {
      if ( *(_BYTE *)(*(_DWORD *)&cinfo[16].is_decompressor + 17) != 0 )
        goto LABEL_14;
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10271F60
// Name: _jpeg_read_header
// Source: json
//------------------------------------------------------------------------------
int __cdecl jpeg_read_header(jpeg_common_struct *cinfo, unsigned __int8 require_image)
{
  int global_state; // eax
  int result; // eax

  global_state = cinfo->global_state;
  if ( global_state != 200 && global_state != 201 )
  {
    cinfo->err->msg_code = 20;
    cinfo->err->msg_parm.i[0] = cinfo->global_state;
    cinfo->err->error_exit(a1: cinfo);
  }
  result = jpeg_consume_input((jpeg_decompress_struct *)cinfo);
  if ( result == 1 )
    return 1;
  if ( result == 2 )
  {
    if ( require_image != 0 )
    {
      cinfo->err->msg_code = 51;
      cinfo->err->error_exit(a1: cinfo);
    }
    jpeg_abort(cinfo);
    return 2;
  }
  return result;
}

} // namespace client
