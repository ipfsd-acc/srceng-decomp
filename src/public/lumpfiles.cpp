// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/lumpfiles.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x101A0480
// Name: void GenerateLumpFileName(char const __near *,char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLumpFileName(const char *bspfilename, char *lumpfilename, int iBufferSize, int iIndex)
{
  char lumppre[260]; // [esp+0h] [ebp-104h] BYREF

  V_StripExtension(in: bspfilename, out: lumppre, outSize: 260);
  V_snprintf(pDest: lumpfilename, maxLen: iBufferSize, pFormat: "%s_l_%d.lmp", lumppre, iIndex);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x101A08C0
// Name: void GenerateLumpFileName(char const __near *,char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLumpFileName(const char *bspfilename, char *lumpfilename, int iBufferSize, int iIndex)
{
  char lumppre[260]; // [esp+0h] [ebp-104h] BYREF

  V_StripExtension(in: bspfilename, out: lumppre, outSize: 260);
  V_snprintf(pDest: lumpfilename, maxLen: iBufferSize, pFormat: "%s_l_%d.lmp", lumppre, iIndex);
}

} // namespace engine_xlsp

// ============================================================
// Overlay from vbspinfo (Missing functions)
// ============================================================
namespace vbspinfo {

//------------------------------------------------------------------------------
// Address: 0x0040A640
// Name: void GenerateLumpFileName(char const __near *,char __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLumpFileName(const char *bspfilename, char *lumpfilename, int iBufferSize, int iIndex)
{
  char lumppre[260]; // [esp+0h] [ebp-104h] BYREF

  V_StripExtension(in: bspfilename, out: lumppre, outSize: 260);
  V_snprintf(pDest: lumpfilename, maxLen: iBufferSize, pFormat: "%s_l_%d.lmp", lumppre, iIndex);
}

} // namespace vbspinfo
