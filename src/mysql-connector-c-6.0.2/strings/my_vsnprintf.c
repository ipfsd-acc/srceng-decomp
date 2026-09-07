// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/my_vsnprintf.c
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0040F480
// Name: _my_vsnprintf
// Source: json
//------------------------------------------------------------------------------
_EXCEPTION_DISPOSITION __cdecl my_vsnprintf(
        _EXCEPTION_RECORD *to,
        _EXCEPTION_REGISTRATION_RECORD *n,
        _CONTEXT *fmt,
        char *ap)
{
  char *v4; // ebx
  _CONTEXT *v5; // edi
  char ContextFlags; // al
  char *v7; // ebp
  bool v8; // zf
  unsigned __int8 v9; // al
  unsigned int v10; // edx
  unsigned int v11; // esi
  unsigned int v12; // eax
  unsigned __int8 v13; // al
  char v14; // cl
  const char *v15; // ebp
  char *v16; // edi
  unsigned int v17; // eax
  int v18; // eax
  unsigned __int8 *v19; // ebp
  char v20; // dl
  _BYTE *v21; // edi
  signed int v22; // eax
  unsigned int v23; // esi
  unsigned int v24; // ebp
  int v25; // eax
  unsigned int v26; // ebp
  unsigned int v27; // esi
  unsigned int v28; // esi
  unsigned __int64 v29; // st7
  int v30; // eax
  _EXCEPTION_DISPOSITION result; // eax
  char *v32; // [esp+28h] [ebp-44h]
  unsigned int have_longlong; // [esp+2Ch] [ebp-40h]
  _CONTEXT *v34; // [esp+30h] [ebp-3Ch]
  unsigned int length; // [esp+34h] [ebp-38h]
  char *end; // [esp+38h] [ebp-34h]
  unsigned int pre_zero; // [esp+3Ch] [ebp-30h]
  unsigned int to_length; // [esp+40h] [ebp-2Ch]
  char *start; // [esp+44h] [ebp-28h]
  _BYTE v40[32]; // [esp+48h] [ebp-24h] BYREF

  v4 = (char *)to;
  v5 = fmt;
  end = (char *)to + (_DWORD)n - 1;
  ContextFlags = fmt->ContextFlags;
  start = (char *)to;
  if ( ContextFlags != 0 )
  {
    v32 = ap - 8;
    v7 = ap - 4;
    do
    {
      if ( ContextFlags != 37 )
      {
        if ( v4 == end )
          break;
        *v4 = ContextFlags;
        goto LABEL_86;
      }
      v5 = (_CONTEXT *)((char *)v5 + 1);
      v8 = LOBYTE(v5->ContextFlags) == 45;
      v34 = v5;
      if ( v8 )
      {
        v5 = (_CONTEXT *)((char *)v5 + 1);
        v34 = v5;
      }
      v9 = v5->ContextFlags;
      v10 = 0;
      v11 = 0;
      length = 0;
      have_longlong = 0;
      pre_zero = 0;
      if ( v9 == 42 )
      {
        v12 = *((_DWORD *)v7 + 1);
        v7 += 4;
        v5 = (_CONTEXT *)((char *)v5 + 1);
        v32 += 4;
        v34 = v5;
        length = v12;
      }
      else
      {
        if ( (*((_BYTE *)off_4904A8 + v9 + 1) & 4) != 0 )
        {
          do
          {
            length = (char)v9 + 10 * length - 48;
            if ( length == 0 )
              pre_zero = 1;
            v9 = BYTE1(v5->ContextFlags);
            v5 = (_CONTEXT *)((char *)v5 + 1);
          }
          while ( (*((_BYTE *)off_4904A8 + v9 + 1) & 4) != 0 );
          v34 = v5;
        }
        v10 = have_longlong;
      }
      if ( LOBYTE(v5->ContextFlags) == 46 )
      {
        v13 = BYTE1(v5->ContextFlags);
        v5 = (_CONTEXT *)((char *)v5 + 1);
        v34 = v5;
        if ( v13 == 42 )
        {
          v11 = *((_DWORD *)v7 + 1);
          v5 = (_CONTEXT *)((char *)v5 + 1);
          v7 += 4;
          v32 += 4;
          v34 = v5;
        }
        else
        {
          if ( (*((_BYTE *)off_4904A8 + v13 + 1) & 4) != 0 )
          {
            do
            {
              v5 = (_CONTEXT *)((char *)v5 + 1);
              v11 = (char)v13 + 10 * v11 - 48;
              v13 = v5->ContextFlags;
            }
            while ( (*((_BYTE *)off_4904A8 + LOBYTE(v5->ContextFlags) + 1) & 4) != 0 );
            v34 = v5;
          }
          v10 = have_longlong;
        }
      }
      else
      {
        v11 = -1;
      }
      if ( LOBYTE(v5->ContextFlags) == 108 )
      {
        v5 = (_CONTEXT *)((char *)v5 + 1);
        v34 = v5;
        if ( LOBYTE(v5->ContextFlags) == 108 )
        {
          v5 = (_CONTEXT *)((char *)v5 + 1);
          v34 = v5;
          v10 = 1;
          goto LABEL_30;
        }
      }
      else
      {
        if ( LOBYTE(v5->ContextFlags) != 122 )
          goto LABEL_30;
        v5 = (_CONTEXT *)((char *)v5 + 1);
        v34 = v5;
      }
      v10 = 0;
LABEL_30:
      v14 = v5->ContextFlags;
      if ( LOBYTE(v5->ContextFlags) == 115 )
      {
        v32 += 4;
        have_longlong = (unsigned int)(v7 + 4);
        v15 = *((const char **)v7 + 1);
        v16 = (char *)(end - v4 + 1);
        if ( v15 == nullptr )
          v15 = "(null)";
        v17 = strnlen(str: v15, maxsize: v11);
        if ( (unsigned int)v16 <= v17 )
          v17 = (unsigned int)(v16 - 1);
        v18 = strnmov(dst: v4, src: (tagShutdownType)v15, n: v17);
        v7 = (char *)have_longlong;
        v5 = v34;
        v4 = (char *)v18;
        goto LABEL_87;
      }
      if ( v14 == 98 )
      {
        v32 += 4;
        have_longlong = (unsigned int)(v7 + 4);
        v19 = *((unsigned __int8 **)v7 + 1);
        if ( &v4[v11 + 1] > end )
          v11 = end - v4 - 1;
        memmove(dst: (unsigned __int8 *)v4, src: v19, count: v11);
        v7 = (char *)have_longlong;
        v5 = v34;
        v4 += v11;
        goto LABEL_87;
      }
      if ( v14 == 102 || v14 == 103 )
      {
        v29 = *((unsigned __int64 *)v32 + 1);
        have_longlong = (unsigned int)(v7 + 8);
        v32 += 8;
        if ( v11 == -1 )
        {
          v11 = 6;
        }
        else if ( v11 >= 0x1F )
        {
          v11 = 30;
        }
        if ( v11 >= end - v4 - 1 )
          v11 = end - v4 - 1;
        if ( v14 == 102 )
          LOWORD(v30) = my_fcvt();
        else
          v30 = my_gcvt(a1: v29, a2: HIDWORD(v29), a3: 1, a4: v11, a5: v4, a6: 0);
        v5 = v34;
        v7 = (char *)have_longlong;
        v4 += v30;
LABEL_84:
        if ( v4 == end )
          break;
        *v4 = 37;
LABEL_86:
        ++v4;
        goto LABEL_87;
      }
      if ( v14 != 100 && v14 != 117 && v14 != 120 && v14 != 88 && v14 != 112 )
      {
        if ( v14 != 99 )
          goto LABEL_84;
        if ( v4 == end )
          break;
        v20 = v7[4];
        v7 += 4;
        v32 += 4;
        *v4 = v20;
        goto LABEL_86;
      }
      v21 = v4;
      if ( v14 == 112 )
        v10 = 0;
      to_length = end - v4;
      if ( (unsigned int)(end - v4) < 0x10 || length != 0 )
        v21 = v40;
      if ( v10 != 0 )
      {
        v22 = *((_DWORD *)v32 + 2);
        v23 = *((_DWORD *)v32 + 3);
        v24 = (unsigned int)(v7 + 8);
        v32 += 8;
      }
      else
      {
        v32 += 4;
        v22 = *((_DWORD *)v7 + 1);
        v24 = (unsigned int)(v7 + 4);
        if ( v14 == 100 )
          v23 = v22 >> 31;
        else
          v23 = 0;
      }
      have_longlong = v24;
      if ( v14 == 100 || v14 == 117 )
      {
        longlong10_to_str(val: (void *)v22, dst: v23, radix: v21);
      }
      else
      {
        if ( v14 == 112 )
        {
          *v21 = 48;
          v21[1] = 120;
        }
        ll2str(val: v22);
      }
      v26 = v25 - (_DWORD)v21;
      if ( v25 - (int)v21 > to_length )
        break;
      if ( v21 == v40 )
      {
        v27 = length;
        if ( length >= to_length )
        {
          length = to_length;
          v27 = to_length;
        }
        if ( v26 < v27 )
        {
          v28 = v27 - v26;
          memset(dst: (unsigned __int8 *)v4, value: pre_zero != 0 ? 48 : 32, count: v28);
          v4 += v28;
        }
        memmove(dst: (unsigned __int8 *)v4, src: v21, count: v26);
      }
      v5 = v34;
      v4 += v26;
      v7 = (char *)have_longlong;
LABEL_87:
      ContextFlags = BYTE1(v5->ContextFlags);
      v5 = (_CONTEXT *)((char *)v5 + 1);
    }
    while ( ContextFlags != 0 );
  }
  result = v4 - start;
  *v4 = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040F860
// Name: _my_snprintf
// Source: json
//------------------------------------------------------------------------------
_cpinfo *my_snprintf(_cpinfo *result, _EXCEPTION_REGISTRATION_RECORD *n, _CONTEXT *fmt, ...)
{
  va_list ap; // [esp+10h] [ebp+10h] BYREF

  va_start(ap, fmt);
  return (_cpinfo *)my_vsnprintf(to: (_EXCEPTION_RECORD *)result, n, fmt, ap);
}
