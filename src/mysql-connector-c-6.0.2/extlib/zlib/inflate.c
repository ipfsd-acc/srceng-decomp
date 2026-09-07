// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/extlib/zlib/inflate.c
// Functions: 7
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0044F700
// Name: _inflateReset
// Source: json
//------------------------------------------------------------------------------
int __cdecl inflateReset(_DWORD *a1)
{
  _DWORD *v1; // eax

  if ( a1 == nullptr )
    return -2;
  v1 = (_DWORD *)a1[7];
  if ( v1 == nullptr )
    return -2;
  v1[7] = 0;
  a1[5] = 0;
  a1[2] = 0;
  a1[6] = 0;
  a1[12] = 1;
  *v1 = 0;
  v1[1] = 0;
  v1[3] = 0;
  v1[8] = 0;
  v1[10] = 0;
  v1[11] = 0;
  v1[12] = 0;
  v1[14] = 0;
  v1[15] = 0;
  v1[5] = 0x8000;
  v1[27] = v1 + 332;
  v1[20] = v1 + 332;
  v1[19] = v1 + 332;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0044F760
// Name: _inflateInit2_
// Source: json
//------------------------------------------------------------------------------
int __cdecl inflateInit2_(_DWORD *a1, int a2, _BYTE *a3, int a4)
{
  _DWORD *v4; // eax
  int v6; // ecx

  if ( a3 == nullptr || *a3 != 49 || a4 != 56 )
    return -6;
  if ( a1 != nullptr )
  {
    a1[6] = 0;
    if ( a1[8] == 0 )
    {
      a1[8] = zcalloc;
      a1[10] = 0;
    }
    if ( a1[9] == 0 )
      a1[9] = zcfree;
    v4 = (_DWORD *)((int (__cdecl *)(_DWORD, int, int))a1[8])(a1: a1[10], a2: 1, a3: 9520);
    if ( v4 == nullptr )
      return -4;
    v6 = a2;
    a1[7] = v4;
    if ( a2 >= 0 )
    {
      v4[2] = (a2 >> 4) + 1;
      if ( a2 < 48 )
        v6 = a2 & 0xF;
    }
    else
    {
      v4[2] = 0;
      v6 = -a2;
    }
    if ( (unsigned int)(v6 - 8) <= 7 )
    {
      v4[9] = v6;
      v4[13] = 0;
      return inflateReset(a1);
    }
    ((void (__cdecl *)(_DWORD, _DWORD *))a1[9])(a1: a1[10], a2: v4);
    a1[7] = 0;
  }
  return -2;
}

//------------------------------------------------------------------------------
// Address: 0x0044F830
// Name: _inflateInit_
// Source: json
//------------------------------------------------------------------------------
int __cdecl inflateInit_(_DWORD *a1, _BYTE *a2, int a3)
{
  return inflateInit2_(a1, a2: 15, a3: a2, a4: a3);
}

//------------------------------------------------------------------------------
// Address: 0x0044F850
// Name: fixedtables
// Source: json
//------------------------------------------------------------------------------
_DWORD *__usercall fixedtables@<eax>(_DWORD *result@<eax>)
{
  result[19] = "`\a";
  result[21] = 9;
  result[20] = &unk_481380;
  result[22] = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044F870
// Name: updatewindow
// Source: json
//------------------------------------------------------------------------------
int __usercall updatewindow@<eax>(int a1@<eax>, int a2@<ebx>)
{
  int v2; // esi
  int v4; // eax
  int v6; // ecx
  unsigned int v7; // edi
  unsigned int v8; // eax
  int v9; // eax
  unsigned int v10; // ebp
  unsigned int v11; // edi
  int v12; // edx
  unsigned int v13; // eax
  unsigned int v14; // ecx

  v2 = *(_DWORD *)(a2 + 28);
  if ( *(_DWORD *)(v2 + 52) == 0 )
  {
    v4 = (*(int (__cdecl **)(_DWORD, int, int))(a2 + 32))(
           a1: *(_DWORD *)(a2 + 40),
           a2: 1 << *(_DWORD *)(v2 + 36),
           a3: 1);
    *(_DWORD *)(v2 + 52) = v4;
    if ( v4 == 0 )
      return 1;
  }
  if ( *(_DWORD *)(v2 + 40) == 0 )
  {
    v6 = *(_DWORD *)(v2 + 36);
    *(_DWORD *)(v2 + 48) = 0;
    *(_DWORD *)(v2 + 44) = 0;
    *(_DWORD *)(v2 + 40) = 1 << v6;
  }
  v7 = a1 - *(_DWORD *)(a2 + 16);
  v8 = *(_DWORD *)(v2 + 40);
  if ( v7 < v8 )
  {
    v10 = v8 - *(_DWORD *)(v2 + 48);
    if ( v10 > v7 )
      v10 = v7;
    memcpy(
      dst: (unsigned __int8 *)(*(_DWORD *)(v2 + 48) + *(_DWORD *)(v2 + 52)),
      src: (unsigned __int8 *)(*(_DWORD *)(a2 + 12) - v7),
      count: v10);
    v11 = v7 - v10;
    if ( v11 != 0 )
    {
      memcpy(dst: *(unsigned __int8 **)(v2 + 52), src: (unsigned __int8 *)(*(_DWORD *)(a2 + 12) - v11), count: v11);
      v12 = *(_DWORD *)(v2 + 40);
      *(_DWORD *)(v2 + 48) = v11;
      *(_DWORD *)(v2 + 44) = v12;
      return 0;
    }
    else
    {
      *(_DWORD *)(v2 + 48) += v10;
      v13 = *(_DWORD *)(v2 + 40);
      if ( *(_DWORD *)(v2 + 48) == v13 )
        *(_DWORD *)(v2 + 48) = 0;
      v14 = *(_DWORD *)(v2 + 44);
      if ( v14 < v13 )
        *(_DWORD *)(v2 + 44) = v10 + v14;
      return 0;
    }
  }
  else
  {
    memcpy(
      dst: *(unsigned __int8 **)(v2 + 52),
      src: (unsigned __int8 *)(*(_DWORD *)(a2 + 12) - v8),
      count: *(_DWORD *)(v2 + 40));
    v9 = *(_DWORD *)(v2 + 40);
    *(_DWORD *)(v2 + 48) = 0;
    *(_DWORD *)(v2 + 44) = v9;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044F960
// Name: _inflate
// Source: json
//------------------------------------------------------------------------------
int __cdecl inflate(int a1, int a2)
{
  int *v2; // edi
  unsigned int v3; // edx
  unsigned int v4; // ebx
  unsigned __int8 *v5; // ebp
  int v6; // eax
  unsigned int v7; // esi
  int v8; // eax
  int v9; // eax
  int v10; // eax
  unsigned int v11; // ecx
  int v12; // eax
  int v13; // eax
  _DWORD *v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  unsigned int v26; // eax
  int v27; // ecx
  unsigned int v28; // edx
  int v29; // eax
  unsigned int v30; // eax
  int v31; // ecx
  int v32; // eax
  unsigned int v33; // ecx
  int v34; // eax
  int v35; // eax
  unsigned int v36; // eax
  int v37; // ecx
  int v38; // eax
  unsigned int v39; // ecx
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // eax
  int v45; // eax
  int v46; // eax
  int v47; // eax
  int v48; // ecx
  int v49; // eax
  char v50; // cl
  unsigned int v51; // ebx
  unsigned int v52; // esi
  int v53; // ecx
  int v54; // eax
  int v55; // eax
  unsigned int v56; // eax
  int v57; // eax
  int v58; // ecx
  unsigned int v59; // ebx
  char v60; // al
  unsigned int v61; // eax
  int v62; // ecx
  bool v63; // cc
  int v64; // eax
  int v65; // eax
  unsigned int v66; // eax
  int v67; // eax
  unsigned __int8 *v68; // ecx
  int v69; // eax
  int v70; // eax
  int v71; // ecx
  int v72; // eax
  unsigned __int8 *v73; // ecx
  int v74; // eax
  unsigned int v75; // ebx
  int v76; // eax
  int v77; // eax
  unsigned int v78; // ebx
  __int16 v79; // ax
  int v80; // ecx
  int v81; // eax
  unsigned __int8 *v82; // ecx
  int v83; // edx
  unsigned int v84; // eax
  unsigned int v85; // eax
  int v86; // eax
  int v87; // eax
  unsigned int v88; // eax
  int v89; // eax
  int v90; // ecx
  unsigned int v91; // eax
  int v92; // eax
  int v93; // eax
  unsigned int v94; // eax
  int v95; // eax
  int v96; // ecx
  unsigned int v97; // eax
  unsigned int v98; // eax
  unsigned int v99; // ecx
  int v100; // ecx
  unsigned int v101; // ecx
  unsigned __int8 *v102; // ecx
  unsigned int v103; // ecx
  unsigned __int8 *v104; // eax
  unsigned __int8 v105; // cl
  bool v106; // zf
  unsigned __int8 *v107; // eax
  int v108; // eax
  int v109; // eax
  int v110; // eax
  int v111; // eax
  int v112; // eax
  int result; // eax
  unsigned int v114; // ebp
  int v115; // ebx
  int v116; // eax
  int v117; // [esp-1Ch] [ebp-4Ch]
  int v118; // [esp-18h] [ebp-48h]
  unsigned __int8 *v119; // [esp-14h] [ebp-44h]
  unsigned int v120; // [esp+4h] [ebp-2Ch]
  unsigned int count; // [esp+8h] [ebp-28h]
  unsigned int counta; // [esp+8h] [ebp-28h]
  unsigned int countb; // [esp+8h] [ebp-28h]
  unsigned int countc; // [esp+8h] [ebp-28h]
  unsigned int countd; // [esp+8h] [ebp-28h]
  unsigned int counte; // [esp+8h] [ebp-28h]
  unsigned int countf; // [esp+8h] [ebp-28h]
  unsigned int countg; // [esp+8h] [ebp-28h]
  unsigned int counth; // [esp+8h] [ebp-28h]
  unsigned int counti; // [esp+8h] [ebp-28h]
  unsigned int countj; // [esp+8h] [ebp-28h]
  unsigned int v132; // [esp+Ch] [ebp-24h]
  unsigned int v133; // [esp+10h] [ebp-20h] BYREF
  int v134; // [esp+14h] [ebp-1Ch]
  unsigned __int8 *dst; // [esp+18h] [ebp-18h]
  int v136; // [esp+1Ch] [ebp-14h]
  unsigned __int8 *v137; // [esp+20h] [ebp-10h]
  int v138; // [esp+24h] [ebp-Ch]
  unsigned int v139; // [esp+28h] [ebp-8h]
  unsigned int v140; // [esp+2Ch] [ebp-4h]

  if ( a1 == 0 )
    return -2;
  v2 = *(int **)(a1 + 28);
  if ( v2 == nullptr || *(_DWORD *)(a1 + 12) == 0 || *(_DWORD *)a1 == 0 && *(_DWORD *)(a1 + 4) != 0 )
    return -2;
  if ( *v2 == 11 )
    *v2 = 12;
  v3 = *(_DWORD *)(a1 + 4);
  v4 = v2[14];
  v5 = *(unsigned __int8 **)a1;
  dst = *(unsigned __int8 **)(a1 + 12);
  v6 = *v2;
  v7 = v2[15];
  v132 = *(_DWORD *)(a1 + 16);
  v120 = v3;
  v140 = v3;
  v136 = v132;
  v138 = 0;
  while ( 2 )
  {
    switch ( v6 )
    {
      case 0:
        if ( v2[2] == 0 )
        {
          *v2 = 12;
          goto LABEL_293;
        }
        for ( ; v7 < 0x10; v120 = v3 )
        {
          if ( v3 == 0 )
            goto LABEL_301;
          v8 = *v5 << v7;
          --v3;
          v7 += 8;
          ++v5;
          v4 += v8;
        }
        if ( (v2[2] & 2) != 0 && v4 == 35615 )
        {
          v2[6] = crc32(a1: 0, a2: 0, a3: 0);
          LOWORD(v133) = -29921;
          v9 = crc32(a1: v2[6], a2: &v133, a3: 2);
          v3 = v120;
          v4 = 0;
          v2[6] = v9;
          v7 = 0;
          *v2 = 1;
          goto LABEL_293;
        }
        v10 = v2[8];
        v2[4] = 0;
        if ( v10 != 0 )
          *(_DWORD *)(v10 + 48) = -1;
        if ( (v2[2] & 1) == 0 || ((v4 >> 8) + ((unsigned __int8)v4 << 8)) % 0x1F != 0 )
        {
          *(_DWORD *)(a1 + 24) = "incorrect header check";
          v3 = v120;
          goto LABEL_292;
        }
        if ( (v4 & 0xF) != 8 )
        {
          v3 = v120;
          *(_DWORD *)(a1 + 24) = "unknown compression method";
          goto LABEL_292;
        }
        v4 >>= 4;
        v11 = (v4 & 0xF) + 8;
        v7 -= 4;
        if ( v11 > v2[9] )
        {
          v3 = v120;
          *(_DWORD *)(a1 + 24) = "invalid window size";
          goto LABEL_292;
        }
        v2[5] = 1 << v11;
        v12 = adler32(a1: 0, a2: 0, a3: 0);
        v3 = v120;
        v2[6] = v12;
        *(_DWORD *)(a1 + 48) = v12;
        *v2 = ~BYTE1(v4) & 2 | 9;
        v4 = 0;
        v7 = 0;
        goto LABEL_293;
      case 1:
        for ( ; v7 < 0x10; v120 = v3 )
        {
          if ( v3 == 0 )
            goto LABEL_301;
          v13 = *v5 << v7;
          --v3;
          v7 += 8;
          ++v5;
          v4 += v13;
        }
        v2[4] = v4;
        if ( (_BYTE)v4 != 8 )
        {
          *(_DWORD *)(a1 + 24) = "unknown compression method";
          goto LABEL_292;
        }
        if ( (v4 & 0xE000) != 0 )
        {
          *(_DWORD *)(a1 + 24) = "unknown header flags set";
          goto LABEL_292;
        }
        v14 = (_DWORD *)v2[8];
        if ( v14 != nullptr )
          *v14 = (v4 & 0x100) != 0;
        if ( (v2[4] & 0x200) != 0 )
        {
          LOBYTE(v133) = 8;
          BYTE1(v133) = BYTE1(v4);
          v15 = crc32(a1: v2[6], a2: &v133, a3: 2);
          v3 = v120;
          v2[6] = v15;
        }
        v4 = 0;
        v7 = 0;
        *v2 = 2;
        do
        {
LABEL_41:
          if ( v3 == 0 )
            goto LABEL_301;
          v16 = *v5 << v7;
          --v3;
          v7 += 8;
          ++v5;
          v4 += v16;
          v120 = v3;
        }
        while ( v7 < 0x20 );
LABEL_43:
        v17 = v2[8];
        if ( v17 != 0 )
          *(_DWORD *)(v17 + 4) = v4;
        if ( (v2[4] & 0x200) != 0 )
        {
          v133 = v4;
          v18 = crc32(a1: v2[6], a2: &v133, a3: 4);
          v3 = v120;
          v2[6] = v18;
        }
        v4 = 0;
        v7 = 0;
        *v2 = 3;
        do
        {
LABEL_49:
          if ( v3 == 0 )
            goto LABEL_301;
          v19 = *v5 << v7;
          --v3;
          v7 += 8;
          ++v5;
          v4 += v19;
          v120 = v3;
        }
        while ( v7 < 0x10 );
LABEL_51:
        v20 = v2[8];
        if ( v20 != 0 )
        {
          *(_DWORD *)(v20 + 8) = (unsigned __int8)v4;
          *(_DWORD *)(v2[8] + 12) = v4 >> 8;
        }
        if ( (v2[4] & 0x200) != 0 )
        {
          LOWORD(v133) = v4;
          v21 = crc32(a1: v2[6], a2: &v133, a3: 2);
          v3 = v120;
          v2[6] = v21;
        }
        v4 = 0;
        v7 = 0;
        *v2 = 4;
LABEL_56:
        if ( (v2[4] & 0x400) != 0 )
        {
          if ( v7 < 0x10 )
          {
            while ( v3 != 0 )
            {
              v22 = *v5 << v7;
              --v3;
              v7 += 8;
              ++v5;
              v4 += v22;
              v120 = v3;
              if ( v7 >= 0x10 )
                goto LABEL_60;
            }
            goto LABEL_301;
          }
LABEL_60:
          v23 = v2[8];
          v2[16] = v4;
          if ( v23 != 0 )
            *(_DWORD *)(v23 + 20) = v4;
          if ( (v2[4] & 0x200) != 0 )
          {
            LOWORD(v133) = v4;
            v24 = crc32(a1: v2[6], a2: &v133, a3: 2);
            v3 = v120;
            v2[6] = v24;
          }
          v4 = 0;
          v7 = 0;
        }
        else
        {
          v25 = v2[8];
          if ( v25 != 0 )
            *(_DWORD *)(v25 + 16) = 0;
        }
        *v2 = 5;
LABEL_68:
        if ( (v2[4] & 0x400) != 0 )
        {
          v26 = v2[16];
          count = v26;
          if ( v26 > v3 )
          {
            v26 = v3;
            count = v3;
          }
          if ( v26 != 0 )
          {
            v27 = v2[8];
            if ( v27 != 0 )
            {
              v139 = *(_DWORD *)(v27 + 16);
              if ( v139 != 0 )
              {
                v28 = *(_DWORD *)(v2[8] + 24);
                v134 = *(_DWORD *)(v2[8] + 20) - v2[16];
                if ( v26 + v134 > v28 )
                  v26 = v28 - v134;
                memcpy(dst: (unsigned __int8 *)(v134 + v139), src: v5, count: v26);
                v26 = count;
                v3 = v120;
              }
            }
            if ( (v2[4] & 0x200) != 0 )
            {
              v29 = crc32(a1: v2[6], a2: v5, a3: count);
              v3 = v120;
              v2[6] = v29;
              v26 = count;
            }
            v3 -= v26;
            v5 += v26;
            v2[16] -= v26;
            v120 = v3;
          }
          if ( v2[16] != 0 )
            goto LABEL_301;
        }
        v2[16] = 0;
        *v2 = 6;
LABEL_82:
        if ( (v2[4] & 0x800) != 0 )
        {
          if ( v3 == 0 )
            goto LABEL_301;
          v30 = 0;
          do
          {
            v31 = v5[v30];
            counta = v30 + 1;
            v32 = v2[8];
            v134 = v31;
            if ( v32 != 0 )
            {
              v139 = *(_DWORD *)(v32 + 28);
              if ( v139 != 0 )
              {
                v33 = v2[16];
                if ( v33 < *(_DWORD *)(v32 + 32) )
                {
                  *(_BYTE *)(v139 + v33) = v134;
                  ++v2[16];
                  v3 = v120;
                }
              }
            }
            if ( v134 == 0 )
              break;
            v30 = counta;
          }
          while ( counta < v3 );
          if ( (v2[4] & 0x200) != 0 )
          {
            v34 = crc32(a1: v2[6], a2: v5, a3: counta);
            v3 = v120;
            v2[6] = v34;
          }
          v3 -= counta;
          v5 += counta;
          v120 = v3;
          if ( v134 != 0 )
            goto LABEL_301;
        }
        else
        {
          v35 = v2[8];
          if ( v35 != 0 )
            *(_DWORD *)(v35 + 28) = 0;
        }
        v2[16] = 0;
        *v2 = 7;
LABEL_98:
        if ( (v2[4] & 0x1000) != 0 )
        {
          if ( v3 == 0 )
            goto LABEL_301;
          v36 = 0;
          do
          {
            v37 = v5[v36];
            countb = v36 + 1;
            v38 = v2[8];
            v134 = v37;
            if ( v38 != 0 )
            {
              v139 = *(_DWORD *)(v38 + 36);
              if ( v139 != 0 )
              {
                v39 = v2[16];
                if ( v39 < *(_DWORD *)(v38 + 40) )
                {
                  *(_BYTE *)(v139 + v39) = v134;
                  ++v2[16];
                  v3 = v120;
                }
              }
            }
            if ( v134 == 0 )
              break;
            v36 = countb;
          }
          while ( countb < v3 );
          if ( (v2[4] & 0x200) != 0 )
          {
            v40 = crc32(a1: v2[6], a2: v5, a3: countb);
            v3 = v120;
            v2[6] = v40;
          }
          v3 -= countb;
          v5 += countb;
          v120 = v3;
          if ( v134 != 0 )
            goto LABEL_301;
        }
        else
        {
          v41 = v2[8];
          if ( v41 != 0 )
            *(_DWORD *)(v41 + 36) = 0;
        }
        *v2 = 8;
LABEL_114:
        if ( (v2[4] & 0x200) != 0 )
        {
          if ( v7 < 0x10 )
          {
            while ( v3 != 0 )
            {
              v42 = *v5 << v7;
              --v3;
              v7 += 8;
              ++v5;
              v4 += v42;
              v120 = v3;
              if ( v7 >= 0x10 )
                goto LABEL_118;
            }
            goto LABEL_301;
          }
LABEL_118:
          if ( v4 != *((unsigned __int16 *)v2 + 12) )
          {
            *(_DWORD *)(a1 + 24) = "header crc mismatch";
            goto LABEL_292;
          }
          v4 = 0;
          v7 = 0;
        }
        v43 = v2[8];
        if ( v43 != 0 )
        {
          *(_DWORD *)(v43 + 44) = (v2[4] >> 9) & 1;
          *(_DWORD *)(v2[8] + 48) = 1;
        }
        v44 = crc32(a1: 0, a2: 0, a3: 0);
        v3 = v120;
        v2[6] = v44;
        *(_DWORD *)(a1 + 48) = v44;
        *v2 = 11;
        goto LABEL_293;
      case 2:
        if ( v7 < 0x20 )
          goto LABEL_41;
        goto LABEL_43;
      case 3:
        if ( v7 < 0x10 )
          goto LABEL_49;
        goto LABEL_51;
      case 4:
        goto LABEL_56;
      case 5:
        goto LABEL_68;
      case 6:
        goto LABEL_82;
      case 7:
        goto LABEL_98;
      case 8:
        goto LABEL_114;
      case 9:
        for ( ; v7 < 0x20; v120 = v3 )
        {
          if ( v3 == 0 )
            goto LABEL_301;
          v45 = *v5 << v7;
          --v3;
          v7 += 8;
          ++v5;
          v4 += v45;
        }
        v46 = ((v4 >> 8) & 0xFF00) + (((v4 << 16) + (v4 & 0xFF00)) << 8) + HIBYTE(v4);
        v2[6] = v46;
        *(_DWORD *)(a1 + 48) = v46;
        v4 = 0;
        v7 = 0;
        *v2 = 10;
LABEL_128:
        if ( v2[3] == 0 )
        {
          *(_DWORD *)(a1 + 12) = dst;
          *(_DWORD *)a1 = v5;
          *(_DWORD *)(a1 + 16) = v132;
          *(_DWORD *)(a1 + 4) = v3;
          v2[15] = v7;
          v2[14] = v4;
          return 2;
        }
        v47 = adler32(a1: 0, a2: 0, a3: 0);
        v2[6] = v47;
        *(_DWORD *)(a1 + 48) = v47;
        v3 = v120;
        *v2 = 11;
LABEL_130:
        if ( a2 == 5 )
          goto LABEL_301;
LABEL_131:
        if ( v2[1] != 0 )
        {
          v48 = v7 & 7;
          v4 >>= v48;
          v7 -= v48;
          *v2 = 24;
        }
        else
        {
          if ( v7 < 3 )
          {
            while ( v3 != 0 )
            {
              v49 = *v5 << v7;
              --v3;
              v7 += 8;
              ++v5;
              v4 += v49;
              v120 = v3;
              if ( v7 >= 3 )
                goto LABEL_136;
            }
            goto LABEL_301;
          }
LABEL_136:
          v50 = v4;
          v51 = v4 >> 1;
          v52 = v7 - 1;
          v2[1] = v50 & 1;
          switch ( v51 & 3 )
          {
            case 0u:
              v4 = v51 >> 2;
              *v2 = 13;
              v7 = v52 - 2;
              break;
            case 1u:
              fixedtables(result: v2);
              v4 = v51 >> 2;
              *v2 = 18;
              v7 = v52 - 2;
              break;
            case 2u:
              v4 = v51 >> 2;
              *v2 = 15;
              v7 = v52 - 2;
              break;
            case 3u:
              *(_DWORD *)(a1 + 24) = "invalid block type";
              *v2 = 27;
              v4 = v51 >> 2;
              v7 = v52 - 2;
              break;
          }
        }
        goto LABEL_293;
      case 10:
        goto LABEL_128;
      case 11:
        goto LABEL_130;
      case 12:
        goto LABEL_131;
      case 13:
        v53 = v7 & 7;
        v7 -= v53;
        for ( v4 >>= v53; v7 < 0x20; v120 = v3 )
        {
          if ( v3 == 0 )
            goto LABEL_301;
          v54 = *v5 << v7;
          --v3;
          v7 += 8;
          ++v5;
          v4 += v54;
        }
        v55 = (unsigned __int16)v4;
        if ( (unsigned __int16)v4 != ~v4 >> 16 )
        {
          *(_DWORD *)(a1 + 24) = "invalid stored block lengths";
          goto LABEL_292;
        }
        v4 = 0;
        v2[16] = v55;
        v7 = 0;
        *v2 = 14;
LABEL_147:
        v56 = v2[16];
        countc = v56;
        if ( v56 == 0 )
          goto LABEL_224;
        if ( v56 > v3 )
        {
          v56 = v3;
          countc = v3;
        }
        if ( v56 > v132 )
        {
          v56 = v132;
          countc = v132;
        }
        if ( v56 == 0 )
          goto LABEL_301;
        memcpy(dst, src: v5, count: countc);
        v120 -= countc;
        v132 -= countc;
        dst += countc;
        v3 = v120;
        v5 += countc;
        v2[16] -= countc;
        goto LABEL_293;
      case 14:
        goto LABEL_147;
      case 15:
        for ( ; v7 < 0xE; v120 = v3 )
        {
          if ( v3 == 0 )
            goto LABEL_301;
          v57 = *v5 << v7;
          --v3;
          v7 += 8;
          ++v5;
          v4 += v57;
        }
        v58 = v4 & 0x1F;
        v59 = v4 >> 5;
        v60 = v59;
        v2[24] = v58 + 257;
        v59 >>= 5;
        v61 = (v60 & 0x1F) + 1;
        v62 = (v59 & 0xF) + 4;
        v4 = v59 >> 4;
        v7 -= 14;
        v63 = (unsigned int)v2[24] <= 0x11E;
        v2[25] = v61;
        v2[23] = v62;
        if ( !v63 || v61 > 0x1E )
        {
          *(_DWORD *)(a1 + 24) = "too many length or distance symbols";
          goto LABEL_292;
        }
        v2[26] = 0;
        *v2 = 16;
LABEL_160:
        if ( v2[26] < (unsigned int)v2[23] )
        {
          while ( v7 >= 3 )
          {
LABEL_164:
            *((_WORD *)v2 + (unsigned __int16)word_481400[v2[26]++] + 56) = v4 & 7;
            v4 >>= 3;
            v7 -= 3;
            if ( v2[26] >= (unsigned int)v2[23] )
              goto LABEL_165;
          }
          while ( v3 != 0 )
          {
            v64 = *v5 << v7;
            --v3;
            v7 += 8;
            ++v5;
            v4 += v64;
            v120 = v3;
            if ( v7 >= 3 )
              goto LABEL_164;
          }
          goto LABEL_301;
        }
LABEL_165:
        while ( (unsigned int)v2[26] < 0x13 )
          *((_WORD *)v2 + (unsigned __int16)word_481400[v2[26]++] + 56) = 0;
        v2[27] = (int)(v2 + 332);
        v2[19] = (int)(v2 + 332);
        v2[21] = 7;
        v65 = inflate_table(a1: 0, a2: v2 + 28, a3: 19, a4: v2 + 27, a5: v2 + 21, a6: v2 + 188);
        v3 = v120;
        v138 = v65;
        if ( v65 != 0 )
        {
          *(_DWORD *)(a1 + 24) = "invalid code lengths set";
          goto LABEL_292;
        }
        v2[26] = 0;
        *v2 = 17;
LABEL_171:
        if ( v2[26] < (unsigned int)(v2[24] + v2[25]) )
        {
          while ( 1 )
          {
            v66 = *(_DWORD *)(v2[19] + 4 * (v4 & ((1 << v2[21]) - 1)));
            countd = v66;
            if ( BYTE1(v66) > v7 )
              break;
LABEL_175:
            if ( HIWORD(v66) >= 0x10u )
            {
              if ( HIWORD(countd) == 16 )
              {
                v68 = (unsigned __int8 *)BYTE1(v66);
                v137 = (unsigned __int8 *)BYTE1(v66);
                if ( v7 < (unsigned int)BYTE1(v66) + 2 )
                {
                  while ( v3 != 0 )
                  {
                    v69 = *v5 << v7;
                    v68 = v137;
                    --v3;
                    v7 += 8;
                    v4 += v69;
                    ++v5;
                    v120 = v3;
                    if ( v7 >= (unsigned int)(v137 + 2) )
                      goto LABEL_184;
                  }
                  goto LABEL_301;
                }
LABEL_184:
                v70 = v2[26];
                v4 >>= (char)v68;
                v7 -= (unsigned int)v68;
                if ( v70 == 0 )
                {
                  *(_DWORD *)(a1 + 24) = "invalid bit length repeat";
                  goto LABEL_292;
                }
                v71 = *((unsigned __int16 *)v2 + v70 + 55);
                v72 = (v4 & 3) + 3;
                v4 >>= 2;
                v134 = v71;
                counte = v72;
                v7 -= 2;
              }
              else
              {
                v73 = (unsigned __int8 *)BYTE1(v66);
                v137 = (unsigned __int8 *)BYTE1(v66);
                if ( HIWORD(countd) == 17 )
                {
                  if ( v7 < (unsigned int)BYTE1(v66) + 3 )
                  {
                    while ( v3 != 0 )
                    {
                      v74 = *v5 << v7;
                      v73 = v137;
                      --v3;
                      v7 += 8;
                      v4 += v74;
                      ++v5;
                      v120 = v3;
                      if ( v7 >= (unsigned int)(v137 + 3) )
                        goto LABEL_190;
                    }
                    goto LABEL_301;
                  }
LABEL_190:
                  v75 = v4 >> (char)v73;
                  counte = (v75 & 7) + 3;
                  v4 = v75 >> 3;
                  v76 = -3;
                }
                else
                {
                  if ( v7 < (unsigned int)BYTE1(v66) + 7 )
                  {
                    while ( v3 != 0 )
                    {
                      v77 = *v5 << v7;
                      v73 = v137;
                      --v3;
                      v7 += 8;
                      v4 += v77;
                      ++v5;
                      v120 = v3;
                      if ( v7 >= (unsigned int)(v137 + 7) )
                        goto LABEL_194;
                    }
                    goto LABEL_301;
                  }
LABEL_194:
                  v78 = v4 >> (char)v73;
                  counte = (v78 & 0x7F) + 11;
                  v4 = v78 >> 7;
                  v76 = -7;
                }
                v7 += v76 - (_DWORD)v73;
                v72 = counte;
                v134 = 0;
              }
              if ( v72 + v2[26] > (unsigned int)(v2[24] + v2[25]) )
              {
                *(_DWORD *)(a1 + 24) = "invalid bit length repeat";
                goto LABEL_292;
              }
              if ( counte != 0 )
              {
                v79 = v134;
                do
                {
                  --counte;
                  *((_WORD *)v2 + v2[26]++ + 56) = v79;
                }
                while ( counte != 0 );
              }
            }
            else
            {
              if ( v7 < BYTE1(v66) )
              {
                while ( v3 != 0 )
                {
                  v66 = *v5 << v7;
                  --v3;
                  v7 += 8;
                  ++v5;
                  v4 += v66;
                  BYTE1(v66) = BYTE1(countd);
                  v120 = v3;
                  if ( v7 >= BYTE1(countd) )
                    goto LABEL_179;
                }
                goto LABEL_301;
              }
LABEL_179:
              v4 >>= SBYTE1(v66);
              v7 -= BYTE1(v66);
              *((_WORD *)v2 + v2[26]++ + 56) = HIWORD(countd);
            }
            if ( v2[26] >= (unsigned int)(v2[24] + v2[25]) )
              goto LABEL_201;
          }
          while ( v3 != 0 )
          {
            v67 = *v5 << v7;
            --v3;
            v7 += 8;
            v4 += v67;
            ++v5;
            v120 = v3;
            v66 = *(_DWORD *)(v2[19] + 4 * (v4 & ((1 << v2[21]) - 1)));
            countd = v66;
            if ( BYTE1(v66) <= v7 )
              goto LABEL_175;
          }
          goto LABEL_301;
        }
LABEL_201:
        if ( *v2 == 27 )
          goto LABEL_293;
        v2[27] = (int)(v2 + 332);
        v2[19] = (int)(v2 + 332);
        v117 = v2[24];
        v2[21] = 9;
        v138 = inflate_table(a1: 1, a2: v2 + 28, a3: v117, a4: v2 + 27, a5: v2 + 21, a6: v2 + 188);
        if ( v138 != 0 )
        {
          v3 = v120;
          *(_DWORD *)(a1 + 24) = "invalid literal/lengths set";
          goto LABEL_292;
        }
        v2[20] = v2[27];
        v80 = v2[24];
        v2[22] = 6;
        v81 = inflate_table(a1: 2, a2: (char *)v2 + 2 * v80 + 112, a3: v2[25], a4: v2 + 27, a5: v2 + 22, a6: v2 + 188);
        v3 = v120;
        v138 = v81;
        if ( v81 != 0 )
        {
          *(_DWORD *)(a1 + 24) = "invalid distances set";
          goto LABEL_292;
        }
        *v2 = 18;
LABEL_209:
        if ( v3 >= 6 && v132 >= 0x102 )
        {
          v82 = dst;
          *(_DWORD *)(a1 + 16) = v132;
          v83 = v136;
          *(_DWORD *)(a1 + 12) = v82;
          *(_DWORD *)a1 = v5;
          *(_DWORD *)(a1 + 4) = v120;
          v2[14] = v4;
          v2[15] = v7;
          inflate_fast(a1, a2: v83);
          v5 = *(unsigned __int8 **)a1;
          v84 = *(_DWORD *)(a1 + 4);
          v4 = v2[14];
          v7 = v2[15];
          v132 = *(_DWORD *)(a1 + 16);
          dst = *(unsigned __int8 **)(a1 + 12);
          v120 = v84;
          v3 = v84;
          goto LABEL_293;
        }
        v85 = *(_DWORD *)(v2[19] + 4 * (v4 & ((1 << v2[21]) - 1)));
        countf = v85;
        if ( BYTE1(v85) > v7 )
        {
          while ( v3 != 0 )
          {
            v86 = *v5 << v7;
            --v3;
            v7 += 8;
            v4 += v86;
            ++v5;
            v120 = v3;
            v85 = *(_DWORD *)(v2[19] + 4 * (v4 & ((1 << v2[21]) - 1)));
            countf = v85;
            if ( BYTE1(v85) <= v7 )
              goto LABEL_215;
          }
          goto LABEL_301;
        }
LABEL_215:
        if ( (_BYTE)v85 != 0 && (v85 & 0xF0) == 0 )
        {
          v139 = v85 >> 8;
          v134 = BYTE1(v85);
          v137 = (unsigned __int8 *)v85;
          countg = *(_DWORD *)(v2[19] + 4 * (HIWORD(countf) + ((v4 & ((1 << (BYTE1(v85) + v85)) - 1)) >> SBYTE1(v85))));
          if ( BYTE1(v85) + (unsigned int)BYTE1(countg) > v7 )
          {
            while ( v3 != 0 )
            {
              v87 = *v5 << v7;
              --v3;
              v7 += 8;
              v4 += v87;
              v134 = BYTE1(v137);
              ++v5;
              v120 = v3;
              countg = *(_DWORD *)(v2[19]
                                 + 4
                                 * (HIWORD(v137) + ((v4 & ((1 << (BYTE1(v137) + (_BYTE)v137)) - 1)) >> SBYTE1(v137))));
              if ( BYTE1(v137) + (unsigned int)BYTE1(countg) <= v7 )
                goto LABEL_220;
            }
            goto LABEL_301;
          }
LABEL_220:
          v85 = countg;
          v4 >>= SBYTE1(v137);
          v7 -= BYTE1(v137);
        }
        v4 >>= SBYTE1(v85);
        v7 -= BYTE1(v85);
        v134 = BYTE1(v85);
        v2[16] = HIWORD(v85);
        if ( (_BYTE)v85 == 0 )
        {
          *v2 = 23;
          goto LABEL_293;
        }
        if ( (v85 & 0x20) != 0 )
        {
LABEL_224:
          *v2 = 11;
          goto LABEL_293;
        }
        if ( (v85 & 0x40) != 0 )
        {
          *(_DWORD *)(a1 + 24) = "invalid literal/length code";
          goto LABEL_292;
        }
        v2[18] = v85 & 0xF;
        *v2 = 19;
LABEL_228:
        v88 = v2[18];
        if ( v88 != 0 )
        {
          if ( v7 < v88 )
          {
            while ( v3 != 0 )
            {
              v89 = *v5 << v7;
              --v3;
              v7 += 8;
              ++v5;
              v4 += v89;
              v120 = v3;
              if ( v7 >= v2[18] )
                goto LABEL_232;
            }
            goto LABEL_301;
          }
LABEL_232:
          v90 = v2[18];
          v2[16] += v4 & ((1 << v90) - 1);
          v4 >>= v90;
          v7 -= v90;
        }
        *v2 = 20;
LABEL_234:
        v91 = *(_DWORD *)(v2[20] + 4 * (v4 & ((1 << v2[22]) - 1)));
        counth = v91;
        if ( BYTE1(v91) > v7 )
        {
          while ( v3 != 0 )
          {
            v92 = *v5 << v7;
            --v3;
            v7 += 8;
            v4 += v92;
            ++v5;
            v120 = v3;
            v91 = *(_DWORD *)(v2[20] + 4 * (v4 & ((1 << v2[22]) - 1)));
            counth = v91;
            if ( BYTE1(v91) <= v7 )
              goto LABEL_237;
          }
          goto LABEL_301;
        }
LABEL_237:
        if ( (v91 & 0xF0) == 0 )
        {
          v139 = v91 >> 8;
          v134 = BYTE1(v91);
          v137 = (unsigned __int8 *)v91;
          counti = *(_DWORD *)(v2[20] + 4 * (HIWORD(counth) + ((v4 & ((1 << (BYTE1(v91) + v91)) - 1)) >> SBYTE1(v91))));
          if ( BYTE1(v91) + (unsigned int)BYTE1(counti) > v7 )
          {
            while ( v3 != 0 )
            {
              v93 = *v5 << v7;
              --v3;
              v7 += 8;
              v4 += v93;
              v134 = BYTE1(v137);
              ++v5;
              v120 = v3;
              counti = *(_DWORD *)(v2[20]
                                 + 4
                                 * (HIWORD(v137) + ((v4 & ((1 << (BYTE1(v137) + (_BYTE)v137)) - 1)) >> SBYTE1(v137))));
              if ( BYTE1(v137) + (unsigned int)BYTE1(counti) <= v7 )
                goto LABEL_241;
            }
            goto LABEL_301;
          }
LABEL_241:
          v91 = counti;
          v4 >>= SBYTE1(v137);
          v7 -= BYTE1(v137);
        }
        v4 >>= SBYTE1(v91);
        v7 -= BYTE1(v91);
        v134 = BYTE1(v91);
        if ( (v91 & 0x40) != 0 )
        {
          *(_DWORD *)(a1 + 24) = "invalid distance code";
          goto LABEL_292;
        }
        v2[17] = HIWORD(v91);
        v2[18] = v91 & 0xF;
        *v2 = 21;
LABEL_245:
        v94 = v2[18];
        if ( v94 != 0 )
        {
          if ( v7 < v94 )
          {
            while ( v3 != 0 )
            {
              v95 = *v5 << v7;
              --v3;
              v7 += 8;
              ++v5;
              v4 += v95;
              v120 = v3;
              if ( v7 >= v2[18] )
                goto LABEL_249;
            }
            goto LABEL_301;
          }
LABEL_249:
          v96 = v2[18];
          v2[17] += v4 & ((1 << v96) - 1);
          v4 >>= v96;
          v7 -= v96;
        }
        if ( v2[17] > v136 + v2[11] - v132 )
        {
          *(_DWORD *)(a1 + 24) = "invalid distance too far back";
          goto LABEL_292;
        }
        *v2 = 22;
LABEL_253:
        if ( v132 == 0 )
          goto LABEL_301;
        v97 = v2[17];
        if ( v97 <= v136 - v132 )
        {
          v102 = &dst[-v97];
          v98 = v2[16];
          v137 = v102;
          v139 = v98;
          goto LABEL_261;
        }
        v98 = v97 - (v136 - v132);
        v99 = v2[12];
        countj = v98;
        if ( v98 <= v99 )
        {
          v100 = v2[12] + v2[13] - v98;
        }
        else
        {
          v98 -= v99;
          countj = v98;
          v100 = v2[10] + v2[13] - v98;
        }
        v137 = (unsigned __int8 *)v100;
        v101 = v2[16];
        v139 = v101;
        if ( v98 > v101 )
        {
          v98 = v101;
LABEL_261:
          countj = v98;
        }
        if ( v98 > v132 )
        {
          v98 = v132;
          countj = v132;
        }
        v132 -= v98;
        v103 = v139 - v98;
        v104 = dst;
        v2[16] = v103;
        do
        {
          v105 = *v137++;
          *v104++ = v105;
          --countj;
        }
        while ( countj != 0 );
        v106 = v2[16] == 0;
        dst = v104;
        if ( v106 )
          *v2 = 18;
        goto LABEL_293;
      case 16:
        goto LABEL_160;
      case 17:
        goto LABEL_171;
      case 18:
        goto LABEL_209;
      case 19:
        goto LABEL_228;
      case 20:
        goto LABEL_234;
      case 21:
        goto LABEL_245;
      case 22:
        goto LABEL_253;
      case 23:
        if ( v132 == 0 )
          goto LABEL_301;
        v107 = dst;
        *dst = *((_BYTE *)v2 + 64);
        --v132;
        dst = v107 + 1;
        *v2 = 18;
        goto LABEL_293;
      case 24:
        if ( v2[2] == 0 )
          goto LABEL_284;
        for ( ; v7 < 0x20; v120 = v3 )
        {
          if ( v3 == 0 )
            goto LABEL_301;
          v108 = *v5 << v7;
          --v3;
          v7 += 8;
          ++v5;
          v4 += v108;
        }
        v109 = v136 - v132;
        *(_DWORD *)(a1 + 20) += v136 - v132;
        v2[7] += v109;
        v136 = v109;
        if ( v109 != 0 )
        {
          v119 = &dst[-v109];
          v118 = v2[6];
          if ( v2[4] != 0 )
            v110 = crc32(a1: v118, a2: v119, a3: v109);
          else
            v110 = adler32(a1: v118, a2: v119, a3: v109);
          v3 = v120;
          v2[6] = v110;
          *(_DWORD *)(a1 + 48) = v110;
        }
        v106 = v2[4] == 0;
        v136 = v132;
        v111 = v4;
        if ( v106 )
          v111 = HIBYTE(v4) + ((v4 >> 8) & 0xFF00) + (((v4 << 16) + (v4 & 0xFF00)) << 8);
        if ( v111 != v2[6] )
        {
          *(_DWORD *)(a1 + 24) = "incorrect data check";
          goto LABEL_292;
        }
        v4 = 0;
        v7 = 0;
LABEL_284:
        *v2 = 25;
LABEL_285:
        if ( v2[2] == 0 || v2[4] == 0 )
          goto LABEL_298;
        if ( v7 < 0x20 )
        {
          while ( v3 != 0 )
          {
            v112 = *v5 << v7;
            --v3;
            v7 += 8;
            ++v5;
            v4 += v112;
            v120 = v3;
            if ( v7 >= 0x20 )
              goto LABEL_290;
          }
          goto LABEL_301;
        }
LABEL_290:
        if ( v4 != v2[7] )
        {
          *(_DWORD *)(a1 + 24) = "incorrect length check";
LABEL_292:
          *v2 = 27;
LABEL_293:
          v6 = *v2;
          if ( (unsigned int)*v2 > 0x1C )
            return -2;
          continue;
        }
        v4 = 0;
        v7 = 0;
LABEL_298:
        *v2 = 26;
LABEL_299:
        v138 = 1;
LABEL_301:
        *(_DWORD *)(a1 + 12) = dst;
        *(_DWORD *)(a1 + 16) = v132;
        *(_DWORD *)a1 = v5;
        *(_DWORD *)(a1 + 4) = v3;
        v106 = v2[10] == 0;
        v2[14] = v4;
        v2[15] = v7;
        if ( v106 && (*v2 >= 24 || v136 == *(_DWORD *)(a1 + 16)) || updatewindow(a1: v136, a2: a1) == 0 )
        {
          v114 = v140 - *(_DWORD *)(a1 + 4);
          v115 = v136 - *(_DWORD *)(a1 + 16);
          *(_DWORD *)(a1 + 8) += v114;
          *(_DWORD *)(a1 + 20) += v115;
          v2[7] += v115;
          if ( v2[2] != 0 && v115 != 0 )
          {
            if ( v2[4] != 0 )
              v116 = crc32(a1: v2[6], a2: *(_DWORD *)(a1 + 12) - v115, a3: v115);
            else
              v116 = adler32(a1: v2[6], a2: *(_DWORD *)(a1 + 12) - v115, a3: v115);
            v2[6] = v116;
            *(_DWORD *)(a1 + 48) = v116;
          }
          *(_DWORD *)(a1 + 44) = v2[15] + (*v2 != 11 ? 0 : 0x80) + (v2[1] != 0 ? 0x40 : 0);
          if ( (v114 != 0 || v115 != 0) && a2 != 4 )
          {
            return v138;
          }
          else
          {
            result = v138;
            if ( v138 == 0 )
              return -5;
          }
        }
        else
        {
          *v2 = 28;
          return -4;
        }
        return result;
      case 25:
        goto LABEL_285;
      case 26:
        goto LABEL_299;
      case 27:
        v138 = -3;
        goto LABEL_301;
      case 28:
        return -4;
      default:
        return -2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00450E60
// Name: _inflateEnd
// Source: json
//------------------------------------------------------------------------------
int __cdecl inflateEnd(_DWORD *a1)
{
  int v1; // eax
  void (__cdecl *v2)(_DWORD, int); // ecx
  int v3; // eax

  if ( a1 == nullptr )
    return -2;
  v1 = a1[7];
  if ( v1 == 0 )
    return -2;
  v2 = (void (__cdecl *)(_DWORD, int))a1[9];
  if ( v2 == nullptr )
    return -2;
  v3 = *(_DWORD *)(v1 + 52);
  if ( v3 != 0 )
    v2(a1: a1[10], a2: v3);
  ((void (__cdecl *)(_DWORD, _DWORD))a1[9])(a1: a1[10], a2: a1[7]);
  a1[7] = 0;
  return 0;
}
