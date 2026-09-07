// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/dt_utlvector_common.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100D0530
// Name: char __near * AllocateStringHelper(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
char *AllocateStringHelper(const char *pFormat, ...)
{
  unsigned int v1; // kr00_4
  unsigned __int8 *v2; // edi
  char string[512]; // [esp+0h] [ebp-200h] BYREF
  va_list ap; // [esp+20Ch] [ebp+Ch] BYREF

  va_start(ap, pFormat);
  _vsnprintf(string, count: 0x200u, format: pFormat, ap);
  v1 = strlen(string);
  v2 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v1 + 1);
  memcpy(dst: v2, src: (unsigned __int8 *)string, count: v1 + 1);
  return (char *)v2;
}

//------------------------------------------------------------------------------
// Address: 0x100D0590
// Name: char __near * AllocateUniqueDataTableName(bool,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
char *AllocateUniqueDataTableName(bool bSendTable, const char *pFormat, ...)
{
  unsigned int v2; // kr00_4
  unsigned __int8 *v3; // edi
  char string[512]; // [esp+0h] [ebp-200h] BYREF
  va_list ap; // [esp+210h] [ebp+10h] BYREF

  va_start(ap, pFormat);
  _vsnprintf(string, count: 0x200u, format: pFormat, ap);
  v2 = strlen(string);
  v3 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v2 + 1);
  memcpy(dst: v3, src: (unsigned __int8 *)string, count: v2 + 1);
  return (char *)v3;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10103080
// Name: char __near * AllocateStringHelper(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
char *AllocateStringHelper(const char *pFormat, ...)
{
  unsigned int v1; // kr00_4
  unsigned __int8 *v2; // edi
  char string[512]; // [esp+0h] [ebp-200h] BYREF
  va_list ap; // [esp+20Ch] [ebp+Ch] BYREF

  va_start(ap, pFormat);
  _vsnprintf(string, count: 0x200u, format: pFormat, ap);
  v1 = strlen(string);
  v2 = (unsigned __int8 *)operator new(nSize: v1 + 1);
  memcpy(dst: v2, src: (unsigned __int8 *)string, count: v1 + 1);
  return (char *)v2;
}

//------------------------------------------------------------------------------
// Address: 0x101030E0
// Name: char __near * AllocateUniqueDataTableName(bool,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
char *AllocateUniqueDataTableName(bool bSendTable, const char *pFormat, ...)
{
  unsigned int v2; // kr00_4
  unsigned __int8 *v3; // edi
  char string[512]; // [esp+0h] [ebp-200h] BYREF
  va_list ap; // [esp+210h] [ebp+10h] BYREF

  va_start(ap, pFormat);
  _vsnprintf(string, count: 0x200u, format: pFormat, ap);
  v2 = strlen(string);
  v3 = (unsigned __int8 *)operator new(nSize: v2 + 1);
  memcpy(dst: v3, src: (unsigned __int8 *)string, count: v2 + 1);
  return (char *)v3;
}

} // namespace server
