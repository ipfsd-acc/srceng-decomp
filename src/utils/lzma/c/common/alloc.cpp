// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/lzma/c/common/alloc.cpp
// Functions: 5
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1001DEC0
// Name: void __near * MyAlloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl MyAlloc(void *size)
{
  void *result; // eax

  result = size;
  if ( size != nullptr )
    return operator new(nSize: (unsigned int)size);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001DEE0
// Name: void MyFree(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MyFree(void *address)
{
  free(pMem: address);
}

//------------------------------------------------------------------------------
// Address: 0x1001DEF0
// Name: void __near * MidAlloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
LPVOID __cdecl MidAlloc(void *size)
{
  LPVOID result; // eax

  result = size;
  if ( size != nullptr )
    return VirtualAlloc(lpAddress: nullptr, dwSize: (SIZE_T)size, flAllocationType: 0x1000u, flProtect: 4u);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001DF10
// Name: void __near * BigAlloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl BigAlloc(SIZE_T size)
{
  void *result; // eax

  if ( size == 0 )
    return nullptr;
  if ( size < 0x40000 )
    return VirtualAlloc(lpAddress: nullptr, dwSize: size, flAllocationType: 0x1000u, flProtect: 4u);
  result = VirtualAlloc(
             lpAddress: nullptr,
             dwSize: ~(g_LargePageSize - 1) & (g_LargePageSize + size - 1),
             flAllocationType: 0x20001000u,
             flProtect: 4u);
  if ( result == nullptr )
    return VirtualAlloc(lpAddress: nullptr, dwSize: size, flAllocationType: 0x1000u, flProtect: 4u);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001DF60
// Name: void MidFree(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MidFree(void *address)
{
  if ( address != nullptr )
    VirtualFree(lpAddress: address, dwSize: 0, dwFreeType: 0x8000u);
}

// ============================================================
// Overlay from hlfaceposer (Missing functions)
// ============================================================
namespace hlfaceposer {

//------------------------------------------------------------------------------
// Address: 0x004BCA30
// Name: void __near * MyAlloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl MyAlloc(void *size)
{
  void *result; // eax

  result = size;
  if ( size != nullptr )
    return operator new(nSize: (unsigned int)size);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004BCA50
// Name: void MyFree(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MyFree(void *address)
{
  free(pMem: address);
}

//------------------------------------------------------------------------------
// Address: 0x004BCA60
// Name: void __near * MidAlloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
LPVOID __cdecl MidAlloc(void *size)
{
  LPVOID result; // eax

  result = size;
  if ( size != nullptr )
    return VirtualAlloc(lpAddress: nullptr, dwSize: (SIZE_T)size, flAllocationType: 0x1000u, flProtect: 4u);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004BCA80
// Name: void __near * BigAlloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl BigAlloc(SIZE_T size)
{
  void *result; // eax

  if ( size == 0 )
    return nullptr;
  if ( size < 0x40000 )
    return VirtualAlloc(lpAddress: nullptr, dwSize: size, flAllocationType: 0x1000u, flProtect: 4u);
  result = VirtualAlloc(
             lpAddress: nullptr,
             dwSize: ~(g_LargePageSize - 1) & (g_LargePageSize + size - 1),
             flAllocationType: 0x20001000u,
             flProtect: 4u);
  if ( result == nullptr )
    return VirtualAlloc(lpAddress: nullptr, dwSize: size, flAllocationType: 0x1000u, flProtect: 4u);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004BCAD0
// Name: void MidFree(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MidFree(void *address)
{
  if ( address != nullptr )
    VirtualFree(lpAddress: address, dwSize: 0, dwFreeType: 0x8000u);
}

} // namespace hlfaceposer

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x005265A0
// Name: void __near * MyAlloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl MyAlloc(void *size)
{
  void *result; // eax

  result = size;
  if ( size != nullptr )
    return MemAlloc_Alloc(nSize: (unsigned int)size);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005265C0
// Name: void MyFree(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MyFree(void *address)
{
  free(pMem: address);
}

//------------------------------------------------------------------------------
// Address: 0x005265D0
// Name: void __near * MidAlloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
LPVOID __cdecl MidAlloc(void *size)
{
  LPVOID result; // eax

  result = size;
  if ( size != nullptr )
    return VirtualAlloc(lpAddress: nullptr, dwSize: (SIZE_T)size, flAllocationType: 0x1000u, flProtect: 4u);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005265F0
// Name: void MidFree(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MidFree(void *address)
{
  if ( address != nullptr )
    VirtualFree(lpAddress: address, dwSize: 0, dwFreeType: 0x8000u);
}

//------------------------------------------------------------------------------
// Address: 0x00526610
// Name: void __near * BigAlloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl BigAlloc(SIZE_T size)
{
  void *result; // eax

  if ( size == 0 )
    return nullptr;
  if ( size < 0x40000 )
    return VirtualAlloc(lpAddress: nullptr, dwSize: size, flAllocationType: 0x1000u, flProtect: 4u);
  result = VirtualAlloc(
             lpAddress: nullptr,
             dwSize: ~(g_LargePageSize - 1) & (g_LargePageSize + size - 1),
             flAllocationType: 0x20001000u,
             flProtect: 4u);
  if ( result == nullptr )
    return VirtualAlloc(lpAddress: nullptr, dwSize: size, flAllocationType: 0x1000u, flProtect: 4u);
  return result;
}

} // namespace makegamedata

// ============================================================
// Overlay from shadercompile_dll (Missing functions)
// ============================================================
namespace shadercompile_dll {

//------------------------------------------------------------------------------
// Address: 0x10017AD0
// Name: void __near * MyAlloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl MyAlloc(void *size)
{
  void *result; // eax

  result = size;
  if ( size != nullptr )
    return operator new(nSize: (unsigned int)size);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017AF0
// Name: void MyFree(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MyFree(void *address)
{
  free(pMem: address);
}

//------------------------------------------------------------------------------
// Address: 0x10017B00
// Name: void __near * MidAlloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
LPVOID __cdecl MidAlloc(void *size)
{
  LPVOID result; // eax

  result = size;
  if ( size != nullptr )
    return VirtualAlloc(lpAddress: nullptr, dwSize: (SIZE_T)size, flAllocationType: 0x1000u, flProtect: 4u);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017B20
// Name: void __near * BigAlloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl BigAlloc(SIZE_T size)
{
  void *result; // eax

  if ( size == 0 )
    return nullptr;
  if ( size < 0x40000 )
    return VirtualAlloc(lpAddress: nullptr, dwSize: size, flAllocationType: 0x1000u, flProtect: 4u);
  result = VirtualAlloc(
             lpAddress: nullptr,
             dwSize: ~(g_LargePageSize - 1) & (g_LargePageSize + size - 1),
             flAllocationType: 0x20001000u,
             flProtect: 4u);
  if ( result == nullptr )
    return VirtualAlloc(lpAddress: nullptr, dwSize: size, flAllocationType: 0x1000u, flProtect: 4u);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017B70
// Name: void MidFree(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MidFree(void *address)
{
  if ( address != nullptr )
    VirtualFree(lpAddress: address, dwSize: 0, dwFreeType: 0x8000u);
}

} // namespace shadercompile_dll
