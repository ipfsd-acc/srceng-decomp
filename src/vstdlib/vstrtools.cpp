// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vstdlib/vstrtools.cpp
// Functions: 6
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1000F670
// Name: _V_UnicodeToUCS2
// Source: json
//------------------------------------------------------------------------------
int __cdecl V_UnicodeToUCS2(const wchar_t *pUnicode, int cubSrcInBytes, char *pUCS2, int cubDestSizeInBytes)
{
  int v4; // esi

  v4 = cubDestSizeInBytes;
  if ( cubSrcInBytes < cubDestSizeInBytes )
    v4 = cubSrcInBytes;
  V_wcsncpy(pDest: (wchar_t *)pUCS2, pSrc: pUnicode, maxLenInBytes: v4);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1000F6A0
// Name: _V_UTF8ToUnicode
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl V_UTF8ToUnicode(const char *pUTF8, wchar_t *pwchDest, unsigned int cubDestSizeInBytes)
{
  const char *result; // eax

  result = pUTF8;
  if ( pUTF8 != nullptr )
  {
    *pwchDest = 0;
    result = (const char *)MultiByteToWideChar(
                             CodePage: 0xFDE9u,
                             dwFlags: 0,
                             lpMultiByteStr: pUTF8,
                             cbMultiByte: -1,
                             lpWideCharStr: pwchDest,
                             cchWideChar: cubDestSizeInBytes >> 1);
    pwchDest[(cubDestSizeInBytes >> 1) - 1] = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000F6E0
// Name: _V_UnicodeToUTF8
// Source: json
//------------------------------------------------------------------------------
int __cdecl V_UnicodeToUTF8(const wchar_t *pUnicode, char *pUTF8, int cubDestSizeInBytes)
{
  int result; // eax

  if ( cubDestSizeInBytes > 0 )
    *pUTF8 = 0;
  result = WideCharToMultiByte(
             CodePage: 0xFDE9u,
             dwFlags: 0,
             lpWideCharStr: pUnicode,
             cchWideChar: -1,
             lpMultiByteStr: pUTF8,
             cbMultiByte: cubDestSizeInBytes,
             lpDefaultChar: nullptr,
             lpUsedDefaultChar: nullptr);
  if ( cubDestSizeInBytes > 0 )
    pUTF8[cubDestSizeInBytes - 1] = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000F720
// Name: _V_UCS2ToUnicode
// Source: json
//------------------------------------------------------------------------------
int __cdecl V_UCS2ToUnicode(wchar_t *pUCS2, wchar_t *pUnicode, unsigned int cubDestSizeInBytes)
{
  int v3; // edi

  *pUnicode = 0;
  v3 = 2 * _V_wcslen(pwch: pUCS2) + 2;
  if ( v3 >= (int)cubDestSizeInBytes )
    v3 = cubDestSizeInBytes;
  V_wcsncpy(pDest: pUCS2, pSrc: pUnicode, maxLenInBytes: v3);
  pUnicode[(cubDestSizeInBytes >> 1) - 1] = 0;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1000F770
// Name: _V_UCS2ToUTF8
// Source: json
//------------------------------------------------------------------------------
int __cdecl V_UCS2ToUTF8(const wchar_t *pUCS2, char *pUTF8, int cubDestSizeInBytes)
{
  int result; // eax

  *pUTF8 = 0;
  result = WideCharToMultiByte(
             CodePage: 0xFDE9u,
             dwFlags: 0,
             lpWideCharStr: pUCS2,
             cchWideChar: -1,
             lpMultiByteStr: pUTF8,
             cbMultiByte: cubDestSizeInBytes,
             lpDefaultChar: nullptr,
             lpUsedDefaultChar: nullptr);
  pUTF8[cubDestSizeInBytes - 1] = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000F7A0
// Name: _V_UTF8ToUCS2
// Source: json
//------------------------------------------------------------------------------
int __cdecl V_UTF8ToUCS2(const char *pUTF8, int cubSrcInBytes, wchar_t *pUCS2, unsigned int cubDestSizeInBytes)
{
  int result; // eax

  *pUCS2 = 0;
  result = MultiByteToWideChar(
             CodePage: 0xFDE9u,
             dwFlags: 0,
             lpMultiByteStr: pUTF8,
             cbMultiByte: -1,
             lpWideCharStr: pUCS2,
             cchWideChar: cubDestSizeInBytes >> 1);
  pUCS2[(cubDestSizeInBytes >> 1) - 1] = 0;
  return result;
}
