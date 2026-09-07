// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier0/mem.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10006490
// Name: _MemAllocScratch
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl MemAllocScratch(int nMemSize)
{
  signed int v1; // eax
  unsigned __int8 *v2; // eax
  int v3; // eax
  int v4; // ecx
  unsigned __int8 *result; // eax

  v1 = nMemSize + s_nBufCurSize;
  if ( s_nBufAllocSize < nMemSize + s_nBufCurSize )
  {
    s_nBufAllocSize = nMemSize + s_nBufCurSize;
    if ( v1 < 2048 )
    {
      v1 = 2048;
      s_nBufAllocSize = 2048;
    }
    if ( s_pBuf != nullptr )
      v2 = (unsigned __int8 *)g_pMemAlloc->Realloc_2(this: g_pMemAlloc, a2: s_pBuf, a3: v1);
    else
      v2 = (unsigned __int8 *)g_pMemAlloc->Alloc_2(this: g_pMemAlloc, a2: v1);
    s_pBuf = v2;
  }
  v3 = s_nBufCurSize;
  s_nBufCurSize += nMemSize;
  v4 = s_nBufDepth + 1;
  result = &s_pBuf[v3];
  s_pBufStackDepth[v4] = nMemSize;
  s_nBufDepth = v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10006520
// Name: _MemFreeScratch
// Source: json
//------------------------------------------------------------------------------
int MemFreeScratch()
{
  s_nBufCurSize -= s_pBufStackDepth[s_nBufDepth];
  return --s_nBufDepth;
}

// ============================================================
// Overlay from tier0_s (Missing functions)
// ============================================================
namespace tier0_s {

//------------------------------------------------------------------------------
// Address: 0x3F0031F0
// Name: _MemAllocScratch
// Source: json
//------------------------------------------------------------------------------
_DWORD *__cdecl MemAllocScratch(const char *nMemSize, int a2, int a3)
{
  const char *v3; // edi
  _DWORD *result; // eax
  char v5; // al
  int v6; // esi
  int v7; // ebx
  const char *v8; // eax
  int v9; // edx
  char v10; // cl
  int v11; // [esp+10h] [ebp-4h] BYREF

  v3 = nMemSize;
  if ( nMemSize == nullptr )
    ((void (__cdecl *)(const char *, _DWORD, const char *, int, void *, _DWORD))AssertMsgImplementation)(
      a1: "Assertion Failed: pGroupName",
      a2: 0,
      a3: ".\\dbg.cpp",
      a4: 475,
      a5: &unk_3F041A30,
      a6: 0);
  if ( *nMemSize != 42 || nMemSize[1] != 0 )
  {
    v5 = sub_3F003160(a1: nMemSize, a2: &v11);
    v6 = v11;
    if ( v5 == 0 )
    {
      v7 = 56 * ++dword_3F03D378;
      if ( dword_3F03D374 != nullptr )
      {
        dword_3F03D374 = (void *)(*(int (__thiscall **)(int, void *, int, const char *, int, _DWORD))(*(_DWORD *)g_pMemAllocSteam + 12))(
                                   a1: g_pMemAllocSteam,
                                   a2: dword_3F03D374,
                                   a3: v7,
                                   a4: ".\\dbg.cpp",
                                   a5: 496,
                                   a6: 0);
        memcpy_0(
          a1: (char *)dword_3F03D374 + 56 * v6 + 56,
          Src: (char *)dword_3F03D374 + 56 * v6,
          Size: 56 * (dword_3F03D378 - v6 - 1));
        v3 = nMemSize;
      }
      else
      {
        dword_3F03D374 = (void *)(*(int (__thiscall **)(int, int, const char *, int, _DWORD, _DWORD))(*(_DWORD *)g_pMemAllocSteam + 4))(
                                   a1: g_pMemAllocSteam,
                                   a2: v7,
                                   a3: ".\\dbg.cpp",
                                   a4: 504,
                                   a5: 0,
                                   a6: 0);
      }
      if ( strlen(v3) >= 0x30 )
        ((void (__cdecl *)(const char *, _DWORD, const char *, int, void *, _DWORD))AssertMsgImplementation)(
          a1: "Assertion Failed: _tcslen( pGroupName ) < MAX_GROUP_NAME_LENGTH",
          a2: 0,
          a3: ".\\dbg.cpp",
          a4: 506,
          a5: &unk_3F041A31,
          a6: 0);
      v8 = v3;
      v9 = (_BYTE *)dword_3F03D374 + 56 * v6 - v3;
      do
      {
        v10 = *v8;
        v8[v9] = *v8;
        ++v8;
      }
      while ( v10 != 0 );
    }
    result = (char *)dword_3F03D374 + 56 * v6;
    result[12] = a2;
    result[13] = a3;
  }
  else
  {
    dword_3F03D37C = a2;
    dword_3F03D380 = a3;
    return (_DWORD *)a2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F0033C0
// Name: _MemFreeScratch
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void MemFreeScratch()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F0034F0
// Name: void ValidateMemScratch(class CValidator __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ValidateMemScratch(char a1)
{
  byte_3F03D36A = a1;
}

} // namespace tier0_s
