// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/dtoa.c
// Functions: 24
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004118A0
// Name: Balloc
// Source: json
//------------------------------------------------------------------------------
void __usercall Balloc(int k@<edi>, long double *alloc@<edx>)
{
  _DWORD *v2; // eax
  _DWORD *v3; // eax
  unsigned int v4; // ecx

  if ( k <= 15 && (v2 = *((_DWORD **)alloc + k + 3)) != nullptr )
  {
    *((_DWORD *)alloc + k + 3) = *v2;
    v2[4] = 0;
    v2[3] = 0;
    *v2 = v2 + 5;
  }
  else
  {
    v3 = *((_DWORD **)alloc + 1);
    v4 = (4 * (1 << k) + 23) & 0xFFFFFFFC;
    if ( (unsigned int)v3 + v4 > *((_DWORD *)alloc + 2) )
      v3 = operator new(nSize: v4);
    else
      *((_DWORD *)alloc + 1) = (char *)v3 + v4;
    v3[2] = 1 << k;
    v3[1] = k;
    v3[4] = 0;
    v3[3] = 0;
    *v3 = v3 + 5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411920
// Name: Bfree
// Source: json
//------------------------------------------------------------------------------
void __usercall Bfree(_DWORD *a1@<eax>, _DWORD *a2@<edx>)
{
  int v2; // ecx

  if ( (unsigned int)a1 < *a2 || (unsigned int)a1 >= a2[2] )
  {
    free(pMem: a1);
  }
  else
  {
    v2 = a1[1];
    if ( v2 <= 15 )
    {
      *a1 = a2[v2 + 3];
      a2[v2 + 3] = a1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411950
// Name: dtoa_alloc
// Source: json
//------------------------------------------------------------------------------
char *__usercall dtoa_alloc@<eax>(int a1@<edx>, unsigned int a2@<esi>)
{
  char *result; // eax
  char *v3; // ecx

  result = *(char **)(a1 + 4);
  v3 = &result[(a2 + 3) & 0xFFFFFFFC];
  if ( (unsigned int)v3 > *(_DWORD *)(a1 + 8) )
    return (char *)operator new(nSize: a2);
  *(_DWORD *)(a1 + 4) = v3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00411970
// Name: dtoa_free
// Source: json
//------------------------------------------------------------------------------
void __usercall dtoa_free(void *a1@<eax>, int a2@<edx>, unsigned int a3@<ecx>)
{
  if ( (unsigned int)a1 < a3 || (unsigned int)a1 >= a2 + a3 )
    free(pMem: a1);
}

//------------------------------------------------------------------------------
// Address: 0x00411990
// Name: multadd
// Source: json
//------------------------------------------------------------------------------
_DWORD *__cdecl multadd(int a1, int m, int a, long double *alloc)
{
  _DWORD *v4; // esi
  int v5; // ebx
  int v6; // edi
  int v7; // ebp
  unsigned __int64 v8; // rax
  _DWORD *v9; // esi
  int v10; // eax
  _DWORD *v11; // edi
  int wds; // [esp+10h] [ebp-Ch]

  v4 = *(_DWORD **)a1;
  v5 = a;
  v6 = a >> 31;
  wds = *(_DWORD *)(a1 + 16);
  v7 = 0;
  do
  {
    v8 = __PAIR64__(v6, v5) + (unsigned int)*v4 * (__int64)m;
    *v4 = v8;
    ++v7;
    v6 = 0;
    ++v4;
    v5 = HIDWORD(v8);
  }
  while ( v7 < wds );
  if ( HIDWORD(v8) == 0 )
    return (_DWORD *)a1;
  v9 = (_DWORD *)a1;
  if ( wds >= *(_DWORD *)(a1 + 8) )
  {
    Balloc(k: *(_DWORD *)(a1 + 4) + 1, alloc);
    v11 = (_DWORD *)v10;
    memcpy(dst: (unsigned __int8 *)(v10 + 12), src: (unsigned __int8 *)(a1 + 12), count: 4 * *(_DWORD *)(a1 + 16) + 8);
    Bfree((_DWORD *)a1, a2: alloc);
    v9 = v11;
  }
  *(_DWORD *)(*v9 + 4 * wds) = v5;
  v9[4] = wds + 1;
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x00411A60
// Name: s2b
// Source: json
//------------------------------------------------------------------------------
void __usercall s2b(int a1@<eax>, long double *a2@<ebx>, int nd0, int nd, unsigned int y9)
{
  int v6; // edi
  int v7; // eax
  int i; // ecx
  _DWORD *v9; // eax
  int v10; // edi
  char *v11; // esi
  char *v12; // esi
  int v13; // edi

  v6 = 0;
  v7 = (nd + 8) / 9;
  for ( i = 1; v7 > i; ++v6 )
    i *= 2;
  Balloc(k: v6, alloc: a2);
  v10 = 9;
  *(_DWORD *)*v9 = y9;
  v9[4] = 1;
  if ( nd0 <= 9 )
  {
    v12 = (char *)(a1 + 10);
  }
  else
  {
    v11 = (char *)(a1 + 9);
    do
    {
      v9 = multadd(a1: (int)v9, m: 10, a: *v11 - 48, alloc: a2);
      ++v10;
      ++v11;
    }
    while ( v10 < nd0 );
    v12 = v11 + 1;
  }
  if ( v10 < nd )
  {
    v13 = nd - v10;
    do
    {
      v9 = multadd(a1: (int)v9, m: 10, a: *v12++ - 48, alloc: a2);
      --v13;
    }
    while ( v13 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411B00
// Name: hi0bits
// Source: json
//------------------------------------------------------------------------------
int __fastcall hi0bits(int a1)
{
  int result; // eax

  result = 0;
  if ( (a1 & 0xFFFF0000) == 0 )
  {
    result = 16;
    a1 <<= 16;
  }
  if ( (a1 & 0xFF000000) == 0 )
  {
    result += 8;
    a1 <<= 8;
  }
  if ( (a1 & 0xF0000000) == 0 )
  {
    result += 4;
    a1 *= 16;
  }
  if ( (a1 & 0xC0000000) == 0 )
  {
    result += 2;
    a1 *= 4;
  }
  if ( a1 >= 0 )
  {
    ++result;
    if ( (a1 & 0x40000000) == 0 )
      return 32;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00411B50
// Name: lo0bits
// Source: json
//------------------------------------------------------------------------------
int __fastcall lo0bits(int a1, unsigned int *a2)
{
  unsigned int v2; // ecx
  int result; // eax

  v2 = *a2;
  if ( (*a2 & 7) != 0 )
  {
    if ( (v2 & 1) != 0 )
      return 0;
    if ( (v2 & 2) != 0 )
    {
      v2 >>= 1;
      result = 1;
LABEL_6:
      *a2 = v2;
      return result;
    }
    *a2 = v2 >> 2;
    return 2;
  }
  else
  {
    result = 0;
    if ( (_WORD)v2 == 0 )
    {
      result = 16;
      v2 >>= 16;
    }
    if ( (_BYTE)v2 == 0 )
    {
      result += 8;
      v2 >>= 8;
    }
    if ( (v2 & 0xF) == 0 )
    {
      result += 4;
      v2 >>= 4;
    }
    if ( (v2 & 3) == 0 )
    {
      result += 2;
      v2 >>= 2;
    }
    if ( (v2 & 1) != 0 )
      goto LABEL_6;
    ++result;
    v2 >>= 1;
    if ( v2 != 0 )
      goto LABEL_6;
    return 32;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411BC0
// Name: i2b
// Source: json
//------------------------------------------------------------------------------
void __usercall i2b(long double *alloc@<edx>, _LDOUBLE *i)
{
  int v2; // eax

  Balloc(k: 1, alloc);
  **(_DWORD **)v2 = i;
  *(_DWORD *)(v2 + 16) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00411BE0
// Name: mult
// Source: json
//------------------------------------------------------------------------------
int *__usercall mult@<eax>(unsigned int **a1@<eax>, long double *a2@<edx>, unsigned int **wa)
{
  int v3; // ebp
  unsigned int **v4; // esi
  int v5; // edi
  int v6; // ebx
  void **v7; // eax
  int *v8; // edx
  unsigned int *v9; // edi
  char *v10; // esi
  unsigned int *v11; // eax
  unsigned int v12; // ebp
  unsigned int v13; // ecx
  unsigned int v14; // ebx
  int v15; // edi
  unsigned __int64 v16; // rax
  _DWORD *i; // eax
  unsigned int y; // [esp+10h] [ebp-1Ch]
  unsigned int ya; // [esp+10h] [ebp-1Ch]
  unsigned int *xae; // [esp+14h] [ebp-18h]
  void **v22; // [esp+18h] [ebp-14h]
  int wc; // [esp+1Ch] [ebp-10h]
  unsigned int *xa; // [esp+20h] [ebp-Ch]
  unsigned int *xb; // [esp+24h] [ebp-8h]
  unsigned int *xbe; // [esp+28h] [ebp-4h]
  int waa; // [esp+30h] [ebp+4h]
  int wab; // [esp+30h] [ebp+4h]

  v3 = (int)wa;
  v4 = a1;
  if ( (int)a1[4] < (int)wa[4] )
  {
    v4 = wa;
    v3 = (int)a1;
  }
  v5 = (int)v4[1];
  y = *(_DWORD *)(v3 + 16);
  v6 = (int)v4[4] + y;
  waa = (int)v4[4];
  wc = v6;
  if ( v6 > (int)v4[2] )
    ++v5;
  Balloc(k: v5, alloc: a2);
  v8 = (int *)v7;
  v22 = v7;
  if ( *v7 < (char *)*v7 + 4 * v6 )
    memset(*v7, 0, 4 * (((unsigned int)(4 * v6 - 1) >> 2) + 1));
  v9 = *v4;
  v10 = (char *)*v7;
  xae = &v9[waa];
  v11 = *(unsigned int **)v3;
  v12 = *(_DWORD *)v3 + 4 * y;
  xa = v9;
  xbe = (unsigned int *)v12;
  for ( wab = *v8; (unsigned int)v11 < v12; wab = (int)v10 )
  {
    v13 = *v11++;
    ya = v13;
    xb = v11;
    if ( v13 != 0 )
    {
      v14 = 0;
      v15 = (char *)v9 - v10;
      while ( 1 )
      {
        v16 = v14 + *(unsigned int *)v10 + *(unsigned int *)&v10[v15] * (unsigned __int64)v13;
        *(_DWORD *)v10 = v16;
        v10 += 4;
        v14 = HIDWORD(v16);
        if ( &v10[v15] >= (char *)xae )
          break;
        v13 = ya;
      }
      v8 = (int *)v22;
      v9 = xa;
      v11 = xb;
      v12 = (unsigned int)xbe;
      *(_DWORD *)v10 = v14;
      v6 = wc;
      v10 = (char *)wab;
    }
    v10 += 4;
  }
  for ( i = (_DWORD *)(4 * v6 + *v8); v6 > 0; --v6 )
  {
    if ( *--i != 0 )
      break;
  }
  v8[4] = v6;
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x00411D00
// Name: pow5mult
// Source: json
//------------------------------------------------------------------------------
unsigned int **__usercall pow5mult@<eax>(long double *a1@<edi>, int a2, int a3)
{
  unsigned int **v3; // ebp
  int *v5; // esi
  int *v6; // ebx
  int *v7; // ebx
  int v9; // [esp+10h] [ebp+8h]

  v3 = (unsigned int **)a2;
  if ( (a3 & 3) != 0 )
    v3 = (unsigned int **)multadd(a1: a2, m: dword_4909C8[a3 & 3], a: 0, alloc: a1);
  v9 = a3 >> 2;
  if ( a3 >> 2 != 0 )
  {
    v5 = (int *)&p5_a;
    while ( 1 )
    {
      if ( (v9 & 1) != 0 )
      {
        v6 = mult(a1: v3, a2: a1, wa: (unsigned int **)v5);
        Bfree(a1: v3, a2: a1);
        v3 = (unsigned int **)v6;
      }
      v9 >>= 1;
      if ( v9 == 0 )
        break;
      if ( v5 >= (int *)&off_490A50 )
      {
        if ( v5 == (int *)&off_490A50 )
        {
          v5 = mult(a1: (unsigned int **)v5, a2: a1, wa: (unsigned int **)v5);
        }
        else
        {
          v7 = mult(a1: (unsigned int **)v5, a2: a1, wa: (unsigned int **)v5);
          Bfree(a1: v5, a2: a1);
          v5 = v7;
        }
      }
      else
      {
        v5 += 5;
      }
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00411DA0
// Name: lshift
// Source: json
//------------------------------------------------------------------------------
_DWORD **__cdecl lshift(_DWORD *a1, int a2, long double *alloc)
{
  _DWORD *v3; // ebp
  int v4; // esi
  int v5; // ecx
  int v6; // eax
  int v7; // edi
  _DWORD **v8; // eax
  _DWORD *v9; // edx
  bool v10; // zf
  _DWORD *v11; // eax
  unsigned int v12; // ebx
  int v13; // esi
  int v14; // ebp
  int i; // [esp+10h] [ebp-8h]
  _DWORD **v17; // [esp+14h] [ebp-4h]
  char v18; // [esp+20h] [ebp+8h]

  v3 = a1;
  v4 = a2 >> 5;
  v5 = (a2 >> 5) + a1[4] + 1;
  v6 = a1[2];
  v7 = a1[1];
  for ( i = v5; v5 > v6; ++v7 )
    v6 *= 2;
  Balloc(k: v7, alloc);
  v9 = *v8;
  v17 = v8;
  if ( v4 > 0 )
  {
    memset(v9, 0, 4 * v4);
    v9 += v4;
  }
  v10 = (a2 & 0x1F) == 0;
  v18 = a2 & 0x1F;
  v11 = (_DWORD *)*a1;
  v12 = *a1 + 4 * a1[4];
  if ( v10 )
  {
    do
      *v9++ = *v11++;
    while ( (unsigned int)v11 < v12 );
  }
  else
  {
    v13 = 0;
    do
    {
      v14 = *v11++ << v18;
      *v9++ = v13 | v14;
      v13 = *(v11 - 1) >> (32 - v18);
    }
    while ( (unsigned int)v11 < v12 );
    v3 = a1;
    *v9 = v13;
    if ( v13 != 0 )
      ++i;
  }
  v17[4] = (_DWORD *)(i - 1);
  Bfree(a1: v3, a2: alloc);
  return v17;
}

//------------------------------------------------------------------------------
// Address: 0x00411E70
// Name: cmp
// Source: json
//------------------------------------------------------------------------------
void __usercall cmp(unsigned int *a@<edx>, char *b@<eax>)
{
  int v3; // ecx
  unsigned int v4; // edx
  _DWORD *v5; // eax
  _DWORD *v6; // ecx
  int v7; // esi

  v3 = *((_DWORD *)b + 4);
  if ( a[4] == v3 )
  {
    v4 = *a;
    v5 = (_DWORD *)(v4 + 4 * v3 - 4);
    v6 = (_DWORD *)(*(_DWORD *)b + 4 * v3 - 4);
    if ( *v5 == *v6 )
    {
      do
      {
        if ( (unsigned int)v5 <= v4 )
          break;
        v7 = *--v5;
        --v6;
      }
      while ( v7 == *v6 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411EC0
// Name: diff
// Source: json
//------------------------------------------------------------------------------
void __usercall diff(char *b@<ecx>, long double *a2@<eax>, unsigned int *a3@<edx>)
{
  char *v3; // ebx
  char *v5; // esi
  int v6; // eax
  int v7; // eax
  _DWORD *v8; // ecx
  char *v9; // eax
  int v10; // ebp
  int v11; // eax
  unsigned int *v12; // ecx
  unsigned int *v13; // edx
  unsigned int *v14; // ebp
  _DWORD *v15; // esi
  unsigned int v16; // ebx
  unsigned __int64 v17; // kr00_8
  unsigned __int64 v18; // kr08_8
  _DWORD *i; // esi
  unsigned int *xb; // [esp+Ch] [ebp-14h]
  unsigned int *xbe; // [esp+14h] [ebp-Ch]
  unsigned int *xae; // [esp+18h] [ebp-8h]

  v3 = b;
  v5 = (char *)a3;
  cmp(a: a3, b);
  if ( v6 != 0 )
  {
    if ( v6 >= 0 )
    {
      v10 = 0;
    }
    else
    {
      v9 = v5;
      v5 = v3;
      v3 = v9;
      v10 = 1;
    }
    Balloc(k: *((_DWORD *)v5 + 1), alloc: a2);
    *(_DWORD *)(v11 + 12) = v10;
    v12 = *((unsigned int **)v5 + 4);
    v13 = *(unsigned int **)v5;
    v14 = *(unsigned int **)v3;
    v15 = *(_DWORD **)v11;
    xae = &v13[(_DWORD)v12];
    xb = *(unsigned int **)v3;
    xbe = (unsigned int *)(*(_DWORD *)v3 + 4 * *((_DWORD *)v3 + 4));
    v16 = 0;
    do
    {
      v17 = *v13 - (unsigned __int64)*v14;
      v14 = xb + 1;
      *v15 = v17 - v16;
      ++v13;
      ++v15;
      xb = v14;
      v16 = (BYTE4(v17) - ((unsigned int)v17 < v16)) & 1;
    }
    while ( v14 < xbe );
    for ( ; v13 < xae; v16 = BYTE4(v18) & 1 )
    {
      v18 = *v13++ - (unsigned __int64)v16;
      *v15++ = v18;
    }
    for ( i = v15 - 1; *i == 0; v12 = (unsigned int *)((char *)v12 - 1) )
      --i;
    *(_DWORD *)(v11 + 16) = v12;
  }
  else
  {
    Balloc(k: 0, alloc: a2);
    v8 = *(_DWORD **)v7;
    *(_DWORD *)(v7 + 16) = 1;
    *v8 = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411FC0
// Name: ulp
// Source: json
//------------------------------------------------------------------------------
double __cdecl ulp(long double a)
{
  double aa; // [esp+4h] [ebp+4h]

  HIDWORD(aa) = (HIDWORD(a) & 0x7FF00000) - 54525952;
  LODWORD(aa) = 0;
  return aa;
}

//------------------------------------------------------------------------------
// Address: 0x00411FE0
// Name: b2d
// Source: json
//------------------------------------------------------------------------------
double __usercall b2d@<st0>(long double *a@<eax>, char *e)
{
  unsigned int v2; // edi
  int *v3; // esi
  int v4; // eax
  unsigned int v5; // edx
  unsigned int v7; // ecx
  int v8; // eax
  unsigned int v9; // esi
  double da; // [esp+10h] [ebp-8h]
  double db; // [esp+10h] [ebp-8h]

  v2 = *(_DWORD *)a;
  v3 = (int *)(*(_DWORD *)a + 4 * *((_DWORD *)a + 4) - 4);
  v4 = hi0bits(a1: *v3);
  *(_DWORD *)e = 32 - v4;
  if ( v4 >= 11 )
  {
    if ( (unsigned int)v3 <= v2 )
      v7 = 0;
    else
      v7 = *--v3;
    v8 = v4 - 11;
    if ( v8 != 0 )
    {
      if ( (unsigned int)v3 <= v2 )
        v9 = 0;
      else
        v9 = *(v3 - 1);
      LODWORD(db) = (v7 << v8) | (v9 >> (32 - v8));
      HIDWORD(db) = (v5 << v8) | (v7 >> (32 - v8)) | 0x3FF00000;
      return db;
    }
    else
    {
      return COERCE_DOUBLE(__PAIR64__(v5 | 0x3FF00000, v7));
    }
  }
  else
  {
    if ( (unsigned int)v3 <= v2 )
      LODWORD(da) = v5 << (v4 + 21);
    else
      LODWORD(da) = ((unsigned int)*(v3 - 1) >> (11 - v4)) | (v5 << (v4 + 21));
    HIDWORD(da) = (v5 >> (11 - v4)) | 0x3FF00000;
    return da;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004120E0
// Name: d2b
// Source: json
//------------------------------------------------------------------------------
unsigned int **__usercall d2b@<eax>(long double *a1@<edx>, unsigned int y, int a3, int *e, int *bits)
{
  int v5; // ecx
  unsigned int **v6; // eax
  unsigned int **v7; // edi
  unsigned int *v8; // ebx
  unsigned int v9; // esi
  unsigned int v10; // ebp
  int v11; // eax
  unsigned int v12; // edx
  BOOL v13; // edx
  int v14; // edx
  int v15; // eax
  int v17; // eax
  int v18; // edx
  unsigned int z; // [esp+10h] [ebp-4h] BYREF

  Balloc(k: 1, alloc: a1);
  v7 = v6;
  v8 = *v6;
  v9 = a3 & 0xFFFFF;
  v10 = (a3 & 0x7FFFFFFFu) >> 20;
  z = a3 & 0xFFFFF;
  if ( v10 != 0 )
  {
    v9 |= 0x100000u;
    z = v9;
  }
  if ( y != 0 )
  {
    v11 = lo0bits(a1: v5, a2: &y);
    if ( v11 != 0 )
    {
      v12 = v9 << (32 - v11);
      v9 >>= v11;
      *v8 = y | v12;
      v13 = v9 != 0;
    }
    else
    {
      v13 = v9 != 0;
      *v8 = y;
    }
    v8[1] = v9;
    v14 = v13 + 1;
  }
  else
  {
    v15 = lo0bits(a1: v5, a2: &z);
    *v8 = z;
    v14 = 1;
    v11 = v15 + 32;
  }
  v7[4] = (unsigned int *)v14;
  if ( v10 != 0 )
  {
    *e = v11 + v10 - 1075;
    *bits = 53 - v11;
  }
  else
  {
    *e = v11 - 1074;
    v17 = hi0bits(a1: v8[v14 - 1]);
    *bits = 32 * v18 - v17;
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x004121D0
// Name: ratio
// Source: json
//------------------------------------------------------------------------------
double __usercall ratio@<st0>(unsigned int a@<edi>, unsigned int b@<esi>)
{
  int v2; // eax
  int kb; // [esp+0h] [ebp-18h] BYREF
  int ka; // [esp+4h] [ebp-14h] BYREF
  double daa; // [esp+8h] [ebp-10h]
  double db; // [esp+10h] [ebp-8h]

  daa = b2d((long double *)a, e: (char *)&ka);
  db = b2d(a: (long double *)b, e: (char *)&kb);
  v2 = ka + 32 * (*(_DWORD *)(a + 16) - *(_DWORD *)(b + 16)) - kb;
  if ( v2 <= 0 )
    HIDWORD(db) += -1048576 * v2;
  else
    HIDWORD(daa) += v2 << 20;
  return daa / db;
}

//------------------------------------------------------------------------------
// Address: 0x00412240
// Name: my_strtod_int
// Source: json
//------------------------------------------------------------------------------
double __usercall my_strtod_int@<st0>(
        INTRNCVT_STATUS a1@<eax>,
        tagShutdownType s00,
        unsigned int *a3,
        int *error,
        unsigned int buf_size)
{
  unsigned int v5; // edi
  double v6; // st6
  _BYTE *v7; // ecx
  double result; // st7
  int v9; // edx
  int v10; // ebx
  int v11; // eax
  int v12; // edx
  int v13; // esi
  int v14; // eax
  int v15; // edx
  int v16; // eax
  int v17; // edx
  int v18; // esi
  int v19; // edx
  _BYTE *v20; // esi
  int v21; // eax
  int v22; // edx
  int v23; // esi
  int v24; // edx
  int v25; // eax
  double v26; // st7
  int v27; // eax
  int v28; // eax
  int v29; // ecx
  int v30; // eax
  int v31; // eax
  double *v32; // ecx
  int v33; // ecx
  unsigned __int8 *v34; // eax
  unsigned __int8 *v35; // ebx
  int v36; // eax
  int v37; // eax
  int v38; // ecx
  int v39; // ebx
  int v40; // eax
  int v41; // ebx
  int v42; // esi
  int v43; // eax
  int v44; // edi
  unsigned int **v45; // edi
  char *v46; // edi
  unsigned int *v47; // eax
  unsigned int *v48; // ebx
  int v49; // esi
  int v50; // eax
  double v51; // st7
  double v52; // st7
  double v53; // st6
  unsigned int v54; // ecx
  double v55; // st5
  int v56; // ecx
  int v57; // esi
  unsigned int v58; // eax
  double v59; // st7
  int v60; // esi
  int v61; // eax
  int v62; // eax
  double v63; // st6
  bool v64; // zf
  double rv; // [esp+38h] [ebp-98h]
  tagShutdownType s; // [esp+40h] [ebp-90h]
  int scale; // [esp+44h] [ebp-8Ch]
  int scalea; // [esp+44h] [ebp-8Ch]
  int y; // [esp+48h] [ebp-88h]
  int nz; // [esp+4Ch] [ebp-84h]
  int nza; // [esp+4Ch] [ebp-84h]
  int dsign; // [esp+50h] [ebp-80h]
  int dsigna; // [esp+50h] [ebp-80h]
  int dsignb; // [esp+50h] [ebp-80h]
  unsigned int **nd; // [esp+54h] [ebp-7Ch]
  unsigned int **nd0; // [esp+58h] [ebp-78h]
  int nf; // [esp+5Ch] [ebp-74h]
  unsigned __int8 *nfa; // [esp+5Ch] [ebp-74h]
  unsigned int *aadj1; // [esp+60h] [ebp-70h]
  double aadj1a; // [esp+60h] [ebp-70h]
  int e; // [esp+68h] [ebp-68h]
  int ea; // [esp+68h] [ebp-68h]
  int esign; // [esp+6Ch] [ebp-64h] BYREF
  int bbe; // [esp+70h] [ebp-60h] BYREF
  int sign; // [esp+74h] [ebp-5Ch]
  double rv0; // [esp+78h] [ebp-58h]
  INTRNCVT_STATUS alloc; // [esp+80h] [ebp-50h] BYREF
  INTRNCVT_STATUS v88; // [esp+84h] [ebp-4Ch]
  unsigned __int32 v89; // [esp+88h] [ebp-48h]
  unsigned __int8 dst[64]; // [esp+8Ch] [ebp-44h] BYREF

  v5 = *a3;
  *error = 0;
  v88 = a1;
  alloc = a1;
  v89 = buf_size + a1;
  memset(dst, value: 0, count: sizeof(dst));
  v6 = 0.0;
  nz = 0;
  dsign = 0;
  sign = 0;
  v7 = (_BYTE *)s00;
  if ( s00 >= v5 )
    goto LABEL_4;
  while ( 2 )
  {
    switch ( *v7 )
    {
      case 9:
      case 0xA:
      case 0xB:
      case 0xC:
      case 0xD:
      case 0x20:
        if ( (unsigned int)++v7 >= v5 )
          goto LABEL_4;
        continue;
      case 0x2B:
        goto $LN153;
      case 0x2D:
        sign = 1;
$LN153:
        ++v7;
        break;
      default:
        goto break2;
    }
    break;
  }
break2:
  if ( (unsigned int)v7 >= v5 )
    goto LABEL_4;
  if ( *v7 == 48 )
  {
    dsign = 1;
    while ( (unsigned int)++v7 < v5 )
    {
      if ( *v7 != 48 )
        goto LABEL_13;
    }
LABEL_238:
    result = v6;
    goto ret;
  }
LABEL_13:
  v9 = 0;
  bbe = (int)v7;
  y = 0;
  nf = 0;
  v10 = 0;
  do
  {
    v11 = (char)*v7;
    if ( (unsigned int)(v11 - 48) > 9 )
      break;
    if ( v10 >= 9 )
    {
      if ( v10 < 16 )
        v9 = v11 + 10 * v9 - 48;
    }
    else
    {
      y = v11 + 10 * y - 48;
    }
    ++v7;
    ++v10;
  }
  while ( (unsigned int)v7 < v5 );
  scale = v9;
  nd = (unsigned int **)v10;
  s = (tagShutdownType)v7;
  nd0 = (unsigned int **)v10;
  if ( (unsigned int)v7 < v5 - 1 && v11 == 46 )
  {
    v11 = (char)*++v7;
    s = (tagShutdownType)v7;
    if ( v10 != 0 )
    {
      v15 = 0;
      goto LABEL_54;
    }
    if ( (unsigned int)v7 < v5 )
    {
      v12 = 0;
      while ( v11 == 48 )
      {
        v11 = (char)*++v7;
        ++v12;
        if ( (unsigned int)v7 >= v5 )
        {
          s = (tagShutdownType)v7;
          nz = v12;
          goto dig_done;
        }
      }
      s = (tagShutdownType)v7;
      nz = v12;
      if ( (unsigned int)v7 < v5 && (unsigned int)(v11 - 49) <= 8 )
      {
        nf = v12;
        bbe = (int)v7;
        v15 = 0;
        do
        {
          ++v15;
          v16 = v11 - 48;
          nz = v15;
          if ( v16 != 0 )
          {
            nf += v15;
            if ( v15 > 1 )
            {
              v17 = v15 - 1;
              do
              {
                v18 = v10++;
                if ( v18 >= 9 )
                {
                  if ( v10 <= 16 )
                    scale *= 10;
                }
                else
                {
                  y *= 10;
                }
                --v17;
              }
              while ( v17 != 0 );
            }
            v19 = v10++;
            nd = (unsigned int **)v10;
            if ( v19 >= 9 )
            {
              if ( v10 <= 16 )
                scale = v16 + 10 * scale;
            }
            else
            {
              y = v16 + 10 * y;
            }
            nz = 0;
            v15 = 0;
          }
          v11 = (char)*++v7;
          s = (tagShutdownType)v7;
LABEL_54:
          ;
        }
        while ( (unsigned int)v7 < v5 && (unsigned int)(v11 - 48) <= 9 );
      }
    }
  }
dig_done:
  v13 = 0;
  if ( (unsigned int)v7 < v5 && (v11 == 101 || v11 == 69) )
  {
    if ( v10 != 0 || nz != 0 || dsign != 0 )
    {
      s00 = (tagShutdownType)v7++;
      esign = 0;
      if ( (unsigned int)v7 >= v5 )
        goto LABEL_81;
      v14 = (char)*v7;
      if ( v14 != 43 )
      {
        if ( *v7 != 45 )
        {
LABEL_39:
          if ( (unsigned int)v7 < v5 && (unsigned int)(v14 - 48) <= 9 )
          {
            while ( v14 == 48 )
            {
              v14 = (char)*++v7;
              if ( (unsigned int)v7 >= v5 )
              {
                s = (tagShutdownType)v7;
LABEL_44:
                e = 0;
                goto LABEL_45;
              }
            }
            s = (tagShutdownType)v7;
            if ( (unsigned int)v7 >= v5 || (unsigned int)(v14 - 49) > 8 )
              goto LABEL_44;
            v20 = v7++;
            v21 = v14 - 48;
            s = (tagShutdownType)v7;
            if ( (unsigned int)v7 < v5 )
            {
              do
              {
                v22 = (char)*v7;
                if ( (unsigned int)(v22 - 48) > 9 )
                  break;
                ++v7;
                v21 = v22 + 10 * v21 - 48;
              }
              while ( (unsigned int)v7 < v5 );
              v10 = (int)nd;
              s = (tagShutdownType)v7;
            }
            if ( v7 - v20 > 8 || (e = v21, v21 > 19999) )
              e = 19999;
            if ( esign != 0 )
              e = -e;
LABEL_45:
            v13 = e;
            goto LABEL_46;
          }
LABEL_81:
          v7 = (_BYTE *)s00;
          s = s00;
          goto LABEL_46;
        }
        esign = 1;
      }
      v14 = (char)*++v7;
      goto LABEL_39;
    }
LABEL_4:
    result = 0.0;
ret0:
    sign = 0;
    v7 = (_BYTE *)s00;
    goto ret;
  }
LABEL_46:
  if ( v10 == 0 )
  {
    result = 0.0;
    if ( nz != 0 || dsign != 0 )
      goto ret;
    goto ret0;
  }
  v23 = v13 - nf;
  ea = v23;
  if ( nd0 == nullptr )
    nd0 = (unsigned int **)v10;
  v24 = v10;
  if ( v10 >= 16 )
    v24 = 16;
  v6 = (double)(unsigned int)y;
  rv = v6;
  if ( v24 > 9 )
  {
    v6 = v6 * *(double *)&aXXml[8 * v24] + (double)(unsigned int)scale;
    rv = v6;
  }
  nfa = nullptr;
  if ( v10 <= 15 )
  {
    if ( v23 == 0 )
      goto LABEL_238;
    if ( v23 <= 0 )
    {
      if ( v23 >= -22 )
      {
        result = v6 / *(double *)&tens[-2 * v23];
        goto ret;
      }
    }
    else
    {
      if ( v23 <= 22 )
      {
        result = v6 * *(double *)&tens[2 * v23];
        goto ret;
      }
      if ( v23 <= 15 - v10 + 22 )
      {
        result = v6 * *(double *)&tens[2 * (15 - v10)] * *(double *)&tens[2 * (v23 - (15 - v10))];
        goto ret;
      }
    }
  }
  v25 = v10 + v23 - v24;
  scalea = 0;
  if ( v25 > 0 )
  {
    v26 = v6;
    if ( (v25 & 0xF) != 0 )
    {
      v26 = v6 * *(double *)&tens[2 * (v25 & 0xF)];
      rv = v26;
    }
    v27 = v25 & 0x7FFFFFF0;
    if ( v27 != 0 )
    {
      if ( v27 > 308 )
        goto LABEL_234;
      v28 = v27 >> 4;
      v29 = 0;
      if ( v28 > 1 )
      {
        do
        {
          if ( (v28 & 1) != 0 )
            v26 = v26 * bigtens[v29];
          v28 >>= 1;
          ++v29;
        }
        while ( v28 > 1 );
        rv = v26;
      }
      HIDWORD(rv) -= 55574528;
      rv = bigtens[v29] * rv;
      if ( (HIDWORD(rv) & 0x7FF00000u) > 0x7CA00000 )
      {
LABEL_234:
        v48 = aadj1;
ovfl:
        *error = 84;
        rv = INFINITY;
        if ( nfa != nullptr )
          goto retfree;
        result = INFINITY;
        v7 = (_BYTE *)s;
        goto ret;
      }
      if ( (HIDWORD(rv) & 0x7FF00000u) <= 0x7C900000 )
        HIDWORD(rv) += 55574528;
      else
        rv = 1.797693134862316e308;
    }
  }
  else if ( v25 < 0 )
  {
    v30 = -v25;
    if ( (v30 & 0xF) != 0 )
    {
      v6 = v6 / *(double *)&tens[2 * (v30 & 0xF)];
      rv = v6;
    }
    v31 = v30 >> 4;
    if ( v31 != 0 )
    {
      if ( v31 >= 32 )
        goto LABEL_231;
      if ( (v31 & 0x10) != 0 )
        scalea = 106;
      if ( v31 > 0 )
      {
        v32 = (double *)tinytens;
        do
        {
          if ( (v31 & 1) != 0 )
            v6 = v6 * *v32;
          v31 >>= 1;
          ++v32;
        }
        while ( v31 > 0 );
        rv = v6;
      }
      if ( scalea != 0 )
      {
        v33 = 107 - ((HIDWORD(rv) >> 20) & 0x7FF);
        if ( v33 > 0 )
        {
          if ( v33 < 32 )
          {
            LODWORD(rv) &= -1 << v33;
          }
          else
          {
            LODWORD(rv) = 0;
            if ( v33 < 53 )
              HIDWORD(rv) &= -1 << (v33 - 32);
            else
              HIDWORD(rv) = 57671680;
          }
          v6 = rv;
        }
      }
      if ( v6 == 0.0 )
      {
LABEL_231:
        v48 = aadj1;
undfl:
        result = 0.0;
        rv = 0.0;
        if ( nfa != nullptr )
          goto retfree;
        v7 = (_BYTE *)s;
ret:
        v64 = sign == 0;
        *a3 = (unsigned int)v7;
        if ( !v64 )
          return -result;
        return result;
      }
    }
  }
  s2b(a1: bbe, a2: (long double *)&alloc, (int)nd0, nd: v10, y9: y);
  v35 = v34;
  for ( nfa = v34; ; v35 = nfa )
  {
    Balloc(k: *((_DWORD *)v35 + 1), (long double *)&alloc);
    nd = (unsigned int **)v36;
    memcpy(dst: (unsigned __int8 *)(v36 + 12), src: v35 + 12, count: 4 * *((_DWORD *)v35 + 4) + 8);
    nd0 = d2b(a1: (long double *)&alloc, y: LODWORD(rv), a3: SHIDWORD(rv), e: &bbe, bits: &esign);
    i2b((long double *)&alloc, i: (_LDOUBLE *)1);
    y = v37;
    if ( v23 < 0 )
    {
      v38 = -v23;
      v39 = -v23;
      v23 = 0;
    }
    else
    {
      v38 = 0;
      v39 = 0;
    }
    nza = v23;
    if ( bbe < 0 )
      v23 -= bbe;
    else
      v39 += bbe;
    dsigna = v39;
    if ( esign + bbe - scalea - 1 >= -1022 )
      v40 = 54 - esign;
    else
      v40 = bbe - scalea + 1075;
    v41 = v40 + v39;
    v42 = scalea + v40 + v23;
    v43 = v41;
    if ( v41 >= v42 )
      v43 = v42;
    v44 = dsigna;
    if ( v43 > dsigna )
      v43 = dsigna;
    if ( v43 > 0 )
    {
      v41 -= v43;
      v42 -= v43;
      v44 = dsigna - v43;
      dsigna -= v43;
    }
    if ( v38 > 0 )
    {
      v45 = nd0;
      y = (int)pow5mult(a1: (long double *)&alloc, a2: y, a3: v38);
      nd0 = (unsigned int **)mult(a1: (unsigned int **)y, a2: (long double *)&alloc, wa: nd0);
      Bfree(a1: v45, a2: &alloc);
      v44 = dsigna;
    }
    if ( v41 > 0 )
      nd0 = lshift(a1: nd0, a2: v41, (long double *)&alloc);
    if ( nza > 0 )
    {
      v44 = dsigna;
      nd = pow5mult(a1: (long double *)&alloc, a2: (int)nd, a3: nza);
    }
    if ( v42 > 0 )
      nd = lshift(a1: nd, a2: v42, (long double *)&alloc);
    if ( v44 <= 0 )
    {
      v46 = (char *)y;
    }
    else
    {
      v46 = (char *)lshift(a1: (_DWORD *)y, a2: v44, (long double *)&alloc);
      y = (int)v46;
    }
    diff(b: (char *)nd, a2: (long double *)&alloc, a3: (unsigned int *)nd0);
    v48 = v47;
    v49 = v47[3];
    dsignb = v49;
    v47[3] = 0;
    cmp(a: v47, b: v46);
    if ( v50 < 0 )
    {
      if ( v49 != 0 )
        goto LABEL_209;
      if ( LODWORD(rv) != 0 )
        goto LABEL_209;
      v60 = HIDWORD(rv);
      if ( (HIDWORD(rv) & 0xFFFFF) != 0
        || (HIDWORD(rv) & 0x7FF00000u) <= 0x6B00000
        || *(_DWORD *)*v48 == 0 && (int)v48[4] <= 1 )
      {
        goto LABEL_209;
      }
      v48 = (unsigned int *)lshift(a1: v48, a2: 1, (long double *)&alloc);
      cmp(a: v48, b: v46);
      if ( v61 <= 0 )
        goto LABEL_209;
      goto drop_down;
    }
    if ( v50 == 0 )
    {
      if ( v49 != 0 )
      {
        if ( (HIDWORD(rv) & 0xFFFFF) == 0xFFFFF )
        {
          v62 = scalea != 0 && (HIDWORD(rv) & 0x7FF00000u) <= 0x6A00000
              ? -1 << (107 - ((HIDWORD(rv) & 0x7FF00000u) >> 20))
              : -1;
          if ( LODWORD(rv) == v62 )
          {
            HIDWORD(rv) = (HIDWORD(rv) & 0x7FF00000) + 0x100000;
            LODWORD(rv) = 0;
            goto LABEL_209;
          }
        }
        goto LABEL_226;
      }
      v60 = HIDWORD(rv);
      if ( (HIDWORD(rv) & 0xFFFFF) == 0 && LODWORD(rv) == 0 )
      {
drop_down:
        if ( scalea != 0 && (v60 & 0x7FF00000u) <= 0x6B00000 )
        {
          if ( (v60 & 0x7FF00000u) <= 0x3700000 )
            goto undfl;
        }
        else
        {
          HIDWORD(rv) = ((v60 & 0x7FF00000) - 1) | 0xFFFFF;
          LODWORD(rv) = -1;
        }
        goto LABEL_209;
      }
LABEL_226:
      if ( (LOBYTE(rv) & 1) != 0 )
      {
        v63 = ulp(a: rv);
        if ( dsignb != 0 )
        {
          rv = rv + v63;
        }
        else
        {
          rv = rv - v63;
          if ( 0.0 == rv )
            goto undfl;
        }
      }
LABEL_209:
      if ( scalea != 0 )
      {
        rv0 = 1.232595164407831e-32;
        rv = 1.232595164407831e-32 * rv;
      }
retfree:
      Bfree(a1: nd0, a2: &alloc);
      Bfree(a1: nd, a2: &alloc);
      Bfree(a1: (_DWORD *)y, a2: &alloc);
      Bfree(a1: nfa, a2: &alloc);
      Bfree(a1: v48, a2: &alloc);
      result = rv;
      v7 = (_BYTE *)s;
      goto ret;
    }
    v51 = ratio(a: (unsigned int)v48, b: y);
    if ( v51 > 2.0 )
    {
      v52 = v51 * 0.5;
      if ( v49 == 0 )
        goto LABEL_169;
      v53 = v52;
    }
    else
    {
      if ( v49 != 0 )
      {
        v52 = 1.0;
        v53 = 1.0;
        goto LABEL_170;
      }
      if ( LODWORD(rv) == 0 )
      {
        if ( (HIDWORD(rv) & 0xFFFFF) == 0 )
        {
          if ( v51 >= 1.0 )
            v52 = v51 * 0.5;
          else
            v52 = 0.5;
LABEL_169:
          v53 = -v52;
          goto LABEL_170;
        }
LABEL_178:
        v52 = 1.0;
        v53 = -1.0;
        goto LABEL_170;
      }
      if ( LODWORD(rv) != 1 )
        goto LABEL_178;
      if ( HIDWORD(rv) == 0 )
        goto undfl;
      v52 = 1.0;
      v53 = -1.0;
    }
LABEL_170:
    aadj1a = v53;
    v54 = HIDWORD(rv) & 0x7FF00000;
    if ( (HIDWORD(rv) & 0x7FF00000) == 0x7FE00000 )
    {
      v55 = rv;
      HIDWORD(rv) -= 55574528;
      rv0 = v55;
      rv = v53 * ulp(a: rv) + rv;
      if ( (HIDWORD(rv) & 0x7FF00000u) >= 0x7CA00000 )
      {
        if ( rv0 == 1.797693134862316e308 )
          goto ovfl;
        rv = 1.797693134862316e308;
        goto cont;
      }
      v57 = HIDWORD(rv) + 55574528;
      HIDWORD(rv) += 55574528;
    }
    else
    {
      if ( scalea != 0 && v54 <= 0x6A00000 )
      {
        if ( v52 <= 2147483647.0 )
        {
          v58 = (__int64)v52;
          if ( v58 == 0 )
            v58 = 1;
          v52 = (double)v58;
          if ( v49 != 0 )
            aadj1a = v52;
          else
            aadj1a = -v52;
        }
        HIDWORD(aadj1a) += 112197632 - v54;
        v53 = aadj1a;
      }
      rv = v53 * ulp(a: rv) + rv;
      v57 = HIDWORD(rv);
    }
    if ( scalea == 0 && v56 == (v57 & 0x7FF00000) )
    {
      v59 = v52 - (double)(int)v52;
      if ( dsignb != 0 || LODWORD(rv) != 0 || (v57 & 0xFFFFF) != 0 )
      {
        if ( v59 < 0.4999999 || v59 > 0.5000000999999999 )
          goto retfree;
      }
      else if ( v59 < 0.24999995 )
      {
        goto retfree;
      }
    }
cont:
    Bfree(a1: nd0, a2: &alloc);
    Bfree(a1: nd, a2: &alloc);
    Bfree(a1: (_DWORD *)y, a2: &alloc);
    Bfree(a1: v48, a2: &alloc);
    v23 = ea;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412EC0
// Name: quorem
// Source: json
//------------------------------------------------------------------------------
void __cdecl quorem(unsigned int *b, char *S)
{
  char *v2; // ebp
  signed int v3; // eax
  unsigned int *v4; // esi
  _DWORD *v5; // edi
  unsigned int v6; // ebx
  unsigned int v7; // ecx
  unsigned int v8; // eax
  unsigned __int64 v9; // kr00_8
  unsigned int v10; // edx
  unsigned int *v11; // eax
  int v12; // eax
  _DWORD *v13; // edi
  unsigned int *v14; // esi
  unsigned int v15; // ebx
  unsigned int v16; // edx
  unsigned __int64 v17; // kr08_8
  unsigned int v18; // ecx
  int v19; // edx
  _DWORD *i; // eax
  int n; // [esp+4h] [ebp-18h]
  unsigned int q; // [esp+8h] [ebp-14h]
  unsigned int *sxe; // [esp+Ch] [ebp-10h]
  unsigned int *bxe; // [esp+10h] [ebp-Ch]
  unsigned int borrowa; // [esp+14h] [ebp-8h]
  unsigned int borrowb; // [esp+14h] [ebp-8h]

  v2 = S;
  v3 = *((_DWORD *)S + 4);
  if ( (int)b[4] >= v3 )
  {
    v4 = *(unsigned int **)S;
    v5 = (_DWORD *)*b;
    n = v3 - 1;
    sxe = (unsigned int *)(*(_DWORD *)S + 4 * (v3 - 1));
    bxe = (unsigned int *)(*b + 4 * (v3 - 1));
    v6 = 0;
    v7 = *bxe / (*sxe + 1);
    q = v7;
    if ( v7 != 0 )
    {
      borrowa = 0;
      while ( 1 )
      {
        v8 = v6 + *v4 * v7;
        v6 = (v6 + *v4++ * (unsigned __int64)v7) >> 32;
        v9 = (unsigned int)*v5 - (unsigned __int64)v8;
        *v5++ = v9 - borrowa;
        borrowa = (BYTE4(v9) - ((unsigned int)v9 < borrowa)) & 1;
        if ( v4 > sxe )
          break;
        v7 = q;
      }
      if ( *bxe == 0 )
      {
        v10 = n;
        v11 = bxe - 1;
        if ( (unsigned int)(bxe - 1) > *b )
        {
          do
          {
            if ( *v11 != 0 )
              break;
            --v11;
            --v10;
          }
          while ( (unsigned int)v11 > *b );
          n = v10;
        }
        b[4] = v10;
      }
      v2 = S;
    }
    cmp(a: b, b: v2);
    if ( v12 >= 0 )
    {
      v13 = (_DWORD *)*b;
      v14 = *(unsigned int **)v2;
      v15 = 0;
      borrowb = 0;
      do
      {
        v16 = v15 + *v14;
        v15 = (v15 + (unsigned __int64)*v14++) >> 32;
        v17 = (unsigned int)*v13 - (unsigned __int64)v16;
        *v13++ = v17 - borrowb;
        borrowb = (BYTE4(v17) - ((unsigned int)v17 < borrowb)) & 1;
      }
      while ( v14 <= sxe );
      v18 = *b;
      v19 = n;
      if ( *(_DWORD *)(*b + 4 * n) == 0 )
      {
        for ( i = (_DWORD *)(*b + 4 * n - 4); (unsigned int)i > v18; --v19 )
        {
          if ( *i != 0 )
            break;
          --i;
        }
        b[4] = v19;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413020
// Name: dtoa
// Source: json
//------------------------------------------------------------------------------
_FloatOutStruct *__usercall dtoa@<eax>(
        INTRNCVT_STATUS a1@<eax>,
        _DWORD *a2@<edx>,
        int a3@<ecx>,
        double result,
        int mode,
        int ndigits,
        int *decpt,
        char **a8)
{
  int v8; // ebp
  unsigned int v10; // edi
  _FloatOutStruct *v11; // eax
  signed int v12; // esi
  int v13; // esi
  unsigned int v14; // eax
  double v15; // st7
  int v16; // ecx
  int v17; // eax
  int v18; // edi
  int v19; // ebp
  int v20; // ebx
  char *v21; // esi
  double v22; // st5
  int v23; // edx
  double v24; // st3
  int v25; // eax
  double *v26; // ecx
  int v27; // eax
  int v28; // ecx
  int v29; // eax
  double *v30; // ecx
  char *v31; // edi
  double v32; // st4
  double v33; // st5
  double v34; // st4
  double v35; // st4
  int v36; // edi
  double v37; // st2
  double v38; // st5
  double v39; // rt1
  double v40; // rt2
  double v41; // st2
  double v42; // st5
  double v43; // st2
  int v44; // eax
  double v45; // st2
  int v46; // edi
  double v47; // st3
  int v48; // ecx
  double v49; // st5
  int v50; // eax
  double v51; // rt0
  double v52; // st4
  double v53; // st5
  double v54; // st3
  int v55; // ecx
  double v56; // st4
  int v57; // edi
  double v58; // st4
  int v59; // eax
  char *v60; // esi
  int v61; // ecx
  _DWORD *v62; // ebp
  int v63; // eax
  int v64; // edi
  _DWORD *v65; // eax
  int v66; // eax
  int *v67; // edi
  int v68; // eax
  char v69; // cl
  int v70; // eax
  int v71; // eax
  int v72; // eax
  int v73; // eax
  int v74; // eax
  _DWORD *v75; // edi
  int v76; // eax
  int v77; // ebx
  int v78; // eax
  int v79; // ebp
  _DWORD *v80; // eax
  _DWORD *v81; // edi
  int v82; // eax
  int v83; // eax
  int v84; // eax
  int v85; // ebp
  char v86; // al
  int v87; // eax
  unsigned int **a; // [esp+20h] [ebp-9Ch]
  char *L; // [esp+24h] [ebp-98h]
  int k; // [esp+28h] [ebp-94h]
  int i; // [esp+2Ch] [ebp-90h]
  int ia; // [esp+2Ch] [ebp-90h]
  int ib; // [esp+2Ch] [ebp-90h]
  int b2; // [esp+30h] [ebp-8Ch]
  int s2; // [esp+34h] [ebp-88h]
  char *b; // [esp+38h] [ebp-84h]
  int ilim; // [esp+3Ch] [ebp-80h]
  int ilima; // [esp+3Ch] [ebp-80h]
  int ilim1; // [esp+40h] [ebp-7Ch]
  int ilim1a; // [esp+40h] [ebp-7Ch]
  double eps; // [esp+44h] [ebp-78h]
  char *s0; // [esp+4Ch] [ebp-70h]
  int leftright; // [esp+50h] [ebp-6Ch]
  int spec_case; // [esp+54h] [ebp-68h] BYREF
  double d2; // [esp+58h] [ebp-64h]
  int b5; // [esp+60h] [ebp-5Ch]
  int s5; // [esp+64h] [ebp-58h]
  int be; // [esp+68h] [ebp-54h] BYREF
  int denorm; // [esp+6Ch] [ebp-50h]
  INTRNCVT_STATUS alloc; // [esp+70h] [ebp-4Ch] BYREF
  INTRNCVT_STATUS v111; // [esp+74h] [ebp-48h]
  int v112; // [esp+78h] [ebp-44h]
  unsigned __int8 dst[64]; // [esp+7Ch] [ebp-40h] BYREF

  v8 = mode;
  v111 = a1;
  alloc = a1;
  v112 = a3 + a1;
  memset(dst, value: 0, count: sizeof(dst));
  v10 = HIDWORD(result);
  if ( result >= 0.0 )
  {
    *a2 = 0;
  }
  else
  {
    v10 = HIDWORD(result) & 0x7FFFFFFF;
    *a2 = 1;
    result = fabs(result);
  }
  if ( (v10 & 0x7FF00000) == 0x7FF00000 )
  {
    *decpt = 9999;
    goto LABEL_8;
  }
  if ( result == 0.0 )
  {
    *decpt = 1;
LABEL_8:
    v11 = (_FloatOutStruct *)dtoa_alloc(a1: (int)&alloc, a2: 2u);
    LOBYTE(v11->exp) = 48;
    HIBYTE(v11->exp) = 0;
    if ( a8 != nullptr )
      *a8 = (char *)&v11->exp + 1;
    return v11;
  }
  a = d2b(a1: (long double *)&alloc, y: LODWORD(result), a3: SHIDWORD(result), e: &be, bits: &spec_case);
  if ( ((v10 >> 20) & 0x7FF) != 0 )
  {
    v12 = ((v10 >> 20) & 0x7FF) - 1023;
    d2 = result;
    HIDWORD(d2) = HIDWORD(d2) & 0xFFFFF | 0x3FF00000;
    denorm = 0;
  }
  else
  {
    v13 = be + spec_case + 1074;
    if ( v13 <= 32 )
      v14 = LODWORD(result) << (32 - v13);
    else
      v14 = (LODWORD(result) >> (be + spec_case + 18)) | (v10 << (64 - v13));
    d2 = (double)v14;
    v12 = be + spec_case - 1;
    HIDWORD(d2) -= 32505856;
    denorm = 1;
  }
  v15 = (d2 - 1.5) * 0.289529654602168 + 0.1760912590558 + (double)v12 * 0.301029995663981;
  v16 = (int)v15;
  k = (int)v15;
  if ( v15 < 0.0 && (double)k != v15 )
    k = --v16;
  LODWORD(d2) = 1;
  if ( (unsigned int)v16 <= 0x16 )
  {
    if ( *(double *)&tens[2 * v16] > result )
      k = --v16;
    LODWORD(d2) = 0;
  }
  v17 = spec_case - v12 - 1;
  if ( v17 < 0 )
  {
    b2 = 1 - (spec_case - v12);
    v17 = 0;
  }
  else
  {
    b2 = 0;
  }
  s2 = v17;
  if ( v16 < 0 )
  {
    b2 -= v16;
    b5 = -v16;
    s5 = 0;
  }
  else
  {
    b5 = 0;
    s5 = v16;
    s2 = v16 + v17;
  }
  if ( (unsigned int)mode >= 0xA )
  {
    v8 = 0;
    mode = 0;
  }
  v18 = 1;
  if ( v8 > 5 )
  {
    v8 -= 4;
    mode = v8;
    v18 = 0;
  }
  leftright = 1;
  switch ( v8 )
  {
    case 0:
    case 1:
      v19 = -1;
      v20 = -1;
      ilim1 = -1;
      ilim = -1;
      v12 = 18;
      ndigits = 0;
      break;
    case 2:
      leftright = 0;
      goto $LN115;
    case 3:
      leftright = 0;
      goto $LN112_0;
    case 4:
$LN115:
      v12 = ndigits;
      if ( ndigits <= 0 )
      {
        v12 = 1;
        ndigits = 1;
      }
      v19 = v12;
      v20 = v12;
      ilim1 = v12;
      ilim = v12;
      break;
    case 5:
$LN112_0:
      v12 = k + ndigits + 1;
      v20 = v12;
      v19 = k + ndigits;
      ilim = v12;
      ilim1 = k + ndigits;
      if ( v12 <= 0 )
        v12 = 1;
      break;
    default:
      v20 = ilim;
      v19 = ilim1;
      break;
  }
  s0 = dtoa_alloc(a1: (int)&alloc, a2: v12);
  v21 = s0;
  if ( (unsigned int)v20 > 0xE || v18 == 0 )
  {
    v50 = k;
    v52 = result;
    v53 = 0.0;
    goto LABEL_95;
  }
  v22 = result;
  v23 = 2;
  ilima = k;
  i = v20;
  LODWORD(eps) = 2;
  if ( k <= 0 )
  {
    v27 = -k;
    if ( k != 0 )
    {
      v28 = v27 & 0xF;
      v29 = v27 >> 4;
      v22 = result * *(double *)&tens[2 * v28];
      if ( v29 != 0 )
      {
        v30 = bigtens;
        do
        {
          if ( (v29 & 1) != 0 )
          {
            ++v23;
            v22 = v22 * *v30;
          }
          v29 >>= 1;
          ++v30;
        }
        while ( v29 != 0 );
        LODWORD(eps) = v23;
      }
    }
  }
  else
  {
    v24 = *(double *)&tens[2 * (k & 0xF)];
    v25 = k >> 4;
    if ( ((k >> 4) & 0x10) != 0 )
    {
      v23 = 3;
      v25 = (k >> 4) & 0xF;
      LODWORD(eps) = 3;
      v22 = result / 1.0e256;
    }
    if ( v25 != 0 )
    {
      v26 = bigtens;
      do
      {
        if ( (v25 & 1) != 0 )
        {
          v24 = v24 * *v26;
          ++v23;
        }
        v25 >>= 1;
        ++v26;
      }
      while ( v25 != 0 );
      LODWORD(eps) = v23;
    }
    v22 = v22 / v24;
  }
  if ( LODWORD(d2) != 0 && v22 < 1.0 && v20 > 0 )
  {
    if ( v19 <= 0 )
    {
LABEL_91:
      v33 = result;
      v35 = 0.0;
      goto fast_failed;
    }
    --k;
    v20 = v19;
    v22 = v22 * 10.0;
    LODWORD(eps) = v23 + 1;
  }
  v31 = nullptr;
  eps = (double)SLODWORD(eps) * v22 + 7.0;
  HIDWORD(eps) -= 54525952;
  if ( v20 == 0 )
  {
    b = nullptr;
    v32 = v22;
    v33 = result;
    v34 = v32 - 5.0;
    if ( eps < v34 )
    {
one_digit:
      *s0 = 49;
      v21 = s0 + 1;
      ++k;
      goto ret_0;
    }
    if ( -eps > v34 )
      goto no_digits;
    v35 = 0.0;
    goto fast_failed;
  }
  if ( leftright == 0 )
  {
    v46 = 1;
    v47 = dbl_479C28[v20] * eps;
    while ( 1 )
    {
      v48 = (int)v22;
      v49 = v22 - (double)(int)v22;
      if ( 0.0 == v49 )
        v20 = v46;
      *v21++ = v48 + 48;
      if ( v46 == v20 )
        break;
      ++v46;
      v22 = v49 * 10.0;
    }
    if ( v47 + 0.5 < v49 )
      goto bump_up;
    if ( v49 < 0.5 - v47 )
    {
      do
        --v21;
      while ( *v21 == 48 );
      ++v21;
      goto ret1;
    }
    v35 = 0.0;
    v33 = result;
fast_failed:
    v50 = ilima;
    v51 = v35;
    v52 = v33;
    v53 = v51;
    v20 = i;
    result = v52;
    v21 = s0;
    k = ilima;
    ilim = i;
LABEL_95:
    v31 = nullptr;
    if ( be >= 0 && v50 <= 14 )
    {
      v54 = *(double *)&tens[2 * v50];
      if ( ndigits < 0 && v20 <= 0 )
      {
        b = nullptr;
        if ( v20 >= 0 )
        {
          if ( 5.0 * v54 >= v52 )
          {
            k = -1 - ndigits;
            goto ret_0;
          }
          goto one_digit;
        }
        k = -1 - ndigits;
ret_0:
        Bfree(a1: v31, a2: &alloc);
        if ( b != nullptr )
        {
          if ( LODWORD(eps) != 0 && (char *)LODWORD(eps) != b )
            Bfree(a1: (_DWORD *)LODWORD(eps), a2: &alloc);
          Bfree(a1: b, a2: &alloc);
        }
        goto ret1;
      }
      v55 = (int)(v52 / v54);
      *s0 = v55 + 48;
      v21 = s0 + 1;
      v56 = v52 - (double)v55 * v54;
      if ( v53 == v56 )
        goto ret1;
      v57 = 1;
      while ( v57 != v20 )
      {
        v58 = v56 * 10.0;
        v59 = (int)(v58 / v54);
        LOBYTE(v55) = v59;
        *v21++ = v59 + 48;
        ++v57;
        v56 = v58 - (double)v59 * v54;
        if ( v53 == v56 )
          goto ret1;
      }
      if ( v54 >= v56 + v56 && (v54 != v56 + v56 || (v55 & 1) == 0) )
        goto ret1;
bump_up:
      v60 = v21 - 1;
      if ( *v60 == 57 )
      {
        while ( v60 != s0 )
        {
          if ( *--v60 != 57 )
          {
            ++*v60;
            v21 = v60 + 1;
            goto ret1;
          }
        }
        ++k;
        *v60 = 48;
      }
      ++*v60;
      v21 = v60 + 1;
      goto ret1;
    }
    v61 = b2;
    v62 = nullptr;
    ia = b2;
    LODWORD(eps) = 0;
    b = nullptr;
    if ( leftright != 0 )
    {
      if ( denorm != 0 )
        v63 = be + 1075;
      else
        v63 = 54 - spec_case;
      b2 += v63;
      v64 = v63 + s2;
      s2 += v63;
      i2b((long double *)&alloc, i: (_LDOUBLE *)1);
      v61 = ia;
      v62 = v65;
      b = (char *)v65;
    }
    else
    {
      v64 = s2;
    }
    if ( v61 > 0 && v64 > 0 )
    {
      v66 = v61;
      if ( v61 >= v64 )
        v66 = v64;
      b2 -= v66;
      ia = v61 - v66;
      s2 = v64 - v66;
    }
    if ( b5 > 0 )
    {
      if ( leftright != 0 )
      {
        v62 = pow5mult(a1: (long double *)&alloc, a2: (int)v62, a3: b5);
        b = (char *)v62;
        v67 = mult(a1: (unsigned int **)v62, a2: (long double *)&alloc, wa: a);
        Bfree(a1: a, a2: &alloc);
        a = (unsigned int **)v67;
      }
      else
      {
        a = pow5mult(a1: (long double *)&alloc, a2: (int)a, a3: b5);
      }
    }
    i2b((long double *)&alloc, i: (_LDOUBLE *)1);
    v31 = (char *)v68;
    L = (char *)v68;
    if ( s5 > 0 )
    {
      v31 = (char *)pow5mult(a1: (long double *)&alloc, a2: v68, a3: s5);
      L = v31;
    }
    spec_case = 0;
    if ( (mode < 2 || leftright != 0)
      && LODWORD(result) == 0
      && (HIDWORD(result) & 0xFFFFF) == 0
      && (HIDWORD(result) & 0x7FE00000) != 0 )
    {
      ++b2;
      ++s2;
      spec_case = 1;
    }
    if ( s5 != 0 )
      v69 = 32 - hi0bits(a1: *(_DWORD *)(*(_DWORD *)v31 + 4 * *((_DWORD *)v31 + 4) - 4));
    else
      v69 = 1;
    v70 = (v69 + (_BYTE)s2) & 0x1F;
    if ( ((v69 + (_BYTE)s2) & 0x1F) != 0 )
      v70 = 32 - v70;
    if ( v70 <= 4 )
    {
      if ( v70 >= 4 )
        goto LABEL_149;
      v71 = v70 + 28;
    }
    else
    {
      v71 = v70 - 4;
    }
    b2 += v71;
    ia += v71;
    s2 += v71;
LABEL_149:
    if ( b2 > 0 )
      a = lshift(a1: a, a2: b2, (long double *)&alloc);
    if ( s2 > 0 )
    {
      v31 = (char *)lshift(a1: v31, a2: s2, (long double *)&alloc);
      L = v31;
    }
    if ( LODWORD(d2) != 0 )
    {
      cmp((unsigned int *)a, b: v31);
      if ( v72 < 0 )
      {
        --k;
        a = (unsigned int **)multadd(a1: (int)a, m: 10, a: 0, (long double *)&alloc);
        if ( leftright != 0 )
        {
          v62 = multadd(a1: (int)v62, m: 10, a: 0, (long double *)&alloc);
          b = (char *)v62;
        }
        v20 = ilim1;
        ilim = ilim1;
      }
    }
    if ( v20 > 0 || mode != 3 && mode != 5 )
    {
      if ( leftright != 0 )
      {
        if ( ia > 0 )
        {
          v62 = lshift(a1: v62, a2: ia, (long double *)&alloc);
          b = (char *)v62;
        }
        LODWORD(eps) = v62;
        if ( spec_case != 0 )
        {
          Balloc(k: v62[1], (long double *)&alloc);
          v75 = (_DWORD *)v74;
          memcpy(dst: (unsigned __int8 *)(v74 + 12), src: (unsigned __int8 *)v62 + 12, count: 4 * v62[4] + 8);
          b = (char *)lshift(a1: v75, a2: 1, (long double *)&alloc);
        }
        ib = 1;
        while ( 1 )
        {
          quorem(b: (unsigned int *)a, S: L);
          v77 = v76 + 48;
          cmp((unsigned int *)a, b: (char *)LODWORD(eps));
          v79 = v78;
          diff(b, a2: (long double *)&alloc, a3: (unsigned int *)L);
          v81 = v80;
          if ( v80[3] != 0 )
          {
            ilim1a = 1;
          }
          else
          {
            cmp((unsigned int *)a, b: (char *)v80);
            ilim1a = v82;
          }
          Bfree(a1: v81, a2: &alloc);
          if ( ilim1a == 0 && mode != 1 && (LOBYTE(result) & 1) == 0 )
          {
            if ( v77 == 57 )
              goto round_9_up;
            if ( v79 > 0 )
              LOBYTE(v77) = v77 + 1;
            goto LABEL_191;
          }
          if ( v79 < 0 || v79 == 0 && mode != 1 && (LOBYTE(result) & 1) == 0 )
          {
            if ( (**a != 0 || (int)a[4] > 1) && ilim1a > 0 )
            {
              a = lshift(a1: a, a2: 1, (long double *)&alloc);
              cmp((unsigned int *)a, b: L);
              if ( v83 > 0 || v83 == 0 && (v77 & 1) != 0 )
              {
                v84 = v77;
                LOBYTE(v77) = v77 + 1;
                if ( v84 == 57 )
                {
round_9_up:
                  *v21++ = 57;
roundoff:
                  if ( *--v21 == 57 )
                  {
                    while ( v21 != s0 )
                    {
                      if ( *--v21 != 57 )
                        goto LABEL_205;
                    }
                    ++k;
                    *v21 = 49;
                  }
                  else
                  {
LABEL_205:
                    ++*v21;
                  }
                  goto LABEL_206;
                }
              }
            }
LABEL_191:
            *v21++ = v77;
            goto LABEL_207;
          }
          if ( ilim1a > 0 )
            break;
          *v21++ = v77;
          if ( ib == ilim )
            goto LABEL_218;
          a = (unsigned int **)multadd(a1: (int)a, m: 10, a: 0, (long double *)&alloc);
          if ( (char *)LODWORD(eps) == b )
          {
            ++ib;
            LODWORD(eps) = multadd(a1: (int)b, m: 10, a: 0, (long double *)&alloc);
            b = (char *)LODWORD(eps);
          }
          else
          {
            LODWORD(eps) = multadd(a1: SLODWORD(eps), m: 10, a: 0, (long double *)&alloc);
            ++ib;
            b = (char *)multadd(a1: (int)b, m: 10, a: 0, (long double *)&alloc);
          }
        }
        if ( v77 == 57 )
          goto round_9_up;
        *v21++ = v77 + 1;
LABEL_207:
        v31 = L;
      }
      else
      {
        v85 = 1;
        quorem(b: (unsigned int *)a, S: v31);
        while ( 1 )
        {
          LOBYTE(v77) = v86 + 48;
          *v21++ = v86 + 48;
          if ( **a == 0 && (int)a[4] <= 1 )
            break;
          if ( v85 >= ilim )
          {
LABEL_218:
            a = lshift(a1: a, a2: 1, (long double *)&alloc);
            cmp((unsigned int *)a, b: L);
            if ( v87 > 0 || v87 == 0 && (v77 & 1) != 0 )
              goto roundoff;
            do
              --v21;
            while ( *v21 == 48 );
LABEL_206:
            ++v21;
            goto LABEL_207;
          }
          a = (unsigned int **)multadd(a1: (int)a, m: 10, a: 0, (long double *)&alloc);
          ++v85;
          quorem(b: (unsigned int *)a, S: v31);
        }
      }
      goto ret_0;
    }
    if ( v20 >= 0 )
    {
      v31 = (char *)multadd(a1: (int)v31, m: 5, a: 0, (long double *)&alloc);
      cmp((unsigned int *)a, b: v31);
      if ( v73 > 0 )
      {
        *s0 = 49;
        v21 = s0 + 1;
        ++k;
        goto ret_0;
      }
    }
no_digits:
    k = -1 - ndigits;
    goto ret_0;
  }
  v36 = 0;
  v37 = 0.5 / dbl_479C28[v20] - eps;
  *s0 = (int)v22 + 48;
  v21 = s0 + 1;
  v38 = v22 - (double)(int)v22;
  if ( v37 <= v38 )
  {
    while ( 1.0 - v38 >= v37 )
    {
      if ( ++v36 >= v20 )
        goto LABEL_91;
      v40 = v37 * 10.0;
      v41 = v38;
      v42 = v40;
      v43 = v41 * 10.0;
      v44 = (int)v43;
      v45 = v43 - (double)(int)v43;
      *v21++ = v44 + 48;
      if ( v45 < v40 )
        goto ret1;
      v39 = v45;
      v37 = v42;
      v38 = v39;
    }
    goto bump_up;
  }
ret1:
  Bfree(a1: a, a2: &alloc);
  *v21 = 0;
  *decpt = k + 1;
  if ( a8 != nullptr )
    *a8 = v21;
  return (_FloatOutStruct *)s0;
}

//------------------------------------------------------------------------------
// Address: 0x00413D50
// Name: _my_fcvt
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_fcvt(double x, int precision, char *to, char *error)
{
  unsigned __int8 *v4; // esi
  int v5; // eax
  int v6; // ebx
  unsigned __int8 *v8; // edi
  char *v9; // ebp
  _BYTE *v10; // esi
  int i; // eax
  unsigned int v12; // edi
  signed int v13; // edi
  char *v14; // eax
  int decpt; // [esp+24h] [ebp-6ACh] BYREF
  char *v16; // [esp+28h] [ebp-6A8h]
  char *res; // [esp+2Ch] [ebp-6A4h]
  char *end; // [esp+30h] [ebp-6A0h] BYREF
  char *v19; // [esp+34h] [ebp-69Ch]
  int sign; // [esp+38h] [ebp-698h] BYREF
  _BYTE v21[1680]; // [esp+3Ch] [ebp-694h] BYREF

  v4 = (unsigned __int8 *)to;
  v16 = to;
  v19 = error;
  v5 = (int)dtoa(
              a1: (INTRNCVT_STATUS)v21,
              a2: &sign,
              a3: 1680,
              result: x,
              mode: 5,
              ndigits: precision,
              &decpt,
              a8: &end);
  v6 = decpt;
  res = (char *)v5;
  if ( decpt == 9999 )
  {
    dtoa_free(a1: (void *)v5, a2: 1680, a3: (unsigned int)v21);
    *to = 48;
    to[1] = 0;
    if ( error != nullptr )
      *error = 1;
    return 1;
  }
  else
  {
    v8 = (unsigned __int8 *)v5;
    v9 = &end[-v5];
    decpt = v5;
    if ( sign != 0 )
    {
      *to = 45;
      v4 = (unsigned __int8 *)(to + 1);
    }
    if ( v6 <= 0 )
    {
      *v4 = 48;
      v10 = v4 + 1;
      *v10 = 46;
      v4 = v10 + 1;
      if ( v6 < 0 )
      {
        memset(dst: v4, value: 0x30u, count: -v6);
        v4 -= v6;
        v8 = (unsigned __int8 *)decpt;
      }
    }
    for ( i = 1; i <= (int)v9; ++i )
    {
      *v4++ = *v8++;
      if ( i == v6 && i < (int)v9 )
        *v4++ = 46;
    }
    if ( i <= v6 )
    {
      v12 = v6 - i + 1;
      memset(dst: v4, value: 0x30u, count: v12);
      v4 += v12;
    }
    if ( precision > 0 )
    {
      if ( (int)v9 <= v6 )
        *v4++ = 46;
      v13 = precision - ((int)&v9[-v6] < 0 ? 0 : (unsigned int)&v9[-v6]);
      if ( v13 > 0 )
      {
        memset(dst: v4, value: 0x30u, count: v13);
        v4 += v13;
      }
    }
    v14 = v19;
    *v4 = 0;
    if ( v14 != nullptr )
      *v14 = 0;
    dtoa_free(a1: res, a2: 1680, a3: (unsigned int)v21);
    return v4 - (unsigned __int8 *)v16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413EF0
// Name: _my_gcvt
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_gcvt(double x, int type, int width, char *to, char *error)
{
  char *v5; // esi
  int v6; // edi
  int v7; // eax
  char *v8; // eax
  int v9; // ebx
  char *v10; // ebp
  char *v11; // eax
  int result; // eax
  int v13; // eax
  int v14; // ebp
  int v15; // edx
  bool v16; // cl
  bool v17; // dl
  int v18; // ebp
  int v19; // ebx
  int v20; // edi
  _FloatOutStruct *v21; // eax
  char *v22; // edi
  char *v23; // ecx
  char *v24; // ebp
  char *v25; // ecx
  int v26; // edi
  char *v27; // eax
  char *v28; // ecx
  char *v29; // ebp
  int i; // edi
  int decpt; // [esp+28h] [ebp-6B8h] BYREF
  char *end; // [esp+2Ch] [ebp-6B4h] BYREF
  char *res; // [esp+30h] [ebp-6B0h]
  char *v34; // [esp+34h] [ebp-6ACh]
  char *v35; // [esp+38h] [ebp-6A8h]
  int sign; // [esp+3Ch] [ebp-6A4h] BYREF
  char *dend; // [esp+40h] [ebp-6A0h]
  int decpt_sign; // [esp+44h] [ebp-69Ch]
  char *src; // [esp+48h] [ebp-698h]
  _BYTE v40[1680]; // [esp+4Ch] [ebp-694h] BYREF

  v5 = to;
  v6 = width;
  v35 = error;
  v34 = to;
  dend = &to[width];
  if ( x < 0.0 )
    v6 = width - 1;
  v7 = v6;
  if ( type != 1 && v6 >= 6 )
    v7 = 6;
  v8 = (char *)dtoa(a1: (INTRNCVT_STATUS)v40, a2: &sign, a3: 1680, result: x, mode: 4, ndigits: v7, &decpt, a8: &end);
  v9 = decpt;
  v10 = v8;
  res = v8;
  if ( decpt != 9999 )
  {
    if ( v35 != nullptr )
      *v35 = 0;
    v13 = end - v8;
    src = v10;
    v14 = ((unsigned int)(v9 + 8) > 0x12) + ((unsigned int)(v9 + 98) > 0xC6) + 1;
    if ( v9 > 0 )
    {
      v15 = v13 + 1;
      if ( v9 >= v13 )
        v15 = v9;
    }
    else
    {
      v15 = v13 - v9 + 2;
    }
    v16 = v15 <= v6;
    v17 = v9 <= 0 && v6 <= 2 - v9 && v6 >= ((unsigned int)(v9 + 8) > 0x12) + ((unsigned int)(v9 + 98) > 0xC6) + 4;
    if ( v16 )
    {
      if ( v9 < -14 || v9 > 15 && v13 <= v9 )
        goto LABEL_34;
    }
    else
    {
      if ( v9 > v6 )
        goto LABEL_34;
      if ( v9 < -1 )
      {
        if ( v9 != -2 )
          goto LABEL_34;
        if ( v13 <= 1 )
        {
          if ( !v17 )
          {
            v18 = 3;
LABEL_72:
            v26 = v6 - (v18 + (v9 < v13));
            if ( v26 >= v13 )
            {
              v28 = src;
            }
            else
            {
              if ( v26 < v9 )
              {
                if ( v35 != nullptr )
                  *v35 = 1;
                v26 = v9;
              }
              dtoa_free(a1: res, a2: 1680, a3: (unsigned int)v40);
              v27 = (char *)dtoa(
                              a1: (INTRNCVT_STATUS)v40,
                              a2: &sign,
                              a3: 1680,
                              result: x,
                              mode: 5,
                              ndigits: v26 - v9,
                              &decpt,
                              a8: &end);
              v9 = decpt;
              v28 = v27;
              res = v27;
              v13 = end - v27;
            }
            if ( v13 != 0 )
            {
              v29 = dend;
              if ( sign != 0 && to < dend )
              {
                *to = 45;
                v5 = to + 1;
              }
              if ( v9 <= 0 )
              {
                if ( v5 < v29 )
                  *v5++ = 48;
                if ( v13 > 0 && v5 < v29 )
                  *v5++ = 46;
                for ( ; v9 < 0; ++v9 )
                {
                  if ( v5 >= v29 )
                    break;
                  *v5++ = 48;
                }
              }
              for ( i = 1; i <= v13; ++i )
              {
                if ( v5 >= v29 )
                  break;
                *v5++ = *v28++;
                if ( i == v9 && i < v13 && v5 < v29 )
                  *v5++ = 46;
              }
              for ( ; i <= v9; *v5++ = 48 )
              {
                ++i;
                if ( v5 >= v29 )
                  break;
              }
            }
            else
            {
              *to = 48;
              v5 = to + 1;
            }
            goto end_0;
          }
LABEL_34:
          v19 = v9 - 1;
          decpt_sign = 0;
          decpt = v19;
          if ( v19 < 0 )
          {
            v19 = -v19;
            decpt = v19;
            --v6;
            decpt_sign = 1;
          }
          v20 = -1 - v14 + v6;
          if ( v13 > 1 )
            --v20;
          if ( v20 <= 0 )
          {
            if ( v35 != nullptr )
              *v35 = 1;
            v20 = 0;
          }
          if ( v20 >= v13 )
          {
            v23 = src;
            v22 = end;
          }
          else
          {
            dtoa_free(a1: res, a2: 1680, a3: (unsigned int)v40);
            v21 = dtoa(
                    a1: (INTRNCVT_STATUS)v40,
                    a2: &sign,
                    a3: 1680,
                    result: x,
                    mode: 4,
                    ndigits: v20,
                    &decpt,
                    a8: &end);
            v22 = end;
            v23 = (char *)v21;
            v13 = end - (char *)v21;
            v19 = decpt - 1;
            res = v23;
            if ( decpt - 1 < 0 )
              v19 = 1 - decpt;
          }
          v24 = dend;
          if ( sign != 0 )
          {
            if ( to >= dend )
            {
LABEL_51:
              if ( v13 <= 1 )
                goto LABEL_56;
              if ( v5 < v24 )
              {
                *v5++ = 46;
                if ( v23 >= v22 )
                {
LABEL_56:
                  if ( v5 < v24 )
                    *v5++ = 101;
                }
                else
                {
                  while ( v5 < v24 )
                  {
                    *v5++ = *v23++;
                    if ( v23 >= v22 )
                      goto LABEL_56;
                  }
                }
              }
              if ( decpt_sign != 0 && v5 < v24 )
                *v5++ = 45;
              if ( v19 < 100 || v5 >= v24 )
              {
                if ( v19 < 10 )
                  goto LABEL_69;
                if ( v5 < v24 )
                {
                  *v5 = v19 / 10 + 48;
                  goto LABEL_68;
                }
              }
              else
              {
                *v5++ = v19 / 100 + 48;
                v19 %= 100;
                if ( v5 < v24 )
                {
                  *v5 = v19 / 10 + 48;
LABEL_68:
                  ++v5;
LABEL_69:
                  if ( v5 < v24 )
                    *v5++ = v19 % 10 + 48;
                }
              }
end_0:
              dtoa_free(a1: res, a2: 1680, a3: (unsigned int)v40);
              result = v5 - v34;
              *v5 = 0;
              return result;
            }
            *to = 45;
            v5 = to + 1;
          }
          if ( v5 < v24 )
          {
            v25 = res;
            *v5++ = *res;
            v23 = v25 + 1;
          }
          goto LABEL_51;
        }
      }
      if ( v17 )
        goto LABEL_34;
    }
    if ( v9 > 0 )
      v18 = 0;
    else
      v18 = 1 - v9;
    goto LABEL_72;
  }
  dtoa_free(a1: v8, a2: 1680, a3: (unsigned int)v40);
  v11 = v35;
  *to = 48;
  to[1] = 0;
  if ( v11 != nullptr )
    *v11 = 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00414350
// Name: _my_strtod
// Source: json
//------------------------------------------------------------------------------
double __cdecl my_strtod(tagShutdownType a1, unsigned int *a2, int *a3)
{
  double result; // st7
  _BYTE v4[1680]; // [esp+4h] [ebp-694h] BYREF

  result = my_strtod_int(a1: (INTRNCVT_STATUS)v4, s00: a1, a3: a2, error: a3, buf_size: 0x690u);
  if ( *a3 != 0 )
  {
    if ( result >= 0.0 )
      return 1.797693134862316e308;
    else
      return -1.797693134862316e308;
  }
  return result;
}
