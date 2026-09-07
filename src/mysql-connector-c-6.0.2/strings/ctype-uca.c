// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/ctype-uca.c
// Functions: 25
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0041C700
// Name: my_uca_scanner_init_ucs2
// Source: json
//------------------------------------------------------------------------------
_DWORD *__cdecl my_uca_scanner_init_ucs2(_DWORD *a1, _DWORD *a2, int a3, int a4)
{
  _DWORD *result; // eax

  result = a1;
  *a1 = nochar;
  if ( a4 != 0 )
  {
    a1[1] = a3;
    a1[2] = a3 + a4 - 2;
    a1[3] = a2[11];
    a1[4] = a2[13];
    a1[5] = a2[12];
  }
  else
  {
    a1[1] = &unk_5A843E;
    a1[2] = nochar;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041C750
// Name: my_uca_scanner_next_ucs2
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_uca_scanner_next_ucs2(pairNode *result)
{
  unsigned __int16 length; // dx
  int v2; // eax
  int myLen; // ebp
  pairNode_vtbl *v4; // edi
  DNameNode *left; // eax
  DNameNode *right; // ebx
  DNameNode *v7; // esi
  char *v8; // edx
  char v9; // bl
  pairNode_vtbl *v10; // eax
  int v11; // eax
  int v12; // eax
  unsigned __int16 v13; // dx
  pairNode_vtbl *v14; // edx
  int v15; // eax

  length = (unsigned __int16)result->length;
  if ( length != 0 )
  {
    result->__vftable = (pairNode_vtbl *)((char *)result->__vftable + 2);
    return length;
  }
  else
  {
    myLen = result->myLen;
    v4 = result[1].__vftable;
    while ( 1 )
    {
      left = result->left;
      right = result->right;
      if ( left > right )
        return -1;
      v7 = result[1].left;
      result[1].myLen = LOBYTE(left->__vftable);
      result[2].__vftable = (pairNode_vtbl *)BYTE1(left->__vftable);
      v8 = (char *)&left->__vftable + 2;
      result->left = (DNameNode *)((char *)&left->__vftable + 2);
      if ( v7 != nullptr && v8 <= (char *)right && result[1].myLen == 0 && *v8 == 0 )
      {
        v9 = HIBYTE(left->__vftable);
        if ( v9 > 64 )
        {
          v10 = result[2].__vftable;
          if ( (int)v10 > 64 && (int)v10 < 128 )
          {
            v2 = *((unsigned __int16 *)&v7[32 * ((_DWORD)v10 - 65)].__vftable + (unsigned __int8)v9);
            if ( v2 != 0 )
            {
              LOWORD(result[1].right) = 0;
              result->__vftable = (pairNode_vtbl *)&result[1].right;
              result->left = (DNameNode *)(v8 + 2);
              return v2;
            }
          }
        }
      }
      v11 = result[1].myLen;
      if ( *((_DWORD *)&v4->length + v11) == 0 )
        break;
      v12 = *((_DWORD *)&v4->length + v11) + 2 * (int)result[2].__vftable * *(unsigned __int8 *)(v11 + myLen);
      result->__vftable = (pairNode_vtbl *)v12;
      if ( *(_WORD *)v12 != 0 )
      {
        v13 = *(_WORD *)v12;
        result->__vftable = (pairNode_vtbl *)(v12 + 2);
        return v13;
      }
    }
    result[2].__vftable = (pairNode_vtbl *)((char *)result[2].__vftable + 256 * v11);
    LOWORD(result[1].right) = LOWORD(result[2].__vftable) | 0x8000;
    result->__vftable = (pairNode_vtbl *)&result[1].right;
    v14 = result[2].__vftable;
    v15 = v11 >> 7;
    HIWORD(result[1].right) = 0;
    result[1].myLen = v15;
    if ( (int)v14 < 13312 || (int)v14 > 19893 )
    {
      if ( (int)v14 < 19968 || (int)v14 > 40869 )
      {
        v2 = v15 + 64448;
        result[1].myLen = v2;
      }
      else
      {
        v2 = v15 + 64320;
        result[1].myLen = v2;
      }
    }
    else
    {
      v2 = v15 + 64384;
      result[1].myLen = v2;
    }
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0041C8A0
// Name: my_uca_scanner_init_any
// Source: json
//------------------------------------------------------------------------------
_DWORD *__cdecl my_uca_scanner_init_any(_DWORD *a1, _DWORD *a2, int a3, int a4)
{
  a1[1] = a3;
  a1[2] = a4 + a3;
  *a1 = nochar;
  a1[3] = a2[11];
  a1[4] = a2[13];
  a1[5] = a2[12];
  a1[9] = a2;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x0041C8E0
// Name: my_uca_scanner_next_any
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_uca_scanner_next_any(unsigned int result)
{
  pairNode *v1; // esi
  unsigned __int16 v2; // cx
  int v3; // eax
  pairNode_vtbl *v4; // edi
  int myLen; // ebx
  int v6; // eax
  DNameNode *left; // edx
  unsigned int v8; // ecx
  int v9; // eax
  bool v10; // zf
  int v11; // ecx
  int v12; // edx
  int v13; // eax
  _WORD *v14; // eax
  unsigned __int16 v15; // cx
  int v16; // ecx
  int v17; // eax

  v1 = (pairNode *)result;
  v2 = **(_WORD **)result;
  if ( v2 != 0 )
  {
    *(_DWORD *)result += 2;
    return v2;
  }
  else
  {
    while ( 1 )
    {
      v4 = v1[1].__vftable;
      myLen = v1->myLen;
      v6 = ((int (__cdecl *)(DNameNode *, unsigned int *, DNameNode *, DNameNode *))v1[2].left[25].__vftable[2].getString)(
             a1: v1[2].left,
             a2: &result,
             a3: v1->left,
             a4: v1->right);
      if ( v6 <= 0 )
        return -1;
      v1->left = (DNameNode *)((char *)v1->left + v6);
      left = v1->left;
      if ( result > 0xFFFF )
      {
        v1->__vftable = (pairNode_vtbl *)nochar;
        return 65533;
      }
      v8 = result >> 8;
      v9 = (unsigned __int8)result;
      v10 = v1[1].left == nullptr;
      v1[1].myLen = result >> 8;
      v1[2].__vftable = (pairNode_vtbl *)v9;
      if ( !v10 && v8 == 0 && v9 > 64 && v9 < 128 )
      {
        v11 = ((int (__cdecl *)(DNameNode *, unsigned int *, DNameNode *, DNameNode *))v1[2].left[25].__vftable[2].getString)(
                a1: v1[2].left,
                a2: &result,
                a3: left,
                a4: v1->right);
        if ( v11 >= 0 && (result & 0xFFFFFF00) == 0 && (unsigned int)(unsigned __int8)result - 65 <= 0x3E )
        {
          v12 = (unsigned __int8)result + (((int)&v1[2].__vftable[-6].getLastChar + 3) << 6);
          v3 = *((unsigned __int16 *)&v1[1].left->__vftable + v12);
          if ( *((_WORD *)&v1[1].left->__vftable + v12) != 0 )
          {
            v1->left = (DNameNode *)((char *)v1->left + v11);
            LOWORD(v1[1].right) = 0;
            v1->__vftable = (pairNode_vtbl *)&v1[1].right;
            return v3;
          }
        }
      }
      v13 = v1[1].myLen;
      if ( *((_DWORD *)&v4->length + v13) == 0 )
        break;
      v14 = (_WORD *)(*((_DWORD *)&v4->length + v13) + 2 * (int)v1[2].__vftable * *(unsigned __int8 *)(v13 + myLen));
      v1->__vftable = (pairNode_vtbl *)v14;
      if ( *v14 != 0 )
      {
        v15 = *v14;
        v1->__vftable = (pairNode_vtbl *)(v14 + 1);
        return v15;
      }
    }
    v1[2].__vftable = (pairNode_vtbl *)((char *)v1[2].__vftable + 256 * v13);
    LOWORD(v1[1].right) = LOWORD(v1[2].__vftable) | 0x8000;
    v1->__vftable = (pairNode_vtbl *)&v1[1].right;
    v16 = (int)v1[2].__vftable;
    v17 = v13 >> 7;
    HIWORD(v1[1].right) = 0;
    v1[1].myLen = v17;
    if ( v16 < 13312 || v16 > 19893 )
    {
      if ( v16 < 19968 || v16 > 40869 )
      {
        v3 = v17 + 64448;
        v1[1].myLen = v3;
      }
      else
      {
        v3 = v17 + 64320;
        v1[1].myLen = v3;
      }
    }
    else
    {
      v3 = v17 + 64384;
      v1[1].myLen = v3;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0041CA80
// Name: my_strnncoll_uca
// Source: json
//------------------------------------------------------------------------------
DNameStatusNode *__usercall my_strnncoll_uca@<eax>(
        int a1@<edx>,
        int a2@<ecx>,
        int a3@<ebx>,
        int a4@<esi>,
        const LoggingContext_t *result,
        unsigned int tlen,
        char t_is_prefix)
{
  int v8; // edi
  int v9; // eax
  const pDNameNode *sscanner; // [esp+4h] [ebp-54h] BYREF
  const pDNameNode *tscanner; // [esp+2Ch] [ebp-2Ch] BYREF

  (*(void (__cdecl **)(const pDNameNode **, int, const LoggingContext_t *, int))a4)(
    a1: &sscanner,
    a2: a1,
    a3: result,
    a4: a2);
  (*(void (__cdecl **)(const pDNameNode **, int, int, unsigned int))a4)(a1: &tscanner, a2: a1, a3, a4: tlen);
  do
  {
    v8 = (*(int (__cdecl **)(const pDNameNode **))(a4 + 4))(a1: &sscanner);
    v9 = (*(int (__cdecl **)(const pDNameNode **))(a4 + 4))(a1: &tscanner);
  }
  while ( v8 == v9 && v8 > 0 );
  if ( t_is_prefix != 0 && v9 < 0 )
    return nullptr;
  else
    return (DNameStatusNode *)(v8 - v9);
}

//------------------------------------------------------------------------------
// Address: 0x0041CB10
// Name: my_strnncollsp_uca
// Source: json
//------------------------------------------------------------------------------
DNameStatusNode *__usercall my_strnncollsp_uca@<eax>(
        int a1@<edx>,
        int a2@<ecx>,
        int a3@<esi>,
        const LoggingContext_t *result,
        const LoggingContext_t *t,
        unsigned int tlen)
{
  int v7; // edi
  int v8; // eax
  int v9; // ecx
  bool v10; // sf
  int v12; // ebx
  const pDNameNode *sscanner; // [esp+8h] [ebp-54h] BYREF
  const pDNameNode *tscanner; // [esp+30h] [ebp-2Ch] BYREF

  (*(void (__cdecl **)(const pDNameNode **, int, const LoggingContext_t *, int))a3)(
    a1: &sscanner,
    a2: a1,
    a3: result,
    a4: a2);
  (*(void (__cdecl **)(const pDNameNode **, int, const LoggingContext_t *, unsigned int))a3)(
    a1: &tscanner,
    a2: a1,
    a3: t,
    a4: tlen);
  while ( 1 )
  {
    v7 = (*(int (__cdecl **)(const pDNameNode **))(a3 + 4))(a1: &sscanner);
    v8 = (*(int (__cdecl **)(const pDNameNode **))(a3 + 4))(a1: &tscanner);
    v9 = v8;
    if ( v7 != v8 )
      break;
    if ( v7 <= 0 )
      goto LABEL_4;
  }
  v10 = v7 < 0;
  if ( v7 <= 0 )
  {
LABEL_5:
    if ( v10 && v8 > 0 )
    {
      v7 = *(unsigned __int16 *)((**(unsigned __int8 **)(a1 + 44) << 6) + **(_DWORD **)(a1 + 52));
      while ( v7 == v9 )
      {
        v9 = (*(int (__cdecl **)(const pDNameNode **))(a3 + 4))(a1: &tscanner);
        if ( v9 <= 0 )
          return nullptr;
      }
    }
    return (DNameStatusNode *)(v7 - v9);
  }
  if ( v8 >= 0 )
  {
LABEL_4:
    v10 = v7 < 0;
    goto LABEL_5;
  }
  v12 = *(unsigned __int16 *)((**(unsigned __int8 **)(a1 + 44) << 6) + **(_DWORD **)(a1 + 52));
  while ( v7 == v12 )
  {
    v7 = (*(int (__cdecl **)(const pDNameNode **))(a3 + 4))(a1: &sscanner);
    if ( v7 <= 0 )
      return nullptr;
  }
  return (DNameStatusNode *)(v7 - v12);
}

//------------------------------------------------------------------------------
// Address: 0x0041CC40
// Name: my_hash_sort_uca
// Source: json
//------------------------------------------------------------------------------
int __usercall my_hash_sort_uca@<eax>(
        int a1@<edx>,
        int a2@<ebx>,
        _DWORD *a3@<edi>,
        _DWORD *a4@<esi>,
        LIST_ENTRY32 *a5,
        const LoggingContext_t *s)
{
  int v6; // eax
  int result; // eax
  const pDNameNode *scanner; // [esp+8h] [ebp-2Ch] BYREF

  v6 = (*(int (__cdecl **)(LIST_ENTRY32 *, const LoggingContext_t *, int))(a5[12].Blink + 24))(a1: a5, a2: s, a3: a1);
  (*(void (__cdecl **)(const pDNameNode **, LIST_ENTRY32 *, const LoggingContext_t *, int))a2)(
    a1: &scanner,
    a2: a5,
    a3: s,
    a4: v6);
  for ( result = (*(int (__cdecl **)(const pDNameNode **))(a2 + 4))(a1: &scanner);
        result > 0;
        result = (*(int (__cdecl **)(const pDNameNode **))(a2 + 4))(a1: &scanner) )
  {
    *a3 ^= (*a3 << 8) + (result >> 8) * (*a4 + (*a3 & 0x3F));
    *a4 += 3;
    *a3 ^= (*a3 << 8) + (unsigned __int8)result * (*a4 + (*a3 & 0x3F));
    *a4 += 3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041CCF0
// Name: my_strnxfrm_uca
// Source: json
//------------------------------------------------------------------------------
const DNameNode *__usercall my_strnxfrm_uca@<eax>(
        int a1@<edx>,
        int a2@<ecx>,
        int a3@<ebx>,
        pDNameNode *result,
        unsigned __int8 *dst,
        unsigned int nweights,
        const LoggingContext_t *src,
        unsigned int flags)
{
  unsigned __int8 *v8; // esi
  unsigned __int8 *v9; // edi
  unsigned int v10; // ecx
  int v11; // eax
  unsigned int v12; // eax
  __int16 i; // cx
  _BYTE *v14; // esi
  __int16 v15; // ax
  const pDNameNode *scanner; // [esp+10h] [ebp-2Ch] BYREF

  v8 = dst;
  v9 = &dst[a2];
  ((void (__cdecl *)(const pDNameNode **, int, const LoggingContext_t *, int))result->__vftable)(
    a1: &scanner,
    a2: a3,
    a3: src,
    a4: a1);
  if ( dst < v9 )
  {
    while ( 1 )
    {
      v10 = nweights;
      if ( nweights == 0 )
        break;
      v11 = ((int (__cdecl *)(const pDNameNode **))result->me)(a1: &scanner);
      if ( v11 <= 0 )
      {
        v10 = nweights;
        break;
      }
      *v8++ = BYTE1(v11);
      if ( v8 < v9 )
        *v8++ = v11;
      --nweights;
      if ( v8 >= v9 )
        goto LABEL_16;
    }
    if ( v8 < v9 && v10 != 0 && (flags & 0x40) != 0 )
    {
      v12 = (unsigned int)(v9 - v8) >> 1;
      if ( v12 >= v10 )
        v12 = v10;
      for ( i = *(_WORD *)((**(unsigned __int8 **)(a3 + 44) << 6) + **(_DWORD **)(a3 + 52)); v12 != 0; --v12 )
      {
        *v8 = HIBYTE(i);
        v14 = v8 + 1;
        *v14 = i;
        v8 = v14 + 1;
      }
    }
  }
LABEL_16:
  my_strxfrm_desc_and_reverse(str: dst, strend: v8, flags, level: 0);
  if ( (flags & 0x80u) != 0 && v8 < v9 )
  {
    v15 = *(_WORD *)((**(unsigned __int8 **)(a3 + 44) << 6) + **(_DWORD **)(a3 + 52));
    do
    {
      *v8++ = HIBYTE(v15);
      if ( v8 >= v9 )
        break;
      *v8++ = v15;
    }
    while ( v8 < v9 );
  }
  return (const DNameNode *)(v8 - dst);
}

//------------------------------------------------------------------------------
// Address: 0x0041CE00
// Name: my_uca_charcmp
// Source: json
//------------------------------------------------------------------------------
int __usercall my_uca_charcmp@<eax>(int a1@<edx>, unsigned int a2@<ebx>, unsigned int result)
{
  int v3; // esi
  int v4; // edi
  unsigned int v5; // edx
  unsigned int v6; // esi
  int v7; // eax
  unsigned __int8 *v8; // edi
  int v9; // ebp
  unsigned int v10; // ecx
  int v11; // esi
  int v13; // ebp
  unsigned int v14; // ecx
  unsigned __int8 *v15; // edx
  int v16; // esi
  unsigned int v17; // ecx
  unsigned __int8 *v18; // edx
  int v19; // eax

  v3 = *(_DWORD *)(a1 + 44);
  v4 = *(_DWORD *)(a1 + 52);
  v5 = *(unsigned __int8 *)(v3 + (result >> 8));
  v6 = *(unsigned __int8 *)(v3 + (a2 >> 8));
  v7 = *(_DWORD *)(v4 + 4 * (result >> 8)) + 2 * v5 * (unsigned __int8)result;
  v8 = (unsigned __int8 *)(*(_DWORD *)(v4 + 4 * (a2 >> 8)) + 2 * v6 * (unsigned __int8)a2);
  if ( v7 == 0 || v8 == nullptr )
    return result != a2;
  if ( v5 <= v6 )
  {
    if ( v5 < v6 )
    {
      v13 = 2 * v5;
      v14 = 2 * v5;
      v15 = v8;
      v16 = v7;
      if ( v14 >= 4 )
      {
        while ( *(_DWORD *)v16 == *(_DWORD *)v15 )
        {
          v14 -= 4;
          v15 += 4;
          v16 += 4;
          if ( v14 < 4 )
            goto LABEL_19;
        }
        return 1;
      }
LABEL_19:
      if ( v14 != 0
        && (*v15 != *(_BYTE *)v16
         || v14 > 1 && (v15[1] != *(_BYTE *)(v16 + 1) || v14 > 2 && v15[2] != *(_BYTE *)(v16 + 2))) )
      {
        return 1;
      }
      return *(unsigned __int16 *)&v8[v13];
    }
    v17 = 2 * v5;
    v18 = (unsigned __int8 *)v7;
    if ( v17 < 4 )
    {
LABEL_29:
      if ( v17 == 0 )
        return 0;
    }
    else
    {
      while ( *(_DWORD *)v18 == *(_DWORD *)v8 )
      {
        v17 -= 4;
        v8 += 4;
        v18 += 4;
        if ( v17 < 4 )
          goto LABEL_29;
      }
    }
    v19 = *v18 - *v8;
    if ( v19 != 0 )
      return (v19 >> 31) | 1;
    if ( v17 <= 1 )
      return 0;
    v19 = v18[1] - v8[1];
    if ( v19 != 0 )
      return (v19 >> 31) | 1;
    if ( v17 <= 2 )
      return 0;
    v19 = v18[2] - v8[2];
    if ( v19 != 0 )
      return (v19 >> 31) | 1;
    if ( v17 > 3 )
    {
      v19 = v18[3] - v8[3];
      return (v19 >> 31) | 1;
    }
    return 0;
  }
  v9 = 2 * v6;
  v10 = 2 * v6;
  v11 = v7;
  if ( v10 >= 4 )
  {
    while ( *(_DWORD *)v11 == *(_DWORD *)v8 )
    {
      v10 -= 4;
      v8 += 4;
      v11 += 4;
      if ( v10 < 4 )
        goto LABEL_7;
    }
    return 1;
  }
LABEL_7:
  if ( v10 != 0
    && (*v8 != *(_BYTE *)v11 || v10 > 1 && (v8[1] != *(_BYTE *)(v11 + 1) || v10 > 2 && v8[2] != *(_BYTE *)(v11 + 2))) )
  {
    return 1;
  }
  return *(unsigned __int16 *)(v7 + v9);
}

//------------------------------------------------------------------------------
// Address: 0x0041CF80
// Name: my_wildcmp_uca
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_wildcmp_uca(int a1, int a2, int a3, unsigned int a4, int a5, int a6, int a7, int a8)
{
  int (__cdecl *v9)(_DWORD, _DWORD, _DWORD, _DWORD); // ebx
  unsigned int v10; // edi
  int v11; // ebp
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int result; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int i; // eax
  pairNode *v20; // [esp+Ch] [ebp-8h] BYREF
  int (__cdecl *v21)(_DWORD, _DWORD, _DWORD, _DWORD); // [esp+10h] [ebp-4h]
  char v22; // [esp+18h] [ebp+4h]
  int v23; // [esp+18h] [ebp+4h]

  v9 = *(int (__cdecl **)(_DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)(a1 + 100) + 32);
  v10 = a4;
  v21 = v9;
  if ( a4 == a5 )
    return a2 != a3;
  v11 = a2;
  while ( 1 )
  {
    v22 = 0;
    v12 = v9(a1, a2: &a4, a3: v10, a4: a5);
    if ( v12 <= 0 )
      return 1;
    if ( a4 == a8 )
      break;
    v10 += v12;
    if ( a4 == a6 )
    {
      v13 = v9(a1, a2: &a4, a3: v10, a4: a5);
      if ( v13 <= 0 )
        return 1;
      v10 += v13;
      v22 = 1;
    }
    v14 = v9(a1, a2: &v20, a3: v11, a4: a3);
    if ( v14 <= 0 )
      return 1;
    v11 += v14;
    if ( v22 != 0 || a4 != a7 )
    {
      if ( my_uca_charcmp(a1, a2: a4, result: (unsigned int)v20) != 0 )
        return 1;
      v9 = v21;
    }
    if ( v10 == a5 )
      return v11 != a3;
  }
  if ( v10 == a5 )
    return 0;
  while ( 1 )
  {
    v16 = v9(a1, a2: &a4, a3: v10, a4: a5);
    if ( v16 <= 0 )
      return 1;
    if ( a4 != a8 )
      break;
    v10 += v16;
LABEL_23:
    if ( v10 == a5 )
      return 0;
  }
  if ( a4 == a7 )
  {
    v10 += v16;
    v17 = v9(a1, a2: &v20, a3: v11, a4: a3);
    if ( v17 <= 0 )
      return 1;
    v11 += v17;
    goto LABEL_23;
  }
  if ( v10 == a5 )
    return 0;
  if ( v11 == a3 )
    return -1;
  v18 = v9(a1, a2: &a4, a3: v10, a4: a5);
  if ( v18 <= 0 )
    return 1;
  if ( a4 == a6 )
  {
    v10 += v18;
    if ( v9(a1, a2: &a4, a3: v10, a4: a5) <= 0 )
      return 1;
  }
LABEL_31:
  if ( v11 == a3 )
    return -1;
  for ( i = v9(a1, a2: &v20, a3: v11, a4: a3); ; i = v21(a1, a2: &v20, a3: v11, a4: a3) )
  {
    v23 = i;
    if ( i <= 0 )
      break;
    if ( my_uca_charcmp(a1, a2: a4, result: (unsigned int)v20) == 0 )
    {
      if ( v11 == a3 )
        return -1;
      result = my_wildcmp_uca(a1, a2: v11, a3, a4: v10, a5, a6, a7, a8);
      if ( result > 0 )
      {
        v11 += v23;
        v9 = v21;
        goto LABEL_31;
      }
      return result;
    }
    v11 += v23;
    if ( v11 == a3 )
      return -1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041D1D0
// Name: my_coll_lexem_init
// Source: json
//------------------------------------------------------------------------------
_DWORD *__usercall my_coll_lexem_init@<eax>(_DWORD *result@<eax>, int a2@<ecx>, tagShutdownType str_end)
{
  *result = a2;
  result[2] = a2;
  result[1] = str_end;
  result[3] = 0;
  result[4] = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041D1F0
// Name: my_coll_lexem_print_error
// Source: json
//------------------------------------------------------------------------------
_cpinfo *__usercall my_coll_lexem_print_error@<eax>(
        int a1@<ecx>,
        const char *a2@<edi>,
        _cpinfo *a3@<esi>,
        const DNameStatusNode *result)
{
  char *myLen; // ecx
  unsigned int v6; // eax
  char dst[32]; // [esp+4h] [ebp-24h] BYREF

  myLen = (char *)result->myLen;
  v6 = result->me - (_DWORD)myLen;
  if ( v6 >= 0x1D )
    v6 = 29;
  strmake(dst, src: myLen, length: v6);
  *((_BYTE *)a3 + a1 - 1) = 0;
  return my_snprintf(result: a3, n: (_EXCEPTION_REGISTRATION_RECORD *)(a1 - 1), fmt: (_CONTEXT *)"%s at '%s'", a2, dst);
}

//------------------------------------------------------------------------------
// Address: 0x0041D250
// Name: ch2x
// Source: json
//------------------------------------------------------------------------------
int __usercall ch2x@<eax>(int a1@<eax>)
{
  if ( (unsigned int)(a1 - 48) <= 9 )
    return a1 - 48;
  if ( (unsigned int)(a1 - 97) <= 5 )
    return a1 - 87;
  if ( (unsigned int)(a1 - 65) > 5 )
    return -1;
  return a1 - 55;
}

//------------------------------------------------------------------------------
// Address: 0x0041D280
// Name: my_coll_lexem_next
// Source: json
//------------------------------------------------------------------------------
int __usercall my_coll_lexem_next@<eax>(unsigned int *a1@<edi>)
{
  unsigned int v1; // ecx
  char *v2; // ebx
  char *v3; // esi
  char v4; // al
  char v6; // al
  _BYTE *v7; // esi
  int v8; // eax
  _BYTE *v9; // eax
  char *v10; // esi
  int v11; // eax

  v1 = a1[1];
  v2 = (char *)*a1;
  v3 = (char *)*a1;
  if ( *a1 >= v1 )
  {
LABEL_7:
    *a1 = (unsigned int)v3;
    a1[2] = (unsigned int)v2;
    return 0;
  }
  else
  {
    while ( 1 )
    {
      v4 = *v3;
      if ( *v3 != 32 && v4 != 9 && v4 != 13 && v4 != 10 )
        break;
      if ( (unsigned int)++v3 >= v1 )
        goto LABEL_7;
    }
    v6 = *v3;
    if ( *v3 == 38 )
    {
      *a1 = (unsigned int)(v3 + 1);
      a1[2] = (unsigned int)v2;
      return 4;
    }
    else if ( v6 == 61 )
    {
      *a1 = (unsigned int)(v3 + 1);
      a1[2] = (unsigned int)v2;
      return 1;
    }
    else if ( v6 == 60 )
    {
      v7 = v3 + 1;
      for ( a1[3] = 1; (unsigned int)v7 < v1; a1[3] = v8 + 1 )
      {
        if ( *v7 != 60 )
          break;
        v8 = a1[3];
        if ( v8 >= 3 )
          break;
        ++v7;
      }
      *a1 = (unsigned int)v7;
      a1[2] = (unsigned int)v2;
      return 1;
    }
    else if ( (v6 < 97 || v6 > 122) && (v6 < 65 || v6 > 90) )
    {
      if ( v6 == 92 && (v9 = v3 + 2, (unsigned int)(v3 + 2) < v1) && v3[1] == 117 )
      {
        v10 = v3 + 2;
        a1[4] = 0;
        if ( (unsigned int)v9 < v1 )
        {
          do
          {
            v11 = ch2x(a1: *v10);
            if ( v11 < 0 )
              break;
            ++v10;
            a1[4] = v11 + 16 * a1[4];
          }
          while ( (unsigned int)v10 < a1[1] );
        }
        *a1 = (unsigned int)v10;
        a1[2] = (unsigned int)v2;
        return 5;
      }
      else
      {
        *a1 = (unsigned int)v3;
        a1[2] = (unsigned int)v2;
        return 6;
      }
    }
    else
    {
      *a1 = (unsigned int)(v3 + 1);
      a1[4] = v6;
      a1[2] = (unsigned int)v2;
      return 5;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041D390
// Name: my_coll_rule_parse
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_coll_rule_parse(
        const DNameStatusNode *result,
        unsigned int mitems,
        tagShutdownType str,
        _cpinfo *errstr,
        unsigned int errsize)
{
  tagShutdownType v5; // ecx
  DNameStatusNode_vtbl *v6; // ebp
  int v7; // esi
  unsigned int *v8; // eax
  pairNode_vtbl *v9; // eax
  DNameNode *left; // esi
  int v12; // edx
  int v13; // eax
  DNameStatus v14; // eax
  DNameStatusNode_vtbl *v15; // ecx
  int v16; // eax
  DNameStatus v17; // edx
  unsigned int nitems; // [esp+10h] [ebp-48h]
  pairNode prevlexnum; // [esp+14h] [ebp-44h] BYREF
  int v21; // [esp+24h] [ebp-34h]
  DNameStatusNode_vtbl *v22; // [esp+28h] [ebp-30h]
  DNameNode *right; // [esp+30h] [ebp-28h]
  int myLen; // [esp+34h] [ebp-24h]
  int v25; // [esp+38h] [ebp-20h]
  DNameStatusNode_vtbl *v26; // [esp+3Ch] [ebp-1Ch]
  DNameStatus v27; // [esp+44h] [ebp-14h]
  int v28; // [esp+48h] [ebp-10h]
  DNameStatusNode_vtbl *v29; // [esp+4Ch] [ebp-Ch]
  DNameStatus v30; // [esp+50h] [ebp-8h]
  int v31; // [esp+54h] [ebp-4h]

  v6 = nullptr;
  LOBYTE(errstr->MaxCharSize) = 0;
  prevlexnum.__vftable = (pairNode_vtbl *)6;
  v7 = 0;
  nitems = 0;
  v27 = DN_valid;
  v28 = 0;
  v29 = nullptr;
  v30 = DN_valid;
  v31 = 0;
  v8 = my_coll_lexem_init(result: &prevlexnum.left, a2: str, str_end: v5);
  v9 = (pairNode_vtbl *)my_coll_lexem_next(a1: v8);
  if ( v9 == nullptr )
    return nitems;
  while ( 1 )
  {
    if ( v9 == (pairNode_vtbl *)6 )
    {
      my_coll_lexem_print_error(
        a1: errsize - 1,
        a2: "Unknown character",
        a3: errstr,
        result: (const DNameStatusNode *)&prevlexnum.left);
      return -1;
    }
    if ( v7 == 0 )
      break;
    if ( v7 == 1 )
    {
      if ( v9 != (pairNode_vtbl *)4 && v9 != (pairNode_vtbl *)1 )
      {
        my_coll_lexem_print_error(
          a1: errsize - 1,
          a2: "& or < expected",
          a3: errstr,
          result: (const DNameStatusNode *)&prevlexnum.left);
        return -1;
      }
      prevlexnum.__vftable = v9;
      goto LABEL_29;
    }
    if ( v9 != (pairNode_vtbl *)5 )
    {
      my_coll_lexem_print_error(
        a1: errsize - 1,
        a2: "character expected",
        a3: errstr,
        result: (const DNameStatusNode *)&prevlexnum.left);
      return -1;
    }
    if ( prevlexnum.__vftable == (pairNode_vtbl *)4 )
    {
      v6 = v22;
      v29 = nullptr;
      v30 = DN_valid;
      v31 = 0;
      v7 = 1;
      goto LABEL_30;
    }
    if ( prevlexnum.__vftable != (pairNode_vtbl *)1 )
    {
      my_coll_lexem_print_error(
        a1: errsize - 1,
        a2: "Should never happen",
        a3: errstr,
        result: (const DNameStatusNode *)&prevlexnum.left);
      return -1;
    }
    left = prevlexnum.left;
    myLen = prevlexnum.myLen;
    right = prevlexnum.right;
    v25 = v21;
    v26 = v22;
    v27 = (DNameStatus)v22;
    if ( my_coll_lexem_next(a1: (unsigned int *)&prevlexnum.left) == 5 )
    {
      v12 = (int)v22;
      v13 = v21;
    }
    else
    {
      prevlexnum.right = right;
      prevlexnum.left = left;
      prevlexnum.myLen = myLen;
      v13 = v25;
      v12 = 0;
      v21 = v25;
      v22 = v26;
    }
    switch ( v13 )
    {
      case 3:
        ++v31;
        break;
      case 2:
        ++v30;
        goto LABEL_21;
      case 1:
        v29 = (DNameStatusNode_vtbl *)((char *)v29 + 1);
        goto LABEL_20;
      case 0:
        v29 = nullptr;
LABEL_20:
        v30 = DN_valid;
LABEL_21:
        v31 = 0;
        break;
      default:
        break;
    }
    if ( nitems >= mitems )
    {
      my_coll_lexem_print_error(
        a1: errsize - 1,
        a2: "Too many rules",
        a3: errstr,
        result: (const DNameStatusNode *)&prevlexnum.left);
      return -1;
    }
    v14 = v27;
    v15 = v29;
    ++nitems;
    result->__vftable = v6;
    result->me = v14;
    v16 = v31;
    result->myLen = v12;
    v17 = v30;
    result[1].__vftable = v15;
    result[1].me = v17;
    result[1].myLen = v16;
    result += 2;
    v7 = 1;
LABEL_30:
    v9 = (pairNode_vtbl *)my_coll_lexem_next(a1: (unsigned int *)&prevlexnum.left);
    if ( v9 == nullptr )
      return nitems;
  }
  if ( v9 == (pairNode_vtbl *)4 )
  {
    prevlexnum.__vftable = (pairNode_vtbl *)4;
LABEL_29:
    v7 = 2;
    goto LABEL_30;
  }
  my_coll_lexem_print_error(
    a1: errsize - 1,
    a2: "& expected",
    a3: errstr,
    result: (const DNameStatusNode *)&prevlexnum.left);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0041D640
// Name: create_tailoring
// Source: json
//------------------------------------------------------------------------------
char __cdecl create_tailoring(_DWORD *a1)
{
  int (__cdecl *v1)(int); // ecx
  const char *v2; // edx
  int (__cdecl *v3)(int); // edi
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // ebx
  unsigned __int8 *v7; // ebp
  int v8; // edx
  unsigned __int8 *v9; // eax
  int i; // edi
  int v11; // esi
  unsigned __int8 v12; // cl
  unsigned __int8 *v13; // edi
  int v14; // esi
  unsigned int v15; // edi
  unsigned __int8 *v16; // eax
  unsigned int j; // edi
  int v18; // eax
  _WORD *v19; // eax
  bool v20; // cc
  DNameNode **v21; // ecx
  _DWORD *v22; // eax
  _DWORD *v23; // edi
  unsigned __int8 *v24; // eax
  int v25; // esi
  DNameStatus *p_me; // eax
  unsigned int v27; // edx
  int v28; // ecx
  int v29; // ebx
  DNameNode *v30; // ecx
  int v31; // ebx
  bool v32; // zf
  _WORD *v33; // ebx
  unsigned int v34; // ecx
  int v35; // [esp+4h] [ebp-C9Ch]
  int v36; // [esp+4h] [ebp-C9Ch]
  char *v37; // [esp+8h] [ebp-C98h]
  int v38; // [esp+Ch] [ebp-C94h]
  int v39; // [esp+10h] [ebp-C90h]
  int (__cdecl *v40)(unsigned int); // [esp+14h] [ebp-C8Ch]
  DNameStatusNode v41; // [esp+1Ch] [ebp-C84h] BYREF
  _cpinfo v42[6]; // [esp+C1Ch] [ebp-84h] BYREF

  v2 = (const char *)a1[7];
  v3 = v1;
  v40 = (int (__cdecl *)(unsigned int))v1;
  v39 = 0;
  if ( v2 == nullptr )
    return 1;
  strlen(v2);
  v38 = my_coll_rule_parse(result: &v41, mitems: 0x80u, str: (tagShutdownType)v2, errstr: v42, errsize: 0x80u);
  if ( v38 < 0 )
    return 1;
  v5 = (unsigned __int8 *)v3(a1: 1024);
  v6 = v5;
  if ( v5 == nullptr )
    return 1;
  memset(dst: v5, value: 0, count: 0x400u);
  v7 = (unsigned __int8 *)v3(a1: 256);
  if ( v7 != nullptr )
  {
    v8 = v38;
    qmemcpy(v7, uca_length, 256);
    if ( v38 > 0 )
    {
      v9 = (unsigned __int8 *)&v41.__vftable + 1;
      for ( i = v38; i != 0; --i )
      {
        if ( *(_DWORD *)(v9 + 7) != 0 )
        {
          ++v39;
        }
        else
        {
          v11 = v9[4];
          v12 = uca_length[*v9];
          if ( v7[v11] < v12 )
            v7[v11] = v12;
        }
        v9 += 24;
      }
    }
    v35 = 0;
    if ( v38 > 0 )
    {
      v13 = (unsigned __int8 *)&v41.me + 1;
      v37 = (char *)&v41.me + 1;
      do
      {
        v14 = *v13;
        if ( *(_DWORD *)(v13 + 3) == 0 )
        {
          if ( *(_DWORD *)&v6[4 * v14] == 0 )
          {
            v15 = v7[v14] << 9;
            v16 = (unsigned __int8 *)v40(a1: v15);
            *(_DWORD *)&v6[4 * v14] = v16;
            if ( v16 == nullptr )
              return 1;
            memset(dst: v16, value: 0, count: v15);
            for ( j = 0; j < 0x100; ++j )
              memcpy(
                dst: (unsigned __int8 *)(*(_DWORD *)&v6[4 * v14] + 2 * j * v7[v14]),
                src: (unsigned __int8 *)(&uca_weight)[v14] + 2 * j * uca_length[v14],
                count: 2 * uca_length[v14]);
            v13 = (unsigned __int8 *)v37;
          }
          v18 = uca_length[*(v13 - 4)];
          memcpy(
            dst: (unsigned __int8 *)(*(_DWORD *)&v6[4 * v14] + 2 * *(v13 - 1) * v7[v14]),
            src: (unsigned __int8 *)(&uca_weight)[*(v13 - 4)] + 2 * v18 * (unsigned __int8)*(_DWORD *)(v13 - 5),
            count: 2 * v18);
          v19 = (_WORD *)(*(_DWORD *)&v6[4 * v14] + 2 * *(v13 - 1) * v7[v14]);
          v8 = v38;
          *v19 += *(_WORD *)(v13 + 7);
        }
        v13 += 24;
        v20 = ++v35 < v8;
        v37 = (char *)v13;
      }
      while ( v20 );
    }
    v21 = &uca_weight;
    v22 = v6 + 4;
    do
    {
      if ( *(v22 - 1) == 0 )
        *(v22 - 1) = *v21;
      if ( *v22 == 0 )
        *v22 = *(_DWORD *)((char *)v22 + (char *)&uca_weight - (char *)v6);
      if ( v22[1] == 0 )
        v22[1] = *(_DWORD *)((char *)v22 + (char *)&off_4AA09C - (char *)v6);
      if ( v22[2] == 0 )
        v22[2] = *(_DWORD *)((char *)v22 + (char *)&off_4AA0A0 - (char *)v6);
      v21 += 4;
      v22 += 4;
    }
    while ( (int)v21 < (int)&my_ucs2_uca_scanner_handler );
    v23 = a1;
    a1[11] = v7;
    a1[13] = v6;
    a1[12] = 0;
    if ( v39 == 0 )
      return 0;
    v24 = (unsigned __int8 *)v40(a1: 8448u);
    a1[12] = v24;
    if ( v24 != nullptr )
    {
      memset(dst: v24, value: 0, count: 0x2100u);
      v25 = a1[12] + 4096;
      v36 = 0;
      if ( v38 > 0 )
      {
        p_me = &v41.me;
        do
        {
          v27 = *((_DWORD *)p_me + 1);
          if ( v27 != 0 )
          {
            v28 = *((unsigned __int8 *)p_me - 3);
            v29 = uca_length[v28];
            v30 = (&uca_weight)[v28];
            v31 = (unsigned __int8)*((_DWORD *)p_me - 1) * v29;
            v32 = *((_WORD *)&v30->__vftable + v31 + 1) == 0;
            v33 = (_WORD *)v30 + v31;
            if ( !v32 )
              return 1;
            v34 = *p_me;
            if ( *p_me < 0x40u || v34 > 0x7F || v27 < 0x40 || v27 > 0x7F )
              return 1;
            *(_WORD *)(v23[12] + 2 * (v27 + ((v34 - 65) << 6))) = *v33 + *((_WORD *)p_me + 4);
            v23 = a1;
            *(_BYTE *)(v34 + v25) = 1;
            *(_BYTE *)(v27 + v25) = 1;
          }
          p_me += 6;
          ++v36;
        }
        while ( v36 < v38 );
      }
      return 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041D9E0
// Name: my_coll_init_uca
// Source: json
//------------------------------------------------------------------------------
char __cdecl my_coll_init_uca(int a1)
{
  *(_BYTE *)(a1 + 96) = 32;
  return create_tailoring((_DWORD *)a1);
}

//------------------------------------------------------------------------------
// Address: 0x0041DA00
// Name: my_strnncoll_any_uca
// Source: json
//------------------------------------------------------------------------------
DNameStatusNode *__cdecl my_strnncoll_any_uca(
        LIST_ENTRY32 *cs,
        const LoggingContext_t *s,
        unsigned int slen,
        const LoggingContext_t *t,
        unsigned int tlen,
        char t_is_prefix)
{
  return my_strnncoll_uca(
           a1: (int)cs,
           a2: slen,
           a3: (int)t,
           a4: (int)&my_any_uca_scanner_handler,
           result: s,
           tlen,
           t_is_prefix);
}

//------------------------------------------------------------------------------
// Address: 0x0041DA30
// Name: my_strnncollsp_any_uca
// Source: json
//------------------------------------------------------------------------------
DNameStatusNode *__cdecl my_strnncollsp_any_uca(
        LIST_ENTRY32 *cs,
        const LoggingContext_t *s,
        unsigned int slen,
        const LoggingContext_t *t,
        unsigned int tlen)
{
  return my_strnncollsp_uca(a1: (int)cs, a2: slen, a3: (int)&my_any_uca_scanner_handler, result: s, t, tlen);
}

//------------------------------------------------------------------------------
// Address: 0x0041DA60
// Name: my_hash_sort_any_uca
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_hash_sort_any_uca(
        LIST_ENTRY32 *a1,
        const LoggingContext_t *s,
        unsigned int slen,
        unsigned int *n1,
        unsigned int *n2)
{
  return my_hash_sort_uca(a1: slen, a2: (int)&my_any_uca_scanner_handler, a3: n1, a4: n2, a5: a1, s);
}

//------------------------------------------------------------------------------
// Address: 0x0041DA90
// Name: my_strnxfrm_any_uca
// Source: json
//------------------------------------------------------------------------------
const DNameNode *__cdecl my_strnxfrm_any_uca(
        int a1,
        unsigned __int8 *a2,
        int a3,
        unsigned int a4,
        const LoggingContext_t *a5,
        int a6,
        unsigned int a7)
{
  return my_strnxfrm_uca(
           a1: a6,
           a2: a3,
           a3: a1,
           result: (pDNameNode *)&my_any_uca_scanner_handler,
           dst: a2,
           nweights: a4,
           src: a5,
           flags: a7);
}

//------------------------------------------------------------------------------
// Address: 0x0041DAC0
// Name: my_strnncoll_ucs2_uca
// Source: json
//------------------------------------------------------------------------------
DNameStatusNode *__cdecl my_strnncoll_ucs2_uca(
        LIST_ENTRY32 *cs,
        const LoggingContext_t *s,
        unsigned int slen,
        const LoggingContext_t *t,
        unsigned int tlen,
        char t_is_prefix)
{
  return my_strnncoll_uca(
           a1: (int)cs,
           a2: slen,
           a3: (int)t,
           a4: (int)&my_ucs2_uca_scanner_handler,
           result: s,
           tlen,
           t_is_prefix);
}

//------------------------------------------------------------------------------
// Address: 0x0041DAF0
// Name: my_strnncollsp_ucs2_uca
// Source: json
//------------------------------------------------------------------------------
DNameStatusNode *__cdecl my_strnncollsp_ucs2_uca(
        LIST_ENTRY32 *cs,
        const LoggingContext_t *s,
        unsigned int slen,
        const LoggingContext_t *t,
        unsigned int tlen)
{
  return my_strnncollsp_uca(a1: (int)cs, a2: slen, a3: (int)&my_ucs2_uca_scanner_handler, result: s, t, tlen);
}

//------------------------------------------------------------------------------
// Address: 0x0041DB20
// Name: my_hash_sort_ucs2_uca
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_hash_sort_ucs2_uca(
        LIST_ENTRY32 *a1,
        const LoggingContext_t *s,
        unsigned int slen,
        unsigned int *n1,
        unsigned int *n2)
{
  return my_hash_sort_uca(a1: slen, a2: (int)&my_ucs2_uca_scanner_handler, a3: n1, a4: n2, a5: a1, s);
}

//------------------------------------------------------------------------------
// Address: 0x0041DB50
// Name: my_strnxfrm_ucs2_uca
// Source: json
//------------------------------------------------------------------------------
const DNameNode *__cdecl my_strnxfrm_ucs2_uca(
        int a1,
        unsigned __int8 *a2,
        int a3,
        unsigned int a4,
        const LoggingContext_t *a5,
        int a6,
        unsigned int a7)
{
  return my_strnxfrm_uca(
           a1: a6,
           a2: a3,
           a3: a1,
           result: (pDNameNode *)&my_ucs2_uca_scanner_handler,
           dst: a2,
           nweights: a4,
           src: a5,
           flags: a7);
}
