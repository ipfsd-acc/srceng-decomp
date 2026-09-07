// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: resourcefile/resourcedictionary.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10010580
// Name: void GenerateResourceFileName(char const __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateResourceFileName(char *pFileName, char *pResourceFileName, unsigned int nBufLen)
{
  char pContentNameNoExt[260]; // [esp+0h] [ebp-310h] BYREF
  char pContentName[260]; // [esp+104h] [ebp-20Ch] BYREF
  char pFixedContentName[264]; // [esp+208h] [ebp-108h] BYREF

  if ( V_IsAbsolutePath(pStr: pFileName) )
  {
    ComputeModContentFilename(pGameFileName: pFileName, pBuf: &pContentName[4], nBufLen: 0x104u);
    V_StripExtension(in: &pContentName[4], out: &pContentNameNoExt[4], outSize: 260);
    V_FixupPathName(pOut: &pFixedContentName[4], nOutLen: 260, pPath: &pContentNameNoExt[4]);
    g_pFullFileSystem->FullPathToRelativePathEx(
      this: g_pFullFileSystem,
      a2: &pFixedContentName[4],
      a3: "CONTENT",
      a4: pResourceFileName,
      a5: nBufLen);
  }
  else
  {
    V_StripExtension(in: pFileName, out: &pContentNameNoExt[4], outSize: 260);
    V_FixupPathName(pOut: pResourceFileName, nOutLen: nBufLen, pPath: &pContentNameNoExt[4]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010650
// Name: void GenerateResourceName(char const __near *,char const __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateResourceName(char *pFileName, char *pSubResourceName, char *pResourceName, unsigned int pBufLen)
{
  char *v4; // esi
  char pFixedSubResourceName[260]; // [esp+0h] [ebp-20Ch] BYREF
  char pFixedFileName[264]; // [esp+104h] [ebp-108h] BYREF

  v4 = pSubResourceName;
  if ( pSubResourceName == nullptr )
    v4 = (char *)&setName;
  GenerateResourceFileName(pFileName, pResourceFileName: &pFixedFileName[4], nBufLen: 0x104u);
  V_strncpy(pDest: &pFixedSubResourceName[4], pSrc: v4, maxLen: 260);
  _V_strlower(start: &pFixedSubResourceName[4]);
  V_snprintf(pDest: pResourceName, maxLen: pBufLen, pFormat: "%s::%s", &pFixedFileName[4], &pFixedSubResourceName[4]);
}

//------------------------------------------------------------------------------
// Address: 0x100106D0
// Name: unsigned int ComputeResourceIdHash(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl ComputeResourceIdHash(char *pFileName, char *pSubResourceName)
{
  unsigned int v2; // eax
  char pTemp[392]; // [esp+0h] [ebp-188h] BYREF

  if ( pFileName == nullptr )
    return 0;
  if ( *pFileName == 0 )
    return 0;
  GenerateResourceName(pFileName, pSubResourceName, pResourceName: &pTemp[4], pBufLen: 0x184u);
  if ( pTemp[4] == 0 )
    return 0;
  v2 = _V_strlen(str: &pTemp[4]);
  return MurmurHash2(key: &pTemp[4], len: v2, seed: 0xEDABCDEF);
}

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x10097120
// Name: unsigned int ComputeResourceIdHash(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl ComputeResourceIdHash(const char *pResourceName)
{
  int v1; // eax

  if ( pResourceName == nullptr || *pResourceName == 0 )
    return 0;
  v1 = _V_strlen(str: pResourceName);
  return MurmurHash2(key: pResourceName, len: v1, seed: 0xEDABCDEF);
}

//------------------------------------------------------------------------------
// Address: 0x10097150
// Name: void GenerateResourceFileName(char const __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateResourceFileName(const char *pFileName, char *pResourceFileName, unsigned int nBufLen)
{
  char pFixedContentName[260]; // [esp+4h] [ebp-30Ch] BYREF
  char pContentName[260]; // [esp+108h] [ebp-208h] BYREF
  char pContentNameNoExt[260]; // [esp+20Ch] [ebp-104h] BYREF

  if ( V_IsAbsolutePath(pStr: pFileName) )
  {
    ComputeModContentFilename(pGameFileName: pFileName, pBuf: pContentName, nBufLen: 0x104u);
    V_StripExtension(in: pContentName, out: pContentNameNoExt, outSize: 260);
    V_FixupPathName(pOut: pFixedContentName, nOutLen: 0x104u, pPath: pContentNameNoExt);
    g_pFullFileSystem->FullPathToRelativePathEx(
      this: g_pFullFileSystem,
      a2: pFixedContentName,
      a3: "CONTENT",
      a4: pResourceFileName,
      a5: nBufLen);
  }
  else
  {
    V_StripExtension(in: pFileName, out: pContentNameNoExt, outSize: 260);
    V_FixupPathName(pOut: pResourceFileName, nOutLen: nBufLen, pPath: pContentNameNoExt);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10097210
// Name: void GenerateResourceName(char const __near *,char const __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateResourceName(
        const char *pFileName,
        const char *pSubResourceName,
        char *pResourceName,
        unsigned int pBufLen)
{
  const char *v4; // esi
  char pFixedFileName[260]; // [esp+4h] [ebp-208h] BYREF
  char pFixedSubResourceName[260]; // [esp+108h] [ebp-104h] BYREF

  v4 = pSubResourceName;
  if ( pSubResourceName == nullptr )
    v4 = defaultValue;
  GenerateResourceFileName(pFileName, pResourceFileName: pFixedFileName, nBufLen: 0x104u);
  V_strncpy(pDest: pFixedSubResourceName, pSrc: v4, maxLen: 260);
  _V_strlower(start: pFixedSubResourceName);
  V_snprintf(pDest: pResourceName, maxLen: pBufLen, pFormat: "%s::%s", pFixedFileName, pFixedSubResourceName);
}

} // namespace vtex_dll
