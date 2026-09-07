// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/jpeglib/jfdctint.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10258910
// Name: _jpeg_fdct_islow
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_fdct_islow(int *data)
{
  int *v1; // eax
  int v2; // ecx
  int v3; // edx
  int v4; // esi
  int v5; // edx
  int v6; // ecx
  int v7; // esi
  int v8; // edi
  int v9; // esi
  int v10; // ecx
  int v11; // edi
  int v12; // ecx
  int v13; // ebx
  int v14; // ecx
  int v15; // ecx
  int *v16; // eax
  int v17; // ecx
  int v18; // edx
  int v19; // esi
  int v20; // edx
  int v21; // ecx
  int v22; // esi
  int v23; // edi
  int v24; // esi
  int v25; // ecx
  int v26; // edi
  int v27; // ecx
  int v28; // ebx
  int v29; // ecx
  int v30; // ecx
  int tmp13; // [esp+Ch] [ebp-1Ch]
  int tmp13a; // [esp+Ch] [ebp-1Ch]
  int z2; // [esp+10h] [ebp-18h]
  int z2a; // [esp+10h] [ebp-18h]
  int ctr; // [esp+14h] [ebp-14h]
  int ctra; // [esp+14h] [ebp-14h]
  int tmp10; // [esp+18h] [ebp-10h]
  int tmp10a; // [esp+18h] [ebp-10h]
  int tmp10b; // [esp+18h] [ebp-10h]
  int tmp10c; // [esp+18h] [ebp-10h]
  int tmp10d; // [esp+18h] [ebp-10h]
  int tmp10e; // [esp+18h] [ebp-10h]
  int tmp12; // [esp+1Ch] [ebp-Ch]
  int tmp12a; // [esp+1Ch] [ebp-Ch]
  int tmp12b; // [esp+1Ch] [ebp-Ch]
  int tmp12c; // [esp+1Ch] [ebp-Ch]
  int tmp4; // [esp+20h] [ebp-8h]
  int tmp4a; // [esp+20h] [ebp-8h]
  int tmp3; // [esp+24h] [ebp-4h]
  int tmp3a; // [esp+24h] [ebp-4h]
  int tmp3b; // [esp+24h] [ebp-4h]
  int tmp3c; // [esp+24h] [ebp-4h]

  ctr = 7;
  v1 = data + 2;
  do
  {
    v2 = v1[5];
    v3 = *(v1 - 2);
    v4 = v3 + v2;
    v5 = v3 - v2;
    v6 = v1[4];
    tmp10 = v4;
    v7 = *(v1 - 1);
    v8 = v7 + v6;
    v9 = v7 - v6;
    v10 = v1[3];
    z2 = v8;
    tmp12 = v10 + *v1;
    v11 = *v1 - v10;
    v12 = v1[1];
    v13 = v12 + v1[2];
    tmp4 = v12 - v1[2];
    v14 = tmp10 - v13;
    tmp10a = tmp10 + v13;
    tmp13 = v14;
    tmp3 = z2 + tmp12;
    tmp12a = z2 - tmp12;
    *(v1 - 2) = 4 * (tmp10a + tmp3);
    v1[2] = 4 * (tmp10a - tmp3);
    v15 = 4433 * (v14 + tmp12a);
    *v1 = (6270 * tmp13 + v15 + 1024) >> 11;
    v1[4] = (v15 - 15137 * tmp12a + 1024) >> 11;
    tmp10b = 9633 * (v9 + tmp4 + v11 + v5) - 16069 * (v9 + tmp4);
    tmp3a = 9633 * (v9 + tmp4 + v11 + v5) - 3196 * (v11 + v5);
    v1[5] = (tmp10b + 2446 * tmp4 - 7373 * (v5 + tmp4) + 1024) >> 11;
    v1[3] = (tmp3a + 16819 * v11 - 20995 * (v11 + v9) + 1024) >> 11;
    v1[1] = (tmp10b + 25172 * v9 - 20995 * (v11 + v9) + 1024) >> 11;
    *(v1 - 1) = (tmp3a + 12299 * v5 - 7373 * (v5 + tmp4) + 1024) >> 11;
    v1 += 8;
    --ctr;
  }
  while ( ctr >= 0 );
  ctra = 7;
  v16 = data + 16;
  do
  {
    v17 = v16[40];
    v18 = *(v16 - 16);
    v19 = v18 + v17;
    v20 = v18 - v17;
    v21 = v16[32];
    tmp10c = v19;
    v22 = *(v16 - 8);
    v23 = v22 + v21;
    v24 = v22 - v21;
    v25 = v16[24];
    z2a = v23;
    tmp12b = v25 + *v16;
    v26 = *v16 - v25;
    v27 = v16[8];
    v28 = v27 + v16[16];
    tmp4a = v27 - v16[16];
    v29 = tmp10c - v28;
    tmp10d = tmp10c + v28;
    tmp13a = v29;
    tmp3b = z2a + tmp12b;
    tmp12c = z2a - tmp12b;
    *(v16 - 16) = (tmp3b + tmp10d + 2) >> 2;
    v16[16] = (tmp10d - tmp3b + 2) >> 2;
    v30 = 4433 * (v29 + tmp12c);
    *v16 = (6270 * tmp13a + v30 + 0x4000) >> 15;
    v16[32] = (v30 - 15137 * tmp12c + 0x4000) >> 15;
    tmp10e = 9633 * (v24 + tmp4a + v26 + v20) - 16069 * (v24 + tmp4a);
    tmp3c = 9633 * (v24 + tmp4a + v26 + v20) - 3196 * (v26 + v20);
    v16[40] = (tmp10e + 2446 * tmp4a - 7373 * (v20 + tmp4a) + 0x4000) >> 15;
    v16[24] = (tmp3c + 16819 * v26 - 20995 * (v26 + v24) + 0x4000) >> 15;
    v16[8] = (tmp10e + 25172 * v24 - 20995 * (v26 + v24) + 0x4000) >> 15;
    *(v16 - 8) = (tmp3c + 12299 * v20 - 7373 * (v20 + tmp4a) + 0x4000) >> 15;
    ++v16;
    --ctra;
  }
  while ( ctra >= 0 );
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10258940
// Name: _jpeg_fdct_islow
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_fdct_islow(int *data)
{
  int *v1; // eax
  int v2; // ecx
  int v3; // edx
  int v4; // esi
  int v5; // edx
  int v6; // ecx
  int v7; // esi
  int v8; // edi
  int v9; // esi
  int v10; // ecx
  int v11; // edi
  int v12; // ecx
  int v13; // ebx
  int v14; // ecx
  int v15; // ecx
  int *v16; // eax
  int v17; // ecx
  int v18; // edx
  int v19; // esi
  int v20; // edx
  int v21; // ecx
  int v22; // esi
  int v23; // edi
  int v24; // esi
  int v25; // ecx
  int v26; // edi
  int v27; // ecx
  int v28; // ebx
  int v29; // ecx
  int v30; // ecx
  int tmp13; // [esp+Ch] [ebp-1Ch]
  int tmp13a; // [esp+Ch] [ebp-1Ch]
  int z2; // [esp+10h] [ebp-18h]
  int z2a; // [esp+10h] [ebp-18h]
  int ctr; // [esp+14h] [ebp-14h]
  int ctra; // [esp+14h] [ebp-14h]
  int tmp10; // [esp+18h] [ebp-10h]
  int tmp10a; // [esp+18h] [ebp-10h]
  int tmp10b; // [esp+18h] [ebp-10h]
  int tmp10c; // [esp+18h] [ebp-10h]
  int tmp10d; // [esp+18h] [ebp-10h]
  int tmp10e; // [esp+18h] [ebp-10h]
  int tmp12; // [esp+1Ch] [ebp-Ch]
  int tmp12a; // [esp+1Ch] [ebp-Ch]
  int tmp12b; // [esp+1Ch] [ebp-Ch]
  int tmp12c; // [esp+1Ch] [ebp-Ch]
  int tmp4; // [esp+20h] [ebp-8h]
  int tmp4a; // [esp+20h] [ebp-8h]
  int tmp3; // [esp+24h] [ebp-4h]
  int tmp3a; // [esp+24h] [ebp-4h]
  int tmp3b; // [esp+24h] [ebp-4h]
  int tmp3c; // [esp+24h] [ebp-4h]

  ctr = 7;
  v1 = data + 2;
  do
  {
    v2 = v1[5];
    v3 = *(v1 - 2);
    v4 = v3 + v2;
    v5 = v3 - v2;
    v6 = v1[4];
    tmp10 = v4;
    v7 = *(v1 - 1);
    v8 = v7 + v6;
    v9 = v7 - v6;
    v10 = v1[3];
    z2 = v8;
    tmp12 = v10 + *v1;
    v11 = *v1 - v10;
    v12 = v1[1];
    v13 = v12 + v1[2];
    tmp4 = v12 - v1[2];
    v14 = tmp10 - v13;
    tmp10a = tmp10 + v13;
    tmp13 = v14;
    tmp3 = z2 + tmp12;
    tmp12a = z2 - tmp12;
    *(v1 - 2) = 4 * (tmp10a + tmp3);
    v1[2] = 4 * (tmp10a - tmp3);
    v15 = 4433 * (v14 + tmp12a);
    *v1 = (6270 * tmp13 + v15 + 1024) >> 11;
    v1[4] = (v15 - 15137 * tmp12a + 1024) >> 11;
    tmp10b = 9633 * (v9 + tmp4 + v11 + v5) - 16069 * (v9 + tmp4);
    tmp3a = 9633 * (v9 + tmp4 + v11 + v5) - 3196 * (v11 + v5);
    v1[5] = (tmp10b + 2446 * tmp4 - 7373 * (v5 + tmp4) + 1024) >> 11;
    v1[3] = (tmp3a + 16819 * v11 - 20995 * (v11 + v9) + 1024) >> 11;
    v1[1] = (tmp10b + 25172 * v9 - 20995 * (v11 + v9) + 1024) >> 11;
    *(v1 - 1) = (tmp3a + 12299 * v5 - 7373 * (v5 + tmp4) + 1024) >> 11;
    v1 += 8;
    --ctr;
  }
  while ( ctr >= 0 );
  ctra = 7;
  v16 = data + 16;
  do
  {
    v17 = v16[40];
    v18 = *(v16 - 16);
    v19 = v18 + v17;
    v20 = v18 - v17;
    v21 = v16[32];
    tmp10c = v19;
    v22 = *(v16 - 8);
    v23 = v22 + v21;
    v24 = v22 - v21;
    v25 = v16[24];
    z2a = v23;
    tmp12b = v25 + *v16;
    v26 = *v16 - v25;
    v27 = v16[8];
    v28 = v27 + v16[16];
    tmp4a = v27 - v16[16];
    v29 = tmp10c - v28;
    tmp10d = tmp10c + v28;
    tmp13a = v29;
    tmp3b = z2a + tmp12b;
    tmp12c = z2a - tmp12b;
    *(v16 - 16) = (tmp3b + tmp10d + 2) >> 2;
    v16[16] = (tmp10d - tmp3b + 2) >> 2;
    v30 = 4433 * (v29 + tmp12c);
    *v16 = (6270 * tmp13a + v30 + 0x4000) >> 15;
    v16[32] = (v30 - 15137 * tmp12c + 0x4000) >> 15;
    tmp10e = 9633 * (v24 + tmp4a + v26 + v20) - 16069 * (v24 + tmp4a);
    tmp3c = 9633 * (v24 + tmp4a + v26 + v20) - 3196 * (v26 + v20);
    v16[40] = (tmp10e + 2446 * tmp4a - 7373 * (v20 + tmp4a) + 0x4000) >> 15;
    v16[24] = (tmp3c + 16819 * v26 - 20995 * (v26 + v24) + 0x4000) >> 15;
    v16[8] = (tmp10e + 25172 * v24 - 20995 * (v26 + v24) + 0x4000) >> 15;
    *(v16 - 8) = (tmp3c + 12299 * v20 - 7373 * (v20 + tmp4a) + 0x4000) >> 15;
    ++v16;
    --ctra;
  }
  while ( ctra >= 0 );
}

} // namespace engine_xlsp

// ============================================================
// Overlay from statsmap (Missing functions)
// ============================================================
namespace statsmap {

//------------------------------------------------------------------------------
// Address: 0x0040CE60
// Name: _jpeg_fdct_islow
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_fdct_islow(int *data)
{
  int *v1; // eax
  int v2; // ecx
  int v3; // edx
  int v4; // esi
  int v5; // edx
  int v6; // ecx
  int v7; // esi
  int v8; // edi
  int v9; // esi
  int v10; // ecx
  int v11; // edi
  int v12; // ecx
  int v13; // ebx
  int v14; // ecx
  int v15; // ecx
  int *v16; // eax
  int v17; // ecx
  int v18; // edx
  int v19; // esi
  int v20; // edx
  int v21; // ecx
  int v22; // esi
  int v23; // edi
  int v24; // esi
  int v25; // ecx
  int v26; // edi
  int v27; // ecx
  int v28; // ebx
  int v29; // ecx
  int v30; // ecx
  int tmp13; // [esp+Ch] [ebp-1Ch]
  int tmp13a; // [esp+Ch] [ebp-1Ch]
  int z2; // [esp+10h] [ebp-18h]
  int z2a; // [esp+10h] [ebp-18h]
  int ctr; // [esp+14h] [ebp-14h]
  int ctra; // [esp+14h] [ebp-14h]
  int tmp10; // [esp+18h] [ebp-10h]
  int tmp10a; // [esp+18h] [ebp-10h]
  int tmp10b; // [esp+18h] [ebp-10h]
  int tmp10c; // [esp+18h] [ebp-10h]
  int tmp10d; // [esp+18h] [ebp-10h]
  int tmp10e; // [esp+18h] [ebp-10h]
  int tmp12; // [esp+1Ch] [ebp-Ch]
  int tmp12a; // [esp+1Ch] [ebp-Ch]
  int tmp12b; // [esp+1Ch] [ebp-Ch]
  int tmp12c; // [esp+1Ch] [ebp-Ch]
  int tmp4; // [esp+20h] [ebp-8h]
  int tmp4a; // [esp+20h] [ebp-8h]
  int tmp3; // [esp+24h] [ebp-4h]
  int tmp3a; // [esp+24h] [ebp-4h]
  int tmp3b; // [esp+24h] [ebp-4h]
  int tmp3c; // [esp+24h] [ebp-4h]

  ctr = 7;
  v1 = data + 2;
  do
  {
    v2 = v1[5];
    v3 = *(v1 - 2);
    v4 = v3 + v2;
    v5 = v3 - v2;
    v6 = v1[4];
    tmp10 = v4;
    v7 = *(v1 - 1);
    v8 = v7 + v6;
    v9 = v7 - v6;
    v10 = v1[3];
    z2 = v8;
    tmp12 = v10 + *v1;
    v11 = *v1 - v10;
    v12 = v1[1];
    v13 = v12 + v1[2];
    tmp4 = v12 - v1[2];
    v14 = tmp10 - v13;
    tmp10a = tmp10 + v13;
    tmp13 = v14;
    tmp3 = z2 + tmp12;
    tmp12a = z2 - tmp12;
    *(v1 - 2) = 4 * (tmp10a + tmp3);
    v1[2] = 4 * (tmp10a - tmp3);
    v15 = 4433 * (v14 + tmp12a);
    *v1 = (6270 * tmp13 + v15 + 1024) >> 11;
    v1[4] = (v15 - 15137 * tmp12a + 1024) >> 11;
    tmp10b = 9633 * (v9 + tmp4 + v11 + v5) - 16069 * (v9 + tmp4);
    tmp3a = 9633 * (v9 + tmp4 + v11 + v5) - 3196 * (v11 + v5);
    v1[5] = (tmp10b + 2446 * tmp4 - 7373 * (v5 + tmp4) + 1024) >> 11;
    v1[3] = (tmp3a + 16819 * v11 - 20995 * (v11 + v9) + 1024) >> 11;
    v1[1] = (tmp10b + 25172 * v9 - 20995 * (v11 + v9) + 1024) >> 11;
    *(v1 - 1) = (tmp3a + 12299 * v5 - 7373 * (v5 + tmp4) + 1024) >> 11;
    v1 += 8;
    --ctr;
  }
  while ( ctr >= 0 );
  ctra = 7;
  v16 = data + 16;
  do
  {
    v17 = v16[40];
    v18 = *(v16 - 16);
    v19 = v18 + v17;
    v20 = v18 - v17;
    v21 = v16[32];
    tmp10c = v19;
    v22 = *(v16 - 8);
    v23 = v22 + v21;
    v24 = v22 - v21;
    v25 = v16[24];
    z2a = v23;
    tmp12b = v25 + *v16;
    v26 = *v16 - v25;
    v27 = v16[8];
    v28 = v27 + v16[16];
    tmp4a = v27 - v16[16];
    v29 = tmp10c - v28;
    tmp10d = tmp10c + v28;
    tmp13a = v29;
    tmp3b = z2a + tmp12b;
    tmp12c = z2a - tmp12b;
    *(v16 - 16) = (tmp3b + tmp10d + 2) >> 2;
    v16[16] = (tmp10d - tmp3b + 2) >> 2;
    v30 = 4433 * (v29 + tmp12c);
    *v16 = (6270 * tmp13a + v30 + 0x4000) >> 15;
    v16[32] = (v30 - 15137 * tmp12c + 0x4000) >> 15;
    tmp10e = 9633 * (v24 + tmp4a + v26 + v20) - 16069 * (v24 + tmp4a);
    tmp3c = 9633 * (v24 + tmp4a + v26 + v20) - 3196 * (v26 + v20);
    v16[40] = (tmp10e + 2446 * tmp4a - 7373 * (v20 + tmp4a) + 0x4000) >> 15;
    v16[24] = (tmp3c + 16819 * v26 - 20995 * (v26 + v24) + 0x4000) >> 15;
    v16[8] = (tmp10e + 25172 * v24 - 20995 * (v26 + v24) + 0x4000) >> 15;
    *(v16 - 8) = (tmp3c + 12299 * v20 - 7373 * (v20 + tmp4a) + 0x4000) >> 15;
    ++v16;
    --ctra;
  }
  while ( ctra >= 0 );
}

} // namespace statsmap

// ============================================================
// Overlay from VXConsole (Missing functions)
// ============================================================
namespace VXConsole {

//------------------------------------------------------------------------------
// Address: 0x00436170
// Name: _jpeg_fdct_islow
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_fdct_islow(int *data)
{
  int *v1; // eax
  int v2; // ecx
  int v3; // edx
  int v4; // esi
  int v5; // edx
  int v6; // ecx
  int v7; // esi
  int v8; // edi
  int v9; // esi
  int v10; // ecx
  int v11; // edi
  int v12; // ecx
  int v13; // ebx
  int v14; // ecx
  int v15; // ecx
  int *v16; // eax
  int v17; // ecx
  int v18; // edx
  int v19; // esi
  int v20; // edx
  int v21; // ecx
  int v22; // esi
  int v23; // edi
  int v24; // esi
  int v25; // ecx
  int v26; // edi
  int v27; // ecx
  int v28; // ebx
  int v29; // ecx
  int v30; // ecx
  int tmp13; // [esp+Ch] [ebp-1Ch]
  int tmp13a; // [esp+Ch] [ebp-1Ch]
  int z2; // [esp+10h] [ebp-18h]
  int z2a; // [esp+10h] [ebp-18h]
  int ctr; // [esp+14h] [ebp-14h]
  int ctra; // [esp+14h] [ebp-14h]
  int tmp10; // [esp+18h] [ebp-10h]
  int tmp10a; // [esp+18h] [ebp-10h]
  int tmp10b; // [esp+18h] [ebp-10h]
  int tmp10c; // [esp+18h] [ebp-10h]
  int tmp10d; // [esp+18h] [ebp-10h]
  int tmp10e; // [esp+18h] [ebp-10h]
  int tmp12; // [esp+1Ch] [ebp-Ch]
  int tmp12a; // [esp+1Ch] [ebp-Ch]
  int tmp12b; // [esp+1Ch] [ebp-Ch]
  int tmp12c; // [esp+1Ch] [ebp-Ch]
  int tmp4; // [esp+20h] [ebp-8h]
  int tmp4a; // [esp+20h] [ebp-8h]
  int tmp3; // [esp+24h] [ebp-4h]
  int tmp3a; // [esp+24h] [ebp-4h]
  int tmp3b; // [esp+24h] [ebp-4h]
  int tmp3c; // [esp+24h] [ebp-4h]

  ctr = 7;
  v1 = data + 2;
  do
  {
    v2 = v1[5];
    v3 = *(v1 - 2);
    v4 = v3 + v2;
    v5 = v3 - v2;
    v6 = v1[4];
    tmp10 = v4;
    v7 = *(v1 - 1);
    v8 = v7 + v6;
    v9 = v7 - v6;
    v10 = v1[3];
    z2 = v8;
    tmp12 = v10 + *v1;
    v11 = *v1 - v10;
    v12 = v1[1];
    v13 = v12 + v1[2];
    tmp4 = v12 - v1[2];
    v14 = tmp10 - v13;
    tmp10a = tmp10 + v13;
    tmp13 = v14;
    tmp3 = z2 + tmp12;
    tmp12a = z2 - tmp12;
    *(v1 - 2) = 4 * (tmp10a + tmp3);
    v1[2] = 4 * (tmp10a - tmp3);
    v15 = 4433 * (v14 + tmp12a);
    *v1 = (6270 * tmp13 + v15 + 1024) >> 11;
    v1[4] = (v15 - 15137 * tmp12a + 1024) >> 11;
    tmp10b = 9633 * (v9 + tmp4 + v11 + v5) - 16069 * (v9 + tmp4);
    tmp3a = 9633 * (v9 + tmp4 + v11 + v5) - 3196 * (v11 + v5);
    v1[5] = (tmp10b + 2446 * tmp4 - 7373 * (v5 + tmp4) + 1024) >> 11;
    v1[3] = (tmp3a + 16819 * v11 - 20995 * (v11 + v9) + 1024) >> 11;
    v1[1] = (tmp10b + 25172 * v9 - 20995 * (v11 + v9) + 1024) >> 11;
    *(v1 - 1) = (tmp3a + 12299 * v5 - 7373 * (v5 + tmp4) + 1024) >> 11;
    v1 += 8;
    --ctr;
  }
  while ( ctr >= 0 );
  ctra = 7;
  v16 = data + 16;
  do
  {
    v17 = v16[40];
    v18 = *(v16 - 16);
    v19 = v18 + v17;
    v20 = v18 - v17;
    v21 = v16[32];
    tmp10c = v19;
    v22 = *(v16 - 8);
    v23 = v22 + v21;
    v24 = v22 - v21;
    v25 = v16[24];
    z2a = v23;
    tmp12b = v25 + *v16;
    v26 = *v16 - v25;
    v27 = v16[8];
    v28 = v27 + v16[16];
    tmp4a = v27 - v16[16];
    v29 = tmp10c - v28;
    tmp10d = tmp10c + v28;
    tmp13a = v29;
    tmp3b = z2a + tmp12b;
    tmp12c = z2a - tmp12b;
    *(v16 - 16) = (tmp3b + tmp10d + 2) >> 2;
    v16[16] = (tmp10d - tmp3b + 2) >> 2;
    v30 = 4433 * (v29 + tmp12c);
    *v16 = (6270 * tmp13a + v30 + 0x4000) >> 15;
    v16[32] = (v30 - 15137 * tmp12c + 0x4000) >> 15;
    tmp10e = 9633 * (v24 + tmp4a + v26 + v20) - 16069 * (v24 + tmp4a);
    tmp3c = 9633 * (v24 + tmp4a + v26 + v20) - 3196 * (v26 + v20);
    v16[40] = (tmp10e + 2446 * tmp4a - 7373 * (v20 + tmp4a) + 0x4000) >> 15;
    v16[24] = (tmp3c + 16819 * v26 - 20995 * (v26 + v24) + 0x4000) >> 15;
    v16[8] = (tmp10e + 25172 * v24 - 20995 * (v26 + v24) + 0x4000) >> 15;
    *(v16 - 8) = (tmp3c + 12299 * v20 - 7373 * (v20 + tmp4a) + 0x4000) >> 15;
    ++v16;
    --ctra;
  }
  while ( ctra >= 0 );
}

} // namespace VXConsole

// ============================================================
// Overlay from vxconsole_ps3 (Missing functions)
// ============================================================
namespace vxconsole_ps3 {

//------------------------------------------------------------------------------
// Address: 0x00422F80
// Name: _jpeg_fdct_islow
// Source: json
//------------------------------------------------------------------------------
void __cdecl jpeg_fdct_islow(int *data)
{
  int *v1; // eax
  int v2; // ecx
  int v3; // edx
  int v4; // esi
  int v5; // edx
  int v6; // ecx
  int v7; // esi
  int v8; // edi
  int v9; // esi
  int v10; // ecx
  int v11; // edi
  int v12; // ecx
  int v13; // ebx
  int v14; // ecx
  int v15; // ecx
  int *v16; // eax
  int v17; // ecx
  int v18; // edx
  int v19; // esi
  int v20; // edx
  int v21; // ecx
  int v22; // esi
  int v23; // edi
  int v24; // esi
  int v25; // ecx
  int v26; // edi
  int v27; // ecx
  int v28; // ebx
  int v29; // ecx
  int v30; // ecx
  int tmp13; // [esp+Ch] [ebp-1Ch]
  int tmp13a; // [esp+Ch] [ebp-1Ch]
  int z2; // [esp+10h] [ebp-18h]
  int z2a; // [esp+10h] [ebp-18h]
  int ctr; // [esp+14h] [ebp-14h]
  int ctra; // [esp+14h] [ebp-14h]
  int tmp10; // [esp+18h] [ebp-10h]
  int tmp10a; // [esp+18h] [ebp-10h]
  int tmp10b; // [esp+18h] [ebp-10h]
  int tmp10c; // [esp+18h] [ebp-10h]
  int tmp10d; // [esp+18h] [ebp-10h]
  int tmp10e; // [esp+18h] [ebp-10h]
  int tmp12; // [esp+1Ch] [ebp-Ch]
  int tmp12a; // [esp+1Ch] [ebp-Ch]
  int tmp12b; // [esp+1Ch] [ebp-Ch]
  int tmp12c; // [esp+1Ch] [ebp-Ch]
  int tmp4; // [esp+20h] [ebp-8h]
  int tmp4a; // [esp+20h] [ebp-8h]
  int tmp3; // [esp+24h] [ebp-4h]
  int tmp3a; // [esp+24h] [ebp-4h]
  int tmp3b; // [esp+24h] [ebp-4h]
  int tmp3c; // [esp+24h] [ebp-4h]

  ctr = 7;
  v1 = data + 2;
  do
  {
    v2 = v1[5];
    v3 = *(v1 - 2);
    v4 = v3 + v2;
    v5 = v3 - v2;
    v6 = v1[4];
    tmp10 = v4;
    v7 = *(v1 - 1);
    v8 = v7 + v6;
    v9 = v7 - v6;
    v10 = v1[3];
    z2 = v8;
    tmp12 = v10 + *v1;
    v11 = *v1 - v10;
    v12 = v1[1];
    v13 = v12 + v1[2];
    tmp4 = v12 - v1[2];
    v14 = tmp10 - v13;
    tmp10a = tmp10 + v13;
    tmp13 = v14;
    tmp3 = z2 + tmp12;
    tmp12a = z2 - tmp12;
    *(v1 - 2) = 4 * (tmp10a + tmp3);
    v1[2] = 4 * (tmp10a - tmp3);
    v15 = 4433 * (v14 + tmp12a);
    *v1 = (6270 * tmp13 + v15 + 1024) >> 11;
    v1[4] = (v15 - 15137 * tmp12a + 1024) >> 11;
    tmp10b = 9633 * (v9 + tmp4 + v11 + v5) - 16069 * (v9 + tmp4);
    tmp3a = 9633 * (v9 + tmp4 + v11 + v5) - 3196 * (v11 + v5);
    v1[5] = (tmp10b + 2446 * tmp4 - 7373 * (v5 + tmp4) + 1024) >> 11;
    v1[3] = (tmp3a + 16819 * v11 - 20995 * (v11 + v9) + 1024) >> 11;
    v1[1] = (tmp10b + 25172 * v9 - 20995 * (v11 + v9) + 1024) >> 11;
    *(v1 - 1) = (tmp3a + 12299 * v5 - 7373 * (v5 + tmp4) + 1024) >> 11;
    v1 += 8;
    --ctr;
  }
  while ( ctr >= 0 );
  ctra = 7;
  v16 = data + 16;
  do
  {
    v17 = v16[40];
    v18 = *(v16 - 16);
    v19 = v18 + v17;
    v20 = v18 - v17;
    v21 = v16[32];
    tmp10c = v19;
    v22 = *(v16 - 8);
    v23 = v22 + v21;
    v24 = v22 - v21;
    v25 = v16[24];
    z2a = v23;
    tmp12b = v25 + *v16;
    v26 = *v16 - v25;
    v27 = v16[8];
    v28 = v27 + v16[16];
    tmp4a = v27 - v16[16];
    v29 = tmp10c - v28;
    tmp10d = tmp10c + v28;
    tmp13a = v29;
    tmp3b = z2a + tmp12b;
    tmp12c = z2a - tmp12b;
    *(v16 - 16) = (tmp3b + tmp10d + 2) >> 2;
    v16[16] = (tmp10d - tmp3b + 2) >> 2;
    v30 = 4433 * (v29 + tmp12c);
    *v16 = (6270 * tmp13a + v30 + 0x4000) >> 15;
    v16[32] = (v30 - 15137 * tmp12c + 0x4000) >> 15;
    tmp10e = 9633 * (v24 + tmp4a + v26 + v20) - 16069 * (v24 + tmp4a);
    tmp3c = 9633 * (v24 + tmp4a + v26 + v20) - 3196 * (v26 + v20);
    v16[40] = (tmp10e + 2446 * tmp4a - 7373 * (v20 + tmp4a) + 0x4000) >> 15;
    v16[24] = (tmp3c + 16819 * v26 - 20995 * (v26 + v24) + 0x4000) >> 15;
    v16[8] = (tmp10e + 25172 * v24 - 20995 * (v26 + v24) + 0x4000) >> 15;
    *(v16 - 8) = (tmp3c + 12299 * v20 - 7373 * (v20 + tmp4a) + 0x4000) >> 15;
    ++v16;
    --ctra;
  }
  while ( ctra >= 0 );
}

} // namespace vxconsole_ps3
