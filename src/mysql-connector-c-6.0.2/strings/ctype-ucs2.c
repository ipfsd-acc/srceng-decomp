// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/ctype-ucs2.c
// Functions: 65
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004304B0
// Name: my_strntol_mb2_or_mb4
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_strntol_mb2_or_mb4(
        LIST_ENTRY32 *cs,
        signed int nptr,
        int l,
        unsigned int base,
        unsigned int *a5,
        int *err)
{
  unsigned int v6; // esi
  char *v8; // ebx
  unsigned int v9; // ebp
  int v10; // eax
  int v12; // eax
  bool v13; // zf
  signed int v14; // eax
  bool v15; // cc
  char *v16; // [esp-4h] [ebp-20h]
  BOOL negative; // [esp+10h] [ebp-Ch]
  unsigned int v18; // [esp+14h] [ebp-8h]
  const LoggingContext_t *save; // [esp+18h] [ebp-4h]
  unsigned int v20; // [esp+20h] [ebp+4h]

  v6 = nptr;
  v8 = (char *)(nptr + l);
  v16 = (char *)(nptr + l);
  v9 = 0;
  *err = 0;
  negative = false;
  v10 = (*(int (__cdecl **)(LIST_ENTRY32 *, signed int *, unsigned int, char *))(cs[12].Blink + 32))(
          a1: cs,
          a2: &nptr,
          a3: v6,
          a4: v16);
  if ( v10 <= 0 )
  {
LABEL_5:
    if ( a5 != nullptr )
      *a5 = v6;
    *err = v10 != 0 ? 33 : 42;
    return 0;
  }
  else
  {
    while ( 2 )
    {
      switch ( nptr )
      {
        case 9:
        case 32:
        case 43:
          goto $LN29_1;
        case 45:
          negative = !negative;
$LN29_1:
          v6 += v10;
          v10 = (*(int (__cdecl **)(LIST_ENTRY32 *, signed int *, unsigned int, char *))(cs[12].Blink + 32))(
                  a1: cs,
                  a2: &nptr,
                  a3: v6,
                  a4: v8);
          if ( v10 <= 0 )
            goto LABEL_5;
          continue;
        default:
          l = 0;
          save = (const LoggingContext_t *)v6;
          v20 = 0xFFFFFFFF / base;
          v18 = 0xFFFFFFFF % base;
          v12 = (*(int (__cdecl **)(LIST_ENTRY32 *, signed int *, unsigned int, char *))(cs[12].Blink + 32))(
                  a1: cs,
                  a2: &nptr,
                  a3: v6,
                  a4: v8);
          v13 = v12 == 0;
          if ( v12 <= 0 )
            goto LABEL_22;
          break;
      }
      break;
    }
    while ( 1 )
    {
      v6 += v12;
      if ( (unsigned int)(nptr - 48) > 9 )
      {
        if ( (unsigned int)(nptr - 65) > 0x19 )
        {
          if ( (unsigned int)(nptr - 97) > 0x19 )
            break;
          v14 = nptr - 87;
        }
        else
        {
          v14 = nptr - 55;
        }
      }
      else
      {
        v14 = nptr - 48;
      }
      nptr = v14;
      if ( v14 >= (int)base )
        break;
      if ( v9 > v20 || v9 == v20 && v14 > v18 )
        l = 1;
      else
        v9 = v14 + base * v9;
      v12 = (*(int (__cdecl **)(LIST_ENTRY32 *, signed int *, unsigned int, char *))(cs[12].Blink + 32))(
              a1: cs,
              a2: &nptr,
              a3: v6,
              a4: v8);
      v13 = v12 == 0;
      if ( v12 <= 0 )
      {
LABEL_22:
        if ( v13 )
        {
          if ( a5 != nullptr )
            *a5 = v6;
          *err = 42;
          return 0;
        }
        break;
      }
    }
    if ( a5 != nullptr )
      *a5 = v6;
    if ( (const LoggingContext_t *)v6 == save )
    {
      *err = 33;
      return 0;
    }
    else
    {
      if ( negative )
        v15 = v9 <= 0x80000000;
      else
        v15 = v9 <= 0x7FFFFFFF;
      if ( v15 && l == 0 )
      {
        if ( negative )
          return -v9;
        return v9;
      }
      else
      {
        *err = 34;
        return negative + 0x7FFFFFFF;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004306C0
// Name: my_strntoul_mb2_or_mb4
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_strntoul_mb2_or_mb4(
        LIST_ENTRY32 *cs,
        const char *nptr,
        int l,
        int base,
        const char **a5,
        int *err)
{
  const char *v6; // esi
  const char *v8; // ebx
  unsigned int v9; // ebp
  int v10; // eax
  int v12; // eax
  bool v13; // zf
  const char *v14; // eax
  const char *v15; // [esp-4h] [ebp-20h]
  BOOL negative; // [esp+10h] [ebp-Ch]
  unsigned int v17; // [esp+14h] [ebp-8h]
  const LoggingContext_t *save; // [esp+18h] [ebp-4h]
  unsigned int v19; // [esp+20h] [ebp+4h]

  v6 = nptr;
  v8 = &nptr[l];
  v15 = &nptr[l];
  v9 = 0;
  *err = 0;
  negative = false;
  v10 = (*(int (__cdecl **)(LIST_ENTRY32 *, const char **, const char *, const char *))(cs[12].Blink + 32))(
          a1: cs,
          a2: &nptr,
          a3: v6,
          a4: v15);
  if ( v10 <= 0 )
  {
LABEL_5:
    if ( a5 != nullptr )
      *a5 = v6;
    *err = v10 != 0 ? 33 : 42;
    return 0;
  }
  else
  {
    while ( 2 )
    {
      switch ( (unsigned int)nptr )
      {
        case 9u:
        case 0x20u:
        case 0x2Bu:
          goto $LN25_0;
        case 0x2Du:
          negative = !negative;
$LN25_0:
          v6 += v10;
          v10 = (*(int (__cdecl **)(LIST_ENTRY32 *, const char **, const char *, const char *))(cs[12].Blink + 32))(
                  a1: cs,
                  a2: &nptr,
                  a3: v6,
                  a4: v8);
          if ( v10 <= 0 )
            goto LABEL_5;
          continue;
        default:
          l = 0;
          save = (const LoggingContext_t *)v6;
          v19 = 0xFFFFFFFF / base;
          v17 = 0xFFFFFFFF % base;
          v12 = (*(int (__cdecl **)(LIST_ENTRY32 *, const char **, const char *, const char *))(cs[12].Blink + 32))(
                  a1: cs,
                  a2: &nptr,
                  a3: v6,
                  a4: v8);
          v13 = v12 == 0;
          if ( v12 <= 0 )
            goto LABEL_22;
          break;
      }
      break;
    }
    while ( 1 )
    {
      v6 += v12;
      if ( (unsigned int)(nptr - 48) > 9 )
      {
        if ( (unsigned int)(nptr - 65) > 0x19 )
        {
          if ( (unsigned int)(nptr - 97) > 0x19 )
            break;
          v14 = nptr - 87;
        }
        else
        {
          v14 = nptr - 55;
        }
      }
      else
      {
        v14 = nptr - 48;
      }
      nptr = v14;
      if ( (int)v14 >= base )
        break;
      if ( v9 > v19 || v9 == v19 && (unsigned int)v14 > v17 )
        l = 1;
      else
        v9 = (unsigned int)&v14[base * v9];
      v12 = (*(int (__cdecl **)(LIST_ENTRY32 *, const char **, const char *, const char *))(cs[12].Blink + 32))(
              a1: cs,
              a2: &nptr,
              a3: v6,
              a4: v8);
      v13 = v12 == 0;
      if ( v12 <= 0 )
      {
LABEL_22:
        if ( v13 )
        {
          if ( a5 != nullptr )
            *a5 = v6;
          *err = 42;
          return 0;
        }
        break;
      }
    }
    if ( a5 != nullptr )
      *a5 = v6;
    if ( v6 == (const char *)save )
    {
      *err = 33;
      return 0;
    }
    else if ( l != 0 )
    {
      *err = 34;
      return -1;
    }
    else
    {
      if ( negative )
        return -v9;
      return v9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004308B0
// Name: my_strntoll_mb2_or_mb4
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strntoll_mb2_or_mb4(int a1, unsigned int a2, int a3, signed int a4, unsigned int *a5, _DWORD *a6)
{
  unsigned int v6; // esi
  int v8; // ebx
  unsigned int v9; // ebp
  int (__cdecl *v10)(int, unsigned int *, unsigned int, int); // ecx
  int v11; // eax
  int result; // eax
  int v13; // eax
  bool v14; // zf
  unsigned int v15; // ebx
  int v16; // [esp-4h] [ebp-34h]
  BOOL v17; // [esp+10h] [ebp-20h]
  unsigned int v18; // [esp+14h] [ebp-1Ch]
  int v19; // [esp+18h] [ebp-18h]
  unsigned __int64 v20; // [esp+20h] [ebp-10h]
  unsigned __int64 v21; // [esp+28h] [ebp-8h]
  int v22; // [esp+34h] [ebp+4h]

  v6 = a2;
  v8 = a2 + a3;
  v16 = a2 + a3;
  v9 = 0;
  *a6 = 0;
  v10 = *(int (__cdecl **)(int, unsigned int *, unsigned int, int))(*(_DWORD *)(a1 + 100) + 32);
  v17 = false;
  a3 = v8;
  v11 = v10(a1, &a2, a3: v6, a4: v16);
  if ( v11 <= 0 )
  {
LABEL_5:
    if ( a5 != nullptr )
      *a5 = v6;
    *a6 = v11 != 0 ? 33 : 42;
    return 0;
  }
  while ( 2 )
  {
    switch ( a2 )
    {
      case 9u:
      case 0x20u:
      case 0x2Bu:
        goto LABEL_4;
      case 0x2Du:
        v17 = !v17;
LABEL_4:
        v6 += v11;
        v11 = (*(int (__cdecl **)(int, unsigned int *, unsigned int, int))(*(_DWORD *)(a1 + 100) + 32))(
                a1,
                &a2,
                a3: v6,
                a4: v8);
        if ( v11 <= 0 )
          goto LABEL_5;
        continue;
      default:
        v22 = 0;
        v19 = 0;
        v18 = v6;
        v21 = 0xFFFFFFFFFFFFFFFFuLL % (unsigned int)a4;
        v20 = 0xFFFFFFFFFFFFFFFFuLL / (unsigned int)a4;
        v13 = (*(int (__cdecl **)(int, unsigned int *, unsigned int, int))(*(_DWORD *)(a1 + 100) + 32))(
                a1,
                &a2,
                a3: v6,
                a4: a3);
        v14 = v13 == 0;
        if ( v13 <= 0 )
          goto LABEL_22;
        break;
    }
    break;
  }
  do
  {
    v6 += v13;
    if ( a2 - 48 > 9 )
    {
      if ( a2 - 65 > 0x19 )
      {
        if ( a2 - 97 > 0x19 )
          goto LABEL_26;
        v15 = a2 - 87;
      }
      else
      {
        v15 = a2 - 55;
      }
    }
    else
    {
      v15 = a2 - 48;
    }
    a2 = v15;
    if ( (int)v15 >= a4 )
      goto LABEL_26;
    if ( __PAIR64__(v9, v19) > v20 || __PAIR64__(v9, v19) == v20 && v15 > (unsigned int)v21 )
    {
      v22 = 1;
    }
    else
    {
      v9 = (v15 + a4 * __PAIR64__(v9, v19)) >> 32;
      v19 = v15 + a4 * v19;
    }
    v13 = (*(int (__cdecl **)(int, unsigned int *, unsigned int, int))(*(_DWORD *)(a1 + 100) + 32))(
            a1,
            &a2,
            a3: v6,
            a4: a3);
    v14 = v13 == 0;
  }
  while ( v13 > 0 );
LABEL_22:
  if ( v14 )
  {
    if ( a5 != nullptr )
      *a5 = v6;
    *a6 = 42;
    return 0;
  }
LABEL_26:
  if ( a5 != nullptr )
    *a5 = v6;
  if ( v6 == v18 )
  {
    *a6 = 33;
    return 0;
  }
  if ( v17 )
  {
    if ( v9 > 0x80000000 )
      goto LABEL_38;
    result = v19;
    if ( v9 >= 0x80000000 && v19 != 0 )
      goto LABEL_38;
  }
  else
  {
    if ( v9 > 0x7FFFFFFF )
      goto LABEL_38;
    result = v19;
  }
  if ( v22 != 0 )
  {
LABEL_38:
    *a6 = 34;
    if ( v17 )
      return 0;
    else
      return -1;
  }
  if ( v17 )
    return -result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00430B40
// Name: my_strntoull_mb2_or_mb4
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strntoull_mb2_or_mb4(int a1, unsigned int a2, int a3, signed int a4, unsigned int *a5, _DWORD *a6)
{
  unsigned int v6; // esi
  int v8; // ebx
  unsigned int v9; // ebp
  int (__cdecl *v10)(int, unsigned int *, unsigned int, int); // ecx
  int v11; // eax
  int result; // eax
  int v13; // eax
  bool v14; // zf
  unsigned int v15; // ebx
  int v16; // [esp-4h] [ebp-34h]
  BOOL v17; // [esp+10h] [ebp-20h]
  unsigned int v18; // [esp+14h] [ebp-1Ch]
  int v19; // [esp+18h] [ebp-18h]
  unsigned __int64 v20; // [esp+20h] [ebp-10h]
  unsigned __int64 v21; // [esp+28h] [ebp-8h]
  int v22; // [esp+34h] [ebp+4h]

  v6 = a2;
  v8 = a2 + a3;
  v16 = a2 + a3;
  v9 = 0;
  *a6 = 0;
  v10 = *(int (__cdecl **)(int, unsigned int *, unsigned int, int))(*(_DWORD *)(a1 + 100) + 32);
  v17 = false;
  a3 = v8;
  v11 = v10(a1, &a2, a3: v6, a4: v16);
  if ( v11 <= 0 )
  {
LABEL_5:
    if ( a5 != nullptr )
      *a5 = v6;
    *a6 = v11 != 0 ? 33 : 42;
    return 0;
  }
  else
  {
    while ( 2 )
    {
      switch ( a2 )
      {
        case 9u:
        case 0x20u:
        case 0x2Bu:
          goto LABEL_4;
        case 0x2Du:
          v17 = !v17;
LABEL_4:
          v6 += v11;
          v11 = (*(int (__cdecl **)(int, unsigned int *, unsigned int, int))(*(_DWORD *)(a1 + 100) + 32))(
                  a1,
                  &a2,
                  a3: v6,
                  a4: v8);
          if ( v11 <= 0 )
            goto LABEL_5;
          continue;
        default:
          v22 = 0;
          v19 = 0;
          v18 = v6;
          v21 = 0xFFFFFFFFFFFFFFFFuLL % (unsigned int)a4;
          v20 = 0xFFFFFFFFFFFFFFFFuLL / (unsigned int)a4;
          v13 = (*(int (__cdecl **)(int, unsigned int *, unsigned int, int))(*(_DWORD *)(a1 + 100) + 32))(
                  a1,
                  &a2,
                  a3: v6,
                  a4: a3);
          v14 = v13 == 0;
          if ( v13 <= 0 )
            goto LABEL_22;
          break;
      }
      break;
    }
    while ( 1 )
    {
      v6 += v13;
      if ( a2 - 48 > 9 )
      {
        if ( a2 - 65 > 0x19 )
        {
          if ( a2 - 97 > 0x19 )
            break;
          v15 = a2 - 87;
        }
        else
        {
          v15 = a2 - 55;
        }
      }
      else
      {
        v15 = a2 - 48;
      }
      a2 = v15;
      if ( (int)v15 >= a4 )
        break;
      if ( __PAIR64__(v9, v19) > v20 || __PAIR64__(v9, v19) == v20 && v15 > (unsigned int)v21 )
      {
        v22 = 1;
      }
      else
      {
        v9 = (v15 + a4 * __PAIR64__(v9, v19)) >> 32;
        v19 = v15 + a4 * v19;
      }
      v13 = (*(int (__cdecl **)(int, unsigned int *, unsigned int, int))(*(_DWORD *)(a1 + 100) + 32))(
              a1,
              &a2,
              a3: v6,
              a4: a3);
      v14 = v13 == 0;
      if ( v13 <= 0 )
      {
LABEL_22:
        if ( v14 )
        {
          if ( a5 != nullptr )
            *a5 = v6;
          *a6 = 42;
          return 0;
        }
        break;
      }
    }
    if ( a5 != nullptr )
      *a5 = v6;
    if ( v6 == v18 )
    {
      *a6 = 33;
      return 0;
    }
    else if ( v22 != 0 )
    {
      *a6 = 34;
      return -1;
    }
    else
    {
      result = v19;
      if ( v17 )
        return -v19;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00430D90
// Name: my_strntod_mb2_or_mb4
// Source: json
//------------------------------------------------------------------------------
void __cdecl my_strntod_mb2_or_mb4(
        LIST_ENTRY32 *cs,
        char *nptr,
        const wchar_t *length,
        int (__stdcall ***a4)(_EXCEPTION_POINTERS *),
        int *err)
{
  int v5; // eax
  unsigned int v6; // ebx
  int (__stdcall **v7)(_EXCEPTION_POINTERS *); // edi
  char *v8; // ebp
  int i; // eax
  unsigned int Blink; // edx
  int (__stdcall ***v11)(_EXCEPTION_POINTERS *); // ebx
  unsigned int *v12; // [esp-8h] [ebp-12Ch]
  int *v13; // [esp-4h] [ebp-128h]
  unsigned int wc; // [esp+10h] [ebp-114h] BYREF
  int *v15; // [esp+14h] [ebp-110h]
  unsigned int v16; // [esp+18h] [ebp-10Ch]
  int (__stdcall ***v17)(_EXCEPTION_POINTERS *); // [esp+1Ch] [ebp-108h]
  int (__stdcall *buf[64])(_EXCEPTION_POINTERS *); // [esp+20h] [ebp-104h] BYREF

  v5 = (int)length;
  v6 = (unsigned int)nptr;
  v17 = a4;
  v16 = (unsigned int)nptr;
  v15 = err;
  v7 = buf;
  *err = 0;
  if ( (unsigned int)length >= 0x100 )
    v5 = 255;
  v8 = &nptr[v5];
  for ( i = (*(int (__cdecl **)(LIST_ENTRY32 *, unsigned int *, char *, char *))(cs[12].Blink + 32))(
              a1: cs,
              a2: &wc,
              a3: nptr,
              a4: &nptr[v5]);
        i > 0;
        i = (*(int (__cdecl **)(LIST_ENTRY32 *, unsigned int *, unsigned int, char *))(Blink + 32))(
              a1: cs,
              a2: &wc,
              a3: v6,
              a4: v8) )
  {
    v6 += i;
    if ( wc > 0x65 )
      break;
    if ( wc == 0 )
      break;
    Blink = cs[12].Blink;
    *(_BYTE *)v7 = wc;
    v7 = (int (__stdcall **)(_EXCEPTION_POINTERS *))((char *)v7 + 1);
  }
  v11 = v17;
  v13 = v15;
  v12 = (unsigned int *)v17;
  *v17 = v7;
  my_strtod(a1: (tagShutdownType)buf, a2: v12, a3: v13);
  *v11 = (int (__stdcall **)(_EXCEPTION_POINTERS *))(v16 + cs[10].Blink * ((char *)*v11 - (char *)buf));
}

//------------------------------------------------------------------------------
// Address: 0x00430E80
// Name: my_strntoull10rnd_mb2_or_mb4
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strntoull10rnd_mb2_or_mb4(int a1, int a2, unsigned int a3, int a4, _DWORD *a5, _DWORD *a6)
{
  int v6; // ebx
  int v7; // ebp
  _BYTE *v8; // edi
  int v9; // ebp
  int i; // eax
  int v11; // edx
  _DWORD *v12; // ebx
  int result; // eax
  unsigned int v14; // [esp+10h] [ebp-114h] BYREF
  _DWORD *v15; // [esp+14h] [ebp-110h]
  int v16; // [esp+18h] [ebp-10Ch]
  _DWORD *v17; // [esp+1Ch] [ebp-108h]
  _BYTE v18[256]; // [esp+20h] [ebp-104h] BYREF

  v6 = a2;
  v7 = a3;
  v16 = a2;
  v15 = a5;
  v17 = a6;
  v8 = v18;
  if ( a3 >= 0x100 )
    v7 = 255;
  v9 = a2 + v7;
  for ( i = (*(int (__cdecl **)(int, unsigned int *, int, int))(*(_DWORD *)(a1 + 100) + 32))(
              a1,
              a2: &v14,
              a3: a2,
              a4: v9); i > 0; i = (*(int (__cdecl **)(int, unsigned int *, int, int))(v11 + 32))(
                                a1,
                                a2: &v14,
                                a3: v6,
                                a4: v9) )
  {
    v6 += i;
    if ( v14 > 0x65 )
      break;
    if ( v14 == 0 )
      break;
    v11 = *(_DWORD *)(a1 + 100);
    *v8++ = v14;
  }
  v12 = v15;
  result = my_strntoull10rnd_8bit(a1, a2: v18, a3: v8 - v18, a4, a5: v15, a6: v17);
  *v12 = v16 + *(_DWORD *)(a1 + 84) * (*v12 - (_DWORD)v18);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00430F70
// Name: my_l10tostr_mb2_or_mb4
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_l10tostr_mb2_or_mb4(int a1, unsigned int a2, int a3, int a4, int a5)
{
  unsigned int v5; // ecx
  unsigned int v6; // edi
  signed int v7; // edx
  _BYTE *v8; // esi
  char i; // cl
  unsigned int v10; // ebx
  int v11; // eax
  int v13; // [esp+10h] [ebp-50h]
  _BYTE v14[4]; // [esp+58h] [ebp-8h] BYREF

  v5 = a5;
  v6 = a2;
  v13 = 0;
  v14[1] = 0;
  if ( a4 < 0 && a5 < 0 )
  {
    v13 = 1;
    v5 = -a5;
  }
  v7 = v5 / 0xA;
  v14[0] = v5 % 0xA + 48;
  v8 = v14;
  for ( i = v5 / 0xA; v7 != 0; i = v7 )
  {
    v7 /= 10;
    *--v8 = i - 10 * v7 + 48;
  }
  if ( v13 != 0 )
    *--v8 = 45;
  v10 = a3 + a2;
  if ( a2 < a3 + a2 )
  {
    do
    {
      if ( *v8 == 0 )
        break;
      v11 = (*(int (__cdecl **)(int, _DWORD, unsigned int, unsigned int))(*(_DWORD *)(a1 + 100) + 36))(
              a1,
              a2: (char)*v8,
              a3: v6,
              a4: v10);
      if ( v11 <= 0 )
        break;
      v6 += v11;
      ++v8;
    }
    while ( v6 < v10 );
  }
  return v6 - a2;
}

//------------------------------------------------------------------------------
// Address: 0x00431060
// Name: my_ll10tostr_mb2_or_mb4
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_ll10tostr_mb2_or_mb4(
        LIST_ENTRY32 *cs,
        char *dst,
        unsigned int len,
        const char *radix,
        int val,
        char *buffer)
{
  int v6; // ebx
  char *v7; // ebp
  unsigned int v8; // eax
  char *v9; // esi
  unsigned __int64 v10; // kr00_8
  char *v11; // edi
  int v12; // eax
  int sl; // [esp+10h] [ebp-54h]
  char v15; // [esp+5Bh] [ebp-9h] BYREF
  char v16; // [esp+5Ch] [ebp-8h] BYREF

  v6 = val;
  v7 = dst;
  v8 = (unsigned int)buffer;
  sl = 0;
  if ( (int)radix < 0 && (int)buffer < 0 )
  {
    v6 = -val;
    sl = 1;
    v8 = (unsigned __int64)-__SPAIR64__((unsigned int)buffer, val) >> 32;
  }
  v9 = &v16;
  v16 = 0;
  if ( (v8 | v6) != 0 )
  {
    if ( v8 != 0 || (unsigned int)v6 > 0x7FFFFFFF )
    {
      do
      {
        v10 = __PAIR64__(v8, v6) / 0xA;
        *--v9 = __PAIR64__(v8, v6) % 0xA + 48;
        v6 = __PAIR64__(v8, v6) / 0xA;
        v8 = HIDWORD(v10);
      }
      while ( v10 > 0x7FFFFFFF );
    }
    for ( ; v6 != 0; v6 /= 10 )
      *--v9 = v6 % 10 + 48;
  }
  else
  {
    v9 = &v15;
    v15 = 48;
  }
  if ( sl != 0 )
    *--v9 = 45;
  v11 = &dst[len];
  if ( dst < &dst[len] )
  {
    do
    {
      if ( *v9 == 0 )
        break;
      v12 = (*(int (__cdecl **)(LIST_ENTRY32 *, _DWORD, char *, char *))(cs[12].Blink + 36))(
              a1: cs,
              a2: *v9,
              a3: v7,
              a4: v11);
      if ( v12 <= 0 )
        break;
      v7 += v12;
      ++v9;
    }
    while ( v7 < v11 );
  }
  return v7 - dst;
}

//------------------------------------------------------------------------------
// Address: 0x00431190
// Name: my_strtoll10_mb2
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_strtoll10_mb2(LIST_ENTRY32 *cs, unsigned int negative, _DWORD *a3, int *error)
{
  _BYTE *v5; // esi
  unsigned int v6; // ebx
  char v7; // al
  char v8; // al
  unsigned __int64 v9; // rax
  _BYTE *v10; // ecx
  unsigned __int8 v11; // al
  _BYTE *v12; // ebp
  unsigned int v13; // ecx
  _BYTE *v14; // edi
  unsigned __int8 v15; // al
  unsigned __int8 v16; // al
  _BYTE *v17; // esi
  unsigned int v18; // edi
  unsigned __int8 v19; // al
  _BYTE *v20; // esi
  unsigned int v21; // edi
  unsigned int cutoff; // [esp+Ch] [ebp-10h]
  unsigned int cutoff2; // [esp+10h] [ebp-Ch]
  unsigned int cutoff3; // [esp+14h] [ebp-8h]
  tagShutdownType start; // [esp+18h] [ebp-4h]
  int negativea; // [esp+24h] [ebp+8h]

  v5 = (_BYTE *)negative;
  if ( a3 == nullptr )
    goto no_conv;
  v6 = negative + 2 * ((int)(*a3 - negative) / 2);
  if ( negative < v6 )
  {
    do
    {
      if ( *v5 != 0 )
        break;
      v7 = v5[1];
      if ( v7 != 32 && v7 != 9 )
        break;
      v5 += 2;
    }
    while ( (unsigned int)v5 < v6 );
  }
  if ( v5 == (_BYTE *)v6 )
    goto no_conv;
  negativea = 0;
  if ( *v5 != 0 || v5[1] != 45 )
  {
    *error = 0;
    if ( *v5 == 0 && v5[1] == 43 )
    {
      v5 += 2;
      if ( v5 == (_BYTE *)v6 )
        goto no_conv;
    }
    cutoff = 184467440;
    cutoff2 = 737095516;
    cutoff3 = 15;
  }
  else
  {
    v5 += 2;
    *error = -1;
    negativea = 1;
    if ( v5 == (_BYTE *)v6 )
      goto no_conv;
    cutoff = 92233720;
    cutoff2 = 368547758;
    cutoff3 = 8;
  }
  if ( *v5 != 0 )
    goto no_conv;
  v8 = v5[1];
  if ( v8 != 48 )
  {
    v11 = v8 - 48;
    if ( v11 <= 9u )
    {
      v5 += 2;
      HIDWORD(v9) = v11;
      v10 = v5 + 16;
      goto LABEL_25;
    }
no_conv:
    *error = 33;
    *a3 = negative;
    LODWORD(v9) = 0;
    return v9;
  }
  HIDWORD(v9) = 0;
  do
  {
    v5 += 2;
    if ( v5 == (_BYTE *)v6 )
      goto end_i;
  }
  while ( *v5 == 0 && v5[1] == 48 );
  v10 = v5 + 18;
LABEL_25:
  if ( (unsigned int)v10 > v6 )
    v10 = (_BYTE *)v6;
  if ( v5 != v10 )
  {
    while ( *v5 == 0 )
    {
      LOBYTE(v9) = v5[1] - 48;
      if ( (unsigned __int8)v9 > 9u )
        break;
      v5 += 2;
      HIDWORD(v9) = (unsigned __int8)v9 + 10 * HIDWORD(v9);
      if ( v5 == v10 )
        goto LABEL_31;
    }
    goto end_i;
  }
LABEL_31:
  if ( v5 == (_BYTE *)v6 )
  {
end_i:
    *a3 = v5;
    LODWORD(v9) = HIDWORD(v9);
    if ( negativea != 0 )
      LODWORD(v9) = -HIDWORD(v9);
    return v9;
  }
  v12 = v5 + 18;
  v13 = 0;
  start = (tagShutdownType)v5;
  v14 = v5 + 18;
  if ( (unsigned int)(v5 + 18) > v6 )
    v14 = (_BYTE *)v6;
  do
  {
    if ( *v5 != 0 )
      goto end_i_and_j;
    v15 = v5[1] - 48;
    if ( v15 > 9u )
      goto end_i_and_j;
    v5 += 2;
    v13 = v15 + 10 * v13;
  }
  while ( v5 != v14 );
  if ( v5 == (_BYTE *)v6 )
  {
    if ( v5 != v12 )
    {
end_i_and_j:
      LODWORD(v9) = lfactor_0[(unsigned int)&v5[-start] >> 1];
LABEL_63:
      v9 = v13 + HIDWORD(v9) * (unsigned __int64)(unsigned int)v9;
      *a3 = v5;
      if ( negativea != 0 )
        return -(__int64)v9;
      return v9;
    }
end3:
    v9 = HIDWORD(v9) | 0x3B9ACA0000000000LL;
    goto LABEL_63;
  }
  if ( *v5 != 0 )
    goto end3;
  v16 = v5[1] - 48;
  if ( v16 > 9u )
    goto end3;
  v17 = v5 + 2;
  v18 = v16;
  if ( v17 == (_BYTE *)v6 || *v17 != 0 || (v19 = v17[1] - 48) > 9u )
  {
    v9 = v18 + 10 * (v13 + 1000000000LL * HIDWORD(v9));
    *a3 = v17;
    if ( negativea == 0 )
      return v9;
    if ( v9 <= 0x8000000000000000uLL )
      return -(__int64)v9;
  }
  else
  {
    v20 = v17 + 2;
    v21 = v19 + 10 * v18;
    *a3 = v20;
    if ( (v20 == (_BYTE *)v6 || *v20 != 0 || (unsigned __int8)(v20[1] - 48) > 9u)
      && HIDWORD(v9) <= cutoff
      && (HIDWORD(v9) != cutoff || v13 < cutoff2 || v21 <= cutoff3) )
    {
      LODWORD(v9) = v21 + 100 * (v13 + 1000000000 * HIDWORD(v9));
      return v9;
    }
  }
  *error = 34;
  if ( negativea != 0 )
    LODWORD(v9) = 0;
  else
    LODWORD(v9) = -1;
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x00431480
// Name: my_scan_mb2
// Source: json
//------------------------------------------------------------------------------
_BYTE *__cdecl my_scan_mb2(int a1, _BYTE *a2, int a3, int a4)
{
  _BYTE *v4; // eax
  unsigned int v5; // edx

  v4 = a2;
  v5 = a3 - 1;
  if ( a4 != 2 )
    return nullptr;
  if ( (unsigned int)a2 < v5 )
  {
    do
    {
      if ( *v4 != 0 )
        break;
      if ( v4[1] != 32 )
        break;
      v4 += 2;
    }
    while ( (unsigned int)v4 < v5 );
  }
  return (_BYTE *)(v4 - a2);
}

//------------------------------------------------------------------------------
// Address: 0x004314C0
// Name: my_fill_mb2
// Source: json
//------------------------------------------------------------------------------
void __cdecl my_fill_mb2(int a1, _BYTE *a2, unsigned int a3, char a4)
{
  unsigned int v5; // ecx

  if ( a3 >= 2 )
  {
    v5 = a3 >> 1;
    do
    {
      *a2 = 0;
      a2[1] = a4;
      a2 += 2;
      --v5;
    }
    while ( v5 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004314F0
// Name: my_vsnprintf_mb2
// Source: json
//------------------------------------------------------------------------------
_BYTE *__fastcall my_vsnprintf_mb2(int a1, _BYTE *a2, int a3, char *a4)
{
  char *v4; // ebp
  _BYTE *v5; // esi
  int v6; // edx
  char v7; // al
  int v8; // ebx
  char *v9; // esi
  char v10; // al
  char v11; // al
  const char *v12; // ecx
  unsigned int v13; // edx
  int v14; // eax
  _BYTE *v16; // esi
  char *v17; // edi
  int v18; // ecx
  char v19; // al
  char *v20; // esi
  int v21; // [esp+8h] [ebp-20h]
  int v22; // [esp+Ch] [ebp-1Ch]
  _BYTE *v23; // [esp+10h] [ebp-18h]
  char v24[16]; // [esp+14h] [ebp-14h] BYREF

  v4 = a4;
  v5 = a2;
  v6 = (int)&a2[a3 - 1];
  v7 = *a4;
  v23 = v5;
  v22 = v6;
  if ( *a4 != 0 )
  {
    v8 = a1 - 4;
    while ( 1 )
    {
      if ( v7 == 37 )
      {
        do
        {
          do
            v10 = *++v4;
          while ( v10 >= 48 && v10 <= 57 );
        }
        while ( v10 == 46 || v10 == 45 );
        if ( *v4 == 108 )
          ++v4;
        v11 = *v4;
        if ( *v4 == 115 )
        {
          v12 = *(const char **)(v8 + 4);
          v13 = v6 - (_DWORD)v5;
          v21 = v8 + 4;
          if ( v12 == nullptr )
            v12 = "(null)";
          v14 = strlen(v12);
          if ( v13 <= 2 * v14 )
            v14 = (v13 >> 1) - 1;
          for ( ; v14 != 0; ++v12 )
          {
            *v5 = 0;
            v5[1] = *v12;
            --v14;
            v5 += 2;
          }
          v8 = v21;
        }
        else if ( v11 == 100 || v11 == 117 )
        {
          v17 = v24;
          if ( (unsigned int)(v22 - (_DWORD)v5) < 0x20 )
            break;
          v18 = *(_DWORD *)(v8 + 4);
          v8 += 4;
          if ( v11 == 100 )
            int10_to_str(result: v18, dst: v24, radix: -10);
          else
            int10_to_str(result: v18, dst: v24, radix: 10);
          v19 = v24[0];
          if ( v24[0] != 0 )
          {
            do
            {
              *v5 = 0;
              v20 = v5 + 1;
              ++v17;
              *v20 = v19;
              v19 = *v17;
              v5 = v20 + 1;
            }
            while ( *v17 != 0 );
          }
        }
        else
        {
          if ( v5 == (_BYTE *)v6 )
            break;
          *v5 = 0;
          v16 = v5 + 1;
          *v16 = 37;
          v5 = v16 + 1;
        }
      }
      else
      {
        if ( v5 == (_BYTE *)v6 )
          break;
        *v5 = 0;
        v9 = v5 + 1;
        *v9 = *v4;
        v5 = v9 + 1;
      }
      v7 = *++v4;
      if ( v7 == 0 )
        break;
      v6 = v22;
    }
  }
  *v5 = 0;
  return (_BYTE *)(v5 - v23);
}

//------------------------------------------------------------------------------
// Address: 0x00431650
// Name: my_snprintf_mb2
// Source: json
//------------------------------------------------------------------------------
_BYTE *my_snprintf_mb2(LIST_ENTRY32 *a1, char *to, unsigned int n, char *fmt, ...)
{
  va_list va; // [esp+14h] [ebp+14h] BYREF

  va_start(va, fmt);
  return my_vsnprintf_mb2(a1: (int)va, a2: to, a3: n, a4: fmt);
}

//------------------------------------------------------------------------------
// Address: 0x00431670
// Name: my_lengthsp_mb2
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_lengthsp_mb2(int a1, int a2, int a3)
{
  unsigned int i; // eax

  for ( i = a2 + a3; i > a2 + 1; i -= 2 )
  {
    if ( *(_BYTE *)(i - 1) != 32 )
      break;
    if ( *(_BYTE *)(i - 2) != 0 )
      break;
  }
  return i - a2;
}

//------------------------------------------------------------------------------
// Address: 0x004316A0
// Name: my_utf16_uni
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_utf16_uni(int a1, _DWORD *a2, unsigned __int8 *a3, unsigned int a4)
{
  unsigned __int8 v5; // dl
  char v6; // cl
  unsigned __int8 v7; // cl

  if ( (unsigned int)(a3 + 2) > a4 )
    return -102;
  v5 = *a3;
  v6 = *a3 & 0xFC;
  if ( v6 == -40 )
  {
    if ( (unsigned int)(a3 + 4) > a4 )
      return -104;
    v7 = a3[2];
    if ( (v7 & 0xFC) != 0xDC )
      return 0;
    *a2 = a3[3] + (((v7 & 3) + 4 * (a3[1] + ((v5 & 3) << 8)) + 256) << 8);
    return 4;
  }
  else
  {
    if ( v6 == -36 )
      return 0;
    *a2 = a3[1] + (v5 << 8);
    return 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00431740
// Name: my_uni_utf16
// Source: json
//------------------------------------------------------------------------------
int my_uni_utf16(LIST_ENTRY32 *cs, const char *wc, unsigned __int8 *s, unsigned __int8 *e, ...)
{
  if ( (unsigned int)wc <= 0xFFFF )
  {
    if ( s + 2 > e )
      return -102;
    if ( ((unsigned __int16)wc & 0xF800) != 0xD800 )
    {
      *s = BYTE1(wc);
      s[1] = (unsigned __int8)wc;
      return 2;
    }
  }
  else if ( (unsigned int)wc <= 0x10FFFF )
  {
    if ( s + 4 > e )
      return -104;
    *s = ((unsigned int)(wc - 0x10000) >> 18) | 0xD8;
    s[1] = (unsigned int)(wc - 0x10000) >> 10;
    s[2] = BYTE1(wc) & 3 | 0xDC;
    s[3] = (unsigned __int8)wc;
    return 4;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004317D0
// Name: my_caseup_utf16
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_caseup_utf16(LIST_ENTRY32 *cs, unsigned int src, unsigned int srclen)
{
  unsigned int result; // eax
  unsigned __int8 *v5; // esi
  unsigned __int8 *v6; // ebx
  int v7; // edi
  unsigned int v8; // eax
  int v9; // ecx
  int (__stdcall *uni_plane)(); // [esp+10h] [ebp+4h]

  result = srclen;
  v5 = (unsigned __int8 *)src;
  v6 = (unsigned __int8 *)(src + srclen);
  uni_plane = (int (__stdcall *)())cs[8].Flink;
  if ( src < src + srclen )
  {
    do
    {
      v7 = my_utf16_uni(a1: (int)cs, a2: &src, a3: v5, a4: (unsigned int)v6);
      if ( v7 <= 0 )
        break;
      v8 = src;
      if ( src >> 8 < 0x100 )
      {
        v9 = *((_DWORD *)uni_plane + (src >> 8));
        if ( v9 != 0 )
        {
          v8 = *(unsigned __int16 *)(v9 + 6 * (unsigned __int8)src);
          src = v8;
        }
      }
      if ( v7 != my_uni_utf16(cs, wc: (const char *)v8, s: v5, e: v6) )
        break;
      v5 += v7;
    }
    while ( v5 < v6 );
    return srclen;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00431860
// Name: my_hash_sort_utf16
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl my_hash_sort_utf16(
        LIST_ENTRY32 *a1,
        const LoggingContext_t *s,
        unsigned int wc,
        unsigned int *n1,
        unsigned int *n2)
{
  unsigned __int8 *result; // eax
  unsigned int v6; // ebx
  unsigned int *v7; // esi
  unsigned int *v8; // edi
  unsigned int v9; // ecx
  int v10; // eax
  int (__stdcall *uni_plane)(); // [esp+4h] [ebp-8h]
  int res; // [esp+8h] [ebp-4h]

  result = (unsigned __int8 *)s;
  v6 = (unsigned int)s + wc;
  for ( uni_plane = (int (__stdcall *)())a1[8].Flink; v6 > (unsigned int)&s->m_ChannelID + 1; v6 -= 2 )
  {
    if ( *(_BYTE *)(v6 - 1) != 32 )
      break;
    if ( *(_BYTE *)(v6 - 2) != 0 )
      break;
  }
  if ( (unsigned int)s < v6 )
  {
    v7 = n2;
    v8 = n1;
    while ( 1 )
    {
      result = (unsigned __int8 *)my_utf16_uni((int)a1, a2: &wc, a3: result, a4: v6);
      res = (int)result;
      if ( (int)result <= 0 )
        return result;
      v9 = wc;
      if ( wc >> 8 >= 0x100 )
        break;
      v10 = *((_DWORD *)uni_plane + (wc >> 8));
      if ( v10 != 0 )
      {
        v9 = *(unsigned __int16 *)(v10 + 6 * (unsigned __int8)wc + 4);
LABEL_12:
        wc = v9;
      }
      *v8 ^= (*v8 << 8) + (unsigned __int8)v9 * (*v7 + (*v8 & 0x3F));
      *v7 += 3;
      result = (unsigned __int8 *)s + res;
      *v8 ^= (*v8 << 8) + (v9 >> 8) * (*v7 + (*v8 & 0x3F));
      *v7 += 3;
      s = (const LoggingContext_t *)result;
      if ( (unsigned int)result >= v6 )
        return result;
    }
    v9 = 65533;
    goto LABEL_12;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00431960
// Name: my_casedn_utf16
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_casedn_utf16(LIST_ENTRY32 *cs, unsigned int src, unsigned int srclen)
{
  unsigned int result; // eax
  unsigned __int8 *v5; // esi
  unsigned __int8 *v6; // ebx
  int v7; // edi
  unsigned int v8; // eax
  int v9; // ecx
  int (__stdcall *uni_plane)(); // [esp+10h] [ebp+4h]

  result = srclen;
  v5 = (unsigned __int8 *)src;
  v6 = (unsigned __int8 *)(src + srclen);
  uni_plane = (int (__stdcall *)())cs[8].Flink;
  if ( src < src + srclen )
  {
    do
    {
      v7 = my_utf16_uni(a1: (int)cs, a2: &src, a3: v5, a4: (unsigned int)v6);
      if ( v7 <= 0 )
        break;
      v8 = src;
      if ( src >> 8 < 0x100 )
      {
        v9 = *((_DWORD *)uni_plane + (src >> 8));
        if ( v9 != 0 )
        {
          v8 = *(unsigned __int16 *)(v9 + 6 * (unsigned __int8)src + 2);
          src = v8;
        }
      }
      if ( v7 != my_uni_utf16(cs, wc: (const char *)v8, s: v5, e: v6) )
        break;
      v5 += v7;
    }
    while ( v5 < v6 );
    return srclen;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004319F0
// Name: my_strnncoll_utf16
// Source: json
//------------------------------------------------------------------------------
DName *__cdecl my_strnncoll_utf16(
        LIST_ENTRY32 *cs,
        unsigned int s_wc,
        unsigned int t_wc,
        int (__stdcall *uni_plane)(),
        const LoggingContext_t *te,
        char t_is_prefix)
{
  unsigned __int8 *v6; // ebx
  unsigned __int8 *v7; // edi
  const LoggingContext_t *v8; // esi
  int (__stdcall *Flink)(); // eax
  const LoggingContext_t *v10; // ebp
  int v11; // eax
  unsigned int v12; // eax
  int v13; // edx
  unsigned int v14; // ecx
  int v15; // edx
  int s_res; // [esp+10h] [ebp-8h]
  int t_res; // [esp+14h] [ebp-4h]

  v6 = (unsigned __int8 *)uni_plane;
  v7 = (unsigned __int8 *)s_wc;
  v8 = (const LoggingContext_t *)(s_wc + t_wc);
  Flink = (int (__stdcall *)())cs[8].Flink;
  v10 = (const LoggingContext_t *)((char *)te + (_DWORD)uni_plane);
  te = (const LoggingContext_t *)((char *)te + (_DWORD)uni_plane);
  uni_plane = Flink;
  if ( s_wc < s_wc + t_wc )
  {
    do
    {
      if ( v6 >= (unsigned __int8 *)v10 )
        break;
      s_res = my_utf16_uni(a1: (int)cs, a2: &s_wc, a3: v7, a4: (unsigned int)v8);
      v11 = my_utf16_uni(a1: (int)cs, a2: &t_wc, a3: v6, a4: (unsigned int)v10);
      t_res = v11;
      if ( s_res <= 0 || v11 <= 0 )
        return bincmp(s: (char *)v7, a2: (int)v10, a3: v6, se: v8);
      v12 = s_wc;
      if ( s_wc >> 8 >= 0x100 )
      {
        v12 = 65533;
      }
      else
      {
        v13 = *((_DWORD *)uni_plane + (s_wc >> 8));
        if ( v13 == 0 )
          goto LABEL_10;
        v12 = *(unsigned __int16 *)(v13 + 6 * (unsigned __int8)s_wc + 4);
      }
      s_wc = v12;
LABEL_10:
      v14 = t_wc;
      if ( t_wc >> 8 >= 0x100 )
      {
        v14 = 65533;
      }
      else
      {
        v15 = *((_DWORD *)uni_plane + (t_wc >> 8));
        v10 = te;
        if ( v15 == 0 )
          goto LABEL_15;
        v14 = *(unsigned __int16 *)(v15 + 6 * (unsigned __int8)t_wc + 4);
      }
      t_wc = v14;
LABEL_15:
      if ( v14 != v12 )
        return (DName *)(v14 < v12 ? 1 : -1);
      v7 += s_res;
      v6 += t_res;
    }
    while ( v7 < (unsigned __int8 *)v8 );
  }
  if ( t_is_prefix != 0 )
    return (DName *)(v6 - (unsigned __int8 *)v10);
  else
    return (DName *)&v6[(char *)v8 - (char *)v10 - (_DWORD)v7];
}

//------------------------------------------------------------------------------
// Address: 0x00431B40
// Name: my_strnncollsp_utf16
// Source: json
//------------------------------------------------------------------------------
DName *__cdecl my_strnncollsp_utf16(
        LIST_ENTRY32 *cs,
        unsigned int s_wc,
        int swap,
        int (__stdcall *uni_plane)(),
        const LoggingContext_t *te)
{
  unsigned __int8 *v5; // ebx
  unsigned __int8 *v6; // esi
  const LoggingContext_t *v7; // edi
  int (__stdcall *Flink)(); // eax
  const LoggingContext_t *v9; // ebp
  int v10; // eax
  unsigned int v11; // eax
  int v12; // edx
  unsigned int v13; // ecx
  int v14; // edx
  int v15; // eax
  DName *result; // eax
  int s_res; // [esp+10h] [ebp-8h]
  int t_res; // [esp+14h] [ebp-4h]

  v5 = (unsigned __int8 *)uni_plane;
  v6 = (unsigned __int8 *)s_wc;
  v7 = (const LoggingContext_t *)(s_wc + swap);
  Flink = (int (__stdcall *)())cs[8].Flink;
  v9 = (const LoggingContext_t *)((char *)te + (_DWORD)uni_plane);
  te = (const LoggingContext_t *)((char *)te + (_DWORD)uni_plane);
  uni_plane = Flink;
  if ( s_wc < s_wc + swap )
  {
    do
    {
      if ( v5 >= (unsigned __int8 *)v9 )
        break;
      s_res = my_utf16_uni(a1: (int)cs, a2: &s_wc, a3: v6, a4: (unsigned int)v7);
      v10 = my_utf16_uni(a1: (int)cs, a2: &swap, a3: v5, a4: (unsigned int)v9);
      t_res = v10;
      if ( s_res <= 0 || v10 <= 0 )
        return bincmp(s: (char *)v6, a2: (int)v9, a3: v5, se: v7);
      v11 = s_wc;
      if ( s_wc >> 8 >= 0x100 )
      {
        v11 = 65533;
      }
      else
      {
        v12 = *((_DWORD *)uni_plane + (s_wc >> 8));
        if ( v12 == 0 )
          goto LABEL_10;
        v11 = *(unsigned __int16 *)(v12 + 6 * (unsigned __int8)s_wc + 4);
      }
      s_wc = v11;
LABEL_10:
      v13 = swap;
      if ( (unsigned int)swap >> 8 >= 0x100 )
      {
        v13 = 65533;
      }
      else
      {
        v14 = *((_DWORD *)uni_plane + ((unsigned int)swap >> 8));
        v9 = te;
        if ( v14 == 0 )
          goto LABEL_15;
        v13 = *(unsigned __int16 *)(v14 + 6 * (unsigned __int8)swap + 4);
      }
      swap = v13;
LABEL_15:
      if ( v13 != v11 )
        return (DName *)(v13 < v11 ? 1 : -1);
      v6 += s_res;
      v5 += t_res;
    }
    while ( v6 < (unsigned __int8 *)v7 );
  }
  if ( (char *)v7 - (char *)v6 != (char *)v9 - (char *)v5 )
  {
    swap = 1;
    if ( (char *)v7 - (char *)v6 < (unsigned int)((char *)v9 - (char *)v5) )
    {
      v6 = v5;
      v7 = v9;
      swap = -1;
    }
    for ( ; v6 < (unsigned __int8 *)v7; v6 += v15 )
    {
      v15 = my_utf16_uni(a1: (int)cs, a2: &s_wc, a3: v6, a4: (unsigned int)v7);
      if ( v15 < 0 )
        break;
      if ( s_wc != 32 )
      {
        result = (DName *)swap;
        if ( s_wc < 0x20 )
          return (DName *)-swap;
        return result;
      }
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00431CD0
// Name: my_ismbchar_utf16
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_ismbchar_utf16(int a1, _BYTE *a2, unsigned int a3)
{
  char v4; // al

  if ( (unsigned int)(a2 + 2) > a3 )
    return 0;
  v4 = *a2 & 0xFC;
  if ( v4 != -40 )
    return v4 == -36 ? 0 : 2;
  if ( (unsigned int)(a2 + 4) > a3 || (a2[2] & 0xFC) != 0xDC )
    return 0;
  return 4;
}

//------------------------------------------------------------------------------
// Address: 0x00431D20
// Name: my_mbcharlen_utf16
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_mbcharlen_utf16(LIST_ENTRY32 *cs, char c)
{
  return 2 * ((c & 0xFC) == 0xD8) + 2;
}

//------------------------------------------------------------------------------
// Address: 0x00431D40
// Name: my_numchars_utf16
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_numchars_utf16(int a1, _BYTE *a2, unsigned int a3)
{
  _BYTE *v3; // esi
  int v4; // edi
  int i; // eax

  v3 = a2;
  v4 = 0;
  for ( i = my_ismbchar_utf16(a1, a2, a3); i != 0; i = my_ismbchar_utf16(a1, a2: v3, a3) )
  {
    v3 += i;
    ++v4;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00431D80
// Name: my_charpos_utf16
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_charpos_utf16(int a1, int a2, int a3, int a4)
{
  int v4; // ebp
  int v5; // esi
  int v6; // eax

  v4 = a4;
  v5 = a2;
  if ( a4 == 0 )
    return v5 - a2;
  while ( 1 )
  {
    v6 = (*(int (__cdecl **)(int, int, int))(*(_DWORD *)(a1 + 100) + 4))(a1, a2: v5, a3);
    if ( v6 == 0 )
      break;
    v5 += v6;
    if ( --v4 == 0 )
      return v5 - a2;
  }
  return a3 - a2 + 2;
}

//------------------------------------------------------------------------------
// Address: 0x00431DE0
// Name: my_well_formed_len_utf16
// Source: json
//------------------------------------------------------------------------------
int my_well_formed_len_utf16(LIST_ENTRY32 *cs, const char *b, tagShutdownType e, unsigned int nchars, int *error, ...)
{
  unsigned int v5; // ebp
  const char *v6; // esi
  int v7; // eax

  v5 = nchars;
  v6 = b;
  *error = 0;
  if ( nchars != 0 )
  {
    while ( 1 )
    {
      v7 = (*(int (__cdecl **)(LIST_ENTRY32 *, const char *, tagShutdownType))(cs[12].Blink + 4))(a1: cs, a2: v6, a3: e);
      if ( v7 == 0 )
        break;
      v6 += v7;
      if ( --v5 == 0 )
        return v6 - b;
    }
    *error = (unsigned int)v6 < e;
  }
  return v6 - b;
}

//------------------------------------------------------------------------------
// Address: 0x00431E90
// Name: my_strnncoll_utf16_bin
// Source: json
//------------------------------------------------------------------------------
DName *__cdecl my_strnncoll_utf16_bin(
        LIST_ENTRY32 *cs,
        const LoggingContext_t *te,
        unsigned int s_wc,
        unsigned int t_wc,
        unsigned int tlen,
        char t_is_prefix)
{
  unsigned __int8 *v6; // ebx
  unsigned __int8 *v7; // edi
  const LoggingContext_t *v8; // esi
  unsigned int v9; // eax
  int v10; // ebp
  int v11; // eax
  const LoggingContext_t *tea; // [esp+18h] [ebp+8h]

  v6 = (unsigned __int8 *)t_wc;
  v7 = (unsigned __int8 *)te;
  v8 = (const LoggingContext_t *)((char *)te + s_wc);
  v9 = t_wc + tlen;
  tea = (const LoggingContext_t *)(t_wc + tlen);
  if ( v7 < (unsigned __int8 *)v8 )
  {
    while ( (unsigned int)v6 < v9 )
    {
      v10 = my_utf16_uni(a1: (int)cs, a2: &s_wc, a3: v7, a4: (unsigned int)v8);
      v11 = my_utf16_uni(a1: (int)cs, a2: &t_wc, a3: v6, a4: (unsigned int)tea);
      if ( v10 <= 0 || v11 <= 0 )
        return bincmp(s: (char *)v7, a2: (int)tea, a3: v6, se: v8);
      if ( t_wc != s_wc )
        return (DName *)(t_wc < s_wc ? 1 : -1);
      v7 += v10;
      v6 += v11;
      v9 = (unsigned int)tea;
      if ( v7 >= (unsigned __int8 *)v8 )
        break;
    }
  }
  if ( t_is_prefix != 0 )
    return (DName *)&v6[-v9];
  else
    return (DName *)&v6[(char *)v8 - v9 - (char *)v7];
}

//------------------------------------------------------------------------------
// Address: 0x00431F50
// Name: my_strnncollsp_utf16_bin
// Source: json
//------------------------------------------------------------------------------
DName *__cdecl my_strnncollsp_utf16_bin(
        LIST_ENTRY32 *cs,
        const LoggingContext_t *te,
        unsigned int s_wc,
        unsigned int t_wc,
        unsigned int tlen)
{
  unsigned __int8 *v5; // ebx
  unsigned __int8 *v6; // esi
  const LoggingContext_t *v7; // edi
  unsigned int v8; // edx
  int v9; // ebp
  int v10; // eax
  int v11; // ebp
  int v12; // eax
  const LoggingContext_t *tea; // [esp+18h] [ebp+8h]

  v5 = (unsigned __int8 *)t_wc;
  v6 = (unsigned __int8 *)te;
  v7 = (const LoggingContext_t *)((char *)te + s_wc);
  v8 = t_wc + tlen;
  tea = (const LoggingContext_t *)(t_wc + tlen);
  if ( v6 < (unsigned __int8 *)v7 )
  {
    while ( (unsigned int)v5 < v8 )
    {
      v9 = my_utf16_uni(a1: (int)cs, a2: &s_wc, a3: v6, a4: (unsigned int)v7);
      v10 = my_utf16_uni(a1: (int)cs, a2: &t_wc, a3: v5, a4: (unsigned int)tea);
      if ( v9 <= 0 || v10 <= 0 )
        return bincmp(s: (char *)v6, a2: (int)tea, a3: v5, se: v7);
      if ( t_wc != s_wc )
        return (DName *)(t_wc < s_wc ? 1 : -1);
      v8 = (unsigned int)tea;
      v6 += v9;
      v5 += v10;
      if ( v6 >= (unsigned __int8 *)v7 )
        break;
    }
  }
  if ( (char *)v7 - (char *)v6 != v8 - (_DWORD)v5 )
  {
    v11 = 1;
    if ( (char *)v7 - (char *)v6 < v8 - (unsigned int)v5 )
    {
      v6 = v5;
      v7 = (const LoggingContext_t *)v8;
      v11 = -1;
    }
    for ( ; v6 < (unsigned __int8 *)v7; v6 += v12 )
    {
      v12 = my_utf16_uni(a1: (int)cs, a2: &s_wc, a3: v6, a4: (unsigned int)v7);
      if ( v12 < 0 )
        break;
      if ( s_wc != 32 )
      {
        if ( s_wc < 0x20 )
          return (DName *)-v11;
        return (DName *)v11;
      }
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00432040
// Name: _my_like_range_utf16
// Source: json
//------------------------------------------------------------------------------
char __cdecl my_like_range_utf16(
        LIST_ENTRY32 *a1,
        char *ptr,
        unsigned int charlen,
        int escape,
        int w_one,
        int w_many,
        unsigned int res_length,
        char *min_org,
        char *max_str,
        unsigned int *min_length,
        unsigned int *max_length)
{
  char *v11; // ecx
  char *v12; // ebp
  char *v14; // esi
  char *v15; // ebx
  char *v16; // edi
  char v17; // al
  int v18; // eax
  char v19; // bl
  char v20; // bl
  char *v21; // ecx
  char *v22; // edx
  char v23; // al
  char *v24; // esi
  char *i; // eax
  char *v26; // eax
  char *j; // eax
  char *v28; // edx
  _BYTE *v29; // ecx
  unsigned int v31; // eax
  char *v32; // esi
  _BYTE *v33; // ecx
  char *v34; // edx
  char *min_end; // [esp+10h] [ebp-8h]
  tagShutdownType end; // [esp+14h] [ebp-4h]
  unsigned int charlena; // [esp+24h] [ebp+Ch]

  v11 = min_org;
  v12 = ptr;
  min_end = &min_org[res_length];
  v14 = ptr + 1;
  v15 = min_org;
  end = (tagShutdownType)&ptr[charlen];
  charlena = res_length / a1[11].Flink;
  if ( (unsigned int)(ptr + 1) < end )
  {
    v16 = min_org + 1;
    do
    {
      if ( v16 >= min_end || charlena == 0 )
        break;
      v17 = *v12;
      if ( *v12 != 0 )
        goto LABEL_13;
      v18 = *v14;
      if ( v18 == escape && (unsigned int)v14 < end )
      {
        v19 = v12[2];
        v12 += 2;
        *max_str = v19;
        *v11 = v19;
        v20 = v14[2];
        v14 += 2;
        v21 = v11 + 1;
        v22 = max_str + 1;
        *v22 = v20;
        *v21 = v20;
      }
      else
      {
        if ( v18 != w_one )
        {
          if ( v18 == w_many )
          {
            if ( (a1[1].Blink & 0x10) != 0 )
              v31 = v11 - min_org;
            else
              v31 = res_length;
            *min_length = v31;
            *max_length = res_length;
            v32 = v11 + 1;
            do
            {
              *v11 = 0;
              v33 = v11 + 1;
              *v33 = 0;
              *max_str = HIBYTE(a1[11].Blink);
              v34 = max_str + 1;
              v32 += 2;
              *v34 = BYTE2(a1[11].Blink);
              v11 = v33 + 1;
              max_str = v34 + 1;
            }
            while ( v32 < min_end );
            return 0;
          }
          v17 = *v12;
LABEL_13:
          *max_str = v17;
          *v11 = v17;
          v23 = *v14;
          v21 = v11 + 1;
          v22 = max_str + 1;
          *v22 = *v14;
          *v21 = v23;
          goto LABEL_14;
        }
        *v11 = BYTE1(a1[11].Blink);
        v21 = v11 + 1;
        *v21 = a1[11].Blink;
        *max_str = HIBYTE(a1[11].Blink);
        v22 = max_str + 1;
        *v22 = BYTE2(a1[11].Blink);
      }
LABEL_14:
      --charlena;
      v15 = min_org;
      v14 += 2;
      v11 = v21 + 1;
      v16 += 2;
      max_str = v22 + 1;
      v12 += 2;
    }
    while ( (unsigned int)v14 < end );
  }
  v24 = v11 - 1;
  for ( i = v11; v24 > v15; *i = 0 )
  {
    if ( *(i - 1) != 0 )
      break;
    if ( *(i - 2) != 0 )
      break;
    v26 = i - 1;
    *v26 = 32;
    i = v26 - 1;
    v24 -= 2;
  }
  *max_length = v11 - v15;
  *min_length = v11 - v15;
  for ( j = v11 + 1; j < min_end; max_str = v28 + 1 )
  {
    *max_str = 0;
    *v11 = 0;
    v28 = max_str + 1;
    v29 = v11 + 1;
    *v28 = 32;
    *v29 = 32;
    j += 2;
    v11 = v29 + 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004321F0
// Name: my_utf32_uni
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_utf32_uni(int a1, _DWORD *a2, unsigned __int8 *a3, unsigned int a4)
{
  if ( (unsigned int)(a3 + 4) > a4 )
    return -104;
  *a2 = a3[3] + ((a3[2] + ((a3[1] + (*a3 << 8)) << 8)) << 8);
  return 4;
}

//------------------------------------------------------------------------------
// Address: 0x00432230
// Name: my_uni_utf32
// Source: json
//------------------------------------------------------------------------------
int my_uni_utf32(LIST_ENTRY32 *cs, const char *wc, unsigned __int8 *s, unsigned __int8 *e, ...)
{
  if ( s + 4 > e )
    return -104;
  *s = HIBYTE(wc);
  s[1] = BYTE2(wc);
  s[2] = BYTE1(wc);
  s[3] = (unsigned __int8)wc;
  return 4;
}

//------------------------------------------------------------------------------
// Address: 0x00432270
// Name: my_caseup_utf32
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_caseup_utf32(LIST_ENTRY32 *cs, unsigned int src, unsigned int srclen)
{
  unsigned int result; // eax
  unsigned __int8 *v5; // esi
  unsigned __int8 *v6; // ebx
  int v7; // edi
  unsigned int v8; // eax
  int v9; // ecx
  int (__stdcall *uni_plane)(); // [esp+10h] [ebp+4h]

  result = srclen;
  v5 = (unsigned __int8 *)src;
  v6 = (unsigned __int8 *)(src + srclen);
  uni_plane = (int (__stdcall *)())cs[8].Flink;
  if ( src < src + srclen )
  {
    do
    {
      v7 = my_utf32_uni(a1: (int)cs, a2: &src, a3: v5, a4: (unsigned int)v6);
      if ( v7 <= 0 )
        break;
      v8 = src;
      if ( src >> 8 < 0x100 )
      {
        v9 = *((_DWORD *)uni_plane + (src >> 8));
        if ( v9 != 0 )
        {
          v8 = *(unsigned __int16 *)(v9 + 6 * (unsigned __int8)src);
          src = v8;
        }
      }
      if ( v7 != my_uni_utf32(cs, wc: (const char *)v8, s: v5, e: v6) )
        break;
      v5 += v7;
    }
    while ( v5 < v6 );
    return srclen;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00432300
// Name: my_hash_sort_utf32
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_hash_sort_utf32(
        LIST_ENTRY32 *a1,
        unsigned __int8 *s,
        const LoggingContext_t *e,
        unsigned int *n1,
        unsigned int *n2)
{
  unsigned int v5; // eax
  int result; // eax
  unsigned int v7; // ecx
  int v8; // edx
  unsigned int wc; // [esp+8h] [ebp-8h] BYREF
  int (__stdcall *uni_plane)(); // [esp+Ch] [ebp-4h]
  const LoggingContext_t *ea; // [esp+1Ch] [ebp+Ch]

  v5 = (unsigned int)e + (_DWORD)s;
  uni_plane = (int (__stdcall *)())a1[8].Flink;
  ea = (const LoggingContext_t *)v5;
  if ( v5 > (unsigned int)(s + 3) )
  {
    do
    {
      if ( *(_BYTE *)(v5 - 1) != 32 )
        break;
      if ( *(_BYTE *)(v5 - 2) != 0 )
        break;
      if ( *(_BYTE *)(v5 - 3) != 0 )
        break;
      if ( *(_BYTE *)(v5 - 4) != 0 )
        break;
      v5 -= 4;
    }
    while ( v5 > (unsigned int)(s + 3) );
    ea = (const LoggingContext_t *)v5;
  }
  result = my_utf32_uni((int)a1, a2: &wc, a3: s, a4: v5);
  if ( result > 0 )
  {
    while ( 1 )
    {
      v7 = wc;
      if ( wc >> 8 >= 0x100 )
        break;
      v8 = *((_DWORD *)uni_plane + (wc >> 8));
      if ( v8 != 0 )
      {
        v7 = *(unsigned __int16 *)(v8 + 6 * (unsigned __int8)wc + 4);
LABEL_13:
        wc = v7;
      }
      *n1 ^= (*n1 << 8) + HIBYTE(v7) * (*n2 + (*n1 & 0x3F));
      *n2 += 3;
      *n1 ^= (*n1 << 8) + BYTE2(v7) * (*n2 + (*n1 & 0x3F));
      *n2 += 3;
      *n1 ^= (*n1 << 8) + BYTE1(v7) * (*n2 + (*n1 & 0x3F));
      *n2 += 3;
      s += result;
      *n1 ^= (*n1 << 8) + (unsigned __int8)v7 * (*n2 + (*n1 & 0x3F));
      *n2 += 3;
      result = my_utf32_uni((int)a1, a2: &wc, a3: s, a4: (unsigned int)ea);
      if ( result <= 0 )
        return result;
    }
    v7 = 65533;
    goto LABEL_13;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00432470
// Name: my_casedn_utf32
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_casedn_utf32(LIST_ENTRY32 *cs, unsigned int src, unsigned int srclen)
{
  unsigned __int8 *v4; // edi
  unsigned __int8 *v5; // ebx
  int i; // esi
  unsigned int v7; // eax
  int v8; // ecx
  int (__stdcall *uni_plane)(); // [esp+14h] [ebp+4h]

  v4 = (unsigned __int8 *)src;
  v5 = (unsigned __int8 *)(src + srclen);
  uni_plane = (int (__stdcall *)())cs[8].Flink;
  for ( i = my_utf32_uni(a1: (int)cs, a2: &src, a3: (unsigned __int8 *)src, a4: src + srclen);
        i > 0;
        i = my_utf32_uni(a1: (int)cs, a2: &src, a3: v4, a4: (unsigned int)v5) )
  {
    v7 = src;
    if ( src >> 8 < 0x100 )
    {
      v8 = *((_DWORD *)uni_plane + (src >> 8));
      if ( v8 != 0 )
      {
        v7 = *(unsigned __int16 *)(v8 + 6 * (unsigned __int8)src + 2);
        src = v7;
      }
    }
    if ( i != my_uni_utf32(cs, wc: (const char *)v7, s: v4, e: v5) )
      break;
    v4 += i;
  }
  return srclen;
}

//------------------------------------------------------------------------------
// Address: 0x00432500
// Name: my_strnncoll_utf32
// Source: json
//------------------------------------------------------------------------------
DName *__cdecl my_strnncoll_utf32(
        LIST_ENTRY32 *cs,
        unsigned int s_wc,
        unsigned int t_wc,
        int (__stdcall *uni_plane)(),
        const LoggingContext_t *te,
        char t_is_prefix)
{
  unsigned __int8 *v6; // ebx
  unsigned __int8 *v7; // edi
  const LoggingContext_t *v8; // esi
  int (__stdcall *Flink)(); // eax
  const LoggingContext_t *v10; // ebp
  int v11; // eax
  unsigned int v12; // eax
  int v13; // edx
  unsigned int v14; // ecx
  int v15; // edx
  int s_res; // [esp+10h] [ebp-8h]
  int t_res; // [esp+14h] [ebp-4h]

  v6 = (unsigned __int8 *)uni_plane;
  v7 = (unsigned __int8 *)s_wc;
  v8 = (const LoggingContext_t *)(s_wc + t_wc);
  Flink = (int (__stdcall *)())cs[8].Flink;
  v10 = (const LoggingContext_t *)((char *)te + (_DWORD)uni_plane);
  te = (const LoggingContext_t *)((char *)te + (_DWORD)uni_plane);
  uni_plane = Flink;
  if ( s_wc < s_wc + t_wc )
  {
    do
    {
      if ( v6 >= (unsigned __int8 *)v10 )
        break;
      s_res = my_utf32_uni(a1: (int)cs, a2: &s_wc, a3: v7, a4: (unsigned int)v8);
      v11 = my_utf32_uni(a1: (int)cs, a2: &t_wc, a3: v6, a4: (unsigned int)v10);
      t_res = v11;
      if ( s_res <= 0 || v11 <= 0 )
        return bincmp(s: (char *)v7, a2: (int)v10, a3: v6, se: v8);
      v12 = s_wc;
      if ( s_wc >> 8 >= 0x100 )
      {
        v12 = 65533;
      }
      else
      {
        v13 = *((_DWORD *)uni_plane + (s_wc >> 8));
        if ( v13 == 0 )
          goto LABEL_10;
        v12 = *(unsigned __int16 *)(v13 + 6 * (unsigned __int8)s_wc + 4);
      }
      s_wc = v12;
LABEL_10:
      v14 = t_wc;
      if ( t_wc >> 8 >= 0x100 )
      {
        v14 = 65533;
      }
      else
      {
        v15 = *((_DWORD *)uni_plane + (t_wc >> 8));
        v10 = te;
        if ( v15 == 0 )
          goto LABEL_15;
        v14 = *(unsigned __int16 *)(v15 + 6 * (unsigned __int8)t_wc + 4);
      }
      t_wc = v14;
LABEL_15:
      if ( v14 != v12 )
        return (DName *)(v14 < v12 ? 1 : -1);
      v7 += s_res;
      v6 += t_res;
    }
    while ( v7 < (unsigned __int8 *)v8 );
  }
  if ( t_is_prefix != 0 )
    return (DName *)(v6 - (unsigned __int8 *)v10);
  else
    return (DName *)&v6[(char *)v8 - (char *)v10 - (_DWORD)v7];
}

//------------------------------------------------------------------------------
// Address: 0x00432650
// Name: my_strnncollsp_utf32
// Source: json
//------------------------------------------------------------------------------
DName *__cdecl my_strnncollsp_utf32(
        LIST_ENTRY32 *cs,
        unsigned int s_wc,
        int swap,
        int (__stdcall *uni_plane)(),
        const LoggingContext_t *te)
{
  unsigned __int8 *v5; // ebx
  unsigned __int8 *v6; // esi
  const LoggingContext_t *v7; // edi
  int (__stdcall *Flink)(); // eax
  const LoggingContext_t *v9; // ebp
  int v10; // eax
  unsigned int v11; // eax
  int v12; // edx
  unsigned int v13; // ecx
  int v14; // edx
  int v15; // eax
  DName *result; // eax
  int s_res; // [esp+10h] [ebp-8h]
  int t_res; // [esp+14h] [ebp-4h]

  v5 = (unsigned __int8 *)uni_plane;
  v6 = (unsigned __int8 *)s_wc;
  v7 = (const LoggingContext_t *)(s_wc + swap);
  Flink = (int (__stdcall *)())cs[8].Flink;
  v9 = (const LoggingContext_t *)((char *)te + (_DWORD)uni_plane);
  te = (const LoggingContext_t *)((char *)te + (_DWORD)uni_plane);
  uni_plane = Flink;
  if ( s_wc < s_wc + swap )
  {
    do
    {
      if ( v5 >= (unsigned __int8 *)v9 )
        break;
      s_res = my_utf32_uni(a1: (int)cs, a2: &s_wc, a3: v6, a4: (unsigned int)v7);
      v10 = my_utf32_uni(a1: (int)cs, a2: &swap, a3: v5, a4: (unsigned int)v9);
      t_res = v10;
      if ( s_res <= 0 || v10 <= 0 )
        return bincmp(s: (char *)v6, a2: (int)v9, a3: v5, se: v7);
      v11 = s_wc;
      if ( s_wc >> 8 >= 0x100 )
      {
        v11 = 65533;
      }
      else
      {
        v12 = *((_DWORD *)uni_plane + (s_wc >> 8));
        if ( v12 == 0 )
          goto LABEL_10;
        v11 = *(unsigned __int16 *)(v12 + 6 * (unsigned __int8)s_wc + 4);
      }
      s_wc = v11;
LABEL_10:
      v13 = swap;
      if ( (unsigned int)swap >> 8 >= 0x100 )
      {
        v13 = 65533;
      }
      else
      {
        v14 = *((_DWORD *)uni_plane + ((unsigned int)swap >> 8));
        v9 = te;
        if ( v14 == 0 )
          goto LABEL_15;
        v13 = *(unsigned __int16 *)(v14 + 6 * (unsigned __int8)swap + 4);
      }
      swap = v13;
LABEL_15:
      if ( v13 != v11 )
        return (DName *)(v13 < v11 ? 1 : -1);
      v6 += s_res;
      v5 += t_res;
    }
    while ( v6 < (unsigned __int8 *)v7 );
  }
  if ( (char *)v7 - (char *)v6 != (char *)v9 - (char *)v5 )
  {
    swap = 1;
    if ( (char *)v7 - (char *)v6 < (unsigned int)((char *)v9 - (char *)v5) )
    {
      v6 = v5;
      v7 = v9;
      swap = -1;
    }
    for ( ; v6 < (unsigned __int8 *)v7; v6 += v15 )
    {
      v15 = my_utf32_uni(a1: (int)cs, a2: &s_wc, a3: v6, a4: (unsigned int)v7);
      if ( v15 < 0 )
        break;
      if ( s_wc != 32 )
      {
        result = (DName *)swap;
        if ( s_wc < 0x20 )
          return (DName *)-swap;
        return result;
      }
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004327E0
// Name: my_strnxfrmlen_utf32
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_strnxfrmlen_utf32(LIST_ENTRY32 *cs, unsigned int len)
{
  return len >> 1;
}

//------------------------------------------------------------------------------
// Address: 0x004327F0
// Name: my_mbcharlen_utf32
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_mbcharlen_utf32()
{
  return 4;
}

//------------------------------------------------------------------------------
// Address: 0x00432800
// Name: my_vsnprintf_utf32
// Source: json
//------------------------------------------------------------------------------
int __fastcall my_vsnprintf_utf32(int a1, char *a2, _BYTE *a3, int a4)
{
  _BYTE *v4; // esi
  _BYTE *v6; // edx
  char v7; // al
  int v8; // ebp
  char *v9; // esi
  char v10; // al
  char v11; // al
  const char *v12; // ecx
  unsigned int v13; // edx
  int v14; // eax
  _BYTE *v15; // esi
  _BYTE *v17; // esi
  char *v18; // edi
  int v19; // ecx
  char v20; // al
  char *v21; // esi
  int v22; // [esp+8h] [ebp-20h]
  char v23[16]; // [esp+14h] [ebp-14h] BYREF

  v4 = a3;
  v6 = &a3[a4];
  v7 = *a2;
  if ( *a2 != 0 )
  {
    v8 = a1 - 4;
    while ( 1 )
    {
      if ( v7 == 37 )
      {
        do
        {
          do
            v10 = *++a2;
          while ( v10 >= 48 && v10 <= 57 );
        }
        while ( v10 == 46 || v10 == 45 );
        if ( *a2 == 108 )
          ++a2;
        v11 = *a2;
        if ( *a2 == 115 )
        {
          v12 = *(const char **)(v8 + 4);
          v13 = v6 - v4;
          v22 = v8 + 4;
          if ( v12 == nullptr )
            v12 = "(null)";
          v14 = strlen(v12);
          if ( v13 <= 4 * v14 )
            v14 = (v13 >> 2) - 1;
          for ( ; v14 != 0; ++v12 )
          {
            *v4 = 0;
            v4[1] = 0;
            v4[2] = 0;
            v4[3] = *v12;
            --v14;
            v4 += 4;
          }
          v8 = v22;
        }
        else if ( v11 == 100 || v11 == 117 )
        {
          v18 = v23;
          if ( (unsigned int)(&a3[a4] - v4) < 0x40 )
            break;
          v19 = *(_DWORD *)(v8 + 4);
          v8 += 4;
          if ( v11 == 100 )
            int10_to_str(result: v19, dst: v23, radix: -10);
          else
            int10_to_str(result: v19, dst: v23, radix: 10);
          v20 = v23[0];
          if ( v23[0] != 0 )
          {
            do
            {
              *v4 = 0;
              v21 = v4 + 1;
              *v21++ = 0;
              *v21++ = 0;
              ++v18;
              *v21 = v20;
              v20 = *v18;
              v4 = v21 + 1;
            }
            while ( *v18 != 0 );
          }
        }
        else
        {
          if ( v4 == v6 )
            break;
          *v4 = 0;
          v17 = v4 + 1;
          *v17++ = 0;
          *v17++ = 0;
          *v17 = 37;
          v4 = v17 + 1;
        }
      }
      else
      {
        if ( v4 >= v6 )
          break;
        *v4 = 0;
        v9 = v4 + 1;
        *v9++ = 0;
        *v9++ = 0;
        *v9 = *a2;
        v4 = v9 + 1;
      }
      v7 = *++a2;
      if ( v7 == 0 )
        break;
      v6 = &a3[a4];
    }
  }
  *v4 = 0;
  v15 = v4 + 1;
  *v15++ = 0;
  *v15++ = 0;
  *v15 = 0;
  return v15 - a3 - 3;
}

//------------------------------------------------------------------------------
// Address: 0x00432990
// Name: my_snprintf_utf32
// Source: json
//------------------------------------------------------------------------------
int my_snprintf_utf32(LIST_ENTRY32 *a1, char *to, unsigned int n, char *fmt, ...)
{
  va_list va; // [esp+14h] [ebp+14h] BYREF

  va_start(va, fmt);
  return my_vsnprintf_utf32(a1: (int)va, a2: fmt, a3: to, a4: n);
}

//------------------------------------------------------------------------------
// Address: 0x004329B0
// Name: my_strtoll10_utf32
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_strtoll10_utf32(LIST_ENTRY32 *cs, unsigned int negative, _DWORD *a3, int *error)
{
  _BYTE *v5; // esi
  signed int v6; // kr00_4
  _BYTE *v7; // edx
  char v8; // al
  int v9; // ebx
  unsigned int v10; // ebp
  _BYTE *v11; // ecx
  unsigned __int8 v12; // al
  unsigned __int8 v13; // al
  unsigned __int64 v14; // rax
  _BYTE *v15; // edi
  unsigned int v16; // ecx
  _BYTE *v17; // ebx
  _BYTE *v18; // edx
  unsigned __int8 v19; // al
  __int64 v20; // rax
  unsigned __int8 v21; // al
  _BYTE *v22; // esi
  unsigned int v23; // edi
  _BYTE *v24; // eax
  unsigned __int8 v25; // dl
  unsigned int v26; // esi
  tagShutdownType end; // [esp+10h] [ebp-10h]
  unsigned int cutoff; // [esp+14h] [ebp-Ch]
  unsigned int cutoff2; // [esp+18h] [ebp-8h]
  unsigned int cutoff3; // [esp+1Ch] [ebp-4h]
  int negativea; // [esp+28h] [ebp+8h]

  v5 = (_BYTE *)negative;
  if ( a3 == nullptr )
    goto no_conv_0;
  v6 = *a3 - negative;
  v7 = (_BYTE *)(negative + 4 * (v6 / 4));
  end = (tagShutdownType)v7;
  if ( negative < (unsigned int)v7 )
  {
    do
    {
      if ( *v5 != 0 )
        break;
      if ( v5[1] != 0 )
        break;
      if ( v5[2] != 0 )
        break;
      v8 = v5[3];
      if ( v8 != 32 && v8 != 9 )
        break;
      v5 += 4;
    }
    while ( v5 < v7 );
  }
  if ( v5 == v7 )
    goto no_conv_0;
  v9 = 0;
  negativea = 0;
  if ( *v5 != 0 || v5[1] != 0 || v5[2] != 0 || v5[3] != 45 )
  {
    *error = 0;
    if ( *v5 == 0 && v5[1] == 0 && v5[2] == 0 && v5[3] == 43 )
    {
      v5 += 4;
      if ( v5 == v7 )
        goto no_conv_0;
    }
    cutoff = 184467440;
    cutoff2 = 737095516;
    cutoff3 = 15;
  }
  else
  {
    v5 += 4;
    v9 = 1;
    *error = -1;
    negativea = 1;
    if ( v5 == v7 )
      goto no_conv_0;
    cutoff = 92233720;
    cutoff2 = 368547758;
    cutoff3 = 8;
  }
  if ( *v5 != 0 || v5[1] != 0 )
    goto no_conv_0;
  if ( v5[2] != 0 || v5[3] != 48 )
  {
    if ( v5[2] == 0 )
    {
      v12 = v5[3] - 48;
      if ( v12 <= 9u )
      {
        v5 += 4;
        v10 = v12;
        v11 = v5 + 32;
        goto LABEL_36;
      }
    }
no_conv_0:
    *error = 33;
    *a3 = negative;
    LODWORD(v14) = 0;
    return v14;
  }
  v10 = 0;
  do
  {
    v5 += 4;
    if ( v5 == v7 )
      goto end_i_0;
  }
  while ( *v5 == 0 && v5[1] == 0 && v5[2] == 0 && v5[3] == 48 );
  v11 = v5 + 36;
LABEL_36:
  if ( v11 > v7 )
    v11 = (_BYTE *)(negative + 4 * (v6 / 4));
  if ( v5 != v11 )
  {
    while ( *v5 == 0 )
    {
      if ( v5[1] != 0 )
        break;
      if ( v5[2] != 0 )
        break;
      v13 = v5[3] - 48;
      if ( v13 > 9u )
        break;
      v5 += 4;
      v10 = v13 + 10 * v10;
      if ( v5 == v11 )
        goto LABEL_44;
    }
    goto end_i_0;
  }
LABEL_44:
  if ( v5 != v7 )
  {
    v15 = v5 + 36;
    v16 = 0;
    v17 = v5;
    v18 = v5 + 36;
    if ( (unsigned int)(v5 + 36) > end )
      v18 = (_BYTE *)end;
    do
    {
      if ( *v5 != 0 )
        goto end_i_and_j_0;
      if ( v5[1] != 0 )
        goto end_i_and_j_0;
      if ( v5[2] != 0 )
        goto end_i_and_j_0;
      v19 = v5[3] - 48;
      if ( v19 > 9u )
        goto end_i_and_j_0;
      v5 += 4;
      v16 = v19 + 10 * v16;
    }
    while ( v5 != v18 );
    if ( v5 == (_BYTE *)end )
    {
      if ( v5 != v15 )
      {
end_i_and_j_0:
        v20 = v10 * (unsigned __int64)(unsigned int)lfactor_0[(unsigned int)(v5 - v17) >> 2];
LABEL_82:
        v14 = v16 + v20;
        *a3 = v5;
        if ( negativea == 0 )
          return v14;
        return -(__int64)v14;
      }
    }
    else if ( *v5 == 0 && v5[1] == 0 && v5[2] == 0 )
    {
      v21 = v5[3] - 48;
      if ( v21 <= 9u )
      {
        v22 = v5 + 4;
        v23 = v21;
        if ( v22 == (_BYTE *)end || *v22 != 0 || v22[1] != 0 || (v24 = v22 + 2, v22[2] != 0) || (v25 = v22[3] - 48) > 9u )
        {
          v14 = v23 + 10 * (v16 + 1000000000LL * v10);
          *a3 = v22;
          if ( negativea == 0 )
            return v14;
          if ( v14 <= 0x8000000000000000uLL )
            return -(__int64)v14;
        }
        else
        {
          v26 = v25 + 10 * v23;
          *a3 = v24;
          if ( (v24 == (_BYTE *)end || *v24 != 0 || v24[1] != 0 || v24[2] != 0 || (unsigned __int8)(v24[3] - 48) > 9u)
            && v10 <= cutoff
            && (v10 != cutoff || v16 < cutoff2 || v26 <= cutoff3) )
          {
            LODWORD(v14) = v26 + 100 * (v16 + 1000000000 * v10);
            return v14;
          }
        }
        *error = 34;
        if ( negativea != 0 )
          LODWORD(v14) = 0;
        else
          LODWORD(v14) = -1;
        return v14;
      }
    }
    v20 = 1000000000LL * v10;
    goto LABEL_82;
  }
end_i_0:
  *a3 = v5;
  LODWORD(v14) = v10;
  if ( v9 != 0 )
    LODWORD(v14) = -v10;
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x00432D40
// Name: my_numchars_utf32
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_numchars_utf32(int a1, int a2, int a3)
{
  return (unsigned int)(a3 - a2) >> 2;
}

//------------------------------------------------------------------------------
// Address: 0x00432D50
// Name: my_charpos_utf32
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_charpos_utf32(int a1, int a2, int a3, int a4)
{
  int result; // eax

  result = 4 * a4;
  if ( 4 * a4 > (unsigned int)(a3 - a2) )
    return a3 - a2 + 4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00432D70
// Name: my_well_formed_len_utf32
// Source: json
//------------------------------------------------------------------------------
int my_well_formed_len_utf32(LIST_ENTRY32 *cs, const char *b, tagShutdownType e, unsigned int nchars, int *error, ...)
{
  const char *v5; // eax
  const char *v6; // esi
  int v7; // ecx

  v5 = b;
  v6 = (const char *)e;
  v7 = e - (_DWORD)b;
  *error = 0;
  if ( e - (int)b > 4 * nchars )
  {
    v7 = 4 * nchars;
    v6 = &b[4 * nchars];
  }
  if ( b >= v6 )
    return v7;
  while ( *v5 == 0 && v5[1] <= 0x10u )
  {
    v5 += 4;
    if ( v5 >= v6 )
      return v7;
  }
  *error = 1;
  return v5 - b;
}

//------------------------------------------------------------------------------
// Address: 0x00432DD0
// Name: my_fill_utf32
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_fill_utf32(int a1, char *a2, int a3, int a4)
{
  int result; // eax
  int v5; // [esp+8h] [ebp-10h] BYREF
  char v6[2]; // [esp+12h] [ebp-6h] BYREF

  result = (*(int (__cdecl **)(int, int, int *, char *))(*(_DWORD *)(a1 + 100) + 36))(a1, a2: a4, a3: &v5, a4: v6);
  if ( a2 < &a2[a3] )
  {
    result = v5;
    memset32(a2, v5, ((unsigned int)(a3 - 1) >> 2) + 1);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00432E30
// Name: my_lengthsp_utf32
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_lengthsp_utf32(int a1, int a2, int a3)
{
  unsigned int i; // eax

  for ( i = a2 + a3; i > a2 + 3; i -= 4 )
  {
    if ( *(_BYTE *)(i - 1) != 32 )
      break;
    if ( *(_BYTE *)(i - 2) != 0 )
      break;
    if ( *(_BYTE *)(i - 3) != 0 )
      break;
    if ( *(_BYTE *)(i - 4) != 0 )
      break;
  }
  return i - a2;
}

//------------------------------------------------------------------------------
// Address: 0x00432E70
// Name: my_strnncoll_utf32_bin
// Source: json
//------------------------------------------------------------------------------
DName *__cdecl my_strnncoll_utf32_bin(
        LIST_ENTRY32 *cs,
        const LoggingContext_t *te,
        unsigned int s_wc,
        unsigned int t_wc,
        unsigned int tlen,
        char t_is_prefix)
{
  unsigned __int8 *v6; // ebx
  unsigned __int8 *v7; // edi
  const LoggingContext_t *v8; // esi
  unsigned int v9; // eax
  int v10; // ebp
  int v11; // eax
  const LoggingContext_t *tea; // [esp+18h] [ebp+8h]

  v6 = (unsigned __int8 *)t_wc;
  v7 = (unsigned __int8 *)te;
  v8 = (const LoggingContext_t *)((char *)te + s_wc);
  v9 = t_wc + tlen;
  tea = (const LoggingContext_t *)(t_wc + tlen);
  if ( v7 < (unsigned __int8 *)v8 )
  {
    while ( (unsigned int)v6 < v9 )
    {
      v10 = my_utf32_uni(a1: (int)cs, a2: &s_wc, a3: v7, a4: (unsigned int)v8);
      v11 = my_utf32_uni(a1: (int)cs, a2: &t_wc, a3: v6, a4: (unsigned int)tea);
      if ( v10 <= 0 || v11 <= 0 )
        return bincmp(s: (char *)v7, a2: (int)tea, a3: v6, se: v8);
      if ( t_wc != s_wc )
        return (DName *)(t_wc < s_wc ? 1 : -1);
      v7 += v10;
      v6 += v11;
      v9 = (unsigned int)tea;
      if ( v7 >= (unsigned __int8 *)v8 )
        break;
    }
  }
  if ( t_is_prefix != 0 )
    return (DName *)&v6[-v9];
  else
    return (DName *)&v6[(char *)v8 - v9 - (char *)v7];
}

//------------------------------------------------------------------------------
// Address: 0x00432F30
// Name: my_strnncollsp_utf32_bin
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strnncollsp_utf32_bin(
        LIST_ENTRY32 *cs,
        const LoggingContext_t *se,
        const LoggingContext_t *te,
        const LoggingContext_t *t,
        unsigned int tlen)
{
  const LoggingContext_t *v5; // ecx
  unsigned __int8 *v6; // eax
  unsigned __int8 *v7; // esi
  const LoggingContext_t *v8; // edx
  const LoggingContext_t *v9; // edi
  unsigned int v10; // ecx
  unsigned int v11; // edx
  int v12; // edi
  unsigned int v13; // ecx
  const LoggingContext_t *sea; // [esp+18h] [ebp+8h]

  v5 = (const LoggingContext_t *)tlen;
  v6 = (unsigned __int8 *)se;
  v7 = (unsigned __int8 *)t;
  v8 = (const LoggingContext_t *)((char *)te + (_DWORD)se);
  sea = (const LoggingContext_t *)((char *)te + (_DWORD)se);
  v9 = te;
  if ( (unsigned int)te >= tlen )
    v9 = (const LoggingContext_t *)tlen;
  if ( v9 != nullptr )
  {
    while ( 1 )
    {
      v10 = v6[3] + ((v6[2] + ((v6[1] + (*v6 << 8)) << 8)) << 8);
      v11 = v7[3] + ((v7[2] + ((v7[1] + (*v7 << 8)) << 8)) << 8);
      if ( v11 != v10 )
        return v11 < v10 ? 1 : -1;
      v6 += 4;
      v7 += 4;
      v9 = (const LoggingContext_t *)((char *)v9 - 4);
      if ( v9 == nullptr )
      {
        v5 = (const LoggingContext_t *)tlen;
        v8 = sea;
        goto LABEL_7;
      }
    }
  }
  else
  {
LABEL_7:
    if ( te == v5 )
      return 0;
    v12 = 1;
    if ( te < v5 )
    {
      v8 = (const LoggingContext_t *)((char *)t + tlen);
      v6 = v7;
      v12 = -1;
    }
    if ( v6 >= (unsigned __int8 *)v8 )
    {
      return 0;
    }
    else
    {
      while ( 1 )
      {
        v13 = v6[3] + ((v6[2] + ((v6[1] + (*v6 << 8)) << 8)) << 8);
        if ( v13 != 32 )
          break;
        v6 += 4;
        if ( v6 >= (unsigned __int8 *)v8 )
          return 0;
      }
      if ( v13 < 0x20 )
        return -v12;
      return v12;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00433020
// Name: _my_like_range_utf32
// Source: json
//------------------------------------------------------------------------------
char __cdecl my_like_range_utf32(
        unsigned int charlen,
        tagShutdownType ptr,
        char *min_end,
        const char *escape,
        const char *w_one,
        const char *w_many,
        unsigned int res_length,
        char *max_end,
        const char *wc,
        unsigned int *min_length,
        unsigned int *max_length)
{
  char *v11; // ebx
  char *v12; // ecx
  char *v14; // edi
  const char *v15; // ebp
  const char *v16; // ebp
  int v17; // eax
  unsigned int *v18; // edx
  unsigned int v19; // eax
  tagShutdownType end; // [esp+10h] [ebp-8h]
  unsigned int charlena; // [esp+1Ch] [ebp+4h]
  char *min_enda; // [esp+24h] [ebp+Ch]
  unsigned __int8 *max_enda; // [esp+38h] [ebp+20h]

  v11 = (char *)wc;
  v12 = &min_end[ptr];
  v14 = max_end;
  min_enda = &max_end[res_length];
  end = (tagShutdownType)v12;
  max_enda = (unsigned __int8 *)&wc[res_length];
  for ( charlena = res_length / *(_DWORD *)(charlen + 88); charlena != 0; --charlena )
  {
    if ( my_utf32_uni(a1: charlen, a2: &wc, a3: (unsigned __int8 *)ptr, a4: end) < 0 )
    {
      my_fill_utf32(a1: charlen, a2: v14, a3: min_enda - v14, a4: *(unsigned __int16 *)(charlen + 92));
      my_fill_utf32(a1: charlen, a2: v11, a3: min_enda - v14, a4: *(unsigned __int16 *)(charlen + 94));
      return 1;
    }
    v15 = wc;
    if ( wc == escape )
    {
      ptr += 4;
      if ( my_utf32_uni(a1: charlen, a2: &wc, a3: (unsigned __int8 *)ptr, a4: end) < 0 )
      {
        my_fill_utf32(a1: charlen, a2: v14, a3: min_enda - v14, a4: *(unsigned __int16 *)(charlen + 92));
        my_fill_utf32(
          a1: charlen,
          a2: v11,
          a3: max_enda - (unsigned __int8 *)v14,
          a4: *(unsigned __int16 *)(charlen + 94));
        return 1;
      }
      v16 = wc;
      if ( my_uni_utf32(cs: (LIST_ENTRY32 *)charlen, wc, s: (unsigned __int8 *)v14, e: (unsigned __int8 *)min_enda) != 4
        || my_uni_utf32(cs: (LIST_ENTRY32 *)charlen, wc: v16, s: (unsigned __int8 *)v11, e: max_enda) != 4 )
      {
        break;
      }
      *v14++ = 4;
      *v11++ = 4;
    }
    else
    {
      if ( wc == w_one )
      {
        if ( my_uni_utf32(
               cs: (LIST_ENTRY32 *)charlen,
               wc: (const char *)*(unsigned __int16 *)(charlen + 92),
               s: (unsigned __int8 *)v14,
               e: (unsigned __int8 *)min_enda) != 4 )
          break;
        v17 = my_uni_utf32(
                cs: (LIST_ENTRY32 *)charlen,
                wc: (const char *)*(unsigned __int16 *)(charlen + 94),
                s: (unsigned __int8 *)v11,
                e: max_enda);
      }
      else
      {
        if ( wc == w_many )
        {
          if ( (*(_BYTE *)(charlen + 12) & 0x10) != 0 )
          {
            v18 = max_length;
            *min_length = v14 - max_end;
            v19 = res_length;
          }
          else
          {
            v19 = res_length;
            v18 = max_length;
            *min_length = res_length;
          }
          goto LABEL_18;
        }
        if ( my_uni_utf32(cs: (LIST_ENTRY32 *)charlen, wc, s: (unsigned __int8 *)v14, e: (unsigned __int8 *)min_enda) != 4 )
          break;
        v17 = my_uni_utf32(cs: (LIST_ENTRY32 *)charlen, wc: v15, s: (unsigned __int8 *)v11, e: max_enda);
      }
      if ( v17 != 4 )
        break;
      v14 += 4;
      v11 += 4;
    }
    ptr += 4;
  }
  v18 = min_length;
  v19 = v14 - max_end;
  *max_length = v14 - max_end;
LABEL_18:
  *v18 = v19;
  my_fill_utf32(a1: charlen, a2: v14, a3: min_enda - v14, a4: *(unsigned __int16 *)(charlen + 92));
  my_fill_utf32(a1: charlen, a2: v11, a3: max_enda - (unsigned __int8 *)v11, a4: *(unsigned __int16 *)(charlen + 94));
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00433250
// Name: my_scan_utf32
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl my_scan_utf32(int a1, unsigned __int8 *a2, unsigned int a3, int a4)
{
  unsigned __int8 *v4; // esi
  unsigned __int8 *v5; // ebp
  unsigned int v7; // edi
  int v8; // eax

  v4 = a2;
  v5 = a2;
  if ( a4 != 2 )
    return nullptr;
  v7 = a3;
  if ( (unsigned int)a2 < a3 )
  {
    do
    {
      v8 = my_utf32_uni(a1, &a2, a3: v4, a4: v7);
      if ( v8 < 0 )
        break;
      if ( a2 != (unsigned __int8 *)32 )
        break;
      v4 += v8;
    }
    while ( (unsigned int)v4 < v7 );
  }
  return (unsigned __int8 *)(v4 - v5);
}

//------------------------------------------------------------------------------
// Address: 0x004332A0
// Name: my_ucs2_uni
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_ucs2_uni(int a1, _DWORD *a2, unsigned __int8 *a3, unsigned int a4)
{
  if ( (unsigned int)(a3 + 2) > a4 )
    return -102;
  *a2 = a3[1] + (*a3 << 8);
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x004332D0
// Name: my_uni_ucs2
// Source: json
//------------------------------------------------------------------------------
int my_uni_ucs2(LIST_ENTRY32 *cs, const char *wc, unsigned __int8 *r, unsigned __int8 *e, ...)
{
  if ( r + 2 > e )
    return -102;
  *r = BYTE1(wc);
  r[1] = (unsigned __int8)wc;
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x00433300
// Name: my_caseup_ucs2
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_caseup_ucs2(LIST_ENTRY32 *cs, _iobuf *src, unsigned int srclen)
{
  unsigned int result; // eax
  unsigned __int8 *v5; // esi
  unsigned __int8 *v6; // ebx
  int v7; // edi
  _iobuf *v8; // ecx
  int v9; // eax
  int (__stdcall *uni_plane)(); // [esp+10h] [ebp+4h]

  result = srclen;
  v5 = (unsigned __int8 *)src;
  v6 = (unsigned __int8 *)src + srclen;
  uni_plane = (int (__stdcall *)())cs[8].Flink;
  if ( src < (_iobuf *)((char *)src + srclen) )
  {
    do
    {
      v7 = my_ucs2_uni(a1: (int)cs, a2: &src, a3: v5, a4: (unsigned int)v6);
      if ( v7 <= 0 )
        break;
      v8 = src;
      v9 = *((_DWORD *)uni_plane + BYTE1(src));
      if ( v9 != 0 )
      {
        v8 = (_iobuf *)*(unsigned __int16 *)(v9 + 6 * (unsigned __int8)src);
        src = v8;
      }
      if ( v7 != my_uni_ucs2(cs, wc: (const char *)v8, r: v5, e: v6) )
        break;
      v5 += v7;
    }
    while ( v5 < v6 );
    return srclen;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00433380
// Name: my_hash_sort_ucs2
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl my_hash_sort_ucs2(
        LIST_ENTRY32 *a1,
        const LoggingContext_t *s,
        unsigned int wc,
        unsigned int *n1,
        unsigned int *n2)
{
  unsigned __int8 *result; // eax
  unsigned int v6; // ebx
  unsigned int *v7; // esi
  unsigned int *v8; // edi
  unsigned int v9; // ecx
  int v10; // edx
  int (__stdcall *uni_plane)(); // [esp+4h] [ebp-8h]

  result = (unsigned __int8 *)s;
  v6 = (unsigned int)s + wc;
  for ( uni_plane = (int (__stdcall *)())a1[8].Flink; v6 > (unsigned int)&s->m_ChannelID + 1; v6 -= 2 )
  {
    if ( *(_BYTE *)(v6 - 1) != 32 )
      break;
    if ( *(_BYTE *)(v6 - 2) != 0 )
      break;
  }
  if ( (unsigned int)s < v6 )
  {
    v7 = n2;
    v8 = n1;
    do
    {
      result = (unsigned __int8 *)my_ucs2_uni((int)a1, a2: &wc, a3: result, a4: v6);
      if ( (int)result <= 0 )
        break;
      v9 = wc;
      v10 = *((_DWORD *)uni_plane + BYTE1(wc));
      if ( v10 != 0 )
      {
        v9 = *(unsigned __int16 *)(v10 + 6 * (unsigned __int8)wc + 4);
        wc = v9;
      }
      *v8 ^= (*v8 << 8) + (unsigned __int8)v9 * (*v7 + (*v8 & 0x3F));
      *v7 += 3;
      result = (unsigned __int8 *)s + (_DWORD)result;
      *v8 ^= (*v8 << 8) + (v9 >> 8) * (*v7 + (*v8 & 0x3F));
      *v7 += 3;
      s = (const LoggingContext_t *)result;
    }
    while ( (unsigned int)result < v6 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00433470
// Name: my_casedn_ucs2
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_casedn_ucs2(LIST_ENTRY32 *cs, _iobuf *src, unsigned int srclen)
{
  unsigned int result; // eax
  unsigned __int8 *v5; // esi
  unsigned __int8 *v6; // ebx
  int v7; // edi
  _iobuf *v8; // ecx
  int v9; // eax
  int (__stdcall *uni_plane)(); // [esp+10h] [ebp+4h]

  result = srclen;
  v5 = (unsigned __int8 *)src;
  v6 = (unsigned __int8 *)src + srclen;
  uni_plane = (int (__stdcall *)())cs[8].Flink;
  if ( src < (_iobuf *)((char *)src + srclen) )
  {
    do
    {
      v7 = my_ucs2_uni(a1: (int)cs, a2: &src, a3: v5, a4: (unsigned int)v6);
      if ( v7 <= 0 )
        break;
      v8 = src;
      v9 = *((_DWORD *)uni_plane + BYTE1(src));
      if ( v9 != 0 )
      {
        v8 = (_iobuf *)*(unsigned __int16 *)(v9 + 6 * (unsigned __int8)src + 2);
        src = v8;
      }
      if ( v7 != my_uni_ucs2(cs, wc: (const char *)v8, r: v5, e: v6) )
        break;
      v5 += v7;
    }
    while ( v5 < v6 );
    return srclen;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004334F0
// Name: my_strnncoll_ucs2
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl my_strnncoll_ucs2(
        LIST_ENTRY32 *cs,
        const LoggingContext_t *te,
        unsigned int s_wc,
        unsigned int t_wc,
        int s_res,
        char t_is_prefix)
{
  unsigned __int8 *v6; // ebx
  int *v7; // ebp
  unsigned __int8 *v8; // edi
  unsigned int v9; // esi
  unsigned int v10; // eax
  int v12; // eax
  unsigned int v13; // eax
  int v14; // ecx
  unsigned int v15; // edx
  int v16; // ecx
  int (__stdcall *uni_plane)(); // [esp+10h] [ebp-8h]
  int t_res; // [esp+14h] [ebp-4h]
  const LoggingContext_t *tea; // [esp+20h] [ebp+8h]

  v6 = (unsigned __int8 *)t_wc;
  v7 = (int *)cs;
  v8 = (unsigned __int8 *)te;
  v9 = (unsigned int)te + s_wc;
  v10 = t_wc + s_res;
  tea = (const LoggingContext_t *)(t_wc + s_res);
  uni_plane = (int (__stdcall *)())cs[8].Flink;
  if ( (unsigned int)v8 < v9 )
  {
    while ( (unsigned int)v6 < v10 )
    {
      s_res = my_ucs2_uni(a1: (int)v7, a2: &s_wc, a3: v8, a4: v9);
      v12 = my_ucs2_uni(a1: (int)v7, a2: &t_wc, a3: v6, a4: (unsigned int)tea);
      t_res = v12;
      if ( s_res <= 0 || v12 <= 0 )
        return (unsigned __int8 *)(*v8 - *v6);
      v13 = s_wc;
      v14 = *((_DWORD *)uni_plane + BYTE1(s_wc));
      if ( v14 != 0 )
      {
        v13 = *(unsigned __int16 *)(v14 + 6 * (unsigned __int8)s_wc + 4);
        s_wc = v13;
      }
      v15 = t_wc;
      v16 = *((_DWORD *)uni_plane + BYTE1(t_wc));
      if ( v16 != 0 )
      {
        v15 = *(unsigned __int16 *)(v16 + 6 * (unsigned __int8)t_wc + 4);
        t_wc = v15;
      }
      if ( v15 != v13 )
        return (unsigned __int8 *)(v15 < v13 ? 1 : -1);
      v8 += s_res;
      v6 += t_res;
      v10 = (unsigned int)tea;
      if ( (unsigned int)v8 >= v9 )
        break;
      v7 = (int *)cs;
    }
  }
  if ( t_is_prefix != 0 )
    return &v6[-v10];
  else
    return &v6[v9 - v10 - (_DWORD)v8];
}

//------------------------------------------------------------------------------
// Address: 0x00433630
// Name: my_strnncollsp_ucs2
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strnncollsp_ucs2(
        int *cs,
        const LoggingContext_t *te,
        const LoggingContext_t *se,
        const LoggingContext_t *t,
        unsigned int tlen)
{
  int v5; // esi
  const LoggingContext_t *v6; // eax
  unsigned int v7; // ebp
  unsigned int v8; // edx
  const LoggingContext_t *v9; // edi
  const LoggingContext_t *v10; // ebx
  const LoggingContext_t *v11; // ecx
  int m_ChannelID_low; // ecx
  int v13; // ebx
  int v14; // ecx
  int v15; // edx
  int v16; // edx
  int v17; // ecx
  unsigned int minlen; // [esp+14h] [ebp+4h]
  const LoggingContext_t *tea; // [esp+18h] [ebp+8h]
  const LoggingContext_t *sea; // [esp+1Ch] [ebp+Ch]
  unsigned int tlena; // [esp+24h] [ebp+14h]

  v5 = cs[16];
  v6 = te;
  v7 = (unsigned int)se & 0xFFFFFFFE;
  v8 = tlen & 0xFFFFFFFE;
  v9 = t;
  v10 = (const LoggingContext_t *)((char *)te + ((unsigned int)se & 0xFFFFFFFE));
  v11 = (const LoggingContext_t *)((char *)t + (tlen & 0xFFFFFFFE));
  tlena = v8;
  sea = v10;
  tea = v11;
  minlen = v7;
  if ( v7 >= v8 )
    minlen = v8;
  if ( minlen != 0 )
  {
    while ( 1 )
    {
      m_ChannelID_low = LOBYTE(v6->m_ChannelID);
      v13 = *(_DWORD *)(v5 + 4 * m_ChannelID_low) != 0
          ? *(unsigned __int16 *)(*(_DWORD *)(v5 + 4 * m_ChannelID_low) + 6 * BYTE1(v6->m_ChannelID) + 4)
          : (m_ChannelID_low << 8) + BYTE1(v6->m_ChannelID);
      v14 = LOBYTE(v9->m_ChannelID);
      v15 = BYTE1(v9->m_ChannelID);
      v16 = *(_DWORD *)(v5 + 4 * v14) != 0
          ? *(unsigned __int16 *)(*(_DWORD *)(v5 + 4 * v14) + 6 * v15 + 4)
          : (v14 << 8) + v15;
      if ( v13 != v16 )
        return 2 * (v13 > v16) - 1;
      v6 = (const LoggingContext_t *)((char *)v6 + 2);
      v9 = (const LoggingContext_t *)((char *)v9 + 2);
      minlen -= 2;
      if ( minlen == 0 )
      {
        v8 = tlena;
        v10 = sea;
        goto LABEL_13;
      }
    }
  }
  else
  {
LABEL_13:
    if ( v7 == v8 )
      return 0;
    v17 = 1;
    if ( v7 < v8 )
    {
      v6 = v9;
      v17 = -1;
      v10 = tea;
    }
    if ( v6 >= v10 )
    {
      return 0;
    }
    else
    {
      while ( LOBYTE(v6->m_ChannelID) == 0 )
      {
        if ( BYTE1(v6->m_ChannelID) != 32 )
        {
          if ( LOBYTE(v6->m_ChannelID) == 0 && BYTE1(v6->m_ChannelID) < 0x20u )
            return -v17;
          return v17;
        }
        v6 = (const LoggingContext_t *)((char *)v6 + 2);
        if ( v6 >= v10 )
          return 0;
      }
      return v17;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00433740
// Name: my_numchars_ucs2
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_numchars_ucs2(int a1, int a2, int a3)
{
  return (unsigned int)(a3 - a2) >> 1;
}

//------------------------------------------------------------------------------
// Address: 0x00433750
// Name: my_charpos_ucs2
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_charpos_ucs2(int a1, int a2, int a3, unsigned int a4)
{
  if ( a4 <= a3 - a2 )
    return 2 * a4;
  else
    return a3 - a2 + 2;
}

//------------------------------------------------------------------------------
// Address: 0x00433770
// Name: my_well_formed_len_ucs2
// Source: json
//------------------------------------------------------------------------------
unsigned int my_well_formed_len_ucs2(
        LIST_ENTRY32 *cs,
        const char *b,
        tagShutdownType e,
        unsigned int nchars,
        int *error,
        ...)
{
  unsigned int result; // eax

  *error = 0;
  result = (e - (_DWORD)b) & 0xFFFFFFFE;
  if ( result >= 2 * nchars )
    return 2 * nchars;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004337A0
// Name: my_wildcmp_ucs2_bin
// Source: json
//------------------------------------------------------------------------------
void __cdecl my_wildcmp_ucs2_bin(
        LIST_ENTRY32 *a1,
        tagShutdownType a2,
        tagShutdownType a3,
        unsigned int a4,
        tagShutdownType a5,
        int a6,
        int a7,
        int a8)
{
  my_wildcmp_unicode(
    cs: (DNameStatus)a1,
    a2: a1,
    str: a2,
    str_end: a3,
    w_wc: a4,
    wildend: a5,
    escape: a6,
    w_one: a7,
    w_many: a8,
    weights: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004337E0
// Name: my_strnncoll_ucs2_bin
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl my_strnncoll_ucs2_bin(
        LIST_ENTRY32 *cs,
        const LoggingContext_t *te,
        unsigned int s_wc,
        unsigned int t_wc,
        unsigned int tlen,
        char t_is_prefix)
{
  unsigned __int8 *v6; // ebx
  unsigned __int8 *v7; // edi
  unsigned int v8; // esi
  unsigned int v9; // eax
  int v10; // ebp
  int v11; // eax
  const LoggingContext_t *tea; // [esp+18h] [ebp+8h]

  v6 = (unsigned __int8 *)t_wc;
  v7 = (unsigned __int8 *)te;
  v8 = (unsigned int)te + s_wc;
  v9 = t_wc + tlen;
  tea = (const LoggingContext_t *)(t_wc + tlen);
  if ( (unsigned int)v7 < v8 )
  {
    while ( (unsigned int)v6 < v9 )
    {
      v10 = my_ucs2_uni(a1: (int)cs, a2: &s_wc, a3: v7, a4: v8);
      v11 = my_ucs2_uni(a1: (int)cs, a2: &t_wc, a3: v6, a4: (unsigned int)tea);
      if ( v10 <= 0 || v11 <= 0 )
        return (unsigned __int8 *)(*v7 - *v6);
      if ( t_wc != s_wc )
        return (unsigned __int8 *)(t_wc < s_wc ? 1 : -1);
      v7 += v10;
      v6 += v11;
      v9 = (unsigned int)tea;
      if ( (unsigned int)v7 >= v8 )
        break;
    }
  }
  if ( t_is_prefix != 0 )
    return &v6[-v9];
  else
    return &v6[v8 - v9 - (_DWORD)v7];
}

//------------------------------------------------------------------------------
// Address: 0x00433890
// Name: my_strnncollsp_ucs2_bin
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strnncollsp_ucs2_bin(
        LIST_ENTRY32 *cs,
        const LoggingContext_t *te,
        unsigned int minlen,
        const LoggingContext_t *t,
        const LoggingContext_t *se)
{
  const LoggingContext_t *v5; // eax
  const LoggingContext_t *v6; // esi
  unsigned int v7; // edi
  unsigned int v8; // ebx
  const LoggingContext_t *v9; // ecx
  const LoggingContext_t *v10; // edx
  unsigned int v11; // edx
  int v12; // ecx
  int v13; // edx
  int v14; // edx
  const LoggingContext_t *tea; // [esp+18h] [ebp+8h]
  unsigned int minlena; // [esp+1Ch] [ebp+Ch]
  const LoggingContext_t *sea; // [esp+24h] [ebp+14h]

  v5 = te;
  v6 = t;
  v7 = minlen & 0xFFFFFFFE;
  v8 = (unsigned int)se & 0xFFFFFFFE;
  v9 = (const LoggingContext_t *)((char *)te + (minlen & 0xFFFFFFFE));
  v10 = (const LoggingContext_t *)((char *)t + ((unsigned int)se & 0xFFFFFFFE));
  sea = v9;
  tea = v10;
  if ( (minlen & 0xFFFFFFFE) >= v8 )
  {
    v11 = v8;
    minlena = v8;
  }
  else
  {
    v11 = minlen & 0xFFFFFFFE;
    minlena = minlen & 0xFFFFFFFE;
  }
  if ( v11 != 0 )
  {
    while ( 1 )
    {
      v12 = BYTE1(v5->m_ChannelID) + (LOBYTE(v5->m_ChannelID) << 8);
      v13 = BYTE1(v6->m_ChannelID) + (LOBYTE(v6->m_ChannelID) << 8);
      if ( v12 != v13 )
        return 2 * (v12 > v13) - 1;
      v5 = (const LoggingContext_t *)((char *)v5 + 2);
      v6 = (const LoggingContext_t *)((char *)v6 + 2);
      minlena -= 2;
      if ( minlena == 0 )
      {
        v9 = sea;
        goto LABEL_8;
      }
    }
  }
  else
  {
LABEL_8:
    if ( v7 == v8 )
      return 0;
    v14 = 1;
    if ( v7 < v8 )
    {
      v9 = tea;
      v5 = v6;
      v14 = -1;
    }
    if ( v5 >= v9 )
    {
      return 0;
    }
    else
    {
      while ( LOBYTE(v5->m_ChannelID) == 0 )
      {
        if ( BYTE1(v5->m_ChannelID) != 32 )
        {
          if ( LOBYTE(v5->m_ChannelID) == 0 && BYTE1(v5->m_ChannelID) < 0x20u )
            return -v14;
          return v14;
        }
        v5 = (const LoggingContext_t *)((char *)v5 + 2);
        if ( v5 >= v9 )
          return 0;
      }
      return v14;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00433960
// Name: my_hash_sort_ucs2_bin
// Source: json
//------------------------------------------------------------------------------
const LoggingContext_t *__cdecl my_hash_sort_ucs2_bin(
        LIST_ENTRY32 *a1,
        const LoggingContext_t *key,
        unsigned int len,
        unsigned int *nr1,
        unsigned int *nr2)
{
  const LoggingContext_t *v5; // edx
  const LoggingContext_t *v6; // esi
  const LoggingContext_t *result; // eax
  int m_ChannelID_low; // ebp

  v5 = key;
  v6 = (const LoggingContext_t *)((char *)key + len);
  for ( result = (const LoggingContext_t *)((char *)&key->m_ChannelID + 1);
        v6 > result;
        v6 = (const LoggingContext_t *)((char *)v6 - 2) )
  {
    if ( v6[-1].m_Color._color[3] != 32 )
      break;
    if ( v6[-1].m_Color._color[2] != 0 )
      break;
  }
  if ( key < v6 )
  {
    do
    {
      result = (const LoggingContext_t *)*nr1;
      m_ChannelID_low = LOBYTE(v5->m_ChannelID);
      v5 = (const LoggingContext_t *)((char *)v5 + 1);
      *nr1 ^= (*nr1 << 8) + m_ChannelID_low * (*nr2 + (*nr1 & 0x3F));
      *nr2 += 3;
    }
    while ( v5 < v6 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004339C0
// Name: _my_like_range_ucs2
// Source: json
//------------------------------------------------------------------------------
char __cdecl my_like_range_ucs2(
        LIST_ENTRY32 *a1,
        _BYTE *ptr,
        unsigned int ptr_length,
        int escape,
        int w_one,
        int w_many,
        unsigned int res_length,
        char *min_str,
        char *max_str,
        unsigned int *min_length,
        unsigned int *max_length)
{
  char *v11; // ecx
  char *v12; // esi
  char *v13; // ebx
  unsigned int Flink; // eax
  unsigned __int8 *v15; // edi
  char *v16; // edx
  char *v17; // ebp
  int v18; // eax
  unsigned __int8 *v19; // ecx
  unsigned __int8 *v20; // edx
  int v21; // eax
  char v22; // al
  char *v23; // edx
  char *v24; // ecx
  char v25; // al
  unsigned __int8 v26; // al
  unsigned int v27; // eax
  char *v28; // esi
  _BYTE *v29; // ecx
  _BYTE *v30; // edx
  char *v32; // esi
  char *i; // eax
  char *v34; // eax
  char *j; // eax
  _BYTE *v36; // edx
  _BYTE *v37; // ecx
  unsigned int charlen; // [esp+10h] [ebp-14h]
  tagShutdownType contraction_flags; // [esp+14h] [ebp-10h]
  char *min_end; // [esp+18h] [ebp-Ch]
  tagShutdownType end; // [esp+1Ch] [ebp-8h]
  unsigned __int8 *ptr_lengtha; // [esp+30h] [ebp+Ch]
  char *min_stra; // [esp+44h] [ebp+20h]

  v11 = min_str;
  v12 = ptr;
  min_end = &min_str[res_length];
  v13 = min_str;
  end = (tagShutdownType)&ptr[ptr_length];
  charlen = res_length / a1[11].Flink;
  Flink = a1[6].Flink;
  if ( Flink != 0 )
    contraction_flags = Flink + 4096;
  else
    contraction_flags = IdleShutdown;
  v15 = ptr + 1;
  if ( ptr + 1 < &ptr[ptr_length] )
  {
    ptr_lengtha = ptr + 3;
    v16 = max_str;
    min_stra = min_str + 2;
    v17 = v11 + 1;
    while ( 1 )
    {
      if ( v17 >= min_end || charlen == 0 )
        goto LABEL_38;
      if ( *v12 != 0 )
        goto LABEL_15;
      v18 = (char)*v15;
      if ( v18 == escape && (unsigned int)v15 < end )
        break;
      if ( v18 != w_one )
      {
        if ( v18 == w_many )
          goto fill_max_and_min;
LABEL_15:
        if ( contraction_flags != IdleShutdown
          && (unsigned int)ptr_lengtha < end
          && *v12 == 0
          && *(_BYTE *)(*v15 + contraction_flags) != 0 )
        {
          if ( v12[2] == 0 )
          {
            v21 = (char)*ptr_lengtha;
            if ( v21 == w_one || v21 == w_many )
            {
fill_max_and_min:
              if ( (a1[1].Blink & 0x10) != 0 )
                v27 = v11 - min_str;
              else
                v27 = res_length;
              *min_length = v27;
              *max_length = res_length;
              v28 = v11 + 1;
              do
              {
                *v11 = 0;
                v29 = v11 + 1;
                *v29 = 0;
                *v16 = HIBYTE(a1[11].Blink);
                v30 = v16 + 1;
                v28 += 2;
                *v30 = BYTE2(a1[11].Blink);
                v11 = v29 + 1;
                v16 = v30 + 1;
              }
              while ( v28 < min_end );
              return 0;
            }
          }
          if ( v12[2] == 0
            && *(_BYTE *)(*ptr_lengtha + contraction_flags) != 0
            && *(_WORD *)(a1[6].Flink + 2 * ((char)*ptr_lengtha + (((char)*v15 - 65) << 6))) != 0 )
          {
            if ( charlen == 1 || min_stra >= min_end )
              goto fill_max_and_min;
            *v16 = 0;
            *v11 = 0;
            v22 = v12[1];
            v23 = v16 + 1;
            v24 = v11 + 1;
            *v23 = v22;
            *v24 = v22;
            ptr_lengtha += 2;
            v11 = v24 + 1;
            v17 += 2;
            v16 = v23 + 1;
            v12 += 2;
            v15 += 2;
            --charlen;
            min_stra += 2;
          }
        }
LABEL_28:
        v25 = *v12;
        *v16 = *v12;
        *v11 = v25;
        v26 = *v15;
        v20 = (unsigned __int8 *)(v16 + 1);
        v19 = (unsigned __int8 *)(v11 + 1);
        *v20 = *v15;
        *v19 = v26;
        min_stra += 2;
        goto LABEL_29;
      }
      min_stra += 2;
      *v11 = BYTE1(a1[11].Blink);
      v19 = (unsigned __int8 *)(v11 + 1);
      *v19 = a1[11].Blink;
      *v16 = HIBYTE(a1[11].Blink);
      v20 = (unsigned __int8 *)(v16 + 1);
      *v20 = BYTE2(a1[11].Blink);
LABEL_29:
      ptr_lengtha += 2;
      --charlen;
      v13 = min_str;
      v15 += 2;
      v11 = (char *)(v19 + 1);
      v17 += 2;
      v16 = (char *)(v20 + 1);
      v12 += 2;
      if ( (unsigned int)v15 >= end )
        goto LABEL_38;
    }
    ptr_lengtha += 2;
    v12 += 2;
    v15 += 2;
    goto LABEL_28;
  }
  v16 = max_str;
LABEL_38:
  v32 = v11 - 1;
  for ( i = v11; v32 > v13; *i = 0 )
  {
    if ( *(i - 1) != 0 )
      break;
    if ( *(i - 2) != 0 )
      break;
    v34 = i - 1;
    *v34 = 32;
    i = v34 - 1;
    v32 -= 2;
  }
  *max_length = v11 - v13;
  *min_length = v11 - v13;
  for ( j = v11 + 1; j < min_end; v16 = v36 + 1 )
  {
    *v16 = 0;
    *v11 = 0;
    v36 = v16 + 1;
    v37 = v11 + 1;
    *v36 = 32;
    *v37 = 32;
    j += 2;
    v11 = v37 + 1;
  }
  return 0;
}
