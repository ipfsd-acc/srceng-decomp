// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/extlib/zlib/trees.c
// Functions: 19
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004525E0
// Name: init_block
// Source: json
//------------------------------------------------------------------------------
int __fastcall init_block(int a1, int a2)
{
  _WORD *v2; // eax
  int i; // ecx
  _WORD *v4; // eax
  int j; // ecx
  _WORD *v6; // eax
  int k; // ecx

  v2 = (_WORD *)(a2 + 148);
  for ( i = 286; i != 0; --i )
  {
    *v2 = 0;
    v2 += 2;
  }
  v4 = (_WORD *)(a2 + 2440);
  for ( j = 30; j != 0; --j )
  {
    *v4 = 0;
    v4 += 2;
  }
  v6 = (_WORD *)(a2 + 2684);
  for ( k = 19; k != 0; --k )
  {
    *v6 = 0;
    v6 += 2;
  }
  *(_WORD *)(a2 + 1172) = 1;
  *(_DWORD *)(a2 + 5804) = 0;
  *(_DWORD *)(a2 + 5800) = 0;
  *(_DWORD *)(a2 + 5808) = 0;
  *(_DWORD *)(a2 + 5792) = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00452660
// Name: pqdownheap
// Source: json
//------------------------------------------------------------------------------
int __usercall pqdownheap@<eax>(int result@<eax>, int a2@<edi>, int a3)
{
  int v3; // edx
  int v4; // ebp
  int v5; // ecx
  bool v6; // cc
  int v7; // esi
  int v8; // ebp
  unsigned __int16 v9; // dx
  unsigned __int16 v10; // bx
  int v11; // esi
  unsigned __int16 v12; // dx
  unsigned __int16 v13; // bx
  int v14; // edx
  int v15; // [esp+8h] [ebp-4h]

  v3 = *(_DWORD *)(result + 5200);
  v4 = *(_DWORD *)(result + 4 * a3 + 2908);
  v5 = 2 * a3;
  v6 = 2 * a3 < v3;
  v15 = v4;
  if ( 2 * a3 > v3 )
  {
    *(_DWORD *)(result + 4 * a3 + 2908) = v4;
  }
  else
  {
    while ( 1 )
    {
      if ( v6 )
      {
        v7 = *(_DWORD *)(result + 4 * v5 + 2912);
        v8 = *(_DWORD *)(result + 4 * v5 + 2908);
        v9 = *(_WORD *)(a2 + 4 * v7);
        v10 = *(_WORD *)(a2 + 4 * v8);
        if ( v9 < v10 || v9 == v10 && *(_BYTE *)(v7 + result + 5208) <= *(_BYTE *)(result + v8 + 5208) )
          ++v5;
        v4 = v15;
      }
      v11 = *(_DWORD *)(result + 4 * v5 + 2908);
      v12 = *(_WORD *)(a2 + 4 * v4);
      v13 = *(_WORD *)(a2 + 4 * v11);
      if ( v12 < v13 )
      {
LABEL_12:
        *(_DWORD *)(result + 4 * a3 + 2908) = v4;
        return result;
      }
      if ( v12 == v13 && *(_BYTE *)(result + v4 + 5208) <= *(_BYTE *)(v11 + result + 5208) )
        break;
      *(_DWORD *)(result + 4 * a3 + 2908) = v11;
      v14 = *(_DWORD *)(result + 5200);
      a3 = v5;
      v5 *= 2;
      v6 = v5 < v14;
      if ( v5 > v14 )
        goto LABEL_12;
    }
    *(_DWORD *)(result + 4 * a3 + 2908) = v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00452730
// Name: gen_bitlen
// Source: json
//------------------------------------------------------------------------------
_DWORD *__usercall gen_bitlen@<eax>(_DWORD *result@<eax>, int *a2@<ecx>)
{
  int v2; // edx
  int v3; // ebx
  int *v4; // ecx
  int v5; // ebp
  int v6; // esi
  int v7; // edi
  int v8; // ecx
  int v9; // edx
  int v10; // edi
  int v11; // edx
  int v12; // ecx
  int v13; // esi
  int v14; // edi
  int v15; // ebp
  _WORD *v16; // esi
  int v17; // ecx
  _WORD *i; // edx
  int v19; // edx
  int v20; // esi
  int v21; // ebp
  int v22; // ecx
  int v23; // edi
  int v24; // [esp+10h] [ebp-20h]
  int *v25; // [esp+14h] [ebp-1Ch]
  int v26; // [esp+18h] [ebp-18h]
  int v27; // [esp+1Ch] [ebp-14h]
  int v28; // [esp+1Ch] [ebp-14h]
  int v29; // [esp+20h] [ebp-10h]
  int v30; // [esp+20h] [ebp-10h]
  int v31; // [esp+24h] [ebp-Ch]
  int v32; // [esp+28h] [ebp-8h]
  int v33; // [esp+2Ch] [ebp-4h]

  v2 = a2[1];
  v3 = *a2;
  v4 = (int *)a2[2];
  v31 = v2;
  v5 = *v4;
  v33 = v4[1];
  v6 = v4[4];
  v32 = v4[2];
  result[719] = 0;
  result[720] = 0;
  result[721] = 0;
  result[722] = 0;
  result[723] = 0;
  result[724] = 0;
  result[725] = 0;
  result[726] = 0;
  *(_WORD *)(v3 + 4 * result[result[1301] + 727] + 2) = 0;
  v7 = result[1301] + 1;
  v27 = v6;
  v26 = 0;
  if ( v7 < 573 )
  {
    v8 = 573 - v7;
    v9 = (int)&result[v7 + 727];
    v10 = 573;
    v25 = (int *)v9;
    v29 = v8;
    v24 = 573;
    while ( 1 )
    {
      v11 = *v25;
      v12 = *(unsigned __int16 *)(v3 + 4 * *(unsigned __int16 *)(v3 + 4 * *v25 + 2) + 2) + 1;
      if ( v12 > v6 )
      {
        ++v26;
        v12 = v6;
      }
      *(_WORD *)(v3 + 4 * v11 + 2) = v12;
      if ( v11 <= v31 )
      {
        ++*((_WORD *)result + v12 + 1438);
        v13 = 0;
        if ( v11 >= v32 )
          v13 = *(_DWORD *)(v33 + 4 * (v11 - v32));
        v14 = *(unsigned __int16 *)(v3 + 4 * v11);
        result[1450] += v14 * (v13 + v12);
        if ( v5 != 0 )
          result[1451] += v14 * (v13 + *(unsigned __int16 *)(v5 + 4 * v11 + 2));
        v10 = 573;
      }
      ++v25;
      if ( --v29 == 0 )
        break;
      v6 = v27;
    }
    v15 = v26;
    if ( v26 != 0 )
    {
      v16 = (_WORD *)result + v27 + 1438;
      do
      {
        v17 = v27 - 1;
        for ( i = (_WORD *)result + v27 + 1437; *i == 0; --v17 )
          --i;
        *((_WORD *)result + v17 + 1439) += 2;
        --*((_WORD *)result + v17 + 1438);
        --*v16;
        v15 -= 2;
      }
      while ( v15 > 0 );
      v19 = v27;
      if ( v27 != 0 )
      {
        v30 = (int)result + 2 * v27 + 2876;
        do
        {
          v20 = (unsigned __int16)*v16;
          v28 = v20;
          if ( v20 != 0 )
          {
            v21 = (int)&result[v10 + 727];
            do
            {
              v22 = *(_DWORD *)(v21 - 4);
              --v24;
              v21 -= 4;
              if ( v22 <= v31 )
              {
                v23 = *(unsigned __int16 *)(v3 + 4 * v22 + 2);
                if ( v23 != v19 )
                {
                  result[1450] += *(unsigned __int16 *)(v3 + 4 * v22) * (v19 - v23);
                  *(_WORD *)(v3 + 4 * v22 + 2) = v19;
                }
                v20 = --v28;
              }
            }
            while ( v20 != 0 );
            v10 = v24;
          }
          --v19;
          v16 = (_WORD *)(v30 - 2);
          v30 -= 2;
        }
        while ( v19 != 0 );
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00452950
// Name: scan_tree
// Source: json
//------------------------------------------------------------------------------
int __usercall scan_tree@<eax>(int result@<eax>, int a2@<ecx>, _WORD *a3)
{
  int v3; // edi
  int v4; // edx
  int v6; // ecx
  int v7; // esi
  int v8; // ebp
  unsigned __int16 *v9; // [esp+10h] [ebp-Ch]
  int v10; // [esp+14h] [ebp-8h]

  v3 = *(unsigned __int16 *)(result + 2);
  v4 = 0;
  v6 = 7;
  v7 = 4;
  if ( *(_WORD *)(result + 2) == 0 )
  {
    v6 = 138;
    v7 = 3;
  }
  *(_WORD *)(result + 4 * a2 + 6) = -1;
  if ( a2 >= 0 )
  {
    v8 = -1;
    v10 = a2 + 1;
    v9 = (unsigned __int16 *)(result + 6);
    do
    {
      result = v3;
      v3 = *v9;
      if ( ++v4 >= v6 || result != v3 )
      {
        if ( v4 >= v7 )
        {
          if ( result != 0 )
          {
            if ( result != v8 )
              ++a3[2 * result + 1342];
            ++a3[1374];
          }
          else if ( v4 > 10 )
          {
            ++a3[1378];
          }
          else
          {
            ++a3[1376];
          }
        }
        else
        {
          a3[2 * result + 1342] += v4;
        }
        v4 = 0;
        v8 = result;
        if ( v3 != 0 )
        {
          if ( result == v3 )
          {
            v6 = 6;
            v7 = 3;
          }
          else
          {
            v6 = 7;
            v7 = 4;
          }
        }
        else
        {
          v6 = 138;
          v7 = 3;
        }
      }
      v9 += 2;
      --v10;
    }
    while ( v10 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00452A30
// Name: send_tree
// Source: json
//------------------------------------------------------------------------------
int __usercall send_tree@<eax>(int result@<eax>, int a2@<edx>, int a3@<ecx>)
{
  int v3; // esi
  int v5; // ecx
  int v6; // edi
  int v7; // edx
  int v8; // edi
  int v9; // ecx
  unsigned __int16 v10; // si
  int v11; // edx
  int v12; // ecx
  int v13; // edx
  __int16 v14; // si
  int v15; // ecx
  int v16; // ecx
  unsigned __int16 v17; // si
  int v18; // edi
  int v19; // ecx
  int v20; // ebx
  int v21; // ecx
  int v22; // ecx
  unsigned __int16 v23; // si
  int v24; // edi
  int v25; // ecx
  int v26; // ebx
  int v27; // ecx
  int v28; // esi
  int v29; // edi
  int v30; // ecx
  int v31; // ebx
  int v32; // ecx
  int v33; // ecx
  unsigned __int16 v34; // si
  int v35; // edi
  int v36; // ecx
  int v37; // ebx
  int v38; // ecx
  int v39; // esi
  int v40; // edi
  int v41; // ecx
  int v42; // ebx
  unsigned __int16 v43; // si
  int v44; // edi
  int v45; // ecx
  int v46; // ebx
  int v47; // ecx
  int v48; // esi
  int v49; // edi
  int v50; // ecx
  int v51; // ebx
  int v52; // [esp+10h] [ebp-18h]
  int v53; // [esp+14h] [ebp-14h]
  unsigned __int16 *v54; // [esp+18h] [ebp-10h]
  int v55; // [esp+1Ch] [ebp-Ch]
  int v56; // [esp+1Ch] [ebp-Ch]
  int v57; // [esp+1Ch] [ebp-Ch]
  int v58; // [esp+1Ch] [ebp-Ch]
  int v59; // [esp+1Ch] [ebp-Ch]
  int i; // [esp+20h] [ebp-8h]
  int v61; // [esp+24h] [ebp-4h]

  v3 = 0;
  v55 = -1;
  v53 = *(unsigned __int16 *)(a2 + 2);
  v5 = 7;
  v6 = 4;
  if ( *(_WORD *)(a2 + 2) == 0 )
  {
    v5 = 138;
    v6 = 3;
  }
  if ( a3 >= 0 )
  {
    v54 = (unsigned __int16 *)(a2 + 6);
    for ( i = a3 + 1; i != 0; --i )
    {
      v7 = v53;
      ++v3;
      v61 = v53;
      v53 = *v54;
      v52 = v3;
      if ( v3 < v5 && v7 == *v54 )
        goto LABEL_44;
      if ( v3 < v6 )
      {
        do
        {
          v8 = *(unsigned __int16 *)(result + 4 * v7 + 2686);
          v9 = *(_DWORD *)(result + 5820);
          if ( v9 <= 16 - v8 )
          {
            *(_WORD *)(result + 5816) |= *(_WORD *)(result + 4 * v7 + 2684) << v9;
            v15 = v8 + v9;
          }
          else
          {
            v10 = *(_WORD *)(result + 4 * v7 + 2684);
            v11 = v10 << v9;
            v12 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5816) |= v11;
            *(_BYTE *)(v12 + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5816);
            *(_BYTE *)(*(_DWORD *)(result + 20) + *(_DWORD *)(result + 8)) = *(_BYTE *)(result + 5817);
            v13 = *(_DWORD *)(result + 5820);
            ++*(_DWORD *)(result + 20);
            v14 = v10 >> (16 - v13);
            v15 = v13 + v8 - 16;
            v7 = v61;
            *(_WORD *)(result + 5816) = v14;
            v3 = v52;
          }
          --v3;
          *(_DWORD *)(result + 5820) = v15;
          v52 = v3;
        }
        while ( v3 != 0 );
        goto LABEL_39;
      }
      if ( v7 != 0 )
      {
        if ( v7 != v55 )
        {
          v16 = *(_DWORD *)(result + 5820);
          v56 = *(unsigned __int16 *)(result + 4 * v7 + 2686);
          if ( v16 <= 16 - v56 )
          {
            *(_WORD *)(result + 5816) |= *(_WORD *)(result + 4 * v7 + 2684) << v16;
            v21 = v56 + v16;
          }
          else
          {
            v17 = *(_WORD *)(result + 4 * v7 + 2684);
            v18 = v17 << v16;
            v19 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5816) |= v18;
            *(_BYTE *)(v19 + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5816);
            *(_BYTE *)(*(_DWORD *)(result + 20) + *(_DWORD *)(result + 8)) = *(_BYTE *)(result + 5817);
            v20 = *(_DWORD *)(result + 5820);
            ++*(_DWORD *)(result + 20);
            v21 = v20 + v56 - 16;
            *(_WORD *)(result + 5816) = v17 >> (16 - v20);
            v3 = v52;
          }
          --v3;
          *(_DWORD *)(result + 5820) = v21;
          v52 = v3;
        }
        v22 = *(_DWORD *)(result + 5820);
        v57 = *(unsigned __int16 *)(result + 2750);
        if ( v22 <= 16 - v57 )
        {
          *(_WORD *)(result + 5816) |= *(_WORD *)(result + 2748) << v22;
          v27 = v57 + v22;
        }
        else
        {
          v23 = *(_WORD *)(result + 2748);
          v24 = v23 << v22;
          v25 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5816) |= v24;
          *(_BYTE *)(v25 + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5816);
          *(_BYTE *)(*(_DWORD *)(result + 20) + *(_DWORD *)(result + 8)) = *(_BYTE *)(result + 5817);
          v26 = *(_DWORD *)(result + 5820);
          ++*(_DWORD *)(result + 20);
          v27 = v26 + v57 - 16;
          *(_WORD *)(result + 5816) = v23 >> (16 - v26);
          v3 = v52;
        }
        v28 = v3 - 3;
        *(_DWORD *)(result + 5820) = v27;
        if ( v27 > 14 )
        {
          v29 = v28 << v27;
          v30 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5816) |= v29;
          *(_BYTE *)(v30 + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5816);
          *(_BYTE *)(*(_DWORD *)(result + 20) + *(_DWORD *)(result + 8)) = *(_BYTE *)(result + 5817);
          v31 = *(_DWORD *)(result + 5820);
          ++*(_DWORD *)(result + 20);
          *(_DWORD *)(result + 5820) = v31 - 14;
          *(_WORD *)(result + 5816) = (unsigned __int16)v28 >> (16 - v31);
          goto LABEL_39;
        }
        *(_WORD *)(result + 5816) |= v28 << v27;
        v32 = v27 + 2;
      }
      else
      {
        v33 = *(_DWORD *)(result + 5820);
        if ( v3 > 10 )
        {
          v59 = *(unsigned __int16 *)(result + 2758);
          if ( v33 <= 16 - v59 )
          {
            *(_WORD *)(result + 5816) |= *(_WORD *)(result + 2756) << v33;
            v47 = v59 + v33;
          }
          else
          {
            v43 = *(_WORD *)(result + 2756);
            v44 = v43 << v33;
            v45 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5816) |= v44;
            *(_BYTE *)(v45 + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5816);
            *(_BYTE *)(*(_DWORD *)(result + 20) + *(_DWORD *)(result + 8)) = *(_BYTE *)(result + 5817);
            v46 = *(_DWORD *)(result + 5820);
            ++*(_DWORD *)(result + 20);
            v47 = v46 + v59 - 16;
            *(_WORD *)(result + 5816) = v43 >> (16 - v46);
            v3 = v52;
          }
          v48 = v3 - 11;
          *(_DWORD *)(result + 5820) = v47;
          if ( v47 > 9 )
          {
            v49 = v48 << v47;
            v50 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5816) |= v49;
            *(_BYTE *)(v50 + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5816);
            *(_BYTE *)(*(_DWORD *)(result + 20) + *(_DWORD *)(result + 8)) = *(_BYTE *)(result + 5817);
            v51 = *(_DWORD *)(result + 5820);
            ++*(_DWORD *)(result + 20);
            *(_DWORD *)(result + 5820) = v51 - 9;
            *(_WORD *)(result + 5816) = (unsigned __int16)v48 >> (16 - v51);
            goto LABEL_39;
          }
          *(_WORD *)(result + 5816) |= v48 << v47;
          v32 = v47 + 7;
        }
        else
        {
          v58 = *(unsigned __int16 *)(result + 2754);
          if ( v33 <= 16 - v58 )
          {
            *(_WORD *)(result + 5816) |= *(_WORD *)(result + 2752) << v33;
            v38 = v58 + v33;
          }
          else
          {
            v34 = *(_WORD *)(result + 2752);
            v35 = v34 << v33;
            v36 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5816) |= v35;
            *(_BYTE *)(v36 + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5816);
            *(_BYTE *)(*(_DWORD *)(result + 20) + *(_DWORD *)(result + 8)) = *(_BYTE *)(result + 5817);
            v37 = *(_DWORD *)(result + 5820);
            ++*(_DWORD *)(result + 20);
            v38 = v37 + v58 - 16;
            *(_WORD *)(result + 5816) = v34 >> (16 - v37);
            v3 = v52;
          }
          v39 = v3 - 3;
          *(_DWORD *)(result + 5820) = v38;
          if ( v38 > 13 )
          {
            v40 = v39 << v38;
            v41 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5816) |= v40;
            *(_BYTE *)(v41 + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5816);
            *(_BYTE *)(*(_DWORD *)(result + 20) + *(_DWORD *)(result + 8)) = *(_BYTE *)(result + 5817);
            v42 = *(_DWORD *)(result + 5820);
            ++*(_DWORD *)(result + 20);
            *(_DWORD *)(result + 5820) = v42 - 13;
            *(_WORD *)(result + 5816) = (unsigned __int16)v39 >> (16 - v42);
            goto LABEL_39;
          }
          *(_WORD *)(result + 5816) |= v39 << v38;
          v32 = v38 + 3;
        }
      }
      *(_DWORD *)(result + 5820) = v32;
LABEL_39:
      v3 = 0;
      v55 = v7;
      if ( v53 != 0 )
      {
        if ( v7 == v53 )
        {
          v5 = 6;
          v6 = 3;
        }
        else
        {
          v5 = 7;
          v6 = 4;
        }
      }
      else
      {
        v5 = 138;
        v6 = 3;
      }
LABEL_44:
      v54 += 2;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00452F40
// Name: send_all_trees
// Source: json
//------------------------------------------------------------------------------
int __usercall send_all_trees@<eax>(int a1@<eax>, int a2, int a3, int a4)
{
  int v4; // ecx
  int v5; // ebx
  int v6; // edx
  int v7; // ecx
  int v8; // edx
  int v9; // ecx
  int v10; // edx
  int v11; // ecx
  int v12; // edx
  int v13; // ecx
  int v14; // edx
  int v15; // ecx
  int v16; // edx
  int i; // edi
  int v18; // ecx
  int v19; // edx
  unsigned __int16 v20; // si
  int v21; // edx
  int v22; // ecx
  int v23; // edx
  int v24; // eax

  v4 = *(_DWORD *)(a1 + 5820);
  v5 = a4;
  if ( v4 <= 11 )
  {
    *(_WORD *)(a1 + 5816) |= (a2 - 257) << v4;
    *(_DWORD *)(a1 + 5820) = v4 + 5;
  }
  else
  {
    v6 = (a2 - 257) << v4;
    v7 = *(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5816) |= v6;
    *(_BYTE *)(v7 + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5816);
    *(_BYTE *)(++*(_DWORD *)(a1 + 20) + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5817);
    v8 = *(_DWORD *)(a1 + 5820);
    ++*(_DWORD *)(a1 + 20);
    v5 = a4;
    *(_DWORD *)(a1 + 5820) = v8 - 11;
    *(_WORD *)(a1 + 5816) = (unsigned __int16)(a2 - 257) >> (16 - v8);
  }
  v9 = *(_DWORD *)(a1 + 5820);
  if ( v9 <= 11 )
  {
    *(_WORD *)(a1 + 5816) |= (a3 - 1) << v9;
    *(_DWORD *)(a1 + 5820) = v9 + 5;
  }
  else
  {
    v10 = (a3 - 1) << v9;
    v11 = *(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5816) |= v10;
    *(_BYTE *)(v11 + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5816);
    *(_BYTE *)(++*(_DWORD *)(a1 + 20) + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5817);
    v12 = *(_DWORD *)(a1 + 5820);
    ++*(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 5820) = v12 - 11;
    *(_WORD *)(a1 + 5816) = (unsigned __int16)(a3 - 1) >> (16 - v12);
  }
  v13 = *(_DWORD *)(a1 + 5820);
  if ( v13 <= 12 )
  {
    *(_WORD *)(a1 + 5816) |= (v5 - 4) << v13;
    *(_DWORD *)(a1 + 5820) = v13 + 4;
  }
  else
  {
    v14 = (v5 - 4) << v13;
    v15 = *(_DWORD *)(a1 + 20);
    *(_WORD *)(a1 + 5816) |= v14;
    *(_BYTE *)(v15 + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5816);
    *(_BYTE *)(++*(_DWORD *)(a1 + 20) + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5817);
    v16 = *(_DWORD *)(a1 + 5820);
    ++*(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 5820) = v16 - 12;
    *(_WORD *)(a1 + 5816) = (unsigned __int16)(v5 - 4) >> (16 - v16);
  }
  for ( i = 0; i < v5; ++i )
  {
    v18 = *(_DWORD *)(a1 + 5820);
    v19 = (unsigned __int8)bl_order[i];
    if ( v18 <= 13 )
    {
      *(_WORD *)(a1 + 5816) |= *(_WORD *)(a1 + 4 * v19 + 2686) << v18;
      *(_DWORD *)(a1 + 5820) = v18 + 3;
    }
    else
    {
      v20 = *(_WORD *)(a1 + 4 * v19 + 2686);
      v21 = v20 << v18;
      v22 = *(_DWORD *)(a1 + 20);
      *(_WORD *)(a1 + 5816) |= v21;
      *(_BYTE *)(v22 + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5816);
      *(_BYTE *)(++*(_DWORD *)(a1 + 20) + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5817);
      v23 = *(_DWORD *)(a1 + 5820);
      ++*(_DWORD *)(a1 + 20);
      v5 = a4;
      *(_DWORD *)(a1 + 5820) = v23 - 13;
      *(_WORD *)(a1 + 5816) = v20 >> (16 - v23);
    }
  }
  v24 = send_tree(result: a1, a2: a1 + 148, a3: a2 - 1);
  return send_tree(result: v24, a2: v24 + 2440, a3: a3 - 1);
}

//------------------------------------------------------------------------------
// Address: 0x004531A0
// Name: compress_block
// Source: json
//------------------------------------------------------------------------------
int __usercall compress_block@<eax>(int result@<eax>, int a2, int a3)
{
  int v3; // ebx
  unsigned int v4; // ecx
  int v5; // ebp
  int v6; // esi
  int v7; // ecx
  int v8; // edi
  int v9; // esi
  int v10; // edx
  int v11; // ecx
  int v12; // edx
  int v13; // ecx
  int v14; // edx
  int v15; // edi
  int v16; // edx
  int v17; // ecx
  int v18; // edx
  int v19; // edi
  int v20; // esi
  int v21; // ecx
  int v22; // edx
  int v23; // ecx
  int v24; // edx
  int v25; // ecx
  unsigned int v26; // ebp
  int v27; // edi
  int v28; // edx
  int v29; // ecx
  unsigned __int16 v30; // si
  int v31; // edx
  int v32; // ecx
  int v33; // edx
  int v34; // esi
  int v35; // ecx
  unsigned int v36; // ebp
  unsigned int v37; // edx
  int v38; // ecx
  int v39; // edx
  int v40; // edi
  int v41; // ecx
  unsigned __int16 v42; // si
  int v43; // edx
  int v44; // ecx
  int v45; // edx
  int v46; // [esp+10h] [ebp-Ch]
  int v47; // [esp+14h] [ebp-8h]
  int v48; // [esp+14h] [ebp-8h]
  unsigned int v49; // [esp+18h] [ebp-4h]

  v3 = a2;
  v4 = 0;
  if ( *(_DWORD *)(result + 5792) != 0 )
  {
    do
    {
      v5 = *(unsigned __int16 *)(*(_DWORD *)(result + 5796) + 2 * v4);
      v6 = *(unsigned __int8 *)(v4 + *(_DWORD *)(result + 5784));
      v49 = v4 + 1;
      v7 = *(_DWORD *)(result + 5820);
      if ( v5 != 0 )
      {
        v14 = _length_code[v6];
        v46 = *(unsigned __int16 *)(v3 + 4 * v14 + 1030);
        v47 = v14;
        if ( v7 <= 16 - v46 )
        {
          *(_WORD *)(result + 5816) |= *(_WORD *)(a2 + 4 * v14 + 1028) << v7;
          *(_DWORD *)(result + 5820) = v46 + v7;
        }
        else
        {
          v15 = *(unsigned __int16 *)(a2 + 4 * v14 + 1028);
          v16 = v15 << v7;
          v17 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5816) |= v16;
          *(_BYTE *)(v17 + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5816);
          *(_BYTE *)(*(_DWORD *)(result + 20) + *(_DWORD *)(result + 8)) = *(_BYTE *)(result + 5817);
          v18 = *(_DWORD *)(result + 5820);
          ++*(_DWORD *)(result + 20);
          LOWORD(v15) = (unsigned __int16)v15 >> (16 - v18);
          *(_DWORD *)(result + 5820) = v18 + v46 - 16;
          v14 = v47;
          *(_WORD *)(result + 5816) = v15;
        }
        v19 = extra_lbits[v14];
        v3 = a2;
        if ( v19 != 0 )
        {
          v20 = v6 - base_length[v14];
          v21 = *(_DWORD *)(result + 5820);
          if ( v21 <= 16 - v19 )
          {
            *(_WORD *)(result + 5816) |= v20 << v21;
            v25 = v19 + v21;
          }
          else
          {
            v22 = v20 << v21;
            v23 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5816) |= v22;
            *(_BYTE *)(v23 + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5816);
            *(_BYTE *)(*(_DWORD *)(result + 20) + *(_DWORD *)(result + 8)) = *(_BYTE *)(result + 5817);
            v24 = *(_DWORD *)(result + 5820);
            ++*(_DWORD *)(result + 20);
            v3 = a2;
            v25 = v24 + v19 - 16;
            *(_WORD *)(result + 5816) = (unsigned __int16)v20 >> (16 - v24);
          }
          *(_DWORD *)(result + 5820) = v25;
        }
        v26 = v5 - 1;
        if ( v26 >= 0x100 )
          v27 = (unsigned __int8)byte_481FF0[v26 >> 7];
        else
          v27 = (unsigned __int8)_dist_code[v26];
        v28 = *(unsigned __int16 *)(a3 + 4 * v27 + 2);
        v29 = *(_DWORD *)(result + 5820);
        v48 = v28;
        if ( v29 <= 16 - v28 )
        {
          *(_WORD *)(result + 5816) |= *(_WORD *)(a3 + 4 * v27) << v29;
          *(_DWORD *)(result + 5820) = v28 + v29;
        }
        else
        {
          v30 = *(_WORD *)(a3 + 4 * v27);
          v31 = v30 << v29;
          v32 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5816) |= v31;
          *(_BYTE *)(v32 + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5816);
          *(_BYTE *)(*(_DWORD *)(result + 20) + *(_DWORD *)(result + 8)) = *(_BYTE *)(result + 5817);
          v33 = *(_DWORD *)(result + 5820);
          ++*(_DWORD *)(result + 20);
          v3 = a2;
          *(_DWORD *)(result + 5820) = v33 + v48 - 16;
          *(_WORD *)(result + 5816) = v30 >> (16 - v33);
        }
        v34 = extra_dbits[v27];
        if ( v34 == 0 )
          goto LABEL_25;
        v35 = *(_DWORD *)(result + 5820);
        v36 = v26 - base_dist[v27];
        if ( v35 <= 16 - v34 )
        {
          *(_WORD *)(result + 5816) |= v36 << v35;
          v13 = v34 + v35;
        }
        else
        {
          v37 = v36 << v35;
          v38 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5816) |= v37;
          *(_BYTE *)(v38 + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5816);
          *(_BYTE *)(*(_DWORD *)(result + 20) + *(_DWORD *)(result + 8)) = *(_BYTE *)(result + 5817);
          v39 = *(_DWORD *)(result + 5820);
          ++*(_DWORD *)(result + 20);
          v13 = v39 + v34 - 16;
          *(_WORD *)(result + 5816) = (unsigned __int16)v36 >> (16 - v39);
        }
      }
      else
      {
        v8 = *(unsigned __int16 *)(v3 + 4 * v6 + 2);
        if ( v7 <= 16 - v8 )
        {
          *(_WORD *)(result + 5816) |= *(_WORD *)(v3 + 4 * v6) << v7;
          v13 = v8 + v7;
        }
        else
        {
          v9 = *(unsigned __int16 *)(v3 + 4 * v6);
          v10 = v9 << v7;
          v11 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5816) |= v10;
          *(_BYTE *)(v11 + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5816);
          *(_BYTE *)(*(_DWORD *)(result + 20) + *(_DWORD *)(result + 8)) = *(_BYTE *)(result + 5817);
          v12 = *(_DWORD *)(result + 5820);
          ++*(_DWORD *)(result + 20);
          v13 = v12 + v8 - 16;
          *(_WORD *)(result + 5816) = (unsigned __int16)v9 >> (16 - v12);
        }
      }
      *(_DWORD *)(result + 5820) = v13;
LABEL_25:
      v4 = v49;
    }
    while ( v49 < *(_DWORD *)(result + 5792) );
  }
  v40 = *(unsigned __int16 *)(v3 + 1026);
  v41 = *(_DWORD *)(result + 5820);
  if ( v41 <= 16 - v40 )
  {
    *(_WORD *)(result + 5816) |= *(_WORD *)(v3 + 1024) << v41;
    *(_DWORD *)(result + 5820) = v40 + v41;
  }
  else
  {
    v42 = *(_WORD *)(v3 + 1024);
    v43 = v42 << v41;
    v44 = *(_DWORD *)(result + 8);
    *(_WORD *)(result + 5816) |= v43;
    *(_BYTE *)(v44 + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5816);
    *(_BYTE *)(*(_DWORD *)(result + 8) + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5817);
    v45 = *(_DWORD *)(result + 5820);
    ++*(_DWORD *)(result + 20);
    *(_DWORD *)(result + 5820) = v45 + v40 - 16;
    *(_WORD *)(result + 5816) = v42 >> (16 - v45);
  }
  *(_DWORD *)(result + 5812) = *(unsigned __int16 *)(v3 + 1026);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004535A0
// Name: set_data_type
// Source: json
//------------------------------------------------------------------------------
int __fastcall set_data_type(int a1, _WORD *a2)
{
  int result; // eax
  _WORD *v3; // ecx
  _WORD *i; // ecx

  result = 0;
  v3 = a2 + 74;
  do
  {
    if ( *v3 != 0 )
      break;
    ++result;
    v3 += 2;
  }
  while ( result < 9 );
  if ( result == 9 )
  {
    result = 14;
    for ( i = a2 + 104; *(i - 2) == 0; i += 12 )
    {
      if ( *i != 0 )
      {
        *(_DWORD *)(*(_DWORD *)a2 + 44) = ++result == 32;
        return result;
      }
      if ( i[2] != 0 )
      {
        result += 2;
        *(_DWORD *)(*(_DWORD *)a2 + 44) = result == 32;
        return result;
      }
      if ( i[4] != 0 )
      {
        result += 3;
        *(_DWORD *)(*(_DWORD *)a2 + 44) = result == 32;
        return result;
      }
      if ( i[6] != 0 )
      {
        result += 4;
        *(_DWORD *)(*(_DWORD *)a2 + 44) = result == 32;
        return result;
      }
      if ( i[8] != 0 )
      {
        result += 5;
        break;
      }
      result += 6;
      if ( result >= 32 )
      {
        *(_DWORD *)(*(_DWORD *)a2 + 44) = result == 32;
        return result;
      }
    }
  }
  *(_DWORD *)(*(_DWORD *)a2 + 44) = result == 32;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00453670
// Name: bi_reverse
// Source: json
//------------------------------------------------------------------------------
unsigned int __fastcall bi_reverse(unsigned int a1, int a2)
{
  unsigned int v2; // eax
  int v3; // esi

  v2 = 0;
  do
  {
    v3 = a1 & 1;
    --a2;
    a1 >>= 1;
    v2 = 2 * (v3 | v2);
  }
  while ( a2 > 0 );
  return v2 >> 1;
}

//------------------------------------------------------------------------------
// Address: 0x00453690
// Name: bi_flush
// Source: json
//------------------------------------------------------------------------------
int __usercall bi_flush@<eax>(int result@<eax>)
{
  int v1; // ecx
  __int16 v2; // dx

  v1 = *(_DWORD *)(result + 5820);
  if ( v1 == 16 )
  {
    *(_BYTE *)(*(_DWORD *)(result + 8) + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5816);
    *(_BYTE *)(*(_DWORD *)(result + 20) + *(_DWORD *)(result + 8)) = *(_BYTE *)(result + 5817);
    ++*(_DWORD *)(result + 20);
    *(_WORD *)(result + 5816) = 0;
    *(_DWORD *)(result + 5820) = 0;
  }
  else if ( v1 >= 8 )
  {
    *(_BYTE *)(*(_DWORD *)(result + 8) + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5816);
    v2 = *(unsigned __int8 *)(result + 5817);
    ++*(_DWORD *)(result + 20);
    *(_DWORD *)(result + 5820) -= 8;
    *(_WORD *)(result + 5816) = v2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00453710
// Name: bi_windup
// Source: json
//------------------------------------------------------------------------------
int __usercall bi_windup@<eax>(int result@<eax>)
{
  int v1; // ecx
  int v2; // ecx
  int v3; // edx
  char v4; // bl

  v1 = *(_DWORD *)(result + 5820);
  if ( v1 > 8 )
  {
    *(_BYTE *)(*(_DWORD *)(result + 8) + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5816);
    v2 = *(_DWORD *)(result + 20);
    v3 = *(_DWORD *)(result + 8);
    v4 = *(_BYTE *)(result + 5817);
LABEL_5:
    *(_BYTE *)(v2 + v3) = v4;
    ++*(_DWORD *)(result + 20);
    goto LABEL_6;
  }
  if ( v1 > 0 )
  {
    v2 = *(_DWORD *)(result + 8);
    v3 = *(_DWORD *)(result + 20);
    v4 = *(_BYTE *)(result + 5816);
    goto LABEL_5;
  }
LABEL_6:
  *(_WORD *)(result + 5816) = 0;
  *(_DWORD *)(result + 5820) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00453770
// Name: copy_block
// Source: json
//------------------------------------------------------------------------------
_DWORD *__usercall copy_block@<eax>(int a1@<eax>, _BYTE *a2@<edx>, int a3@<ecx>, int a4)
{
  _DWORD *result; // eax

  result = (_DWORD *)bi_windup(result: a1);
  result[1453] = 8;
  if ( a4 != 0 )
  {
    *(_BYTE *)(result[5] + result[2]) = a3;
    ++result[5];
    *(_BYTE *)(result[2] + result[5]++) = BYTE1(a3);
    *(_BYTE *)(result[2] + result[5]++) = ~(_BYTE)a3;
    *(_BYTE *)(result[2] + result[5]++) = (unsigned __int16)~(_WORD)a3 >> 8;
  }
  for ( ; a3 != 0; ++a2 )
  {
    *(_BYTE *)(result[5] + result[2]) = *a2;
    --a3;
    ++result[5];
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00453870
// Name: gen_codes
// Source: json
//------------------------------------------------------------------------------
signed int __usercall gen_codes@<eax>(int a1@<edx>, int a2@<ebx>, int a3@<edi>)
{
  __int16 v3; // cx
  signed int result; // eax
  int v5; // edx
  int i; // esi
  int v7; // edx
  unsigned __int16 v8; // ax
  __int16 v9; // [esp+4h] [ebp-24h]
  char v10; // [esp+6h] [ebp-22h] BYREF

  v3 = 0;
  result = 1;
  v5 = a1 - (_DWORD)&v10;
  do
  {
    v3 = 2 * (v3 + *(__int16 *)((char *)&v9 + 2 * result + v5));
    *(&v9 + result++) = v3;
  }
  while ( result <= 15 );
  for ( i = 0; i <= a2; ++i )
  {
    v7 = *(unsigned __int16 *)(a3 + 4 * i + 2);
    if ( *(_WORD *)(a3 + 4 * i + 2) != 0 )
    {
      v8 = *(&v9 + v7);
      *(&v9 + v7) = v8 + 1;
      result = bi_reverse(a1: v8, a2: v7);
      *(_WORD *)(a3 + 4 * i) = result;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004538F0
// Name: build_tree
// Source: json
//------------------------------------------------------------------------------
signed int __usercall build_tree@<eax>(_DWORD *a1@<esi>, int *a2)
{
  int v2; // edi
  int *v3; // eax
  int v4; // ecx
  int v5; // edx
  int v6; // ebp
  int v7; // eax
  int v8; // eax
  int i; // ebp
  int v10; // ebx
  int v11; // eax
  int v12; // edx
  int v13; // ebp
  int v14; // eax
  unsigned __int8 v15; // cl
  int v17; // [esp+Ch] [ebp-8h]
  int v18; // [esp+10h] [ebp-4h]

  v2 = *a2;
  v3 = (int *)a2[2];
  v4 = v3[3];
  v5 = *v3;
  v6 = -1;
  v7 = 0;
  v18 = v4;
  v17 = -1;
  a1[1300] = 0;
  for ( a1[1301] = 573; v7 < v4; ++v7 )
  {
    if ( *(_WORD *)(v2 + 4 * v7) != 0 )
    {
      a1[++a1[1300] + 727] = v7;
      v17 = v7;
      *((_BYTE *)a1 + v7 + 5208) = 0;
      v6 = v7;
    }
    else
    {
      *(_WORD *)(v2 + 4 * v7 + 2) = 0;
    }
  }
  if ( (int)a1[1300] < 2 )
  {
    do
    {
      if ( v6 >= 2 )
        v8 = 0;
      else
        v8 = ++v6;
      a1[++a1[1300] + 727] = v8;
      *(_WORD *)(v2 + 4 * v8) = 1;
      *((_BYTE *)a1 + v8 + 5208) = 0;
      --a1[1450];
      if ( v5 != 0 )
        a1[1451] -= *(unsigned __int16 *)(v5 + 4 * v8 + 2);
    }
    while ( (int)a1[1300] < 2 );
    v17 = v6;
  }
  a2[1] = v6;
  for ( i = a1[1300] / 2; i >= 1; --i )
    pqdownheap(result: (int)a1, a2: v2, a3: i);
  v10 = v18;
  do
  {
    v11 = a1[1300];
    v12 = a1[v11 + 727];
    v13 = a1[728];
    a1[1300] = v11 - 1;
    a1[728] = v12;
    pqdownheap(result: (int)a1, a2: v2, a3: 1);
    v14 = a1[728];
    --a1[1301];
    a1[a1[1301]-- + 727] = v13;
    a1[a1[1301] + 727] = v14;
    *(_WORD *)(v2 + 4 * v10) = *(_WORD *)(v2 + 4 * v13) + *(_WORD *)(v2 + 4 * v14);
    v15 = *((_BYTE *)a1 + v14 + 5208);
    if ( *((_BYTE *)a1 + v13 + 5208) >= v15 )
      v15 = *((_BYTE *)a1 + v13 + 5208);
    *((_BYTE *)a1 + v10 + 5208) = v15 + 1;
    *(_WORD *)(v2 + 4 * v14 + 2) = v10;
    *(_WORD *)(v2 + 4 * v13 + 2) = v10;
    a1[728] = v10++;
    pqdownheap(result: (int)a1, a2: v2, a3: 1);
  }
  while ( (int)a1[1300] >= 2 );
  a1[--a1[1301] + 727] = a1[728];
  gen_bitlen(result: a1, a2);
  return gen_codes(a1: (int)(a1 + 719), a2: v17, a3: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00453AF0
// Name: build_bl_tree
// Source: json
//------------------------------------------------------------------------------
int __usercall build_bl_tree@<eax>(int a1@<eax>)
{
  int result; // eax

  scan_tree(result: a1 + 148, a2: *(_DWORD *)(a1 + 2844), a3: (_WORD *)a1);
  scan_tree(result: a1 + 2440, a2: *(_DWORD *)(a1 + 2856), a3: (_WORD *)a1);
  build_tree((_DWORD *)a1, a2: (int *)(a1 + 2864));
  result = 18;
  while ( *(_WORD *)(a1 + 4 * (unsigned __int8)bl_order[result] + 2686) == 0 )
  {
    if ( *(_WORD *)(a1 + 4 * (unsigned __int8)byte_48191B[result] + 2686) != 0 )
    {
      --result;
      *(_DWORD *)(a1 + 5800) += 3 * result + 17;
      return result;
    }
    if ( *(_WORD *)(a1 + 4 * (unsigned __int8)byte_48191A[result] + 2686) != 0 )
    {
      result -= 2;
      *(_DWORD *)(a1 + 5800) += 3 * result + 17;
      return result;
    }
    if ( *(_WORD *)(a1 + 4 * (unsigned __int8)byte_481919[result] + 2686) != 0 )
    {
      result -= 3;
      break;
    }
    result -= 4;
    if ( result < 3 )
    {
      *(_DWORD *)(a1 + 5800) += 3 * result + 17;
      return result;
    }
  }
  *(_DWORD *)(a1 + 5800) += 3 * result + 17;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00453800
// Name: __tr_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _tr_init(int a1)
{
  *(_DWORD *)(a1 + 2840) = a1 + 148;
  *(_DWORD *)(a1 + 2852) = a1 + 2440;
  *(_DWORD *)(a1 + 2848) = &static_l_desc;
  *(_DWORD *)(a1 + 2860) = &static_d_desc;
  *(_DWORD *)(a1 + 2864) = a1 + 2684;
  *(_DWORD *)(a1 + 2872) = &static_bl_desc;
  *(_WORD *)(a1 + 5816) = 0;
  *(_DWORD *)(a1 + 5820) = 0;
  *(_DWORD *)(a1 + 5812) = 8;
  return init_block(a1: 0, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x00453BC0
// Name: __tr_stored_block
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__cdecl _tr_stored_block(int a1, _BYTE *a2, int a3, int a4)
{
  int v4; // ecx
  int v5; // edx
  int v6; // ecx
  char v7; // bl
  int v8; // edx

  v4 = *(_DWORD *)(a1 + 5820);
  if ( v4 <= 13 )
  {
    *(_DWORD *)(a1 + 5820) = v4 + 3;
    *(_WORD *)(a1 + 5816) |= a4 << v4;
  }
  else
  {
    v5 = a4 << v4;
    v6 = *(_DWORD *)(a1 + 8);
    *(_WORD *)(a1 + 5816) |= v5;
    *(_BYTE *)(v6 + *(_DWORD *)(a1 + 20)) = *(_BYTE *)(a1 + 5816);
    v7 = *(_BYTE *)(a1 + 5817);
    *(_BYTE *)(++*(_DWORD *)(a1 + 20) + *(_DWORD *)(a1 + 8)) = v7;
    v8 = *(_DWORD *)(a1 + 5820);
    ++*(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 5820) = v8 - 13;
    *(_WORD *)(a1 + 5816) = (unsigned __int16)a4 >> (16 - v8);
  }
  return copy_block(a1, a2, a3, a4: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00453C60
// Name: __tr_align
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _tr_align(int a1)
{
  int v1; // ecx
  int v2; // edx
  int v3; // ecx
  int v4; // edx
  int result; // eax
  int v6; // ecx
  int v7; // edx
  int v8; // ecx
  int v9; // edx

  v1 = *(_DWORD *)(a1 + 5820);
  *(_WORD *)(a1 + 5816) |= 2 << v1;
  if ( v1 <= 13 )
  {
    *(_DWORD *)(a1 + 5820) = v1 + 3;
  }
  else
  {
    *(_BYTE *)(*(_DWORD *)(a1 + 8) + (*(_DWORD *)(a1 + 20))++) = *(_BYTE *)(a1 + 5816);
    *(_BYTE *)(*(_DWORD *)(a1 + 20) + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5817);
    v2 = *(_DWORD *)(a1 + 5820);
    ++*(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 5820) = v2 - 13;
    *(_WORD *)(a1 + 5816) = 2u >> (16 - v2);
  }
  v3 = *(_DWORD *)(a1 + 5820);
  *(_WORD *)(a1 + 5816) = *(_WORD *)(a1 + 5816);
  if ( v3 <= 9 )
  {
    *(_DWORD *)(a1 + 5820) = v3 + 7;
  }
  else
  {
    *(_BYTE *)(*(_DWORD *)(a1 + 8) + (*(_DWORD *)(a1 + 20))++) = *(_BYTE *)(a1 + 5816);
    *(_BYTE *)(*(_DWORD *)(a1 + 20) + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5817);
    v4 = *(_DWORD *)(a1 + 5820);
    ++*(_DWORD *)(a1 + 20);
    *(_DWORD *)(a1 + 5820) = v4 - 9;
    *(_WORD *)(a1 + 5816) = 0;
  }
  result = bi_flush(result: a1);
  v6 = *(_DWORD *)(result + 5820);
  if ( *(_DWORD *)(result + 5812) - v6 + 11 < 9 )
  {
    *(_WORD *)(result + 5816) |= 2 << v6;
    if ( v6 <= 13 )
    {
      *(_DWORD *)(result + 5820) = v6 + 3;
    }
    else
    {
      *(_BYTE *)(*(_DWORD *)(result + 8) + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5816);
      *(_BYTE *)(*(_DWORD *)(result + 20) + *(_DWORD *)(result + 8)) = *(_BYTE *)(result + 5817);
      v7 = *(_DWORD *)(result + 5820);
      ++*(_DWORD *)(result + 20);
      *(_DWORD *)(result + 5820) = v7 - 13;
      *(_WORD *)(result + 5816) = 2u >> (16 - v7);
    }
    v8 = *(_DWORD *)(result + 5820);
    *(_WORD *)(result + 5816) = *(_WORD *)(result + 5816);
    if ( v8 > 9 )
    {
      *(_BYTE *)(*(_DWORD *)(result + 8) + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5816);
      *(_BYTE *)(*(_DWORD *)(result + 20) + *(_DWORD *)(result + 8)) = *(_BYTE *)(result + 5817);
      v9 = *(_DWORD *)(result + 5820);
      ++*(_DWORD *)(result + 20);
      *(_DWORD *)(result + 5820) = v9 - 9;
      *(_WORD *)(result + 5816) = 0;
      result = bi_flush(result);
      *(_DWORD *)(result + 5812) = 7;
      return result;
    }
    *(_DWORD *)(result + 5820) = v8 + 7;
    result = bi_flush(result);
  }
  *(_DWORD *)(result + 5812) = 7;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00453E50
// Name: __tr_flush_block
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _tr_flush_block(int a1, _BYTE *a2, int a3, int a4)
{
  int v4; // ecx
  int v5; // eax
  unsigned int v6; // edx
  unsigned int v7; // ecx
  int v8; // edi
  int v9; // ecx
  int v10; // ecx
  int v11; // edx
  int v12; // eax
  int v13; // ecx
  int v14; // ebx
  int v15; // ecx
  int v16; // eax
  int v17; // edx
  int v18; // ecx
  int v19; // edx
  int result; // eax
  int v21; // [esp+Ch] [ebp-4h]

  v21 = 0;
  if ( *(int *)(a1 + 132) <= 0 )
  {
    v7 = a3 + 5;
LABEL_8:
    v6 = v7;
    goto LABEL_9;
  }
  if ( a3 != 0 && *(_DWORD *)(*(_DWORD *)a1 + 44) == 2 )
    set_data_type(a1: v4, a2: (_WORD *)a1);
  build_tree((_DWORD *)a1, a2: (int *)(a1 + 2840));
  build_tree((_DWORD *)a1, a2: (int *)(a1 + 2852));
  v5 = build_bl_tree(a1);
  v6 = (unsigned int)(*(_DWORD *)(a1 + 5800) + 10) >> 3;
  v7 = (unsigned int)(*(_DWORD *)(a1 + 5804) + 10) >> 3;
  v21 = v5;
  if ( v7 <= v6 )
    goto LABEL_8;
LABEL_9:
  if ( a3 + 4 <= v6 && a2 != nullptr )
  {
    v8 = a4;
    _tr_stored_block(a1, a2, a3, a4);
  }
  else if ( *(_DWORD *)(a1 + 136) == 4 || v7 == v6 )
  {
    v15 = *(_DWORD *)(a1 + 5820);
    v8 = a4;
    v16 = a4 + 2;
    if ( v15 <= 13 )
    {
      *(_WORD *)(a1 + 5816) |= v16 << v15;
      *(_DWORD *)(a1 + 5820) = v15 + 3;
    }
    else
    {
      v17 = v16 << v15;
      v18 = *(_DWORD *)(a1 + 8);
      *(_WORD *)(a1 + 5816) |= v17;
      *(_BYTE *)(v18 + (*(_DWORD *)(a1 + 20))++) = *(_BYTE *)(a1 + 5816);
      *(_BYTE *)(*(_DWORD *)(a1 + 20) + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5817);
      v19 = *(_DWORD *)(a1 + 5820);
      ++*(_DWORD *)(a1 + 20);
      *(_DWORD *)(a1 + 5820) = v19 - 13;
      *(_WORD *)(a1 + 5816) = (unsigned __int16)v16 >> (16 - v19);
    }
    compress_block(result: a1, a2: (int)&static_ltree, a3: (int)&static_dtree);
  }
  else
  {
    v10 = *(_DWORD *)(a1 + 5820);
    v8 = a4;
    v11 = a4 + 4;
    if ( v10 <= 13 )
    {
      *(_WORD *)(a1 + 5816) |= v11 << v10;
      *(_DWORD *)(a1 + 5820) = v10 + 3;
    }
    else
    {
      v12 = v11 << v10;
      v13 = *(_DWORD *)(a1 + 8);
      *(_WORD *)(a1 + 5816) |= v12;
      *(_BYTE *)(v13 + (*(_DWORD *)(a1 + 20))++) = *(_BYTE *)(a1 + 5816);
      *(_BYTE *)(*(_DWORD *)(a1 + 20) + *(_DWORD *)(a1 + 8)) = *(_BYTE *)(a1 + 5817);
      v14 = *(_DWORD *)(a1 + 5820);
      ++*(_DWORD *)(a1 + 20);
      *(_DWORD *)(a1 + 5820) = v14 - 13;
      *(_WORD *)(a1 + 5816) = (unsigned __int16)v11 >> (16 - v14);
    }
    send_all_trees(a1, a2: *(_DWORD *)(a1 + 2844) + 1, a3: *(_DWORD *)(a1 + 2856) + 1, a4: v21 + 1);
    compress_block(result: a1, a2: a1 + 148, a3: a1 + 2440);
  }
  result = init_block(a1: v9, a2: a1);
  if ( v8 != 0 )
    return bi_windup(result: a1);
  return result;
}
