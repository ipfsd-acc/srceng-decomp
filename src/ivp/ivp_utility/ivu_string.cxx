// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_utility/ivu_string.cxx
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1008D780
// Name: int p_strlen(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl p_strlen(const char *s)
{
  if ( s != nullptr && *s != 0 )
    return strlen(s);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1008D7B0
// Name: int p_strcmp(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl p_strcmp(const char *s1, const char *s2)
{
  if ( s1 == nullptr )
    return s2 != nullptr;
  if ( s2 != nullptr )
    return strcmp(s1, s2);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1008D800
// Name: char __near * p_strdup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl p_strdup(char *s)
{
  unsigned int v1; // eax
  unsigned int v2; // esi
  unsigned __int8 *v3; // edi

  if ( s == nullptr )
    return nullptr;
  if ( *s != 0 )
    v1 = strlen(s);
  else
    v1 = 0;
  v2 = v1 + 1;
  v3 = (unsigned __int8 *)p_malloc(size: v1 + 1);
  memcpy(dst: v3, src: (unsigned __int8 *)s, count: v2);
  return (char *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x1008D850
// Name: void ivp_message(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void ivp_message(char *templat, ...)
{
  unsigned __int8 dst[10000]; // [esp+0h] [ebp-2710h] BYREF
  va_list ap; // [esp+271Ch] [ebp+Ch] BYREF

  va_start(ap, templat);
  memset(dst, value: 0, count: 0x3E8u);
  sprintf(string: (char *)dst, format: "ERROR: ");
  vsprintf(string: (char *)dst, format: templat, ap);
  _Plat_DebugString(a1: dst);
}
