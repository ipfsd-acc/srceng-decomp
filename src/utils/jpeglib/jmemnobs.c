// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jmemnobs.c
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10173100
// Name: _jpeg_mem_available
// Source: json
//------------------------------------------------------------------------------
int __cdecl jpeg_mem_available(jpeg_common_struct *cinfo, int min_bytes_needed, int max_bytes_needed)
{
  return max_bytes_needed;
}

//------------------------------------------------------------------------------
// Address: 0x10253270
// Name: _jpeg_free_small
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_free_small(jpeg_common_struct *cinfo, void *object)
{
  free(pMem: object);
}

//------------------------------------------------------------------------------
// Address: 0x10253290
// Name: _jpeg_get_small
// Source: json
//------------------------------------------------------------------------------
void *__cdecl jpeg_get_small(jpeg_common_struct *cinfo, unsigned int sizeofobject)
{
  return MemAlloc_Alloc(nSize: sizeofobject);
}

//------------------------------------------------------------------------------
// Address: 0x102532B0
// Name: _jpeg_open_backing_store
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_open_backing_store(jpeg_common_struct *cinfo)
{
  cinfo->err->msg_code = 49;
  cinfo->err->error_exit(a1: cinfo);
}

// ============================================================
// Overlay from FileSystemOpenDialog (Missing functions)
// ============================================================
namespace FileSystemOpenDialog {

//------------------------------------------------------------------------------
// Address: 0x1000CF50
// Name: _jpeg_free_small
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_free_small(jpeg_common_struct *cinfo, void *object)
{
  free(pMem: object);
}

//------------------------------------------------------------------------------
// Address: 0x1000CF70
// Name: _jpeg_get_small
// Source: json
//------------------------------------------------------------------------------
void *__cdecl jpeg_get_small(jpeg_common_struct *cinfo, unsigned int sizeofobject)
{
  return _malloc_crt(size: sizeofobject);
}

//------------------------------------------------------------------------------
// Address: 0x1000CF90
// Name: _jpeg_mem_available
// Source: json
//------------------------------------------------------------------------------
int __cdecl jpeg_mem_available(jpeg_common_struct *cinfo, int min_bytes_needed, int max_bytes_needed)
{
  return max_bytes_needed;
}

//------------------------------------------------------------------------------
// Address: 0x1000CFA0
// Name: _jpeg_open_backing_store
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_open_backing_store(jpeg_common_struct *cinfo)
{
  cinfo->err->msg_code = 49;
  cinfo->err->error_exit(a1: cinfo);
}

//------------------------------------------------------------------------------
// Address: 0x1000D930
// Name: _jpeg_mem_init
// Source: json
//------------------------------------------------------------------------------
int __cdecl jpeg_mem_init()
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10012730
// Name: _jpeg_mem_term
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_mem_term()
{
  ;
}

} // namespace FileSystemOpenDialog

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102532D0
// Name: _jpeg_mem_available
// Source: json
//------------------------------------------------------------------------------
int __cdecl jpeg_mem_available(jpeg_common_struct *cinfo, int min_bytes_needed, int max_bytes_needed)
{
  return max_bytes_needed;
}

//------------------------------------------------------------------------------
// Address: 0x102532E0
// Name: _jpeg_open_backing_store
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_open_backing_store(jpeg_common_struct *cinfo)
{
  cinfo->err->msg_code = 49;
  cinfo->err->error_exit(a1: cinfo);
}

} // namespace engine_xlsp

// ============================================================
// Overlay from statsmap (Missing functions)
// ============================================================
namespace statsmap {

//------------------------------------------------------------------------------
// Address: 0x00403EF0
// Name: _jpeg_mem_term
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_mem_term()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x004077A0
// Name: _jpeg_free_small
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_free_small(jpeg_common_struct *cinfo, void *object)
{
  free(pMem: object);
}

//------------------------------------------------------------------------------
// Address: 0x004077C0
// Name: _jpeg_get_small
// Source: json
//------------------------------------------------------------------------------
void *__cdecl jpeg_get_small(jpeg_common_struct *cinfo, unsigned int sizeofobject)
{
  return operator new(nSize: sizeofobject);
}

//------------------------------------------------------------------------------
// Address: 0x004077E0
// Name: _jpeg_mem_available
// Source: json
//------------------------------------------------------------------------------
int __cdecl jpeg_mem_available(jpeg_common_struct *cinfo, int min_bytes_needed, int max_bytes_needed)
{
  return max_bytes_needed;
}

//------------------------------------------------------------------------------
// Address: 0x004077F0
// Name: _jpeg_open_backing_store
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_open_backing_store(jpeg_common_struct *cinfo)
{
  cinfo->err->msg_code = 49;
  cinfo->err->error_exit(a1: cinfo);
}

//------------------------------------------------------------------------------
// Address: 0x00407810
// Name: _jpeg_mem_init
// Source: json
//------------------------------------------------------------------------------
int __cdecl jpeg_mem_init()
{
  return 0;
}

} // namespace statsmap

// ============================================================
// Overlay from VXConsole (Missing functions)
// ============================================================
namespace VXConsole {

//------------------------------------------------------------------------------
// Address: 0x00422670
// Name: _jpeg_mem_term
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_mem_term()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00430AB0
// Name: _jpeg_get_small
// Source: json
//------------------------------------------------------------------------------
void *__cdecl jpeg_get_small(jpeg_common_struct *cinfo, unsigned int sizeofobject)
{
  return operator new(nSize: sizeofobject);
}

//------------------------------------------------------------------------------
// Address: 0x00430AD0
// Name: _jpeg_free_small
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_free_small(jpeg_common_struct *cinfo, void *object)
{
  free(pMem: object);
}

//------------------------------------------------------------------------------
// Address: 0x00430AF0
// Name: _jpeg_mem_available
// Source: json
//------------------------------------------------------------------------------
int __cdecl jpeg_mem_available(jpeg_common_struct *cinfo, int min_bytes_needed, int max_bytes_needed)
{
  return max_bytes_needed;
}

//------------------------------------------------------------------------------
// Address: 0x00430B00
// Name: _jpeg_open_backing_store
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_open_backing_store(jpeg_common_struct *cinfo)
{
  cinfo->err->msg_code = 49;
  cinfo->err->error_exit(a1: cinfo);
}

//------------------------------------------------------------------------------
// Address: 0x00430B20
// Name: _jpeg_mem_init
// Source: json
//------------------------------------------------------------------------------
int __cdecl jpeg_mem_init()
{
  return 0;
}

} // namespace VXConsole

// ============================================================
// Overlay from vxconsole_ps3 (Missing functions)
// ============================================================
namespace vxconsole_ps3 {

//------------------------------------------------------------------------------
// Address: 0x0041D8B0
// Name: _jpeg_get_small
// Source: json
//------------------------------------------------------------------------------
void *__cdecl jpeg_get_small(jpeg_common_struct *cinfo, unsigned int sizeofobject)
{
  return operator new(nSize: sizeofobject);
}

//------------------------------------------------------------------------------
// Address: 0x0041D8D0
// Name: _jpeg_free_small
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_free_small(jpeg_common_struct *cinfo, void *object)
{
  free(pMem: object);
}

//------------------------------------------------------------------------------
// Address: 0x0041D8F0
// Name: _jpeg_mem_available
// Source: json
//------------------------------------------------------------------------------
int __cdecl jpeg_mem_available(jpeg_common_struct *cinfo, int min_bytes_needed, int max_bytes_needed)
{
  return max_bytes_needed;
}

//------------------------------------------------------------------------------
// Address: 0x0041D900
// Name: _jpeg_open_backing_store
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_open_backing_store(jpeg_common_struct *cinfo)
{
  cinfo->err->msg_code = 49;
  cinfo->err->error_exit(a1: cinfo);
}

//------------------------------------------------------------------------------
// Address: 0x0041D920
// Name: _jpeg_mem_init
// Source: json
//------------------------------------------------------------------------------
int __cdecl jpeg_mem_init()
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00421450
// Name: _jpeg_mem_term
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_mem_term()
{
  ;
}

} // namespace vxconsole_ps3

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x10275CD0
// Name: _jpeg_get_small
// Source: json
//------------------------------------------------------------------------------
void *__cdecl jpeg_get_small(jpeg_common_struct *cinfo, unsigned int sizeofobject)
{
  return MemAlloc_Alloc(nSize: sizeofobject);
}

//------------------------------------------------------------------------------
// Address: 0x10275CF0
// Name: _jpeg_free_small
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_free_small(jpeg_common_struct *cinfo, void *object)
{
  C_BaseEntity::operator delete(pMem: object);
}

//------------------------------------------------------------------------------
// Address: 0x10275D10
// Name: _jpeg_mem_available
// Source: json
//------------------------------------------------------------------------------
int __cdecl jpeg_mem_available(jpeg_common_struct *cinfo, int min_bytes_needed, int max_bytes_needed)
{
  return max_bytes_needed;
}

//------------------------------------------------------------------------------
// Address: 0x10275D20
// Name: _jpeg_open_backing_store
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_open_backing_store(jpeg_common_struct *cinfo)
{
  cinfo->err->msg_code = 49;
  cinfo->err->error_exit(a1: cinfo);
}

} // namespace client
