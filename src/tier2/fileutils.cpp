// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier2/fileutils.cpp
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1027AC00
// Name: void GetModSubdirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetModSubdirectory(const char *pSubDir, char *pBuf, int nBufLen)
{
  _BYTE *v3; // eax
  unsigned int nLen; // [esp+14h] [ebp+8h]

  g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "MOD", a3: false, a4: pBuf, a5: nBufLen);
  strchr(string: (unsigned __int8 *)pBuf, chr: 0x3Bu);
  if ( v3 != nullptr )
    *v3 = 0;
  V_StripTrailingSlash(ppath: pBuf);
  if ( pSubDir != nullptr )
  {
    nLen = _V_strlen(str: pSubDir);
    V_strncat(pDest: pBuf, pSrc: "\\", destBufferSize: nBufLen, max_chars_to_copy: 1);
    V_strncat(pDest: pBuf, pSrc: pSubDir, destBufferSize: nBufLen, max_chars_to_copy: nLen);
  }
  V_FixSlashes(pname: pBuf, separator: 92);
}

//------------------------------------------------------------------------------
// Address: 0x1027AC80
// Name: void ComputeModFilename(char const __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeModFilename(char *pContentFileName, char *pBuf, unsigned int nBufLen)
{
  _BYTE *v3; // eax
  char pRelativePath[260]; // [esp+4h] [ebp-208h] BYREF
  char pGameRoot[260]; // [esp+108h] [ebp-104h] BYREF

  if ( g_pFullFileSystem->FullPathToRelativePathEx(
         this: g_pFullFileSystem,
         a2: pContentFileName,
         a3: "CONTENTROOT",
         a4: pRelativePath,
         a5: 260) )
  {
    g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "GAMEROOT", a3: false, a4: pGameRoot, a5: 260);
    strchr(string: (unsigned __int8 *)pGameRoot, chr: 0x3Bu);
    if ( v3 != nullptr )
      *v3 = 0;
    V_ComposeFileName(path: pGameRoot, filename: pRelativePath, dest: pBuf, destSize: nBufLen);
  }
  else
  {
    V_strncpy(pDest: pBuf, pSrc: pContentFileName, maxLen: nBufLen);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027AD30
// Name: void ComputeModContentFilename(char const __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeModContentFilename(char *pGameFileName, char *pBuf, unsigned int nBufLen)
{
  _BYTE *v3; // eax
  char pRelativePath[260]; // [esp+4h] [ebp-208h] BYREF
  char pContentRoot[260]; // [esp+108h] [ebp-104h] BYREF

  if ( g_pFullFileSystem->FullPathToRelativePathEx(
         this: g_pFullFileSystem,
         a2: pGameFileName,
         a3: "GAMEROOT",
         a4: pRelativePath,
         a5: 260) )
  {
    g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "CONTENTROOT", a3: false, a4: pContentRoot, a5: 260);
    strchr(string: (unsigned __int8 *)pContentRoot, chr: 0x3Bu);
    if ( v3 != nullptr )
      *v3 = 0;
    V_ComposeFileName(path: pContentRoot, filename: pRelativePath, dest: pBuf, destSize: nBufLen);
  }
  else
  {
    V_strncpy(pDest: pBuf, pSrc: pGameFileName, maxLen: nBufLen);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027ADE0
// Name: void GetModContentSubdirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetModContentSubdirectory(const char *pSubDir, char *pBuf, unsigned int nBufLen)
{
  char pTemp[260]; // [esp+0h] [ebp-104h] BYREF

  GetModSubdirectory(pSubDir, pBuf: pTemp, nBufLen: 260);
  ComputeModContentFilename(pGameFileName: pTemp, pBuf, nBufLen);
}

// ============================================================
// Overlay from MaterialSystem (Missing functions)
// ============================================================
namespace MaterialSystem {

//------------------------------------------------------------------------------
// Address: 0x1025E070
// Name: void GetModSubdirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetModSubdirectory(const char *pSubDir, char *pBuf, int nBufLen)
{
  _BYTE *v3; // eax
  unsigned int nLen; // [esp+14h] [ebp+8h]

  g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "MOD", a3: false, a4: pBuf, a5: nBufLen);
  strchr(string: (unsigned __int8 *)pBuf, chr: 0x3Bu);
  if ( v3 != nullptr )
    *v3 = 0;
  V_StripTrailingSlash(ppath: pBuf);
  if ( pSubDir != nullptr )
  {
    nLen = _V_strlen(str: pSubDir);
    V_strncat(pDest: pBuf, pSrc: "\\", destBufferSize: nBufLen, max_chars_to_copy: 1);
    V_strncat(pDest: pBuf, pSrc: pSubDir, destBufferSize: nBufLen, max_chars_to_copy: nLen);
  }
  V_FixSlashes(pname: pBuf, separator: 92);
}

} // namespace MaterialSystem

// ============================================================
// Overlay from dmxconvert (Missing functions)
// ============================================================
namespace dmxconvert {

//------------------------------------------------------------------------------
// Address: 0x004687D0
// Name: bool GenerateFullPath(char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl GenerateFullPath(char *pFileName, const char *pPathID, char *pBuf, int nBufLen)
{
  bool result; // al
  const char *v5; // eax
  char pDir[260]; // [esp+4h] [ebp-104h] BYREF

  if ( V_IsAbsolutePath(pStr: pFileName) )
  {
    V_strncpy(pDest: pBuf, pSrc: pFileName, maxLen: nBufLen);
    return true;
  }
  v5 = g_pFullFileSystem->RelativePathToFullPath(
         this: g_pFullFileSystem,
         a2: pFileName,
         a3: pPathID,
         a4: pBuf,
         a5: nBufLen,
         a6: 0,
         a7: 0);
  if ( v5 == nullptr || !V_IsAbsolutePath(pStr: v5) )
  {
    result = g_pFullFileSystem->GetCurrentDirectory(this: g_pFullFileSystem, a2: pDir, a3: 260);
    if ( !result )
      return result;
    V_ComposeFileName(path: pDir, filename: pFileName, dest: pBuf, destSize: nBufLen);
    V_RemoveDotSlashes(pFilename: pBuf, separator: 92);
  }
  return true;
}

} // namespace dmxconvert

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x00576920
// Name: void GetModSubdirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetModSubdirectory(const char *pSubDir, char *pBuf, int nBufLen)
{
  _BYTE *v3; // eax
  unsigned int nLen; // [esp+14h] [ebp+8h]

  g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "MOD", a3: false, a4: pBuf, a5: nBufLen);
  strchr(string: (unsigned __int8 *)pBuf, chr: 0x3Bu);
  if ( v3 != nullptr )
    *v3 = 0;
  V_StripTrailingSlash(ppath: pBuf);
  if ( pSubDir != nullptr )
  {
    nLen = _V_strlen(str: pSubDir);
    V_strncat(pDest: pBuf, pSrc: "\\", destBufferSize: nBufLen, max_chars_to_copy: 1);
    V_strncat(pDest: pBuf, pSrc: pSubDir, destBufferSize: nBufLen, max_chars_to_copy: nLen);
  }
  V_FixSlashes(pname: pBuf, separator: 92);
}

//------------------------------------------------------------------------------
// Address: 0x005769A0
// Name: void ComputeModContentFilename(char const __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeModContentFilename(char *pGameFileName, char *pBuf, unsigned int nBufLen)
{
  _BYTE *v3; // eax
  char pRelativePath[260]; // [esp+4h] [ebp-208h] BYREF
  char pContentRoot[260]; // [esp+108h] [ebp-104h] BYREF

  if ( g_pFullFileSystem->FullPathToRelativePathEx(
         this: g_pFullFileSystem,
         a2: pGameFileName,
         a3: "GAMEROOT",
         a4: pRelativePath,
         a5: 260) )
  {
    g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "CONTENTROOT", a3: false, a4: pContentRoot, a5: 260);
    strchr(string: (unsigned __int8 *)pContentRoot, chr: 0x3Bu);
    if ( v3 != nullptr )
      *v3 = 0;
    V_ComposeFileName(path: pContentRoot, filename: pRelativePath, dest: pBuf, destSize: nBufLen);
  }
  else
  {
    V_strncpy(pDest: pBuf, pSrc: pGameFileName, maxLen: nBufLen);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00576A50
// Name: bool GenerateFullPath(char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl GenerateFullPath(char *pFileName, const char *pPathID, char *pBuf, int nBufLen)
{
  bool result; // al
  const char *v5; // eax
  char pDir[260]; // [esp+4h] [ebp-104h] BYREF

  if ( V_IsAbsolutePath(pStr: pFileName) )
  {
    V_strncpy(pDest: pBuf, pSrc: pFileName, maxLen: nBufLen);
    return true;
  }
  v5 = g_pFullFileSystem->RelativePathToFullPath(
         this: g_pFullFileSystem,
         a2: pFileName,
         a3: pPathID,
         a4: pBuf,
         a5: nBufLen,
         a6: 0,
         a7: 0);
  if ( v5 == nullptr || !V_IsAbsolutePath(pStr: v5) )
  {
    result = g_pFullFileSystem->GetCurrentDirectory(this: g_pFullFileSystem, a2: pDir, a3: 260);
    if ( !result )
      return result;
    V_ComposeFileName(path: pDir, filename: pFileName, dest: pBuf, destSize: nBufLen);
    V_RemoveDotSlashes(pFilename: pBuf, separator: 92);
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x00576B00
// Name: void GetModContentSubdirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetModContentSubdirectory(const char *pSubDir, char *pBuf, unsigned int nBufLen)
{
  char pTemp[260]; // [esp+0h] [ebp-104h] BYREF

  GetModSubdirectory(pSubDir, pBuf: pTemp, nBufLen: 260);
  ComputeModContentFilename(pGameFileName: pTemp, pBuf, nBufLen);
}

} // namespace dmxedit

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005DA070
// Name: void GetModSubdirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetModSubdirectory(const char *pSubDir, char *pBuf, int nBufLen)
{
  _BYTE *v3; // eax
  unsigned int nLen; // [esp+14h] [ebp+8h]

  g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "MOD", a3: false, a4: pBuf, a5: nBufLen);
  strchr(string: (unsigned __int8 *)pBuf, chr: 0x3Bu);
  if ( v3 != nullptr )
    *v3 = 0;
  V_StripTrailingSlash(ppath: pBuf);
  if ( pSubDir != nullptr )
  {
    nLen = _V_strlen(str: pSubDir);
    V_strncat(pDest: pBuf, pSrc: "\\", destBufferSize: nBufLen, max_chars_to_copy: 1);
    V_strncat(pDest: pBuf, pSrc: pSubDir, destBufferSize: nBufLen, max_chars_to_copy: nLen);
  }
  V_FixSlashes(pname: pBuf, separator: 92);
}

//------------------------------------------------------------------------------
// Address: 0x005DA0F0
// Name: void ComputeModContentFilename(char const __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeModContentFilename(char *pGameFileName, char *pBuf, unsigned int nBufLen)
{
  _BYTE *v3; // eax
  char pRelativePath[260]; // [esp+4h] [ebp-208h] BYREF
  char pContentRoot[260]; // [esp+108h] [ebp-104h] BYREF

  if ( g_pFullFileSystem->FullPathToRelativePathEx(
         this: g_pFullFileSystem,
         a2: pGameFileName,
         a3: "GAMEROOT",
         a4: pRelativePath,
         a5: 260) )
  {
    g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "CONTENTROOT", a3: false, a4: pContentRoot, a5: 260);
    strchr(string: (unsigned __int8 *)pContentRoot, chr: 0x3Bu);
    if ( v3 != nullptr )
      *v3 = 0;
    V_ComposeFileName(path: pContentRoot, filename: pRelativePath, dest: pBuf, destSize: nBufLen);
  }
  else
  {
    V_strncpy(pDest: pBuf, pSrc: pGameFileName, maxLen: nBufLen);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005DA1A0
// Name: bool GenerateFullPath(char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl GenerateFullPath(char *pFileName, const char *pPathID, char *pBuf, int nBufLen)
{
  bool result; // al
  const char *v5; // eax
  char pDir[260]; // [esp+4h] [ebp-104h] BYREF

  if ( V_IsAbsolutePath(pStr: pFileName) )
  {
    V_strncpy(pDest: pBuf, pSrc: pFileName, maxLen: nBufLen);
    return true;
  }
  v5 = g_pFullFileSystem->RelativePathToFullPath(
         this: g_pFullFileSystem,
         a2: pFileName,
         a3: pPathID,
         a4: pBuf,
         a5: nBufLen,
         a6: 0,
         a7: 0);
  if ( v5 == nullptr || !V_IsAbsolutePath(pStr: v5) )
  {
    result = g_pFullFileSystem->GetCurrentDirectory(this: g_pFullFileSystem, a2: pDir, a3: 260);
    if ( !result )
      return result;
    V_ComposeFileName(path: pDir, filename: pFileName, dest: pBuf, destSize: nBufLen);
    V_RemoveDotSlashes(pFilename: pBuf, separator: 92);
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x005DA250
// Name: void GetModContentSubdirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetModContentSubdirectory(const char *pSubDir, char *pBuf, unsigned int nBufLen)
{
  char pTemp[260]; // [esp+0h] [ebp-104h] BYREF

  GetModSubdirectory(pSubDir, pBuf: pTemp, nBufLen: 260);
  ComputeModContentFilename(pGameFileName: pTemp, pBuf, nBufLen);
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1027AD40
// Name: void GetModSubdirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetModSubdirectory(const char *pSubDir, char *pBuf, int nBufLen)
{
  _BYTE *v3; // eax
  int nLen; // [esp+14h] [ebp+8h]

  g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "MOD", a3: false, a4: pBuf, a5: nBufLen);
  strchr(string: (unsigned __int8 *)pBuf, chr: 0x3Bu);
  if ( v3 != nullptr )
    *v3 = 0;
  V_StripTrailingSlash(ppath: pBuf);
  if ( pSubDir != nullptr )
  {
    nLen = _V_strlen(str: pSubDir);
    V_strncat(pDest: pBuf, pSrc: "\\", destBufferSize: nBufLen, max_chars_to_copy: 1);
    V_strncat(pDest: pBuf, pSrc: pSubDir, destBufferSize: nBufLen, max_chars_to_copy: nLen);
  }
  V_FixSlashes(pname: pBuf, separator: 92);
}

//------------------------------------------------------------------------------
// Address: 0x1027ADC0
// Name: void ComputeModFilename(char const __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeModFilename(const char *pContentFileName, char *pBuf, unsigned int nBufLen)
{
  _BYTE *v3; // eax
  char pRelativePath[260]; // [esp+4h] [ebp-208h] BYREF
  char pGameRoot[260]; // [esp+108h] [ebp-104h] BYREF

  if ( g_pFullFileSystem->FullPathToRelativePathEx(
         this: g_pFullFileSystem,
         a2: pContentFileName,
         a3: "CONTENTROOT",
         a4: pRelativePath,
         a5: 260) )
  {
    g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "GAMEROOT", a3: false, a4: pGameRoot, a5: 260);
    strchr(string: (unsigned __int8 *)pGameRoot, chr: 0x3Bu);
    if ( v3 != nullptr )
      *v3 = 0;
    V_ComposeFileName(path: pGameRoot, filename: pRelativePath, dest: pBuf, destSize: nBufLen);
  }
  else
  {
    V_strncpy(pDest: pBuf, pSrc: pContentFileName, maxLen: nBufLen);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027AE70
// Name: void ComputeModContentFilename(char const __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeModContentFilename(const char *pGameFileName, char *pBuf, unsigned int nBufLen)
{
  _BYTE *v3; // eax
  char pRelativePath[260]; // [esp+4h] [ebp-208h] BYREF
  char pContentRoot[260]; // [esp+108h] [ebp-104h] BYREF

  if ( g_pFullFileSystem->FullPathToRelativePathEx(
         this: g_pFullFileSystem,
         a2: pGameFileName,
         a3: "GAMEROOT",
         a4: pRelativePath,
         a5: 260) )
  {
    g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "CONTENTROOT", a3: false, a4: pContentRoot, a5: 260);
    strchr(string: (unsigned __int8 *)pContentRoot, chr: 0x3Bu);
    if ( v3 != nullptr )
      *v3 = 0;
    V_ComposeFileName(path: pContentRoot, filename: pRelativePath, dest: pBuf, destSize: nBufLen);
  }
  else
  {
    V_strncpy(pDest: pBuf, pSrc: pGameFileName, maxLen: nBufLen);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027AF20
// Name: void GetModContentSubdirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetModContentSubdirectory(const char *pSubDir, char *pBuf, unsigned int nBufLen)
{
  char pTemp[260]; // [esp+0h] [ebp-104h] BYREF

  GetModSubdirectory(pSubDir, pBuf: pTemp, nBufLen: 260);
  ComputeModContentFilename(pGameFileName: pTemp, pBuf, nBufLen);
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102B7D90
// Name: void GetModSubdirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetModSubdirectory(const char *pSubDir, char *pBuf, int nBufLen)
{
  _BYTE *v3; // eax
  unsigned int nLen; // [esp+14h] [ebp+8h]

  g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "MOD", a3: false, a4: pBuf, a5: nBufLen);
  strchr(string: pBuf, chr: 0x3Bu);
  if ( v3 != nullptr )
    *v3 = 0;
  V_StripTrailingSlash(ppath: pBuf);
  if ( pSubDir != nullptr )
  {
    nLen = std::char_traits<char>::length(str: pSubDir);
    V_strncat(pDest: pBuf, pSrc: "\\", destBufferSize: nBufLen, max_chars_to_copy: 1);
    V_strncat(pDest: pBuf, pSrc: pSubDir, destBufferSize: nBufLen, max_chars_to_copy: nLen);
  }
  V_FixSlashes(pname: pBuf, separator: 92);
}

//------------------------------------------------------------------------------
// Address: 0x102B7E10
// Name: void ComputeModContentFilename(char const __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeModContentFilename(char *pGameFileName, char *pBuf, unsigned int nBufLen)
{
  _BYTE *v3; // eax
  char pRelativePath[260]; // [esp+4h] [ebp-208h] BYREF
  char pContentRoot[260]; // [esp+108h] [ebp-104h] BYREF

  if ( g_pFullFileSystem->FullPathToRelativePathEx(
         this: g_pFullFileSystem,
         a2: pGameFileName,
         a3: "GAMEROOT",
         a4: pRelativePath,
         a5: 260) )
  {
    g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "CONTENTROOT", a3: false, a4: pContentRoot, a5: 260);
    strchr(string: pContentRoot, chr: 0x3Bu);
    if ( v3 != nullptr )
      *v3 = 0;
    V_ComposeFileName(path: pContentRoot, filename: pRelativePath, dest: pBuf, destSize: nBufLen);
  }
  else
  {
    V_strncpy(pDest: pBuf, pSrc: pGameFileName, maxLen: nBufLen);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B7EC0
// Name: bool GenerateFullPath(char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl GenerateFullPath(char *pFileName, const char *pPathID, char *pBuf, int nBufLen)
{
  bool result; // al
  const char *v5; // eax
  char pDir[260]; // [esp+4h] [ebp-104h] BYREF

  if ( V_IsAbsolutePath(pStr: pFileName) )
  {
    V_strncpy(pDest: pBuf, pSrc: pFileName, maxLen: nBufLen);
    return true;
  }
  v5 = g_pFullFileSystem->RelativePathToFullPath(
         this: g_pFullFileSystem,
         a2: pFileName,
         a3: pPathID,
         a4: pBuf,
         a5: nBufLen,
         a6: 0,
         a7: 0);
  if ( v5 == nullptr || !V_IsAbsolutePath(pStr: v5) )
  {
    result = g_pFullFileSystem->GetCurrentDirectory(this: g_pFullFileSystem, a2: pDir, a3: 260);
    if ( !result )
      return result;
    V_ComposeFileName(path: pDir, filename: pFileName, dest: pBuf, destSize: nBufLen);
    V_RemoveDotSlashes(pFilename: pBuf, separator: 92);
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x102B7F70
// Name: void GetModContentSubdirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetModContentSubdirectory(const char *pSubDir, char *pBuf, unsigned int nBufLen)
{
  char pTemp[260]; // [esp+0h] [ebp-104h] BYREF

  GetModSubdirectory(pSubDir, pBuf: pTemp, nBufLen: 260);
  ComputeModContentFilename(pGameFileName: pTemp, pBuf, nBufLen);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0057B250
// Name: void GetModSubdirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetModSubdirectory(const char *pSubDir, char *pBuf, int nBufLen)
{
  _BYTE *v3; // eax
  unsigned int nLen; // [esp+14h] [ebp+8h]

  g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "MOD", a3: false, a4: pBuf, a5: nBufLen);
  strchr(string: (unsigned __int8 *)pBuf, chr: 0x3Bu);
  if ( v3 != nullptr )
    *v3 = 0;
  V_StripTrailingSlash(ppath: pBuf);
  if ( pSubDir != nullptr )
  {
    nLen = _V_strlen(str: pSubDir);
    V_strncat(pDest: pBuf, pSrc: "\\", destBufferSize: nBufLen, max_chars_to_copy: 1);
    V_strncat(pDest: pBuf, pSrc: pSubDir, destBufferSize: nBufLen, max_chars_to_copy: nLen);
  }
  V_FixSlashes(pname: pBuf, separator: 92);
}

//------------------------------------------------------------------------------
// Address: 0x0057B2D0
// Name: void ComputeModContentFilename(char const __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeModContentFilename(char *pGameFileName, char *pBuf, unsigned int nBufLen)
{
  _BYTE *v3; // eax
  char pRelativePath[260]; // [esp+4h] [ebp-208h] BYREF
  char pContentRoot[260]; // [esp+108h] [ebp-104h] BYREF

  if ( g_pFullFileSystem->FullPathToRelativePathEx(
         this: g_pFullFileSystem,
         a2: pGameFileName,
         a3: "GAMEROOT",
         a4: pRelativePath,
         a5: 260) )
  {
    g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "CONTENTROOT", a3: false, a4: pContentRoot, a5: 260);
    strchr(string: (unsigned __int8 *)pContentRoot, chr: 0x3Bu);
    if ( v3 != nullptr )
      *v3 = 0;
    V_ComposeFileName(path: pContentRoot, filename: pRelativePath, dest: pBuf, destSize: nBufLen);
  }
  else
  {
    V_strncpy(pDest: pBuf, pSrc: pGameFileName, maxLen: nBufLen);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0057B380
// Name: bool GenerateFullPath(char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl GenerateFullPath(char *pFileName, const char *pPathID, char *pBuf, int nBufLen)
{
  bool result; // al
  const char *v5; // eax
  char pDir[260]; // [esp+4h] [ebp-104h] BYREF

  if ( V_IsAbsolutePath(pStr: pFileName) )
  {
    V_strncpy(pDest: pBuf, pSrc: pFileName, maxLen: nBufLen);
    return true;
  }
  v5 = g_pFullFileSystem->RelativePathToFullPath(
         this: g_pFullFileSystem,
         a2: pFileName,
         a3: pPathID,
         a4: pBuf,
         a5: nBufLen,
         a6: 0,
         a7: 0);
  if ( v5 == nullptr || !V_IsAbsolutePath(pStr: v5) )
  {
    result = g_pFullFileSystem->GetCurrentDirectory(this: g_pFullFileSystem, a2: pDir, a3: 260);
    if ( !result )
      return result;
    V_ComposeFileName(path: pDir, filename: pFileName, dest: pBuf, destSize: nBufLen);
    V_RemoveDotSlashes(pFilename: pBuf, separator: 92);
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x0057B430
// Name: void GetModContentSubdirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetModContentSubdirectory(const char *pSubDir, char *pBuf, unsigned int nBufLen)
{
  char pTemp[260]; // [esp+0h] [ebp-104h] BYREF

  GetModSubdirectory(pSubDir, pBuf: pTemp, nBufLen: 260);
  ComputeModContentFilename(pGameFileName: pTemp, pBuf, nBufLen);
}

} // namespace hlmv

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x00533E50
// Name: bool GenerateFullPath(char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl GenerateFullPath(char *pFileName, const char *pPathID, char *pBuf, int nBufLen)
{
  bool result; // al
  const char *v5; // eax
  char pDir[260]; // [esp+4h] [ebp-104h] BYREF

  if ( V_IsAbsolutePath(pStr: pFileName) )
  {
    V_strncpy(pDest: pBuf, pSrc: pFileName, maxLen: nBufLen);
    return true;
  }
  v5 = g_pFullFileSystem->RelativePathToFullPath(
         this: g_pFullFileSystem,
         a2: pFileName,
         a3: pPathID,
         a4: pBuf,
         a5: nBufLen,
         a6: 0,
         a7: 0);
  if ( v5 == nullptr || !V_IsAbsolutePath(pStr: v5) )
  {
    result = g_pFullFileSystem->GetCurrentDirectory(this: g_pFullFileSystem, a2: pDir, a3: 260);
    if ( !result )
      return result;
    V_ComposeFileName(path: pDir, filename: pFileName, dest: pBuf, destSize: nBufLen);
    V_RemoveDotSlashes(pFilename: pBuf, separator: 92);
  }
  return true;
}

} // namespace makegamedata

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x005C78B0
// Name: void GetModSubdirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetModSubdirectory(const char *pSubDir, char *pBuf, int nBufLen)
{
  _BYTE *v3; // eax
  unsigned int nLen; // [esp+14h] [ebp+8h]

  g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "MOD", a3: false, a4: pBuf, a5: nBufLen);
  strchr(string: (unsigned __int8 *)pBuf, chr: 0x3Bu);
  if ( v3 != nullptr )
    *v3 = 0;
  V_StripTrailingSlash(ppath: pBuf);
  if ( pSubDir != nullptr )
  {
    nLen = _V_strlen(str: pSubDir);
    V_strncat(pDest: pBuf, pSrc: "\\", destBufferSize: nBufLen, max_chars_to_copy: 1);
    V_strncat(pDest: pBuf, pSrc: pSubDir, destBufferSize: nBufLen, max_chars_to_copy: nLen);
  }
  V_FixSlashes(pname: pBuf, separator: 92);
}

//------------------------------------------------------------------------------
// Address: 0x005C7930
// Name: void ComputeModFilename(char const __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeModFilename(char *pContentFileName, char *pBuf, unsigned int nBufLen)
{
  _BYTE *v3; // eax
  char pRelativePath[260]; // [esp+4h] [ebp-208h] BYREF
  char pGameRoot[260]; // [esp+108h] [ebp-104h] BYREF

  if ( g_pFullFileSystem->FullPathToRelativePathEx(
         this: g_pFullFileSystem,
         a2: pContentFileName,
         a3: "CONTENTROOT",
         a4: pRelativePath,
         a5: 260) )
  {
    g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "GAMEROOT", a3: false, a4: pGameRoot, a5: 260);
    strchr(string: (unsigned __int8 *)pGameRoot, chr: 0x3Bu);
    if ( v3 != nullptr )
      *v3 = 0;
    V_ComposeFileName(path: pGameRoot, filename: pRelativePath, dest: pBuf, destSize: nBufLen);
  }
  else
  {
    V_strncpy(pDest: pBuf, pSrc: pContentFileName, maxLen: nBufLen);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C79E0
// Name: void ComputeModContentFilename(char const __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeModContentFilename(char *pGameFileName, char *pBuf, unsigned int nBufLen)
{
  _BYTE *v3; // eax
  char pRelativePath[260]; // [esp+4h] [ebp-208h] BYREF
  char pContentRoot[260]; // [esp+108h] [ebp-104h] BYREF

  if ( g_pFullFileSystem->FullPathToRelativePathEx(
         this: g_pFullFileSystem,
         a2: pGameFileName,
         a3: "GAMEROOT",
         a4: pRelativePath,
         a5: 260) )
  {
    g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "CONTENTROOT", a3: false, a4: pContentRoot, a5: 260);
    strchr(string: (unsigned __int8 *)pContentRoot, chr: 0x3Bu);
    if ( v3 != nullptr )
      *v3 = 0;
    V_ComposeFileName(path: pContentRoot, filename: pRelativePath, dest: pBuf, destSize: nBufLen);
  }
  else
  {
    V_strncpy(pDest: pBuf, pSrc: pGameFileName, maxLen: nBufLen);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C7A90
// Name: bool GenerateFullPath(char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl GenerateFullPath(char *pFileName, const char *pPathID, char *pBuf, int nBufLen)
{
  bool result; // al
  const char *v5; // eax
  char pDir[260]; // [esp+4h] [ebp-104h] BYREF

  if ( V_IsAbsolutePath(pStr: pFileName) )
  {
    V_strncpy(pDest: pBuf, pSrc: pFileName, maxLen: nBufLen);
    return true;
  }
  v5 = g_pFullFileSystem->RelativePathToFullPath(
         this: g_pFullFileSystem,
         a2: pFileName,
         a3: pPathID,
         a4: pBuf,
         a5: nBufLen,
         a6: 0,
         a7: 0);
  if ( v5 == nullptr || !V_IsAbsolutePath(pStr: v5) )
  {
    result = g_pFullFileSystem->GetCurrentDirectory(this: g_pFullFileSystem, a2: pDir, a3: 260);
    if ( !result )
      return result;
    V_ComposeFileName(path: pDir, filename: pFileName, dest: pBuf, destSize: nBufLen);
    V_RemoveDotSlashes(pFilename: pBuf, separator: 92);
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x005C7B40
// Name: void GetModContentSubdirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetModContentSubdirectory(const char *pSubDir, char *pBuf, unsigned int nBufLen)
{
  char pTemp[260]; // [esp+0h] [ebp-104h] BYREF

  GetModSubdirectory(pSubDir, pBuf: pTemp, nBufLen: 260);
  ComputeModContentFilename(pGameFileName: pTemp, pBuf, nBufLen);
}

} // namespace mdlcompile

// ============================================================
// Overlay from mksheet (Missing functions)
// ============================================================
namespace mksheet {

//------------------------------------------------------------------------------
// Address: 0x0049BB00
// Name: bool GenerateFullPath(char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl GenerateFullPath(char *pFileName, const char *pPathID, char *pBuf, int nBufLen)
{
  bool result; // al
  const char *v5; // eax
  char pDir[260]; // [esp+4h] [ebp-104h] BYREF

  if ( V_IsAbsolutePath(pStr: pFileName) )
  {
    V_strncpy(pDest: pBuf, pSrc: pFileName, maxLen: nBufLen);
    return true;
  }
  v5 = g_pFullFileSystem->RelativePathToFullPath(
         this: g_pFullFileSystem,
         a2: pFileName,
         a3: pPathID,
         a4: pBuf,
         a5: nBufLen,
         a6: 0,
         a7: 0);
  if ( v5 == nullptr || !V_IsAbsolutePath(pStr: v5) )
  {
    result = g_pFullFileSystem->GetCurrentDirectory(this: g_pFullFileSystem, a2: pDir, a3: 260);
    if ( !result )
      return result;
    V_ComposeFileName(path: pDir, filename: pFileName, dest: pBuf, destSize: nBufLen);
    V_RemoveDotSlashes(pFilename: pBuf, separator: 92);
  }
  return true;
}

} // namespace mksheet

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x0053B770
// Name: void GetModSubdirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetModSubdirectory(const char *pSubDir, char *pBuf, int nBufLen)
{
  _BYTE *v3; // eax
  unsigned int nLen; // [esp+14h] [ebp+8h]

  g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "MOD", a3: false, a4: pBuf, a5: nBufLen);
  strchr(string: (unsigned __int8 *)pBuf, chr: 0x3Bu);
  if ( v3 != nullptr )
    *v3 = 0;
  V_StripTrailingSlash(ppath: pBuf);
  if ( pSubDir != nullptr )
  {
    nLen = _V_strlen(str: pSubDir);
    V_strncat(pDest: pBuf, pSrc: "\\", destBufferSize: nBufLen, max_chars_to_copy: 1);
    V_strncat(pDest: pBuf, pSrc: pSubDir, destBufferSize: nBufLen, max_chars_to_copy: nLen);
  }
  V_FixSlashes(pname: pBuf, separator: 92);
}

//------------------------------------------------------------------------------
// Address: 0x0053B7F0
// Name: void ComputeModContentFilename(char const __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeModContentFilename(char *pGameFileName, char *pBuf, unsigned int nBufLen)
{
  _BYTE *v3; // eax
  char pRelativePath[260]; // [esp+4h] [ebp-208h] BYREF
  char pContentRoot[260]; // [esp+108h] [ebp-104h] BYREF

  if ( g_pFullFileSystem->FullPathToRelativePathEx(
         this: g_pFullFileSystem,
         a2: pGameFileName,
         a3: "GAMEROOT",
         a4: pRelativePath,
         a5: 260) )
  {
    g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "CONTENTROOT", a3: false, a4: pContentRoot, a5: 260);
    strchr(string: (unsigned __int8 *)pContentRoot, chr: 0x3Bu);
    if ( v3 != nullptr )
      *v3 = 0;
    V_ComposeFileName(path: pContentRoot, filename: pRelativePath, dest: pBuf, destSize: nBufLen);
  }
  else
  {
    V_strncpy(pDest: pBuf, pSrc: pGameFileName, maxLen: nBufLen);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053B8A0
// Name: bool GenerateFullPath(char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl GenerateFullPath(char *pFileName, const char *pPathID, char *pBuf, int nBufLen)
{
  bool result; // al
  const char *v5; // eax
  char pDir[260]; // [esp+4h] [ebp-104h] BYREF

  if ( V_IsAbsolutePath(pStr: pFileName) )
  {
    V_strncpy(pDest: pBuf, pSrc: pFileName, maxLen: nBufLen);
    return true;
  }
  v5 = g_pFullFileSystem->RelativePathToFullPath(
         this: g_pFullFileSystem,
         a2: pFileName,
         a3: pPathID,
         a4: pBuf,
         a5: nBufLen,
         a6: 0,
         a7: 0);
  if ( v5 == nullptr || !V_IsAbsolutePath(pStr: v5) )
  {
    result = g_pFullFileSystem->GetCurrentDirectory(this: g_pFullFileSystem, a2: pDir, a3: 260);
    if ( !result )
      return result;
    V_ComposeFileName(path: pDir, filename: pFileName, dest: pBuf, destSize: nBufLen);
    V_RemoveDotSlashes(pFilename: pBuf, separator: 92);
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x0053B950
// Name: void GetModContentSubdirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetModContentSubdirectory(const char *pSubDir, char *pBuf, unsigned int nBufLen)
{
  char pTemp[260]; // [esp+0h] [ebp-104h] BYREF

  GetModSubdirectory(pSubDir, pBuf: pTemp, nBufLen: 260);
  ComputeModContentFilename(pGameFileName: pTemp, pBuf, nBufLen);
}

} // namespace particle_import

// ============================================================
// Overlay from pcfmanager (Missing functions)
// ============================================================
namespace pcfmanager {

//------------------------------------------------------------------------------
// Address: 0x0046AC90
// Name: bool GenerateFullPath(char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl GenerateFullPath(char *pFileName, const char *pPathID, char *pBuf, int nBufLen)
{
  bool result; // al
  const char *v5; // eax
  char pDir[260]; // [esp+4h] [ebp-104h] BYREF

  if ( V_IsAbsolutePath(pStr: pFileName) )
  {
    V_strncpy(pDest: pBuf, pSrc: pFileName, maxLen: nBufLen);
    return true;
  }
  v5 = g_pFullFileSystem->RelativePathToFullPath(
         this: g_pFullFileSystem,
         a2: pFileName,
         a3: pPathID,
         a4: pBuf,
         a5: nBufLen,
         a6: 0,
         a7: 0);
  if ( v5 == nullptr || !V_IsAbsolutePath(pStr: v5) )
  {
    result = g_pFullFileSystem->GetCurrentDirectory(this: g_pFullFileSystem, a2: pDir, a3: 260);
    if ( !result )
      return result;
    V_ComposeFileName(path: pDir, filename: pFileName, dest: pBuf, destSize: nBufLen);
    V_RemoveDotSlashes(pFilename: pBuf, separator: 92);
  }
  return true;
}

} // namespace pcfmanager

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x0054F220
// Name: void GetModSubdirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetModSubdirectory(const char *pSubDir, char *pBuf, int nBufLen)
{
  _BYTE *v3; // eax
  unsigned int nLen; // [esp+14h] [ebp+8h]

  g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "MOD", a3: false, a4: pBuf, a5: nBufLen);
  strchr(string: (unsigned __int8 *)pBuf, chr: 0x3Bu);
  if ( v3 != nullptr )
    *v3 = 0;
  V_StripTrailingSlash(ppath: pBuf);
  if ( pSubDir != nullptr )
  {
    nLen = _V_strlen(str: pSubDir);
    V_strncat(pDest: pBuf, pSrc: "\\", destBufferSize: nBufLen, max_chars_to_copy: 1);
    V_strncat(pDest: pBuf, pSrc: pSubDir, destBufferSize: nBufLen, max_chars_to_copy: nLen);
  }
  V_FixSlashes(pname: pBuf, separator: 92);
}

//------------------------------------------------------------------------------
// Address: 0x0054F2A0
// Name: void ComputeModContentFilename(char const __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeModContentFilename(char *pGameFileName, char *pBuf, unsigned int nBufLen)
{
  _BYTE *v3; // eax
  char pRelativePath[260]; // [esp+4h] [ebp-208h] BYREF
  char pContentRoot[260]; // [esp+108h] [ebp-104h] BYREF

  if ( g_pFullFileSystem->FullPathToRelativePathEx(
         this: g_pFullFileSystem,
         a2: pGameFileName,
         a3: "GAMEROOT",
         a4: pRelativePath,
         a5: 260) )
  {
    g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "CONTENTROOT", a3: false, a4: pContentRoot, a5: 260);
    strchr(string: (unsigned __int8 *)pContentRoot, chr: 0x3Bu);
    if ( v3 != nullptr )
      *v3 = 0;
    V_ComposeFileName(path: pContentRoot, filename: pRelativePath, dest: pBuf, destSize: nBufLen);
  }
  else
  {
    V_strncpy(pDest: pBuf, pSrc: pGameFileName, maxLen: nBufLen);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0054F350
// Name: bool GenerateFullPath(char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl GenerateFullPath(char *pFileName, const char *pPathID, char *pBuf, int nBufLen)
{
  bool result; // al
  const char *v5; // eax
  char pDir[260]; // [esp+4h] [ebp-104h] BYREF

  if ( V_IsAbsolutePath(pStr: pFileName) )
  {
    V_strncpy(pDest: pBuf, pSrc: pFileName, maxLen: nBufLen);
    return true;
  }
  v5 = g_pFullFileSystem->RelativePathToFullPath(
         this: g_pFullFileSystem,
         a2: pFileName,
         a3: pPathID,
         a4: pBuf,
         a5: nBufLen,
         a6: 0,
         a7: 0);
  if ( v5 == nullptr || !V_IsAbsolutePath(pStr: v5) )
  {
    result = g_pFullFileSystem->GetCurrentDirectory(this: g_pFullFileSystem, a2: pDir, a3: 260);
    if ( !result )
      return result;
    V_ComposeFileName(path: pDir, filename: pFileName, dest: pBuf, destSize: nBufLen);
    V_RemoveDotSlashes(pFilename: pBuf, separator: 92);
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x0054F400
// Name: void GetModContentSubdirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetModContentSubdirectory(const char *pSubDir, char *pBuf, unsigned int nBufLen)
{
  char pTemp[260]; // [esp+0h] [ebp-104h] BYREF

  GetModSubdirectory(pSubDir, pBuf: pTemp, nBufLen: 260);
  ComputeModContentFilename(pGameFileName: pTemp, pBuf, nBufLen);
}

} // namespace phogen

// ============================================================
// Overlay from resourcesystem (Missing functions)
// ============================================================
namespace resourcesystem {

//------------------------------------------------------------------------------
// Address: 0x1001D4F0
// Name: void ComputeModContentFilename(char const __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeModContentFilename(char *pGameFileName, char *pBuf, unsigned int nBufLen)
{
  _BYTE *v3; // eax
  char pContentRoot[260]; // [esp+1Ch] [ebp-20Ch] BYREF
  char pRelativePath[264]; // [esp+120h] [ebp-108h] BYREF

  if ( g_pFullFileSystem->FullPathToRelativePathEx(
         this: g_pFullFileSystem,
         a2: pGameFileName,
         a3: "GAMEROOT",
         a4: &pRelativePath[4],
         a5: 260) )
  {
    g_pFullFileSystem->GetSearchPath(
      this: g_pFullFileSystem,
      a2: "CONTENTROOT",
      a3: false,
      a4: &pContentRoot[4],
      a5: 260);
    strchr(string: &pContentRoot[4], chr: 0x3Bu);
    if ( v3 != nullptr )
      *v3 = 0;
    V_ComposeFileName(path: &pContentRoot[4], filename: &pRelativePath[4], dest: pBuf, destSize: nBufLen);
  }
  else
  {
    V_strncpy(pDest: pBuf, pSrc: pGameFileName, maxLen: nBufLen);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D5A7
// Name: int _strlwr_s_l_stat(char __near *,unsigned int,struct localeinfo_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _strlwr_s_l_stat(char *string, unsigned int sizeInBytes, localeinfo_struct *plocinfo)
{
  int *v3; // eax
  unsigned int v4; // esi
  unsigned int v5; // ecx
  char *i; // ecx
  char v7; // al
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  void *v12; // esp
  unsigned __int8 *v13; // eax
  unsigned int v14; // [esp-4h] [ebp-1Ch]
  _DWORD v15[3]; // [esp+0h] [ebp-18h] BYREF
  int dstsize; // [esp+Ch] [ebp-Ch]
  unsigned __int8 *dst; // [esp+10h] [ebp-8h]

  if ( string == nullptr )
    goto LABEL_2;
  if ( strnlen(str: string, maxsize: sizeInBytes) >= sizeInBytes )
  {
    *string = 0;
LABEL_2:
    v3 = _errno();
    v14 = 22;
LABEL_3:
    v4 = v14;
    *v3 = v14;
    _invalid_parameter(a1: 0, a2: (unsigned int)string, a3: v14);
    return v4;
  }
  v5 = plocinfo->locinfo->lc_handle[2];
  if ( v5 != 0 )
  {
    v9 = __crtLCMapStringA(
           plocinfo,
           Locale: v5,
           dwMapFlags: 0x100u,
           lpSrcStr: string,
           cchSrc: -1,
           lpDestStr: nullptr,
           cchDest: 0,
           code_page: plocinfo->locinfo->lc_codepage,
           bError: 1);
    v10 = v9;
    dstsize = v9;
    if ( v9 == 0 )
    {
      *_errno() = 42;
      return *_errno();
    }
    if ( sizeInBytes < v9 )
    {
      *string = 0;
      v3 = _errno();
      v14 = 34;
      goto LABEL_3;
    }
    if ( v9 <= 0 || 0xFFFFFFE0 / v9 == 0 )
    {
      dst = nullptr;
      goto LABEL_28;
    }
    v11 = v9 + 8;
    if ( (unsigned int)(v10 + 8) > 0x400 )
    {
      v13 = (unsigned __int8 *)operator new(nSize: v10 + 8);
      if ( v13 != nullptr )
      {
        *(_DWORD *)v13 = 56797;
        goto LABEL_25;
      }
    }
    else
    {
      v12 = alloca(v11);
      v13 = (unsigned __int8 *)v15;
      if ( v15 != nullptr )
      {
        v15[0] = 52428;
LABEL_25:
        v13 += 8;
      }
    }
    v10 = dstsize;
    dst = v13;
LABEL_28:
    if ( dst != nullptr )
    {
      if ( __crtLCMapStringA(
             plocinfo,
             Locale: plocinfo->locinfo->lc_handle[2],
             dwMapFlags: 0x100u,
             lpSrcStr: string,
             cchSrc: -1,
             lpDestStr: (char *)dst,
             cchDest: v10,
             code_page: plocinfo->locinfo->lc_codepage,
             bError: 1) != 0 )
      {
        v4 = strcpy_s(a1: (unsigned int)string, _Dst: string, _SizeInBytes: sizeInBytes, _Src: (const char *)dst);
      }
      else
      {
        *_errno() = 42;
        v4 = 42;
      }
      _freea(_Memory: dst);
      return v4;
    }
    *_errno() = 12;
    return *_errno();
  }
  for ( i = string; *i != 0; ++i )
  {
    v7 = *i;
    if ( *i >= 65 && v7 <= 90 )
      *i = v7 + 32;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001D728
// Name: __strlwr_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _strlwr_s_l(char *string, unsigned int sizeInBytes, localeinfo_struct *plocinfo)
{
  unsigned int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _strlwr_s_l_stat(string, sizeInBytes, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001D75A
// Name: _strlwr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__usercall strlwr@<eax>(unsigned int a1@<edi>, unsigned int a2@<esi>, char *string)
{
  char *result; // eax
  char *i; // edx
  char v5; // cl

  if ( __locale_changed != 0 )
  {
    _strlwr_s_l(string, sizeInBytes: 0xFFFFFFFF, plocinfo: nullptr);
    return string;
  }
  else
  {
    result = string;
    if ( string != nullptr )
    {
      for ( i = string; *i != 0; ++i )
      {
        v5 = *i;
        if ( *i >= 65 && v5 <= 90 )
          *i = v5 + 32;
      }
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter(a1: 0, a2: a1, a3: a2);
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001D7C0
// Name: _dynamic_initializer_for__s_ResourceSystem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ResourceSystem__()
{
  CResourceSystem::CResourceSystem(this: &s_ResourceSystem);
  return atexit(func: dynamic_atexit_destructor_for__s_ResourceSystem__);
}

//------------------------------------------------------------------------------
// Address: 0x1001D7E0
// Name: _dynamic_initializer_for____g_CreateCResourceSystemIResourceSystem_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCResourceSystemIResourceSystem_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCResourceSystemIResourceSystem_reg,
           fn: (void *(__cdecl *)())_CreateCResourceSystemIResourceSystem_interface,
           pName: "ResourceSystem004");
}

//------------------------------------------------------------------------------
// Address: 0x1001D800
// Name: _dynamic_initializer_for__s_FileAtomicFactory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_FileAtomicFactory__()
{
  s_FileAtomicFactory.m_pNext = CResourceTypeManagerFactoryBase::sm_pFactoryList;
  CResourceTypeManagerFactoryBase::sm_pFactoryList = &s_FileAtomicFactory;
  return atexit(func: dynamic_atexit_destructor_for__s_FileAtomicFactory__);
}

} // namespace resourcesystem

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x006063B0
// Name: void GetModSubdirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetModSubdirectory(const char *pSubDir, char *pBuf, int nBufLen)
{
  _BYTE *v3; // eax
  unsigned int nLen; // [esp+14h] [ebp+8h]

  g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "MOD", a3: false, a4: pBuf, a5: nBufLen);
  strchr(string: (unsigned __int8 *)pBuf, chr: 0x3Bu);
  if ( v3 != nullptr )
    *v3 = 0;
  V_StripTrailingSlash(ppath: pBuf);
  if ( pSubDir != nullptr )
  {
    nLen = _V_strlen(str: pSubDir);
    V_strncat(pDest: pBuf, pSrc: "\\", destBufferSize: nBufLen, max_chars_to_copy: 1);
    V_strncat(pDest: pBuf, pSrc: pSubDir, destBufferSize: nBufLen, max_chars_to_copy: nLen);
  }
  V_FixSlashes(pname: pBuf, separator: 92);
}

//------------------------------------------------------------------------------
// Address: 0x00606430
// Name: void ComputeModContentFilename(char const __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeModContentFilename(char *pGameFileName, char *pBuf, unsigned int nBufLen)
{
  _BYTE *v3; // eax
  char pRelativePath[260]; // [esp+4h] [ebp-208h] BYREF
  char pContentRoot[260]; // [esp+108h] [ebp-104h] BYREF

  if ( g_pFullFileSystem->FullPathToRelativePathEx(
         this: g_pFullFileSystem,
         a2: pGameFileName,
         a3: "GAMEROOT",
         a4: pRelativePath,
         a5: 260) )
  {
    g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "CONTENTROOT", a3: false, a4: pContentRoot, a5: 260);
    strchr(string: (unsigned __int8 *)pContentRoot, chr: 0x3Bu);
    if ( v3 != nullptr )
      *v3 = 0;
    V_ComposeFileName(path: pContentRoot, filename: pRelativePath, dest: pBuf, destSize: nBufLen);
  }
  else
  {
    V_strncpy(pDest: pBuf, pSrc: pGameFileName, maxLen: nBufLen);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006064E0
// Name: bool GenerateFullPath(char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl GenerateFullPath(char *pFileName, const char *pPathID, char *pBuf, int nBufLen)
{
  bool result; // al
  const char *v5; // eax
  char pDir[260]; // [esp+4h] [ebp-104h] BYREF

  if ( V_IsAbsolutePath(pStr: pFileName) )
  {
    V_strncpy(pDest: pBuf, pSrc: pFileName, maxLen: nBufLen);
    return true;
  }
  v5 = g_pFullFileSystem->RelativePathToFullPath(
         this: g_pFullFileSystem,
         a2: pFileName,
         a3: pPathID,
         a4: pBuf,
         a5: nBufLen,
         a6: 0,
         a7: 0);
  if ( v5 == nullptr || !V_IsAbsolutePath(pStr: v5) )
  {
    result = g_pFullFileSystem->GetCurrentDirectory(this: g_pFullFileSystem, a2: pDir, a3: 260);
    if ( !result )
      return result;
    V_ComposeFileName(path: pDir, filename: pFileName, dest: pBuf, destSize: nBufLen);
    V_RemoveDotSlashes(pFilename: pBuf, separator: 92);
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x00606590
// Name: void GetModContentSubdirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetModContentSubdirectory(const char *pSubDir, char *pBuf, unsigned int nBufLen)
{
  char pTemp[260]; // [esp+0h] [ebp-104h] BYREF

  GetModSubdirectory(pSubDir, pBuf: pTemp, nBufLen: 260);
  ComputeModContentFilename(pGameFileName: pTemp, pBuf, nBufLen);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00550FC0
// Name: void GetModSubdirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetModSubdirectory(const char *pSubDir, char *pBuf, int nBufLen)
{
  _BYTE *v3; // eax
  unsigned int nLen; // [esp+14h] [ebp+8h]

  g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "MOD", a3: false, a4: pBuf, a5: nBufLen);
  strchr(string: (unsigned __int8 *)pBuf, chr: 0x3Bu);
  if ( v3 != nullptr )
    *v3 = 0;
  V_StripTrailingSlash(ppath: pBuf);
  if ( pSubDir != nullptr )
  {
    nLen = _V_strlen(str: pSubDir);
    V_strncat(pDest: pBuf, pSrc: "\\", destBufferSize: nBufLen, max_chars_to_copy: 1);
    V_strncat(pDest: pBuf, pSrc: pSubDir, destBufferSize: nBufLen, max_chars_to_copy: nLen);
  }
  V_FixSlashes(pname: pBuf, separator: 92);
}

//------------------------------------------------------------------------------
// Address: 0x00551040
// Name: void ComputeModContentFilename(char const __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeModContentFilename(char *pGameFileName, char *pBuf, unsigned int nBufLen)
{
  _BYTE *v3; // eax
  char pRelativePath[260]; // [esp+4h] [ebp-208h] BYREF
  char pContentRoot[260]; // [esp+108h] [ebp-104h] BYREF

  if ( g_pFullFileSystem->FullPathToRelativePathEx(
         this: g_pFullFileSystem,
         a2: pGameFileName,
         a3: "GAMEROOT",
         a4: pRelativePath,
         a5: 260) )
  {
    g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "CONTENTROOT", a3: false, a4: pContentRoot, a5: 260);
    strchr(string: (unsigned __int8 *)pContentRoot, chr: 0x3Bu);
    if ( v3 != nullptr )
      *v3 = 0;
    V_ComposeFileName(path: pContentRoot, filename: pRelativePath, dest: pBuf, destSize: nBufLen);
  }
  else
  {
    V_strncpy(pDest: pBuf, pSrc: pGameFileName, maxLen: nBufLen);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005510F0
// Name: bool GenerateFullPath(char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl GenerateFullPath(char *pFileName, const char *pPathID, char *pBuf, int nBufLen)
{
  bool result; // al
  const char *v5; // eax
  char pDir[260]; // [esp+4h] [ebp-104h] BYREF

  if ( V_IsAbsolutePath(pStr: pFileName) )
  {
    V_strncpy(pDest: pBuf, pSrc: pFileName, maxLen: nBufLen);
    return true;
  }
  v5 = g_pFullFileSystem->RelativePathToFullPath(
         this: g_pFullFileSystem,
         a2: pFileName,
         a3: pPathID,
         a4: pBuf,
         a5: nBufLen,
         a6: 0,
         a7: 0);
  if ( v5 == nullptr || !V_IsAbsolutePath(pStr: v5) )
  {
    result = g_pFullFileSystem->GetCurrentDirectory(this: g_pFullFileSystem, a2: pDir, a3: 260);
    if ( !result )
      return result;
    V_ComposeFileName(path: pDir, filename: pFileName, dest: pBuf, destSize: nBufLen);
    V_RemoveDotSlashes(pFilename: pBuf, separator: 92);
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x005511A0
// Name: void GetModContentSubdirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetModContentSubdirectory(const char *pSubDir, char *pBuf, unsigned int nBufLen)
{
  char pTemp[260]; // [esp+0h] [ebp-104h] BYREF

  GetModSubdirectory(pSubDir, pBuf: pTemp, nBufLen: 260);
  ComputeModContentFilename(pGameFileName: pTemp, pBuf, nBufLen);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x005C0780
// Name: void GetModSubdirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetModSubdirectory(const char *pSubDir, char *pBuf, int nBufLen)
{
  _BYTE *v3; // eax
  unsigned int nLen; // [esp+14h] [ebp+8h]

  g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "MOD", a3: false, a4: pBuf, a5: nBufLen);
  strchr(string: (unsigned __int8 *)pBuf, chr: 0x3Bu);
  if ( v3 != nullptr )
    *v3 = 0;
  V_StripTrailingSlash(ppath: pBuf);
  if ( pSubDir != nullptr )
  {
    nLen = _V_strlen(str: pSubDir);
    V_strncat(pDest: pBuf, pSrc: "\\", destBufferSize: nBufLen, max_chars_to_copy: 1);
    V_strncat(pDest: pBuf, pSrc: pSubDir, destBufferSize: nBufLen, max_chars_to_copy: nLen);
  }
  V_FixSlashes(pname: pBuf, separator: 92);
}

//------------------------------------------------------------------------------
// Address: 0x005C0800
// Name: void ComputeModContentFilename(char const __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeModContentFilename(char *pGameFileName, char *pBuf, unsigned int nBufLen)
{
  _BYTE *v3; // eax
  char pRelativePath[260]; // [esp+4h] [ebp-208h] BYREF
  char pContentRoot[260]; // [esp+108h] [ebp-104h] BYREF

  if ( g_pFullFileSystem->FullPathToRelativePathEx(
         this: g_pFullFileSystem,
         a2: pGameFileName,
         a3: "GAMEROOT",
         a4: pRelativePath,
         a5: 260) )
  {
    g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "CONTENTROOT", a3: false, a4: pContentRoot, a5: 260);
    strchr(string: (unsigned __int8 *)pContentRoot, chr: 0x3Bu);
    if ( v3 != nullptr )
      *v3 = 0;
    V_ComposeFileName(path: pContentRoot, filename: pRelativePath, dest: pBuf, destSize: nBufLen);
  }
  else
  {
    V_strncpy(pDest: pBuf, pSrc: pGameFileName, maxLen: nBufLen);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C08B0
// Name: bool GenerateFullPath(char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl GenerateFullPath(char *pFileName, const char *pPathID, char *pBuf, int nBufLen)
{
  bool result; // al
  const char *v5; // eax
  char pDir[260]; // [esp+4h] [ebp-104h] BYREF

  if ( V_IsAbsolutePath(pStr: pFileName) )
  {
    V_strncpy(pDest: pBuf, pSrc: pFileName, maxLen: nBufLen);
    return true;
  }
  v5 = g_pFullFileSystem->RelativePathToFullPath(
         this: g_pFullFileSystem,
         a2: pFileName,
         a3: pPathID,
         a4: pBuf,
         a5: nBufLen,
         a6: 0,
         a7: 0);
  if ( v5 == nullptr || !V_IsAbsolutePath(pStr: v5) )
  {
    result = g_pFullFileSystem->GetCurrentDirectory(this: g_pFullFileSystem, a2: pDir, a3: 260);
    if ( !result )
      return result;
    V_ComposeFileName(path: pDir, filename: pFileName, dest: pBuf, destSize: nBufLen);
    V_RemoveDotSlashes(pFilename: pBuf, separator: 92);
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x005C0960
// Name: void GetModContentSubdirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetModContentSubdirectory(const char *pSubDir, char *pBuf, unsigned int nBufLen)
{
  char pTemp[260]; // [esp+0h] [ebp-104h] BYREF

  GetModSubdirectory(pSubDir, pBuf: pTemp, nBufLen: 260);
  ComputeModContentFilename(pGameFileName: pTemp, pBuf, nBufLen);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x00547D60
// Name: void GetModSubdirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetModSubdirectory(const char *pSubDir, char *pBuf, int nBufLen)
{
  _BYTE *v3; // eax
  unsigned int nLen; // [esp+14h] [ebp+8h]

  g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "MOD", a3: false, a4: pBuf, a5: nBufLen);
  strchr(string: pBuf, chr: 0x3Bu);
  if ( v3 != nullptr )
    *v3 = 0;
  V_StripTrailingSlash(ppath: pBuf);
  if ( pSubDir != nullptr )
  {
    nLen = _V_strlen(str: pSubDir);
    V_strncat(pDest: pBuf, pSrc: "\\", destBufferSize: nBufLen, max_chars_to_copy: 1);
    V_strncat(pDest: pBuf, pSrc: pSubDir, destBufferSize: nBufLen, max_chars_to_copy: nLen);
  }
  V_FixSlashes(pname: pBuf, separator: 92);
}

//------------------------------------------------------------------------------
// Address: 0x00547DE0
// Name: void ComputeModContentFilename(char const __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeModContentFilename(char *pGameFileName, char *pBuf, unsigned int nBufLen)
{
  _BYTE *v3; // eax
  char pRelativePath[260]; // [esp+4h] [ebp-208h] BYREF
  char pContentRoot[260]; // [esp+108h] [ebp-104h] BYREF

  if ( g_pFullFileSystem->FullPathToRelativePathEx(
         this: g_pFullFileSystem,
         a2: pGameFileName,
         a3: "GAMEROOT",
         a4: pRelativePath,
         a5: 260) )
  {
    g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "CONTENTROOT", a3: false, a4: pContentRoot, a5: 260);
    strchr(string: pContentRoot, chr: 0x3Bu);
    if ( v3 != nullptr )
      *v3 = 0;
    V_ComposeFileName(path: pContentRoot, filename: pRelativePath, dest: pBuf, destSize: nBufLen);
  }
  else
  {
    V_strncpy(pDest: pBuf, pSrc: pGameFileName, maxLen: nBufLen);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00547E90
// Name: bool GenerateFullPath(char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl GenerateFullPath(char *pFileName, const char *pPathID, char *pBuf, int nBufLen)
{
  bool result; // al
  const char *v5; // eax
  char pDir[260]; // [esp+4h] [ebp-104h] BYREF

  if ( V_IsAbsolutePath(pStr: pFileName) )
  {
    V_strncpy(pDest: pBuf, pSrc: pFileName, maxLen: nBufLen);
    return true;
  }
  v5 = g_pFullFileSystem->RelativePathToFullPath(
         this: g_pFullFileSystem,
         a2: pFileName,
         a3: pPathID,
         a4: pBuf,
         a5: nBufLen,
         a6: 0,
         a7: 0);
  if ( v5 == nullptr || !V_IsAbsolutePath(pStr: v5) )
  {
    result = g_pFullFileSystem->GetCurrentDirectory(this: g_pFullFileSystem, a2: pDir, a3: 260);
    if ( !result )
      return result;
    V_ComposeFileName(path: pDir, filename: pFileName, dest: pBuf, destSize: nBufLen);
    V_RemoveDotSlashes(pFilename: pBuf, separator: 92);
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x00547F40
// Name: void GetModContentSubdirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetModContentSubdirectory(const char *pSubDir, char *pBuf, unsigned int nBufLen)
{
  char pTemp[260]; // [esp+0h] [ebp-104h] BYREF

  GetModSubdirectory(pSubDir, pBuf: pTemp, nBufLen: 260);
  ComputeModContentFilename(pGameFileName: pTemp, pBuf, nBufLen);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vcdupdate (Missing functions)
// ============================================================
namespace vcdupdate {

//------------------------------------------------------------------------------
// Address: 0x004183A0
// Name: void GetSearchPath(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetSearchPath(CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *path, const char *pPathID)
{
  int v2; // esi
  void *v3; // esp
  char *v4; // edi
  _BYTE *v5; // eax
  _BYTE *v6; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *m_pMemory; // ecx
  int v10; // eax
  CUtlString *v11; // edi
  _BYTE *v12; // eax
  unsigned __int8 v13[12]; // [esp+0h] [ebp-1Ch] BYREF
  CUtlString string; // [esp+Ch] [ebp-10h] BYREF

  v2 = g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: pPathID, a3: false, a4: nullptr, a5: 0);
  v3 = alloca(v2);
  v4 = (char *)v13;
  g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: pPathID, a3: false, a4: (char *)v13, a5: v2);
  strchr(string: v13, chr: 0x3Bu);
  v6 = v5;
  if ( v5 != nullptr )
  {
    do
    {
      *v6 = 0;
      CUtlString::CUtlString(this: &string, pString: v4);
      m_Size = path->m_Size;
      m_nAllocationCount = path->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>::Grow(
          this: &path->m_Memory,
          num: m_Size - m_nAllocationCount + 1);
      ++path->m_Size;
      m_pMemory = path->m_Memory.m_pMemory;
      v10 = path->m_Size - m_Size - 1;
      path->m_pElements = path->m_Memory.m_pMemory;
      if ( v10 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: 16 * v10);
      v11 = &path->m_Memory.m_pMemory[m_Size];
      if ( v11 != nullptr )
        CUtlString::CUtlString(this: v11, &string);
      string.m_Storage.m_nActualLength = 0;
      if ( string.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( string.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: string.m_Storage.m_Memory.m_pMemory);
          string.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        string.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      v4 = v6 + 1;
      strchr(string: v6 + 1, chr: 0x3Bu);
      v6 = v12;
    }
    while ( v12 != nullptr );
  }
  CUtlString::CUtlString(this: &string, pString: v4);
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: path, elem: path->m_Size, src: &string);
  string.m_Storage.m_nActualLength = 0;
  if ( string.m_Storage.m_Memory.m_nGrowSize >= 0 && string.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: string.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00418500
// Name: void AddFilesToList(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddFilesToList(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *list,
        const char *pDirectory,
        const char *pPathID,
        const char *pExtension)
{
  bool IsAbsolutePath; // al
  const char *(__thiscall *FindFirstEx)(IFileSystem *, const char *, const char *, int *); // edx
  int m_Size; // ebx
  const char *v7; // esi
  int v8; // esi
  CUtlString *m_pMemory; // ecx
  CUtlString *v10; // esi
  const char *FileExtension; // eax
  char *v12; // esi
  int v13; // esi
  int m_nAllocationCount; // eax
  CUtlString *v15; // ecx
  int v16; // eax
  CUtlString *v17; // esi
  CUtlString *v18; // esi
  const char *v19; // eax
  char pFullPathBuf[260]; // [esp+Ch] [ebp-348h] BYREF
  char pSearchString[260]; // [esp+110h] [ebp-244h] BYREF
  char pChildPath[260]; // [esp+214h] [ebp-140h] BYREF
  CUtlString string; // [esp+318h] [ebp-3Ch] BYREF
  CUtlString v24; // [esp+328h] [ebp-2Ch] BYREF
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > subDirs; // [esp+338h] [ebp-1Ch] BYREF
  int hFind; // [esp+34Ch] [ebp-8h] BYREF
  bool bIsAbsolute; // [esp+353h] [ebp-1h]

  V_snprintf(pDest: pSearchString, maxLen: 0x104u, pFormat: "%s\\*", pDirectory);
  IsAbsolutePath = V_IsAbsolutePath(pStr: pDirectory);
  FindFirstEx = g_pFullFileSystem->FindFirstEx;
  bIsAbsolute = IsAbsolutePath;
  m_Size = 0;
  v7 = FindFirstEx(this: g_pFullFileSystem, a2: pSearchString, a3: pPathID, a4: &hFind);
  memset(&subDirs, 0, sizeof(subDirs));
  for ( ; v7 != nullptr; v7 = g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: hFind) )
  {
    V_snprintf(pDest: pChildPath, maxLen: 0x104u, pFormat: "%s\\%s", pDirectory, v7);
    if ( g_pFullFileSystem->FindIsDirectory(this: g_pFullFileSystem, a2: hFind) )
    {
      if ( V_strnicmp(s1: v7, s2: ".", n: 2) != 0 && V_strnicmp(s1: v7, s2: "..", n: 3) != 0 )
      {
        CUtlString::CUtlString(this: &string, pString: pChildPath);
        v8 = m_Size;
        if ( m_Size + 1 > subDirs.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>::Grow(
            this: &subDirs.m_Memory,
            num: m_Size - subDirs.m_Memory.m_nAllocationCount + 1);
          m_Size = subDirs.m_Size;
        }
        m_pMemory = subDirs.m_Memory.m_pMemory;
        subDirs.m_Size = ++m_Size;
        subDirs.m_pElements = subDirs.m_Memory.m_pMemory;
        if ( m_Size - v8 - 1 > 0 )
        {
          _V_memmove(
            dest: (unsigned __int8 *)&subDirs.m_Memory.m_pMemory[v8 + 1],
            src: (unsigned __int8 *)&subDirs.m_Memory.m_pMemory[v8],
            count: 16 * (m_Size - v8 - 1));
          m_pMemory = subDirs.m_Memory.m_pMemory;
        }
        v10 = &m_pMemory[v8];
        if ( v10 != nullptr )
          CUtlString::CUtlString(this: v10, &string);
        string.m_Storage.m_nActualLength = 0;
        if ( string.m_Storage.m_Memory.m_nGrowSize >= 0 )
        {
          if ( string.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: string.m_Storage.m_Memory.m_pMemory);
            string.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          string.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
      }
    }
    else
    {
      FileExtension = V_GetFileExtension(path: v7);
      if ( _V_stricmp(s1: FileExtension, s2: pExtension) == 0 )
      {
        v12 = pFullPathBuf;
        if ( bIsAbsolute )
          v12 = pChildPath;
        else
          g_pFullFileSystem->RelativePathToFullPath(
            this: g_pFullFileSystem,
            a2: pChildPath,
            a3: pPathID,
            a4: pFullPathBuf,
            a5: 260,
            a6: FILTER_NONE,
            a7: nullptr);
        _V_strlower(start: v12);
        V_FixSlashes(pname: v12, separator: 92);
        CUtlString::CUtlString(this: &v24, pString: v12);
        v13 = list->m_Size;
        m_nAllocationCount = list->m_Memory.m_nAllocationCount;
        if ( v13 + 1 > m_nAllocationCount )
          CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>::Grow(
            this: &list->m_Memory,
            num: v13 - m_nAllocationCount + 1);
        ++list->m_Size;
        v15 = list->m_Memory.m_pMemory;
        v16 = list->m_Size - v13 - 1;
        list->m_pElements = list->m_Memory.m_pMemory;
        if ( v16 > 0 )
          _V_memmove(dest: (unsigned __int8 *)&v15[v13 + 1], src: (unsigned __int8 *)&v15[v13], count: 16 * v16);
        v17 = &list->m_Memory.m_pMemory[v13];
        if ( v17 != nullptr )
          CUtlString::CUtlString(this: v17, string: &v24);
        v24.m_Storage.m_nActualLength = 0;
        if ( v24.m_Storage.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v24.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v24.m_Storage.m_Memory.m_pMemory);
            v24.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          v24.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
      }
    }
  }
  g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: hFind);
  if ( m_Size > 0 )
  {
    v18 = subDirs.m_Memory.m_pMemory;
    do
    {
      v19 = CUtlString::operator char const *(this: v18);
      AddFilesToList(list, pDirectory: v19, pPathID, pExtension);
      ++v18;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: &subDirs);
  if ( subDirs.m_Memory.m_nGrowSize >= 0 && subDirs.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: subDirs.m_Memory.m_pMemory);
}

} // namespace vcdupdate

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00468C10
// Name: bool GenerateFullPath(char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl GenerateFullPath(char *pFileName, const char *pPathID, char *pBuf, int nBufLen)
{
  bool result; // al
  const char *v5; // eax
  char pDir[264]; // [esp+1Ch] [ebp-108h] BYREF

  if ( V_IsAbsolutePath(pStr: pFileName) )
  {
    V_strncpy(pDest: pBuf, pSrc: pFileName, maxLen: nBufLen);
    return true;
  }
  v5 = g_pFullFileSystem->RelativePathToFullPath(
         this: g_pFullFileSystem,
         a2: pFileName,
         a3: pPathID,
         a4: pBuf,
         a5: nBufLen,
         a6: 0,
         a7: 0);
  if ( v5 == nullptr || !V_IsAbsolutePath(pStr: v5) )
  {
    result = g_pFullFileSystem->GetCurrentDirectory(this: g_pFullFileSystem, a2: &pDir[4], a3: 260);
    if ( !result )
      return result;
    V_ComposeFileName(path: &pDir[4], filename: pFileName, dest: pBuf, destSize: nBufLen);
    V_RemoveDotSlashes(pFilename: pBuf, separator: 92);
  }
  return true;
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00650D80
// Name: void GetModSubdirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetModSubdirectory(const char *pSubDir, char *pBuf, int nBufLen)
{
  _BYTE *v3; // eax
  unsigned int nLen; // [esp+14h] [ebp+8h]

  g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "MOD", a3: false, a4: pBuf, a5: nBufLen);
  strchr(string: (unsigned __int8 *)pBuf, chr: 0x3Bu);
  if ( v3 != nullptr )
    *v3 = 0;
  V_StripTrailingSlash(ppath: pBuf);
  if ( pSubDir != nullptr )
  {
    nLen = _V_strlen(str: pSubDir);
    V_strncat(pDest: pBuf, pSrc: "\\", destBufferSize: nBufLen, max_chars_to_copy: 1);
    V_strncat(pDest: pBuf, pSrc: pSubDir, destBufferSize: nBufLen, max_chars_to_copy: nLen);
  }
  V_FixSlashes(pname: pBuf, separator: 92);
}

//------------------------------------------------------------------------------
// Address: 0x00650E00
// Name: void ComputeModContentFilename(char const __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeModContentFilename(char *pGameFileName, char *pBuf, unsigned int nBufLen)
{
  _BYTE *v3; // eax
  char pRelativePath[260]; // [esp+4h] [ebp-208h] BYREF
  char pContentRoot[260]; // [esp+108h] [ebp-104h] BYREF

  if ( g_pFullFileSystem->FullPathToRelativePathEx(
         this: g_pFullFileSystem,
         a2: pGameFileName,
         a3: "GAMEROOT",
         a4: pRelativePath,
         a5: 260) )
  {
    g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "CONTENTROOT", a3: false, a4: pContentRoot, a5: 260);
    strchr(string: (unsigned __int8 *)pContentRoot, chr: 0x3Bu);
    if ( v3 != nullptr )
      *v3 = 0;
    V_ComposeFileName(path: pContentRoot, filename: pRelativePath, dest: pBuf, destSize: nBufLen);
  }
  else
  {
    V_strncpy(pDest: pBuf, pSrc: pGameFileName, maxLen: nBufLen);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00650EB0
// Name: bool GenerateFullPath(char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl GenerateFullPath(char *pFileName, const char *pPathID, char *pBuf, int nBufLen)
{
  bool result; // al
  const char *v5; // eax
  char pDir[260]; // [esp+4h] [ebp-104h] BYREF

  if ( V_IsAbsolutePath(pStr: pFileName) )
  {
    V_strncpy(pDest: pBuf, pSrc: pFileName, maxLen: nBufLen);
    return true;
  }
  v5 = g_pFullFileSystem->RelativePathToFullPath(
         this: g_pFullFileSystem,
         a2: pFileName,
         a3: pPathID,
         a4: pBuf,
         a5: nBufLen,
         a6: 0,
         a7: 0);
  if ( v5 == nullptr || !V_IsAbsolutePath(pStr: v5) )
  {
    result = g_pFullFileSystem->GetCurrentDirectory(this: g_pFullFileSystem, a2: pDir, a3: 260);
    if ( !result )
      return result;
    V_ComposeFileName(path: pDir, filename: pFileName, dest: pBuf, destSize: nBufLen);
    V_RemoveDotSlashes(pFilename: pBuf, separator: 92);
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x00650F60
// Name: void GetModContentSubdirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetModContentSubdirectory(const char *pSubDir, char *pBuf, unsigned int nBufLen)
{
  char pTemp[260]; // [esp+0h] [ebp-104h] BYREF

  GetModSubdirectory(pSubDir, pBuf: pTemp, nBufLen: 260);
  ComputeModContentFilename(pGameFileName: pTemp, pBuf, nBufLen);
}

} // namespace vmap

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x100A2550
// Name: void ComputeModContentFilename(char const __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeModContentFilename(char *pGameFileName, char *pBuf, unsigned int nBufLen)
{
  _BYTE *v3; // eax
  char pRelativePath[260]; // [esp+4h] [ebp-208h] BYREF
  char pContentRoot[260]; // [esp+108h] [ebp-104h] BYREF

  if ( g_pFullFileSystem->FullPathToRelativePathEx(
         this: g_pFullFileSystem,
         a2: pGameFileName,
         a3: "GAMEROOT",
         a4: pRelativePath,
         a5: 260) )
  {
    g_pFullFileSystem->GetSearchPath(this: g_pFullFileSystem, a2: "CONTENTROOT", a3: false, a4: pContentRoot, a5: 260);
    strchr(string: (unsigned __int8 *)pContentRoot, chr: 0x3Bu);
    if ( v3 != nullptr )
      *v3 = 0;
    V_ComposeFileName(path: pContentRoot, filename: pRelativePath, dest: pBuf, destSize: nBufLen);
  }
  else
  {
    V_strncpy(pDest: pBuf, pSrc: pGameFileName, maxLen: nBufLen);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A2600
// Name: bool GenerateFullPath(char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl GenerateFullPath(char *pFileName, const char *pPathID, char *pBuf, int nBufLen)
{
  bool result; // al
  const char *v5; // eax
  char pDir[260]; // [esp+4h] [ebp-104h] BYREF

  if ( V_IsAbsolutePath(pStr: pFileName) )
  {
    V_strncpy(pDest: pBuf, pSrc: pFileName, maxLen: nBufLen);
    return true;
  }
  v5 = g_pFullFileSystem->RelativePathToFullPath(
         this: g_pFullFileSystem,
         a2: pFileName,
         a3: pPathID,
         a4: pBuf,
         a5: nBufLen,
         a6: 0,
         a7: 0);
  if ( v5 == nullptr || !V_IsAbsolutePath(pStr: v5) )
  {
    result = g_pFullFileSystem->GetCurrentDirectory(this: g_pFullFileSystem, a2: pDir, a3: 260);
    if ( !result )
      return result;
    V_ComposeFileName(path: pDir, filename: pFileName, dest: pBuf, destSize: nBufLen);
    V_RemoveDotSlashes(pFilename: pBuf, separator: 92);
  }
  return true;
}

} // namespace vtex_dll
