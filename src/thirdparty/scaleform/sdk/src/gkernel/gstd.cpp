// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gkernel/gstd.cpp
// Functions: 7
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1006A260
// Name: int G_stricmp(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl G_stricmp(const char *a1, const char *a2)
{
  return _stricmp(dst: a1, src: a2);
}

//------------------------------------------------------------------------------
// Address: 0x1006A270
// Name: wchar_t __near * G_wcsncpy(wchar_t __near *,unsigned int,wchar_t const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
wchar_t *__cdecl G_wcsncpy(wchar_t *dest, unsigned int destsize, const wchar_t *count, unsigned int _Count)
{
  wcsncpy_s(_Dst: dest, _SizeInWords: destsize, _Src: count, _Count);
  return dest;
}

//------------------------------------------------------------------------------
// Address: 0x1006A2A0
// Name: int G_wcscmp(wchar_t const __near *,wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall G_wcscmp(unsigned __int16 a, const unsigned __int16 *b, const unsigned __int16 *b_4)
{
  return wcscmp(b, b_4);
}

//------------------------------------------------------------------------------
// Address: 0x1006A2E0
// Name: double G_strtod(char const __near *,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl G_strtod(char *_Src, char **endptr)
{
  char v2; // bl
  CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *p_buffer; // eax
  CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > buffer; // [esp+Ch] [ebp-160h] BYREF

  v2 = *localeconv()->decimal_point;
  if ( v2 == 46 )
  {
    strtod(nptr: _Src, endptr);
  }
  else
  {
    strcpy_s(_Dst: (char *)&buffer, _SizeInBytes: 0x15Cu, _Src);
    p_buffer = &buffer;
    if ( LOBYTE(buffer.CFunctor::IRefCounted::__vftable) != 0 )
    {
      while ( LOBYTE(p_buffer->CFunctor::IRefCounted::__vftable) != 46 )
      {
        p_buffer = (CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> > *)((char *)p_buffer + 1);
        if ( LOBYTE(p_buffer->CFunctor::IRefCounted::__vftable) == 0 )
          goto LABEL_5;
      }
      LOBYTE(p_buffer->CFunctor::IRefCounted::__vftable) = v2;
    }
LABEL_5:
    strtod(nptr: (const char *)&buffer, endptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006A370
// Name: int G_towupper(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall G_towupper(const CFileSystemPassThru *charCode, wchar_t charCodea)
{
  int v2; // ecx
  int v3; // edx
  int v4; // esi
  int v5; // ecx
  int v6; // edx

  v2 = HIBYTE(charCodea);
  v3 = *((unsigned __int16 *)&G_UnicodeToUpperBits + v2);
  if ( *((_WORD *)&G_UnicodeToUpperBits + v2) != 0
    && (v3 == 1
     || (*((unsigned __int16 *)&G_UnicodeToUpperBits + v3 + ((unsigned __int8)charCodea >> 4)) & (1 << (charCodea & 0xF))) != 0) )
  {
    v4 = 0;
    v5 = 636;
    do
    {
      v6 = (v5 >> 1) + v4;
      if ( *((_WORD *)&G_UnicodeToUpperTable + 2 * v6) >= charCodea )
      {
        v5 >>= 1;
      }
      else
      {
        v4 = v6 + 1;
        v5 += -1 - (v5 >> 1);
      }
    }
    while ( v5 > 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006A3F0
// Name: int G_towlower(wchar_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall G_towlower(const CFileSystemPassThru *charCode, wchar_t charCodea)
{
  int v2; // ecx
  int v3; // edx
  int v4; // esi
  int v5; // ecx
  int v6; // edx

  v2 = HIBYTE(charCodea);
  v3 = *((unsigned __int16 *)&G_UnicodeToLowerBits.m_ConCommandAccessor.__vftable + v2);
  if ( *((_WORD *)&G_UnicodeToLowerBits.m_ConCommandAccessor.__vftable + v2) != 0
    && (v3 == 1
     || (*((unsigned __int16 *)&G_UnicodeToLowerBits.m_ConCommandAccessor.__vftable
         + v3
         + ((unsigned __int8)charCodea >> 4))
       & (1 << (charCodea & 0xF))) != 0) )
  {
    v4 = 0;
    v5 = 673;
    do
    {
      v6 = (v5 >> 1) + v4;
      if ( (unsigned __int16)G_UnicodeToLowerTable[2 * v6] >= charCodea )
      {
        v5 >>= 1;
      }
      else
      {
        v4 = v6 + 1;
        v5 += -1 - (v5 >> 1);
      }
    }
    while ( v5 > 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102529B0
// Name: unsigned int G_wcslen(wchar_t const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl G_wcslen(const wchar_t *pwch)
{
  return wcslen(pwch);
}
