// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jerror.c
// Functions: 6
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10251120
// Name: error_exit
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn error_exit(jpeg_common_struct *cinfo)
{
  cinfo->err->output_message(a1: cinfo);
  jpeg_destroy(cinfo);
  exit(code: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10251140
// Name: output_message
// Source: json
//------------------------------------------------------------------------------
void __cdecl output_message(jpeg_common_struct *cinfo)
{
  _iobuf *v1; // eax
  char buffer[200]; // [esp+0h] [ebp-C8h] BYREF

  cinfo->err->format_message(a1: cinfo, a2: buffer);
  v1 = __iob_func();
  fprintf(str: v1 + 2, format: "%s\n", buffer);
}

//------------------------------------------------------------------------------
// Address: 0x10251180
// Name: emit_message
// Source: json
//------------------------------------------------------------------------------
void __cdecl emit_message(jpeg_common_struct *cinfo, int msg_level)
{
  jpeg_error_mgr *err; // esi

  err = cinfo->err;
  if ( msg_level >= 0 )
  {
    if ( err->trace_level >= msg_level )
      err->output_message(a1: cinfo);
  }
  else
  {
    if ( err->num_warnings == 0 || err->trace_level >= 3 )
      err->output_message(a1: cinfo);
    ++err->num_warnings;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102511C0
// Name: format_message
// Source: json
//------------------------------------------------------------------------------
void __cdecl format_message(jpeg_common_struct *cinfo, char *buffer)
{
  jpeg_error_mgr *err; // eax
  int msg_code; // ecx
  const char *v4; // esi
  const char *const *addon_message_table; // esi
  int first_addon_message; // edx
  char v7; // cl
  char *v8; // edx

  err = cinfo->err;
  msg_code = cinfo->err->msg_code;
  if ( msg_code <= 0 || msg_code > err->last_jpeg_message )
  {
    addon_message_table = err->addon_message_table;
    if ( addon_message_table == nullptr )
      goto LABEL_9;
    first_addon_message = err->first_addon_message;
    if ( msg_code < first_addon_message || msg_code > err->last_addon_message )
      goto LABEL_9;
    v4 = addon_message_table[msg_code - first_addon_message];
  }
  else
  {
    v4 = err->jpeg_message_table[msg_code];
  }
  if ( v4 == nullptr )
  {
LABEL_9:
    err->msg_parm.i[0] = msg_code;
    v4 = *err->jpeg_message_table;
  }
  v7 = *v4;
  v8 = (char *)v4;
  if ( *v4 == 0 )
    goto LABEL_13;
  while ( 1 )
  {
    ++v8;
    if ( v7 == 37 )
      break;
    v7 = *v8;
    if ( *v8 == 0 )
      goto LABEL_13;
  }
  if ( *v8 == 115 )
    sprintf(string: buffer, format: v4, &err->msg_parm);
  else
LABEL_13:
    sprintf(
      string: buffer,
      format: v4,
      err->msg_parm.i[0],
      err->msg_parm.i[1],
      err->msg_parm.i[2],
      err->msg_parm.i[3],
      err->msg_parm.i[4],
      err->msg_parm.i[5],
      err->msg_parm.i[6],
      err->msg_parm.i[7]);
}

//------------------------------------------------------------------------------
// Address: 0x10251270
// Name: reset_error_mgr
// Source: json
//------------------------------------------------------------------------------
void __cdecl reset_error_mgr(jpeg_common_struct *cinfo)
{
  cinfo->err->num_warnings = 0;
  cinfo->err->msg_code = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10251290
// Name: _jpeg_std_error
// Source: json
//------------------------------------------------------------------------------
jpeg_error_mgr *__cdecl jpeg_std_error(jpeg_error_mgr *err)
{
  err->error_exit = (void (__cdecl *)(jpeg_common_struct *))error_exit;
  err->emit_message = emit_message;
  err->output_message = output_message;
  err->format_message = format_message;
  err->reset_error_mgr = reset_error_mgr;
  err->trace_level = 0;
  err->num_warnings = 0;
  err->msg_code = 0;
  err->jpeg_message_table = jpeg_std_message_table;
  err->last_jpeg_message = 123;
  err->addon_message_table = nullptr;
  err->first_addon_message = 0;
  err->last_addon_message = 0;
  return err;
}

// ============================================================
// Overlay from FileSystemOpenDialog (Missing functions)
// ============================================================
namespace FileSystemOpenDialog {

//------------------------------------------------------------------------------
// Address: 0x10009890
// Name: error_exit
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn error_exit(jpeg_common_struct *cinfo)
{
  cinfo->err->output_message(a1: cinfo);
  jpeg_destroy(cinfo);
  exit(code: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100098B0
// Name: output_message
// Source: json
//------------------------------------------------------------------------------
void __cdecl output_message(jpeg_common_struct *cinfo)
{
  _iobuf *v1; // eax
  char buffer[200]; // [esp+0h] [ebp-C8h] BYREF

  cinfo->err->format_message(a1: cinfo, a2: buffer);
  v1 = __iob_func();
  fprintf(str: v1 + 2, format: "%s\n", buffer);
}

//------------------------------------------------------------------------------
// Address: 0x100098F0
// Name: emit_message
// Source: json
//------------------------------------------------------------------------------
void __cdecl emit_message(jpeg_common_struct *cinfo, int msg_level)
{
  jpeg_error_mgr *err; // esi

  err = cinfo->err;
  if ( msg_level >= 0 )
  {
    if ( err->trace_level >= msg_level )
      err->output_message(a1: cinfo);
  }
  else
  {
    if ( err->num_warnings == 0 || err->trace_level >= 3 )
      err->output_message(a1: cinfo);
    ++err->num_warnings;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009930
// Name: format_message
// Source: json
//------------------------------------------------------------------------------
void __cdecl format_message(jpeg_common_struct *cinfo, char *buffer)
{
  jpeg_error_mgr *err; // eax
  int msg_code; // ecx
  const char *v4; // esi
  const char *const *addon_message_table; // esi
  int first_addon_message; // edx
  char v7; // cl
  char *v8; // edx

  err = cinfo->err;
  msg_code = cinfo->err->msg_code;
  if ( msg_code <= 0 || msg_code > err->last_jpeg_message )
  {
    addon_message_table = err->addon_message_table;
    if ( addon_message_table == nullptr )
      goto LABEL_9;
    first_addon_message = err->first_addon_message;
    if ( msg_code < first_addon_message || msg_code > err->last_addon_message )
      goto LABEL_9;
    v4 = addon_message_table[msg_code - first_addon_message];
  }
  else
  {
    v4 = err->jpeg_message_table[msg_code];
  }
  if ( v4 == nullptr )
  {
LABEL_9:
    err->msg_parm.i[0] = msg_code;
    v4 = *err->jpeg_message_table;
  }
  v7 = *v4;
  v8 = (char *)v4;
  if ( *v4 == 0 )
    goto LABEL_13;
  while ( 1 )
  {
    ++v8;
    if ( v7 == 37 )
      break;
    v7 = *v8;
    if ( *v8 == 0 )
      goto LABEL_13;
  }
  if ( *v8 == 115 )
    sprintf(string: buffer, format: v4, &err->msg_parm);
  else
LABEL_13:
    sprintf(
      string: buffer,
      format: v4,
      err->msg_parm.i[0],
      err->msg_parm.i[1],
      err->msg_parm.i[2],
      err->msg_parm.i[3],
      err->msg_parm.i[4],
      err->msg_parm.i[5],
      err->msg_parm.i[6],
      err->msg_parm.i[7]);
}

//------------------------------------------------------------------------------
// Address: 0x100099E0
// Name: reset_error_mgr
// Source: json
//------------------------------------------------------------------------------
void __cdecl reset_error_mgr(jpeg_common_struct *cinfo)
{
  cinfo->err->num_warnings = 0;
  cinfo->err->msg_code = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10009A00
// Name: _jpeg_std_error
// Source: json
//------------------------------------------------------------------------------
jpeg_error_mgr *__cdecl jpeg_std_error(jpeg_error_mgr *err)
{
  err->error_exit = (void (__cdecl *)(jpeg_common_struct *))error_exit;
  err->emit_message = emit_message;
  err->output_message = output_message;
  err->format_message = format_message;
  err->reset_error_mgr = reset_error_mgr;
  err->trace_level = 0;
  err->num_warnings = 0;
  err->msg_code = 0;
  err->jpeg_message_table = jpeg_std_message_table;
  err->last_jpeg_message = 123;
  err->addon_message_table = nullptr;
  err->first_addon_message = 0;
  err->last_addon_message = 0;
  return err;
}

} // namespace FileSystemOpenDialog

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10251160
// Name: output_message
// Source: json
//------------------------------------------------------------------------------
void __cdecl output_message(jpeg_common_struct *cinfo)
{
  _iobuf *v1; // eax
  char buffer[200]; // [esp+0h] [ebp-C8h] BYREF

  cinfo->err->format_message(a1: cinfo, a2: buffer);
  v1 = __iob_func();
  fprintf(str: v1 + 2, format: "%s\n", buffer);
}

//------------------------------------------------------------------------------
// Address: 0x102511A0
// Name: emit_message
// Source: json
//------------------------------------------------------------------------------
void __cdecl emit_message(jpeg_common_struct *cinfo, int msg_level)
{
  jpeg_error_mgr *err; // esi

  err = cinfo->err;
  if ( msg_level >= 0 )
  {
    if ( err->trace_level >= msg_level )
      err->output_message(a1: cinfo);
  }
  else
  {
    if ( err->num_warnings == 0 || err->trace_level >= 3 )
      err->output_message(a1: cinfo);
    ++err->num_warnings;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102511E0
// Name: format_message
// Source: json
//------------------------------------------------------------------------------
void __cdecl format_message(jpeg_common_struct *cinfo, char *buffer)
{
  jpeg_error_mgr *err; // eax
  int msg_code; // ecx
  const char *v4; // esi
  const char *const *addon_message_table; // esi
  int first_addon_message; // edx
  char v7; // cl
  char *v8; // edx

  err = cinfo->err;
  msg_code = cinfo->err->msg_code;
  if ( msg_code <= 0 || msg_code > err->last_jpeg_message )
  {
    addon_message_table = err->addon_message_table;
    if ( addon_message_table == nullptr )
      goto LABEL_9;
    first_addon_message = err->first_addon_message;
    if ( msg_code < first_addon_message || msg_code > err->last_addon_message )
      goto LABEL_9;
    v4 = addon_message_table[msg_code - first_addon_message];
  }
  else
  {
    v4 = err->jpeg_message_table[msg_code];
  }
  if ( v4 == nullptr )
  {
LABEL_9:
    err->msg_parm.i[0] = msg_code;
    v4 = *err->jpeg_message_table;
  }
  v7 = *v4;
  v8 = (char *)v4;
  if ( *v4 == 0 )
    goto LABEL_13;
  while ( 1 )
  {
    ++v8;
    if ( v7 == 37 )
      break;
    v7 = *v8;
    if ( *v8 == 0 )
      goto LABEL_13;
  }
  if ( *v8 == 115 )
    sprintf(string: buffer, format: v4, &err->msg_parm);
  else
LABEL_13:
    sprintf(
      string: buffer,
      format: v4,
      err->msg_parm.i[0],
      err->msg_parm.i[1],
      err->msg_parm.i[2],
      err->msg_parm.i[3],
      err->msg_parm.i[4],
      err->msg_parm.i[5],
      err->msg_parm.i[6],
      err->msg_parm.i[7]);
}

//------------------------------------------------------------------------------
// Address: 0x102512B0
// Name: _jpeg_std_error
// Source: json
//------------------------------------------------------------------------------
jpeg_error_mgr *__cdecl jpeg_std_error(jpeg_error_mgr *err)
{
  err->error_exit = error_exit;
  err->emit_message = emit_message;
  err->output_message = output_message;
  err->format_message = format_message;
  err->reset_error_mgr = reset_error_mgr;
  err->trace_level = 0;
  err->num_warnings = 0;
  err->msg_code = 0;
  err->jpeg_message_table = jpeg_std_message_table;
  err->last_jpeg_message = 123;
  err->addon_message_table = nullptr;
  err->first_addon_message = 0;
  err->last_addon_message = 0;
  return err;
}

} // namespace engine_xlsp

// ============================================================
// Overlay from statsmap (Missing functions)
// ============================================================
namespace statsmap {

//------------------------------------------------------------------------------
// Address: 0x00405650
// Name: error_exit
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn error_exit(jpeg_common_struct *cinfo)
{
  cinfo->err->output_message(a1: cinfo);
  jpeg_destroy(cinfo);
  exit(code: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00405670
// Name: output_message
// Source: json
//------------------------------------------------------------------------------
void __cdecl output_message(jpeg_common_struct *cinfo)
{
  _iobuf *v1; // eax
  char buffer[200]; // [esp+0h] [ebp-C8h] BYREF

  cinfo->err->format_message(a1: cinfo, a2: buffer);
  v1 = __iob_func();
  fprintf(str: v1 + 2, format: "%s\n", buffer);
}

//------------------------------------------------------------------------------
// Address: 0x004056B0
// Name: emit_message
// Source: json
//------------------------------------------------------------------------------
void __cdecl emit_message(jpeg_common_struct *cinfo, int msg_level)
{
  jpeg_error_mgr *err; // esi

  err = cinfo->err;
  if ( msg_level >= 0 )
  {
    if ( err->trace_level >= msg_level )
      err->output_message(a1: cinfo);
  }
  else
  {
    if ( err->num_warnings == 0 || err->trace_level >= 3 )
      err->output_message(a1: cinfo);
    ++err->num_warnings;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004056F0
// Name: format_message
// Source: json
//------------------------------------------------------------------------------
void __cdecl format_message(jpeg_common_struct *cinfo, char *buffer)
{
  jpeg_error_mgr *err; // eax
  int msg_code; // ecx
  const char *v4; // esi
  const char *const *addon_message_table; // esi
  int first_addon_message; // edx
  char v7; // cl
  char *v8; // edx

  err = cinfo->err;
  msg_code = cinfo->err->msg_code;
  if ( msg_code <= 0 || msg_code > err->last_jpeg_message )
  {
    addon_message_table = err->addon_message_table;
    if ( addon_message_table == nullptr )
      goto LABEL_9;
    first_addon_message = err->first_addon_message;
    if ( msg_code < first_addon_message || msg_code > err->last_addon_message )
      goto LABEL_9;
    v4 = addon_message_table[msg_code - first_addon_message];
  }
  else
  {
    v4 = err->jpeg_message_table[msg_code];
  }
  if ( v4 == nullptr )
  {
LABEL_9:
    err->msg_parm.i[0] = msg_code;
    v4 = *err->jpeg_message_table;
  }
  v7 = *v4;
  v8 = (char *)v4;
  if ( *v4 == 0 )
    goto LABEL_13;
  while ( 1 )
  {
    ++v8;
    if ( v7 == 37 )
      break;
    v7 = *v8;
    if ( *v8 == 0 )
      goto LABEL_13;
  }
  if ( *v8 == 115 )
    sprintf(string: buffer, format: v4, &err->msg_parm);
  else
LABEL_13:
    sprintf(
      string: buffer,
      format: v4,
      err->msg_parm.i[0],
      err->msg_parm.i[1],
      err->msg_parm.i[2],
      err->msg_parm.i[3],
      err->msg_parm.i[4],
      err->msg_parm.i[5],
      err->msg_parm.i[6],
      err->msg_parm.i[7]);
}

//------------------------------------------------------------------------------
// Address: 0x004057A0
// Name: reset_error_mgr
// Source: json
//------------------------------------------------------------------------------
void __cdecl reset_error_mgr(jpeg_common_struct *cinfo)
{
  cinfo->err->num_warnings = 0;
  cinfo->err->msg_code = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004057C0
// Name: _jpeg_std_error
// Source: json
//------------------------------------------------------------------------------
jpeg_error_mgr *__cdecl jpeg_std_error(jpeg_error_mgr *err)
{
  err->error_exit = (void (__cdecl *)(jpeg_common_struct *))error_exit;
  err->emit_message = emit_message;
  err->output_message = output_message;
  err->format_message = format_message;
  err->reset_error_mgr = reset_error_mgr;
  err->trace_level = 0;
  err->num_warnings = 0;
  err->msg_code = 0;
  err->jpeg_message_table = jpeg_std_message_table;
  err->last_jpeg_message = 123;
  err->addon_message_table = nullptr;
  err->first_addon_message = 0;
  err->last_addon_message = 0;
  return err;
}

} // namespace statsmap

// ============================================================
// Overlay from VXConsole (Missing functions)
// ============================================================
namespace VXConsole {

//------------------------------------------------------------------------------
// Address: 0x0042E960
// Name: error_exit
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn error_exit(jpeg_common_struct *cinfo)
{
  cinfo->err->output_message(a1: cinfo);
  jpeg_destroy(cinfo);
  exit(code: 1);
}

//------------------------------------------------------------------------------
// Address: 0x0042E980
// Name: output_message
// Source: json
//------------------------------------------------------------------------------
void __cdecl output_message(jpeg_common_struct *cinfo)
{
  _iobuf *v1; // eax
  char buffer[200]; // [esp+0h] [ebp-C8h] BYREF

  cinfo->err->format_message(a1: cinfo, a2: buffer);
  v1 = __iob_func();
  fprintf(str: v1 + 2, format: "%s\n", buffer);
}

//------------------------------------------------------------------------------
// Address: 0x0042E9C0
// Name: emit_message
// Source: json
//------------------------------------------------------------------------------
void __cdecl emit_message(jpeg_common_struct *cinfo, int msg_level)
{
  jpeg_error_mgr *err; // esi

  err = cinfo->err;
  if ( msg_level >= 0 )
  {
    if ( err->trace_level >= msg_level )
      err->output_message(a1: cinfo);
  }
  else
  {
    if ( err->num_warnings == 0 || err->trace_level >= 3 )
      err->output_message(a1: cinfo);
    ++err->num_warnings;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042EA00
// Name: format_message
// Source: json
//------------------------------------------------------------------------------
void __cdecl format_message(jpeg_common_struct *cinfo, char *buffer)
{
  jpeg_error_mgr *err; // eax
  int msg_code; // ecx
  const char *v4; // esi
  const char *const *addon_message_table; // esi
  int first_addon_message; // edx
  char v7; // cl
  char *v8; // edx

  err = cinfo->err;
  msg_code = cinfo->err->msg_code;
  if ( msg_code <= 0 || msg_code > err->last_jpeg_message )
  {
    addon_message_table = err->addon_message_table;
    if ( addon_message_table == nullptr )
      goto LABEL_9;
    first_addon_message = err->first_addon_message;
    if ( msg_code < first_addon_message || msg_code > err->last_addon_message )
      goto LABEL_9;
    v4 = addon_message_table[msg_code - first_addon_message];
  }
  else
  {
    v4 = err->jpeg_message_table[msg_code];
  }
  if ( v4 == nullptr )
  {
LABEL_9:
    err->msg_parm.i[0] = msg_code;
    v4 = *err->jpeg_message_table;
  }
  v7 = *v4;
  v8 = (char *)v4;
  if ( *v4 == 0 )
    goto LABEL_13;
  while ( 1 )
  {
    ++v8;
    if ( v7 == 37 )
      break;
    v7 = *v8;
    if ( *v8 == 0 )
      goto LABEL_13;
  }
  if ( *v8 == 115 )
    sprintf(string: buffer, format: v4, &err->msg_parm);
  else
LABEL_13:
    sprintf(
      string: buffer,
      format: v4,
      err->msg_parm.i[0],
      err->msg_parm.i[1],
      err->msg_parm.i[2],
      err->msg_parm.i[3],
      err->msg_parm.i[4],
      err->msg_parm.i[5],
      err->msg_parm.i[6],
      err->msg_parm.i[7]);
}

//------------------------------------------------------------------------------
// Address: 0x0042EAB0
// Name: reset_error_mgr
// Source: json
//------------------------------------------------------------------------------
void __cdecl reset_error_mgr(jpeg_common_struct *cinfo)
{
  cinfo->err->num_warnings = 0;
  cinfo->err->msg_code = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042EAD0
// Name: _jpeg_std_error
// Source: json
//------------------------------------------------------------------------------
jpeg_error_mgr *__cdecl jpeg_std_error(jpeg_error_mgr *err)
{
  err->error_exit = (void (__cdecl *)(jpeg_common_struct *))error_exit;
  err->emit_message = emit_message;
  err->output_message = output_message;
  err->format_message = format_message;
  err->reset_error_mgr = reset_error_mgr;
  err->trace_level = 0;
  err->num_warnings = 0;
  err->msg_code = 0;
  err->jpeg_message_table = jpeg_std_message_table;
  err->last_jpeg_message = 123;
  err->addon_message_table = nullptr;
  err->first_addon_message = 0;
  err->last_addon_message = 0;
  return err;
}

} // namespace VXConsole

// ============================================================
// Overlay from vxconsole_ps3 (Missing functions)
// ============================================================
namespace vxconsole_ps3 {

//------------------------------------------------------------------------------
// Address: 0x0041B760
// Name: error_exit
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn error_exit(jpeg_common_struct *cinfo)
{
  cinfo->err->output_message(a1: cinfo);
  jpeg_destroy(cinfo);
  exit(code: 1);
}

//------------------------------------------------------------------------------
// Address: 0x0041B780
// Name: output_message
// Source: json
//------------------------------------------------------------------------------
void __cdecl output_message(jpeg_common_struct *cinfo)
{
  _iobuf *v1; // eax
  char buffer[200]; // [esp+0h] [ebp-C8h] BYREF

  cinfo->err->format_message(a1: cinfo, a2: buffer);
  v1 = __iob_func();
  fprintf(str: v1 + 2, format: "%s\n", buffer);
}

//------------------------------------------------------------------------------
// Address: 0x0041B7C0
// Name: emit_message
// Source: json
//------------------------------------------------------------------------------
void __cdecl emit_message(jpeg_common_struct *cinfo, int msg_level)
{
  jpeg_error_mgr *err; // esi

  err = cinfo->err;
  if ( msg_level >= 0 )
  {
    if ( err->trace_level >= msg_level )
      err->output_message(a1: cinfo);
  }
  else
  {
    if ( err->num_warnings == 0 || err->trace_level >= 3 )
      err->output_message(a1: cinfo);
    ++err->num_warnings;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B800
// Name: format_message
// Source: json
//------------------------------------------------------------------------------
void __cdecl format_message(jpeg_common_struct *cinfo, char *buffer)
{
  jpeg_error_mgr *err; // eax
  int msg_code; // ecx
  const char *v4; // esi
  const char *const *addon_message_table; // esi
  int first_addon_message; // edx
  char v7; // cl
  char *v8; // edx

  err = cinfo->err;
  msg_code = cinfo->err->msg_code;
  if ( msg_code <= 0 || msg_code > err->last_jpeg_message )
  {
    addon_message_table = err->addon_message_table;
    if ( addon_message_table == nullptr )
      goto LABEL_9;
    first_addon_message = err->first_addon_message;
    if ( msg_code < first_addon_message || msg_code > err->last_addon_message )
      goto LABEL_9;
    v4 = addon_message_table[msg_code - first_addon_message];
  }
  else
  {
    v4 = err->jpeg_message_table[msg_code];
  }
  if ( v4 == nullptr )
  {
LABEL_9:
    err->msg_parm.i[0] = msg_code;
    v4 = *err->jpeg_message_table;
  }
  v7 = *v4;
  v8 = (char *)v4;
  if ( *v4 == 0 )
    goto LABEL_13;
  while ( 1 )
  {
    ++v8;
    if ( v7 == 37 )
      break;
    v7 = *v8;
    if ( *v8 == 0 )
      goto LABEL_13;
  }
  if ( *v8 == 115 )
    sprintf(string: buffer, format: v4, &err->msg_parm);
  else
LABEL_13:
    sprintf(
      string: buffer,
      format: v4,
      err->msg_parm.i[0],
      err->msg_parm.i[1],
      err->msg_parm.i[2],
      err->msg_parm.i[3],
      err->msg_parm.i[4],
      err->msg_parm.i[5],
      err->msg_parm.i[6],
      err->msg_parm.i[7]);
}

//------------------------------------------------------------------------------
// Address: 0x0041B8B0
// Name: reset_error_mgr
// Source: json
//------------------------------------------------------------------------------
void __cdecl reset_error_mgr(jpeg_common_struct *cinfo)
{
  cinfo->err->num_warnings = 0;
  cinfo->err->msg_code = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041B8D0
// Name: _jpeg_std_error
// Source: json
//------------------------------------------------------------------------------
jpeg_error_mgr *__cdecl jpeg_std_error(jpeg_error_mgr *err)
{
  err->error_exit = (void (__cdecl *)(jpeg_common_struct *))error_exit;
  err->emit_message = emit_message;
  err->output_message = output_message;
  err->format_message = format_message;
  err->reset_error_mgr = reset_error_mgr;
  err->trace_level = 0;
  err->num_warnings = 0;
  err->msg_code = 0;
  err->jpeg_message_table = jpeg_std_message_table;
  err->last_jpeg_message = 123;
  err->addon_message_table = nullptr;
  err->first_addon_message = 0;
  err->last_addon_message = 0;
  return err;
}

} // namespace vxconsole_ps3

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x102723F0
// Name: error_exit
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn error_exit(jpeg_common_struct *cinfo)
{
  cinfo->err->output_message(a1: cinfo);
  jpeg_destroy(cinfo);
  exit(code: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10272410
// Name: output_message
// Source: json
//------------------------------------------------------------------------------
void __cdecl output_message(jpeg_common_struct *cinfo)
{
  _iobuf *v1; // eax
  char buffer[200]; // [esp+0h] [ebp-C8h] BYREF

  cinfo->err->format_message(a1: cinfo, a2: buffer);
  v1 = __iob_func();
  fprintf(str: v1 + 2, format: "%s\n", buffer);
}

//------------------------------------------------------------------------------
// Address: 0x10272450
// Name: emit_message
// Source: json
//------------------------------------------------------------------------------
void __cdecl emit_message(jpeg_common_struct *cinfo, int msg_level)
{
  jpeg_error_mgr *err; // esi

  err = cinfo->err;
  if ( msg_level >= 0 )
  {
    if ( err->trace_level >= msg_level )
      err->output_message(a1: cinfo);
  }
  else
  {
    if ( err->num_warnings == 0 || err->trace_level >= 3 )
      err->output_message(a1: cinfo);
    ++err->num_warnings;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10272490
// Name: format_message
// Source: json
//------------------------------------------------------------------------------
void __cdecl format_message(jpeg_common_struct *cinfo, char *buffer)
{
  jpeg_error_mgr *err; // eax
  int msg_code; // ecx
  const char *v4; // esi
  const char *const *addon_message_table; // esi
  int first_addon_message; // edx
  char v7; // cl
  char *v8; // edx

  err = cinfo->err;
  msg_code = cinfo->err->msg_code;
  if ( msg_code <= 0 || msg_code > err->last_jpeg_message )
  {
    addon_message_table = err->addon_message_table;
    if ( addon_message_table == nullptr )
      goto LABEL_9;
    first_addon_message = err->first_addon_message;
    if ( msg_code < first_addon_message || msg_code > err->last_addon_message )
      goto LABEL_9;
    v4 = addon_message_table[msg_code - first_addon_message];
  }
  else
  {
    v4 = err->jpeg_message_table[msg_code];
  }
  if ( v4 == nullptr )
  {
LABEL_9:
    err->msg_parm.i[0] = msg_code;
    v4 = *err->jpeg_message_table;
  }
  v7 = *v4;
  v8 = (char *)v4;
  if ( *v4 == 0 )
    goto LABEL_13;
  while ( 1 )
  {
    ++v8;
    if ( v7 == 37 )
      break;
    v7 = *v8;
    if ( *v8 == 0 )
      goto LABEL_13;
  }
  if ( *v8 == 115 )
    sprintf(string: buffer, format: v4, &err->msg_parm);
  else
LABEL_13:
    sprintf(
      string: buffer,
      format: v4,
      err->msg_parm.i[0],
      err->msg_parm.i[1],
      err->msg_parm.i[2],
      err->msg_parm.i[3],
      err->msg_parm.i[4],
      err->msg_parm.i[5],
      err->msg_parm.i[6],
      err->msg_parm.i[7]);
}

//------------------------------------------------------------------------------
// Address: 0x10272540
// Name: reset_error_mgr
// Source: json
//------------------------------------------------------------------------------
void __cdecl reset_error_mgr(jpeg_common_struct *cinfo)
{
  cinfo->err->num_warnings = 0;
  cinfo->err->msg_code = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10272560
// Name: _jpeg_std_error
// Source: json
//------------------------------------------------------------------------------
jpeg_error_mgr *__cdecl jpeg_std_error(jpeg_error_mgr *err)
{
  err->error_exit = (void (__cdecl *)(jpeg_common_struct *))error_exit;
  err->emit_message = emit_message;
  err->output_message = output_message;
  err->format_message = format_message;
  err->reset_error_mgr = reset_error_mgr;
  err->trace_level = 0;
  err->num_warnings = 0;
  err->msg_code = 0;
  err->jpeg_message_table = jpeg_std_message_table;
  err->last_jpeg_message = 123;
  err->addon_message_table = nullptr;
  err->first_addon_message = 0;
  err->last_addon_message = 0;
  return err;
}

} // namespace client
