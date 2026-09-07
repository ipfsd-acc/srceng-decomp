// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: _libs/mod0877_Import:KERNEL32.cpp
// Functions: 13
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1030ED70
// Name: GetProcAddress(x,x)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
FARPROC __stdcall GetProcAddress(HMODULE hModule, LPCSTR lpProcName)
{
  return __imp__GetProcAddress@8(hModule, lpProcName);
}

//------------------------------------------------------------------------------
// Address: 0x1030ED76
// Name: RtlUnwind(x,x,x,x)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __stdcall RtlUnwind(PVOID TargetFrame, PVOID TargetIp, PEXCEPTION_RECORD ExceptionRecord, PVOID ReturnValue)
{
  __imp__RtlUnwind@16(TargetFrame, TargetIp, ExceptionRecord, ReturnValue);
}

//------------------------------------------------------------------------------
// Address: 0x1030ED7C
// Name: __fdopen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl _fdopen(int filedes, const char *mode)
{
  const char *v2; // ecx
  char v4; // al
  int v5; // ebx
  int v6; // esi
  int v7; // edx
  unsigned int v8; // ebx
  _iobuf *v9; // eax
  _iobuf *v10; // esi
  int _Expr_val; // [esp+34h] [ebp+Ch]

  v2 = mode;
  if ( mode == nullptr )
    goto LABEL_2;
  if ( filedes == -2 )
  {
    *_errno() = 9;
    return nullptr;
  }
  if ( filedes < 0 || filedes >= _nhandle || (__pioinfo[filedes >> 5][filedes & 0x1F].osfile & 1) == 0 )
  {
    *_errno() = 9;
    goto LABEL_3;
  }
  while ( *v2 == 32 )
    ++v2;
  v4 = *v2;
  if ( *v2 != 97 )
  {
    if ( v4 == 114 )
    {
      v5 = 1;
      goto LABEL_18;
    }
    if ( v4 != 119 )
    {
LABEL_2:
      *_errno() = 22;
LABEL_3:
      _invalid_parameter_noinfo();
      return nullptr;
    }
  }
  v5 = 2;
LABEL_18:
  v6 = 1;
  v7 = 0;
  _Expr_val = 0;
  v8 = _commode | v5;
  while ( *++v2 != 0 && v6 != 0 )
  {
    if ( *v2 != 32 )
    {
      switch ( *v2 )
      {
        case '+':
          if ( (v8 & 0x80u) == 0 )
            v8 = v8 & 0xFFFFFF7C | 0x80;
          else
LABEL_34:
            v6 = 0;
          break;
        case 'b':
          goto LABEL_27;
        case 'c':
          if ( v7 != 0 )
            goto LABEL_34;
          v7 = 1;
          v8 |= 0x4000u;
          break;
        case 'n':
          if ( v7 != 0 )
            goto LABEL_34;
          v7 = 1;
          v8 &= ~0x4000u;
          break;
        case 't':
LABEL_27:
          if ( _Expr_val != 0 )
            goto LABEL_34;
          _Expr_val = 1;
          break;
        default:
          goto LABEL_2;
      }
    }
  }
  while ( *v2 == 32 )
    ++v2;
  if ( *v2 != 0 )
    goto LABEL_2;
  v9 = _getstream();
  v10 = v9;
  if ( v9 != nullptr )
  {
    ++_cflush;
    v9->_flag = v8;
    v9->_file = filedes;
    _unlock_file(pf: v9);
    return v10;
  }
  else
  {
    *_errno() = 24;
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030EEF2
// Name: _strupr_s_l_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall strupr_s_l_stat@<eax>(char *string@<edi>, localeinfo_struct *plocinfo@<ebx>, unsigned int sizeInBytes)
{
  int *v3; // eax
  int v4; // esi
  LCID v5; // ecx
  char *i; // ecx
  char v7; // al
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  void *v12; // esp
  unsigned __int8 *v13; // eax
  int v14; // [esp-4h] [ebp-14h]
  int v15; // [esp+0h] [ebp-10h] BYREF
  int dstsize; // [esp+4h] [ebp-Ch]
  unsigned __int8 *dst; // [esp+8h] [ebp-8h]

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
    _invalid_parameter_noinfo();
    return v4;
  }
  v5 = plocinfo->locinfo->lc_handle[2];
  if ( v5 != 0 )
  {
    v9 = __crtLCMapStringA(
           plocinfo,
           Locale: v5,
           dwMapFlags: 0x200u,
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
      v13 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v10 + 8);
      if ( v13 != nullptr )
      {
        *(_DWORD *)v13 = 56797;
        goto LABEL_25;
      }
    }
    else
    {
      v12 = alloca(v11);
      v13 = (unsigned __int8 *)&v15;
      if ( &v15 != nullptr )
      {
        v15 = 52428;
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
             dwMapFlags: 0x200u,
             lpSrcStr: string,
             cchSrc: -1,
             lpDestStr: (char *)dst,
             cchDest: v10,
             code_page: plocinfo->locinfo->lc_codepage,
             bError: 1) != 0 )
      {
        v4 = strcpy_s(_Dst: string, _SizeInBytes: sizeInBytes, _Src: (const char *)dst);
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
    if ( *i >= 97 && v7 <= 122 )
      *i = v7 - 32;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1030F066
// Name: __strupr_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _strupr_s_l(char *string, unsigned int sizeInBytes, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = strupr_s_l_stat(string, plocinfo: &_loc_update.localeinfo, sizeInBytes);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1030F09B
// Name: _strupr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strupr(char *string)
{
  char *result; // eax
  char *i; // edx
  char v3; // cl

  if ( __locale_changed != 0 )
  {
    _strupr_s_l(string, sizeInBytes: 0xFFFFFFFF, plocinfo: nullptr);
    return string;
  }
  else
  {
    result = string;
    if ( string != nullptr )
    {
      for ( i = string; *i != 0; ++i )
      {
        v3 = *i;
        if ( *i >= 97 && v3 <= 122 )
          *i = v3 - 32;
      }
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1030F0F8
// Name: int _strlwr_s_l_stat(char __near *,unsigned int,struct localeinfo_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _strlwr_s_l_stat(char *string, unsigned int sizeInBytes, localeinfo_struct *plocinfo)
{
  int *v3; // eax
  int v4; // esi
  LCID v5; // ecx
  char *i; // ecx
  char v7; // al
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  void *v12; // esp
  unsigned __int8 *v13; // eax
  int v14; // [esp-4h] [ebp-1Ch]
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
    _invalid_parameter_noinfo();
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
      v13 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v10 + 8);
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
        v4 = strcpy_s(_Dst: string, _SizeInBytes: sizeInBytes, _Src: (const char *)dst);
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
// Address: 0x1030F276
// Name: __strlwr_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _strlwr_s_l(char *string, unsigned int sizeInBytes, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _strlwr_s_l_stat(string, sizeInBytes, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1030F2AA
// Name: _strlwr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strlwr(char *string)
{
  char *result; // eax
  char *i; // edx
  char v3; // cl

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
        v3 = *i;
        if ( *i >= 65 && v3 <= 90 )
          *i = v3 + 32;
      }
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1030F307
// Name: __wcsicmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wcsicmp_l(wchar_t *dst, wchar_t *src, localeinfo_struct *plocinfo)
{
  unsigned __int16 *v3; // ebx
  int result; // eax
  unsigned __int16 *v5; // edi
  int v6; // ebx
  unsigned int v7; // eax
  unsigned __int16 v8; // si
  unsigned int v9; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v3 = dst;
  if ( dst != nullptr )
  {
    v5 = src;
    if ( src != nullptr )
    {
      if ( _loc_update.localeinfo.locinfo->lc_handle[2] != 0 )
      {
        do
        {
          v8 = _towlower_l(c: *v3++, plocinfo: &_loc_update.localeinfo);
          LOWORD(v9) = _towlower_l(c: *v5++, plocinfo: &_loc_update.localeinfo);
        }
        while ( v8 != 0 && v8 == (_WORD)v9 );
      }
      else
      {
        v6 = (char *)dst - (char *)src;
        do
        {
          v7 = *(unsigned __int16 *)((char *)v5 + v6);
          if ( v7 < 0x41 || v7 > 0x5A )
            v8 = *(unsigned __int16 *)((char *)v5 + v6);
          else
            v8 = v7 + 32;
          v9 = *v5;
          if ( v9 >= 0x41 && v9 <= 0x5A )
            LOWORD(v9) = v9 + 32;
          ++v5;
        }
        while ( v8 != 0 && v8 == (_WORD)v9 );
      }
      result = v8 - (unsigned __int16)v9;
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 0x7FFFFFFF;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0x7FFFFFFF;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1030F40A
// Name: __wcsicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wcsicmp(wchar_t *dst, wchar_t *src)
{
  wchar_t *v3; // ecx
  int v4; // esi
  unsigned int v5; // eax
  unsigned __int16 v6; // dx
  unsigned int v7; // eax

  if ( __locale_changed != 0 )
    return _wcsicmp_l(dst, src, plocinfo: nullptr);
  if ( dst != nullptr && (v3 = src, src != nullptr) )
  {
    v4 = (char *)dst - (char *)src;
    do
    {
      v5 = *(wchar_t *)((char *)v3 + v4);
      if ( v5 < 0x41 || v5 > 0x5A )
        v6 = *(wchar_t *)((char *)v3 + v4);
      else
        v6 = v5 + 32;
      v7 = *v3;
      if ( v7 >= 0x41 && v7 <= 0x5A )
        LOWORD(v7) = v7 + 32;
      ++v3;
    }
    while ( v6 != 0 && v6 == (_WORD)v7 );
    return v6 - (unsigned __int16)v7;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0x7FFFFFFF;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1030F495
// Name: __wcsnicmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wcsnicmp_l(wchar_t *first, wchar_t *last, unsigned int count, localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned __int16 *v5; // ebx
  unsigned __int16 *v6; // edi
  int v7; // ebx
  unsigned int v8; // eax
  unsigned __int16 v9; // si
  unsigned int v10; // eax
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-10h] BYREF

  result = 0;
  if ( count != 0 )
  {
    v5 = first;
    if ( first != nullptr && (v6 = last, last != nullptr) )
    {
      _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
      if ( _loc_update.localeinfo.locinfo->lc_handle[2] != 0 )
      {
        do
        {
          v9 = _towlower_l(c: *v5, plocinfo: &_loc_update.localeinfo);
          LOWORD(v10) = _towlower_l(c: *v6, plocinfo: &_loc_update.localeinfo);
          ++v5;
          ++v6;
          --count;
        }
        while ( count != 0 && v9 != 0 && v9 == (_WORD)v10 );
      }
      else
      {
        v7 = (char *)first - (char *)last;
        do
        {
          v8 = *(unsigned __int16 *)((char *)v6 + v7);
          if ( v8 < 0x41 || v8 > 0x5A )
            v9 = *(unsigned __int16 *)((char *)v6 + v7);
          else
            v9 = v8 + 32;
          v10 = *v6;
          if ( v10 >= 0x41 && v10 <= 0x5A )
            LOWORD(v10) = v10 + 32;
          ++v6;
          --count;
        }
        while ( count != 0 && v9 != 0 && v9 == (_WORD)v10 );
      }
      result = v9 - (unsigned __int16)v10;
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return 0x7FFFFFFF;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1030F57A
// Name: __wcsnicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wcsnicmp(wchar_t *first, wchar_t *last, unsigned int count)
{
  int result; // eax
  wchar_t *v4; // ecx
  int v5; // esi
  unsigned int v6; // eax
  unsigned __int16 v7; // dx
  unsigned int v8; // eax

  if ( __locale_changed != 0 )
    return _wcsnicmp_l(first, last, count, plocinfo: nullptr);
  result = 0;
  if ( count != 0 )
  {
    if ( first != nullptr && (v4 = last, last != nullptr) )
    {
      v5 = (char *)first - (char *)last;
      do
      {
        v6 = *(wchar_t *)((char *)v4 + v5);
        if ( v6 < 0x41 || v6 > 0x5A )
          v7 = *(wchar_t *)((char *)v4 + v5);
        else
          v7 = v6 + 32;
        v8 = *v4;
        if ( v8 >= 0x41 && v8 <= 0x5A )
          LOWORD(v8) = v8 + 32;
        ++v4;
        --count;
      }
      while ( count != 0 && v7 != 0 && v7 == (_WORD)v8 );
      return v7 - (unsigned __int16)v8;
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return 0x7FFFFFFF;
    }
  }
  return result;
}
