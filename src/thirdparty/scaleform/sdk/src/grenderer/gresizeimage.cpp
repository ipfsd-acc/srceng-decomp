// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/grenderer/gresizeimage.cpp
// Functions: 6
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1007DF70
// Name: GPixelFilterBilinearRGBA32
// Source: json
//------------------------------------------------------------------------------
int __cdecl GPixelFilterBilinearRGBA32(
        _BYTE *a1,
        unsigned __int8 *a2,
        unsigned __int8 *a3,
        unsigned __int8 *a4,
        unsigned __int8 *a5,
        int a6,
        int a7)
{
  int v7; // ebx
  int v8; // edi
  int v9; // ecx
  int v10; // edx
  int v11; // eax
  int v12; // esi
  int v13; // edi
  int v14; // edx
  int v15; // esi
  int v16; // ecx

  v7 = a6 * (256 - a7);
  v8 = (256 - a6) * (256 - a7);
  v9 = v8 * a2[1];
  v10 = v8 * a2[2];
  v11 = v7 * *a3 + v8 * *a2 + 0x8000;
  v12 = v7 * a3[3] + v8 * a2[3] + 0x8000;
  v13 = a7 * (256 - a6);
  v14 = a7 * a6 * a5[2] + v13 * a4[2] + v7 * a3[2] + v10 + 0x8000;
  v15 = a7 * a6 * a5[3] + v13 * a4[3] + v12;
  v16 = (a7 * a6 * a5[1] + v13 * a4[1] + v7 * a3[1] + v9 + 0x8000) >> 16;
  *a1 = (a7 * a6 * *a5 + v13 * (unsigned int)*a4 + v11) >> 16;
  a1[1] = v16;
  a1[2] = BYTE2(v14);
  a1[3] = BYTE2(v15);
  return v15 >> 16;
}

//------------------------------------------------------------------------------
// Address: 0x1007E090
// Name: GPixelFilterBilinearRGB24
// Source: json
//------------------------------------------------------------------------------
int __cdecl GPixelFilterBilinearRGB24(
        _BYTE *a1,
        unsigned __int8 *a2,
        unsigned __int8 *a3,
        unsigned __int8 *a4,
        unsigned __int8 *a5,
        int a6,
        int a7)
{
  int v7; // edi
  int v8; // edx
  int v9; // esi
  int result; // eax
  int v11; // ecx
  int v12; // edx

  v7 = a6 * (256 - a7);
  v8 = (256 - a6) * (256 - a7);
  v9 = a7 * (256 - a6);
  result = (a7 * a6 * *a5 + v9 * *a4 + v7 * *a3 + v8 * *a2 + 0x8000) >> 16;
  v11 = (a7 * a6 * a5[1] + v9 * a4[1] + v7 * a3[1] + v8 * a2[1] + 0x8000) >> 16;
  v12 = (a7 * a6 * a5[2] + v9 * a4[2] + v7 * a3[2] + v8 * a2[2] + 0x8000) >> 16;
  *a1 = result;
  a1[1] = v11;
  a1[2] = v12;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007E160
// Name: GPixelFilterBilinearRGBtoRGBA32
// Source: json
//------------------------------------------------------------------------------
int __cdecl GPixelFilterBilinearRGBtoRGBA32(
        _BYTE *a1,
        unsigned __int8 *a2,
        unsigned __int8 *a3,
        unsigned __int8 *a4,
        unsigned __int8 *a5,
        int a6,
        int a7)
{
  int v7; // edi
  int v8; // edx
  int v9; // esi
  int result; // eax
  int v11; // ecx
  int v12; // edx

  v7 = a6 * (256 - a7);
  v8 = (256 - a6) * (256 - a7);
  v9 = a7 * (256 - a6);
  result = (a7 * a6 * *a5 + v9 * *a4 + v7 * *a3 + v8 * *a2 + 0x8000) >> 16;
  v11 = (a7 * a6 * a5[1] + v9 * a4[1] + v7 * a3[1] + v8 * a2[1] + 0x8000) >> 16;
  v12 = (a7 * a6 * a5[2] + v9 * a4[2] + v7 * a3[2] + v8 * a2[2] + 0x8000) >> 16;
  *a1 = result;
  a1[1] = v11;
  a1[2] = v12;
  a1[3] = -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007E240
// Name: GPixelFilterBilinearGray8
// Source: json
//------------------------------------------------------------------------------
_BYTE *__cdecl GPixelFilterBilinearGray8(
        _BYTE *a1,
        unsigned __int8 *a2,
        unsigned __int8 *a3,
        unsigned __int8 *a4,
        unsigned __int8 *a5,
        int a6,
        int a7)
{
  *a1 = ((256 - a6) * (256 - a7) * *a2
       + a7 * (256 - a6) * *a4
       + a6 * (256 - a7) * *a3
       + a7 * a6 * (unsigned int)*a5
       + 0x8000) >> 16;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x1007E4F0
// Name: void GResizeImageBilinear(unsigned char __near *,int,int,int,unsigned char const __near *,int,int,int,enum GResizeImageType)
// Source: json
//------------------------------------------------------------------------------
int __stdcall GResizeImageBilinear(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int result; // eax

  if ( a2 > 0 && a3 > 0 && a6 > 0 )
  {
    result = a7;
    if ( a7 > 0 )
    {
      switch ( a9 )
      {
        case 0:
          result = GImageResizeFilter2x2_void____cdecl___unsigned_char___unsigned_char_const___unsigned_char_const___unsigned_char_const___unsigned_char_const___int_int__(
                     a1,
                     a2,
                     a3,
                     a4,
                     a5: 3,
                     a6: a5,
                     a7: a6,
                     a8: a7,
                     a9: a8,
                     a10: 3,
                     a11: GPixelFilterBilinearRGB24);
          break;
        case 1:
          result = GImageResizeFilter2x2_void____cdecl___unsigned_char___unsigned_char_const___unsigned_char_const___unsigned_char_const___unsigned_char_const___int_int__(
                     a1,
                     a2,
                     a3,
                     a4,
                     a5: 4,
                     a6: a5,
                     a7: a6,
                     a8: a7,
                     a9: a8,
                     a10: 4,
                     a11: GPixelFilterBilinearRGBA32);
          break;
        case 2:
          result = GImageResizeFilter2x2_void____cdecl___unsigned_char___unsigned_char_const___unsigned_char_const___unsigned_char_const___unsigned_char_const___int_int__(
                     a1,
                     a2,
                     a3,
                     a4,
                     a5: 4,
                     a6: a5,
                     a7: a6,
                     a8: a7,
                     a9: a8,
                     a10: 3,
                     a11: GPixelFilterBilinearRGBtoRGBA32);
          break;
        case 3:
          result = GImageResizeFilter2x2_void____cdecl___unsigned_char___unsigned_char_const___unsigned_char_const___unsigned_char_const___unsigned_char_const___int_int__(
                     a1,
                     a2,
                     a3,
                     a4,
                     a5: 1,
                     a6: a5,
                     a7: a6,
                     a8: a7,
                     a9: a8,
                     a10: 1,
                     a11: GPixelFilterBilinearGray8);
          break;
        default:
          return result;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1007E2B0
// Name: GImageResizeFilter2x2_void_(__cdecl_)(unsigned_char___unsigned_char_const___unsigned_char_const___unsigned_char_const___unsigned_char_const___int_int)_
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl GImageResizeFilter2x2_void____cdecl___unsigned_char___unsigned_char_const___unsigned_char_const___unsigned_char_const___unsigned_char_const___int_int__(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        void (__cdecl *a11)(int, int, int, int, int, _DWORD, int))
{
  int v11; // ebx
  int v12; // edx
  int v13; // ecx
  int v14; // ecx
  int v15; // eax
  int v16; // esi
  int v17; // eax
  int v18; // edx
  int v19; // ecx
  int v20; // ebx
  int v21; // edi
  int v22; // ebx
  int v23; // ebx
  int v24; // esi
  int v25; // edi
  int i; // ebx
  int v27; // eax
  bool v28; // zf
  int v30; // [esp+10h] [ebp-38h]
  int v31; // [esp+10h] [ebp-38h]
  int v32; // [esp+14h] [ebp-34h]
  int v33; // [esp+18h] [ebp-30h]
  int v34; // [esp+18h] [ebp-30h]
  _DWORD *v35; // [esp+20h] [ebp-28h]
  int v36; // [esp+2Ch] [ebp-1Ch]
  int v37; // [esp+30h] [ebp-18h]
  int v38; // [esp+34h] [ebp-14h]
  int v39; // [esp+38h] [ebp-10h] BYREF
  int v40; // [esp+3Ch] [ebp-Ch]
  int v41; // [esp+40h] [ebp-8h]
  int v42; // [esp+44h] [ebp-4h]
  int v43; // [esp+50h] [ebp+8h]
  int v44; // [esp+68h] [ebp+20h]

  v11 = 0;
  v35 = nullptr;
  if ( a2 != 0 )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: nullptr);
    v39 = 2;
    v35 = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 4 * a2, a3: &v39);
  }
  v12 = (a7 << 8) % a2;
  v30 = (a7 << 8) / a2;
  v13 = v12;
  if ( v12 <= 0 )
  {
    --v30;
    v13 = v12 + a2;
    v12 += a2;
  }
  v14 = v13 - a2;
  if ( a2 > 0 )
  {
    v15 = (a7 << 7) / a2 - 128;
    do
    {
      v35[v11] = v15;
      v15 += v30;
      v14 += v12;
      if ( v14 > 0 )
      {
        v14 -= a2;
        ++v15;
      }
      ++v11;
    }
    while ( v11 < a2 );
  }
  v16 = a8;
  v31 = (a8 << 8) / a3;
  v17 = (a8 << 8) % a3;
  v32 = v17;
  v33 = v17;
  if ( v17 <= 0 )
  {
    --v31;
    v33 = a3 + v17;
    v32 = a3 + v17;
  }
  v34 = v33 - a3;
  v18 = a1;
  v41 = a1;
  if ( a3 > 0 )
  {
    v38 = a7 - 1;
    v19 = (a8 << 7) / a3 - 128;
    v36 = a10 * (a7 - 1);
    v42 = v19;
    v40 = a3;
    while ( 1 )
    {
      v20 = v19 >> 8;
      v43 = (unsigned __int8)v19;
      if ( v19 >> 8 >= 0 )
        v21 = a6 + a9 * v20;
      else
        v21 = a6;
      v22 = v20 + 1;
      if ( v22 >= v16 )
        v22 = v16 - 1;
      v23 = a6 + a9 * v22;
      v24 = 0;
      v44 = v18;
      if ( a2 > 0 )
      {
        do
        {
          if ( (int)v35[v24] >= 0 )
            break;
          a11(a1: v44, a2: v21, a3: v21, a4: v23, a5: v23, a6: (unsigned __int8)v35[v24], a7: v43);
          v44 += a5;
          ++v24;
        }
        while ( v24 < a2 );
        for ( ; v24 < a2; ++v24 )
        {
          v37 = v35[v24];
          if ( v37 >> 8 >= v38 )
            break;
          a11(
            a1: v44,
            a2: v21 + a10 * (v37 >> 8),
            a3: v21 + a10 * ((v37 >> 8) + 1),
            a4: a10 * (v37 >> 8) + v23,
            a5: a10 * ((v37 >> 8) + 1) + v23,
            a6: (unsigned __int8)v37,
            a7: v43);
          v44 += a5;
        }
      }
      v25 = v36 + v21;
      for ( i = v36 + v23; v24 < a2; ++v24 )
      {
        a11(a1: v44, a2: v25, a3: v25, a4: i, a5: i, a6: (unsigned __int8)v35[v24], a7: v43);
        v44 += a5;
      }
      v27 = v32 + v34;
      v19 = v31 + v42;
      v34 = v27;
      v42 += v31;
      if ( v27 > 0 )
      {
        ++v19;
        v34 = v27 - a3;
        v42 = v19;
      }
      v18 = a4 + v41;
      v28 = v40-- == 1;
      v41 += a4;
      if ( v28 )
        break;
      v16 = a8;
    }
  }
  return ((int (__thiscall *)(GMemoryHeap *, _DWORD *))GMemory::pGlobalHeap->Free)(a1: GMemory::pGlobalHeap, a2: v35);
}
