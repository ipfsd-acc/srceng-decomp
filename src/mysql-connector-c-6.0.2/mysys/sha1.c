// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/sha1.c
// Functions: 5
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00418630
// Name: _mysql_sha1_reset
// Source: json
//------------------------------------------------------------------------------
int __cdecl mysql_sha1_reset(int a1)
{
  *(_DWORD *)a1 = 0;
  *(_DWORD *)(a1 + 4) = 0;
  *(_WORD *)(a1 + 36) = 0;
  *(_DWORD *)(a1 + 8) = 1732584193;
  *(_DWORD *)(a1 + 12) = -271733879;
  *(_DWORD *)(a1 + 16) = -1732584194;
  *(_DWORD *)(a1 + 20) = 271733878;
  *(_DWORD *)(a1 + 24) = -1009589776;
  *(_DWORD *)(a1 + 28) = 0;
  *(_DWORD *)(a1 + 32) = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00418670
// Name: SHA1ProcessMessageBlock
// Source: json
//------------------------------------------------------------------------------
int __cdecl SHA1ProcessMessageBlock(int a1)
{
  unsigned __int8 *v1; // eax
  int v2; // esi
  int v3; // edx
  unsigned __int8 *v4; // edi
  unsigned __int8 *v5; // ecx
  int v6; // ebp
  char *v7; // eax
  int i; // edi
  int v9; // edx
  int v10; // esi
  int v11; // ecx
  int v12; // ebp
  int v13; // ebp
  int v14; // ebp
  int v15; // edx
  int v16; // esi
  int v17; // eax
  int v18; // ecx
  int v19; // edx
  int v20; // ebx
  int v21; // edi
  int v22; // eax
  int v23; // edx
  int v24; // ebp
  int v25; // ecx
  int v26; // esi
  int v27; // edi
  int v28; // ecx
  int v29; // eax
  int v30; // ebx
  int v31; // edi
  int v32; // eax
  int v33; // edi
  int v34; // esi
  int v35; // edx
  int v36; // ebp
  int v37; // ecx
  int v38; // ebp
  int v39; // edi
  int v40; // eax
  int v41; // esi
  int v42; // eax
  int v43; // ecx
  int v44; // esi
  int v45; // edi
  int v46; // ebx
  int v47; // eax
  int v48; // ebp
  int v49; // ebx
  int v50; // edx
  int v51; // esi
  int v52; // edi
  int v53; // edx
  int v54; // ecx
  int v55; // eax
  int v56; // edx
  int v57; // edi
  int v58; // esi
  int v59; // esi
  int v60; // ebp
  int v61; // ecx
  int v62; // eax
  int v63; // edi
  int v64; // ebp
  int v65; // eax
  int v66; // ebx
  int v67; // edx
  int v68; // ebp
  int v69; // esi
  int v70; // edx
  int v71; // ebx
  int v72; // ecx
  int v73; // eax
  int v74; // ebx
  int v75; // esi
  int v76; // ebp
  int v77; // esi
  int v78; // eax
  int v79; // ebx
  bool v80; // cc
  int v81; // ebp
  int v82; // ebx
  int v83; // esi
  int result; // eax
  int v85; // [esp+8h] [ebp-168h]
  int v86; // [esp+8h] [ebp-168h]
  int v87; // [esp+8h] [ebp-168h]
  int v88; // [esp+8h] [ebp-168h]
  int v89; // [esp+8h] [ebp-168h]
  int v90; // [esp+8h] [ebp-168h]
  int v91; // [esp+8h] [ebp-168h]
  int v92; // [esp+8h] [ebp-168h]
  int v93; // [esp+Ch] [ebp-164h]
  int v94; // [esp+Ch] [ebp-164h]
  int v95; // [esp+Ch] [ebp-164h]
  int v96; // [esp+Ch] [ebp-164h]
  int v97; // [esp+Ch] [ebp-164h]
  int v98; // [esp+Ch] [ebp-164h]
  int v99; // [esp+Ch] [ebp-164h]
  int v100; // [esp+Ch] [ebp-164h]
  int v101; // [esp+Ch] [ebp-164h]
  int v102; // [esp+Ch] [ebp-164h]
  int v103; // [esp+Ch] [ebp-164h]
  int v104; // [esp+Ch] [ebp-164h]
  int v105; // [esp+30h] [ebp-140h] BYREF
  int v106; // [esp+34h] [ebp-13Ch] BYREF
  _DWORD v107[6]; // [esp+38h] [ebp-138h] BYREF
  char v108; // [esp+50h] [ebp-120h] BYREF

  v1 = (unsigned __int8 *)(a1 + 43);
  v2 = 0;
  v3 = a1 + 38 - (_DWORD)&v105;
  v4 = (unsigned __int8 *)(a1 + 53);
  v5 = (unsigned __int8 *)(a1 + 48);
  while ( 1 )
  {
    v6 = *v1;
    *(&v105 + v2) = *(v4 - 12)
                  | ((*(v5 - 8) | ((*(v1 - 4) | (*((unsigned __int8 *)&v105 + 4 * v2 + v3) << 8)) << 8)) << 8);
    *(int *)((char *)&v105 + (_DWORD)v1 - a1 - 39) = v1[2] | ((v1[1] | ((v6 | (*(v1 - 1) << 8)) << 8)) << 8);
    *(int *)((char *)&v106 + (_DWORD)v1 - a1 - 39) = v5[1] | ((*v5 | ((v1[4] | (*(v5 - 2) << 8)) << 8)) << 8);
    *(_DWORD *)((char *)&v107[-9] + (_DWORD)v1 - a1 - 3) = *v4 | ((v5[4] | ((v1[8] | (*(v4 - 3) << 8)) << 8)) << 8);
    v2 += 4;
    v1 += 16;
    v5 += 16;
    v4 += 16;
    if ( v2 >= 16 )
      break;
    v3 = a1 + 38 - (_DWORD)&v105;
  }
  v7 = &v108;
  for ( i = 16; i != 0; --i )
  {
    v9 = *((_DWORD *)v7 - 6);
    v10 = *((_DWORD *)v7 - 5);
    v11 = __ROL4__(*(_DWORD *)v7 ^ v9 ^ *((_DWORD *)v7 + 5) ^ *((_DWORD *)v7 - 8), 1);
    *((_DWORD *)v7 + 9) = __ROL4__(v10 ^ *((_DWORD *)v7 + 1) ^ *((_DWORD *)v7 + 6) ^ *((_DWORD *)v7 - 7), 1);
    v12 = *((_DWORD *)v7 - 4) ^ *((_DWORD *)v7 + 7);
    *((_DWORD *)v7 + 8) = v11;
    v13 = *((_DWORD *)v7 + 2) ^ v12;
    v7 += 16;
    v14 = __ROL4__(v9 ^ v13, 1);
    v15 = __ROL4__(v10 ^ v11 ^ *((_DWORD *)v7 - 1) ^ *((_DWORD *)v7 - 7), 1);
    *((_DWORD *)v7 + 6) = v14;
    *((_DWORD *)v7 + 7) = v15;
  }
  v16 = *(_DWORD *)(a1 + 8);
  v17 = *(_DWORD *)(a1 + 12);
  v18 = *(_DWORD *)(a1 + 16);
  v19 = *(_DWORD *)(a1 + 20);
  v85 = *(_DWORD *)(a1 + 24);
  v93 = 0;
  do
  {
    v20 = v93;
    v21 = *(&v105 + v93) + (v17 & v18 | v19 & ~v17) + __ROL4__(v16, 5);
    v22 = __ROR4__(v17, 2);
    v94 = v21 + v85 + 1518500249;
    v23 = v107[v20 - 1] + (v16 & v22 | v18 & ~v16) + __ROL4__(v94, 5) + v19 + 1518500249;
    v86 = v18;
    v24 = __ROR4__(v16, 2);
    v25 = __ROR4__(v94, 2);
    v95 = v107[v20] + (v94 & v24 | v22 & ~v94) + __ROL4__(v23, 5) + v86 + 1518500249;
    v26 = v107[v20 + 1] + (v23 & v25 | v24 & ~v23) + __ROL4__(v95, 5) + v22 + 1518500249;
    v27 = v25;
    v28 = v95;
    v19 = __ROR4__(v23, 2);
    v29 = ~v95;
    v96 = v26;
    v16 = v107[v20 + 2] + (v28 & v19 | v27 & v29) + __ROL4__(v26, 5) + v24 + 1518500249;
    v17 = v96;
    v18 = __ROR4__(v28, 2);
    v85 = v27;
    v93 = v20 + 5;
  }
  while ( v20 + 5 < 20 );
  v30 = 20;
  do
  {
    v31 = *(&v105 + v30) + (v17 ^ v18 ^ v19) + __ROL4__(v16, 5);
    v32 = __ROR4__(v17, 2);
    v97 = v31 + v85 + 1859775393;
    v33 = v107[v30 - 1] + (v16 ^ v32 ^ v18) + __ROL4__(v97, 5);
    v34 = __ROR4__(v16, 2);
    v35 = v33 + v19 + 1859775393;
    v36 = v18;
    v37 = __ROR4__(v97, 2);
    v98 = v107[v30] + (v97 ^ v34 ^ v32) + __ROL4__(v35, 5) + v36 + 1859775393;
    v38 = v32;
    v39 = v34;
    v40 = v107[v30 + 1] + (v35 ^ v37 ^ v34) + __ROL4__(v98, 5);
    v19 = __ROR4__(v35, 2);
    v41 = v40 + v38 + 1859775393;
    v42 = v37;
    v43 = v98;
    v99 = v41;
    v44 = v107[v30 + 2] + (v43 ^ v19 ^ v42) + __ROL4__(v41, 5);
    v30 += 5;
    v18 = __ROR4__(v43, 2);
    v85 = v42;
    v17 = v99;
    v16 = v44 + v39 + 1859775393;
  }
  while ( v30 < 40 );
  v100 = 40;
  do
  {
    v45 = v85 + __ROL4__(v16, 5);
    v46 = *(&v105 + v100) + (v17 & v18 | v19 & (v17 | v18));
    v47 = __ROR4__(v17, 2);
    v87 = v19;
    v48 = v46 + v45 - 1894007588;
    v49 = v100;
    v50 = v107[v100 - 1] + (v16 & v47 | v18 & (v16 | v47));
    v51 = __ROR4__(v16, 2);
    v52 = v107[v100] + (v48 & v51 | v47 & (v48 | v51));
    v101 = v50 + v87 + __ROL4__(v48, 5) - 1894007588;
    v53 = v18 + __ROL4__(v101, 5);
    v54 = __ROR4__(v48, 2);
    v88 = v47;
    v55 = v101;
    v56 = v52 + v53 - 1894007588;
    v57 = v51;
    v58 = v107[v49 + 1] + (v101 & v54 | v51 & (v101 | v54));
    v102 = v56;
    v59 = v58 + v88 + __ROL4__(v56, 5) - 1894007588;
    v19 = __ROR4__(v55, 2);
    v60 = v54;
    v61 = v102;
    v62 = v60 & (v102 | v19);
    v103 = v59;
    v16 = v107[v49 + 2] + (v61 & v19 | v62) + v57 + __ROL4__(v59, 5) - 1894007588;
    v17 = v103;
    v18 = __ROR4__(v61, 2);
    v85 = v60;
    v100 = v49 + 5;
  }
  while ( v49 + 5 < 60 );
  v63 = 60;
  v104 = 60;
  do
  {
    v64 = *(&v105 + v63) + (v17 ^ v18 ^ v19);
    v65 = __ROR4__(v17, 2);
    v66 = v85 + __ROL4__(v16, 5) + v64 - 899497514;
    v89 = v19;
    v67 = v107[v104 - 1] + (v16 ^ v65 ^ v18);
    v68 = v66;
    v69 = __ROR4__(v16, 2);
    v70 = v67 + v89 + __ROL4__(v66, 5) - 899497514;
    v71 = v65;
    v90 = v18;
    v72 = __ROR4__(v68, 2);
    v73 = v107[v104] + (v68 ^ v69 ^ v65) + v90 + __ROL4__(v70, 5) - 899497514;
    v91 = v71;
    v74 = v69;
    v75 = v107[v104 + 1] + (v70 ^ v72 ^ v69);
    v76 = v73;
    v19 = __ROR4__(v70, 2);
    v77 = v75 + v91 + __ROL4__(v73, 5) - 899497514;
    v78 = v72;
    v92 = v74;
    v79 = v77;
    v63 = v104 + 5;
    v16 = v92 + __ROL4__(v77, 5) + v107[v104 + 2] + (v76 ^ v19 ^ v72) - 899497514;
    v18 = __ROR4__(v76, 2);
    v80 = v104 + 5 < 80;
    v81 = v78;
    v85 = v78;
    v17 = v79;
    v104 += 5;
  }
  while ( v80 );
  v82 = v16 + *(_DWORD *)(a1 + 8);
  v83 = v17 + *(_DWORD *)(a1 + 12);
  *(_DWORD *)(a1 + 16) += v18;
  *(_DWORD *)(a1 + 20) += v19;
  result = v81 + *(_DWORD *)(a1 + 24);
  *(_DWORD *)(a1 + 8) = v82;
  *(_DWORD *)(a1 + 12) = v83;
  *(_DWORD *)(a1 + 24) = result;
  *(_WORD *)(a1 + 36) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00418C10
// Name: SHA1PadMessage
// Source: json
//------------------------------------------------------------------------------
int __usercall SHA1PadMessage@<eax>(int a1@<esi>)
{
  int v1; // eax
  unsigned int v2; // eax
  unsigned int v3; // ecx
  unsigned int v4; // edx
  int v5; // ecx
  int v6; // edx

  v1 = *(__int16 *)(a1 + 36);
  *(_BYTE *)(v1 + a1 + 38) = 0x80;
  if ( v1 <= 55 )
  {
    memset(dst: (unsigned __int8 *)(v1 + 1 + a1 + 38), value: 0, count: 56 - (v1 + 1));
  }
  else
  {
    memset(dst: (unsigned __int8 *)(v1 + 1 + a1 + 38), value: 0, count: 64 - (v1 + 1));
    *(_WORD *)(a1 + 36) = 64;
    SHA1ProcessMessageBlock(a1);
    memset(dst: (unsigned __int8 *)(a1 + 38), value: 0, count: 0x38u);
  }
  *(_WORD *)(a1 + 36) = 56;
  v2 = *(_DWORD *)(a1 + 4);
  v3 = *(_DWORD *)a1;
  *(_BYTE *)(a1 + 94) = HIBYTE(v2);
  *(_BYTE *)(a1 + 95) = BYTE2(v2);
  *(_BYTE *)(a1 + 96) = BYTE1(v2);
  *(_BYTE *)(a1 + 97) = v2;
  *(_BYTE *)(a1 + 98) = HIBYTE(v3);
  v4 = v3;
  v5 = __PAIR64__(v2, v3) >> 8;
  v6 = __PAIR64__(v2, v4) >> 16;
  LOBYTE(v2) = *(_BYTE *)a1;
  *(_BYTE *)(a1 + 99) = v6;
  *(_BYTE *)(a1 + 100) = v5;
  *(_BYTE *)(a1 + 101) = v2;
  return SHA1ProcessMessageBlock(a1);
}

//------------------------------------------------------------------------------
// Address: 0x00418CE0
// Name: _mysql_sha1_result
// Source: json
//------------------------------------------------------------------------------
int __cdecl mysql_sha1_result(int a1, int a2)
{
  int i; // eax
  int v3; // edx

  if ( *(_DWORD *)(a1 + 28) == 0 )
  {
    SHA1PadMessage(a1);
    memset(dst: (unsigned __int8 *)(a1 + 38), value: 0, count: 0x40u);
    *(_DWORD *)a1 = 0;
    *(_DWORD *)(a1 + 4) = 0;
    *(_DWORD *)(a1 + 28) = 1;
  }
  for ( i = 0; i < 20; *(_BYTE *)(i + a2 - 1) = v3 )
  {
    v3 = *(_DWORD *)(a1 + 4 * (i >> 2) + 8) >> (8 * (3 - (i & 3)));
    ++i;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00418D50
// Name: _mysql_sha1_input
// Source: json
//------------------------------------------------------------------------------
int __cdecl mysql_sha1_input(int a1, _BYTE *a2, int a3)
{
  int i; // ebx
  __int16 v5; // ax

  for ( i = a3; i != 0; ++a2 )
  {
    *(_BYTE *)((__int16)(*(_WORD *)(a1 + 36))++ + a1 + 38) = *a2;
    v5 = *(_WORD *)(a1 + 36);
    --i;
    *(_QWORD *)a1 += 8LL;
    if ( v5 == 64 )
      SHA1ProcessMessageBlock(a1);
  }
  return 0;
}
