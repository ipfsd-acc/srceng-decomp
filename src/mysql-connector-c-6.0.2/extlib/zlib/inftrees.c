// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/extlib/zlib/inftrees.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004547F0
// Name: _inflate_table
// Source: json
//------------------------------------------------------------------------------
int __cdecl inflate_table(int a1, int a2, unsigned int a3, _DWORD **a4, unsigned int *a5, unsigned __int16 *a6)
{
  unsigned int i; // eax
  unsigned int v7; // eax
  unsigned int j; // ecx
  unsigned int v10; // esi
  int v11; // edx
  unsigned int k; // eax
  unsigned int m; // eax
  __int16 v14; // cx
  unsigned int n; // eax
  char *v16; // eax
  unsigned int v17; // ebp
  unsigned int v18; // ebx
  unsigned __int16 v19; // ax
  int v20; // eax
  int v21; // eax
  int v22; // edx
  _DWORD *v23; // ecx
  unsigned int v24; // edx
  unsigned int ii; // eax
  int v26; // esi
  char v27; // cl
  unsigned int v28; // edx
  int v29; // eax
  unsigned __int16 *v30; // esi
  int v31; // eax
  _DWORD *v32; // esi
  unsigned int jj; // eax
  int v34; // [esp+Ch] [ebp-8Ch]
  int v35; // [esp+Ch] [ebp-8Ch]
  unsigned int v36; // [esp+10h] [ebp-88h]
  unsigned int v37; // [esp+14h] [ebp-84h]
  unsigned __int16 *v38; // [esp+18h] [ebp-80h]
  unsigned int v39; // [esp+1Ch] [ebp-7Ch]
  _DWORD *v40; // [esp+20h] [ebp-78h]
  unsigned int v41; // [esp+28h] [ebp-70h]
  _BYTE *v42; // [esp+2Ch] [ebp-6Ch]
  int v43; // [esp+30h] [ebp-68h]
  int v44; // [esp+34h] [ebp-64h]
  char *v45; // [esp+38h] [ebp-60h]
  int v46; // [esp+3Ch] [ebp-5Ch]
  int v47; // [esp+40h] [ebp-58h]
  int v48; // [esp+54h] [ebp-44h] BYREF
  int v49; // [esp+58h] [ebp-40h]
  _WORD v50[28]; // [esp+5Ch] [ebp-3Ch] BYREF

  v38 = a6;
  v48 = 0;
  v49 = 0;
  memset(v50, 0, 24);
  for ( i = 0; i < a3; ++i )
    ++*((_WORD *)&v48 + *(unsigned __int16 *)(a2 + 2 * i));
  v7 = *a5;
  v36 = *a5;
  for ( j = 15; j != 0; --j )
  {
    if ( *((_WORD *)&v48 + j) != 0 )
      break;
  }
  v39 = j;
  if ( v7 > j )
  {
    v36 = j;
    v7 = j;
  }
  if ( j == 0 )
  {
    *(*a4)++ = 320;
    *(*a4)++ = 320;
    *a5 = 1;
    return 0;
  }
  v10 = 1;
  while ( *((_WORD *)&v48 + v10) == 0 )
  {
    if ( *((_WORD *)&v48 + v10 + 1) != 0 )
    {
      ++v10;
      break;
    }
    if ( v50[v10 - 2] != 0 )
    {
      v10 += 2;
      break;
    }
    if ( v50[v10 - 1] != 0 )
    {
      v10 += 3;
      break;
    }
    if ( v50[v10] != 0 )
    {
      v10 += 4;
      break;
    }
    v10 += 5;
    if ( v10 > 0xF )
      break;
  }
  if ( v7 < v10 )
    v36 = v10;
  v11 = 1;
  for ( k = 1; k <= 0xF; ++k )
  {
    v11 = 2 * v11 - *((unsigned __int16 *)&v48 + k);
    if ( v11 < 0 )
      return -1;
  }
  if ( v11 > 0 && (a1 == 0 || j != 1) )
    return -1;
  v50[13] = 0;
  for ( m = 1; m < 15; v50[m + 12] = v14 )
  {
    v14 = *(_WORD *)((char *)&v48 + m * 2) + v50[m + 12];
    ++m;
  }
  for ( n = 0; n < a3; ++n )
  {
    if ( *(_WORD *)(a2 + 2 * n) != 0 )
      a6[(unsigned __int16)v50[*(unsigned __int16 *)(a2 + 2 * n) + 12]++] = n;
  }
  if ( a1 == 0 )
  {
    v16 = (char *)a6;
    v45 = (char *)a6;
    v44 = 19;
    goto LABEL_42;
  }
  if ( a1 == 1 )
  {
    v45 = (char *)&unk_4843B8 - 514;
    v16 = (char *)&unk_4843F8 - 514;
    v44 = 256;
LABEL_42:
    v42 = v16;
    goto LABEL_43;
  }
  v45 = (char *)&unk_484438;
  v42 = &unk_484478;
  v44 = -1;
LABEL_43:
  v43 = -1;
  v17 = 0;
  v18 = 0;
  v37 = v10;
  v40 = *a4;
  v46 = 1 << v36;
  v41 = 1 << v36;
  v47 = (1 << v36) - 1;
  if ( a1 == 1 && (unsigned int)(1 << v36) >= 0x5B0 )
    return 1;
  while ( 1 )
  {
    v19 = *v38;
    if ( *v38 < v44 )
    {
      LOBYTE(v34) = 0;
LABEL_50:
      HIWORD(v34) = v19;
      goto LABEL_51;
    }
    if ( v19 <= v44 )
    {
      LOBYTE(v34) = 96;
      v19 = 0;
      goto LABEL_50;
    }
    v20 = 2 * *v38;
    LOBYTE(v34) = v42[v20];
    HIWORD(v34) = *(_WORD *)&v45[v20];
LABEL_51:
    v21 = v46;
    v22 = 1 << (v37 - v18);
    v23 = &v40[v46 + (v17 >> v18)];
    do
    {
      v21 -= v22;
      v23 -= v22;
      BYTE1(v34) = v37 - v18;
      *v23 = v34;
    }
    while ( v21 != 0 );
    v24 = v37;
    for ( ii = 1 << (v37 - 1); (ii & v17) != 0; ii >>= 1 )
      ;
    if ( ii != 0 )
      v17 = ii + (v17 & (ii - 1));
    else
      v17 = 0;
    ++v38;
    if ( --*((_WORD *)&v48 + v37) == 0 )
    {
      if ( v37 == v39 )
        break;
      v37 = *(unsigned __int16 *)(a2 + 2 * *v38);
      v24 = v37;
    }
    if ( v24 > v36 )
    {
      v26 = v17 & v47;
      if ( (v17 & v47) != v43 )
      {
        if ( v18 == 0 )
          v18 = v36;
        v40 += v46;
        v27 = v37 - v18;
        v28 = v37;
        v29 = 1 << (v37 - v18);
        if ( v37 < v39 )
        {
          v30 = (unsigned __int16 *)&v48 + v37;
          do
          {
            v31 = v29 - *v30;
            if ( v31 <= 0 )
              break;
            ++v28;
            ++v27;
            ++v30;
            v29 = 2 * v31;
          }
          while ( v28 < v39 );
          v26 = v17 & v47;
        }
        v41 += 1 << v27;
        v46 = 1 << v27;
        if ( a1 == 1 && v41 >= 0x5B0 )
          return 1;
        LOBYTE((*a4)[v26]) = v27;
        BYTE1((*a4)[v26]) = v36;
        v43 = v26;
        HIWORD((*a4)[v26]) = v40 - *a4;
      }
    }
  }
  LOBYTE(v35) = 64;
  BYTE1(v35) = v37 - v18;
  HIWORD(v35) = 0;
  if ( v17 != 0 )
  {
    v32 = v40;
    do
    {
      if ( v18 != 0 && (v17 & v47) != v43 )
      {
        v32 = *a4;
        v18 = 0;
        BYTE1(v35) = v36;
        LOBYTE(v24) = v36;
      }
      v32[v17 >> v18] = v35;
      for ( jj = 1 << (v24 - 1); (jj & v17) != 0; jj >>= 1 )
        ;
      if ( jj == 0 )
        break;
      v17 = jj + (v17 & (jj - 1));
    }
    while ( v17 != 0 );
  }
  *a4 += v41;
  *a5 = v36;
  return 0;
}
